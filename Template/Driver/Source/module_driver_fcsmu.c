/**
 * @file        module_driver_fcsmu.c
 * @author      Flagchip0100
 * @brief       FCSMU module driver type definition and API
 * @version 2.0.0
 * @date 2024-08-20
 *
 * SDK Version: 2.6.0
 *

 * @copyright   Copyright 2020-2024 Flagchip Semiconductors Co., Ltd.
 */

/*********************************************************************************
 *   Revision History:
 *
 *   Version     Date          Initials       CR#          Descriptions
 *   ---------   ----------    ------------   ----------   ---------------
 *   0.1.0       2022-11-18    Flagchip084    N/A          First version for FC7xxx
 *   0.2.0       2023-02-13    Flagchip084    N/A          FC7xxx release version
 *   2.0.0       2024-08-01    Flagchip0100   N/A          SDK2.0 release version
 *********************************************************************************/

#include "module_driver_fcsmu.h"
#include "HwA_csc.h"

#if (FCSMU_INSTANCE_COUNT > 0U)

/*******************************************************************************
 * Definitions
 ******************************************************************************/

#ifndef FCSMU_DEV_ERROR_REPORT
#define FCSMU_DEV_ERROR_REPORT          STD_OFF
#endif

#if FCSMU_DEV_ERROR_REPORT == STD_ON
#define FCSMU_ReportDevError(func, error)     ReportDevError(FCSMU_MODULE_ID, func, error)
#endif

#define FCSMU_FST_UNLOCK_KEY            0x951413CFU
#define FCSMU_OPC1_UNLOCK_KEY           0xFC2020CFU
#define FCSMU_OPC2_UNLOCK_KEY           0x20FCCF20U
#define FCSMU_CONFIG_TMEP_UNLOCK_KEY    0xFCU
#define FCSMU_CONFIG_TMEP_LOCK_KEY      0xFFU

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
static FCSMU_StatusType FCSMU_TransStateNTC(FCSMU_Type *const pFcsmu);
static FCSMU_StatusType FCSMU_TransStateCTN(FCSMU_Type *const pFcsmu);

/*******************************************************************************
 * Variables
 ******************************************************************************/
static FCSMU_Type *const s_apFcsmuBase[FCSMU_INSTANCE_COUNT] = FCSMU_BASE_PTRS;

/*******************************************************************************
 * Code
 ******************************************************************************/

/**
 * @brief Transitions the FCSMU module state to the configuration state.
 *
 * This function attempts to transition the FCSMU module state to the configuration state by setting the appropriate
 * control registers and checking the operation status.
 *
 * @param pFcsmu Pointer to the FCSMU hardware abstraction layer (HAL) structure.
 *
 * @return FCSMU_StatusType Indicates the status of the state transition (FCSMU_STATUS_SUCCESS or FCSMU_STATUS_TIMEOUT).
 *
 * @note The function retries the state transition up to 65535 times with a timeout mechanism to ensure the transition is successful.
 */
static FCSMU_StatusType FCSMU_TransStateNTC(FCSMU_Type *const pFcsmu)
{
    FCSMU_StatusType eStatus = FCSMU_STATUS_TIMEOUT;
    uint32_t u32RetryTimes = 65535U;
    uint32_t u32TimeoutTimes;
    uint32_t u32Temp;

    while (u32RetryTimes != 0U)
    {
        u32TimeoutTimes = 65535U;
        u32Temp = FCSMU_HWA_GetCtrl(pFcsmu);
        u32Temp |= (uint32_t)FCSMU_OP_CODE_MOVE_TO_CONFIG;
        FCSMU_HWA_SetTempUnlk(pFcsmu, FCSMU_CONFIG_TMEP_UNLOCK_KEY);
        FCSMU_HWA_SetOprk(pFcsmu, FCSMU_OPC1_UNLOCK_KEY);
        FCSMU_HWA_SetCrtl(pFcsmu, u32Temp);

        while (FCSMU_HWA_GetCtrlOps(pFcsmu) != (uint32_t)FCSMU_OP_STATE_SUCCESSFUL)
        {
            if (FCSMU_HWA_GetCtrlOps(pFcsmu) == (uint32_t)FCSMU_OP_STATE_BUSY)
            {
                u32TimeoutTimes--;
                if (u32TimeoutTimes == 0U)
                {
                    break;
                }
            }
            else
            {
                break;
            }
        }

        if (u32TimeoutTimes != 0U)
        {
            if (FCSMU_HWA_GetFcsmuState(pFcsmu) == (uint32_t)FCSMU_STATE_CONGIG)
            {
                break;
            }
        }

        u32RetryTimes--;
    }

    if (u32RetryTimes != 0U)
    {
        eStatus = FCSMU_STATUS_SUCCESS;
    }

    return eStatus;
}

/**
 * @brief Transitions the FCSMU module state to the normal state.
 *
 * This function attempts to transition the FCSMU module state to the normal state by setting the appropriate control registers
 * and checking the operation status.
 *
 * @param pFcsmu Pointer to the FCSMU hardware abstraction layer (HAL) structure.
 *
 * @return FCSMU_StatusType Indicates the status of the state transition (FCSMU_STATUS_SUCCESS or FCSMU_STATUS_TIMEOUT).
 *
 * @note The function retries the state transition up to 65535 times with a timeout mechanism to ensure the transition is successful.
 * After a successful transition, it locks the temperature unlock key.
 */
static FCSMU_StatusType FCSMU_TransStateCTN(FCSMU_Type *const pFcsmu)
{
    FCSMU_StatusType eStatus = FCSMU_STATUS_TIMEOUT;
    uint32_t u32RetryTimes = 65535U;
    uint32_t u32TimeoutTimes;
    uint32_t u32Temp;

    while (u32RetryTimes != 0U)
    {
        u32TimeoutTimes = 65535U;
        u32Temp = (uint32_t)FCSMU_HWA_GetCtrl(pFcsmu);
        u32Temp |= (uint32_t)FCSMU_OP_CODE_MOVE_TO_NORMAL;

        FCSMU_HWA_SetOprk(pFcsmu, FCSMU_OPC2_UNLOCK_KEY);
        FCSMU_HWA_SetCrtl(pFcsmu, u32Temp);

        while (FCSMU_HWA_GetCtrlOps(pFcsmu) != (uint32_t)FCSMU_OP_STATE_SUCCESSFUL)
        {
            u32TimeoutTimes--;
            if (u32TimeoutTimes == 0U)
            {
                break;
            }
        }

        if (u32TimeoutTimes != 0U)
        {
            if (FCSMU_HWA_GetFcsmuState(pFcsmu) == (uint32_t)FCSMU_STATE_NORMAL)
            {
                break;
            }
        }

        u32RetryTimes--;
    }

    if (u32RetryTimes != 0U)
    {
        eStatus = FCSMU_STATUS_SUCCESS;
    }

    FCSMU_HWA_SetTempUnlk(pFcsmu, FCSMU_CONFIG_TMEP_LOCK_KEY);

    return eStatus;
}

/**
 * @brief Initializes the FCSMU module.
 *
 * This function initializes the specified FCSMU module instance by transitioning the state to the configuration state,
 * configuring the module according to the provided initialization configuration, and then transitioning back to the normal state.
 *
 * @param pHandle Pointer to the FCSMU handle structure.
 * @param pInitCfg Pointer to the FCSMU initialization configuration structure.
 *
 * @return FCSMU_StatusType Indicates the status of the initialization process (FCSMU_STATUS_SUCCESS or FCSMU_STATUS_FAIL).
 *
 * @note If the handle pointer, initialization configuration pointer, or instance index is invalid,
 * a device error will be reported, and the function returns FCSMU_STATUS_FAIL.
 */
FCSMU_StatusType FCSMU_Init(FCSMU_HandleType *const pHandle, const FCSMU_InitCfgType *const pInitCfg)
{
    FCSMU_StatusType eStatus = FCSMU_STATUS_SUCCESS;

#if FCSMU_DEV_ERROR_REPORT == STD_ON
    if (pHandle == NULL)
    {
        FCSMU_ReportDevError(FCSMU_INIT_ID, FCSMU_E_PARAM_NULLPTR);
        eStatus = FCSMU_STATUS_FAIL;
    }
    else if (pInitCfg == NULL)
    {
        FCSMU_ReportDevError(FCSMU_INIT_ID, FCSMU_E_PARAM_NULLPTR);
        eStatus = FCSMU_STATUS_FAIL;
    }
    else if (pHandle->eInstance >= FCSMU_INSTANCE_COUNT)
    {
        FCSMU_ReportDevError(FCSMU_INIT_ID, FCSMU_E_PARAM_INSTANCE);
        eStatus = FCSMU_STATUS_FAIL;
    }
    else
#endif
    {
        FCSMU_Type *const pFcsmu = s_apFcsmuBase[pHandle->eInstance];

        eStatus = FCSMU_TransStateNTC(pFcsmu);
        if (eStatus == FCSMU_STATUS_SUCCESS)
        {
            if (pInitCfg->u32WarnTo > 204000U) //Max Warning time is 17ms
            {
                FCSMU_HWA_SetWarningTo(pFcsmu, 204000U);
            }
            else
            {
                FCSMU_HWA_SetWarningTo(pFcsmu, pInitCfg->u32WarnTo);
            }
            FCSMU_HWA_ClearCfgToIrq(pFcsmu);
            FCSMU_HWA_SetWarningEn0(pFcsmu, pInitCfg->u32WarnChannel);
            FCSMU_HWA_SetWarningIen0(pFcsmu, pInitCfg->u32WarnInterruptChannel);
            FCSMU_HWA_SetFaultIen0(pFcsmu, pInitCfg->u32FaultInterruptChannel);
            FCSMU_HWA_SetFrst0(pFcsmu, pInitCfg->u32FaultResetChannel);
            FCSMU_HWA_SetFe0(pFcsmu, pInitCfg->u32FaultChannel);
            FCSMU_HWA_SetFccr0(pFcsmu, pInitCfg->u32SoftwareClearedChannel);

            eStatus = FCSMU_TransStateCTN(pFcsmu);
        }
    }
    return eStatus;
}

/**
 * @brief Deinitializes the FCSMU module.
 *
 * This function deinitializes the specified FCSMU module instance by transitioning the state to the configuration state,
 * resetting the configuration settings, and then transitioning back to the normal state.
 *
 * @param pHandle Pointer to the FCSMU handle structure.
 *
 * @return FCSMU_StatusType Indicates the status of the deinitialization process (FCSMU_STATUS_SUCCESS or FCSMU_STATUS_FAIL).
 *
 * @note If the handle pointer or instance index is invalid, a device error will be reported, and the function returns FCSMU_STATUS_FAIL.
 */
FCSMU_StatusType FCSMU_Deinit(FCSMU_HandleType *const pHandle)
{
    FCSMU_StatusType eStatus = FCSMU_STATUS_SUCCESS;

#if FCSMU_DEV_ERROR_REPORT == STD_ON
    if (pHandle == NULL)
    {
        FCSMU_ReportDevError(FCSMU_DEINIT_ID, FCSMU_E_PARAM_NULLPTR);
        eStatus = FCSMU_STATUS_FAIL;
    }
    else if (pHandle->eInstance >= FCSMU_INSTANCE_COUNT)
    {
        FCSMU_ReportDevError(FCSMU_DEINIT_ID, FCSMU_E_PARAM_INSTANCE);
        eStatus = FCSMU_STATUS_FAIL;
    }
    else
#endif
    {
        FCSMU_Type *const pFcsmu = s_apFcsmuBase[pHandle->eInstance];

        eStatus = FCSMU_TransStateNTC(pFcsmu);
        if (eStatus == FCSMU_STATUS_SUCCESS)
        {
            FCSMU_HWA_SetFaultIen0(pFcsmu, 0U);
            FCSMU_HWA_SetWarningIen0(pFcsmu, 0U);
            FCSMU_HWA_SetFe0(pFcsmu, 0U);
            FCSMU_HWA_SetWarningEn0(pFcsmu, 0U);
            FCSMU_HWA_SetWarningTo(pFcsmu, 0x0003A980U);
            FCSMU_HWA_ClearCfgToIrq(pFcsmu);
            FCSMU_HWA_SetFrst0(pFcsmu, 0U);
            FCSMU_HWA_SetFccr0(pFcsmu, 0xFFFFFFFFU);

            eStatus = FCSMU_TransStateCTN(pFcsmu);
        }
    }

    return eStatus;
}

/**
 * @brief Initializes the status output configuration for the FCSMU module.
 *
 * This function initializes the status output configuration for the specified FCSMU module instance by transitioning the state
 * to the configuration state, setting the status output control register, and then transitioning back to the normal state.
 *
 * @param pHandle Pointer to the FCSMU handle structure.
 * @param pInitCfg Pointer to the FCSMU status output configuration structure.
 *
 * @return FCSMU_StatusType Indicates the status of the status output initialization process (FCSMU_STATUS_SUCCESS or FCSMU_STATUS_FAIL).
 *
 * @note If the handle pointer, initialization configuration pointer, or instance index is invalid, a device error will be reported,
 * and the function returns FCSMU_STATUS_FAIL.
 */
FCSMU_StatusType FCSMU_StatusOutputInit(FCSMU_HandleType *const pHandle, const FCSMU_StatusOutputCfgType *const pInitCfg)
{
    FCSMU_StatusType eStatus = FCSMU_STATUS_SUCCESS;

#if FCSMU_DEV_ERROR_REPORT == STD_ON
    if (pHandle == NULL)
    {
        FCSMU_ReportDevError(FCSMU_STATUSOUTPUTINIT_ID, FCSMU_E_PARAM_NULLPTR);
        eStatus = FCSMU_STATUS_FAIL;
    }
    else if (pInitCfg == NULL)
    {
        FCSMU_ReportDevError(FCSMU_STATUSOUTPUTINIT_ID, FCSMU_E_PARAM_NULLPTR);
        eStatus = FCSMU_STATUS_FAIL;
    }
    else if (pHandle->eInstance >= FCSMU_INSTANCE_COUNT)
    {
        FCSMU_ReportDevError(FCSMU_STATUSOUTPUTINIT_ID, FCSMU_E_PARAM_INSTANCE);
        eStatus = FCSMU_STATUS_FAIL;
    }
    else
#endif
    {
        FCSMU_Type *const pFcsmu = s_apFcsmuBase[pHandle->eInstance];
        uint32_t u32SoctrlValue, u32StmrValue;

        if (pInitCfg->bFastMode == true)
        {
            if ((pInitCfg->u32Protocal != FCSMU_SOUT_PROTOCOL_DUAL_RAIL) &&
                (pInitCfg->u32Protocal != FCSMU_SOUT_PROTOCOL_TIME_SWITCH))
            {
                eStatus = FCSMU_STATUS_FAIL;
            }
        }

        if (eStatus == FCSMU_STATUS_SUCCESS)
        {
            u32SoctrlValue = FCSMU_SOCTRL_SOUT_PEN(pInitCfg->bEnable) |
                        FCSMU_SOCTRL_FASTEN(pInitCfg->bFastMode) |
                        FCSMU_SOCTRL_POLSW(pInitCfg->u8Polarity) |
                        FCSMU_SOCTRL_SOUT_PTC(pInitCfg->u32Protocal) |
                        FCSMU_SOCTRL_SOUT_CTRL(pInitCfg->u8SoutCtrl) |
                        FCSMU_SOCTRL_SOUT_DIV(pInitCfg->u32Divder) |
                        FCSMU_SOCTRL_SMRDT(pInitCfg->u32Delaytimer);

            u32StmrValue = FCSMU_STMR_MINI_TIME(pInitCfg->u32SoutMinTmrInterval);

#ifdef FCSMU_SOCTRL_DIVEX_SUPPORT
            u32SoctrlValue |= FCSMU_SOCTRL_DIVEX(pInitCfg->bDivex);
#endif
#ifdef FCSMU_STMR_FTTI_SUPPORT
            u32StmrValue |= FCSMU_STMR_FTTI(pInitCfg->u8FttiTime);
#endif
#ifdef FCSMU_STMR_MTE_SUPPORT
            u32StmrValue |= FCSMU_STMR_MTE(pInitCfg->bSoutMinTmr);
#endif

            eStatus = FCSMU_TransStateNTC(pFcsmu);
            if (eStatus == FCSMU_STATUS_SUCCESS)
            {
                FCSMU_HWA_SetSoctrl(pFcsmu, u32SoctrlValue);
                FCSMU_HWA_SetStmr(pFcsmu, u32StmrValue);
                FCSMU_HWA_SetSoutEn0(pFcsmu, pInitCfg->u32SoutChannel);

                eStatus = FCSMU_TransStateCTN(pFcsmu);
            }
        }
    }

    return eStatus;
}

/**
 * @brief Deinitializes the status output configuration for the FCSMU module.
 *
 * This function deinitializes the status output configuration for the specified FCSMU module instance by transitioning the state to the
 * configuration state, clearing the status output control register, and then transitioning back to the normal state.
 *
 * @param pHandle Pointer to the FCSMU handle structure.
 *
 * @return FCSMU_StatusType Indicates the status of the status output deinitialization process (FCSMU_STATUS_SUCCESS or FCSMU_STATUS_FAIL).
 *
 * @note If the handle pointer or instance index is invalid, a device error will be reported, and the function returns FCSMU_STATUS_FAIL.
 */
FCSMU_StatusType FCSMU_StatusOutputDeinit(FCSMU_HandleType *const pHandle)
{
    FCSMU_StatusType eStatus = FCSMU_STATUS_SUCCESS;

#if FCSMU_DEV_ERROR_REPORT == STD_ON
    if (pHandle == NULL)
    {
        FCSMU_ReportDevError(FCSMU_STATUSOUTPUTDEINIT_ID, FCSMU_E_PARAM_NULLPTR);
        eStatus = FCSMU_STATUS_FAIL;
    }
    else if (pHandle->eInstance >= FCSMU_INSTANCE_COUNT)
    {
        FCSMU_ReportDevError(FCSMU_STATUSOUTPUTDEINIT_ID, FCSMU_E_PARAM_INSTANCE);
        eStatus = FCSMU_STATUS_FAIL;
    }
    else
#endif
    {
        FCSMU_Type *const pFcsmu = s_apFcsmuBase[pHandle->eInstance];

        eStatus = FCSMU_TransStateNTC(pFcsmu);
        if (eStatus == FCSMU_STATUS_SUCCESS)
        {
            FCSMU_HWA_SetSoctrl(pFcsmu, 0U);
            FCSMU_HWA_SetSoutEn0(pFcsmu, 0U);

            eStatus = FCSMU_TransStateCTN(pFcsmu);
        }
    }

    return eStatus;
}

/**
 * @brief Retrieves the fault channel for the specified FCSMU module.
 *
 * This function retrieves the fault channel for the specified FCSMU module instance.
 *
 * @param pHandle Pointer to the FCSMU handle structure.
 *
 * @return uint32_t The fault channel number.
 *
 * @note If the handle pointer or instance index is invalid, a device error will be reported.
 */
uint32_t FCSMU_GetFaultChannel(FCSMU_HandleType *const pHandle)
{
    uint32_t u32Channel = 0u;

#if FCSMU_DEV_ERROR_REPORT == STD_ON
    if (pHandle == NULL)
    {
        FCSMU_ReportDevError(FCSMU_GETFAULTCHANNEL_ID, FCSMU_E_PARAM_NULLPTR);
    }
    else if (pHandle->eInstance >= FCSMU_INSTANCE_COUNT)
    {
        FCSMU_ReportDevError(FCSMU_GETFAULTCHANNEL_ID, FCSMU_E_PARAM_INSTANCE);
    }
    else
#endif
    {
        FCSMU_Type *const pFcsmu = s_apFcsmuBase[pHandle->eInstance];

        u32Channel = FCSMU_HWA_GetFst0(pFcsmu);
    }

    return u32Channel;
}

/**
 * @brief Clears the fault flag for the specified fault channel in the FCSMU module.
 *
 * This function clears the fault flag for the specified fault channel in the specified FCSMU module instance by unlocking the fault clear
 * mechanism, setting the fault channel to clear, and waiting for the operation to complete.
 *
 * @param pHandle Pointer to the FCSMU handle structure.
 * @param u32FaultChannel The fault channel whose fault flag should be cleared.
 *
 * @return FCSMU_StatusType Indicates the status of the fault flag clearing process (FCSMU_STATUS_SUCCESS or FCSMU_STATUS_TIMEOUT).
 *
 * @note If the handle pointer or instance index is invalid, a device error will be reported, and the function returns FCSMU_STATUS_FAIL.
 */
FCSMU_StatusType FCSMU_ClearFaultFlag(FCSMU_HandleType *const pHandle, uint32_t u32FaultChannel)
{
    FCSMU_StatusType eStatus = FCSMU_STATUS_SUCCESS;

#if FCSMU_DEV_ERROR_REPORT == STD_ON
    if (pHandle == NULL)
    {
        FCSMU_ReportDevError(FCSMU_CLEARFAULT_ID, FCSMU_E_PARAM_NULLPTR);
        eStatus = FCSMU_STATUS_FAIL;
    }
    else if (pHandle->eInstance >= FCSMU_INSTANCE_COUNT)
    {
        FCSMU_ReportDevError(FCSMU_CLEARFAULT_ID, FCSMU_E_PARAM_INSTANCE);
        eStatus = FCSMU_STATUS_FAIL;
    }
    else
#endif
    {
        FCSMU_Type *const pFcsmu = s_apFcsmuBase[pHandle->eInstance];
        uint32_t u32TimeoutTimes = 65535U;

        FCSMU_HWA_SetFstUnlk(pFcsmu, FCSMU_FST_UNLOCK_KEY);
        FCSMU_HWA_SetFst0(pFcsmu, u32FaultChannel);

        while (FCSMU_HWA_GetCtrlOps(pFcsmu) != FCSMU_OP_STATE_SUCCESSFUL)
        {
            u32TimeoutTimes--;
            if (u32TimeoutTimes == 0U)
            {
                eStatus = FCSMU_STATUS_TIMEOUT;
                break;
            }
        }

        /* Clear NTF/WTF/NTW/FTW register when no FST flag is set. */
        if (eStatus == FCSMU_STATUS_SUCCESS)
        {
            if (FCSMU_HWA_GetFst0(pFcsmu) == 0U)
            {
                u32TimeoutTimes = (uint32_t)FCSMU_HWA_GetCtrl(pFcsmu);
                u32TimeoutTimes |= (uint32_t)FCSMU_OP_CODE_CLEAR_FAULT_INFO;
                FCSMU_HWA_SetCrtl(pFcsmu, u32TimeoutTimes);

                u32TimeoutTimes = 65535U;
                while (FCSMU_HWA_GetCtrlOps(pFcsmu) != FCSMU_OP_STATE_SUCCESSFUL)
                {
                    u32TimeoutTimes--;
                    if (u32TimeoutTimes == 0U)
                    {
                        eStatus =  FCSMU_STATUS_TIMEOUT;
                        break;
                    }
                }
            }
        }
    }

    return eStatus;
}

/**
 * @brief Injects a fault into the specified channel in the FCSMU module.
 *
 * This function injects a fault into the specified channel in the specified FCSMU module instance by setting the injection register.
 *
 * @param pHandle Pointer to the FCSMU handle structure.
 * @param u32ChannelIndex The channel index where the fault should be injected.
 *
 * @return FCSMU_StatusType Indicates the status of the fault injection process (FCSMU_STATUS_SUCCESS or FCSMU_STATUS_FAIL).
 *
 * @note If the handle pointer or instance index is invalid, a device error will be reported, and the function returns FCSMU_STATUS_FAIL.
 */
FCSMU_StatusType FCSMU_InjectionFault(FCSMU_HandleType *const pHandle, uint32_t u32ChannelIndex)
{
    FCSMU_StatusType eStatus = FCSMU_STATUS_SUCCESS;

#if FCSMU_DEV_ERROR_REPORT == STD_ON
    if (pHandle == NULL)
    {
        FCSMU_ReportDevError(FCSMU_INJECTIONFAULT_ID, FCSMU_E_PARAM_NULLPTR);
        eStatus = FCSMU_STATUS_FAIL;
    }
    else if (pHandle->eInstance >= FCSMU_INSTANCE_COUNT)
    {
        FCSMU_ReportDevError(FCSMU_INJECTIONFAULT_ID, FCSMU_E_PARAM_INSTANCE);
        eStatus = FCSMU_STATUS_FAIL;
    }
    else
#endif
    {
        FCSMU_Type *const pFcsmu = s_apFcsmuBase[pHandle->eInstance];

        FCSMU_HWA_SetInject(pFcsmu, u32ChannelIndex);
    }

    return eStatus;
}

/**
 * @brief Initializes the CRC checker for the FCSMU module.
 *
 * This function initializes the CRC checker for the specified FCSMU module instance by generating a CRC, configuring the trigger mode
 * and error request mode, and enabling the CRC checker and error output.
 *
 * @param pHandle Pointer to the FCSMU handle structure.
 * @param pInitCfg Pointer to the FCSMU CRC configuration structure.
 *
 * @return FCSMU_StatusType Indicates the status of the CRC initialization process (FCSMU_STATUS_SUCCESS or FCSMU_STATUS_TIMEOUT).
 *
 * @note If the handle pointer, initialization configuration pointer, or instance index is invalid, a device error will be reported,
 * and the function returns FCSMU_STATUS_FAIL.
 */
FCSMU_StatusType FCSMU_CrcInit(FCSMU_HandleType *const pHandle, const FCSMU_CrcCfgType *const pInitCfg)
{
    FCSMU_StatusType eStatus = FCSMU_STATUS_SUCCESS;

#if FCSMU_DEV_ERROR_REPORT == STD_ON
    if (pHandle == NULL)
    {
        FCSMU_ReportDevError(FCSMU_CRCINIT_ID, FCSMU_E_PARAM_NULLPTR);
        eStatus = FCSMU_STATUS_FAIL;
    }
    else if (pInitCfg == NULL)
    {
        FCSMU_ReportDevError(FCSMU_CRCINIT_ID, FCSMU_E_PARAM_NULLPTR);
        eStatus = FCSMU_STATUS_FAIL;
    }
    else if (pHandle->eInstance >= FCSMU_INSTANCE_COUNT)
    {
        FCSMU_ReportDevError(FCSMU_CRCINIT_ID, FCSMU_E_PARAM_INSTANCE);
        eStatus = FCSMU_STATUS_FAIL;
    }
    else
#endif
    {
        FCSMU_Type *const pFcsmu = s_apFcsmuBase[pHandle->eInstance];
        uint32_t u32TimeoutTimes = 65535U;

        FCSMU_HWA_GenerateCrc(pFcsmu);
        while (FCSMU_HWA_GetCrcBusy(pFcsmu) == FCSMU_CRC_STATE_BUSY)
        {
            u32TimeoutTimes--;
            if (u32TimeoutTimes == 0U)
            {
                eStatus = FCSMU_STATUS_TIMEOUT;
                break;
            }
        }

        if (eStatus == FCSMU_STATUS_SUCCESS)
        {
#ifdef FCSMU_CRC_CTRL_DONE_SUPPORT
            FCSMU_HWA_ClearCrcDoneFlag(pFcsmu);
#endif
            if (pInitCfg->u16Mode == FCSMU_CRC_SW_MODE)
            {
                FCSMU_HWA_EnableTrigger(pFcsmu, false);
            }
            else{
                FCSMU_HWA_EnableTrigger(pFcsmu, true);
            }

#ifdef CSC0_SMU_CTRL4_SMU_RIE_MASK /* FC7240 is not same to others */
            if (pInitCfg->u16ErrorReqMode == FCSMU_CRC_ERROR_REQ_MODE_IRQ)
            {
                u32TimeoutTimes = CSC0_HWA_Get_SMU_CTRL4() | CSC0_SMU_CTRL4_SMU_RIE(0U);
                u32TimeoutTimes &= ~CSC0_SMU_CTRL4_SMU_RIE_MASK;
                CSC0_HWA_Set_SMU_CTRL4(u32TimeoutTimes);
            }
            else if (pInitCfg->u16ErrorReqMode == FCSMU_CRC_ERROR_REQ_MODE_RST)
            {
                u32TimeoutTimes = CSC0_HWA_Get_SMU_CTRL4() | CSC0_SMU_CTRL4_SMU_RIE(2U);
                u32TimeoutTimes &= ~CSC0_SMU_CTRL4_SMU_RIE_MASK;
                CSC0_HWA_Set_SMU_CTRL4(u32TimeoutTimes);
            }
            else
            {
                u32TimeoutTimes = CSC0_HWA_Get_SMU_CTRL4();
                u32TimeoutTimes &= ~(CSC0_SMU_CTRL4_SMU_RIE_MASK);
                CSC0_HWA_Set_SMU_CTRL4(u32TimeoutTimes);
            }
#else
            if (pInitCfg->u16ErrorReqMode == FCSMU_CRC_ERROR_REQ_MODE_IRQ)
            {
                u32TimeoutTimes = CSC0_HWA_Get_SMU_CTRL4() | CSC0_SMU_CTRL4_SCF_IRQ_EN_MASK;
                u32TimeoutTimes &= ~CSC0_SMU_CTRL4_SCF_RST_EN_MASK;
                CSC0_HWA_Set_SMU_CTRL4(u32TimeoutTimes);
            }
            else if (pInitCfg->u16ErrorReqMode == FCSMU_CRC_ERROR_REQ_MODE_RST)
            {
                u32TimeoutTimes = CSC0_HWA_Get_SMU_CTRL4() | CSC0_SMU_CTRL4_SCF_RST_EN_MASK;
                u32TimeoutTimes &= ~CSC0_SMU_CTRL4_SCF_IRQ_EN_MASK;
                CSC0_HWA_Set_SMU_CTRL4(u32TimeoutTimes);
            }
            else
            {
                u32TimeoutTimes = CSC0_HWA_Get_SMU_CTRL4();
                u32TimeoutTimes &= ~(CSC0_SMU_CTRL4_SCF_IRQ_EN_MASK | CSC0_SMU_CTRL4_SCF_RST_EN_MASK);
                CSC0_HWA_Set_SMU_CTRL4(u32TimeoutTimes);
            }
#endif

            FCSMU_HWA_EnableErrorOutput(pFcsmu, true);
            FCSMU_HWA_EnableCrcChecker(pFcsmu, true);
        }
    }

    return eStatus;
}

/**
 * @brief Deinitializes the CRC checker for the FCSMU module.
 *
 * This function deinitializes the CRC checker for the specified FCSMU module instance by clearing the CRC control register and the CRC error flag.
 *
 * @param pHandle Pointer to the FCSMU handle structure.
 *
 * @return FCSMU_StatusType Indicates the status of the CRC deinitialization process (FCSMU_STATUS_SUCCESS or FCSMU_STATUS_FAIL).
 *
 * @note If the handle pointer or instance index is invalid, a device error will be reported, and the function returns FCSMU_STATUS_FAIL.
 */
FCSMU_StatusType FCSMU_CrcDeinit(FCSMU_HandleType *const pHandle)
{
    FCSMU_StatusType eStatus = FCSMU_STATUS_SUCCESS;

#if FCSMU_DEV_ERROR_REPORT == STD_ON
    if (pHandle == NULL)
    {
        FCSMU_ReportDevError(FCSMU_CRCDEINIT_ID, FCSMU_E_PARAM_NULLPTR);
        eStatus = FCSMU_STATUS_FAIL;
    }
    else if (pHandle->eInstance >= FCSMU_INSTANCE_COUNT)
    {
        FCSMU_ReportDevError(FCSMU_CRCDEINIT_ID, FCSMU_E_PARAM_INSTANCE);
        eStatus = FCSMU_STATUS_FAIL;
    }
    else
#endif
    {
        FCSMU_Type *const pFcsmu = s_apFcsmuBase[pHandle->eInstance];

        FCSMU_HWA_SetCrcCtrl(pFcsmu, 0U);
        FCSMU_HWA_ClearCrcErrorFlag(pFcsmu);
#ifdef FCSMU_CRC_CTRL_DONE_SUPPORT
        FCSMU_HWA_ClearCrcDoneFlag(pFcsmu);
#endif
    }

    return eStatus;
}

/**
 * @brief Generates a CRC for the specified FCSMU module.
 *
 * This function generates a CRC for the specified FCSMU module instance by initiating the CRC generation process.
 *
 * @param pHandle Pointer to the FCSMU handle structure.
 *
 * @return FCSMU_StatusType Indicates the status of the CRC generation process (FCSMU_STATUS_SUCCESS or FCSMU_STATUS_FAIL).
 *
 * @note If the handle pointer or instance index is invalid, a device error will be reported, and the function returns FCSMU_STATUS_FAIL.
 */
FCSMU_StatusType FCSMU_CrcGen(FCSMU_HandleType *const pHandle)
{
    FCSMU_StatusType eStatus = FCSMU_STATUS_SUCCESS;

#if FCSMU_DEV_ERROR_REPORT == STD_ON
    if (pHandle == NULL)
    {
        FCSMU_ReportDevError(FCSMU_CRCGEN_ID, FCSMU_E_PARAM_NULLPTR);
        eStatus = FCSMU_STATUS_FAIL;
    }
    else if (pHandle->eInstance >= FCSMU_INSTANCE_COUNT)
    {
        FCSMU_ReportDevError(FCSMU_CRCGEN_ID, FCSMU_E_PARAM_INSTANCE);
        eStatus = FCSMU_STATUS_FAIL;
    }
    else
#endif
    {
        FCSMU_Type *const pFcsmu = s_apFcsmuBase[pHandle->eInstance];

        FCSMU_HWA_GenerateCrc(pFcsmu);
    }

    return eStatus;
}

/**
 * @brief Checks if the CRC generation process is busy for the specified FCSMU module.
 *
 * This function checks if the CRC generation process is currently busy for the specified FCSMU module instance.
 *
 * @param pHandle Pointer to the FCSMU handle structure.
 *
 * @return bool Indicates whether the CRC generation process is busy (true) or not (false).
 *
 * @note If the handle pointer or instance index is invalid, a device error will be reported.
 */
bool FCSMU_CrcIsBusy(FCSMU_HandleType *const pHandle)
{
    bool bIsBusy = false;

#if FCSMU_DEV_ERROR_REPORT == STD_ON
    if (pHandle == NULL)
    {
        FCSMU_ReportDevError(FCSMU_CRCISBUSY_ID, FCSMU_E_PARAM_NULLPTR);
    }
    else if (pHandle->eInstance >= FCSMU_INSTANCE_COUNT)
    {
        FCSMU_ReportDevError(FCSMU_CRCISBUSY_ID, FCSMU_E_PARAM_INSTANCE);
    }
    else
#endif
    {
        FCSMU_Type *const pFcsmu = s_apFcsmuBase[pHandle->eInstance];

        bIsBusy = FCSMU_HWA_GetCrcBusy(pFcsmu);
    }

    return bIsBusy;
}

#ifdef FCSMU_CRC_CTRL_DONE_SUPPORT
/**
 * @brief Clears the busy flag for the CRC generation process in the specified FCSMU module.
 *
 * This function clears the busy flag for the CRC generation process in the specified FCSMU module instance.
 *
 * @param pHandle Pointer to the FCSMU handle structure.
 *
 * @note If the handle pointer or instance index is invalid, a device error will be reported.
 *
 * @note This function is specific to devices within the range FC7240F2MDS1P100T1A to FC7240F2MDS1P176T1A.
 */
void FCSMU_CrcClearBusy(FCSMU_HandleType *const pHandle)
{
#if FCSMU_DEV_ERROR_REPORT == STD_ON
    if (pHandle == NULL)
    {
        FCSMU_ReportDevError(FCSMU_CRCCLEARBUSY_ID, FCSMU_E_PARAM_NULLPTR);
    }
    else if (pHandle->eInstance >= FCSMU_INSTANCE_COUNT)
    {
        FCSMU_ReportDevError(FCSMU_CRCCLEARBUSY_ID, FCSMU_E_PARAM_INSTANCE);
    }
    else
#endif
    {
        FCSMU_Type *const pFcsmu = s_apFcsmuBase[pHandle->eInstance];
        FCSMU_HWA_ClearCrcDoneFlag(pFcsmu);
    }
}
#endif

/**
 * @brief Retrieves the result of the CRC calculation for the specified FCSMU module.
 *
 * This function retrieves the result of the CRC calculation for the specified FCSMU module instance.
 *
 * @param pHandle Pointer to the FCSMU handle structure.
 *
 * @return uint32_t The result of the CRC calculation.
 *
 * @note If the handle pointer or instance index is invalid, a device error will be reported.
 */
uint32_t FCSMU_CrcGetResult(FCSMU_HandleType *const pHandle)
{
    uint32_t u32Result = 0U;

#if FCSMU_DEV_ERROR_REPORT == STD_ON
    if (pHandle == NULL)
    {
        FCSMU_ReportDevError(FCSMU_CRCGETRESULT_ID, FCSMU_E_PARAM_NULLPTR);
    }
    else if (pHandle->eInstance >= FCSMU_INSTANCE_COUNT)
    {
        FCSMU_ReportDevError(FCSMU_CRCGETRESULT_ID, FCSMU_E_PARAM_INSTANCE);
    }
    else
#endif
    {
        FCSMU_Type *const pFcsmu = s_apFcsmuBase[pHandle->eInstance];

        u32Result = FCSMU_HWA_GetCrcResult(pFcsmu);
    }

    return u32Result;
}

/**
 * @brief Handles common interrupts for the FCSMU module.
 *
 * This static function handles common interrupts for the specified FCSMU module instance. It processes fault, warning, and configuration
 * timeout interrupts by retrieving relevant information and invoking appropriate callbacks.
 *
 * @param pHandle Pointer to the FCSMU handle structure.
 *
 * @note This function is intended for internal use only and should not be called directly.
 *
 * @note If the handle pointer or instance index is invalid, a device error will be reported.
 */
void FCSMU_CommonIRQHandler(FCSMU_HandleType *const pHandle)
{
#if FCSMU_DEV_ERROR_REPORT == STD_ON
    if (pHandle == NULL)
    {
        FCSMU_ReportDevError(FCSMU_COMMONIRQHANDLER_ID, FCSMU_E_PARAM_NULLPTR);
    }
    else if (pHandle->eInstance >= FCSMU_INSTANCE_COUNT)
    {
        FCSMU_ReportDevError(FCSMU_COMMONIRQHANDLER_ID, FCSMU_E_PARAM_INSTANCE);
    }
    else
#endif
    {
        FCSMU_Type *const pFcsmu   = s_apFcsmuBase[pHandle->eInstance];
        uint32_t u32IrqStat        = FCSMU_HWA_GetIrqStat(pFcsmu);
        uint32_t u32IrqChannelMask = FCSMU_HWA_GetFst0(pFcsmu);

        if ((u32IrqStat & FCSMU_IRQ_STAT_FAULT_IRQ_MASK) == FCSMU_IRQ_STAT_FAULT_IRQ_MASK)
        {
            pHandle->tSettings.pFaultCallback(pHandle, u32IrqChannelMask);
        }
        else if ((u32IrqStat & FCSMU_IRQ_STAT_WARNING_IRQ_MASK) == FCSMU_IRQ_STAT_WARNING_IRQ_MASK)
        {
            pHandle->tSettings.pWarningCallback(pHandle, u32IrqChannelMask);
        }
        else if ((u32IrqStat & FCSMU_IRQ_STAT_CFG_TO_IRQ_MASK) == FCSMU_IRQ_STAT_CFG_TO_IRQ_MASK)
        {
            pHandle->tSettings.pTimeoutCallback(pHandle);
        }
        else
        {

        }
    }
}

#endif /* (FCSMU_INSTANCE_COUNT > 0U) */
