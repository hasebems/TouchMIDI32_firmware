/***************************************************************************//**
* \file CapSense_1.h
* \version 3.10
*
* \brief
*   This file includes all header files of the CapSense_1 component modules.
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

#if !defined(CY_CAPSENSE_CapSense_1_H)

#define CY_CAPSENSE_CapSense_1_H

#include "CapSense_1_Configuration.h"
#include "CapSense_1_Control.h"
#include "CapSense_1_Filter.h"
#include "CapSense_1_Processing.h"
#include "CapSense_1_Sensing.h"
#if (CapSense_1_ENABLE == CapSense_1_CSD_EN)
    #include "CapSense_1_SensingCSD_LL.h"
#endif /* (CapSense_1_ENABLE == CapSense_1_CSD_EN) */
#if (CapSense_1_ENABLE == CapSense_1_CSD2X_EN)
    #include "CapSense_1_SensingCSD2X_LL.h"
#endif /* (CapSense_1_ENABLE == CapSense_1_CSD2X_EN) */
#if (CapSense_1_ENABLE == CapSense_1_CSX_EN)
    #include "CapSense_1_SensingCSX_LL.h"
#endif /* (CapSense_1_ENABLE == CapSense_1_CSX_EN) */
#include "CapSense_1_Structure.h"
#include "CapSense_1_Tuner.h"

#endif /* End CY_CAPSENSE_CapSense_1_H */


/* [] END OF FILE */
