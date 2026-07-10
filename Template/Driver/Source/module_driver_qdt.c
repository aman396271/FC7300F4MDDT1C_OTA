/**
 * @file module_driver_adc.c
 * @author Flagchip030
 * @brief FC7xxx ADC driver source code
 * @version 2.0.0
 * @date 2022-04-20
 *
 * SDK Version: 2.6.0
 *

 * @copyright Copyright (c) 2022 Flagchip Semiconductors Co., Ltd.
 *
 */
/* ********************************************************************************
   *   Revision History:
   *
   *   Version     Date          Initials      CR#          Descriptions
   *   ---------   ----------    ------------  ----------   ---------------
   *   0.1.0       2022-12-01    Flagchip030   N/A          First version for FC7300
   ******************************************************************************** */

#include "module_driver_qdt.h"    /* include peripheral declarations */

#if QDT_INSTANCE_COUNT > 0U

#ifndef QDT_DEV_ERROR_REPORT
#define QDT_DEV_ERROR_REPORT    STD_OFF
#endif

#if QDT_DEV_ERROR_REPORT == STD_ON
#define QDT_ReportDevError(func, error) ReportDevError(QDT_MODULE_ID, func, error)
#endif

static void QDT_EnableWrtieProtection(QDT_Type *pQdt, bool bEnable);

static QDT_Type* const aQdt_Base[] = QDT_BASE_PTRS;

/**
 * @brief Enable or disable the write protection for QDT registers.
 *
 * @param pQdt The address QDT instance layout
 * @param bEnable true means enable, false means disable
 *
 * @return void
 */
static void QDT_EnableWrtieProtection(QDT_Type *pQdt, bool bEnable)
{
    if(bEnable)
    {
    	QDT_HWA_EnableWP(pQdt);
    }
    else
    {
    	QDT_HWA_DisableWP(pQdt);
    }
}

/**
 * @brief Initialize the QDT instance.
 *
 * @param pQdtHandle  The structure of the QDT processing handle
 * @param pConfig The structure of QDT instance configuration
 *
 * @return void
 */
void QDT_Init(QDT_HandleType *pQdtHandle, QDT_ConfigType *pConfig)
{
    QDT_Type *pQdt;
    
#if QDT_DEV_ERROR_REPORT == STD_ON
    if (pQdtHandle == NULL || pConfig == NULL)
    {
        QDT_ReportDevError(QDT_INIT_ID, QDT_E_PARAM_POINTER);
    }
    else if (false != pQdtHandle->eStatus)
    {
    	QDT_ReportDevError(QDT_INIT_ID, QDT_E_ALREADY_INIT);
    }
    else if (pQdtHandle->eInstance >= QDT_INSTANCE_MAX)
    {
    	QDT_ReportDevError(QDT_INIT_ID, QDT_E_PARAM_INSTANCE);
    }
    else
    {
#endif

		pQdt = aQdt_Base[pQdtHandle->eInstance];
		//disable the write protection
		QDT_EnableWrtieProtection(pQdt, false);
		//select the clock source
		if(QDT_CLOCK_INTERNAL_BUSCLK == pConfig->eClkSrcSel) //internal clock source from bus clock
		{
			QDT_HWA_SetCLKS(pQdt, pConfig->eClkSrcSel);
		}
		else if(QDT_CLOCK_INTERNAL_PCCCLK == pConfig->eClkSrcSel) //internal clock source from pcc clock
		{
			QDT_HWA_SetCLKS(pQdt, 3u);
			QDT_HWA_SetEXTCLK_SEL(pQdt, 3u);
		}
		else//external clock source
		{
			QDT_HWA_SetCLKS(pQdt, 3u);
			QDT_HWA_SetEXTCLK_SEL(pQdt, (uint8_t)(pConfig->eClkSrcSel - QDT_CLOCK_EXTERNAL_TCLK0));
		}
		//debug mode
		QDT_HWA_SetDBG(pQdt, (true == pConfig->bEnDebugMode)?1u:0u);
		//match trigger control
		QDT_HWA_SetMTRIGCTRL(pQdt, (false == pConfig->bEnMatchPulse)?1u:0u);
		//prescale setting
		QDT_HWA_SetPS(pQdt, pConfig->eCounterPrescale);
		QDT_HWA_SetFLTPS(pQdt, pConfig->eFilterPrescale);
		//Timer overflow interrupt enable
		QDT_HWA_SetTOIE(pQdt, (true == pConfig->bEnTOFInt)?1u:0u);
		pQdtHandle->tSetting.pTOFCallback = pConfig->pTOFCallback;
		//wdog enable
		QDT_HWA_SetWDOGEN(pQdt, (true == pConfig->tWdgConfig.bEnWDOG)?1u:0u);
		QDT_HWA_SetWDOGIE(pQdt, (true == pConfig->tWdgConfig.bEnWDOGFInt)?1u:0u);
		QDT_HWA_SetWDOGVAL(pQdt, pConfig->tWdgConfig.u16Timeout);
		pQdtHandle->tSetting.pWDOGFCallback = pConfig->tWdgConfig.pWDOGFCallback;
		//sync mode
		QDT_HWA_SetSYNCMODE(pQdt, (true == pConfig->tSyncModeConfig.bEnCVSyncTriggerMode)?1u:0u);
		QDT_HWA_SetTRIG_UPHOLD(pQdt, (true == pConfig->tSyncModeConfig.bEnHardTriggerUpdate)?1u:0u);
		QDT_HWA_SetTRIG_RSTCNT(pQdt, (true == pConfig->tSyncModeConfig.bEnHardTriggerReset)?1u:0u);
		QDT_HWA_SetTRIG0(pQdt, (true == pConfig->tSyncModeConfig.bEnHardTriggerInput)?1u:0u);
		QDT_HWA_SetSW_RSTCNT(pQdt, (true == pConfig->tSyncModeConfig.bEnSoftTriggerReset)?1u:0u);
		//enable the write protection
		QDT_EnableWrtieProtection(pQdt, true);
		pQdtHandle->eStatus = QDT_INIT;

#if QDT_DEV_ERROR_REPORT == STD_ON
    }
#endif

    return;
}

/**
 * @brief De-Initialize the QDT instance.
 *
 * @param pQdtHandle  The structure of the QDT processing handle
 *
 * @return void
 */
void QDT_Deinit(QDT_HandleType *pQdtHandle)
{
    uint8_t u8Temp;
    QDT_Type *pQdt;
    
#if QDT_DEV_ERROR_REPORT == STD_ON
    if (pQdtHandle == NULL)
    {
        QDT_ReportDevError(QDT_DEINIT_ID, QDT_E_PARAM_POINTER);
    }
    else if (false == pQdtHandle->eStatus)
    {
    	QDT_ReportDevError(QDT_DEINIT_ID, QDT_E_UNINIT);
    }
    else if (pQdtHandle->eInstance >= QDT_INSTANCE_MAX)
    {
    	QDT_ReportDevError(QDT_DEINIT_ID, QDT_E_PARAM_INSTANCE);
    }
    else
    {
#endif

		pQdt = aQdt_Base[pQdtHandle->eInstance];
		//disable the write protection
		QDT_EnableWrtieProtection(pQdt, false);
		//disable QUAD mode
		QDT_HWA_SetQUADEN(pQdt, 0u);
		//disable the clock
		QDT_HWA_SetCLKS(pQdt, QDT_CLOCK_NONE);
		//clear the flag
		QDT_HWA_ClearWDOGF(pQdt);
		QDT_HWA_ClearCHNF(pQdt);
		QDT_HWA_ClearTOF(pQdt);
		//disable watchdog
		QDT_HWA_SetWDOGEN(pQdt, 0u);
		for(u8Temp = 0u; u8Temp < QDT_CHANNEL_MAX; u8Temp++)
		{
			//disable channel function
			QDT_HWA_ClearCSC(pQdt, u8Temp);
			pQdtHandle->tSetting.achannelCallback[u8Temp] = NULL;
			pQdtHandle->tSetting.aChannelMode[u8Temp] = QDT_CHANNEL_NOT_USED;
		}
		pQdtHandle->tSetting.pTOFCallback = NULL;
		pQdtHandle->tSetting.pWDOGFCallback = NULL;
		//enable the write protection
		QDT_EnableWrtieProtection(pQdt, true);
		pQdtHandle->eStatus = QDT_DEINIT;

#if QDT_DEV_ERROR_REPORT == STD_ON
    }
#endif

    return;
}

/**
 * @brief Initialize the QDT channel.
 *
 * @param pQdtHandle  The structure of the QDT processing handle
 * @param pConfig The structure of QDT channel configuration
 *
 * @return void
 */
void QDT_Channel_Init(QDT_HandleType *pQdtHandle, QDT_Channel_ConfigType *pConfig)
{
    uint8_t u8channel;
    QDT_Type *pQdt;

#if QDT_DEV_ERROR_REPORT == STD_ON
    if ((pQdtHandle == NULL) || (pConfig == NULL))
    {
        QDT_ReportDevError(QDT_CHANNEL_INIT_ID, QDT_E_PARAM_POINTER);
    }
    else if (false == pQdtHandle->eStatus)
    {
    	QDT_ReportDevError(QDT_CHANNEL_INIT_ID, QDT_E_UNINIT);
    }
    else if (pQdtHandle->eInstance >= QDT_INSTANCE_MAX)
    {
    	QDT_ReportDevError(QDT_CHANNEL_INIT_ID, QDT_E_PARAM_INSTANCE);
    }
    else if(pConfig->eChannelIndex >= QDT_CHANNEL_MAX)
    {
    	QDT_ReportDevError(QDT_CHANNEL_INIT_ID, QDT_E_PARAM_CHANNEL);
    }
    else
    {
#endif
    
		u8channel = pConfig->eChannelIndex;
		pQdt = aQdt_Base[pQdtHandle->eInstance];

		//disable the write protection
		QDT_EnableWrtieProtection(pQdt, false);

		if(QDT_CHANNEL_IC_MODE == pConfig->eChannelMode)
		{
			//check if current channel is QUAD or ICM mode
			if((QDT_CHANNEL_NOT_USED == pQdtHandle->tSetting.aChannelMode[u8channel]) ||\
			   (QDT_CHANNEL_IC_MODE == pQdtHandle->tSetting.aChannelMode[u8channel]) ||\
			   ((QDT_CHANNEL_QUAD_MODE == pQdtHandle->tSetting.aChannelMode[u8channel]) && (QDT_CHANNEL_1_PHB != u8channel)) ||\
			   (((QDT_CHANNEL_ICDM_MODE <= pQdtHandle->tSetting.aChannelMode[u8channel]) && (QDT_CHANNEL_ICEXPENM_MODE >= pQdtHandle->tSetting.aChannelMode[u8channel])) &&\
			   (0u == u8channel % 1u)))
			{
				//clear channel control register
				QDT_HWA_ClearCSC(pQdt, u8channel);
				//reset the POSCNT
				QDT_HWA_SetICRST(pQdt, u8channel, (true == pConfig->tICConfig.bResetPOSCNT)?1u:0u);
				//channel interrupt
				QDT_HWA_SetCHIE(pQdt, u8channel, (true == pConfig->bEnChannelInt)?1u:0u);
				pQdtHandle->tSetting.achannelCallback[u8channel] = pConfig->pChannelCallback;
				//Polarity. keep default(zero)
				if(u8channel < QDT_CHANNEL_3_HOME)
				{
					QDT_HWA_SetPHXPOL(pQdt, u8channel, 0u);
				}
				QDT_HWA_SetICM_MODE(pQdt, u8channel, 0u);
				//configure which counter should be captured into CV register
				QDT_HWA_SetREVMODE(pQdt, u8channel, (true == pConfig->tICConfig.bFromRevCNT)?1u:0u);
				//configure the edge capture type
				if(QDT_CAPTURE_RISING_EDGE == pConfig->tICConfig.eEdge)
				{
					QDT_HWA_SetELSA(pQdt, u8channel, 1u);
					QDT_HWA_SetELSB(pQdt, u8channel, 0u);
				}
				else if(QDT_CAPTURE_FALLING_EDGE == pConfig->tICConfig.eEdge)
				{
					QDT_HWA_SetELSA(pQdt, u8channel, 0u);
					QDT_HWA_SetELSB(pQdt, u8channel, 1u);
				}
				else //QDT_CAPTURE_BOTH_EDGE
				{
					QDT_HWA_SetELSA(pQdt, u8channel, 1u);
					QDT_HWA_SetELSB(pQdt, u8channel, 1u);
				}
				pQdtHandle->tSetting.aChannelMode[u8channel] = QDT_CHANNEL_IC_MODE;
				if((QDT_CHANNEL_QUAD_MODE == pQdtHandle->tSetting.aChannelMode[u8channel]) && (QDT_CHANNEL_0_PHA == u8channel))
				{
					QDT_HWA_SetQUADEN(pQdt, 0u);
					QDT_HWA_ClearCSC(pQdt, QDT_CHANNEL_1_PHB);
					pQdtHandle->tSetting.aChannelMode[QDT_CHANNEL_1_PHB] = QDT_CHANNEL_NOT_USED;
				}
				else if((QDT_CHANNEL_ICDM_MODE <= pQdtHandle->tSetting.aChannelMode[u8channel]) &&\
						(QDT_CHANNEL_ICEXPENM_MODE >= pQdtHandle->tSetting.aChannelMode[u8channel]))
				{
					QDT_HWA_ClearCSC(pQdt, (uint8_t)(u8channel + 1u));
					pQdtHandle->tSetting.aChannelMode[u8channel + 1u] = QDT_CHANNEL_NOT_USED;
				}
			}
			else
			{
#if QDT_DEV_ERROR_REPORT == STD_ON
				QDT_ReportDevError(QDT_CHANNEL_INIT_ID, QDT_E_PARAM_GENERAL);
#endif
			}
		}
		else if(QDT_CHANNEL_NOT_USED == pConfig->eChannelMode)
		{
				//clear channel control register
				QDT_HWA_ClearCSC(pQdt, u8channel);

				pQdtHandle->tSetting.aChannelMode[u8channel] = QDT_CHANNEL_NOT_USED;
				pQdtHandle->tSetting.achannelCallback[u8channel] = NULL;
		}
		else if(QDT_CHANNEL_QUAD_MODE == pConfig->eChannelMode)
		{
			if(0u == u8channel) //only need to configure the PHA
			{
				//step1. Clear {ICM_MODE, ELSB, ELSA}) of PHA/B before enabling QUADEN.
				QDT_HWA_SetQUADEN(pQdt, 0u);
				//clear channel control register
				QDT_HWA_ClearCSC(pQdt, QDT_CHANNEL_0_PHA);
				QDT_HWA_ClearCSC(pQdt, QDT_CHANNEL_1_PHB);
				//step2. configure the QUAD
				if(QDT_CHANNEL_MATCH_DISABLE == pConfig->tPHABQUADConfig.ePHAMatchType)
				{
					QDT_HWA_SetCHTRIG(pQdt, QDT_CHANNEL_0_PHA, 0u);
				}
				else
				{
					QDT_HWA_SetCHTRIG(pQdt, QDT_CHANNEL_0_PHA, 1u);
					QDT_HWA_SetREVMODE(pQdt, QDT_CHANNEL_0_PHA, pConfig->tPHABQUADConfig.ePHAMatchType);
				}
				if(QDT_CHANNEL_MATCH_DISABLE == pConfig->tPHABQUADConfig.ePHBMatchType)
				{
					QDT_HWA_SetCHTRIG(pQdt, QDT_CHANNEL_1_PHB, 0u);
				}
				else
				{
					QDT_HWA_SetCHTRIG(pQdt, QDT_CHANNEL_1_PHB, 1u);
					QDT_HWA_SetREVMODE(pQdt, QDT_CHANNEL_1_PHB, pConfig->tPHABQUADConfig.ePHBMatchType);
				}
				QDT_HWA_SetPHAGFVAL(pQdt, pConfig->tPHABQUADConfig.u8PHAInputFilter);
				QDT_HWA_SetPHBGFVAL(pQdt, pConfig->tPHABQUADConfig.u8PHBInputFilter);
				QDT_HWA_SetCV(pQdt, QDT_CHANNEL_0_PHA, pConfig->tPHABQUADConfig.u32PHACV);
				QDT_HWA_SetCV(pQdt, QDT_CHANNEL_1_PHB, pConfig->tPHABQUADConfig.u32PHBCV);
				QDT_HWA_SetPHXPOL(pQdt, QDT_CHANNEL_0_PHA, (false == pConfig->tPHABQUADConfig.bPHANormalPolarity)?1u:0u);
				QDT_HWA_SetPHXPOL(pQdt, QDT_CHANNEL_1_PHB, (false == pConfig->tPHABQUADConfig.bPHBNormalPolarity)?1u:0u);
				QDT_HWA_SetQUADMODE(pQdt, (false == pConfig->tPHABQUADConfig.bEnPHAPHBMode)?1u:0u);
				QDT_HWA_SetCHIE(pQdt, QDT_CHANNEL_0_PHA, (true == pConfig->bEnChannelInt)?1u:0u);
				pQdtHandle->tSetting.achannelCallback[QDT_CHANNEL_0_PHA] = pConfig->pChannelCallback;
				//step3. enable quad mode
				QDT_HWA_SetQUADEN(pQdt, 1u);

				pQdtHandle->tSetting.aChannelMode[u8channel] = QDT_CHANNEL_QUAD_MODE;
				pQdtHandle->tSetting.aChannelMode[u8channel + 1u] = QDT_CHANNEL_QUAD_MODE;
			}
			else if((2u == u8channel) || (3u == u8channel)) //Z or home
			{
				if(QDT_CHANNEL_QUAD_MODE != pQdtHandle->tSetting.aChannelMode[QDT_CHANNEL_0_PHA])
				{
					//clear channel control register
					QDT_HWA_ClearCSC(pQdt, u8channel);
					if(QDT_CHANNEL_MATCH_DISABLE == pConfig->tPHZHOMEQUADConfig.eMatchType)
					{
						QDT_HWA_SetCHTRIG(pQdt, u8channel, 0u);
					}
					else
					{
						QDT_HWA_SetCHTRIG(pQdt, u8channel, 1u);
						QDT_HWA_SetREVMODE(pQdt, u8channel, pConfig->tPHZHOMEQUADConfig.eMatchType);
					}
					QDT_HWA_SetCHIE(pQdt, u8channel, (true == pConfig->bEnChannelInt)?1u:0u);
					pQdtHandle->tSetting.achannelCallback[u8channel] = pConfig->pChannelCallback;
					QDT_HWA_SetCV(pQdt, u8channel, pConfig->tPHZHOMEQUADConfig.u32CV);
					if(2u == u8channel)
					{
						QDT_HWA_SetPHZGFVAL(pQdt, pConfig->tPHZHOMEQUADConfig.u8InputFilter);
						QDT_HWA_SetPHXPOL(pQdt, u8channel, 0u);
					}
					else
					{
						QDT_HWA_SetHOMEGFVAL(pQdt, pConfig->tPHZHOMEQUADConfig.u8InputFilter);
					}

					pQdtHandle->tSetting.aChannelMode[u8channel] = QDT_CHANNEL_QUAD_MODE;
				}
				else
				{
#if QDT_DEV_ERROR_REPORT == STD_ON
				    QDT_ReportDevError(QDT_CHANNEL_INIT_ID, QDT_E_PARAM_MODE);
#endif
				}
			}
			else
			{
#if QDT_DEV_ERROR_REPORT == STD_ON
				QDT_ReportDevError(QDT_CHANNEL_INIT_ID, QDT_E_PARAM_GENERAL);
#endif
			}
		}
		else //ICM MODE
		{
			if(0u == (u8channel & 1u)) //Even channel
			{
				if((0u == u8channel) && (QDT_CHANNEL_QUAD_MODE == pQdtHandle->tSetting.aChannelMode[u8channel]))
				{
					//disable the QUAD Mode
					QDT_HWA_SetQUADEN(pQdt, 0u);
				}

				//clear channel pair control register
				QDT_HWA_ClearCSC(pQdt, u8channel);
				QDT_HWA_ClearCSC(pQdt, (uint8_t)(u8channel + 1u));

				if(QDT_CHANNEL_ICDM_MODE == pConfig->eChannelMode)
				{
					//configure the ICDM mode
					QDT_HWA_SetICM_CONT(pQdt, u8channel, (true == pConfig->tICDMConfig.bContinueMeasure)?1u:0u);
					QDT_HWA_SetICDPM_START(pQdt, u8channel, (true == pConfig->tICDMConfig.bStartWIthActive)?1u:0u);
					if(true == pConfig->tICDMConfig.bHighActive)
					{
						QDT_HWA_SetPHXPOL(pQdt, u8channel, 1u);
						//channel interrupt
						QDT_HWA_SetCHIE(pQdt, (uint8_t)(u8channel + 1u), (true == pConfig->bEnChannelInt)?1u:0u);
						pQdtHandle->tSetting.achannelCallback[u8channel + 1u] = pConfig->pChannelCallback;
					}
					else
					{
						QDT_HWA_SetPHXPOL(pQdt, u8channel, 0u);
						//channel interrupt
						QDT_HWA_SetCHIE(pQdt, u8channel, (true == pConfig->bEnChannelInt)?1u:0u);
						pQdtHandle->tSetting.achannelCallback[u8channel] = pConfig->pChannelCallback;
					}

					//even channel
					QDT_HWA_SetELSA(pQdt, u8channel, 1u);
					QDT_HWA_SetELSB(pQdt, u8channel, 0u);
					//odd channel
					QDT_HWA_SetELSA(pQdt, (uint8_t)(u8channel + 1u), 0u);
					QDT_HWA_SetELSB(pQdt, (uint8_t)(u8channel + 1u), 1u);
					QDT_HWA_SetICM_MODE(pQdt, u8channel, 1u); //ICDM
					//QDT_HWA_SetICM_MODE(pQdt, u8channel + 1u, 1u); //ICDM
				}
				else if(QDT_CHANNEL_ICPM_MODE == pConfig->eChannelMode)
				{
					//configure the ICPM mode
					QDT_HWA_SetICM_CONT(pQdt, u8channel, (true == pConfig->tICPMConfig.bContinueMeasure)?1u:0u);
					QDT_HWA_SetICDPM_START(pQdt, u8channel, (true == pConfig->tICPMConfig.bStartWIthActive)?1u:0u);
					QDT_HWA_SetPHXPOL(pQdt, u8channel, 0u);
					//channel interrupt
					QDT_HWA_SetCHIE(pQdt, u8channel, (true == pConfig->bEnChannelInt)?1u:0u);
					pQdtHandle->tSetting.achannelCallback[u8channel] = pConfig->pChannelCallback;
					if(QDT_CAPTURE_RISING_EDGE == pConfig->tICPMConfig.eEdge)
					{
						//even channel
						QDT_HWA_SetELSA(pQdt, u8channel, 1u);
						QDT_HWA_SetELSB(pQdt, u8channel, 0u);
						//odd channel
						QDT_HWA_SetICM_MODE(pQdt, u8channel, 2u); //ICPM
					}
					else if(QDT_CAPTURE_FALLING_EDGE == pConfig->tICPMConfig.eEdge) //capture falling edge
					{
						//even channel
						QDT_HWA_SetELSA(pQdt, u8channel, 0u);
						QDT_HWA_SetELSB(pQdt, u8channel, 1u);
						//odd channel
						QDT_HWA_SetELSA(pQdt, (uint8_t)(u8channel + 1u), 0u);
						QDT_HWA_SetELSB(pQdt, (uint8_t)(u8channel + 1u), 0u);
						QDT_HWA_SetICM_MODE(pQdt, u8channel, 2u); //ICPM
					}
					else
					{
#if QDT_DEV_ERROR_REPORT == STD_ON
				        QDT_ReportDevError(QDT_CHANNEL_INIT_ID, QDT_E_PARAM_GENERAL);
#endif
					}
				}
				else if(QDT_CHANNEL_ICENM_MODE == pConfig->eChannelMode)
				{
					//configure the ICENM mode
					QDT_HWA_SetICM_MODE(pQdt, u8channel, 7u); // ICENM_WIND_WRITE
					QDT_HWA_SetCV(pQdt, u8channel, pConfig->tICENMConfig.u32StartPoint);
					QDT_HWA_SetCV(pQdt, (uint8_t)(u8channel+1u), pConfig->tICENMConfig.u32EndPoint);
					QDT_HWA_SetICM_CONT(pQdt, u8channel, (true == pConfig->tICENMConfig.bContinueMeasure)?1u:0u);
					QDT_HWA_SetPHXPOL(pQdt, u8channel, 0u);
					//channel interrupt
					QDT_HWA_SetCHIE(pQdt, u8channel, (true == pConfig->bEnChannelInt)?1u:0u);
					pQdtHandle->tSetting.achannelCallback[u8channel] = pConfig->pChannelCallback;
					if(QDT_CAPTURE_RISING_EDGE == pConfig->tICPMConfig.eEdge)
					{
						QDT_HWA_SetELSA(pQdt, u8channel, 1u);
						QDT_HWA_SetELSB(pQdt, u8channel, 0u);
					}
					else if(QDT_CAPTURE_FALLING_EDGE == pConfig->tICPMConfig.eEdge) //capture falling edge
					{
						QDT_HWA_SetELSA(pQdt, u8channel, 0u);
						QDT_HWA_SetELSB(pQdt, u8channel, 1u);
					}
					else //both edge
					{
						QDT_HWA_SetELSA(pQdt, u8channel, 1u);
						QDT_HWA_SetELSB(pQdt, u8channel, 1u);
					}
					QDT_HWA_SetICM_MODE(pQdt, u8channel, 3u); //ICENM
				}
				else //QDT_CHANNEL_ICEXPENM_MODE
				{
					//configure the ICEXPENM mode
					QDT_HWA_SetICM_CONT(pQdt, u8channel, (true == pConfig->tICEXPENMConfig.bContinueMeasure)?1u:0u);
					QDT_HWA_SetPHXPOL(pQdt, u8channel, 0u);
					QDT_HWA_SetICEXP_NUM_ICM_ECNT(pQdt, (uint8_t)(u8channel + 1u), pConfig->tICEXPENMConfig.u8ExpectedNum);
					//channel interrupt
					QDT_HWA_SetCHIE(pQdt, u8channel, (true == pConfig->bEnChannelInt)?1u:0u);
					pQdtHandle->tSetting.achannelCallback[u8channel] = pConfig->pChannelCallback;
					if(QDT_CAPTURE_RISING_EDGE == pConfig->tICEXPENMConfig.eEdge)
					{
						QDT_HWA_SetELSA(pQdt, u8channel, 1u);
						QDT_HWA_SetELSB(pQdt, u8channel, 0u);
					}
					else if(QDT_CAPTURE_FALLING_EDGE == pConfig->tICEXPENMConfig.eEdge) //capture falling edge
					{
						QDT_HWA_SetELSA(pQdt, u8channel, 0u);
						QDT_HWA_SetELSB(pQdt, u8channel, 1u);
					}
					else //both edge
					{
						QDT_HWA_SetELSA(pQdt, u8channel, 1u);
						QDT_HWA_SetELSB(pQdt, u8channel, 1u);
					}
					QDT_HWA_SetICM_MODE(pQdt, u8channel, 4u); //ICEXPENM
				}

				pQdtHandle->tSetting.aChannelMode[u8channel] = pConfig->eChannelMode;
				pQdtHandle->tSetting.aChannelMode[u8channel + 1u] = pConfig->eChannelMode;
			}
			else
			{
#if QDT_DEV_ERROR_REPORT == STD_ON
				QDT_ReportDevError(QDT_CHANNEL_INIT_ID, QDT_E_PARAM_GENERAL);
#endif
			}
		}

		//enable the write protection
		QDT_EnableWrtieProtection(pQdt, true);

#if QDT_DEV_ERROR_REPORT == STD_ON
    }
#endif
    
    return;
}

/**
 * @brief Re-start a measurement in Single Measurement Mode.
 *
 * @param pQdtHandle  The structure of the QDT processing handle.
 * @param u8Channel The sent channel index.
 *
 * @return void
 */
void QDT_ReStartMeasurement(QDT_HandleType *pQdtHandle, uint8_t u8Channel)
{
    QDT_Type *pQdt;

#if QDT_DEV_ERROR_REPORT == STD_ON
    if (pQdtHandle == NULL)
    {
        QDT_ReportDevError(QDT_RESTART_MEASUREMENT_ID, QDT_E_PARAM_POINTER);
    }
    else if (false == pQdtHandle->eStatus)
    {
    	QDT_ReportDevError(QDT_RESTART_MEASUREMENT_ID, QDT_E_UNINIT);
    }
    else if (pQdtHandle->eInstance >= QDT_INSTANCE_MAX)
    {
    	QDT_ReportDevError(QDT_RESTART_MEASUREMENT_ID, QDT_E_PARAM_INSTANCE);
    }
    else if((u8Channel >= QDT_CHANNEL_MAX) || (0u != (u8Channel & 1u))) // only valid for even channel
    {
    	QDT_ReportDevError(QDT_RESTART_MEASUREMENT_ID, QDT_E_PARAM_CHANNEL);
    }
    else
    {
#endif

		pQdt = aQdt_Base[pQdtHandle->eInstance];
		QDT_HWA_SetICM_SIG_REG(pQdt, u8Channel, 1u);

#if QDT_DEV_ERROR_REPORT == STD_ON
    }
#endif

    return;
}

/**
 * @brief Get the channel flag, used for polling method.
 *
 * @param pQdtHandle  The structure of the QDT processing handle.
 * @param u8Channel The sent channel index.
 * @param pSet The pointer of getting if the flag is set.
 *
 * @return void
 */
void QDT_GetChannelFlag(QDT_HandleType *pQdtHandle, uint8_t u8Channel, bool *pSet)
{
    QDT_Type *pQdt;

#if QDT_DEV_ERROR_REPORT == STD_ON
    if ((pQdtHandle == NULL) || (pSet == NULL))
    {
        QDT_ReportDevError(QDT_GET_CHANNEL_FLAG_ID, QDT_E_PARAM_POINTER);
    }
    else if (false == pQdtHandle->eStatus)
    {
    	QDT_ReportDevError(QDT_GET_CHANNEL_FLAG_ID, QDT_E_UNINIT);
    }
    else if (pQdtHandle->eInstance >= QDT_INSTANCE_MAX)
    {
    	QDT_ReportDevError(QDT_GET_CHANNEL_FLAG_ID, QDT_E_PARAM_INSTANCE);
    }
    else if(u8Channel >= QDT_CHANNEL_MAX)
    {
    	QDT_ReportDevError(QDT_GET_CHANNEL_FLAG_ID, QDT_E_PARAM_CHANNEL);
    }
    else
    {
#endif

		pQdt = aQdt_Base[pQdtHandle->eInstance];
		if(0u == QDT_HWA_GetCHF(pQdt, u8Channel))
		{
			*pSet = false;
		}
		else
		{
			*pSet = true;
		}

#if QDT_DEV_ERROR_REPORT == STD_ON
    }
#endif

    return;
}

/**
 * @brief Clear the channel flag, used for polling method.
 *
 * @param pQdtHandle  The structure of the QDT processing handle.
 * @param u8Channel The sent channel index.
 *
 * @return void
 */
void QDT_ClearChannelFlag(QDT_HandleType *pQdtHandle, uint8_t u8Channel)
{
    QDT_Type *pQdt;

#if QDT_DEV_ERROR_REPORT == STD_ON
    if (pQdtHandle == NULL)
    {
        QDT_ReportDevError(QDT_CLEAR_CHANNEL_FLAG_ID, QDT_E_PARAM_POINTER);
    }
    else if (false == pQdtHandle->eStatus)
    {
    	QDT_ReportDevError(QDT_CLEAR_CHANNEL_FLAG_ID, QDT_E_UNINIT);
    }
    else if (pQdtHandle->eInstance >= QDT_INSTANCE_MAX)
    {
    	QDT_ReportDevError(QDT_CLEAR_CHANNEL_FLAG_ID, QDT_E_PARAM_INSTANCE);
    }
    else if(u8Channel >= QDT_CHANNEL_MAX)
    {
    	QDT_ReportDevError(QDT_CLEAR_CHANNEL_FLAG_ID, QDT_E_PARAM_CHANNEL);
    }
    else
    {
#endif

		pQdt = aQdt_Base[pQdtHandle->eInstance];
		QDT_HWA_ClearCHF(pQdt, u8Channel);

#if QDT_DEV_ERROR_REPORT == STD_ON
    }
#endif

    return;
}

/**
 * @brief Get the edge number value.
 *
 * @param pQdtHandle  The structure of the QDT processing handle.
 * @param u8Channel The sent channel index.
 * @param pNumber The pointer of getting the edge number value.
 *
 * @return void
 */
void QDT_GetEdgeNumber(QDT_HandleType *pQdtHandle, uint8_t u8Channel, uint32_t *pNumber)
{
    QDT_Type *pQdt;

#if QDT_DEV_ERROR_REPORT == STD_ON
    if ((pQdtHandle == NULL) || (pNumber == NULL))
    {
        QDT_ReportDevError(QDT_GET_EDGE_NUMBER_ID, QDT_E_PARAM_POINTER);
    }
    else if (false == pQdtHandle->eStatus)
    {
    	QDT_ReportDevError(QDT_GET_EDGE_NUMBER_ID, QDT_E_UNINIT);
    }
    else if (pQdtHandle->eInstance >= QDT_INSTANCE_MAX)
    {
    	QDT_ReportDevError(QDT_GET_EDGE_NUMBER_ID, QDT_E_PARAM_INSTANCE);
    }
    else if(u8Channel >= QDT_CHANNEL_MAX)
    {
    	QDT_ReportDevError(QDT_GET_EDGE_NUMBER_ID, QDT_E_PARAM_CHANNEL);
    }
    else
    {
#endif

		pQdt = aQdt_Base[pQdtHandle->eInstance];
		*pNumber = QDT_HWA_GetICEXP_NUM_ICM_ECNT(pQdt, u8Channel);

#if QDT_DEV_ERROR_REPORT == STD_ON
    }
#endif

    return;
}

/**
 * @brief Get the CV counter value.
 *
 * @param pQdtHandle  The structure of the QDT processing handle.
 * @param u8Channel The sent channel index.
 * @param pCV The pointer of getting the CV counter value.
 *
 * @return void
 */
void QDT_GetCV(QDT_HandleType *pQdtHandle, uint8_t u8Channel, uint32_t *pCV)
{
    QDT_Type *pQdt;
    
#if QDT_DEV_ERROR_REPORT == STD_ON
    if ((pQdtHandle == NULL) || (pCV == NULL))
    {
        QDT_ReportDevError(QDT_GET_CV_ID, QDT_E_PARAM_POINTER);
    }
    else if (false == pQdtHandle->eStatus)
    {
    	QDT_ReportDevError(QDT_GET_CV_ID, QDT_E_UNINIT);
    }
    else if (pQdtHandle->eInstance >= QDT_INSTANCE_MAX)
    {
    	QDT_ReportDevError(QDT_GET_CV_ID, QDT_E_PARAM_INSTANCE);
    }
    else if(u8Channel >= QDT_CHANNEL_MAX)
    {
    	QDT_ReportDevError(QDT_GET_CV_ID, QDT_E_PARAM_CHANNEL);
    }
    else
    {
#endif

		pQdt = aQdt_Base[pQdtHandle->eInstance];
		*pCV = QDT_HWA_GetCV(pQdt, u8Channel);

#if QDT_DEV_ERROR_REPORT == STD_ON
    }
#endif
    
    return;
}

/**
 * @brief Get the REV counter value.
 *
 * @param pQdtHandle  The structure of the QDT processing handle.
 * @param u8Channel The sent channel index.
 * @param pREVCNT The pointer of getting the REV counter value.
 *
 * @return void
 */
void QDT_GetREVCNT(QDT_HandleType *pQdtHandle, uint32_t *pREVCNT)
{
    QDT_Type *pQdt;
    
#if QDT_DEV_ERROR_REPORT == STD_ON
    if ((pQdtHandle == NULL) || (pREVCNT == NULL))
    {
        QDT_ReportDevError(QDT_GET_REVCNT_ID, QDT_E_PARAM_POINTER);
    }
    else if (false == pQdtHandle->eStatus)
    {
    	QDT_ReportDevError(QDT_GET_REVCNT_ID, QDT_E_UNINIT);
    }
    else if (pQdtHandle->eInstance >= QDT_INSTANCE_MAX)
    {
    	QDT_ReportDevError(QDT_GET_REVCNT_ID, QDT_E_PARAM_INSTANCE);
    }
    else
    {
#endif

		pQdt = aQdt_Base[pQdtHandle->eInstance];
		*pREVCNT = QDT_HWA_GetREVCNT(pQdt);
    
#if QDT_DEV_ERROR_REPORT == STD_ON
    }
#endif

    return;
}

/**
 * @brief Get the REV HOLD counter value.
 *
 * @param pQdtHandle  The structure of the QDT processing handle.
 * @param u8Channel The sent channel index.
 * @param pREVCNTH The pointer of getting the REV HOLD counter value.
 *
 * @return void
 */
void QDT_GetREVCNT_HOLD(QDT_HandleType *pQdtHandle, uint32_t *pREVCNTH)
{
    QDT_Type *pQdt;
    
#if QDT_DEV_ERROR_REPORT == STD_ON
    if ((pQdtHandle == NULL) || (pREVCNTH == NULL))
    {
        QDT_ReportDevError(QDT_GET_REVCNT_HOLD_ID, QDT_E_PARAM_POINTER);
    }
    else if (false == pQdtHandle->eStatus)
    {
    	QDT_ReportDevError(QDT_GET_REVCNT_HOLD_ID, QDT_E_UNINIT);
    }
    else if (pQdtHandle->eInstance >= QDT_INSTANCE_MAX)
    {
    	QDT_ReportDevError(QDT_GET_REVCNT_HOLD_ID, QDT_E_PARAM_INSTANCE);
    }
    else
    {
#endif

		pQdt = aQdt_Base[pQdtHandle->eInstance];
		*pREVCNTH = QDT_HWA_GetREVCNT_HOLD(pQdt);
    
#if QDT_DEV_ERROR_REPORT == STD_ON
    }
#endif

    return;
}

/**
 * @brief Get the POS counter value.
 *
 * @param pQdtHandle  The structure of the QDT processing handle.
 * @param u8Channel The sent channel index.
 * @param pPOSCNT The pointer of getting the POS counter value.
 *
 * @return void
 */
void QDT_GetPOSCNT(QDT_HandleType *pQdtHandle, uint32_t *pPOSCNT)
{
    QDT_Type *pQdt;

#if QDT_DEV_ERROR_REPORT == STD_ON
    if ((pQdtHandle == NULL) || (pPOSCNT == NULL))
    {
        QDT_ReportDevError(QDT_GET_POSCNT_ID, QDT_E_PARAM_POINTER);
    }
    else if (false == pQdtHandle->eStatus)
    {
    	QDT_ReportDevError(QDT_GET_POSCNT_ID, QDT_E_UNINIT);
    }
    else if (pQdtHandle->eInstance >= QDT_INSTANCE_MAX)
    {
    	QDT_ReportDevError(QDT_GET_POSCNT_ID, QDT_E_PARAM_INSTANCE);
    }
    else
    {
#endif

		pQdt = aQdt_Base[pQdtHandle->eInstance];
		*pPOSCNT = QDT_HWA_GetPOSCNT(pQdt);

#if QDT_DEV_ERROR_REPORT == STD_ON
    }
#endif

    return;
}

/**
 * @brief Get the POS HOLD counter value.
 *
 * @param pQdtHandle  The structure of the QDT processing handle.
 * @param u8Channel The sent channel index.
 * @param pPOSCNTH The pointer of getting the POS HOLD counter value.
 *
 * @return void
 */
void QDT_GetPOSCNT_HOLD(QDT_HandleType *pQdtHandle, uint32_t *pPOSCNTH)
{
    QDT_Type *pQdt;

#if QDT_DEV_ERROR_REPORT == STD_ON
    if ((pQdtHandle == NULL) || (pPOSCNTH == NULL))
    {
        QDT_ReportDevError(QDT_GET_POSCNT_HOLD_ID, QDT_E_PARAM_POINTER);
    }
    else if (false == pQdtHandle->eStatus)
    {
    	QDT_ReportDevError(QDT_GET_POSCNT_HOLD_ID, QDT_E_UNINIT);
    }
    else if (pQdtHandle->eInstance >= QDT_INSTANCE_MAX)
    {
    	QDT_ReportDevError(QDT_GET_POSCNT_HOLD_ID, QDT_E_PARAM_INSTANCE);
    }
    else
    {
#endif

		pQdt = aQdt_Base[pQdtHandle->eInstance];
		*pPOSCNTH = QDT_HWA_GetPOSCNT_HOLD(pQdt);

#if QDT_DEV_ERROR_REPORT == STD_ON
    }
#endif
    
    return;
}

/**
 * @brief Get the POS DIFF counter value.
 *
 * @param pQdtHandle  The structure of the QDT processing handle.
 * @param u8Channel The sent channel index.
 * @param pPOSDCNT The pointer of getting the POS DIFF counter value.
 *
 * @return void
 */
void QDT_GetPOSDCNT(QDT_HandleType *pQdtHandle, uint32_t *pPOSDCNT)
{
    QDT_Type *pQdt;

#if QDT_DEV_ERROR_REPORT == STD_ON
    if ((pQdtHandle == NULL) || (pPOSDCNT == NULL))
    {
        QDT_ReportDevError(QDT_GET_POSDCNT_ID, QDT_E_PARAM_POINTER);
    }
    else if (false == pQdtHandle->eStatus)
    {
    	QDT_ReportDevError(QDT_GET_POSDCNT_ID, QDT_E_UNINIT);
    }
    else if (pQdtHandle->eInstance >= QDT_INSTANCE_MAX)
    {
    	QDT_ReportDevError(QDT_GET_POSDCNT_ID, QDT_E_PARAM_INSTANCE);
    }
    else
    {
#endif

		pQdt = aQdt_Base[pQdtHandle->eInstance];
		*pPOSDCNT = QDT_HWA_GetPOSDCNT(pQdt);

#if QDT_DEV_ERROR_REPORT == STD_ON
    }
#endif
    
    return;
}

/**
 * @brief Get the POS DIFF HOLD counter value.
 *
 * @param pQdtHandle  The structure of the QDT processing handle.
 * @param u8Channel The sent channel index.
 * @param pPOSDCNTH The pointer of getting the POS DIFF HOLD counter value.
 *
 * @return void
 */
void QDT_GetPOSDCNT_HOLD(QDT_HandleType *pQdtHandle, uint32_t *pPOSDCNTH)
{
    QDT_Type *pQdt;
    
#if QDT_DEV_ERROR_REPORT == STD_ON
    if ((pQdtHandle == NULL) || (pPOSDCNTH == NULL))
    {
        QDT_ReportDevError(QDT_GET_POSDCNT_HOLD_ID, QDT_E_PARAM_POINTER);
    }
    else if (false == pQdtHandle->eStatus)
    {
    	QDT_ReportDevError(QDT_GET_POSDCNT_HOLD_ID, QDT_E_UNINIT);
    }
    else if (pQdtHandle->eInstance >= QDT_INSTANCE_MAX)
    {
    	QDT_ReportDevError(QDT_GET_POSDCNT_HOLD_ID, QDT_E_PARAM_INSTANCE);
    }
    else
    {
#endif

		pQdt = aQdt_Base[pQdtHandle->eInstance];
		*pPOSDCNTH = QDT_HWA_GetPOSDCNT_HOLD(pQdt);

#if QDT_DEV_ERROR_REPORT == STD_ON
    }
#endif
    
    return;
}

/**
 * @brief Get the LE counter value.
 *
 * @param pQdtHandle  The structure of the QDT processing handle.
 * @param u8Channel The sent channel index.
 * @param pLECNT The pointer of getting the LE counter value.
 *
 * @return void
 */
void QDT_GetLECNT(QDT_HandleType *pQdtHandle, uint32_t *pLECNT)
{
    QDT_Type *pQdt;
    
#if QDT_DEV_ERROR_REPORT == STD_ON
    if ((pQdtHandle == NULL) || (pLECNT == NULL))
    {
        QDT_ReportDevError(QDT_GET_LECNT_ID, QDT_E_PARAM_POINTER);
    }
    else if (false == pQdtHandle->eStatus)
    {
    	QDT_ReportDevError(QDT_GET_LECNT_ID, QDT_E_UNINIT);
    }
    else if (pQdtHandle->eInstance >= QDT_INSTANCE_MAX)
    {
    	QDT_ReportDevError(QDT_GET_LECNT_ID, QDT_E_PARAM_INSTANCE);
    }
    else
    {
#endif

		pQdt = aQdt_Base[pQdtHandle->eInstance];
		*pLECNT = QDT_HWA_GetLECNT(pQdt);

#if QDT_DEV_ERROR_REPORT == STD_ON
    }
#endif
    
    return;
}

/**
 * @brief Get the LE HOLD counter value.
 *
 * @param pQdtHandle  The structure of the QDT processing handle.
 * @param u8Channel The sent channel index.
 * @param pLECNTH The pointer of getting the LE HOLD counter value.
 *
 * @return void
 */
void QDT_GetLECNT_HOLD(QDT_HandleType *pQdtHandle, uint32_t *pLECNTH)
{
    QDT_Type *pQdt;

#if QDT_DEV_ERROR_REPORT == STD_ON
    if ((pQdtHandle == NULL) || (pLECNTH == NULL))
    {
        QDT_ReportDevError(QDT_GET_LECNT_HOLD_ID, QDT_E_PARAM_POINTER);
    }
    else if (false == pQdtHandle->eStatus)
    {
    	QDT_ReportDevError(QDT_GET_LECNT_HOLD_ID, QDT_E_UNINIT);
    }
    else if (pQdtHandle->eInstance >= QDT_INSTANCE_MAX)
    {
    	QDT_ReportDevError(QDT_GET_LECNT_HOLD_ID, QDT_E_PARAM_INSTANCE);
    }
    else
    {
#endif

		pQdt = aQdt_Base[pQdtHandle->eInstance];
		*pLECNTH = QDT_HWA_GetLECNT_HOLD(pQdt);

#if QDT_DEV_ERROR_REPORT == STD_ON
    }
#endif

    return;
}

/**
 * @brief Get the POSDTMR counter value.
 *
 * @param pQdtHandle  The structure of the QDT processing handle.
 * @param u8Channel The sent channel index.
 * @param pPOSDTMRCNT The pointer of getting the POSDTMR counter value.
 *
 * @return void
 */
void QDT_GetPOSDTMRCNT(QDT_HandleType *pQdtHandle, uint32_t *pPOSDTMRCNT)
{
    
	QDT_Type *pQdt;

#if QDT_DEV_ERROR_REPORT == STD_ON
    if ((pQdtHandle == NULL) || (pPOSDTMRCNT == NULL))
    {
        QDT_ReportDevError(QDT_GET_POSDTMRCNT_ID, QDT_E_PARAM_POINTER);
    }
    else if (false == pQdtHandle->eStatus)
    {
    	QDT_ReportDevError(QDT_GET_POSDTMRCNT_ID, QDT_E_UNINIT);
    }
    else if (pQdtHandle->eInstance >= QDT_INSTANCE_MAX)
    {
    	QDT_ReportDevError(QDT_GET_POSDTMRCNT_ID, QDT_E_PARAM_INSTANCE);
    }
    else
    {
#endif

		pQdt = aQdt_Base[pQdtHandle->eInstance];
		*pPOSDTMRCNT = QDT_HWA_GetPOSDTMRCNT(pQdt);

#if QDT_DEV_ERROR_REPORT == STD_ON
    }
#endif
    
    return;
}

/**
 * @brief Get the POSDTMR HOLD counter value.
 *
 * @param pQdtHandle  The structure of the QDT processing handle.
 * @param u8Channel The sent channel index.
 * @param pPOSDTMRCNTH The pointer of getting the POSDTMR HOLD counter value.
 *
 * @return void
 */
void QDT_GetPOSDTMRCNT_HOLD(QDT_HandleType *pQdtHandle, uint32_t *pPOSDTMRCNTH)
{
    QDT_Type *pQdt;
    
#if QDT_DEV_ERROR_REPORT == STD_ON
    if ((pQdtHandle == NULL) || (pPOSDTMRCNTH == NULL))
    {
        QDT_ReportDevError(QDT_GET_POSDTMRCNT_HOLD_ID, QDT_E_PARAM_POINTER);
    }
    else if (false == pQdtHandle->eStatus)
    {
    	QDT_ReportDevError(QDT_GET_POSDTMRCNT_HOLD_ID, QDT_E_UNINIT);
    }
    else if (pQdtHandle->eInstance >= QDT_INSTANCE_MAX)
    {
    	QDT_ReportDevError(QDT_GET_POSDTMRCNT_HOLD_ID, QDT_E_PARAM_INSTANCE);
    }
    else
    {
#endif

		pQdt = aQdt_Base[pQdtHandle->eInstance];
		*pPOSDTMRCNTH = QDT_HWA_GetPOSDTMRCNT_HOLD(pQdt);

#if QDT_DEV_ERROR_REPORT == STD_ON
    }
#endif

    return;
}

/**
 * @brief Get the speed from the sensor.
 *
 * @param pQdtHandle  The structure of the QDT processing handle.
 * @param pSpeed The pointer of getting the speed value.
 *
 * @return void
 */
void QDT_GetSpeed(QDT_HandleType *pQdtHandle, QDT_SpeedResultType *pSpeed)
{
    QDT_Type *pQdt;
    uint16_t u16Poscnt, u16Posdcnth, u16Posdtmrcnth, u16lecnth;
    static uint32_t u32E;
    static float fM,fM_1, fSpeed_pre;
    
#if QDT_DEV_ERROR_REPORT == STD_ON
    if ((pQdtHandle == NULL) || (pSpeed == NULL))
    {
        QDT_ReportDevError(QDT_GET_SPEED_ID, QDT_E_PARAM_POINTER);
    }
    else if (false == pQdtHandle->eStatus)
    {
    	QDT_ReportDevError(QDT_GET_SPEED_ID, QDT_E_UNINIT);
    }
    else if (pQdtHandle->eInstance >= QDT_INSTANCE_MAX)
    {
    	QDT_ReportDevError(QDT_GET_SPEED_ID, QDT_E_PARAM_INSTANCE);
    }
    else if((QDT_CHANNEL_QUAD_MODE != pQdtHandle->tSetting.aChannelMode[QDT_CHANNEL_0_PHA]) ||\
    		(QDT_CHANNEL_QUAD_MODE != pQdtHandle->tSetting.aChannelMode[QDT_CHANNEL_1_PHB]))
    {
    	QDT_ReportDevError(QDT_GET_SPEED_ID, QDT_E_PARAM_MODE);
    }
    else
    {
#endif

		pQdt = aQdt_Base[pQdtHandle->eInstance];
		//step1. read POSDCNT
		u16Poscnt = QDT_HWA_GetPOSDCNT(pQdt);
		u16Poscnt++;
		//step2. read POSDCNTH
		u16Posdcnth = QDT_HWA_GetPOSDCNT_HOLD(pQdt);
		//step3. read POSDTMRCnTH
		u16Posdtmrcnth = QDT_HWA_GetPOSDTMRCNT_HOLD(pQdt);
		//step4. read LECNTH
		u16lecnth = QDT_HWA_GetLECNT_HOLD(pQdt);
		//step5. POSDCNTH = 0?
		if(0u == u16Posdcnth)
		{
			fM = (float)u16lecnth / (float)(pSpeed->u32ClkFreq);
			if(u16lecnth >= pSpeed->u32LecntLarge)
			{
				pSpeed->fSpeed = 0.0;
			}
			else
			{
				if(fM > fM_1)
				{
					pSpeed->fSpeed = ((float)15 / (float)(pSpeed->u32Line)) / fM;
				}
				else
				{
					pSpeed->fSpeed = fSpeed_pre;
				}
			}
		}
		else
		{
			fM = (float)u16Posdtmrcnth / (float)(pSpeed->u32ClkFreq);
			u32E = u16Posdcnth;
			fM_1 = fM;

			pSpeed->fSpeed = ((float)15u / (float)(pSpeed->u32Line)) * (float)u32E / fM;
		}

		fSpeed_pre = pSpeed->fSpeed;

#if QDT_DEV_ERROR_REPORT == STD_ON
    }
#endif

    return;
}

/**
 * @brief SENT ISR process function, used to clear the flag and call the user defined callback API.
 *
 * @param pQdtHandle  The structure of the QDT processing handle.
 *
 * @return void
 */
void QDT_InterruptProcess(const QDT_HandleType *pQdtHandle)
{
	uint8_t u8Channel;
	QDT_Type *pQdt;
	
	if((NULL != pQdtHandle) && (pQdtHandle->eInstance < QDT_INSTANCE_MAX))
    {
        if(QDT_INIT == pQdtHandle->eStatus)
        {
            pQdt = aQdt_Base[pQdtHandle->eInstance];
			//Timer overflow interrupt
			if(0u != QDT_HWA_GetTOIE(pQdt))
			{
				if(0u != QDT_HWA_GetTOF(pQdt))
				{
					QDT_HWA_ClearTOF(pQdt);
					if(NULL != pQdtHandle->tSetting.pTOFCallback)
					{
						pQdtHandle->tSetting.pTOFCallback();
					}
				}
			}
			//Watchdog interrupt
			if(0u != QDT_HWA_GetWDOGIE(pQdt))
			{
				if(0u != QDT_HWA_GetWDOGF(pQdt))
				{
					QDT_HWA_ClearWDOGF(pQdt);
					if(NULL != pQdtHandle->tSetting.pWDOGFCallback)
					{
						pQdtHandle->tSetting.pWDOGFCallback();
					}
				}
			}
			//channel interrupt
			for(u8Channel = 0u; u8Channel < QDT_INSTANCE_MAX; u8Channel++)
			{
				if(0u != QDT_HWA_GetCHIE(pQdt, u8Channel))
				{
					if(0u != QDT_HWA_GetCHF(pQdt, u8Channel))
					{
						QDT_HWA_ClearCHF(pQdt, u8Channel);
						if(NULL != pQdtHandle->tSetting.achannelCallback[u8Channel])
						{
							pQdtHandle->tSetting.achannelCallback[u8Channel]();
						}
					}
				}
			}
		}
	}
}

#endif
