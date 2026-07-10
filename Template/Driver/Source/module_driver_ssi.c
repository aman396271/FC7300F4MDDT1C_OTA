/**
 * @file module_driver_ssi.c
 * @author Flagchip
 * @brief ssi driver type definition and API
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
 *   ---------   ----------    ------------   ----------   ---------------
 *   2.1.0      2023-12-15    Flagchip054     N/A          First version for FC7300
 ********************************************************************************/

#include "module_driver_ssi.h"
#include "module_driver_pcc.h"
#include <stdarg.h>

#if SSI_INSTANCE_COUNT > 0U
/********* Macro ************/
#ifndef SSI_DEV_ERROR_REPORT
#define SSI_DEV_ERROR_REPORT STD_OFF
#endif

#if SSI_DEV_ERROR_REPORT == STD_ON
#define SSI_ReportDevError(func, error) ReportDevError(SSI_MODULE_ID, func, error)
#endif

/********* Local Variables ************/
/* Ssi instance array */
static SSI_Type *const s_SSI_InstanceTable[SSI_INSTANCE_COUNT] = SSI_BASE_PTRS;
static uint8_t         s_SSI_PreStop[SSI_INSTANCE_COUNT]       = { 0 };
static uint32_t        s_SSI_PreWhl[SSI_INSTANCE_COUNT]        = { 0 };

/********* Local Prototype Functions ************/

/********* Local Functions  ************/

static void SSI_SubinsEnable(SSI_Type *pSsi, SSI_Sub_Ins_Index u8SubIdx)
{
    SSI_HWA_Subins_Enable(pSsi, (uint8_t)u8SubIdx);
}

static void SSI_SubinsDisable(SSI_Type *pSsi, SSI_Sub_Ins_Index u8SubIdx)
{
    SSI_HWA_Subins_Disable(pSsi, (uint8_t)u8SubIdx);
}

static SSI_ErrorType SSI_Common_Cfg(SSI_Type *pSsi, uint8_t u8SubIdx, const SSI_Common_CfgType *tCommCfg)
{
    SSI_ErrorType eRet = SSI_ERROR_OK;

    SSI_HWA_SetSubinsChlSwitch(pSsi, u8SubIdx, tCommCfg->u8ChlSw);
    if (tCommCfg->u8RangeChken == TRUE)
    {
        SSI_HWA_SubinsWinRangChk_Enable(pSsi, u8SubIdx);
    }
    else
    {
        SSI_HWA_SubinsWinRangChk_Disable(pSsi, u8SubIdx);
    }

    SSI_HWA_SetSubinsGpwmTimeCnt(pSsi, u8SubIdx, tCommCfg->u32GpwmToc);
    SSI_HWA_SetSubinsGpwmPola(pSsi, u8SubIdx, tCommCfg->u8GpwmInv);
    SSI_HWA_SetSubinsChlSel(pSsi, u8SubIdx, tCommCfg->eChnlSel);
    SSI_HWA_SetSubinsProtSel(pSsi, u8SubIdx, tCommCfg->eProtSel);
#if SSI_INTERNAL_CMP_SUPPORT == STD_ON
    uint32_t u32TryCount = 0;
    if (tCommCfg->u8CmpEn == TRUE)
    {
        SSI_HWA_SetSubinsResSel(pSsi, u8SubIdx, tCommCfg->u8ResSel);
        SSI_HWA_SubinsIntCmp_Enable(pSsi, u8SubIdx);
        while (!SSI_HWA_GetIntCmpStatus(pSsi, u8SubIdx) && (u32TryCount++ < 1000000))
            ;
        if (u32TryCount < 1000000)
        {
            eRet = SSI_ERROR_OK;
        }
        else
        {
            eRet = SSI_ERROR_INDEX;
        }
    }
    else
    {
        SSI_HWA_SubinsIntCmp_Disable(pSsi, u8SubIdx);
    }
#endif
    return eRet;
}

static void SSI_Filter_Cfg(SSI_Type *pSsi, SSI_Sub_Ins_Index u8SubIdx, uint32_t u32FiltWidth)
{
    SSI_HWA_SetSubinsFilterWidth(pSsi, (uint8_t)u8SubIdx, u32FiltWidth);
    SSI_HWA_SubinsFilter_Enable(pSsi, (uint8_t)u8SubIdx);
}

/********* Global Functions  ************/
void SSI_Clock_Div_Cfg(SSI_HandleType *pSSIHandle, uint32_t u32ClkDiv)
{
    SSI_Type *pSSI;

#if SSI_DEV_ERROR_REPORT == STD_ON
    if (pSSIHandle == NULL)
    {
        SSI_ReportDevError(SSI_CLOCK_DIV_ID, SSI_E_PARAM_POINTER);
    }
    else if (pSSIHandle->eInstance >= SSI_INSTANCE_COUNT)
    {
        SSI_ReportDevError(SSI_CLOCK_DIV_ID, SSI_E_PARAM_INSTANCE);
    }
    else
    {
#endif
        pSSI = (SSI_Type *)s_SSI_InstanceTable[pSSIHandle->eInstance];
        SSI_HWA_SetFuncDev(pSSI, u32ClkDiv);
        SSI_HWA_Func_Enable(pSSI);
#if SSI_DEV_ERROR_REPORT == STD_ON
    }
#endif
}

void SSI_Window_Cfg(SSI_HandleType *pSSIHandle, SSI_Window_CfgType *u32WindowCfg)
{
    SSI_Type *pSSI;

#if SSI_DEV_ERROR_REPORT == STD_ON
    if ((pSSIHandle == NULL) || (U32windowCfg == NULL))
    {
        SSI_ReportDevError(SSI_WINDOW_ID, SSI_E_PARAM_POINTER);
    }
    else if (pSSIHandle->eInstance >= SSI_INSTANCE_COUNT)
    {
        SSI_ReportDevError(SSI_WINDOW_ID, SSI_E_PARAM_INSTANCE);
    }
    else
    {
#endif
        pSSI = (SSI_Type *)s_SSI_InstanceTable[pSSIHandle->eInstance];
        SSI_HWA_SetGlobalCounterWindowsL(pSSI, u32WindowCfg->u32win_l);
        SSI_HWA_SetGlobalCounterWindowsH(pSSI, u32WindowCfg->u32win_h);
        /* Wait for the register write operation to complete */
#if SSI_DEV_ERROR_REPORT == STD_ON
    }
#endif
}

void SSI_GlobalPro_Cfg(SSI_HandleType *pSSIHandle, uint32_t u32GpcrCfg)
{
    SSI_Type *pSSI;

#if SSI_DEV_ERROR_REPORT == STD_ON
    if ((pSSIHandle == NULL) || (U32windowCfg == NULL))
    {
        SSI_ReportDevError(SSI_WINDOW_ID, SSI_E_PARAM_POINTER);
    }
    else if (pSSIHandle->eInstance >= SSI_INSTANCE_COUNT)
    {
        SSI_ReportDevError(SSI_WINDOW_ID, SSI_E_PARAM_INSTANCE);
    }
    else
    {
#endif
        pSSI = (SSI_Type *)s_SSI_InstanceTable[pSSIHandle->eInstance];
        SSI_HWA_SetGlobalProCfg(pSSI, u32GpcrCfg);
        /* Wait for the register write operation to complete */
#if SSI_DEV_ERROR_REPORT == STD_ON
    }
#endif
}

SSI_ErrorType SSI_Sub_Ins_Init(SSI_HandleType *pSSIHandle, SSI_Sub_Ins_InitType *pInitCfg)
{
    SSI_ErrorType eRetval = SSI_ERROR_OK;
    SSI_Type     *pSSI;

#if SSI_DEV_ERROR_REPORT == STD_ON
    if ((pSSIHandle == NULL) || (pInitCfg == NULL))
    {
        SSI_ReportDevError(SSI_SUBINS_INIT_ID, SSI_E_PARAM_POINTER);
    }
    else if (pSSIHandle->eInstance >= SSI_INSTANCE_COUNT)
    {
        SSI_ReportDevError(SSI_SUBINS_INIT_ID, SSI_E_PARAM_INSTANCE);
    }
    else
    {
#endif
        pSSI = (SSI_Type *)s_SSI_InstanceTable[pSSIHandle->eInstance];

        if (pInitCfg->eIndex >= SUB_INS_COUNT)
        {
#if SSI_DEV_ERROR_REPORT == STD_ON
            SSI_ReportDevError(SSI_SUBINS_INIT_ID, SSI_E_PARAM_SUBINSTANCE);
#endif
            eRetval = SSI_ERROR_INDEX;
        }
        else
        {
            SSI_SubinsDisable(pSSI, pInitCfg->eIndex);
            SSI_Filter_Cfg(pSSI, pInitCfg->eIndex, pInitCfg->u32FiltWidth);
            eRetval = SSI_Common_Cfg(pSSI, pInitCfg->eIndex, pInitCfg->tCfg);
            if (eRetval == SSI_ERROR_OK)
            {
                if (pInitCfg->bEnErrorInterrupt == true)
                {
                    SSI_HWA_SubinsErrInt_Enable(pSSI, pInitCfg->eIndex);
                }
                if (pInitCfg->bEnVldInterrupt == true)
                {
                    SSI_HWA_SubinsValidInt_Enable(pSSI, pInitCfg->eIndex);
                }
                SSI_SubinsEnable(pSSI, pInitCfg->eIndex);
            }
            else
            {
#if SSI_DEV_ERROR_REPORT == STD_ON
                SSI_ReportDevError(SSI_SUBINS_INIT_ID, SSI_E_COMMON);
#endif
            }
        }
#if SSI_DEV_ERROR_REPORT == STD_ON
    }
#endif
    return eRetval;
}

void SSI_IRQHandler(SSI_HandleType *pSSIHandle)
{
    uint32_t  u32State;
    uint32_t  u32Prot;
    uint32_t  u32Err = 0;
    uint32_t  u32Tmp = 0;
    SSI_Type *pSSI;

#if SSI_DEV_ERROR_REPORT == STD_ON
    if (pSSIHandle == NULL)
    {
        SSI_ReportDevError(SSI_INIT_INTERRUPT_ID, SSI_E_PARAM_POINTER);
    }
    else
    {
#endif
        pSSI = (SSI_Type *)s_SSI_InstanceTable[pSSIHandle->eInstance];
        for (uint8_t u32SubIdx = 0; u32SubIdx < SUB_INS_COUNT; u32SubIdx++)
        {
            u32Err   = 0;
            u32State = SSI_HWA_GetStatusVal(pSSI, u32SubIdx);
            if (u32State != 0)
            {
                SSI_HWA_ClearSubStatus(pSSI, u32SubIdx);

                pSSIHandle->tSSI_DataInf->tActiveIdx = (SSI_Sub_Ins_Index)u32SubIdx;
                /* error */
                if (u32State & SSI_ISR_SPC_TIMEOUT_ERR(1))
                {
                    u32Err |= (1U << 1);
                }

                if (u32State & SSI_ISR_PROTOC_ERR(1))
                {
                    u32Err |= (1U << 6);
                    if (u32State & SSI_ISR_SPC_RANGE_ERR(1))
                    {
                        u32Err |= (1U << 2);
                    }
                    else if (u32State & SSI_ISR_DECODE_ERR(1))
                    {
                        u32Err |= (1U << 3);
                    }
                    else if (u32State & SSI_ISR_INTERVAL_ERR(1))
                    {
                        u32Err |= (1U << 4);
                    }
                    else if (u32State & SSI_ISR_PULSE_WIDTH_ERR(1))
                    {
                        u32Err |= (1U << 5);
                    }
                    else
                    {
                    }
                }

                if (u32Err)
                {
                    if (pSSIHandle->pSSI_ErrorNotify != NULL)
                    {
                        pSSIHandle->pSSI_ErrorNotify(pSSIHandle, u32Err);
                    }
                }

                if (u32State & SSI_ISR_SPC_VLD(1))
                {
                    u32Tmp = SSI_HWA_GetSensorProtocolCnt(pSSI, u32SubIdx);
                    if (s_SSI_PreStop[u32SubIdx] == 1)
                    {
                        pSSIHandle->tSSI_DataInf->U32Whlval = s_SSI_PreWhl[u32SubIdx] + u32Tmp;
                    }
                    else
                    {
                        pSSIHandle->tSSI_DataInf->U32Whlval = u32Tmp;
                    }
                    s_SSI_PreWhl[u32SubIdx] = u32Tmp;

                    if (u32State & SSI_ISR_WHL_STOP(1))
                    {
                        pSSIHandle->tSSI_DataInf->U8StopFlag = 1;
                        s_SSI_PreStop[u32SubIdx]             = 1;
                    }
                    else
                    {
                        pSSIHandle->tSSI_DataInf->U8StopFlag = 0;
                        s_SSI_PreStop[u32SubIdx]             = 0;
                    }

                    u32Prot = SSI_HWA_GetSubinsProtSel(pSSI, u32SubIdx);
                    switch (u32Prot)
                    {
                        case NORMAL:
                            if (pSSIHandle->pSSI_VldNotify != NULL)
                            {
                                pSSIHandle->pSSI_VldNotify(pSSIHandle, NORMAL);
                            }
                            break;
                        case PWM:
                            pSSIHandle->tSSI_DataInf->U32Pwmval = SSI_HWA_GetPwmDecodeVal(pSSI,
                                                                                          u32SubIdx);
                            if (pSSIHandle->pSSI_VldNotify != NULL)
                            {
                                pSSIHandle->pSSI_VldNotify(pSSIHandle, PWM);
                            }
                            break;
                        case GPWM:
                            pSSIHandle->tSSI_DataInf->U32HPCRval =
                                SSI_HWA_GetHighPulseCnt(pSSI, u32SubIdx);
                            if (pSSIHandle->pSSI_VldNotify != NULL)
                            {
                                pSSIHandle->pSSI_VldNotify(pSSIHandle, GPWM);
                            }
                            break;
                        case AK:
                            pSSIHandle->tSSI_DataInf->U32Mcodecnt =
                                SSI_HWA_GetAkManDecodeCnt(pSSI, u32SubIdx);
                            pSSIHandle->tSSI_DataInf->U32Mcodeval =
                                SSI_HWA_GetAkMancodeVal(pSSI, u32SubIdx);
                            if (pSSIHandle->pSSI_VldNotify != NULL)
                            {
                                pSSIHandle->pSSI_VldNotify(pSSIHandle, AK);
                            }
                            break;
                        default:
                            break;
                    }
                }
                break;
            }
        }
#if SSI_DEV_ERROR_REPORT == STD_ON
    }
#endif
}

#endif
