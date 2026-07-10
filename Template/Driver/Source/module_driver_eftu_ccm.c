#include "module_driver_eftu_ccm.h"

#if defined(EFTU_INSTANCE_COUNT) && (EFTU_INSTANCE_COUNT > 0)
static  EFTU_CCM_Type *const s_pEftuCcmBasePtrs[EFTU_INSTANCE_COUNT] = EFTU_CCM_ADDRESS_TAB;

#ifndef CCM_DEV_ERROR_REPORT
    #define CCM_DEV_ERROR_REPORT    STD_OFF
#endif

#if CCM_DEV_ERROR_REPORT == STD_ON
    #define CCM_ReportDevError(func, error) ReportDevError(EFTU_CCM_MODULE_ID, func, error)
#endif

/**
 * @brief Initialize CCM peripherals
 * @param pCcmHandle EFTU Ccm processing handle
 * @param pConfig Ccm InitStruct
 */
void EFTU_CCM_Init(EFTU_CCM_HandleType *pCcmHandle, EFTU_CCM_InitStruct *pConfig)
{
    #if CCM_DEV_ERROR_REPORT == STD_ON
    if (pCcmHandle->eInstance >= EFTU_INSTANCE_COUNT)
    {
        CCM_ReportDevError(EFTU_CCM_INIT_ID, EFTU_CCM_E_PARAM_INVALID);
    }
    else
    #endif
    {
        EFTU_CCM_Type *pCcm = s_pEftuCcmBasePtrs[pCcmHandle->eInstance];
        pCcmHandle->tStatus.pCcm = pCcm;
        pCcmHandle->tStatus.bTim0En = TRUE;
        pCcmHandle->tStatus.bTom0En = TRUE;
        pCcmHandle->tStatus.bTom1En = TRUE;
        EFTU_CCM_HWA_DisableProtection(pCcm);
        if (pConfig->bTim0Enable == FALSE)
        {
            EFTU_CCM_HWA_DisableTim0(pCcm);
            pCcmHandle->tStatus.bTim0En = FALSE;
        }
        if (pConfig->bTom0Enable == FALSE)
        {
            EFTU_CCM_HWA_DisableTom0(pCcm);
            pCcmHandle->tStatus.bTom0En = FALSE;
        }
        if (pConfig->bTom1Enable == FALSE)
        {
            EFTU_CCM_HWA_DisableTom1(pCcm);
            pCcmHandle->tStatus.bTom1En = FALSE;
        }
        EFTU_CCM_HWA_ConfigDebugMode(pCcm, pConfig->eDebugMode);
        pCcmHandle->tStatus.eDebugMode = pConfig->eDebugMode;
    }
}

/**
 * @brief Config EFTU debug mode
 * @param pCcmHandle EFTU Ccm processing handle
 * @param eDebugMode EFTU debug mode
 */
void EFTU_CCM_ConfigDebugMode(EFTU_CCM_HandleType *pCcmHandle, EFTU_CCM_DebugMode eDebugMode)
{
    #if CCM_DEV_ERROR_REPORT == STD_ON
    if (pCcmHandle->tStatus.pCcm == NULL)
    {
        CCM_ReportDevError(EFTU_CCM_CONFIG_DEBUG_ID, EFTU_CCM_UNINIT);
    }
    else
    #endif
    {
        EFTU_CCM_Type *pCcm = s_pEftuCcmBasePtrs[pCcmHandle->eInstance];
        EFTU_CCM_HWA_DisableProtection(pCcm);
        EFTU_CCM_HWA_ConfigDebugMode(pCcm, eDebugMode);
        pCcmHandle->tStatus.eDebugMode = eDebugMode;
    }
}

/**
 * @brief Enable EFTU Tim0
 * @param pCcmHandle EFTU Ccm processing handle
 */
void EFTU_CCM_EnableTim0(EFTU_CCM_HandleType *pCcmHandle)
{
    EFTU_CCM_Type *pCcm = s_pEftuCcmBasePtrs[pCcmHandle->eInstance];
    EFTU_CCM_HWA_EnableTim0(pCcm);
    pCcmHandle->tStatus.bTim0En = TRUE;
}
/**
 * @brief Enable EFTU Tom0
 * @param pCcmHandle EFTU Ccm processing handle
 */
void EFTU_CCM_EnableTom0(EFTU_CCM_HandleType *pCcmHandle)
{
    EFTU_CCM_Type *pCcm = s_pEftuCcmBasePtrs[pCcmHandle->eInstance];
    EFTU_CCM_HWA_EnableTom0(pCcm);
    pCcmHandle->tStatus.bTom0En  = TRUE;
}
/**
 * @brief Enable EFTU Tom1
 * @param pCcmHandle EFTU Ccm processing handle
 */
void EFTU_CCM_EnableTom1(EFTU_CCM_HandleType *pCcmHandle)
{
    EFTU_CCM_Type *pCcm = s_pEftuCcmBasePtrs[pCcmHandle->eInstance];
    EFTU_CCM_HWA_EnableTom1(pCcm);
    pCcmHandle->tStatus.bTom1En  = TRUE;
}

/**
 * @brief Disable EFTU Tim0
 * @param pCcmHandle EFTU Ccm processing handle
 */
void EFTU_CCM_DisableTim0(EFTU_CCM_HandleType *pCcmHandle)
{
    EFTU_CCM_Type *pCcm = s_pEftuCcmBasePtrs[pCcmHandle->eInstance];
    EFTU_CCM_HWA_DisableTim0(pCcm);
    pCcmHandle->tStatus.bTim0En = FALSE;
}

/**
 * @brief Disable EFTU Tom0
 * @param pCcmHandle EFTU Ccm processing handle
 */
void EFTU_CCM_DisableTom0(EFTU_CCM_HandleType *pCcmHandle)
{
    EFTU_CCM_Type *pCcm = s_pEftuCcmBasePtrs[pCcmHandle->eInstance];
    EFTU_CCM_HWA_DisableTom0(pCcm);
    pCcmHandle->tStatus.bTom0En = FALSE;
}

/**
 * @brief Disable EFTU Tom1
 * @param pCcmHandle EFTU Ccm processing handle
 */
void EFTU_CCM_DisableTom1(EFTU_CCM_HandleType *pCcmHandle)
{
    EFTU_CCM_Type *pCcm = s_pEftuCcmBasePtrs[pCcmHandle->eInstance];
    EFTU_CCM_HWA_DisableTom1(pCcm);
    pCcmHandle->tStatus.bTom1En = FALSE;
}

/**
 * @brief Config EFTU Cmp peripherals
 * @param pCcmHandle EFTU Ccm processing handle
 * @param  pCmpInitStruct Cmp InitStruct
 */
void EFTU_CCM_ConfigCmp(EFTU_CCM_HandleType *pCcmHandle, EFTU_CCM_CmpConfigStruct *pCmpInitStruct)
{
    #if CCM_DEV_ERROR_REPORT == STD_ON
    if (pCcmHandle->tStatus.pCcm == NULL)
    {
        CCM_ReportDevError(EFTU_CCM_CONFIG_CMP_ID, EFTU_CCM_UNINIT);
    }
    else if ((pCmpInitStruct->bEnInterrupt == TRUE) && (pCmpInitStruct->EftuCmpIntback == NULL))
    {
        CCM_ReportDevError(EFTU_CCM_CONFIG_CMP_ID, EFTU_CCM_E_PARAM_INVALID);
    }
    else
    #endif
    {
        EFTU_CCM_Type *pCcm = s_pEftuCcmBasePtrs[pCcmHandle->eInstance];
        EFTU_CCM_HWA_SpecUnLock(pCcm);
        EFTU_CCM_HWA_ConfigCmpSrc(pCcm, pCmpInitStruct->eCmpInstance, pCmpInitStruct->u8CmpEnMask, pCmpInitStruct->eCmpSrcX, pCmpInitStruct->eCmpSrcY);
        EFTU_CCM_HWA_SpecLock(pCcm);
        if (TRUE == (pCmpInitStruct->bEnInterrupt))
        {
                EFTU_CCM_HWA_EnCmpInterrupt(pCcm, pCmpInitStruct->eCmpInstance);

            pCcmHandle->tStatus.g_pEftuCmpIntback[pCmpInitStruct->eCmpInstance] = pCmpInitStruct->pEftuCmpIntback;
        }
    }
}

/**
 * @brief Config cluster cmu clock source.
 * @param pCcmHandle EFTU Ccm processing handle
 * @param  eClusterClk  Cluster clock index
 * @param  pCmpInitStruct Cluster clock select
 * @param pCmuHandle EFTU cmu processing handle
 * @param  u32Freq user define frequency
 */
void EFTU_CCM_ConfigClusterCmuClock(EFTU_CCM_HandleType *pCcmHandle, EFTU_CCM_ClusterCmuClkType eClusterClk, EFTU_CCM_ClusterCmuClkSelectType eCcmClockSel,EFTU_CMU_HandleType *pCmuHandle,uint32 u32Freq )
{
    #if CCM_DEV_ERROR_REPORT == STD_ON
    if (pCcmHandle->tStatus.pCcm == NULL)
    {
        CCM_ReportDevError(EFTU_CCM_CONFIG_CLUSTER_CMU_CLOCK_ID, EFTU_CCM_UNINIT);
    }
    else if (eClusterClk > EFTU_CLUSTER_CMU_CLK_7)
    {
        CCM_ReportDevError(EFTU_CCM_CONFIG_CLUSTER_CMU_CLOCK_ID, EFTU_CCM_E_PARAM_CHANNEL);
    }
    else if (eCcmClockSel > EFTU_CLUSTER_CLOCK_EXT_CAPTURE)
    {
        CCM_ReportDevError(EFTU_CCM_CONFIG_CLUSTER_CMU_CLOCK_ID, EFTU_CCM_E_PARAM_CHANNEL);
    }
    else
    #endif
    {
        EFTU_CCM_Type *pCcm = s_pEftuCcmBasePtrs[pCcmHandle->eInstance];
        EFTU_CCM_HWA_SetClusterCmuClkSrc(pCcm, eClusterClk, eCcmClockSel);
        pCcmHandle->tStatus.eaClusterClkSrc[(uint8_t)eClusterClk] = eCcmClockSel;
        if( eCcmClockSel == EFTU_CLUSTER_CLOCK_CMU_CLK8)
        {
        	pCmuHandle->tStatus.fCmuClock[pCcmHandle->eInstance][eClusterClk] = pCmuHandle->tStatus.fClock8;
        }
        else if ( eCcmClockSel == EFTU_CLUSTER_CLOCK_EXT_CAPTURE)
        {
        	pCmuHandle->tStatus.fCmuClock[pCcmHandle->eInstance][eClusterClk] = u32Freq;
        }
        else
        {
        	(void)u32Freq;
        }
    }
}

/*
#define EFTU_TIM_ERROR_EN_BIT0          (0x1<<0U)
#define EFTU_TIM_ERROR_EN_BIT1          (0x1<<1U)
#define EFTU_TIM_ERROR_EN_BIT2          (0x1<<2U)
#define EFTU_TIM_ERROR_EN_BIT3          (0x1<<3U)
#define EFTU_TIM_ERROR_EN_BIT4          (0x1<<4U)
#define EFTU_TIM_ERROR_EN_BIT5          (0x1<<5U)
 *
 * */
/**
 * @brief Config cluster Tim Err Interrupt.
 * @param pCcmHandle EFTU Ccm processing handle
 * @param  pTimErrStruct  Tim Err InitStruct
 */
void EFTU_CCM_ConfigTimErrorInterrupt(EFTU_CCM_HandleType *pCcmHandle, EFTU_CCM_TimErrIntStruct *pTimErrStruct)
{
    #if CCM_DEV_ERROR_REPORT == STD_ON
    if (pCcmHandle->tStatus.pCcm == NULL)
    {
        CCM_ReportDevError(EFTU_CCM_CONFIG_TIM_ERR_INTERRUPT_ID, EFTU_CCM_UNINIT);
    }
    else if (pTimErrStruct->eTimChannel > EFTU_TIM_ERR_CH7)
    {
        CCM_ReportDevError(EFTU_CCM_CONFIG_TIM_ERR_INTERRUPT_ID, EFTU_CCM_E_PARAM_CHANNEL);
    }
    else if ((pTimErrStruct->bEnErrInterrupt == TRUE) && (pTimErrStruct->EftuTimErrIntback == NULL))
    {
        CCM_ReportDevError(EFTU_CCM_CONFIG_TIM_ERR_INTERRUPT_ID, EFTU_CCM_E_PARAM_INVALID);
    }
    else
    #endif
    {
        EFTU_CCM_Type *pCcm = s_pEftuCcmBasePtrs[pCcmHandle->eInstance];
        if (TRUE == (pTimErrStruct->bEnErrInterrupt))
        {
            if (pTimErrStruct->eTimChannel <= EFTU_TIM_ERR_CH3)
            {
                EFTU_CCM_HWA_EnTimChnErrInterupt0_3(pCcm, pTimErrStruct->eTimChannel, pTimErrStruct->u8ErrorEnMask);
            }
            else
            {
                EFTU_CCM_HWA_EnTimChnErrInterupt4_7(pCcm, pTimErrStruct->eTimChannel, pTimErrStruct->u8ErrorEnMask);
            }
            pCcmHandle->tStatus.g_pEftuTimErrIntback[pTimErrStruct->eTimChannel] = pTimErrStruct->pEftuTimErrIntback;
        }
    }
}

/**
 * @brief Config cluster  Dma Request.
 * @param pCcmHandle EFTU Ccm processing handle
 * @param  pDmaReqStruct  Tim Dma InitStruct
 */
void EFTU_CCM_ConfigDmaRequest(EFTU_CCM_HandleType *pCcmHandle, EFTU_CCM_DmaReqStruct *pDmaReqStruct)
{
    #if CCM_DEV_ERROR_REPORT == STD_ON
    if (pCcmHandle->tStatus.pCcm == NULL)
    {
        CCM_ReportDevError(EFTU_CCM_CONFIG_DMA_REQUEST_ID, EFTU_CCM_UNINIT);
    }
    else
    #endif
    {
        EFTU_CCM_Type *pCcm = s_pEftuCcmBasePtrs[pCcmHandle->eInstance];
        uint32_t u32DmaReqMask = (uint32_t)0U;
        if ((uint32_t)pDmaReqStruct->eDmaReqSelect <= EFTU_CCM_DMA_REQ_TOM1_CH_7)
		{
        	u32DmaReqMask = 0x1u<<4U;

        	u32DmaReqMask  |= ((uint32_t)pDmaReqStruct->eDmaReqSelect);
		}
		else if ((uint32_t)pDmaReqStruct->eDmaReqSelect <= EFTU_CCM_DMA_REQ_TOM0_CH_7)
		{
			u32DmaReqMask = 0x2u<<4U;
			u32DmaReqMask  |= ((uint32_t)pDmaReqStruct->eDmaReqSelect - 8U);
		}
		else/*TOM*/
		{
			u32DmaReqMask = 0x3u<<4U;
			u32DmaReqMask  |= ((uint32_t)pDmaReqStruct->eDmaReqSelect - 16U);
		}

        u32DmaReqMask |= (((uint32_t)pDmaReqStruct->bCcu0IrqEnDmaReq) << 6U) | (((uint32_t)pDmaReqStruct->bCcu1IrqEnDmaReq) << 7U);

#if EFTU_CCM_DMA_REQ_ONE_INSTANCE == 6U
        if (pDmaReqStruct->u8DmaReqSrcChnIndex <= 1U)
        {
            EFTU_CCM_HWA_ConfigDmaSrc0_1(pCcm, pDmaReqStruct->u8DmaReqSrcChnIndex, (uint8_t)u32DmaReqMask);
        }
        else if (pDmaReqStruct->u8DmaReqSrcChnIndex <= 3U)
        {
            EFTU_CCM_HWA_ConfigDmaSrc2_3(pCcm, pDmaReqStruct->u8DmaReqSrcChnIndex, (uint8_t)u32DmaReqMask);
        }
        else if (pDmaReqStruct->u8DmaReqSrcChnIndex <= 5U)
        {
            EFTU_CCM_HWA_ConfigDmaSrc4_5(pCcm, pDmaReqStruct->u8DmaReqSrcChnIndex, (uint8_t)u32DmaReqMask);
        }
        else
        {
            /*error*/
        }

#elif  EFTU_CCM_DMA_REQ_ONE_INSTANCE == 16U
        EFTU_CCM_HWA_ConfigDmaSrc(pCcm, pDmaReqStruct->u8DmaReqSrcChnIndex, (uint8_t)u32DmaReqMask);
#endif

    }
}


/*EFTU_CCM_TRG_MUX/EFTU_CCM_TRG_EN0/EFTU_CCM_TRG_EN1,only for EFTU0*/
/*
#define  EFTU_GTRIGGER_OUT_MASK_TOM1_CCU1_BIT0    (0x1<<0U)
#define  EFTU_GTRIGGER_OUT_MASK_TOM0_CCU1_BIT1    (0x1<<1U)
#define  EFTU_GTRIGGER_OUT_MASK_TOM1_CCU0_BIT2    (0x1<<2U)
#define  EFTU_GTRIGGER_OUT_MASK_TOM0_CCU0_BIT3    (0x1<<3U)
#define  EFTU_GTRIGGER_OUT_MASK_TIM_TRIG_BIT4     (0x1<<4U)
 * */
/**
 * @brief Config global trigger.(Only for EFTU0)
 * @param pCcmHandle EFTU Ccm processing handle
 * @param u8TriggerIndex  Trigger Index
* @param  pTriggerStruct  Trigger InitStruct
 */
void EFTU_CCM_ConfigGlobalTrigger(EFTU_CCM_HandleType *pCcmHandle, uint8_t u8TriggerIndex, EFTU_CCM_GlobalTriggerMode *pTriggerStruct) /*Only for EFTU0*/
{
    #if CCM_DEV_ERROR_REPORT == STD_ON
    if (pCcmHandle->tStatus.pCcm == NULL)
    {
        CCM_ReportDevError(EFTU_CCM_CONFIG_DMA_REQUEST_ID, EFTU_CCM_UNINIT);
    }
    else if (u8TriggerIndex >= 8U)
    {
        CCM_ReportDevError(EFTU_CCM_CONFIG_DMA_REQUEST_ID, EFTU_CCM_E_PARAM_CHANNEL);
    }
    else if (pTriggerStruct->eGtriggerSrc > GTRIGGER_OUT_SRC_EFTU2)
    {
        CCM_ReportDevError(EFTU_CCM_CONFIG_DMA_REQUEST_ID, EFTU_CCM_E_PARAM_INVALID);
    }
    else
    #endif
    {
        EFTU_CCM_Type *pCcm = s_pEftuCcmBasePtrs[pCcmHandle->eInstance];
        EFTU_CCM_HWA_SpecUnLock(pCcm);
        EFTU_CCM_HWA_ConfigGtomTriggerSrc(pCcm, u8TriggerIndex, pTriggerStruct->eGtriggerSrc);
        if (u8TriggerIndex < 4U)
        {
            EFTU_CCM_HWA_ConfigGtomTriggerMask0_3(pCcm, u8TriggerIndex, pTriggerStruct->u8TriggerOutMask);
        }
        else
        {
            EFTU_CCM_HWA_ConfigGtomTriggerMask4_7(pCcm, u8TriggerIndex, pTriggerStruct->u8TriggerOutMask);
        }
        EFTU_CCM_HWA_SpecLock(pCcm);
    }
}

/**
 * @brief Ccm Interrupt process
 * @param pCcmHandle EFTU Ccm processing handle
 */
void EFTUn_CCM_IRQHandler(EFTU_CCM_HandleType *pCcmHandle)
{
    EFTU_CCM_Type *pCcm = s_pEftuCcmBasePtrs[pCcmHandle->eInstance];

    if (pCcmHandle->eInstance == EFTU_INSTANCE_0)
    {
        if ((EFTU_CCM_HWA_GetCmp0IrqFlag(pCcm) == TRUE) && (TRUE == EFTU_CCM_HWA_GetCmp0IrqEnable(pCcm)))
        {
            EFTU_CCM_HWA_ClearCmp0IrqFlag(pCcm);
            if (pCcmHandle->tStatus.g_pEftuCmpIntback[0] != NULL)
            {
                pCcmHandle->tStatus.g_pEftuCmpIntback[0]();
            }
        }
        else if ((EFTU_CCM_HWA_GetCmp1IrqFlag(pCcm) == TRUE) && (TRUE == EFTU_CCM_HWA_GetCmp1IrqEnable(pCcm)))
        {
            EFTU_CCM_HWA_ClearCmp1IrqFlag(pCcm);
            if (pCcmHandle->tStatus.g_pEftuCmpIntback[1] != NULL)
            {
                pCcmHandle->tStatus.g_pEftuCmpIntback[1]();
            }
        }
    }

    uint32 u32ErrFlag = EFTU_CCM_HWA_GetErrIrqFlag(pCcm);
    for (uint8 u8ErrChannel = 0U; u8ErrChannel < 8u; u8ErrChannel++)
    {
        if ((u32ErrFlag & (1U << u8ErrChannel)) != 0u)
        {
            if (u8ErrChannel < 4U) /*0-3*/
            {
                uint32 ErrMask = EFTU_CCM_HWA_GetTimErrFlag0_3(pCcm);
                ErrMask &= EFTU_CCM_HWA_GetTimErrEnable0_3(pCcm);
                EFTU_CCM_HWA_ClearTimErrFlag0_3(pCcm, ErrMask);
                if (ErrMask & (uint32)(0x3f << (8U * u8ErrChannel)))
                {
                    if (pCcmHandle->tStatus.g_pEftuTimErrIntback[u8ErrChannel] != NULL)
                    {
                        pCcmHandle->tStatus.g_pEftuTimErrIntback[u8ErrChannel]();
                    }
                }
            }
            else /*4-7*/
            {
                uint32 ErrMask = EFTU_CCM_HWA_GetTimErrFlag4_7(pCcm);
                ErrMask &= EFTU_CCM_HWA_GetTimErrEnable4_7(pCcm);
                EFTU_CCM_HWA_ClearTimErrFlag4_7(pCcm, ErrMask);
                if (ErrMask & (uint32)(0x3f << (8U * (u8ErrChannel - 4U))))
                {
                    if (pCcmHandle->tStatus.g_pEftuTimErrIntback[u8ErrChannel] != NULL)
                    {
                        pCcmHandle->tStatus.g_pEftuTimErrIntback[u8ErrChannel]();
                    }
                }
            }
        }
    }
}


#endif /* defined(EFTU_INSTANCE_COUNT) && (EFTU_INSTANCE_COUNT > 0) */

