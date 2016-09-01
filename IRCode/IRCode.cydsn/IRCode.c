#include <project.h>
#include "IRCode.h"
#include "CyFlash.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

volatile TAG_IRCODE gtag_ircode;
uint8 decodemsg[128];
uint8 decodemsg_len;

//解析红外解码

uint8 Proc_SampDecodeData(uint8 data)
{
	static uint8 step = 0;
	uint8 status = 0;
	gtag_ircode.tick_50us ++; 
	if(gtag_ircode.IR_NewKeyflag)
		return status;
	switch(step)
	{
		case 0:
			if(data < gtag_ircode.IR_threshold )
			{
				
				gtag_ircode.decode_delta ++;
				if(gtag_ircode.decode_delta < 20)
					break;
				step ++;
				decodemsg_len = 0;
				status  = 1; 
			}
			else
			{
				gtag_ircode.decode_delta = 0;
				status  = 0;
			}
			break;
		case 1:   //开始计数  低电平
			if(data < gtag_ircode.IR_threshold)
			{
				gtag_ircode.decode_delta ++;
			}
			else 
			{
				step++;
				decodemsg[decodemsg_len++] = gtag_ircode.decode_delta;
				gtag_ircode.decode_delta = 0;
				if(decodemsg_len >= sizeof(decodemsg))
				decodemsg_len = 0;
			}
			status  = 1;  
			break;
		case 2://开始计数  高电平
			status  = 1;  
			if(data >= gtag_ircode.IR_threshold )
			{
				gtag_ircode.decode_delta ++;
				if(gtag_ircode.decode_delta > 250)
				{
					//按键存在
					step = 0;
					gtag_ircode.IR_NewKeyflag = 1;	
					gtag_ircode.decode_delta = 0;
					status  = 0;
				}
			}
			else
			{
				step--;
				decodemsg[decodemsg_len++] = gtag_ircode.decode_delta;
				gtag_ircode.decode_delta = 0;
				if(decodemsg_len >= sizeof(decodemsg))
				decodemsg_len = 0;			
			}
			break;
		
			
		
		default:break;
	}
    return status;
}


//uint16 output;
//float32 VOUT;
CY_ISR(ADC_ISR_Handler)
{
	uint32 intr_status;

	/* Read interrupt status register */
	intr_status = ADC_SAP_SAR_INTR_REG;

	//output = (int16)(ADC_SAP_SAR_CHAN0_RESULT_REG & ADC_SAP_RESULT_MASK); 
	//VOUT = ADC_SAP_CountsTo_Volts(0,output);
	Proc_SampDecodeData((int16)(ADC_SAP_SAR_CHAN0_RESULT_REG & ADC_SAP_RESULT_MASK)>> 3);
	/* Clear handled interrupt */
	ADC_SAP_SAR_INTR_REG = intr_status;

}

const uint8 irinitkey[][128] =
{
	{  //OK  
		0x55,0x04,0x11,0xEE,0x15,0xea,
	},
	
};
void IrCode_InitKey(void)
{
	uint8 *readBuf,i;
	readBuf = (uint8*)((CY_FLASH_NUMBER_ROWS-1)*CYDEV_FLS_ROW_SIZE);
	if(readBuf[0] == 0x55)	   //初始化过
	return;
	for(i = 0;i < sizeof(irinitkey)/sizeof(irinitkey[0]);i++)
	{
		CySysFlashWriteRow(CY_FLASH_NUMBER_ROWS-1-i,irinitkey[i]);
	}
}

void IrCode_Init(void)
{
	uint8 i;
	uint16 sum;
   	CTL_DOut_Write(0);
    ADC_SAP_Start();           /* Initialize ADC */ 
	ADC_SAP_IRQ_StartEx(ADC_ISR_Handler);
	ADC_SAP_IRQ_Disable();
	memset((uint8*)&gtag_ircode,0x00,sizeof(TAG_IRCODE));
	//获取一次
	sum = 0;
	for(i = 0;i < 8;i++)
	{
		 ADC_SAP_StartConvert();    /* Start ADC conversions */	
		 ADC_SAP_IsEndConversion(ADC_SAP_WAIT_FOR_RESULT);
		 sum += ((int16)(ADC_SAP_SAR_CHAN0_RESULT_REG & ADC_SAP_RESULT_MASK)>> 3);
	}
	gtag_ircode.IR_threshold = sum /8;
	gtag_ircode.IR_threshold/=2;
	ADC_SAP_IRQ_Enable();      /* Enable ADC interrupts */ 
	IrCode_InitKey();
	Timer_Start();
	gtag_ircode.IR_NewKeyflag  =  1 ;   
}

void SampDecodeData_Loop(void)
{
	CyGlobalIntDisable;
	while(1)
	{
		   /* Start ADC conversions */	
		ADC_SAP_IsEndConversion(ADC_SAP_WAIT_FOR_RESULT);
		if(Proc_SampDecodeData((int16)(ADC_SAP_SAR_CHAN0_RESULT_REG & ADC_SAP_RESULT_MASK)>> 3) == 0)
		{
			break;
		}
	}
	CyGlobalIntEnable;
}


static uint32 Ir_DecoderCode(void)
{
	uint8 i,ucPreBit,ucCurBit;
	uint32 uiRetCmd;
	if(decodemsg_len != 32*2 + 1 + 2)
		return 0;
	i = 0;
	if(decodemsg[i++] < 135)   //9 ms
		return 0;
	if(decodemsg[i++] < 59)   //   4ms
		return 0;	
	uiRetCmd = 0;
	for(;i < decodemsg_len-1;i ++)
	{
		
		if(decodemsg[i] < 26)
			ucCurBit = 0;
		else 
			ucCurBit = 1;
		if((i % 2) != 0)   //  到结果位
		{
			uiRetCmd >>= 1;
			if(ucCurBit == 1 && ucPreBit == 0)
				uiRetCmd |= 0x80000000;
			else if(ucCurBit == 0 && ucPreBit == 0)
				uiRetCmd |= 0x00;
			else 
				return 0;
		}
		else
			ucPreBit = ucCurBit;
	}
	if(decodemsg[i]  >  59)  //stop bit
			return 0;
	// 判断命令是否重复
	if((uiRetCmd >>24 & 0x00ff) != (~uiRetCmd >>16 & 0x00ff))
		return 0;
	return uiRetCmd;
}
uint8 IrCode_ScanKey(void)
{
	uint8 i;
	uint8 *readBuf;
	uint32 uiRetCmd,uiReadCmd;
	//SampDecodeData_Loop();
	if(!gtag_ircode.IR_NewKeyflag)
	return 0;
	//查找类似按键 方差计算
	uiRetCmd = Ir_DecoderCode();
	gtag_ircode.IR_NewKeyflag = 0;
	if(uiRetCmd == 0)
		return 0;
	for(i = 1;i < 0x7f;i++)
	{
		readBuf = (uint8*)((CY_FLASH_NUMBER_ROWS-i)*CYDEV_FLS_ROW_SIZE);
		if(readBuf[0] != 0x55)
			continue;
		//存在数据比对
		uiReadCmd = readBuf[2] +readBuf[3]*0x100+readBuf[4]*0x10000+readBuf[5]*0x1000000;
		if(uiRetCmd == uiReadCmd)
			break;
	}
	if(i == 0x7f)
		return 0 ;
	else 
		return i;
}


void SendTempKey(uint32 uiSendKey)
{
	uint32 cmd,i,uiCurTick;
	cmd = uiSendKey;
	//send startx;
	PWM_SEND_Start();
	gtag_ircode.tick_50us = 0;
	uiCurTick = 9000;
	while(gtag_ircode.tick_50us  < uiCurTick/50);
	PWM_SEND_Stop();
	uiCurTick += 4500;
	while(gtag_ircode.tick_50us  < uiCurTick/50);
	for(i = 0;i < 32;i++)
	{
		PWM_SEND_Start();
		uiCurTick += 560;
		while(gtag_ircode.tick_50us  < uiCurTick/50);
		PWM_SEND_Stop();
		if(cmd&0x01)
		{
			uiCurTick += 1680;
			while(gtag_ircode.tick_50us  < uiCurTick/50);

		}else
		{
			uiCurTick += 560;
			while(gtag_ircode.tick_50us  < uiCurTick/50);		
		}
		cmd >>=1;
	}	
	PWM_SEND_Start();
	uiCurTick += 560;
	while(gtag_ircode.tick_50us  < uiCurTick/50);		
	PWM_SEND_Stop();
	uiCurTick = 108000;
	while(gtag_ircode.tick_50us  < uiCurTick/50);	
	uiCurTick = 0;
	PWM_SEND_Start();
	IrCode_DelayUs(9000);
	PWM_SEND_Stop();
	IrCode_DelayUs(1680);
	PWM_SEND_Start();
	IrCode_DelayUs(1680);
	PWM_SEND_Stop();
}
void IrCode_SendKey(uint8 key)
{
	uint8 *readBuf;
	uint32 uiReadCmdKey;
	readBuf = (uint8*)((CY_FLASH_NUMBER_ROWS-key)*CYDEV_FLS_ROW_SIZE);
	if(readBuf[0] != 0x55)
		return;
	uiReadCmdKey  =readBuf[2] +readBuf[3]*0x100+readBuf[4]*0x10000+readBuf[5]*0x1000000;
	SendTempKey(uiReadCmdKey);
}

void IrCode_DelayUs(uint32 delay_us)
{
	gtag_ircode.tick_50us = 0;
	while(gtag_ircode.tick_50us  < delay_us/50);
}
void IrBlink_RedLed(void)
{
	Disconnect_LED_Write(0);
	IrCode_DelayUs(100000);
	Disconnect_LED_Write(1);
	IrCode_DelayUs(100000);
	Disconnect_LED_Write(0);
	IrCode_DelayUs(100000);
	Disconnect_LED_Write(1);
	IrCode_DelayUs(100000);    	
}

uint8 IrCode_Study(uint8 key)  //学习KEY键盘
{
	uint32 uiRecvKey;
	uint8 irinitkey[128] ={0,};
	while(1)
	{
		if(gtag_ircode.IR_NewKeyflag == 0)
		{
			IrBlink_RedLed();
			continue;
		}
		uiRecvKey =  Ir_DecoderCode();
		gtag_ircode.IR_NewKeyflag = 0;
		if(uiRecvKey == 0)
			continue;
		//收到键盘
		irinitkey[0] = 0x55;
		irinitkey[1] = 0x04;
		memcpy(irinitkey+2,(uint8*)&uiRecvKey,4);
		CySysFlashWriteRow(CY_FLASH_NUMBER_ROWS-key,irinitkey);
		IrBlink_RedLed();
		IrBlink_RedLed();
		break;
	}
    return 0;
}

