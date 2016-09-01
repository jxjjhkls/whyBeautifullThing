/*******************************************************************************
* File Name: BLE_HAL_Uart_SPI_UART_INT.c
* Version 3.10
*
* Description:
*  This file provides the source code to the Interrupt Service Routine for
*  the SCB Component in SPI and UART modes.
*
* Note:
*
********************************************************************************
* Copyright 2013-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "BLE_HAL_Uart_PVT.h"
#include "BLE_HAL_Uart_SPI_UART_PVT.h"
#include "cyapicallbacks.h"

#if (BLE_HAL_Uart_SCB_IRQ_INTERNAL)
/*******************************************************************************
* Function Name: BLE_HAL_Uart_SPI_UART_ISR
********************************************************************************
*
* Summary:
*  Handles the Interrupt Service Routine for the SCB SPI or UART modes.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
CY_ISR(BLE_HAL_Uart_SPI_UART_ISR)
{
#if (BLE_HAL_Uart_INTERNAL_RX_SW_BUFFER_CONST)
    uint32 locHead;
#endif /* (BLE_HAL_Uart_INTERNAL_RX_SW_BUFFER_CONST) */

#if (BLE_HAL_Uart_INTERNAL_TX_SW_BUFFER_CONST)
    uint32 locTail;
#endif /* (BLE_HAL_Uart_INTERNAL_TX_SW_BUFFER_CONST) */

#ifdef BLE_HAL_Uart_SPI_UART_ISR_ENTRY_CALLBACK
    BLE_HAL_Uart_SPI_UART_ISR_EntryCallback();
#endif /* BLE_HAL_Uart_SPI_UART_ISR_ENTRY_CALLBACK */

    if (NULL != BLE_HAL_Uart_customIntrHandler)
    {
        BLE_HAL_Uart_customIntrHandler();
    }

    #if (BLE_HAL_Uart_CHECK_SPI_WAKE_ENABLE)
    {
        /* Clear SPI wakeup source */
        BLE_HAL_Uart_ClearSpiExtClkInterruptSource(BLE_HAL_Uart_INTR_SPI_EC_WAKE_UP);
    }
    #endif

    #if (BLE_HAL_Uart_CHECK_RX_SW_BUFFER)
    {
        if (BLE_HAL_Uart_CHECK_INTR_RX_MASKED(BLE_HAL_Uart_INTR_RX_NOT_EMPTY))
        {
            do
            {
                /* Move local head index */
                locHead = (BLE_HAL_Uart_rxBufferHead + 1u);

                /* Adjust local head index */
                if (BLE_HAL_Uart_INTERNAL_RX_BUFFER_SIZE == locHead)
                {
                    locHead = 0u;
                }

                if (locHead == BLE_HAL_Uart_rxBufferTail)
                {
                    #if (BLE_HAL_Uart_CHECK_UART_RTS_CONTROL_FLOW)
                    {
                        /* There is no space in the software buffer - disable the
                        * RX Not Empty interrupt source. The data elements are
                        * still being received into the RX FIFO until the RTS signal
                        * stops the transmitter. After the data element is read from the
                        * buffer, the RX Not Empty interrupt source is enabled to
                        * move the next data element in the software buffer.
                        */
                        BLE_HAL_Uart_INTR_RX_MASK_REG &= ~BLE_HAL_Uart_INTR_RX_NOT_EMPTY;
                        break;
                    }
                    #else
                    {
                        /* Overflow: through away received data element */
                        (void) BLE_HAL_Uart_RX_FIFO_RD_REG;
                        BLE_HAL_Uart_rxBufferOverflow = (uint8) BLE_HAL_Uart_INTR_RX_OVERFLOW;
                    }
                    #endif
                }
                else
                {
                    /* Store received data */
                    BLE_HAL_Uart_PutWordInRxBuffer(locHead, BLE_HAL_Uart_RX_FIFO_RD_REG);

                    /* Move head index */
                    BLE_HAL_Uart_rxBufferHead = locHead;
                }
            }
            while(0u != BLE_HAL_Uart_GET_RX_FIFO_ENTRIES);

            BLE_HAL_Uart_ClearRxInterruptSource(BLE_HAL_Uart_INTR_RX_NOT_EMPTY);
        }
    }
    #endif


    #if (BLE_HAL_Uart_CHECK_TX_SW_BUFFER)
    {
        if (BLE_HAL_Uart_CHECK_INTR_TX_MASKED(BLE_HAL_Uart_INTR_TX_NOT_FULL))
        {
            do
            {
                /* Check for room in TX software buffer */
                if (BLE_HAL_Uart_txBufferHead != BLE_HAL_Uart_txBufferTail)
                {
                    /* Move local tail index */
                    locTail = (BLE_HAL_Uart_txBufferTail + 1u);

                    /* Adjust local tail index */
                    if (BLE_HAL_Uart_TX_BUFFER_SIZE == locTail)
                    {
                        locTail = 0u;
                    }

                    /* Put data into TX FIFO */
                    BLE_HAL_Uart_TX_FIFO_WR_REG = BLE_HAL_Uart_GetWordFromTxBuffer(locTail);

                    /* Move tail index */
                    BLE_HAL_Uart_txBufferTail = locTail;
                }
                else
                {
                    /* TX software buffer is empty: complete transfer */
                    BLE_HAL_Uart_DISABLE_INTR_TX(BLE_HAL_Uart_INTR_TX_NOT_FULL);
                    break;
                }
            }
            while (BLE_HAL_Uart_SPI_UART_FIFO_SIZE != BLE_HAL_Uart_GET_TX_FIFO_ENTRIES);

            BLE_HAL_Uart_ClearTxInterruptSource(BLE_HAL_Uart_INTR_TX_NOT_FULL);
        }
    }
    #endif
    
#ifdef BLE_HAL_Uart_SPI_UART_ISR_EXIT_CALLBACK
    BLE_HAL_Uart_SPI_UART_ISR_ExitCallback();
#endif /* BLE_HAL_Uart_SPI_UART_ISR_EXIT_CALLBACK */
    
}

#endif /* (BLE_HAL_Uart_SCB_IRQ_INTERNAL) */


/* [] END OF FILE */
