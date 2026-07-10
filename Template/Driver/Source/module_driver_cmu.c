/**
 * @file        module_driver_cmu.c
 * @author      Flagchip0100
 * @brief       CMU Module driver type definition and API
 * @version 2.0.0
 * @date 2024-08-20
 *
 * SDK Version: 2.6.0
 *

 * @copyright   Copyright 2020-2024 Flagchip Semiconductors Co., Ltd.
 */

/********************************************************************************
 *   Revision History:
 *
 *   Version     Date          Initials       CR#          Descriptions
 *   ---------   ----------    ------------   ----------   ---------------
 *   0.1.0       2022-12-12    Flagchip084    N/A          FC7xxx release version
 *   0.2.0       2023-02-13    Flagchip084    N/A          FC7xxx release version
 *   2.0.0       2024-08-01    Flagchip0100   N/A          SDK2.0 release version
 ********************************************************************************/

#include "module_driver_cmu.h"
#include "module_driver_scg.h"

#if (CMU_INSTANCE_COUNT > 0U)

/*******************************************************************************
 * Definitions
 ******************************************************************************/

#ifndef CMU_DEV_ERROR_REPORT
#define CMU_DEV_ERROR_REPORT            STD_OFF
#endif

#if CMU_DEV_ERROR_REPORT == STD_ON
#define CMU_ReportDevError(func, error)     ReportDevError(CMU_MODULE_ID, func, error)
#endif

#define CMU_MULTIPLY_FACTOR             100U
#define CMU_PERCENT_FACTOR              100U
#define CMU_DIVID_FACTOR_1K             1000U

/*******************************************************************************
 * Prototypes
 ******************************************************************************/


/*******************************************************************************
 * Variables
 ******************************************************************************/

static CMU_Type *const s_apCmuBase[CMU_INSTANCE_COUNT] = CMU_BASE_PTRS;

/*******************************************************************************
 * Code
 ******************************************************************************/
/**
 * @brief Initializes a CMU configuration structure with default values
 *
 * This function configures the provided CMU configuration structure with a set of default settings,
 * including interrupt enable, low-power mode, clock divider, and more. If the passed configuration
 * structure pointer is NULL and error reporting is enabled, an error will be reported.
 *
 * @param pInitCfg Pointer to a CMU_CfgType structure that will be initialized with default configuration values
 *
 * @note The function checks for NULL pointer only if error reporting (`CMU_DEV_ERROR_REPORT`) is turned on.
 *       By default, it sets the structure fields to:
 *       - Interrupt Enable: true
 *       - Low Power Enable: false
 *       - Clock Monitor Enable: false
 *       - Module Enable: true
 *       - Peripheral Monitor Enable: false
 *       - Clock Divider: CMU_REFCLK_NODIV
 *       - Error Callback: NULL
 */
void CMU_GetDefaultConfig(CMU_CfgType *const pInitCfg)
{
#if CMU_DEV_ERROR_REPORT == STD_ON
    if (pInitCfg == NULL)
    {
        CMU_ReportDevError(CMU_GET_DEFAULT_CONFIG_ID, CMU_E_PARAM_NULLPTR);
    }
    else
#endif
    {
        pInitCfg->bIntEnable          = true;
        pInitCfg->bLpen               = false;
        pInitCfg->bSten               = false;
        pInitCfg->bEnable             = true;
        pInitCfg->bPerMonitorEnable   = false;
        pInitCfg->eDiv                = CMU_REFCLK_NODIV;
    }
}

/**
 * @brief Calculates monitor window values for the CMU based on the given configuration
 *
 * This function calculates the reference and monitor clock window values for the specified CMU instance.
 * It verifies input parameters, checks the clock status, and performs necessary calculations.
 * If any input is invalid or an error occurs, appropriate error reporting may be triggered.
 *
 * @param pInitCfg Pointer to a CMU configuration structure with user-defined settings
 *
 * @preconditions
 * - A valid CMU handle and configuration structure must be provided
 * - The CMU instance number should be within the supported range
 *
 * @postconditions
 * - The `pInitCfg` structure will be updated with calculated window and counter values
 * - If the reference or monitor clock is zero, all configuration flags will be set to disabled
 *
 * @note Error reporting is enabled when `CMU_DEV_ERROR_REPORT` is set to `STD_ON`.
 */
void CMU_CaculateMonitorWindowsValue(CMU_CfgType *const pInitCfg)
{
#if CMU_DEV_ERROR_REPORT == STD_ON
    if (pInitCfg == NULL)
    {
        CMU_ReportDevError(CMU_CAL_MONITOR_WINDOW_ID, CMU_E_PARAM_NULLPTR);
    }
    else
#endif
    {
        uint32_t u32RefWindow, u32MaxRefWindow, u32MinRefWindow;
        uint32_t u32MonitorCnts, u32MinMonitorCnts, u32MaxMonitorCnts;
        uint32_t u32RefClk, u32MonitorClk;
        uint32_t u32MaxPeriod;

        /* divide the clock value by 1K_factor */
        u32RefClk = (pInitCfg->u32RefClk >> pInitCfg->eDiv) / CMU_DIVID_FACTOR_1K;
        u32MonitorClk = pInitCfg->u32MonitorClk / CMU_DIVID_FACTOR_1K;

        if ((u32RefClk != 0U) && (u32MonitorClk != 0U))
        {
            if (u32RefClk / u32MonitorClk <= 0x100U)
            {
                u32MaxRefWindow = (0xFFFFFFU - 3U) / u32MonitorClk * u32RefClk / 105U * CMU_PERCENT_FACTOR - 2U;

                if (u32MaxRefWindow > 0xFFFFFFU)
                {
                    u32MaxRefWindow = 0xFFFFFFU;
                }
            }
            else
            {
                u32MaxRefWindow = 0xFFFFFFU;
            }

            u32MinRefWindow = 6U + 5U * u32RefClk / u32MonitorClk;
            u32RefWindow = 100U * u32MinRefWindow;

            if (u32RefWindow > u32MaxRefWindow)
            {
                u32RefWindow = u32MaxRefWindow;
            }

            u32MonitorCnts = u32MonitorClk * (u32RefWindow + 2U) / u32RefClk;
            u32MinMonitorCnts = u32MonitorCnts * 95U / CMU_PERCENT_FACTOR - 3U;
            u32MaxMonitorCnts = u32MonitorCnts * 105U / CMU_PERCENT_FACTOR + 3U;

            /* Program program PERIOD[EN] and PERIOD[WINDOW]. */
            u32MaxPeriod = u32RefClk / u32RefWindow;

            if (u32MaxPeriod >> CMU_PERIOD_WINDOW_WIDTH)
            {
                u32MaxPeriod = ((uint32_t)1U << CMU_PERIOD_WINDOW_WIDTH) - 1U;
            }

            pInitCfg->u32RefWindow        = u32RefWindow;
            pInitCfg->u32PerMonitorWindow = u32MaxPeriod;
            pInitCfg->u32MinMonitorCnts   = u32MinMonitorCnts;
            pInitCfg->u32MaxMonitorCnts   = u32MaxMonitorCnts;
        }
        else
        {
            pInitCfg->bIntEnable          = false;
            pInitCfg->bLpen               = false;
            pInitCfg->bSten               = false;
            pInitCfg->bEnable             = false;
            pInitCfg->bPerMonitorEnable   = false;
            pInitCfg->u32RefWindow        = 0U;
            pInitCfg->u32PerMonitorWindow = 0U;
            pInitCfg->u32MinMonitorCnts   = 0U;
            pInitCfg->u32MaxMonitorCnts   = 0U;
        }
    }
}

/**
 * @brief Initializes the CMU module with the provided configuration
 *
 * This function initializes the Clock Monitor Unit (CMU) according to the specified configuration.
 * It performs parameter validation, initializes hardware registers, and sets up callback functions.
 * If any input is invalid, an error will be reported and the function will return `CMU_STATUS_FAIL`.
 *
 * @param pHandle Pointer to a CMU handle structure containing the instance information
 * @param pInitCfg Pointer to a constant CMU configuration structure with initialization settings
 *
 * @return Status of the initialization process
 *         - CMU_STATUS_SUCCESS: Initialization successful
 *         - CMU_STATUS_FAIL: Initialization failed due to an error or invalid parameter
 *
 * @preconditions
 * - A valid CMU handle and configuration structure must be provided
 * - The CMU instance number should be within the supported range
 *
 * @postconditions
 * - The CMU hardware registers will be configured according to the provided `pInitCfg`
 * - The handle's error callback will be set to the value from `pInitCfg->pErrorCallback`
 *
 * @note Error reporting is enabled when `CMU_DEV_ERROR_REPORT` is set to `STD_ON`.
 */
CMU_StatusType CMU_Init(CMU_HandleType *const pHandle, const CMU_CfgType *const pInitCfg)
{
    CMU_StatusType eStatus = CMU_STATUS_SUCCESS;

#if CMU_DEV_ERROR_REPORT == STD_ON
    if (pHandle == NULL)
    {
        CMU_ReportDevError(CMU_INIT_ID, CMU_E_PARAM_NULLPTR);
        eStatus = CMU_STATUS_FAIL;
    }
    else if (pInitCfg == NULL)
    {
        CMU_ReportDevError(CMU_INIT_ID, CMU_E_PARAM_NULLPTR);
        eStatus = CMU_STATUS_FAIL;
    }
    else if (pHandle->eInstance >= CMU_INSTANCE_COUNT)
    {
        CMU_ReportDevError(CMU_INIT_ID, CMU_E_PARAM_INSTANCE);
        eStatus = CMU_STATUS_FAIL;
    }
    else
#endif
    {
        CMU_Type *const pCmu = s_apCmuBase[pHandle->eInstance];
        uint32_t u32Temp = 0x1FFU;;

        CMU_HWA_SetCtrl(pCmu, 0U);
        CMU_HWA_SoftwareRST(pCmu);
        while (CMU_HWA_GetSoftwareRST(pCmu))
        {
            u32Temp--;
            if (u32Temp == 0U)
            {
                eStatus = CMU_STATUS_FAIL;
                break;
            }
        }
        if (u32Temp != 0U)
        {
            CMU_HWA_SetRefWindow(pCmu, pInitCfg->u32RefWindow);
            CMU_HWA_SetMinCnts(pCmu, pInitCfg->u32MinMonitorCnts);
            CMU_HWA_SetMaxCnts(pCmu, pInitCfg->u32MaxMonitorCnts);
            CMU_HWA_SetPeriodWindow(pCmu, pInitCfg->u32PerMonitorWindow);
            CMU_HWA_SetPeriodEnable(pCmu, pInitCfg->bPerMonitorEnable);

            /* Program DIV,IRQ_EN,LP_EN,STOP_EN,ENABLE */
            u32Temp = CMU_CTRL_REF_DIV(pInitCfg->eDiv) |
                    CMU_CTRL_IRQ_EN(pInitCfg->bIntEnable) |
#ifdef CMU_CTRL_LP_SUPPORT
                    CMU_CTRL_LP_EN(pInitCfg->bLpen) |
#endif
                    CMU_CTRL_STOP_EN(pInitCfg->bSten) |
                    CMU_CTRL_ENABLE(pInitCfg->bEnable);
            CMU_HWA_SetCtrl(pCmu, u32Temp);
        }
    }
    return eStatus;
}

/**
 * @brief Enables the Clock Monitor Unit (CMU) for the specified instance
 *
 * This function enables the CMU module for the given handle's instance. It performs parameter
 * validation and updates the control register to activate the CMU. If an error occurs or the
 * handle is invalid, an error report will be generated.
 *
 * @param pHandle Pointer to a CMU handle structure containing the instance information
 *
 * @preconditions
 * - A valid CMU handle must be provided
 * - The CMU instance number should be within the supported range
 *
 * @postconditions
 * - The CMU will be enabled if it was previously disabled
 *
 * @note Error reporting is enabled when `CMU_DEV_ERROR_REPORT` is set to `STD_ON`.
 */
void CMU_Enable(CMU_HandleType *const pHandle)
{
#if CMU_DEV_ERROR_REPORT == STD_ON
    if (pHandle == NULL)
    {
        CMU_ReportDevError(CMU_ENABLE_ID, CMU_E_PARAM_NULLPTR);
    }
    else if (pHandle->eInstance >= CMU_INSTANCE_COUNT)
    {
        CMU_ReportDevError(CMU_ENABLE_ID, CMU_E_PARAM_INSTANCE);
    }
    else
#endif
    {
        uint32_t u32Temp;
        CMU_Type *const pCmu = s_apCmuBase[pHandle->eInstance];

        u32Temp = CMU_HWA_GetCtrl(pCmu);
        u32Temp |= CMU_CTRL_ENABLE_MASK;
        CMU_HWA_SetCtrl(pCmu, u32Temp);
    }
}

/**
 * @brief Disables the Clock Monitor Unit (CMU) for the specified instance
 *
 * This function disables the CMU module for the given handle's instance. It performs parameter
 * validation, clears the control register flags for enabling and interrupts, and resets the
 * status. If an error occurs or the handle is invalid, an error report will be generated.
 *
 * @param pHandle Pointer to a CMU handle structure containing the instance information
 *
 * @preconditions
 * - A valid CMU handle must be provided
 * - The CMU instance number should be within the supported range
 *
 * @postconditions
 * - The CMU will be disabled if it was previously enabled
 * - Interrupts will be disabled and the status will be cleared
 *
 * @note Error reporting is enabled when `CMU_DEV_ERROR_REPORT` is set to `STD_ON`.
 */
void CMU_Disable(CMU_HandleType *const pHandle)
{
#if CMU_DEV_ERROR_REPORT == STD_ON
    if (pHandle == NULL)
    {
        CMU_ReportDevError(CMU_DISABLE_ID, CMU_E_PARAM_NULLPTR);
    }
    else if (pHandle->eInstance >= CMU_INSTANCE_COUNT)
    {
        CMU_ReportDevError(CMU_DISABLE_ID, CMU_E_PARAM_INSTANCE);
    }
    else
#endif
    {
        uint32_t u32Temp;
        CMU_Type *const pCmu = s_apCmuBase[pHandle->eInstance];

        u32Temp = CMU_HWA_GetCtrl(pCmu);
        u32Temp &= ~(CMU_CTRL_ENABLE_MASK | CMU_CTRL_IRQ_EN_MASK);
        CMU_HWA_SetCtrl(pCmu, u32Temp);
        CMU_HWA_ClsST(pCmu);
    }
}

/**
 * @brief Enables the Clock Monitor Unit (CMU) interrupt for the specified instance
 *
 * This function enables the interrupt for the CMU module associated with the given handle's instance.
 * It performs parameter validation and updates the control register to enable the interrupt.
 * If an error occurs or the handle is invalid, an error report will be generated.
 *
 * @param pHandle Pointer to a CMU handle structure containing the instance information
 *
 * @preconditions
 * - A valid CMU handle must be provided
 * - The CMU instance number should be within the supported range
 *
 * @postconditions
 * - The CMU interrupt will be enabled if it was previously disabled
 *
 * @note Error reporting is enabled when `CMU_DEV_ERROR_REPORT` is set to `STD_ON`.
 */
void CMU_EnableInterrupt(CMU_HandleType *const pHandle)
{
#if CMU_DEV_ERROR_REPORT == STD_ON
    if (pHandle == NULL)
    {
        CMU_ReportDevError(CMU_ENABLE_IRQ_ID, CMU_E_PARAM_NULLPTR);
    }
    else if (pHandle->eInstance >= CMU_INSTANCE_COUNT)
    {
        CMU_ReportDevError(CMU_ENABLE_IRQ_ID, CMU_E_PARAM_INSTANCE);
    }
    else
#endif
    {
        uint32_t u32Temp;
        CMU_Type *const pCmu = s_apCmuBase[pHandle->eInstance];

        u32Temp = CMU_HWA_GetCtrl(pCmu);
        u32Temp |= CMU_CTRL_IRQ_EN_MASK;
        CMU_HWA_SetCtrl(pCmu, u32Temp);
    }
}

/**
 * @brief Disables the Clock Monitor Unit (CMU) interrupt for the specified instance
 *
 * This function disables the interrupt for the CMU module associated with the given handle's instance.
 * It performs parameter validation and updates the control register to disable the interrupt.
 * If an error occurs or the handle is invalid, an error report will be generated.
 *
 * @param pHandle Pointer to a CMU handle structure containing the instance information
 *
 * @preconditions
 * - A valid CMU handle must be provided
 * - The CMU instance number should be within the supported range
 *
 * @postconditions
 * - The CMU interrupt will be disabled if it was previously enabled
 *
 * @note Error reporting is enabled when `CMU_DEV_ERROR_REPORT` is set to `STD_ON`.
 */
void CMU_DisableInterrupt(CMU_HandleType *const pHandle)
{
#if CMU_DEV_ERROR_REPORT == STD_ON
    if (pHandle == NULL)
    {
        CMU_ReportDevError(CMU_DISABLE_IRQ_ID, CMU_E_PARAM_NULLPTR);
    }
    else if (pHandle->eInstance >= CMU_INSTANCE_COUNT)
    {
        CMU_ReportDevError(CMU_DISABLE_IRQ_ID, CMU_E_PARAM_INSTANCE);
    }
    else
#endif
    {
        uint32_t u32Temp;
        CMU_Type *const pCmu = s_apCmuBase[pHandle->eInstance];

        u32Temp = CMU_HWA_GetCtrl(pCmu);
        u32Temp &= ~CMU_CTRL_IRQ_EN_MASK;
        CMU_HWA_SetCtrl(pCmu, u32Temp);
    }
}

/**
 * @brief Enables or disables low power mode on the CMU module.
 *
 * This function configures the CMU module to enter or exit low power mode based on the parameters provided.
 * It supports both standby and stop modes, and can optionally enable low power restart.
 *
 * @param pHandle Pointer to the CMU handle structure.
 * @param eMode The low power mode type to be set (CMU_STANDBY_MODE or CMU_STOP_MODE).
 * @param bModeEnable Boolean flag indicating whether to enable (true) or disable (false) the low power mode.
 * @param bRestartEnable Boolean flag indicating whether to enable (true) or disable (false) low power restart.
 *
 * @note If the handle pointer is NULL or the instance index is out of range, a device error will be reported.
 */
void CMU_LowPowerModeEnable(CMU_HandleType *const pHandle, CMU_LowpowerModeType eMode, bool bModeEnable, bool bRestartEnable)
{
#if CMU_DEV_ERROR_REPORT == STD_ON
    if (pHandle == NULL)
    {
        CMU_ReportDevError(CMU_ENABLE_LOWPOWER_MODE_ID, CMU_E_PARAM_NULLPTR);
    }
    else if (pHandle->eInstance >= CMU_INSTANCE_COUNT)
    {
        CMU_ReportDevError(CMU_ENABLE_LOWPOWER_MODE_ID, CMU_E_PARAM_INSTANCE);
    }
    else
#endif
    {
        CMU_Type *const pCmu = s_apCmuBase[pHandle->eInstance];

        if (eMode == CMU_STANDBY_MODE)
        {
            CMU_HWA_StopModeEnable(pCmu, bModeEnable);
#ifdef CMU_CTRL_LP_SUPPORT
            CMU_HWA_StanbyModeEnable(pCmu, bModeEnable);
#endif
        }
        else if (eMode == CMU_STOP_MODE)
        {
            CMU_HWA_StopModeEnable(pCmu, bModeEnable);
        }
        else
        {

        }
        CMU_HWA_LPRestartEnable(pCmu, bRestartEnable);
    }
}

/**
 * @brief Retrieves the current count from the CMU module.
 *
 * This function returns the current count value from the specified CMU module instance.
 *
 * @param pHandle Pointer to the CMU handle structure.
 *
 * @return uint32_t The current count value from the CMU module.
 *
 * @note If the handle pointer is NULL or the instance index is out of range, a device error will be reported.
 */
uint32_t CMU_GetCount(CMU_HandleType *const pHandle)
{
    uint32_t u32Value = 0U;
#if CMU_DEV_ERROR_REPORT == STD_ON
    if (pHandle == NULL)
    {
        CMU_ReportDevError(CMU_GET_CURRENTCOUNT_ID, CMU_E_PARAM_NULLPTR);
    }
    else if (pHandle->eInstance >= CMU_INSTANCE_COUNT)
    {
        CMU_ReportDevError(CMU_GET_CURRENTCOUNT_ID, CMU_E_PARAM_INSTANCE);
    }
    else
#endif
    {
        CMU_Type *const pCmu = s_apCmuBase[pHandle->eInstance];
        u32Value = CMU_HWA_GetCount(pCmu);
    }

    return u32Value;
}

/**
 * @brief Retrieves the minimum count value from the CMU module.
 *
 * This function returns the minimum count value that the specified CMU module instance can support.
 *
 * @param pHandle Pointer to the CMU handle structure.
 *
 * @return uint32_t The minimum count value supported by the CMU module.
 *
 * @note If the handle pointer is NULL or the instance index is out of range, a device error will be reported.
 */
uint32_t CMU_GetMinCount(CMU_HandleType *const pHandle)
{
    uint32_t u32Value = 0U;
#if CMU_DEV_ERROR_REPORT == STD_ON
    if (pHandle == NULL)
    {
        CMU_ReportDevError(CMU_GET_MINCOUNT_ID, CMU_E_PARAM_NULLPTR);
    }
    else if (pHandle->eInstance >= CMU_INSTANCE_COUNT)
    {
        CMU_ReportDevError(CMU_GET_MINCOUNT_ID, CMU_E_PARAM_INSTANCE);
    }
    else
#endif
    {
        CMU_Type *const pCmu = s_apCmuBase[pHandle->eInstance];
        u32Value = CMU_HWA_GetMinCnts(pCmu);
    }

    return u32Value;
}

/**
 * @brief Retrieves the maximum count value from the CMU module.
 *
 * This function returns the maximum count value that the specified CMU module instance can support.
 *
 * @param pHandle Pointer to the CMU handle structure.
 *
 * @return uint32_t The maximum count value supported by the CMU module.
 *
 * @note If the handle pointer is NULL or the instance index is out of range, a device error will be reported.
 */
uint32_t CMU_GetMaxCount(CMU_HandleType *const pHandle)
{
    uint32_t u32Value = 0U;
#if CMU_DEV_ERROR_REPORT == STD_ON
    if (pHandle == NULL)
    {
        CMU_ReportDevError(CMU_GET_MAXCOUNT_ID, CMU_E_PARAM_NULLPTR);
    }
    else if (pHandle->eInstance >= CMU_INSTANCE_COUNT)
    {
        CMU_ReportDevError(CMU_GET_MAXCOUNT_ID, CMU_E_PARAM_INSTANCE);
    }
    else
#endif
    {
        CMU_Type *const pCmu = s_apCmuBase[pHandle->eInstance];
        u32Value = CMU_HWA_GetMaxCnts(pCmu);
    }

    return u32Value;
}

/**
 * @brief Sets the reference clock source for CMU4.
 *
 * This function configures the CMU4 reference clock source to either the Fast Oscillator Clock (FOSC) or the Slow Internal RC Oscillator Clock (SIRC).
 *
 * @param eSrc The CMU4 clock source type (CMU_CMU4_REF_CLK_FOSC or CMU_CMU4_REF_CLK_SIRC).
 *
 * @note The function clears the current CMU4 clock setting before applying the new source.
 */
void CMU_SetCmu4RefSrc(CMU_Cmu4ClkSrcType eSrc)
{
    uint32_t u32Cmu4ClkMask;

    SCG_HWA_SetCmu4Clk(0U);

    if (CMU_CMU4_REF_CLK_FOSC == eSrc)
    {
        u32Cmu4ClkMask = SCG_CLKOUTCFG_CMU4CLK_FOSC(1U);
        SCG_HWA_SetCmu4Clk(u32Cmu4ClkMask);
    }
    else if (CMU_CMU4_REF_CLK_SIRC == eSrc)
    {
        u32Cmu4ClkMask = SCG_CLKOUTCFG_CMU4CLK_SIRC(1U);
        SCG_HWA_SetCmu4Clk(u32Cmu4ClkMask);
    }
    else
    {

    }
}

/**
 * @brief Retrieves the interrupt type of the CMU (Clock Monitor Unit) module.
 *
 * This function reads the status register of the CMU module to determine if a LOC (Loss of Clock) 
 * or MIS (Mismatch) interrupt has occurred.
 *
 * @param pHandle Pointer to the CMU module handle. The handle contains information about the CMU instance.
 *
 * @return CMU_InterruptType The current interrupt type, which can be one of the following:
 *         - CMU_INTERRUPT_NONE: No interrupt has occurred.
 *         - CMU_INTERRUPT_LOC: A LOC interrupt has occurred.
 *         - CMU_INTERRUPT_MIS: A MIS interrupt has occurred.
 *
 * @note If device error reporting is enabled (CMU_DEV_ERROR_REPORT == STD_ON),
 *       the function will report an error if the handle pointer is NULL or if the instance number is invalid.
 */
CMU_InterruptType CMU_GetInterruptType(CMU_HandleType *const pHandle)
{
    CMU_InterruptType eStatus = CMU_INTERRUPT_NONE;

#if CMU_DEV_ERROR_REPORT == STD_ON
    if (pHandle == NULL)
    {
        CMU_ReportDevError(CMU_GET_INQTYPE_ID, CMU_E_PARAM_NULLPTR);
    }
    else if (pHandle->eInstance >= CMU_INSTANCE_COUNT)
    {
        CMU_ReportDevError(CMU_GET_INQTYPE_ID, CMU_E_PARAM_INSTANCE);
    }
    else
#endif
    {
        CMU_Type *const pCmu = s_apCmuBase[pHandle->eInstance];
        uint32_t u32Temp;

        u32Temp = CMU_HWA_GetST(pCmu);
        if ((u32Temp & CMU_ST_LOC_MASK) != 0U)
        {
            eStatus = CMU_INTERRUPT_LOC;
        }
        else if ((u32Temp & CMU_ST_MIS_MASK) != 0U)
        {
            eStatus = CMU_INTERRUPT_MIS;
        }
        else
        {

        }
    }

    return eStatus;
}

/**
 * @brief Common Clock Monitor Unit (CMU) Interrupt Service Routine (ISR)
 *
 * This ISR handles common interrupt scenarios for the CMU module associated with the given handle.
 * It retrieves the current interrupt status, performs error handling as needed, and calls
 * the registered error callback function if present. Additionally, it addresses a specific
 * hardware erratum (ERR_CMU_001). After processing, the ISR clears the status flags.
 *
 * @param pHandle Pointer to a CMU handle structure containing the instance information
 *
 * @preconditions
 * - A valid CMU handle must be provided
 * - The CMU instance number should be within the supported range
 * - The error callback function pointer in the handle should be properly initialized
 *
 * @note This function assumes that the CMU interrupt has already occurred and is being serviced.
 * @note Error reporting and handling are performed based on the interrupt status.
 */
void CMU_CommonIRQHandler(CMU_HandleType *const pHandle)
{
#if CMU_DEV_ERROR_REPORT == STD_ON
    if (pHandle == NULL)
    {
        CMU_ReportDevError(CMU_COMMONIRQHANDLER_ID, CMU_E_PARAM_NULLPTR);
    }
    else if (pHandle->eInstance >= CMU_INSTANCE_COUNT)
    {
        CMU_ReportDevError(CMU_COMMONIRQHANDLER_ID, CMU_E_PARAM_INSTANCE);
    }
    else
#endif
    {
        CMU_Type *const pCmu = s_apCmuBase[pHandle->eInstance];
        CMU_InterruptType eStatus;

        eStatus = CMU_GetInterruptType(pHandle);
#ifdef CMU_ERRATA_CMU_001_FIX
        uint32_t u32Count;

        /* Errata: ERR_CMU_001 */
        /* After assert software reset, you need init cmu again */
        if (eStatus == CMU_INTERRUPT_NONE && CMU_HWA_GetPeriodEnable(pCmu))
        {
            if (CMU_INSTANCE_0 == pHandle->eInstance)
            {
                u32Count = 0x1FFU;
            }
            else
            {
                u32Count = 0x1FU;
            }
            CMU_HWA_SetCtrl(pCmu, 0U);
            CMU_HWA_SoftwareRST(pCmu);
            while (CMU_HWA_GetSoftwareRST(pCmu))
            {
                u32Count--;
                if (u32Count == 0U)
                {
                    break;
                }
            }

            if (u32Count == 0U)
            {
                eStatus = CMU_INTERRUPT_LOC;
            }
            else
            {
                eStatus = CMU_INTERRUPT_MIS;
            }
        }
#endif

        CMU_HWA_ClsST(pCmu);
        if (pHandle->tSettings.pErrorCallback != NULL)
        {
            pHandle->tSettings.pErrorCallback(pHandle, eStatus);
        }
    }
}

#endif /* (CMU_INSTANCE_COUNT > 0U) */
