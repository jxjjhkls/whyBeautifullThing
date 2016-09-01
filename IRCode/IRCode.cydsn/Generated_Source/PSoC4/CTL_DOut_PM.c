/*******************************************************************************
* File Name: CTL_DOut.c  
* Version 2.20
*
* Description:
*  This file contains APIs to set up the Pins component for low power modes.
*
* Note:
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "CTL_DOut.h"

static CTL_DOut_BACKUP_STRUCT  CTL_DOut_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: CTL_DOut_Sleep
****************************************************************************//**
*
* \brief Stores the pin configuration and prepares the pin for entering chip 
*  deep-sleep/hibernate modes. This function must be called for SIO and USBIO
*  pins. It is not essential if using GPIO or GPIO_OVT pins.
*
* <b>Note</b> This function is available in PSoC 4 only.
*
* \return 
*  None 
*  
* \sideeffect
*  For SIO pins, this function configures the pin input threshold to CMOS and
*  drive level to Vddio. This is needed for SIO pins when in device 
*  deep-sleep/hibernate modes.
*
* \funcusage
*  \snippet CTL_DOut_SUT.c usage_CTL_DOut_Sleep_Wakeup
*******************************************************************************/
void CTL_DOut_Sleep(void)
{
    #if defined(CTL_DOut__PC)
        CTL_DOut_backup.pcState = CTL_DOut_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            CTL_DOut_backup.usbState = CTL_DOut_CR1_REG;
            CTL_DOut_USB_POWER_REG |= CTL_DOut_USBIO_ENTER_SLEEP;
            CTL_DOut_CR1_REG &= CTL_DOut_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(CTL_DOut__SIO)
        CTL_DOut_backup.sioState = CTL_DOut_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        CTL_DOut_SIO_REG &= (uint32)(~CTL_DOut_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: CTL_DOut_Wakeup
****************************************************************************//**
*
* \brief Restores the pin configuration that was saved during Pin_Sleep().
*
* For USBIO pins, the wakeup is only triggered for falling edge interrupts.
*
* <b>Note</b> This function is available in PSoC 4 only.
*
* \return 
*  None
*  
* \funcusage
*  Refer to CTL_DOut_Sleep() for an example usage.
*******************************************************************************/
void CTL_DOut_Wakeup(void)
{
    #if defined(CTL_DOut__PC)
        CTL_DOut_PC = CTL_DOut_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            CTL_DOut_USB_POWER_REG &= CTL_DOut_USBIO_EXIT_SLEEP_PH1;
            CTL_DOut_CR1_REG = CTL_DOut_backup.usbState;
            CTL_DOut_USB_POWER_REG &= CTL_DOut_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(CTL_DOut__SIO)
        CTL_DOut_SIO_REG = CTL_DOut_backup.sioState;
    #endif
}


/* [] END OF FILE */
