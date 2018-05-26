/*******************************************************************************
* File Name: MIDI_OUT.h  
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

#if !defined(CY_PINS_MIDI_OUT_ALIASES_H) /* Pins MIDI_OUT_ALIASES_H */
#define CY_PINS_MIDI_OUT_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define MIDI_OUT_0			(MIDI_OUT__0__PC)
#define MIDI_OUT_0_PS		(MIDI_OUT__0__PS)
#define MIDI_OUT_0_PC		(MIDI_OUT__0__PC)
#define MIDI_OUT_0_DR		(MIDI_OUT__0__DR)
#define MIDI_OUT_0_SHIFT	(MIDI_OUT__0__SHIFT)
#define MIDI_OUT_0_INTR	((uint16)((uint16)0x0003u << (MIDI_OUT__0__SHIFT*2u)))

#define MIDI_OUT_INTR_ALL	 ((uint16)(MIDI_OUT_0_INTR))


#endif /* End Pins MIDI_OUT_ALIASES_H */


/* [] END OF FILE */
