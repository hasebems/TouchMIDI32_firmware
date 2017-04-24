/***************************************************************************//**
* \file CapSense_1_Processing.h
* \version 3.10
*
* \brief
* This file provides the function prototypes for the Data Processing module.
* The Data Processing module is responsible for the low level raw counts
* processing provided by the sensing module, maintaining baseline and 
* difference values and performing high-level widget processing like updating
* button status or calculating slider position.
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

#if !defined(CY_CAPSENSE_CapSense_1_DATA_PROCESS_H)
#define CY_CAPSENSE_CapSense_1_DATA_PROCESS_H

#include "CapSense_1_Configuration.h"
#include "CapSense_1_Structure.h"

#if (0 != (CapSense_1_CSD_AUTOTUNE & CapSense_1_CSD_SS_TH_EN))
    #include "CapSense_1_SmartSense_LL.h"
#endif /* (0 != (CapSense_1_CSD_AUTOTUNE & CapSense_1_CSD_SS_TH_EN)) */
    
/*******************************************************************************
* Definitions
*******************************************************************************/
    
/* Define the data processing tasks */
   
/* Applies all enabled filters in the default order to the raw counts */
#define CapSense_1_PROCESS_FILTER             (0x01Lu)
    
/* Updates baselines using current raw count values for the widget/sensor */
#define CapSense_1_PROCESS_BASELINE           (0x02Lu)
    
/* Calculates differences for the widget/sensor */
#define CapSense_1_PROCESS_DIFFCOUNTS         (0x04Lu)
    
/* Runs the noise envelope filter to measure noise magnitude for the widget/sensor */
#define CapSense_1_PROCESS_CALC_NOISE         (0x08Lu)
    
/* Updates widget thresholds based on raw counts noise magnitude */
#define CapSense_1_PROCESS_THRESHOLDS         (0x10Lu)
    
/* Runs the widget-specific processing algorithms and updates it status */
#define CapSense_1_PROCESS_STATUS             (0x20Lu)
    
/* Runs the deconvolution algorithm for the widgets with the multiphase TX scanning */
#define CapSense_1_PROCESS_DECONVOLUTION      (0x40Lu)
    
/* Definition that combines all possible processing tasks */
#define CapSense_1_PROCESS_ALL    (CapSense_1_PROCESS_FILTER        | \
                                         CapSense_1_PROCESS_BASELINE      | \
                                         CapSense_1_PROCESS_DIFFCOUNTS    | \
                                         CapSense_1_PROCESS_CALC_NOISE    | \
                                         CapSense_1_PROCESS_THRESHOLDS    | \
                                         CapSense_1_PROCESS_DECONVOLUTION | \
                                         CapSense_1_PROCESS_STATUS )
        
/*******************************************************************************
* Function Prototypes 
*******************************************************************************/

/*******************************************************************************
* Function Prototypes - internal functions.
*******************************************************************************/
/**
* \if SECTION_CAPSENSE_INTERNAL
* \addtogroup group_capsense_internal
* \{
*/

void CapSense_1_DpInitialize(void);

#if ((0u != CapSense_1_BUTTON_WIDGET_EN) || (0u != CapSense_1_CSX_MATRIX_WIDGET_EN))
    uint32 CapSense_1_DpProcessButton(uint32 currStatus, CapSense_1_FLASH_WD_STRUCT const *ptrFlashWdgt);
#endif /* #if ((0u != CapSense_1_BUTTON_WIDGET_EN) || (0u != CapSense_1_CSX_MATRIX_WIDGET_EN)) */

#if (0u != CapSense_1_CSX_TOUCHPAD_WIDGET_EN)
    uint32 CapSense_1_DpProcessCsxTouchpad(
                uint32 currStatus, CapSense_1_FLASH_WD_STRUCT const *ptrFlashWdgt);
#endif /* #if (0u != CapSense_1_CSX_TOUCHPAD_WIDGET_EN) */

#if (0u != CapSense_1_PROXIMITY_WIDGET_EN)
    uint32 CapSense_1_DpProcessProximity(uint32 currStatus, CapSense_1_FLASH_WD_STRUCT const *ptrFlashWdgt);
#endif /* #if (0u != CapSense_1_PROXIMITY_WIDGET_EN) */

#if (0u != CapSense_1_SLIDER_WIDGET_EN)
    uint32 CapSense_1_DpProcessSlider(uint32 currStatus, CapSense_1_FLASH_WD_STRUCT const *ptrFlashWdgt);
#endif /* #if (0u != CapSense_1_SLIDER_WIDGET_EN) */

#if (0u != CapSense_1_CSD_MATRIX_WIDGET_EN)
    uint32 CapSense_1_DpProcessCsdMatrix(uint32 currStatus, CapSense_1_FLASH_WD_STRUCT const *ptrFlashWdgt);
#endif /* #if (0u != CapSense_1_CSD_MATRIX_WIDGET_EN) */

#if (0u != CapSense_1_CSD_TOUCHPAD_WIDGET_EN)
    uint32 CapSense_1_DpProcessCsdTouchpad(
                uint32 currStatus, CapSense_1_FLASH_WD_STRUCT const *ptrFlashWdgt);
#endif /* #if (0u != CapSense_1_CSD_TOUCHPAD_WIDGET_EN) */

#if (0u != CapSense_1_TOTAL_CSD_WIDGETS)
    uint32 CapSense_1_DpProcessCsdWidgetRawCounts(
                    CapSense_1_FLASH_WD_STRUCT const *ptrFlashWdgt);
    
    uint32 CapSense_1_DpProcessCsdSensorRawCountsExt(
                    CapSense_1_FLASH_WD_STRUCT const *ptrFlashWdgt, 
                    CapSense_1_RAM_SNS_STRUCT *ptrSns,
                    CapSense_1_PTR_FILTER_VARIANT fltrHistV, 
                     uint32 mode);
    
    void CapSense_1_DpProcessCsdWidgetStatus(uint32 wdgtId, CapSense_1_FLASH_WD_STRUCT const *ptrFlashWdgt);
#endif /* #if (0u != CapSense_1_TOTAL_CSD_WIDGETS) */

#if (0u != CapSense_1_TOTAL_CSX_WIDGETS)
    uint32 CapSense_1_DpProcessCsxWidgetRawCounts(
            CapSense_1_FLASH_WD_STRUCT const *ptrFlashWdgt);

    uint32 CapSense_1_DpProcessCsxSensorRawCountsExt(
                    CapSense_1_FLASH_WD_STRUCT const *ptrFlashWdgt, 
                    CapSense_1_RAM_SNS_STRUCT *ptrSns,
                    CapSense_1_PTR_FILTER_VARIANT fltrHistV, 
                     uint32 mode);
    
    void CapSense_1_DpProcessCsxWidgetStatus(
                uint32 wdgtId, CapSense_1_FLASH_WD_STRUCT const *ptrFlashWdgt);
#endif /* #if (0u != CapSense_1_TOTAL_CSX_WIDGETS) */

void CapSense_1_DpUpdateDifferences(
        CapSense_1_RAM_WD_BASE_STRUCT  *ptrRamWdgt, CapSense_1_RAM_SNS_STRUCT *ptrSns);

#if (0u != (CapSense_1_CSD_AUTOTUNE & CapSense_1_CSD_SS_TH_EN))
    void CapSense_1_DpUpdateThresholds(
                    CapSense_1_RAM_WD_BASE_STRUCT *ptrRamWdgt,
                    SMARTSENSE_CSD_NOISE_ENVELOPE_STRUCT *ptrNoiseEnvelope,
                    uint32 startFlag);
#endif /* #if (0u != (CapSense_1_CSD_AUTOTUNE & CapSense_1_CSD_SS_TH_EN)) */

#if (0u != CapSense_1_CSX_MULTIPHASE_TX_EN)
    void CapSense_1_DpDeconvolution(CapSense_1_FLASH_WD_STRUCT const *ptrFlashWdgt);
#endif /* #if (0u != CapSense_1_CSX_MULTIPHASE_TX_EN) */


/** \}
* \endif */

#endif /* End CY_CAPSENSE_CapSense_1_DATA_PROCESS_H */


/* [] END OF FILE */
