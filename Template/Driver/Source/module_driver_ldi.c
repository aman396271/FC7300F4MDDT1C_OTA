/**
 * @file module_driver_port.c
 * @author Flagchip
 * @brief LDI driver type definition and API
 * @version 2.0.0
 * @date 2025-06-18
 *
 * SDK Version: 2.6.0
 *

 * @copyright Copyright (c) 2020-2024 Flagchip Semiconductors Co., Ltd.
 *
 * @details
 */
/********************************************************************************
*   Revision History:
*
*   Version     Date          Initials       CR#          Descriptions
*   ---------   ----------    ------------   ----------   ---------------
   *   0.1.0      2025-06-18     Flagchip0121   N/A         Init version
********************************************************************************/
#include "module_driver_ldi.h"

#if LDI_INSTANCE_COUNT > 0U



#ifndef LDI_DEV_ERROR_RELDI
    #define LDI_DEV_ERROR_RELDI   STD_OFF
#endif

#if LDI_DEV_ERROR_RELDI == STD_ON
    #define LDI_ReportDevError(func, error) ReportDevError(LDI_MODULE_ID, func, error)
#endif

#define LDI_FIFO_DEPTH            (0x08U)

/********* Local Variables ************/
/** @brief LDI instance list */
static LDI_Type *const s_pLdiInstanceTable[LDI_INSTANCE_COUNT] = LDI_BASE_PTRS;

/***************LDI Global Functions*****************/
/**
 * @brief Initialize ldi
 *
 * @param pLdiHandle pLdiHandle LDI handle for LDI functionality
 * @param pInitStruct Initialization structure of ldi
 */
void LDI_Init(LDI_HandleType *pLdiHandle, const LDI_InitType *const pInitStruct)
{
    #if LDI_DEV_ERROR_RELDI == STD_ON
    if (NULL == pInitStruct || NULL == pLdiHandle)
    {
        LDI_ReportDevError(LDI_InitPins_ID, LDI_E_PARAM_INPUT);
    }
    else if (pLdiHandle->eInstance >= LDI_INSTANCE_COUNT)
    {
        LDI_ReportDevError(LDI_InitPins_ID, LDI_E_PARAM_INSTANCE);
    }
    else if ((FALSE == pInitStruct->tEnChannelfg.bChannel0En))
    {
        LDI_ReportDevError(LDI_InitPins_ID, LDI_E_PARAM_INPUT);
    }
    else if ((LDI_STATE_UNINIT != pLdiHandle->eLdiState))
    {
        LDI_ReportDevError(LDI_InitPins_ID, LDI_E_PARAM_STATUS);
    }
    else if ((pInitStruct->tDisplayfg.tPxdScfg.u32ScfgSignalwinStart >= pInitStruct->tDisplayfg.tPxdScfg.u32ScfgSignalwinEnd) ||
             (pInitStruct->tDisplayfg.tPxdScfg.u32ScfgSignalwinStart > LDI_SIGNAL_WINDOW_START_MAX) ||
             (pInitStruct->tDisplayfg.tPxdScfg.u32ScfgSignalwinEnd > LDI_SIGNAL_WINDOW_END_MAX))
    {
        LDI_ReportDevError(LDI_InitPins_ID, LDI_E_PARAM_INPUT);
    }
    else if ((pInitStruct->tDisplayfg.tPxdDcfg.u32DcfgSignalwinStart >= pInitStruct->tDisplayfg.tPxdDcfg.u32DcfgSignalwinEnd) ||
             (pInitStruct->tDisplayfg.tPxdDcfg.u32DcfgSignalwinStart > LDI_SIGNAL_WINDOW_START_MAX) ||
             (pInitStruct->tDisplayfg.tPxdDcfg.u32DcfgSignalwinEnd > LDI_SIGNAL_WINDOW_END_MAX))
    {
        LDI_ReportDevError(LDI_InitPins_ID, LDI_E_PARAM_INPUT);
    }     
    else if ((pInitStruct->tDisplayfg.tPxdIcfg.u32IcfgSignalwinStart >= pInitStruct->tDisplayfg.tPxdIcfg.u32IcfgSignalwinEnd) ||
             (pInitStruct->tDisplayfg.tPxdIcfg.u32IcfgSignalwinStart > LDI_SIGNAL_WINDOW_START_MAX) ||
             (pInitStruct->tDisplayfg.tPxdIcfg.u32IcfgSignalwinEnd > LDI_SIGNAL_WINDOW_END_MAX))
    {
        LDI_ReportDevError(LDI_InitPins_ID, LDI_E_PARAM_INPUT);
    }
    else if ((pInitStruct->tDisplayfg.tPxdGcfg.u32GclkStart > LDI_GCLK_START_MAX) ||
             (pInitStruct->tDisplayfg.tPxdGcfg.u32GclkEnd > LDI_GCLK_START_END) ||
             (pInitStruct->tDisplayfg.tPxdGcfg.u32GclkPeriod > LDI_GCLK_PERIOD_MAX) )
    {
        LDI_ReportDevError(LDI_InitPins_ID, LDI_E_PARAM_INPUT);
    }
    else if ((pInitStruct->tDisplayfg.u32PxdRcfg > LDI_RCFG_MAX))
    {
        LDI_ReportDevError(LDI_InitPins_ID, LDI_E_PARAM_INPUT);
    }      
    else
    {
    #endif

        LDI_Type *pLdi = s_pLdiInstanceTable[pLdiHandle->eInstance];
        uint32 u32LdiCtrlRegValue = 0U;
        uint32 u32LdiPxCtrlRegValue = 0U;
        uint32 u32LdiPxCtrl2RegValue = 0U;

        uint32 u32LdiPxGcfgRegValue = 0U;
        uint32 u32LdiPxScfgRegValue = 0U;
        uint32 u32LdiPxDcfgRegValue = 0U;
        uint32 u32LdiPxIcfgRegValue = 0U;

        uint32_t  u32Fcr0RegValue = 0U;
        uint32_t  u32Fcr1RegValue = 0U;
        uint32_t  u32Fcr2RegValue = 0U;
        uint32_t  u32Fcr3RegValue = 0U;

        uint32 u32ClkCfgValue = 0U;
        uint32 u32PinsMask = 0U;

        /** config Ldi Dtrl */
        LDI_HWA_ClearFIFO(pLdi);
        LDI_HWA_ClearFIFOStatus(pLdi);
        if (LDI_DCLK_SDR_MODE != pInitStruct->tClkcfg.tDclkcfg.eLdiDclkMode)
        {
            u32LdiCtrlRegValue |= LDI_CTRL_DDR(1U);
            if (FALSE != pInitStruct->tClkcfg.bDdrSdrDelayEn)
            {
                u32LdiCtrlRegValue |= LDI_CTRL_DDRT(1U);
            }

        }
        else
        {
            u32LdiCtrlRegValue |= LDI_CTRL_DDR(0U);
            if (TRUE != pInitStruct->tClkcfg.bDdrSdrDelayEn)
            { 
                u32LdiCtrlRegValue |= LDI_CTRL_DCLK_INV(1U);
            }
        }

        LDI_HWA_CfgCtrl(pLdi, u32LdiCtrlRegValue);

        /** config Ldi Clock */
        LDI_HWA_EnFuncClkRef(pLdi);

        u32ClkCfgValue |= LDI_CLK_CTRL_FUT_MASK;

        switch(pInitStruct->tClkcfg.eDdrSdrDivider)
        {
            case LDI_DDRSDRPREDIV_BY1:
                 u32ClkCfgValue |= (LDI_CLK_CTRL_HDC(0x0U)) | (LDI_CLK_CTRL_DEN(0x40U))| (LDI_CLK_CTRL_NUM(0x40U));
                 break;

            case LDI_DDRSDRPREDIV_BY2:
                 u32ClkCfgValue |= (LDI_CLK_CTRL_HDC(0x0U)) | (LDI_CLK_CTRL_DEN(0x40U))| (LDI_CLK_CTRL_NUM(0x80U));
                 break;

            case LDI_DDRSDRPREDIV_BY4:
                 u32ClkCfgValue |= (LDI_CLK_CTRL_HDC(0x1U)) | (LDI_CLK_CTRL_DEN(0x20U))| (LDI_CLK_CTRL_NUM(0x80U));
                 break;

            case LDI_DDRSDRPREDIV_BY8:
                 u32ClkCfgValue |= (LDI_CLK_CTRL_HDC(0x3U)) | (LDI_CLK_CTRL_DEN(0x10U))| (LDI_CLK_CTRL_NUM(0x80U));
                 break;

            case LDI_DDRSDRPREDIV_BY12:
                 u32ClkCfgValue |= (LDI_CLK_CTRL_HDC(0x5U)) | (LDI_CLK_CTRL_DEN(0x10U)) | (LDI_CLK_CTRL_NUM(0xC0U));
                 break;

            case LDI_DDRSDRPREDIV_BY16:
                 u32ClkCfgValue |= (LDI_CLK_CTRL_HDC(0x7U)) | (LDI_CLK_CTRL_DEN(0x08U)) | (LDI_CLK_CTRL_NUM(0x80U));
                 break;

            default:
                 u32ClkCfgValue |= (LDI_CLK_CTRL_HDC(0x0U)) | (LDI_CLK_CTRL_DEN(0x40U)) | (LDI_CLK_CTRL_NUM(0x40U));
                 break;
        }
        
        u32ClkCfgValue |=  LDI_CLK_CTRL_GCLKDIV(pInitStruct->tClkcfg.tGclkcfg.eLdiGclkDivider);

        if (LDI_GCLK_SDR_CLK == pInitStruct->tClkcfg.tGclkcfg.eLdiGclkSrc)
        {
            u32ClkCfgValue |=  LDI_CLK_CTRL_GCLKMUX(0U);
        }
        else if (LDI_GCLK_DDR_CLK == pInitStruct->tClkcfg.tGclkcfg.eLdiGclkSrc)
        {
            u32ClkCfgValue |=  LDI_CLK_CTRL_GCLKMUX(1U);
        }
        else
        {
            u32ClkCfgValue |=  LDI_CLK_CTRL_GCLKMUX(3U);
        }
        
        u32ClkCfgValue |= LDI_CLK_CTRL_SSM(pInitStruct->tClkcfg.eSpreadMode);
        u32ClkCfgValue |= LDI_CLK_CTRL_SSD(pInitStruct->tClkcfg.eSpreadDirect);
        LDI_HWA_SetClkcfg(pLdi, u32ClkCfgValue);
        
        LDI_HWA_EnableClk(pLdi);

        /** config Ldi px ctrl */
        u32LdiPxCtrlRegValue = (LDI_PX_CTRL_ROWS(pInitStruct->tScreencfg.u32Rows)) | (LDI_PX_CTRL_CHNS(pInitStruct->tScreencfg.u32Channels)) |
                       (LDI_PX_CTRL_CASCDS(pInitStruct->tScreencfg.u32Cascds)) | (LDI_PX_CTRL_DNUMS(pInitStruct->tScreencfg.u32Dnums));

        LDI_HWA_CfgPxCtrl(pLdi, u32LdiPxCtrlRegValue);

        /** config Ldi Px Ctrl2 */
        u32LdiPxCtrl2RegValue = LDI_PX_CTRL2_GCLK_CONT(1U) | LDI_PX_CTRL2_DCLK_CONT(1U);
        LDI_HWA_CfgPxCtrl2(pLdi, u32LdiPxCtrl2RegValue);

        /** Ldi clear Tr Size */
        LDI_HWA_ClearTrSize(pLdi);

        /** config Ldi for special device */
        LDI_HWA_CfgPxdRcfg(pLdi, LDI_PXD_RCFG_RCFG(pInitStruct->tDisplayfg.u8PxdRcfg));

        uint32_t u32TempGclkPeriod = (pInitStruct->tDisplayfg.tPxdGcfg.u32GclkPeriod > 0x7FFFU) ? 0x7FFFU : pInitStruct->tDisplayfg.tPxdGcfg.u32GclkPeriod;
         
        u32LdiPxGcfgRegValue = LDI_PXD_GCFG_GCLK_START(pInitStruct->tDisplayfg.tPxdGcfg.u8GclkStart) |
                               LDI_PXD_GCFG_GCLK_PERIOD(u32TempGclkPeriod) |
                               LDI_PXD_GCFG_GCLK_END(pInitStruct->tDisplayfg.tPxdGcfg.u8GclkEnd) |
                               LDI_PXD_GCFG_GCLK_RMODE(pInitStruct->tDisplayfg.tPxdGcfg.bGclkRmodeEn);
        LDI_HWA_CfgPxdGcfg(pLdi, u32LdiPxGcfgRegValue);

        u32LdiPxScfgRegValue = LDI_PXD_SCFG_SET(pInitStruct->tDisplayfg.tPxdScfg.u8ScfgSignalwinStart) |
                               LDI_PXD_SCFG_CLR(pInitStruct->tDisplayfg.tPxdScfg.u8ScfgSignalwinEnd) |
                               LDI_PXD_SCFG_CLKM(pInitStruct->tDisplayfg.tPxdScfg.bScfgClockModeEn)  |
                               LDI_PXD_SCFG_REPEAT(pInitStruct->tDisplayfg.tPxdScfg.bScfgRepeatModeEn);
        LDI_HWA_CfgPxdScfg(pLdi, u32LdiPxScfgRegValue);

        u32LdiPxDcfgRegValue = LDI_PXD_DCFG_SET(pInitStruct->tDisplayfg.tPxdDcfg.u8DcfgSignalwinStart) |
                               LDI_PXD_DCFG_CLR(pInitStruct->tDisplayfg.tPxdDcfg.u8DcfgSignalwinEnd) |
                               LDI_PXD_DCFG_CLKM(pInitStruct->tDisplayfg.tPxdDcfg.bDcfgClockModeEn)  |
                               LDI_PXD_DCFG_REPEAT(pInitStruct->tDisplayfg.tPxdDcfg.bDcfgRepeatModeEn);
        LDI_HWA_CfgPxdDcfg(pLdi, u32LdiPxDcfgRegValue);


        u32LdiPxIcfgRegValue = LDI_PXD_ICFG_SET(pInitStruct->tDisplayfg.tPxdIcfg.u8IcfgSignalwinStart) |
                               LDI_PXD_ICFG_CLR(pInitStruct->tDisplayfg.tPxdIcfg.u8IcfgSignalwinEnd) |
                               LDI_PXD_ICFG_CLKM(pInitStruct->tDisplayfg.tPxdIcfg.bIcfgClockModeEn)  |
                               LDI_PXD_ICFG_REPEAT(pInitStruct->tDisplayfg.tPxdIcfg.bIcfgRepeatModeEn);
        LDI_HWA_CfgPxdIcfg(pLdi, u32LdiPxIcfgRegValue);

        /** config Ldi enable pins */
        if (LDI_LSB_FIRST != pInitStruct->eBitOrder)
        {          
            u32PinsMask = 0x1U;
            pLdiHandle->tStatus.tChannelState.bChannel0En = TRUE;
            u32Fcr0RegValue = LDI_FCR0_EDC(0U) | LDI_FCR0_WMRK(4U);

            if (FALSE != pInitStruct->tEnChannelfg.bChannel1En)
            {
                u32PinsMask |= 0x2U;
                pLdiHandle->tStatus.tChannelState.bChannel1En = TRUE;
                u32Fcr1RegValue |= LDI_FCR1_EDC(0U) | LDI_FCR0_WMRK(4U);
            }

            if (FALSE != pInitStruct->tEnChannelfg.bChannel2En)
            {
                u32PinsMask |= 0x4U;
                pLdiHandle->tStatus.tChannelState.bChannel2En = TRUE;
                u32Fcr2RegValue |= LDI_FCR2_EDC(0U) | LDI_FCR0_WMRK(4U);
            }
        
            if (FALSE != pInitStruct->tEnChannelfg.bChannel3En)
            {
                u32PinsMask |= 0x8U;
                pLdiHandle->tStatus.tChannelState.bChannel3En = TRUE;
                u32Fcr3RegValue |= LDI_FCR3_EDC(0U) | LDI_FCR0_WMRK(4U);
            }
        }
        else
        {
            u32PinsMask = 0x1U;
            pLdiHandle->tStatus.tChannelState.bChannel0En = TRUE;
            u32Fcr0RegValue |= LDI_FCR0_EDC(1U) | LDI_FCR0_WMRK(4U);

            if (FALSE != pInitStruct->tEnChannelfg.bChannel1En)
            {
                u32PinsMask |= 0x2U;
                pLdiHandle->tStatus.tChannelState.bChannel1En = TRUE;
                u32Fcr1RegValue |= LDI_FCR1_EDC(1U) | LDI_FCR0_WMRK(4U);
            }

            if (FALSE != pInitStruct->tEnChannelfg.bChannel2En)
            {
                u32PinsMask |= 0x4U;
                pLdiHandle->tStatus.tChannelState.bChannel2En = TRUE;
                u32Fcr2RegValue |= LDI_FCR2_EDC(1U) | LDI_FCR0_WMRK(4U);
            }
        
            if (FALSE != pInitStruct->tEnChannelfg.bChannel3En)
            {
                u32PinsMask |= 0x8U;
                pLdiHandle->tStatus.tChannelState.bChannel3En = TRUE;
                u32Fcr3RegValue |= LDI_FCR3_EDC(1U) | LDI_FCR0_WMRK(4U);
            }            
        }

        LDI_HWA_CfgFcr0(pLdi, u32Fcr0RegValue);
        LDI_HWA_CfgFcr1(pLdi, u32Fcr1RegValue);
        LDI_HWA_CfgFcr2(pLdi, u32Fcr2RegValue);
        LDI_HWA_CfgFcr3(pLdi, u32Fcr3RegValue);
        LDI_HWA_EnableChannel(pLdi, u32PinsMask);

        /** Enable interrupt */
        LDI_HWA_ClearInterruptFlag(pLdi);
        
        pLdiHandle->tStatus.pUpdateCallback = pInitStruct->pUpdateCallback;
        pLdiHandle->tStatus.eLdiState = LDI_STATE_IDLE;
        pLdiHandle->tStatus.eLdiDisplayState = LDI_DISPLAY_STOP;

    #if LDI_DEV_ERROR_RELDI == STD_ON
    }
    #endif
}

/**
 * @brief Deinit ldi
 *
 * @param pLdiHandle pLdiHandle LDI handle for LDI functionality
 */
void LDI_Deinit(LDI_HandleType *pLdiHandle)
{
    #if LDI_DEV_ERROR_RELDI == STD_ON
    if (NULL == pLdiHandle)
    {
        LDI_ReportDevError(LDI_InitPins_ID, LDI_E_PARAM_INPUT);
    }
    else if (pLdiHandle->eInstance >= LDI_INSTANCE_COUNT)
    {
        LDI_ReportDevError(LDI_InitPins_ID, LDI_E_PARAM_INSTANCE);
    }
    else if ((LDI_STATE_UNINIT == pLdiHandle->tStatus.eLdiState))
    {
        LDI_ReportDevError(LDI_InitPins_ID, LDI_E_PARAM_STATUS);
    }
    else
    {
    #endif

        LDI_Type *pLdi = s_pLdiInstanceTable[pLdiHandle->eInstance];

        /** Reset register */
        LDI_HWA_ClearFIFO(pLdi);
        LDI_HWA_ClearFIFOStatus(pLdi);
        LDI_HWA_CfgCtrl(pLdi, 0x00010000U);
        LDI_HWA_CfgClkCtrl(pLdi, 0x00420000U);
        LDI_HWA_DisableInterrupt(pLdi);
        LDI_HWA_ClearInterruptFlag(pLdi);
        LDI_HWA_CfgPxCtrl(pLdi, 0x00000000U);
        LDI_HWA_CfgPxCtrl2(pLdi, 0x00000000U);
        LDI_HWA_CfgPxStatus(pLdi, 0xFFFFFF00U);
        LDI_HWA_CfgPxdRcfg(pLdi, 0x00000000U);
        LDI_HWA_CfgPxdGcfg(pLdi, 0x00000000U);
        LDI_HWA_CfgPxdScfg(pLdi, 0x00000000U);
        LDI_HWA_CfgPxdDcfg(pLdi, 0x00000000U);
        LDI_HWA_CfgPxdIcfg(pLdi, 0x00000000U);
        LDI_HWA_CfgFcr0(pLdi, 0x00000000U);
        LDI_HWA_CfgFcr1(pLdi, 0x00000000U);
        LDI_HWA_CfgFcr2(pLdi, 0x00000000U);
        LDI_HWA_CfgFcr3(pLdi, 0x00000000U);

        /** Reset status */
        pLdiHandle->eInstance = LDI0;
        pLdiHandle->tStatus.pUpdateCallback = NULL;
        pLdiHandle->tStatus.eLdiState = LDI_STATE_UNINIT;
        pLdiHandle->tStatus.eLdiDisplayState = LDI_DISPLAY_STOP;
        pLdiHandle->tStatus.tChannelState.bChannel0En = FALSE;
        pLdiHandle->tStatus.tChannelState.bChannel1En = FALSE;
        pLdiHandle->tStatus.tChannelState.bChannel2En = FALSE;
        pLdiHandle->tStatus.tChannelState.bChannel3En = FALSE;
   
    #if LDI_DEV_ERROR_RELDI == STD_ON
    }
    #endif
}

/**
 * @brief De-initialize the Ldi instance
 *
 * @param pLdiHandle pLdiHandle LDI handle for LDI functionality
 * @param pUpdateStruct Ldi update data struct
 * 
 * @return LDI_StatesType 
 */
LDI_StatesType LDI_Update(LDI_HandleType *pLdiHandle, const LDI_UpdateType *const pUpdateStruct)
{
    #if LDI_DEV_ERROR_RELDI == STD_ON
    if (NULL == pLdiHandle)
    {
        LDI_ReportDevError(LDI_InitPins_ID, LDI_E_PARAM_INPUT);
    }
    else if (pLdiHandle->eInstance >= LDI_INSTANCE_COUNT)
    {
        LDI_ReportDevError(LDI_InitPins_ID, LDI_E_PARAM_INSTANCE);
    }
    else if ((LDI_STATE_UNINIT == pLdiHandle->tStatus.eLdiState))
    {
        LDI_ReportDevError(LDI_InitPins_ID, LDI_E_PARAM_STATUS);
    }
    else if ((TRUE != pLdiHandle->tStatus.tChannelState.bChannel0En))
    {
        LDI_ReportDevError(LDI_InitPins_ID, LDI_E_PARAM_INPUT);
    }    
    else if (NULL == pUpdateStruct)
    {
        LDI_ReportDevError(LDI_InitPins_ID, LDI_E_PARAM_INPUT);
    }     
    else if ((0U != ((pUpdateStruct->u32LdiDatalen) & 0x1U)))
    {
        LDI_ReportDevError(LDI_InitPins_ID, LDI_E_PARAM_INPUT);
    }
    else if (NULL == pUpdateStruct->pLdiData0)
    {
        LDI_ReportDevError(LDI_InitPins_ID, LDI_E_PARAM_INPUT);
    }
    else if ((NULL == pUpdateStruct->pLdiData1) && (FALSE != pLdiHandle->tStatus.tChannelState.bChannel1En))
    {
        LDI_ReportDevError(LDI_InitPins_ID, LDI_E_PARAM_INPUT);
    }
    else if ((NULL == pUpdateStruct->pLdiData2) && (FALSE != pLdiHandle->tStatus.tChannelState.bChannel2En))
    {
        LDI_ReportDevError(LDI_InitPins_ID, LDI_E_PARAM_INPUT);
    }   
    else if ((NULL == pUpdateStruct->pLdiData3) && (FALSE != pLdiHandle->tStatus.tChannelState.bChannel3En))
    {
        LDI_ReportDevError(LDI_InitPins_ID, LDI_E_PARAM_INPUT);
    }           
    else
    {
    #endif

    LDI_StatesType eRet = LDI_STATUS_SUCCESS;

    if (LDI_STATE_IDLE != pLdiHandle->tStatus.eLdiState)
    {
    	eRet = LDI_STATUS_ERROR;
    }
    else
    {
        pLdiHandle->tStatus.eLdiState = LDI_STATE_BUSY;

        LDI_Type *pLdi = s_pLdiInstanceTable[pLdiHandle->eInstance];

        const uint32_t *pTempData0 = (uint32_t *)pUpdateStruct->pLdiData0;
        const uint32_t *pTempData1 = (uint32_t *)pUpdateStruct->pLdiData1;
        const uint32_t *pTempData2 = (uint32_t *)pUpdateStruct->pLdiData2;
        const uint32_t *pTempData3 = (uint32_t *)pUpdateStruct->pLdiData3;


        uint32_t  u32LdiTimeOut = 0xFFFFFFFFU;

        uint32_t  u32Cnt = 0U;
        uint32_t  u32TrSizeValue = pUpdateStruct->u32LdiDatalen >> 0x1U;

        uint32_t  u32leftDatalen = pUpdateStruct->u32LdiDatalen & 0x3U;
        uint32_t  u32Clearlen = ((pUpdateStruct->u32LdiDatalen - u32leftDatalen) >> 2U);

        if (TRUE != pLdiHandle->tStatus.tChannelState.bChannel1En)
        {
            pTempData1 = pTempData0;
        }
        if (TRUE != pLdiHandle->tStatus.tChannelState.bChannel2En)
        {
            pTempData2 = pTempData0;
        }
           
        if (TRUE != pLdiHandle->tStatus.tChannelState.bChannel3En)
        {
            pTempData3 = pTempData0;
        }
        
        LDI_HWA_ClearFIFO(pLdi);
        LDI_HWA_SetTrSize(pLdi, u32TrSizeValue);
        LDI_HWA_EnableInterrupt(pLdi);

        if (u32Clearlen < 4U )
        {   
            if (0U < u32Clearlen)
            {
                for (u32Cnt = 0U; u32Cnt < u32Clearlen; u32Cnt++)
                {
                    pLdi->FDR0 = *pTempData0;
                    pLdi->FDR1 = *pTempData1;
                    pLdi->FDR2 = *pTempData2;
                    pLdi->FDR3 = *pTempData3;
                    pTempData0++;
                    pTempData1++;
                    pTempData2++;
                    pTempData3++;
                }
                LDI_HWA_UpdateStart(pLdi);
            }
        }
        else
        {
            for (u32Cnt = 0U; u32Cnt < 4U; u32Cnt++)
            {
                pLdi->FDR0 = *pTempData0;
                pLdi->FDR1 = *pTempData1;
                pLdi->FDR2 = *pTempData2;
                pLdi->FDR3 = *pTempData3;
                pTempData0++;
                pTempData1++;
                pTempData2++;
                pTempData3++;
            }

            LDI_HWA_UpdateStart(pLdi);

            while ((u32Cnt < u32Clearlen) && (0U != u32LdiTimeOut))
            {
                if (LDI_HWA_GetCh0FifoFillLevel(pLdi) < (LDI_FIFO_DEPTH - 1U))
                {
                    pLdi->FDR0 = *pTempData0;
                    pLdi->FDR1 = *pTempData1;
                    pLdi->FDR2 = *pTempData2;
                    pLdi->FDR3 = *pTempData3;
                    pTempData0++;
                    pTempData1++;
                    pTempData2++;
                    pTempData3++;
                    u32Cnt++;
                }
                u32LdiTimeOut--;
            }
        }

        /** Data len is 2 Byte*/
        if (0U < u32leftDatalen)
        {
            if (LDI_HWA_GetCh0FifoFillLevel(pLdi) < LDI_FIFO_DEPTH)
            {
                pLdi->FDR0 = (uint16)(*pTempData0);
                pLdi->FDR1 = (uint16)(*pTempData1);
                pLdi->FDR2 = (uint16)(*pTempData2);
                pLdi->FDR3 = (uint16)(*pTempData3);
            }

            if (0U == u32Clearlen)
            {
                LDI_HWA_UpdateStart(pLdi);
            }       
        }

        u32LdiTimeOut = 0xFFFFFFFFU;

        while (0U != u32LdiTimeOut)
        {
            if (0U != LDI_HWA_GetUpdateFlag(pLdi))
            {
                pLdiHandle->tStatus.eLdiState = LDI_STATE_IDLE;
                LDI_HWA_DisableInterrupt(pLdi);
                LDI_HWA_ClearInterruptFlag(pLdi);
                LDI_HWA_ClearFIFO(pLdi);
                break;
            }
            u32LdiTimeOut--;
        }

        if (0U == u32LdiTimeOut)
        {
        	eRet = LDI_STATUS_TIMEOUT;
        	LDI_HWA_DisableInterrupt(pLdi);
        	LDI_HWA_ClearInterruptFlag(pLdi);
        	LDI_HWA_ClearFIFO(pLdi);
        }          
    }

    return eRet;
   
    #if LDI_DEV_ERROR_RELDI == STD_ON
    }
    #endif
}

/**
 * @brief Update data in DMA mode (Non-block)
 *
 * @param pLdiHandle pLdiHandle LDI handle for LDI functionality
 * @param pUpdateStruct Ldi update data struct
 * 
 * @return LDI_StatesType 
 */
LDI_StatesType LDI_Update_DMA(LDI_HandleType *pLdiHandle, const LDI_UpdateType *const pUpdateStruct)
{
    #if LDI_DEV_ERROR_RELDI == STD_ON
    if (NULL == pLdiHandle)
    {
        LDI_ReportDevError(LDI_InitPins_ID, LDI_E_PARAM_INPUT);
    }
    else if (pLdiHandle->eInstance >= LDI_INSTANCE_COUNT)
    {
        LDI_ReportDevError(LDI_InitPins_ID, LDI_E_PARAM_INSTANCE);
    }
    else if ((LDI_STATE_UNINIT == pLdiHandle->tStatus.eLdiState))
    {
        LDI_ReportDevError(LDI_InitPins_ID, LDI_E_PARAM_STATUS);
    }
    else if ((TRUE != pLdiHandle->tStatus.tChannelState.bChannel0En))
    {
        LDI_ReportDevError(LDI_InitPins_ID, LDI_E_PARAM_INPUT);
    }    
    else if (NULL == pUpdateStruct)
    {
        LDI_ReportDevError(LDI_InitPins_ID, LDI_E_PARAM_INPUT);
    }     
    else if ((0U != ((pUpdateStruct->u32LdiDatalen) & 0x1U)))
    {
        LDI_ReportDevError(LDI_InitPins_ID, LDI_E_PARAM_INPUT);
    }        
    else
    {
    #endif

        LDI_StatesType eRet = LDI_STATUS_SUCCESS;

        if (LDI_STATE_IDLE != pLdiHandle->tStatus.eLdiState)
        {
        	eRet = LDI_STATUS_ERROR;
        }
        else
        {
            LDI_Type *pLdi = s_pLdiInstanceTable[pLdiHandle->eInstance];
            
            uint32_t  u32TrSizeValue = pUpdateStruct->u32LdiDatalen >> 0x1U;

            LDI_HWA_ClearFIFO(pLdi);
            LDI_HWA_SetTrSize(pLdi, u32TrSizeValue);
            LDI_HWA_EnableDma(pLdi);
            LDI_HWA_EnableInterrupt(pLdi);
            LDI_HWA_UpdateStart(pLdi);
        }

        return eRet;

    #if LDI_DEV_ERROR_RELDI == STD_ON
    }
    #endif
}

/**
 * @brief Ldi start display
 *
 * @param pLdiHandle pLdiHandle LDI handle for LDI functionality
 */
void LDI_Dispaly_Start(LDI_HandleType *pLdiHandle)
{
    #if LDI_DEV_ERROR_RELDI == STD_ON
    if (NULL == pLdiHandle)
    {
        LDI_ReportDevError(LDI_InitPins_ID, LDI_E_PARAM_INPUT);
    }
    else if (pLdiHandle->eInstance >= LDI_INSTANCE_COUNT)
    {
        LDI_ReportDevError(LDI_InitPins_ID, LDI_E_PARAM_INSTANCE);
    }
    else if ((LDI_STATE_UNINIT == pLdiHandle->tStatus.eLdiState))
    {
        LDI_ReportDevError(LDI_InitPins_ID, LDI_E_PARAM_STATUS);
    }
    else
    {
    #endif
        if (LDI_DISPLAY_START != pLdiHandle->tStatus.eLdiDisplayState)
        {
            LDI_Type *pLdi = s_pLdiInstanceTable[pLdiHandle->eInstance];

            LDI_HWA_CfgDisplay(pLdi);
        }
    #if LDI_DEV_ERROR_RELDI == STD_ON
    }
    #endif
}

/**
 * @brief Ldi stop display
 *
 * @param pLdiHandle pLdiHandle LDI handle for LDI functionality
 */
void LDI_Dispaly_Stop(LDI_HandleType *pLdiHandle)
{
    #if LDI_DEV_ERROR_RELDI == STD_ON
    if (NULL == pLdiHandle)
    {
        LDI_ReportDevError(LDI_InitPins_ID, LDI_E_PARAM_INPUT);
    }
    else if (pLdiHandle->eInstance >= LDI_INSTANCE_COUNT)
    {
        LDI_ReportDevError(LDI_InitPins_ID, LDI_E_PARAM_INSTANCE);
    }
    else if ((LDI_STATE_UNINIT == pLdiHandle->tStatus.eLdiState))
    {
        LDI_ReportDevError(LDI_InitPins_ID, LDI_E_PARAM_STATUS);
    }
    else
    {
    #endif
        if (LDI_DISPLAY_STOP != pLdiHandle->tStatus.eLdiDisplayState)
        {
            LDI_Type *pLdi = s_pLdiInstanceTable[pLdiHandle->eInstance];

            LDI_HWA_CfgDisplay(pLdi);
        }
    #if LDI_DEV_ERROR_RELDI == STD_ON
    }
    #endif
}

/**
 * @brief LDIn Interrupt Handler.
 *
 * @param pLdiHandle pLdiHandle LDI handle for LDI functionality
 */
void LDIn_IRQHandler(LDI_HandleType *pLdiHandle)
{
    #if LDI_DEV_ERROR_RELDI == STD_ON
    if (NULL == pLdiHandle)
    {
        LDI_ReportDevError(LDI_InitPins_ID, LDI_E_PARAM_INPUT);
    }
    else if (pLdiHandle->eInstance >= LDI_INSTANCE_COUNT)
    {
        LDI_ReportDevError(LDI_InitPins_ID, LDI_E_PARAM_INSTANCE);
    }
    else if ((LDI_STATE_UNINIT == pLdiHandle->tStatus.eLdiState))
    {
        LDI_ReportDevError(LDI_InitPins_ID, LDI_E_PARAM_STATUS);
    }
    else
    {
    #endif

        LDI_Type *pLdi = s_pLdiInstanceTable[pLdiHandle->eInstance];
        uint32_t  u32LdiTimeOut = 0xFFFFFFFFU;

        LDI_HWA_DisableDma(pLdi);

        while(0U != u32LdiTimeOut)
        {
            if (0U != LDI_HWA_GetUpdateFlag(pLdi))
            {
                pLdiHandle->tStatus.eLdiState = LDI_STATE_IDLE;
                LDI_HWA_DisableInterrupt(pLdi);
                LDI_HWA_ClearInterruptFlag(pLdi);
                LDI_HWA_ClearFIFO(pLdi);
                if (NULL != pLdiHandle->tStatus.pUpdateCallback)
                {
                	pLdiHandle->tStatus.pUpdateCallback();
                }

                break;
            }
            u32LdiTimeOut--;
        }
    #if LDI_DEV_ERROR_RELDI == STD_ON
    }
    #endif
}
#endif


