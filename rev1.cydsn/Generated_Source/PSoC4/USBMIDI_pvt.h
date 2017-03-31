/***************************************************************************//**
* \file .h
* \version 3.10
*
* \brief
*  This file provides private function prototypes and constants for the 
*  USBFS component. It is not intended to be used in the user project.
*
********************************************************************************
* \copyright
* Copyright 2013-2016, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_USBFS_USBMIDI_pvt_H)
#define CY_USBFS_USBMIDI_pvt_H

#include "USBMIDI.h"
   
#ifdef USBMIDI_ENABLE_AUDIO_CLASS
    #include "USBMIDI_audio.h"
#endif /* USBMIDI_ENABLE_AUDIO_CLASS */

#ifdef USBMIDI_ENABLE_CDC_CLASS
    #include "USBMIDI_cdc.h"
#endif /* USBMIDI_ENABLE_CDC_CLASS */

#if (USBMIDI_ENABLE_MIDI_CLASS)
    #include "USBMIDI_midi.h"
#endif /* (USBMIDI_ENABLE_MIDI_CLASS) */

#if (USBMIDI_ENABLE_MSC_CLASS)
    #include "USBMIDI_msc.h"
#endif /* (USBMIDI_ENABLE_MSC_CLASS) */

#if (USBMIDI_EP_MANAGEMENT_DMA)
    #if (CY_PSOC4)
        #include <CyDMA.h>
    #else
        #include <CyDmac.h>
        #if ((USBMIDI_EP_MANAGEMENT_DMA_AUTO) && (USBMIDI_EP_DMA_AUTO_OPT == 0u))
            #include "USBMIDI_EP_DMA_Done_isr.h"
            #include "USBMIDI_EP8_DMA_Done_SR.h"
            #include "USBMIDI_EP17_DMA_Done_SR.h"
        #endif /* ((USBMIDI_EP_MANAGEMENT_DMA_AUTO) && (USBMIDI_EP_DMA_AUTO_OPT == 0u)) */
    #endif /* (CY_PSOC4) */
#endif /* (USBMIDI_EP_MANAGEMENT_DMA) */

#if (USBMIDI_DMA1_ACTIVE)
    #include "USBMIDI_ep1_dma.h"
    #define USBMIDI_EP1_DMA_CH     (USBMIDI_ep1_dma_CHANNEL)
#endif /* (USBMIDI_DMA1_ACTIVE) */

#if (USBMIDI_DMA2_ACTIVE)
    #include "USBMIDI_ep2_dma.h"
    #define USBMIDI_EP2_DMA_CH     (USBMIDI_ep2_dma_CHANNEL)
#endif /* (USBMIDI_DMA2_ACTIVE) */

#if (USBMIDI_DMA3_ACTIVE)
    #include "USBMIDI_ep3_dma.h"
    #define USBMIDI_EP3_DMA_CH     (USBMIDI_ep3_dma_CHANNEL)
#endif /* (USBMIDI_DMA3_ACTIVE) */

#if (USBMIDI_DMA4_ACTIVE)
    #include "USBMIDI_ep4_dma.h"
    #define USBMIDI_EP4_DMA_CH     (USBMIDI_ep4_dma_CHANNEL)
#endif /* (USBMIDI_DMA4_ACTIVE) */

#if (USBMIDI_DMA5_ACTIVE)
    #include "USBMIDI_ep5_dma.h"
    #define USBMIDI_EP5_DMA_CH     (USBMIDI_ep5_dma_CHANNEL)
#endif /* (USBMIDI_DMA5_ACTIVE) */

#if (USBMIDI_DMA6_ACTIVE)
    #include "USBMIDI_ep6_dma.h"
    #define USBMIDI_EP6_DMA_CH     (USBMIDI_ep6_dma_CHANNEL)
#endif /* (USBMIDI_DMA6_ACTIVE) */

#if (USBMIDI_DMA7_ACTIVE)
    #include "USBMIDI_ep7_dma.h"
    #define USBMIDI_EP7_DMA_CH     (USBMIDI_ep7_dma_CHANNEL)
#endif /* (USBMIDI_DMA7_ACTIVE) */

#if (USBMIDI_DMA8_ACTIVE)
    #include "USBMIDI_ep8_dma.h"
    #define USBMIDI_EP8_DMA_CH     (USBMIDI_ep8_dma_CHANNEL)
#endif /* (USBMIDI_DMA8_ACTIVE) */


/***************************************
*     Private Variables
***************************************/

/* Generated external references for descriptors. */
extern const uint8 CYCODE USBMIDI_DEVICE0_DESCR[18u];
extern const uint8 CYCODE USBMIDI_DEVICE0_CONFIGURATION0_DESCR[101u];
extern const T_USBMIDI_EP_SETTINGS_BLOCK CYCODE USBMIDI_DEVICE0_CONFIGURATION0_EP_SETTINGS_TABLE[2u];
extern const uint8 CYCODE USBMIDI_DEVICE0_CONFIGURATION0_INTERFACE_CLASS[2u];
extern const T_USBMIDI_LUT CYCODE USBMIDI_DEVICE0_CONFIGURATION0_TABLE[5u];
extern const T_USBMIDI_LUT CYCODE USBMIDI_DEVICE0_TABLE[3u];
extern const T_USBMIDI_LUT CYCODE USBMIDI_TABLE[1u];
extern const uint8 CYCODE USBMIDI_SN_STRING_DESCRIPTOR[2];
extern const uint8 CYCODE USBMIDI_STRING_DESCRIPTORS[177u];


extern const uint8 CYCODE USBMIDI_MSOS_DESCRIPTOR[USBMIDI_MSOS_DESCRIPTOR_LENGTH];
extern const uint8 CYCODE USBMIDI_MSOS_CONFIGURATION_DESCR[USBMIDI_MSOS_CONF_DESCR_LENGTH];
#if defined(USBMIDI_ENABLE_IDSN_STRING)
    extern uint8 USBMIDI_idSerialNumberStringDescriptor[USBMIDI_IDSN_DESCR_LENGTH];
#endif /* (USBMIDI_ENABLE_IDSN_STRING) */

extern volatile uint8 USBMIDI_interfaceNumber;
extern volatile uint8 USBMIDI_interfaceSetting[USBMIDI_MAX_INTERFACES_NUMBER];
extern volatile uint8 USBMIDI_interfaceSettingLast[USBMIDI_MAX_INTERFACES_NUMBER];
extern volatile uint8 USBMIDI_deviceAddress;
extern volatile uint8 USBMIDI_interfaceStatus[USBMIDI_MAX_INTERFACES_NUMBER];
extern const uint8 CYCODE *USBMIDI_interfaceClass;

extern volatile T_USBMIDI_EP_CTL_BLOCK USBMIDI_EP[USBMIDI_MAX_EP];
extern volatile T_USBMIDI_TD USBMIDI_currentTD;

#if (USBMIDI_EP_MANAGEMENT_DMA)
    #if (CY_PSOC4)
        extern const uint8 USBMIDI_DmaChan[USBMIDI_MAX_EP];
    #else
        extern uint8 USBMIDI_DmaChan[USBMIDI_MAX_EP];
        extern uint8 USBMIDI_DmaTd  [USBMIDI_MAX_EP];
    #endif /* (CY_PSOC4) */
#endif /* (USBMIDI_EP_MANAGEMENT_DMA) */

#if (USBMIDI_EP_MANAGEMENT_DMA_AUTO)
#if (CY_PSOC4)
    extern uint8  USBMIDI_DmaEpBurstCnt   [USBMIDI_MAX_EP];
    extern uint8  USBMIDI_DmaEpLastBurstEl[USBMIDI_MAX_EP];

    extern uint8  USBMIDI_DmaEpBurstCntBackup  [USBMIDI_MAX_EP];
    extern uint32 USBMIDI_DmaEpBufferAddrBackup[USBMIDI_MAX_EP];
    
    extern const uint8 USBMIDI_DmaReqOut     [USBMIDI_MAX_EP];    
    extern const uint8 USBMIDI_DmaBurstEndOut[USBMIDI_MAX_EP];
#else
    #if (USBMIDI_EP_DMA_AUTO_OPT == 0u)
        extern uint8 USBMIDI_DmaNextTd[USBMIDI_MAX_EP];
        extern volatile uint16 USBMIDI_inLength [USBMIDI_MAX_EP];
        extern volatile uint8  USBMIDI_inBufFull[USBMIDI_MAX_EP];
        extern const uint8 USBMIDI_epX_TD_TERMOUT_EN[USBMIDI_MAX_EP];
        extern const uint8 *USBMIDI_inDataPointer[USBMIDI_MAX_EP];
    #endif /* (USBMIDI_EP_DMA_AUTO_OPT == 0u) */
#endif /* CY_PSOC4 */
#endif /* (USBMIDI_EP_MANAGEMENT_DMA_AUTO) */

extern volatile uint8 USBMIDI_ep0Toggle;
extern volatile uint8 USBMIDI_lastPacketSize;
extern volatile uint8 USBMIDI_ep0Mode;
extern volatile uint8 USBMIDI_ep0Count;
extern volatile uint16 USBMIDI_transferByteCount;


/***************************************
*     Private Function Prototypes
***************************************/
void  USBMIDI_ReInitComponent(void)            ;
void  USBMIDI_HandleSetup(void)                ;
void  USBMIDI_HandleIN(void)                   ;
void  USBMIDI_HandleOUT(void)                  ;
void  USBMIDI_LoadEP0(void)                    ;
uint8 USBMIDI_InitControlRead(void)            ;
uint8 USBMIDI_InitControlWrite(void)           ;
void  USBMIDI_ControlReadDataStage(void)       ;
void  USBMIDI_ControlReadStatusStage(void)     ;
void  USBMIDI_ControlReadPrematureStatus(void) ;
uint8 USBMIDI_InitControlWrite(void)           ;
uint8 USBMIDI_InitZeroLengthControlTransfer(void) ;
void  USBMIDI_ControlWriteDataStage(void)      ;
void  USBMIDI_ControlWriteStatusStage(void)    ;
void  USBMIDI_ControlWritePrematureStatus(void);
uint8 USBMIDI_InitNoDataControlTransfer(void)  ;
void  USBMIDI_NoDataControlStatusStage(void)   ;
void  USBMIDI_InitializeStatusBlock(void)      ;
void  USBMIDI_UpdateStatusBlock(uint8 completionCode) ;
uint8 USBMIDI_DispatchClassRqst(void)          ;

void USBMIDI_Config(uint8 clearAltSetting) ;
void USBMIDI_ConfigAltChanged(void)        ;
void USBMIDI_ConfigReg(void)               ;
void USBMIDI_EpStateInit(void)             ;


const T_USBMIDI_LUT CYCODE *USBMIDI_GetConfigTablePtr(uint8 confIndex);
const T_USBMIDI_LUT CYCODE *USBMIDI_GetDeviceTablePtr(void)           ;
#if (USBMIDI_BOS_ENABLE)
    const T_USBMIDI_LUT CYCODE *USBMIDI_GetBOSPtr(void)               ;
#endif /* (USBMIDI_BOS_ENABLE) */
const uint8 CYCODE *USBMIDI_GetInterfaceClassTablePtr(void)                    ;uint8 USBMIDI_ClearEndpointHalt(void)                                          ;
uint8 USBMIDI_SetEndpointHalt(void)                                            ;
uint8 USBMIDI_ValidateAlternateSetting(void)                                   ;

void USBMIDI_SaveConfig(void)      ;
void USBMIDI_RestoreConfig(void)   ;

#if (CY_PSOC3 || CY_PSOC5LP)
    #if (USBMIDI_EP_MANAGEMENT_DMA_AUTO && (USBMIDI_EP_DMA_AUTO_OPT == 0u))
        void USBMIDI_LoadNextInEP(uint8 epNumber, uint8 mode)  ;
    #endif /* (USBMIDI_EP_MANAGEMENT_DMA_AUTO && (USBMIDI_EP_DMA_AUTO_OPT == 0u)) */
#endif /* (CY_PSOC3 || CY_PSOC5LP) */

#if defined(USBMIDI_ENABLE_IDSN_STRING)
    void USBMIDI_ReadDieID(uint8 descr[])  ;
#endif /* USBMIDI_ENABLE_IDSN_STRING */

#if defined(USBMIDI_ENABLE_HID_CLASS)
    uint8 USBMIDI_DispatchHIDClassRqst(void) ;
#endif /* (USBMIDI_ENABLE_HID_CLASS) */

#if defined(USBMIDI_ENABLE_AUDIO_CLASS)
    uint8 USBMIDI_DispatchAUDIOClassRqst(void) ;
#endif /* (USBMIDI_ENABLE_AUDIO_CLASS) */

#if defined(USBMIDI_ENABLE_CDC_CLASS)
    uint8 USBMIDI_DispatchCDCClassRqst(void) ;
#endif /* (USBMIDI_ENABLE_CDC_CLASS) */

#if (USBMIDI_ENABLE_MSC_CLASS)
    #if (USBMIDI_HANDLE_MSC_REQUESTS)
        uint8 USBMIDI_DispatchMSCClassRqst(void) ;
    #endif /* (USBMIDI_HANDLE_MSC_REQUESTS) */
#endif /* (USBMIDI_ENABLE_MSC_CLASS */

CY_ISR_PROTO(USBMIDI_EP_0_ISR);
CY_ISR_PROTO(USBMIDI_BUS_RESET_ISR);

#if (USBMIDI_SOF_ISR_ACTIVE)
    CY_ISR_PROTO(USBMIDI_SOF_ISR);
#endif /* (USBMIDI_SOF_ISR_ACTIVE) */

#if (USBMIDI_EP1_ISR_ACTIVE)
    CY_ISR_PROTO(USBMIDI_EP_1_ISR);
#endif /* (USBMIDI_EP1_ISR_ACTIVE) */

#if (USBMIDI_EP2_ISR_ACTIVE)
    CY_ISR_PROTO(USBMIDI_EP_2_ISR);
#endif /* (USBMIDI_EP2_ISR_ACTIVE) */

#if (USBMIDI_EP3_ISR_ACTIVE)
    CY_ISR_PROTO(USBMIDI_EP_3_ISR);
#endif /* (USBMIDI_EP3_ISR_ACTIVE) */

#if (USBMIDI_EP4_ISR_ACTIVE)
    CY_ISR_PROTO(USBMIDI_EP_4_ISR);
#endif /* (USBMIDI_EP4_ISR_ACTIVE) */

#if (USBMIDI_EP5_ISR_ACTIVE)
    CY_ISR_PROTO(USBMIDI_EP_5_ISR);
#endif /* (USBMIDI_EP5_ISR_ACTIVE) */

#if (USBMIDI_EP6_ISR_ACTIVE)
    CY_ISR_PROTO(USBMIDI_EP_6_ISR);
#endif /* (USBMIDI_EP6_ISR_ACTIVE) */

#if (USBMIDI_EP7_ISR_ACTIVE)
    CY_ISR_PROTO(USBMIDI_EP_7_ISR);
#endif /* (USBMIDI_EP7_ISR_ACTIVE) */

#if (USBMIDI_EP8_ISR_ACTIVE)
    CY_ISR_PROTO(USBMIDI_EP_8_ISR);
#endif /* (USBMIDI_EP8_ISR_ACTIVE) */

#if (USBMIDI_EP_MANAGEMENT_DMA)
    CY_ISR_PROTO(USBMIDI_ARB_ISR);
#endif /* (USBMIDI_EP_MANAGEMENT_DMA) */

#if (USBMIDI_DP_ISR_ACTIVE)
    CY_ISR_PROTO(USBMIDI_DP_ISR);
#endif /* (USBMIDI_DP_ISR_ACTIVE) */

#if (CY_PSOC4)
    CY_ISR_PROTO(USBMIDI_INTR_HI_ISR);
    CY_ISR_PROTO(USBMIDI_INTR_MED_ISR);
    CY_ISR_PROTO(USBMIDI_INTR_LO_ISR);
    #if (USBMIDI_LPM_ACTIVE)
        CY_ISR_PROTO(USBMIDI_LPM_ISR);
    #endif /* (USBMIDI_LPM_ACTIVE) */
#endif /* (CY_PSOC4) */

#if (USBMIDI_EP_MANAGEMENT_DMA_AUTO)
#if (CY_PSOC4)
    #if (USBMIDI_DMA1_ACTIVE)
        void USBMIDI_EP1_DMA_DONE_ISR(void);
    #endif /* (USBMIDI_DMA1_ACTIVE) */

    #if (USBMIDI_DMA2_ACTIVE)
        void USBMIDI_EP2_DMA_DONE_ISR(void);
    #endif /* (USBMIDI_DMA2_ACTIVE) */

    #if (USBMIDI_DMA3_ACTIVE)
        void USBMIDI_EP3_DMA_DONE_ISR(void);
    #endif /* (USBMIDI_DMA3_ACTIVE) */

    #if (USBMIDI_DMA4_ACTIVE)
        void USBMIDI_EP4_DMA_DONE_ISR(void);
    #endif /* (USBMIDI_DMA4_ACTIVE) */

    #if (USBMIDI_DMA5_ACTIVE)
        void USBMIDI_EP5_DMA_DONE_ISR(void);
    #endif /* (USBMIDI_DMA5_ACTIVE) */

    #if (USBMIDI_DMA6_ACTIVE)
        void USBMIDI_EP6_DMA_DONE_ISR(void);
    #endif /* (USBMIDI_DMA6_ACTIVE) */

    #if (USBMIDI_DMA7_ACTIVE)
        void USBMIDI_EP7_DMA_DONE_ISR(void);
    #endif /* (USBMIDI_DMA7_ACTIVE) */

    #if (USBMIDI_DMA8_ACTIVE)
        void USBMIDI_EP8_DMA_DONE_ISR(void);
    #endif /* (USBMIDI_DMA8_ACTIVE) */

#else
    #if (USBMIDI_EP_DMA_AUTO_OPT == 0u)
        CY_ISR_PROTO(USBMIDI_EP_DMA_DONE_ISR);
    #endif /* (USBMIDI_EP_DMA_AUTO_OPT == 0u) */
#endif /* (CY_PSOC4) */
#endif /* (USBMIDI_EP_MANAGEMENT_DMA_AUTO) */


/***************************************
*         Request Handlers
***************************************/

uint8 USBMIDI_HandleStandardRqst(void) ;
uint8 USBMIDI_DispatchClassRqst(void)  ;
uint8 USBMIDI_HandleVendorRqst(void)   ;


/***************************************
*    HID Internal references
***************************************/

#if defined(USBMIDI_ENABLE_HID_CLASS)
    void USBMIDI_FindReport(void)            ;
    void USBMIDI_FindReportDescriptor(void)  ;
    void USBMIDI_FindHidClassDecriptor(void) ;
#endif /* USBMIDI_ENABLE_HID_CLASS */


/***************************************
*    MIDI Internal references
***************************************/

#if defined(USBMIDI_ENABLE_MIDI_STREAMING)
    void USBMIDI_MIDI_IN_EP_Service(void)  ;
#endif /* (USBMIDI_ENABLE_MIDI_STREAMING) */


/***************************************
*    CDC Internal references
***************************************/

#if defined(USBMIDI_ENABLE_CDC_CLASS)

    typedef struct
    {
        uint8  bRequestType;
        uint8  bNotification;
        uint8  wValue;
        uint8  wValueMSB;
        uint8  wIndex;
        uint8  wIndexMSB;
        uint8  wLength;
        uint8  wLengthMSB;
        uint8  wSerialState;
        uint8  wSerialStateMSB;
    } t_USBMIDI_cdc_notification;

    uint8 USBMIDI_GetInterfaceComPort(uint8 interface) ;
    uint8 USBMIDI_Cdc_EpInit( const T_USBMIDI_EP_SETTINGS_BLOCK CYCODE *pEP, uint8 epNum, uint8 cdcComNums) ;

    extern volatile uint8  USBMIDI_cdc_dataInEpList[USBMIDI_MAX_MULTI_COM_NUM];
    extern volatile uint8  USBMIDI_cdc_dataOutEpList[USBMIDI_MAX_MULTI_COM_NUM];
    extern volatile uint8  USBMIDI_cdc_commInEpList[USBMIDI_MAX_MULTI_COM_NUM];
#endif /* (USBMIDI_ENABLE_CDC_CLASS) */


#endif /* CY_USBFS_USBMIDI_pvt_H */


/* [] END OF FILE */
