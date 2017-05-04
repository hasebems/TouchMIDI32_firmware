/***************************************************************************//**
* \file .h
* \version 3.20
*
* \brief
*  This private file provides constants and parameter values for the
*  SCB Component.
*  Please do not use this file or its content in your project.
*
* Note:
*
********************************************************************************
* \copyright
* Copyright 2013-2016, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_SCB_PVT_EZI2C_1_H)
#define CY_SCB_PVT_EZI2C_1_H

#include "EZI2C_1.h"


/***************************************
*     Private Function Prototypes
***************************************/

/* APIs to service INTR_I2C_EC register */
#define EZI2C_1_SetI2CExtClkInterruptMode(interruptMask) EZI2C_1_WRITE_INTR_I2C_EC_MASK(interruptMask)
#define EZI2C_1_ClearI2CExtClkInterruptSource(interruptMask) EZI2C_1_CLEAR_INTR_I2C_EC(interruptMask)
#define EZI2C_1_GetI2CExtClkInterruptSource()                (EZI2C_1_INTR_I2C_EC_REG)
#define EZI2C_1_GetI2CExtClkInterruptMode()                  (EZI2C_1_INTR_I2C_EC_MASK_REG)
#define EZI2C_1_GetI2CExtClkInterruptSourceMasked()          (EZI2C_1_INTR_I2C_EC_MASKED_REG)

#if (!EZI2C_1_CY_SCBIP_V1)
    /* APIs to service INTR_SPI_EC register */
    #define EZI2C_1_SetSpiExtClkInterruptMode(interruptMask) \
                                                                EZI2C_1_WRITE_INTR_SPI_EC_MASK(interruptMask)
    #define EZI2C_1_ClearSpiExtClkInterruptSource(interruptMask) \
                                                                EZI2C_1_CLEAR_INTR_SPI_EC(interruptMask)
    #define EZI2C_1_GetExtSpiClkInterruptSource()                 (EZI2C_1_INTR_SPI_EC_REG)
    #define EZI2C_1_GetExtSpiClkInterruptMode()                   (EZI2C_1_INTR_SPI_EC_MASK_REG)
    #define EZI2C_1_GetExtSpiClkInterruptSourceMasked()           (EZI2C_1_INTR_SPI_EC_MASKED_REG)
#endif /* (!EZI2C_1_CY_SCBIP_V1) */

#if(EZI2C_1_SCB_MODE_UNCONFIG_CONST_CFG)
    extern void EZI2C_1_SetPins(uint32 mode, uint32 subMode, uint32 uartEnableMask);
#endif /* (EZI2C_1_SCB_MODE_UNCONFIG_CONST_CFG) */


/***************************************
*     Vars with External Linkage
***************************************/

#if (EZI2C_1_SCB_IRQ_INTERNAL)
#if !defined (CY_REMOVE_EZI2C_1_CUSTOM_INTR_HANDLER)
    extern cyisraddress EZI2C_1_customIntrHandler;
#endif /* !defined (CY_REMOVE_EZI2C_1_CUSTOM_INTR_HANDLER) */
#endif /* (EZI2C_1_SCB_IRQ_INTERNAL) */

extern EZI2C_1_BACKUP_STRUCT EZI2C_1_backup;

#if(EZI2C_1_SCB_MODE_UNCONFIG_CONST_CFG)
    /* Common configuration variables */
    extern uint8 EZI2C_1_scbMode;
    extern uint8 EZI2C_1_scbEnableWake;
    extern uint8 EZI2C_1_scbEnableIntr;

    /* I2C configuration variables */
    extern uint8 EZI2C_1_mode;
    extern uint8 EZI2C_1_acceptAddr;

    /* SPI/UART configuration variables */
    extern volatile uint8 * EZI2C_1_rxBuffer;
    extern uint8   EZI2C_1_rxDataBits;
    extern uint32  EZI2C_1_rxBufferSize;

    extern volatile uint8 * EZI2C_1_txBuffer;
    extern uint8   EZI2C_1_txDataBits;
    extern uint32  EZI2C_1_txBufferSize;

    /* EZI2C configuration variables */
    extern uint8 EZI2C_1_numberOfAddr;
    extern uint8 EZI2C_1_subAddrSize;
#endif /* (EZI2C_1_SCB_MODE_UNCONFIG_CONST_CFG) */

#if (! (EZI2C_1_SCB_MODE_I2C_CONST_CFG || \
        EZI2C_1_SCB_MODE_EZI2C_CONST_CFG))
    extern uint16 EZI2C_1_IntrTxMask;
#endif /* (! (EZI2C_1_SCB_MODE_I2C_CONST_CFG || \
              EZI2C_1_SCB_MODE_EZI2C_CONST_CFG)) */


/***************************************
*        Conditional Macro
****************************************/

#if(EZI2C_1_SCB_MODE_UNCONFIG_CONST_CFG)
    /* Defines run time operation mode */
    #define EZI2C_1_SCB_MODE_I2C_RUNTM_CFG     (EZI2C_1_SCB_MODE_I2C      == EZI2C_1_scbMode)
    #define EZI2C_1_SCB_MODE_SPI_RUNTM_CFG     (EZI2C_1_SCB_MODE_SPI      == EZI2C_1_scbMode)
    #define EZI2C_1_SCB_MODE_UART_RUNTM_CFG    (EZI2C_1_SCB_MODE_UART     == EZI2C_1_scbMode)
    #define EZI2C_1_SCB_MODE_EZI2C_RUNTM_CFG   (EZI2C_1_SCB_MODE_EZI2C    == EZI2C_1_scbMode)
    #define EZI2C_1_SCB_MODE_UNCONFIG_RUNTM_CFG \
                                                        (EZI2C_1_SCB_MODE_UNCONFIG == EZI2C_1_scbMode)

    /* Defines wakeup enable */
    #define EZI2C_1_SCB_WAKE_ENABLE_CHECK       (0u != EZI2C_1_scbEnableWake)
#endif /* (EZI2C_1_SCB_MODE_UNCONFIG_CONST_CFG) */

/* Defines maximum number of SCB pins */
#if (!EZI2C_1_CY_SCBIP_V1)
    #define EZI2C_1_SCB_PINS_NUMBER    (7u)
#else
    #define EZI2C_1_SCB_PINS_NUMBER    (2u)
#endif /* (!EZI2C_1_CY_SCBIP_V1) */

#endif /* (CY_SCB_PVT_EZI2C_1_H) */


/* [] END OF FILE */
