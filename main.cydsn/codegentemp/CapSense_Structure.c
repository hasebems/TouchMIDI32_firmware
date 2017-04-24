/***************************************************************************//**
* \file CapSense_Structure.c
* \version 3.10
*
* \brief
*   This file defines the data structure global variables and provides implementation
*   for the high-level and low-level APIs of the Data Structure module.
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

#include <cytypes.h>
#include "CyLib.h"
#include "CapSense_Structure.h"
#include "CapSense_Configuration.h"

#if (0u != CapSense_ADC_EN)
    #include "CapSense_Adc.h"
#endif /* (0u != CapSense_ADC_EN) */

#if (CapSense_ENABLE == CapSense_SELF_TEST_EN)
    #include "CapSense_SelfTest.h"
#endif

/*******************************************************************************
* Define the RAM Data Structure variables and their init data in flash
*******************************************************************************/
/**
* \if SECTION_GLOBAL_VARIABLES
* \addtogroup group_global_variables
* \{
*/

/**
* Variable that contains CapSense configuration, settings and scanning results.
* CapSense_dsRam represents RAM Data Structure.
*/
CapSense_RAM_STRUCT CapSense_dsRam;
/** \}
* \endif */

/*******************************************************************************
* Declare Widget's De-bounce Counters
*******************************************************************************/
static uint8 CapSense_debounceButton0[CapSense_BUTTON0_NUM_SENSORS];
static uint8 CapSense_debounceButton1[CapSense_BUTTON1_NUM_SENSORS];
static uint8 CapSense_debounceButton2[CapSense_BUTTON2_NUM_SENSORS];
static uint8 CapSense_debounceButton3[CapSense_BUTTON3_NUM_SENSORS];
static uint8 CapSense_debounceButton4[CapSense_BUTTON4_NUM_SENSORS];
static uint8 CapSense_debounceButton5[CapSense_BUTTON5_NUM_SENSORS];
static uint8 CapSense_debounceButton6[CapSense_BUTTON6_NUM_SENSORS];
static uint8 CapSense_debounceButton7[CapSense_BUTTON7_NUM_SENSORS];
static uint8 CapSense_debounceButton8[CapSense_BUTTON8_NUM_SENSORS];
static uint8 CapSense_debounceButton9[CapSense_BUTTON9_NUM_SENSORS];
static uint8 CapSense_debounceButton10[CapSense_BUTTON10_NUM_SENSORS];
static uint8 CapSense_debounceButton11[CapSense_BUTTON11_NUM_SENSORS];
static uint8 CapSense_debounceButton12[CapSense_BUTTON12_NUM_SENSORS];
static uint8 CapSense_debounceButton13[CapSense_BUTTON13_NUM_SENSORS];
static uint8 CapSense_debounceButton14[CapSense_BUTTON14_NUM_SENSORS];
static uint8 CapSense_debounceButton15[CapSense_BUTTON15_NUM_SENSORS];
static uint8 CapSense_debounceButton16[CapSense_BUTTON16_NUM_SENSORS];
static uint8 CapSense_debounceButton17[CapSense_BUTTON17_NUM_SENSORS];
static uint8 CapSense_debounceButton18[CapSense_BUTTON18_NUM_SENSORS];
static uint8 CapSense_debounceButton19[CapSense_BUTTON19_NUM_SENSORS];
static uint8 CapSense_debounceButton20[CapSense_BUTTON20_NUM_SENSORS];
static uint8 CapSense_debounceButton21[CapSense_BUTTON21_NUM_SENSORS];
static uint8 CapSense_debounceButton22[CapSense_BUTTON22_NUM_SENSORS];
static uint8 CapSense_debounceButton23[CapSense_BUTTON23_NUM_SENSORS];
static uint8 CapSense_debounceButton24[CapSense_BUTTON24_NUM_SENSORS];
static uint8 CapSense_debounceButton25[CapSense_BUTTON25_NUM_SENSORS];
static uint8 CapSense_debounceButton26[CapSense_BUTTON26_NUM_SENSORS];
static uint8 CapSense_debounceButton27[CapSense_BUTTON27_NUM_SENSORS];
static uint8 CapSense_debounceButton28[CapSense_BUTTON28_NUM_SENSORS];
static uint8 CapSense_debounceButton29[CapSense_BUTTON29_NUM_SENSORS];
static uint8 CapSense_debounceButton30[CapSense_BUTTON30_NUM_SENSORS];
static uint8 CapSense_debounceButton31[CapSense_BUTTON31_NUM_SENSORS];


/***************************************************************************//**
* Declare Noise Envelope data structures
*******************************************************************************/
static SMARTSENSE_CSD_NOISE_ENVELOPE_STRUCT CapSense_noiseEnvlpButton0[CapSense_BUTTON0_NUM_SENSORS];
static SMARTSENSE_CSD_NOISE_ENVELOPE_STRUCT CapSense_noiseEnvlpButton1[CapSense_BUTTON1_NUM_SENSORS];
static SMARTSENSE_CSD_NOISE_ENVELOPE_STRUCT CapSense_noiseEnvlpButton2[CapSense_BUTTON2_NUM_SENSORS];
static SMARTSENSE_CSD_NOISE_ENVELOPE_STRUCT CapSense_noiseEnvlpButton3[CapSense_BUTTON3_NUM_SENSORS];
static SMARTSENSE_CSD_NOISE_ENVELOPE_STRUCT CapSense_noiseEnvlpButton4[CapSense_BUTTON4_NUM_SENSORS];
static SMARTSENSE_CSD_NOISE_ENVELOPE_STRUCT CapSense_noiseEnvlpButton5[CapSense_BUTTON5_NUM_SENSORS];
static SMARTSENSE_CSD_NOISE_ENVELOPE_STRUCT CapSense_noiseEnvlpButton6[CapSense_BUTTON6_NUM_SENSORS];
static SMARTSENSE_CSD_NOISE_ENVELOPE_STRUCT CapSense_noiseEnvlpButton7[CapSense_BUTTON7_NUM_SENSORS];
static SMARTSENSE_CSD_NOISE_ENVELOPE_STRUCT CapSense_noiseEnvlpButton8[CapSense_BUTTON8_NUM_SENSORS];
static SMARTSENSE_CSD_NOISE_ENVELOPE_STRUCT CapSense_noiseEnvlpButton9[CapSense_BUTTON9_NUM_SENSORS];
static SMARTSENSE_CSD_NOISE_ENVELOPE_STRUCT CapSense_noiseEnvlpButton10[CapSense_BUTTON10_NUM_SENSORS];
static SMARTSENSE_CSD_NOISE_ENVELOPE_STRUCT CapSense_noiseEnvlpButton11[CapSense_BUTTON11_NUM_SENSORS];
static SMARTSENSE_CSD_NOISE_ENVELOPE_STRUCT CapSense_noiseEnvlpButton12[CapSense_BUTTON12_NUM_SENSORS];
static SMARTSENSE_CSD_NOISE_ENVELOPE_STRUCT CapSense_noiseEnvlpButton13[CapSense_BUTTON13_NUM_SENSORS];
static SMARTSENSE_CSD_NOISE_ENVELOPE_STRUCT CapSense_noiseEnvlpButton14[CapSense_BUTTON14_NUM_SENSORS];
static SMARTSENSE_CSD_NOISE_ENVELOPE_STRUCT CapSense_noiseEnvlpButton15[CapSense_BUTTON15_NUM_SENSORS];
static SMARTSENSE_CSD_NOISE_ENVELOPE_STRUCT CapSense_noiseEnvlpButton16[CapSense_BUTTON16_NUM_SENSORS];
static SMARTSENSE_CSD_NOISE_ENVELOPE_STRUCT CapSense_noiseEnvlpButton17[CapSense_BUTTON17_NUM_SENSORS];
static SMARTSENSE_CSD_NOISE_ENVELOPE_STRUCT CapSense_noiseEnvlpButton18[CapSense_BUTTON18_NUM_SENSORS];
static SMARTSENSE_CSD_NOISE_ENVELOPE_STRUCT CapSense_noiseEnvlpButton19[CapSense_BUTTON19_NUM_SENSORS];
static SMARTSENSE_CSD_NOISE_ENVELOPE_STRUCT CapSense_noiseEnvlpButton20[CapSense_BUTTON20_NUM_SENSORS];
static SMARTSENSE_CSD_NOISE_ENVELOPE_STRUCT CapSense_noiseEnvlpButton21[CapSense_BUTTON21_NUM_SENSORS];
static SMARTSENSE_CSD_NOISE_ENVELOPE_STRUCT CapSense_noiseEnvlpButton22[CapSense_BUTTON22_NUM_SENSORS];
static SMARTSENSE_CSD_NOISE_ENVELOPE_STRUCT CapSense_noiseEnvlpButton23[CapSense_BUTTON23_NUM_SENSORS];
static SMARTSENSE_CSD_NOISE_ENVELOPE_STRUCT CapSense_noiseEnvlpButton24[CapSense_BUTTON24_NUM_SENSORS];
static SMARTSENSE_CSD_NOISE_ENVELOPE_STRUCT CapSense_noiseEnvlpButton25[CapSense_BUTTON25_NUM_SENSORS];
static SMARTSENSE_CSD_NOISE_ENVELOPE_STRUCT CapSense_noiseEnvlpButton26[CapSense_BUTTON26_NUM_SENSORS];
static SMARTSENSE_CSD_NOISE_ENVELOPE_STRUCT CapSense_noiseEnvlpButton27[CapSense_BUTTON27_NUM_SENSORS];
static SMARTSENSE_CSD_NOISE_ENVELOPE_STRUCT CapSense_noiseEnvlpButton28[CapSense_BUTTON28_NUM_SENSORS];
static SMARTSENSE_CSD_NOISE_ENVELOPE_STRUCT CapSense_noiseEnvlpButton29[CapSense_BUTTON29_NUM_SENSORS];
static SMARTSENSE_CSD_NOISE_ENVELOPE_STRUCT CapSense_noiseEnvlpButton30[CapSense_BUTTON30_NUM_SENSORS];
static SMARTSENSE_CSD_NOISE_ENVELOPE_STRUCT CapSense_noiseEnvlpButton31[CapSense_BUTTON31_NUM_SENSORS];

/*******************************************************************************
* Define and initialize the Flash Data Structure
*******************************************************************************/

/**
* \if SECTION_API_CONSTANTS
* \addtogroup group_api_constants
* \{
*/

/**
* Constant for the FLASH Data Structure
*/
const CapSense_FLASH_STRUCT CapSense_dsFlash =
{
    /* Flash Widget Initialization Data */
    {
        { /* Button0 */
            &CapSense_ioList[0u],
            (void *)&CapSense_dsRam.wdgtList.button0,
            CapSense_dsRam.snsList.button0,
            (void *)0u,
            CapSense_debounceButton0,
            CapSense_BUTTON0_STATIC_CONFIG,
            CapSense_BUTTON0_NUM_SENSORS,
            (uint8)CapSense_WD_BUTTON_E,
            CapSense_BUTTON0_NUM_SENSORS,
            CapSense_noiseEnvlpButton0,
        },
        { /* Button1 */
            &CapSense_ioList[1u],
            (void *)&CapSense_dsRam.wdgtList.button1,
            CapSense_dsRam.snsList.button1,
            (void *)0u,
            CapSense_debounceButton1,
            CapSense_BUTTON1_STATIC_CONFIG,
            CapSense_BUTTON1_NUM_SENSORS,
            (uint8)CapSense_WD_BUTTON_E,
            CapSense_BUTTON1_NUM_SENSORS,
            CapSense_noiseEnvlpButton1,
        },
        { /* Button2 */
            &CapSense_ioList[2u],
            (void *)&CapSense_dsRam.wdgtList.button2,
            CapSense_dsRam.snsList.button2,
            (void *)0u,
            CapSense_debounceButton2,
            CapSense_BUTTON2_STATIC_CONFIG,
            CapSense_BUTTON2_NUM_SENSORS,
            (uint8)CapSense_WD_BUTTON_E,
            CapSense_BUTTON2_NUM_SENSORS,
            CapSense_noiseEnvlpButton2,
        },
        { /* Button3 */
            &CapSense_ioList[3u],
            (void *)&CapSense_dsRam.wdgtList.button3,
            CapSense_dsRam.snsList.button3,
            (void *)0u,
            CapSense_debounceButton3,
            CapSense_BUTTON3_STATIC_CONFIG,
            CapSense_BUTTON3_NUM_SENSORS,
            (uint8)CapSense_WD_BUTTON_E,
            CapSense_BUTTON3_NUM_SENSORS,
            CapSense_noiseEnvlpButton3,
        },
        { /* Button4 */
            &CapSense_ioList[4u],
            (void *)&CapSense_dsRam.wdgtList.button4,
            CapSense_dsRam.snsList.button4,
            (void *)0u,
            CapSense_debounceButton4,
            CapSense_BUTTON4_STATIC_CONFIG,
            CapSense_BUTTON4_NUM_SENSORS,
            (uint8)CapSense_WD_BUTTON_E,
            CapSense_BUTTON4_NUM_SENSORS,
            CapSense_noiseEnvlpButton4,
        },
        { /* Button5 */
            &CapSense_ioList[5u],
            (void *)&CapSense_dsRam.wdgtList.button5,
            CapSense_dsRam.snsList.button5,
            (void *)0u,
            CapSense_debounceButton5,
            CapSense_BUTTON5_STATIC_CONFIG,
            CapSense_BUTTON5_NUM_SENSORS,
            (uint8)CapSense_WD_BUTTON_E,
            CapSense_BUTTON5_NUM_SENSORS,
            CapSense_noiseEnvlpButton5,
        },
        { /* Button6 */
            &CapSense_ioList[6u],
            (void *)&CapSense_dsRam.wdgtList.button6,
            CapSense_dsRam.snsList.button6,
            (void *)0u,
            CapSense_debounceButton6,
            CapSense_BUTTON6_STATIC_CONFIG,
            CapSense_BUTTON6_NUM_SENSORS,
            (uint8)CapSense_WD_BUTTON_E,
            CapSense_BUTTON6_NUM_SENSORS,
            CapSense_noiseEnvlpButton6,
        },
        { /* Button7 */
            &CapSense_ioList[7u],
            (void *)&CapSense_dsRam.wdgtList.button7,
            CapSense_dsRam.snsList.button7,
            (void *)0u,
            CapSense_debounceButton7,
            CapSense_BUTTON7_STATIC_CONFIG,
            CapSense_BUTTON7_NUM_SENSORS,
            (uint8)CapSense_WD_BUTTON_E,
            CapSense_BUTTON7_NUM_SENSORS,
            CapSense_noiseEnvlpButton7,
        },
        { /* Button8 */
            &CapSense_ioList[8u],
            (void *)&CapSense_dsRam.wdgtList.button8,
            CapSense_dsRam.snsList.button8,
            (void *)0u,
            CapSense_debounceButton8,
            CapSense_BUTTON8_STATIC_CONFIG,
            CapSense_BUTTON8_NUM_SENSORS,
            (uint8)CapSense_WD_BUTTON_E,
            CapSense_BUTTON8_NUM_SENSORS,
            CapSense_noiseEnvlpButton8,
        },
        { /* Button9 */
            &CapSense_ioList[9u],
            (void *)&CapSense_dsRam.wdgtList.button9,
            CapSense_dsRam.snsList.button9,
            (void *)0u,
            CapSense_debounceButton9,
            CapSense_BUTTON9_STATIC_CONFIG,
            CapSense_BUTTON9_NUM_SENSORS,
            (uint8)CapSense_WD_BUTTON_E,
            CapSense_BUTTON9_NUM_SENSORS,
            CapSense_noiseEnvlpButton9,
        },
        { /* Button10 */
            &CapSense_ioList[10u],
            (void *)&CapSense_dsRam.wdgtList.button10,
            CapSense_dsRam.snsList.button10,
            (void *)0u,
            CapSense_debounceButton10,
            CapSense_BUTTON10_STATIC_CONFIG,
            CapSense_BUTTON10_NUM_SENSORS,
            (uint8)CapSense_WD_BUTTON_E,
            CapSense_BUTTON10_NUM_SENSORS,
            CapSense_noiseEnvlpButton10,
        },
        { /* Button11 */
            &CapSense_ioList[11u],
            (void *)&CapSense_dsRam.wdgtList.button11,
            CapSense_dsRam.snsList.button11,
            (void *)0u,
            CapSense_debounceButton11,
            CapSense_BUTTON11_STATIC_CONFIG,
            CapSense_BUTTON11_NUM_SENSORS,
            (uint8)CapSense_WD_BUTTON_E,
            CapSense_BUTTON11_NUM_SENSORS,
            CapSense_noiseEnvlpButton11,
        },
        { /* Button12 */
            &CapSense_ioList[12u],
            (void *)&CapSense_dsRam.wdgtList.button12,
            CapSense_dsRam.snsList.button12,
            (void *)0u,
            CapSense_debounceButton12,
            CapSense_BUTTON12_STATIC_CONFIG,
            CapSense_BUTTON12_NUM_SENSORS,
            (uint8)CapSense_WD_BUTTON_E,
            CapSense_BUTTON12_NUM_SENSORS,
            CapSense_noiseEnvlpButton12,
        },
        { /* Button13 */
            &CapSense_ioList[13u],
            (void *)&CapSense_dsRam.wdgtList.button13,
            CapSense_dsRam.snsList.button13,
            (void *)0u,
            CapSense_debounceButton13,
            CapSense_BUTTON13_STATIC_CONFIG,
            CapSense_BUTTON13_NUM_SENSORS,
            (uint8)CapSense_WD_BUTTON_E,
            CapSense_BUTTON13_NUM_SENSORS,
            CapSense_noiseEnvlpButton13,
        },
        { /* Button14 */
            &CapSense_ioList[14u],
            (void *)&CapSense_dsRam.wdgtList.button14,
            CapSense_dsRam.snsList.button14,
            (void *)0u,
            CapSense_debounceButton14,
            CapSense_BUTTON14_STATIC_CONFIG,
            CapSense_BUTTON14_NUM_SENSORS,
            (uint8)CapSense_WD_BUTTON_E,
            CapSense_BUTTON14_NUM_SENSORS,
            CapSense_noiseEnvlpButton14,
        },
        { /* Button15 */
            &CapSense_ioList[15u],
            (void *)&CapSense_dsRam.wdgtList.button15,
            CapSense_dsRam.snsList.button15,
            (void *)0u,
            CapSense_debounceButton15,
            CapSense_BUTTON15_STATIC_CONFIG,
            CapSense_BUTTON15_NUM_SENSORS,
            (uint8)CapSense_WD_BUTTON_E,
            CapSense_BUTTON15_NUM_SENSORS,
            CapSense_noiseEnvlpButton15,
        },
        { /* Button16 */
            &CapSense_ioList[16u],
            (void *)&CapSense_dsRam.wdgtList.button16,
            CapSense_dsRam.snsList.button16,
            (void *)0u,
            CapSense_debounceButton16,
            CapSense_BUTTON16_STATIC_CONFIG,
            CapSense_BUTTON16_NUM_SENSORS,
            (uint8)CapSense_WD_BUTTON_E,
            CapSense_BUTTON16_NUM_SENSORS,
            CapSense_noiseEnvlpButton16,
        },
        { /* Button17 */
            &CapSense_ioList[17u],
            (void *)&CapSense_dsRam.wdgtList.button17,
            CapSense_dsRam.snsList.button17,
            (void *)0u,
            CapSense_debounceButton17,
            CapSense_BUTTON17_STATIC_CONFIG,
            CapSense_BUTTON17_NUM_SENSORS,
            (uint8)CapSense_WD_BUTTON_E,
            CapSense_BUTTON17_NUM_SENSORS,
            CapSense_noiseEnvlpButton17,
        },
        { /* Button18 */
            &CapSense_ioList[18u],
            (void *)&CapSense_dsRam.wdgtList.button18,
            CapSense_dsRam.snsList.button18,
            (void *)0u,
            CapSense_debounceButton18,
            CapSense_BUTTON18_STATIC_CONFIG,
            CapSense_BUTTON18_NUM_SENSORS,
            (uint8)CapSense_WD_BUTTON_E,
            CapSense_BUTTON18_NUM_SENSORS,
            CapSense_noiseEnvlpButton18,
        },
        { /* Button19 */
            &CapSense_ioList[19u],
            (void *)&CapSense_dsRam.wdgtList.button19,
            CapSense_dsRam.snsList.button19,
            (void *)0u,
            CapSense_debounceButton19,
            CapSense_BUTTON19_STATIC_CONFIG,
            CapSense_BUTTON19_NUM_SENSORS,
            (uint8)CapSense_WD_BUTTON_E,
            CapSense_BUTTON19_NUM_SENSORS,
            CapSense_noiseEnvlpButton19,
        },
        { /* Button20 */
            &CapSense_ioList[20u],
            (void *)&CapSense_dsRam.wdgtList.button20,
            CapSense_dsRam.snsList.button20,
            (void *)0u,
            CapSense_debounceButton20,
            CapSense_BUTTON20_STATIC_CONFIG,
            CapSense_BUTTON20_NUM_SENSORS,
            (uint8)CapSense_WD_BUTTON_E,
            CapSense_BUTTON20_NUM_SENSORS,
            CapSense_noiseEnvlpButton20,
        },
        { /* Button21 */
            &CapSense_ioList[21u],
            (void *)&CapSense_dsRam.wdgtList.button21,
            CapSense_dsRam.snsList.button21,
            (void *)0u,
            CapSense_debounceButton21,
            CapSense_BUTTON21_STATIC_CONFIG,
            CapSense_BUTTON21_NUM_SENSORS,
            (uint8)CapSense_WD_BUTTON_E,
            CapSense_BUTTON21_NUM_SENSORS,
            CapSense_noiseEnvlpButton21,
        },
        { /* Button22 */
            &CapSense_ioList[22u],
            (void *)&CapSense_dsRam.wdgtList.button22,
            CapSense_dsRam.snsList.button22,
            (void *)0u,
            CapSense_debounceButton22,
            CapSense_BUTTON22_STATIC_CONFIG,
            CapSense_BUTTON22_NUM_SENSORS,
            (uint8)CapSense_WD_BUTTON_E,
            CapSense_BUTTON22_NUM_SENSORS,
            CapSense_noiseEnvlpButton22,
        },
        { /* Button23 */
            &CapSense_ioList[23u],
            (void *)&CapSense_dsRam.wdgtList.button23,
            CapSense_dsRam.snsList.button23,
            (void *)0u,
            CapSense_debounceButton23,
            CapSense_BUTTON23_STATIC_CONFIG,
            CapSense_BUTTON23_NUM_SENSORS,
            (uint8)CapSense_WD_BUTTON_E,
            CapSense_BUTTON23_NUM_SENSORS,
            CapSense_noiseEnvlpButton23,
        },
        { /* Button24 */
            &CapSense_ioList[24u],
            (void *)&CapSense_dsRam.wdgtList.button24,
            CapSense_dsRam.snsList.button24,
            (void *)0u,
            CapSense_debounceButton24,
            CapSense_BUTTON24_STATIC_CONFIG,
            CapSense_BUTTON24_NUM_SENSORS,
            (uint8)CapSense_WD_BUTTON_E,
            CapSense_BUTTON24_NUM_SENSORS,
            CapSense_noiseEnvlpButton24,
        },
        { /* Button25 */
            &CapSense_ioList[25u],
            (void *)&CapSense_dsRam.wdgtList.button25,
            CapSense_dsRam.snsList.button25,
            (void *)0u,
            CapSense_debounceButton25,
            CapSense_BUTTON25_STATIC_CONFIG,
            CapSense_BUTTON25_NUM_SENSORS,
            (uint8)CapSense_WD_BUTTON_E,
            CapSense_BUTTON25_NUM_SENSORS,
            CapSense_noiseEnvlpButton25,
        },
        { /* Button26 */
            &CapSense_ioList[26u],
            (void *)&CapSense_dsRam.wdgtList.button26,
            CapSense_dsRam.snsList.button26,
            (void *)0u,
            CapSense_debounceButton26,
            CapSense_BUTTON26_STATIC_CONFIG,
            CapSense_BUTTON26_NUM_SENSORS,
            (uint8)CapSense_WD_BUTTON_E,
            CapSense_BUTTON26_NUM_SENSORS,
            CapSense_noiseEnvlpButton26,
        },
        { /* Button27 */
            &CapSense_ioList[27u],
            (void *)&CapSense_dsRam.wdgtList.button27,
            CapSense_dsRam.snsList.button27,
            (void *)0u,
            CapSense_debounceButton27,
            CapSense_BUTTON27_STATIC_CONFIG,
            CapSense_BUTTON27_NUM_SENSORS,
            (uint8)CapSense_WD_BUTTON_E,
            CapSense_BUTTON27_NUM_SENSORS,
            CapSense_noiseEnvlpButton27,
        },
        { /* Button28 */
            &CapSense_ioList[28u],
            (void *)&CapSense_dsRam.wdgtList.button28,
            CapSense_dsRam.snsList.button28,
            (void *)0u,
            CapSense_debounceButton28,
            CapSense_BUTTON28_STATIC_CONFIG,
            CapSense_BUTTON28_NUM_SENSORS,
            (uint8)CapSense_WD_BUTTON_E,
            CapSense_BUTTON28_NUM_SENSORS,
            CapSense_noiseEnvlpButton28,
        },
        { /* Button29 */
            &CapSense_ioList[29u],
            (void *)&CapSense_dsRam.wdgtList.button29,
            CapSense_dsRam.snsList.button29,
            (void *)0u,
            CapSense_debounceButton29,
            CapSense_BUTTON29_STATIC_CONFIG,
            CapSense_BUTTON29_NUM_SENSORS,
            (uint8)CapSense_WD_BUTTON_E,
            CapSense_BUTTON29_NUM_SENSORS,
            CapSense_noiseEnvlpButton29,
        },
        { /* Button30 */
            &CapSense_ioList[30u],
            (void *)&CapSense_dsRam.wdgtList.button30,
            CapSense_dsRam.snsList.button30,
            (void *)0u,
            CapSense_debounceButton30,
            CapSense_BUTTON30_STATIC_CONFIG,
            CapSense_BUTTON30_NUM_SENSORS,
            (uint8)CapSense_WD_BUTTON_E,
            CapSense_BUTTON30_NUM_SENSORS,
            CapSense_noiseEnvlpButton30,
        },
        { /* Button31 */
            &CapSense_ioList[31u],
            (void *)&CapSense_dsRam.wdgtList.button31,
            CapSense_dsRam.snsList.button31,
            (void *)0u,
            CapSense_debounceButton31,
            CapSense_BUTTON31_STATIC_CONFIG,
            CapSense_BUTTON31_NUM_SENSORS,
            (uint8)CapSense_WD_BUTTON_E,
            CapSense_BUTTON31_NUM_SENSORS,
            CapSense_noiseEnvlpButton31,
        },
    },
};


/**
* Array of pointers to the electrode specific register
*/
const CapSense_FLASH_IO_STRUCT CapSense_ioList[CapSense_TOTAL_ELECTRODES] =
{
    { /* 0: Button0_Sns0 */
        (reg32 *)CapSense_Sns__0__HSIOM,
        (reg32 *)CapSense_Sns__0__PC,
        (reg32 *)CapSense_Sns__0__DR,
        (reg32 *)CapSense_Sns__0__PS,
        CapSense_Sns__0__HSIOM_MASK,
        CapSense_Sns__0__MASK,
        CapSense_Sns__0__HSIOM_SHIFT,
        (uint8)CapSense_Sns__0__SHIFT,
        (uint8)CapSense_Sns__0__SHIFT * 3u,
    },
    { /* 1: Button1_Sns0 */
        (reg32 *)CapSense_Sns__1__HSIOM,
        (reg32 *)CapSense_Sns__1__PC,
        (reg32 *)CapSense_Sns__1__DR,
        (reg32 *)CapSense_Sns__1__PS,
        CapSense_Sns__1__HSIOM_MASK,
        CapSense_Sns__1__MASK,
        CapSense_Sns__1__HSIOM_SHIFT,
        (uint8)CapSense_Sns__1__SHIFT,
        (uint8)CapSense_Sns__1__SHIFT * 3u,
    },
    { /* 2: Button2_Sns0 */
        (reg32 *)CapSense_Sns__2__HSIOM,
        (reg32 *)CapSense_Sns__2__PC,
        (reg32 *)CapSense_Sns__2__DR,
        (reg32 *)CapSense_Sns__2__PS,
        CapSense_Sns__2__HSIOM_MASK,
        CapSense_Sns__2__MASK,
        CapSense_Sns__2__HSIOM_SHIFT,
        (uint8)CapSense_Sns__2__SHIFT,
        (uint8)CapSense_Sns__2__SHIFT * 3u,
    },
    { /* 3: Button3_Sns0 */
        (reg32 *)CapSense_Sns__3__HSIOM,
        (reg32 *)CapSense_Sns__3__PC,
        (reg32 *)CapSense_Sns__3__DR,
        (reg32 *)CapSense_Sns__3__PS,
        CapSense_Sns__3__HSIOM_MASK,
        CapSense_Sns__3__MASK,
        CapSense_Sns__3__HSIOM_SHIFT,
        (uint8)CapSense_Sns__3__SHIFT,
        (uint8)CapSense_Sns__3__SHIFT * 3u,
    },
    { /* 4: Button4_Sns0 */
        (reg32 *)CapSense_Sns__4__HSIOM,
        (reg32 *)CapSense_Sns__4__PC,
        (reg32 *)CapSense_Sns__4__DR,
        (reg32 *)CapSense_Sns__4__PS,
        CapSense_Sns__4__HSIOM_MASK,
        CapSense_Sns__4__MASK,
        CapSense_Sns__4__HSIOM_SHIFT,
        (uint8)CapSense_Sns__4__SHIFT,
        (uint8)CapSense_Sns__4__SHIFT * 3u,
    },
    { /* 5: Button5_Sns0 */
        (reg32 *)CapSense_Sns__5__HSIOM,
        (reg32 *)CapSense_Sns__5__PC,
        (reg32 *)CapSense_Sns__5__DR,
        (reg32 *)CapSense_Sns__5__PS,
        CapSense_Sns__5__HSIOM_MASK,
        CapSense_Sns__5__MASK,
        CapSense_Sns__5__HSIOM_SHIFT,
        (uint8)CapSense_Sns__5__SHIFT,
        (uint8)CapSense_Sns__5__SHIFT * 3u,
    },
    { /* 6: Button6_Sns0 */
        (reg32 *)CapSense_Sns__6__HSIOM,
        (reg32 *)CapSense_Sns__6__PC,
        (reg32 *)CapSense_Sns__6__DR,
        (reg32 *)CapSense_Sns__6__PS,
        CapSense_Sns__6__HSIOM_MASK,
        CapSense_Sns__6__MASK,
        CapSense_Sns__6__HSIOM_SHIFT,
        (uint8)CapSense_Sns__6__SHIFT,
        (uint8)CapSense_Sns__6__SHIFT * 3u,
    },
    { /* 7: Button7_Sns0 */
        (reg32 *)CapSense_Sns__7__HSIOM,
        (reg32 *)CapSense_Sns__7__PC,
        (reg32 *)CapSense_Sns__7__DR,
        (reg32 *)CapSense_Sns__7__PS,
        CapSense_Sns__7__HSIOM_MASK,
        CapSense_Sns__7__MASK,
        CapSense_Sns__7__HSIOM_SHIFT,
        (uint8)CapSense_Sns__7__SHIFT,
        (uint8)CapSense_Sns__7__SHIFT * 3u,
    },
    { /* 8: Button8_Sns0 */
        (reg32 *)CapSense_Sns__8__HSIOM,
        (reg32 *)CapSense_Sns__8__PC,
        (reg32 *)CapSense_Sns__8__DR,
        (reg32 *)CapSense_Sns__8__PS,
        CapSense_Sns__8__HSIOM_MASK,
        CapSense_Sns__8__MASK,
        CapSense_Sns__8__HSIOM_SHIFT,
        (uint8)CapSense_Sns__8__SHIFT,
        (uint8)CapSense_Sns__8__SHIFT * 3u,
    },
    { /* 9: Button9_Sns0 */
        (reg32 *)CapSense_Sns__9__HSIOM,
        (reg32 *)CapSense_Sns__9__PC,
        (reg32 *)CapSense_Sns__9__DR,
        (reg32 *)CapSense_Sns__9__PS,
        CapSense_Sns__9__HSIOM_MASK,
        CapSense_Sns__9__MASK,
        CapSense_Sns__9__HSIOM_SHIFT,
        (uint8)CapSense_Sns__9__SHIFT,
        (uint8)CapSense_Sns__9__SHIFT * 3u,
    },
    { /* 10: Button10_Sns0 */
        (reg32 *)CapSense_Sns__10__HSIOM,
        (reg32 *)CapSense_Sns__10__PC,
        (reg32 *)CapSense_Sns__10__DR,
        (reg32 *)CapSense_Sns__10__PS,
        CapSense_Sns__10__HSIOM_MASK,
        CapSense_Sns__10__MASK,
        CapSense_Sns__10__HSIOM_SHIFT,
        (uint8)CapSense_Sns__10__SHIFT,
        (uint8)CapSense_Sns__10__SHIFT * 3u,
    },
    { /* 11: Button11_Sns0 */
        (reg32 *)CapSense_Sns__11__HSIOM,
        (reg32 *)CapSense_Sns__11__PC,
        (reg32 *)CapSense_Sns__11__DR,
        (reg32 *)CapSense_Sns__11__PS,
        CapSense_Sns__11__HSIOM_MASK,
        CapSense_Sns__11__MASK,
        CapSense_Sns__11__HSIOM_SHIFT,
        (uint8)CapSense_Sns__11__SHIFT,
        (uint8)CapSense_Sns__11__SHIFT * 3u,
    },
    { /* 12: Button12_Sns0 */
        (reg32 *)CapSense_Sns__12__HSIOM,
        (reg32 *)CapSense_Sns__12__PC,
        (reg32 *)CapSense_Sns__12__DR,
        (reg32 *)CapSense_Sns__12__PS,
        CapSense_Sns__12__HSIOM_MASK,
        CapSense_Sns__12__MASK,
        CapSense_Sns__12__HSIOM_SHIFT,
        (uint8)CapSense_Sns__12__SHIFT,
        (uint8)CapSense_Sns__12__SHIFT * 3u,
    },
    { /* 13: Button13_Sns0 */
        (reg32 *)CapSense_Sns__13__HSIOM,
        (reg32 *)CapSense_Sns__13__PC,
        (reg32 *)CapSense_Sns__13__DR,
        (reg32 *)CapSense_Sns__13__PS,
        CapSense_Sns__13__HSIOM_MASK,
        CapSense_Sns__13__MASK,
        CapSense_Sns__13__HSIOM_SHIFT,
        (uint8)CapSense_Sns__13__SHIFT,
        (uint8)CapSense_Sns__13__SHIFT * 3u,
    },
    { /* 14: Button14_Sns0 */
        (reg32 *)CapSense_Sns__14__HSIOM,
        (reg32 *)CapSense_Sns__14__PC,
        (reg32 *)CapSense_Sns__14__DR,
        (reg32 *)CapSense_Sns__14__PS,
        CapSense_Sns__14__HSIOM_MASK,
        CapSense_Sns__14__MASK,
        CapSense_Sns__14__HSIOM_SHIFT,
        (uint8)CapSense_Sns__14__SHIFT,
        (uint8)CapSense_Sns__14__SHIFT * 3u,
    },
    { /* 15: Button15_Sns0 */
        (reg32 *)CapSense_Sns__15__HSIOM,
        (reg32 *)CapSense_Sns__15__PC,
        (reg32 *)CapSense_Sns__15__DR,
        (reg32 *)CapSense_Sns__15__PS,
        CapSense_Sns__15__HSIOM_MASK,
        CapSense_Sns__15__MASK,
        CapSense_Sns__15__HSIOM_SHIFT,
        (uint8)CapSense_Sns__15__SHIFT,
        (uint8)CapSense_Sns__15__SHIFT * 3u,
    },
    { /* 16: Button16_Sns0 */
        (reg32 *)CapSense_Sns__16__HSIOM,
        (reg32 *)CapSense_Sns__16__PC,
        (reg32 *)CapSense_Sns__16__DR,
        (reg32 *)CapSense_Sns__16__PS,
        CapSense_Sns__16__HSIOM_MASK,
        CapSense_Sns__16__MASK,
        CapSense_Sns__16__HSIOM_SHIFT,
        (uint8)CapSense_Sns__16__SHIFT,
        (uint8)CapSense_Sns__16__SHIFT * 3u,
    },
    { /* 17: Button17_Sns0 */
        (reg32 *)CapSense_Sns__17__HSIOM,
        (reg32 *)CapSense_Sns__17__PC,
        (reg32 *)CapSense_Sns__17__DR,
        (reg32 *)CapSense_Sns__17__PS,
        CapSense_Sns__17__HSIOM_MASK,
        CapSense_Sns__17__MASK,
        CapSense_Sns__17__HSIOM_SHIFT,
        (uint8)CapSense_Sns__17__SHIFT,
        (uint8)CapSense_Sns__17__SHIFT * 3u,
    },
    { /* 18: Button18_Sns0 */
        (reg32 *)CapSense_Sns__18__HSIOM,
        (reg32 *)CapSense_Sns__18__PC,
        (reg32 *)CapSense_Sns__18__DR,
        (reg32 *)CapSense_Sns__18__PS,
        CapSense_Sns__18__HSIOM_MASK,
        CapSense_Sns__18__MASK,
        CapSense_Sns__18__HSIOM_SHIFT,
        (uint8)CapSense_Sns__18__SHIFT,
        (uint8)CapSense_Sns__18__SHIFT * 3u,
    },
    { /* 19: Button19_Sns0 */
        (reg32 *)CapSense_Sns__19__HSIOM,
        (reg32 *)CapSense_Sns__19__PC,
        (reg32 *)CapSense_Sns__19__DR,
        (reg32 *)CapSense_Sns__19__PS,
        CapSense_Sns__19__HSIOM_MASK,
        CapSense_Sns__19__MASK,
        CapSense_Sns__19__HSIOM_SHIFT,
        (uint8)CapSense_Sns__19__SHIFT,
        (uint8)CapSense_Sns__19__SHIFT * 3u,
    },
    { /* 20: Button20_Sns0 */
        (reg32 *)CapSense_Sns__20__HSIOM,
        (reg32 *)CapSense_Sns__20__PC,
        (reg32 *)CapSense_Sns__20__DR,
        (reg32 *)CapSense_Sns__20__PS,
        CapSense_Sns__20__HSIOM_MASK,
        CapSense_Sns__20__MASK,
        CapSense_Sns__20__HSIOM_SHIFT,
        (uint8)CapSense_Sns__20__SHIFT,
        (uint8)CapSense_Sns__20__SHIFT * 3u,
    },
    { /* 21: Button21_Sns0 */
        (reg32 *)CapSense_Sns__21__HSIOM,
        (reg32 *)CapSense_Sns__21__PC,
        (reg32 *)CapSense_Sns__21__DR,
        (reg32 *)CapSense_Sns__21__PS,
        CapSense_Sns__21__HSIOM_MASK,
        CapSense_Sns__21__MASK,
        CapSense_Sns__21__HSIOM_SHIFT,
        (uint8)CapSense_Sns__21__SHIFT,
        (uint8)CapSense_Sns__21__SHIFT * 3u,
    },
    { /* 22: Button22_Sns0 */
        (reg32 *)CapSense_Sns__22__HSIOM,
        (reg32 *)CapSense_Sns__22__PC,
        (reg32 *)CapSense_Sns__22__DR,
        (reg32 *)CapSense_Sns__22__PS,
        CapSense_Sns__22__HSIOM_MASK,
        CapSense_Sns__22__MASK,
        CapSense_Sns__22__HSIOM_SHIFT,
        (uint8)CapSense_Sns__22__SHIFT,
        (uint8)CapSense_Sns__22__SHIFT * 3u,
    },
    { /* 23: Button23_Sns0 */
        (reg32 *)CapSense_Sns__23__HSIOM,
        (reg32 *)CapSense_Sns__23__PC,
        (reg32 *)CapSense_Sns__23__DR,
        (reg32 *)CapSense_Sns__23__PS,
        CapSense_Sns__23__HSIOM_MASK,
        CapSense_Sns__23__MASK,
        CapSense_Sns__23__HSIOM_SHIFT,
        (uint8)CapSense_Sns__23__SHIFT,
        (uint8)CapSense_Sns__23__SHIFT * 3u,
    },
    { /* 24: Button24_Sns0 */
        (reg32 *)CapSense_Sns__24__HSIOM,
        (reg32 *)CapSense_Sns__24__PC,
        (reg32 *)CapSense_Sns__24__DR,
        (reg32 *)CapSense_Sns__24__PS,
        CapSense_Sns__24__HSIOM_MASK,
        CapSense_Sns__24__MASK,
        CapSense_Sns__24__HSIOM_SHIFT,
        (uint8)CapSense_Sns__24__SHIFT,
        (uint8)CapSense_Sns__24__SHIFT * 3u,
    },
    { /* 25: Button25_Sns0 */
        (reg32 *)CapSense_Sns__25__HSIOM,
        (reg32 *)CapSense_Sns__25__PC,
        (reg32 *)CapSense_Sns__25__DR,
        (reg32 *)CapSense_Sns__25__PS,
        CapSense_Sns__25__HSIOM_MASK,
        CapSense_Sns__25__MASK,
        CapSense_Sns__25__HSIOM_SHIFT,
        (uint8)CapSense_Sns__25__SHIFT,
        (uint8)CapSense_Sns__25__SHIFT * 3u,
    },
    { /* 26: Button26_Sns0 */
        (reg32 *)CapSense_Sns__26__HSIOM,
        (reg32 *)CapSense_Sns__26__PC,
        (reg32 *)CapSense_Sns__26__DR,
        (reg32 *)CapSense_Sns__26__PS,
        CapSense_Sns__26__HSIOM_MASK,
        CapSense_Sns__26__MASK,
        CapSense_Sns__26__HSIOM_SHIFT,
        (uint8)CapSense_Sns__26__SHIFT,
        (uint8)CapSense_Sns__26__SHIFT * 3u,
    },
    { /* 27: Button27_Sns0 */
        (reg32 *)CapSense_Sns__27__HSIOM,
        (reg32 *)CapSense_Sns__27__PC,
        (reg32 *)CapSense_Sns__27__DR,
        (reg32 *)CapSense_Sns__27__PS,
        CapSense_Sns__27__HSIOM_MASK,
        CapSense_Sns__27__MASK,
        CapSense_Sns__27__HSIOM_SHIFT,
        (uint8)CapSense_Sns__27__SHIFT,
        (uint8)CapSense_Sns__27__SHIFT * 3u,
    },
    { /* 28: Button28_Sns0 */
        (reg32 *)CapSense_Sns__28__HSIOM,
        (reg32 *)CapSense_Sns__28__PC,
        (reg32 *)CapSense_Sns__28__DR,
        (reg32 *)CapSense_Sns__28__PS,
        CapSense_Sns__28__HSIOM_MASK,
        CapSense_Sns__28__MASK,
        CapSense_Sns__28__HSIOM_SHIFT,
        (uint8)CapSense_Sns__28__SHIFT,
        (uint8)CapSense_Sns__28__SHIFT * 3u,
    },
    { /* 29: Button29_Sns0 */
        (reg32 *)CapSense_Sns__29__HSIOM,
        (reg32 *)CapSense_Sns__29__PC,
        (reg32 *)CapSense_Sns__29__DR,
        (reg32 *)CapSense_Sns__29__PS,
        CapSense_Sns__29__HSIOM_MASK,
        CapSense_Sns__29__MASK,
        CapSense_Sns__29__HSIOM_SHIFT,
        (uint8)CapSense_Sns__29__SHIFT,
        (uint8)CapSense_Sns__29__SHIFT * 3u,
    },
    { /* 30: Button30_Sns0 */
        (reg32 *)CapSense_Sns__30__HSIOM,
        (reg32 *)CapSense_Sns__30__PC,
        (reg32 *)CapSense_Sns__30__DR,
        (reg32 *)CapSense_Sns__30__PS,
        CapSense_Sns__30__HSIOM_MASK,
        CapSense_Sns__30__MASK,
        CapSense_Sns__30__HSIOM_SHIFT,
        (uint8)CapSense_Sns__30__SHIFT,
        (uint8)CapSense_Sns__30__SHIFT * 3u,
    },
    { /* 31: Button31_Sns0 */
        (reg32 *)CapSense_Sns__31__HSIOM,
        (reg32 *)CapSense_Sns__31__PC,
        (reg32 *)CapSense_Sns__31__DR,
        (reg32 *)CapSense_Sns__31__PS,
        CapSense_Sns__31__HSIOM_MASK,
        CapSense_Sns__31__MASK,
        CapSense_Sns__31__HSIOM_SHIFT,
        (uint8)CapSense_Sns__31__SHIFT,
        (uint8)CapSense_Sns__31__SHIFT * 3u,
    },
};



/** \}
* \endif */

/* Initialization data for RAM widget list */
static const CapSense_RAM_WD_LIST_STRUCT CapSense_ramWidgetInit =
{
    { /* Button0 */
        CapSense_BUTTON0_RESOLUTION,
        CapSense_BUTTON0_FINGER_TH,
        CapSense_BUTTON0_NOISE_TH,
        CapSense_BUTTON0_NNOISE_TH,
        CapSense_BUTTON0_HYSTERESIS,
        CapSense_BUTTON0_ON_DEBOUNCE,
        CapSense_BUTTON0_LOW_BSLN_RST,
        CapSense_BUTTON0_BSLN_COEFF,
        {
            CapSense_BUTTON0_IDAC_MOD0,
        },
        CapSense_BUTTON0_SNS_CLK,
        CapSense_BUTTON0_SNS_CLK_SOURCE,
        CapSense_BUTTON0_FINGER_CAP,
        CapSense_BUTTON0_SIGPFC,
    },
    { /* Button1 */
        CapSense_BUTTON1_RESOLUTION,
        CapSense_BUTTON1_FINGER_TH,
        CapSense_BUTTON1_NOISE_TH,
        CapSense_BUTTON1_NNOISE_TH,
        CapSense_BUTTON1_HYSTERESIS,
        CapSense_BUTTON1_ON_DEBOUNCE,
        CapSense_BUTTON1_LOW_BSLN_RST,
        CapSense_BUTTON1_BSLN_COEFF,
        {
            CapSense_BUTTON1_IDAC_MOD0,
        },
        CapSense_BUTTON1_SNS_CLK,
        CapSense_BUTTON1_SNS_CLK_SOURCE,
        CapSense_BUTTON1_FINGER_CAP,
        CapSense_BUTTON1_SIGPFC,
    },
    { /* Button2 */
        CapSense_BUTTON2_RESOLUTION,
        CapSense_BUTTON2_FINGER_TH,
        CapSense_BUTTON2_NOISE_TH,
        CapSense_BUTTON2_NNOISE_TH,
        CapSense_BUTTON2_HYSTERESIS,
        CapSense_BUTTON2_ON_DEBOUNCE,
        CapSense_BUTTON2_LOW_BSLN_RST,
        CapSense_BUTTON2_BSLN_COEFF,
        {
            CapSense_BUTTON2_IDAC_MOD0,
        },
        CapSense_BUTTON2_SNS_CLK,
        CapSense_BUTTON2_SNS_CLK_SOURCE,
        CapSense_BUTTON2_FINGER_CAP,
        CapSense_BUTTON2_SIGPFC,
    },
    { /* Button3 */
        CapSense_BUTTON3_RESOLUTION,
        CapSense_BUTTON3_FINGER_TH,
        CapSense_BUTTON3_NOISE_TH,
        CapSense_BUTTON3_NNOISE_TH,
        CapSense_BUTTON3_HYSTERESIS,
        CapSense_BUTTON3_ON_DEBOUNCE,
        CapSense_BUTTON3_LOW_BSLN_RST,
        CapSense_BUTTON3_BSLN_COEFF,
        {
            CapSense_BUTTON3_IDAC_MOD0,
        },
        CapSense_BUTTON3_SNS_CLK,
        CapSense_BUTTON3_SNS_CLK_SOURCE,
        CapSense_BUTTON3_FINGER_CAP,
        CapSense_BUTTON3_SIGPFC,
    },
    { /* Button4 */
        CapSense_BUTTON4_RESOLUTION,
        CapSense_BUTTON4_FINGER_TH,
        CapSense_BUTTON4_NOISE_TH,
        CapSense_BUTTON4_NNOISE_TH,
        CapSense_BUTTON4_HYSTERESIS,
        CapSense_BUTTON4_ON_DEBOUNCE,
        CapSense_BUTTON4_LOW_BSLN_RST,
        CapSense_BUTTON4_BSLN_COEFF,
        {
            CapSense_BUTTON4_IDAC_MOD0,
        },
        CapSense_BUTTON4_SNS_CLK,
        CapSense_BUTTON4_SNS_CLK_SOURCE,
        CapSense_BUTTON4_FINGER_CAP,
        CapSense_BUTTON4_SIGPFC,
    },
    { /* Button5 */
        CapSense_BUTTON5_RESOLUTION,
        CapSense_BUTTON5_FINGER_TH,
        CapSense_BUTTON5_NOISE_TH,
        CapSense_BUTTON5_NNOISE_TH,
        CapSense_BUTTON5_HYSTERESIS,
        CapSense_BUTTON5_ON_DEBOUNCE,
        CapSense_BUTTON5_LOW_BSLN_RST,
        CapSense_BUTTON5_BSLN_COEFF,
        {
            CapSense_BUTTON5_IDAC_MOD0,
        },
        CapSense_BUTTON5_SNS_CLK,
        CapSense_BUTTON5_SNS_CLK_SOURCE,
        CapSense_BUTTON5_FINGER_CAP,
        CapSense_BUTTON5_SIGPFC,
    },
    { /* Button6 */
        CapSense_BUTTON6_RESOLUTION,
        CapSense_BUTTON6_FINGER_TH,
        CapSense_BUTTON6_NOISE_TH,
        CapSense_BUTTON6_NNOISE_TH,
        CapSense_BUTTON6_HYSTERESIS,
        CapSense_BUTTON6_ON_DEBOUNCE,
        CapSense_BUTTON6_LOW_BSLN_RST,
        CapSense_BUTTON6_BSLN_COEFF,
        {
            CapSense_BUTTON6_IDAC_MOD0,
        },
        CapSense_BUTTON6_SNS_CLK,
        CapSense_BUTTON6_SNS_CLK_SOURCE,
        CapSense_BUTTON6_FINGER_CAP,
        CapSense_BUTTON6_SIGPFC,
    },
    { /* Button7 */
        CapSense_BUTTON7_RESOLUTION,
        CapSense_BUTTON7_FINGER_TH,
        CapSense_BUTTON7_NOISE_TH,
        CapSense_BUTTON7_NNOISE_TH,
        CapSense_BUTTON7_HYSTERESIS,
        CapSense_BUTTON7_ON_DEBOUNCE,
        CapSense_BUTTON7_LOW_BSLN_RST,
        CapSense_BUTTON7_BSLN_COEFF,
        {
            CapSense_BUTTON7_IDAC_MOD0,
        },
        CapSense_BUTTON7_SNS_CLK,
        CapSense_BUTTON7_SNS_CLK_SOURCE,
        CapSense_BUTTON7_FINGER_CAP,
        CapSense_BUTTON7_SIGPFC,
    },
    { /* Button8 */
        CapSense_BUTTON8_RESOLUTION,
        CapSense_BUTTON8_FINGER_TH,
        CapSense_BUTTON8_NOISE_TH,
        CapSense_BUTTON8_NNOISE_TH,
        CapSense_BUTTON8_HYSTERESIS,
        CapSense_BUTTON8_ON_DEBOUNCE,
        CapSense_BUTTON8_LOW_BSLN_RST,
        CapSense_BUTTON8_BSLN_COEFF,
        {
            CapSense_BUTTON8_IDAC_MOD0,
        },
        CapSense_BUTTON8_SNS_CLK,
        CapSense_BUTTON8_SNS_CLK_SOURCE,
        CapSense_BUTTON8_FINGER_CAP,
        CapSense_BUTTON8_SIGPFC,
    },
    { /* Button9 */
        CapSense_BUTTON9_RESOLUTION,
        CapSense_BUTTON9_FINGER_TH,
        CapSense_BUTTON9_NOISE_TH,
        CapSense_BUTTON9_NNOISE_TH,
        CapSense_BUTTON9_HYSTERESIS,
        CapSense_BUTTON9_ON_DEBOUNCE,
        CapSense_BUTTON9_LOW_BSLN_RST,
        CapSense_BUTTON9_BSLN_COEFF,
        {
            CapSense_BUTTON9_IDAC_MOD0,
        },
        CapSense_BUTTON9_SNS_CLK,
        CapSense_BUTTON9_SNS_CLK_SOURCE,
        CapSense_BUTTON9_FINGER_CAP,
        CapSense_BUTTON9_SIGPFC,
    },
    { /* Button10 */
        CapSense_BUTTON10_RESOLUTION,
        CapSense_BUTTON10_FINGER_TH,
        CapSense_BUTTON10_NOISE_TH,
        CapSense_BUTTON10_NNOISE_TH,
        CapSense_BUTTON10_HYSTERESIS,
        CapSense_BUTTON10_ON_DEBOUNCE,
        CapSense_BUTTON10_LOW_BSLN_RST,
        CapSense_BUTTON10_BSLN_COEFF,
        {
            CapSense_BUTTON10_IDAC_MOD0,
        },
        CapSense_BUTTON10_SNS_CLK,
        CapSense_BUTTON10_SNS_CLK_SOURCE,
        CapSense_BUTTON10_FINGER_CAP,
        CapSense_BUTTON10_SIGPFC,
    },
    { /* Button11 */
        CapSense_BUTTON11_RESOLUTION,
        CapSense_BUTTON11_FINGER_TH,
        CapSense_BUTTON11_NOISE_TH,
        CapSense_BUTTON11_NNOISE_TH,
        CapSense_BUTTON11_HYSTERESIS,
        CapSense_BUTTON11_ON_DEBOUNCE,
        CapSense_BUTTON11_LOW_BSLN_RST,
        CapSense_BUTTON11_BSLN_COEFF,
        {
            CapSense_BUTTON11_IDAC_MOD0,
        },
        CapSense_BUTTON11_SNS_CLK,
        CapSense_BUTTON11_SNS_CLK_SOURCE,
        CapSense_BUTTON11_FINGER_CAP,
        CapSense_BUTTON11_SIGPFC,
    },
    { /* Button12 */
        CapSense_BUTTON12_RESOLUTION,
        CapSense_BUTTON12_FINGER_TH,
        CapSense_BUTTON12_NOISE_TH,
        CapSense_BUTTON12_NNOISE_TH,
        CapSense_BUTTON12_HYSTERESIS,
        CapSense_BUTTON12_ON_DEBOUNCE,
        CapSense_BUTTON12_LOW_BSLN_RST,
        CapSense_BUTTON12_BSLN_COEFF,
        {
            CapSense_BUTTON12_IDAC_MOD0,
        },
        CapSense_BUTTON12_SNS_CLK,
        CapSense_BUTTON12_SNS_CLK_SOURCE,
        CapSense_BUTTON12_FINGER_CAP,
        CapSense_BUTTON12_SIGPFC,
    },
    { /* Button13 */
        CapSense_BUTTON13_RESOLUTION,
        CapSense_BUTTON13_FINGER_TH,
        CapSense_BUTTON13_NOISE_TH,
        CapSense_BUTTON13_NNOISE_TH,
        CapSense_BUTTON13_HYSTERESIS,
        CapSense_BUTTON13_ON_DEBOUNCE,
        CapSense_BUTTON13_LOW_BSLN_RST,
        CapSense_BUTTON13_BSLN_COEFF,
        {
            CapSense_BUTTON13_IDAC_MOD0,
        },
        CapSense_BUTTON13_SNS_CLK,
        CapSense_BUTTON13_SNS_CLK_SOURCE,
        CapSense_BUTTON13_FINGER_CAP,
        CapSense_BUTTON13_SIGPFC,
    },
    { /* Button14 */
        CapSense_BUTTON14_RESOLUTION,
        CapSense_BUTTON14_FINGER_TH,
        CapSense_BUTTON14_NOISE_TH,
        CapSense_BUTTON14_NNOISE_TH,
        CapSense_BUTTON14_HYSTERESIS,
        CapSense_BUTTON14_ON_DEBOUNCE,
        CapSense_BUTTON14_LOW_BSLN_RST,
        CapSense_BUTTON14_BSLN_COEFF,
        {
            CapSense_BUTTON14_IDAC_MOD0,
        },
        CapSense_BUTTON14_SNS_CLK,
        CapSense_BUTTON14_SNS_CLK_SOURCE,
        CapSense_BUTTON14_FINGER_CAP,
        CapSense_BUTTON14_SIGPFC,
    },
    { /* Button15 */
        CapSense_BUTTON15_RESOLUTION,
        CapSense_BUTTON15_FINGER_TH,
        CapSense_BUTTON15_NOISE_TH,
        CapSense_BUTTON15_NNOISE_TH,
        CapSense_BUTTON15_HYSTERESIS,
        CapSense_BUTTON15_ON_DEBOUNCE,
        CapSense_BUTTON15_LOW_BSLN_RST,
        CapSense_BUTTON15_BSLN_COEFF,
        {
            CapSense_BUTTON15_IDAC_MOD0,
        },
        CapSense_BUTTON15_SNS_CLK,
        CapSense_BUTTON15_SNS_CLK_SOURCE,
        CapSense_BUTTON15_FINGER_CAP,
        CapSense_BUTTON15_SIGPFC,
    },
    { /* Button16 */
        CapSense_BUTTON16_RESOLUTION,
        CapSense_BUTTON16_FINGER_TH,
        CapSense_BUTTON16_NOISE_TH,
        CapSense_BUTTON16_NNOISE_TH,
        CapSense_BUTTON16_HYSTERESIS,
        CapSense_BUTTON16_ON_DEBOUNCE,
        CapSense_BUTTON16_LOW_BSLN_RST,
        CapSense_BUTTON16_BSLN_COEFF,
        {
            CapSense_BUTTON16_IDAC_MOD0,
        },
        CapSense_BUTTON16_SNS_CLK,
        CapSense_BUTTON16_SNS_CLK_SOURCE,
        CapSense_BUTTON16_FINGER_CAP,
        CapSense_BUTTON16_SIGPFC,
    },
    { /* Button17 */
        CapSense_BUTTON17_RESOLUTION,
        CapSense_BUTTON17_FINGER_TH,
        CapSense_BUTTON17_NOISE_TH,
        CapSense_BUTTON17_NNOISE_TH,
        CapSense_BUTTON17_HYSTERESIS,
        CapSense_BUTTON17_ON_DEBOUNCE,
        CapSense_BUTTON17_LOW_BSLN_RST,
        CapSense_BUTTON17_BSLN_COEFF,
        {
            CapSense_BUTTON17_IDAC_MOD0,
        },
        CapSense_BUTTON17_SNS_CLK,
        CapSense_BUTTON17_SNS_CLK_SOURCE,
        CapSense_BUTTON17_FINGER_CAP,
        CapSense_BUTTON17_SIGPFC,
    },
    { /* Button18 */
        CapSense_BUTTON18_RESOLUTION,
        CapSense_BUTTON18_FINGER_TH,
        CapSense_BUTTON18_NOISE_TH,
        CapSense_BUTTON18_NNOISE_TH,
        CapSense_BUTTON18_HYSTERESIS,
        CapSense_BUTTON18_ON_DEBOUNCE,
        CapSense_BUTTON18_LOW_BSLN_RST,
        CapSense_BUTTON18_BSLN_COEFF,
        {
            CapSense_BUTTON18_IDAC_MOD0,
        },
        CapSense_BUTTON18_SNS_CLK,
        CapSense_BUTTON18_SNS_CLK_SOURCE,
        CapSense_BUTTON18_FINGER_CAP,
        CapSense_BUTTON18_SIGPFC,
    },
    { /* Button19 */
        CapSense_BUTTON19_RESOLUTION,
        CapSense_BUTTON19_FINGER_TH,
        CapSense_BUTTON19_NOISE_TH,
        CapSense_BUTTON19_NNOISE_TH,
        CapSense_BUTTON19_HYSTERESIS,
        CapSense_BUTTON19_ON_DEBOUNCE,
        CapSense_BUTTON19_LOW_BSLN_RST,
        CapSense_BUTTON19_BSLN_COEFF,
        {
            CapSense_BUTTON19_IDAC_MOD0,
        },
        CapSense_BUTTON19_SNS_CLK,
        CapSense_BUTTON19_SNS_CLK_SOURCE,
        CapSense_BUTTON19_FINGER_CAP,
        CapSense_BUTTON19_SIGPFC,
    },
    { /* Button20 */
        CapSense_BUTTON20_RESOLUTION,
        CapSense_BUTTON20_FINGER_TH,
        CapSense_BUTTON20_NOISE_TH,
        CapSense_BUTTON20_NNOISE_TH,
        CapSense_BUTTON20_HYSTERESIS,
        CapSense_BUTTON20_ON_DEBOUNCE,
        CapSense_BUTTON20_LOW_BSLN_RST,
        CapSense_BUTTON20_BSLN_COEFF,
        {
            CapSense_BUTTON20_IDAC_MOD0,
        },
        CapSense_BUTTON20_SNS_CLK,
        CapSense_BUTTON20_SNS_CLK_SOURCE,
        CapSense_BUTTON20_FINGER_CAP,
        CapSense_BUTTON20_SIGPFC,
    },
    { /* Button21 */
        CapSense_BUTTON21_RESOLUTION,
        CapSense_BUTTON21_FINGER_TH,
        CapSense_BUTTON21_NOISE_TH,
        CapSense_BUTTON21_NNOISE_TH,
        CapSense_BUTTON21_HYSTERESIS,
        CapSense_BUTTON21_ON_DEBOUNCE,
        CapSense_BUTTON21_LOW_BSLN_RST,
        CapSense_BUTTON21_BSLN_COEFF,
        {
            CapSense_BUTTON21_IDAC_MOD0,
        },
        CapSense_BUTTON21_SNS_CLK,
        CapSense_BUTTON21_SNS_CLK_SOURCE,
        CapSense_BUTTON21_FINGER_CAP,
        CapSense_BUTTON21_SIGPFC,
    },
    { /* Button22 */
        CapSense_BUTTON22_RESOLUTION,
        CapSense_BUTTON22_FINGER_TH,
        CapSense_BUTTON22_NOISE_TH,
        CapSense_BUTTON22_NNOISE_TH,
        CapSense_BUTTON22_HYSTERESIS,
        CapSense_BUTTON22_ON_DEBOUNCE,
        CapSense_BUTTON22_LOW_BSLN_RST,
        CapSense_BUTTON22_BSLN_COEFF,
        {
            CapSense_BUTTON22_IDAC_MOD0,
        },
        CapSense_BUTTON22_SNS_CLK,
        CapSense_BUTTON22_SNS_CLK_SOURCE,
        CapSense_BUTTON22_FINGER_CAP,
        CapSense_BUTTON22_SIGPFC,
    },
    { /* Button23 */
        CapSense_BUTTON23_RESOLUTION,
        CapSense_BUTTON23_FINGER_TH,
        CapSense_BUTTON23_NOISE_TH,
        CapSense_BUTTON23_NNOISE_TH,
        CapSense_BUTTON23_HYSTERESIS,
        CapSense_BUTTON23_ON_DEBOUNCE,
        CapSense_BUTTON23_LOW_BSLN_RST,
        CapSense_BUTTON23_BSLN_COEFF,
        {
            CapSense_BUTTON23_IDAC_MOD0,
        },
        CapSense_BUTTON23_SNS_CLK,
        CapSense_BUTTON23_SNS_CLK_SOURCE,
        CapSense_BUTTON23_FINGER_CAP,
        CapSense_BUTTON23_SIGPFC,
    },
    { /* Button24 */
        CapSense_BUTTON24_RESOLUTION,
        CapSense_BUTTON24_FINGER_TH,
        CapSense_BUTTON24_NOISE_TH,
        CapSense_BUTTON24_NNOISE_TH,
        CapSense_BUTTON24_HYSTERESIS,
        CapSense_BUTTON24_ON_DEBOUNCE,
        CapSense_BUTTON24_LOW_BSLN_RST,
        CapSense_BUTTON24_BSLN_COEFF,
        {
            CapSense_BUTTON24_IDAC_MOD0,
        },
        CapSense_BUTTON24_SNS_CLK,
        CapSense_BUTTON24_SNS_CLK_SOURCE,
        CapSense_BUTTON24_FINGER_CAP,
        CapSense_BUTTON24_SIGPFC,
    },
    { /* Button25 */
        CapSense_BUTTON25_RESOLUTION,
        CapSense_BUTTON25_FINGER_TH,
        CapSense_BUTTON25_NOISE_TH,
        CapSense_BUTTON25_NNOISE_TH,
        CapSense_BUTTON25_HYSTERESIS,
        CapSense_BUTTON25_ON_DEBOUNCE,
        CapSense_BUTTON25_LOW_BSLN_RST,
        CapSense_BUTTON25_BSLN_COEFF,
        {
            CapSense_BUTTON25_IDAC_MOD0,
        },
        CapSense_BUTTON25_SNS_CLK,
        CapSense_BUTTON25_SNS_CLK_SOURCE,
        CapSense_BUTTON25_FINGER_CAP,
        CapSense_BUTTON25_SIGPFC,
    },
    { /* Button26 */
        CapSense_BUTTON26_RESOLUTION,
        CapSense_BUTTON26_FINGER_TH,
        CapSense_BUTTON26_NOISE_TH,
        CapSense_BUTTON26_NNOISE_TH,
        CapSense_BUTTON26_HYSTERESIS,
        CapSense_BUTTON26_ON_DEBOUNCE,
        CapSense_BUTTON26_LOW_BSLN_RST,
        CapSense_BUTTON26_BSLN_COEFF,
        {
            CapSense_BUTTON26_IDAC_MOD0,
        },
        CapSense_BUTTON26_SNS_CLK,
        CapSense_BUTTON26_SNS_CLK_SOURCE,
        CapSense_BUTTON26_FINGER_CAP,
        CapSense_BUTTON26_SIGPFC,
    },
    { /* Button27 */
        CapSense_BUTTON27_RESOLUTION,
        CapSense_BUTTON27_FINGER_TH,
        CapSense_BUTTON27_NOISE_TH,
        CapSense_BUTTON27_NNOISE_TH,
        CapSense_BUTTON27_HYSTERESIS,
        CapSense_BUTTON27_ON_DEBOUNCE,
        CapSense_BUTTON27_LOW_BSLN_RST,
        CapSense_BUTTON27_BSLN_COEFF,
        {
            CapSense_BUTTON27_IDAC_MOD0,
        },
        CapSense_BUTTON27_SNS_CLK,
        CapSense_BUTTON27_SNS_CLK_SOURCE,
        CapSense_BUTTON27_FINGER_CAP,
        CapSense_BUTTON27_SIGPFC,
    },
    { /* Button28 */
        CapSense_BUTTON28_RESOLUTION,
        CapSense_BUTTON28_FINGER_TH,
        CapSense_BUTTON28_NOISE_TH,
        CapSense_BUTTON28_NNOISE_TH,
        CapSense_BUTTON28_HYSTERESIS,
        CapSense_BUTTON28_ON_DEBOUNCE,
        CapSense_BUTTON28_LOW_BSLN_RST,
        CapSense_BUTTON28_BSLN_COEFF,
        {
            CapSense_BUTTON28_IDAC_MOD0,
        },
        CapSense_BUTTON28_SNS_CLK,
        CapSense_BUTTON28_SNS_CLK_SOURCE,
        CapSense_BUTTON28_FINGER_CAP,
        CapSense_BUTTON28_SIGPFC,
    },
    { /* Button29 */
        CapSense_BUTTON29_RESOLUTION,
        CapSense_BUTTON29_FINGER_TH,
        CapSense_BUTTON29_NOISE_TH,
        CapSense_BUTTON29_NNOISE_TH,
        CapSense_BUTTON29_HYSTERESIS,
        CapSense_BUTTON29_ON_DEBOUNCE,
        CapSense_BUTTON29_LOW_BSLN_RST,
        CapSense_BUTTON29_BSLN_COEFF,
        {
            CapSense_BUTTON29_IDAC_MOD0,
        },
        CapSense_BUTTON29_SNS_CLK,
        CapSense_BUTTON29_SNS_CLK_SOURCE,
        CapSense_BUTTON29_FINGER_CAP,
        CapSense_BUTTON29_SIGPFC,
    },
    { /* Button30 */
        CapSense_BUTTON30_RESOLUTION,
        CapSense_BUTTON30_FINGER_TH,
        CapSense_BUTTON30_NOISE_TH,
        CapSense_BUTTON30_NNOISE_TH,
        CapSense_BUTTON30_HYSTERESIS,
        CapSense_BUTTON30_ON_DEBOUNCE,
        CapSense_BUTTON30_LOW_BSLN_RST,
        CapSense_BUTTON30_BSLN_COEFF,
        {
            CapSense_BUTTON30_IDAC_MOD0,
        },
        CapSense_BUTTON30_SNS_CLK,
        CapSense_BUTTON30_SNS_CLK_SOURCE,
        CapSense_BUTTON30_FINGER_CAP,
        CapSense_BUTTON30_SIGPFC,
    },
    { /* Button31 */
        CapSense_BUTTON31_RESOLUTION,
        CapSense_BUTTON31_FINGER_TH,
        CapSense_BUTTON31_NOISE_TH,
        CapSense_BUTTON31_NNOISE_TH,
        CapSense_BUTTON31_HYSTERESIS,
        CapSense_BUTTON31_ON_DEBOUNCE,
        CapSense_BUTTON31_LOW_BSLN_RST,
        CapSense_BUTTON31_BSLN_COEFF,
        {
            CapSense_BUTTON31_IDAC_MOD0,
        },
        CapSense_BUTTON31_SNS_CLK,
        CapSense_BUTTON31_SNS_CLK_SOURCE,
        CapSense_BUTTON31_FINGER_CAP,
        CapSense_BUTTON31_SIGPFC,
    },
};


/* IDAC Initialization Data */
static const uint8 CapSense_ramIdacInit[CapSense_TOTAL_SENSORS] =
{
    /* Button0 */
    CapSense_BUTTON0_SNS0_IDAC_COMP0,

    /* Button1 */
    CapSense_BUTTON1_SNS0_IDAC_COMP0,

    /* Button2 */
    CapSense_BUTTON2_SNS0_IDAC_COMP0,

    /* Button3 */
    CapSense_BUTTON3_SNS0_IDAC_COMP0,

    /* Button4 */
    CapSense_BUTTON4_SNS0_IDAC_COMP0,

    /* Button5 */
    CapSense_BUTTON5_SNS0_IDAC_COMP0,

    /* Button6 */
    CapSense_BUTTON6_SNS0_IDAC_COMP0,

    /* Button7 */
    CapSense_BUTTON7_SNS0_IDAC_COMP0,

    /* Button8 */
    CapSense_BUTTON8_SNS0_IDAC_COMP0,

    /* Button9 */
    CapSense_BUTTON9_SNS0_IDAC_COMP0,

    /* Button10 */
    CapSense_BUTTON10_SNS0_IDAC_COMP0,

    /* Button11 */
    CapSense_BUTTON11_SNS0_IDAC_COMP0,

    /* Button12 */
    CapSense_BUTTON12_SNS0_IDAC_COMP0,

    /* Button13 */
    CapSense_BUTTON13_SNS0_IDAC_COMP0,

    /* Button14 */
    CapSense_BUTTON14_SNS0_IDAC_COMP0,

    /* Button15 */
    CapSense_BUTTON15_SNS0_IDAC_COMP0,

    /* Button16 */
    CapSense_BUTTON16_SNS0_IDAC_COMP0,

    /* Button17 */
    CapSense_BUTTON17_SNS0_IDAC_COMP0,

    /* Button18 */
    CapSense_BUTTON18_SNS0_IDAC_COMP0,

    /* Button19 */
    CapSense_BUTTON19_SNS0_IDAC_COMP0,

    /* Button20 */
    CapSense_BUTTON20_SNS0_IDAC_COMP0,

    /* Button21 */
    CapSense_BUTTON21_SNS0_IDAC_COMP0,

    /* Button22 */
    CapSense_BUTTON22_SNS0_IDAC_COMP0,

    /* Button23 */
    CapSense_BUTTON23_SNS0_IDAC_COMP0,

    /* Button24 */
    CapSense_BUTTON24_SNS0_IDAC_COMP0,

    /* Button25 */
    CapSense_BUTTON25_SNS0_IDAC_COMP0,

    /* Button26 */
    CapSense_BUTTON26_SNS0_IDAC_COMP0,

    /* Button27 */
    CapSense_BUTTON27_SNS0_IDAC_COMP0,

    /* Button28 */
    CapSense_BUTTON28_SNS0_IDAC_COMP0,

    /* Button29 */
    CapSense_BUTTON29_SNS0_IDAC_COMP0,

    /* Button30 */
    CapSense_BUTTON30_SNS0_IDAC_COMP0,

    /* Button31 */
    CapSense_BUTTON31_SNS0_IDAC_COMP0,
};


/*******************************************************************************
* Define internal data types and statements
*******************************************************************************/
#define PARAM_TYPE_OFFSET       (30u)
#define PARAM_TYPE_MASK         (3Lu << PARAM_TYPE_OFFSET)
#define PARAM_RWBIT_OFFSET      (29u)
#define PARAM_RWBIT_MASK        (1Lu << PARAM_RWBIT_OFFSET)
#define PARAM_FBIT_OFFSET       (28u)
#define PARAM_FBIT_MASK         (1Lu << PARAM_FBIT_OFFSET)
#define PARAM_UBIT_OFFSET       (23u)
#define PARAM_UBIT_MASK         (1Lu << PARAM_UBIT_OFFSET)
#define PARAM_WDID_OFFSET       (16u)
#define PARAM_WDID_MASK         (0x7FLu << PARAM_WDID_OFFSET)
#define PARAM_CRC_OFFSET        (24u)
#define PARAM_CRC_MASK          (0x0FLu << PARAM_CRC_OFFSET)

/* Define align masks for uint16 and uint32 */
#define UINT16_ALIGN_MASK       (1Lu)
#define UINT32_ALIGN_MASK       (3Lu)

/* Define supported parameter types */
#define DS_PARAM_TYPE_UINT8     (0x01u)
#define DS_PARAM_TYPE_UINT16    (0x02u)
#define DS_PARAM_TYPE_UINT32    (0x03u)


/* Define PARAM_ID structure */
typedef struct
{
    uint16 offset;      /* parameter offset                     */
    uint8  widgetId;    /* widget Id parameter belongs to       */
    uint8  affectsCrc;  /* parameter affects widget CRC         */
    uint8  crc;         /* parameter CRC                        */
    uint8  flash;       /* parameter located in FLASH flag      */
    uint8  rw;          /* parameter is read/write flag         */
    uint8  type;        /* parameter type: uint8/uint16/uint32  */
} PARAM_ID_STRUCT;


/*******************************************************************************
* Static Function Prototypes
*******************************************************************************/
/**
* \if SECTION_CAPSENSE_INTERNAL
* \addtogroup group_capsense_internal
* \{
*/

static cystatus DsParseParamId(uint32 paramId, PARAM_ID_STRUCT *pData);

/** \}
* \endif */


/*******************************************************************************
* Function Name: CapSense_DsInitialize
****************************************************************************//**
*
* \brief
*   This function initializes the Data Structure storage.
*
* \details
*   This function copies the default widget configuration parameters 
*   from the Flash storage into the RAM Data Structure.
*
*******************************************************************************/
void CapSense_DsInitialize(void)
{
    #if (0u != CapSense_CSX_EN) || (0 != CapSense_CSD_IDAC_COMP_EN)
        uint32 snsId;
        uint32 wdgtId;
    
        CapSense_RAM_SNS_STRUCT * ptrSns;
        CapSense_FLASH_WD_STRUCT const * ptrFlashWdgt;
        uint8 const * ptrIdacInit = CapSense_ramIdacInit;
    #endif        
    
    /* Reset RAM data structure content */
    (void)memset(&CapSense_dsRam, 0, sizeof(CapSense_dsRam));
    
    /* Initialize configId and deviceId registers */
    CapSense_dsRam.configId = CapSense_CONFIG_ID;
    CapSense_dsRam.deviceId = CapSense_DEVICE_ID;
    
    /* Initialize global RAM data */
    CapSense_dsRam.csd0Config = CapSense_CSD0_CONFIG;

    #if ((0u != CapSense_CSD2X_EN) || (0u != CapSense_CSX2X_EN))
        CapSense_dsRam.csd1Config = CapSense_CSD1_CONFIG;
    #endif /* #if ((0u != CapSense_CSD2X_EN) || (0u != CapSense_CSX2X_EN)) */
    
    #if (0u != CapSense_TOTAL_CSD_WIDGETS)
        CapSense_dsRam.modCsdClk = CapSense_CSD_SCANSPEED_DIVIDER;
        
        #if (0u != CapSense_CSD_COMMON_SNS_CLK_EN)
            CapSense_dsRam.snsCsdClk = CapSense_CSD_SNS_CLK_DIVIDER;
        #endif /* #if (0u != CapSense_CSD_COMMON_SNS_CLK_EN) */
    #endif /* #if (0u != CapSense_TOTAL_CSD_WIDGETS) */
    
    #if (0u != CapSense_CSX_EN)
        CapSense_dsRam.modCsxClk = CapSense_CSX_SCANSPEED_DIVIDER;
        
        #if (0u != CapSense_CSX_COMMON_TX_CLK_EN)
            CapSense_dsRam.snsCsxClk = CapSense_CSX_TX_CLK_DIVIDER;
        #endif /* #if (0u != CapSense_CSX_COMMON_TX_CLK_EN) */
    #endif /* #if (0u != CapSense_CSX_EN) */
    
    #if (0u != CapSense_SELF_TEST_EN)
        CapSense_dsRam.glbCrc = CapSense_GLB_CRC;
    #endif /* #if (0u != CapSense_SELF_TEST_EN) */
   
    /* Initialize RAM widget data */
    CapSense_dsRam.wdgtList = CapSense_ramWidgetInit;
    
    #if (0u != CapSense_CSX_EN) || (0 != CapSense_CSD_IDAC_COMP_EN)
        /* Initialize IDAC data */
        ptrFlashWdgt = CapSense_dsFlash.wdgtArray;
        
        for (wdgtId = CapSense_TOTAL_WIDGETS; wdgtId-- > 0u; )
        {
            ptrSns = ptrFlashWdgt->ptr2SnsRam;
                
            for (snsId = CapSense_GET_SNS_CNT_BY_PTR(ptrFlashWdgt); snsId-- > 0u;)
            {
                ptrSns->idacComp[0u] = *ptrIdacInit;
                ptrIdacInit++;
                
                #if (0u != CapSense_MULTI_FREQ_SCAN_EN)
                    ptrSns->idacComp[1u] = *ptrIdacInit;
                    ptrIdacInit++;
                    
                    ptrSns->idacComp[2u] = *ptrIdacInit;
                    ptrIdacInit++;
                #endif /* #if (0u != CapSense_MULTI_FREQ_SCAN_EN) */
                
                ptrSns++;
            }
            
            ptrFlashWdgt++; /* Move to next widget */
        }
    #endif /*(0u != CapSense_CSX_EN) || (0 != CapSense_CSD_IDAC_COMP_EN)*/
    
    #if (0u != CapSense_ADC_EN)
        CapSense_AdcDsInitialize();
    #endif /* (0u != CapSense_ADC_EN) */
}


#if (0u != CapSense_ADC_EN)
    /*******************************************************************************
    * Function Name: CapSense_AdcDsInitialize
    ****************************************************************************//**
    *
    * \brief
    *   Configures the initial Adc datastructure members.
    *
    *******************************************************************************/
    void CapSense_AdcDsInitialize(void)
    {
        CapSense_dsRam.adcResolution = CapSense_ADC_RESOLUTION;
        CapSense_dsRam.adcIdac = (uint8)(CapSense_ADC_IDACVAL);
    }
#endif /* (0u != CapSense_ADC_EN) */


/*******************************************************************************
* Function Name: DsParseParamId
****************************************************************************//**
*
* \brief
*   This function parses the parameter ID and checks its correctness.
*
* \details
*   This function checks the parameter CRC if the self-test is enabled, 
*   validates the offset value and parameter type.
*
* \param paramId The parameter to parse.
* \param pData   The pointer to the structure that will hold parsed data.
*
* \return CYRET_SUCCESS     If the parameter is valid
*         CYRET_BAD_PARAM   If  the parameter is invalid
*
*******************************************************************************/
static cystatus DsParseParamId(uint32 paramId, PARAM_ID_STRUCT *pData)
{
    cystatus result = CYRET_SUCCESS;
    
    #if (0u != CapSense_SELF_TEST_EN)
        const uint8 crcTable[] =
        {
            0x00u, 0x09u, 0x0Bu, 0x02u, 0x0Fu, 0x06u, 0x04u, 0x0Du,
            0x07u, 0x0Eu, 0x0Cu, 0x05u, 0x08u, 0x01u, 0x03u, 0x0Au
        };
        
        uint32 i;
        uint32 actualCrc = 0u;
        uint32 crcIndex;
    #endif /* #if (0u != CapSense_SELF_TEST_EN) */
            
    /* Extract parameter data */
    pData->offset     = LO16(paramId);
    pData->affectsCrc = LO8((paramId & PARAM_UBIT_MASK)  >> PARAM_UBIT_OFFSET);
    pData->widgetId   = LO8((paramId & PARAM_WDID_MASK)  >> PARAM_WDID_OFFSET);
    pData->type       = LO8((paramId & PARAM_TYPE_MASK)  >> PARAM_TYPE_OFFSET);
    pData->flash      = LO8((paramId & PARAM_FBIT_MASK)  >> PARAM_FBIT_OFFSET);
    pData->rw         = LO8((paramId & PARAM_RWBIT_MASK) >> PARAM_RWBIT_OFFSET);
    pData->crc        = LO8((paramId & PARAM_CRC_MASK)   >> PARAM_CRC_OFFSET);
    
    /* Check parameter CRC if self-test is enabled */
    #if (0u != CapSense_SELF_TEST_EN)
 
        /* Calculate CRC for bits 0..24.
         * The CRC is calculated using nibbles (4-bits). 
         * So for 0..24 bits there are in total 6 nibbles. */
        for (i = 6u; i > 0u; i--)
        {
            crcIndex = actualCrc ^ (paramId & 0x0Fu);
            actualCrc = crcTable[crcIndex];
            paramId >>= 4u;
        }

        /* Add bits 28..32 */
        crcIndex = actualCrc ^ ((paramId >> 4u) & 0x0Fu);
        actualCrc = crcTable[crcIndex];

        /* Add bits 24..28 (CRC) */
        crcIndex = actualCrc ^ (paramId & 0x0Fu);
        actualCrc = crcTable[crcIndex];
        
        if (0u != actualCrc)
        {
            /* CRC mismatch */
            result = CYRET_BAD_PARAM;
        }
        
        if ((CYRET_SUCCESS == result) && 
            (0u != pData->affectsCrc) && (pData->widgetId >= CapSense_TOTAL_WIDGETS ))
        {
            /* Wrong widgetId for protected parameter */
            result = CYRET_BAD_PARAM;
        }
        
        /* Check offset value range */
        if (CYRET_SUCCESS == result)
        {
            if (0u == pData->flash)
            {
                /* Check offset for RAM Data Structure range */
                if (pData->offset >= sizeof(CapSense_dsRam))
                {
                    result = CYRET_BAD_PARAM;
                }
            }
            else
            {
                /* Check offset for Flash Data Structure range */
                if (pData->offset >= sizeof(CapSense_dsFlash))
                {
                    result = CYRET_BAD_PARAM;
                }
                
                /* Check if it is marked as Read Only */
                if (0u != pData->rw)
                {
                    result = CYRET_BAD_PARAM;
                }
            }
        }
    #else /* #if (0u != CapSense_SELF_TEST_EN) */
        /* Check offset value range */
        if (0u == pData->flash)
        {
            /* Check offset for RAM Data Structure range */
            if (pData->offset >= sizeof(CapSense_dsRam))
            {
                result = CYRET_BAD_PARAM;
            }
        }
        else
        {
            /* Check offset for Flash Data Structure range */
            if (pData->offset >= sizeof(CapSense_dsFlash))
            {
                result = CYRET_BAD_PARAM;
            }
            
            /* Check if it is marked as Read Only */
            if (0u != pData->rw)
            {
                result = CYRET_BAD_PARAM;
            }
        }
    #endif /* #if (0u != CapSense_SELF_TEST_EN) */

    if (CYRET_SUCCESS == result)
    {
        /* Check parameter type, offset alignment */
        switch (pData->type)
        {
        case DS_PARAM_TYPE_UINT16:
            if (0u != (pData->offset & UINT16_ALIGN_MASK))
            {
                result = CYRET_BAD_PARAM;
            }
            break;
            
        case DS_PARAM_TYPE_UINT32:
            if (0u != (pData->offset & UINT32_ALIGN_MASK))
            {
                result = CYRET_BAD_PARAM;
            }
            break;
            
        case DS_PARAM_TYPE_UINT8:
            break;
            
        default:
            result = CYRET_BAD_PARAM;
            break;
        }
    }

    return result;
}

/*******************************************************************************
* Function Name: CapSense_GetParam
****************************************************************************//**
*
* \brief
*  Gets the specified parameter value from the \ref group_structures.
*
* \details
*  This function gets the value of the specified parameter by the paramId 
*  argument. The paramId for each register is available in the 
*  CapSense RegisterMap header file as 
*  CapSense_<ParameterName>_PARAM_ID. The paramId is a special 
*  enumerated value generated by the customizer. The format of paramId is as 
*  follows:
*    1. [ byte 3 byte 2 byte 1 byte 0 ] 
*    2. [ TTWFCCCC UIIIIIII MMMMMMMM LLLLLLLL ]
*    3. T - encodes the parameter type:
*      - 01b: uint8
*      - 10b: uint16
*      - 11b: uint32
*    4. W - indicates whether the parameter is writable:
*      - 0: ReadOnly
*      - 1: Read/Write
*    5. C - 4 bit CRC (X^3 + 1) of the whole paramId word, the C bits are 
*       filled with 0s when the CRC is calculated.
*    6. U - indicates if the parameter affects the RAM Widget Object CRC.
*    7. I - specifies that the widgetID parameter belongs to
*    8. M,L - the parameter offset MSB and LSB accordingly in:
*      - Flash Data Structure if W bit is 0.
*      - RAM Data Structure if W bit is 1.
*
*  Refer to the \ref group_structures section for details of the data structure 
*  organization and examples of its register access.
*
* \param  paramId 
*  Specify the ID of parameter to get its value.
*  A macro for the parameter ID can be found in the CapSense RegisterMap header 
*  file defined as CapSense_<ParameterName>_PARAM_ID.
*
* \param  value   
*  The pointer to a variable that should be updated with the got value.
*
* \return
*  Returns the status of operation:
*    - CYRET_SUCCESS if the operation is successfully completed.
*    - CYRET_BAD_PARAM if the input parameter is invalid. 
*
*******************************************************************************/
cystatus CapSense_GetParam(uint32 paramId, uint32 *value)
{
    PARAM_ID_STRUCT pData;
    cystatus result;
    
    union
    {
        volatile void   const * ptr;
        volatile uint8  const * ptrUint8;
        volatile uint16 const * ptrUint16;
        volatile uint32 const * ptrUint32;
    } ptrData;
    
    result = DsParseParamId(paramId, &pData);
    
    /* Parse and validate paramId */
    if (CYRET_SUCCESS == result)
    {
        /* Get base address of parameter */
        if (0u == pData.flash)
        {
            ptrData.ptr = &CapSense_dsRam;
        }
        else
        {
            ptrData.ptr = &CapSense_dsFlash;
        }
        
        /* Add offset to base address */
        ptrData.ptrUint8 += pData.offset;
        
        /* Read data */
        if (DS_PARAM_TYPE_UINT8 == pData.type)
        {
            *value = (uint32) (*ptrData.ptrUint8);
        }
        else if (DS_PARAM_TYPE_UINT16 == pData.type)
        {
            *value = (uint32) (*ptrData.ptrUint16);
        }
        else if (DS_PARAM_TYPE_UINT32 == pData.type)
        {
            *value = *ptrData.ptrUint32;
        }
        else
        {
            /* Parameter comes here already validated. */
            CYASSERT(0u);
        }
    }
    
    return result;
}


/*******************************************************************************
* Function Name: CapSense_SetParam
****************************************************************************//**
*
* \brief
*  Sets a new value for the specified parameter in the \ref group_structures.
*
* \details
*  This function sets the value of the specified parameter by the paramId 
*  argument. The paramId for each register is available in the 
*  CapSense RegisterMap header file as 
*  CapSense_<ParameterName>_PARAM_ID. The paramId is a special 
*  enumerated value generated by the customizer. The format of paramId is as 
*  follows:
*    1. [ byte 3 byte 2 byte 1 byte 0 ] 
*    2. [ TTWFCCCC UIIIIIII MMMMMMMM LLLLLLLL ]
*    3. T - encodes the parameter type:
*      - 01b: uint8
*      - 10b: uint16
*      - 11b: uint32
*    4. W - indicates whether the parameter is writable:
*      - 0: ReadOnly
*      - 1: Read/Write
*    5. C - 4 bit CRC (X^3 + 1) of the whole paramId word, the C bits are 
*       filled with 0s when the CRC is calculated.
*    6. U - indicates if the parameter affects the RAM Widget Object CRC.
*    7. I - specifies that the widgetID parameter belongs to
*    8. M,L - the parameter offset MSB and LSB accordingly in:
*      - Flash Data Structure if W bit is 0.
*      - RAM Data Structure if W bit is 1.
*
*  Refer to the \ref group_structures section for details of the data structure 
*  organization and examples of its register access.
*
* \param paramId  
*  Specify the ID of parameter to set its value.
*  A macro for the parameter ID can be found in the CapSense RegisterMap header
*  file defined as CapSense_<ParameterName>_PARAM_ID.

* \param value    
*  Specify the new parameter's value.
*
* \return
*  Returns the status of operation:
*    - CYRET_SUCCESS if the operation is successfully completed.
*    - CYRET_BAD_PARAM if the input parameter is invalid. 
*
*******************************************************************************/
cystatus CapSense_SetParam(uint32 paramId, uint32 value)
{
    cystatus result;
    PARAM_ID_STRUCT pData;
    
    union
    {
        volatile void   * ptr;
        volatile uint8  * ptrUint8;
        volatile uint16 * ptrUint16;
        volatile uint32 * ptrUint32;
    } ptrData;
    
    result = DsParseParamId(paramId, &pData);
    
    /* verify if parameter is writable */
    if (CYRET_SUCCESS == result)
    {
        if (0u == pData.rw)
        {
            result = CYRET_BAD_PARAM;
        }
    }
    
    /* Parse and validate paramId */
    if (CYRET_SUCCESS == result)
    {
        /* Get base address of parameter */
        ptrData.ptr = &CapSense_dsRam;
        
        /* Add offset to base address */
        ptrData.ptrUint8 += pData.offset;
        
        /* Write data */
        if (DS_PARAM_TYPE_UINT8 == pData.type)
        {
            *ptrData.ptrUint8 = LO8(value);
        }
        else if (DS_PARAM_TYPE_UINT16 == pData.type)
        {
            *ptrData.ptrUint16 = LO16(value);
        }
        else if (DS_PARAM_TYPE_UINT32 == pData.type)
        {
            *ptrData.ptrUint32 = value;
        }
        else
        {
            /* Parameter comes here already validated. */
            CYASSERT(0u);
        }
        
        #if (CapSense_ENABLE == (CapSense_TST_WDGT_CRC_EN || CapSense_TST_GLOBAL_CRC_EN))
            /* Update widget or global CRC if self-test is enabled and parameter affects it */
            if (0u != pData.affectsCrc)
            {
                if ((ptrData.ptrUint16 >= &CapSense_dsRam.csd0Config) &&
                    (ptrData.ptrUint16 <  &CapSense_dsRam.glbCrc))
                {
                    
                    #if (CapSense_ENABLE == CapSense_TST_GLOBAL_CRC_EN)
                        CapSense_DsUpdateGlobalCrc();
                    #endif /* (CapSense_ENABLE == CapSense_TST_GLOBAL_CRC_EN) */

                }
                else
                {
                    #if (CapSense_ENABLE == CapSense_TST_WDGT_CRC_EN)
                        CapSense_DsUpdateWidgetCrc((uint32)pData.widgetId);
                    #endif /* (CapSense_ENABLE == CapSense_TST_WDGT_CRC_EN) */
                }
            }
        #endif /* (CapSense_ENABLE == (CapSense_TST_WDGT_CRC_EN || CapSense_TST_GLOBAL_CRC_EN)) */
    }
    
    return result;
}

/*******************************************************************************
* Function Name: CapSense_IsAnyWidgetActive
****************************************************************************//**
*
* \brief
*  Reports if any widget has detected a touch.
*
* \details
*  This function reports if any widget has detected a touch or not by extracting 
*  the information from the wdgtStatus registers 
*  (CapSense_WDGT_STATUS<X>_VALUE). This function does not process any 
*  widget but extracts the processed results from the \ref group_structures.
*
* \return 
*   Returns the touch detection status of all widgets:
*     - Zero if no touch is detected in all widgets or sensors.
*     - Non-zero if at least one widget or sensor detected a touch.
*
*******************************************************************************/
uint32 CapSense_IsAnyWidgetActive(void)
{
    uint32 result = 0Lu;
    uint32 wdWord;
    
    for (wdWord = CapSense_WDGT_STATUS_WORDS; wdWord-- > 0u;)
    {
        result |= CapSense_dsRam.wdgtStatus[wdWord];
    }
    
    return result;
}


/*******************************************************************************
* Function Name: CapSense_IsWidgetActive
****************************************************************************//**
*
* \brief
*  Reports if the specified widget detects a touch on any of its sensors.
*
* \details
*  This function reports if the specified widget has detected a touch or not by 
*  extracting the information from the wdgtStatus registers 
*  (CapSense_WDGT_STATUS<X>_VALUE). This function does not process the 
*  widget, but extracts the processed results from the \ref group_structures.
*
* \param widgetId  
*  Specify the ID number of the widget to get its status.
*  A macro for the widget ID can be found in the CapSense Configuration header 
*  file defined as CapSense_<WidgetName>_WDGT_ID.
*
* \return 
*  Returns the touch detection status of the specified widgets:
*    - Zero if no touch is detected in the specified widget or a wrong widgetId
*      is specified
*    - Non-zero if at least one sensor of the specified widget is active i.e. 
*      touch is detected
*
*******************************************************************************/
uint32 CapSense_IsWidgetActive(uint32 widgetId)
{
    uint32 result = 0Lu;
   
    if (widgetId < CapSense_TOTAL_WIDGETS)
    {
        result = CapSense_GET_WIDGET_ACTIVE_STATUS(widgetId);
    }
    return result;
}


/*******************************************************************************
* Function Name: CapSense_IsSensorActive
****************************************************************************//**
*
* \brief
*  Reports if the specified sensor in the widget detects a touch.
*
* \details 
*  This function reports if the specified sensor in the widget has detected a 
*  touch or not by extracting the information from wdgtStatus registers 
*  (CapSense_WDGT_STATUS<X>_VALUE). This function does not process the
*  widget or sensor, but extracts the processed results from the \ref group_structures.
*   
*  For Proximity sensors this function returns proximity detection status. To 
*  get finger touch status of proximity sensors, use the 
*  CapSense_IsProximitySensorActive() function. 
*
* \param widgetId  
*  Specify the ID number of the widget.
*  A macro for the widget ID can be found in the CapSense Configuration header 
*  file defined as CapSense_<WidgetName>_WDGT_ID 

* \param sensorId  
*  Specify the ID number of the sensor within the widget to get its touch 
*  detection status.
*  A macro for the sensor ID within specified widget can be found in the 
*  CapSense Configuration header file defined as 
*  CapSense_<WidgetName>_SNS<SensorNumber>_ID 
*
* \return 
*  Returns the touch detection status of the specified sensor / widget:
*    - Zero if no touch is detected in the specified sensor / widget or a wrong
*      widget ID / sensor ID is specified
*    - Non-zero if the specified sensor is active i.e. touch is detected. If the
*      specific sensor belongs to a proximity widget, the proximity detection 
*      status is returned.
*
*******************************************************************************/
uint32 CapSense_IsSensorActive(uint32 widgetId, uint32 sensorId)
{
    uint32 result = 0Lu;
    
    if ((widgetId < CapSense_TOTAL_WIDGETS) &&
        (sensorId < CapSense_GET_SENSOR_COUNT(widgetId)))
    {
        #if (CapSense_ENABLE == CapSense_PROXIMITY_WIDGET_EN)
            if (CapSense_WD_PROXIMITY_E == 
				(CapSense_WD_TYPE_ENUM)CapSense_dsFlash.wdgtArray[widgetId].wdgtType)
            {
                sensorId = CapSense_PROX_STS_OFFSET(sensorId);
            }
        #endif /* (CapSense_ENABLE != CapSense_PROXIMITY_WIDGET_EN) */
        result = CapSense_dsRam.snsStatus[widgetId] & (1Lu << sensorId);
    }
    
    return result;
}

#if (0u != CapSense_MATRIX_WIDGET_EN)
/*******************************************************************************
* Function Name: CapSense_IsMatrixButtonsActive
****************************************************************************//**
*
* \brief
*  Reports the status of the specified matrix button widget.
*
* \details 
*  This function reports if the specified matrix widget has detected a touch or
*  not by extracting the information from the wdgtStatus registers 
*  (CapSense_WDGT_STATUS<X>_VALUE for the CSD widgets and 
*  CapSense_SNS_STATUS<WidgetId>_VALUE for CSX widget). In addition, the
*  function provides details of the active sensor including active rows/columns 
*  for the CSD widgets. This function should be used only with the matrix button
*  widgets. This function does not process the widget, but extracts the 
*  processed results from the \ref group_structures.
*
* \param widgetId 
*  Specify the ID number of the matrix button widget to check status of its 
*  sensors. 
*  A macro for widget ID can be found in the CapSense Configuration header file 
*  defined as CapSense_<WidgetName>_WDGT_ID
*
* \return 
*  Returns the touch detection status of sensors in the specified matrix 
*  buttons widget. Zero indicates that no touch is detected in the specified 
*  widget or a wrong widgetId is specified.
*    1. For the matrix buttons widgets with the CSD sensing mode:
*      - Bit [31] if set, indicates that one or more sensors in the widget 
*        detected a touch.
*      - Bits [30..24] is reserved
*      - Bits [23..16] indicates the logical sensor number of the sensor that 
*        detected a touch. If more than one sensor detected a touch for the CSD
*        widget, no status is reported as more than one touch is invalid for the
*        CSD matrix buttons widgets.
*      - Bits [15..8] indicates the active row number.
*      - Bits [7..0] indicates the active column number.
*    2. For the matrix buttons widgets with the CSX widgets, each bit (31..0)
*      corresponds to the TX/RX intersection.
*
*******************************************************************************/
uint32 CapSense_IsMatrixButtonsActive(uint32 widgetId)
{
    uint32 result = 0Lu;
    cystatus state = CYRET_SUCCESS;
    CapSense_FLASH_WD_STRUCT const *ptrFlashWdgt = 0u;
    
    #if (0u != CapSense_CSD_MATRIX_WIDGET_EN)
        CapSense_RAM_WD_CSD_MATRIX_STRUCT *wdCsdMatrix;
    #endif
  
    if (widgetId >= CapSense_TOTAL_WIDGETS)
    {
        state = CYRET_BAD_PARAM;
    }
    else
    {
        ptrFlashWdgt = &CapSense_dsFlash.wdgtArray[widgetId];
        
        if ((CapSense_WD_TYPE_ENUM)ptrFlashWdgt->wdgtType != CapSense_WD_MATRIX_BUTTON_E)
        {
            state = CYRET_BAD_PARAM;
        }
        else if (0u == CapSense_GET_WIDGET_ACTIVE_STATUS(widgetId))
        {
            state = CYRET_BAD_PARAM;
        }
        else
        {
            /* input parameters are OK */
        }
    }
       
    if (CYRET_SUCCESS == state)
    {
        switch(CapSense_GET_SENSE_METHOD(ptrFlashWdgt))
        {
        #if (0u != CapSense_CSD_MATRIX_WIDGET_EN)
            case CapSense_SENSE_METHOD_CSD_E:
                wdCsdMatrix = ptrFlashWdgt->ptr2WdgtRam;
                
                result = CapSense_MATRIX_BUTTONS_TOUCHED | 
                         ((uint32)wdCsdMatrix->posSnsId << 16u)  |
                         ((uint32)wdCsdMatrix->posRow   << 8u)   |
                         (uint32)wdCsdMatrix->posCol;
                break;
        #endif /* #if (0u != CapSense_CSD_MATRIX_WIDGET_EN) */
        
        #if (0u != CapSense_CSX_MATRIX_WIDGET_EN)
            case CapSense_SENSE_METHOD_CSX_E:
                result = CapSense_dsRam.snsStatus[widgetId];
                break;
        #endif /* #if (0u != CapSense_CSX_MATRIX_WIDGET_EN) */
        
        default:
            CYASSERT(0u);
            break;
        }
    }
    
    return result;
}
#endif /* #if (0u != CapSense_MATRIX_WIDGET_EN) */

#if (0u != CapSense_PROXIMITY_WIDGET_EN)
/*******************************************************************************
* Function Name: CapSense_IsProximitySensorActive
****************************************************************************//**
*
* \brief
*  Reports the finger detection status of the specified proximity widget/sensor.
*
* \details 
*  This function reports if the specified proximity sensor has detected a touch
*  or not by extracting the information from the wdgtStatus registers 
*  (CapSense_SNS_STATUS<WidgetId>_VALUE). This function should be used 
*  only with the proximity sensor widgets. This function does not process the 
*  widget but extracts the processed results from the \ref group_structures.
*
* \param widgetId  
*  Specify the ID number of the proximity widget.
*  A macro for the widget ID can be found in the CapSense Configuration header 
*  file defined as CapSense_<WidgetName>_WDGT_ID
*  
* \param proxId    
*  Specify the ID number of the proximity sensor within the proximity widget to 
*  get its touch detection status.
*  A macro for the proximity ID within a specified widget can be found in the
*  CapSense Configuration header file defined as 
*  CapSense_<WidgetName>_SNS<SensorNumber>_ID
*
* \return 
*  Returns the status of the specified sensor of proximity widget. Zero 
*  indicates that no touch is detected in the specified sensor / widget or a 
*  wrong widgetId / proxId is specified.
*    - Bits [31..2] is reserved.
*    - Bit [1] indicates that a touch is detected.
*    - Bit [0] indicates that a proximity is detected.
*
*******************************************************************************/
uint32 CapSense_IsProximitySensorActive(uint32 widgetId, uint32 proxId)
{
    uint32 result = 0Lu;
    
    if ((widgetId < CapSense_TOTAL_WIDGETS) && (proxId < CapSense_GET_SENSOR_COUNT(widgetId)) &&
        (CapSense_WD_PROXIMITY_E == 
            (CapSense_WD_TYPE_ENUM)CapSense_dsFlash.wdgtArray[widgetId].wdgtType))
    {
        result = CapSense_dsRam.snsStatus[widgetId];
        result >>= CapSense_PROX_STS_OFFSET(proxId);
        result &=  CapSense_PROX_STS_MASK;
    }
    
    return result;
}
#endif /* #if (0u != CapSense_PROXIMITY_WIDGET_EN) */


#if (0u != CapSense_SLIDER_WIDGET_EN)
/*******************************************************************************
* Function Name: CapSense_GetCentroidPos
****************************************************************************//**
*
* \brief
*  Reports the centroid position for the specified slider widget.
*
* \details 
*  This function reports the centrode value of a specified radial or linear 
*  slider widget by extracting the information from the wdgtStatus registers 
*  (CapSense_<WidgetName>_POSITION<X>_VALUE). This function should be 
*  used only with the radial or linear slider widgets. This function does not 
*  process the widget but extracts the processed results from the \ref group_structures.
*
* \param widgetId 
*  Specify the ID number of the slider widget to get the centroid of the 
*  detected touch.
*  A macro for the widget ID can be found in the 
*  CapSense Configuration header file defined as 
*  CapSense_<WidgetName>_WDGT_ID
*
* \return 
*  Returns the centroid position of a specified slider widget:
*    - The centroid position if a touch is detected.
*    - CapSense_SLIDER_NO_TOUCH if no touch is detected or a wrong 
*      widgetId is specified.
*
*******************************************************************************/
uint32 CapSense_GetCentroidPos(uint32 widgetId)
{
    uint32 result = CapSense_SLIDER_NO_TOUCH;
    CapSense_RAM_WD_SLIDER_STRUCT *wdSlider;
    
    if ((widgetId < CapSense_TOTAL_WIDGETS) && 
        ((CapSense_WD_LINEAR_SLIDER_E == 
            (CapSense_WD_TYPE_ENUM)CapSense_dsFlash.wdgtArray[widgetId].wdgtType) ||
         (CapSense_WD_RADIAL_SLIDER_E == 
            (CapSense_WD_TYPE_ENUM)CapSense_dsFlash.wdgtArray[widgetId].wdgtType)))
    {
        wdSlider = CapSense_dsFlash.wdgtArray[widgetId].ptr2WdgtRam;
        result = (uint32)wdSlider->position[0u];
    }
    
    return result;
}
#endif /* #if (0u != CapSense_SLIDER_WIDGET_EN) */


#if (0u != CapSense_TOUCHPAD_WIDGET_EN)
/*******************************************************************************
* Function Name: CapSense_GetXYCoordinates
****************************************************************************//**
*
* \brief
*  Reports the X/Y position detected for the specified touchpad widget.
*
* \details 
*  This function reports a touch position (X and Y coordinates) value of a 
*  specified touchpad widget by extracting the information from the wdgtStatus 
*  registers (CapSense_<WidgetName>_POS_Y_VALUE). This function should 
*  be used only with the touchpad widgets. This function does not process the 
*  widget, but extracts the processed results from the \ref group_structures.
*
* \param widgetId 
*  Specify the ID number of the touchpad widget to get the X/Y position of a 
*  detected touch.
*  A macro for the widget ID can be found in the 
*  CapSense Configuration header file defined as 
*  CapSense_<WidgetName>_WDGT_ID.
*
* \return 
*  Returns the touch position of a specified touchpad widget:
*    1. If a touch is detected:
*      - Bits [31..16] indicates the Y coordinate.
*      - Bits [15..0] indicates the X coordinate.
*    2. If no touch is detected or a wrong widgetId is specified:
*      - CapSense_TOUCHPAD_NO_TOUCH.
*
*******************************************************************************/
uint32 CapSense_GetXYCoordinates(uint32 widgetId)
{
    CapSense_FLASH_WD_STRUCT const *ptrFlashWdgt = NULL;
    
    #if (0u != CapSense_CSD_TOUCHPAD_WIDGET_EN)
        CapSense_RAM_WD_CSD_TOUCHPAD_STRUCT *wdCsdTouchpad;
    #endif /* #if (0u != CapSense_CSD_TOUCHPAD_WIDGET_EN) */
    
    #if (0u != CapSense_CSX_TOUCHPAD_WIDGET_EN)
        CapSense_RAM_WD_CSX_TOUCHPAD_STRUCT *wdCsxTouchpad;
    #endif /* #if (0u != CapSense_CSX_TOUCHPAD_WIDGET_EN) */
    
    cystatus state = CYRET_SUCCESS;
    uint32 result = CapSense_TOUCHPAD_NO_TOUCH;

    if (widgetId >= CapSense_TOTAL_WIDGETS)
    {
        state = CYRET_BAD_PARAM;
    }
    else
    {
        ptrFlashWdgt = &CapSense_dsFlash.wdgtArray[widgetId];
         
        if ((CapSense_WD_TYPE_ENUM)ptrFlashWdgt->wdgtType != CapSense_WD_TOUCHPAD_E)
        {
            state = CYRET_BAD_PARAM;
        }
    }
      
    if (CYRET_SUCCESS == state)
    {
        switch(CapSense_GET_SENSE_METHOD(ptrFlashWdgt))
        {
        #if (0u != CapSense_CSD_TOUCHPAD_WIDGET_EN)
            case CapSense_SENSE_METHOD_CSD_E:
                wdCsdTouchpad = ptrFlashWdgt->ptr2WdgtRam;
                
                result = ((uint32)wdCsdTouchpad->posX) |
                         ((uint32)wdCsdTouchpad->posY << 16u);
                break;
        #endif /* #if (0u != CapSense_CSD_TOUCHPAD_WIDGET_EN) */
        
        #if (0u != CapSense_CSX_TOUCHPAD_WIDGET_EN)
            case CapSense_SENSE_METHOD_CSX_E:
                wdCsxTouchpad = ptrFlashWdgt->ptr2WdgtRam;
                
                result = ((uint32)wdCsxTouchpad->touch[0u].x) |
                         ((uint32)wdCsxTouchpad->touch[0u].y << 16u);
                break;
        #endif /* #if (0u != CapSense_CSX_TOUCHPAD_WIDGET_EN) */
        
        default:
            CYASSERT(0u);
            break;
        }
    }
    
    return result;
}
#endif /* #if (0u != CapSense_TOUCHPAD_WIDGET_EN) */


/* [] END OF FILE */
