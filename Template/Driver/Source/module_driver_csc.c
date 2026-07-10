/**
 * @file module_driver_csc.h
 * @author Flagchip
 * @brief csc driver type definition and API
 * @version 2.0.0
 * @date 2024-08-20
 *
 * SDK Version: 2.6.0
 *

 * @copyright Copyright (c) 2024 Flagchip Semiconductors Co., Ltd.
 *
 */

/* ********************************************************************************
   *   Revision History:
   *
   *   Version     Date          Initials      CR#          Descriptions
   *   ---------   ----------    ------------  ----------   ---------------
   *   2.0.0       2024-08-30    Flagchip055    N/A          Update file structures
   ******************************************************************************** */

#include "module_driver_csc.h"

#if CSC0_INSTANCE_COUNT > 0U

#include "module_driver_scg.h"


/********* Local Variables ************/

/********* Local function ************/

/********* Global function ************/
#if CSC0_CLOCKCONFIG_SUPPORT
/**
 * @brief set clock out. with clock out pin configure, the clock would be monitored.
 *        This Function may combined with SCG_ClkOut setting
 *        need to call SCG_SetClkOut,if clock out source set to SCG_CLKOUT. *
 * @param pCsc0ClkOut to Csc0ClkOut instance for clock out configuration
 * @param bLockStatus to lock current register
 *
 * @return Set clock out operation success/failed
 * @note  configuration sequence:
 *           1. Disable CLKOUTEN
 *           2. Set CLKOUTSEL
 *           3. Enable CLKOUTEN
 */
CSC_RetStatusType CSC0_SetClockOut(const CSC0_ClkoutType *const pCsc0ClkOut, bool bLockStatus)
{
    CSC_RetStatusType eRetVal = CSC_E_NOT_OK;
#if CSC0_DEV_ERROR_REPORT == STD_ON
    if (pCsc0ClkOut == NULL)
    {
        CSC0_ReportDevError(CSC0_SET_CLOCK_OUT_ID, CSC0_E_PARAM_POINTER);
    }
    else
    {
#endif

        /* Check CSC0_CLKOUT_CTRL register lock status */
        if (0U == CSC0_HWA_CLKOUT_CTRL_GetLockStatus())
        {
            /* Disable CLKOUTEN */
            CSC0_HWA_DisableClockOut();
            /* Set CLKOUTDIV */
            CSC0_HWA_SetClkOutDiv(pCsc0ClkOut->eDivider);
            /* Set CLKOUTSEL */
            CSC0_HWA_SetClkOutSel(pCsc0ClkOut->eClkOutSrc);
            /* Enable CLKOUTEN */
            CSC0_HWA_EnableClockOut();

            if (true == bLockStatus)
            {
                /* Lock CSC0_CLKOUT_CTRL register */
                CSC0_HWA_LockCLKOUT_CTRL();
            }
            else
            {
                /* No deal with */
            }

            eRetVal = CSC_E_OK;
        }
        else
        {
            /* No deal with */
        }

#if CSC0_DEV_ERROR_REPORT == STD_ON
    }
#endif

    return eRetVal;
}

/**
 * @brief set always on clock source configuration include AON32K, RTC, AONCLK clock.
 *
 * @param pAonclkSrcType pointer to AONCLKSR instance for AON clock source configuration
 * @param bLockStatus to lock current register
 *
 * @return Set clock out operation success/failed
 */
CSC_RetStatusType CSC0_SetAonClkSrc(const CSC0_AONCLKSRType *const pAonclkSrcType, bool bLockStatus)
{
    CSC_RetStatusType eRetVal = CSC_E_NOT_OK;

#if CSC0_DEV_ERROR_REPORT == STD_ON
    if (pAonclkSrcType == NULL)
    {
        CSC0_ReportDevError(CSC0_SET_AONCLKSRC_ID, CSC0_E_PARAM_POINTER);
    }
    else
    {
#endif

        /* Check CSC0_AONCLKSR register lock status */
        if (0U == CSC0_HWA_AONCLKSR_GetLockStaus())
        {
            /* Gating SIRC_32K clock*/
            if ((CSC0_AON32K_SIRCDIV_32K_CLK == pAonclkSrcType->eAon32KSel) ||
                    (CSC0_AON_SIRCDIV_32K_CLK == pAonclkSrcType->eAonSel) ||
                    (CSC0_RTC_SIRCDIV_32K_CLK == pAonclkSrcType->eRtcSel))
            {
                CSC0_HWA_EnableSIRCDIV_32KClkOut();
            }
            else
            {
                /* No deal with */
            }

            /* Gating SIRC32_1K clock*/
            if (CSC0_AON_SIRC32_1K_CLK == pAonclkSrcType->eAonSel)
            {
                CSC0_HWA_EnableSIRC32_1KClkOut();
            }
            else
            {
                /* No deal with */
            }

            /* Set AONCLOCK configuration */
            CSC0_HWA_SetAON32kClkSrc(pAonclkSrcType->eAon32KSel);
            CSC0_HWA_SetRTCClkSrc(pAonclkSrcType->eRtcSel);
            CSC0_HWA_SetAONClkSrc(pAonclkSrcType->eAonSel);

            if (true == bLockStatus)
            {
                /* Lock CSC0_AONCLKSR register */
                CSC0_HWA_LockAONCLKSR();
            }
            else
            {
                /* No deal with */
            }

            eRetVal = CSC_E_OK;
        }
        else
        {
            /* No deal with */
        }

#if CSC0_DEV_ERROR_REPORT == STD_ON
    }
#endif

    return eRetVal;
}

/**
 * @brief Report the clock source status and frequency configured in MCU run time.
 *        The clock frequency and status would change by clock set function.
 *
 * @param eClkkName: the CSC0 clock source to query
 * @param pFreq: frequency variable point to get the frequency value
 * @return true or false. This indicate the clock source status invalid or request clock source out of
 *         range.
 */
CSC_RetStatusType CSC0_GetCSC0ClockFreq(const CSC0_ClkSrcType eClkkName, uint32_t *const pFreq)
{
    CSC_RetStatusType eRetVal = CSC_E_NOT_OK;
    uint32_t u32TempVal;

#if CSC0_DEV_ERROR_REPORT == STD_ON
    if (pFreq == NULL)
    {
        CSC0_ReportDevError(CSC0_GET_CLOCK_FREQ_ID, CSC0_E_PARAM_POINTER);
    }
    else if (eClkkName > CSC0_END_OF_CLOCKS)
    {
        CSC0_ReportDevError(CSC0_GET_CLOCK_FREQ_ID, CSC0_E_PARAM_OUT_RANGE);
    }
    else
    {
#endif

        u32TempVal = CSC0_HWA_Get_AONCLKSR();

        if (CSC0_AON_CLK == eClkkName)
        {
            CSC0_AONClkSrcType eClockkRet = (CSC0_AONClkSrcType)(uint8_t)((u32TempVal & CSC0_AONCLKSR_AONCLKSEL_MASK) >> CSC0_AONCLKSR_AONCLKSEL_SHIFT);

            if (CSC0_AON_SIRCDIV_128K_CLK == eClockkRet)
            {
                *pFreq = CSC0_AONCLK_128K;
            }
            else if (CSC0_AON_SIRC32_1K_CLK == eClockkRet)
            {
                *pFreq = CSC0_AONCLK_1K;
            }
            else
            {
                *pFreq = CSC0_AONCLK_32K;
            }

            eRetVal = CSC_E_OK;
        }
        else if (CSC0_AON32K_CLK == eClkkName)
        {
            CSC0_AON32KClkSrcType eClockkRet = (CSC0_AON32KClkSrcType)(uint8_t)((u32TempVal & CSC0_AONCLKSR_AON32KCLKSEL_MASK) >> CSC0_AONCLKSR_AON32KCLKSEL_SHIFT);

            if (CSC0_AON32K_SOSC32K_CLK == eClockkRet)
            {
                *pFreq = CSC0_AONCLK_SOSC_32K;
            }
            else
            {
                *pFreq = CSC0_AONCLK_32K;
            }

            eRetVal = CSC_E_OK;
        }
        else if (CSC0_RTC_CLK == eClkkName)
        {
            CSC0_RTCClkSrcType eClockkRet = (CSC0_RTCClkSrcType)(uint8_t)((u32TempVal & CSC0_AONCLKSR_RTCCLKSEL_MASK) >> CSC0_AONCLKSR_RTCCLKSEL_SHIFT);
            if (CSC0_RTC_FOSCDIVL_CLK == eClockkRet)
            {
                *pFreq = SCG_GetScgClockFreq(SCG_FOSCDIVL_CLK);
            }
            else if (CSC0_RTC_SOSC_CLK == eClockkRet)
            {
                *pFreq = CSC0_AONCLK_SOSC_32K;
            }
            else
            {
                *pFreq = CSC0_AONCLK_32K;
            }

            eRetVal = CSC_E_OK;
        }
        else
        {
            /* Clock out or error parameter do not get frequency */
            *pFreq = 0U;
        }

#if CSC0_DEV_ERROR_REPORT == STD_ON
    }
#endif

    return eRetVal;
}
#endif /* CSC0_CLOCKCONFIG_SUPPORT */

#endif /* #if CSC0_INSTANCE_COUNT > 0U */
