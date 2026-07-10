/**
 * @file module_driver_pcc.c
 * @author Flagchip
 * @brief PCC driver type definition and API
 * @version 2.0.0
 * @date 2024-08-20
 *
 * SDK Version: 2.6.0
 *

 * @copyright Copyright (c) 2024 Flagchip Semiconductors Co., Ltd.
 *
 */

/********************************************************************************
*   Revision History:
*
*   Version     Date          Initials       CR#          Descriptions
*   ---------   ----------    ------------   ----------   ---------------
*   2.0.0       2024-08-30    Flagchip055    N/A          Update file structures
********************************************************************************/

#include "module_driver_pcc.h"

#if PCC_INSTANCE_COUNT > 0U

#include "module_driver_scg.h"


/***************** mcaro *********************/
#ifndef PCC_DEV_ERROR_REPORT
#define PCC_DEV_ERROR_REPORT	STD_OFF
#endif

#if PCC_DEV_ERROR_REPORT == STD_ON
#define PCC_ReportDevError(func, error) ReportDevError(PCC_MODULE_ID, func, error)
#endif


/***************** Type define *********************/
/**
 * @brief PCC clock attribution.
 * @param u32RegOffset: the register offset base on PCC module base address 0x4002_4000h
 * @param u8ClockProperty include clock domain and clock MUX information by bit filed setting.
 */
typedef struct
{
    uint32_t u32RegOffset;
    uint32_t u32ClockProperty;
} PCC_ClockMapType;

/**
 * @brief PCC peripheral clock index map to SCG clock source
 * @param ePccClkIndex: PCC peripheral clock index
 * @param eScgClkIndex SCG clock source
 */
typedef struct
{
    PCC_ClkGateSrcType ePccClkIndex;
    SCG_ClkSrcType eScgClkIndex;
} PCC_ClockIndexMap;

/***************** Local Variables *********************/
/**
 * @brief PCC clock index to SCG clock source map.
*/
static const PCC_ClockIndexMap s_tPccClocIndexkMap[PCC_MUX_MAX_NUMBER] = {
    {PCC_CLKGATE_SRC_OFF, SCG_END_OF_CLOCKS},

    {PCC_CLKGATE_SRC_FOSCDIV, SCG_FOSCDIVH_CLK},

    {PCC_CLKGATE_SRC_SIRCDIV, SCG_SIRCDIVH_CLK},

    {PCC_CLKGATE_SRC_FIRCDIV, SCG_FIRCDIVH_CLK},

#if PCC_PLLX_CLK1_SUPPORT
#if PCC_PLLX_CLK2_SUPPORT
    {PCC_CLKGATE_SRC_PLL0CLK2, SCG_PLL0CLK2_RESERVE0},
#else
    {PCC_CLKGATE_SRC_PLL1CLK1, SCG_PLL1CLK1_RESERVE0},
#endif /* PCC_PLLX_CLK2_SUPPORT */
#else
    {PCC_CLKGATE_SRC_RESERVE0, SCG_END_OF_CLOCKS},
#endif /* PCC_PLLX_CLK1_SUPPORT */

#if PCC_PLL1_CLK_SUPPORT
    {PCC_CLKGATE_SRC_PLL1DIV, SCG_PLL1DIVH_CLK},
#else
    {PCC_CLKGATE_SRC_RESERVE1, SCG_END_OF_CLOCKS},
#endif /* PCC_PLL1_CLK_SUPPORT */

    {PCC_CLKGATE_SRC_PLL0DIV, SCG_PLL0DIVH_CLK},

#if PCC_PLLX_CLK1_SUPPORT
    {PCC_CLKGATE_SRC_PLL0CLK1, SCG_PLL0CLK1_RESERVE0}
#else
    {PCC_CLKGATE_SRC_RESERVE2, SCG_END_OF_CLOCKS}
#endif

};


/**
 * @brief clock attribution map.
 */
static const PCC_ClockMapType s_tPccClockMap[PCC_END_OF_CLOCKS] = PCC_CLOCK_MAP_INFO

/***************** Local Prototype Functions *********************/

/***************** Local Functions *********************/

/***************** Global Functions *********************/

/**
 * @brief get PCC function clock status and value.
 *
 * @param pcc_ClkSrcType eClockName: used for choose PCC clock source to query.
 */
uint32_t PCC_GetPccFunctionClock(const PCC_ClkSrcType eClockName)
{
    uint8_t u8DivVal;
    PCC_ClkGateSrcType eSelVal;
    uint32_t u32ScgClkIndex = 0U;
    uint32_t u32FunctionFreqVal = 0U;
    uint32_t u32RegVal;
    uint32_t u32ScgClkDivIndex;
    const PCC_ClockMapType *pAttributeVal;

#if PCC_DEV_ERROR_REPORT == STD_ON
    if (eClockName >= PCC_END_OF_CLOCKS)
    {
        PCC_ReportDevError(PCC_GET_PCC_FUNCTION_CLOCK_ID, PCC_E_PARAM_OUT_RANGE);
    }
    else
    {
#endif

        /* Get peripheral PCC register value */
        u32RegVal = *((volatile uint32_t *)(PCC_BASE + s_tPccClockMap[eClockName].u32RegOffset));
        pAttributeVal = &s_tPccClockMap[eClockName];
        /* Check peripheral PCC is valid or not and peripheral have function clock or not */
        if ((PCC_CGC_MASK == (u32RegVal & PCC_CGC_MASK)) && (0U != (pAttributeVal->u32ClockProperty & PCC_PROPERTY_MUXDIV_ALL_MASK)))
        {
            eSelVal = (PCC_ClkGateSrcType)((uint8_t)PCC_GetSEL(u32RegVal));
            /* Get PCC divide value */
            if (PCC_MOUDULE_DIV_USED == (pAttributeVal->u32ClockProperty & PCC_MOUDULE_DIV_USED))
            {
                u8DivVal = (uint8_t)(PCC_GetDIV(u32RegVal) + (uint8_t)1U);
            }
            else
            {
                u8DivVal = 1U;
            }

            /* Get peripheral function clock source which is from SCG or TCLK */
            if (PCC_CLKGATE_SRC_OFF == eSelVal)
            {
                if (PCC_FUNCCLK_MUXDIVHPIN_USED == (pAttributeVal->u32ClockProperty & PCC_FUNCCLK_MUXDIVHPIN_USED))
                {
                    u32FunctionFreqVal = PCC_FTU_TCLK_FREQ;
                }
                else
                {
                    u32FunctionFreqVal = 0U;
                }
            }
            else
            {
                if (PCC_FUNCCLK_MUXDIVH_USED == (pAttributeVal->u32ClockProperty & PCC_FUNCCLK_MUXDIVH_USED))
                {
                    u32ScgClkDivIndex = 0U;
                }
                else if (PCC_FUNCCLK_MUXDIVM_USED == (pAttributeVal->u32ClockProperty & PCC_FUNCCLK_MUXDIVM_USED))
                {
                    u32ScgClkDivIndex = 1U;
                }
                else if (PCC_FUNCCLK_MUXDIVL_USED == (pAttributeVal->u32ClockProperty & PCC_FUNCCLK_MUXDIVL_USED))
                {
                    u32ScgClkDivIndex = 2U;
                }
                else
                {
                    u32ScgClkDivIndex = 0U;
                }
                u32ScgClkIndex = (uint32_t)s_tPccClocIndexkMap[eSelVal].eScgClkIndex + u32ScgClkDivIndex;
            }

            /* If clock source is valid, calculate peripheral function clock */
            if ((uint32_t)SCG_END_OF_CLOCKS != u32ScgClkIndex)
            {
                u32FunctionFreqVal = SCG_GetScgClockFreq((SCG_ClkSrcType)u32ScgClkIndex) / u8DivVal;
            }
        }
        else
        {
            u32FunctionFreqVal = 0U;
        }

#if PCC_DEV_ERROR_REPORT == STD_ON
    }
#endif

    return u32FunctionFreqVal;
}

/**
 * @brief get PCC interface clock status and value.
 *
 * @param pcc_ClkSrcType eClockName: used for choose PCC clock source to query.
 */
uint32_t PCC_GetPccInterfaceClock(const PCC_ClkSrcType eClockName)
{
    uint32_t u32InterfaceFreqVal = 0U;
    uint32_t u32AttributeVal = 0U;

#if PCC_DEV_ERROR_REPORT == STD_ON
    if (eClockName > PCC_END_OF_CLOCKS)
    {
        PCC_ReportDevError(PCC_GET_PCC_INTERFACE_CLOCK_ID, PCC_E_PARAM_OUT_RANGE);
    }
    else
    {
#endif

        u32AttributeVal = s_tPccClockMap[eClockName].u32ClockProperty;
        if (PCC_CLK_DOMAIN_BUS == (u32AttributeVal & PCC_CLK_DOMAIN_BUS))
        {
            u32InterfaceFreqVal = SCG_GetScgClockFreq(SCG_BUS_CLK);
        }
        else if (PCC_CLK_DOMAIN_SLOW == (u32AttributeVal & PCC_CLK_DOMAIN_SLOW))
        {
            u32InterfaceFreqVal = SCG_GetScgClockFreq(SCG_SLOW_CLK);
        }
        else
        {
            u32InterfaceFreqVal = 0U;
        }

#if PCC_DEV_ERROR_REPORT == STD_ON
    }
#endif

    return u32InterfaceFreqVal;
}


/**
 * @brief set PCC one peripheral clock configuration.
 *
 * @param PCC_CtrlType* pConfig: the PCC initialize value point set by user.
 * @return PCC_StatusType pcc function status
 */
PCC_StatusType PCC_SetPcc(const PCC_CtrlType *const pConfig)
{
    PCC_StatusType eStatus = PCC_STATUS_SUCCESS;
    uint8_t u8DivVal;
    uint32_t u32ScgClkIndex = 0U;
    uint32_t u32FreqVal = 0U;
    uint32_t u32FunctionFreqVal = 0U;
    uint32_t u32RegVal = 0U;
    uint32_t u32ScgClkDivIndex;
    uint32_t u32ExceptRegVal;
    const PCC_ClockMapType *pAttributeVal;

#if PCC_DEV_ERROR_REPORT == STD_ON
    if (NULL == pConfig)
    {
        PCC_ReportDevError(PCC_SET_PCC_ID, PCC_E_PARAM_POINTER);
    }
    else
    {
#endif

        pAttributeVal = &s_tPccClockMap[pConfig->eClockName];
        /* check peripheral clock domain to calculate module clock */
        if (PCC_CLK_DOMAIN_BUS == (pAttributeVal->u32ClockProperty & PCC_CLK_DOMAIN_BUS))
        {
            u32FreqVal = SCG_GetScgClockFreq(SCG_BUS_CLK);
        }
        else if (PCC_CLK_DOMAIN_SLOW == (pAttributeVal->u32ClockProperty & PCC_CLK_DOMAIN_SLOW))
        {
            u32FreqVal = SCG_GetScgClockFreq(SCG_SLOW_CLK);
        }
        else
        {
            /* Do nothing */
        }

        if (0U == u32FreqVal)
        {
            /* Please call SCG function first */
            eStatus = PCC_STATUS_CLOCK_INVALID;
        }

        if (PCC_STATUS_SUCCESS == eStatus)
        {
            /* Disable PCC gate and Unlock PCC protection */
            *((volatile uint32_t *)(PCC_BASE + pAttributeVal->u32RegOffset)) &= ~(uint32_t)(PCC_CGC_MASK | PCC_DWPLK_MASK);

            if (pConfig->bEn)
            {
                if (PCC_MOUDULE_DIV_USED == (pAttributeVal->u32ClockProperty & PCC_MOUDULE_DIV_USED))
                {
                    u8DivVal = (uint8_t)(pConfig->eDivider + (uint8_t)1U);
                    u32RegVal |= PCC_DIV(pConfig->eDivider);
                }
                else
                {
                    u8DivVal = 1U;
                }

                if (0U != (pAttributeVal->u32ClockProperty & PCC_PROPERTY_MUXDIV_ALL_MASK))
                {
                    u32RegVal |= PCC_SEL(pConfig->eClkSrc);
                }

#if PCC_DWP_SUPPORT
                if (PCC_DWP_SWR_AVAILABLE == (pAttributeVal->u32ClockProperty & PCC_DWP_SWR_AVAILABLE))
                {
                    u32RegVal |= PCC_DWP(pConfig->eCtrlOwner);
                }
#endif

                if (PCC_CGC_AVAILABLE == (pAttributeVal->u32ClockProperty & PCC_CGC_AVAILABLE))
                {
                    /* Enable peripheral clock */
                    u32RegVal |= PCC_CGC_MASK;
                }

                /* Configure PCC register */
                *((volatile uint32_t *)(PCC_BASE + pAttributeVal->u32RegOffset)) = u32RegVal;

#if PCC_DWPLK_SUPPORT
                /* Configure DWPLK */
                if (pConfig->bLockCtrl)
                {
                    u32RegVal |= PCC_DWPLK_MASK;

                    /* DWPLK need to be set after DWP */
                    *((volatile uint32_t *)(PCC_BASE + pAttributeVal->u32RegOffset)) = u32RegVal;
                }
#endif

                /* Get peripheral function clock source which is from SCG or TCLK */
                if (PCC_CLKGATE_SRC_OFF == pConfig->eClkSrc)
                {
                    if (PCC_FUNCCLK_MUXDIVHPIN_USED == (pAttributeVal->u32ClockProperty & PCC_FUNCCLK_MUXDIVHPIN_USED))
                    {
                        u32FunctionFreqVal = PCC_FTU_TCLK_FREQ;
                    }
                    else
                    {
                        u32FunctionFreqVal = 0U;
                        u8DivVal = 0U;
                    }
                }
                else
                {
                    if (PCC_FUNCCLK_MUXDIVH_USED == (pAttributeVal->u32ClockProperty & PCC_FUNCCLK_MUXDIVH_USED))
                    {
                        u32ScgClkDivIndex = 0U;
                    }
                    else if (PCC_FUNCCLK_MUXDIVM_USED == (pAttributeVal->u32ClockProperty & PCC_FUNCCLK_MUXDIVM_USED))
                    {
                        u32ScgClkDivIndex = 1U;
                    }
                    else if (PCC_FUNCCLK_MUXDIVL_USED == (pAttributeVal->u32ClockProperty & PCC_FUNCCLK_MUXDIVL_USED))
                    {
                        u32ScgClkDivIndex = 2U;
                    }
                    else
                    {
                        u32ScgClkDivIndex = 0U;
                    }
                    u32ScgClkIndex = (uint32_t)s_tPccClocIndexkMap[pConfig->eClkSrc].eScgClkIndex + u32ScgClkDivIndex;
                }

                /* Calculate peripheral function clock */
                if (((uint32_t)SCG_END_OF_CLOCKS != u32ScgClkIndex) && (0U != u8DivVal))
                {
                    u32FunctionFreqVal = SCG_GetScgClockFreq((SCG_ClkSrcType)u32ScgClkIndex) / u8DivVal;
                }
                u32ExceptRegVal = u32RegVal;
            }
            else
            {
                /* Clear PCC register */
                *((volatile uint32_t *)(PCC_BASE + pAttributeVal->u32RegOffset)) = 0U;
                u32ExceptRegVal = 0U;
                u32FunctionFreqVal = 0U;
            }

            /* Check PCC register has been configured, If current CPU do not have permission to configure the PCC register, the except value
             * will not match the actual value */
            if (u32ExceptRegVal != *((volatile uint32_t *)(PCC_BASE + pAttributeVal->u32RegOffset)))
            {
                /* In this case, current core does not have permission to control the register */
                eStatus = PCC_STATUS_CONFIGURED_NOT_SUPPORT;
            }
            else if (u32FunctionFreqVal > PCC_FUNCTION_CLOCK_MAX)
            {
                /* In this case, current function clock too high, must configured below 150M */
                eStatus = PCC_STATUS_CONFIGURED_NOT_SUPPORT;
            }
            else
            {
                /* do nothing */
            }
        }

#if PCC_DEV_ERROR_REPORT == STD_ON
    }
#endif

    return eStatus;
}

/**
 * @brief Generate peripheral reset
 *
 */
void PCC_GenPeripheralReset(const PCC_ClkSrcType eClockName)
{
    /* Close CGC */
    *((volatile uint32_t *)(PCC_BASE + s_tPccClockMap[eClockName].u32RegOffset)) &= ~(uint32_t)PCC_CGC_MASK;

    *((volatile uint32_t *)(PCC_BASE + s_tPccClockMap[eClockName].u32RegOffset)) |= (uint32_t)PCC_SWR_MASK;
    *((volatile uint32_t *)(PCC_BASE + s_tPccClockMap[eClockName].u32RegOffset)) &= ~(uint32_t)PCC_SWR_MASK;
}

#endif /* #if PCC_INSTANCE_COUNT > 0U */
