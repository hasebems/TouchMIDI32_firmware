/***************************************************************************//**
* \file USBMIDI_cdc.c
* \version 3.10
*
* \brief
*  This file contains the USB MSC Class request handler and global API for MSC 
*  class.
*
* Related Document:
*  Universal Serial Bus Class Definitions for Communication Devices Version 1.1
*
********************************************************************************
* \copyright
* Copyright 2012-2016, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "USBMIDI_msc.h"
#include "USBMIDI_pvt.h"
#include "cyapicallbacks.h"

#if (USBMIDI_HANDLE_MSC_REQUESTS)

/***************************************
*          Internal variables
***************************************/

static uint8 USBMIDI_lunCount = USBMIDI_MSC_LUN_NUMBER;


/*******************************************************************************
* Function Name: USBMIDI_DispatchMSCClassRqst
****************************************************************************//**
*   
*  \internal 
*  This routine dispatches MSC class requests.
*
* \return
*  Status of request processing: handled or not handled.
*
* \globalvars
*  USBMIDI_lunCount - stores number of LUN (logical units).
*
* \reentrant
*  No.
*
*******************************************************************************/
uint8 USBMIDI_DispatchMSCClassRqst(void) 
{
    uint8 requestHandled = USBMIDI_FALSE;
    
    /* Get request data. */
    uint16 value  = USBMIDI_GET_UINT16(USBMIDI_wValueHiReg,  USBMIDI_wValueLoReg);
    uint16 dataLength = USBMIDI_GET_UINT16(USBMIDI_wLengthHiReg, USBMIDI_wLengthLoReg);
       
    /* Check request direction: D2H or H2D. */
    if (0u != (USBMIDI_bmRequestTypeReg & USBMIDI_RQST_DIR_D2H))
    {
        /* Handle direction from device to host. */
        
        if (USBMIDI_MSC_GET_MAX_LUN == USBMIDI_bRequestReg)
        {
            /* Check request fields. */
            if ((value  == USBMIDI_MSC_GET_MAX_LUN_WVALUE) &&
                (dataLength == USBMIDI_MSC_GET_MAX_LUN_WLENGTH))
            {
                /* Reply to Get Max LUN request: setup control read. */
                USBMIDI_currentTD.pData = &USBMIDI_lunCount;
                USBMIDI_currentTD.count =  USBMIDI_MSC_GET_MAX_LUN_WLENGTH;
                
                requestHandled  = USBMIDI_InitControlRead();
            }
        }
    }
    else
    {
        /* Handle direction from host to device. */
        
        if (USBMIDI_MSC_RESET == USBMIDI_bRequestReg)
        {
            /* Check request fields. */
            if ((value  == USBMIDI_MSC_RESET_WVALUE) &&
                (dataLength == USBMIDI_MSC_RESET_WLENGTH))
            {
                /* Handle to Bulk-Only Reset request: no data control transfer. */
                USBMIDI_currentTD.count = USBMIDI_MSC_RESET_WLENGTH;
                
            #ifdef USBMIDI_DISPATCH_MSC_CLASS_MSC_RESET_RQST_CALLBACK
                USBMIDI_DispatchMSCClass_MSC_RESET_RQST_Callback();
            #endif /* (USBMIDI_DISPATCH_MSC_CLASS_MSC_RESET_RQST_CALLBACK) */
                
                requestHandled = USBMIDI_InitNoDataControlTransfer();
            }
        }
    }
    
    return (requestHandled);
}


/*******************************************************************************
* Function Name: USBMIDI_MSC_SetLunCount
****************************************************************************//**
*
*  This function sets the number of logical units supported in the application. 
*  The default number of logical units is set in the component customizer.
*
*  \param lunCount: Count of the logical units. Valid range is between 1 and 16.
*
*
* \globalvars
*  USBMIDI_lunCount - stores number of LUN (logical units).
*
* \reentrant
*  No.
*
*******************************************************************************/
void USBMIDI_MSC_SetLunCount(uint8 lunCount) 
{
    USBMIDI_lunCount = (lunCount - 1u);
}


/*******************************************************************************
* Function Name: USBMIDI_MSC_GetLunCount
****************************************************************************//**
*
*  This function returns the number of logical units.
*
* \return
*   Number of the logical units.
*
* \globalvars
*  USBMIDI_lunCount - stores number of LUN (logical units).
*
* \reentrant
*  No.
*
*******************************************************************************/
uint8 USBMIDI_MSC_GetLunCount(void) 
{
    return (USBMIDI_lunCount + 1u);
}   

#endif /* (USBMIDI_HANDLE_MSC_REQUESTS) */


/* [] END OF FILE */
