/***************************************************************************//**
* \file USBMIDI_midi.h
* \version 3.10
*
* \brief
*  This file provides function prototypes and constants for the USBFS component 
*  MIDI class support.
*
* Related Document:
*  Universal Serial Bus Device Class Definition for MIDI Devices Release 1.0
*  MIDI 1.0 Detailed Specification Document Version 4.2
*
********************************************************************************
* \copyright
* Copyright 2008-2016, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_USBFS_USBMIDI_midi_H)
#define CY_USBFS_USBMIDI_midi_H

#include "USBMIDI.h"

/***************************************
*    Initial Parameter Constants
***************************************/

#define USBMIDI_ENABLE_MIDI_API    (0u != (1u))
#define USBMIDI_MIDI_EXT_MODE      (0u)
#define USBMIDI_ENABLE_MIDI_STREAMING          
#define USBMIDI_MIDI_IN_BUFF_SIZE              (32u)
#define USBMIDI_MIDI_OUT_BUFF_SIZE             (32u)


/* Number of external interfaces (UARTs). */
#define USBMIDI_ONE_EXT_INTRF  (0x01u)
#define USBMIDI_TWO_EXT_INTRF  (0x02u)
    
#define USBMIDI_ISR_SERVICE_MIDI_OUT \
            ((USBMIDI_ENABLE_MIDI_API != 0u) && (USBMIDI_MIDI_OUT_BUFF_SIZE > 0) && \
             (USBMIDI_EP_MANAGEMENT_DMA_AUTO))

#define USBMIDI_ISR_SERVICE_MIDI_IN \
            ((USBMIDI_ENABLE_MIDI_API != 0u) && (USBMIDI_MIDI_IN_BUFF_SIZE > 0))


/***************************************
*    External References
***************************************/

#if (USBMIDI_MIDI_EXT_MODE >= USBMIDI_ONE_EXT_INTRF)
    #include "MIDI1_UART.h"
#endif /* (USBMIDI_MIDI_EXT_MODE >= USBMIDI_ONE_EXT_INTRF) */

#if (USBMIDI_MIDI_EXT_MODE >= USBMIDI_TWO_EXT_INTRF)
    #include "MIDI2_UART.h"
#endif /* (USBMIDI_MIDI_EXT_MODE >= USBMIDI_TWO_EXT_INTRF) */


/***************************************
*    Data Structure Definition
***************************************/

/* The following structure is used to hold status information for
* building and parsing incoming MIDI messages. 
*/
typedef struct
{
    uint8    length;        /* expected length */
    uint8    count;         /* current byte count */
    uint8    size;          /* complete size */
    uint8    runstat;       /* running status */
    uint8    msgBuff[4u];   /* message buffer */
} USBMIDI_MIDI_RX_STATUS;


/***************************************
*       Function Prototypes
***************************************/
/**
* \addtogroup group_midi
* @{
*/
#if defined(USBMIDI_ENABLE_MIDI_STREAMING) && (USBMIDI_ENABLE_MIDI_API != 0u)
    void USBMIDI_MIDI_Init(void) ;

    #if (USBMIDI_MIDI_IN_BUFF_SIZE > 0u)
        void USBMIDI_MIDI_IN_Service(void) ;
        uint8 USBMIDI_PutUsbMidiIn(uint8 ic, const uint8 midiMsg[], uint8 cable) ;
    #endif /* (USBMIDI_MIDI_IN_BUFF_SIZE > 0u) */

    #if (USBMIDI_MIDI_OUT_BUFF_SIZE > 0u)
        void USBMIDI_MIDI_OUT_Service(void) ;
    #endif /* (USBMIDI_MIDI_OUT_BUFF_SIZE > 0u) */
#endif /*  (USBMIDI_ENABLE_MIDI_API != 0u) */


/*******************************************************************************
*   Callback Function Prototypes
*******************************************************************************/

/*******************************************************************************
* Function Name: USBMIDI_callbackLocalMidiEvent
****************************************************************************//**
*
*  This is a callback function that locally processes data received from the PC 
*  in main.c. You should implement this function if you want to use it. It is 
*  called from the USB output processing routine for each MIDI output event 
*  processed (decoded) from the output endpoint buffer. 
*
*  \param cable: Cable number
*  
*  \param midiMsg: Pointer to the 3-byte MIDI message
*
*
***************************************************************************/
void USBMIDI_callbackLocalMidiEvent(uint8 cable, uint8 *midiMsg)
                                                     ;
/** @} midi */
                                                    
/***************************************
*           MIDI Constants.
***************************************/

/* Flag definitions for use with MIDI device inquiry */
#define USBMIDI_INQ_SYSEX_FLAG             (0x01u)
#define USBMIDI_INQ_IDENTITY_REQ_FLAG      (0x02u)

/* USB-MIDI Code Index Number Classifications (MIDI Table 4-1) */
#define USBMIDI_CIN_MASK                   (0x0Fu)
#define USBMIDI_RESERVED0                  (0x00u)
#define USBMIDI_RESERVED1                  (0x01u)
#define USBMIDI_2BYTE_COMMON               (0x02u)
#define USBMIDI_3BYTE_COMMON               (0x03u)
#define USBMIDI_SYSEX                      (0x04u)
#define USBMIDI_1BYTE_COMMON               (0x05u)
#define USBMIDI_SYSEX_ENDS_WITH1           (0x05u)
#define USBMIDI_SYSEX_ENDS_WITH2           (0x06u)
#define USBMIDI_SYSEX_ENDS_WITH3           (0x07u)
#define USBMIDI_NOTE_OFF                   (0x08u)
#define USBMIDI_NOTE_ON                    (0x09u)
#define USBMIDI_POLY_KEY_PRESSURE          (0x0Au)
#define USBMIDI_CONTROL_CHANGE             (0x0Bu)
#define USBMIDI_PROGRAM_CHANGE             (0x0Cu)
#define USBMIDI_CHANNEL_PRESSURE           (0x0Du)
#define USBMIDI_PITCH_BEND_CHANGE          (0x0Eu)
#define USBMIDI_SINGLE_BYTE                (0x0Fu)

#define USBMIDI_CABLE_MASK                 (0xF0u)
#define USBMIDI_MIDI_CABLE_00              (0x00u)
#define USBMIDI_MIDI_CABLE_01              (0x10u)

#define USBMIDI_EVENT_BYTE0                (0x00u)
#define USBMIDI_EVENT_BYTE1                (0x01u)
#define USBMIDI_EVENT_BYTE2                (0x02u)
#define USBMIDI_EVENT_BYTE3                (0x03u)
#define USBMIDI_EVENT_LENGTH               (0x04u)

#define USBMIDI_MIDI_STATUS_BYTE_MASK      (0x80u)
#define USBMIDI_MIDI_STATUS_MASK           (0xF0u)
#define USBMIDI_MIDI_SINGLE_BYTE_MASK      (0x08u)
#define USBMIDI_MIDI_NOTE_OFF              (0x80u)
#define USBMIDI_MIDI_NOTE_ON               (0x90u)
#define USBMIDI_MIDI_POLY_KEY_PRESSURE     (0xA0u)
#define USBMIDI_MIDI_CONTROL_CHANGE        (0xB0u)
#define USBMIDI_MIDI_PROGRAM_CHANGE        (0xC0u)
#define USBMIDI_MIDI_CHANNEL_PRESSURE      (0xD0u)
#define USBMIDI_MIDI_PITCH_BEND_CHANGE     (0xE0u)
#define USBMIDI_MIDI_SYSEX                 (0xF0u)
#define USBMIDI_MIDI_EOSEX                 (0xF7u)
#define USBMIDI_MIDI_QFM                   (0xF1u)
#define USBMIDI_MIDI_SPP                   (0xF2u)
#define USBMIDI_MIDI_SONGSEL               (0xF3u)
#define USBMIDI_MIDI_TUNEREQ               (0xF6u)
#define USBMIDI_MIDI_ACTIVESENSE           (0xFEu)

/* MIDI Universal System Exclusive defines */
#define USBMIDI_MIDI_SYSEX_NON_REAL_TIME   (0x7Eu)
#define USBMIDI_MIDI_SYSEX_REALTIME        (0x7Fu)

/* ID of target device */
#define USBMIDI_MIDI_SYSEX_ID_ALL          (0x7Fu)

/* Sub-ID#1*/
#define USBMIDI_MIDI_SYSEX_GEN_INFORMATION (0x06u)
#define USBMIDI_MIDI_SYSEX_GEN_MESSAGE     (0x09u)

/* Sub-ID#2*/
#define USBMIDI_MIDI_SYSEX_IDENTITY_REQ    (0x01u)
#define USBMIDI_MIDI_SYSEX_IDENTITY_REPLY  (0x02u)
#define USBMIDI_MIDI_SYSEX_SYSTEM_ON       (0x01u)
#define USBMIDI_MIDI_SYSEX_SYSTEM_OFF      (0x02u)

/* UART TX and RX interrupt priority. */
#if (CY_PSOC4)
    #define USBMIDI_CUSTOM_UART_RX_PRIOR_NUM   (0x01u)
    #define USBMIDI_CUSTOM_UART_TX_PRIOR_NUM   (0x02u)
#else
    #define USBMIDI_CUSTOM_UART_RX_PRIOR_NUM   (0x02u)
    #define USBMIDI_CUSTOM_UART_TX_PRIOR_NUM   (0x04u)
#endif /* (CYPSOC4) */


/***************************************
*    Private Function Prototypes
***************************************/

void USBMIDI_PrepareInBuffer(uint8 ic, const uint8 srcBuff[], uint8 eventLen, uint8 cable)
                                                                ;
#if (USBMIDI_MIDI_EXT_MODE >= USBMIDI_ONE_EXT_INTRF)
    void  USBMIDI_MIDI_InitInterface(void)             ;
    uint8 USBMIDI_ProcessMidiIn(uint8 mData, USBMIDI_MIDI_RX_STATUS *rxStat)
                                                                ;
    uint8 USBMIDI_MIDI1_GetEvent(void)                 ;
    void  USBMIDI_MIDI1_ProcessUsbOut(const uint8 epBuf[])
                                                                ;

    #if (USBMIDI_MIDI_EXT_MODE >= USBMIDI_TWO_EXT_INTRF)
        uint8 USBMIDI_MIDI2_GetEvent(void)             ;
        void  USBMIDI_MIDI2_ProcessUsbOut(const uint8 epBuf[])
                                                                ;
    #endif /* (USBMIDI_MIDI_EXT_MODE >= USBMIDI_TWO_EXT_INTRF) */
#endif /* (USBMIDI_MIDI_EXT_MODE >= USBMIDI_ONE_EXT_INTRF) */


/***************************************
*     Vars with External Linkage
***************************************/

#if defined(USBMIDI_ENABLE_MIDI_STREAMING)

#if (USBMIDI_MIDI_IN_BUFF_SIZE > 0)
    #if (USBMIDI_MIDI_IN_BUFF_SIZE >= 256)
/**
* \addtogroup group_midi
* @{
*/  
        extern volatile uint16 USBMIDI_midiInPointer;                       /* Input endpoint buffer pointer */
/** @} midi*/
    #else
        extern volatile uint8 USBMIDI_midiInPointer;                        /* Input endpoint buffer pointer */
    #endif /* (USBMIDI_MIDI_IN_BUFF_SIZE >=256) */
/**
* \addtogroup group_midi
* @{
*/  
    extern volatile uint8 USBMIDI_midi_in_ep;                               /* Input endpoint number */
    extern uint8 USBMIDI_midiInBuffer[USBMIDI_MIDI_IN_BUFF_SIZE];  /* Input endpoint buffer */
#endif /* (USBMIDI_MIDI_IN_BUFF_SIZE > 0) */

#if (USBMIDI_MIDI_OUT_BUFF_SIZE > 0)
    extern volatile uint8 USBMIDI_midi_out_ep;                               /* Output endpoint number */
    extern uint8 USBMIDI_midiOutBuffer[USBMIDI_MIDI_OUT_BUFF_SIZE]; /* Output endpoint buffer */
#endif /* (USBMIDI_MIDI_OUT_BUFF_SIZE > 0) */

#if (USBMIDI_MIDI_EXT_MODE >= USBMIDI_ONE_EXT_INTRF)
    extern volatile uint8 USBMIDI_MIDI1_InqFlags;                            /* Device inquiry flag */
    
    #if (USBMIDI_MIDI_EXT_MODE >= USBMIDI_TWO_EXT_INTRF)
        extern volatile uint8 USBMIDI_MIDI2_InqFlags;                        /* Device inquiry flag */
    #endif /* (USBMIDI_MIDI_EXT_MODE >= USBMIDI_TWO_EXT_INTRF) */
#endif /* (USBMIDI_MIDI_EXT_MODE >= USBMIDI_ONE_EXT_INTRF) */
/** @} midi */
#endif /* (USBMIDI_ENABLE_MIDI_STREAMING) */


/***************************************
* The following code is DEPRECATED and
* must not be used.
***************************************/

#define USBMIDI_MIDI_EP_Init           USBMIDI_MIDI_Init
#define USBMIDI_MIDI_OUT_EP_Service    USBMIDI_MIDI_OUT_Service

#endif /* (CY_USBFS_USBMIDI_midi_H) */


/* [] END OF FILE */
