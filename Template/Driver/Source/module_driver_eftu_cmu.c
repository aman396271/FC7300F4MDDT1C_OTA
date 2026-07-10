#include "module_driver_eftu_cmu.h"

#if defined(EFTU_INSTANCE_COUNT) && (EFTU_INSTANCE_COUNT > 0)
static  EFTU_CMU_Type *const s_pEftuCmuBasePtrs[EFTU_CMU_INSTANCE_COUNT] =
{
    (EFTU_CMU_Type *)(EFTU0_BASE + EFTU_CMU_BASE),
};

#ifndef CMU_DEV_ERROR_REPORT
    #define CMU_DEV_ERROR_REPORT    STD_OFF
#endif

#if CMU_DEV_ERROR_REPORT == STD_ON
    #define CMU_ReportDevError(func, error) ReportDevError(EFTU_CMU_MODULE_ID, func, error)
#endif


/**
 * @brief Cmu Global clock configuration.
 * @param pCmuHandle EFTU CMU processing handle
 */
void EFTU_CMU_Init(EFTU_CMU_HandleType *pCmuHandle)
{
    #if CMU_DEV_ERROR_REPORT == STD_ON
    if (((uint32_t)pCmuHandle->freqBusClock  == 0U) || ((uint32_t)pCmuHandle->freqGlobalClock  == 0U))
    {
        CMU_ReportDevError(EFTU_CMU_INIT_ID, EFTU_CMU_E_PARAM_COUNT);
    }
    else
    #endif
    {
        /*
         * freqGlobalClock = DEN/NUM *freqBusClock;
         * */
        EFTU_CMU_Type *pCmu = s_pEftuCmuBasePtrs[0];
        float fTempFreq;
        float freqBusClock =  pCmuHandle->fBusClock;
        float freqGlobalClock = pCmuHandle->fGlobalClock;
        float fDistance =  pCmuHandle->fGlobalClock;;
        uint8_t  u8Num, u8Den, u8DenBest = 1, u8NumBest = 1;
        float fTempBusDivider;
        for (u8Num = 1; u8Num < 0xFF; u8Num++)
        {
            boolean endLoop = FALSE;
            fTempBusDivider = freqBusClock / u8Num;
            for (u8Den = u8Num; u8Den > 0; u8Den--)
            {
                float dis;
                fTempFreq   = fTempBusDivider * u8Den;
                dis = (float)fabsf(freqGlobalClock - fTempFreq);

                if (dis < fDistance)
                {
                    fDistance = dis;
                    u8DenBest        = u8Den;
                    u8NumBest        = u8Num;
                }
                if (fDistance < 0.1f)
                {
                    endLoop = TRUE;
                    break;
                }
            }
            if (endLoop)
            {
                break;
            }
        }
        EFTU_CMU_HWA_SetGclkNum(pCmu, u8NumBest);
        EFTU_CMU_HWA_SetGclkDen(pCmu, u8DenBest);
        pCmuHandle->tStatus.pCmu = pCmu;
    }
}

/**
 * @brief Cmu external clock configuration.
 * @param pCmuHandle EFTU CMU processing handle
 * @param eEclk      Cmu external clock Index
 * @param fFrequence Cmu external clock frequency
 */
void EFTU_CMU_SetEClock(EFTU_CMU_HandleType *pCmuHandle, EFTU_CMU_ClkSrcType eEclk, float fFrequence)
{
    #if CMU_DEV_ERROR_REPORT == STD_ON
    if (((uint32_t)pCmuHandle->freqBusClock  == 0U) || ((uint32_t)pCmuHandle->freqGlobalClock  == 0U) || ((uint32_t)fFrequence == 0U))
    {
        CMU_ReportDevError(EFTU_CMU_SET_ECLK_ID, EFTU_CMU_E_PARAM_COUNT);
    }
    else if (pCmuHandle->tStatus.pCmu == NULL)
    {
        CMU_ReportDevError(EFTU_CMU_SET_ECLK_ID, EFTU_CMU_UNINIT);
    }
    else if ((eEclk != EFTU_ECLK_0) && (eEclk != EFTU_ECLK_1))
    {
        CMU_ReportDevError(EFTU_CMU_SET_ECLK_ID, EFTU_CMU_E_PARAM_CHANNEL);
    }
    else
    #endif
    {
        /*
         * freqEClock = DEN/NUM *freqGlobalClock;
         * */
        EFTU_CMU_Type *pCmu = s_pEftuCmuBasePtrs[0];
        float fTempfreq;
        float freqInClock =  pCmuHandle->fBusClock;
        float bDis =  fFrequence;
        uint8_t  u8Num, u8Den, u8DenBest = 1, u8NumBest = 1;
        float fTempGlobalDivider;
        for (u8Num = 1; u8Num < 0xFF; u8Num++)
        {
            boolean endLoop = FALSE;
            fTempGlobalDivider = freqInClock / u8Num;
            for (u8Den = u8Num; u8Den > 0; u8Den--)
            {
                float dis;
                fTempfreq = fTempGlobalDivider * u8Den;
                dis = (float)fabsf(fFrequence - fTempfreq);
                if (dis < bDis)
                {
                    bDis = dis;
                    u8DenBest        = u8Den;
                    u8NumBest        = u8Num;
                }
                if (bDis < 0.1f)
                {
                    endLoop = TRUE;
                    break;
                }
            }
            if (endLoop)
            {
                break;
            }
        }
        if (EFTU_ECLK_0 == eEclk)
        {
            EFTU_CMU_HWA_SetEclk0Num(pCmu, u8NumBest);
            EFTU_CMU_HWA_SetEclk0Den(pCmu, u8DenBest);
        }
        else /*EFTU_ECLK_1*/
        {
            EFTU_CMU_HWA_SetEclk1Num(pCmu, u8NumBest);
            EFTU_CMU_HWA_SetEclk1Den(pCmu, u8DenBest);
        }
        pCmuHandle->tStatus.afExternalClock[eEclk-EFTU_ECLK_0] = fFrequence;
    }
}

/**
 * @brief Cmu  clock configuration.
 * @param pCmuHandle EFTU CMU processing handle
 * @param eClk      Cmu clock Index
 * @param eClockSource Cmu clock source
 * @param fFrequence Cmu  clock frequency
 */
void EFTU_CMU_SetCmuClock(EFTU_CMU_HandleType *pCmuHandle, EFTU_CMU_ClkSrcType eClk, EFTU_CMU_ClkCtrlSrcType eClockSource, float fFrequence)
{
    #if CMU_DEV_ERROR_REPORT == STD_ON
    if (((uint32_t)pCmuHandle->freqBusClock  == 0U) || ((uint32_t)pCmuHandle->freqGlobalClock  == 0U) || ((uint32_t)fFrequence == 0U))
    {
        CMU_ReportDevError(EFTU_CMU_SET_CMUCLK_ID, EFTU_CMU_E_PARAM_COUNT);
    }
    else if (pCmuHandle->tStatus.pCmu == NULL)
    {
        CMU_ReportDevError(EFTU_CMU_SET_CMUCLK_ID, EFTU_CMU_UNINIT);
    }
    else if (eEclk > EFTU_CMU_CLK_7)
    {
        CMU_ReportDevError(EFTU_CMU_SET_CMUCLK_ID, EFTU_CMU_E_PARAM_CHANNEL);
    }
    else
    #endif
    {
        float ftempDivider;
        if (eClockSource == CMU_GCLK_EN)
        {
            ftempDivider = pCmuHandle->fGlobalClock / fFrequence - 1 ;
        }
        else /*CMU_ECLK1_EN*/
        {
            ftempDivider = pCmuHandle->tStatus.afExternalClock[1] / fFrequence - 1 ;
        }
        uint32  cnt = (uint32)ftempDivider;
        if ((ftempDivider - (float)cnt) > 0.5f)
        {
            /* Round to nearest */
            cnt++;
        }
        EFTU_CMU_HWA_SetCmuclkCnt(pCmuHandle->tStatus.pCmu, cnt, eClk);

        if (eClockSource == CMU_GCLK_EN)
        {

        	for(uint8 u8Instance = 0u ; u8Instance< EFTU_INSTANCE_COUNT ;u8Instance++)
        	{
        		pCmuHandle->tStatus.fCmuClock[u8Instance][eClk] = pCmuHandle->fGlobalClock /(((float)cnt+1));
        	}
        }
        else/*CMU_ECLK1_EN*/
        {
        	for(uint8 u8Instance = 0u ; u8Instance< EFTU_INSTANCE_COUNT ;u8Instance++)
        	{
        		pCmuHandle->tStatus.fCmuClock[u8Instance][eClk] = pCmuHandle->tStatus.afExternalClock[1]/(((float)cnt+1));
        	}
        }
        EFTU_CMU_HWA_SetCmuClkSrc(pCmuHandle->tStatus.pCmu,eClk,eClockSource);
    }
}

/**
 * @brief Cmu clock 8 configuration.
 * @param pCmuHandle EFTU CMU processing handle
 * @param eCmu8ClockSrc      Cmu clock 8 source
 */
void EFTU_CMU_SetCmuClk8Src(EFTU_CMU_HandleType *pCmuHandle, EFTU_CMU_Clk8CtrlSrcType eCmu8ClockSrc)
{
    #if CMU_DEV_ERROR_REPORT == STD_ON
    if (pCmuHandle->tStatus.pCmu == NULL)
    {
        CMU_ReportDevError(EFTU_CMU_SET_CLK8_ID, EFTU_CMU_UNINIT);
    }
    else
    #endif
    {
        if (eCmu8ClockSrc == CLUSTER_RES_CONST_1)
        {
            pCmuHandle->tStatus.fClock8 = pCmuHandle->fBusClock;
        }
        else
        {
            pCmuHandle->tStatus.fClock8 = pCmuHandle->tStatus.afExternalClock[0];
        }
        EFTU_CMU_HWA_SetCmuClk8Src(pCmuHandle->tStatus.pCmu, eCmu8ClockSrc);
    }
}

/**
 * @brief Enable Cmu clock
 * @param pCmuHandle EFTU CMU processing handle
 * @param eChannel Clock Index
 */
void EFTU_CMU_EnableClock(EFTU_CMU_HandleType *pCmuHandle, EFTU_CMU_ClkSrcType eChannel)
{
    #if CMU_DEV_ERROR_REPORT == STD_ON
    if (pCmuHandle->tStatus.pCmu == NULL)
    {
        CMU_ReportDevError(EFTU_CMU_ENABLE_CLK_ID, EFTU_CMU_UNINIT);
    }
    else
    #endif
    {
        EFTU_CMU_HWA_EnableClock(pCmuHandle->tStatus.pCmu, eChannel);
    }
}

/**
 * @brief Disable Cmu clock
 * @param pCmuHandle EFTU CMU processing handle
 * @param eChannel  Clock Index
 */
void EFTU_CMU_DisableClock(EFTU_CMU_HandleType *pCmuHandle, EFTU_CMU_ClkSrcType eChannel)
{
    #if CMU_DEV_ERROR_REPORT == STD_ON
    if (pCmuHandle->tStatus.pCmu == NULL)
    {
        CMU_ReportDevError(EFTU_CMU_ENABLE_CLK_ID, EFTU_CMU_UNINIT);
    }
    else
    #endif
    {
        EFTU_CMU_HWA_DisableClock(pCmuHandle->tStatus.pCmu, eChannel);
    }
}
#endif /* defined(EFTU_INSTANCE_COUNT) && (EFTU_INSTANCE_COUNT > 0) */
