/*******************************************************************************
* File Name: MIDI_OUT.c  
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
#include "MIDI_OUT.h"

static MIDI_OUT_BACKUP_STRUCT  MIDI_OUT_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: MIDI_OUT_Sleep
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
*  \snippet MIDI_OUT_SUT.c usage_MIDI_OUT_Sleep_Wakeup
*******************************************************************************/
void MIDI_OUT_Sleep(void)
{
    #if defined(MIDI_OUT__PC)
        MIDI_OUT_backup.pcState = MIDI_OUT_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            MIDI_OUT_backup.usbState = MIDI_OUT_CR1_REG;
            MIDI_OUT_USB_POWER_REG |= MIDI_OUT_USBIO_ENTER_SLEEP;
            MIDI_OUT_CR1_REG &= MIDI_OUT_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(MIDI_OUT__SIO)
        MIDI_OUT_backup.sioState = MIDI_OUT_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        MIDI_OUT_SIO_REG &= (uint32)(~MIDI_OUT_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: MIDI_OUT_Wakeup
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
*  Refer to MIDI_OUT_Sleep() for an example usage.
*******************************************************************************/
void MIDI_OUT_Wakeup(void)
{
    #if defined(MIDI_OUT__PC)
        MIDI_OUT_PC = MIDI_OUT_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            MIDI_OUT_USB_POWER_REG &= MIDI_OUT_USBIO_EXIT_SLEEP_PH1;
            MIDI_OUT_CR1_REG = MIDI_OUT_backup.usbState;
            MIDI_OUT_USB_POWER_REG &= MIDI_OUT_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(MIDI_OUT__SIO)
        MIDI_OUT_SIO_REG = MIDI_OUT_backup.sioState;
    #endif
}


/* [] END OF FILE */
