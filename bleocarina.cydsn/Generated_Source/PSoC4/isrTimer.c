/*******************************************************************************
* File Name: isrTimer.c  
* Version 1.70
*
*  Description:
*   API for controlling the state of an interrupt.
*
*
*  Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/


#include <cydevice_trm.h>
#include <CyLib.h>
#include <isrTimer.h>
#include "cyapicallbacks.h"

#if !defined(isrTimer__REMOVED) /* Check for removal by optimization */

/*******************************************************************************
*  Place your includes, defines and code here 
********************************************************************************/
/* `#START isrTimer_intc` */
#include "SystemTimer.h"
#include "tm32_lib.h"
/* `#END` */

extern cyisraddress CyRamVectors[CYINT_IRQ_BASE + CY_NUM_INTERRUPTS];

/* Declared in startup, used to set unused interrupts to. */
CY_ISR_PROTO(IntDefaultHandler);


/*******************************************************************************
* Function Name: isrTimer_Start
********************************************************************************
*
* Summary:
*  Set up the interrupt and enable it. This function disables the interrupt, 
*  sets the default interrupt vector, sets the priority from the value in the
*  Design Wide Resources Interrupt Editor, then enables the interrupt to the 
*  interrupt controller.
*
* Parameters:  
*   None
*
* Return:
*   None
*
*******************************************************************************/
void isrTimer_Start(void)
{
    /* For all we know the interrupt is active. */
    isrTimer_Disable();

    /* Set the ISR to point to the isrTimer Interrupt. */
    isrTimer_SetVector(&isrTimer_Interrupt);

    /* Set the priority. */
    isrTimer_SetPriority((uint8)isrTimer_INTC_PRIOR_NUMBER);

    /* Enable it. */
    isrTimer_Enable();
}


/*******************************************************************************
* Function Name: isrTimer_StartEx
********************************************************************************
*
* Summary:
*  Sets up the interrupt and enables it. This function disables the interrupt,
*  sets the interrupt vector based on the address passed in, sets the priority 
*  from the value in the Design Wide Resources Interrupt Editor, then enables 
*  the interrupt to the interrupt controller.
*  
*  When defining ISR functions, the CY_ISR and CY_ISR_PROTO macros should be 
*  used to provide consistent definition across compilers:
*  
*  Function definition example:
*   CY_ISR(MyISR)
*   {
*   }
*   Function prototype example:
*   CY_ISR_PROTO(MyISR);
*
* Parameters:  
*   address: Address of the ISR to set in the interrupt vector table.
*
* Return:
*   None
*
*******************************************************************************/
void isrTimer_StartEx(cyisraddress address)
{
    /* For all we know the interrupt is active. */
    isrTimer_Disable();

    /* Set the ISR to point to the isrTimer Interrupt. */
    isrTimer_SetVector(address);

    /* Set the priority. */
    isrTimer_SetPriority((uint8)isrTimer_INTC_PRIOR_NUMBER);

    /* Enable it. */
    isrTimer_Enable();
}


/*******************************************************************************
* Function Name: isrTimer_Stop
********************************************************************************
*
* Summary:
*   Disables and removes the interrupt.
*
* Parameters:  
*   None
*
* Return:
*   None
*
*******************************************************************************/
void isrTimer_Stop(void)
{
    /* Disable this interrupt. */
    isrTimer_Disable();

    /* Set the ISR to point to the passive one. */
    isrTimer_SetVector(&IntDefaultHandler);
}


/*******************************************************************************
* Function Name: isrTimer_Interrupt
********************************************************************************
*
* Summary:
*   The default Interrupt Service Routine for isrTimer.
*
*   Add custom code between the START and END comments to keep the next version
*   of this file from over-writing your code.
*
*   Note You may use either the default ISR by using this API, or you may define
*   your own separate ISR through ISR_StartEx().
*
* Parameters:  
*   None
*
* Return:
*   None
*
*******************************************************************************/
CY_ISR(isrTimer_Interrupt)
{
    #ifdef isrTimer_INTERRUPT_INTERRUPT_CALLBACK
        isrTimer_Interrupt_InterruptCallback();
    #endif /* isrTimer_INTERRUPT_INTERRUPT_CALLBACK */ 

    /*  Place your Interrupt code here. */
    /* `#START isrTimer_Interrupt` */
	tm32_systemTimer++;
	tm32_intrpt();
	SystemTimer_ReadStatusRegister();
    /* `#END` */
}


/*******************************************************************************
* Function Name: isrTimer_SetVector
********************************************************************************
*
* Summary:
*   Change the ISR vector for the Interrupt. Note calling isrTimer_Start
*   will override any effect this method would have had. To set the vector 
*   before the component has been started use isrTimer_StartEx instead.
* 
*   When defining ISR functions, the CY_ISR and CY_ISR_PROTO macros should be 
*   used to provide consistent definition across compilers:
*
*   Function definition example:
*   CY_ISR(MyISR)
*   {
*   }
*
*   Function prototype example:
*     CY_ISR_PROTO(MyISR);
*
* Parameters:
*   address: Address of the ISR to set in the interrupt vector table.
*
* Return:
*   None
*
*******************************************************************************/
void isrTimer_SetVector(cyisraddress address)
{
    CyRamVectors[CYINT_IRQ_BASE + isrTimer__INTC_NUMBER] = address;
}


/*******************************************************************************
* Function Name: isrTimer_GetVector
********************************************************************************
*
* Summary:
*   Gets the "address" of the current ISR vector for the Interrupt.
*
* Parameters:
*   None
*
* Return:
*   Address of the ISR in the interrupt vector table.
*
*******************************************************************************/
cyisraddress isrTimer_GetVector(void)
{
    return CyRamVectors[CYINT_IRQ_BASE + isrTimer__INTC_NUMBER];
}


/*******************************************************************************
* Function Name: isrTimer_SetPriority
********************************************************************************
*
* Summary:
*   Sets the Priority of the Interrupt. 
*
*   Note calling isrTimer_Start or isrTimer_StartEx will 
*   override any effect this API would have had. This API should only be called
*   after isrTimer_Start or isrTimer_StartEx has been called. 
*   To set the initial priority for the component, use the Design-Wide Resources
*   Interrupt Editor.
*
*   Note This API has no effect on Non-maskable interrupt NMI).
*
* Parameters:
*   priority: Priority of the interrupt, 0 being the highest priority
*             PSoC 3 and PSoC 5LP: Priority is from 0 to 7.
*             PSoC 4: Priority is from 0 to 3.
*
* Return:
*   None
*
*******************************************************************************/
void isrTimer_SetPriority(uint8 priority)
{
	uint8 interruptState;
    uint32 priorityOffset = ((isrTimer__INTC_NUMBER % 4u) * 8u) + 6u;
    
	interruptState = CyEnterCriticalSection();
    *isrTimer_INTC_PRIOR = (*isrTimer_INTC_PRIOR & (uint32)(~isrTimer__INTC_PRIOR_MASK)) |
                                    ((uint32)priority << priorityOffset);
	CyExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: isrTimer_GetPriority
********************************************************************************
*
* Summary:
*   Gets the Priority of the Interrupt.
*
* Parameters:
*   None
*
* Return:
*   Priority of the interrupt, 0 being the highest priority
*    PSoC 3 and PSoC 5LP: Priority is from 0 to 7.
*    PSoC 4: Priority is from 0 to 3.
*
*******************************************************************************/
uint8 isrTimer_GetPriority(void)
{
    uint32 priority;
	uint32 priorityOffset = ((isrTimer__INTC_NUMBER % 4u) * 8u) + 6u;

    priority = (*isrTimer_INTC_PRIOR & isrTimer__INTC_PRIOR_MASK) >> priorityOffset;

    return (uint8)priority;
}


/*******************************************************************************
* Function Name: isrTimer_Enable
********************************************************************************
*
* Summary:
*   Enables the interrupt to the interrupt controller. Do not call this function
*   unless ISR_Start() has been called or the functionality of the ISR_Start() 
*   function, which sets the vector and the priority, has been called.
*
* Parameters:
*   None
*
* Return:
*   None
*
*******************************************************************************/
void isrTimer_Enable(void)
{
    /* Enable the general interrupt. */
    *isrTimer_INTC_SET_EN = isrTimer__INTC_MASK;
}


/*******************************************************************************
* Function Name: isrTimer_GetState
********************************************************************************
*
* Summary:
*   Gets the state (enabled, disabled) of the Interrupt.
*
* Parameters:
*   None
*
* Return:
*   1 if enabled, 0 if disabled.
*
*******************************************************************************/
uint8 isrTimer_GetState(void)
{
    /* Get the state of the general interrupt. */
    return ((*isrTimer_INTC_SET_EN & (uint32)isrTimer__INTC_MASK) != 0u) ? 1u:0u;
}


/*******************************************************************************
* Function Name: isrTimer_Disable
********************************************************************************
*
* Summary:
*   Disables the Interrupt in the interrupt controller.
*
* Parameters:
*   None
*
* Return:
*   None
*
*******************************************************************************/
void isrTimer_Disable(void)
{
    /* Disable the general interrupt. */
    *isrTimer_INTC_CLR_EN = isrTimer__INTC_MASK;
}


/*******************************************************************************
* Function Name: isrTimer_SetPending
********************************************************************************
*
* Summary:
*   Causes the Interrupt to enter the pending state, a software method of
*   generating the interrupt.
*
* Parameters:
*   None
*
* Return:
*   None
*
* Side Effects:
*   If interrupts are enabled and the interrupt is set up properly, the ISR is
*   entered (depending on the priority of this interrupt and other pending 
*   interrupts).
*
*******************************************************************************/
void isrTimer_SetPending(void)
{
    *isrTimer_INTC_SET_PD = isrTimer__INTC_MASK;
}


/*******************************************************************************
* Function Name: isrTimer_ClearPending
********************************************************************************
*
* Summary:
*   Clears a pending interrupt in the interrupt controller.
*
*   Note Some interrupt sources are clear-on-read and require the block 
*   interrupt/status register to be read/cleared with the appropriate block API 
*   (GPIO, UART, and so on). Otherwise the ISR will continue to remain in 
*   pending state even though the interrupt itself is cleared using this API.
*
* Parameters:
*   None
*
* Return:
*   None
*
*******************************************************************************/
void isrTimer_ClearPending(void)
{
    *isrTimer_INTC_CLR_PD = isrTimer__INTC_MASK;
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
