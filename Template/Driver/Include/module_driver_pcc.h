/**
 * @file module_driver_pcc.h
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
/* ********************************************************************************
   *   Revision History:
   *
   *   Version     Date          Initials      CR#          Descriptions
   *   ---------   ----------    ------------  ----------   ---------------
   *   0.1.0       2023-12-15    Flagchip055   N/A          First version for FC7300
   *   2.0.0       2024-10-12    Flagchip055   N/A          Change version and release
   ******************************************************************************** */
#ifndef _DRIVER_MODULE_DRIVER_PCC_H_
#define _DRIVER_MODULE_DRIVER_PCC_H_

#include "device_header.h"

#if PCC_INSTANCE_COUNT > 0U

/**
 * @addtogroup module_driver_pcc
 * @{
 */

/**
 * @name  PCC API Service IDs
 *
 * @{
 */
#define PCC_SET_PCC_ID                  0x00U
#define PCC_GET_PCC_INTERFACE_CLOCK_ID  0x01U
#define PCC_GET_PCC_FUNCTION_CLOCK_ID   0x02U

/** @}*/

/**
 * @name  PCC Dev Error Code
 * @brief Error Code of calling PCC apis
 *
 * @{
 */
#define PCC_E_PARAM_POINTER   			0x01U
#define PCC_E_PARAM_OUT_RANGE  			0x02U
/** @}*/

/** @brief Marco for PCCn Bit Field definition */

#define PCC_DWPLK_MASK                      0x80000000u
#define PCC_DWPLK_SHIFT                     31u
#define PCC_DWPLK_WIDTH                     1u
#define PCC_DWP_MASK                        0x70000000u
#define PCC_DWP_SHIFT                       28u
#define PCC_DWP_WIDTH                       3u
#define PCC_DWP(x)                          (((uint32_t)(((uint32_t)(x))<<PCC_DWP_SHIFT))&PCC_DWP_MASK)
#define PCC_CGC_MASK                        0x800000U
#define PCC_CGC_SHIFT                       23U
#define PCC_CGC_WIDTH                       1U
#define PCC_CGC(x)                          (((uint32_t)(((uint32_t)(x))<<PCC_CGC_SHIFT))&PCC_CGC_MASK)
#define PCC_SEL_MASK                        0x700000U
#define PCC_SEL_SHIFT                       20U
#define PCC_SEL_WIDTH                       3U
#define PCC_SEL(x)                          (((uint32_t)(((uint32_t)(x))<<PCC_SEL_SHIFT))&PCC_SEL_MASK)
#define PCC_GetSEL(x)                       ((((uint32_t)(x))&PCC_SEL_MASK)>>PCC_SEL_SHIFT)
#define PCC_DIV_MASK                        0x7U
#define PCC_DIV_SHIFT                       0U
#define PCC_DIV_WIDTH                       3U
#define PCC_DIV(x)                          (((uint32_t)(((uint32_t)(x))<<PCC_DIV_SHIFT))&PCC_DIV_MASK)
#define PCC_GetDIV(x)                       ((((uint32_t)(x))&PCC_DIV_MASK)>>PCC_DIV_SHIFT)
#define PCC_SWR_MASK                        0x10000u

#define PCC_MUX_MAX_NUMBER                  8U

/**
 * @brief Pcc clock status
*/
typedef enum
{
    PCC_STATUS_SUCCESS = 0U,
    PCC_STATUS_CLOCK_INVALID = 1U,
    PCC_STATUS_CONFIGURED_NOT_SUPPORT = 1U,
} PCC_StatusType;

/**
 * @brief defined the clock source for function clock,match with PCC_XXX[SEL] bit filed.
 */
typedef enum
{
    PCC_CLKGATE_SRC_OFF        = 0U,

    PCC_CLKGATE_SRC_FOSCDIV    = 1U,

    PCC_CLKGATE_SRC_SIRCDIV    = 2U,

    PCC_CLKGATE_SRC_FIRCDIV    = 3U,

#if PCC_PLLX_CLK1_SUPPORT
#if PCC_PLLX_CLK2_SUPPORT
    PCC_CLKGATE_SRC_PLL0CLK2   = 4U,
#else
    PCC_CLKGATE_SRC_PLL1CLK1   = 4U,
#endif /* PCC_PLLX_CLK2_SUPPORT */
#else
    PCC_CLKGATE_SRC_RESERVE0   = 4U,
#endif /* PCC_PLLX_CLK1_SUPPORT */

#if PCC_PLL1_CLK_SUPPORT
    PCC_CLKGATE_SRC_PLL1DIV    = 5U,
#else
    PCC_CLKGATE_SRC_RESERVE1   = 5U,
#endif /* PCC_PLL1_CLK_SUPPORT */

    PCC_CLKGATE_SRC_PLL0DIV    = 6U,

#if PCC_PLLX_CLK1_SUPPORT
    PCC_CLKGATE_SRC_PLL0CLK1   = 7U
#else
    PCC_CLKGATE_SRC_RESERVE2   = 7U
#endif
} PCC_ClkGateSrcType;

/**
 * @brief define the clock divider,match with PCC_XXX[DIV] bit filed.
 */
typedef enum
{
    PCC_CLK_DIV_BY1     = 0U,             /*!< Divide by 1 (pass-through, no clock divide) */
    PCC_CLK_DIV_BY2     = 1U,             /*!< Divide by 2 */
    PCC_CLK_DIV_BY3     = 2U,             /*!< Divide by 3 */
    PCC_CLK_DIV_BY4     = 3U,             /*!< Divide by 4 */
    PCC_CLK_DIV_BY5     = 4U,             /*!< Divide by 5 */
    PCC_CLK_DIV_BY6     = 5U,             /*!< Divide by 6 */
    PCC_CLK_DIV_BY7     = 6U,             /*!< Divide by 7 */
    PCC_CLK_DIV_BY8     = 7U,              /*!< Divide by 8 */
    PCC_CLK_UNINVOLVED  = 8U              /*!< Current peripheral dose not contain DIV configuration */
} PCC_ClkDivType;

/**
 * @brief Indicate which CPU can control PCC
 */
typedef enum
{
    PCC_CTRL_BY_ALL = 0U,    /*!< All CPUs are allowed to write this peripheral */
    PCC_CTRL_BY_CPU0 = 1U,   /*!< Only CPU0 is allowed to control this peripheral */
    PCC_CTRL_BY_CPU1 = 2U,   /*!< Only CPU1 is allowed to control this peripheral */
    PCC_CTRL_BY_CPU2 = 3U,   /*!< Only CPU2 is allowed to control this peripheral */
    PCC_CTRL_BY_NONE = 7U,   /*!<None CPU is allowed to control this peripheral */
} PCC_CtrlOwnerType;

/**
 * @brief define the PCC module initialization structure.
 */
typedef struct
{
    PCC_ClkSrcType eClockName;          /*!< Peripheral clock */
    bool bEn;                           /*!< Peripheral clock enable or disable */
    PCC_ClkGateSrcType eClkSrc;         /*!< Peripheral function clock source select */
    PCC_ClkDivType eDivider;            /*!< Peripheral clock divider value */
#if PCC_DWP_SUPPORT
    PCC_CtrlOwnerType eCtrlOwner;       /*!< Peripheral control by which CPI */
#endif
#if PCC_DWPLK_SUPPORT
    bool bLockCtrl;                     /*!< Peripheral control setting locked or not which configured by eCtrlOwner */
#endif
} PCC_CtrlType;

/**
 * @brief get PCC function clock status and value.
 *
 * @param pcc_ClkSrcType eClockName: used for choose PCC clock source to query.
 * @return uint32_t Pcc function clock frequency, if PCC is not enable or do not have clock mux configuration,
 *                  the function will return 0
 */
uint32_t PCC_GetPccFunctionClock(const PCC_ClkSrcType eClockName);

/**
 * @brief get PCC interface clock status and value.
 *
 * @param pcc_ClkSrcType eClockName: used for choose PCC clock source to query.
 */
uint32_t PCC_GetPccInterfaceClock(const PCC_ClkSrcType eClockName);

/**
 * @brief set PCC one peripheral clock configuration.
 *
 * @param PCC_CtrlType* pConfig: the PCC initialize value point set by user.
 * @return PCC_StatusType pcc function status
 */
PCC_StatusType PCC_SetPcc(const PCC_CtrlType *const pConfig);

/**
 * @brief Generate peripheral reset
 *
 */
void PCC_GenPeripheralReset(const PCC_ClkSrcType eClockName);


/** @}*/ /* module_driver_pcc */

#endif /* #if PCC_INSTANCE_COUNT > 0U */

#endif
