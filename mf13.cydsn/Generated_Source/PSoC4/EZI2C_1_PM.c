/***************************************************************************//**
* \file EZI2C_1_PM.c
* \version 3.20
*
* \brief
*  This file provides the source code to the Power Management support for
*  the SCB Component.
*
* Note:
*
********************************************************************************
* \copyright
* Copyright 2013-2016, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "EZI2C_1.h"
#include "EZI2C_1_PVT.h"

#if(EZI2C_1_SCB_MODE_I2C_INC)
    #include "EZI2C_1_I2C_PVT.h"
#endif /* (EZI2C_1_SCB_MODE_I2C_INC) */

#if(EZI2C_1_SCB_MODE_EZI2C_INC)
    #include "EZI2C_1_EZI2C_PVT.h"
#endif /* (EZI2C_1_SCB_MODE_EZI2C_INC) */

#if(EZI2C_1_SCB_MODE_SPI_INC || EZI2C_1_SCB_MODE_UART_INC)
    #include "EZI2C_1_SPI_UART_PVT.h"
#endif /* (EZI2C_1_SCB_MODE_SPI_INC || EZI2C_1_SCB_MODE_UART_INC) */


/***************************************
*   Backup Structure declaration
***************************************/

#if(EZI2C_1_SCB_MODE_UNCONFIG_CONST_CFG || \
   (EZI2C_1_SCB_MODE_I2C_CONST_CFG   && (!EZI2C_1_I2C_WAKE_ENABLE_CONST))   || \
   (EZI2C_1_SCB_MODE_EZI2C_CONST_CFG && (!EZI2C_1_EZI2C_WAKE_ENABLE_CONST)) || \
   (EZI2C_1_SCB_MODE_SPI_CONST_CFG   && (!EZI2C_1_SPI_WAKE_ENABLE_CONST))   || \
   (EZI2C_1_SCB_MODE_UART_CONST_CFG  && (!EZI2C_1_UART_WAKE_ENABLE_CONST)))

    EZI2C_1_BACKUP_STRUCT EZI2C_1_backup =
    {
        0u, /* enableState */
    };
#endif


/*******************************************************************************
* Function Name: EZI2C_1_Sleep
****************************************************************************//**
*
*  Prepares the EZI2C_1 component to enter Deep Sleep.
*  The ÅgEnable wakeup from Deep Sleep ModeÅh selection has an influence on this 
*  function implementation:
*  - Checked: configures the component to be wakeup source from Deep Sleep.
*  - Unchecked: stores the current component state (enabled or disabled) and 
*    disables the component. See SCB_Stop() function for details about component 
*    disabling.
*
*  Call the EZI2C_1_Sleep() function before calling the 
*  CyPmSysDeepSleep() function. 
*  Refer to the PSoC Creator System Reference Guide for more information about 
*  power management functions and Low power section of this document for the 
*  selected mode.
*
*  This function should not be called before entering Sleep.
*
*******************************************************************************/
void EZI2C_1_Sleep(void)
{
#if(EZI2C_1_SCB_MODE_UNCONFIG_CONST_CFG)

    if(EZI2C_1_SCB_WAKE_ENABLE_CHECK)
    {
        if(EZI2C_1_SCB_MODE_I2C_RUNTM_CFG)
        {
            EZI2C_1_I2CSaveConfig();
        }
        else if(EZI2C_1_SCB_MODE_EZI2C_RUNTM_CFG)
        {
            EZI2C_1_EzI2CSaveConfig();
        }
    #if(!EZI2C_1_CY_SCBIP_V1)
        else if(EZI2C_1_SCB_MODE_SPI_RUNTM_CFG)
        {
            EZI2C_1_SpiSaveConfig();
        }
        else if(EZI2C_1_SCB_MODE_UART_RUNTM_CFG)
        {
            EZI2C_1_UartSaveConfig();
        }
    #endif /* (!EZI2C_1_CY_SCBIP_V1) */
        else
        {
            /* Unknown mode */
        }
    }
    else
    {
        EZI2C_1_backup.enableState = (uint8) EZI2C_1_GET_CTRL_ENABLED;

        if(0u != EZI2C_1_backup.enableState)
        {
            EZI2C_1_Stop();
        }
    }

#else

    #if (EZI2C_1_SCB_MODE_I2C_CONST_CFG && EZI2C_1_I2C_WAKE_ENABLE_CONST)
        EZI2C_1_I2CSaveConfig();

    #elif (EZI2C_1_SCB_MODE_EZI2C_CONST_CFG && EZI2C_1_EZI2C_WAKE_ENABLE_CONST)
        EZI2C_1_EzI2CSaveConfig();

    #elif (EZI2C_1_SCB_MODE_SPI_CONST_CFG && EZI2C_1_SPI_WAKE_ENABLE_CONST)
        EZI2C_1_SpiSaveConfig();

    #elif (EZI2C_1_SCB_MODE_UART_CONST_CFG && EZI2C_1_UART_WAKE_ENABLE_CONST)
        EZI2C_1_UartSaveConfig();

    #else

        EZI2C_1_backup.enableState = (uint8) EZI2C_1_GET_CTRL_ENABLED;

        if(0u != EZI2C_1_backup.enableState)
        {
            EZI2C_1_Stop();
        }

    #endif /* defined (EZI2C_1_SCB_MODE_I2C_CONST_CFG) && (EZI2C_1_I2C_WAKE_ENABLE_CONST) */

#endif /* (EZI2C_1_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/*******************************************************************************
* Function Name: EZI2C_1_Wakeup
****************************************************************************//**
*
*  Prepares the EZI2C_1 component for Active mode operation after 
*  Deep Sleep.
*  The ÅgEnable wakeup from Deep Sleep ModeÅh selection has influence on this 
*  function implementation:
*  - Checked: restores the component Active mode configuration.
*  - Unchecked: enables the component if it was enabled before enter Deep Sleep.
*
*  This function should not be called after exiting Sleep.
*
*  \sideeffect
*   Calling the EZI2C_1_Wakeup() function without first calling the 
*   EZI2C_1_Sleep() function may produce unexpected behavior.
*
*******************************************************************************/
void EZI2C_1_Wakeup(void)
{
#if(EZI2C_1_SCB_MODE_UNCONFIG_CONST_CFG)

    if(EZI2C_1_SCB_WAKE_ENABLE_CHECK)
    {
        if(EZI2C_1_SCB_MODE_I2C_RUNTM_CFG)
        {
            EZI2C_1_I2CRestoreConfig();
        }
        else if(EZI2C_1_SCB_MODE_EZI2C_RUNTM_CFG)
        {
            EZI2C_1_EzI2CRestoreConfig();
        }
    #if(!EZI2C_1_CY_SCBIP_V1)
        else if(EZI2C_1_SCB_MODE_SPI_RUNTM_CFG)
        {
            EZI2C_1_SpiRestoreConfig();
        }
        else if(EZI2C_1_SCB_MODE_UART_RUNTM_CFG)
        {
            EZI2C_1_UartRestoreConfig();
        }
    #endif /* (!EZI2C_1_CY_SCBIP_V1) */
        else
        {
            /* Unknown mode */
        }
    }
    else
    {
        if(0u != EZI2C_1_backup.enableState)
        {
            EZI2C_1_Enable();
        }
    }

#else

    #if (EZI2C_1_SCB_MODE_I2C_CONST_CFG  && EZI2C_1_I2C_WAKE_ENABLE_CONST)
        EZI2C_1_I2CRestoreConfig();

    #elif (EZI2C_1_SCB_MODE_EZI2C_CONST_CFG && EZI2C_1_EZI2C_WAKE_ENABLE_CONST)
        EZI2C_1_EzI2CRestoreConfig();

    #elif (EZI2C_1_SCB_MODE_SPI_CONST_CFG && EZI2C_1_SPI_WAKE_ENABLE_CONST)
        EZI2C_1_SpiRestoreConfig();

    #elif (EZI2C_1_SCB_MODE_UART_CONST_CFG && EZI2C_1_UART_WAKE_ENABLE_CONST)
        EZI2C_1_UartRestoreConfig();

    #else

        if(0u != EZI2C_1_backup.enableState)
        {
            EZI2C_1_Enable();
        }

    #endif /* (EZI2C_1_I2C_WAKE_ENABLE_CONST) */

#endif /* (EZI2C_1_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/* [] END OF FILE */
