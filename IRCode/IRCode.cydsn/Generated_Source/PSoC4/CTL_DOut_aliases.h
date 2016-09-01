/*******************************************************************************
* File Name: CTL_DOut.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_CTL_DOut_ALIASES_H) /* Pins CTL_DOut_ALIASES_H */
#define CY_PINS_CTL_DOut_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define CTL_DOut_0			(CTL_DOut__0__PC)
#define CTL_DOut_0_PS		(CTL_DOut__0__PS)
#define CTL_DOut_0_PC		(CTL_DOut__0__PC)
#define CTL_DOut_0_DR		(CTL_DOut__0__DR)
#define CTL_DOut_0_SHIFT	(CTL_DOut__0__SHIFT)
#define CTL_DOut_0_INTR	((uint16)((uint16)0x0003u << (CTL_DOut__0__SHIFT*2u)))

#define CTL_DOut_INTR_ALL	 ((uint16)(CTL_DOut_0_INTR))


#endif /* End Pins CTL_DOut_ALIASES_H */


/* [] END OF FILE */
