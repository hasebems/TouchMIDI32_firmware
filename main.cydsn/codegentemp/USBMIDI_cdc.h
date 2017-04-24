/***************************************************************************//**
* \file USBMIDI_cdc.h
* \version 3.10
*
* \brief
*  This file provides function prototypes and constants for the USBFS component 
*  CDC class.
*
* Related Document:
*  Universal Serial Bus Class Definitions for Communication Devices Version 1.1
*
********************************************************************************
* \copyright
* Copyright 2012-2016, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_USBFS_USBMIDI_cdc_H)
#define CY_USBFS_USBMIDI_cdc_H

#include "USBMIDI.h"


/*******************************************************************************
* Prototypes of the USBMIDI_cdc API.
*******************************************************************************/
/**
* \addtogroup group_cdc
* @{
*/
#if (USBMIDI_ENABLE_CDC_CLASS_API != 0u)
    uint8 USBMIDI_CDC_Init(void)            ;
    void USBMIDI_PutData(const uint8* pData, uint16 length) ;
    void USBMIDI_PutString(const char8 string[])            ;
    void USBMIDI_PutChar(char8 txDataByte) ;
    void USBMIDI_PutCRLF(void)             ;
    uint16 USBMIDI_GetCount(void)          ;
    uint8  USBMIDI_CDCIsReady(void)        ;
    uint8  USBMIDI_DataIsReady(void)       ;
    uint16 USBMIDI_GetData(uint8* pData, uint16 length)     ;
    uint16 USBMIDI_GetAll(uint8* pData)    ;
    uint8  USBMIDI_GetChar(void)           ;
    uint8  USBMIDI_IsLineChanged(void)     ;
    uint32 USBMIDI_GetDTERate(void)        ;
    uint8  USBMIDI_GetCharFormat(void)     ;
    uint8  USBMIDI_GetParityType(void)     ;
    uint8  USBMIDI_GetDataBits(void)       ;
    uint16 USBMIDI_GetLineControl(void)    ;
    void USBMIDI_SendSerialState (uint16 serialState) ;
    uint16 USBMIDI_GetSerialState (void)   ;
    void USBMIDI_SetComPort (uint8 comNumber) ;
    uint8 USBMIDI_GetComPort (void)        ;
    uint8 USBMIDI_NotificationIsReady(void) ;

#endif  /* (USBMIDI_ENABLE_CDC_CLASS_API) */
/** @} cdc */

/*******************************************************************************
*  Constants for USBMIDI_cdc API.
*******************************************************************************/

/* CDC Class-Specific Request Codes (CDC ver 1.2 Table 19) */
#define USBMIDI_CDC_SET_LINE_CODING        (0x20u)
#define USBMIDI_CDC_GET_LINE_CODING        (0x21u)
#define USBMIDI_CDC_SET_CONTROL_LINE_STATE (0x22u)

/*PSTN Subclass Specific Notifications (CDC ver 1.2 Table 30)*/
#define USBMIDI_SERIAL_STATE               (0x20u)

#define USBMIDI_LINE_CODING_CHANGED        (0x01u)
#define USBMIDI_LINE_CONTROL_CHANGED       (0x02u)

#define USBMIDI_1_STOPBIT                  (0x00u)
#define USBMIDI_1_5_STOPBITS               (0x01u)
#define USBMIDI_2_STOPBITS                 (0x02u)

#define USBMIDI_PARITY_NONE                (0x00u)
#define USBMIDI_PARITY_ODD                 (0x01u)
#define USBMIDI_PARITY_EVEN                (0x02u)
#define USBMIDI_PARITY_MARK                (0x03u)
#define USBMIDI_PARITY_SPACE               (0x04u)

#define USBMIDI_LINE_CODING_SIZE           (0x07u)
#define USBMIDI_LINE_CODING_RATE           (0x00u)
#define USBMIDI_LINE_CODING_STOP_BITS      (0x04u)
#define USBMIDI_LINE_CODING_PARITY         (0x05u)
#define USBMIDI_LINE_CODING_DATA_BITS      (0x06u)

#define USBMIDI_LINE_CONTROL_DTR           (0x01u)
#define USBMIDI_LINE_CONTROL_RTS           (0x02u)

#define USBMIDI_MAX_MULTI_COM_NUM          (2u) 

#define USBMIDI_COM_PORT1                  (0u) 
#define USBMIDI_COM_PORT2                  (1u) 

#define USBMIDI_SUCCESS                    (0u)
#define USBMIDI_FAILURE                    (1u)

#define USBMIDI_SERIAL_STATE_SIZE          (10u)

/* SerialState constants*/
#define USBMIDI_SERIAL_STATE_REQUEST_TYPE  (0xA1u)
#define USBMIDI_SERIAL_STATE_LENGTH        (0x2u)

/*******************************************************************************
* External data references
*******************************************************************************/
/**
* \addtogroup group_cdc
* @{
*/
extern volatile uint8  USBMIDI_linesCoding[USBMIDI_MAX_MULTI_COM_NUM][USBMIDI_LINE_CODING_SIZE];
extern volatile uint8  USBMIDI_linesChanged[USBMIDI_MAX_MULTI_COM_NUM];
extern volatile uint16 USBMIDI_linesControlBitmap[USBMIDI_MAX_MULTI_COM_NUM];
extern volatile uint16 USBMIDI_serialStateBitmap[USBMIDI_MAX_MULTI_COM_NUM];
extern volatile uint8  USBMIDI_cdcDataInEp[USBMIDI_MAX_MULTI_COM_NUM];
extern volatile uint8  USBMIDI_cdcDataOutEp[USBMIDI_MAX_MULTI_COM_NUM];
extern volatile uint8  USBMIDI_cdcCommInInterruptEp[USBMIDI_MAX_MULTI_COM_NUM];
/** @} cdc */

/*******************************************************************************
* The following code is DEPRECATED and
* must not be used.
*******************************************************************************/


#define USBMIDI_lineCoding             USBMIDI_linesCoding[0]
#define USBMIDI_lineChanged            USBMIDI_linesChanged[0]
#define USBMIDI_lineControlBitmap      USBMIDI_linesControlBitmap[0]
#define USBMIDI_cdc_data_in_ep         USBMIDI_cdcDataInEp[0]
#define USBMIDI_cdc_data_out_ep        USBMIDI_cdcDataOutEp[0]

#endif /* (CY_USBFS_USBMIDI_cdc_H) */


/* [] END OF FILE */
