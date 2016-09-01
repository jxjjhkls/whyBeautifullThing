/*******************************************************************************
* File Name: Samp_DIN.h  
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

#if !defined(CY_PINS_Samp_DIN_ALIASES_H) /* Pins Samp_DIN_ALIASES_H */
#define CY_PINS_Samp_DIN_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define Samp_DIN_0			(Samp_DIN__0__PC)
#define Samp_DIN_0_PS		(Samp_DIN__0__PS)
#define Samp_DIN_0_PC		(Samp_DIN__0__PC)
#define Samp_DIN_0_DR		(Samp_DIN__0__DR)
#define Samp_DIN_0_SHIFT	(Samp_DIN__0__SHIFT)
#define Samp_DIN_0_INTR	((uint16)((uint16)0x0003u << (Samp_DIN__0__SHIFT*2u)))

#define Samp_DIN_INTR_ALL	 ((uint16)(Samp_DIN_0_INTR))


#endif /* End Pins Samp_DIN_ALIASES_H */


/* [] END OF FILE */
