/*******************************************************************************
* File Name: SystemTimer.h
* Version 2.70
*
*  Description:
*     Contains the function prototypes and constants available to the timer
*     user module.
*
*   Note:
*     None
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
********************************************************************************/

#if !defined(CY_Timer_v2_60_SystemTimer_H)
#define CY_Timer_v2_60_SystemTimer_H

#include "cytypes.h"
#include "cyfitter.h"
#include "CyLib.h" /* For CyEnterCriticalSection() and CyExitCriticalSection() functions */

extern uint8 SystemTimer_initVar;

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component Timer_v2_70 requires cy_boot v3.0 or later
#endif /* (CY_ PSOC5LP) */


/**************************************
*           Parameter Defaults
**************************************/

#define SystemTimer_Resolution                 8u
#define SystemTimer_UsingFixedFunction         0u
#define SystemTimer_UsingHWCaptureCounter      0u
#define SystemTimer_SoftwareCaptureMode        0u
#define SystemTimer_SoftwareTriggerMode        0u
#define SystemTimer_UsingHWEnable              0u
#define SystemTimer_EnableTriggerMode          0u
#define SystemTimer_InterruptOnCaptureCount    0u
#define SystemTimer_RunModeUsed                0u
#define SystemTimer_ControlRegRemoved          0u

#if defined(SystemTimer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_REG)
    #define SystemTimer_UDB_CONTROL_REG_REMOVED            (0u)
#elif  (SystemTimer_UsingFixedFunction)
    #define SystemTimer_UDB_CONTROL_REG_REMOVED            (0u)
#else 
    #define SystemTimer_UDB_CONTROL_REG_REMOVED            (1u)
#endif /* End SystemTimer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_REG */


/***************************************
*       Type defines
***************************************/


/**************************************************************************
 * Sleep Wakeup Backup structure for Timer Component
 *************************************************************************/
typedef struct
{
    uint8 TimerEnableState;
    #if(!SystemTimer_UsingFixedFunction)

        uint8 TimerUdb;
        uint8 InterruptMaskValue;
        #if (SystemTimer_UsingHWCaptureCounter)
            uint8 TimerCaptureCounter;
        #endif /* variable declarations for backing up non retention registers in CY_UDB_V1 */

        #if (!SystemTimer_UDB_CONTROL_REG_REMOVED)
            uint8 TimerControlRegister;
        #endif /* variable declaration for backing up enable state of the Timer */
    #endif /* define backup variables only for UDB implementation. Fixed function registers are all retention */

}SystemTimer_backupStruct;


/***************************************
*       Function Prototypes
***************************************/

void    SystemTimer_Start(void) ;
void    SystemTimer_Stop(void) ;

void    SystemTimer_SetInterruptMode(uint8 interruptMode) ;
uint8   SystemTimer_ReadStatusRegister(void) ;
/* Deprecated function. Do not use this in future. Retained for backward compatibility */
#define SystemTimer_GetInterruptSource() SystemTimer_ReadStatusRegister()

#if(!SystemTimer_UDB_CONTROL_REG_REMOVED)
    uint8   SystemTimer_ReadControlRegister(void) ;
    void    SystemTimer_WriteControlRegister(uint8 control) ;
#endif /* (!SystemTimer_UDB_CONTROL_REG_REMOVED) */

uint8  SystemTimer_ReadPeriod(void) ;
void    SystemTimer_WritePeriod(uint8 period) ;
uint8  SystemTimer_ReadCounter(void) ;
void    SystemTimer_WriteCounter(uint8 counter) ;
uint8  SystemTimer_ReadCapture(void) ;
void    SystemTimer_SoftwareCapture(void) ;

#if(!SystemTimer_UsingFixedFunction) /* UDB Prototypes */
    #if (SystemTimer_SoftwareCaptureMode)
        void    SystemTimer_SetCaptureMode(uint8 captureMode) ;
    #endif /* (!SystemTimer_UsingFixedFunction) */

    #if (SystemTimer_SoftwareTriggerMode)
        void    SystemTimer_SetTriggerMode(uint8 triggerMode) ;
    #endif /* (SystemTimer_SoftwareTriggerMode) */

    #if (SystemTimer_EnableTriggerMode)
        void    SystemTimer_EnableTrigger(void) ;
        void    SystemTimer_DisableTrigger(void) ;
    #endif /* (SystemTimer_EnableTriggerMode) */


    #if(SystemTimer_InterruptOnCaptureCount)
        void    SystemTimer_SetInterruptCount(uint8 interruptCount) ;
    #endif /* (SystemTimer_InterruptOnCaptureCount) */

    #if (SystemTimer_UsingHWCaptureCounter)
        void    SystemTimer_SetCaptureCount(uint8 captureCount) ;
        uint8   SystemTimer_ReadCaptureCount(void) ;
    #endif /* (SystemTimer_UsingHWCaptureCounter) */

    void SystemTimer_ClearFIFO(void) ;
#endif /* UDB Prototypes */

/* Sleep Retention APIs */
void SystemTimer_Init(void)          ;
void SystemTimer_Enable(void)        ;
void SystemTimer_SaveConfig(void)    ;
void SystemTimer_RestoreConfig(void) ;
void SystemTimer_Sleep(void)         ;
void SystemTimer_Wakeup(void)        ;


/***************************************
*   Enumerated Types and Parameters
***************************************/

/* Enumerated Type B_Timer__CaptureModes, Used in Capture Mode */
#define SystemTimer__B_TIMER__CM_NONE 0
#define SystemTimer__B_TIMER__CM_RISINGEDGE 1
#define SystemTimer__B_TIMER__CM_FALLINGEDGE 2
#define SystemTimer__B_TIMER__CM_EITHEREDGE 3
#define SystemTimer__B_TIMER__CM_SOFTWARE 4



/* Enumerated Type B_Timer__TriggerModes, Used in Trigger Mode */
#define SystemTimer__B_TIMER__TM_NONE 0x00u
#define SystemTimer__B_TIMER__TM_RISINGEDGE 0x04u
#define SystemTimer__B_TIMER__TM_FALLINGEDGE 0x08u
#define SystemTimer__B_TIMER__TM_EITHEREDGE 0x0Cu
#define SystemTimer__B_TIMER__TM_SOFTWARE 0x10u


/***************************************
*    Initialial Parameter Constants
***************************************/

#define SystemTimer_INIT_PERIOD             63u
#define SystemTimer_INIT_CAPTURE_MODE       ((uint8)((uint8)0u << SystemTimer_CTRL_CAP_MODE_SHIFT))
#define SystemTimer_INIT_TRIGGER_MODE       ((uint8)((uint8)0u << SystemTimer_CTRL_TRIG_MODE_SHIFT))
#if (SystemTimer_UsingFixedFunction)
    #define SystemTimer_INIT_INTERRUPT_MODE (((uint8)((uint8)1u << SystemTimer_STATUS_TC_INT_MASK_SHIFT)) | \
                                                  ((uint8)((uint8)0 << SystemTimer_STATUS_CAPTURE_INT_MASK_SHIFT)))
#else
    #define SystemTimer_INIT_INTERRUPT_MODE (((uint8)((uint8)1u << SystemTimer_STATUS_TC_INT_MASK_SHIFT)) | \
                                                 ((uint8)((uint8)0 << SystemTimer_STATUS_CAPTURE_INT_MASK_SHIFT)) | \
                                                 ((uint8)((uint8)0 << SystemTimer_STATUS_FIFOFULL_INT_MASK_SHIFT)))
#endif /* (SystemTimer_UsingFixedFunction) */
#define SystemTimer_INIT_CAPTURE_COUNT      (2u)
#define SystemTimer_INIT_INT_CAPTURE_COUNT  ((uint8)((uint8)(1u - 1u) << SystemTimer_CTRL_INTCNT_SHIFT))


/***************************************
*           Registers
***************************************/

#if (SystemTimer_UsingFixedFunction) /* Implementation Specific Registers and Register Constants */


    /***************************************
    *    Fixed Function Registers
    ***************************************/

    #define SystemTimer_STATUS         (*(reg8 *) SystemTimer_TimerHW__SR0 )
    /* In Fixed Function Block Status and Mask are the same register */
    #define SystemTimer_STATUS_MASK    (*(reg8 *) SystemTimer_TimerHW__SR0 )
    #define SystemTimer_CONTROL        (*(reg8 *) SystemTimer_TimerHW__CFG0)
    #define SystemTimer_CONTROL2       (*(reg8 *) SystemTimer_TimerHW__CFG1)
    #define SystemTimer_CONTROL2_PTR   ( (reg8 *) SystemTimer_TimerHW__CFG1)
    #define SystemTimer_RT1            (*(reg8 *) SystemTimer_TimerHW__RT1)
    #define SystemTimer_RT1_PTR        ( (reg8 *) SystemTimer_TimerHW__RT1)

    #if (CY_PSOC3 || CY_PSOC5LP)
        #define SystemTimer_CONTROL3       (*(reg8 *) SystemTimer_TimerHW__CFG2)
        #define SystemTimer_CONTROL3_PTR   ( (reg8 *) SystemTimer_TimerHW__CFG2)
    #endif /* (CY_PSOC3 || CY_PSOC5LP) */
    #define SystemTimer_GLOBAL_ENABLE  (*(reg8 *) SystemTimer_TimerHW__PM_ACT_CFG)
    #define SystemTimer_GLOBAL_STBY_ENABLE  (*(reg8 *) SystemTimer_TimerHW__PM_STBY_CFG)

    #define SystemTimer_CAPTURE_LSB         (* (reg16 *) SystemTimer_TimerHW__CAP0 )
    #define SystemTimer_CAPTURE_LSB_PTR       ((reg16 *) SystemTimer_TimerHW__CAP0 )
    #define SystemTimer_PERIOD_LSB          (* (reg16 *) SystemTimer_TimerHW__PER0 )
    #define SystemTimer_PERIOD_LSB_PTR        ((reg16 *) SystemTimer_TimerHW__PER0 )
    #define SystemTimer_COUNTER_LSB         (* (reg16 *) SystemTimer_TimerHW__CNT_CMP0 )
    #define SystemTimer_COUNTER_LSB_PTR       ((reg16 *) SystemTimer_TimerHW__CNT_CMP0 )


    /***************************************
    *    Register Constants
    ***************************************/

    /* Fixed Function Block Chosen */
    #define SystemTimer_BLOCK_EN_MASK                     SystemTimer_TimerHW__PM_ACT_MSK
    #define SystemTimer_BLOCK_STBY_EN_MASK                SystemTimer_TimerHW__PM_STBY_MSK

    /* Control Register Bit Locations */
    /* Interrupt Count - Not valid for Fixed Function Block */
    #define SystemTimer_CTRL_INTCNT_SHIFT                  0x00u
    /* Trigger Polarity - Not valid for Fixed Function Block */
    #define SystemTimer_CTRL_TRIG_MODE_SHIFT               0x00u
    /* Trigger Enable - Not valid for Fixed Function Block */
    #define SystemTimer_CTRL_TRIG_EN_SHIFT                 0x00u
    /* Capture Polarity - Not valid for Fixed Function Block */
    #define SystemTimer_CTRL_CAP_MODE_SHIFT                0x00u
    /* Timer Enable - As defined in Register Map, part of TMRX_CFG0 register */
    #define SystemTimer_CTRL_ENABLE_SHIFT                  0x00u

    /* Control Register Bit Masks */
    #define SystemTimer_CTRL_ENABLE                        ((uint8)((uint8)0x01u << SystemTimer_CTRL_ENABLE_SHIFT))

    /* Control2 Register Bit Masks */
    /* As defined in Register Map, Part of the TMRX_CFG1 register */
    #define SystemTimer_CTRL2_IRQ_SEL_SHIFT                 0x00u
    #define SystemTimer_CTRL2_IRQ_SEL                      ((uint8)((uint8)0x01u << SystemTimer_CTRL2_IRQ_SEL_SHIFT))

    #if (CY_PSOC5A)
        /* Use CFG1 Mode bits to set run mode */
        /* As defined by Verilog Implementation */
        #define SystemTimer_CTRL_MODE_SHIFT                 0x01u
        #define SystemTimer_CTRL_MODE_MASK                 ((uint8)((uint8)0x07u << SystemTimer_CTRL_MODE_SHIFT))
    #endif /* (CY_PSOC5A) */
    #if (CY_PSOC3 || CY_PSOC5LP)
        /* Control3 Register Bit Locations */
        #define SystemTimer_CTRL_RCOD_SHIFT        0x02u
        #define SystemTimer_CTRL_ENBL_SHIFT        0x00u
        #define SystemTimer_CTRL_MODE_SHIFT        0x00u

        /* Control3 Register Bit Masks */
        #define SystemTimer_CTRL_RCOD_MASK  ((uint8)((uint8)0x03u << SystemTimer_CTRL_RCOD_SHIFT)) /* ROD and COD bit masks */
        #define SystemTimer_CTRL_ENBL_MASK  ((uint8)((uint8)0x80u << SystemTimer_CTRL_ENBL_SHIFT)) /* HW_EN bit mask */
        #define SystemTimer_CTRL_MODE_MASK  ((uint8)((uint8)0x03u << SystemTimer_CTRL_MODE_SHIFT)) /* Run mode bit mask */

        #define SystemTimer_CTRL_RCOD       ((uint8)((uint8)0x03u << SystemTimer_CTRL_RCOD_SHIFT))
        #define SystemTimer_CTRL_ENBL       ((uint8)((uint8)0x80u << SystemTimer_CTRL_ENBL_SHIFT))
    #endif /* (CY_PSOC3 || CY_PSOC5LP) */

    /*RT1 Synch Constants: Applicable for PSoC3 and PSoC5LP */
    #define SystemTimer_RT1_SHIFT                       0x04u
    /* Sync TC and CMP bit masks */
    #define SystemTimer_RT1_MASK                        ((uint8)((uint8)0x03u << SystemTimer_RT1_SHIFT))
    #define SystemTimer_SYNC                            ((uint8)((uint8)0x03u << SystemTimer_RT1_SHIFT))
    #define SystemTimer_SYNCDSI_SHIFT                   0x00u
    /* Sync all DSI inputs with Mask  */
    #define SystemTimer_SYNCDSI_MASK                    ((uint8)((uint8)0x0Fu << SystemTimer_SYNCDSI_SHIFT))
    /* Sync all DSI inputs */
    #define SystemTimer_SYNCDSI_EN                      ((uint8)((uint8)0x0Fu << SystemTimer_SYNCDSI_SHIFT))

    #define SystemTimer_CTRL_MODE_PULSEWIDTH            ((uint8)((uint8)0x01u << SystemTimer_CTRL_MODE_SHIFT))
    #define SystemTimer_CTRL_MODE_PERIOD                ((uint8)((uint8)0x02u << SystemTimer_CTRL_MODE_SHIFT))
    #define SystemTimer_CTRL_MODE_CONTINUOUS            ((uint8)((uint8)0x00u << SystemTimer_CTRL_MODE_SHIFT))

    /* Status Register Bit Locations */
    /* As defined in Register Map, part of TMRX_SR0 register */
    #define SystemTimer_STATUS_TC_SHIFT                 0x07u
    /* As defined in Register Map, part of TMRX_SR0 register, Shared with Compare Status */
    #define SystemTimer_STATUS_CAPTURE_SHIFT            0x06u
    /* As defined in Register Map, part of TMRX_SR0 register */
    #define SystemTimer_STATUS_TC_INT_MASK_SHIFT        (SystemTimer_STATUS_TC_SHIFT - 0x04u)
    /* As defined in Register Map, part of TMRX_SR0 register, Shared with Compare Status */
    #define SystemTimer_STATUS_CAPTURE_INT_MASK_SHIFT   (SystemTimer_STATUS_CAPTURE_SHIFT - 0x04u)

    /* Status Register Bit Masks */
    #define SystemTimer_STATUS_TC                       ((uint8)((uint8)0x01u << SystemTimer_STATUS_TC_SHIFT))
    #define SystemTimer_STATUS_CAPTURE                  ((uint8)((uint8)0x01u << SystemTimer_STATUS_CAPTURE_SHIFT))
    /* Interrupt Enable Bit-Mask for interrupt on TC */
    #define SystemTimer_STATUS_TC_INT_MASK              ((uint8)((uint8)0x01u << SystemTimer_STATUS_TC_INT_MASK_SHIFT))
    /* Interrupt Enable Bit-Mask for interrupt on Capture */
    #define SystemTimer_STATUS_CAPTURE_INT_MASK         ((uint8)((uint8)0x01u << SystemTimer_STATUS_CAPTURE_INT_MASK_SHIFT))

#else   /* UDB Registers and Register Constants */


    /***************************************
    *           UDB Registers
    ***************************************/

    #define SystemTimer_STATUS              (* (reg8 *) SystemTimer_TimerUDB_rstSts_stsreg__STATUS_REG )
    #define SystemTimer_STATUS_MASK         (* (reg8 *) SystemTimer_TimerUDB_rstSts_stsreg__MASK_REG)
    #define SystemTimer_STATUS_AUX_CTRL     (* (reg8 *) SystemTimer_TimerUDB_rstSts_stsreg__STATUS_AUX_CTL_REG)
    #define SystemTimer_CONTROL             (* (reg8 *) SystemTimer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_REG )
    
    #if(SystemTimer_Resolution <= 8u) /* 8-bit Timer */
        #define SystemTimer_CAPTURE_LSB         (* (reg8 *) SystemTimer_TimerUDB_sT8_timerdp_u0__F0_REG )
        #define SystemTimer_CAPTURE_LSB_PTR       ((reg8 *) SystemTimer_TimerUDB_sT8_timerdp_u0__F0_REG )
        #define SystemTimer_PERIOD_LSB          (* (reg8 *) SystemTimer_TimerUDB_sT8_timerdp_u0__D0_REG )
        #define SystemTimer_PERIOD_LSB_PTR        ((reg8 *) SystemTimer_TimerUDB_sT8_timerdp_u0__D0_REG )
        #define SystemTimer_COUNTER_LSB         (* (reg8 *) SystemTimer_TimerUDB_sT8_timerdp_u0__A0_REG )
        #define SystemTimer_COUNTER_LSB_PTR       ((reg8 *) SystemTimer_TimerUDB_sT8_timerdp_u0__A0_REG )
    #elif(SystemTimer_Resolution <= 16u) /* 8-bit Timer */
        #if(CY_PSOC3) /* 8-bit addres space */
            #define SystemTimer_CAPTURE_LSB         (* (reg16 *) SystemTimer_TimerUDB_sT8_timerdp_u0__F0_REG )
            #define SystemTimer_CAPTURE_LSB_PTR       ((reg16 *) SystemTimer_TimerUDB_sT8_timerdp_u0__F0_REG )
            #define SystemTimer_PERIOD_LSB          (* (reg16 *) SystemTimer_TimerUDB_sT8_timerdp_u0__D0_REG )
            #define SystemTimer_PERIOD_LSB_PTR        ((reg16 *) SystemTimer_TimerUDB_sT8_timerdp_u0__D0_REG )
            #define SystemTimer_COUNTER_LSB         (* (reg16 *) SystemTimer_TimerUDB_sT8_timerdp_u0__A0_REG )
            #define SystemTimer_COUNTER_LSB_PTR       ((reg16 *) SystemTimer_TimerUDB_sT8_timerdp_u0__A0_REG )
        #else /* 16-bit address space */
            #define SystemTimer_CAPTURE_LSB         (* (reg16 *) SystemTimer_TimerUDB_sT8_timerdp_u0__16BIT_F0_REG )
            #define SystemTimer_CAPTURE_LSB_PTR       ((reg16 *) SystemTimer_TimerUDB_sT8_timerdp_u0__16BIT_F0_REG )
            #define SystemTimer_PERIOD_LSB          (* (reg16 *) SystemTimer_TimerUDB_sT8_timerdp_u0__16BIT_D0_REG )
            #define SystemTimer_PERIOD_LSB_PTR        ((reg16 *) SystemTimer_TimerUDB_sT8_timerdp_u0__16BIT_D0_REG )
            #define SystemTimer_COUNTER_LSB         (* (reg16 *) SystemTimer_TimerUDB_sT8_timerdp_u0__16BIT_A0_REG )
            #define SystemTimer_COUNTER_LSB_PTR       ((reg16 *) SystemTimer_TimerUDB_sT8_timerdp_u0__16BIT_A0_REG )
        #endif /* CY_PSOC3 */
    #elif(SystemTimer_Resolution <= 24u)/* 24-bit Timer */
        #define SystemTimer_CAPTURE_LSB         (* (reg32 *) SystemTimer_TimerUDB_sT8_timerdp_u0__F0_REG )
        #define SystemTimer_CAPTURE_LSB_PTR       ((reg32 *) SystemTimer_TimerUDB_sT8_timerdp_u0__F0_REG )
        #define SystemTimer_PERIOD_LSB          (* (reg32 *) SystemTimer_TimerUDB_sT8_timerdp_u0__D0_REG )
        #define SystemTimer_PERIOD_LSB_PTR        ((reg32 *) SystemTimer_TimerUDB_sT8_timerdp_u0__D0_REG )
        #define SystemTimer_COUNTER_LSB         (* (reg32 *) SystemTimer_TimerUDB_sT8_timerdp_u0__A0_REG )
        #define SystemTimer_COUNTER_LSB_PTR       ((reg32 *) SystemTimer_TimerUDB_sT8_timerdp_u0__A0_REG )
    #else /* 32-bit Timer */
        #if(CY_PSOC3 || CY_PSOC5) /* 8-bit address space */
            #define SystemTimer_CAPTURE_LSB         (* (reg32 *) SystemTimer_TimerUDB_sT8_timerdp_u0__F0_REG )
            #define SystemTimer_CAPTURE_LSB_PTR       ((reg32 *) SystemTimer_TimerUDB_sT8_timerdp_u0__F0_REG )
            #define SystemTimer_PERIOD_LSB          (* (reg32 *) SystemTimer_TimerUDB_sT8_timerdp_u0__D0_REG )
            #define SystemTimer_PERIOD_LSB_PTR        ((reg32 *) SystemTimer_TimerUDB_sT8_timerdp_u0__D0_REG )
            #define SystemTimer_COUNTER_LSB         (* (reg32 *) SystemTimer_TimerUDB_sT8_timerdp_u0__A0_REG )
            #define SystemTimer_COUNTER_LSB_PTR       ((reg32 *) SystemTimer_TimerUDB_sT8_timerdp_u0__A0_REG )
        #else /* 32-bit address space */
            #define SystemTimer_CAPTURE_LSB         (* (reg32 *) SystemTimer_TimerUDB_sT8_timerdp_u0__32BIT_F0_REG )
            #define SystemTimer_CAPTURE_LSB_PTR       ((reg32 *) SystemTimer_TimerUDB_sT8_timerdp_u0__32BIT_F0_REG )
            #define SystemTimer_PERIOD_LSB          (* (reg32 *) SystemTimer_TimerUDB_sT8_timerdp_u0__32BIT_D0_REG )
            #define SystemTimer_PERIOD_LSB_PTR        ((reg32 *) SystemTimer_TimerUDB_sT8_timerdp_u0__32BIT_D0_REG )
            #define SystemTimer_COUNTER_LSB         (* (reg32 *) SystemTimer_TimerUDB_sT8_timerdp_u0__32BIT_A0_REG )
            #define SystemTimer_COUNTER_LSB_PTR       ((reg32 *) SystemTimer_TimerUDB_sT8_timerdp_u0__32BIT_A0_REG )
        #endif /* CY_PSOC3 || CY_PSOC5 */ 
    #endif

    #define SystemTimer_COUNTER_LSB_PTR_8BIT       ((reg8 *) SystemTimer_TimerUDB_sT8_timerdp_u0__A0_REG )
    
    #if (SystemTimer_UsingHWCaptureCounter)
        #define SystemTimer_CAP_COUNT              (*(reg8 *) SystemTimer_TimerUDB_sCapCount_counter__PERIOD_REG )
        #define SystemTimer_CAP_COUNT_PTR          ( (reg8 *) SystemTimer_TimerUDB_sCapCount_counter__PERIOD_REG )
        #define SystemTimer_CAPTURE_COUNT_CTRL     (*(reg8 *) SystemTimer_TimerUDB_sCapCount_counter__CONTROL_AUX_CTL_REG )
        #define SystemTimer_CAPTURE_COUNT_CTRL_PTR ( (reg8 *) SystemTimer_TimerUDB_sCapCount_counter__CONTROL_AUX_CTL_REG )
    #endif /* (SystemTimer_UsingHWCaptureCounter) */


    /***************************************
    *       Register Constants
    ***************************************/

    /* Control Register Bit Locations */
    #define SystemTimer_CTRL_INTCNT_SHIFT              0x00u       /* As defined by Verilog Implementation */
    #define SystemTimer_CTRL_TRIG_MODE_SHIFT           0x02u       /* As defined by Verilog Implementation */
    #define SystemTimer_CTRL_TRIG_EN_SHIFT             0x04u       /* As defined by Verilog Implementation */
    #define SystemTimer_CTRL_CAP_MODE_SHIFT            0x05u       /* As defined by Verilog Implementation */
    #define SystemTimer_CTRL_ENABLE_SHIFT              0x07u       /* As defined by Verilog Implementation */

    /* Control Register Bit Masks */
    #define SystemTimer_CTRL_INTCNT_MASK               ((uint8)((uint8)0x03u << SystemTimer_CTRL_INTCNT_SHIFT))
    #define SystemTimer_CTRL_TRIG_MODE_MASK            ((uint8)((uint8)0x03u << SystemTimer_CTRL_TRIG_MODE_SHIFT))
    #define SystemTimer_CTRL_TRIG_EN                   ((uint8)((uint8)0x01u << SystemTimer_CTRL_TRIG_EN_SHIFT))
    #define SystemTimer_CTRL_CAP_MODE_MASK             ((uint8)((uint8)0x03u << SystemTimer_CTRL_CAP_MODE_SHIFT))
    #define SystemTimer_CTRL_ENABLE                    ((uint8)((uint8)0x01u << SystemTimer_CTRL_ENABLE_SHIFT))

    /* Bit Counter (7-bit) Control Register Bit Definitions */
    /* As defined by the Register map for the AUX Control Register */
    #define SystemTimer_CNTR_ENABLE                    0x20u

    /* Status Register Bit Locations */
    #define SystemTimer_STATUS_TC_SHIFT                0x00u  /* As defined by Verilog Implementation */
    #define SystemTimer_STATUS_CAPTURE_SHIFT           0x01u  /* As defined by Verilog Implementation */
    #define SystemTimer_STATUS_TC_INT_MASK_SHIFT       SystemTimer_STATUS_TC_SHIFT
    #define SystemTimer_STATUS_CAPTURE_INT_MASK_SHIFT  SystemTimer_STATUS_CAPTURE_SHIFT
    #define SystemTimer_STATUS_FIFOFULL_SHIFT          0x02u  /* As defined by Verilog Implementation */
    #define SystemTimer_STATUS_FIFONEMP_SHIFT          0x03u  /* As defined by Verilog Implementation */
    #define SystemTimer_STATUS_FIFOFULL_INT_MASK_SHIFT SystemTimer_STATUS_FIFOFULL_SHIFT

    /* Status Register Bit Masks */
    /* Sticky TC Event Bit-Mask */
    #define SystemTimer_STATUS_TC                      ((uint8)((uint8)0x01u << SystemTimer_STATUS_TC_SHIFT))
    /* Sticky Capture Event Bit-Mask */
    #define SystemTimer_STATUS_CAPTURE                 ((uint8)((uint8)0x01u << SystemTimer_STATUS_CAPTURE_SHIFT))
    /* Interrupt Enable Bit-Mask */
    #define SystemTimer_STATUS_TC_INT_MASK             ((uint8)((uint8)0x01u << SystemTimer_STATUS_TC_SHIFT))
    /* Interrupt Enable Bit-Mask */
    #define SystemTimer_STATUS_CAPTURE_INT_MASK        ((uint8)((uint8)0x01u << SystemTimer_STATUS_CAPTURE_SHIFT))
    /* NOT-Sticky FIFO Full Bit-Mask */
    #define SystemTimer_STATUS_FIFOFULL                ((uint8)((uint8)0x01u << SystemTimer_STATUS_FIFOFULL_SHIFT))
    /* NOT-Sticky FIFO Not Empty Bit-Mask */
    #define SystemTimer_STATUS_FIFONEMP                ((uint8)((uint8)0x01u << SystemTimer_STATUS_FIFONEMP_SHIFT))
    /* Interrupt Enable Bit-Mask */
    #define SystemTimer_STATUS_FIFOFULL_INT_MASK       ((uint8)((uint8)0x01u << SystemTimer_STATUS_FIFOFULL_SHIFT))

    #define SystemTimer_STATUS_ACTL_INT_EN             0x10u   /* As defined for the ACTL Register */

    /* Datapath Auxillary Control Register definitions */
    #define SystemTimer_AUX_CTRL_FIFO0_CLR             0x01u   /* As defined by Register map */
    #define SystemTimer_AUX_CTRL_FIFO1_CLR             0x02u   /* As defined by Register map */
    #define SystemTimer_AUX_CTRL_FIFO0_LVL             0x04u   /* As defined by Register map */
    #define SystemTimer_AUX_CTRL_FIFO1_LVL             0x08u   /* As defined by Register map */
    #define SystemTimer_STATUS_ACTL_INT_EN_MASK        0x10u   /* As defined for the ACTL Register */

#endif /* Implementation Specific Registers and Register Constants */

#endif  /* CY_Timer_v2_30_SystemTimer_H */


/* [] END OF FILE */
