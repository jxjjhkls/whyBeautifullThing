/*******************************************************************************
* File Name: CTL_DOut.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_CTL_DOut_H) /* Pins CTL_DOut_H */
#define CY_PINS_CTL_DOut_H

#include "cytypes.h"
#include "cyfitter.h"
#include "CTL_DOut_aliases.h"


/***************************************
*     Data Struct Definitions
***************************************/

/**
* \addtogroup group_structures
* @{
*/
    
/* Structure for sleep mode support */
typedef struct
{
    uint32 pcState; /**< State of the port control register */
    uint32 sioState; /**< State of the SIO configuration */
    uint32 usbState; /**< State of the USBIO regulator */
} CTL_DOut_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   CTL_DOut_Read(void);
void    CTL_DOut_Write(uint8 value);
uint8   CTL_DOut_ReadDataReg(void);
#if defined(CTL_DOut__PC) || (CY_PSOC4_4200L) 
    void    CTL_DOut_SetDriveMode(uint8 mode);
#endif
void    CTL_DOut_SetInterruptMode(uint16 position, uint16 mode);
uint8   CTL_DOut_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void CTL_DOut_Sleep(void); 
void CTL_DOut_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(CTL_DOut__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define CTL_DOut_DRIVE_MODE_BITS        (3)
    #define CTL_DOut_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - CTL_DOut_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the CTL_DOut_SetDriveMode() function.
         *  @{
         */
        #define CTL_DOut_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define CTL_DOut_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define CTL_DOut_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define CTL_DOut_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define CTL_DOut_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define CTL_DOut_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define CTL_DOut_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define CTL_DOut_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define CTL_DOut_MASK               CTL_DOut__MASK
#define CTL_DOut_SHIFT              CTL_DOut__SHIFT
#define CTL_DOut_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in CTL_DOut_SetInterruptMode() function.
     *  @{
     */
        #define CTL_DOut_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define CTL_DOut_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define CTL_DOut_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define CTL_DOut_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(CTL_DOut__SIO)
    #define CTL_DOut_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(CTL_DOut__PC) && (CY_PSOC4_4200L)
    #define CTL_DOut_USBIO_ENABLE               ((uint32)0x80000000u)
    #define CTL_DOut_USBIO_DISABLE              ((uint32)(~CTL_DOut_USBIO_ENABLE))
    #define CTL_DOut_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define CTL_DOut_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define CTL_DOut_USBIO_ENTER_SLEEP          ((uint32)((1u << CTL_DOut_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << CTL_DOut_USBIO_SUSPEND_DEL_SHIFT)))
    #define CTL_DOut_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << CTL_DOut_USBIO_SUSPEND_SHIFT)))
    #define CTL_DOut_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << CTL_DOut_USBIO_SUSPEND_DEL_SHIFT)))
    #define CTL_DOut_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(CTL_DOut__PC)
    /* Port Configuration */
    #define CTL_DOut_PC                 (* (reg32 *) CTL_DOut__PC)
#endif
/* Pin State */
#define CTL_DOut_PS                     (* (reg32 *) CTL_DOut__PS)
/* Data Register */
#define CTL_DOut_DR                     (* (reg32 *) CTL_DOut__DR)
/* Input Buffer Disable Override */
#define CTL_DOut_INP_DIS                (* (reg32 *) CTL_DOut__PC2)

/* Interrupt configuration Registers */
#define CTL_DOut_INTCFG                 (* (reg32 *) CTL_DOut__INTCFG)
#define CTL_DOut_INTSTAT                (* (reg32 *) CTL_DOut__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define CTL_DOut_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(CTL_DOut__SIO)
    #define CTL_DOut_SIO_REG            (* (reg32 *) CTL_DOut__SIO)
#endif /* (CTL_DOut__SIO_CFG) */

/* USBIO registers */
#if !defined(CTL_DOut__PC) && (CY_PSOC4_4200L)
    #define CTL_DOut_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define CTL_DOut_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define CTL_DOut_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define CTL_DOut_DRIVE_MODE_SHIFT       (0x00u)
#define CTL_DOut_DRIVE_MODE_MASK        (0x07u << CTL_DOut_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins CTL_DOut_H */


/* [] END OF FILE */
