/***************************************************************************//**
* \file CapSense_1_SensingCSD_LL.h
* \version 3.10
*
* \brief
*   This file provides the headers of APIs specific to CSD sensing implementation.
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

#if !defined(CY_CAPSENSE_CapSense_1_SENSINGCSD_LL_H)
#define CY_CAPSENSE_CapSense_1_SENSINGCSD_LL_H

#include <CyLib.h>
#include <cyfitter.h>
#include "cytypes.h"
#include "CapSense_1_Structure.h"
#include "CapSense_1_Configuration.h"

/***************************************
* Function Prototypes
**************************************/

/**
* \if SECTION_CAPSENSE_LOW_LEVEL
* \addtogroup group_capsense_low_level
* \{
*/

void CapSense_1_CSDSetupWidget(uint32 wdgtIndex);
void CapSense_1_CSDSetupWidgetExt(uint32 wdgtIndex, uint32 snsIndex);
void CapSense_1_CSDScan(void);
void CapSense_1_CSDScanExt(void);
#if ((CapSense_1_CSD_SS_DIS != CapSense_1_CSD_AUTOTUNE) || \
     (CapSense_1_ENABLE == CapSense_1_CSD_IDAC_AUTOCAL_EN))
    cystatus CapSense_1_CSDCalibrateWidget(uint32 wdgtIndex, uint32 target);
#endif /* ((CapSense_1_CSD_SS_DIS != CapSense_1_CSD_AUTOTUNE) || \
           (CapSense_1_ENABLE == CapSense_1_CSD_IDAC_AUTOCAL_EN))  */
void CapSense_1_CSDConnectSns(CapSense_1_FLASH_IO_STRUCT const *snsAddrPtr);
void CapSense_1_CSDDisconnectSns(CapSense_1_FLASH_IO_STRUCT const *snsAddrPtr);

/** \}
* \endif */

/*****************************************************
* Function Prototypes - internal Low Level functions
*****************************************************/
/**
* \if SECTION_CAPSENSE_INTERNAL
* \addtogroup group_capsense_internal
* \{
*/

void CapSense_1_SsCSDInitialize(void);
void CapSense_1_SsCSDStartSample(void);
void CapSense_1_SsCSDSetUpIdacs(CapSense_1_RAM_WD_BASE_STRUCT const *ptrWdgt);
void CapSense_1_SsCSDConfigClock(void);
void CapSense_1_SsCSDElectrodeCheck(void);
#if ((CapSense_1_ENABLE == CapSense_1_CSD_SHIELD_EN) && \
     (0u != CapSense_1_CSD_TOTAL_SHIELD_COUNT))
    void CapSense_1_SsCSDDisableShieldElectrodes(void);
#endif /* ((CapSense_1_ENABLE == CapSense_1_CSD_SHIELD_EN) && \
           (0u != CapSense_1_CSD_TOTAL_SHIELD_COUNT)) */
#if (CapSense_1_ENABLE == CapSense_1_CSDV2)
    uint32 CapSense_1_SsCSDGetNumberOfConversions(uint32 snsClkDivider, uint32 resolution, uint32 snsClkSrc);
#endif /* (CapSense_1_ENABLE == CapSense_1_CSDV2) */
void CapSense_1_SsCSDCalculateScanDuration(CapSense_1_RAM_WD_BASE_STRUCT const *ptrWdgt);
void CapSense_1_SsCSDConnectSensorExt(uint32 wdgtIndex, uint32 sensorIndex);
void CapSense_1_SsCSDDisconnectSnsExt(uint32 wdgtIndex, uint32 sensorIndex);
void CapSense_1_SsCSDSetModeSnsClockDivider(uint32 snsClkSource, uint32 snsClkDivider);

#if ((CapSense_1_CSD_SS_DIS != CapSense_1_CSD_AUTOTUNE) || \
     (CapSense_1_ENABLE == CapSense_1_SELF_TEST_EN) || \
     (CapSense_1_ENABLE == CapSense_1_CSD_IDAC_AUTOCAL_EN))
    #if (CapSense_1_ENABLE == CapSense_1_CSD_IDAC_COMP_EN)
        void CapSense_1_SsCSDSetSingleIdacMode(void);
    #endif /* (CapSense_1_ENABLE == CapSense_1_CSD_IDAC_COMP_EN) */
#endif /* ((CapSense_1_CSD_SS_DIS != CapSense_1_CSD_AUTOTUNE) || \
           (CapSense_1_ENABLE == CapSense_1_SELF_TEST_EN) || \
           (CapSense_1_ENABLE == CapSense_1_CSD_IDAC_AUTOCAL_EN)) */

/** \}
* \endif */

/***************************************
* Global software variables
***************************************/
extern uint32 CapSense_1_configCsd;
/* Interrupt handler */
extern CY_ISR_PROTO(CapSense_1_CSDPostSingleScan);
extern CY_ISR_PROTO(CapSense_1_CSDPostMultiScan);
#if (CapSense_1_ENABLE == CapSense_1_CSD_GANGED_SNS_EN)
extern CY_ISR_PROTO(CapSense_1_CSDPostMultiScanGanged);
#endif /* (CapSense_1_ENABLE == CapSense_1_CSD_GANGED_SNS_EN) */
#if (CapSense_1_ENABLE == CapSense_1_CSD_NOISE_METRIC_EN)
    extern uint8 CapSense_1_badConversionsNum;
#endif /* (CapSense_1_ENABLE == CapSense_1_CSD_NOISE_METRIC_EN) */

#endif /* End CY_CAPSENSE_CapSense_1_SENSINGCSD_LL_H */


/* [] END OF FILE */
