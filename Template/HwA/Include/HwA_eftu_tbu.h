/**
 * @file HwA_eftu_tbu.h
 * @author flagchip
 * @brief Hardware access layer for EFTU TBU
 * @version 2.0.0
 * @date 2024-08-20
 *
 * SDK Version: 2.6.0
 *

 * @copyright Copyright (c) 2024 Flagchip Semiconductors Co., Ltd.
 *
 */
/* ********************************************************************************
   *   Revision History:
   *
   *   Version     Date          Initials      CR#          Descriptions
   *   ---------   ----------    ------------  ----------   ---------------
   *   0.1.0      2023-12-15     Flagchip030   N/A          First version for FC7300
   *   2.0.0      2024-10-12     Flagchip099   N/A          Change version and release
   ******************************************************************************** */

#ifndef _HWA_EFTU_TBU_H_
#define _HWA_EFTU_TBU_H_
#include "device_header.h"

#if EFTU_INSTANCE_COUNT > 0U
/********* Local typedef ************/
/**
 * @brief Select the EFTU TBU clock source.
 *
 */
typedef enum
{
    EFTU_TBU_CMU_CLK0 = 0U,
    EFTU_TBU_CMU_CLK1,
    EFTU_TBU_CMU_CLK2,
    EFTU_TBU_CMU_CLK3,
    EFTU_TBU_CMU_CLK4,
    EFTU_TBU_CMU_CLK5,
    EFTU_TBU_CMU_CLK6,
    EFTU_TBU_CMU_CLK7
} EFTU_TBU_ClkSrcType;

/*
*@brief Select the EFTU channel_0 register resolution.
*/
typedef enum
{
    EFTU_TBU_CNT0_0_23BIT = 0U,
    EFTU_TBU_CNT0_3_26BIT
} EFTU_TBU_Ch0ResType;

/*
*@brief Select the EFTU channel x
*/
typedef enum
{
    EFTU_TBU_CNT0 = 0U,
    EFTU_TBU_CNT1,
    EFTU_TBU_CNT2,
    EFTU_TBU_CNT3,
    EFTU_TBU_MAX
} EFTU_TBU_ChnCntType;

/*
*@brief Select the EFTU TBU CNT3 QD mode
*/
typedef enum
{
    EFTU_TBU_QD_DIR_MODE = 0U,
    EFTU_TBU_QD_PHA_MODE,
} EFTU_TBU_QDModeType;

typedef enum
{
    EFTU_TBU_INSTANCE = 0U,
} EFTU_TBU_InstanceType;

/*
*@brief Channel selector for modulo counter. Only for channel 3
*/
typedef enum
{
    EFTU0_CNT_TIM0_1 = 0U,
    EFTU0_CNT_TIM2_3 = 1U,
} EFTU_TBU_QDInputSrcType;

/********* Local inline function ************/
/*
 * @brief enable Tbu channel
*/
LOCAL_INLINE void EFTU_TBU_HWA_EnableChannel(EFTU_TBU_Type *const pTbu, EFTU_TBU_ChnCntType eChannel)
{
    pTbu->CNTEN = (0x2U << (uint8_t)(eChannel * 2u));
}

/*
 * @brief disable Tbu channel
*/
LOCAL_INLINE void EFTU_TBU_HWA_DisableChannel(EFTU_TBU_Type *const pTbu, EFTU_TBU_ChnCntType eChannel)
{
    pTbu->CNTEN = (0x1U << (uint8_t)(eChannel * 2u));
}

/**
 * @brief select the clock src of the channel 0
 * */
LOCAL_INLINE void EFTU_TBU_HWA_SetTs0Src(EFTU_TBU_Type *const pTbu, EFTU_TBU_ClkSrcType eClkSrc)
{
    pTbu->CNT0_CTRL |= EFTU_TBU_CNT0_CTRL_CNT_CLK_SRC(eClkSrc);
}

/**
 * @brief select the clock src of the channel 0
 * */
LOCAL_INLINE void EFTU_TBU_HWA_SetTs1Src(EFTU_TBU_Type *const pTbu, EFTU_TBU_ClkSrcType eClkSrc)
{
    pTbu->CNT1_CTRL |= EFTU_TBU_CNT1_CTRL_CNT_CLK_SRC(eClkSrc);
}

/**
 * @brief select the clock src of the channel 0
 * */
LOCAL_INLINE void EFTU_TBU_HWA_SetTs2Src(EFTU_TBU_Type *const pTbu, EFTU_TBU_ClkSrcType eClkSrc)
{
    pTbu->CNT2_CTRL |= EFTU_TBU_CNT2_CTRL_CNT_CLK_SRC(eClkSrc);
}


/**
 * @brief select the time base register of the channel 0 provided to the sub module.
*/
LOCAL_INLINE void EFTU_TBU_HWA_SetChannel0BaseReg(EFTU_TBU_Type *const pTbu, EFTU_TBU_Ch0ResType eTbuch0base)
{
    pTbu->CNT0_CTRL |= EFTU_TBU_CNT0_CTRL_LOW_RES(eTbuch0base);
}

/**
 * @brief  get the  TBU_TSx.
 */
LOCAL_INLINE uint32_t EFTU_TBU_HWA_GetChannelTS0(const EFTU_TBU_Type *const pTbu)
{
    return (uint32_t)(pTbu->CNT0_BASE & EFTU_TBU_CNT0_BASE_BASE_MASK);
}

/**
 * @brief  get the  TBU_TSx.
 */
LOCAL_INLINE uint32_t EFTU_TBU_HWA_GetChannelTS1(const EFTU_TBU_Type *const pTbu)
{

    return (uint32_t)(pTbu->CNT1_BASE & EFTU_TBU_CNT1_BASE_BASE_MASK);

}
/**
 * @brief  get the  TBU_TSx.
 */
LOCAL_INLINE uint32_t EFTU_TBU_HWA_GetChannelTS2(const EFTU_TBU_Type *const pTbu)
{

    return (uint32_t)(pTbu->CNT2_BASE & EFTU_TBU_CNT2_BASE_BASE_MASK);

}
/**
 * @brief  get the  TBU_TSx.
 */
LOCAL_INLINE uint32_t EFTU_TBU_HWA_GetChannelTS3(const EFTU_TBU_Type *const pTbu)
{
    return (uint32_t)(pTbu->CNT3_BASE & EFTU_TBU_CNT3_BASE_BASE_MASK);
}
/**
 * @brief Set the TBU_TS0 base
*/
LOCAL_INLINE  void EFTU_TBU_HWA_SetChannelTS0(EFTU_TBU_Type *const pTbu, uint32 u32TimeValue)
{
    pTbu->CNT0_BASE = (pTbu->CNT0_BASE & ~EFTU_TBU_CNT0_BASE_BASE_MASK)|EFTU_TBU_CNT0_BASE_BASE(u32TimeValue);
}

/**
 * @brief Set the TBU_TS1 base
*/
LOCAL_INLINE  void EFTU_TBU_HWA_SetChannelTS1(EFTU_TBU_Type *const pTbu, uint32 u32TimeValue)
{
    pTbu->CNT1_BASE =(pTbu->CNT1_BASE & ~EFTU_TBU_CNT1_BASE_BASE_MASK) | EFTU_TBU_CNT1_BASE_BASE(u32TimeValue);
}
/**
 * @brief Set the TBU_TS2 base
*/
LOCAL_INLINE  void EFTU_TBU_HWA_SetChannelTS2(EFTU_TBU_Type *const pTbu, uint32 u32TimeValue)
{
    pTbu->CNT2_BASE =(pTbu->CNT2_BASE & ~EFTU_TBU_CNT2_BASE_BASE_MASK)|EFTU_TBU_CNT2_BASE_BASE(u32TimeValue);
}
/**
 * @brief Set the TBU_TS3 base
*/
LOCAL_INLINE  void EFTU_TBU_HWA_SetChannelTS3(EFTU_TBU_Type *const pTbu, uint32 u32TimeValue)
{
    pTbu->CNT3_BASE = (pTbu->CNT3_BASE & ~EFTU_TBU_CNT3_BASE_BASE_MASK)|EFTU_TBU_CNT3_BASE_BASE(u32TimeValue);
}

/**
 * @brief configure channel 3 mode
*/
LOCAL_INLINE void EFTU_TBU_HWA_SetChannel3Mode(EFTU_TBU_Type *const pTbu, EFTU_TBU_QDModeType eTbuch3Mode)
{
    pTbu->CNT3_CTRL = (pTbu->CNT3_CTRL & ~EFTU_TBU_CNT3_CTRL_CNT_MODE_MASK)|EFTU_TBU_CNT3_CTRL_CNT_MODE(eTbuch3Mode);
}

/**
 * @brief configure channel 3 src for modulo counter
*/
LOCAL_INLINE void EFTU_TBU_HWA_SetChannel3Src(EFTU_TBU_Type *const pTbu, EFTU_TBU_QDInputSrcType eTbuch3CounterSrc)
{
    pTbu->CNT3_CTRL =(pTbu->CNT3_CTRL & ~EFTU_TBU_CNT3_CTRL_USE_CNT2_MASK)|EFTU_TBU_CNT3_CTRL_USE_CNT2(eTbuch3CounterSrc);
}

/**
 * @brief configure channel 3 Modulo value
*/
LOCAL_INLINE void EFTU_TBU_HWA_SetChannel3MARK(EFTU_TBU_Type *const pTbu, uint32 u32mark)
{
    pTbu->CNT3_MARK = (pTbu->CNT3_MARK & ~EFTU_TBU_CNT3_MARK_MARK_MASK)|EFTU_TBU_CNT3_MARK_MARK(u32mark);
}

/**
 * @brief get channel 3 Modulo value
*/
LOCAL_INLINE uint32_t EFTU_TBU_HWA_GetChannel3MARK(EFTU_TBU_Type *const pTbu)
{
    return (uint32_t)pTbu->CNT3_MARK;
}

/**
 * @brief get channel 3 capture value
*/
LOCAL_INLINE uint32_t EFTU_TBU_HWA_GetChannel3Capture(EFTU_TBU_Type *const pTbu)
{
    return (uint32_t)pTbu->CNT3_CAPTURE;
}

#if (EFTU_EAC_SUPPORT == STD_ON)

/**
 * @brief Insert dummy physical tooth for exiting halt mode
*/
LOCAL_INLINE void EFTU_TBU_HWA_SetIph(EFTU_TBU_Type *const pTbu)
{
    pTbu->EAC_TPR |=  EFTU_TBU_EAC_TPR_IPH_MASK;
}

/**
 * @brief Force EAC halt
*/
LOCAL_INLINE void EFTU_TBU_HWA_HoldEac(EFTU_TBU_Type *const pTbu)
{
    pTbu->EAC_TPR |=  EFTU_TBU_EAC_TPR_HOLD_MASK;
}

/**
 * @brief Last Tooth Indication
*/
LOCAL_INLINE void EFTU_TBU_HWA_SetLast(EFTU_TBU_Type *const pTbu)
{
    pTbu->EAC_TPR |=  EFTU_TBU_EAC_TPR_LAST_MASK;
}

/**
 * @brief Angle Ticks Number in the Current Tooth
*/
LOCAL_INLINE void EFTU_TBU_HWA_SetTicks(EFTU_TBU_Type *const pTbu,uint32 u32Ticks)
{
    pTbu->EAC_TPR |=  EFTU_TBU_EAC_TPR_TICKS(u32Ticks);
}

/**
 * @brief Misscnt Tooth Counter
*/
LOCAL_INLINE void EFTU_TBU_HWA_SetMisscnt(EFTU_TBU_Type *const pTbu,uint32 u32MissCnt)
{
    pTbu->EAC_TPR |=  EFTU_TBU_EAC_TPR_MISSCNT(u32MissCnt);
}

/**
 * @brief set EAC TRR value
*/
LOCAL_INLINE void EFTU_TBU_HWA_SetTrr(EFTU_TBU_Type *const pTbu,uint32_t u32TrrValue)
{
    pTbu->EAC_TRR = u32TrrValue;
}


/**
 * @brief The value of the window start is used to determine the start of the
 * window for the next tooth
*/
LOCAL_INLINE void EFTU_TBU_HWA_SetStartWin(EFTU_TBU_Type *const pTbu,uint32_t u32StartWin)
{
    pTbu->EAC_WINDOW_S = ((0x1U<<24)|u32StartWin);
}

/**
 * @brief The value of the window start is used to determine the End of the
 * window for the next tooth
*/
LOCAL_INLINE void EFTU_TBU_HWA_SetEndWin(EFTU_TBU_Type *const pTbu,uint32_t u32EndWin)
{
    pTbu->EAC_WINDOW_E = ((0x1U<<24)|u32EndWin);
}



/**
 * @brief Set the EAC control register
 */
LOCAL_INLINE void  EFTU_TBU_HWA_SetCtrl(EFTU_TBU_Type *const pTbu,uint32_t u32CtrlValue)
{
    pTbu->EAC_CTRL = u32CtrlValue;
}


/**
 * @brief Clear the counter value to zero
 */
LOCAL_INLINE void  EFTU_TBU_HWA_EacSwClearCnt(EFTU_TBU_Type *const pTbu)
{
    pTbu->EAC_CTRL |= EFTU_TBU_EAC_CTRL_CNT_SW_CLR_MASK;
}

/**
 * @brief EAC is halted until a physical tooth is detected
 */
LOCAL_INLINE void  EFTU_TBU_HWA_HaltEac(EFTU_TBU_Type *const pTbu)
{
    pTbu->EAC_CTRL |= EFTU_TBU_EAC_CTRL_HALT_ENABLE_MASK;
}

/**
 * @brief Get the last measured time
 */
LOCAL_INLINE uint32  EFTU_TBU_HWA_GetLastMeasTime(EFTU_TBU_Type *const pTbu)
{
    return (uint32_t)(pTbu->EAC_CNTS & 0xFFFFFF );
}

/**
 * @brief Get the last last measured time
 */
LOCAL_INLINE uint32_t  EFTU_TBU_HWA_GetCnt(EFTU_TBU_Type *const pTbu)
{
    return (uint32_t)(pTbu->EAC_CNT & 0xFFFFFF );
}

/**
 * @brief Get the last last measured time
 */
LOCAL_INLINE uint8_t  EFTU_TBU_HWA_GetDetectCounter(EFTU_TBU_Type *const pTbu)
{
    return (uint8_t)((pTbu->EAC_CNTS & EFTU_TBU_EAC_CNTS_CH_CNTS_MASK) >> EFTU_TBU_EAC_CNTS_CH_CNTS_SHIFT) ;
}

/**
 * @brief Set the last last measured time
 */
LOCAL_INLINE void   EFTU_TBU_HWA_SetCnts(EFTU_TBU_Type *const pTbu,uint32_t u32CntsValue)
{
    pTbu->EAC_CNTS |= EFTU_TBU_EAC_CNTS_CH_CNTS_WE_SHIFT |  EFTU_TBU_EAC_CNTS_CNTS(u32CntsValue);
}


/**
 * @brief Set the detect counter
 */
LOCAL_INLINE void   EFTU_TBU_HWA_SetCntsCounter(EFTU_TBU_Type *const pTbu,uint8_t u8Counter)
{
    pTbu->EAC_CNTS |= EFTU_TBU_EAC_CNTS_CH_CNTS(u8Counter);
}


/**
 * @brief Enable timeout interrupt
 */
LOCAL_INLINE void   EFTU_TBU_HWA_EACEnTimeoutIRQ(EFTU_TBU_Type *const pTbu)
{
    pTbu->EAC_IRQEN |= EFTU_TBU_EAC_IRQEN_TOOTH_TO_IEN_MASK;
}

/**
 * @brief Enable error interrupt
 */
LOCAL_INLINE void   EFTU_TBU_HWA_EACEnErrIRQ(EFTU_TBU_Type *const pTbu)
{
    pTbu->EAC_IRQEN |= EFTU_TBU_EAC_IRQEN_TOOTH_ERR_IEN_MASK;
}

/**
 * @brief Enable detect interrupt
 */
LOCAL_INLINE void   EFTU_TBU_HWA_EACEnDetIRQ(EFTU_TBU_Type *const pTbu)
{
    pTbu->EAC_IRQEN |= EFTU_TBU_EAC_STAT_TOOTH_DET_MASK;
}


/**
 * @brief Disable timeout interrupt
 */
LOCAL_INLINE void   EFTU_TBU_HWA_EACDisTimeoutIRQ(EFTU_TBU_Type *const pTbu)
{
    pTbu->EAC_IRQEN &= ~EFTU_TBU_EAC_IRQEN_TOOTH_TO_IEN_MASK;
}

/**
 * @brief Disable error interrupt
 */
LOCAL_INLINE void   EFTU_TBU_HWA_EACDisErrIRQ(EFTU_TBU_Type *const pTbu)
{
    pTbu->EAC_IRQEN &= ~EFTU_TBU_EAC_IRQEN_TOOTH_ERR_IEN_MASK;
}

/**
 * @brief Disable detect interrupt
 */
LOCAL_INLINE void   EFTU_TBU_HWA_EACDisDetIRQ(EFTU_TBU_Type *const pTbu)
{
    pTbu->EAC_IRQEN  &= ~EFTU_TBU_EAC_STAT_TOOTH_DET_MASK;
}

/**
 * @brief get interrupt status
 */
 
LOCAL_INLINE  uint32_t EFTU_TBU_HWA_EacGetIrqflag(EFTU_TBU_Type *const pTbu)
{
    return   (uint32_t)pTbu->EAC_STAT;
}

/**
 * @brief get interrupt status
 */
 
LOCAL_INLINE  void EFTU_TBU_HWA_EacClearIrqflag(EFTU_TBU_Type *const pTbu,uint32_t u32Mask)
{
    pTbu->EAC_STAT = u32Mask;
}

#endif	/* EFTU_EAC_SUPPORT */

#endif 	/* EFTU_INSTANCE_COUNT*/

#endif  /*#ifndef _HWA_EFTU_TBU_H_*/
