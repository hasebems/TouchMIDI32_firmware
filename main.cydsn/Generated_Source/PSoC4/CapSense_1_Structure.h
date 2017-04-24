/***************************************************************************//**
* \file CapSense_1_Structure.h
* \version 3.10
*
* \brief
*   This file provides the top level declarations of the component data structure.
*   Also, the file declares the high-level and low-level APIs for data access.
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

#if !defined(CY_CAPSENSE_CapSense_1_STRUCTURE_H)
#define CY_CAPSENSE_CapSense_1_STRUCTURE_H

#include <cytypes.h>
#include "CapSense_1_Configuration.h"
#if (CapSense_1_CSD_SS_DIS != CapSense_1_CSD_AUTOTUNE)
    #include "CapSense_1_SmartSense_LL.h"
#endif  /* (CapSense_1_CSD_SS_DIS != CapSense_1_CSD_AUTOTUNE) */

/*******************************************************************************
* Constant Definitions
*******************************************************************************/

/* Defines size of Sensor Status Register in Data Structure */
#define CapSense_1_SNS_STS_TYPE               uint8

/* No touch condition for slider position report */
#define CapSense_1_SLIDER_NO_TOUCH            (0xFFFFu)
#define CapSense_1_TOUCHPAD_NO_TOUCH          (0xFFFFFFFFLu)

#define CapSense_1_SLIDER_POS_NONE            (0xFFFFu)
#define CapSense_1_TOUCHPAD_POS_NONE          (0xFFFFu)

#define CapSense_1_MATRIX_POS_NONE            (0xFFu)
#define CapSense_1_MATRIX_POS_MULTI           (0xFEu)

#define CapSense_1_PROX_STS_MASK              (3Lu)
#define CapSense_1_PROX_STS_OFFSET(proxId)    ((proxId) << 1u)
    
#define CapSense_1_MATRIX_BUTTONS_TOUCHED     (0x80000000Lu)

/*******************************************************************************
* Enumeration types definition
*******************************************************************************/

/***************************************************************************//**
* \brief Defines widget types
*******************************************************************************/
typedef enum
{
    CapSense_1_WD_BUTTON_E            = 0x01u,
    CapSense_1_WD_LINEAR_SLIDER_E     = 0x02u,
    CapSense_1_WD_RADIAL_SLIDER_E     = 0x03u,
    CapSense_1_WD_MATRIX_BUTTON_E     = 0x04u,
    CapSense_1_WD_TOUCHPAD_E          = 0x05u,
    CapSense_1_WD_PROXIMITY_E         = 0x06u
} CapSense_1_WD_TYPE_ENUM;


/***************************************************************************//**
* \brief Defines sensing methods types
*******************************************************************************/
typedef enum
{
    CapSense_1_UNDEFINED_E            = 0x00u,
    CapSense_1_SENSE_METHOD_CSD_E     = 0x01u,
    CapSense_1_SENSE_METHOD_CSX_E     = 0x02u,
    CapSense_1_SENSE_METHOD_BIST_E    = 0x03u
} CapSense_1_SENSE_METHOD_ENUM;

/***************************************************************************//**
* \brief Defines electrode types
*******************************************************************************/
typedef enum
{
    CapSense_1_ELTD_TYPE_SELF_E       = 0x01u,
    CapSense_1_ELTD_TYPE_MUT_TX_E     = 0x02u,
    CapSense_1_ELTD_TYPE_MUT_RX_E     = 0x03u
} CapSense_1_ELTD_TYPE_ENUM;


/**
* \if SECTION_STRUCTURES
* \addtogroup group_structures
* \{
*/

/*******************************************************************************
* Declare RAM structures for all used widgets
*******************************************************************************/

/***************************************************************************//**
* \brief Declare common widget RAM parameters
*******************************************************************************/
typedef struct
{
    /**
     *  Provides scan resolution for the CSD Widgets.
     *  Provides number of the sub-conversions for the CSX Widgets.
     */
    uint16 resolution;

    /**
     *  Widget Finger Threshold.
     */
    CapSense_1_THRESHOLD_TYPE fingerTh;

    /**
     *  Widget Noise Threshold.
     */
    uint8  noiseTh;

    /**
     *  Widget Negative Noise Threshold.
     */
    uint8  nNoiseTh;

    /**
     *  Widget Hysteresis for the signal crossing finger threshold.
     */
    uint8  hysteresis;

    /**
     *  Widget Debounce for the signal above the finger threshold. OFF to ON.
     */
    uint8  onDebounce;

    /**
     *  The widget low baseline reset count.
     *  Specifies the number of samples the sensor has to be below the Negative Noise Threshold to trigger a baseline reset.
     */
    CapSense_1_LOW_BSLN_RST_TYPE lowBslnRst;

    /**
     *  The widget baseline filter coefficient N (for IIR 2 to 8) or baseline update threshold (for bucket method 1 to 255)
     */
    uint8  bslnCoeff;

    /**
     *  Sets the current of the modulation IDAC for the CSD widgets. 
     *  For the CSD Touchpad and Matrix Button widgets sets the current of the modulation IDAC for the column sensors.
     *  Not used for the CSX widgets.
     */
    uint8  idacMod [CapSense_1_NUM_SCAN_FREQS];

    /**
     *  Specifies the sense clock divider. Present only if individual clock dividers are enabled.
     *  Specifies the sense clock divider for the Column sensors for the Matrix Buttons and Touchpad widgets.
     *  Sets Tx clock divider for the CSX Widgets.
     */
    uint8  snsClk;

    /**
     *  Register for internal use
     */
    uint8  snsClkSource;

    /**
     *  Widget Finger capacitance parameter. Available only if the SmartSense is enabled.
     *  Not used for the CSX Widgets.
     */
    uint16 fingerCap;

    /**
     *  The 75% of signal per user-defined finger capacitance
     */
    uint16 sigPFC;
} CapSense_1_RAM_WD_BASE_STRUCT;

/***************************************************************************//**
* \brief Declare RAM parameters for the CSD Button
*******************************************************************************/
typedef struct
{
    /**
     *  Provides scan resolution for the CSD Widgets.
     *  Provides number of the sub-conversions for the CSX Widgets.
     */
    uint16 resolution;

    /**
     *  Widget Finger Threshold.
     */
    CapSense_1_THRESHOLD_TYPE fingerTh;

    /**
     *  Widget Noise Threshold.
     */
    uint8  noiseTh;

    /**
     *  Widget Negative Noise Threshold.
     */
    uint8  nNoiseTh;

    /**
     *  Widget Hysteresis for the signal crossing finger threshold.
     */
    uint8  hysteresis;

    /**
     *  Widget Debounce for the signal above the finger threshold. OFF to ON.
     */
    uint8  onDebounce;

    /**
     *  The widget low baseline reset count.
     *  Specifies the number of samples the sensor has to be below the Negative Noise Threshold to trigger a baseline reset.
     */
    CapSense_1_LOW_BSLN_RST_TYPE lowBslnRst;

    /**
     *  The widget baseline filter coefficient N (for IIR 2 to 8) or baseline update threshold (for bucket method 1 to 255)
     */
    uint8  bslnCoeff;

    /**
     *  Sets the current of the modulation IDAC for the CSD widgets. 
     *  For the CSD Touchpad and Matrix Button widgets sets the current of the modulation IDAC for the column sensors.
     *  Not used for the CSX widgets.
     */
    uint8  idacMod [CapSense_1_NUM_SCAN_FREQS];

    /**
     *  Specifies the sense clock divider. Present only if individual clock dividers are enabled.
     *  Specifies the sense clock divider for the Column sensors for the Matrix Buttons and Touchpad widgets.
     *  Sets Tx clock divider for the CSX Widgets.
     */
    uint8  snsClk;

    /**
     *  Register for internal use
     */
    uint8  snsClkSource;

    /**
     *  Widget Finger capacitance parameter. Available only if the SmartSense is enabled.
     *  Not used for the CSX Widgets.
     */
    uint16 fingerCap;

    /**
     *  The 75% of signal per user-defined finger capacitance
     */
    uint16 sigPFC;
} CapSense_1_RAM_WD_BUTTON_STRUCT;


/***************************************************************************//**
* \brief Declare RAM structure with all defined widgets
*******************************************************************************/
typedef struct
{
    /**
     *  Button0 widget RAM structure
     */
    CapSense_1_RAM_WD_BUTTON_STRUCT button0;

    /**
     *  Button1 widget RAM structure
     */
    CapSense_1_RAM_WD_BUTTON_STRUCT button1;

    /**
     *  Button2 widget RAM structure
     */
    CapSense_1_RAM_WD_BUTTON_STRUCT button2;

    /**
     *  Button3 widget RAM structure
     */
    CapSense_1_RAM_WD_BUTTON_STRUCT button3;

    /**
     *  Button4 widget RAM structure
     */
    CapSense_1_RAM_WD_BUTTON_STRUCT button4;

    /**
     *  Button5 widget RAM structure
     */
    CapSense_1_RAM_WD_BUTTON_STRUCT button5;

    /**
     *  Button6 widget RAM structure
     */
    CapSense_1_RAM_WD_BUTTON_STRUCT button6;

    /**
     *  Button7 widget RAM structure
     */
    CapSense_1_RAM_WD_BUTTON_STRUCT button7;

    /**
     *  Button8 widget RAM structure
     */
    CapSense_1_RAM_WD_BUTTON_STRUCT button8;

    /**
     *  Button9 widget RAM structure
     */
    CapSense_1_RAM_WD_BUTTON_STRUCT button9;

    /**
     *  Button10 widget RAM structure
     */
    CapSense_1_RAM_WD_BUTTON_STRUCT button10;

    /**
     *  Button11 widget RAM structure
     */
    CapSense_1_RAM_WD_BUTTON_STRUCT button11;

    /**
     *  Button12 widget RAM structure
     */
    CapSense_1_RAM_WD_BUTTON_STRUCT button12;

    /**
     *  Button13 widget RAM structure
     */
    CapSense_1_RAM_WD_BUTTON_STRUCT button13;

    /**
     *  Button14 widget RAM structure
     */
    CapSense_1_RAM_WD_BUTTON_STRUCT button14;

    /**
     *  Button15 widget RAM structure
     */
    CapSense_1_RAM_WD_BUTTON_STRUCT button15;
} CapSense_1_RAM_WD_LIST_STRUCT;


/***************************************************************************//**
* \brief Declare RAM structure for sensors
*******************************************************************************/
typedef struct
{
    /**
     *  The sensor raw counts.
     */
    uint16 raw [CapSense_1_NUM_SCAN_FREQS];

    /**
     *  The sensor baseline.
     */
    uint16 bsln [CapSense_1_NUM_SCAN_FREQS];

    /**
     *  For the bucket baseline algorithm holds the bucket state,
     *  For the IIR baseline keeps LSB of the baseline value.
     */
    uint8  bslnExt [CapSense_1_NUM_SCAN_FREQS];

    /**
     *  Sensor differences.
     */
    CapSense_1_THRESHOLD_TYPE diff;

    /**
     *  The baseline reset counter for the low baseline reset function.
     */
    CapSense_1_LOW_BSLN_RST_TYPE negBslnRstCnt [CapSense_1_NUM_SCAN_FREQS];

    /**
     *  CSD Widgets: The compensation IDAC value.
     *  CSX Widgets: The balancing IDAC value.
     */
    uint8  idacComp [CapSense_1_NUM_SCAN_FREQS];
} CapSense_1_RAM_SNS_STRUCT;


/***************************************************************************//**
* \brief Declare RAM structure with all defined sensors
*******************************************************************************/
typedef struct
{
    /**
     *  Button0 sensors RAM structures array
     */
    CapSense_1_RAM_SNS_STRUCT button0  [CapSense_1_BUTTON0_NUM_SENSORS];

    /**
     *  Button1 sensors RAM structures array
     */
    CapSense_1_RAM_SNS_STRUCT button1  [CapSense_1_BUTTON1_NUM_SENSORS];

    /**
     *  Button2 sensors RAM structures array
     */
    CapSense_1_RAM_SNS_STRUCT button2  [CapSense_1_BUTTON2_NUM_SENSORS];

    /**
     *  Button3 sensors RAM structures array
     */
    CapSense_1_RAM_SNS_STRUCT button3  [CapSense_1_BUTTON3_NUM_SENSORS];

    /**
     *  Button4 sensors RAM structures array
     */
    CapSense_1_RAM_SNS_STRUCT button4  [CapSense_1_BUTTON4_NUM_SENSORS];

    /**
     *  Button5 sensors RAM structures array
     */
    CapSense_1_RAM_SNS_STRUCT button5  [CapSense_1_BUTTON5_NUM_SENSORS];

    /**
     *  Button6 sensors RAM structures array
     */
    CapSense_1_RAM_SNS_STRUCT button6  [CapSense_1_BUTTON6_NUM_SENSORS];

    /**
     *  Button7 sensors RAM structures array
     */
    CapSense_1_RAM_SNS_STRUCT button7  [CapSense_1_BUTTON7_NUM_SENSORS];

    /**
     *  Button8 sensors RAM structures array
     */
    CapSense_1_RAM_SNS_STRUCT button8  [CapSense_1_BUTTON8_NUM_SENSORS];

    /**
     *  Button9 sensors RAM structures array
     */
    CapSense_1_RAM_SNS_STRUCT button9  [CapSense_1_BUTTON9_NUM_SENSORS];

    /**
     *  Button10 sensors RAM structures array
     */
    CapSense_1_RAM_SNS_STRUCT button10 [CapSense_1_BUTTON10_NUM_SENSORS];

    /**
     *  Button11 sensors RAM structures array
     */
    CapSense_1_RAM_SNS_STRUCT button11 [CapSense_1_BUTTON11_NUM_SENSORS];

    /**
     *  Button12 sensors RAM structures array
     */
    CapSense_1_RAM_SNS_STRUCT button12 [CapSense_1_BUTTON12_NUM_SENSORS];

    /**
     *  Button13 sensors RAM structures array
     */
    CapSense_1_RAM_SNS_STRUCT button13 [CapSense_1_BUTTON13_NUM_SENSORS];

    /**
     *  Button14 sensors RAM structures array
     */
    CapSense_1_RAM_SNS_STRUCT button14 [CapSense_1_BUTTON14_NUM_SENSORS];

    /**
     *  Button15 sensors RAM structures array
     */
    CapSense_1_RAM_SNS_STRUCT button15 [CapSense_1_BUTTON15_NUM_SENSORS];
} CapSense_1_RAM_SNS_LIST_STRUCT;



/***************************************************************************//**
* \brief Declares the top-level RAM Data Structure
*******************************************************************************/
typedef struct
{
    /**
     *  16-bit CRC calculated by the customizer for the component configuration. 
     *  Used by the Tuner application to identify if the FW corresponds to the specific user configuration.
     */
    uint16 configId;

    /**
     *  Used by the Tuner application to identify device-specific configuration.
     */
    uint16 deviceId;

    /**
     *  Tuner Command Register. 
     *  Used for the communication between the Tuner GUI and the component.
     */
    uint16 tunerCmd;

    /**
     *  This counter gets incremented after each scan.
     */
    uint16 scanCounter;

    /**
     *  Status information: Current Widget, Scan active, Error code.
     */
    uint32 status;

    /**
     *  The bitmask that sets which Widgets are enabled and scanned, each bit corresponds to one widget.
     */
    uint32 wdgtEnable [CapSense_1_WDGT_STATUS_WORDS];

    /**
     *  The bitmask that reports activated Widgets (widgets that detect a touch signal above the threshold), each bit corresponds to one widget.
     */
    uint32 wdgtStatus [CapSense_1_WDGT_STATUS_WORDS];

    /**
     *  For Buttons, Sliders, Matrix Buttons and CSD Touchpad each bit reports status of the individual sensor of the widget:
     *  1 - active (above the finger threshold);
     *  0 - inactive;
     *  For the CSD Touchpad and CSD Matrix Buttons, the column sensors occupy the least significant bits.
     *  For the Proximity widget, each sensor uses two bits with the following meaning:
     *  00 - Not active;
     *  01 - Proximity detected (signal above finger threshold);
     *  11 - A finger touch detected (signal above the touch threshold);
     *  For the CSX Touchpad Widget, this register provides a number of the detected touches.
     *  The array size is equal to the total number of widgets. The size of the array element depends on the max number of sensors per widget used in the current design. It could be 1, 2 or 4 bytes.
     */
    CapSense_1_SNS_STS_TYPE snsStatus [CapSense_1_TOTAL_WIDGETS];

    /**
     *  The configuration register for global parameters of the CSD0 block.
     */
    uint16 csd0Config;

    /**
     *  The modulator clock divider for the CSD widgets.
     */
    uint8  modCsdClk;

    /**
     *  RAM Widget Objects.
     */
    CapSense_1_RAM_WD_LIST_STRUCT wdgtList;

    /**
     *  RAM Sensor Objects.
     */
    CapSense_1_RAM_SNS_LIST_STRUCT snsList;

    /**
     *  The selected widget ID.
     */
    uint8  snrTestWidgetId;

    /**
     *  The selected sensor ID.
     */
    uint8  snrTestSensorId;

    /**
     *  The scan counter.
     */
    uint16 snrTestScanCounter;

    /**
     *  The sensor raw counts.
     */
    uint16 snrTestRawCount [CapSense_1_NUM_SCAN_FREQS];
} CapSense_1_RAM_STRUCT;


/***************************************************************************//**
* \brief Declares the Flash IO object
*******************************************************************************/
typedef struct
{
    /**
     *  Pointer to the HSIOM configuration register of the IO.
     */
    reg32  * hsiomPtr;

    /**
     *  Pointer to the port configuration register of the IO.
     */
    reg32  * pcPtr;

    /**
     *  Pointer to the port data register of the IO.
     */
    reg32  * drPtr;

    /**
     *  Pointer to the pin state data register of the IO.
     */
    reg32  * psPtr;

    /**
     *  IO mask in the HSIOM configuration register.
     */
    uint32   hsiomMask;

    /**
     *  IO mask in the DR and PS registers.
     */
    uint32   mask;

    /**
     *  Position of the IO configuration bits in the HSIOM register.
     */
    uint8    hsiomShift;

    /**
     *  Position of the IO configuration bits in the DR and PS registers.
     */
    uint8    drShift;

    /**
     *  Position of the IO configuration bits in the PC register.
     */
    uint8    shift;
} CapSense_1_FLASH_IO_STRUCT;


/***************************************************************************//**
* \brief Declares the Flash Electrode object
*******************************************************************************/
typedef struct
{
    /**
     *  Index of the first IO in the Flash IO Object Array.
     */
    uint16 firstPinId;

    /**
     *  Total number of IOs in this sensor.
     */
    uint8  numPins;

    /**
     * Sensor type:
     * - ELTD_TYPE_SELF_E - CSD sensor;
     * - ELTD_TYPE_MUT_TX_E - CSX Tx sensor;
     * - ELTD_TYPE_MUT_RX_E - CSX Rx sensor;
     */
    uint8  type;
} CapSense_1_FLASH_SNS_STRUCT;


/***************************************************************************//**
* \brief Declares the structure with all Flash electrode objects
*******************************************************************************/
typedef struct
{
    /**
     *  No ganged sensors available
     */
    uint8 notUsed;
} CapSense_1_FLASH_SNS_LIST_STRUCT;


/***************************************************************************//**
* \brief Declare Flash widget object
*******************************************************************************/
typedef struct
{
    /**
     *  Points to the array of the FLASH Sensor Objects or FLASH IO Objects that belong to this widget.
     *  Sensing block uses this pointer to access and configure IOs for the scanning.
     *  Bit #2 in WD_STATIC_CONFIG field indicates the type of array: 
     *  1 - Sensor Object; 
     *  0 - IO Object.
     */
    void const * ptr2SnsFlash;

    /**
     *  Points to the Widget Object in RAM. Sensing block uses it to access scan parameters.
     *  Processing uses it to access threshold and widget specific data.
     */
    void * ptr2WdgtRam;

    /**
     *  Points to the array of Sensor Objects in RAM.
     *  The sensing and processing blocks use it to access the scan data.
     */
    CapSense_1_RAM_SNS_STRUCT * ptr2SnsRam;

    /**
     *  Points to the array of the Filter History Objects in RAM that belongs to this widget.
     */
    void * ptr2FltrHistory;

    /**
     *  Points to the array of the debounce counters.
     *  The size of the debounce counter is 8 bits.
     *  These arrays are not part of the data structure.
     */
    uint8 * ptr2DebounceArr;

    /**
     *  Miscellaneous configuration flags.
     */
    uint16 staticConfig;

    /**
     *  The total number of sensors. 
     *  For CSD widgets: WD_NUM_ROWS + WD_NUM_COLS
     *  For CSX widgets: WD_NUM_ROWS * WD_NUM_COLS
     */
    uint16 totalNumSns;

    /**
     *  Specifies one of the following widget types: 
     *  WD_BUTTON_E,
     *  WD_LINEAR_SLIDER_E,
     *  WD_RADIAL_SLIDER_E,
     *  WD_MATRIX_BUTTON_E, 
     *  WD_TOUCHPAD_E, 
     *  WD_PROXIMITY_E
     */
    uint8  wdgtType;

    /**
     *  For CSD Button and Proximity Widgets, the number of sensors.
     *  For CSD Slider Widget, the number of segments.
     *  For CSD Touchpad and Matrix Button, the number of the column sensors.
     *  For CSX Button, Touchpad and Matrix Button, the number of the Rx electrodes.
     */
    uint8  numCols;

    /**
     *  The pointer to the array with the sensor noise envelope data.
     *  Set to the valid value only for the CSD widgets.
     *  For the CSX widgets this pointer is set to NULL.
     *  The pointed array is not part of the data structure.
     */
    SMARTSENSE_CSD_NOISE_ENVELOPE_STRUCT * ptr2NoiseEnvlp;
} CapSense_1_FLASH_WD_STRUCT;


/***************************************************************************//**
* \brief Declares top-level Flash Data Structure
*******************************************************************************/
typedef struct
{
    /**
     *  Array of flash widget objects
     */
    CapSense_1_FLASH_WD_STRUCT wdgtArray[CapSense_1_TOTAL_WIDGETS];
} CapSense_1_FLASH_STRUCT;


#if (CapSense_1_ENABLE == CapSense_1_TST_BSLN_RAW_OUT_RANGE_EN)
    /***************************************************************************//**
    * \brief Define the structure for test of baseline and raw count limits which 
    * will be determined by user for every sensor grounding on the 
    * manufacturing specific data 
    *******************************************************************************/
    typedef struct
    {
        /**
         *  Upper limit of a sensor baseline.
         */
        uint16 bslnHiLim;
        /**
         *  Lower limit of a sensor baseline.
         */
        uint16 bslnLoLim;
        /**
         *  Upper limit of a sensor raw count.
         */
        uint16 rawHiLim;
        /**
         *  Lower limit of a sensor raw count.
         */
        uint16 rawLoLim;
    } CapSense_1_BSLN_RAW_RANGE_STRUCT;
#endif /* (CapSense_1_ENABLE == CapSense_1_TST_BSLN_RAW_OUT_RANGE_EN) */

/** \}
* \endif */


/***************************************************************************//**
* Declares Dual-channel scan structure
*******************************************************************************/
typedef struct
{
    uint8 csd0WidgetId;
    uint8 csd0SensorId;
    uint8 csd1WidgetId;
    uint8 csd1SensorId;
} CapSense_1_SCAN_SLOT_STRUCT;


/***************************************************************************//**
* Declares Filter module structures
*******************************************************************************/

/***************************************************************************//**
* \brief Declare filter channel structure for regular sensors
*******************************************************************************/
typedef struct
{
    uint16 notUsed;
} CapSense_1_REGULAR_FLTR_CHANNEL_STRUCT;

/***************************************************************************//**
* \brief Declare filter structure for regular sensors
*******************************************************************************/
typedef struct
{
    /**
     *  Array of CapSense_1_REGULAR_FLTR_CHANNEL_STRUCT for each available scan frequency
     */
    CapSense_1_REGULAR_FLTR_CHANNEL_STRUCT regularChannel[CapSense_1_NUM_SCAN_FREQS];
} CapSense_1_REGULAR_FLTR_STRUCT;

/***************************************************************************//**
* \brief Declare union for filter structure variants
*******************************************************************************/
typedef union
{
    /**
     *  Pointer to void type
     */
    void *ptr;

    /**
     *  Pointer to CapSense_1_REGULAR_FLTR_STRUCT type
     */
    CapSense_1_REGULAR_FLTR_STRUCT *ptrRegular;
} CapSense_1_PTR_FILTER_VARIANT;


typedef struct
{
    uint16 posMedianZ1;
    uint16 posMedianZ2;
} CapSense_1_SLIDER_POS_HISTORY_STRUCT;

typedef struct
{
    CapSense_1_SLIDER_POS_HISTORY_STRUCT xPos;
    CapSense_1_SLIDER_POS_HISTORY_STRUCT yPos;
} CapSense_1_TOUCHPAD_POS_HISTORY_STRUCT;

/*******************************************************************************
* API Constants
*******************************************************************************/

/*******************************************************************************
* Defines shift/mask values for data structure register bit fields
*******************************************************************************/

/* CSD0_CONFIG bit fields */

/* Bit 0: The multi-frequency scan enable/disable at runtime. This bit is functional
 * only if the multi-frequency scan functionality has been activated
 * in general component configuration. */
#define CapSense_1_MULTI_FREQ_EN_SIZE     (0x00000001Lu)
#define CapSense_1_MULTI_FREQ_EN_SHIFT    (0u)
#define CapSense_1_MULTI_FREQ_EN_MASK     (CapSense_1_MULTI_FREQ_EN_SIZE << CapSense_1_MULTI_FREQ_EN_SHIFT)

/* Bit 1: The sensor auto-reset is enabled */
#define CapSense_1_SNS_ARST_SIZE          (0x00000001Lu)
#define CapSense_1_SNS_ARST_SHIFT         (1u)
#define CapSense_1_SNS_ARST_MASK          (CapSense_1_SNS_ARST_SIZE << CapSense_1_SNS_ARST_SHIFT)

/* Bits 2-3: The IDAC range setting (4x/8x) */
#define CapSense_1_IDAC_RANGE_SIZE        (0x00000003Lu)
#define CapSense_1_IDAC_RANGE_SHIFT       (2u)
#define CapSense_1_IDAC_RANGE_MASK        (CapSense_1_IDAC_RANGE_SIZE << CapSense_1_IDAC_RANGE_SHIFT)

/* Bits 4-7: Reserved */

/* Bit 8: The shield electrode signal Enable/Disable */
#define CapSense_1_SHLD_EN_SIZE           (0x00000001Lu)
#define CapSense_1_SHLD_EN_SHIFT          (8u)
#define CapSense_1_SHLD_EN_MASK           (CapSense_1_SHLD_EN_SIZE << CapSense_1_SHLD_EN_SHIFT)

/* Bits 9-10: Selects the delay by which the csd_shield is delayed relative to csd_sense */
#define CapSense_1_SHLD_DLY_SIZE          (0x00000003Lu)
#define CapSense_1_SHLD_DLY_SHIFT         (9u)
#define CapSense_1_SHLD_DLY_MASK          (CapSense_1_SHLD_DLY_SIZE << CapSense_1_SHLD_DLY_SHIFT)


/* STATUS bit fields */

/* Bits 0-6: The widget currently selected for CSD0 */
#define CapSense_1_STATUS_WDGT0_SIZE      (0x0000007FLu)
#define CapSense_1_STATUS_WDGT0_SHIFT     (0u)
#define CapSense_1_STATUS_WDGT0_MASK      (CapSense_1_STATUS_WDGT0_SIZE << CapSense_1_STATUS_WDGT0_SHIFT)

/* Bit 7: The CSD0 block status */
#define CapSense_1_STATUS_CSD0_SIZE       (0x00000001Lu)
#define CapSense_1_STATUS_CSD0_SHIFT      (7u)
#define CapSense_1_STATUS_CSD0_MASK       (CapSense_1_STATUS_CSD0_SIZE << CapSense_1_STATUS_CSD0_SHIFT)

/* Bits 8-14: The widget currently selected for CSD1 */
#define CapSense_1_STATUS_WDGT1_SIZE      (0x0000007FLu)
#define CapSense_1_STATUS_WDGT1_SHIFT     (8u)
#define CapSense_1_STATUS_WDGT1_MASK      (CapSense_1_STATUS_WDGT1_SIZE << CapSense_1_STATUS_WDGT1_SHIFT)

/* Bit 15: The CSD1 block status */
#define CapSense_1_STATUS_CSD1_SIZE       (0x00000001Lu)
#define CapSense_1_STATUS_CSD1_SHIFT      (15u)
#define CapSense_1_STATUS_CSD1_MASK       (CapSense_1_STATUS_CSD1_SIZE << CapSense_1_STATUS_CSD1_SHIFT)

/* Bit 16: The WIDGET BUSY flag status for CSD0 */
#define CapSense_1_STATUS_WDGT0_BUSY_SIZE (0x00000001Lu)
#define CapSense_1_STATUS_WDGT0_BUSY_SHIFT (16u)
#define CapSense_1_STATUS_WDGT0_BUSY_MASK (CapSense_1_STATUS_WDGT0_BUSY_SIZE << CapSense_1_STATUS_WDGT0_BUSY_SHIFT)

/* Bit 17: The WIDGET BUSY flag status for CSD1 */
#define CapSense_1_STATUS_WDGT1_BUSY_SIZE (0x00000001Lu)
#define CapSense_1_STATUS_WDGT1_BUSY_SHIFT (17u)
#define CapSense_1_STATUS_WDGT1_BUSY_MASK (CapSense_1_STATUS_WDGT1_BUSY_SIZE << CapSense_1_STATUS_WDGT1_BUSY_SHIFT)

/* Bits 18-23: Reserved */

/* Bits 24-31: CapSense component error code */
#define CapSense_1_STATUS_ERR_SIZE        (0x000000FFLu)
#define CapSense_1_STATUS_ERR_SHIFT       (24u)
#define CapSense_1_STATUS_ERR_MASK        (CapSense_1_STATUS_ERR_SIZE << CapSense_1_STATUS_ERR_SHIFT)


/* WD_STATIC_CONFIG bit fields */

/* Bit 0: The sense/Tx frequency selection: 0 - Common, 1 - Individual (per widget). */
#define CapSense_1_SNS_FREQ_SIZE          (0x00000001Lu)
#define CapSense_1_SNS_FREQ_SHIFT         (0u)
#define CapSense_1_SNS_FREQ_MASK          (CapSense_1_SNS_FREQ_SIZE << CapSense_1_SNS_FREQ_SHIFT)

/* Bit 1: Duplexing Enable/Disable for linear sliders. */
#define CapSense_1_DIPLEXING_SIZE         (0x00000001Lu)
#define CapSense_1_DIPLEXING_SHIFT        (1u)
#define CapSense_1_DIPLEXING_MASK         (CapSense_1_DIPLEXING_SIZE << CapSense_1_DIPLEXING_SHIFT)

/* Bit 2: The widget contains a sensor ganged to other sensors. */
#define CapSense_1_GANGED_SNS_SIZE        (0x00000001Lu)
#define CapSense_1_GANGED_SNS_SHIFT       (2u)
#define CapSense_1_GANGED_SNS_MASK        (CapSense_1_GANGED_SNS_SIZE << CapSense_1_GANGED_SNS_SHIFT)

/* Bit 3: Some pin from this widget is used by other sensors to make a ganged sensor. */
#define CapSense_1_SHARED_IO_SIZE         (0x00000001Lu)
#define CapSense_1_SHARED_IO_SHIFT        (3u)
#define CapSense_1_SHARED_IO_MASK         (CapSense_1_SHARED_IO_SIZE << CapSense_1_SHARED_IO_SHIFT)

/* Bit 4: The centroid position IIR filter Enable/Disable. */
#define CapSense_1_POS_IIR_FILTER_SIZE    (0x00000001Lu)
#define CapSense_1_POS_IIR_FILTER_SHIFT   (4u)
#define CapSense_1_POS_IIR_FILTER_MASK    (CapSense_1_POS_IIR_FILTER_SIZE << CapSense_1_POS_IIR_FILTER_SHIFT)

/* Bit 5: The centroid position median filter Enable/Disable. */
#define CapSense_1_POS_MEDIAN_FILTER_SIZE (0x00000001Lu)
#define CapSense_1_POS_MEDIAN_FILTER_SHIFT (5u)
#define CapSense_1_POS_MEDIAN_FILTER_MASK (CapSense_1_POS_MEDIAN_FILTER_SIZE << CapSense_1_POS_MEDIAN_FILTER_SHIFT)

/* Bit 6: The centroid position average filter Enable/Disable. */
#define CapSense_1_POS_AVERAGE_FILTER_SIZE (0x00000001Lu)
#define CapSense_1_POS_AVERAGE_FILTER_SHIFT (6u)
#define CapSense_1_POS_AVERAGE_FILTER_MASK (CapSense_1_POS_AVERAGE_FILTER_SIZE << CapSense_1_POS_AVERAGE_FILTER_SHIFT)

/* Bit 7: The centroid position jitter filter Enable/Disable. */
#define CapSense_1_POS_JITTER_FILTER_SIZE (0x00000001Lu)
#define CapSense_1_POS_JITTER_FILTER_SHIFT (7u)
#define CapSense_1_POS_JITTER_FILTER_MASK (CapSense_1_POS_JITTER_FILTER_SIZE << CapSense_1_POS_JITTER_FILTER_SHIFT)

/* Bit 8: The multiphase Tx scan Enable (CSX widgets only). */
#define CapSense_1_MULTIPHASE_TX_SIZE     (0x00000001Lu)
#define CapSense_1_MULTIPHASE_TX_SHIFT    (8u)
#define CapSense_1_MULTIPHASE_TX_MASK     (CapSense_1_MULTIPHASE_TX_SIZE << CapSense_1_MULTIPHASE_TX_SHIFT)


/*******************************************************************************
* Define Data Structure Macro helpers
*******************************************************************************/

/*******************************************************************************
* Determines the widget specific word in the wdgtStatus array by widget ID
*******************************************************************************/
/* Divide by 32 - size of the wdgtStatus word in bits to find the word index */
#define CapSense_1_GET_WDGT_STATUS_INDEX(wdgtId)  ((wdgtId) >> 5u)

/*******************************************************************************
* Determines the widget bitmask in wdgtStatus word by widget ID
*******************************************************************************/
/* Take the least 5 bits of widget id to find the bit number */
#define CapSense_1_GET_WDGT_STATUS_MASK(wdgtId)   (1Lu << ((wdgtId) & 0x1FLu))

/*******************************************************************************
* Determines the sense method of the widget
*******************************************************************************/
#if (0u != CapSense_1_TOTAL_CSD_WIDGETS) && (0u != CapSense_1_TOTAL_CSX_WIDGETS)
    #define CapSense_1_GET_SENSE_METHOD(ptrFlash) ((CapSense_1_SENSE_METHOD_ENUM)(ptrFlash)->senseMethod)
#else
    #if (0u != CapSense_1_TOTAL_CSX_WIDGETS)
        #define CapSense_1_GET_SENSE_METHOD(ptrFlash) CapSense_1_SENSE_METHOD_CSX_E
    #else
        #define CapSense_1_GET_SENSE_METHOD(ptrFlash) CapSense_1_SENSE_METHOD_CSD_E
    #endif /* #if (0u != CapSense_1_TOTAL_CSX_WIDGETS) */
#endif /* #if (0u != CapSense_1_TOTAL_CSD_WIDGETS) && (0u != CapSense_1_TOTAL_CSX_WIDGETS) */

/*******************************************************************************
* Gets the widget type
*******************************************************************************/
#define CapSense_1_GET_WIDGET_TYPE(ptrFlashWdgt)  ((CapSense_1_WD_TYPE_ENUM)((ptrFlashWdgt)->wdgtType))

/*******************************************************************************
* Gets the number of the widget's sensors
*******************************************************************************/
#define CapSense_1_GET_SENSOR_COUNT(widgetId)         CapSense_1_dsFlash.wdgtArray[(widgetId)].totalNumSns
#define CapSense_1_GET_SNS_CNT_BY_PTR(ptrFlashWidget) (ptrFlashWidget)->totalNumSns


/*******************************************************************************
* Increments the pointer to the Regular Filter History Object
*******************************************************************************/
#if ((0u != CapSense_1_REGULAR_RC_FILTER_EN) &&                                               \
     ((0u != CapSense_1_BUTTON_WIDGET_EN) || (0u != CapSense_1_SLIDER_WIDGET_EN)  ||    \
      (0u != CapSense_1_MATRIX_WIDGET_EN) || (0u != CapSense_1_TOUCHPAD_WIDGET_EN)))

    #define CapSense_1_INC_REG_FLTR_OBJ(fltrVariant)    \
    do {                                                      \
        (fltrVariant).ptrRegular++;                           \
    } while(0)

#else

    #define CapSense_1_INC_REG_FLTR_OBJ(fltrVariant)

#endif /* #if ((0u != CapSense_1_REGULAR_RC_FILTER_EN) &&                                 
               ((0u != CapSense_1_BUTTON_WIDGET_EN) || (0u != CapSense_1_SLIDER_WIDGET_EN)  ||
                (0u != CapSense_1_MATRIX_WIDGET_EN) || (0u != CapSense_1_TOUCHPAD_WIDGET_EN))) */


/*******************************************************************************
* Increments the pointer to the Proximity Filter History Object
*******************************************************************************/
#if ((0u != CapSense_1_PROX_RC_FILTER_EN) && (0u != CapSense_1_PROXIMITY_WIDGET_EN))
    #define CapSense_1_INC_PROX_FLTR_OBJ(fltrVariant)     \
        do {                                                    \
            (fltrVariant).ptrProx++;                            \
        } while(0)
#else
    #define CapSense_1_INC_PROX_FLTR_OBJ(fltrVariant)
#endif /* #if ((0u != CapSense_1_PROX_RC_FILTER_EN) && (0u != CapSense_1_PROXIMITY_WIDGET_EN)) */


/*******************************************************************************
* Increments the pointer to the Filter History Object Variant
*******************************************************************************/
#define CapSense_1_INC_FLTR_OBJ_VARIANT(isProxHistObj, fltrVariant)   \
    do {                                                                    \
        if (0u == (isProxHistObj))                                          \
        {                                                                   \
            CapSense_1_INC_REG_FLTR_OBJ(fltrVariant);                 \
        }                                                                   \
        else                                                                \
        {                                                                   \
            CapSense_1_INC_PROX_FLTR_OBJ(fltrVariant);                \
        }                                                                   \
    } while(0)

/*******************************************************************************
* Gets a widget status in the global enable register dsRam.wdgtEnable[]
*******************************************************************************/
#if (CapSense_1_ENABLE == CapSense_1_SELF_TEST_EN)
    #define CapSense_1_GET_WIDGET_EN_STATUS(wdId)                                                     \
                 (CapSense_1_GET_WDGT_STATUS_MASK(wdId) &                                             \
                  CapSense_1_dsRam.wdgtEnable[CapSense_1_GET_WDGT_STATUS_INDEX(wdId)] &         \
                  CapSense_1_dsRam.wdgtWorking[CapSense_1_GET_WDGT_STATUS_INDEX(wdId)])
#else
    #define CapSense_1_GET_WIDGET_EN_STATUS(wdId)                    \
                (CapSense_1_GET_WDGT_STATUS_MASK(wdId) &             \
                 CapSense_1_dsRam.wdgtEnable[CapSense_1_GET_WDGT_STATUS_INDEX(wdId)])
#endif /* (CapSense_1_ENABLE == CapSense_1_SELF_TEST_EN) */

/*******************************************************************************
* Gets a widget active status from the dsRam.wdgtStatus[] register
*******************************************************************************/
#define CapSense_1_GET_WIDGET_ACTIVE_STATUS(wdId)                    \
            (CapSense_1_GET_WDGT_STATUS_MASK(wdId) &                 \
             CapSense_1_dsRam.wdgtStatus[CapSense_1_GET_WDGT_STATUS_INDEX(wdId)])

/*******************************************************************************
* Declares Flash and RAM Data Structure variables
*******************************************************************************/
extern CapSense_1_RAM_STRUCT            CapSense_1_dsRam;
extern const CapSense_1_FLASH_STRUCT    CapSense_1_dsFlash;
extern const CapSense_1_FLASH_IO_STRUCT CapSense_1_ioList[CapSense_1_TOTAL_ELECTRODES];



/*******************************************************************************
* Function Prototypes
*******************************************************************************/

/*******************************************************************************
* High-level API
*******************************************************************************/

/**
* \if SECTION_CAPSENSE_HIGH_LEVEL
* \addtogroup group_capsense_high_level
* \{
*/

uint32 CapSense_1_IsAnyWidgetActive(void);
uint32 CapSense_1_IsWidgetActive(uint32 widgetId);
uint32 CapSense_1_IsSensorActive(uint32 widgetId, uint32 sensorId);

#if (0u != CapSense_1_MATRIX_WIDGET_EN)
    uint32 CapSense_1_IsMatrixButtonsActive(uint32 widgetId);
#endif /* #if (0u != CapSense_1_MATRIX_WIDGET_EN) */

#if (0u != CapSense_1_PROXIMITY_WIDGET_EN)
    uint32 CapSense_1_IsProximitySensorActive(uint32 widgetId, uint32 proxId);
#endif /* #if (0u != CapSense_1_PROXIMITY_WIDGET_EN) */

#if (0u != CapSense_1_SLIDER_WIDGET_EN)
    uint32 CapSense_1_GetCentroidPos(uint32 widgetId);
#endif /* #if (0u != CapSense_1_SLIDER_WIDGET_EN) */

#if (0u != CapSense_1_TOUCHPAD_WIDGET_EN)
    uint32 CapSense_1_GetXYCoordinates(uint32 widgetId);
#endif /* #if (0u != CapSense_1_TOUCHPAD_WIDGET_EN) */

/** \}
* \endif */

/*******************************************************************************
* Low level API
*******************************************************************************/

/**
* \if SECTION_CAPSENSE_LOW_LEVEL
* \addtogroup group_capsense_low_level
* \{
*/

cystatus CapSense_1_GetParam(uint32 paramId, uint32 *value);
cystatus CapSense_1_SetParam(uint32 paramId, uint32 value);

/** \}
* \endif
*/

/*******************************************************************************
* Function Prototypes - internal functions
*******************************************************************************/
/**
* \if SECTION_CAPSENSE_INTERNAL
* \addtogroup group_capsense_internal
* \{
*/

void CapSense_1_DsInitialize(void);
#if (0u != CapSense_1_ADC_EN)
    void CapSense_1_AdcDsInitialize(void);
#endif /* (0u != CapSense_1_ADC_EN) */

/** \}
* \endif */

#endif /* End CY_CAPSENSE_CapSense_1_STRUCTURE_H */

/* [] END OF FILE */
