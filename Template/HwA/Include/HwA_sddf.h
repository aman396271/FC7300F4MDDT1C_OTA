/**
 * @file HwA_sddf.h
 * @author Flagchip
 * @brief Hardware access layer for SDDF
 * @version 2.0.0
 * @date 2024-08-20
 *
 * SDK Version: 2.6.0
 *

 * @copyright Copyright (c) 2020-2024 Flagchip Semiconductors Co., Ltd.
 *
 */
/* ********************************************************************************
   *   Revision History:
   *
   *   Version     Date          Initials      CR#          Descriptions
   *   ---------   ----------    ------------  ----------   ---------------
   *   0.1.0      2023-12-15     Flagchip030   N/A          First version for FC7300
   *   2.0.0      2024-10-12     Flagchip030   N/A          Change version and release
   ******************************************************************************** */

#ifndef _HWA_SDDF_H_
#define _HWA_SDDF_H_

#include "device_header.h"

#if SDDF_INSTANCE_COUNT > 0U

/**
 * @defgroup HwA_sddf HwA_sddf
 * @ingroup module_driver_sddf
 * @{
 */

/**
 * @brief Select the SDDF function clock pre-divider ratio
 *
 */
typedef enum
{
    SDDF_PREDIV_1 = 0U, /**< The clock is pre-diveded by 1 */
    SDDF_PREDIV_2 = 1U, /**< The clock is pre-diveded by 2 */
    SDDF_PREDIV_4 = 2U, /**< The clock is pre-diveded by 4 */
    SDDF_PREDIV_8 = 3U  /**< The clock is pre-diveded by 8 */
} SDDF_PreDivType;

/**
 * @brief Select the SDDF operation mode
 *
 */
typedef enum
{
    SDDF_MODE_NORMAL = 0U, /**< SDDF is in normal mode */
    SDDF_MODE_DEBUG  = 1U  /**< SDDF is in debug mode */
} SDDF_ModeType;

/**
 * @brief Select whether the SDDF module enables in debug mode
 * 
 */
typedef enum
{
    SDDF_MODULE_ENABLE_IN_DEBUG  = 0U, /**< SDDF is enabled in debug mode */
    SDDF_MODULE_DISABLE_IN_DEBUG = 1U  /**< SDDF is disabled in debug mode. Need trigger again for new conversion */
} SDDF_DebugModuleEnableType;

/**
 * @brief Select the data source for limit check and zero cross check
 *
 */
typedef enum
{
    SDDF_INPUT_SRC_MAIN_FILTER      = 0U, /**< The input source is main filter */
    SDDF_INPUT_SRC_AUXILIARY_FILTER = 1U  /**< The input source is auxiliary filter */
} SDDF_InputSrcType;

/**
 * @brief Select the conversion mode for auxiliary filter
 *
 */
typedef enum
{
    SDDF_AUX_FILTER_CONV_ALWAYS_ON   = 0U, /**< Auxiliary filter is always on */
    SDDF_AUX_FILTER_CONV_FOLLOW_MAIN = 1U  /**< Auxiliary filter operates following the main filter */
} SDDF_AuxFilterConvModeType;

/**
 * @brief Selects the filter order for auxiliary filter
 *
 */
typedef enum
{
    SDDF_AUX_FILTER_FIRST_ORDER  = 1U, /**< The auxiliary filter is 1st order */
    SDDF_AUX_FILTER_SECOND_ORDER = 2U, /**< The auxiliary filter is 2nd order */
    SDDF_AUX_FILTER_THIRD_ORDER  = 3U  /**< The auxiliary filter is 3rd order */
} SDDF_AuxFilterOrderType;

/**
 * @brief Selects the conversion mode for main filter
 *
 */
typedef enum
{
    SDDF_MAIN_FILTER_CONV_SINGLE     = 0U, /**< Single mode. One conversion following a triggering event */
    SDDF_MAIN_FILTER_CONV_CONTINUOUS = 1U, /**< Continuouts conversion mode. Multiple conversions following a triggering
                                                event, and the next trigger will cancel and restart conversion */
    SDDF_MAIN_FILTER_CONV_ALWAYS     = 2U  /**< Always conversion mode. Multiple conversions following the first trigger,
                                                and the next trigger will be ignored */
} SDDF_MainFilterConvModeType;

/**
 * @brief Selects the filter order for main filter
 * 
 */
typedef enum
{
    SDDF_MAIN_FILTER_FIRST_ORDER  = 1U, /**< The main filter is 1st order */
    SDDF_MAIN_FILTER_SECOND_ORDER = 2U, /**< The main filter is 2nd order */
    SDDF_MAIN_FILTER_THIRD_ORDER  = 3U, /**< The main filter is 3rd order */
    SDDF_MAIN_FILTER_FOURTH_ORDER = 4U, /**< The main filter is 4th order */
    SDDF_MAIN_FILTER_FIFTH_ORDER  = 5U  /**< The main filter is 5th order */
} SDDF_MainFilterOrderType;

/**
 * @brief Select the trigger level type
 * 
 */
typedef enum
{
    SDDF_TRIGGER_EVENT_EDGE  = 0U, /**< Trigger is edge event. Next edge event will cancel the current conversion,
                                        and re-start in single or continuous mode */
    SDDF_TRIGGER_EVENT_LEVEL = 1U  /**< Trigger is level event. De-assert cancels the current conversion, and stop
                                        filter function in single or continuous mode */
} SDDF_TriggerEventType;

/**
 * @brief Select the trigger source
 * 
 */
typedef enum
{
    SDDF_TRIGGER_SRC_SOFTWARE = 0U, /**< Software trigger is selected */
    SDDF_TRIGGER_SRC_HARDWARE = 1U  /**< Hardware trigger is selected */
} SDDF_TriggerSrcType;

/**
 * @brief Select the input clock edge
 * 
 */
typedef enum
{
    SDDF_CLOCK_EDGE_RISING  = 1U, /**< Use the input clock rising edge */
    SDDF_CLOCK_EDGE_FALLING = 2U, /**< Use the input clock falling edge */
    SDDF_CLOCK_EDGE_BOTH    = 3U  /**< Use both edges of the input clock */
} SDDF_ClockEdgeType;

/**
 * @brief Select the input clock source
 * 
 */
typedef enum
{
    SDDF_CLOCK_SRC_EXTERNAL_MODULATOR_CLOCK = 3U /**< The input clock is from the external modulator clock dedicated to
                                                      this channel */
} SDDF_ClockSrcType;

/**
 * @brief Select the input bit format
 * 
 */
typedef enum
{
    SDDF_BIT_FORMAT_EXTERNAL_ONE_BIT_STREAM = 0U, /**< External one bit stream */
    SDDF_BIT_FORMAT_EXTERNAL_MANCHSTER_CODE = 1U  /**< External Manchester code, SDDF_ClockEdgeType will determine rise
                                                       or fall decoder */
} SDDF_BitFormatType;

/**
 * @brief Select the result data format
 * 
 */
typedef enum
{
    SDDF_RESULT_DATA_LEFT_ALIGNED_SIGNED   = 0U, /**< The result is left justfied, signed, for the case where input
                                                      bitstram is signed */
    SDDF_RESULT_DATA_LEFT_ALIGNED_UNSIGNED = 1U  /**< The result is left justfied, unsigned, for the case where input
                                                      bitstram is unsigned */
} SDDF_ResultFormatType;

/**
 * @brief Set the main filter shift to get correct 24 bit precision
 * @details Main Filter CIC raw result is always 32bit width. The user should program MFSHIFT for cut-off and shift
 * left/right to get 24bit result.
 * 
 */
typedef enum
{
    SDDF_MAIN_FILTER_NOT_SHIFT      = 0U,  /**< Main filter no shift needed */
    SDDF_MAIN_FILTER_SHIFT_RIGHT_1  = 1U,  /**< Main filter shift right by 1 bit */
    SDDF_MAIN_FILTER_SHIFT_RIGHT_2  = 2U,  /**< Main filter shift right by 2 bits */
    SDDF_MAIN_FILTER_SHIFT_RIGHT_3  = 3U,  /**< Main filter shift right by 3 bits */
    SDDF_MAIN_FILTER_SHIFT_RIGHT_4  = 4U,  /**< Main filter shift right by 4 bits */
    SDDF_MAIN_FILTER_SHIFT_RIGHT_5  = 5U,  /**< Main filter shift right by 5 bits */
    SDDF_MAIN_FILTER_SHIFT_RIGHT_6  = 6U,  /**< Main filter shift right by 6 bits */
    SDDF_MAIN_FILTER_SHIFT_RIGHT_7  = 7U,  /**< Main filter shift right by 7 bits */
    SDDF_MAIN_FILTER_SHIFT_RIGHT_8  = 8U,  /**< Main filter shift right by 8 bits */
    SDDF_MAIN_FILTER_SHIFT_RIGHT_9  = 9U,  /**< Main filter shift right by 9 bits */
    SDDF_MAIN_FILTER_SHIFT_RIGHT_10 = 10U, /**< Main filter shift right by 10 bits */
    SDDF_MAIN_FILTER_SHIFT_RIGHT_11 = 11U, /**< Main filter shift right by 11 bits */
    SDDF_MAIN_FILTER_SHIFT_RIGHT_12 = 12U, /**< Main filter shift right by 12 bits */
    SDDF_MAIN_FILTER_SHIFT_RIGHT_13 = 13U, /**< Main filter shift right by 13 bits */
    SDDF_MAIN_FILTER_SHIFT_RIGHT_14 = 14U, /**< Main filter shift right by 14 bits */
    SDDF_MAIN_FILTER_SHIFT_RIGHT_15 = 15U, /**< Main filter shift right by 15 bits */
    SDDF_MAIN_FILTER_SHIFT_LEFT_1   = 17U, /**< Main filter shift left by 1 bit */
    SDDF_MAIN_FILTER_SHIFT_LEFT_2   = 18U, /**< Main filter shift left by 2 bits */
    SDDF_MAIN_FILTER_SHIFT_LEFT_3   = 19U, /**< Main filter shift left by 3 bits */
    SDDF_MAIN_FILTER_SHIFT_LEFT_4   = 20U, /**< Main filter shift left by 4 bits */
    SDDF_MAIN_FILTER_SHIFT_LEFT_5   = 21U, /**< Main filter shift left by 5 bits */
    SDDF_MAIN_FILTER_SHIFT_LEFT_6   = 22U, /**< Main filter shift left by 6 bits */
    SDDF_MAIN_FILTER_SHIFT_LEFT_7   = 23U, /**< Main filter shift left by 7 bits */
    SDDF_MAIN_FILTER_SHIFT_LEFT_8   = 24U, /**< Main filter shift left by 8 bits */
    SDDF_MAIN_FILTER_SHIFT_LEFT_9   = 25U, /**< Main filter shift left by 9 bits */
    SDDF_MAIN_FILTER_SHIFT_LEFT_10  = 26U, /**< Main filter shift left by 10 bits */
    SDDF_MAIN_FILTER_SHIFT_LEFT_11  = 27U, /**< Main filter shift left by 11 bits */
    SDDF_MAIN_FILTER_SHIFT_LEFT_12  = 28U, /**< Main filter shift left by 12 bits */
    SDDF_MAIN_FILTER_SHIFT_LEFT_13  = 29U, /**< Main filter shift left by 13 bits */
    SDDF_MAIN_FILTER_SHIFT_LEFT_14  = 30U, /**< Main filter shift left by 14 bits */
    SDDF_MAIN_FILTER_SHIFT_LEFT_15  = 31U  /**< Main filter shift left by 15 bits */
} SDDF_MainFilterShiftType;

/**
 * @brief Select the limit detection option
 * 
 */
typedef enum
{
    SDDF_CHANNEL_LIMIT_BOTH_HITH_LOW_THRES = 0U, /**< Limitation detect on exceed both high and low value */
    SDDF_CHANNEL_LIMIT_HITH_THRES          = 1U, /**< Limitation detect on exceed high threshold value */
    SDDF_CHANNEL_LIMIT_LOW_THRES           = 2U, /**< Limitation detect on exceed low threshold value */
    SDDF_CHANNEL_LIMIT_WINDOW              = 3U  /**< Limitation detect on windowed value */
} SDDF_ChannelLimitOptionType;

/**
 * @brief Select the short circuit detection option
 * 
 */
typedef enum
{
    SDDF_SHORT_CIRCUIT_COUNT_ON_BOTH = 0U, /**< Short circuit count on both 0 and 1, detect both high and low value*/
    SDDF_SHORT_CIRCUIT_COUNT_ON_1    = 1U, /**< Short circuit count on 1, detect high value */
    SDDF_SHORT_CIRCUIT_COUNT_ON_0    = 2U  /**< Short circuit count on 0, detect low value */
} SDDF_ShortCircuitOptionType;

/**
 * @brief Select sht short circuit detect conversion mode
 * 
 */
typedef enum
{
    SDDF_SHORT_DETECT_ALWAYS_ON     = 0U, /**< Short circuit detect is always on when CHEN and MEN are asserted */
    SDDF_SHORT_DETECT_AUX_FILTER_EN = 1U  /**< Short circuit detect only works  when the Auxiliary Filter is enabled */
} SDDF_ShortCircuitDetectModeType;

/**
 * @brief Get the global control register (SDDF_CTRL) value
 * 
 * @param pSddf the base address of the SDDF instance
 * @return uint32_t the SDDF_CTRL register value
 */
LOCAL_INLINE uint32_t SDDF_HWA_GetCtrl(const SDDF_Type *const pSddf)
{
    return pSddf->CTRL;
}

/**
 * @brief Set the global control register (SDDF_CTRL) value
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u32Ctrl the SDDF_CTRL register value to set
 */
LOCAL_INLINE void SDDF_HWA_SetCtrl(SDDF_Type *const pSddf, uint32_t u32Ctrl)
{
    pSddf->CTRL = u32Ctrl;
}

/**
 * @brief Get whether SDDF clock output 2 is disabled
 * 
 * @param pSddf the base address of the SDDF instance
 * @return true SDDF clock output 2 is diabled
 * @return false SDDF clock output 2 is enabled
 */
LOCAL_INLINE bool SDDF_HWA_GetClockOut2DisableFlag(const SDDF_Type *const pSddf)
{
    uint32_t u32TmpVal = (pSddf->CTRL & SDDF_CTRL_CLKO2_DIS_MASK) >> SDDF_CTRL_CLKO2_DIS_SHIFT;
    return (u32TmpVal != 0U ? true : false);
}

/**
 * @brief Set whether to disable clock output 2
 * 
 * @param pSddf the base address of the SDDF instance
 * @param bDisable whether to disable clock output 2
 */
LOCAL_INLINE void SDDF_HWA_SetClockOut2DisableFlag(SDDF_Type *const pSddf, bool bDisable)
{
    pSddf->CTRL = (pSddf->CTRL & ~SDDF_CTRL_CLKO2_DIS_MASK) | SDDF_CTRL_CLKO2_DIS(bDisable);
}

/**
 * @brief Get whether SDDF clock output 1 is disabled
 * 
 * @param pSddf the base address of the SDDF instance
 * @return true SDDF clock output 1 is diabled
 * @return false SDDF clock output 1 is enabled
 */
LOCAL_INLINE bool SDDF_HWA_GetClockOut1DisableFlag(const SDDF_Type *const pSddf)
{
    uint32_t u32TmpVal = (pSddf->CTRL & SDDF_CTRL_CLKO1_DIS_MASK) >> SDDF_CTRL_CLKO1_DIS_SHIFT;
    return (u32TmpVal != 0U ? true : false);
}

/**
 * @brief Set whether to disable clock output 1
 * 
 * @param pSddf the base address of the SDDF instance
 * @param bDisable whether to disable clock output 1
 */
LOCAL_INLINE void SDDF_HWA_SetClockOut1DisableFlag(SDDF_Type *const pSddf, bool bDisable)
{
    pSddf->CTRL = (pSddf->CTRL & ~SDDF_CTRL_CLKO1_DIS_MASK) | SDDF_CTRL_CLKO1_DIS(bDisable);
}

/**
 * @brief Get whether SDDF clock output 0 is disabled
 * 
 * @param pSddf the base address of the SDDF instance
 * @return true SDDF clock output 0 is diabled
 * @return false SDDF clock output 0 is enabled
 */
LOCAL_INLINE bool SDDF_HWA_GetClockOut0DisableFlag(const SDDF_Type *const pSddf)
{
    uint32_t u32TmpVal = (pSddf->CTRL & SDDF_CTRL_CLKO0_DIS_MASK) >> SDDF_CTRL_CLKO0_DIS_SHIFT;
    return (u32TmpVal != 0U ? true : false);
}

/**
 * @brief Set whether to disable clock output 0
 * 
 * @param pSddf the base address of the SDDF instance
 * @param bDisable whether to disable clock output 0
 */
LOCAL_INLINE void SDDF_HWA_SetClockOut0DisableFlag(SDDF_Type *const pSddf, bool bDisable)
{
    pSddf->CTRL = (pSddf->CTRL & ~SDDF_CTRL_CLKO0_DIS_MASK) | SDDF_CTRL_CLKO0_DIS(bDisable);
}

/**
 * @brief Get the function clock pre-divider value
 * 
 * @param pSddf the base address of the SDDF instance
 * @return SDDF_PreDivType the function clock pre-divider value
 */
LOCAL_INLINE SDDF_PreDivType SDDF_HWA_GetPreDivider(const SDDF_Type *const pSddf)
{
    uint32_t u32TmpVal = (pSddf->CTRL & SDDF_CTRL_PRESCALE_MASK) >> SDDF_CTRL_PRESCALE_SHIFT;
    return (SDDF_PreDivType)u32TmpVal;
}

/**
 * @brief Set the function clock pre-divider value
 * 
 * @param pSddf the base address of the SDDF instance
 * @param eDiv the function clock pre-divider value
 */
LOCAL_INLINE void SDDF_HWA_SetPreDivider(SDDF_Type *const pSddf, SDDF_PreDivType eDiv)
{
    pSddf->CTRL = (pSddf->CTRL & ~SDDF_CTRL_PRESCALE_MASK) | SDDF_CTRL_PRESCALE(eDiv);
}

/**
 * @brief Get the clock divider value
 * 
 * @param pSddf the base address of the SDDF instance
 * @return uint32_t the clock out divider value
 */
LOCAL_INLINE uint32_t SDDF_HWA_GetDivider(const SDDF_Type *const pSddf)
{
    uint32_t u32TmpVal = (pSddf->CTRL & SDDF_CTRL_MCLK_DIV_MASK) >> SDDF_CTRL_MCLK_DIV_SHIFT;
    return (u32TmpVal + 1U);
}

/**
 * @brief Set the clock divider value
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u32Div the clock out divider value
 */
LOCAL_INLINE void SDDF_HWA_SetDivider(SDDF_Type *const pSddf, uint32_t u32Div)
{
    DEV_ASSERT((u32Div >= 2U) && (u32Div <= 128U));
    pSddf->CTRL = (pSddf->CTRL & ~SDDF_CTRL_MCLK_DIV_MASK) | SDDF_CTRL_MCLK_DIV(u32Div - 1U);
}

/**
 * @brief Get whether the SDDF function blocks are enabled
 * 
 * @param pSddf the base address of the SDDF instance
 * @return true the fuction blocks are enabled
 * @return false all function blocks are disabled
 */
LOCAL_INLINE bool SDDF_HWA_GetMainEnableFlag(const SDDF_Type *const pSddf)
{
    uint32_t u32TmpVal = (pSddf->CTRL & SDDF_CTRL_MEN_MASK) >> SDDF_CTRL_MEN_SHIFT;
    return (u32TmpVal != 0U ? true : false);
}

/**
 * @brief Enable the SDDF function blocks
 * 
 * @param pSddf the base address of the SDDF instance
 */
LOCAL_INLINE void SDDF_HWA_MainEnable(SDDF_Type *const pSddf)
{
    pSddf->CTRL |= SDDF_CTRL_MEN_MASK;
}

/**
 * @brief Disable all SDDF function blocks
 * 
 * @param pSddf the base address of the SDDF instance
 */
LOCAL_INLINE void SDDF_HWA_MainDisable(SDDF_Type *const pSddf)
{
    pSddf->CTRL &= ~SDDF_CTRL_MEN_MASK;
}

/**
 * @brief Reset all SDDF function blocks and clock configuration bits
 * 
 * @param pSddf the base address of the SDDF instance
 */
LOCAL_INLINE void SDDF_HWA_Reset(SDDF_Type *const pSddf)
{
    pSddf->CTRL |= SDDF_CTRL_RESET_MASK;
    pSddf->CTRL &= ~SDDF_CTRL_RESET_MASK;
}

/**
 * @brief Get the SDDF operation mode (normal mode or debug mode)
 * 
 * @param pSddf the base address of the SDDF instance
 * @return SDDF_ModeType the operation mode of SDDF
 */
LOCAL_INLINE SDDF_ModeType SDDF_HWA_GetOperationMode(const SDDF_Type *const pSddf)
{
    uint32_t u32TmpVal = (pSddf->CTRL & SDDF_CTRL_DBG_MODE_MASK) >> SDDF_CTRL_DBG_MODE_SHIFT;
    return (SDDF_ModeType)u32TmpVal;
}

/**
 * @brief Set the SDDF operation mode
 * 
 * @param pSddf the base address of the SDDF instanc
 * @param eMode the operation mode of SDDF
 */
LOCAL_INLINE void SDDF_HWA_SetOperationMode(SDDF_Type *const pSddf, SDDF_ModeType eMode)
{
    DEV_ASSERT((SDDF_HWA_GetMainEnableFlag(pSddf) == false));
    pSddf->CTRL = (pSddf->CTRL & ~SDDF_CTRL_DBG_MODE_MASK) | SDDF_CTRL_DBG_MODE(eMode);
}

/**
 * @brief Get whether SDDF module is enabled in debug mode
 * 
 * @param pSddf the base address of the SDDF instanc
 * @return SDDF_DebugModuleEnableType whether SDDF module is enabled in debug mode
 */
LOCAL_INLINE SDDF_DebugModuleEnableType SDDF_HWA_GetModuleDebugEnableFlag(const SDDF_Type *const pSddf)
{
    uint32_t u32TmpVal = (pSddf->CTRL & SDDF_CTRL_DBG_EN_MASK) >> SDDF_CTRL_DBG_EN_SHIFT;
    return (SDDF_DebugModuleEnableType)u32TmpVal;
}

/**
 * @brief Set whether SDDF module is enabled in debug mode
 * 
 * @param pSddf the base address of the SDDF instanc
 * @param eEnable whether SDDF module is enabled in debug mode
 */
LOCAL_INLINE void SDDF_HWA_SetModuleDebugEnableFlag(SDDF_Type *const pSddf, SDDF_DebugModuleEnableType eEnable)
{
    pSddf->CTRL = (pSddf->CTRL & ~SDDF_CTRL_DBG_EN_MASK) | SDDF_CTRL_DBG_EN(eEnable);
}

/**
 * @brief Generate software trigger signal for the selected channel
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the channel to generate software trigger signal
 */
LOCAL_INLINE void SDDF_HWA_GenerateChannelSwTrigger(SDDF_Type *const pSddf, uint8_t u8ChanIdx)
{
    pSddf->CTRL |= SDDF_CTRL_SWTRIG0_MASK << u8ChanIdx;
}

/**
 * @brief Get the normal interrupt (SDDF_NIER) register value
 * 
 * @param pSddf the base address of the SDDF instance
 * @return uint32_t the SDDF_NIER register value
 */
LOCAL_INLINE uint32_t SDDF_HWA_GetNormalInterruptEnable(const SDDF_Type *const pSddf)
{
    return pSddf->NIER;
}

/**
 * @brief Set the normal interrupt (SDDF_NIER) register value
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u32IntEn the SDDF_NIER register value to set
 */
LOCAL_INLINE void SDDF_HWA_SetNormalInterruptEnable(SDDF_Type *const pSddf, uint32_t u32IntEn)
{
    pSddf->NIER = u32IntEn;
}

/**
 * @brief Get whether zero cross detect interrupt is enabled
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the channel index
 * @return true zero cross detect interrupt is enabled
 * @return false zero cross detect interrupt is disabled
 */
LOCAL_INLINE bool SDDF_HWA_GetChannelZeroCrossDetectIntEnableFlag(const SDDF_Type *const pSddf, uint8_t u8ChanIdx)
{
    uint32_t u32TmpVal = (pSddf->NIER & (SDDF_NIER_ZCDIE0_MASK << u8ChanIdx)) >> (SDDF_NIER_ZCDIE0_SHIFT + u8ChanIdx);
    return (u32TmpVal != 0U ? true : false);
}

/**
 * @brief Set whether to enable zero cross detect interrupt
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the channel index
 * @param bEnable whether to enable zero cross detect interrupt
 */
LOCAL_INLINE void SDDF_HWA_SetChannelZeroCrossDetectIntEnableFlag(SDDF_Type *const pSddf, uint8_t u8ChanIdx,
                                                                  bool bEnable)
{
    pSddf->NIER = (pSddf->NIER & ~(SDDF_NIER_ZCDIE0_MASK << u8ChanIdx)) | (SDDF_NIER_ZCDIE0(bEnable) << u8ChanIdx);
}

/**
 * @brief Get whether channel FIFO data ready interrupt is enabled
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the channel index
 * @return true channel FIFO data ready interrupt is enabled
 * @return false channel FIFO data ready interrupt is disabled
 */
LOCAL_INLINE bool SDDF_HWA_GetChannelFIFODataReadyIntEnableFlag(const SDDF_Type *const pSddf, uint8_t u8ChanIdx)
{
    uint32_t u32TmpVal = (pSddf->NIER & (SDDF_NIER_FRDYIE0_MASK << u8ChanIdx)) >> (SDDF_NIER_FRDYIE0_SHIFT + u8ChanIdx);
    return (u32TmpVal != 0U ? true : false);
}

/**
 * @brief Set whether to enable channel FIFO data ready interrupt
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the channel index
 * @param bEnable whether to enable channel FIFO data ready interrupt
 */
LOCAL_INLINE void SDDF_HWA_SetChannelFIFODataReadyIntEnableFlag(SDDF_Type *const pSddf, uint8_t u8ChanIdx, bool bEnable)
{
    pSddf->NIER = (pSddf->NIER & ~(SDDF_NIER_FRDYIE0_MASK << u8ChanIdx)) | (SDDF_NIER_FRDYIE0(bEnable) << u8ChanIdx);
}

/**
 * @brief Get whether channel conversion complete interrupt is enabled
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the channel index
 * @return true channel conversion complete interrupt is enabled
 * @return false channel conversion complete interrupt is disabled
 */
LOCAL_INLINE bool SDDF_HWA_GetChannelConvCompleteIntEnableFlag(const SDDF_Type *const pSddf, uint8_t u8ChanIdx)
{
    uint32_t u32TmpVal = (pSddf->NIER & (SDDF_NIER_COCIE0_MASK << u8ChanIdx)) >> (SDDF_NIER_COCIE0_SHIFT + u8ChanIdx);
    return (u32TmpVal != 0U ? true : false);
}

/**
 * @brief Set whether to enable channel conversion complete interrupt
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the channel index
 * @param bEnable whether to enable channel conversion complete interrupt
 */
LOCAL_INLINE void SDDF_HWA_SetChannelConvCompleteIntEnableFlag(SDDF_Type *const pSddf, uint8_t u8ChanIdx, bool bEnable)
{
    pSddf->NIER = (pSddf->NIER & ~(SDDF_NIER_COCIE0_MASK << u8ChanIdx)) | (SDDF_NIER_COCIE0(bEnable) << u8ChanIdx);
}

/**
 * @brief Get the channel abnornal interrupt 0 (SDDF_ABNIER0) register value
 * 
 * @param pSddf the base address of the SDDF instance
 * @return uint32_t the SDDF_ABNIER0 register value
 */
LOCAL_INLINE uint32_t SDDF_HWA_GetAbnormalInterruptEnable0(const SDDF_Type *const pSddf)
{
    return pSddf->ABNIER0;
}

/**
 * @brief Set the channel abnornal interrupt 0 (SDDF_ABNIER0) register value
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u32IntEn the SDDF_ABNIER0 register value to set
 */
LOCAL_INLINE void SDDF_HWA_SetAbnormalInterruptEnable0(SDDF_Type *const pSddf, uint32_t u32IntEn)
{
    pSddf->ABNIER0 = u32IntEn;
}

/**
 * @brief Get whether channel high limit detect interrupt is enabled
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the channel index
 * @return true the channel high limit detect interrupt is enabled
 * @return false the channel high limit detect interrupt is disabled
 */
LOCAL_INLINE bool SDDF_HWA_GetChannelHighLimitIntEnableFlag(const SDDF_Type *const pSddf, uint8_t u8ChanIdx)
{
    uint32_t u32TmpVal = (pSddf->ABNIER0 & (SDDF_ABNIER0_HLMTIE0_MASK << u8ChanIdx)) >>
                         (SDDF_ABNIER0_HLMTIE0_SHIFT + u8ChanIdx);
    return (u32TmpVal != 0U ? true : false);
}

/**
 * @brief Set whether to enable channel high limit detect interrupt
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the channel index
 * @param bEnable whether to enable channel high limit detect interrupt
 */
LOCAL_INLINE void SDDF_HWA_SetChannelHighLimitIntEnableFlag(SDDF_Type *const pSddf, uint8_t u8ChanIdx, bool bEnable)
{
    pSddf->ABNIER0 = (pSddf->ABNIER0 & ~(SDDF_ABNIER0_HLMTIE0_MASK << u8ChanIdx)) | (SDDF_ABNIER0_HLMTIE0(
                         bEnable) << u8ChanIdx);
}

/**
 * @brief Get whether channel low limit detect interrupt is enabled
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the channel index
 * @return true the channel low limit detect interrupt is enabled
 * @return false the channel low limit detect interrupt is disabled
 */
LOCAL_INLINE bool SDDF_HWA_GetChannelLowLimitIntEnableFlag(const SDDF_Type *const pSddf, uint8_t u8ChanIdx)
{
    uint32_t u32TmpVal = (pSddf->ABNIER0 & (SDDF_ABNIER0_LLMTIE0_MASK << u8ChanIdx)) >>
                         (SDDF_ABNIER0_LLMTIE0_SHIFT + u8ChanIdx);
    return (u32TmpVal != 0U ? true : false);
}

/**
 * @brief Set whether to enable channel low limit detect interrupt
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the channel index
 * @param bEnable whether to enable channel low limit detect interrupt
 */
LOCAL_INLINE void SDDF_HWA_SetChannelLowLimitIntEnableFlag(SDDF_Type *const pSddf, uint8_t u8ChanIdx, bool bEnable)
{
    pSddf->ABNIER0 = (pSddf->ABNIER0 & ~(SDDF_ABNIER0_LLMTIE0_MASK << u8ChanIdx)) | (SDDF_ABNIER0_LLMTIE0(
                         bEnable) << u8ChanIdx);
}

/**
 * @brief Get whether channel window limit detect interrupt is enabled
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the channel index
 * @return true the channel window limit detect interrupt is enabled
 * @return false the channel window limit detect interrupt is disabled
 */
LOCAL_INLINE bool SDDF_HWA_GetChannelWindowLimitIntEnableFlag(const SDDF_Type *const pSddf, uint8_t u8ChanIdx)
{
    uint32_t u32TmpVal = (pSddf->ABNIER0 & (SDDF_ABNIER0_WLMTIE0_MASK << u8ChanIdx)) >>
                         (SDDF_ABNIER0_WLMTIE0_SHIFT + u8ChanIdx);
    return (u32TmpVal != 0U ? true : false);
}

/**
 * @brief Set whether to enable channel window limit detect interrupt
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the channel index
 * @param bEnable whether to enable channel window limit detect interrupt
 */
LOCAL_INLINE void SDDF_HWA_SetChannelWindowLimitIntEnableFlag(SDDF_Type *const pSddf, uint8_t u8ChanIdx, bool bEnable)
{
    pSddf->ABNIER0 = (pSddf->ABNIER0 & ~(SDDF_ABNIER0_WLMTIE0_MASK << u8ChanIdx)) | (SDDF_ABNIER0_WLMTIE0(
                         bEnable) << u8ChanIdx);
}

/**
 * @brief Get whether channel short circuit detect interrupt is enabled
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the channel index
 * @return true the channel short circuit detect interrupt is enabled
 * @return false the channel short circuit detect interrupt is disabled
 */
LOCAL_INLINE bool SDDF_HWA_GetChannelShortCircuitDetectIntEnableFlag(const SDDF_Type *const pSddf, uint8_t u8ChanIdx)
{
    uint32_t u32TmpVal = (pSddf->ABNIER0 & (SDDF_ABNIER0_SCDIE0_MASK << u8ChanIdx)) >> (SDDF_ABNIER0_SCDIE0_SHIFT +
                         u8ChanIdx);
    return (u32TmpVal != 0U ? true : false);
}

/**
 * @brief Set whether to enable channel short circuit detect interrupt
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the channel index
 * @param bEnable whether to enable channel short circuit detect interrupt
 */
LOCAL_INLINE void SDDF_HWA_SetChannelShortCircuitDetectIntEnableFlag(SDDF_Type *const pSddf, uint8_t u8ChanIdx,
                                                                     bool bEnable)
{
    pSddf->ABNIER0 = (pSddf->ABNIER0 & ~(SDDF_ABNIER0_SCDIE0_MASK << u8ChanIdx)) | (SDDF_ABNIER0_SCDIE0(
            bEnable) << u8ChanIdx);
}

/**
 * @brief Get the channel abnornal interrupt 1 (SDDF_ABNIER1) register value
 * 
 * @param pSddf the base address of the SDDF instance
 * @return uint32_t the SDDF_ABNIER1 register value
 */
LOCAL_INLINE uint32_t SDDF_HWA_GetAbnormalInterruptEnable1(const SDDF_Type *const pSddf)
{
    return pSddf->ABNIER1;
}

/**
 * @brief Set the channel abnornal interrupt 1 (SDDF_ABNIER1) register value
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u32IntEn the SDDF_ABNIER1 register value to set
 */
LOCAL_INLINE void SDDF_HWA_SetAbnormalInterruptEnable1(SDDF_Type *const pSddf, uint32_t u32IntEn)
{
    pSddf->ABNIER1 = u32IntEn;
}

/**
 * @brief Get whether channel result saturation interrupt is enabled
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the channel index
 * @return true the channel result saturation interrupt is enabled
 * @return false the channel result saturation interrupt is disabled
 */
LOCAL_INLINE bool SDDF_HWA_GetChannelSaturationIntEnableFlag(const SDDF_Type *const pSddf, uint8_t u8ChanIdx)
{
    uint32_t u32TmpVal = (pSddf->ABNIER1 & (SDDF_ABNIER1_SATIE0_MASK << u8ChanIdx)) >> (SDDF_ABNIER1_SATIE0_SHIFT +
                         u8ChanIdx);
    return (u32TmpVal != 0U ? true : false);
}

/**
 * @brief Set whether to enable channel result saturation interrupt
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the channel index
 * @param bEnable whether to enable channel result saturation interrupt
 */
LOCAL_INLINE void SDDF_HWA_SetChannelSaturationIntEnableFlag(SDDF_Type *const pSddf, uint8_t u8ChanIdx, bool bEnable)
{
    pSddf->ABNIER1 = (pSddf->ABNIER1 & ~(SDDF_ABNIER1_SATIE0_MASK << u8ChanIdx)) | (SDDF_ABNIER1_SATIE0(
            bEnable) << u8ChanIdx);
}

/**
 * @brief Get whether channel clock absence detect interrupt is enabled
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the channel index
 * @return true the channel clock absence detect interrupt is enabled
 * @return false the channel clock absence detect interrupt is disabled
 */
LOCAL_INLINE bool SDDF_HWA_GetChannelClockAbsenceIntEnableFlag(const SDDF_Type *const pSddf, uint8_t u8ChanIdx)
{
    uint32_t u32TmpVal = (pSddf->ABNIER1 & (SDDF_ABNIER1_CADIE0_MASK << u8ChanIdx)) >> (SDDF_ABNIER1_CADIE0_SHIFT +
                         u8ChanIdx);
    return (u32TmpVal != 0U ? true : false);
}

/**
 * @brief Set whether to enable channel clock absence detect interrupt
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the channel index
 * @param bEnable whether to enable channel clock absence detect interrupt
 */
LOCAL_INLINE void SDDF_HWA_SetChannelClockAbsenceIntEnableFlag(SDDF_Type *const pSddf, uint8_t u8ChanIdx, bool bEnable)
{
    pSddf->ABNIER1 = (pSddf->ABNIER1 & ~(SDDF_ABNIER1_CADIE0_MASK << u8ChanIdx)) | (SDDF_ABNIER1_CADIE0(
            bEnable) << u8ChanIdx);
}

/**
 * @brief Get whether channel FIFO overflow interrupt is enabled
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the channel index
 * @return true the channel FIFO overflow interrupt is enabled
 * @return false the channel FIFO overflow interrupt is disabled
 */
LOCAL_INLINE bool SDDF_HWA_GetChannelFIFOOverflowIntEnableFlag(const SDDF_Type *const pSddf, uint8_t u8ChanIdx)
{
    uint32_t u32TmpVal = (pSddf->ABNIER1 & (SDDF_ABNIER1_FOVFIE0_MASK << u8ChanIdx)) >>
                         (SDDF_ABNIER1_FOVFIE0_SHIFT + u8ChanIdx);
    return (u32TmpVal != 0U ? true : false);
}

/**
 * @brief Set whether to enable channel FIFO overflow interrupt
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the channel index
 * @param bEnable whether to enable channel FIFO overflow interrupt
 */
LOCAL_INLINE void SDDF_HWA_SetChannelFIFOOverflowIntEnableFlag(SDDF_Type *const pSddf, uint8_t u8ChanIdx, bool bEnable)
{
    pSddf->ABNIER1 = (pSddf->ABNIER1 & ~(SDDF_ABNIER1_FOVFIE0_MASK << u8ChanIdx)) | (SDDF_ABNIER1_FOVFIE0(
                         bEnable) << u8ChanIdx);
}

/**
 * @brief Get whether channel FIFO underflow interrupt is enabled
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the channel index
 * @return true the channel FIFO underflow interrupt is enabled
 * @return false the channel FIFO underflow interrupt is disabled
 */
LOCAL_INLINE bool SDDF_HWA_GetChannelFIFOUnderflowIntEnableFlag(const SDDF_Type *const pSddf, uint8_t u8ChanIdx)
{
    uint32_t u32TmpVal = (pSddf->ABNIER1 & (SDDF_ABNIER1_FUNFIE0_MASK << u8ChanIdx)) >>
                         (SDDF_ABNIER1_FUNFIE0_SHIFT + u8ChanIdx);
    return (u32TmpVal != 0U ? true : false);
}

/**
 * @brief Set whether to enable channel FIFO underflow interrupt
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the channel index
 * @param bEnable whether to enable channel FIFO underflow interrupt
 */
LOCAL_INLINE void SDDF_HWA_SetChannelFIFOUnderflowIntEnableFlag(SDDF_Type *const pSddf, uint8_t u8ChanIdx, bool bEnable)
{
    pSddf->ABNIER1 = (pSddf->ABNIER1 & ~(SDDF_ABNIER1_FUNFIE0_MASK << u8ChanIdx)) | (SDDF_ABNIER1_FUNFIE0(
                         bEnable) << u8ChanIdx);
}

/**
 * @brief Get the normal interrupt status register (SDDF_NISR) value
 * 
 * @param pSddf the base address of the SDDF instance
 * @return uint32_t the normal interrupt status (SDDF_NISR) register value
 */
LOCAL_INLINE uint32_t SDDF_HWA_GetNormalInterruptStatus(const SDDF_Type *const pSddf)
{
    return pSddf->NISR;
}

/**
 * @brief Clear the normal interrupt status register (SDDF_NISR) value
 * 
 * @param pSddf the base address of the SDDF instance
 */
LOCAL_INLINE void SDDF_HWA_ClearNormalInterruptStatus(SDDF_Type *const pSddf)
{
    pSddf->NISR = SDDF_NIER_MASK;
}

/**
 * @brief Get zero cross detect status of the selected channel
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the selected SDDF channel
 * @return true zero cross is detected
 * @return false zero cross is not detected 
 */
LOCAL_INLINE bool SDDF_HWA_GetChannelZeroCrossDetectStatus(const SDDF_Type *const pSddf, uint8_t u8ChanIdx)
{
    uint32_t u32TmpVal = (pSddf->NISR & (SDDF_NISR_ZCD0_MASK << u8ChanIdx)) >> (SDDF_NISR_ZCD0_SHIFT + u8ChanIdx);
    return (u32TmpVal != 0U ? true : false);
}

/**
 * @brief Clear zero cross detect flag of the selected channel
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the selected SDDF channel
 */
LOCAL_INLINE void SDDF_HWA_ClearChannelZeroCrossDetectStatus(SDDF_Type *const pSddf, uint8_t u8ChanIdx)
{
    pSddf->NISR = SDDF_NISR_ZCD0_MASK << u8ChanIdx;
}

/**
 * @brief Get FIFO data ready status of the selected channel
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the selected SDDF channel
 * @return true FIFO data ready is detected
 * @return false FIFO data ready is not detected 
 */
LOCAL_INLINE bool SDDF_HWA_GetChannelFIFODataReadyStatus(const SDDF_Type *const pSddf, uint8_t u8ChanIdx)
{
    uint32_t u32TmpVal = (pSddf->NISR & (SDDF_NISR_FRDY0_MASK << u8ChanIdx)) >> (SDDF_NISR_FRDY0_SHIFT + u8ChanIdx);
    return (u32TmpVal != 0U ? true : false);
}

/**
 * @brief Clear FIFO data ready flag of the selected channel
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the selected SDDF channel
 */
LOCAL_INLINE void SDDF_HWA_ClearChannelFIFODataReadyStatus(SDDF_Type *const pSddf, uint8_t u8ChanIdx)
{
    pSddf->NISR = SDDF_NISR_FRDY0_MASK << u8ChanIdx;
}

/**
 * @brief Get channel conversion complete status of the selected channel
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the selected SDDF channel
 * @return true channel conversion complete is detected
 * @return false channel conversion complete is not detected 
 */
LOCAL_INLINE bool SDDF_HWA_GetChannelConvCompleteStatus(const SDDF_Type *const pSddf, uint8_t u8ChanIdx)
{
    uint32_t u32TmpVal = (pSddf->NISR & (SDDF_NISR_COC0_MASK << u8ChanIdx)) >> (SDDF_NISR_COC0_SHIFT + u8ChanIdx);
    return (u32TmpVal != 0U ? true : false);
}

/**
 * @brief Clear channel conversion complete flag of the selected channel
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the selected SDDF channel
 */
LOCAL_INLINE void SDDF_HWA_ClearChannelConvCompleteStatus(SDDF_Type *const pSddf, uint8_t u8ChanIdx)
{
    pSddf->NISR = SDDF_NISR_COC0_MASK << u8ChanIdx;
}

/**
 * @brief Get the abnormal interrupt status 0 register (SDDF_ABNISR0) value
 * 
 * @param pSddf the base address of the SDDF instance
 * @return uint32_t the value of SDDF_ABNISR0 register
 */
LOCAL_INLINE uint32_t SDDF_HWA_GetAbnormalInterruptStatus0(const SDDF_Type *const pSddf)
{
    return pSddf->ABNISR0;
}

/**
 * @brief Clear the abnormal interrupt status 0 register (SDDF_ABNISR0) value
 * 
 * @param pSddf the base address of the SDDF instance
 */
LOCAL_INLINE void SDDF_HWA_ClearAbnormalInterruptStatus0(SDDF_Type *const pSddf)
{
    pSddf->ABNISR0 = SDDF_ABNISR0_MASK;
}

/**
 * @brief Get out of high limit range status of the selected channel
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the selected SDDF channel
 * @return true out of high limit range is detected
 * @return false out of high limit range is not detected 
 */
LOCAL_INLINE bool SDDF_HWA_GetChannelHighLimitStatus(const SDDF_Type *const pSddf, uint8_t u8ChanIdx)
{
    uint32_t u32TmpVal = (pSddf->ABNISR0 & (SDDF_ABNISR0_HLMT0_MASK << u8ChanIdx)) >> (SDDF_ABNISR0_HLMT0_SHIFT +
                         u8ChanIdx);
    return (u32TmpVal != 0U ? true : false);
}

/**
 * @brief Clear out of high limit range flag of the selected channel
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the selected SDDF channel
 */
LOCAL_INLINE void SDDF_HWA_ClearChannelHighLimitStatus(SDDF_Type *const pSddf, uint8_t u8ChanIdx)
{
    pSddf->ABNISR0 = SDDF_ABNISR0_HLMT0_MASK << u8ChanIdx;
}

/**
 * @brief Get out of low limit range status of the selected channel
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the selected SDDF channel
 * @return true out of low limit range is detected
 * @return false out of low limit range is not detected 
 */
LOCAL_INLINE bool SDDF_HWA_GetChannelLowLimitStatus(const SDDF_Type *const pSddf, uint8_t u8ChanIdx)
{
    uint32_t u32TmpVal = (pSddf->ABNISR0 & (SDDF_ABNISR0_LLMT0_MASK << u8ChanIdx)) >> (SDDF_ABNISR0_LLMT0_SHIFT +
                         u8ChanIdx);
    return (u32TmpVal != 0U ? true : false);
}

/**
 * @brief Clear out of low limit range flag of the selected channel
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the selected SDDF channel
 */
LOCAL_INLINE void SDDF_HWA_ClearChannelLowLimitStatus(SDDF_Type *const pSddf, uint8_t u8ChanIdx)
{
    pSddf->ABNISR0 = SDDF_ABNISR0_LLMT0_MASK << u8ChanIdx;
}

/**
 * @brief Get out of window limit range status of the selected channel
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the selected SDDF channel
 * @return true out of window limit range is detected
 * @return false out of window limit range is not detected 
 */
LOCAL_INLINE bool SDDF_HWA_GetChannelWindowLimitStatus(const SDDF_Type *const pSddf, uint8_t u8ChanIdx)
{
    uint32_t u32TmpVal = (pSddf->ABNISR0 & (SDDF_ABNISR0_WLMT0_MASK << u8ChanIdx)) >> (SDDF_ABNISR0_WLMT0_SHIFT +
                         u8ChanIdx);
    return (u32TmpVal != 0U ? true : false);
}

/**
 * @brief Clear out of window limit range flag of the selected channel
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the selected SDDF channel
 */
LOCAL_INLINE void SDDF_HWA_ClearChannelWindowLimitStatus(SDDF_Type *const pSddf, uint8_t u8ChanIdx)
{
    pSddf->ABNISR0 = SDDF_ABNISR0_WLMT0_MASK << u8ChanIdx;
}

/**
 * @brief Get short circuit detect status of the selected channel
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the selected SDDF channel
 * @return true short circuit is detected
 * @return false short circuit is not detected 
 */
LOCAL_INLINE bool SDDF_HWA_GetChannelShortCircuitDetectStatus(const SDDF_Type *const pSddf, uint8_t u8ChanIdx)
{
    uint32_t u32TmpVal = (pSddf->ABNISR0 & (SDDF_ABNISR0_SCD0_MASK << u8ChanIdx)) >> (SDDF_ABNISR0_SCD0_SHIFT + u8ChanIdx);
    return (u32TmpVal != 0U ? true : false);
}

/**
 * @brief Clear short circuit flag of the selected channel
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the selected SDDF channel
 */
LOCAL_INLINE void SDDF_HWA_ClearChannelShortCircuitDetectStatus(SDDF_Type *const pSddf, uint8_t u8ChanIdx)
{
    pSddf->ABNISR0 = SDDF_ABNISR0_SCD0_MASK << u8ChanIdx;
}

/**
 * @brief Get the abnormal interrupt status 1 register (SDDF_ABNISR1) value
 * 
 * @param pSddf the base address of the SDDF instance
 * @return uint32_t the value of SDDF_ABNISR1 register
 */
LOCAL_INLINE uint32_t SDDF_HWA_GetAbnormalInterruptStatus1(const SDDF_Type *const pSddf)
{
    return pSddf->ABNISR1;
}

/**
 * @brief Clear the abnormal interrupt status 0 register (SDDF_ABNISR0) value
 * 
 * @param pSddf the base address of the SDDF instance
 */
LOCAL_INLINE void SDDF_HWA_ClearAbnormalInterruptStatus1(SDDF_Type *const pSddf)
{
    pSddf->ABNISR1 = SDDF_ABNISR1_MASK;
}

/**
 * @brief Get result saturation status of the selected channel
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the selected SDDF channel
 * @return true result saturation is detected
 * @return false result saturation is not detected 
 */
LOCAL_INLINE bool SDDF_HWA_GetChannelSaturationStatus(const SDDF_Type *const pSddf, uint8_t u8ChanIdx)
{
    uint32_t u32TmpVal = (pSddf->ABNISR1 & (SDDF_ABNISR1_SAT0_MASK << u8ChanIdx)) >> (SDDF_ABNISR1_SAT0_SHIFT + u8ChanIdx);
    return (u32TmpVal != 0U ? true : false);
}

/**
 * @brief Clear result saturation flag of the selected channel
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the selected SDDF channel
 */
LOCAL_INLINE void SDDF_HWA_ClearChannelSaturationStatus(SDDF_Type *const pSddf, uint8_t u8ChanIdx)
{
    pSddf->ABNISR1 = SDDF_ABNISR1_SAT0_MASK << u8ChanIdx;
}

/**
 * @brief Get clock absence detect status of the selected channel
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the selected SDDF channel
 * @return true clock absence is detected
 * @return false clock absence is not detected 
 */
LOCAL_INLINE bool SDDF_HWA_GetChannelClockAbsenceStatus(const SDDF_Type *const pSddf, uint8_t u8ChanIdx)
{
    uint32_t u32TmpVal = (pSddf->ABNISR1 & (SDDF_ABNISR1_CAD0_MASK << u8ChanIdx)) >> (SDDF_ABNISR1_CAD0_SHIFT + u8ChanIdx);
    return (u32TmpVal != 0U ? true : false);
}

/**
 * @brief Clear clock absence flag of the selected channel
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the selected SDDF channel
 */
LOCAL_INLINE void SDDF_HWA_ClearChannelClockAbsenceStatus(SDDF_Type *const pSddf, uint8_t u8ChanIdx)
{
    pSddf->ABNISR1 = SDDF_ABNISR1_CAD0_MASK << u8ChanIdx;
}

/**
 * @brief Get FIFO overflow status of the selected channel
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the selected SDDF channel
 * @return true FIFO overflow is detected
 * @return false FIFO overflow is not detected 
 */
LOCAL_INLINE bool SDDF_HWA_GetChannelFIFOOverflowStatus(const SDDF_Type *const pSddf, uint8_t u8ChanIdx)
{
    uint32_t u32TmpVal = (pSddf->ABNISR1 & (SDDF_ABNISR1_FOVF0_MASK << u8ChanIdx)) >> (SDDF_ABNISR1_FOVF0_SHIFT +
                         u8ChanIdx);
    return (u32TmpVal != 0U ? true : false);
}

/**
 * @brief Clear FIFO overflow flag of the selected channel
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the selected SDDF channel
 */
LOCAL_INLINE void SDDF_HWA_ClearChannelFIFOOverflowStatus(SDDF_Type *const pSddf, uint8_t u8ChanIdx)
{
    pSddf->ABNISR1 = SDDF_ABNISR1_FOVF0_MASK << u8ChanIdx;
}

/**
 * @brief Get FIFO underflow status of the selected channel
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the selected SDDF channel
 * @return true FIFO underflow is detected
 * @return false FIFO underflow is not detected 
 */
LOCAL_INLINE bool SDDF_HWA_GetChannelFIFOUnderflowStatus(const SDDF_Type *const pSddf, uint8_t u8ChanIdx)
{
    uint32_t u32TmpVal = (pSddf->ABNISR1 & (SDDF_ABNISR1_FUNF0_MASK << u8ChanIdx)) >> (SDDF_ABNISR1_FUNF0_SHIFT +
                         u8ChanIdx);
    return (u32TmpVal != 0U ? true : false);
}

/**
 * @brief Clear FIFO underflow flag of the selected channel
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the selected SDDF channel
 */
LOCAL_INLINE void SDDF_HWA_ClearChannelFIFOUnderflowStatus(SDDF_Type *const pSddf, uint8_t u8ChanIdx)
{
    pSddf->ABNISR1 = SDDF_ABNISR1_FUNF0_MASK << u8ChanIdx;
}

/**
 * @brief Get main status of the selected channel
 * 
 * @param pSddf the base address of the SDDF instance
 * @return uint32_t the main status of the selected channel
 */
LOCAL_INLINE uint32_t SDDF_HWA_GetMainStatus(const SDDF_Type *const pSddf)
{
    return pSddf->MSR;
}

/**
 * @brief Get whether the modulator clock 2 output is ready
 * 
 * @param pSddf the base address of the SDDF instance
 * @return true the modulator clock 2 output is ready
 * @return false the modulator clock 2 output is not ready
 */
LOCAL_INLINE bool SDDF_HWA_GetClockOutput2ReadyFlag(const SDDF_Type *const pSddf)
{
    uint32_t u32TmpVal = (pSddf->MSR & SDDF_MSR_CLKO2_RDY_MASK) >> SDDF_MSR_CLKO2_RDY_SHIFT;
    return (u32TmpVal != 0U ? true : false);
}

/**
 * @brief Get whether the modulator clock 1 output is ready
 * 
 * @param pSddf the base address of the SDDF instance
 * @return true the modulator clock 1 output is ready
 * @return false the modulator clock 1 output is not ready
 */
LOCAL_INLINE bool SDDF_HWA_GetClockOutput1ReadyFlag(const SDDF_Type *const pSddf)
{
    uint32_t u32TmpVal = (pSddf->MSR & SDDF_MSR_CLKO1_RDY_MASK) >> SDDF_MSR_CLKO1_RDY_SHIFT;
    return (u32TmpVal != 0U ? true : false);
}

/**
 * @brief Get whether the modulator clock 0 output is ready
 * 
 * @param pSddf the base address of the SDDF instance
 * @return true the modulator clock 0 output is ready
 * @return false the modulator clock 0 output is not ready
 */
LOCAL_INLINE bool SDDF_HWA_GetClockOutput0ReadyFlag(const SDDF_Type *const pSddf)
{
    uint32_t u32TmpVal = (pSddf->MSR & SDDF_MSR_CLKO0_RDY_MASK) >> SDDF_MSR_CLKO0_RDY_SHIFT;
    return (u32TmpVal != 0U ? true : false);
}

/**
 * @brief Get whether conversion of the selected channel is ongoing
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the selected SDDF channel
 * @return true the conversion is ongoing
 * @return false the conversion is not ongoing
 */
LOCAL_INLINE bool SDDF_HWA_GetChannelConvOngoingStatus(const SDDF_Type *const pSddf, uint8_t u8ChanIdx)
{
    uint32_t u32TmpVal = (pSddf->MSR & (SDDF_MSR_CHON0_MASK << u8ChanIdx)) >> (SDDF_MSR_CHON0_MASK + u8ChanIdx);
    return (u32TmpVal != 0U ? true : false);
}

/**
 * @brief Get channel control reigister (SDDF_CCRn) value of the selected channel
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the selected SDDF channel
 * @return uint32_t the SDDF_CCRn register value
 */
LOCAL_INLINE uint32_t SDDF_HWA_GetChannelControl(const SDDF_Type *const pSddf, uint8_t u8ChanIdx)
{
    return pSddf->CH[u8ChanIdx].CCR;
}

/**
 * @brief Set channel control reigister (SDDF_CCRn) value of the selected channel
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the selected SDDF channel
 * @param u32Ctrl the SDDF_CCRn register value to set
 */
LOCAL_INLINE void SDDF_HWA_SetChannelControl(SDDF_Type *const pSddf, uint8_t u8ChanIdx, uint32_t u32Ctrl)
{
    pSddf->CH[u8ChanIdx].CCR = u32Ctrl;
}

/**
 * @brief Get the result input source of channel limit check
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the selected SDDF channel
 * @return SDDF_InputSrcType the result input source of channel limit check
 */
LOCAL_INLINE SDDF_InputSrcType SDDF_HWA_GetChannelLimitCheckInputSrc(const SDDF_Type *const pSddf, uint8_t u8ChanIdx)
{
    uint32_t u32TmpVal = (pSddf->CH[u8ChanIdx].CCR & SDDF_CCR_LMT_SEL_MASK) >> SDDF_CCR_LMT_SEL_SHIFT;
    return (SDDF_InputSrcType)u32TmpVal;
}

/**
 * @brief Set the result input source of the channel limit check
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the selected SDDF channel
 * @param eSrc the result input source of channel limit check
 */
LOCAL_INLINE void SDDF_HWA_SetChannelLimitCheckInputSrc(SDDF_Type *const pSddf, uint8_t u8ChanIdx,
                                                        SDDF_InputSrcType eSrc)
{
    pSddf->CH[u8ChanIdx].CCR = (pSddf->CH[u8ChanIdx].CCR & ~SDDF_CCR_LMT_SEL_MASK) | SDDF_CCR_LMT_SEL(eSrc);
}

/**
 * @brief Get the result input source of channel zero cross check
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the selected SDDF channel
 * @return SDDF_InputSrcType the result input source of channel zero cross check
 */
LOCAL_INLINE SDDF_InputSrcType SDDF_HWA_GetChannelZeroCrossCheckInputSrc(const SDDF_Type *const pSddf,
                                                                         uint8_t u8ChanIdx)
{
    uint32_t u32TmpVal = (pSddf->CH[u8ChanIdx].CCR & SDDF_CCR_ZCD_SEL_MASK) >> SDDF_CCR_ZCD_SEL_SHIFT;
    return (SDDF_InputSrcType)u32TmpVal;
}

/**
 * @brief Set the result input source of the channel zero cross check
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the selected SDDF channel
 * @param eSrc the result input source of channel zero cross check
 */
LOCAL_INLINE void SDDF_HWA_SetChannelZeroCrossCheckInputSrc(SDDF_Type *const pSddf, uint8_t u8ChanIdx,
                                                            SDDF_InputSrcType eSrc)
{
    pSddf->CH[u8ChanIdx].CCR = (pSddf->CH[u8ChanIdx].CCR & ~SDDF_CCR_ZCD_SEL_MASK) | SDDF_CCR_ZCD_SEL(eSrc);
}

/**
 * @brief Get whether FIFO is enabled for the selected channel
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the selected SDDF channel
 * @return true FIFO is enabled for the selected channel
 * @return false FIFO is disabled for the selected channel
 */
LOCAL_INLINE bool SDDF_HWA_GetChannelFIFOEnableFlag(const SDDF_Type *const pSddf, uint8_t u8ChanIdx)
{
    uint32_t u32TmpVal = (pSddf->CH[u8ChanIdx].CCR & SDDF_CCR_FIFO_EN_MASK) >> SDDF_CCR_FIFO_EN_SHIFT;
    return (u32TmpVal != 0U ? true : false);
}

/**
 * @brief Set whether to enable FIFO for the selected channel
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the selected SDDF channel
 * @param bEnable whether to enable FIFO for the selected channel
 */
LOCAL_INLINE void SDDF_HWA_SetChannelFIFOEnableFlag(SDDF_Type *const pSddf, uint8_t u8ChanIdx, bool bEnable)
{
    pSddf->CH[u8ChanIdx].CCR = (pSddf->CH[u8ChanIdx].CCR & ~SDDF_CCR_FIFO_EN_MASK) | SDDF_CCR_FIFO_EN(bEnable);
}

/**
 * @brief Get whether limit check is enabled for the selected channel
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the selected SDDF channel
 * @return true limit check is enabled for the selected channel
 * @return false limit check is disabled for the selected channel
 */
LOCAL_INLINE bool SDDF_HWA_GetChannelLimitCheckEnableFlag(const SDDF_Type *const pSddf, uint8_t u8ChanIdx)
{
    uint32_t u32TmpVal = (pSddf->CH[u8ChanIdx].CCR & SDDF_CCR_LMT_EN_MASK) >> SDDF_CCR_LMT_EN_SHIFT;
    return (u32TmpVal != 0U ? true : false);
}

/**
 * @brief Set whether to enable limit check for the selected channel
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the selected SDDF channel
 * @param bEnable whether to enable limit check for the selected channel
 */
LOCAL_INLINE void SDDF_HWA_SetChannelLimitCheckEnableFlag(SDDF_Type *const pSddf, uint8_t u8ChanIdx, bool bEnable)
{
    pSddf->CH[u8ChanIdx].CCR = (pSddf->CH[u8ChanIdx].CCR & ~SDDF_CCR_LMT_EN_MASK) | SDDF_CCR_LMT_EN(bEnable);
}

/**
 * @brief Get whether zero cross detect is enabled for the selected channel
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the selected SDDF channel
 * @return true zero cross detect is enabled for the selected channel
 * @return false zero cross detect is disabled for the selected channel
 */
LOCAL_INLINE bool SDDF_HWA_GetChannelZeroCrossDetectEnableFlag(const SDDF_Type *const pSddf, uint8_t u8ChanIdx)
{
    uint32_t u32TmpVal = (pSddf->CH[u8ChanIdx].CCR & SDDF_CCR_ZCD_EN_MASK) >> SDDF_CCR_ZCD_EN_SHIFT;
    return (u32TmpVal != 0U ? true : false);
}

/**
 * @brief Set whether to enable zero cross detect for the selected channel
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the selected SDDF channel
 * @param bEnable whether to enable zero cross detect for the selected channel
 */
LOCAL_INLINE void SDDF_HWA_SetChannelZeroCrossDetectEnableFlag(SDDF_Type *const pSddf, uint8_t u8ChanIdx, bool bEnable)
{
    pSddf->CH[u8ChanIdx].CCR = (pSddf->CH[u8ChanIdx].CCR & ~SDDF_CCR_ZCD_EN_MASK) | SDDF_CCR_ZCD_EN(bEnable);
}

/**
 * @brief Get whether clocl absence detect is enabled for the selected channel
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the selected SDDF channel
 * @return true clocl absence detect is enabled for the selected channel
 * @return false clocl absence detect is disabled for the selected channel
 */
LOCAL_INLINE bool SDDF_HWA_GetChannelClockAbsenceDetectEnableFlag(const SDDF_Type *const pSddf, uint8_t u8ChanIdx)
{
    uint32_t u32TmpVal = (pSddf->CH[u8ChanIdx].CCR & SDDF_CCR_CAD_EN_MASK) >> SDDF_CCR_CAD_EN_SHIFT;
    return (u32TmpVal != 0U ? true : false);
}

/**
 * @brief Set whether to enable clocl absence detect for the selected channel
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the selected SDDF channel
 * @param bEnable whether to enable clocl absence detect for the selected channel
 */
LOCAL_INLINE void SDDF_HWA_SetChannelClockAbsenceDetectEnableFlag(SDDF_Type *const pSddf, uint8_t u8ChanIdx,
                                                                  bool bEnable)
{
    pSddf->CH[u8ChanIdx].CCR = (pSddf->CH[u8ChanIdx].CCR & ~SDDF_CCR_CAD_EN_MASK) | SDDF_CCR_CAD_EN(bEnable);
}

/**
 * @brief Get whether short circuit detect is enabled for the selected channel
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the selected SDDF channel
 * @return true short circuit detect is enabled for the selected channel
 * @return false short circuit detect is disabled for the selected channel
 */
LOCAL_INLINE bool SDDF_HWA_GetChannelShortCircuitDetectEnableFlag(const SDDF_Type *const pSddf, uint8_t u8ChanIdx)
{
    uint32_t u32TmpVal = (pSddf->CH[u8ChanIdx].CCR & SDDF_CCR_SCD_EN_MASK) >> SDDF_CCR_SCD_EN_SHIFT;
    return (u32TmpVal != 0U ? true : false);
}

/**
 * @brief Set whether to enable short circuit detect for the selected channel
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the selected SDDF channel
 * @param bEnable whether to enable short circuit detect for the selected channel
 */
LOCAL_INLINE void SDDF_HWA_SetChannelShortCircuitDetectEnableFlag(SDDF_Type *const pSddf, uint8_t u8ChanIdx,
                                                                  bool bEnable)
{
    pSddf->CH[u8ChanIdx].CCR = (pSddf->CH[u8ChanIdx].CCR & ~SDDF_CCR_SCD_EN_MASK) | SDDF_CCR_SCD_EN(bEnable);
}

/**
 * @brief Get whether DMA is enabled for the selected channel
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the selected SDDF channel
 * @return true DMA is enabled for the selected channel
 * @return false DMA is disabled for the selected channel
 */
LOCAL_INLINE bool SDDF_HWA_GetChannelDMAEnableFlag(const SDDF_Type *const pSddf, uint8_t u8ChanIdx)
{
    uint32_t u32TmpVal = (pSddf->CH[u8ChanIdx].CCR & SDDF_CCR_DMA_EN_MASK) >> SDDF_CCR_DMA_EN_SHIFT;
    return (u32TmpVal != 0U ? true : false);
}

/**
 * @brief Set whether to enable DMA for the selected channel
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the selected SDDF channel
 * @param bEnable whether to enable DMA for the selected channel
 */
LOCAL_INLINE void SDDF_HWA_SetChannelDMAEnableFlag(SDDF_Type *const pSddf, uint8_t u8ChanIdx, bool bEnable)
{
    pSddf->CH[u8ChanIdx].CCR = (pSddf->CH[u8ChanIdx].CCR & ~SDDF_CCR_DMA_EN_MASK) | SDDF_CCR_DMA_EN(bEnable);
}

/**
 * @brief Get whether auxiliary filter is enabled for the selected channel
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the selected SDDF channel
 * @return true auxiliary filter is enabled for the selected channel
 * @return false auxiliary filter is disabled for the selected channel
 */
LOCAL_INLINE bool SDDF_HWA_GetChannelAuxiliaryFilterEnableFlag(const SDDF_Type *const pSddf, uint8_t u8ChanIdx)
{
    uint32_t u32TmpVal = (pSddf->CH[u8ChanIdx].CCR & SDDF_CCR_AF_EN_MASK) >> SDDF_CCR_AF_EN_SHIFT;
    return (u32TmpVal != 0U ? true : false);
}

/**
 * @brief Set whether to enable auxiliary filter for the selected channel
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the selected SDDF channel
 * @param bEnable whether to enable auxiliary filter for the selected channel
 */
LOCAL_INLINE void SDDF_HWA_SetChannelAuxiliaryFilterEnableFlag(SDDF_Type *const pSddf, uint8_t u8ChanIdx, bool bEnable)
{
    pSddf->CH[u8ChanIdx].CCR = (pSddf->CH[u8ChanIdx].CCR & ~SDDF_CCR_AF_EN_MASK) | SDDF_CCR_AF_EN(bEnable);
}

/**
 * @brief Get whether main filter is enabled for the selected channel
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the selected SDDF channel
 * @return true main filter is enabled for the selected channel
 * @return false main filter is disabled for the selected channel
 */
LOCAL_INLINE bool SDDF_HWA_GetChannelMainFilterEnableFlag(const SDDF_Type *const pSddf, uint8_t u8ChanIdx)
{
    uint32_t u32TmpVal = (pSddf->CH[u8ChanIdx].CCR & SDDF_CCR_MF_EN_MASK) >> SDDF_CCR_MF_EN_SHIFT;
    return (u32TmpVal != 0U ? true : false);
}

/**
 * @brief Set whether to enable main filter for the selected channel
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the selected SDDF channel
 * @param bEnable whether to enable main filter for the selected channel
 */
LOCAL_INLINE void SDDF_HWA_SetChannelMainFilterEnableFlag(SDDF_Type *const pSddf, uint8_t u8ChanIdx, bool bEnable)
{
    pSddf->CH[u8ChanIdx].CCR = (pSddf->CH[u8ChanIdx].CCR & ~SDDF_CCR_MF_EN_MASK) | SDDF_CCR_MF_EN(bEnable);
}

/**
 * @brief Get whether the selected channel is enabled
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the selected SDDF channel
 * @return true the selected channel is enabled
 * @return false the selected channel is disabled
 */
LOCAL_INLINE bool SDDF_HWA_GetChannelEnableFlag(const SDDF_Type *const pSddf, uint8_t u8ChanIdx)
{
    uint32_t u32TmpVal = (pSddf->CH[u8ChanIdx].CCR & SDDF_CCR_CH_EN_MASK) >> SDDF_CCR_CH_EN_SHIFT;
    return (u32TmpVal != 0U ? true : false);
}

/**
 * @brief Set whether to enable the selected channel
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the selected SDDF channel
 * @param bEnable whether to enable the selected channel
 */
LOCAL_INLINE void SDDF_HWA_SetChannelEnableFlag(SDDF_Type *const pSddf, uint8_t u8ChanIdx, bool bEnable)
{
    pSddf->CH[u8ChanIdx].CCR = (pSddf->CH[u8ChanIdx].CCR & ~SDDF_CCR_CH_EN_MASK) | SDDF_CCR_CH_EN(bEnable);
}

/**
 * @brief Get the data rate register (SDDF_CDRn) value of the selected channel
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the selected SDDF channel
 * @return uint32_t the data rate register value of the selected channel
 */
LOCAL_INLINE uint32_t SDDF_HWA_GetChannelDataRate(const SDDF_Type *const pSddf, uint8_t u8ChanIdx)
{
    return pSddf->CH[u8ChanIdx].CDR;
}

/**
 * @brief Set the data rate register (SDDF_CDRn) value of the selected channel
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the selected SDDF channel
 * @param u32DataRate the data rate register value to set of the selected channel
 */
LOCAL_INLINE void SDDF_HWA_SetChannelDataRate(SDDF_Type *const pSddf, uint8_t u8ChanIdx, uint32_t u32DataRate)
{
    pSddf->CH[u8ChanIdx].CDR = u32DataRate;
}

/**
 * @brief Get the auxiliary filter conversion mode of the selected channel
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the selected SDDF channel
 * @return SDDF_AuxFilterConvModeType the auxiliary filter conversion mode
 */
LOCAL_INLINE SDDF_AuxFilterConvModeType SDDF_HWA_GetChannelAuxiliaryFilterConvMode(const SDDF_Type *const pSddf,
        uint8_t u8ChanIdx)
{
    uint32_t u32TmpVal = (pSddf->CH[u8ChanIdx].CDR & SDDF_CDR_AFCM_MASK) >> SDDF_CDR_AFCM_SHIFT;
    return (SDDF_AuxFilterConvModeType)u32TmpVal;
}

/**
 * @brief Set the auxiliary filter conversion mode of the selected channel
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the selected SDDF channel
 * @param eConvMode the auxiliary filter conversion mode
 */
LOCAL_INLINE void SDDF_HWA_SetChannelAuxiliaryFilterConvMode(SDDF_Type *const pSddf, uint8_t u8ChanIdx,
                                                             SDDF_AuxFilterConvModeType eConvMode)
{
    pSddf->CH[u8ChanIdx].CDR = (pSddf->CH[u8ChanIdx].CDR & ~SDDF_CDR_AFCM_MASK) | SDDF_CDR_AFCM(eConvMode);
}

/**
 * @brief Get the auxiliary filter order of the selected channel
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the selected SDDF channel
 * @return SDDF_AuxFilterOrderType the auxiliary filter order
 */
LOCAL_INLINE SDDF_AuxFilterOrderType SDDF_HWA_GetChannelAuxiliaryFilterOrder(const SDDF_Type *const pSddf,
                                                                             uint8_t u8ChanIdx)
{
    uint32_t u32TmpVal = (pSddf->CH[u8ChanIdx].CDR & SDDF_CDR_AFORD_MASK) >> SDDF_CDR_AFORD_SHIFT;
    return (SDDF_AuxFilterOrderType)u32TmpVal;
}

/**
 * @brief Set the auxiliary filter order of the selected channel
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the selected SDDF channel
 * @param eOrder the auxiliary filter order
 */
LOCAL_INLINE void SDDF_HWA_SetChannelAuxiliaryFilterOrder(SDDF_Type *const pSddf, uint8_t u8ChanIdx,
                                                          SDDF_AuxFilterOrderType eOrder)
{
    pSddf->CH[u8ChanIdx].CDR = (pSddf->CH[u8ChanIdx].CDR & ~SDDF_CDR_AFORD_MASK) | SDDF_CDR_AFORD(eOrder);
}

/**
 * @brief Get the auxiliary filter oversampling rate of the selected channel
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the selected SDDF channel
 * @return uint32_t the auxiliary filter oversampling rate
 */
LOCAL_INLINE uint32_t SDDF_HWA_GetChannelAuxiliaryFilterOversampleRate(const SDDF_Type *const pSddf, uint8_t u8ChanIdx)
{
    uint32_t u32TmpVal = (pSddf->CH[u8ChanIdx].CDR & SDDF_CDR_AFOSR_MASK) >> SDDF_CDR_AFOSR_SHIFT;
    return (u32TmpVal + 1U);
}

/**
 * @brief Set the auxiliary filter oversampling rate of the selected channel
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the selected SDDF channel
 * @param u32SampleRate the auxiliary filter oversampling rate
 */
LOCAL_INLINE void SDDF_HWA_SetChannelAuxiliaryFilterOversampleRate(SDDF_Type *const pSddf, uint8_t u8ChanIdx,
                                                                   uint32_t u32SampleRate)
{
    DEV_ASSERT(u32SampleRate >= 4U);
#ifndef NDEBUG
    if (SDDF_HWA_GetChannelAuxiliaryFilterOrder(pSddf, u8ChanIdx) == SDDF_AUX_FILTER_THIRD_ORDER)
    {
        DEV_ASSERT(u32SampleRate <= 203U);
    }
    else
    {
        DEV_ASSERT(u32SampleRate <= 512U);
    }
#endif
    pSddf->CH[u8ChanIdx].CDR = (pSddf->CH[u8ChanIdx].CDR & ~SDDF_CDR_AFOSR_MASK) | SDDF_CDR_AFOSR(u32SampleRate - 1U);
}

/**
 * @brief Get the main filter conversion mode of the selected channel
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the selected SDDF channel
 * @return SDDF_AuxFilterConvModeType the main filter conversion mode
 */
LOCAL_INLINE SDDF_MainFilterConvModeType SDDF_HWA_GetChannelMainFilterConvMode(const SDDF_Type *const pSddf,
                                                                               uint8_t u8ChanIdx)
{
    uint32_t u32TmpVal = (pSddf->CH[u8ChanIdx].CDR & SDDF_CDR_MFCM_MASK) >> SDDF_CDR_MFCM_SHIFT;
    return (SDDF_MainFilterConvModeType)u32TmpVal;
}

/**
 * @brief Set the main filter conversion mode of the selected channel
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the selected SDDF channel
 * @param eConvMode the main filter conversion mode
 */
LOCAL_INLINE void SDDF_HWA_SetChannelMainFilterConvMode(SDDF_Type *const pSddf, uint8_t u8ChanIdx,
                                                        SDDF_MainFilterConvModeType eConvMode)
{
    pSddf->CH[u8ChanIdx].CDR = (pSddf->CH[u8ChanIdx].CDR & ~SDDF_CDR_MFCM_MASK) | SDDF_CDR_MFCM(eConvMode);
}

/**
 * @brief Get the main filter order of the selected channel
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the selected SDDF channel
 * @return SDDF_AuxFilterOrderType the main filter order
 */
LOCAL_INLINE SDDF_MainFilterOrderType SDDF_HWA_GetChannelMainFilterOrder(const SDDF_Type *const pSddf,
                                                                         uint8_t u8ChanIdx)
{
    uint32_t u32TmpVal = (pSddf->CH[u8ChanIdx].CDR & SDDF_CDR_MFORD_MASK) >> SDDF_CDR_MFORD_SHIFT;
    return (SDDF_MainFilterOrderType)u32TmpVal;
}

/**
 * @brief Set the main filter order of the selected channel
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the selected SDDF channel
 * @param eOrder the main filter order
 */
LOCAL_INLINE void SDDF_HWA_SetChannelMainFilterOrder(SDDF_Type *const pSddf, uint8_t u8ChanIdx,
                                                     SDDF_MainFilterOrderType eOrder)
{
    pSddf->CH[u8ChanIdx].CDR = (pSddf->CH[u8ChanIdx].CDR & ~SDDF_CDR_MFORD_MASK) | SDDF_CDR_MFORD(eOrder);
}

/**
 * @brief Get the main filter oversampling rate of the selected channel
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the selected SDDF channel
 * @return uint32_t the main filter oversampling rate
 */
LOCAL_INLINE uint32_t SDDF_HWA_GetChannelMainFilterOversampleRate(const SDDF_Type *const pSddf, uint8_t u8ChanIdx)
{
    uint32_t u32TmpVal = (pSddf->CH[u8ChanIdx].CDR & SDDF_CDR_MFOSR_MASK) >> SDDF_CDR_MFOSR_SHIFT;
    return (u32TmpVal + 1U);
}

/**
 * @brief Set the main filter oversampling rate of the selected channel
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the selected SDDF channel
 * @param u32SampleRate the main filter oversampling rate
 */
LOCAL_INLINE void SDDF_HWA_SetChannelMainFilterOversampleRate(SDDF_Type *const pSddf, uint8_t u8ChanIdx,
                                                              uint32_t u32SampleRate)
{
    DEV_ASSERT(u32SampleRate >= 4U);
#ifndef NDEBUG
    if (SDDF_HWA_GetChannelMainFilterOrder(pSddf, u8ChanIdx) == SDDF_MAIN_FILTER_FOURTH_ORDER)
    {
        DEV_ASSERT(u32SampleRate <= 204U);
    }
    else if (SDDF_HWA_GetChannelMainFilterOrder(pSddf, u8ChanIdx) == SDDF_MAIN_FILTER_FIFTH_ORDER)
    {
        DEV_ASSERT(u32SampleRate <= 73U);
    }
    else
    {
        DEV_ASSERT(u32SampleRate <= 512U);
    }
#endif
    pSddf->CH[u8ChanIdx].CDR = (pSddf->CH[u8ChanIdx].CDR & ~SDDF_CDR_AFOSR_MASK) | SDDF_CDR_AFOSR(u32SampleRate - 1U);
}

/**
 * @brief Get the configuration register (SDDF_CFRn) value of the selected channel
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the selected SDDF channel
 * @return uint32_t the channel configuration register value
 */
LOCAL_INLINE uint32_t SDDF_HWA_GetChannelConfig(const SDDF_Type *const pSddf, uint8_t u8ChanIdx)
{
    return pSddf->CH[u8ChanIdx].CFR;
}

/**
 * @brief Set the configuration register (SDDF_CFRn) value of the selected channel
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the selected SDDF channel
 * @param u32Config the channel configuration register value to set
 */
LOCAL_INLINE void SDDF_HWA_SetChannelConfig(SDDF_Type *const pSddf, uint8_t u8ChanIdx, uint32_t u32Config)
{
    pSddf->CH[u8ChanIdx].CFR = u32Config;
}

/**
 * @brief Get the trigger level type of the selected channel
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the selected SDDF channel
 * @return SDDF_TriggerEventType the trigger level type
 */
LOCAL_INLINE SDDF_TriggerEventType SDDF_HWA_GetChannelTriggerEvent(const SDDF_Type *const pSddf, uint8_t u8ChanIdx)
{
    uint32_t u32TmpVal = (pSddf->CH[u8ChanIdx].CFR & SDDF_CFR_TRGLVL_MASK) >> SDDF_CFR_TRGLVL_SHIFT;
    return (SDDF_TriggerEventType)u32TmpVal;
}

/**
 * @brief Set the trigger level type of the selected channel
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the selected SDDF channel
 * @param eEvent the trigger level type
 */
LOCAL_INLINE void SDDF_HWA_SetChannelTriggerEvent(SDDF_Type *const pSddf, uint8_t u8ChanIdx,
                                                  SDDF_TriggerEventType eEvent)
{
    pSddf->CH[u8ChanIdx].CFR = (pSddf->CH[u8ChanIdx].CFR & ~SDDF_CFR_TRGLVL_MASK) | SDDF_CFR_TRGLVL(eEvent);
}

/**
 * @brief Get the trigger source type of the selected channel
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the selected SDDF channel
 * @return SDDF_TriggerSrcType the trigger source type
 */
LOCAL_INLINE SDDF_TriggerSrcType SDDF_HWA_GetChannelTriggerSource(const SDDF_Type *const pSddf, uint8_t u8ChanIdx)
{
    uint32_t u32TmpVal = (pSddf->CH[u8ChanIdx].CFR & SDDF_CFR_TRGSEL_MASK) >> SDDF_CFR_TRGSEL_SHIFT;
    return (SDDF_TriggerSrcType)u32TmpVal;
}

/**
 * @brief Set the trigger source type of the selected channel
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the selected SDDF channel
 * @param eSrc the trigger source type
 */
LOCAL_INLINE void SDDF_HWA_SetChannelTriggerSource(SDDF_Type *const pSddf, uint8_t u8ChanIdx, SDDF_TriggerSrcType eSrc)
{
    pSddf->CH[u8ChanIdx].CFR = (pSddf->CH[u8ChanIdx].CFR & ~SDDF_CFR_TRGSEL_MASK) | SDDF_CFR_TRGSEL(eSrc);
}

/**
 * @brief Get the clock edge for conversion of the selected channel
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the selected SDDF channel
 * @return SDDF_ClockEdgeType the input clock edge
 */
LOCAL_INLINE SDDF_ClockEdgeType SDDF_HWA_GetChannelInputClockEdge(const SDDF_Type *const pSddf, uint8_t u8ChanIdx)
{
    uint32_t u32TmpVal = (pSddf->CH[u8ChanIdx].CFR & SDDF_CFR_CLKEDG_MASK) >> SDDF_CFR_CLKEDG_SHIFT;
    return (SDDF_ClockEdgeType)u32TmpVal;
}

/**
 * @brief Set the clock edge for conversion of the selected channel
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the selected SDDF channel
 * @param eClkEdge the input clock edge
 */
LOCAL_INLINE void SDDF_HWA_SetChannelInputClockEdge(SDDF_Type *const pSddf, uint8_t u8ChanIdx,
                                                    SDDF_ClockEdgeType eClkEdge)
{
    pSddf->CH[u8ChanIdx].CFR = (pSddf->CH[u8ChanIdx].CFR & ~SDDF_CFR_CLKEDG_MASK) | SDDF_CFR_CLKEDG(eClkEdge);
}

/**
 * @brief Get the input clock select of the selected channel
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the selected SDDF channel
 * @return SDDF_ClockSrcType the input clock select
 */
LOCAL_INLINE SDDF_ClockSrcType SDDF_HWA_GetChannelInputClockSource(const SDDF_Type *const pSddf, uint8_t u8ChanIdx)
{
    uint32_t u32TmpVal = (pSddf->CH[u8ChanIdx].CFR & SDDF_CFR_CLKSEL_MASK) >> SDDF_CFR_CLKSEL_SHIFT;
    return (SDDF_ClockSrcType)u32TmpVal;
}

/**
 * @brief Set the input clock select of the selected channel
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the selected SDDF channel
 * @param eSrc the input clock select
 */
LOCAL_INLINE void SDDF_HWA_SetChannelInputClockSource(SDDF_Type *const pSddf, uint8_t u8ChanIdx, SDDF_ClockSrcType eSrc)
{
    pSddf->CH[u8ChanIdx].CFR = (pSddf->CH[u8ChanIdx].CFR & ~SDDF_CFR_CLKSEL_MASK) | SDDF_CFR_CLKSEL(eSrc);
}

/**
 * @brief Get the input bit format of the selected channel
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the selected SDDF channel
 * @return SDDF_BitFormatType the input bit format
 */
LOCAL_INLINE SDDF_BitFormatType SDDF_HWA_GetChannelInputBitFormat(const SDDF_Type *const pSddf, uint8_t u8ChanIdx)
{
    uint32_t u32TmpVal = (pSddf->CH[u8ChanIdx].CFR & SDDF_CFR_IBFMT_MASK) >> SDDF_CFR_IBFMT_SHIFT;
    return (SDDF_BitFormatType)u32TmpVal;
}

/**
 * @brief Set the input bit format of the selected channel
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the selected SDDF channel
 * @param eFormat the input bit format
 */
LOCAL_INLINE void SDDF_HWA_SetChannelInputBitFormat(SDDF_Type *const pSddf, uint8_t u8ChanIdx,
                                                    SDDF_BitFormatType eFormat)
{
    pSddf->CH[u8ChanIdx].CFR = (pSddf->CH[u8ChanIdx].CFR & ~SDDF_CFR_IBFMT_MASK) | SDDF_CFR_IBFMT(eFormat);
}

/**
 * @brief Get the FIFO watermark of the selected channel
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the selected SDDF channel
 * @return uint8_t the FIFO watermark of the selected channel
 */
LOCAL_INLINE uint8_t SDDF_HWA_GetChannelFIFOWatermark(const SDDF_Type *const pSddf, uint8_t u8ChanIdx)
{
    uint32_t u32TmpVal = (pSddf->CH[u8ChanIdx].CFR & SDDF_CFR_FWMK_MASK) >> SDDF_CFR_FWMK_SHIFT;
    return (uint8_t)u32TmpVal;
}

/**
 * @brief Set the FIFO watermark of the selected channel
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the selected SDDF channel
 * @param u8Watermark the FIFO watermark of the selected channel
 */
LOCAL_INLINE void SDDF_HWA_SetChannelFIFOWatermark(SDDF_Type *const pSddf, uint8_t u8ChanIdx, uint8_t u8Watermark)
{
    pSddf->CH[u8ChanIdx].CFR = (pSddf->CH[u8ChanIdx].CFR & ~SDDF_CFR_FWMK_MASK) | SDDF_CFR_FWMK(u8Watermark);
}

/**
 * @brief Get the result data format of the selected channel
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the selected SDDF channel
 * @return SDDF_ResultFormatType the result data format of the selected channel
 */
LOCAL_INLINE SDDF_ResultFormatType SDDF_HWA_GetChannelResultDataFormat(const SDDF_Type *const pSddf, uint8_t u8ChanIdx)
{
    uint32_t u32TmpVal = (pSddf->CH[u8ChanIdx].CFR & SDDF_CFR_RDFMT_MASK) >> SDDF_CFR_RDFMT_SHIFT;
    return (SDDF_ResultFormatType)u32TmpVal;
}

/**
 * @brief Set the result data format of the selected channel
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the selected SDDF channel
 * @param eFormat the result data format of the selected channel
 */
LOCAL_INLINE void SDDF_HWA_SetChannelResultDataFormat(SDDF_Type *const pSddf, uint8_t u8ChanIdx,
                                                      SDDF_ResultFormatType eFormat)
{
    pSddf->CH[u8ChanIdx].CFR = (pSddf->CH[u8ChanIdx].CFR & ~SDDF_CFR_RDFMT_MASK) | SDDF_CFR_RDFMT(eFormat);
}

/**
 * @brief Get the main filter shift of the selected channel
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the selected SDDF channel
 * @return SDDF_MainFilterShiftType the main filter shift of the selected channel
 */
LOCAL_INLINE SDDF_MainFilterShiftType SDDF_HWA_GetChannelMainFilterShift(const SDDF_Type *const pSddf,
                                                                         uint8_t u8ChanIdx)
{
    uint32_t u32TmpVal = (pSddf->CH[u8ChanIdx].CFR & SDDF_CFR_MFSHIFT_MASK) >> SDDF_CFR_MFSHIFT_SHIFT;
    if (u32TmpVal == 16U)
    {
        u32TmpVal = 0U;
    }
    return (SDDF_MainFilterShiftType)u32TmpVal;
}

/**
 * @brief Set the main filter shift to get correct 24 bit precision of the selected channel
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the selected SDDF channel
 * @param eShift the main filter shift to set
 */
LOCAL_INLINE void SDDF_HWA_SetChannelMainFilterShift(SDDF_Type *const pSddf, uint8_t u8ChanIdx,
                                                     SDDF_MainFilterShiftType eShift)
{
    pSddf->CH[u8ChanIdx].CFR = (pSddf->CH[u8ChanIdx].CFR & ~SDDF_CFR_MFSHIFT_MASK) | SDDF_CFR_RDFMT(eShift);
}

/**
 * @brief Get the protection settings (SDDF_CPRn) value of the selected channel
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the selected SDDF channel
 * @return uint32_t the protection settings (SDDF_CPRn) value
 */
LOCAL_INLINE uint32_t SDDF_HWA_GetChannelProtectionConfig(const SDDF_Type *const pSddf, uint8_t u8ChanIdx)
{
    return pSddf->CH[u8ChanIdx].CPR;
}

/**
 * @brief Set the protection settings (SDDF_CPRn) value of the selected channel
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the selected SDDF channel
 * @param u32Config the protection settings (SDDF_CPRn) value
 */
LOCAL_INLINE void SDDF_HWA_SetChannelProtectionConfig(SDDF_Type *const pSddf, uint8_t u8ChanIdx, uint32_t u32Config)
{
    pSddf->CH[u8ChanIdx].CPR = u32Config;
}

/**
 * @brief Get whether the high limit break signal is enabled for the selected channel
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the selected SDDF channel
 * @return true the high limit break signal is enabled for the selected channel
 * @return false the high limit break signal is disabled for the selected channel
 */
LOCAL_INLINE bool SDDF_HWA_GetChannelHighLimitBreakSignalEnableFlag(const SDDF_Type *const pSddf, uint8_t u8ChanIdx)
{
    uint32_t u32TmpVal = (pSddf->CH[u8ChanIdx].CPR & SDDF_CPR_HLMT_BKEN_MASK) >> SDDF_CPR_HLMT_BKEN_SHIFT;
    return (u32TmpVal != 0U ? true : false);
}

/**
 * @brief Set whether to enable high limit break signal for the selected channel
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the selected SDDF channel
 * @param bEnable whether to enable high limit break signal for the selected channel
 */
LOCAL_INLINE void SDDF_HWA_SetChannelHighLimitBreakSignalEnableFlag(SDDF_Type *const pSddf, uint8_t u8ChanIdx,
                                                                    bool bEnable)
{
    pSddf->CH[u8ChanIdx].CPR = (pSddf->CH[u8ChanIdx].CPR & ~SDDF_CPR_HLMT_BKEN_MASK) | SDDF_CPR_HLMT_BKEN(bEnable);
}

/**
 * @brief Get whether the window limit break signal is enabled for the selected channel
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the selected SDDF channel
 * @return true the window limit break signal is enabled for the selected channel
 * @return false the window limit break signal is disabled for the selected channel
 */
LOCAL_INLINE bool SDDF_HWA_GetChannelWindowLimitBreakSignalEnableFlag(const SDDF_Type *const pSddf, uint8_t u8ChanIdx)
{
    uint32_t u32TmpVal = (pSddf->CH[u8ChanIdx].CPR & SDDF_CPR_WLMT_BKEN_MASK) >> SDDF_CPR_WLMT_BKEN_SHIFT;
    return (u32TmpVal != 0U ? true : false);
}

/**
 * @brief Set whether to enable window limit break signal for the selected channel
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the selected SDDF channel
 * @param bEnable whether to enable window limit break signal for the selected channel
 */
LOCAL_INLINE void SDDF_HWA_SetChannelWindowLimitBreakSignalEnableFlag(SDDF_Type *const pSddf, uint8_t u8ChanIdx,
                                                                      bool bEnable)
{
    pSddf->CH[u8ChanIdx].CPR = (pSddf->CH[u8ChanIdx].CPR & ~SDDF_CPR_WLMT_BKEN_MASK) | SDDF_CPR_WLMT_BKEN(bEnable);
}

/**
 * @brief Get whether the low limit break signal is enabled for the selected channel
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the selected SDDF channel
 * @return true the low limit break signal is enabled for the selected channel
 * @return false the low limit break signal is disabled for the selected channel
 */
LOCAL_INLINE bool SDDF_HWA_GetChannelLowLimitBreakSignalEnableFlag(const SDDF_Type *const pSddf, uint8_t u8ChanIdx)
{
    uint32_t u32TmpVal = (pSddf->CH[u8ChanIdx].CPR & SDDF_CPR_LLMT_BKEN_MASK) >> SDDF_CPR_LLMT_BKEN_SHIFT;
    return (u32TmpVal != 0U ? true : false);
}

/**
 * @brief Set whether to enable low limit break signal for the selected channel
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the selected SDDF channel
 * @param bEnable whether to enable low limit break signal for the selected channel
 */
LOCAL_INLINE void SDDF_HWA_SetChannelLowLimitBreakSignalEnableFlag(SDDF_Type *const pSddf, uint8_t u8ChanIdx,
                                                                   bool bEnable)
{
    pSddf->CH[u8ChanIdx].CPR = (pSddf->CH[u8ChanIdx].CPR & ~SDDF_CPR_LLMT_BKEN_MASK) | SDDF_CPR_LLMT_BKEN(bEnable);
}

/**
 * @brief Get whether short circuit detect break signal is enabled for the selected channel
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the selected SDDF channel
 * @return true short circuit detect break signal is enabled for the selected channel
 * @return false short circuit detect break signal is disabled for the selected channel
 */
LOCAL_INLINE bool SDDF_HWA_GetChannelShortCircuitBreakSignalEnableFlag(const SDDF_Type *const pSddf, uint8_t u8ChanIdx)
{
    uint32_t u32TmpVal = (pSddf->CH[u8ChanIdx].CPR & SDDF_CPR_SCD_BKEN_MASK) >> SDDF_CPR_SCD_BKEN_SHIFT;
    return (u32TmpVal != 0U ? true : false);
}

/**
 * @brief Set whether to enable short circuit detect break signal for the selected channel
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the selected SDDF channel
 * @param bEnable whether to enable short circuit detect break signal for the selected channel
 */
LOCAL_INLINE void SDDF_HWA_SetChannelShortCircuitBreakSignalEnableFlag(SDDF_Type *const pSddf, uint8_t u8ChanIdx,
                                                                       bool bEnable)
{
    pSddf->CH[u8ChanIdx].CPR = (pSddf->CH[u8ChanIdx].CPR & ~SDDF_CPR_SCD_BKEN_MASK) | SDDF_CPR_SCD_BKEN(bEnable);
}

/**
 * @brief Get whether clock absence detect break signal is enabled for the selected channel
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the selected SDDF channel
 * @return true clock absence detect break signal is enabled for the selected channel
 * @return false clock absence detect break signal is disabled for the selected channel
 */
LOCAL_INLINE bool SDDF_HWA_GetChannelClockAbsenceBreakSignalEnableFlag(const SDDF_Type *const pSddf, uint8_t u8ChanIdx)
{
    uint32_t u32TmpVal = (pSddf->CH[u8ChanIdx].CPR & SDDF_CPR_CAD_BKEN_MASK) >> SDDF_CPR_CAD_BKEN_SHIFT;
    return (u32TmpVal != 0U ? true : false);
}

/**
 * @brief Set whether to enable clock absence detect break signal for the selected channel
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the selected SDDF channel
 * @param bEnable whether to enable clock absence detect break signal for the selected channel
 */
LOCAL_INLINE void SDDF_HWA_SetChannelClockAbsenceBreakSignalEnableFlag(SDDF_Type *const pSddf, uint8_t u8ChanIdx,
                                                                       bool bEnable)
{
    pSddf->CH[u8ChanIdx].CPR = (pSddf->CH[u8ChanIdx].CPR & ~SDDF_CPR_CAD_BKEN_MASK) | SDDF_CPR_CAD_BKEN(bEnable);
}

/**
 * @brief Get the clock absence detector limitation threshold
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the selected SDDF channel
 * @return uint8_t the clock absence detector limitation threshold
 */
LOCAL_INLINE uint8_t SDDF_HWA_GetChannelClockAbsenceLimitThreshold(const SDDF_Type *const pSddf, uint8_t u8ChanIdx)
{
    uint32_t u32TmpVal = (pSddf->CH[u8ChanIdx].CPR & SDDF_CPR_CADLMT_MASK) >> SDDF_CPR_CADLMT_SHIFT;
    return (uint8_t)u32TmpVal;
}

/**
 * @brief Set the clock absence detector limitation threshold
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the selected SDDF channel
 * @param u8Thres the clock absence detector limitation threshold
 */
LOCAL_INLINE void SDDF_HWA_SetChannelClockAbsenceLimitThreshold(SDDF_Type *const pSddf, uint8_t u8ChanIdx,
                                                                uint8_t u8Thres)
{
    pSddf->CH[u8ChanIdx].CPR = (pSddf->CH[u8ChanIdx].CPR & ~SDDF_CPR_CADLMT_MASK) | SDDF_CPR_CADLMT(u8Thres);
}

/**
 * @brief Get the channel limit check option
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the selected SDDF channel
 * @return SDDF_ChannelLimitOptionType the channel limit check option
 */
LOCAL_INLINE SDDF_ChannelLimitOptionType SDDF_HWA_GetChannelLimitOption(const SDDF_Type *const pSddf, uint8_t u8ChanIdx)
{
    uint32_t u32TmpVal = (pSddf->CH[u8ChanIdx].CPR & SDDF_CPR_LMTOPT_MASK) >> SDDF_CPR_LMTOPT_SHIFT;
    return (SDDF_ChannelLimitOptionType)u32TmpVal;
}

/**
 * @brief Set the channel limit check option
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the selected SDDF channel
 * @param eOption the channel limit check option
 */
LOCAL_INLINE void SDDF_HWA_SetChannelLimitOption(SDDF_Type *const pSddf, uint8_t u8ChanIdx,
                                                 SDDF_ChannelLimitOptionType eOption)
{
    pSddf->CH[u8ChanIdx].CPR = (pSddf->CH[u8ChanIdx].CPR & ~SDDF_CPR_LMTOPT_MASK) | SDDF_CPR_LMTOPT(eOption);
}

/**
 * @brief Get the channel short circuit detect option
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the selected SDDF channel
 * @return SDDF_ShortCircuitOptionType the channel short circuit detect option
 */
LOCAL_INLINE SDDF_ShortCircuitOptionType SDDF_HWA_GetChannelShortCircuitOption(const SDDF_Type *const pSddf,
                                                                               uint8_t u8ChanIdx)
{
    uint32_t u32TmpVal = (pSddf->CH[u8ChanIdx].CPR & SDDF_CPR_SCDOPT_MASK) >> SDDF_CPR_SCDOPT_SHIFT;
    return (SDDF_ShortCircuitOptionType)u32TmpVal;
}

/**
 * @brief Set the channel short circuit detect option
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the selected SDDF channel
 * @param eOption the channel short circuit detect option
 */
LOCAL_INLINE void SDDF_HWA_SetChannelShortCircuitOption(SDDF_Type *const pSddf, uint8_t u8ChanIdx,
                                                        SDDF_ShortCircuitOptionType eOption)
{
    pSddf->CH[u8ChanIdx].CPR = (pSddf->CH[u8ChanIdx].CPR & ~SDDF_CPR_SCDOPT_MASK) | SDDF_CPR_SCDOPT(eOption);
}

/**
 * @brief Get the channel short circuit detect conversion mode
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the selected SDDF channel
 * @return SDDF_ShortCircuitDetectModeType the channel short circuit detect conversion mode
 */
LOCAL_INLINE SDDF_ShortCircuitDetectModeType SDDF_HWA_GetShortCircuitDetectMode(const SDDF_Type *const pSddf,
                                                                                uint8_t u8ChanIdx)
{
    uint32_t u32TmpVal = (pSddf->CH[u8ChanIdx].CPR & SDDF_CPR_SCDCM_MASK) >> SDDF_CPR_SCDCM_SHIFT;
    return (SDDF_ShortCircuitDetectModeType)u32TmpVal;
}

/**
 * @brief Set the channel short circuit detect conversion mode
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the selected SDDF channel
 * @param eMode the channel short circuit detect conversion mode
 */
LOCAL_INLINE void SDDF_HWA_SetShortCircuitDetectMode(SDDF_Type *const pSddf, uint8_t u8ChanIdx,
                                                     SDDF_ShortCircuitDetectModeType eMode)
{
    pSddf->CH[u8ChanIdx].CPR = (pSddf->CH[u8ChanIdx].CPR & ~SDDF_CPR_SCDCM_MASK) | SDDF_CPR_SCDCM(eMode);
}

/**
 * @brief Get the threshold value for short circuit detector counter of the selected channel
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the selected SDDF channel
 * @return uint8_t the threshold value for short circuit detector counter
 */
LOCAL_INLINE uint8_t SDDF_HWA_GetShortCircuitLimitThreshold(const SDDF_Type *const pSddf, uint8_t u8ChanIdx)
{
    uint32_t u32TmpVal = (pSddf->CH[u8ChanIdx].CPR & SDDF_CPR_SCDLMT_MASK) >> SDDF_CPR_SCDLMT_SHIFT;
    return (uint8_t)u32TmpVal;
}

/**
 * @brief Set the threshold value for short circuit detector counter of the selected channel
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the selected SDDF channel
 * @param u8Thres the threshold value for short circuit detector counter
 */
LOCAL_INLINE void SDDF_HWA_SetShortCircuitLimitThreshold(SDDF_Type *const pSddf, uint8_t u8ChanIdx, uint8_t u8Thres)
{
    pSddf->CH[u8ChanIdx].CPR = (pSddf->CH[u8ChanIdx].CPR & ~SDDF_CPR_SCDLMT_MASK) | SDDF_CPR_SCDLMT(u8Thres);
}

/**
 * @brief Get the bias value for the selected channel main filter
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the selected SDDF channel
 * @return int32_t the bias value for result adjustment or compensation
 */
LOCAL_INLINE int32_t SDDF_HWA_GetChannelBias(const SDDF_Type *const pSddf, uint8_t u8ChanIdx)
{
    return (int32_t)pSddf->CH[u8ChanIdx].CBR;
}

/**
 * @brief Set the bias value for the selected channel main filter
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the selected SDDF channel
 * @param s32Bias the bias value for result adjustment or compensation
 */
LOCAL_INLINE void SDDF_HWA_SetChannelBias(SDDF_Type *const pSddf, uint8_t u8ChanIdx, int32_t s32Bias)
{
    pSddf->CH[u8ChanIdx].CBR = (uint32_t)s32Bias;
}

/**
 * @brief Get the low limit threshold for limit check of the selected channel
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the selected SDDF channel
 * @return uint32_t the low limit threshold
 */
LOCAL_INLINE uint32_t SDDF_HWA_GetChannelLowLimit(const SDDF_Type *const pSddf, uint8_t u8ChanIdx)
{
    return pSddf->CH[u8ChanIdx].CLLMT;
}

/**
 * @brief Set the low limit threshold for limit check of the selected channel
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the selected SDDF channel
 * @param u32LowLimit the low limit threshold
 */
LOCAL_INLINE void SDDF_HWA_SetChannelLowLimit(SDDF_Type *const pSddf, uint8_t u8ChanIdx, uint32_t u32LowLimit)
{
    pSddf->CH[u8ChanIdx].CLLMT = u32LowLimit;
}

/**
 * @brief Get the high limit threshold for limit check of the selected channel
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the selected SDDF channel
 * @return uint32_t the high limit threshold
 */
LOCAL_INLINE uint32_t SDDF_HWA_GetChannelHighLimit(const SDDF_Type *const pSddf, uint8_t u8ChanIdx)
{
    return pSddf->CH[u8ChanIdx].CHLMT;
}

/**
 * @brief Set the high limit threshold for limit check of the selected channel
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the selected SDDF channel
 * @param u32HighLimit the high limit threshold
 */
LOCAL_INLINE void SDDF_HWA_SetChannelHighLimit(SDDF_Type *const pSddf, uint8_t u8ChanIdx, uint32_t u32HighLimit)
{
    pSddf->CH[u8ChanIdx].CHLMT = u32HighLimit;
}

/**
 * @brief Get the result data of the selected channel
 * 
 * @param pSddf the base address of the SDDF instance
 * @param u8ChanIdx the selected SDDF channel
 * @return uint32_t the result data
 */
LOCAL_INLINE uint32_t SDDF_HWA_GetChannelData(const SDDF_Type *const pSddf, uint8_t u8ChanIdx)
{
    return pSddf->CH[u8ChanIdx].CRDATA;
}

/** @}*/

#endif /* #if SDDF_INSTANCE_COUNT > 0U */

#endif /* _HWA_SDDF_H_ */
