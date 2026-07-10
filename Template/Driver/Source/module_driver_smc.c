/**
 * @file module_driver_smc.c
 * @author Flagchip
 * @brief SMC driver type definition and API
 * @version 2.0.0
 * @date 2024-08-20
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
*   0.1.0       2022-11-21    Flagchip032    N/A          FC7300 First version
*   0.2.0       2023-02-13    Flagchip032    N/A          optimize SMC driver code
*   2.0.0       2024-09-30    Flagchip055    N/A          Update file structures
********************************************************************************/
#include "module_driver_smc.h"
#include "module_driver_scg.h"

#if SCG_PLLX_CLK1_SUPPORT
#include "module_driver_cpm.h"
#endif

#if SMC_INSTANCE_COUNT > 0U

#if SCG_PLLX_CLK1_SUPPORT

SMC_PllStatusType tSmc_PllStatusBeforeStopMode =
{
    .bPll0Clk1GateOff = false,
#if SCG_PLL0_CLK2_SUPPORT
    .bPll0Clk2GateOff = false,
#endif /* SCG_PLL0_CLK2_SUPPORT */
#if SCG_PLL1_SUPPORT
    .bPll1Clk1GateOff = false,
#endif /* SCG_PLL1_SUPPORT */
};

static void SMC_EntryStopMode_PllxClk1_Clk2Status(void);
static void SMC_EntryStopMode_PLLClkOperation(void);
static void SMC_EntryStandbyMode_PllxClk1_Clk2Operation(void);
static void SMC_ExitStopMode_PllxOperation(void);

/**
 * @brief Check PLLx_CLK1 enable status
 *
 * @param void
 *
 * @ note
 *    INdex    PLL0/1_CLK1_CLK2     PLL0/1      Operation
 *      0       Enable               STEN         N/A
 *      1       Disable              STEN         N/A
 *      2       Enable              No STEN       ShutOff
 *      3       Disable             No STEN       N/A
 */
static void SMC_EntryStopMode_PllxClk1_Clk2Status(void)
{
    uint32_t u32CoreId;
    uint32_t u32Pll0CsrRegVal;
#if SCG_PLL1_SUPPORT
    uint32_t u32Pll1CsrRegVal;
#endif /* SCG_PLL1_SUPPORT */

    u32CoreId = Cpm_HWA_GetCoreId();

    if(0U == u32CoreId)
    {
    	u32Pll0CsrRegVal = SCG_HWA_GetPll0Csr();
#if SCG_PLL1_SUPPORT
    	u32Pll1CsrRegVal = SCG_HWA_GetPll1Csr();
#endif /* SCG_PLL1_SUPPORT */

        if(SCG_PLL0CSR_CK1EN_MASK == (u32Pll0CsrRegVal & SCG_PLL0CSR_CK1EN_MASK))
        {
            if(SCG_PLL0CSR_STEN_MASK == (u32Pll0CsrRegVal & SCG_PLL0CSR_STEN_MASK))
            {
                /* PLL0_CLK1 enable and PLL0 STEN */
                tSmc_PllStatusBeforeStopMode.bPll0Clk1GateOff = false;
            }
            else
            {
                /* PLL0_CLK1 enable and PLL0 no STEN */
                tSmc_PllStatusBeforeStopMode.bPll0Clk1GateOff = true;
            }
        }
        else
        {
            /* PLL0_CLK1 disable */
            tSmc_PllStatusBeforeStopMode.bPll0Clk1GateOff = false;
        }

#if SCG_PLL0_CLK2_SUPPORT
        if(SCG_PLL0CSR_CK2EN_MASK == (u32Pll0CsrRegVal & SCG_PLL0CSR_CK2EN_MASK))
        {
            if(SCG_PLL0CSR_STEN_MASK == (u32Pll0CsrRegVal & SCG_PLL0CSR_STEN_MASK))
            {
                /* PLL0_CLK2 enable and PLL0 STEN */
                tSmc_PllStatusBeforeStopMode.bPll0Clk2GateOff = false;
            }
            else
            {
                /* PLL0_CLK2 enable and PLL0 no STEN */
                tSmc_PllStatusBeforeStopMode.bPll0Clk2GateOff = true;
            }
        }
        else
        {
            /* PLL0_CLK2 disable */
            tSmc_PllStatusBeforeStopMode.bPll0Clk2GateOff = false;
        }
#endif /* SCG_PLL0_CLK2_SUPPORT */

#if SCG_PLL1_SUPPORT
        if(SCG_PLL1CSR_CK1EN_MASK == (u32Pll1CsrRegVal & SCG_PLL1CSR_CK1EN_MASK))
        {
            if(SCG_PLL1CSR_STEN_MASK == (u32Pll1CsrRegVal & SCG_PLL1CSR_STEN_MASK))
            {
                /* PLL1_CLK1 enable and PLL1 STEN */
                tSmc_PllStatusBeforeStopMode.bPll1Clk1GateOff = false;
            }
            else
            {
                /* PLL1_CLK1 enable and PLL1 no STEN */
                tSmc_PllStatusBeforeStopMode.bPll1Clk1GateOff = true;
            }
        }
        else
        {
            /* PLL1_CLK1 disable*/
            tSmc_PllStatusBeforeStopMode.bPll1Clk1GateOff = false;
        }
#endif /* SCG_PLL1_SUPPORT */
    }
    else
    {
        /* Not Core 0, do nothing */
    }
}

/**
 * @brief Set Pll Operation before stop mode
 *
 * @note Core 0 operate
 *
 */
static void SMC_EntryStopMode_PLLClkOperation(void)
{
    uint32_t u32CoreId;

    u32CoreId = Cpm_HWA_GetCoreId();

    if(0U == u32CoreId)
    {
        /* PLL0_CLK1 operation before entry stop mode */
        if(true == tSmc_PllStatusBeforeStopMode.bPll0Clk1GateOff)
        {
            /* PLL0_CLK1 need to be gated off */
            SCG_HWA_UnlockPllCsr(SCG_PLL0_CLOCK_SYMBOL);
            SCG_HWA_DisablePLL0CLK1Output();
        }
        else
        {
            /* PLL0_CLK1 no need operation */
        }

#if SCG_PLL0_CLK2_SUPPORT
        /* PLL0_CLK2 operation before entry stop mode */
        if(true == tSmc_PllStatusBeforeStopMode.bPll0Clk2GateOff)
        {
            /* PLL0_CLK1 need to be gated off */
            SCG_HWA_UnlockPllCsr(SCG_PLL0_CLOCK_SYMBOL);
            SCG_HWA_DisablePLL0CLK2Output();
        }
        else
        {
            /* PLL0_CLK2 no need operation */
        }
#endif /* SCG_PLL0_CLK2_SUPPORT */

#if SCG_PLL1_SUPPORT
        /* PLL1_CLK1 operation before entry stop mode */
        if(true == tSmc_PllStatusBeforeStopMode.bPll1Clk1GateOff)
        {
            /* PLL1_CLK1 need to be gated off */
            SCG_HWA_UnlockPllCsr(SCG_PLL1_CLOCK_SYMBOL);
            SCG_HWA_DisablePLL1CLK1Output();
        }
        else
        {
            /* PLL1_CLK1 no need operation */
        }
#endif /* SCG_PLL1_SUPPORT */
    }
    else
    {
        /* Not Core 0, do nothing */
    }
}

/**
 * @brief Restore PLL0_CLK1, PLL0_CLK2 and PLL1_CLK1 configuration when exit stop mode
 *
 * @note Core 0 operate
 *
 */
static void SMC_ExitStopMode_PllxOperation(void)
{
    uint32_t u32CoreId;
    uint32_t u32TempVal;
    uint32_t u32ScgCsrRegVal;
    uint32_t u32Pll0CsrRegVal;
#if SCG_PLL1_SUPPORT
    uint32_t u32Pll1CsrRegVal;
#endif /* SCG_PLL1_SUPPORT */
    SCG_ClockCtrlType tSysClkCfg;
    SCG_StatusType eStatusVal = SCG_STATUS_SUCCESS;
    SCG_FircType tFircCfg =
    {
        .bLock = false,
        .bCm   = false,
        .bTrEn = false,
        .bSten = false,
        .u8TrimSrc = 0U,
        .eDivL = SCG_ASYNCCLOCKDIV_BY4,
        .eDivM = SCG_ASYNCCLOCKDIV_BY2,
        .eDivH = SCG_ASYNCCLOCKDIV_BY1
    };

    u32CoreId = Cpm_HWA_GetCoreId();

    if(0U == u32CoreId)
    {
        /* PLL0 Operation */
        if( (true == tSmc_PllStatusBeforeStopMode.bPll0Clk1GateOff)
#if SCG_PLL0_CLK2_SUPPORT
            || (true == tSmc_PllStatusBeforeStopMode.bPll0Clk2GateOff)
#endif /* SCG_PLL0_CLK2_SUPPORT */
          )
        {
            /* Record SCG CSR register value. */
            u32ScgCsrRegVal = SCG_HWA_GetCSR();

            if( (uint8_t)SCG_CLOCK_SRC_PLL0 == SCG_HWA_GetSysClkSrc())
            {
                /* System clock is PLL0, change to FIRC first.  */
                eStatusVal = SCG_SwitchSystemClock(SCG_CLOCK_SRC_FIRC);
                if (SCG_STATUS_SEQUENCE_ERROR == eStatusVal)
                {
                    eStatusVal = SCG_EnableFIRC(&tFircCfg);
                    if (SCG_STATUS_TIMEOUT != eStatusVal)
                    {
                        eStatusVal = SCG_SwitchSystemClock(SCG_CLOCK_SRC_FIRC);
                    }
                }
                else
                {
                    /* do nothing */
                }
            }
            else
            {
                /* System clock is not PLL0, no change.  */
            }

            if (SCG_STATUS_SUCCESS == eStatusVal)
            {
                u32Pll0CsrRegVal = SCG_HWA_GetPll0Csr();

                /* Turn off PLL0, because re-enable PLL0_CLK1 and PLL0_CLK2 need keep PLL0 EN is 0 */
                /* PLL0_CLK1 and PLL0_CLK2 has been turn off before entry stop mode */
                SCG_HWA_UnlockPllCsr(SCG_PLL0_CLOCK_SYMBOL);
                SCG_HWA_SetPllCsr(SCG_PLL0_CLOCK_SYMBOL, SCG_PLL0CSR_ERR_MASK);
                SCG_HWA_EnablePll0ForceOff();

                u32TempVal = CLOCK_OFF_STABILIZATION_TIMEOUT;
                while ((true == SCG_HWA_GetClockValid(SCG_PLL0_CLOCK_SYMBOL)) && (u32TempVal > 0U))
                {
                    u32TempVal--;
                }

                if (0U == u32TempVal)
                {
                    eStatusVal = SCG_STATUS_TIMEOUT;
                }
                else
                {
                    /* Re-enable PLL0_CLK1 or PLL0_CLK2 */
                    u32TempVal = SCG_PLL0CSR_EN_MASK |
#if SCG_PLL0_CLK2_SUPPORT
                                SCG_PLL0CSR_CK2EN(tSmc_PllStatusBeforeStopMode.bPll0Clk2GateOff)|
#endif /* SCG_PLL0_CLK2_SUPPORT */
                                SCG_PLL0CSR_CK1EN(tSmc_PllStatusBeforeStopMode.bPll0Clk1GateOff);
                    SCG_HWA_SetPllCsr(SCG_PLL0_CLOCK_SYMBOL, u32TempVal);

                    /* Wait PLL0 locked */
                    u32TempVal = PLL_STABILIZATION_TIMEOUT;
                    while ((false == SCG_HWA_GetPllLocked(SCG_PLL0_CLOCK_SYMBOL)) && (u32TempVal > 0U))
                    {
                        u32TempVal--;
                    }

                    if(0U == u32TempVal)
                    {
                        eStatusVal = SCG_STATUS_TIMEOUT;
                    }
                    else
                    {
                        if (SCG_PLL0CSR_CM_MASK == (u32Pll0CsrRegVal & SCG_PLL0CSR_CM_MASK))
                        {
                            SCG_HWA_EnablePllClockMonitor(SCG_PLL0_CLOCK_SYMBOL);
                        }
                        else
                        {
                            /* Do nothing */
                        }

                        if (SCG_PLL0CSR_CMRE_MASK == (u32Pll0CsrRegVal & SCG_PLL0CSR_CMRE_MASK))
                        {
                            SCG_HWA_EnablePllClockMonitorReset(SCG_PLL0_CLOCK_SYMBOL);
                        }
                        else
                        {
                            /* Do nothing */
                        }

                        if(SCG_PLL0CSR_LK_MASK == (u32Pll0CsrRegVal & SCG_PLL0CSR_LK_MASK))
                        {
                            SCG_HWA_LockPllCsr(SCG_PLL0_CLOCK_SYMBOL);
                        }
                        else
                        {
                            /* Keep unlock */
                        }

                        if((uint8_t)SCG_CLOCK_SRC_PLL0 == (uint8_t)((u32ScgCsrRegVal & SCG_CSR_SCS_MASK) >> SCG_CSR_SCS_SHIFT))
                        {
                            /* SCG CSR has been changed, means system clock is PLL0 and has changed to FIRC
                             * restore system clock configuration
                             */
                            tSysClkCfg.bSysClkMonitor = true;
                            tSysClkCfg.eDivCore = (SCG_ClockDivType)(uint8_t)((u32ScgCsrRegVal & SCG_CCR_DIVCORE_MASK)>>SCG_CCR_DIVCORE_SHIFT);
                            tSysClkCfg.eDivBus  = (SCG_ClockDivType)(uint8_t)((u32ScgCsrRegVal & SCG_CCR_DIVBUS_MASK)>>SCG_CCR_DIVBUS_SHIFT);
                            tSysClkCfg.eDivSlow = (SCG_ClockDivType)(uint8_t)((u32ScgCsrRegVal & SCG_CCR_DIVSLOW_MASK)>>SCG_CCR_DIVSLOW_SHIFT);
                            tSysClkCfg.eSrc     = (SCG_ClockSrcType)(uint8_t)((u32ScgCsrRegVal & SCG_CCR_SCS_MASK)>>SCG_CCR_SCS_SHIFT);

                            (void)SCG_SetClkCtrl(&tSysClkCfg);
                        }
                        else
                        {
                            /* SCG CSR has not been changed */
                        }
                    }
                }
            }
            else
            {
                /* System clock switch failed.  */
            }
        }
         else
        {
            /* do nothing */
        }

#if SCG_PLL1_SUPPORT
        /* PLL1 Operation */
        if(true == tSmc_PllStatusBeforeStopMode.bPll1Clk1GateOff)
        {
            u32Pll1CsrRegVal = SCG_HWA_GetPll1Csr();
            /* Must turn Off PLL1, before Restore PLL1_CLK1 */
            SCG_HWA_UnlockPllCsr(SCG_PLL1_CLOCK_SYMBOL);
            SCG_HWA_SetPllCsr(SCG_PLL1_CLOCK_SYMBOL, SCG_PLL1CSR_ERR_MASK);
            SCG_HWA_EnablePll1ForceOff();

            u32TempVal = CLOCK_OFF_STABILIZATION_TIMEOUT;
            while ((true == SCG_HWA_GetClockValid(SCG_PLL1_CLOCK_SYMBOL)) && (u32TempVal > 0U))
            {
                u32TempVal--;
            }

            if (0U == u32TempVal)
            {
                eStatusVal = SCG_STATUS_TIMEOUT;
            }
            else
            {
                /* Restore PLL1_CLK1 */
                u32TempVal = SCG_PLL1CSR_EN_MASK | SCG_PLL1CSR_CK1EN_MASK;
                SCG_HWA_SetPllCsr(SCG_PLL1_CLOCK_SYMBOL, u32TempVal);

                /* Wait PLL1 locked */
                u32TempVal = PLL_STABILIZATION_TIMEOUT;
                while ((false == SCG_HWA_GetPllLocked(SCG_PLL1_CLOCK_SYMBOL)) && (u32TempVal > 0U))
                {
                    u32TempVal--;
                }

                if(0U == u32TempVal)
                {
                	/* disable PLL0 failed */
                	eStatusVal = SCG_STATUS_TIMEOUT;
                }
                else
                {
                    if (SCG_PLL1CSR_CM_MASK == (u32Pll1CsrRegVal & SCG_PLL1CSR_CM_MASK))
                    {
                        SCG_HWA_EnablePllClockMonitor(SCG_PLL1_CLOCK_SYMBOL);
                    }
                    else
                    {
                        /* Do nothing */
                    }

                    if (SCG_PLL1CSR_CMRE_MASK == (u32Pll1CsrRegVal & SCG_PLL1CSR_CMRE_MASK))
                    {
                        SCG_HWA_EnablePllClockMonitorReset(SCG_PLL1_CLOCK_SYMBOL);
                    }
                    else
                    {
                        /* Do nothing */
                    }

                    if(SCG_PLL1CSR_LK_MASK == (u32Pll1CsrRegVal & SCG_PLL1CSR_LK_MASK))
                    {
                        SCG_HWA_LockPllCsr(SCG_PLL1_CLOCK_SYMBOL);
                    }
                    else
                    {
                        /* Keep unlock */
                    }
                }
            }
        }
        else
        {
            /* do nothing */
        }
#endif /* SCG_PLL1_SUPPORT */
        
    }
    else
    {
        /* Not Core 0, do nothing */
    }
}

/**
 * @brief Set PllxClk1Operation before standby mode
 *
 */
static void SMC_EntryStandbyMode_PllxClk1_Clk2Operation(void)
{
    uint32_t u32CoreId;

    u32CoreId = Cpm_HWA_GetCoreId();
    if(0U == u32CoreId)
    {
        /* Disable PLL0_CLK1 */
        SCG_HWA_UnlockPllCsr(SCG_PLL0_CLOCK_SYMBOL);
        SCG_HWA_DisablePLL0CLK1Output();
#if SCG_PLL0_CLK2_SUPPORT
        SCG_HWA_DisablePLL0CLK2Output();
#endif /* SCG_PLL0_CLK2_SUPPORT */

#if SCG_PLL1_SUPPORT
        /* Disable PLL1_CLK1 */
        SCG_HWA_UnlockPllCsr(SCG_PLL1_CLOCK_SYMBOL);
        SCG_HWA_DisablePLL1CLK1Output();
#endif /* SCG_PLL1_SUPPORT */
    }
    else
    {
        /* Core 0 gate off */
    }
}
#endif /* SCG_PLLX_CLK1_SUPPORT */

/**
 * @brief Set system mode
 *
 * @param eMode MCU low power mode
 *
 */
void SMC_SetSystemMode(const SMC_ModeType eMode)
{
    switch (eMode)
    {
    case SMC_MODE_RUN:
        /* Clear the SLEEPDEEP bit to disable deep sleep mode */
        CM7_HWA_DisableDeepSleep();

        break;
    case SMC_MODE_STOP:
        /* switch smc mode to stop mode */
        SMC_HWA_SetStopModeCtrl(SMC_STOP_MODE);
        /* Set the SLEEPDEEP bit to enable deep sleep mode (STOP)*/
        CM7_HWA_EnableDeepSleep();

#if SCG_PLLX_CLK1_SUPPORT
        SMC_EntryStopMode_PllxClk1_Clk2Status();
        SMC_EntryStopMode_PLLClkOperation();
#endif
        /* Cpu is going into deep sleep state */
        STANDBY();

#if SCG_PLLX_CLK1_SUPPORT
        SMC_ExitStopMode_PllxOperation();
#endif

        break;

    case SMC_MODE_WAIT:
        /* Clear the SLEEPDEEP bit to disable deep sleep mode */
        CM7_HWA_DisableDeepSleep();

        /* Cpu is going into sleep state */
        STANDBY();

        break;

    case SMC_MODE_STANBY_0:
        /* select standby mode*/
        SMC_HWA_SetStandbyMode(SMC_CFG_STANDBY_0);

        /* switch smc mode to standby mode */
        SMC_HWA_SetStopModeCtrl(SMC_STANDBY_MODE);
        /* Set the SLEEPDEEP bit to enable deep sleep mode */
        CM7_HWA_EnableDeepSleep();

#if SCG_PLLX_CLK1_SUPPORT
        SMC_EntryStandbyMode_PllxClk1_Clk2Operation();
#endif
        /* Cpu is going into deep sleep state */
        STANDBY();

        break;

    case SMC_MODE_STANBY_1:
        /* select standby mode*/
        SMC_HWA_SetStandbyMode(SMC_CFG_STANDBY_1);

        /* switch smc mode to standby mode */
        SMC_HWA_SetStopModeCtrl(SMC_STANDBY_MODE);

        /* Set the SLEEPDEEP bit to enable deep sleep mode */
        CM7_HWA_EnableDeepSleep();

#if SCG_PLLX_CLK1_SUPPORT
        SMC_EntryStandbyMode_PllxClk1_Clk2Operation();
#endif
        /* Cpu is going into deep sleep state */
        STANDBY();
        break;

    case SMC_MODE_STANBY_2:
        /* select standby mode*/
        SMC_HWA_SetStandbyMode(SMC_CFG_STANDBY_2);

        /* switch smc mode to standby mode */
        SMC_HWA_SetStopModeCtrl(SMC_STANDBY_MODE);

        /* Set the SLEEPDEEP bit to enable deep sleep mode */
        CM7_HWA_EnableDeepSleep();

#if SCG_PLLX_CLK1_SUPPORT
        SMC_EntryStandbyMode_PllxClk1_Clk2Operation();
#endif
        /* Cpu is going into deep sleep state */
        STANDBY();
        break;

    case SMC_MODE_STANBY_3:
        /* select standby mode*/
        SMC_HWA_SetStandbyMode(SMC_CFG_STANDBY_3);

        /* switch smc mode to standby mode */
        SMC_HWA_SetStopModeCtrl(SMC_STANDBY_MODE);

        /* Set the SLEEPDEEP bit to enable deep sleep mode */
        CM7_HWA_EnableDeepSleep();

#if SCG_PLLX_CLK1_SUPPORT
        SMC_EntryStandbyMode_PllxClk1_Clk2Operation();
#endif
        /* Cpu is going into deep sleep state */
        STANDBY();
        break;
    default:
        /* do nothing */
        break;
    }
}

#if SMC_CLOCKCONFIG_SUPPORT
/**
 * @brief set always on clock source configuration include AON32K, RTC, AONCLK clock.
 *
 * @param pAonclkSrcType pointer to AONCLKSR instance for AON clock source configuration
 * @param bLockStatus to lock current register
 *
 * @return Set clock out operation success/failed
 */
SMC_StatusType SMC_SetAonClkSrc(const SMC_AONCLKSRType *const pAonclkSrcType, bool bLockStatus)
{
    SMC_StatusType eRetVal = SMC_STATUS_PARAM_INVALID;

#if SMC_DEV_ERROR_REPORT == STD_ON
    if (pAonclkSrcType == NULL)
    {
        SMC_ReportDevError(SMC_SET_AONCLKSRC_ID, SMC_E_PARAM_POINTER);
    }
    else
    {
#endif

        /* Check SMC_AONCLKSR register lock status */
        if (0U == SMC_HWA_GetAONCLKSRLOCK())
        {
            /* Gating SIRC_32K clock*/
            if ((SMC_AON32K_SIRCDIV_32K_CLK == pAonclkSrcType->eAon32KSel) ||
                    (SMC_AON_SIRCDIV_32K_CLK == pAonclkSrcType->eAonSel)       ||
                    (SMC_RTC_SIRCDIV_32K_CLK == pAonclkSrcType->eRtcSel))
            {
                SMC_HWA_SetSIRCDIV32KEN(1U);
            }
            else
            {
                /* No deal with */
            }

            /* Gating SIRC32_1K clock*/
            if (SMC_AON_SIRC32_1K_CLK == pAonclkSrcType->eAonSel)
            {
                SMC_HWA_SetAON1KCLKEN(1U);
            }
            else
            {
                /* No deal with */
            }

            /* Set AONCLOCK configuration */
            SMC_HWA_SetAON32kClkSrc(pAonclkSrcType->eAon32KSel);
            SMC_HWA_SetRTCClkSrc(pAonclkSrcType->eRtcSel);
            SMC_HWA_SetAONClkSrc(pAonclkSrcType->eAonSel);

            if (true == bLockStatus)
            {
                /* Lock SMC_AONCLKSR register */
                SMC_HWA_SetAONCLKSRLOCK(1U);
            }

            eRetVal = SMC_STATUS_SUCCESS;
        }
        else
        {
            /* No deal with */
        }

#if SMC_DEV_ERROR_REPORT == STD_ON
    }
#endif

    return eRetVal;
}

/**
 * @brief Report the clock source status and frequency configured in MCU run time.
 *        The clock frequency and status would change by clock set function.
 *
 * @param eClkkName: the SMC clock source to query
 * @param pFreq: frequency variable point to get the frequency value
 * @return true or false. This indicate the clock source status invalid or request clock source out of
 *         range.
 */
SMC_StatusType SMC_GetSMCClockFreq(const SMC_ClkSrcType eClkkName, uint32_t *const pFreq)
{
    SMC_StatusType eRetVal = SMC_STATUS_PARAM_INVALID;
    uint32_t u32TempVal;

#if SMC_DEV_ERROR_REPORT == STD_ON
    if (pFreq == NULL)
    {
        SMC_ReportDevError(SMC_GET_CLOCK_FREQ_ID, SMC_E_PARAM_POINTER);
    }
    else if (eClkkName > SMC_END_OF_CLOCKS)
    {
        SMC_ReportDevError(SMC_GET_CLOCK_FREQ_ID, SMC_E_PARAM_OUT_RANGE);
    }
    else
    {
#endif

        u32TempVal = SMC_HWA_Get_AONCLKSR();

        if (SMC_AON_CLK == eClkkName)
        {
            SMC_AONClkSrcType eClockkRet = (SMC_AONClkSrcType)(uint8_t)((u32TempVal & SMC_AONCLKSR_AONCLKSEL_MASK) >> SMC_AONCLKSR_AONCLKSEL_SHIFT);

            if (SMC_AON_SIRCDIV_128K_CLK == eClockkRet)
            {
                *pFreq = SMC_AONCLK_128K;
            }
            else if (SMC_AON_SIRC32_1K_CLK == eClockkRet)
            {
                *pFreq = SMC_AONCLK_1K;
            }
            else
            {
                *pFreq = SMC_AONCLK_32K;
            }

            eRetVal = SMC_STATUS_SUCCESS;
        }
        else if (SMC_AON32K_CLK == eClkkName)
        {
            SMC_AON32KClkSrcType eClockkRet = (SMC_AON32KClkSrcType)(uint8_t)((u32TempVal & SMC_AONCLKSR_AON32KCLKSEL_MASK) >> SMC_AONCLKSR_AON32KCLKSEL_SHIFT);

            if (SMC_AON32K_SOSC32K_CLK == eClockkRet)
            {
                *pFreq = SMC_AONCLK_SOSC_32K;
            }
            else
            {
                *pFreq = SMC_AONCLK_32K;
            }

            eRetVal = SMC_STATUS_SUCCESS;
        }
        else if (SMC_RTC_CLK == eClkkName)
        {
            SMC_RTCClkSrcType eClockkRet = (SMC_RTCClkSrcType)(uint8_t)((u32TempVal & SMC_AONCLKSR_RTCCLKSEL_MASK) >> SMC_AONCLKSR_RTCCLKSEL_SHIFT);
            if (SMC_RTC_FOSCDIVL_CLK == eClockkRet)
            {
                *pFreq = SCG_GetScgClockFreq(SCG_FOSCDIVL_CLK);
            }
            else if (SMC_RTC_SOSC_CLK == eClockkRet)
            {
                *pFreq = SMC_AONCLK_SOSC_32K;
            }
            else
            {
                *pFreq = SMC_AONCLK_32K;
            }

            eRetVal = SMC_STATUS_SUCCESS;
        }
        else
        {
            /* Clock out or error parameter do not get frequency */
            *pFreq = 0U;
        }

#if SMC_DEV_ERROR_REPORT == STD_ON
    }
#endif

    return eRetVal;
}

/**
 * @brief Configure the low power wakeup PAD output in SMC_LP_WAKEUP register
 *
 * @param SMC_LPWakeUpPadType the low power wakeup PAD source and polarity configuration
 */
void SMC_SetLPWakeUpPad(const SMC_LPWakeUpPadType* pLPWakeUpPad)
{
    uint8_t u8Index;
    uint32_t u32RegVal;

    /* Unlock SMC important registers */
    SMC_HWA_SetPmportReg(0U);

    /* Get IO lock status */
    u32RegVal = SMC_HWA_GetIolockReg();

    for(u8Index=0U; u8Index < LP_WAKEUP_PAD_NUM; u8Index++)
    {
        SMC_HWA_SetLPWakeUpPadSrc(pLPWakeUpPad[u8Index].u8LPWakeUpPadNum, (uint8_t)(pLPWakeUpPad[u8Index].eLpWakeUpPadSel));
        SMC_HWA_SetLPWakeUpPadPol(pLPWakeUpPad[u8Index].u8LPWakeUpPadNum, (uint8_t)(pLPWakeUpPad[u8Index].eLpWakeUpPadPolSel));

        if (SMC_LPWAKEUP_PAD_DISABLE != (pLPWakeUpPad[u8Index].eLpWakeUpPadSel) )
        {
            /* Default enable iolock when wakeup pad is enabled */
            u32RegVal |= ( 1U <<(SMC_IOLOCK_IOLOCK_CTRL0_SHIFT - (pLPWakeUpPad[u8Index].u8LPWakeUpPadNum)) );
        }
        else
        {
            /* Disable iolock when wakeuppad is disabled */
            u32RegVal &= ~( 1U <<(SMC_IOLOCK_IOLOCK_CTRL0_SHIFT - (pLPWakeUpPad[u8Index].u8LPWakeUpPadNum)) );
        }
    }

    /* Set IO lock status */
    SMC_HWA_SetIolockReg(u32RegVal);
}

/**
 * @brief Configure SMC mixed used control
 *
 * @param SMC_MixedUsedType SMC mixed used control
 */
void SMC_SetMixedUsedConfiguration(const SMC_MixedUsedType* pMixedUsedConfig)
{
#if SMC_LP_GOOD_SUPPORT
    uint32_t u32Temp = 0U;

    /* Unlock SMC important registers */
    SMC_HWA_SetPmportReg(0U);

    /* Set SRAM2 block retention control */
    SMC_HWA_SetRETEN((uint16_t)(pMixedUsedConfig->eRamRetenSel));

    /* PG Contrl */
    if ((boolean)TRUE == pMixedUsedConfig->tPGCtrlConifg.bEnable)
    {
        u32Temp |= (uint32_t)( SMC_PGCTRL_PG_EN_MASK | SMC_PGCTRL_PG_LOCK_EN_MASK |
                               SMC_PGCTRL_PG_LOCK_SEL(pMixedUsedConfig->tPGCtrlConifg.ePGLockSel) |
                               SMC_PGCTRL_PG_POL(pMixedUsedConfig->tPGCtrlConifg.ePGActivePol)
                             );
    }
    else
    {
        /* Disable PG control */
        u32Temp = 0U;
        /* Set standby exit postpone count through PCUCtrl when LP_GOOD is not used. */
        SMC_HWA_SetRPM_EXIT_CNT(pMixedUsedConfig->tPGCtrlConifg.u16RpmExitCnt);
    }

    SMC_HWA_SetPgctrlReg(u32Temp);
#else
    /* Unlock SMC important registers */
    SMC_HWA_SetPmportReg(0U);

    /* Set standby exit postpone count through PCUCtrl when LP_GOOD is not used. */
    SMC_HWA_SetRPM_EXIT_CNT(pMixedUsedConfig->tPGCtrlConifg.u16RpmExitCnt);
#endif
}

/**
 * @brief set clock out. with clock out pin configure, the clock would be monitored.
 *        This Function may combined with SCG_ClkOut setting
 *        need to call SCG_SetClkOut,if clock out source set to SCG_CLKOUT. *
 * @param pSmcClkOut to SmcClkOut instance for clock out configuration
 * @param bLockStatus to lock current register
 *
 * @return Set clock out operation success/failed
 * @note  configuration sequence:
 *           1. Disable CLKOUTEN
 *           2. Set CLKOUTSEL
 *           3. Enable CLKOUTEN
 */
SMC_StatusType SMC_SetClockOut(const SMC_ClkoutType *const pSmcClkOut, bool bLockStatus)
{
    SMC_StatusType eRetVal = SMC_STATUS_PARAM_INVALID;
#if SMC_DEV_ERROR_REPORT == STD_ON
    if (pSmcClkOut == NULL)
    {
        SMC_ReportDevError(SMC_SET_CLOCK_OUT_ID, SMC_E_PARAM_POINTER);
    }
    else
    {
#endif

        /* Check SMC_CLKOUT_CTRL register lock status */
        if (0U == SMC_HWA_CLKOUT_CTRL_GetLockStatus())
        {
            /* Disable CLKOUTEN */
            SMC_HWA_DisableClockOut();
            /* Set CLKOUTDIV */
            SMC_HWA_SetClkOutDiv(pSmcClkOut->eDivider);
            /* Set CLKOUTSEL */
            SMC_HWA_SetClkOutSel(pSmcClkOut->eClkOutSrc);
            /* Enable CLKOUTEN */
            SMC_HWA_EnableClockOut();

            if (true == bLockStatus)
            {
                /* Lock SMC_CLKOUT_CTRL register */
                SMC_HWA_LockCLKOUT_CTRL();
            }
            else
            {
                /* No deal with */
            }

            eRetVal = SMC_STATUS_SUCCESS;
        }
        else
        {
            /* No deal with */
        }

#if SMC_DEV_ERROR_REPORT == STD_ON
    }
#endif

    return eRetVal;
}

#if SMC_SCG_WAKEUP_CONFIG_SUPPORT
/**
 * @brief Set scg wakup configuration.
 *
 * @param SMC_SCGWakeUpConfigType SCG wakeup configuration
 *
 */
void SMC_SetSCGWakeUpConfiguration(const SMC_SCGWakeUpConfigType *const pSCGWakeUpConfig)
{
    uint32_t u32RegVal = 0U;

    u32RegVal = SMC_SCG_WAKEUP_SCG_WAKEUP_CFG(pSCGWakeUpConfig->eWakeUpSource) |
                SMC_SCG_WAKEUP_SCG_POL(pSCGWakeUpConfig->eWakeUpPolarity) |
                SMC_SCG_WAKEUP_SCG_TRGSEL(pSCGWakeUpConfig->eSircTriggerToAdc) |
                SMC_SCG_WAKEUP_LOCK(pSCGWakeUpConfig->eRegLockSel);

    SMC_HWA_SetSCG_WAKEUP_REG(u32RegVal);
}
#endif

#if SMC_TSTMP0CLOCK_CONFIG_SUPPORT
/**
 * @brief Set tstmp0 clock configuration.
 *
 * @param SMC_Tmtmp0ClkConfigType Tstmp0 clock configuration
 *
 * @note  configuration sequence:
 *           1. Disable EN and wait for 4 clock cycles
 *           2. Set div and sel
 *           3. Enable EN and wait for 4 clock cycles
 *        if set lock bit, this register can be restored by POR
 */
void SMC_SetTstmp0ClockConfiguration(const SMC_Tmtmp0ClkConfigType *const pTstmp0ClkConfig)
{
    uint32_t u32RegVal = 0U;
    uint32_t u32WaitCycles;
    uint32_t i;

    /* Get clock source to determine wait cycle */
    u32RegVal = (SMC_HWA_GetTstmp0_CLk_CfgReg() & SMC_TSTMP0_CLK_CFG_SEL_MASK)>>SMC_TSTMP0_CLK_CFG_SEL_SHIFT;
    if( (uint32)SMC_TSTMP0_CLK_SRC_SIRCDIV_1M == u32RegVal )
    {
        u32WaitCycles = SMC_TSTMP0_DUMMY_CYCLES_1M;
    }
    else if ( (uint32)SMC_TSTMP0_CLK_SRC_FOSC_DIVL == u32RegVal )
    {
        u32WaitCycles = SMC_TSTMP0_DUMMY_CYCLES_250K;
    }
    else
    {
        u32WaitCycles = SMC_TSTMP0_DUMMY_CYCLES_32K;
    }

    SMC_HWA_DisableTstmp0Clk();
    for(i=0U; i<u32WaitCycles; i++)
    {
        __asm volatile("nop");
    }

    u32RegVal = (uint32_t)( SMC_TSTMP0_CLK_CFG_DIV(pTstmp0ClkConfig->eClkDiv) |
                            SMC_TSTMP0_CLK_CFG_SEL(pTstmp0ClkConfig->eClkSrc) );

    SMC_HWA_SetTstmp0_CLk_CfgReg(u32RegVal);

    SMC_HWA_EnableTstmp0Clk();

    /* Recalculate u32WaitCycles because clock source may be changed */
    if( SMC_TSTMP0_CLK_SRC_SIRCDIV_1M == pTstmp0ClkConfig->eClkSrc )
    {
        u32WaitCycles = SMC_TSTMP0_DUMMY_CYCLES_1M;
    }
    else if ( SMC_TSTMP0_CLK_SRC_FOSC_DIVL == pTstmp0ClkConfig->eClkSrc )
    {
        u32WaitCycles = SMC_TSTMP0_DUMMY_CYCLES_250K;
    }
    else
    {
        u32WaitCycles = SMC_TSTMP0_DUMMY_CYCLES_32K;
    }

    for(i=0U; i<u32WaitCycles; i++)
    {
        __asm volatile("nop");
    }

}
#endif /* #if SMC_TSTMP0CLOCK_CONFIG_SUPPORT */

#endif /* #if SMC_CLOCKCONFIG_SUPPORT */
#endif /* #if SMC_INSTANCE_COUNT > 0U */

