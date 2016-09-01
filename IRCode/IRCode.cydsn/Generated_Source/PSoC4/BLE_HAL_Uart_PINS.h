/*******************************************************************************
* File Name: BLE_HAL_Uart_PINS.h
* Version 3.10
*
* Description:
*  This file provides constants and parameter values for the pin components
*  buried into SCB Component.
*
* Note:
*
********************************************************************************
* Copyright 2013-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_SCB_PINS_BLE_HAL_Uart_H)
#define CY_SCB_PINS_BLE_HAL_Uart_H

#include "cydevice_trm.h"
#include "cyfitter.h"
#include "cytypes.h"


/***************************************
*   Conditional Compilation Parameters
****************************************/

/* Unconfigured pins */
#define BLE_HAL_Uart_REMOVE_RX_WAKE_SDA_MOSI_PIN  (1u)
#define BLE_HAL_Uart_REMOVE_RX_SDA_MOSI_PIN      (1u)
#define BLE_HAL_Uart_REMOVE_TX_SCL_MISO_PIN      (1u)
#define BLE_HAL_Uart_REMOVE_CTS_SCLK_PIN      (1u)
#define BLE_HAL_Uart_REMOVE_RTS_SS0_PIN      (1u)
#define BLE_HAL_Uart_REMOVE_SS1_PIN                 (1u)
#define BLE_HAL_Uart_REMOVE_SS2_PIN                 (1u)
#define BLE_HAL_Uart_REMOVE_SS3_PIN                 (1u)

/* Mode defined pins */
#define BLE_HAL_Uart_REMOVE_I2C_PINS                (1u)
#define BLE_HAL_Uart_REMOVE_SPI_MASTER_PINS         (1u)
#define BLE_HAL_Uart_REMOVE_SPI_MASTER_SCLK_PIN     (1u)
#define BLE_HAL_Uart_REMOVE_SPI_MASTER_MOSI_PIN     (1u)
#define BLE_HAL_Uart_REMOVE_SPI_MASTER_MISO_PIN     (1u)
#define BLE_HAL_Uart_REMOVE_SPI_MASTER_SS0_PIN      (1u)
#define BLE_HAL_Uart_REMOVE_SPI_MASTER_SS1_PIN      (1u)
#define BLE_HAL_Uart_REMOVE_SPI_MASTER_SS2_PIN      (1u)
#define BLE_HAL_Uart_REMOVE_SPI_MASTER_SS3_PIN      (1u)
#define BLE_HAL_Uart_REMOVE_SPI_SLAVE_PINS          (1u)
#define BLE_HAL_Uart_REMOVE_SPI_SLAVE_MOSI_PIN      (1u)
#define BLE_HAL_Uart_REMOVE_SPI_SLAVE_MISO_PIN      (1u)
#define BLE_HAL_Uart_REMOVE_UART_TX_PIN             (0u)
#define BLE_HAL_Uart_REMOVE_UART_RX_TX_PIN          (1u)
#define BLE_HAL_Uart_REMOVE_UART_RX_PIN             (0u)
#define BLE_HAL_Uart_REMOVE_UART_RX_WAKE_PIN        (1u)
#define BLE_HAL_Uart_REMOVE_UART_RTS_PIN            (0u)
#define BLE_HAL_Uart_REMOVE_UART_CTS_PIN            (0u)

/* Unconfigured pins */
#define BLE_HAL_Uart_RX_WAKE_SDA_MOSI_PIN (0u == BLE_HAL_Uart_REMOVE_RX_WAKE_SDA_MOSI_PIN)
#define BLE_HAL_Uart_RX_SDA_MOSI_PIN     (0u == BLE_HAL_Uart_REMOVE_RX_SDA_MOSI_PIN)
#define BLE_HAL_Uart_TX_SCL_MISO_PIN     (0u == BLE_HAL_Uart_REMOVE_TX_SCL_MISO_PIN)
#define BLE_HAL_Uart_CTS_SCLK_PIN     (0u == BLE_HAL_Uart_REMOVE_CTS_SCLK_PIN)
#define BLE_HAL_Uart_RTS_SS0_PIN     (0u == BLE_HAL_Uart_REMOVE_RTS_SS0_PIN)
#define BLE_HAL_Uart_SS1_PIN                (0u == BLE_HAL_Uart_REMOVE_SS1_PIN)
#define BLE_HAL_Uart_SS2_PIN                (0u == BLE_HAL_Uart_REMOVE_SS2_PIN)
#define BLE_HAL_Uart_SS3_PIN                (0u == BLE_HAL_Uart_REMOVE_SS3_PIN)

/* Mode defined pins */
#define BLE_HAL_Uart_I2C_PINS               (0u == BLE_HAL_Uart_REMOVE_I2C_PINS)
#define BLE_HAL_Uart_SPI_MASTER_PINS        (0u == BLE_HAL_Uart_REMOVE_SPI_MASTER_PINS)
#define BLE_HAL_Uart_SPI_MASTER_SCLK_PIN    (0u == BLE_HAL_Uart_REMOVE_SPI_MASTER_SCLK_PIN)
#define BLE_HAL_Uart_SPI_MASTER_MOSI_PIN    (0u == BLE_HAL_Uart_REMOVE_SPI_MASTER_MOSI_PIN)
#define BLE_HAL_Uart_SPI_MASTER_MISO_PIN    (0u == BLE_HAL_Uart_REMOVE_SPI_MASTER_MISO_PIN)
#define BLE_HAL_Uart_SPI_MASTER_SS0_PIN     (0u == BLE_HAL_Uart_REMOVE_SPI_MASTER_SS0_PIN)
#define BLE_HAL_Uart_SPI_MASTER_SS1_PIN     (0u == BLE_HAL_Uart_REMOVE_SPI_MASTER_SS1_PIN)
#define BLE_HAL_Uart_SPI_MASTER_SS2_PIN     (0u == BLE_HAL_Uart_REMOVE_SPI_MASTER_SS2_PIN)
#define BLE_HAL_Uart_SPI_MASTER_SS3_PIN     (0u == BLE_HAL_Uart_REMOVE_SPI_MASTER_SS3_PIN)
#define BLE_HAL_Uart_SPI_SLAVE_PINS         (0u == BLE_HAL_Uart_REMOVE_SPI_SLAVE_PINS)
#define BLE_HAL_Uart_SPI_SLAVE_MOSI_PIN     (0u == BLE_HAL_Uart_REMOVE_SPI_SLAVE_MOSI_PIN)
#define BLE_HAL_Uart_SPI_SLAVE_MISO_PIN     (0u == BLE_HAL_Uart_REMOVE_SPI_SLAVE_MISO_PIN)
#define BLE_HAL_Uart_UART_TX_PIN            (0u == BLE_HAL_Uart_REMOVE_UART_TX_PIN)
#define BLE_HAL_Uart_UART_RX_TX_PIN         (0u == BLE_HAL_Uart_REMOVE_UART_RX_TX_PIN)
#define BLE_HAL_Uart_UART_RX_PIN            (0u == BLE_HAL_Uart_REMOVE_UART_RX_PIN)
#define BLE_HAL_Uart_UART_RX_WAKE_PIN       (0u == BLE_HAL_Uart_REMOVE_UART_RX_WAKE_PIN)
#define BLE_HAL_Uart_UART_RTS_PIN           (0u == BLE_HAL_Uart_REMOVE_UART_RTS_PIN)
#define BLE_HAL_Uart_UART_CTS_PIN           (0u == BLE_HAL_Uart_REMOVE_UART_CTS_PIN)


/***************************************
*             Includes
****************************************/

#if (BLE_HAL_Uart_RX_WAKE_SDA_MOSI_PIN)
    #include "BLE_HAL_Uart_uart_rx_wake_i2c_sda_spi_mosi.h"
#endif /* (BLE_HAL_Uart_RX_SDA_MOSI) */

#if (BLE_HAL_Uart_RX_SDA_MOSI_PIN)
    #include "BLE_HAL_Uart_uart_rx_i2c_sda_spi_mosi.h"
#endif /* (BLE_HAL_Uart_RX_SDA_MOSI) */

#if (BLE_HAL_Uart_TX_SCL_MISO_PIN)
    #include "BLE_HAL_Uart_uart_tx_i2c_scl_spi_miso.h"
#endif /* (BLE_HAL_Uart_TX_SCL_MISO) */

#if (BLE_HAL_Uart_CTS_SCLK_PIN)
    #include "BLE_HAL_Uart_uart_cts_spi_sclk.h"
#endif /* (BLE_HAL_Uart_CTS_SCLK) */

#if (BLE_HAL_Uart_RTS_SS0_PIN)
    #include "BLE_HAL_Uart_uart_rts_spi_ss0.h"
#endif /* (BLE_HAL_Uart_RTS_SS0_PIN) */

#if (BLE_HAL_Uart_SS1_PIN)
    #include "BLE_HAL_Uart_spi_ss1.h"
#endif /* (BLE_HAL_Uart_SS1_PIN) */

#if (BLE_HAL_Uart_SS2_PIN)
    #include "BLE_HAL_Uart_spi_ss2.h"
#endif /* (BLE_HAL_Uart_SS2_PIN) */

#if (BLE_HAL_Uart_SS3_PIN)
    #include "BLE_HAL_Uart_spi_ss3.h"
#endif /* (BLE_HAL_Uart_SS3_PIN) */

#if (BLE_HAL_Uart_I2C_PINS)
    #include "BLE_HAL_Uart_scl.h"
    #include "BLE_HAL_Uart_sda.h"
#endif /* (BLE_HAL_Uart_I2C_PINS) */

#if (BLE_HAL_Uart_SPI_MASTER_PINS)
#if (BLE_HAL_Uart_SPI_MASTER_SCLK_PIN)
    #include "BLE_HAL_Uart_sclk_m.h"
#endif /* (BLE_HAL_Uart_SPI_MASTER_SCLK_PIN) */

#if (BLE_HAL_Uart_SPI_MASTER_MOSI_PIN)
    #include "BLE_HAL_Uart_mosi_m.h"
#endif /* (BLE_HAL_Uart_SPI_MASTER_MOSI_PIN) */

#if (BLE_HAL_Uart_SPI_MASTER_MISO_PIN)
    #include "BLE_HAL_Uart_miso_m.h"
#endif /*(BLE_HAL_Uart_SPI_MASTER_MISO_PIN) */
#endif /* (BLE_HAL_Uart_SPI_MASTER_PINS) */

#if (BLE_HAL_Uart_SPI_SLAVE_PINS)
    #include "BLE_HAL_Uart_sclk_s.h"
    #include "BLE_HAL_Uart_ss_s.h"

#if (BLE_HAL_Uart_SPI_SLAVE_MOSI_PIN)
    #include "BLE_HAL_Uart_mosi_s.h"
#endif /* (BLE_HAL_Uart_SPI_SLAVE_MOSI_PIN) */

#if (BLE_HAL_Uart_SPI_SLAVE_MISO_PIN)
    #include "BLE_HAL_Uart_miso_s.h"
#endif /*(BLE_HAL_Uart_SPI_SLAVE_MISO_PIN) */
#endif /* (BLE_HAL_Uart_SPI_SLAVE_PINS) */

#if (BLE_HAL_Uart_SPI_MASTER_SS0_PIN)
    #include "BLE_HAL_Uart_ss0_m.h"
#endif /* (BLE_HAL_Uart_SPI_MASTER_SS0_PIN) */

#if (BLE_HAL_Uart_SPI_MASTER_SS1_PIN)
    #include "BLE_HAL_Uart_ss1_m.h"
#endif /* (BLE_HAL_Uart_SPI_MASTER_SS1_PIN) */

#if (BLE_HAL_Uart_SPI_MASTER_SS2_PIN)
    #include "BLE_HAL_Uart_ss2_m.h"
#endif /* (BLE_HAL_Uart_SPI_MASTER_SS2_PIN) */

#if (BLE_HAL_Uart_SPI_MASTER_SS3_PIN)
    #include "BLE_HAL_Uart_ss3_m.h"
#endif /* (BLE_HAL_Uart_SPI_MASTER_SS3_PIN) */

#if (BLE_HAL_Uart_UART_TX_PIN)
    #include "BLE_HAL_Uart_tx.h"
#endif /* (BLE_HAL_Uart_UART_TX_PIN) */

#if (BLE_HAL_Uart_UART_RX_TX_PIN)
    #include "BLE_HAL_Uart_rx_tx.h"
#endif /* (BLE_HAL_Uart_UART_RX_TX_PIN) */

#if (BLE_HAL_Uart_UART_RX_PIN)
    #include "BLE_HAL_Uart_rx.h"
#endif /* (BLE_HAL_Uart_UART_RX_PIN) */

#if (BLE_HAL_Uart_UART_RX_WAKE_PIN)
    #include "BLE_HAL_Uart_rx_wake.h"
#endif /* (BLE_HAL_Uart_UART_RX_WAKE_PIN) */

#if (BLE_HAL_Uart_UART_RTS_PIN)
    #include "BLE_HAL_Uart_rts.h"
#endif /* (BLE_HAL_Uart_UART_RTS_PIN) */

#if (BLE_HAL_Uart_UART_CTS_PIN)
    #include "BLE_HAL_Uart_cts.h"
#endif /* (BLE_HAL_Uart_UART_CTS_PIN) */


/***************************************
*              Registers
***************************************/

#if (BLE_HAL_Uart_RX_WAKE_SDA_MOSI_PIN)
    #define BLE_HAL_Uart_RX_WAKE_SDA_MOSI_HSIOM_REG \
                            (*(reg32 *) BLE_HAL_Uart_uart_rx_wake_i2c_sda_spi_mosi__0__HSIOM)
    #define BLE_HAL_Uart_RX_WAKE_SDA_MOSI_HSIOM_PTR \
                            ( (reg32 *) BLE_HAL_Uart_uart_rx_wake_i2c_sda_spi_mosi__0__HSIOM)
    #define BLE_HAL_Uart_RX_WAKE_SDA_MOSI_HSIOM_MASK \
                            (BLE_HAL_Uart_uart_rx_wake_i2c_sda_spi_mosi__0__HSIOM_MASK)
    #define BLE_HAL_Uart_RX_WAKE_SDA_MOSI_HSIOM_POS \
                            (BLE_HAL_Uart_uart_rx_wake_i2c_sda_spi_mosi__0__HSIOM_SHIFT)

    #define BLE_HAL_Uart_RX_WAKE_SDA_MOSI_INTCFG_REG \
                            (*(reg32 *) BLE_HAL_Uart_uart_rx_wake_i2c_sda_spi_mosi__0__INTCFG)
    #define BLE_HAL_Uart_RX_WAKE_SDA_MOSI_INTCFG_PTR \
                            ( (reg32 *) BLE_HAL_Uart_uart_rx_wake_i2c_sda_spi_mosi__0__INTCFG)
    #define BLE_HAL_Uart_RX_WAKE_SDA_MOSI_INTCFG_TYPE_POS  (BLE_HAL_Uart_uart_rx_wake_i2c_sda_spi_mosi__SHIFT)
    #define BLE_HAL_Uart_RX_WAKE_SDA_MOSI_INTCFG_TYPE_MASK \
                            ((uint32) BLE_HAL_Uart_INTCFG_TYPE_MASK << \
                                      BLE_HAL_Uart_RX_WAKE_SDA_MOSI_INTCFG_TYPE_POS)
#endif /* (BLE_HAL_Uart_RX_WAKE_SDA_MOSI_PIN) */

#if (BLE_HAL_Uart_RX_SDA_MOSI_PIN)
    #define BLE_HAL_Uart_RX_SDA_MOSI_HSIOM_REG   (*(reg32 *) BLE_HAL_Uart_uart_rx_i2c_sda_spi_mosi__0__HSIOM)
    #define BLE_HAL_Uart_RX_SDA_MOSI_HSIOM_PTR   ( (reg32 *) BLE_HAL_Uart_uart_rx_i2c_sda_spi_mosi__0__HSIOM)
    #define BLE_HAL_Uart_RX_SDA_MOSI_HSIOM_MASK  (BLE_HAL_Uart_uart_rx_i2c_sda_spi_mosi__0__HSIOM_MASK)
    #define BLE_HAL_Uart_RX_SDA_MOSI_HSIOM_POS   (BLE_HAL_Uart_uart_rx_i2c_sda_spi_mosi__0__HSIOM_SHIFT)
#endif /* (BLE_HAL_Uart_RX_SDA_MOSI_PIN) */

#if (BLE_HAL_Uart_TX_SCL_MISO_PIN)
    #define BLE_HAL_Uart_TX_SCL_MISO_HSIOM_REG   (*(reg32 *) BLE_HAL_Uart_uart_tx_i2c_scl_spi_miso__0__HSIOM)
    #define BLE_HAL_Uart_TX_SCL_MISO_HSIOM_PTR   ( (reg32 *) BLE_HAL_Uart_uart_tx_i2c_scl_spi_miso__0__HSIOM)
    #define BLE_HAL_Uart_TX_SCL_MISO_HSIOM_MASK  (BLE_HAL_Uart_uart_tx_i2c_scl_spi_miso__0__HSIOM_MASK)
    #define BLE_HAL_Uart_TX_SCL_MISO_HSIOM_POS   (BLE_HAL_Uart_uart_tx_i2c_scl_spi_miso__0__HSIOM_SHIFT)
#endif /* (BLE_HAL_Uart_TX_SCL_MISO_PIN) */

#if (BLE_HAL_Uart_CTS_SCLK_PIN)
    #define BLE_HAL_Uart_CTS_SCLK_HSIOM_REG   (*(reg32 *) BLE_HAL_Uart_uart_cts_spi_sclk__0__HSIOM)
    #define BLE_HAL_Uart_CTS_SCLK_HSIOM_PTR   ( (reg32 *) BLE_HAL_Uart_uart_cts_spi_sclk__0__HSIOM)
    #define BLE_HAL_Uart_CTS_SCLK_HSIOM_MASK  (BLE_HAL_Uart_uart_cts_spi_sclk__0__HSIOM_MASK)
    #define BLE_HAL_Uart_CTS_SCLK_HSIOM_POS   (BLE_HAL_Uart_uart_cts_spi_sclk__0__HSIOM_SHIFT)
#endif /* (BLE_HAL_Uart_CTS_SCLK_PIN) */

#if (BLE_HAL_Uart_RTS_SS0_PIN)
    #define BLE_HAL_Uart_RTS_SS0_HSIOM_REG   (*(reg32 *) BLE_HAL_Uart_uart_rts_spi_ss0__0__HSIOM)
    #define BLE_HAL_Uart_RTS_SS0_HSIOM_PTR   ( (reg32 *) BLE_HAL_Uart_uart_rts_spi_ss0__0__HSIOM)
    #define BLE_HAL_Uart_RTS_SS0_HSIOM_MASK  (BLE_HAL_Uart_uart_rts_spi_ss0__0__HSIOM_MASK)
    #define BLE_HAL_Uart_RTS_SS0_HSIOM_POS   (BLE_HAL_Uart_uart_rts_spi_ss0__0__HSIOM_SHIFT)
#endif /* (BLE_HAL_Uart_RTS_SS0_PIN) */

#if (BLE_HAL_Uart_SS1_PIN)
    #define BLE_HAL_Uart_SS1_HSIOM_REG      (*(reg32 *) BLE_HAL_Uart_spi_ss1__0__HSIOM)
    #define BLE_HAL_Uart_SS1_HSIOM_PTR      ( (reg32 *) BLE_HAL_Uart_spi_ss1__0__HSIOM)
    #define BLE_HAL_Uart_SS1_HSIOM_MASK     (BLE_HAL_Uart_spi_ss1__0__HSIOM_MASK)
    #define BLE_HAL_Uart_SS1_HSIOM_POS      (BLE_HAL_Uart_spi_ss1__0__HSIOM_SHIFT)
#endif /* (BLE_HAL_Uart_SS1_PIN) */

#if (BLE_HAL_Uart_SS2_PIN)
    #define BLE_HAL_Uart_SS2_HSIOM_REG     (*(reg32 *) BLE_HAL_Uart_spi_ss2__0__HSIOM)
    #define BLE_HAL_Uart_SS2_HSIOM_PTR     ( (reg32 *) BLE_HAL_Uart_spi_ss2__0__HSIOM)
    #define BLE_HAL_Uart_SS2_HSIOM_MASK    (BLE_HAL_Uart_spi_ss2__0__HSIOM_MASK)
    #define BLE_HAL_Uart_SS2_HSIOM_POS     (BLE_HAL_Uart_spi_ss2__0__HSIOM_SHIFT)
#endif /* (BLE_HAL_Uart_SS2_PIN) */

#if (BLE_HAL_Uart_SS3_PIN)
    #define BLE_HAL_Uart_SS3_HSIOM_REG     (*(reg32 *) BLE_HAL_Uart_spi_ss3__0__HSIOM)
    #define BLE_HAL_Uart_SS3_HSIOM_PTR     ( (reg32 *) BLE_HAL_Uart_spi_ss3__0__HSIOM)
    #define BLE_HAL_Uart_SS3_HSIOM_MASK    (BLE_HAL_Uart_spi_ss3__0__HSIOM_MASK)
    #define BLE_HAL_Uart_SS3_HSIOM_POS     (BLE_HAL_Uart_spi_ss3__0__HSIOM_SHIFT)
#endif /* (BLE_HAL_Uart_SS3_PIN) */

#if (BLE_HAL_Uart_I2C_PINS)
    #define BLE_HAL_Uart_SCL_HSIOM_REG     (*(reg32 *) BLE_HAL_Uart_scl__0__HSIOM)
    #define BLE_HAL_Uart_SCL_HSIOM_PTR     ( (reg32 *) BLE_HAL_Uart_scl__0__HSIOM)
    #define BLE_HAL_Uart_SCL_HSIOM_MASK    (BLE_HAL_Uart_scl__0__HSIOM_MASK)
    #define BLE_HAL_Uart_SCL_HSIOM_POS     (BLE_HAL_Uart_scl__0__HSIOM_SHIFT)

    #define BLE_HAL_Uart_SDA_HSIOM_REG     (*(reg32 *) BLE_HAL_Uart_sda__0__HSIOM)
    #define BLE_HAL_Uart_SDA_HSIOM_PTR     ( (reg32 *) BLE_HAL_Uart_sda__0__HSIOM)
    #define BLE_HAL_Uart_SDA_HSIOM_MASK    (BLE_HAL_Uart_sda__0__HSIOM_MASK)
    #define BLE_HAL_Uart_SDA_HSIOM_POS     (BLE_HAL_Uart_sda__0__HSIOM_SHIFT)
#endif /* (BLE_HAL_Uart_I2C_PINS) */

#if (BLE_HAL_Uart_SPI_MASTER_SCLK_PIN)
    #define BLE_HAL_Uart_SCLK_M_HSIOM_REG   (*(reg32 *) BLE_HAL_Uart_sclk_m__0__HSIOM)
    #define BLE_HAL_Uart_SCLK_M_HSIOM_PTR   ( (reg32 *) BLE_HAL_Uart_sclk_m__0__HSIOM)
    #define BLE_HAL_Uart_SCLK_M_HSIOM_MASK  (BLE_HAL_Uart_sclk_m__0__HSIOM_MASK)
    #define BLE_HAL_Uart_SCLK_M_HSIOM_POS   (BLE_HAL_Uart_sclk_m__0__HSIOM_SHIFT)
#endif /* (BLE_HAL_Uart_SPI_MASTER_SCLK_PIN) */

#if (BLE_HAL_Uart_SPI_MASTER_SS0_PIN)
    #define BLE_HAL_Uart_SS0_M_HSIOM_REG    (*(reg32 *) BLE_HAL_Uart_ss0_m__0__HSIOM)
    #define BLE_HAL_Uart_SS0_M_HSIOM_PTR    ( (reg32 *) BLE_HAL_Uart_ss0_m__0__HSIOM)
    #define BLE_HAL_Uart_SS0_M_HSIOM_MASK   (BLE_HAL_Uart_ss0_m__0__HSIOM_MASK)
    #define BLE_HAL_Uart_SS0_M_HSIOM_POS    (BLE_HAL_Uart_ss0_m__0__HSIOM_SHIFT)
#endif /* (BLE_HAL_Uart_SPI_MASTER_SS0_PIN) */

#if (BLE_HAL_Uart_SPI_MASTER_SS1_PIN)
    #define BLE_HAL_Uart_SS1_M_HSIOM_REG    (*(reg32 *) BLE_HAL_Uart_ss1_m__0__HSIOM)
    #define BLE_HAL_Uart_SS1_M_HSIOM_PTR    ( (reg32 *) BLE_HAL_Uart_ss1_m__0__HSIOM)
    #define BLE_HAL_Uart_SS1_M_HSIOM_MASK   (BLE_HAL_Uart_ss1_m__0__HSIOM_MASK)
    #define BLE_HAL_Uart_SS1_M_HSIOM_POS    (BLE_HAL_Uart_ss1_m__0__HSIOM_SHIFT)
#endif /* (BLE_HAL_Uart_SPI_MASTER_SS1_PIN) */

#if (BLE_HAL_Uart_SPI_MASTER_SS2_PIN)
    #define BLE_HAL_Uart_SS2_M_HSIOM_REG    (*(reg32 *) BLE_HAL_Uart_ss2_m__0__HSIOM)
    #define BLE_HAL_Uart_SS2_M_HSIOM_PTR    ( (reg32 *) BLE_HAL_Uart_ss2_m__0__HSIOM)
    #define BLE_HAL_Uart_SS2_M_HSIOM_MASK   (BLE_HAL_Uart_ss2_m__0__HSIOM_MASK)
    #define BLE_HAL_Uart_SS2_M_HSIOM_POS    (BLE_HAL_Uart_ss2_m__0__HSIOM_SHIFT)
#endif /* (BLE_HAL_Uart_SPI_MASTER_SS2_PIN) */

#if (BLE_HAL_Uart_SPI_MASTER_SS3_PIN)
    #define BLE_HAL_Uart_SS3_M_HSIOM_REG    (*(reg32 *) BLE_HAL_Uart_ss3_m__0__HSIOM)
    #define BLE_HAL_Uart_SS3_M_HSIOM_PTR    ( (reg32 *) BLE_HAL_Uart_ss3_m__0__HSIOM)
    #define BLE_HAL_Uart_SS3_M_HSIOM_MASK   (BLE_HAL_Uart_ss3_m__0__HSIOM_MASK)
    #define BLE_HAL_Uart_SS3_M_HSIOM_POS    (BLE_HAL_Uart_ss3_m__0__HSIOM_SHIFT)
#endif /* (BLE_HAL_Uart_SPI_MASTER_SS3_PIN) */

#if (BLE_HAL_Uart_UART_TX_PIN)
    #define BLE_HAL_Uart_TX_HSIOM_REG   (*(reg32 *) BLE_HAL_Uart_tx__0__HSIOM)
    #define BLE_HAL_Uart_TX_HSIOM_PTR   ( (reg32 *) BLE_HAL_Uart_tx_0__HSIOM)
    #define BLE_HAL_Uart_TX_HSIOM_MASK  (BLE_HAL_Uart_tx__0__HSIOM_MASK)
    #define BLE_HAL_Uart_TX_HSIOM_POS   (BLE_HAL_Uart_tx__0__HSIOM_SHIFT)
#endif /* (BLE_HAL_Uart_UART_TX_PIN) */

#if (BLE_HAL_Uart_UART_RTS_PIN)
    #define BLE_HAL_Uart_RTS_HSIOM_REG  (*(reg32 *) BLE_HAL_Uart_rts__0__HSIOM)
    #define BLE_HAL_Uart_RTS_HSIOM_PTR  ( (reg32 *) BLE_HAL_Uart_rts__0__HSIOM)
    #define BLE_HAL_Uart_RTS_HSIOM_MASK (BLE_HAL_Uart_rts__0__HSIOM_MASK)
    #define BLE_HAL_Uart_RTS_HSIOM_POS  (BLE_HAL_Uart_rts__0__HSIOM_SHIFT)
#endif /* (BLE_HAL_Uart_UART_RTS_PIN) */


/***************************************
*        Registers Constants
***************************************/

/* Pins constants */
#define BLE_HAL_Uart_HSIOM_DEF_SEL      (0x00u)
#define BLE_HAL_Uart_HSIOM_GPIO_SEL     (0x00u)
#define BLE_HAL_Uart_HSIOM_UART_SEL     (0x09u)
#define BLE_HAL_Uart_HSIOM_I2C_SEL      (0x0Eu)
#define BLE_HAL_Uart_HSIOM_SPI_SEL      (0x0Fu)

#define BLE_HAL_Uart_RX_WAKE_SDA_MOSI_PIN_INDEX   (0u)
#define BLE_HAL_Uart_RX_SDA_MOSI_PIN_INDEX       (0u)
#define BLE_HAL_Uart_TX_SCL_MISO_PIN_INDEX       (1u)
#define BLE_HAL_Uart_CTS_SCLK_PIN_INDEX       (2u)
#define BLE_HAL_Uart_RTS_SS0_PIN_INDEX       (3u)
#define BLE_HAL_Uart_SS1_PIN_INDEX                  (4u)
#define BLE_HAL_Uart_SS2_PIN_INDEX                  (5u)
#define BLE_HAL_Uart_SS3_PIN_INDEX                  (6u)

#define BLE_HAL_Uart_RX_WAKE_SDA_MOSI_PIN_MASK ((uint32) 0x01u << BLE_HAL_Uart_RX_WAKE_SDA_MOSI_PIN_INDEX)
#define BLE_HAL_Uart_RX_SDA_MOSI_PIN_MASK     ((uint32) 0x01u << BLE_HAL_Uart_RX_SDA_MOSI_PIN_INDEX)
#define BLE_HAL_Uart_TX_SCL_MISO_PIN_MASK     ((uint32) 0x01u << BLE_HAL_Uart_TX_SCL_MISO_PIN_INDEX)
#define BLE_HAL_Uart_CTS_SCLK_PIN_MASK     ((uint32) 0x01u << BLE_HAL_Uart_CTS_SCLK_PIN_INDEX)
#define BLE_HAL_Uart_RTS_SS0_PIN_MASK     ((uint32) 0x01u << BLE_HAL_Uart_RTS_SS0_PIN_INDEX)
#define BLE_HAL_Uart_SS1_PIN_MASK                ((uint32) 0x01u << BLE_HAL_Uart_SS1_PIN_INDEX)
#define BLE_HAL_Uart_SS2_PIN_MASK                ((uint32) 0x01u << BLE_HAL_Uart_SS2_PIN_INDEX)
#define BLE_HAL_Uart_SS3_PIN_MASK                ((uint32) 0x01u << BLE_HAL_Uart_SS3_PIN_INDEX)

/* Pin interrupt constants */
#define BLE_HAL_Uart_INTCFG_TYPE_MASK           (0x03u)
#define BLE_HAL_Uart_INTCFG_TYPE_FALLING_EDGE   (0x02u)

/* Pin Drive Mode constants */
#define BLE_HAL_Uart_PIN_DM_ALG_HIZ  (0u)
#define BLE_HAL_Uart_PIN_DM_DIG_HIZ  (1u)
#define BLE_HAL_Uart_PIN_DM_OD_LO    (4u)
#define BLE_HAL_Uart_PIN_DM_STRONG   (6u)


/***************************************
*          Macro Definitions
***************************************/

/* Return drive mode of the pin */
#define BLE_HAL_Uart_DM_MASK    (0x7u)
#define BLE_HAL_Uart_DM_SIZE    (3)
#define BLE_HAL_Uart_GET_P4_PIN_DM(reg, pos) \
    ( ((reg) & (uint32) ((uint32) BLE_HAL_Uart_DM_MASK << (BLE_HAL_Uart_DM_SIZE * (pos)))) >> \
                                                              (BLE_HAL_Uart_DM_SIZE * (pos)) )

#if (BLE_HAL_Uart_TX_SCL_MISO_PIN)
    #define BLE_HAL_Uart_CHECK_TX_SCL_MISO_PIN_USED \
                (BLE_HAL_Uart_PIN_DM_ALG_HIZ != \
                    BLE_HAL_Uart_GET_P4_PIN_DM(BLE_HAL_Uart_uart_tx_i2c_scl_spi_miso_PC, \
                                                   BLE_HAL_Uart_uart_tx_i2c_scl_spi_miso_SHIFT))
#endif /* (BLE_HAL_Uart_TX_SCL_MISO_PIN) */

#if (BLE_HAL_Uart_RTS_SS0_PIN)
    #define BLE_HAL_Uart_CHECK_RTS_SS0_PIN_USED \
                (BLE_HAL_Uart_PIN_DM_ALG_HIZ != \
                    BLE_HAL_Uart_GET_P4_PIN_DM(BLE_HAL_Uart_uart_rts_spi_ss0_PC, \
                                                   BLE_HAL_Uart_uart_rts_spi_ss0_SHIFT))
#endif /* (BLE_HAL_Uart_RTS_SS0_PIN) */

/* Set bits-mask in register */
#define BLE_HAL_Uart_SET_REGISTER_BITS(reg, mask, pos, mode) \
                    do                                           \
                    {                                            \
                        (reg) = (((reg) & ((uint32) ~(uint32) (mask))) | ((uint32) ((uint32) (mode) << (pos)))); \
                    }while(0)

/* Set bit in the register */
#define BLE_HAL_Uart_SET_REGISTER_BIT(reg, mask, val) \
                    ((val) ? ((reg) |= (mask)) : ((reg) &= ((uint32) ~((uint32) (mask)))))

#define BLE_HAL_Uart_SET_HSIOM_SEL(reg, mask, pos, sel) BLE_HAL_Uart_SET_REGISTER_BITS(reg, mask, pos, sel)
#define BLE_HAL_Uart_SET_INCFG_TYPE(reg, mask, pos, intType) \
                                                        BLE_HAL_Uart_SET_REGISTER_BITS(reg, mask, pos, intType)
#define BLE_HAL_Uart_SET_INP_DIS(reg, mask, val) BLE_HAL_Uart_SET_REGISTER_BIT(reg, mask, val)

/* BLE_HAL_Uart_SET_I2C_SCL_DR(val) - Sets I2C SCL DR register.
*  BLE_HAL_Uart_SET_I2C_SCL_HSIOM_SEL(sel) - Sets I2C SCL HSIOM settings.
*/
/* SCB I2C: scl signal */
#if (BLE_HAL_Uart_CY_SCBIP_V0)
#if (BLE_HAL_Uart_I2C_PINS)
    #define BLE_HAL_Uart_SET_I2C_SCL_DR(val) BLE_HAL_Uart_scl_Write(val)

    #define BLE_HAL_Uart_SET_I2C_SCL_HSIOM_SEL(sel) \
                          BLE_HAL_Uart_SET_HSIOM_SEL(BLE_HAL_Uart_SCL_HSIOM_REG,  \
                                                         BLE_HAL_Uart_SCL_HSIOM_MASK, \
                                                         BLE_HAL_Uart_SCL_HSIOM_POS,  \
                                                         (sel))
    #define BLE_HAL_Uart_WAIT_SCL_SET_HIGH  (0u == BLE_HAL_Uart_scl_Read())

/* Unconfigured SCB: scl signal */
#elif (BLE_HAL_Uart_RX_WAKE_SDA_MOSI_PIN)
    #define BLE_HAL_Uart_SET_I2C_SCL_DR(val) \
                            BLE_HAL_Uart_uart_rx_wake_i2c_sda_spi_mosi_Write(val)

    #define BLE_HAL_Uart_SET_I2C_SCL_HSIOM_SEL(sel) \
                    BLE_HAL_Uart_SET_HSIOM_SEL(BLE_HAL_Uart_RX_WAKE_SDA_MOSI_HSIOM_REG,  \
                                                   BLE_HAL_Uart_RX_WAKE_SDA_MOSI_HSIOM_MASK, \
                                                   BLE_HAL_Uart_RX_WAKE_SDA_MOSI_HSIOM_POS,  \
                                                   (sel))

    #define BLE_HAL_Uart_WAIT_SCL_SET_HIGH  (0u == BLE_HAL_Uart_uart_rx_wake_i2c_sda_spi_mosi_Read())

#elif (BLE_HAL_Uart_RX_SDA_MOSI_PIN)
    #define BLE_HAL_Uart_SET_I2C_SCL_DR(val) \
                            BLE_HAL_Uart_uart_rx_i2c_sda_spi_mosi_Write(val)


    #define BLE_HAL_Uart_SET_I2C_SCL_HSIOM_SEL(sel) \
                            BLE_HAL_Uart_SET_HSIOM_SEL(BLE_HAL_Uart_RX_SDA_MOSI_HSIOM_REG,  \
                                                           BLE_HAL_Uart_RX_SDA_MOSI_HSIOM_MASK, \
                                                           BLE_HAL_Uart_RX_SDA_MOSI_HSIOM_POS,  \
                                                           (sel))

    #define BLE_HAL_Uart_WAIT_SCL_SET_HIGH  (0u == BLE_HAL_Uart_uart_rx_i2c_sda_spi_mosi_Read())

#else
    #define BLE_HAL_Uart_SET_I2C_SCL_DR(val) \
                                                    do{ /* Does nothing */ }while(0)
    #define BLE_HAL_Uart_SET_I2C_SCL_HSIOM_SEL(sel) \
                                                    do{ /* Does nothing */ }while(0)

    #define BLE_HAL_Uart_WAIT_SCL_SET_HIGH  (0u)
#endif /* (BLE_HAL_Uart_I2C_PINS) */

/* SCB I2C: sda signal */
#if (BLE_HAL_Uart_I2C_PINS)
    #define BLE_HAL_Uart_WAIT_SDA_SET_HIGH  (0u == BLE_HAL_Uart_sda_Read())
/* Unconfigured SCB: sda signal */
#elif (BLE_HAL_Uart_TX_SCL_MISO_PIN)
    #define BLE_HAL_Uart_WAIT_SDA_SET_HIGH  (0u == BLE_HAL_Uart_uart_tx_i2c_scl_spi_miso_Read())
#else
    #define BLE_HAL_Uart_WAIT_SDA_SET_HIGH  (0u)
#endif /* (BLE_HAL_Uart_MOSI_SCL_RX_PIN) */
#endif /* (BLE_HAL_Uart_CY_SCBIP_V0) */


/***************************************
* The following code is DEPRECATED and
* must not be used.
***************************************/

/* Unconfigured pins */
#define BLE_HAL_Uart_REMOVE_MOSI_SCL_RX_WAKE_PIN    BLE_HAL_Uart_REMOVE_RX_WAKE_SDA_MOSI_PIN
#define BLE_HAL_Uart_REMOVE_MOSI_SCL_RX_PIN         BLE_HAL_Uart_REMOVE_RX_SDA_MOSI_PIN
#define BLE_HAL_Uart_REMOVE_MISO_SDA_TX_PIN         BLE_HAL_Uart_REMOVE_TX_SCL_MISO_PIN
#ifndef BLE_HAL_Uart_REMOVE_SCLK_PIN
#define BLE_HAL_Uart_REMOVE_SCLK_PIN                BLE_HAL_Uart_REMOVE_CTS_SCLK_PIN
#endif /* BLE_HAL_Uart_REMOVE_SCLK_PIN */
#ifndef BLE_HAL_Uart_REMOVE_SS0_PIN
#define BLE_HAL_Uart_REMOVE_SS0_PIN                 BLE_HAL_Uart_REMOVE_RTS_SS0_PIN
#endif /* BLE_HAL_Uart_REMOVE_SS0_PIN */

/* Unconfigured pins */
#define BLE_HAL_Uart_MOSI_SCL_RX_WAKE_PIN   BLE_HAL_Uart_RX_WAKE_SDA_MOSI_PIN
#define BLE_HAL_Uart_MOSI_SCL_RX_PIN        BLE_HAL_Uart_RX_SDA_MOSI_PIN
#define BLE_HAL_Uart_MISO_SDA_TX_PIN        BLE_HAL_Uart_TX_SCL_MISO_PIN
#ifndef BLE_HAL_Uart_SCLK_PIN
#define BLE_HAL_Uart_SCLK_PIN               BLE_HAL_Uart_CTS_SCLK_PIN
#endif /* BLE_HAL_Uart_SCLK_PIN */
#ifndef BLE_HAL_Uart_SS0_PIN
#define BLE_HAL_Uart_SS0_PIN                BLE_HAL_Uart_RTS_SS0_PIN
#endif /* BLE_HAL_Uart_SS0_PIN */

#if (BLE_HAL_Uart_MOSI_SCL_RX_WAKE_PIN)
    #define BLE_HAL_Uart_MOSI_SCL_RX_WAKE_HSIOM_REG     BLE_HAL_Uart_RX_WAKE_SDA_MOSI_HSIOM_REG
    #define BLE_HAL_Uart_MOSI_SCL_RX_WAKE_HSIOM_PTR     BLE_HAL_Uart_RX_WAKE_SDA_MOSI_HSIOM_REG
    #define BLE_HAL_Uart_MOSI_SCL_RX_WAKE_HSIOM_MASK    BLE_HAL_Uart_RX_WAKE_SDA_MOSI_HSIOM_REG
    #define BLE_HAL_Uart_MOSI_SCL_RX_WAKE_HSIOM_POS     BLE_HAL_Uart_RX_WAKE_SDA_MOSI_HSIOM_REG

    #define BLE_HAL_Uart_MOSI_SCL_RX_WAKE_INTCFG_REG    BLE_HAL_Uart_RX_WAKE_SDA_MOSI_HSIOM_REG
    #define BLE_HAL_Uart_MOSI_SCL_RX_WAKE_INTCFG_PTR    BLE_HAL_Uart_RX_WAKE_SDA_MOSI_HSIOM_REG

    #define BLE_HAL_Uart_MOSI_SCL_RX_WAKE_INTCFG_TYPE_POS   BLE_HAL_Uart_RX_WAKE_SDA_MOSI_HSIOM_REG
    #define BLE_HAL_Uart_MOSI_SCL_RX_WAKE_INTCFG_TYPE_MASK  BLE_HAL_Uart_RX_WAKE_SDA_MOSI_HSIOM_REG
#endif /* (BLE_HAL_Uart_RX_WAKE_SDA_MOSI_PIN) */

#if (BLE_HAL_Uart_MOSI_SCL_RX_PIN)
    #define BLE_HAL_Uart_MOSI_SCL_RX_HSIOM_REG      BLE_HAL_Uart_RX_SDA_MOSI_HSIOM_REG
    #define BLE_HAL_Uart_MOSI_SCL_RX_HSIOM_PTR      BLE_HAL_Uart_RX_SDA_MOSI_HSIOM_PTR
    #define BLE_HAL_Uart_MOSI_SCL_RX_HSIOM_MASK     BLE_HAL_Uart_RX_SDA_MOSI_HSIOM_MASK
    #define BLE_HAL_Uart_MOSI_SCL_RX_HSIOM_POS      BLE_HAL_Uart_RX_SDA_MOSI_HSIOM_POS
#endif /* (BLE_HAL_Uart_MOSI_SCL_RX_PIN) */

#if (BLE_HAL_Uart_MISO_SDA_TX_PIN)
    #define BLE_HAL_Uart_MISO_SDA_TX_HSIOM_REG      BLE_HAL_Uart_TX_SCL_MISO_HSIOM_REG
    #define BLE_HAL_Uart_MISO_SDA_TX_HSIOM_PTR      BLE_HAL_Uart_TX_SCL_MISO_HSIOM_REG
    #define BLE_HAL_Uart_MISO_SDA_TX_HSIOM_MASK     BLE_HAL_Uart_TX_SCL_MISO_HSIOM_REG
    #define BLE_HAL_Uart_MISO_SDA_TX_HSIOM_POS      BLE_HAL_Uart_TX_SCL_MISO_HSIOM_REG
#endif /* (BLE_HAL_Uart_MISO_SDA_TX_PIN_PIN) */

#if (BLE_HAL_Uart_SCLK_PIN)
    #ifndef BLE_HAL_Uart_SCLK_HSIOM_REG
    #define BLE_HAL_Uart_SCLK_HSIOM_REG     BLE_HAL_Uart_CTS_SCLK_HSIOM_REG
    #define BLE_HAL_Uart_SCLK_HSIOM_PTR     BLE_HAL_Uart_CTS_SCLK_HSIOM_PTR
    #define BLE_HAL_Uart_SCLK_HSIOM_MASK    BLE_HAL_Uart_CTS_SCLK_HSIOM_MASK
    #define BLE_HAL_Uart_SCLK_HSIOM_POS     BLE_HAL_Uart_CTS_SCLK_HSIOM_POS
    #endif /* BLE_HAL_Uart_SCLK_HSIOM_REG */
#endif /* (BLE_HAL_Uart_SCLK_PIN) */

#if (BLE_HAL_Uart_SS0_PIN)
    #ifndef BLE_HAL_Uart_SS0_HSIOM_REG
    #define BLE_HAL_Uart_SS0_HSIOM_REG      BLE_HAL_Uart_RTS_SS0_HSIOM_REG
    #define BLE_HAL_Uart_SS0_HSIOM_PTR      BLE_HAL_Uart_RTS_SS0_HSIOM_PTR
    #define BLE_HAL_Uart_SS0_HSIOM_MASK     BLE_HAL_Uart_RTS_SS0_HSIOM_MASK
    #define BLE_HAL_Uart_SS0_HSIOM_POS      BLE_HAL_Uart_RTS_SS0_HSIOM_POS
    #endif /* BLE_HAL_Uart_SS0_HSIOM_REG */
#endif /* (BLE_HAL_Uart_SS0_PIN) */

#define BLE_HAL_Uart_MOSI_SCL_RX_WAKE_PIN_INDEX BLE_HAL_Uart_RX_WAKE_SDA_MOSI_PIN_INDEX
#define BLE_HAL_Uart_MOSI_SCL_RX_PIN_INDEX      BLE_HAL_Uart_RX_SDA_MOSI_PIN_INDEX
#define BLE_HAL_Uart_MISO_SDA_TX_PIN_INDEX      BLE_HAL_Uart_TX_SCL_MISO_PIN_INDEX
#ifndef BLE_HAL_Uart_SCLK_PIN_INDEX
#define BLE_HAL_Uart_SCLK_PIN_INDEX             BLE_HAL_Uart_CTS_SCLK_PIN_INDEX
#endif /* BLE_HAL_Uart_SCLK_PIN_INDEX */
#ifndef BLE_HAL_Uart_SS0_PIN_INDEX
#define BLE_HAL_Uart_SS0_PIN_INDEX              BLE_HAL_Uart_RTS_SS0_PIN_INDEX
#endif /* BLE_HAL_Uart_SS0_PIN_INDEX */

#define BLE_HAL_Uart_MOSI_SCL_RX_WAKE_PIN_MASK BLE_HAL_Uart_RX_WAKE_SDA_MOSI_PIN_MASK
#define BLE_HAL_Uart_MOSI_SCL_RX_PIN_MASK      BLE_HAL_Uart_RX_SDA_MOSI_PIN_MASK
#define BLE_HAL_Uart_MISO_SDA_TX_PIN_MASK      BLE_HAL_Uart_TX_SCL_MISO_PIN_MASK
#ifndef BLE_HAL_Uart_SCLK_PIN_MASK
#define BLE_HAL_Uart_SCLK_PIN_MASK             BLE_HAL_Uart_CTS_SCLK_PIN_MASK
#endif /* BLE_HAL_Uart_SCLK_PIN_MASK */
#ifndef BLE_HAL_Uart_SS0_PIN_MASK
#define BLE_HAL_Uart_SS0_PIN_MASK              BLE_HAL_Uart_RTS_SS0_PIN_MASK
#endif /* BLE_HAL_Uart_SS0_PIN_MASK */

#endif /* (CY_SCB_PINS_BLE_HAL_Uart_H) */


/* [] END OF FILE */
