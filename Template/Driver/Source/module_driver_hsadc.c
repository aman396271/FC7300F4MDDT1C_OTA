/**
 * @file module_driver_hsadc.c
 * @author flagchip
 * @brief HSADC driver source code
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
   *   0.1.0       2024-08-15    Flagchip0126  N/A          First version for FC7300
   *********************************************************************************/

#include "module_driver_hsadc.h"

#if HSADC_INSTANCE_COUNT > 0U

#include "module_driver_scg.h"
#include "module_driver_pcc.h"

#if HSADC_DEV_ERROR_REPORT == STD_ON
    #define HSADC_ReportDevError(func, error) ReportDevError(HSADC_MODULE_ID, func, error)
#endif

/**
 * @name  HSADC default values
 * @brief HSADC default configuration parameters
 *
 * @{
 */
#define HSADC_DEFAULT_SAMPLE_TIME_OPTION_0                  (0x06U)
#define HSADC_DEFAULT_SAMPLE_TIME_OPTION_1                  (0x0AU)
#define HSADC_DEFAULT_SAMPLE_TIME_OPTION_2                  (0x22U)
#define HSADC_DEFAULT_SAMPLE_TIME_OPTION_3                  (0x82U)
#define HSADC_DEFAULT_STARTUP_COUNTER                       (0xA0U)
#define HSADC_DEFAULT_WATER_MARK                            (0x08U)
#define HSADC_DEFAULT_COMPARE_HIGH_THRESHOLD                (0x000U)
#define HSADC_DEFAULT_COMPARE_LOW_THRESHOLD                 (0x200U)
#define HSADC_DEFAULT_SC_CHANNEL                            (0x3FU)
/** @}*/

/********* Local Variables ************/
static HSADC_Type *const s_apHsadcBase[HSADC_INSTANCE_COUNT] = HSADC_BASE_PTRS;

/******* Local Function Prototype *********/

/********* Local Functions ************/

static uint32_t HSADC_GetFunctionClockFreq(HSADC_HandleType *pHsadcHandle, const HSADC_InitType *const pInitCfg)
{
    uint32_t u32FunctionClockFreq;

    PCC_ClkSrcType eHsadcClkName = PCC_CLK_HSADC0;

    if (pInitCfg->eFunctionClockSel == FUNCTION_CLOCK_FROM_PCC)
    {
        switch (pHsadcHandle->eInstance)
        {
            case HSADC_INSTANCE_0:
            {
                eHsadcClkName = PCC_CLK_HSADC0;
                break;
            }
            case HSADC_INSTANCE_1:
            {
                eHsadcClkName = PCC_CLK_HSADC1;
                break;
            }
            case HSADC_INSTANCE_2:
            {
                eHsadcClkName = PCC_CLK_HSADC2;
                break;
            }
            case HSADC_INSTANCE_3:
            {
                eHsadcClkName = PCC_CLK_HSADC3;
                break;
            }
            default:
                break;
        }

        u32FunctionClockFreq = PCC_GetPccFunctionClock(eHsadcClkName) / (1U << pInitCfg->eClockDivider);
    }
    else
    {
        u32FunctionClockFreq = pInitCfg->u32ExtClkFreq;
    }

    return u32FunctionClockFreq;
}

/**
 * @brief Exceute HSADC hardware auto calibration
 *
 * @param pHsadcHandle the HSADC instance to exceute calibration
 *
 * @note  User should reset OGCR and DCAPWTn registers to factor test values before calling this function,
 *        hardware uses these values to compensate the conversion results.
 */
static void HSADC_Calibration(const HSADC_HandleType *pHsadcHandle)
{
    HSADC_Type *const pHsadc = s_apHsadcBase[pHsadcHandle->eInstance];
    uint8_t i;
    uint32_t u32TimeOut;
    uint32_t u32Cfg1;
    uint32_t u32Cfg2;
    uint32_t u32CCal;
    uint32_t u32SCCfg;
    int32_t s32ResultBuffer[3];

    /* Enable HSADC */

    HSADC_HWA_Enable(pHsadc);
    u32TimeOut = 15000000U;
    while ((HSADC_HWA_GetHSADCReadyFlag(pHsadc) != true) && (u32TimeOut != 0U))
    {
        u32TimeOut--;
    }
    if (u32TimeOut != 0U)
    {
        HSADC_HWA_ClearHSADCReadyFlag(pHsadc);
    }

    /* Capacitance calibration first. */

    u32Cfg2 = HSADC_CFG2_EXT_CH_EN(false) |
              HSADC_CFG2_FWMARK(HSADC_DEFAULT_WATER_MARK) |
              HSADC_CFG2_SMP_SPARE_EN(true) |
              HSADC_CFG2_TRG_PRI(TRG_LATCH_UNIT_PRI_ROUND_ROBIN) |
              HSADC_CFG2_TRG_CLR(0U) |
              HSADC_CFG2_AVG_EN(true) |
              HSADC_CFG2_AVG_LEN(HSADC_AVERAGE_LEN_32) |
              HSADC_CFG2_STCNT(HSADC_DEFAULT_STARTUP_COUNTER);
    HSADC_HWA_SetConfig2(pHsadc, u32Cfg2);

    u32CCal = HSADC_CCAL_CCAL_EN(true);
    HSADC_HWA_SetCCal(pHsadc, u32CCal);

    HSADC_HWA_Start(pHsadc);
    u32TimeOut = 15000000U;
    while(HSADC_HWA_GetEndOfSequenceFlag(pHsadc) != true && (u32TimeOut != 0U))
    {
        u32TimeOut--;
    }
    if (u32TimeOut != 0U)
    {
        HSADC_HWA_ClearEndOfSequenceFlag(pHsadc);
    }

    u32CCal = HSADC_CCAL_CCAL_EN(false);
    HSADC_HWA_SetCCal(pHsadc, u32CCal);

    /* Capacitance calibration done. All DCAPWTn registers will be updated automatically by hardware. */

    /* Offset and Gain calibration next. */

    u32Cfg1 = HSADC_CFG1_OVRMOD(HSADC_OVERRUN_MODE_PRESERVE) |
              HSADC_CFG1_SEQGP_EN(false) |
              HSADC_CFG1_SEQ_LEN(2U) |
              HSADC_CFG1_SEQ_MOD(HSADC_SEQMODE_SINGLE) |
              HSADC_CFG1_AUTO_DIS(false) |
              HSADC_CFG1_WAIT(false) |
              HSADC_CFG1_TRIGSRC(0U) |
              HSADC_CFG1_TRIGMODE(HSADC_TRGMODE_SW) |
              HSADC_CFG1_ALIGN(HSADC_ALIGN_RIGHT) |
              HSADC_CFG1_SGDMA_SEL(0) |
              HSADC_CFG1_SGDMAEN(false) |
              HSADC_CFG1_DMAEN(false);
    HSADC_HWA_SetConfig1(pHsadc, u32Cfg1);

    u32Cfg2 = HSADC_CFG2_EXT_CH_EN(false) |
              HSADC_CFG2_FWMARK(HSADC_DEFAULT_WATER_MARK) |
              HSADC_CFG2_SMP_SPARE_EN(true) |
              HSADC_CFG2_TRG_PRI(TRG_LATCH_UNIT_PRI_ROUND_ROBIN) |
              HSADC_CFG2_TRG_CLR(0U) |
              HSADC_CFG2_AVG_EN(true) |
              HSADC_CFG2_AVG_LEN(HSADC_AVERAGE_LEN_32) |
              HSADC_CFG2_STCNT(HSADC_DEFAULT_STARTUP_COUNTER);
    HSADC_HWA_SetConfig2(pHsadc, u32Cfg2);

    u32SCCfg = HSADC_SC_SMPSEL(HSADC_DEFAULT_SAMPLE_TIME_OPTION_0) |
               HSADC_SC_COCO(1U) |
               HSADC_SC_AIEN(0U) |
               HSADC_SC_CHS(HSADC_CHANNEL_OFFSET_CALIBRATION);
    HSADC_HWA_SetSCCfg(pHsadc, 0U, u32SCCfg);

    u32SCCfg = HSADC_SC_SMPSEL(HSADC_DEFAULT_SAMPLE_TIME_OPTION_0) |
               HSADC_SC_COCO(1U) |
               HSADC_SC_AIEN(0U) |
               HSADC_SC_CHS(HSADC_CHANNEL_GAIN_LOW_CALIBRATION);
    HSADC_HWA_SetSCCfg(pHsadc, 1U, u32SCCfg);

    u32SCCfg = HSADC_SC_SMPSEL(HSADC_DEFAULT_SAMPLE_TIME_OPTION_0) |
               HSADC_SC_COCO(1U) |
               HSADC_SC_AIEN(0U) |
               HSADC_SC_CHS(HSADC_CHANNEL_GAIN_HIGH_CALIBRATION);
    HSADC_HWA_SetSCCfg(pHsadc, 2U, u32SCCfg);

    HSADC_HWA_Start(pHsadc);
    for (i = 0; i < 3U; i++)
    {
        u32TimeOut = 15000000U;
        while(HSADC_HWA_GetEndOfConversionFlag(pHsadc) != true && (u32TimeOut != 0U))
        {
            u32TimeOut--;
        }
        if (u32TimeOut != 0U)
        {
            HSADC_HWA_ClearEndOfConversionFlag(pHsadc);
        }
        s32ResultBuffer[i] = HSADC_HWA_GetResultCal(pHsadc);
    }

    HSADC_HWA_SetOGCOffset(pHsadc, (uint16_t)s32ResultBuffer[0]);
    HSADC_HWA_SetOGCGain(pHsadc, (uint16_t)(2048 * 3968 / (s32ResultBuffer[2] - s32ResultBuffer[1])));

    /* Offset and Gain calibration done. */

    u32TimeOut = 15000000U;
    HSADC_HWA_Disable(pHsadc);
    while ((HSADC_HWA_GetEnable(pHsadc) == true) && (u32TimeOut != 0U))
    {
        u32TimeOut--;
    }
}

/***************** Global Functions *********************/

void HSADCn_IRQHandler(HSADC_HandleType *pHsadcHandle)
{
    HSADC_Type *const pHsadc = s_apHsadcBase[pHsadcHandle->eInstance];
    uint8_t u8Index;
    uint8_t u8SeqGroupIndex;
    uint8_t u8SeqGroupStart;
    uint8_t u8SeqGroupEnd;
    uint8_t u8BufferIndex;

    if ((pHsadcHandle->tSettings).eSeqMode == HSADC_SEQMODE_GROUP)
    {
        for (u8SeqGroupIndex = 0U; u8SeqGroupIndex < HSADC_SEQ_GROUP_COUNT; u8SeqGroupIndex++)
        {
            if (HSADC_HWA_GetEndOfSGFlag(pHsadc, u8SeqGroupIndex) && HSADC_HWA_GetEndOfSGIntEnable(pHsadc, u8SeqGroupIndex))
            {
                HSADC_HWA_ClearEndOfSGFlag(pHsadc, u8SeqGroupIndex);
                u8SeqGroupStart = HSADC_HWA_GetSGStartPoint(pHsadc, u8SeqGroupIndex);
                u8SeqGroupEnd   = HSADC_HWA_GetSGEndPoint(pHsadc, u8SeqGroupIndex);
                u8BufferIndex   = 0U;
                for (u8Index = u8SeqGroupStart + HSADC_SC_START_INDEX; u8Index < u8SeqGroupEnd + 1U; u8Index++)
                {
                    (pHsadcHandle->tSettings).pSGResultBuffer[u8SeqGroupIndex][u8BufferIndex++] = HSADC_HWA_GetChannelData(pHsadc, u8Index);
                }
                if (pHsadcHandle->tSettings.pSGConvCompleteNotify[u8SeqGroupIndex] != NULL)
                {
                    pHsadcHandle->tSettings.pSGConvCompleteNotify[u8SeqGroupIndex](pHsadcHandle);
                }
            }
        }
    }
    else
    {
        if (HSADC_HWA_GetFIFOReadyFlag(pHsadc) && HSADC_HWA_GetFIFOReadyIntEnable(pHsadc))
        {
            for (u8Index = 0; u8Index < HSADC_SC_START_INDEX; u8Index++)
            {
                (void)HSADC_HWA_GetFIFOData(pHsadc);
            }
            for (u8Index = 0; u8Index < (pHsadcHandle->tSettings).u8ChannelCnt; u8Index++)
            {
                ((pHsadcHandle->tSettings).pResultBuffer)[u8Index] = HSADC_HWA_GetFIFOData(pHsadc);
            }
            if ((pHsadcHandle->tSettings).pConvCompleteNotify != NULL)
            {
                (pHsadcHandle->tSettings).pConvCompleteNotify(pHsadcHandle);
            }
        }
    }

    if (HSADC_HWA_GetFCEnable(pHsadc))
    {
        if (HSADC_HWA_GetFCRFFlag(pHsadc) && HSADC_HWA_GetFCRFIntEnable(pHsadc))
        {
            HSADC_HWA_ClearFCRFFlag(pHsadc);
            if ((pHsadcHandle->tSettings).pFastCmpFallingNotify != NULL)
            {
                (pHsadcHandle->tSettings).pFastCmpFallingNotify(pHsadcHandle);
            }
        }

        if (HSADC_HWA_GetFCRRFlag(pHsadc) && HSADC_HWA_GetFCRRIntEnable(pHsadc))
        {
            HSADC_HWA_ClearFCRRFlag(pHsadc);
            if ((pHsadcHandle->tSettings).pFastCmpRisingNotify != NULL)
            {
                (pHsadcHandle->tSettings).pFastCmpRisingNotify(pHsadcHandle);
            }
        }
    }

    if (HSADC_HWA_GetOverrunFlag(pHsadc) && HSADC_HWA_GetOverrunIntEnable(pHsadc))
    {
        HSADC_HWA_ClearOverrunFlag(pHsadc);
        if ((pHsadcHandle->tSettings).pOverrunNotify != NULL)
        {
            (pHsadcHandle->tSettings).pOverrunNotify(pHsadcHandle);
        }
    }
    if (HSADC_HWA_GetCmpFlag(pHsadc) && HSADC_HWA_GetCmpIntEnable(pHsadc))
    {
        HSADC_HWA_ClearCmpFlag(pHsadc);
        if ((pHsadcHandle->tSettings).pCmpNotify != NULL)
        {
            (pHsadcHandle->tSettings).pCmpNotify(pHsadcHandle);
        }
    }
}

void HSADC_InitStructure(HSADC_InitType *const pInitCfg)
{
    #if HSADC_DEV_ERROR_REPORT == STD_ON
    if (pInitCfg == NULL)
    {
        HSADC_ReportDevError(HSADC_INIT_STRUCTURE_ID, HSADC_E_PARAM_POINTER);
    }
    else
    {
    #endif
        /* Basic Settings */

        pInitCfg->eAlign               = HSADC_ALIGN_RIGHT;                   /* Align right */
        pInitCfg->eTrgMode             = HSADC_TRGMODE_SW;                    /* Software trigger */
        pInitCfg->u16PeriodTrgInterval = 0;                                   /* Step width is 5 HASDC_CLK cycles */
        pInitCfg->bWaitEn              = false;                               /* Enable wait conversion mode */
        pInitCfg->eTrgLatchUnitPri     = TRG_LATCH_UNIT_PRI_ROUND_ROBIN;      /* Round Robin priority */
        pInitCfg->eSeqMode             = HSADC_SEQMODE_SINGLE;                /* Single sequence mode */
        pInitCfg->bAutoDis             = false;                               /* Disable auto disable mode */
        pInitCfg->eOverrunMode         = HSADC_OVERRUN_MODE_PRESERVE;         /* Old conversion data preserved when overrun occured */
        pInitCfg->bAverageEn           = false;                               /* Disable averaging functionality */
        pInitCfg->eAverageLen          = HSADC_AVERAGE_LEN_4;                 /* Average by 4 samples if average is enabled */
        pInitCfg->aSampleTimes[0]      = HSADC_DEFAULT_SAMPLE_TIME_OPTION_0;  /* Sample time option 0 is 6 HSADC Clock */
        pInitCfg->aSampleTimes[1]      = HSADC_DEFAULT_SAMPLE_TIME_OPTION_1;  /* Sample time option 1 is 10 HSADC Clock */
        pInitCfg->aSampleTimes[2]      = HSADC_DEFAULT_SAMPLE_TIME_OPTION_2;  /* Sample time option 2 is 34 HSADC Clock */
        pInitCfg->aSampleTimes[3]      = HSADC_DEFAULT_SAMPLE_TIME_OPTION_3;  /* Sample time option 3 is 130 HSADC Clock */
        pInitCfg->eFunctionClockSel    = FUNCTION_CLOCK_FROM_PCC;             /* Function clock is from PCC */
        pInitCfg->u32ExtClkFreq        = 0U;                                  /* External clock frequency, only valid when eFunctionClockSel == FUNCTION_CLOCK_FROM_EXT_CLK */
        pInitCfg->eClockDivider        = HSADC_CLOCK_DIV_1;
        pInitCfg->bCalibrationEn       = true;
        pInitCfg->bExecuteCalibration  = false;                               /* Execute calibration at initialization */
        pInitCfg->bDmaEn               = false;                               /* Disable DMA for HSADC */

        /* Interrupt Settings */

        pInitCfg->bConvCompleteIntEn   = false;
        pInitCfg->bOverrunIntEn        = false;

        pInitCfg->pConvCompleteNotify  = NULL;
        pInitCfg->pOverrunNotify       = NULL;

        /* Result buffer */

        pInitCfg->pResultBuffer             = NULL;

    #if HSADC_DEV_ERROR_REPORT == STD_ON
    }
    #endif
}

void HSADC_InitSGStructure(HSADC_SGType *const pSGCfg)
{
    #if HSADC_DEV_ERROR_REPORT == STD_ON
    if (pSGCfg == NULL)
    {
        HSADC_ReportDevError(HSADC_INIT_SG_STRUCTURE_ID, HSADC_E_PARAM_POINTER);
    }
    else
    {
    #endif

        pSGCfg->bSG0En                 = false;
        pSGCfg->u8SG0Len               = 0;       /*  */
        pSGCfg->aSG0Channels           = NULL;
        pSGCfg->bSG0ConvCompleteIntEn  = false;   /*  */
        pSGCfg->pSG0ResultBuffer       = NULL;    /*  */
        pSGCfg->pSG0ConvCompleteNotify = NULL;    /*  */
        
        pSGCfg->bSG1En                 = false;
        pSGCfg->u8SG1Len               = 0;
        pSGCfg->aSG1Channels           = NULL;
        pSGCfg->bSG1ConvCompleteIntEn  = false;
        pSGCfg->pSG1ResultBuffer       = NULL;
        pSGCfg->pSG1ConvCompleteNotify = NULL;

        pSGCfg->bSGDmaEn              = false;   /*  */
        pSGCfg->u8SGDMAIndex          = 0;

    #if HSADC_DEV_ERROR_REPORT == STD_ON
    }
    #endif
}

void HSADC_InitCmpStructure(HSADC_CmpType *const pCmpCfg)
{
    #if HSADC_DEV_ERROR_REPORT == STD_ON
    if (pCmpCfg == NULL)
    {
        HSADC_ReportDevError(HSADC_INIT_CMP_STRUCTURE_ID, HSADC_E_PARAM_POINTER);
    }
    else
    {
    #endif

        pCmpCfg->bCmpEn          = false;                       /*  */
        pCmpCfg->eCmpChannelType = HSADC_CMP_CHANNEL_ALL;       /*  */
        pCmpCfg->u8CmpChannelSel = HSADC_CHANNEL_0;             /*  */
        pCmpCfg->u16CmpHighThres = 0;                           /*  */
        pCmpCfg->u16CmpLowThres  = 0;                           /*  */
        pCmpCfg->bCmpIntEn       = false;                       /*  */
        pCmpCfg->pCmpNotify      = NULL;                        /*  */

    #if HSADC_DEV_ERROR_REPORT == STD_ON
    }
    #endif
}

void HSADC_InitFastCmpStructure(HSADC_FastCmpType *const pFastCmpCfg)
{
    #if HSADC_DEV_ERROR_REPORT == STD_ON
    if (pFastCmpCfg == NULL)
    {
        HSADC_ReportDevError(HSADC_INIT_FAST_CMP_STRUCTURE_ID, HSADC_E_PARAM_POINTER);
    }
    else
    {
    #endif

        pFastCmpCfg->bFastCmpEn            = false;
        pFastCmpCfg->bFastCmpPreSetResult  = false;
        pFastCmpCfg->bFastCmpDigitalModeEn = false;
        pFastCmpCfg->bFastCmpSaveConvData  = false;
        pFastCmpCfg->u16FastCmpRefValue    = 0U;
        pFastCmpCfg->u16FastCmpUpperDelta  = 0U;
        pFastCmpCfg->u16FastCmpLowerDelta  = 0U;
        pFastCmpCfg->eFastCmpRefMode       = HSADC_FAST_CMP_REFMODE_SW;
        pFastCmpCfg->eFastCmpRampDir       = HSADC_FAST_CMP_RAMPDIR_UP;
        pFastCmpCfg->eFastCmpRampTrgMode   = HSADC_FAST_CMP_RAMPTRGMODE_SW_AUTO;
        pFastCmpCfg->eFastCmpRampTrgPol    = HSADC_FAST_CMP_RAMPTRGPOL_RISING_OR_HIGH;
        pFastCmpCfg->u8FastCmpRampStep     = 0U;
        pFastCmpCfg->u16FastCmpRampRefA    = 0U;
        pFastCmpCfg->u16FastCmpRampRefB    = 0U;
        pFastCmpCfg->bFastCmpBFLEn         = false;
        pFastCmpCfg->eFastCmpBFLAct        = HSADC_FAST_CMP_BFA_A1B0;
        pFastCmpCfg->bFastCmpBFLInvert     = false;

    #if HSADC_DEV_ERROR_REPORT == STD_ON
    }
    #endif
}

void HSADC_Init(HSADC_HandleType *pHsadcHandle, const HSADC_InitType *const pInitCfg)
{
    #if HSADC_DEV_ERROR_REPORT == STD_ON
    if ((pHsadcHandle == NULL) || (pInitCfg == NULL))
    {
        HSADC_ReportDevError(HSADC_INIT_ID, HSADC_E_PARAM_POINTER);
    }
    else if (pHsadcHandle->eInstance >= HSADC_INSTANCE_COUNT)
    {
        HSADC_ReportDevError(HSADC_INIT_ID, HSADC_E_PARAM_INSTANCE);
    }
    else
    {
    #endif
        HSADC_Type *const pHsadc = s_apHsadcBase[pHsadcHandle->eInstance];
        uint32_t u32TimeOut;
        uint32_t u32Cfg1;
        uint32_t u32Cfg2;
        uint32_t u32Cfg3;
        uint32_t u32Ccal;
        uint32_t u32IntCfg;
        uint32_t u32StartupCnt;
        uint32_t u32FunctionClockFreq;

        bool bSeqGroupEn;

        HSADC_TrgSrcType eTrgSrc;
        HSADC_TrgModeType eTrgMode;

        HSADC_StatusType eRet = HSADC_STATUS_SUCCESS;

        /* Disable HSADC firstly */

        eRet = HSADC_Disable(pHsadcHandle);
        if (eRet != HSADC_STATUS_SUCCESS)
            return;

        /* Set function clock selection firstly, this will reset other registers except CONTROL */

        HSADC_HWA_SetFClkSel(pHsadc, pInitCfg->eFunctionClockSel);

        /* Execute HSADC hardware auto calibration if need */

        if (pInitCfg->bExecuteCalibration)
        {
            HSADC_Calibration(pHsadcHandle);
        }

        if (pInitCfg->eSeqMode != HSADC_SEQMODE_GROUP)
        {
            bSeqGroupEn = false;
            eTrgSrc     = HSADC_TRGSRC_TRGSEL;
            eTrgMode    = pInitCfg->eTrgMode;
        }
        else
        {
            bSeqGroupEn = true;
            eTrgSrc     = HSADC_TRGSRC_TRIG_LATCH_UNIT;
            eTrgMode    = HSADC_TRGMODE_RISING_EDGE;
        }

        u32FunctionClockFreq = HSADC_GetFunctionClockFreq(pHsadcHandle, pInitCfg);

        /* The start up count shall be around 20us */
        u32StartupCnt = 20U * u32FunctionClockFreq / 1000000U / 16u + 1U;
        if (u32StartupCnt > 255U)
        {
            u32StartupCnt = 255U;
        }
        else
        {}

        u32Cfg1 = HSADC_CFG1_OVRMOD(pInitCfg->eOverrunMode) |
                  HSADC_CFG1_SEQGP_EN(bSeqGroupEn)  |
                  HSADC_CFG1_SEQ_LEN(0) |
                  HSADC_CFG1_SEQ_MOD(pInitCfg->eSeqMode) |
                  HSADC_CFG1_AUTO_DIS(pInitCfg->bAutoDis) |
                  HSADC_CFG1_WAIT(pInitCfg->bWaitEn) |
                  HSADC_CFG1_TRIGSRC(eTrgSrc) |
                  HSADC_CFG1_TRIGMODE(eTrgMode) |
                  HSADC_CFG1_ALIGN(pInitCfg->eAlign) |
                  HSADC_CFG1_SGDMA_SEL(HSADC_SEQ_GROUP_0) |
                  HSADC_CFG1_SGDMAEN(false) |
                  HSADC_CFG1_DMAEN(pInitCfg->bDmaEn);
        HSADC_HWA_SetConfig1(pHsadc, u32Cfg1);

        u32Cfg2 = HSADC_CFG2_EXT_CH_EN(false) |
                  HSADC_CFG2_FWMARK(HSADC_DEFAULT_WATER_MARK) |
                  HSADC_CFG2_SMP_SPARE_EN(true) |
                  HSADC_CFG2_TRG_PRI(pInitCfg->eTrgLatchUnitPri) |
                  HSADC_CFG2_TRG_CLR(1U) |
                  HSADC_CFG2_AVG_EN(pInitCfg->bAverageEn) |
                  HSADC_CFG2_AVG_LEN(pInitCfg->eAverageLen) |
                  HSADC_CFG2_STCNT(u32StartupCnt);
        HSADC_HWA_SetConfig2(pHsadc, u32Cfg2);

        u32Cfg3 = HSADC_CFG3_PTRGIV(pInitCfg->u16PeriodTrgInterval);
        HSADC_HWA_SetConfig3(pHsadc, u32Cfg3);

        u32Ccal = HSADC_CCAL_CCAL_EN(false);
        HSADC_HWA_SetCCal(pHsadc, u32Ccal);

        HSADC_HWA_SetOGCEnable(pHsadc, pInitCfg->bCalibrationEn);

        u32TimeOut = 15000000U;
        HSADC_HWA_SetClockGatingEnable(pHsadc, true);
        while ((HSADC_HWA_GetClockGatingAck(pHsadc) != true) && (u32TimeOut != 0))
        {
            u32TimeOut--;
        }
        if (HSADC_HWA_GetClockGatingAck(pHsadc) == true)
        {
            HSADC_HWA_SetClockDivider(pHsadc, pInitCfg->eClockDivider);
        }
        u32TimeOut = 15000000U;
        HSADC_HWA_SetClockGatingEnable(pHsadc, false);
        while ((HSADC_HWA_GetClockGatingAck(pHsadc) != false) && (u32TimeOut != 0))
        {
            u32TimeOut--;
        }

        HSADC_HWA_SetSampleTime(pHsadc, 0U, (uint8_t)(pInitCfg->aSampleTimes[0U]));
        HSADC_HWA_SetSampleTime(pHsadc, 1U, (uint8_t)(pInitCfg->aSampleTimes[1U]));
        HSADC_HWA_SetSampleTime(pHsadc, 2U, (uint8_t)(pInitCfg->aSampleTimes[2U]));
        HSADC_HWA_SetSampleTime(pHsadc, 3U, (uint8_t)(pInitCfg->aSampleTimes[3U]));

        (pHsadcHandle->tSettings).eSeqMode                  = pInitCfg->eSeqMode;
 
        (pHsadcHandle->tSettings).bConvCompleteIntEn        = pInitCfg->bConvCompleteIntEn;
        (pHsadcHandle->tSettings).bOverrunIntEn             = pInitCfg->bOverrunIntEn;

        (pHsadcHandle->tSettings).pOverrunNotify            = pInitCfg->pOverrunNotify;
        (pHsadcHandle->tSettings).pConvCompleteNotify       = pInitCfg->pConvCompleteNotify;

        (pHsadcHandle->tSettings).pResultBuffer             = pInitCfg->pResultBuffer;

        switch (pInitCfg->eSeqMode)
        {
            case HSADC_SEQMODE_GROUP:
            {
                u32IntCfg = 0u;
                break;
            }
            case HSADC_SEQMODE_SINGLE:
            case HSADC_SEQMODE_CONTINUOUS:
            case HSADC_SEQMODE_DISCONTINUOUS:
            {
                u32IntCfg = HSADC_INT_ENABLE_OVRIE((pHsadcHandle->tSettings).bOverrunIntEn) |
                            HSADC_INT_ENABLE_FIFO_RDY_IE((pHsadcHandle->tSettings).bConvCompleteIntEn);
                break;
            }
            default:
            {
                u32IntCfg = 0u;
                break;
            }
        }

        HSADC_HWA_SetInterruptEnable(pHsadc, u32IntCfg);

    #if HSADC_DEV_ERROR_REPORT == STD_ON
    }
    #endif
}

void HSADC_DeInit(HSADC_HandleType *pHsadcHandle)
{
    #if HSADC_DEV_ERROR_REPORT == STD_ON
    if (pHsadcHandle == NULL)
    {
        HSADC_ReportDevError(HSADC_DEINIT_ID, HSADC_E_PARAM_POINTER);
    }
    else if (pHsadcHandle->eInstance >= HSADC_INSTANCE_COUNT)
    {
        HSADC_ReportDevError(HSADC_DEINIT_ID, HSADC_E_PARAM_INSTANCE);
    }
    else
    {
    #endif
        HSADC_Type *const pHsadc = s_apHsadcBase[pHsadcHandle->eInstance];
        uint32_t u32TimeOut;
        uint8_t i;

        u32TimeOut = 15000000U;

        if (HSADC_HWA_GetStart(pHsadc) == true)
        {
            HSADC_HWA_Stop(pHsadc);

            while ((HSADC_HWA_GetStop(pHsadc) == true) && (u32TimeOut != 0U))
            {
                u32TimeOut--;
            }
        }

        u32TimeOut = 15000000U;

        if (HSADC_HWA_GetEnable(pHsadc) == true)
        {
            HSADC_HWA_Disable(pHsadc);

            while ((HSADC_HWA_GetEnable(pHsadc) == true) && (u32TimeOut != 0U))
            {
                u32TimeOut--;
            }
        }

        /* Reset all registers to default values */

        HSADC_HWA_Reset(pHsadc);

        pHsadcHandle->tSettings.eSeqMode             = HSADC_SEQMODE_SINGLE;
        pHsadcHandle->tSettings.u8ChannelCnt         = 0U;
        pHsadcHandle->tSettings.bConvCompleteIntEn   = false;
        pHsadcHandle->tSettings.bOverrunIntEn        = false;
        pHsadcHandle->tSettings.bCmpIntEn            = false;
        pHsadcHandle->tSettings.bSGConvCompleteIntEn = false;
        pHsadcHandle->tSettings.pConvCompleteNotify  = NULL;
        pHsadcHandle->tSettings.pOverrunNotify       = NULL;
        pHsadcHandle->tSettings.pCmpNotify           = NULL;
        for (i = 0; i < HSADC_SEQ_GROUP_COUNT; i++)
            pHsadcHandle->tSettings.pSGConvCompleteNotify[i] = NULL;
        pHsadcHandle->tSettings.pResultBuffer = NULL;
        for (i = 0; i < HSADC_SEQ_GROUP_COUNT; i++)
            pHsadcHandle->tSettings.pSGResultBuffer[i] = NULL;
        pHsadcHandle->tSettings.bFastCmpFallingIntEn   = false;
        pHsadcHandle->tSettings.bFastCmpRisingIntEn    = false;
        pHsadcHandle->tSettings.pFastCmpRisingNotify   = NULL;
        pHsadcHandle->tSettings.pFastCmpFallingNotify  = NULL;

    #if HSADC_DEV_ERROR_REPORT == STD_ON
    }
    #endif
}

void HSADC_InitChannel(HSADC_HandleType *pHsadcHandle, const HSADC_ChannelCfgType aChannels[],
                       const uint8_t u8ChannelCnt)
{
    #if HSADC_DEV_ERROR_REPORT == STD_ON
    if (pHsadcHandle == NULL || aChannels == NULL)
    {
        HSADC_ReportDevError(HSADC_INIT_CHANNEL_ID, HSADC_E_PARAM_POINTER);
    }
    else if (pHsadcHandle->eInstance >= HSADC_INSTANCE_COUNT)
    {
        HSADC_ReportDevError(HSADC_INIT_CHANNEL_ID, HSADC_E_PARAM_INSTANCE);
    }
    else if (u8ChannelCnt >= (HSADC_SC_COUNT - HSADC_SC_START_INDEX))
    {
        HSADC_ReportDevError(HSADC_INIT_CHANNEL_ID, HSADC_E_PARAM_CHANNEL);
    }
    else
    {
    #endif
        HSADC_Type *const pHsadc = s_apHsadcBase[pHsadcHandle->eInstance];

        bool bExtendChannelEn = false;

        pHsadcHandle->tSettings.u8ChannelCnt = u8ChannelCnt;

        uint8_t u8ChnIndex;

        /* Fill two internal channels to avoid conversion data non-correct issue */
        for (u8ChnIndex = 0U; u8ChnIndex < HSADC_SC_START_INDEX; u8ChnIndex++)
        {
            HSADC_HWA_SetChannelSampleTimeIndex(pHsadc, u8ChnIndex, HSADC_DEFAULT_SAMPLE_TIME_OPTION_0);
            HSADC_HWA_SetChannelCoCoIntEnable(pHsadc, u8ChnIndex, false);
            HSADC_HWA_SetChannelInput(pHsadc, u8ChnIndex, HSADC_CHANNEL_INTERNAL_0);
        }

        for (u8ChnIndex = 0U; u8ChnIndex < u8ChannelCnt; u8ChnIndex++)
        {
            if (aChannels[u8ChnIndex].eChannel >= HSADC_CHANNEL_EXTEND_0 && aChannels[u8ChnIndex].eChannel <= HSADC_CHANNEL_EXTEND_7)
                bExtendChannelEn = true;

            HSADC_HWA_SetChannelSampleTimeIndex(pHsadc, u8ChnIndex + HSADC_SC_START_INDEX, aChannels[u8ChnIndex].eSampleTimeOption);
            HSADC_HWA_SetChannelCoCoIntEnable(pHsadc, u8ChnIndex + HSADC_SC_START_INDEX, false);
            HSADC_HWA_SetChannelInput(pHsadc, u8ChnIndex + HSADC_SC_START_INDEX, aChannels[u8ChnIndex].eChannel);
        }

        HSADC_HWA_SetExtChEnable(pHsadc, bExtendChannelEn);
        HSADC_HWA_SetSequenceLength(pHsadc, (uint8_t)(u8ChannelCnt + HSADC_SC_START_INDEX - 1U));
        HSADC_HWA_SetFIFOWaterMark(pHsadc, (uint8_t)(u8ChannelCnt + HSADC_SC_START_INDEX - 1U));

    #if HSADC_DEV_ERROR_REPORT == STD_ON
    }
    #endif
}

void HSADC_InitCmp(HSADC_HandleType *pHsadcHandle, const HSADC_CmpType *const pCmpCfg)
{
    #if HSADC_DEV_ERROR_REPORT == STD_ON
    if ((pCmpCfg == NULL) || (pHsadcHandle == NULL))
    {
        HSADC_ReportDevError(HSADC_INIT_CMP_ID, HSADC_E_PARAM_POINTER);
    }
    else if ((pHsadcHandle->eInstance) >= HSADC_INSTANCE_COUNT)
    {
        HSADC_ReportDevError(HSADC_INIT_CMP_ID, HSADC_E_PARAM_INSTANCE);
    }
    else
    {
    #endif
        HSADC_Type *const pHsadc = s_apHsadcBase[pHsadcHandle->eInstance];

        if (pCmpCfg->bCmpEn)
        {
            HSADC_HWA_SetCmpChannel(pHsadc, pCmpCfg->eCmpChannelType, pCmpCfg->u8CmpChannelSel);
            HSADC_HWA_SetCmpThreshold(pHsadc, pCmpCfg->u16CmpLowThres, pCmpCfg->u16CmpHighThres);
            HSADC_HWA_SetCmpIntEnable(pHsadc, pCmpCfg->bCmpIntEn);
            pHsadcHandle->tSettings.bCmpIntEn = pCmpCfg->bCmpIntEn;
            pHsadcHandle->tSettings.pCmpNotify = pCmpCfg->pCmpNotify;
            HSADC_HWA_SetCmpEnable(pHsadc, true);
        }
        else
        {
            HSADC_HWA_SetCmpEnable(pHsadc, false);
        }

    #if HSADC_DEV_ERROR_REPORT == STD_ON
    }
    #endif
}

void HSADC_InitFastCmp(HSADC_HandleType *pHsadcHandle, const HSADC_FastCmpType *const pFastCmpCfg)
{
    #if HSADC_DEV_ERROR_REPORT == STD_ON
    if ((pFastCmpCfg == NULL) || (pHsadcHandle == NULL))
    {
        HSADC_ReportDevError(HSADC_INIT_FAST_CMP_ID, HSADC_E_PARAM_POINTER);
    }
    else if ((pHsadcHandle->eInstance) >= HSADC_INSTANCE_COUNT)
    {
        HSADC_ReportDevError(HSADC_INIT_FAST_CMP_ID, HSADC_E_PARAM_INSTANCE);
    }
    else
    {
    #endif
        HSADC_Type *const pHsadc = s_apHsadcBase[pHsadcHandle->eInstance];
        uint32_t u32FCCTRL;
        uint32_t u32FCHyst;
        uint32_t u32FCRamp0;
        uint32_t u32FCRamp1;

        bool bFCModALT = false;
        bool bFCRampCntEn = false;
        bool bFCConvDataSave = false;

        if (pFastCmpCfg->bFastCmpEn == true)
        {
            if (pFastCmpCfg->eFastCmpRefMode == HSADC_FAST_CMP_REFMODE_SW)
            {
                bFCModALT = false;
                bFCRampCntEn = false;
            }
            else if(pFastCmpCfg->eFastCmpRefMode == HSADC_FAST_CMP_REFMODE_RAMP)
            {
                bFCModALT = false;
                bFCRampCntEn = true;
            }
            else if(pFastCmpCfg->eFastCmpRefMode == HSADC_FAST_CMP_REFMODE_ALT)
            {
                bFCModALT = true;
                bFCRampCntEn = false;
            }
            else
            {
                bFCModALT = false;
                bFCRampCntEn = false;
            }

            if (pFastCmpCfg->bFastCmpDigitalModeEn == true)
            {
                bFCConvDataSave = pFastCmpCfg->bFastCmpSaveConvData;
            }
            else
            {
                bFCConvDataSave = false;
            }

            /* Config fast compare channel */
            HSADC_HWA_SetChannelSampleTimeIndex(pHsadc, 0, pFastCmpCfg->eFastCmpSampleTimeOption);
            HSADC_HWA_SetChannelCoCoIntEnable(pHsadc, 0, false);
            HSADC_HWA_SetChannelInput(pHsadc, 0, pFastCmpCfg->eFastCmpChannel);
            if (pFastCmpCfg->eFastCmpChannel >= HSADC_CHANNEL_EXTEND_0 && pFastCmpCfg->eFastCmpChannel <= HSADC_CHANNEL_EXTEND_7)
                HSADC_HWA_SetExtChEnable(pHsadc, true);
            else
                HSADC_HWA_SetExtChEnable(pHsadc, false);
            HSADC_HWA_SetSequenceLength(pHsadc, 0U);
            HSADC_HWA_SetFIFOWaterMark(pHsadc, 0U);

            /* Disable fast compare function firstly. */
            HSADC_HWA_SetFCEnable(pHsadc, false);

            HSADC_HWA_SetFCRef(pHsadc, pFastCmpCfg->u16FastCmpRefValue);

            u32FCRamp0 = pFastCmpCfg->u16FastCmpRampRefA;
            u32FCRamp0 <<= 16U;
            u32FCRamp0 |= pFastCmpCfg->u8FastCmpRampStep;
            HSADC_HWA_SetFCRamp0(pHsadc, u32FCRamp0);

            u32FCRamp1 = pFastCmpCfg->u16FastCmpRampRefB;
            u32FCRamp1 <<= 16U;
            u32FCRamp1 |= pFastCmpCfg->eFastCmpRampDir;
            HSADC_HWA_SetFCRamp1(pHsadc, u32FCRamp1);

            u32FCHyst = pFastCmpCfg->u16FastCmpUpperDelta;
            u32FCHyst <<= 16U;
            u32FCHyst |= pFastCmpCfg->u16FastCmpLowerDelta;
            HSADC_HWA_SetFCHysteresis(pHsadc, u32FCHyst);

            /* Just write fast compare ctrl register after setting other fast compare function registers. */
            u32FCCTRL = HSADC_FCMP_CTRL_DATA_SAVE(bFCConvDataSave) |
                        HSADC_FCMP_CTRL_RPTRG_SEL(pFastCmpCfg->eFastCmpRampTrgMode) |
                        HSADC_FCMP_CTRL_RPCNT_EN(bFCRampCntEn) |
                        HSADC_FCMP_CTRL_ETRG_POL(pFastCmpCfg->eFastCmpRampTrgPol) |
                        HSADC_FCMP_CTRL_FCMOD_ALT(bFCModALT) |
                        HSADC_FCMP_CTRL_FC_DSEL(pFastCmpCfg->bFastCmpDigitalModeEn) |
                        HSADC_FCMP_CTRL_FC_EN(true); /* Enable fast compare function here. */
            HSADC_HWA_SetFCCtrl(pHsadc, u32FCCTRL);

            if (pFastCmpCfg->bFastCmpFallingIntEn)
            {
                HSADC_HWA_SetFCRFIntEnable(pHsadc, true);
                pHsadcHandle->tSettings.pFastCmpFallingNotify = pFastCmpCfg->pFastCmpFallingNotify;
            }

            if (pFastCmpCfg->bFastCmpRisingIntEn)
            {
                HSADC_HWA_SetFCRRIntEnable(pHsadc, true);
                pHsadcHandle->tSettings.pFastCmpRisingNotify = pFastCmpCfg->pFastCmpRisingNotify;
            }
        }
        else
        {
            HSADC_HWA_SetFCEnable(pHsadc, false);
        }

    #if HSADC_DEV_ERROR_REPORT == STD_ON
    }
    #endif
}

void HSADC_InitSG(HSADC_HandleType *pHsadcHandle, const HSADC_SGType *const pSGType)
{
    #if HSADC_DEV_ERROR_REPORT == STD_ON
    if ((pSGType == NULL) || (pHsadcHandle == NULL))
    {
        HSADC_ReportDevError(HSADC_INIT_SG_ID, HSADC_E_PARAM_POINTER);
    }
    else if ((pHsadcHandle->eInstance) >= HSADC_INSTANCE_COUNT)
    {
        HSADC_ReportDevError(HSADC_INIT_SG_ID, HSADC_E_PARAM_INSTANCE);
    }
    else if ((pHsadcHandle->tSettings.eSeqMode) != HSADC_SEQMODE_GROUP)
    {
        HSADC_ReportDevError(HSADC_INIT_SG_ID, HSADC_E_PARAM_INVALID);
    }
    else
    {
    #endif
        HSADC_Type *const pHsadc = s_apHsadcBase[pHsadcHandle->eInstance];
        bool bExtendChannelEn = false;
        uint32_t u32RegVal;
        uint8_t u8ChnIndex;
        uint8_t u8SCnIndex;

        u8SCnIndex = 0;

        if (pSGType->bSGDmaEn)
        {
            u32RegVal = HSADC_HWA_GetConfig1(pHsadc);
            u32RegVal &= ~HSADC_CFG1_SGDMA_SEL_MASK;
            u32RegVal = HSADC_CFG1_SGDMA_SEL(pSGType->u8SGDMAIndex) | HSADC_CFG1_SGDMAEN(true);
            HSADC_HWA_SetConfig1(pHsadc, u32RegVal);
        }
        else
        {
            u32RegVal = HSADC_HWA_GetConfig1(pHsadc);
            u32RegVal &= ~(HSADC_CFG1_SGDMA_SEL_MASK | HSADC_CFG1_SGDMAEN_MASK);
            HSADC_HWA_SetConfig1(pHsadc, u32RegVal);
        }

        if (pSGType->bSG0En)
        {
            /* SG0's start point must be 0, end point must be 0 + HSADC_SC_START_INDEX + SG0's length - 1. */
            HSADC_HWA_SetSGStartEndPoint(pHsadc, 0, 0, (uint8_t)(0 + HSADC_SC_START_INDEX + pSGType->u8SG0Len - 1));
            HSADC_HWA_SetEndOfSGIntEnable(pHsadc, 0, pSGType->bSG0ConvCompleteIntEn);
            pHsadcHandle->tSettings.pSGResultBuffer[0]  = pSGType->pSG0ResultBuffer;
            pHsadcHandle->tSettings.pSGConvCompleteNotify[0] = pSGType->pSG0ConvCompleteNotify;

            /* Fill two internal channels to avoid conversion date non-correct issue */
            for (u8ChnIndex = 0U; u8ChnIndex < HSADC_SC_START_INDEX; u8ChnIndex++)
            {
                HSADC_HWA_SetChannelSampleTimeIndex(pHsadc, u8SCnIndex, HSADC_DEFAULT_SAMPLE_TIME_OPTION_0);
                HSADC_HWA_SetChannelCoCoIntEnable(pHsadc, u8SCnIndex, false);
                HSADC_HWA_SetChannelInput(pHsadc, u8SCnIndex, HSADC_CHANNEL_INTERNAL_0);
                u8SCnIndex++;
            }
            for (u8ChnIndex = 0U; u8ChnIndex < pSGType->u8SG0Len; u8ChnIndex++)
            {
                if ( pSGType->aSG0Channels[u8ChnIndex].eChannel >= HSADC_CHANNEL_EXTEND_0 &&  pSGType->aSG0Channels[u8ChnIndex].eChannel <= HSADC_CHANNEL_EXTEND_7)
                    bExtendChannelEn = true;

                HSADC_HWA_SetChannelSampleTimeIndex(pHsadc, u8SCnIndex, pSGType->aSG0Channels[u8ChnIndex].eSampleTimeOption);
                HSADC_HWA_SetChannelCoCoIntEnable(pHsadc, u8SCnIndex, false);
                HSADC_HWA_SetChannelInput(pHsadc, u8SCnIndex, pSGType->aSG0Channels[u8ChnIndex].eChannel);
                u8SCnIndex++;
            }
        }
        else
        {
            HSADC_HWA_SetSGStartEndPoint(pHsadc, 0, 0, 0);
            HSADC_HWA_SetEndOfSGIntEnable(pHsadc, 0, false);
            pHsadcHandle->tSettings.pSGResultBuffer[0]  = NULL;
            pHsadcHandle->tSettings.pSGConvCompleteNotify[0] = NULL;
        }

        if (pSGType->bSG1En)
        {
            /* SG1's start point must be SG0 end point + 1, end point must be SG0 end point + 1 + HSADC_SC_START_INDEX + SG1's length - 1. */
            HSADC_HWA_SetSGStartEndPoint(pHsadc, 1, u8SCnIndex, (uint8_t)(u8SCnIndex + HSADC_SC_START_INDEX + pSGType->u8SG1Len - 1));
            HSADC_HWA_SetEndOfSGIntEnable(pHsadc, 1, pSGType->bSG1ConvCompleteIntEn);
            pHsadcHandle->tSettings.pSGResultBuffer[1]  = pSGType->pSG1ResultBuffer;
            pHsadcHandle->tSettings.pSGConvCompleteNotify[1] = pSGType->pSG1ConvCompleteNotify;

            /* Fill two internal channels to avoid conversion date non-correct issue */
            for (u8ChnIndex = 0U; u8ChnIndex < HSADC_SC_START_INDEX; u8ChnIndex++)
            {
                HSADC_HWA_SetChannelSampleTimeIndex(pHsadc, u8SCnIndex, HSADC_DEFAULT_SAMPLE_TIME_OPTION_0);
                HSADC_HWA_SetChannelCoCoIntEnable(pHsadc, u8SCnIndex, false);
                HSADC_HWA_SetChannelInput(pHsadc, u8SCnIndex, HSADC_CHANNEL_INTERNAL_0);
                u8SCnIndex++;
            }
            for (u8ChnIndex = 0U; u8ChnIndex < pSGType->u8SG1Len; u8ChnIndex++)
            {
                if ( pSGType->aSG1Channels[u8ChnIndex].eChannel >= HSADC_CHANNEL_EXTEND_0 &&  pSGType->aSG1Channels[u8ChnIndex].eChannel <= HSADC_CHANNEL_EXTEND_7)
                    bExtendChannelEn = true;

                HSADC_HWA_SetChannelSampleTimeIndex(pHsadc, u8SCnIndex, pSGType->aSG1Channels[u8ChnIndex].eSampleTimeOption);
                HSADC_HWA_SetChannelCoCoIntEnable(pHsadc, u8SCnIndex, false);
                HSADC_HWA_SetChannelInput(pHsadc, u8SCnIndex, pSGType->aSG1Channels[u8ChnIndex].eChannel);
                u8SCnIndex++;
            }
        }
        else
        {
            HSADC_HWA_SetSGStartEndPoint(pHsadc, 1, 0, 0);
            HSADC_HWA_SetEndOfSGIntEnable(pHsadc, 1, false);
            pHsadcHandle->tSettings.pSGResultBuffer[1]  = NULL;
            pHsadcHandle->tSettings.pSGConvCompleteNotify[1] = NULL;
        }

        HSADC_HWA_SetExtChEnable(pHsadc, bExtendChannelEn);

    #if HSADC_DEV_ERROR_REPORT == STD_ON
    }
    #endif
}

HSADC_StatusType HSADC_Enable(const HSADC_HandleType *pHsadcHandle)
{
    HSADC_StatusType eRet = HSADC_STATUS_SUCCESS;
    #if HSADC_DEV_ERROR_REPORT == STD_ON
    if (pHsadcHandle == NULL)
    {
        HSADC_ReportDevError(HSADC_ENABLE_ID, HSADC_E_PARAM_POINTER);
    }
    else if ((pHsadcHandle->eInstance) >= HSADC_INSTANCE_COUNT)
    {
        HSADC_ReportDevError(HSADC_ENABLE_ID, HSADC_E_PARAM_INSTANCE);
    }
    else
    {
    #endif
        uint32_t u32TimeOut = 15000000U;
        HSADC_Type *const pHsadc = s_apHsadcBase[pHsadcHandle->eInstance];

        HSADC_HWA_Enable(pHsadc);
        while ((HSADC_HWA_GetHSADCReadyFlag(pHsadc) != true) && (u32TimeOut != 0U))
        {
            u32TimeOut--;
        }
        if (u32TimeOut != 0U)
        {
            HSADC_HWA_ClearHSADCReadyFlag(pHsadc);
            eRet = HSADC_STATUS_SUCCESS;
        }
        else
        {
            eRet = HSADC_STATUS_TIMEOUT;
        }
    #if HSADC_DEV_ERROR_REPORT == STD_ON
    }
    #endif
    return eRet;
}

HSADC_StatusType HSADC_Disable(HSADC_HandleType *pHsadcHandle)
{
    HSADC_StatusType eRet = HSADC_STATUS_SUCCESS;
    #if HSADC_DEV_ERROR_REPORT == STD_ON
    if (pHsadcHandle == NULL)
    {
        HSADC_ReportDevError(HSADC_DISABLE_ID, HSADC_E_PARAM_POINTER);
    }
    else if ((pHsadcHandle->eInstance) >= HSADC_INSTANCE_COUNT)
    {
        HSADC_ReportDevError(HSADC_DISABLE_ID, HSADC_E_PARAM_INSTANCE);
    }
    else
    {
    #endif
        uint32_t u32TimeOut = 15000000U;
        HSADC_Type *const pHsadc = s_apHsadcBase[pHsadcHandle->eInstance];

        if (HSADC_HWA_GetStart(pHsadc) == true)
        {
            eRet = HSADC_Stop(pHsadcHandle);
        }

        if (eRet == HSADC_STATUS_SUCCESS)
        {
            HSADC_HWA_Disable(pHsadc);
            while ((HSADC_HWA_GetEnable(pHsadc) == true) && (u32TimeOut != 0U))
            {
                u32TimeOut--;
            }
            if (u32TimeOut != 0U)
            {
                eRet = HSADC_STATUS_SUCCESS;
            }
            else
            {
                eRet = HSADC_STATUS_TIMEOUT;
            }
        }
    #if HSADC_DEV_ERROR_REPORT == STD_ON
    }
    #endif
    return eRet;
}

void HSADC_Start(const HSADC_HandleType *pHsadcHandle)
{
    #if HSADC_DEV_ERROR_REPORT == STD_ON
    if (pHsadcHandle == NULL)
    {
        HSADC_ReportDevError(HSADC_START_ID, HSADC_E_PARAM_POINTER);
    }
    else if ((pHsadcHandle->eInstance) >= HSADC_INSTANCE_COUNT)
    {
        HSADC_ReportDevError(HSADC_START_ID, HSADC_E_PARAM_INSTANCE);
    }
    else
    {
    #endif
        HSADC_Type *const pHsadc = s_apHsadcBase[pHsadcHandle->eInstance];
        HSADC_HWA_Start(pHsadc);
    #if HSADC_DEV_ERROR_REPORT == STD_ON
    }
    #endif
}

HSADC_StatusType HSADC_Stop(const HSADC_HandleType *pHsadcHandle)
{
    HSADC_StatusType eRet = HSADC_STATUS_ERROR;
    #if HSADC_DEV_ERROR_REPORT == STD_ON
    if (pHsadcHandle == NULL)
    {
        HSADC_ReportDevError(HSADC_STOP_ID, HSADC_E_PARAM_POINTER);
    }
    else if ((pHsadcHandle->eInstance) >= HSADC_INSTANCE_COUNT)
    {
        HSADC_ReportDevError(HSADC_STOP_ID, HSADC_E_PARAM_INSTANCE);
    }
    else
    {
    #endif
        uint32_t u32TimeOut = 15000000U;
        HSADC_Type *const pHsadc = s_apHsadcBase[pHsadcHandle->eInstance];

        HSADC_HWA_Stop(pHsadc);

        while ((HSADC_HWA_GetStop(pHsadc) == true) && (u32TimeOut != 0U))
        {
            u32TimeOut--;
        }
        if (u32TimeOut != 0U)
        {
            eRet = HSADC_STATUS_SUCCESS;
        }
        else
        {
            eRet = HSADC_STATUS_TIMEOUT;
        }
    #if HSADC_DEV_ERROR_REPORT == STD_ON
    }
    #endif
    return eRet;
}

void HSADC_Reset(const HSADC_HandleType *pHsadcHandle)
{
    #if HSADC_DEV_ERROR_REPORT == STD_ON
    if (pHsadcHandle == NULL)
    {
        HSADC_ReportDevError(HSADC_RESET_ID, HSADC_E_PARAM_POINTER);
    }
    else if ((pHsadcHandle->eInstance) >= HSADC_INSTANCE_COUNT)
    {
        HSADC_ReportDevError(HSADC_RESET_ID, HSADC_E_PARAM_INSTANCE);
    }
    else
    {
    #endif
        HSADC_Type *const pHsadc = s_apHsadcBase[pHsadcHandle->eInstance];

        /* TODO : Disable Interrupt and DMA */

        HSADC_HWA_Reset(pHsadc);
    #if HSADC_DEV_ERROR_REPORT == STD_ON
    }
    #endif
}

bool HSADC_GetFastCmpResult(const HSADC_HandleType *pHsadcHandle)
{
    #if HSADC_DEV_ERROR_REPORT == STD_ON
    if (pHsadcHandle == NULL)
    {
        HSADC_ReportDevError(HSADC_GET_FAST_CMP_RESULT_ID, HSADC_E_PARAM_POINTER);
    }
    else if ((pHsadcHandle->eInstance) >= HSADC_INSTANCE_COUNT)
    {
        HSADC_ReportDevError(HSADC_GET_FAST_CMP_RESULT_ID, HSADC_E_PARAM_INSTANCE);
    }
    else
    {
    #endif

        HSADC_Type *const pHsadc = s_apHsadcBase[pHsadcHandle->eInstance];
        return HSADC_HWA_GetFCResult(pHsadc);

    #if HSADC_DEV_ERROR_REPORT == STD_ON
    }
    #endif
}

bool HSADC_GetFastCmpBoundaryFlag(const HSADC_HandleType *pHsadcHandle)
{
    #if HSADC_DEV_ERROR_REPORT == STD_ON
    if (pHsadcHandle == NULL)
    {
        HSADC_ReportDevError(HSADC_GET_FAST_CMP_BOUNDARY_FLAG_ID, HSADC_E_PARAM_POINTER);
    }
    else if ((pHsadcHandle->eInstance) >= HSADC_INSTANCE_COUNT)
    {
        HSADC_ReportDevError(HSADC_GET_FAST_CMP_BOUNDARY_FLAG_ID, HSADC_E_PARAM_INSTANCE);
    }
    else
    {
    #endif

        HSADC_Type *const pHsadc = s_apHsadcBase[pHsadcHandle->eInstance];
        return HSADC_HWA_GetFCBoundaryFlag(pHsadc);

    #if HSADC_DEV_ERROR_REPORT == STD_ON
    }
    #endif
}

#endif /* HSADC_INSTANCE_COUNT > 0 */
