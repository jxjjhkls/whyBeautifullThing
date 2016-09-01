/*******************************************************************************
* File Name: BLE_HAL_Uart.c
* Version 3.10
*
* Description:
*  This file provides the source code to the API for the SCB Component.
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

#if (BLE_HAL_Uart_SCB_MODE_I2C_INC)
    #include "BLE_HAL_Uart_I2C_PVT.h"
#endif /* (BLE_HAL_Uart_SCB_MODE_I2C_INC) */

#if (BLE_HAL_Uart_SCB_MODE_EZI2C_INC)
    #include "BLE_HAL_Uart_EZI2C_PVT.h"
#endif /* (BLE_HAL_Uart_SCB_MODE_EZI2C_INC) */

#if (BLE_HAL_Uart_SCB_MODE_SPI_INC || BLE_HAL_Uart_SCB_MODE_UART_INC)
    #include "BLE_HAL_Uart_SPI_UART_PVT.h"
#endif /* (BLE_HAL_Uart_SCB_MODE_SPI_INC || BLE_HAL_Uart_SCB_MODE_UART_INC) */


/***************************************
*    Run Time Configuration Vars
***************************************/

/* Stores internal component configuration for Unconfigured mode */
#if (BLE_HAL_Uart_SCB_MODE_UNCONFIG_CONST_CFG)
    /* Common configuration variables */
    uint8 BLE_HAL_Uart_scbMode = BLE_HAL_Uart_SCB_MODE_UNCONFIG;
    uint8 BLE_HAL_Uart_scbEnableWake;
    uint8 BLE_HAL_Uart_scbEnableIntr;

    /* I2C configuration variables */
    uint8 BLE_HAL_Uart_mode;
    uint8 BLE_HAL_Uart_acceptAddr;

    /* SPI/UART configuration variables */
    volatile uint8 * BLE_HAL_Uart_rxBuffer;
    uint8  BLE_HAL_Uart_rxDataBits;
    uint32 BLE_HAL_Uart_rxBufferSize;

    volatile uint8 * BLE_HAL_Uart_txBuffer;
    uint8  BLE_HAL_Uart_txDataBits;
    uint32 BLE_HAL_Uart_txBufferSize;

    /* EZI2C configuration variables */
    uint8 BLE_HAL_Uart_numberOfAddr;
    uint8 BLE_HAL_Uart_subAddrSize;
#endif /* (BLE_HAL_Uart_SCB_MODE_UNCONFIG_CONST_CFG) */


/***************************************
*     Common SCB Vars
***************************************/

uint8 BLE_HAL_Uart_initVar = 0u;

#if (BLE_HAL_Uart_SCB_IRQ_INTERNAL)
#if !defined (CY_REMOVE_BLE_HAL_Uart_CUSTOM_INTR_HANDLER)
    void (*BLE_HAL_Uart_customIntrHandler)(void) = NULL;
#endif /* !defined (CY_REMOVE_BLE_HAL_Uart_CUSTOM_INTR_HANDLER) */
#endif /* (BLE_HAL_Uart_SCB_IRQ_INTERNAL) */


/***************************************
*    Private Function Prototypes
***************************************/

static void BLE_HAL_Uart_ScbEnableIntr(void);
static void BLE_HAL_Uart_ScbModeStop(void);
static void BLE_HAL_Uart_ScbModePostEnable(void);


/*******************************************************************************
* Function Name: BLE_HAL_Uart_Init
********************************************************************************
*
* Summary:
*  Initializes the SCB component to operate in one of the selected
*  configurations: I2C, SPI, UART or EZI2C.
*  When the configuration is set to "Unconfigured SCB", this function does
*  not do any initialization. Use mode-specific initialization APIs instead:
*  SCB_I2CInit, SCB_SpiInit, SCB_UartInit or SCB_EzI2CInit.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void BLE_HAL_Uart_Init(void)
{
#if (BLE_HAL_Uart_SCB_MODE_UNCONFIG_CONST_CFG)
    if (BLE_HAL_Uart_SCB_MODE_UNCONFIG_RUNTM_CFG)
    {
        BLE_HAL_Uart_initVar = 0u;
    }
    else
    {
        /* Initialization was done before this function call */
    }

#elif (BLE_HAL_Uart_SCB_MODE_I2C_CONST_CFG)
    BLE_HAL_Uart_I2CInit();

#elif (BLE_HAL_Uart_SCB_MODE_SPI_CONST_CFG)
    BLE_HAL_Uart_SpiInit();

#elif (BLE_HAL_Uart_SCB_MODE_UART_CONST_CFG)
    BLE_HAL_Uart_UartInit();

#elif (BLE_HAL_Uart_SCB_MODE_EZI2C_CONST_CFG)
    BLE_HAL_Uart_EzI2CInit();

#endif /* (BLE_HAL_Uart_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/*******************************************************************************
* Function Name: BLE_HAL_Uart_Enable
********************************************************************************
*
* Summary:
*  Enables the SCB component operation.
*  The SCB configuration should be not changed when the component is enabled.
*  Any configuration changes should be made after disabling the component.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void BLE_HAL_Uart_Enable(void)
{
#if (BLE_HAL_Uart_SCB_MODE_UNCONFIG_CONST_CFG)
    /* Enable SCB block, only if it is already configured */
    if (!BLE_HAL_Uart_SCB_MODE_UNCONFIG_RUNTM_CFG)
    {
        BLE_HAL_Uart_CTRL_REG |= BLE_HAL_Uart_CTRL_ENABLED;

        BLE_HAL_Uart_ScbEnableIntr();

        /* Call PostEnable function specific to current operation mode */
        BLE_HAL_Uart_ScbModePostEnable();
    }
#else
    BLE_HAL_Uart_CTRL_REG |= BLE_HAL_Uart_CTRL_ENABLED;

    BLE_HAL_Uart_ScbEnableIntr();

    /* Call PostEnable function specific to current operation mode */
    BLE_HAL_Uart_ScbModePostEnable();
#endif /* (BLE_HAL_Uart_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/*******************************************************************************
* Function Name: BLE_HAL_Uart_Start
********************************************************************************
*
* Summary:
*  Invokes SCB_Init() and SCB_Enable().
*  After this function call, the component is enabled and ready for operation.
*  When configuration is set to "Unconfigured SCB", the component must first be
*  initialized to operate in one of the following configurations: I2C, SPI, UART
*  or EZ I2C. Otherwise this function does not enable the component.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  BLE_HAL_Uart_initVar - used to check initial configuration, modified
*  on first function call.
*
*******************************************************************************/
void BLE_HAL_Uart_Start(void)
{
    if (0u == BLE_HAL_Uart_initVar)
    {
        BLE_HAL_Uart_Init();
        BLE_HAL_Uart_initVar = 1u; /* Component was initialized */
    }

    BLE_HAL_Uart_Enable();
}


/*******************************************************************************
* Function Name: BLE_HAL_Uart_Stop
********************************************************************************
*
* Summary:
*  Disables the SCB component and its interrupt.
*  It also disables all TX interrupt sources so as not to cause an unexpected
*  interrupt trigger because after the component is enabled, the TX FIFO 
*  is empty.
*
* Parameters:
*  None
*
* Return:
*  None
* 
*******************************************************************************/
void BLE_HAL_Uart_Stop(void)
{
#if (BLE_HAL_Uart_SCB_IRQ_INTERNAL)
    BLE_HAL_Uart_DisableInt();
#endif /* (BLE_HAL_Uart_SCB_IRQ_INTERNAL) */

    /* Call Stop function specific to current operation mode */
    BLE_HAL_Uart_ScbModeStop();

    /* Disable SCB IP */
    BLE_HAL_Uart_CTRL_REG &= (uint32) ~BLE_HAL_Uart_CTRL_ENABLED;

    /* Disable all TX interrupt sources so as not to cause an unexpected
    * interrupt trigger because after the component is enabled, the TX FIFO
    * is empty.
    * For SCB IP v0, it is critical as it does not mask-out interrupt
    * sources when they are disabled. This can cause a code lock-up in the
    * interrupt handler because TX FIFO cannot be loaded after the block
    * is disabled.
    */
    BLE_HAL_Uart_SetTxInterruptMode(BLE_HAL_Uart_NO_INTR_SOURCES);

#if (BLE_HAL_Uart_SCB_IRQ_INTERNAL)
    BLE_HAL_Uart_ClearPendingInt();
#endif /* (BLE_HAL_Uart_SCB_IRQ_INTERNAL) */
}


/*******************************************************************************
* Function Name: BLE_HAL_Uart_SetRxFifoLevel
********************************************************************************
*
* Summary:
*  Sets level in the RX FIFO to generate a RX level interrupt.
*  When the RX FIFO has more entries than the RX FIFO level an RX level
*  interrupt request is generated.
*
* Parameters:
*  level: Level in the RX FIFO to generate RX level interrupt.
*         The range of valid level values is between 0 and RX FIFO depth - 1.
*
* Return:
*  None
*
*******************************************************************************/
void BLE_HAL_Uart_SetRxFifoLevel(uint32 level)
{
    uint32 rxFifoCtrl;

    rxFifoCtrl = BLE_HAL_Uart_RX_FIFO_CTRL_REG;

    rxFifoCtrl &= ((uint32) ~BLE_HAL_Uart_RX_FIFO_CTRL_TRIGGER_LEVEL_MASK); /* Clear level mask bits */
    rxFifoCtrl |= ((uint32) (BLE_HAL_Uart_RX_FIFO_CTRL_TRIGGER_LEVEL_MASK & level));

    BLE_HAL_Uart_RX_FIFO_CTRL_REG = rxFifoCtrl;
}


/*******************************************************************************
* Function Name: BLE_HAL_Uart_SetTxFifoLevel
********************************************************************************
*
* Summary:
*  Sets level in the TX FIFO to generate a TX level interrupt.
*  When the TX FIFO has more entries than the TX FIFO level an TX level
*  interrupt request is generated.
*
* Parameters:
*  level: Level in the TX FIFO to generate TX level interrupt.
*         The range of valid level values is between 0 and TX FIFO depth - 1.
*
* Return:
*  None
*
*******************************************************************************/
void BLE_HAL_Uart_SetTxFifoLevel(uint32 level)
{
    uint32 txFifoCtrl;

    txFifoCtrl = BLE_HAL_Uart_TX_FIFO_CTRL_REG;

    txFifoCtrl &= ((uint32) ~BLE_HAL_Uart_TX_FIFO_CTRL_TRIGGER_LEVEL_MASK); /* Clear level mask bits */
    txFifoCtrl |= ((uint32) (BLE_HAL_Uart_TX_FIFO_CTRL_TRIGGER_LEVEL_MASK & level));

    BLE_HAL_Uart_TX_FIFO_CTRL_REG = txFifoCtrl;
}


#if (BLE_HAL_Uart_SCB_IRQ_INTERNAL)
    /*******************************************************************************
    * Function Name: BLE_HAL_Uart_SetCustomInterruptHandler
    ********************************************************************************
    *
    * Summary:
    *  Registers a function to be called by the internal interrupt handler.
    *  First the function that is registered is called, then the internal interrupt
    *  handler performs any operation such as software buffer management functions
    *  before the interrupt returns.  It is the user's responsibility not to break
    *  the software buffer operations. Only one custom handler is supported, which
    *  is the function provided by the most recent call.
    *  At the initialization time no custom handler is registered.
    *
    * Parameters:
    *  func: Pointer to the function to register.
    *        The value NULL indicates to remove the current custom interrupt
    *        handler.
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void BLE_HAL_Uart_SetCustomInterruptHandler(void (*func)(void))
    {
    #if !defined (CY_REMOVE_BLE_HAL_Uart_CUSTOM_INTR_HANDLER)
        BLE_HAL_Uart_customIntrHandler = func; /* Register interrupt handler */
    #else
        if (NULL != func)
        {
            /* Suppress compiler warning */
        }
    #endif /* !defined (CY_REMOVE_BLE_HAL_Uart_CUSTOM_INTR_HANDLER) */
    }
#endif /* (BLE_HAL_Uart_SCB_IRQ_INTERNAL) */


/*******************************************************************************
* Function Name: BLE_HAL_Uart_ScbModeEnableIntr
********************************************************************************
*
* Summary:
*  Enables an interrupt for a specific mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
static void BLE_HAL_Uart_ScbEnableIntr(void)
{
#if (BLE_HAL_Uart_SCB_IRQ_INTERNAL)
    /* Enable interrupt in NVIC */
    #if (BLE_HAL_Uart_SCB_MODE_UNCONFIG_CONST_CFG)
        if (0u != BLE_HAL_Uart_scbEnableIntr)
        {
            BLE_HAL_Uart_EnableInt();
        }

    #else
        BLE_HAL_Uart_EnableInt();

    #endif /* (BLE_HAL_Uart_SCB_MODE_UNCONFIG_CONST_CFG) */
#endif /* (BLE_HAL_Uart_SCB_IRQ_INTERNAL) */
}


/*******************************************************************************
* Function Name: BLE_HAL_Uart_ScbModePostEnable
********************************************************************************
*
* Summary:
*  Calls the PostEnable function for a specific operation mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
static void BLE_HAL_Uart_ScbModePostEnable(void)
{
#if (BLE_HAL_Uart_SCB_MODE_UNCONFIG_CONST_CFG)
#if (!BLE_HAL_Uart_CY_SCBIP_V1)
    if (BLE_HAL_Uart_SCB_MODE_SPI_RUNTM_CFG)
    {
        BLE_HAL_Uart_SpiPostEnable();
    }
    else if (BLE_HAL_Uart_SCB_MODE_UART_RUNTM_CFG)
    {
        BLE_HAL_Uart_UartPostEnable();
    }
    else
    {
        /* Unknown mode: do nothing */
    }
#endif /* (!BLE_HAL_Uart_CY_SCBIP_V1) */

#elif (BLE_HAL_Uart_SCB_MODE_SPI_CONST_CFG)
    BLE_HAL_Uart_SpiPostEnable();

#elif (BLE_HAL_Uart_SCB_MODE_UART_CONST_CFG)
    BLE_HAL_Uart_UartPostEnable();

#else
    /* Unknown mode: do nothing */
#endif /* (BLE_HAL_Uart_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/*******************************************************************************
* Function Name: BLE_HAL_Uart_ScbModeStop
********************************************************************************
*
* Summary:
*  Calls the Stop function for a specific operation mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
static void BLE_HAL_Uart_ScbModeStop(void)
{
#if (BLE_HAL_Uart_SCB_MODE_UNCONFIG_CONST_CFG)
    if (BLE_HAL_Uart_SCB_MODE_I2C_RUNTM_CFG)
    {
        BLE_HAL_Uart_I2CStop();
    }
    else if (BLE_HAL_Uart_SCB_MODE_EZI2C_RUNTM_CFG)
    {
        BLE_HAL_Uart_EzI2CStop();
    }
#if (!BLE_HAL_Uart_CY_SCBIP_V1)
    else if (BLE_HAL_Uart_SCB_MODE_SPI_RUNTM_CFG)
    {
        BLE_HAL_Uart_SpiStop();
    }
    else if (BLE_HAL_Uart_SCB_MODE_UART_RUNTM_CFG)
    {
        BLE_HAL_Uart_UartStop();
    }
#endif /* (!BLE_HAL_Uart_CY_SCBIP_V1) */
    else
    {
        /* Unknown mode: do nothing */
    }
#elif (BLE_HAL_Uart_SCB_MODE_I2C_CONST_CFG)
    BLE_HAL_Uart_I2CStop();

#elif (BLE_HAL_Uart_SCB_MODE_EZI2C_CONST_CFG)
    BLE_HAL_Uart_EzI2CStop();

#elif (BLE_HAL_Uart_SCB_MODE_SPI_CONST_CFG)
    BLE_HAL_Uart_SpiStop();

#elif (BLE_HAL_Uart_SCB_MODE_UART_CONST_CFG)
    BLE_HAL_Uart_UartStop();

#else
    /* Unknown mode: do nothing */
#endif /* (BLE_HAL_Uart_SCB_MODE_UNCONFIG_CONST_CFG) */
}


#if (BLE_HAL_Uart_SCB_MODE_UNCONFIG_CONST_CFG)
    /*******************************************************************************
    * Function Name: BLE_HAL_Uart_SetPins
    ********************************************************************************
    *
    * Summary:
    *  Sets the pins settings accordingly to the selected operation mode.
    *  Only available in the Unconfigured operation mode. The mode specific
    *  initialization function calls it.
    *  Pins configuration is set by PSoC Creator when a specific mode of operation
    *  is selected in design time.
    *
    * Parameters:
    *  mode:      Mode of SCB operation.
    *  subMode:   Sub-mode of SCB operation. It is only required for SPI and UART
    *             modes.
    *  uartEnableMask: enables TX or RX direction and RTS and CTS signals.
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void BLE_HAL_Uart_SetPins(uint32 mode, uint32 subMode, uint32 uartEnableMask)
    {
        uint32 hsiomSel [BLE_HAL_Uart_SCB_PINS_NUMBER];
        uint32 pinsDm   [BLE_HAL_Uart_SCB_PINS_NUMBER];

    #if (!BLE_HAL_Uart_CY_SCBIP_V1)
        uint32 pinsInBuf = 0u;
    #endif /* (!BLE_HAL_Uart_CY_SCBIP_V1) */

        uint32 i;

        /* Set default HSIOM to GPIO and Drive Mode to Analog Hi-Z */
        for (i = 0u; i < BLE_HAL_Uart_SCB_PINS_NUMBER; i++)
        {
            hsiomSel[i]  = BLE_HAL_Uart_HSIOM_DEF_SEL;
            pinsDm[i]    = BLE_HAL_Uart_PIN_DM_ALG_HIZ;
        }

        if ((BLE_HAL_Uart_SCB_MODE_I2C   == mode) ||
           (BLE_HAL_Uart_SCB_MODE_EZI2C == mode))
        {
            hsiomSel[BLE_HAL_Uart_RX_SDA_MOSI_PIN_INDEX] = BLE_HAL_Uart_HSIOM_I2C_SEL;
            hsiomSel[BLE_HAL_Uart_TX_SCL_MISO_PIN_INDEX] = BLE_HAL_Uart_HSIOM_I2C_SEL;

            pinsDm[BLE_HAL_Uart_RX_SDA_MOSI_PIN_INDEX] = BLE_HAL_Uart_PIN_DM_OD_LO;
            pinsDm[BLE_HAL_Uart_TX_SCL_MISO_PIN_INDEX] = BLE_HAL_Uart_PIN_DM_OD_LO;
        }
    #if (!BLE_HAL_Uart_CY_SCBIP_V1)
        else if (BLE_HAL_Uart_SCB_MODE_SPI == mode)
        {
            hsiomSel[BLE_HAL_Uart_RX_SDA_MOSI_PIN_INDEX] = BLE_HAL_Uart_HSIOM_SPI_SEL;
            hsiomSel[BLE_HAL_Uart_TX_SCL_MISO_PIN_INDEX] = BLE_HAL_Uart_HSIOM_SPI_SEL;
            hsiomSel[BLE_HAL_Uart_CTS_SCLK_PIN_INDEX] = BLE_HAL_Uart_HSIOM_SPI_SEL;

            if (BLE_HAL_Uart_SPI_SLAVE == subMode)
            {
                /* Slave */
                pinsDm[BLE_HAL_Uart_RX_SDA_MOSI_PIN_INDEX] = BLE_HAL_Uart_PIN_DM_DIG_HIZ;
                pinsDm[BLE_HAL_Uart_TX_SCL_MISO_PIN_INDEX] = BLE_HAL_Uart_PIN_DM_STRONG;
                pinsDm[BLE_HAL_Uart_CTS_SCLK_PIN_INDEX] = BLE_HAL_Uart_PIN_DM_DIG_HIZ;

            #if (BLE_HAL_Uart_RTS_SS0_PIN)
                /* Only SS0 is valid choice for Slave */
                hsiomSel[BLE_HAL_Uart_RTS_SS0_PIN_INDEX] = BLE_HAL_Uart_HSIOM_SPI_SEL;
                pinsDm  [BLE_HAL_Uart_RTS_SS0_PIN_INDEX] = BLE_HAL_Uart_PIN_DM_DIG_HIZ;
            #endif /* (BLE_HAL_Uart_RTS_SS0_PIN) */

            #if (BLE_HAL_Uart_TX_SCL_MISO_PIN)
                /* Disable input buffer */
                 pinsInBuf |= BLE_HAL_Uart_TX_SCL_MISO_PIN_MASK;
            #endif /* (BLE_HAL_Uart_TX_SCL_MISO_PIN) */
            }
            else /* (Master) */
            {
                pinsDm[BLE_HAL_Uart_RX_SDA_MOSI_PIN_INDEX] = BLE_HAL_Uart_PIN_DM_STRONG;
                pinsDm[BLE_HAL_Uart_TX_SCL_MISO_PIN_INDEX] = BLE_HAL_Uart_PIN_DM_DIG_HIZ;
                pinsDm[BLE_HAL_Uart_CTS_SCLK_PIN_INDEX] = BLE_HAL_Uart_PIN_DM_STRONG;

            #if (BLE_HAL_Uart_RTS_SS0_PIN)
                hsiomSel [BLE_HAL_Uart_RTS_SS0_PIN_INDEX] = BLE_HAL_Uart_HSIOM_SPI_SEL;
                pinsDm   [BLE_HAL_Uart_RTS_SS0_PIN_INDEX] = BLE_HAL_Uart_PIN_DM_STRONG;
                pinsInBuf |= BLE_HAL_Uart_RTS_SS0_PIN_MASK;
            #endif /* (BLE_HAL_Uart_RTS_SS0_PIN) */

            #if (BLE_HAL_Uart_SS1_PIN)
                hsiomSel [BLE_HAL_Uart_SS1_PIN_INDEX] = BLE_HAL_Uart_HSIOM_SPI_SEL;
                pinsDm   [BLE_HAL_Uart_SS1_PIN_INDEX] = BLE_HAL_Uart_PIN_DM_STRONG;
                pinsInBuf |= BLE_HAL_Uart_SS1_PIN_MASK;
            #endif /* (BLE_HAL_Uart_SS1_PIN) */

            #if (BLE_HAL_Uart_SS2_PIN)
                hsiomSel [BLE_HAL_Uart_SS2_PIN_INDEX] = BLE_HAL_Uart_HSIOM_SPI_SEL;
                pinsDm   [BLE_HAL_Uart_SS2_PIN_INDEX] = BLE_HAL_Uart_PIN_DM_STRONG;
                pinsInBuf |= BLE_HAL_Uart_SS2_PIN_MASK;
            #endif /* (BLE_HAL_Uart_SS2_PIN) */

            #if (BLE_HAL_Uart_SS3_PIN)
                hsiomSel [BLE_HAL_Uart_SS3_PIN_INDEX] = BLE_HAL_Uart_HSIOM_SPI_SEL;
                pinsDm   [BLE_HAL_Uart_SS3_PIN_INDEX] = BLE_HAL_Uart_PIN_DM_STRONG;
                pinsInBuf |= BLE_HAL_Uart_SS3_PIN_MASK;
            #endif /* (BLE_HAL_Uart_SS3_PIN) */

                /* Disable input buffers */
            #if (BLE_HAL_Uart_RX_SDA_MOSI_PIN)
                pinsInBuf |= BLE_HAL_Uart_RX_SDA_MOSI_PIN_MASK;
            #endif /* (BLE_HAL_Uart_RX_SDA_MOSI_PIN) */

             #if (BLE_HAL_Uart_RX_WAKE_SDA_MOSI_PIN)
                pinsInBuf |= BLE_HAL_Uart_RX_WAKE_SDA_MOSI_PIN_MASK;
            #endif /* (BLE_HAL_Uart_RX_WAKE_SDA_MOSI_PIN) */

            #if (BLE_HAL_Uart_CTS_SCLK_PIN)
                pinsInBuf |= BLE_HAL_Uart_CTS_SCLK_PIN_MASK;
            #endif /* (BLE_HAL_Uart_CTS_SCLK_PIN) */
            }
        }
        else /* UART */
        {
            if (BLE_HAL_Uart_UART_MODE_SMARTCARD == subMode)
            {
                /* SmartCard */
                hsiomSel[BLE_HAL_Uart_TX_SCL_MISO_PIN_INDEX] = BLE_HAL_Uart_HSIOM_UART_SEL;
                pinsDm  [BLE_HAL_Uart_TX_SCL_MISO_PIN_INDEX] = BLE_HAL_Uart_PIN_DM_OD_LO;
            }
            else /* Standard or IrDA */
            {
                if (0u != (BLE_HAL_Uart_UART_RX_PIN_ENABLE & uartEnableMask))
                {
                    hsiomSel[BLE_HAL_Uart_RX_SDA_MOSI_PIN_INDEX] = BLE_HAL_Uart_HSIOM_UART_SEL;
                    pinsDm  [BLE_HAL_Uart_RX_SDA_MOSI_PIN_INDEX] = BLE_HAL_Uart_PIN_DM_DIG_HIZ;
                }

                if (0u != (BLE_HAL_Uart_UART_TX_PIN_ENABLE & uartEnableMask))
                {
                    hsiomSel[BLE_HAL_Uart_TX_SCL_MISO_PIN_INDEX] = BLE_HAL_Uart_HSIOM_UART_SEL;
                    pinsDm  [BLE_HAL_Uart_TX_SCL_MISO_PIN_INDEX] = BLE_HAL_Uart_PIN_DM_STRONG;

                #if (BLE_HAL_Uart_TX_SCL_MISO_PIN)
                     pinsInBuf |= BLE_HAL_Uart_TX_SCL_MISO_PIN_MASK;
                #endif /* (BLE_HAL_Uart_TX_SCL_MISO_PIN) */
                }

            #if !(BLE_HAL_Uart_CY_SCBIP_V0 || BLE_HAL_Uart_CY_SCBIP_V1)
                if (BLE_HAL_Uart_UART_MODE_STD == subMode)
                {
                    if (0u != (BLE_HAL_Uart_UART_CTS_PIN_ENABLE & uartEnableMask))
                    {
                        /* CTS input is multiplexed with SCLK */
                        hsiomSel[BLE_HAL_Uart_CTS_SCLK_PIN_INDEX] = BLE_HAL_Uart_HSIOM_UART_SEL;
                        pinsDm  [BLE_HAL_Uart_CTS_SCLK_PIN_INDEX] = BLE_HAL_Uart_PIN_DM_DIG_HIZ;
                    }

                    if (0u != (BLE_HAL_Uart_UART_RTS_PIN_ENABLE & uartEnableMask))
                    {
                        /* RTS output is multiplexed with SS0 */
                        hsiomSel[BLE_HAL_Uart_RTS_SS0_PIN_INDEX] = BLE_HAL_Uart_HSIOM_UART_SEL;
                        pinsDm  [BLE_HAL_Uart_RTS_SS0_PIN_INDEX] = BLE_HAL_Uart_PIN_DM_STRONG;

                    #if (BLE_HAL_Uart_RTS_SS0_PIN)
                        /* Disable input buffer */
                        pinsInBuf |= BLE_HAL_Uart_RTS_SS0_PIN_MASK;
                    #endif /* (BLE_HAL_Uart_RTS_SS0_PIN) */
                    }
                }
            #endif /* !(BLE_HAL_Uart_CY_SCBIP_V0 || BLE_HAL_Uart_CY_SCBIP_V1) */
            }
        }
    #endif /* (!BLE_HAL_Uart_CY_SCBIP_V1) */

    /* Configure pins: set HSIOM, DM and InputBufEnable */
    /* Note: the DR register settings do not effect the pin output if HSIOM is other than GPIO */

    #if (BLE_HAL_Uart_RX_WAKE_SDA_MOSI_PIN)
        BLE_HAL_Uart_SET_HSIOM_SEL(BLE_HAL_Uart_RX_WAKE_SDA_MOSI_HSIOM_REG,
                                       BLE_HAL_Uart_RX_WAKE_SDA_MOSI_HSIOM_MASK,
                                       BLE_HAL_Uart_RX_WAKE_SDA_MOSI_HSIOM_POS,
                                       hsiomSel[BLE_HAL_Uart_RX_WAKE_SDA_MOSI_PIN_INDEX]);

        BLE_HAL_Uart_uart_rx_wake_i2c_sda_spi_mosi_SetDriveMode((uint8)
                                                               pinsDm[BLE_HAL_Uart_RX_WAKE_SDA_MOSI_PIN_INDEX]);

        BLE_HAL_Uart_SET_INP_DIS(BLE_HAL_Uart_uart_rx_wake_i2c_sda_spi_mosi_INP_DIS,
                                     BLE_HAL_Uart_uart_rx_wake_i2c_sda_spi_mosi_MASK,
                                     (0u != (pinsInBuf & BLE_HAL_Uart_RX_WAKE_SDA_MOSI_PIN_MASK)));

         /* Set interrupt on falling edge */
        BLE_HAL_Uart_SET_INCFG_TYPE(BLE_HAL_Uart_RX_WAKE_SDA_MOSI_INTCFG_REG,
                                        BLE_HAL_Uart_RX_WAKE_SDA_MOSI_INTCFG_TYPE_MASK,
                                        BLE_HAL_Uart_RX_WAKE_SDA_MOSI_INTCFG_TYPE_POS,
                                        BLE_HAL_Uart_INTCFG_TYPE_FALLING_EDGE);
    #endif /* (BLE_HAL_Uart_RX_WAKE_SDA_MOSI_PIN) */

    #if (BLE_HAL_Uart_RX_SDA_MOSI_PIN)
        BLE_HAL_Uart_SET_HSIOM_SEL(BLE_HAL_Uart_RX_SDA_MOSI_HSIOM_REG,
                                       BLE_HAL_Uart_RX_SDA_MOSI_HSIOM_MASK,
                                       BLE_HAL_Uart_RX_SDA_MOSI_HSIOM_POS,
                                        hsiomSel[BLE_HAL_Uart_RX_SDA_MOSI_PIN_INDEX]);

        BLE_HAL_Uart_uart_rx_i2c_sda_spi_mosi_SetDriveMode((uint8) pinsDm[BLE_HAL_Uart_RX_SDA_MOSI_PIN_INDEX]);

    #if (!BLE_HAL_Uart_CY_SCBIP_V1)
        BLE_HAL_Uart_SET_INP_DIS(BLE_HAL_Uart_uart_rx_i2c_sda_spi_mosi_INP_DIS,
                                     BLE_HAL_Uart_uart_rx_i2c_sda_spi_mosi_MASK,
                                     (0u != (pinsInBuf & BLE_HAL_Uart_RX_SDA_MOSI_PIN_MASK)));
    #endif /* (!BLE_HAL_Uart_CY_SCBIP_V1) */
    #endif /* (BLE_HAL_Uart_RX_SDA_MOSI_PIN) */

    #if (BLE_HAL_Uart_TX_SCL_MISO_PIN)
        BLE_HAL_Uart_SET_HSIOM_SEL(BLE_HAL_Uart_TX_SCL_MISO_HSIOM_REG,
                                       BLE_HAL_Uart_TX_SCL_MISO_HSIOM_MASK,
                                       BLE_HAL_Uart_TX_SCL_MISO_HSIOM_POS,
                                        hsiomSel[BLE_HAL_Uart_TX_SCL_MISO_PIN_INDEX]);

        BLE_HAL_Uart_uart_tx_i2c_scl_spi_miso_SetDriveMode((uint8) pinsDm[BLE_HAL_Uart_TX_SCL_MISO_PIN_INDEX]);

    #if (!BLE_HAL_Uart_CY_SCBIP_V1)
        BLE_HAL_Uart_SET_INP_DIS(BLE_HAL_Uart_uart_tx_i2c_scl_spi_miso_INP_DIS,
                                     BLE_HAL_Uart_uart_tx_i2c_scl_spi_miso_MASK,
                                    (0u != (pinsInBuf & BLE_HAL_Uart_TX_SCL_MISO_PIN_MASK)));
    #endif /* (!BLE_HAL_Uart_CY_SCBIP_V1) */
    #endif /* (BLE_HAL_Uart_RX_SDA_MOSI_PIN) */

    #if (BLE_HAL_Uart_CTS_SCLK_PIN)
        BLE_HAL_Uart_SET_HSIOM_SEL(BLE_HAL_Uart_CTS_SCLK_HSIOM_REG,
                                       BLE_HAL_Uart_CTS_SCLK_HSIOM_MASK,
                                       BLE_HAL_Uart_CTS_SCLK_HSIOM_POS,
                                       hsiomSel[BLE_HAL_Uart_CTS_SCLK_PIN_INDEX]);

        BLE_HAL_Uart_uart_cts_spi_sclk_SetDriveMode((uint8) pinsDm[BLE_HAL_Uart_CTS_SCLK_PIN_INDEX]);

        BLE_HAL_Uart_SET_INP_DIS(BLE_HAL_Uart_uart_cts_spi_sclk_INP_DIS,
                                     BLE_HAL_Uart_uart_cts_spi_sclk_MASK,
                                     (0u != (pinsInBuf & BLE_HAL_Uart_CTS_SCLK_PIN_MASK)));
    #endif /* (BLE_HAL_Uart_CTS_SCLK_PIN) */

    #if (BLE_HAL_Uart_RTS_SS0_PIN)
        BLE_HAL_Uart_SET_HSIOM_SEL(BLE_HAL_Uart_RTS_SS0_HSIOM_REG,
                                       BLE_HAL_Uart_RTS_SS0_HSIOM_MASK,
                                       BLE_HAL_Uart_RTS_SS0_HSIOM_POS,
                                       hsiomSel[BLE_HAL_Uart_RTS_SS0_PIN_INDEX]);

        BLE_HAL_Uart_uart_rts_spi_ss0_SetDriveMode((uint8) pinsDm[BLE_HAL_Uart_RTS_SS0_PIN_INDEX]);

        BLE_HAL_Uart_SET_INP_DIS(BLE_HAL_Uart_uart_rts_spi_ss0_INP_DIS,
                                     BLE_HAL_Uart_uart_rts_spi_ss0_MASK,
                                     (0u != (pinsInBuf & BLE_HAL_Uart_RTS_SS0_PIN_MASK)));
    #endif /* (BLE_HAL_Uart_RTS_SS0_PIN) */

    #if (BLE_HAL_Uart_SS1_PIN)
        BLE_HAL_Uart_SET_HSIOM_SEL(BLE_HAL_Uart_SS1_HSIOM_REG,
                                       BLE_HAL_Uart_SS1_HSIOM_MASK,
                                       BLE_HAL_Uart_SS1_HSIOM_POS,
                                       hsiomSel[BLE_HAL_Uart_SS1_PIN_INDEX]);

        BLE_HAL_Uart_spi_ss1_SetDriveMode((uint8) pinsDm[BLE_HAL_Uart_SS1_PIN_INDEX]);

        BLE_HAL_Uart_SET_INP_DIS(BLE_HAL_Uart_spi_ss1_INP_DIS,
                                     BLE_HAL_Uart_spi_ss1_MASK,
                                     (0u != (pinsInBuf & BLE_HAL_Uart_SS1_PIN_MASK)));
    #endif /* (BLE_HAL_Uart_SS1_PIN) */

    #if (BLE_HAL_Uart_SS2_PIN)
        BLE_HAL_Uart_SET_HSIOM_SEL(BLE_HAL_Uart_SS2_HSIOM_REG,
                                       BLE_HAL_Uart_SS2_HSIOM_MASK,
                                       BLE_HAL_Uart_SS2_HSIOM_POS,
                                       hsiomSel[BLE_HAL_Uart_SS2_PIN_INDEX]);

        BLE_HAL_Uart_spi_ss2_SetDriveMode((uint8) pinsDm[BLE_HAL_Uart_SS2_PIN_INDEX]);

        BLE_HAL_Uart_SET_INP_DIS(BLE_HAL_Uart_spi_ss2_INP_DIS,
                                     BLE_HAL_Uart_spi_ss2_MASK,
                                     (0u != (pinsInBuf & BLE_HAL_Uart_SS2_PIN_MASK)));
    #endif /* (BLE_HAL_Uart_SS2_PIN) */

    #if (BLE_HAL_Uart_SS3_PIN)
        BLE_HAL_Uart_SET_HSIOM_SEL(BLE_HAL_Uart_SS3_HSIOM_REG,
                                       BLE_HAL_Uart_SS3_HSIOM_MASK,
                                       BLE_HAL_Uart_SS3_HSIOM_POS,
                                       hsiomSel[BLE_HAL_Uart_SS3_PIN_INDEX]);

        BLE_HAL_Uart_spi_ss3_SetDriveMode((uint8) pinsDm[BLE_HAL_Uart_SS3_PIN_INDEX]);

        BLE_HAL_Uart_SET_INP_DIS(BLE_HAL_Uart_spi_ss3_INP_DIS,
                                     BLE_HAL_Uart_spi_ss3_MASK,
                                     (0u != (pinsInBuf & BLE_HAL_Uart_SS3_PIN_MASK)));
    #endif /* (BLE_HAL_Uart_SS3_PIN) */
    }

#endif /* (BLE_HAL_Uart_SCB_MODE_UNCONFIG_CONST_CFG) */


#if (BLE_HAL_Uart_CY_SCBIP_V0 || BLE_HAL_Uart_CY_SCBIP_V1)
    /*******************************************************************************
    * Function Name: BLE_HAL_Uart_I2CSlaveNackGeneration
    ********************************************************************************
    *
    * Summary:
    *  Sets command to generate NACK to the address or data.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void BLE_HAL_Uart_I2CSlaveNackGeneration(void)
    {
        /* Check for EC_AM toggle condition: EC_AM and clock stretching for address are enabled */
        if ((0u != (BLE_HAL_Uart_CTRL_REG & BLE_HAL_Uart_CTRL_EC_AM_MODE)) &&
            (0u == (BLE_HAL_Uart_I2C_CTRL_REG & BLE_HAL_Uart_I2C_CTRL_S_NOT_READY_ADDR_NACK)))
        {
            /* Toggle EC_AM before NACK generation */
            BLE_HAL_Uart_CTRL_REG &= ~BLE_HAL_Uart_CTRL_EC_AM_MODE;
            BLE_HAL_Uart_CTRL_REG |=  BLE_HAL_Uart_CTRL_EC_AM_MODE;
        }

        BLE_HAL_Uart_I2C_SLAVE_CMD_REG = BLE_HAL_Uart_I2C_SLAVE_CMD_S_NACK;
    }
#endif /* (BLE_HAL_Uart_CY_SCBIP_V0 || BLE_HAL_Uart_CY_SCBIP_V1) */


/* [] END OF FILE */
