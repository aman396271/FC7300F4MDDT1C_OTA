/**
 * @file module_driver_cmp.c
 * @author Flagchip
 * @brief CMP driver source code
 * @version 2.0.0
 * @date 2024-08-20
 *
 * SDK Version: 2.6.0
 *

 * @copyright Copyright (c) 2020-2024 Flagchip Semiconductors Co., Ltd.
 *
 */
/********************************************************************************
*   Revision History:
*
*   Version     Date          Initials       CR#          Descriptions
*   ---------   ----------    ------------   ----------   ------------------------
*   0.1.0       2023-12-15    Flagchip055     N/A          First version for FC7300
*   0.2.0       2023-02-14    Flagchip052     N/A          Add callback function
**********************************************************************************/

#include "module_driver_cmp.h"

#if CMP_INSTANCE_COUNT > 0U

#ifndef CMP_DEV_ERROR_REPORT
    #define CMP_DEV_ERROR_REPORT    STD_OFF
#endif

#if CMP_DEV_ERROR_REPORT == STD_ON
    #define CMP_ReportDevError(func, error) ReportDevError(CMP_MODULE_ID, func, error)
#endif

/********* Local Typedef ************/

/********* Local Variables ************/

static CMP_Type *const s_apCmpBase[CMP_INSTANCE_COUNT] = CMP_BASE_PTRS;

/********* Local Functions ************/

static void CMP_InitInterrupt(CMP_HandleType *pCmpHandle, const CMP_InterruptType *const pInterruptCfg)
{
    CMP_Type *const pCmp = s_apCmpBase[pCmpHandle->eInstance];

    /* clear interrupter flag */
    CMP_HWA_ClearIntFlag_Rising(pCmp);
    CMP_HWA_ClearIntFlag_Falling(pCmp);
    #ifdef  CMP_SUPPORT_CHANNELSCAN_MODE_FEATURE
    CMP_HWA_ClearIntFlag_ChannelScan(pCmp);
    #endif

    /* set rising interrupt */
    CMP_HWA_SetIntEn_Rising(pCmp, pInterruptCfg->bRisingIntEn);
    pCmpHandle->tSettings.bRisingIntEn = pInterruptCfg->bRisingIntEn;

    /* set falling interrupt */
    CMP_HWA_SetIntEn_Falling(pCmp, pInterruptCfg->bFallingIntEn);
    pCmpHandle->tSettings.bFallingIntEn = pInterruptCfg->bFallingIntEn;

    #ifdef  CMP_SUPPORT_CHANNELSCAN_MODE_FEATURE
    /* set channel scan flag interrupt */
    CMP_HWA_SetIntEn_ChannelScan(pCmp, pInterruptCfg->bChannelScanIntEn);
    pCmpHandle->tSettings.bChannelScanIntEn = pInterruptCfg->bChannelScanIntEn;
    #endif

    pCmpHandle->tSettings.pRisingNotify      = pInterruptCfg->pRisingNotify;
    pCmpHandle->tSettings.pFallingNotify     = pInterruptCfg->pFallingNotify;
    #ifdef  CMP_SUPPORT_CHANNELSCAN_MODE_FEATURE
    pCmpHandle->tSettings.pChannelScanNotify = pInterruptCfg->pChannelScanNotify;
    #endif
}

/********* Public Functions ************/

void CMP_GetDefaultInitCfg(CMP_InitType *const pInitCfg)
{
    #if CMP_DEV_ERROR_REPORT == STD_ON
    if (NULL_PTR == pInitCfg)
    {
        CMP_ReportDevError(CMP_GETDEFAULTINITCFG_ID, CMP_E_PARAM_POINTER);
    }
    else
    {
    #endif

        pInitCfg->tDacConfig.bDacEn     = false;
        pInitCfg->tDacConfig.u8DacData  = 0;
        pInitCfg->tDacConfig.eDacEnsrc  = CMP_DACENABLE_DCR;

        pInitCfg->tMuxConfig.eINPSel    = CMP_INSRCSEL_DAC;
        pInitCfg->tMuxConfig.eINNSel    = CMP_INSRCSEL_DAC;
        pInitCfg->tMuxConfig.ePSelMux   = CMP_INSEL_MUX_IN0;
        pInitCfg->tMuxConfig.eNSelMux   = CMP_INSEL_MUX_IN0;
        #ifdef CMP_SUPPORT_CHANNELSCAN_MODE_FEATURE
        pInitCfg->tMuxConfig.eCSFIXCMux = CMP_INSEL_MUX_IN0;
        pInitCfg->tMuxConfig.eCSFIXPSel = CMP_PORTSEL_MUX_P;
        #endif

        pInitCfg->tComparatorConfig.bLPModeEn          = false;
        pInitCfg->tComparatorConfig.bDmaEn             = false;
        pInitCfg->tComparatorConfig.bOutToPackagePinEn = false;
        pInitCfg->tComparatorConfig.bWinSampleInvertEn = false;
        pInitCfg->tComparatorConfig.bEventCloseWinEn   = false;
        pInitCfg->tComparatorConfig.u8FilterPeriod     = 0U;
        pInitCfg->tComparatorConfig.u32InitDelay       = 15000U;
        pInitCfg->tComparatorConfig.eModeSel           = CMP_MODE_DISABLE;
        pInitCfg->tComparatorConfig.eInvert            = CMP_NON_INVERT;
        pInitCfg->tComparatorConfig.eOutSelect         = CMP_FILTEROUT;
        pInitCfg->tComparatorConfig.eOutWinLevel       = CMP_HOLD;
        pInitCfg->tComparatorConfig.eOutWin            = CMP_OUTWIN_0;
        pInitCfg->tComparatorConfig.eEventSelect       = CMP_RISINGEDGE;
        pInitCfg->tComparatorConfig.eFilterCnt         = CMP_FILTERCNT_0;
        pInitCfg->tComparatorConfig.eSpeedMode         = CMP_LOWSPEEDMODE;
        pInitCfg->tComparatorConfig.eHystCrtl          = CMP_HYSTCTRL_0;

        #ifdef CMP_SUPPORT_CHANNELSCAN_MODE_FEATURE
        pInitCfg->tChannelScanConfig.u8CSInitModulus    = 0;
        pInitCfg->tChannelScanConfig.u8CSNSAM           = 0;
        pInitCfg->tChannelScanConfig.bCSCompareResultAC = false;
        #endif

        #ifdef CMP_SUPPORT_CHANNELSCAN_MODE_FEATURE
        pInitCfg->tInterruptConfig.bChannelScanIntEn     = false;
        #endif
        pInitCfg->tInterruptConfig.bFallingIntEn         = false;
        pInitCfg->tInterruptConfig.bRisingIntEn          = false;
        pInitCfg->tInterruptConfig.pRisingNotify         = NULL;
        pInitCfg->tInterruptConfig.pFallingNotify        = NULL;
        #ifdef CMP_SUPPORT_CHANNELSCAN_MODE_FEATURE
        pInitCfg->tInterruptConfig.pChannelScanNotify    = NULL;
        #endif

    #if CMP_DEV_ERROR_REPORT == STD_ON
    }
    #endif
}

void CMP_Enable(CMP_HandleType *pCmpHandle)
{
    #if CMP_DEV_ERROR_REPORT == STD_ON
    if (NULL_PTR == pCmpHandle)
    {
        CMP_ReportDevError(CMP_ENABLE_ID, CMP_E_PARAM_POINTER);
    }
    else if ((uint32_t)pCmpHandle->eInstance >= CMP_INSTANCE_COUNT)
    {
        CMP_ReportDevError(CMP_ENABLE_ID, CMP_E_PARAM_INSTANCE);
    }
    else
    {
    #endif

        uint32_t i;
        uint32_t timeout;

        CMP_Type *const pCmp = s_apCmpBase[pCmpHandle->eInstance];

        CMP_HWA_SetEn(pCmp, true);

        timeout = pCmpHandle->tSettings.u32InitDelay;
        for(i = 0; i < timeout; i++)
            __asm("nop");

        /* Cmp output pin must be enabled after cmp enabled 30us */
        CMP_HWA_SetEnCmpOutPack(pCmp, pCmpHandle->tSettings.bOutToPackagePinEn);

    #if CMP_DEV_ERROR_REPORT == STD_ON
    }
    #endif
}

void CMP_Disable(CMP_HandleType *pCmpHandle)
{
    #if CMP_DEV_ERROR_REPORT == STD_ON
    if (NULL_PTR == pCmpHandle)
    {
        CMP_ReportDevError(CMP_DISABLE_ID, CMP_E_PARAM_POINTER);
    }
    else if ((uint32_t)pCmpHandle->eInstance >= CMP_INSTANCE_COUNT)
    {
        CMP_ReportDevError(CMP_DISABLE_ID, CMP_E_PARAM_INSTANCE);
    }
    else
    {
    #endif

        CMP_Type *const pCmp = s_apCmpBase[pCmpHandle->eInstance];

        CMP_HWA_SetEnCmpOutPack(pCmp, false);
        CMP_HWA_SetEn(pCmp, false);

    #if CMP_DEV_ERROR_REPORT == STD_ON
    }
    #endif
}

uint32_t CMP_GetCmpOut(CMP_HandleType *pCmpHandle)
{
    #if CMP_DEV_ERROR_REPORT == STD_ON
    if (NULL_PTR == pCmpHandle)
    {
        CMP_ReportDevError(CMP_GETCMPOUT_ID, CMP_E_PARAM_POINTER);
    }
    else if ((uint32_t)pCmpHandle->eInstance >= CMP_INSTANCE_COUNT)
    {
        CMP_ReportDevError(CMP_GETCMPOUT_ID, CMP_E_PARAM_INSTANCE);
    }
    else
    {
    #endif

        CMP_Type *const pCmp = s_apCmpBase[pCmpHandle->eInstance];

        return CMP_HWA_GetCmpOut(pCmp);

    #if CMP_DEV_ERROR_REPORT == STD_ON
    }
    #endif
}

void CMP_SetDacData(CMP_HandleType *pCmpHandle, const uint8_t u8Data)
{
    #if CMP_DEV_ERROR_REPORT == STD_ON
    if (NULL_PTR == pCmpHandle)
    {
        CMP_ReportDevError(CMP_SETDACDATA_ID, CMP_E_PARAM_POINTER);
    }
    else if ((uint32_t)pCmpHandle->eInstance >= CMP_INSTANCE_COUNT)
    {
        CMP_ReportDevError(CMP_SETDACDATA_ID, CMP_E_PARAM_INSTANCE);
    }
    else
    {
    #endif

        CMP_Type *const pCmp = s_apCmpBase[pCmpHandle->eInstance];

        CMP_HWA_SetDacData(pCmp, u8Data);

    #if CMP_DEV_ERROR_REPORT == STD_ON
    }
    #endif
}

CMP_OutStatus CMP_GetOutFlagStatus(CMP_HandleType *pCmpHandle)
{
    #if CMP_DEV_ERROR_REPORT == STD_ON
    if (NULL_PTR == pCmpHandle)
    {
        CMP_ReportDevError(CMP_GETOUTFLAGSTATUS_ID, CMP_E_PARAM_POINTER);
    }
    else if ((uint32_t)pCmpHandle->eInstance >= CMP_INSTANCE_COUNT)
    {
        CMP_ReportDevError(CMP_GETOUTFLAGSTATUS_ID, CMP_E_PARAM_INSTANCE);
    }
    else
    {
    #endif

        bool bCFF_Status = false;
        bool bCFR_Status = false;
        CMP_Type *const pCmp = s_apCmpBase[pCmpHandle->eInstance];
        CMP_OutStatus eRetVal = CMP_OUT_NONE;

        bCFF_Status = CMP_HWA_GetIntFlag_Falling(pCmp);
        bCFR_Status = CMP_HWA_GetIntFlag_Rising(pCmp);

        if ((bCFF_Status == true) && (bCFR_Status == false))
        {
            eRetVal = CMP_OUT_FALLING_EDGE;
        }
        else if ((bCFF_Status == false) && (bCFR_Status == true))
        {
            eRetVal = CMP_OUT_RISING_EDGE;
        }
        else
        {
            eRetVal = CMP_OUT_NONE;
        }

        return eRetVal;

    #if CMP_DEV_ERROR_REPORT == STD_ON
    }
    #endif
}

void CMP_Init(CMP_HandleType *pCmpHandle, const CMP_InitType *const pInitCfg)
{
    #if CMP_DEV_ERROR_REPORT == STD_ON
    if (NULL_PTR == pCmpHandle || NULL_PTR == pInitCfg)
    {
        CMP_ReportDevError(CMP_INIT_ID, CMP_E_PARAM_POINTER);
    }
    else if ((uint32_t)pCmpHandle->eInstance >= CMP_INSTANCE_COUNT)
    {
        CMP_ReportDevError(CMP_INIT_ID, CMP_E_PARAM_INSTANCE);
    }
    else
    {
    #endif

        CMP_Type *const pCmp = s_apCmpBase[pCmpHandle->eInstance];

        /* disable CMP module */
        CMP_HWA_SetEn(pCmp, false);

        /* determine comparator function mode */
        CMP_HWA_SetComparatorMode(pCmp, (pInitCfg->tComparatorConfig).eModeSel, ((pInitCfg->tComparatorConfig).u8FilterPeriod), ((pInitCfg->tComparatorConfig).eFilterCnt));

        /* CCR0 register */
        CMP_HWA_SetEnLPMode(pCmp, (pInitCfg->tComparatorConfig).bLPModeEn);
        pCmpHandle->tSettings.bLPModeEn = (pInitCfg->tComparatorConfig).bLPModeEn;
        CMP_HWA_SetDacEnableSrc(pCmp, (pInitCfg->tDacConfig).eDacEnsrc);

        /* CCR1 register */
        CMP_HWA_SetCmpOutInvert(pCmp, (pInitCfg->tComparatorConfig).eInvert);
        CMP_HWA_SetCmpOutSel(pCmp, (pInitCfg->tComparatorConfig).eOutSelect);
        /* Enabling out to package pin must be after enabling the whole CMP module */
        pCmpHandle->tSettings.bOutToPackagePinEn = (pInitCfg->tComparatorConfig).bOutToPackagePinEn;
        /* Set initialization delay */
        pCmpHandle->tSettings.u32InitDelay = (pInitCfg->tComparatorConfig).u32InitDelay;
        CMP_HWA_SetCmpOutWinLevel(pCmp, (pInitCfg->tComparatorConfig).eOutWinLevel);
        CMP_HWA_SetCmpOutWin(pCmp, (pInitCfg->tComparatorConfig).eOutWin);
        CMP_HWA_SetEnWinSampleInvert(pCmp, (pInitCfg->tComparatorConfig).bWinSampleInvertEn);
        CMP_HWA_SetEnEventCloseWin(pCmp, (pInitCfg->tComparatorConfig).bEventCloseWinEn);
        CMP_HWA_SetEventCloseWin(pCmp, (pInitCfg->tComparatorConfig).eEventSelect);
        CMP_HWA_SetDma(pCmp, (pInitCfg->tComparatorConfig).bDmaEn);

        /* CCR2 register */
        CMP_HWA_SetSpeedMode(pCmp, (pInitCfg->tComparatorConfig).eSpeedMode);
        CMP_HWA_SetHystCtrl(pCmp, (pInitCfg->tComparatorConfig).eHystCrtl);
        CMP_HWA_SetPSelMux(pCmp, (pInitCfg->tMuxConfig).ePSelMux);
        CMP_HWA_SetNSelMux(pCmp, (pInitCfg->tMuxConfig).eNSelMux);
        CMP_HWA_SetINPSel(pCmp, (pInitCfg->tMuxConfig).eINPSel);
        CMP_HWA_SetINNSel(pCmp, (pInitCfg->tMuxConfig).eINNSel);

        /* DCR register */
        CMP_HWA_SetEnDac(pCmp, (pInitCfg->tDacConfig).bDacEn);
        CMP_HWA_SetDacData(pCmp, (pInitCfg->tDacConfig).u8DacData);

        #ifdef CMP_SUPPORT_CHANNELSCAN_MODE_FEATURE

        if ((pInitCfg->tComparatorConfig).eModeSel == CMP_MODE_CHANNEL_SCAN)
        {
            /* CSCR0 register */
            CMP_HWA_SetCSInitModulus(pCmp, (pInitCfg->tChannelScanConfig).u8CSInitModulus);
            CMP_HWA_SetCSNSAM(pCmp, (pInitCfg->tChannelScanConfig).u8CSNSAM);

            /* CSCR1 register */
            CMP_HWA_SetCSFixedChannel(pCmp, (pInitCfg->tMuxConfig).eCSFIXCMux);
            CMP_HWA_SetCSFixedPort(pCmp, (pInitCfg->tMuxConfig).eCSFIXPSel);

            /* CSCSR register */
            CMP_HWA_SetCSCompareResultACEn(pCmp, (pInitCfg->tChannelScanConfig).bCSCompareResultAC);

            /* Enable Channel Scan Mode */
            CMP_HWA_SetCSEn(pCmp, true);
        }

        #endif

        CMP_InitInterrupt(pCmpHandle, &(pInitCfg->tInterruptConfig));

    #if CMP_DEV_ERROR_REPORT == STD_ON
    }
    #endif
}

void CMP_Deinit(CMP_HandleType *pCmpHandle)
{
    #if CMP_DEV_ERROR_REPORT == STD_ON
    if (NULL_PTR == pCmpHandle)
    {
        CMP_ReportDevError(CMP_DEINIT_ID, CMP_E_PARAM_POINTER);
    }
    else if ((uint32_t)pCmpHandle->eInstance >= CMP_INSTANCE_COUNT)
    {
        CMP_ReportDevError(CMP_DEINIT_ID, CMP_E_PARAM_INSTANCE);
    }
    else
    {
    #endif

        CMP_Type *const pCmp = s_apCmpBase[pCmpHandle->eInstance];

        /* Reset all registers to default value */

        CMP_HWA_SetEn(pCmp, false);
        CMP_HWA_SetDacEnableSrc(pCmp, CMP_DACENABLE_DCR);
        CMP_HWA_SetEnLPMode(pCmp, true);

        CMP_HWA_SetCCR1(pCmp, 0);
        CMP_HWA_SetCCR2(pCmp, 0);
        CMP_HWA_SetDCR(pCmp, 0);
        CMP_HWA_SetIER(pCmp, 0);
        CMP_HWA_SetCSR(pCmp, 0);
        #ifdef  CMP_SUPPORT_CHANNELSCAN_MODE_FEATURE
        CMP_HWA_SetCSCR0(pCmp, 0);
        CMP_HWA_SetCSCR1(pCmp, 0);
        CMP_HWA_SetCSCSR(pCmp, 0);
        CMP_HWA_SetCSSR(pCmp, 0);
        #endif

        pCmpHandle->tSettings.pRisingNotify      = NULL_PTR;
        pCmpHandle->tSettings.pFallingNotify     = NULL_PTR;
        #ifdef  CMP_SUPPORT_CHANNELSCAN_MODE_FEATURE
        pCmpHandle->tSettings.pChannelScanNotify = NULL_PTR;
        #endif

    #if CMP_DEV_ERROR_REPORT == STD_ON
    }
    #endif
}

void CMPn_IRQHandler(CMP_HandleType *pCmpHandle)
{
    bool bRisingFlag;
    bool bFallingFlag;
    #ifdef  CMP_SUPPORT_CHANNELSCAN_MODE_FEATURE
    bool bCSFlag;
    #endif
    CMP_Type *const pCmp = s_apCmpBase[pCmpHandle->eInstance];

    bRisingFlag  = CMP_HWA_GetIntFlag_Rising(pCmp);
    bFallingFlag = CMP_HWA_GetIntFlag_Falling(pCmp);
    #ifdef  CMP_SUPPORT_CHANNELSCAN_MODE_FEATURE
    bCSFlag      = CMP_HWA_GetIntFlag_ChannelScan(pCmp);
    #endif

    /*clear interrupter status regs*/
    CMP_HWA_ClearIntFlag_Rising(pCmp);
    CMP_HWA_ClearIntFlag_Falling(pCmp);
    #ifdef  CMP_SUPPORT_CHANNELSCAN_MODE_FEATURE
    CMP_HWA_ClearIntFlag_ChannelScan(pCmp);
    #endif

    if (pCmpHandle->tSettings.bRisingIntEn)
    {
        if (bRisingFlag && pCmpHandle->tSettings.pRisingNotify != NULL)
        {
            pCmpHandle->tSettings.pRisingNotify(pCmpHandle);
        }
    }

    if (pCmpHandle->tSettings.bFallingIntEn)
    {
        if (bFallingFlag && pCmpHandle->tSettings.pFallingNotify != NULL)
        {
            pCmpHandle->tSettings.pFallingNotify(pCmpHandle);
        }
    }

    #ifdef  CMP_SUPPORT_CHANNELSCAN_MODE_FEATURE
    if (pCmpHandle->tSettings.bChannelScanIntEn)
    {
        if (bCSFlag && pCmpHandle->tSettings.pChannelScanNotify != NULL)
        {
            pCmpHandle->tSettings.pChannelScanNotify(pCmpHandle);
        }
    }
    #endif
}

void CMP_Enter_LP_Mode(CMP_HandleType *pCmpHandle)
{
    #if CMP_DEV_ERROR_REPORT == STD_ON
    if (NULL_PTR == pCmpHandle)
    {
        CMP_ReportDevError(CMP_ENTERLPMODE_ID, CMP_E_PARAM_POINTER);
    }
    else if ((uint32_t)pCmpHandle->eInstance >= CMP_INSTANCE_COUNT)
    {
        CMP_ReportDevError(CMP_ENTERLPMODE_ID, CMP_E_PARAM_INSTANCE);
    }
    else
    {
    #endif

        CMP_Type *const pCmp = s_apCmpBase[pCmpHandle->eInstance];

        if (!(pCmpHandle->tSettings.bLPModeEn))
        {
            /* CFF_IE and CFR_IE need to be set to 0 if STOP_EN = 0 */
            CMP_HWA_SetIntEn_Rising(pCmp, false);
            CMP_HWA_SetIntEn_Falling(pCmp, false);
        }
        else
        {
            /* Do nothing */
        }

    #if CMP_DEV_ERROR_REPORT == STD_ON
    }
    #endif
}

void CMP_Exit_LP_Mode(CMP_HandleType *pCmpHandle)
{
    #if CMP_DEV_ERROR_REPORT == STD_ON
    if (NULL_PTR == pCmpHandle)
    {
        CMP_ReportDevError(CMP_EXITLPMODE_ID, CMP_E_PARAM_POINTER);
    }
    else if ((uint32_t)pCmpHandle->eInstance >= CMP_INSTANCE_COUNT)
    {
        CMP_ReportDevError(CMP_EXITLPMODE_ID, CMP_E_PARAM_INSTANCE);
    }
    else
    {
    #endif

        CMP_Type *const pCmp = s_apCmpBase[pCmpHandle->eInstance];

        CMP_HWA_SetIntEn_Rising(pCmp, pCmpHandle->tSettings.bRisingIntEn);
        CMP_HWA_SetIntEn_Falling(pCmp, pCmpHandle->tSettings.bFallingIntEn);

    #if CMP_DEV_ERROR_REPORT == STD_ON
    }
    #endif
}

#ifdef CMP_SUPPORT_CHANNELSCAN_MODE_FEATURE

bool CMP_GetCSFlagStatus(CMP_HandleType *pCmpHandle)
{
    #if CMP_DEV_ERROR_REPORT == STD_ON
    if (NULL_PTR == pCmpHandle)
    {
        CMP_ReportDevError(CMP_GETCSFLAGSTATUS_ID, CMP_E_PARAM_POINTER);
    }
    else if ((uint32_t)pCmpHandle->eInstance >= CMP_INSTANCE_COUNT)
    {
        CMP_ReportDevError(CMP_GETCSFLAGSTATUS_ID, CMP_E_PARAM_INSTANCE);
    }
    else
    {
    #endif

        CMP_Type *const pCmp = s_apCmpBase[pCmpHandle->eInstance];

        return CMP_HWA_GetIntFlag_ChannelScan(pCmp);

    #if CMP_DEV_ERROR_REPORT == STD_ON
    }
    #endif
}

void CMP_EnableCSChannel(CMP_HandleType *pCmpHandle, const CMP_MuxSelType eChannel, const bool bPreSetState)
{
    #if CMP_DEV_ERROR_REPORT == STD_ON
    if (NULL_PTR == pCmpHandle)
    {
        CMP_ReportDevError(CMP_ENABLECSCHANNEL_ID, CMP_E_PARAM_POINTER);
    }
    else if ((uint32_t)pCmpHandle->eInstance >= CMP_INSTANCE_COUNT)
    {
        CMP_ReportDevError(CMP_ENABLECSCHANNEL_ID, CMP_E_PARAM_INSTANCE);
    }
    else if ((uint32_t)eChannel >= CMP_INSEL_MUX_IN5)
    {
        CMP_ReportDevError(CMP_ENABLECSCHANNEL_ID, CMP_E_PARAM_CHANNEL);
    }
    else
    {
    #endif

        CMP_Type *const pCmp = s_apCmpBase[pCmpHandle->eInstance];

        CMP_HWA_SetCSChannelEn(pCmp, eChannel, true);
        CMP_HWA_SetCSChannelPresetstate(pCmp, eChannel, bPreSetState);

    #if CMP_DEV_ERROR_REPORT == STD_ON
    }
    #endif
}

void CMP_DisableCSChannel(CMP_HandleType *pCmpHandle, const CMP_MuxSelType eChannel)
{
    #if CMP_DEV_ERROR_REPORT == STD_ON
    if (NULL_PTR == pCmpHandle)
    {
        CMP_ReportDevError(CMP_DISABLECSCHANNEL_ID, CMP_E_PARAM_POINTER);
    }
    else if ((uint32_t)pCmpHandle->eInstance >= CMP_INSTANCE_COUNT)
    {
        CMP_ReportDevError(CMP_DISABLECSCHANNEL_ID, CMP_E_PARAM_INSTANCE);
    }
    else if (eChannel >= CMP_INSEL_MUX_IN5)
    {
        CMP_ReportDevError(CMP_DISABLECSCHANNEL_ID, CMP_E_PARAM_CHANNEL);
    }
    else
    {
    #endif

        CMP_Type *const pCmp = s_apCmpBase[pCmpHandle->eInstance];

        CMP_HWA_SetCSChannelEn(pCmp, eChannel, false);
        CMP_HWA_SetCSChannelPresetstate(pCmp, eChannel, false);

    #if CMP_DEV_ERROR_REPORT == STD_ON
    }
    #endif
}

bool CMP_GetCSChannlOut(CMP_HandleType *pCmpHandle, const CMP_MuxSelType e_Channel)
{
    #if CMP_DEV_ERROR_REPORT == STD_ON
    if (NULL_PTR == pCmpHandle)
    {
        CMP_ReportDevError(CMP_GETCSCHANNELOUT_ID, CMP_E_PARAM_POINTER);
    }
    else if ((uint32_t)pCmpHandle->eInstance >= CMP_INSTANCE_COUNT)
    {
        CMP_ReportDevError(CMP_GETCSCHANNELOUT_ID, CMP_E_PARAM_INSTANCE);
    }
    else
    {
    #endif

        CMP_Type *const pCmp = s_apCmpBase[pCmpHandle->eInstance];

        return CMP_HWA_GetCSChannelOut(pCmp, e_Channel);

    #if CMP_DEV_ERROR_REPORT == STD_ON
    }
    #endif
}

bool CMP_GetCmpCSActive(CMP_HandleType *pCmpHandle)
{
    #if CMP_DEV_ERROR_REPORT == STD_ON
    if (NULL_PTR == pCmpHandle)
    {
        CMP_ReportDevError(CMP_GETCMPCSACTIVE_ID, CMP_E_PARAM_POINTER);
    }
    else if ((uint32_t)pCmpHandle->eInstance >= CMP_INSTANCE_COUNT)
    {
        CMP_ReportDevError(CMP_GETCMPCSACTIVE_ID, CMP_E_PARAM_INSTANCE);
    }
    else
    {
    #endif

        CMP_Type *const pCmp = s_apCmpBase[pCmpHandle->eInstance];

        return CMP_HWA_GetCSActive(pCmp);

    #if CMP_DEV_ERROR_REPORT == STD_ON
    }
    #endif
}

#endif /* CMP_SUPPORT_CHANNELSCAN_MODE_FEATURE */

#endif /* CMP_INSTANCE_COUNT > 0U */
