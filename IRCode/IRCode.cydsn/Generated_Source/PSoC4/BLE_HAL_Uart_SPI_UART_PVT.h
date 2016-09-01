/*******************************************************************************
* File Name: BLE_HAL_Uart_SPI_UART_PVT.h
* Version 3.10
*
* Description:
*  This private file provides constants and parameter values for the
*  SCB Component in SPI and UART modes.
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

#if !defined(CY_SCB_SPI_UART_PVT_BLE_HAL_Uart_H)
#define CY_SCB_SPI_UART_PVT_BLE_HAL_Uart_H

#include "BLE_HAL_Uart_SPI_UART.h"


/***************************************
*     Internal Global Vars
***************************************/

#if (BLE_HAL_Uart_INTERNAL_RX_SW_BUFFER_CONST)
    extern volatile uint32  BLE_HAL_Uart_rxBufferHead;
    extern volatile uint32  BLE_HAL_Uart_rxBufferTail;
    extern volatile uint8   BLE_HAL_Uart_rxBufferOverflow;
#endif /* (BLE_HAL_Uart_INTERNAL_RX_SW_BUFFER_CONST) */

#if (BLE_HAL_Uart_INTERNAL_TX_SW_BUFFER_CONST)
    extern volatile uint32  BLE_HAL_Uart_txBufferHead;
    extern volatile uint32  BLE_HAL_Uart_txBufferTail;
#endif /* (BLE_HAL_Uart_INTERNAL_TX_SW_BUFFER_CONST) */

#if (BLE_HAL_Uart_INTERNAL_RX_SW_BUFFER)
    extern volatile uint8 BLE_HAL_Uart_rxBufferInternal[BLE_HAL_Uart_INTERNAL_RX_BUFFER_SIZE];
#endif /* (BLE_HAL_Uart_INTERNAL_RX_SW_BUFFER) */

#if (BLE_HAL_Uart_INTERNAL_TX_SW_BUFFER)
    extern volatile uint8 BLE_HAL_Uart_txBufferInternal[BLE_HAL_Uart_TX_BUFFER_SIZE];
#endif /* (BLE_HAL_Uart_INTERNAL_TX_SW_BUFFER) */


/***************************************
*     Private Function Prototypes
***************************************/

void BLE_HAL_Uart_SpiPostEnable(void);
void BLE_HAL_Uart_SpiStop(void);

#if (BLE_HAL_Uart_SCB_MODE_SPI_CONST_CFG)
    void BLE_HAL_Uart_SpiInit(void);
#endif /* (BLE_HAL_Uart_SCB_MODE_SPI_CONST_CFG) */

#if (BLE_HAL_Uart_SPI_WAKE_ENABLE_CONST)
    void BLE_HAL_Uart_SpiSaveConfig(void);
    void BLE_HAL_Uart_SpiRestoreConfig(void);
#endif /* (BLE_HAL_Uart_SPI_WAKE_ENABLE_CONST) */

void BLE_HAL_Uart_UartPostEnable(void);
void BLE_HAL_Uart_UartStop(void);

#if (BLE_HAL_Uart_SCB_MODE_UART_CONST_CFG)
    void BLE_HAL_Uart_UartInit(void);
#endif /* (BLE_HAL_Uart_SCB_MODE_UART_CONST_CFG) */

#if (BLE_HAL_Uart_UART_WAKE_ENABLE_CONST)
    void BLE_HAL_Uart_UartSaveConfig(void);
    void BLE_HAL_Uart_UartRestoreConfig(void);
#endif /* (BLE_HAL_Uart_UART_WAKE_ENABLE_CONST) */


/***************************************
*         UART API Constants
***************************************/

/* UART RX and TX position to be used in BLE_HAL_Uart_SetPins() */
#define BLE_HAL_Uart_UART_RX_PIN_ENABLE    (BLE_HAL_Uart_UART_RX)
#define BLE_HAL_Uart_UART_TX_PIN_ENABLE    (BLE_HAL_Uart_UART_TX)

/* UART RTS and CTS position to be used in  BLE_HAL_Uart_SetPins() */
#define BLE_HAL_Uart_UART_RTS_PIN_ENABLE    (0x10u)
#define BLE_HAL_Uart_UART_CTS_PIN_ENABLE    (0x20u)


/***************************************
* The following code is DEPRECATED and
* must not be used.
***************************************/

/* Interrupt processing */
#define BLE_HAL_Uart_SpiUartEnableIntRx(intSourceMask)  BLE_HAL_Uart_SetRxInterruptMode(intSourceMask)
#define BLE_HAL_Uart_SpiUartEnableIntTx(intSourceMask)  BLE_HAL_Uart_SetTxInterruptMode(intSourceMask)
uint32  BLE_HAL_Uart_SpiUartDisableIntRx(void);
uint32  BLE_HAL_Uart_SpiUartDisableIntTx(void);


#endif /* (CY_SCB_SPI_UART_PVT_BLE_HAL_Uart_H) */


/* [] END OF FILE */
