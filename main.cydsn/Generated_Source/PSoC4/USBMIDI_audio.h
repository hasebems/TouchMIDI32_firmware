/***************************************************************************//**
* \file USBMIDI_audio.h
* \version 3.10
*
* \brief
*  This file provides function prototypes and constants for the USBFS component 
*  Audio class.
*
* Related Document:
*  Universal Serial Bus Device Class Definition for Audio Devices Release 1.0
*
********************************************************************************
* \copyright
* Copyright 2008-2016, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_USBFS_USBMIDI_audio_H)
#define CY_USBFS_USBMIDI_audio_H

#include "USBMIDI.h"


/***************************************
* Custom Declarations
***************************************/

/* `#START CUSTOM_CONSTANTS` Place your declaration here */

/* `#END` */


/***************************************
*  Constants for USBMIDI_audio API.
***************************************/

/* Audio Class-Specific Request Codes (AUDIO Table A-9) */
#define USBMIDI_REQUEST_CODE_UNDEFINED     (0x00u)
#define USBMIDI_SET_CUR                    (0x01u)
#define USBMIDI_GET_CUR                    (0x81u)
#define USBMIDI_SET_MIN                    (0x02u)
#define USBMIDI_GET_MIN                    (0x82u)
#define USBMIDI_SET_MAX                    (0x03u)
#define USBMIDI_GET_MAX                    (0x83u)
#define USBMIDI_SET_RES                    (0x04u)
#define USBMIDI_GET_RES                    (0x84u)
#define USBMIDI_SET_MEM                    (0x05u)
#define USBMIDI_GET_MEM                    (0x85u)
#define USBMIDI_GET_STAT                   (0xFFu)

/* point Control Selectors (AUDIO Table A-19) */
#define USBMIDI_EP_CONTROL_UNDEFINED       (0x00u)
#define USBMIDI_SAMPLING_FREQ_CONTROL      (0x01u)
#define USBMIDI_PITCH_CONTROL              (0x02u)

/* Feature Unit Control Selectors (AUDIO Table A-11) */
#define USBMIDI_FU_CONTROL_UNDEFINED       (0x00u)
#define USBMIDI_MUTE_CONTROL               (0x01u)
#define USBMIDI_VOLUME_CONTROL             (0x02u)
#define USBMIDI_BASS_CONTROL               (0x03u)
#define USBMIDI_MID_CONTROL                (0x04u)
#define USBMIDI_TREBLE_CONTROL             (0x05u)
#define USBMIDI_GRAPHIC_EQUALIZER_CONTROL  (0x06u)
#define USBMIDI_AUTOMATIC_GAIN_CONTROL     (0x07u)
#define USBMIDI_DELAY_CONTROL              (0x08u)
#define USBMIDI_BASS_BOOST_CONTROL         (0x09u)
#define USBMIDI_LOUDNESS_CONTROL           (0x0Au)

#define USBMIDI_SAMPLE_FREQ_LEN            (3u)
#define USBMIDI_VOLUME_LEN                 (2u)

#if !defined(USER_SUPPLIED_DEFAULT_VOLUME_VALUE)
    #define USBMIDI_VOL_MIN_MSB            (0x80u)
    #define USBMIDI_VOL_MIN_LSB            (0x01u)
    #define USBMIDI_VOL_MAX_MSB            (0x7Fu)
    #define USBMIDI_VOL_MAX_LSB            (0xFFu)
    #define USBMIDI_VOL_RES_MSB            (0x00u)
    #define USBMIDI_VOL_RES_LSB            (0x01u)
#endif /* USER_SUPPLIED_DEFAULT_VOLUME_VALUE */


/***************************************
* External data references
***************************************/
/**
* \addtogroup group_audio
* @{
*/
extern volatile uint8 USBMIDI_currentSampleFrequency[USBMIDI_MAX_EP][USBMIDI_SAMPLE_FREQ_LEN];
extern volatile uint8 USBMIDI_frequencyChanged;
extern volatile uint8 USBMIDI_currentMute;
extern volatile uint8 USBMIDI_currentVolume[USBMIDI_VOLUME_LEN];
/** @} audio */

extern volatile uint8 USBMIDI_minimumVolume[USBMIDI_VOLUME_LEN];
extern volatile uint8 USBMIDI_maximumVolume[USBMIDI_VOLUME_LEN];
extern volatile uint8 USBMIDI_resolutionVolume[USBMIDI_VOLUME_LEN];

#endif /*  CY_USBFS_USBMIDI_audio_H */


/* [] END OF FILE */
