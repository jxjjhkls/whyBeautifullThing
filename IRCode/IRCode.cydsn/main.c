/*******************************************************************************
* File Name: main.c
*
* Version: 1.0
*
* Description:
*  This is source code for the PSoC 4 BLE Find Me Profile Target example project.
*
* Note:
*
* Owners:
*  OLEG@CYPRESS.COM, KRIS@CYPRESS.COM
*
* Related Document:
*
* Hardware Dependency:
*  1. PSoC 4 BLE device
*  2. CY8CKIT-042 BLE Pioneer Kit
*
* Code Tested With:
*  1. PSoC Creator 3.1
*  2. ARM CM3-RVDS
*  3. ARM CM3-GCC
*  4. ARM CM3-MDK
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include <project.h>
#include "app_ble.h"
#include "common.h"
#include "ircode.h"
#include "app_ble.h"

int main()
{
    uint8 cmd = 0;
    BLE_Init();
	IrCode_Init();
    CyGlobalIntEnable;
    for(;;)
    {
    	BLE_Loop();
		if(IrCode_ScanKey())
		{
			IrBlink_RedLed();
		}	
    	cmd = Sys_GetCmd();
    	if(SW1_Read() ==0)   //测试
    	{
    		cmd =1;
    	}
		if(cmd &&cmd<0x80)
		{
			if(gtag_ircode.study_flag == 0)
			{
				IrBlink_RedLed();
				IrCode_SendKey(cmd);
			}else   //学习功能开始
			{
				IrBlink_RedLed();
				IrCode_Study(cmd);
			}
		}
		else if(cmd == 0x80)
		{
			IrBlink_RedLed();
			gtag_ircode.study_flag = 1;
		}
		else if(cmd == 0x81)
		{
			IrBlink_RedLed();
			gtag_ircode.study_flag = 0;
		}		
		else
		{
			
		}
   		
    }
}


/* [] END OF FILE */
