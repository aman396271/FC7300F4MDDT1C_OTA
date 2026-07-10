/**
 * @file HwA_eftu_tim.h
 * @author flagchip
 * @brief Hardware access layer for EFTU TIM
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

#ifndef _HWA_EFTU_TIM_H_
#define _HWA_EFTU_TIM_H_
#include "device_header.h"

#if EFTU_INSTANCE_COUNT > 0U

/********* Local typedef ************/
/**
 * @get Tim Filter counter Frequency Selection.
*/
typedef enum
{
	EFTU_TIM_FLT_CMUCLK0 = 0U,
	EFTU_TIM_FLT_CMUCLK1 = 1U,
	EFTU_TIM_FLT_CMUCLK6 = 2U,
	EFTU_TIM_FLT_CMUCLK7 = 3U
}EFTU_TIM_FltSrcType;

typedef  enum
{
	EFTU_TIM_CMU_CLK0 = 0U,
	EFTU_TIM_CMU_CLK1 = 1U,
	EFTU_TIM_CMU_CLK2 = 2U,
	EFTU_TIM_CMU_CLK3 = 3U,
	EFTU_TIM_CMU_CLK4 = 4U,
	EFTU_TIM_CMU_CLK5 = 5U,
	EFTU_TIM_CMU_CLK6 = 6U,
	EFTU_TIM_CMU_CLK7 = 7U,
}EFTU_TIM_ClockSrcType;


/*Tim Input Timeout EDGE*/
typedef enum
{
	EFTU_TIM_TIMEOUT_DIS          = 0U,
	EFTU_TIM_TIMEOUT_RISING_EDGE  = 1U,
	EFTU_TIM_TIMEOUT_FALLING_EDGE = 2U,
	EFTU_TIM_TIMEOUT_BOTH_EDGE    = 3U,

}EFTU_TIM_TimeOutEdgeType;


typedef enum
{
	EFTU_TO_CNT2_CLOCK_CMU_CLK = 0U,
	EFTU_TO_CNT_CLOCK_SAMPLE_EVT = 1U,
}EFTU_TIM_TduCnt2ClkType;

typedef enum
{
	EFTU_TO_CNT1_CLOCK_WORD_EVENT = 0U,
	EFTU_TO_CNT1_CLOCK_TO_CNT     = 1U,
}EFTU_TIM_TduCnt1ClkType;

typedef enum
{
	EFTU_TDU_24BIT_OR_RESERVED 		= 0U,
	EFTU_TDU_16BIT_8BIT_OR_16BIT 	= 1U,
	EFTU_TDU_3_8BIT_OR_2_8BIT		= 2U,
	EFTU_TDU_2_8BIT_OR_2_8BIT		= 3U
}EFTU_TIM_TduSlicType;

/**
 *@brief TBU0_TS0 select bit
*/
typedef enum
{
	EFTU_TIM_TBU_TS0_0_23BIT = 0U,
	EFTU_TIM_TBU_TS0_3_26BIT = 1U
}EFTU_TIM_TbuTs0ResType;

typedef enum
{
	EFTU_TIM_ACTIVE_FALLINGEDGE = 0U,
	EFTU_TIM_ACTIVE_RISINGEDGE = 1U,
	EFTU_TIM_ACTIVE_BOTHEDGE	= 2U,/*just for TIEM TIPM mode*/
}EFTU_TIM_ActiveEdgeType;

/**
 * @get Tim tdu counter timeout  sensitive edge.
*/
typedef enum
{
	EFTU_TIM_TDU_DISABLE = 0U,
	EFTU_TIM_TDU_RISING_EDGE = 1U,
	EFTU_TIM_TDU_FALLING_EDGE = 2U,
	EFTU_TIM_TDU_BOTH_EDGE = 3U
}EFTU_TIM_TduEdgeType;

/**
 * @brief Tim Channel Mode
*/
typedef enum
{
    EFTU_TIM_MODE_PWMMEASUREMENT    = 0U,            /**< \brief TPWM */
    EFTU_TIM_MODE_PULSEINTEGRATION  = 1U,           /**< \brief TPIM */
    EFTU_TIM_MODE_INPUTEVENT        = 2U,           /**< \brief TIEM */
    EFTU_TIM_MODE_PRESCALER         = 3U,           /**< \brief TIPM */
    EFTU_TIM_MODE_BITCOMPRESSION    = 4U,           /**< \brief TBCM */
    EFTU_TIM_MODE_PERIODICSAMPLING  = 5U,           /**< \brief TGPS */
    EFTU_TIM_MODE_SERIALSHIFT       = 6U            /**< \brief TSSM */
}EFTU_TiM_ChannelModeType;

/**
 * @brief GPR0 select mux
*/
typedef enum
{
    EFTU_TIM_GPTSEL_TBUTS0  		= 0U,
    EFTU_TIM_GPTSEL_TBUTS1   		= 1U,
    EFTU_TIM_GPTSEL_TBUTS2   		= 2U,
    EFTU_TIM_GPTSEL_CNTS_OR_CNT    = 3U,      /*For GPR0 CNTS;For GPR1 CNT*/
	EFTU_GPTSEL_CH_ECNT      		= 4U,
	EFTU_GPTSEL_TIM_INP_VAL  		= 5U,
}EFTU_TIM_GprSrcType;



typedef enum
{
    EFTU_TIM_CNTS_CNT       = 0U,
    EFTU_TIM_CNTS_TBUTS0    = 1u
}EFTU_TIM_CntsSrcType;


typedef enum
{
	EFTU_TIM_TPWM_CNTRESET_ACTIVE_EDGE	= 0U,
	EFTU_TIM_TPWM_CNTRESET_EVERY_EDGE	= 1U,
}EFTU_TIM_TpwmCntResType;

typedef enum
{
	EFTU_TIM_IRQ_NEWVAL				= 0X01U,			 /**< \brief new value irq mode */
	EFTU_TIM_IRQ_ECNTOFL			= 0X02U,
	EFTU_TIM_IRQ_CNTOFL				= 0X04U,
	EFTU_TIM_IRQ_GPR0OFL			= 0X08U,
	EFTU_TIM_IRQ_TODET				= 0X10U,			 /**< \brief Timeout irq mode */
	EFTU_TIM_IRQ_GLITCHDET			= 0X20U,
}EFTU_TIM_IrqSrcType;

typedef enum
{
	EFTU_TIM_LUT_DISABLE = 0u,
	EFTU_TIM_LUT_EXT_CAPTURE = 1u,
	EFTU_TIM_LUT_FOUT_PREV	= 2u,
	EFTU_TIM_LUT_TSSM_OUT = 3u,
}EFTU_TIM_LutType;

/********* Local inline function ************/
LOCAL_INLINE void EFTU_TIM_HWA_EnIrq( EFTU_TIM_Type *const pTim,EFTU_TIM_IrqSrcType eirq ,uint8_t u8channel)
{
	if(EFTU_TIM_IRQ_NEWVAL == eirq )
	{
		pTim->CONTROL[u8channel].CH_IRQ_EN |= EFTU_TIM_CHn_IRQ_EN_NEWVAL_IRQ_EN_MASK;
	}
	else if (EFTU_TIM_IRQ_ECNTOFL == eirq )
	{
		pTim->CONTROL[u8channel].CH_IRQ_EN |= EFTU_TIM_CHn_IRQ_EN_ECNTOFL_IRQ_EN_MASK;
	}
	else if (EFTU_TIM_IRQ_CNTOFL == eirq )
	{
		pTim->CONTROL[u8channel].CH_IRQ_EN |=  EFTU_TIM_CHn_IRQ_EN_CNTOFL_IRQ_EN_MASK;
	}
	else if (EFTU_TIM_IRQ_GPR0OFL == eirq)
	{
		pTim->CONTROL[u8channel].CH_IRQ_EN |= EFTU_TIM_CHn_IRQ_EN_GPROFL_IRQ_EN_MASK;
	}
	else if (EFTU_TIM_IRQ_TODET == eirq)
	{
		pTim->CONTROL[u8channel].CH_IRQ_EN |= EFTU_TIM_CHn_IRQ_EN_TODET_IRQ_EN_MASK;
	}
	else if (EFTU_TIM_IRQ_GLITCHDET == eirq )
	{
		pTim->CONTROL[u8channel].CH_IRQ_EN |=EFTU_TIM_CHn_IRQ_EN_GLITCHDET_IRQ_EN_MASK;
	}
	else
	{

	}
}

LOCAL_INLINE void EFTU_TIM_HWA_DisIrq( EFTU_TIM_Type *const pTim,EFTU_TIM_IrqSrcType eirq ,uint8_t u8channel)
{
	if(EFTU_TIM_IRQ_NEWVAL == eirq )
	{
		pTim->CONTROL[u8channel].CH_IRQ_EN &= ~EFTU_TIM_CHn_IRQ_EN_NEWVAL_IRQ_EN_MASK;
	}
	else if (EFTU_TIM_IRQ_ECNTOFL == eirq )
	{
		pTim->CONTROL[u8channel].CH_IRQ_EN &= ~EFTU_TIM_CHn_IRQ_EN_ECNTOFL_IRQ_EN_MASK;
	}
	else if (EFTU_TIM_IRQ_CNTOFL == eirq )
	{
		pTim->CONTROL[u8channel].CH_IRQ_EN &= ~EFTU_TIM_CHn_IRQ_EN_CNTOFL_IRQ_EN_MASK;
	}
	else if (EFTU_TIM_IRQ_GPR0OFL == eirq)
	{
		pTim->CONTROL[u8channel].CH_IRQ_EN &= ~EFTU_TIM_CHn_IRQ_EN_GPROFL_IRQ_EN_MASK;
	}
	else if (EFTU_TIM_IRQ_TODET == eirq)
	{
		pTim->CONTROL[u8channel].CH_IRQ_EN &= ~EFTU_TIM_CHn_IRQ_EN_TODET_IRQ_EN_MASK;
	}
	else if (EFTU_TIM_IRQ_GLITCHDET == eirq )
	{
		pTim->CONTROL[u8channel].CH_IRQ_EN &= ~EFTU_TIM_CHn_IRQ_EN_GLITCHDET_IRQ_EN_MASK;
	}
	else
	{

	}
}

LOCAL_INLINE boolean EFTU_TIM_HWA_GetGlitchEvent(const EFTU_TIM_Type *const pTim,uint8_t u8channel)
{
	return  (pTim->CONTROL[u8channel].CH_IRQ_ST & EFTU_TIM_CHn_IRQ_ST_GLITCHDET_MASK) !=0U;
}

LOCAL_INLINE boolean EFTU_TIM_HWA_GetTimeOutEvent(const EFTU_TIM_Type *const pTim,uint8_t u8channel)
{
	return  (pTim->CONTROL[u8channel].CH_IRQ_ST & EFTU_TIM_CHn_IRQ_ST_TODET_MASK) !=0U;
}

LOCAL_INLINE boolean EFTU_TIM_HWA_GetGprOverflowEvent(const EFTU_TIM_Type *const pTim,uint8_t u8channel)
{
	return  (pTim->CONTROL[u8channel].CH_IRQ_ST & EFTU_TIM_CHn_IRQ_ST_GPROFL_MASK) !=0U;
}

LOCAL_INLINE boolean EFTU_TIM_HWA_GetCntOverflowEvent(const EFTU_TIM_Type *const pTim,uint8_t u8channel)
{
	return  (pTim->CONTROL[u8channel].CH_IRQ_ST & EFTU_TIM_CHn_IRQ_ST_CNTOFL_MASK) !=0U;
}

LOCAL_INLINE boolean EFTU_TIM_HWA_GetNewValEvent(const EFTU_TIM_Type *const pTim,uint8_t u8channel)
{
	return  (pTim->CONTROL[u8channel].CH_IRQ_ST & EFTU_TIM_CHn_IRQ_ST_NEWVAL_MASK) !=0U;
}

LOCAL_INLINE boolean EFTU_TIM_HWA_GetEcntEvent(const EFTU_TIM_Type *const pTim,uint8_t u8channel)
{
	return  (pTim->CONTROL[u8channel].CH_IRQ_ST & EFTU_TIM_CHn_IRQ_ST_ECNTOFL_MASK) !=0U;
}



LOCAL_INLINE boolean EFTU_TIM_HWA_GetGlitchIrqEnable(const EFTU_TIM_Type *const pTim,uint8_t u8channel)
{
	return  (pTim->CONTROL[u8channel].CH_IRQ_EN & EFTU_TIM_CHn_IRQ_EN_GLITCHDET_IRQ_EN_MASK) !=0U;
}

LOCAL_INLINE boolean EFTU_TIM_HWA_GetTimeOutIrqEnable(const EFTU_TIM_Type *const pTim,uint8_t u8channel)
{
	return  (pTim->CONTROL[u8channel].CH_IRQ_EN & EFTU_TIM_CHn_IRQ_EN_TODET_IRQ_EN_MASK) !=0U;
}

LOCAL_INLINE boolean EFTU_TIM_HWA_GetGprOverflowIrqEnable(const EFTU_TIM_Type *const pTim,uint8_t u8channel)
{
	return  (pTim->CONTROL[u8channel].CH_IRQ_EN & EFTU_TIM_CHn_IRQ_EN_GPROFL_IRQ_EN_MASK) !=0U;
}

LOCAL_INLINE boolean EFTU_TIM_HWA_GetCntOverflowIrqEnable(const EFTU_TIM_Type *const pTim,uint8_t u8channel)
{
	return  (pTim->CONTROL[u8channel].CH_IRQ_EN & EFTU_TIM_CHn_IRQ_EN_CNTOFL_IRQ_EN_MASK) !=0U;
}

LOCAL_INLINE boolean EFTU_TIM_HWA_GetNewValIrqEnable(const EFTU_TIM_Type *const pTim,uint8_t u8channel)
{
	return  (pTim->CONTROL[u8channel].CH_IRQ_EN & EFTU_TIM_CHn_IRQ_EN_NEWVAL_IRQ_EN_MASK) !=0U;
}

LOCAL_INLINE boolean EFTU_TIM_HWA_GetEcntIrqEnable(const EFTU_TIM_Type *const pTim,uint8_t u8channel)
{
	return  (pTim->CONTROL[u8channel].CH_IRQ_EN & EFTU_TIM_CHn_IRQ_EN_ECNTOFL_IRQ_EN_MASK) !=0U;
}






LOCAL_INLINE void EFTU_TIM_HWA_ClearGlitchFlag( EFTU_TIM_Type * pTim,uint8_t u8channel)
{
	  pTim->CONTROL[u8channel].CH_IRQ_ST = EFTU_TIM_CHn_IRQ_ST_GLITCHDET_MASK;
}

LOCAL_INLINE void EFTU_TIM_HWA_ClearTimeOutFlag( EFTU_TIM_Type * pTim,uint8_t u8channel)
{
	pTim->CONTROL[u8channel].CH_IRQ_ST = EFTU_TIM_CHn_IRQ_ST_TODET_MASK;
}

LOCAL_INLINE void EFTU_TIM_HWA_ClearGprOverflowFlag( EFTU_TIM_Type * pTim,uint8_t u8channel)
{
	pTim->CONTROL[u8channel].CH_IRQ_ST = EFTU_TIM_CHn_IRQ_ST_GPROFL_MASK;
}

LOCAL_INLINE void EFTU_TIM_HWA_ClearCntOverflowFlag( EFTU_TIM_Type * pTim,uint8_t u8channel)
{
pTim->CONTROL[u8channel].CH_IRQ_ST = EFTU_TIM_CHn_IRQ_ST_CNTOFL_MASK;
}

LOCAL_INLINE void EFTU_TIM_HWA_ClearNewValFlag( EFTU_TIM_Type * pTim,uint8_t u8channel)
{
pTim->CONTROL[u8channel].CH_IRQ_ST = EFTU_TIM_CHn_IRQ_ST_NEWVAL_MASK;
}

LOCAL_INLINE void EFTU_TIM_HWA_ClearEcntFlag( EFTU_TIM_Type *const pTim,uint8_t u8channel)
{
pTim->CONTROL[u8channel].CH_IRQ_ST = EFTU_TIM_CHn_IRQ_ST_ECNTOFL_MASK;
}


/**
 * @get Tim channel x GPR0 value
*/
LOCAL_INLINE uint32_t EFTU_TIM_HWA_GetChGPR0(const EFTU_TIM_Type *const pTim,uint8_t u8channel)
{
    return (uint32_t)(pTim->CONTROL[u8channel].CH_GPR0 & EFTU_TIM_CHn_GPR0_GPR0_MASK);
}

/**
 * @get Tim channel x GPR0  Ecnt value
*/
LOCAL_INLINE uint32_t EFTU_TIM_HWA_GetChGPR0Ecnt(const EFTU_TIM_Type *const pTim,uint8_t u8channel)
{
    return (uint32_t)((pTim->CONTROL[u8channel].CH_GPR0 & EFTU_TIM_CHn_GPR0_ECNT_MASK)>>EFTU_TIM_CHn_GPR0_ECNT_SHIFT);
}

/**
 * @get Tim channel x GPR1 value
*/
LOCAL_INLINE uint32_t EFTU_TIM_HWA_GetChGPR1(const EFTU_TIM_Type *const pTim,uint8_t u8channel)
{
    return (uint32_t)(pTim->CONTROL[u8channel].CH_GPR1 & EFTU_TIM_CHn_GPR1_GPR1_MASK);
}

/**
 * @get Tim channel x Counter value
*/
LOCAL_INLINE  uint32_t EFTU_TIM_HWA_GetChCnt(const EFTU_TIM_Type *const pTim,uint8_t u8channel)
{
    return (uint32_t)(pTim->CONTROL[u8channel].CH_CNT & EFTU_TIM_CHn_CNT_CNT_MASK);
}

/**
 * @get Tim channel0  Shadow Counter value
*/
LOCAL_INLINE  uint32_t EFTU_TIM_HWA_GetCntsCnt(const EFTU_TIM_Type *const pTim,uint8_t u8channel)
{
    return (uint32_t)(pTim->CONTROL[u8channel].CH_CNTS & EFTU_TIM_CHn_CNTS_CNTS_MASK);
}

/**
 * @get Tim channel0  edge counter value
*/
LOCAL_INLINE  uint32_t EFTU_TIM_HWA_GetChECnt(const EFTU_TIM_Type *const pTim,uint8_t u8channel)
{
    return (uint32_t)(pTim->CONTROL[u8channel].CH_ECNT & EFTU_TIM_CHn_ECNT_ECNT_MASK);
}


/*******************FLT relate register *****************/
/**
 * @get Set  Value to be fed to Channel x
*/
LOCAL_INLINE void EFTU_TIM_HWA_SetVal(EFTU_TIM_Type *const pTim,uint8_t u8channel)
{
    uint8_t u8shift = (uint8_t)(u8channel *4U);
    pTim->IN_SRC = (uint32_t)(0x2<<u8shift);
}

/**
 * @get clear Value to be fed to Channel x
*/
LOCAL_INLINE void EFTU_TIM_HWA_ClearVal(EFTU_TIM_Type *const pTim,uint8_t u8channel)
{
    uint8_t u8shift = (uint8_t)(u8channel *4U);
    pTim->IN_SRC =(uint32_t) (0x1<<u8shift);
}

/**
 * @get Set channel  AUX IN Source.
*/
LOCAL_INLINE void EFTU_TIM_HWA_SetAuxMode(EFTU_TIM_Type *const pTim,uint8_t u8channel)
{
    uint8_t u8shift = (uint8_t)(u8channel *4U);
    pTim->IN_SRC = (uint32_t)(0x8<<u8shift);
}

/**
 * @get clear channel  AUX IN Source.
*/
LOCAL_INLINE void EFTU_TIM_HWA_ClearAuxMode(EFTU_TIM_Type *const pTim,uint8_t u8channel)
{
    uint8_t u8shift = (uint8_t)(u8channel *4U);
    pTim->IN_SRC = (uint32_t)(0x4<<u8shift);
}

/**
 * @brief CICTRL  Channel Input Control Use signal TIM_IN(x-1) as input for channel x (or TIM_IN(m-1) if x is 0)
*
* 
*/
LOCAL_INLINE void EFTU_TIM_HWA_SetchCicrl(EFTU_TIM_Type *const pTim,uint8_t u8channel)
{
    pTim->CONTROL[u8channel].CH_CTRL |=  EFTU_TIM_CHn_CTRL_CICTRL_MASK;
}

LOCAL_INLINE void EFTU_TIM_HWA_ClearchCicrl(EFTU_TIM_Type *const pTim,uint8_t u8channel)
{
    pTim->CONTROL[u8channel].CH_CTRL &=  ~EFTU_TIM_CHn_CTRL_CICTRL_MASK;
}

/**
 * @brief config source for triggering the EXT_CAPTURE functionality
 */
LOCAL_INLINE void EFTU_TIM_HWA_ConfigchExtCapSrc(EFTU_TIM_Type *const pTim,uint8_t u8src,uint8_t u8channel)
{
    pTim->CONTROL[u8channel].CH_ECTRL =(pTim->CONTROL[u8channel].CH_ECTRL & ~EFTU_TIM_CHn_ECTRL_EXT_CAP_SRC_MASK) | EFTU_TIM_CHn_ECTRL_EXT_CAP_SRC(u8src);
}


LOCAL_INLINE void EFTU_TIM_HWA_ConfigLut( EFTU_TIM_Type *const pTim,EFTU_TIM_LutType elut ,uint8_t u8channel)
{
	
	pTim->CONTROL[u8channel].CH_ECTRL =(pTim->CONTROL[u8channel].CH_ECTRL & ~EFTU_TIM_CHn_ECTRL_USE_LUT_MASK)|EFTU_TIM_CHn_ECTRL_USE_LUT(elut);
}


/**
 * @brief set Filter counter Src
*/
LOCAL_INLINE void EFTU_TIM_HWA_SetChFltSrc( EFTU_TIM_Type *const pTim, EFTU_TIM_FltSrcType eFltClkSrc,uint8_t u8channel)
{
	
    pTim->CONTROL[u8channel].CH_CTRL =(pTim->CONTROL[u8channel].CH_CTRL & ~EFTU_TIM_CHn_CTRL_FLT_CNT_FRQ_MASK) | EFTU_TIM_CHn_CTRL_FLT_CNT_FRQ(eFltClkSrc);
}

/**
 * @brief  set channel rising edge number
*/
LOCAL_INLINE void EFTU_TIM_HWA_SetChFltReValue( EFTU_TIM_Type *const pTim, uint8_t u8Recount,uint8_t u8channel)
{
    pTim->CONTROL[u8channel].CH_FLT_RE = u8Recount;
}

/**
 * @brief  set channel fall edge number
*/
LOCAL_INLINE void EFTU_TIM_HWA_SetChFltFeValue( EFTU_TIM_Type *const pTim, uint8_t u8Fecount,uint8_t u8channel)
{
    pTim->CONTROL[u8channel].CH_FLT_FE = u8Fecount;
}


/**
 * @brief Enable the Filter mode for rising edge
*/
LOCAL_INLINE void EFTU_TIM_HWA_EnableChFltRe(EFTU_TIM_Type *const pTim,uint8_t u8channel)
{
    pTim->CONTROL[u8channel].CH_CTRL |= EFTU_TIM_CHn_CTRL_FLT_MODE_RE_MASK;
}

/**
 * @brief Disable the Filter mode for rising edge
*/
LOCAL_INLINE void EFTU_TIM_HWA_DisableChFltRe(EFTU_TIM_Type *const pTim,uint8_t u8channel)
{
    pTim->CONTROL[u8channel].CH_CTRL &= ~EFTU_TIM_CHn_CTRL_FLT_MODE_RE_MASK;
}

/**
 * @brief Enable the Filter mode for falling edge
*/
LOCAL_INLINE void EFTU_TIM_HWA_EnableChFltFe(EFTU_TIM_Type *const pTim,uint8_t u8channel)
{
    pTim->CONTROL[u8channel].CH_CTRL |= EFTU_TIM_CHn_CTRL_FLT_MODE_FE_MASK;
}

/**
 * @brief Disable the Filter mode for falling edge
*/
LOCAL_INLINE void EFTU_TIM_HWA_DisableChFltFe(EFTU_TIM_Type *const pTim,uint8_t u8channel)
{
    pTim->CONTROL[u8channel].CH_CTRL &= ~EFTU_TIM_CHn_CTRL_FLT_MODE_FE_MASK;
}

/**
 * @brief Enable the Filter counter mode for rising edge
*/
LOCAL_INLINE void EFTU_TIM_HWA_EnableChFltReCounter(EFTU_TIM_Type *const pTim,uint8_t u8channel)
{
    pTim->CONTROL[u8channel].CH_CTRL |= EFTU_TIM_CHn_CTRL_FLT_CTR_RE_MASK;
}

/**
 * @brief Disable the Filter mode for rising edge
*/
LOCAL_INLINE void EFTU_TIM_HWA_DisableChFltReCounter(EFTU_TIM_Type *const pTim,uint8_t u8channel)
{
    pTim->CONTROL[u8channel].CH_CTRL &= ~EFTU_TIM_CHn_CTRL_FLT_CTR_RE_MASK;
}

/**
 * @brief Enable the Filter counter mode for falling edge
*/
LOCAL_INLINE void EFTU_TIM_HWA_EnableChFltFeCounter(EFTU_TIM_Type *const pTim,uint8_t u8channel)
{
    pTim->CONTROL[u8channel].CH_CTRL |= EFTU_TIM_CHn_CTRL_FLT_CTR_FE_MASK;
}

/**
 * @brief Disable the Filter mode for falling edge
*/
LOCAL_INLINE void EFTU_TIM_HWA_DisableChFltFeCounter(EFTU_TIM_Type *const pTim,uint8_t u8channel)
{
    pTim->CONTROL[u8channel].CH_CTRL &= ~EFTU_TIM_CHn_CTRL_FLT_CTR_FE_MASK;
}

/**
 * @brief set extension of bit field FLT_CTR_RE
*/
LOCAL_INLINE void EFTU_TIM_HWA_EnableChFltReExbit(EFTU_TIM_Type *const pTim,uint8_t u8channel)
{
    pTim->CONTROL[u8channel].CH_ECTRL |=EFTU_TIM_CHn_ECTRL_EFLT_CTR_RE_MASK;
}

/**
 * @brief Disable extension of bit field FLT_CTR_RE
*/
LOCAL_INLINE void EFTU_TIM_HWA_DisableChFltReExbit(EFTU_TIM_Type *const pTim,uint8_t u8channel)
{
    pTim->CONTROL[u8channel].CH_ECTRL &= ~EFTU_TIM_CHn_ECTRL_EFLT_CTR_RE_MASK;
}

/**
 * @brief set extension of bit field FLT_CTR_FE
*/
LOCAL_INLINE void EFTU_TIM_HWA_EnableChFltFeExbit(EFTU_TIM_Type *const pTim,uint8_t u8channel)
{
    pTim->CONTROL[u8channel].CH_ECTRL |=EFTU_TIM_CHn_ECTRL_EFLT_CTR_FE_MASK;
}

/**
 * @brief Disable extension of bit field FLT_CTR_FE
*/
LOCAL_INLINE void EFTU_TIM_HWA_DisableChFltFeExbit(EFTU_TIM_Type *const pTim,uint8_t u8channel)
{
    pTim->CONTROL[u8channel].CH_ECTRL &= ~EFTU_TIM_CHn_ECTRL_EFLT_CTR_FE_MASK;
}


LOCAL_INLINE void EFTU_TIM_HWA_EnableFlt(EFTU_TIM_Type *const pTim,uint8_t u8channel)
{
	pTim->CONTROL[u8channel].CH_CTRL |= EFTU_TIM_CHn_CTRL_FLT_EN_MASK;
}

LOCAL_INLINE void EFTU_TIM_HWA_DisableFlt(EFTU_TIM_Type *const pTim,uint8_t u8channel)
{
	pTim->CONTROL[u8channel].CH_CTRL &= ~EFTU_TIM_CHn_CTRL_FLT_EN_MASK;
}

/******************* End FLT relate register *****************/
/*but ECTRL related register has been changed*/

/*******************  TDU relate register *****************/

/**
 * @brief config Tov0 value.
*/
LOCAL_INLINE void EFTU_TOM_HWA_SetTduTov(EFTU_TIM_Type *const pTim,uint8_t u8Tov0Value, uint8_t u8channel)
{
	pTim->CONTROL[u8channel].CH_EGV = (pTim->CONTROL[u8channel].CH_EGV & ~EFTU_TIM_CHn_EGV_TOV_MASK)|EFTU_TIM_CHn_EGV_TOV(u8Tov0Value);
}

/**
 * @brief config Tov1 value.
*/
LOCAL_INLINE void EFTU_TOM_HWA_SetTduTov1(EFTU_TIM_Type *const pTim,uint8_t u8Tov1Value, uint8_t u8channel)
{
	pTim->CONTROL[u8channel].CH_EGV = (pTim->CONTROL[u8channel].CH_EGV	& ~EFTU_TIM_CHn_EGV_TOV1_MASK)|EFTU_TIM_CHn_EGV_TOV1(u8Tov1Value);
}

/**
 * @brief config Tov2 value.
*/
LOCAL_INLINE void EFTU_TOM_HWA_SetTduTov2(EFTU_TIM_Type *const pTim,uint8_t u8Tov2Value, uint8_t u8channel)
{
	pTim->CONTROL[u8channel].CH_EGV = (pTim->CONTROL[u8channel].CH_EGV	& ~EFTU_TIM_CHn_EGV_TOV2_MASK)|EFTU_TIM_CHn_EGV_TOV2(u8Tov2Value);
}

LOCAL_INLINE void EFTU_TOM_HWA_SetimeoutValue(EFTU_TIM_Type *const pTim,uint32_t u32TimeoutValue, uint8_t u8channel)
{
	pTim->CONTROL[u8channel].CH_EGV = (pTim->CONTROL[u8channel].CH_EGV & 0XFF000000)|(u32TimeoutValue & 0xFFFFFF);
}


/*
 * @brief Config Tdu Clock
 * */
LOCAL_INLINE void EFTU_TIM_HWA_SetTduClk(EFTU_TIM_Type *const pTim,EFTU_TIM_ClockSrcType eClk,uint8_t u8channel)
{
	
    pTim->CONTROL[u8channel].CH_EGV =(pTim->CONTROL[u8channel].CH_EGV & ~EFTU_TIM_CHn_EGV_TCS_MASK)|EFTU_TIM_CHn_EGV_TCS(eClk);
}

LOCAL_INLINE void EFTU_TIM_HWA_SetTimeoutEdge(EFTU_TIM_Type *const pTim,EFTU_TIM_TimeOutEdgeType pTimeOutSensitiveEgde, uint8_t u8channel)
{
	
	pTim->CONTROL[u8channel].CH_CTRL =(pTim->CONTROL[u8channel].CH_CTRL & ~EFTU_TIM_CHn_CTRL_TOCTRL_MASK)| EFTU_TIM_CHn_CTRL_TOCTRL(pTimeOutSensitiveEgde);
}



LOCAL_INLINE void EFTU_TIM_HWA_ConfigTduCnt2Clk(EFTU_TIM_Type *const pTim,EFTU_TIM_TduCnt2ClkType eClk,uint8_t u8channel)
{
	if(EFTU_TO_CNT2_CLOCK_CMU_CLK == eClk)
	{
		pTim->CONTROL[u8channel].CH_EGV &= ~EFTU_TIM_CHn_EGV_TCS_USE_SAMPLE_EVT_MASK;
	}
	else
	{
		pTim->CONTROL[u8channel].CH_EGV |= EFTU_TIM_CHn_EGV_TCS_USE_SAMPLE_EVT_MASK;
	}
}



LOCAL_INLINE void EFTU_TIM_HWA_ConfigTduCnt1Clk(EFTU_TIM_Type *const pTim,EFTU_TIM_TduCnt1ClkType eClk,uint8_t u8channel)
{

	if(EFTU_TO_CNT1_CLOCK_WORD_EVENT == eClk)
	{
		pTim->CONTROL[u8channel].CH_EGV &= ~EFTU_TIM_CHn_EGV_EG_SAME_CNT_CLK_MASK;
	}
	else
	{
		pTim->CONTROL[u8channel].CH_EGV |= EFTU_TIM_CHn_EGV_EG_SAME_CNT_CLK_MASK;
	}
}

/**
 * @brief confg tdu slic mode
*/
LOCAL_INLINE void EFTU_TIM_HWA_SetTduSlicing(EFTU_TIM_Type *const pTim,EFTU_TIM_TduSlicType eSlic,uint8_t u8channel)
{
	
    pTim->CONTROL[u8channel].CH_EGV = (pTim->CONTROL[u8channel].CH_EGV & ~EFTU_TIM_CHn_EGV_SLICING_MASK)| EFTU_TIM_CHn_EGV_SLICING(eSlic);
}

/******************* End TDU relate register *****************/



/**********channel related register*************/
LOCAL_INLINE void EFTU_TIM_HWA_SetChannelMode(EFTU_TIM_Type *const pTim,EFTU_TiM_ChannelModeType pTimMode,uint8_t u8channel)
{
	pTim->CONTROL[u8channel].CH_CTRL = (pTim->CONTROL[u8channel].CH_CTRL & ~EFTU_TIM_CHn_CTRL_TIM_MODE_MASK)|EFTU_TIM_CHn_CTRL_TIM_MODE(pTimMode);
}


LOCAL_INLINE void EFTU_TIM_HWA_SetChannelClockSrc(EFTU_TIM_Type *const pTim,EFTU_TIM_ClockSrcType pTimSrc,uint8_t u8channel)
{
	pTim->CONTROL[u8channel].CH_CTRL = (pTim->CONTROL[u8channel].CH_CTRL & ~EFTU_TIM_CHn_CTRL_CLK_SEL_MASK) | EFTU_TIM_CHn_CTRL_CLK_SEL(pTimSrc);
}

LOCAL_INLINE void EFTU_TIM_HWA_EnableChannel(EFTU_TIM_Type *const pTim,uint8_t u8channel)
{
	pTim->CONTROL[u8channel].CH_CTRL |= EFTU_TIM_CHn_CTRL_TIM_EN_MASK;
}

LOCAL_INLINE void EFTU_TIM_HWA_DisableChannel(EFTU_TIM_Type *const pTim,uint8_t u8channel)
{
	pTim->CONTROL[u8channel].CH_CTRL &= ~EFTU_TIM_CHn_CTRL_TIM_EN_MASK;
}

LOCAL_INLINE void EFTU_TIM_HWA_SetGPR0Sel(EFTU_TIM_Type *const pTim,EFTU_TIM_GprSrcType pTimGprser,uint8_t u8channel)
{
	pTim->CONTROL[u8channel].CH_CTRL = (pTim->CONTROL[u8channel].CH_CTRL & ~EFTU_TIM_CHn_CTRL_GPR0_SEL_MASK)|EFTU_TIM_CHn_CTRL_GPR0_SEL(pTimGprser);
}

LOCAL_INLINE void EFTU_TIM_HWA_SetGPR1Sel(EFTU_TIM_Type *const pTim,EFTU_TIM_GprSrcType pTimGprsel,uint8_t u8channel)
{
	pTim->CONTROL[u8channel].CH_CTRL = (pTim->CONTROL[u8channel].CH_CTRL & ~EFTU_TIM_CHn_CTRL_GPR1_SEL_MASK) | EFTU_TIM_CHn_CTRL_GPR1_SEL(pTimGprsel);
}

LOCAL_INLINE void EFTU_TIM_HWA_SetCntsSel(EFTU_TIM_Type *const pTim,EFTU_TIM_CntsSrcType pTimCntssel,uint8_t u8channel)
{
	
	pTim->CONTROL[u8channel].CH_CTRL = (pTim->CONTROL[u8channel].CH_CTRL & ~ EFTU_TIM_CHn_CTRL_CNTS_SEL_MASK)|EFTU_TIM_CHn_CTRL_CNTS_SEL(pTimCntssel);
}

LOCAL_INLINE void EFTU_TIM_HWA_SetTbu0BitFiled(EFTU_TIM_Type *const pTim,EFTU_TIM_TbuTs0ResType eTbu0Ts0,uint8_t u8channel)
{

	pTim->CONTROL[u8channel].CH_CTRL =(pTim->CONTROL[u8channel].CH_CTRL & ~EFTU_TIM_CHn_CTRL_TBU0_SEL_MASK) | EFTU_TIM_CHn_CTRL_TBU0_SEL(eTbu0Ts0);
}


LOCAL_INLINE void EFTU_TIM_HWA_EnableExtCapture(EFTU_TIM_Type *const pTim,boolean bEn,uint8_t u8channel)
{
	if(TRUE == bEn)
	{
		pTim->CONTROL[u8channel].CH_CTRL |= EFTU_TIM_CHn_CTRL_EXT_CAP_EN_MASK;
	}
	else
	{
		pTim->CONTROL[u8channel].CH_CTRL &= ~EFTU_TIM_CHn_CTRL_EXT_CAP_EN_MASK;
	}
}

LOCAL_INLINE void EFTU_TIM_HWA_EnableSwCaputure(EFTU_TIM_Type *const pTim,boolean bEn,uint8_t u8channel)
{
	if(TRUE == bEn)
	{
		pTim->CONTROL[u8channel].CH_ECTRL |= EFTU_TIM_CHn_ECTRL_SWAP_CAPTURE_MASK;
	}
	else
	{
		pTim->CONTROL[u8channel].CH_ECTRL &= ~EFTU_TIM_CHn_ECTRL_SWAP_CAPTURE_MASK;
	}
}


LOCAL_INLINE void EFTU_TIM_HWA_ConfigActiveEdge(EFTU_TIM_Type *const pTim,EFTU_TIM_ActiveEdgeType eEdge ,uint8_t u8channel)
{
	if(EFTU_TIM_ACTIVE_RISINGEDGE== eEdge)
	{
		pTim->CONTROL[u8channel].CH_CTRL |= EFTU_TIM_CHn_CTRL_DSL_MASK;
	}
	else
	{
		pTim->CONTROL[u8channel].CH_CTRL &= ~EFTU_TIM_CHn_CTRL_DSL_MASK;
	}
}



LOCAL_INLINE void EFTU_TIM_HWA_ConfigTpwmCntmode(EFTU_TIM_Type *const pTim,EFTU_TIM_TpwmCntResType eResType ,uint8_t u8channel)
{

	if(EFTU_TIM_TPWM_CNTRESET_EVERY_EDGE == eResType)
	{
		pTim->CONTROL[u8channel].CH_CTRL |= EFTU_TIM_CHn_CTRL_ECNT_RESET_MASK;
	}
	else
	{
		pTim->CONTROL[u8channel].CH_CTRL &= ~EFTU_TIM_CHn_CTRL_ECNT_RESET_MASK;
	}
}

LOCAL_INLINE void EFTU_TIM_HWA_EnIngnoreEdge(EFTU_TIM_Type *const pTim,boolean bEn,uint8_t u8channel)
{
	if(TRUE == bEn)
	{
		pTim->CONTROL[u8channel].CH_CTRL |= EFTU_TIM_CHn_CTRL_ISL_MASK;
	}
	else
	{
		pTim->CONTROL[u8channel].CH_CTRL &= ~EFTU_TIM_CHn_CTRL_ISL_MASK;
	}
}


LOCAL_INLINE void EFTU_TIM_HWA_EnableImmStart(EFTU_TIM_Type *const pTim,boolean bEnable,uint8_t u8channel)
{
	if(TRUE == bEnable)
	{
		pTim->CONTROL[u8channel].CH_ECTRL |=EFTU_TIM_CHn_ECTRL_IMM_START_MASK;
	}
	else
	{
		pTim->CONTROL[u8channel].CH_ECTRL &= ~EFTU_TIM_CHn_ECTRL_IMM_START_MASK;
	}
}

LOCAL_INLINE void EFTU_TIM_HWA_SetCntsValue(EFTU_TIM_Type *const pTim,uint32 value,uint8_t u8channel)
{
	pTim->CONTROL[u8channel].CH_CNTS = value;
}


LOCAL_INLINE void EFTU_TIM_HWA_TssmEnshiftRight(EFTU_TIM_Type *const pTim,boolean bShiftRight ,uint8_t u8channel)
{
	if(TRUE== bShiftRight)
	{
		pTim->CONTROL[u8channel].CH_CTRL |= EFTU_TIM_CHn_CTRL_DSL_MASK;
	}
	else
	{
		pTim->CONTROL[u8channel].CH_CTRL &= ~EFTU_TIM_CHn_CTRL_DSL_MASK;
	}
}

LOCAL_INLINE void EFTU_TIM_HWA_UnLock(EFTU_TIM_Type *const pTim)
{
	pTim->TIM_SPEC_LOCK = 0xBEEFCAFE;
}

LOCAL_INLINE void EFTU_TIM_HWA_Lock(EFTU_TIM_Type *const pTim)
{
	pTim->TIM_SPEC_LOCK = 0x5AFECAFE;
}

LOCAL_INLINE void EFTU_TIM_HWA_ResetChannel(EFTU_TIM_Type *const pTim,uint8_t u8channel)
{
	pTim->RST |=  0x1U<<u8channel;
}

LOCAL_INLINE uint32_t EFTU_TIM_HWA_GetInputLevel(EFTU_TIM_Type *const pTim)
{
	return (uint32_t)(pTim->INP_VAL);
}


#endif

#endif /*#ifndef _HWA_EFTU_TIM_H_*/
