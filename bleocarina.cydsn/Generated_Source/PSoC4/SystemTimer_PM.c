/*******************************************************************************
* File Name: SystemTimer_PM.c
* Version 2.70
*
*  Description:
*     This file provides the power management source code to API for the
*     Timer.
*
*   Note:
*     None
*
*******************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
********************************************************************************/

#include "SystemTimer.h"

static SystemTimer_backupStruct SystemTimer_backup;


/*******************************************************************************
* Function Name: SystemTimer_SaveConfig
********************************************************************************
*
* Summary:
*     Save the current user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  SystemTimer_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void SystemTimer_SaveConfig(void) 
{
    #if (!SystemTimer_UsingFixedFunction)
        SystemTimer_backup.TimerUdb = SystemTimer_ReadCounter();
        SystemTimer_backup.InterruptMaskValue = SystemTimer_STATUS_MASK;
        #if (SystemTimer_UsingHWCaptureCounter)
            SystemTimer_backup.TimerCaptureCounter = SystemTimer_ReadCaptureCount();
        #endif /* Back Up capture counter register  */

        #if(!SystemTimer_UDB_CONTROL_REG_REMOVED)
            SystemTimer_backup.TimerControlRegister = SystemTimer_ReadControlRegister();
        #endif /* Backup the enable state of the Timer component */
    #endif /* Backup non retention registers in UDB implementation. All fixed function registers are retention */
}


/*******************************************************************************
* Function Name: SystemTimer_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration.
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  SystemTimer_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void SystemTimer_RestoreConfig(void) 
{   
    #if (!SystemTimer_UsingFixedFunction)

        SystemTimer_WriteCounter(SystemTimer_backup.TimerUdb);
        SystemTimer_STATUS_MASK =SystemTimer_backup.InterruptMaskValue;
        #if (SystemTimer_UsingHWCaptureCounter)
            SystemTimer_SetCaptureCount(SystemTimer_backup.TimerCaptureCounter);
        #endif /* Restore Capture counter register*/

        #if(!SystemTimer_UDB_CONTROL_REG_REMOVED)
            SystemTimer_WriteControlRegister(SystemTimer_backup.TimerControlRegister);
        #endif /* Restore the enable state of the Timer component */
    #endif /* Restore non retention registers in the UDB implementation only */
}


/*******************************************************************************
* Function Name: SystemTimer_Sleep
********************************************************************************
*
* Summary:
*     Stop and Save the user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  SystemTimer_backup.TimerEnableState:  Is modified depending on the
*  enable state of the block before entering sleep mode.
*
*******************************************************************************/
void SystemTimer_Sleep(void) 
{
    #if(!SystemTimer_UDB_CONTROL_REG_REMOVED)
        /* Save Counter's enable state */
        if(SystemTimer_CTRL_ENABLE == (SystemTimer_CONTROL & SystemTimer_CTRL_ENABLE))
        {
            /* Timer is enabled */
            SystemTimer_backup.TimerEnableState = 1u;
        }
        else
        {
            /* Timer is disabled */
            SystemTimer_backup.TimerEnableState = 0u;
        }
    #endif /* Back up enable state from the Timer control register */
    SystemTimer_Stop();
    SystemTimer_SaveConfig();
}


/*******************************************************************************
* Function Name: SystemTimer_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  SystemTimer_backup.enableState:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void SystemTimer_Wakeup(void) 
{
    SystemTimer_RestoreConfig();
    #if(!SystemTimer_UDB_CONTROL_REG_REMOVED)
        if(SystemTimer_backup.TimerEnableState == 1u)
        {     /* Enable Timer's operation */
                SystemTimer_Enable();
        } /* Do nothing if Timer was disabled before */
    #endif /* Remove this code section if Control register is removed */
}


/* [] END OF FILE */
