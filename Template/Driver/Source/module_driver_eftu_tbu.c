
#include "module_driver_eftu_tbu.h"

#if defined(EFTU_INSTANCE_COUNT) && (EFTU_INSTANCE_COUNT > 0)
static  EFTU_TBU_Type *const s_pEftuTbuBasePtrs[EFTU_TBU_INSTANCE_COUNT] =
{
    (EFTU_TBU_Type *)(EFTU0_BASE + EFTU_TBU_BASE)
};

/**
 * @brief Set Timestamp Counter 0 configuration
 * @param eInstance     TBU Instance Index
 * @param pConfig Timestamp 0 InitStruct
 */
void EFTU_TBU_SetTS0(EFTU_TBU_InstanceType  eInstance, EFTU_TBU_Ts0ChannelConfigStruct *pConfig)
{
    EFTU_TBU_Type *pTbu = s_pEftuTbuBasePtrs[eInstance];

    EFTU_TBU_HWA_SetTs0Src(pTbu, pConfig->eClkSrc);
    EFTU_TBU_HWA_SetChannel0BaseReg(pTbu, pConfig->eResolution);
    EFTU_TBU_HWA_SetChannelTS0(pTbu, pConfig->u32InitialValue);
    if (pConfig->bEnable == TRUE)
    {
        EFTU_TBU_HWA_EnableChannel(pTbu, (EFTU_TBU_ChnCntType)0U);
    }
}

/**
 * @brief Set Timestamp Counter 1/2 configuration
 * @param eInstance TBU Instance Index
 * @param pConfig Timestamp 1/2 InitStruct
 */
void EFTU_TBU_SetTS12(EFTU_TBU_InstanceType  eInstance,  EFTU_TBU_Ts12ChannelConfigStruct *pConfig)
{
    EFTU_TBU_Type *pTbu = s_pEftuTbuBasePtrs[eInstance];

    if (pConfig->eChannel == EFTU_TBU_CNT1)
    {
        EFTU_TBU_HWA_SetTs1Src(pTbu, pConfig->eClkSrc);
        EFTU_TBU_HWA_SetChannelTS1(pTbu, pConfig->u32InitialValue);
    }
    else /*(pConfig->eChannel == EFTU_TBU_CNT2)*/
    {
        EFTU_TBU_HWA_SetTs2Src(pTbu, pConfig->eClkSrc);
        EFTU_TBU_HWA_SetChannelTS2(pTbu, pConfig->u32InitialValue);
    }
    if (pConfig->bEnable == TRUE)
    {
        EFTU_TBU_HWA_EnableChannel(pTbu, pConfig->eChannel);
    }
}

/**
 * @brief Set Timestamp Counter 3 configuration
 * @param eInstance TBU Instance Index
 * @param pConfig Orthogonal decoding InitStruct
 */
void EFTU_TBU_SetQD(EFTU_TBU_InstanceType  eInstance, EFTU_TBU_QDConfigStruct *pConfig)
{
    EFTU_TBU_Type *pTbu = s_pEftuTbuBasePtrs[eInstance];
    EFTU_TBU_HWA_SetChannel3Mode(pTbu, pConfig->TbuCnt3QDMode);
    EFTU_TBU_HWA_SetChannel3Src(pTbu, pConfig->eTbuch3CounterSrc);
    EFTU_TBU_HWA_SetChannel3MARK(pTbu, pConfig->u32Modulo);
}

/**
 * @brief Get the QD Counter
 * @param eInstance TBU Instance Index
 * @return The QD counter
 */
uint32_t EFTU_TBU_GetQDCounter(EFTU_TBU_InstanceType  eInstance)
{
    EFTU_TBU_Type *pTbu = s_pEftuTbuBasePtrs[eInstance];
    return EFTU_TBU_HWA_GetChannelTS3(pTbu);
}

/**
 * @brief Get the QD Counter Capture Value.
 * @param eInstance TBU Instance Index
 * @return The QD Counter Capture Value.
 */
uint32_t EFTU_TBU_GetQDCapture(EFTU_TBU_InstanceType  eInstance)
{
    EFTU_TBU_Type *pTbu = s_pEftuTbuBasePtrs[eInstance];
    return EFTU_TBU_HWA_GetChannel3Capture(pTbu);
}

#if EFTU_EAC_SUPPORT == STD_ON


void EFTU_TBU_EAC_Init(EFTU_TBU_InstanceType eInstance, EFTU_TBU_EAC_ConfigType *pConfig)
{
    EFTU_TBU_Type *pTbu = s_pEftuTbuBasePtrs[eInstance];
    uint32_t u32EacCtrl = 0U;

    u32EacCtrl |= EFTU_TBU_EAC_CTRL_ANGLE_MODE_MASK;
    if(pConfig->bUpdateErrCnt == TRUE)
    {
        u32EacCtrl |= EFTU_TBU_EAC_CTRL_CNT_NO_UP_MASK;
    }
    if(pConfig->bHaltInDebug == TRUE)
    {
        u32EacCtrl |= EFTU_TBU_EAC_CTRL_HALT_ENABLE_MASK;
    }
    u32EacCtrl |=  EFTU_TBU_EAC_CTRL_EDGE_SEL(pConfig->activeEdge.eEacEdgeSelect);
    u32EacCtrl |= EFTU_TBU_EAC_CTRL_PRESCALER(pConfig->activeEdge.eFpsck);
    u32EacCtrl |= EFTU_TBU_EAC_CTRL_TCRCF(pConfig->activeEdge.eTcrDiv);
   
    /*Clear counter*/
    EFTU_TBU_HWA_EacSwClearCnt(pTbu);
    EFTU_TBU_HWA_SetCtrl(pTbu,u32EacCtrl);
}
#endif

#endif /* defined(EFTU_INSTANCE_COUNT) && (EFTU_INSTANCE_COUNT > 0) */




