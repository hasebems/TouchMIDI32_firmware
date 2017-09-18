/*******************************************************************************
* \file       CapSense_1_Configuration.h
* \version    3.10
*
* \brief
*   This file provides the customizer parameters definitions.
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

#if !defined(CY_CAPSENSE_CapSense_1_CONFIGURATION_H)
#define CY_CAPSENSE_CapSense_1_CONFIGURATION_H

#include <cytypes.h>

/*******************************************************************************
* Customizer-generated defines
*******************************************************************************/
#define CapSense_1_ENABLE                   (1u)
#define CapSense_1_DISABLE                  (0u)

/*******************************************************************************
* Creator-global defines
*******************************************************************************/
#ifdef CYIPBLOCK_m0s8csdv2_VERSION
    #define CapSense_1_CSDV2                              (1u)
#else
    #define CapSense_1_CSDV2                              (0u)
#endif  /* CYIPBLOCK_m0s8csdv2_VERSION */

#define CapSense_1_2000_MV                            (2000u)

#ifdef CYDEV_VDDA_MV
    #define CapSense_1_CYDEV_VDDA_MV                  (CYDEV_VDDA_MV)
#else
    #define CapSense_1_CYDEV_VDDA_MV                  (CYDEV_VDD_MV)
#endif  /* #ifdef CYDEV_VDDA_MV */

#define CapSense_1_BAD_CONVERSIONS_NUM                (1u)
#define CapSense_1_RESAMPLING_CYCLES_MAX_NUMBER       (1u)

/*******************************************************************************
* Enabled Scan Methods
*******************************************************************************/
#define CapSense_1_CSD_EN                   (1u)
#define CapSense_1_CSX_EN                   (0u)
#define CapSense_1_CSD_CSX_EN               (CapSense_1_CSD_EN & CapSense_1_CSX_EN)
#define CapSense_1_CSD2X_EN                 (0u)
#define CapSense_1_CSX2X_EN                 (0u)

/*******************************************************************************
* Definitions for number of widgets and sensors
*******************************************************************************/
#define CapSense_1_TOTAL_WIDGETS            (16u)
#define CapSense_1_TOTAL_CSD_WIDGETS        (16u)
#define CapSense_1_TOTAL_CSD_SENSORS        (16u)
#define CapSense_1_TOTAL_CSX_WIDGETS        (0u)
#define CapSense_1_TOTAL_CSX_NODES          (0u)

/*******************************************************************************
* Total number of CSD sensors + CSX nodes
*******************************************************************************/
#define CapSense_1_TOTAL_SENSORS            (CapSense_1_TOTAL_CSD_SENSORS + \
                                                   CapSense_1_TOTAL_CSX_NODES)

/*******************************************************************************
* Total number of scan slots (used only when dual-channel scan is enabled)
*******************************************************************************/
#define CapSense_1_TOTAL_SCAN_SLOTS         (16u)

/*******************************************************************************
* Define widget IDs
*******************************************************************************/
#define CapSense_1_BUTTON0_WDGT_ID              (0u)
#define CapSense_1_BUTTON1_WDGT_ID              (1u)
#define CapSense_1_BUTTON2_WDGT_ID              (2u)
#define CapSense_1_BUTTON3_WDGT_ID              (3u)
#define CapSense_1_BUTTON4_WDGT_ID              (4u)
#define CapSense_1_BUTTON5_WDGT_ID              (5u)
#define CapSense_1_BUTTON6_WDGT_ID              (6u)
#define CapSense_1_BUTTON7_WDGT_ID              (7u)
#define CapSense_1_BUTTON8_WDGT_ID              (8u)
#define CapSense_1_BUTTON9_WDGT_ID              (9u)
#define CapSense_1_BUTTON10_WDGT_ID             (10u)
#define CapSense_1_BUTTON11_WDGT_ID             (11u)
#define CapSense_1_BUTTON12_WDGT_ID             (12u)
#define CapSense_1_BUTTON13_WDGT_ID             (13u)
#define CapSense_1_BUTTON14_WDGT_ID             (14u)
#define CapSense_1_BUTTON15_WDGT_ID             (15u)

/*******************************************************************************
* Define sensor IDs
*******************************************************************************/

/* Button0 */
#define CapSense_1_BUTTON0_SNS0_ID              (0u)

/* Button1 */
#define CapSense_1_BUTTON1_SNS0_ID              (0u)

/* Button2 */
#define CapSense_1_BUTTON2_SNS0_ID              (0u)

/* Button3 */
#define CapSense_1_BUTTON3_SNS0_ID              (0u)

/* Button4 */
#define CapSense_1_BUTTON4_SNS0_ID              (0u)

/* Button5 */
#define CapSense_1_BUTTON5_SNS0_ID              (0u)

/* Button6 */
#define CapSense_1_BUTTON6_SNS0_ID              (0u)

/* Button7 */
#define CapSense_1_BUTTON7_SNS0_ID              (0u)

/* Button8 */
#define CapSense_1_BUTTON8_SNS0_ID              (0u)

/* Button9 */
#define CapSense_1_BUTTON9_SNS0_ID              (0u)

/* Button10 */
#define CapSense_1_BUTTON10_SNS0_ID             (0u)

/* Button11 */
#define CapSense_1_BUTTON11_SNS0_ID             (0u)

/* Button12 */
#define CapSense_1_BUTTON12_SNS0_ID             (0u)

/* Button13 */
#define CapSense_1_BUTTON13_SNS0_ID             (0u)

/* Button14 */
#define CapSense_1_BUTTON14_SNS0_ID             (0u)

/* Button15 */
#define CapSense_1_BUTTON15_SNS0_ID             (0u)



/*******************************************************************************
* Enabled widget types
*******************************************************************************/
#define CapSense_1_BUTTON_WIDGET_EN         (1u)
#define CapSense_1_SLIDER_WIDGET_EN         (0u)
#define CapSense_1_MATRIX_WIDGET_EN         (0u)
#define CapSense_1_PROXIMITY_WIDGET_EN      (0u)
#define CapSense_1_TOUCHPAD_WIDGET_EN       (0u)

#define CapSense_1_CSD_MATRIX_WIDGET_EN     (0u)
#define CapSense_1_CSD_TOUCHPAD_WIDGET_EN   (0u)

#define CapSense_1_CSX_MATRIX_WIDGET_EN     (0u)
#define CapSense_1_CSX_TOUCHPAD_WIDGET_EN   (0u)

/*******************************************************************************
* Centroid APIs
*******************************************************************************/
#define CapSense_1_CENTROID_EN              (0u)
#define CapSense_1_TOTAL_DIPLEXED_SLIDERS   (0u)
#define CapSense_1_TOTAL_LINEAR_SLIDERS     (0u)
#define CapSense_1_TOTAL_RADIAL_SLIDERS     (0u)
#define CapSense_1_TOTAL_TOUCHPADS          (0u)
#define CapSense_1_MAX_CENTROID_LENGTH      (0u)

/*******************************************************************************
* Enabled sensor types
*******************************************************************************/
#define CapSense_1_REGULAR_SENSOR_EN        (1u)
#define CapSense_1_PROXIMITY_SENSOR_EN      (0u)

/*******************************************************************************
* Sensor ganging
*******************************************************************************/
#define CapSense_1_GANGED_SNS_EN            (0u)
#define CapSense_1_CSD_GANGED_SNS_EN        (0u)
#define CapSense_1_CSX_GANGED_SNS_EN        (0u)

/*******************************************************************************
* Max number of sensors used among all widgets
*******************************************************************************/
#define CapSense_1_MAX_SENSORS_PER_WIDGET   (1u)

/*******************************************************************************
* Total number of all used electrodes (NOT unique)
*******************************************************************************/
#define CapSense_1_TOTAL_ELECTRODES         (16u)
/* Obsolete */
#define CapSense_1_TOTAL_SENSOR_IOS         CapSense_1_TOTAL_ELECTRODES

/*******************************************************************************
* Total number of used physical IOs (unique)
*******************************************************************************/
#define CapSense_1_TOTAL_IO_CNT             (16u)

/*******************************************************************************
* Array length for widget status registers
*******************************************************************************/
#define CapSense_1_WDGT_STATUS_WORDS        \
                        (((uint8)((CapSense_1_TOTAL_WIDGETS - 1u) / 32u)) + 1u)


/*******************************************************************************
* Auto-tuning mode selection
*******************************************************************************/
#define CapSense_1_CSD_SS_DIS         (0x00ul)
#define CapSense_1_CSD_SS_HW_EN       (0x01ul)
#define CapSense_1_CSD_SS_TH_EN       (0x02ul)
#define CapSense_1_CSD_SS_HWTH_EN     (CapSense_1_CSD_SS_HW_EN | \
                                             CapSense_1_CSD_SS_TH_EN)

#define CapSense_1_CSD_AUTOTUNE       CapSense_1_CSD_SS_HWTH_EN


/*******************************************************************************
* General settings
*******************************************************************************/

#define CapSense_1_AUTO_RESET_METHOD_LEGACY (0u)
#define CapSense_1_AUTO_RESET_METHOD_SAMPLE (1u)

#define CapSense_1_MULTI_FREQ_SCAN_EN       (0u)
#define CapSense_1_SENSOR_AUTO_RESET_EN     (0u)
#define CapSense_1_SENSOR_AUTO_RESET_METHOD (0u)
#define CapSense_1_NUM_CENTROIDS            (1u)
#define CapSense_1_OFF_DEBOUNCE_EN          (0u)

/* Define power status of HW IP block after scanning */
#define CapSense_1_BLOCK_OFF_AFTER_SCAN_EN  (0u)

/* Define number of scan frequencies */
#if (CapSense_1_DISABLE != CapSense_1_MULTI_FREQ_SCAN_EN)
    #define CapSense_1_NUM_SCAN_FREQS       (3u)
#else
    #define CapSense_1_NUM_SCAN_FREQS       (1u)
#endif /* #if (CapSense_1_DISABLE != CapSense_1_MULTI_FREQ_SCAN_EN) */

/* Data size for thresholds / low baseline reset */
#define CapSense_1_SIZE_8BITS               (8u)
#define CapSense_1_SIZE_16BITS              (16u)

#define CapSense_1_THRESHOLD_SIZE           CapSense_1_SIZE_16BITS
typedef uint16 CapSense_1_THRESHOLD_TYPE;

#if (CapSense_1_AUTO_RESET_METHOD_LEGACY == CapSense_1_SENSOR_AUTO_RESET_METHOD)
    #define CapSense_1_LOW_BSLN_RST_SIZE        CapSense_1_SIZE_8BITS
    typedef uint8 CapSense_1_LOW_BSLN_RST_TYPE;
#else
    #define CapSense_1_LOW_BSLN_RST_SIZE    (16u)
    typedef uint16 CapSense_1_LOW_BSLN_RST_TYPE;
#endif /* #if (CapSense_1_AUTO_RESET_METHOD_LEGACY == CapSense_1_SENSOR_AUTO_RESET_METHOD) */

/* Coefficient to define touch threshold for proximity sensors */
#define CapSense_1_PROX_TOUCH_COEFF         (300u)

/*******************************************************************************
* General Filter Constants
*******************************************************************************/

/* Baseline algorithm options */
#define CapSense_1_IIR_BASELINE                 (0u)
#define CapSense_1_BUCKET_BASELINE              (1u)

#define CapSense_1_BASELINE_TYPE                CapSense_1_IIR_BASELINE

/* IIR baseline filter algorithm for regular sensors*/
#define CapSense_1_REGULAR_IIR_BL_TYPE          CapSense_1_IIR_FILTER_PERFORMANCE

/* IIR baseline coefficients for regular sensors */
#define CapSense_1_REGULAR_IIR_BL_N             (1u)
#define CapSense_1_REGULAR_IIR_BL_SHIFT         (8u)

/* IIR baseline filter algorithm for proximity sensors*/
#define CapSense_1_PROX_IIR_BL_TYPE             CapSense_1_IIR_FILTER_PERFORMANCE

/* IIR baseline coefficients for proximity sensors */
#define CapSense_1_PROX_IIR_BL_N                (1u)
#define CapSense_1_PROX_IIR_BL_SHIFT            (8u)


/* IIR filter constants */
#define CapSense_1_IIR_COEFFICIENT_K            (256u)

/* IIR filter type */
#define CapSense_1_IIR_FILTER_STANDARD          (1u)
#define CapSense_1_IIR_FILTER_PERFORMANCE       (2u)
#define CapSense_1_IIR_FILTER_MEMORY            (3u)

/* Regular sensor raw-count filters */
#define CapSense_1_REGULAR_RC_FILTER_EN         (0u)
#define CapSense_1_REGULAR_RC_IIR_FILTER_EN     (0u)
#define CapSense_1_REGULAR_RC_MEDIAN_FILTER_EN  (0u)
#define CapSense_1_REGULAR_RC_AVERAGE_FILTER_EN (0u)
#define CapSense_1_REGULAR_RC_CUSTOM_FILTER_EN  (0u)

/* Proximity sensor raw-count filters */
#define CapSense_1_PROX_RC_FILTER_EN            (0u)
#define CapSense_1_PROX_RC_IIR_FILTER_EN        (0u)
#define CapSense_1_PROX_RC_MEDIAN_FILTER_EN     (0u)
#define CapSense_1_PROX_RC_AVERAGE_FILTER_EN    (0u)
#define CapSense_1_PROX_RC_CUSTOM_FILTER_EN     (0u)

/* IIR raw-count filter algorithm for regular sensors */
#define CapSense_1_REGULAR_IIR_RC_TYPE          (CapSense_1_IIR_FILTER_STANDARD)

/* IIR raw-count filter coefficients for regular sensors */
#define CapSense_1_REGULAR_IIR_RC_N             (128u)
#define CapSense_1_REGULAR_IIR_RC_SHIFT         (0u)

/* IIR raw-count filter algorithm for proximity sensors*/
#define CapSense_1_PROX_IIR_RC_TYPE             (CapSense_1_IIR_FILTER_STANDARD)

/* IIR raw-count filter coefficients for proximity sensors */
#define CapSense_1_PROX_IIR_RC_N                (128u)
#define CapSense_1_PROX_IIR_RC_SHIFT            (0u)

/* Median filter constants */

/* Order of regular sensor median filter */
#define CapSense_1_REGULAR_MEDIAN_LEN           (2u)

/* Order of proximity sensor median filter */
#define CapSense_1_PROX_MEDIAN_LEN              (2u)

/* Average filter constants*/
#define CapSense_1_AVERAGE_FILTER_LEN_2         (2u)
#define CapSense_1_AVERAGE_FILTER_LEN_4         (4u)

/* Order of regular sensor average filter */
#define CapSense_1_REGULAR_AVERAGE_LEN          (CapSense_1_AVERAGE_FILTER_LEN_4)

/* Order of proximity sensor average filter */
#define CapSense_1_PROX_AVERAGE_LEN             (CapSense_1_AVERAGE_FILTER_LEN_4)


/* Centroid position filters */
#define CapSense_1_POS_IIR_FILTER_EN            (0x00u)
#define CapSense_1_POS_MEDIAN_FILTER_EN         (0x00u)
#define CapSense_1_POS_AVERAGE_FILTER_EN        (0x00u)
#define CapSense_1_POS_JITTER_FILTER_EN         (0x00u)
#define CapSense_1_CSX_TOUCHPAD_POS_MEDIAN_FILTER_EN (0x00u)

#define CapSense_1_POS_IIR_COEFF                (128u)
#define CapSense_1_CSX_TOUCHPAD_UNDEFINED       (40u)


/* IDAC options */

/* CSDv1 IDAC gain */
#define CapSense_1_IDAC_GAIN_4X                 (4u)
#define CapSense_1_IDAC_GAIN_8X                 (8u)

/* CSDv2 IDAC gain */
#define CapSense_1_IDAC_GAIN_LOW                (0uL)
#define CapSense_1_IDAC_GAIN_MEDIUM             (1uL)
#define CapSense_1_IDAC_GAIN_HIGH               (2uL)

#define CapSense_1_IDAC_SOURCING                (0u)
#define CapSense_1_IDAC_SINKING                 (1u)

/* Shield tank capacitor precharge source */
#define CapSense_1_CSH_PRECHARGE_VREF           (0u)
#define CapSense_1_CSH_PRECHARGE_IO_BUF         (1u)

/* Shield electrode delay */
#define CapSense_1_NO_DELAY                     (0u)
/* CSDv1 */
#define CapSense_1_SH_DELAY_50NS                (1u)
#define CapSense_1_SH_DELAY_100NS               (2u)
/* CSDv2 */
#define CapSense_1_SH_DELAY_5NS                 (1u)
#define CapSense_1_SH_DELAY_10NS                (2u)
#define CapSense_1_SH_DELAY_20NS                (3u)

/* Inactive sensor connection options */
#define CapSense_1_SNS_CONNECTION_GROUND        (0x00000006Lu)
#define CapSense_1_SNS_CONNECTION_HIGHZ         (0x00000000Lu)
#define CapSense_1_SNS_CONNECTION_SHIELD        (0x00000002Lu)

/* Sense clock selection options */
#if defined(CapSense_1_TAPEOUT_STAR_USED)
    #define CapSense_1_CSDV2_REF9P6UA_EN            (0u)
#else
    #define CapSense_1_CSDV2_REF9P6UA_EN            (0u)
#endif /* defined(CapSense_1_TAPEOUT_A_USED) */

#define CapSense_1_CLK_SOURCE_DIRECT            (0x00000000Lu)

#define CapSense_1_CLK_SOURCE_SSC1              (0x01u)
#define CapSense_1_CLK_SOURCE_SSC2              (0x02u)
#define CapSense_1_CLK_SOURCE_SSC3              (0x03u)
#define CapSense_1_CLK_SOURCE_SSC4              (0x04u)

/* CSDv1 and CSDv2 */
#define CapSense_1_CLK_SOURCE_PRS8              (0x05u)
#define CapSense_1_CLK_SOURCE_PRS12             (0x06u)
#define CapSense_1_CLK_SOURCE_PRSAUTO           (0xFFu)

/* Defines scan resolutions */
#define CapSense_1_RES6BIT                      (6u)
#define CapSense_1_RES7BIT                      (7u)
#define CapSense_1_RES8BIT                      (8u)
#define CapSense_1_RES9BIT                      (9u)
#define CapSense_1_RES10BIT                     (10u)
#define CapSense_1_RES11BIT                     (11u)
#define CapSense_1_RES12BIT                     (12u)
#define CapSense_1_RES13BIT                     (13u)
#define CapSense_1_RES14BIT                     (14u)
#define CapSense_1_RES15BIT                     (15u)
#define CapSense_1_RES16BIT                     (16u)

/* CSDv2: Initialization switch resistance */
#define CapSense_1_INIT_SW_RES_LOW              (0x00000000Lu)
#define CapSense_1_INIT_SW_RES_MEDIUM           (0x00000001Lu)
#define CapSense_1_INIT_SW_RES_HIGH             (0x00000002Lu)

/* CSDv2: Initialization switch resistance */
#define CapSense_1_SCAN_SW_RES_LOW              (0x00000000Lu)
#define CapSense_1_SCAN_SW_RES_MEDIUM           (0x00000001Lu)
#define CapSense_1_SCAN_SW_RES_HIGH             (0x00000002Lu)

/* CSDv2: CSD shield switch resistance */
#define CapSense_1_SHIELD_SW_RES_LOW            (0x00000000Lu)
#define CapSense_1_SHIELD_SW_RES_MEDIUM         (0x00000001Lu)
#define CapSense_1_SHIELD_SW_RES_HIGH           (0x00000002Lu)
#define CapSense_1_SHIELD_SW_RES_LOW_EMI        (0x00000003Lu)

/* CSDv2: CSD shield switch resistance */
#define CapSense_1_INIT_SHIELD_SW_RES_LOW       (0x00000000Lu)
#define CapSense_1_INIT_SHIELD_SW_RES_MEDIUM    (0x00000001Lu)
#define CapSense_1_INIT_SHIELD_SW_RES_HIGH      (0x00000002Lu)
#define CapSense_1_INIT_SHIELD_SW_RES_LOW_EMI   (0x00000003Lu)

/* CSDv2: CSD shield switch resistance */
#define CapSense_1_SCAN_SHIELD_SW_RES_LOW            (0x00000000Lu)
#define CapSense_1_SCAN_SHIELD_SW_RES_MEDIUM         (0x00000001Lu)
#define CapSense_1_SCAN_SHIELD_SW_RES_HIGH           (0x00000002Lu)
#define CapSense_1_SCAN_SHIELD_SW_RES_LOW_EMI        (0x00000003Lu)

/*******************************************************************************
* CSD Specific settings
*******************************************************************************/

/* CSD scan method settings */
#define CapSense_1_CSD_IDAC_AUTOCAL_EN          (1u)
#define CapSense_1_CSD_IDAC_GAIN                (CapSense_1_IDAC_GAIN_4X)
#define CapSense_1_CSD_SHIELD_EN                (0u)
#define CapSense_1_CSD_SHIELD_TANK_EN           (0u)
#define CapSense_1_CSD_CSH_PRECHARGE_SRC        (CapSense_1_CSH_PRECHARGE_VREF)
#define CapSense_1_CSD_SHIELD_DELAY             (CapSense_1_NO_DELAY)
#define CapSense_1_CSD_TOTAL_SHIELD_COUNT       (0u)
#define CapSense_1_CSD_SCANSPEED_DIVIDER        (2u)
#define CapSense_1_CSD_COMMON_SNS_CLK_EN        (0u)
#define CapSense_1_CSD_SNS_CLK_SOURCE           (CapSense_1_CLK_SOURCE_PRSAUTO)
#define CapSense_1_CSD_SNS_CLK_DIVIDER          (8u)
#define CapSense_1_CSD_INACTIVE_SNS_CONNECTION  (CapSense_1_SNS_CONNECTION_GROUND)
#define CapSense_1_CSD_IDAC_COMP_EN             (1u)
#define CapSense_1_CSD_IDAC_CONFIG              (CapSense_1_IDAC_SOURCING)
#define CapSense_1_CSD_RAWCOUNT_CAL_LEVEL       (85u)
#define CapSense_1_CSD_DUALIDAC_LEVEL           (50u)
#define CapSense_1_CSD_PRESCAN_SETTLING_TIME    (5u)
#define CapSense_1_CSD_SNSCLK_R_CONST           (1000u)
#define CapSense_1_CSD_VREF_MV                  (1200u)

/* CSD settings - CSDv2 */
#define CapSense_1_CSD_DEDICATED_IDAC_COMP_EN   (1u)
#define CapSense_1_CSD_AUTO_ZERO_EN             (0u)
#define CapSense_1_CSD_AUTO_ZERO_TIME           (15Lu)
#define CapSense_1_CSD_NOISE_METRIC_EN          (0u)
#define CapSense_1_CSD_NOISE_METRIC_TH          (1Lu)
#define CapSense_1_CSD_INIT_SWITCH_RES          (CapSense_1_INIT_SW_RES_MEDIUM)
#define CapSense_1_CSD_SHIELD_SWITCH_RES        (CapSense_1_SHIELD_SW_RES_MEDIUM)
#define CapSense_1_CSD_GAIN                     (31Lu)


/*******************************************************************************
* CSX Specific settings
*******************************************************************************/

/* CSX scan method settings */
#define CapSense_1_CSX_SCANSPEED_DIVIDER        (2u)
#define CapSense_1_CSX_COMMON_TX_CLK_EN         (0u)
#define CapSense_1_CSX_TX_CLK_SOURCE            (CapSense_1_CLK_SOURCE_DIRECT)
#define CapSense_1_CSX_TX_CLK_DIVIDER           (80u)
#define CapSense_1_CSX_MAX_FINGERS              (1u)
#define CapSense_1_CSX_MAX_LOCAL_PEAKS          (5u)
#define CapSense_1_CSX_IDAC_AUTOCAL_EN          (0u)
#define CapSense_1_CSX_IDAC_BITS_USED           (8u)
#define CapSense_1_CSX_RAWCOUNT_CAL_LEVEL       (40u)
#define CapSense_1_CSX_IDAC_GAIN                (CapSense_1_IDAC_GAIN_4X)
#define CapSense_1_CSX_SKIP_OVSMPL_SPECIFIC_NODES (0u)
#define CapSense_1_CSX_MULTIPHASE_TX_EN         (0u)
#define CapSense_1_CSX_MAX_TX_PHASE_LENGTH      (0u)

/* CSX settings - CSDv2 */
#define CapSense_1_CSX_AUTO_ZERO_EN             (0u)
#define CapSense_1_CSX_AUTO_ZERO_TIME           (15u)
#define CapSense_1_CSX_FINE_INIT_TIME           (4u)
#define CapSense_1_CSX_NOISE_METRIC_EN          (0u)
#define CapSense_1_CSX_NOISE_METRIC_TH          (1u)
#define CapSense_1_CSX_INIT_SWITCH_RES          (CapSense_1_INIT_SW_RES_MEDIUM)
#define CapSense_1_CSX_SCAN_SWITCH_RES          (CapSense_1_SCAN_SW_RES_LOW)
#define CapSense_1_CSX_INIT_SHIELD_SWITCH_RES   (CapSense_1_INIT_SHIELD_SW_RES_HIGH)
#define CapSense_1_CSX_SCAN_SHIELD_SWITCH_RES   (CapSense_1_SCAN_SHIELD_SW_RES_LOW)


/*******************************************************************************
* Global Parameter Definitions
*******************************************************************************/

/* RAM Global Parameters Definitions */
#define CapSense_1_CONFIG_ID                    (0x1A9Eu)
#define CapSense_1_DEVICE_ID                    (0x00C0u)
#define CapSense_1_CSD0_CONFIG                  (0x0000u)

/***************************************************************************//**
* Button0 initialization values for FLASH data structure
*******************************************************************************/
#define CapSense_1_BUTTON0_STATIC_CONFIG        (1u)
#define CapSense_1_BUTTON0_NUM_SENSORS          (1u)

/***************************************************************************//**
* Button0 initialization values for RAM data structure
*******************************************************************************/
#define CapSense_1_BUTTON0_RESOLUTION           (CapSense_1_RES12BIT)
#define CapSense_1_BUTTON0_FINGER_TH            (100u)
#define CapSense_1_BUTTON0_NOISE_TH             (40u)
#define CapSense_1_BUTTON0_NNOISE_TH            (40u)
#define CapSense_1_BUTTON0_HYSTERESIS           (10u)
#define CapSense_1_BUTTON0_ON_DEBOUNCE          (3u)
#define CapSense_1_BUTTON0_LOW_BSLN_RST         (30u)
#define CapSense_1_BUTTON0_BSLN_COEFF           (100u)
#define CapSense_1_BUTTON0_IDAC_MOD0            (32u)
#define CapSense_1_BUTTON0_SNS_CLK              (4u)
#define CapSense_1_BUTTON0_SNS_CLK_SOURCE       (0u)
#define CapSense_1_BUTTON0_FINGER_CAP           (160u)
#define CapSense_1_BUTTON0_SIGPFC               (0u)

/***************************************************************************//**
* Button1 initialization values for FLASH data structure
*******************************************************************************/
#define CapSense_1_BUTTON1_STATIC_CONFIG        (1u)
#define CapSense_1_BUTTON1_NUM_SENSORS          (1u)

/***************************************************************************//**
* Button1 initialization values for RAM data structure
*******************************************************************************/
#define CapSense_1_BUTTON1_RESOLUTION           (CapSense_1_RES12BIT)
#define CapSense_1_BUTTON1_FINGER_TH            (100u)
#define CapSense_1_BUTTON1_NOISE_TH             (40u)
#define CapSense_1_BUTTON1_NNOISE_TH            (40u)
#define CapSense_1_BUTTON1_HYSTERESIS           (10u)
#define CapSense_1_BUTTON1_ON_DEBOUNCE          (3u)
#define CapSense_1_BUTTON1_LOW_BSLN_RST         (30u)
#define CapSense_1_BUTTON1_BSLN_COEFF           (100u)
#define CapSense_1_BUTTON1_IDAC_MOD0            (32u)
#define CapSense_1_BUTTON1_SNS_CLK              (4u)
#define CapSense_1_BUTTON1_SNS_CLK_SOURCE       (0u)
#define CapSense_1_BUTTON1_FINGER_CAP           (160u)
#define CapSense_1_BUTTON1_SIGPFC               (0u)

/***************************************************************************//**
* Button2 initialization values for FLASH data structure
*******************************************************************************/
#define CapSense_1_BUTTON2_STATIC_CONFIG        (1u)
#define CapSense_1_BUTTON2_NUM_SENSORS          (1u)

/***************************************************************************//**
* Button2 initialization values for RAM data structure
*******************************************************************************/
#define CapSense_1_BUTTON2_RESOLUTION           (CapSense_1_RES12BIT)
#define CapSense_1_BUTTON2_FINGER_TH            (100u)
#define CapSense_1_BUTTON2_NOISE_TH             (40u)
#define CapSense_1_BUTTON2_NNOISE_TH            (40u)
#define CapSense_1_BUTTON2_HYSTERESIS           (10u)
#define CapSense_1_BUTTON2_ON_DEBOUNCE          (3u)
#define CapSense_1_BUTTON2_LOW_BSLN_RST         (30u)
#define CapSense_1_BUTTON2_BSLN_COEFF           (100u)
#define CapSense_1_BUTTON2_IDAC_MOD0            (32u)
#define CapSense_1_BUTTON2_SNS_CLK              (4u)
#define CapSense_1_BUTTON2_SNS_CLK_SOURCE       (0u)
#define CapSense_1_BUTTON2_FINGER_CAP           (160u)
#define CapSense_1_BUTTON2_SIGPFC               (0u)

/***************************************************************************//**
* Button3 initialization values for FLASH data structure
*******************************************************************************/
#define CapSense_1_BUTTON3_STATIC_CONFIG        (1u)
#define CapSense_1_BUTTON3_NUM_SENSORS          (1u)

/***************************************************************************//**
* Button3 initialization values for RAM data structure
*******************************************************************************/
#define CapSense_1_BUTTON3_RESOLUTION           (CapSense_1_RES12BIT)
#define CapSense_1_BUTTON3_FINGER_TH            (100u)
#define CapSense_1_BUTTON3_NOISE_TH             (40u)
#define CapSense_1_BUTTON3_NNOISE_TH            (40u)
#define CapSense_1_BUTTON3_HYSTERESIS           (10u)
#define CapSense_1_BUTTON3_ON_DEBOUNCE          (3u)
#define CapSense_1_BUTTON3_LOW_BSLN_RST         (30u)
#define CapSense_1_BUTTON3_BSLN_COEFF           (100u)
#define CapSense_1_BUTTON3_IDAC_MOD0            (32u)
#define CapSense_1_BUTTON3_SNS_CLK              (4u)
#define CapSense_1_BUTTON3_SNS_CLK_SOURCE       (0u)
#define CapSense_1_BUTTON3_FINGER_CAP           (160u)
#define CapSense_1_BUTTON3_SIGPFC               (0u)

/***************************************************************************//**
* Button4 initialization values for FLASH data structure
*******************************************************************************/
#define CapSense_1_BUTTON4_STATIC_CONFIG        (1u)
#define CapSense_1_BUTTON4_NUM_SENSORS          (1u)

/***************************************************************************//**
* Button4 initialization values for RAM data structure
*******************************************************************************/
#define CapSense_1_BUTTON4_RESOLUTION           (CapSense_1_RES12BIT)
#define CapSense_1_BUTTON4_FINGER_TH            (100u)
#define CapSense_1_BUTTON4_NOISE_TH             (40u)
#define CapSense_1_BUTTON4_NNOISE_TH            (40u)
#define CapSense_1_BUTTON4_HYSTERESIS           (10u)
#define CapSense_1_BUTTON4_ON_DEBOUNCE          (3u)
#define CapSense_1_BUTTON4_LOW_BSLN_RST         (30u)
#define CapSense_1_BUTTON4_BSLN_COEFF           (100u)
#define CapSense_1_BUTTON4_IDAC_MOD0            (32u)
#define CapSense_1_BUTTON4_SNS_CLK              (4u)
#define CapSense_1_BUTTON4_SNS_CLK_SOURCE       (0u)
#define CapSense_1_BUTTON4_FINGER_CAP           (160u)
#define CapSense_1_BUTTON4_SIGPFC               (0u)

/***************************************************************************//**
* Button5 initialization values for FLASH data structure
*******************************************************************************/
#define CapSense_1_BUTTON5_STATIC_CONFIG        (1u)
#define CapSense_1_BUTTON5_NUM_SENSORS          (1u)

/***************************************************************************//**
* Button5 initialization values for RAM data structure
*******************************************************************************/
#define CapSense_1_BUTTON5_RESOLUTION           (CapSense_1_RES12BIT)
#define CapSense_1_BUTTON5_FINGER_TH            (100u)
#define CapSense_1_BUTTON5_NOISE_TH             (40u)
#define CapSense_1_BUTTON5_NNOISE_TH            (40u)
#define CapSense_1_BUTTON5_HYSTERESIS           (10u)
#define CapSense_1_BUTTON5_ON_DEBOUNCE          (3u)
#define CapSense_1_BUTTON5_LOW_BSLN_RST         (30u)
#define CapSense_1_BUTTON5_BSLN_COEFF           (100u)
#define CapSense_1_BUTTON5_IDAC_MOD0            (32u)
#define CapSense_1_BUTTON5_SNS_CLK              (4u)
#define CapSense_1_BUTTON5_SNS_CLK_SOURCE       (0u)
#define CapSense_1_BUTTON5_FINGER_CAP           (160u)
#define CapSense_1_BUTTON5_SIGPFC               (0u)

/***************************************************************************//**
* Button6 initialization values for FLASH data structure
*******************************************************************************/
#define CapSense_1_BUTTON6_STATIC_CONFIG        (1u)
#define CapSense_1_BUTTON6_NUM_SENSORS          (1u)

/***************************************************************************//**
* Button6 initialization values for RAM data structure
*******************************************************************************/
#define CapSense_1_BUTTON6_RESOLUTION           (CapSense_1_RES12BIT)
#define CapSense_1_BUTTON6_FINGER_TH            (100u)
#define CapSense_1_BUTTON6_NOISE_TH             (40u)
#define CapSense_1_BUTTON6_NNOISE_TH            (40u)
#define CapSense_1_BUTTON6_HYSTERESIS           (10u)
#define CapSense_1_BUTTON6_ON_DEBOUNCE          (3u)
#define CapSense_1_BUTTON6_LOW_BSLN_RST         (30u)
#define CapSense_1_BUTTON6_BSLN_COEFF           (100u)
#define CapSense_1_BUTTON6_IDAC_MOD0            (32u)
#define CapSense_1_BUTTON6_SNS_CLK              (4u)
#define CapSense_1_BUTTON6_SNS_CLK_SOURCE       (0u)
#define CapSense_1_BUTTON6_FINGER_CAP           (160u)
#define CapSense_1_BUTTON6_SIGPFC               (0u)

/***************************************************************************//**
* Button7 initialization values for FLASH data structure
*******************************************************************************/
#define CapSense_1_BUTTON7_STATIC_CONFIG        (1u)
#define CapSense_1_BUTTON7_NUM_SENSORS          (1u)

/***************************************************************************//**
* Button7 initialization values for RAM data structure
*******************************************************************************/
#define CapSense_1_BUTTON7_RESOLUTION           (CapSense_1_RES12BIT)
#define CapSense_1_BUTTON7_FINGER_TH            (100u)
#define CapSense_1_BUTTON7_NOISE_TH             (40u)
#define CapSense_1_BUTTON7_NNOISE_TH            (40u)
#define CapSense_1_BUTTON7_HYSTERESIS           (10u)
#define CapSense_1_BUTTON7_ON_DEBOUNCE          (3u)
#define CapSense_1_BUTTON7_LOW_BSLN_RST         (30u)
#define CapSense_1_BUTTON7_BSLN_COEFF           (100u)
#define CapSense_1_BUTTON7_IDAC_MOD0            (32u)
#define CapSense_1_BUTTON7_SNS_CLK              (4u)
#define CapSense_1_BUTTON7_SNS_CLK_SOURCE       (0u)
#define CapSense_1_BUTTON7_FINGER_CAP           (160u)
#define CapSense_1_BUTTON7_SIGPFC               (0u)

/***************************************************************************//**
* Button8 initialization values for FLASH data structure
*******************************************************************************/
#define CapSense_1_BUTTON8_STATIC_CONFIG        (1u)
#define CapSense_1_BUTTON8_NUM_SENSORS          (1u)

/***************************************************************************//**
* Button8 initialization values for RAM data structure
*******************************************************************************/
#define CapSense_1_BUTTON8_RESOLUTION           (CapSense_1_RES12BIT)
#define CapSense_1_BUTTON8_FINGER_TH            (100u)
#define CapSense_1_BUTTON8_NOISE_TH             (40u)
#define CapSense_1_BUTTON8_NNOISE_TH            (40u)
#define CapSense_1_BUTTON8_HYSTERESIS           (10u)
#define CapSense_1_BUTTON8_ON_DEBOUNCE          (3u)
#define CapSense_1_BUTTON8_LOW_BSLN_RST         (30u)
#define CapSense_1_BUTTON8_BSLN_COEFF           (100u)
#define CapSense_1_BUTTON8_IDAC_MOD0            (32u)
#define CapSense_1_BUTTON8_SNS_CLK              (4u)
#define CapSense_1_BUTTON8_SNS_CLK_SOURCE       (0u)
#define CapSense_1_BUTTON8_FINGER_CAP           (160u)
#define CapSense_1_BUTTON8_SIGPFC               (0u)

/***************************************************************************//**
* Button9 initialization values for FLASH data structure
*******************************************************************************/
#define CapSense_1_BUTTON9_STATIC_CONFIG        (1u)
#define CapSense_1_BUTTON9_NUM_SENSORS          (1u)

/***************************************************************************//**
* Button9 initialization values for RAM data structure
*******************************************************************************/
#define CapSense_1_BUTTON9_RESOLUTION           (CapSense_1_RES12BIT)
#define CapSense_1_BUTTON9_FINGER_TH            (100u)
#define CapSense_1_BUTTON9_NOISE_TH             (40u)
#define CapSense_1_BUTTON9_NNOISE_TH            (40u)
#define CapSense_1_BUTTON9_HYSTERESIS           (10u)
#define CapSense_1_BUTTON9_ON_DEBOUNCE          (3u)
#define CapSense_1_BUTTON9_LOW_BSLN_RST         (30u)
#define CapSense_1_BUTTON9_BSLN_COEFF           (100u)
#define CapSense_1_BUTTON9_IDAC_MOD0            (32u)
#define CapSense_1_BUTTON9_SNS_CLK              (4u)
#define CapSense_1_BUTTON9_SNS_CLK_SOURCE       (0u)
#define CapSense_1_BUTTON9_FINGER_CAP           (160u)
#define CapSense_1_BUTTON9_SIGPFC               (0u)

/***************************************************************************//**
* Button10 initialization values for FLASH data structure
*******************************************************************************/
#define CapSense_1_BUTTON10_STATIC_CONFIG       (1u)
#define CapSense_1_BUTTON10_NUM_SENSORS         (1u)

/***************************************************************************//**
* Button10 initialization values for RAM data structure
*******************************************************************************/
#define CapSense_1_BUTTON10_RESOLUTION          (CapSense_1_RES12BIT)
#define CapSense_1_BUTTON10_FINGER_TH           (100u)
#define CapSense_1_BUTTON10_NOISE_TH            (40u)
#define CapSense_1_BUTTON10_NNOISE_TH           (40u)
#define CapSense_1_BUTTON10_HYSTERESIS          (10u)
#define CapSense_1_BUTTON10_ON_DEBOUNCE         (3u)
#define CapSense_1_BUTTON10_LOW_BSLN_RST        (30u)
#define CapSense_1_BUTTON10_BSLN_COEFF          (100u)
#define CapSense_1_BUTTON10_IDAC_MOD0           (32u)
#define CapSense_1_BUTTON10_SNS_CLK             (4u)
#define CapSense_1_BUTTON10_SNS_CLK_SOURCE      (0u)
#define CapSense_1_BUTTON10_FINGER_CAP          (160u)
#define CapSense_1_BUTTON10_SIGPFC              (0u)

/***************************************************************************//**
* Button11 initialization values for FLASH data structure
*******************************************************************************/
#define CapSense_1_BUTTON11_STATIC_CONFIG       (1u)
#define CapSense_1_BUTTON11_NUM_SENSORS         (1u)

/***************************************************************************//**
* Button11 initialization values for RAM data structure
*******************************************************************************/
#define CapSense_1_BUTTON11_RESOLUTION          (CapSense_1_RES12BIT)
#define CapSense_1_BUTTON11_FINGER_TH           (100u)
#define CapSense_1_BUTTON11_NOISE_TH            (40u)
#define CapSense_1_BUTTON11_NNOISE_TH           (40u)
#define CapSense_1_BUTTON11_HYSTERESIS          (10u)
#define CapSense_1_BUTTON11_ON_DEBOUNCE         (3u)
#define CapSense_1_BUTTON11_LOW_BSLN_RST        (30u)
#define CapSense_1_BUTTON11_BSLN_COEFF          (100u)
#define CapSense_1_BUTTON11_IDAC_MOD0           (32u)
#define CapSense_1_BUTTON11_SNS_CLK             (4u)
#define CapSense_1_BUTTON11_SNS_CLK_SOURCE      (0u)
#define CapSense_1_BUTTON11_FINGER_CAP          (160u)
#define CapSense_1_BUTTON11_SIGPFC              (0u)

/***************************************************************************//**
* Button12 initialization values for FLASH data structure
*******************************************************************************/
#define CapSense_1_BUTTON12_STATIC_CONFIG       (1u)
#define CapSense_1_BUTTON12_NUM_SENSORS         (1u)

/***************************************************************************//**
* Button12 initialization values for RAM data structure
*******************************************************************************/
#define CapSense_1_BUTTON12_RESOLUTION          (CapSense_1_RES12BIT)
#define CapSense_1_BUTTON12_FINGER_TH           (100u)
#define CapSense_1_BUTTON12_NOISE_TH            (40u)
#define CapSense_1_BUTTON12_NNOISE_TH           (40u)
#define CapSense_1_BUTTON12_HYSTERESIS          (10u)
#define CapSense_1_BUTTON12_ON_DEBOUNCE         (3u)
#define CapSense_1_BUTTON12_LOW_BSLN_RST        (30u)
#define CapSense_1_BUTTON12_BSLN_COEFF          (100u)
#define CapSense_1_BUTTON12_IDAC_MOD0           (32u)
#define CapSense_1_BUTTON12_SNS_CLK             (4u)
#define CapSense_1_BUTTON12_SNS_CLK_SOURCE      (0u)
#define CapSense_1_BUTTON12_FINGER_CAP          (160u)
#define CapSense_1_BUTTON12_SIGPFC              (0u)

/***************************************************************************//**
* Button13 initialization values for FLASH data structure
*******************************************************************************/
#define CapSense_1_BUTTON13_STATIC_CONFIG       (1u)
#define CapSense_1_BUTTON13_NUM_SENSORS         (1u)

/***************************************************************************//**
* Button13 initialization values for RAM data structure
*******************************************************************************/
#define CapSense_1_BUTTON13_RESOLUTION          (CapSense_1_RES12BIT)
#define CapSense_1_BUTTON13_FINGER_TH           (100u)
#define CapSense_1_BUTTON13_NOISE_TH            (40u)
#define CapSense_1_BUTTON13_NNOISE_TH           (40u)
#define CapSense_1_BUTTON13_HYSTERESIS          (10u)
#define CapSense_1_BUTTON13_ON_DEBOUNCE         (3u)
#define CapSense_1_BUTTON13_LOW_BSLN_RST        (30u)
#define CapSense_1_BUTTON13_BSLN_COEFF          (100u)
#define CapSense_1_BUTTON13_IDAC_MOD0           (32u)
#define CapSense_1_BUTTON13_SNS_CLK             (4u)
#define CapSense_1_BUTTON13_SNS_CLK_SOURCE      (0u)
#define CapSense_1_BUTTON13_FINGER_CAP          (160u)
#define CapSense_1_BUTTON13_SIGPFC              (0u)

/***************************************************************************//**
* Button14 initialization values for FLASH data structure
*******************************************************************************/
#define CapSense_1_BUTTON14_STATIC_CONFIG       (1u)
#define CapSense_1_BUTTON14_NUM_SENSORS         (1u)

/***************************************************************************//**
* Button14 initialization values for RAM data structure
*******************************************************************************/
#define CapSense_1_BUTTON14_RESOLUTION          (CapSense_1_RES12BIT)
#define CapSense_1_BUTTON14_FINGER_TH           (100u)
#define CapSense_1_BUTTON14_NOISE_TH            (40u)
#define CapSense_1_BUTTON14_NNOISE_TH           (40u)
#define CapSense_1_BUTTON14_HYSTERESIS          (10u)
#define CapSense_1_BUTTON14_ON_DEBOUNCE         (3u)
#define CapSense_1_BUTTON14_LOW_BSLN_RST        (30u)
#define CapSense_1_BUTTON14_BSLN_COEFF          (100u)
#define CapSense_1_BUTTON14_IDAC_MOD0           (32u)
#define CapSense_1_BUTTON14_SNS_CLK             (4u)
#define CapSense_1_BUTTON14_SNS_CLK_SOURCE      (0u)
#define CapSense_1_BUTTON14_FINGER_CAP          (160u)
#define CapSense_1_BUTTON14_SIGPFC              (0u)

/***************************************************************************//**
* Button15 initialization values for FLASH data structure
*******************************************************************************/
#define CapSense_1_BUTTON15_STATIC_CONFIG       (1u)
#define CapSense_1_BUTTON15_NUM_SENSORS         (1u)

/***************************************************************************//**
* Button15 initialization values for RAM data structure
*******************************************************************************/
#define CapSense_1_BUTTON15_RESOLUTION          (CapSense_1_RES12BIT)
#define CapSense_1_BUTTON15_FINGER_TH           (100u)
#define CapSense_1_BUTTON15_NOISE_TH            (40u)
#define CapSense_1_BUTTON15_NNOISE_TH           (40u)
#define CapSense_1_BUTTON15_HYSTERESIS          (10u)
#define CapSense_1_BUTTON15_ON_DEBOUNCE         (3u)
#define CapSense_1_BUTTON15_LOW_BSLN_RST        (30u)
#define CapSense_1_BUTTON15_BSLN_COEFF          (100u)
#define CapSense_1_BUTTON15_IDAC_MOD0           (32u)
#define CapSense_1_BUTTON15_SNS_CLK             (4u)
#define CapSense_1_BUTTON15_SNS_CLK_SOURCE      (0u)
#define CapSense_1_BUTTON15_FINGER_CAP          (160u)
#define CapSense_1_BUTTON15_SIGPFC              (0u)

/* RAM Sensor Parameters Definitions */
#define CapSense_1_BUTTON0_SNS0_IDAC_COMP0      (32u)
#define CapSense_1_BUTTON1_SNS0_IDAC_COMP0      (32u)
#define CapSense_1_BUTTON2_SNS0_IDAC_COMP0      (32u)
#define CapSense_1_BUTTON3_SNS0_IDAC_COMP0      (32u)
#define CapSense_1_BUTTON4_SNS0_IDAC_COMP0      (32u)
#define CapSense_1_BUTTON5_SNS0_IDAC_COMP0      (32u)
#define CapSense_1_BUTTON6_SNS0_IDAC_COMP0      (32u)
#define CapSense_1_BUTTON7_SNS0_IDAC_COMP0      (32u)
#define CapSense_1_BUTTON8_SNS0_IDAC_COMP0      (32u)
#define CapSense_1_BUTTON9_SNS0_IDAC_COMP0      (32u)
#define CapSense_1_BUTTON10_SNS0_IDAC_COMP0     (32u)
#define CapSense_1_BUTTON11_SNS0_IDAC_COMP0     (32u)
#define CapSense_1_BUTTON12_SNS0_IDAC_COMP0     (32u)
#define CapSense_1_BUTTON13_SNS0_IDAC_COMP0     (32u)
#define CapSense_1_BUTTON14_SNS0_IDAC_COMP0     (32u)
#define CapSense_1_BUTTON15_SNS0_IDAC_COMP0     (32u)


/*******************************************************************************
* ADC Specific Macros
*******************************************************************************/
#define CapSense_1_ADC_RES8BIT                  (8u)
#define CapSense_1_ADC_RES10BIT                 (10u)

#define CapSense_1_ADC_EN                       (0u)
#define CapSense_1_ADC_STANDALONE_EN            (0u)
#define CapSense_1_ADC_TOTAL_CHANNELS           (1u)
#define CapSense_1_ADC_RESOLUTION               (CapSense_1_ADC_RES10BIT)
#define CapSense_1_ADC_AMUXB_INPUT_EN           (0u)
#define CapSense_1_ADC_SELECT_AMUXB_CH          (0u)
#define CapSense_1_ADC_AZ_EN                    (1Lu)
#define CapSense_1_ADC_AZ_TIME                  (5u)
#define CapSense_1_ADC_VREF_MV                  (2133u)
#define CapSense_1_ADC_GAIN                     (17Lu)
#define CapSense_1_ADC_IDACVAL                  (22u)
#define CapSense_1_ADC_MEASURE_MODE             (0u)

/*******************************************************************************
* Built-In Self-Test Configuration
*******************************************************************************/
#define CapSense_1_SELF_TEST_EN                   (0Lu)
#define CapSense_1_TST_GLOBAL_CRC_EN              (0Lu)
#define CapSense_1_TST_WDGT_CRC_EN                (0Lu)
#define CapSense_1_TST_BSLN_DUPLICATION_EN        (0Lu)
#define CapSense_1_TST_BSLN_RAW_OUT_RANGE_EN      (0Lu)
#define CapSense_1_TST_SNS_SHORT_EN               (0Lu)
#define CapSense_1_TST_SNS2SNS_SHORT_EN           (0Lu)
#define CapSense_1_TST_SNS_CAP_EN                 (0Lu)
#define CapSense_1_TST_SH_CAP_EN                  (0Lu)
#define CapSense_1_TST_EXTERNAL_CAP_EN            (0Lu)
#define CapSense_1_TST_INTERNAL_CAP_EN            (0Lu)
#define CapSense_1_TST_VDDA_EN                    (0Lu)


#endif /* CY_CAPSENSE_CapSense_1_CONFIGURATION_H */


/* [] END OF FILE */
