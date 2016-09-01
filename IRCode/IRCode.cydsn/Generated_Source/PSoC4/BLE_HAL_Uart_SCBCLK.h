/*******************************************************************************
* File Name: BLE_HAL_Uart_SCBCLK.h
* Version 2.20
*
*  Description:
*   Provides the function and constant definitions for the clock component.
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CLOCK_BLE_HAL_Uart_SCBCLK_H)
#define CY_CLOCK_BLE_HAL_Uart_SCBCLK_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
*        Function Prototypes
***************************************/
#if defined CYREG_PERI_DIV_CMD

void BLE_HAL_Uart_SCBCLK_StartEx(uint32 alignClkDiv);
#define BLE_HAL_Uart_SCBCLK_Start() \
    BLE_HAL_Uart_SCBCLK_StartEx(BLE_HAL_Uart_SCBCLK__PA_DIV_ID)

#else

void BLE_HAL_Uart_SCBCLK_Start(void);

#endif/* CYREG_PERI_DIV_CMD */

void BLE_HAL_Uart_SCBCLK_Stop(void);

void BLE_HAL_Uart_SCBCLK_SetFractionalDividerRegister(uint16 clkDivider, uint8 clkFractional);

uint16 BLE_HAL_Uart_SCBCLK_GetDividerRegister(void);
uint8  BLE_HAL_Uart_SCBCLK_GetFractionalDividerRegister(void);

#define BLE_HAL_Uart_SCBCLK_Enable()                         BLE_HAL_Uart_SCBCLK_Start()
#define BLE_HAL_Uart_SCBCLK_Disable()                        BLE_HAL_Uart_SCBCLK_Stop()
#define BLE_HAL_Uart_SCBCLK_SetDividerRegister(clkDivider, reset)  \
    BLE_HAL_Uart_SCBCLK_SetFractionalDividerRegister((clkDivider), 0u)
#define BLE_HAL_Uart_SCBCLK_SetDivider(clkDivider)           BLE_HAL_Uart_SCBCLK_SetDividerRegister((clkDivider), 1u)
#define BLE_HAL_Uart_SCBCLK_SetDividerValue(clkDivider)      BLE_HAL_Uart_SCBCLK_SetDividerRegister((clkDivider) - 1u, 1u)


/***************************************
*             Registers
***************************************/
#if defined CYREG_PERI_DIV_CMD

#define BLE_HAL_Uart_SCBCLK_DIV_ID     BLE_HAL_Uart_SCBCLK__DIV_ID

#define BLE_HAL_Uart_SCBCLK_CMD_REG    (*(reg32 *)CYREG_PERI_DIV_CMD)
#define BLE_HAL_Uart_SCBCLK_CTRL_REG   (*(reg32 *)BLE_HAL_Uart_SCBCLK__CTRL_REGISTER)
#define BLE_HAL_Uart_SCBCLK_DIV_REG    (*(reg32 *)BLE_HAL_Uart_SCBCLK__DIV_REGISTER)

#define BLE_HAL_Uart_SCBCLK_CMD_DIV_SHIFT          (0u)
#define BLE_HAL_Uart_SCBCLK_CMD_PA_DIV_SHIFT       (8u)
#define BLE_HAL_Uart_SCBCLK_CMD_DISABLE_SHIFT      (30u)
#define BLE_HAL_Uart_SCBCLK_CMD_ENABLE_SHIFT       (31u)

#define BLE_HAL_Uart_SCBCLK_CMD_DISABLE_MASK       ((uint32)((uint32)1u << BLE_HAL_Uart_SCBCLK_CMD_DISABLE_SHIFT))
#define BLE_HAL_Uart_SCBCLK_CMD_ENABLE_MASK        ((uint32)((uint32)1u << BLE_HAL_Uart_SCBCLK_CMD_ENABLE_SHIFT))

#define BLE_HAL_Uart_SCBCLK_DIV_FRAC_MASK  (0x000000F8u)
#define BLE_HAL_Uart_SCBCLK_DIV_FRAC_SHIFT (3u)
#define BLE_HAL_Uart_SCBCLK_DIV_INT_MASK   (0xFFFFFF00u)
#define BLE_HAL_Uart_SCBCLK_DIV_INT_SHIFT  (8u)

#else 

#define BLE_HAL_Uart_SCBCLK_DIV_REG        (*(reg32 *)BLE_HAL_Uart_SCBCLK__REGISTER)
#define BLE_HAL_Uart_SCBCLK_ENABLE_REG     BLE_HAL_Uart_SCBCLK_DIV_REG
#define BLE_HAL_Uart_SCBCLK_DIV_FRAC_MASK  BLE_HAL_Uart_SCBCLK__FRAC_MASK
#define BLE_HAL_Uart_SCBCLK_DIV_FRAC_SHIFT (16u)
#define BLE_HAL_Uart_SCBCLK_DIV_INT_MASK   BLE_HAL_Uart_SCBCLK__DIVIDER_MASK
#define BLE_HAL_Uart_SCBCLK_DIV_INT_SHIFT  (0u)

#endif/* CYREG_PERI_DIV_CMD */

#endif /* !defined(CY_CLOCK_BLE_HAL_Uart_SCBCLK_H) */

/* [] END OF FILE */
