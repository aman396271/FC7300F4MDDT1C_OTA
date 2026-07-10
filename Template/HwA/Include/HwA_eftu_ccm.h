/**
 * @file HwA_eftu_ccm.h
 * @author flagchip
 * @brief Hardware access layer for EFTU CCM
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

#ifndef HWA_INCLUDE_HWA_EFTU_CCM_H_
#define HWA_INCLUDE_HWA_EFTU_CCM_H_
#include "device_header.h"

#if EFTU_INSTANCE_COUNT > 0U

#define EFTU_CLUSTER_CLOCK_COUNT     (8U)

#define EFTU_GTOM_CHANNEL_COUNT     (16U)
#define EFTU_GTRIGGER_OUT_COUNT     (8U)
#define EFTU_CMP_COUNT      (2U)
#define EFTU_DMA_REQUEST_COUNT     (6U)

#define  EFTU_GTRIGGER_OUT_MASK_TOM1_CCU1_BIT0    (0x1<<0U)
#define  EFTU_GTRIGGER_OUT_MASK_TOM0_CCU1_BIT1    (0x1<<1U)
#define  EFTU_GTRIGGER_OUT_MASK_TOM1_CCU0_BIT2    (0x1<<2U)
#define  EFTU_GTRIGGER_OUT_MASK_TOM0_CCU0_BIT3    (0x1<<3U)
#define  EFTU_GTRIGGER_OUT_MASK_TIM_TRIG_BIT4     (0x1<<4U)

#define EFTU_TIM_ERROR_EN_BIT0          (0x1<<0U)
#define EFTU_TIM_ERROR_EN_BIT1          (0x1<<1U)
#define EFTU_TIM_ERROR_EN_BIT2          (0x1<<2U)
#define EFTU_TIM_ERROR_EN_BIT3          (0x1<<3U)
#define EFTU_TIM_ERROR_EN_BIT4          (0x1<<4U)
#define EFTU_TIM_ERROR_EN_BIT5          (0x1<<5U)


#define EFTU_TOM_SWAP_OUT_2_3_OUT_T_0_1_BIT0  (0x1<<0U)
#define EFTU_TOM_SWAP_OUT_6_7_OUT_T_4_5_BIT1  (0x1<<1U)
#define EFTU_TOM_SWAP_OUT_10_11_OUT_T_8_9_BIT2  (0x1<<2U)
#define EFTU_TOM_SWAP_OUT_14_15_OUT_T_12_13_BIT3  (0x1<<3U)
#define EFTU_TOM_SWAP_OUT_4_7_OUT_T_0_3_BIT4  (0x1<<4U)
#define EFTU_TOM_SWAP_OUT12_15_OUT_T_8_11_BIT5  (0x1<<5U)


typedef enum
{
    EFTU_CLUSTER_CLOCK_CMU_CLK = 0U,
    EFTU_CLUSTER_CLOCK_CMU_CLK8 = 1U,
    EFTU_CLUSTER_CLOCK_EXT_CAPTURE = 2U,
} EFTU_CCM_ClusterCmuClkSelectType;

typedef enum
{
    EFTU_DEBUG_RUN = 0U,
    EFTU_DEBUG_TOM_HALT = 1U,
    EFTU_DEBUG_OUT_FREEZEN = 2U,
    EFTU_DEBUG_ALL_HALT = 3U,
} EFTU_CCM_DebugMode;

typedef enum
{
    EFTU_TIM_AUXI_SRC_CH0  = 0U,
    EFTU_TIM_AUXI_SRC_CH1  = 1U,
    EFTU_TIM_AUXI_SRC_CH2  = 2U,
    EFTU_TIM_AUXI_SRC_CH3  = 3U,
    EFTU_TIM_AUXI_SRC_CH4  = 4U,
    EFTU_TIM_AUXI_SRC_CH5  = 5U,
    EFTU_TIM_AUXI_SRC_CH6  = 6U,
    EFTU_TIM_AUXI_SRC_CH7  = 7U,
    EFTU_TIM_AUXI_SRC_CH8  = 8U,
    EFTU_TIM_AUXI_SRC_CH9  = 9U,
    EFTU_TIM_AUXI_SRC_CH10  = 10U,
    EFTU_TIM_AUXI_SRC_CH11  = 11U,
    EFTU_TIM_AUXI_SRC_CH12  = 12U,
    EFTU_TIM_AUXI_SRC_CH13  = 13U,
    EFTU_TIM_AUXI_SRC_CH14  = 14U,
    EFTU_TIM_AUXI_SRC_CH15  = 15U,
} EFTU_CCM_AuxInChlSrcType;

typedef enum
{
    EFTU0_OUT0 = 0U,
    EFTU1_OUT0 = 1U,
    EFTU2_OUT0 = 2U,
    EFTU0_OUT1 = 3U,
    EFTU1_OUT2 = 4U,
    EFTU2_OUT3 = 5U,
} EFTU_CCM_AuxInSrcType;

typedef enum
{
    EFTU_TIM_PAD_IN = 0U,
    EFTU_TIM_EXT_TRIGGER = 0U,
} EFTU_CCM_TimInSrcType;

typedef enum
{
    EFTU_GTOM_MUX_SRC_EFTU2_OUT = 0U,
    EFTU_GTOM_MUX_SRC_EFTU1_OUT = 1U,
    EFTU_GTOM_MUX_SRC_EFTU0_OUT = 2U,
} EFTU_CCM_GtomOutSrc;

typedef enum
{
    EFTU_GTRIGGER_OUT_SRC_DIS = 0U,
    EFTU_GTRIGGER_OUT_SRC_EFTU0 = 1U,
    EFTU_GTRIGGER_OUT_SRC_EFTU1 = 2U,
    EFTU_GTRIGGER_OUT_SRC_EFTU2 = 3U,
} EFTU_CCM_GlobalTriggerOutType;

typedef enum
{
    EFTU0_CMP0 = 0U,
    EFTU0_CMP1 = 1U,
} EFTU_CCM_CmpInstance;

typedef enum
{
    EFTU_CMP_X_Y_SEL_EFTU0_OUT_0_7 = 0x0U,
    EFTU_CMP_X_Y_SEL_EFTU0_OUT_8_15 = 0x1U,
    EFTU_CMP_X_Y_SEL_EFTU1_OUT_0_7 = 0x2U,
    EFTU_CMP_X_Y_SEL_EFTU1_OUT_8_15 = 0x3U,
    EFTU_CMP_X_Y_SEL_EFTU2_OUT_0_7 = 0x4U,
    EFTU_CMP_X_Y_SEL_EFTU2_OUT_8_15 = 0x5U,

    EFTU_CMP_X_Y_SEL_EFTU0_OUT_T_0_7 = 0x8U,
    EFTU_CMP_X_Y_SEL_EFTU0_OUT_T_8_15 = 0x9U,
    EFTU_CMP_X_Y_SEL_EFTU1_OUT_T_0_7 = 0xAU,
    EFTU_CMP_X_Y_SEL_EFTU1_OUT_T_8_15 = 0xBU,
    EFTU_CMP_X_Y_SEL_EFTU2_OUT_T_0_7 = 0xCU,
    EFTU_CMP_X_Y_SEL_EFTU2_OUT_T_8_15 = 0xDU,
} EFTU_CCM_CmpSrcSelectType;

typedef enum
{
    EFTU_HRPWM_SRC_OUT03_OUT_T03  = 0x0U,
    EFTU_HRPWM_SRC_OUT47_OUT_T47  = 0x1U,
    EFTU_HRPWM_SRC_OUT07  = 0x2U,
    EFTU_HRPWM_SRC_OUT_T07  = 0x3U,
} EFTU_CCM_HrPwmSrcType;


typedef enum
{
    EFTU_TOM0_CH0_TO_TOM1_CH0 = 0x1U,
    EFTU_TOM0_CH7_TO_TOM1_CH0 = 0x2U,
} EFTU_CCM_TomChTrigInType;

typedef enum
{
    EFTU_CLUSTER_CMU_CLK_0 = 0u,
    EFTU_CLUSTER_CMU_CLK_1 = 1u,
    EFTU_CLUSTER_CMU_CLK_2 = 2u,
    EFTU_CLUSTER_CMU_CLK_3 = 3u,
    EFTU_CLUSTER_CMU_CLK_4 = 4u,
    EFTU_CLUSTER_CMU_CLK_5 = 5u,
    EFTU_CLUSTER_CMU_CLK_6 = 6u,
    EFTU_CLUSTER_CMU_CLK_7 = 7u,
} EFTU_CCM_ClusterCmuClkType;

typedef enum
{
    EFTU_TIM_ERR_CH0  = 0U,
    EFTU_TIM_ERR_CH1  = 1U,
    EFTU_TIM_ERR_CH2  = 2U,
    EFTU_TIM_ERR_CH3  = 3U,
    EFTU_TIM_ERR_CH4  = 4U,
    EFTU_TIM_ERR_CH5  = 5U,
    EFTU_TIM_ERR_CH6  = 6U,
    EFTU_TIM_ERR_CH7  = 7U,
} EFTU_CCM_TimErrChnType;
/*EFTU_CCM_PROT*/
LOCAL_INLINE void EFTU_CCM_HWA_EnableProtection(EFTU_CCM_Type *pCcm)
{
    pCcm->PROT |= EFTU_CCM_PROT_CLS_PROT_MASK;
}

LOCAL_INLINE void EFTU_CCM_HWA_DisableProtection(EFTU_CCM_Type *pCcm)
{
    pCcm->PROT &= ~EFTU_CCM_PROT_CLS_PROT_MASK;
}

LOCAL_INLINE void EFTU_CCM_HWA_ConfigDebugMode(EFTU_CCM_Type *pCcm, EFTU_CCM_DebugMode eDebugMode)
{
    pCcm->PROT = (pCcm->PROT & ~EFTU_CCM_PROT_DBG_MODE_MASK) | EFTU_CCM_PROT_DBG_MODE(eDebugMode);
}


/*EFTU_CCM_CFG*/
LOCAL_INLINE void EFTU_CCM_HWA_EnableTim0(EFTU_CCM_Type *pCcm)
{
    pCcm->CFG  |= EFTU_CCM_CFG_EN_TIM_MASK;
}

LOCAL_INLINE void EFTU_CCM_HWA_EnableTom0(EFTU_CCM_Type *pCcm)
{
    pCcm->CFG  |= EFTU_CCM_CFG_EN_TOM0_MASK;
}

LOCAL_INLINE void EFTU_CCM_HWA_EnableTom1(EFTU_CCM_Type *pCcm)
{
    pCcm->CFG  |= EFTU_CCM_CFG_EN_TOM1_MASK;
}

LOCAL_INLINE void EFTU_CCM_HWA_DisableTim0(EFTU_CCM_Type *pCcm)
{
    pCcm->CFG  &= ~EFTU_CCM_CFG_EN_TIM_MASK;
}

LOCAL_INLINE void EFTU_CCM_HWA_DisableTom0(EFTU_CCM_Type *pCcm)
{
    pCcm->CFG  &= ~EFTU_CCM_CFG_EN_TOM0_MASK;
}

LOCAL_INLINE void EFTU_CCM_HWA_DisableTom1(EFTU_CCM_Type *pCcm)
{
    pCcm->CFG  &= ~EFTU_CCM_CFG_EN_TOM1_MASK;
}


/*EFTU_CCM_CMU_CLK_CFG*/
LOCAL_INLINE void EFTU_CCM_HWA_SetClusterCmuClkSrc(EFTU_CCM_Type *pCcm, EFTU_CCM_ClusterCmuClkType eCmuClk, EFTU_CCM_ClusterCmuClkSelectType eCmuClkSelect)
{
    pCcm->CMU_CLK_CFG = ((uint32_t)pCcm->CMU_CLK_CFG  & ~(uint32_t)(0x3U << (uint8_t)(4 * eCmuClk)))| ((uint32_t)((uint8_t)eCmuClkSelect << (uint8_t)(4 * eCmuClk)));
}


/*EFTU_CCM_TIM_IN_SRC /EFTU_CCM_TIM_IN_SRC0 /EFTU_CCM_TIM_IN_SRC1 */
LOCAL_INLINE void  EFTU_CCM_HWA_SetTimInSrc(EFTU_CCM_Type *pCcm, uint8_t u8TimChannel, EFTU_CCM_TimInSrcType eTimSrcSelect)
{
    pCcm->TIM_IN_SRC = ((uint32_t)pCcm->TIM_IN_SRC & ~(uint32_t)(0x1u << u8TimChannel)) | ((uint32_t)eTimSrcSelect << u8TimChannel);
}


LOCAL_INLINE void EFTU_CCM_HWA_SetAuxInSel0_3(EFTU_CCM_Type *pCcm, uint8_t u8TimAuxIn, EFTU_CCM_AuxInSrcType  eAuxInSecSrc, EFTU_CCM_AuxInChlSrcType eAuxInSecChannel)
{
    pCcm->TIM_IN_SRC0 = (pCcm->TIM_IN_SRC0  & ~(uint32_t)(0x7FU << (u8TimAuxIn * 8U)))|(eAuxInSecSrc * 16U + eAuxInSecChannel) << (u8TimAuxIn * 8U);
}

LOCAL_INLINE void EFTU_CCM_HWA_SetAuxInSel4_7(EFTU_CCM_Type *pCcm, uint8_t u8TimAuxIn, EFTU_CCM_AuxInSrcType  eAuxInSecSrc, EFTU_CCM_AuxInChlSrcType eAuxInSecChannel)
{
    pCcm->TIM_IN_SRC1 =(pCcm->TIM_IN_SRC1  & ~(uint32_t)(0x7FU << ((u8TimAuxIn - 4U) * 8U))) | (eAuxInSecSrc * 16U + eAuxInSecChannel) << ((u8TimAuxIn - 4U) * 8U);
}


/*EFTU_CCM_TOM_OUT*/
LOCAL_INLINE uint16_t EFTU_CCM_HWA_GetTomOutlevel(EFTU_CCM_Type *pCcm)
{
    return  pCcm->EFTU_OUT & EFTU_CCM_EFTU_OUT_EFTU_OUT_MASK ;
}

LOCAL_INLINE uint16_t EFTU_CCM_HWA_GetTomNOutlevel(EFTU_CCM_Type *pCcm)
{
    return (pCcm->EFTU_OUT & EFTU_CCM_EFTU_OUT_EFTU_OUT_T_MASK) >> EFTU_CCM_EFTU_OUT_EFTU_OUT_T_SHIFT;
}


/*EFTU_CCM_GTOM_MUX_0/EFTU_CCM_GTOM_MUX_1/EFTU_CCM_GTOM_MUX_2/EFTU_CCM_GTOM_MUX_3,only for EFTU0*/
LOCAL_INLINE void EFTU_CCM_HWA_SetGtomMux0_3(EFTU_CCM_Type *pCcm, uint8_t u8GtomAuxIn, EFTU_CCM_GtomOutSrc eGtomSrc, uint8_t u8channel)
{
    pCcm->GTOM_MUX_0 &= ~(uint32_t)(0x7FU << (u8GtomAuxIn * 8U));
    pCcm->GTOM_MUX_0 |= (uint32_t)(eGtomSrc << 5U | u8channel) << (u8GtomAuxIn * 8U);
}
LOCAL_INLINE void EFTU_CCM_HWA_SetGtomMux4_7(EFTU_CCM_Type *pCcm, uint8_t u8GtomAuxIn, EFTU_CCM_GtomOutSrc eGtomSrc, uint8_t u8channel)
{
    pCcm->GTOM_MUX_1 &= ~(uint32_t)(0x7FU << ((u8GtomAuxIn - 4U) * 8U));
    pCcm->GTOM_MUX_1 |= (uint32_t)(eGtomSrc << 5U | u8channel) << ((u8GtomAuxIn - 4U) * 8U);
}
LOCAL_INLINE void EFTU_CCM_HWA_SetGtomMux8_11(EFTU_CCM_Type *pCcm, uint8_t u8GtomAuxIn, EFTU_CCM_GtomOutSrc eGtomSrc, uint8_t u8channel)
{
    pCcm->GTOM_MUX_2 &= ~(uint32_t)(0x7FU << ((u8GtomAuxIn - 8U) * 8U));
    pCcm->GTOM_MUX_2 |= (uint32_t)(eGtomSrc << 5U | u8channel) << ((u8GtomAuxIn - 8U) * 8U);
}

LOCAL_INLINE void EFTU_CCM_HWA_SetGtomMux12_15(EFTU_CCM_Type *pCcm, uint8_t u8GtomAuxIn, EFTU_CCM_GtomOutSrc eGtomSrc, uint8_t u8channel)
{
    pCcm->GTOM_MUX_3 &= ~(uint32_t)(0x7FU << ((u8GtomAuxIn - 12U) * 8U));
    pCcm->GTOM_MUX_3 |= (uint32_t)(eGtomSrc << 5U | u8channel) << ((u8GtomAuxIn - 12U) * 8U);
}

#if (EFTU_HRPWM_SUPPORT == STD_ON)
/*EFTU_CCM_HRPWM_MUX,only for EFTU0*/
LOCAL_INLINE void EFTU_CCM_HWA_SetHrPwmSrc(EFTU_CCM_Type *pCcm, EFTU_CCM_HrPwmSrcType eHrpwmSrcStatus)
{
    pCcm->HRPWM_MUX = (pCcm->HRPWM_MUX & ~EFTU_CCM_HRPWM_MUX_SWAP_CTRL_MASK)|eHrpwmSrcStatus;
}
#endif
/*EFTU_CCM_TRG_MUX/EFTU_CCM_TRG_EN0/EFTU_CCM_TRG_EN1,only for EFTU0*/
/*
#define  EFTU_GTRIGGER_OUT_MASK_TOM1_CCU1_BIT0    (0x1<<0U)
#define  EFTU_GTRIGGER_OUT_MASK_TOM0_CCU1_BIT1    (0x1<<1U)
#define  EFTU_GTRIGGER_OUT_MASK_TOM1_CCU0_BIT2    (0x1<<2U)
#define  EFTU_GTRIGGER_OUT_MASK_TOM0_CCU0_BIT3    (0x1<<3U)
#define  EFTU_GTRIGGER_OUT_MASK_TIM_TRIG_BIT4     (0x1<<4U)
 * */
LOCAL_INLINE void EFTU_CCM_HWA_ConfigGtomTriggerSrc(EFTU_CCM_Type *pCcm, uint8_t u8TrgMux, EFTU_CCM_GlobalTriggerOutType eGtriggerSrc)
{
    pCcm->TRG_MUX  &= ~(uint32_t)(0x3U << (2U * u8TrgMux));
    pCcm->TRG_MUX  |= (uint32_t)eGtriggerSrc << (2U * u8TrgMux);
}

LOCAL_INLINE void EFTU_CCM_HWA_ConfigGtomTriggerMask0_3(EFTU_CCM_Type *pCcm, uint8_t u8TrgMux, uint8_t u8TriggerMask)
{
    pCcm->TRG_EN0 &= ~(uint32_t)(0x1FU << (u8TrgMux * 8U));
    pCcm->TRG_EN0 |= (uint32_t)u8TriggerMask << (u8TrgMux * 8U);
}

LOCAL_INLINE void EFTU_CCM_HWA_ConfigGtomTriggerMask4_7(EFTU_CCM_Type *pCcm, uint8_t u8TrgMux, uint8_t u8TriggerMask)
{
    pCcm->TRG_EN1 &= ~(uint32_t)(0x1FU << ((u8TrgMux - 4U) * 8U));   
    pCcm->TRG_EN1 |= (uint32_t)u8TriggerMask << ((u8TrgMux - 4U) * 8U);
}

/*EFTU_CCM_CMP_MUX_SEL,only for EFTU0*/
LOCAL_INLINE void EFTU_CCM_HWA_ConfigCmpSrc(EFTU_CCM_Type *pCcm, EFTU_CCM_CmpInstance eCmpInstance, uint8_t Cmp_EnMask, EFTU_CCM_CmpSrcSelectType eCmpSrc_X,
                                            EFTU_CCM_CmpSrcSelectType eCmpSrc_Y)
{

    pCcm->CMP_MUX_SEL &= ~ ((uint32_t)(0xFFU << (8U * (eCmpInstance + 2u))) | (uint32_t)(0xFU << (eCmpInstance * 8U)) |(uint32_t)(0xFU << (eCmpInstance * 8U + 4u)));
    pCcm->CMP_MUX_SEL |= (uint32_t)Cmp_EnMask << (8U * (eCmpInstance + 2u)) | ((uint32_t)eCmpSrc_X << (eCmpInstance * 8U)) | ((uint32_t)eCmpSrc_Y << (eCmpInstance * 8U + 4u));
}
/*EFTU_CCM_CMP Interrupt,only for EFTU0*/
LOCAL_INLINE bool EFTU_CCM_HWA_GetCmp0IrqFlag(EFTU_CCM_Type *pCcm)
{
    return (((pCcm->EINT_ST & EFTU_CCM_EINT_ST_CMP0_ERR_MASK) != 0U) ? TRUE : FALSE);
}

LOCAL_INLINE bool EFTU_CCM_HWA_GetCmp1IrqFlag(EFTU_CCM_Type *pCcm)
{
    return (((pCcm->EINT_ST & EFTU_CCM_EINT_ST_CMP1_ERR_MASK) != 0U) ? TRUE : FALSE);
}
LOCAL_INLINE void EFTU_CCM_HWA_ClearCmp0IrqFlag(EFTU_CCM_Type *pCcm)
{
    pCcm->EINT_ST = EFTU_CCM_EINT_ST_CMP0_ERR_MASK;
}
LOCAL_INLINE void EFTU_CCM_HWA_ClearCmp1IrqFlag(EFTU_CCM_Type *pCcm)
{
    pCcm->EINT_ST = EFTU_CCM_EINT_ST_CMP1_ERR_MASK;
}

LOCAL_INLINE bool EFTU_CCM_HWA_GetCmp0IrqEnable(EFTU_CCM_Type *pCcm)
{
    return (((pCcm->EINT_EN & EFTU_CCM_EINT_EN_CMP0_ENABLE_MASK) != 0U) ? TRUE : FALSE);
}

LOCAL_INLINE bool EFTU_CCM_HWA_GetCmp1IrqEnable(EFTU_CCM_Type *pCcm)
{
    return (((pCcm->EINT_EN & EFTU_CCM_EINT_EN_CMP1_ENABLE_MASK) != 0U) ? TRUE : FALSE);
}

LOCAL_INLINE void EFTU_CCM_HWA_EnCmpInterrupt(EFTU_CCM_Type *pCcm, EFTU_CCM_CmpInstance eCmpInstance)
{
    pCcm->EINT_EN |=  EFTU_CCM_EINT_EN_CMP0_ENABLE_MASK << eCmpInstance;
}


LOCAL_INLINE uint32 EFTU_CCM_HWA_GetErrIrqFlag(EFTU_CCM_Type *pCcm)
{
    return ((pCcm->EINT_ST & EFTU_CCM_EINT_ST_TIM_ERR_MASK) >> EFTU_CCM_EINT_ST_TIM_ERR_SHIFT);
}


/*EFTU_CCM_TOM_MUX*/
/*
#define EFTU_TOM_SWAP_OUT_2_3_OUT_T_0_1_BIT0  (0x1<<0U)
#define EFTU_TOM_SWAP_OUT_6_7_OUT_T_4_5_BIT1  (0x1<<1U)
#define EFTU_TOM_SWAP_OUT_10_11_OUT_T_8_9_BIT2  (0x1<<2U)
#define EFTU_TOM_SWAP_OUT_14_15_OUT_T_12_13_BIT3  (0x1<<3U)
#define EFTU_TOM_SWAP_OUT_4_7_OUT_T_0_3_BIT4  (0x1<<4U)
#define EFTU_TOM_SWAP_OUT12_15_OUT_T_8_11_BIT5  (0x1<<5U)
 * */
LOCAL_INLINE void EFTU_CCM_HWA_SwapTomOut(EFTU_CCM_Type *pCcm, uint8_t u8OutSwapMask)
{
    pCcm->TOM_MUX = ( pCcm->TOM_MUX  & ~EFTU_CCM_TOM_MUX_TOM_SWAP_MASK)|EFTU_CCM_TOM_MUX_TOM_SWAP(u8OutSwapMask);
}

LOCAL_INLINE void EFTU_CCM_HWA_SetTom0ch0TrigIn(EFTU_CCM_Type *pCcm, EFTU_CCM_TomChTrigInType eChSrc)
{
    pCcm->TOM_MUX |= EFTU_CCM_TOM_MUX_TOM_MUX_CTRL(eChSrc);
}

/*EFTU_CCM_SPEC_LOCK,only for EFTU0*/
LOCAL_INLINE void EFTU_CCM_HWA_SpecUnLock(EFTU_CCM_Type *pCcm)
{
    pCcm->SPEC_LOCK = 0xBEEFCAFE;
}
LOCAL_INLINE void EFTU_CCM_HWA_SpecLock(EFTU_CCM_Type *pCcm)
{
    pCcm->SPEC_LOCK = 0x5AFECAFE;
}

/*EFTU_CCM_EINT_EN,EFTU_CCM_TIM_EINT_EN0/EFTU_CCM_TIM_EINT_EN2*/
/*
#define EFTU_TIM_ERROR_EN_BIT0          (0x1<<0U)
#define EFTU_TIM_ERROR_EN_BIT1          (0x1<<1U)
#define EFTU_TIM_ERROR_EN_BIT2          (0x1<<2U)
#define EFTU_TIM_ERROR_EN_BIT3          (0x1<<3U)
#define EFTU_TIM_ERROR_EN_BIT4          (0x1<<4U)
#define EFTU_TIM_ERROR_EN_BIT5          (0x1<<5U)
*/


LOCAL_INLINE void EFTU_CCM_HWA_EnTimChnErrInterupt0_3(EFTU_CCM_Type *pCcm, uint8_t u8TimChannel, uint8_t u8ErrEnMask)
{
    pCcm->TIM_EINT_EN0 |= (uint32_t)u8ErrEnMask << (u8TimChannel * 8U);
}
LOCAL_INLINE void EFTU_CCM_HWA_EnTimChnErrInterupt4_7(EFTU_CCM_Type *pCcm, uint8_t u8TimChannel, uint8_t u8ErrEnMask)
{
    pCcm->TIM_EINT_EN1 |= (uint32_t)u8ErrEnMask << ((u8TimChannel - 4U) * 8U);
}

LOCAL_INLINE uint32 EFTU_CCM_HWA_GetTimErrEnable0_3(EFTU_CCM_Type *pCcm)
{
    return  pCcm->TIM_EINT_EN0 & EFTU_CCM_TIM_EINT_EN0_MASK;
}

LOCAL_INLINE uint32 EFTU_CCM_HWA_GetTimErrEnable4_7(EFTU_CCM_Type *pCcm)
{
    return  pCcm->TIM_EINT_EN1 & EFTU_CCM_TIM_EINT_EN1_MASK;
}

LOCAL_INLINE uint32 EFTU_CCM_HWA_GetTimErrFlag0_3(EFTU_CCM_Type *pCcm)
{
    return  pCcm->TIM_EINT_ST0 & EFTU_CCM_TIM_EINT_ST0_MASK;
}

LOCAL_INLINE uint32 EFTU_CCM_HWA_GetTimErrFlag4_7(EFTU_CCM_Type *pCcm)
{
    return  pCcm->TIM_EINT_ST1 & EFTU_CCM_TIM_EINT_ST1_MASK;
}

LOCAL_INLINE void  EFTU_CCM_HWA_ClearTimErrFlag0_3(EFTU_CCM_Type *pCcm, uint32 u32ErrMask)
{
    pCcm->TIM_EINT_ST0 &= u32ErrMask;
}

LOCAL_INLINE void  EFTU_CCM_HWA_ClearTimErrFlag4_7(EFTU_CCM_Type *pCcm, uint32 u32ErrMask)
{
    pCcm->TIM_EINT_ST1 &= u32ErrMask;
}

#if (EFTU_CCM_DMA_REQ_ONE_INSTANCE == 6U)
/*EFTU_CCM_DMA_SRC01/EFTU_CCM_DMA_SRC23/EFTU_CCM_DMA_SRC45*/
LOCAL_INLINE void EFTU_CCM_HWA_ConfigDmaSrc0_1(EFTU_CCM_Type *pCcm, uint8_t u8DmaChannel, uint8_t u8DmaReqMask)
{
    pCcm->DMA_SRC01 &= ~(uint32_t)(EFTU_CCM_DMA_SRC01_REQ_0_MASK << (u8DmaChannel * EFTU_CCM_DMA_SRC01_REQ_1_SHIFT));
    pCcm->DMA_SRC01 |= (uint32_t)u8DmaReqMask << (u8DmaChannel * EFTU_CCM_DMA_SRC01_REQ_1_SHIFT);
}

LOCAL_INLINE void EFTU_CCM_HWA_ConfigDmaSrc2_3(EFTU_CCM_Type *pCcm, uint8_t u8DmaChannel, uint8_t u8DmaReqMask)
{
    pCcm->DMA_SRC23 &= ~(uint32_t)(EFTU_CCM_DMA_SRC01_REQ_0_MASK << ((u8DmaChannel - 2U) * EFTU_CCM_DMA_SRC01_REQ_1_SHIFT));
    pCcm->DMA_SRC23 |= (uint32_t)u8DmaReqMask << ((u8DmaChannel - 2U) * EFTU_CCM_DMA_SRC01_REQ_1_SHIFT);
}

LOCAL_INLINE void EFTU_CCM_HWA_ConfigDmaSrc4_5(EFTU_CCM_Type *pCcm, uint8_t u8DmaChannel, uint8_t u8DmaReqMask)
{
    pCcm->DMA_SRC45 &= ~(uint32_t)(EFTU_CCM_DMA_SRC01_REQ_0_MASK << ((u8DmaChannel - 4U) * EFTU_CCM_DMA_SRC01_REQ_1_SHIFT));
    pCcm->DMA_SRC45 |= (uint32_t)u8DmaReqMask << ((u8DmaChannel - 4U) * EFTU_CCM_DMA_SRC01_REQ_1_SHIFT);
}

#elif (EFTU_CCM_DMA_REQ_ONE_INSTANCE == 16U)

LOCAL_INLINE void EFTU_CCM_HWA_ConfigDmaSrc(EFTU_CCM_Type *pCcm, uint8_t u8DmaChannel, uint8_t u8DmaReqMask)
{
	pCcm->DMA_SRC[(uint8_t)(u8DmaChannel>>1u)] = ((pCcm->DMA_SRC[(uint8_t)(u8DmaChannel>>1u)]) & ((~(uint32_t)(EFTU_CCM_DMA_SRC_REQ_0_MASK << (((uint8_t)u8DmaChannel&0x1U) * EFTU_CCM_DMA_SRC_REQ_1_SHIFT)))))|
												(((uint32_t)u8DmaReqMask << ((u8DmaChannel&0x1U) * EFTU_CCM_DMA_SRC_REQ_1_SHIFT)));
}
#endif	/*EFTU_CCM_DMA_REQ_ONE_INSTANCE*/

#endif	/*EFTU_INSTANCE_COUNT*/
#endif /* HWA_INCLUDE_HWA_EFTU_CCM_H_ */
