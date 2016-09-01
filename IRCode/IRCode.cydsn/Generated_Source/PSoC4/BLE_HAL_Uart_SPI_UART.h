/*******************************************************************************
* File Name: BLE_HAL_Uart_SPI_UART.h
* Version 3.10
*
* Description:
*  This file provides constants and parameter values for the SCB Component in
*  SPI and UART modes.
*
* Note:
*
********************************************************************************
* Copyright 2013-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_SCB_SPI_UART_BLE_HAL_Uart_H)
#define CY_SCB_SPI_UART_BLE_HAL_Uart_H

#include "BLE_HAL_Uart.h"


/***************************************
*   SPI Initial Parameter Constants
****************************************/

#define BLE_HAL_Uart_SPI_MODE                   (0u)
#define BLE_HAL_Uart_SPI_SUB_MODE               (0u)
#define BLE_HAL_Uart_SPI_CLOCK_MODE             (0u)
#define BLE_HAL_Uart_SPI_OVS_FACTOR             (16u)
#define BLE_HAL_Uart_SPI_MEDIAN_FILTER_ENABLE   (0u)
#define BLE_HAL_Uart_SPI_LATE_MISO_SAMPLE_ENABLE (0u)
#define BLE_HAL_Uart_SPI_RX_DATA_BITS_NUM       (8u)
#define BLE_HAL_Uart_SPI_TX_DATA_BITS_NUM       (8u)
#define BLE_HAL_Uart_SPI_WAKE_ENABLE            (0u)
#define BLE_HAL_Uart_SPI_BITS_ORDER             (1u)
#define BLE_HAL_Uart_SPI_TRANSFER_SEPARATION    (1u)
#define BLE_HAL_Uart_SPI_NUMBER_OF_SS_LINES     (1u)
#define BLE_HAL_Uart_SPI_RX_BUFFER_SIZE         (8u)
#define BLE_HAL_Uart_SPI_TX_BUFFER_SIZE         (8u)

#define BLE_HAL_Uart_SPI_INTERRUPT_MODE         (0u)

#define BLE_HAL_Uart_SPI_INTR_RX_MASK           (0u)
#define BLE_HAL_Uart_SPI_INTR_TX_MASK           (0u)

#define BLE_HAL_Uart_SPI_RX_TRIGGER_LEVEL       (7u)
#define BLE_HAL_Uart_SPI_TX_TRIGGER_LEVEL       (0u)

#define BLE_HAL_Uart_SPI_BYTE_MODE_ENABLE       (0u)
#define BLE_HAL_Uart_SPI_FREE_RUN_SCLK_ENABLE   (0u)
#define BLE_HAL_Uart_SPI_SS0_POLARITY           (0u)
#define BLE_HAL_Uart_SPI_SS1_POLARITY           (0u)
#define BLE_HAL_Uart_SPI_SS2_POLARITY           (0u)
#define BLE_HAL_Uart_SPI_SS3_POLARITY           (0u)


/***************************************
*   UART Initial Parameter Constants
****************************************/

#define BLE_HAL_Uart_UART_SUB_MODE              (0u)
#define BLE_HAL_Uart_UART_DIRECTION             (3u)
#define BLE_HAL_Uart_UART_DATA_BITS_NUM         (8u)
#define BLE_HAL_Uart_UART_PARITY_TYPE           (2u)
#define BLE_HAL_Uart_UART_STOP_BITS_NUM         (2u)
#define BLE_HAL_Uart_UART_OVS_FACTOR            (16u)
#define BLE_HAL_Uart_UART_IRDA_LOW_POWER        (0u)
#define BLE_HAL_Uart_UART_MEDIAN_FILTER_ENABLE  (0u)
#define BLE_HAL_Uart_UART_RETRY_ON_NACK         (0u)
#define BLE_HAL_Uart_UART_IRDA_POLARITY         (0u)
#define BLE_HAL_Uart_UART_DROP_ON_FRAME_ERR     (0u)
#define BLE_HAL_Uart_UART_DROP_ON_PARITY_ERR    (0u)
#define BLE_HAL_Uart_UART_WAKE_ENABLE           (0u)
#define BLE_HAL_Uart_UART_RX_BUFFER_SIZE        (8u)
#define BLE_HAL_Uart_UART_TX_BUFFER_SIZE        (8u)
#define BLE_HAL_Uart_UART_MP_MODE_ENABLE        (0u)
#define BLE_HAL_Uart_UART_MP_ACCEPT_ADDRESS     (0u)
#define BLE_HAL_Uart_UART_MP_RX_ADDRESS         (2u)
#define BLE_HAL_Uart_UART_MP_RX_ADDRESS_MASK    (255u)

#define BLE_HAL_Uart_UART_INTERRUPT_MODE        (2u)

#define BLE_HAL_Uart_UART_INTR_RX_MASK          (100u)
#define BLE_HAL_Uart_UART_INTR_TX_MASK          (544u)

#define BLE_HAL_Uart_UART_RX_TRIGGER_LEVEL      (7u)
#define BLE_HAL_Uart_UART_TX_TRIGGER_LEVEL      (0u)

#define BLE_HAL_Uart_UART_BYTE_MODE_ENABLE      (0u)
#define BLE_HAL_Uart_UART_CTS_ENABLE            (1u)
#define BLE_HAL_Uart_UART_CTS_POLARITY          (0u)
#define BLE_HAL_Uart_UART_RTS_ENABLE            (1u)
#define BLE_HAL_Uart_UART_RTS_POLARITY          (0u)
#define BLE_HAL_Uart_UART_RTS_FIFO_LEVEL        (4u)

/* SPI mode enum */
#define BLE_HAL_Uart_SPI_SLAVE  (0u)
#define BLE_HAL_Uart_SPI_MASTER (1u)

/* UART direction enum */
#define BLE_HAL_Uart_UART_RX    (1u)
#define BLE_HAL_Uart_UART_TX    (2u)
#define BLE_HAL_Uart_UART_TX_RX (3u)


/***************************************
*   Conditional Compilation Parameters
****************************************/

#if(BLE_HAL_Uart_SCB_MODE_UNCONFIG_CONST_CFG)

    /* Mode */
    #define BLE_HAL_Uart_SPI_SLAVE_CONST        (1u)
    #define BLE_HAL_Uart_SPI_MASTER_CONST       (1u)

    /* Direction */
    #define BLE_HAL_Uart_RX_DIRECTION           (1u)
    #define BLE_HAL_Uart_TX_DIRECTION           (1u)
    #define BLE_HAL_Uart_UART_RX_DIRECTION      (1u)
    #define BLE_HAL_Uart_UART_TX_DIRECTION      (1u)

    /* Only external RX and TX buffer for Uncofigured mode */
    #define BLE_HAL_Uart_INTERNAL_RX_SW_BUFFER   (0u)
    #define BLE_HAL_Uart_INTERNAL_TX_SW_BUFFER   (0u)

    /* Get RX and TX buffer size */
    #define BLE_HAL_Uart_INTERNAL_RX_BUFFER_SIZE    (BLE_HAL_Uart_rxBufferSize + 1u)
    #define BLE_HAL_Uart_RX_BUFFER_SIZE             (BLE_HAL_Uart_rxBufferSize)
    #define BLE_HAL_Uart_TX_BUFFER_SIZE             (BLE_HAL_Uart_txBufferSize)

    /* Return true if buffer is provided */
    #define BLE_HAL_Uart_CHECK_RX_SW_BUFFER (NULL != BLE_HAL_Uart_rxBuffer)
    #define BLE_HAL_Uart_CHECK_TX_SW_BUFFER (NULL != BLE_HAL_Uart_txBuffer)

    /* Always provide global variables to support RX and TX buffers */
    #define BLE_HAL_Uart_INTERNAL_RX_SW_BUFFER_CONST    (1u)
    #define BLE_HAL_Uart_INTERNAL_TX_SW_BUFFER_CONST    (1u)

    /* Get wakeup enable option */
    #define BLE_HAL_Uart_SPI_WAKE_ENABLE_CONST  (1u)
    #define BLE_HAL_Uart_CHECK_SPI_WAKE_ENABLE  (0u != BLE_HAL_Uart_scbEnableWake)
    #define BLE_HAL_Uart_UART_WAKE_ENABLE_CONST (1u)

    /* SPI/UART: TX or RX FIFO size */
    #if (BLE_HAL_Uart_CY_SCBIP_V0 || BLE_HAL_Uart_CY_SCBIP_V1)
        #define BLE_HAL_Uart_SPI_UART_FIFO_SIZE             (BLE_HAL_Uart_FIFO_SIZE)
        #define BLE_HAL_Uart_CHECK_UART_RTS_CONTROL_FLOW    (0u)
    #else
        #define BLE_HAL_Uart_SPI_UART_FIFO_SIZE (BLE_HAL_Uart_GET_FIFO_SIZE(BLE_HAL_Uart_CTRL_REG & \
                                                                                    BLE_HAL_Uart_CTRL_BYTE_MODE))

        #define BLE_HAL_Uart_CHECK_UART_RTS_CONTROL_FLOW \
                    ((BLE_HAL_Uart_SCB_MODE_UART_RUNTM_CFG) && \
                     (0u != BLE_HAL_Uart_GET_UART_FLOW_CTRL_TRIGGER_LEVEL(BLE_HAL_Uart_UART_FLOW_CTRL_REG)))
    #endif /* (BLE_HAL_Uart_CY_SCBIP_V0 || BLE_HAL_Uart_CY_SCBIP_V1) */

#else

    /* Internal RX and TX buffer: for SPI or UART */
    #if (BLE_HAL_Uart_SCB_MODE_SPI_CONST_CFG)

        /* SPI Direction */
        #define BLE_HAL_Uart_SPI_RX_DIRECTION (1u)
        #define BLE_HAL_Uart_SPI_TX_DIRECTION (1u)

        /* Get FIFO size */
        #if (BLE_HAL_Uart_CY_SCBIP_V0 || BLE_HAL_Uart_CY_SCBIP_V1)
            #define BLE_HAL_Uart_SPI_UART_FIFO_SIZE    (BLE_HAL_Uart_FIFO_SIZE)
        #else
            #define BLE_HAL_Uart_SPI_UART_FIFO_SIZE \
                                           BLE_HAL_Uart_GET_FIFO_SIZE(BLE_HAL_Uart_SPI_BYTE_MODE_ENABLE)

        #endif /* (BLE_HAL_Uart_CY_SCBIP_V0 || BLE_HAL_Uart_CY_SCBIP_V1) */

        /* SPI internal RX and TX buffers */
        #define BLE_HAL_Uart_INTERNAL_SPI_RX_SW_BUFFER  (BLE_HAL_Uart_SPI_RX_BUFFER_SIZE > \
                                                                BLE_HAL_Uart_SPI_UART_FIFO_SIZE)
        #define BLE_HAL_Uart_INTERNAL_SPI_TX_SW_BUFFER  (BLE_HAL_Uart_SPI_TX_BUFFER_SIZE > \
                                                                BLE_HAL_Uart_SPI_UART_FIFO_SIZE)

        /* Internal SPI RX and TX buffer */
        #define BLE_HAL_Uart_INTERNAL_RX_SW_BUFFER  (BLE_HAL_Uart_INTERNAL_SPI_RX_SW_BUFFER)
        #define BLE_HAL_Uart_INTERNAL_TX_SW_BUFFER  (BLE_HAL_Uart_INTERNAL_SPI_TX_SW_BUFFER)

        /* Internal SPI RX and TX buffer size */
        #define BLE_HAL_Uart_INTERNAL_RX_BUFFER_SIZE    (BLE_HAL_Uart_SPI_RX_BUFFER_SIZE + 1u)
        #define BLE_HAL_Uart_RX_BUFFER_SIZE             (BLE_HAL_Uart_SPI_RX_BUFFER_SIZE)
        #define BLE_HAL_Uart_TX_BUFFER_SIZE             (BLE_HAL_Uart_SPI_TX_BUFFER_SIZE)

        /* Get wakeup enable option */
        #define BLE_HAL_Uart_SPI_WAKE_ENABLE_CONST  (0u != BLE_HAL_Uart_SPI_WAKE_ENABLE)
        #define BLE_HAL_Uart_UART_WAKE_ENABLE_CONST (0u)

    #else

        /* UART Direction */
        #define BLE_HAL_Uart_UART_RX_DIRECTION (0u != (BLE_HAL_Uart_UART_DIRECTION & BLE_HAL_Uart_UART_RX))
        #define BLE_HAL_Uart_UART_TX_DIRECTION (0u != (BLE_HAL_Uart_UART_DIRECTION & BLE_HAL_Uart_UART_TX))

        /* Get FIFO size */
        #if (BLE_HAL_Uart_CY_SCBIP_V0 || BLE_HAL_Uart_CY_SCBIP_V1)
            #define BLE_HAL_Uart_SPI_UART_FIFO_SIZE    (BLE_HAL_Uart_FIFO_SIZE)
        #else
            #define BLE_HAL_Uart_SPI_UART_FIFO_SIZE \
                                           BLE_HAL_Uart_GET_FIFO_SIZE(BLE_HAL_Uart_UART_BYTE_MODE_ENABLE)
        #endif /* (BLE_HAL_Uart_CY_SCBIP_V0 || BLE_HAL_Uart_CY_SCBIP_V1) */

        /* UART internal RX and TX buffers */
        #define BLE_HAL_Uart_INTERNAL_UART_RX_SW_BUFFER  (BLE_HAL_Uart_UART_RX_BUFFER_SIZE > \
                                                                BLE_HAL_Uart_SPI_UART_FIFO_SIZE)
        #define BLE_HAL_Uart_INTERNAL_UART_TX_SW_BUFFER  (BLE_HAL_Uart_UART_TX_BUFFER_SIZE > \
                                                                    BLE_HAL_Uart_SPI_UART_FIFO_SIZE)

        /* Internal UART RX and TX buffer */
        #define BLE_HAL_Uart_INTERNAL_RX_SW_BUFFER  (BLE_HAL_Uart_INTERNAL_UART_RX_SW_BUFFER)
        #define BLE_HAL_Uart_INTERNAL_TX_SW_BUFFER  (BLE_HAL_Uart_INTERNAL_UART_TX_SW_BUFFER)

        /* Internal UART RX and TX buffer size */
        #define BLE_HAL_Uart_INTERNAL_RX_BUFFER_SIZE    (BLE_HAL_Uart_UART_RX_BUFFER_SIZE + 1u)
        #define BLE_HAL_Uart_RX_BUFFER_SIZE             (BLE_HAL_Uart_UART_RX_BUFFER_SIZE)
        #define BLE_HAL_Uart_TX_BUFFER_SIZE             (BLE_HAL_Uart_UART_TX_BUFFER_SIZE)

        /* Get wakeup enable option */
        #define BLE_HAL_Uart_SPI_WAKE_ENABLE_CONST  (0u)
        #define BLE_HAL_Uart_UART_WAKE_ENABLE_CONST (0u != BLE_HAL_Uart_UART_WAKE_ENABLE)

    #endif /* (BLE_HAL_Uart_SCB_MODE_SPI_CONST_CFG) */

    /* Mode */
    #define BLE_HAL_Uart_SPI_SLAVE_CONST    (BLE_HAL_Uart_SPI_MODE == BLE_HAL_Uart_SPI_SLAVE)
    #define BLE_HAL_Uart_SPI_MASTER_CONST   (BLE_HAL_Uart_SPI_MODE == BLE_HAL_Uart_SPI_MASTER)

    /* Direction */
    #define BLE_HAL_Uart_RX_DIRECTION ((BLE_HAL_Uart_SCB_MODE_SPI_CONST_CFG) ? \
                                            (BLE_HAL_Uart_SPI_RX_DIRECTION) : (BLE_HAL_Uart_UART_RX_DIRECTION))

    #define BLE_HAL_Uart_TX_DIRECTION ((BLE_HAL_Uart_SCB_MODE_SPI_CONST_CFG) ? \
                                            (BLE_HAL_Uart_SPI_TX_DIRECTION) : (BLE_HAL_Uart_UART_TX_DIRECTION))

    /* Internal RX and TX buffer: for SPI or UART. Used in conditional compilation check */
    #define BLE_HAL_Uart_CHECK_RX_SW_BUFFER (BLE_HAL_Uart_INTERNAL_RX_SW_BUFFER)
    #define BLE_HAL_Uart_CHECK_TX_SW_BUFFER (BLE_HAL_Uart_INTERNAL_TX_SW_BUFFER)

    /* Provide global variables to support RX and TX buffers */
    #define BLE_HAL_Uart_INTERNAL_RX_SW_BUFFER_CONST    (BLE_HAL_Uart_INTERNAL_RX_SW_BUFFER)
    #define BLE_HAL_Uart_INTERNAL_TX_SW_BUFFER_CONST    (BLE_HAL_Uart_INTERNAL_TX_SW_BUFFER)

    /* SPI wakeup */
    #define BLE_HAL_Uart_CHECK_SPI_WAKE_ENABLE  (BLE_HAL_Uart_SPI_WAKE_ENABLE_CONST)

    /* UART flow control: not applicable for CY_SCBIP_V0 || CY_SCBIP_V1 */
    #define BLE_HAL_Uart_CHECK_UART_RTS_CONTROL_FLOW    (BLE_HAL_Uart_SCB_MODE_UART_CONST_CFG && \
                                                             BLE_HAL_Uart_UART_RTS_ENABLE)

#endif /* End (BLE_HAL_Uart_SCB_MODE_UNCONFIG_CONST_CFG) */


/***************************************
*       Type Definitions
***************************************/

/* BLE_HAL_Uart_SPI_INIT_STRUCT */
typedef struct
{
    uint32 mode;
    uint32 submode;
    uint32 sclkMode;
    uint32 oversample;
    uint32 enableMedianFilter;
    uint32 enableLateSampling;
    uint32 enableWake;
    uint32 rxDataBits;
    uint32 txDataBits;
    uint32 bitOrder;
    uint32 transferSeperation;
    uint32 rxBufferSize;
    uint8* rxBuffer;
    uint32 txBufferSize;
    uint8* txBuffer;
    uint32 enableInterrupt;
    uint32 rxInterruptMask;
    uint32 rxTriggerLevel;
    uint32 txInterruptMask;
    uint32 txTriggerLevel;
    uint8 enableByteMode;
    uint8 enableFreeRunSclk;
    uint8 polaritySs;
} BLE_HAL_Uart_SPI_INIT_STRUCT;

/* BLE_HAL_Uart_UART_INIT_STRUCT */
typedef struct
{
    uint32 mode;
    uint32 direction;
    uint32 dataBits;
    uint32 parity;
    uint32 stopBits;
    uint32 oversample;
    uint32 enableIrdaLowPower;
    uint32 enableMedianFilter;
    uint32 enableRetryNack;
    uint32 enableInvertedRx;
    uint32 dropOnParityErr;
    uint32 dropOnFrameErr;
    uint32 enableWake;
    uint32 rxBufferSize;
    uint8* rxBuffer;
    uint32 txBufferSize;
    uint8* txBuffer;
    uint32 enableMultiproc;
    uint32 multiprocAcceptAddr;
    uint32 multiprocAddr;
    uint32 multiprocAddrMask;
    uint32 enableInterrupt;
    uint32 rxInterruptMask;
    uint32 rxTriggerLevel;
    uint32 txInterruptMask;
    uint32 txTriggerLevel;
    uint8 enableByteMode;
    uint8 enableCts;
    uint8 ctsPolarity;
    uint8 rtsRxFifoLevel;
    uint8 rtsPolarity;
} BLE_HAL_Uart_UART_INIT_STRUCT;


/***************************************
*        Function Prototypes
***************************************/

/* SPI specific functions */
#if(BLE_HAL_Uart_SCB_MODE_UNCONFIG_CONST_CFG)
    void BLE_HAL_Uart_SpiInit(const BLE_HAL_Uart_SPI_INIT_STRUCT *config);
#endif /* (BLE_HAL_Uart_SCB_MODE_UNCONFIG_CONST_CFG) */

#if(BLE_HAL_Uart_SCB_MODE_SPI_INC)
    #define BLE_HAL_Uart_SpiIsBusBusy() ((uint32) (0u != (BLE_HAL_Uart_SPI_STATUS_REG & \
                                                              BLE_HAL_Uart_SPI_STATUS_BUS_BUSY)))

    #if (BLE_HAL_Uart_SPI_MASTER_CONST)
        void BLE_HAL_Uart_SpiSetActiveSlaveSelect(uint32 slaveSelect);
    #endif /*(BLE_HAL_Uart_SPI_MASTER_CONST) */

    #if !(BLE_HAL_Uart_CY_SCBIP_V0 || BLE_HAL_Uart_CY_SCBIP_V1)
        void BLE_HAL_Uart_SpiSetSlaveSelectPolarity(uint32 slaveSelect, uint32 polarity);
    #endif /* !(BLE_HAL_Uart_CY_SCBIP_V0 || BLE_HAL_Uart_CY_SCBIP_V1) */
#endif /* (BLE_HAL_Uart_SCB_MODE_SPI_INC) */

/* UART specific functions */
#if(BLE_HAL_Uart_SCB_MODE_UNCONFIG_CONST_CFG)
    void BLE_HAL_Uart_UartInit(const BLE_HAL_Uart_UART_INIT_STRUCT *config);
#endif /* (BLE_HAL_Uart_SCB_MODE_UNCONFIG_CONST_CFG) */

#if(BLE_HAL_Uart_SCB_MODE_UART_INC)
    void BLE_HAL_Uart_UartSetRxAddress(uint32 address);
    void BLE_HAL_Uart_UartSetRxAddressMask(uint32 addressMask);

    /* UART RX direction APIs */
    #if(BLE_HAL_Uart_UART_RX_DIRECTION)
        uint32 BLE_HAL_Uart_UartGetChar(void);
        uint32 BLE_HAL_Uart_UartGetByte(void);

        #if !(BLE_HAL_Uart_CY_SCBIP_V0 || BLE_HAL_Uart_CY_SCBIP_V1)
            /* UART APIs for Flow Control */
            void BLE_HAL_Uart_UartSetRtsPolarity(uint32 polarity);
            void BLE_HAL_Uart_UartSetRtsFifoLevel(uint32 level);
        #endif /* !(BLE_HAL_Uart_CY_SCBIP_V0 || BLE_HAL_Uart_CY_SCBIP_V1) */
    #endif /* (BLE_HAL_Uart_UART_RX_DIRECTION) */

    /* UART TX direction APIs */
    #if(BLE_HAL_Uart_UART_TX_DIRECTION)
        #define BLE_HAL_Uart_UartPutChar(ch)    BLE_HAL_Uart_SpiUartWriteTxData((uint32)(ch))
        void BLE_HAL_Uart_UartPutString(const char8 string[]);
        void BLE_HAL_Uart_UartPutCRLF(uint32 txDataByte);

        #if !(BLE_HAL_Uart_CY_SCBIP_V0 || BLE_HAL_Uart_CY_SCBIP_V1)
            /* UART APIs for Flow Control */
            void BLE_HAL_Uart_UartEnableCts(void);
            void BLE_HAL_Uart_UartDisableCts(void);
            void BLE_HAL_Uart_UartSetCtsPolarity(uint32 polarity);
        #endif /* !(BLE_HAL_Uart_CY_SCBIP_V0 || BLE_HAL_Uart_CY_SCBIP_V1) */
    #endif /* (BLE_HAL_Uart_UART_TX_DIRECTION) */
#endif /* (BLE_HAL_Uart_SCB_MODE_UART_INC) */

/* Common APIs RX direction */
#if(BLE_HAL_Uart_RX_DIRECTION)
    uint32 BLE_HAL_Uart_SpiUartReadRxData(void);
    uint32 BLE_HAL_Uart_SpiUartGetRxBufferSize(void);
    void   BLE_HAL_Uart_SpiUartClearRxBuffer(void);
#endif /* (BLE_HAL_Uart_RX_DIRECTION) */

/* Common APIs TX direction */
#if(BLE_HAL_Uart_TX_DIRECTION)
    void   BLE_HAL_Uart_SpiUartWriteTxData(uint32 txData);
    void   BLE_HAL_Uart_SpiUartPutArray(const uint8 wrBuf[], uint32 count);
    uint32 BLE_HAL_Uart_SpiUartGetTxBufferSize(void);
    void   BLE_HAL_Uart_SpiUartClearTxBuffer(void);
#endif /* (BLE_HAL_Uart_TX_DIRECTION) */

CY_ISR_PROTO(BLE_HAL_Uart_SPI_UART_ISR);

#if(BLE_HAL_Uart_UART_RX_WAKEUP_IRQ)
    CY_ISR_PROTO(BLE_HAL_Uart_UART_WAKEUP_ISR);
#endif /* (BLE_HAL_Uart_UART_RX_WAKEUP_IRQ) */


/***************************************
*     Buffer Access Macro Definitions
***************************************/

#if(BLE_HAL_Uart_SCB_MODE_UNCONFIG_CONST_CFG)
    /* RX direction */
    void   BLE_HAL_Uart_PutWordInRxBuffer  (uint32 idx, uint32 rxDataByte);
    uint32 BLE_HAL_Uart_GetWordFromRxBuffer(uint32 idx);

    /* TX direction */
    void   BLE_HAL_Uart_PutWordInTxBuffer  (uint32 idx, uint32 txDataByte);
    uint32 BLE_HAL_Uart_GetWordFromTxBuffer(uint32 idx);

#else
    /* RX direction */
    #if(BLE_HAL_Uart_INTERNAL_RX_SW_BUFFER_CONST)
        #define BLE_HAL_Uart_PutWordInRxBuffer(idx, rxDataByte) \
                do{                                                 \
                    BLE_HAL_Uart_rxBufferInternal[(idx)] = ((uint8) (rxDataByte)); \
                }while(0)

        #define BLE_HAL_Uart_GetWordFromRxBuffer(idx) BLE_HAL_Uart_rxBufferInternal[(idx)]

    #endif /* (BLE_HAL_Uart_INTERNAL_RX_SW_BUFFER_CONST) */

    /* TX direction */
    #if(BLE_HAL_Uart_INTERNAL_TX_SW_BUFFER_CONST)
        #define BLE_HAL_Uart_PutWordInTxBuffer(idx, txDataByte) \
                    do{                                             \
                        BLE_HAL_Uart_txBufferInternal[(idx)] = ((uint8) (txDataByte)); \
                    }while(0)

        #define BLE_HAL_Uart_GetWordFromTxBuffer(idx) BLE_HAL_Uart_txBufferInternal[(idx)]

    #endif /* (BLE_HAL_Uart_INTERNAL_TX_SW_BUFFER_CONST) */

#endif /* (BLE_HAL_Uart_TX_SW_BUFFER_ENABLE) */


/***************************************
*         SPI API Constants
***************************************/

/* SPI sub mode enum */
#define BLE_HAL_Uart_SPI_MODE_MOTOROLA      (0x00u)
#define BLE_HAL_Uart_SPI_MODE_TI_COINCIDES  (0x01u)
#define BLE_HAL_Uart_SPI_MODE_TI_PRECEDES   (0x11u)
#define BLE_HAL_Uart_SPI_MODE_NATIONAL      (0x02u)
#define BLE_HAL_Uart_SPI_MODE_MASK          (0x03u)
#define BLE_HAL_Uart_SPI_MODE_TI_PRECEDES_MASK  (0x10u)
#define BLE_HAL_Uart_SPI_MODE_NS_MICROWIRE  (BLE_HAL_Uart_SPI_MODE_NATIONAL)

/* SPI phase and polarity mode enum */
#define BLE_HAL_Uart_SPI_SCLK_CPHA0_CPOL0   (0x00u)
#define BLE_HAL_Uart_SPI_SCLK_CPHA0_CPOL1   (0x02u)
#define BLE_HAL_Uart_SPI_SCLK_CPHA1_CPOL0   (0x01u)
#define BLE_HAL_Uart_SPI_SCLK_CPHA1_CPOL1   (0x03u)

/* SPI bits order enum */
#define BLE_HAL_Uart_BITS_ORDER_LSB_FIRST   (0u)
#define BLE_HAL_Uart_BITS_ORDER_MSB_FIRST   (1u)

/* SPI transfer separation enum */
#define BLE_HAL_Uart_SPI_TRANSFER_SEPARATED     (0u)
#define BLE_HAL_Uart_SPI_TRANSFER_CONTINUOUS    (1u)

/* SPI slave select constants */
#define BLE_HAL_Uart_SPI_SLAVE_SELECT0    (BLE_HAL_Uart_SCB__SS0_POSISTION)
#define BLE_HAL_Uart_SPI_SLAVE_SELECT1    (BLE_HAL_Uart_SCB__SS1_POSISTION)
#define BLE_HAL_Uart_SPI_SLAVE_SELECT2    (BLE_HAL_Uart_SCB__SS2_POSISTION)
#define BLE_HAL_Uart_SPI_SLAVE_SELECT3    (BLE_HAL_Uart_SCB__SS3_POSISTION)

/* SPI slave select polarity settings */
#define BLE_HAL_Uart_SPI_SS_ACTIVE_LOW  (0u)
#define BLE_HAL_Uart_SPI_SS_ACTIVE_HIGH (1u)


/***************************************
*         UART API Constants
***************************************/

/* UART sub-modes enum */
#define BLE_HAL_Uart_UART_MODE_STD          (0u)
#define BLE_HAL_Uart_UART_MODE_SMARTCARD    (1u)
#define BLE_HAL_Uart_UART_MODE_IRDA         (2u)

/* UART direction enum */
#define BLE_HAL_Uart_UART_RX    (1u)
#define BLE_HAL_Uart_UART_TX    (2u)
#define BLE_HAL_Uart_UART_TX_RX (3u)

/* UART parity enum */
#define BLE_HAL_Uart_UART_PARITY_EVEN   (0u)
#define BLE_HAL_Uart_UART_PARITY_ODD    (1u)
#define BLE_HAL_Uart_UART_PARITY_NONE   (2u)

/* UART stop bits enum */
#define BLE_HAL_Uart_UART_STOP_BITS_1   (2u)
#define BLE_HAL_Uart_UART_STOP_BITS_1_5 (3u)
#define BLE_HAL_Uart_UART_STOP_BITS_2   (4u)

/* UART IrDA low power OVS enum */
#define BLE_HAL_Uart_UART_IRDA_LP_OVS16     (16u)
#define BLE_HAL_Uart_UART_IRDA_LP_OVS32     (32u)
#define BLE_HAL_Uart_UART_IRDA_LP_OVS48     (48u)
#define BLE_HAL_Uart_UART_IRDA_LP_OVS96     (96u)
#define BLE_HAL_Uart_UART_IRDA_LP_OVS192    (192u)
#define BLE_HAL_Uart_UART_IRDA_LP_OVS768    (768u)
#define BLE_HAL_Uart_UART_IRDA_LP_OVS1536   (1536u)

/* Uart MP: mark (address) and space (data) bit definitions */
#define BLE_HAL_Uart_UART_MP_MARK       (0x100u)
#define BLE_HAL_Uart_UART_MP_SPACE      (0x000u)

/* UART CTS/RTS polarity settings */
#define BLE_HAL_Uart_UART_CTS_ACTIVE_LOW    (0u)
#define BLE_HAL_Uart_UART_CTS_ACTIVE_HIGH   (1u)
#define BLE_HAL_Uart_UART_RTS_ACTIVE_LOW    (0u)
#define BLE_HAL_Uart_UART_RTS_ACTIVE_HIGH   (1u)

/* Sources of RX errors */
#define BLE_HAL_Uart_INTR_RX_ERR        (BLE_HAL_Uart_INTR_RX_OVERFLOW    | \
                                             BLE_HAL_Uart_INTR_RX_UNDERFLOW   | \
                                             BLE_HAL_Uart_INTR_RX_FRAME_ERROR | \
                                             BLE_HAL_Uart_INTR_RX_PARITY_ERROR)

/* Shifted INTR_RX_ERR defines ONLY for BLE_HAL_Uart_UartGetByte() */
#define BLE_HAL_Uart_UART_RX_OVERFLOW       (BLE_HAL_Uart_INTR_RX_OVERFLOW << 8u)
#define BLE_HAL_Uart_UART_RX_UNDERFLOW      (BLE_HAL_Uart_INTR_RX_UNDERFLOW << 8u)
#define BLE_HAL_Uart_UART_RX_FRAME_ERROR    (BLE_HAL_Uart_INTR_RX_FRAME_ERROR << 8u)
#define BLE_HAL_Uart_UART_RX_PARITY_ERROR   (BLE_HAL_Uart_INTR_RX_PARITY_ERROR << 8u)
#define BLE_HAL_Uart_UART_RX_ERROR_MASK     (BLE_HAL_Uart_UART_RX_OVERFLOW    | \
                                                 BLE_HAL_Uart_UART_RX_UNDERFLOW   | \
                                                 BLE_HAL_Uart_UART_RX_FRAME_ERROR | \
                                                 BLE_HAL_Uart_UART_RX_PARITY_ERROR)


/***************************************
*     Vars with External Linkage
***************************************/

#if(BLE_HAL_Uart_SCB_MODE_UNCONFIG_CONST_CFG)
    extern const BLE_HAL_Uart_SPI_INIT_STRUCT  BLE_HAL_Uart_configSpi;
    extern const BLE_HAL_Uart_UART_INIT_STRUCT BLE_HAL_Uart_configUart;
#endif /* (BLE_HAL_Uart_SCB_MODE_UNCONFIG_CONST_CFG) */


/***************************************
*    Specific SPI Macro Definitions
***************************************/

#define BLE_HAL_Uart_GET_SPI_INTR_SLAVE_MASK(sourceMask)  ((sourceMask) & BLE_HAL_Uart_INTR_SLAVE_SPI_BUS_ERROR)
#define BLE_HAL_Uart_GET_SPI_INTR_MASTER_MASK(sourceMask) ((sourceMask) & BLE_HAL_Uart_INTR_MASTER_SPI_DONE)
#define BLE_HAL_Uart_GET_SPI_INTR_RX_MASK(sourceMask) \
                                             ((sourceMask) & (uint32) ~BLE_HAL_Uart_INTR_SLAVE_SPI_BUS_ERROR)

#define BLE_HAL_Uart_GET_SPI_INTR_TX_MASK(sourceMask) \
                                             ((sourceMask) & (uint32) ~BLE_HAL_Uart_INTR_MASTER_SPI_DONE)


/***************************************
*    Specific UART Macro Definitions
***************************************/

#define BLE_HAL_Uart_UART_GET_CTRL_OVS_IRDA_LP(oversample) \
        ((BLE_HAL_Uart_UART_IRDA_LP_OVS16   == (oversample)) ? BLE_HAL_Uart_CTRL_OVS_IRDA_LP_OVS16 : \
         ((BLE_HAL_Uart_UART_IRDA_LP_OVS32   == (oversample)) ? BLE_HAL_Uart_CTRL_OVS_IRDA_LP_OVS32 : \
          ((BLE_HAL_Uart_UART_IRDA_LP_OVS48   == (oversample)) ? BLE_HAL_Uart_CTRL_OVS_IRDA_LP_OVS48 : \
           ((BLE_HAL_Uart_UART_IRDA_LP_OVS96   == (oversample)) ? BLE_HAL_Uart_CTRL_OVS_IRDA_LP_OVS96 : \
            ((BLE_HAL_Uart_UART_IRDA_LP_OVS192  == (oversample)) ? BLE_HAL_Uart_CTRL_OVS_IRDA_LP_OVS192 : \
             ((BLE_HAL_Uart_UART_IRDA_LP_OVS768  == (oversample)) ? BLE_HAL_Uart_CTRL_OVS_IRDA_LP_OVS768 : \
              ((BLE_HAL_Uart_UART_IRDA_LP_OVS1536 == (oversample)) ? BLE_HAL_Uart_CTRL_OVS_IRDA_LP_OVS1536 : \
                                                                          BLE_HAL_Uart_CTRL_OVS_IRDA_LP_OVS16)))))))

#define BLE_HAL_Uart_GET_UART_RX_CTRL_ENABLED(direction) ((0u != (BLE_HAL_Uart_UART_RX & (direction))) ? \
                                                                     (BLE_HAL_Uart_RX_CTRL_ENABLED) : (0u))

#define BLE_HAL_Uart_GET_UART_TX_CTRL_ENABLED(direction) ((0u != (BLE_HAL_Uart_UART_TX & (direction))) ? \
                                                                     (BLE_HAL_Uart_TX_CTRL_ENABLED) : (0u))


/***************************************
*        SPI Register Settings
***************************************/

#define BLE_HAL_Uart_CTRL_SPI      (BLE_HAL_Uart_CTRL_MODE_SPI)
#define BLE_HAL_Uart_SPI_RX_CTRL   (BLE_HAL_Uart_RX_CTRL_ENABLED)
#define BLE_HAL_Uart_SPI_TX_CTRL   (BLE_HAL_Uart_TX_CTRL_ENABLED)


/***************************************
*       SPI Init Register Settings
***************************************/

#define BLE_HAL_Uart_SPI_SS_POLARITY \
             (((uint32) BLE_HAL_Uart_SPI_SS0_POLARITY << BLE_HAL_Uart_SPI_SLAVE_SELECT0) | \
              ((uint32) BLE_HAL_Uart_SPI_SS1_POLARITY << BLE_HAL_Uart_SPI_SLAVE_SELECT1) | \
              ((uint32) BLE_HAL_Uart_SPI_SS2_POLARITY << BLE_HAL_Uart_SPI_SLAVE_SELECT2) | \
              ((uint32) BLE_HAL_Uart_SPI_SS3_POLARITY << BLE_HAL_Uart_SPI_SLAVE_SELECT3))

#if(BLE_HAL_Uart_SCB_MODE_SPI_CONST_CFG)

    /* SPI Configuration */
    #define BLE_HAL_Uart_SPI_DEFAULT_CTRL \
                    (BLE_HAL_Uart_GET_CTRL_OVS(BLE_HAL_Uart_SPI_OVS_FACTOR) | \
                     BLE_HAL_Uart_GET_CTRL_BYTE_MODE (BLE_HAL_Uart_SPI_BYTE_MODE_ENABLE) | \
                     BLE_HAL_Uart_GET_CTRL_EC_AM_MODE(BLE_HAL_Uart_SPI_WAKE_ENABLE)      | \
                     BLE_HAL_Uart_CTRL_SPI)

    #define BLE_HAL_Uart_SPI_DEFAULT_SPI_CTRL \
                    (BLE_HAL_Uart_GET_SPI_CTRL_CONTINUOUS    (BLE_HAL_Uart_SPI_TRANSFER_SEPARATION)       | \
                     BLE_HAL_Uart_GET_SPI_CTRL_SELECT_PRECEDE(BLE_HAL_Uart_SPI_SUB_MODE &                   \
                                                                  BLE_HAL_Uart_SPI_MODE_TI_PRECEDES_MASK)     | \
                     BLE_HAL_Uart_GET_SPI_CTRL_SCLK_MODE     (BLE_HAL_Uart_SPI_CLOCK_MODE)                | \
                     BLE_HAL_Uart_GET_SPI_CTRL_LATE_MISO_SAMPLE(BLE_HAL_Uart_SPI_LATE_MISO_SAMPLE_ENABLE) | \
                     BLE_HAL_Uart_GET_SPI_CTRL_SCLK_CONTINUOUS(BLE_HAL_Uart_SPI_FREE_RUN_SCLK_ENABLE)     | \
                     BLE_HAL_Uart_GET_SPI_CTRL_SSEL_POLARITY (BLE_HAL_Uart_SPI_SS_POLARITY)               | \
                     BLE_HAL_Uart_GET_SPI_CTRL_SUB_MODE      (BLE_HAL_Uart_SPI_SUB_MODE)                  | \
                     BLE_HAL_Uart_GET_SPI_CTRL_MASTER_MODE   (BLE_HAL_Uart_SPI_MODE))

    /* RX direction */
    #define BLE_HAL_Uart_SPI_DEFAULT_RX_CTRL \
                    (BLE_HAL_Uart_GET_RX_CTRL_DATA_WIDTH(BLE_HAL_Uart_SPI_RX_DATA_BITS_NUM)     | \
                     BLE_HAL_Uart_GET_RX_CTRL_BIT_ORDER (BLE_HAL_Uart_SPI_BITS_ORDER)           | \
                     BLE_HAL_Uart_GET_RX_CTRL_MEDIAN    (BLE_HAL_Uart_SPI_MEDIAN_FILTER_ENABLE) | \
                     BLE_HAL_Uart_SPI_RX_CTRL)

    #define BLE_HAL_Uart_SPI_DEFAULT_RX_FIFO_CTRL \
                    BLE_HAL_Uart_GET_RX_FIFO_CTRL_TRIGGER_LEVEL(BLE_HAL_Uart_SPI_RX_TRIGGER_LEVEL)

    /* TX direction */
    #define BLE_HAL_Uart_SPI_DEFAULT_TX_CTRL \
                    (BLE_HAL_Uart_GET_TX_CTRL_DATA_WIDTH(BLE_HAL_Uart_SPI_TX_DATA_BITS_NUM) | \
                     BLE_HAL_Uart_GET_TX_CTRL_BIT_ORDER (BLE_HAL_Uart_SPI_BITS_ORDER)       | \
                     BLE_HAL_Uart_SPI_TX_CTRL)

    #define BLE_HAL_Uart_SPI_DEFAULT_TX_FIFO_CTRL \
                    BLE_HAL_Uart_GET_TX_FIFO_CTRL_TRIGGER_LEVEL(BLE_HAL_Uart_SPI_TX_TRIGGER_LEVEL)

    /* Interrupt sources */
    #define BLE_HAL_Uart_SPI_DEFAULT_INTR_SPI_EC_MASK   (BLE_HAL_Uart_NO_INTR_SOURCES)

    #define BLE_HAL_Uart_SPI_DEFAULT_INTR_I2C_EC_MASK   (BLE_HAL_Uart_NO_INTR_SOURCES)
    #define BLE_HAL_Uart_SPI_DEFAULT_INTR_SLAVE_MASK \
                    (BLE_HAL_Uart_SPI_INTR_RX_MASK & BLE_HAL_Uart_INTR_SLAVE_SPI_BUS_ERROR)

    #define BLE_HAL_Uart_SPI_DEFAULT_INTR_MASTER_MASK \
                    (BLE_HAL_Uart_SPI_INTR_TX_MASK & BLE_HAL_Uart_INTR_MASTER_SPI_DONE)

    #define BLE_HAL_Uart_SPI_DEFAULT_INTR_RX_MASK \
                    (BLE_HAL_Uart_SPI_INTR_RX_MASK & (uint32) ~BLE_HAL_Uart_INTR_SLAVE_SPI_BUS_ERROR)

    #define BLE_HAL_Uart_SPI_DEFAULT_INTR_TX_MASK \
                    (BLE_HAL_Uart_SPI_INTR_TX_MASK & (uint32) ~BLE_HAL_Uart_INTR_MASTER_SPI_DONE)

#endif /* (BLE_HAL_Uart_SCB_MODE_SPI_CONST_CFG) */


/***************************************
*        UART Register Settings
***************************************/

#define BLE_HAL_Uart_CTRL_UART      (BLE_HAL_Uart_CTRL_MODE_UART)
#define BLE_HAL_Uart_UART_RX_CTRL   (BLE_HAL_Uart_RX_CTRL_LSB_FIRST) /* LSB for UART goes first */
#define BLE_HAL_Uart_UART_TX_CTRL   (BLE_HAL_Uart_TX_CTRL_LSB_FIRST) /* LSB for UART goes first */


/***************************************
*      UART Init Register Settings
***************************************/

#if(BLE_HAL_Uart_SCB_MODE_UART_CONST_CFG)

    /* UART configuration */
    #if(BLE_HAL_Uart_UART_MODE_IRDA == BLE_HAL_Uart_UART_SUB_MODE)

        #define BLE_HAL_Uart_DEFAULT_CTRL_OVS   ((0u != BLE_HAL_Uart_UART_IRDA_LOW_POWER) ?              \
                                (BLE_HAL_Uart_UART_GET_CTRL_OVS_IRDA_LP(BLE_HAL_Uart_UART_OVS_FACTOR)) : \
                                (BLE_HAL_Uart_CTRL_OVS_IRDA_OVS16))

    #else

        #define BLE_HAL_Uart_DEFAULT_CTRL_OVS   BLE_HAL_Uart_GET_CTRL_OVS(BLE_HAL_Uart_UART_OVS_FACTOR)

    #endif /* (BLE_HAL_Uart_UART_MODE_IRDA == BLE_HAL_Uart_UART_SUB_MODE) */

    #define BLE_HAL_Uart_UART_DEFAULT_CTRL \
                                (BLE_HAL_Uart_GET_CTRL_BYTE_MODE  (BLE_HAL_Uart_UART_BYTE_MODE_ENABLE)  | \
                                 BLE_HAL_Uart_GET_CTRL_ADDR_ACCEPT(BLE_HAL_Uart_UART_MP_ACCEPT_ADDRESS) | \
                                 BLE_HAL_Uart_DEFAULT_CTRL_OVS                                              | \
                                 BLE_HAL_Uart_CTRL_UART)

    #define BLE_HAL_Uart_UART_DEFAULT_UART_CTRL \
                                    (BLE_HAL_Uart_GET_UART_CTRL_MODE(BLE_HAL_Uart_UART_SUB_MODE))

    /* RX direction */
    #define BLE_HAL_Uart_UART_DEFAULT_RX_CTRL_PARITY \
                                ((BLE_HAL_Uart_UART_PARITY_NONE != BLE_HAL_Uart_UART_PARITY_TYPE) ?      \
                                  (BLE_HAL_Uart_GET_UART_RX_CTRL_PARITY(BLE_HAL_Uart_UART_PARITY_TYPE) | \
                                   BLE_HAL_Uart_UART_RX_CTRL_PARITY_ENABLED) : (0u))

    #define BLE_HAL_Uart_UART_DEFAULT_UART_RX_CTRL \
                    (BLE_HAL_Uart_GET_UART_RX_CTRL_MODE(BLE_HAL_Uart_UART_STOP_BITS_NUM)                    | \
                     BLE_HAL_Uart_GET_UART_RX_CTRL_POLARITY(BLE_HAL_Uart_UART_IRDA_POLARITY)                | \
                     BLE_HAL_Uart_GET_UART_RX_CTRL_MP_MODE(BLE_HAL_Uart_UART_MP_MODE_ENABLE)                | \
                     BLE_HAL_Uart_GET_UART_RX_CTRL_DROP_ON_PARITY_ERR(BLE_HAL_Uart_UART_DROP_ON_PARITY_ERR) | \
                     BLE_HAL_Uart_GET_UART_RX_CTRL_DROP_ON_FRAME_ERR(BLE_HAL_Uart_UART_DROP_ON_FRAME_ERR)   | \
                     BLE_HAL_Uart_UART_DEFAULT_RX_CTRL_PARITY)

    #define BLE_HAL_Uart_UART_DEFAULT_RX_CTRL \
                                (BLE_HAL_Uart_GET_RX_CTRL_DATA_WIDTH(BLE_HAL_Uart_UART_DATA_BITS_NUM)        | \
                                 BLE_HAL_Uart_GET_RX_CTRL_MEDIAN    (BLE_HAL_Uart_UART_MEDIAN_FILTER_ENABLE) | \
                                 BLE_HAL_Uart_GET_UART_RX_CTRL_ENABLED(BLE_HAL_Uart_UART_DIRECTION))

    #define BLE_HAL_Uart_UART_DEFAULT_RX_FIFO_CTRL \
                                BLE_HAL_Uart_GET_RX_FIFO_CTRL_TRIGGER_LEVEL(BLE_HAL_Uart_UART_RX_TRIGGER_LEVEL)

    #define BLE_HAL_Uart_UART_DEFAULT_RX_MATCH_REG  ((0u != BLE_HAL_Uart_UART_MP_MODE_ENABLE) ?          \
                                (BLE_HAL_Uart_GET_RX_MATCH_ADDR(BLE_HAL_Uart_UART_MP_RX_ADDRESS) | \
                                 BLE_HAL_Uart_GET_RX_MATCH_MASK(BLE_HAL_Uart_UART_MP_RX_ADDRESS_MASK)) : (0u))

    /* TX direction */
    #define BLE_HAL_Uart_UART_DEFAULT_TX_CTRL_PARITY (BLE_HAL_Uart_UART_DEFAULT_RX_CTRL_PARITY)

    #define BLE_HAL_Uart_UART_DEFAULT_UART_TX_CTRL \
                                (BLE_HAL_Uart_GET_UART_TX_CTRL_MODE(BLE_HAL_Uart_UART_STOP_BITS_NUM)       | \
                                 BLE_HAL_Uart_GET_UART_TX_CTRL_RETRY_NACK(BLE_HAL_Uart_UART_RETRY_ON_NACK) | \
                                 BLE_HAL_Uart_UART_DEFAULT_TX_CTRL_PARITY)

    #define BLE_HAL_Uart_UART_DEFAULT_TX_CTRL \
                                (BLE_HAL_Uart_GET_TX_CTRL_DATA_WIDTH(BLE_HAL_Uart_UART_DATA_BITS_NUM) | \
                                 BLE_HAL_Uart_GET_UART_TX_CTRL_ENABLED(BLE_HAL_Uart_UART_DIRECTION))

    #define BLE_HAL_Uart_UART_DEFAULT_TX_FIFO_CTRL \
                                BLE_HAL_Uart_GET_TX_FIFO_CTRL_TRIGGER_LEVEL(BLE_HAL_Uart_UART_TX_TRIGGER_LEVEL)

    #define BLE_HAL_Uart_UART_DEFAULT_FLOW_CTRL \
                        (BLE_HAL_Uart_GET_UART_FLOW_CTRL_TRIGGER_LEVEL(BLE_HAL_Uart_UART_RTS_FIFO_LEVEL) | \
                         BLE_HAL_Uart_GET_UART_FLOW_CTRL_RTS_POLARITY (BLE_HAL_Uart_UART_RTS_POLARITY)   | \
                         BLE_HAL_Uart_GET_UART_FLOW_CTRL_CTS_POLARITY (BLE_HAL_Uart_UART_CTS_POLARITY)   | \
                         BLE_HAL_Uart_GET_UART_FLOW_CTRL_CTS_ENABLE   (BLE_HAL_Uart_UART_CTS_ENABLE))

    /* Interrupt sources */
    #define BLE_HAL_Uart_UART_DEFAULT_INTR_I2C_EC_MASK  (BLE_HAL_Uart_NO_INTR_SOURCES)
    #define BLE_HAL_Uart_UART_DEFAULT_INTR_SPI_EC_MASK  (BLE_HAL_Uart_NO_INTR_SOURCES)
    #define BLE_HAL_Uart_UART_DEFAULT_INTR_SLAVE_MASK   (BLE_HAL_Uart_NO_INTR_SOURCES)
    #define BLE_HAL_Uart_UART_DEFAULT_INTR_MASTER_MASK  (BLE_HAL_Uart_NO_INTR_SOURCES)
    #define BLE_HAL_Uart_UART_DEFAULT_INTR_RX_MASK      (BLE_HAL_Uart_UART_INTR_RX_MASK)
    #define BLE_HAL_Uart_UART_DEFAULT_INTR_TX_MASK      (BLE_HAL_Uart_UART_INTR_TX_MASK)

#endif /* (BLE_HAL_Uart_SCB_MODE_UART_CONST_CFG) */


/***************************************
* The following code is DEPRECATED and
* must not be used.
***************************************/

#define BLE_HAL_Uart_SPIM_ACTIVE_SS0    (BLE_HAL_Uart_SPI_SLAVE_SELECT0)
#define BLE_HAL_Uart_SPIM_ACTIVE_SS1    (BLE_HAL_Uart_SPI_SLAVE_SELECT1)
#define BLE_HAL_Uart_SPIM_ACTIVE_SS2    (BLE_HAL_Uart_SPI_SLAVE_SELECT2)
#define BLE_HAL_Uart_SPIM_ACTIVE_SS3    (BLE_HAL_Uart_SPI_SLAVE_SELECT3)

#endif /* CY_SCB_SPI_UART_BLE_HAL_Uart_H */


/* [] END OF FILE */
