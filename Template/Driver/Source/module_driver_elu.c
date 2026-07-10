/**
 * @file module_driver_lu.c
 * @author Flagchip032
 * @brief LU driver source code
 * @version 2.0.0
 * @date 2024-11-10
 *
 * SDK Version: 2.6.0
 *

 * @copyright Copyright (c) 2024 Flagchip Semiconductors Co., Ltd.
 *
 * @details
 */
/********************************************************************************
*  Revision History:

*   Version     Date          Initials      CR#          Descriptions
*   ---------   ----------    ------------  ----------   ---------------
*   2.0.0       2024-04-20    Flagchip032   N/A          First version
*   2.4.0       2025-07-14    Flagchip0103  N/A          Add support for DU
*********************************************************************************/

#include "module_driver_elu.h"

#if ELU_INSTANCE_COUNT > 0U


static LU_Type *const p_LUTables[ELU_INSTANCE_COUNT] = LU_BASE_PTRS;

#ifndef LU_DEV_ERROR_REPORT
    #define LU_DEV_ERROR_REPORT    STD_ON
#endif

#if LU_DEV_ERROR_REPORT == STD_ON
    #define LU_ReportDevError(func, error)     ReportDevError(LU_MODULE_ID, func, error)
#endif

/**
 * @brief Initialize Lu instance
 *
 * @param pInitStruct Lu initialization structure
 *
 * @return LU return type
 */
LU_StatusType LU_Init(LU_HandleType *pLuHandler, const LU_ConfigType *const pInitStruct)
{
    LU_StatusType eRet = LU_STATUS_SUCCESS;
    uint32_t u32LgIndex;
    LU_LG_Type eLg;
    LU_InstanceType eInstance = pLuHandler->eInstance;

#if LU_DEV_ERROR_REPORT == STD_ON
    if (eInstance >= ELU_INSTANCE_COUNT)
    {
        LU_ReportDevError(LU_INIT_ID, LU_E_PARAM_INSTANCE);
    }
    else if (pInitStruct == NULL)
    {
        LU_ReportDevError(LU_INIT_ID, LU_E_PARAM_NULLPTR);
    }
    else
    {
#endif
        LU_Type *const p_LU = p_LUTables[eInstance];
        uint32_t u32TempCfg = 0U;
        if (NULL == pInitStruct)
        {
            eRet = LU_STATUS_PARAM_INVALID;
        }
        else
        {
            /* Lg Configuration*/
            for(u32LgIndex=0; u32LgIndex < LG_CNT; u32LgIndex++)
            {
                eLg = (LU_LG_Type)u32LgIndex;

                /* set CTRL value */
                LU_HWA_ConfigCtrl(p_LU, eLg, pInitStruct->eLuClockPreScaler);

                /* set LUT0 value */
                LU_HWA_SetConfigCfgLut0(p_LU, eLg, pInitStruct->tLgCfg[u32LgIndex].u16LUT0Position);

                /* set LUT1 value */
                LU_HWA_SetConfigCfgLut1(p_LU, eLg, pInitStruct->tLgCfg[u32LgIndex].u16LUT1Position);

                /* bypass mode */
                LU_HWA_SetLgBypassControl(p_LU, eLg, pInitStruct->tLgCfg[u32LgIndex].eLutMode);

                /* set Flip-Flop mode configure */
                LU_HWA_SetLgFlipFlopMode(p_LU, eLg, pInitStruct->tLgCfg[u32LgIndex].eFFMode);

                if(true == pInitStruct->tLgCfg[u32LgIndex].bEnableInterrupt)
                {
                    LU_HWA_ConfigIntSel(p_LU, eLg);
                    pLuHandler->Lu_Status.pLgInterruptCallback[u32LgIndex] = pInitStruct->tLgCfg[u32LgIndex].pLgInterruptCallback;
                }

                if(true == pInitStruct->tLgCfg[u32LgIndex].bGenerateDMARequest)
                {
                    LU_HWA_ConfigDmaSel(p_LU, eLg);
                }

                /* set LG input source */
                LU_HWA_ConfigInuptSelToA(p_LU,eLg,pInitStruct->tLgCfg[u32LgIndex].tLgInputConfig.eInACfg);
                LU_HWA_ConfigInuptSelToB(p_LU,eLg,pInitStruct->tLgCfg[u32LgIndex].tLgInputConfig.eInBCfg);
                LU_HWA_ConfigInuptSelToC(p_LU,eLg,pInitStruct->tLgCfg[u32LgIndex].tLgInputConfig.eInCCfg);
                LU_HWA_ConfigInuptSelToD(p_LU,eLg,pInitStruct->tLgCfg[u32LgIndex].tLgInputConfig.eInDCfg);

                /* set FILT value */
                LU_HWA_SetLUT0InputFilterSampleCount(p_LU, eLg,pInitStruct->tLgCfg[u32LgIndex].u8Lut0FiltCnt);
                LU_HWA_SetLUT0InputFilterSamplePeriod(p_LU, eLg,pInitStruct->tLgCfg[u32LgIndex].u8Lut0Period);
                LU_HWA_SetLUT1InputFilterSampleCount(p_LU, eLg,pInitStruct->tLgCfg[u32LgIndex].u8Lut1FiltCnt);
                LU_HWA_SetLUT1InputFilterSamplePeriod(p_LU, eLg,pInitStruct->tLgCfg[u32LgIndex].u8Lut1Period);

                u32TempCfg = 0U;
                if (pInitStruct->tLgCfg[u32LgIndex].tSyncCtrl.bInputASync)
                {
                    u32TempCfg |= LU_SYNC_CONTROL_INPUT_N(LU_INPUT_N_A, 1U);
                }
                if (pInitStruct->tLgCfg[u32LgIndex].tSyncCtrl.bInputBSync)
                {
                    u32TempCfg |= LU_SYNC_CONTROL_INPUT_N(LU_INPUT_N_B, 1U);
                }
                if (pInitStruct->tLgCfg[u32LgIndex].tSyncCtrl.bInputCSync)
                {
                    u32TempCfg |= LU_SYNC_CONTROL_INPUT_N(LU_INPUT_N_C, 1U);
                }
                if (pInitStruct->tLgCfg[u32LgIndex].tSyncCtrl.bInputDSync)
                {
                    u32TempCfg |= LU_SYNC_CONTROL_INPUT_N(LU_INPUT_N_D, 1U);
                }
                /* set LG inputs synchronous control */
                LU_HWA_SetLgInputsSyncCtrl(p_LU, eLg, u32TempCfg);

                if (LU_JKFF_MODE == pInitStruct->tLgCfg[u32LgIndex].eFFMode)
                {
                    /* set LG output feedback override control */
                    LU_HWA_SetLgFeedbackOverrideCtrl(p_LU, eLg, pInitStruct->tLgCfg[u32LgIndex].eFbMode);
                }
                if (LU_OUTPUT_INIT_DISABLE > pInitStruct->tLgCfg[u32LgIndex].eFFInitValue)
                {
                    if (LU_OUTPUT_INIT_ONE == pInitStruct->tLgCfg[u32LgIndex].eFFInitValue)
                    {
                        /* Configure the output of flip-flop as "1" */
                        LU_HWA_ConfigFlipFlopTo1(p_LU, eLg);
                    }
                    else
                    {
                        /* Configure the output of flip-flop as "0" */
                        LU_HWA_ConfigFlipFlopTo0(p_LU, eLg);
                    }
                    /* Flip-Flop initial output enable control */
                    LU_HWA_EnableControlFlipFlopInitOutput(p_LU, eLg);
                }
            }

            /* DU Configuration*/
            if(LU_OPC_NONE != pInitStruct->tDuCfg.eDuOperationCode)
            {
                switch(pInitStruct->tDuCfg.eDuOperationCode)
                {
                    case LU_OPC_INCR:
                        LU_HWA_SetLuDuData0(p_LU,pInitStruct->tDuCfg.DU_OperationCfg.tINCR_Cfg.u32InitialVal);
                        LU_HWA_SetLuDuData1(p_LU,pInitStruct->tDuCfg.DU_OperationCfg.tINCR_Cfg.u32FinalVal);
                        LU_HWA_ConfigDuCtrlCapture(p_LU,pInitStruct->tDuCfg.DU_OperationCfg.tINCR_Cfg.eCaptureEdge);
                        break;

                    case LU_OPC_DECR:
                        LU_HWA_SetLuDuData0(p_LU,pInitStruct->tDuCfg.DU_OperationCfg.tDECR_Cfg.u32InitialVal);
                        LU_HWA_ConfigDuCtrlCapture(p_LU,pInitStruct->tDuCfg.DU_OperationCfg.tDECR_Cfg.eCaptureEdge);
                        break;

                    case LU_OPC_INCR_WRAP:
                        LU_HWA_SetLuDuData0(p_LU,pInitStruct->tDuCfg.DU_OperationCfg.tINCR_WRAP_Cfg.u32InitialVal);
                        LU_HWA_SetLuDuData1(p_LU,pInitStruct->tDuCfg.DU_OperationCfg.tINCR_WRAP_Cfg.u32FinalVal);
                        LU_HWA_ConfigDuCtrlCapture(p_LU,pInitStruct->tDuCfg.DU_OperationCfg.tINCR_WRAP_Cfg.eCaptureEdge);
                        break;

                    case LU_OPC_DECR_WRAP:
                        LU_HWA_SetLuDuData0(p_LU,pInitStruct->tDuCfg.DU_OperationCfg.tDECR_WRAP_Cfg.u32InitialVal);
                        LU_HWA_ConfigDuCtrlCapture(p_LU,pInitStruct->tDuCfg.DU_OperationCfg.tDECR_WRAP_Cfg.eCaptureEdge);
                        break;

                    case LU_OPC_INCR_DECR:
                        LU_HWA_SetLuDuData0(p_LU,pInitStruct->tDuCfg.DU_OperationCfg.tINCR_DECR_Cfg.u32InitialVal);
                        LU_HWA_SetLuDuData1(p_LU,pInitStruct->tDuCfg.DU_OperationCfg.tINCR_DECR_Cfg.u32FinalVal);
                        break;

                    case LU_OPC_INCR_DECR_WRAP:
                        LU_HWA_SetLuDuData0(p_LU,pInitStruct->tDuCfg.DU_OperationCfg.tINCR_DECR_WRAP_Cfg.u32InitialVal);
                        LU_HWA_SetLuDuData1(p_LU,pInitStruct->tDuCfg.DU_OperationCfg.tINCR_DECR_WRAP_Cfg.u32FinalVal);
                        break;

                    case LU_OPC_INCR_WRAP_MODE1:
                        LU_HWA_SetLuDuData0(p_LU,pInitStruct->tDuCfg.DU_OperationCfg.tINCR_WRAP_MODE1_Cfg.u32InitialVal);
                        LU_HWA_SetLuDuData2(p_LU,pInitStruct->tDuCfg.DU_OperationCfg.tINCR_WRAP_MODE1_Cfg.u32MediumVal);
                        LU_HWA_SetLuDuData1(p_LU,pInitStruct->tDuCfg.DU_OperationCfg.tINCR_WRAP_MODE1_Cfg.u32FinalVal);
                        LU_HWA_ConfigDuCtrlCapture(p_LU,pInitStruct->tDuCfg.DU_OperationCfg.tINCR_WRAP_MODE1_Cfg.eCaptureEdge);
                        break;

                    case LU_OPC_INCR_DECR_WRAP_MODE1:
                        LU_HWA_SetLuDuData0(p_LU,pInitStruct->tDuCfg.DU_OperationCfg.tINCR_DECR_WRAP_MODE1_Cfg.u32InitialVal);
                        LU_HWA_SetLuDuData2(p_LU,pInitStruct->tDuCfg.DU_OperationCfg.tINCR_DECR_WRAP_MODE1_Cfg.u32MediumVal);
                        LU_HWA_SetLuDuData1(p_LU,pInitStruct->tDuCfg.DU_OperationCfg.tINCR_DECR_WRAP_MODE1_Cfg.u32FinalVal);
                        LU_HWA_ConfigDuCtrlCapture(p_LU,pInitStruct->tDuCfg.DU_OperationCfg.tINCR_DECR_WRAP_MODE1_Cfg.eCaptureEdge);
                        break;

                    case LU_OPC_SHIFT_IN_LEFT:
                        LU_HWA_SetTransmitBitNumber(p_LU,pInitStruct->tDuCfg.DU_OperationCfg.tSHIFT_IN_LEFT_Cfg.u32ShiftInBitCnt);
                        if(true == pInitStruct->tDuCfg.DU_OperationCfg.tSHIFT_IN_LEFT_Cfg.bShiftInitCfg)
                        {
                            LU_HWA_EnableDuCfgInitShift(p_LU);
                        }
                        else
                        {
                            LU_HWA_DisableDuCfgInitShift(p_LU);
                        }

                        if(true == pInitStruct->tDuCfg.DU_OperationCfg.tSHIFT_IN_LEFT_Cfg.bContinuousEnable)
                        {
                            LU_HWA_EnableDuCfgCone(p_LU);
                        }
                        else
                        {
                            LU_HWA_DisableDuCfgCone(p_LU);
                        }
                        break;

                    case LU_OPC_SHIFT_IN_RIGHT:
                        LU_HWA_SetTransmitBitNumber(p_LU,pInitStruct->tDuCfg.DU_OperationCfg.tSHIFT_IN_RIGHT_Cfg.u32ShiftInBitCnt);
                        if(true == pInitStruct->tDuCfg.DU_OperationCfg.tSHIFT_IN_RIGHT_Cfg.bShiftInitCfg)
                        {
                            LU_HWA_EnableDuCfgInitShift(p_LU);
                        }
                        else
                        {
                            LU_HWA_DisableDuCfgInitShift(p_LU);
                        }

                        if(true == pInitStruct->tDuCfg.DU_OperationCfg.tSHIFT_IN_RIGHT_Cfg.bContinuousEnable)
                        {
                            LU_HWA_EnableDuCfgCone(p_LU);
                        }
                        else
                        {
                            LU_HWA_DisableDuCfgCone(p_LU);
                        }
                        break;

                    case LU_OPC_SHIFT_OUT_LEFT:
                        LU_HWA_SetTransmitBitNumber(p_LU,pInitStruct->tDuCfg.DU_OperationCfg.tSHIFT_OUT_LEFT_Cfg.u32ShiftInBitCnt);
                        if(true == pInitStruct->tDuCfg.DU_OperationCfg.tSHIFT_OUT_LEFT_Cfg.bShiftInitCfg)
                        {
                            LU_HWA_EnableDuCfgInitShift(p_LU);
                        }
                        else
                        {
                            LU_HWA_DisableDuCfgInitShift(p_LU);
                        }

                        if(true == pInitStruct->tDuCfg.DU_OperationCfg.tSHIFT_OUT_LEFT_Cfg.bContinuousEnable)
                        {
                            LU_HWA_EnableDuCfgCone(p_LU);
                        }
                        else
                        {
                            LU_HWA_DisableDuCfgCone(p_LU);
                        }

                        LU_HWA_SetLuDuData0(p_LU,pInitStruct->tDuCfg.DU_OperationCfg.tSHIFT_OUT_LEFT_Cfg.u32ShiftData0);
                        LU_HWA_SetLuDuData2(p_LU,pInitStruct->tDuCfg.DU_OperationCfg.tSHIFT_OUT_LEFT_Cfg.u32ShiftData2);
                        LU_HWA_SetLuDuData1(p_LU,pInitStruct->tDuCfg.DU_OperationCfg.tSHIFT_OUT_LEFT_Cfg.u32ShiftData1);
                        break;

                    case LU_OPC_SHIFT_OUT_RIGHT:
                        LU_HWA_SetTransmitBitNumber(p_LU,pInitStruct->tDuCfg.DU_OperationCfg.tSHIFT_OUT_RIGHT_Cfg.u32ShiftInBitCnt);
                        if(true == pInitStruct->tDuCfg.DU_OperationCfg.tSHIFT_OUT_RIGHT_Cfg.bShiftInitCfg)
                        {
                            LU_HWA_EnableDuCfgInitShift(p_LU);
                        }
                        else
                        {
                            LU_HWA_DisableDuCfgInitShift(p_LU);
                        }

                        if(true == pInitStruct->tDuCfg.DU_OperationCfg.tSHIFT_OUT_RIGHT_Cfg.bContinuousEnable)
                        {
                            LU_HWA_EnableDuCfgCone(p_LU);
                        }
                        else
                        {
                            LU_HWA_DisableDuCfgCone(p_LU);
                        }

                        LU_HWA_SetLuDuData0(p_LU,pInitStruct->tDuCfg.DU_OperationCfg.tSHIFT_OUT_RIGHT_Cfg.u32ShiftData0);
                        LU_HWA_SetLuDuData2(p_LU,pInitStruct->tDuCfg.DU_OperationCfg.tSHIFT_OUT_RIGHT_Cfg.u32ShiftData2);
                        LU_HWA_SetLuDuData1(p_LU,pInitStruct->tDuCfg.DU_OperationCfg.tSHIFT_OUT_RIGHT_Cfg.u32ShiftData1);
                        break;

                    case LU_OPC_FLEX:
                        LU_HWA_SetConfigDuCTRL(p_LU,pInitStruct->tDuCfg.DU_OperationCfg.tFlex_Mode_Cfg.u32CTRL);
                        LU_HWA_SetConfigDuCfg(p_LU,pInitStruct->tDuCfg.DU_OperationCfg.tFlex_Mode_Cfg.u32CFG);
                        LU_HWA_SetLuDuData0(p_LU,pInitStruct->tDuCfg.DU_OperationCfg.tFlex_Mode_Cfg.u32DATA0);
                        LU_HWA_SetLuDuData0(p_LU,pInitStruct->tDuCfg.DU_OperationCfg.tFlex_Mode_Cfg.u32DATA1);
                        LU_HWA_SetLuDuData0(p_LU,pInitStruct->tDuCfg.DU_OperationCfg.tFlex_Mode_Cfg.u32DATA2);
                        LU_HWA_SetLuDuData0(p_LU,pInitStruct->tDuCfg.DU_OperationCfg.tFlex_Mode_Cfg.u32DATA3);
                        LU_HWA_SetLuDuData0(p_LU,pInitStruct->tDuCfg.DU_OperationCfg.tFlex_Mode_Cfg.u32DATA4);
                        LU_HWA_SetLuDuData0(p_LU,pInitStruct->tDuCfg.DU_OperationCfg.tFlex_Mode_Cfg.u32DATA5);
                        LU_HWA_SetLuDuData0(p_LU,pInitStruct->tDuCfg.DU_OperationCfg.tFlex_Mode_Cfg.u32DATA6);
                        LU_HWA_SetLuDuData0(p_LU,pInitStruct->tDuCfg.DU_OperationCfg.tFlex_Mode_Cfg.u32DATA7);
                        break;

                    case LU_OPC_DATA_MATCH:
                        LU_HWA_SetLuDuData0(p_LU,pInitStruct->tDuCfg.DU_OperationCfg.tMatch_Mode_Cfg.u32MatchMask);
                        LU_HWA_SetLuDuData1(p_LU,pInitStruct->tDuCfg.DU_OperationCfg.tMatch_Mode_Cfg.u32MatchData);
                        break;

                    default:
                        /* do nothing*/
                        break;
                }

                LU_HWA_SetDuCfgOpc(p_LU,pInitStruct->tDuCfg.eDuOperationCode);
                LU_HWA_SetInputAmux(p_LU,pInitStruct->tDuCfg.tDuInputSelect.eDuInputASelect);
                LU_HWA_SetInputBmux(p_LU,pInitStruct->tDuCfg.tDuInputSelect.eDuInputBSelect);
                LU_HWA_SetInputCmux(p_LU,pInitStruct->tDuCfg.tDuInputSelect.eDuInputCSelect);

                if(true == pInitStruct->tDuCfg.bEnableMatchInterrupt)
                {
                    LU_HWA_EnableInterruptMatch(p_LU);
                }
                else
                {
                    LU_HWA_DisableInterruptMatch(p_LU);
                }

                if(true == pInitStruct->tDuCfg.bEnableUnderflowInterrupt)
                {
                    LU_HWA_EnableInterruptUnderflow(p_LU);
                }
                else
                {
                    LU_HWA_DisableInterruptUnderflow(p_LU);
                }

                if(true == pInitStruct->tDuCfg.bEnableOverflowInterrupt)
                {
                    LU_HWA_EnableInterruptOverflow(p_LU);
                }
                else
                {
                    LU_HWA_DisableInterruptOverflow(p_LU);
                }

                if(true == pInitStruct->tDuCfg.bEnableMatchInterrupt)
                {
                    LU_HWA_EnableInterruptMatch(p_LU);
                }
                else
                {
                    LU_HWA_DisableInterruptMatch(p_LU);
                }

                if(true == pInitStruct->tDuCfg.bGenerateUnderflowDMARequest)
                {
                    LU_HWA_EnableDmaUnderflow(p_LU);
                }
                else
                {
                    LU_HWA_DisableDmaUnderflow(p_LU);
                }

                if(true == pInitStruct->tDuCfg.bGenerateOverflowDMARequest)
                {
                    LU_HWA_EnableDmaOverflow(p_LU);
                }
                else
                {
                    LU_HWA_DisableDmaOverflow(p_LU);
                }

                if((true == pInitStruct->tDuCfg.bEnableMatchInterrupt) ||
                   (true == pInitStruct->tDuCfg.bEnableUnderflowInterrupt) ||
                   (true == pInitStruct->tDuCfg.bEnableOverflowInterrupt)
                )
                {
                    LU_HWA_EnableDuCtrlInt(p_LU);
                    pLuHandler->Lu_Status.pDuInterruptCallback = pInitStruct->tDuCfg.pDuInterruptCallback;
                }
                else
                {
                    LU_HWA_DisableDuCtrlInt(p_LU);
                }

                if((true == pInitStruct->tDuCfg.bGenerateMatchDMARequest) ||
                   (true == pInitStruct->tDuCfg.bGenerateUnderflowDMARequest) ||
                   (true == pInitStruct->tDuCfg.bGenerateOverflowDMARequest)
                )
                {
                    LU_HWA_EnableDuCtrlDma(p_LU);
                }
                else
                {
                    LU_HWA_DisableDuCtrlDma(p_LU);
                }
            }
        }
#if LU_DEV_ERROR_REPORT == STD_ON
    }
#endif
    return eRet;
}

/**
 * @brief De-initialize Lu instance
 * @param pInitStruct Lu initialization structure
 *
 */
void LU_Deinit(LU_HandleType *pLuHandler)
{
#if LU_DEV_ERROR_REPORT == STD_ON
    if (pLuHandler->eInstance >= ELU_INSTANCE_COUNT)
    {
        LU_ReportDevError(LU_DEINIT_ID, LU_E_PARAM_INSTANCE);
    }
    else
    {
#endif
        LU_Type *const p_LU = p_LUTables[pLuHandler->eInstance] ;
        LU_HWA_SoftReset(p_LU);
#if LU_DEV_ERROR_REPORT == STD_ON
    }
#endif
}

/**
 * @brief lu interrupt function.
* @param pFcpitHandle Fcpit processing handle
 */
void LUn_IRQHandler(LU_HandleType *pLuHandle)
{
    LU_Type *const p_LU = p_LUTables[pLuHandle->eInstance] ;
    uint32_t u32LgIndex;
    uint32 u32InterruptStatus = LU_HWA_GetIntStatus(p_LU);

    pLuHandle->Lu_Status.u32DATA0 = LU_HWA_GetLuDuData0(p_LU);
    pLuHandle->Lu_Status.u32DATA1 = LU_HWA_GetLuDuData1(p_LU);
    pLuHandle->Lu_Status.u32DATA2 = LU_HWA_GetLuDuData2(p_LU);
    pLuHandle->Lu_Status.u32DATA3 = LU_HWA_GetLuDuData3(p_LU);
    pLuHandle->Lu_Status.u32DATA4 = LU_HWA_GetLuDuData4(p_LU);
    pLuHandle->Lu_Status.u32DATA5 = LU_HWA_GetLuDuData5(p_LU);
    pLuHandle->Lu_Status.u32DATA6 = LU_HWA_GetLuDuData6(p_LU);
    pLuHandle->Lu_Status.u32DATA7 = LU_HWA_GetLuDuData7(p_LU);

    for(u32LgIndex=0; u32LgIndex < LG_CNT; u32LgIndex++)
    {
        if(0u != (u32InterruptStatus&(0x1u<<u32LgIndex)))
        {
            if(NULL_PTR != pLuHandle->Lu_Status.pLgInterruptCallback)
            {
                pLuHandle->Lu_Status.pLgInterruptCallback[u32LgIndex](pLuHandle);
            }
        }
    }

    if(0x10u == (u32InterruptStatus&0x10u))
    {
        if(NULL_PTR != pLuHandle->Lu_Status.pDuInterruptCallback)
        {
            pLuHandle->Lu_Status.pDuInterruptCallback(pLuHandle);
        }
    }

    /*Clear all interrupt flag*/
    LU_HWA_SetIntStatus(p_LU,LU_INT_ST_LUTINTST_MASK);
}
#endif
