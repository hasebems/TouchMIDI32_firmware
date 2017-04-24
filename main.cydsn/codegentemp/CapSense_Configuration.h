/*******************************************************************************
* \file       CapSense_Configuration.h
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

#if !defined(CY_CAPSENSE_CapSense_CONFIGURATION_H)
#define CY_CAPSENSE_CapSense_CONFIGURATION_H

#include <cytypes.h>

/*******************************************************************************
* Customizer-generated defines
*******************************************************************************/
#define CapSense_ENABLE                   (1u)
#define CapSense_DISABLE                  (0u)

/*******************************************************************************
* Creator-global defines
*******************************************************************************/
#ifdef CYIPBLOCK_m0s8csdv2_VERSION
    #define CapSense_CSDV2                              (1u)
#else
    #define CapSense_CSDV2                              (0u)
#endif  /* CYIPBLOCK_m0s8csdv2_VERSION */

#define CapSense_2000_MV                            (2000u)

#ifdef CYDEV_VDDA_MV
    #define CapSense_CYDEV_VDDA_MV                  (CYDEV_VDDA_MV)
#else
    #define CapSense_CYDEV_VDDA_MV                  (CYDEV_VDD_MV)
#endif  /* #ifdef CYDEV_VDDA_MV */

#define CapSense_BAD_CONVERSIONS_NUM                (1u)
#define CapSense_RESAMPLING_CYCLES_MAX_NUMBER       (1u)

/*******************************************************************************
* Enabled Scan Methods
*******************************************************************************/
#define CapSense_CSD_EN                   (1u)
#define CapSense_CSX_EN                   (0u)
#define CapSense_CSD_CSX_EN               (CapSense_CSD_EN & CapSense_CSX_EN)
#define CapSense_CSD2X_EN                 (0u)
#define CapSense_CSX2X_EN                 (0u)

/*******************************************************************************
* Definitions for number of widgets and sensors
*******************************************************************************/
#define CapSense_TOTAL_WIDGETS            (32u)
#define CapSense_TOTAL_CSD_WIDGETS        (32u)
#define CapSense_TOTAL_CSD_SENSORS        (32u)
#define CapSense_TOTAL_CSX_WIDGETS        (0u)
#define CapSense_TOTAL_CSX_NODES          (0u)

/*******************************************************************************
* Total number of CSD sensors + CSX nodes
*******************************************************************************/
#define CapSense_TOTAL_SENSORS            (CapSense_TOTAL_CSD_SENSORS + \
                                                   CapSense_TOTAL_CSX_NODES)

/*******************************************************************************
* Total number of scan slots (used only when dual-channel scan is enabled)
*******************************************************************************/
#define CapSense_TOTAL_SCAN_SLOTS         (32u)

/*******************************************************************************
* Define widget IDs
*******************************************************************************/
#define CapSense_BUTTON0_WDGT_ID                (0u)
#define CapSense_BUTTON1_WDGT_ID                (1u)
#define CapSense_BUTTON2_WDGT_ID                (2u)
#define CapSense_BUTTON3_WDGT_ID                (3u)
#define CapSense_BUTTON4_WDGT_ID                (4u)
#define CapSense_BUTTON5_WDGT_ID                (5u)
#define CapSense_BUTTON6_WDGT_ID                (6u)
#define CapSense_BUTTON7_WDGT_ID                (7u)
#define CapSense_BUTTON8_WDGT_ID                (8u)
#define CapSense_BUTTON9_WDGT_ID                (9u)
#define CapSense_BUTTON10_WDGT_ID               (10u)
#define CapSense_BUTTON11_WDGT_ID               (11u)
#define CapSense_BUTTON12_WDGT_ID               (12u)
#define CapSense_BUTTON13_WDGT_ID               (13u)
#define CapSense_BUTTON14_WDGT_ID               (14u)
#define CapSense_BUTTON15_WDGT_ID               (15u)
#define CapSense_BUTTON16_WDGT_ID               (16u)
#define CapSense_BUTTON17_WDGT_ID               (17u)
#define CapSense_BUTTON18_WDGT_ID               (18u)
#define CapSense_BUTTON19_WDGT_ID               (19u)
#define CapSense_BUTTON20_WDGT_ID               (20u)
#define CapSense_BUTTON21_WDGT_ID               (21u)
#define CapSense_BUTTON22_WDGT_ID               (22u)
#define CapSense_BUTTON23_WDGT_ID               (23u)
#define CapSense_BUTTON24_WDGT_ID               (24u)
#define CapSense_BUTTON25_WDGT_ID               (25u)
#define CapSense_BUTTON26_WDGT_ID               (26u)
#define CapSense_BUTTON27_WDGT_ID               (27u)
#define CapSense_BUTTON28_WDGT_ID               (28u)
#define CapSense_BUTTON29_WDGT_ID               (29u)
#define CapSense_BUTTON30_WDGT_ID               (30u)
#define CapSense_BUTTON31_WDGT_ID               (31u)

/*******************************************************************************
* Define sensor IDs
*******************************************************************************/

/* Button0 */
#define CapSense_BUTTON0_SNS0_ID                (0u)

/* Button1 */
#define CapSense_BUTTON1_SNS0_ID                (0u)

/* Button2 */
#define CapSense_BUTTON2_SNS0_ID                (0u)

/* Button3 */
#define CapSense_BUTTON3_SNS0_ID                (0u)

/* Button4 */
#define CapSense_BUTTON4_SNS0_ID                (0u)

/* Button5 */
#define CapSense_BUTTON5_SNS0_ID                (0u)

/* Button6 */
#define CapSense_BUTTON6_SNS0_ID                (0u)

/* Button7 */
#define CapSense_BUTTON7_SNS0_ID                (0u)

/* Button8 */
#define CapSense_BUTTON8_SNS0_ID                (0u)

/* Button9 */
#define CapSense_BUTTON9_SNS0_ID                (0u)

/* Button10 */
#define CapSense_BUTTON10_SNS0_ID               (0u)

/* Button11 */
#define CapSense_BUTTON11_SNS0_ID               (0u)

/* Button12 */
#define CapSense_BUTTON12_SNS0_ID               (0u)

/* Button13 */
#define CapSense_BUTTON13_SNS0_ID               (0u)

/* Button14 */
#define CapSense_BUTTON14_SNS0_ID               (0u)

/* Button15 */
#define CapSense_BUTTON15_SNS0_ID               (0u)

/* Button16 */
#define CapSense_BUTTON16_SNS0_ID               (0u)

/* Button17 */
#define CapSense_BUTTON17_SNS0_ID               (0u)

/* Button18 */
#define CapSense_BUTTON18_SNS0_ID               (0u)

/* Button19 */
#define CapSense_BUTTON19_SNS0_ID               (0u)

/* Button20 */
#define CapSense_BUTTON20_SNS0_ID               (0u)

/* Button21 */
#define CapSense_BUTTON21_SNS0_ID               (0u)

/* Button22 */
#define CapSense_BUTTON22_SNS0_ID               (0u)

/* Button23 */
#define CapSense_BUTTON23_SNS0_ID               (0u)

/* Button24 */
#define CapSense_BUTTON24_SNS0_ID               (0u)

/* Button25 */
#define CapSense_BUTTON25_SNS0_ID               (0u)

/* Button26 */
#define CapSense_BUTTON26_SNS0_ID               (0u)

/* Button27 */
#define CapSense_BUTTON27_SNS0_ID               (0u)

/* Button28 */
#define CapSense_BUTTON28_SNS0_ID               (0u)

/* Button29 */
#define CapSense_BUTTON29_SNS0_ID               (0u)

/* Button30 */
#define CapSense_BUTTON30_SNS0_ID               (0u)

/* Button31 */
#define CapSense_BUTTON31_SNS0_ID               (0u)



/*******************************************************************************
* Enabled widget types
*******************************************************************************/
#define CapSense_BUTTON_WIDGET_EN         (1u)
#define CapSense_SLIDER_WIDGET_EN         (0u)
#define CapSense_MATRIX_WIDGET_EN         (0u)
#define CapSense_PROXIMITY_WIDGET_EN      (0u)
#define CapSense_TOUCHPAD_WIDGET_EN       (0u)

#define CapSense_CSD_MATRIX_WIDGET_EN     (0u)
#define CapSense_CSD_TOUCHPAD_WIDGET_EN   (0u)

#define CapSense_CSX_MATRIX_WIDGET_EN     (0u)
#define CapSense_CSX_TOUCHPAD_WIDGET_EN   (0u)

/*******************************************************************************
* Centroid APIs
*******************************************************************************/
#define CapSense_CENTROID_EN              (0u)
#define CapSense_TOTAL_DIPLEXED_SLIDERS   (0u)
#define CapSense_TOTAL_LINEAR_SLIDERS     (0u)
#define CapSense_TOTAL_RADIAL_SLIDERS     (0u)
#define CapSense_TOTAL_TOUCHPADS          (0u)
#define CapSense_MAX_CENTROID_LENGTH      (0u)

/*******************************************************************************
* Enabled sensor types
*******************************************************************************/
#define CapSense_REGULAR_SENSOR_EN        (1u)
#define CapSense_PROXIMITY_SENSOR_EN      (0u)

/*******************************************************************************
* Sensor ganging
*******************************************************************************/
#define CapSense_GANGED_SNS_EN            (0u)
#define CapSense_CSD_GANGED_SNS_EN        (0u)
#define CapSense_CSX_GANGED_SNS_EN        (0u)

/*******************************************************************************
* Max number of sensors used among all widgets
*******************************************************************************/
#define CapSense_MAX_SENSORS_PER_WIDGET   (1u)

/*******************************************************************************
* Total number of all used electrodes (NOT unique)
*******************************************************************************/
#define CapSense_TOTAL_ELECTRODES         (32u)
/* Obsolete */
#define CapSense_TOTAL_SENSOR_IOS         CapSense_TOTAL_ELECTRODES

/*******************************************************************************
* Total number of used physical IOs (unique)
*******************************************************************************/
#define CapSense_TOTAL_IO_CNT             (32u)

/*******************************************************************************
* Array length for widget status registers
*******************************************************************************/
#define CapSense_WDGT_STATUS_WORDS        \
                        (((uint8)((CapSense_TOTAL_WIDGETS - 1u) / 32u)) + 1u)


/*******************************************************************************
* Auto-tuning mode selection
*******************************************************************************/
#define CapSense_CSD_SS_DIS         (0x00ul)
#define CapSense_CSD_SS_HW_EN       (0x01ul)
#define CapSense_CSD_SS_TH_EN       (0x02ul)
#define CapSense_CSD_SS_HWTH_EN     (CapSense_CSD_SS_HW_EN | \
                                             CapSense_CSD_SS_TH_EN)

#define CapSense_CSD_AUTOTUNE       CapSense_CSD_SS_HWTH_EN


/*******************************************************************************
* General settings
*******************************************************************************/

#define CapSense_AUTO_RESET_METHOD_LEGACY (0u)
#define CapSense_AUTO_RESET_METHOD_SAMPLE (1u)

#define CapSense_MULTI_FREQ_SCAN_EN       (0u)
#define CapSense_SENSOR_AUTO_RESET_EN     (0u)
#define CapSense_SENSOR_AUTO_RESET_METHOD (0u)
#define CapSense_NUM_CENTROIDS            (1u)
#define CapSense_OFF_DEBOUNCE_EN          (0u)

/* Define power status of HW IP block after scanning */
#define CapSense_BLOCK_OFF_AFTER_SCAN_EN  (0u)

/* Define number of scan frequencies */
#if (CapSense_DISABLE != CapSense_MULTI_FREQ_SCAN_EN)
    #define CapSense_NUM_SCAN_FREQS       (3u)
#else
    #define CapSense_NUM_SCAN_FREQS       (1u)
#endif /* #if (CapSense_DISABLE != CapSense_MULTI_FREQ_SCAN_EN) */

/* Data size for thresholds / low baseline reset */
#define CapSense_SIZE_8BITS               (8u)
#define CapSense_SIZE_16BITS              (16u)

#define CapSense_THRESHOLD_SIZE           CapSense_SIZE_16BITS
typedef uint16 CapSense_THRESHOLD_TYPE;

#if (CapSense_AUTO_RESET_METHOD_LEGACY == CapSense_SENSOR_AUTO_RESET_METHOD)
    #define CapSense_LOW_BSLN_RST_SIZE        CapSense_SIZE_8BITS
    typedef uint8 CapSense_LOW_BSLN_RST_TYPE;
#else
    #define CapSense_LOW_BSLN_RST_SIZE    (16u)
    typedef uint16 CapSense_LOW_BSLN_RST_TYPE;
#endif /* #if (CapSense_AUTO_RESET_METHOD_LEGACY == CapSense_SENSOR_AUTO_RESET_METHOD) */

/* Coefficient to define touch threshold for proximity sensors */
#define CapSense_PROX_TOUCH_COEFF         (300u)

/*******************************************************************************
* General Filter Constants
*******************************************************************************/

/* Baseline algorithm options */
#define CapSense_IIR_BASELINE                 (0u)
#define CapSense_BUCKET_BASELINE              (1u)

#define CapSense_BASELINE_TYPE                CapSense_IIR_BASELINE

/* IIR baseline filter algorithm for regular sensors*/
#define CapSense_REGULAR_IIR_BL_TYPE          CapSense_IIR_FILTER_PERFORMANCE

/* IIR baseline coefficients for regular sensors */
#define CapSense_REGULAR_IIR_BL_N             (1u)
#define CapSense_REGULAR_IIR_BL_SHIFT         (8u)

/* IIR baseline filter algorithm for proximity sensors*/
#define CapSense_PROX_IIR_BL_TYPE             CapSense_IIR_FILTER_PERFORMANCE

/* IIR baseline coefficients for proximity sensors */
#define CapSense_PROX_IIR_BL_N                (1u)
#define CapSense_PROX_IIR_BL_SHIFT            (8u)


/* IIR filter constants */
#define CapSense_IIR_COEFFICIENT_K            (256u)

/* IIR filter type */
#define CapSense_IIR_FILTER_STANDARD          (1u)
#define CapSense_IIR_FILTER_PERFORMANCE       (2u)
#define CapSense_IIR_FILTER_MEMORY            (3u)

/* Regular sensor raw-count filters */
#define CapSense_REGULAR_RC_FILTER_EN         (0u)
#define CapSense_REGULAR_RC_IIR_FILTER_EN     (0u)
#define CapSense_REGULAR_RC_MEDIAN_FILTER_EN  (0u)
#define CapSense_REGULAR_RC_AVERAGE_FILTER_EN (0u)
#define CapSense_REGULAR_RC_CUSTOM_FILTER_EN  (0u)

/* Proximity sensor raw-count filters */
#define CapSense_PROX_RC_FILTER_EN            (0u)
#define CapSense_PROX_RC_IIR_FILTER_EN        (0u)
#define CapSense_PROX_RC_MEDIAN_FILTER_EN     (0u)
#define CapSense_PROX_RC_AVERAGE_FILTER_EN    (0u)
#define CapSense_PROX_RC_CUSTOM_FILTER_EN     (0u)

/* IIR raw-count filter algorithm for regular sensors */
#define CapSense_REGULAR_IIR_RC_TYPE          (CapSense_IIR_FILTER_STANDARD)

/* IIR raw-count filter coefficients for regular sensors */
#define CapSense_REGULAR_IIR_RC_N             (128u)
#define CapSense_REGULAR_IIR_RC_SHIFT         (0u)

/* IIR raw-count filter algorithm for proximity sensors*/
#define CapSense_PROX_IIR_RC_TYPE             (CapSense_IIR_FILTER_STANDARD)

/* IIR raw-count filter coefficients for proximity sensors */
#define CapSense_PROX_IIR_RC_N                (128u)
#define CapSense_PROX_IIR_RC_SHIFT            (0u)

/* Median filter constants */

/* Order of regular sensor median filter */
#define CapSense_REGULAR_MEDIAN_LEN           (2u)

/* Order of proximity sensor median filter */
#define CapSense_PROX_MEDIAN_LEN              (2u)

/* Average filter constants*/
#define CapSense_AVERAGE_FILTER_LEN_2         (2u)
#define CapSense_AVERAGE_FILTER_LEN_4         (4u)

/* Order of regular sensor average filter */
#define CapSense_REGULAR_AVERAGE_LEN          (CapSense_AVERAGE_FILTER_LEN_4)

/* Order of proximity sensor average filter */
#define CapSense_PROX_AVERAGE_LEN             (CapSense_AVERAGE_FILTER_LEN_4)


/* Centroid position filters */
#define CapSense_POS_IIR_FILTER_EN            (0x00u)
#define CapSense_POS_MEDIAN_FILTER_EN         (0x00u)
#define CapSense_POS_AVERAGE_FILTER_EN        (0x00u)
#define CapSense_POS_JITTER_FILTER_EN         (0x00u)
#define CapSense_CSX_TOUCHPAD_POS_MEDIAN_FILTER_EN (0x00u)

#define CapSense_POS_IIR_COEFF                (128u)
#define CapSense_CSX_TOUCHPAD_UNDEFINED       (40u)


/* IDAC options */

/* CSDv1 IDAC gain */
#define CapSense_IDAC_GAIN_4X                 (4u)
#define CapSense_IDAC_GAIN_8X                 (8u)

/* CSDv2 IDAC gain */
#define CapSense_IDAC_GAIN_LOW                (0uL)
#define CapSense_IDAC_GAIN_MEDIUM             (1uL)
#define CapSense_IDAC_GAIN_HIGH               (2uL)

#define CapSense_IDAC_SOURCING                (0u)
#define CapSense_IDAC_SINKING                 (1u)

/* Shield tank capacitor precharge source */
#define CapSense_CSH_PRECHARGE_VREF           (0u)
#define CapSense_CSH_PRECHARGE_IO_BUF         (1u)

/* Shield electrode delay */
#define CapSense_NO_DELAY                     (0u)
/* CSDv1 */
#define CapSense_SH_DELAY_50NS                (1u)
#define CapSense_SH_DELAY_100NS               (2u)
/* CSDv2 */
#define CapSense_SH_DELAY_5NS                 (1u)
#define CapSense_SH_DELAY_10NS                (2u)
#define CapSense_SH_DELAY_20NS                (3u)

/* Inactive sensor connection options */
#define CapSense_SNS_CONNECTION_GROUND        (0x00000006Lu)
#define CapSense_SNS_CONNECTION_HIGHZ         (0x00000000Lu)
#define CapSense_SNS_CONNECTION_SHIELD        (0x00000002Lu)

/* Sense clock selection options */
#if defined(CapSense_TAPEOUT_STAR_USED)
    #define CapSense_CSDV2_REF9P6UA_EN            (0u)
#else
    #define CapSense_CSDV2_REF9P6UA_EN            (0u)
#endif /* defined(CapSense_TAPEOUT_A_USED) */

#define CapSense_CLK_SOURCE_DIRECT            (0x00000000Lu)

#define CapSense_CLK_SOURCE_SSC1              (0x01u)
#define CapSense_CLK_SOURCE_SSC2              (0x02u)
#define CapSense_CLK_SOURCE_SSC3              (0x03u)
#define CapSense_CLK_SOURCE_SSC4              (0x04u)

/* CSDv1 and CSDv2 */
#define CapSense_CLK_SOURCE_PRS8              (0x05u)
#define CapSense_CLK_SOURCE_PRS12             (0x06u)
#define CapSense_CLK_SOURCE_PRSAUTO           (0xFFu)

/* Defines scan resolutions */
#define CapSense_RES6BIT                      (6u)
#define CapSense_RES7BIT                      (7u)
#define CapSense_RES8BIT                      (8u)
#define CapSense_RES9BIT                      (9u)
#define CapSense_RES10BIT                     (10u)
#define CapSense_RES11BIT                     (11u)
#define CapSense_RES12BIT                     (12u)
#define CapSense_RES13BIT                     (13u)
#define CapSense_RES14BIT                     (14u)
#define CapSense_RES15BIT                     (15u)
#define CapSense_RES16BIT                     (16u)

/* CSDv2: Initialization switch resistance */
#define CapSense_INIT_SW_RES_LOW              (0x00000000Lu)
#define CapSense_INIT_SW_RES_MEDIUM           (0x00000001Lu)
#define CapSense_INIT_SW_RES_HIGH             (0x00000002Lu)

/* CSDv2: Initialization switch resistance */
#define CapSense_SCAN_SW_RES_LOW              (0x00000000Lu)
#define CapSense_SCAN_SW_RES_MEDIUM           (0x00000001Lu)
#define CapSense_SCAN_SW_RES_HIGH             (0x00000002Lu)

/* CSDv2: CSD shield switch resistance */
#define CapSense_SHIELD_SW_RES_LOW            (0x00000000Lu)
#define CapSense_SHIELD_SW_RES_MEDIUM         (0x00000001Lu)
#define CapSense_SHIELD_SW_RES_HIGH           (0x00000002Lu)
#define CapSense_SHIELD_SW_RES_LOW_EMI        (0x00000003Lu)

/* CSDv2: CSD shield switch resistance */
#define CapSense_INIT_SHIELD_SW_RES_LOW       (0x00000000Lu)
#define CapSense_INIT_SHIELD_SW_RES_MEDIUM    (0x00000001Lu)
#define CapSense_INIT_SHIELD_SW_RES_HIGH      (0x00000002Lu)
#define CapSense_INIT_SHIELD_SW_RES_LOW_EMI   (0x00000003Lu)

/* CSDv2: CSD shield switch resistance */
#define CapSense_SCAN_SHIELD_SW_RES_LOW            (0x00000000Lu)
#define CapSense_SCAN_SHIELD_SW_RES_MEDIUM         (0x00000001Lu)
#define CapSense_SCAN_SHIELD_SW_RES_HIGH           (0x00000002Lu)
#define CapSense_SCAN_SHIELD_SW_RES_LOW_EMI        (0x00000003Lu)

/*******************************************************************************
* CSD Specific settings
*******************************************************************************/

/* CSD scan method settings */
#define CapSense_CSD_IDAC_AUTOCAL_EN          (1u)
#define CapSense_CSD_IDAC_GAIN                (CapSense_IDAC_GAIN_4X)
#define CapSense_CSD_SHIELD_EN                (0u)
#define CapSense_CSD_SHIELD_TANK_EN           (0u)
#define CapSense_CSD_CSH_PRECHARGE_SRC        (CapSense_CSH_PRECHARGE_VREF)
#define CapSense_CSD_SHIELD_DELAY             (CapSense_NO_DELAY)
#define CapSense_CSD_TOTAL_SHIELD_COUNT       (0u)
#define CapSense_CSD_SCANSPEED_DIVIDER        (2u)
#define CapSense_CSD_COMMON_SNS_CLK_EN        (0u)
#define CapSense_CSD_SNS_CLK_SOURCE           (CapSense_CLK_SOURCE_PRSAUTO)
#define CapSense_CSD_SNS_CLK_DIVIDER          (8u)
#define CapSense_CSD_INACTIVE_SNS_CONNECTION  (CapSense_SNS_CONNECTION_GROUND)
#define CapSense_CSD_IDAC_COMP_EN             (1u)
#define CapSense_CSD_IDAC_CONFIG              (CapSense_IDAC_SOURCING)
#define CapSense_CSD_RAWCOUNT_CAL_LEVEL       (85u)
#define CapSense_CSD_DUALIDAC_LEVEL           (50u)
#define CapSense_CSD_PRESCAN_SETTLING_TIME    (5u)
#define CapSense_CSD_SNSCLK_R_CONST           (1000u)
#define CapSense_CSD_VREF_MV                  (1200u)

/* CSD settings - CSDv2 */
#define CapSense_CSD_DEDICATED_IDAC_COMP_EN   (1u)
#define CapSense_CSD_AUTO_ZERO_EN             (0u)
#define CapSense_CSD_AUTO_ZERO_TIME           (15Lu)
#define CapSense_CSD_NOISE_METRIC_EN          (0u)
#define CapSense_CSD_NOISE_METRIC_TH          (1Lu)
#define CapSense_CSD_INIT_SWITCH_RES          (CapSense_INIT_SW_RES_MEDIUM)
#define CapSense_CSD_SHIELD_SWITCH_RES        (CapSense_SHIELD_SW_RES_MEDIUM)
#define CapSense_CSD_GAIN                     (31Lu)


/*******************************************************************************
* CSX Specific settings
*******************************************************************************/

/* CSX scan method settings */
#define CapSense_CSX_SCANSPEED_DIVIDER        (2u)
#define CapSense_CSX_COMMON_TX_CLK_EN         (0u)
#define CapSense_CSX_TX_CLK_SOURCE            (CapSense_CLK_SOURCE_DIRECT)
#define CapSense_CSX_TX_CLK_DIVIDER           (80u)
#define CapSense_CSX_MAX_FINGERS              (1u)
#define CapSense_CSX_MAX_LOCAL_PEAKS          (5u)
#define CapSense_CSX_IDAC_AUTOCAL_EN          (0u)
#define CapSense_CSX_IDAC_BITS_USED           (8u)
#define CapSense_CSX_RAWCOUNT_CAL_LEVEL       (40u)
#define CapSense_CSX_IDAC_GAIN                (CapSense_IDAC_GAIN_4X)
#define CapSense_CSX_SKIP_OVSMPL_SPECIFIC_NODES (0u)
#define CapSense_CSX_MULTIPHASE_TX_EN         (0u)
#define CapSense_CSX_MAX_TX_PHASE_LENGTH      (0u)

/* CSX settings - CSDv2 */
#define CapSense_CSX_AUTO_ZERO_EN             (0u)
#define CapSense_CSX_AUTO_ZERO_TIME           (15u)
#define CapSense_CSX_FINE_INIT_TIME           (4u)
#define CapSense_CSX_NOISE_METRIC_EN          (0u)
#define CapSense_CSX_NOISE_METRIC_TH          (1u)
#define CapSense_CSX_INIT_SWITCH_RES          (CapSense_INIT_SW_RES_MEDIUM)
#define CapSense_CSX_SCAN_SWITCH_RES          (CapSense_SCAN_SW_RES_LOW)
#define CapSense_CSX_INIT_SHIELD_SWITCH_RES   (CapSense_INIT_SHIELD_SW_RES_HIGH)
#define CapSense_CSX_SCAN_SHIELD_SWITCH_RES   (CapSense_SCAN_SHIELD_SW_RES_LOW)


/*******************************************************************************
* Global Parameter Definitions
*******************************************************************************/

/* RAM Global Parameters Definitions */
#define CapSense_CONFIG_ID                      (0xA754u)
#define CapSense_DEVICE_ID                      (0x00C0u)
#define CapSense_CSD0_CONFIG                    (0x0000u)

/***************************************************************************//**
* Button0 initialization values for FLASH data structure
*******************************************************************************/
#define CapSense_BUTTON0_STATIC_CONFIG          (1u)
#define CapSense_BUTTON0_NUM_SENSORS            (1u)

/***************************************************************************//**
* Button0 initialization values for RAM data structure
*******************************************************************************/
#define CapSense_BUTTON0_RESOLUTION             (CapSense_RES12BIT)
#define CapSense_BUTTON0_FINGER_TH              (100u)
#define CapSense_BUTTON0_NOISE_TH               (40u)
#define CapSense_BUTTON0_NNOISE_TH              (40u)
#define CapSense_BUTTON0_HYSTERESIS             (10u)
#define CapSense_BUTTON0_ON_DEBOUNCE            (3u)
#define CapSense_BUTTON0_LOW_BSLN_RST           (30u)
#define CapSense_BUTTON0_BSLN_COEFF             (100u)
#define CapSense_BUTTON0_IDAC_MOD0              (32u)
#define CapSense_BUTTON0_SNS_CLK                (4u)
#define CapSense_BUTTON0_SNS_CLK_SOURCE         (0u)
#define CapSense_BUTTON0_FINGER_CAP             (800u)
#define CapSense_BUTTON0_SIGPFC                 (0u)

/***************************************************************************//**
* Button1 initialization values for FLASH data structure
*******************************************************************************/
#define CapSense_BUTTON1_STATIC_CONFIG          (1u)
#define CapSense_BUTTON1_NUM_SENSORS            (1u)

/***************************************************************************//**
* Button1 initialization values for RAM data structure
*******************************************************************************/
#define CapSense_BUTTON1_RESOLUTION             (CapSense_RES12BIT)
#define CapSense_BUTTON1_FINGER_TH              (100u)
#define CapSense_BUTTON1_NOISE_TH               (40u)
#define CapSense_BUTTON1_NNOISE_TH              (40u)
#define CapSense_BUTTON1_HYSTERESIS             (10u)
#define CapSense_BUTTON1_ON_DEBOUNCE            (3u)
#define CapSense_BUTTON1_LOW_BSLN_RST           (30u)
#define CapSense_BUTTON1_BSLN_COEFF             (100u)
#define CapSense_BUTTON1_IDAC_MOD0              (32u)
#define CapSense_BUTTON1_SNS_CLK                (4u)
#define CapSense_BUTTON1_SNS_CLK_SOURCE         (0u)
#define CapSense_BUTTON1_FINGER_CAP             (800u)
#define CapSense_BUTTON1_SIGPFC                 (0u)

/***************************************************************************//**
* Button2 initialization values for FLASH data structure
*******************************************************************************/
#define CapSense_BUTTON2_STATIC_CONFIG          (1u)
#define CapSense_BUTTON2_NUM_SENSORS            (1u)

/***************************************************************************//**
* Button2 initialization values for RAM data structure
*******************************************************************************/
#define CapSense_BUTTON2_RESOLUTION             (CapSense_RES12BIT)
#define CapSense_BUTTON2_FINGER_TH              (100u)
#define CapSense_BUTTON2_NOISE_TH               (40u)
#define CapSense_BUTTON2_NNOISE_TH              (40u)
#define CapSense_BUTTON2_HYSTERESIS             (10u)
#define CapSense_BUTTON2_ON_DEBOUNCE            (3u)
#define CapSense_BUTTON2_LOW_BSLN_RST           (30u)
#define CapSense_BUTTON2_BSLN_COEFF             (100u)
#define CapSense_BUTTON2_IDAC_MOD0              (32u)
#define CapSense_BUTTON2_SNS_CLK                (4u)
#define CapSense_BUTTON2_SNS_CLK_SOURCE         (0u)
#define CapSense_BUTTON2_FINGER_CAP             (800u)
#define CapSense_BUTTON2_SIGPFC                 (0u)

/***************************************************************************//**
* Button3 initialization values for FLASH data structure
*******************************************************************************/
#define CapSense_BUTTON3_STATIC_CONFIG          (1u)
#define CapSense_BUTTON3_NUM_SENSORS            (1u)

/***************************************************************************//**
* Button3 initialization values for RAM data structure
*******************************************************************************/
#define CapSense_BUTTON3_RESOLUTION             (CapSense_RES12BIT)
#define CapSense_BUTTON3_FINGER_TH              (100u)
#define CapSense_BUTTON3_NOISE_TH               (40u)
#define CapSense_BUTTON3_NNOISE_TH              (40u)
#define CapSense_BUTTON3_HYSTERESIS             (10u)
#define CapSense_BUTTON3_ON_DEBOUNCE            (3u)
#define CapSense_BUTTON3_LOW_BSLN_RST           (30u)
#define CapSense_BUTTON3_BSLN_COEFF             (100u)
#define CapSense_BUTTON3_IDAC_MOD0              (32u)
#define CapSense_BUTTON3_SNS_CLK                (4u)
#define CapSense_BUTTON3_SNS_CLK_SOURCE         (0u)
#define CapSense_BUTTON3_FINGER_CAP             (800u)
#define CapSense_BUTTON3_SIGPFC                 (0u)

/***************************************************************************//**
* Button4 initialization values for FLASH data structure
*******************************************************************************/
#define CapSense_BUTTON4_STATIC_CONFIG          (1u)
#define CapSense_BUTTON4_NUM_SENSORS            (1u)

/***************************************************************************//**
* Button4 initialization values for RAM data structure
*******************************************************************************/
#define CapSense_BUTTON4_RESOLUTION             (CapSense_RES12BIT)
#define CapSense_BUTTON4_FINGER_TH              (100u)
#define CapSense_BUTTON4_NOISE_TH               (40u)
#define CapSense_BUTTON4_NNOISE_TH              (40u)
#define CapSense_BUTTON4_HYSTERESIS             (10u)
#define CapSense_BUTTON4_ON_DEBOUNCE            (3u)
#define CapSense_BUTTON4_LOW_BSLN_RST           (30u)
#define CapSense_BUTTON4_BSLN_COEFF             (100u)
#define CapSense_BUTTON4_IDAC_MOD0              (32u)
#define CapSense_BUTTON4_SNS_CLK                (4u)
#define CapSense_BUTTON4_SNS_CLK_SOURCE         (0u)
#define CapSense_BUTTON4_FINGER_CAP             (800u)
#define CapSense_BUTTON4_SIGPFC                 (0u)

/***************************************************************************//**
* Button5 initialization values for FLASH data structure
*******************************************************************************/
#define CapSense_BUTTON5_STATIC_CONFIG          (1u)
#define CapSense_BUTTON5_NUM_SENSORS            (1u)

/***************************************************************************//**
* Button5 initialization values for RAM data structure
*******************************************************************************/
#define CapSense_BUTTON5_RESOLUTION             (CapSense_RES12BIT)
#define CapSense_BUTTON5_FINGER_TH              (100u)
#define CapSense_BUTTON5_NOISE_TH               (40u)
#define CapSense_BUTTON5_NNOISE_TH              (40u)
#define CapSense_BUTTON5_HYSTERESIS             (10u)
#define CapSense_BUTTON5_ON_DEBOUNCE            (3u)
#define CapSense_BUTTON5_LOW_BSLN_RST           (30u)
#define CapSense_BUTTON5_BSLN_COEFF             (100u)
#define CapSense_BUTTON5_IDAC_MOD0              (32u)
#define CapSense_BUTTON5_SNS_CLK                (4u)
#define CapSense_BUTTON5_SNS_CLK_SOURCE         (0u)
#define CapSense_BUTTON5_FINGER_CAP             (800u)
#define CapSense_BUTTON5_SIGPFC                 (0u)

/***************************************************************************//**
* Button6 initialization values for FLASH data structure
*******************************************************************************/
#define CapSense_BUTTON6_STATIC_CONFIG          (1u)
#define CapSense_BUTTON6_NUM_SENSORS            (1u)

/***************************************************************************//**
* Button6 initialization values for RAM data structure
*******************************************************************************/
#define CapSense_BUTTON6_RESOLUTION             (CapSense_RES12BIT)
#define CapSense_BUTTON6_FINGER_TH              (100u)
#define CapSense_BUTTON6_NOISE_TH               (40u)
#define CapSense_BUTTON6_NNOISE_TH              (40u)
#define CapSense_BUTTON6_HYSTERESIS             (10u)
#define CapSense_BUTTON6_ON_DEBOUNCE            (3u)
#define CapSense_BUTTON6_LOW_BSLN_RST           (30u)
#define CapSense_BUTTON6_BSLN_COEFF             (100u)
#define CapSense_BUTTON6_IDAC_MOD0              (32u)
#define CapSense_BUTTON6_SNS_CLK                (4u)
#define CapSense_BUTTON6_SNS_CLK_SOURCE         (0u)
#define CapSense_BUTTON6_FINGER_CAP             (800u)
#define CapSense_BUTTON6_SIGPFC                 (0u)

/***************************************************************************//**
* Button7 initialization values for FLASH data structure
*******************************************************************************/
#define CapSense_BUTTON7_STATIC_CONFIG          (1u)
#define CapSense_BUTTON7_NUM_SENSORS            (1u)

/***************************************************************************//**
* Button7 initialization values for RAM data structure
*******************************************************************************/
#define CapSense_BUTTON7_RESOLUTION             (CapSense_RES12BIT)
#define CapSense_BUTTON7_FINGER_TH              (100u)
#define CapSense_BUTTON7_NOISE_TH               (40u)
#define CapSense_BUTTON7_NNOISE_TH              (40u)
#define CapSense_BUTTON7_HYSTERESIS             (10u)
#define CapSense_BUTTON7_ON_DEBOUNCE            (3u)
#define CapSense_BUTTON7_LOW_BSLN_RST           (30u)
#define CapSense_BUTTON7_BSLN_COEFF             (100u)
#define CapSense_BUTTON7_IDAC_MOD0              (32u)
#define CapSense_BUTTON7_SNS_CLK                (4u)
#define CapSense_BUTTON7_SNS_CLK_SOURCE         (0u)
#define CapSense_BUTTON7_FINGER_CAP             (800u)
#define CapSense_BUTTON7_SIGPFC                 (0u)

/***************************************************************************//**
* Button8 initialization values for FLASH data structure
*******************************************************************************/
#define CapSense_BUTTON8_STATIC_CONFIG          (1u)
#define CapSense_BUTTON8_NUM_SENSORS            (1u)

/***************************************************************************//**
* Button8 initialization values for RAM data structure
*******************************************************************************/
#define CapSense_BUTTON8_RESOLUTION             (CapSense_RES12BIT)
#define CapSense_BUTTON8_FINGER_TH              (100u)
#define CapSense_BUTTON8_NOISE_TH               (40u)
#define CapSense_BUTTON8_NNOISE_TH              (40u)
#define CapSense_BUTTON8_HYSTERESIS             (10u)
#define CapSense_BUTTON8_ON_DEBOUNCE            (3u)
#define CapSense_BUTTON8_LOW_BSLN_RST           (30u)
#define CapSense_BUTTON8_BSLN_COEFF             (100u)
#define CapSense_BUTTON8_IDAC_MOD0              (32u)
#define CapSense_BUTTON8_SNS_CLK                (4u)
#define CapSense_BUTTON8_SNS_CLK_SOURCE         (0u)
#define CapSense_BUTTON8_FINGER_CAP             (800u)
#define CapSense_BUTTON8_SIGPFC                 (0u)

/***************************************************************************//**
* Button9 initialization values for FLASH data structure
*******************************************************************************/
#define CapSense_BUTTON9_STATIC_CONFIG          (1u)
#define CapSense_BUTTON9_NUM_SENSORS            (1u)

/***************************************************************************//**
* Button9 initialization values for RAM data structure
*******************************************************************************/
#define CapSense_BUTTON9_RESOLUTION             (CapSense_RES12BIT)
#define CapSense_BUTTON9_FINGER_TH              (100u)
#define CapSense_BUTTON9_NOISE_TH               (40u)
#define CapSense_BUTTON9_NNOISE_TH              (40u)
#define CapSense_BUTTON9_HYSTERESIS             (10u)
#define CapSense_BUTTON9_ON_DEBOUNCE            (3u)
#define CapSense_BUTTON9_LOW_BSLN_RST           (30u)
#define CapSense_BUTTON9_BSLN_COEFF             (100u)
#define CapSense_BUTTON9_IDAC_MOD0              (32u)
#define CapSense_BUTTON9_SNS_CLK                (4u)
#define CapSense_BUTTON9_SNS_CLK_SOURCE         (0u)
#define CapSense_BUTTON9_FINGER_CAP             (800u)
#define CapSense_BUTTON9_SIGPFC                 (0u)

/***************************************************************************//**
* Button10 initialization values for FLASH data structure
*******************************************************************************/
#define CapSense_BUTTON10_STATIC_CONFIG         (1u)
#define CapSense_BUTTON10_NUM_SENSORS           (1u)

/***************************************************************************//**
* Button10 initialization values for RAM data structure
*******************************************************************************/
#define CapSense_BUTTON10_RESOLUTION            (CapSense_RES12BIT)
#define CapSense_BUTTON10_FINGER_TH             (100u)
#define CapSense_BUTTON10_NOISE_TH              (40u)
#define CapSense_BUTTON10_NNOISE_TH             (40u)
#define CapSense_BUTTON10_HYSTERESIS            (10u)
#define CapSense_BUTTON10_ON_DEBOUNCE           (3u)
#define CapSense_BUTTON10_LOW_BSLN_RST          (30u)
#define CapSense_BUTTON10_BSLN_COEFF            (100u)
#define CapSense_BUTTON10_IDAC_MOD0             (32u)
#define CapSense_BUTTON10_SNS_CLK               (4u)
#define CapSense_BUTTON10_SNS_CLK_SOURCE        (0u)
#define CapSense_BUTTON10_FINGER_CAP            (800u)
#define CapSense_BUTTON10_SIGPFC                (0u)

/***************************************************************************//**
* Button11 initialization values for FLASH data structure
*******************************************************************************/
#define CapSense_BUTTON11_STATIC_CONFIG         (1u)
#define CapSense_BUTTON11_NUM_SENSORS           (1u)

/***************************************************************************//**
* Button11 initialization values for RAM data structure
*******************************************************************************/
#define CapSense_BUTTON11_RESOLUTION            (CapSense_RES12BIT)
#define CapSense_BUTTON11_FINGER_TH             (100u)
#define CapSense_BUTTON11_NOISE_TH              (40u)
#define CapSense_BUTTON11_NNOISE_TH             (40u)
#define CapSense_BUTTON11_HYSTERESIS            (10u)
#define CapSense_BUTTON11_ON_DEBOUNCE           (3u)
#define CapSense_BUTTON11_LOW_BSLN_RST          (30u)
#define CapSense_BUTTON11_BSLN_COEFF            (100u)
#define CapSense_BUTTON11_IDAC_MOD0             (32u)
#define CapSense_BUTTON11_SNS_CLK               (4u)
#define CapSense_BUTTON11_SNS_CLK_SOURCE        (0u)
#define CapSense_BUTTON11_FINGER_CAP            (800u)
#define CapSense_BUTTON11_SIGPFC                (0u)

/***************************************************************************//**
* Button12 initialization values for FLASH data structure
*******************************************************************************/
#define CapSense_BUTTON12_STATIC_CONFIG         (1u)
#define CapSense_BUTTON12_NUM_SENSORS           (1u)

/***************************************************************************//**
* Button12 initialization values for RAM data structure
*******************************************************************************/
#define CapSense_BUTTON12_RESOLUTION            (CapSense_RES12BIT)
#define CapSense_BUTTON12_FINGER_TH             (100u)
#define CapSense_BUTTON12_NOISE_TH              (40u)
#define CapSense_BUTTON12_NNOISE_TH             (40u)
#define CapSense_BUTTON12_HYSTERESIS            (10u)
#define CapSense_BUTTON12_ON_DEBOUNCE           (3u)
#define CapSense_BUTTON12_LOW_BSLN_RST          (30u)
#define CapSense_BUTTON12_BSLN_COEFF            (100u)
#define CapSense_BUTTON12_IDAC_MOD0             (32u)
#define CapSense_BUTTON12_SNS_CLK               (4u)
#define CapSense_BUTTON12_SNS_CLK_SOURCE        (0u)
#define CapSense_BUTTON12_FINGER_CAP            (800u)
#define CapSense_BUTTON12_SIGPFC                (0u)

/***************************************************************************//**
* Button13 initialization values for FLASH data structure
*******************************************************************************/
#define CapSense_BUTTON13_STATIC_CONFIG         (1u)
#define CapSense_BUTTON13_NUM_SENSORS           (1u)

/***************************************************************************//**
* Button13 initialization values for RAM data structure
*******************************************************************************/
#define CapSense_BUTTON13_RESOLUTION            (CapSense_RES12BIT)
#define CapSense_BUTTON13_FINGER_TH             (100u)
#define CapSense_BUTTON13_NOISE_TH              (40u)
#define CapSense_BUTTON13_NNOISE_TH             (40u)
#define CapSense_BUTTON13_HYSTERESIS            (10u)
#define CapSense_BUTTON13_ON_DEBOUNCE           (3u)
#define CapSense_BUTTON13_LOW_BSLN_RST          (30u)
#define CapSense_BUTTON13_BSLN_COEFF            (100u)
#define CapSense_BUTTON13_IDAC_MOD0             (32u)
#define CapSense_BUTTON13_SNS_CLK               (4u)
#define CapSense_BUTTON13_SNS_CLK_SOURCE        (0u)
#define CapSense_BUTTON13_FINGER_CAP            (800u)
#define CapSense_BUTTON13_SIGPFC                (0u)

/***************************************************************************//**
* Button14 initialization values for FLASH data structure
*******************************************************************************/
#define CapSense_BUTTON14_STATIC_CONFIG         (1u)
#define CapSense_BUTTON14_NUM_SENSORS           (1u)

/***************************************************************************//**
* Button14 initialization values for RAM data structure
*******************************************************************************/
#define CapSense_BUTTON14_RESOLUTION            (CapSense_RES12BIT)
#define CapSense_BUTTON14_FINGER_TH             (100u)
#define CapSense_BUTTON14_NOISE_TH              (40u)
#define CapSense_BUTTON14_NNOISE_TH             (40u)
#define CapSense_BUTTON14_HYSTERESIS            (10u)
#define CapSense_BUTTON14_ON_DEBOUNCE           (3u)
#define CapSense_BUTTON14_LOW_BSLN_RST          (30u)
#define CapSense_BUTTON14_BSLN_COEFF            (100u)
#define CapSense_BUTTON14_IDAC_MOD0             (32u)
#define CapSense_BUTTON14_SNS_CLK               (4u)
#define CapSense_BUTTON14_SNS_CLK_SOURCE        (0u)
#define CapSense_BUTTON14_FINGER_CAP            (800u)
#define CapSense_BUTTON14_SIGPFC                (0u)

/***************************************************************************//**
* Button15 initialization values for FLASH data structure
*******************************************************************************/
#define CapSense_BUTTON15_STATIC_CONFIG         (1u)
#define CapSense_BUTTON15_NUM_SENSORS           (1u)

/***************************************************************************//**
* Button15 initialization values for RAM data structure
*******************************************************************************/
#define CapSense_BUTTON15_RESOLUTION            (CapSense_RES12BIT)
#define CapSense_BUTTON15_FINGER_TH             (100u)
#define CapSense_BUTTON15_NOISE_TH              (40u)
#define CapSense_BUTTON15_NNOISE_TH             (40u)
#define CapSense_BUTTON15_HYSTERESIS            (10u)
#define CapSense_BUTTON15_ON_DEBOUNCE           (3u)
#define CapSense_BUTTON15_LOW_BSLN_RST          (30u)
#define CapSense_BUTTON15_BSLN_COEFF            (100u)
#define CapSense_BUTTON15_IDAC_MOD0             (32u)
#define CapSense_BUTTON15_SNS_CLK               (4u)
#define CapSense_BUTTON15_SNS_CLK_SOURCE        (0u)
#define CapSense_BUTTON15_FINGER_CAP            (800u)
#define CapSense_BUTTON15_SIGPFC                (0u)

/***************************************************************************//**
* Button16 initialization values for FLASH data structure
*******************************************************************************/
#define CapSense_BUTTON16_STATIC_CONFIG         (1u)
#define CapSense_BUTTON16_NUM_SENSORS           (1u)

/***************************************************************************//**
* Button16 initialization values for RAM data structure
*******************************************************************************/
#define CapSense_BUTTON16_RESOLUTION            (CapSense_RES12BIT)
#define CapSense_BUTTON16_FINGER_TH             (100u)
#define CapSense_BUTTON16_NOISE_TH              (40u)
#define CapSense_BUTTON16_NNOISE_TH             (40u)
#define CapSense_BUTTON16_HYSTERESIS            (10u)
#define CapSense_BUTTON16_ON_DEBOUNCE           (3u)
#define CapSense_BUTTON16_LOW_BSLN_RST          (30u)
#define CapSense_BUTTON16_BSLN_COEFF            (100u)
#define CapSense_BUTTON16_IDAC_MOD0             (32u)
#define CapSense_BUTTON16_SNS_CLK               (4u)
#define CapSense_BUTTON16_SNS_CLK_SOURCE        (0u)
#define CapSense_BUTTON16_FINGER_CAP            (800u)
#define CapSense_BUTTON16_SIGPFC                (0u)

/***************************************************************************//**
* Button17 initialization values for FLASH data structure
*******************************************************************************/
#define CapSense_BUTTON17_STATIC_CONFIG         (1u)
#define CapSense_BUTTON17_NUM_SENSORS           (1u)

/***************************************************************************//**
* Button17 initialization values for RAM data structure
*******************************************************************************/
#define CapSense_BUTTON17_RESOLUTION            (CapSense_RES12BIT)
#define CapSense_BUTTON17_FINGER_TH             (100u)
#define CapSense_BUTTON17_NOISE_TH              (40u)
#define CapSense_BUTTON17_NNOISE_TH             (40u)
#define CapSense_BUTTON17_HYSTERESIS            (10u)
#define CapSense_BUTTON17_ON_DEBOUNCE           (3u)
#define CapSense_BUTTON17_LOW_BSLN_RST          (30u)
#define CapSense_BUTTON17_BSLN_COEFF            (100u)
#define CapSense_BUTTON17_IDAC_MOD0             (32u)
#define CapSense_BUTTON17_SNS_CLK               (4u)
#define CapSense_BUTTON17_SNS_CLK_SOURCE        (0u)
#define CapSense_BUTTON17_FINGER_CAP            (800u)
#define CapSense_BUTTON17_SIGPFC                (0u)

/***************************************************************************//**
* Button18 initialization values for FLASH data structure
*******************************************************************************/
#define CapSense_BUTTON18_STATIC_CONFIG         (1u)
#define CapSense_BUTTON18_NUM_SENSORS           (1u)

/***************************************************************************//**
* Button18 initialization values for RAM data structure
*******************************************************************************/
#define CapSense_BUTTON18_RESOLUTION            (CapSense_RES12BIT)
#define CapSense_BUTTON18_FINGER_TH             (100u)
#define CapSense_BUTTON18_NOISE_TH              (40u)
#define CapSense_BUTTON18_NNOISE_TH             (40u)
#define CapSense_BUTTON18_HYSTERESIS            (10u)
#define CapSense_BUTTON18_ON_DEBOUNCE           (3u)
#define CapSense_BUTTON18_LOW_BSLN_RST          (30u)
#define CapSense_BUTTON18_BSLN_COEFF            (100u)
#define CapSense_BUTTON18_IDAC_MOD0             (32u)
#define CapSense_BUTTON18_SNS_CLK               (4u)
#define CapSense_BUTTON18_SNS_CLK_SOURCE        (0u)
#define CapSense_BUTTON18_FINGER_CAP            (800u)
#define CapSense_BUTTON18_SIGPFC                (0u)

/***************************************************************************//**
* Button19 initialization values for FLASH data structure
*******************************************************************************/
#define CapSense_BUTTON19_STATIC_CONFIG         (1u)
#define CapSense_BUTTON19_NUM_SENSORS           (1u)

/***************************************************************************//**
* Button19 initialization values for RAM data structure
*******************************************************************************/
#define CapSense_BUTTON19_RESOLUTION            (CapSense_RES12BIT)
#define CapSense_BUTTON19_FINGER_TH             (100u)
#define CapSense_BUTTON19_NOISE_TH              (40u)
#define CapSense_BUTTON19_NNOISE_TH             (40u)
#define CapSense_BUTTON19_HYSTERESIS            (10u)
#define CapSense_BUTTON19_ON_DEBOUNCE           (3u)
#define CapSense_BUTTON19_LOW_BSLN_RST          (30u)
#define CapSense_BUTTON19_BSLN_COEFF            (100u)
#define CapSense_BUTTON19_IDAC_MOD0             (32u)
#define CapSense_BUTTON19_SNS_CLK               (4u)
#define CapSense_BUTTON19_SNS_CLK_SOURCE        (0u)
#define CapSense_BUTTON19_FINGER_CAP            (800u)
#define CapSense_BUTTON19_SIGPFC                (0u)

/***************************************************************************//**
* Button20 initialization values for FLASH data structure
*******************************************************************************/
#define CapSense_BUTTON20_STATIC_CONFIG         (1u)
#define CapSense_BUTTON20_NUM_SENSORS           (1u)

/***************************************************************************//**
* Button20 initialization values for RAM data structure
*******************************************************************************/
#define CapSense_BUTTON20_RESOLUTION            (CapSense_RES12BIT)
#define CapSense_BUTTON20_FINGER_TH             (100u)
#define CapSense_BUTTON20_NOISE_TH              (40u)
#define CapSense_BUTTON20_NNOISE_TH             (40u)
#define CapSense_BUTTON20_HYSTERESIS            (10u)
#define CapSense_BUTTON20_ON_DEBOUNCE           (3u)
#define CapSense_BUTTON20_LOW_BSLN_RST          (30u)
#define CapSense_BUTTON20_BSLN_COEFF            (100u)
#define CapSense_BUTTON20_IDAC_MOD0             (32u)
#define CapSense_BUTTON20_SNS_CLK               (4u)
#define CapSense_BUTTON20_SNS_CLK_SOURCE        (0u)
#define CapSense_BUTTON20_FINGER_CAP            (800u)
#define CapSense_BUTTON20_SIGPFC                (0u)

/***************************************************************************//**
* Button21 initialization values for FLASH data structure
*******************************************************************************/
#define CapSense_BUTTON21_STATIC_CONFIG         (1u)
#define CapSense_BUTTON21_NUM_SENSORS           (1u)

/***************************************************************************//**
* Button21 initialization values for RAM data structure
*******************************************************************************/
#define CapSense_BUTTON21_RESOLUTION            (CapSense_RES12BIT)
#define CapSense_BUTTON21_FINGER_TH             (100u)
#define CapSense_BUTTON21_NOISE_TH              (40u)
#define CapSense_BUTTON21_NNOISE_TH             (40u)
#define CapSense_BUTTON21_HYSTERESIS            (10u)
#define CapSense_BUTTON21_ON_DEBOUNCE           (3u)
#define CapSense_BUTTON21_LOW_BSLN_RST          (30u)
#define CapSense_BUTTON21_BSLN_COEFF            (100u)
#define CapSense_BUTTON21_IDAC_MOD0             (32u)
#define CapSense_BUTTON21_SNS_CLK               (4u)
#define CapSense_BUTTON21_SNS_CLK_SOURCE        (0u)
#define CapSense_BUTTON21_FINGER_CAP            (800u)
#define CapSense_BUTTON21_SIGPFC                (0u)

/***************************************************************************//**
* Button22 initialization values for FLASH data structure
*******************************************************************************/
#define CapSense_BUTTON22_STATIC_CONFIG         (1u)
#define CapSense_BUTTON22_NUM_SENSORS           (1u)

/***************************************************************************//**
* Button22 initialization values for RAM data structure
*******************************************************************************/
#define CapSense_BUTTON22_RESOLUTION            (CapSense_RES12BIT)
#define CapSense_BUTTON22_FINGER_TH             (100u)
#define CapSense_BUTTON22_NOISE_TH              (40u)
#define CapSense_BUTTON22_NNOISE_TH             (40u)
#define CapSense_BUTTON22_HYSTERESIS            (10u)
#define CapSense_BUTTON22_ON_DEBOUNCE           (3u)
#define CapSense_BUTTON22_LOW_BSLN_RST          (30u)
#define CapSense_BUTTON22_BSLN_COEFF            (100u)
#define CapSense_BUTTON22_IDAC_MOD0             (32u)
#define CapSense_BUTTON22_SNS_CLK               (4u)
#define CapSense_BUTTON22_SNS_CLK_SOURCE        (0u)
#define CapSense_BUTTON22_FINGER_CAP            (800u)
#define CapSense_BUTTON22_SIGPFC                (0u)

/***************************************************************************//**
* Button23 initialization values for FLASH data structure
*******************************************************************************/
#define CapSense_BUTTON23_STATIC_CONFIG         (1u)
#define CapSense_BUTTON23_NUM_SENSORS           (1u)

/***************************************************************************//**
* Button23 initialization values for RAM data structure
*******************************************************************************/
#define CapSense_BUTTON23_RESOLUTION            (CapSense_RES12BIT)
#define CapSense_BUTTON23_FINGER_TH             (100u)
#define CapSense_BUTTON23_NOISE_TH              (40u)
#define CapSense_BUTTON23_NNOISE_TH             (40u)
#define CapSense_BUTTON23_HYSTERESIS            (10u)
#define CapSense_BUTTON23_ON_DEBOUNCE           (3u)
#define CapSense_BUTTON23_LOW_BSLN_RST          (30u)
#define CapSense_BUTTON23_BSLN_COEFF            (100u)
#define CapSense_BUTTON23_IDAC_MOD0             (32u)
#define CapSense_BUTTON23_SNS_CLK               (4u)
#define CapSense_BUTTON23_SNS_CLK_SOURCE        (0u)
#define CapSense_BUTTON23_FINGER_CAP            (800u)
#define CapSense_BUTTON23_SIGPFC                (0u)

/***************************************************************************//**
* Button24 initialization values for FLASH data structure
*******************************************************************************/
#define CapSense_BUTTON24_STATIC_CONFIG         (1u)
#define CapSense_BUTTON24_NUM_SENSORS           (1u)

/***************************************************************************//**
* Button24 initialization values for RAM data structure
*******************************************************************************/
#define CapSense_BUTTON24_RESOLUTION            (CapSense_RES12BIT)
#define CapSense_BUTTON24_FINGER_TH             (100u)
#define CapSense_BUTTON24_NOISE_TH              (40u)
#define CapSense_BUTTON24_NNOISE_TH             (40u)
#define CapSense_BUTTON24_HYSTERESIS            (10u)
#define CapSense_BUTTON24_ON_DEBOUNCE           (3u)
#define CapSense_BUTTON24_LOW_BSLN_RST          (30u)
#define CapSense_BUTTON24_BSLN_COEFF            (100u)
#define CapSense_BUTTON24_IDAC_MOD0             (32u)
#define CapSense_BUTTON24_SNS_CLK               (4u)
#define CapSense_BUTTON24_SNS_CLK_SOURCE        (0u)
#define CapSense_BUTTON24_FINGER_CAP            (800u)
#define CapSense_BUTTON24_SIGPFC                (0u)

/***************************************************************************//**
* Button25 initialization values for FLASH data structure
*******************************************************************************/
#define CapSense_BUTTON25_STATIC_CONFIG         (1u)
#define CapSense_BUTTON25_NUM_SENSORS           (1u)

/***************************************************************************//**
* Button25 initialization values for RAM data structure
*******************************************************************************/
#define CapSense_BUTTON25_RESOLUTION            (CapSense_RES12BIT)
#define CapSense_BUTTON25_FINGER_TH             (100u)
#define CapSense_BUTTON25_NOISE_TH              (40u)
#define CapSense_BUTTON25_NNOISE_TH             (40u)
#define CapSense_BUTTON25_HYSTERESIS            (10u)
#define CapSense_BUTTON25_ON_DEBOUNCE           (3u)
#define CapSense_BUTTON25_LOW_BSLN_RST          (30u)
#define CapSense_BUTTON25_BSLN_COEFF            (100u)
#define CapSense_BUTTON25_IDAC_MOD0             (32u)
#define CapSense_BUTTON25_SNS_CLK               (4u)
#define CapSense_BUTTON25_SNS_CLK_SOURCE        (0u)
#define CapSense_BUTTON25_FINGER_CAP            (800u)
#define CapSense_BUTTON25_SIGPFC                (0u)

/***************************************************************************//**
* Button26 initialization values for FLASH data structure
*******************************************************************************/
#define CapSense_BUTTON26_STATIC_CONFIG         (1u)
#define CapSense_BUTTON26_NUM_SENSORS           (1u)

/***************************************************************************//**
* Button26 initialization values for RAM data structure
*******************************************************************************/
#define CapSense_BUTTON26_RESOLUTION            (CapSense_RES12BIT)
#define CapSense_BUTTON26_FINGER_TH             (100u)
#define CapSense_BUTTON26_NOISE_TH              (40u)
#define CapSense_BUTTON26_NNOISE_TH             (40u)
#define CapSense_BUTTON26_HYSTERESIS            (10u)
#define CapSense_BUTTON26_ON_DEBOUNCE           (3u)
#define CapSense_BUTTON26_LOW_BSLN_RST          (30u)
#define CapSense_BUTTON26_BSLN_COEFF            (100u)
#define CapSense_BUTTON26_IDAC_MOD0             (32u)
#define CapSense_BUTTON26_SNS_CLK               (4u)
#define CapSense_BUTTON26_SNS_CLK_SOURCE        (0u)
#define CapSense_BUTTON26_FINGER_CAP            (800u)
#define CapSense_BUTTON26_SIGPFC                (0u)

/***************************************************************************//**
* Button27 initialization values for FLASH data structure
*******************************************************************************/
#define CapSense_BUTTON27_STATIC_CONFIG         (1u)
#define CapSense_BUTTON27_NUM_SENSORS           (1u)

/***************************************************************************//**
* Button27 initialization values for RAM data structure
*******************************************************************************/
#define CapSense_BUTTON27_RESOLUTION            (CapSense_RES12BIT)
#define CapSense_BUTTON27_FINGER_TH             (100u)
#define CapSense_BUTTON27_NOISE_TH              (40u)
#define CapSense_BUTTON27_NNOISE_TH             (40u)
#define CapSense_BUTTON27_HYSTERESIS            (10u)
#define CapSense_BUTTON27_ON_DEBOUNCE           (3u)
#define CapSense_BUTTON27_LOW_BSLN_RST          (30u)
#define CapSense_BUTTON27_BSLN_COEFF            (100u)
#define CapSense_BUTTON27_IDAC_MOD0             (32u)
#define CapSense_BUTTON27_SNS_CLK               (4u)
#define CapSense_BUTTON27_SNS_CLK_SOURCE        (0u)
#define CapSense_BUTTON27_FINGER_CAP            (800u)
#define CapSense_BUTTON27_SIGPFC                (0u)

/***************************************************************************//**
* Button28 initialization values for FLASH data structure
*******************************************************************************/
#define CapSense_BUTTON28_STATIC_CONFIG         (1u)
#define CapSense_BUTTON28_NUM_SENSORS           (1u)

/***************************************************************************//**
* Button28 initialization values for RAM data structure
*******************************************************************************/
#define CapSense_BUTTON28_RESOLUTION            (CapSense_RES12BIT)
#define CapSense_BUTTON28_FINGER_TH             (100u)
#define CapSense_BUTTON28_NOISE_TH              (40u)
#define CapSense_BUTTON28_NNOISE_TH             (40u)
#define CapSense_BUTTON28_HYSTERESIS            (10u)
#define CapSense_BUTTON28_ON_DEBOUNCE           (3u)
#define CapSense_BUTTON28_LOW_BSLN_RST          (30u)
#define CapSense_BUTTON28_BSLN_COEFF            (100u)
#define CapSense_BUTTON28_IDAC_MOD0             (32u)
#define CapSense_BUTTON28_SNS_CLK               (4u)
#define CapSense_BUTTON28_SNS_CLK_SOURCE        (0u)
#define CapSense_BUTTON28_FINGER_CAP            (800u)
#define CapSense_BUTTON28_SIGPFC                (0u)

/***************************************************************************//**
* Button29 initialization values for FLASH data structure
*******************************************************************************/
#define CapSense_BUTTON29_STATIC_CONFIG         (1u)
#define CapSense_BUTTON29_NUM_SENSORS           (1u)

/***************************************************************************//**
* Button29 initialization values for RAM data structure
*******************************************************************************/
#define CapSense_BUTTON29_RESOLUTION            (CapSense_RES12BIT)
#define CapSense_BUTTON29_FINGER_TH             (100u)
#define CapSense_BUTTON29_NOISE_TH              (40u)
#define CapSense_BUTTON29_NNOISE_TH             (40u)
#define CapSense_BUTTON29_HYSTERESIS            (10u)
#define CapSense_BUTTON29_ON_DEBOUNCE           (3u)
#define CapSense_BUTTON29_LOW_BSLN_RST          (30u)
#define CapSense_BUTTON29_BSLN_COEFF            (100u)
#define CapSense_BUTTON29_IDAC_MOD0             (32u)
#define CapSense_BUTTON29_SNS_CLK               (4u)
#define CapSense_BUTTON29_SNS_CLK_SOURCE        (0u)
#define CapSense_BUTTON29_FINGER_CAP            (800u)
#define CapSense_BUTTON29_SIGPFC                (0u)

/***************************************************************************//**
* Button30 initialization values for FLASH data structure
*******************************************************************************/
#define CapSense_BUTTON30_STATIC_CONFIG         (1u)
#define CapSense_BUTTON30_NUM_SENSORS           (1u)

/***************************************************************************//**
* Button30 initialization values for RAM data structure
*******************************************************************************/
#define CapSense_BUTTON30_RESOLUTION            (CapSense_RES12BIT)
#define CapSense_BUTTON30_FINGER_TH             (100u)
#define CapSense_BUTTON30_NOISE_TH              (40u)
#define CapSense_BUTTON30_NNOISE_TH             (40u)
#define CapSense_BUTTON30_HYSTERESIS            (10u)
#define CapSense_BUTTON30_ON_DEBOUNCE           (3u)
#define CapSense_BUTTON30_LOW_BSLN_RST          (30u)
#define CapSense_BUTTON30_BSLN_COEFF            (100u)
#define CapSense_BUTTON30_IDAC_MOD0             (32u)
#define CapSense_BUTTON30_SNS_CLK               (4u)
#define CapSense_BUTTON30_SNS_CLK_SOURCE        (0u)
#define CapSense_BUTTON30_FINGER_CAP            (800u)
#define CapSense_BUTTON30_SIGPFC                (0u)

/***************************************************************************//**
* Button31 initialization values for FLASH data structure
*******************************************************************************/
#define CapSense_BUTTON31_STATIC_CONFIG         (1u)
#define CapSense_BUTTON31_NUM_SENSORS           (1u)

/***************************************************************************//**
* Button31 initialization values for RAM data structure
*******************************************************************************/
#define CapSense_BUTTON31_RESOLUTION            (CapSense_RES12BIT)
#define CapSense_BUTTON31_FINGER_TH             (100u)
#define CapSense_BUTTON31_NOISE_TH              (40u)
#define CapSense_BUTTON31_NNOISE_TH             (40u)
#define CapSense_BUTTON31_HYSTERESIS            (10u)
#define CapSense_BUTTON31_ON_DEBOUNCE           (3u)
#define CapSense_BUTTON31_LOW_BSLN_RST          (30u)
#define CapSense_BUTTON31_BSLN_COEFF            (100u)
#define CapSense_BUTTON31_IDAC_MOD0             (32u)
#define CapSense_BUTTON31_SNS_CLK               (4u)
#define CapSense_BUTTON31_SNS_CLK_SOURCE        (0u)
#define CapSense_BUTTON31_FINGER_CAP            (800u)
#define CapSense_BUTTON31_SIGPFC                (0u)

/* RAM Sensor Parameters Definitions */
#define CapSense_BUTTON0_SNS0_IDAC_COMP0        (32u)
#define CapSense_BUTTON1_SNS0_IDAC_COMP0        (32u)
#define CapSense_BUTTON2_SNS0_IDAC_COMP0        (32u)
#define CapSense_BUTTON3_SNS0_IDAC_COMP0        (32u)
#define CapSense_BUTTON4_SNS0_IDAC_COMP0        (32u)
#define CapSense_BUTTON5_SNS0_IDAC_COMP0        (32u)
#define CapSense_BUTTON6_SNS0_IDAC_COMP0        (32u)
#define CapSense_BUTTON7_SNS0_IDAC_COMP0        (32u)
#define CapSense_BUTTON8_SNS0_IDAC_COMP0        (32u)
#define CapSense_BUTTON9_SNS0_IDAC_COMP0        (32u)
#define CapSense_BUTTON10_SNS0_IDAC_COMP0       (32u)
#define CapSense_BUTTON11_SNS0_IDAC_COMP0       (32u)
#define CapSense_BUTTON12_SNS0_IDAC_COMP0       (32u)
#define CapSense_BUTTON13_SNS0_IDAC_COMP0       (32u)
#define CapSense_BUTTON14_SNS0_IDAC_COMP0       (32u)
#define CapSense_BUTTON15_SNS0_IDAC_COMP0       (32u)
#define CapSense_BUTTON16_SNS0_IDAC_COMP0       (32u)
#define CapSense_BUTTON17_SNS0_IDAC_COMP0       (32u)
#define CapSense_BUTTON18_SNS0_IDAC_COMP0       (32u)
#define CapSense_BUTTON19_SNS0_IDAC_COMP0       (32u)
#define CapSense_BUTTON20_SNS0_IDAC_COMP0       (32u)
#define CapSense_BUTTON21_SNS0_IDAC_COMP0       (32u)
#define CapSense_BUTTON22_SNS0_IDAC_COMP0       (32u)
#define CapSense_BUTTON23_SNS0_IDAC_COMP0       (32u)
#define CapSense_BUTTON24_SNS0_IDAC_COMP0       (32u)
#define CapSense_BUTTON25_SNS0_IDAC_COMP0       (32u)
#define CapSense_BUTTON26_SNS0_IDAC_COMP0       (32u)
#define CapSense_BUTTON27_SNS0_IDAC_COMP0       (32u)
#define CapSense_BUTTON28_SNS0_IDAC_COMP0       (32u)
#define CapSense_BUTTON29_SNS0_IDAC_COMP0       (32u)
#define CapSense_BUTTON30_SNS0_IDAC_COMP0       (32u)
#define CapSense_BUTTON31_SNS0_IDAC_COMP0       (32u)


/*******************************************************************************
* ADC Specific Macros
*******************************************************************************/
#define CapSense_ADC_RES8BIT                  (8u)
#define CapSense_ADC_RES10BIT                 (10u)

#define CapSense_ADC_EN                       (0u)
#define CapSense_ADC_STANDALONE_EN            (0u)
#define CapSense_ADC_TOTAL_CHANNELS           (1u)
#define CapSense_ADC_RESOLUTION               (CapSense_ADC_RES10BIT)
#define CapSense_ADC_AMUXB_INPUT_EN           (0u)
#define CapSense_ADC_SELECT_AMUXB_CH          (0u)
#define CapSense_ADC_AZ_EN                    (1Lu)
#define CapSense_ADC_AZ_TIME                  (5u)
#define CapSense_ADC_VREF_MV                  (2133u)
#define CapSense_ADC_GAIN                     (17Lu)
#define CapSense_ADC_IDACVAL                  (22u)
#define CapSense_ADC_MEASURE_MODE             (0u)

/*******************************************************************************
* Built-In Self-Test Configuration
*******************************************************************************/
#define CapSense_SELF_TEST_EN                   (0Lu)
#define CapSense_TST_GLOBAL_CRC_EN              (0Lu)
#define CapSense_TST_WDGT_CRC_EN                (0Lu)
#define CapSense_TST_BSLN_DUPLICATION_EN        (0Lu)
#define CapSense_TST_BSLN_RAW_OUT_RANGE_EN      (0Lu)
#define CapSense_TST_SNS_SHORT_EN               (0Lu)
#define CapSense_TST_SNS2SNS_SHORT_EN           (0Lu)
#define CapSense_TST_SNS_CAP_EN                 (0Lu)
#define CapSense_TST_SH_CAP_EN                  (0Lu)
#define CapSense_TST_EXTERNAL_CAP_EN            (0Lu)
#define CapSense_TST_INTERNAL_CAP_EN            (0Lu)
#define CapSense_TST_VDDA_EN                    (0Lu)


#endif /* CY_CAPSENSE_CapSense_CONFIGURATION_H */


/* [] END OF FILE */
