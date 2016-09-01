/*******************************************************************************
* File Name: BLE_HAL_Uart_PM.c
* Version 3.10
*
* Description:
*  This file provides the source code to the Power Management support for
*  the SCB Component.
*
* Note:
*
********************************************************************************
* Copyright 2013-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "BLE_HAL_Uart.h"
#include "BLE_HAL_Uart_PVT.h"

#if(BLE_HAL_Uart_SCB_MODE_I2C_INC)
    #include "BLE_HAL_Uart_I2C_PVT.h"
#endif /* (BLE_HAL_Uart_SCB_MODE_I2C_INC) */

#if(BLE_HAL_Uart_SCB_MODE_EZI2C_INC)
    #include "BLE_HAL_Uart_EZI2C_PVT.h"
#endif /* (BLE_HAL_Uart_SCB_MODE_EZI2C_INC) */

#if(BLE_HAL_Uart_SCB_MODE_SPI_INC || BLE_HAL_Uart_SCB_MODE_UART_INC)
    #include "BLE_HAL_Uart_SPI_UART_PVT.h"
#endif /* (BLE_HAL_Uart_SCB_MODE_SPI_INC || BLE_HAL_Uart_SCB_MODE_UART_INC) */


/***************************************
*   Backup Structure declaration
***************************************/

#if(BLE_HAL_Uart_SCB_MODE_UNCONFIG_CONST_CFG || \
   (BLE_HAL_Uart_SCB_MODE_I2C_CONST_CFG   && (!BLE_HAL_Uart_I2C_WAKE_ENABLE_CONST))   || \
   (BLE_HAL_Uart_SCB_MODE_EZI2C_CONST_CFG && (!BLE_HAL_Uart_EZI2C_WAKE_ENABLE_CONST)) || \
   (BLE_HAL_Uart_SCB_MODE_SPI_CONST_CFG   && (!BLE_HAL_Uart_SPI_WAKE_ENABLE_CONST))   || \
   (BLE_HAL_Uart_SCB_MODE_UART_CONST_CFG  && (!BLE_HAL_Uart_UART_WAKE_ENABLE_CONST)))

    BLE_HAL_Uart_BACKUP_STRUCT BLE_HAL_Uart_backup =
    {
        0u, /* enableState */
    };
#endif


/*******************************************************************************
* Function Name: BLE_HAL_Uart_Sleep
********************************************************************************
*
* Summary:
*  Prepares the component to enter Deep Sleep.
*  The "Enable wakeup from Sleep Mode" selection has an influence on
*  this function implementation.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void BLE_HAL_Uart_Sleep(void)
{
#if(BLE_HAL_Uart_SCB_MODE_UNCONFIG_CONST_CFG)

    if(BLE_HAL_Uart_SCB_WAKE_ENABLE_CHECK)
    {
        if(BLE_HAL_Uart_SCB_MODE_I2C_RUNTM_CFG)
        {
            BLE_HAL_Uart_I2CSaveConfig();
        }
        else if(BLE_HAL_Uart_SCB_MODE_EZI2C_RUNTM_CFG)
        {
            BLE_HAL_Uart_EzI2CSaveConfig();
        }
    #if(!BLE_HAL_Uart_CY_SCBIP_V1)
        else if(BLE_HAL_Uart_SCB_MODE_SPI_RUNTM_CFG)
        {
            BLE_HAL_Uart_SpiSaveConfig();
        }
        else if(BLE_HAL_Uart_SCB_MODE_UART_RUNTM_CFG)
        {
            BLE_HAL_Uart_UartSaveConfig();
        }
    #endif /* (!BLE_HAL_Uart_CY_SCBIP_V1) */
        else
        {
            /* Unknown mode */
        }
    }
    else
    {
        BLE_HAL_Uart_backup.enableState = (uint8) BLE_HAL_Uart_GET_CTRL_ENABLED;

        if(0u != BLE_HAL_Uart_backup.enableState)
        {
            BLE_HAL_Uart_Stop();
        }
    }

#else

    #if (BLE_HAL_Uart_SCB_MODE_I2C_CONST_CFG && BLE_HAL_Uart_I2C_WAKE_ENABLE_CONST)
        BLE_HAL_Uart_I2CSaveConfig();

    #elif (BLE_HAL_Uart_SCB_MODE_EZI2C_CONST_CFG && BLE_HAL_Uart_EZI2C_WAKE_ENABLE_CONST)
        BLE_HAL_Uart_EzI2CSaveConfig();

    #elif (BLE_HAL_Uart_SCB_MODE_SPI_CONST_CFG && BLE_HAL_Uart_SPI_WAKE_ENABLE_CONST)
        BLE_HAL_Uart_SpiSaveConfig();

    #elif (BLE_HAL_Uart_SCB_MODE_UART_CONST_CFG && BLE_HAL_Uart_UART_WAKE_ENABLE_CONST)
        BLE_HAL_Uart_UartSaveConfig();

    #else

        BLE_HAL_Uart_backup.enableState = (uint8) BLE_HAL_Uart_GET_CTRL_ENABLED;

        if(0u != BLE_HAL_Uart_backup.enableState)
        {
            BLE_HAL_Uart_Stop();
        }

    #endif /* defined (BLE_HAL_Uart_SCB_MODE_I2C_CONST_CFG) && (BLE_HAL_Uart_I2C_WAKE_ENABLE_CONST) */

#endif /* (BLE_HAL_Uart_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/*******************************************************************************
* Function Name: BLE_HAL_Uart_Wakeup
********************************************************************************
*
* Summary:
*  Prepares the component for the Active mode operation after exiting
*  Deep Sleep. The "Enable wakeup from Sleep Mode" option has an influence
*  on this function implementation.
*  This function should not be called after exiting Sleep.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void BLE_HAL_Uart_Wakeup(void)
{
#if(BLE_HAL_Uart_SCB_MODE_UNCONFIG_CONST_CFG)

    if(BLE_HAL_Uart_SCB_WAKE_ENABLE_CHECK)
    {
        if(BLE_HAL_Uart_SCB_MODE_I2C_RUNTM_CFG)
        {
            BLE_HAL_Uart_I2CRestoreConfig();
        }
        else if(BLE_HAL_Uart_SCB_MODE_EZI2C_RUNTM_CFG)
        {
            BLE_HAL_Uart_EzI2CRestoreConfig();
        }
    #if(!BLE_HAL_Uart_CY_SCBIP_V1)
        else if(BLE_HAL_Uart_SCB_MODE_SPI_RUNTM_CFG)
        {
            BLE_HAL_Uart_SpiRestoreConfig();
        }
        else if(BLE_HAL_Uart_SCB_MODE_UART_RUNTM_CFG)
        {
            BLE_HAL_Uart_UartRestoreConfig();
        }
    #endif /* (!BLE_HAL_Uart_CY_SCBIP_V1) */
        else
        {
            /* Unknown mode */
        }
    }
    else
    {
        if(0u != BLE_HAL_Uart_backup.enableState)
        {
            BLE_HAL_Uart_Enable();
        }
    }

#else

    #if (BLE_HAL_Uart_SCB_MODE_I2C_CONST_CFG  && BLE_HAL_Uart_I2C_WAKE_ENABLE_CONST)
        BLE_HAL_Uart_I2CRestoreConfig();

    #elif (BLE_HAL_Uart_SCB_MODE_EZI2C_CONST_CFG && BLE_HAL_Uart_EZI2C_WAKE_ENABLE_CONST)
        BLE_HAL_Uart_EzI2CRestoreConfig();

    #elif (BLE_HAL_Uart_SCB_MODE_SPI_CONST_CFG && BLE_HAL_Uart_SPI_WAKE_ENABLE_CONST)
        BLE_HAL_Uart_SpiRestoreConfig();

    #elif (BLE_HAL_Uart_SCB_MODE_UART_CONST_CFG && BLE_HAL_Uart_UART_WAKE_ENABLE_CONST)
        BLE_HAL_Uart_UartRestoreConfig();

    #else

        if(0u != BLE_HAL_Uart_backup.enableState)
        {
            BLE_HAL_Uart_Enable();
        }

    #endif /* (BLE_HAL_Uart_I2C_WAKE_ENABLE_CONST) */

#endif /* (BLE_HAL_Uart_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/* [] END OF FILE */
