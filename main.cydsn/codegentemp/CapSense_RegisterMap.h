/***************************************************************************//**
* \file CapSense_RegisterMap.h
* \version 3.10
*
* \brief
*   This file provides the definitions for the component data structure register.
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

#if !defined(CY_CAPSENSE_CapSense_REGISTER_MAP_H)
#define CY_CAPSENSE_CapSense_REGISTER_MAP_H

#include <cytypes.h>
#include "CapSense_Configuration.h"
#include "CapSense_Structure.h"

/*****************************************************************************/
/* RAM Data structure register definitions                                   */
/*****************************************************************************/
#define CapSense_CONFIG_ID_VALUE                            (CapSense_dsRam.configId)
#define CapSense_CONFIG_ID_OFFSET                           (0u)
#define CapSense_CONFIG_ID_SIZE                             (2u)
#define CapSense_CONFIG_ID_PARAM_ID                         (0x87000000u)

#define CapSense_DEVICE_ID_VALUE                            (CapSense_dsRam.deviceId)
#define CapSense_DEVICE_ID_OFFSET                           (2u)
#define CapSense_DEVICE_ID_SIZE                             (2u)
#define CapSense_DEVICE_ID_PARAM_ID                         (0x8B000002u)

#define CapSense_TUNER_CMD_VALUE                            (CapSense_dsRam.tunerCmd)
#define CapSense_TUNER_CMD_OFFSET                           (4u)
#define CapSense_TUNER_CMD_SIZE                             (2u)
#define CapSense_TUNER_CMD_PARAM_ID                         (0xAD000004u)

#define CapSense_SCAN_COUNTER_VALUE                         (CapSense_dsRam.scanCounter)
#define CapSense_SCAN_COUNTER_OFFSET                        (6u)
#define CapSense_SCAN_COUNTER_SIZE                          (2u)
#define CapSense_SCAN_COUNTER_PARAM_ID                      (0x8A000006u)

#define CapSense_STATUS_VALUE                               (CapSense_dsRam.status)
#define CapSense_STATUS_OFFSET                              (8u)
#define CapSense_STATUS_SIZE                                (4u)
#define CapSense_STATUS_PARAM_ID                            (0xCA000008u)

#define CapSense_WDGT_ENABLE0_VALUE                         (CapSense_dsRam.wdgtEnable[0u])
#define CapSense_WDGT_ENABLE0_OFFSET                        (12u)
#define CapSense_WDGT_ENABLE0_SIZE                          (4u)
#define CapSense_WDGT_ENABLE0_PARAM_ID                      (0xE000000Cu)

#define CapSense_WDGT_STATUS0_VALUE                         (CapSense_dsRam.wdgtStatus[0u])
#define CapSense_WDGT_STATUS0_OFFSET                        (16u)
#define CapSense_WDGT_STATUS0_SIZE                          (4u)
#define CapSense_WDGT_STATUS0_PARAM_ID                      (0xCD000010u)

#define CapSense_SNS_STATUS0_VALUE                          (CapSense_dsRam.snsStatus[0u])
#define CapSense_SNS_STATUS0_OFFSET                         (20u)
#define CapSense_SNS_STATUS0_SIZE                           (1u)
#define CapSense_SNS_STATUS0_PARAM_ID                       (0x4B000014u)

#define CapSense_SNS_STATUS1_VALUE                          (CapSense_dsRam.snsStatus[1u])
#define CapSense_SNS_STATUS1_OFFSET                         (21u)
#define CapSense_SNS_STATUS1_SIZE                           (1u)
#define CapSense_SNS_STATUS1_PARAM_ID                       (0x4D000015u)

#define CapSense_SNS_STATUS2_VALUE                          (CapSense_dsRam.snsStatus[2u])
#define CapSense_SNS_STATUS2_OFFSET                         (22u)
#define CapSense_SNS_STATUS2_SIZE                           (1u)
#define CapSense_SNS_STATUS2_PARAM_ID                       (0x47000016u)

#define CapSense_SNS_STATUS3_VALUE                          (CapSense_dsRam.snsStatus[3u])
#define CapSense_SNS_STATUS3_OFFSET                         (23u)
#define CapSense_SNS_STATUS3_SIZE                           (1u)
#define CapSense_SNS_STATUS3_PARAM_ID                       (0x41000017u)

#define CapSense_SNS_STATUS4_VALUE                          (CapSense_dsRam.snsStatus[4u])
#define CapSense_SNS_STATUS4_OFFSET                         (24u)
#define CapSense_SNS_STATUS4_SIZE                           (1u)
#define CapSense_SNS_STATUS4_PARAM_ID                       (0x48000018u)

#define CapSense_SNS_STATUS5_VALUE                          (CapSense_dsRam.snsStatus[5u])
#define CapSense_SNS_STATUS5_OFFSET                         (25u)
#define CapSense_SNS_STATUS5_SIZE                           (1u)
#define CapSense_SNS_STATUS5_PARAM_ID                       (0x4E000019u)

#define CapSense_SNS_STATUS6_VALUE                          (CapSense_dsRam.snsStatus[6u])
#define CapSense_SNS_STATUS6_OFFSET                         (26u)
#define CapSense_SNS_STATUS6_SIZE                           (1u)
#define CapSense_SNS_STATUS6_PARAM_ID                       (0x4400001Au)

#define CapSense_SNS_STATUS7_VALUE                          (CapSense_dsRam.snsStatus[7u])
#define CapSense_SNS_STATUS7_OFFSET                         (27u)
#define CapSense_SNS_STATUS7_SIZE                           (1u)
#define CapSense_SNS_STATUS7_PARAM_ID                       (0x4200001Bu)

#define CapSense_SNS_STATUS8_VALUE                          (CapSense_dsRam.snsStatus[8u])
#define CapSense_SNS_STATUS8_OFFSET                         (28u)
#define CapSense_SNS_STATUS8_SIZE                           (1u)
#define CapSense_SNS_STATUS8_PARAM_ID                       (0x4900001Cu)

#define CapSense_SNS_STATUS9_VALUE                          (CapSense_dsRam.snsStatus[9u])
#define CapSense_SNS_STATUS9_OFFSET                         (29u)
#define CapSense_SNS_STATUS9_SIZE                           (1u)
#define CapSense_SNS_STATUS9_PARAM_ID                       (0x4F00001Du)

#define CapSense_SNS_STATUS10_VALUE                         (CapSense_dsRam.snsStatus[10u])
#define CapSense_SNS_STATUS10_OFFSET                        (30u)
#define CapSense_SNS_STATUS10_SIZE                          (1u)
#define CapSense_SNS_STATUS10_PARAM_ID                      (0x4500001Eu)

#define CapSense_SNS_STATUS11_VALUE                         (CapSense_dsRam.snsStatus[11u])
#define CapSense_SNS_STATUS11_OFFSET                        (31u)
#define CapSense_SNS_STATUS11_SIZE                          (1u)
#define CapSense_SNS_STATUS11_PARAM_ID                      (0x4300001Fu)

#define CapSense_SNS_STATUS12_VALUE                         (CapSense_dsRam.snsStatus[12u])
#define CapSense_SNS_STATUS12_OFFSET                        (32u)
#define CapSense_SNS_STATUS12_SIZE                          (1u)
#define CapSense_SNS_STATUS12_PARAM_ID                      (0x45000020u)

#define CapSense_SNS_STATUS13_VALUE                         (CapSense_dsRam.snsStatus[13u])
#define CapSense_SNS_STATUS13_OFFSET                        (33u)
#define CapSense_SNS_STATUS13_SIZE                          (1u)
#define CapSense_SNS_STATUS13_PARAM_ID                      (0x43000021u)

#define CapSense_SNS_STATUS14_VALUE                         (CapSense_dsRam.snsStatus[14u])
#define CapSense_SNS_STATUS14_OFFSET                        (34u)
#define CapSense_SNS_STATUS14_SIZE                          (1u)
#define CapSense_SNS_STATUS14_PARAM_ID                      (0x49000022u)

#define CapSense_SNS_STATUS15_VALUE                         (CapSense_dsRam.snsStatus[15u])
#define CapSense_SNS_STATUS15_OFFSET                        (35u)
#define CapSense_SNS_STATUS15_SIZE                          (1u)
#define CapSense_SNS_STATUS15_PARAM_ID                      (0x4F000023u)

#define CapSense_SNS_STATUS16_VALUE                         (CapSense_dsRam.snsStatus[16u])
#define CapSense_SNS_STATUS16_OFFSET                        (36u)
#define CapSense_SNS_STATUS16_SIZE                          (1u)
#define CapSense_SNS_STATUS16_PARAM_ID                      (0x44000024u)

#define CapSense_SNS_STATUS17_VALUE                         (CapSense_dsRam.snsStatus[17u])
#define CapSense_SNS_STATUS17_OFFSET                        (37u)
#define CapSense_SNS_STATUS17_SIZE                          (1u)
#define CapSense_SNS_STATUS17_PARAM_ID                      (0x42000025u)

#define CapSense_SNS_STATUS18_VALUE                         (CapSense_dsRam.snsStatus[18u])
#define CapSense_SNS_STATUS18_OFFSET                        (38u)
#define CapSense_SNS_STATUS18_SIZE                          (1u)
#define CapSense_SNS_STATUS18_PARAM_ID                      (0x48000026u)

#define CapSense_SNS_STATUS19_VALUE                         (CapSense_dsRam.snsStatus[19u])
#define CapSense_SNS_STATUS19_OFFSET                        (39u)
#define CapSense_SNS_STATUS19_SIZE                          (1u)
#define CapSense_SNS_STATUS19_PARAM_ID                      (0x4E000027u)

#define CapSense_SNS_STATUS20_VALUE                         (CapSense_dsRam.snsStatus[20u])
#define CapSense_SNS_STATUS20_OFFSET                        (40u)
#define CapSense_SNS_STATUS20_SIZE                          (1u)
#define CapSense_SNS_STATUS20_PARAM_ID                      (0x47000028u)

#define CapSense_SNS_STATUS21_VALUE                         (CapSense_dsRam.snsStatus[21u])
#define CapSense_SNS_STATUS21_OFFSET                        (41u)
#define CapSense_SNS_STATUS21_SIZE                          (1u)
#define CapSense_SNS_STATUS21_PARAM_ID                      (0x41000029u)

#define CapSense_SNS_STATUS22_VALUE                         (CapSense_dsRam.snsStatus[22u])
#define CapSense_SNS_STATUS22_OFFSET                        (42u)
#define CapSense_SNS_STATUS22_SIZE                          (1u)
#define CapSense_SNS_STATUS22_PARAM_ID                      (0x4B00002Au)

#define CapSense_SNS_STATUS23_VALUE                         (CapSense_dsRam.snsStatus[23u])
#define CapSense_SNS_STATUS23_OFFSET                        (43u)
#define CapSense_SNS_STATUS23_SIZE                          (1u)
#define CapSense_SNS_STATUS23_PARAM_ID                      (0x4D00002Bu)

#define CapSense_SNS_STATUS24_VALUE                         (CapSense_dsRam.snsStatus[24u])
#define CapSense_SNS_STATUS24_OFFSET                        (44u)
#define CapSense_SNS_STATUS24_SIZE                          (1u)
#define CapSense_SNS_STATUS24_PARAM_ID                      (0x4600002Cu)

#define CapSense_SNS_STATUS25_VALUE                         (CapSense_dsRam.snsStatus[25u])
#define CapSense_SNS_STATUS25_OFFSET                        (45u)
#define CapSense_SNS_STATUS25_SIZE                          (1u)
#define CapSense_SNS_STATUS25_PARAM_ID                      (0x4000002Du)

#define CapSense_SNS_STATUS26_VALUE                         (CapSense_dsRam.snsStatus[26u])
#define CapSense_SNS_STATUS26_OFFSET                        (46u)
#define CapSense_SNS_STATUS26_SIZE                          (1u)
#define CapSense_SNS_STATUS26_PARAM_ID                      (0x4A00002Eu)

#define CapSense_SNS_STATUS27_VALUE                         (CapSense_dsRam.snsStatus[27u])
#define CapSense_SNS_STATUS27_OFFSET                        (47u)
#define CapSense_SNS_STATUS27_SIZE                          (1u)
#define CapSense_SNS_STATUS27_PARAM_ID                      (0x4C00002Fu)

#define CapSense_SNS_STATUS28_VALUE                         (CapSense_dsRam.snsStatus[28u])
#define CapSense_SNS_STATUS28_OFFSET                        (48u)
#define CapSense_SNS_STATUS28_SIZE                          (1u)
#define CapSense_SNS_STATUS28_PARAM_ID                      (0x40000030u)

#define CapSense_SNS_STATUS29_VALUE                         (CapSense_dsRam.snsStatus[29u])
#define CapSense_SNS_STATUS29_OFFSET                        (49u)
#define CapSense_SNS_STATUS29_SIZE                          (1u)
#define CapSense_SNS_STATUS29_PARAM_ID                      (0x46000031u)

#define CapSense_SNS_STATUS30_VALUE                         (CapSense_dsRam.snsStatus[30u])
#define CapSense_SNS_STATUS30_OFFSET                        (50u)
#define CapSense_SNS_STATUS30_SIZE                          (1u)
#define CapSense_SNS_STATUS30_PARAM_ID                      (0x4C000032u)

#define CapSense_SNS_STATUS31_VALUE                         (CapSense_dsRam.snsStatus[31u])
#define CapSense_SNS_STATUS31_OFFSET                        (51u)
#define CapSense_SNS_STATUS31_SIZE                          (1u)
#define CapSense_SNS_STATUS31_PARAM_ID                      (0x4A000033u)

#define CapSense_CSD0_CONFIG_VALUE                          (CapSense_dsRam.csd0Config)
#define CapSense_CSD0_CONFIG_OFFSET                         (52u)
#define CapSense_CSD0_CONFIG_SIZE                           (2u)
#define CapSense_CSD0_CONFIG_PARAM_ID                       (0xAF800034u)

#define CapSense_MOD_CSD_CLK_VALUE                          (CapSense_dsRam.modCsdClk)
#define CapSense_MOD_CSD_CLK_OFFSET                         (54u)
#define CapSense_MOD_CSD_CLK_SIZE                           (1u)
#define CapSense_MOD_CSD_CLK_PARAM_ID                       (0x6B800036u)

#define CapSense_BUTTON0_RESOLUTION_VALUE                   (CapSense_dsRam.wdgtList.button0.resolution)
#define CapSense_BUTTON0_RESOLUTION_OFFSET                  (56u)
#define CapSense_BUTTON0_RESOLUTION_SIZE                    (2u)
#define CapSense_BUTTON0_RESOLUTION_PARAM_ID                (0x87800038u)

#define CapSense_BUTTON0_FINGER_TH_VALUE                    (CapSense_dsRam.wdgtList.button0.fingerTh)
#define CapSense_BUTTON0_FINGER_TH_OFFSET                   (58u)
#define CapSense_BUTTON0_FINGER_TH_SIZE                     (2u)
#define CapSense_BUTTON0_FINGER_TH_PARAM_ID                 (0x8B80003Au)

#define CapSense_BUTTON0_NOISE_TH_VALUE                     (CapSense_dsRam.wdgtList.button0.noiseTh)
#define CapSense_BUTTON0_NOISE_TH_OFFSET                    (60u)
#define CapSense_BUTTON0_NOISE_TH_SIZE                      (1u)
#define CapSense_BUTTON0_NOISE_TH_PARAM_ID                  (0x4E80003Cu)

#define CapSense_BUTTON0_NNOISE_TH_VALUE                    (CapSense_dsRam.wdgtList.button0.nNoiseTh)
#define CapSense_BUTTON0_NNOISE_TH_OFFSET                   (61u)
#define CapSense_BUTTON0_NNOISE_TH_SIZE                     (1u)
#define CapSense_BUTTON0_NNOISE_TH_PARAM_ID                 (0x4880003Du)

#define CapSense_BUTTON0_HYSTERESIS_VALUE                   (CapSense_dsRam.wdgtList.button0.hysteresis)
#define CapSense_BUTTON0_HYSTERESIS_OFFSET                  (62u)
#define CapSense_BUTTON0_HYSTERESIS_SIZE                    (1u)
#define CapSense_BUTTON0_HYSTERESIS_PARAM_ID                (0x4280003Eu)

#define CapSense_BUTTON0_ON_DEBOUNCE_VALUE                  (CapSense_dsRam.wdgtList.button0.onDebounce)
#define CapSense_BUTTON0_ON_DEBOUNCE_OFFSET                 (63u)
#define CapSense_BUTTON0_ON_DEBOUNCE_SIZE                   (1u)
#define CapSense_BUTTON0_ON_DEBOUNCE_PARAM_ID               (0x4480003Fu)

#define CapSense_BUTTON0_LOW_BSLN_RST_VALUE                 (CapSense_dsRam.wdgtList.button0.lowBslnRst)
#define CapSense_BUTTON0_LOW_BSLN_RST_OFFSET                (64u)
#define CapSense_BUTTON0_LOW_BSLN_RST_SIZE                  (1u)
#define CapSense_BUTTON0_LOW_BSLN_RST_PARAM_ID              (0x4F800040u)

#define CapSense_BUTTON0_BSLN_COEFF_VALUE                   (CapSense_dsRam.wdgtList.button0.bslnCoeff)
#define CapSense_BUTTON0_BSLN_COEFF_OFFSET                  (65u)
#define CapSense_BUTTON0_BSLN_COEFF_SIZE                    (1u)
#define CapSense_BUTTON0_BSLN_COEFF_PARAM_ID                (0x62800041u)

#define CapSense_BUTTON0_IDAC_MOD0_VALUE                    (CapSense_dsRam.wdgtList.button0.idacMod[0u])
#define CapSense_BUTTON0_IDAC_MOD0_OFFSET                   (66u)
#define CapSense_BUTTON0_IDAC_MOD0_SIZE                     (1u)
#define CapSense_BUTTON0_IDAC_MOD0_PARAM_ID                 (0x4E000042u)

#define CapSense_BUTTON0_SNS_CLK_VALUE                      (CapSense_dsRam.wdgtList.button0.snsClk)
#define CapSense_BUTTON0_SNS_CLK_OFFSET                     (67u)
#define CapSense_BUTTON0_SNS_CLK_SIZE                       (1u)
#define CapSense_BUTTON0_SNS_CLK_PARAM_ID                   (0x45800043u)

#define CapSense_BUTTON0_SNS_CLK_SOURCE_VALUE               (CapSense_dsRam.wdgtList.button0.snsClkSource)
#define CapSense_BUTTON0_SNS_CLK_SOURCE_OFFSET              (68u)
#define CapSense_BUTTON0_SNS_CLK_SOURCE_SIZE                (1u)
#define CapSense_BUTTON0_SNS_CLK_SOURCE_PARAM_ID            (0x4E800044u)

#define CapSense_BUTTON0_FINGER_CAP_VALUE                   (CapSense_dsRam.wdgtList.button0.fingerCap)
#define CapSense_BUTTON0_FINGER_CAP_OFFSET                  (70u)
#define CapSense_BUTTON0_FINGER_CAP_SIZE                    (2u)
#define CapSense_BUTTON0_FINGER_CAP_PARAM_ID                (0xAC000046u)

#define CapSense_BUTTON0_SIGPFC_VALUE                       (CapSense_dsRam.wdgtList.button0.sigPFC)
#define CapSense_BUTTON0_SIGPFC_OFFSET                      (72u)
#define CapSense_BUTTON0_SIGPFC_SIZE                        (2u)
#define CapSense_BUTTON0_SIGPFC_PARAM_ID                    (0xA3000048u)

#define CapSense_BUTTON1_RESOLUTION_VALUE                   (CapSense_dsRam.wdgtList.button1.resolution)
#define CapSense_BUTTON1_RESOLUTION_OFFSET                  (74u)
#define CapSense_BUTTON1_RESOLUTION_SIZE                    (2u)
#define CapSense_BUTTON1_RESOLUTION_PARAM_ID                (0x8A81004Au)

#define CapSense_BUTTON1_FINGER_TH_VALUE                    (CapSense_dsRam.wdgtList.button1.fingerTh)
#define CapSense_BUTTON1_FINGER_TH_OFFSET                   (76u)
#define CapSense_BUTTON1_FINGER_TH_SIZE                     (2u)
#define CapSense_BUTTON1_FINGER_TH_PARAM_ID                 (0x8781004Cu)

#define CapSense_BUTTON1_NOISE_TH_VALUE                     (CapSense_dsRam.wdgtList.button1.noiseTh)
#define CapSense_BUTTON1_NOISE_TH_OFFSET                    (78u)
#define CapSense_BUTTON1_NOISE_TH_SIZE                      (1u)
#define CapSense_BUTTON1_NOISE_TH_PARAM_ID                  (0x4381004Eu)

#define CapSense_BUTTON1_NNOISE_TH_VALUE                    (CapSense_dsRam.wdgtList.button1.nNoiseTh)
#define CapSense_BUTTON1_NNOISE_TH_OFFSET                   (79u)
#define CapSense_BUTTON1_NNOISE_TH_SIZE                     (1u)
#define CapSense_BUTTON1_NNOISE_TH_PARAM_ID                 (0x4581004Fu)

#define CapSense_BUTTON1_HYSTERESIS_VALUE                   (CapSense_dsRam.wdgtList.button1.hysteresis)
#define CapSense_BUTTON1_HYSTERESIS_OFFSET                  (80u)
#define CapSense_BUTTON1_HYSTERESIS_SIZE                    (1u)
#define CapSense_BUTTON1_HYSTERESIS_PARAM_ID                (0x49810050u)

#define CapSense_BUTTON1_ON_DEBOUNCE_VALUE                  (CapSense_dsRam.wdgtList.button1.onDebounce)
#define CapSense_BUTTON1_ON_DEBOUNCE_OFFSET                 (81u)
#define CapSense_BUTTON1_ON_DEBOUNCE_SIZE                   (1u)
#define CapSense_BUTTON1_ON_DEBOUNCE_PARAM_ID               (0x4F810051u)

#define CapSense_BUTTON1_LOW_BSLN_RST_VALUE                 (CapSense_dsRam.wdgtList.button1.lowBslnRst)
#define CapSense_BUTTON1_LOW_BSLN_RST_OFFSET                (82u)
#define CapSense_BUTTON1_LOW_BSLN_RST_SIZE                  (1u)
#define CapSense_BUTTON1_LOW_BSLN_RST_PARAM_ID              (0x45810052u)

#define CapSense_BUTTON1_BSLN_COEFF_VALUE                   (CapSense_dsRam.wdgtList.button1.bslnCoeff)
#define CapSense_BUTTON1_BSLN_COEFF_OFFSET                  (83u)
#define CapSense_BUTTON1_BSLN_COEFF_SIZE                    (1u)
#define CapSense_BUTTON1_BSLN_COEFF_PARAM_ID                (0x68810053u)

#define CapSense_BUTTON1_IDAC_MOD0_VALUE                    (CapSense_dsRam.wdgtList.button1.idacMod[0u])
#define CapSense_BUTTON1_IDAC_MOD0_OFFSET                   (84u)
#define CapSense_BUTTON1_IDAC_MOD0_SIZE                     (1u)
#define CapSense_BUTTON1_IDAC_MOD0_PARAM_ID                 (0x45010054u)

#define CapSense_BUTTON1_SNS_CLK_VALUE                      (CapSense_dsRam.wdgtList.button1.snsClk)
#define CapSense_BUTTON1_SNS_CLK_OFFSET                     (85u)
#define CapSense_BUTTON1_SNS_CLK_SIZE                       (1u)
#define CapSense_BUTTON1_SNS_CLK_PARAM_ID                   (0x4E810055u)

#define CapSense_BUTTON1_SNS_CLK_SOURCE_VALUE               (CapSense_dsRam.wdgtList.button1.snsClkSource)
#define CapSense_BUTTON1_SNS_CLK_SOURCE_OFFSET              (86u)
#define CapSense_BUTTON1_SNS_CLK_SOURCE_SIZE                (1u)
#define CapSense_BUTTON1_SNS_CLK_SOURCE_PARAM_ID            (0x44810056u)

#define CapSense_BUTTON1_FINGER_CAP_VALUE                   (CapSense_dsRam.wdgtList.button1.fingerCap)
#define CapSense_BUTTON1_FINGER_CAP_OFFSET                  (88u)
#define CapSense_BUTTON1_FINGER_CAP_SIZE                    (2u)
#define CapSense_BUTTON1_FINGER_CAP_PARAM_ID                (0xA5010058u)

#define CapSense_BUTTON1_SIGPFC_VALUE                       (CapSense_dsRam.wdgtList.button1.sigPFC)
#define CapSense_BUTTON1_SIGPFC_OFFSET                      (90u)
#define CapSense_BUTTON1_SIGPFC_SIZE                        (2u)
#define CapSense_BUTTON1_SIGPFC_PARAM_ID                    (0xA901005Au)

#define CapSense_BUTTON2_RESOLUTION_VALUE                   (CapSense_dsRam.wdgtList.button2.resolution)
#define CapSense_BUTTON2_RESOLUTION_OFFSET                  (92u)
#define CapSense_BUTTON2_RESOLUTION_SIZE                    (2u)
#define CapSense_BUTTON2_RESOLUTION_PARAM_ID                (0x8782005Cu)

#define CapSense_BUTTON2_FINGER_TH_VALUE                    (CapSense_dsRam.wdgtList.button2.fingerTh)
#define CapSense_BUTTON2_FINGER_TH_OFFSET                   (94u)
#define CapSense_BUTTON2_FINGER_TH_SIZE                     (2u)
#define CapSense_BUTTON2_FINGER_TH_PARAM_ID                 (0x8B82005Eu)

#define CapSense_BUTTON2_NOISE_TH_VALUE                     (CapSense_dsRam.wdgtList.button2.noiseTh)
#define CapSense_BUTTON2_NOISE_TH_OFFSET                    (96u)
#define CapSense_BUTTON2_NOISE_TH_SIZE                      (1u)
#define CapSense_BUTTON2_NOISE_TH_PARAM_ID                  (0x43820060u)

#define CapSense_BUTTON2_NNOISE_TH_VALUE                    (CapSense_dsRam.wdgtList.button2.nNoiseTh)
#define CapSense_BUTTON2_NNOISE_TH_OFFSET                   (97u)
#define CapSense_BUTTON2_NNOISE_TH_SIZE                     (1u)
#define CapSense_BUTTON2_NNOISE_TH_PARAM_ID                 (0x45820061u)

#define CapSense_BUTTON2_HYSTERESIS_VALUE                   (CapSense_dsRam.wdgtList.button2.hysteresis)
#define CapSense_BUTTON2_HYSTERESIS_OFFSET                  (98u)
#define CapSense_BUTTON2_HYSTERESIS_SIZE                    (1u)
#define CapSense_BUTTON2_HYSTERESIS_PARAM_ID                (0x4F820062u)

#define CapSense_BUTTON2_ON_DEBOUNCE_VALUE                  (CapSense_dsRam.wdgtList.button2.onDebounce)
#define CapSense_BUTTON2_ON_DEBOUNCE_OFFSET                 (99u)
#define CapSense_BUTTON2_ON_DEBOUNCE_SIZE                   (1u)
#define CapSense_BUTTON2_ON_DEBOUNCE_PARAM_ID               (0x49820063u)

#define CapSense_BUTTON2_LOW_BSLN_RST_VALUE                 (CapSense_dsRam.wdgtList.button2.lowBslnRst)
#define CapSense_BUTTON2_LOW_BSLN_RST_OFFSET                (100u)
#define CapSense_BUTTON2_LOW_BSLN_RST_SIZE                  (1u)
#define CapSense_BUTTON2_LOW_BSLN_RST_PARAM_ID              (0x42820064u)

#define CapSense_BUTTON2_BSLN_COEFF_VALUE                   (CapSense_dsRam.wdgtList.button2.bslnCoeff)
#define CapSense_BUTTON2_BSLN_COEFF_OFFSET                  (101u)
#define CapSense_BUTTON2_BSLN_COEFF_SIZE                    (1u)
#define CapSense_BUTTON2_BSLN_COEFF_PARAM_ID                (0x6F820065u)

#define CapSense_BUTTON2_IDAC_MOD0_VALUE                    (CapSense_dsRam.wdgtList.button2.idacMod[0u])
#define CapSense_BUTTON2_IDAC_MOD0_OFFSET                   (102u)
#define CapSense_BUTTON2_IDAC_MOD0_SIZE                     (1u)
#define CapSense_BUTTON2_IDAC_MOD0_PARAM_ID                 (0x43020066u)

#define CapSense_BUTTON2_SNS_CLK_VALUE                      (CapSense_dsRam.wdgtList.button2.snsClk)
#define CapSense_BUTTON2_SNS_CLK_OFFSET                     (103u)
#define CapSense_BUTTON2_SNS_CLK_SIZE                       (1u)
#define CapSense_BUTTON2_SNS_CLK_PARAM_ID                   (0x48820067u)

#define CapSense_BUTTON2_SNS_CLK_SOURCE_VALUE               (CapSense_dsRam.wdgtList.button2.snsClkSource)
#define CapSense_BUTTON2_SNS_CLK_SOURCE_OFFSET              (104u)
#define CapSense_BUTTON2_SNS_CLK_SOURCE_SIZE                (1u)
#define CapSense_BUTTON2_SNS_CLK_SOURCE_PARAM_ID            (0x41820068u)

#define CapSense_BUTTON2_FINGER_CAP_VALUE                   (CapSense_dsRam.wdgtList.button2.fingerCap)
#define CapSense_BUTTON2_FINGER_CAP_OFFSET                  (106u)
#define CapSense_BUTTON2_FINGER_CAP_SIZE                    (2u)
#define CapSense_BUTTON2_FINGER_CAP_PARAM_ID                (0xA302006Au)

#define CapSense_BUTTON2_SIGPFC_VALUE                       (CapSense_dsRam.wdgtList.button2.sigPFC)
#define CapSense_BUTTON2_SIGPFC_OFFSET                      (108u)
#define CapSense_BUTTON2_SIGPFC_SIZE                        (2u)
#define CapSense_BUTTON2_SIGPFC_PARAM_ID                    (0xAE02006Cu)

#define CapSense_BUTTON3_RESOLUTION_VALUE                   (CapSense_dsRam.wdgtList.button3.resolution)
#define CapSense_BUTTON3_RESOLUTION_OFFSET                  (110u)
#define CapSense_BUTTON3_RESOLUTION_SIZE                    (2u)
#define CapSense_BUTTON3_RESOLUTION_PARAM_ID                (0x8783006Eu)

#define CapSense_BUTTON3_FINGER_TH_VALUE                    (CapSense_dsRam.wdgtList.button3.fingerTh)
#define CapSense_BUTTON3_FINGER_TH_OFFSET                   (112u)
#define CapSense_BUTTON3_FINGER_TH_SIZE                     (2u)
#define CapSense_BUTTON3_FINGER_TH_PARAM_ID                 (0x8D830070u)

#define CapSense_BUTTON3_NOISE_TH_VALUE                     (CapSense_dsRam.wdgtList.button3.noiseTh)
#define CapSense_BUTTON3_NOISE_TH_OFFSET                    (114u)
#define CapSense_BUTTON3_NOISE_TH_SIZE                      (1u)
#define CapSense_BUTTON3_NOISE_TH_PARAM_ID                  (0x49830072u)

#define CapSense_BUTTON3_NNOISE_TH_VALUE                    (CapSense_dsRam.wdgtList.button3.nNoiseTh)
#define CapSense_BUTTON3_NNOISE_TH_OFFSET                   (115u)
#define CapSense_BUTTON3_NNOISE_TH_SIZE                     (1u)
#define CapSense_BUTTON3_NNOISE_TH_PARAM_ID                 (0x4F830073u)

#define CapSense_BUTTON3_HYSTERESIS_VALUE                   (CapSense_dsRam.wdgtList.button3.hysteresis)
#define CapSense_BUTTON3_HYSTERESIS_OFFSET                  (116u)
#define CapSense_BUTTON3_HYSTERESIS_SIZE                    (1u)
#define CapSense_BUTTON3_HYSTERESIS_PARAM_ID                (0x44830074u)

#define CapSense_BUTTON3_ON_DEBOUNCE_VALUE                  (CapSense_dsRam.wdgtList.button3.onDebounce)
#define CapSense_BUTTON3_ON_DEBOUNCE_OFFSET                 (117u)
#define CapSense_BUTTON3_ON_DEBOUNCE_SIZE                   (1u)
#define CapSense_BUTTON3_ON_DEBOUNCE_PARAM_ID               (0x42830075u)

#define CapSense_BUTTON3_LOW_BSLN_RST_VALUE                 (CapSense_dsRam.wdgtList.button3.lowBslnRst)
#define CapSense_BUTTON3_LOW_BSLN_RST_OFFSET                (118u)
#define CapSense_BUTTON3_LOW_BSLN_RST_SIZE                  (1u)
#define CapSense_BUTTON3_LOW_BSLN_RST_PARAM_ID              (0x48830076u)

#define CapSense_BUTTON3_BSLN_COEFF_VALUE                   (CapSense_dsRam.wdgtList.button3.bslnCoeff)
#define CapSense_BUTTON3_BSLN_COEFF_OFFSET                  (119u)
#define CapSense_BUTTON3_BSLN_COEFF_SIZE                    (1u)
#define CapSense_BUTTON3_BSLN_COEFF_PARAM_ID                (0x65830077u)

#define CapSense_BUTTON3_IDAC_MOD0_VALUE                    (CapSense_dsRam.wdgtList.button3.idacMod[0u])
#define CapSense_BUTTON3_IDAC_MOD0_OFFSET                   (120u)
#define CapSense_BUTTON3_IDAC_MOD0_SIZE                     (1u)
#define CapSense_BUTTON3_IDAC_MOD0_PARAM_ID                 (0x4A030078u)

#define CapSense_BUTTON3_SNS_CLK_VALUE                      (CapSense_dsRam.wdgtList.button3.snsClk)
#define CapSense_BUTTON3_SNS_CLK_OFFSET                     (121u)
#define CapSense_BUTTON3_SNS_CLK_SIZE                       (1u)
#define CapSense_BUTTON3_SNS_CLK_PARAM_ID                   (0x41830079u)

#define CapSense_BUTTON3_SNS_CLK_SOURCE_VALUE               (CapSense_dsRam.wdgtList.button3.snsClkSource)
#define CapSense_BUTTON3_SNS_CLK_SOURCE_OFFSET              (122u)
#define CapSense_BUTTON3_SNS_CLK_SOURCE_SIZE                (1u)
#define CapSense_BUTTON3_SNS_CLK_SOURCE_PARAM_ID            (0x4B83007Au)

#define CapSense_BUTTON3_FINGER_CAP_VALUE                   (CapSense_dsRam.wdgtList.button3.fingerCap)
#define CapSense_BUTTON3_FINGER_CAP_OFFSET                  (124u)
#define CapSense_BUTTON3_FINGER_CAP_SIZE                    (2u)
#define CapSense_BUTTON3_FINGER_CAP_PARAM_ID                (0xA803007Cu)

#define CapSense_BUTTON3_SIGPFC_VALUE                       (CapSense_dsRam.wdgtList.button3.sigPFC)
#define CapSense_BUTTON3_SIGPFC_OFFSET                      (126u)
#define CapSense_BUTTON3_SIGPFC_SIZE                        (2u)
#define CapSense_BUTTON3_SIGPFC_PARAM_ID                    (0xA403007Eu)

#define CapSense_BUTTON4_RESOLUTION_VALUE                   (CapSense_dsRam.wdgtList.button4.resolution)
#define CapSense_BUTTON4_RESOLUTION_OFFSET                  (128u)
#define CapSense_BUTTON4_RESOLUTION_SIZE                    (2u)
#define CapSense_BUTTON4_RESOLUTION_PARAM_ID                (0x85840080u)

#define CapSense_BUTTON4_FINGER_TH_VALUE                    (CapSense_dsRam.wdgtList.button4.fingerTh)
#define CapSense_BUTTON4_FINGER_TH_OFFSET                   (130u)
#define CapSense_BUTTON4_FINGER_TH_SIZE                     (2u)
#define CapSense_BUTTON4_FINGER_TH_PARAM_ID                 (0x89840082u)

#define CapSense_BUTTON4_NOISE_TH_VALUE                     (CapSense_dsRam.wdgtList.button4.noiseTh)
#define CapSense_BUTTON4_NOISE_TH_OFFSET                    (132u)
#define CapSense_BUTTON4_NOISE_TH_SIZE                      (1u)
#define CapSense_BUTTON4_NOISE_TH_PARAM_ID                  (0x4C840084u)

#define CapSense_BUTTON4_NNOISE_TH_VALUE                    (CapSense_dsRam.wdgtList.button4.nNoiseTh)
#define CapSense_BUTTON4_NNOISE_TH_OFFSET                   (133u)
#define CapSense_BUTTON4_NNOISE_TH_SIZE                     (1u)
#define CapSense_BUTTON4_NNOISE_TH_PARAM_ID                 (0x4A840085u)

#define CapSense_BUTTON4_HYSTERESIS_VALUE                   (CapSense_dsRam.wdgtList.button4.hysteresis)
#define CapSense_BUTTON4_HYSTERESIS_OFFSET                  (134u)
#define CapSense_BUTTON4_HYSTERESIS_SIZE                    (1u)
#define CapSense_BUTTON4_HYSTERESIS_PARAM_ID                (0x40840086u)

#define CapSense_BUTTON4_ON_DEBOUNCE_VALUE                  (CapSense_dsRam.wdgtList.button4.onDebounce)
#define CapSense_BUTTON4_ON_DEBOUNCE_OFFSET                 (135u)
#define CapSense_BUTTON4_ON_DEBOUNCE_SIZE                   (1u)
#define CapSense_BUTTON4_ON_DEBOUNCE_PARAM_ID               (0x46840087u)

#define CapSense_BUTTON4_LOW_BSLN_RST_VALUE                 (CapSense_dsRam.wdgtList.button4.lowBslnRst)
#define CapSense_BUTTON4_LOW_BSLN_RST_OFFSET                (136u)
#define CapSense_BUTTON4_LOW_BSLN_RST_SIZE                  (1u)
#define CapSense_BUTTON4_LOW_BSLN_RST_PARAM_ID              (0x4F840088u)

#define CapSense_BUTTON4_BSLN_COEFF_VALUE                   (CapSense_dsRam.wdgtList.button4.bslnCoeff)
#define CapSense_BUTTON4_BSLN_COEFF_OFFSET                  (137u)
#define CapSense_BUTTON4_BSLN_COEFF_SIZE                    (1u)
#define CapSense_BUTTON4_BSLN_COEFF_PARAM_ID                (0x62840089u)

#define CapSense_BUTTON4_IDAC_MOD0_VALUE                    (CapSense_dsRam.wdgtList.button4.idacMod[0u])
#define CapSense_BUTTON4_IDAC_MOD0_OFFSET                   (138u)
#define CapSense_BUTTON4_IDAC_MOD0_SIZE                     (1u)
#define CapSense_BUTTON4_IDAC_MOD0_PARAM_ID                 (0x4E04008Au)

#define CapSense_BUTTON4_SNS_CLK_VALUE                      (CapSense_dsRam.wdgtList.button4.snsClk)
#define CapSense_BUTTON4_SNS_CLK_OFFSET                     (139u)
#define CapSense_BUTTON4_SNS_CLK_SIZE                       (1u)
#define CapSense_BUTTON4_SNS_CLK_PARAM_ID                   (0x4584008Bu)

#define CapSense_BUTTON4_SNS_CLK_SOURCE_VALUE               (CapSense_dsRam.wdgtList.button4.snsClkSource)
#define CapSense_BUTTON4_SNS_CLK_SOURCE_OFFSET              (140u)
#define CapSense_BUTTON4_SNS_CLK_SOURCE_SIZE                (1u)
#define CapSense_BUTTON4_SNS_CLK_SOURCE_PARAM_ID            (0x4E84008Cu)

#define CapSense_BUTTON4_FINGER_CAP_VALUE                   (CapSense_dsRam.wdgtList.button4.fingerCap)
#define CapSense_BUTTON4_FINGER_CAP_OFFSET                  (142u)
#define CapSense_BUTTON4_FINGER_CAP_SIZE                    (2u)
#define CapSense_BUTTON4_FINGER_CAP_PARAM_ID                (0xAC04008Eu)

#define CapSense_BUTTON4_SIGPFC_VALUE                       (CapSense_dsRam.wdgtList.button4.sigPFC)
#define CapSense_BUTTON4_SIGPFC_OFFSET                      (144u)
#define CapSense_BUTTON4_SIGPFC_SIZE                        (2u)
#define CapSense_BUTTON4_SIGPFC_PARAM_ID                    (0xA6040090u)

#define CapSense_BUTTON5_RESOLUTION_VALUE                   (CapSense_dsRam.wdgtList.button5.resolution)
#define CapSense_BUTTON5_RESOLUTION_OFFSET                  (146u)
#define CapSense_BUTTON5_RESOLUTION_SIZE                    (2u)
#define CapSense_BUTTON5_RESOLUTION_PARAM_ID                (0x8F850092u)

#define CapSense_BUTTON5_FINGER_TH_VALUE                    (CapSense_dsRam.wdgtList.button5.fingerTh)
#define CapSense_BUTTON5_FINGER_TH_OFFSET                   (148u)
#define CapSense_BUTTON5_FINGER_TH_SIZE                     (2u)
#define CapSense_BUTTON5_FINGER_TH_PARAM_ID                 (0x82850094u)

#define CapSense_BUTTON5_NOISE_TH_VALUE                     (CapSense_dsRam.wdgtList.button5.noiseTh)
#define CapSense_BUTTON5_NOISE_TH_OFFSET                    (150u)
#define CapSense_BUTTON5_NOISE_TH_SIZE                      (1u)
#define CapSense_BUTTON5_NOISE_TH_PARAM_ID                  (0x46850096u)

#define CapSense_BUTTON5_NNOISE_TH_VALUE                    (CapSense_dsRam.wdgtList.button5.nNoiseTh)
#define CapSense_BUTTON5_NNOISE_TH_OFFSET                   (151u)
#define CapSense_BUTTON5_NNOISE_TH_SIZE                     (1u)
#define CapSense_BUTTON5_NNOISE_TH_PARAM_ID                 (0x40850097u)

#define CapSense_BUTTON5_HYSTERESIS_VALUE                   (CapSense_dsRam.wdgtList.button5.hysteresis)
#define CapSense_BUTTON5_HYSTERESIS_OFFSET                  (152u)
#define CapSense_BUTTON5_HYSTERESIS_SIZE                    (1u)
#define CapSense_BUTTON5_HYSTERESIS_PARAM_ID                (0x49850098u)

#define CapSense_BUTTON5_ON_DEBOUNCE_VALUE                  (CapSense_dsRam.wdgtList.button5.onDebounce)
#define CapSense_BUTTON5_ON_DEBOUNCE_OFFSET                 (153u)
#define CapSense_BUTTON5_ON_DEBOUNCE_SIZE                   (1u)
#define CapSense_BUTTON5_ON_DEBOUNCE_PARAM_ID               (0x4F850099u)

#define CapSense_BUTTON5_LOW_BSLN_RST_VALUE                 (CapSense_dsRam.wdgtList.button5.lowBslnRst)
#define CapSense_BUTTON5_LOW_BSLN_RST_OFFSET                (154u)
#define CapSense_BUTTON5_LOW_BSLN_RST_SIZE                  (1u)
#define CapSense_BUTTON5_LOW_BSLN_RST_PARAM_ID              (0x4585009Au)

#define CapSense_BUTTON5_BSLN_COEFF_VALUE                   (CapSense_dsRam.wdgtList.button5.bslnCoeff)
#define CapSense_BUTTON5_BSLN_COEFF_OFFSET                  (155u)
#define CapSense_BUTTON5_BSLN_COEFF_SIZE                    (1u)
#define CapSense_BUTTON5_BSLN_COEFF_PARAM_ID                (0x6885009Bu)

#define CapSense_BUTTON5_IDAC_MOD0_VALUE                    (CapSense_dsRam.wdgtList.button5.idacMod[0u])
#define CapSense_BUTTON5_IDAC_MOD0_OFFSET                   (156u)
#define CapSense_BUTTON5_IDAC_MOD0_SIZE                     (1u)
#define CapSense_BUTTON5_IDAC_MOD0_PARAM_ID                 (0x4505009Cu)

#define CapSense_BUTTON5_SNS_CLK_VALUE                      (CapSense_dsRam.wdgtList.button5.snsClk)
#define CapSense_BUTTON5_SNS_CLK_OFFSET                     (157u)
#define CapSense_BUTTON5_SNS_CLK_SIZE                       (1u)
#define CapSense_BUTTON5_SNS_CLK_PARAM_ID                   (0x4E85009Du)

#define CapSense_BUTTON5_SNS_CLK_SOURCE_VALUE               (CapSense_dsRam.wdgtList.button5.snsClkSource)
#define CapSense_BUTTON5_SNS_CLK_SOURCE_OFFSET              (158u)
#define CapSense_BUTTON5_SNS_CLK_SOURCE_SIZE                (1u)
#define CapSense_BUTTON5_SNS_CLK_SOURCE_PARAM_ID            (0x4485009Eu)

#define CapSense_BUTTON5_FINGER_CAP_VALUE                   (CapSense_dsRam.wdgtList.button5.fingerCap)
#define CapSense_BUTTON5_FINGER_CAP_OFFSET                  (160u)
#define CapSense_BUTTON5_FINGER_CAP_SIZE                    (2u)
#define CapSense_BUTTON5_FINGER_CAP_PARAM_ID                (0xAA0500A0u)

#define CapSense_BUTTON5_SIGPFC_VALUE                       (CapSense_dsRam.wdgtList.button5.sigPFC)
#define CapSense_BUTTON5_SIGPFC_OFFSET                      (162u)
#define CapSense_BUTTON5_SIGPFC_SIZE                        (2u)
#define CapSense_BUTTON5_SIGPFC_PARAM_ID                    (0xA60500A2u)

#define CapSense_BUTTON6_RESOLUTION_VALUE                   (CapSense_dsRam.wdgtList.button6.resolution)
#define CapSense_BUTTON6_RESOLUTION_OFFSET                  (164u)
#define CapSense_BUTTON6_RESOLUTION_SIZE                    (2u)
#define CapSense_BUTTON6_RESOLUTION_PARAM_ID                (0x888600A4u)

#define CapSense_BUTTON6_FINGER_TH_VALUE                    (CapSense_dsRam.wdgtList.button6.fingerTh)
#define CapSense_BUTTON6_FINGER_TH_OFFSET                   (166u)
#define CapSense_BUTTON6_FINGER_TH_SIZE                     (2u)
#define CapSense_BUTTON6_FINGER_TH_PARAM_ID                 (0x848600A6u)

#define CapSense_BUTTON6_NOISE_TH_VALUE                     (CapSense_dsRam.wdgtList.button6.noiseTh)
#define CapSense_BUTTON6_NOISE_TH_OFFSET                    (168u)
#define CapSense_BUTTON6_NOISE_TH_SIZE                      (1u)
#define CapSense_BUTTON6_NOISE_TH_PARAM_ID                  (0x438600A8u)

#define CapSense_BUTTON6_NNOISE_TH_VALUE                    (CapSense_dsRam.wdgtList.button6.nNoiseTh)
#define CapSense_BUTTON6_NNOISE_TH_OFFSET                   (169u)
#define CapSense_BUTTON6_NNOISE_TH_SIZE                     (1u)
#define CapSense_BUTTON6_NNOISE_TH_PARAM_ID                 (0x458600A9u)

#define CapSense_BUTTON6_HYSTERESIS_VALUE                   (CapSense_dsRam.wdgtList.button6.hysteresis)
#define CapSense_BUTTON6_HYSTERESIS_OFFSET                  (170u)
#define CapSense_BUTTON6_HYSTERESIS_SIZE                    (1u)
#define CapSense_BUTTON6_HYSTERESIS_PARAM_ID                (0x4F8600AAu)

#define CapSense_BUTTON6_ON_DEBOUNCE_VALUE                  (CapSense_dsRam.wdgtList.button6.onDebounce)
#define CapSense_BUTTON6_ON_DEBOUNCE_OFFSET                 (171u)
#define CapSense_BUTTON6_ON_DEBOUNCE_SIZE                   (1u)
#define CapSense_BUTTON6_ON_DEBOUNCE_PARAM_ID               (0x498600ABu)

#define CapSense_BUTTON6_LOW_BSLN_RST_VALUE                 (CapSense_dsRam.wdgtList.button6.lowBslnRst)
#define CapSense_BUTTON6_LOW_BSLN_RST_OFFSET                (172u)
#define CapSense_BUTTON6_LOW_BSLN_RST_SIZE                  (1u)
#define CapSense_BUTTON6_LOW_BSLN_RST_PARAM_ID              (0x428600ACu)

#define CapSense_BUTTON6_BSLN_COEFF_VALUE                   (CapSense_dsRam.wdgtList.button6.bslnCoeff)
#define CapSense_BUTTON6_BSLN_COEFF_OFFSET                  (173u)
#define CapSense_BUTTON6_BSLN_COEFF_SIZE                    (1u)
#define CapSense_BUTTON6_BSLN_COEFF_PARAM_ID                (0x6F8600ADu)

#define CapSense_BUTTON6_IDAC_MOD0_VALUE                    (CapSense_dsRam.wdgtList.button6.idacMod[0u])
#define CapSense_BUTTON6_IDAC_MOD0_OFFSET                   (174u)
#define CapSense_BUTTON6_IDAC_MOD0_SIZE                     (1u)
#define CapSense_BUTTON6_IDAC_MOD0_PARAM_ID                 (0x430600AEu)

#define CapSense_BUTTON6_SNS_CLK_VALUE                      (CapSense_dsRam.wdgtList.button6.snsClk)
#define CapSense_BUTTON6_SNS_CLK_OFFSET                     (175u)
#define CapSense_BUTTON6_SNS_CLK_SIZE                       (1u)
#define CapSense_BUTTON6_SNS_CLK_PARAM_ID                   (0x488600AFu)

#define CapSense_BUTTON6_SNS_CLK_SOURCE_VALUE               (CapSense_dsRam.wdgtList.button6.snsClkSource)
#define CapSense_BUTTON6_SNS_CLK_SOURCE_OFFSET              (176u)
#define CapSense_BUTTON6_SNS_CLK_SOURCE_SIZE                (1u)
#define CapSense_BUTTON6_SNS_CLK_SOURCE_PARAM_ID            (0x448600B0u)

#define CapSense_BUTTON6_FINGER_CAP_VALUE                   (CapSense_dsRam.wdgtList.button6.fingerCap)
#define CapSense_BUTTON6_FINGER_CAP_OFFSET                  (178u)
#define CapSense_BUTTON6_FINGER_CAP_SIZE                    (2u)
#define CapSense_BUTTON6_FINGER_CAP_PARAM_ID                (0xA60600B2u)

#define CapSense_BUTTON6_SIGPFC_VALUE                       (CapSense_dsRam.wdgtList.button6.sigPFC)
#define CapSense_BUTTON6_SIGPFC_OFFSET                      (180u)
#define CapSense_BUTTON6_SIGPFC_SIZE                        (2u)
#define CapSense_BUTTON6_SIGPFC_PARAM_ID                    (0xAB0600B4u)

#define CapSense_BUTTON7_RESOLUTION_VALUE                   (CapSense_dsRam.wdgtList.button7.resolution)
#define CapSense_BUTTON7_RESOLUTION_OFFSET                  (182u)
#define CapSense_BUTTON7_RESOLUTION_SIZE                    (2u)
#define CapSense_BUTTON7_RESOLUTION_PARAM_ID                (0x828700B6u)

#define CapSense_BUTTON7_FINGER_TH_VALUE                    (CapSense_dsRam.wdgtList.button7.fingerTh)
#define CapSense_BUTTON7_FINGER_TH_OFFSET                   (184u)
#define CapSense_BUTTON7_FINGER_TH_SIZE                     (2u)
#define CapSense_BUTTON7_FINGER_TH_PARAM_ID                 (0x8D8700B8u)

#define CapSense_BUTTON7_NOISE_TH_VALUE                     (CapSense_dsRam.wdgtList.button7.noiseTh)
#define CapSense_BUTTON7_NOISE_TH_OFFSET                    (186u)
#define CapSense_BUTTON7_NOISE_TH_SIZE                      (1u)
#define CapSense_BUTTON7_NOISE_TH_PARAM_ID                  (0x498700BAu)

#define CapSense_BUTTON7_NNOISE_TH_VALUE                    (CapSense_dsRam.wdgtList.button7.nNoiseTh)
#define CapSense_BUTTON7_NNOISE_TH_OFFSET                   (187u)
#define CapSense_BUTTON7_NNOISE_TH_SIZE                     (1u)
#define CapSense_BUTTON7_NNOISE_TH_PARAM_ID                 (0x4F8700BBu)

#define CapSense_BUTTON7_HYSTERESIS_VALUE                   (CapSense_dsRam.wdgtList.button7.hysteresis)
#define CapSense_BUTTON7_HYSTERESIS_OFFSET                  (188u)
#define CapSense_BUTTON7_HYSTERESIS_SIZE                    (1u)
#define CapSense_BUTTON7_HYSTERESIS_PARAM_ID                (0x448700BCu)

#define CapSense_BUTTON7_ON_DEBOUNCE_VALUE                  (CapSense_dsRam.wdgtList.button7.onDebounce)
#define CapSense_BUTTON7_ON_DEBOUNCE_OFFSET                 (189u)
#define CapSense_BUTTON7_ON_DEBOUNCE_SIZE                   (1u)
#define CapSense_BUTTON7_ON_DEBOUNCE_PARAM_ID               (0x428700BDu)

#define CapSense_BUTTON7_LOW_BSLN_RST_VALUE                 (CapSense_dsRam.wdgtList.button7.lowBslnRst)
#define CapSense_BUTTON7_LOW_BSLN_RST_OFFSET                (190u)
#define CapSense_BUTTON7_LOW_BSLN_RST_SIZE                  (1u)
#define CapSense_BUTTON7_LOW_BSLN_RST_PARAM_ID              (0x488700BEu)

#define CapSense_BUTTON7_BSLN_COEFF_VALUE                   (CapSense_dsRam.wdgtList.button7.bslnCoeff)
#define CapSense_BUTTON7_BSLN_COEFF_OFFSET                  (191u)
#define CapSense_BUTTON7_BSLN_COEFF_SIZE                    (1u)
#define CapSense_BUTTON7_BSLN_COEFF_PARAM_ID                (0x658700BFu)

#define CapSense_BUTTON7_IDAC_MOD0_VALUE                    (CapSense_dsRam.wdgtList.button7.idacMod[0u])
#define CapSense_BUTTON7_IDAC_MOD0_OFFSET                   (192u)
#define CapSense_BUTTON7_IDAC_MOD0_SIZE                     (1u)
#define CapSense_BUTTON7_IDAC_MOD0_PARAM_ID                 (0x480700C0u)

#define CapSense_BUTTON7_SNS_CLK_VALUE                      (CapSense_dsRam.wdgtList.button7.snsClk)
#define CapSense_BUTTON7_SNS_CLK_OFFSET                     (193u)
#define CapSense_BUTTON7_SNS_CLK_SIZE                       (1u)
#define CapSense_BUTTON7_SNS_CLK_PARAM_ID                   (0x438700C1u)

#define CapSense_BUTTON7_SNS_CLK_SOURCE_VALUE               (CapSense_dsRam.wdgtList.button7.snsClkSource)
#define CapSense_BUTTON7_SNS_CLK_SOURCE_OFFSET              (194u)
#define CapSense_BUTTON7_SNS_CLK_SOURCE_SIZE                (1u)
#define CapSense_BUTTON7_SNS_CLK_SOURCE_PARAM_ID            (0x498700C2u)

#define CapSense_BUTTON7_FINGER_CAP_VALUE                   (CapSense_dsRam.wdgtList.button7.fingerCap)
#define CapSense_BUTTON7_FINGER_CAP_OFFSET                  (196u)
#define CapSense_BUTTON7_FINGER_CAP_SIZE                    (2u)
#define CapSense_BUTTON7_FINGER_CAP_PARAM_ID                (0xAA0700C4u)

#define CapSense_BUTTON7_SIGPFC_VALUE                       (CapSense_dsRam.wdgtList.button7.sigPFC)
#define CapSense_BUTTON7_SIGPFC_OFFSET                      (198u)
#define CapSense_BUTTON7_SIGPFC_SIZE                        (2u)
#define CapSense_BUTTON7_SIGPFC_PARAM_ID                    (0xA60700C6u)

#define CapSense_BUTTON8_RESOLUTION_VALUE                   (CapSense_dsRam.wdgtList.button8.resolution)
#define CapSense_BUTTON8_RESOLUTION_OFFSET                  (200u)
#define CapSense_BUTTON8_RESOLUTION_SIZE                    (2u)
#define CapSense_BUTTON8_RESOLUTION_PARAM_ID                (0x878800C8u)

#define CapSense_BUTTON8_FINGER_TH_VALUE                    (CapSense_dsRam.wdgtList.button8.fingerTh)
#define CapSense_BUTTON8_FINGER_TH_OFFSET                   (202u)
#define CapSense_BUTTON8_FINGER_TH_SIZE                     (2u)
#define CapSense_BUTTON8_FINGER_TH_PARAM_ID                 (0x8B8800CAu)

#define CapSense_BUTTON8_NOISE_TH_VALUE                     (CapSense_dsRam.wdgtList.button8.noiseTh)
#define CapSense_BUTTON8_NOISE_TH_OFFSET                    (204u)
#define CapSense_BUTTON8_NOISE_TH_SIZE                      (1u)
#define CapSense_BUTTON8_NOISE_TH_PARAM_ID                  (0x4E8800CCu)

#define CapSense_BUTTON8_NNOISE_TH_VALUE                    (CapSense_dsRam.wdgtList.button8.nNoiseTh)
#define CapSense_BUTTON8_NNOISE_TH_OFFSET                   (205u)
#define CapSense_BUTTON8_NNOISE_TH_SIZE                     (1u)
#define CapSense_BUTTON8_NNOISE_TH_PARAM_ID                 (0x488800CDu)

#define CapSense_BUTTON8_HYSTERESIS_VALUE                   (CapSense_dsRam.wdgtList.button8.hysteresis)
#define CapSense_BUTTON8_HYSTERESIS_OFFSET                  (206u)
#define CapSense_BUTTON8_HYSTERESIS_SIZE                    (1u)
#define CapSense_BUTTON8_HYSTERESIS_PARAM_ID                (0x428800CEu)

#define CapSense_BUTTON8_ON_DEBOUNCE_VALUE                  (CapSense_dsRam.wdgtList.button8.onDebounce)
#define CapSense_BUTTON8_ON_DEBOUNCE_OFFSET                 (207u)
#define CapSense_BUTTON8_ON_DEBOUNCE_SIZE                   (1u)
#define CapSense_BUTTON8_ON_DEBOUNCE_PARAM_ID               (0x448800CFu)

#define CapSense_BUTTON8_LOW_BSLN_RST_VALUE                 (CapSense_dsRam.wdgtList.button8.lowBslnRst)
#define CapSense_BUTTON8_LOW_BSLN_RST_OFFSET                (208u)
#define CapSense_BUTTON8_LOW_BSLN_RST_SIZE                  (1u)
#define CapSense_BUTTON8_LOW_BSLN_RST_PARAM_ID              (0x488800D0u)

#define CapSense_BUTTON8_BSLN_COEFF_VALUE                   (CapSense_dsRam.wdgtList.button8.bslnCoeff)
#define CapSense_BUTTON8_BSLN_COEFF_OFFSET                  (209u)
#define CapSense_BUTTON8_BSLN_COEFF_SIZE                    (1u)
#define CapSense_BUTTON8_BSLN_COEFF_PARAM_ID                (0x658800D1u)

#define CapSense_BUTTON8_IDAC_MOD0_VALUE                    (CapSense_dsRam.wdgtList.button8.idacMod[0u])
#define CapSense_BUTTON8_IDAC_MOD0_OFFSET                   (210u)
#define CapSense_BUTTON8_IDAC_MOD0_SIZE                     (1u)
#define CapSense_BUTTON8_IDAC_MOD0_PARAM_ID                 (0x490800D2u)

#define CapSense_BUTTON8_SNS_CLK_VALUE                      (CapSense_dsRam.wdgtList.button8.snsClk)
#define CapSense_BUTTON8_SNS_CLK_OFFSET                     (211u)
#define CapSense_BUTTON8_SNS_CLK_SIZE                       (1u)
#define CapSense_BUTTON8_SNS_CLK_PARAM_ID                   (0x428800D3u)

#define CapSense_BUTTON8_SNS_CLK_SOURCE_VALUE               (CapSense_dsRam.wdgtList.button8.snsClkSource)
#define CapSense_BUTTON8_SNS_CLK_SOURCE_OFFSET              (212u)
#define CapSense_BUTTON8_SNS_CLK_SOURCE_SIZE                (1u)
#define CapSense_BUTTON8_SNS_CLK_SOURCE_PARAM_ID            (0x498800D4u)

#define CapSense_BUTTON8_FINGER_CAP_VALUE                   (CapSense_dsRam.wdgtList.button8.fingerCap)
#define CapSense_BUTTON8_FINGER_CAP_OFFSET                  (214u)
#define CapSense_BUTTON8_FINGER_CAP_SIZE                    (2u)
#define CapSense_BUTTON8_FINGER_CAP_PARAM_ID                (0xAB0800D6u)

#define CapSense_BUTTON8_SIGPFC_VALUE                       (CapSense_dsRam.wdgtList.button8.sigPFC)
#define CapSense_BUTTON8_SIGPFC_OFFSET                      (216u)
#define CapSense_BUTTON8_SIGPFC_SIZE                        (2u)
#define CapSense_BUTTON8_SIGPFC_PARAM_ID                    (0xA40800D8u)

#define CapSense_BUTTON9_RESOLUTION_VALUE                   (CapSense_dsRam.wdgtList.button9.resolution)
#define CapSense_BUTTON9_RESOLUTION_OFFSET                  (218u)
#define CapSense_BUTTON9_RESOLUTION_SIZE                    (2u)
#define CapSense_BUTTON9_RESOLUTION_PARAM_ID                (0x8D8900DAu)

#define CapSense_BUTTON9_FINGER_TH_VALUE                    (CapSense_dsRam.wdgtList.button9.fingerTh)
#define CapSense_BUTTON9_FINGER_TH_OFFSET                   (220u)
#define CapSense_BUTTON9_FINGER_TH_SIZE                     (2u)
#define CapSense_BUTTON9_FINGER_TH_PARAM_ID                 (0x808900DCu)

#define CapSense_BUTTON9_NOISE_TH_VALUE                     (CapSense_dsRam.wdgtList.button9.noiseTh)
#define CapSense_BUTTON9_NOISE_TH_OFFSET                    (222u)
#define CapSense_BUTTON9_NOISE_TH_SIZE                      (1u)
#define CapSense_BUTTON9_NOISE_TH_PARAM_ID                  (0x448900DEu)

#define CapSense_BUTTON9_NNOISE_TH_VALUE                    (CapSense_dsRam.wdgtList.button9.nNoiseTh)
#define CapSense_BUTTON9_NNOISE_TH_OFFSET                   (223u)
#define CapSense_BUTTON9_NNOISE_TH_SIZE                     (1u)
#define CapSense_BUTTON9_NNOISE_TH_PARAM_ID                 (0x428900DFu)

#define CapSense_BUTTON9_HYSTERESIS_VALUE                   (CapSense_dsRam.wdgtList.button9.hysteresis)
#define CapSense_BUTTON9_HYSTERESIS_OFFSET                  (224u)
#define CapSense_BUTTON9_HYSTERESIS_SIZE                    (1u)
#define CapSense_BUTTON9_HYSTERESIS_PARAM_ID                (0x448900E0u)

#define CapSense_BUTTON9_ON_DEBOUNCE_VALUE                  (CapSense_dsRam.wdgtList.button9.onDebounce)
#define CapSense_BUTTON9_ON_DEBOUNCE_OFFSET                 (225u)
#define CapSense_BUTTON9_ON_DEBOUNCE_SIZE                   (1u)
#define CapSense_BUTTON9_ON_DEBOUNCE_PARAM_ID               (0x428900E1u)

#define CapSense_BUTTON9_LOW_BSLN_RST_VALUE                 (CapSense_dsRam.wdgtList.button9.lowBslnRst)
#define CapSense_BUTTON9_LOW_BSLN_RST_OFFSET                (226u)
#define CapSense_BUTTON9_LOW_BSLN_RST_SIZE                  (1u)
#define CapSense_BUTTON9_LOW_BSLN_RST_PARAM_ID              (0x488900E2u)

#define CapSense_BUTTON9_BSLN_COEFF_VALUE                   (CapSense_dsRam.wdgtList.button9.bslnCoeff)
#define CapSense_BUTTON9_BSLN_COEFF_OFFSET                  (227u)
#define CapSense_BUTTON9_BSLN_COEFF_SIZE                    (1u)
#define CapSense_BUTTON9_BSLN_COEFF_PARAM_ID                (0x658900E3u)

#define CapSense_BUTTON9_IDAC_MOD0_VALUE                    (CapSense_dsRam.wdgtList.button9.idacMod[0u])
#define CapSense_BUTTON9_IDAC_MOD0_OFFSET                   (228u)
#define CapSense_BUTTON9_IDAC_MOD0_SIZE                     (1u)
#define CapSense_BUTTON9_IDAC_MOD0_PARAM_ID                 (0x480900E4u)

#define CapSense_BUTTON9_SNS_CLK_VALUE                      (CapSense_dsRam.wdgtList.button9.snsClk)
#define CapSense_BUTTON9_SNS_CLK_OFFSET                     (229u)
#define CapSense_BUTTON9_SNS_CLK_SIZE                       (1u)
#define CapSense_BUTTON9_SNS_CLK_PARAM_ID                   (0x438900E5u)

#define CapSense_BUTTON9_SNS_CLK_SOURCE_VALUE               (CapSense_dsRam.wdgtList.button9.snsClkSource)
#define CapSense_BUTTON9_SNS_CLK_SOURCE_OFFSET              (230u)
#define CapSense_BUTTON9_SNS_CLK_SOURCE_SIZE                (1u)
#define CapSense_BUTTON9_SNS_CLK_SOURCE_PARAM_ID            (0x498900E6u)

#define CapSense_BUTTON9_FINGER_CAP_VALUE                   (CapSense_dsRam.wdgtList.button9.fingerCap)
#define CapSense_BUTTON9_FINGER_CAP_OFFSET                  (232u)
#define CapSense_BUTTON9_FINGER_CAP_SIZE                    (2u)
#define CapSense_BUTTON9_FINGER_CAP_PARAM_ID                (0xA80900E8u)

#define CapSense_BUTTON9_SIGPFC_VALUE                       (CapSense_dsRam.wdgtList.button9.sigPFC)
#define CapSense_BUTTON9_SIGPFC_OFFSET                      (234u)
#define CapSense_BUTTON9_SIGPFC_SIZE                        (2u)
#define CapSense_BUTTON9_SIGPFC_PARAM_ID                    (0xA40900EAu)

#define CapSense_BUTTON10_RESOLUTION_VALUE                  (CapSense_dsRam.wdgtList.button10.resolution)
#define CapSense_BUTTON10_RESOLUTION_OFFSET                 (236u)
#define CapSense_BUTTON10_RESOLUTION_SIZE                   (2u)
#define CapSense_BUTTON10_RESOLUTION_PARAM_ID               (0x8A8A00ECu)

#define CapSense_BUTTON10_FINGER_TH_VALUE                   (CapSense_dsRam.wdgtList.button10.fingerTh)
#define CapSense_BUTTON10_FINGER_TH_OFFSET                  (238u)
#define CapSense_BUTTON10_FINGER_TH_SIZE                    (2u)
#define CapSense_BUTTON10_FINGER_TH_PARAM_ID                (0x868A00EEu)

#define CapSense_BUTTON10_NOISE_TH_VALUE                    (CapSense_dsRam.wdgtList.button10.noiseTh)
#define CapSense_BUTTON10_NOISE_TH_OFFSET                   (240u)
#define CapSense_BUTTON10_NOISE_TH_SIZE                     (1u)
#define CapSense_BUTTON10_NOISE_TH_PARAM_ID                 (0x448A00F0u)

#define CapSense_BUTTON10_NNOISE_TH_VALUE                   (CapSense_dsRam.wdgtList.button10.nNoiseTh)
#define CapSense_BUTTON10_NNOISE_TH_OFFSET                  (241u)
#define CapSense_BUTTON10_NNOISE_TH_SIZE                    (1u)
#define CapSense_BUTTON10_NNOISE_TH_PARAM_ID                (0x428A00F1u)

#define CapSense_BUTTON10_HYSTERESIS_VALUE                  (CapSense_dsRam.wdgtList.button10.hysteresis)
#define CapSense_BUTTON10_HYSTERESIS_OFFSET                 (242u)
#define CapSense_BUTTON10_HYSTERESIS_SIZE                   (1u)
#define CapSense_BUTTON10_HYSTERESIS_PARAM_ID               (0x488A00F2u)

#define CapSense_BUTTON10_ON_DEBOUNCE_VALUE                 (CapSense_dsRam.wdgtList.button10.onDebounce)
#define CapSense_BUTTON10_ON_DEBOUNCE_OFFSET                (243u)
#define CapSense_BUTTON10_ON_DEBOUNCE_SIZE                  (1u)
#define CapSense_BUTTON10_ON_DEBOUNCE_PARAM_ID              (0x4E8A00F3u)

#define CapSense_BUTTON10_LOW_BSLN_RST_VALUE                (CapSense_dsRam.wdgtList.button10.lowBslnRst)
#define CapSense_BUTTON10_LOW_BSLN_RST_OFFSET               (244u)
#define CapSense_BUTTON10_LOW_BSLN_RST_SIZE                 (1u)
#define CapSense_BUTTON10_LOW_BSLN_RST_PARAM_ID             (0x458A00F4u)

#define CapSense_BUTTON10_BSLN_COEFF_VALUE                  (CapSense_dsRam.wdgtList.button10.bslnCoeff)
#define CapSense_BUTTON10_BSLN_COEFF_OFFSET                 (245u)
#define CapSense_BUTTON10_BSLN_COEFF_SIZE                   (1u)
#define CapSense_BUTTON10_BSLN_COEFF_PARAM_ID               (0x688A00F5u)

#define CapSense_BUTTON10_IDAC_MOD0_VALUE                   (CapSense_dsRam.wdgtList.button10.idacMod[0u])
#define CapSense_BUTTON10_IDAC_MOD0_OFFSET                  (246u)
#define CapSense_BUTTON10_IDAC_MOD0_SIZE                    (1u)
#define CapSense_BUTTON10_IDAC_MOD0_PARAM_ID                (0x440A00F6u)

#define CapSense_BUTTON10_SNS_CLK_VALUE                     (CapSense_dsRam.wdgtList.button10.snsClk)
#define CapSense_BUTTON10_SNS_CLK_OFFSET                    (247u)
#define CapSense_BUTTON10_SNS_CLK_SIZE                      (1u)
#define CapSense_BUTTON10_SNS_CLK_PARAM_ID                  (0x4F8A00F7u)

#define CapSense_BUTTON10_SNS_CLK_SOURCE_VALUE              (CapSense_dsRam.wdgtList.button10.snsClkSource)
#define CapSense_BUTTON10_SNS_CLK_SOURCE_OFFSET             (248u)
#define CapSense_BUTTON10_SNS_CLK_SOURCE_SIZE               (1u)
#define CapSense_BUTTON10_SNS_CLK_SOURCE_PARAM_ID           (0x468A00F8u)

#define CapSense_BUTTON10_FINGER_CAP_VALUE                  (CapSense_dsRam.wdgtList.button10.fingerCap)
#define CapSense_BUTTON10_FINGER_CAP_OFFSET                 (250u)
#define CapSense_BUTTON10_FINGER_CAP_SIZE                   (2u)
#define CapSense_BUTTON10_FINGER_CAP_PARAM_ID               (0xA40A00FAu)

#define CapSense_BUTTON10_SIGPFC_VALUE                      (CapSense_dsRam.wdgtList.button10.sigPFC)
#define CapSense_BUTTON10_SIGPFC_OFFSET                     (252u)
#define CapSense_BUTTON10_SIGPFC_SIZE                       (2u)
#define CapSense_BUTTON10_SIGPFC_PARAM_ID                   (0xA90A00FCu)

#define CapSense_BUTTON11_RESOLUTION_VALUE                  (CapSense_dsRam.wdgtList.button11.resolution)
#define CapSense_BUTTON11_RESOLUTION_OFFSET                 (254u)
#define CapSense_BUTTON11_RESOLUTION_SIZE                   (2u)
#define CapSense_BUTTON11_RESOLUTION_PARAM_ID               (0x808B00FEu)

#define CapSense_BUTTON11_FINGER_TH_VALUE                   (CapSense_dsRam.wdgtList.button11.fingerTh)
#define CapSense_BUTTON11_FINGER_TH_OFFSET                  (256u)
#define CapSense_BUTTON11_FINGER_TH_SIZE                    (2u)
#define CapSense_BUTTON11_FINGER_TH_PARAM_ID                (0x858B0100u)

#define CapSense_BUTTON11_NOISE_TH_VALUE                    (CapSense_dsRam.wdgtList.button11.noiseTh)
#define CapSense_BUTTON11_NOISE_TH_OFFSET                   (258u)
#define CapSense_BUTTON11_NOISE_TH_SIZE                     (1u)
#define CapSense_BUTTON11_NOISE_TH_PARAM_ID                 (0x418B0102u)

#define CapSense_BUTTON11_NNOISE_TH_VALUE                   (CapSense_dsRam.wdgtList.button11.nNoiseTh)
#define CapSense_BUTTON11_NNOISE_TH_OFFSET                  (259u)
#define CapSense_BUTTON11_NNOISE_TH_SIZE                    (1u)
#define CapSense_BUTTON11_NNOISE_TH_PARAM_ID                (0x478B0103u)

#define CapSense_BUTTON11_HYSTERESIS_VALUE                  (CapSense_dsRam.wdgtList.button11.hysteresis)
#define CapSense_BUTTON11_HYSTERESIS_OFFSET                 (260u)
#define CapSense_BUTTON11_HYSTERESIS_SIZE                   (1u)
#define CapSense_BUTTON11_HYSTERESIS_PARAM_ID               (0x4C8B0104u)

#define CapSense_BUTTON11_ON_DEBOUNCE_VALUE                 (CapSense_dsRam.wdgtList.button11.onDebounce)
#define CapSense_BUTTON11_ON_DEBOUNCE_OFFSET                (261u)
#define CapSense_BUTTON11_ON_DEBOUNCE_SIZE                  (1u)
#define CapSense_BUTTON11_ON_DEBOUNCE_PARAM_ID              (0x4A8B0105u)

#define CapSense_BUTTON11_LOW_BSLN_RST_VALUE                (CapSense_dsRam.wdgtList.button11.lowBslnRst)
#define CapSense_BUTTON11_LOW_BSLN_RST_OFFSET               (262u)
#define CapSense_BUTTON11_LOW_BSLN_RST_SIZE                 (1u)
#define CapSense_BUTTON11_LOW_BSLN_RST_PARAM_ID             (0x408B0106u)

#define CapSense_BUTTON11_BSLN_COEFF_VALUE                  (CapSense_dsRam.wdgtList.button11.bslnCoeff)
#define CapSense_BUTTON11_BSLN_COEFF_OFFSET                 (263u)
#define CapSense_BUTTON11_BSLN_COEFF_SIZE                   (1u)
#define CapSense_BUTTON11_BSLN_COEFF_PARAM_ID               (0x6D8B0107u)

#define CapSense_BUTTON11_IDAC_MOD0_VALUE                   (CapSense_dsRam.wdgtList.button11.idacMod[0u])
#define CapSense_BUTTON11_IDAC_MOD0_OFFSET                  (264u)
#define CapSense_BUTTON11_IDAC_MOD0_SIZE                    (1u)
#define CapSense_BUTTON11_IDAC_MOD0_PARAM_ID                (0x420B0108u)

#define CapSense_BUTTON11_SNS_CLK_VALUE                     (CapSense_dsRam.wdgtList.button11.snsClk)
#define CapSense_BUTTON11_SNS_CLK_OFFSET                    (265u)
#define CapSense_BUTTON11_SNS_CLK_SIZE                      (1u)
#define CapSense_BUTTON11_SNS_CLK_PARAM_ID                  (0x498B0109u)

#define CapSense_BUTTON11_SNS_CLK_SOURCE_VALUE              (CapSense_dsRam.wdgtList.button11.snsClkSource)
#define CapSense_BUTTON11_SNS_CLK_SOURCE_OFFSET             (266u)
#define CapSense_BUTTON11_SNS_CLK_SOURCE_SIZE               (1u)
#define CapSense_BUTTON11_SNS_CLK_SOURCE_PARAM_ID           (0x438B010Au)

#define CapSense_BUTTON11_FINGER_CAP_VALUE                  (CapSense_dsRam.wdgtList.button11.fingerCap)
#define CapSense_BUTTON11_FINGER_CAP_OFFSET                 (268u)
#define CapSense_BUTTON11_FINGER_CAP_SIZE                   (2u)
#define CapSense_BUTTON11_FINGER_CAP_PARAM_ID               (0xA00B010Cu)

#define CapSense_BUTTON11_SIGPFC_VALUE                      (CapSense_dsRam.wdgtList.button11.sigPFC)
#define CapSense_BUTTON11_SIGPFC_OFFSET                     (270u)
#define CapSense_BUTTON11_SIGPFC_SIZE                       (2u)
#define CapSense_BUTTON11_SIGPFC_PARAM_ID                   (0xAC0B010Eu)

#define CapSense_BUTTON12_RESOLUTION_VALUE                  (CapSense_dsRam.wdgtList.button12.resolution)
#define CapSense_BUTTON12_RESOLUTION_OFFSET                 (272u)
#define CapSense_BUTTON12_RESOLUTION_SIZE                   (2u)
#define CapSense_BUTTON12_RESOLUTION_PARAM_ID               (0x898C0110u)

#define CapSense_BUTTON12_FINGER_TH_VALUE                   (CapSense_dsRam.wdgtList.button12.fingerTh)
#define CapSense_BUTTON12_FINGER_TH_OFFSET                  (274u)
#define CapSense_BUTTON12_FINGER_TH_SIZE                    (2u)
#define CapSense_BUTTON12_FINGER_TH_PARAM_ID                (0x858C0112u)

#define CapSense_BUTTON12_NOISE_TH_VALUE                    (CapSense_dsRam.wdgtList.button12.noiseTh)
#define CapSense_BUTTON12_NOISE_TH_OFFSET                   (276u)
#define CapSense_BUTTON12_NOISE_TH_SIZE                     (1u)
#define CapSense_BUTTON12_NOISE_TH_PARAM_ID                 (0x408C0114u)

#define CapSense_BUTTON12_NNOISE_TH_VALUE                   (CapSense_dsRam.wdgtList.button12.nNoiseTh)
#define CapSense_BUTTON12_NNOISE_TH_OFFSET                  (277u)
#define CapSense_BUTTON12_NNOISE_TH_SIZE                    (1u)
#define CapSense_BUTTON12_NNOISE_TH_PARAM_ID                (0x468C0115u)

#define CapSense_BUTTON12_HYSTERESIS_VALUE                  (CapSense_dsRam.wdgtList.button12.hysteresis)
#define CapSense_BUTTON12_HYSTERESIS_OFFSET                 (278u)
#define CapSense_BUTTON12_HYSTERESIS_SIZE                   (1u)
#define CapSense_BUTTON12_HYSTERESIS_PARAM_ID               (0x4C8C0116u)

#define CapSense_BUTTON12_ON_DEBOUNCE_VALUE                 (CapSense_dsRam.wdgtList.button12.onDebounce)
#define CapSense_BUTTON12_ON_DEBOUNCE_OFFSET                (279u)
#define CapSense_BUTTON12_ON_DEBOUNCE_SIZE                  (1u)
#define CapSense_BUTTON12_ON_DEBOUNCE_PARAM_ID              (0x4A8C0117u)

#define CapSense_BUTTON12_LOW_BSLN_RST_VALUE                (CapSense_dsRam.wdgtList.button12.lowBslnRst)
#define CapSense_BUTTON12_LOW_BSLN_RST_OFFSET               (280u)
#define CapSense_BUTTON12_LOW_BSLN_RST_SIZE                 (1u)
#define CapSense_BUTTON12_LOW_BSLN_RST_PARAM_ID             (0x438C0118u)

#define CapSense_BUTTON12_BSLN_COEFF_VALUE                  (CapSense_dsRam.wdgtList.button12.bslnCoeff)
#define CapSense_BUTTON12_BSLN_COEFF_OFFSET                 (281u)
#define CapSense_BUTTON12_BSLN_COEFF_SIZE                   (1u)
#define CapSense_BUTTON12_BSLN_COEFF_PARAM_ID               (0x6E8C0119u)

#define CapSense_BUTTON12_IDAC_MOD0_VALUE                   (CapSense_dsRam.wdgtList.button12.idacMod[0u])
#define CapSense_BUTTON12_IDAC_MOD0_OFFSET                  (282u)
#define CapSense_BUTTON12_IDAC_MOD0_SIZE                    (1u)
#define CapSense_BUTTON12_IDAC_MOD0_PARAM_ID                (0x420C011Au)

#define CapSense_BUTTON12_SNS_CLK_VALUE                     (CapSense_dsRam.wdgtList.button12.snsClk)
#define CapSense_BUTTON12_SNS_CLK_OFFSET                    (283u)
#define CapSense_BUTTON12_SNS_CLK_SIZE                      (1u)
#define CapSense_BUTTON12_SNS_CLK_PARAM_ID                  (0x498C011Bu)

#define CapSense_BUTTON12_SNS_CLK_SOURCE_VALUE              (CapSense_dsRam.wdgtList.button12.snsClkSource)
#define CapSense_BUTTON12_SNS_CLK_SOURCE_OFFSET             (284u)
#define CapSense_BUTTON12_SNS_CLK_SOURCE_SIZE               (1u)
#define CapSense_BUTTON12_SNS_CLK_SOURCE_PARAM_ID           (0x428C011Cu)

#define CapSense_BUTTON12_FINGER_CAP_VALUE                  (CapSense_dsRam.wdgtList.button12.fingerCap)
#define CapSense_BUTTON12_FINGER_CAP_OFFSET                 (286u)
#define CapSense_BUTTON12_FINGER_CAP_SIZE                   (2u)
#define CapSense_BUTTON12_FINGER_CAP_PARAM_ID               (0xA00C011Eu)

#define CapSense_BUTTON12_SIGPFC_VALUE                      (CapSense_dsRam.wdgtList.button12.sigPFC)
#define CapSense_BUTTON12_SIGPFC_OFFSET                     (288u)
#define CapSense_BUTTON12_SIGPFC_SIZE                       (2u)
#define CapSense_BUTTON12_SIGPFC_PARAM_ID                   (0xA00C0120u)

#define CapSense_BUTTON13_RESOLUTION_VALUE                  (CapSense_dsRam.wdgtList.button13.resolution)
#define CapSense_BUTTON13_RESOLUTION_OFFSET                 (290u)
#define CapSense_BUTTON13_RESOLUTION_SIZE                   (2u)
#define CapSense_BUTTON13_RESOLUTION_PARAM_ID               (0x898D0122u)

#define CapSense_BUTTON13_FINGER_TH_VALUE                   (CapSense_dsRam.wdgtList.button13.fingerTh)
#define CapSense_BUTTON13_FINGER_TH_OFFSET                  (292u)
#define CapSense_BUTTON13_FINGER_TH_SIZE                    (2u)
#define CapSense_BUTTON13_FINGER_TH_PARAM_ID                (0x848D0124u)

#define CapSense_BUTTON13_NOISE_TH_VALUE                    (CapSense_dsRam.wdgtList.button13.noiseTh)
#define CapSense_BUTTON13_NOISE_TH_OFFSET                   (294u)
#define CapSense_BUTTON13_NOISE_TH_SIZE                     (1u)
#define CapSense_BUTTON13_NOISE_TH_PARAM_ID                 (0x408D0126u)

#define CapSense_BUTTON13_NNOISE_TH_VALUE                   (CapSense_dsRam.wdgtList.button13.nNoiseTh)
#define CapSense_BUTTON13_NNOISE_TH_OFFSET                  (295u)
#define CapSense_BUTTON13_NNOISE_TH_SIZE                    (1u)
#define CapSense_BUTTON13_NNOISE_TH_PARAM_ID                (0x468D0127u)

#define CapSense_BUTTON13_HYSTERESIS_VALUE                  (CapSense_dsRam.wdgtList.button13.hysteresis)
#define CapSense_BUTTON13_HYSTERESIS_OFFSET                 (296u)
#define CapSense_BUTTON13_HYSTERESIS_SIZE                   (1u)
#define CapSense_BUTTON13_HYSTERESIS_PARAM_ID               (0x4F8D0128u)

#define CapSense_BUTTON13_ON_DEBOUNCE_VALUE                 (CapSense_dsRam.wdgtList.button13.onDebounce)
#define CapSense_BUTTON13_ON_DEBOUNCE_OFFSET                (297u)
#define CapSense_BUTTON13_ON_DEBOUNCE_SIZE                  (1u)
#define CapSense_BUTTON13_ON_DEBOUNCE_PARAM_ID              (0x498D0129u)

#define CapSense_BUTTON13_LOW_BSLN_RST_VALUE                (CapSense_dsRam.wdgtList.button13.lowBslnRst)
#define CapSense_BUTTON13_LOW_BSLN_RST_OFFSET               (298u)
#define CapSense_BUTTON13_LOW_BSLN_RST_SIZE                 (1u)
#define CapSense_BUTTON13_LOW_BSLN_RST_PARAM_ID             (0x438D012Au)

#define CapSense_BUTTON13_BSLN_COEFF_VALUE                  (CapSense_dsRam.wdgtList.button13.bslnCoeff)
#define CapSense_BUTTON13_BSLN_COEFF_OFFSET                 (299u)
#define CapSense_BUTTON13_BSLN_COEFF_SIZE                   (1u)
#define CapSense_BUTTON13_BSLN_COEFF_PARAM_ID               (0x6E8D012Bu)

#define CapSense_BUTTON13_IDAC_MOD0_VALUE                   (CapSense_dsRam.wdgtList.button13.idacMod[0u])
#define CapSense_BUTTON13_IDAC_MOD0_OFFSET                  (300u)
#define CapSense_BUTTON13_IDAC_MOD0_SIZE                    (1u)
#define CapSense_BUTTON13_IDAC_MOD0_PARAM_ID                (0x430D012Cu)

#define CapSense_BUTTON13_SNS_CLK_VALUE                     (CapSense_dsRam.wdgtList.button13.snsClk)
#define CapSense_BUTTON13_SNS_CLK_OFFSET                    (301u)
#define CapSense_BUTTON13_SNS_CLK_SIZE                      (1u)
#define CapSense_BUTTON13_SNS_CLK_PARAM_ID                  (0x488D012Du)

#define CapSense_BUTTON13_SNS_CLK_SOURCE_VALUE              (CapSense_dsRam.wdgtList.button13.snsClkSource)
#define CapSense_BUTTON13_SNS_CLK_SOURCE_OFFSET             (302u)
#define CapSense_BUTTON13_SNS_CLK_SOURCE_SIZE               (1u)
#define CapSense_BUTTON13_SNS_CLK_SOURCE_PARAM_ID           (0x428D012Eu)

#define CapSense_BUTTON13_FINGER_CAP_VALUE                  (CapSense_dsRam.wdgtList.button13.fingerCap)
#define CapSense_BUTTON13_FINGER_CAP_OFFSET                 (304u)
#define CapSense_BUTTON13_FINGER_CAP_SIZE                   (2u)
#define CapSense_BUTTON13_FINGER_CAP_PARAM_ID               (0xA60D0130u)

#define CapSense_BUTTON13_SIGPFC_VALUE                      (CapSense_dsRam.wdgtList.button13.sigPFC)
#define CapSense_BUTTON13_SIGPFC_OFFSET                     (306u)
#define CapSense_BUTTON13_SIGPFC_SIZE                       (2u)
#define CapSense_BUTTON13_SIGPFC_PARAM_ID                   (0xAA0D0132u)

#define CapSense_BUTTON14_RESOLUTION_VALUE                  (CapSense_dsRam.wdgtList.button14.resolution)
#define CapSense_BUTTON14_RESOLUTION_OFFSET                 (308u)
#define CapSense_BUTTON14_RESOLUTION_SIZE                   (2u)
#define CapSense_BUTTON14_RESOLUTION_PARAM_ID               (0x848E0134u)

#define CapSense_BUTTON14_FINGER_TH_VALUE                   (CapSense_dsRam.wdgtList.button14.fingerTh)
#define CapSense_BUTTON14_FINGER_TH_OFFSET                  (310u)
#define CapSense_BUTTON14_FINGER_TH_SIZE                    (2u)
#define CapSense_BUTTON14_FINGER_TH_PARAM_ID                (0x888E0136u)

#define CapSense_BUTTON14_NOISE_TH_VALUE                    (CapSense_dsRam.wdgtList.button14.noiseTh)
#define CapSense_BUTTON14_NOISE_TH_OFFSET                   (312u)
#define CapSense_BUTTON14_NOISE_TH_SIZE                     (1u)
#define CapSense_BUTTON14_NOISE_TH_PARAM_ID                 (0x4F8E0138u)

#define CapSense_BUTTON14_NNOISE_TH_VALUE                   (CapSense_dsRam.wdgtList.button14.nNoiseTh)
#define CapSense_BUTTON14_NNOISE_TH_OFFSET                  (313u)
#define CapSense_BUTTON14_NNOISE_TH_SIZE                    (1u)
#define CapSense_BUTTON14_NNOISE_TH_PARAM_ID                (0x498E0139u)

#define CapSense_BUTTON14_HYSTERESIS_VALUE                  (CapSense_dsRam.wdgtList.button14.hysteresis)
#define CapSense_BUTTON14_HYSTERESIS_OFFSET                 (314u)
#define CapSense_BUTTON14_HYSTERESIS_SIZE                   (1u)
#define CapSense_BUTTON14_HYSTERESIS_PARAM_ID               (0x438E013Au)

#define CapSense_BUTTON14_ON_DEBOUNCE_VALUE                 (CapSense_dsRam.wdgtList.button14.onDebounce)
#define CapSense_BUTTON14_ON_DEBOUNCE_OFFSET                (315u)
#define CapSense_BUTTON14_ON_DEBOUNCE_SIZE                  (1u)
#define CapSense_BUTTON14_ON_DEBOUNCE_PARAM_ID              (0x458E013Bu)

#define CapSense_BUTTON14_LOW_BSLN_RST_VALUE                (CapSense_dsRam.wdgtList.button14.lowBslnRst)
#define CapSense_BUTTON14_LOW_BSLN_RST_OFFSET               (316u)
#define CapSense_BUTTON14_LOW_BSLN_RST_SIZE                 (1u)
#define CapSense_BUTTON14_LOW_BSLN_RST_PARAM_ID             (0x4E8E013Cu)

#define CapSense_BUTTON14_BSLN_COEFF_VALUE                  (CapSense_dsRam.wdgtList.button14.bslnCoeff)
#define CapSense_BUTTON14_BSLN_COEFF_OFFSET                 (317u)
#define CapSense_BUTTON14_BSLN_COEFF_SIZE                   (1u)
#define CapSense_BUTTON14_BSLN_COEFF_PARAM_ID               (0x638E013Du)

#define CapSense_BUTTON14_IDAC_MOD0_VALUE                   (CapSense_dsRam.wdgtList.button14.idacMod[0u])
#define CapSense_BUTTON14_IDAC_MOD0_OFFSET                  (318u)
#define CapSense_BUTTON14_IDAC_MOD0_SIZE                    (1u)
#define CapSense_BUTTON14_IDAC_MOD0_PARAM_ID                (0x4F0E013Eu)

#define CapSense_BUTTON14_SNS_CLK_VALUE                     (CapSense_dsRam.wdgtList.button14.snsClk)
#define CapSense_BUTTON14_SNS_CLK_OFFSET                    (319u)
#define CapSense_BUTTON14_SNS_CLK_SIZE                      (1u)
#define CapSense_BUTTON14_SNS_CLK_PARAM_ID                  (0x448E013Fu)

#define CapSense_BUTTON14_SNS_CLK_SOURCE_VALUE              (CapSense_dsRam.wdgtList.button14.snsClkSource)
#define CapSense_BUTTON14_SNS_CLK_SOURCE_OFFSET             (320u)
#define CapSense_BUTTON14_SNS_CLK_SOURCE_SIZE               (1u)
#define CapSense_BUTTON14_SNS_CLK_SOURCE_PARAM_ID           (0x4F8E0140u)

#define CapSense_BUTTON14_FINGER_CAP_VALUE                  (CapSense_dsRam.wdgtList.button14.fingerCap)
#define CapSense_BUTTON14_FINGER_CAP_OFFSET                 (322u)
#define CapSense_BUTTON14_FINGER_CAP_SIZE                   (2u)
#define CapSense_BUTTON14_FINGER_CAP_PARAM_ID               (0xAD0E0142u)

#define CapSense_BUTTON14_SIGPFC_VALUE                      (CapSense_dsRam.wdgtList.button14.sigPFC)
#define CapSense_BUTTON14_SIGPFC_OFFSET                     (324u)
#define CapSense_BUTTON14_SIGPFC_SIZE                       (2u)
#define CapSense_BUTTON14_SIGPFC_PARAM_ID                   (0xA00E0144u)

#define CapSense_BUTTON15_RESOLUTION_VALUE                  (CapSense_dsRam.wdgtList.button15.resolution)
#define CapSense_BUTTON15_RESOLUTION_OFFSET                 (326u)
#define CapSense_BUTTON15_RESOLUTION_SIZE                   (2u)
#define CapSense_BUTTON15_RESOLUTION_PARAM_ID               (0x898F0146u)

#define CapSense_BUTTON15_FINGER_TH_VALUE                   (CapSense_dsRam.wdgtList.button15.fingerTh)
#define CapSense_BUTTON15_FINGER_TH_OFFSET                  (328u)
#define CapSense_BUTTON15_FINGER_TH_SIZE                    (2u)
#define CapSense_BUTTON15_FINGER_TH_PARAM_ID                (0x868F0148u)

#define CapSense_BUTTON15_NOISE_TH_VALUE                    (CapSense_dsRam.wdgtList.button15.noiseTh)
#define CapSense_BUTTON15_NOISE_TH_OFFSET                   (330u)
#define CapSense_BUTTON15_NOISE_TH_SIZE                     (1u)
#define CapSense_BUTTON15_NOISE_TH_PARAM_ID                 (0x428F014Au)

#define CapSense_BUTTON15_NNOISE_TH_VALUE                   (CapSense_dsRam.wdgtList.button15.nNoiseTh)
#define CapSense_BUTTON15_NNOISE_TH_OFFSET                  (331u)
#define CapSense_BUTTON15_NNOISE_TH_SIZE                    (1u)
#define CapSense_BUTTON15_NNOISE_TH_PARAM_ID                (0x448F014Bu)

#define CapSense_BUTTON15_HYSTERESIS_VALUE                  (CapSense_dsRam.wdgtList.button15.hysteresis)
#define CapSense_BUTTON15_HYSTERESIS_OFFSET                 (332u)
#define CapSense_BUTTON15_HYSTERESIS_SIZE                   (1u)
#define CapSense_BUTTON15_HYSTERESIS_PARAM_ID               (0x4F8F014Cu)

#define CapSense_BUTTON15_ON_DEBOUNCE_VALUE                 (CapSense_dsRam.wdgtList.button15.onDebounce)
#define CapSense_BUTTON15_ON_DEBOUNCE_OFFSET                (333u)
#define CapSense_BUTTON15_ON_DEBOUNCE_SIZE                  (1u)
#define CapSense_BUTTON15_ON_DEBOUNCE_PARAM_ID              (0x498F014Du)

#define CapSense_BUTTON15_LOW_BSLN_RST_VALUE                (CapSense_dsRam.wdgtList.button15.lowBslnRst)
#define CapSense_BUTTON15_LOW_BSLN_RST_OFFSET               (334u)
#define CapSense_BUTTON15_LOW_BSLN_RST_SIZE                 (1u)
#define CapSense_BUTTON15_LOW_BSLN_RST_PARAM_ID             (0x438F014Eu)

#define CapSense_BUTTON15_BSLN_COEFF_VALUE                  (CapSense_dsRam.wdgtList.button15.bslnCoeff)
#define CapSense_BUTTON15_BSLN_COEFF_OFFSET                 (335u)
#define CapSense_BUTTON15_BSLN_COEFF_SIZE                   (1u)
#define CapSense_BUTTON15_BSLN_COEFF_PARAM_ID               (0x6E8F014Fu)

#define CapSense_BUTTON15_IDAC_MOD0_VALUE                   (CapSense_dsRam.wdgtList.button15.idacMod[0u])
#define CapSense_BUTTON15_IDAC_MOD0_OFFSET                  (336u)
#define CapSense_BUTTON15_IDAC_MOD0_SIZE                    (1u)
#define CapSense_BUTTON15_IDAC_MOD0_PARAM_ID                (0x440F0150u)

#define CapSense_BUTTON15_SNS_CLK_VALUE                     (CapSense_dsRam.wdgtList.button15.snsClk)
#define CapSense_BUTTON15_SNS_CLK_OFFSET                    (337u)
#define CapSense_BUTTON15_SNS_CLK_SIZE                      (1u)
#define CapSense_BUTTON15_SNS_CLK_PARAM_ID                  (0x4F8F0151u)

#define CapSense_BUTTON15_SNS_CLK_SOURCE_VALUE              (CapSense_dsRam.wdgtList.button15.snsClkSource)
#define CapSense_BUTTON15_SNS_CLK_SOURCE_OFFSET             (338u)
#define CapSense_BUTTON15_SNS_CLK_SOURCE_SIZE               (1u)
#define CapSense_BUTTON15_SNS_CLK_SOURCE_PARAM_ID           (0x458F0152u)

#define CapSense_BUTTON15_FINGER_CAP_VALUE                  (CapSense_dsRam.wdgtList.button15.fingerCap)
#define CapSense_BUTTON15_FINGER_CAP_OFFSET                 (340u)
#define CapSense_BUTTON15_FINGER_CAP_SIZE                   (2u)
#define CapSense_BUTTON15_FINGER_CAP_PARAM_ID               (0xA60F0154u)

#define CapSense_BUTTON15_SIGPFC_VALUE                      (CapSense_dsRam.wdgtList.button15.sigPFC)
#define CapSense_BUTTON15_SIGPFC_OFFSET                     (342u)
#define CapSense_BUTTON15_SIGPFC_SIZE                       (2u)
#define CapSense_BUTTON15_SIGPFC_PARAM_ID                   (0xAA0F0156u)

#define CapSense_BUTTON16_RESOLUTION_VALUE                  (CapSense_dsRam.wdgtList.button16.resolution)
#define CapSense_BUTTON16_RESOLUTION_OFFSET                 (344u)
#define CapSense_BUTTON16_RESOLUTION_SIZE                   (2u)
#define CapSense_BUTTON16_RESOLUTION_PARAM_ID               (0x85900158u)

#define CapSense_BUTTON16_FINGER_TH_VALUE                   (CapSense_dsRam.wdgtList.button16.fingerTh)
#define CapSense_BUTTON16_FINGER_TH_OFFSET                  (346u)
#define CapSense_BUTTON16_FINGER_TH_SIZE                    (2u)
#define CapSense_BUTTON16_FINGER_TH_PARAM_ID                (0x8990015Au)

#define CapSense_BUTTON16_NOISE_TH_VALUE                    (CapSense_dsRam.wdgtList.button16.noiseTh)
#define CapSense_BUTTON16_NOISE_TH_OFFSET                   (348u)
#define CapSense_BUTTON16_NOISE_TH_SIZE                     (1u)
#define CapSense_BUTTON16_NOISE_TH_PARAM_ID                 (0x4C90015Cu)

#define CapSense_BUTTON16_NNOISE_TH_VALUE                   (CapSense_dsRam.wdgtList.button16.nNoiseTh)
#define CapSense_BUTTON16_NNOISE_TH_OFFSET                  (349u)
#define CapSense_BUTTON16_NNOISE_TH_SIZE                    (1u)
#define CapSense_BUTTON16_NNOISE_TH_PARAM_ID                (0x4A90015Du)

#define CapSense_BUTTON16_HYSTERESIS_VALUE                  (CapSense_dsRam.wdgtList.button16.hysteresis)
#define CapSense_BUTTON16_HYSTERESIS_OFFSET                 (350u)
#define CapSense_BUTTON16_HYSTERESIS_SIZE                   (1u)
#define CapSense_BUTTON16_HYSTERESIS_PARAM_ID               (0x4090015Eu)

#define CapSense_BUTTON16_ON_DEBOUNCE_VALUE                 (CapSense_dsRam.wdgtList.button16.onDebounce)
#define CapSense_BUTTON16_ON_DEBOUNCE_OFFSET                (351u)
#define CapSense_BUTTON16_ON_DEBOUNCE_SIZE                  (1u)
#define CapSense_BUTTON16_ON_DEBOUNCE_PARAM_ID              (0x4690015Fu)

#define CapSense_BUTTON16_LOW_BSLN_RST_VALUE                (CapSense_dsRam.wdgtList.button16.lowBslnRst)
#define CapSense_BUTTON16_LOW_BSLN_RST_OFFSET               (352u)
#define CapSense_BUTTON16_LOW_BSLN_RST_SIZE                 (1u)
#define CapSense_BUTTON16_LOW_BSLN_RST_PARAM_ID             (0x40900160u)

#define CapSense_BUTTON16_BSLN_COEFF_VALUE                  (CapSense_dsRam.wdgtList.button16.bslnCoeff)
#define CapSense_BUTTON16_BSLN_COEFF_OFFSET                 (353u)
#define CapSense_BUTTON16_BSLN_COEFF_SIZE                   (1u)
#define CapSense_BUTTON16_BSLN_COEFF_PARAM_ID               (0x6D900161u)

#define CapSense_BUTTON16_IDAC_MOD0_VALUE                   (CapSense_dsRam.wdgtList.button16.idacMod[0u])
#define CapSense_BUTTON16_IDAC_MOD0_OFFSET                  (354u)
#define CapSense_BUTTON16_IDAC_MOD0_SIZE                    (1u)
#define CapSense_BUTTON16_IDAC_MOD0_PARAM_ID                (0x41100162u)

#define CapSense_BUTTON16_SNS_CLK_VALUE                     (CapSense_dsRam.wdgtList.button16.snsClk)
#define CapSense_BUTTON16_SNS_CLK_OFFSET                    (355u)
#define CapSense_BUTTON16_SNS_CLK_SIZE                      (1u)
#define CapSense_BUTTON16_SNS_CLK_PARAM_ID                  (0x4A900163u)

#define CapSense_BUTTON16_SNS_CLK_SOURCE_VALUE              (CapSense_dsRam.wdgtList.button16.snsClkSource)
#define CapSense_BUTTON16_SNS_CLK_SOURCE_OFFSET             (356u)
#define CapSense_BUTTON16_SNS_CLK_SOURCE_SIZE               (1u)
#define CapSense_BUTTON16_SNS_CLK_SOURCE_PARAM_ID           (0x41900164u)

#define CapSense_BUTTON16_FINGER_CAP_VALUE                  (CapSense_dsRam.wdgtList.button16.fingerCap)
#define CapSense_BUTTON16_FINGER_CAP_OFFSET                 (358u)
#define CapSense_BUTTON16_FINGER_CAP_SIZE                   (2u)
#define CapSense_BUTTON16_FINGER_CAP_PARAM_ID               (0xA3100166u)

#define CapSense_BUTTON16_SIGPFC_VALUE                      (CapSense_dsRam.wdgtList.button16.sigPFC)
#define CapSense_BUTTON16_SIGPFC_OFFSET                     (360u)
#define CapSense_BUTTON16_SIGPFC_SIZE                       (2u)
#define CapSense_BUTTON16_SIGPFC_PARAM_ID                   (0xAC100168u)

#define CapSense_BUTTON17_RESOLUTION_VALUE                  (CapSense_dsRam.wdgtList.button17.resolution)
#define CapSense_BUTTON17_RESOLUTION_OFFSET                 (362u)
#define CapSense_BUTTON17_RESOLUTION_SIZE                   (2u)
#define CapSense_BUTTON17_RESOLUTION_PARAM_ID               (0x8591016Au)

#define CapSense_BUTTON17_FINGER_TH_VALUE                   (CapSense_dsRam.wdgtList.button17.fingerTh)
#define CapSense_BUTTON17_FINGER_TH_OFFSET                  (364u)
#define CapSense_BUTTON17_FINGER_TH_SIZE                    (2u)
#define CapSense_BUTTON17_FINGER_TH_PARAM_ID                (0x8891016Cu)

#define CapSense_BUTTON17_NOISE_TH_VALUE                    (CapSense_dsRam.wdgtList.button17.noiseTh)
#define CapSense_BUTTON17_NOISE_TH_OFFSET                   (366u)
#define CapSense_BUTTON17_NOISE_TH_SIZE                     (1u)
#define CapSense_BUTTON17_NOISE_TH_PARAM_ID                 (0x4C91016Eu)

#define CapSense_BUTTON17_NNOISE_TH_VALUE                   (CapSense_dsRam.wdgtList.button17.nNoiseTh)
#define CapSense_BUTTON17_NNOISE_TH_OFFSET                  (367u)
#define CapSense_BUTTON17_NNOISE_TH_SIZE                    (1u)
#define CapSense_BUTTON17_NNOISE_TH_PARAM_ID                (0x4A91016Fu)

#define CapSense_BUTTON17_HYSTERESIS_VALUE                  (CapSense_dsRam.wdgtList.button17.hysteresis)
#define CapSense_BUTTON17_HYSTERESIS_OFFSET                 (368u)
#define CapSense_BUTTON17_HYSTERESIS_SIZE                   (1u)
#define CapSense_BUTTON17_HYSTERESIS_PARAM_ID               (0x46910170u)

#define CapSense_BUTTON17_ON_DEBOUNCE_VALUE                 (CapSense_dsRam.wdgtList.button17.onDebounce)
#define CapSense_BUTTON17_ON_DEBOUNCE_OFFSET                (369u)
#define CapSense_BUTTON17_ON_DEBOUNCE_SIZE                  (1u)
#define CapSense_BUTTON17_ON_DEBOUNCE_PARAM_ID              (0x40910171u)

#define CapSense_BUTTON17_LOW_BSLN_RST_VALUE                (CapSense_dsRam.wdgtList.button17.lowBslnRst)
#define CapSense_BUTTON17_LOW_BSLN_RST_OFFSET               (370u)
#define CapSense_BUTTON17_LOW_BSLN_RST_SIZE                 (1u)
#define CapSense_BUTTON17_LOW_BSLN_RST_PARAM_ID             (0x4A910172u)

#define CapSense_BUTTON17_BSLN_COEFF_VALUE                  (CapSense_dsRam.wdgtList.button17.bslnCoeff)
#define CapSense_BUTTON17_BSLN_COEFF_OFFSET                 (371u)
#define CapSense_BUTTON17_BSLN_COEFF_SIZE                   (1u)
#define CapSense_BUTTON17_BSLN_COEFF_PARAM_ID               (0x67910173u)

#define CapSense_BUTTON17_IDAC_MOD0_VALUE                   (CapSense_dsRam.wdgtList.button17.idacMod[0u])
#define CapSense_BUTTON17_IDAC_MOD0_OFFSET                  (372u)
#define CapSense_BUTTON17_IDAC_MOD0_SIZE                    (1u)
#define CapSense_BUTTON17_IDAC_MOD0_PARAM_ID                (0x4A110174u)

#define CapSense_BUTTON17_SNS_CLK_VALUE                     (CapSense_dsRam.wdgtList.button17.snsClk)
#define CapSense_BUTTON17_SNS_CLK_OFFSET                    (373u)
#define CapSense_BUTTON17_SNS_CLK_SIZE                      (1u)
#define CapSense_BUTTON17_SNS_CLK_PARAM_ID                  (0x41910175u)

#define CapSense_BUTTON17_SNS_CLK_SOURCE_VALUE              (CapSense_dsRam.wdgtList.button17.snsClkSource)
#define CapSense_BUTTON17_SNS_CLK_SOURCE_OFFSET             (374u)
#define CapSense_BUTTON17_SNS_CLK_SOURCE_SIZE               (1u)
#define CapSense_BUTTON17_SNS_CLK_SOURCE_PARAM_ID           (0x4B910176u)

#define CapSense_BUTTON17_FINGER_CAP_VALUE                  (CapSense_dsRam.wdgtList.button17.fingerCap)
#define CapSense_BUTTON17_FINGER_CAP_OFFSET                 (376u)
#define CapSense_BUTTON17_FINGER_CAP_SIZE                   (2u)
#define CapSense_BUTTON17_FINGER_CAP_PARAM_ID               (0xAA110178u)

#define CapSense_BUTTON17_SIGPFC_VALUE                      (CapSense_dsRam.wdgtList.button17.sigPFC)
#define CapSense_BUTTON17_SIGPFC_OFFSET                     (378u)
#define CapSense_BUTTON17_SIGPFC_SIZE                       (2u)
#define CapSense_BUTTON17_SIGPFC_PARAM_ID                   (0xA611017Au)

#define CapSense_BUTTON18_RESOLUTION_VALUE                  (CapSense_dsRam.wdgtList.button18.resolution)
#define CapSense_BUTTON18_RESOLUTION_OFFSET                 (380u)
#define CapSense_BUTTON18_RESOLUTION_SIZE                   (2u)
#define CapSense_BUTTON18_RESOLUTION_PARAM_ID               (0x8892017Cu)

#define CapSense_BUTTON18_FINGER_TH_VALUE                   (CapSense_dsRam.wdgtList.button18.fingerTh)
#define CapSense_BUTTON18_FINGER_TH_OFFSET                  (382u)
#define CapSense_BUTTON18_FINGER_TH_SIZE                    (2u)
#define CapSense_BUTTON18_FINGER_TH_PARAM_ID                (0x8492017Eu)

#define CapSense_BUTTON18_NOISE_TH_VALUE                    (CapSense_dsRam.wdgtList.button18.noiseTh)
#define CapSense_BUTTON18_NOISE_TH_OFFSET                   (384u)
#define CapSense_BUTTON18_NOISE_TH_SIZE                     (1u)
#define CapSense_BUTTON18_NOISE_TH_PARAM_ID                 (0x42920180u)

#define CapSense_BUTTON18_NNOISE_TH_VALUE                   (CapSense_dsRam.wdgtList.button18.nNoiseTh)
#define CapSense_BUTTON18_NNOISE_TH_OFFSET                  (385u)
#define CapSense_BUTTON18_NNOISE_TH_SIZE                    (1u)
#define CapSense_BUTTON18_NNOISE_TH_PARAM_ID                (0x44920181u)

#define CapSense_BUTTON18_HYSTERESIS_VALUE                  (CapSense_dsRam.wdgtList.button18.hysteresis)
#define CapSense_BUTTON18_HYSTERESIS_OFFSET                 (386u)
#define CapSense_BUTTON18_HYSTERESIS_SIZE                   (1u)
#define CapSense_BUTTON18_HYSTERESIS_PARAM_ID               (0x4E920182u)

#define CapSense_BUTTON18_ON_DEBOUNCE_VALUE                 (CapSense_dsRam.wdgtList.button18.onDebounce)
#define CapSense_BUTTON18_ON_DEBOUNCE_OFFSET                (387u)
#define CapSense_BUTTON18_ON_DEBOUNCE_SIZE                  (1u)
#define CapSense_BUTTON18_ON_DEBOUNCE_PARAM_ID              (0x48920183u)

#define CapSense_BUTTON18_LOW_BSLN_RST_VALUE                (CapSense_dsRam.wdgtList.button18.lowBslnRst)
#define CapSense_BUTTON18_LOW_BSLN_RST_OFFSET               (388u)
#define CapSense_BUTTON18_LOW_BSLN_RST_SIZE                 (1u)
#define CapSense_BUTTON18_LOW_BSLN_RST_PARAM_ID             (0x43920184u)

#define CapSense_BUTTON18_BSLN_COEFF_VALUE                  (CapSense_dsRam.wdgtList.button18.bslnCoeff)
#define CapSense_BUTTON18_BSLN_COEFF_OFFSET                 (389u)
#define CapSense_BUTTON18_BSLN_COEFF_SIZE                   (1u)
#define CapSense_BUTTON18_BSLN_COEFF_PARAM_ID               (0x6E920185u)

#define CapSense_BUTTON18_IDAC_MOD0_VALUE                   (CapSense_dsRam.wdgtList.button18.idacMod[0u])
#define CapSense_BUTTON18_IDAC_MOD0_OFFSET                  (390u)
#define CapSense_BUTTON18_IDAC_MOD0_SIZE                    (1u)
#define CapSense_BUTTON18_IDAC_MOD0_PARAM_ID                (0x42120186u)

#define CapSense_BUTTON18_SNS_CLK_VALUE                     (CapSense_dsRam.wdgtList.button18.snsClk)
#define CapSense_BUTTON18_SNS_CLK_OFFSET                    (391u)
#define CapSense_BUTTON18_SNS_CLK_SIZE                      (1u)
#define CapSense_BUTTON18_SNS_CLK_PARAM_ID                  (0x49920187u)

#define CapSense_BUTTON18_SNS_CLK_SOURCE_VALUE              (CapSense_dsRam.wdgtList.button18.snsClkSource)
#define CapSense_BUTTON18_SNS_CLK_SOURCE_OFFSET             (392u)
#define CapSense_BUTTON18_SNS_CLK_SOURCE_SIZE               (1u)
#define CapSense_BUTTON18_SNS_CLK_SOURCE_PARAM_ID           (0x40920188u)

#define CapSense_BUTTON18_FINGER_CAP_VALUE                  (CapSense_dsRam.wdgtList.button18.fingerCap)
#define CapSense_BUTTON18_FINGER_CAP_OFFSET                 (394u)
#define CapSense_BUTTON18_FINGER_CAP_SIZE                   (2u)
#define CapSense_BUTTON18_FINGER_CAP_PARAM_ID               (0xA212018Au)

#define CapSense_BUTTON18_SIGPFC_VALUE                      (CapSense_dsRam.wdgtList.button18.sigPFC)
#define CapSense_BUTTON18_SIGPFC_OFFSET                     (396u)
#define CapSense_BUTTON18_SIGPFC_SIZE                       (2u)
#define CapSense_BUTTON18_SIGPFC_PARAM_ID                   (0xAF12018Cu)

#define CapSense_BUTTON19_RESOLUTION_VALUE                  (CapSense_dsRam.wdgtList.button19.resolution)
#define CapSense_BUTTON19_RESOLUTION_OFFSET                 (398u)
#define CapSense_BUTTON19_RESOLUTION_SIZE                   (2u)
#define CapSense_BUTTON19_RESOLUTION_PARAM_ID               (0x8693018Eu)

#define CapSense_BUTTON19_FINGER_TH_VALUE                   (CapSense_dsRam.wdgtList.button19.fingerTh)
#define CapSense_BUTTON19_FINGER_TH_OFFSET                  (400u)
#define CapSense_BUTTON19_FINGER_TH_SIZE                    (2u)
#define CapSense_BUTTON19_FINGER_TH_PARAM_ID                (0x8C930190u)

#define CapSense_BUTTON19_NOISE_TH_VALUE                    (CapSense_dsRam.wdgtList.button19.noiseTh)
#define CapSense_BUTTON19_NOISE_TH_OFFSET                   (402u)
#define CapSense_BUTTON19_NOISE_TH_SIZE                     (1u)
#define CapSense_BUTTON19_NOISE_TH_PARAM_ID                 (0x48930192u)

#define CapSense_BUTTON19_NNOISE_TH_VALUE                   (CapSense_dsRam.wdgtList.button19.nNoiseTh)
#define CapSense_BUTTON19_NNOISE_TH_OFFSET                  (403u)
#define CapSense_BUTTON19_NNOISE_TH_SIZE                    (1u)
#define CapSense_BUTTON19_NNOISE_TH_PARAM_ID                (0x4E930193u)

#define CapSense_BUTTON19_HYSTERESIS_VALUE                  (CapSense_dsRam.wdgtList.button19.hysteresis)
#define CapSense_BUTTON19_HYSTERESIS_OFFSET                 (404u)
#define CapSense_BUTTON19_HYSTERESIS_SIZE                   (1u)
#define CapSense_BUTTON19_HYSTERESIS_PARAM_ID               (0x45930194u)

#define CapSense_BUTTON19_ON_DEBOUNCE_VALUE                 (CapSense_dsRam.wdgtList.button19.onDebounce)
#define CapSense_BUTTON19_ON_DEBOUNCE_OFFSET                (405u)
#define CapSense_BUTTON19_ON_DEBOUNCE_SIZE                  (1u)
#define CapSense_BUTTON19_ON_DEBOUNCE_PARAM_ID              (0x43930195u)

#define CapSense_BUTTON19_LOW_BSLN_RST_VALUE                (CapSense_dsRam.wdgtList.button19.lowBslnRst)
#define CapSense_BUTTON19_LOW_BSLN_RST_OFFSET               (406u)
#define CapSense_BUTTON19_LOW_BSLN_RST_SIZE                 (1u)
#define CapSense_BUTTON19_LOW_BSLN_RST_PARAM_ID             (0x49930196u)

#define CapSense_BUTTON19_BSLN_COEFF_VALUE                  (CapSense_dsRam.wdgtList.button19.bslnCoeff)
#define CapSense_BUTTON19_BSLN_COEFF_OFFSET                 (407u)
#define CapSense_BUTTON19_BSLN_COEFF_SIZE                   (1u)
#define CapSense_BUTTON19_BSLN_COEFF_PARAM_ID               (0x64930197u)

#define CapSense_BUTTON19_IDAC_MOD0_VALUE                   (CapSense_dsRam.wdgtList.button19.idacMod[0u])
#define CapSense_BUTTON19_IDAC_MOD0_OFFSET                  (408u)
#define CapSense_BUTTON19_IDAC_MOD0_SIZE                    (1u)
#define CapSense_BUTTON19_IDAC_MOD0_PARAM_ID                (0x4B130198u)

#define CapSense_BUTTON19_SNS_CLK_VALUE                     (CapSense_dsRam.wdgtList.button19.snsClk)
#define CapSense_BUTTON19_SNS_CLK_OFFSET                    (409u)
#define CapSense_BUTTON19_SNS_CLK_SIZE                      (1u)
#define CapSense_BUTTON19_SNS_CLK_PARAM_ID                  (0x40930199u)

#define CapSense_BUTTON19_SNS_CLK_SOURCE_VALUE              (CapSense_dsRam.wdgtList.button19.snsClkSource)
#define CapSense_BUTTON19_SNS_CLK_SOURCE_OFFSET             (410u)
#define CapSense_BUTTON19_SNS_CLK_SOURCE_SIZE               (1u)
#define CapSense_BUTTON19_SNS_CLK_SOURCE_PARAM_ID           (0x4A93019Au)

#define CapSense_BUTTON19_FINGER_CAP_VALUE                  (CapSense_dsRam.wdgtList.button19.fingerCap)
#define CapSense_BUTTON19_FINGER_CAP_OFFSET                 (412u)
#define CapSense_BUTTON19_FINGER_CAP_SIZE                   (2u)
#define CapSense_BUTTON19_FINGER_CAP_PARAM_ID               (0xA913019Cu)

#define CapSense_BUTTON19_SIGPFC_VALUE                      (CapSense_dsRam.wdgtList.button19.sigPFC)
#define CapSense_BUTTON19_SIGPFC_OFFSET                     (414u)
#define CapSense_BUTTON19_SIGPFC_SIZE                       (2u)
#define CapSense_BUTTON19_SIGPFC_PARAM_ID                   (0xA513019Eu)

#define CapSense_BUTTON20_RESOLUTION_VALUE                  (CapSense_dsRam.wdgtList.button20.resolution)
#define CapSense_BUTTON20_RESOLUTION_OFFSET                 (416u)
#define CapSense_BUTTON20_RESOLUTION_SIZE                   (2u)
#define CapSense_BUTTON20_RESOLUTION_PARAM_ID               (0x8A9401A0u)

#define CapSense_BUTTON20_FINGER_TH_VALUE                   (CapSense_dsRam.wdgtList.button20.fingerTh)
#define CapSense_BUTTON20_FINGER_TH_OFFSET                  (418u)
#define CapSense_BUTTON20_FINGER_TH_SIZE                    (2u)
#define CapSense_BUTTON20_FINGER_TH_PARAM_ID                (0x869401A2u)

#define CapSense_BUTTON20_NOISE_TH_VALUE                    (CapSense_dsRam.wdgtList.button20.noiseTh)
#define CapSense_BUTTON20_NOISE_TH_OFFSET                   (420u)
#define CapSense_BUTTON20_NOISE_TH_SIZE                     (1u)
#define CapSense_BUTTON20_NOISE_TH_PARAM_ID                 (0x439401A4u)

#define CapSense_BUTTON20_NNOISE_TH_VALUE                   (CapSense_dsRam.wdgtList.button20.nNoiseTh)
#define CapSense_BUTTON20_NNOISE_TH_OFFSET                  (421u)
#define CapSense_BUTTON20_NNOISE_TH_SIZE                    (1u)
#define CapSense_BUTTON20_NNOISE_TH_PARAM_ID                (0x459401A5u)

#define CapSense_BUTTON20_HYSTERESIS_VALUE                  (CapSense_dsRam.wdgtList.button20.hysteresis)
#define CapSense_BUTTON20_HYSTERESIS_OFFSET                 (422u)
#define CapSense_BUTTON20_HYSTERESIS_SIZE                   (1u)
#define CapSense_BUTTON20_HYSTERESIS_PARAM_ID               (0x4F9401A6u)

#define CapSense_BUTTON20_ON_DEBOUNCE_VALUE                 (CapSense_dsRam.wdgtList.button20.onDebounce)
#define CapSense_BUTTON20_ON_DEBOUNCE_OFFSET                (423u)
#define CapSense_BUTTON20_ON_DEBOUNCE_SIZE                  (1u)
#define CapSense_BUTTON20_ON_DEBOUNCE_PARAM_ID              (0x499401A7u)

#define CapSense_BUTTON20_LOW_BSLN_RST_VALUE                (CapSense_dsRam.wdgtList.button20.lowBslnRst)
#define CapSense_BUTTON20_LOW_BSLN_RST_OFFSET               (424u)
#define CapSense_BUTTON20_LOW_BSLN_RST_SIZE                 (1u)
#define CapSense_BUTTON20_LOW_BSLN_RST_PARAM_ID             (0x409401A8u)

#define CapSense_BUTTON20_BSLN_COEFF_VALUE                  (CapSense_dsRam.wdgtList.button20.bslnCoeff)
#define CapSense_BUTTON20_BSLN_COEFF_OFFSET                 (425u)
#define CapSense_BUTTON20_BSLN_COEFF_SIZE                   (1u)
#define CapSense_BUTTON20_BSLN_COEFF_PARAM_ID               (0x6D9401A9u)

#define CapSense_BUTTON20_IDAC_MOD0_VALUE                   (CapSense_dsRam.wdgtList.button20.idacMod[0u])
#define CapSense_BUTTON20_IDAC_MOD0_OFFSET                  (426u)
#define CapSense_BUTTON20_IDAC_MOD0_SIZE                    (1u)
#define CapSense_BUTTON20_IDAC_MOD0_PARAM_ID                (0x411401AAu)

#define CapSense_BUTTON20_SNS_CLK_VALUE                     (CapSense_dsRam.wdgtList.button20.snsClk)
#define CapSense_BUTTON20_SNS_CLK_OFFSET                    (427u)
#define CapSense_BUTTON20_SNS_CLK_SIZE                      (1u)
#define CapSense_BUTTON20_SNS_CLK_PARAM_ID                  (0x4A9401ABu)

#define CapSense_BUTTON20_SNS_CLK_SOURCE_VALUE              (CapSense_dsRam.wdgtList.button20.snsClkSource)
#define CapSense_BUTTON20_SNS_CLK_SOURCE_OFFSET             (428u)
#define CapSense_BUTTON20_SNS_CLK_SOURCE_SIZE               (1u)
#define CapSense_BUTTON20_SNS_CLK_SOURCE_PARAM_ID           (0x419401ACu)

#define CapSense_BUTTON20_FINGER_CAP_VALUE                  (CapSense_dsRam.wdgtList.button20.fingerCap)
#define CapSense_BUTTON20_FINGER_CAP_OFFSET                 (430u)
#define CapSense_BUTTON20_FINGER_CAP_SIZE                   (2u)
#define CapSense_BUTTON20_FINGER_CAP_PARAM_ID               (0xA31401AEu)

#define CapSense_BUTTON20_SIGPFC_VALUE                      (CapSense_dsRam.wdgtList.button20.sigPFC)
#define CapSense_BUTTON20_SIGPFC_OFFSET                     (432u)
#define CapSense_BUTTON20_SIGPFC_SIZE                       (2u)
#define CapSense_BUTTON20_SIGPFC_PARAM_ID                   (0xA91401B0u)

#define CapSense_BUTTON21_RESOLUTION_VALUE                  (CapSense_dsRam.wdgtList.button21.resolution)
#define CapSense_BUTTON21_RESOLUTION_OFFSET                 (434u)
#define CapSense_BUTTON21_RESOLUTION_SIZE                   (2u)
#define CapSense_BUTTON21_RESOLUTION_PARAM_ID               (0x809501B2u)

#define CapSense_BUTTON21_FINGER_TH_VALUE                   (CapSense_dsRam.wdgtList.button21.fingerTh)
#define CapSense_BUTTON21_FINGER_TH_OFFSET                  (436u)
#define CapSense_BUTTON21_FINGER_TH_SIZE                    (2u)
#define CapSense_BUTTON21_FINGER_TH_PARAM_ID                (0x8D9501B4u)

#define CapSense_BUTTON21_NOISE_TH_VALUE                    (CapSense_dsRam.wdgtList.button21.noiseTh)
#define CapSense_BUTTON21_NOISE_TH_OFFSET                   (438u)
#define CapSense_BUTTON21_NOISE_TH_SIZE                     (1u)
#define CapSense_BUTTON21_NOISE_TH_PARAM_ID                 (0x499501B6u)

#define CapSense_BUTTON21_NNOISE_TH_VALUE                   (CapSense_dsRam.wdgtList.button21.nNoiseTh)
#define CapSense_BUTTON21_NNOISE_TH_OFFSET                  (439u)
#define CapSense_BUTTON21_NNOISE_TH_SIZE                    (1u)
#define CapSense_BUTTON21_NNOISE_TH_PARAM_ID                (0x4F9501B7u)

#define CapSense_BUTTON21_HYSTERESIS_VALUE                  (CapSense_dsRam.wdgtList.button21.hysteresis)
#define CapSense_BUTTON21_HYSTERESIS_OFFSET                 (440u)
#define CapSense_BUTTON21_HYSTERESIS_SIZE                   (1u)
#define CapSense_BUTTON21_HYSTERESIS_PARAM_ID               (0x469501B8u)

#define CapSense_BUTTON21_ON_DEBOUNCE_VALUE                 (CapSense_dsRam.wdgtList.button21.onDebounce)
#define CapSense_BUTTON21_ON_DEBOUNCE_OFFSET                (441u)
#define CapSense_BUTTON21_ON_DEBOUNCE_SIZE                  (1u)
#define CapSense_BUTTON21_ON_DEBOUNCE_PARAM_ID              (0x409501B9u)

#define CapSense_BUTTON21_LOW_BSLN_RST_VALUE                (CapSense_dsRam.wdgtList.button21.lowBslnRst)
#define CapSense_BUTTON21_LOW_BSLN_RST_OFFSET               (442u)
#define CapSense_BUTTON21_LOW_BSLN_RST_SIZE                 (1u)
#define CapSense_BUTTON21_LOW_BSLN_RST_PARAM_ID             (0x4A9501BAu)

#define CapSense_BUTTON21_BSLN_COEFF_VALUE                  (CapSense_dsRam.wdgtList.button21.bslnCoeff)
#define CapSense_BUTTON21_BSLN_COEFF_OFFSET                 (443u)
#define CapSense_BUTTON21_BSLN_COEFF_SIZE                   (1u)
#define CapSense_BUTTON21_BSLN_COEFF_PARAM_ID               (0x679501BBu)

#define CapSense_BUTTON21_IDAC_MOD0_VALUE                   (CapSense_dsRam.wdgtList.button21.idacMod[0u])
#define CapSense_BUTTON21_IDAC_MOD0_OFFSET                  (444u)
#define CapSense_BUTTON21_IDAC_MOD0_SIZE                    (1u)
#define CapSense_BUTTON21_IDAC_MOD0_PARAM_ID                (0x4A1501BCu)

#define CapSense_BUTTON21_SNS_CLK_VALUE                     (CapSense_dsRam.wdgtList.button21.snsClk)
#define CapSense_BUTTON21_SNS_CLK_OFFSET                    (445u)
#define CapSense_BUTTON21_SNS_CLK_SIZE                      (1u)
#define CapSense_BUTTON21_SNS_CLK_PARAM_ID                  (0x419501BDu)

#define CapSense_BUTTON21_SNS_CLK_SOURCE_VALUE              (CapSense_dsRam.wdgtList.button21.snsClkSource)
#define CapSense_BUTTON21_SNS_CLK_SOURCE_OFFSET             (446u)
#define CapSense_BUTTON21_SNS_CLK_SOURCE_SIZE               (1u)
#define CapSense_BUTTON21_SNS_CLK_SOURCE_PARAM_ID           (0x4B9501BEu)

#define CapSense_BUTTON21_FINGER_CAP_VALUE                  (CapSense_dsRam.wdgtList.button21.fingerCap)
#define CapSense_BUTTON21_FINGER_CAP_OFFSET                 (448u)
#define CapSense_BUTTON21_FINGER_CAP_SIZE                   (2u)
#define CapSense_BUTTON21_FINGER_CAP_PARAM_ID               (0xA81501C0u)

#define CapSense_BUTTON21_SIGPFC_VALUE                      (CapSense_dsRam.wdgtList.button21.sigPFC)
#define CapSense_BUTTON21_SIGPFC_OFFSET                     (450u)
#define CapSense_BUTTON21_SIGPFC_SIZE                       (2u)
#define CapSense_BUTTON21_SIGPFC_PARAM_ID                   (0xA41501C2u)

#define CapSense_BUTTON22_RESOLUTION_VALUE                  (CapSense_dsRam.wdgtList.button22.resolution)
#define CapSense_BUTTON22_RESOLUTION_OFFSET                 (452u)
#define CapSense_BUTTON22_RESOLUTION_SIZE                   (2u)
#define CapSense_BUTTON22_RESOLUTION_PARAM_ID               (0x8A9601C4u)

#define CapSense_BUTTON22_FINGER_TH_VALUE                   (CapSense_dsRam.wdgtList.button22.fingerTh)
#define CapSense_BUTTON22_FINGER_TH_OFFSET                  (454u)
#define CapSense_BUTTON22_FINGER_TH_SIZE                    (2u)
#define CapSense_BUTTON22_FINGER_TH_PARAM_ID                (0x869601C6u)

#define CapSense_BUTTON22_NOISE_TH_VALUE                    (CapSense_dsRam.wdgtList.button22.noiseTh)
#define CapSense_BUTTON22_NOISE_TH_OFFSET                   (456u)
#define CapSense_BUTTON22_NOISE_TH_SIZE                     (1u)
#define CapSense_BUTTON22_NOISE_TH_PARAM_ID                 (0x419601C8u)

#define CapSense_BUTTON22_NNOISE_TH_VALUE                   (CapSense_dsRam.wdgtList.button22.nNoiseTh)
#define CapSense_BUTTON22_NNOISE_TH_OFFSET                  (457u)
#define CapSense_BUTTON22_NNOISE_TH_SIZE                    (1u)
#define CapSense_BUTTON22_NNOISE_TH_PARAM_ID                (0x479601C9u)

#define CapSense_BUTTON22_HYSTERESIS_VALUE                  (CapSense_dsRam.wdgtList.button22.hysteresis)
#define CapSense_BUTTON22_HYSTERESIS_OFFSET                 (458u)
#define CapSense_BUTTON22_HYSTERESIS_SIZE                   (1u)
#define CapSense_BUTTON22_HYSTERESIS_PARAM_ID               (0x4D9601CAu)

#define CapSense_BUTTON22_ON_DEBOUNCE_VALUE                 (CapSense_dsRam.wdgtList.button22.onDebounce)
#define CapSense_BUTTON22_ON_DEBOUNCE_OFFSET                (459u)
#define CapSense_BUTTON22_ON_DEBOUNCE_SIZE                  (1u)
#define CapSense_BUTTON22_ON_DEBOUNCE_PARAM_ID              (0x4B9601CBu)

#define CapSense_BUTTON22_LOW_BSLN_RST_VALUE                (CapSense_dsRam.wdgtList.button22.lowBslnRst)
#define CapSense_BUTTON22_LOW_BSLN_RST_OFFSET               (460u)
#define CapSense_BUTTON22_LOW_BSLN_RST_SIZE                 (1u)
#define CapSense_BUTTON22_LOW_BSLN_RST_PARAM_ID             (0x409601CCu)

#define CapSense_BUTTON22_BSLN_COEFF_VALUE                  (CapSense_dsRam.wdgtList.button22.bslnCoeff)
#define CapSense_BUTTON22_BSLN_COEFF_OFFSET                 (461u)
#define CapSense_BUTTON22_BSLN_COEFF_SIZE                   (1u)
#define CapSense_BUTTON22_BSLN_COEFF_PARAM_ID               (0x6D9601CDu)

#define CapSense_BUTTON22_IDAC_MOD0_VALUE                   (CapSense_dsRam.wdgtList.button22.idacMod[0u])
#define CapSense_BUTTON22_IDAC_MOD0_OFFSET                  (462u)
#define CapSense_BUTTON22_IDAC_MOD0_SIZE                    (1u)
#define CapSense_BUTTON22_IDAC_MOD0_PARAM_ID                (0x411601CEu)

#define CapSense_BUTTON22_SNS_CLK_VALUE                     (CapSense_dsRam.wdgtList.button22.snsClk)
#define CapSense_BUTTON22_SNS_CLK_OFFSET                    (463u)
#define CapSense_BUTTON22_SNS_CLK_SIZE                      (1u)
#define CapSense_BUTTON22_SNS_CLK_PARAM_ID                  (0x4A9601CFu)

#define CapSense_BUTTON22_SNS_CLK_SOURCE_VALUE              (CapSense_dsRam.wdgtList.button22.snsClkSource)
#define CapSense_BUTTON22_SNS_CLK_SOURCE_OFFSET             (464u)
#define CapSense_BUTTON22_SNS_CLK_SOURCE_SIZE               (1u)
#define CapSense_BUTTON22_SNS_CLK_SOURCE_PARAM_ID           (0x469601D0u)

#define CapSense_BUTTON22_FINGER_CAP_VALUE                  (CapSense_dsRam.wdgtList.button22.fingerCap)
#define CapSense_BUTTON22_FINGER_CAP_OFFSET                 (466u)
#define CapSense_BUTTON22_FINGER_CAP_SIZE                   (2u)
#define CapSense_BUTTON22_FINGER_CAP_PARAM_ID               (0xA41601D2u)

#define CapSense_BUTTON22_SIGPFC_VALUE                      (CapSense_dsRam.wdgtList.button22.sigPFC)
#define CapSense_BUTTON22_SIGPFC_OFFSET                     (468u)
#define CapSense_BUTTON22_SIGPFC_SIZE                       (2u)
#define CapSense_BUTTON22_SIGPFC_PARAM_ID                   (0xA91601D4u)

#define CapSense_BUTTON23_RESOLUTION_VALUE                  (CapSense_dsRam.wdgtList.button23.resolution)
#define CapSense_BUTTON23_RESOLUTION_OFFSET                 (470u)
#define CapSense_BUTTON23_RESOLUTION_SIZE                   (2u)
#define CapSense_BUTTON23_RESOLUTION_PARAM_ID               (0x809701D6u)

#define CapSense_BUTTON23_FINGER_TH_VALUE                   (CapSense_dsRam.wdgtList.button23.fingerTh)
#define CapSense_BUTTON23_FINGER_TH_OFFSET                  (472u)
#define CapSense_BUTTON23_FINGER_TH_SIZE                    (2u)
#define CapSense_BUTTON23_FINGER_TH_PARAM_ID                (0x8F9701D8u)

#define CapSense_BUTTON23_NOISE_TH_VALUE                    (CapSense_dsRam.wdgtList.button23.noiseTh)
#define CapSense_BUTTON23_NOISE_TH_OFFSET                   (474u)
#define CapSense_BUTTON23_NOISE_TH_SIZE                     (1u)
#define CapSense_BUTTON23_NOISE_TH_PARAM_ID                 (0x4B9701DAu)

#define CapSense_BUTTON23_NNOISE_TH_VALUE                   (CapSense_dsRam.wdgtList.button23.nNoiseTh)
#define CapSense_BUTTON23_NNOISE_TH_OFFSET                  (475u)
#define CapSense_BUTTON23_NNOISE_TH_SIZE                    (1u)
#define CapSense_BUTTON23_NNOISE_TH_PARAM_ID                (0x4D9701DBu)

#define CapSense_BUTTON23_HYSTERESIS_VALUE                  (CapSense_dsRam.wdgtList.button23.hysteresis)
#define CapSense_BUTTON23_HYSTERESIS_OFFSET                 (476u)
#define CapSense_BUTTON23_HYSTERESIS_SIZE                   (1u)
#define CapSense_BUTTON23_HYSTERESIS_PARAM_ID               (0x469701DCu)

#define CapSense_BUTTON23_ON_DEBOUNCE_VALUE                 (CapSense_dsRam.wdgtList.button23.onDebounce)
#define CapSense_BUTTON23_ON_DEBOUNCE_OFFSET                (477u)
#define CapSense_BUTTON23_ON_DEBOUNCE_SIZE                  (1u)
#define CapSense_BUTTON23_ON_DEBOUNCE_PARAM_ID              (0x409701DDu)

#define CapSense_BUTTON23_LOW_BSLN_RST_VALUE                (CapSense_dsRam.wdgtList.button23.lowBslnRst)
#define CapSense_BUTTON23_LOW_BSLN_RST_OFFSET               (478u)
#define CapSense_BUTTON23_LOW_BSLN_RST_SIZE                 (1u)
#define CapSense_BUTTON23_LOW_BSLN_RST_PARAM_ID             (0x4A9701DEu)

#define CapSense_BUTTON23_BSLN_COEFF_VALUE                  (CapSense_dsRam.wdgtList.button23.bslnCoeff)
#define CapSense_BUTTON23_BSLN_COEFF_OFFSET                 (479u)
#define CapSense_BUTTON23_BSLN_COEFF_SIZE                   (1u)
#define CapSense_BUTTON23_BSLN_COEFF_PARAM_ID               (0x679701DFu)

#define CapSense_BUTTON23_IDAC_MOD0_VALUE                   (CapSense_dsRam.wdgtList.button23.idacMod[0u])
#define CapSense_BUTTON23_IDAC_MOD0_OFFSET                  (480u)
#define CapSense_BUTTON23_IDAC_MOD0_SIZE                    (1u)
#define CapSense_BUTTON23_IDAC_MOD0_PARAM_ID                (0x471701E0u)

#define CapSense_BUTTON23_SNS_CLK_VALUE                     (CapSense_dsRam.wdgtList.button23.snsClk)
#define CapSense_BUTTON23_SNS_CLK_OFFSET                    (481u)
#define CapSense_BUTTON23_SNS_CLK_SIZE                      (1u)
#define CapSense_BUTTON23_SNS_CLK_PARAM_ID                  (0x4C9701E1u)

#define CapSense_BUTTON23_SNS_CLK_SOURCE_VALUE              (CapSense_dsRam.wdgtList.button23.snsClkSource)
#define CapSense_BUTTON23_SNS_CLK_SOURCE_OFFSET             (482u)
#define CapSense_BUTTON23_SNS_CLK_SOURCE_SIZE               (1u)
#define CapSense_BUTTON23_SNS_CLK_SOURCE_PARAM_ID           (0x469701E2u)

#define CapSense_BUTTON23_FINGER_CAP_VALUE                  (CapSense_dsRam.wdgtList.button23.fingerCap)
#define CapSense_BUTTON23_FINGER_CAP_OFFSET                 (484u)
#define CapSense_BUTTON23_FINGER_CAP_SIZE                   (2u)
#define CapSense_BUTTON23_FINGER_CAP_PARAM_ID               (0xA51701E4u)

#define CapSense_BUTTON23_SIGPFC_VALUE                      (CapSense_dsRam.wdgtList.button23.sigPFC)
#define CapSense_BUTTON23_SIGPFC_OFFSET                     (486u)
#define CapSense_BUTTON23_SIGPFC_SIZE                       (2u)
#define CapSense_BUTTON23_SIGPFC_PARAM_ID                   (0xA91701E6u)

#define CapSense_BUTTON24_RESOLUTION_VALUE                  (CapSense_dsRam.wdgtList.button24.resolution)
#define CapSense_BUTTON24_RESOLUTION_OFFSET                 (488u)
#define CapSense_BUTTON24_RESOLUTION_SIZE                   (2u)
#define CapSense_BUTTON24_RESOLUTION_PARAM_ID               (0x889801E8u)

#define CapSense_BUTTON24_FINGER_TH_VALUE                   (CapSense_dsRam.wdgtList.button24.fingerTh)
#define CapSense_BUTTON24_FINGER_TH_OFFSET                  (490u)
#define CapSense_BUTTON24_FINGER_TH_SIZE                    (2u)
#define CapSense_BUTTON24_FINGER_TH_PARAM_ID                (0x849801EAu)

#define CapSense_BUTTON24_NOISE_TH_VALUE                    (CapSense_dsRam.wdgtList.button24.noiseTh)
#define CapSense_BUTTON24_NOISE_TH_OFFSET                   (492u)
#define CapSense_BUTTON24_NOISE_TH_SIZE                     (1u)
#define CapSense_BUTTON24_NOISE_TH_PARAM_ID                 (0x419801ECu)

#define CapSense_BUTTON24_NNOISE_TH_VALUE                   (CapSense_dsRam.wdgtList.button24.nNoiseTh)
#define CapSense_BUTTON24_NNOISE_TH_OFFSET                  (493u)
#define CapSense_BUTTON24_NNOISE_TH_SIZE                    (1u)
#define CapSense_BUTTON24_NNOISE_TH_PARAM_ID                (0x479801EDu)

#define CapSense_BUTTON24_HYSTERESIS_VALUE                  (CapSense_dsRam.wdgtList.button24.hysteresis)
#define CapSense_BUTTON24_HYSTERESIS_OFFSET                 (494u)
#define CapSense_BUTTON24_HYSTERESIS_SIZE                   (1u)
#define CapSense_BUTTON24_HYSTERESIS_PARAM_ID               (0x4D9801EEu)

#define CapSense_BUTTON24_ON_DEBOUNCE_VALUE                 (CapSense_dsRam.wdgtList.button24.onDebounce)
#define CapSense_BUTTON24_ON_DEBOUNCE_OFFSET                (495u)
#define CapSense_BUTTON24_ON_DEBOUNCE_SIZE                  (1u)
#define CapSense_BUTTON24_ON_DEBOUNCE_PARAM_ID              (0x4B9801EFu)

#define CapSense_BUTTON24_LOW_BSLN_RST_VALUE                (CapSense_dsRam.wdgtList.button24.lowBslnRst)
#define CapSense_BUTTON24_LOW_BSLN_RST_OFFSET               (496u)
#define CapSense_BUTTON24_LOW_BSLN_RST_SIZE                 (1u)
#define CapSense_BUTTON24_LOW_BSLN_RST_PARAM_ID             (0x479801F0u)

#define CapSense_BUTTON24_BSLN_COEFF_VALUE                  (CapSense_dsRam.wdgtList.button24.bslnCoeff)
#define CapSense_BUTTON24_BSLN_COEFF_OFFSET                 (497u)
#define CapSense_BUTTON24_BSLN_COEFF_SIZE                   (1u)
#define CapSense_BUTTON24_BSLN_COEFF_PARAM_ID               (0x6A9801F1u)

#define CapSense_BUTTON24_IDAC_MOD0_VALUE                   (CapSense_dsRam.wdgtList.button24.idacMod[0u])
#define CapSense_BUTTON24_IDAC_MOD0_OFFSET                  (498u)
#define CapSense_BUTTON24_IDAC_MOD0_SIZE                    (1u)
#define CapSense_BUTTON24_IDAC_MOD0_PARAM_ID                (0x461801F2u)

#define CapSense_BUTTON24_SNS_CLK_VALUE                     (CapSense_dsRam.wdgtList.button24.snsClk)
#define CapSense_BUTTON24_SNS_CLK_OFFSET                    (499u)
#define CapSense_BUTTON24_SNS_CLK_SIZE                      (1u)
#define CapSense_BUTTON24_SNS_CLK_PARAM_ID                  (0x4D9801F3u)

#define CapSense_BUTTON24_SNS_CLK_SOURCE_VALUE              (CapSense_dsRam.wdgtList.button24.snsClkSource)
#define CapSense_BUTTON24_SNS_CLK_SOURCE_OFFSET             (500u)
#define CapSense_BUTTON24_SNS_CLK_SOURCE_SIZE               (1u)
#define CapSense_BUTTON24_SNS_CLK_SOURCE_PARAM_ID           (0x469801F4u)

#define CapSense_BUTTON24_FINGER_CAP_VALUE                  (CapSense_dsRam.wdgtList.button24.fingerCap)
#define CapSense_BUTTON24_FINGER_CAP_OFFSET                 (502u)
#define CapSense_BUTTON24_FINGER_CAP_SIZE                   (2u)
#define CapSense_BUTTON24_FINGER_CAP_PARAM_ID               (0xA41801F6u)

#define CapSense_BUTTON24_SIGPFC_VALUE                      (CapSense_dsRam.wdgtList.button24.sigPFC)
#define CapSense_BUTTON24_SIGPFC_OFFSET                     (504u)
#define CapSense_BUTTON24_SIGPFC_SIZE                       (2u)
#define CapSense_BUTTON24_SIGPFC_PARAM_ID                   (0xAB1801F8u)

#define CapSense_BUTTON25_RESOLUTION_VALUE                  (CapSense_dsRam.wdgtList.button25.resolution)
#define CapSense_BUTTON25_RESOLUTION_OFFSET                 (506u)
#define CapSense_BUTTON25_RESOLUTION_SIZE                   (2u)
#define CapSense_BUTTON25_RESOLUTION_PARAM_ID               (0x829901FAu)

#define CapSense_BUTTON25_FINGER_TH_VALUE                   (CapSense_dsRam.wdgtList.button25.fingerTh)
#define CapSense_BUTTON25_FINGER_TH_OFFSET                  (508u)
#define CapSense_BUTTON25_FINGER_TH_SIZE                    (2u)
#define CapSense_BUTTON25_FINGER_TH_PARAM_ID                (0x8F9901FCu)

#define CapSense_BUTTON25_NOISE_TH_VALUE                    (CapSense_dsRam.wdgtList.button25.noiseTh)
#define CapSense_BUTTON25_NOISE_TH_OFFSET                   (510u)
#define CapSense_BUTTON25_NOISE_TH_SIZE                     (1u)
#define CapSense_BUTTON25_NOISE_TH_PARAM_ID                 (0x4B9901FEu)

#define CapSense_BUTTON25_NNOISE_TH_VALUE                   (CapSense_dsRam.wdgtList.button25.nNoiseTh)
#define CapSense_BUTTON25_NNOISE_TH_OFFSET                  (511u)
#define CapSense_BUTTON25_NNOISE_TH_SIZE                    (1u)
#define CapSense_BUTTON25_NNOISE_TH_PARAM_ID                (0x4D9901FFu)

#define CapSense_BUTTON25_HYSTERESIS_VALUE                  (CapSense_dsRam.wdgtList.button25.hysteresis)
#define CapSense_BUTTON25_HYSTERESIS_OFFSET                 (512u)
#define CapSense_BUTTON25_HYSTERESIS_SIZE                   (1u)
#define CapSense_BUTTON25_HYSTERESIS_PARAM_ID               (0x41990200u)

#define CapSense_BUTTON25_ON_DEBOUNCE_VALUE                 (CapSense_dsRam.wdgtList.button25.onDebounce)
#define CapSense_BUTTON25_ON_DEBOUNCE_OFFSET                (513u)
#define CapSense_BUTTON25_ON_DEBOUNCE_SIZE                  (1u)
#define CapSense_BUTTON25_ON_DEBOUNCE_PARAM_ID              (0x47990201u)

#define CapSense_BUTTON25_LOW_BSLN_RST_VALUE                (CapSense_dsRam.wdgtList.button25.lowBslnRst)
#define CapSense_BUTTON25_LOW_BSLN_RST_OFFSET               (514u)
#define CapSense_BUTTON25_LOW_BSLN_RST_SIZE                 (1u)
#define CapSense_BUTTON25_LOW_BSLN_RST_PARAM_ID             (0x4D990202u)

#define CapSense_BUTTON25_BSLN_COEFF_VALUE                  (CapSense_dsRam.wdgtList.button25.bslnCoeff)
#define CapSense_BUTTON25_BSLN_COEFF_OFFSET                 (515u)
#define CapSense_BUTTON25_BSLN_COEFF_SIZE                   (1u)
#define CapSense_BUTTON25_BSLN_COEFF_PARAM_ID               (0x60990203u)

#define CapSense_BUTTON25_IDAC_MOD0_VALUE                   (CapSense_dsRam.wdgtList.button25.idacMod[0u])
#define CapSense_BUTTON25_IDAC_MOD0_OFFSET                  (516u)
#define CapSense_BUTTON25_IDAC_MOD0_SIZE                    (1u)
#define CapSense_BUTTON25_IDAC_MOD0_PARAM_ID                (0x4D190204u)

#define CapSense_BUTTON25_SNS_CLK_VALUE                     (CapSense_dsRam.wdgtList.button25.snsClk)
#define CapSense_BUTTON25_SNS_CLK_OFFSET                    (517u)
#define CapSense_BUTTON25_SNS_CLK_SIZE                      (1u)
#define CapSense_BUTTON25_SNS_CLK_PARAM_ID                  (0x46990205u)

#define CapSense_BUTTON25_SNS_CLK_SOURCE_VALUE              (CapSense_dsRam.wdgtList.button25.snsClkSource)
#define CapSense_BUTTON25_SNS_CLK_SOURCE_OFFSET             (518u)
#define CapSense_BUTTON25_SNS_CLK_SOURCE_SIZE               (1u)
#define CapSense_BUTTON25_SNS_CLK_SOURCE_PARAM_ID           (0x4C990206u)

#define CapSense_BUTTON25_FINGER_CAP_VALUE                  (CapSense_dsRam.wdgtList.button25.fingerCap)
#define CapSense_BUTTON25_FINGER_CAP_OFFSET                 (520u)
#define CapSense_BUTTON25_FINGER_CAP_SIZE                   (2u)
#define CapSense_BUTTON25_FINGER_CAP_PARAM_ID               (0xAD190208u)

#define CapSense_BUTTON25_SIGPFC_VALUE                      (CapSense_dsRam.wdgtList.button25.sigPFC)
#define CapSense_BUTTON25_SIGPFC_OFFSET                     (522u)
#define CapSense_BUTTON25_SIGPFC_SIZE                       (2u)
#define CapSense_BUTTON25_SIGPFC_PARAM_ID                   (0xA119020Au)

#define CapSense_BUTTON26_RESOLUTION_VALUE                  (CapSense_dsRam.wdgtList.button26.resolution)
#define CapSense_BUTTON26_RESOLUTION_OFFSET                 (524u)
#define CapSense_BUTTON26_RESOLUTION_SIZE                   (2u)
#define CapSense_BUTTON26_RESOLUTION_PARAM_ID               (0x8F9A020Cu)

#define CapSense_BUTTON26_FINGER_TH_VALUE                   (CapSense_dsRam.wdgtList.button26.fingerTh)
#define CapSense_BUTTON26_FINGER_TH_OFFSET                  (526u)
#define CapSense_BUTTON26_FINGER_TH_SIZE                    (2u)
#define CapSense_BUTTON26_FINGER_TH_PARAM_ID                (0x839A020Eu)

#define CapSense_BUTTON26_NOISE_TH_VALUE                    (CapSense_dsRam.wdgtList.button26.noiseTh)
#define CapSense_BUTTON26_NOISE_TH_OFFSET                   (528u)
#define CapSense_BUTTON26_NOISE_TH_SIZE                     (1u)
#define CapSense_BUTTON26_NOISE_TH_PARAM_ID                 (0x419A0210u)

#define CapSense_BUTTON26_NNOISE_TH_VALUE                   (CapSense_dsRam.wdgtList.button26.nNoiseTh)
#define CapSense_BUTTON26_NNOISE_TH_OFFSET                  (529u)
#define CapSense_BUTTON26_NNOISE_TH_SIZE                    (1u)
#define CapSense_BUTTON26_NNOISE_TH_PARAM_ID                (0x479A0211u)

#define CapSense_BUTTON26_HYSTERESIS_VALUE                  (CapSense_dsRam.wdgtList.button26.hysteresis)
#define CapSense_BUTTON26_HYSTERESIS_OFFSET                 (530u)
#define CapSense_BUTTON26_HYSTERESIS_SIZE                   (1u)
#define CapSense_BUTTON26_HYSTERESIS_PARAM_ID               (0x4D9A0212u)

#define CapSense_BUTTON26_ON_DEBOUNCE_VALUE                 (CapSense_dsRam.wdgtList.button26.onDebounce)
#define CapSense_BUTTON26_ON_DEBOUNCE_OFFSET                (531u)
#define CapSense_BUTTON26_ON_DEBOUNCE_SIZE                  (1u)
#define CapSense_BUTTON26_ON_DEBOUNCE_PARAM_ID              (0x4B9A0213u)

#define CapSense_BUTTON26_LOW_BSLN_RST_VALUE                (CapSense_dsRam.wdgtList.button26.lowBslnRst)
#define CapSense_BUTTON26_LOW_BSLN_RST_OFFSET               (532u)
#define CapSense_BUTTON26_LOW_BSLN_RST_SIZE                 (1u)
#define CapSense_BUTTON26_LOW_BSLN_RST_PARAM_ID             (0x409A0214u)

#define CapSense_BUTTON26_BSLN_COEFF_VALUE                  (CapSense_dsRam.wdgtList.button26.bslnCoeff)
#define CapSense_BUTTON26_BSLN_COEFF_OFFSET                 (533u)
#define CapSense_BUTTON26_BSLN_COEFF_SIZE                   (1u)
#define CapSense_BUTTON26_BSLN_COEFF_PARAM_ID               (0x6D9A0215u)

#define CapSense_BUTTON26_IDAC_MOD0_VALUE                   (CapSense_dsRam.wdgtList.button26.idacMod[0u])
#define CapSense_BUTTON26_IDAC_MOD0_OFFSET                  (534u)
#define CapSense_BUTTON26_IDAC_MOD0_SIZE                    (1u)
#define CapSense_BUTTON26_IDAC_MOD0_PARAM_ID                (0x411A0216u)

#define CapSense_BUTTON26_SNS_CLK_VALUE                     (CapSense_dsRam.wdgtList.button26.snsClk)
#define CapSense_BUTTON26_SNS_CLK_OFFSET                    (535u)
#define CapSense_BUTTON26_SNS_CLK_SIZE                      (1u)
#define CapSense_BUTTON26_SNS_CLK_PARAM_ID                  (0x4A9A0217u)

#define CapSense_BUTTON26_SNS_CLK_SOURCE_VALUE              (CapSense_dsRam.wdgtList.button26.snsClkSource)
#define CapSense_BUTTON26_SNS_CLK_SOURCE_OFFSET             (536u)
#define CapSense_BUTTON26_SNS_CLK_SOURCE_SIZE               (1u)
#define CapSense_BUTTON26_SNS_CLK_SOURCE_PARAM_ID           (0x439A0218u)

#define CapSense_BUTTON26_FINGER_CAP_VALUE                  (CapSense_dsRam.wdgtList.button26.fingerCap)
#define CapSense_BUTTON26_FINGER_CAP_OFFSET                 (538u)
#define CapSense_BUTTON26_FINGER_CAP_SIZE                   (2u)
#define CapSense_BUTTON26_FINGER_CAP_PARAM_ID               (0xA11A021Au)

#define CapSense_BUTTON26_SIGPFC_VALUE                      (CapSense_dsRam.wdgtList.button26.sigPFC)
#define CapSense_BUTTON26_SIGPFC_OFFSET                     (540u)
#define CapSense_BUTTON26_SIGPFC_SIZE                       (2u)
#define CapSense_BUTTON26_SIGPFC_PARAM_ID                   (0xAC1A021Cu)

#define CapSense_BUTTON27_RESOLUTION_VALUE                  (CapSense_dsRam.wdgtList.button27.resolution)
#define CapSense_BUTTON27_RESOLUTION_OFFSET                 (542u)
#define CapSense_BUTTON27_RESOLUTION_SIZE                   (2u)
#define CapSense_BUTTON27_RESOLUTION_PARAM_ID               (0x859B021Eu)

#define CapSense_BUTTON27_FINGER_TH_VALUE                   (CapSense_dsRam.wdgtList.button27.fingerTh)
#define CapSense_BUTTON27_FINGER_TH_OFFSET                  (544u)
#define CapSense_BUTTON27_FINGER_TH_SIZE                    (2u)
#define CapSense_BUTTON27_FINGER_TH_PARAM_ID                (0x859B0220u)

#define CapSense_BUTTON27_NOISE_TH_VALUE                    (CapSense_dsRam.wdgtList.button27.noiseTh)
#define CapSense_BUTTON27_NOISE_TH_OFFSET                   (546u)
#define CapSense_BUTTON27_NOISE_TH_SIZE                     (1u)
#define CapSense_BUTTON27_NOISE_TH_PARAM_ID                 (0x419B0222u)

#define CapSense_BUTTON27_NNOISE_TH_VALUE                   (CapSense_dsRam.wdgtList.button27.nNoiseTh)
#define CapSense_BUTTON27_NNOISE_TH_OFFSET                  (547u)
#define CapSense_BUTTON27_NNOISE_TH_SIZE                    (1u)
#define CapSense_BUTTON27_NNOISE_TH_PARAM_ID                (0x479B0223u)

#define CapSense_BUTTON27_HYSTERESIS_VALUE                  (CapSense_dsRam.wdgtList.button27.hysteresis)
#define CapSense_BUTTON27_HYSTERESIS_OFFSET                 (548u)
#define CapSense_BUTTON27_HYSTERESIS_SIZE                   (1u)
#define CapSense_BUTTON27_HYSTERESIS_PARAM_ID               (0x4C9B0224u)

#define CapSense_BUTTON27_ON_DEBOUNCE_VALUE                 (CapSense_dsRam.wdgtList.button27.onDebounce)
#define CapSense_BUTTON27_ON_DEBOUNCE_OFFSET                (549u)
#define CapSense_BUTTON27_ON_DEBOUNCE_SIZE                  (1u)
#define CapSense_BUTTON27_ON_DEBOUNCE_PARAM_ID              (0x4A9B0225u)

#define CapSense_BUTTON27_LOW_BSLN_RST_VALUE                (CapSense_dsRam.wdgtList.button27.lowBslnRst)
#define CapSense_BUTTON27_LOW_BSLN_RST_OFFSET               (550u)
#define CapSense_BUTTON27_LOW_BSLN_RST_SIZE                 (1u)
#define CapSense_BUTTON27_LOW_BSLN_RST_PARAM_ID             (0x409B0226u)

#define CapSense_BUTTON27_BSLN_COEFF_VALUE                  (CapSense_dsRam.wdgtList.button27.bslnCoeff)
#define CapSense_BUTTON27_BSLN_COEFF_OFFSET                 (551u)
#define CapSense_BUTTON27_BSLN_COEFF_SIZE                   (1u)
#define CapSense_BUTTON27_BSLN_COEFF_PARAM_ID               (0x6D9B0227u)

#define CapSense_BUTTON27_IDAC_MOD0_VALUE                   (CapSense_dsRam.wdgtList.button27.idacMod[0u])
#define CapSense_BUTTON27_IDAC_MOD0_OFFSET                  (552u)
#define CapSense_BUTTON27_IDAC_MOD0_SIZE                    (1u)
#define CapSense_BUTTON27_IDAC_MOD0_PARAM_ID                (0x421B0228u)

#define CapSense_BUTTON27_SNS_CLK_VALUE                     (CapSense_dsRam.wdgtList.button27.snsClk)
#define CapSense_BUTTON27_SNS_CLK_OFFSET                    (553u)
#define CapSense_BUTTON27_SNS_CLK_SIZE                      (1u)
#define CapSense_BUTTON27_SNS_CLK_PARAM_ID                  (0x499B0229u)

#define CapSense_BUTTON27_SNS_CLK_SOURCE_VALUE              (CapSense_dsRam.wdgtList.button27.snsClkSource)
#define CapSense_BUTTON27_SNS_CLK_SOURCE_OFFSET             (554u)
#define CapSense_BUTTON27_SNS_CLK_SOURCE_SIZE               (1u)
#define CapSense_BUTTON27_SNS_CLK_SOURCE_PARAM_ID           (0x439B022Au)

#define CapSense_BUTTON27_FINGER_CAP_VALUE                  (CapSense_dsRam.wdgtList.button27.fingerCap)
#define CapSense_BUTTON27_FINGER_CAP_OFFSET                 (556u)
#define CapSense_BUTTON27_FINGER_CAP_SIZE                   (2u)
#define CapSense_BUTTON27_FINGER_CAP_PARAM_ID               (0xA01B022Cu)

#define CapSense_BUTTON27_SIGPFC_VALUE                      (CapSense_dsRam.wdgtList.button27.sigPFC)
#define CapSense_BUTTON27_SIGPFC_OFFSET                     (558u)
#define CapSense_BUTTON27_SIGPFC_SIZE                       (2u)
#define CapSense_BUTTON27_SIGPFC_PARAM_ID                   (0xAC1B022Eu)

#define CapSense_BUTTON28_RESOLUTION_VALUE                  (CapSense_dsRam.wdgtList.button28.resolution)
#define CapSense_BUTTON28_RESOLUTION_OFFSET                 (560u)
#define CapSense_BUTTON28_RESOLUTION_SIZE                   (2u)
#define CapSense_BUTTON28_RESOLUTION_PARAM_ID               (0x899C0230u)

#define CapSense_BUTTON28_FINGER_TH_VALUE                   (CapSense_dsRam.wdgtList.button28.fingerTh)
#define CapSense_BUTTON28_FINGER_TH_OFFSET                  (562u)
#define CapSense_BUTTON28_FINGER_TH_SIZE                    (2u)
#define CapSense_BUTTON28_FINGER_TH_PARAM_ID                (0x859C0232u)

#define CapSense_BUTTON28_NOISE_TH_VALUE                    (CapSense_dsRam.wdgtList.button28.noiseTh)
#define CapSense_BUTTON28_NOISE_TH_OFFSET                   (564u)
#define CapSense_BUTTON28_NOISE_TH_SIZE                     (1u)
#define CapSense_BUTTON28_NOISE_TH_PARAM_ID                 (0x409C0234u)

#define CapSense_BUTTON28_NNOISE_TH_VALUE                   (CapSense_dsRam.wdgtList.button28.nNoiseTh)
#define CapSense_BUTTON28_NNOISE_TH_OFFSET                  (565u)
#define CapSense_BUTTON28_NNOISE_TH_SIZE                    (1u)
#define CapSense_BUTTON28_NNOISE_TH_PARAM_ID                (0x469C0235u)

#define CapSense_BUTTON28_HYSTERESIS_VALUE                  (CapSense_dsRam.wdgtList.button28.hysteresis)
#define CapSense_BUTTON28_HYSTERESIS_OFFSET                 (566u)
#define CapSense_BUTTON28_HYSTERESIS_SIZE                   (1u)
#define CapSense_BUTTON28_HYSTERESIS_PARAM_ID               (0x4C9C0236u)

#define CapSense_BUTTON28_ON_DEBOUNCE_VALUE                 (CapSense_dsRam.wdgtList.button28.onDebounce)
#define CapSense_BUTTON28_ON_DEBOUNCE_OFFSET                (567u)
#define CapSense_BUTTON28_ON_DEBOUNCE_SIZE                  (1u)
#define CapSense_BUTTON28_ON_DEBOUNCE_PARAM_ID              (0x4A9C0237u)

#define CapSense_BUTTON28_LOW_BSLN_RST_VALUE                (CapSense_dsRam.wdgtList.button28.lowBslnRst)
#define CapSense_BUTTON28_LOW_BSLN_RST_OFFSET               (568u)
#define CapSense_BUTTON28_LOW_BSLN_RST_SIZE                 (1u)
#define CapSense_BUTTON28_LOW_BSLN_RST_PARAM_ID             (0x439C0238u)

#define CapSense_BUTTON28_BSLN_COEFF_VALUE                  (CapSense_dsRam.wdgtList.button28.bslnCoeff)
#define CapSense_BUTTON28_BSLN_COEFF_OFFSET                 (569u)
#define CapSense_BUTTON28_BSLN_COEFF_SIZE                   (1u)
#define CapSense_BUTTON28_BSLN_COEFF_PARAM_ID               (0x6E9C0239u)

#define CapSense_BUTTON28_IDAC_MOD0_VALUE                   (CapSense_dsRam.wdgtList.button28.idacMod[0u])
#define CapSense_BUTTON28_IDAC_MOD0_OFFSET                  (570u)
#define CapSense_BUTTON28_IDAC_MOD0_SIZE                    (1u)
#define CapSense_BUTTON28_IDAC_MOD0_PARAM_ID                (0x421C023Au)

#define CapSense_BUTTON28_SNS_CLK_VALUE                     (CapSense_dsRam.wdgtList.button28.snsClk)
#define CapSense_BUTTON28_SNS_CLK_OFFSET                    (571u)
#define CapSense_BUTTON28_SNS_CLK_SIZE                      (1u)
#define CapSense_BUTTON28_SNS_CLK_PARAM_ID                  (0x499C023Bu)

#define CapSense_BUTTON28_SNS_CLK_SOURCE_VALUE              (CapSense_dsRam.wdgtList.button28.snsClkSource)
#define CapSense_BUTTON28_SNS_CLK_SOURCE_OFFSET             (572u)
#define CapSense_BUTTON28_SNS_CLK_SOURCE_SIZE               (1u)
#define CapSense_BUTTON28_SNS_CLK_SOURCE_PARAM_ID           (0x429C023Cu)

#define CapSense_BUTTON28_FINGER_CAP_VALUE                  (CapSense_dsRam.wdgtList.button28.fingerCap)
#define CapSense_BUTTON28_FINGER_CAP_OFFSET                 (574u)
#define CapSense_BUTTON28_FINGER_CAP_SIZE                   (2u)
#define CapSense_BUTTON28_FINGER_CAP_PARAM_ID               (0xA01C023Eu)

#define CapSense_BUTTON28_SIGPFC_VALUE                      (CapSense_dsRam.wdgtList.button28.sigPFC)
#define CapSense_BUTTON28_SIGPFC_OFFSET                     (576u)
#define CapSense_BUTTON28_SIGPFC_SIZE                       (2u)
#define CapSense_BUTTON28_SIGPFC_PARAM_ID                   (0xAD1C0240u)

#define CapSense_BUTTON29_RESOLUTION_VALUE                  (CapSense_dsRam.wdgtList.button29.resolution)
#define CapSense_BUTTON29_RESOLUTION_OFFSET                 (578u)
#define CapSense_BUTTON29_RESOLUTION_SIZE                   (2u)
#define CapSense_BUTTON29_RESOLUTION_PARAM_ID               (0x849D0242u)

#define CapSense_BUTTON29_FINGER_TH_VALUE                   (CapSense_dsRam.wdgtList.button29.fingerTh)
#define CapSense_BUTTON29_FINGER_TH_OFFSET                  (580u)
#define CapSense_BUTTON29_FINGER_TH_SIZE                    (2u)
#define CapSense_BUTTON29_FINGER_TH_PARAM_ID                (0x899D0244u)

#define CapSense_BUTTON29_NOISE_TH_VALUE                    (CapSense_dsRam.wdgtList.button29.noiseTh)
#define CapSense_BUTTON29_NOISE_TH_OFFSET                   (582u)
#define CapSense_BUTTON29_NOISE_TH_SIZE                     (1u)
#define CapSense_BUTTON29_NOISE_TH_PARAM_ID                 (0x4D9D0246u)

#define CapSense_BUTTON29_NNOISE_TH_VALUE                   (CapSense_dsRam.wdgtList.button29.nNoiseTh)
#define CapSense_BUTTON29_NNOISE_TH_OFFSET                  (583u)
#define CapSense_BUTTON29_NNOISE_TH_SIZE                    (1u)
#define CapSense_BUTTON29_NNOISE_TH_PARAM_ID                (0x4B9D0247u)

#define CapSense_BUTTON29_HYSTERESIS_VALUE                  (CapSense_dsRam.wdgtList.button29.hysteresis)
#define CapSense_BUTTON29_HYSTERESIS_OFFSET                 (584u)
#define CapSense_BUTTON29_HYSTERESIS_SIZE                   (1u)
#define CapSense_BUTTON29_HYSTERESIS_PARAM_ID               (0x429D0248u)

#define CapSense_BUTTON29_ON_DEBOUNCE_VALUE                 (CapSense_dsRam.wdgtList.button29.onDebounce)
#define CapSense_BUTTON29_ON_DEBOUNCE_OFFSET                (585u)
#define CapSense_BUTTON29_ON_DEBOUNCE_SIZE                  (1u)
#define CapSense_BUTTON29_ON_DEBOUNCE_PARAM_ID              (0x449D0249u)

#define CapSense_BUTTON29_LOW_BSLN_RST_VALUE                (CapSense_dsRam.wdgtList.button29.lowBslnRst)
#define CapSense_BUTTON29_LOW_BSLN_RST_OFFSET               (586u)
#define CapSense_BUTTON29_LOW_BSLN_RST_SIZE                 (1u)
#define CapSense_BUTTON29_LOW_BSLN_RST_PARAM_ID             (0x4E9D024Au)

#define CapSense_BUTTON29_BSLN_COEFF_VALUE                  (CapSense_dsRam.wdgtList.button29.bslnCoeff)
#define CapSense_BUTTON29_BSLN_COEFF_OFFSET                 (587u)
#define CapSense_BUTTON29_BSLN_COEFF_SIZE                   (1u)
#define CapSense_BUTTON29_BSLN_COEFF_PARAM_ID               (0x639D024Bu)

#define CapSense_BUTTON29_IDAC_MOD0_VALUE                   (CapSense_dsRam.wdgtList.button29.idacMod[0u])
#define CapSense_BUTTON29_IDAC_MOD0_OFFSET                  (588u)
#define CapSense_BUTTON29_IDAC_MOD0_SIZE                    (1u)
#define CapSense_BUTTON29_IDAC_MOD0_PARAM_ID                (0x4E1D024Cu)

#define CapSense_BUTTON29_SNS_CLK_VALUE                     (CapSense_dsRam.wdgtList.button29.snsClk)
#define CapSense_BUTTON29_SNS_CLK_OFFSET                    (589u)
#define CapSense_BUTTON29_SNS_CLK_SIZE                      (1u)
#define CapSense_BUTTON29_SNS_CLK_PARAM_ID                  (0x459D024Du)

#define CapSense_BUTTON29_SNS_CLK_SOURCE_VALUE              (CapSense_dsRam.wdgtList.button29.snsClkSource)
#define CapSense_BUTTON29_SNS_CLK_SOURCE_OFFSET             (590u)
#define CapSense_BUTTON29_SNS_CLK_SOURCE_SIZE               (1u)
#define CapSense_BUTTON29_SNS_CLK_SOURCE_PARAM_ID           (0x4F9D024Eu)

#define CapSense_BUTTON29_FINGER_CAP_VALUE                  (CapSense_dsRam.wdgtList.button29.fingerCap)
#define CapSense_BUTTON29_FINGER_CAP_OFFSET                 (592u)
#define CapSense_BUTTON29_FINGER_CAP_SIZE                   (2u)
#define CapSense_BUTTON29_FINGER_CAP_PARAM_ID               (0xAB1D0250u)

#define CapSense_BUTTON29_SIGPFC_VALUE                      (CapSense_dsRam.wdgtList.button29.sigPFC)
#define CapSense_BUTTON29_SIGPFC_OFFSET                     (594u)
#define CapSense_BUTTON29_SIGPFC_SIZE                       (2u)
#define CapSense_BUTTON29_SIGPFC_PARAM_ID                   (0xA71D0252u)

#define CapSense_BUTTON30_RESOLUTION_VALUE                  (CapSense_dsRam.wdgtList.button30.resolution)
#define CapSense_BUTTON30_RESOLUTION_OFFSET                 (596u)
#define CapSense_BUTTON30_RESOLUTION_SIZE                   (2u)
#define CapSense_BUTTON30_RESOLUTION_PARAM_ID               (0x899E0254u)

#define CapSense_BUTTON30_FINGER_TH_VALUE                   (CapSense_dsRam.wdgtList.button30.fingerTh)
#define CapSense_BUTTON30_FINGER_TH_OFFSET                  (598u)
#define CapSense_BUTTON30_FINGER_TH_SIZE                    (2u)
#define CapSense_BUTTON30_FINGER_TH_PARAM_ID                (0x859E0256u)

#define CapSense_BUTTON30_NOISE_TH_VALUE                    (CapSense_dsRam.wdgtList.button30.noiseTh)
#define CapSense_BUTTON30_NOISE_TH_OFFSET                   (600u)
#define CapSense_BUTTON30_NOISE_TH_SIZE                     (1u)
#define CapSense_BUTTON30_NOISE_TH_PARAM_ID                 (0x429E0258u)

#define CapSense_BUTTON30_NNOISE_TH_VALUE                   (CapSense_dsRam.wdgtList.button30.nNoiseTh)
#define CapSense_BUTTON30_NNOISE_TH_OFFSET                  (601u)
#define CapSense_BUTTON30_NNOISE_TH_SIZE                    (1u)
#define CapSense_BUTTON30_NNOISE_TH_PARAM_ID                (0x449E0259u)

#define CapSense_BUTTON30_HYSTERESIS_VALUE                  (CapSense_dsRam.wdgtList.button30.hysteresis)
#define CapSense_BUTTON30_HYSTERESIS_OFFSET                 (602u)
#define CapSense_BUTTON30_HYSTERESIS_SIZE                   (1u)
#define CapSense_BUTTON30_HYSTERESIS_PARAM_ID               (0x4E9E025Au)

#define CapSense_BUTTON30_ON_DEBOUNCE_VALUE                 (CapSense_dsRam.wdgtList.button30.onDebounce)
#define CapSense_BUTTON30_ON_DEBOUNCE_OFFSET                (603u)
#define CapSense_BUTTON30_ON_DEBOUNCE_SIZE                  (1u)
#define CapSense_BUTTON30_ON_DEBOUNCE_PARAM_ID              (0x489E025Bu)

#define CapSense_BUTTON30_LOW_BSLN_RST_VALUE                (CapSense_dsRam.wdgtList.button30.lowBslnRst)
#define CapSense_BUTTON30_LOW_BSLN_RST_OFFSET               (604u)
#define CapSense_BUTTON30_LOW_BSLN_RST_SIZE                 (1u)
#define CapSense_BUTTON30_LOW_BSLN_RST_PARAM_ID             (0x439E025Cu)

#define CapSense_BUTTON30_BSLN_COEFF_VALUE                  (CapSense_dsRam.wdgtList.button30.bslnCoeff)
#define CapSense_BUTTON30_BSLN_COEFF_OFFSET                 (605u)
#define CapSense_BUTTON30_BSLN_COEFF_SIZE                   (1u)
#define CapSense_BUTTON30_BSLN_COEFF_PARAM_ID               (0x6E9E025Du)

#define CapSense_BUTTON30_IDAC_MOD0_VALUE                   (CapSense_dsRam.wdgtList.button30.idacMod[0u])
#define CapSense_BUTTON30_IDAC_MOD0_OFFSET                  (606u)
#define CapSense_BUTTON30_IDAC_MOD0_SIZE                    (1u)
#define CapSense_BUTTON30_IDAC_MOD0_PARAM_ID                (0x421E025Eu)

#define CapSense_BUTTON30_SNS_CLK_VALUE                     (CapSense_dsRam.wdgtList.button30.snsClk)
#define CapSense_BUTTON30_SNS_CLK_OFFSET                    (607u)
#define CapSense_BUTTON30_SNS_CLK_SIZE                      (1u)
#define CapSense_BUTTON30_SNS_CLK_PARAM_ID                  (0x499E025Fu)

#define CapSense_BUTTON30_SNS_CLK_SOURCE_VALUE              (CapSense_dsRam.wdgtList.button30.snsClkSource)
#define CapSense_BUTTON30_SNS_CLK_SOURCE_OFFSET             (608u)
#define CapSense_BUTTON30_SNS_CLK_SOURCE_SIZE               (1u)
#define CapSense_BUTTON30_SNS_CLK_SOURCE_PARAM_ID           (0x4F9E0260u)

#define CapSense_BUTTON30_FINGER_CAP_VALUE                  (CapSense_dsRam.wdgtList.button30.fingerCap)
#define CapSense_BUTTON30_FINGER_CAP_OFFSET                 (610u)
#define CapSense_BUTTON30_FINGER_CAP_SIZE                   (2u)
#define CapSense_BUTTON30_FINGER_CAP_PARAM_ID               (0xAD1E0262u)

#define CapSense_BUTTON30_SIGPFC_VALUE                      (CapSense_dsRam.wdgtList.button30.sigPFC)
#define CapSense_BUTTON30_SIGPFC_OFFSET                     (612u)
#define CapSense_BUTTON30_SIGPFC_SIZE                       (2u)
#define CapSense_BUTTON30_SIGPFC_PARAM_ID                   (0xA01E0264u)

#define CapSense_BUTTON31_RESOLUTION_VALUE                  (CapSense_dsRam.wdgtList.button31.resolution)
#define CapSense_BUTTON31_RESOLUTION_OFFSET                 (614u)
#define CapSense_BUTTON31_RESOLUTION_SIZE                   (2u)
#define CapSense_BUTTON31_RESOLUTION_PARAM_ID               (0x899F0266u)

#define CapSense_BUTTON31_FINGER_TH_VALUE                   (CapSense_dsRam.wdgtList.button31.fingerTh)
#define CapSense_BUTTON31_FINGER_TH_OFFSET                  (616u)
#define CapSense_BUTTON31_FINGER_TH_SIZE                    (2u)
#define CapSense_BUTTON31_FINGER_TH_PARAM_ID                (0x869F0268u)

#define CapSense_BUTTON31_NOISE_TH_VALUE                    (CapSense_dsRam.wdgtList.button31.noiseTh)
#define CapSense_BUTTON31_NOISE_TH_OFFSET                   (618u)
#define CapSense_BUTTON31_NOISE_TH_SIZE                     (1u)
#define CapSense_BUTTON31_NOISE_TH_PARAM_ID                 (0x429F026Au)

#define CapSense_BUTTON31_NNOISE_TH_VALUE                   (CapSense_dsRam.wdgtList.button31.nNoiseTh)
#define CapSense_BUTTON31_NNOISE_TH_OFFSET                  (619u)
#define CapSense_BUTTON31_NNOISE_TH_SIZE                    (1u)
#define CapSense_BUTTON31_NNOISE_TH_PARAM_ID                (0x449F026Bu)

#define CapSense_BUTTON31_HYSTERESIS_VALUE                  (CapSense_dsRam.wdgtList.button31.hysteresis)
#define CapSense_BUTTON31_HYSTERESIS_OFFSET                 (620u)
#define CapSense_BUTTON31_HYSTERESIS_SIZE                   (1u)
#define CapSense_BUTTON31_HYSTERESIS_PARAM_ID               (0x4F9F026Cu)

#define CapSense_BUTTON31_ON_DEBOUNCE_VALUE                 (CapSense_dsRam.wdgtList.button31.onDebounce)
#define CapSense_BUTTON31_ON_DEBOUNCE_OFFSET                (621u)
#define CapSense_BUTTON31_ON_DEBOUNCE_SIZE                  (1u)
#define CapSense_BUTTON31_ON_DEBOUNCE_PARAM_ID              (0x499F026Du)

#define CapSense_BUTTON31_LOW_BSLN_RST_VALUE                (CapSense_dsRam.wdgtList.button31.lowBslnRst)
#define CapSense_BUTTON31_LOW_BSLN_RST_OFFSET               (622u)
#define CapSense_BUTTON31_LOW_BSLN_RST_SIZE                 (1u)
#define CapSense_BUTTON31_LOW_BSLN_RST_PARAM_ID             (0x439F026Eu)

#define CapSense_BUTTON31_BSLN_COEFF_VALUE                  (CapSense_dsRam.wdgtList.button31.bslnCoeff)
#define CapSense_BUTTON31_BSLN_COEFF_OFFSET                 (623u)
#define CapSense_BUTTON31_BSLN_COEFF_SIZE                   (1u)
#define CapSense_BUTTON31_BSLN_COEFF_PARAM_ID               (0x6E9F026Fu)

#define CapSense_BUTTON31_IDAC_MOD0_VALUE                   (CapSense_dsRam.wdgtList.button31.idacMod[0u])
#define CapSense_BUTTON31_IDAC_MOD0_OFFSET                  (624u)
#define CapSense_BUTTON31_IDAC_MOD0_SIZE                    (1u)
#define CapSense_BUTTON31_IDAC_MOD0_PARAM_ID                (0x441F0270u)

#define CapSense_BUTTON31_SNS_CLK_VALUE                     (CapSense_dsRam.wdgtList.button31.snsClk)
#define CapSense_BUTTON31_SNS_CLK_OFFSET                    (625u)
#define CapSense_BUTTON31_SNS_CLK_SIZE                      (1u)
#define CapSense_BUTTON31_SNS_CLK_PARAM_ID                  (0x4F9F0271u)

#define CapSense_BUTTON31_SNS_CLK_SOURCE_VALUE              (CapSense_dsRam.wdgtList.button31.snsClkSource)
#define CapSense_BUTTON31_SNS_CLK_SOURCE_OFFSET             (626u)
#define CapSense_BUTTON31_SNS_CLK_SOURCE_SIZE               (1u)
#define CapSense_BUTTON31_SNS_CLK_SOURCE_PARAM_ID           (0x459F0272u)

#define CapSense_BUTTON31_FINGER_CAP_VALUE                  (CapSense_dsRam.wdgtList.button31.fingerCap)
#define CapSense_BUTTON31_FINGER_CAP_OFFSET                 (628u)
#define CapSense_BUTTON31_FINGER_CAP_SIZE                   (2u)
#define CapSense_BUTTON31_FINGER_CAP_PARAM_ID               (0xA61F0274u)

#define CapSense_BUTTON31_SIGPFC_VALUE                      (CapSense_dsRam.wdgtList.button31.sigPFC)
#define CapSense_BUTTON31_SIGPFC_OFFSET                     (630u)
#define CapSense_BUTTON31_SIGPFC_SIZE                       (2u)
#define CapSense_BUTTON31_SIGPFC_PARAM_ID                   (0xAA1F0276u)

#define CapSense_BUTTON0_SNS0_RAW0_VALUE                    (CapSense_dsRam.snsList.button0[0u].raw[0u])
#define CapSense_BUTTON0_SNS0_RAW0_OFFSET                   (632u)
#define CapSense_BUTTON0_SNS0_RAW0_SIZE                     (2u)
#define CapSense_BUTTON0_SNS0_RAW0_PARAM_ID                 (0x88000278u)

#define CapSense_BUTTON0_SNS0_BSLN0_VALUE                   (CapSense_dsRam.snsList.button0[0u].bsln[0u])
#define CapSense_BUTTON0_SNS0_BSLN0_OFFSET                  (634u)
#define CapSense_BUTTON0_SNS0_BSLN0_SIZE                    (2u)
#define CapSense_BUTTON0_SNS0_BSLN0_PARAM_ID                (0x8400027Au)

#define CapSense_BUTTON0_SNS0_BSLN_EXT0_VALUE               (CapSense_dsRam.snsList.button0[0u].bslnExt[0u])
#define CapSense_BUTTON0_SNS0_BSLN_EXT0_OFFSET              (636u)
#define CapSense_BUTTON0_SNS0_BSLN_EXT0_SIZE                (1u)
#define CapSense_BUTTON0_SNS0_BSLN_EXT0_PARAM_ID            (0x4100027Cu)

#define CapSense_BUTTON0_SNS0_DIFF_VALUE                    (CapSense_dsRam.snsList.button0[0u].diff)
#define CapSense_BUTTON0_SNS0_DIFF_OFFSET                   (638u)
#define CapSense_BUTTON0_SNS0_DIFF_SIZE                     (2u)
#define CapSense_BUTTON0_SNS0_DIFF_PARAM_ID                 (0x8500027Eu)

#define CapSense_BUTTON0_SNS0_NEG_BSLN_RST_CNT0_VALUE       (CapSense_dsRam.snsList.button0[0u].negBslnRstCnt[0u])
#define CapSense_BUTTON0_SNS0_NEG_BSLN_RST_CNT0_OFFSET      (640u)
#define CapSense_BUTTON0_SNS0_NEG_BSLN_RST_CNT0_SIZE        (1u)
#define CapSense_BUTTON0_SNS0_NEG_BSLN_RST_CNT0_PARAM_ID    (0x43000280u)

#define CapSense_BUTTON0_SNS0_IDAC_COMP0_VALUE              (CapSense_dsRam.snsList.button0[0u].idacComp[0u])
#define CapSense_BUTTON0_SNS0_IDAC_COMP0_OFFSET             (641u)
#define CapSense_BUTTON0_SNS0_IDAC_COMP0_SIZE               (1u)
#define CapSense_BUTTON0_SNS0_IDAC_COMP0_PARAM_ID           (0x45000281u)

#define CapSense_BUTTON1_SNS0_RAW0_VALUE                    (CapSense_dsRam.snsList.button1[0u].raw[0u])
#define CapSense_BUTTON1_SNS0_RAW0_OFFSET                   (642u)
#define CapSense_BUTTON1_SNS0_RAW0_SIZE                     (2u)
#define CapSense_BUTTON1_SNS0_RAW0_PARAM_ID                 (0x87000282u)

#define CapSense_BUTTON1_SNS0_BSLN0_VALUE                   (CapSense_dsRam.snsList.button1[0u].bsln[0u])
#define CapSense_BUTTON1_SNS0_BSLN0_OFFSET                  (644u)
#define CapSense_BUTTON1_SNS0_BSLN0_SIZE                    (2u)
#define CapSense_BUTTON1_SNS0_BSLN0_PARAM_ID                (0x8A000284u)

#define CapSense_BUTTON1_SNS0_BSLN_EXT0_VALUE               (CapSense_dsRam.snsList.button1[0u].bslnExt[0u])
#define CapSense_BUTTON1_SNS0_BSLN_EXT0_OFFSET              (646u)
#define CapSense_BUTTON1_SNS0_BSLN_EXT0_SIZE                (1u)
#define CapSense_BUTTON1_SNS0_BSLN_EXT0_PARAM_ID            (0x4E000286u)

#define CapSense_BUTTON1_SNS0_DIFF_VALUE                    (CapSense_dsRam.snsList.button1[0u].diff)
#define CapSense_BUTTON1_SNS0_DIFF_OFFSET                   (648u)
#define CapSense_BUTTON1_SNS0_DIFF_SIZE                     (2u)
#define CapSense_BUTTON1_SNS0_DIFF_PARAM_ID                 (0x89000288u)

#define CapSense_BUTTON1_SNS0_NEG_BSLN_RST_CNT0_VALUE       (CapSense_dsRam.snsList.button1[0u].negBslnRstCnt[0u])
#define CapSense_BUTTON1_SNS0_NEG_BSLN_RST_CNT0_OFFSET      (650u)
#define CapSense_BUTTON1_SNS0_NEG_BSLN_RST_CNT0_SIZE        (1u)
#define CapSense_BUTTON1_SNS0_NEG_BSLN_RST_CNT0_PARAM_ID    (0x4D00028Au)

#define CapSense_BUTTON1_SNS0_IDAC_COMP0_VALUE              (CapSense_dsRam.snsList.button1[0u].idacComp[0u])
#define CapSense_BUTTON1_SNS0_IDAC_COMP0_OFFSET             (651u)
#define CapSense_BUTTON1_SNS0_IDAC_COMP0_SIZE               (1u)
#define CapSense_BUTTON1_SNS0_IDAC_COMP0_PARAM_ID           (0x4B00028Bu)

#define CapSense_BUTTON2_SNS0_RAW0_VALUE                    (CapSense_dsRam.snsList.button2[0u].raw[0u])
#define CapSense_BUTTON2_SNS0_RAW0_OFFSET                   (652u)
#define CapSense_BUTTON2_SNS0_RAW0_SIZE                     (2u)
#define CapSense_BUTTON2_SNS0_RAW0_PARAM_ID                 (0x8800028Cu)

#define CapSense_BUTTON2_SNS0_BSLN0_VALUE                   (CapSense_dsRam.snsList.button2[0u].bsln[0u])
#define CapSense_BUTTON2_SNS0_BSLN0_OFFSET                  (654u)
#define CapSense_BUTTON2_SNS0_BSLN0_SIZE                    (2u)
#define CapSense_BUTTON2_SNS0_BSLN0_PARAM_ID                (0x8400028Eu)

#define CapSense_BUTTON2_SNS0_BSLN_EXT0_VALUE               (CapSense_dsRam.snsList.button2[0u].bslnExt[0u])
#define CapSense_BUTTON2_SNS0_BSLN_EXT0_OFFSET              (656u)
#define CapSense_BUTTON2_SNS0_BSLN_EXT0_SIZE                (1u)
#define CapSense_BUTTON2_SNS0_BSLN_EXT0_PARAM_ID            (0x46000290u)

#define CapSense_BUTTON2_SNS0_DIFF_VALUE                    (CapSense_dsRam.snsList.button2[0u].diff)
#define CapSense_BUTTON2_SNS0_DIFF_OFFSET                   (658u)
#define CapSense_BUTTON2_SNS0_DIFF_SIZE                     (2u)
#define CapSense_BUTTON2_SNS0_DIFF_PARAM_ID                 (0x82000292u)

#define CapSense_BUTTON2_SNS0_NEG_BSLN_RST_CNT0_VALUE       (CapSense_dsRam.snsList.button2[0u].negBslnRstCnt[0u])
#define CapSense_BUTTON2_SNS0_NEG_BSLN_RST_CNT0_OFFSET      (660u)
#define CapSense_BUTTON2_SNS0_NEG_BSLN_RST_CNT0_SIZE        (1u)
#define CapSense_BUTTON2_SNS0_NEG_BSLN_RST_CNT0_PARAM_ID    (0x47000294u)

#define CapSense_BUTTON2_SNS0_IDAC_COMP0_VALUE              (CapSense_dsRam.snsList.button2[0u].idacComp[0u])
#define CapSense_BUTTON2_SNS0_IDAC_COMP0_OFFSET             (661u)
#define CapSense_BUTTON2_SNS0_IDAC_COMP0_SIZE               (1u)
#define CapSense_BUTTON2_SNS0_IDAC_COMP0_PARAM_ID           (0x41000295u)

#define CapSense_BUTTON3_SNS0_RAW0_VALUE                    (CapSense_dsRam.snsList.button3[0u].raw[0u])
#define CapSense_BUTTON3_SNS0_RAW0_OFFSET                   (662u)
#define CapSense_BUTTON3_SNS0_RAW0_SIZE                     (2u)
#define CapSense_BUTTON3_SNS0_RAW0_PARAM_ID                 (0x83000296u)

#define CapSense_BUTTON3_SNS0_BSLN0_VALUE                   (CapSense_dsRam.snsList.button3[0u].bsln[0u])
#define CapSense_BUTTON3_SNS0_BSLN0_OFFSET                  (664u)
#define CapSense_BUTTON3_SNS0_BSLN0_SIZE                    (2u)
#define CapSense_BUTTON3_SNS0_BSLN0_PARAM_ID                (0x8C000298u)

#define CapSense_BUTTON3_SNS0_BSLN_EXT0_VALUE               (CapSense_dsRam.snsList.button3[0u].bslnExt[0u])
#define CapSense_BUTTON3_SNS0_BSLN_EXT0_OFFSET              (666u)
#define CapSense_BUTTON3_SNS0_BSLN_EXT0_SIZE                (1u)
#define CapSense_BUTTON3_SNS0_BSLN_EXT0_PARAM_ID            (0x4800029Au)

#define CapSense_BUTTON3_SNS0_DIFF_VALUE                    (CapSense_dsRam.snsList.button3[0u].diff)
#define CapSense_BUTTON3_SNS0_DIFF_OFFSET                   (668u)
#define CapSense_BUTTON3_SNS0_DIFF_SIZE                     (2u)
#define CapSense_BUTTON3_SNS0_DIFF_PARAM_ID                 (0x8D00029Cu)

#define CapSense_BUTTON3_SNS0_NEG_BSLN_RST_CNT0_VALUE       (CapSense_dsRam.snsList.button3[0u].negBslnRstCnt[0u])
#define CapSense_BUTTON3_SNS0_NEG_BSLN_RST_CNT0_OFFSET      (670u)
#define CapSense_BUTTON3_SNS0_NEG_BSLN_RST_CNT0_SIZE        (1u)
#define CapSense_BUTTON3_SNS0_NEG_BSLN_RST_CNT0_PARAM_ID    (0x4900029Eu)

#define CapSense_BUTTON3_SNS0_IDAC_COMP0_VALUE              (CapSense_dsRam.snsList.button3[0u].idacComp[0u])
#define CapSense_BUTTON3_SNS0_IDAC_COMP0_OFFSET             (671u)
#define CapSense_BUTTON3_SNS0_IDAC_COMP0_SIZE               (1u)
#define CapSense_BUTTON3_SNS0_IDAC_COMP0_PARAM_ID           (0x4F00029Fu)

#define CapSense_BUTTON4_SNS0_RAW0_VALUE                    (CapSense_dsRam.snsList.button4[0u].raw[0u])
#define CapSense_BUTTON4_SNS0_RAW0_OFFSET                   (672u)
#define CapSense_BUTTON4_SNS0_RAW0_SIZE                     (2u)
#define CapSense_BUTTON4_SNS0_RAW0_PARAM_ID                 (0x810002A0u)

#define CapSense_BUTTON4_SNS0_BSLN0_VALUE                   (CapSense_dsRam.snsList.button4[0u].bsln[0u])
#define CapSense_BUTTON4_SNS0_BSLN0_OFFSET                  (674u)
#define CapSense_BUTTON4_SNS0_BSLN0_SIZE                    (2u)
#define CapSense_BUTTON4_SNS0_BSLN0_PARAM_ID                (0x8D0002A2u)

#define CapSense_BUTTON4_SNS0_BSLN_EXT0_VALUE               (CapSense_dsRam.snsList.button4[0u].bslnExt[0u])
#define CapSense_BUTTON4_SNS0_BSLN_EXT0_OFFSET              (676u)
#define CapSense_BUTTON4_SNS0_BSLN_EXT0_SIZE                (1u)
#define CapSense_BUTTON4_SNS0_BSLN_EXT0_PARAM_ID            (0x480002A4u)

#define CapSense_BUTTON4_SNS0_DIFF_VALUE                    (CapSense_dsRam.snsList.button4[0u].diff)
#define CapSense_BUTTON4_SNS0_DIFF_OFFSET                   (678u)
#define CapSense_BUTTON4_SNS0_DIFF_SIZE                     (2u)
#define CapSense_BUTTON4_SNS0_DIFF_PARAM_ID                 (0x8C0002A6u)

#define CapSense_BUTTON4_SNS0_NEG_BSLN_RST_CNT0_VALUE       (CapSense_dsRam.snsList.button4[0u].negBslnRstCnt[0u])
#define CapSense_BUTTON4_SNS0_NEG_BSLN_RST_CNT0_OFFSET      (680u)
#define CapSense_BUTTON4_SNS0_NEG_BSLN_RST_CNT0_SIZE        (1u)
#define CapSense_BUTTON4_SNS0_NEG_BSLN_RST_CNT0_PARAM_ID    (0x4B0002A8u)

#define CapSense_BUTTON4_SNS0_IDAC_COMP0_VALUE              (CapSense_dsRam.snsList.button4[0u].idacComp[0u])
#define CapSense_BUTTON4_SNS0_IDAC_COMP0_OFFSET             (681u)
#define CapSense_BUTTON4_SNS0_IDAC_COMP0_SIZE               (1u)
#define CapSense_BUTTON4_SNS0_IDAC_COMP0_PARAM_ID           (0x4D0002A9u)

#define CapSense_BUTTON5_SNS0_RAW0_VALUE                    (CapSense_dsRam.snsList.button5[0u].raw[0u])
#define CapSense_BUTTON5_SNS0_RAW0_OFFSET                   (682u)
#define CapSense_BUTTON5_SNS0_RAW0_SIZE                     (2u)
#define CapSense_BUTTON5_SNS0_RAW0_PARAM_ID                 (0x8F0002AAu)

#define CapSense_BUTTON5_SNS0_BSLN0_VALUE                   (CapSense_dsRam.snsList.button5[0u].bsln[0u])
#define CapSense_BUTTON5_SNS0_BSLN0_OFFSET                  (684u)
#define CapSense_BUTTON5_SNS0_BSLN0_SIZE                    (2u)
#define CapSense_BUTTON5_SNS0_BSLN0_PARAM_ID                (0x820002ACu)

#define CapSense_BUTTON5_SNS0_BSLN_EXT0_VALUE               (CapSense_dsRam.snsList.button5[0u].bslnExt[0u])
#define CapSense_BUTTON5_SNS0_BSLN_EXT0_OFFSET              (686u)
#define CapSense_BUTTON5_SNS0_BSLN_EXT0_SIZE                (1u)
#define CapSense_BUTTON5_SNS0_BSLN_EXT0_PARAM_ID            (0x460002AEu)

#define CapSense_BUTTON5_SNS0_DIFF_VALUE                    (CapSense_dsRam.snsList.button5[0u].diff)
#define CapSense_BUTTON5_SNS0_DIFF_OFFSET                   (688u)
#define CapSense_BUTTON5_SNS0_DIFF_SIZE                     (2u)
#define CapSense_BUTTON5_SNS0_DIFF_PARAM_ID                 (0x840002B0u)

#define CapSense_BUTTON5_SNS0_NEG_BSLN_RST_CNT0_VALUE       (CapSense_dsRam.snsList.button5[0u].negBslnRstCnt[0u])
#define CapSense_BUTTON5_SNS0_NEG_BSLN_RST_CNT0_OFFSET      (690u)
#define CapSense_BUTTON5_SNS0_NEG_BSLN_RST_CNT0_SIZE        (1u)
#define CapSense_BUTTON5_SNS0_NEG_BSLN_RST_CNT0_PARAM_ID    (0x400002B2u)

#define CapSense_BUTTON5_SNS0_IDAC_COMP0_VALUE              (CapSense_dsRam.snsList.button5[0u].idacComp[0u])
#define CapSense_BUTTON5_SNS0_IDAC_COMP0_OFFSET             (691u)
#define CapSense_BUTTON5_SNS0_IDAC_COMP0_SIZE               (1u)
#define CapSense_BUTTON5_SNS0_IDAC_COMP0_PARAM_ID           (0x460002B3u)

#define CapSense_BUTTON6_SNS0_RAW0_VALUE                    (CapSense_dsRam.snsList.button6[0u].raw[0u])
#define CapSense_BUTTON6_SNS0_RAW0_OFFSET                   (692u)
#define CapSense_BUTTON6_SNS0_RAW0_SIZE                     (2u)
#define CapSense_BUTTON6_SNS0_RAW0_PARAM_ID                 (0x850002B4u)

#define CapSense_BUTTON6_SNS0_BSLN0_VALUE                   (CapSense_dsRam.snsList.button6[0u].bsln[0u])
#define CapSense_BUTTON6_SNS0_BSLN0_OFFSET                  (694u)
#define CapSense_BUTTON6_SNS0_BSLN0_SIZE                    (2u)
#define CapSense_BUTTON6_SNS0_BSLN0_PARAM_ID                (0x890002B6u)

#define CapSense_BUTTON6_SNS0_BSLN_EXT0_VALUE               (CapSense_dsRam.snsList.button6[0u].bslnExt[0u])
#define CapSense_BUTTON6_SNS0_BSLN_EXT0_OFFSET              (696u)
#define CapSense_BUTTON6_SNS0_BSLN_EXT0_SIZE                (1u)
#define CapSense_BUTTON6_SNS0_BSLN_EXT0_PARAM_ID            (0x4E0002B8u)

#define CapSense_BUTTON6_SNS0_DIFF_VALUE                    (CapSense_dsRam.snsList.button6[0u].diff)
#define CapSense_BUTTON6_SNS0_DIFF_OFFSET                   (698u)
#define CapSense_BUTTON6_SNS0_DIFF_SIZE                     (2u)
#define CapSense_BUTTON6_SNS0_DIFF_PARAM_ID                 (0x8A0002BAu)

#define CapSense_BUTTON6_SNS0_NEG_BSLN_RST_CNT0_VALUE       (CapSense_dsRam.snsList.button6[0u].negBslnRstCnt[0u])
#define CapSense_BUTTON6_SNS0_NEG_BSLN_RST_CNT0_OFFSET      (700u)
#define CapSense_BUTTON6_SNS0_NEG_BSLN_RST_CNT0_SIZE        (1u)
#define CapSense_BUTTON6_SNS0_NEG_BSLN_RST_CNT0_PARAM_ID    (0x4F0002BCu)

#define CapSense_BUTTON6_SNS0_IDAC_COMP0_VALUE              (CapSense_dsRam.snsList.button6[0u].idacComp[0u])
#define CapSense_BUTTON6_SNS0_IDAC_COMP0_OFFSET             (701u)
#define CapSense_BUTTON6_SNS0_IDAC_COMP0_SIZE               (1u)
#define CapSense_BUTTON6_SNS0_IDAC_COMP0_PARAM_ID           (0x490002BDu)

#define CapSense_BUTTON7_SNS0_RAW0_VALUE                    (CapSense_dsRam.snsList.button7[0u].raw[0u])
#define CapSense_BUTTON7_SNS0_RAW0_OFFSET                   (702u)
#define CapSense_BUTTON7_SNS0_RAW0_SIZE                     (2u)
#define CapSense_BUTTON7_SNS0_RAW0_PARAM_ID                 (0x8B0002BEu)

#define CapSense_BUTTON7_SNS0_BSLN0_VALUE                   (CapSense_dsRam.snsList.button7[0u].bsln[0u])
#define CapSense_BUTTON7_SNS0_BSLN0_OFFSET                  (704u)
#define CapSense_BUTTON7_SNS0_BSLN0_SIZE                    (2u)
#define CapSense_BUTTON7_SNS0_BSLN0_PARAM_ID                (0x860002C0u)

#define CapSense_BUTTON7_SNS0_BSLN_EXT0_VALUE               (CapSense_dsRam.snsList.button7[0u].bslnExt[0u])
#define CapSense_BUTTON7_SNS0_BSLN_EXT0_OFFSET              (706u)
#define CapSense_BUTTON7_SNS0_BSLN_EXT0_SIZE                (1u)
#define CapSense_BUTTON7_SNS0_BSLN_EXT0_PARAM_ID            (0x420002C2u)

#define CapSense_BUTTON7_SNS0_DIFF_VALUE                    (CapSense_dsRam.snsList.button7[0u].diff)
#define CapSense_BUTTON7_SNS0_DIFF_OFFSET                   (708u)
#define CapSense_BUTTON7_SNS0_DIFF_SIZE                     (2u)
#define CapSense_BUTTON7_SNS0_DIFF_PARAM_ID                 (0x870002C4u)

#define CapSense_BUTTON7_SNS0_NEG_BSLN_RST_CNT0_VALUE       (CapSense_dsRam.snsList.button7[0u].negBslnRstCnt[0u])
#define CapSense_BUTTON7_SNS0_NEG_BSLN_RST_CNT0_OFFSET      (710u)
#define CapSense_BUTTON7_SNS0_NEG_BSLN_RST_CNT0_SIZE        (1u)
#define CapSense_BUTTON7_SNS0_NEG_BSLN_RST_CNT0_PARAM_ID    (0x430002C6u)

#define CapSense_BUTTON7_SNS0_IDAC_COMP0_VALUE              (CapSense_dsRam.snsList.button7[0u].idacComp[0u])
#define CapSense_BUTTON7_SNS0_IDAC_COMP0_OFFSET             (711u)
#define CapSense_BUTTON7_SNS0_IDAC_COMP0_SIZE               (1u)
#define CapSense_BUTTON7_SNS0_IDAC_COMP0_PARAM_ID           (0x450002C7u)

#define CapSense_BUTTON8_SNS0_RAW0_VALUE                    (CapSense_dsRam.snsList.button8[0u].raw[0u])
#define CapSense_BUTTON8_SNS0_RAW0_OFFSET                   (712u)
#define CapSense_BUTTON8_SNS0_RAW0_SIZE                     (2u)
#define CapSense_BUTTON8_SNS0_RAW0_PARAM_ID                 (0x840002C8u)

#define CapSense_BUTTON8_SNS0_BSLN0_VALUE                   (CapSense_dsRam.snsList.button8[0u].bsln[0u])
#define CapSense_BUTTON8_SNS0_BSLN0_OFFSET                  (714u)
#define CapSense_BUTTON8_SNS0_BSLN0_SIZE                    (2u)
#define CapSense_BUTTON8_SNS0_BSLN0_PARAM_ID                (0x880002CAu)

#define CapSense_BUTTON8_SNS0_BSLN_EXT0_VALUE               (CapSense_dsRam.snsList.button8[0u].bslnExt[0u])
#define CapSense_BUTTON8_SNS0_BSLN_EXT0_OFFSET              (716u)
#define CapSense_BUTTON8_SNS0_BSLN_EXT0_SIZE                (1u)
#define CapSense_BUTTON8_SNS0_BSLN_EXT0_PARAM_ID            (0x4D0002CCu)

#define CapSense_BUTTON8_SNS0_DIFF_VALUE                    (CapSense_dsRam.snsList.button8[0u].diff)
#define CapSense_BUTTON8_SNS0_DIFF_OFFSET                   (718u)
#define CapSense_BUTTON8_SNS0_DIFF_SIZE                     (2u)
#define CapSense_BUTTON8_SNS0_DIFF_PARAM_ID                 (0x890002CEu)

#define CapSense_BUTTON8_SNS0_NEG_BSLN_RST_CNT0_VALUE       (CapSense_dsRam.snsList.button8[0u].negBslnRstCnt[0u])
#define CapSense_BUTTON8_SNS0_NEG_BSLN_RST_CNT0_OFFSET      (720u)
#define CapSense_BUTTON8_SNS0_NEG_BSLN_RST_CNT0_SIZE        (1u)
#define CapSense_BUTTON8_SNS0_NEG_BSLN_RST_CNT0_PARAM_ID    (0x4B0002D0u)

#define CapSense_BUTTON8_SNS0_IDAC_COMP0_VALUE              (CapSense_dsRam.snsList.button8[0u].idacComp[0u])
#define CapSense_BUTTON8_SNS0_IDAC_COMP0_OFFSET             (721u)
#define CapSense_BUTTON8_SNS0_IDAC_COMP0_SIZE               (1u)
#define CapSense_BUTTON8_SNS0_IDAC_COMP0_PARAM_ID           (0x4D0002D1u)

#define CapSense_BUTTON9_SNS0_RAW0_VALUE                    (CapSense_dsRam.snsList.button9[0u].raw[0u])
#define CapSense_BUTTON9_SNS0_RAW0_OFFSET                   (722u)
#define CapSense_BUTTON9_SNS0_RAW0_SIZE                     (2u)
#define CapSense_BUTTON9_SNS0_RAW0_PARAM_ID                 (0x8F0002D2u)

#define CapSense_BUTTON9_SNS0_BSLN0_VALUE                   (CapSense_dsRam.snsList.button9[0u].bsln[0u])
#define CapSense_BUTTON9_SNS0_BSLN0_OFFSET                  (724u)
#define CapSense_BUTTON9_SNS0_BSLN0_SIZE                    (2u)
#define CapSense_BUTTON9_SNS0_BSLN0_PARAM_ID                (0x820002D4u)

#define CapSense_BUTTON9_SNS0_BSLN_EXT0_VALUE               (CapSense_dsRam.snsList.button9[0u].bslnExt[0u])
#define CapSense_BUTTON9_SNS0_BSLN_EXT0_OFFSET              (726u)
#define CapSense_BUTTON9_SNS0_BSLN_EXT0_SIZE                (1u)
#define CapSense_BUTTON9_SNS0_BSLN_EXT0_PARAM_ID            (0x460002D6u)

#define CapSense_BUTTON9_SNS0_DIFF_VALUE                    (CapSense_dsRam.snsList.button9[0u].diff)
#define CapSense_BUTTON9_SNS0_DIFF_OFFSET                   (728u)
#define CapSense_BUTTON9_SNS0_DIFF_SIZE                     (2u)
#define CapSense_BUTTON9_SNS0_DIFF_PARAM_ID                 (0x810002D8u)

#define CapSense_BUTTON9_SNS0_NEG_BSLN_RST_CNT0_VALUE       (CapSense_dsRam.snsList.button9[0u].negBslnRstCnt[0u])
#define CapSense_BUTTON9_SNS0_NEG_BSLN_RST_CNT0_OFFSET      (730u)
#define CapSense_BUTTON9_SNS0_NEG_BSLN_RST_CNT0_SIZE        (1u)
#define CapSense_BUTTON9_SNS0_NEG_BSLN_RST_CNT0_PARAM_ID    (0x450002DAu)

#define CapSense_BUTTON9_SNS0_IDAC_COMP0_VALUE              (CapSense_dsRam.snsList.button9[0u].idacComp[0u])
#define CapSense_BUTTON9_SNS0_IDAC_COMP0_OFFSET             (731u)
#define CapSense_BUTTON9_SNS0_IDAC_COMP0_SIZE               (1u)
#define CapSense_BUTTON9_SNS0_IDAC_COMP0_PARAM_ID           (0x430002DBu)

#define CapSense_BUTTON10_SNS0_RAW0_VALUE                   (CapSense_dsRam.snsList.button10[0u].raw[0u])
#define CapSense_BUTTON10_SNS0_RAW0_OFFSET                  (732u)
#define CapSense_BUTTON10_SNS0_RAW0_SIZE                    (2u)
#define CapSense_BUTTON10_SNS0_RAW0_PARAM_ID                (0x800002DCu)

#define CapSense_BUTTON10_SNS0_BSLN0_VALUE                  (CapSense_dsRam.snsList.button10[0u].bsln[0u])
#define CapSense_BUTTON10_SNS0_BSLN0_OFFSET                 (734u)
#define CapSense_BUTTON10_SNS0_BSLN0_SIZE                   (2u)
#define CapSense_BUTTON10_SNS0_BSLN0_PARAM_ID               (0x8C0002DEu)

#define CapSense_BUTTON10_SNS0_BSLN_EXT0_VALUE              (CapSense_dsRam.snsList.button10[0u].bslnExt[0u])
#define CapSense_BUTTON10_SNS0_BSLN_EXT0_OFFSET             (736u)
#define CapSense_BUTTON10_SNS0_BSLN_EXT0_SIZE               (1u)
#define CapSense_BUTTON10_SNS0_BSLN_EXT0_PARAM_ID           (0x440002E0u)

#define CapSense_BUTTON10_SNS0_DIFF_VALUE                   (CapSense_dsRam.snsList.button10[0u].diff)
#define CapSense_BUTTON10_SNS0_DIFF_OFFSET                  (738u)
#define CapSense_BUTTON10_SNS0_DIFF_SIZE                    (2u)
#define CapSense_BUTTON10_SNS0_DIFF_PARAM_ID                (0x800002E2u)

#define CapSense_BUTTON10_SNS0_NEG_BSLN_RST_CNT0_VALUE      (CapSense_dsRam.snsList.button10[0u].negBslnRstCnt[0u])
#define CapSense_BUTTON10_SNS0_NEG_BSLN_RST_CNT0_OFFSET     (740u)
#define CapSense_BUTTON10_SNS0_NEG_BSLN_RST_CNT0_SIZE       (1u)
#define CapSense_BUTTON10_SNS0_NEG_BSLN_RST_CNT0_PARAM_ID   (0x450002E4u)

#define CapSense_BUTTON10_SNS0_IDAC_COMP0_VALUE             (CapSense_dsRam.snsList.button10[0u].idacComp[0u])
#define CapSense_BUTTON10_SNS0_IDAC_COMP0_OFFSET            (741u)
#define CapSense_BUTTON10_SNS0_IDAC_COMP0_SIZE              (1u)
#define CapSense_BUTTON10_SNS0_IDAC_COMP0_PARAM_ID          (0x430002E5u)

#define CapSense_BUTTON11_SNS0_RAW0_VALUE                   (CapSense_dsRam.snsList.button11[0u].raw[0u])
#define CapSense_BUTTON11_SNS0_RAW0_OFFSET                  (742u)
#define CapSense_BUTTON11_SNS0_RAW0_SIZE                    (2u)
#define CapSense_BUTTON11_SNS0_RAW0_PARAM_ID                (0x810002E6u)

#define CapSense_BUTTON11_SNS0_BSLN0_VALUE                  (CapSense_dsRam.snsList.button11[0u].bsln[0u])
#define CapSense_BUTTON11_SNS0_BSLN0_OFFSET                 (744u)
#define CapSense_BUTTON11_SNS0_BSLN0_SIZE                   (2u)
#define CapSense_BUTTON11_SNS0_BSLN0_PARAM_ID               (0x8E0002E8u)

#define CapSense_BUTTON11_SNS0_BSLN_EXT0_VALUE              (CapSense_dsRam.snsList.button11[0u].bslnExt[0u])
#define CapSense_BUTTON11_SNS0_BSLN_EXT0_OFFSET             (746u)
#define CapSense_BUTTON11_SNS0_BSLN_EXT0_SIZE               (1u)
#define CapSense_BUTTON11_SNS0_BSLN_EXT0_PARAM_ID           (0x4A0002EAu)

#define CapSense_BUTTON11_SNS0_DIFF_VALUE                   (CapSense_dsRam.snsList.button11[0u].diff)
#define CapSense_BUTTON11_SNS0_DIFF_OFFSET                  (748u)
#define CapSense_BUTTON11_SNS0_DIFF_SIZE                    (2u)
#define CapSense_BUTTON11_SNS0_DIFF_PARAM_ID                (0x8F0002ECu)

#define CapSense_BUTTON11_SNS0_NEG_BSLN_RST_CNT0_VALUE      (CapSense_dsRam.snsList.button11[0u].negBslnRstCnt[0u])
#define CapSense_BUTTON11_SNS0_NEG_BSLN_RST_CNT0_OFFSET     (750u)
#define CapSense_BUTTON11_SNS0_NEG_BSLN_RST_CNT0_SIZE       (1u)
#define CapSense_BUTTON11_SNS0_NEG_BSLN_RST_CNT0_PARAM_ID   (0x4B0002EEu)

#define CapSense_BUTTON11_SNS0_IDAC_COMP0_VALUE             (CapSense_dsRam.snsList.button11[0u].idacComp[0u])
#define CapSense_BUTTON11_SNS0_IDAC_COMP0_OFFSET            (751u)
#define CapSense_BUTTON11_SNS0_IDAC_COMP0_SIZE              (1u)
#define CapSense_BUTTON11_SNS0_IDAC_COMP0_PARAM_ID          (0x4D0002EFu)

#define CapSense_BUTTON12_SNS0_RAW0_VALUE                   (CapSense_dsRam.snsList.button12[0u].raw[0u])
#define CapSense_BUTTON12_SNS0_RAW0_OFFSET                  (752u)
#define CapSense_BUTTON12_SNS0_RAW0_SIZE                    (2u)
#define CapSense_BUTTON12_SNS0_RAW0_PARAM_ID                (0x890002F0u)

#define CapSense_BUTTON12_SNS0_BSLN0_VALUE                  (CapSense_dsRam.snsList.button12[0u].bsln[0u])
#define CapSense_BUTTON12_SNS0_BSLN0_OFFSET                 (754u)
#define CapSense_BUTTON12_SNS0_BSLN0_SIZE                   (2u)
#define CapSense_BUTTON12_SNS0_BSLN0_PARAM_ID               (0x850002F2u)

#define CapSense_BUTTON12_SNS0_BSLN_EXT0_VALUE              (CapSense_dsRam.snsList.button12[0u].bslnExt[0u])
#define CapSense_BUTTON12_SNS0_BSLN_EXT0_OFFSET             (756u)
#define CapSense_BUTTON12_SNS0_BSLN_EXT0_SIZE               (1u)
#define CapSense_BUTTON12_SNS0_BSLN_EXT0_PARAM_ID           (0x400002F4u)

#define CapSense_BUTTON12_SNS0_DIFF_VALUE                   (CapSense_dsRam.snsList.button12[0u].diff)
#define CapSense_BUTTON12_SNS0_DIFF_OFFSET                  (758u)
#define CapSense_BUTTON12_SNS0_DIFF_SIZE                    (2u)
#define CapSense_BUTTON12_SNS0_DIFF_PARAM_ID                (0x840002F6u)

#define CapSense_BUTTON12_SNS0_NEG_BSLN_RST_CNT0_VALUE      (CapSense_dsRam.snsList.button12[0u].negBslnRstCnt[0u])
#define CapSense_BUTTON12_SNS0_NEG_BSLN_RST_CNT0_OFFSET     (760u)
#define CapSense_BUTTON12_SNS0_NEG_BSLN_RST_CNT0_SIZE       (1u)
#define CapSense_BUTTON12_SNS0_NEG_BSLN_RST_CNT0_PARAM_ID   (0x430002F8u)

#define CapSense_BUTTON12_SNS0_IDAC_COMP0_VALUE             (CapSense_dsRam.snsList.button12[0u].idacComp[0u])
#define CapSense_BUTTON12_SNS0_IDAC_COMP0_OFFSET            (761u)
#define CapSense_BUTTON12_SNS0_IDAC_COMP0_SIZE              (1u)
#define CapSense_BUTTON12_SNS0_IDAC_COMP0_PARAM_ID          (0x450002F9u)

#define CapSense_BUTTON13_SNS0_RAW0_VALUE                   (CapSense_dsRam.snsList.button13[0u].raw[0u])
#define CapSense_BUTTON13_SNS0_RAW0_OFFSET                  (762u)
#define CapSense_BUTTON13_SNS0_RAW0_SIZE                    (2u)
#define CapSense_BUTTON13_SNS0_RAW0_PARAM_ID                (0x870002FAu)

#define CapSense_BUTTON13_SNS0_BSLN0_VALUE                  (CapSense_dsRam.snsList.button13[0u].bsln[0u])
#define CapSense_BUTTON13_SNS0_BSLN0_OFFSET                 (764u)
#define CapSense_BUTTON13_SNS0_BSLN0_SIZE                   (2u)
#define CapSense_BUTTON13_SNS0_BSLN0_PARAM_ID               (0x8A0002FCu)

#define CapSense_BUTTON13_SNS0_BSLN_EXT0_VALUE              (CapSense_dsRam.snsList.button13[0u].bslnExt[0u])
#define CapSense_BUTTON13_SNS0_BSLN_EXT0_OFFSET             (766u)
#define CapSense_BUTTON13_SNS0_BSLN_EXT0_SIZE               (1u)
#define CapSense_BUTTON13_SNS0_BSLN_EXT0_PARAM_ID           (0x4E0002FEu)

#define CapSense_BUTTON13_SNS0_DIFF_VALUE                   (CapSense_dsRam.snsList.button13[0u].diff)
#define CapSense_BUTTON13_SNS0_DIFF_OFFSET                  (768u)
#define CapSense_BUTTON13_SNS0_DIFF_SIZE                    (2u)
#define CapSense_BUTTON13_SNS0_DIFF_PARAM_ID                (0x83000300u)

#define CapSense_BUTTON13_SNS0_NEG_BSLN_RST_CNT0_VALUE      (CapSense_dsRam.snsList.button13[0u].negBslnRstCnt[0u])
#define CapSense_BUTTON13_SNS0_NEG_BSLN_RST_CNT0_OFFSET     (770u)
#define CapSense_BUTTON13_SNS0_NEG_BSLN_RST_CNT0_SIZE       (1u)
#define CapSense_BUTTON13_SNS0_NEG_BSLN_RST_CNT0_PARAM_ID   (0x47000302u)

#define CapSense_BUTTON13_SNS0_IDAC_COMP0_VALUE             (CapSense_dsRam.snsList.button13[0u].idacComp[0u])
#define CapSense_BUTTON13_SNS0_IDAC_COMP0_OFFSET            (771u)
#define CapSense_BUTTON13_SNS0_IDAC_COMP0_SIZE              (1u)
#define CapSense_BUTTON13_SNS0_IDAC_COMP0_PARAM_ID          (0x41000303u)

#define CapSense_BUTTON14_SNS0_RAW0_VALUE                   (CapSense_dsRam.snsList.button14[0u].raw[0u])
#define CapSense_BUTTON14_SNS0_RAW0_OFFSET                  (772u)
#define CapSense_BUTTON14_SNS0_RAW0_SIZE                    (2u)
#define CapSense_BUTTON14_SNS0_RAW0_PARAM_ID                (0x82000304u)

#define CapSense_BUTTON14_SNS0_BSLN0_VALUE                  (CapSense_dsRam.snsList.button14[0u].bsln[0u])
#define CapSense_BUTTON14_SNS0_BSLN0_OFFSET                 (774u)
#define CapSense_BUTTON14_SNS0_BSLN0_SIZE                   (2u)
#define CapSense_BUTTON14_SNS0_BSLN0_PARAM_ID               (0x8E000306u)

#define CapSense_BUTTON14_SNS0_BSLN_EXT0_VALUE              (CapSense_dsRam.snsList.button14[0u].bslnExt[0u])
#define CapSense_BUTTON14_SNS0_BSLN_EXT0_OFFSET             (776u)
#define CapSense_BUTTON14_SNS0_BSLN_EXT0_SIZE               (1u)
#define CapSense_BUTTON14_SNS0_BSLN_EXT0_PARAM_ID           (0x49000308u)

#define CapSense_BUTTON14_SNS0_DIFF_VALUE                   (CapSense_dsRam.snsList.button14[0u].diff)
#define CapSense_BUTTON14_SNS0_DIFF_OFFSET                  (778u)
#define CapSense_BUTTON14_SNS0_DIFF_SIZE                    (2u)
#define CapSense_BUTTON14_SNS0_DIFF_PARAM_ID                (0x8D00030Au)

#define CapSense_BUTTON14_SNS0_NEG_BSLN_RST_CNT0_VALUE      (CapSense_dsRam.snsList.button14[0u].negBslnRstCnt[0u])
#define CapSense_BUTTON14_SNS0_NEG_BSLN_RST_CNT0_OFFSET     (780u)
#define CapSense_BUTTON14_SNS0_NEG_BSLN_RST_CNT0_SIZE       (1u)
#define CapSense_BUTTON14_SNS0_NEG_BSLN_RST_CNT0_PARAM_ID   (0x4800030Cu)

#define CapSense_BUTTON14_SNS0_IDAC_COMP0_VALUE             (CapSense_dsRam.snsList.button14[0u].idacComp[0u])
#define CapSense_BUTTON14_SNS0_IDAC_COMP0_OFFSET            (781u)
#define CapSense_BUTTON14_SNS0_IDAC_COMP0_SIZE              (1u)
#define CapSense_BUTTON14_SNS0_IDAC_COMP0_PARAM_ID          (0x4E00030Du)

#define CapSense_BUTTON15_SNS0_RAW0_VALUE                   (CapSense_dsRam.snsList.button15[0u].raw[0u])
#define CapSense_BUTTON15_SNS0_RAW0_OFFSET                  (782u)
#define CapSense_BUTTON15_SNS0_RAW0_SIZE                    (2u)
#define CapSense_BUTTON15_SNS0_RAW0_PARAM_ID                (0x8C00030Eu)

#define CapSense_BUTTON15_SNS0_BSLN0_VALUE                  (CapSense_dsRam.snsList.button15[0u].bsln[0u])
#define CapSense_BUTTON15_SNS0_BSLN0_OFFSET                 (784u)
#define CapSense_BUTTON15_SNS0_BSLN0_SIZE                   (2u)
#define CapSense_BUTTON15_SNS0_BSLN0_PARAM_ID               (0x86000310u)

#define CapSense_BUTTON15_SNS0_BSLN_EXT0_VALUE              (CapSense_dsRam.snsList.button15[0u].bslnExt[0u])
#define CapSense_BUTTON15_SNS0_BSLN_EXT0_OFFSET             (786u)
#define CapSense_BUTTON15_SNS0_BSLN_EXT0_SIZE               (1u)
#define CapSense_BUTTON15_SNS0_BSLN_EXT0_PARAM_ID           (0x42000312u)

#define CapSense_BUTTON15_SNS0_DIFF_VALUE                   (CapSense_dsRam.snsList.button15[0u].diff)
#define CapSense_BUTTON15_SNS0_DIFF_OFFSET                  (788u)
#define CapSense_BUTTON15_SNS0_DIFF_SIZE                    (2u)
#define CapSense_BUTTON15_SNS0_DIFF_PARAM_ID                (0x87000314u)

#define CapSense_BUTTON15_SNS0_NEG_BSLN_RST_CNT0_VALUE      (CapSense_dsRam.snsList.button15[0u].negBslnRstCnt[0u])
#define CapSense_BUTTON15_SNS0_NEG_BSLN_RST_CNT0_OFFSET     (790u)
#define CapSense_BUTTON15_SNS0_NEG_BSLN_RST_CNT0_SIZE       (1u)
#define CapSense_BUTTON15_SNS0_NEG_BSLN_RST_CNT0_PARAM_ID   (0x43000316u)

#define CapSense_BUTTON15_SNS0_IDAC_COMP0_VALUE             (CapSense_dsRam.snsList.button15[0u].idacComp[0u])
#define CapSense_BUTTON15_SNS0_IDAC_COMP0_OFFSET            (791u)
#define CapSense_BUTTON15_SNS0_IDAC_COMP0_SIZE              (1u)
#define CapSense_BUTTON15_SNS0_IDAC_COMP0_PARAM_ID          (0x45000317u)

#define CapSense_BUTTON16_SNS0_RAW0_VALUE                   (CapSense_dsRam.snsList.button16[0u].raw[0u])
#define CapSense_BUTTON16_SNS0_RAW0_OFFSET                  (792u)
#define CapSense_BUTTON16_SNS0_RAW0_SIZE                    (2u)
#define CapSense_BUTTON16_SNS0_RAW0_PARAM_ID                (0x84000318u)

#define CapSense_BUTTON16_SNS0_BSLN0_VALUE                  (CapSense_dsRam.snsList.button16[0u].bsln[0u])
#define CapSense_BUTTON16_SNS0_BSLN0_OFFSET                 (794u)
#define CapSense_BUTTON16_SNS0_BSLN0_SIZE                   (2u)
#define CapSense_BUTTON16_SNS0_BSLN0_PARAM_ID               (0x8800031Au)

#define CapSense_BUTTON16_SNS0_BSLN_EXT0_VALUE              (CapSense_dsRam.snsList.button16[0u].bslnExt[0u])
#define CapSense_BUTTON16_SNS0_BSLN_EXT0_OFFSET             (796u)
#define CapSense_BUTTON16_SNS0_BSLN_EXT0_SIZE               (1u)
#define CapSense_BUTTON16_SNS0_BSLN_EXT0_PARAM_ID           (0x4D00031Cu)

#define CapSense_BUTTON16_SNS0_DIFF_VALUE                   (CapSense_dsRam.snsList.button16[0u].diff)
#define CapSense_BUTTON16_SNS0_DIFF_OFFSET                  (798u)
#define CapSense_BUTTON16_SNS0_DIFF_SIZE                    (2u)
#define CapSense_BUTTON16_SNS0_DIFF_PARAM_ID                (0x8900031Eu)

#define CapSense_BUTTON16_SNS0_NEG_BSLN_RST_CNT0_VALUE      (CapSense_dsRam.snsList.button16[0u].negBslnRstCnt[0u])
#define CapSense_BUTTON16_SNS0_NEG_BSLN_RST_CNT0_OFFSET     (800u)
#define CapSense_BUTTON16_SNS0_NEG_BSLN_RST_CNT0_SIZE       (1u)
#define CapSense_BUTTON16_SNS0_NEG_BSLN_RST_CNT0_PARAM_ID   (0x41000320u)

#define CapSense_BUTTON16_SNS0_IDAC_COMP0_VALUE             (CapSense_dsRam.snsList.button16[0u].idacComp[0u])
#define CapSense_BUTTON16_SNS0_IDAC_COMP0_OFFSET            (801u)
#define CapSense_BUTTON16_SNS0_IDAC_COMP0_SIZE              (1u)
#define CapSense_BUTTON16_SNS0_IDAC_COMP0_PARAM_ID          (0x47000321u)

#define CapSense_BUTTON17_SNS0_RAW0_VALUE                   (CapSense_dsRam.snsList.button17[0u].raw[0u])
#define CapSense_BUTTON17_SNS0_RAW0_OFFSET                  (802u)
#define CapSense_BUTTON17_SNS0_RAW0_SIZE                    (2u)
#define CapSense_BUTTON17_SNS0_RAW0_PARAM_ID                (0x85000322u)

#define CapSense_BUTTON17_SNS0_BSLN0_VALUE                  (CapSense_dsRam.snsList.button17[0u].bsln[0u])
#define CapSense_BUTTON17_SNS0_BSLN0_OFFSET                 (804u)
#define CapSense_BUTTON17_SNS0_BSLN0_SIZE                   (2u)
#define CapSense_BUTTON17_SNS0_BSLN0_PARAM_ID               (0x88000324u)

#define CapSense_BUTTON17_SNS0_BSLN_EXT0_VALUE              (CapSense_dsRam.snsList.button17[0u].bslnExt[0u])
#define CapSense_BUTTON17_SNS0_BSLN_EXT0_OFFSET             (806u)
#define CapSense_BUTTON17_SNS0_BSLN_EXT0_SIZE               (1u)
#define CapSense_BUTTON17_SNS0_BSLN_EXT0_PARAM_ID           (0x4C000326u)

#define CapSense_BUTTON17_SNS0_DIFF_VALUE                   (CapSense_dsRam.snsList.button17[0u].diff)
#define CapSense_BUTTON17_SNS0_DIFF_OFFSET                  (808u)
#define CapSense_BUTTON17_SNS0_DIFF_SIZE                    (2u)
#define CapSense_BUTTON17_SNS0_DIFF_PARAM_ID                (0x8B000328u)

#define CapSense_BUTTON17_SNS0_NEG_BSLN_RST_CNT0_VALUE      (CapSense_dsRam.snsList.button17[0u].negBslnRstCnt[0u])
#define CapSense_BUTTON17_SNS0_NEG_BSLN_RST_CNT0_OFFSET     (810u)
#define CapSense_BUTTON17_SNS0_NEG_BSLN_RST_CNT0_SIZE       (1u)
#define CapSense_BUTTON17_SNS0_NEG_BSLN_RST_CNT0_PARAM_ID   (0x4F00032Au)

#define CapSense_BUTTON17_SNS0_IDAC_COMP0_VALUE             (CapSense_dsRam.snsList.button17[0u].idacComp[0u])
#define CapSense_BUTTON17_SNS0_IDAC_COMP0_OFFSET            (811u)
#define CapSense_BUTTON17_SNS0_IDAC_COMP0_SIZE              (1u)
#define CapSense_BUTTON17_SNS0_IDAC_COMP0_PARAM_ID          (0x4900032Bu)

#define CapSense_BUTTON18_SNS0_RAW0_VALUE                   (CapSense_dsRam.snsList.button18[0u].raw[0u])
#define CapSense_BUTTON18_SNS0_RAW0_OFFSET                  (812u)
#define CapSense_BUTTON18_SNS0_RAW0_SIZE                    (2u)
#define CapSense_BUTTON18_SNS0_RAW0_PARAM_ID                (0x8A00032Cu)

#define CapSense_BUTTON18_SNS0_BSLN0_VALUE                  (CapSense_dsRam.snsList.button18[0u].bsln[0u])
#define CapSense_BUTTON18_SNS0_BSLN0_OFFSET                 (814u)
#define CapSense_BUTTON18_SNS0_BSLN0_SIZE                   (2u)
#define CapSense_BUTTON18_SNS0_BSLN0_PARAM_ID               (0x8600032Eu)

#define CapSense_BUTTON18_SNS0_BSLN_EXT0_VALUE              (CapSense_dsRam.snsList.button18[0u].bslnExt[0u])
#define CapSense_BUTTON18_SNS0_BSLN_EXT0_OFFSET             (816u)
#define CapSense_BUTTON18_SNS0_BSLN_EXT0_SIZE               (1u)
#define CapSense_BUTTON18_SNS0_BSLN_EXT0_PARAM_ID           (0x44000330u)

#define CapSense_BUTTON18_SNS0_DIFF_VALUE                   (CapSense_dsRam.snsList.button18[0u].diff)
#define CapSense_BUTTON18_SNS0_DIFF_OFFSET                  (818u)
#define CapSense_BUTTON18_SNS0_DIFF_SIZE                    (2u)
#define CapSense_BUTTON18_SNS0_DIFF_PARAM_ID                (0x80000332u)

#define CapSense_BUTTON18_SNS0_NEG_BSLN_RST_CNT0_VALUE      (CapSense_dsRam.snsList.button18[0u].negBslnRstCnt[0u])
#define CapSense_BUTTON18_SNS0_NEG_BSLN_RST_CNT0_OFFSET     (820u)
#define CapSense_BUTTON18_SNS0_NEG_BSLN_RST_CNT0_SIZE       (1u)
#define CapSense_BUTTON18_SNS0_NEG_BSLN_RST_CNT0_PARAM_ID   (0x45000334u)

#define CapSense_BUTTON18_SNS0_IDAC_COMP0_VALUE             (CapSense_dsRam.snsList.button18[0u].idacComp[0u])
#define CapSense_BUTTON18_SNS0_IDAC_COMP0_OFFSET            (821u)
#define CapSense_BUTTON18_SNS0_IDAC_COMP0_SIZE              (1u)
#define CapSense_BUTTON18_SNS0_IDAC_COMP0_PARAM_ID          (0x43000335u)

#define CapSense_BUTTON19_SNS0_RAW0_VALUE                   (CapSense_dsRam.snsList.button19[0u].raw[0u])
#define CapSense_BUTTON19_SNS0_RAW0_OFFSET                  (822u)
#define CapSense_BUTTON19_SNS0_RAW0_SIZE                    (2u)
#define CapSense_BUTTON19_SNS0_RAW0_PARAM_ID                (0x81000336u)

#define CapSense_BUTTON19_SNS0_BSLN0_VALUE                  (CapSense_dsRam.snsList.button19[0u].bsln[0u])
#define CapSense_BUTTON19_SNS0_BSLN0_OFFSET                 (824u)
#define CapSense_BUTTON19_SNS0_BSLN0_SIZE                   (2u)
#define CapSense_BUTTON19_SNS0_BSLN0_PARAM_ID               (0x8E000338u)

#define CapSense_BUTTON19_SNS0_BSLN_EXT0_VALUE              (CapSense_dsRam.snsList.button19[0u].bslnExt[0u])
#define CapSense_BUTTON19_SNS0_BSLN_EXT0_OFFSET             (826u)
#define CapSense_BUTTON19_SNS0_BSLN_EXT0_SIZE               (1u)
#define CapSense_BUTTON19_SNS0_BSLN_EXT0_PARAM_ID           (0x4A00033Au)

#define CapSense_BUTTON19_SNS0_DIFF_VALUE                   (CapSense_dsRam.snsList.button19[0u].diff)
#define CapSense_BUTTON19_SNS0_DIFF_OFFSET                  (828u)
#define CapSense_BUTTON19_SNS0_DIFF_SIZE                    (2u)
#define CapSense_BUTTON19_SNS0_DIFF_PARAM_ID                (0x8F00033Cu)

#define CapSense_BUTTON19_SNS0_NEG_BSLN_RST_CNT0_VALUE      (CapSense_dsRam.snsList.button19[0u].negBslnRstCnt[0u])
#define CapSense_BUTTON19_SNS0_NEG_BSLN_RST_CNT0_OFFSET     (830u)
#define CapSense_BUTTON19_SNS0_NEG_BSLN_RST_CNT0_SIZE       (1u)
#define CapSense_BUTTON19_SNS0_NEG_BSLN_RST_CNT0_PARAM_ID   (0x4B00033Eu)

#define CapSense_BUTTON19_SNS0_IDAC_COMP0_VALUE             (CapSense_dsRam.snsList.button19[0u].idacComp[0u])
#define CapSense_BUTTON19_SNS0_IDAC_COMP0_OFFSET            (831u)
#define CapSense_BUTTON19_SNS0_IDAC_COMP0_SIZE              (1u)
#define CapSense_BUTTON19_SNS0_IDAC_COMP0_PARAM_ID          (0x4D00033Fu)

#define CapSense_BUTTON20_SNS0_RAW0_VALUE                   (CapSense_dsRam.snsList.button20[0u].raw[0u])
#define CapSense_BUTTON20_SNS0_RAW0_OFFSET                  (832u)
#define CapSense_BUTTON20_SNS0_RAW0_SIZE                    (2u)
#define CapSense_BUTTON20_SNS0_RAW0_PARAM_ID                (0x8E000340u)

#define CapSense_BUTTON20_SNS0_BSLN0_VALUE                  (CapSense_dsRam.snsList.button20[0u].bsln[0u])
#define CapSense_BUTTON20_SNS0_BSLN0_OFFSET                 (834u)
#define CapSense_BUTTON20_SNS0_BSLN0_SIZE                   (2u)
#define CapSense_BUTTON20_SNS0_BSLN0_PARAM_ID               (0x82000342u)

#define CapSense_BUTTON20_SNS0_BSLN_EXT0_VALUE              (CapSense_dsRam.snsList.button20[0u].bslnExt[0u])
#define CapSense_BUTTON20_SNS0_BSLN_EXT0_OFFSET             (836u)
#define CapSense_BUTTON20_SNS0_BSLN_EXT0_SIZE               (1u)
#define CapSense_BUTTON20_SNS0_BSLN_EXT0_PARAM_ID           (0x47000344u)

#define CapSense_BUTTON20_SNS0_DIFF_VALUE                   (CapSense_dsRam.snsList.button20[0u].diff)
#define CapSense_BUTTON20_SNS0_DIFF_OFFSET                  (838u)
#define CapSense_BUTTON20_SNS0_DIFF_SIZE                    (2u)
#define CapSense_BUTTON20_SNS0_DIFF_PARAM_ID                (0x83000346u)

#define CapSense_BUTTON20_SNS0_NEG_BSLN_RST_CNT0_VALUE      (CapSense_dsRam.snsList.button20[0u].negBslnRstCnt[0u])
#define CapSense_BUTTON20_SNS0_NEG_BSLN_RST_CNT0_OFFSET     (840u)
#define CapSense_BUTTON20_SNS0_NEG_BSLN_RST_CNT0_SIZE       (1u)
#define CapSense_BUTTON20_SNS0_NEG_BSLN_RST_CNT0_PARAM_ID   (0x44000348u)

#define CapSense_BUTTON20_SNS0_IDAC_COMP0_VALUE             (CapSense_dsRam.snsList.button20[0u].idacComp[0u])
#define CapSense_BUTTON20_SNS0_IDAC_COMP0_OFFSET            (841u)
#define CapSense_BUTTON20_SNS0_IDAC_COMP0_SIZE              (1u)
#define CapSense_BUTTON20_SNS0_IDAC_COMP0_PARAM_ID          (0x42000349u)

#define CapSense_BUTTON21_SNS0_RAW0_VALUE                   (CapSense_dsRam.snsList.button21[0u].raw[0u])
#define CapSense_BUTTON21_SNS0_RAW0_OFFSET                  (842u)
#define CapSense_BUTTON21_SNS0_RAW0_SIZE                    (2u)
#define CapSense_BUTTON21_SNS0_RAW0_PARAM_ID                (0x8000034Au)

#define CapSense_BUTTON21_SNS0_BSLN0_VALUE                  (CapSense_dsRam.snsList.button21[0u].bsln[0u])
#define CapSense_BUTTON21_SNS0_BSLN0_OFFSET                 (844u)
#define CapSense_BUTTON21_SNS0_BSLN0_SIZE                   (2u)
#define CapSense_BUTTON21_SNS0_BSLN0_PARAM_ID               (0x8D00034Cu)

#define CapSense_BUTTON21_SNS0_BSLN_EXT0_VALUE              (CapSense_dsRam.snsList.button21[0u].bslnExt[0u])
#define CapSense_BUTTON21_SNS0_BSLN_EXT0_OFFSET             (846u)
#define CapSense_BUTTON21_SNS0_BSLN_EXT0_SIZE               (1u)
#define CapSense_BUTTON21_SNS0_BSLN_EXT0_PARAM_ID           (0x4900034Eu)

#define CapSense_BUTTON21_SNS0_DIFF_VALUE                   (CapSense_dsRam.snsList.button21[0u].diff)
#define CapSense_BUTTON21_SNS0_DIFF_OFFSET                  (848u)
#define CapSense_BUTTON21_SNS0_DIFF_SIZE                    (2u)
#define CapSense_BUTTON21_SNS0_DIFF_PARAM_ID                (0x8B000350u)

#define CapSense_BUTTON21_SNS0_NEG_BSLN_RST_CNT0_VALUE      (CapSense_dsRam.snsList.button21[0u].negBslnRstCnt[0u])
#define CapSense_BUTTON21_SNS0_NEG_BSLN_RST_CNT0_OFFSET     (850u)
#define CapSense_BUTTON21_SNS0_NEG_BSLN_RST_CNT0_SIZE       (1u)
#define CapSense_BUTTON21_SNS0_NEG_BSLN_RST_CNT0_PARAM_ID   (0x4F000352u)

#define CapSense_BUTTON21_SNS0_IDAC_COMP0_VALUE             (CapSense_dsRam.snsList.button21[0u].idacComp[0u])
#define CapSense_BUTTON21_SNS0_IDAC_COMP0_OFFSET            (851u)
#define CapSense_BUTTON21_SNS0_IDAC_COMP0_SIZE              (1u)
#define CapSense_BUTTON21_SNS0_IDAC_COMP0_PARAM_ID          (0x49000353u)

#define CapSense_BUTTON22_SNS0_RAW0_VALUE                   (CapSense_dsRam.snsList.button22[0u].raw[0u])
#define CapSense_BUTTON22_SNS0_RAW0_OFFSET                  (852u)
#define CapSense_BUTTON22_SNS0_RAW0_SIZE                    (2u)
#define CapSense_BUTTON22_SNS0_RAW0_PARAM_ID                (0x8A000354u)

#define CapSense_BUTTON22_SNS0_BSLN0_VALUE                  (CapSense_dsRam.snsList.button22[0u].bsln[0u])
#define CapSense_BUTTON22_SNS0_BSLN0_OFFSET                 (854u)
#define CapSense_BUTTON22_SNS0_BSLN0_SIZE                   (2u)
#define CapSense_BUTTON22_SNS0_BSLN0_PARAM_ID               (0x86000356u)

#define CapSense_BUTTON22_SNS0_BSLN_EXT0_VALUE              (CapSense_dsRam.snsList.button22[0u].bslnExt[0u])
#define CapSense_BUTTON22_SNS0_BSLN_EXT0_OFFSET             (856u)
#define CapSense_BUTTON22_SNS0_BSLN_EXT0_SIZE               (1u)
#define CapSense_BUTTON22_SNS0_BSLN_EXT0_PARAM_ID           (0x41000358u)

#define CapSense_BUTTON22_SNS0_DIFF_VALUE                   (CapSense_dsRam.snsList.button22[0u].diff)
#define CapSense_BUTTON22_SNS0_DIFF_OFFSET                  (858u)
#define CapSense_BUTTON22_SNS0_DIFF_SIZE                    (2u)
#define CapSense_BUTTON22_SNS0_DIFF_PARAM_ID                (0x8500035Au)

#define CapSense_BUTTON22_SNS0_NEG_BSLN_RST_CNT0_VALUE      (CapSense_dsRam.snsList.button22[0u].negBslnRstCnt[0u])
#define CapSense_BUTTON22_SNS0_NEG_BSLN_RST_CNT0_OFFSET     (860u)
#define CapSense_BUTTON22_SNS0_NEG_BSLN_RST_CNT0_SIZE       (1u)
#define CapSense_BUTTON22_SNS0_NEG_BSLN_RST_CNT0_PARAM_ID   (0x4000035Cu)

#define CapSense_BUTTON22_SNS0_IDAC_COMP0_VALUE             (CapSense_dsRam.snsList.button22[0u].idacComp[0u])
#define CapSense_BUTTON22_SNS0_IDAC_COMP0_OFFSET            (861u)
#define CapSense_BUTTON22_SNS0_IDAC_COMP0_SIZE              (1u)
#define CapSense_BUTTON22_SNS0_IDAC_COMP0_PARAM_ID          (0x4600035Du)

#define CapSense_BUTTON23_SNS0_RAW0_VALUE                   (CapSense_dsRam.snsList.button23[0u].raw[0u])
#define CapSense_BUTTON23_SNS0_RAW0_OFFSET                  (862u)
#define CapSense_BUTTON23_SNS0_RAW0_SIZE                    (2u)
#define CapSense_BUTTON23_SNS0_RAW0_PARAM_ID                (0x8400035Eu)

#define CapSense_BUTTON23_SNS0_BSLN0_VALUE                  (CapSense_dsRam.snsList.button23[0u].bsln[0u])
#define CapSense_BUTTON23_SNS0_BSLN0_OFFSET                 (864u)
#define CapSense_BUTTON23_SNS0_BSLN0_SIZE                   (2u)
#define CapSense_BUTTON23_SNS0_BSLN0_PARAM_ID               (0x84000360u)

#define CapSense_BUTTON23_SNS0_BSLN_EXT0_VALUE              (CapSense_dsRam.snsList.button23[0u].bslnExt[0u])
#define CapSense_BUTTON23_SNS0_BSLN_EXT0_OFFSET             (866u)
#define CapSense_BUTTON23_SNS0_BSLN_EXT0_SIZE               (1u)
#define CapSense_BUTTON23_SNS0_BSLN_EXT0_PARAM_ID           (0x40000362u)

#define CapSense_BUTTON23_SNS0_DIFF_VALUE                   (CapSense_dsRam.snsList.button23[0u].diff)
#define CapSense_BUTTON23_SNS0_DIFF_OFFSET                  (868u)
#define CapSense_BUTTON23_SNS0_DIFF_SIZE                    (2u)
#define CapSense_BUTTON23_SNS0_DIFF_PARAM_ID                (0x85000364u)

#define CapSense_BUTTON23_SNS0_NEG_BSLN_RST_CNT0_VALUE      (CapSense_dsRam.snsList.button23[0u].negBslnRstCnt[0u])
#define CapSense_BUTTON23_SNS0_NEG_BSLN_RST_CNT0_OFFSET     (870u)
#define CapSense_BUTTON23_SNS0_NEG_BSLN_RST_CNT0_SIZE       (1u)
#define CapSense_BUTTON23_SNS0_NEG_BSLN_RST_CNT0_PARAM_ID   (0x41000366u)

#define CapSense_BUTTON23_SNS0_IDAC_COMP0_VALUE             (CapSense_dsRam.snsList.button23[0u].idacComp[0u])
#define CapSense_BUTTON23_SNS0_IDAC_COMP0_OFFSET            (871u)
#define CapSense_BUTTON23_SNS0_IDAC_COMP0_SIZE              (1u)
#define CapSense_BUTTON23_SNS0_IDAC_COMP0_PARAM_ID          (0x47000367u)

#define CapSense_BUTTON24_SNS0_RAW0_VALUE                   (CapSense_dsRam.snsList.button24[0u].raw[0u])
#define CapSense_BUTTON24_SNS0_RAW0_OFFSET                  (872u)
#define CapSense_BUTTON24_SNS0_RAW0_SIZE                    (2u)
#define CapSense_BUTTON24_SNS0_RAW0_PARAM_ID                (0x86000368u)

#define CapSense_BUTTON24_SNS0_BSLN0_VALUE                  (CapSense_dsRam.snsList.button24[0u].bsln[0u])
#define CapSense_BUTTON24_SNS0_BSLN0_OFFSET                 (874u)
#define CapSense_BUTTON24_SNS0_BSLN0_SIZE                   (2u)
#define CapSense_BUTTON24_SNS0_BSLN0_PARAM_ID               (0x8A00036Au)

#define CapSense_BUTTON24_SNS0_BSLN_EXT0_VALUE              (CapSense_dsRam.snsList.button24[0u].bslnExt[0u])
#define CapSense_BUTTON24_SNS0_BSLN_EXT0_OFFSET             (876u)
#define CapSense_BUTTON24_SNS0_BSLN_EXT0_SIZE               (1u)
#define CapSense_BUTTON24_SNS0_BSLN_EXT0_PARAM_ID           (0x4F00036Cu)

#define CapSense_BUTTON24_SNS0_DIFF_VALUE                   (CapSense_dsRam.snsList.button24[0u].diff)
#define CapSense_BUTTON24_SNS0_DIFF_OFFSET                  (878u)
#define CapSense_BUTTON24_SNS0_DIFF_SIZE                    (2u)
#define CapSense_BUTTON24_SNS0_DIFF_PARAM_ID                (0x8B00036Eu)

#define CapSense_BUTTON24_SNS0_NEG_BSLN_RST_CNT0_VALUE      (CapSense_dsRam.snsList.button24[0u].negBslnRstCnt[0u])
#define CapSense_BUTTON24_SNS0_NEG_BSLN_RST_CNT0_OFFSET     (880u)
#define CapSense_BUTTON24_SNS0_NEG_BSLN_RST_CNT0_SIZE       (1u)
#define CapSense_BUTTON24_SNS0_NEG_BSLN_RST_CNT0_PARAM_ID   (0x49000370u)

#define CapSense_BUTTON24_SNS0_IDAC_COMP0_VALUE             (CapSense_dsRam.snsList.button24[0u].idacComp[0u])
#define CapSense_BUTTON24_SNS0_IDAC_COMP0_OFFSET            (881u)
#define CapSense_BUTTON24_SNS0_IDAC_COMP0_SIZE              (1u)
#define CapSense_BUTTON24_SNS0_IDAC_COMP0_PARAM_ID          (0x4F000371u)

#define CapSense_BUTTON25_SNS0_RAW0_VALUE                   (CapSense_dsRam.snsList.button25[0u].raw[0u])
#define CapSense_BUTTON25_SNS0_RAW0_OFFSET                  (882u)
#define CapSense_BUTTON25_SNS0_RAW0_SIZE                    (2u)
#define CapSense_BUTTON25_SNS0_RAW0_PARAM_ID                (0x8D000372u)

#define CapSense_BUTTON25_SNS0_BSLN0_VALUE                  (CapSense_dsRam.snsList.button25[0u].bsln[0u])
#define CapSense_BUTTON25_SNS0_BSLN0_OFFSET                 (884u)
#define CapSense_BUTTON25_SNS0_BSLN0_SIZE                   (2u)
#define CapSense_BUTTON25_SNS0_BSLN0_PARAM_ID               (0x80000374u)

#define CapSense_BUTTON25_SNS0_BSLN_EXT0_VALUE              (CapSense_dsRam.snsList.button25[0u].bslnExt[0u])
#define CapSense_BUTTON25_SNS0_BSLN_EXT0_OFFSET             (886u)
#define CapSense_BUTTON25_SNS0_BSLN_EXT0_SIZE               (1u)
#define CapSense_BUTTON25_SNS0_BSLN_EXT0_PARAM_ID           (0x44000376u)

#define CapSense_BUTTON25_SNS0_DIFF_VALUE                   (CapSense_dsRam.snsList.button25[0u].diff)
#define CapSense_BUTTON25_SNS0_DIFF_OFFSET                  (888u)
#define CapSense_BUTTON25_SNS0_DIFF_SIZE                    (2u)
#define CapSense_BUTTON25_SNS0_DIFF_PARAM_ID                (0x83000378u)

#define CapSense_BUTTON25_SNS0_NEG_BSLN_RST_CNT0_VALUE      (CapSense_dsRam.snsList.button25[0u].negBslnRstCnt[0u])
#define CapSense_BUTTON25_SNS0_NEG_BSLN_RST_CNT0_OFFSET     (890u)
#define CapSense_BUTTON25_SNS0_NEG_BSLN_RST_CNT0_SIZE       (1u)
#define CapSense_BUTTON25_SNS0_NEG_BSLN_RST_CNT0_PARAM_ID   (0x4700037Au)

#define CapSense_BUTTON25_SNS0_IDAC_COMP0_VALUE             (CapSense_dsRam.snsList.button25[0u].idacComp[0u])
#define CapSense_BUTTON25_SNS0_IDAC_COMP0_OFFSET            (891u)
#define CapSense_BUTTON25_SNS0_IDAC_COMP0_SIZE              (1u)
#define CapSense_BUTTON25_SNS0_IDAC_COMP0_PARAM_ID          (0x4100037Bu)

#define CapSense_BUTTON26_SNS0_RAW0_VALUE                   (CapSense_dsRam.snsList.button26[0u].raw[0u])
#define CapSense_BUTTON26_SNS0_RAW0_OFFSET                  (892u)
#define CapSense_BUTTON26_SNS0_RAW0_SIZE                    (2u)
#define CapSense_BUTTON26_SNS0_RAW0_PARAM_ID                (0x8200037Cu)

#define CapSense_BUTTON26_SNS0_BSLN0_VALUE                  (CapSense_dsRam.snsList.button26[0u].bsln[0u])
#define CapSense_BUTTON26_SNS0_BSLN0_OFFSET                 (894u)
#define CapSense_BUTTON26_SNS0_BSLN0_SIZE                   (2u)
#define CapSense_BUTTON26_SNS0_BSLN0_PARAM_ID               (0x8E00037Eu)

#define CapSense_BUTTON26_SNS0_BSLN_EXT0_VALUE              (CapSense_dsRam.snsList.button26[0u].bslnExt[0u])
#define CapSense_BUTTON26_SNS0_BSLN_EXT0_OFFSET             (896u)
#define CapSense_BUTTON26_SNS0_BSLN_EXT0_SIZE               (1u)
#define CapSense_BUTTON26_SNS0_BSLN_EXT0_PARAM_ID           (0x48000380u)

#define CapSense_BUTTON26_SNS0_DIFF_VALUE                   (CapSense_dsRam.snsList.button26[0u].diff)
#define CapSense_BUTTON26_SNS0_DIFF_OFFSET                  (898u)
#define CapSense_BUTTON26_SNS0_DIFF_SIZE                    (2u)
#define CapSense_BUTTON26_SNS0_DIFF_PARAM_ID                (0x8C000382u)

#define CapSense_BUTTON26_SNS0_NEG_BSLN_RST_CNT0_VALUE      (CapSense_dsRam.snsList.button26[0u].negBslnRstCnt[0u])
#define CapSense_BUTTON26_SNS0_NEG_BSLN_RST_CNT0_OFFSET     (900u)
#define CapSense_BUTTON26_SNS0_NEG_BSLN_RST_CNT0_SIZE       (1u)
#define CapSense_BUTTON26_SNS0_NEG_BSLN_RST_CNT0_PARAM_ID   (0x49000384u)

#define CapSense_BUTTON26_SNS0_IDAC_COMP0_VALUE             (CapSense_dsRam.snsList.button26[0u].idacComp[0u])
#define CapSense_BUTTON26_SNS0_IDAC_COMP0_OFFSET            (901u)
#define CapSense_BUTTON26_SNS0_IDAC_COMP0_SIZE              (1u)
#define CapSense_BUTTON26_SNS0_IDAC_COMP0_PARAM_ID          (0x4F000385u)

#define CapSense_BUTTON27_SNS0_RAW0_VALUE                   (CapSense_dsRam.snsList.button27[0u].raw[0u])
#define CapSense_BUTTON27_SNS0_RAW0_OFFSET                  (902u)
#define CapSense_BUTTON27_SNS0_RAW0_SIZE                    (2u)
#define CapSense_BUTTON27_SNS0_RAW0_PARAM_ID                (0x8D000386u)

#define CapSense_BUTTON27_SNS0_BSLN0_VALUE                  (CapSense_dsRam.snsList.button27[0u].bsln[0u])
#define CapSense_BUTTON27_SNS0_BSLN0_OFFSET                 (904u)
#define CapSense_BUTTON27_SNS0_BSLN0_SIZE                   (2u)
#define CapSense_BUTTON27_SNS0_BSLN0_PARAM_ID               (0x82000388u)

#define CapSense_BUTTON27_SNS0_BSLN_EXT0_VALUE              (CapSense_dsRam.snsList.button27[0u].bslnExt[0u])
#define CapSense_BUTTON27_SNS0_BSLN_EXT0_OFFSET             (906u)
#define CapSense_BUTTON27_SNS0_BSLN_EXT0_SIZE               (1u)
#define CapSense_BUTTON27_SNS0_BSLN_EXT0_PARAM_ID           (0x4600038Au)

#define CapSense_BUTTON27_SNS0_DIFF_VALUE                   (CapSense_dsRam.snsList.button27[0u].diff)
#define CapSense_BUTTON27_SNS0_DIFF_OFFSET                  (908u)
#define CapSense_BUTTON27_SNS0_DIFF_SIZE                    (2u)
#define CapSense_BUTTON27_SNS0_DIFF_PARAM_ID                (0x8300038Cu)

#define CapSense_BUTTON27_SNS0_NEG_BSLN_RST_CNT0_VALUE      (CapSense_dsRam.snsList.button27[0u].negBslnRstCnt[0u])
#define CapSense_BUTTON27_SNS0_NEG_BSLN_RST_CNT0_OFFSET     (910u)
#define CapSense_BUTTON27_SNS0_NEG_BSLN_RST_CNT0_SIZE       (1u)
#define CapSense_BUTTON27_SNS0_NEG_BSLN_RST_CNT0_PARAM_ID   (0x4700038Eu)

#define CapSense_BUTTON27_SNS0_IDAC_COMP0_VALUE             (CapSense_dsRam.snsList.button27[0u].idacComp[0u])
#define CapSense_BUTTON27_SNS0_IDAC_COMP0_OFFSET            (911u)
#define CapSense_BUTTON27_SNS0_IDAC_COMP0_SIZE              (1u)
#define CapSense_BUTTON27_SNS0_IDAC_COMP0_PARAM_ID          (0x4100038Fu)

#define CapSense_BUTTON28_SNS0_RAW0_VALUE                   (CapSense_dsRam.snsList.button28[0u].raw[0u])
#define CapSense_BUTTON28_SNS0_RAW0_OFFSET                  (912u)
#define CapSense_BUTTON28_SNS0_RAW0_SIZE                    (2u)
#define CapSense_BUTTON28_SNS0_RAW0_PARAM_ID                (0x85000390u)

#define CapSense_BUTTON28_SNS0_BSLN0_VALUE                  (CapSense_dsRam.snsList.button28[0u].bsln[0u])
#define CapSense_BUTTON28_SNS0_BSLN0_OFFSET                 (914u)
#define CapSense_BUTTON28_SNS0_BSLN0_SIZE                   (2u)
#define CapSense_BUTTON28_SNS0_BSLN0_PARAM_ID               (0x89000392u)

#define CapSense_BUTTON28_SNS0_BSLN_EXT0_VALUE              (CapSense_dsRam.snsList.button28[0u].bslnExt[0u])
#define CapSense_BUTTON28_SNS0_BSLN_EXT0_OFFSET             (916u)
#define CapSense_BUTTON28_SNS0_BSLN_EXT0_SIZE               (1u)
#define CapSense_BUTTON28_SNS0_BSLN_EXT0_PARAM_ID           (0x4C000394u)

#define CapSense_BUTTON28_SNS0_DIFF_VALUE                   (CapSense_dsRam.snsList.button28[0u].diff)
#define CapSense_BUTTON28_SNS0_DIFF_OFFSET                  (918u)
#define CapSense_BUTTON28_SNS0_DIFF_SIZE                    (2u)
#define CapSense_BUTTON28_SNS0_DIFF_PARAM_ID                (0x88000396u)

#define CapSense_BUTTON28_SNS0_NEG_BSLN_RST_CNT0_VALUE      (CapSense_dsRam.snsList.button28[0u].negBslnRstCnt[0u])
#define CapSense_BUTTON28_SNS0_NEG_BSLN_RST_CNT0_OFFSET     (920u)
#define CapSense_BUTTON28_SNS0_NEG_BSLN_RST_CNT0_SIZE       (1u)
#define CapSense_BUTTON28_SNS0_NEG_BSLN_RST_CNT0_PARAM_ID   (0x4F000398u)

#define CapSense_BUTTON28_SNS0_IDAC_COMP0_VALUE             (CapSense_dsRam.snsList.button28[0u].idacComp[0u])
#define CapSense_BUTTON28_SNS0_IDAC_COMP0_OFFSET            (921u)
#define CapSense_BUTTON28_SNS0_IDAC_COMP0_SIZE              (1u)
#define CapSense_BUTTON28_SNS0_IDAC_COMP0_PARAM_ID          (0x49000399u)

#define CapSense_BUTTON29_SNS0_RAW0_VALUE                   (CapSense_dsRam.snsList.button29[0u].raw[0u])
#define CapSense_BUTTON29_SNS0_RAW0_OFFSET                  (922u)
#define CapSense_BUTTON29_SNS0_RAW0_SIZE                    (2u)
#define CapSense_BUTTON29_SNS0_RAW0_PARAM_ID                (0x8B00039Au)

#define CapSense_BUTTON29_SNS0_BSLN0_VALUE                  (CapSense_dsRam.snsList.button29[0u].bsln[0u])
#define CapSense_BUTTON29_SNS0_BSLN0_OFFSET                 (924u)
#define CapSense_BUTTON29_SNS0_BSLN0_SIZE                   (2u)
#define CapSense_BUTTON29_SNS0_BSLN0_PARAM_ID               (0x8600039Cu)

#define CapSense_BUTTON29_SNS0_BSLN_EXT0_VALUE              (CapSense_dsRam.snsList.button29[0u].bslnExt[0u])
#define CapSense_BUTTON29_SNS0_BSLN_EXT0_OFFSET             (926u)
#define CapSense_BUTTON29_SNS0_BSLN_EXT0_SIZE               (1u)
#define CapSense_BUTTON29_SNS0_BSLN_EXT0_PARAM_ID           (0x4200039Eu)

#define CapSense_BUTTON29_SNS0_DIFF_VALUE                   (CapSense_dsRam.snsList.button29[0u].diff)
#define CapSense_BUTTON29_SNS0_DIFF_OFFSET                  (928u)
#define CapSense_BUTTON29_SNS0_DIFF_SIZE                    (2u)
#define CapSense_BUTTON29_SNS0_DIFF_PARAM_ID                (0x8A0003A0u)

#define CapSense_BUTTON29_SNS0_NEG_BSLN_RST_CNT0_VALUE      (CapSense_dsRam.snsList.button29[0u].negBslnRstCnt[0u])
#define CapSense_BUTTON29_SNS0_NEG_BSLN_RST_CNT0_OFFSET     (930u)
#define CapSense_BUTTON29_SNS0_NEG_BSLN_RST_CNT0_SIZE       (1u)
#define CapSense_BUTTON29_SNS0_NEG_BSLN_RST_CNT0_PARAM_ID   (0x4E0003A2u)

#define CapSense_BUTTON29_SNS0_IDAC_COMP0_VALUE             (CapSense_dsRam.snsList.button29[0u].idacComp[0u])
#define CapSense_BUTTON29_SNS0_IDAC_COMP0_OFFSET            (931u)
#define CapSense_BUTTON29_SNS0_IDAC_COMP0_SIZE              (1u)
#define CapSense_BUTTON29_SNS0_IDAC_COMP0_PARAM_ID          (0x480003A3u)

#define CapSense_BUTTON30_SNS0_RAW0_VALUE                   (CapSense_dsRam.snsList.button30[0u].raw[0u])
#define CapSense_BUTTON30_SNS0_RAW0_OFFSET                  (932u)
#define CapSense_BUTTON30_SNS0_RAW0_SIZE                    (2u)
#define CapSense_BUTTON30_SNS0_RAW0_PARAM_ID                (0x8B0003A4u)

#define CapSense_BUTTON30_SNS0_BSLN0_VALUE                  (CapSense_dsRam.snsList.button30[0u].bsln[0u])
#define CapSense_BUTTON30_SNS0_BSLN0_OFFSET                 (934u)
#define CapSense_BUTTON30_SNS0_BSLN0_SIZE                   (2u)
#define CapSense_BUTTON30_SNS0_BSLN0_PARAM_ID               (0x870003A6u)

#define CapSense_BUTTON30_SNS0_BSLN_EXT0_VALUE              (CapSense_dsRam.snsList.button30[0u].bslnExt[0u])
#define CapSense_BUTTON30_SNS0_BSLN_EXT0_OFFSET             (936u)
#define CapSense_BUTTON30_SNS0_BSLN_EXT0_SIZE               (1u)
#define CapSense_BUTTON30_SNS0_BSLN_EXT0_PARAM_ID           (0x400003A8u)

#define CapSense_BUTTON30_SNS0_DIFF_VALUE                   (CapSense_dsRam.snsList.button30[0u].diff)
#define CapSense_BUTTON30_SNS0_DIFF_OFFSET                  (938u)
#define CapSense_BUTTON30_SNS0_DIFF_SIZE                    (2u)
#define CapSense_BUTTON30_SNS0_DIFF_PARAM_ID                (0x840003AAu)

#define CapSense_BUTTON30_SNS0_NEG_BSLN_RST_CNT0_VALUE      (CapSense_dsRam.snsList.button30[0u].negBslnRstCnt[0u])
#define CapSense_BUTTON30_SNS0_NEG_BSLN_RST_CNT0_OFFSET     (940u)
#define CapSense_BUTTON30_SNS0_NEG_BSLN_RST_CNT0_SIZE       (1u)
#define CapSense_BUTTON30_SNS0_NEG_BSLN_RST_CNT0_PARAM_ID   (0x410003ACu)

#define CapSense_BUTTON30_SNS0_IDAC_COMP0_VALUE             (CapSense_dsRam.snsList.button30[0u].idacComp[0u])
#define CapSense_BUTTON30_SNS0_IDAC_COMP0_OFFSET            (941u)
#define CapSense_BUTTON30_SNS0_IDAC_COMP0_SIZE              (1u)
#define CapSense_BUTTON30_SNS0_IDAC_COMP0_PARAM_ID          (0x470003ADu)

#define CapSense_BUTTON31_SNS0_RAW0_VALUE                   (CapSense_dsRam.snsList.button31[0u].raw[0u])
#define CapSense_BUTTON31_SNS0_RAW0_OFFSET                  (942u)
#define CapSense_BUTTON31_SNS0_RAW0_SIZE                    (2u)
#define CapSense_BUTTON31_SNS0_RAW0_PARAM_ID                (0x850003AEu)

#define CapSense_BUTTON31_SNS0_BSLN0_VALUE                  (CapSense_dsRam.snsList.button31[0u].bsln[0u])
#define CapSense_BUTTON31_SNS0_BSLN0_OFFSET                 (944u)
#define CapSense_BUTTON31_SNS0_BSLN0_SIZE                   (2u)
#define CapSense_BUTTON31_SNS0_BSLN0_PARAM_ID               (0x8F0003B0u)

#define CapSense_BUTTON31_SNS0_BSLN_EXT0_VALUE              (CapSense_dsRam.snsList.button31[0u].bslnExt[0u])
#define CapSense_BUTTON31_SNS0_BSLN_EXT0_OFFSET             (946u)
#define CapSense_BUTTON31_SNS0_BSLN_EXT0_SIZE               (1u)
#define CapSense_BUTTON31_SNS0_BSLN_EXT0_PARAM_ID           (0x4B0003B2u)

#define CapSense_BUTTON31_SNS0_DIFF_VALUE                   (CapSense_dsRam.snsList.button31[0u].diff)
#define CapSense_BUTTON31_SNS0_DIFF_OFFSET                  (948u)
#define CapSense_BUTTON31_SNS0_DIFF_SIZE                    (2u)
#define CapSense_BUTTON31_SNS0_DIFF_PARAM_ID                (0x8E0003B4u)

#define CapSense_BUTTON31_SNS0_NEG_BSLN_RST_CNT0_VALUE      (CapSense_dsRam.snsList.button31[0u].negBslnRstCnt[0u])
#define CapSense_BUTTON31_SNS0_NEG_BSLN_RST_CNT0_OFFSET     (950u)
#define CapSense_BUTTON31_SNS0_NEG_BSLN_RST_CNT0_SIZE       (1u)
#define CapSense_BUTTON31_SNS0_NEG_BSLN_RST_CNT0_PARAM_ID   (0x4A0003B6u)

#define CapSense_BUTTON31_SNS0_IDAC_COMP0_VALUE             (CapSense_dsRam.snsList.button31[0u].idacComp[0u])
#define CapSense_BUTTON31_SNS0_IDAC_COMP0_OFFSET            (951u)
#define CapSense_BUTTON31_SNS0_IDAC_COMP0_SIZE              (1u)
#define CapSense_BUTTON31_SNS0_IDAC_COMP0_PARAM_ID          (0x4C0003B7u)

#define CapSense_SNR_TEST_WIDGET_ID_VALUE                   (CapSense_dsRam.snrTestWidgetId)
#define CapSense_SNR_TEST_WIDGET_ID_OFFSET                  (952u)
#define CapSense_SNR_TEST_WIDGET_ID_SIZE                    (1u)
#define CapSense_SNR_TEST_WIDGET_ID_PARAM_ID                (0x6E0003B8u)

#define CapSense_SNR_TEST_SENSOR_ID_VALUE                   (CapSense_dsRam.snrTestSensorId)
#define CapSense_SNR_TEST_SENSOR_ID_OFFSET                  (953u)
#define CapSense_SNR_TEST_SENSOR_ID_SIZE                    (1u)
#define CapSense_SNR_TEST_SENSOR_ID_PARAM_ID                (0x680003B9u)

#define CapSense_SNR_TEST_SCAN_COUNTER_VALUE                (CapSense_dsRam.snrTestScanCounter)
#define CapSense_SNR_TEST_SCAN_COUNTER_OFFSET               (954u)
#define CapSense_SNR_TEST_SCAN_COUNTER_SIZE                 (2u)
#define CapSense_SNR_TEST_SCAN_COUNTER_PARAM_ID             (0x810003BAu)

#define CapSense_SNR_TEST_RAW_COUNT0_VALUE                  (CapSense_dsRam.snrTestRawCount[0u])
#define CapSense_SNR_TEST_RAW_COUNT0_OFFSET                 (956u)
#define CapSense_SNR_TEST_RAW_COUNT0_SIZE                   (2u)
#define CapSense_SNR_TEST_RAW_COUNT0_PARAM_ID               (0x8C0003BCu)


/*****************************************************************************/
/* Flash Data structure register definitions                                 */
/*****************************************************************************/
#define CapSense_BUTTON0_PTR2SNS_FLASH_VALUE                (CapSense_dsFlash.wdgtArray[0].ptr2SnsFlash)
#define CapSense_BUTTON0_PTR2SNS_FLASH_OFFSET               (0u)
#define CapSense_BUTTON0_PTR2SNS_FLASH_SIZE                 (4u)
#define CapSense_BUTTON0_PTR2SNS_FLASH_PARAM_ID             (0xD1000000u)

#define CapSense_BUTTON0_PTR2WD_RAM_VALUE                   (CapSense_dsFlash.wdgtArray[0].ptr2WdgtRam)
#define CapSense_BUTTON0_PTR2WD_RAM_OFFSET                  (4u)
#define CapSense_BUTTON0_PTR2WD_RAM_SIZE                    (4u)
#define CapSense_BUTTON0_PTR2WD_RAM_PARAM_ID                (0xD0000004u)

#define CapSense_BUTTON0_PTR2SNS_RAM_VALUE                  (CapSense_dsFlash.wdgtArray[0].ptr2SnsRam)
#define CapSense_BUTTON0_PTR2SNS_RAM_OFFSET                 (8u)
#define CapSense_BUTTON0_PTR2SNS_RAM_SIZE                   (4u)
#define CapSense_BUTTON0_PTR2SNS_RAM_PARAM_ID               (0xD3000008u)

#define CapSense_BUTTON0_PTR2FLTR_HISTORY_VALUE             (CapSense_dsFlash.wdgtArray[0].ptr2FltrHistory)
#define CapSense_BUTTON0_PTR2FLTR_HISTORY_OFFSET            (12u)
#define CapSense_BUTTON0_PTR2FLTR_HISTORY_SIZE              (4u)
#define CapSense_BUTTON0_PTR2FLTR_HISTORY_PARAM_ID          (0xD200000Cu)

#define CapSense_BUTTON0_PTR2DEBOUNCE_VALUE                 (CapSense_dsFlash.wdgtArray[0].ptr2DebounceArr)
#define CapSense_BUTTON0_PTR2DEBOUNCE_OFFSET                (16u)
#define CapSense_BUTTON0_PTR2DEBOUNCE_SIZE                  (4u)
#define CapSense_BUTTON0_PTR2DEBOUNCE_PARAM_ID              (0xD4000010u)

#define CapSense_BUTTON0_STATIC_CONFIG_VALUE                (CapSense_dsFlash.wdgtArray[0].staticConfig)
#define CapSense_BUTTON0_STATIC_CONFIG_OFFSET               (20u)
#define CapSense_BUTTON0_STATIC_CONFIG_SIZE                 (2u)
#define CapSense_BUTTON0_STATIC_CONFIG_PARAM_ID             (0x9A000014u)

#define CapSense_BUTTON0_TOTAL_NUM_SNS_VALUE                (CapSense_dsFlash.wdgtArray[0].totalNumSns)
#define CapSense_BUTTON0_TOTAL_NUM_SNS_OFFSET               (22u)
#define CapSense_BUTTON0_TOTAL_NUM_SNS_SIZE                 (2u)
#define CapSense_BUTTON0_TOTAL_NUM_SNS_PARAM_ID             (0x96000016u)

#define CapSense_BUTTON0_TYPE_VALUE                         (CapSense_dsFlash.wdgtArray[0].wdgtType)
#define CapSense_BUTTON0_TYPE_OFFSET                        (24u)
#define CapSense_BUTTON0_TYPE_SIZE                          (1u)
#define CapSense_BUTTON0_TYPE_PARAM_ID                      (0x51000018u)

#define CapSense_BUTTON0_NUM_COLS_VALUE                     (CapSense_dsFlash.wdgtArray[0].numCols)
#define CapSense_BUTTON0_NUM_COLS_OFFSET                    (25u)
#define CapSense_BUTTON0_NUM_COLS_SIZE                      (1u)
#define CapSense_BUTTON0_NUM_COLS_PARAM_ID                  (0x57000019u)

#define CapSense_BUTTON0_PTR2NOISE_ENVLP_VALUE              (CapSense_dsFlash.wdgtArray[0].ptr2NoiseEnvlp)
#define CapSense_BUTTON0_PTR2NOISE_ENVLP_OFFSET             (28u)
#define CapSense_BUTTON0_PTR2NOISE_ENVLP_SIZE               (4u)
#define CapSense_BUTTON0_PTR2NOISE_ENVLP_PARAM_ID           (0xD700001Cu)

#define CapSense_BUTTON1_PTR2SNS_FLASH_VALUE                (CapSense_dsFlash.wdgtArray[1].ptr2SnsFlash)
#define CapSense_BUTTON1_PTR2SNS_FLASH_OFFSET               (32u)
#define CapSense_BUTTON1_PTR2SNS_FLASH_SIZE                 (4u)
#define CapSense_BUTTON1_PTR2SNS_FLASH_PARAM_ID             (0xD8010020u)

#define CapSense_BUTTON1_PTR2WD_RAM_VALUE                   (CapSense_dsFlash.wdgtArray[1].ptr2WdgtRam)
#define CapSense_BUTTON1_PTR2WD_RAM_OFFSET                  (36u)
#define CapSense_BUTTON1_PTR2WD_RAM_SIZE                    (4u)
#define CapSense_BUTTON1_PTR2WD_RAM_PARAM_ID                (0xD9010024u)

#define CapSense_BUTTON1_PTR2SNS_RAM_VALUE                  (CapSense_dsFlash.wdgtArray[1].ptr2SnsRam)
#define CapSense_BUTTON1_PTR2SNS_RAM_OFFSET                 (40u)
#define CapSense_BUTTON1_PTR2SNS_RAM_SIZE                   (4u)
#define CapSense_BUTTON1_PTR2SNS_RAM_PARAM_ID               (0xDA010028u)

#define CapSense_BUTTON1_PTR2FLTR_HISTORY_VALUE             (CapSense_dsFlash.wdgtArray[1].ptr2FltrHistory)
#define CapSense_BUTTON1_PTR2FLTR_HISTORY_OFFSET            (44u)
#define CapSense_BUTTON1_PTR2FLTR_HISTORY_SIZE              (4u)
#define CapSense_BUTTON1_PTR2FLTR_HISTORY_PARAM_ID          (0xDB01002Cu)

#define CapSense_BUTTON1_PTR2DEBOUNCE_VALUE                 (CapSense_dsFlash.wdgtArray[1].ptr2DebounceArr)
#define CapSense_BUTTON1_PTR2DEBOUNCE_OFFSET                (48u)
#define CapSense_BUTTON1_PTR2DEBOUNCE_SIZE                  (4u)
#define CapSense_BUTTON1_PTR2DEBOUNCE_PARAM_ID              (0xDD010030u)

#define CapSense_BUTTON1_STATIC_CONFIG_VALUE                (CapSense_dsFlash.wdgtArray[1].staticConfig)
#define CapSense_BUTTON1_STATIC_CONFIG_OFFSET               (52u)
#define CapSense_BUTTON1_STATIC_CONFIG_SIZE                 (2u)
#define CapSense_BUTTON1_STATIC_CONFIG_PARAM_ID             (0x93010034u)

#define CapSense_BUTTON1_TOTAL_NUM_SNS_VALUE                (CapSense_dsFlash.wdgtArray[1].totalNumSns)
#define CapSense_BUTTON1_TOTAL_NUM_SNS_OFFSET               (54u)
#define CapSense_BUTTON1_TOTAL_NUM_SNS_SIZE                 (2u)
#define CapSense_BUTTON1_TOTAL_NUM_SNS_PARAM_ID             (0x9F010036u)

#define CapSense_BUTTON1_TYPE_VALUE                         (CapSense_dsFlash.wdgtArray[1].wdgtType)
#define CapSense_BUTTON1_TYPE_OFFSET                        (56u)
#define CapSense_BUTTON1_TYPE_SIZE                          (1u)
#define CapSense_BUTTON1_TYPE_PARAM_ID                      (0x58010038u)

#define CapSense_BUTTON1_NUM_COLS_VALUE                     (CapSense_dsFlash.wdgtArray[1].numCols)
#define CapSense_BUTTON1_NUM_COLS_OFFSET                    (57u)
#define CapSense_BUTTON1_NUM_COLS_SIZE                      (1u)
#define CapSense_BUTTON1_NUM_COLS_PARAM_ID                  (0x5E010039u)

#define CapSense_BUTTON1_PTR2NOISE_ENVLP_VALUE              (CapSense_dsFlash.wdgtArray[1].ptr2NoiseEnvlp)
#define CapSense_BUTTON1_PTR2NOISE_ENVLP_OFFSET             (60u)
#define CapSense_BUTTON1_PTR2NOISE_ENVLP_SIZE               (4u)
#define CapSense_BUTTON1_PTR2NOISE_ENVLP_PARAM_ID           (0xDE01003Cu)

#define CapSense_BUTTON2_PTR2SNS_FLASH_VALUE                (CapSense_dsFlash.wdgtArray[2].ptr2SnsFlash)
#define CapSense_BUTTON2_PTR2SNS_FLASH_OFFSET               (64u)
#define CapSense_BUTTON2_PTR2SNS_FLASH_SIZE                 (4u)
#define CapSense_BUTTON2_PTR2SNS_FLASH_PARAM_ID             (0xDA020040u)

#define CapSense_BUTTON2_PTR2WD_RAM_VALUE                   (CapSense_dsFlash.wdgtArray[2].ptr2WdgtRam)
#define CapSense_BUTTON2_PTR2WD_RAM_OFFSET                  (68u)
#define CapSense_BUTTON2_PTR2WD_RAM_SIZE                    (4u)
#define CapSense_BUTTON2_PTR2WD_RAM_PARAM_ID                (0xDB020044u)

#define CapSense_BUTTON2_PTR2SNS_RAM_VALUE                  (CapSense_dsFlash.wdgtArray[2].ptr2SnsRam)
#define CapSense_BUTTON2_PTR2SNS_RAM_OFFSET                 (72u)
#define CapSense_BUTTON2_PTR2SNS_RAM_SIZE                   (4u)
#define CapSense_BUTTON2_PTR2SNS_RAM_PARAM_ID               (0xD8020048u)

#define CapSense_BUTTON2_PTR2FLTR_HISTORY_VALUE             (CapSense_dsFlash.wdgtArray[2].ptr2FltrHistory)
#define CapSense_BUTTON2_PTR2FLTR_HISTORY_OFFSET            (76u)
#define CapSense_BUTTON2_PTR2FLTR_HISTORY_SIZE              (4u)
#define CapSense_BUTTON2_PTR2FLTR_HISTORY_PARAM_ID          (0xD902004Cu)

#define CapSense_BUTTON2_PTR2DEBOUNCE_VALUE                 (CapSense_dsFlash.wdgtArray[2].ptr2DebounceArr)
#define CapSense_BUTTON2_PTR2DEBOUNCE_OFFSET                (80u)
#define CapSense_BUTTON2_PTR2DEBOUNCE_SIZE                  (4u)
#define CapSense_BUTTON2_PTR2DEBOUNCE_PARAM_ID              (0xDF020050u)

#define CapSense_BUTTON2_STATIC_CONFIG_VALUE                (CapSense_dsFlash.wdgtArray[2].staticConfig)
#define CapSense_BUTTON2_STATIC_CONFIG_OFFSET               (84u)
#define CapSense_BUTTON2_STATIC_CONFIG_SIZE                 (2u)
#define CapSense_BUTTON2_STATIC_CONFIG_PARAM_ID             (0x91020054u)

#define CapSense_BUTTON2_TOTAL_NUM_SNS_VALUE                (CapSense_dsFlash.wdgtArray[2].totalNumSns)
#define CapSense_BUTTON2_TOTAL_NUM_SNS_OFFSET               (86u)
#define CapSense_BUTTON2_TOTAL_NUM_SNS_SIZE                 (2u)
#define CapSense_BUTTON2_TOTAL_NUM_SNS_PARAM_ID             (0x9D020056u)

#define CapSense_BUTTON2_TYPE_VALUE                         (CapSense_dsFlash.wdgtArray[2].wdgtType)
#define CapSense_BUTTON2_TYPE_OFFSET                        (88u)
#define CapSense_BUTTON2_TYPE_SIZE                          (1u)
#define CapSense_BUTTON2_TYPE_PARAM_ID                      (0x5A020058u)

#define CapSense_BUTTON2_NUM_COLS_VALUE                     (CapSense_dsFlash.wdgtArray[2].numCols)
#define CapSense_BUTTON2_NUM_COLS_OFFSET                    (89u)
#define CapSense_BUTTON2_NUM_COLS_SIZE                      (1u)
#define CapSense_BUTTON2_NUM_COLS_PARAM_ID                  (0x5C020059u)

#define CapSense_BUTTON2_PTR2NOISE_ENVLP_VALUE              (CapSense_dsFlash.wdgtArray[2].ptr2NoiseEnvlp)
#define CapSense_BUTTON2_PTR2NOISE_ENVLP_OFFSET             (92u)
#define CapSense_BUTTON2_PTR2NOISE_ENVLP_SIZE               (4u)
#define CapSense_BUTTON2_PTR2NOISE_ENVLP_PARAM_ID           (0xDC02005Cu)

#define CapSense_BUTTON3_PTR2SNS_FLASH_VALUE                (CapSense_dsFlash.wdgtArray[3].ptr2SnsFlash)
#define CapSense_BUTTON3_PTR2SNS_FLASH_OFFSET               (96u)
#define CapSense_BUTTON3_PTR2SNS_FLASH_SIZE                 (4u)
#define CapSense_BUTTON3_PTR2SNS_FLASH_PARAM_ID             (0xD3030060u)

#define CapSense_BUTTON3_PTR2WD_RAM_VALUE                   (CapSense_dsFlash.wdgtArray[3].ptr2WdgtRam)
#define CapSense_BUTTON3_PTR2WD_RAM_OFFSET                  (100u)
#define CapSense_BUTTON3_PTR2WD_RAM_SIZE                    (4u)
#define CapSense_BUTTON3_PTR2WD_RAM_PARAM_ID                (0xD2030064u)

#define CapSense_BUTTON3_PTR2SNS_RAM_VALUE                  (CapSense_dsFlash.wdgtArray[3].ptr2SnsRam)
#define CapSense_BUTTON3_PTR2SNS_RAM_OFFSET                 (104u)
#define CapSense_BUTTON3_PTR2SNS_RAM_SIZE                   (4u)
#define CapSense_BUTTON3_PTR2SNS_RAM_PARAM_ID               (0xD1030068u)

#define CapSense_BUTTON3_PTR2FLTR_HISTORY_VALUE             (CapSense_dsFlash.wdgtArray[3].ptr2FltrHistory)
#define CapSense_BUTTON3_PTR2FLTR_HISTORY_OFFSET            (108u)
#define CapSense_BUTTON3_PTR2FLTR_HISTORY_SIZE              (4u)
#define CapSense_BUTTON3_PTR2FLTR_HISTORY_PARAM_ID          (0xD003006Cu)

#define CapSense_BUTTON3_PTR2DEBOUNCE_VALUE                 (CapSense_dsFlash.wdgtArray[3].ptr2DebounceArr)
#define CapSense_BUTTON3_PTR2DEBOUNCE_OFFSET                (112u)
#define CapSense_BUTTON3_PTR2DEBOUNCE_SIZE                  (4u)
#define CapSense_BUTTON3_PTR2DEBOUNCE_PARAM_ID              (0xD6030070u)

#define CapSense_BUTTON3_STATIC_CONFIG_VALUE                (CapSense_dsFlash.wdgtArray[3].staticConfig)
#define CapSense_BUTTON3_STATIC_CONFIG_OFFSET               (116u)
#define CapSense_BUTTON3_STATIC_CONFIG_SIZE                 (2u)
#define CapSense_BUTTON3_STATIC_CONFIG_PARAM_ID             (0x98030074u)

#define CapSense_BUTTON3_TOTAL_NUM_SNS_VALUE                (CapSense_dsFlash.wdgtArray[3].totalNumSns)
#define CapSense_BUTTON3_TOTAL_NUM_SNS_OFFSET               (118u)
#define CapSense_BUTTON3_TOTAL_NUM_SNS_SIZE                 (2u)
#define CapSense_BUTTON3_TOTAL_NUM_SNS_PARAM_ID             (0x94030076u)

#define CapSense_BUTTON3_TYPE_VALUE                         (CapSense_dsFlash.wdgtArray[3].wdgtType)
#define CapSense_BUTTON3_TYPE_OFFSET                        (120u)
#define CapSense_BUTTON3_TYPE_SIZE                          (1u)
#define CapSense_BUTTON3_TYPE_PARAM_ID                      (0x53030078u)

#define CapSense_BUTTON3_NUM_COLS_VALUE                     (CapSense_dsFlash.wdgtArray[3].numCols)
#define CapSense_BUTTON3_NUM_COLS_OFFSET                    (121u)
#define CapSense_BUTTON3_NUM_COLS_SIZE                      (1u)
#define CapSense_BUTTON3_NUM_COLS_PARAM_ID                  (0x55030079u)

#define CapSense_BUTTON3_PTR2NOISE_ENVLP_VALUE              (CapSense_dsFlash.wdgtArray[3].ptr2NoiseEnvlp)
#define CapSense_BUTTON3_PTR2NOISE_ENVLP_OFFSET             (124u)
#define CapSense_BUTTON3_PTR2NOISE_ENVLP_SIZE               (4u)
#define CapSense_BUTTON3_PTR2NOISE_ENVLP_PARAM_ID           (0xD503007Cu)

#define CapSense_BUTTON4_PTR2SNS_FLASH_VALUE                (CapSense_dsFlash.wdgtArray[4].ptr2SnsFlash)
#define CapSense_BUTTON4_PTR2SNS_FLASH_OFFSET               (128u)
#define CapSense_BUTTON4_PTR2SNS_FLASH_SIZE                 (4u)
#define CapSense_BUTTON4_PTR2SNS_FLASH_PARAM_ID             (0xDE040080u)

#define CapSense_BUTTON4_PTR2WD_RAM_VALUE                   (CapSense_dsFlash.wdgtArray[4].ptr2WdgtRam)
#define CapSense_BUTTON4_PTR2WD_RAM_OFFSET                  (132u)
#define CapSense_BUTTON4_PTR2WD_RAM_SIZE                    (4u)
#define CapSense_BUTTON4_PTR2WD_RAM_PARAM_ID                (0xDF040084u)

#define CapSense_BUTTON4_PTR2SNS_RAM_VALUE                  (CapSense_dsFlash.wdgtArray[4].ptr2SnsRam)
#define CapSense_BUTTON4_PTR2SNS_RAM_OFFSET                 (136u)
#define CapSense_BUTTON4_PTR2SNS_RAM_SIZE                   (4u)
#define CapSense_BUTTON4_PTR2SNS_RAM_PARAM_ID               (0xDC040088u)

#define CapSense_BUTTON4_PTR2FLTR_HISTORY_VALUE             (CapSense_dsFlash.wdgtArray[4].ptr2FltrHistory)
#define CapSense_BUTTON4_PTR2FLTR_HISTORY_OFFSET            (140u)
#define CapSense_BUTTON4_PTR2FLTR_HISTORY_SIZE              (4u)
#define CapSense_BUTTON4_PTR2FLTR_HISTORY_PARAM_ID          (0xDD04008Cu)

#define CapSense_BUTTON4_PTR2DEBOUNCE_VALUE                 (CapSense_dsFlash.wdgtArray[4].ptr2DebounceArr)
#define CapSense_BUTTON4_PTR2DEBOUNCE_OFFSET                (144u)
#define CapSense_BUTTON4_PTR2DEBOUNCE_SIZE                  (4u)
#define CapSense_BUTTON4_PTR2DEBOUNCE_PARAM_ID              (0xDB040090u)

#define CapSense_BUTTON4_STATIC_CONFIG_VALUE                (CapSense_dsFlash.wdgtArray[4].staticConfig)
#define CapSense_BUTTON4_STATIC_CONFIG_OFFSET               (148u)
#define CapSense_BUTTON4_STATIC_CONFIG_SIZE                 (2u)
#define CapSense_BUTTON4_STATIC_CONFIG_PARAM_ID             (0x95040094u)

#define CapSense_BUTTON4_TOTAL_NUM_SNS_VALUE                (CapSense_dsFlash.wdgtArray[4].totalNumSns)
#define CapSense_BUTTON4_TOTAL_NUM_SNS_OFFSET               (150u)
#define CapSense_BUTTON4_TOTAL_NUM_SNS_SIZE                 (2u)
#define CapSense_BUTTON4_TOTAL_NUM_SNS_PARAM_ID             (0x99040096u)

#define CapSense_BUTTON4_TYPE_VALUE                         (CapSense_dsFlash.wdgtArray[4].wdgtType)
#define CapSense_BUTTON4_TYPE_OFFSET                        (152u)
#define CapSense_BUTTON4_TYPE_SIZE                          (1u)
#define CapSense_BUTTON4_TYPE_PARAM_ID                      (0x5E040098u)

#define CapSense_BUTTON4_NUM_COLS_VALUE                     (CapSense_dsFlash.wdgtArray[4].numCols)
#define CapSense_BUTTON4_NUM_COLS_OFFSET                    (153u)
#define CapSense_BUTTON4_NUM_COLS_SIZE                      (1u)
#define CapSense_BUTTON4_NUM_COLS_PARAM_ID                  (0x58040099u)

#define CapSense_BUTTON4_PTR2NOISE_ENVLP_VALUE              (CapSense_dsFlash.wdgtArray[4].ptr2NoiseEnvlp)
#define CapSense_BUTTON4_PTR2NOISE_ENVLP_OFFSET             (156u)
#define CapSense_BUTTON4_PTR2NOISE_ENVLP_SIZE               (4u)
#define CapSense_BUTTON4_PTR2NOISE_ENVLP_PARAM_ID           (0xD804009Cu)

#define CapSense_BUTTON5_PTR2SNS_FLASH_VALUE                (CapSense_dsFlash.wdgtArray[5].ptr2SnsFlash)
#define CapSense_BUTTON5_PTR2SNS_FLASH_OFFSET               (160u)
#define CapSense_BUTTON5_PTR2SNS_FLASH_SIZE                 (4u)
#define CapSense_BUTTON5_PTR2SNS_FLASH_PARAM_ID             (0xD70500A0u)

#define CapSense_BUTTON5_PTR2WD_RAM_VALUE                   (CapSense_dsFlash.wdgtArray[5].ptr2WdgtRam)
#define CapSense_BUTTON5_PTR2WD_RAM_OFFSET                  (164u)
#define CapSense_BUTTON5_PTR2WD_RAM_SIZE                    (4u)
#define CapSense_BUTTON5_PTR2WD_RAM_PARAM_ID                (0xD60500A4u)

#define CapSense_BUTTON5_PTR2SNS_RAM_VALUE                  (CapSense_dsFlash.wdgtArray[5].ptr2SnsRam)
#define CapSense_BUTTON5_PTR2SNS_RAM_OFFSET                 (168u)
#define CapSense_BUTTON5_PTR2SNS_RAM_SIZE                   (4u)
#define CapSense_BUTTON5_PTR2SNS_RAM_PARAM_ID               (0xD50500A8u)

#define CapSense_BUTTON5_PTR2FLTR_HISTORY_VALUE             (CapSense_dsFlash.wdgtArray[5].ptr2FltrHistory)
#define CapSense_BUTTON5_PTR2FLTR_HISTORY_OFFSET            (172u)
#define CapSense_BUTTON5_PTR2FLTR_HISTORY_SIZE              (4u)
#define CapSense_BUTTON5_PTR2FLTR_HISTORY_PARAM_ID          (0xD40500ACu)

#define CapSense_BUTTON5_PTR2DEBOUNCE_VALUE                 (CapSense_dsFlash.wdgtArray[5].ptr2DebounceArr)
#define CapSense_BUTTON5_PTR2DEBOUNCE_OFFSET                (176u)
#define CapSense_BUTTON5_PTR2DEBOUNCE_SIZE                  (4u)
#define CapSense_BUTTON5_PTR2DEBOUNCE_PARAM_ID              (0xD20500B0u)

#define CapSense_BUTTON5_STATIC_CONFIG_VALUE                (CapSense_dsFlash.wdgtArray[5].staticConfig)
#define CapSense_BUTTON5_STATIC_CONFIG_OFFSET               (180u)
#define CapSense_BUTTON5_STATIC_CONFIG_SIZE                 (2u)
#define CapSense_BUTTON5_STATIC_CONFIG_PARAM_ID             (0x9C0500B4u)

#define CapSense_BUTTON5_TOTAL_NUM_SNS_VALUE                (CapSense_dsFlash.wdgtArray[5].totalNumSns)
#define CapSense_BUTTON5_TOTAL_NUM_SNS_OFFSET               (182u)
#define CapSense_BUTTON5_TOTAL_NUM_SNS_SIZE                 (2u)
#define CapSense_BUTTON5_TOTAL_NUM_SNS_PARAM_ID             (0x900500B6u)

#define CapSense_BUTTON5_TYPE_VALUE                         (CapSense_dsFlash.wdgtArray[5].wdgtType)
#define CapSense_BUTTON5_TYPE_OFFSET                        (184u)
#define CapSense_BUTTON5_TYPE_SIZE                          (1u)
#define CapSense_BUTTON5_TYPE_PARAM_ID                      (0x570500B8u)

#define CapSense_BUTTON5_NUM_COLS_VALUE                     (CapSense_dsFlash.wdgtArray[5].numCols)
#define CapSense_BUTTON5_NUM_COLS_OFFSET                    (185u)
#define CapSense_BUTTON5_NUM_COLS_SIZE                      (1u)
#define CapSense_BUTTON5_NUM_COLS_PARAM_ID                  (0x510500B9u)

#define CapSense_BUTTON5_PTR2NOISE_ENVLP_VALUE              (CapSense_dsFlash.wdgtArray[5].ptr2NoiseEnvlp)
#define CapSense_BUTTON5_PTR2NOISE_ENVLP_OFFSET             (188u)
#define CapSense_BUTTON5_PTR2NOISE_ENVLP_SIZE               (4u)
#define CapSense_BUTTON5_PTR2NOISE_ENVLP_PARAM_ID           (0xD10500BCu)

#define CapSense_BUTTON6_PTR2SNS_FLASH_VALUE                (CapSense_dsFlash.wdgtArray[6].ptr2SnsFlash)
#define CapSense_BUTTON6_PTR2SNS_FLASH_OFFSET               (192u)
#define CapSense_BUTTON6_PTR2SNS_FLASH_SIZE                 (4u)
#define CapSense_BUTTON6_PTR2SNS_FLASH_PARAM_ID             (0xD50600C0u)

#define CapSense_BUTTON6_PTR2WD_RAM_VALUE                   (CapSense_dsFlash.wdgtArray[6].ptr2WdgtRam)
#define CapSense_BUTTON6_PTR2WD_RAM_OFFSET                  (196u)
#define CapSense_BUTTON6_PTR2WD_RAM_SIZE                    (4u)
#define CapSense_BUTTON6_PTR2WD_RAM_PARAM_ID                (0xD40600C4u)

#define CapSense_BUTTON6_PTR2SNS_RAM_VALUE                  (CapSense_dsFlash.wdgtArray[6].ptr2SnsRam)
#define CapSense_BUTTON6_PTR2SNS_RAM_OFFSET                 (200u)
#define CapSense_BUTTON6_PTR2SNS_RAM_SIZE                   (4u)
#define CapSense_BUTTON6_PTR2SNS_RAM_PARAM_ID               (0xD70600C8u)

#define CapSense_BUTTON6_PTR2FLTR_HISTORY_VALUE             (CapSense_dsFlash.wdgtArray[6].ptr2FltrHistory)
#define CapSense_BUTTON6_PTR2FLTR_HISTORY_OFFSET            (204u)
#define CapSense_BUTTON6_PTR2FLTR_HISTORY_SIZE              (4u)
#define CapSense_BUTTON6_PTR2FLTR_HISTORY_PARAM_ID          (0xD60600CCu)

#define CapSense_BUTTON6_PTR2DEBOUNCE_VALUE                 (CapSense_dsFlash.wdgtArray[6].ptr2DebounceArr)
#define CapSense_BUTTON6_PTR2DEBOUNCE_OFFSET                (208u)
#define CapSense_BUTTON6_PTR2DEBOUNCE_SIZE                  (4u)
#define CapSense_BUTTON6_PTR2DEBOUNCE_PARAM_ID              (0xD00600D0u)

#define CapSense_BUTTON6_STATIC_CONFIG_VALUE                (CapSense_dsFlash.wdgtArray[6].staticConfig)
#define CapSense_BUTTON6_STATIC_CONFIG_OFFSET               (212u)
#define CapSense_BUTTON6_STATIC_CONFIG_SIZE                 (2u)
#define CapSense_BUTTON6_STATIC_CONFIG_PARAM_ID             (0x9E0600D4u)

#define CapSense_BUTTON6_TOTAL_NUM_SNS_VALUE                (CapSense_dsFlash.wdgtArray[6].totalNumSns)
#define CapSense_BUTTON6_TOTAL_NUM_SNS_OFFSET               (214u)
#define CapSense_BUTTON6_TOTAL_NUM_SNS_SIZE                 (2u)
#define CapSense_BUTTON6_TOTAL_NUM_SNS_PARAM_ID             (0x920600D6u)

#define CapSense_BUTTON6_TYPE_VALUE                         (CapSense_dsFlash.wdgtArray[6].wdgtType)
#define CapSense_BUTTON6_TYPE_OFFSET                        (216u)
#define CapSense_BUTTON6_TYPE_SIZE                          (1u)
#define CapSense_BUTTON6_TYPE_PARAM_ID                      (0x550600D8u)

#define CapSense_BUTTON6_NUM_COLS_VALUE                     (CapSense_dsFlash.wdgtArray[6].numCols)
#define CapSense_BUTTON6_NUM_COLS_OFFSET                    (217u)
#define CapSense_BUTTON6_NUM_COLS_SIZE                      (1u)
#define CapSense_BUTTON6_NUM_COLS_PARAM_ID                  (0x530600D9u)

#define CapSense_BUTTON6_PTR2NOISE_ENVLP_VALUE              (CapSense_dsFlash.wdgtArray[6].ptr2NoiseEnvlp)
#define CapSense_BUTTON6_PTR2NOISE_ENVLP_OFFSET             (220u)
#define CapSense_BUTTON6_PTR2NOISE_ENVLP_SIZE               (4u)
#define CapSense_BUTTON6_PTR2NOISE_ENVLP_PARAM_ID           (0xD30600DCu)

#define CapSense_BUTTON7_PTR2SNS_FLASH_VALUE                (CapSense_dsFlash.wdgtArray[7].ptr2SnsFlash)
#define CapSense_BUTTON7_PTR2SNS_FLASH_OFFSET               (224u)
#define CapSense_BUTTON7_PTR2SNS_FLASH_SIZE                 (4u)
#define CapSense_BUTTON7_PTR2SNS_FLASH_PARAM_ID             (0xDC0700E0u)

#define CapSense_BUTTON7_PTR2WD_RAM_VALUE                   (CapSense_dsFlash.wdgtArray[7].ptr2WdgtRam)
#define CapSense_BUTTON7_PTR2WD_RAM_OFFSET                  (228u)
#define CapSense_BUTTON7_PTR2WD_RAM_SIZE                    (4u)
#define CapSense_BUTTON7_PTR2WD_RAM_PARAM_ID                (0xDD0700E4u)

#define CapSense_BUTTON7_PTR2SNS_RAM_VALUE                  (CapSense_dsFlash.wdgtArray[7].ptr2SnsRam)
#define CapSense_BUTTON7_PTR2SNS_RAM_OFFSET                 (232u)
#define CapSense_BUTTON7_PTR2SNS_RAM_SIZE                   (4u)
#define CapSense_BUTTON7_PTR2SNS_RAM_PARAM_ID               (0xDE0700E8u)

#define CapSense_BUTTON7_PTR2FLTR_HISTORY_VALUE             (CapSense_dsFlash.wdgtArray[7].ptr2FltrHistory)
#define CapSense_BUTTON7_PTR2FLTR_HISTORY_OFFSET            (236u)
#define CapSense_BUTTON7_PTR2FLTR_HISTORY_SIZE              (4u)
#define CapSense_BUTTON7_PTR2FLTR_HISTORY_PARAM_ID          (0xDF0700ECu)

#define CapSense_BUTTON7_PTR2DEBOUNCE_VALUE                 (CapSense_dsFlash.wdgtArray[7].ptr2DebounceArr)
#define CapSense_BUTTON7_PTR2DEBOUNCE_OFFSET                (240u)
#define CapSense_BUTTON7_PTR2DEBOUNCE_SIZE                  (4u)
#define CapSense_BUTTON7_PTR2DEBOUNCE_PARAM_ID              (0xD90700F0u)

#define CapSense_BUTTON7_STATIC_CONFIG_VALUE                (CapSense_dsFlash.wdgtArray[7].staticConfig)
#define CapSense_BUTTON7_STATIC_CONFIG_OFFSET               (244u)
#define CapSense_BUTTON7_STATIC_CONFIG_SIZE                 (2u)
#define CapSense_BUTTON7_STATIC_CONFIG_PARAM_ID             (0x970700F4u)

#define CapSense_BUTTON7_TOTAL_NUM_SNS_VALUE                (CapSense_dsFlash.wdgtArray[7].totalNumSns)
#define CapSense_BUTTON7_TOTAL_NUM_SNS_OFFSET               (246u)
#define CapSense_BUTTON7_TOTAL_NUM_SNS_SIZE                 (2u)
#define CapSense_BUTTON7_TOTAL_NUM_SNS_PARAM_ID             (0x9B0700F6u)

#define CapSense_BUTTON7_TYPE_VALUE                         (CapSense_dsFlash.wdgtArray[7].wdgtType)
#define CapSense_BUTTON7_TYPE_OFFSET                        (248u)
#define CapSense_BUTTON7_TYPE_SIZE                          (1u)
#define CapSense_BUTTON7_TYPE_PARAM_ID                      (0x5C0700F8u)

#define CapSense_BUTTON7_NUM_COLS_VALUE                     (CapSense_dsFlash.wdgtArray[7].numCols)
#define CapSense_BUTTON7_NUM_COLS_OFFSET                    (249u)
#define CapSense_BUTTON7_NUM_COLS_SIZE                      (1u)
#define CapSense_BUTTON7_NUM_COLS_PARAM_ID                  (0x5A0700F9u)

#define CapSense_BUTTON7_PTR2NOISE_ENVLP_VALUE              (CapSense_dsFlash.wdgtArray[7].ptr2NoiseEnvlp)
#define CapSense_BUTTON7_PTR2NOISE_ENVLP_OFFSET             (252u)
#define CapSense_BUTTON7_PTR2NOISE_ENVLP_SIZE               (4u)
#define CapSense_BUTTON7_PTR2NOISE_ENVLP_PARAM_ID           (0xDA0700FCu)

#define CapSense_BUTTON8_PTR2SNS_FLASH_VALUE                (CapSense_dsFlash.wdgtArray[8].ptr2SnsFlash)
#define CapSense_BUTTON8_PTR2SNS_FLASH_OFFSET               (256u)
#define CapSense_BUTTON8_PTR2SNS_FLASH_SIZE                 (4u)
#define CapSense_BUTTON8_PTR2SNS_FLASH_PARAM_ID             (0xDB080100u)

#define CapSense_BUTTON8_PTR2WD_RAM_VALUE                   (CapSense_dsFlash.wdgtArray[8].ptr2WdgtRam)
#define CapSense_BUTTON8_PTR2WD_RAM_OFFSET                  (260u)
#define CapSense_BUTTON8_PTR2WD_RAM_SIZE                    (4u)
#define CapSense_BUTTON8_PTR2WD_RAM_PARAM_ID                (0xDA080104u)

#define CapSense_BUTTON8_PTR2SNS_RAM_VALUE                  (CapSense_dsFlash.wdgtArray[8].ptr2SnsRam)
#define CapSense_BUTTON8_PTR2SNS_RAM_OFFSET                 (264u)
#define CapSense_BUTTON8_PTR2SNS_RAM_SIZE                   (4u)
#define CapSense_BUTTON8_PTR2SNS_RAM_PARAM_ID               (0xD9080108u)

#define CapSense_BUTTON8_PTR2FLTR_HISTORY_VALUE             (CapSense_dsFlash.wdgtArray[8].ptr2FltrHistory)
#define CapSense_BUTTON8_PTR2FLTR_HISTORY_OFFSET            (268u)
#define CapSense_BUTTON8_PTR2FLTR_HISTORY_SIZE              (4u)
#define CapSense_BUTTON8_PTR2FLTR_HISTORY_PARAM_ID          (0xD808010Cu)

#define CapSense_BUTTON8_PTR2DEBOUNCE_VALUE                 (CapSense_dsFlash.wdgtArray[8].ptr2DebounceArr)
#define CapSense_BUTTON8_PTR2DEBOUNCE_OFFSET                (272u)
#define CapSense_BUTTON8_PTR2DEBOUNCE_SIZE                  (4u)
#define CapSense_BUTTON8_PTR2DEBOUNCE_PARAM_ID              (0xDE080110u)

#define CapSense_BUTTON8_STATIC_CONFIG_VALUE                (CapSense_dsFlash.wdgtArray[8].staticConfig)
#define CapSense_BUTTON8_STATIC_CONFIG_OFFSET               (276u)
#define CapSense_BUTTON8_STATIC_CONFIG_SIZE                 (2u)
#define CapSense_BUTTON8_STATIC_CONFIG_PARAM_ID             (0x90080114u)

#define CapSense_BUTTON8_TOTAL_NUM_SNS_VALUE                (CapSense_dsFlash.wdgtArray[8].totalNumSns)
#define CapSense_BUTTON8_TOTAL_NUM_SNS_OFFSET               (278u)
#define CapSense_BUTTON8_TOTAL_NUM_SNS_SIZE                 (2u)
#define CapSense_BUTTON8_TOTAL_NUM_SNS_PARAM_ID             (0x9C080116u)

#define CapSense_BUTTON8_TYPE_VALUE                         (CapSense_dsFlash.wdgtArray[8].wdgtType)
#define CapSense_BUTTON8_TYPE_OFFSET                        (280u)
#define CapSense_BUTTON8_TYPE_SIZE                          (1u)
#define CapSense_BUTTON8_TYPE_PARAM_ID                      (0x5B080118u)

#define CapSense_BUTTON8_NUM_COLS_VALUE                     (CapSense_dsFlash.wdgtArray[8].numCols)
#define CapSense_BUTTON8_NUM_COLS_OFFSET                    (281u)
#define CapSense_BUTTON8_NUM_COLS_SIZE                      (1u)
#define CapSense_BUTTON8_NUM_COLS_PARAM_ID                  (0x5D080119u)

#define CapSense_BUTTON8_PTR2NOISE_ENVLP_VALUE              (CapSense_dsFlash.wdgtArray[8].ptr2NoiseEnvlp)
#define CapSense_BUTTON8_PTR2NOISE_ENVLP_OFFSET             (284u)
#define CapSense_BUTTON8_PTR2NOISE_ENVLP_SIZE               (4u)
#define CapSense_BUTTON8_PTR2NOISE_ENVLP_PARAM_ID           (0xDD08011Cu)

#define CapSense_BUTTON9_PTR2SNS_FLASH_VALUE                (CapSense_dsFlash.wdgtArray[9].ptr2SnsFlash)
#define CapSense_BUTTON9_PTR2SNS_FLASH_OFFSET               (288u)
#define CapSense_BUTTON9_PTR2SNS_FLASH_SIZE                 (4u)
#define CapSense_BUTTON9_PTR2SNS_FLASH_PARAM_ID             (0xD2090120u)

#define CapSense_BUTTON9_PTR2WD_RAM_VALUE                   (CapSense_dsFlash.wdgtArray[9].ptr2WdgtRam)
#define CapSense_BUTTON9_PTR2WD_RAM_OFFSET                  (292u)
#define CapSense_BUTTON9_PTR2WD_RAM_SIZE                    (4u)
#define CapSense_BUTTON9_PTR2WD_RAM_PARAM_ID                (0xD3090124u)

#define CapSense_BUTTON9_PTR2SNS_RAM_VALUE                  (CapSense_dsFlash.wdgtArray[9].ptr2SnsRam)
#define CapSense_BUTTON9_PTR2SNS_RAM_OFFSET                 (296u)
#define CapSense_BUTTON9_PTR2SNS_RAM_SIZE                   (4u)
#define CapSense_BUTTON9_PTR2SNS_RAM_PARAM_ID               (0xD0090128u)

#define CapSense_BUTTON9_PTR2FLTR_HISTORY_VALUE             (CapSense_dsFlash.wdgtArray[9].ptr2FltrHistory)
#define CapSense_BUTTON9_PTR2FLTR_HISTORY_OFFSET            (300u)
#define CapSense_BUTTON9_PTR2FLTR_HISTORY_SIZE              (4u)
#define CapSense_BUTTON9_PTR2FLTR_HISTORY_PARAM_ID          (0xD109012Cu)

#define CapSense_BUTTON9_PTR2DEBOUNCE_VALUE                 (CapSense_dsFlash.wdgtArray[9].ptr2DebounceArr)
#define CapSense_BUTTON9_PTR2DEBOUNCE_OFFSET                (304u)
#define CapSense_BUTTON9_PTR2DEBOUNCE_SIZE                  (4u)
#define CapSense_BUTTON9_PTR2DEBOUNCE_PARAM_ID              (0xD7090130u)

#define CapSense_BUTTON9_STATIC_CONFIG_VALUE                (CapSense_dsFlash.wdgtArray[9].staticConfig)
#define CapSense_BUTTON9_STATIC_CONFIG_OFFSET               (308u)
#define CapSense_BUTTON9_STATIC_CONFIG_SIZE                 (2u)
#define CapSense_BUTTON9_STATIC_CONFIG_PARAM_ID             (0x99090134u)

#define CapSense_BUTTON9_TOTAL_NUM_SNS_VALUE                (CapSense_dsFlash.wdgtArray[9].totalNumSns)
#define CapSense_BUTTON9_TOTAL_NUM_SNS_OFFSET               (310u)
#define CapSense_BUTTON9_TOTAL_NUM_SNS_SIZE                 (2u)
#define CapSense_BUTTON9_TOTAL_NUM_SNS_PARAM_ID             (0x95090136u)

#define CapSense_BUTTON9_TYPE_VALUE                         (CapSense_dsFlash.wdgtArray[9].wdgtType)
#define CapSense_BUTTON9_TYPE_OFFSET                        (312u)
#define CapSense_BUTTON9_TYPE_SIZE                          (1u)
#define CapSense_BUTTON9_TYPE_PARAM_ID                      (0x52090138u)

#define CapSense_BUTTON9_NUM_COLS_VALUE                     (CapSense_dsFlash.wdgtArray[9].numCols)
#define CapSense_BUTTON9_NUM_COLS_OFFSET                    (313u)
#define CapSense_BUTTON9_NUM_COLS_SIZE                      (1u)
#define CapSense_BUTTON9_NUM_COLS_PARAM_ID                  (0x54090139u)

#define CapSense_BUTTON9_PTR2NOISE_ENVLP_VALUE              (CapSense_dsFlash.wdgtArray[9].ptr2NoiseEnvlp)
#define CapSense_BUTTON9_PTR2NOISE_ENVLP_OFFSET             (316u)
#define CapSense_BUTTON9_PTR2NOISE_ENVLP_SIZE               (4u)
#define CapSense_BUTTON9_PTR2NOISE_ENVLP_PARAM_ID           (0xD409013Cu)

#define CapSense_BUTTON10_PTR2SNS_FLASH_VALUE               (CapSense_dsFlash.wdgtArray[10].ptr2SnsFlash)
#define CapSense_BUTTON10_PTR2SNS_FLASH_OFFSET              (320u)
#define CapSense_BUTTON10_PTR2SNS_FLASH_SIZE                (4u)
#define CapSense_BUTTON10_PTR2SNS_FLASH_PARAM_ID            (0xD00A0140u)

#define CapSense_BUTTON10_PTR2WD_RAM_VALUE                  (CapSense_dsFlash.wdgtArray[10].ptr2WdgtRam)
#define CapSense_BUTTON10_PTR2WD_RAM_OFFSET                 (324u)
#define CapSense_BUTTON10_PTR2WD_RAM_SIZE                   (4u)
#define CapSense_BUTTON10_PTR2WD_RAM_PARAM_ID               (0xD10A0144u)

#define CapSense_BUTTON10_PTR2SNS_RAM_VALUE                 (CapSense_dsFlash.wdgtArray[10].ptr2SnsRam)
#define CapSense_BUTTON10_PTR2SNS_RAM_OFFSET                (328u)
#define CapSense_BUTTON10_PTR2SNS_RAM_SIZE                  (4u)
#define CapSense_BUTTON10_PTR2SNS_RAM_PARAM_ID              (0xD20A0148u)

#define CapSense_BUTTON10_PTR2FLTR_HISTORY_VALUE            (CapSense_dsFlash.wdgtArray[10].ptr2FltrHistory)
#define CapSense_BUTTON10_PTR2FLTR_HISTORY_OFFSET           (332u)
#define CapSense_BUTTON10_PTR2FLTR_HISTORY_SIZE             (4u)
#define CapSense_BUTTON10_PTR2FLTR_HISTORY_PARAM_ID         (0xD30A014Cu)

#define CapSense_BUTTON10_PTR2DEBOUNCE_VALUE                (CapSense_dsFlash.wdgtArray[10].ptr2DebounceArr)
#define CapSense_BUTTON10_PTR2DEBOUNCE_OFFSET               (336u)
#define CapSense_BUTTON10_PTR2DEBOUNCE_SIZE                 (4u)
#define CapSense_BUTTON10_PTR2DEBOUNCE_PARAM_ID             (0xD50A0150u)

#define CapSense_BUTTON10_STATIC_CONFIG_VALUE               (CapSense_dsFlash.wdgtArray[10].staticConfig)
#define CapSense_BUTTON10_STATIC_CONFIG_OFFSET              (340u)
#define CapSense_BUTTON10_STATIC_CONFIG_SIZE                (2u)
#define CapSense_BUTTON10_STATIC_CONFIG_PARAM_ID            (0x9B0A0154u)

#define CapSense_BUTTON10_TOTAL_NUM_SNS_VALUE               (CapSense_dsFlash.wdgtArray[10].totalNumSns)
#define CapSense_BUTTON10_TOTAL_NUM_SNS_OFFSET              (342u)
#define CapSense_BUTTON10_TOTAL_NUM_SNS_SIZE                (2u)
#define CapSense_BUTTON10_TOTAL_NUM_SNS_PARAM_ID            (0x970A0156u)

#define CapSense_BUTTON10_TYPE_VALUE                        (CapSense_dsFlash.wdgtArray[10].wdgtType)
#define CapSense_BUTTON10_TYPE_OFFSET                       (344u)
#define CapSense_BUTTON10_TYPE_SIZE                         (1u)
#define CapSense_BUTTON10_TYPE_PARAM_ID                     (0x500A0158u)

#define CapSense_BUTTON10_NUM_COLS_VALUE                    (CapSense_dsFlash.wdgtArray[10].numCols)
#define CapSense_BUTTON10_NUM_COLS_OFFSET                   (345u)
#define CapSense_BUTTON10_NUM_COLS_SIZE                     (1u)
#define CapSense_BUTTON10_NUM_COLS_PARAM_ID                 (0x560A0159u)

#define CapSense_BUTTON10_PTR2NOISE_ENVLP_VALUE             (CapSense_dsFlash.wdgtArray[10].ptr2NoiseEnvlp)
#define CapSense_BUTTON10_PTR2NOISE_ENVLP_OFFSET            (348u)
#define CapSense_BUTTON10_PTR2NOISE_ENVLP_SIZE              (4u)
#define CapSense_BUTTON10_PTR2NOISE_ENVLP_PARAM_ID          (0xD60A015Cu)

#define CapSense_BUTTON11_PTR2SNS_FLASH_VALUE               (CapSense_dsFlash.wdgtArray[11].ptr2SnsFlash)
#define CapSense_BUTTON11_PTR2SNS_FLASH_OFFSET              (352u)
#define CapSense_BUTTON11_PTR2SNS_FLASH_SIZE                (4u)
#define CapSense_BUTTON11_PTR2SNS_FLASH_PARAM_ID            (0xD90B0160u)

#define CapSense_BUTTON11_PTR2WD_RAM_VALUE                  (CapSense_dsFlash.wdgtArray[11].ptr2WdgtRam)
#define CapSense_BUTTON11_PTR2WD_RAM_OFFSET                 (356u)
#define CapSense_BUTTON11_PTR2WD_RAM_SIZE                   (4u)
#define CapSense_BUTTON11_PTR2WD_RAM_PARAM_ID               (0xD80B0164u)

#define CapSense_BUTTON11_PTR2SNS_RAM_VALUE                 (CapSense_dsFlash.wdgtArray[11].ptr2SnsRam)
#define CapSense_BUTTON11_PTR2SNS_RAM_OFFSET                (360u)
#define CapSense_BUTTON11_PTR2SNS_RAM_SIZE                  (4u)
#define CapSense_BUTTON11_PTR2SNS_RAM_PARAM_ID              (0xDB0B0168u)

#define CapSense_BUTTON11_PTR2FLTR_HISTORY_VALUE            (CapSense_dsFlash.wdgtArray[11].ptr2FltrHistory)
#define CapSense_BUTTON11_PTR2FLTR_HISTORY_OFFSET           (364u)
#define CapSense_BUTTON11_PTR2FLTR_HISTORY_SIZE             (4u)
#define CapSense_BUTTON11_PTR2FLTR_HISTORY_PARAM_ID         (0xDA0B016Cu)

#define CapSense_BUTTON11_PTR2DEBOUNCE_VALUE                (CapSense_dsFlash.wdgtArray[11].ptr2DebounceArr)
#define CapSense_BUTTON11_PTR2DEBOUNCE_OFFSET               (368u)
#define CapSense_BUTTON11_PTR2DEBOUNCE_SIZE                 (4u)
#define CapSense_BUTTON11_PTR2DEBOUNCE_PARAM_ID             (0xDC0B0170u)

#define CapSense_BUTTON11_STATIC_CONFIG_VALUE               (CapSense_dsFlash.wdgtArray[11].staticConfig)
#define CapSense_BUTTON11_STATIC_CONFIG_OFFSET              (372u)
#define CapSense_BUTTON11_STATIC_CONFIG_SIZE                (2u)
#define CapSense_BUTTON11_STATIC_CONFIG_PARAM_ID            (0x920B0174u)

#define CapSense_BUTTON11_TOTAL_NUM_SNS_VALUE               (CapSense_dsFlash.wdgtArray[11].totalNumSns)
#define CapSense_BUTTON11_TOTAL_NUM_SNS_OFFSET              (374u)
#define CapSense_BUTTON11_TOTAL_NUM_SNS_SIZE                (2u)
#define CapSense_BUTTON11_TOTAL_NUM_SNS_PARAM_ID            (0x9E0B0176u)

#define CapSense_BUTTON11_TYPE_VALUE                        (CapSense_dsFlash.wdgtArray[11].wdgtType)
#define CapSense_BUTTON11_TYPE_OFFSET                       (376u)
#define CapSense_BUTTON11_TYPE_SIZE                         (1u)
#define CapSense_BUTTON11_TYPE_PARAM_ID                     (0x590B0178u)

#define CapSense_BUTTON11_NUM_COLS_VALUE                    (CapSense_dsFlash.wdgtArray[11].numCols)
#define CapSense_BUTTON11_NUM_COLS_OFFSET                   (377u)
#define CapSense_BUTTON11_NUM_COLS_SIZE                     (1u)
#define CapSense_BUTTON11_NUM_COLS_PARAM_ID                 (0x5F0B0179u)

#define CapSense_BUTTON11_PTR2NOISE_ENVLP_VALUE             (CapSense_dsFlash.wdgtArray[11].ptr2NoiseEnvlp)
#define CapSense_BUTTON11_PTR2NOISE_ENVLP_OFFSET            (380u)
#define CapSense_BUTTON11_PTR2NOISE_ENVLP_SIZE              (4u)
#define CapSense_BUTTON11_PTR2NOISE_ENVLP_PARAM_ID          (0xDF0B017Cu)

#define CapSense_BUTTON12_PTR2SNS_FLASH_VALUE               (CapSense_dsFlash.wdgtArray[12].ptr2SnsFlash)
#define CapSense_BUTTON12_PTR2SNS_FLASH_OFFSET              (384u)
#define CapSense_BUTTON12_PTR2SNS_FLASH_SIZE                (4u)
#define CapSense_BUTTON12_PTR2SNS_FLASH_PARAM_ID            (0xD40C0180u)

#define CapSense_BUTTON12_PTR2WD_RAM_VALUE                  (CapSense_dsFlash.wdgtArray[12].ptr2WdgtRam)
#define CapSense_BUTTON12_PTR2WD_RAM_OFFSET                 (388u)
#define CapSense_BUTTON12_PTR2WD_RAM_SIZE                   (4u)
#define CapSense_BUTTON12_PTR2WD_RAM_PARAM_ID               (0xD50C0184u)

#define CapSense_BUTTON12_PTR2SNS_RAM_VALUE                 (CapSense_dsFlash.wdgtArray[12].ptr2SnsRam)
#define CapSense_BUTTON12_PTR2SNS_RAM_OFFSET                (392u)
#define CapSense_BUTTON12_PTR2SNS_RAM_SIZE                  (4u)
#define CapSense_BUTTON12_PTR2SNS_RAM_PARAM_ID              (0xD60C0188u)

#define CapSense_BUTTON12_PTR2FLTR_HISTORY_VALUE            (CapSense_dsFlash.wdgtArray[12].ptr2FltrHistory)
#define CapSense_BUTTON12_PTR2FLTR_HISTORY_OFFSET           (396u)
#define CapSense_BUTTON12_PTR2FLTR_HISTORY_SIZE             (4u)
#define CapSense_BUTTON12_PTR2FLTR_HISTORY_PARAM_ID         (0xD70C018Cu)

#define CapSense_BUTTON12_PTR2DEBOUNCE_VALUE                (CapSense_dsFlash.wdgtArray[12].ptr2DebounceArr)
#define CapSense_BUTTON12_PTR2DEBOUNCE_OFFSET               (400u)
#define CapSense_BUTTON12_PTR2DEBOUNCE_SIZE                 (4u)
#define CapSense_BUTTON12_PTR2DEBOUNCE_PARAM_ID             (0xD10C0190u)

#define CapSense_BUTTON12_STATIC_CONFIG_VALUE               (CapSense_dsFlash.wdgtArray[12].staticConfig)
#define CapSense_BUTTON12_STATIC_CONFIG_OFFSET              (404u)
#define CapSense_BUTTON12_STATIC_CONFIG_SIZE                (2u)
#define CapSense_BUTTON12_STATIC_CONFIG_PARAM_ID            (0x9F0C0194u)

#define CapSense_BUTTON12_TOTAL_NUM_SNS_VALUE               (CapSense_dsFlash.wdgtArray[12].totalNumSns)
#define CapSense_BUTTON12_TOTAL_NUM_SNS_OFFSET              (406u)
#define CapSense_BUTTON12_TOTAL_NUM_SNS_SIZE                (2u)
#define CapSense_BUTTON12_TOTAL_NUM_SNS_PARAM_ID            (0x930C0196u)

#define CapSense_BUTTON12_TYPE_VALUE                        (CapSense_dsFlash.wdgtArray[12].wdgtType)
#define CapSense_BUTTON12_TYPE_OFFSET                       (408u)
#define CapSense_BUTTON12_TYPE_SIZE                         (1u)
#define CapSense_BUTTON12_TYPE_PARAM_ID                     (0x540C0198u)

#define CapSense_BUTTON12_NUM_COLS_VALUE                    (CapSense_dsFlash.wdgtArray[12].numCols)
#define CapSense_BUTTON12_NUM_COLS_OFFSET                   (409u)
#define CapSense_BUTTON12_NUM_COLS_SIZE                     (1u)
#define CapSense_BUTTON12_NUM_COLS_PARAM_ID                 (0x520C0199u)

#define CapSense_BUTTON12_PTR2NOISE_ENVLP_VALUE             (CapSense_dsFlash.wdgtArray[12].ptr2NoiseEnvlp)
#define CapSense_BUTTON12_PTR2NOISE_ENVLP_OFFSET            (412u)
#define CapSense_BUTTON12_PTR2NOISE_ENVLP_SIZE              (4u)
#define CapSense_BUTTON12_PTR2NOISE_ENVLP_PARAM_ID          (0xD20C019Cu)

#define CapSense_BUTTON13_PTR2SNS_FLASH_VALUE               (CapSense_dsFlash.wdgtArray[13].ptr2SnsFlash)
#define CapSense_BUTTON13_PTR2SNS_FLASH_OFFSET              (416u)
#define CapSense_BUTTON13_PTR2SNS_FLASH_SIZE                (4u)
#define CapSense_BUTTON13_PTR2SNS_FLASH_PARAM_ID            (0xDD0D01A0u)

#define CapSense_BUTTON13_PTR2WD_RAM_VALUE                  (CapSense_dsFlash.wdgtArray[13].ptr2WdgtRam)
#define CapSense_BUTTON13_PTR2WD_RAM_OFFSET                 (420u)
#define CapSense_BUTTON13_PTR2WD_RAM_SIZE                   (4u)
#define CapSense_BUTTON13_PTR2WD_RAM_PARAM_ID               (0xDC0D01A4u)

#define CapSense_BUTTON13_PTR2SNS_RAM_VALUE                 (CapSense_dsFlash.wdgtArray[13].ptr2SnsRam)
#define CapSense_BUTTON13_PTR2SNS_RAM_OFFSET                (424u)
#define CapSense_BUTTON13_PTR2SNS_RAM_SIZE                  (4u)
#define CapSense_BUTTON13_PTR2SNS_RAM_PARAM_ID              (0xDF0D01A8u)

#define CapSense_BUTTON13_PTR2FLTR_HISTORY_VALUE            (CapSense_dsFlash.wdgtArray[13].ptr2FltrHistory)
#define CapSense_BUTTON13_PTR2FLTR_HISTORY_OFFSET           (428u)
#define CapSense_BUTTON13_PTR2FLTR_HISTORY_SIZE             (4u)
#define CapSense_BUTTON13_PTR2FLTR_HISTORY_PARAM_ID         (0xDE0D01ACu)

#define CapSense_BUTTON13_PTR2DEBOUNCE_VALUE                (CapSense_dsFlash.wdgtArray[13].ptr2DebounceArr)
#define CapSense_BUTTON13_PTR2DEBOUNCE_OFFSET               (432u)
#define CapSense_BUTTON13_PTR2DEBOUNCE_SIZE                 (4u)
#define CapSense_BUTTON13_PTR2DEBOUNCE_PARAM_ID             (0xD80D01B0u)

#define CapSense_BUTTON13_STATIC_CONFIG_VALUE               (CapSense_dsFlash.wdgtArray[13].staticConfig)
#define CapSense_BUTTON13_STATIC_CONFIG_OFFSET              (436u)
#define CapSense_BUTTON13_STATIC_CONFIG_SIZE                (2u)
#define CapSense_BUTTON13_STATIC_CONFIG_PARAM_ID            (0x960D01B4u)

#define CapSense_BUTTON13_TOTAL_NUM_SNS_VALUE               (CapSense_dsFlash.wdgtArray[13].totalNumSns)
#define CapSense_BUTTON13_TOTAL_NUM_SNS_OFFSET              (438u)
#define CapSense_BUTTON13_TOTAL_NUM_SNS_SIZE                (2u)
#define CapSense_BUTTON13_TOTAL_NUM_SNS_PARAM_ID            (0x9A0D01B6u)

#define CapSense_BUTTON13_TYPE_VALUE                        (CapSense_dsFlash.wdgtArray[13].wdgtType)
#define CapSense_BUTTON13_TYPE_OFFSET                       (440u)
#define CapSense_BUTTON13_TYPE_SIZE                         (1u)
#define CapSense_BUTTON13_TYPE_PARAM_ID                     (0x5D0D01B8u)

#define CapSense_BUTTON13_NUM_COLS_VALUE                    (CapSense_dsFlash.wdgtArray[13].numCols)
#define CapSense_BUTTON13_NUM_COLS_OFFSET                   (441u)
#define CapSense_BUTTON13_NUM_COLS_SIZE                     (1u)
#define CapSense_BUTTON13_NUM_COLS_PARAM_ID                 (0x5B0D01B9u)

#define CapSense_BUTTON13_PTR2NOISE_ENVLP_VALUE             (CapSense_dsFlash.wdgtArray[13].ptr2NoiseEnvlp)
#define CapSense_BUTTON13_PTR2NOISE_ENVLP_OFFSET            (444u)
#define CapSense_BUTTON13_PTR2NOISE_ENVLP_SIZE              (4u)
#define CapSense_BUTTON13_PTR2NOISE_ENVLP_PARAM_ID          (0xDB0D01BCu)

#define CapSense_BUTTON14_PTR2SNS_FLASH_VALUE               (CapSense_dsFlash.wdgtArray[14].ptr2SnsFlash)
#define CapSense_BUTTON14_PTR2SNS_FLASH_OFFSET              (448u)
#define CapSense_BUTTON14_PTR2SNS_FLASH_SIZE                (4u)
#define CapSense_BUTTON14_PTR2SNS_FLASH_PARAM_ID            (0xDF0E01C0u)

#define CapSense_BUTTON14_PTR2WD_RAM_VALUE                  (CapSense_dsFlash.wdgtArray[14].ptr2WdgtRam)
#define CapSense_BUTTON14_PTR2WD_RAM_OFFSET                 (452u)
#define CapSense_BUTTON14_PTR2WD_RAM_SIZE                   (4u)
#define CapSense_BUTTON14_PTR2WD_RAM_PARAM_ID               (0xDE0E01C4u)

#define CapSense_BUTTON14_PTR2SNS_RAM_VALUE                 (CapSense_dsFlash.wdgtArray[14].ptr2SnsRam)
#define CapSense_BUTTON14_PTR2SNS_RAM_OFFSET                (456u)
#define CapSense_BUTTON14_PTR2SNS_RAM_SIZE                  (4u)
#define CapSense_BUTTON14_PTR2SNS_RAM_PARAM_ID              (0xDD0E01C8u)

#define CapSense_BUTTON14_PTR2FLTR_HISTORY_VALUE            (CapSense_dsFlash.wdgtArray[14].ptr2FltrHistory)
#define CapSense_BUTTON14_PTR2FLTR_HISTORY_OFFSET           (460u)
#define CapSense_BUTTON14_PTR2FLTR_HISTORY_SIZE             (4u)
#define CapSense_BUTTON14_PTR2FLTR_HISTORY_PARAM_ID         (0xDC0E01CCu)

#define CapSense_BUTTON14_PTR2DEBOUNCE_VALUE                (CapSense_dsFlash.wdgtArray[14].ptr2DebounceArr)
#define CapSense_BUTTON14_PTR2DEBOUNCE_OFFSET               (464u)
#define CapSense_BUTTON14_PTR2DEBOUNCE_SIZE                 (4u)
#define CapSense_BUTTON14_PTR2DEBOUNCE_PARAM_ID             (0xDA0E01D0u)

#define CapSense_BUTTON14_STATIC_CONFIG_VALUE               (CapSense_dsFlash.wdgtArray[14].staticConfig)
#define CapSense_BUTTON14_STATIC_CONFIG_OFFSET              (468u)
#define CapSense_BUTTON14_STATIC_CONFIG_SIZE                (2u)
#define CapSense_BUTTON14_STATIC_CONFIG_PARAM_ID            (0x940E01D4u)

#define CapSense_BUTTON14_TOTAL_NUM_SNS_VALUE               (CapSense_dsFlash.wdgtArray[14].totalNumSns)
#define CapSense_BUTTON14_TOTAL_NUM_SNS_OFFSET              (470u)
#define CapSense_BUTTON14_TOTAL_NUM_SNS_SIZE                (2u)
#define CapSense_BUTTON14_TOTAL_NUM_SNS_PARAM_ID            (0x980E01D6u)

#define CapSense_BUTTON14_TYPE_VALUE                        (CapSense_dsFlash.wdgtArray[14].wdgtType)
#define CapSense_BUTTON14_TYPE_OFFSET                       (472u)
#define CapSense_BUTTON14_TYPE_SIZE                         (1u)
#define CapSense_BUTTON14_TYPE_PARAM_ID                     (0x5F0E01D8u)

#define CapSense_BUTTON14_NUM_COLS_VALUE                    (CapSense_dsFlash.wdgtArray[14].numCols)
#define CapSense_BUTTON14_NUM_COLS_OFFSET                   (473u)
#define CapSense_BUTTON14_NUM_COLS_SIZE                     (1u)
#define CapSense_BUTTON14_NUM_COLS_PARAM_ID                 (0x590E01D9u)

#define CapSense_BUTTON14_PTR2NOISE_ENVLP_VALUE             (CapSense_dsFlash.wdgtArray[14].ptr2NoiseEnvlp)
#define CapSense_BUTTON14_PTR2NOISE_ENVLP_OFFSET            (476u)
#define CapSense_BUTTON14_PTR2NOISE_ENVLP_SIZE              (4u)
#define CapSense_BUTTON14_PTR2NOISE_ENVLP_PARAM_ID          (0xD90E01DCu)

#define CapSense_BUTTON15_PTR2SNS_FLASH_VALUE               (CapSense_dsFlash.wdgtArray[15].ptr2SnsFlash)
#define CapSense_BUTTON15_PTR2SNS_FLASH_OFFSET              (480u)
#define CapSense_BUTTON15_PTR2SNS_FLASH_SIZE                (4u)
#define CapSense_BUTTON15_PTR2SNS_FLASH_PARAM_ID            (0xD60F01E0u)

#define CapSense_BUTTON15_PTR2WD_RAM_VALUE                  (CapSense_dsFlash.wdgtArray[15].ptr2WdgtRam)
#define CapSense_BUTTON15_PTR2WD_RAM_OFFSET                 (484u)
#define CapSense_BUTTON15_PTR2WD_RAM_SIZE                   (4u)
#define CapSense_BUTTON15_PTR2WD_RAM_PARAM_ID               (0xD70F01E4u)

#define CapSense_BUTTON15_PTR2SNS_RAM_VALUE                 (CapSense_dsFlash.wdgtArray[15].ptr2SnsRam)
#define CapSense_BUTTON15_PTR2SNS_RAM_OFFSET                (488u)
#define CapSense_BUTTON15_PTR2SNS_RAM_SIZE                  (4u)
#define CapSense_BUTTON15_PTR2SNS_RAM_PARAM_ID              (0xD40F01E8u)

#define CapSense_BUTTON15_PTR2FLTR_HISTORY_VALUE            (CapSense_dsFlash.wdgtArray[15].ptr2FltrHistory)
#define CapSense_BUTTON15_PTR2FLTR_HISTORY_OFFSET           (492u)
#define CapSense_BUTTON15_PTR2FLTR_HISTORY_SIZE             (4u)
#define CapSense_BUTTON15_PTR2FLTR_HISTORY_PARAM_ID         (0xD50F01ECu)

#define CapSense_BUTTON15_PTR2DEBOUNCE_VALUE                (CapSense_dsFlash.wdgtArray[15].ptr2DebounceArr)
#define CapSense_BUTTON15_PTR2DEBOUNCE_OFFSET               (496u)
#define CapSense_BUTTON15_PTR2DEBOUNCE_SIZE                 (4u)
#define CapSense_BUTTON15_PTR2DEBOUNCE_PARAM_ID             (0xD30F01F0u)

#define CapSense_BUTTON15_STATIC_CONFIG_VALUE               (CapSense_dsFlash.wdgtArray[15].staticConfig)
#define CapSense_BUTTON15_STATIC_CONFIG_OFFSET              (500u)
#define CapSense_BUTTON15_STATIC_CONFIG_SIZE                (2u)
#define CapSense_BUTTON15_STATIC_CONFIG_PARAM_ID            (0x9D0F01F4u)

#define CapSense_BUTTON15_TOTAL_NUM_SNS_VALUE               (CapSense_dsFlash.wdgtArray[15].totalNumSns)
#define CapSense_BUTTON15_TOTAL_NUM_SNS_OFFSET              (502u)
#define CapSense_BUTTON15_TOTAL_NUM_SNS_SIZE                (2u)
#define CapSense_BUTTON15_TOTAL_NUM_SNS_PARAM_ID            (0x910F01F6u)

#define CapSense_BUTTON15_TYPE_VALUE                        (CapSense_dsFlash.wdgtArray[15].wdgtType)
#define CapSense_BUTTON15_TYPE_OFFSET                       (504u)
#define CapSense_BUTTON15_TYPE_SIZE                         (1u)
#define CapSense_BUTTON15_TYPE_PARAM_ID                     (0x560F01F8u)

#define CapSense_BUTTON15_NUM_COLS_VALUE                    (CapSense_dsFlash.wdgtArray[15].numCols)
#define CapSense_BUTTON15_NUM_COLS_OFFSET                   (505u)
#define CapSense_BUTTON15_NUM_COLS_SIZE                     (1u)
#define CapSense_BUTTON15_NUM_COLS_PARAM_ID                 (0x500F01F9u)

#define CapSense_BUTTON15_PTR2NOISE_ENVLP_VALUE             (CapSense_dsFlash.wdgtArray[15].ptr2NoiseEnvlp)
#define CapSense_BUTTON15_PTR2NOISE_ENVLP_OFFSET            (508u)
#define CapSense_BUTTON15_PTR2NOISE_ENVLP_SIZE              (4u)
#define CapSense_BUTTON15_PTR2NOISE_ENVLP_PARAM_ID          (0xD00F01FCu)

#define CapSense_BUTTON16_PTR2SNS_FLASH_VALUE               (CapSense_dsFlash.wdgtArray[16].ptr2SnsFlash)
#define CapSense_BUTTON16_PTR2SNS_FLASH_OFFSET              (512u)
#define CapSense_BUTTON16_PTR2SNS_FLASH_SIZE                (4u)
#define CapSense_BUTTON16_PTR2SNS_FLASH_PARAM_ID            (0xD0100200u)

#define CapSense_BUTTON16_PTR2WD_RAM_VALUE                  (CapSense_dsFlash.wdgtArray[16].ptr2WdgtRam)
#define CapSense_BUTTON16_PTR2WD_RAM_OFFSET                 (516u)
#define CapSense_BUTTON16_PTR2WD_RAM_SIZE                   (4u)
#define CapSense_BUTTON16_PTR2WD_RAM_PARAM_ID               (0xD1100204u)

#define CapSense_BUTTON16_PTR2SNS_RAM_VALUE                 (CapSense_dsFlash.wdgtArray[16].ptr2SnsRam)
#define CapSense_BUTTON16_PTR2SNS_RAM_OFFSET                (520u)
#define CapSense_BUTTON16_PTR2SNS_RAM_SIZE                  (4u)
#define CapSense_BUTTON16_PTR2SNS_RAM_PARAM_ID              (0xD2100208u)

#define CapSense_BUTTON16_PTR2FLTR_HISTORY_VALUE            (CapSense_dsFlash.wdgtArray[16].ptr2FltrHistory)
#define CapSense_BUTTON16_PTR2FLTR_HISTORY_OFFSET           (524u)
#define CapSense_BUTTON16_PTR2FLTR_HISTORY_SIZE             (4u)
#define CapSense_BUTTON16_PTR2FLTR_HISTORY_PARAM_ID         (0xD310020Cu)

#define CapSense_BUTTON16_PTR2DEBOUNCE_VALUE                (CapSense_dsFlash.wdgtArray[16].ptr2DebounceArr)
#define CapSense_BUTTON16_PTR2DEBOUNCE_OFFSET               (528u)
#define CapSense_BUTTON16_PTR2DEBOUNCE_SIZE                 (4u)
#define CapSense_BUTTON16_PTR2DEBOUNCE_PARAM_ID             (0xD5100210u)

#define CapSense_BUTTON16_STATIC_CONFIG_VALUE               (CapSense_dsFlash.wdgtArray[16].staticConfig)
#define CapSense_BUTTON16_STATIC_CONFIG_OFFSET              (532u)
#define CapSense_BUTTON16_STATIC_CONFIG_SIZE                (2u)
#define CapSense_BUTTON16_STATIC_CONFIG_PARAM_ID            (0x9B100214u)

#define CapSense_BUTTON16_TOTAL_NUM_SNS_VALUE               (CapSense_dsFlash.wdgtArray[16].totalNumSns)
#define CapSense_BUTTON16_TOTAL_NUM_SNS_OFFSET              (534u)
#define CapSense_BUTTON16_TOTAL_NUM_SNS_SIZE                (2u)
#define CapSense_BUTTON16_TOTAL_NUM_SNS_PARAM_ID            (0x97100216u)

#define CapSense_BUTTON16_TYPE_VALUE                        (CapSense_dsFlash.wdgtArray[16].wdgtType)
#define CapSense_BUTTON16_TYPE_OFFSET                       (536u)
#define CapSense_BUTTON16_TYPE_SIZE                         (1u)
#define CapSense_BUTTON16_TYPE_PARAM_ID                     (0x50100218u)

#define CapSense_BUTTON16_NUM_COLS_VALUE                    (CapSense_dsFlash.wdgtArray[16].numCols)
#define CapSense_BUTTON16_NUM_COLS_OFFSET                   (537u)
#define CapSense_BUTTON16_NUM_COLS_SIZE                     (1u)
#define CapSense_BUTTON16_NUM_COLS_PARAM_ID                 (0x56100219u)

#define CapSense_BUTTON16_PTR2NOISE_ENVLP_VALUE             (CapSense_dsFlash.wdgtArray[16].ptr2NoiseEnvlp)
#define CapSense_BUTTON16_PTR2NOISE_ENVLP_OFFSET            (540u)
#define CapSense_BUTTON16_PTR2NOISE_ENVLP_SIZE              (4u)
#define CapSense_BUTTON16_PTR2NOISE_ENVLP_PARAM_ID          (0xD610021Cu)

#define CapSense_BUTTON17_PTR2SNS_FLASH_VALUE               (CapSense_dsFlash.wdgtArray[17].ptr2SnsFlash)
#define CapSense_BUTTON17_PTR2SNS_FLASH_OFFSET              (544u)
#define CapSense_BUTTON17_PTR2SNS_FLASH_SIZE                (4u)
#define CapSense_BUTTON17_PTR2SNS_FLASH_PARAM_ID            (0xD9110220u)

#define CapSense_BUTTON17_PTR2WD_RAM_VALUE                  (CapSense_dsFlash.wdgtArray[17].ptr2WdgtRam)
#define CapSense_BUTTON17_PTR2WD_RAM_OFFSET                 (548u)
#define CapSense_BUTTON17_PTR2WD_RAM_SIZE                   (4u)
#define CapSense_BUTTON17_PTR2WD_RAM_PARAM_ID               (0xD8110224u)

#define CapSense_BUTTON17_PTR2SNS_RAM_VALUE                 (CapSense_dsFlash.wdgtArray[17].ptr2SnsRam)
#define CapSense_BUTTON17_PTR2SNS_RAM_OFFSET                (552u)
#define CapSense_BUTTON17_PTR2SNS_RAM_SIZE                  (4u)
#define CapSense_BUTTON17_PTR2SNS_RAM_PARAM_ID              (0xDB110228u)

#define CapSense_BUTTON17_PTR2FLTR_HISTORY_VALUE            (CapSense_dsFlash.wdgtArray[17].ptr2FltrHistory)
#define CapSense_BUTTON17_PTR2FLTR_HISTORY_OFFSET           (556u)
#define CapSense_BUTTON17_PTR2FLTR_HISTORY_SIZE             (4u)
#define CapSense_BUTTON17_PTR2FLTR_HISTORY_PARAM_ID         (0xDA11022Cu)

#define CapSense_BUTTON17_PTR2DEBOUNCE_VALUE                (CapSense_dsFlash.wdgtArray[17].ptr2DebounceArr)
#define CapSense_BUTTON17_PTR2DEBOUNCE_OFFSET               (560u)
#define CapSense_BUTTON17_PTR2DEBOUNCE_SIZE                 (4u)
#define CapSense_BUTTON17_PTR2DEBOUNCE_PARAM_ID             (0xDC110230u)

#define CapSense_BUTTON17_STATIC_CONFIG_VALUE               (CapSense_dsFlash.wdgtArray[17].staticConfig)
#define CapSense_BUTTON17_STATIC_CONFIG_OFFSET              (564u)
#define CapSense_BUTTON17_STATIC_CONFIG_SIZE                (2u)
#define CapSense_BUTTON17_STATIC_CONFIG_PARAM_ID            (0x92110234u)

#define CapSense_BUTTON17_TOTAL_NUM_SNS_VALUE               (CapSense_dsFlash.wdgtArray[17].totalNumSns)
#define CapSense_BUTTON17_TOTAL_NUM_SNS_OFFSET              (566u)
#define CapSense_BUTTON17_TOTAL_NUM_SNS_SIZE                (2u)
#define CapSense_BUTTON17_TOTAL_NUM_SNS_PARAM_ID            (0x9E110236u)

#define CapSense_BUTTON17_TYPE_VALUE                        (CapSense_dsFlash.wdgtArray[17].wdgtType)
#define CapSense_BUTTON17_TYPE_OFFSET                       (568u)
#define CapSense_BUTTON17_TYPE_SIZE                         (1u)
#define CapSense_BUTTON17_TYPE_PARAM_ID                     (0x59110238u)

#define CapSense_BUTTON17_NUM_COLS_VALUE                    (CapSense_dsFlash.wdgtArray[17].numCols)
#define CapSense_BUTTON17_NUM_COLS_OFFSET                   (569u)
#define CapSense_BUTTON17_NUM_COLS_SIZE                     (1u)
#define CapSense_BUTTON17_NUM_COLS_PARAM_ID                 (0x5F110239u)

#define CapSense_BUTTON17_PTR2NOISE_ENVLP_VALUE             (CapSense_dsFlash.wdgtArray[17].ptr2NoiseEnvlp)
#define CapSense_BUTTON17_PTR2NOISE_ENVLP_OFFSET            (572u)
#define CapSense_BUTTON17_PTR2NOISE_ENVLP_SIZE              (4u)
#define CapSense_BUTTON17_PTR2NOISE_ENVLP_PARAM_ID          (0xDF11023Cu)

#define CapSense_BUTTON18_PTR2SNS_FLASH_VALUE               (CapSense_dsFlash.wdgtArray[18].ptr2SnsFlash)
#define CapSense_BUTTON18_PTR2SNS_FLASH_OFFSET              (576u)
#define CapSense_BUTTON18_PTR2SNS_FLASH_SIZE                (4u)
#define CapSense_BUTTON18_PTR2SNS_FLASH_PARAM_ID            (0xDB120240u)

#define CapSense_BUTTON18_PTR2WD_RAM_VALUE                  (CapSense_dsFlash.wdgtArray[18].ptr2WdgtRam)
#define CapSense_BUTTON18_PTR2WD_RAM_OFFSET                 (580u)
#define CapSense_BUTTON18_PTR2WD_RAM_SIZE                   (4u)
#define CapSense_BUTTON18_PTR2WD_RAM_PARAM_ID               (0xDA120244u)

#define CapSense_BUTTON18_PTR2SNS_RAM_VALUE                 (CapSense_dsFlash.wdgtArray[18].ptr2SnsRam)
#define CapSense_BUTTON18_PTR2SNS_RAM_OFFSET                (584u)
#define CapSense_BUTTON18_PTR2SNS_RAM_SIZE                  (4u)
#define CapSense_BUTTON18_PTR2SNS_RAM_PARAM_ID              (0xD9120248u)

#define CapSense_BUTTON18_PTR2FLTR_HISTORY_VALUE            (CapSense_dsFlash.wdgtArray[18].ptr2FltrHistory)
#define CapSense_BUTTON18_PTR2FLTR_HISTORY_OFFSET           (588u)
#define CapSense_BUTTON18_PTR2FLTR_HISTORY_SIZE             (4u)
#define CapSense_BUTTON18_PTR2FLTR_HISTORY_PARAM_ID         (0xD812024Cu)

#define CapSense_BUTTON18_PTR2DEBOUNCE_VALUE                (CapSense_dsFlash.wdgtArray[18].ptr2DebounceArr)
#define CapSense_BUTTON18_PTR2DEBOUNCE_OFFSET               (592u)
#define CapSense_BUTTON18_PTR2DEBOUNCE_SIZE                 (4u)
#define CapSense_BUTTON18_PTR2DEBOUNCE_PARAM_ID             (0xDE120250u)

#define CapSense_BUTTON18_STATIC_CONFIG_VALUE               (CapSense_dsFlash.wdgtArray[18].staticConfig)
#define CapSense_BUTTON18_STATIC_CONFIG_OFFSET              (596u)
#define CapSense_BUTTON18_STATIC_CONFIG_SIZE                (2u)
#define CapSense_BUTTON18_STATIC_CONFIG_PARAM_ID            (0x90120254u)

#define CapSense_BUTTON18_TOTAL_NUM_SNS_VALUE               (CapSense_dsFlash.wdgtArray[18].totalNumSns)
#define CapSense_BUTTON18_TOTAL_NUM_SNS_OFFSET              (598u)
#define CapSense_BUTTON18_TOTAL_NUM_SNS_SIZE                (2u)
#define CapSense_BUTTON18_TOTAL_NUM_SNS_PARAM_ID            (0x9C120256u)

#define CapSense_BUTTON18_TYPE_VALUE                        (CapSense_dsFlash.wdgtArray[18].wdgtType)
#define CapSense_BUTTON18_TYPE_OFFSET                       (600u)
#define CapSense_BUTTON18_TYPE_SIZE                         (1u)
#define CapSense_BUTTON18_TYPE_PARAM_ID                     (0x5B120258u)

#define CapSense_BUTTON18_NUM_COLS_VALUE                    (CapSense_dsFlash.wdgtArray[18].numCols)
#define CapSense_BUTTON18_NUM_COLS_OFFSET                   (601u)
#define CapSense_BUTTON18_NUM_COLS_SIZE                     (1u)
#define CapSense_BUTTON18_NUM_COLS_PARAM_ID                 (0x5D120259u)

#define CapSense_BUTTON18_PTR2NOISE_ENVLP_VALUE             (CapSense_dsFlash.wdgtArray[18].ptr2NoiseEnvlp)
#define CapSense_BUTTON18_PTR2NOISE_ENVLP_OFFSET            (604u)
#define CapSense_BUTTON18_PTR2NOISE_ENVLP_SIZE              (4u)
#define CapSense_BUTTON18_PTR2NOISE_ENVLP_PARAM_ID          (0xDD12025Cu)

#define CapSense_BUTTON19_PTR2SNS_FLASH_VALUE               (CapSense_dsFlash.wdgtArray[19].ptr2SnsFlash)
#define CapSense_BUTTON19_PTR2SNS_FLASH_OFFSET              (608u)
#define CapSense_BUTTON19_PTR2SNS_FLASH_SIZE                (4u)
#define CapSense_BUTTON19_PTR2SNS_FLASH_PARAM_ID            (0xD2130260u)

#define CapSense_BUTTON19_PTR2WD_RAM_VALUE                  (CapSense_dsFlash.wdgtArray[19].ptr2WdgtRam)
#define CapSense_BUTTON19_PTR2WD_RAM_OFFSET                 (612u)
#define CapSense_BUTTON19_PTR2WD_RAM_SIZE                   (4u)
#define CapSense_BUTTON19_PTR2WD_RAM_PARAM_ID               (0xD3130264u)

#define CapSense_BUTTON19_PTR2SNS_RAM_VALUE                 (CapSense_dsFlash.wdgtArray[19].ptr2SnsRam)
#define CapSense_BUTTON19_PTR2SNS_RAM_OFFSET                (616u)
#define CapSense_BUTTON19_PTR2SNS_RAM_SIZE                  (4u)
#define CapSense_BUTTON19_PTR2SNS_RAM_PARAM_ID              (0xD0130268u)

#define CapSense_BUTTON19_PTR2FLTR_HISTORY_VALUE            (CapSense_dsFlash.wdgtArray[19].ptr2FltrHistory)
#define CapSense_BUTTON19_PTR2FLTR_HISTORY_OFFSET           (620u)
#define CapSense_BUTTON19_PTR2FLTR_HISTORY_SIZE             (4u)
#define CapSense_BUTTON19_PTR2FLTR_HISTORY_PARAM_ID         (0xD113026Cu)

#define CapSense_BUTTON19_PTR2DEBOUNCE_VALUE                (CapSense_dsFlash.wdgtArray[19].ptr2DebounceArr)
#define CapSense_BUTTON19_PTR2DEBOUNCE_OFFSET               (624u)
#define CapSense_BUTTON19_PTR2DEBOUNCE_SIZE                 (4u)
#define CapSense_BUTTON19_PTR2DEBOUNCE_PARAM_ID             (0xD7130270u)

#define CapSense_BUTTON19_STATIC_CONFIG_VALUE               (CapSense_dsFlash.wdgtArray[19].staticConfig)
#define CapSense_BUTTON19_STATIC_CONFIG_OFFSET              (628u)
#define CapSense_BUTTON19_STATIC_CONFIG_SIZE                (2u)
#define CapSense_BUTTON19_STATIC_CONFIG_PARAM_ID            (0x99130274u)

#define CapSense_BUTTON19_TOTAL_NUM_SNS_VALUE               (CapSense_dsFlash.wdgtArray[19].totalNumSns)
#define CapSense_BUTTON19_TOTAL_NUM_SNS_OFFSET              (630u)
#define CapSense_BUTTON19_TOTAL_NUM_SNS_SIZE                (2u)
#define CapSense_BUTTON19_TOTAL_NUM_SNS_PARAM_ID            (0x95130276u)

#define CapSense_BUTTON19_TYPE_VALUE                        (CapSense_dsFlash.wdgtArray[19].wdgtType)
#define CapSense_BUTTON19_TYPE_OFFSET                       (632u)
#define CapSense_BUTTON19_TYPE_SIZE                         (1u)
#define CapSense_BUTTON19_TYPE_PARAM_ID                     (0x52130278u)

#define CapSense_BUTTON19_NUM_COLS_VALUE                    (CapSense_dsFlash.wdgtArray[19].numCols)
#define CapSense_BUTTON19_NUM_COLS_OFFSET                   (633u)
#define CapSense_BUTTON19_NUM_COLS_SIZE                     (1u)
#define CapSense_BUTTON19_NUM_COLS_PARAM_ID                 (0x54130279u)

#define CapSense_BUTTON19_PTR2NOISE_ENVLP_VALUE             (CapSense_dsFlash.wdgtArray[19].ptr2NoiseEnvlp)
#define CapSense_BUTTON19_PTR2NOISE_ENVLP_OFFSET            (636u)
#define CapSense_BUTTON19_PTR2NOISE_ENVLP_SIZE              (4u)
#define CapSense_BUTTON19_PTR2NOISE_ENVLP_PARAM_ID          (0xD413027Cu)

#define CapSense_BUTTON20_PTR2SNS_FLASH_VALUE               (CapSense_dsFlash.wdgtArray[20].ptr2SnsFlash)
#define CapSense_BUTTON20_PTR2SNS_FLASH_OFFSET              (640u)
#define CapSense_BUTTON20_PTR2SNS_FLASH_SIZE                (4u)
#define CapSense_BUTTON20_PTR2SNS_FLASH_PARAM_ID            (0xDF140280u)

#define CapSense_BUTTON20_PTR2WD_RAM_VALUE                  (CapSense_dsFlash.wdgtArray[20].ptr2WdgtRam)
#define CapSense_BUTTON20_PTR2WD_RAM_OFFSET                 (644u)
#define CapSense_BUTTON20_PTR2WD_RAM_SIZE                   (4u)
#define CapSense_BUTTON20_PTR2WD_RAM_PARAM_ID               (0xDE140284u)

#define CapSense_BUTTON20_PTR2SNS_RAM_VALUE                 (CapSense_dsFlash.wdgtArray[20].ptr2SnsRam)
#define CapSense_BUTTON20_PTR2SNS_RAM_OFFSET                (648u)
#define CapSense_BUTTON20_PTR2SNS_RAM_SIZE                  (4u)
#define CapSense_BUTTON20_PTR2SNS_RAM_PARAM_ID              (0xDD140288u)

#define CapSense_BUTTON20_PTR2FLTR_HISTORY_VALUE            (CapSense_dsFlash.wdgtArray[20].ptr2FltrHistory)
#define CapSense_BUTTON20_PTR2FLTR_HISTORY_OFFSET           (652u)
#define CapSense_BUTTON20_PTR2FLTR_HISTORY_SIZE             (4u)
#define CapSense_BUTTON20_PTR2FLTR_HISTORY_PARAM_ID         (0xDC14028Cu)

#define CapSense_BUTTON20_PTR2DEBOUNCE_VALUE                (CapSense_dsFlash.wdgtArray[20].ptr2DebounceArr)
#define CapSense_BUTTON20_PTR2DEBOUNCE_OFFSET               (656u)
#define CapSense_BUTTON20_PTR2DEBOUNCE_SIZE                 (4u)
#define CapSense_BUTTON20_PTR2DEBOUNCE_PARAM_ID             (0xDA140290u)

#define CapSense_BUTTON20_STATIC_CONFIG_VALUE               (CapSense_dsFlash.wdgtArray[20].staticConfig)
#define CapSense_BUTTON20_STATIC_CONFIG_OFFSET              (660u)
#define CapSense_BUTTON20_STATIC_CONFIG_SIZE                (2u)
#define CapSense_BUTTON20_STATIC_CONFIG_PARAM_ID            (0x94140294u)

#define CapSense_BUTTON20_TOTAL_NUM_SNS_VALUE               (CapSense_dsFlash.wdgtArray[20].totalNumSns)
#define CapSense_BUTTON20_TOTAL_NUM_SNS_OFFSET              (662u)
#define CapSense_BUTTON20_TOTAL_NUM_SNS_SIZE                (2u)
#define CapSense_BUTTON20_TOTAL_NUM_SNS_PARAM_ID            (0x98140296u)

#define CapSense_BUTTON20_TYPE_VALUE                        (CapSense_dsFlash.wdgtArray[20].wdgtType)
#define CapSense_BUTTON20_TYPE_OFFSET                       (664u)
#define CapSense_BUTTON20_TYPE_SIZE                         (1u)
#define CapSense_BUTTON20_TYPE_PARAM_ID                     (0x5F140298u)

#define CapSense_BUTTON20_NUM_COLS_VALUE                    (CapSense_dsFlash.wdgtArray[20].numCols)
#define CapSense_BUTTON20_NUM_COLS_OFFSET                   (665u)
#define CapSense_BUTTON20_NUM_COLS_SIZE                     (1u)
#define CapSense_BUTTON20_NUM_COLS_PARAM_ID                 (0x59140299u)

#define CapSense_BUTTON20_PTR2NOISE_ENVLP_VALUE             (CapSense_dsFlash.wdgtArray[20].ptr2NoiseEnvlp)
#define CapSense_BUTTON20_PTR2NOISE_ENVLP_OFFSET            (668u)
#define CapSense_BUTTON20_PTR2NOISE_ENVLP_SIZE              (4u)
#define CapSense_BUTTON20_PTR2NOISE_ENVLP_PARAM_ID          (0xD914029Cu)

#define CapSense_BUTTON21_PTR2SNS_FLASH_VALUE               (CapSense_dsFlash.wdgtArray[21].ptr2SnsFlash)
#define CapSense_BUTTON21_PTR2SNS_FLASH_OFFSET              (672u)
#define CapSense_BUTTON21_PTR2SNS_FLASH_SIZE                (4u)
#define CapSense_BUTTON21_PTR2SNS_FLASH_PARAM_ID            (0xD61502A0u)

#define CapSense_BUTTON21_PTR2WD_RAM_VALUE                  (CapSense_dsFlash.wdgtArray[21].ptr2WdgtRam)
#define CapSense_BUTTON21_PTR2WD_RAM_OFFSET                 (676u)
#define CapSense_BUTTON21_PTR2WD_RAM_SIZE                   (4u)
#define CapSense_BUTTON21_PTR2WD_RAM_PARAM_ID               (0xD71502A4u)

#define CapSense_BUTTON21_PTR2SNS_RAM_VALUE                 (CapSense_dsFlash.wdgtArray[21].ptr2SnsRam)
#define CapSense_BUTTON21_PTR2SNS_RAM_OFFSET                (680u)
#define CapSense_BUTTON21_PTR2SNS_RAM_SIZE                  (4u)
#define CapSense_BUTTON21_PTR2SNS_RAM_PARAM_ID              (0xD41502A8u)

#define CapSense_BUTTON21_PTR2FLTR_HISTORY_VALUE            (CapSense_dsFlash.wdgtArray[21].ptr2FltrHistory)
#define CapSense_BUTTON21_PTR2FLTR_HISTORY_OFFSET           (684u)
#define CapSense_BUTTON21_PTR2FLTR_HISTORY_SIZE             (4u)
#define CapSense_BUTTON21_PTR2FLTR_HISTORY_PARAM_ID         (0xD51502ACu)

#define CapSense_BUTTON21_PTR2DEBOUNCE_VALUE                (CapSense_dsFlash.wdgtArray[21].ptr2DebounceArr)
#define CapSense_BUTTON21_PTR2DEBOUNCE_OFFSET               (688u)
#define CapSense_BUTTON21_PTR2DEBOUNCE_SIZE                 (4u)
#define CapSense_BUTTON21_PTR2DEBOUNCE_PARAM_ID             (0xD31502B0u)

#define CapSense_BUTTON21_STATIC_CONFIG_VALUE               (CapSense_dsFlash.wdgtArray[21].staticConfig)
#define CapSense_BUTTON21_STATIC_CONFIG_OFFSET              (692u)
#define CapSense_BUTTON21_STATIC_CONFIG_SIZE                (2u)
#define CapSense_BUTTON21_STATIC_CONFIG_PARAM_ID            (0x9D1502B4u)

#define CapSense_BUTTON21_TOTAL_NUM_SNS_VALUE               (CapSense_dsFlash.wdgtArray[21].totalNumSns)
#define CapSense_BUTTON21_TOTAL_NUM_SNS_OFFSET              (694u)
#define CapSense_BUTTON21_TOTAL_NUM_SNS_SIZE                (2u)
#define CapSense_BUTTON21_TOTAL_NUM_SNS_PARAM_ID            (0x911502B6u)

#define CapSense_BUTTON21_TYPE_VALUE                        (CapSense_dsFlash.wdgtArray[21].wdgtType)
#define CapSense_BUTTON21_TYPE_OFFSET                       (696u)
#define CapSense_BUTTON21_TYPE_SIZE                         (1u)
#define CapSense_BUTTON21_TYPE_PARAM_ID                     (0x561502B8u)

#define CapSense_BUTTON21_NUM_COLS_VALUE                    (CapSense_dsFlash.wdgtArray[21].numCols)
#define CapSense_BUTTON21_NUM_COLS_OFFSET                   (697u)
#define CapSense_BUTTON21_NUM_COLS_SIZE                     (1u)
#define CapSense_BUTTON21_NUM_COLS_PARAM_ID                 (0x501502B9u)

#define CapSense_BUTTON21_PTR2NOISE_ENVLP_VALUE             (CapSense_dsFlash.wdgtArray[21].ptr2NoiseEnvlp)
#define CapSense_BUTTON21_PTR2NOISE_ENVLP_OFFSET            (700u)
#define CapSense_BUTTON21_PTR2NOISE_ENVLP_SIZE              (4u)
#define CapSense_BUTTON21_PTR2NOISE_ENVLP_PARAM_ID          (0xD01502BCu)

#define CapSense_BUTTON22_PTR2SNS_FLASH_VALUE               (CapSense_dsFlash.wdgtArray[22].ptr2SnsFlash)
#define CapSense_BUTTON22_PTR2SNS_FLASH_OFFSET              (704u)
#define CapSense_BUTTON22_PTR2SNS_FLASH_SIZE                (4u)
#define CapSense_BUTTON22_PTR2SNS_FLASH_PARAM_ID            (0xD41602C0u)

#define CapSense_BUTTON22_PTR2WD_RAM_VALUE                  (CapSense_dsFlash.wdgtArray[22].ptr2WdgtRam)
#define CapSense_BUTTON22_PTR2WD_RAM_OFFSET                 (708u)
#define CapSense_BUTTON22_PTR2WD_RAM_SIZE                   (4u)
#define CapSense_BUTTON22_PTR2WD_RAM_PARAM_ID               (0xD51602C4u)

#define CapSense_BUTTON22_PTR2SNS_RAM_VALUE                 (CapSense_dsFlash.wdgtArray[22].ptr2SnsRam)
#define CapSense_BUTTON22_PTR2SNS_RAM_OFFSET                (712u)
#define CapSense_BUTTON22_PTR2SNS_RAM_SIZE                  (4u)
#define CapSense_BUTTON22_PTR2SNS_RAM_PARAM_ID              (0xD61602C8u)

#define CapSense_BUTTON22_PTR2FLTR_HISTORY_VALUE            (CapSense_dsFlash.wdgtArray[22].ptr2FltrHistory)
#define CapSense_BUTTON22_PTR2FLTR_HISTORY_OFFSET           (716u)
#define CapSense_BUTTON22_PTR2FLTR_HISTORY_SIZE             (4u)
#define CapSense_BUTTON22_PTR2FLTR_HISTORY_PARAM_ID         (0xD71602CCu)

#define CapSense_BUTTON22_PTR2DEBOUNCE_VALUE                (CapSense_dsFlash.wdgtArray[22].ptr2DebounceArr)
#define CapSense_BUTTON22_PTR2DEBOUNCE_OFFSET               (720u)
#define CapSense_BUTTON22_PTR2DEBOUNCE_SIZE                 (4u)
#define CapSense_BUTTON22_PTR2DEBOUNCE_PARAM_ID             (0xD11602D0u)

#define CapSense_BUTTON22_STATIC_CONFIG_VALUE               (CapSense_dsFlash.wdgtArray[22].staticConfig)
#define CapSense_BUTTON22_STATIC_CONFIG_OFFSET              (724u)
#define CapSense_BUTTON22_STATIC_CONFIG_SIZE                (2u)
#define CapSense_BUTTON22_STATIC_CONFIG_PARAM_ID            (0x9F1602D4u)

#define CapSense_BUTTON22_TOTAL_NUM_SNS_VALUE               (CapSense_dsFlash.wdgtArray[22].totalNumSns)
#define CapSense_BUTTON22_TOTAL_NUM_SNS_OFFSET              (726u)
#define CapSense_BUTTON22_TOTAL_NUM_SNS_SIZE                (2u)
#define CapSense_BUTTON22_TOTAL_NUM_SNS_PARAM_ID            (0x931602D6u)

#define CapSense_BUTTON22_TYPE_VALUE                        (CapSense_dsFlash.wdgtArray[22].wdgtType)
#define CapSense_BUTTON22_TYPE_OFFSET                       (728u)
#define CapSense_BUTTON22_TYPE_SIZE                         (1u)
#define CapSense_BUTTON22_TYPE_PARAM_ID                     (0x541602D8u)

#define CapSense_BUTTON22_NUM_COLS_VALUE                    (CapSense_dsFlash.wdgtArray[22].numCols)
#define CapSense_BUTTON22_NUM_COLS_OFFSET                   (729u)
#define CapSense_BUTTON22_NUM_COLS_SIZE                     (1u)
#define CapSense_BUTTON22_NUM_COLS_PARAM_ID                 (0x521602D9u)

#define CapSense_BUTTON22_PTR2NOISE_ENVLP_VALUE             (CapSense_dsFlash.wdgtArray[22].ptr2NoiseEnvlp)
#define CapSense_BUTTON22_PTR2NOISE_ENVLP_OFFSET            (732u)
#define CapSense_BUTTON22_PTR2NOISE_ENVLP_SIZE              (4u)
#define CapSense_BUTTON22_PTR2NOISE_ENVLP_PARAM_ID          (0xD21602DCu)

#define CapSense_BUTTON23_PTR2SNS_FLASH_VALUE               (CapSense_dsFlash.wdgtArray[23].ptr2SnsFlash)
#define CapSense_BUTTON23_PTR2SNS_FLASH_OFFSET              (736u)
#define CapSense_BUTTON23_PTR2SNS_FLASH_SIZE                (4u)
#define CapSense_BUTTON23_PTR2SNS_FLASH_PARAM_ID            (0xDD1702E0u)

#define CapSense_BUTTON23_PTR2WD_RAM_VALUE                  (CapSense_dsFlash.wdgtArray[23].ptr2WdgtRam)
#define CapSense_BUTTON23_PTR2WD_RAM_OFFSET                 (740u)
#define CapSense_BUTTON23_PTR2WD_RAM_SIZE                   (4u)
#define CapSense_BUTTON23_PTR2WD_RAM_PARAM_ID               (0xDC1702E4u)

#define CapSense_BUTTON23_PTR2SNS_RAM_VALUE                 (CapSense_dsFlash.wdgtArray[23].ptr2SnsRam)
#define CapSense_BUTTON23_PTR2SNS_RAM_OFFSET                (744u)
#define CapSense_BUTTON23_PTR2SNS_RAM_SIZE                  (4u)
#define CapSense_BUTTON23_PTR2SNS_RAM_PARAM_ID              (0xDF1702E8u)

#define CapSense_BUTTON23_PTR2FLTR_HISTORY_VALUE            (CapSense_dsFlash.wdgtArray[23].ptr2FltrHistory)
#define CapSense_BUTTON23_PTR2FLTR_HISTORY_OFFSET           (748u)
#define CapSense_BUTTON23_PTR2FLTR_HISTORY_SIZE             (4u)
#define CapSense_BUTTON23_PTR2FLTR_HISTORY_PARAM_ID         (0xDE1702ECu)

#define CapSense_BUTTON23_PTR2DEBOUNCE_VALUE                (CapSense_dsFlash.wdgtArray[23].ptr2DebounceArr)
#define CapSense_BUTTON23_PTR2DEBOUNCE_OFFSET               (752u)
#define CapSense_BUTTON23_PTR2DEBOUNCE_SIZE                 (4u)
#define CapSense_BUTTON23_PTR2DEBOUNCE_PARAM_ID             (0xD81702F0u)

#define CapSense_BUTTON23_STATIC_CONFIG_VALUE               (CapSense_dsFlash.wdgtArray[23].staticConfig)
#define CapSense_BUTTON23_STATIC_CONFIG_OFFSET              (756u)
#define CapSense_BUTTON23_STATIC_CONFIG_SIZE                (2u)
#define CapSense_BUTTON23_STATIC_CONFIG_PARAM_ID            (0x961702F4u)

#define CapSense_BUTTON23_TOTAL_NUM_SNS_VALUE               (CapSense_dsFlash.wdgtArray[23].totalNumSns)
#define CapSense_BUTTON23_TOTAL_NUM_SNS_OFFSET              (758u)
#define CapSense_BUTTON23_TOTAL_NUM_SNS_SIZE                (2u)
#define CapSense_BUTTON23_TOTAL_NUM_SNS_PARAM_ID            (0x9A1702F6u)

#define CapSense_BUTTON23_TYPE_VALUE                        (CapSense_dsFlash.wdgtArray[23].wdgtType)
#define CapSense_BUTTON23_TYPE_OFFSET                       (760u)
#define CapSense_BUTTON23_TYPE_SIZE                         (1u)
#define CapSense_BUTTON23_TYPE_PARAM_ID                     (0x5D1702F8u)

#define CapSense_BUTTON23_NUM_COLS_VALUE                    (CapSense_dsFlash.wdgtArray[23].numCols)
#define CapSense_BUTTON23_NUM_COLS_OFFSET                   (761u)
#define CapSense_BUTTON23_NUM_COLS_SIZE                     (1u)
#define CapSense_BUTTON23_NUM_COLS_PARAM_ID                 (0x5B1702F9u)

#define CapSense_BUTTON23_PTR2NOISE_ENVLP_VALUE             (CapSense_dsFlash.wdgtArray[23].ptr2NoiseEnvlp)
#define CapSense_BUTTON23_PTR2NOISE_ENVLP_OFFSET            (764u)
#define CapSense_BUTTON23_PTR2NOISE_ENVLP_SIZE              (4u)
#define CapSense_BUTTON23_PTR2NOISE_ENVLP_PARAM_ID          (0xDB1702FCu)

#define CapSense_BUTTON24_PTR2SNS_FLASH_VALUE               (CapSense_dsFlash.wdgtArray[24].ptr2SnsFlash)
#define CapSense_BUTTON24_PTR2SNS_FLASH_OFFSET              (768u)
#define CapSense_BUTTON24_PTR2SNS_FLASH_SIZE                (4u)
#define CapSense_BUTTON24_PTR2SNS_FLASH_PARAM_ID            (0xDA180300u)

#define CapSense_BUTTON24_PTR2WD_RAM_VALUE                  (CapSense_dsFlash.wdgtArray[24].ptr2WdgtRam)
#define CapSense_BUTTON24_PTR2WD_RAM_OFFSET                 (772u)
#define CapSense_BUTTON24_PTR2WD_RAM_SIZE                   (4u)
#define CapSense_BUTTON24_PTR2WD_RAM_PARAM_ID               (0xDB180304u)

#define CapSense_BUTTON24_PTR2SNS_RAM_VALUE                 (CapSense_dsFlash.wdgtArray[24].ptr2SnsRam)
#define CapSense_BUTTON24_PTR2SNS_RAM_OFFSET                (776u)
#define CapSense_BUTTON24_PTR2SNS_RAM_SIZE                  (4u)
#define CapSense_BUTTON24_PTR2SNS_RAM_PARAM_ID              (0xD8180308u)

#define CapSense_BUTTON24_PTR2FLTR_HISTORY_VALUE            (CapSense_dsFlash.wdgtArray[24].ptr2FltrHistory)
#define CapSense_BUTTON24_PTR2FLTR_HISTORY_OFFSET           (780u)
#define CapSense_BUTTON24_PTR2FLTR_HISTORY_SIZE             (4u)
#define CapSense_BUTTON24_PTR2FLTR_HISTORY_PARAM_ID         (0xD918030Cu)

#define CapSense_BUTTON24_PTR2DEBOUNCE_VALUE                (CapSense_dsFlash.wdgtArray[24].ptr2DebounceArr)
#define CapSense_BUTTON24_PTR2DEBOUNCE_OFFSET               (784u)
#define CapSense_BUTTON24_PTR2DEBOUNCE_SIZE                 (4u)
#define CapSense_BUTTON24_PTR2DEBOUNCE_PARAM_ID             (0xDF180310u)

#define CapSense_BUTTON24_STATIC_CONFIG_VALUE               (CapSense_dsFlash.wdgtArray[24].staticConfig)
#define CapSense_BUTTON24_STATIC_CONFIG_OFFSET              (788u)
#define CapSense_BUTTON24_STATIC_CONFIG_SIZE                (2u)
#define CapSense_BUTTON24_STATIC_CONFIG_PARAM_ID            (0x91180314u)

#define CapSense_BUTTON24_TOTAL_NUM_SNS_VALUE               (CapSense_dsFlash.wdgtArray[24].totalNumSns)
#define CapSense_BUTTON24_TOTAL_NUM_SNS_OFFSET              (790u)
#define CapSense_BUTTON24_TOTAL_NUM_SNS_SIZE                (2u)
#define CapSense_BUTTON24_TOTAL_NUM_SNS_PARAM_ID            (0x9D180316u)

#define CapSense_BUTTON24_TYPE_VALUE                        (CapSense_dsFlash.wdgtArray[24].wdgtType)
#define CapSense_BUTTON24_TYPE_OFFSET                       (792u)
#define CapSense_BUTTON24_TYPE_SIZE                         (1u)
#define CapSense_BUTTON24_TYPE_PARAM_ID                     (0x5A180318u)

#define CapSense_BUTTON24_NUM_COLS_VALUE                    (CapSense_dsFlash.wdgtArray[24].numCols)
#define CapSense_BUTTON24_NUM_COLS_OFFSET                   (793u)
#define CapSense_BUTTON24_NUM_COLS_SIZE                     (1u)
#define CapSense_BUTTON24_NUM_COLS_PARAM_ID                 (0x5C180319u)

#define CapSense_BUTTON24_PTR2NOISE_ENVLP_VALUE             (CapSense_dsFlash.wdgtArray[24].ptr2NoiseEnvlp)
#define CapSense_BUTTON24_PTR2NOISE_ENVLP_OFFSET            (796u)
#define CapSense_BUTTON24_PTR2NOISE_ENVLP_SIZE              (4u)
#define CapSense_BUTTON24_PTR2NOISE_ENVLP_PARAM_ID          (0xDC18031Cu)

#define CapSense_BUTTON25_PTR2SNS_FLASH_VALUE               (CapSense_dsFlash.wdgtArray[25].ptr2SnsFlash)
#define CapSense_BUTTON25_PTR2SNS_FLASH_OFFSET              (800u)
#define CapSense_BUTTON25_PTR2SNS_FLASH_SIZE                (4u)
#define CapSense_BUTTON25_PTR2SNS_FLASH_PARAM_ID            (0xD3190320u)

#define CapSense_BUTTON25_PTR2WD_RAM_VALUE                  (CapSense_dsFlash.wdgtArray[25].ptr2WdgtRam)
#define CapSense_BUTTON25_PTR2WD_RAM_OFFSET                 (804u)
#define CapSense_BUTTON25_PTR2WD_RAM_SIZE                   (4u)
#define CapSense_BUTTON25_PTR2WD_RAM_PARAM_ID               (0xD2190324u)

#define CapSense_BUTTON25_PTR2SNS_RAM_VALUE                 (CapSense_dsFlash.wdgtArray[25].ptr2SnsRam)
#define CapSense_BUTTON25_PTR2SNS_RAM_OFFSET                (808u)
#define CapSense_BUTTON25_PTR2SNS_RAM_SIZE                  (4u)
#define CapSense_BUTTON25_PTR2SNS_RAM_PARAM_ID              (0xD1190328u)

#define CapSense_BUTTON25_PTR2FLTR_HISTORY_VALUE            (CapSense_dsFlash.wdgtArray[25].ptr2FltrHistory)
#define CapSense_BUTTON25_PTR2FLTR_HISTORY_OFFSET           (812u)
#define CapSense_BUTTON25_PTR2FLTR_HISTORY_SIZE             (4u)
#define CapSense_BUTTON25_PTR2FLTR_HISTORY_PARAM_ID         (0xD019032Cu)

#define CapSense_BUTTON25_PTR2DEBOUNCE_VALUE                (CapSense_dsFlash.wdgtArray[25].ptr2DebounceArr)
#define CapSense_BUTTON25_PTR2DEBOUNCE_OFFSET               (816u)
#define CapSense_BUTTON25_PTR2DEBOUNCE_SIZE                 (4u)
#define CapSense_BUTTON25_PTR2DEBOUNCE_PARAM_ID             (0xD6190330u)

#define CapSense_BUTTON25_STATIC_CONFIG_VALUE               (CapSense_dsFlash.wdgtArray[25].staticConfig)
#define CapSense_BUTTON25_STATIC_CONFIG_OFFSET              (820u)
#define CapSense_BUTTON25_STATIC_CONFIG_SIZE                (2u)
#define CapSense_BUTTON25_STATIC_CONFIG_PARAM_ID            (0x98190334u)

#define CapSense_BUTTON25_TOTAL_NUM_SNS_VALUE               (CapSense_dsFlash.wdgtArray[25].totalNumSns)
#define CapSense_BUTTON25_TOTAL_NUM_SNS_OFFSET              (822u)
#define CapSense_BUTTON25_TOTAL_NUM_SNS_SIZE                (2u)
#define CapSense_BUTTON25_TOTAL_NUM_SNS_PARAM_ID            (0x94190336u)

#define CapSense_BUTTON25_TYPE_VALUE                        (CapSense_dsFlash.wdgtArray[25].wdgtType)
#define CapSense_BUTTON25_TYPE_OFFSET                       (824u)
#define CapSense_BUTTON25_TYPE_SIZE                         (1u)
#define CapSense_BUTTON25_TYPE_PARAM_ID                     (0x53190338u)

#define CapSense_BUTTON25_NUM_COLS_VALUE                    (CapSense_dsFlash.wdgtArray[25].numCols)
#define CapSense_BUTTON25_NUM_COLS_OFFSET                   (825u)
#define CapSense_BUTTON25_NUM_COLS_SIZE                     (1u)
#define CapSense_BUTTON25_NUM_COLS_PARAM_ID                 (0x55190339u)

#define CapSense_BUTTON25_PTR2NOISE_ENVLP_VALUE             (CapSense_dsFlash.wdgtArray[25].ptr2NoiseEnvlp)
#define CapSense_BUTTON25_PTR2NOISE_ENVLP_OFFSET            (828u)
#define CapSense_BUTTON25_PTR2NOISE_ENVLP_SIZE              (4u)
#define CapSense_BUTTON25_PTR2NOISE_ENVLP_PARAM_ID          (0xD519033Cu)

#define CapSense_BUTTON26_PTR2SNS_FLASH_VALUE               (CapSense_dsFlash.wdgtArray[26].ptr2SnsFlash)
#define CapSense_BUTTON26_PTR2SNS_FLASH_OFFSET              (832u)
#define CapSense_BUTTON26_PTR2SNS_FLASH_SIZE                (4u)
#define CapSense_BUTTON26_PTR2SNS_FLASH_PARAM_ID            (0xD11A0340u)

#define CapSense_BUTTON26_PTR2WD_RAM_VALUE                  (CapSense_dsFlash.wdgtArray[26].ptr2WdgtRam)
#define CapSense_BUTTON26_PTR2WD_RAM_OFFSET                 (836u)
#define CapSense_BUTTON26_PTR2WD_RAM_SIZE                   (4u)
#define CapSense_BUTTON26_PTR2WD_RAM_PARAM_ID               (0xD01A0344u)

#define CapSense_BUTTON26_PTR2SNS_RAM_VALUE                 (CapSense_dsFlash.wdgtArray[26].ptr2SnsRam)
#define CapSense_BUTTON26_PTR2SNS_RAM_OFFSET                (840u)
#define CapSense_BUTTON26_PTR2SNS_RAM_SIZE                  (4u)
#define CapSense_BUTTON26_PTR2SNS_RAM_PARAM_ID              (0xD31A0348u)

#define CapSense_BUTTON26_PTR2FLTR_HISTORY_VALUE            (CapSense_dsFlash.wdgtArray[26].ptr2FltrHistory)
#define CapSense_BUTTON26_PTR2FLTR_HISTORY_OFFSET           (844u)
#define CapSense_BUTTON26_PTR2FLTR_HISTORY_SIZE             (4u)
#define CapSense_BUTTON26_PTR2FLTR_HISTORY_PARAM_ID         (0xD21A034Cu)

#define CapSense_BUTTON26_PTR2DEBOUNCE_VALUE                (CapSense_dsFlash.wdgtArray[26].ptr2DebounceArr)
#define CapSense_BUTTON26_PTR2DEBOUNCE_OFFSET               (848u)
#define CapSense_BUTTON26_PTR2DEBOUNCE_SIZE                 (4u)
#define CapSense_BUTTON26_PTR2DEBOUNCE_PARAM_ID             (0xD41A0350u)

#define CapSense_BUTTON26_STATIC_CONFIG_VALUE               (CapSense_dsFlash.wdgtArray[26].staticConfig)
#define CapSense_BUTTON26_STATIC_CONFIG_OFFSET              (852u)
#define CapSense_BUTTON26_STATIC_CONFIG_SIZE                (2u)
#define CapSense_BUTTON26_STATIC_CONFIG_PARAM_ID            (0x9A1A0354u)

#define CapSense_BUTTON26_TOTAL_NUM_SNS_VALUE               (CapSense_dsFlash.wdgtArray[26].totalNumSns)
#define CapSense_BUTTON26_TOTAL_NUM_SNS_OFFSET              (854u)
#define CapSense_BUTTON26_TOTAL_NUM_SNS_SIZE                (2u)
#define CapSense_BUTTON26_TOTAL_NUM_SNS_PARAM_ID            (0x961A0356u)

#define CapSense_BUTTON26_TYPE_VALUE                        (CapSense_dsFlash.wdgtArray[26].wdgtType)
#define CapSense_BUTTON26_TYPE_OFFSET                       (856u)
#define CapSense_BUTTON26_TYPE_SIZE                         (1u)
#define CapSense_BUTTON26_TYPE_PARAM_ID                     (0x511A0358u)

#define CapSense_BUTTON26_NUM_COLS_VALUE                    (CapSense_dsFlash.wdgtArray[26].numCols)
#define CapSense_BUTTON26_NUM_COLS_OFFSET                   (857u)
#define CapSense_BUTTON26_NUM_COLS_SIZE                     (1u)
#define CapSense_BUTTON26_NUM_COLS_PARAM_ID                 (0x571A0359u)

#define CapSense_BUTTON26_PTR2NOISE_ENVLP_VALUE             (CapSense_dsFlash.wdgtArray[26].ptr2NoiseEnvlp)
#define CapSense_BUTTON26_PTR2NOISE_ENVLP_OFFSET            (860u)
#define CapSense_BUTTON26_PTR2NOISE_ENVLP_SIZE              (4u)
#define CapSense_BUTTON26_PTR2NOISE_ENVLP_PARAM_ID          (0xD71A035Cu)

#define CapSense_BUTTON27_PTR2SNS_FLASH_VALUE               (CapSense_dsFlash.wdgtArray[27].ptr2SnsFlash)
#define CapSense_BUTTON27_PTR2SNS_FLASH_OFFSET              (864u)
#define CapSense_BUTTON27_PTR2SNS_FLASH_SIZE                (4u)
#define CapSense_BUTTON27_PTR2SNS_FLASH_PARAM_ID            (0xD81B0360u)

#define CapSense_BUTTON27_PTR2WD_RAM_VALUE                  (CapSense_dsFlash.wdgtArray[27].ptr2WdgtRam)
#define CapSense_BUTTON27_PTR2WD_RAM_OFFSET                 (868u)
#define CapSense_BUTTON27_PTR2WD_RAM_SIZE                   (4u)
#define CapSense_BUTTON27_PTR2WD_RAM_PARAM_ID               (0xD91B0364u)

#define CapSense_BUTTON27_PTR2SNS_RAM_VALUE                 (CapSense_dsFlash.wdgtArray[27].ptr2SnsRam)
#define CapSense_BUTTON27_PTR2SNS_RAM_OFFSET                (872u)
#define CapSense_BUTTON27_PTR2SNS_RAM_SIZE                  (4u)
#define CapSense_BUTTON27_PTR2SNS_RAM_PARAM_ID              (0xDA1B0368u)

#define CapSense_BUTTON27_PTR2FLTR_HISTORY_VALUE            (CapSense_dsFlash.wdgtArray[27].ptr2FltrHistory)
#define CapSense_BUTTON27_PTR2FLTR_HISTORY_OFFSET           (876u)
#define CapSense_BUTTON27_PTR2FLTR_HISTORY_SIZE             (4u)
#define CapSense_BUTTON27_PTR2FLTR_HISTORY_PARAM_ID         (0xDB1B036Cu)

#define CapSense_BUTTON27_PTR2DEBOUNCE_VALUE                (CapSense_dsFlash.wdgtArray[27].ptr2DebounceArr)
#define CapSense_BUTTON27_PTR2DEBOUNCE_OFFSET               (880u)
#define CapSense_BUTTON27_PTR2DEBOUNCE_SIZE                 (4u)
#define CapSense_BUTTON27_PTR2DEBOUNCE_PARAM_ID             (0xDD1B0370u)

#define CapSense_BUTTON27_STATIC_CONFIG_VALUE               (CapSense_dsFlash.wdgtArray[27].staticConfig)
#define CapSense_BUTTON27_STATIC_CONFIG_OFFSET              (884u)
#define CapSense_BUTTON27_STATIC_CONFIG_SIZE                (2u)
#define CapSense_BUTTON27_STATIC_CONFIG_PARAM_ID            (0x931B0374u)

#define CapSense_BUTTON27_TOTAL_NUM_SNS_VALUE               (CapSense_dsFlash.wdgtArray[27].totalNumSns)
#define CapSense_BUTTON27_TOTAL_NUM_SNS_OFFSET              (886u)
#define CapSense_BUTTON27_TOTAL_NUM_SNS_SIZE                (2u)
#define CapSense_BUTTON27_TOTAL_NUM_SNS_PARAM_ID            (0x9F1B0376u)

#define CapSense_BUTTON27_TYPE_VALUE                        (CapSense_dsFlash.wdgtArray[27].wdgtType)
#define CapSense_BUTTON27_TYPE_OFFSET                       (888u)
#define CapSense_BUTTON27_TYPE_SIZE                         (1u)
#define CapSense_BUTTON27_TYPE_PARAM_ID                     (0x581B0378u)

#define CapSense_BUTTON27_NUM_COLS_VALUE                    (CapSense_dsFlash.wdgtArray[27].numCols)
#define CapSense_BUTTON27_NUM_COLS_OFFSET                   (889u)
#define CapSense_BUTTON27_NUM_COLS_SIZE                     (1u)
#define CapSense_BUTTON27_NUM_COLS_PARAM_ID                 (0x5E1B0379u)

#define CapSense_BUTTON27_PTR2NOISE_ENVLP_VALUE             (CapSense_dsFlash.wdgtArray[27].ptr2NoiseEnvlp)
#define CapSense_BUTTON27_PTR2NOISE_ENVLP_OFFSET            (892u)
#define CapSense_BUTTON27_PTR2NOISE_ENVLP_SIZE              (4u)
#define CapSense_BUTTON27_PTR2NOISE_ENVLP_PARAM_ID          (0xDE1B037Cu)

#define CapSense_BUTTON28_PTR2SNS_FLASH_VALUE               (CapSense_dsFlash.wdgtArray[28].ptr2SnsFlash)
#define CapSense_BUTTON28_PTR2SNS_FLASH_OFFSET              (896u)
#define CapSense_BUTTON28_PTR2SNS_FLASH_SIZE                (4u)
#define CapSense_BUTTON28_PTR2SNS_FLASH_PARAM_ID            (0xD51C0380u)

#define CapSense_BUTTON28_PTR2WD_RAM_VALUE                  (CapSense_dsFlash.wdgtArray[28].ptr2WdgtRam)
#define CapSense_BUTTON28_PTR2WD_RAM_OFFSET                 (900u)
#define CapSense_BUTTON28_PTR2WD_RAM_SIZE                   (4u)
#define CapSense_BUTTON28_PTR2WD_RAM_PARAM_ID               (0xD41C0384u)

#define CapSense_BUTTON28_PTR2SNS_RAM_VALUE                 (CapSense_dsFlash.wdgtArray[28].ptr2SnsRam)
#define CapSense_BUTTON28_PTR2SNS_RAM_OFFSET                (904u)
#define CapSense_BUTTON28_PTR2SNS_RAM_SIZE                  (4u)
#define CapSense_BUTTON28_PTR2SNS_RAM_PARAM_ID              (0xD71C0388u)

#define CapSense_BUTTON28_PTR2FLTR_HISTORY_VALUE            (CapSense_dsFlash.wdgtArray[28].ptr2FltrHistory)
#define CapSense_BUTTON28_PTR2FLTR_HISTORY_OFFSET           (908u)
#define CapSense_BUTTON28_PTR2FLTR_HISTORY_SIZE             (4u)
#define CapSense_BUTTON28_PTR2FLTR_HISTORY_PARAM_ID         (0xD61C038Cu)

#define CapSense_BUTTON28_PTR2DEBOUNCE_VALUE                (CapSense_dsFlash.wdgtArray[28].ptr2DebounceArr)
#define CapSense_BUTTON28_PTR2DEBOUNCE_OFFSET               (912u)
#define CapSense_BUTTON28_PTR2DEBOUNCE_SIZE                 (4u)
#define CapSense_BUTTON28_PTR2DEBOUNCE_PARAM_ID             (0xD01C0390u)

#define CapSense_BUTTON28_STATIC_CONFIG_VALUE               (CapSense_dsFlash.wdgtArray[28].staticConfig)
#define CapSense_BUTTON28_STATIC_CONFIG_OFFSET              (916u)
#define CapSense_BUTTON28_STATIC_CONFIG_SIZE                (2u)
#define CapSense_BUTTON28_STATIC_CONFIG_PARAM_ID            (0x9E1C0394u)

#define CapSense_BUTTON28_TOTAL_NUM_SNS_VALUE               (CapSense_dsFlash.wdgtArray[28].totalNumSns)
#define CapSense_BUTTON28_TOTAL_NUM_SNS_OFFSET              (918u)
#define CapSense_BUTTON28_TOTAL_NUM_SNS_SIZE                (2u)
#define CapSense_BUTTON28_TOTAL_NUM_SNS_PARAM_ID            (0x921C0396u)

#define CapSense_BUTTON28_TYPE_VALUE                        (CapSense_dsFlash.wdgtArray[28].wdgtType)
#define CapSense_BUTTON28_TYPE_OFFSET                       (920u)
#define CapSense_BUTTON28_TYPE_SIZE                         (1u)
#define CapSense_BUTTON28_TYPE_PARAM_ID                     (0x551C0398u)

#define CapSense_BUTTON28_NUM_COLS_VALUE                    (CapSense_dsFlash.wdgtArray[28].numCols)
#define CapSense_BUTTON28_NUM_COLS_OFFSET                   (921u)
#define CapSense_BUTTON28_NUM_COLS_SIZE                     (1u)
#define CapSense_BUTTON28_NUM_COLS_PARAM_ID                 (0x531C0399u)

#define CapSense_BUTTON28_PTR2NOISE_ENVLP_VALUE             (CapSense_dsFlash.wdgtArray[28].ptr2NoiseEnvlp)
#define CapSense_BUTTON28_PTR2NOISE_ENVLP_OFFSET            (924u)
#define CapSense_BUTTON28_PTR2NOISE_ENVLP_SIZE              (4u)
#define CapSense_BUTTON28_PTR2NOISE_ENVLP_PARAM_ID          (0xD31C039Cu)

#define CapSense_BUTTON29_PTR2SNS_FLASH_VALUE               (CapSense_dsFlash.wdgtArray[29].ptr2SnsFlash)
#define CapSense_BUTTON29_PTR2SNS_FLASH_OFFSET              (928u)
#define CapSense_BUTTON29_PTR2SNS_FLASH_SIZE                (4u)
#define CapSense_BUTTON29_PTR2SNS_FLASH_PARAM_ID            (0xDC1D03A0u)

#define CapSense_BUTTON29_PTR2WD_RAM_VALUE                  (CapSense_dsFlash.wdgtArray[29].ptr2WdgtRam)
#define CapSense_BUTTON29_PTR2WD_RAM_OFFSET                 (932u)
#define CapSense_BUTTON29_PTR2WD_RAM_SIZE                   (4u)
#define CapSense_BUTTON29_PTR2WD_RAM_PARAM_ID               (0xDD1D03A4u)

#define CapSense_BUTTON29_PTR2SNS_RAM_VALUE                 (CapSense_dsFlash.wdgtArray[29].ptr2SnsRam)
#define CapSense_BUTTON29_PTR2SNS_RAM_OFFSET                (936u)
#define CapSense_BUTTON29_PTR2SNS_RAM_SIZE                  (4u)
#define CapSense_BUTTON29_PTR2SNS_RAM_PARAM_ID              (0xDE1D03A8u)

#define CapSense_BUTTON29_PTR2FLTR_HISTORY_VALUE            (CapSense_dsFlash.wdgtArray[29].ptr2FltrHistory)
#define CapSense_BUTTON29_PTR2FLTR_HISTORY_OFFSET           (940u)
#define CapSense_BUTTON29_PTR2FLTR_HISTORY_SIZE             (4u)
#define CapSense_BUTTON29_PTR2FLTR_HISTORY_PARAM_ID         (0xDF1D03ACu)

#define CapSense_BUTTON29_PTR2DEBOUNCE_VALUE                (CapSense_dsFlash.wdgtArray[29].ptr2DebounceArr)
#define CapSense_BUTTON29_PTR2DEBOUNCE_OFFSET               (944u)
#define CapSense_BUTTON29_PTR2DEBOUNCE_SIZE                 (4u)
#define CapSense_BUTTON29_PTR2DEBOUNCE_PARAM_ID             (0xD91D03B0u)

#define CapSense_BUTTON29_STATIC_CONFIG_VALUE               (CapSense_dsFlash.wdgtArray[29].staticConfig)
#define CapSense_BUTTON29_STATIC_CONFIG_OFFSET              (948u)
#define CapSense_BUTTON29_STATIC_CONFIG_SIZE                (2u)
#define CapSense_BUTTON29_STATIC_CONFIG_PARAM_ID            (0x971D03B4u)

#define CapSense_BUTTON29_TOTAL_NUM_SNS_VALUE               (CapSense_dsFlash.wdgtArray[29].totalNumSns)
#define CapSense_BUTTON29_TOTAL_NUM_SNS_OFFSET              (950u)
#define CapSense_BUTTON29_TOTAL_NUM_SNS_SIZE                (2u)
#define CapSense_BUTTON29_TOTAL_NUM_SNS_PARAM_ID            (0x9B1D03B6u)

#define CapSense_BUTTON29_TYPE_VALUE                        (CapSense_dsFlash.wdgtArray[29].wdgtType)
#define CapSense_BUTTON29_TYPE_OFFSET                       (952u)
#define CapSense_BUTTON29_TYPE_SIZE                         (1u)
#define CapSense_BUTTON29_TYPE_PARAM_ID                     (0x5C1D03B8u)

#define CapSense_BUTTON29_NUM_COLS_VALUE                    (CapSense_dsFlash.wdgtArray[29].numCols)
#define CapSense_BUTTON29_NUM_COLS_OFFSET                   (953u)
#define CapSense_BUTTON29_NUM_COLS_SIZE                     (1u)
#define CapSense_BUTTON29_NUM_COLS_PARAM_ID                 (0x5A1D03B9u)

#define CapSense_BUTTON29_PTR2NOISE_ENVLP_VALUE             (CapSense_dsFlash.wdgtArray[29].ptr2NoiseEnvlp)
#define CapSense_BUTTON29_PTR2NOISE_ENVLP_OFFSET            (956u)
#define CapSense_BUTTON29_PTR2NOISE_ENVLP_SIZE              (4u)
#define CapSense_BUTTON29_PTR2NOISE_ENVLP_PARAM_ID          (0xDA1D03BCu)

#define CapSense_BUTTON30_PTR2SNS_FLASH_VALUE               (CapSense_dsFlash.wdgtArray[30].ptr2SnsFlash)
#define CapSense_BUTTON30_PTR2SNS_FLASH_OFFSET              (960u)
#define CapSense_BUTTON30_PTR2SNS_FLASH_SIZE                (4u)
#define CapSense_BUTTON30_PTR2SNS_FLASH_PARAM_ID            (0xDE1E03C0u)

#define CapSense_BUTTON30_PTR2WD_RAM_VALUE                  (CapSense_dsFlash.wdgtArray[30].ptr2WdgtRam)
#define CapSense_BUTTON30_PTR2WD_RAM_OFFSET                 (964u)
#define CapSense_BUTTON30_PTR2WD_RAM_SIZE                   (4u)
#define CapSense_BUTTON30_PTR2WD_RAM_PARAM_ID               (0xDF1E03C4u)

#define CapSense_BUTTON30_PTR2SNS_RAM_VALUE                 (CapSense_dsFlash.wdgtArray[30].ptr2SnsRam)
#define CapSense_BUTTON30_PTR2SNS_RAM_OFFSET                (968u)
#define CapSense_BUTTON30_PTR2SNS_RAM_SIZE                  (4u)
#define CapSense_BUTTON30_PTR2SNS_RAM_PARAM_ID              (0xDC1E03C8u)

#define CapSense_BUTTON30_PTR2FLTR_HISTORY_VALUE            (CapSense_dsFlash.wdgtArray[30].ptr2FltrHistory)
#define CapSense_BUTTON30_PTR2FLTR_HISTORY_OFFSET           (972u)
#define CapSense_BUTTON30_PTR2FLTR_HISTORY_SIZE             (4u)
#define CapSense_BUTTON30_PTR2FLTR_HISTORY_PARAM_ID         (0xDD1E03CCu)

#define CapSense_BUTTON30_PTR2DEBOUNCE_VALUE                (CapSense_dsFlash.wdgtArray[30].ptr2DebounceArr)
#define CapSense_BUTTON30_PTR2DEBOUNCE_OFFSET               (976u)
#define CapSense_BUTTON30_PTR2DEBOUNCE_SIZE                 (4u)
#define CapSense_BUTTON30_PTR2DEBOUNCE_PARAM_ID             (0xDB1E03D0u)

#define CapSense_BUTTON30_STATIC_CONFIG_VALUE               (CapSense_dsFlash.wdgtArray[30].staticConfig)
#define CapSense_BUTTON30_STATIC_CONFIG_OFFSET              (980u)
#define CapSense_BUTTON30_STATIC_CONFIG_SIZE                (2u)
#define CapSense_BUTTON30_STATIC_CONFIG_PARAM_ID            (0x951E03D4u)

#define CapSense_BUTTON30_TOTAL_NUM_SNS_VALUE               (CapSense_dsFlash.wdgtArray[30].totalNumSns)
#define CapSense_BUTTON30_TOTAL_NUM_SNS_OFFSET              (982u)
#define CapSense_BUTTON30_TOTAL_NUM_SNS_SIZE                (2u)
#define CapSense_BUTTON30_TOTAL_NUM_SNS_PARAM_ID            (0x991E03D6u)

#define CapSense_BUTTON30_TYPE_VALUE                        (CapSense_dsFlash.wdgtArray[30].wdgtType)
#define CapSense_BUTTON30_TYPE_OFFSET                       (984u)
#define CapSense_BUTTON30_TYPE_SIZE                         (1u)
#define CapSense_BUTTON30_TYPE_PARAM_ID                     (0x5E1E03D8u)

#define CapSense_BUTTON30_NUM_COLS_VALUE                    (CapSense_dsFlash.wdgtArray[30].numCols)
#define CapSense_BUTTON30_NUM_COLS_OFFSET                   (985u)
#define CapSense_BUTTON30_NUM_COLS_SIZE                     (1u)
#define CapSense_BUTTON30_NUM_COLS_PARAM_ID                 (0x581E03D9u)

#define CapSense_BUTTON30_PTR2NOISE_ENVLP_VALUE             (CapSense_dsFlash.wdgtArray[30].ptr2NoiseEnvlp)
#define CapSense_BUTTON30_PTR2NOISE_ENVLP_OFFSET            (988u)
#define CapSense_BUTTON30_PTR2NOISE_ENVLP_SIZE              (4u)
#define CapSense_BUTTON30_PTR2NOISE_ENVLP_PARAM_ID          (0xD81E03DCu)

#define CapSense_BUTTON31_PTR2SNS_FLASH_VALUE               (CapSense_dsFlash.wdgtArray[31].ptr2SnsFlash)
#define CapSense_BUTTON31_PTR2SNS_FLASH_OFFSET              (992u)
#define CapSense_BUTTON31_PTR2SNS_FLASH_SIZE                (4u)
#define CapSense_BUTTON31_PTR2SNS_FLASH_PARAM_ID            (0xD71F03E0u)

#define CapSense_BUTTON31_PTR2WD_RAM_VALUE                  (CapSense_dsFlash.wdgtArray[31].ptr2WdgtRam)
#define CapSense_BUTTON31_PTR2WD_RAM_OFFSET                 (996u)
#define CapSense_BUTTON31_PTR2WD_RAM_SIZE                   (4u)
#define CapSense_BUTTON31_PTR2WD_RAM_PARAM_ID               (0xD61F03E4u)

#define CapSense_BUTTON31_PTR2SNS_RAM_VALUE                 (CapSense_dsFlash.wdgtArray[31].ptr2SnsRam)
#define CapSense_BUTTON31_PTR2SNS_RAM_OFFSET                (1000u)
#define CapSense_BUTTON31_PTR2SNS_RAM_SIZE                  (4u)
#define CapSense_BUTTON31_PTR2SNS_RAM_PARAM_ID              (0xD51F03E8u)

#define CapSense_BUTTON31_PTR2FLTR_HISTORY_VALUE            (CapSense_dsFlash.wdgtArray[31].ptr2FltrHistory)
#define CapSense_BUTTON31_PTR2FLTR_HISTORY_OFFSET           (1004u)
#define CapSense_BUTTON31_PTR2FLTR_HISTORY_SIZE             (4u)
#define CapSense_BUTTON31_PTR2FLTR_HISTORY_PARAM_ID         (0xD41F03ECu)

#define CapSense_BUTTON31_PTR2DEBOUNCE_VALUE                (CapSense_dsFlash.wdgtArray[31].ptr2DebounceArr)
#define CapSense_BUTTON31_PTR2DEBOUNCE_OFFSET               (1008u)
#define CapSense_BUTTON31_PTR2DEBOUNCE_SIZE                 (4u)
#define CapSense_BUTTON31_PTR2DEBOUNCE_PARAM_ID             (0xD21F03F0u)

#define CapSense_BUTTON31_STATIC_CONFIG_VALUE               (CapSense_dsFlash.wdgtArray[31].staticConfig)
#define CapSense_BUTTON31_STATIC_CONFIG_OFFSET              (1012u)
#define CapSense_BUTTON31_STATIC_CONFIG_SIZE                (2u)
#define CapSense_BUTTON31_STATIC_CONFIG_PARAM_ID            (0x9C1F03F4u)

#define CapSense_BUTTON31_TOTAL_NUM_SNS_VALUE               (CapSense_dsFlash.wdgtArray[31].totalNumSns)
#define CapSense_BUTTON31_TOTAL_NUM_SNS_OFFSET              (1014u)
#define CapSense_BUTTON31_TOTAL_NUM_SNS_SIZE                (2u)
#define CapSense_BUTTON31_TOTAL_NUM_SNS_PARAM_ID            (0x901F03F6u)

#define CapSense_BUTTON31_TYPE_VALUE                        (CapSense_dsFlash.wdgtArray[31].wdgtType)
#define CapSense_BUTTON31_TYPE_OFFSET                       (1016u)
#define CapSense_BUTTON31_TYPE_SIZE                         (1u)
#define CapSense_BUTTON31_TYPE_PARAM_ID                     (0x571F03F8u)

#define CapSense_BUTTON31_NUM_COLS_VALUE                    (CapSense_dsFlash.wdgtArray[31].numCols)
#define CapSense_BUTTON31_NUM_COLS_OFFSET                   (1017u)
#define CapSense_BUTTON31_NUM_COLS_SIZE                     (1u)
#define CapSense_BUTTON31_NUM_COLS_PARAM_ID                 (0x511F03F9u)

#define CapSense_BUTTON31_PTR2NOISE_ENVLP_VALUE             (CapSense_dsFlash.wdgtArray[31].ptr2NoiseEnvlp)
#define CapSense_BUTTON31_PTR2NOISE_ENVLP_OFFSET            (1020u)
#define CapSense_BUTTON31_PTR2NOISE_ENVLP_SIZE              (4u)
#define CapSense_BUTTON31_PTR2NOISE_ENVLP_PARAM_ID          (0xD11F03FCu)


#endif /* End CY_CAPSENSE_CapSense_REGISTER_MAP_H */

/* [] END OF FILE */
