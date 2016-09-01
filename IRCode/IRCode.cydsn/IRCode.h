/*******************************************************************************
* File Name: IRCode.h
*
* Description:
* Contains the IR decode and encode 
* project.
*
*******************************************************************************/
#ifndef _IRCODE_H_
#define _IRCODE_H_







  	
#define IR_BACK 0x20





typedef struct _tag_ircode
{
    uint8 IR_threshold;   //阈值
    uint8 IR_Key;   //按键值
    uint8 IR_NewKeyflag;  //有新按键
	uint16 decode_delta;
	uint8 study_flag;
	uint32 tick_50us;
} TAG_IRCODE;


extern volatile TAG_IRCODE gtag_ircode;

void IrCode_Init(void);

uint8 IrCode_ScanKey(void);

uint8 IrCode_Study(uint8 key);


void IrCode_DelayUs(uint32 delay_us);
void IrBlink_RedLed(void);


void IrCode_SendKey(uint8 key);



#endif
