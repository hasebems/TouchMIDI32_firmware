/***************************************************************************//**
* \file USBMIDI_cls.c
* \version 3.10
*
* \brief
*  This file contains the USB Class request handler.
*
********************************************************************************
* \copyright
* Copyright 2008-2016, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "USBMIDI_pvt.h"
#include "cyapicallbacks.h"

#if(USBMIDI_EXTERN_CLS == USBMIDI_FALSE)

/***************************************
* User Implemented Class Driver Declarations.
***************************************/
/* `#START USER_DEFINED_CLASS_DECLARATIONS` Place your declaration here */

/* `#END` */


/*******************************************************************************
* Function Name: USBMIDI_DispatchClassRqst
****************************************************************************//**
*  This routine dispatches class specific requests depend on interface class.
*
* \return
*  requestHandled.
*
* \reentrant
*  No.
*
*******************************************************************************/
uint8 USBMIDI_DispatchClassRqst(void) 
{
    uint8 requestHandled;
    uint8 interfaceNumber;

    /* Get interface to which request is intended. */
    switch (USBMIDI_bmRequestTypeReg & USBMIDI_RQST_RCPT_MASK)
    {
        case USBMIDI_RQST_RCPT_IFC:
            /* Class-specific request directed to interface: wIndexLoReg 
            * contains interface number.
            */
            interfaceNumber = (uint8) USBMIDI_wIndexLoReg;
            break;
        
        case USBMIDI_RQST_RCPT_EP:
            /* Class-specific request directed to endpoint: wIndexLoReg contains 
            * endpoint number. Find interface related to endpoint, 
            */
            interfaceNumber = USBMIDI_EP[USBMIDI_wIndexLoReg & USBMIDI_DIR_UNUSED].interface;
            break;
            
        default:
            /* Default interface is zero. */
            interfaceNumber = 0u;
            break;
    }

#if (defined(USBMIDI_ENABLE_HID_CLASS) ||\
            defined(USBMIDI_ENABLE_AUDIO_CLASS) ||\
            defined(USBMIDI_ENABLE_CDC_CLASS) ||\
            USBMIDI_ENABLE_MSC_CLASS)

    /* Handle class request depends on interface type. */
    switch (USBMIDI_interfaceClass[interfaceNumber])
    {
    #if defined(USBMIDI_ENABLE_HID_CLASS)
        case USBMIDI_CLASS_HID:
            requestHandled = USBMIDI_DispatchHIDClassRqst();
            break;
    #endif /* (USBMIDI_ENABLE_HID_CLASS) */
            
    #if defined(USBMIDI_ENABLE_AUDIO_CLASS)
        case USBMIDI_CLASS_AUDIO:
            requestHandled = USBMIDI_DispatchAUDIOClassRqst();
            break;
    #endif /* (USBMIDI_CLASS_AUDIO) */
            
    #if defined(USBMIDI_ENABLE_CDC_CLASS)
        case USBMIDI_CLASS_CDC:
            requestHandled = USBMIDI_DispatchCDCClassRqst();
            break;
    #endif /* (USBMIDI_ENABLE_CDC_CLASS) */
        
    #if (USBMIDI_ENABLE_MSC_CLASS)
        case USBMIDI_CLASS_MSD:
        #if (USBMIDI_HANDLE_MSC_REQUESTS)
            /* MSC requests are handled by the component. */
            requestHandled = USBMIDI_DispatchMSCClassRqst();
        #elif defined(USBMIDI_DISPATCH_MSC_CLASS_RQST_CALLBACK)
            /* MSC requests are handled by user defined callbcak. */
            requestHandled = USBMIDI_DispatchMSCClassRqst_Callback();
        #else
            /* MSC requests are not handled. */
            requestHandled = USBMIDI_FALSE;
        #endif /* (USBMIDI_HANDLE_MSC_REQUESTS) */
            break;
    #endif /* (USBMIDI_ENABLE_MSC_CLASS) */
        
        default:
            /* Request is not handled: unknown class request type. */
            requestHandled = USBMIDI_FALSE;
            break;
    }
#else /*No class is defined*/
    if (0u != interfaceNumber)
    {
        /* Suppress warning message */
    }
    requestHandled = USBMIDI_FALSE;
#endif /*HID or AUDIO or MSC or CDC class enabled*/

    /* `#START USER_DEFINED_CLASS_CODE` Place your Class request here */

    /* `#END` */

#ifdef USBMIDI_DISPATCH_CLASS_RQST_CALLBACK
    if (USBMIDI_FALSE == requestHandled)
    {
        requestHandled = USBMIDI_DispatchClassRqst_Callback(interfaceNumber);
    }
#endif /* (USBMIDI_DISPATCH_CLASS_RQST_CALLBACK) */

    return (requestHandled);
}


/*******************************************************************************
* Additional user functions supporting Class Specific Requests
********************************************************************************/

/* `#START CLASS_SPECIFIC_FUNCTIONS` Place any additional functions here */

/* `#END` */

#endif /* USBMIDI_EXTERN_CLS */


/* [] END OF FILE */
