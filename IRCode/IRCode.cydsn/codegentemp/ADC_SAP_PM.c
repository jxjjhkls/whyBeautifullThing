/*******************************************************************************
* File Name: ADC_SAP_PM.c
* Version 2.40
*
* Description:
*  This file provides Sleep/WakeUp APIs functionality.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "ADC_SAP.h"


/***************************************
* Local data allocation
***************************************/

static ADC_SAP_BACKUP_STRUCT  ADC_SAP_backup =
{
    ADC_SAP_DISABLED
};


/*******************************************************************************
* Function Name: ADC_SAP_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the current user configuration.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void ADC_SAP_SaveConfig(void)
{
    /* All configuration registers are marked as [reset_all_retention] */
}


/*******************************************************************************
* Function Name: ADC_SAP_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void ADC_SAP_RestoreConfig(void)
{
    /* All congiguration registers are marked as [reset_all_retention] */
}


/*******************************************************************************
* Function Name: ADC_SAP_Sleep
********************************************************************************
*
* Summary:
*  Stops the ADC operation and saves the configuration registers and component
*  enable state. Should be called just prior to entering sleep.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  ADC_SAP_backup - modified.
*
*******************************************************************************/
void ADC_SAP_Sleep(void)
{
    /* During deepsleep/ hibernate mode keep SARMUX active, i.e. do not open
    *   all switches (disconnect), to be used for ADFT
    */
    ADC_SAP_SAR_DFT_CTRL_REG |= ADC_SAP_ADFT_OVERRIDE;
    if((ADC_SAP_SAR_CTRL_REG  & ADC_SAP_ENABLE) != 0u)
    {
        if((ADC_SAP_SAR_SAMPLE_CTRL_REG & ADC_SAP_CONTINUOUS_EN) != 0u)
        {
            ADC_SAP_backup.enableState = ADC_SAP_ENABLED | ADC_SAP_STARTED;
        }
        else
        {
            ADC_SAP_backup.enableState = ADC_SAP_ENABLED;
        }
        ADC_SAP_StopConvert();
        ADC_SAP_Stop();
        
        /* Disable the SAR internal pump before entering the chip low power mode */
        if((ADC_SAP_SAR_CTRL_REG & ADC_SAP_BOOSTPUMP_EN) != 0u)
        {
            ADC_SAP_SAR_CTRL_REG &= (uint32)~ADC_SAP_BOOSTPUMP_EN;
            ADC_SAP_backup.enableState |= ADC_SAP_BOOSTPUMP_ENABLED;
        }
    }
    else
    {
        ADC_SAP_backup.enableState = ADC_SAP_DISABLED;
    }
}


/*******************************************************************************
* Function Name: ADC_SAP_Wakeup
********************************************************************************
*
* Summary:
*  Restores the component enable state and configuration registers.
*  This should be called just after awaking from sleep mode.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  ADC_SAP_backup - used.
*
*******************************************************************************/
void ADC_SAP_Wakeup(void)
{
    ADC_SAP_SAR_DFT_CTRL_REG &= (uint32)~ADC_SAP_ADFT_OVERRIDE;
    if(ADC_SAP_backup.enableState != ADC_SAP_DISABLED)
    {
        /* Enable the SAR internal pump  */
        if((ADC_SAP_backup.enableState & ADC_SAP_BOOSTPUMP_ENABLED) != 0u)
        {
            ADC_SAP_SAR_CTRL_REG |= ADC_SAP_BOOSTPUMP_EN;
        }
        ADC_SAP_Enable();
        if((ADC_SAP_backup.enableState & ADC_SAP_STARTED) != 0u)
        {
            ADC_SAP_StartConvert();
        }
    }
}
/* [] END OF FILE */
