/***************************************************************************//**
* \file CapSense_1_Sensing.c
* \version 3.10
*
* \brief
*   This file contains the source of functions common for
*   different sensing methods.
*
* \see CapSense P4 v3.10 Datasheet
*
*//*****************************************************************************
* Copyright (2016), Cypress Semiconductor Corporation.
********************************************************************************
* This software is owned by Cypress Semiconductor Corporation (Cypress) and is
* protected by and subject to worldwide patent protection (United States and
* foreign), United States copyright laws and international treaty provisions.
* Cypress hereby grants to licensee a personal, non-exclusive, non-transferable
* license to copy, use, modify, create derivative works of, and compile the
* Cypress Source Code and derivative works for the sole purpose of creating
* custom software in support of licensee product to be used only in conjunction
* with a Cypress integrated circuit as specified in the applicable agreement.
* Any reproduction, modification, translation, compilation, or representation of
* this software except as specified above is prohibited without the express
* written permission of Cypress.
*
* Disclaimer: CYPRESS MAKES NO WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, WITH
* REGARD TO THIS MATERIAL, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* Cypress reserves the right to make changes without further notice to the
* materials described herein. Cypress does not assume any liability arising out
* of the application or use of any product or circuit described herein. Cypress
* does not authorize its products for use as critical components in life-support
* systems where a malfunction or failure may reasonably be expected to result in
* significant injury to the user. The inclusion of Cypress' product in a life-
* support systems application implies that the manufacturer assumes all risk of
* such use and in doing so indemnifies Cypress against all charges. Use may be
* limited by and subject to the applicable Cypress software license agreement.
*******************************************************************************/

#include "cyfitter.h"
#include "CapSense_1_Structure.h"
#include "CapSense_1_Configuration.h"
#include "CapSense_1_Sensing.h"
#if (CapSense_1_ENABLE == CapSense_1_SELF_TEST_EN)
    #include "CapSense_1_SelfTest.h"
#endif

/***************************************
* API Constants
***************************************/

#define CapSense_1_WIDGET_NUM_32                          (32u)
#define CapSense_1_WIDGET_NUM_32_DIV_SHIFT                (5u)
#define CapSense_1_WIDGET_NUM_32_MASK                     (0x0000001FLu)
#define CapSense_1_CALIBRATION_RESOLUTION                 (12u)
#define CapSense_1_COARSE_TRIM_THRESHOLD_1                (40u)
#define CapSense_1_COARSE_TRIM_THRESHOLD_2                (215u)
#define CapSense_1_FREQUENCY_OFFSET_5                     (20u)
#define CapSense_1_FREQUENCY_OFFSET_10                    (40u)
#define CapSense_1_CALIBRATION_FREQ_KHZ                   (1500u)
#define CapSense_1_CALIBRATION_MD                         (2u)
#define CapSense_1_MIN_IMO_FREQ_KHZ                       (6000u)
#define CapSense_1_CSD_AUTOTUNE_CAL_LEVEL                 (CapSense_1_CSD_RAWCOUNT_CAL_LEVEL)
#define CapSense_1_CP_MIN                                 (0u)
#define CapSense_1_CP_MAX                                 (65000Lu)
#define CapSense_1_CP_ERROR                               (4000Lu)
#if (CapSense_1_ENABLE == CapSense_1_CSD2X_EN)
    #define CapSense_1_TOTAL_SLOTS                        (CapSense_1_TOTAL_SCAN_SLOTS)
#else
    #define CapSense_1_TOTAL_SLOTS                        (CapSense_1_TOTAL_WIDGETS)
#endif /* (CapSense_1_ENABLE == CapSense_1_CSD2X_EN) */

#define CapSense_1_CLK_SOURCE_LFSR_SCALE_OFFSET           (4u)

#if (CapSense_1_CLK_SOURCE_DIRECT != CapSense_1_CSD_SNS_CLK_SOURCE)
    #if (CapSense_1_ENABLE == CapSense_1_CSDV2)
        #define CapSense_1_PRS_FACTOR_DIV                 (2u)
    #else
        #define CapSense_1_PRS_FACTOR_DIV                 (1u)
    #endif /* (CapSense_1_ENABLE == CapSense_1_CSDV2) */
#else
    #define CapSense_1_PRS_FACTOR_DIV                     (0u)
#endif /* (CapSense_1_CLK_SOURCE_DIRECT != CapSense_1_CSD_SNS_CLK_SOURCE) */

#define CapSense_1_FLIP_FLOP_DIV                          (1u)

#define CapSense_1_MOD_CSD_CLK_12000KHZ                   (12000uL)
#define CapSense_1_MOD_CSD_CLK_24000KHZ                   (24000uL)
#define CapSense_1_MOD_CSD_CLK_48000KHZ                   (48000uL)

#if ((CapSense_1_CLK_SOURCE_PRS8 == CapSense_1_CSD_SNS_CLK_SOURCE) || \
    (CapSense_1_CLK_SOURCE_PRS12 == CapSense_1_CSD_SNS_CLK_SOURCE) || \
    (CapSense_1_CLK_SOURCE_PRSAUTO == CapSense_1_CSD_SNS_CLK_SOURCE))
    #define CapSense_1_FACTOR_FILTER_DELAY_12MHZ          (2u)
#else
    #define CapSense_1_FACTOR_FILTER_DELAY_12MHZ          (4u)
#endif /* (CapSense_1_CLK_SOURCE_DIRECT != CapSense_1_CSD_SNS_CLK_SOURCE) */

#define CapSense_1_FACTOR_MOD_SNS                         (8u)
#define CapSense_1_UINT8_MAX_VAL                          (0xFFu)
#define CapSense_1_MSB_OFFSET                             (8u)

/*****************************************************************************/
/* Enumeration types definition                                               */
/*****************************************************************************/

typedef enum
{
    CapSense_1_RES_PULLUP_E   = 0x02u,
    CapSense_1_RES_PULLDOWN_E = 0x03u
} CapSense_1_PORT_TEST_DM;

typedef enum
{
    CapSense_1_STS_RESET      = 0x01u,
    CapSense_1_STS_NO_RESET   = 0x02u
} CapSense_1_TEST_TYPE;


/*******************************************************************************
* Static Function Prototypes
*******************************************************************************/
/**
* \if SECTION_CAPSENSE_INTERNAL
* \addtogroup group_capsense_internal
* \{
*/

#if (CapSense_1_DISABLE == CapSense_1_CSDV2)
    static void CapSense_1_SsTrimIdacs(void);
    #if ((CapSense_1_ENABLE == CapSense_1_CSX_EN) || \
         (CapSense_1_IDAC_SINKING == CapSense_1_CSD_IDAC_CONFIG))
        static void CapSense_1_SsTrimIdacsSinking(void);
    #endif /* ((CapSense_1_ENABLE == CapSense_1_CSX_EN) || \
               (CapSense_1_IDAC_SINKING == CapSense_1_CSD_IDAC_CONFIG)) */
    #if ((CapSense_1_ENABLE == CapSense_1_CSX_EN) || \
         (CapSense_1_IDAC_SOURCING == CapSense_1_CSD_IDAC_CONFIG))
        static void CapSense_1_SsTrimIdacsSourcing(void);
    #endif /* ((CapSense_1_ENABLE == CapSense_1_CSX_EN) || \
               (CapSense_1_IDAC_SOURCING == CapSense_1_CSD_IDAC_CONFIG)) */
#endif /* (CapSense_1_ENABLE == CapSense_1_CSDV2) */
#if ((CapSense_1_ENABLE == CapSense_1_CSD_CSX_EN) || \
     (CapSense_1_ENABLE == CapSense_1_SELF_TEST_EN) || \
     (CapSense_1_ENABLE == CapSense_1_ADC_EN))
    #if (CapSense_1_ENABLE == CapSense_1_CSD_EN)
        static void CapSense_1_SsCSDDisableMode(void);
    #endif /* (CapSense_1_ENABLE == CapSense_1_CSD_EN) */
    #if (CapSense_1_ENABLE == CapSense_1_CSX_EN)
        static void CapSense_1_SsDisableCSXMode(void);
    #endif /* (CapSense_1_ENABLE == CapSense_1_CSX_EN) */
#endif /* ((CapSense_1_ENABLE == CapSense_1_CSD_CSX_EN) || \
           (CapSense_1_ENABLE == CapSense_1_SELF_TEST_EN) || \
           (CapSense_1_ENABLE == CapSense_1_ADC_EN)) */
#if (CapSense_1_CSD_SS_DIS != CapSense_1_CSD_AUTOTUNE)
    #if (CapSense_1_ENABLE == CapSense_1_CSD2X_EN)
        static void CapSense_1_SsSetCSD0DirectClockMode(void);
        static void CapSense_1_SsSetCSD1DirectClockMode(void);
    #else
        static void CapSense_1_SsSetDirectClockMode(void);
    #endif /* (CapSense_1_ENABLE == CapSense_1_CSD2X_EN) */
#endif /* (CapSense_1_CSD_SS_DIS != CapSense_1_CSD_AUTOTUNE) */

#if(((CapSense_1_ENABLE == CapSense_1_CSX_EN) && \
     (CapSense_1_ENABLE == CapSense_1_CSDV2) && \
     (CapSense_1_CLK_SOURCE_PRSAUTO == CapSense_1_CSX_TX_CLK_SOURCE)) ||\
    ((CapSense_1_ENABLE == CapSense_1_CSD_EN) && \
     (CapSense_1_ENABLE == CapSense_1_CSDV2) && \
     (CapSense_1_CLK_SOURCE_PRSAUTO == CapSense_1_CSD_SNS_CLK_SOURCE)))
    static CY_INLINE uint8 CapSense_1_SsCalcLfsrSize(uint32 snsClkDivider, uint32 conversionsNum);
    static CY_INLINE uint8 CapSense_1_SsCalcLfsrScale(uint32 snsClkDivider, uint8 lfsrSize);
#endif /* (((CapSense_1_ENABLE == CapSense_1_CSX_EN) && \
            (CapSense_1_ENABLE == CapSense_1_CSDV2) && \
            (CapSense_1_CLK_SOURCE_PRSAUTO == CapSense_1_CSX_TX_CLK_SOURCE)) ||\
           ((CapSense_1_ENABLE == CapSense_1_CSD_EN) && \
            (CapSense_1_ENABLE == CapSense_1_CSDV2) && \
            (CapSense_1_CLK_SOURCE_PRSAUTO == CapSense_1_CSD_SNS_CLK_SOURCE))) */
#if ((CapSense_1_CSD_SS_DIS != CapSense_1_CSD_AUTOTUNE) && \
    (CapSense_1_ENABLE == CapSense_1_CSD2X_EN))
    static void CapSense_1_SsSetEqualSlotClock(void);
#endif /* ((CapSense_1_CSD_SS_DIS != CapSense_1_CSD_AUTOTUNE) \
           (CapSense_1_ENABLE == CapSense_1_CSD2X_EN)) */
#if ((CapSense_1_ENABLE == CapSense_1_CSD_EN) || (CapSense_1_ENABLE == CapSense_1_CSD2X_EN))
    static void CapSense_1_SsSetWidgetSenseClkSrc(uint32 wdgtIndex, CapSense_1_RAM_WD_BASE_STRUCT * ptrWdgt);
#endif /* ((CapSense_1_ENABLE == CapSense_1_CSD_EN) || (CapSense_1_ENABLE == CapSense_1_CSD2X_EN)) */

#if ((CapSense_1_ENABLE == CapSense_1_CSX_EN) && (CapSense_1_ENABLE == CapSense_1_CSDV2))
    static void CapSense_1_SsSetWidgetTxClkSrc(uint32 wdgtIndex, CapSense_1_RAM_WD_BASE_STRUCT * ptrWdgt);
#endif /* ((CapSense_1_ENABLE == CapSense_1_CSX_EN) && (CapSense_1_ENABLE == CapSense_1_CSDV2)) */

/** \}
* \endif */

/*******************************************************************************
* Define module variables
*******************************************************************************/

#if ((CapSense_1_ENABLE == CapSense_1_CSD_CSX_EN) || \
     (CapSense_1_ENABLE == CapSense_1_SELF_TEST_EN) || \
     (CapSense_1_ENABLE == CapSense_1_ADC_EN))
    CapSense_1_SENSE_METHOD_ENUM CapSense_1_currentSenseMethod = CapSense_1_UNDEFINED_E;
#endif /* ((CapSense_1_ENABLE == CapSense_1_CSD_CSX_EN) || \
           (CapSense_1_ENABLE == CapSense_1_SELF_TEST_EN) || \
           (CapSense_1_ENABLE == CapSense_1_ADC_EN))) */

#if(CapSense_1_ENABLE == CapSense_1_MULTI_FREQ_SCAN_EN)
    /*  Module variable keep track of frequency hopping channel index   */
    uint8 CapSense_1_scanFreqIndex = 0u;
    /*  Variable keep frequency offsets */
    uint8 CapSense_1_immunity[CapSense_1_NUM_SCAN_FREQS] = {0u, 0u, 0u};
#else
    /* const allows C-compiler to do optimization */
    const uint8 CapSense_1_scanFreqIndex = 0u;
#endif /* (CapSense_1_ENABLE == CapSense_1_MULTI_FREQ_SCAN_EN) */

/* Global software variables */
#if (CapSense_1_ENABLE == CapSense_1_CSD2X_EN)
    volatile uint8 CapSense_1_widgetIndex0 = 0u;    /* Index of the scanning widget0 */
    volatile uint8 CapSense_1_sensorIndex0 = 0u;    /* Index of the scanning sensor0 */
    volatile uint8 CapSense_1_widgetIndex1 = 0u;    /* Index of the scanning widget1 */
    volatile uint8 CapSense_1_sensorIndex1 = 0u;    /* Index of the scanning sensor1 */
#else
    volatile uint8 CapSense_1_widgetIndex = 0u;    /* Index of the scanning widget */
    volatile uint8 CapSense_1_sensorIndex = 0u;    /* Index of the scanning sensor */
#endif /* (CapSense_1_ENABLE == CapSense_1_CSD2X_EN) */
uint8 CapSense_1_requestScanAllWidget = 0u;
#if (CapSense_1_CSD_SS_DIS != CapSense_1_CSD_AUTOTUNE)
    uint8 CapSense_1_prescalersTuningDone = 0u;
#endif /* (CapSense_1_CSD_SS_DIS != CapSense_1_CSD_AUTOTUNE) */

/* Pointer to RAM_SNS_STRUCT structure  */
#if (CapSense_1_ENABLE == CapSense_1_CSD2X_EN)
    CapSense_1_RAM_SNS_STRUCT *CapSense_1_curRamSnsPtr0;
    CapSense_1_RAM_SNS_STRUCT *CapSense_1_curRamSnsPtr1;
#else
    CapSense_1_RAM_SNS_STRUCT *CapSense_1_curRamSnsPtr;
#endif /* (CapSense_1_ENABLE == CapSense_1_CSD2X_EN) */

#if ((CapSense_1_ENABLE == CapSense_1_CSD_GANGED_SNS_EN) || \
     (CapSense_1_ENABLE == CapSense_1_CSX_EN))
    /*  Pointer to Flash structure holding configuration of widget to be scanned  */
    #if (CapSense_1_ENABLE == CapSense_1_CSD2X_EN)
         CapSense_1_FLASH_WD_STRUCT const *CapSense_1_curFlashWdgtPtr0 = 0u;
         CapSense_1_FLASH_WD_STRUCT const *CapSense_1_curFlashWdgtPtr1 = 0u;
    #else
         CapSense_1_FLASH_WD_STRUCT const *CapSense_1_curFlashWdgtPtr = 0u;
    #endif /* (CapSense_1_ENABLE == CapSense_1_CSD2X_EN) */
#endif /* ((CapSense_1_ENABLE == CapSense_1_CSD_GANGED_SNS_EN) || \
           (CapSense_1_ENABLE == CapSense_1_CSX_EN))  */
#if (CapSense_1_ENABLE == CapSense_1_CSD_GANGED_SNS_EN)
    /*  Pointer to Flash structure holding info of sensor to be scanned  */
    #if (CapSense_1_ENABLE == CapSense_1_CSD2X_EN)
        CapSense_1_FLASH_SNS_STRUCT const *CapSense_1_curFlashSnsPtr0 = 0u;
        CapSense_1_FLASH_SNS_STRUCT const *CapSense_1_curFlashSnsPtr1 = 0u;
    #else
        CapSense_1_FLASH_SNS_STRUCT const *CapSense_1_curFlashSnsPtr = 0u;
    #endif /* (CapSense_1_ENABLE == CapSense_1_CSD2X_EN) */
#endif /* (CapSense_1_ENABLE == CapSense_1_CSD_GANGED_SNS_EN) */
/*  Pointer to Flash structure to hold Sns electrode that was connected previously  */
#if (CapSense_1_ENABLE == CapSense_1_CSD2X_EN)
    CapSense_1_FLASH_IO_STRUCT const *CapSense_1_curSnsIOPtr0;
    CapSense_1_FLASH_IO_STRUCT const *CapSense_1_curSnsIOPtr1;
#else
    CapSense_1_FLASH_IO_STRUCT const *CapSense_1_curSnsIOPtr;
#endif /* (CapSense_1_ENABLE == CapSense_1_CSD2X_EN) */

/*******************************************************************************
* Function Name: CapSense_1_IsBusy
****************************************************************************//**
*
* \brief
*  Returns the current status of the component (scan completed or scan in
*  progress).
*
* \details
*  This function returns the status of the hardware block whether a scan is
*  currently in progress or not. If the component is busy, no new scan or setup
*  widgets should be made. It is recommended using the critical section (i.e.
*  disable global interrupt) in the application when the device transitions from
*  the active mode to sleep or deep sleep mode.
*
* \return
*  Returns the current status of the component:
*    - CapSense_1_NOT_BUSY if there is no scan in progress and a next scan
*      can be initiated.
*    - CapSense_1_SW_STS_BUSY if the previous scanning is not completed
*      and the hardware block is busy.
*
*******************************************************************************/
uint32 CapSense_1_IsBusy(void)
{
    return ((*(volatile uint32 *)&CapSense_1_dsRam.status) & CapSense_1_SW_STS_BUSY);
}

/*******************************************************************************
* Function Name: CapSense_1_SetupWidget
****************************************************************************//**
*
* \brief
*  Performs the initialization required to scan the specified widget.
*
* \details
*  This function prepares the component to scan all sensors in the specified
*  widget, by executing the following tasks.
*    1. Re-initialize the hardware if it is not configured to perform the
*       sensing method used by the specified widget, this happens only if the
*       CSD and CSX methods are used in the component.
*    2. Initialize the hardware with specific sensing configuration (e.g.
*       sensor clock, scan resolution) used by the widget.
*    3. Disconnect all previously connected electrodes, if the electrodes
*       connected by the CapSense_1_CSDSetupWidgetExt(),
*       CapSense_1_CSXSetupWidgetExt() or CapSense_1_CSDConnectSns()
*       functions and not disconnected.
*
*  This function does not start sensor scanning, the CapSense_1_Scan()
*  function must be called to start the scan sensors in the widget. If this
*  function is called more than once, it does not break the component operation,
*  but only the last initialized widget is in effect.

*
* \param wdgtIndex
*  Specify the ID number of the widget to be initialized for scanning.
*  A macro for the widget ID can be found in the
*  CapSense_1 Configuration header file defined as
*  CapSense_1_<WidgetName>_WDGT_ID
*
* \return
*  Returns the status of the widget setting up operation:
*    - CYRET_SUCCESS if the operation is successfully completed.
*    - CYRET_BAD_PARAM if the widget is invalid or if the specified widget is
*      disabled
*    - CYRET_INVALID_STATE if the previous scanning is not completed and the
*      hardware block is busy.
*    - CYRET_UNKNOWN if an unknown sensing method is used by the widget or
*      other spurious errors.
*
**********************************************************************************/
cystatus CapSense_1_SetupWidget(uint32 wdgtIndex)
{
    cystatus widgetStatus;

    if (CapSense_1_WDGT_SW_STS_BUSY == (CapSense_1_dsRam.status & CapSense_1_WDGT_SW_STS_BUSY))
    {
        /* Previous widget is being scanned. Return error. */
        widgetStatus = CYRET_INVALID_STATE;
    }
    /*
     *  Check if widget id is valid, specified widget is enabled and widget did not
     *  detect any fault conditions if BIST is enabled. If all conditions are met,
     *  set widgetStatus as good, if not, set widgetStatus as bad.
     */
    else if ((CapSense_1_TOTAL_SLOTS > wdgtIndex) &&
        (0uL != CapSense_1_GET_WIDGET_EN_STATUS(wdgtIndex)))

    {
        widgetStatus = CYRET_SUCCESS;
    }
    else
    {
        widgetStatus = CYRET_BAD_PARAM;
    }

    /*
     * Check widgetStatus flag that is set earlier, if flag is good, then set up only
     * widget
     */
    if (CYRET_SUCCESS == widgetStatus)
    {
        /*  Check if CSD2X is enabled   */
        #if (CapSense_1_ENABLE == CapSense_1_CSD2X_EN)

            widgetStatus = CapSense_1_SetupWidget2x(wdgtIndex);

        #elif (CapSense_1_ENABLE == CapSense_1_CSD_CSX_EN)
            /*  Check widget sensing method is CSX and call CSX APIs    */
            if (CapSense_1_SENSE_METHOD_CSX_E ==
                CapSense_1_GET_SENSE_METHOD(&CapSense_1_dsFlash.wdgtArray[wdgtIndex]))
            {
                /*  Set up widget for CSX scan  */
                CapSense_1_CSXSetupWidget(wdgtIndex);
            }
            /*  Check widget sensing method is CSD and call appropriate API */
            else if (CapSense_1_SENSE_METHOD_CSD_E ==
                     CapSense_1_GET_SENSE_METHOD(&CapSense_1_dsFlash.wdgtArray[wdgtIndex]))
            {
                /*  Set up widget for CSD scan  */
                CapSense_1_CSDSetupWidget(wdgtIndex);
            }
            else
            {
                /*  Sensing method is invalid, return error to caller  */
                widgetStatus = CYRET_UNKNOWN;
            }
        #elif (CapSense_1_ENABLE == CapSense_1_CSD_EN)
            /*  Set up widget for scan */
            CapSense_1_CSDSetupWidget(wdgtIndex);
        #elif (CapSense_1_ENABLE == CapSense_1_CSX_EN)
            /*  Set up widgets for scan     */
            CapSense_1_CSXSetupWidget(wdgtIndex);
        #else
            widgetStatus = CYRET_UNKNOWN;
            #error "No sensing method enabled, component cannot work in this mode"
        #endif  /* (CapSense_1_ENABLE == CapSense_1_CSD2X_EN) */
    }

    return (widgetStatus);
}


/*******************************************************************************
* Function Name: CapSense_1_Scan
****************************************************************************//**
*
* \brief
*  Initiates scan of all sensors in the widget which is initialized by
*  CapSense_1_SetupWidget(), if the no scan is in progress.
*
* \details
*  This function should be called only after the CapSense_1_SetupWidget()
*  function is called to start the scanning of the sensors in the widget. The
*  status of a sensor scan must be checked using the CapSense_1_IsBusy()
*  API prior to starting a next scan or setting up another widget.
*
* \return
*  Returns the status of the scan initiation operation:
*    - CYRET_SUCCESS if scanning is successfully started.
*    - CYRET_INVALID_STATE if the previous scanning is not completed and the
*      hardware block is busy.
*    - CYRET_UNKNOWN if an unknown sensing method is used by the widget.
*
********************************************************************************/
cystatus CapSense_1_Scan(void)
{
    cystatus scanStatus = CYRET_SUCCESS;

    if (CapSense_1_WDGT_SW_STS_BUSY == (CapSense_1_dsRam.status & CapSense_1_WDGT_SW_STS_BUSY))
    {
        /* Previous widget is being scanned. Return error. */
        scanStatus = CYRET_INVALID_STATE;
    }
    else
    {
        /*  If CSD2X is enabled, call CSD2X scan    */
    #if (CapSense_1_ENABLE == CapSense_1_CSD2X_EN)
        scanStatus = CapSense_1_Scan2x();

    /*  If both CSD and CSX are enabled, call scan API based on widget sensing method    */
    #elif (CapSense_1_ENABLE == CapSense_1_CSD_CSX_EN)
        /*  Check widget sensing method and call appropriate APIs   */
        switch (CapSense_1_currentSenseMethod)
        {
            case CapSense_1_SENSE_METHOD_CSX_E:
                CapSense_1_CSXScan();
                break;

            case CapSense_1_SENSE_METHOD_CSD_E:
                 CapSense_1_CSDScan();
                break;

            default:
                scanStatus = CYRET_UNKNOWN;
                break;
        }

    /*  If only CSD is enabled, call CSD scan   */
    #elif (CapSense_1_ENABLE == CapSense_1_CSD_EN)
        CapSense_1_CSDScan();

    /*  If only CSX is enabled, call CSX scan   */
    #elif (CapSense_1_ENABLE == CapSense_1_CSX_EN)
        CapSense_1_CSXScan();

    #else
        scanStatus = CYRET_UNKNOWN;
        #error "No sensing method enabled, component cannot work in this mode"
    #endif  /* (CapSense_1_ENABLE == CapSense_1_CSD2X_EN) */
    }

    return (scanStatus);
}


/*******************************************************************************
* Function Name: CapSense_1_ScanAllWidgets
****************************************************************************//**
*
* \brief
*  Initializes the first enabled widget and scans of all the sensors in the
*  widget, then the same process is repeated for all widgets in the component.
*  I.e. scan all the widgets in the component.
*
* \details
*  This function initializes a widget and scans all the sensors in the widget,
*  and then repeats the same for all the widgets in the component. The tasks of
*  the CapSense_1_SetupWidget() and CapSense_1_Scan() functions are
*  executed by these functions. The status of a sensor scan must be checked
*  using the CapSense_1_IsBusy() API prior to starting a next scan
*  or setting up another widget.
*
* \return
*  Returns the status of operation:
*    - CYRET_SUCCESS if scanning is successfully started.
*    - CYRET_BAD_PARAM if all the widgets are disabled.
*    - CYRET_INVALID_STATE if the previous scanning is not completed and the HW block is busy.
*    - CYRET_UNKNOWN if there are unknown errors.
*
*******************************************************************************/
cystatus CapSense_1_ScanAllWidgets(void)
{
    cystatus scanStatus = CYRET_UNKNOWN;

    uint32 wdgtIndex;

    if (CapSense_1_SW_STS_BUSY == (CapSense_1_dsRam.status & CapSense_1_SW_STS_BUSY))
    {
        /* Previous widget is being scanned. Return error. */
        scanStatus = CYRET_INVALID_STATE;
    }
    else
    {
        /*
         *  Set up widget first widget.
         *  If widget returned error, set up next, continue same until widget does not return error.
         */
        for (wdgtIndex = 0u;
             wdgtIndex < CapSense_1_TOTAL_SLOTS;
             wdgtIndex++)
        {

            scanStatus = CapSense_1_SetupWidget(wdgtIndex);

            if (CYRET_SUCCESS == scanStatus)
            {
                #if (0u != (CapSense_1_TOTAL_SLOTS - 1u))
                    /* If there are more than one widget to be scanned, request callback to scan next widget */
                    if ((CapSense_1_TOTAL_SLOTS - 1u) > wdgtIndex)
                    {
                         /* Request callback to scan next widget in ISR */
                        CapSense_1_requestScanAllWidget = CapSense_1_ENABLE;
                    }
                    else
                    {
                        /* Request to exit in ISR (Do not scan the next widgets) */
                        CapSense_1_requestScanAllWidget = CapSense_1_DISABLE;
                    }
                #else
                    {
                        /* Request to exit in ISR (We have only one widget) */
                        CapSense_1_requestScanAllWidget = CapSense_1_DISABLE;
                    }
                #endif  /* (0u != (CapSense_1_TOTAL_SLOTS - 1u)) */

                /*  Initiate scan and quit loop */
                scanStatus = CapSense_1_Scan();

                break;
            }
        }
    }

    return (scanStatus);
}


/*******************************************************************************
* Function Name: CapSense_1_SsInitialize
****************************************************************************//**
*
* \brief
*   Performs hardware and firmware initialization required for proper operation
*   of the CapSense_1 component. This function is called from
*   the CapSense_1_Start() API prior to calling any other APIs of the component.
*
* \details
*   Performs hardware and firmware initialization required for proper operation
*   of the CapSense_1 component. This function is called from
*   the CapSense_1_Start() API prior to calling any other APIs of the component.
*   1. The function initializes immunity offsets when the frequency hopping is
*      enabled.
*   2. Depending on the configuration, the function initializes the CSD block
*      for the CSD2X, CSD, CSX, or CSD+CSX modes.
*   3. The function updates the dsRam.wdgtWorking variable with 1 when Self Test
*      is enabled.
*
*   Calling the CapSense_1_Start API is the recommended method to initialize
*   the CapSense_1 component at power-up. The CapSense_1_SsInitialize()
*   API should not be used for initialization, resume, or wake-up operations.
*   The dsRam.wdgtWorking variable is updated.
*
* \return status
*   Returns status of operation:
*   - Zero        - Indicates successful initialization.
*   - Non-zero    - One or more errors occurred in the initialization process.
*
*******************************************************************************/
cystatus CapSense_1_SsInitialize(void)
{
    cystatus initStatus = CYRET_SUCCESS;

    #if (CapSense_1_ENABLE == CapSense_1_MULTI_FREQ_SCAN_EN)
        CapSense_1_immunity[CapSense_1_FREQ_CHANNEL_0] = (uint8)CY_GET_REG32(CY_SYS_CLK_IMO_TRIM1_PTR);
        if (CapSense_1_COARSE_TRIM_THRESHOLD_1 > CapSense_1_immunity[CapSense_1_FREQ_CHANNEL_0])
        {
            CapSense_1_immunity[CapSense_1_FREQ_CHANNEL_1] =
            CapSense_1_immunity[CapSense_1_FREQ_CHANNEL_0] + CapSense_1_FREQUENCY_OFFSET_5;
            CapSense_1_immunity[CapSense_1_FREQ_CHANNEL_2] =
            CapSense_1_immunity[CapSense_1_FREQ_CHANNEL_0] + CapSense_1_FREQUENCY_OFFSET_10;
        }
        else if (CapSense_1_COARSE_TRIM_THRESHOLD_2 > CapSense_1_immunity[CapSense_1_FREQ_CHANNEL_0])
        {
            CapSense_1_immunity[CapSense_1_FREQ_CHANNEL_1] =
            CapSense_1_immunity[CapSense_1_FREQ_CHANNEL_0] - CapSense_1_FREQUENCY_OFFSET_5;
            CapSense_1_immunity[CapSense_1_FREQ_CHANNEL_2] =
            CapSense_1_immunity[CapSense_1_FREQ_CHANNEL_0] + CapSense_1_FREQUENCY_OFFSET_5;
        }
        else
        {
            CapSense_1_immunity[CapSense_1_FREQ_CHANNEL_1] =
            CapSense_1_immunity[CapSense_1_FREQ_CHANNEL_0] - CapSense_1_FREQUENCY_OFFSET_5;
            CapSense_1_immunity[CapSense_1_FREQ_CHANNEL_2] =
            CapSense_1_immunity[CapSense_1_FREQ_CHANNEL_0] - CapSense_1_FREQUENCY_OFFSET_10;
        }
    #endif /* (CapSense_1_ENABLE == CapSense_1_MULTI_FREQ_SCAN_EN) */

    #if (CapSense_1_DISABLE == CapSense_1_CSDV2)
        CapSense_1_SsTrimIdacs();
    #endif /* (CapSense_1_ENABLE == CapSense_1_CSDV2) */

    #if((CapSense_1_ENABLE == CapSense_1_CSD_EN) ||\
    ((CapSense_1_ENABLE == CapSense_1_CSX_EN) && (CapSense_1_ENABLE == CapSense_1_CSDV2)))
        CapSense_1_SsInitializeSourceSenseClk();
    #endif /* ((CapSense_1_ENABLE == CapSense_1_CSD_EN) ||\
              ((CapSense_1_ENABLE == CapSense_1_CSX_EN) && (CapSense_1_ENABLE == CapSense_1_CSDV2))) */

    /*
     *  Check if CSD2X is enabled, if yes, initialize CapSense_1 component
     *  for CSD2x operation
     */
    #if (CapSense_1_ENABLE == CapSense_1_CSD2X_EN)
        /*
         *  Check if CSX or CSD enable along with CSD2X, if yes, provide the error
         *  message as CSD2X can not coexist with CSD or CSX
         */
        #if (CapSense_1_ENABLE == CapSense_1_CSX_EN)
            #error "CSD2X and CSX can not be enabled together"
            initStatus = CYRET_UNKNOWN;
        #elif (CapSense_1_ENABLE == CapSense_1_CSD_EN)
            #error "CSD2X and CSD can not be enabled together"
            initStatus = CYRET_UNKNOWN;
        #endif /* (CapSense_1_CSX_EN == CapSense_1_ENABLE) */

        /* Initialize both CSD blocks for CSD2X scanning    */
        CapSense_1_CSD2XInitialize();

    #elif ((CapSense_1_ENABLE == CapSense_1_CSD_CSX_EN) || \
            (CapSense_1_ENABLE == CapSense_1_SELF_TEST_EN) || \
            (CapSense_1_ENABLE == CapSense_1_ADC_EN))

        /* Set all IO states to default state  */
        CapSense_1_SsSetIOsInDefaultState();
        /*
         * CSD hardware block is initialized in the Setup Widget based
         * on widget sensing method. Release previously captured HW resources
         * if it is second call of CapSense_1_Start() function.
         */
        CapSense_1_SsSwitchSensingMode(CapSense_1_UNDEFINED_E);
    #elif (CapSense_1_ENABLE == CapSense_1_CSD_EN)
        /*  Initialize CSD block for CSD scanning   */
        CapSense_1_SsCSDInitialize();

    #elif (CapSense_1_ENABLE == CapSense_1_CSX_EN)
        /*  Initialize CSD block for CSX scanning   */
        CapSense_1_CSXInitialize();

    #else
        #error "No sensing method enabled, component cannot work in this mode"
        initStatus = CYRET_UNKNOWN;
    #endif  /* (CapSense_1_ENABLE == CapSense_1_CSD2X_EN) */

    return (initStatus);
}


/*******************************************************************************
* Function Name: CapSense_1_SetPinState
****************************************************************************//**
*
* \brief
*  Sets the state (drive mode and output state) of port pin used by a sensor.
*  The possible states are GND, Shield, High-Z, Tx or Rx, sensor. If the sensor
*  specified in the input parameter is a ganged sensor, then state of all pins
*  associated with ganged sensor is updated.
*
* \details
*  This function sets a specified state to the specified sensor pin. If the
*  sensor is a ganged sensor, then the specified state is also set for all
*  ganged pins of this sensor. Scanning should be completed before calling
*  this API.
*
*  The CapSense_1_SHIELD and CapSense_1_SENSOR states are not
*  allowed if there is no CSD widget configured in the userÅfs project.
*  The CapSense_1_TX_PIN and CapSense_1_RX_PIN states are not
*  allowed if there is no CSX widget configured in the userÅfs project.
*
*  It is not recommended to call this function directly from the application
*  layer. This function should be used to implement only the userÅfs specific
*  use cases. Functions that perform a setup and scan of the sensor/widget
*  automatically set needed pin states. They do not take into account changes
*  in the design made by the CapSense_1_SetPinState() function.
*
*  \param wdgtIndex
*  Specify the ID number of the widget to change the pin state of the specified
*  sensor.
*  A macro for the widget ID can be found in the CapSense_1 Configuration header
*  file defined as CapSense_1_<WidgetName>_WDGT_ID.
*
*  \param snsIndex
*  Specify the ID number of the sensor within the widget to change its pin
*  state.
*  A macro for the sensor ID within a specified widget can be found in the
*  CapSense_1 Configuration header file defined as
*  CapSense_1_<WidgetName>_SNS<SensorNumber>_ID
*
*  \param state
*   Specify the state of the sensor that needs to be set:
*     1. CapSense_1_GROUND - The pin is connected to ground.
*     2. CapSense_1_HIGHZ - The drive mode of the pin is set to High-Z
*        Analog.
*     3. CapSense_1_SHIELD - The shield signal is routed to the pin (only
*        in CSD sensing method when shield electrode is enabled).
*     4. CapSense_1_SENSOR ? The pin is connected to the scanning bus
*        (only in CSD sensing method).
*     5. CapSense_1_TX_PIN ? The TX signal is routed to the sensor
*        (only in CSX sensing method).
*     6. CapSense_1_RX_PIN ? The pin is connected to the scanning bus
*        (only in CSX sensing method).
*
*******************************************************************************/
void CapSense_1_SetPinState(uint32 wdgtIndex, uint32 snsIndex, uint32 state)
{
    CapSense_1_FLASH_IO_STRUCT const *curSnsIOPtr;
    #if (CapSense_1_ENABLE == CapSense_1_CSD_GANGED_SNS_EN)
        CapSense_1_FLASH_SNS_STRUCT const *curFlashSnsPtr;
        uint32 tempVal;
    #endif /* (CapSense_1_ENABLE == CapSense_1_CSD_GANGED_SNS_EN) */
    uint32 newRegisterValue;
    uint8  interruptState;
    uint32 pinHSIOMShift;
    uint32 pinModeShift;

    #if (CapSense_1_ENABLE == CapSense_1_CSD_GANGED_SNS_EN)
        /* Check ganged sns flag  */
        if (CapSense_1_GANGED_SNS_MASK == (CapSense_1_dsFlash.wdgtArray[wdgtIndex].staticConfig &
            CapSense_1_GANGED_SNS_MASK))
        {
            curFlashSnsPtr = CapSense_1_dsFlash.wdgtArray[wdgtIndex].ptr2SnsFlash;
            curFlashSnsPtr += snsIndex;
            curSnsIOPtr = &CapSense_1_ioList[curFlashSnsPtr->firstPinId];

            /* Get number of ganged pins  */
            tempVal = curFlashSnsPtr->numPins;
        }
        else
        {
            curSnsIOPtr = (CapSense_1_FLASH_IO_STRUCT const *)
                                    CapSense_1_dsFlash.wdgtArray[wdgtIndex].ptr2SnsFlash + snsIndex;
            /* There are no ganged pins */
            tempVal = 1u;
        }
    #else
        curSnsIOPtr = (CapSense_1_FLASH_IO_STRUCT const *)
                                    CapSense_1_dsFlash.wdgtArray[wdgtIndex].ptr2SnsFlash + snsIndex;
    #endif  /* (CapSense_1_ENABLE == CapSense_1_CSD_GANGED_SNS_EN) */

    #if (CapSense_1_ENABLE == CapSense_1_CSD_GANGED_SNS_EN)
        /* Reconfigure all ganged sensors  */
        do
        {
    #endif  /* (CapSense_1_ENABLE == CapSense_1_CSD_GANGED_SNS_EN) */

            /* Get HSIOM and port mode shifts */
            pinHSIOMShift = (uint32)curSnsIOPtr->hsiomShift;
            pinModeShift = (uint32)curSnsIOPtr->shift;

            /* Reset HSIOM register */
            CY_SET_REG32(curSnsIOPtr->hsiomPtr, CY_GET_REG32(curSnsIOPtr->hsiomPtr) & ~(CapSense_1_HSIOM_SEL_MASK << pinHSIOMShift));

            switch (state)
            {
            case CapSense_1_GROUND:
                interruptState = CyEnterCriticalSection();

                /* Update port configuration register (drive mode) for sensor */
                newRegisterValue = CY_GET_REG32(curSnsIOPtr->pcPtr);
                newRegisterValue &= ~(CapSense_1_GPIO_PC_MASK << pinModeShift);
                newRegisterValue |= (CapSense_1_SNS_GROUND_CONNECT << pinModeShift);
                CY_SET_REG32(curSnsIOPtr->pcPtr, newRegisterValue);

                CyExitCriticalSection(interruptState);

                /* Set logic 0 to port data register */
                CY_SET_REG32(curSnsIOPtr->drPtr, CY_GET_REG32(curSnsIOPtr->drPtr) & (uint32)~(uint32)((uint32)1u << curSnsIOPtr->drShift));
                break;

            case CapSense_1_HIGHZ:
                interruptState = CyEnterCriticalSection();

                /* Update port configuration register (drive mode) for sensor */
                newRegisterValue = CY_GET_REG32(curSnsIOPtr->pcPtr);
                newRegisterValue &= ~(CapSense_1_GPIO_PC_MASK << pinModeShift);
                CY_SET_REG32(curSnsIOPtr->pcPtr, newRegisterValue);

                CyExitCriticalSection(interruptState);

                /* Set logic 0 to port data register */
                CY_SET_REG32(curSnsIOPtr->drPtr, CY_GET_REG32(curSnsIOPtr->drPtr) & (uint32)~(uint32)((uint32)1u << curSnsIOPtr->drShift));
                break;

            #if (CapSense_1_ENABLE == CapSense_1_CSD_SHIELD_EN)
                case CapSense_1_SHIELD:
                    /* Set drive mode to Analog */
                    CY_SET_REG32(curSnsIOPtr->pcPtr, CY_GET_REG32(curSnsIOPtr->pcPtr) &
                               ~(CapSense_1_GPIO_PC_MASK <<(curSnsIOPtr->shift)));

                    /* Set appropriate bit in HSIOM register to configure pin to shield mode */
                    CY_SET_REG32(curSnsIOPtr->hsiomPtr, CY_GET_REG32(curSnsIOPtr->hsiomPtr) |
                                                       (CapSense_1_HSIOM_SEL_CSD_SHIELD << pinHSIOMShift));
                    break;
            #endif  /* (CapSense_1_ENABLE == CapSense_1_CSD_SHIELD_EN) */

            #if ((CapSense_1_ENABLE == CapSense_1_CSD_EN) || \
                 (CapSense_1_ENABLE == CapSense_1_CSD_CSX_EN))
                case CapSense_1_SENSOR:
                    /* Enable sensor */
                    CapSense_1_CSDConnectSns(curSnsIOPtr);
                    break;
            #endif  /* ((CapSense_1_ENABLE == CapSense_1_CSD_EN) || \
                        (CapSense_1_ENABLE == CapSense_1_CSD_CSX_EN)) */

            #if ((CapSense_1_ENABLE == CapSense_1_CSX_EN) || \
                 (CapSense_1_ENABLE == CapSense_1_CSD_CSX_EN))
                case CapSense_1_TX_PIN:
                    CY_SET_REG32(curSnsIOPtr->hsiomPtr, CY_GET_REG32(curSnsIOPtr->hsiomPtr) | (CapSense_1_HSIOM_SEL_CSD_SENSE << pinHSIOMShift));
                    CY_SET_REG32(curSnsIOPtr->pcPtr, CY_GET_REG32(curSnsIOPtr->pcPtr) | (CapSense_1_GPIO_STRGDRV << pinModeShift));
                    break;

                case CapSense_1_RX_PIN:
                    CY_SET_REG32(curSnsIOPtr->hsiomPtr, CY_GET_REG32(curSnsIOPtr->hsiomPtr) | (CapSense_1_HSIOM_SEL_AMUXA << pinHSIOMShift));
                    CY_SET_REG32(curSnsIOPtr->pcPtr, CY_GET_REG32(curSnsIOPtr->pcPtr) & ~(CapSense_1_GPIO_PC_MASK << pinModeShift));
                    break;
            #endif  /* ((CapSense_1_ENABLE == CapSense_1_CSX_EN) || \
                        (CapSense_1_ENABLE == CapSense_1_CSD_CSX_EN)) */

            default:
                /* Wrong input */
                break;
            }

    #if (CapSense_1_ENABLE == CapSense_1_CSD_GANGED_SNS_EN)
            curSnsIOPtr++;
            tempVal--;
        } while (0u != tempVal);
    #endif  /* (CapSense_1_ENABLE == CapSense_1_CSD_GANGED_SNS_EN) */
}


#if ((CapSense_1_ENABLE == CapSense_1_CSD_CSX_EN) || \
     (CapSense_1_ENABLE == CapSense_1_SELF_TEST_EN) || \
     (CapSense_1_ENABLE == CapSense_1_ADC_EN))

    #if (CapSense_1_ENABLE == CapSense_1_CSD_EN)
        /*******************************************************************************
        * Function Name: CapSense_1_SsCSDDisableMode
        ****************************************************************************//**
        *
        * \brief
        *  This function disables CSD mode.
        *
        * \details
        *  To disable CSD mode the following tasks are performed:
        *  1. Disconnect Cmod from AMUXBUS-A;
        *  2. Disconnect previous CSX electrode if it has been connected;
        *  3. Disconnect Csh from AMUXBUS-B;
        *  4. Disable Shield Electrodes.
        *
        *******************************************************************************/
        static void CapSense_1_SsCSDDisableMode(void)
        {
            uint32 newRegValue;

            /* Disconnect Cmod from AMUXBUS-A using HSIOM registers */
            newRegValue = CY_GET_REG32(CapSense_1_CMOD_HSIOM_PTR);
            newRegValue &= (uint32)(~(uint32)CapSense_1_CMOD_HSIOM_MASK);
            CY_SET_REG32(CapSense_1_CMOD_HSIOM_PTR, newRegValue);

            #if ((CapSense_1_ENABLE == CapSense_1_CSDV2) && \
                 ((CapSense_1_ENABLE == CapSense_1_CSD_IDAC_COMP_EN) && \
                 (CapSense_1_ENABLE == CapSense_1_CSD_DEDICATED_IDAC_COMP_EN)))
                /* Disconnect IDACA and IDACB */
                newRegValue = CY_GET_REG32(CapSense_1_SW_REFGEN_SEL_PTR);
                newRegValue &= (uint32)(~CapSense_1_SW_REFGEN_SEL_SW_IAIB_MASK);
                CY_SET_REG32(CapSense_1_SW_REFGEN_SEL_PTR, newRegValue);
            #endif /* ((CapSense_1_ENABLE == CapSense_1_CSDV2) && \
                       ((CapSense_1_ENABLE == CapSense_1_CSD_IDAC_COMP_EN) && \
                       (CapSense_1_ENABLE == CapSense_1_CSD_DEDICATED_IDAC_COMP_EN))) */

            /* Disconnect previous CSD electrode if it has been connected */
            CapSense_1_SsCSDElectrodeCheck();

            /* Disconnect Csh from AMUXBUS-B */
            #if ((CapSense_1_ENABLE == CapSense_1_CSD_SHIELD_EN) && \
                 (CapSense_1_ENABLE == CapSense_1_CSD_SHIELD_TANK_EN))
                newRegValue = CY_GET_REG32(CapSense_1_CSH_HSIOM_PTR);
                newRegValue &= (uint32)(~(uint32)(CapSense_1_CSH_TO_AMUXBUS_B_MASK << CapSense_1_CSH_HSIOM_SHIFT));
                CY_SET_REG32(CapSense_1_CSH_HSIOM_PTR, newRegValue);
            #endif /* ((CapSense_1_ENABLE == CapSense_1_CSD_SHIELD_EN) && \
                       (CapSense_1_ENABLE == CapSense_1_CSD_SHIELD_TANK_EN)) */

            #if ((CapSense_1_ENABLE == CapSense_1_CSD_SHIELD_EN) && \
                 (0u != CapSense_1_CSD_TOTAL_SHIELD_COUNT))
                CapSense_1_SsCSDDisableShieldElectrodes();
            #endif /* ((CapSense_1_ENABLE == CapSense_1_CSD_SHIELD_EN) && \
                       (0u != CapSense_1_CSD_TOTAL_SHIELD_COUNT)) */
        }
    #endif /* (CapSense_1_ENABLE == CapSense_1_CSD_EN) */


    #if (CapSense_1_ENABLE == CapSense_1_CSX_EN)
        /*******************************************************************************
        * Function Name: CapSense_1_SsDisableCSXMode
        ****************************************************************************//**
        *
        * \brief
        *  This function disables CSX mode.
        *
        * \details
        *  To disable CSX mode the following tasks are performed:
        *  1. Disconnect CintA and CintB from AMUXBUS-A
        *  2. Disconnect previous CSX electrode if it has been connected
        *
        *******************************************************************************/
        static void CapSense_1_SsDisableCSXMode(void)
        {
            uint32 newRegValue;

            /*  Disconnect CintA from AMUXBUS-A using HSIOM registers.   */
            newRegValue = CY_GET_REG32(CapSense_1_CintA_HSIOM_PTR);
            newRegValue &= (uint32)(~(uint32)CapSense_1_CintA_HSIOM_MASK);
            CY_SET_REG32(CapSense_1_CintA_HSIOM_PTR, newRegValue);

            /*  Disconnect CintB from AMUXBUS-A using HSIOM registers.   */
            newRegValue = CY_GET_REG32(CapSense_1_CintB_HSIOM_PTR);
            newRegValue &= (uint32)(~(uint32)CapSense_1_CintB_HSIOM_MASK);
            CY_SET_REG32(CapSense_1_CintB_HSIOM_PTR, newRegValue);

            /* Disconnect previous CSX electrode if it has been connected */
            CapSense_1_CSXElectrodeCheck();
        }
    #endif /* (CapSense_1_ENABLE == CapSense_1_CSX_EN) */


    /*******************************************************************************
    * Function Name: CapSense_1_SsSwitchSensingMode
    ****************************************************************************//**
    *
    * \brief
    *  This function changes the mode for case when both CSD and CSX widgets are
    *  scanned.
    *
    * \details
    *  To switch to the CSD mode the following tasks are performed:
    *  1. Disconnect CintA and CintB from AMUXBUS-A;
    *  2. Disconnect previous CSD electrode if it has been connected;
    *  3. Initialize CSD mode.
    *
    *  To switch to the CSX mode the following tasks are performed:
    *  1. Disconnect Cmod from AMUXBUS-A;
    *  2. Disconnect previous CSX electrode if it has been connected;
    *  3. Initialize CSX mode.
    *
    * \param mode Specifies the scan mode:
    *           -  (1) CapSense_1_SENSE_METHOD_CSD_E
    *           -  (2) CapSense_1_SENSE_METHOD_CSX_E
    *           -  (3) CapSense_1_SENSE_METHOD_BIST_E
    *
    *******************************************************************************/
    void CapSense_1_SsSwitchSensingMode(CapSense_1_SENSE_METHOD_ENUM mode)
    {
        if (CapSense_1_currentSenseMethod != mode)
        {
            /* The requested mode differes to the current one. Disable the current mode */
            if (CapSense_1_SENSE_METHOD_CSD_E ==  CapSense_1_currentSenseMethod)
            {
                #if (CapSense_1_ENABLE == CapSense_1_CSD_EN)
                    CapSense_1_SsCSDDisableMode();
                #endif /* (CapSense_1_ENABLE == CapSense_1_CSD_EN) */
            }
            else if (CapSense_1_SENSE_METHOD_CSX_E ==  CapSense_1_currentSenseMethod)
            {
                #if (CapSense_1_ENABLE == CapSense_1_CSX_EN)
                    CapSense_1_SsDisableCSXMode();
                #endif /* (CapSense_1_ENABLE == CapSense_1_CSX_EN) */
            }
            else if (CapSense_1_SENSE_METHOD_BIST_E ==  CapSense_1_currentSenseMethod)
            {
                #if (CapSense_1_ENABLE == CapSense_1_SELF_TEST_EN)
                    CapSense_1_BistDisableMode();
                #endif /* (CapSense_1_ENABLE == CapSense_1_CSX_EN) */
            }
            else
            {
                #if (CapSense_1_ENABLE == CapSense_1_ADC_EN)
                    /* Release ADC resources */
                    (void)CapSense_1_AdcReleaseResources();
                #endif /* (CapSense_1_ENABLE == CapSense_1_ADC_EN) */
            }

            /* Enable the specified mode */
            if (CapSense_1_SENSE_METHOD_CSD_E == mode)
            {
                #if (CapSense_1_ENABLE == CapSense_1_CSD_EN)
                    /* Initialize CSD mode to guarantee configured CSD mode */
                    CapSense_1_SsCSDInitialize();
                    CapSense_1_currentSenseMethod = CapSense_1_SENSE_METHOD_CSD_E;
                #endif /* (CapSense_1_ENABLE == CapSense_1_CSD_EN) */
            }
            else if (CapSense_1_SENSE_METHOD_CSX_E == mode)
            {
                #if (CapSense_1_ENABLE == CapSense_1_CSX_EN)
                    /* Initialize CSX mode to guarantee configured CSX mode */
                    CapSense_1_CSXInitialize();
                    CapSense_1_currentSenseMethod = CapSense_1_SENSE_METHOD_CSX_E;
                #endif /* (CapSense_1_ENABLE == CapSense_1_CSX_EN) */
            }
            else if (CapSense_1_SENSE_METHOD_BIST_E == mode)
            {
                #if (CapSense_1_ENABLE == CapSense_1_SELF_TEST_EN)
                    /* Initialize CSX mode to guarantee configured CSX mode */
                    CapSense_1_BistInitialize();
                    CapSense_1_currentSenseMethod = CapSense_1_SENSE_METHOD_BIST_E;
                #endif /* (CapSense_1_ENABLE == CapSense_1_CSX_EN) */
            }
            else
            {
                CapSense_1_currentSenseMethod = CapSense_1_UNDEFINED_E;
            }
        }
    }
#endif  /* ((CapSense_1_ENABLE == CapSense_1_CSD_CSX_EN) || \
            (CapSense_1_ENABLE == CapSense_1_SELF_TEST_EN) || \
            (CapSense_1_ENABLE == CapSense_1_ADC_EN)) */

#if ((CapSense_1_ENABLE == CapSense_1_CSX_EN) || \
     (CapSense_1_ENABLE == CapSense_1_SELF_TEST_EN) || \
     (CapSense_1_ENABLE == CapSense_1_ADC_EN))
    /*******************************************************************************
    * Function Name: CapSense_1_SsSetIOsInDefaultState
    ****************************************************************************//**
    *
    * \brief
    *   Sets all electrodes into a default state.
    *
    * \details
    *   Sets all IOs into a default state:
    *   - HSIOM   - Disconnected, the GPIO mode.
    *   - DM      - Strong drive.
    *   - State   - Zero.
    *
    *   It is not recommended to call this function directly from the application
    *   layer.
    *
    *******************************************************************************/
    void CapSense_1_SsSetIOsInDefaultState(void)
    {
        CapSense_1_FLASH_IO_STRUCT const *ioPtr = &CapSense_1_ioList[0u];
        uint32 loopIndex;
        uint32 regValue;

        /*  Loop through all electrodes */
        for (loopIndex = 0u; loopIndex < CapSense_1_TOTAL_ELECTRODES; loopIndex++)
        {
            /*  1. Disconnect HSIOM
                2. Set strong DM
                3. Set pin state to logic 0     */
            regValue = CY_GET_REG32 (ioPtr->hsiomPtr);
            regValue &= ~(ioPtr->hsiomMask);
            CY_SET_REG32 (ioPtr->hsiomPtr, regValue);

            regValue = CY_GET_REG32 (ioPtr->pcPtr);
            regValue &= ~(CapSense_1_GPIO_PC_MASK << ioPtr->shift);
            regValue |=  (CapSense_1_GPIO_STRGDRV << ioPtr->shift);
            CY_SET_REG32 (ioPtr->pcPtr, regValue);

            regValue = CY_GET_REG32 (ioPtr->drPtr);
            regValue &= ~(ioPtr->mask);
            CY_SET_REG32 (ioPtr->drPtr, regValue);

            /*  Get next electrode  */
            ioPtr++;
        }
    }
#endif /* ((CapSense_1_ENABLE == CapSense_1_CSX_EN) || \
          (CapSense_1_ENABLE == CapSense_1_SELF_TEST_EN) || \
          (CapSense_1_ENABLE == CapSense_1_ADC_EN)) */


#if (CapSense_1_ENABLE == CapSense_1_ADC_EN)
/*******************************************************************************
* Function Name: CapSense_1_SsReleaseResources()
****************************************************************************//**
*
* \brief
*  This function sets the resources that do not belong to the CSDv2 HW block to
*  default state.
*
* \details
*  The function performs following tasks:
*  1. Checks if CSD block busy and returns error if it is busy
*  2. Disconnects integration capacitors (CintA, CintB for CSX mode and
*     Cmod for CSD mode)
*  3. Disconnect electroded if they have been connected.
*
* \return
*   Returns the status of operation:
*   - Zero        - Resources released successfully.
*   - Non-zero    - One or more errors occurred in releasing process.
*
*******************************************************************************/
cystatus CapSense_1_SsReleaseResources(void)
{
    cystatus busyStatus = CYRET_SUCCESS;

    if (CapSense_1_SW_STS_BUSY == (CapSense_1_dsRam.status & CapSense_1_SW_STS_BUSY))
    {
        /* Previous widget is being scanned. Return error. */
        busyStatus = CYRET_INVALID_STATE;
    }
    else
    {
        #if (CapSense_1_ENABLE == CapSense_1_CSX_EN)
            CapSense_1_SsDisableCSXMode();
        #endif /* (CapSense_1_ENABLE == CapSense_1_CSX_EN) */

        #if (CapSense_1_ENABLE == CapSense_1_CSD_EN)
            CapSense_1_SsCSDDisableMode();
        #endif /* (CapSense_1_ENABLE == CapSense_1_CSD_EN) */

        #if (CapSense_1_ENABLE == CapSense_1_SELF_TEST_EN)
            CapSense_1_BistDisableMode();
        #endif /* (CapSense_1_ENABLE == CapSense_1_SELF_TEST_EN) */

        #if ((CapSense_1_ENABLE == CapSense_1_CSD_EN) && \
             (CapSense_1_ENABLE == CapSense_1_CSD_SHIELD_EN) &&  \
             (CapSense_1_SNS_CONNECTION_SHIELD == CapSense_1_CSD_INACTIVE_SNS_CONNECTION))
            CapSense_1_SsSetIOsInDefaultState();
        #endif /* ((CapSense_1_ENABLE == CapSense_1_CSD_EN) && \
             (CapSense_1_DISABLE != CapSense_1_CSD_SHIELD_EN) &&  \
             (CapSense_1_SNS_CONNECTION_SHIELD == CapSense_1_CSD_INACTIVE_SNS_CONNECTION)) */

        /*
         * Reset of the currentSenseMethod variable to make sure that the next
         * call of SetupWidget() API setups the correct widget mode
         */
        CapSense_1_currentSenseMethod = CapSense_1_UNDEFINED_E;
    }

    return busyStatus;
}
#endif /* (CapSense_1_ENABLE == CapSense_1_ADC_EN) */


/*******************************************************************************
* Function Name: CapSense_1_SsPostAllWidgetsScan
****************************************************************************//**
*
* \brief
*   The ISR function for multiple widget scanning implementation.
*
* \details
*   This is the function used by the CapSense_1 ISR to implement multiple widget
*   scanning.
*   Should not be used by the application layer.
*
*******************************************************************************/
void CapSense_1_SsPostAllWidgetsScan(void)
{
    #if (CapSense_1_DISABLE == CapSense_1_CSD2X_EN)
        /*
        *   1. Increment widget index
        *   2. Check if all widgets are scanned
        *   3. If all widgets are not scanned, set up and scan next widget
        */
        #if (1u != CapSense_1_TOTAL_WIDGETS)
            cystatus postScanStatus;

            do
            {
                CapSense_1_widgetIndex++;

                postScanStatus = CapSense_1_SetupWidget((uint32)CapSense_1_widgetIndex);

                if (CYRET_SUCCESS == postScanStatus)
                {
                    if((CapSense_1_TOTAL_WIDGETS - 1u) == CapSense_1_widgetIndex)
                    {
                        /* The last widget will be scanned. Reset flag to skip configuring the next widget setup in ISR. */
                        CapSense_1_requestScanAllWidget = CapSense_1_DISABLE;
                    }
                    (void)CapSense_1_Scan();
                }
                else if((CapSense_1_TOTAL_WIDGETS - 1u) == CapSense_1_widgetIndex)
                {
                    #if ((CapSense_1_ENABLE == CapSense_1_BLOCK_OFF_AFTER_SCAN_EN) && \
                         (CapSense_1_ENABLE == CapSense_1_CSD_EN))
                        if (CapSense_1_SENSE_METHOD_CSD_E ==
                             CapSense_1_GET_SENSE_METHOD(&CapSense_1_dsFlash.wdgtArray[CapSense_1_widgetIndex]))
                        {
                            /*  Disable the CSD block */
                            CY_SET_REG32(CapSense_1_CONFIG_PTR, CapSense_1_configCsd);
                        }
                    #endif /* ((CapSense_1_ENABLE == CapSense_1_BLOCK_OFF_AFTER_SCAN_EN) && \
                               (CapSense_1_ENABLE == CapSense_1_CSD_EN)) */

                    /* All widgets are totally processed. Reset BUSY flag */
                    CapSense_1_dsRam.status &= ~CapSense_1_SW_STS_BUSY;

                    /* Update status with with the failure */
                    CapSense_1_dsRam.status &= ~CapSense_1_STATUS_ERR_MASK;
                    CapSense_1_dsRam.status |= ((postScanStatus & CapSense_1_STATUS_ERR_SIZE) << CapSense_1_STATUS_ERR_SHIFT);

                    /* Set postScanStatus to exit the while loop */
                    postScanStatus = CYRET_SUCCESS;
                }
                else
                {
                    /* Update status with with the failure. Configure the next widget in while() loop */
                    CapSense_1_dsRam.status &= ~CapSense_1_STATUS_ERR_MASK;
                    CapSense_1_dsRam.status |= ((postScanStatus & CapSense_1_STATUS_ERR_SIZE) << CapSense_1_STATUS_ERR_SHIFT);
                }
            } while (CYRET_SUCCESS != postScanStatus);
        #endif /* (1u != CapSense_1_TOTAL_WIDGETS) */
    #else
        #if (1u != CapSense_1_TOTAL_SLOTS)
            cystatus postScanStatus = CYRET_SUCCESS;

            do
            {
                if ((CapSense_1_TOTAL_SLOTS - 1u) > CapSense_1_slotIndex)
                {
                    CapSense_1_slotIndex++;
                    postScanStatus = CapSense_1_SetupWidget((uint32)CapSense_1_slotIndex);


                    if (CYRET_SUCCESS == postScanStatus)
                    {
                        if((CapSense_1_TOTAL_SLOTS - 1u) == CapSense_1_slotIndex)
                        {
                            /* The last slot will be scanned. Reset flag to skip configuring the next widget setup in ISR. */
                            CapSense_1_requestScanAllWidget = CapSense_1_DISABLE;
                        }
                        (void)CapSense_1_Scan();
                    }
                    else if((CapSense_1_TOTAL_SLOTS - 1u) == CapSense_1_slotIndex)
                    {
                        #if (CapSense_1_ENABLE == CapSense_1_BLOCK_OFF_AFTER_SCAN_EN)
                            /*  Disable the CSD blocks */
                            CY_SET_REG32(CapSense_1_CSD0_CONFIG_PTR, CapSense_1_configCsd0);
                            CY_SET_REG32(CapSense_1_CSD1_CONFIG_PTR, CapSense_1_configCsd1);
                        #endif /* (CapSense_1_ENABLE == CapSense_1_BLOCK_OFF_AFTER_SCAN_EN) */

                        /* All widgets are totally processed. Reset BUSY flag */
                        CapSense_1_dsRam.status &= ~CapSense_1_SW_STS_BUSY;

                        /* Update status with with the failure */
                        CapSense_1_dsRam.status &= ~CapSense_1_STATUS_ERR_MASK;
                        CapSense_1_dsRam.status |= ((postScanStatus & CapSense_1_STATUS_ERR_SIZE) << CapSense_1_STATUS_ERR_SHIFT);

                        /* Set postScanStatus to exit the while loop */
                        postScanStatus = CYRET_SUCCESS;
                    }
                    else
                    {
                        /* Update status with with the failure. Configure the next widget in while() loop */
                        CapSense_1_dsRam.status &= ~CapSense_1_STATUS_ERR_MASK;
                        CapSense_1_dsRam.status |= ((postScanStatus & CapSense_1_STATUS_ERR_SIZE) << CapSense_1_STATUS_ERR_SHIFT);
                    }
                }
            } while (CYRET_SUCCESS != postScanStatus);
        #endif /* (1u != CapSense_1_TOTAL_SLOTS) */
    #endif /* (CapSense_1_CSD2X_EN == CapSense_1_DISABLE) */
}


/*******************************************************************************
* Function Name: CapSense_1_SsIsrInitialize
****************************************************************************//**
*
* \brief
*   Enables and initializes for the function pointer for a callback for the ISR.
*
* \details
*   The  "address" is a special type cyisraddress defined by Cylib. This function
*   is used by component APIs and should not be used by an application program for
*   proper working of the component.
*
* \param  address The address of the function to be called when interrupt is fired.
*
*******************************************************************************/
void CapSense_1_SsIsrInitialize(cyisraddress address)
{
#if (CapSense_1_ENABLE == CapSense_1_CSD2X_EN)
    CapSense_1_ISR0_StartEx(address);
    CapSense_1_ISR1_StartEx(address);
#else
    CapSense_1_ISR_StartEx(address);
#endif /* (CapSense_1_ENABLE == CapSense_1_CSD2X_EN) */
}


/*******************************************************************************
* Function Name: CapSense_1_SsSetModClkClockDivider
****************************************************************************//**
*
* \brief
*   Sets the divider values for the modulator clock and then starts
*   the modulator clock.
*
* \details
*   It is not recommended to call this function directly by the application layer.
*   It is used by initialization, widget APIs or wakeup functions to
*   enable the clocks.
*
* \param
*   modClk The divider value for the modulator clock.
*
*******************************************************************************/
void CapSense_1_SsSetModClkClockDivider(uint32 modClk)
{
#if (CapSense_1_ENABLE == CapSense_1_IS_M0S8PERI_BLOCK)
    /*  Stop modulator clock   */
    CY_SET_REG32(CapSense_1_MODCLK_CMD_PTR,
                 ((uint32)CapSense_1_ModClk__DIV_ID <<
                 CapSense_1_MODCLK_CMD_DIV_SHIFT)|
                 ((uint32)CapSense_1_MODCLK_CMD_DISABLE_MASK));

    /*
     * Set divider value for sense modClk.
     * 1u is subtracted from modClk because Divider register value 0 corresponds
     * to dividing by 1.
     */
    CY_SET_REG32(CapSense_1_MODCLK_DIV_PTR, ((modClk - 1u) << 8u));

    /*  Check whether previous modulator clock start command has finished. */
    while(0u != (CY_GET_REG32(CapSense_1_MODCLK_CMD_PTR) & CapSense_1_MODCLK_CMD_ENABLE_MASK))
    {
        /*  Wait until previous modulator clock start command has finished. */
    }

    /*  Start modulator clock, aligned to HFCLK */
    CY_SET_REG32(CapSense_1_MODCLK_CMD_PTR,
                 (uint32)(((uint32)CapSense_1_ModClk__DIV_ID << CapSense_1_MODCLK_CMD_DIV_SHIFT) |
                  ((uint32)CapSense_1_ModClk__PA_DIV_ID << CapSense_1_MODCLK_CMD_PA_DIV_SHIFT) |
                  CapSense_1_MODCLK_CMD_ENABLE_MASK));
#else
    uint32 newRegValue;

    /* Clear bit to disable ModClk clock. */
    CY_SET_REG32(CapSense_1_MODCLK_CMD_PTR,
                 CY_GET_REG32(CapSense_1_MODCLK_CMD_PTR) &
                 (uint32)(~CapSense_1_ModClk__ENABLE_MASK));

    /*
     * Update ModClk clock divider.
     * 1u is subtracted from modClk because Divider register value has range (0-65535).
     */
    newRegValue = CY_GET_REG32(CapSense_1_MODCLK_DIV_PTR) & (uint32)(~(uint32)CapSense_1_ModClk__DIVIDER_MASK);
    newRegValue |= (modClk - 1u);
    CY_SET_REG32(CapSense_1_MODCLK_DIV_PTR, newRegValue);

    /* Set bit to enable ModClk clock. */
    CY_SET_REG32(CapSense_1_MODCLK_CMD_PTR,
                 CY_GET_REG32(CapSense_1_MODCLK_CMD_PTR) |
                CapSense_1_ModClk__ENABLE_MASK);
#endif /* (CapSense_1_ENABLE == CapSense_1_IS_M0S8PERI_BLOCK) */
}


/*******************************************************************************
* Function Name: CapSense_1_SsSetSnsClockDivider
****************************************************************************//**
*
* \brief
*   Sets the divider values for the sense clock and then starts
*   the sense clock.
*
* \details
*   It is not recommended to call this function directly by the application layer.
*   It is used by initialization, widget APIs or wakeup functions to
*   enable the clocks.
*
* \param
*   snsClk The divider value for the sense clock.
*
*******************************************************************************/
void CapSense_1_SsSetSnsClockDivider(uint32 snsClk)
{
#if (CapSense_1_ENABLE == CapSense_1_CSDV2)
    uint32 newRegValue;

    /*
     * Set divider value for sense clock.
     * 1u is subtracted from snsClk because SENSE_DIV value 0 corresponds
     * to dividing by 1.
     */
    newRegValue = CY_GET_REG32(CapSense_1_SENSE_PERIOD_PTR);
    newRegValue &= (uint32)(~CapSense_1_SENSE_PERIOD_SENSE_DIV_MASK);
    newRegValue |= snsClk - 1u;
    CY_SET_REG32(CapSense_1_SENSE_PERIOD_PTR, newRegValue);
#else
    #if (CapSense_1_ENABLE == CapSense_1_IS_M0S8PERI_BLOCK)
        /*  Stop sense clock clock   */
        CY_SET_REG32(CapSense_1_SNSCLK_CMD_PTR,
                     ((uint32)CapSense_1_SnsClk__DIV_ID <<
                     CapSense_1_SNSCLK_CMD_DIV_SHIFT)|
                     ((uint32)CapSense_1_SNSCLK_CMD_DISABLE_MASK));

        /*
         * Set divider value for sense clock.
         * 1u is subtracted from snsClk because Divider register value 0 corresponds
         * to dividing by 1.
         */
        CY_SET_REG32(CapSense_1_SNSCLK_DIV_PTR, ((snsClk - 1u) << 8u));

        /*  Check whether previous sense clock start command has finished. */
        while(0u != (CY_GET_REG32(CapSense_1_SNSCLK_CMD_PTR) & CapSense_1_SNSCLK_CMD_ENABLE_MASK))
        {
            /*  Wait until previous sense clock start command has finished. */
        }

        /* Start sense clock aligned to previously started modulator clock. */
        CY_SET_REG32(CapSense_1_SNSCLK_CMD_PTR,
                     (uint32)(((uint32)CapSense_1_SnsClk__DIV_ID << CapSense_1_SNSCLK_CMD_DIV_SHIFT) |
                      ((uint32)CapSense_1_ModClk__PA_DIV_ID << CapSense_1_SNSCLK_CMD_PA_DIV_SHIFT) |
                      CapSense_1_SNSCLK_CMD_ENABLE_MASK));
    #else
        uint32 newRegValue;

        /* Clear bit to disable SnsClk clock. */
        CY_SET_REG32(CapSense_1_SNSCLK_CMD_PTR,
                     CY_GET_REG32(CapSense_1_SNSCLK_CMD_PTR) &
                     (uint32)(~(uint32)CapSense_1_SnsClk__ENABLE_MASK));

        /*
         * Update snsClk clock divider.
         * 1u is subtracted from snsClk because Divider register value has range (0-65535).
         */
        newRegValue = CY_GET_REG32(CapSense_1_SNSCLK_DIV_PTR) & (uint32)(~(uint32)CapSense_1_SnsClk__DIVIDER_MASK);
        newRegValue |= (snsClk - 1u);
        CY_SET_REG32(CapSense_1_SNSCLK_DIV_PTR, newRegValue);

        /* Set bit to enable SnsClk clock. */
        CY_SET_REG32(CapSense_1_SNSCLK_CMD_PTR,
                     CY_GET_REG32(CapSense_1_SNSCLK_CMD_PTR) |
                    CapSense_1_SnsClk__ENABLE_MASK);
    #endif /* (CapSense_1_ENABLE == CapSense_1_IS_M0S8PERI_BLOCK) */
#endif /* (CapSense_1_ENABLE == CapSense_1_CSDV2) */
}


/*******************************************************************************
* Function Name: CapSense_1_SsSetClockDividers
****************************************************************************//**
*
* \brief
*   Sets the divider values for sense and modulator clocks and then starts
*   a modulator clock-phase aligned to HFCLK and sense clock-phase aligned to
*   the modulator clock.
*
* \details
*   It is not recommended to call this function directly by the application layer.
*   It is used by initialization, widget APIs or wakeup functions to
*   enable the clocks.
*
* \param
*   snsClk The divider value for the sense clock.
*   modClk The divider value for the modulator clock.
*
*******************************************************************************/
void CapSense_1_SsSetClockDividers(uint32 snsClk, uint32 modClk)
{
    /* Configure Mod clock */
    CapSense_1_SsSetModClkClockDivider(modClk);

    /* Configure Sns clock */
    CapSense_1_SsSetSnsClockDivider(snsClk);
}


#if ((CapSense_1_ENABLE == CapSense_1_CSD_IDAC_AUTOCAL_EN) || \
     (CapSense_1_ENABLE == CapSense_1_CSX_IDAC_AUTOCAL_EN))
    /*******************************************************************************
    * Function Name: CapSense_1_CalibrateWidget
    ****************************************************************************//**
    *
    * \brief
    *  Calibrates the IDACs for all sensors in the specified widget to default
    *  target (85%) value, this function detects sensing method used by the
    *  widget prior to calibration.
    *
    * \details
    *  This function performs exactly the same tasks as
    *  CapSense_1_CalibrateAllWidgets, but only for a specified widget.
    *  This function detects the sensing method used by the widgets and takes
    *  into account the Enable compensation IDAC parameter.
    *
    *  This function is available when the CSD and/or CSX Enable IDAC
    *  auto-calibration parameter is enabled.

    *
    * \param wdgtIndex
    *  Specify the ID number of the widget to calibrate its raw count.
    *  A macro for the widget ID can be found in the
    *  CapSense_1 Configuration header file defined as
    *  CapSense_1_<WidgetName>_WDGT_ID.
    *
    * \return
    *  Returns the status of the specified widget calibration:
    *    - CYRET_SUCCESS if operation is successfully completed.
    *    - CYRET_BAD_PARAM if the input parameter is invalid.
    *    - CYRET_BAD_DATA if the calibration failed and the component may not
    *      operate as expected.
    *
    *******************************************************************************/
    cystatus CapSense_1_CalibrateWidget(uint32 wdgtIndex)
    {
        cystatus calibrateStatus = CYRET_SUCCESS;

        do
        {
            if (CapSense_1_TOTAL_WIDGETS <= wdgtIndex)
            {
                calibrateStatus = CYRET_BAD_PARAM;
            }

            /*
             *  Check if widget id is valid, specified widget did not
             *  detect any faults conditions if BIST is enabled.
             */
            #if (CapSense_1_ENABLE == CapSense_1_SELF_TEST_EN)
                if (0u != CapSense_1_GET_WIDGET_EN_STATUS(wdgtIndex))
                {
                    calibrateStatus = CYRET_SUCCESS;
                }
                else
                {
                    calibrateStatus = CYRET_INVALID_STATE;
                }
            #endif  /* (CapSense_1_ENABLE == CapSense_1_SELF_TEST_EN) */

            if (CYRET_SUCCESS != calibrateStatus)
            {
                /* Exit from the loop because of a fail */
                break;
            }
            
            /* If CSD2X is enabled, calibrate CSD sensor    */
            #if (CapSense_1_ENABLE == CapSense_1_CSD2X_EN)
                /* Calibrate CSD2X slot */
                calibrateStatus = CapSense_1_CSD2XCalibrateWidget(wdgtIndex, CapSense_1_CSD_RAWCOUNT_CAL_LEVEL);

            /*  If both CSD and CSX are enabled, calibrate widget using sensing method */
            #elif (CapSense_1_ENABLE == CapSense_1_CSD_CSX_EN)

                /* Check widget sensing method and call appropriate APIs */
                #if (CapSense_1_ENABLE == CapSense_1_CSX_IDAC_AUTOCAL_EN)
                    if (CapSense_1_SENSE_METHOD_CSX_E ==
                        CapSense_1_GET_SENSE_METHOD(&CapSense_1_dsFlash.wdgtArray[wdgtIndex]))
                    {
                        /* Calibrate CSX widget  */
                       CapSense_1_CSXCalibrateWidget(wdgtIndex, CapSense_1_CSX_RAWCOUNT_CAL_LEVEL);
                    }
                #endif  /* (CapSense_1_ENABLE == CapSense_1_CSX_IDAC_AUTOCAL_EN) */

                #if (CapSense_1_ENABLE == CapSense_1_CSD_IDAC_AUTOCAL_EN)
                    if (CapSense_1_SENSE_METHOD_CSD_E ==
                        CapSense_1_GET_SENSE_METHOD(&CapSense_1_dsFlash.wdgtArray[wdgtIndex]))
                    {
                        /* Calibrate CSD widget */
                        calibrateStatus = CapSense_1_CSDCalibrateWidget(wdgtIndex, CapSense_1_CSD_RAWCOUNT_CAL_LEVEL);
                    }
                #endif  /* (CapSense_1_ENABLE == CapSense_1_CSD_IDAC_AUTOCAL_EN) */

            /*  If only CSD is enabled, calibrate CSD sensor  */
            #elif (CapSense_1_ENABLE == CapSense_1_CSD_EN)
                calibrateStatus = CapSense_1_CSDCalibrateWidget(wdgtIndex, CapSense_1_CSD_RAWCOUNT_CAL_LEVEL);

            /*  If only CSX is enabled, call CSX scan   */
            #elif (CapSense_1_ENABLE == CapSense_1_CSX_EN)
                CapSense_1_CSXCalibrateWidget(wdgtIndex, CapSense_1_CSX_RAWCOUNT_CAL_LEVEL);

            #else
                calibrateStatus = CYRET_UNKNOWN;
            #endif  /* (CapSense_1_ENABLE == CapSense_1_CSD2X_EN) */

             /* Update CRC */
            #if (CapSense_1_ENABLE ==CapSense_1_TST_WDGT_CRC_EN)
                CapSense_1_DsUpdateWidgetCrc(wdgtIndex);
            #endif /* (CapSense_1_ENABLE ==CapSense_1_TST_WDGT_CRC_EN) */

        } while (0u);

        return calibrateStatus;
    }


    /*******************************************************************************
    * Function Name: CapSense_1_CalibrateAllWidgets
    ****************************************************************************//**
    *
    * \brief
    *  Calibrates the IDACs for all widgets in the component to default target
    *  (85%) value, this function detects sensing method used by the widgets
    *  prior to calibration.
    *
    * \details
    *  Calibrates the IDACs for all widgets in the component to the default
    *  target (85% of maximum possible raw count) value. This function detects
    *  the sensing method used by the widgets and takes into account the Enable
    *  compensation IDAC parameter.
    *
    *  This function is available when the CSD and/or CSX Enable IDAC
    *  auto-calibration parameter is enabled.
    *
    * \return
    *  Returns the status of the calibration process:
    *    - CYRET_SUCCESS if the operation is successfully completed.
    *    - CYRET_BAD_DATA if the calibration failed and the component may not
    *      operate as expected.
    *
    *******************************************************************************/
    cystatus CapSense_1_CalibrateAllWidgets(void)
    {
        cystatus calibrateStatus = CYRET_SUCCESS;
        uint32 wdgtIndex;

        for (wdgtIndex = 0u; wdgtIndex < CapSense_1_TOTAL_WIDGETS; wdgtIndex++)
        {
            calibrateStatus |= CapSense_1_CalibrateWidget(wdgtIndex);
        }

        return calibrateStatus;
    }
#endif /* ((CapSense_1_ENABLE == CapSense_1_CSD_IDAC_AUTOCAL_EN) ||
           (CapSense_1_ENABLE == CapSense_1_CSX_IDAC_AUTOCAL_EN)) */


#if (CapSense_1_CSD_SS_DIS != CapSense_1_CSD_AUTOTUNE)
    #if (CapSense_1_ENABLE == CapSense_1_CSD2X_EN)
        /*******************************************************************************
        * Function Name: CapSense_1_SsSetEqualSlotClock
        ****************************************************************************//**
        *
        * \brief
        *  This function sets sense clocks to be equal on both CSD blocks.
        *
        * \details
        *  This function sets clock dividers to equal
        *  to widget divider that has higher value.
        *
        *
        *******************************************************************************/
        static void CapSense_1_SsSetEqualSlotClock(void)
        {
            CapSense_1_RAM_WD_BASE_STRUCT *ptrCSD0Wdgt = 0u;
            CapSense_1_RAM_WD_BASE_STRUCT *ptrCSD1Wdgt = 0u;
            uint32 widgetIndex;
            uint32 emptySlot;

            /* Make sure that sense clocks are equal on both CSD blocks */
            for (widgetIndex = 0u; widgetIndex < CapSense_1_TOTAL_WIDGETS; widgetIndex++)
            {
                emptySlot = 0u;
                for (CapSense_1_slotIndex = 0u; CapSense_1_slotIndex < CapSense_1_TOTAL_SLOTS; CapSense_1_slotIndex++)
                {
                    CapSense_1_widgetIndex0 = CapSense_1_scanSlots[CapSense_1_slotIndex].csd0WidgetId;
                    CapSense_1_sensorIndex0 = CapSense_1_scanSlots[CapSense_1_slotIndex].csd0SensorId;

                    CapSense_1_widgetIndex1 = CapSense_1_scanSlots[CapSense_1_slotIndex].csd1WidgetId;
                    CapSense_1_sensorIndex1 = CapSense_1_scanSlots[CapSense_1_slotIndex].csd1SensorId;

                    if (CapSense_1_EMPTY_SLOT == CapSense_1_widgetIndex0)
                    {
                        emptySlot++;
                    }

                    if (CapSense_1_EMPTY_SLOT == CapSense_1_widgetIndex1)
                    {
                        emptySlot++;
                    }

                    if (0u == emptySlot)
                    {
                        ptrCSD0Wdgt = (CapSense_1_RAM_WD_BASE_STRUCT *)
                                       CapSense_1_dsFlash.wdgtArray[CapSense_1_widgetIndex0].ptr2WdgtRam;
                        ptrCSD1Wdgt = (CapSense_1_RAM_WD_BASE_STRUCT *)
                                       CapSense_1_dsFlash.wdgtArray[CapSense_1_widgetIndex1].ptr2WdgtRam;

                        #if (CapSense_1_CSD_MATRIX_WIDGET_EN | CapSense_1_CSD_TOUCHPAD_WIDGET_EN)
                            /* Check if current slot for CSD0 block has a row */
                            if (CapSense_1_dsFlash.wdgtArray[CapSense_1_widgetIndex0].numCols <= CapSense_1_sensorIndex0)
                            {
                                /* Check if current slot for CSD1 block has a row */
                                if (CapSense_1_dsFlash.wdgtArray[CapSense_1_widgetIndex1].numCols <= CapSense_1_sensorIndex1)
                                {
                                    /* Both slots have the rows. Compare rowSnsClk and reassign the higher divider to widget with the lower divider */
                                    if (ptrCSD0Wdgt->rowSnsClk < ptrCSD1Wdgt->rowSnsClk)
                                    {
                                        ptrCSD0Wdgt->rowSnsClk = ptrCSD1Wdgt->rowSnsClk;
                                    }
                                    else
                                    {
                                        ptrCSD1Wdgt->rowSnsClk = ptrCSD0Wdgt->rowSnsClk;
                                    }
                                }
                                else
                                {
                                    /* CSD0 block has the row and CSD1 block has the column. Compare rowSnsClk and snsClk */
                                    if (ptrCSD0Wdgt->rowSnsClk < ptrCSD1Wdgt->snsClk)
                                    {
                                        ptrCSD0Wdgt->rowSnsClk = ptrCSD1Wdgt->snsClk;
                                    }
                                    else
                                    {
                                        ptrCSD1Wdgt->snsClk = ptrCSD0Wdgt->rowSnsClk;
                                    }
                                }
                            }
                            else
                            {
                                /* Check if current slot for CSD1 block has a row */
                                if (CapSense_1_dsFlash.wdgtArray[CapSense_1_widgetIndex1].numCols <= CapSense_1_sensorIndex1)
                                {
                                    /* CSD0 block has the column and CSD1 block has the row. Compare snsClk and rowSnsClk */
                                    if (ptrCSD0Wdgt->snsClk < ptrCSD1Wdgt->rowSnsClk)
                                    {
                                        ptrCSD0Wdgt->snsClk = ptrCSD1Wdgt->rowSnsClk;
                                    }
                                    else
                                    {
                                        ptrCSD1Wdgt->rowSnsClk = ptrCSD0Wdgt->snsClk;
                                    }
                                }
                                else
                                {
                                    /* Both slots have the columns. Compare snsClk and reassign the higher divider to widget with the lower divider */
                                    if (ptrCSD0Wdgt->snsClk < ptrCSD1Wdgt->snsClk)
                                    {
                                        ptrCSD0Wdgt->snsClk = ptrCSD1Wdgt->snsClk;
                                    }
                                    else
                                    {
                                        ptrCSD1Wdgt->snsClk = ptrCSD0Wdgt->snsClk;
                                    }
                                }
                            }
                        #else
                            /* Compare snsClk and reassign the higher divider to widget with the lower divider */
                            if (ptrCSD0Wdgt->snsClk < ptrCSD1Wdgt->snsClk)
                            {
                                ptrCSD0Wdgt->snsClk = ptrCSD1Wdgt->snsClk;
                            }
                            else
                            {
                                ptrCSD1Wdgt->snsClk = ptrCSD0Wdgt->snsClk;
                            }
                        #endif /* (CapSense_1_CSD_MATRIX_WIDGET_EN | CapSense_1_CSD_TOUCHPAD_WIDGET_EN) */
                    }
                }
            }
        }


        /*******************************************************************************
        * Function Name: CapSense_1_SsSetCSD0DirectClockMode
        ****************************************************************************//**
        *
        * \brief
        *  Sets Direct Clock Mode.
        *
        * \details
        *  For CSDv1: Resets PRS bit in CapSense_1_configCsd variable;
        *
        *******************************************************************************/
        static void CapSense_1_SsSetCSD0DirectClockMode(void)
        {
            #if (CapSense_1_DISABLE == CapSense_1_CSDV2)
                CapSense_1_configCsd0 = CapSense_1_configCsd0 &(uint32)~(CapSense_1_CONFIG_PRS_SELECT_MASK);
            #endif /* (CapSense_1_ENABLE == CapSense_1_CSDV2) */
        }


        /*******************************************************************************
        * Function Name: CapSense_1_SsSetCSD1DirectClockMode
        ****************************************************************************//**
        *
        * \brief
        *  Sets Direct Clock Mode.
        *
        * \details
        *  For CSDv1: Resets PRS bit in CapSense_1_configCsd variable;
        *
        *******************************************************************************/
        static void CapSense_1_SsSetCSD1DirectClockMode(void)
        {
            #if (CapSense_1_DISABLE == CapSense_1_CSDV2)
                CapSense_1_configCsd1 = CapSense_1_configCsd1 &(uint32)~(CapSense_1_CONFIG_PRS_SELECT_MASK);
            #endif /* (CapSense_1_ENABLE == CapSense_1_CSDV2) */
        }
    #else


        /*******************************************************************************
        * Function Name: CapSense_1_SsSetDirectClockMode
        ****************************************************************************//**
        *
        * \brief
        *  Sets Direct Clock Mode.
        *
        * \details
        *  For CSDv1: Resets PRS bit in CapSense_1_configCsd variable;
        *  For CSDv2: Resets CapSense_1_SENSE_PERIOD_SEL_LFSR_MSB_MASK and
        *  CapSense_1_SENSE_PERIOD_SEL_LFSR_MSB_MASK bits in
        *  CapSense_1_SENSE_PERIOD register.
        *
        *******************************************************************************/
        static void CapSense_1_SsSetDirectClockMode(void)
        {
            #if (CapSense_1_ENABLE == CapSense_1_CSDV2)
                CY_SET_REG32(CapSense_1_SENSE_PERIOD_PTR, CY_GET_REG32(CapSense_1_SENSE_PERIOD_PTR) &
                                                                     (uint32)~(CapSense_1_SENSE_PERIOD_SEL_LFSR_MSB_MASK | \
                                                                     CapSense_1_SENSE_PERIOD_LFSR_SIZE_MASK));
            #else
                CapSense_1_configCsd = CapSense_1_configCsd &(uint32)~(CapSense_1_CONFIG_PRS_SELECT_MASK);
            #endif /* (CapSense_1_ENABLE == CapSense_1_CSDV2) */
        }
    #endif /* (CapSense_1_ENABLE == CapSense_1_CSD2X_EN) */


    /*******************************************************************************
    * Function Name: CapSense_1_SsAutoTune
    ****************************************************************************//**
    *
    * \brief
    *  This API performs the parameters auto-tuning for the optimal CapSense_1 operation.
    *
    * \details
    *  This API performs the following:
    *  - Calibrates Modulator and Compensation IDACs.
    *  - Tunes the Sense Clock optimal value to get a Sense Clock period greater than
    *     2*5*R*Cp.
    *  - Calculates the resolution for the optimal finger capacitance.
    *
    * \return
    *   Returns the status of operation:
    *   - Zero     - All the widgets are auto-tuned successfully.
    *   - Non-zero - Auto-tuning failed for any widget.
    *
    *******************************************************************************/
    cystatus CapSense_1_SsAutoTune(void)
    {
        cystatus autoTuneStatus = CYRET_SUCCESS;
        uint32 wdgtIndex;
        uint32 cp = 0uL;
        #if (CapSense_1_CSD_MATRIX_WIDGET_EN | CapSense_1_CSD_TOUCHPAD_WIDGET_EN)
            uint32 cpRow = 0uL;
        #endif /* (CapSense_1_CSD_MATRIX_WIDGET_EN | CapSense_1_CSD_TOUCHPAD_WIDGET_EN) */
        CapSense_1_RAM_WD_BASE_STRUCT *ptrWdgt;
        AUTO_TUNE_CONFIG_TYPE autoTuneConfig;
        #if (CapSense_1_ENABLE == CapSense_1_CSD2X_EN)
            uint32 csdBlockID;
        #endif /* (CapSense_1_ENABLE == CapSense_1_CSD2X_EN) */

        /* Configure common config variables */
        autoTuneConfig.snsClkConstantR = CapSense_1_CSD_SNSCLK_R_CONST;
        autoTuneConfig.vRef = CapSense_1_CSD_VREF_MV;
        #if (CapSense_1_DISABLE == CapSense_1_CSD2X_EN)
            autoTuneConfig.iDacGain = CapSense_1_CSD_IDAC_GAIN_VALUE_NA * CapSense_1_CSD_DUAL_IDAC_FACTOR;
        #endif /* (CapSense_1_DISABLE == CapSense_1_CSD2X_EN) */
        autoTuneConfig.calTarget = CapSense_1_CSD_AUTOTUNE_CAL_LEVEL;

        /* Calculate snsClk Input Clock in KHz */
        #if (CapSense_1_ENABLE == CapSense_1_CSDV2)
            /*  Dividers are chained (CSDV2). Flip flop is not available */
            autoTuneConfig.snsClkInputClock = (CYDEV_BCLK__HFCLK__KHZ / CapSense_1_dsRam.modCsdClk);
        #elif ((CapSense_1_ENABLE == CapSense_1_IS_M0S8PERI_BLOCK) && (CapSense_1_DISABLE == CY_PSOC4_4000))
            /*  Dividers are not chained */
            autoTuneConfig.snsClkInputClock = CYDEV_BCLK__HFCLK__KHZ >> CapSense_1_FLIP_FLOP_DIV;
        #elif (CapSense_1_ENABLE == CapSense_1_IS_M0S8PERI_BLOCK)
            /*  Dividers are not chained (PSoC 4000) */
            autoTuneConfig.snsClkInputClock = CYDEV_BCLK__HFCLK__KHZ >> CapSense_1_FLIP_FLOP_DIV;
        #else
            /*  Dividers are chained (PSoC 4100, PSoC 4200) */
            autoTuneConfig.snsClkInputClock = (CYDEV_BCLK__HFCLK__KHZ / CapSense_1_dsRam.modCsdClk) >> CapSense_1_FLIP_FLOP_DIV;
        #endif /* (CapSense_1_ENABLE == CapSense_1_CSDV2) */

        /* If both CSD and CSX are enabled, calibrate widget using sensing method */
        #if (CapSense_1_ENABLE == CapSense_1_CSD_CSX_EN)
            /* Initialize CSD mode */
            CapSense_1_SsCSDInitialize();
        #endif /* (CapSense_1_ENABLE == CapSense_1_CSD_CSX_EN) */

        /* Set flag to calibrate in PWM mode only */
        CapSense_1_prescalersTuningDone = CapSense_1_DISABLE;

        /* Switch charge clock source to direct clock mode */
        #if (CapSense_1_ENABLE == CapSense_1_CSD2X_EN)
            CapSense_1_SsSetCSD0DirectClockMode();
            CapSense_1_SsSetCSD1DirectClockMode();
        #else
            CapSense_1_SsSetDirectClockMode();
        #endif /* (CapSense_1_ENABLE == CapSense_1_CSD2X_EN) */


        /* Tune sense clock for all widgets */
        for (wdgtIndex = 0u; wdgtIndex < CapSense_1_TOTAL_WIDGETS; wdgtIndex++)
        {
            if (CapSense_1_SENSE_METHOD_CSD_E ==
                CapSense_1_GET_SENSE_METHOD(&CapSense_1_dsFlash.wdgtArray[wdgtIndex]))
            {
                ptrWdgt = (CapSense_1_RAM_WD_BASE_STRUCT *)
                          CapSense_1_dsFlash.wdgtArray[wdgtIndex].ptr2WdgtRam;

                #if (CapSense_1_ENABLE == CapSense_1_CSD2X_EN)
                    csdBlockID = CapSense_1_dsFlash.wdgtArray[wdgtIndex].csdblk;

                    if (CapSense_1_CSD0_BLOCK_ID == csdBlockID)
                    {
                        autoTuneConfig.iDacGain = CapSense_1_CSD0_IDAC_GAIN_VALUE_NA * CapSense_1_CSD_DUAL_IDAC_FACTOR;
                    }
                    else
                    {
                        autoTuneConfig.iDacGain = CapSense_1_CSD1_IDAC_GAIN_VALUE_NA * CapSense_1_CSD_DUAL_IDAC_FACTOR;
                    }
                #endif /* (CapSense_1_ENABLE == CapSense_1_CSD2X_EN) */

                /* Set calibration resolution to 12 bits */
                ptrWdgt->resolution = CapSense_1_CALIBRATION_RESOLUTION;

                /* Set Sense clock frequency to 1.5 MHz */
                #if (CapSense_1_ENABLE == CapSense_1_CSD_COMMON_SNS_CLK_EN)
                    CapSense_1_dsRam.snsCsdClk = (uint8)((uint32)autoTuneConfig.snsClkInputClock /
                                                       CapSense_1_CALIBRATION_FREQ_KHZ);
                #elif (CapSense_1_CSD_MATRIX_WIDGET_EN | CapSense_1_CSD_TOUCHPAD_WIDGET_EN)
                    if ((CapSense_1_WD_TOUCHPAD_E == (CapSense_1_WD_TYPE_ENUM)CapSense_1_dsFlash.wdgtArray[(wdgtIndex)].wdgtType) ||
                        (CapSense_1_WD_MATRIX_BUTTON_E == (CapSense_1_WD_TYPE_ENUM)CapSense_1_dsFlash.wdgtArray[(wdgtIndex)].wdgtType))
                    {
                        ptrWdgt->rowSnsClk = (uint8)((uint32)autoTuneConfig.snsClkInputClock /
                                             CapSense_1_CALIBRATION_FREQ_KHZ);
                    }
                    ptrWdgt->snsClk = (uint8)((uint32)autoTuneConfig.snsClkInputClock /
                                      CapSense_1_CALIBRATION_FREQ_KHZ);
                #else
                    ptrWdgt->snsClk = (uint8)((uint32)autoTuneConfig.snsClkInputClock /
                                      CapSense_1_CALIBRATION_FREQ_KHZ);
                #endif /*  (CapSense_1_ENABLE == CapSense_1_CSD_COMMON_SNS_CLK_EN) */

                /* Calibrate CSD widget to 85% */
                #if (CapSense_1_ENABLE == CapSense_1_CSD2X_EN)
                    (void)CapSense_1_CSD2XCalibrateWidget(wdgtIndex, CapSense_1_CSD_AUTOTUNE_CAL_LEVEL);
                #else
                    (void)CapSense_1_CSDCalibrateWidget(wdgtIndex, CapSense_1_CSD_AUTOTUNE_CAL_LEVEL);
                #endif /* (CapSense_1_ENABLE == CapSense_1_CSD2X_EN) */

                #if (CapSense_1_CSD_MATRIX_WIDGET_EN | CapSense_1_CSD_TOUCHPAD_WIDGET_EN)
                    if ((CapSense_1_WD_TOUCHPAD_E == (CapSense_1_WD_TYPE_ENUM)CapSense_1_dsFlash.wdgtArray[(wdgtIndex)].wdgtType) ||
                        (CapSense_1_WD_MATRIX_BUTTON_E == (CapSense_1_WD_TYPE_ENUM)CapSense_1_dsFlash.wdgtArray[(wdgtIndex)].wdgtType))
                    {
                        /* Get pointer to Modulator IDAC for columns */
                        autoTuneConfig.ptrModIDAC = &ptrWdgt->rowIdacMod[0u];

                        /* Get pointer to Sense Clock Divider for columns */
                        autoTuneConfig.ptrSenseClk = &ptrWdgt->rowSnsClk;

                        /* Find correct sense clock value */
                        cpRow = SmartSense_TunePrescalers(&autoTuneConfig);

                        if ((CapSense_1_CP_MAX + CapSense_1_CP_ERROR) <= cpRow)
                        {
                            autoTuneStatus = CYRET_BAD_DATA;
                        }

                        #if (CapSense_1_ENABLE == CapSense_1_CSDV2)
                            /* Make sure that ModClk >= 4 * rowSnsClk for ModClk <= 12 MHz and rowSnsClk <= 6MHz */
                            if (autoTuneConfig.snsClkInputClock <= CapSense_1_MOD_CSD_CLK_24000KHZ)
                            {
                                if (ptrWdgt->rowSnsClk < CapSense_1_FACTOR_FILTER_DELAY_12MHZ)
                                {
                                    ptrWdgt->rowSnsClk = CapSense_1_FACTOR_FILTER_DELAY_12MHZ;
                                }
                            }
                            else if (autoTuneConfig.snsClkInputClock <= CapSense_1_MOD_CSD_CLK_48000KHZ)
                            {
                                if (ptrWdgt->rowSnsClk < CapSense_1_FACTOR_MOD_SNS)
                                {
                                    ptrWdgt->rowSnsClk = CapSense_1_FACTOR_MOD_SNS;
                                }
                            }
                            else
                            {
                                /* rowSnsClk is valid*/
                            }
                        #else
                            #if (CapSense_1_ENABLE == CapSense_1_IS_M0S8PERI_BLOCK)
                                /* Make sure that ModClk >= 2 * rowSnsClk */
                                if (CapSense_1_dsRam.modCsdClk >= ((uint8)(ptrWdgt->rowSnsClk << CapSense_1_FLIP_FLOP_DIV)))
                                {
                                     ptrWdgt->rowSnsClk = CapSense_1_dsRam.modCsdClk;
                                }
                            #else
                                /* Sense clock never equals to Modulator clock for chained dividers because of Flip Flop */
                            #endif /* (CapSense_1_ENABLE == CapSense_1_CSDV2) */
                        #endif /* (CapSense_1_ENABLE == CapSense_1_CSDV2) */
                    }
                #endif /* (CapSense_1_CSD_MATRIX_WIDGET_EN | CapSense_1_CSD_TOUCHPAD_WIDGET_EN) */

                /* Get pointer to Modulator IDAC  for rows */
                autoTuneConfig.ptrModIDAC = &ptrWdgt->idacMod[0u];

                /* Get pointer to Sense Clock Divider for columns */
                autoTuneConfig.ptrSenseClk = &ptrWdgt->snsClk;

                /* Find correct sense clock value */
                cp = SmartSense_TunePrescalers(&autoTuneConfig);

                if ((CapSense_1_CP_MAX + CapSense_1_CP_ERROR) <= cp)
                {
                    autoTuneStatus = CYRET_BAD_DATA;
                }

                #if (CapSense_1_ENABLE == CapSense_1_CSDV2)
                    /* Make sure that ModClk >= 4 * SnsClk for ModClk <= 12 MHz and SnsClk <= 6MHz */
                    if (autoTuneConfig.snsClkInputClock <= CapSense_1_MOD_CSD_CLK_24000KHZ)
                    {
                        if (ptrWdgt->snsClk < CapSense_1_FACTOR_FILTER_DELAY_12MHZ)
                        {
                            ptrWdgt->snsClk = CapSense_1_FACTOR_FILTER_DELAY_12MHZ;
                        }
                    }
                    else if (autoTuneConfig.snsClkInputClock <= CapSense_1_MOD_CSD_CLK_48000KHZ)
                    {
                        if (ptrWdgt->snsClk < CapSense_1_FACTOR_MOD_SNS)
                        {
                            ptrWdgt->snsClk = CapSense_1_FACTOR_MOD_SNS;
                        }
                    }
                    else
                    {
                        /* SnsClk is valid*/
                    }
                #else
                    #if (CapSense_1_ENABLE == CapSense_1_IS_M0S8PERI_BLOCK)
                        /* Make sure that ModClk >= 2 * snsClk */
                        if (CapSense_1_dsRam.modCsdClk >= ((uint8)(ptrWdgt->snsClk << CapSense_1_FLIP_FLOP_DIV)))
                        {
                             ptrWdgt->snsClk = CapSense_1_dsRam.modCsdClk;
                        }
                    #else
                        /* Sense clock never equals to Modulator clock for chained dividers because of Flip Flop */
                    #endif /* (CapSense_1_ENABLE == CapSense_1_CSDV2) */
                #endif /* (CapSense_1_ENABLE == CapSense_1_CSDV2) */
            }
        }

        #if (CapSense_1_ENABLE == CapSense_1_CSD2X_EN)
            CapSense_1_SsSetEqualSlotClock();
        #endif /* (CapSense_1_ENABLE == CapSense_1_CSD2X_EN) */

        /* Set flag to indicate that calibration in PWM mode has been performed */
        CapSense_1_prescalersTuningDone = 1u;

        /* Multiply Clk divider to 2 for PRS mode to take into account average PRS frequency */
        autoTuneConfig.prsFactor = CapSense_1_PRS_FACTOR_DIV;

        /* Tune sensitivity and resolution for all widgets */
        for (wdgtIndex = 0u; wdgtIndex < CapSense_1_TOTAL_WIDGETS; wdgtIndex++)
        {
            if (CapSense_1_SENSE_METHOD_CSD_E ==
                CapSense_1_GET_SENSE_METHOD(&CapSense_1_dsFlash.wdgtArray[wdgtIndex]))
            {
                ptrWdgt = (CapSense_1_RAM_WD_BASE_STRUCT *)
                          CapSense_1_dsFlash.wdgtArray[wdgtIndex].ptr2WdgtRam;

                /* Get pointer to Modulator IDAC for rows */
                autoTuneConfig.ptrModIDAC = &ptrWdgt->idacMod[0u];

                /* Get pointer to maximum Sense Clock Divider (column or row) */
                autoTuneConfig.ptrSenseClk = &ptrWdgt->snsClk;

                /* Set parasitic capacitance for columns */
                autoTuneConfig.sensorCap = cp;

                #if (CapSense_1_CSD_MATRIX_WIDGET_EN | CapSense_1_CSD_TOUCHPAD_WIDGET_EN)
                    if ((CapSense_1_WD_TOUCHPAD_E == (CapSense_1_WD_TYPE_ENUM)CapSense_1_dsFlash.wdgtArray[(wdgtIndex)].wdgtType) ||
                        (CapSense_1_WD_MATRIX_BUTTON_E == (CapSense_1_WD_TYPE_ENUM)CapSense_1_dsFlash.wdgtArray[(wdgtIndex)].wdgtType))

                    {
                        /* Set the minimum sense clock frequency to calculate the resolution */
                        if (ptrWdgt->snsClk < ptrWdgt->rowSnsClk)
                        {
                            /* Rewrite pointer to Sense Clock Divider for rows */
                            autoTuneConfig.ptrSenseClk = &ptrWdgt->rowSnsClk;

                            /* Set parasitic capacitance for rows */
                            autoTuneConfig.sensorCap = cpRow;
                        }
                    }
                #endif /* (CapSense_1_CSD_MATRIX_WIDGET_EN | CapSense_1_CSD_TOUCHPAD_WIDGET_EN) */

                /* Get finger capacitance */
                autoTuneConfig.fingerCap = ptrWdgt->fingerCap;

                /* Init pointer to sigPFC */
                autoTuneConfig.sigPFC = &ptrWdgt->sigPFC;

                #if (CapSense_1_CLK_SOURCE_PRSAUTO == CapSense_1_CSD_SNS_CLK_SOURCE)
                    CapSense_1_SsSetWidgetSenseClkSrc(wdgtIndex, ptrWdgt);
                #endif /* (CapSense_1_CLK_SOURCE_PRSAUTO == CapSense_1_CSD_SNS_CLK_SOURCE) */

                /* Calibrate CSD widget to 85% */
                #if (CapSense_1_ENABLE == CapSense_1_CSD2X_EN)
                    autoTuneStatus |=CapSense_1_CSD2XCalibrateWidget(wdgtIndex, CapSense_1_CSD_AUTOTUNE_CAL_LEVEL);
                #else
                    autoTuneStatus |= CapSense_1_CSDCalibrateWidget(wdgtIndex, CapSense_1_CSD_AUTOTUNE_CAL_LEVEL);
                #endif /* (CapSense_1_ENABLE == CapSense_1_CSD2X_EN) */

                /* Find resolution */
                ptrWdgt->resolution = SmartSense_TuneSensitivity(&autoTuneConfig);

                #if (CapSense_1_CLK_SOURCE_PRSAUTO == CapSense_1_CSD_SNS_CLK_SOURCE)
                    CapSense_1_SsSetWidgetSenseClkSrc(wdgtIndex, ptrWdgt);

                    #if (CapSense_1_CSD_MATRIX_WIDGET_EN | CapSense_1_CSD_TOUCHPAD_WIDGET_EN)
                        if (((uint8)CapSense_1_CLK_SOURCE_DIRECT == ptrWdgt->snsClkSource) ||
                            ((uint8)CapSense_1_CLK_SOURCE_DIRECT == ptrWdgt->rowSnsClkSource))
                        {
                            /* Recalibrate CSD widget to 85% because source is changed to direct */
                            #if (CapSense_1_ENABLE == CapSense_1_CSD2X_EN)
                                autoTuneStatus |= CapSense_1_CSD2XCalibrateWidget(wdgtIndex, CapSense_1_CSD_AUTOTUNE_CAL_LEVEL);
                            #else
                                autoTuneStatus |= CapSense_1_CSDCalibrateWidget(wdgtIndex, CapSense_1_CSD_AUTOTUNE_CAL_LEVEL);
                            #endif /* (CapSense_1_ENABLE == CapSense_1_CSD2X_EN) */
                        }
                    #else
                        if ((uint8)CapSense_1_CLK_SOURCE_DIRECT == ptrWdgt->snsClkSource)
                        {
                            /* Recalibrate CSD widget to 85% because source is changed to direct */
                            #if (CapSense_1_ENABLE == CapSense_1_CSD2X_EN)
                                autoTuneStatus |= CapSense_1_CSD2XCalibrateWidget(wdgtIndex, CapSense_1_CSD_AUTOTUNE_CAL_LEVEL);
                            #else
                                autoTuneStatus |= CapSense_1_CSDCalibrateWidget(wdgtIndex, CapSense_1_CSD_AUTOTUNE_CAL_LEVEL);
                            #endif /* (CapSense_1_ENABLE == CapSense_1_CSD2X_EN) */
                        }
                    #endif /* (CapSense_1_CSD_MATRIX_WIDGET_EN | CapSense_1_CSD_TOUCHPAD_WIDGET_EN) */
                #endif /* (CapSense_1_CLK_SOURCE_PRSAUTO == CapSense_1_CSD_SNS_CLK_SOURCE) */
                
                #if (CapSense_1_ENABLE == CapSense_1_TST_WDGT_CRC_EN)
                    CapSense_1_DsUpdateWidgetCrc(wdgtIndex);
                #endif /* (CapSense_1_ENABLE == CapSense_1_TST_WDGT_CRC_EN) */
            }
        }

        return autoTuneStatus;
    }
#endif /* (CapSense_1_CSD_SS_DIS != CapSense_1_CSD_AUTOTUNE)) */


#if (CapSense_1_DISABLE == CapSense_1_CSDV2)
    #if ((CapSense_1_ENABLE == CapSense_1_CSX_EN) || \
         (CapSense_1_IDAC_SINKING == CapSense_1_CSD_IDAC_CONFIG))
        /*******************************************************************************
        * Function Name: CapSense_1_SsTrimIdacsSinking
        ****************************************************************************//**
        *
        * \brief
        *  This function loads trim values from SFLASH rows to calibrate
        *  IDAC1 and IDAC2 for Sinking CSD Mode
        *
        * \details
        *  Function reads trim value from SFLASH and loads it into IDAC trim register.
        *  If Compensation IDAC is disabled the function loads trim values for IDAC1 only.
        *
        *******************************************************************************/
        static void CapSense_1_SsTrimIdacsSinking(void)
        {
            uint32 trimValue;

            #if (CapSense_1_ENABLE == CapSense_1_CSD2X_EN)

                /* iDAC0 Sinking Mode */
                trimValue = CY_GET_REG32(CapSense_1_CSD0_TRIM2_PTR) & ~CapSense_1_IDAC_TRIM2_MOD_SNK_MASK;
                trimValue |= ((uint32)CY_GET_REG8(CapSense_1_CSD0_SFLASH_TRIM2_PTR) &
                                                          CapSense_1_SFLASH_TRIM_IDAC_MOD_MASK) ;

                #if (CapSense_1_ENABLE == CapSense_1_CSD_IDAC_COMP_EN)
                    /* iDAC1 Sinking Mode */
                    trimValue &= ~CapSense_1_IDAC_TRIM2_COMP_SNK_MASK;
                    trimValue |= ((uint32)CY_GET_REG8(CapSense_1_CSD0_SFLASH_TRIM2_PTR) &
                                                              CapSense_1_SFLASH_TRIM_IDAC_COMP_MASK);
                #endif /* (CapSense_1_ENABLE == CapSense_1_CSD_IDAC_COMP_EN) */

                /* Update IDAC trim bits for gain control in current sink mode */
                CY_SET_REG32(CapSense_1_CSD0_TRIM2_PTR, trimValue);

                /* iDAC2 Sinking Mode */
                trimValue = CY_GET_REG32(CapSense_1_CSD1_TRIM2_PTR) & ~CapSense_1_IDAC_TRIM2_MOD_SNK_MASK;
                trimValue |= ((uint32)CY_GET_REG8(CapSense_1_CSD1_SFLASH_TRIM2_PTR) &
                                                          CapSense_1_SFLASH_TRIM_IDAC_MOD_MASK) ;

                #if (CapSense_1_ENABLE == CapSense_1_CSD_IDAC_COMP_EN)
                    /* iDAC3 Sinking Mode */
                    trimValue &= ~CapSense_1_IDAC_TRIM2_COMP_SNK_MASK;
                    trimValue |= ((uint32)CY_GET_REG8(CapSense_1_CSD1_SFLASH_TRIM2_PTR) &
                                                              CapSense_1_SFLASH_TRIM_IDAC_COMP_MASK);
                #endif /* (CapSense_1_ENABLE == CapSense_1_CSD_IDAC_COMP_EN) */

                /* Update IDAC trim bits for gain control in current sink mode */
                CY_SET_REG32(CapSense_1_CSD1_TRIM2_PTR, trimValue);

            #else

                /* Mod iDAC Sinking Mode */
                trimValue = CY_GET_REG32(CapSense_1_TRIM2_PTR) & ~CapSense_1_IDAC_TRIM2_MOD_SNK_MASK;
                trimValue |= ((uint32)CY_GET_REG8(CapSense_1_SFLASH_TRIM2_PTR) &
                                                          CapSense_1_SFLASH_TRIM_IDAC_MOD_MASK) ;

                #if (CapSense_1_ENABLE == CapSense_1_CSD_IDAC_COMP_EN)
                    /* Comp iDAC Sinking Mode */
                    trimValue &= ~CapSense_1_IDAC_TRIM2_COMP_SNK_MASK;
                    trimValue |= ((uint32)CY_GET_REG8(CapSense_1_SFLASH_TRIM2_PTR) &
                                                              CapSense_1_SFLASH_TRIM_IDAC_COMP_MASK);
                #endif /* (CapSense_1_ENABLE == CapSense_1_CSD_IDAC_COMP_EN) */

                /* Update IDAC trim bits for gain control in current sink mode */
                CY_SET_REG32(CapSense_1_TRIM2_PTR, trimValue);

            #endif /* (CapSense_1_ENABLE == CapSense_1_CSD2X_EN)) */
        }
    #endif /* ((CapSense_1_ENABLE == CapSense_1_CSX_EN) || \
               (CapSense_1_IDAC_SINKING == CapSense_1_CSD_IDAC_CONFIG)) */


    #if ((CapSense_1_ENABLE == CapSense_1_CSX_EN) || \
         (CapSense_1_IDAC_SOURCING == CapSense_1_CSD_IDAC_CONFIG))
        /*******************************************************************************
        * Function Name: CapSense_1_SsTrimIdacsSourcing
        ****************************************************************************//**
        *
        * \brief
        *  This function loads trim values from SFLASH rows to calibrate
        *  IDAC1 and IDAC2 for Sourcing CSD Mode
        *
        * \details
        *  Function reads trim value from SFLASH and loads it into IDAC trim register.
        *  If Compensation IDAC is disabled the function loads trim values for IDAC1 only.
        *
        *******************************************************************************/
        static void CapSense_1_SsTrimIdacsSourcing(void)
        {
            uint32 trimValue;

            #if (CapSense_1_ENABLE == CapSense_1_CSD2X_EN)

                /* iDAC0 Sourcing Mode */
                trimValue = CY_GET_REG32(CapSense_1_CSD0_TRIM1_PTR) & ~CapSense_1_IDAC_TRIM1_MOD_SRC_MASK;
                trimValue |= ((uint32)CY_GET_REG8(CapSense_1_CSD0_SFLASH_TRIM1_PTR) &
                                                          CapSense_1_SFLASH_TRIM_IDAC_MOD_MASK);

                #if (CapSense_1_ENABLE == CapSense_1_CSD_IDAC_COMP_EN)
                     /* iDAC1 Sourcing Mode */
                    trimValue &= ~CapSense_1_IDAC_TRIM1_COMP_SRC_MASK;
                    trimValue |= ((uint32)CY_GET_REG8(CapSense_1_CSD0_SFLASH_TRIM1_PTR) &
                                                              CapSense_1_SFLASH_TRIM_IDAC_COMP_MASK);
                #endif /* (CapSense_1_ENABLE == CapSense_1_CSD_IDAC_COMP_EN) */

                /* Update IDAC trim bits for gain control in current source mode */
                CY_SET_REG32(CapSense_1_CSD0_TRIM1_PTR, trimValue);

                /* iDAC2 Sourcing Mode */
                trimValue = CY_GET_REG32(CapSense_1_CSD1_TRIM1_PTR) & ~CapSense_1_IDAC_TRIM1_MOD_SRC_MASK;
                trimValue |= ((uint32)CY_GET_REG8(CapSense_1_CSD1_SFLASH_TRIM1_PTR) &
                                                          CapSense_1_SFLASH_TRIM_IDAC_MOD_MASK);

                #if (CapSense_1_ENABLE == CapSense_1_CSD_IDAC_COMP_EN)
                     /* iDAC3 Sourcing Mode */
                    trimValue &= ~CapSense_1_IDAC_TRIM1_COMP_SRC_MASK;
                    trimValue |= ((uint32)CY_GET_REG8(CapSense_1_CSD1_SFLASH_TRIM1_PTR) &
                                                              CapSense_1_SFLASH_TRIM_IDAC_COMP_MASK);
                #endif /* (CapSense_1_ENABLE == CapSense_1_CSD_IDAC_COMP_EN) */

                /* Update IDAC trim bits for gain control in current source mode */
                CY_SET_REG32(CapSense_1_CSD1_TRIM1_PTR, trimValue);

            #else

                /* Mod iDAC Sourcing Mode */
                trimValue = CY_GET_REG32(CapSense_1_TRIM1_PTR) & ~CapSense_1_IDAC_TRIM1_MOD_SRC_MASK;
                trimValue |= ((uint32)CY_GET_REG8(CapSense_1_SFLASH_TRIM1_PTR) &
                                                          CapSense_1_SFLASH_TRIM_IDAC_MOD_MASK);

                #if (CapSense_1_ENABLE == CapSense_1_CSD_IDAC_COMP_EN)
                     /* Comp iDAC Sourcing Mode */
                    trimValue &= ~CapSense_1_IDAC_TRIM1_COMP_SRC_MASK;
                    trimValue |= ((uint32)CY_GET_REG8(CapSense_1_SFLASH_TRIM1_PTR) &
                                                              CapSense_1_SFLASH_TRIM_IDAC_COMP_MASK);
                #endif /* (CapSense_1_ENABLE == CapSense_1_CSD_IDAC_COMP_EN) */

                /* Update IDAC trim bits for gain control in current source mode */
                CY_SET_REG32(CapSense_1_TRIM1_PTR, trimValue);

            #endif /* (CapSense_1_ENABLE == CapSense_1_CSD2X_EN) */
        }
    #endif /* ((CapSense_1_ENABLE == CapSense_1_CSX_EN) || \
               (CapSense_1_IDAC_SOURCING == CapSense_1_CSD_IDAC_CONFIG)) */


    /*******************************************************************************
    * Function Name: CapSense_1_SsTrimIdacs
    ****************************************************************************//**
    *
    * \brief
    *  This function loads trim values from SFLASH rows to calibrate
    *  IDAC1 and IDAC2 for CSD Mode
    *
    * \details
    *  If CSX mode is enabled the function loads trim values for both sink and source
    *  mode. If CSX mode is disabled the function loads trim values for sink or
    *  source mode based on sink/source mode configuration.
    *  If Compensation IDAC is disabled the function loads trim values for IDAC1 only.
    *
    *******************************************************************************/
    static void CapSense_1_SsTrimIdacs(void)
    {
        #if (CapSense_1_ENABLE == CapSense_1_CSX_EN)
            CapSense_1_SsTrimIdacsSinking();
            CapSense_1_SsTrimIdacsSourcing();
        #elif (CapSense_1_IDAC_SINKING == CapSense_1_CSD_IDAC_CONFIG)
            CapSense_1_SsTrimIdacsSinking();
        #elif (CapSense_1_IDAC_SOURCING == CapSense_1_CSD_IDAC_CONFIG)
            CapSense_1_SsTrimIdacsSourcing();
        #else
            #error "Not supported Mode, component cannot work in this mode"
        #endif /* (CapSense_1_ENABLE == CapSense_1_CSX_EN) */
    }
#endif  /* (CapSense_1_DISABLE == CapSense_1_CSDV2) */


#if (CapSense_1_ENABLE == CapSense_1_MULTI_FREQ_SCAN_EN)
    /*******************************************************************************
    * Function Name: CapSense_1_SsChangeImoFreq
    ****************************************************************************//**
    *
    * \brief
    *  This function changes the IMO frequency.
    *
    * \details
    *   The IMO frequency can have three offsets: 0%, -5% and +5%. The frequency
    *   trims are contained in the CapSense_1_immunity[value] array for each
    *   frequency channel.
    *
    * \param value The frequency channel ID.
    *
    *******************************************************************************/
    void CapSense_1_SsChangeImoFreq(uint32 value)
    {
        CY_SET_REG32(CY_SYS_CLK_IMO_TRIM1_PTR, CapSense_1_immunity[value]);
    }
#endif  /* (CapSense_1_ENABLE == CapSense_1_MULTI_FREQ_SCAN_EN) */


#if((CapSense_1_ENABLE == CapSense_1_CSD_EN) ||\
    (CapSense_1_ENABLE == CapSense_1_CSD2X_EN) ||\
    ((CapSense_1_ENABLE == CapSense_1_CSX_EN) && (CapSense_1_ENABLE == CapSense_1_CSDV2)))
/*******************************************************************************
* Function Name: CapSense_1_SsInitializeSourceSenseClk
****************************************************************************//**
*
* \brief
*  Sets a source for Sense Clk for all CSD widgets.
*
* \details
*  Updates snsClkSource and rowSnsClkSource with a source for the sense Clk.
*  for all CSD widgets.
*
*******************************************************************************/
void CapSense_1_SsInitializeSourceSenseClk(void)
{
    uint32 wdgtIndex;
    CapSense_1_RAM_WD_BASE_STRUCT *ptrWdgt;

    for (wdgtIndex = 0u; wdgtIndex < CapSense_1_TOTAL_WIDGETS; wdgtIndex++)
    {
        ptrWdgt = (CapSense_1_RAM_WD_BASE_STRUCT *)CapSense_1_dsFlash.wdgtArray[wdgtIndex].ptr2WdgtRam;
        if (CapSense_1_SENSE_METHOD_CSD_E ==
        CapSense_1_GET_SENSE_METHOD(&CapSense_1_dsFlash.wdgtArray[wdgtIndex]))
        {
            #if ((CapSense_1_ENABLE == CapSense_1_CSD_EN) || (CapSense_1_ENABLE == CapSense_1_CSD2X_EN))
                CapSense_1_SsSetWidgetSenseClkSrc(wdgtIndex, ptrWdgt);
            #endif /* ((CapSense_1_ENABLE == CapSense_1_CSD_EN) || CapSense_1_ENABLE == CapSense_1_CSD2X_EN)) */
        }
        else
        {
            #if ((CapSense_1_ENABLE == CapSense_1_CSX_EN) && (CapSense_1_ENABLE == CapSense_1_CSDV2))
                CapSense_1_SsSetWidgetTxClkSrc(wdgtIndex, ptrWdgt);
            #endif /* ((CapSense_1_ENABLE == CapSense_1_CSX_EN) && (CapSense_1_ENABLE == CapSense_1_CSDV2)) */
        }
        #if (CapSense_1_ENABLE == CapSense_1_TST_WDGT_CRC_EN)
            CapSense_1_DsUpdateWidgetCrc(wdgtIndex);
        #endif /* (CapSense_1_ENABLE == CapSense_1_TST_WDGT_CRC_EN) */
    }
}
#endif /* ((CapSense_1_ENABLE == CapSense_1_CSD_EN) ||\
           (CapSense_1_ENABLE == CapSense_1_CSD2X_EN) ||\
           ((CapSense_1_ENABLE == CapSense_1_CSX_EN) && (CapSense_1_ENABLE == CapSense_1_CSDV2))) */


#if ((CapSense_1_ENABLE == CapSense_1_CSD_EN) ||\
     (CapSense_1_ENABLE == CapSense_1_CSD2X_EN))
    /*******************************************************************************
    * Function Name: CapSense_1_SsSetWidgetSenseClkSrc
    ****************************************************************************//**
    *
    * \brief
    *  Sets a source for the sense clock for a widget.
    *
    * \param wdgtIndex
    *   Specifies the ID of the widget.
    * \param ptrWdgt
    *   The pointer to the RAM_WD_BASE_STRUCT structure.
    *
    * \details
    *  Updates snsClkSource and rowSnsClkSource with a source for the sense Clk for a
    *  widget.
    *
    *******************************************************************************/
    static void CapSense_1_SsSetWidgetSenseClkSrc(uint32 wdgtIndex, CapSense_1_RAM_WD_BASE_STRUCT * ptrWdgt)
    {
        uint8 lfsrSize;
        uint8 lfsrScale;

        #if(CapSense_1_CLK_SOURCE_PRSAUTO == CapSense_1_CSD_SNS_CLK_SOURCE)
            #if(CapSense_1_ENABLE == CapSense_1_CSDV2)
                uint32 conversionsNum;
            #endif /* (CapSense_1_ENABLE == CapSense_1_CSDV2) */
            uint32 snsClkDivider;
        #endif /* (CapSense_1_CLK_SOURCE_PRSAUTO == CapSense_1_CSD_SNS_CLK_SOURCE) */

        #if(CapSense_1_CLK_SOURCE_PRSAUTO == CapSense_1_CSD_SNS_CLK_SOURCE)
            snsClkDivider = CapSense_1_SsCSDGetColSnsClkDivider(wdgtIndex);

            #if(CapSense_1_ENABLE == CapSense_1_CSDV2)
                conversionsNum = CapSense_1_SsCSDGetNumberOfConversions(snsClkDivider, (uint32)ptrWdgt->resolution,
                                                                                             CapSense_1_CLK_SOURCE_DIRECT);
                lfsrSize = CapSense_1_SsCalcLfsrSize(snsClkDivider, conversionsNum);
                if (CapSense_1_CLK_SOURCE_DIRECT == lfsrSize)
                {
                    lfsrSize = CapSense_1_SsCSDCalcPrsSize(snsClkDivider, (uint32)ptrWdgt->resolution);
                }
                lfsrScale = CapSense_1_SsCalcLfsrScale(snsClkDivider, lfsrSize);
            #else
                lfsrSize = CapSense_1_SsCSDCalcPrsSize(snsClkDivider, (uint32)ptrWdgt->resolution);
                lfsrScale = 0u;
            #endif /* (CapSense_1_ENABLE == CapSense_1_CSDV2) */
        #else
            lfsrSize = (uint8)CapSense_1_DEFAULT_MODULATION_MODE;
            lfsrScale = 0u;
            (void)wdgtIndex; /* This parameter is unused in such configurations */
        #endif /* (CapSense_1_CLK_SOURCE_PRSAUTO == CapSense_1_CSD_SNS_CLK_SOURCE) */

        ptrWdgt->snsClkSource = lfsrSize | (uint8)(lfsrScale << CapSense_1_CLK_SOURCE_LFSR_SCALE_OFFSET);

        #if (CapSense_1_ENABLE == (CapSense_1_CSD_MATRIX_WIDGET_EN | CapSense_1_CSD_TOUCHPAD_WIDGET_EN))
            if ((CapSense_1_WD_TOUCHPAD_E == (CapSense_1_WD_TYPE_ENUM)CapSense_1_dsFlash.wdgtArray[wdgtIndex].wdgtType) ||
                (CapSense_1_WD_MATRIX_BUTTON_E == (CapSense_1_WD_TYPE_ENUM)CapSense_1_dsFlash.wdgtArray[wdgtIndex].wdgtType))
            {
                #if(CapSense_1_CLK_SOURCE_PRSAUTO == CapSense_1_CSD_SNS_CLK_SOURCE)
                    snsClkDivider = CapSense_1_SsCSDGetRowSnsClkDivider(wdgtIndex);

                    #if(CapSense_1_ENABLE == CapSense_1_CSDV2)
                        lfsrSize = CapSense_1_SsCalcLfsrSize(snsClkDivider, conversionsNum);
                        if (CapSense_1_CLK_SOURCE_DIRECT == lfsrSize)
                        {
                            lfsrSize = CapSense_1_SsCSDCalcPrsSize(snsClkDivider, (uint32)ptrWdgt->resolution);
                        }
                        lfsrScale = CapSense_1_SsCalcLfsrScale(snsClkDivider, lfsrSize);
                    #else
                        lfsrSize = CapSense_1_SsCSDCalcPrsSize(snsClkDivider, (uint32)ptrWdgt->resolution);
                        lfsrScale = 0u;
                    #endif /* (CapSense_1_ENABLE == CapSense_1_CSDV2) */
                #else
                    lfsrSize = (uint8)CapSense_1_DEFAULT_MODULATION_MODE;
                    lfsrScale = 0u;
                #endif /* (CapSense_1_CLK_SOURCE_PRSAUTO == CapSense_1_CSD_SNS_CLK_SOURCE) */
                ptrWdgt->rowSnsClkSource = lfsrSize | (uint8)(lfsrScale << CapSense_1_CLK_SOURCE_LFSR_SCALE_OFFSET);
            }
        #endif /* (CapSense_1_ENABLE == (CapSense_1_CSD_MATRIX_WIDGET_EN | CapSense_1_CSD_TOUCHPAD_WIDGET_EN)) */
    }
#endif /* ((CapSense_1_ENABLE == CapSense_1_CSD_EN) ||\
           (CapSense_1_ENABLE == CapSense_1_CSD2X_EN))*/


#if ((CapSense_1_ENABLE == CapSense_1_CSX_EN) && (CapSense_1_ENABLE == CapSense_1_CSDV2))
    /*******************************************************************************
    * Function Name: CapSense_1_SsSetWidgetTxClkSrc
    ****************************************************************************//**
    *
    * \brief
    *  Sets a source for the Tx clock for a widget.
    *
    * \param wdgtIndex
    *   Specifies the ID of the widget.
    * \param ptrWdgt
    *   The pointer to the RAM_WD_BASE_STRUCT structure.
    *
    * \details
    *  Updates snsClkSourcewith with a source for Tx Clk for a widget.
    *
    *******************************************************************************/
    static void CapSense_1_SsSetWidgetTxClkSrc(uint32 wdgtIndex, CapSense_1_RAM_WD_BASE_STRUCT * ptrWdgt)
    {
        uint8 lfsrSize;
        uint8 lfsrScale;

        #if(CapSense_1_CLK_SOURCE_PRSAUTO == CapSense_1_CSX_TX_CLK_SOURCE)
            uint32 conversionsNum;
            uint32 snsClkDivider;
        #endif /* (CapSense_1_CLK_SOURCE_PRSAUTO == CapSense_1_CSX_TX_CLK_SOURCE) */

        #if(CapSense_1_CLK_SOURCE_PRSAUTO == CapSense_1_CSX_TX_CLK_SOURCE)
            conversionsNum = (uint32)ptrWdgt->resolution;
            snsClkDivider = CapSense_1_SsCSXGetTxClkDivider(wdgtIndex);
            lfsrSize = CapSense_1_SsCalcLfsrSize(snsClkDivider, conversionsNum);
            lfsrScale = CapSense_1_SsCalcLfsrScale(snsClkDivider, lfsrSize);
        #else
            lfsrSize = (uint8)CapSense_1_CSX_TX_CLK_SOURCE;
            lfsrScale = 0u;
        #endif /* (CapSense_1_CLK_SOURCE_PRSAUTO == CapSense_1_CSX_TX_CLK_SOURCE) */

        ptrWdgt->snsClkSource = lfsrSize | (uint8)(lfsrScale << CapSense_1_CLK_SOURCE_LFSR_SCALE_OFFSET);
    }
#endif /* ((CapSense_1_ENABLE == CapSense_1_CSX_EN) && (CapSense_1_ENABLE == CapSense_1_CSDV2)) */


#if(((CapSense_1_ENABLE == CapSense_1_CSX_EN) && \
     (CapSense_1_ENABLE == CapSense_1_CSDV2) && \
     (CapSense_1_CLK_SOURCE_PRSAUTO == CapSense_1_CSX_TX_CLK_SOURCE)) ||\
    ((CapSense_1_ENABLE == CapSense_1_CSD_EN) && \
     (CapSense_1_ENABLE == CapSense_1_CSDV2) && \
     (CapSense_1_CLK_SOURCE_PRSAUTO == CapSense_1_CSD_SNS_CLK_SOURCE)))
/*******************************************************************************
* Function Name: CapSense_1_SsCSDCalcLfsr
****************************************************************************//**
*
* \brief
*   This is an internal function that finds a SSC polynomial size in the Auto mode.
*
* \details
*   The SSC polynomial size in the auto mode is found based on the following
*   requirements:
*   - an LFSR value should be selected so that the max clock dither is limited with +/-10%.
*   - at least one full spread spectrum polynomial should pass during the scan time.
*   - the value of the number of conversions should be an integer multiple of the
*     repeat period of the programmed LFSR_SIZE.
*
* \param
*  snsClkDivider The divider value for the sense clock.
*  resolution The widget resolution.
*
* \return lfsrSize The LFSRSIZE value for the SENSE_PERIOD register.
*
*******************************************************************************/
static CY_INLINE  uint8 CapSense_1_SsCalcLfsrSize(uint32 snsClkDivider, uint32 conversionsNum)
{
    uint8 lfsrSize = 0u;

    /* Find LFSR value */
    if((CapSense_1_SNSCLK_SSC4_THRESHOLD <= snsClkDivider) &&
       (CapSense_1_SNSCLK_SSC4_PERIOD <= conversionsNum) &&
       (0uL == (conversionsNum % CapSense_1_SNSCLK_SSC4_PERIOD)))
    {
        lfsrSize = CapSense_1_CLK_SOURCE_SSC4;
    }
    else if((CapSense_1_SNSCLK_SSC3_THRESHOLD <= snsClkDivider) &&
            (CapSense_1_SNSCLK_SSC3_PERIOD <= conversionsNum) &&
            (0uL == (conversionsNum % CapSense_1_SNSCLK_SSC3_PERIOD)))
    {
        lfsrSize = CapSense_1_CLK_SOURCE_SSC3;
    }
    else if((CapSense_1_SNSCLK_SSC2_THRESHOLD <= snsClkDivider) &&
            (CapSense_1_SNSCLK_SSC2_PERIOD <= conversionsNum) &&
            (0uL == (conversionsNum % CapSense_1_SNSCLK_SSC2_PERIOD)))
    {
        lfsrSize = CapSense_1_CLK_SOURCE_SSC2;
    }
    else if((CapSense_1_SNSCLK_SSC1_THRESHOLD <= snsClkDivider) &&
            (CapSense_1_SNSCLK_SSC1_PERIOD <= conversionsNum) &&
            (0uL == (conversionsNum % CapSense_1_SNSCLK_SSC1_PERIOD)))
    {
        lfsrSize = CapSense_1_CLK_SOURCE_SSC1;
    }
    else
    {
        lfsrSize = (uint8)CapSense_1_CLK_SOURCE_DIRECT;
    }

    return (lfsrSize);
}


/*******************************************************************************
* Function Name: CapSense_1_SsCSDCalcLfsr
****************************************************************************//**
*
* \brief
*   This is an internal function that calculates the LFSR scale value.
*
* \details
*   The LFSR scale value is used to increase the clock dither if the desired dither
*   is wider than can be achieved with the current Sense Clock Divider and current LFSR
*   period.
*
*   This returns the LFSR scale value needed to keep the clock dither in
*   range +/-10%.
*
* \param
*  snsClkDivider The divider value for the sense clock.
*  lfsrSize The period of the LFSR sequence.
*           For devices with CapSense_1_CSDV2_REF9P6UA_EN = TRUE, the
*           mode parameters can take the following values:
*           CapSense_1_CLK_SOURCE_DIRECT The spreadspectrum is not used.
*           CapSense_1_CLK_SOURCE_SSC1   The length of LFSR sequence is 63 cycles.
*           CapSense_1_CLK_SOURCE_SSC2   The length of LFSR sequence is 127 cycles.
*           CapSense_1_CLK_SOURCE_SSC3   The length of LFSR sequence is 255 cycles.
*           CapSense_1_CLK_SOURCE_SSC4   The length of LFSR sequence is 511 cycles.
*
*           For devices with CapSense_1_CSDV2_REF9P6UA_EN = TRUE, the
*           mode parameters can take the following values:
*           CapSense_1_CLK_SOURCE_DIRECT The spreadspectrum is not used.
*           CapSense_1_CLK_SOURCE_SSC1   The length of LFSR sequence is 3 cycles.
*           CapSense_1_CLK_SOURCE_SSC2   The length of LFSR sequence is 7 cycles.
*           CapSense_1_CLK_SOURCE_SSC3   The length of LFSR sequence is 15 cycles.
*           CapSense_1_CLK_SOURCE_SSC4   The length of LFSR sequence is 31 cycles.
*
* \return The LFSR scale value needed to keep the clock dither in range +/-10%.
*
*******************************************************************************/
static CY_INLINE uint8 CapSense_1_SsCalcLfsrScale(uint32 snsClkDivider, uint8 lfsrSize)
{
    uint32 lfsrScale;
    uint32 lfsrRange;
    uint32 lfsrDither;

    /* Initialize the lfsrSize variable with the LFSR Range for given Lfsr Size. */
    switch(lfsrSize)
    {
        case CapSense_1_CLK_SOURCE_SSC1:
        {
            lfsrRange = CapSense_1_SNSCLK_SSC1_RANGE;
            break;
        }
        case CapSense_1_CLK_SOURCE_SSC2:
        {
            lfsrRange = CapSense_1_SNSCLK_SSC2_RANGE;
            break;
        }
        case CapSense_1_CLK_SOURCE_SSC3:
        {
            lfsrRange = CapSense_1_SNSCLK_SSC3_RANGE;
            break;
        }
        case CapSense_1_CLK_SOURCE_SSC4:
        {
            lfsrRange = CapSense_1_SNSCLK_SSC4_RANGE;
            break;
        }
        default:
        {
            lfsrRange = 0u;
            break;
        }
    }

    /* Calculate the LFSR Scale value that is required to keep the Clock dither
     * as close as possible to the +/-10% limit of the used frequency.
     */
    if((lfsrSize != CapSense_1_CLK_SOURCE_DIRECT) && (0u != lfsrRange))
    {
        /* Calculate the LFSR Dither in percents. */
        lfsrDither  = ((lfsrRange * 100uL) / snsClkDivider);
        lfsrScale = 0uL;
        
        while(lfsrDither < CapSense_1_LFSR_DITHER_PERCENTAGE)
        {
            lfsrScale++;
            lfsrDither <<=1uL;
        }

        if(lfsrDither > CapSense_1_LFSR_DITHER_PERCENTAGE)
        {
            lfsrScale--;
        }
    }
    else
    {
        lfsrScale = 0uL;
    }

    return ((uint8)lfsrScale);
}
#endif /* (((CapSense_1_ENABLE == CapSense_1_CSX_EN) &&  \
            (CapSense_1_ENABLE == CapSense_1_CSDV2) &&  \
            (CapSense_1_CLK_SOURCE_PRSAUTO == CapSense_1_CSX_TX_CLK_SOURCE)) ||\
          ((CapSense_1_ENABLE == CapSense_1_CSD_EN) &&  \
           (CapSense_1_ENABLE == CapSense_1_CSDV2) &&  \
           (CapSense_1_CLK_SOURCE_PRSAUTO == CapSense_1_CSD_SNS_CLK_SOURCE))) */


#if ((CapSense_1_ENABLE == CapSense_1_CSD_EN) ||\
    (CapSense_1_ENABLE == CapSense_1_CSD2X_EN))
    /*******************************************************************************
    * Function Name: CapSense_1_SsClearCSDSensors
    ****************************************************************************//**
    *
    * \brief
    *  Resets all the CSD sensors to the non-sampling state by sequentially
    *  disconnecting all the sensors from the Analog MUX bus and putting them to
    *  an inactive state.
    *
    * \details
    *   The function goes through all the widgets and updates appropriate bits in
    *   the IO HSIOM, PC and DR registers depending on the Inactive sensor connection
    *   parameter. DR register bits are set to zero when the Inactive sensor
    *   connection is Ground or Hi-Z.
    *
    *******************************************************************************/
    void CapSense_1_SsClearCSDSensors(void)
    {
        uint32 wdgtIndex;
        uint32 snsIndex;

        #if (CapSense_1_ENABLE == CapSense_1_CSD_GANGED_SNS_EN)
            uint32 pinIndex;
        #endif /* (CapSense_1_ENABLE == CapSense_1_CSD_GANGED_SNS_EN)  */

        #if (CapSense_1_ENABLE == CapSense_1_CSD_GANGED_SNS_EN)
            /* Declare ptr to sensor IO structure */
            CapSense_1_FLASH_IO_STRUCT const *curDedicatedSnsIOPtr;
            /*  Pointer to Flash structure holding info of sensor to be scanned  */
            CapSense_1_FLASH_SNS_STRUCT const *curFlashSnsPtr;
        #endif /* (CapSense_1_ENABLE == CapSense_1_CSD_GANGED_SNS_EN)  */
        CapSense_1_FLASH_IO_STRUCT const *curSnsIOPtr;

        for (wdgtIndex = 0u; wdgtIndex < CapSense_1_TOTAL_WIDGETS; wdgtIndex++)
        {
            if (CapSense_1_SENSE_METHOD_CSD_E ==
                CapSense_1_GET_SENSE_METHOD(&CapSense_1_dsFlash.wdgtArray[wdgtIndex]))
            {
                curSnsIOPtr = (CapSense_1_FLASH_IO_STRUCT const *)
                                                CapSense_1_dsFlash.wdgtArray[wdgtIndex].ptr2SnsFlash;

                /* Go through all sensors in widget */
                for (snsIndex = 0u; snsIndex < (uint8)CapSense_1_dsFlash.wdgtArray[(wdgtIndex)].totalNumSns; snsIndex++)
                {
                    #if (CapSense_1_ENABLE == CapSense_1_CSD_GANGED_SNS_EN)
                        /* Check ganged sns flag  */
                        if (CapSense_1_GANGED_SNS_MASK == (CapSense_1_dsFlash.wdgtArray[wdgtIndex].staticConfig &
                                                                 CapSense_1_GANGED_SNS_MASK))
                        {
                            /* Get sns pointer */
                            curFlashSnsPtr = (CapSense_1_FLASH_SNS_STRUCT const *)
                                                               CapSense_1_dsFlash.wdgtArray[wdgtIndex].ptr2SnsFlash +
                                                               snsIndex;

                            for(pinIndex = 0u; pinIndex < curFlashSnsPtr->numPins; pinIndex++)
                            {
                                /* Get IO pointer for dedicated pin */
                                curDedicatedSnsIOPtr = &CapSense_1_ioList[curFlashSnsPtr->firstPinId + pinIndex];

                                /* Disconnect dedicated pin */
                                CapSense_1_CSDDisconnectSns(curDedicatedSnsIOPtr);
                            }
                        }
                        else
                        {
                            /* Disable sensor */
                            CapSense_1_CSDDisconnectSns(&curSnsIOPtr[snsIndex]);
                        }
                    #else
                        /* Disable sensor */
                        CapSense_1_CSDDisconnectSns(&curSnsIOPtr[snsIndex]);
                    #endif /* (CapSense_1_ENABLE == CapSense_1_CSD_GANGED_SNS_EN)  */
                }
            }
        }
    }

    /*******************************************************************************
    * Function Name: CapSense_1_SsCSDGetColSnsClkDivider
    ****************************************************************************//**
    *
    * \brief
    *  This function gets the Sense Clock Divider value for one-dimension widgets
    *  and Column Sense Clock divider value for two-dimension widgets.
    *
    * \details
    *  This function gets the Sense Clock Divider value based on the component
    *  configuration. The function is applicable for one-dimension widgets and for
    *  two-dimension widgets.
    *
    * \param
    *  wdgtIndex Specifies the ID of the widget.
    *
    * \return The Sense Clock Divider value for one-dimension widgets
    *         and the Column Sense Clock divider value for two-dimension widgets.
    *
    *******************************************************************************/
    uint32 CapSense_1_SsCSDGetColSnsClkDivider(uint32 wdgtIndex)
    {
        uint32 retVal;

        /* Get sense divider based on configuration */
        #if (CapSense_1_ENABLE != CapSense_1_CSD_COMMON_SNS_CLK_EN)
            CapSense_1_RAM_WD_BASE_STRUCT *ptrWdgt;

            ptrWdgt = (CapSense_1_RAM_WD_BASE_STRUCT *)
            CapSense_1_dsFlash.wdgtArray[wdgtIndex].ptr2WdgtRam;

            retVal = (uint32)(ptrWdgt->snsClk);
        #else
            retVal = (uint32)CapSense_1_dsRam.snsCsdClk;

            (void)wdgtIndex; /* This parameter is unused in such configurations */
        #endif /* (CapSense_1_ENABLE == CapSense_1_CSD_COMMON_SNS_CLK_EN) */

        return (retVal);
    }


    #if (CapSense_1_ENABLE == (CapSense_1_CSD_MATRIX_WIDGET_EN | CapSense_1_CSD_TOUCHPAD_WIDGET_EN))
        /*******************************************************************************
        * Function Name: CapSense_1_SsCSDGetRowSnsClkDivider
        ****************************************************************************//**
        *
        * \brief
        *  This function gets the Sense Clock Divider value for one-dimension widgets
        *  and the Column Sense Clock divider value for two-dimension widgets.
        *
        * \details
        *  This function gets the Sense Clock Divider value based on the component
        *  configuration. The function is applicable for one-dimension widgets and for
        *  two-dimension widgets.
        *
        * \param
        *  wdgtIndex Specifies the ID of the widget.
        *
        * \return The Sense Clock Divider value for one-dimension widgets
        *         and Column Sense Clock divider value for two-dimension widgets.
        *
        *******************************************************************************/
        uint32 CapSense_1_SsCSDGetRowSnsClkDivider(uint32 wdgtIndex)
        {
            uint32 retVal;

            /* Get sense divider based on configuration */
            #if (CapSense_1_ENABLE != CapSense_1_CSD_COMMON_SNS_CLK_EN)
                CapSense_1_RAM_WD_BASE_STRUCT *ptrWdgt;

                ptrWdgt = (CapSense_1_RAM_WD_BASE_STRUCT *)
                CapSense_1_dsFlash.wdgtArray[wdgtIndex].ptr2WdgtRam;

                retVal = ptrWdgt->rowSnsClk;
            #else
                retVal = (uint32)CapSense_1_dsRam.snsCsdClk;

                (void)wdgtIndex; /* This parameter is unused in such configurations */
            #endif /* (CapSense_1_ENABLE == CapSense_1_CSD_COMMON_SNS_CLK_EN) */

            return (retVal);
        }
    #endif /* (CapSense_1_ENABLE == (CapSense_1_CSD_MATRIX_WIDGET_EN | CapSense_1_CSD_TOUCHPAD_WIDGET_EN)) */

    #if (CapSense_1_CLK_SOURCE_PRSAUTO == CapSense_1_CSD_SNS_CLK_SOURCE)
        /*******************************************************************************
        * Function Name: CapSense_1_SsCSDCalcPrsSize
        ****************************************************************************//**
        *
        * \brief
        *   The function finds PRS polynomial size in the Auto mode.
        *
        * \details
        *   The PRS polynomial size in the Auto mode is found based on the following
        *   requirements:
        *   - at least one full spread spectrum polynomial should pass during scan time.
        *
        * \param
        *  snsClkDivider The divider value for the sense clock.
        *  resolution The widget resolution.
        *
        * \return prsSize PRS value for SENSE_PERIOD register.
        *
        *******************************************************************************/
        uint8 CapSense_1_SsCSDCalcPrsSize(uint32 snsClkDivider, uint32 resolution)
        {
            uint32 prsSize;
            uint32 modClkDivider;

            #if (CapSense_1_ENABLE == CapSense_1_CSDV2)
                modClkDivider = 1uL;
            #else
                #if (CapSense_1_ENABLE == CapSense_1_IS_M0S8PERI_BLOCK)
                    modClkDivider = (uint32)CapSense_1_dsRam.modCsdClk;
                #else
                    modClkDivider = 1uL;
                #endif /* (CapSense_1_ENABLE == CapSense_1_IS_M0S8PERI_BLOCK) */
            #endif /* (CapSense_1_ENABLE == CapSense_1_CSDV2) */

            if ((snsClkDivider * CapSense_1_PRS_LENGTH_12_BITS) <
                (modClkDivider * ((0x00000001Lu << resolution) - 1u)))
            {
                /* Set PRS12 mode */
                prsSize = CapSense_1_PRS_12_CONFIG;
            }
            else if ((snsClkDivider * CapSense_1_PRS_LENGTH_8_BITS) <
                     (modClkDivider * ((0x00000001Lu << resolution) - 1u)))
            {
                /* Set PRS8 mode */
                prsSize = CapSense_1_PRS_8_CONFIG;
            }
            else
            {
                /* Set Direct clock mode */
                prsSize = CapSense_1_CLK_SOURCE_DIRECT;
            }

            return (uint8)prsSize;
        }
    #endif /* (CapSense_1_CLK_SOURCE_PRSAUTO == CapSense_1_CSD_SNS_CLK_SOURCE) */
#endif /* ((CapSense_1_ENABLE == CapSense_1_CSD_EN) ||\
           (CapSense_1_ENABLE == CapSense_1_CSD2X_EN)) */


/* [] END OF FILE */
