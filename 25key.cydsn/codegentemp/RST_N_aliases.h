/*******************************************************************************
* File Name: RST_N.h  
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

#if !defined(CY_PINS_RST_N_ALIASES_H) /* Pins RST_N_ALIASES_H */
#define CY_PINS_RST_N_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define RST_N_0			(RST_N__0__PC)
#define RST_N_0_PS		(RST_N__0__PS)
#define RST_N_0_PC		(RST_N__0__PC)
#define RST_N_0_DR		(RST_N__0__DR)
#define RST_N_0_SHIFT	(RST_N__0__SHIFT)
#define RST_N_0_INTR	((uint16)((uint16)0x0003u << (RST_N__0__SHIFT*2u)))

#define RST_N_INTR_ALL	 ((uint16)(RST_N_0_INTR))


#endif /* End Pins RST_N_ALIASES_H */


/* [] END OF FILE */
