/**
 * @file HwA_elu.h
 * @author Flagchip
 * @brief esLU hardware access layer
 * @version 2.0.0
 * @date 2024-08-20
 *
 * SDK Version: 2.6.0
 *

 * @copyright Copyright (c) 2020-2024 Flagchip Semiconductors Co., Ltd.
 *
 * @details
 */
/* ********************************************************************************
 *   Revision History:
 *
 *   Version     Date          Initials      CR#          Descriptions
 *   ---------   ----------    ------------  ----------   ---------------
 *   0.1.0      2023-12-15     Flagchip084   N/A          First version for FC7300
 *   2.0.0      2024-10-12     Flagchip084   N/A          Change version and release
 ******************************************************************************** */

#ifndef _HWA_ELU_H_
#define _HWA_ELU_H_

#include "device_header.h"

#if ELU_INSTANCE_COUNT > 0U

/**
 * @defgroup HwA_lu HwA_lu
 * @ingroup module_driver_lu
 * @{
 */

/********* Local typedef ************/
/** @brief LU LG instance */
typedef enum
{
    LU_LG_0 = 0U,
    LU_LG_1,
    LU_LG_2,
    LU_LG_3
} LU_LG_Type;

/** @brief LU AOI mode */
typedef enum
{
    LU_NO_BYPASS = 0U,
    LU_LUT0_BYPASS,
    LU_LUT1_BYPASS,
    LU_LUT0_LUT1_BYPASS
} LU_LG_BypassModeType;

/** @brief LU FF mode */
typedef enum
{
    LU_BYPASS_MODE0 = 0U,
    LU_RS_MODE,
    LU_TFF_MODE,
    LU_DFF_MODE,
    LU_JKFF_MODE,
    LU_LATCH_MODE,
    LU_NORMAL0_MODE,
    LU_NORMAL1_MODE
} LU_LG_ConfigModeType;

/** @brief LU Input(n) type */
typedef enum
{
    LU_INPUT_N_A = 0U,
    LU_INPUT_N_B,
    LU_INPUT_N_C,
    LU_INPUT_N_D
} LU_LG_InputNType;

typedef enum
{
    LU_INPUT_LU = 0U,
    LU_INPUT_DU_OUTA,
    LU_INPUT_DU_OUTB,
    LU_INPUT_DU_OUTC
} LU_InputDType;

typedef enum
{
    LU_OUTPUT_LG = 0U,
    LU_OUTPUT_DU_OUTA,
    LU_OUTPUT_DU_OUTB,
    LU_OUTPUT_DU_OUTC,
} LU_OutputDType;

typedef enum
{
    LU_PRESCALER_DIV_0 = 0,
    LU_PRESCALER_DIV_2,
    LU_PRESCALER_DIV_3,
    LU_PRESCALER_DIV_8,
    LU_PRESCALER_DIV_16,
    LU_PRESCALER_DIV_32,
    LU_PRESCALER_DIV_64,
    LU_PRESCALER_DIV_128
} LU_PrescalerType;

typedef enum
{
    LU_FLEX_SAMP_EVEN_EDGES = 0,  /** 00b - Sampling on even edges.*/
    LU_FLEX_SAMP_ODD_EDGES ,    /** 01b - Sampling on odd edges.*/
    LU_FLEX_SAMP_SEND_EVEN_EDGES,  /** 10b - Sending on even edges.*/
    LU_FLEX_SAMP_SEND_ODD_EDGES    /** 11b - Sending on odd edges.*/
} LU_FlexSampType;

typedef enum
{
    LU_OPC_NONE = 0,
    LU_OPC_INCR ,        /** 0001b - INCR.*/
    LU_OPC_DECR ,        /** 0010b - DECR.*/
    LU_OPC_INCR_WRAP ,   /** 0011b - INCR_Wrap.*/
    LU_OPC_DECR_WRAP ,   /** 0100b - DECR_Wrap.*/
    LU_OPC_INCR_DECR ,   /** 0101b - INCR_DECR.*/
    LU_OPC_INCR_DECR_WRAP ,  /** 0110b - INCR_DECR_Wrap.*/
    LU_OPC_INCR_WRAP_MODE1 ,  /** 0111b - INCR_Wrap_Mode1.*/
    LU_OPC_INCR_DECR_WRAP_MODE1 ,  /** 1000b - INCR_DECR_Wrap_Mode1.*/
    LU_OPC_SHIFT_IN_LEFT ,  /** 1001b - Shift In Left.*/
    LU_OPC_SHIFT_IN_RIGHT ,  /** 1010b - Shift In Right.*/
    LU_OPC_SHIFT_OUT_LEFT ,  /** 1011b - Shift Out Left.*/
    LU_OPC_SHIFT_OUT_RIGHT ,  /** 1100b - Shift Out Right.*/
    LU_OPC_FLEX,  /** 1101b - FLEX.*/
    LU_OPC_DATA_MATCH  /** 1110b - Data Match.*/
} LU_DU_OpcType;

typedef enum
{
    INPUTAMUX_VSS = 0,
    INPUTAMUX_VDD ,
    INPUTAMUX_LG0_LUT0_OUT ,
    INPUTAMUX_LG0_LUT1_OUT ,
    INPUTAMUX_LG1_LUT0_OUT ,
    INPUTAMUX_LG1_LUT1_OUT ,
    INPUTAMUX_LG2_LUT0_OUT ,
    INPUTAMUX_LG2_LUT1_OUT ,
    INPUTAMUX_LG3_LUT0_OUT ,
    INPUTAMUX_LG3_LUT1_OUT ,
    INPUTAMUX_LU_DATA_UNIT_OUTA ,
    INPUTAMUX_LU_DATA_UNIT_OUTB ,
    INPUTAMUX_LU_DATA_UNIT_OUTC 
} LU_DU_InputMuxType;

typedef enum
{
    LU_DU_CAPTURE_NONE = 0, /**< do not use capture*/
    LU_DU_CAPTURE_POS_EDGE ,
    LU_DU_CAPTURE_NEG_EDGE ,
    LU_DU_CAPTURE_BOTH_EDGE
}LU_DU_CaptureModeType;

/********* Local inline function ************/
/**
 * @brief Configure LU LG(n) configuration
 *
 * @param pLu LU instance
 * @param eLg LG instance
 * @param u32RegValue LUT register value
 */
LOCAL_INLINE void LU_HWA_ConfigCfg(LU_Type *pLu, LU_LG_Type eLg, uint32_t u32RegValue)
{
    pLu->LG[eLg].LG_CFG = u32RegValue;
}

/**
 * @brief Configure LU LG(n) configuration
 *
 * @param pLu LU instance
 * @param eLg LG instance
 * @param u32RegValue LUT0 register value
 */
LOCAL_INLINE void LU_HWA_SetConfigCfgLut0(LU_Type *pLu, LU_LG_Type eLg, uint32_t u32RegValue)
{
    pLu->LG[eLg].LG_CFG |= LU_LG_CFG_LUT0_CTRL(u32RegValue);
}

/**
 * @brief Configure LU LG(n) configuration
 *
 * @param pLu LU instance
 * @param eLg LG instance
 * @param u32RegValue LUT1 register value
 */
LOCAL_INLINE void LU_HWA_SetConfigCfgLut1(LU_Type *pLu, LU_LG_Type eLg, uint32_t u32RegValue)
{
    pLu->LG[eLg].LG_CFG |= LU_LG_CFG_LUT1_CTRL(u32RegValue);
}

/**
 * @brief Configure LU LG(n) contrl configuration
 *
 * @param pLu LU instance
 * @param eLg LG instance
 * @param u32RegValue CTRL register value
 */
LOCAL_INLINE void LU_HWA_ConfigCtrl(LU_Type *pLu, LU_LG_Type eLg, uint32_t u32RegValue)
{
    pLu->LG[eLg].LG_CTRL = u32RegValue;
}

/**
 * @brief Configure LU LG(n) filter configuration
 *
 * @param pLu LU instance
 * @param eLg LG instance
 * @param u32RegValue FILT register value
 */
LOCAL_INLINE void LU_HWA_ConfigFilter(LU_Type *pLu, LU_LG_Type eLg, uint32_t u32RegValue)
{
    pLu->LG[eLg].LG_FILT = u32RegValue;
}

/**
 * @brief Configures the DMA selection.
 *
 * @param pLu LU instance
 * @param eLg LG instance
 */
LOCAL_INLINE void LU_HWA_ConfigDmaSel(LU_Type *pLu, LU_LG_Type eLg)
{
    pLu->LG[eLg].LG_CTRL |= (uint32_t)LU_DU_CTRL_DMASEL_MASK;
}

/**
 * @brief  Configures the Interrupt selection.
 *
 * @param pLu LU instance
 * @param eLg LG instance
 */
LOCAL_INLINE void LU_HWA_ConfigIntSel(LU_Type *pLu, LU_LG_Type eLg)
{
    pLu->LG[eLg].LG_CTRL |= (uint32_t)LU_DU_CTRL_INTSEL_MASK;
}

/**
 * @brief Configures the input selection.
 *
 * @param pLu Pointer to the LU instance.
 * @param eLg LG instance.
 * @param eInput Input selection.
 */
LOCAL_INLINE void LU_HWA_ConfigInuptSelToA(LU_Type *pLu, LU_LG_Type eLg, LU_InputDType eInput)
{
    uint32_t u32TempRegValue = pLu->LG[eLg].LG_CTRL;
    pLu->LG[eLg].LG_CTRL = ((u32TempRegValue & ~(uint32_t)LU_LG_CTRL_INPUTASEL_MASK) | LU_LG_CTRL_INPUTASEL(eInput));
}

/**
 * @brief Configures the input selection.
 *
 * @param pLu Pointer to the LU instance.
 * @param eLg LG instance.
 * @param eInput Input selection.
 */
LOCAL_INLINE void LU_HWA_ConfigInuptSelToB(LU_Type *pLu, LU_LG_Type eLg, LU_InputDType eInput)
{
    uint32_t u32TempRegValue = pLu->LG[eLg].LG_CTRL;
    pLu->LG[eLg].LG_CTRL = ((u32TempRegValue & ~(uint32_t)LU_LG_CTRL_INPUTBSEL_MASK) | LU_LG_CTRL_INPUTBSEL(eInput));
}

/**
 * @brief  Configures the input selection.
 *
 * @param pLu Pointer to the LU instance.
 * @param eLg LG instance.
 * @param eInput Input selection.
 */
LOCAL_INLINE void LU_HWA_ConfigInuptSelToC(LU_Type *pLu, LU_LG_Type eLg, LU_InputDType eInput)
{
    uint32_t u32TempRegValue = pLu->LG[eLg].LG_CTRL;
    pLu->LG[eLg].LG_CTRL = ((u32TempRegValue & ~(uint32_t)LU_LG_CTRL_INPUTCSEL_MASK) | LU_LG_CTRL_INPUTCSEL(eInput));
}

/**
 * @brief Configures the input selection.
 *
 * @param pLu Pointer to the LU instance.
 * @param eLg LG instance.
 * @param eInput Input selection.
 */
LOCAL_INLINE void LU_HWA_ConfigInuptSelToD(LU_Type *pLu, LU_LG_Type eLg, LU_InputDType eInput)
{
    uint32_t u32TempRegValue = pLu->LG[eLg].LG_CTRL;
    pLu->LG[eLg].LG_CTRL = ((u32TempRegValue & ~(uint32_t)LU_LG_CTRL_INPUTDSEL_MASK) | LU_LG_CTRL_INPUTDSEL(eInput));
}

/**
 * @brief Set LG bypass control
 *
 * @param pLu LU instance
 * @param eLg LG instance
 * @param eMode LG bypass control mode
 */
LOCAL_INLINE void LU_HWA_SetLgBypassControl(LU_Type *pLu, LU_LG_Type eLg, LU_LG_BypassModeType eMode)
{
    uint32_t u32TempRegValue = pLu->LG[eLg].LG_CTRL;
    pLu->LG[eLg].LG_CTRL = ((u32TempRegValue & ~(uint32_t)LU_LG_CTRL_BYPASS_MASK) | LU_LG_CTRL_BYPASS(eMode));
}

/**
 * @brief Set LG inputs synchronous control
 *
 * @param pLu LU instance
 * @param eLg LG instance
 * @param u32Value LG input bit,0-3 bit indicate INPUT(n)A/INPUT(n)B/INPUT(n)C/INPUT(n)D
 */
LOCAL_INLINE void LU_HWA_SetLgInputsSyncCtrl(LU_Type *pLu, LU_LG_Type eLg, uint32_t u32Value)
{
    uint32_t u32TempRegValue = pLu->LG[eLg].LG_CTRL;
    pLu->LG[eLg].LG_CTRL = ((u32TempRegValue & ~(uint32_t)LU_LG_CTRL_SYNC_MASK) | LU_LG_CTRL_SYNC(u32Value));
}

/**
 * @brief Set LG output feedback override control
 *
 * @param pLu LU instance
 * @param eLg LG instance
 * @param eInput Feedback to LG input
 */
LOCAL_INLINE void LU_HWA_SetLgFeedbackOverrideCtrl(LU_Type *pLu, LU_LG_Type eLg, LU_LG_InputNType eInput)
{
    uint32_t u32TempRegValue = pLu->LG[eLg].LG_CTRL;
    pLu->LG[eLg].LG_CTRL = ((u32TempRegValue & ~(uint32_t)LU_LG_CTRL_FB_OVRD_MASK) | LU_LG_CTRL_FB_OVRD(eInput));
}

/**
 * @brief Set LG Flip-Flop mode
 *
 * @param pLu LU instance
 * @param eLg LG instance
 * @param eMode Flip-Flop mode
 */
LOCAL_INLINE void LU_HWA_SetLgFlipFlopMode(LU_Type *pLu, LU_LG_Type eLg, LU_LG_ConfigModeType eMode)
{
    uint32_t u32TempRegValue = pLu->LG[eLg].LG_CTRL;
    pLu->LG[eLg].LG_CTRL = ((u32TempRegValue & ~(uint32_t)LU_LG_CTRL_MOD_MASK) | LU_LG_CTRL_MOD(eMode));
}

/**
 * @brief Generate enable pulse
 *
 * @param pLu LU instance
 * @param eLg LG instance
 */
LOCAL_INLINE void LU_HWA_EnableControlFlipFlopInitOutput(LU_Type *pLu, LU_LG_Type eLg)
{
    pLu->LG[eLg].LG_CTRL |= (uint32_t)LU_LG_CTRL_INIT_EN_MASK;
}

/**
 * @brief Configure the output of flip-flop as "1"
 *
 * @param pLu LU instance
 * @param eLg LG instance
 */
LOCAL_INLINE void LU_HWA_ConfigFlipFlopTo1(LU_Type *pLu, LU_LG_Type eLg)
{
    pLu->LG[eLg].LG_CTRL |= (uint32_t)LU_LG_CTRL_FF_INIT_MASK;
}

/**
 * @brief Configure the output of flip-flop as "0"
 *
 * @param pLu LU instance
 * @param eLg LG instance
 */
LOCAL_INLINE void LU_HWA_ConfigFlipFlopTo0(LU_Type *pLu, LU_LG_Type eLg)
{
    pLu->LG[eLg].LG_CTRL &= ~(uint32_t)LU_LG_CTRL_FF_INIT_MASK;
}

/**
 * @brief Input filter sample count for LUT0
 *
 * @param pLu LU instance
 * @param eLg LG instance
 * @param u32Value Sample count value
 */
LOCAL_INLINE void LU_HWA_SetLUT0InputFilterSampleCount(LU_Type *pLu, LU_LG_Type eLg, uint32_t u32Value)
{
    uint32_t u32TempRegValue = pLu->LG[eLg].LG_FILT;
    pLu->LG[eLg].LG_FILT = ((u32TempRegValue & ~(uint32_t)LU_LG_FILT_CNT0_MASK) | LU_LG_FILT_CNT0(u32Value));
}

/**
 * @brief Input filter sample period for LUT0
 *
 * @param pLu LU instance
 * @param eLg LG instance
 * @param u32Value Sample period value
 */
LOCAL_INLINE void LU_HWA_SetLUT0InputFilterSamplePeriod(LU_Type *pLu, LU_LG_Type eLg, uint32_t u32Value)
{
    uint32_t u32TempRegValue = pLu->LG[eLg].LG_FILT;
    pLu->LG[eLg].LG_FILT = ((u32TempRegValue & ~(uint32_t)LU_LG_FILT_PRE0_MASK) | LU_LG_FILT_PRE0(u32Value));
}

/**
 * @brief Input filter sample count for LUT1
 *
 * @param pLu LU instance
 * @param eLg LG instance
 * @param u32Value Sample count value
 */
LOCAL_INLINE void LU_HWA_SetLUT1InputFilterSampleCount(LU_Type *pLu, LU_LG_Type eLg, uint32_t u32Value)
{
    uint32_t u32TempRegValue = pLu->LG[eLg].LG_FILT;
    pLu->LG[eLg].LG_FILT = ((u32TempRegValue & ~(uint32_t)LU_LG_FILT_CNT1_MASK) | LU_LG_FILT_CNT1(u32Value));
}

/**
 * @brief Input filter sample period for LUT1
 *
 * @param pLu LU instance
 * @param eLg LG instance
 * @param u32Value Sample period value
 */
LOCAL_INLINE void LU_HWA_SetLUT1InputFilterSamplePeriod(LU_Type *pLu, LU_LG_Type eLg, uint32_t u32Value)
{
    uint32_t u32TempRegValue = pLu->LG[eLg].LG_FILT;
    pLu->LG[eLg].LG_FILT = ((u32TempRegValue & ~(uint32_t)LU_LG_FILT_PRE1_MASK) | LU_LG_FILT_PRE1(u32Value));
}

/**
 * @brief Input filter sample period for LUT1
 *
 * @param pLu LU instance
 * @param eLg LG instance
 * @param u32Value Sample period value
 */
LOCAL_INLINE void LU_HWA_SetControlPrescaler(LU_Type *pLu, LU_PrescalerType ePrescaler)
{
    pLu->CTRL |= LU_CTRL_PS(ePrescaler);
}

/**
 * @brief Input filter sample period for LUT1
 *
 * @param pLu LU instance
 * @param eLg LG instance
 * @param u32Value Sample period value
 */
LOCAL_INLINE void LU_HWA_SetIntStatus(LU_Type *pLu, uint32_t u32W1cFlag)
{
    pLu->INT_ST |= LU_INT_ST_LUTINTST(u32W1cFlag);
}

/**
 * @brief Input filter sample period for LUT1
 *
 * @param pLu LU instance
 * @param eLg LG instance
 * @param u32Value Sample period value
 */
LOCAL_INLINE uint32_t LU_HWA_GetIntStatus(LU_Type *pLu)
{
    return (pLu->INT_ST & LU_INT_ST_LUTINTST_MASK);
}

/**
 * @brief Input filter sample period for LUT1
 *
 * @param pLu LU instance
 * @param eLg LG instance
 * @param u32Value Sample period value
 */
LOCAL_INLINE void LU_HWA_SetConfigCfg(LU_Type *pLu, uint32_t u32RegValue)
{
    pLu->CFG = u32RegValue;
}

/**
 * @brief Input filter sample period for LUT1
 *
 * @param pLu LU instance
 */
LOCAL_INLINE void LU_HWA_EnableCofigCfgInt(LU_Type *pLu)
{
    pLu->CFG |= LU_CFG_INTEN_MASK;
}

/**
 * @brief Input filter sample period for LUT1
 *
 * @param pLu LU instance
 */
LOCAL_INLINE void LU_HWA_DisableCofigCfgInt(LU_Type *pLu)
{
    pLu->CFG &= ~LU_CFG_INTEN_MASK;
}

/**
 * @brief Input filter sample period for LUT1
 *
 * @param pLu LU instance
 */
LOCAL_INLINE void LU_HWA_SoftReset(LU_Type *pLu)
{
    pLu->SW_RESET = 0xFC50AF50;
}

/**
 * @brief Sets the configuration of the Data Unit Control Register
 *
 * @param pLu Pointer to the LU_Type instance
 * @param u32RegValue The value to be written to the DU_CFG register
 */
LOCAL_INLINE void LU_HWA_SetConfigDuCfg(LU_Type *pLu, uint32_t u32RegValue)
{
    pLu->DU_CFG = u32RegValue;
}

/**
 * @brief Sets the configuration of the Data Unit Control Register
 *
 * @param pLu Pointer to the LU_Type instance
 * @param u32RegValue The value to be written to the DU_CTRL register
 */
LOCAL_INLINE void LU_HWA_SetConfigDuCTRL(LU_Type *pLu, uint32_t u32RegValue)
{
    pLu->DU_CTRL = u32RegValue;
}

/**
 * @brief Enables the FlexMode Data Compare feature
 *
 * @param pLu Pointer to the LU_Type instance
 */
LOCAL_INLINE void LU_HWA_EnableDuCtrlComp(LU_Type *pLu)
{
    pLu->DU_CTRL |= LU_DU_CTRL_COMP_MASK;
}

/**
 * @brief Disables the FlexMode Data Compare feature
 *
 * @param pLu Pointer to the LU_Type instance
 */
LOCAL_INLINE void LU_HWA_DisableDuCtrlComp(LU_Type *pLu)
{
    pLu->DU_CTRL &= ~LU_DU_CTRL_COMP_MASK;
}

/**
 * @brief Enables the Continuous Mode
 *
 * @param pLu Pointer to the LU_Type instance
 */
LOCAL_INLINE void LU_HWA_EnableDuCfgCone(LU_Type *pLu)
{
    pLu->DU_CFG |= LU_DU_CTRL_CONEN_MASK;
}

/**
 * @brief Disables the Continuous Mode
 *
 * @param pLu Pointer to the LU_Type instance
 */
LOCAL_INLINE void LU_HWA_DisableDuCfgCone(LU_Type *pLu)
{
    pLu->DU_CFG &= ~LU_DU_CTRL_CONEN_MASK;
}

/**
 * @brief Enables the Capture Mode
 *
 * @param pLu Pointer to the LU_Type instance
 */
LOCAL_INLINE void LU_HWA_ConfigDuCtrlCapture(LU_Type *pLu, LU_DU_CaptureModeType eCaptureCfg)
{
    pLu->DU_CTRL |= LU_DU_CTRL_CAPMODE(eCaptureCfg);
}

/**
 * @brief Enables the DMA Selection feature
 *
 * @param pLu Pointer to the LU_Type instance
 */
LOCAL_INLINE void LU_HWA_EnableDuCtrlDma(LU_Type *pLu)
{
    pLu->DU_CTRL |= LU_DU_CTRL_DMASEL_MASK;
}

/**
 * @brief Disables the DMA Selection feature
 *
 * @param pLu Pointer to the LU_Type instance
 */
LOCAL_INLINE void LU_HWA_DisableDuCtrlDma(LU_Type *pLu)
{
    pLu->DU_CTRL &= ~LU_DU_CTRL_DMASEL_MASK;
}

/**
 * @brief Enables the Interrupt Selection feature
 *
 * @param pLu Pointer to the LU_Type instance
 */
LOCAL_INLINE void LU_HWA_EnableDuCtrlInt(LU_Type *pLu)
{
    pLu->DU_CTRL |= LU_DU_CTRL_INTSEL_MASK;
}

/**
 * @brief Disables the Interrupt Selection feature
 *
 * @param pLu Pointer to the LU_Type instance
 */
LOCAL_INLINE void LU_HWA_DisableDuCtrlInt(LU_Type *pLu)
{
    pLu->DU_CTRL &= ~LU_DU_CTRL_INTSEL_MASK;
}

/**
 * @brief Sets the OUTC Initial Polarity to low valid
 *
 * @param pLu Pointer to the LU_Type instance
 */
LOCAL_INLINE void LU_HWA_SetDuCfgOutLow(LU_Type *pLu)
{
    pLu->DU_CFG |= LU_DU_CTRL_OUTCINIT_MASK;
}

/**
 * @brief Sets the OUTC Initial Polarity to high valid
 *
 * @param pLu Pointer to the LU_Type instance
 */
LOCAL_INLINE void LU_HWA_SetDuCfgOutCHigh(LU_Type *pLu)
{
    pLu->DU_CFG &= ~LU_DU_CTRL_OUTCINIT_MASK;
}

/**
 * @brief Enables the Initial Sample feature
 *
 * @param pLu Pointer to the LU_Type instance
 */
LOCAL_INLINE void LU_HWA_EnableDuCfgInitSamp(LU_Type *pLu)
{
    pLu->DU_CFG |= LU_DU_CTRL_SAMPINIT_MASK;
}

/**
 * @brief Disables the Initial Sample feature
 *
 * @param pLu Pointer to the LU_Type instance
 */
LOCAL_INLINE void LU_HWA_DisableDuCfgInitSamp(LU_Type *pLu)
{
    pLu->DU_CFG &= ~LU_DU_CTRL_SAMPINIT_MASK;
}

/**
 * @brief Enables the Initial Shift Out feature
 *
 * @param pLu Pointer to the LU_Type instance
 */
LOCAL_INLINE void LU_HWA_EnableDuCfgInitShift(LU_Type *pLu)
{
    pLu->DU_CFG |= LU_DU_CTRL_SHIFTOUTINIT_MASK;
}

/**
 * @brief Disables the Initial Shift Out feature
 *
 * @param pLu Pointer to the LU_Type instance
 */
LOCAL_INLINE void LU_HWA_DisableDuCfgInitShift(LU_Type *pLu)
{
    pLu->DU_CFG &= ~LU_DU_CTRL_SHIFTOUTINIT_MASK;
}

/**
 * @brief Sets the Compare Type to Equal compare
 *
 * @param pLu Pointer to the LU_Type instance
 */
LOCAL_INLINE void LU_HWA_SetDuCfgCompEqual(LU_Type *pLu)
{
    pLu->DU_CFG |= LU_DU_CTRL_COMPTYPE_MASK;
}

/**
 * @brief Sets the Compare Type to Toggle compare
 *
 * @param pLu Pointer to the LU_Type instance
 */
LOCAL_INLINE void LU_HWA_SetDuCfgCompToggle(LU_Type *pLu)
{
    pLu->DU_CFG &= ~LU_DU_CTRL_COMPTYPE_MASK;
}

/**
 * @brief Sets the Compare Size
 *
 * @param pLu Pointer to the LU_Type instance
 * @param u32Value The size to be set (1-32 bits)
 */
LOCAL_INLINE void LU_HWA_SetDuCfgCompSize(LU_Type *pLu, uint32_t u32Value)
{
    pLu->DU_CFG |= LU_DU_CTRL_COMPSIZE(u32Value);
}

/**
 * @brief Sets the Input Trigger Mode
 *
 * @param pLu Pointer to the LU_Type instance
 * @param u32Value The trigger mode value to be set
 */
LOCAL_INLINE void LU_HWA_SetDuCfgInTrigerMode(LU_Type *pLu, uint32_t u32Value)
{
    pLu->DU_CFG |= LU_DU_CTRL_INPUTTRIG(u32Value);
}

/**
 * @brief Sets the Multi Pin Compare Type to All pin meet
 *
 * @param pLu Pointer to the LU_Type instance
 * @param u32Value The value to be set for the COMPTOGTYPE field
 */
LOCAL_INLINE void LU_HWA_SetDuCfgCompPinAll(LU_Type *pLu, uint32_t u32Value)
{
    (void)u32Value;
    pLu->DU_CFG |= LU_DU_CTRL_COMPTYPE_MASK;
}

/**
 * @brief Sets the Multi Pin Compare Type to Any pin meet
 *
 * @param pLu Pointer to the LU_Type instance
 * @param u32Value The value to be set for the COMPTOGTYPE field
 */
LOCAL_INLINE void LU_HWA_SetDuCfgCompPinAny(LU_Type *pLu, uint32_t u32Value)
{
    (void)u32Value;
    pLu->DU_CFG &= ~LU_DU_CTRL_COMPTYPE_MASK;
}

/**
 * @brief Enables Both Edge Mode
 *
 * @param pLu Pointer to the LU_Type instance
 */
LOCAL_INLINE void LU_HWA_EnableDuCfgEdge(LU_Type *pLu)
{
    pLu->DU_CFG |= LU_DU_CTRL_EDGEMODE_MASK;
}

/**
 * @brief Disables Both Edge Mode
 *
 * @param pLu Pointer to the LU_Type instance
 */
LOCAL_INLINE void LU_HWA_DisableDuCfgEdge(LU_Type *pLu)
{
    pLu->DU_CFG &= ~LU_DU_CTRL_EDGEMODE_MASK;
}

/**
 * @brief Sets the Sample Control in Flex Mode
 *
 * @param pLu Pointer to the LU_Type instance
 * @param u32Value The value to be set for the FLEX_SAMP field
 */
LOCAL_INLINE void LU_HWA_SetDuCfgFlexSamp(LU_Type *pLu, LU_FlexSampType eFlexSampValue)
{
    pLu->DU_CFG |= LU_DU_CTRL_FLEX_SAMP(eFlexSampValue);
}

/**
 * @brief Sets the Clock Initial Polarity to high
 *
 * @param pLu Pointer to the LU_Type instance
 * @param u32Value The value to be set for the CLKINIT field
 */
LOCAL_INLINE void LU_HWA_SetDuCfgClkHigh(LU_Type *pLu, uint32_t u32Value)
{
    pLu->DU_CFG |= LU_DU_CTRL_CLKINIT(u32Value);
}

/**
 * @brief Sets the Clock Initial Polarity to low
 *
 * @param pLu Pointer to the LU_Type instance
 * @param u32Value The value to be set for the CLKINIT field
 */
LOCAL_INLINE void LU_HWA_SetDuCfgClkLow(LU_Type *pLu, uint32_t u32Value)
{
    pLu->DU_CFG &= ~LU_DU_CTRL_CLKINIT(u32Value);
}

/**
 * @brief Sets the LU Data Unit Operation Code
 *
 * @param pLu Pointer to the LU_Type instance
 * @param u32Value The value to be set for the OPC field
 */
LOCAL_INLINE void LU_HWA_SetDuCfgOpc(LU_Type *pLu, LU_DU_OpcType eOpcValue)
{
    // Note: There seems to be an error in the original code, it should use LU_DU_CTRL_OPC_MASK instead of LU_DU_CTRL_FLEX_SAMP(u32Value)
    pLu->DU_CFG |= LU_DU_CTRL_OPC(eOpcValue);
}

/**
 * @brief Sets the INPUTAMUX selection
 *
 * @param pLu Pointer to the LU_Type instance
 * @param sel The selection for INPUTAMUX
 */
LOCAL_INLINE void LU_HWA_SetInputAmux(LU_Type *pLu, LU_DU_InputMuxType eInputMuxSel)
{
    pLu->DU_INPUT_SEL |= LU_DU_INPUT_SEL_INPUTAMUX(eInputMuxSel);
}

/**
 * @brief Sets the INPUTBMUX selection (same as INPUTAMUX)
 *
 * @param pLu Pointer to the LU_Type instance
 * @param sel The selection for INPUTBMUX
 */
LOCAL_INLINE void LU_HWA_SetInputBmux(LU_Type *pLu, LU_DU_InputMuxType eInputMuxSel)
{
    pLu->DU_INPUT_SEL |= LU_DU_INPUT_SEL_INPUTBMUX(eInputMuxSel);
}

/**
 * @brief Sets the INPUTCMUX selection (same as INPUTAMUX)
 *
 * @param pLu Pointer to the LU_Type instance
 * @param sel The selection for INPUTCMUX
 */
LOCAL_INLINE void LU_HWA_SetInputCmux(LU_Type *pLu, LU_DU_InputMuxType eInputMuxSel)
{
    pLu->DU_INPUT_SEL |= LU_DU_INPUT_SEL_INPUTCMUX(eInputMuxSel);
}

/**
 * @brief Clears the buffer
 *
 * @param pLu Pointer to the LU_Type instance
 */
LOCAL_INLINE void LU_HWA_ClearBuffer(LU_Type *pLu)
{
    pLu->DU_CFG |= LU_DU_CFG_BUFFERCLR_MASK;
}

/**
 * @brief Disables buffer clearing
 *
 * @param pLu Pointer to the LU_Type instance
 */
LOCAL_INLINE void LU_HWA_DisableBufferClear(LU_Type *pLu)
{
    pLu->DU_CFG &= ~LU_DU_CFG_BUFFERCLR_MASK;
}

/**
 * @brief Enables Interrupt Match
 *
 * @param pLu Pointer to the LU_Type instance
 */
LOCAL_INLINE void LU_HWA_EnableInterruptMatch(LU_Type *pLu)
{
    pLu->DU_CFG |= LU_DU_CFG_INTMATCH_MASK;
}

/**
 * @brief Disables Interrupt Match
 *
 * @param pLu Pointer to the LU_Type instance
 */
LOCAL_INLINE void LU_HWA_DisableInterruptMatch(LU_Type *pLu)
{
    pLu->DU_CFG &= ~LU_DU_CFG_INTMATCH_MASK;
}

/**
 * @brief Enables Interrupt Underflow
 *
 * @param pLu Pointer to the LU_Type instance
 */
LOCAL_INLINE void LU_HWA_EnableInterruptUnderflow(LU_Type *pLu)
{
    pLu->DU_CFG |= LU_DU_CFG_INTUNDERFLOW_MASK;
}

/**
 * @brief Disables Interrupt Underflow
 *
 * @param pLu Pointer to the LU_Type instance
 */
LOCAL_INLINE void LU_HWA_DisableInterruptUnderflow(LU_Type *pLu)
{
    pLu->DU_CFG &= ~LU_DU_CFG_INTUNDERFLOW_MASK;
}

/**
 * @brief Enables Interrupt Overflow
 *
 * @param pLu Pointer to the LU_Type instance
 */
LOCAL_INLINE void LU_HWA_EnableInterruptOverflow(LU_Type *pLu)
{
    pLu->DU_CFG |= LU_DU_CFG_INTOVERFLOW_MASK;
}

/**
 * @brief Disables Interrupt Overflow
 *
 * @param pLu Pointer to the LU_Type instance
 */
LOCAL_INLINE void LU_HWA_DisableInterruptOverflow(LU_Type *pLu)
{
    pLu->DU_CFG &= ~LU_DU_CFG_INTOVERFLOW_MASK;
}

/**
 * @brief Enables DMA Match
 *
 * @param pLu Pointer to the LU_Type instance
 */
LOCAL_INLINE void LU_HWA_EnableDmaMatch(LU_Type *pLu)
{
    pLu->DU_CFG |= LU_DU_CFG_DMAMATCH_MASK;
}

/**
 * @brief Disables DMA Match
 *
 * @param pLu Pointer to the LU_Type instance
 */
LOCAL_INLINE void LU_HWA_DisableDmaMatch(LU_Type *pLu)
{
    pLu->DU_CFG &= ~LU_DU_CFG_DMAMATCH_MASK;
}

/**
 * @brief Enables DMA Underflow
 *
 * @param pLu Pointer to the LU_Type instance
 */
LOCAL_INLINE void LU_HWA_EnableDmaUnderflow(LU_Type *pLu)
{
    pLu->DU_CFG |= LU_DU_CFG_DMAUNDERFLOW_MASK;
}

/**
 * @brief Disables DMA Underflow
 *
 * @param pLu Pointer to the LU_Type instance
 */
LOCAL_INLINE void LU_HWA_DisableDmaUnderflow(LU_Type *pLu)
{
    pLu->DU_CFG &= ~LU_DU_CFG_DMAUNDERFLOW_MASK;
}

/**
 * @brief Enables DMA Overflow
 *
 * @param pLu Pointer to the LU_Type instance
 */
LOCAL_INLINE void LU_HWA_EnableDmaOverflow(LU_Type *pLu)
{
    pLu->DU_CFG |= LU_DU_CFG_DMAOVERFLOW_MASK;
}

/**
 * @brief Disables DMA Overflow
 *
 * @param pLu Pointer to the LU_Type instance
 */
LOCAL_INLINE void LU_HWA_DisableDmaOverflow(LU_Type *pLu)
{
    pLu->DU_CFG &= ~LU_DU_CFG_DMAOVERFLOW_MASK;
}

/**
 * @brief Sets the Start Counter Config
 *
 * @param pLu Pointer to the LU_Type instance
 * @param config The configuration value for the start counter
 */
LOCAL_INLINE void LU_HWA_SetStartCounterConfig(LU_Type *pLu, uint8_t config)
{
    pLu->DU_CFG = (pLu->DU_CFG & ~LU_DU_CFG_STARTCFG_MASK) | LU_DU_CFG_STARTCFG(config);
}

/**
 * @brief Sets the Transmit Bit Number
 *
 * @param pLu Pointer to the LU_Type instance
 * @param bitNumber The bit number to be transmitted
 */
LOCAL_INLINE void LU_HWA_SetTransmitBitNumber(LU_Type *pLu, uint8_t bitNumber)
{
    pLu->DU_CFG = (pLu->DU_CFG & ~LU_DU_CFG_BITCFG_MASK) | LU_DU_CFG_BITCFG(bitNumber);
}

/**
 * @brief Sets the value of the Data Unit Data0 Register
 *
 * @param pLu Pointer to the LU_Type instance
 * @param data The value to be written to the DATA0 register
 */
LOCAL_INLINE void LU_HWA_SetLuDuData0(LU_Type *pLu, uint32_t data)
{
    pLu->DU_DATA0 = data;
}

/**
 * @brief Gets the value of the Data Unit Data0 Register
 *
 * @param pLu Pointer to the LU_Type instance
 * @return The value of the DATA0 register
 */
LOCAL_INLINE uint32_t LU_HWA_GetLuDuData0(LU_Type *pLu)
{
    return pLu->DU_DATA0;
}

/**
 * @brief Sets the value of the Data Unit Data1 Register
 *
 * @param pLu Pointer to the LU_Type instance
 * @param data The value to be written to the DATA1 register
 */
LOCAL_INLINE void LU_HWA_SetLuDuData1(LU_Type *pLu, uint32_t data)
{
    pLu->DU_DATA1 = data;
}

/**
 * @brief Gets the value of the Data Unit Data1 Register
 *
 * @param pLu Pointer to the LU_Type instance
 * @return The value of the DATA1 register
 */
LOCAL_INLINE uint32_t LU_HWA_GetLuDuData1(LU_Type *pLu)
{
    return pLu->DU_DATA1;
}

/**
 * @brief Sets the value of the Data Unit Data2 Register
 *
 * @param pLu Pointer to the LU_Type instance
 * @param data The value to be written to the DATA2 register
 */
LOCAL_INLINE void LU_HWA_SetLuDuData2(LU_Type *pLu, uint32_t data)
{
    pLu->DU_DATA2 = data;
}

/**
 * @brief Gets the value of the Data Unit Data2 Register
 *
 * @param pLu Pointer to the LU_Type instance
 * @return The value of the DATA2 register
 */
LOCAL_INLINE uint32_t LU_HWA_GetLuDuData2(LU_Type *pLu)
{
    return pLu->DU_DATA2;
}

/**
 * @brief Gets the value of the Data Unit Data3 Register
 *
 * @param pLu Pointer to the LU_Type instance
 * @return The value of the DATA3 register
 */
LOCAL_INLINE uint32_t LU_HWA_GetLuDuData3(LU_Type *pLu)
{
    return pLu->DU_DATA3;
}

/**
 * @brief Gets the value of the Data Unit Data4 Register
 *
 * @param pLu Pointer to the LU_Type instance
 * @return The value of the DATA4 register
 */
LOCAL_INLINE uint32_t LU_HWA_GetLuDuData4(LU_Type *pLu)
{
    return pLu->DU_DATA4;
}

/**
 * @brief Gets the value of the Data Unit Data5 Register
 *
 * @param pLu Pointer to the LU_Type instance
 * @return The value of the DATA5 register
 */
LOCAL_INLINE uint32_t LU_HWA_GetLuDuData5(LU_Type *pLu)
{
    return pLu->DU_DATA5;
}

/**
 * @brief Gets the value of the Data Unit Data6 Register
 *
 * @param pLu Pointer to the LU_Type instance
 * @return The value of the DATA6 register
 */
LOCAL_INLINE uint32_t LU_HWA_GetLuDuData6(LU_Type *pLu)
{
    return pLu->DU_DATA6;
}

/**
 * @brief Sets the value of the Data Unit Data7 Register
 *
 * @param pLu Pointer to the LU_Type instance
 * @param data The value to be written to the DATA7 register
 */
LOCAL_INLINE void LU_HWA_SetLuDuData7(LU_Type *pLu, uint32_t data)
{
    pLu->DU_DATA7 = data;
}

/**
 * @brief Gets the value of the Data Unit Data7 Register
 *
 * @param pLu Pointer to the LU_Type instance
 * @return The value of the DATA7 register
 */
LOCAL_INLINE uint32_t LU_HWA_GetLuDuData7(LU_Type *pLu)
{
    return pLu->DU_DATA7;
}

/** @}*/


#endif /* #if ELU_INSTANCE_COUNT > 0U */

#endif /* #ifndef _HWA_LU_H_ */
