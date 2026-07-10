/**
 * @file module_driver_msc.c
 * @author Flagchip
 * @brief MSC driver type definition and API
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
 *   0.1.0       2022-11-18    Flagchip084   N/A          First version for FC7xxx
 *   0.2.0       2023-02-13    Flagchip084   N/A          FC7xxx release version
 *   0.3.0       2024-07-26    Flagchip084   N/A          FC7xxx SDK 2.0 version
 ******************************************************************************** */
#include "module_driver_msc.h"

#if MSC_INSTANCE_COUNT > 0U

/* ################################################################################## */
/* ####################################### Macro #################################### */

/* ################################################################################## */
/* ################################### Type define ################################## */

/* ################################################################################## */
/* ################################ Local Variables ################################# */
static MSC_Type *const     s_apMscBase[MSC_INSTANCE_COUNT]        = MSC_BASE_PTRS;
/* ################################################################################## */
/* ########################### Local Prototype Functions ############################ */

/* ################################################################################## */
/* ######################### Global prototype Functions  ############################ */

/* ################################################################################## */
/* ################################ Local Functions  ################################ */
void MSCn_IRQHandler(const MSC_HandleType *pMscHandle)
{
    uint32_t u32IntFlag = MSC_GetInterruptStatus(pMscHandle);
    uint32_t u32IntStatus = 0;
    MSC_Type *const pMsc = s_apMscBase[pMscHandle->eInstance];

    if (u32IntFlag & MSC_INSR_RFI_MASK)
    {
        MSC_ClearReceiveInterruptFlag(pMscHandle);
        if(MSC_HWA_GetIncr(pMsc) & MSC_INCR_RFIE_MASK)
        {
            u32IntStatus |= MSC_INSR_RFI_MASK;
        }
    }
    if (u32IntFlag & MSC_INSR_TFI_MASK)
    {
        MSC_ClearTimeFrameInterruptFlag(pMscHandle);
        if(MSC_HWA_GetIncr(pMsc) & MSC_INCR_TFIE_MASK)
        {
            u32IntStatus |= MSC_INSR_TFI_MASK;
        }
    }
    if (u32IntFlag & MSC_INSR_CFI_MASK)
    {
        MSC_ClearCommandFrameInterruptFlag(pMscHandle);
        if(MSC_HWA_GetIncr(pMsc) & MSC_INCR_CFIE_MASK)
        {
            u32IntStatus |= MSC_INSR_CFI_MASK;
        }
    }
    if (u32IntFlag & MSC_INSR_DFI_MASK)
    {
        MSC_ClearDataFrameInterruptFlag(pMscHandle);
        if(MSC_HWA_GetIncr(pMsc) & MSC_INCR_DFIE_MASK)
        {
            u32IntStatus |= MSC_INSR_DFI_MASK;
        }
    }

    if ((pMscHandle->tSettings).pISRCallback != NULL)
    {
        (pMscHandle->tSettings).pISRCallback(pMscHandle, u32IntStatus);
    }

    if (u32IntFlag & MSC_INSR_RFI_MASK)
    {
        if (((MSC_HWA_GetRtor(pMsc) & MSC_RTOR_TOIE_MASK) != MSC_RTOR_TOIE_MASK) && (pMscHandle->tSettings).bToEnableFlag)
        {
            MSC_ClearTimeoutInterruptFlag(pMscHandle);
            MSC_HWA_SetRtor(pMsc, (MSC_HWA_GetRtor(pMsc)& MSC_RTOR_TOV_MASK)|MSC_RTOR_TOIE_MASK);
        }
    }

    if(MSC_GetToInterruptStatus(pMscHandle) & MSC_RTOR_TOF_MASK)
    {
        MSC_ClearTimeoutInterruptFlag(pMscHandle);
        if ((MSC_HWA_GetRtor(pMsc) & MSC_RTOR_TOIE_MASK))
        {
            if ((pMscHandle->tSettings).pTOISRCallback != NULL)
            {
                (pMscHandle->tSettings).pTOISRCallback(pMscHandle);
            }
        }
    }
}
/* ################################################################################## */
/* ################################ Global Functions ################################ */

MSC_ReturnType MSC_InitStructure(MSC_InitCfgType *pInitConfig)
{
    MSC_ReturnType result = MSC_RETURN_OK;

#if MSC_DEV_ERROR_REPORT == STD_ON
    if (pInitConfig == NULL)
    {
        result = MSC_RETURN_E_PARAM;
        MSC_ReportDevError(MSC_INIT_STRUCTURE_ID, MSC_E_PARAM_POINTER);
    }
    else if (pInitConfig->u8CommandBitLength > 32U || pInitConfig->u8SRLDataBitLength > 16U || pInitConfig->u8SRHDataBitLength > 16U)
    {
        result = MSC_RETURN_E_PARAM;
        MSC_ReportDevError(MSC_INIT_STRUCTURE_ID, MSC_E_PARAM_BITLENGTH);
    }
    else
#endif
    {
        pInitConfig->u8PassiveLength = 2;                  /* Frame passive phase is 2 clock. */
        pInitConfig->u8PTFNumber = 0xFU;                   /* Passive frame number between data frames. */
        pInitConfig->eWorkMode = MSC_REPETITION_MODE;      /* Set Repetition mode. */
        pInitConfig->u8CommandBitLength = 16;              /* Command bits length. */
        pInitConfig->u8SRHDataBitLength = 0;               /* High data register selected bits length. */
        pInitConfig->bSelSRH = false;                      /* Disable High data register start bit. */
        pInitConfig->u8SRLDataBitLength = 16;              /* Low data register selected bits length. */
        pInitConfig->bSelSRL = true;                       /* Enable Low data register start bit. */
        pInitConfig->bDelayControl = false;                /* Disable the interrupt delay. */
        pInitConfig->eParity = MSC_EVEN_PARITY;            /* Set even parity. */
        pInitConfig->eBaudRate = MSC_BAUDRATE_FMSC_DIV128; /* Set the FMSC divider to be 128. */
        pInitConfig->eRsvFrameType = MSC_FRAME_12_BIT;     /* Set receive frame bit length. */
    }

    return result;
}

MSC_ReturnType MSC_Init(MSC_HandleType *pMscHandle, const MSC_InitCfgType *pInitConfig)
{
    MSC_ReturnType result = MSC_RETURN_OK;

#if MSC_DEV_ERROR_REPORT == STD_ON
    if (pMscHandle == NULL)
    {
        result = MSC_RETURN_E_PARAM;
        MSC_ReportDevError(MSC_INIT_ID, MSC_E_PARAM_POINTER);
    }
    else if (pMscHandle->eInstance >= MSC_INSTANCE_COUNT)
    {
        result = MSC_RETURN_E_PARAM;
        MSC_ReportDevError(MSC_INIT_ID, MSC_E_PARAM_INSTANCE);
    }
    else if (pInitConfig == NULL)
    {
        result = MSC_RETURN_E_PARAM;
        MSC_ReportDevError(MSC_INIT_ID, MSC_E_PARAM_POINTER);
    }
    else if (pInitConfig->u8CommandBitLength > 32U || pInitConfig->u8SRLDataBitLength > 16U || pInitConfig->u8SRHDataBitLength > 16U)
    {
        result = MSC_RETURN_E_PARAM;
        MSC_ReportDevError(MSC_INIT_ID, MSC_E_PARAM_BITLENGTH);
    }
    else
#endif
    {
        MSC_Type *const pMsc = s_apMscBase[pMscHandle->eInstance];
        uint32_t        u32TempValue;
        uint32_t        u32TimeoutCount = 0xFFFFFFU;

        (pMscHandle->tSettings).bToEnableFlag = false;

        MSC_HWA_SetMsrRst(pMsc);

        while (MSC_HWA_GetMsrRdone(pMsc) == false)
        {
            u32TimeoutCount--;
            if (u32TimeoutCount == 0U)
            {
                break;
            }
        }

        if (u32TimeoutCount == 0U)
        {
            result = MSC_RETURN_E_NOT_OK;
        }
        else
        {
            MSC_HWA_ClearMsrDone(pMsc);

            u32TempValue = MSC_TCCTR_PL(pInitConfig->u8PassiveLength) | MSC_TCCTR_WM(pInitConfig->eWorkMode) | MSC_TCCTR_SELH(pInitConfig->bSelSRH) | MSC_TCCTR_SELL(pInitConfig->bSelSRL) |
                        MSC_TCCTR_NBS(pInitConfig->u8CommandBitLength) | MSC_TCCTR_NHBS(pInitConfig->u8SRHDataBitLength) | MSC_TCCTR_NLBS(pInitConfig->u8SRLDataBitLength);
            MSC_HWA_SetTcctr(pMsc, u32TempValue);

            MSC_HWA_SetNp(pMsc, pInitConfig->u8PTFNumber);

            u32TempValue =
                MSC_RCCSR_RFT(pInitConfig->eRsvFrameType) | MSC_RCCSR_RBR(pInitConfig->eBaudRate) | MSC_RCCSR_PCTL(pInitConfig->eParity) | MSC_RCCSR_HIDC(pInitConfig->bDelayControl);
            MSC_HWA_SetRccsr(pMsc, u32TempValue);
        }
    }

    return result;
}

MSC_ReturnType MSC_DeInit(MSC_HandleType *pMscHandle)
{
    MSC_ReturnType result = MSC_RETURN_OK;

#if MSC_DEV_ERROR_REPORT == STD_ON
    if (pMscHandle == NULL)
    {
        MSC_ReportDevError(MSC_DEINIT_ID, MSC_E_PARAM_POINTER);
    }
    else if (pMscHandle->eInstance >= MSC_INSTANCE_COUNT)
    {
        MSC_ReportDevError(MSC_DEINIT_ID, MSC_E_PARAM_INSTANCE);
    }
    else
#endif
    {
        uint32_t u32TimeoutCount = 0xFFFFFFU;
        MSC_Type *const pMsc = s_apMscBase[pMscHandle->eInstance];

        MSC_HWA_SetMsrRst(pMsc);

        while (MSC_HWA_GetMsrRdone(pMsc) == false)
        {
            u32TimeoutCount--;
            if (u32TimeoutCount == 0U)
            {
                break;
            }
        }

        if (u32TimeoutCount == 0U)
        {
            result = MSC_RETURN_E_NOT_OK;
        }
        else
        {
            MSC_HWA_ClearMsrDone(pMsc);
            (pMscHandle->tSettings).pISRCallback = NULL;
        }
    }

    return result;
}

void MSC_initInterrupt(MSC_HandleType *pMscHandle, const MSC_InterruptCfgType *pInteruptConfig)
{

#if MSC_DEV_ERROR_REPORT == STD_ON
    if (pMscHandle == NULL)
    {
        MSC_ReportDevError(MSC_INIT_INTERRUPT_ID, MSC_E_PARAM_POINTER);
    }
    else if (pMscHandle->eInstance >= MSC_INSTANCE_COUNT)
    {
        MSC_ReportDevError(MSC_INIT_INTERRUPT_ID, MSC_E_PARAM_INSTANCE);
    }
    else if (pInteruptConfig == NULL)
    {
        MSC_ReportDevError(MSC_INIT_INTERRUPT_ID, MSC_E_PARAM_POINTER);
    }
    else
#endif
    {
        uint32_t        u32TempValue;
        MSC_Type *const pMsc = s_apMscBase[pMscHandle->eInstance];

        u32TempValue = MSC_INCR_RFIE(pInteruptConfig->eRFIEMode) | MSC_INCR_TFIE(pInteruptConfig->bTFIntEnable) | MSC_INCR_CFIE(pInteruptConfig->bCFIntEnable) |
                    MSC_INCR_DFIE(pInteruptConfig->eDFIEMode);
        MSC_HWA_SetIncr(pMsc, u32TempValue);

        u32TempValue = MSC_RTOR_TOIE(0) | MSC_RTOR_TOV(pInteruptConfig->u16TimeoutValue);
        MSC_HWA_SetRtor(pMsc, u32TempValue);

        (pMscHandle->tSettings).pISRCallback = pInteruptConfig->pISRCallback;
        (pMscHandle->tSettings).pTOISRCallback = pInteruptConfig->pTOISRCallback;

        (pMscHandle->tSettings).bToEnableFlag = pInteruptConfig->bTOIntEnable;
    }
}

void MSC_SelTranmittingSource(const MSC_HandleType *pMscHandle, uint32_t u32SourceMask, MSC_TransSourceType eSourceType)
{

#if MSC_DEV_ERROR_REPORT == STD_ON
    if (pMscHandle == NULL)
    {
        MSC_ReportDevError(MSC_SEL_TRANSMITTING_SOURCE_ID, MSC_E_PARAM_POINTER);
    }
    else if (pMscHandle->eInstance >= MSC_INSTANCE_COUNT)
    {
        MSC_ReportDevError(MSC_SEL_TRANSMITTING_SOURCE_ID, MSC_E_PARAM_INSTANCE);
    }
    else
#endif
    {
        MSC_Type *const pMsc          = s_apMscBase[pMscHandle->eInstance];
        uint32_t        u32TempValue1 = 0;
        uint16_t        u32TempValue2;
        uint8_t         u8i;

        u32TempValue2 = (uint16_t)(u32SourceMask & 0xFFFFU);

        for (u8i = 0U; u8i < 16U; u8i++)
        {
            if ((u32TempValue2 & 0x01U) != 0U)
            {
                u32TempValue1 |= (uint32_t)eSourceType << (u8i << 1U);
            }
            u32TempValue2 = u32TempValue2 >> 1;
        }
        MSC_HWA_SetTcslr(pMsc, u32TempValue1);

        u32TempValue2 = (uint16_t)((u32SourceMask >> 16) & 0xFFFFU);
        for (u8i = 0U; u8i < 16U; u8i++)
        {
            if ((u32TempValue2 & 0x01U) != 0U)
            {
                u32TempValue1 |= (uint32_t)eSourceType << (u8i << 1U);
            }
            u32TempValue2 = u32TempValue2 >> 1;
        }
        MSC_HWA_SetTcshr(pMsc, u32TempValue1);
    }
}

void MSC_SetEmergencyLoad(const MSC_HandleType *pMscHandle, uint32_t u32Value)
{

#if MSC_DEV_ERROR_REPORT == STD_ON
    if (pMscHandle == NULL)
    {
        MSC_ReportDevError(MSC_SET_EMERGENCY_LOAD_ID, MSC_E_PARAM_POINTER);
    }
    else if (pMscHandle->eInstance >= MSC_INSTANCE_COUNT)
    {
        MSC_ReportDevError(MSC_SET_EMERGENCY_LOAD_ID, MSC_E_PARAM_INSTANCE);
    }
    else
#endif
    {
        MSC_Type *const pMsc = s_apMscBase[pMscHandle->eInstance];

        MSC_HWA_SetTcelr(pMsc, u32Value);
    }
}

void MSC_SetIOControl(const MSC_HandleType *pMscHandle, const MSC_IOControlInitType *pIOConfig)
{

#if MSC_DEV_ERROR_REPORT == STD_ON
    if (pMscHandle == NULL)
    {
        MSC_ReportDevError(MSC_SET_IO_CONTROL_ID, MSC_E_PARAM_POINTER);
    }
    else if (pMscHandle->eInstance >= MSC_INSTANCE_COUNT)
    {
        MSC_ReportDevError(MSC_SET_IO_CONTROL_ID, MSC_E_PARAM_INSTANCE);
    }
    else
#endif
    {
        uint32_t        u32TempValue = 0;
        MSC_Type *const pMsc         = s_apMscBase[pMscHandle->eInstance];

        u32TempValue |= MSC_IOCR_IDS(pIOConfig->eSDIsel);
        u32TempValue |= MSC_IOCR_ESC(pIOConfig->eENCSel);
        u32TempValue |= MSC_IOCR_ESH(pIOConfig->eENHSel);
        u32TempValue |= MSC_IOCR_ESL(pIOConfig->eENLSel);
        u32TempValue |= MSC_IOCR_FCLCTRL(pIOConfig->eFclCtrl);
        u32TempValue |= MSC_IOCR_IPS(pIOConfig->eSDIPol);
        u32TempValue |= MSC_IOCR_ENP(pIOConfig->eENXPol);
        u32TempValue |= MSC_IOCR_SOP(pIOConfig->eSOPPol);
        u32TempValue |= MSC_IOCR_FCLP(pIOConfig->eFCLPPol);

        MSC_HWA_SetIocr(pMsc, u32TempValue);
    }
}

void MSC_Enable(const MSC_HandleType *pMscHandle)
{

#if MSC_DEV_ERROR_REPORT == STD_ON
    if (pMscHandle == NULL)
    {
        MSC_ReportDevError(MSC_ENABLE_ID, MSC_E_PARAM_POINTER);
    }
    else if (pMscHandle->eInstance >= MSC_INSTANCE_COUNT)
    {
        MSC_ReportDevError(MSC_ENABLE_ID, MSC_E_PARAM_INSTANCE);
    }
    else
#endif
    {
        MSC_Type *const pMsc = s_apMscBase[pMscHandle->eInstance];

        MSC_HWA_SetMscEnable(pMsc, true);
    }
}

void MSC_Disable(const MSC_HandleType *pMscHandle)
{

#if MSC_DEV_ERROR_REPORT == STD_ON
    if (pMscHandle == NULL)
    {
        MSC_ReportDevError(MSC_DISABLE_ID, MSC_E_PARAM_POINTER);
    }
    else if (pMscHandle->eInstance >= MSC_INSTANCE_COUNT)
    {
        MSC_ReportDevError(MSC_DISABLE_ID, MSC_E_PARAM_INSTANCE);
    }
    else
#endif
    {
        MSC_Type *const pMsc = s_apMscBase[pMscHandle->eInstance];

        MSC_HWA_SetMscEnable(pMsc, false);
    }
}

void MSC_SetDataFrame(const MSC_HandleType *pMscHandle, uint32_t u32Data)
{

#if MSC_DEV_ERROR_REPORT == STD_ON
    if (pMscHandle == NULL)
    {
        MSC_ReportDevError(MSC_SET_DATA_FRAME_ID, MSC_E_PARAM_POINTER);
    }
    else if (pMscHandle->eInstance >= MSC_INSTANCE_COUNT)
    {
        MSC_ReportDevError(MSC_SET_DATA_FRAME_ID, MSC_E_PARAM_INSTANCE);
    }
    else
#endif
    {
        MSC_Type *const pMsc = s_apMscBase[pMscHandle->eInstance];

        MSC_HWA_SetTcdar(pMsc, u32Data);
    }
}

void MSC_SendDataFrame(const MSC_HandleType *pMscHandle)
{

#if MSC_DEV_ERROR_REPORT == STD_ON
    if (pMscHandle == NULL)
    {
        MSC_ReportDevError(MSC_SEND_DATA_FRAME_ID, MSC_E_PARAM_POINTER);
    }
    else if (pMscHandle->eInstance >= MSC_INSTANCE_COUNT)
    {
        MSC_ReportDevError(MSC_SEND_DATA_FRAME_ID, MSC_E_PARAM_INSTANCE);
    }
    else
#endif
    {
        MSC_Type *const pMsc = s_apMscBase[pMscHandle->eInstance];
        MSC_HWA_SetDataNeedSend(pMsc);
    }
}

void MSC_SendCommandFrame(const MSC_HandleType *pMscHandle, uint32_t u32Command)
{

#if MSC_DEV_ERROR_REPORT == STD_ON
    if (pMscHandle == NULL)
    {
        MSC_ReportDevError(MSC_SEND_COMMAND_FRAME_ID, MSC_E_PARAM_POINTER);
    }
    else if (pMscHandle->eInstance >= MSC_INSTANCE_COUNT)
    {
        MSC_ReportDevError(MSC_SEND_COMMAND_FRAME_ID, MSC_E_PARAM_INSTANCE);
    }
    else
#endif
    {
        MSC_Type *const pMsc = s_apMscBase[pMscHandle->eInstance];

        MSC_HWA_SetTccor(pMsc, u32Command);
    }
}

uint8_t MSC_GetReceivedFrameAddr(const MSC_HandleType *pMscHandle, MSC_RDRxIndexType eIndex)
{
    uint8_t result = 0U;

#if MSC_DEV_ERROR_REPORT == STD_ON
    if (pMscHandle == NULL)
    {
        MSC_ReportDevError(MSC_GET_RECEIVED_FRAME_ADDR_ID, MSC_E_PARAM_POINTER);
    }
    else if (pMscHandle->eInstance >= MSC_INSTANCE_COUNT)
    {
        MSC_ReportDevError(MSC_GET_RECEIVED_FRAME_ADDR_ID, MSC_E_PARAM_INSTANCE);
    }
    else if (eIndex >= MSC_RDRx_COUNT)
    {
        MSC_ReportDevError(MSC_GET_RECEIVED_FRAME_ADDR_ID, MSC_E_PARAM_RXINDEX);
    }
    else
#endif
    {
        MSC_Type *const pMsc   = s_apMscBase[pMscHandle->eInstance];

        if (eIndex == MSC_RDR0)
        {
            result = MSC_HWA_GetRdr0Addr(pMsc);
        }
        else if (eIndex == MSC_RDR1)
        {
            result = MSC_HWA_GetRdr1Addr(pMsc);
        }
        else if (eIndex == MSC_RDR2)
        {
            result = MSC_HWA_GetRdr2Addr(pMsc);
        }
        else if (eIndex == MSC_RDR3)
        {
            result = MSC_HWA_GetRdr3Addr(pMsc);
        }
    }

    return result;
}

MSC_ReceiveStatusType MSC_GetReceivedFrame(const MSC_HandleType *pMscHandle, MSC_RDRxIndexType eIndex, uint8_t *pData)
{
    MSC_ReceiveStatusType result = MSC_RSV_ERROR;

#if MSC_DEV_ERROR_REPORT == STD_ON
    if (pMscHandle == NULL)
    {
        MSC_ReportDevError(MSC_GET_RECEIVED_FRAME_ID, MSC_E_PARAM_POINTER);
    }
    else if (pMscHandle->eInstance >= MSC_INSTANCE_COUNT)
    {
        MSC_ReportDevError(MSC_GET_RECEIVED_FRAME_ID, MSC_E_PARAM_INSTANCE);
    }
    else if (eIndex >= MSC_RDRx_COUNT)
    {
        MSC_ReportDevError(MSC_GET_RECEIVED_FRAME_ID, MSC_E_PARAM_RXINDEX);
    }
    else
#endif
    {
        MSC_Type *const       pMsc       = s_apMscBase[pMscHandle->eInstance];

        if (eIndex == MSC_RDR0)
        {
            result = MSC_HWA_GetRdr0Rerr(pMsc);
            if (MSC_RSV_SUCCESS == result)
            {
                *pData = MSC_HWA_GetRdr0Data(pMsc);
            }
        }
        else if (eIndex == MSC_RDR1)
        {
            result = MSC_HWA_GetRdr1Rerr(pMsc);
            if (MSC_RSV_SUCCESS == result)
            {
                *pData = MSC_HWA_GetRdr1Data(pMsc);
            }
        }
        else if (eIndex == MSC_RDR2)
        {
            result = MSC_HWA_GetRdr2Rerr(pMsc);
            if (MSC_RSV_SUCCESS == result)
            {
                *pData = MSC_HWA_GetRdr2Data(pMsc);
            }
        }
        else if (eIndex == MSC_RDR3)
        {
            result = MSC_HWA_GetRdr3Rerr(pMsc);
            if (MSC_RSV_SUCCESS == result)
            {
                *pData = MSC_HWA_GetRdr3Data(pMsc);
            }
        }
    }

    return result;
}

uint32_t MSC_GetToInterruptStatus(const MSC_HandleType *pMscHandle)
{
    uint32_t result = 0U;

#if MSC_DEV_ERROR_REPORT == STD_ON
    if (pMscHandle == NULL)
    {
        MSC_ReportDevError(MSC_GET_INTERRUPT_STATUS_ID, MSC_E_PARAM_POINTER);
    }
    else if (pMscHandle->eInstance >= MSC_INSTANCE_COUNT)
    {
        MSC_ReportDevError(MSC_GET_INTERRUPT_STATUS_ID, MSC_E_PARAM_INSTANCE);
    }
    else
#endif
    {
        MSC_Type *const pMsc = s_apMscBase[pMscHandle->eInstance];
        result = MSC_HWA_GetRtor(pMsc);
    }

    return result;
}

uint32_t MSC_GetInterruptStatus(const MSC_HandleType *pMscHandle)
{
    uint32_t result = 0U;

#if MSC_DEV_ERROR_REPORT == STD_ON
    if (pMscHandle == NULL)
    {
        MSC_ReportDevError(MSC_GET_INTERRUPT_STATUS_ID, MSC_E_PARAM_POINTER);
    }
    else if (pMscHandle->eInstance >= MSC_INSTANCE_COUNT)
    {
        MSC_ReportDevError(MSC_GET_INTERRUPT_STATUS_ID, MSC_E_PARAM_INSTANCE);
    }
    else
#endif
    {
        MSC_Type *const pMsc = s_apMscBase[pMscHandle->eInstance];
        result = MSC_HWA_GetInsr(pMsc);
    }

    return result;
}

void MSC_EnableTrasmit(const MSC_HandleType *pMscHandle, bool bEnable)
{

#if MSC_DEV_ERROR_REPORT == STD_ON
    if (pMscHandle == NULL)
    {
        MSC_ReportDevError(MSC_ENABLE_TRANSMIT_ID, MSC_E_PARAM_POINTER);
    }
    else if (pMscHandle->eInstance >= MSC_INSTANCE_COUNT)
    {
        MSC_ReportDevError(MSC_ENABLE_TRANSMIT_ID, MSC_E_PARAM_INSTANCE);
    }
    else
#endif
    {
        MSC_Type *const pMsc = s_apMscBase[pMscHandle->eInstance];

        if (bEnable)
        {
            MSC_HWA_ClearTcdis(pMsc);
        }
        else
        {
            MSC_HWA_SetTcdis(pMsc);
        }
    }
}

void MSC_ClearReceiveInterruptFlag(const MSC_HandleType *pMscHandle)
{

#if MSC_DEV_ERROR_REPORT == STD_ON
    if (pMscHandle == NULL)
    {
        MSC_ReportDevError(MSC_CLEAR_RECEIVE_INTERRUPT_FLAG_ID, MSC_E_PARAM_POINTER);
    }
    else if (pMscHandle->eInstance >= MSC_INSTANCE_COUNT)
    {
        MSC_ReportDevError(MSC_CLEAR_RECEIVE_INTERRUPT_FLAG_ID, MSC_E_PARAM_INSTANCE);
    }
    else
#endif
    {
        MSC_Type *const pMsc = s_apMscBase[pMscHandle->eInstance];

        MSC_HWA_ClearCrfi(pMsc);
    }
}

void MSC_ClearTimeFrameInterruptFlag(const MSC_HandleType *pMscHandle)
{

#if MSC_DEV_ERROR_REPORT == STD_ON
    if (pMscHandle == NULL)
    {
        MSC_ReportDevError(MSC_CLEAR_TIME_FRAME_INTERRUPT_FLAG_ID, MSC_E_PARAM_POINTER);
    }
    else if (pMscHandle->eInstance >= MSC_INSTANCE_COUNT)
    {
        MSC_ReportDevError(MSC_CLEAR_TIME_FRAME_INTERRUPT_FLAG_ID, MSC_E_PARAM_INSTANCE);
    }
    else
#endif
    {
        MSC_Type *const pMsc = s_apMscBase[pMscHandle->eInstance];

        MSC_HWA_ClearCtfi(pMsc);
    }
}

void MSC_ClearCommandFrameInterruptFlag(const MSC_HandleType *pMscHandle)
{

#if MSC_DEV_ERROR_REPORT == STD_ON
    if (pMscHandle == NULL)
    {
        MSC_ReportDevError(MSC_CLEAR_COMMAND_FRAME_INTERRUPT_FLAG_ID, MSC_E_PARAM_POINTER);
    }
    else if (pMscHandle->eInstance >= MSC_INSTANCE_COUNT)
    {
        MSC_ReportDevError(MSC_CLEAR_COMMAND_FRAME_INTERRUPT_FLAG_ID, MSC_E_PARAM_INSTANCE);
    }
    else
#endif
    {
        MSC_Type *const pMsc = s_apMscBase[pMscHandle->eInstance];

        MSC_HWA_ClearCcfi(pMsc);
    }
}

void MSC_ClearDataFrameInterruptFlag(const MSC_HandleType *pMscHandle)
{
#if MSC_DEV_ERROR_REPORT == STD_ON
    if (pMscHandle == NULL)
    {
        MSC_ReportDevError(MSC_CLEAR_DATA_FRAME_INTERRUPT_FLAG_ID, MSC_E_PARAM_POINTER);
    }
    else if (pMscHandle->eInstance >= MSC_INSTANCE_COUNT)
    {
        MSC_ReportDevError(MSC_CLEAR_DATA_FRAME_INTERRUPT_FLAG_ID, MSC_E_PARAM_INSTANCE);
    }
    else
#endif
    {
        MSC_Type *const pMsc = s_apMscBase[pMscHandle->eInstance];

        MSC_HWA_ClearCdfi(pMsc);
    }
}

void MSC_ClearTimeoutInterruptFlag(const MSC_HandleType *pMscHandle)
{
#if MSC_DEV_ERROR_REPORT == STD_ON
    if (pMscHandle == NULL)
    {
        MSC_ReportDevError(MSC_CLEAR_TIMEOUT_INTERRUPT_FLAG_ID, MSC_E_PARAM_POINTER);
    }
    else if (pMscHandle->eInstance >= MSC_INSTANCE_COUNT)
    {
        MSC_ReportDevError(MSC_CLEAR_TIMEOUT_INTERRUPT_FLAG_ID, MSC_E_PARAM_INSTANCE);
    }
    else
#endif
    {
        MSC_Type *const pMsc = s_apMscBase[pMscHandle->eInstance];

        MSC_HWA_SetRtor(pMsc, MSC_HWA_GetRtor(pMsc) | MSC_RTOR_TOFC_MASK);
    }
}
#endif /* #if MSC_INSTANCE_COUNT > 0U */
