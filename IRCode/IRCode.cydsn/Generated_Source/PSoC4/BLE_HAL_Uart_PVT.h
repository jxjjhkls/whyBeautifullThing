/*******************************************************************************
* File Name: .h
* Version 3.10
*
* Description:
*  This private file provides constants and parameter values for the
*  SCB Component.
*  Please do not use this file or its content in your project.
*
* Note:
*
********************************************************************************
* Copyright 2013-2015, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_SCB_PVT_BLE_HAL_Uart_H)
#define CY_SCB_PVT_BLE_HAL_Uart_H

#include "BLE_HAL_Uart.h"


/***************************************
*     Private Function Prototypes
***************************************/

/* APIs to service INTR_I2C_EC register */
#define BLE_HAL_Uart_SetI2CExtClkInterruptMode(interruptMask) BLE_HAL_Uart_WRITE_INTR_I2C_EC_MASK(interruptMask)
#define BLE_HAL_Uart_ClearI2CExtClkInterruptSource(interruptMask) BLE_HAL_Uart_CLEAR_INTR_I2C_EC(interruptMask)
#define BLE_HAL_Uart_GetI2CExtClkInterruptSource()                (BLE_HAL_Uart_INTR_I2C_EC_REG)
#define BLE_HAL_Uart_GetI2CExtClkInterruptMode()                  (BLE_HAL_Uart_INTR_I2C_EC_MASK_REG)
#define BLE_HAL_Uart_GetI2CExtClkInterruptSourceMasked()          (BLE_HAL_Uart_INTR_I2C_EC_MASKED_REG)

#if (!BLE_HAL_Uart_CY_SCBIP_V1)
    /* APIs to service INTR_SPI_EC register */
    #define BLE_HAL_Uart_SetSpiExtClkInterruptMode(interruptMask) \
                                                                BLE_HAL_Uart_WRITE_INTR_SPI_EC_MASK(interruptMask)
    #define BLE_HAL_Uart_ClearSpiExtClkInterruptSource(interruptMask) \
                                                                BLE_HAL_Uart_CLEAR_INTR_SPI_EC(interruptMask)
    #define BLE_HAL_Uart_GetExtSpiClkInterruptSource()                 (BLE_HAL_Uart_INTR_SPI_EC_REG)
    #define BLE_HAL_Uart_GetExtSpiClkInterruptMode()                   (BLE_HAL_Uart_INTR_SPI_EC_MASK_REG)
    #define BLE_HAL_Uart_GetExtSpiClkInterruptSourceMasked()           (BLE_HAL_Uart_INTR_SPI_EC_MASKED_REG)
#endif /* (!BLE_HAL_Uart_CY_SCBIP_V1) */

#if(BLE_HAL_Uart_SCB_MODE_UNCONFIG_CONST_CFG)
    extern void BLE_HAL_Uart_SetPins(uint32 mode, uint32 subMode, uint32 uartEnableMask);
#endif /* (BLE_HAL_Uart_SCB_MODE_UNCONFIG_CONST_CFG) */


/***************************************
*     Vars with External Linkage
***************************************/

#if (BLE_HAL_Uart_SCB_IRQ_INTERNAL)
#if !defined (CY_REMOVE_BLE_HAL_Uart_CUSTOM_INTR_HANDLER)
    extern cyisraddress BLE_HAL_Uart_customIntrHandler;
#endif /* !defined (CY_REMOVE_BLE_HAL_Uart_CUSTOM_INTR_HANDLER) */
#endif /* (BLE_HAL_Uart_SCB_IRQ_INTERNAL) */

extern BLE_HAL_Uart_BACKUP_STRUCT BLE_HAL_Uart_backup;

#if(BLE_HAL_Uart_SCB_MODE_UNCONFIG_CONST_CFG)
    /* Common configuration variables */
    extern uint8 BLE_HAL_Uart_scbMode;
    extern uint8 BLE_HAL_Uart_scbEnableWake;
    extern uint8 BLE_HAL_Uart_scbEnableIntr;

    /* I2C configuration variables */
    extern uint8 BLE_HAL_Uart_mode;
    extern uint8 BLE_HAL_Uart_acceptAddr;

    /* SPI/UART configuration variables */
    extern volatile uint8 * BLE_HAL_Uart_rxBuffer;
    extern uint8   BLE_HAL_Uart_rxDataBits;
    extern uint32  BLE_HAL_Uart_rxBufferSize;

    extern volatile uint8 * BLE_HAL_Uart_txBuffer;
    extern uint8   BLE_HAL_Uart_txDataBits;
    extern uint32  BLE_HAL_Uart_txBufferSize;

    /* EZI2C configuration variables */
    extern uint8 BLE_HAL_Uart_numberOfAddr;
    extern uint8 BLE_HAL_Uart_subAddrSize;
#endif /* (BLE_HAL_Uart_SCB_MODE_UNCONFIG_CONST_CFG) */


/***************************************
*        Conditional Macro
****************************************/

#if(BLE_HAL_Uart_SCB_MODE_UNCONFIG_CONST_CFG)
    /* Defines run time operation mode */
    #define BLE_HAL_Uart_SCB_MODE_I2C_RUNTM_CFG     (BLE_HAL_Uart_SCB_MODE_I2C      == BLE_HAL_Uart_scbMode)
    #define BLE_HAL_Uart_SCB_MODE_SPI_RUNTM_CFG     (BLE_HAL_Uart_SCB_MODE_SPI      == BLE_HAL_Uart_scbMode)
    #define BLE_HAL_Uart_SCB_MODE_UART_RUNTM_CFG    (BLE_HAL_Uart_SCB_MODE_UART     == BLE_HAL_Uart_scbMode)
    #define BLE_HAL_Uart_SCB_MODE_EZI2C_RUNTM_CFG   (BLE_HAL_Uart_SCB_MODE_EZI2C    == BLE_HAL_Uart_scbMode)
    #define BLE_HAL_Uart_SCB_MODE_UNCONFIG_RUNTM_CFG \
                                                        (BLE_HAL_Uart_SCB_MODE_UNCONFIG == BLE_HAL_Uart_scbMode)

    /* Defines wakeup enable */
    #define BLE_HAL_Uart_SCB_WAKE_ENABLE_CHECK       (0u != BLE_HAL_Uart_scbEnableWake)
#endif /* (BLE_HAL_Uart_SCB_MODE_UNCONFIG_CONST_CFG) */

/* Defines maximum number of SCB pins */
#if (!BLE_HAL_Uart_CY_SCBIP_V1)
    #define BLE_HAL_Uart_SCB_PINS_NUMBER    (7u)
#else
    #define BLE_HAL_Uart_SCB_PINS_NUMBER    (2u)
#endif /* (!BLE_HAL_Uart_CY_SCBIP_V1) */

#endif /* (CY_SCB_PVT_BLE_HAL_Uart_H) */


/* [] END OF FILE */
