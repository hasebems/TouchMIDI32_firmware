/*******************************************************************************
* File Name: USBMIDI_Dp.h  
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

#if !defined(CY_PINS_USBMIDI_Dp_ALIASES_H) /* Pins USBMIDI_Dp_ALIASES_H */
#define CY_PINS_USBMIDI_Dp_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define USBMIDI_Dp_0			(USBMIDI_Dp__0__PC)
#define USBMIDI_Dp_0_PS		(USBMIDI_Dp__0__PS)
#define USBMIDI_Dp_0_PC		(USBMIDI_Dp__0__PC)
#define USBMIDI_Dp_0_DR		(USBMIDI_Dp__0__DR)
#define USBMIDI_Dp_0_SHIFT	(USBMIDI_Dp__0__SHIFT)
#define USBMIDI_Dp_0_INTR	((uint16)((uint16)0x0003u << (USBMIDI_Dp__0__SHIFT*2u)))

#define USBMIDI_Dp_INTR_ALL	 ((uint16)(USBMIDI_Dp_0_INTR))


#endif /* End Pins USBMIDI_Dp_ALIASES_H */


/* [] END OF FILE */
