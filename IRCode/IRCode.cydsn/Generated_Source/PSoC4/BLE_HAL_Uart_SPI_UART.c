/*******************************************************************************
* File Name: BLE_HAL_Uart_SPI_UART.c
* Version 3.10
*
* Description:
*  This file provides the source code to the API for the SCB Component in
*  SPI and UART modes.
*
* Note:
*
*******************************************************************************
* Copyright 2013-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "BLE_HAL_Uart_PVT.h"
#include "BLE_HAL_Uart_SPI_UART_PVT.h"

/***************************************
*        SPI/UART Private Vars
***************************************/

#if(BLE_HAL_Uart_INTERNAL_RX_SW_BUFFER_CONST)
    volatile uint32 BLE_HAL_Uart_rxBufferHead;
    volatile uint32 BLE_HAL_Uart_rxBufferTail;
    volatile uint8  BLE_HAL_Uart_rxBufferOverflow;
#endif /* (BLE_HAL_Uart_INTERNAL_RX_SW_BUFFER_CONST) */

#if(BLE_HAL_Uart_INTERNAL_TX_SW_BUFFER_CONST)
    volatile uint32 BLE_HAL_Uart_txBufferHead;
    volatile uint32 BLE_HAL_Uart_txBufferTail;
#endif /* (BLE_HAL_Uart_INTERNAL_TX_SW_BUFFER_CONST) */

#if(BLE_HAL_Uart_INTERNAL_RX_SW_BUFFER)
    /* Add one element to the buffer to receive full packet. One byte in receive buffer is always empty */
    volatile uint8 BLE_HAL_Uart_rxBufferInternal[BLE_HAL_Uart_INTERNAL_RX_BUFFER_SIZE];
#endif /* (BLE_HAL_Uart_INTERNAL_RX_SW_BUFFER) */

#if(BLE_HAL_Uart_INTERNAL_TX_SW_BUFFER)
    volatile uint8 BLE_HAL_Uart_txBufferInternal[BLE_HAL_Uart_TX_BUFFER_SIZE];
#endif /* (BLE_HAL_Uart_INTERNAL_TX_SW_BUFFER) */


#if(BLE_HAL_Uart_RX_DIRECTION)
    /*******************************************************************************
    * Function Name: BLE_HAL_Uart_SpiUartReadRxData
    ********************************************************************************
    *
    * Summary:
    *  Retrieves the next data element from the receive buffer.
    *   - RX software buffer is disabled: Returns data element retrieved from
    *     RX FIFO. Undefined data will be returned if the RX FIFO is empty.
    *   - RX software buffer is enabled: Returns data element from the software
    *     receive buffer. Zero value is returned if the software receive buffer
    *     is empty.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  Next data element from the receive buffer.
    *
    * Global Variables:
    *  Look into BLE_HAL_Uart_SpiInit for description.
    *
    *******************************************************************************/
    uint32 BLE_HAL_Uart_SpiUartReadRxData(void)
    {
        uint32 rxData = 0u;

    #if (BLE_HAL_Uart_INTERNAL_RX_SW_BUFFER_CONST)
        uint32 locTail;
    #endif /* (BLE_HAL_Uart_INTERNAL_RX_SW_BUFFER_CONST) */

        #if (BLE_HAL_Uart_CHECK_RX_SW_BUFFER)
        {
            if (BLE_HAL_Uart_rxBufferHead != BLE_HAL_Uart_rxBufferTail)
            {
                /* There is data in RX software buffer */

                /* Calculate index to read from */
                locTail = (BLE_HAL_Uart_rxBufferTail + 1u);

                if (BLE_HAL_Uart_INTERNAL_RX_BUFFER_SIZE == locTail)
                {
                    locTail = 0u;
                }

                /* Get data from RX software buffer */
                rxData = BLE_HAL_Uart_GetWordFromRxBuffer(locTail);

                /* Change index in the buffer */
                BLE_HAL_Uart_rxBufferTail = locTail;

                #if (BLE_HAL_Uart_CHECK_UART_RTS_CONTROL_FLOW)
                {
                    /* Check if RX Not Empty is disabled in the interrupt */
                    if (0u == (BLE_HAL_Uart_INTR_RX_MASK_REG & BLE_HAL_Uart_INTR_RX_NOT_EMPTY))
                    {
                        /* Enable RX Not Empty interrupt source to continue
                        * receiving data into software buffer.
                        */
                        BLE_HAL_Uart_INTR_RX_MASK_REG |= BLE_HAL_Uart_INTR_RX_NOT_EMPTY;
                    }
                }
                #endif

            }
        }
        #else
        {
            /* Read data from RX FIFO */
            rxData = BLE_HAL_Uart_RX_FIFO_RD_REG;
        }
        #endif

        return (rxData);
    }


    /*******************************************************************************
    * Function Name: BLE_HAL_Uart_SpiUartGetRxBufferSize
    ********************************************************************************
    *
    * Summary:
    *  Returns the number of received data elements in the receive buffer.
    *   - RX software buffer disabled: returns the number of used entries in
    *     RX FIFO.
    *   - RX software buffer enabled: returns the number of elements which were
    *     placed in the receive buffer. This does not include the hardware RX FIFO.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  Number of received data elements
    *
    *******************************************************************************/
    uint32 BLE_HAL_Uart_SpiUartGetRxBufferSize(void)
    {
        uint32 size;
    #if (BLE_HAL_Uart_INTERNAL_RX_SW_BUFFER_CONST)
        uint32 locHead;
    #endif /* (BLE_HAL_Uart_INTERNAL_RX_SW_BUFFER_CONST) */

        #if (BLE_HAL_Uart_CHECK_RX_SW_BUFFER)
        {
            locHead = BLE_HAL_Uart_rxBufferHead;

            if(locHead >= BLE_HAL_Uart_rxBufferTail)
            {
                size = (locHead - BLE_HAL_Uart_rxBufferTail);
            }
            else
            {
                size = (locHead + (BLE_HAL_Uart_INTERNAL_RX_BUFFER_SIZE - BLE_HAL_Uart_rxBufferTail));
            }
        }
        #else
        {
            size = BLE_HAL_Uart_GET_RX_FIFO_ENTRIES;
        }
        #endif

        return (size);
    }


    /*******************************************************************************
    * Function Name: BLE_HAL_Uart_SpiUartClearRxBuffer
    ********************************************************************************
    *
    * Summary:
    *  Clears the receive buffer and RX FIFO.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void BLE_HAL_Uart_SpiUartClearRxBuffer(void)
    {
        #if (BLE_HAL_Uart_CHECK_RX_SW_BUFFER)
        {
            /* Lock from component interruption */
            BLE_HAL_Uart_DisableInt();

            /* Flush RX software buffer */
            BLE_HAL_Uart_rxBufferHead = BLE_HAL_Uart_rxBufferTail;
            BLE_HAL_Uart_rxBufferOverflow = 0u;

            BLE_HAL_Uart_CLEAR_RX_FIFO;
            BLE_HAL_Uart_ClearRxInterruptSource(BLE_HAL_Uart_INTR_RX_ALL);

            #if (BLE_HAL_Uart_CHECK_UART_RTS_CONTROL_FLOW)
            {
                /* Enable RX Not Empty interrupt source to continue receiving
                * data into software buffer.
                */
                BLE_HAL_Uart_INTR_RX_MASK_REG |= BLE_HAL_Uart_INTR_RX_NOT_EMPTY;
            }
            #endif

            /* Release lock */
            BLE_HAL_Uart_EnableInt();
        }
        #else
        {
            BLE_HAL_Uart_CLEAR_RX_FIFO;
        }
        #endif
    }

#endif /* (BLE_HAL_Uart_RX_DIRECTION) */


#if(BLE_HAL_Uart_TX_DIRECTION)
    /*******************************************************************************
    * Function Name: BLE_HAL_Uart_SpiUartWriteTxData
    ********************************************************************************
    *
    * Summary:
    *  Places a data entry into the transmit buffer to be sent at the next available
    *  bus time.
    *  This function is blocking and waits until there is space available to put the
    *  requested data in the transmit buffer.
    *
    * Parameters:
    *  txDataByte: the data to be transmitted.
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void BLE_HAL_Uart_SpiUartWriteTxData(uint32 txData)
    {
    #if (BLE_HAL_Uart_INTERNAL_TX_SW_BUFFER_CONST)
        uint32 locHead;
    #endif /* (BLE_HAL_Uart_INTERNAL_TX_SW_BUFFER_CONST) */

        #if (BLE_HAL_Uart_CHECK_TX_SW_BUFFER)
        {
            /* Put data directly into the TX FIFO */
            if ((BLE_HAL_Uart_txBufferHead == BLE_HAL_Uart_txBufferTail) &&
                (BLE_HAL_Uart_SPI_UART_FIFO_SIZE != BLE_HAL_Uart_GET_TX_FIFO_ENTRIES))
            {
                /* TX software buffer is empty: put data directly in TX FIFO */
                BLE_HAL_Uart_TX_FIFO_WR_REG = txData;
            }
            /* Put data into TX software buffer */
            else
            {
                /* Head index to put data */
                locHead = (BLE_HAL_Uart_txBufferHead + 1u);

                /* Adjust TX software buffer index */
                if (BLE_HAL_Uart_TX_BUFFER_SIZE == locHead)
                {
                    locHead = 0u;
                }

                /* Wait for space in TX software buffer */
                while (locHead == BLE_HAL_Uart_txBufferTail)
                {
                }

                /* TX software buffer has at least one room */

                /* Clear old status of INTR_TX_NOT_FULL. It sets at the end of transfer when TX FIFO is empty. */
                BLE_HAL_Uart_ClearTxInterruptSource(BLE_HAL_Uart_INTR_TX_NOT_FULL);

                BLE_HAL_Uart_PutWordInTxBuffer(locHead, txData);

                BLE_HAL_Uart_txBufferHead = locHead;

                /* Check if TX Not Full is disabled in interrupt */
                if (0u == (BLE_HAL_Uart_INTR_TX_MASK_REG & BLE_HAL_Uart_INTR_TX_NOT_FULL))
                {
                    /* Enable TX Not Full interrupt source to transmit from software buffer */
                    BLE_HAL_Uart_INTR_TX_MASK_REG |= (uint32) BLE_HAL_Uart_INTR_TX_NOT_FULL;
                }
            }
        }
        #else
        {
            /* Wait until TX FIFO has space to put data element */
            while (BLE_HAL_Uart_SPI_UART_FIFO_SIZE == BLE_HAL_Uart_GET_TX_FIFO_ENTRIES)
            {
            }

            BLE_HAL_Uart_TX_FIFO_WR_REG = txData;
        }
        #endif
    }


    /*******************************************************************************
    * Function Name: BLE_HAL_Uart_SpiUartPutArray
    ********************************************************************************
    *
    * Summary:
    *  Places an array of data into the transmit buffer to be sent.
    *  This function is blocking and waits until there is a space available to put
    *  all the requested data in the transmit buffer. The array size can be greater
    *  than transmit buffer size.
    *
    * Parameters:
    *  wrBuf:  pointer to an array with data to be placed in transmit buffer.
    *  count:  number of data elements to be placed in the transmit buffer.
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void BLE_HAL_Uart_SpiUartPutArray(const uint8 wrBuf[], uint32 count)
    {
        uint32 i;

        for (i=0u; i < count; i++)
        {
            BLE_HAL_Uart_SpiUartWriteTxData((uint32) wrBuf[i]);
        }
    }


    /*******************************************************************************
    * Function Name: BLE_HAL_Uart_SpiUartGetTxBufferSize
    ********************************************************************************
    *
    * Summary:
    * Returns the number of elements currently in the transmit buffer.
    *  - TX software buffer is disabled: returns the number of used entries in
    *    TX FIFO.
    *  - TX software buffer is enabled: returns the number of elements currently
    *    used in the transmit buffer. This number does not include used entries in
    *    the TX FIFO. The transmit buffer size is zero until the TX FIFO is
    *    not full.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  Number of data elements ready to transmit.
    *
    *******************************************************************************/
    uint32 BLE_HAL_Uart_SpiUartGetTxBufferSize(void)
    {
        uint32 size;
    #if (BLE_HAL_Uart_INTERNAL_TX_SW_BUFFER_CONST)
        uint32 locTail;
    #endif /* (BLE_HAL_Uart_INTERNAL_TX_SW_BUFFER_CONST) */

        #if (BLE_HAL_Uart_CHECK_TX_SW_BUFFER)
        {
            /* Get current Tail index */
            locTail = BLE_HAL_Uart_txBufferTail;

            if (BLE_HAL_Uart_txBufferHead >= locTail)
            {
                size = (BLE_HAL_Uart_txBufferHead - locTail);
            }
            else
            {
                size = (BLE_HAL_Uart_txBufferHead + (BLE_HAL_Uart_TX_BUFFER_SIZE - locTail));
            }
        }
        #else
        {
            size = BLE_HAL_Uart_GET_TX_FIFO_ENTRIES;
        }
        #endif

        return (size);
    }


    /*******************************************************************************
    * Function Name: BLE_HAL_Uart_SpiUartClearTxBuffer
    ********************************************************************************
    *
    * Summary:
    *  Clears the transmit buffer and TX FIFO.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void BLE_HAL_Uart_SpiUartClearTxBuffer(void)
    {
        #if (BLE_HAL_Uart_CHECK_TX_SW_BUFFER)
        {
            /* Lock from component interruption */
            BLE_HAL_Uart_DisableInt();

            /* Flush TX software buffer */
            BLE_HAL_Uart_txBufferHead = BLE_HAL_Uart_txBufferTail;

            BLE_HAL_Uart_INTR_TX_MASK_REG &= (uint32) ~BLE_HAL_Uart_INTR_TX_NOT_FULL;
            BLE_HAL_Uart_CLEAR_TX_FIFO;
            BLE_HAL_Uart_ClearTxInterruptSource(BLE_HAL_Uart_INTR_TX_ALL);

            /* Release lock */
            BLE_HAL_Uart_EnableInt();
        }
        #else
        {
            BLE_HAL_Uart_CLEAR_TX_FIFO;
        }
        #endif
    }

#endif /* (BLE_HAL_Uart_TX_DIRECTION) */


/*******************************************************************************
* Function Name: BLE_HAL_Uart_SpiUartDisableIntRx
********************************************************************************
*
* Summary:
*  Disables the RX interrupt sources.
*
* Parameters:
*  None
*
* Return:
*  Returns the RX interrupt sources enabled before the function call.
*
*******************************************************************************/
uint32 BLE_HAL_Uart_SpiUartDisableIntRx(void)
{
    uint32 intSource;

    intSource = BLE_HAL_Uart_GetRxInterruptMode();

    BLE_HAL_Uart_SetRxInterruptMode(BLE_HAL_Uart_NO_INTR_SOURCES);

    return (intSource);
}


/*******************************************************************************
* Function Name: BLE_HAL_Uart_SpiUartDisableIntTx
********************************************************************************
*
* Summary:
*  Disables TX interrupt sources.
*
* Parameters:
*  None
*
* Return:
*  Returns TX interrupt sources enabled before function call.
*
*******************************************************************************/
uint32 BLE_HAL_Uart_SpiUartDisableIntTx(void)
{
    uint32 intSourceMask;

    intSourceMask = BLE_HAL_Uart_GetTxInterruptMode();

    BLE_HAL_Uart_SetTxInterruptMode(BLE_HAL_Uart_NO_INTR_SOURCES);

    return (intSourceMask);
}


#if(BLE_HAL_Uart_SCB_MODE_UNCONFIG_CONST_CFG)
    /*******************************************************************************
    * Function Name: BLE_HAL_Uart_PutWordInRxBuffer
    ********************************************************************************
    *
    * Summary:
    *  Stores a byte/word into the RX buffer.
    *  Only available in the Unconfigured operation mode.
    *
    * Parameters:
    *  index:      index to store data byte/word in the RX buffer.
    *  rxDataByte: byte/word to store.
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void BLE_HAL_Uart_PutWordInRxBuffer(uint32 idx, uint32 rxDataByte)
    {
        /* Put data in buffer */
        if (BLE_HAL_Uart_ONE_BYTE_WIDTH == BLE_HAL_Uart_rxDataBits)
        {
            BLE_HAL_Uart_rxBuffer[idx] = ((uint8) rxDataByte);
        }
        else
        {
            BLE_HAL_Uart_rxBuffer[(uint32)(idx << 1u)]      = LO8(LO16(rxDataByte));
            BLE_HAL_Uart_rxBuffer[(uint32)(idx << 1u) + 1u] = HI8(LO16(rxDataByte));
        }
    }


    /*******************************************************************************
    * Function Name: BLE_HAL_Uart_GetWordFromRxBuffer
    ********************************************************************************
    *
    * Summary:
    *  Reads byte/word from RX buffer.
    *  Only available in the Unconfigured operation mode.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  Returns byte/word read from RX buffer.
    *
    *******************************************************************************/
    uint32 BLE_HAL_Uart_GetWordFromRxBuffer(uint32 idx)
    {
        uint32 value;

        if (BLE_HAL_Uart_ONE_BYTE_WIDTH == BLE_HAL_Uart_rxDataBits)
        {
            value = BLE_HAL_Uart_rxBuffer[idx];
        }
        else
        {
            value  = (uint32) BLE_HAL_Uart_rxBuffer[(uint32)(idx << 1u)];
            value |= (uint32) ((uint32)BLE_HAL_Uart_rxBuffer[(uint32)(idx << 1u) + 1u] << 8u);
        }

        return (value);
    }


    /*******************************************************************************
    * Function Name: BLE_HAL_Uart_PutWordInTxBuffer
    ********************************************************************************
    *
    * Summary:
    *  Stores byte/word into the TX buffer.
    *  Only available in the Unconfigured operation mode.
    *
    * Parameters:
    *  idx:        index to store data byte/word in the TX buffer.
    *  txDataByte: byte/word to store.
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void BLE_HAL_Uart_PutWordInTxBuffer(uint32 idx, uint32 txDataByte)
    {
        /* Put data in buffer */
        if (BLE_HAL_Uart_ONE_BYTE_WIDTH == BLE_HAL_Uart_txDataBits)
        {
            BLE_HAL_Uart_txBuffer[idx] = ((uint8) txDataByte);
        }
        else
        {
            BLE_HAL_Uart_txBuffer[(uint32)(idx << 1u)]      = LO8(LO16(txDataByte));
            BLE_HAL_Uart_txBuffer[(uint32)(idx << 1u) + 1u] = HI8(LO16(txDataByte));
        }
    }


    /*******************************************************************************
    * Function Name: BLE_HAL_Uart_GetWordFromTxBuffer
    ********************************************************************************
    *
    * Summary:
    *  Reads byte/word from the TX buffer.
    *  Only available in the Unconfigured operation mode.
    *
    * Parameters:
    *  idx: index to get data byte/word from the TX buffer.
    *
    * Return:
    *  Returns byte/word read from the TX buffer.
    *
    *******************************************************************************/
    uint32 BLE_HAL_Uart_GetWordFromTxBuffer(uint32 idx)
    {
        uint32 value;

        if (BLE_HAL_Uart_ONE_BYTE_WIDTH == BLE_HAL_Uart_txDataBits)
        {
            value = (uint32) BLE_HAL_Uart_txBuffer[idx];
        }
        else
        {
            value  = (uint32) BLE_HAL_Uart_txBuffer[(uint32)(idx << 1u)];
            value |= (uint32) ((uint32) BLE_HAL_Uart_txBuffer[(uint32)(idx << 1u) + 1u] << 8u);
        }

        return (value);
    }

#endif /* (BLE_HAL_Uart_SCB_MODE_UNCONFIG_CONST_CFG) */


/* [] END OF FILE */
