/**
 * @file module_driver_scg.c
 * @author Flagchip
 * @brief SCG driver type definition and API
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
*   2.0.0       2024-08-30    Flagchip055    N/A          Update file structures
********************************************************************************/
#include "module_driver_scg.h"

#if SCG_INSTANCE_COUNT > 0U

/***************** Macros *********************/


/***************** mcaro function *********************/
#define SCG_CheckClockAckStatus(x, timeout, returnVal)                      \
    while ((x) && (timeout > 0U))                                           \
    {                                                                       \
        timeout--;                                                          \
    }                                                                       \
    if (timeout != 0U)                                                      \
    {                                                                       \
        returnVal = SCG_STATUS_SUCCESS;                                     \
    }                                                                       \
    else                                                                    \
    {                                                                       \
        returnVal = SCG_STATUS_TIMEOUT;                                     \
    }


#define SCG_GetDivHClock(_clock_, input_freq, ouput_freq)                                \
    {                                                                                    \
        uint32_t u32DivRegVal;                                                           \
        \
        u32DivRegVal = SCG_HWA_GetClockDiv(_clock_);                                     \
        ouput_freq = SCG_CALCULATE_DIVH_FREQ(input_freq, u32DivRegVal);                  \
    }

#define SCG_GetDivMClock(_clock_, input_freq, ouput_freq)                                \
    {                                                                                    \
        uint32_t u32DivRegVal;                                                           \
        \
        u32DivRegVal = SCG_HWA_GetClockDiv(_clock_);                                     \
        ouput_freq = SCG_CALCULATE_DIVM_FREQ(input_freq, u32DivRegVal);                  \
    }

#define SCG_GetDivLClock(_clock_, input_freq, ouput_freq)                                                                                                                                                          \
    {                                                                                    \
        uint32_t u32DivRegVal;                                                           \
        \
        u32DivRegVal = SCG_HWA_GetClockDiv(_clock_);                                     \
        ouput_freq = SCG_CALCULATE_DIVL_FREQ(input_freq, u32DivRegVal);                  \
    }

/***************** Local Functions *********************/
static uint32_t SCG_CalculatePll0MultFreq(void);
static uint32_t SCG_CalculatePll0Freq(const SCG_ClkSrcType eScgClockName);
#if SCG_PLL1_SUPPORT
static uint32_t SCG_CalculatePll1Freq(const SCG_ClkSrcType eScgClockName);
#endif /* SCG_PLL1_SUPPORT */
static uint32_t SCG_CalculateSystemFreq(const SCG_ClkSrcType eScgClockName);
static uint32_t SCG_CalculateSircFreq(const SCG_ClkSrcType eScgClockName);
static uint32_t SCG_CalculateFircFreq(const SCG_ClkSrcType eScgClockName);
static uint32_t SCG_CalculateFoscFreq(const SCG_ClkSrcType eScgClockName);
static uint32_t SCG_CalculateClkOutFreq(void);
static uint32_t SCG_CalculateCMU4RefFreq(void);
#if SCG_PLLX_CLK1_SUPPORT
static uint32_t SCG_CalculatePll0Clk1Freq(void);
#endif /* SCG_PLLX_CLK1_SUPPORT */
#if SCG_PLL0_CLK2_SUPPORT
static uint32_t SCG_CalculatePll0Clk2Freq(void);
#endif /* SCG_PLL0_CLK2_SUPPORT */

/**
 * @brief Calculate SIRC frequency
 *
 * @param eScgClockName SCG clock name
 * @return uint32_t SIRC frequency
 */
static uint32_t SCG_CalculateSircFreq(const SCG_ClkSrcType eScgClockName)
{
    uint32_t u32Freq;

    if (SCG_SIRC_CLK == eScgClockName)
    {
        u32Freq = SIRC_CLOCK;
    }
    else if (SCG_SIRCDIVH_CLK == eScgClockName)
    {
        SCG_GetDivHClock(SCG_SIRC_CLOCK_SYMBOL, SIRC_CLOCK, u32Freq);
    }
    else if (SCG_SIRCDIVM_CLK == eScgClockName)
    {
        SCG_GetDivMClock(SCG_SIRC_CLOCK_SYMBOL, SIRC_CLOCK, u32Freq);
    }
    else if (SCG_SIRCDIVL_CLK == eScgClockName)
    {
        SCG_GetDivLClock(SCG_SIRC_CLOCK_SYMBOL, SIRC_CLOCK, u32Freq);
    }
    else
    {
        u32Freq = UNKNOWN_CLOCK;
    }

    return u32Freq;
}

/**
 * @brief Calculate FIRC frequency
 *
 * @param eScgClockName SCG clock name
 * @return uint32_t FIRC frequency
 */
static uint32_t SCG_CalculateFircFreq(const SCG_ClkSrcType eScgClockName)
{
    uint32_t u32Freq;

    if (true == SCG_HWA_GetClockValid(SCG_FIRC_CLOCK_SYMBOL))
    {
        if (SCG_FIRC_CLK == eScgClockName)
        {
            u32Freq = FIRC_CLOCK;
        }
        else if (SCG_FIRCDIVH_CLK == eScgClockName)
        {
            SCG_GetDivHClock(SCG_FIRC_CLOCK_SYMBOL, FIRC_CLOCK, u32Freq);
        }
        else if (SCG_FIRCDIVM_CLK == eScgClockName)
        {
            SCG_GetDivMClock(SCG_FIRC_CLOCK_SYMBOL, FIRC_CLOCK, u32Freq);
        }
        else if (SCG_FIRCDIVL_CLK == eScgClockName)
        {
            SCG_GetDivLClock(SCG_FIRC_CLOCK_SYMBOL, FIRC_CLOCK, u32Freq);
        }
        else
        {
            u32Freq = UNKNOWN_CLOCK;
        }
    }
    else
    {
        u32Freq = UNKNOWN_CLOCK;
    }

    return u32Freq;
}

/**
 * @brief Calculate FOSC frequency
 *
 * @param eScgClockName SCG clock name
 * @return uint32_t FOSC frequency
 */
static uint32_t SCG_CalculateFoscFreq(const SCG_ClkSrcType eScgClockName)
{
    uint32_t u32Freq;

    if (true == SCG_HWA_GetClockValid(SCG_FOSC_CLOCK_SYMBOL))
    {
        if (SCG_FOSC_CLK == eScgClockName)
        {
            u32Freq = FOSC_FREQUENCY;
        }
        else if (SCG_FOSCDIVH_CLK == eScgClockName)
        {
            SCG_GetDivHClock(SCG_FOSC_CLOCK_SYMBOL, FOSC_FREQUENCY, u32Freq);
        }
        else if (SCG_FOSCDIVM_CLK == eScgClockName)
        {
            SCG_GetDivMClock(SCG_FOSC_CLOCK_SYMBOL, FOSC_FREQUENCY, u32Freq);
        }
        else if (SCG_FOSCDIVL_CLK == eScgClockName)
        {
            SCG_GetDivLClock(SCG_FOSC_CLOCK_SYMBOL, FOSC_FREQUENCY, u32Freq);
        }
        else
        {
            u32Freq = UNKNOWN_CLOCK;
        }
    }
    else
    {
        u32Freq = UNKNOWN_CLOCK;
    }

    return u32Freq;
}

/**
 * @brief Calculate PLL0  multi frequency
 *
 * @return uint32_t PLL0 multi frequency
 */
static uint32_t SCG_CalculatePll0MultFreq(void)
{
    uint32_t u32ClkFreq;
    uint8_t u8Temp, u8PreDiv;
    uint16_t u16Mult;
#if SCG_PLL0_CLK2_SUPPORT
    uint32_t u32Pll0EcfgVal;
#endif /* SCG_PLL0_CLK2_SUPPORT */

    if (true == SCG_HWA_GetPllLocked(SCG_PLL0_CLOCK_SYMBOL))
    {
        u8Temp = SCG_HWA_GetPllSrc(SCG_PLL0_CLOCK_SYMBOL);
        if (u8Temp == (uint8_t)SCG_PLLSOURCE_FIRC)
        {

            u32ClkFreq = FIRC_CLOCK / 2U;
        }
        else
        {
            /* (u8Temp == (uint8_t)SCG_PLLSOURCE_FOSC) */
            u32ClkFreq = FOSC_FREQUENCY;
        }

        u8PreDiv = (uint8_t)(SCG_HWA_GetPllPrediv(SCG_PLL0_CLOCK_SYMBOL) + 1U);

#if SCG_PLL0_CLK2_SUPPORT
        u32Pll0EcfgVal = SCG_HWA_GetPll0Ecfg();
        if(SCG_PLL0_MULT_MUX_SEL_DOUBLE_MULT == (SCG_PllMultMuxSelType)((u32Pll0EcfgVal & SCG_PLL0ECFG_MULT_MUX_MASK)>>SCG_PLL0ECFG_MULT_MUX_SHIFT))
        {
            u16Mult = (uint16_t)((SCG_HWA_GetPllMult(SCG_PLL0_CLOCK_SYMBOL) + 1U) << 1U);
        }
        else
        {
            u16Mult = (uint16_t)(SCG_HWA_GetPllMult(SCG_PLL0_CLOCK_SYMBOL) + 1U);
        }
#else
        u16Mult = (uint16_t)(SCG_HWA_GetPllMult(SCG_PLL0_CLOCK_SYMBOL) + 1U);
#endif /* SCG_PLL0_CLK2_SUPPORT */

        u32ClkFreq = (u32ClkFreq / (u8PreDiv) * (u16Mult));
    }
    else
    {
        /* Pll0 is unlocked */
        u32ClkFreq = UNKNOWN_CLOCK;
    }

    return u32ClkFreq;
}

#if SCG_PLLX_CLK1_SUPPORT
/**
 * @brief Calculate PLL0 CLK1 frequency
 *
 * @return uint32_t PLL0 CLK1 frequency
 */
static uint32_t SCG_CalculatePll0Clk1Freq(void)
{
    uint32_t u32Freq, u32MultFreq;
    uint8_t  u8PstDiv1;

    u32MultFreq = SCG_CalculatePll0MultFreq();

    if(UNKNOWN_CLOCK != u32MultFreq)
    {
        u8PstDiv1 = (uint8_t)((SCG_HWA_GetPllPstdiv1(SCG_PLL0_CLOCK_SYMBOL) + 1U) << 1U);

#if SCG_PLL0_CLK2_SUPPORT
        if(SCG_PLL0ECFG_CLK1_MUX_MASK == (SCG_HWA_GetPll0Ecfg() & SCG_PLL0ECFG_CLK1_MUX_MASK))
        {
            /* Enable extra divider 2 */
            u8PstDiv1 = (u8PstDiv1 << 1U);
        }
        else
        {
            /* No extra divider 2 */
        }
#endif /* SCG_PLL0_CLK2_SUPPORT */

        u32Freq = u32MultFreq / u8PstDiv1;
    }
    else
    {
        u32Freq = UNKNOWN_CLOCK;
    }

    return u32Freq;
}

#if SCG_PLL1_SUPPORT
/**
 * @brief Calculate PLL1 CLK1 frequency
 *
 * @return uint32_t PLL1 CLK1 frequency
 */
static uint32_t SCG_CalculatePll1Clk1Freq(void)
{
    uint32_t u32Freq, u32ClkFreq;
    uint8_t u8Temp, u8PreDiv, u8PstDiv1;
    uint16_t u16Mult;

    if (true == SCG_HWA_GetClockValid(SCG_PLL1_CLOCK_SYMBOL))
    {
        u8Temp = SCG_HWA_GetPllSrc(SCG_PLL1_CLOCK_SYMBOL);
        if (u8Temp == (uint8_t)SCG_PLLSOURCE_FIRC)
        {

            u32ClkFreq = FIRC_CLOCK / 2U;
        }
        else
        {
            /* (u8Temp == (uint8_t)SCG_PLLSOURCE_FOSC) */
            u32ClkFreq = FOSC_FREQUENCY;
        }
        u8PreDiv = (uint8_t)(SCG_HWA_GetPllPrediv(SCG_PLL1_CLOCK_SYMBOL) + 1U);
        u16Mult = (uint16_t)(SCG_HWA_GetPllMult(SCG_PLL1_CLOCK_SYMBOL) + 1U);
        u8PstDiv1 = (uint8_t)((SCG_HWA_GetPllPstdiv1(SCG_PLL1_CLOCK_SYMBOL) + 1U) << 1U);
        u32Freq = (u32ClkFreq / (u8PreDiv) * (u16Mult)) / u8PstDiv1;
    }
    else
    {
        u32Freq = UNKNOWN_CLOCK;
    }

    return u32Freq;
}
#endif /* SCG_PLL1_SUPPORT */
#endif /* SCG_PLLX_CLK1_SUPPORT */

#if SCG_PLL0_CLK2_SUPPORT
/**
 * @brief Calculate PLL0 CLK2 frequency
 *
 * @return uint32_t PLL0 CLK2 frequency
 */
static uint32_t SCG_CalculatePll0Clk2Freq(void)
{
    uint32_t u32Freq, u32MultFreq;

    u32MultFreq = SCG_CalculatePll0MultFreq();

    if(UNKNOWN_CLOCK != u32MultFreq)
    {
        u32Freq = u32MultFreq / 15U;
    }
    else
    {
        u32Freq = UNKNOWN_CLOCK;
    }

    return u32Freq;
}
#endif /* SCG_PLL0_CLK2_SUPPORT */

/**
 * @brief Calculate PLL0 frequency
 *
 * @param eScgClockName SCG clock name
 * @return uint32_t PLL0 frequency
 */
static uint32_t SCG_CalculatePll0Freq(const SCG_ClkSrcType eScgClockName)
{
    uint32_t u32Freq, u32MultFreq, u32ClkFreq;
    uint8_t  u8PstDiv;

    u32MultFreq = SCG_CalculatePll0MultFreq();

    if(UNKNOWN_CLOCK != u32MultFreq)
    {
        u8PstDiv = SCG_HWA_GetPllPstdiv(SCG_PLL0_CLOCK_SYMBOL);
        /* PSTDIV = 0b/1b, Post-Divider divide 2 */
        if (0U == u8PstDiv)
        {
            u8PstDiv = 1U;
        }

#if SCG_PLL0_CLK2_SUPPORT
        if(SCG_PLL0ECFG_CLK_MUX_MASK == (SCG_HWA_GetPll0Ecfg() & SCG_PLL0ECFG_CLK_MUX_MASK))
        {
            /* Enable extra divider 2 */
            u32ClkFreq = ((u32MultFreq >> u8PstDiv) >> 1U);
        }
        else
        {
            /* No extra divider 2 */
            u32ClkFreq = (u32MultFreq >> u8PstDiv);
        }
#else
        u32ClkFreq = (u32MultFreq >> u8PstDiv);
#endif /* SCG_PLL0_CLK2_SUPPORT */

        if (SCG_PLL0_CLK == eScgClockName)
        {
            u32Freq = u32ClkFreq;
        }
        else if (SCG_PLL0DIVH_CLK == eScgClockName)
        {
            SCG_GetDivHClock(SCG_PLL0_CLOCK_SYMBOL, u32ClkFreq, u32Freq);
        }
        else if (SCG_PLL0DIVM_CLK == eScgClockName)
        {
            SCG_GetDivMClock(SCG_PLL0_CLOCK_SYMBOL, u32ClkFreq, u32Freq);
        }
        else if (SCG_PLL0DIVL_CLK == eScgClockName)
        {
            SCG_GetDivLClock(SCG_PLL0_CLOCK_SYMBOL, u32ClkFreq, u32Freq);
        }
        else
        {
            u32Freq = UNKNOWN_CLOCK;
        }
    }
    else
    {
        u32Freq = UNKNOWN_CLOCK;
    }

    return u32Freq;
}

#if SCG_PLL1_SUPPORT
/**
 * @brief Calculate PLL1 frequency
 *
 * @param eScgClockName SCG clock name
 * @return uint32_t PLL1 frequency
 */
static uint32_t SCG_CalculatePll1Freq(const SCG_ClkSrcType eScgClockName)
{
    uint32_t u32Freq, u32ClkFreq;
    uint8_t u8Temp, u8PreDiv, u8PstDiv;
    uint16_t u16Mult;

    if (true == SCG_HWA_GetClockValid(SCG_PLL1_CLOCK_SYMBOL))
    {
        u8Temp = SCG_HWA_GetPllSrc(SCG_PLL1_CLOCK_SYMBOL);
        if (u8Temp == (uint8_t)SCG_PLLSOURCE_FIRC)
        {

            u32ClkFreq = FIRC_CLOCK / 2U;
        }
        else
        {
            /* (u8Temp == (uint8_t)SCG_PLLSOURCE_FOSC) */
            u32ClkFreq = FOSC_FREQUENCY;
        }
        u8PreDiv = (uint8_t)(SCG_HWA_GetPllPrediv(SCG_PLL1_CLOCK_SYMBOL) + 1U);
        u16Mult = (uint16_t)(SCG_HWA_GetPllMult(SCG_PLL1_CLOCK_SYMBOL) + 1U);
        u8PstDiv = SCG_HWA_GetPllPstdiv(SCG_PLL1_CLOCK_SYMBOL);
        /* PSTDIV = 0b/1b, Post-Divider divide 2 */
        if (0U == u8PstDiv)
        {
            u8PstDiv = 1U;
        }

        u32ClkFreq = (u32ClkFreq / (u8PreDiv) * (u16Mult)) >> (u8PstDiv);

        if (SCG_PLL1_CLK == eScgClockName)
        {
            u32Freq = u32ClkFreq;
        }
        else if (SCG_PLL1DIVH_CLK == eScgClockName)
        {
            SCG_GetDivHClock(SCG_PLL1_CLOCK_SYMBOL, u32ClkFreq, u32Freq);
        }
        else if (SCG_PLL1DIVM_CLK == eScgClockName)
        {
            SCG_GetDivMClock(SCG_PLL1_CLOCK_SYMBOL, u32ClkFreq, u32Freq);
        }
        else if (SCG_PLL1DIVL_CLK == eScgClockName)
        {
            SCG_GetDivLClock(SCG_PLL1_CLOCK_SYMBOL, u32ClkFreq, u32Freq);
        }
        else
        {
            u32Freq = UNKNOWN_CLOCK;
        }
    }
    else
    {
        u32Freq = UNKNOWN_CLOCK;
    }

    return u32Freq;
}
#endif /* SCG_PLL1_SUPPORT */

/**
 * @brief Calculate system clock frequency
 *
 * @param eScgClockName SCG clock name
 * @return uint32_t System clock frequency
 */
static uint32_t SCG_CalculateSystemFreq(const SCG_ClkSrcType eScgClockName)
{
    uint32_t u32Freq, u32ClkFreq;
    uint8_t u8Temp, u8DivCore, u8DivBus, u8DivSlow;

    u8Temp = SCG_HWA_GetSysClkSrc();

    if (SCG_CLOCK_SRC_FOSC == (SCG_ClockSrcType)u8Temp)
    {
        u32ClkFreq = FOSC_FREQUENCY;
    }
    else if (SCG_CLOCK_SRC_FIRC == (SCG_ClockSrcType)u8Temp)
    {
        u32ClkFreq = FIRC_CLOCK;
    }
    else if (SCG_CLOCK_SRC_PLL0 == (SCG_ClockSrcType)u8Temp)
    {
        u32ClkFreq = SCG_CalculatePll0Freq(SCG_PLL0_CLK);
    }
#if SCG_SYSCLK_SEL_SIRC_SUPPORT
    else if (SCG_CLOCK_SRC_SIRC == (SCG_ClockSrcType)u8Temp)
    {
        u32ClkFreq = SCG_CalculateSircFreq(SCG_SIRC_CLK);
    }
#endif
    else
    {
        u32ClkFreq = UNKNOWN_CLOCK;
    }

    u8DivCore = (uint8_t)(SCG_HWA_GetSysClkDivCore() + 1U);
    u8DivBus = (uint8_t)(SCG_HWA_GetSysClkDivBus() + 1U);
    u8DivSlow = (uint8_t)(SCG_HWA_GetSysClkDivSlow() + 1U);

    u32ClkFreq = (uint32_t)(u32ClkFreq / u8DivCore);

    if (SCG_CORE_CLK == eScgClockName)
    {
        u32Freq = u32ClkFreq;
    }
    else if (SCG_BUS_CLK == eScgClockName)
    {
        u32Freq = (uint32_t)(u32ClkFreq / u8DivBus);
    }
    else
    {
        /* (SCG_SLOW_CLK == eScgClockName) */
        u32Freq = (uint32_t)((u32ClkFreq / u8DivBus) / u8DivSlow);
    }

    return u32Freq;
}

/**
 * @brief Calculate clock out frequency
 *
 * @return uint32_t Clock out frequency
 */
static uint32_t SCG_CalculateClkOutFreq(void)
{
    uint8_t u8ClockoutSrc;
    uint32_t u32Freq;
    /* check clock out configuration */
    u8ClockoutSrc = SCG_HWA_GetClkOutSel();

    if ((uint8_t)SCG_CLOCKOUT_SRC_OFF == u8ClockoutSrc)
    {
        u32Freq = 0U;
    }
    else if ((uint8_t)SCG_CLOCKOUT_SRC_FOSC == u8ClockoutSrc)
    {
        u32Freq = FOSC_FREQUENCY;
    }
    else if ((uint8_t)SCG_CLOCKOUT_SRC_SIRC == u8ClockoutSrc)
    {
        u32Freq = SCG_CalculateSircFreq(SCG_SIRC_CLK);
    }
    else if ((uint8_t)SCG_CLOCKOUT_SRC_FIRC == u8ClockoutSrc)
    {
        u32Freq = SCG_CalculateFircFreq(SCG_FIRC_CLK);
    }
    else if ((uint8_t)SCG_CLOCKOUT_SRC_SOSC == u8ClockoutSrc)
    {
        u32Freq = SOSC_FREQUENCY;
    }
    else if ((uint8_t)SCG_CLOCKOUT_SRC_SIRC32K == u8ClockoutSrc)
    {
        u32Freq = SIRC32K_CLOCK;
    }
    else
    {
        u32Freq = UNKNOWN_CLOCK;
    }

    return u32Freq;
}

/**
 * @brief Calculate CMU4 reference clock frequency
 *
 * @return uint32_t CMU4 reference clock frequency
 */
static uint32_t SCG_CalculateCMU4RefFreq(void)
{
    uint32_t u32Freq, u32Temp;

    u32Temp = SCG_HWA_GetClkOutCfg();

    if ((u32Temp & SCG_CLKOUTCFG_CMU4CLK_FOSC_MASK) != 0U)
    {
        u32Freq = FOSC_FREQUENCY;
    }
    else if ((u32Temp & SCG_CLKOUTCFG_CMU4CLK_SIRC_MASK) != 0U)
    {
        u32Freq = SIRC_CLOCK;
    }
    else
    {
        u32Freq = UNKNOWN_CLOCK;
    }

    return u32Freq;
}

/**
 * @brief Enable Pll0 clock
 *
 * @param pPllConfig Pll configuration
 * @return SCG_StatusType SCG status
 */
static SCG_StatusType SCG_EnablePLL0(const SCG_PllType *const pPllConfig)
{
    SCG_StatusType eStatusVal = SCG_STATUS_SUCCESS;
    uint32_t u32TempVal;
    uint32_t u32Freq, u32FeedBackFreq, u32VcoFreq;
    uint32_t u32VcoMax,u32Pll0Max;
#if SCG_PLLX_CLK1_SUPPORT
    uint32_t u32Pll0Clk1Max;
#endif /* SCG_PLLX_CLK1_SUPPORT */
    uint32_t u32PllClk1Freq   = 0U;
    uint32_t u32DivHClockFreq = 0U;
    uint32_t u32DivMClockFreq = 0U;
    uint32_t u32DivLClockFreq = 0U;

    /* check pll is valid, if valid, do not configure PLL */
    if ( (true == SCG_HWA_GetClockValid(SCG_PLL0_CLOCK_SYMBOL)) ||
         (true == SCG_HWA_GetPllLocked(SCG_PLL0_CLOCK_SYMBOL)) )
    {
        eStatusVal = SCG_STATUS_SEQUENCE_ERROR;
    }

#if SCG_PLLX_CLK1_SUPPORT && SCG_PLL_ERRATA_PSTDIV1_SUPPORT
    /* check pll pstdiv1 when pll0_clk1 is enable */
    if ((true == pPllConfig->bPllx_Clk1En) && (SCG_PLLPSTDIV1_BY4 == pPllConfig->ePstDiv1))
    {
        eStatusVal = SCG_STATUS_PARAM_ERROR;
    }
#endif /* SCG_PLLX_CLK1_SUPPORT */

    if (eStatusVal == SCG_STATUS_SUCCESS)
    {
        /*   PLL input is FOSC or FIRC clock/2  */
        u32Freq = (SCG_PLLSOURCE_FOSC == pPllConfig->eSrc) ? (FOSC_FREQUENCY) : (FIRC_CLOCK / 2U);

        /* Check the PLL feedback clock range */
        u32FeedBackFreq = u32Freq / ((uint8_t)(pPllConfig->ePrediv) + 1U);
        if (u32FeedBackFreq < PLL_FEEDBACK_CLK_MIN || u32FeedBackFreq > PLL_FEEDBACK_CLK_MAX)
        {
            eStatusVal = SCG_STATUS_PARAM_ERROR;
        }
        else
        {
#if SCG_PLL0_CLK2_SUPPORT
            if(SCG_PLL0_MULT_MUX_SEL_TYPICAL == pPllConfig->eSel)
            {
                u32VcoFreq = u32FeedBackFreq * (pPllConfig->u16Mult + 1U);
                u32VcoMax = PLL_VCO_CLK_MAX_TYPICAL;
                u32Pll0Max = PLL_CLK_MAX_TYPICAL;
                u32Pll0Clk1Max = PLL1_CLK1_CLK_MAX_TYPICAL;
            }
            else if(SCG_PLL0_MULT_MUX_SEL_DOUBLE_MULT == pPllConfig->eSel)
            {
                u32VcoFreq = ((u32FeedBackFreq * (pPllConfig->u16Mult + 1U)) << 1U);
                u32VcoMax = PLL_VCO_CLK_MAX_SCENARIO_1;
                u32Pll0Max = PLL_CLK_MAX_SCENARIO_1;
                u32Pll0Clk1Max = PLL1_CLK1_CLK_MAX_SCENARIO_1;
            }
            else if(SCG_PLL0_MULT_MUX_SEL_10_BITS == pPllConfig->eSel)
            {
                u32VcoFreq = u32FeedBackFreq * (pPllConfig->u16Mult + 1U);
                u32VcoMax = PLL_VCO_CLK_MAX_SCENARIO_2;
                u32Pll0Max = PLL_CLK_MAX_TYPICAL;
                u32Pll0Clk1Max = PLL1_CLK1_CLK_MAX_TYPICAL;
            }
            else
            {
                u32VcoFreq = 0U;
                u32VcoMax = PLL_VCO_CLK_MAX_TYPICAL;
                u32Pll0Max = PLL_CLK_MAX_TYPICAL;
                u32Pll0Clk1Max = PLL1_CLK1_CLK_MAX_TYPICAL;
            }
#else
            /* Check the PLL VCO clock range */
            u32VcoFreq = u32FeedBackFreq * (pPllConfig->u16Mult + 1U);
            u32VcoMax = PLL_VCO_CLK_MAX;
            u32Pll0Max = PLL_CLK_MAX;
#if SCG_PLLX_CLK1_SUPPORT
            u32Pll0Clk1Max = PLLx_CLK1_CLK_MAX;
#endif /* SCG_PLLX_CLK1_SUPPORT */
#endif /* SCG_PLL0_CLK2_SUPPORT */

            if ((u32VcoFreq < PLL_VCO_CLK_MIN) || (u32VcoFreq > u32VcoMax))
            {
                eStatusVal = SCG_STATUS_PARAM_ERROR;
            }
            else
            {
#if SCG_PLL0_CLK2_SUPPORT
                if( (SCG_PLL0_MULT_MUX_SEL_TYPICAL != pPllConfig->eSel) &&
                    (u32VcoFreq > PLL_VCO_CLK_SPECIFIC_MAX) &&
                    ( (false ==pPllConfig->bPllx_ClkMuxExtraDiv2) || (false == pPllConfig->bPllx_Clk1MuxExtraDiv2) )
                  )
                {
                    eStatusVal = SCG_STATUS_PARAM_ERROR;
                }
                else
#endif /* SCG_PLL0_CLK2_SUPPORT */
                {
                /* Check the PLL out clock range */
                /* PSTDIV = 0b/1b, Post-Divider divide 2 */
                u32TempVal = ((0U == (uint8_t)(pPllConfig->ePstDiv)) ? 1U : (uint32_t)(pPllConfig->ePstDiv));

#if SCG_PLL0_CLK2_SUPPORT
                if(true == pPllConfig->bPllx_ClkMuxExtraDiv2)
                {
                    /* PSTDIV = 0b/1b, Post-Divider divide 2,  extra divider 2 enable */
                    u32Freq = ((u32VcoFreq >> u32TempVal) >> 1U);
                }
                else
                {
                    /* PSTDIV = 0b/1b, Post-Divider divide 2,  extra divider 2 disable */
                    u32Freq = (u32VcoFreq >> u32TempVal);
                }
#else
                /* Calc PLL0_CLK frequency */
                u32Freq = (u32VcoFreq >> u32TempVal);
#endif /* SCG_PLL0_CLK2_SUPPORT */

                if ( (u32Freq < PLL_CLK_MIN) || (u32Freq > u32Pll0Max) )
                {
                    eStatusVal = SCG_STATUS_PARAM_ERROR;
                }
#if SCG_PLLX_CLK1_SUPPORT
                else
                {
                    /* Check PLL0_CLK1 clock range */
                    if(true == pPllConfig->bPllx_Clk1En)
                    {
#if SCG_PLL0_CLK2_SUPPORT
                        /* PLL0 post divider1 divide ratio = (PSTDIV1 + 1)*2 */
                        if(true == pPllConfig->bPllx_Clk1MuxExtraDiv2)
                        {
                            /* PSTDIV1 extra divider 2 enable */
                            u32TempVal = (((uint32_t)(pPllConfig->ePstDiv1) + 1U) << 2U);
                        }
                        else
                        {
                            /* PSTDIV1 extra divider 2 disable */
                            u32TempVal = (((uint32_t)(pPllConfig->ePstDiv1) + 1U) << 1U);
                        }
#else
                        /* PLL0 post divider1 divide ratio = (PSTDIV1 + 1)*2 */
                        u32TempVal = (((uint32_t)(pPllConfig->ePstDiv1) + 1U) << 1U);
#endif /* SCG_PLL0_CLK2_SUPPORT */
                        /* Calac PLL0_CLK1 frequency */
                        u32PllClk1Freq = u32VcoFreq / u32TempVal;

                        if(u32PllClk1Freq > u32Pll0Clk1Max)
                        {
                            eStatusVal = SCG_STATUS_PARAM_ERROR;
                        }
                    }
                    else
                    {
                        /* do not check when Pll0_Clk1 is not enable. */
                    }

                    /**
                     * PLL0_CLK2 must lower than 80MHz(if available), the divider is fixed to 15,
                     * So when Vco is lower than 1200MHz,it's no need to check.
                     */
                }
#else
                PROCESS_UNUSED_VAR(u32PllClk1Freq)
#endif /* SCG_PLLX_CLK1_SUPPORT */
                }
            }
        }

        /* Check DIV clock frequency is valid or not */
        if (eStatusVal == SCG_STATUS_SUCCESS)
        {
            if (pPllConfig->eDivH != SCG_ASYNC_CLOCK_DISABLE)
            {
                u32DivHClockFreq = (uint32_t)(u32Freq >> ((uint8_t)(pPllConfig->eDivH) - 1U));
            }
            if (pPllConfig->eDivM != SCG_ASYNC_CLOCK_DISABLE)
            {
                u32DivMClockFreq = (uint32_t)(u32Freq >> ((uint8_t)(pPllConfig->eDivM) - 1U));
            }
            if (pPllConfig->eDivL != SCG_ASYNC_CLOCK_DISABLE)
            {
                u32DivLClockFreq = (uint32_t)(u32Freq >> ((uint8_t)(pPllConfig->eDivL) - 1U));
            }

            if ((u32DivHClockFreq > PLL0_DIVH_MAX_CLOCK) || (u32DivMClockFreq > PLL0_DIVM_MAX_CLOCK) || (u32DivLClockFreq > PLL0_DIVL_MAX_CLOCK))
            {
                eStatusVal = SCG_STATUS_PARAM_ERROR;
            }
        }
    }

    if (eStatusVal == SCG_STATUS_SUCCESS)
    {
        /* Disable PLLDIV */
        SCG_HWA_DisablePllDiv(SCG_PLL0_CLOCK_SYMBOL);
        /* Wait DIV[ACK] change to 0 */
        SCG_CheckClockAckStatus((SCG_CHECK_DIV_ACK(SCG_HWA_GetClockDiv(SCG_PLL0_CLOCK_SYMBOL)) ==
                                 SCG_CLOCKDIV_DIV_ACK_MASK_SHIFT), u32TempVal, eStatusVal)

        if (eStatusVal == SCG_STATUS_SUCCESS)
        {
            /* unlock PLL CSR register */
            SCG_HWA_UnlockPllCsr(SCG_PLL0_CLOCK_SYMBOL);

#if SCG_PLL0_CLK2_SUPPORT
            /* Configure PLL0ECFG register */
            u32TempVal = SCG_PLL0ECFG_MULT_MUX(pPllConfig->eSel) |
                         SCG_PLL0ECFG_CLK1_MUX(pPllConfig->bPllx_Clk1MuxExtraDiv2) |
                         SCG_PLL0ECFG_CLK_MUX(pPllConfig->bPllx_ClkMuxExtraDiv2);

            SCG_HWA_SetPll0Ecfg(u32TempVal);
#endif /* SCG_PLL0_CLK2_SUPPORT */

            /* Configure PLLCFG register */
            u32TempVal =  SCG_PLLCFG_PREDIV(pPllConfig->ePrediv)  |
                          SCG_PLLCFG_MULT(pPllConfig->u16Mult)    |
                          SCG_PLLCFG_PSTDIV(pPllConfig->ePstDiv)  |
#if SCG_PLLX_CLK1_SUPPORT
                          SCG_PLLCFG_PSTDIV1(pPllConfig->ePstDiv1)|
#endif /* SCG_PLLX_CLK1_SUPPORT */
                          SCG_PLLCFG_SOURCE(pPllConfig->eSrc)  ;

            SCG_HWA_SetPllCfg(SCG_PLL0_CLOCK_SYMBOL, u32TempVal);

#if SCG_PLLX_CLK1_SUPPORT
#else
            SCG_HWA_SetCfgRegProt((boolean)TRUE);
            SCG_HWA_EnablePll0FastStart();
            SCG_HWA_SetCfgRegProt((boolean)FALSE);
#endif /* SCG_PLLX_CLK1_SUPPORT */

            /* Configure PLLCSR register */
            u32TempVal = SCG_PLL0CSR_ERR_MASK |
#if SCG_PLLX_CLK1_SUPPORT
                         SCG_PLL0CSR_CK1EN(pPllConfig->bPllx_Clk1En)|
#endif /* SCG_PLLX_CLK1_SUPPORT */
#if SCG_PLL0_CLK2_SUPPORT
                         SCG_PLL0CSR_CK2EN(pPllConfig->bPllx_Clk2En)|
#endif /* SCG_PLL0_CLK2_SUPPORT */
                         SCG_PLLCSR_STEN(pPllConfig->bSten);
            SCG_HWA_SetPllCsr(SCG_PLL0_CLOCK_SYMBOL, u32TempVal);

            /* Configure PLLDIV */
            u32TempVal = SCG_HWA_GetClockDiv(SCG_PLL0_CLOCK_SYMBOL);
            u32TempVal &= ~(uint32_t)(SCG_PLLDIV_DIVL_MASK | SCG_PLLDIV_DIVM_MASK | SCG_PLLDIV_DIVH_MASK);
            u32TempVal |= (SCG_PLLDIV_DIVH(pPllConfig->eDivH) |
                           SCG_PLLDIV_DIVM(pPllConfig->eDivM) |
                           SCG_PLLDIV_DIVL(pPllConfig->eDivL));
            SCG_HWA_SetPllDiv(SCG_PLL0_CLOCK_SYMBOL, u32TempVal) ;

            /* Set CSR[EN] bit to 1 */
            SCG_HWA_EnablePll(SCG_PLL0_CLOCK_SYMBOL);

            /* Wait PLL locked */
            u32TempVal = PLL_STABILIZATION_TIMEOUT;
            SCG_CheckClockAckStatus(( (false == SCG_HWA_GetPllLocked(SCG_PLL0_CLOCK_SYMBOL)) ||
                                      (false == SCG_HWA_GetClockValid(SCG_PLL0_CLOCK_SYMBOL)) ),
                                    u32TempVal, eStatusVal)

            if (eStatusVal == SCG_STATUS_SUCCESS)
            {
                /* Enable PLLDIV */
                SCG_HWA_EnablePllDiv(SCG_PLL0_CLOCK_SYMBOL);

                if (pPllConfig->bCm)
                {
                    SCG_HWA_EnablePllClockMonitor(SCG_PLL0_CLOCK_SYMBOL);
                }

                if (pPllConfig->bCmre)
                {
                    SCG_HWA_EnablePllClockMonitorReset(SCG_PLL0_CLOCK_SYMBOL);
                }

                if (pPllConfig->bLock)
                {
                    /* lock CSR register */
                    SCG_HWA_LockPllCsr(SCG_PLL0_CLOCK_SYMBOL);
                }

                /* Wait DIV[ACK] change to 1 */
                u32TempVal = CLOCK_DIV_STABILIZATION_TIMEOUT;
                SCG_CheckClockAckStatus((SCG_CHECK_DIV_ACK(SCG_HWA_GetClockDiv(SCG_PLL0_CLOCK_SYMBOL)) !=
                                         SCG_CLOCKDIV_DIV_ACK_MASK_SHIFT), u32TempVal, eStatusVal)
            }
            else
            {
#if SCG_PLLX_CLK1_SUPPORT
                /* Disable PLL0_CLK1 */
                SCG_HWA_DisablePLL0CLK1Output();
#endif
#if SCG_PLL0_CLK2_SUPPORT
                /* Disable PLL0_CLK2 */
                SCG_HWA_DisablePLL0CLK2Output();
#endif /* SCG_PLL0_CLK2_SUPPORT */

                /* Clear CSR configuration */
                SCG_HWA_SetPllCsr(SCG_PLL0_CLOCK_SYMBOL, 0U);

                /* Clear CFG configuration */
                SCG_HWA_SetPllCfg(SCG_PLL0_CLOCK_SYMBOL, 0U);

                /* Clear DIV configuration*/
                SCG_HWA_SetPllDiv(SCG_PLL0_CLOCK_SYMBOL, 0U);

#if SCG_PLLX_CLK1_SUPPORT
                SCG_HWA_EnablePll0ForceOff();
#endif
            }
        }
    }

    return eStatusVal;
}

#if SCG_PLL1_SUPPORT
/**
 * @brief  Enable PLL1
 * @param  pPllConfig: PLL configuration
 * @return SCG_StatusType: SCG status
 */
static SCG_StatusType SCG_EnablePLL1(const SCG_PllType *const pPllConfig)
{
    SCG_StatusType eStatusVal = SCG_STATUS_SUCCESS;
    uint32_t u32TempVal;
    uint32_t u32Freq, u32FeedBackFreq, u32VcoFreq;
    uint32_t u32PllClk1Freq   = 0U;
    uint32_t u32DivHClockFreq = 0U;
    uint32_t u32DivMClockFreq = 0U;
    uint32_t u32DivLClockFreq = 0U;

    /* check pll is valid, if valid, do not configure PLL */
    if ( (true == SCG_HWA_GetClockValid(SCG_PLL1_CLOCK_SYMBOL)) ||
         (true == SCG_HWA_GetPllLocked(SCG_PLL1_CLOCK_SYMBOL)) )
    {
        eStatusVal = SCG_STATUS_SEQUENCE_ERROR;
    }

#if SCG_PLLX_CLK1_SUPPORT && SCG_PLL_ERRATA_PSTDIV1_SUPPORT
    /* check pll pstdiv1 when pll0_clk1 is enable */
    if ((true == pPllConfig->bPllx_Clk1En) && (SCG_PLLPSTDIV1_BY4 == pPllConfig->ePstDiv1))
    {
        eStatusVal = SCG_STATUS_PARAM_ERROR;
    }
#endif /* SCG_PLLX_CLK1_SUPPORT */

    if (eStatusVal == SCG_STATUS_SUCCESS)
    {
        /*   PLL input is FOSC or FIRC clock/2  */
        u32Freq = (SCG_PLLSOURCE_FOSC == pPllConfig->eSrc) ? (FOSC_FREQUENCY) : (FIRC_CLOCK / 2U);

        /* Check the PLL feedback clock range */
        u32FeedBackFreq = u32Freq / ((uint8_t)(pPllConfig->ePrediv) + 1U);
        if (u32FeedBackFreq < PLL_FEEDBACK_CLK_MIN || u32FeedBackFreq > PLL_FEEDBACK_CLK_MAX)
        {
            eStatusVal = SCG_STATUS_PARAM_ERROR;
        }
        else
        {
            /* Check the PLL VCO clock range */
            u32VcoFreq = u32FeedBackFreq * (pPllConfig->u16Mult + 1U);
            if ((u32VcoFreq < PLL_VCO_CLK_MIN) || (u32VcoFreq > PLL_VCO_CLK_MAX))
            {
                eStatusVal = SCG_STATUS_PARAM_ERROR;
            }
            else
            {
                /* Check the PLL out clock range */
                /* PSTDIV = 0b/1b, Post-Divider divide 2 */
                u32TempVal = ((0U == (uint8_t)(pPllConfig->ePstDiv)) ? 1U : (uint32_t)(pPllConfig->ePstDiv));
                u32Freq = (u32VcoFreq >> u32TempVal);

                if ( (u32Freq < PLL_CLK_MIN) || (u32Freq > PLL_CLK_MAX) )
                {
                    eStatusVal = SCG_STATUS_PARAM_ERROR;
                }
#if SCG_PLLX_CLK1_SUPPORT
                else
                {
                    /* Check PLL0_CLK1 clock range */
                    if(true == pPllConfig->bPllx_Clk1En)
                    {
                        u32TempVal = (((uint32_t)(pPllConfig->ePstDiv1) + 1U) << 1U);
                        u32PllClk1Freq = u32VcoFreq / u32TempVal;
                        if(u32PllClk1Freq > PLLx_CLK1_CLK_MAX)
                        {
                            eStatusVal = SCG_STATUS_PARAM_ERROR;
                        }
                    }
                    else
                    {
                        /* do not check when Pll0_Clk1 is not enable. */
                    }
                }
#else
                PROCESS_UNUSED_VAR(u32PllClk1Freq)
#endif /* SCG_PLLX_CLK1_SUPPORT */
            }
        }

        /* Check DIV clock frequency is valid or not */
        if (eStatusVal == SCG_STATUS_SUCCESS)
        {
            if (pPllConfig->eDivH != SCG_ASYNC_CLOCK_DISABLE)
            {
                u32DivHClockFreq = (uint32_t)(u32Freq >> ((uint8_t)(pPllConfig->eDivH) - 1U));
            }
            if (pPllConfig->eDivM != SCG_ASYNC_CLOCK_DISABLE)
            {
                u32DivMClockFreq = (uint32_t)(u32Freq >> ((uint8_t)(pPllConfig->eDivM) - 1U));
            }
            if (pPllConfig->eDivL != SCG_ASYNC_CLOCK_DISABLE)
            {
                u32DivLClockFreq = (uint32_t)(u32Freq >> ((uint8_t)(pPllConfig->eDivL) - 1U));
            }

            if ((u32DivHClockFreq > PLL1_DIVH_MAX_CLOCK) || (u32DivMClockFreq > PLL1_DIVM_MAX_CLOCK) || (u32DivLClockFreq > PLL1_DIVL_MAX_CLOCK))
            {
                eStatusVal = SCG_STATUS_PARAM_ERROR;
            }
        }
    }

    if (eStatusVal == SCG_STATUS_SUCCESS)
    {
        /* Disable PLLDIV */
        SCG_HWA_DisablePllDiv(SCG_PLL1_CLOCK_SYMBOL);
        /* Wait DIV[ACK] change to 0 */
        SCG_CheckClockAckStatus((SCG_CHECK_DIV_ACK(SCG_HWA_GetClockDiv(SCG_PLL1_CLOCK_SYMBOL)) ==
                                 SCG_CLOCKDIV_DIV_ACK_MASK_SHIFT), u32TempVal, eStatusVal)

        if (eStatusVal == SCG_STATUS_SUCCESS)
        {
            /* unlock PLL CSR register */
            SCG_HWA_UnlockPllCsr(SCG_PLL1_CLOCK_SYMBOL);

            /* Configure PLLCFG register */

            u32TempVal =  SCG_PLLCFG_PREDIV(pPllConfig->ePrediv) |
                          SCG_PLLCFG_MULT(pPllConfig->u16Mult) |
                          SCG_PLLCFG_PSTDIV(pPllConfig->ePstDiv) |
#if SCG_PLLX_CLK1_SUPPORT
                          SCG_PLLCFG_PSTDIV1(pPllConfig->ePstDiv1) |
#endif /* SCG_PLLX_CLK1_SUPPORT */
                          SCG_PLLCFG_SOURCE(pPllConfig->eSrc);

            SCG_HWA_SetPllCfg(SCG_PLL1_CLOCK_SYMBOL, u32TempVal);

#if SCG_PLLX_CLK1_SUPPORT
#else
            SCG_HWA_SetCfgRegProt((boolean)TRUE);
            SCG_HWA_EnablePll1FastStart();
            SCG_HWA_SetCfgRegProt((boolean)FALSE);
#endif /* SCG_PLLX_CLK1_SUPPORT */

            /* Configure PLLCSR register */
            u32TempVal = SCG_PLL1CSR_ERR_MASK |
#if SCG_PLLX_CLK1_SUPPORT
                         SCG_PLL1CSR_CK1EN(pPllConfig->bPllx_Clk1En)|
#endif /* SCG_PLLX_CLK1_SUPPORT */
                         SCG_PLLCSR_STEN(pPllConfig->bSten);
            SCG_HWA_SetPllCsr(SCG_PLL1_CLOCK_SYMBOL, u32TempVal);

            /* Configure PLLDIV */
            u32TempVal = SCG_HWA_GetClockDiv(SCG_PLL1_CLOCK_SYMBOL);
            u32TempVal &= ~(uint32_t)(SCG_PLLDIV_DIVL_MASK | SCG_PLLDIV_DIVM_MASK | SCG_PLLDIV_DIVH_MASK);
            u32TempVal |= (SCG_PLLDIV_DIVH(pPllConfig->eDivH) |
                           SCG_PLLDIV_DIVM(pPllConfig->eDivM) |
                           SCG_PLLDIV_DIVL(pPllConfig->eDivL));
            SCG_HWA_SetPllDiv(SCG_PLL1_CLOCK_SYMBOL, u32TempVal) ;

            /* Set CSR[EN] bit to 1 */
            SCG_HWA_EnablePll(SCG_PLL1_CLOCK_SYMBOL);

            /* Wait PLL locked */
            u32TempVal = PLL_STABILIZATION_TIMEOUT;
            SCG_CheckClockAckStatus(( (false == SCG_HWA_GetPllLocked(SCG_PLL1_CLOCK_SYMBOL)) ||
                                      (false == SCG_HWA_GetClockValid(SCG_PLL1_CLOCK_SYMBOL)) ),
                                    u32TempVal, eStatusVal)

            if (eStatusVal == SCG_STATUS_SUCCESS)
            {
                /* Enable PLLDIV */
                SCG_HWA_EnablePllDiv(SCG_PLL1_CLOCK_SYMBOL);

                if (pPllConfig->bCm)
                {
                    SCG_HWA_EnablePllClockMonitor(SCG_PLL1_CLOCK_SYMBOL);
                }

                if (pPllConfig->bCmre)
                {
                    SCG_HWA_EnablePllClockMonitorReset(SCG_PLL1_CLOCK_SYMBOL);
                }

                if (pPllConfig->bLock)
                {
                    /* lock CSR register */
                    SCG_HWA_LockPllCsr(SCG_PLL1_CLOCK_SYMBOL);
                }

                /* Wait DIV[ACK] change to 1 */
                u32TempVal = CLOCK_DIV_STABILIZATION_TIMEOUT;
                SCG_CheckClockAckStatus((SCG_CHECK_DIV_ACK(SCG_HWA_GetClockDiv(SCG_PLL1_CLOCK_SYMBOL)) !=
                                         SCG_CLOCKDIV_DIV_ACK_MASK_SHIFT), u32TempVal, eStatusVal)
            }
            else
            {
#if SCG_PLLX_CLK1_SUPPORT
                /* Disable PLL0_CLK1 */
                SCG_HWA_DisablePLL1CLK1Output();
#endif

                /* Clear CSR configuration */
                SCG_HWA_SetPllCsr(SCG_PLL1_CLOCK_SYMBOL, 0U);

                /* Clear CFG configuration */
                SCG_HWA_SetPllCfg(SCG_PLL1_CLOCK_SYMBOL, 0U);

                /* Clear DIV configuration*/
                SCG_HWA_SetPllDiv(SCG_PLL1_CLOCK_SYMBOL, 0U);
#if SCG_PLLX_CLK1_SUPPORT
                SCG_HWA_EnablePll1ForceOff();
#endif
            }
        }
    }

    return eStatusVal;
}
#endif /* SCG_PLL1_SUPPORT */

/**
 * @brief  Disable PLL0.
 *
 * @return  PLL0 disable status.
 */
static SCG_StatusType SCG_DisablePLL0(void)
{
    SCG_StatusType eStatusVal = SCG_STATUS_SUCCESS;
    uint32_t u32TempVal;

    /* unlock PLL CSR register */
    SCG_HWA_UnlockPllCsr(SCG_PLL0_CLOCK_SYMBOL);

#if SCG_PLLX_CLK1_SUPPORT
    /* Disable PLL0_CLK1 first  */
    SCG_HWA_DisablePLL0CLK1Output();
#endif

#if SCG_PLL0_CLK2_SUPPORT
    /* Disable PLL0_CLK2 first  */
    SCG_HWA_DisablePLL0CLK2Output();
#endif /* SCG_PLL0_CLK2_SUPPORT */

    /* Clear CSR configuration(mainly for disable PLL0) */
    SCG_HWA_SetPllCsr(SCG_PLL0_CLOCK_SYMBOL, 0U);

#if SCG_PLL_INIT_DIS_FOSC_SUPPORT
    /* Unlock CSR register */
    SCG_HWA_UnlockFoscCsr();
    /* Clear FOSC[EN] bit */
    SCG_HWA_DisableFosc();
#endif

#if SCG_PLL0_CLK2_SUPPORT
    /* Clear ECFG configuration */
    SCG_HWA_SetPll0Ecfg(0U);
#endif /* SCG_PLL0_CLK2_SUPPORT */

    /* Clear CFG configuration */
    SCG_HWA_SetPllCfg(SCG_PLL0_CLOCK_SYMBOL, 0U);

#if SCG_PLLX_CLK1_SUPPORT
    SCG_HWA_EnablePll0ForceOff();
#endif

    u32TempVal = CLOCK_OFF_STABILIZATION_TIMEOUT;
    SCG_CheckClockAckStatus(( (true == SCG_HWA_GetClockValid(SCG_PLL0_CLOCK_SYMBOL)) ||
                              (true == SCG_HWA_GetPllLocked(SCG_PLL0_CLOCK_SYMBOL)) ),
                            u32TempVal, eStatusVal)

    if (eStatusVal == SCG_STATUS_SUCCESS)
    {
        /* Clear CSR register */
        SCG_HWA_SetPllCsr(SCG_PLL0_CLOCK_SYMBOL, 0U);

        /* In order to avoid the DIV register value not cleared, Clear PLL DIV register twice */
        SCG_HWA_SetPllDiv(SCG_PLL0_CLOCK_SYMBOL, 0U);
        SCG_HWA_SetPllDiv(SCG_PLL0_CLOCK_SYMBOL, 0U);
    }

    return eStatusVal;
}

#if SCG_PLL1_SUPPORT
/**
 * @brief  Disable PLL1.
 *
 * @return  PLL1 disable status.
 */
static SCG_StatusType SCG_DisablePLL1(void)
{
    SCG_StatusType eStatusVal = SCG_STATUS_SUCCESS;
    uint32_t u32TempVal;

    /* unlock PLL CSR register */
    SCG_HWA_UnlockPllCsr(SCG_PLL1_CLOCK_SYMBOL);

#if SCG_PLLX_CLK1_SUPPORT
    /* Disable PLL0_CLK1 first  */
    SCG_HWA_DisablePLL1CLK1Output();
#endif

    /* Clear CSR configuration(mainly for disable PLL0) */
    SCG_HWA_SetPllCsr(SCG_PLL1_CLOCK_SYMBOL, 0U);

#if SCG_PLL_INIT_DIS_FOSC_SUPPORT
    /* Unlock CSR register */
    SCG_HWA_UnlockFoscCsr();
    /* Clear FOSC[EN] bit */
    SCG_HWA_DisableFosc();
#endif

    /* Clear CFG configuration */
    SCG_HWA_SetPllCfg(SCG_PLL1_CLOCK_SYMBOL, 0U);

#if SCG_PLLX_CLK1_SUPPORT
    SCG_HWA_EnablePll1ForceOff();
#endif

    u32TempVal = CLOCK_OFF_STABILIZATION_TIMEOUT;
    SCG_CheckClockAckStatus(( (true == SCG_HWA_GetClockValid(SCG_PLL1_CLOCK_SYMBOL)) ||
                              (true == SCG_HWA_GetPllLocked(SCG_PLL1_CLOCK_SYMBOL)) ),
                             u32TempVal, eStatusVal)

    if (eStatusVal == SCG_STATUS_SUCCESS)
    {
        /* Clear CSR register */
        SCG_HWA_SetPllCsr(SCG_PLL1_CLOCK_SYMBOL, 0U);

        /* In order to avoid the DIV register value not cleared, Clear PLL DIV register twice */
        SCG_HWA_SetPllDiv(SCG_PLL1_CLOCK_SYMBOL, 0U);
        SCG_HWA_SetPllDiv(SCG_PLL1_CLOCK_SYMBOL, 0U);
    }

    return eStatusVal;
}
#endif /* SCG_PLL1_SUPPORT */

/***************** Global Functions *********************/
/**
 * @brief Enable SOSC
 *
 * @param pSoscConfig SOSC configuration
 * @return SCG_StatusType Function status
 */
SCG_StatusType SCG_EnableSOSC(const SCG_SoscType *const pSoscConfig)
{
    SCG_StatusType eStatusVal = SCG_STATUS_SUCCESS;
    uint32_t u32TempVal;

#if SCG_DEV_ERROR_REPORT == STD_ON
    if (NULL == pSoscConfig)
    {
        SCG_ReportDevError(SCG_ENABLE_SOSC_ID, SCG_E_PARAM_POINTER);
    }
    else
    {
#endif

        /* Disable Sosc */
        SCG_HWA_DisableSosc();

        /* Configure SOSC, recommend Eocv value is 64 */
        u32TempVal = (uint32_t)(SCG_SOSCCFG_EOCV(pSoscConfig->u8Eocv) |
                                SCG_SOSCCFG_GM_SEL(3U)  |
                                SCG_SOSCCFG_CURPRG_SF(3U) |
                                SCG_SOSCCFG_CURPRG_COMP(3U));
        SCG_HWA_SetSoscCfg(u32TempVal);

        /* Unlock CSR register first */
        SCG_HWA_UnlockSoscCsr();

        /* Configure SOSC CSR register */
        u32TempVal = SCG_HWA_GetSoscCsr();
        u32TempVal &= ~(uint32_t)(SCG_SOSCCSR_BYPASS_MASK | SCG_SOSCCSR_CM_MASK | SCG_SOSCCSR_CMRE_MASK);
        u32TempVal |= SCG_SOSCCSR_BYPASS(pSoscConfig->bBypass);
        SCG_HWA_SetSoscCsr(u32TempVal);

        /* Enable SOSC*/
        SCG_HWA_EnableSosc();

        if(pSoscConfig->bNoWait)
        {
            /* No wait SOSC valid, SOSC valid status must be polling before used  */
        }
        else
        {
            /* Wait SOSC valid */
            u32TempVal = SOSC_STABILIZATION_TIMEOUT;
            SCG_CheckClockAckStatus((false == SCG_HWA_GetClockValid(SCG_SOSC_CLOCK_SYMBOL)), u32TempVal, eStatusVal)

            if (eStatusVal == SCG_STATUS_SUCCESS)
            {
                if (pSoscConfig->bCm)
                {
                    SCG_HWA_EnableSoscClockMonitor();
                }

                if (pSoscConfig->bCmre)
                {
                    SCG_HWA_EnableSoscClockMonitorReset();
                }

                if (pSoscConfig->bLock)
                {
                    /* Lock CSR */
                    SCG_HWA_LockSoscCsr();
                }
            }
            else
            {
                SCG_HWA_SetSoscCsr(0U);
            }
        }

#if SCG_DEV_ERROR_REPORT == STD_ON
    }
#endif

    return eStatusVal;
}

/**
 * @brief Disable SOSC
 *
 * @return SCG_StatusType Function status
 */
SCG_StatusType SCG_DisableSOSC(void)
{
    SCG_StatusType eStatusVal;
    uint32_t u32TempVal;

    /* Unlock CSR register first */
    SCG_HWA_UnlockSoscCsr();

    /* Disable SOSC */
    SCG_HWA_DisableSosc();

    /* Wait SOSC valid */
    u32TempVal = SOSC_STABILIZATION_TIMEOUT;
    SCG_CheckClockAckStatus((true == SCG_HWA_GetClockValid(SCG_SOSC_CLOCK_SYMBOL)), u32TempVal, eStatusVal)

    if (eStatusVal == SCG_STATUS_SUCCESS)
    {
        /* Clear CSR register */
        SCG_HWA_SetSoscCsr(0U);
    }

    return eStatusVal;
}

/**
 * @brief Get SOSC Valid status
 *
 * @return SCG_StatusType Function status
 */
SCG_StatusType SCG_GetSOSCValidStatus(void)
{
    SCG_StatusType eStatusVal;

    if(true == SCG_HWA_GetClockValid(SCG_SOSC_CLOCK_SYMBOL))
    {
        eStatusVal = SCG_STATUS_SUCCESS;
    }
    else
    {
        eStatusVal = SCG_STATUS_SEQUENCE_ERROR;
    }
    return eStatusVal;
}

/**
 * @brief Enable FOSC clock with input configuration
 *
 * @param pFoscConfig FOSC configuration
 * @return SCG_StatusType function status
 */
SCG_StatusType SCG_EnableFOSC(const SCG_FoscType *const pFoscConfig)
{
    SCG_StatusType eStatusVal = SCG_STATUS_PARAM_ERROR;
    uint32_t u32TempVal;
    uint32_t u32DivHClockFreq = 0U;
    uint32_t u32DivMClockFreq = 0U;
    uint32_t u32DivLClockFreq = 0U;
#if SCG_LP_WKPWDG_SUPPORT
    uint32_t u32FoscFreq;
    uint8_t u8MSBVal;
#endif

#if SCG_DEV_ERROR_REPORT == STD_ON
    if (NULL_PTR == pFoscConfig)
    {
        SCG_ReportDevError(SCG_ENABLE_FOSC_ID, SCG_E_PARAM_POINTER);
    }
    else
    {
#endif

        /* Check DIV clock frequency is valid or not */
        if (SCG_ASYNC_CLOCK_DISABLE != pFoscConfig->eDivH)
        {
            u32DivHClockFreq = (uint32_t)(FOSC_FREQUENCY >> ((uint8_t)(pFoscConfig->eDivH) - 1U));
        }

        if (SCG_ASYNC_CLOCK_DISABLE != pFoscConfig->eDivM)
        {
            u32DivMClockFreq = (uint32_t)(FOSC_FREQUENCY >> ((uint8_t)(pFoscConfig->eDivM) - 1U));
        }

        if (SCG_ASYNC_CLOCK_DISABLE != pFoscConfig->eDivL)
        {
            u32DivLClockFreq = (uint32_t)(FOSC_FREQUENCY >> ((uint8_t)(pFoscConfig->eDivL) - 1U));
        }

        if ((u32DivHClockFreq > FOSC_DIVH_MAX_CLOCK) || (u32DivMClockFreq > FOSC_DIVM_MAX_CLOCK) || (u32DivLClockFreq > FOSC_DIVL_MAX_CLOCK))
        {
            eStatusVal = SCG_STATUS_PARAM_ERROR;
        }
        else
        {
            /* Disable Fosc */
            SCG_HWA_DisableFosc();

            /* Disable FOSC DIVEN */
            SCG_HWA_DiableFoscDiv();

            /* Wait DIV[ACK] change to 0 */
            u32TempVal = CLOCK_DIV_STABILIZATION_TIMEOUT;
            SCG_CheckClockAckStatus((SCG_CHECK_DIV_ACK(SCG_HWA_GetClockDiv(SCG_FOSC_CLOCK_SYMBOL)) ==
                                     SCG_CLOCKDIV_DIV_ACK_MASK_SHIFT), u32TempVal, eStatusVal)

            if (eStatusVal == SCG_STATUS_SUCCESS)
            {
                /* Unlock CSR register */
                SCG_HWA_UnlockFoscCsr();

                /* recommend Eocv value is 50 */
                /* COMP_EN is setting to 1  COMP_EN must be 1 when using an external crystal */
                /* Configure GM to the max value, GM_SEL: 15U */
                u32TempVal = SCG_FOSCCFG_BYPASS(pFoscConfig->bBypass) | SCG_FOSCCFG_COMP_EN(!pFoscConfig->bBypass) |
                             SCG_FOSCCFG_EOCV(pFoscConfig->u8Eocv)    | SCG_FOSCCFG_GM_SEL(15U) |
                             SCG_FOSCCFG_ALC_D(1U) | SCG_FOSCCFG_HYST_D(0U);
                SCG_HWA_SetFoscCfg(u32TempVal);

                /* Configure CSR register */
                u32TempVal = SCG_HWA_GetFoscCsr();
                u32TempVal &= ~(uint32_t)(SCG_FOSCCSR_STEN_MASK | SCG_FOSCCSR_CM_MASK | SCG_FOSCCSR_CMRE_MASK);
                u32TempVal |= SCG_FOSCCSR_STEN(pFoscConfig->bSten);
                SCG_HWA_SetFoscCsr(u32TempVal);

                /* Configure DIV value */
                u32TempVal = SCG_HWA_GetClockDiv(SCG_FOSC_CLOCK_SYMBOL);
                u32TempVal &= ~(uint32_t)(SCG_FOSCDIV_DIVL_MASK | SCG_FOSCDIV_DIVM_MASK | SCG_FOSCDIV_DIVH_MASK);
                u32TempVal |= (SCG_FOSCDIV_DIVH(pFoscConfig->eDivH) |
                               SCG_FOSCDIV_DIVM(pFoscConfig->eDivM) |
                               SCG_FOSCDIV_DIVL(pFoscConfig->eDivL));
                SCG_HWA_SetFoscDiv(u32TempVal) ;

                /* Enable FOSC */
                SCG_HWA_EnableFosc();

                /* Wait FOSC valid */
                u32TempVal = FOSC_STABILIZATION_TIMEOUT;
                SCG_CheckClockAckStatus((false == SCG_HWA_GetClockValid(SCG_FOSC_CLOCK_SYMBOL)), u32TempVal, eStatusVal)

                if (eStatusVal == SCG_STATUS_SUCCESS)
                {
                    /* Enable DIV */
                    SCG_HWA_EnableFoscDiv();

                    if (pFoscConfig->bCm)
                    {
                        SCG_HWA_EnableFoscClockMonitor();
                    }

                    if (pFoscConfig->bCmre)
                    {
                        SCG_HWA_EnableFoscClockMonitorReset();
                    }

                    if (pFoscConfig->bLock)
                    {
                        /* Lock FOSC CSR register */
                        SCG_HWA_LockFoscCsr();
                    }

                    /* Wait DIV[ACK] change to 1 */
                    u32TempVal = CLOCK_DIV_STABILIZATION_TIMEOUT;
                    SCG_CheckClockAckStatus((SCG_CHECK_DIV_ACK(SCG_HWA_GetClockDiv(SCG_FOSC_CLOCK_SYMBOL)) !=
                                             SCG_CLOCKDIV_DIV_ACK_MASK_SHIFT), u32TempVal, eStatusVal)

                    /* if OSC >= 40M ,set 5, if OSC = 32M,set 10, if OSC = 24M, set 15, if OSC = 16M, set 20, if OSC = 8M, set 25*/
                    /* This is the protection measure during low power wake up, if SCG register not valid after the setting time, the chip will reset
                     * and will set clock error flag in RGM register */
#if SCG_LP_WKPWDG_SUPPORT
                    u32FoscFreq = FOSC_FREQUENCY;
                    u8MSBVal = ((u32FoscFreq / 8000000U) >= 5U) ? (uint8_t)5U : (uint8_t)((6U - (FOSC_FREQUENCY / 8000000U)) * 5U);
                    SCG_HWA_SetWKPWDG(u8MSBVal);
#endif

                }
                else
                {
                    /* Clear CSR configuration */
                    SCG_HWA_SetFoscCsr(0U);

                    /* Clear CFG configuration*/
                    SCG_HWA_SetFoscCfg(0U);

                    /* Clear DIV configuration*/
                    SCG_HWA_SetFoscDiv(0U);
                }
            }
        }

#if SCG_DEV_ERROR_REPORT == STD_ON
    }
#endif

    return eStatusVal;
}

/**
 * @brief Disable FOSC
 *
 * @return SCG_StatusType function status
 */
SCG_StatusType SCG_DisableFOSC(void)
{
    SCG_StatusType eStatusVal = SCG_STATUS_SUCCESS;
    uint32_t u32TempVal;
    uint8_t u8ClkSrc;

    u8ClkSrc = SCG_HWA_GetSysClkSrc();
    if ((uint8_t)SCG_CLOCK_SRC_FOSC == u8ClkSrc)
    {
        eStatusVal = SCG_STATUS_SEQUENCE_ERROR;
    }
    else if ((SCG_HWA_GetPllSrc(SCG_PLL0_CLOCK_SYMBOL) == (uint8_t)SCG_PLLSOURCE_FOSC) && ((uint8_t)SCG_CLOCK_SRC_PLL0 == u8ClkSrc))
    {
        eStatusVal = SCG_STATUS_SEQUENCE_ERROR;
    }
    else
    {
        /* do nothing */
    }

    if (eStatusVal == SCG_STATUS_SUCCESS)
    {
        /* Unlock CSR register */
        SCG_HWA_UnlockFoscCsr();

        /* Clear FOSC[EN] bit */
        SCG_HWA_DisableFosc();

        u32TempVal = CLOCK_OFF_STABILIZATION_TIMEOUT;
        SCG_CheckClockAckStatus((true == SCG_HWA_GetClockValid(SCG_FOSC_CLOCK_SYMBOL)), u32TempVal, eStatusVal)

        if (eStatusVal == SCG_STATUS_SUCCESS)
        {
            /* Clear CSR register */
            SCG_HWA_SetFoscCsr(0U);

            /* In order to avoid the DIV register value not cleared, Clear FOSC DIV register twice */
            SCG_HWA_SetFoscDiv(0U);
            SCG_HWA_SetFoscDiv(0U);
        }
    }

    return eStatusVal;
}

/**
 * @brief Set SIRC configuration and configure SIRC DIV
 *
 * @param pSircConfig SIRC configuration
 * @return SCG_StatusType function status
 */
SCG_StatusType SCG_SetSIRC(const SCG_SircType *const pSircConfig)
{
    SCG_StatusType eStatusVal = SCG_STATUS_PARAM_ERROR;
    uint32_t u32TempVal = 0U;
#if SCG_AUTOTRIM_SUPPORT
    uint16_t u16TrimDiv = 0U;
#endif

#if SCG_DEV_ERROR_REPORT == STD_ON
    if (NULL == pSircConfig)
    {
        SCG_ReportDevError(SCG_SET_SIRC_ID, SCG_E_PARAM_POINTER);
    }
    else
    {
#endif

        /* Unlock SIRC CSR register */
        SCG_HWA_UnlockSircCsr();

        /* Configure CSR register, clear TRUP,TREN,CM ,ERR(w1c)and configure STEN,LPEN  */
        u32TempVal = SCG_HWA_GetSircCsr();
        u32TempVal &= ~(uint32_t)( SCG_SIRCCSR_STEN_MASK  |
                                   SCG_SIRCCSR_LPEN_MASK  |
#if SCG_SIRC_LP_WAKEUP_SUPPORT
                                   SCG_SIRCCSR_LPWKE_MASK |
#endif /* SCG_SIRC_LP_WAKEUP_SUPPORT */
                                   SCG_SIRCCSR_TREN_MASK  |
                                   SCG_SIRCCSR_TRUP_MASK  |
                                   SCG_SIRCCSR_CM_MASK
                                 );
        u32TempVal |= (uint32_t)(SCG_SIRCCSR_LPEN(pSircConfig->bLpen) |
                                 SCG_SIRCCSR_STEN(pSircConfig->bSten) |
#if SCG_SIRC_LP_WAKEUP_SUPPORT
                                 SCG_SIRCCSR_LPWKE(pSircConfig->bLpwken) |
#endif /* SCG_SIRC_LP_WAKEUP_SUPPORT */
                                 SCG_SIRCCSR_ERR_MASK);
        SCG_HWA_SetSircCsr(u32TempVal);

        /* Disable SIRC DIV[EN] bit */
        SCG_HWA_DiableSircDiv();
        /* Wait div ack change to 0  */
        SCG_CheckClockAckStatus((SCG_CHECK_DIV_ACK(SCG_HWA_GetClockDiv(SCG_SIRC_CLOCK_SYMBOL)) ==
                                 SCG_CLOCKDIV_DIV_ACK_MASK_SHIFT), u32TempVal, eStatusVal)

        if (eStatusVal == SCG_STATUS_SUCCESS)
        {
            /* Configure SIRC DIV */
            u32TempVal = SCG_HWA_GetClockDiv(SCG_SIRC_CLOCK_SYMBOL);
            u32TempVal &= ~(uint32_t)(SCG_SIRCDIV_DIVL_MASK | SCG_SIRCDIV_DIVM_MASK | SCG_SIRCDIV_DIVH_MASK);
            u32TempVal |= (uint32_t)(SCG_SIRCDIV_DIVL(pSircConfig->eDivL) |
                                     SCG_SIRCDIV_DIVM(pSircConfig->eDivM) |
                                     SCG_SIRCDIV_DIVH(pSircConfig->eDivH));
            SCG_HWA_SetSircDiv(u32TempVal);

            /* Enable SIRC DIV */
            SCG_HWA_EnableSircDiv();
            u32TempVal = CLOCK_DIV_STABILIZATION_TIMEOUT;
            SCG_CheckClockAckStatus((SCG_CHECK_DIV_ACK(SCG_HWA_GetClockDiv(SCG_SIRC_CLOCK_SYMBOL)) !=
                                     SCG_CLOCKDIV_DIV_ACK_MASK_SHIFT), u32TempVal, eStatusVal)

            if (SCG_STATUS_SUCCESS != eStatusVal)
            {
                /* Clear SIRC DIV register */
                SCG_HWA_SetSircDiv(0U);
            }

#if SCG_AUTOTRIM_SUPPORT
            /* Set SIRCTCFG register */
            if (pSircConfig->bTrEn == true)
            {
                /*   set SIRCTCFG trim configuration    */
                if (pSircConfig->u8TrimSrc == (uint8_t)SCG_IRC_TRIMSRC_FOSC)
                {
                    /*   Trim clock source choose FOSC   */
                    u16TrimDiv = (uint16_t)(FOSC_FREQUENCY / IRC_TRIM_DIV_CLOCK - 1U);
                }
                else if (pSircConfig->u8TrimSrc == (uint8_t)SCG_IRC_TRIMSRC_SOSC)
                {
                    /*   Trim clock source choose SOSC   */
                    u16TrimDiv = 0U;
                }
                else
                {
                    /* Do nothing */
                }

                /* This register can only be written when FIRCCSR[TREN] is cleared */
                u32TempVal = (uint32_t)(SCG_SIRCTCFG_TRIMSRC(pSircConfig->u8TrimSrc) | SCG_SIRCTCFG_TRIMDIV(u16TrimDiv));
                SCG_HWA_SetSircTcfg(u32TempVal);

                /* Set TRUP and EN together with TREN setting   */
                u32TempVal = SCG_HWA_GetSircCsr();
                u32TempVal |= (uint32_t)(SCG_SIRCCSR_TRUP(true) | SCG_SIRCCSR_TREN(true));
                SCG_HWA_SetSircCsr(u32TempVal);

                /* Wait SIRC trim completion */
                u32TempVal = IRC_TRIM_STABILIZATION_TIMEOUT;
                SCG_CheckClockAckStatus((false == SCG_HWA_GetTrimLocked(SCG_SIRC_CLOCK_SYMBOL)), u32TempVal, eStatusVal)
            }
            else
            {
                /* Do nothing */
            }
#endif /* SCG_AUTOTRIM_SUPPORT */

            if (SCG_STATUS_SUCCESS == eStatusVal)
            {
                if (pSircConfig->bCm)
                {
                    SCG_HWA_EnableSircClockMonitor();
                }
                else
                {
                    /* Cleared before */
                }

                if (pSircConfig->bLock)
                {
                    /* lock CSR */
                    SCG_HWA_LockSircCsr();
                }
            }
        }

#if SCG_DEV_ERROR_REPORT == STD_ON
    }
#endif

    return eStatusVal;
}

/**
 * @brief Disable SIRC DIV and clear DIV configuration
 *
 * @return SCG_StatusType function status
 */
SCG_StatusType SCG_ClearSIRC(void)
{
    SCG_StatusType eStatusVal = SCG_STATUS_SUCCESS;

    /* check SIRC is invalid, if invalid, do not configure SIRC */
    if (true != SCG_HWA_GetClockValid(SCG_SIRC_CLOCK_SYMBOL))
    {
        eStatusVal = SCG_STATUS_SEQUENCE_ERROR;
    }

    if (eStatusVal == SCG_STATUS_SUCCESS)
    {
        /* Unlock SIRC CSR register */
        SCG_HWA_UnlockSircCsr();

        /* Disable SIRC DIV[EN] bit */
        SCG_HWA_DiableSircDiv();

        /* Clear SIRC DIV register */
        SCG_HWA_SetSircDiv(0U);
    }

    return eStatusVal;
}

/**
 * @brief Enable SIRC32K
 *
 * @param pSirc32kConfig SIRC32K configuration
 * @return SCG_StatusType function status
 */
SCG_StatusType SCG_EnableSIRC32K(const SCG_Sirc32kType *const pSirc32kConfig)
{
    SCG_StatusType eStatusVal = SCG_STATUS_SUCCESS;
    uint32_t u32TempVal;

#if SCG_DEV_ERROR_REPORT == STD_ON
    if (NULL_PTR == pSirc32kConfig)
    {
        SCG_ReportDevError(SCG_ENABLE_SIRC32K_ID, SCG_E_PARAM_POINTER);
    }
    else
    {
#endif

        /* Unlock SIRC32K CSR register */
        SCG_HWA_UnlockSirc32kCsr();

        /* Enable SIRC32K */
        SCG_HWA_EnableSirc32kCsr();

        /* Wait SIRC32K valid */
        u32TempVal = SIRC32K_STABILIZATION_TIMEOUT;
        SCG_CheckClockAckStatus((false == SCG_HWA_GetClockValid(SCG_SIRC32K_CLOCK_SYMBOL)), u32TempVal, eStatusVal)

        if (eStatusVal == SCG_STATUS_SUCCESS)
        {
            if (pSirc32kConfig->bLock)
            {
                /* Lock SIRC32K CSR register */
                SCG_HWA_LockSirc32kCsr();
            }
        }

#if SCG_DEV_ERROR_REPORT == STD_ON
    }
#endif

    return eStatusVal;
}

/**
 * @brief Disable SIRC32K
 *
 * @return SCG_StatusType function status
 */
SCG_StatusType SCG_DisableSIRC32K(void)
{
    SCG_StatusType eStatusVal;
    uint32_t u32TempVal;

    /* Unlock SIRC32K CSR register */
    SCG_HWA_UnlockSirc32kCsr();

    /* Disable SIRC32K */
    SCG_HWA_DisableSirc32kCsr();

    /* Wait SIRC32K not valid */
    u32TempVal = SIRC32K_STABILIZATION_TIMEOUT;
    SCG_CheckClockAckStatus((true == SCG_HWA_GetClockValid(SCG_SIRC32K_CLOCK_SYMBOL)), u32TempVal, eStatusVal)

    return eStatusVal;
}

/**
 * @brief Enable FIRC
 *
 * @param pFircConfig FIRC configuration
 * @return SCG_StatusType function status
 */
SCG_StatusType SCG_EnableFIRC(const SCG_FircType *const pFircConfig)
{
    SCG_StatusType eStatusVal = SCG_STATUS_PARAM_ERROR;
    uint32_t u32TempVal;
    uint32_t u32DivLClockFreq = 0U;
#if SCG_AUTOTRIM_SUPPORT
    uint16_t u16TrimDiv = 0U;
#endif

#if SCG_DEV_ERROR_REPORT == STD_ON
    if (NULL_PTR == pFircConfig)
    {
        SCG_ReportDevError(SCG_ENABLE_FIRC_ID, SCG_E_PARAM_POINTER);
    }
    else
    {
#endif

        /* Check DIV clock frequency is valid or not */
        if (SCG_ASYNC_CLOCK_DISABLE != pFircConfig->eDivL)
        {
            u32DivLClockFreq = (uint32_t)(FIRC_CLOCK >> ((uint8_t)(pFircConfig->eDivL) - 1U));
        }

        if (u32DivLClockFreq > FIRC_DIVL_MAX_CLOCK)
        {
            eStatusVal = SCG_STATUS_PARAM_ERROR;
        }
        else
        {
            /* Disable Div[En] */
            SCG_HWA_DiableFircDiv();
            /* Wait DIV[ACK] change to 0 */
            u32TempVal = CLOCK_DIV_STABILIZATION_TIMEOUT;
            SCG_CheckClockAckStatus((SCG_CHECK_DIV_ACK(SCG_HWA_GetClockDiv(SCG_FIRC_CLOCK_SYMBOL)) ==
                                     SCG_CLOCKDIV_DIV_ACK_MASK_SHIFT), u32TempVal, eStatusVal)

            if (eStatusVal == SCG_STATUS_SUCCESS)
            {
                /* Unlock CSR register */
                SCG_HWA_UnlockFircCsr();

                /* Configure recommend value */
                SCG_HWA_SetFircCfg(SCG_FIRCCFG_CLKEN(3U));

                /* Configure CSR register, clear TRUP,TREN,CM, ERR(w1c)and configure STEN  */
                u32TempVal = SCG_HWA_GetFircCsr();
                u32TempVal &= ~(uint32_t)(SCG_FIRCCSR_STEN_MASK | SCG_FIRCCSR_TREN_MASK | SCG_FIRCCSR_TRUP_MASK | SCG_FIRCCSR_CM_MASK);
                u32TempVal |= (uint32_t)(SCG_FIRCCSR_STEN(pFircConfig->bSten) | SCG_FIRCCSR_ERR_MASK);
                SCG_HWA_SetFircCsr(u32TempVal);

                /* Configure DIV value */
                u32TempVal = SCG_HWA_GetClockDiv(SCG_FIRC_CLOCK_SYMBOL);
                u32TempVal &= ~(uint32_t)(SCG_FIRCDIV_DIVL_MASK | SCG_FIRCDIV_DIVM_MASK | SCG_FIRCDIV_DIVH_MASK);
                u32TempVal |= (SCG_FIRCDIV_DIVH(pFircConfig->eDivH) |
                               SCG_FIRCDIV_DIVM(pFircConfig->eDivM) |
                               SCG_FIRCDIV_DIVL(pFircConfig->eDivL));
                SCG_HWA_SetFircDiv(u32TempVal) ;

                /* Set CSR[EN] bit to 1 */
                SCG_HWA_EnableFirc();

                /* Wait FIRC valid */
                u32TempVal = FIRC_STABILIZATION_TIMEOUT;
                SCG_CheckClockAckStatus((false == SCG_HWA_GetClockValid(SCG_FIRC_CLOCK_SYMBOL)), u32TempVal, eStatusVal)

                if (eStatusVal == SCG_STATUS_SUCCESS)
                {
                    /* Enable DIV */
                    SCG_HWA_EnableFircDiv();

                    /* Wait DIV[ACK] change to 1 */
                    u32TempVal = CLOCK_DIV_STABILIZATION_TIMEOUT;
                    SCG_CheckClockAckStatus((SCG_CHECK_DIV_ACK(SCG_HWA_GetClockDiv(SCG_FIRC_CLOCK_SYMBOL)) !=
                                             SCG_CLOCKDIV_DIV_ACK_MASK_SHIFT), u32TempVal, eStatusVal)

#if SCG_AUTOTRIM_SUPPORT
                    /*   For clock auto trim, set TREN to True together with TRUP to True   */
                    if (pFircConfig->bTrEn == true)
                    {
                        /*   set FIRCTCFG trim configuration    */
                        if (pFircConfig->u8TrimSrc == (uint8_t)SCG_IRC_TRIMSRC_FOSC)
                        {
                            /*   Trim clock source choose FOSC   */
                            u16TrimDiv = (uint16_t)(FOSC_FREQUENCY / IRC_TRIM_DIV_CLOCK - 1U);
                        }
                        else if (pFircConfig->u8TrimSrc == (uint8_t)SCG_IRC_TRIMSRC_SOSC)
                        {
                            /*   Trim clock source choose SOSC   */
                            u16TrimDiv = 0U;
                        }
                        else
                        {
                            /*   do nothing   */
                        }
                        /* This register can only be written when FIRCCSR[TREN] is cleared */
                        u32TempVal = (uint32_t)(SCG_FIRCTCFG_TRIMSRC(pFircConfig->u8TrimSrc) | SCG_FIRCTCFG_TRIMDIV(u16TrimDiv));
                        SCG_HWA_SetFircTcfg(u32TempVal);

                        /* Set TRUP and EN together with TREN setting   */
                        u32TempVal = SCG_HWA_GetFircCsr();
                        u32TempVal |= (uint32_t)(SCG_FIRCCSR_TRUP(true) | SCG_FIRCCSR_TREN(true) );
                        SCG_HWA_SetFircCsr(u32TempVal);

                        /* Wait FIRC trim completion */
                        u32TempVal = IRC_TRIM_STABILIZATION_TIMEOUT;
                        SCG_CheckClockAckStatus((false == SCG_HWA_GetTrimLocked(SCG_FIRC_CLOCK_SYMBOL)), u32TempVal, eStatusVal)
                    }
                    else
                    {
                        /*   Trim disabled, just using IC internal IRC trim value */
                    }
#endif

                    if (eStatusVal == SCG_STATUS_SUCCESS)
                    {
                        if (pFircConfig->bCm)
                        {
                            SCG_HWA_EnableFircClockMonitor();
                        }
                        else
                        {
                            /* Cleared before */
                        }

                        if (pFircConfig->bLock)
                        {
                            /* lock CSR register */
                            SCG_HWA_LockFircCsr();
                        }
                    }

                }
                else
                {
                    /* Clear CSR configuration */
                    SCG_HWA_SetFircCsr(0U);

                    /* Clear DIV configuration*/
                    SCG_HWA_SetFircDiv(0U);
                }
            }
            else
            {
                /* return Error  */
            }
        }

#if SCG_DEV_ERROR_REPORT == STD_ON
    }
#endif

    return eStatusVal;
}

/**
 * @brief Disable FIRC
 *
 * @return SCG_StatusType function status
 */
SCG_StatusType SCG_DisableFIRC(void)
{
    SCG_StatusType eStatusVal = SCG_STATUS_SUCCESS;
    uint32_t u32TempVal;
    uint8_t u8ClkSrc;

    u8ClkSrc = SCG_HWA_GetSysClkSrc();
    if ((uint8_t)SCG_CLOCK_SRC_FIRC == u8ClkSrc)
    {
        eStatusVal = SCG_STATUS_SEQUENCE_ERROR;
    }
    else if ((SCG_HWA_GetPllSrc(SCG_PLL0_CLOCK_SYMBOL) == (uint8_t)SCG_PLLSOURCE_FIRC) && ((uint8_t)SCG_CLOCK_SRC_PLL0 == u8ClkSrc))
    {
        eStatusVal = SCG_STATUS_SEQUENCE_ERROR;
    }
    else
    {
        /* do nothing */
    }

    if (eStatusVal == SCG_STATUS_SUCCESS)
    {
        /* Unlock CSR register */
        SCG_HWA_UnlockFircCsr();

        /* Disable FIRC */
        SCG_HWA_DisableFirc();

        /* Wait FIRC not valid */
        u32TempVal = FIRC_STABILIZATION_TIMEOUT;
        SCG_CheckClockAckStatus((true == SCG_HWA_GetClockValid(SCG_FIRC_CLOCK_SYMBOL)), u32TempVal, eStatusVal)

        if (eStatusVal == SCG_STATUS_SUCCESS)
        {
            /* Clear CSR register */
            SCG_HWA_SetFircCsr(0U);

            /* In order to avoid the DIV register value not cleared, Clear FIRC DIV register twice */
            SCG_HWA_SetFircDiv(0U);
            SCG_HWA_SetFircDiv(0U);
        }
    }
    return eStatusVal;
}


/**
 * @brief Enable PLL
 *
 * @param ePLL PLL instance
 * @param pPllConfig PLL configuration
 * @return SCG_StatusType function status
 */
SCG_StatusType SCG_EnablePLL(const SCG_PllClkType ePll, const SCG_PllType *const pPllConfig)
{
    SCG_StatusType eStatusVal = SCG_STATUS_PARAM_ERROR;

#if SCG_DEV_ERROR_REPORT == STD_ON
    if (NULL_PTR == pPllConfig)
    {
        SCG_ReportDevError(SCG_ENABLE_PLL_ID, SCG_E_PARAM_POINTER);
    }
    else
    {
#endif

        if ((true != SCG_HWA_GetClockValid(SCG_FOSC_CLOCK_SYMBOL)) && (SCG_PLLSOURCE_FOSC == pPllConfig->eSrc))
        {
            eStatusVal = SCG_STATUS_SEQUENCE_ERROR;
        }
        else if ((true != SCG_HWA_GetClockValid(SCG_FIRC_CLOCK_SYMBOL)) && (SCG_PLLSOURCE_FIRC == pPllConfig->eSrc))
        {
            eStatusVal = SCG_STATUS_SEQUENCE_ERROR;
        }
        else
        {
            eStatusVal = SCG_STATUS_SUCCESS;
        }

        if (eStatusVal == SCG_STATUS_SUCCESS)
        {
            if (SCG_PLL0 == ePll)
            {
                eStatusVal = SCG_EnablePLL0(pPllConfig);
            }
#if SCG_PLL1_SUPPORT
            else if (SCG_PLL1 == ePll)
            {
                eStatusVal = SCG_EnablePLL1(pPllConfig);
            }
#endif /* SCG_PLL1_SUPPORT */
            else
            {
                /* do nothing */
            }
        }

#if SCG_DEV_ERROR_REPORT == STD_ON
    }
#endif

    return eStatusVal;
}

/**
 * @brief Disable PLL
 *
 * @param ePll PLL instance
 * @return SCG_StatusType function status
 */
SCG_StatusType SCG_DisablePLL(const SCG_PllClkType ePll)
{
    SCG_StatusType eStatusVal = SCG_STATUS_SUCCESS;

    if (SCG_PLL0 == ePll)
    {
        if (SCG_HWA_GetSysClkSrc() == (uint8_t)SCG_CLOCK_SRC_PLL0)
        {
            eStatusVal = SCG_STATUS_SEQUENCE_ERROR;
        }
        else
        {
            eStatusVal = SCG_DisablePLL0();
        }
    }
#if SCG_PLL1_SUPPORT
    else
    {
        /* (SCG_PLL1 == ePll) */
        eStatusVal = SCG_DisablePLL1();
    }
#endif /* SCG_PLL1_SUPPORT */

    return eStatusVal;
}

/**
 * @brief Switch system clock source
 *
 * @param eClock selected clock source
 * @return SCG_StatusType function status
 *
 * @note: Attention-- if switch Slow clock to fast clock,
 *        divcore,divbus,divslow will be 1,2,4 mandatory to prevent from clock overrun
 */
SCG_StatusType SCG_SwitchSystemClock(const SCG_ClockSrcType eClock)
{
    SCG_StatusType eStatusVal = SCG_STATUS_SUCCESS;
    uint32_t u32TempVal;
    uint32_t u32TempReg;
    uint8_t u8ClkSrc;

#if SCG_DEV_ERROR_REPORT == STD_ON
    if (SCG_CLOCK_SRC_NONE == eClock)
    {
        SCG_ReportDevError(SCG_SWITCH_SYS_CLOCK_ID, SCG_E_PARAM_OUT_RANGE);
    }
    else
    {
#endif

        if ((true != SCG_HWA_GetClockValid(SCG_FOSC_CLOCK_SYMBOL)) && (SCG_CLOCK_SRC_FOSC == eClock))
        {
            eStatusVal = SCG_STATUS_SEQUENCE_ERROR;
        }
        else if ((true != SCG_HWA_GetClockValid(SCG_FIRC_CLOCK_SYMBOL)) && (SCG_CLOCK_SRC_FIRC == eClock))
        {
            eStatusVal = SCG_STATUS_SEQUENCE_ERROR;
        }
        else if ((true != SCG_HWA_GetClockValid(SCG_PLL0_CLOCK_SYMBOL)) && (SCG_CLOCK_SRC_PLL0 == eClock))
        {
            eStatusVal = SCG_STATUS_SEQUENCE_ERROR;
        }
#if SCG_SYSCLK_SEL_SIRC_SUPPORT
        else if ((true != SCG_HWA_GetClockValid(SCG_SIRC_CLOCK_SYMBOL)) && (SCG_CLOCK_SRC_SIRC == eClock))
        {
            eStatusVal = SCG_STATUS_SEQUENCE_ERROR;
        }
#endif
        else
        {
            /* do nothing */
        }

        if (eStatusVal == SCG_STATUS_SUCCESS)
        {
            u8ClkSrc = SCG_HWA_GetSysClkSrc();

            if(u8ClkSrc >= (uint8_t)eClock)
            {
                /* Fast clock to slow clock  */
                SCG_HWA_SetSystemClock((uint8_t)eClock);
            }
            else
            {
                /* Slow clock to fast clock, divider here is not default value */
                u32TempReg = SCG_HWA_GetCCR();
                u32TempReg &= ~(uint32)(SCG_CCR_SCS_MASK|SCG_CCR_DIVCORE_MASK|SCG_CCR_DIVBUS_MASK|SCG_CCR_DIVSLOW_MASK);
                u32TempReg |= (uint32)((uint32)SCG_CCR_SCS(eClock)                |
                                       (uint32)SCG_CCR_DIVCORE(SCG_CLOCK_DIV_BY1) |
                                       (uint32)SCG_CCR_DIVBUS(SCG_CLOCK_DIV_BY2)  |
                                       (uint32)SCG_CCR_DIVSLOW(SCG_CLOCK_DIV_BY4));
                SCG_HWA_SetCCR(u32TempReg);

            }

            u32TempVal = SCG_CLKSRC_STABILIZATION_TIMEOUT;
            while ((SCG_HWA_GetSysClkUPRD() == false) && (u32TempVal > 0U))
            {
                u32TempVal--;
            }

            if ((uint32_t)0U == u32TempVal)
            {
                eStatusVal = SCG_STATUS_TIMEOUT;
            }
            else if(SCG_HWA_GetSysClkSrc() != (uint8_t)eClock)
            {
                eStatusVal = SCG_STATUS_SEQUENCE_ERROR;
            }
            else
            {
                eStatusVal = SCG_STATUS_SUCCESS;
            }
        }

#if SCG_DEV_ERROR_REPORT == STD_ON
    }
#endif

    return eStatusVal;
}

/**
 * @brief Set system run time clock and related CORE/BUS/SLOW clock.
 *
 * @param pSysClkConfig pointer to the clockCtrlType structure data instance,which defined for system clock selection.
 * @return SCG_StatusType function status
 */
SCG_StatusType SCG_SetClkCtrl(const SCG_ClockCtrlType *const pSysClkConfig)
{
    SCG_StatusType eStatusVal = SCG_STATUS_PARAM_ERROR;
    uint32_t u32TempVal, u32Freq = 0U, u32FreqCore, u32FreqBus, u32FreqSlow;
    uint8_t u8ClkSrc;

#if SCG_DEV_ERROR_REPORT == STD_ON
    if (NULL_PTR == pSysClkConfig)
    {
        SCG_ReportDevError(SCG_SET_CLOCK_CTRL_ID, SCG_E_PARAM_POINTER);
    }
    else
    {
#endif

        /* Check configuration */
        if (SCG_CLOCK_SRC_FOSC == pSysClkConfig->eSrc)
        {
            u32Freq = FOSC_FREQUENCY;
        }
        else if (SCG_CLOCK_SRC_FIRC == pSysClkConfig->eSrc)
        {
            u32Freq = FIRC_CLOCK;
        }
        else if (SCG_CLOCK_SRC_PLL0 == pSysClkConfig->eSrc)
        {
            u32Freq = SCG_CalculatePll0Freq(SCG_PLL0_CLK);
        }
#if SCG_SYSCLK_SEL_SIRC_SUPPORT
        else if (SCG_CLOCK_SRC_SIRC == pSysClkConfig->eSrc)
        {
            u32Freq = SIRC_CLOCK;
        }
#endif
        else
        {
            /* do nothing */
        }

        u32FreqCore =  u32Freq / ((uint8_t)pSysClkConfig->eDivCore + 1U);
        u32FreqBus =  u32FreqCore / ((uint8_t)pSysClkConfig->eDivBus + 1U);
        u32FreqSlow =  u32FreqBus / ((uint8_t)pSysClkConfig->eDivSlow + 1U);
        if ((u32FreqCore > SYS_CORE_CLK_MAX) || (u32FreqBus > SYS_BUS_CLK_MAX) || (u32FreqSlow > SYS_SLOW_CLK_MAX))
        {
            eStatusVal = SCG_STATUS_PARAM_ERROR;
        }
        else
        {
            eStatusVal = SCG_STATUS_SUCCESS;
        }

#if SCG_ERRATA_DIVCORE_DIVBUS
        /* ERR_SCG_001 */
        if( (pSysClkConfig->eDivCore) == (pSysClkConfig->eDivBus) )
        {
            if( SCG_CLOCK_DIV_BY1 != (pSysClkConfig->eDivCore) )
            {
                eStatusVal = SCG_STATUS_PARAM_ERROR;
            }
        }
        else
        {
            /* do nothing */
        }
#endif /* SCG_ERRATA_DIVCORE_DIVBUS */

        /* Configure register */
        if (eStatusVal == SCG_STATUS_SUCCESS)
        {
            u8ClkSrc = SCG_HWA_GetSysClkSrc();

            if(u8ClkSrc >= (uint8_t)pSysClkConfig->eSrc)
            {
                /* Fast clock to slow clock, need switch clock source first */
                /* Switch system clock */
                SCG_HWA_SetSystemClock((uint8_t)pSysClkConfig->eSrc);

                /* Wait CCR update ready */
                u32TempVal = SCG_CLKSRC_STABILIZATION_TIMEOUT;
                while ((SCG_HWA_GetSysClkUPRD() == false) && (u32TempVal > 0U))
                {
                    u32TempVal--;
                }

                if ((uint32_t)0U == u32TempVal)
                {
                    eStatusVal = SCG_STATUS_TIMEOUT;
                }
                else if(SCG_HWA_GetSysClkSrc() != (uint8_t)pSysClkConfig->eSrc)
                {
                    eStatusVal = SCG_STATUS_SEQUENCE_ERROR;
                }
                else
                {
                    /* do nothing */
                }
            }
            else
            {
                /* Slow clock to fast clock, set CCR directly */
            }

            if (eStatusVal == SCG_STATUS_SUCCESS)
            {
                /* Configure CCR register to select divider */
                /* ERR_RGM_003 SCG_CCR_SYSCLK_CME will be set enable mandatory. */
                u32TempVal = (uint32_t)((uint32_t)SCG_CCR_SYSCLK_CME(1U) |
                                        (uint32_t)SCG_CCR_SCS(pSysClkConfig->eSrc) |
                                        (uint32_t)SCG_CCR_DIVCORE(pSysClkConfig->eDivCore) |
                                        (uint32_t)SCG_CCR_DIVBUS(pSysClkConfig->eDivBus) |
                                        (uint32_t)SCG_CCR_DIVSLOW(pSysClkConfig->eDivSlow));
                SCG_HWA_SetCCR(u32TempVal);

                /* Wait CCR update ready */
                u32TempVal = SCG_CLKSRC_STABILIZATION_TIMEOUT;
                while ((SCG_HWA_GetSysClkUPRD() == false) && (u32TempVal > 0U))
                {
                    u32TempVal--;
                }

                if ((uint32_t)0U == u32TempVal)
                {
                    eStatusVal = SCG_STATUS_TIMEOUT;
                }
                else if(SCG_HWA_GetSysClkSrc() != (uint8_t)pSysClkConfig->eSrc)
                {
                    eStatusVal = SCG_STATUS_SEQUENCE_ERROR;
                }
                else
                {
                    /* do nothing */
                }
            }
            else
            {
                /* do nothing */
            }
        }

#if SCG_DEV_ERROR_REPORT == STD_ON
    }
#endif

    return eStatusVal;
}

/**
 * @brief Get clock frequency
 *
 * @param eScgClockName Clock source type
 * @return uint32_t frequency value
 */
uint32_t SCG_GetScgClockFreq(const SCG_ClkSrcType eScgClockName)
{
    uint32_t u32Freq = 0U;
#if SCG_DEV_ERROR_REPORT == STD_ON
    if (eScgClockName >= SCG_END_OF_CLOCKS)
    {
        SCG_ReportDevError(SCG_GET_SCG_CLOCK_FREQ_ID, SCG_E_PARAM_POINTER);
    }
    else
    {
#endif

        if ((SCG_CORE_CLK == eScgClockName) ||
            (SCG_BUS_CLK == eScgClockName)  ||
            (SCG_SLOW_CLK == eScgClockName))
        {
            u32Freq = SCG_CalculateSystemFreq(eScgClockName);
        }
        else if ((SCG_SIRC_CLK == eScgClockName)     ||
                 (SCG_SIRCDIVH_CLK == eScgClockName) ||
                 (SCG_SIRCDIVM_CLK == eScgClockName) ||
                 (SCG_SIRCDIVL_CLK == eScgClockName))
        {
            u32Freq = SCG_CalculateSircFreq(eScgClockName);
        }
        else if ((SCG_FIRC_CLK == eScgClockName)     ||
                 (SCG_FIRCDIVH_CLK == eScgClockName) ||
                 (SCG_FIRCDIVM_CLK == eScgClockName) ||
                 (SCG_FIRCDIVL_CLK == eScgClockName))
        {
            u32Freq = SCG_CalculateFircFreq(eScgClockName);
        }
        else if ((SCG_FOSC_CLK == eScgClockName)     ||
                 (SCG_FOSCDIVH_CLK == eScgClockName) ||
                 (SCG_FOSCDIVM_CLK == eScgClockName) ||
                 (SCG_FOSCDIVL_CLK == eScgClockName))
        {
            u32Freq = SCG_CalculateFoscFreq(eScgClockName);
        }
        else if ((SCG_PLL0_CLK == eScgClockName)     ||
                 (SCG_PLL0DIVH_CLK == eScgClockName) ||
                 (SCG_PLL0DIVM_CLK == eScgClockName) ||
                 (SCG_PLL0DIVL_CLK == eScgClockName))
        {
            u32Freq = SCG_CalculatePll0Freq(eScgClockName);
        }
#if SCG_PLL1_SUPPORT
        else if ((SCG_PLL1_CLK == eScgClockName)     ||
                 (SCG_PLL1DIVH_CLK == eScgClockName) ||
                 (SCG_PLL1DIVM_CLK == eScgClockName) ||
                 (SCG_PLL1DIVL_CLK == eScgClockName))
        {
            u32Freq = SCG_CalculatePll1Freq(eScgClockName);
        }
#endif /* SCG_PLL1_SUPPORT */
        else if (SCG_SIRC32K_CLK == eScgClockName)
        {
            u32Freq = SIRC32K_CLOCK;
        }
        else if (SCG_SOSC_CLK == eScgClockName)
        {
            u32Freq = SOSC_FREQUENCY;
        }
        else if (SCG_SCG_CLKOUT_CLK == eScgClockName)
        {
            u32Freq = SCG_CalculateClkOutFreq();
        }
        else if (SCG_NVMINIT_CLK == eScgClockName)
        {
            u32Freq = NVM_CLOCK;
        }
        else if (SCG_CMU4REF_CLK == eScgClockName)
        {
            u32Freq = SCG_CalculateCMU4RefFreq();
        }
#if SCG_PLLX_CLK1_SUPPORT
        else if ((SCG_PLL0CLK1_RESERVE0 == eScgClockName) ||
                 (SCG_PLL0CLK1_RESERVE1 == eScgClockName) ||
                 (SCG_PLL0CLK1_RESERVE2 == eScgClockName))
        {
            u32Freq = SCG_CalculatePll0Clk1Freq();
        }
#if SCG_PLL1_SUPPORT
        else if ((SCG_PLL1CLK1_RESERVE0 == eScgClockName) ||
                 (SCG_PLL1CLK1_RESERVE1 == eScgClockName) ||
                 (SCG_PLL1CLK1_RESERVE2 == eScgClockName))
        {
            u32Freq = SCG_CalculatePll1Clk1Freq();
        }
#endif /* SCG_PLL1_SUPPORT */
#endif /* SCG_PLLX_CLK1_SUPPORT */
#if SCG_PLL0_CLK2_SUPPORT
        else if ((SCG_PLL0CLK2_RESERVE0 == eScgClockName) ||
                 (SCG_PLL0CLK2_RESERVE1 == eScgClockName) ||
                 (SCG_PLL0CLK2_RESERVE2 == eScgClockName))
        {
            u32Freq = SCG_CalculatePll0Clk2Freq();
        }
#endif /* SCG_PLL0_CLK2_SUPPORT */
        else
        {
            u32Freq = UNKNOWN_CLOCK;
        }

        if (UNKNOWN_CLOCK == u32Freq)
        {
            u32Freq = 0U;
        }

#if SCG_DEV_ERROR_REPORT == STD_ON
    }
#endif

    return u32Freq;
}

/**
 * @brief Select clock out source
 *
 * @param eClkoutSel clock out source
 */
void SCG_SetClkOut(const SCG_ClockoutSrcType eClkoutSel)
{
#if SCG_DEV_ERROR_REPORT == STD_ON
    if (eClkoutSel > SCG_CLOCKOUT_SRC_SIRC32K)
    {
        SCG_ReportDevError(SCG_SET_CLOCK_OUT_ID, SCG_E_PARAM_OUT_RANGE);
    }
    else
    {
#endif

        SCG_HWA_SetClkOutSel((uint8_t)eClkoutSel);

#if SCG_DEV_ERROR_REPORT == STD_ON
    }
#endif
}

/**
 * @brief Select NVM clock source
 *
 * @param eNvmClkSrc NVM clock source
 * @return uint32_t function status
 */
SCG_StatusType SCG_SetNvmClk(const SCG_NvmClkSrcType eNvmClkSrc)
{
    SCG_StatusType eStatusVal = SCG_STATUS_SUCCESS;

    if ((true != SCG_HWA_GetClockValid(SCG_FIRC_CLOCK_SYMBOL)) && (eNvmClkSrc == SCG_NVMCLK_SRC_FIRC))
    {
        eStatusVal = SCG_STATUS_SEQUENCE_ERROR;
    }

    if (eStatusVal == SCG_STATUS_SUCCESS)
    {
        SCG_HWA_SetNvmClk(((uint32_t)1U << eNvmClkSrc));
    }

    return eStatusVal;
}

/**
 * @brief Select CMU4 clock source
 *
 * @param eCmu4ClkSrc CMU4 clock source
 * @return SCG_StatusType function status
 */
SCG_StatusType SCG_SetCmu4Clk(const SCG_Cmu4ClkSrcType eCmu4ClkSrc)
{
    SCG_StatusType eStatusVal = SCG_STATUS_SUCCESS;

    if ((true != SCG_HWA_GetClockValid(SCG_FOSC_CLOCK_SYMBOL)) && (eCmu4ClkSrc == SCG_CMU4CLK_SRC_FOSC))
    {
        eStatusVal = SCG_STATUS_SEQUENCE_ERROR;
    }

    if (eStatusVal == SCG_STATUS_SUCCESS)
    {
        SCG_HWA_SetCmu4Clk(((uint32_t)1U << eCmu4ClkSrc));
    }
    return eStatusVal;
}

/**
 * @brief Initializes the CRC module based on the specified mode.
 *
 * This function initializes the CRC module by first disabling and clearing any existing CRC-related configurations.
 * It then generates the original CRC value and waits for the CRC calculation to complete. If the operation times out,
 * the function returns a timeout status. If the initialization is successful, it enables the CRC trigger mode (if specified)
 * and enables CRC error output and CRC check.
 *
 * @param eMode The CRC mode to be initialized. Possible values are:
 *              - SCG_CRC_TRIGGER_MODE: Enables CRC trigger mode.
 *
 * @return SCG_StatusType Returns the status of the CRC initialization:
 *         - SCG_STATUS_SUCCESS: CRC initialization was successful.
 *         - SCG_STATUS_TIMEOUT: CRC initialization timed out.
 */
SCG_StatusType SCG_CrcInit(SCG_CrcModeType eMode)
{
    SCG_StatusType eStatusVal = SCG_STATUS_SUCCESS;
    uint32_t u32Timeout = 0xFFFFU;

    /* Deinit CRC register */
    SCG_HWA_DisableCrcCheck();
    SCG_HWA_DisableCrcTrigger();
    SCG_HWA_DisableCrcErrorOutput();
    SCG_HWA_ClearCrcErrorFlag();

    /* Generate original CRC result */
    SCG_HWA_GenCrcVal();
    while (SCG_HWA_GetCrcBusyStatus() == true)
    {
        u32Timeout--;
        if (u32Timeout == 0U)
        {
            eStatusVal = SCG_STATUS_TIMEOUT;
            break;
        }
    }

    if (eStatusVal == SCG_STATUS_SUCCESS)
    {
        if (eMode == SCG_CRC_TRIGGER_MODE)
        {
            SCG_HWA_EnableCrcTrigger();
        }

        /* Generate CRC error output */
        SCG_HWA_EnableCrcErrorOutput();
        /* Generate CRC check */
        SCG_HWA_EnableCrcCheck();
    }
    return eStatusVal;
}

/**
 * @brief Generates a CRC value using the SCG hardware accelerator.
 *
 * This function invokes the hardware accelerator to generate a CRC value.
 * It calls the `SCG_HWA_GenCrcVal()` function, which is responsible for
 * the actual CRC computation.
 *
 * @note This function assumes that the hardware accelerator is properly
 * initialized and configured before being called.
 *
 * @return void
 */
void SCG_CrcGenerate(void)
{
    SCG_HWA_GenCrcVal();
}

/**
 * @brief Clock source De-init
 *
 * @return SCG_StatusType function status
 */
SCG_StatusType SCG_Deinit(void)
{
    SCG_StatusType eStatusVal = SCG_STATUS_SUCCESS;
    SCG_FircType tFircCfg =
    {
        .bLock = false,
        .bCm = false,
        .bTrEn = false,
        .bSten = false,
        .u8TrimSrc = 0U,
        .eDivL = SCG_ASYNCCLOCKDIV_BY4,
        .eDivM = SCG_ASYNCCLOCKDIV_BY2,
        .eDivH = SCG_ASYNCCLOCKDIV_BY1
    };

    if (SCG_HWA_GetSysClkSrc() != (uint8_t)SCG_CLOCK_SRC_FIRC)
    {
        eStatusVal = SCG_SwitchSystemClock(SCG_CLOCK_SRC_FIRC);
        if (SCG_STATUS_SEQUENCE_ERROR == eStatusVal)
        {
            eStatusVal = SCG_EnableFIRC(&tFircCfg);
            if (SCG_STATUS_TIMEOUT != eStatusVal)
            {
                eStatusVal = SCG_SwitchSystemClock(SCG_CLOCK_SRC_FIRC);
            }
        }
    }

    if (SCG_STATUS_SUCCESS == eStatusVal)
    {
        /* Disable all clock source */
#if SCG_PLL1_SUPPORT
        (void)SCG_DisablePLL(SCG_PLL1);
#endif /* SCG_PLL1_SUPPORT */
        (void)SCG_DisablePLL(SCG_PLL0);
        (void)SCG_DisableFOSC();
        (void)SCG_DisableSOSC();
        (void)SCG_DisableSIRC32K();
    }

    return eStatusVal;
}

/**
 * @brief  Set clock error interrupt.
 * @param pScgHandle: Scg handle
 * @param  pIntrStruct: pointer to interrupt configuration,
 */

void SCG_InterruptInit(SCG_HandleType *pScgHandle, const SCG_InterruptType *const pIntrStruct)
{
    uint32_t u32Temp = 0U;
#if SCG_DEV_ERROR_REPORT == STD_ON
    if ((NULL_PTR == pScgHandle) || (NULL_PTR == pIntrStruct))
    {
        SCG_ReportDevError(SCG_SCG_INTERRUPT_INIT_ID, SCG_E_PARAM_POINTER);
    }
    else
    {
#endif

        u32Temp = SCG_HWA_GetFircCsr();
        if ((0U != ((uint32_t)SCG_INTR_MASK_FIRC_CLK_ERR & (pIntrStruct->u32InterruptMask))) &&
            (SCG_FIRCCSR_CM_MASK == (u32Temp & SCG_FIRCCSR_CM_MASK)))
        {
            pScgHandle->pFircClkErrNotify = pIntrStruct->pFircClkErrNotify;
        }

        u32Temp = SCG_HWA_GetFoscCsr();
        if ((0U != ((uint32_t)SCG_INTR_MASK_FOSC_CLK_ERR & (pIntrStruct->u32InterruptMask))) &&
            (SCG_FOSCCSR_CM_MASK == (u32Temp & (SCG_FOSCCSR_CM_MASK | SCG_FOSCCSR_CMRE_MASK))))
        {
            pScgHandle->pFoscClkErrNotify = pIntrStruct->pFoscClkErrNotify;
        }

        u32Temp = SCG_HWA_GetSircCsr();
        if ((0U != ((uint32_t)SCG_INTR_MASK_SIRC_CLK_ERR & (pIntrStruct->u32InterruptMask))) &&
            (SCG_SIRCCSR_CM_MASK == (u32Temp & SCG_SIRCCSR_CM_MASK)))
        {
            pScgHandle->pSircClkErrNotify = pIntrStruct->pSircClkErrNotify;
        }

        u32Temp = SCG_HWA_GetSoscCsr();
        if ((0U != ((uint32_t)SCG_INTR_MASK_SOSC_CLK_ERR & (pIntrStruct->u32InterruptMask))) &&
            (SCG_SOSCCSR_CM_MASK == (u32Temp & (SCG_SOSCCSR_CM_MASK | SCG_SOSCCSR_CMRE_MASK))))
        {
            pScgHandle->pSoscClkErrNotify = pIntrStruct->pSoscClkErrNotify;
        }

        u32Temp = SCG_HWA_GetPll0Csr();
        if ((0U != ((uint32_t)SCG_INTR_MASK_PLL0_CLK_ERR & (pIntrStruct->u32InterruptMask))) &&
            (SCG_PLL0CSR_CM_MASK == (u32Temp & (SCG_PLL0CSR_CM_MASK | SCG_PLL0CSR_CMRE_MASK))))
        {
            pScgHandle->pPll0ClkErrNotify = pIntrStruct->pPll0ClkErrNotify;
        }
#if SCG_PLL1_SUPPORT
        u32Temp = SCG_HWA_GetPll1Csr();
        if ((0U != ((uint32_t)SCG_INTR_MASK_PLL1_CLK_ERR & (pIntrStruct->u32InterruptMask))) &&
            (SCG_PLL1CSR_CM_MASK == (u32Temp & (SCG_PLL1CSR_CM_MASK | SCG_PLL1CSR_CMRE_MASK))))
        {
            pScgHandle->pPll1ClkErrNotify = pIntrStruct->pPll1ClkErrNotify;
        }
#endif /* SCG_PLL1_SUPPORT */
#if SCG_DEV_ERROR_REPORT == STD_ON
    }
#endif
}

/**
 * \brief Clock error interrupt handler
 * \param pScgHandle: Scg handle
 */

void SCG_UserIRQHandler(SCG_HandleType *pScgHandle)
{
    if ((true == SCG_HWA_CheckAndClearFircClkErr()) && (NULL_PTR != pScgHandle->pFircClkErrNotify))
    {
        pScgHandle->pFircClkErrNotify(pScgHandle);
    }

    if ((true == SCG_HWA_CheckAndClearSircClkErr()) && (NULL_PTR != pScgHandle->pSircClkErrNotify))
    {
        pScgHandle->pSircClkErrNotify(pScgHandle);
    }

    if ((true == SCG_HWA_CheckAndClearFoscClkErr()) && (NULL_PTR != pScgHandle->pFoscClkErrNotify))
    {
        pScgHandle->pFoscClkErrNotify(pScgHandle);
    }

    if ((true == SCG_HWA_CheckAndClearSoscClkErr()) && (NULL_PTR != pScgHandle->pSoscClkErrNotify))
    {
        pScgHandle->pSoscClkErrNotify(pScgHandle);
    }

    if ((true == SCG_HWA_CheckAndClearPll0ClkErr()) && (NULL_PTR != pScgHandle->pPll0ClkErrNotify))
    {
        pScgHandle->pPll0ClkErrNotify(pScgHandle);
    }
#if SCG_PLL1_SUPPORT
    if ((true == SCG_HWA_CheckAndClearPll1ClkErr()) && (NULL_PTR != pScgHandle->pPll1ClkErrNotify))
    {
        pScgHandle->pPll1ClkErrNotify(pScgHandle);
    }
#endif /* SCG_PLL1_SUPPORT */
}

#endif /* #if SCG_INSTANCE_COUNT > 0U */
