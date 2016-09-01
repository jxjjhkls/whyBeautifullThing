/*******************************************************************************
* File Name: Timer_SYS_PM.c
* Version 2.70
*
*  Description:
*     This file provides the power management source code to API for the
*     Timer.
*
*   Note:
*     None
*
*******************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
********************************************************************************/

#include "Timer_SYS.h"

static Timer_SYS_backupStruct Timer_SYS_backup;


/*******************************************************************************
* Function Name: Timer_SYS_SaveConfig
********************************************************************************
*
* Summary:
*     Save the current user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  Timer_SYS_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void Timer_SYS_SaveConfig(void) 
{
    #if (!Timer_SYS_UsingFixedFunction)
        Timer_SYS_backup.TimerUdb = Timer_SYS_ReadCounter();
        Timer_SYS_backup.InterruptMaskValue = Timer_SYS_STATUS_MASK;
        #if (Timer_SYS_UsingHWCaptureCounter)
            Timer_SYS_backup.TimerCaptureCounter = Timer_SYS_ReadCaptureCount();
        #endif /* Back Up capture counter register  */

        #if(!Timer_SYS_UDB_CONTROL_REG_REMOVED)
            Timer_SYS_backup.TimerControlRegister = Timer_SYS_ReadControlRegister();
        #endif /* Backup the enable state of the Timer component */
    #endif /* Backup non retention registers in UDB implementation. All fixed function registers are retention */
}


/*******************************************************************************
* Function Name: Timer_SYS_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration.
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  Timer_SYS_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void Timer_SYS_RestoreConfig(void) 
{   
    #if (!Timer_SYS_UsingFixedFunction)

        Timer_SYS_WriteCounter(Timer_SYS_backup.TimerUdb);
        Timer_SYS_STATUS_MASK =Timer_SYS_backup.InterruptMaskValue;
        #if (Timer_SYS_UsingHWCaptureCounter)
            Timer_SYS_SetCaptureCount(Timer_SYS_backup.TimerCaptureCounter);
        #endif /* Restore Capture counter register*/

        #if(!Timer_SYS_UDB_CONTROL_REG_REMOVED)
            Timer_SYS_WriteControlRegister(Timer_SYS_backup.TimerControlRegister);
        #endif /* Restore the enable state of the Timer component */
    #endif /* Restore non retention registers in the UDB implementation only */
}


/*******************************************************************************
* Function Name: Timer_SYS_Sleep
********************************************************************************
*
* Summary:
*     Stop and Save the user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  Timer_SYS_backup.TimerEnableState:  Is modified depending on the
*  enable state of the block before entering sleep mode.
*
*******************************************************************************/
void Timer_SYS_Sleep(void) 
{
    #if(!Timer_SYS_UDB_CONTROL_REG_REMOVED)
        /* Save Counter's enable state */
        if(Timer_SYS_CTRL_ENABLE == (Timer_SYS_CONTROL & Timer_SYS_CTRL_ENABLE))
        {
            /* Timer is enabled */
            Timer_SYS_backup.TimerEnableState = 1u;
        }
        else
        {
            /* Timer is disabled */
            Timer_SYS_backup.TimerEnableState = 0u;
        }
    #endif /* Back up enable state from the Timer control register */
    Timer_SYS_Stop();
    Timer_SYS_SaveConfig();
}


/*******************************************************************************
* Function Name: Timer_SYS_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  Timer_SYS_backup.enableState:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void Timer_SYS_Wakeup(void) 
{
    Timer_SYS_RestoreConfig();
    #if(!Timer_SYS_UDB_CONTROL_REG_REMOVED)
        if(Timer_SYS_backup.TimerEnableState == 1u)
        {     /* Enable Timer's operation */
                Timer_SYS_Enable();
        } /* Do nothing if Timer was disabled before */
    #endif /* Remove this code section if Control register is removed */
}


/* [] END OF FILE */
