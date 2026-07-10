/**
 * @file HwA_eftu_cmu.h
 * @author flagchip
 * @brief Hardware access layer for EFTU CMU
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

#ifndef _HWA_EFTU_CMU_H_
#define _HWA_EFTU_CMU_H_
#include "device_header.h"

#if EFTU_INSTANCE_COUNT > 0U

/********* Local typedef ************/
/*
 * @brief Clock source selection for CMU_CLK_x_CTRL
*/
typedef enum
{
    CMU_GCLK_EN = 0u,
    CMU_ECLK1_EN = 1U,
}EFTU_CMU_ClkCtrlSrcType;

typedef enum
{
    CLUSTER_RES_CONST_1 = 0u,
    CMU_ECLK0_EN = 1U,
}EFTU_CMU_Clk8CtrlSrcType;

typedef enum
{
	EFTU_CMU_INSTANCE = 0U,
}EFTU_CMU_InstanceType;

/**
 * @brief Cmu clock definition
*/
typedef enum
{
    EFTU_CMU_CLK_0 = 0u,
    EFTU_CMU_CLK_1 = 1u,
    EFTU_CMU_CLK_2 = 2u,
    EFTU_CMU_CLK_3 = 3u,
    EFTU_CMU_CLK_4 = 4u,
    EFTU_CMU_CLK_5 = 5u,
    EFTU_CMU_CLK_6 = 6u,
    EFTU_CMU_CLK_7 = 7u,
	EFTU_ECLK_0	   = 8u,
	EFTU_ECLK_1	   = 9u,
}EFTU_CMU_ClkSrcType;


/********* Local inline function ************/
/*
 * @brief enable Cmu clock
*/
LOCAL_INLINE void EFTU_CMU_HWA_EnableClock(EFTU_CMU_Type *const pCmu ,EFTU_CMU_ClkSrcType eChannel)
{
    pCmu->CLK_EN = (uint32_t)(0x2U << (uint8_t)(eChannel*2U));
}

/*
 * @brief disable the Cmu clock
*/
LOCAL_INLINE void EFTU_CMU_HWA_DisableClock(EFTU_CMU_Type *const pCmu ,EFTU_CMU_ClkSrcType eChannel)
{
    pCmu->CLK_EN = (uint32_t)(0x1u << (uint8_t)(eChannel*2U));
}

/*
 * @brief set CMU Global Clock Control Numerator
*/
LOCAL_INLINE void EFTU_CMU_HWA_SetGclkNum(EFTU_CMU_Type *const pCmu ,uint8_t u8Num)
{
    pCmu->GCLK_NUM = EFTU_CMU_GCLK_NUM_GCLK_NUM(u8Num);
}

/*
 * @brief set CMU  Global Clock Control Denominator
*/
LOCAL_INLINE void EFTU_CMU_HWA_SetGclkDen(EFTU_CMU_Type *const pCmu ,uint8_t u8Den)
{
    pCmu->GCLK_DEN = EFTU_CMU_GCLK_DEN_GCLK_DEN(u8Den);
}

/*
 * @brief set CMU Control for Clock Source CMU_CLK[n] n = 0~7
*/
LOCAL_INLINE void EFTU_CMU_HWA_SetCmuclkCnt(EFTU_CMU_Type *const pCmu ,uint32_t u32Cnt,EFTU_CMU_ClkSrcType eChannel)
{
    pCmu->CLKn_CTRL[(uint8_t)eChannel] = EFTU_CMU_CLKn_CTRL_CLK_CNT(u32Cnt);
}

/*
 * @brief set CMU ECLK0 Clock Control Numerator
*/
LOCAL_INLINE void EFTU_CMU_HWA_SetEclk0Num(EFTU_CMU_Type *const pCmu ,uint32_t u32Num)
{
    pCmu->ECLK0_NUM = EFTU_CMU_ECLKn_NUM_ECLK_NUM(u32Num);
}

/*
 * @brief set CMU  ECLK0 Clock Control Denominator
*/
LOCAL_INLINE void EFTU_CMU_HWA_SetEclk0Den(EFTU_CMU_Type *const pCmu ,uint32_t u32Den)
{
    pCmu->ECLK0_DEN = EFTU_CMU_ECLKn_DEN_ECLK_DEN(u32Den);
}
/*
 * @brief set CMU ECLK1 Clock Control Numerator
*/
LOCAL_INLINE void EFTU_CMU_HWA_SetEclk1Num(EFTU_CMU_Type *const pCmu ,uint32_t u32Num)
{
    pCmu->ECLK1_NUM = EFTU_CMU_ECLKn_NUM_ECLK_NUM(u32Num);
}
/*
 * @brief set CMU  ECLK1 Clock Control Denominator
*/
LOCAL_INLINE void EFTU_CMU_HWA_SetEclk1Den(EFTU_CMU_Type *const pCmu ,uint32_t u32Den)
{
    pCmu->ECLK1_DEN = EFTU_CMU_ECLKn_DEN_ECLK_DEN(u32Den);
}


LOCAL_INLINE void EFTU_CMU_HWA_SetCmuClkSrc(EFTU_CMU_Type *const pCmu ,EFTU_CMU_ClkSrcType eChannel,EFTU_CMU_ClkCtrlSrcType  eCtrl)
{
    if (CMU_GCLK_EN == eCtrl)
    {
        pCmu->CLK_CTRL &= ~(1u<<(uint8_t)eChannel);
    }
    else
    {
        pCmu->CLK_CTRL |=(1u<<(uint8_t)eChannel);
    }
}

LOCAL_INLINE void EFTU_CMU_HWA_SetCmuClk8Src(EFTU_CMU_Type *const pCmu ,EFTU_CMU_Clk8CtrlSrcType  eCtrl)
{
    if (CLUSTER_RES_CONST_1 == eCtrl)
    {
        pCmu->CLK_CTRL &= ~(1u<<(uint8_t)8U);
    }
    else
    {
        pCmu->CLK_CTRL |=(1u<<(uint8_t)8U);
    }
}

#endif

#endif /*#ifndef _HWA_EFTU_CMU_H_*/
