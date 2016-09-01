/*******************************************************************************
* File Name: BLE_HAL_Uart_BOOT.h
* Version 3.10
*
* Description:
*  This file provides constants and parameter values of the bootloader
*  communication APIs for the SCB Component.
*
* Note:
*
********************************************************************************
* Copyright 2014-2015, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_SCB_BOOT_BLE_HAL_Uart_H)
#define CY_SCB_BOOT_BLE_HAL_Uart_H

#include "BLE_HAL_Uart_PVT.h"

#if (BLE_HAL_Uart_SCB_MODE_I2C_INC)
    #include "BLE_HAL_Uart_I2C.h"
#endif /* (BLE_HAL_Uart_SCB_MODE_I2C_INC) */

#if (BLE_HAL_Uart_SCB_MODE_EZI2C_INC)
    #include "BLE_HAL_Uart_EZI2C.h"
#endif /* (BLE_HAL_Uart_SCB_MODE_EZI2C_INC) */

#if (BLE_HAL_Uart_SCB_MODE_SPI_INC || BLE_HAL_Uart_SCB_MODE_UART_INC)
    #include "BLE_HAL_Uart_SPI_UART.h"
#endif /* (BLE_HAL_Uart_SCB_MODE_SPI_INC || BLE_HAL_Uart_SCB_MODE_UART_INC) */


/***************************************
*  Conditional Compilation Parameters
****************************************/

/* Bootloader communication interface enable */
#define BLE_HAL_Uart_BTLDR_COMM_ENABLED ((CYDEV_BOOTLOADER_IO_COMP == CyBtldr_BLE_HAL_Uart) || \
                                             (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_Custom_Interface))

/* Enable I2C bootloader communication */
#if (BLE_HAL_Uart_SCB_MODE_I2C_INC)
    #define BLE_HAL_Uart_I2C_BTLDR_COMM_ENABLED     (BLE_HAL_Uart_BTLDR_COMM_ENABLED && \
                                                            (BLE_HAL_Uart_SCB_MODE_UNCONFIG_CONST_CFG || \
                                                             BLE_HAL_Uart_I2C_SLAVE_CONST))
#else
     #define BLE_HAL_Uart_I2C_BTLDR_COMM_ENABLED    (0u)
#endif /* (BLE_HAL_Uart_SCB_MODE_I2C_INC) */

/* EZI2C does not support bootloader communication. Provide empty APIs */
#if (BLE_HAL_Uart_SCB_MODE_EZI2C_INC)
    #define BLE_HAL_Uart_EZI2C_BTLDR_COMM_ENABLED   (BLE_HAL_Uart_BTLDR_COMM_ENABLED && \
                                                         BLE_HAL_Uart_SCB_MODE_UNCONFIG_CONST_CFG)
#else
    #define BLE_HAL_Uart_EZI2C_BTLDR_COMM_ENABLED   (0u)
#endif /* (BLE_HAL_Uart_EZI2C_BTLDR_COMM_ENABLED) */

/* Enable SPI bootloader communication */
#if (BLE_HAL_Uart_SCB_MODE_SPI_INC)
    #define BLE_HAL_Uart_SPI_BTLDR_COMM_ENABLED     (BLE_HAL_Uart_BTLDR_COMM_ENABLED && \
                                                            (BLE_HAL_Uart_SCB_MODE_UNCONFIG_CONST_CFG || \
                                                             BLE_HAL_Uart_SPI_SLAVE_CONST))
#else
        #define BLE_HAL_Uart_SPI_BTLDR_COMM_ENABLED (0u)
#endif /* (BLE_HAL_Uart_SPI_BTLDR_COMM_ENABLED) */

/* Enable UART bootloader communication */
#if (BLE_HAL_Uart_SCB_MODE_UART_INC)
       #define BLE_HAL_Uart_UART_BTLDR_COMM_ENABLED    (BLE_HAL_Uart_BTLDR_COMM_ENABLED && \
                                                            (BLE_HAL_Uart_SCB_MODE_UNCONFIG_CONST_CFG || \
                                                             (BLE_HAL_Uart_UART_RX_DIRECTION && \
                                                              BLE_HAL_Uart_UART_TX_DIRECTION)))
#else
     #define BLE_HAL_Uart_UART_BTLDR_COMM_ENABLED   (0u)
#endif /* (BLE_HAL_Uart_UART_BTLDR_COMM_ENABLED) */

/* Enable bootloader communication */
#define BLE_HAL_Uart_BTLDR_COMM_MODE_ENABLED    (BLE_HAL_Uart_I2C_BTLDR_COMM_ENABLED   || \
                                                     BLE_HAL_Uart_SPI_BTLDR_COMM_ENABLED   || \
                                                     BLE_HAL_Uart_EZI2C_BTLDR_COMM_ENABLED || \
                                                     BLE_HAL_Uart_UART_BTLDR_COMM_ENABLED)


/***************************************
*        Function Prototypes
***************************************/

#if defined(CYDEV_BOOTLOADER_IO_COMP) && (BLE_HAL_Uart_I2C_BTLDR_COMM_ENABLED)
    /* I2C Bootloader physical layer functions */
    void BLE_HAL_Uart_I2CCyBtldrCommStart(void);
    void BLE_HAL_Uart_I2CCyBtldrCommStop (void);
    void BLE_HAL_Uart_I2CCyBtldrCommReset(void);
    cystatus BLE_HAL_Uart_I2CCyBtldrCommRead       (uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
    cystatus BLE_HAL_Uart_I2CCyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);

    /* Map I2C specific bootloader communication APIs to SCB specific APIs */
    #if (BLE_HAL_Uart_SCB_MODE_I2C_CONST_CFG)
        #define BLE_HAL_Uart_CyBtldrCommStart   BLE_HAL_Uart_I2CCyBtldrCommStart
        #define BLE_HAL_Uart_CyBtldrCommStop    BLE_HAL_Uart_I2CCyBtldrCommStop
        #define BLE_HAL_Uart_CyBtldrCommReset   BLE_HAL_Uart_I2CCyBtldrCommReset
        #define BLE_HAL_Uart_CyBtldrCommRead    BLE_HAL_Uart_I2CCyBtldrCommRead
        #define BLE_HAL_Uart_CyBtldrCommWrite   BLE_HAL_Uart_I2CCyBtldrCommWrite
    #endif /* (BLE_HAL_Uart_SCB_MODE_I2C_CONST_CFG) */

#endif /* defined(CYDEV_BOOTLOADER_IO_COMP) && (BLE_HAL_Uart_I2C_BTLDR_COMM_ENABLED) */


#if defined(CYDEV_BOOTLOADER_IO_COMP) && (BLE_HAL_Uart_EZI2C_BTLDR_COMM_ENABLED)
    /* Bootloader physical layer functions */
    void BLE_HAL_Uart_EzI2CCyBtldrCommStart(void);
    void BLE_HAL_Uart_EzI2CCyBtldrCommStop (void);
    void BLE_HAL_Uart_EzI2CCyBtldrCommReset(void);
    cystatus BLE_HAL_Uart_EzI2CCyBtldrCommRead       (uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
    cystatus BLE_HAL_Uart_EzI2CCyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);

    /* Map EZI2C specific bootloader communication APIs to SCB specific APIs */
    #if (BLE_HAL_Uart_SCB_MODE_EZI2C_CONST_CFG)
        #define BLE_HAL_Uart_CyBtldrCommStart   BLE_HAL_Uart_EzI2CCyBtldrCommStart
        #define BLE_HAL_Uart_CyBtldrCommStop    BLE_HAL_Uart_EzI2CCyBtldrCommStop
        #define BLE_HAL_Uart_CyBtldrCommReset   BLE_HAL_Uart_EzI2CCyBtldrCommReset
        #define BLE_HAL_Uart_CyBtldrCommRead    BLE_HAL_Uart_EzI2CCyBtldrCommRead
        #define BLE_HAL_Uart_CyBtldrCommWrite   BLE_HAL_Uart_EzI2CCyBtldrCommWrite
    #endif /* (BLE_HAL_Uart_SCB_MODE_EZI2C_CONST_CFG) */

#endif /* defined(CYDEV_BOOTLOADER_IO_COMP) && (BLE_HAL_Uart_EZI2C_BTLDR_COMM_ENABLED) */

#if defined(CYDEV_BOOTLOADER_IO_COMP) && (BLE_HAL_Uart_SPI_BTLDR_COMM_ENABLED)
    /* SPI Bootloader physical layer functions */
    void BLE_HAL_Uart_SpiCyBtldrCommStart(void);
    void BLE_HAL_Uart_SpiCyBtldrCommStop (void);
    void BLE_HAL_Uart_SpiCyBtldrCommReset(void);
    cystatus BLE_HAL_Uart_SpiCyBtldrCommRead       (uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
    cystatus BLE_HAL_Uart_SpiCyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);

    /* Map SPI specific bootloader communication APIs to SCB specific APIs */
    #if (BLE_HAL_Uart_SCB_MODE_SPI_CONST_CFG)
        #define BLE_HAL_Uart_CyBtldrCommStart   BLE_HAL_Uart_SpiCyBtldrCommStart
        #define BLE_HAL_Uart_CyBtldrCommStop    BLE_HAL_Uart_SpiCyBtldrCommStop
        #define BLE_HAL_Uart_CyBtldrCommReset   BLE_HAL_Uart_SpiCyBtldrCommReset
        #define BLE_HAL_Uart_CyBtldrCommRead    BLE_HAL_Uart_SpiCyBtldrCommRead
        #define BLE_HAL_Uart_CyBtldrCommWrite   BLE_HAL_Uart_SpiCyBtldrCommWrite
    #endif /* (BLE_HAL_Uart_SCB_MODE_SPI_CONST_CFG) */

#endif /* defined(CYDEV_BOOTLOADER_IO_COMP) && (BLE_HAL_Uart_SPI_BTLDR_COMM_ENABLED) */

#if defined(CYDEV_BOOTLOADER_IO_COMP) && (BLE_HAL_Uart_UART_BTLDR_COMM_ENABLED)
    /* UART Bootloader physical layer functions */
    void BLE_HAL_Uart_UartCyBtldrCommStart(void);
    void BLE_HAL_Uart_UartCyBtldrCommStop (void);
    void BLE_HAL_Uart_UartCyBtldrCommReset(void);
    cystatus BLE_HAL_Uart_UartCyBtldrCommRead       (uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
    cystatus BLE_HAL_Uart_UartCyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);

    /* Map UART specific bootloader communication APIs to SCB specific APIs */
    #if (BLE_HAL_Uart_SCB_MODE_UART_CONST_CFG)
        #define BLE_HAL_Uart_CyBtldrCommStart   BLE_HAL_Uart_UartCyBtldrCommStart
        #define BLE_HAL_Uart_CyBtldrCommStop    BLE_HAL_Uart_UartCyBtldrCommStop
        #define BLE_HAL_Uart_CyBtldrCommReset   BLE_HAL_Uart_UartCyBtldrCommReset
        #define BLE_HAL_Uart_CyBtldrCommRead    BLE_HAL_Uart_UartCyBtldrCommRead
        #define BLE_HAL_Uart_CyBtldrCommWrite   BLE_HAL_Uart_UartCyBtldrCommWrite
    #endif /* (BLE_HAL_Uart_SCB_MODE_UART_CONST_CFG) */

#endif /* defined(CYDEV_BOOTLOADER_IO_COMP) && (BLE_HAL_Uart_UART_BTLDR_COMM_ENABLED) */

#if defined(CYDEV_BOOTLOADER_IO_COMP) && (BLE_HAL_Uart_BTLDR_COMM_ENABLED)
    #if (BLE_HAL_Uart_SCB_MODE_UNCONFIG_CONST_CFG)
        /* Bootloader physical layer functions */
        void BLE_HAL_Uart_CyBtldrCommStart(void);
        void BLE_HAL_Uart_CyBtldrCommStop (void);
        void BLE_HAL_Uart_CyBtldrCommReset(void);
        cystatus BLE_HAL_Uart_CyBtldrCommRead       (uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
        cystatus BLE_HAL_Uart_CyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
    #endif /* (BLE_HAL_Uart_SCB_MODE_UNCONFIG_CONST_CFG) */

    /* Map SCB specific bootloader communication APIs to common APIs */
    #if (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_BLE_HAL_Uart)
        #define CyBtldrCommStart    BLE_HAL_Uart_CyBtldrCommStart
        #define CyBtldrCommStop     BLE_HAL_Uart_CyBtldrCommStop
        #define CyBtldrCommReset    BLE_HAL_Uart_CyBtldrCommReset
        #define CyBtldrCommWrite    BLE_HAL_Uart_CyBtldrCommWrite
        #define CyBtldrCommRead     BLE_HAL_Uart_CyBtldrCommRead
    #endif /* (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_BLE_HAL_Uart) */

#endif /* defined(CYDEV_BOOTLOADER_IO_COMP) && (BLE_HAL_Uart_BTLDR_COMM_ENABLED) */


/***************************************
*           API Constants
***************************************/

/* Timeout unit in milliseconds */
#define BLE_HAL_Uart_WAIT_1_MS  (1u)

/* Return number of bytes to copy into bootloader buffer */
#define BLE_HAL_Uart_BYTES_TO_COPY(actBufSize, bufSize) \
                            ( ((uint32)(actBufSize) < (uint32)(bufSize)) ? \
                                ((uint32) (actBufSize)) : ((uint32) (bufSize)) )

/* Size of Read/Write buffers for I2C bootloader  */
#define BLE_HAL_Uart_I2C_BTLDR_SIZEOF_READ_BUFFER   (64u)
#define BLE_HAL_Uart_I2C_BTLDR_SIZEOF_WRITE_BUFFER  (64u)

/* Byte to byte time interval: calculated basing on current component
* data rate configuration, can be defined in project if required.
*/
#ifndef BLE_HAL_Uart_SPI_BYTE_TO_BYTE
    #define BLE_HAL_Uart_SPI_BYTE_TO_BYTE   (160u)
#endif

/* Byte to byte time interval: calculated basing on current component
* baud rate configuration, can be defined in the project if required.
*/
#ifndef BLE_HAL_Uart_UART_BYTE_TO_BYTE
    #define BLE_HAL_Uart_UART_BYTE_TO_BYTE  (187u)
#endif /* BLE_HAL_Uart_UART_BYTE_TO_BYTE */

#endif /* (CY_SCB_BOOT_BLE_HAL_Uart_H) */


/* [] END OF FILE */
