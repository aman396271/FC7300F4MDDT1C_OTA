/**
 * @file module_driver_sent.c
 * @author Flagchip
 * @brief SENT driver source code
 * @version 2.0.0
 * @date 2022-12-30
 *
 * SDK Version: 2.6.0
 *

 * @copyright Copyright (c) 2020-2024 Flagchip Semiconductors Co., Ltd.
 *
 */
/* ********************************************************************************
   *   Revision History:
   *
   *   Version     Date          Author        CR#          Descriptions
   *   ---------   ----------    ------------  ----------   ---------------
   *   0.1.0       2022-12-14    Flagchip      N/A          First version for FC7300 SENT
   *   0.2.0       2022-12-30    Flagchip      N/A          Support SPC mode for SENT
   ******************************************************************************** */

#include "module_driver_sent.h"

#if SENT_INSTANCE_COUNT > 0U

#define SENT_GLBL_CTL_PRESCALER_MAX   255U

#if (DEVICE_TYPE == MCU_FC7300F4MDD_T1C)
#define SENT_GLBL_CTL_WATERMARK_MAX   4U
#else
#define SENT_GLBL_CTL_WATERMARK_MAX   16U
#endif

#ifndef SENT_DEV_ERROR_REPORT
#define SENT_DEV_ERROR_REPORT    STD_OFF
#endif

#if SENT_DEV_ERROR_REPORT == STD_ON
#define SENT_ReportDevError(func, error) ReportDevError(SENT_MODULE_ID, func, error)
#endif

static SENT_Type* const aSent_Base[] = SENT_BASE_PTRS;

void SENT_InterruptProcess(const Sent_HandleType *pSentHandle)
{
    uint8_t u8Channel;
    uint32_t u32ChannelStatus;
    SENT_Type *pSent  = aSent_Base[pSentHandle->eInstance];


    for(u8Channel = 0U; u8Channel < SENT_CHANNEL_COUNT; u8Channel++)
    {
        if(true == SENT_HWA_GetChannelReceive(pSent, u8Channel))
        {
            if(true == SENT_HWA_GetSLowMessageUnderflowFlag(pSent, u8Channel))
            {
                if(NULL != pSentHandle->tSettings.pGBCallback)
                {
                    SENT_HWA_ClearSLowMessageUnderflowFlag(pSent, u8Channel);
                    pSentHandle->tSettings.pGBCallback((Sent_ChannelType)u8Channel, SENT_SLOW_MSG_DMA_UF_IT);
                }
            }
            if(true == SENT_HWA_GetFastMessageReadyFlag(pSent, u8Channel))
            {
                if(NULL != pSentHandle->tSettings.pGBCallback)
                {
                    SENT_HWA_ClearFastMessageReadyFlag(pSent, u8Channel);
                    pSentHandle->tSettings.pGBCallback((Sent_ChannelType)u8Channel, SENT_FAST_MSG_READY_IT);
                }
            }
            if(true == SENT_HWA_GetSlowMessageReadyFlag(pSent, u8Channel))
            {
                if(NULL != pSentHandle->tSettings.pGBCallback)
                {
                    SENT_HWA_ClearSlowMessageReadyFlag(pSent, u8Channel);
                    pSentHandle->tSettings.pGBCallback((Sent_ChannelType)u8Channel, SENT_SLOW_MSG_READY_IT);
                }
            }
            if(true == SENT_HWA_GetFastMessageFIFOOverflowFlag(pSent, u8Channel))
            {
                if(NULL != pSentHandle->tSettings.pGBCallback)
                {
                    SENT_HWA_ClearFastMessageFIFOOverflowFlag(pSent, u8Channel);
                    pSentHandle->tSettings.pGBCallback((Sent_ChannelType)u8Channel, SENT_FAST_MSG_FIFO_OF_IT);
                }
            }
            if(true == SENT_HWA_GetFastMessageDMAUnderflowFlag(pSent, u8Channel))
            {
                if(NULL != pSentHandle->tSettings.pGBCallback)
                {
                    SENT_HWA_ClearFastMessageDMAUnderflowFlag(pSent, u8Channel);
                    pSentHandle->tSettings.pGBCallback((Sent_ChannelType)u8Channel, SENT_FAST_MSG_DMA_DF_IT);
                }
            }
            u32ChannelStatus = SENT_HWA_GetChannelStatus(pSent, u8Channel);
            if(0U != u32ChannelStatus)
            {
                if(NULL != pSentHandle->tSettings.pCHCallback)
                {
                    SENT_HWA_ClearChannelStatus(pSent, u8Channel, u32ChannelStatus);
                    pSentHandle->tSettings.pCHCallback((Sent_ChannelType)u8Channel, u32ChannelStatus);
                }
            }
        }
    }
}

void SENT_Init(Sent_HandleType *pSentHandle, const Sent_ConfigType *pCfg)
{
    SENT_Type *pSent;

#if SENT_DEV_ERROR_REPORT == STD_ON
    if (pSentHandle == NULL || pCfg == NULL)
    {
        SENT_ReportDevError(SENT_INIT_ID, SENT_E_PARAM_POINTER);
    }
    else if (false != pSentHandle->tStatus.bInitStatus)
    {
    	SENT_ReportDevError(SENT_INIT_ID, SENT_E_ALREADY_INIT);
    }
    else if (pSentHandle->eInstance >= SENT_INSTANCE_MAX)
    {
    	SENT_ReportDevError(SENT_INIT_ID, SENT_E_PARAM_INSTANCE);
    }
    else if ((pCfg->u8DmaWaterMark > SENT_GLBL_CTL_WATERMARK_MAX) || (pCfg->u8PreScaler >= SENT_GLBL_CTL_PRESCALER_MAX))
    {
    	SENT_ReportDevError(SENT_INIT_ID, SENT_E_PARAM_GENERAL);
    }
    else
    {
#endif
		pSent = aSent_Base[pSentHandle->eInstance];

		SENT_HWA_SetGlobalPreScaler(pSent, pCfg->u8PreScaler);
		SENT_HWA_SetDMAWaterMark(pSent, pCfg->u8DmaWaterMark);
		if(true == pCfg->bDebugModeEn)
		{
			SENT_HWA_EnableDebugMode(pSent);
		}
		else
		{
			SENT_HWA_DisableDebugMode(pSent);
		}
		if(true == pCfg->bAutoClearReadyFlag)
		{
			SENT_HWA_EnableDataOverflowFlagFastClear(pSent);
		}
		else
		{
			SENT_HWA_DisableDataOverflowFlagFastClear(pSent);
		}
		pSentHandle->tSettings.pGBCallback = pCfg->pGBCallback;
		pSentHandle->tSettings.pCHCallback = pCfg->pCHCallback;
		SENT_HWA_EnableGlobal(pSent);
		pSentHandle->tStatus.bInitStatus = true;

#if SENT_DEV_ERROR_REPORT == STD_ON
    }
#endif

    return;
}

void SENT_SetChannelConfig(const Sent_HandleType *pSentHandle, const Sent_ChannelType eChannel, const Sent_ChannelConfigType *pCfg)
{
    SENT_Type *pSent;

#if SENT_DEV_ERROR_REPORT == STD_ON
    if (pSentHandle == NULL || pCfg == NULL)
    {
        SENT_ReportDevError(SENT_SET_CHANNEL_CONFIG_ID, SENT_E_PARAM_POINTER);
    }
    else if (false == pSentHandle->tStatus.bInitStatus)
    {
    	SENT_ReportDevError(SENT_SET_CHANNEL_CONFIG_ID, SENT_E_UNINIT);
    }
    else if (pSentHandle->eInstance >= SENT_INSTANCE_MAX)
    {
    	SENT_ReportDevError(SENT_SET_CHANNEL_CONFIG_ID, SENT_E_PARAM_INSTANCE);
    }
    else if (eChannel >= SENT_CHANNEL_MAX)
    {
    	SENT_ReportDevError(SENT_SET_CHANNEL_CONFIG_ID, SENT_E_PARAM_CHANNEL);
    }
    else if ((true == pCfg->bChannelEn) && ((pCfg->u8DataNibbleNumber <= 0U) || (pCfg->u8DataNibbleNumber >= 6U)))
    {
    	SENT_ReportDevError(SENT_SET_CHANNEL_CONFIG_ID, SENT_E_PARAM_GENERAL);
    }
    else
    {
#endif

		pSent = aSent_Base[pSentHandle->eInstance];
		if(true == pCfg->bChannelEn)
		{
			SENT_HWA_DisableChannelReceive(pSent, (uint8_t)eChannel);

			SENT_HWA_SetChannelIdleCount(pSent, (uint8_t)eChannel, (uint8_t)pCfg->eIdleCount);
			SENT_HWA_SetChannelDigitalFilterCount(pSent, (uint8_t)eChannel, pCfg->u8DigitalFilterCount);
			SENT_HWA_SetChannelNibbleNumber(pSent, (uint8_t)eChannel, pCfg->u8DataNibbleNumber);
			SENT_HWA_SetChannelPreScaler(pSent, (uint8_t)eChannel, (uint16_t)pCfg->u16TickScaler);
			SENT_HWA_SetChannelNibbleDataMode(pSent, (uint8_t)eChannel, (SENT_NibbleDataModeType)(pCfg->eDataNibbleMode));

			if(SENT_CALIBRATION_PULSE_DIAG_OPTION1 != pCfg->eCalDiagOption)
			{
				SENT_HWA_DisableChannelSPCOption1(pSent, (uint8_t)eChannel);
			}
			else
			{
				SENT_HWA_EnableChannelSPCOption1(pSent, (uint8_t)eChannel);
			}
			if(true == pCfg->bPausePulseEn)
			{
				SENT_HWA_EnableChannelPausePulse(pSent, (uint8_t)eChannel);
			}
			else
			{
				SENT_HWA_DisableChannelPausePulse(pSent, (uint8_t)eChannel);
			}
			if(true == pCfg->bTickCompensateEn)
			{
				SENT_HWA_EnableChannelCompensate(pSent, (uint8_t)eChannel);
			}
			else
			{
				SENT_HWA_DisableChannelCompensate(pSent, (uint8_t)eChannel);
			}

			if(true == pCfg->bFastMessageFifoEn)
			{
				SENT_HWA_EnableChannelFIFO(pSent, (uint8_t)eChannel);
			}
			else
			{
				SENT_HWA_DisableChannelFIFO(pSent, (uint8_t)eChannel);
			}

			if(true == pCfg->bFastMsgCRCAugEn)
			{
				SENT_HWA_EnableChannelFastMessageAugmentation(pSent, (uint8_t)eChannel);
			}
			else
			{
				SENT_HWA_DisableChannelFastMessageAugmentation(pSent, (uint8_t)eChannel);
			}

			if(true == pCfg->bFastMsgCRCCheckEn)
			{
				SENT_HWA_EnableChannelFastMessageCRCCheck(pSent, (uint8_t)eChannel);
			}
			else
			{
				SENT_HWA_DisableChannelFastMessageCRCCheck(pSent, (uint8_t)eChannel);
			}

			if(true == pCfg->bFastMsgCRCWithSCEn)
			{
				SENT_HWA_EnableChannelFastMessageCRCWithSC(pSent, (uint8_t)eChannel);
			}
			else
			{
				SENT_HWA_DisableChannelFastMessageCRCWithSC(pSent, (uint8_t)eChannel);
			}

			if(true == pCfg->bFastMsgDataChangeEn)
			{
				SENT_HWA_EnableChannelFastMessageDataChange(pSent, (uint8_t)eChannel);
			}
			else
			{
				SENT_HWA_DisableChannelFastMessageDataChange(pSent, (uint8_t)eChannel);
			}


			if(true == pCfg->bSlowMsgCRCAugEn)
			{
				SENT_HWA_EnableChannelSlowMessageAugmentation(pSent, (uint8_t)eChannel);
			}
			else
			{
				SENT_HWA_DisableChannelSlowMessageAugmentation(pSent, (uint8_t)eChannel);
			}

			if(true == pCfg->bUseAlternativeCrc)
			{
				SENT_HWA_EnableChannelAltCRC(pSent, (uint8_t)eChannel);
			}
			else
			{
				SENT_HWA_DisableChannelAltCRC(pSent, (uint8_t)eChannel);
			}

			if(SENT_CALIBRATION_VALID_WITHIN_20 == pCfg->eCalValid)
			{
				SENT_HWA_DisableChannelCalValid20To25(pSent, (uint8_t)eChannel);
				SENT_HWA_EnableChannelCalValidDiagnostic(pSent, (uint8_t)eChannel);
			}
			else if(SENT_CALIBRATION_VALID_FROM_20_TO_25 == pCfg->eCalValid)
			{
				SENT_HWA_EnableChannelCalValid20To25(pSent, (uint8_t)eChannel);
				SENT_HWA_EnableChannelCalValidDiagnostic(pSent, (uint8_t)eChannel);
			}
			else
			{
				SENT_HWA_DisableChannelCalValid20To25(pSent, (uint8_t)eChannel);
				SENT_HWA_DisableChannelCalValidDiagnostic(pSent, (uint8_t)eChannel);
			}
			SENT_HWA_EnableChannelReceive(pSent, (uint8_t)eChannel);
		}
		else
		{
			SENT_HWA_DisableChannelReceive(pSent, (uint8_t)eChannel);
		}

#if SENT_DEV_ERROR_REPORT == STD_ON
    }
#endif

    return;
}

void SENT_SetDMAConfig(const Sent_HandleType *pSentHandle, const Sent_ChannelType eChannel, Sent_DMAConfigType *pCfg)
{
    SENT_Type *pSent;

#if SENT_DEV_ERROR_REPORT == STD_ON
    if (pSentHandle == NULL || pCfg == NULL)
    {
        SENT_ReportDevError(SENT_SET_DMA_CONFIG_ID, SENT_E_PARAM_POINTER);
    }
    else if (false == pSentHandle->tStatus.bInitStatus)
    {
    	SENT_ReportDevError(SENT_SET_DMA_CONFIG_ID, SENT_E_UNINIT);
    }
    else if (pSentHandle->eInstance >= SENT_INSTANCE_MAX)
    {
    	SENT_ReportDevError(SENT_SET_DMA_CONFIG_ID, SENT_E_PARAM_INSTANCE);
    }
    else if (eChannel >= SENT_CHANNEL_MAX)
    {
    	SENT_ReportDevError(SENT_SET_DMA_CONFIG_ID, SENT_E_PARAM_CHANNEL);
    }
    else
    {
#endif

		pSent = aSent_Base[pSentHandle->eInstance];

		if(true == pCfg->bFastMsgDmaEn)
		{
			SENT_HWA_EnableChannelFastMessageDmaRequest(pSent, (uint8_t)eChannel);
		}
		else
		{
			SENT_HWA_DisableChannelFastMessageDmaRequest(pSent, (uint8_t)eChannel);
		}

		if(true == pCfg->bSlowMsgDmaEn)
		{
			SENT_HWA_EnableChannelSlowMessageDmaRequest(pSent, (uint8_t)eChannel);
		}
		else
		{
			SENT_HWA_DisableChannelSlowMessageDmaRequest(pSent, (uint8_t)eChannel);
		}

#if SENT_DEV_ERROR_REPORT == STD_ON
    }
#endif

    return;
}

void SENT_SetSPCConfig(const Sent_HandleType *pSentHandle, const Sent_ChannelType eChannel, const Sent_SpcConfigType *pCfg)
{
    SENT_Type *pSent;

#if SENT_DEV_ERROR_REPORT == STD_ON
    if (pSentHandle == NULL || pCfg == NULL)
    {
        SENT_ReportDevError(SENT_SET_SPC_CONFIG_ID, SENT_E_PARAM_POINTER);
    }
    else if (false == pSentHandle->tStatus.bInitStatus)
    {
    	SENT_ReportDevError(SENT_SET_SPC_CONFIG_ID, SENT_E_UNINIT);
    }
    else if (pSentHandle->eInstance >= SENT_INSTANCE_MAX)
    {
    	SENT_ReportDevError(SENT_SET_SPC_CONFIG_ID, SENT_E_PARAM_INSTANCE);
    }
    else if (eChannel >= SENT_CHANNEL_MAX)
    {
    	SENT_ReportDevError(SENT_SET_SPC_CONFIG_ID, SENT_E_PARAM_CHANNEL);
    }
    else
    {
#endif

		pSent = aSent_Base[pSentHandle->eInstance];

		SENT_HWA_DisableChannelSPCMode(pSent, (uint8_t)eChannel);
		SENT_HWA_SetChannelSPCTickBase(pSent, (uint8_t)eChannel, (SENT_SPCTickType)(pCfg->eSpcTickBase));
		SENT_HWA_SetChannelSPCTriggerMethod(pSent, (uint8_t)eChannel, (SENT_SPCTriggerType)(pCfg->eSpcTrigger));
		SENT_HWA_SetChannelSPCPulseDelay(pSent, (uint8_t)eChannel, pCfg->u8PulseDelay);
		SENT_HWA_SetChannelSPCPulseWidth(pSent, (uint8_t)eChannel, pCfg->u8PulseWidth);
		if(true == pCfg->bCalDiagEn)
		{
			SENT_HWA_EnableChannelCalibrationDiag(pSent, (uint8_t)eChannel);
		}
		else
		{
			SENT_HWA_DisableChannelCalibrationDiag(pSent, (uint8_t)eChannel);
		}
		if(true == pCfg->bSpcModeEn)
		{
			SENT_HWA_EnableChannelSPCMode(pSent, (uint8_t)eChannel);
		}
		else
		{
			SENT_HWA_DisableChannelSPCMode(pSent, (uint8_t)eChannel);
		}

#if SENT_DEV_ERROR_REPORT == STD_ON
    }
#endif

    return;
}

void SENT_GetFastMessageData(const Sent_HandleType *pSentHandle, const Sent_ChannelType eChannel, Sent_FastMessageDataType *pMsg)
{
    SENT_Type *pSent;
    uint8_t u8DataShift;

#if SENT_DEV_ERROR_REPORT == STD_ON
    if (pSentHandle == NULL || pMsg == NULL)
    {
        SENT_ReportDevError(SENT_GET_FAST_MSG_ID, SENT_E_PARAM_POINTER);
    }
    else if (false == pSentHandle->tStatus.bInitStatus)
    {
    	SENT_ReportDevError(SENT_GET_FAST_MSG_ID, SENT_E_UNINIT);
    }
    else if (pSentHandle->eInstance >= SENT_INSTANCE_MAX)
    {
    	SENT_ReportDevError(SENT_GET_FAST_MSG_ID, SENT_E_PARAM_INSTANCE);
    }
    else if (eChannel >= SENT_CHANNEL_MAX)
    {
    	SENT_ReportDevError(SENT_GET_FAST_MSG_ID, SENT_E_PARAM_CHANNEL);
    }
    else
    {
#endif

		pSent = aSent_Base[pSentHandle->eInstance];

		pMsg->u8CRC = SENT_HWA_GetChannelFastMessageCRCNibble(pSent, (uint8_t)eChannel);
		pMsg->u8SC = SENT_HWA_GetChannelFastMessageStatusNibble(pSent, (uint8_t)eChannel);
		pMsg->u32Timestamp = SENT_HWA_GetChannelFastMessageTimeStamp(pSent, (uint8_t)eChannel);
		u8DataShift = (uint8_t)((5U - SENT_HWA_GetChannelNibbleNumber(pSent, (uint8_t)eChannel)) << 2U);
		pMsg->u32Data = SENT_HWA_GetChannelDataNibble(pSent, (uint8_t)eChannel) >> (SENT_CHN_FDATA_DATA6_SHIFT + u8DataShift);

#if SENT_DEV_ERROR_REPORT == STD_ON
    }
#endif

    return;
}

void SENT_GetSlowMessageData(const Sent_HandleType *pSentHandle, const Sent_ChannelType eChannel, Sent_SlowMessageDataType *pMsg)
{
    SENT_Type *pSent;

#if SENT_DEV_ERROR_REPORT == STD_ON
    if (pSentHandle == NULL || pMsg == NULL)
    {
        SENT_ReportDevError(SENT_GET_SLOW_MSG_ID, SENT_E_PARAM_POINTER);
    }
    else if (false == pSentHandle->tStatus.bInitStatus)
    {
    	SENT_ReportDevError(SENT_GET_SLOW_MSG_ID, SENT_E_UNINIT);
    }
    else if (pSentHandle->eInstance >= SENT_INSTANCE_MAX)
    {
    	SENT_ReportDevError(SENT_GET_SLOW_MSG_ID, SENT_E_PARAM_INSTANCE);
    }
    else if (eChannel >= SENT_CHANNEL_MAX)
    {
    	SENT_ReportDevError(SENT_GET_SLOW_MSG_ID, SENT_E_PARAM_CHANNEL);
    }
    else
    {
#endif


            pSent = aSent_Base[pSentHandle->eInstance];

            pMsg->eMsgType = (Sent_SerialMessageType)SENT_HWA_GetChannelSLowMessageType(pSent, (uint8_t)eChannel);
            pMsg->u32Timestamp = SENT_HWA_GetChannelSlowMessageTimeStamp(pSent, (uint8_t)eChannel);
            if(SENT_SERIAL_MESSAGE_SHORT == pMsg->eMsgType)
            {
                pMsg->u8CRC = SENT_HWA_GetChannelBit2CRC(pSent, (uint8_t)eChannel) & 0xFU;
                pMsg->u16Data = SENT_HWA_GetChannelBit2DATA(pSent, (uint8_t)eChannel) & 0xFFU;
                pMsg->u8ID = (uint8_t)(SENT_HWA_GetChannelBit2DATA(pSent, (uint8_t)eChannel) >> 8U);
            }
            else if(SENT_SERIAL_MESSAGE_ENHANCE_12DATA_8ID == pMsg->eMsgType)
            {
                pMsg->u8CRC = SENT_HWA_GetChannelBit2CRC(pSent, (uint8_t)eChannel);
                pMsg->u16Data = SENT_HWA_GetChannelBit2DATA(pSent, (uint8_t)eChannel);
                pMsg->u8ID = (uint8_t)((SENT_HWA_GetChannelBit3EnhancedID7_4_OR_ID3_0(pSent, (uint8_t)eChannel) << 4U) | SENT_HWA_GetChannelBit3EnhancedID3_0_OR_DATA15_12(pSent, (uint8_t)eChannel));
            }
            else if(SENT_SERIAL_MESSAGE_ENHANCE_16DATA_4ID == pMsg->eMsgType)
            {
                pMsg->u8CRC = SENT_HWA_GetChannelBit2CRC(pSent, (uint8_t)eChannel);
                pMsg->u16Data = (uint16_t)(((uint16_t)SENT_HWA_GetChannelBit3EnhancedID3_0_OR_DATA15_12(pSent, (uint8_t)eChannel) << 12U) | (uint16_t)SENT_HWA_GetChannelBit2DATA(pSent, (uint8_t)eChannel));
                pMsg->u8ID = SENT_HWA_GetChannelBit3EnhancedID7_4_OR_ID3_0(pSent, (uint8_t)eChannel);
            }
            else
            {
#if SENT_DEV_ERROR_REPORT == STD_ON
            	SENT_ReportDevError(SENT_GET_SLOW_MSG_ID, SENT_E_INVALID_BRANCH);
#endif
            }

#if SENT_DEV_ERROR_REPORT == STD_ON
    }
#endif

    return;
}

void SENT_DecodeFastMessageWithDMABuffer(uint32_t *pDmaBuffer, uint32_t u32BufferLength, Sent_FastMessageDataType *pMsg)
{
#if SENT_DEV_ERROR_REPORT == STD_ON
    if (pDmaBuffer == NULL || pMsg == NULL)
    {
        SENT_ReportDevError(SENT_DECODE_FAST_MSG_ID, SENT_E_PARAM_POINTER);
    }
    else if (12U != u32BufferLength)
    {
    	SENT_ReportDevError(SENT_DECODE_FAST_MSG_ID, SENT_E_PARAM_GENERAL);
    }
    else
    {
#else
    PROCESS_UNUSED_VAR(u32BufferLength);
#endif

        pMsg->u8CRC = (uint8_t)((pDmaBuffer[1] & SENT_CHN_FCRC_CRC_DATA_MASK) >> SENT_CHN_FCRC_CRC_DATA_SHIFT);
        pMsg->u8SC = (uint8_t)((pDmaBuffer[1] & SENT_CHN_FCRC_SC_NB_MASK) >> SENT_CHN_FCRC_SC_NB_SHIFT);
        pMsg->u32Timestamp = ((pDmaBuffer[2] & SENT_CHN_FTS_TIMESTAMP_VAL_MASK) >> SENT_CHN_FTS_TIMESTAMP_VAL_SHIFT);
        pMsg->u32Data = (pDmaBuffer[0] >> SENT_CHN_FDATA_DATA6_SHIFT);

#if SENT_DEV_ERROR_REPORT == STD_ON
    }
#endif

    return;
}

void SENT_DecodeSlowMessageWithDMABuffer(uint32_t *pDmaBuffer, uint32_t u32BufferLength, Sent_SlowMessageDataType *pMsg)
{
#if SENT_DEV_ERROR_REPORT == STD_ON
    if (pDmaBuffer == NULL || pMsg == NULL)
    {
        SENT_ReportDevError(SENT_DECODE_SLOW_MSG_ID, SENT_E_PARAM_POINTER);
    }
    else if (12U != u32BufferLength)
    {
    	SENT_ReportDevError(SENT_DECODE_SLOW_MSG_ID, SENT_E_PARAM_GENERAL);
    }
    else
    {
#else
    PROCESS_UNUSED_VAR(u32BufferLength);
#endif

        if(SENT_CHN_SBIT3__MSG_TYPE_MASK == (pDmaBuffer[0] & SENT_CHN_SBIT3__MSG_TYPE_MASK))
        {
            if(SENT_CHN_SBIT3__CFG_MASK == (pDmaBuffer[0] & SENT_CHN_SBIT3__CFG_MASK))
            {
                pMsg->eMsgType = (Sent_SerialMessageType)SENT_SERIAL_MESSAGE_ENHANCE_16DATA_4ID;
            }
            else
            {
                pMsg->eMsgType = (Sent_SerialMessageType)SENT_SERIAL_MESSAGE_ENHANCE_12DATA_8ID;
            }
        }
        else
        {
            pMsg->eMsgType = (Sent_SerialMessageType)SENT_SERIAL_MESSAGE_SHORT;
        }
        pMsg->u32Timestamp = ((pDmaBuffer[2] & SENT_CHN_STS_SMSG_TIMESTAMP_MASK) >> SENT_CHN_STS_SMSG_TIMESTAMP_SHIFT);
        if(SENT_SERIAL_MESSAGE_SHORT == pMsg->eMsgType)
        {
            pMsg->u8CRC =(uint8_t)(((pDmaBuffer[1] & SENT_CHN_SBIT2__SMSG_CRC_MASK) >> SENT_CHN_SBIT2__SMSG_CRC_SHIFT) & 0xFU);
            pMsg->u16Data = (uint16_t)(((pDmaBuffer[1] & SENT_CHN_SBIT2__SMSG_DATA_MASK) >> SENT_CHN_SBIT2__SMSG_DATA_SHIFT) & 0xFFU);
            pMsg->u8ID = (uint8_t)(((pDmaBuffer[1] & SENT_CHN_SBIT2__SMSG_DATA_MASK) >> SENT_CHN_SBIT2__SMSG_DATA_SHIFT) >> 8U);
        }
        else if(SENT_SERIAL_MESSAGE_ENHANCE_12DATA_8ID == pMsg->eMsgType)
        {
            pMsg->u8CRC = (uint8_t)((pDmaBuffer[1] & SENT_CHN_SBIT2__SMSG_CRC_MASK) >> SENT_CHN_SBIT2__SMSG_CRC_SHIFT);
            pMsg->u16Data = (uint16_t)((pDmaBuffer[1] & SENT_CHN_SBIT2__SMSG_DATA_MASK) >> SENT_CHN_SBIT2__SMSG_DATA_SHIFT);
            pMsg->u8ID = (uint8_t)((((pDmaBuffer[0] & SENT_CHN_SBIT3__ID7_4_OR_ID3_0_MASK) >> SENT_CHN_SBIT3__ID7_4_OR_ID3_0_SHIFT) << 4U) |\
                                   ((pDmaBuffer[0] & SENT_CHN_SBIT3__ID3_0_OR_DATA15_12_MASK) >> SENT_CHN_SBIT3__ID3_0_OR_DATA15_12_SHIFT));
        }
        else if(SENT_SERIAL_MESSAGE_ENHANCE_16DATA_4ID == pMsg->eMsgType)
        {
            pMsg->u8CRC = (uint8_t)((pDmaBuffer[1] & SENT_CHN_SBIT2__SMSG_CRC_MASK) >> SENT_CHN_SBIT2__SMSG_CRC_SHIFT);
            pMsg->u16Data = (uint16_t)((((pDmaBuffer[0] & SENT_CHN_SBIT3__ID3_0_OR_DATA15_12_MASK) >> SENT_CHN_SBIT3__ID3_0_OR_DATA15_12_SHIFT) << 12U) |\
                                       ((pDmaBuffer[1] & SENT_CHN_SBIT2__SMSG_DATA_MASK) >> SENT_CHN_SBIT2__SMSG_DATA_SHIFT));
            pMsg->u8ID = (uint8_t)((pDmaBuffer[0] & SENT_CHN_SBIT3__ID7_4_OR_ID3_0_MASK) >> SENT_CHN_SBIT3__ID7_4_OR_ID3_0_SHIFT);
        }
        else
        {
#if SENT_DEV_ERROR_REPORT == STD_ON
        	SENT_ReportDevError(SENT_DECODE_SLOW_MSG_ID, SENT_E_INVALID_BRANCH);
#endif
        }

#if SENT_DEV_ERROR_REPORT == STD_ON
    }
#endif

    return;
}

void SENT_EnableGlobalFastMsgNotification(const Sent_HandleType *pSentHandle, const Sent_ChannelType eChannel)
{
    SENT_Type *pSent;

#if SENT_DEV_ERROR_REPORT == STD_ON
    if (pSentHandle == NULL)
    {
        SENT_ReportDevError(SENT_ENABLE_FAST_MSG_NOTIFY_ID, SENT_E_PARAM_POINTER);
    }
    else if (false == pSentHandle->tStatus.bInitStatus)
    {
    	SENT_ReportDevError(SENT_ENABLE_FAST_MSG_NOTIFY_ID, SENT_E_UNINIT);
    }
    else if (pSentHandle->eInstance >= SENT_INSTANCE_MAX)
    {
    	SENT_ReportDevError(SENT_ENABLE_FAST_MSG_NOTIFY_ID, SENT_E_PARAM_INSTANCE);
    }
    else if (eChannel >= SENT_CHANNEL_MAX)
    {
    	SENT_ReportDevError(SENT_ENABLE_FAST_MSG_NOTIFY_ID, SENT_E_PARAM_CHANNEL);
    }
    else
    {
#endif

		pSent = aSent_Base[pSentHandle->eInstance];

		SENT_HWA_EnableChannelFastMessageInterrupt(pSent, (uint8_t)eChannel);

#if SENT_DEV_ERROR_REPORT == STD_ON
    }
#endif

    return;
}

void SENT_DisableGlobalFastMsgNotification(const Sent_HandleType *pSentHandle, const Sent_ChannelType eChannel)
{
    SENT_Type *pSent;

#if SENT_DEV_ERROR_REPORT == STD_ON
    if (pSentHandle == NULL)
    {
        SENT_ReportDevError(SENT_DISABLE_FAST_MSG_NOTIFY_ID, SENT_E_PARAM_POINTER);
    }
    else if (false == pSentHandle->tStatus.bInitStatus)
    {
    	SENT_ReportDevError(SENT_DISABLE_FAST_MSG_NOTIFY_ID, SENT_E_UNINIT);
    }
    else if (pSentHandle->eInstance >= SENT_INSTANCE_MAX)
    {
    	SENT_ReportDevError(SENT_DISABLE_FAST_MSG_NOTIFY_ID, SENT_E_PARAM_INSTANCE);
    }
    else if (eChannel >= SENT_CHANNEL_MAX)
    {
    	SENT_ReportDevError(SENT_DISABLE_FAST_MSG_NOTIFY_ID, SENT_E_PARAM_CHANNEL);
    }
    else
    {
#endif

		pSent = aSent_Base[pSentHandle->eInstance];

		SENT_HWA_DisableChannelFastMessageInterrupt(pSent, (uint8_t)eChannel);

#if SENT_DEV_ERROR_REPORT == STD_ON
    }
#endif

    return;
}

void SENT_EnableGlobalSlowMsgNotification(const Sent_HandleType *pSentHandle, const Sent_ChannelType eChannel)
{
    SENT_Type *pSent;

#if SENT_DEV_ERROR_REPORT == STD_ON
    if (pSentHandle == NULL)
    {
        SENT_ReportDevError(SENT_ENABLE_SLOW_MSG_NOTIFY_ID, SENT_E_PARAM_POINTER);
    }
    else if (false == pSentHandle->tStatus.bInitStatus)
    {
    	SENT_ReportDevError(SENT_ENABLE_SLOW_MSG_NOTIFY_ID, SENT_E_UNINIT);
    }
    else if (pSentHandle->eInstance >= SENT_INSTANCE_MAX)
    {
    	SENT_ReportDevError(SENT_ENABLE_SLOW_MSG_NOTIFY_ID, SENT_E_PARAM_INSTANCE);
    }
    else if (eChannel >= SENT_CHANNEL_MAX)
    {
    	SENT_ReportDevError(SENT_ENABLE_SLOW_MSG_NOTIFY_ID, SENT_E_PARAM_CHANNEL);
    }
    else
    {
#endif

        pSent = aSent_Base[pSentHandle->eInstance];

        SENT_HWA_EnableChannelSlowMessageInterrupt(pSent, (uint8_t)eChannel);

#if SENT_DEV_ERROR_REPORT == STD_ON
    }
#endif

    return;
}

void SENT_DisableGlobalSlowMsgNotification(const Sent_HandleType *pSentHandle, const Sent_ChannelType eChannel)
{
    SENT_Type *pSent;

#if SENT_DEV_ERROR_REPORT == STD_ON
    if (pSentHandle == NULL)
    {
        SENT_ReportDevError(SENT_DISABLE_SLOW_MSG_NOTIFY_ID, SENT_E_PARAM_POINTER);
    }
    else if (false == pSentHandle->tStatus.bInitStatus)
    {
    	SENT_ReportDevError(SENT_DISABLE_SLOW_MSG_NOTIFY_ID, SENT_E_UNINIT);
    }
    else if (pSentHandle->eInstance >= SENT_INSTANCE_MAX)
    {
    	SENT_ReportDevError(SENT_DISABLE_SLOW_MSG_NOTIFY_ID, SENT_E_PARAM_INSTANCE);
    }
    else if (eChannel >= SENT_CHANNEL_MAX)
    {
    	SENT_ReportDevError(SENT_DISABLE_SLOW_MSG_NOTIFY_ID, SENT_E_PARAM_CHANNEL);
    }
    else
    {
#endif

        pSent = aSent_Base[pSentHandle->eInstance];

        SENT_HWA_DisableChannelSlowMessageInterrupt(pSent, (uint8_t)eChannel);

#if SENT_DEV_ERROR_REPORT == STD_ON
    }
#endif

    return;
}

void SENT_EnableGlobalFastFifoMsgNotification(const Sent_HandleType *pSentHandle)
{
    SENT_Type *pSent;

#if SENT_DEV_ERROR_REPORT == STD_ON
    if (pSentHandle == NULL)
    {
        SENT_ReportDevError(SENT_ENABLE_FAST_FIFO_MSG_NOTIFY_ID, SENT_E_PARAM_POINTER);
    }
    else if (false == pSentHandle->tStatus.bInitStatus)
    {
    	SENT_ReportDevError(SENT_ENABLE_FAST_FIFO_MSG_NOTIFY_ID, SENT_E_UNINIT);
    }
    else if (pSentHandle->eInstance >= SENT_INSTANCE_MAX)
    {
    	SENT_ReportDevError(SENT_ENABLE_FAST_FIFO_MSG_NOTIFY_ID, SENT_E_PARAM_INSTANCE);
    }
    else
    {
#endif

		pSent = aSent_Base[pSentHandle->eInstance];

		SENT_HWA_EnableFastMessageFIFOOverflowInterrupt(pSent);

#if SENT_DEV_ERROR_REPORT == STD_ON
    }
#endif

    return;
}

void SENT_DisableGlobalFastFifoMsgNotification(const Sent_HandleType *pSentHandle)
{
    SENT_Type *pSent;

#if SENT_DEV_ERROR_REPORT == STD_ON
    if (pSentHandle == NULL)
    {
        SENT_ReportDevError(SENT_DISABLE_FAST_FIFO_MSG_NOTIFY_ID, SENT_E_PARAM_POINTER);
    }
    else if (false == pSentHandle->tStatus.bInitStatus)
    {
    	SENT_ReportDevError(SENT_DISABLE_FAST_FIFO_MSG_NOTIFY_ID, SENT_E_UNINIT);
    }
    else if (pSentHandle->eInstance >= SENT_INSTANCE_MAX)
    {
    	SENT_ReportDevError(SENT_DISABLE_FAST_FIFO_MSG_NOTIFY_ID, SENT_E_PARAM_INSTANCE);
    }
    else
    {
#endif

		pSent = aSent_Base[pSentHandle->eInstance];

		SENT_HWA_DisableFastMessageFIFOOverflowInterrupt(pSent);

#if SENT_DEV_ERROR_REPORT == STD_ON
    }
#endif

    return;
}

void SENT_ConfigChannelStatusNotification(const Sent_HandleType *pSentHandle, const Sent_ChannelType eChannel, const Sent_ChannelInterruptType *sInterruptEn)
{
    SENT_Type *pSent;

#if SENT_DEV_ERROR_REPORT == STD_ON
    if ((pSentHandle == NULL) || (sInterruptEn == NULL))
    {
        SENT_ReportDevError(SENT_CONFIG_CHANNEL_STATUS_NOITFY_ID, SENT_E_PARAM_POINTER);
    }
    else if (false == pSentHandle->tStatus.bInitStatus)
    {
    	SENT_ReportDevError(SENT_CONFIG_CHANNEL_STATUS_NOITFY_ID, SENT_E_UNINIT);
    }
    else if (pSentHandle->eInstance >= SENT_INSTANCE_MAX)
    {
    	SENT_ReportDevError(SENT_CONFIG_CHANNEL_STATUS_NOITFY_ID, SENT_E_PARAM_INSTANCE);
    }
    else if (eChannel >= SENT_CHANNEL_MAX)
    {
    	SENT_ReportDevError(SENT_CONFIG_CHANNEL_STATUS_NOITFY_ID, SENT_E_PARAM_CHANNEL);
    }
    else
    {
#endif

		pSent = aSent_Base[pSentHandle->eInstance];

		SENT_HWA_EnableChannelBusIdleInterrupt(pSent, (uint8_t)eChannel, sInterruptEn->bBusIdleITEn);
		SENT_HWA_EnableChannelCALDiagInterrupt(pSent, (uint8_t)eChannel, sInterruptEn->bCalDiagErrITEn);
		SENT_HWA_EnableChannelCalFailInterrupt(pSent, (uint8_t)eChannel, sInterruptEn->bCalFailITEn);
		SENT_HWA_EnableChannelCalResyncInterrupt(pSent, (uint8_t)eChannel, sInterruptEn->bCalResyncErrITEn);
		SENT_HWA_EnableChannelEdgeERRInterrupt(pSent, (uint8_t)eChannel, sInterruptEn->bFallingEdgeNumErrITEn);
		SENT_HWA_EnableChannelFCRCInterrupt(pSent, (uint8_t)eChannel, sInterruptEn->bFastMsgCrcErrITEn);
		SENT_HWA_EnableChannelFOVFLInterrupt(pSent, (uint8_t)eChannel, sInterruptEn->bFastMsgOFITEn);
		SENT_HWA_EnableChannelNibbleErrorInterrupt(pSent, (uint8_t)eChannel, sInterruptEn->bNibbleValueErrITEn);
		SENT_HWA_EnableChannelPPDiagInterrupt(pSent, (uint8_t)eChannel, sInterruptEn->bPrePulseDiagErrITEn);
		SENT_HWA_EnableChannelSCRCInterrupt(pSent, (uint8_t)eChannel, sInterruptEn->bSlowMsgCrcErrITEn);
		SENT_HWA_EnableChannelSOVFLInterrupt(pSent, (uint8_t)eChannel, sInterruptEn->bSlowMsgOFITEn);
		SENT_HWA_EnableChannelCalERRInterrupt(pSent, (uint8_t)eChannel, sInterruptEn->bCalErrITEn);
		//SENT_HWA_EnableChannelAllErrorInterrupt(pSent, eChannel);

#if SENT_DEV_ERROR_REPORT == STD_ON
    }
#endif

    return;
}

void SENT_RequestSPCPulse(const Sent_HandleType *pSentHandle, const Sent_ChannelType eChannel)
{
    SENT_Type *pSent;

#if SENT_DEV_ERROR_REPORT == STD_ON
    if (pSentHandle == NULL)
    {
        SENT_ReportDevError(SENT_REQUEST_SPC_PULSE_ID, SENT_E_PARAM_POINTER);
    }
    else if (false == pSentHandle->tStatus.bInitStatus)
    {
    	SENT_ReportDevError(SENT_REQUEST_SPC_PULSE_ID, SENT_E_UNINIT);
    }
    else if (pSentHandle->eInstance >= SENT_INSTANCE_MAX)
    {
    	SENT_ReportDevError(SENT_REQUEST_SPC_PULSE_ID, SENT_E_PARAM_INSTANCE);
    }
    else if (eChannel >= SENT_CHANNEL_MAX)
    {
    	SENT_ReportDevError(SENT_REQUEST_SPC_PULSE_ID, SENT_E_PARAM_CHANNEL);
    }
    else
    {
#endif

		pSent = aSent_Base[pSentHandle->eInstance];

		SENT_HWA_StartChannelSPC(pSent, (uint8_t)eChannel);

#if SENT_DEV_ERROR_REPORT == STD_ON
    }
#endif

    return;
}

void SENT_GetFastMsgReadyFlag(const Sent_HandleType *pSentHandle, const Sent_ChannelType eChannel, bool *pFlag)
{
    SENT_Type *pSent;

#if SENT_DEV_ERROR_REPORT == STD_ON
    if ((pSentHandle == NULL) || (pFlag == NULL))
    {
        SENT_ReportDevError(SENT_GET_FAST_MSG_READY_FLAG_ID, SENT_E_PARAM_POINTER);
    }
    else if (false == pSentHandle->tStatus.bInitStatus)
    {
    	SENT_ReportDevError(SENT_GET_FAST_MSG_READY_FLAG_ID, SENT_E_UNINIT);
    }
    else if (pSentHandle->eInstance >= SENT_INSTANCE_MAX)
    {
    	SENT_ReportDevError(SENT_GET_FAST_MSG_READY_FLAG_ID, SENT_E_PARAM_INSTANCE);
    }
    else if (eChannel >= SENT_CHANNEL_MAX)
    {
    	SENT_ReportDevError(SENT_GET_FAST_MSG_READY_FLAG_ID, SENT_E_PARAM_CHANNEL);
    }
    else
    {
#endif

		pSent = aSent_Base[pSentHandle->eInstance];

		*pFlag = SENT_HWA_GetFastMessageReadyFlag(pSent, (uint8_t)eChannel);

#if SENT_DEV_ERROR_REPORT == STD_ON
    }
#endif

    return;
}

void SENT_GetSlowMsgReadyFlag(const Sent_HandleType *pSentHandle, const Sent_ChannelType eChannel, bool *pFlag)
{
    SENT_Type *pSent;

#if SENT_DEV_ERROR_REPORT == STD_ON
    if ((pSentHandle == NULL) || (pFlag == NULL))
    {
        SENT_ReportDevError(SENT_GET_SLOW_MSG_READY_FLAG_ID, SENT_E_PARAM_POINTER);
    }
    else if (false == pSentHandle->tStatus.bInitStatus)
    {
    	SENT_ReportDevError(SENT_GET_SLOW_MSG_READY_FLAG_ID, SENT_E_UNINIT);
    }
    else if (pSentHandle->eInstance >= SENT_INSTANCE_MAX)
    {
    	SENT_ReportDevError(SENT_GET_SLOW_MSG_READY_FLAG_ID, SENT_E_PARAM_INSTANCE);
    }
    else if (eChannel >= SENT_CHANNEL_MAX)
    {
    	SENT_ReportDevError(SENT_GET_SLOW_MSG_READY_FLAG_ID, SENT_E_PARAM_CHANNEL);
    }
    else
    {
#endif

		pSent = aSent_Base[pSentHandle->eInstance];

		*pFlag = SENT_HWA_GetSlowMessageReadyFlag(pSent, (uint8_t)eChannel);

#if SENT_DEV_ERROR_REPORT == STD_ON
    }
#endif

    return;
}

void SENT_GetChannelStatus(const Sent_HandleType *pSentHandle, const Sent_ChannelType eChannel, uint32_t *pStatus)
{
    SENT_Type *pSent;

#if SENT_DEV_ERROR_REPORT == STD_ON
    if ((pSentHandle == NULL) || (pStatus == NULL))
    {
        SENT_ReportDevError(SENT_GET_CHANNEL_STATUS_ID, SENT_E_PARAM_POINTER);
    }
    else if (false == pSentHandle->tStatus.bInitStatus)
    {
    	SENT_ReportDevError(SENT_GET_CHANNEL_STATUS_ID, SENT_E_UNINIT);
    }
    else if (pSentHandle->eInstance >= SENT_INSTANCE_MAX)
    {
    	SENT_ReportDevError(SENT_GET_CHANNEL_STATUS_ID, SENT_E_PARAM_INSTANCE);
    }
    else if (eChannel >= SENT_CHANNEL_MAX)
    {
    	SENT_ReportDevError(SENT_GET_CHANNEL_STATUS_ID, SENT_E_PARAM_CHANNEL);
    }
    else
    {
#endif

    	pSent = aSent_Base[pSentHandle->eInstance];

        *pStatus = SENT_HWA_GetChannelStatus(pSent, (uint8_t)eChannel);

#if SENT_DEV_ERROR_REPORT == STD_ON
    }
#endif

    return;
}

void SENT_ClearChannelStatus(const Sent_HandleType *pSentHandle, const Sent_ChannelType eChannel, uint32_t Status)
{
    SENT_Type *pSent;

#if SENT_DEV_ERROR_REPORT == STD_ON
    if (pSentHandle == NULL)
    {
        SENT_ReportDevError(SENT_CLEAR_CHANNEL_STATUS_ID, SENT_E_PARAM_POINTER);
    }
    else if (false == pSentHandle->tStatus.bInitStatus)
    {
    	SENT_ReportDevError(SENT_CLEAR_CHANNEL_STATUS_ID, SENT_E_UNINIT);
    }
    else if (pSentHandle->eInstance >= SENT_INSTANCE_MAX)
    {
    	SENT_ReportDevError(SENT_CLEAR_CHANNEL_STATUS_ID, SENT_E_PARAM_INSTANCE);
    }
    else if (eChannel >= SENT_CHANNEL_MAX)
    {
    	SENT_ReportDevError(SENT_CLEAR_CHANNEL_STATUS_ID, SENT_E_PARAM_CHANNEL);
    }
    else
    {
#endif

		pSent = aSent_Base[pSentHandle->eInstance];

		SENT_HWA_ClearChannelStatus(pSent, (uint8_t)eChannel, Status);

#if SENT_DEV_ERROR_REPORT == STD_ON
    }
#endif

    return;
}

void SENT_GetChannelSPCBusyFlag(const Sent_HandleType *pSentHandle, const Sent_ChannelType eChannel, bool *pflag)
{
    SENT_Type *pSent;

#if SENT_DEV_ERROR_REPORT == STD_ON
    if ((pSentHandle == NULL) || (pflag == NULL))
    {
        SENT_ReportDevError(SENT_GET_SPC_BUSY_FLAG_ID, SENT_E_PARAM_POINTER);
    }
    else if (false == pSentHandle->tStatus.bInitStatus)
    {
    	SENT_ReportDevError(SENT_GET_SPC_BUSY_FLAG_ID, SENT_E_UNINIT);
    }
    else if (pSentHandle->eInstance >= SENT_INSTANCE_MAX)
    {
    	SENT_ReportDevError(SENT_GET_SPC_BUSY_FLAG_ID, SENT_E_PARAM_INSTANCE);
    }
    else if (eChannel >= SENT_CHANNEL_MAX)
    {
    	SENT_ReportDevError(SENT_GET_SPC_BUSY_FLAG_ID, SENT_E_PARAM_CHANNEL);
    }
    else
    {
#endif

		pSent = aSent_Base[pSentHandle->eInstance];

		*pflag = SENT_HWA_GetChanneSPCBusyFlag(pSent, (uint8_t)eChannel);

#if SENT_DEV_ERROR_REPORT == STD_ON
    }
#endif

    return;
}

#endif /* #if SENT_INSTANCE_COUNT > 0U */

