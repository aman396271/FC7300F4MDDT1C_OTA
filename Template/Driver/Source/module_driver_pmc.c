/* @file module_driver_pmc.c
* @author Flagchip032
* @brief FC7xxx PMC driver type definition and API
* @version 0.2.0
 * @date 2024-08-20
*
* @copyright Copyright (c) 2022 Flagchip Semiconductors Co., Ltd.
*
*/
/* ********************************************************************************
  *   Revision History:
  *
  *   Version     Date          Initials          Descriptions
  *   ---------   ----------    ------------     ---------------
  *   0.1.0       2022-11-21    Flagchip032      First version for FC7xxx
  ******************************************************************************** */
#include "module_driver_pmc.h"

#if PMC_INSTANCE_COUNT > 0U

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus*/

#ifndef PMC_DEV_ERROR_REPORT
#define PMC_DEV_ERROR_REPORT    STD_OFF
#endif

#if PMC_DEV_ERROR_REPORT == STD_ON
#define PMC_ReportDevError(func, error) ReportDevError(PMC_MODULE_ID, func, error)
#endif


/***************** Local variable *********************/


/***************** prototype *********************/

/***************** Global Functions *********************/
/**
 * @brief PMC get status flag
 *
 * This function returns the state of a status flag.
 *
 * @param eFlag PMC flag type
 * @return true the flag bit is 1,false the flag bit is 0
 */
bool PMC_GetFlag(PMC_FlagType eFlag)
{
    return ((PMC_HWA_GetLVSCR() & (uint32_t)eFlag) != 0U) ? true : false;
}

/**
 * @brief PMC clears an individual status flag.
 *
 * This function clears an individual status flag (see pmc_status_flag_t for list of status bits).
 *
 * @param eFlag PMC flag type
 */
void PMC_ClearFlag(PMC_FlagType eFlag)
{
    PMC_HWA_SetLVSCR((uint32_t)eFlag);
}

/**
 * @brief PMC get status
 *
 * @param eStatus the status type
 * @return true the status bit return 1
 * @return false the status bit return 0
 */
bool PMC_GetStatus(PMC_StatusType eStatus)
{
    return ((PMC_HWA_GetLVSCR() & (uint32_t)eStatus) != 0U) ? true : false;
}

/**
 * @brief Enable PMC interrupt
 * @param the parameter of interrupt flag
 */
void Pmc_EnableInterrupt(uint32 u32Val)
{
    Pmc_HWA_EnableInterrupt(u32Val);
}

/**
 * @brief Disable PMC interrupt
 * @param the parameter of interrupt flag
 */
void Pmc_DisableInterrupt(uint32 u32Val)
{
    PMC_HWA_DisableInterrupt(u32Val);
}

/**
 * @brief PMC Init
 *
 * @param pPmcHandle Pmc handle
 * @param pIntCfg    Pmc initialize configuration
 */
void Pmc_Init(PMC_HandleType* pPmcHandle, PMC_ConfigType *pIntCfg)
{
#if PMC_DEV_ERROR_REPORT == STD_ON
    if (NULL == pIntCfg)
    {
        PMC_ReportDevError(PMC_INIT_ID, PMC_E_PARAM_POINTER);
    }
    else
    {
#endif

    bool bIntrEn = false;
    uint32_t u32Temp;

    /* Clear all LVSCR flag */
    PMC_HWA_SetLVSCR(LVSCR_DEFAULT_VAL);

    u32Temp =
#if PMC_V15_CTRL_SUPPORT
              PMC_CONFIG_V15_CTRL_EN(pIntCfg->bV15CtrlEn) |
              PMC_CONFIG_V15_AUTOSW(pIntCfg->bV15AutoswEn)|
#endif
#if PMC_HVD5VB_SUPPORT
              PMC_CONFIG_5VB_MON_EN(pIntCfg->b5VBMonEn) |
#endif /* PMC_HVD5VB_SUPPORT */
              PMC_CONFIG_RPM_VDD2P5_EN(pIntCfg->bRpmV25En);


    PMC_HWA_SetCONFIG(u32Temp);

    /* Interrupt configuration */
    if ((uint32_t)PMC_INTR_MASK_HVD == ((uint32_t)PMC_INTR_MASK_HVD & (pIntCfg->u32InterruptMask)))
    {
        Pmc_EnableInterrupt(HVD_INTERRUPT);
        bIntrEn = true;
    }

    if ((uint32_t)PMC_INTR_MASK_LVD == ((uint32_t)PMC_INTR_MASK_LVD & (pIntCfg->u32InterruptMask)))
    {
        Pmc_EnableInterrupt(LVD_INTERRUPT);
        bIntrEn = true;
    }

    if ( true == bIntrEn)
    {
        pPmcHandle->pPmcFaultNotify = pIntCfg->pPmcFaultNotify;
        pPmcHandle->pPmcRecoveryNotify = pIntCfg->pPmcRecoveryNotify;
    }

#if PMC_DEV_ERROR_REPORT == STD_ON
    }
#endif
}

/**
 * @brief Clear all PMC register
 *
 */
void PMC_Deinit(void)
{
    PMC_HWA_SetLVSCR(LVSCR_DEFAULT_VAL);
    PMC_HWA_SetCONFIG(CONFIG_DEFAULT_VAL);
}

/**
 * @brief PMC_UserIRQHandler function
 * Customer needs to write this function according by customer's requirement. This function is only resolve compile conflict
 *
 * @param pPmcHandle Pmc handle
 *
 */
void PMC_UserIRQHandler(PMC_HandleType* pPmcHandle)
{
    /* high voltage detection of 5V interrupt, keep CPU running in this loop until HVD fault disappear */
    if (PMC_GetFlag(PMC_HVD5V_FLAG) && PMC_ReadHVDInterruptFlag())
    {
        PMC_ClearFlag(PMC_HVD5V_FLAG);

        if (TRUE == (PMC_GetStatus(PMC_HVD5V_STATUS)))
        {
            if (NULL != pPmcHandle->pPmcFaultNotify)
            {
                pPmcHandle->pPmcFaultNotify(pPmcHandle, PMC_HVD5V);
            }
        }
        else
        {
            /*The V5 has resumed from High Power*/
            if (NULL != pPmcHandle->pPmcRecoveryNotify)
            {
                pPmcHandle->pPmcRecoveryNotify(pPmcHandle, PMC_HVD5V);
            }
        }
    }
#if PMC_HVD5VB_SUPPORT
    /* high voltage detection of 5VB interrupt, keep CPU running in this loop until HVD fault disappear */
    else if (PMC_GetFlag(PMC_HVD5VB_FLAG) && PMC_ReadHVDInterruptFlag())
    {
        PMC_ClearFlag(PMC_HVD5VB_FLAG);

        if (TRUE == (PMC_GetStatus(PMC_HVD5VB_STATUS)))
        {
            if (NULL != pPmcHandle->pPmcFaultNotify)
            {
                pPmcHandle->pPmcFaultNotify(pPmcHandle, PMC_HVD5VB);
            }
        }
        else
        {
            /*The V5B has resumed from High Power*/
            if (NULL != pPmcHandle->pPmcRecoveryNotify)
            {
            	pPmcHandle->pPmcRecoveryNotify(pPmcHandle, PMC_HVD5VB);
            }
        }
    }
#endif /* PMC_HVD5VB_SUPPORT */
    /* high voltage detection of V25 interrupt, keep CPU running in this loop until HVD fault disappear */
    else if (PMC_GetFlag(PMC_HVD2P5V_FLAG) && PMC_ReadHVDInterruptFlag())
    {
        PMC_ClearFlag(PMC_HVD2P5V_FLAG);

        if (TRUE == (PMC_GetStatus(PMC_HVD2P5V_STATUS)))
        {
            if (NULL != pPmcHandle->pPmcFaultNotify)
            {
                pPmcHandle->pPmcFaultNotify(pPmcHandle, PMC_HVD2P5V);
            }
        }
        else
        {
            /*The V25 has resumed from High Power*/
            if (NULL != pPmcHandle->pPmcRecoveryNotify)
            {
            	pPmcHandle->pPmcRecoveryNotify(pPmcHandle, PMC_HVD2P5V);
            }
        }
    }
    /* high voltage detection of V11 interrupt, keep CPU running in this loop until HVD fault disappear */
    else if (PMC_GetFlag(PMC_HVD1P1V_FLAG) && PMC_ReadHVDInterruptFlag())
    {
        PMC_ClearFlag(PMC_HVD1P1V_FLAG);

        if (TRUE == (PMC_GetStatus(PMC_HVD1P1V_STATUS)))
        {
            if (NULL != pPmcHandle->pPmcFaultNotify)
            {
                pPmcHandle->pPmcFaultNotify(pPmcHandle, PMC_HVD1P1V);
            }
        }
        else
        {
            /*The V11 has resumed from High Power*/
            if (NULL != pPmcHandle->pPmcRecoveryNotify)
            {
            	pPmcHandle->pPmcRecoveryNotify(pPmcHandle, PMC_HVD1P1V);
            }
        }
    }
    /* low voltage detection of V5 interrupt, keep CPU running in this loop until LVD fault disappear */
    else if (PMC_GetFlag(PMC_LVD5V_FLAG) && PMC_ReadLVDInterruptFlag())
    {
        PMC_ClearFlag(PMC_LVD5V_FLAG);

        if (TRUE == (PMC_GetStatus(PMC_LVD5V_STATUS)))
        {
            if (NULL != pPmcHandle->pPmcFaultNotify)
            {
                pPmcHandle->pPmcFaultNotify(pPmcHandle, PMC_LVD5V);
            }
        }
        else
        {
            /*The V5 has resumed from High Power*/
            if (NULL != pPmcHandle->pPmcRecoveryNotify)
            {
            	pPmcHandle->pPmcRecoveryNotify(pPmcHandle, PMC_LVD5V);
            }
        }
    }
#if PMC_V15_FLAG_SUPPORT
    /* low voltage detection of V15 interrupt, keep CPU running in this loop until LVD fault disappear */
    else if (PMC_GetFlag(PMC_LVD1P5V_FLAG) && PMC_ReadLVDInterruptFlag())
    {
        PMC_ClearFlag(PMC_LVD1P5V_FLAG);

        if (TRUE == (PMC_GetStatus(PMC_LVD1P5V_STATUS)))
        {
            if (NULL != pPmcHandle->pPmcFaultNotify)
            {
                pPmcHandle->pPmcFaultNotify(pPmcHandle, PMC_LVD1P5V);
            }
        }
        else
        {
            /*The V15 has resumed from High Power*/
            if (NULL != pPmcHandle->pPmcRecoveryNotify)
            {
            	pPmcHandle->pPmcRecoveryNotify(pPmcHandle, PMC_LVD1P5V);
            }
        }
    }
    /* high voltage detection of 1.5V interrupt, keep CPU running in this loop until HVD fault disappear */
    else if (PMC_GetFlag(PMC_HVD1P5V_FLAG) && PMC_ReadHVDInterruptFlag())
    {
        PMC_ClearFlag(PMC_HVD1P5V_FLAG);
        if (TRUE == (PMC_GetStatus(PMC_HVD1P5V_STATUS)))
        {
            if (NULL != pPmcHandle->pPmcFaultNotify)
            {
                pPmcHandle->pPmcFaultNotify(pPmcHandle, PMC_HVD1P5V);
            }
        }
        else
        {
            /*The V15 has resumed from High Power!*/
            if (NULL != pPmcHandle->pPmcRecoveryNotify)
            {
            	pPmcHandle->pPmcRecoveryNotify(pPmcHandle, PMC_HVD1P5V);
            }
        }
    }
#endif /*#ifndef PMC_USERGPR_SUPPORT*/
    else
    {
        /* some error */
    }
}

#endif /* #if PMC_INSTANCE_COUNT > 0U */
