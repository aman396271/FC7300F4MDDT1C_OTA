/**
 * @file module_driver_sdadc.c
 * @author flagchip
 * @brief SDADC driver source code
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
 *   0.1.0       2024-07-25    Flagchip0084   N/A          First version for FC7300
 ******************************************************************************** */

#include "module_driver_sdadc.h"

#if SDADC_INSTANCE_COUNT > 0U

#include "module_driver_scg.h"
#include "module_driver_pcc.h"

#define SDADC_NISR_CH0_MASK        0x00010101u
#define SDADC_ABNISR0_CH0_MASK     0x01010101u
#define SDADC_ABNISR1_CH0_MASK     0x01010101u
#define SDADC_EXTIS_CH0_MASK       0x01010101u
#define LN2VALUE                   0.69314718056f
#define COMPUTATIONAL_ACCURACY_POS 1e-5f
#define COMPUTATIONAL_ACCURACY_NEG -1e-5f

static SDADC_Type *const s_apSdadcBase[SDADC_INSTANCE_COUNT] = SDADC_BASE_PTRS;

void SDADC_ClearChannelIntFlags(SDADC_HandleType *pSdadcHandle, uint8_t u8ChannelIndex);

static float _pow2(float exponent)
{
    float result = 1.0f;
    float term   = 1.0f;
    float x      = exponent * LN2VALUE;
    int   n      = 1;

    while (term > COMPUTATIONAL_ACCURACY_POS || term < COMPUTATIONAL_ACCURACY_NEG)
    {
        term *= x / (float)n;
        result += term;
        n++;
    }

    return result;
}

static float _Log2(float x)
{
    int exponent = 0;
    while (x >= 2.0f)
    {
        x /= 2.0f;
        exponent++;
    }
    while (x < 1.0f)
    {
        x *= 2.0f;
        exponent--;
    }

    x /= 2.0f;
    exponent++;

    float ln_x = 0.0f;
    float term = x - 1.0f;
    int   n    = 1;

    while (term > COMPUTATIONAL_ACCURACY_POS || term < COMPUTATIONAL_ACCURACY_NEG)
    {
        ln_x += term / (float)n;
        term *= -(x - 1.0f);
        n++;
    }

    return (float)exponent + ln_x / LN2VALUE;
}

static uint32_t _ceilFloat(float xValue)
{
    uint32_t u32Part = (uint32_t)xValue;
    uint32_t u32Ret;
    if (xValue > (float)u32Part)
    {
        u32Ret = (u32Part + 1U);
    }
    else
    {
        u32Ret = u32Part;
    }
    return u32Ret;
}

static uint32_t _cacuGainFactor(uint8_t u8Order, uint16_t u16Osr, uint32_t u32OptValue)
{
    float    fTemp;
    float    fSum = 1.0F;
    uint32_t u32Ret;

    if (u16Osr > 0 && (u16Osr & (u16Osr - 1)) == 0)
    {
        u32Ret = u32OptValue;
    }
    else
    {
        fTemp  = u8Order * _Log2((float)u16Osr);
        fSum   = _pow2((float)_ceilFloat(fTemp) - fTemp);
        u32Ret = (uint32)(fSum * (float)u32OptValue);
    }

    return u32Ret;
}

static uint32_t SDADC_CacuMFShift(const SDADC_ChannelInitType *const pInitCfg)
{
    SDADC_FilterChainCfgType *const pFCInitCfg = pInitCfg->pFilterChainCfg;

    uint32_t u32Temp;
    uint32_t u32Mfshift;
    if ((pFCInitCfg->u16MainOSR & (pFCInitCfg->u16MainOSR - 1)) == 0)
    {
        uint16_t u16Temp = pFCInitCfg->u16MainOSR;
        uint32_t u32Pow  = 0;
        while ((u16Temp >> 1U) != 0)
        {
            u16Temp >>= 1U;
            u32Pow++;
        }
        u32Temp = pFCInitCfg->eMainOrder * u32Pow + 1U - (uint32_t)(pInitCfg->eResultFmt);
    }
    else
    {
        float fTemp;
        fTemp   = _Log2((float)pFCInitCfg->u16MainOSR);
        u32Temp = _ceilFloat(pFCInitCfg->eMainOrder * fTemp) + 1 - (uint32_t)(pInitCfg->eResultFmt);
    }

    if (u32Temp < SDADC_MFSHIFT_DATALENGTH)
    {
        u32Mfshift = SDADC_MFSHIFT_LEFT | (SDADC_MFSHIFT_DATALENGTH - u32Temp);
    }
    else
    {
        u32Mfshift = SDADC_MFSHIFT_RIGHT | (u32Temp - SDADC_MFSHIFT_DATALENGTH);
    }
    return u32Mfshift;
}

static void SDADC_ModulatorInit(SDADC_HandleType *pSdadcHandle, uint8_t u8ChannelIndex, const SDADC_ModulatorCfgType *const pInitCfg, SDADC_MASELType eMasel)
{
    uint32_t          u32TempValue;
    SDADC_Type *const pSdadc = s_apSdadcBase[pSdadcHandle->eInstance];

    u32TempValue = SDADC_CMACSR_MASEL(eMasel) | SDADC_CMACSR_MACLKSEL(pInitCfg->eMaClkSrc) | SDADC_CMACSR_RSTSEL(pInitCfg->u8ResetCycle) |
                   SDADC_CMACSR_DITHER_EN(pInitCfg->eDitherEnable) | SDADC_CMACSR_INCFGPV11(pInitCfg->ePosV11) | SDADC_CMACSR_GAINSEL(pInitCfg->eGain) |
                   SDADC_CMACSR_CMENP(pInitCfg->u8PosInputCommonVolModeMask) | SDADC_CMACSR_CMENM(pInitCfg->u8NegInputCommonVolModeMask) |
                   SDADC_CMACSR_INCFGP(pInitCfg->ePosInputSrc) | SDADC_CMACSR_INCFGM(pInitCfg->eNegInputSrc) | SDADC_CMACSR_INSEL(pInitCfg->eInputSel) |
                   SDADC_CMACSR_INMOD(pInitCfg->eInputSelMode);
    pSdadc->CMACSR[u8ChannelIndex] = u32TempValue;
}

static void SDADC_FilterChainInit(SDADC_HandleType *pSdadcHandle, uint8_t u8ChannelIndex, const SDADC_FilterChainCfgType *const pInitCfg)
{
    uint32_t          u32TempValue;
    SDADC_Type *const pSdadc = s_apSdadcBase[pSdadcHandle->eInstance];

    u32TempValue = SDADC_CRTCSR_DLY_TRG(pInitCfg->tRectCfg.u8SignDelayTsignPosEdge) | SDADC_CRTCSR_CTRGSIGN_OEN(pInitCfg->tRectCfg.eChannelTrgSignOutEnable) |
                   SDADC_CRTCSR_SSCH(pInitCfg->tRectCfg.eSignSignalChSel) | SDADC_CRTCSR_SSRC(pInitCfg->tRectCfg.eSignSignalSrcSel);
    pSdadc->CRTCSR[u8ChannelIndex] = u32TempValue;
    u32TempValue                   = SDADC_CSDR_DLY_NEG(pInitCfg->tRectCfg.u8SignNegDelay) | SDADC_CSDR_DLY_POS(pInitCfg->tRectCfg.u8SignPosDelay);
    pSdadc->CSDR[u8ChannelIndex]   = u32TempValue;

    u32TempValue = SDADC_CICFR_NVALINT(pInitCfg->tIntgraterCfg.u8IntgratorCnt - 1) | SDADC_CICFR_NVALDIS(pInitCfg->tIntgraterCfg.u8IntgratorDiscardCnt) |
                   SDADC_CICFR_SYNC_TRGEN(pInitCfg->tIntgraterCfg.eSyncSrc) | SDADC_CICFR_SYNC_TRGSEL(pInitCfg->tIntgraterCfg.u8SyncTrgSel) |
                   SDADC_CICFR_NVALREP(pInitCfg->tIntgraterCfg.u8IntgratorRepeatCnt - 1) | SDADC_CICFR_ITRSEL(pInitCfg->tIntgraterCfg.eTrgType) |
                   SDADC_CICFR_HTRPOL(pInitCfg->tIntgraterCfg.eHWTrgPolarity) | SDADC_CICFR_FCRC(pInitCfg->tIntgraterCfg.u8RestartFilterOnStart) |
                   SDADC_CICFR_EXTSTP(pInitCfg->tIntgraterCfg.eStopControl) | SDADC_CICFR_IOGT(pInitCfg->tIntgraterCfg.eGateControl) |
                   SDADC_CICFR_ISVAL(pInitCfg->tIntgraterCfg.u8IntgratShiftValue);
    pSdadc->CICFR[u8ChannelIndex] = u32TempValue;

    u32TempValue = SDADC_CDR_AFCM(pInitCfg->eAuxFilterMode) | SDADC_CDR_MFCM(pInitCfg->eMainFilterMode) | SDADC_CDR_AFORD(pInitCfg->eAuxOrder) |
                   SDADC_CDR_MFORD(pInitCfg->eMainOrder) | SDADC_CDR_AFOSR(pInitCfg->u16AuxOSR - 1) | SDADC_CDR_MFOSR(pInitCfg->u16MainOSR - 1);
    SDADC_HWA_SetCDRn(pSdadc, u8ChannelIndex, u32TempValue);

    u32TempValue = SDADC_CCR_INTG_EN(pInitCfg->u8IntgraterEnable) | SDADC_CCR_RECT_EN(pInitCfg->u8RectEnable) | SDADC_CCR_AF_EN(pInitCfg->eAuxFilterMode) |
                   SDADC_CCR_MF_EN(pInitCfg->u8MainFilterEnable) | SDADC_CCR_DBG_SEL(pInitCfg->u32DebugSel);
    u32TempValue =
        (SDADC_HWA_GetCCRn(pSdadc, u8ChannelIndex) & ~(SDADC_CCR_INTG_EN_MASK | SDADC_CCR_RECT_EN_MASK | SDADC_CCR_AF_EN_MASK | SDADC_CCR_MF_EN_MASK | SDADC_CCR_DBG_SEL_MASK)) |
        u32TempValue;
    SDADC_HWA_SetCCRn(pSdadc, u8ChannelIndex, u32TempValue);

    if (pInitCfg->eGainCompMode == SDADC_GAIN_CMP_BYPASS)
    {
        pSdadc->CGNR[u8ChannelIndex] = 0;
        SDADC_HWA_SetBIAS(pSdadc, u8ChannelIndex, 0);
    }
    else if (pInitCfg->eGainCompMode == SDADC_GAIN_CMP_INTERNAL_GAIN1)
    {
        pSdadc->CGNR[u8ChannelIndex] = _cacuGainFactor(pInitCfg->eMainOrder, pInitCfg->u16MainOSR, SDADC_HWA_GetGainOPT0(pSdadc, u8ChannelIndex));
        SDADC_HWA_SetBIAS(pSdadc, u8ChannelIndex, (SDADC_HWA_GetOffsetOPT0(pSdadc, u8ChannelIndex) << 8U));
    }
    else if (pInitCfg->eGainCompMode == SDADC_GAIN_CMP_INTERNAL_GAIN2)
    {
        pSdadc->CGNR[u8ChannelIndex] = _cacuGainFactor(pInitCfg->eMainOrder, pInitCfg->u16MainOSR, SDADC_HWA_GetGainOPT1(pSdadc, u8ChannelIndex));
        SDADC_HWA_SetBIAS(pSdadc, u8ChannelIndex, (SDADC_HWA_GetOffsetOPT1(pSdadc, u8ChannelIndex) << 8U));
    }
    else
    {
        pSdadc->CGNR[u8ChannelIndex] = pInitCfg->u32GainFactor & SDADC_CGNR_GAIN_FAC_MASK;
        SDADC_HWA_SetBIAS(pSdadc, u8ChannelIndex, (uint32_t)((pInitCfg->s32Offset) >> 8U));
    }
}

static void SDADC_BiasInit(SDADC_HandleType *pSdadcHandle, const SDADC_InitType *const pInitCfg)
{
    SDADC_Type *const      pSdadc      = s_apSdadcBase[pSdadcHandle->eInstance];
    SDADC_ChannelInitType *pChannelCfg = NULL;
    uint8_t                u8HrefValue = 0;

    for (uint8_t i = 0; i < SDADC_CHANNEL_CNT; i++)
    {
        if ((pInitCfg->pChannelCfg)[i] != NULL)
        {
            pChannelCfg = (pInitCfg->pChannelCfg)[i];
            u8HrefValue |= (uint8_t)(1U << (i));
            SDADC_HWA_SetCMENP(pSdadc, i, pChannelCfg->u8BiasPositiveInputMask);
            SDADC_HWA_SetCMENM(pSdadc, i, pChannelCfg->u8BiasNegativeInputMask);
        }
    }
    if (u8HrefValue)
    {
        uint32_t u32BSTCValue;
        SDADC_HWA_SetHFVREF_EN(pSdadc, u8HrefValue);
        SDADC_HWA_SetVCM_BEN(pSdadc, 1U);

        u32BSTCValue = pInitCfg->u32FunctionClk / (1U << (uint8_t)(pInitCfg->ePrescale)) / pInitCfg->u8CLKDiv / 2U;
        u32BSTCValue /= 500000U;
        u32BSTCValue += 1U;
        /*BSTC need 2us stable time(div_clk1)*/
        SDADC_HWA_SetBSTC(pSdadc, u32BSTCValue);
        SDADC_HWA_SetBIAS_EN(pSdadc, 1U);
    }
}

static void SDADC_DetectInit(SDADC_HandleType *pSdadcHandle, uint8_t u8ChannelIndex, SDADC_DetectCfgType *const pInitCfg)
{
    SDADC_Type *const pSdadc = s_apSdadcBase[pSdadcHandle->eInstance];
    uint32_t          u32TempValue;

    u32TempValue = SDADC_CCR_LMT_SEL(pInitCfg->eLmtCheckSrc) | SDADC_CCR_ZCD_SEL(pInitCfg->eZCDCheckSrc) | SDADC_CCR_LMT_EN(pInitCfg->u8LmtCheckEnable) |
                   SDADC_CCR_ZCD_EN(pInitCfg->u8ZCDCheckEnable) | SDADC_CCR_CAD_EN(pInitCfg->u8ClkAbsenceCheckEnable) | SDADC_CCR_SCD_EN(pInitCfg->u8ShortCircutCheckEnable);
    u32TempValue = (SDADC_HWA_GetCCRn(pSdadc, u8ChannelIndex) &
                    ~(SDADC_CCR_LMT_SEL_MASK | SDADC_CCR_ZCD_SEL_MASK | SDADC_CCR_LMT_EN_MASK | SDADC_CCR_ZCD_EN_MASK | SDADC_CCR_CAD_EN_MASK | SDADC_CCR_SCD_EN_MASK)) |
                   u32TempValue;
    SDADC_HWA_SetCCRn(pSdadc, u8ChannelIndex, u32TempValue);

    u32TempValue = SDADC_CPR_HLMT_BKEN(pInitCfg->u8HighLimitReachBreakEnable) | SDADC_CPR_WLMT_BKEN(pInitCfg->u8WindowLimitReachBreakEnable) |
                   SDADC_CPR_LLMT_BKEN(pInitCfg->u8LowLimitReachBreakEnable) | SDADC_CPR_SCD_BKEN(pInitCfg->u8ShortCircuitDetectBreakEnable) |
                   SDADC_CPR_CAD_BKEN(pInitCfg->u8ClockAbsenceDetectBreakEnable) | SDADC_CPR_LMTF_PROTEN(pInitCfg->u8LMTFlagProtectionEnable) |
                   SDADC_CPR_LMTR_PROTEN(pInitCfg->u8LMTResultProtectionEnable) | SDADC_CPR_HYSTR_PROTEN(pInitCfg->u8LMTHysteresisProtectionEnable) |
                   SDADC_CPR_SCD_PROTEN(pInitCfg->u8SCDFlagProtectionEnable) | SDADC_CPR_CAD_PROTEN(pInitCfg->u8CADFlagProtectionEnable) | SDADC_CPR_LMTAVT(pInitCfg->eLMTAvtType) |
                   SDADC_CPR_CADLMT(pInitCfg->u8ClkAbsenceCnt) | SDADC_CPR_LMTOPT(pInitCfg->eLMTOptType) | SDADC_CPR_SCDOPT(pInitCfg->eSCDOptType) |
                   SDADC_CPR_SCDCM(pInitCfg->eSCDCmtType) | SDADC_CPR_SCDLMT(pInitCfg->u8SCDLmtCnt);
    SDADC_HWA_SetCPRn(pSdadc, u8ChannelIndex, u32TempValue);

    SDADC_HWA_SetCLLMTn(pSdadc, u8ChannelIndex, (pInitCfg->u32LowLmt) << SDADC_CLLMT_LOLMT_SHIFT);
    SDADC_HWA_SetCHLMTn(pSdadc, u8ChannelIndex, (pInitCfg->u32HighLmt) << SDADC_CHLMT_HILMT_SHIFT);
}

static void SDADC_ChannelInit(SDADC_HandleType *pSdadcHandle, uint8_t u8ChannelIndex, const SDADC_ChannelInitType *const pChannelCfg)
{
    uint32_t          u32TempValue;
    SDADC_Type *const pSdadc = s_apSdadcBase[pSdadcHandle->eInstance];

    u32TempValue = SDADC_CCR_DMA_EN(pChannelCfg->u8DMAEnable) | SDADC_CCR_FIFO_EN(pChannelCfg->u8FIFOEnable);
    u32TempValue = (SDADC_HWA_GetCCRn(pSdadc, u8ChannelIndex) & ~(SDADC_CCR_DMA_EN_MASK | SDADC_CCR_FIFO_EN_MASK)) | u32TempValue;
    SDADC_HWA_SetCCRn(pSdadc, u8ChannelIndex, u32TempValue);

    u32TempValue = SDADC_CFR_SYNC_TRGEN(pChannelCfg->eSyncSrc) | SDADC_CFR_TRGLVL(pChannelCfg->eTrgLevel) | SDADC_CFR_SYNC_TRGSEL(pChannelCfg->u8SyncTrgSel) |
                   SDADC_CFR_TRGSEL(pChannelCfg->eTrgType) | SDADC_CFR_CLKSEL(pChannelCfg->eRcvClkSel) | SDADC_CFR_FWMK(pChannelCfg->u8FIFOWaterMark) |
                   SDADC_CFR_RDFMT(pChannelCfg->eResultFmt) | SDADC_CFR_MFSHIFT(SDADC_CacuMFShift(pChannelCfg));

    if (pChannelCfg->eResultFmt == SDADC_RDFMT_LEFT_JUSTIFIED_SIGNED)
    {
        u32TempValue |= SDADC_CFR_CUTOFF(pChannelCfg->u8HPFCutOff);
    }
    else
    {
        u32TempValue |= SDADC_CFR_CUTOFF(0);
    }

    if (pChannelCfg->u8InternalModulator == SDADC_MASEL_INTERNAL)
    {
        u32TempValue |= SDADC_CFR_CLKEDG(SDADC_CLKEDG_POSEDGE);
    }
    else
    {
        u32TempValue |= SDADC_CFR_IBFMT(pChannelCfg->eInputBitFormat) | SDADC_CFR_CLKEDG(pChannelCfg->eSyncSrc);
    }
    SDADC_HWA_SetCFRn(pSdadc, u8ChannelIndex, u32TempValue);

    u32TempValue = SDADC_CTSCNT_SYNC_TRGEN(pChannelCfg->eTsSyncSrc) | SDADC_CTSCNT_SYNC_TRGSEL(pChannelCfg->u8TsSyncTrgSel) | SDADC_CTSCNT_TSRDM(pChannelCfg->eTsReadMode) |
                   SDADC_CTSCNT_TSTRGM(pChannelCfg->eTsCounterTriggerMode) | SDADC_CTSCNT_INMXCP(pChannelCfg->eTsInputMuxCopy) | SDADC_CTSCNT_TS_EN(pChannelCfg->eTsCounterEnable) |
                   SDADC_CTSCNT_TSCLKSEL(pChannelCfg->eTsCounterClkDiv);
    pSdadc->CTSCNT[u8ChannelIndex] = u32TempValue;
}

static void SDADC_InterruptInit(SDADC_HandleType *pSdadcHandle, const SDADC_InitType *const pInitCfg)
{
    SDADC_Type *const      pSdadc          = s_apSdadcBase[pSdadcHandle->eInstance];
    SDADC_ChannelInitType *pChannelCfg     = NULL;
    uint32_t               NormalIntCfg    = 0x0U;
    uint32_t               AbnormalIntCfg0 = 0x0U;
    uint32_t               AbnormalIntCfg1 = 0x0U;
    uint32_t               ExtIntCfg       = 0x0U;
    for (uint8_t i = 0; i < SDADC_CHANNEL_CNT; i++)
    {
        if ((pInitCfg->pChannelCfg)[i] != NULL)
        {
            pChannelCfg = (pInitCfg->pChannelCfg)[i];

            if (pChannelCfg->tIntCfg.u8COCIrqEnable)
            {
                NormalIntCfg |= SDADC_NIER_COCIE0_MASK << (i);
            }
            if (pChannelCfg->tIntCfg.u8FIFOReadyIrqEnable)
            {
                NormalIntCfg |= SDADC_NIER_FRDYIE0_MASK << (i);
            }
            if (pChannelCfg->tIntCfg.u8ZeroCrossDetectIrqEnable)
            {
                NormalIntCfg |= SDADC_NIER_ZCDIE0_MASK << (i);
            }

            if (pChannelCfg->tIntCfg.u8HighLimitReachIrqEnable)
            {
                AbnormalIntCfg0 |= SDADC_ABNIER0_HLMTIE0_MASK << (i);
            }
            if (pChannelCfg->tIntCfg.u8LowLimitReachIrqEnable)
            {
                AbnormalIntCfg0 |= SDADC_ABNIER0_LLMTIE0_MASK << (i);
            }
            if (pChannelCfg->tIntCfg.u8WindowLimitReachIrqEnable)
            {
                AbnormalIntCfg0 |= SDADC_ABNIER0_WLMTIE0_MASK << (i);
            }
            if (pChannelCfg->tIntCfg.u8ShortCircuitDetectIrqEnable)
            {
                AbnormalIntCfg0 |= SDADC_ABNIER0_SCDIE0_MASK << (i);
            }

            if (pChannelCfg->tIntCfg.u8DataSaturationDetectIrqEnable)
            {
                AbnormalIntCfg1 |= SDADC_ABNIER1_SATIE0_MASK << (i);
            }
            if (pChannelCfg->tIntCfg.u8ClockAbsenceDetectIrqEnable)
            {
                AbnormalIntCfg1 |= SDADC_ABNIER1_CADIE0_MASK << (i);
            }
            if (pChannelCfg->tIntCfg.u8FIFOOverFlowIrqEnable)
            {
                AbnormalIntCfg1 |= SDADC_ABNIER1_FOVFIE0_MASK << (i);
            }
            if (pChannelCfg->tIntCfg.u8FIFOUnderFlowIrqEnable)
            {
                AbnormalIntCfg1 |= SDADC_ABNIER1_FUNFIE0_MASK << (i);
            }

            if (pChannelCfg->tIntCfg.u8SignDelayCaptureIrqEnable)
            {
                ExtIntCfg |= SDADC_EXTIS_SD_CAPVLD0_MASK << (i);
            }
            if (pChannelCfg->tIntCfg.u8TSignChangedIrqEnable)
            {
                ExtIntCfg |= SDADC_EXTIS_TSIGN_P2N0_MASK << (i);
            }
            if (pChannelCfg->tIntCfg.u8TSValidIrqEnable)
            {
                ExtIntCfg |= SDADC_EXTIS_TSVLD0_MASK << (i);
            }
        }
    }

    pSdadc->NISR    = 0xFFFFFFFFU;
    pSdadc->NIER    = NormalIntCfg;
    pSdadc->ABNISR0 = 0xFFFFFFFFU;
    pSdadc->ABNIER0 = AbnormalIntCfg0;
    pSdadc->ABNISR1 = 0xFFFFFFFFU;
    pSdadc->ABNIER1 = AbnormalIntCfg1;
    pSdadc->EXTIS   = 0xFFFFFFFFU;
    pSdadc->EXTIE   = ExtIntCfg;
}

#if SDADC_DEV_ERROR_REPORT == STD_ON
static uint8_t SDADC_InitParamCheck(const SDADC_InitType *const pInitCfg, uint8_t u8FunctionID)
{
    SDADC_ChannelInitType *pChannelCfg;
    uint8_t                u8CheckFailed = 0;

    if (pInitCfg == NULL)
    {
        u8CheckFailed = 1;
        return u8CheckFailed;
    }

    for (uint8_t i = 0; i < SDADC_CHANNEL_CNT; i++)
    {
        if ((pInitCfg->pChannelCfg)[i] != NULL)
        {
            pChannelCfg = (pInitCfg->pChannelCfg)[i];

            if (pChannelCfg->eResultFmt != SDADC_RDFMT_LEFT_JUSTIFIED_SIGNED && pChannelCfg->u8HPFCutOff == 0)
            {
                u8CheckFailed = 1;
                break;
            }
            if (pChannelCfg->eTsReadMode == SDADC_TSRDM_DIRECT_MODE && pChannelCfg->u8FIFOEnable != 0)
            {
                u8CheckFailed = 1;
                break;
            }
            if (pChannelCfg->pFilterChainCfg)
            {
                if (pChannelCfg->pFilterChainCfg->tIntgraterCfg.eTrgType == SDADC_TRGSEL_HARDWARE && pChannelCfg->eTrgType == SDADC_TRGSEL_HARDWARE)
                {
                    u8CheckFailed = 1;
                    break;
                }
            }
            if (pChannelCfg->pModulatorCfg && pChannelCfg->pFilterChainCfg)
            {
                if (((pChannelCfg->pModulatorCfg)->eInputSelMode != SDADC_INMOD_SOFTWARE_CONTROL) && ((pChannelCfg->pFilterChainCfg)->eAuxFilterMode == SDADC_AFCM_ALWAYS_ON))
                {
                    u8CheckFailed = 1;
                    break;
                }
            }
        }
    }
    if (u8CheckFailed)
    {
        SDADC_ReportDevError(u8FunctionID, SDADC_E_PARAM_INSTANCE);
    }
    return u8CheckFailed;
}

static uint8_t SDADC_HandleChannelCheck(SDADC_HandleType *pSdadcHandle, uint8_t u8ChannelIndex, uint8_t u8FunctionID)
{
    uint8_t u8CheckFailed = 0;

    if (pSdadcHandle == NULL)
    {
        u8CheckFailed = 1;
        SDADC_ReportDevError(u8FunctionID, SDADC_E_PARAM_POINTER);
    }
    else if (pSdadcHandle->eInstance >= SDADC_INSTANCE_COUNT)
    {
        u8CheckFailed = 1;
        SDADC_ReportDevError(u8FunctionID, SDADC_E_PARAM_INSTANCE);
    }
    else if (u8ChannelIndex >= SDADC_CHANNEL_CNT)
    {
        u8CheckFailed = 1;
        SDADC_ReportDevError(u8FunctionID, SDADC_E_PARAM_CHANNEL);
    }
    return u8CheckFailed;
}

static uint8_t SDADC_HandleCheck(SDADC_HandleType *pSdadcHandle, uint8_t u8FunctionID)
{
    uint8_t u8CheckFailed = 0;

    if (pSdadcHandle == NULL)
    {
        u8CheckFailed = 1;
        SDADC_ReportDevError(u8FunctionID, SDADC_E_PARAM_POINTER);
    }
    else if (pSdadcHandle->eInstance >= SDADC_INSTANCE_COUNT)
    {
        u8CheckFailed = 1;
        SDADC_ReportDevError(u8FunctionID, SDADC_E_PARAM_INSTANCE);
    }

    return u8CheckFailed;
}
#endif

void SDADC_ClearChannelIntFlags(SDADC_HandleType *pSdadcHandle, uint8_t u8ChannelIndex)
{
    SDADC_Type *const pSdadc = s_apSdadcBase[pSdadcHandle->eInstance];
    SDADC_HWA_SetNISR(pSdadc, SDADC_NISR_CH0_MASK << u8ChannelIndex);
    SDADC_HWA_SetABNISR0(pSdadc, SDADC_ABNISR0_CH0_MASK << u8ChannelIndex);
    SDADC_HWA_SetABNISR1(pSdadc, SDADC_ABNISR1_CH0_MASK << u8ChannelIndex);
    SDADC_HWA_SetEXTIS(pSdadc, SDADC_EXTIS_CH0_MASK << u8ChannelIndex);
}

void SDADCn_IRQHandler(SDADC_HandleType *pSdadcHandle, uint8_t u8ChannelIndex)
{
    SDADC_Type *const pSdadc = s_apSdadcBase[pSdadcHandle->eInstance];
    uint32_t          u32NIInt;
    uint32_t          u32ABInt0;
    uint32_t          u32ABInt1;
    uint32_t          u32EXInt;

    u32NIInt = (pSdadc->NISR);
    u32NIInt &= pSdadc->NIER;
    u32NIInt &= (SDADC_NISR_CH0_MASK << u8ChannelIndex);

    u32ABInt0 = (pSdadc->ABNISR0);
    u32ABInt0 &= pSdadc->ABNIER0;
    u32ABInt0 &= (SDADC_ABNISR0_CH0_MASK << u8ChannelIndex);

    u32ABInt1 = (pSdadc->ABNISR1);
    u32ABInt1 &= pSdadc->ABNIER1;
    u32ABInt1 &= (SDADC_ABNISR1_CH0_MASK << u8ChannelIndex);

    u32EXInt = (pSdadc->EXTIS);
    u32EXInt &= pSdadc->EXTIE;
    u32EXInt &= (SDADC_EXTIS_CH0_MASK << u8ChannelIndex);
    SDADC_ClearChannelIntFlags(pSdadcHandle, u8ChannelIndex);

    if (u32NIInt)
    {
        if ((u32NIInt & (SDADC_NISR_COC0_MASK << u8ChannelIndex)) && (pSdadcHandle->tSettings.pCOCISRCallback != NULL))
        {
            pSdadcHandle->tSettings.pCOCISRCallback(pSdadcHandle, u8ChannelIndex);
        }
        if ((u32NIInt & (SDADC_NISR_FRDY0_MASK << u8ChannelIndex)) && (pSdadcHandle->tSettings.pFIFOISRCallback != NULL))
        {
            pSdadcHandle->tSettings.pFIFOISRCallback(pSdadcHandle, u8ChannelIndex, SDADC_FIFO_READY);
        }
        if ((u32NIInt & (SDADC_NISR_ZCD0_MASK << u8ChannelIndex)) && (pSdadcHandle->tSettings.pDetectISRCallback != NULL))
        {
            pSdadcHandle->tSettings.pDetectISRCallback(pSdadcHandle, u8ChannelIndex, SDADC_DET_ZERO_CROSS);
        }
    }

    if (u32ABInt0)
    {
        if ((u32ABInt0 & (SDADC_ABNISR0_SCD0_MASK << u8ChannelIndex)) && (pSdadcHandle->tSettings.pDetectISRCallback != NULL))
        {
            pSdadcHandle->tSettings.pDetectISRCallback(pSdadcHandle, u8ChannelIndex, SDADC_DET_SHORT_CIRCUIT);
        }
        if ((u32ABInt0 & (SDADC_ABNISR0_WLMT0_MASK << u8ChannelIndex)) && (pSdadcHandle->tSettings.pDetectISRCallback != NULL))
        {
            pSdadcHandle->tSettings.pDetectISRCallback(pSdadcHandle, u8ChannelIndex, SDADC_DET_WIN_LMT_REACH);
        }
        if ((u32ABInt0 & (SDADC_ABNISR0_HLMT0_MASK << u8ChannelIndex)) && (pSdadcHandle->tSettings.pDetectISRCallback != NULL))
        {
            pSdadcHandle->tSettings.pDetectISRCallback(pSdadcHandle, u8ChannelIndex, SDADC_DET_HIGH_LMT_REACH);
        }
        if ((u32ABInt0 & (SDADC_ABNISR0_LLMT0_MASK << u8ChannelIndex)) && (pSdadcHandle->tSettings.pDetectISRCallback != NULL))
        {
            pSdadcHandle->tSettings.pDetectISRCallback(pSdadcHandle, u8ChannelIndex, SDADC_DET_LOW_LMT_REACH);
        }
    }

    if (u32ABInt1)
    {
        if ((u32ABInt1 & (SDADC_ABNISR1_CAD0_MASK << u8ChannelIndex)) && (pSdadcHandle->tSettings.pDetectISRCallback != NULL))
        {
            pSdadcHandle->tSettings.pDetectISRCallback(pSdadcHandle, u8ChannelIndex, SDADC_DET_CLK_ABSENCE);
        }
        if ((u32ABInt1 & (SDADC_ABNISR1_SAT0_MASK << u8ChannelIndex)) && (pSdadcHandle->tSettings.pDetectISRCallback != NULL))
        {
            pSdadcHandle->tSettings.pDetectISRCallback(pSdadcHandle, u8ChannelIndex, SDADC_DET_DATA_SATURATION);
        }
        if ((u32ABInt1 & (SDADC_ABNISR1_FOVF0_MASK << u8ChannelIndex)) && (pSdadcHandle->tSettings.pFIFOISRCallback != NULL))
        {
            pSdadcHandle->tSettings.pFIFOISRCallback(pSdadcHandle, u8ChannelIndex, SDADC_FIFO_OVERFLOW);
        }
        if ((u32ABInt1 & (SDADC_ABNISR1_FUNF0_MASK << u8ChannelIndex)) && (pSdadcHandle->tSettings.pFIFOISRCallback != NULL))
        {
            pSdadcHandle->tSettings.pFIFOISRCallback(pSdadcHandle, u8ChannelIndex, SDADC_FIFO_UNDERFLOW);
        }
    }

    if (u32EXInt)
    {
        if ((u32EXInt & (SDADC_EXTIS_SD_CAPVLD0_MASK << u8ChannelIndex)) && (pSdadcHandle->tSettings.pSignDelayISRCallback != NULL))
        {
            pSdadcHandle->tSettings.pSignDelayISRCallback(pSdadcHandle, u8ChannelIndex);
        }
        if ((u32EXInt & (SDADC_EXTIS_TSIGN_P2N0_MASK << u8ChannelIndex)) && (pSdadcHandle->tSettings.pTSignChangeISRCallback != NULL))
        {
            pSdadcHandle->tSettings.pTSignChangeISRCallback(pSdadcHandle, u8ChannelIndex);
        }
        if ((u32EXInt & (SDADC_EXTIS_TSVLD0_MASK << u8ChannelIndex)) && (pSdadcHandle->tSettings.pTSValidISRCallback != NULL))
        {
            pSdadcHandle->tSettings.pTSValidISRCallback(pSdadcHandle, u8ChannelIndex);
        }
    }
}

void SDADC_InitCfg(SDADC_InitType *pInitCfg)
{
    if (pInitCfg == NULL)
    {
        return;
    }
    pInitCfg->u8BiasEnable  = 1;
    pInitCfg->ePrescale     = SDADC_PRESCALE_NO_PRESCALE;
    pInitCfg->eMenSel       = SDADC_MENSEL_INTERNAL;
    pInitCfg->u8CLKDiv      = 2;
    pInitCfg->u8Clk0Disable = 0;
    pInitCfg->u8Clk1Disable = 0;
    pInitCfg->u8Clk2Disable = 0;

    for (uint8_t i = 0; i < SDADC_CHANNEL_CNT; i++)
    {
        (pInitCfg->pChannelCfg)[i] = NULL;
    }

    pInitCfg->pPWMCfg                 = NULL;
    pInitCfg->pCOCISRCallback         = NULL;
    pInitCfg->pFIFOISRCallback        = NULL;
    pInitCfg->pDetectISRCallback      = NULL;
    pInitCfg->pSignDelayISRCallback   = NULL;
    pInitCfg->pTSignChangeISRCallback = NULL;
    pInitCfg->pTSValidISRCallback     = NULL;
}

void SDADC_InitChannelCfg(SDADC_ChannelInitType *pInitCfg)
{
    if (pInitCfg == NULL)
    {
        return;
    }
    pInitCfg->u8SyncTrgSel          = 0;
    pInitCfg->eSyncSrc              = SDADC_SYNC_TRGEN_SELF;
    pInitCfg->eTrgLevel             = SDADC_TRGLVL_EDGE;
    pInitCfg->eTrgType              = SDADC_TRGSEL_SOFTWARE;
    pInitCfg->eRcvClkSel            = SDADC_CLKSEL_DIV_CLK1;
    pInitCfg->u8HPFCutOff           = 0;
    pInitCfg->u8InternalModulator   = SDADC_MASEL_INTERNAL;
    pInitCfg->eClkEdg               = SDADC_CLKEDG_POSEDGE;
    pInitCfg->eInputBitFormat       = SDADC_IBFMT_ONE_BIT_STREAM;
    pInitCfg->eResultFmt            = SDADC_RDFMT_LEFT_JUSTIFIED_SIGNED;
    pInitCfg->u8TsSyncTrgSel        = 0;
    pInitCfg->eTsSyncSrc            = SDADC_SYNC_TRGEN_SELF;
    pInitCfg->eTsReadMode           = SDADC_TSRDM_DEFAULT_MODE;
    pInitCfg->eTsCounterTriggerMode = SDADC_TSTRGM_RISING_EDGE;
    pInitCfg->eTsInputMuxCopy       = SDADC_INMXCP_DISABLED;
    pInitCfg->eTsCounterEnable      = SDADC_TS_EN_ENABLED;
    pInitCfg->eTsCounterClkDiv      = SDADC_TSCLKSEL_MODULATOR_CLOCK;

    pInitCfg->u8FIFOEnable            = 0;
    pInitCfg->u8FIFOWaterMark         = 0;
    pInitCfg->u8DMAEnable             = 0;
    pInitCfg->u8BiasPositiveInputMask = 0;
    pInitCfg->u8BiasNegativeInputMask = 0;
    pInitCfg->tIntCfg                 = (SDADC_IntInitType){0};
    pInitCfg->pModulatorCfg           = NULL;
    pInitCfg->pFilterChainCfg         = NULL;
    pInitCfg->pDectectCfg             = NULL;
}

void SDADC_InitModulatorCfg(SDADC_ModulatorCfgType *pInitCfg)
{
    if (pInitCfg == NULL)
    {
        return;
    }
    pInitCfg->eMaClkSrc                   = SDADC_MACLKSEL_DIV_CLK1;
    pInitCfg->eDitherEnable               = SDADC_DITHER_EN_DISABLED;
    pInitCfg->u8ResetCycle                = 8;
    pInitCfg->ePosV11                     = SDADC_INCFGPV11_DISABLED;
    pInitCfg->eGain                       = SDADC_GAINSEL_1;
    pInitCfg->u8PosInputCommonVolModeMask = 0;
    pInitCfg->u8NegInputCommonVolModeMask = 0;
    pInitCfg->ePosInputSrc                = SDADC_INCFGP_FROM_PIN;
    pInitCfg->eNegInputSrc                = SDADC_INCFGM_FROM_PIN;
    pInitCfg->eInputSel                   = SDADC_INSEL_PIN_0;
    pInitCfg->eInputSelMode               = SDADC_INMOD_SOFTWARE_CONTROL;
}

void SDADC_InitPwmCfg(SDADC_PWMInitType *pInitCfg)
{
    if (pInitCfg == NULL)
    {
        return;
    }

    pInitCfg->eTrgSignOEN  = SDADC_TRGSIGN_OEN_DISABLED;
    pInitCfg->eClkSel      = SDADC_PWM_CLKSEL_DIV_CLK0;
    pInitCfg->eBitRev      = SDADC_BIT_REV_NORMAL;
    pInitCfg->ePwmPolarity = SDADC_PWM_POLARITY_POSITIVE;
    pInitCfg->ePwmPattern  = SDADC_PWM_PATTERN_STOPPED;
}

void SDADC_InitFilterChainCfg(SDADC_FilterChainCfgType *pInitCfg)
{
    if (pInitCfg == NULL)
    {
        return;
    }

    pInitCfg->u8IntgraterEnable                    = 0;
    pInitCfg->tIntgraterCfg.eSyncSrc               = SDADC_SYNC_TRGEN_SELF;
    pInitCfg->tIntgraterCfg.u8SyncTrgSel           = 0;
    pInitCfg->tIntgraterCfg.eHWTrgPolarity         = SDADC_HTRPOL_HIGH_RISING;
    pInitCfg->tIntgraterCfg.eTrgType               = SDADC_TRGSEL_HARDWARE;
    pInitCfg->tIntgraterCfg.u8RestartFilterOnStart = 0;
    pInitCfg->tIntgraterCfg.u8IntgratorCnt         = 1;
    pInitCfg->tIntgraterCfg.u8IntgratorDiscardCnt  = 0;
    pInitCfg->tIntgraterCfg.u8IntgratorRepeatCnt   = 1;
    pInitCfg->tIntgraterCfg.u8IntgratShiftValue    = 0;
    pInitCfg->tIntgraterCfg.eStopControl           = SDADC_EXTSTP_INTERNAL;
    pInitCfg->tIntgraterCfg.eGateControl           = SDADC_IOGT_ALWAYS_WORK;

    pInitCfg->u8RectEnable                      = 0;
    pInitCfg->tRectCfg.u8SignDelayTsignPosEdge  = 0;
    pInitCfg->tRectCfg.eChannelTrgSignOutEnable = SDADC_CTRGSIGN_OEN_DISABLED;
    pInitCfg->tRectCfg.eSignSignalChSel         = SDADC_SSCH_CH0;
    pInitCfg->tRectCfg.eSignSignalSrcSel        = SDADC_SSRC_INTERNAL_PWM;
    pInitCfg->tRectCfg.u8SignPosDelay           = 0;
    pInitCfg->tRectCfg.u8SignNegDelay           = 0;

    pInitCfg->u8MainFilterEnable = 0;
    pInitCfg->eMainFilterMode    = SDADC_MFCM_SINGLE_MODE;
    pInitCfg->eMainOrder         = SDADC_MFORD_THIRD_ORDER;
    pInitCfg->u16MainOSR         = 128;

    pInitCfg->u8AuxFilterEnable = 0;
    pInitCfg->eAuxFilterMode    = SDADC_AFCM_ALWAYS_ON;
    pInitCfg->eAuxOrder         = SDADC_AFORD_SECOND_ORDER;
    pInitCfg->u16AuxOSR         = 32;
    pInitCfg->eGainCompMode     = SDADC_GAIN_CMP_BYPASS;
    pInitCfg->u32GainFactor     = 0;
    pInitCfg->s32Offset         = 0;
}

void SDADC_InitDectCfg(SDADC_DetectCfgType *pInitCfg)
{
    if (pInitCfg == NULL)
    {
        return;
    }

    pInitCfg->u8LmtCheckEnable         = 0;
    pInitCfg->eLmtCheckSrc             = SDADC_SEL_AUXILIARY;
    pInitCfg->u8ZCDCheckEnable         = 0;
    pInitCfg->eZCDCheckSrc             = SDADC_SEL_AUXILIARY;
    pInitCfg->u8ClkAbsenceCheckEnable  = 0;
    pInitCfg->u8ShortCircutCheckEnable = 0;

    pInitCfg->u8HighLimitReachBreakEnable     = 0;
    pInitCfg->u8LowLimitReachBreakEnable      = 0;
    pInitCfg->u8WindowLimitReachBreakEnable   = 0;
    pInitCfg->u8ShortCircuitDetectBreakEnable = 0;
    pInitCfg->u8ClockAbsenceDetectBreakEnable = 0;

    pInitCfg->u8LMTFlagProtectionEnable       = 0;
    pInitCfg->u8LMTResultProtectionEnable     = 0;
    pInitCfg->u8LMTHysteresisProtectionEnable = 0;
    pInitCfg->u8SCDFlagProtectionEnable       = 0;
    pInitCfg->u8CADFlagProtectionEnable       = 0;
    pInitCfg->eLMTAvtType                     = SDADC_LMTAVT_SET_ON_LARGER_CLEAR_ON_SMALLER;
    pInitCfg->u8ClkAbsenceCnt                 = 0;
    pInitCfg->eLMTOptType                     = SDADC_LMTOPT_DETECT_BOTH_HIGH_AND_LOW;
    pInitCfg->eSCDOptType                     = SDADC_SCDOPT_COUNT_ON_BOTH_0_AND_1;
    pInitCfg->eSCDCmtType                     = SDADC_SCDCM_ALWAYS_ON;
    pInitCfg->u8SCDLmtCnt                     = 0;

    pInitCfg->u32HighLmt = 0x0;
    pInitCfg->u32LowLmt  = 0x0;
}

SDADC_RetStatusType SDADC_Init(SDADC_HandleType *pSdadcHandle, const SDADC_InitType *const pInitCfg)
{
    SDADC_RetStatusType eRet = SDADC_E_OK;
#if SDADC_DEV_ERROR_REPORT == STD_ON
    if (SDADC_HandleCheck(pSdadcHandle, SDADC_INIT_ID))
    {
        return SDADC_E_NOT_OK;
    }

    if (SDADC_InitParamCheck(pInitCfg, SDADC_INIT_ID))
    {
        return SDADC_E_NOT_OK;
    }
#endif
    SDADC_Type *const      pSdadc = s_apSdadcBase[pSdadcHandle->eInstance];
    SDADC_ChannelInitType *pChannelCfg;
    uint32_t               u32TempValue;
    uint8_t                i;

    SDADC_InterruptInit(pSdadcHandle, pInitCfg);

    u32TempValue = SDADC_CTRL_CLKO0_DIS(pInitCfg->u8Clk0Disable) | SDADC_CTRL_CLKO1_DIS(pInitCfg->u8Clk1Disable) | SDADC_CTRL_CLKO2_DIS(pInitCfg->u8Clk2Disable) |
                   SDADC_CTRL_PRESCALE(pInitCfg->ePrescale) | SDADC_CTRL_MCLK_DIV(pInitCfg->u8CLKDiv - 1) | SDADC_CTRL_MENSEL(pInitCfg->eMenSel);
    pSdadc->CTRL = u32TempValue;

    if (pInitCfg->pPWMCfg)
    {
        SDADC_PWMInitType *pPWMCfg = pInitCfg->pPWMCfg;
        pSdadc->PWM_GEN            = SDADC_PWM_GEN_TRGSIGN_OEN(pPWMCfg->eTrgSignOEN) | SDADC_PWM_GEN_POL(pPWMCfg->ePwmPolarity) | SDADC_PWM_GEN_BIT_REV(pPWMCfg->eBitRev) |
                          SDADC_PWM_GEN_CLKSEL(pPWMCfg->eClkSel) | SDADC_PWM_GEN_PATTERN(pPWMCfg->ePwmPattern);
    }

    for (i = 0; i < SDADC_CHANNEL_CNT; i++)
    {
        if ((pInitCfg->pChannelCfg)[i] != NULL)
        {
            pChannelCfg = (pInitCfg->pChannelCfg)[i];
            SDADC_ChannelInit(pSdadcHandle, i, pChannelCfg);
            if (pChannelCfg->pModulatorCfg)
            {
                SDADC_ModulatorInit(pSdadcHandle, i, pChannelCfg->pModulatorCfg, pChannelCfg->u8InternalModulator);
            }
            if (pChannelCfg->pFilterChainCfg)
            {
                SDADC_FilterChainInit(pSdadcHandle, i, pChannelCfg->pFilterChainCfg);
            }
            if (pChannelCfg->pDectectCfg)
            {
                SDADC_DetectInit(pSdadcHandle, i, pChannelCfg->pDectectCfg);
            }
        }
    }

    if (pInitCfg->u8BiasEnable)
    {
        SDADC_BiasInit(pSdadcHandle, pInitCfg);
    }

    pSdadcHandle->tSettings.pCOCISRCallback         = pInitCfg->pCOCISRCallback;
    pSdadcHandle->tSettings.pFIFOISRCallback        = pInitCfg->pFIFOISRCallback;
    pSdadcHandle->tSettings.pDetectISRCallback      = pInitCfg->pDetectISRCallback;
    pSdadcHandle->tSettings.pTSValidISRCallback     = pInitCfg->pTSValidISRCallback;
    pSdadcHandle->tSettings.pSignDelayISRCallback   = pInitCfg->pSignDelayISRCallback;
    pSdadcHandle->tSettings.pTSignChangeISRCallback = pInitCfg->pTSignChangeISRCallback;

    return eRet;
}

void SDADC_Deinit(SDADC_HandleType *pSdadcHandle, uint32_t RstHoldCount)
{
#if SDADC_DEV_ERROR_REPORT == STD_ON
    if (SDADC_HandleCheck(pSdadcHandle, SDADC_DEINIT_ID))
    {
        return;
    }
#endif
    SDADC_Type *const pSdadc = s_apSdadcBase[pSdadcHandle->eInstance];
    /* NOTE: Before asserting this bit, the interrupt(s) should be disabled by
        deasserting the corresponding NVIC Interrupt Set-Enable Register or
        deasserting the interrupt enable bit(s), and the DMA function should be
        disabled by deasserting the DMA enable bit or disabling the DMA
        channels via DMAMUX. */
    pSdadc->NIER = 0;
    pSdadc->ABNIER0 = 0;
    pSdadc->ABNIER1 = 0;
    pSdadc->EXTIE   = 0;
    SDADC_HWA_SetDMA_EN(pSdadc, 0, 0);
    SDADC_HWA_SetDMA_EN(pSdadc, 1, 0);
    SDADC_HWA_SetDMA_EN(pSdadc, 2, 0);
    SDADC_HWA_SetRESET(pSdadc, 1U);
    for (volatile uint32_t j = RstHoldCount; j > 0; j--)
        asm volatile("nop");
    SDADC_HWA_SetRESET(pSdadc, 0U);
    pSdadcHandle->tSettings.pCOCISRCallback         = NULL;
    pSdadcHandle->tSettings.pFIFOISRCallback        = NULL;
    pSdadcHandle->tSettings.pDetectISRCallback      = NULL;
    pSdadcHandle->tSettings.pSignDelayISRCallback   = NULL;
    pSdadcHandle->tSettings.pTSignChangeISRCallback = NULL;
    pSdadcHandle->tSettings.pTSValidISRCallback     = NULL;
}

void SDADC_ChannelEnable(SDADC_HandleType *pSdadcHandle, uint8_t u8ChannelIndex, uint8_t u8Enable)
{
#if SDADC_DEV_ERROR_REPORT == STD_ON
    if (SDADC_HandleChannelCheck(pSdadcHandle, u8ChannelIndex, SDADC_CHANNELENABLE_ID))
    {
        return;
    }
#endif
    SDADC_Type *const pSdadc = s_apSdadcBase[pSdadcHandle->eInstance];
    SDADC_HWA_SetCH_EN(pSdadc, u8ChannelIndex, u8Enable);
}

SDADC_RetStatusType SDADC_MainEnable(SDADC_HandleType *pSdadcHandle, uint8_t u8Enable)
{
#if SDADC_DEV_ERROR_REPORT == STD_ON
    if (SDADC_HandleCheck(pSdadcHandle, SDADC_MAIN_ENABLE_ID))
    {
        return SDADC_E_NOT_OK;
    }
#endif
    SDADC_RetStatusType eRet       = SDADC_E_OK;
    uint32_t            u32Counter = 0xFFFFFFFFU;
    SDADC_Type *const   pSdadc     = s_apSdadcBase[pSdadcHandle->eInstance];
    SDADC_HWA_SetMEN(pSdadc, u8Enable);

    if (u8Enable)
    {
        if (SDADC_HWA_GetBIAS_EN(pSdadc))
        {
            while (u32Counter--)
            {
                if (SDADC_HWA_GetBIAS_ON(pSdadc))
                {
                    break;
                }
            }
        }
        while (u32Counter--)
        {
            if (SDADC_HWA_GetCHRDY(pSdadc))
            {
                break;
            }
        }
    }
    else
    {
        while (u32Counter--)
        {
            if (SDADC_HWA_GetCHON(pSdadc) == 0)
            {
                break;
            }
        }
    }
    if (u32Counter == 0U)
    {
        eRet = SDADC_E_NOT_OK;
    }
    return eRet;
}

void SDADC_ChannelSWTrigger(SDADC_HandleType *pSdadcHandle, SDADC_ChannelMaskType u8ChannelMask)
{
#if SDADC_DEV_ERROR_REPORT == STD_ON
    if (SDADC_HandleCheck(pSdadcHandle, SDADC_CHANNELSWTRIGGER_ID))
    {
        return;
    }
#endif
    SDADC_Type *const pSdadc = s_apSdadcBase[pSdadcHandle->eInstance];
    u8ChannelMask            = u8ChannelMask & 0x7U;
    pSdadc->CTRL             = (pSdadc->CTRL & ~0x7U) | u8ChannelMask;
}

void SDADC_ClearChannelSWTrigger(SDADC_HandleType *pSdadcHandle, SDADC_ChannelMaskType u8ChannelMask)
{
#if SDADC_DEV_ERROR_REPORT == STD_ON
    if (SDADC_HandleCheck(pSdadcHandle, SDADC_CLEARCHANNELSWTRIGGER_ID))
    {
        return;
    }
#endif
    SDADC_Type *const pSdadc = s_apSdadcBase[pSdadcHandle->eInstance];
    u8ChannelMask            = u8ChannelMask & 0x7U;
    pSdadc->CTRL &= (uint32_t)(~u8ChannelMask);
}

void SDADC_IntegratorSWTrigger(SDADC_HandleType *pSdadcHandle, SDADC_ChannelMaskType u8ChannelMask)
{
#if SDADC_DEV_ERROR_REPORT == STD_ON
    if (SDADC_HandleCheck(pSdadcHandle, SDADC_INTEGRATORSWTRIGGER_ID))
    {
        return;
    }
#endif
    SDADC_Type *const pSdadc = s_apSdadcBase[pSdadcHandle->eInstance];
    u8ChannelMask            = u8ChannelMask & 0x7U;
    pSdadc->EXTCTRL          = (pSdadc->EXTCTRL & ~0x7U) | u8ChannelMask;
}

void SDADC_ClearIntegratorSWTrigger(SDADC_HandleType *pSdadcHandle, SDADC_ChannelMaskType u8ChannelMask)
{
#if SDADC_DEV_ERROR_REPORT == STD_ON
    if (SDADC_HandleCheck(pSdadcHandle, SDADC_INTEGRATORSWTRIGGER_ID))
    {
        return;
    }
#endif
    SDADC_Type *const pSdadc = s_apSdadcBase[pSdadcHandle->eInstance];
    u8ChannelMask            = u8ChannelMask & 0x7U;
    pSdadc->EXTCTRL &= (uint32_t)(~u8ChannelMask);
}

void SDADC_EnablePWMSignTriggerOut(SDADC_HandleType *pSdadcHandle, uint8_t u8Enable)
{
#if SDADC_DEV_ERROR_REPORT == STD_ON
    if (SDADC_HandleCheck(pSdadcHandle, SDADC_ENABLEPWMSIGNTRIGGEROUT_ID))
    {
        return;
    }
#endif
    SDADC_Type *const pSdadc = s_apSdadcBase[pSdadcHandle->eInstance];
    SDADC_HWA_SetTRGSIGN_OEN(pSdadc, u8Enable);
}

void SDADC_EnableTSignTriggerOut(SDADC_HandleType *pSdadcHandle, uint8_t u8ChannelIndex, uint8_t u8Enable)
{
#if SDADC_DEV_ERROR_REPORT == STD_ON
    if (SDADC_HandleChannelCheck(pSdadcHandle, u8ChannelIndex, SDADC_ENABLETSIGNTRIGGEROUT_ID))
    {
        return;
    }
#endif
    SDADC_Type *const pSdadc = s_apSdadcBase[pSdadcHandle->eInstance];
    SDADC_HWA_SetCTRGSIGN_OEN(pSdadc, u8ChannelIndex, u8Enable);
}

SDADC_RetStatusType SDADC_GetConversionResult(SDADC_HandleType *pSdadcHandle, uint8_t u8ChannelIndex, uint32_t *pData)
{
#if SDADC_DEV_ERROR_REPORT == STD_ON
    if (SDADC_HandleChannelCheck(pSdadcHandle, u8ChannelIndex, SDADC_GETCONVERSIONRESULT_ID))
    {
        return SDADC_E_NOT_OK;
    }
#endif
    SDADC_RetStatusType eRet   = SDADC_E_OK;
    SDADC_Type *const   pSdadc = s_apSdadcBase[pSdadcHandle->eInstance];

    *pData = SDADC_HWA_GetCRDATAn(pSdadc, u8ChannelIndex);
    return eRet;
}

SDADC_RetStatusType SDADC_GetCaptureTimeStamp(SDADC_HandleType *pSdadcHandle, uint8_t u8ChannelIndex, uint16_t *pTimestamp, uint16_t *pLastCov)
{
#if SDADC_DEV_ERROR_REPORT == STD_ON
    if (SDADC_HandleChannelCheck(pSdadcHandle, u8ChannelIndex, SDADC_GETCAPTURETIMESTAMP_ID))
    {
        return SDADC_E_NOT_OK;
    }
#endif
    SDADC_RetStatusType eRet   = SDADC_E_OK;
    SDADC_Type *const   pSdadc = s_apSdadcBase[pSdadcHandle->eInstance];

    if (pTimestamp)
    {
        *pTimestamp = (uint16_t)SDADC_HWA_GetTSTAMP(pSdadc, u8ChannelIndex);
    }
    if (pLastCov)
    {
        *pLastCov = (uint16_t)SDADC_HWA_GetTSDATA(pSdadc, u8ChannelIndex);
    }
    return eRet;
}

SDADC_RetStatusType SDADC_GetSignDelayCapture(SDADC_HandleType *pSdadcHandle, uint8_t u8ChannelIndex, uint8_t *pCapture)
{
#if SDADC_DEV_ERROR_REPORT == STD_ON
    if (SDADC_HandleChannelCheck(pSdadcHandle, u8ChannelIndex, SDADC_GETSIGNDELAYCAPTURE_ID))
    {
        return SDADC_E_NOT_OK;
    }
#endif
    SDADC_RetStatusType eRet   = SDADC_E_OK;
    SDADC_Type *const   pSdadc = s_apSdadcBase[pSdadcHandle->eInstance];
    *pCapture                  = (uint8_t)SDADC_HWA_GetSD_CAP(pSdadc, u8ChannelIndex);
    return eRet;
}

uint8_t SDADC_GetChannelReady(SDADC_HandleType *pSdadcHandle, uint8_t u8ChannelIndex)
{
#if SDADC_DEV_ERROR_REPORT == STD_ON
    if (SDADC_HandleChannelCheck(pSdadcHandle, u8ChannelIndex, SDADC_GETCHANNELREADY_ID))
    {
        return SDADC_E_NOT_OK;
    }
#endif
    uint8_t           u8Ret  = 0;
    SDADC_Type *const pSdadc = s_apSdadcBase[pSdadcHandle->eInstance];

    if ((pSdadc->MSR & ((1U << u8ChannelIndex) << SDADC_MSR_CHRDY_SHIFT)) != 0U)
    {
        u8Ret = 1U;
    }
    else
    {
        u8Ret = 0U;
    }

    return u8Ret;
}

uint8_t SDADC_GetChannelConverting(SDADC_HandleType *pSdadcHandle, uint8_t u8ChannelIndex)
{
#if SDADC_DEV_ERROR_REPORT == STD_ON
    if (SDADC_HandleChannelCheck(pSdadcHandle, u8ChannelIndex, SDADC_GETCHANNELCONVERTING_ID))
    {
        return SDADC_E_NOT_OK;
    }
#endif
    uint8_t           u8Ret  = 0;
    SDADC_Type *const pSdadc = s_apSdadcBase[pSdadcHandle->eInstance];

    if ((pSdadc->NISR & (SDADC_MSR_CHON0_MASK << u8ChannelIndex)) != 0U)
    {
        u8Ret = 1U;
    }
    else
    {
        u8Ret = 0U;
    }

    return u8Ret;
}

uint8_t SDADC_GetChannelConversionComplete(SDADC_HandleType *pSdadcHandle, uint8_t u8ChannelIndex)
{
#if SDADC_DEV_ERROR_REPORT == STD_ON
    if (SDADC_HandleChannelCheck(pSdadcHandle, u8ChannelIndex, SDADC_GETCHANNELCONVERSIONCOMPLETE_ID))
    {
        return SDADC_E_NOT_OK;
    }
#endif
    uint8_t           u8Ret  = 0;
    SDADC_Type *const pSdadc = s_apSdadcBase[pSdadcHandle->eInstance];

    if ((pSdadc->NISR & (SDADC_NISR_COC0_MASK << u8ChannelIndex)) != 0U)
    {
        u8Ret = 1U;
    }
    else
    {
        u8Ret = 0U;
    }

    return u8Ret;
}

uint8_t SDADC_GetChannelFIFOEmpty(SDADC_HandleType *pSdadcHandle, uint8_t u8ChannelIndex)
{
#if SDADC_DEV_ERROR_REPORT == STD_ON
    if (SDADC_HandleChannelCheck(pSdadcHandle, u8ChannelIndex, SDADC_GETCHANNELFIFOEMPTY_ID))
    {
        return SDADC_E_NOT_OK;
    }
#endif
    uint8_t           u8Ret  = 0;
    SDADC_Type *const pSdadc = s_apSdadcBase[pSdadcHandle->eInstance];

    if ((pSdadc->MSR & ((1U << u8ChannelIndex) << SDADC_MSR_FIFO_EMPTY_SHIFT)) != 0U)
    {
        u8Ret = 1U;
    }
    else
    {
        u8Ret = 0U;
    }

    return u8Ret;
}

uint8_t SDADC_GetChannelFIFOReady(SDADC_HandleType *pSdadcHandle, uint8_t u8ChannelIndex)
{
#if SDADC_DEV_ERROR_REPORT == STD_ON
    if (SDADC_HandleChannelCheck(pSdadcHandle, u8ChannelIndex, SDADC_GETCHANNELFIFOREADY_ID))
    {
        return SDADC_E_NOT_OK;
    }
#endif
    uint8_t           u8Ret  = 0;
    SDADC_Type *const pSdadc = s_apSdadcBase[pSdadcHandle->eInstance];

    if ((pSdadc->NISR & (SDADC_NISR_FRDY0_MASK << u8ChannelIndex)) != 0U)
    {
        u8Ret = 1U;
    }
    else
    {
        u8Ret = 0U;
    }

    return u8Ret;
}

void SDADC_ClearChannelFIFOReady(SDADC_HandleType *pSdadcHandle, uint8_t u8ChannelIndex)
{
#if SDADC_DEV_ERROR_REPORT == STD_ON
    if (SDADC_HandleChannelCheck(pSdadcHandle, u8ChannelIndex, SDADC_CLEARCHANNELFIFOREADY_ID))
    {
        return;
    }
#endif
    SDADC_Type *const pSdadc = s_apSdadcBase[pSdadcHandle->eInstance];
    pSdadc->NISR             = SDADC_NISR_FRDY0_MASK << u8ChannelIndex;
}

void SDADC_ClearChannelConversionComplete(SDADC_HandleType *pSdadcHandle, uint8_t u8ChannelIndex)
{
#if SDADC_DEV_ERROR_REPORT == STD_ON
    if (SDADC_HandleChannelCheck(pSdadcHandle, u8ChannelIndex, SDADC_CLEARCHANNELCONVERSIONCOMPLETE_ID))
    {
        return;
    }
#endif
    SDADC_Type *const pSdadc = s_apSdadcBase[pSdadcHandle->eInstance];
    pSdadc->NISR             = SDADC_NISR_COC0_MASK << u8ChannelIndex;
}

SDADC_RetStatusType SDADC_StartPwmGeneration(SDADC_HandleType *pSdadcHandle, SDADC_PWMPatternType ePattern)
{
#if SDADC_DEV_ERROR_REPORT == STD_ON
    if (SDADC_HandleCheck(pSdadcHandle, SDADC_STARTPWMGENERATION_ID))
    {
        return SDADC_E_NOT_OK;
    }
#endif
    SDADC_Type *const   pSdadc = s_apSdadcBase[pSdadcHandle->eInstance];
    SDADC_RetStatusType u8Ret;
    if (SDADC_HWA_GetON(pSdadc))
    {
        u8Ret = SDADC_E_NOT_OK;
    }
    else
    {
        SDADC_HWA_SetPATTERN(pSdadc, ePattern);
        u8Ret = SDADC_E_OK;
    }
    return u8Ret;
}

SDADC_RetStatusType SDADC_StopPwmGeneration(SDADC_HandleType *pSdadcHandle)
{
#if SDADC_DEV_ERROR_REPORT == STD_ON
    if (SDADC_HandleCheck(pSdadcHandle, SDADC_STOPPWMGENERATION_ID))
    {
        return SDADC_E_NOT_OK;
    }
#endif
    SDADC_Type *const   pSdadc = s_apSdadcBase[pSdadcHandle->eInstance];
    SDADC_RetStatusType u8Ret;
    if (SDADC_HWA_GetON(pSdadc))
    {
        SDADC_HWA_SetPATTERN(pSdadc, SDADC_PWM_PATTERN_STOPPED);
        u8Ret = SDADC_E_OK;
    }
    else
    {
        u8Ret = SDADC_E_NOT_OK;
    }
    return u8Ret;
}

void SDADC_SetInterrupptEnable(SDADC_HandleType *pSdadcHandle, uint8_t u8ChannelIndex, SDADC_InterruptType eIntType, uint8_t u8Enable)
{
#if SDADC_DEV_ERROR_REPORT == STD_ON
    if (SDADC_HandleChannelCheck(pSdadcHandle, u8ChannelIndex, SDADC_SETINTERRUPPTENABLE_ID))
    {
        return;
    }
#endif

    SDADC_Type *const pSdadc = s_apSdadcBase[pSdadcHandle->eInstance];

    switch (eIntType)
    {
        case SDADC_COCI_INTERRUPT:
            {
                if (u8ChannelIndex == 0)
                {
                    SDADC_HWA_ClearCOC0(pSdadc);
                    SDADC_HWA_SetCOCIE0(pSdadc, u8Enable);
                }
                else if (u8ChannelIndex == 1)
                {
                    SDADC_HWA_ClearCOC1(pSdadc);
                    SDADC_HWA_SetCOCIE1(pSdadc, u8Enable);
                }
                else
                {
                    SDADC_HWA_ClearCOC2(pSdadc);
                    SDADC_HWA_SetCOCIE2(pSdadc, u8Enable);
                }
            }
            break;

        case SDADC_FIFO_READY_INTERRUPT:
            {
                if (u8ChannelIndex == 0)
                {
                    SDADC_HWA_ClearFRDY0(pSdadc);
                    SDADC_HWA_SetFRDYIE0(pSdadc, u8Enable);
                }
                else if (u8ChannelIndex == 1)
                {
                    SDADC_HWA_ClearFRDY1(pSdadc);
                    SDADC_HWA_SetFRDYIE1(pSdadc, u8Enable);
                }
                else
                {
                    SDADC_HWA_ClearFRDY2(pSdadc);
                    SDADC_HWA_SetFRDYIE2(pSdadc, u8Enable);
                }
            }
            break;

        case SDADC_FIFO_OVERFLOW_INTERRUPT:
            {
                if (u8ChannelIndex == 0)
                {
                    SDADC_HWA_ClearFOVF0(pSdadc);
                    SDADC_HWA_SetFOVFIE0(pSdadc, u8Enable);
                }
                else if (u8ChannelIndex == 1)
                {
                    SDADC_HWA_ClearFOVF1(pSdadc);
                    SDADC_HWA_SetFOVFIE1(pSdadc, u8Enable);
                }
                else
                {
                    SDADC_HWA_ClearFOVF2(pSdadc);
                    SDADC_HWA_SetFOVFIE2(pSdadc, u8Enable);
                }
            }
            break;

        case SDADC_FIFO_UNDERFLOW_INTERRUPT:
            {
                if (u8ChannelIndex == 0)
                {
                    SDADC_HWA_ClearFUNF0(pSdadc);
                    SDADC_HWA_SetFUNFIE0(pSdadc, u8Enable);
                }
                else if (u8ChannelIndex == 1)
                {
                    SDADC_HWA_ClearFUNF1(pSdadc);
                    SDADC_HWA_SetFUNFIE1(pSdadc, u8Enable);
                }
                else
                {
                    SDADC_HWA_ClearFUNF2(pSdadc);
                    SDADC_HWA_SetFUNFIE2(pSdadc, u8Enable);
                }
            }
            break;

        case SDADC_ZERO_CROSS_DETECT_INTERRUPT:
            {
                if (u8ChannelIndex == 0)
                {
                    SDADC_HWA_ClearZCD0(pSdadc);
                    SDADC_HWA_SetZCDIE0(pSdadc, u8Enable);
                }
                else if (u8ChannelIndex == 1)
                {
                    SDADC_HWA_ClearZCD1(pSdadc);
                    SDADC_HWA_SetZCDIE1(pSdadc, u8Enable);
                }
                else
                {
                    SDADC_HWA_ClearZCD2(pSdadc);
                    SDADC_HWA_SetZCDIE2(pSdadc, u8Enable);
                }
            }
            break;

        case SDADC_HIGH_LIMIT_REACH_INTERRUPT:
            {
                if (u8ChannelIndex == 0)
                {
                    SDADC_HWA_ClearHLMT0(pSdadc);
                    SDADC_HWA_SetHLMTIE0(pSdadc, u8Enable);
                }
                else if (u8ChannelIndex == 1)
                {
                    SDADC_HWA_ClearHLMT1(pSdadc);
                    SDADC_HWA_SetHLMTIE1(pSdadc, u8Enable);
                }
                else
                {
                    SDADC_HWA_ClearHLMT2(pSdadc);
                    SDADC_HWA_SetHLMTIE2(pSdadc, u8Enable);
                }
            }
            break;

        case SDADC_LOW_LIMIT_REACH_INTERRUPT:
            {
                if (u8ChannelIndex == 0)
                {
                    SDADC_HWA_ClearLLMT0(pSdadc);
                    SDADC_HWA_SetLLMTIE0(pSdadc, u8Enable);
                }
                else if (u8ChannelIndex == 1)
                {
                    SDADC_HWA_ClearLLMT1(pSdadc);
                    SDADC_HWA_SetLLMTIE1(pSdadc, u8Enable);
                }
                else
                {
                    SDADC_HWA_ClearLLMT2(pSdadc);
                    SDADC_HWA_SetLLMTIE2(pSdadc, u8Enable);
                }
            }
            break;

        case SDADC_WINDOW_LIMIT_REACH_INTERRUPT:
            {
                if (u8ChannelIndex == 0)
                {
                    SDADC_HWA_ClearWLMT0(pSdadc);
                    SDADC_HWA_SetWLMTIE0(pSdadc, u8Enable);
                }
                else if (u8ChannelIndex == 1)
                {
                    SDADC_HWA_ClearWLMT1(pSdadc);
                    SDADC_HWA_SetWLMTIE1(pSdadc, u8Enable);
                }
                else
                {
                    SDADC_HWA_ClearWLMT2(pSdadc);
                    SDADC_HWA_SetWLMTIE2(pSdadc, u8Enable);
                }
            }
            break;

        case SDADC_SHORT_CIRCUIT_DETECT_INTERRUPT:
            {
                if (u8ChannelIndex == 0)
                {
                    SDADC_HWA_ClearSCD0(pSdadc);
                    SDADC_HWA_SetSCDIE0(pSdadc, u8Enable);
                }
                else if (u8ChannelIndex == 1)
                {
                    SDADC_HWA_ClearSCD1(pSdadc);
                    SDADC_HWA_SetSCDIE1(pSdadc, u8Enable);
                }
                else
                {
                    SDADC_HWA_ClearSCD2(pSdadc);
                    SDADC_HWA_SetSCDIE2(pSdadc, u8Enable);
                }
            }
            break;

        case SDADC_DATA_SATURATION_DETECT_INTERRUPT:
            {
                if (u8ChannelIndex == 0)
                {
                    SDADC_HWA_ClearSAT0(pSdadc);
                    SDADC_HWA_SetSATIE0(pSdadc, u8Enable);
                }
                else if (u8ChannelIndex == 1)
                {
                    SDADC_HWA_ClearSAT1(pSdadc);
                    SDADC_HWA_SetSATIE1(pSdadc, u8Enable);
                }
                else
                {
                    SDADC_HWA_ClearSAT2(pSdadc);
                    SDADC_HWA_SetSATIE2(pSdadc, u8Enable);
                }
            }
            break;

        case SDADC_CLOCK_ABSENCE_DETECT_INTERRUPT:
            {
                if (u8ChannelIndex == 0)
                {
                    SDADC_HWA_ClearCAD0(pSdadc);
                    SDADC_HWA_SetCADIE0(pSdadc, u8Enable);
                }
                else if (u8ChannelIndex == 1)
                {
                    SDADC_HWA_ClearCAD1(pSdadc);
                    SDADC_HWA_SetCADIE1(pSdadc, u8Enable);
                }
                else
                {
                    SDADC_HWA_ClearCAD2(pSdadc);
                    SDADC_HWA_SetCADIE2(pSdadc, u8Enable);
                }
            }
            break;

        case SDADC_SIGN_DELAY_CAPTURE_INTERRUPT:
            {
                if (u8ChannelIndex == 0)
                {
                    SDADC_HWA_ClearSD_CAPVLD0(pSdadc);
                    SDADC_HWA_SetSD_CAPVLD_IE0(pSdadc, u8Enable);
                }
                else if (u8ChannelIndex == 1)
                {
                    SDADC_HWA_ClearSD_CAPVLD1(pSdadc);
                    SDADC_HWA_SetSD_CAPVLD_IE1(pSdadc, u8Enable);
                }
                else
                {
                    SDADC_HWA_ClearSD_CAPVLD2(pSdadc);
                    SDADC_HWA_SetSD_CAPVLD_IE2(pSdadc, u8Enable);
                }
            }
            break;

        case SDADC_TSIGN_CHANGED_INTERRUPT:
            {
                if (u8ChannelIndex == 0)
                {
                    SDADC_HWA_ClearTSIGN_P2N0(pSdadc);
                    SDADC_HWA_SetTSIGN_P2N_IE0(pSdadc, u8Enable);
                }
                else if (u8ChannelIndex == 1)
                {
                    SDADC_HWA_ClearTSIGN_P2N1(pSdadc);
                    SDADC_HWA_SetTSIGN_P2N_IE1(pSdadc, u8Enable);
                }
                else
                {
                    SDADC_HWA_ClearTSIGN_P2N2(pSdadc);
                    SDADC_HWA_SetTSIGN_P2N_IE2(pSdadc, u8Enable);
                }
            }
            break;

        case SDADC_TS_VALID_INTERRUPT:
            {
                if (u8ChannelIndex == 0)
                {
                    SDADC_HWA_ClearTSVLD0(pSdadc);
                    SDADC_HWA_SetTSVLD_IE0(pSdadc, u8Enable);
                }
                else if (u8ChannelIndex == 1)
                {
                    SDADC_HWA_ClearTSVLD1(pSdadc);
                    SDADC_HWA_SetTSVLD_IE1(pSdadc, u8Enable);
                }
                else
                {
                    SDADC_HWA_ClearTSVLD2(pSdadc);
                    SDADC_HWA_SetTSVLD_IE2(pSdadc, u8Enable);
                }
            }
            break;

        default:
            break;
    }
}

#endif /* #if SDADC_INSTANCE_COUNT > 0U */
