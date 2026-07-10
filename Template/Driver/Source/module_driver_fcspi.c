/**
 * @file module_driver_fcspi.c
 * @author Flagchip
 * @brief FCSPI driver type definition and API
 * @version 2.0.0
 * @date 2024-08-20
 *
 * @copyright Copyright (c) 2020-2024 Flagchip Semiconductors Co., Ltd.
 *
 */
/* ********************************************************************************
   *   Revision History:
   *
   *   Version     Date          Initials      CR#          Descriptions
   *   ---------   ----------    ------------  ----------   ---------------
   *   0.1.0       31/12/2022    Flagchip071    N/A          First version for FC7300
   *   0.2.0       04/02/2022    Flagchip071    N/A          0.2.0 release
   *   2.0.0       30/07/2024    Flagchip0103   N/A          SDK2.0 architecture
   ******************************************************************************** */

#include "module_driver_fcspi.h"
#include "module_driver_scg.h"
#include "module_driver_pcc.h"
#include "module_driver_dma.h"

#if FCSPI_INSTANCE_COUNT > 0U

#if FCSPI_DEV_ERROR_REPORT == STD_ON
#define FCSPI_ReportDevError(func, error) ReportDevError(FCSPI_MODULE_ID, func, error)
#endif

/**
 * @brief FCSPI FIFO depth(words).
 *
 * @{
 */
#define FCSPI_TX_FIFO_DEPTH            (0x08U)
#define FCSPI_RX_FIFO_DEPTH            (0x08U)
/** @}*/

static FCSPI_Type *const s_apFcspiBase[FCSPI_INSTANCE_COUNT] = FCSPI_BASE_PTRS;

static void fcspi_isr_transmit_8bit(FCSPI_HandleType *pFcspiHandle);
static void fcspi_isr_transmit_16bit(FCSPI_HandleType *pFcspiHandle);
static void fcspi_isr_transmit_32bit(FCSPI_HandleType *pFcspiHandle);

static void fcspi_isr_receive_8bit(FCSPI_HandleType *pFcspiHandle);
static void fcspi_isr_receive_16bit(FCSPI_HandleType *pFcspiHandle);
static void fcspi_isr_receive_32bit(FCSPI_HandleType *pFcspiHandle);

static void fcspi_isr_receive_8bit_cs_no_cont(FCSPI_HandleType *pFcspiHandle);
static void fcspi_isr_receive_16bit_cs_no_cont(FCSPI_HandleType *pFcspiHandle);
static void fcspi_isr_receive_32bit_cs_no_cont(FCSPI_HandleType *pFcspiHandle);
uint32_t FCSPI_LL_CaculateClockConfigParam(uint32_t *Prescale, uint32_t *Sckdiv, uint32_t InputClkFreq, FCSPI_HandleType *pFcspiHandle);

uint32_t FCSPI_LL_CaculateSckdivPrescale(uint32_t *Prescale, uint32_t *Sckdiv, uint32_t InputClkFreq, uint32_t TargetSckFreq)
{
    const uint32_t prescaleValues[] = {1u, 2u, 4u, 8u, 16u, 32u, 64u, 128u};
    const uint32_t sckdivMax = 257u;
    const uint32_t sckdivMin = 2u;

    uint32_t bestPrescale = 1u;
    uint32_t bestSckdiv = 2u;
    uint32_t bestFreq = 0u;
    uint32_t minError = InputClkFreq;

    /* Iterate through all possible 'Prescale' values */
    for (uint8_t i = 0; i < sizeof(prescaleValues) / sizeof(prescaleValues[0]); i++)
    {
        uint32_t currentPrescale = prescaleValues[i];
        uint32_t intermediateFreq = InputClkFreq / currentPrescale; // 中间频率

        /* Binary finds the optimal value of Sckdiv */
        uint32_t low = sckdivMin;
        uint32_t high = sckdivMax;
        while (low <= high)
        {
            uint32_t mid = (low + high) / 2u;
            uint32_t finalFreq = intermediateFreq / mid;
            uint32_t error = (finalFreq > TargetSckFreq) ? (finalFreq - TargetSckFreq) : (TargetSckFreq - finalFreq);

            /* If the current error is smaller, update the best value */
            if (error < minError)
            {
                minError = error;
                bestPrescale = currentPrescale;
                bestSckdiv = mid;
                bestFreq = finalFreq;
            }

            /* Adjust the bounds of binary search */
            if (finalFreq > TargetSckFreq)
            {
                low = mid + 1u;
            } else {
                high = mid - 1u;
            }
        }
    }

    *Prescale = bestPrescale;
    *Sckdiv = bestSckdiv;

    return bestFreq;
}

uint32_t FCSPI_LL_CaculateClockConfigParam(uint32_t *Prescale, uint32_t *Sckdiv, uint32_t InputClkFreq, FCSPI_HandleType *pFcspiHandle)
{
    const uint32_t prescaleValues[] = {1u, 2u, 4u, 8u, 16u, 32u, 64u, 128u};
    uint32_t sckdivMax = 257u;
    uint32_t sckdivMin = 2u;

    uint32_t bestPrescale = 1u;
    uint32_t bestSckdiv = 2u;
    uint32_t bestFreq = 0u;
    uint32_t minError = 0;
    uint32_t TargetSckFreq = pFcspiHandle->Config.SckFreq;

#ifdef FCSPI_NOT_SUPPORT_CSEN_SAMPLE_2nd_EDGE
    if ((pFcspiHandle->Config.PcsContinuousEnable == true) && (pFcspiHandle->Config.SckPhase == FCSPI_SCK_SAMPLE_SECOND_EDGE))
    {
        sckdivMin = 2u;
        sckdivMax = 2u;
    }
#endif

    if ((pFcspiHandle->Config.TransferWidth == FCSPI_TRANSFER_WIDTH_4_BIT) && (pFcspiHandle->Config.FrameSize == 8u))
    {
        sckdivMin = 4u;
    }

    minError = InputClkFreq / sckdivMin;

    /* Iterate through all possible 'Prescale' values */
    for (uint8_t i = 0; i < sizeof(prescaleValues) / sizeof(prescaleValues[0]); i++)
    {
        uint32_t currentPrescale = prescaleValues[i];
        uint32_t intermediateFreq = InputClkFreq / currentPrescale;

        /* Binary finds the optimal value of Sckdiv */
        uint32_t low = sckdivMin;
        uint32_t high = sckdivMax;

        while (low <= high)
        {
            uint32_t mid = (low + high) / 2u;

            uint32_t finalFreq = intermediateFreq / mid;
            uint32_t error = (finalFreq > TargetSckFreq) ? (finalFreq - TargetSckFreq) : (TargetSckFreq - finalFreq);

            /* If the current error is smaller, update the best value */
            if (error < minError)
            {
                minError = error;
                bestPrescale = currentPrescale;
                bestSckdiv = mid;
                bestFreq = finalFreq;
            }

            /* Adjust the bounds of binary search */
            if (finalFreq > TargetSckFreq)
            {
                low = mid + 1u;
                if ((pFcspiHandle->Config.SckFeature == FCSPI_SCK_FEATURE_50_DUTY_CYCLE) &&
                    ((((low + high) / 2u) % 0x2u) != 0u))
                {
                    low++;
                }
            }
            else
            {
                high = mid - 1u;
                if ((pFcspiHandle->Config.SckFeature == FCSPI_SCK_FEATURE_50_DUTY_CYCLE) &&
                    ((((low + high) / 2u) % 0x2u) != 0u))
                {
                    high--;
                }
            }
        }
    }

    *Prescale = bestPrescale;
    *Sckdiv = bestSckdiv;

    return bestFreq;
}


static void fcspi_isr_transmit_8bit(FCSPI_HandleType *pFcspiHandle)
{
    FCSPI_Type *const pSpiBase = s_apFcspiBase[pFcspiHandle->eInstance];
    uint32_t u32TxFIFOAvailableCnt = FCSPI_TX_FIFO_DEPTH - FCSPI_HWA_GetTxFIFOCnt(pSpiBase)
                                     - FCSPI_HWA_GetRxFIFOCnt(pSpiBase);
    uint32_t u32RemainTxData = pFcspiHandle->tStatus.TxSize - pFcspiHandle->tStatus.TxCnt;

    if (u32TxFIFOAvailableCnt > u32RemainTxData)
    {
        u32TxFIFOAvailableCnt = u32RemainTxData;
    }

    for (uint32_t i = 0u; i < u32TxFIFOAvailableCnt; i++)
    {
        pSpiBase->TX_DATA = *pFcspiHandle->tStatus.TxBuff++;
    }
    (pFcspiHandle->tStatus.TxCnt) += u32TxFIFOAvailableCnt;
}

static void fcspi_isr_transmit_16bit(FCSPI_HandleType *pFcspiHandle)
{
    FCSPI_Type *const pSpiBase = s_apFcspiBase[pFcspiHandle->eInstance];
    uint32_t u32TxFIFOAvailableCnt = FCSPI_TX_FIFO_DEPTH - FCSPI_HWA_GetTxFIFOCnt(pSpiBase);
    uint32_t u32RemainTxData = pFcspiHandle->tStatus.TxSize - pFcspiHandle->tStatus.TxCnt;

    if (u32TxFIFOAvailableCnt * sizeof(uint16_t) > u32RemainTxData)
    {
        u32TxFIFOAvailableCnt = u32RemainTxData / sizeof(uint16_t);
    }

    for (uint32_t i = 0u; i < u32TxFIFOAvailableCnt; i++)
    {
        pSpiBase->TX_DATA = *(uint16_t *)pFcspiHandle->tStatus.TxBuff;
        pFcspiHandle->tStatus.TxBuff += sizeof(uint16_t);
    }
    (pFcspiHandle->tStatus.TxCnt) += u32TxFIFOAvailableCnt * sizeof(uint16_t);
}

static void fcspi_isr_transmit_32bit(FCSPI_HandleType *pFcspiHandle)
{
    FCSPI_Type *const pSpiBase = s_apFcspiBase[pFcspiHandle->eInstance];
    uint32_t u32TxFIFOAvailableCnt = FCSPI_TX_FIFO_DEPTH - FCSPI_HWA_GetTxFIFOCnt(pSpiBase);
    uint32_t u32RemainTxData = pFcspiHandle->tStatus.TxSize - pFcspiHandle->tStatus.TxCnt;

    if (u32TxFIFOAvailableCnt * sizeof(uint32_t) > u32RemainTxData)
    {
        u32TxFIFOAvailableCnt = u32RemainTxData / sizeof(uint32_t);
    }

    for (uint32_t i = 0u; i < u32TxFIFOAvailableCnt; i++)
    {
        pSpiBase->TX_DATA = *(uint32_t *)pFcspiHandle->tStatus.TxBuff;
        pFcspiHandle->tStatus.TxBuff += sizeof(uint32_t);
    }
    (pFcspiHandle->tStatus.TxCnt) += u32TxFIFOAvailableCnt * sizeof(uint32_t);
}

static void fcspi_isr_receive_8bit(FCSPI_HandleType *pFcspiHandle)
{
    FCSPI_Type *const pSpiBase = s_apFcspiBase[pFcspiHandle->eInstance];
    uint32_t u32RxFIFODataCnt = FCSPI_HWA_GetRxFIFOCnt(pSpiBase);
    uint32_t u32RemainRxData = pFcspiHandle->tStatus.RxSize - pFcspiHandle->tStatus.RxCnt;

    if (u32RxFIFODataCnt > u32RemainRxData)
    {
        u32RxFIFODataCnt = u32RemainRxData;
    }

    for (uint32_t i = 0; i < u32RxFIFODataCnt; i++)
    {
        *(pFcspiHandle->tStatus.RxBuff) = (uint8_t)pSpiBase->RX_DATA;
        (pFcspiHandle->tStatus.RxBuff)++;
    }
    (pFcspiHandle->tStatus.RxCnt) += u32RxFIFODataCnt;
}

static void fcspi_isr_receive_16bit(FCSPI_HandleType *pFcspiHandle)
{
    FCSPI_Type *const pSpiBase = s_apFcspiBase[pFcspiHandle->eInstance];
    uint32_t u32RxFIFODataCnt = FCSPI_HWA_GetRxFIFOCnt(pSpiBase);
    uint32_t u32RemainRxData = pFcspiHandle->tStatus.RxSize - pFcspiHandle->tStatus.RxCnt;

    if (u32RxFIFODataCnt * sizeof(uint16_t) > u32RemainRxData)
    {
        u32RxFIFODataCnt = u32RemainRxData / sizeof(uint16_t);
    }

    for (uint32_t i = 0; i < u32RxFIFODataCnt; i++)
    {
        *(uint16_t *)(pFcspiHandle->tStatus.RxBuff) = (uint16_t)pSpiBase->RX_DATA;
        (pFcspiHandle->tStatus.RxBuff) += sizeof(uint16_t);
    }
    (pFcspiHandle->tStatus.RxCnt) += u32RxFIFODataCnt * sizeof(uint16_t);
}



static void fcspi_isr_receive_32bit(FCSPI_HandleType *pFcspiHandle)
{
    FCSPI_Type *const pSpiBase = s_apFcspiBase[pFcspiHandle->eInstance];
    uint32_t u32RxFIFODataCnt = FCSPI_HWA_GetRxFIFOCnt(pSpiBase);
    uint32_t u32RemainRxData = pFcspiHandle->tStatus.RxSize - pFcspiHandle->tStatus.RxCnt;

    if (u32RxFIFODataCnt * sizeof(uint32_t) > u32RemainRxData)
    {
        u32RxFIFODataCnt = u32RemainRxData / sizeof(uint32_t);
    }

    for (uint32_t i = 0; i < u32RxFIFODataCnt; i++)
    {
        *(uint32_t *)(pFcspiHandle->tStatus.RxBuff) = (uint32_t)pSpiBase->RX_DATA;
        (pFcspiHandle->tStatus.RxBuff) += sizeof(uint32_t);
    }
    (pFcspiHandle->tStatus.RxCnt) += u32RxFIFODataCnt * sizeof(uint32_t);
}

static void fcspi_isr_receive_8bit_cs_no_cont(FCSPI_HandleType *pFcspiHandle)
{
    FCSPI_Type *const pSpiBase = s_apFcspiBase[pFcspiHandle->eInstance];

    if (0u != FCSPI_HWA_GetRxFIFOCnt(pSpiBase))
    {
        *(pFcspiHandle->tStatus.RxBuff) = (uint8_t)pSpiBase->RX_DATA;
        (pFcspiHandle->tStatus.RxBuff) += sizeof(uint8_t);
        (pFcspiHandle->tStatus.RxCnt) += sizeof(uint8_t);
    }

    if (0u == FCSPI_HWA_GetTxFIFOCnt(pSpiBase))
    {
        if (pFcspiHandle->tStatus.TxSize > pFcspiHandle->tStatus.TxCnt)
        {
            pSpiBase->TR_CTRL |= FCSPI_TR_CTRL_TX_MSK_MASK;
            (pFcspiHandle->tStatus.TxCnt) += sizeof(uint8_t);
        }
    }
}

static void fcspi_isr_receive_16bit_cs_no_cont(FCSPI_HandleType *pFcspiHandle)
{
    FCSPI_Type *const pSpiBase = s_apFcspiBase[pFcspiHandle->eInstance];

    if (0u != FCSPI_HWA_GetRxFIFOCnt(pSpiBase))
    {
        *(uint16_t *)(pFcspiHandle->tStatus.RxBuff) = (uint16_t)pSpiBase->RX_DATA;
        (pFcspiHandle->tStatus.RxBuff) += sizeof(uint16_t);
        (pFcspiHandle->tStatus.RxCnt) += sizeof(uint16_t);
    }

    if (0u == FCSPI_HWA_GetTxFIFOCnt(pSpiBase))
    {
        if (pFcspiHandle->tStatus.TxSize > pFcspiHandle->tStatus.TxCnt)
        {
            pSpiBase->TR_CTRL |= FCSPI_TR_CTRL_TX_MSK_MASK;
            (pFcspiHandle->tStatus.TxCnt) += sizeof(uint16_t);
        }
    }
}

static void fcspi_isr_receive_32bit_cs_no_cont(FCSPI_HandleType *pFcspiHandle)
{
    FCSPI_Type *const pSpiBase = s_apFcspiBase[pFcspiHandle->eInstance];

    if (0u != FCSPI_HWA_GetRxFIFOCnt(pSpiBase))
    {
        *(uint32_t *)(pFcspiHandle->tStatus.RxBuff) = (uint32_t)pSpiBase->RX_DATA;
        (pFcspiHandle->tStatus.RxBuff) += sizeof(uint32_t);
        (pFcspiHandle->tStatus.RxCnt) += sizeof(uint32_t);
    }

    if (0u == FCSPI_HWA_GetTxFIFOCnt(pSpiBase))
    {
        if (pFcspiHandle->tStatus.TxSize > pFcspiHandle->tStatus.TxCnt)
        {
            pSpiBase->TR_CTRL |= FCSPI_TR_CTRL_TX_MSK_MASK;
            (pFcspiHandle->tStatus.TxCnt) += sizeof(uint32_t);
        }
    }
}

static void FCSPI_LL_PcsConfig(FCSPI_HandleType *pFcspiHandle)
{
    FCSPI_Type *const pSpiBase = s_apFcspiBase[pFcspiHandle->eInstance];

    FCSPI_CLEAR_BIT(pFcspiHandle->tStatus.TR_CTRL,
    		        FCSPI_TR_CTRL_PCS_MASK);
    FCSPI_SET_BIT(pFcspiHandle->tStatus.TR_CTRL,
    		      ((uint32_t)pFcspiHandle->Config.HardwareSelect.PCSn << FCSPI_TR_CTRL_PCS_SHIFT));
    pSpiBase->TR_CTRL = pFcspiHandle->tStatus.TR_CTRL;

    FCSPI_HWA_SetPcsPolarity(pSpiBase,
                            pFcspiHandle->Config.HardwareSelect.PCSn,
                            pFcspiHandle->Config.HardwareSelect.PcsPolarity);
}

#if FCSPI_DEV_ERROR_REPORT == STD_ON
static FCSPI_StatusType FCSPI_LL_CheckInitConfiguration(FCSPI_HandleType *pFcspiHandle)
{
    FCSPI_StatusType eStat = FCSPI_STATUS_SUCCESS;

    if (NULL == pFcspiHandle)
    {
         FCSPI_ReportDevError(FCSPI_INIT_ID, FCSPI_E_PARAM_POINTER);
    }
    else if ((pFcspiHandle->Config.FrameSize < 8u) ||
             ((pFcspiHandle->Config.FrameSize & 0x1u) != 0u))
    {
        FCSPI_ReportDevError(FCSPI_INIT_ID, FCSPI_E_PARAM_CONFIG);
    }
    else if ((pFcspiHandle->Config.Mode == FCSPI_MODE_MASTER) &
             ((0u == pFcspiHandle->Config.DelayPCS2SCK) ||
              (0u == pFcspiHandle->Config.DelaySCK2PCS) ||
              (0u == pFcspiHandle->Config.DelayPCS2PCS))
            )
    {
        FCSPI_ReportDevError(FCSPI_INIT_ID, FCSPI_E_PARAM_CONFIG);
    }
    else if ((FCSPI_TRANSFER_WIDTH_1_BIT != pFcspiHandle->Config.TransferWidth) &&
             (FCSPI_SIN_INPUT_SOUT_OUTPUT != pFcspiHandle->Config.PinConfig))
    {
        FCSPI_ReportDevError(FCSPI_INIT_ID, FCSPI_E_PARAM_CONFIG);
    }
    else if ((FCSPI_MODE_SLAVE == pFcspiHandle->Config.Mode) &&
             (true == pFcspiHandle->Config.SckLoopbackEnable))
    {
        FCSPI_ReportDevError(FCSPI_INIT_ID, FCSPI_E_PARAM_CONFIG);
    }
    else if ((FCSPI_MODE_MASTER == pFcspiHandle->Config.Mode) &&
             (true == pFcspiHandle->Config.InternalPcsEnable))
    {
        FCSPI_ReportDevError(FCSPI_INIT_ID, FCSPI_E_PARAM_CONFIG);
    }
#ifdef FCSPI_NOT_SUPPORT_CSEN_SAMPLE_2nd_EDGE
    else if ((FCSPI_MODE_MASTER == pFcspiHandle->Config.Mode) &&
             (FCSPI_SCK_SAMPLE_SECOND_EDGE == pFcspiHandle->Config.SckPhase) &&
             (true == pFcspiHandle->Config.PcsContinuousEnable))
    {
        /*The hardware does not support this configuration. It is recommended to set
          PcsContinuousEnable to false and use GPIO to emulate chip select 
          instead of automatic hardware chip select. */
        FCSPI_ReportDevError(FCSPI_INIT_ID, FCSPI_E_PARAM_CONFIG);
    }
#endif
    else
    {
        ;
    }

    return eStat;
}
#endif

/* Global Function */

/**
 * @brief Initialize FCSPI based on configurations in FCSPI_HandleType
 * 
 * @param pFcspiHandle pointer to a FCSPI_HandleType structure
 * 
 * @return FCSPI_StatusType 
 */
FCSPI_StatusType FCSPI_Init(FCSPI_HandleType *pFcspiHandle)
{
    FCSPI_Type *pSpiBase = NULL;
    uint32_t u32TR_CTRL = 0u;
    uint32_t u32Prescale = 0u;
    uint32_t u32SckDiv = 0u;
    PCC_ClkSrcType eSpiClkName = PCC_CLK_FCSPI0;
    uint32_t u32SpiPccClkFreq = 0u;
    FCSPI_StatusType eStat = FCSPI_STATUS_SUCCESS;
    uint32_t u32TimeOut = 10000u;

#if FCSPI_DEV_ERROR_REPORT == STD_ON
    eStat = FCSPI_LL_CheckInitConfiguration(pFcspiHandle);

    if (FCSPI_STATUS_SUCCESS == eStat)
    {
#endif
    pSpiBase = s_apFcspiBase[pFcspiHandle->eInstance];

    /* Soft reset all registers of FCSPIn to initial value. */
    FCSPI_HWA_SoftwareReset(pSpiBase);

    if (pFcspiHandle->Config.Mode == FCSPI_MODE_MASTER)
    {
        FCSPI_HWA_SetMasterMode(pSpiBase);

        /* calculate 'prescaler' and 'sckdiv' according to 'Config.SckFreq' user configured. */
        switch ((uint32_t)pSpiBase)
        {
            #ifdef FCSPI0_BASE
            case FCSPI0_BASE:
                eSpiClkName = PCC_CLK_FCSPI0;
                break;
            #endif
            
            #ifdef FCSPI1_BASE
            case FCSPI1_BASE:
                eSpiClkName = PCC_CLK_FCSPI1;
                break;
            #endif

            #ifdef FCSPI2_BASE
            case FCSPI2_BASE:
                eSpiClkName = PCC_CLK_FCSPI2;
                break;
            #endif

            #ifdef FCSPI3_BASE
            case FCSPI3_BASE:
                eSpiClkName = PCC_CLK_FCSPI3;
                break;
            #endif

            #ifdef FCSPI4_BASE
            case FCSPI4_BASE:
                eSpiClkName = PCC_CLK_FCSPI4;
                break;
            #endif

            #ifdef FCSPI5_BASE
            case FCSPI5_BASE:
                eSpiClkName = PCC_CLK_FCSPI5;
                break;
            #endif

            #ifdef FCSPI6_BASE
            case FCSPI6_BASE:
                eSpiClkName = PCC_CLK_FCSPI6;
                break;
            #endif

            #ifdef FCSPI7_BASE
            case FCSPI7_BASE:
                eSpiClkName = PCC_CLK_FCSPI7;
                break;
            #endif
            default:
                ;
        }

        u32SpiPccClkFreq = PCC_GetPccFunctionClock(eSpiClkName);
        (void)FCSPI_LL_CaculateClockConfigParam(&u32Prescale, &u32SckDiv,
                                                u32SpiPccClkFreq, pFcspiHandle);

        FCSPI_HWA_SetSCKDIV(pSpiBase, (uint8_t)(u32SckDiv - 2u));

        uint32_t u32DelayPCS2SCK = (pFcspiHandle->Config.DelayPCS2SCK * u32SckDiv) - 1u;
        u32DelayPCS2SCK = (u32DelayPCS2SCK > 0xFFu) ? 0xFF : u32DelayPCS2SCK;
        FCSPI_HWA_SetDelayPCSSCK(pSpiBase, (uint8_t)u32DelayPCS2SCK);

        if (pFcspiHandle->Config.PcsContinuousEnable == false)
        {
            uint32_t u32DelayPCS2PCS = (pFcspiHandle->Config.DelayPCS2PCS * u32SckDiv) - 1u;
            u32DelayPCS2PCS = (u32DelayPCS2PCS > 0xFFu) ? 0xFF : u32DelayPCS2PCS;
            FCSPI_HWA_SetDelayPCSPCS(pSpiBase, (uint8_t)u32DelayPCS2PCS);
        }
        else
        {
            FCSPI_HWA_SetDelayPCSPCS(pSpiBase, (uint8_t)(u32SckDiv / 2u - 1u));
        }

        uint32_t u32DelaySCK2PCS = (pFcspiHandle->Config.DelaySCK2PCS * u32SckDiv) - 1u;
        u32DelaySCK2PCS = (u32DelaySCK2PCS > 0xFFu) ? 0xFF : u32DelaySCK2PCS;
        FCSPI_HWA_SetDelaySCKPCS(pSpiBase, (uint8_t)u32DelaySCK2PCS);

        switch (u32Prescale)
        {
            case 1u:
                u32Prescale = FCSPI_PRESCALE_DIV_1;
                break;
            case 2u:
                u32Prescale = FCSPI_PRESCALE_DIV_2;
                break;
            case 4u:
                u32Prescale = FCSPI_PRESCALE_DIV_4;
                break;
            case 8u:
                u32Prescale = FCSPI_PRESCALE_DIV_8;
                break;
            case 16u:
                u32Prescale = FCSPI_PRESCALE_DIV_16;
                break;
            case 32u:
                u32Prescale = FCSPI_PRESCALE_DIV_32;
                break;
            case 64u:
                u32Prescale = FCSPI_PRESCALE_DIV_64;
                break;
            case 128u:
                u32Prescale = FCSPI_PRESCALE_DIV_128;
                break;
            default:
                ;
        }
        u32TR_CTRL |=  u32Prescale << FCSPI_TR_CTRL_PRESCALE_SHIFT;

        FCSPI_HWA_EnableSckLoopback(pSpiBase, pFcspiHandle->Config.SckLoopbackEnable);
    }
    else /* Slave mode */
    {
        /* No need to call FCSPI_HWA_SetSlaveMode(), FCSPI_HWA_SoftwareReset() has been called before. */

        FCSPI_HWA_EnableInternalPcs(pSpiBase, pFcspiHandle->Config.InternalPcsEnable);
    }

    if (pFcspiHandle->Config.TransferWidth != FCSPI_TRANSFER_WIDTH_1_BIT)
    {
        FCSPI_HWA_SetOutputConfig(pSpiBase, FCSPI_OUTPUT_TRISTATE);
    }

    if (pFcspiHandle->Config.TransferWidth == FCSPI_TRANSFER_WIDTH_4_BIT)
    {
        FCSPI_HWA_SetPcsConfig(pSpiBase, true);
    }

    FCSPI_HWA_SetPinConfig(pSpiBase, pFcspiHandle->Config.PinConfig);
    FCSPI_HWA_SetWatermarkTx(pSpiBase, (uint8_t)(pFcspiHandle->Config.TxFifoWatermark));
    FCSPI_HWA_SetWatermarkRx(pSpiBase, (uint8_t)(pFcspiHandle->Config.RxFifoWatermark));

    if (true == pFcspiHandle->Config.ByteSwapEnable)
    {
        u32TR_CTRL |= FCSPI_TR_CTRL_BYSW_MASK;
    }

    if (FCSPI_LSB_FIRST == pFcspiHandle->Config.BitOrder)
    {
        u32TR_CTRL |= FCSPI_TR_CTRL_LSBF_MASK;
    }

    if (FCSPI_SCK_SAMPLE_SECOND_EDGE == pFcspiHandle->Config.SckPhase)
    {
        u32TR_CTRL |= FCSPI_TR_CTRL_SCK_PHA_MASK;
    }

    if (FCSPI_SCK_IDLE_HIGH == pFcspiHandle->Config.SckPolarity)
    {
        u32TR_CTRL |= FCSPI_TR_CTRL_SCK_POL_MASK;
    }

    u32TR_CTRL |= (uint32_t)pFcspiHandle->Config.TransferWidth << FCSPI_TR_CTRL_WIDTH_SHIFT;
    u32TR_CTRL |= (pFcspiHandle->Config.FrameSize - 1) & FCSPI_TR_CTRL_FRM_SZ_MASK;

    pSpiBase->TR_CTRL = u32TR_CTRL;
    pFcspiHandle->tStatus.TR_CTRL = u32TR_CTRL;


    FCSPI_HWA_EnableModule(pSpiBase, true);
    FCSPI_HWA_EnableDebugMode(pSpiBase, true);

    while((FCSPI_HWA_GetTxFIFOCnt(pSpiBase) != 0u) && (u32TimeOut != 0u))
    {
        u32TimeOut--;
        if (u32TimeOut == 0u)
        {
            eStat = FCSPI_STATUS_TIMEOUT;
        }
    }

    if (pFcspiHandle->Config.FrameSize == 8u)
    {
        pFcspiHandle->tStatus.eAccessWidth = FCSPI_DATA_ACCESS_8_BIT;
    }
    else if (pFcspiHandle->Config.FrameSize <= 16u)
    {
        pFcspiHandle->tStatus.eAccessWidth = FCSPI_DATA_ACCESS_16_BIT;
    }
    else
    {
        pFcspiHandle->tStatus.eAccessWidth = FCSPI_DATA_ACCESS_32_BIT;
    }

    pFcspiHandle->tStatus.TxBuff = NULL;
    pFcspiHandle->tStatus.TxSize = 0u;
    pFcspiHandle->tStatus.TxCnt  = 0u;
    pFcspiHandle->tStatus.RxBuff = NULL;
    pFcspiHandle->tStatus.RxSize = 0u;
    pFcspiHandle->tStatus.RxCnt  = 0u;
    pFcspiHandle->tStatus.RxIsr  = NULL;
    pFcspiHandle->tStatus.TxIsr  = NULL;

    if (eStat == FCSPI_STATUS_SUCCESS)
    {
        pFcspiHandle->tStatus.state = FCSPI_STATE_IDLE;
    }

#if FCSPI_DEV_ERROR_REPORT == STD_ON
    }
#endif

    return eStat;
}

/**
 * @brief De-init FCSPI peripheral and 'tStatus' of FCSPI_HandleType structure
 * 
 * @param pFcspiHandle pointer to a FCSPI_HandleType structure
 * 
 * @return void 
 */
void FCSPI_DeInit(FCSPI_HandleType *pFcspiHandle)
{
    FCSPI_Type *const pSpiBase = s_apFcspiBase[pFcspiHandle->eInstance];

    FCSPI_HWA_SoftwareReset(pSpiBase);

    pFcspiHandle->tStatus.eAccessWidth = FCSPI_DATA_ACCESS_8_BIT;
    pFcspiHandle->tStatus.state  = FCSPI_STATE_UNINIT;
    pFcspiHandle->tStatus.TxBuff = NULL;
    pFcspiHandle->tStatus.TxSize = 0u;
    pFcspiHandle->tStatus.TxCnt  = 0u;
    pFcspiHandle->tStatus.RxBuff = NULL;
    pFcspiHandle->tStatus.RxSize = 0u;
    pFcspiHandle->tStatus.RxCnt  = 0u;
    pFcspiHandle->tStatus.TxIsr = NULL;
    pFcspiHandle->tStatus.RxIsr = NULL;
}

/**
 * @brief Transmit data in blocking(polling) mode.
 * 
 * @param pFcspiHandle pointer to a FCSPI_HandleType structure
 * @param pData pointer to Tx data buffer.
 * @param Size Bytes count of data buffer to be transmitted.
 * 
 * @return FCSPI_StatusType 
 */
FCSPI_StatusType FCSPI_Transmit(FCSPI_HandleType *pFcspiHandle, uint8_t *pData, uint32_t Size)
{
    FCSPI_StatusType eStat = FCSPI_STATUS_SUCCESS;
    uint32_t u32TimeOut = Size * 1000u;
    FCSPI_Type *const pSpiBase = s_apFcspiBase[pFcspiHandle->eInstance];

#if FCSPI_DEV_ERROR_REPORT == STD_ON
    if (FCSPI_MODE_SLAVE == pFcspiHandle->Config.Mode)
    {
        eStat = FCSPI_STATUS_ERROR;
        FCSPI_ReportDevError(FCSPI_TRANSMIT_ID, FCSPI_E_PARAM_CONFIG);
    }
    else
    {
#endif

    if (pFcspiHandle->tStatus.state != FCSPI_STATE_IDLE)
    {
        eStat = FCSPI_STATUS_ERROR;
    }
    else 
    {
        pFcspiHandle->tStatus.state = FCSPI_STATE_BUSY_TX;
        pFcspiHandle->tStatus.TxBuff = pData;
        pFcspiHandle->tStatus.TxSize = Size;
        pFcspiHandle->tStatus.TxCnt  = 0u;
        pFcspiHandle->tStatus.RxBuff = NULL;
        pFcspiHandle->tStatus.RxSize = 0u;
        pFcspiHandle->tStatus.RxCnt  = 0u;

        /* Wait until SPI disabled
         * Note: In slave mode, module can not be disabled if PCS is active.
         *       (master is communicating with slave SPI) */
        while (FCSPI_HWA_IsEnabled(pSpiBase) == true)
        {
            FCSPI_HWA_EnableModule(pSpiBase, false);
        }
        /* After SPI disabled, then reset TxFIFO and RxFIFO */
        FCSPI_HWA_ResetTxFIFO(pSpiBase);
        FCSPI_HWA_ResetRxFIFO(pSpiBase);
        /* After reset FIFO, re-enable SPI */
        FCSPI_HWA_EnableModule(pSpiBase, true);
        FCSPI_HWA_EnableDebugMode(pSpiBase, true);

        FCSPI_HWA_ClearStatus(pSpiBase, FCSPI_STATUS_MASK);

        if (pFcspiHandle->Config.PcsMode == FCSPI_PCS_HARDWARE_SEL)
        {
            FCSPI_LL_PcsConfig(pFcspiHandle);
        }

        if (true == pFcspiHandle->Config.PcsContinuousEnable)
        {
            FCSPI_SET_BIT(pFcspiHandle->tStatus.TR_CTRL,
                          FCSPI_TR_CTRL_CT_EN_MASK |
                          FCSPI_TR_CTRL_CT_GO_MASK |
                          FCSPI_TR_CTRL_RX_MSK_MASK);

            FCSPI_CLEAR_BIT(pFcspiHandle->tStatus.TR_CTRL,
                            FCSPI_TR_CTRL_TX_MSK_MASK);
            pSpiBase->TR_CTRL = pFcspiHandle->tStatus.TR_CTRL;
        }
        else
        {
            FCSPI_SET_BIT(pFcspiHandle->tStatus.TR_CTRL,
                          FCSPI_TR_CTRL_RX_MSK_MASK);

            FCSPI_CLEAR_BIT(pFcspiHandle->tStatus.TR_CTRL,
                            FCSPI_TR_CTRL_TX_MSK_MASK);
            pSpiBase->TR_CTRL = pFcspiHandle->tStatus.TR_CTRL;
        }

        if (pFcspiHandle->tStatus.eAccessWidth == FCSPI_DATA_ACCESS_8_BIT)
        {
            while((pFcspiHandle->tStatus.TxCnt < Size) && (u32TimeOut != 0u))
            {
                if (FCSPI_HWA_GetTxFIFOCnt(pSpiBase) < FCSPI_TX_FIFO_DEPTH)
                {
                    pSpiBase->TX_DATA = *(uint8_t *)pFcspiHandle->tStatus.TxBuff;
                    (pFcspiHandle->tStatus.TxBuff)++;
                    (pFcspiHandle->tStatus.TxCnt)++;
                }
                u32TimeOut--;
            }
        }
        else if (pFcspiHandle->tStatus.eAccessWidth == FCSPI_DATA_ACCESS_16_BIT)
        {
            while((pFcspiHandle->tStatus.TxCnt < Size) && (u32TimeOut != 0u))
            {
                if (FCSPI_HWA_GetTxFIFOCnt(pSpiBase) < FCSPI_TX_FIFO_DEPTH)
                {
                    pSpiBase->TX_DATA = *(uint16_t *)pFcspiHandle->tStatus.TxBuff;
                    pFcspiHandle->tStatus.TxBuff += sizeof(uint16_t);
                    pFcspiHandle->tStatus.TxCnt  += sizeof(uint16_t);
                }
                u32TimeOut--;
            }
        }
        else
        {
            while((pFcspiHandle->tStatus.TxCnt < Size) && (u32TimeOut != 0u))
            {
                if (FCSPI_HWA_GetTxFIFOCnt(pSpiBase) < FCSPI_TX_FIFO_DEPTH)
                {
                    pSpiBase->TX_DATA = *(uint32_t *)pFcspiHandle->tStatus.TxBuff;
                    pFcspiHandle->tStatus.TxBuff += sizeof(uint32_t);
                    pFcspiHandle->tStatus.TxCnt  += sizeof(uint32_t);
                }
                u32TimeOut--;
            }
        }

        if (true == pFcspiHandle->Config.PcsContinuousEnable)
        {
            if (u32TimeOut != 0u)
            {
                u32TimeOut = 100u;

                do {
                    if ((FCSPI_HWA_GetTxFIFOCnt(pSpiBase) < FCSPI_TX_FIFO_DEPTH))
                    {
                        FCSPI_CLEAR_BIT(pFcspiHandle->tStatus.TR_CTRL,
                                        FCSPI_TR_CTRL_CT_EN_MASK | FCSPI_TR_CTRL_CT_GO_MASK);
                        pSpiBase->TR_CTRL = pFcspiHandle->tStatus.TR_CTRL;
                    }

                    u32TimeOut--;
                } while ((false == (bool)FCSPI_HWA_GetStatus(pSpiBase, FCSPI_STATUS_TCF_MASK))
                        && (u32TimeOut != 0u));
            }
        }

        /* make sure all data in Tx FIFO has been send out. */
        while((FCSPI_HWA_GetTxFIFOCnt(pSpiBase) != 0u) 
             && (u32TimeOut != 0u))
        {
            u32TimeOut--;
        }

        if (u32TimeOut == 0u)
        {
            eStat = FCSPI_STATUS_TIMEOUT;
        }

        pFcspiHandle->tStatus.state = FCSPI_STATE_IDLE;
    }

#if FCSPI_DEV_ERROR_REPORT == STD_ON
    }
#endif

    return eStat;
}

/**
 * @brief Receive data in blocking(polling) mode.
 * 
 * @param pFcspiHandle pointer to a FCSPI_HandleType structure
 * @param pRxData pointer to Rx data buffer.
 * @param Size Bytes count of data buffer.
 * 
 * @return FCSPI_StatusType 
 */
FCSPI_StatusType FCSPI_Receive(FCSPI_HandleType *pFcspiHandle, uint8_t *pRxData, uint32_t Size)
{
    FCSPI_StatusType eStat = FCSPI_STATUS_SUCCESS;
    uint32_t u32TimeOut = Size * 1000u;
    FCSPI_Type *const pSpiBase = s_apFcspiBase[pFcspiHandle->eInstance];

#if FCSPI_DEV_ERROR_REPORT == STD_ON
    if (FCSPI_MODE_SLAVE == pFcspiHandle->Config.Mode)
    {
        FCSPI_ReportDevError(FCSPI_TRANSMIT_ID, FCSPI_E_PARAM_CONFIG);
    }
    else
    {
#endif

    if (pFcspiHandle->tStatus.state != FCSPI_STATE_IDLE)
    {
        eStat = FCSPI_STATUS_ERROR;
    }
    else
    {
        pFcspiHandle->tStatus.state = FCSPI_STATE_BUSY_RX;

        /* Wait until SPI disabled
         * Note: In slave mode, module can not be disabled if PCS is active.
         *       (master is communicating with slave SPI) */
        while (FCSPI_HWA_IsEnabled(pSpiBase) == true)
        {
            FCSPI_HWA_EnableModule(pSpiBase, false);
        }
        /* After SPI disabled, then reset TxFIFO and RxFIFO */
        FCSPI_HWA_ResetTxFIFO(pSpiBase);
        FCSPI_HWA_ResetRxFIFO(pSpiBase);
        /* After reset FIFO, re-enable SPI */
        FCSPI_HWA_EnableModule(pSpiBase, true);
        FCSPI_HWA_EnableDebugMode(pSpiBase, true);

        if(pFcspiHandle->Config.PcsMode == FCSPI_PCS_HARDWARE_SEL)
        {
            FCSPI_LL_PcsConfig(pFcspiHandle);
        }

        /* Clear status flag, reset tx/rx FIFO to prepare for transmission */
        FCSPI_HWA_ClearStatus(pSpiBase, FCSPI_STATUS_MASK);

        pFcspiHandle->tStatus.TxBuff = NULL;
        pFcspiHandle->tStatus.TxSize = Size;
        pFcspiHandle->tStatus.TxCnt  = 0u;
        pFcspiHandle->tStatus.RxBuff = pRxData;
        pFcspiHandle->tStatus.RxSize = Size;
        pFcspiHandle->tStatus.RxCnt  = 0u;

        if(true == pFcspiHandle->Config.PcsContinuousEnable)
        {
            /* Enable cs continuous, clear Rx_mask, set Tx_Mask 
               After writing this TR_CTRL, SPI will send SCK out all the time until CT_EN & CT_GO is cleared. */
            FCSPI_SET_BIT(pFcspiHandle->tStatus.TR_CTRL,
                          FCSPI_TR_CTRL_CT_EN_MASK |
                          FCSPI_TR_CTRL_CT_GO_MASK |
                          FCSPI_TR_CTRL_TX_MSK_MASK);
            FCSPI_CLEAR_BIT(pFcspiHandle->tStatus.TR_CTRL,
                            FCSPI_TR_CTRL_RX_MSK_MASK);
            pSpiBase->TR_CTRL = pFcspiHandle->tStatus.TR_CTRL;

            if (pFcspiHandle->tStatus.eAccessWidth == FCSPI_DATA_ACCESS_8_BIT)
            {
                while((pFcspiHandle->tStatus.RxCnt < Size) && (u32TimeOut != 0u))
                {
                    if (FCSPI_HWA_GetRxFIFOCnt(pSpiBase) > 0u)
                    {
                        *(pFcspiHandle->tStatus.RxBuff) = (uint8_t)pSpiBase->RX_DATA;
                        (pFcspiHandle->tStatus.RxBuff)++;
                        (pFcspiHandle->tStatus.RxCnt)++;
                    }
                    u32TimeOut--;
                }
            }
            else if (pFcspiHandle->tStatus.eAccessWidth == FCSPI_DATA_ACCESS_16_BIT)
            {
                while((pFcspiHandle->tStatus.RxCnt < Size) && (u32TimeOut != 0u))
                {
                    if (FCSPI_HWA_GetRxFIFOCnt(pSpiBase) > 0u)
                    {
                        *(uint16_t *)(pFcspiHandle->tStatus.RxBuff) = (uint16_t)pSpiBase->RX_DATA;
                        (pFcspiHandle->tStatus.RxBuff) += 2;
                        (pFcspiHandle->tStatus.RxCnt)  += 2;
                    }
                    u32TimeOut--;
                }
            }
            else
            {
                while((pFcspiHandle->tStatus.RxCnt < Size) && (u32TimeOut != 0u))
                {
                    if (FCSPI_HWA_GetRxFIFOCnt(pSpiBase) > 0u)
                    {
                        *(uint32_t *)(pFcspiHandle->tStatus.RxBuff) = (uint32_t)pSpiBase->RX_DATA;
                        (pFcspiHandle->tStatus.RxBuff) += 4;
                        (pFcspiHandle->tStatus.RxCnt)  += 4;
                    }
                    u32TimeOut--;
                }
            }

            if (u32TimeOut != 0u)
            {
                /* Receive enougth Rx data, clear CT_EN/CT_GO/TX_MASK to stop sending SCK out. */
                FCSPI_CLEAR_BIT(pFcspiHandle->tStatus.TR_CTRL,
                                FCSPI_TR_CTRL_CT_EN_MASK |
                                FCSPI_TR_CTRL_CT_GO_MASK |
								FCSPI_TR_CTRL_TX_MSK_MASK);
                pSpiBase->TR_CTRL = pFcspiHandle->tStatus.TR_CTRL;
            }
            else
            {
                eStat = FCSPI_STATUS_TIMEOUT;
            }
        }
        else
        {
            /* One frame sck will be send out every time writing reg 'TRCTRL' with the 'TRCTRLvalue' */
            uint32_t  TRCTRLvalue = pFcspiHandle->tStatus.TR_CTRL | FCSPI_TR_CTRL_TX_MSK_MASK;

            if (pFcspiHandle->tStatus.eAccessWidth == FCSPI_DATA_ACCESS_8_BIT)
            {
                while((pFcspiHandle->tStatus.RxCnt < Size) &&
                      (u32TimeOut != 0u))
                {
                    if (0u != FCSPI_HWA_GetRxFIFOCnt(pSpiBase))
                    {
                        *(pFcspiHandle->tStatus.RxBuff) = (uint8_t)pSpiBase->RX_DATA;
                        (pFcspiHandle->tStatus.RxBuff) += sizeof(uint8_t);
                        (pFcspiHandle->tStatus.RxCnt) += sizeof(uint8_t);
                    }
                    
                    if (pFcspiHandle->tStatus.TxCnt < Size)
                    {
                        if (0u == FCSPI_HWA_GetTxFIFOCnt(pSpiBase))
                        {
                            pSpiBase->TR_CTRL = TRCTRLvalue;
                            (pFcspiHandle->tStatus.TxCnt) += sizeof(uint8_t);
                        }
                    }

                    u32TimeOut--;
                }
            }
            else if (pFcspiHandle->tStatus.eAccessWidth == FCSPI_DATA_ACCESS_16_BIT)
            {
                while((pFcspiHandle->tStatus.RxCnt < Size)&&
                      (u32TimeOut != 0u))
                {
                    if (0u != FCSPI_HWA_GetRxFIFOCnt(pSpiBase))
                    {
                        *(uint16_t *)(pFcspiHandle->tStatus.RxBuff) = (uint16_t)pSpiBase->RX_DATA;
                        (pFcspiHandle->tStatus.RxBuff) += sizeof(uint16_t);
                        (pFcspiHandle->tStatus.RxCnt) += sizeof(uint16_t);
                    }

                    if (pFcspiHandle->tStatus.TxCnt < Size)
                    {
                        if (0u == FCSPI_HWA_GetTxFIFOCnt(pSpiBase))
                        {
                            pSpiBase->TR_CTRL = TRCTRLvalue;
                            (pFcspiHandle->tStatus.TxCnt) += sizeof(uint16_t);
                        }
                    }

                    u32TimeOut--;
                }
            }
            else
            {
                while((pFcspiHandle->tStatus.RxCnt < Size)&&
                      (u32TimeOut != 0u))
                {
                    if (0u != FCSPI_HWA_GetRxFIFOCnt(pSpiBase))
                    {
                        *(uint32_t *)(pFcspiHandle->tStatus.RxBuff) = (uint32_t)pSpiBase->RX_DATA;
                        (pFcspiHandle->tStatus.RxBuff) += sizeof(uint32_t);
                        (pFcspiHandle->tStatus.RxCnt) += sizeof(uint32_t);
                    }

                    if (pFcspiHandle->tStatus.TxCnt < Size)
                    {
                        if (0u == FCSPI_HWA_GetTxFIFOCnt(pSpiBase))
                        {
                            pSpiBase->TR_CTRL = TRCTRLvalue;
                            (pFcspiHandle->tStatus.TxCnt) += sizeof(uint32_t);
                        }
                    }

                    u32TimeOut--;
                }
            }

            if (u32TimeOut == 0u)
            {
                eStat = FCSPI_STATUS_TIMEOUT;
            }
        }

        pFcspiHandle->tStatus.state = FCSPI_STATE_IDLE;
    }

#if FCSPI_DEV_ERROR_REPORT == STD_ON
    }
#endif

    return eStat;
}

/**
 * @brief Transmit and receive data in blocking(polling) mode.
 * 
 * @param pFcspiHandle pointer to a FCSPI_HandleType structure
 * @param pTxData pointer to Tx data buffer.
 * @param pRxData pointer to Rx data buffer.
 * @param Size Bytes count of data to be transmitted and received.
 * 
 * @return FCSPI_StatusType 
 */
FCSPI_StatusType FCSPI_TransmitReceive(FCSPI_HandleType *pFcspiHandle, uint8_t *pTxData, uint8_t *pRxData, uint32_t Size)
{
    FCSPI_StatusType eStat = FCSPI_STATUS_SUCCESS;
    uint32_t u32TimeOut = Size * 1000u;
    FCSPI_Type *const pSpiBase = s_apFcspiBase[pFcspiHandle->eInstance];

#if FCSPI_DEV_ERROR_REPORT == STD_ON
    if (FCSPI_MODE_SLAVE == pFcspiHandle->Config.Mode)
    {
        /* Blocking API shall not support slave mode. */
        FCSPI_ReportDevError(FCSPI_TRANSMITRECEIVE_ID, FCSPI_E_PARAM_CONFIG);
    }
    else if (pFcspiHandle->Config.TransferWidth != FCSPI_TRANSFER_WIDTH_1_BIT)
    {
        /* FCSPI_TransmitReceive is a full-duplex api,shall not be used in half-duplex transfer. */
        FCSPI_ReportDevError(FCSPI_TRANSMITRECEIVE_ID, FCSPI_E_PARAM_CONFIG);
    }
    else
    {
#endif

    if (pFcspiHandle->tStatus.state != FCSPI_STATE_IDLE)
    {
        eStat = FCSPI_STATUS_ERROR;
    }
    else 
    {
        pFcspiHandle->tStatus.state = FCSPI_STATE_BUSY_TX_RX;
        pFcspiHandle->tStatus.TxBuff = pTxData;
        pFcspiHandle->tStatus.TxSize = Size;
        pFcspiHandle->tStatus.TxCnt  = 0u;
        pFcspiHandle->tStatus.RxBuff = pRxData;
        pFcspiHandle->tStatus.RxSize = Size;
        pFcspiHandle->tStatus.RxCnt  = 0u;

        /* Wait until SPI disabled
         * Note: In slave mode, module can not be disabled if PCS is active.
         *       (master is communicating with slave SPI) */
        while (FCSPI_HWA_IsEnabled(pSpiBase) == true)
        {
            FCSPI_HWA_EnableModule(pSpiBase, false);
        }
        /* After SPI disabled, then reset TxFIFO and RxFIFO */
        FCSPI_HWA_ResetTxFIFO(pSpiBase);
        FCSPI_HWA_ResetRxFIFO(pSpiBase);
        /* After reset FIFO, re-enable SPI */
        FCSPI_HWA_EnableModule(pSpiBase, true);
        FCSPI_HWA_EnableDebugMode(pSpiBase, true);

        if (pFcspiHandle->Config.PcsMode == FCSPI_PCS_HARDWARE_SEL)
        {
            FCSPI_LL_PcsConfig(pFcspiHandle);
        }

        if (true == pFcspiHandle->Config.PcsContinuousEnable)
        {
            FCSPI_SET_BIT(pFcspiHandle->tStatus.TR_CTRL,
                          FCSPI_TR_CTRL_CT_EN_MASK |
                          FCSPI_TR_CTRL_CT_GO_MASK);
            FCSPI_CLEAR_BIT(pFcspiHandle->tStatus.TR_CTRL,
                            FCSPI_TR_CTRL_RX_MSK_MASK |
                            FCSPI_TR_CTRL_TX_MSK_MASK);
            pSpiBase->TR_CTRL = pFcspiHandle->tStatus.TR_CTRL;
        }

        if (pFcspiHandle->tStatus.eAccessWidth == FCSPI_DATA_ACCESS_8_BIT)
        {
            while(((pFcspiHandle->tStatus.TxCnt < Size) || (pFcspiHandle->tStatus.RxCnt < Size)) &&
                  (u32TimeOut != 0u))
            {
                uint32_t u32TxFIFOAvailableCnt = FCSPI_TX_FIFO_DEPTH - FCSPI_HWA_GetTxFIFOCnt(pSpiBase);
                uint32_t u32RemainTxData = (Size - pFcspiHandle->tStatus.TxCnt);
                if (u32TxFIFOAvailableCnt > u32RemainTxData)
                {
                    u32TxFIFOAvailableCnt = u32RemainTxData;
                }

                for (uint32_t i = 0u; i < u32TxFIFOAvailableCnt; i++)
                {
                    pSpiBase->TX_DATA = *pFcspiHandle->tStatus.TxBuff++;
                }
                (pFcspiHandle->tStatus.TxCnt) += u32TxFIFOAvailableCnt;

                uint32_t u32RxFIFODataCnt = FCSPI_HWA_GetRxFIFOCnt(pSpiBase);
                for (uint32_t i = 0; i < u32RxFIFODataCnt; i++)
                {
                    *(pFcspiHandle->tStatus.RxBuff) = (uint8_t)pSpiBase->RX_DATA;
                    (pFcspiHandle->tStatus.RxBuff)++;
                }
                (pFcspiHandle->tStatus.RxCnt) += u32RxFIFODataCnt;

                /* Used to deassert PCS when CS continuous mode,but has no effect on no-continuous mode 
                   therefore, no need to add an 'if' statement to conditionally execute this code. */
                if ((pFcspiHandle->tStatus.TxCnt == Size) &&
                    (FCSPI_HWA_GetTxFIFOCnt(pSpiBase) < FCSPI_TX_FIFO_DEPTH))
                {
                    FCSPI_CLEAR_BIT(pFcspiHandle->tStatus.TR_CTRL,
                                    FCSPI_TR_CTRL_CT_EN_MASK |
                                    FCSPI_TR_CTRL_CT_GO_MASK);
                    pSpiBase->TR_CTRL = pFcspiHandle->tStatus.TR_CTRL;
                }

                u32TimeOut--;
            }
        }
        else if (pFcspiHandle->tStatus.eAccessWidth == FCSPI_DATA_ACCESS_16_BIT)
        {
            while(((pFcspiHandle->tStatus.TxCnt < Size) || (pFcspiHandle->tStatus.RxCnt < Size)) &&
                  (u32TimeOut != 0u))
            {
                uint32_t u32TxFIFOAvailableCnt = FCSPI_TX_FIFO_DEPTH - FCSPI_HWA_GetTxFIFOCnt(pSpiBase);
                uint32_t u32RemainTxData = (Size - pFcspiHandle->tStatus.TxCnt);
                if (u32TxFIFOAvailableCnt * 2u > u32RemainTxData)
                {
                    u32TxFIFOAvailableCnt = u32RemainTxData / 2u;
                }

                for (uint32_t i = 0u; i < u32TxFIFOAvailableCnt; i++)
                {
                    pSpiBase->TX_DATA = *(uint16_t *)pFcspiHandle->tStatus.TxBuff;
                    pFcspiHandle->tStatus.TxBuff += 2;
                }
                (pFcspiHandle->tStatus.TxCnt) += u32TxFIFOAvailableCnt * 2u;

                uint32_t u32RxFIFODataCnt = FCSPI_HWA_GetRxFIFOCnt(pSpiBase);
                for (uint32_t i = 0; i < u32RxFIFODataCnt; i++)
                {
                    *(uint16_t *)(pFcspiHandle->tStatus.RxBuff) = (uint16_t)pSpiBase->RX_DATA;
                    (pFcspiHandle->tStatus.RxBuff) += 2;
                }
                (pFcspiHandle->tStatus.RxCnt) += u32RxFIFODataCnt * 2u;

                if ((pFcspiHandle->tStatus.TxCnt == Size) &&
                    (FCSPI_HWA_GetTxFIFOCnt(pSpiBase) < FCSPI_TX_FIFO_DEPTH))
                {
                    FCSPI_CLEAR_BIT(pFcspiHandle->tStatus.TR_CTRL,
                                    FCSPI_TR_CTRL_CT_EN_MASK |
                                    FCSPI_TR_CTRL_CT_GO_MASK);
                    pSpiBase->TR_CTRL = pFcspiHandle->tStatus.TR_CTRL;
                }
                u32TimeOut--;
            }
        }
        else
        {
            while(((pFcspiHandle->tStatus.TxCnt < Size) || (pFcspiHandle->tStatus.RxCnt < Size)) &&
                  (u32TimeOut != 0u))
            {
                uint32_t u32TxFIFOAvailableCnt = FCSPI_TX_FIFO_DEPTH - FCSPI_HWA_GetTxFIFOCnt(pSpiBase);
                uint32_t u32RemainTxData = (Size - pFcspiHandle->tStatus.TxCnt);
                if (u32TxFIFOAvailableCnt * 4u > u32RemainTxData)
                {
                    u32TxFIFOAvailableCnt = u32RemainTxData / 4u;
                }

                for (uint32_t i = 0u; i < u32TxFIFOAvailableCnt; i++)
                {
                    pSpiBase->TX_DATA = *(uint32_t *)pFcspiHandle->tStatus.TxBuff;
                    pFcspiHandle->tStatus.TxBuff += 4;
                }
                (pFcspiHandle->tStatus.TxCnt) += u32TxFIFOAvailableCnt * 4u;

                uint32_t u32RxFIFODataCnt = FCSPI_HWA_GetRxFIFOCnt(pSpiBase);

                for (uint32_t i = 0; i < u32RxFIFODataCnt; i++)
                {
                    *(uint32_t *)(pFcspiHandle->tStatus.RxBuff) = (uint32_t)pSpiBase->RX_DATA;
                    (pFcspiHandle->tStatus.RxBuff) += 4;
                }
                (pFcspiHandle->tStatus.RxCnt) += u32RxFIFODataCnt * 4u;

                if ((pFcspiHandle->tStatus.TxCnt == Size) &&
                    (FCSPI_HWA_GetTxFIFOCnt(pSpiBase) < FCSPI_TX_FIFO_DEPTH))
                {
                    FCSPI_CLEAR_BIT(pFcspiHandle->tStatus.TR_CTRL,
                                    FCSPI_TR_CTRL_CT_EN_MASK |
                                    FCSPI_TR_CTRL_CT_GO_MASK);
                    pSpiBase->TR_CTRL = pFcspiHandle->tStatus.TR_CTRL;
                }
                u32TimeOut--;
            }
        }

        if (u32TimeOut == 0u)
        {
            eStat = FCSPI_STATUS_TIMEOUT;
        }

        pFcspiHandle->tStatus.state = FCSPI_STATE_IDLE;
    }

#if FCSPI_DEV_ERROR_REPORT == STD_ON
    }
#endif

    return eStat;
}

/**
 * @brief Transmit data in interrupt mode(non-blocking).
 * 
 * @param pFcspiHandle pointer to a FCSPI_HandleType structure
 * @param pTxData pointer to Tx data buffer.
 * @param Size Bytes count of data buffer to be transmitted.
 * 
 * @return FCSPI_StatusType 
 */
FCSPI_StatusType FCSPI_Transmit_IT(FCSPI_HandleType *pFcspiHandle, uint8_t *pTxData, uint32_t Size)
{
    FCSPI_StatusType eStat = FCSPI_STATUS_SUCCESS;
    FCSPI_Type *const pSpiBase = s_apFcspiBase[pFcspiHandle->eInstance];

    if (pFcspiHandle->tStatus.state != FCSPI_STATE_IDLE)
    {
        eStat = FCSPI_STATUS_ERROR;
    }
    else 
    {
        pFcspiHandle->tStatus.state = FCSPI_STATE_BUSY_TX;

        pFcspiHandle->tStatus.TxBuff = pTxData;
        pFcspiHandle->tStatus.TxSize = Size;
        pFcspiHandle->tStatus.TxCnt  = 0u;
        pFcspiHandle->tStatus.RxBuff = NULL;
        pFcspiHandle->tStatus.RxSize = 0u;
        pFcspiHandle->tStatus.RxCnt  = 0u;
        pFcspiHandle->tStatus.RxIsr = NULL;
        
        /* register Tx ISR callback function */
        if (pFcspiHandle->tStatus.eAccessWidth == FCSPI_DATA_ACCESS_8_BIT)
        {
            pFcspiHandle->tStatus.TxIsr = fcspi_isr_transmit_8bit;
        }
        else if (pFcspiHandle->tStatus.eAccessWidth == FCSPI_DATA_ACCESS_16_BIT)
        {
            pFcspiHandle->tStatus.TxIsr = fcspi_isr_transmit_16bit;
        }
        else /* pFcspiHandle->tStatus.eAccessWidth == FCSPI_DATA_ACCESS_16_BIT */
        {
            pFcspiHandle->tStatus.TxIsr = fcspi_isr_transmit_32bit;
        }

        /* Wait until SPI disabled
         * Note: In slave mode, module can not be disabled if PCS is active.
         *       (master is communicating with slave SPI) */
        while (FCSPI_HWA_IsEnabled(pSpiBase) == true)
        {
            FCSPI_HWA_EnableModule(pSpiBase, false);
        }
        /* After SPI disabled, then reset TxFIFO and RxFIFO */
        FCSPI_HWA_ResetTxFIFO(pSpiBase);
        FCSPI_HWA_ResetRxFIFO(pSpiBase);
        /* After reset FIFO, re-enable SPI */
        FCSPI_HWA_EnableModule(pSpiBase, true);
        FCSPI_HWA_EnableDebugMode(pSpiBase, true);

        if (pFcspiHandle->Config.PcsMode == FCSPI_PCS_HARDWARE_SEL)
        {
            FCSPI_LL_PcsConfig(pFcspiHandle);
        }

        FCSPI_HWA_ClearStatus(pSpiBase, FCSPI_STATUS_MASK);

        if ((true == pFcspiHandle->Config.PcsContinuousEnable) &&
           (FCSPI_MODE_MASTER == pFcspiHandle->Config.Mode))
        {
            FCSPI_SET_BIT(pFcspiHandle->tStatus.TR_CTRL,
                            FCSPI_TR_CTRL_CT_EN_MASK |
                            FCSPI_TR_CTRL_CT_GO_MASK |
                            FCSPI_TR_CTRL_RX_MSK_MASK);
            FCSPI_CLEAR_BIT(pFcspiHandle->tStatus.TR_CTRL,
                            FCSPI_TR_CTRL_TX_MSK_MASK);
            pSpiBase->TR_CTRL = pFcspiHandle->tStatus.TR_CTRL;
        }
        else
        {
            FCSPI_SET_BIT(pFcspiHandle->tStatus.TR_CTRL,
                            FCSPI_TR_CTRL_RX_MSK_MASK);
            pSpiBase->TR_CTRL = pFcspiHandle->tStatus.TR_CTRL;
        }

        if (NULL != pFcspiHandle->Config.TansferStartNotification)
        {
            pFcspiHandle->Config.TansferStartNotification(pFcspiHandle);
        }

        /* Enable Tx FIFO interrupt */
        FCSPI_SET_BIT(pSpiBase->INT_EN, FCSPI_INT_EN_TFIE_MASK);
    }

    return eStat;
}

/**
 * @brief Transmit and receive data in interrupt mode(non-blocking).
 * 
 * @param pFcspiHandle pointer to a FCSPI_HandleType structure
 * @param pTxData pointer to Tx data buffer.
 * @param pRxData pointer to Rx data buffer.
 * @param Size Bytes count of data buffer to be transmitted and received.
 * 
 * @return FCSPI_StatusType 
 */
FCSPI_StatusType FCSPI_TransmitReceive_IT(FCSPI_HandleType *pFcspiHandle, uint8_t *pTxData, uint8_t *pRxData, uint32_t Size)
{
    FCSPI_StatusType eStat = FCSPI_STATUS_SUCCESS;
    FCSPI_Type *const pSpiBase = s_apFcspiBase[pFcspiHandle->eInstance];

#if FCSPI_DEV_ERROR_REPORT == STD_ON
    if (pFcspiHandle->Config.TransferWidth != FCSPI_TRANSFER_WIDTH_1_BIT)
    {
        /* FCSPI_TransmitReceive is a full-duplex api,shall not be used in half-duplex transfer. */
        FCSPI_ReportDevError(FCSPI_TRANSMITRECEIVE_ID, FCSPI_E_PARAM_CONFIG);
    }
    else
    {
#endif

    if (pFcspiHandle->tStatus.state != FCSPI_STATE_IDLE)
    {
        eStat = FCSPI_STATUS_ERROR;
    }
    else
    {
        pFcspiHandle->tStatus.state = FCSPI_STATE_BUSY_TX_RX;
        pFcspiHandle->tStatus.TxBuff = pTxData;
        pFcspiHandle->tStatus.TxSize = Size;
        pFcspiHandle->tStatus.TxCnt  = 0u;
        pFcspiHandle->tStatus.RxBuff = pRxData;
        pFcspiHandle->tStatus.RxSize = Size;
        pFcspiHandle->tStatus.RxCnt  = 0u;

        /* register Tx ISR callback function */
        if (pFcspiHandle->tStatus.eAccessWidth == FCSPI_DATA_ACCESS_8_BIT)
        {
            pFcspiHandle->tStatus.TxIsr = fcspi_isr_transmit_8bit;
            pFcspiHandle->tStatus.RxIsr = fcspi_isr_receive_8bit;
        }
        else if (pFcspiHandle->tStatus.eAccessWidth == FCSPI_DATA_ACCESS_16_BIT)
        {
            pFcspiHandle->tStatus.TxIsr = fcspi_isr_transmit_16bit;
            pFcspiHandle->tStatus.RxIsr = fcspi_isr_receive_16bit;
        }
        else /* pFcspiHandle->tStatus.eAccessWidth == FCSPI_DATA_ACCESS_16_BIT */
        {
            pFcspiHandle->tStatus.TxIsr = fcspi_isr_transmit_32bit;
            pFcspiHandle->tStatus.RxIsr = fcspi_isr_receive_32bit;
        }

        /* Wait until SPI disabled
         * Note: In slave mode, module can not be disabled if PCS is active.
         *       (master is communicating with slave SPI) */
        while (FCSPI_HWA_IsEnabled(pSpiBase) == true)
        {
            FCSPI_HWA_EnableModule(pSpiBase, false);
        }
        /* After SPI disabled, then reset TxFIFO and RxFIFO */
        FCSPI_HWA_ResetTxFIFO(pSpiBase);
        FCSPI_HWA_ResetRxFIFO(pSpiBase);
        /* After reset FIFO, re-enable SPI */
        FCSPI_HWA_EnableModule(pSpiBase, true);
        FCSPI_HWA_EnableDebugMode(pSpiBase, true);

        if (pFcspiHandle->Config.PcsMode == FCSPI_PCS_HARDWARE_SEL)
        {
            FCSPI_LL_PcsConfig(pFcspiHandle);
        }

        FCSPI_HWA_ClearStatus(pSpiBase, FCSPI_STATUS_MASK);

        /* Enable continuous mode */
        if ((pFcspiHandle->Config.PcsContinuousEnable == true) &&
            (pFcspiHandle->Config.Mode == FCSPI_MODE_MASTER))
        {
                FCSPI_SET_BIT(pFcspiHandle->tStatus.TR_CTRL,
                            FCSPI_TR_CTRL_CT_EN_MASK |
                            FCSPI_TR_CTRL_CT_GO_MASK);
                FCSPI_CLEAR_BIT(pFcspiHandle->tStatus.TR_CTRL,
                                FCSPI_TR_CTRL_TX_MSK_MASK |
                                FCSPI_TR_CTRL_RX_MSK_MASK);
                pSpiBase->TR_CTRL = pFcspiHandle->tStatus.TR_CTRL;
        }

        if (NULL != pFcspiHandle->Config.TansferStartNotification)
        {
            pFcspiHandle->Config.TansferStartNotification(pFcspiHandle);
        }

        /* Enable Tx FIFO interrupt and RX FIFO interrupt */
        FCSPI_SET_BIT(pSpiBase->INT_EN, FCSPI_INT_EN_TFIE_MASK | FCSPI_INT_EN_RFIE_MASK);
    }

#if FCSPI_DEV_ERROR_REPORT == STD_ON
    }
#endif

    return eStat;
}

/**
 * @brief Receive data in interrupt mode(non-blocking).
 * 
 * @param pFcspiHandle pointer to a FCSPI_HandleType structure
 * @param pRxData pointer to Rx data buffer.
 * @param Size Bytes count of data buffer to be received.
 * 
 * @return FCSPI_StatusType 
 */
FCSPI_StatusType FCSPI_Receive_IT(FCSPI_HandleType *pFcspiHandle, uint8_t *pRxData, uint32_t Size)
{
    FCSPI_StatusType eStat = FCSPI_STATUS_SUCCESS;
    FCSPI_Type *const pSpiBase = s_apFcspiBase[pFcspiHandle->eInstance];

#if FCSPI_DEV_ERROR_REPORT == STD_ON
    if((pFcspiHandle->Config.PcsContinuousEnable == false) &&
       (pFcspiHandle->Config.RxFifoWatermark != 0u))
    {
        /* In this API, if CS continuous mode enabled, Rx FIFO watermark must be 0 */
        FCSPI_ReportDevError(FCSPI_RECEIVE_ID, FCSPI_E_PARAM_CONFIG);
    }
    else
    {
#endif
    if (pFcspiHandle->tStatus.state != FCSPI_STATE_IDLE)
    {
        eStat = FCSPI_STATUS_ERROR;
    }
    else
    {
        pFcspiHandle->tStatus.state = FCSPI_STATE_BUSY_RX;
        pFcspiHandle->tStatus.RxBuff = pRxData;
        pFcspiHandle->tStatus.RxSize = Size;
        pFcspiHandle->tStatus.RxCnt = 0u;
        pFcspiHandle->tStatus.TxIsr = NULL;
        pFcspiHandle->tStatus.TxBuff = NULL;
        pFcspiHandle->tStatus.TxSize = Size;
        pFcspiHandle->tStatus.TxCnt = 0u;
        FCSPI_HWA_ClearStatus(pSpiBase, FCSPI_STATUS_MASK);

        /* Wait until SPI disabled
         * Note: In slave mode, module can not be disabled if PCS is active.
         *       (master is communicating with slave SPI) */
        while (FCSPI_HWA_IsEnabled(pSpiBase) == true)
        {
            FCSPI_HWA_EnableModule(pSpiBase, false);
        }
        /* After SPI disabled, then reset TxFIFO and RxFIFO */
        FCSPI_HWA_ResetTxFIFO(pSpiBase);
        FCSPI_HWA_ResetRxFIFO(pSpiBase);
        /* After reset FIFO, re-enable SPI */
        FCSPI_HWA_EnableModule(pSpiBase, true);
        FCSPI_HWA_EnableDebugMode(pSpiBase, true);

        if (pFcspiHandle->Config.PcsMode == FCSPI_PCS_HARDWARE_SEL)
        {
            FCSPI_LL_PcsConfig(pFcspiHandle);
        }

        if(NULL != pFcspiHandle->Config.TansferStartNotification)
        {
            pFcspiHandle->Config.TansferStartNotification(pFcspiHandle);
        }

        if (FCSPI_MODE_MASTER == pFcspiHandle->Config.Mode)
        {
            if (true == pFcspiHandle->Config.PcsContinuousEnable)
            {
                FCSPI_SET_BIT(pFcspiHandle->tStatus.TR_CTRL,
                              FCSPI_TR_CTRL_CT_EN_MASK |
                              FCSPI_TR_CTRL_CT_GO_MASK |
                              FCSPI_TR_CTRL_TX_MSK_MASK);
                FCSPI_CLEAR_BIT(pFcspiHandle->tStatus.TR_CTRL,
                                FCSPI_TR_CTRL_RX_MSK_MASK);
                pSpiBase->TR_CTRL = pFcspiHandle->tStatus.TR_CTRL;

                /* register Rx ISR callback function */
                if (pFcspiHandle->tStatus.eAccessWidth == FCSPI_DATA_ACCESS_8_BIT)
                {
                    pFcspiHandle->tStatus.RxIsr = fcspi_isr_receive_8bit;
                }
                else if (pFcspiHandle->tStatus.eAccessWidth == FCSPI_DATA_ACCESS_16_BIT)
                {
                    pFcspiHandle->tStatus.RxIsr = fcspi_isr_receive_16bit;
                }
                else /* pFcspiHandle->tStatus.eAccessWidth == FCSPI_DATA_ACCESS_16_BIT */
                {
                    pFcspiHandle->tStatus.RxIsr = fcspi_isr_receive_32bit;
                }  
            }
            else
            {
                /* register Rx ISR callback function */
                if (pFcspiHandle->tStatus.eAccessWidth == FCSPI_DATA_ACCESS_8_BIT)
                {
                    pFcspiHandle->tStatus.RxIsr = fcspi_isr_receive_8bit_cs_no_cont;
                    fcspi_isr_receive_8bit_cs_no_cont(pFcspiHandle);
                }
                else if (pFcspiHandle->tStatus.eAccessWidth == FCSPI_DATA_ACCESS_16_BIT)
                {
                    pFcspiHandle->tStatus.RxIsr = fcspi_isr_receive_16bit_cs_no_cont;
                    fcspi_isr_receive_16bit_cs_no_cont(pFcspiHandle);
                }
                else /* pFcspiHandle->tStatus.eAccessWidth == FCSPI_DATA_ACCESS_16_BIT */
                {
                    pFcspiHandle->tStatus.RxIsr = fcspi_isr_receive_32bit_cs_no_cont;
                    fcspi_isr_receive_32bit_cs_no_cont(pFcspiHandle);
                }  
            }
        }
        else
        {
            /* register Rx ISR callback function */
            if (pFcspiHandle->tStatus.eAccessWidth == FCSPI_DATA_ACCESS_8_BIT)
            {
                pFcspiHandle->tStatus.RxIsr = fcspi_isr_receive_8bit;
            }
            else if (pFcspiHandle->tStatus.eAccessWidth == FCSPI_DATA_ACCESS_16_BIT)
            {
                pFcspiHandle->tStatus.RxIsr = fcspi_isr_receive_16bit;
            }
            else /* pFcspiHandle->tStatus.eAccessWidth == FCSPI_DATA_ACCESS_32_BIT */
            {
                pFcspiHandle->tStatus.RxIsr = fcspi_isr_receive_32bit;
            }
        }

        /* Enable RX FIFO interrupt.
         * when CS continuous enable: set CTEN&CTGO will send sck immediately, so RXFIFO will fill up quickly.
         *                            then SPI interrupt will be triggered.
         * when CS continuous disable: 'fcspi_isr_receive_8bit_cs_no_cont' will be actively called once, in which TX mask is written.
         *                              RxFIFO will get one data,then SPI interrupt will be triggered.
         **/
        FCSPI_SET_BIT(pSpiBase->INT_EN, FCSPI_INT_EN_RFIE_MASK);
    }
#if FCSPI_DEV_ERROR_REPORT == STD_ON
    }
#endif
    return eStat;
}

/**
 * @brief Transmit data in DMA mode(non-blocking).
 * 
 * @param pFcspiHandle pointer to a FCSPI_HandleType structure
 * @param pTxData pointer to Tx data buffer.
 * @param Size Bytes count of data buffer to be transmitted.
 * 
 * @return FCSPI_StatusType 
 */
FCSPI_StatusType FCSPI_Transmit_DMA(FCSPI_HandleType *pFcspiHandle, uint8_t *pTxData, uint32_t Size)
{
    FCSPI_StatusType eStat = FCSPI_STATUS_SUCCESS;
    FCSPI_Type *const pSpiBase = s_apFcspiBase[pFcspiHandle->eInstance];

    if (pFcspiHandle->tStatus.state != FCSPI_STATE_IDLE)
    {
        eStat = FCSPI_STATUS_ERROR;
    }
    else 
    {
        pFcspiHandle->tStatus.state = FCSPI_STATE_BUSY_TX;
        pFcspiHandle->tStatus.TxBuff = pTxData;
        pFcspiHandle->tStatus.TxSize = Size;
        pFcspiHandle->tStatus.TxCnt  = 0u;
        pFcspiHandle->tStatus.RxBuff = NULL;
        pFcspiHandle->tStatus.RxSize = 0u;
        pFcspiHandle->tStatus.RxCnt  = 0u;
        pFcspiHandle->tStatus.TxIsr = NULL;
        pFcspiHandle->tStatus.RxIsr = NULL;

        /* Wait until SPI disabled
         * Note: In slave mode, module can not be disabled if PCS is active.
         *       (master is communicating with slave SPI) */
        while (FCSPI_HWA_IsEnabled(pSpiBase) == true)
        {
            FCSPI_HWA_EnableModule(pSpiBase, false);
        }
        /* After SPI disabled, then reset TxFIFO and RxFIFO */
        FCSPI_HWA_ResetTxFIFO(pSpiBase);
        FCSPI_HWA_ResetRxFIFO(pSpiBase);
        /* After reset FIFO, re-enable SPI */
        FCSPI_HWA_EnableModule(pSpiBase, true);
        FCSPI_HWA_EnableDebugMode(pSpiBase, true);

        if (pFcspiHandle->Config.PcsMode == FCSPI_PCS_HARDWARE_SEL)
        {
            FCSPI_LL_PcsConfig(pFcspiHandle);
        }
#if FCSPI_DEV_ERROR_REPORT == STD_ON
//判断FIFO中断有没有打开
#endif

        FCSPI_HWA_ClearStatus(pSpiBase, FCSPI_STATUS_MASK);

        if ((true == pFcspiHandle->Config.PcsContinuousEnable) &&
            (FCSPI_MODE_MASTER == pFcspiHandle->Config.Mode))
        {
                FCSPI_SET_BIT(pFcspiHandle->tStatus.TR_CTRL,
                              FCSPI_TR_CTRL_CT_EN_MASK |
                              FCSPI_TR_CTRL_CT_GO_MASK |
                              FCSPI_TR_CTRL_RX_MSK_MASK);
                FCSPI_CLEAR_BIT(pFcspiHandle->tStatus.TR_CTRL,
                                FCSPI_TR_CTRL_TX_MSK_MASK);
                pSpiBase->TR_CTRL = pFcspiHandle->tStatus.TR_CTRL;
        }
        else
        {
                FCSPI_SET_BIT(pFcspiHandle->tStatus.TR_CTRL,
                              FCSPI_TR_CTRL_RX_MSK_MASK);
                FCSPI_CLEAR_BIT(pFcspiHandle->tStatus.TR_CTRL,
                                FCSPI_TR_CTRL_TX_MSK_MASK);
                pSpiBase->TR_CTRL = pFcspiHandle->tStatus.TR_CTRL;
        }

        if (NULL != pFcspiHandle->Config.TansferStartNotification)
        {
            pFcspiHandle->Config.TansferStartNotification(pFcspiHandle);
        }

        /* Enable Tx FIFO DMA request for FCSPIn */
        FCSPI_HWA_EnableTxDMA(pSpiBase, true);
    }

    return eStat;
}

/**
 * @brief Transmit and receive data in DMA mode(non-blocking).
 * 
 * @param pFcspiHandle pointer to a FCSPI_HandleType structure
 * @param pTxData pointer to Tx data buffer.
 * @param pRxData pointer to Rx data buffer.
 * @param Size Bytes count of data buffer to be transmitted and received.
 * 
 * @return FCSPI_StatusType 
 */
FCSPI_StatusType FCSPI_TransmitReceive_DMA(FCSPI_HandleType *pFcspiHandle, uint8_t *pTxData, uint8_t *pRxData, uint32_t Size)
{
    FCSPI_StatusType eStat = FCSPI_STATUS_SUCCESS;
    FCSPI_Type *const pSpiBase = s_apFcspiBase[pFcspiHandle->eInstance];

#if FCSPI_DEV_ERROR_REPORT == STD_ON
    if (pFcspiHandle->Config.TransferWidth != FCSPI_TRANSFER_WIDTH_1_BIT)
    {
        /* FCSPI_TransmitReceive_DMA is a full-duplex API, shall not be used in half-duplex transfer. */
        FCSPI_ReportDevError(FCSPI_TRANSMITRECEIVE_DMA_ID, FCSPI_E_PARAM_CONFIG);
    }
    else if (pFcspiHandle->Config.RxFifoWatermark != 0u)
    {
        /* DMA mode, Rx FIFO water mark must be 0,otherwise several date will be remained in RX FIFO */
        FCSPI_ReportDevError(FCSPI_RECEIVE_ID, FCSPI_E_PARAM_CONFIG);
    }
    else
    {
#endif

    if (pFcspiHandle->tStatus.state != FCSPI_STATE_IDLE)
    {
        eStat = FCSPI_STATUS_ERROR;
    }
    else
    {
        pFcspiHandle->tStatus.state = FCSPI_STATE_BUSY_TX_RX;
        pFcspiHandle->tStatus.TxBuff = pTxData;
        pFcspiHandle->tStatus.TxSize = Size;
        pFcspiHandle->tStatus.TxCnt  = 0u;
        pFcspiHandle->tStatus.RxBuff = pRxData;
        pFcspiHandle->tStatus.RxSize = Size;
        pFcspiHandle->tStatus.RxCnt  = 0u;
        pFcspiHandle->tStatus.TxIsr = NULL;
        pFcspiHandle->tStatus.RxIsr = NULL;


        /* Wait until SPI disabled
         * Note: In slave mode, module can not be disabled if PCS is active.
         *       (master is communicating with slave SPI) */
        while (FCSPI_HWA_IsEnabled(pSpiBase) == true)
        {
            FCSPI_HWA_EnableModule(pSpiBase, false);
        }
        /* After SPI disabled, then reset TxFIFO and RxFIFO */
        FCSPI_HWA_ResetTxFIFO(pSpiBase);
        FCSPI_HWA_ResetRxFIFO(pSpiBase);
        /* After reset FIFO, re-enable SPI */
        FCSPI_HWA_EnableModule(pSpiBase, true);
        FCSPI_HWA_EnableDebugMode(pSpiBase, true);

        if (pFcspiHandle->Config.PcsMode == FCSPI_PCS_HARDWARE_SEL)
        {
            FCSPI_LL_PcsConfig(pFcspiHandle);
        }

        FCSPI_HWA_ClearStatus(pSpiBase, FCSPI_STATUS_MASK);

        if ((true == pFcspiHandle->Config.PcsContinuousEnable) &&
            (FCSPI_MODE_MASTER == pFcspiHandle->Config.Mode))
        {
                FCSPI_SET_BIT(pFcspiHandle->tStatus.TR_CTRL,
                              FCSPI_TR_CTRL_CT_EN_MASK |
                              FCSPI_TR_CTRL_CT_GO_MASK);
                FCSPI_CLEAR_BIT(pFcspiHandle->tStatus.TR_CTRL,
                                FCSPI_TR_CTRL_TX_MSK_MASK |
                                FCSPI_TR_CTRL_RX_MSK_MASK);
                pSpiBase->TR_CTRL = pFcspiHandle->tStatus.TR_CTRL;
        }

        if (NULL != pFcspiHandle->Config.TansferStartNotification)
        {
            pFcspiHandle->Config.TansferStartNotification(pFcspiHandle);
        }

        /* Enable Tx FIFO DMA request for FCSPIn */
        FCSPI_HWA_EnableTxDMA(pSpiBase, true);
        FCSPI_HWA_EnableRxDMA(pSpiBase, true);
    }

#if FCSPI_DEV_ERROR_REPORT == STD_ON
    }
#endif

    return eStat;
}

/**
 * @brief Receive data in DMA mode(non-blocking).
 * 
 * @param pFcspiHandle pointer to a FCSPI_HandleType structure
 * @param pRxData pointer to Rx data buffer.
 * @param Size Bytes count of data buffer to be received.
 * 
 * @return FCSPI_StatusType 
 */
FCSPI_StatusType FCSPI_Receive_DMA(FCSPI_HandleType *pFcspiHandle, uint8_t *pRxData, uint32_t Size)
{
    FCSPI_StatusType eStat = FCSPI_STATUS_SUCCESS;
    FCSPI_Type *const pSpiBase = s_apFcspiBase[pFcspiHandle->eInstance];

#if FCSPI_DEV_ERROR_REPORT == STD_ON
    if ((pFcspiHandle->Config.PcsContinuousEnable != true) && 
        (FCSPI_MODE_MASTER == pFcspiHandle->Config.Mode))
    {
        /* Master and DMA mode， must enable PCS continuous */
        FCSPI_ReportDevError(FCSPI_RECEIVE_ID, FCSPI_E_PARAM_CONFIG);
    }
    else if (pFcspiHandle->Config.RxFifoWatermark != 0u)
    {
        /* DMA mode, Rx FIFO water mark must be 0,otherwise several date will be remained in RX FIFO */
        FCSPI_ReportDevError(FCSPI_RECEIVE_ID, FCSPI_E_PARAM_CONFIG);
    }
    else
    {
#endif

    if (pFcspiHandle->tStatus.state != FCSPI_STATE_IDLE)
    {
        eStat = FCSPI_STATUS_ERROR;
    }
    else
    {
        pFcspiHandle->tStatus.state = FCSPI_STATE_BUSY_RX;
        pFcspiHandle->tStatus.TxBuff = NULL;
        pFcspiHandle->tStatus.TxSize = 0u;
        pFcspiHandle->tStatus.TxCnt  = 0u;
        pFcspiHandle->tStatus.RxBuff = pRxData;
        pFcspiHandle->tStatus.RxSize = Size;
        pFcspiHandle->tStatus.RxCnt  = 0u;
        pFcspiHandle->tStatus.TxIsr = NULL;
        pFcspiHandle->tStatus.RxIsr = NULL;

        /* Wait until SPI disabled
         * Note: In slave mode, module can not be disabled if PCS is active.
         *       (master is communicating with slave SPI) */
        while (FCSPI_HWA_IsEnabled(pSpiBase) == true)
        {
            FCSPI_HWA_EnableModule(pSpiBase, false);
        }
        /* After SPI disabled, then reset TxFIFO and RxFIFO */
        FCSPI_HWA_ResetTxFIFO(pSpiBase);
        FCSPI_HWA_ResetRxFIFO(pSpiBase);
        /* After reset FIFO, re-enable SPI */
        FCSPI_HWA_EnableModule(pSpiBase, true);
        FCSPI_HWA_EnableDebugMode(pSpiBase, true);

        if (pFcspiHandle->Config.PcsMode == FCSPI_PCS_HARDWARE_SEL)
        {
            FCSPI_LL_PcsConfig(pFcspiHandle);
        }

        FCSPI_HWA_ClearStatus(pSpiBase, FCSPI_STATUS_MASK);

        if (NULL != pFcspiHandle->Config.TansferStartNotification)
        {
            pFcspiHandle->Config.TansferStartNotification(pFcspiHandle);
        }

        if (FCSPI_MODE_MASTER == pFcspiHandle->Config.Mode)
        {
            FCSPI_SET_BIT(pFcspiHandle->tStatus.TR_CTRL,
                            FCSPI_TR_CTRL_CT_EN_MASK |
                            FCSPI_TR_CTRL_CT_GO_MASK |
                            FCSPI_TR_CTRL_TX_MSK_MASK);
            FCSPI_CLEAR_BIT(pFcspiHandle->tStatus.TR_CTRL,
                            FCSPI_TR_CTRL_RX_MSK_MASK);
            pSpiBase->TR_CTRL = pFcspiHandle->tStatus.TR_CTRL;
        }
        else
        {
            FCSPI_SET_BIT(pFcspiHandle->tStatus.TR_CTRL,
                            FCSPI_TR_CTRL_TX_MSK_MASK);
            FCSPI_CLEAR_BIT(pFcspiHandle->tStatus.TR_CTRL,
                            FCSPI_TR_CTRL_RX_MSK_MASK);
            pSpiBase->TR_CTRL = pFcspiHandle->tStatus.TR_CTRL;
        }

        /* Enable Rx FIFO DMA request for FCSPIn */
        FCSPI_HWA_EnableRxDMA(pSpiBase, true);
    }

#if FCSPI_DEV_ERROR_REPORT == STD_ON
    }
#endif

    return eStat;
}

/**
 * @brief The internal interrupt handler function for FCSPI instances.
 * 
 * @param pFcspiHandle pointer to a FCSPI_HandleType structure
 */
void FCSPIn_IRQHandler(FCSPI_HandleType *pFcspiHandle)
{
    FCSPI_Type *const pSpiBase = s_apFcspiBase[pFcspiHandle->eInstance];

    if (NULL != pFcspiHandle->tStatus.RxIsr)
    {
        pFcspiHandle->tStatus.RxIsr(pFcspiHandle);

        /* All data has been read from RxFIFO, Disable RxFIFO interrupt */
        if (pFcspiHandle->tStatus.RxCnt == pFcspiHandle->tStatus.RxSize)
        {
            FCSPI_CLEAR_BIT(pSpiBase->INT_EN, FCSPI_INT_EN_RFIE_MASK);

            /* Used for FCSPI_TransmitReceive_IT(), has no affect on FCSPI_Receive_IT().
               Consider consituation that don't disable Tx interrupt here: Rx done then call TansferEndNotification,
               then Tx FIFO empty will trigger another interrupt,
               in this interrupt's FCSPIn_IRQHandler, TxFIFO empty,then disable Tx interrupt, and TansferEndNotification
               will be called again.
               Disable Tx interrupt here can avoid TxFIFO empty to call another SPI interrupt,
               in which no data be send or get but 'TansferEndNotification' will be wrongly called again. */
            FCSPI_CLEAR_BIT(pSpiBase->INT_EN, FCSPI_INT_EN_TFIE_MASK);
            FCSPI_HWA_ClearStatus(pSpiBase, FCSPI_STATUS_RX_FF_MASK);

            /* The previous interrupt might have set the RX Watermark to 0, so the original Watermark is restored 
               here to prevent it from affecting subsequent transmissions. */
            FCSPI_HWA_SetWatermarkRx(pSpiBase, (uint8_t)(pFcspiHandle->Config.RxFifoWatermark));

            /* Use for FCSPI_Receive_IT(), has no affect on FCSPI_TransmitReceive_IT().
               must clear CT_EN and TX mask simultaneously,otherwise there will be
               unexpected frame wave after PCS deassert. */
            FCSPI_CLEAR_BIT(pFcspiHandle->tStatus.TR_CTRL,
                            FCSPI_TR_CTRL_CT_EN_MASK |
                            FCSPI_TR_CTRL_CT_GO_MASK |
                            FCSPI_TR_CTRL_TX_MSK_MASK);
            pSpiBase->TR_CTRL = pFcspiHandle->tStatus.TR_CTRL;

            if ((FCSPI_STATE_BUSY_RX == pFcspiHandle->tStatus.state) ||
                (FCSPI_STATE_BUSY_TX_RX == pFcspiHandle->tStatus.state))
            {
                pFcspiHandle->tStatus.state = FCSPI_STATE_IDLE;

                if(NULL != pFcspiHandle->Config.TansferEndNotification)
                {
                    pFcspiHandle->Config.TansferEndNotification(pFcspiHandle);
                }
            }
        }
        else if((pFcspiHandle->tStatus.RxSize - pFcspiHandle->tStatus.RxCnt) > pFcspiHandle->Config.RxFifoWatermark)
        {
            /* There is still data in the RX FIFO, but the amount is less than the RX FIFO Watermark,
               so no further interrupt will be triggered. The RX FIFO Watermark must be set to 0 to 
               trigger the interrupt again and read the remaining data in ISR. */
            FCSPI_HWA_SetWatermarkRx(pSpiBase, 0u);
        }
        else
        {

        }
    }

    if (NULL != pFcspiHandle->tStatus.TxIsr)
    {
        pFcspiHandle->tStatus.TxIsr(pFcspiHandle);
        /* All data has been write into TxFIFO, and all data in Tx FIFO has been shift out */
        if (pFcspiHandle->tStatus.TxCnt == pFcspiHandle->tStatus.TxSize)
        {
            if (FCSPI_HWA_GetTxFIFOCnt(pSpiBase) < FCSPI_TX_FIFO_DEPTH)
            {
            	if ((pFcspiHandle->tStatus.TR_CTRL & FCSPI_TR_CTRL_CT_EN_MASK) != 0u)
            	{
                    /* Clear CT_EN,CT_GO to end CS continuous mode */
                    FCSPI_CLEAR_BIT(pFcspiHandle->tStatus.TR_CTRL,
                                    FCSPI_TR_CTRL_CT_EN_MASK |
                                    FCSPI_TR_CTRL_CT_GO_MASK |
                                    FCSPI_TR_CTRL_TX_MSK_MASK |
                                    FCSPI_TR_CTRL_RX_MSK_MASK);
                    pSpiBase->TR_CTRL = pFcspiHandle->tStatus.TR_CTRL;
            	}

                if (0u == FCSPI_HWA_GetTxFIFOCnt(pSpiBase))
                {
                    FCSPI_CLEAR_BIT(pSpiBase->INT_EN, FCSPI_INT_EN_TFIE_MASK);
                    FCSPI_HWA_ClearStatus(pSpiBase, FCSPI_STATUS_TX_FF_MASK);

                    if (FCSPI_STATE_BUSY_TX == pFcspiHandle->tStatus.state)
                    {
                        pFcspiHandle->tStatus.state = FCSPI_STATE_IDLE;

                        if(NULL != pFcspiHandle->Config.TansferEndNotification)
                        {
                            pFcspiHandle->Config.TansferEndNotification(pFcspiHandle);
                        }
                    }
                }
            }
        }
    }
}

/**
 * @brief FCSPI callback  of DMA channel triggered by Tx FIFO.
 * 
 * @param pFcspiHandle pointer to a FCSPI_HandleType structure
 */
void FCSPIn_DmaDoneCallback_Tx(void *pFcspiHandler)
{
    FCSPI_HandleType *pFcspiHandle = (FCSPI_HandleType *)pFcspiHandler;
    uint32_t u32Timeout = 10000u;
    FCSPI_Type *const pSpiBase = s_apFcspiBase[pFcspiHandle->eInstance];

    /* Disable SPI DMA request of TX FIFO after SPI DMA Tx done,  */
    FCSPI_HWA_EnableTxDMA(pSpiBase, false);

    while (u32Timeout-- != 0)
    {
        if ((FCSPI_HWA_GetTxFIFOCnt(pSpiBase) < FCSPI_TX_FIFO_DEPTH))
        {
            FCSPI_CLEAR_BIT(pFcspiHandle->tStatus.TR_CTRL,
                            FCSPI_TR_CTRL_CT_EN_MASK | FCSPI_TR_CTRL_CT_GO_MASK);
            pSpiBase->TR_CTRL = pFcspiHandle->tStatus.TR_CTRL;

            if (FCSPI_STATE_BUSY_TX == pFcspiHandle->tStatus.state)
            {
                pFcspiHandle->tStatus.state = FCSPI_STATE_IDLE;

                if (NULL != pFcspiHandle->Config.TansferEndNotification)
                {
                    pFcspiHandle->Config.TansferEndNotification(pFcspiHandle);
                }
            }

            break;
        }
    }
}

/**
 * @brief FCSPI callback of DMA channel triggered by Rx FIFO.
 * 
 * @param pFcspiHandle pointer to a FCSPI_HandleType structure
 */
void FCSPIn_DmaDoneCallback_Rx(void *pFcspiHandler)
{
    FCSPI_HandleType *pFcspiHandle = (FCSPI_HandleType *)pFcspiHandler;
    FCSPI_Type *const pSpiBase = s_apFcspiBase[pFcspiHandle->eInstance];
    /* SPI DMA Rx done, disable SPI DMA request of RX FIFO */

    FCSPI_CLEAR_BIT(pFcspiHandle->tStatus.TR_CTRL,
                    FCSPI_TR_CTRL_CT_EN_MASK |
                    FCSPI_TR_CTRL_CT_GO_MASK |
                    FCSPI_TR_CTRL_TX_MSK_MASK);
    pSpiBase->TR_CTRL = pFcspiHandle->tStatus.TR_CTRL;

    FCSPI_HWA_ResetRxFIFO(pSpiBase);

    FCSPI_HWA_EnableRxDMA(pSpiBase, false);

    if ((FCSPI_STATE_BUSY_RX == pFcspiHandle->tStatus.state) ||
        (FCSPI_STATE_BUSY_TX_RX == pFcspiHandle->tStatus.state))
    {
        pFcspiHandle->tStatus.state = FCSPI_STATE_IDLE;

        if (NULL != pFcspiHandle->Config.TansferEndNotification)
        {
            pFcspiHandle->Config.TansferEndNotification(pFcspiHandle);
        }
    }
}

#endif /* #if FCSPI_INSTANCE_COUNT > 0U */

