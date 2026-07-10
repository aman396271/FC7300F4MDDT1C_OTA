/**
 * @file        module_driver_eim.c
 * @author      Flagchip0100
 * @brief       EIM module driver type definition and API
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
 *   0.2.0       2023-02-15    Flagchip052    N/A          First version for FC7300
 *   2.0.0       2024-08-01    Flagchip0100   N/A          SDK2.0 release version
 ********************************************************************************/

#include "module_driver_eim.h"

#if (EIM_INSTANCE_COUNT > 0U)

/*******************************************************************************
 * Definitions
 ******************************************************************************/

#ifndef EIM_DEV_ERROR_REPORT
#define EIM_DEV_ERROR_REPORT            STD_OFF
#endif

#if EIM_DEV_ERROR_REPORT == STD_ON
#define EIM_ReportDevError(func, error)     ReportDevError(EIM_MODULE_ID, func, error)
#endif

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/

static EIM_Type *const s_apEimBase[EIM_INSTANCE_COUNT] = EIM_BASE_PTRS;

/*******************************************************************************
 * Code
 ******************************************************************************/

/**
 * @brief Initializes the Error Injection Module(EIM) with provided configuration settings.
 *
 * This function sets up the EIM module according to the configuration specified in `pInitCfg`.
 * It configures the word channels (WORD0 and WORD1), enables the selected EIM channel, and activates
 * global error injection if supported. Error checking is performed to ensure valid pointers and EIM instance.
 *
 * @param pHandle A pointer to the EIM handle structure which identifies the EIM instance to initialize.
 * @param pInitCfg A pointer to the initialization configuration structure (`EIM_ChCfgType`) defining setup parameters for the EIM module.
 *
 * @return `EIM_STATUS_SUCCESS` if the initialization was successful, otherwise `EIM_STATUS_FAIL`.
 *
 * @note The error reporting macros are conditionally compiled based on `EIM_DEV_ERROR_REPORT` definition.
 */
EIM_StatusType EIM_Init(EIM_HandleType *const pHandle, const EIM_ChCfgType *const pInitCfg)
{
    EIM_StatusType eStatus = EIM_STATUS_SUCCESS;

#if EIM_DEV_ERROR_REPORT == STD_ON
    if (pHandle == NULL)
    {
        EIM_ReportDevError(EIM_INIT_ID, EIM_E_PARAM_NULLPTR);
        eStatus = EIM_STATUS_FAIL;
    }
    else if (pInitCfg == NULL)
    {
        EIM_ReportDevError(EIM_INIT_ID, EIM_E_PARAM_NULLPTR);
        eStatus = EIM_STATUS_FAIL;
    }
    else if (pHandle->eInstance >= EIM_INSTANCE_COUNT)
    {
        EIM_ReportDevError(EIM_INIT_ID, EIM_E_PARAM_INSTANCE);
        eStatus = EIM_STATUS_FAIL;
    }
    else
#endif
    {
        EIM_Type *const pEim = s_apEimBase[pHandle->eInstance];
        uint32_t value;

        pHandle->tStatus.u8EimChn = pInitCfg->u8EimChn;

        if (pInitCfg->u8EimChn >= EIM_LOCKSTEP_CHANNEL_CPU0_LOCKSTEP)
        {
            if (pInitCfg->u8MonNum == EIM_LOCKSTEP_MONITOR0)
            {
                value = EIM_LOCKSTEP_DWP(pInitCfg->u8DwpMode) | EIM_LOCKSTEP_LOCKSTEP_MON0_SET(1U);
            }
            else if (pInitCfg->u8MonNum == EIM_LOCKSTEP_MONITOR1)
            {
                value = EIM_LOCKSTEP_DWP(pInitCfg->u8DwpMode) | EIM_LOCKSTEP_LOCKSTEP_MON1_SET(1U);
            }
            else
            {
                value = EIM_LOCKSTEP_DWP(pInitCfg->u8DwpMode);
            }
            EIM_HWA_SetLockstep(pEim, 
                                (uint8_t)(pInitCfg->u8EimChn - EIM_LOCKSTEP_CHANNEL_CPU0_LOCKSTEP),
                                value);
        }
        else
        {
            value = EIM_BUS_REG_ATTR(pInitCfg->u8AttrPosition) |
                    EIM_BUS_REG_ADDR(pInitCfg->u8AddrePosition) |
                    EIM_BUS_REG_DATA1(pInitCfg->u8Data1Val) |
                    EIM_BUS_REG_DATA0(pInitCfg->u8Data0Val);
            EIM_HWA_SetBusRegn(pEim, pInitCfg->u8BusSelIdx, value);

            value = EIM_LOCKSTEP_DWP(pInitCfg->u8DwpMode) |
                    EIM_CTRL_REG_BUS_SEL(pInitCfg->u8BusSelIdx) |
                    EIM_CTRL_REG_ATTREIE(pInitCfg->u8Attreenable) |
                    EIM_CTRL_REG_ADDREIE(pInitCfg->u8Addreenable) |
                    EIM_CTRL_REG_DATA1EIE(pInitCfg->u8Data1enable) |
                    EIM_CTRL_REG_DATA0EIE(pInitCfg->u8Data0enable);
            EIM_HWA_SetCtrlRegn(pEim, pInitCfg->u8EimChn, value);

            EIM_HWA_EnableGlobalErrorInjection(pEim);
        }
    }

    return eStatus;
}

/**
 * @brief Deinitializes the Error Injection Module(EIM).
 *
 * This function disables the EIM module by clearing all channel configurations, disabling global error injection,
 * and resetting the word channel registers to their default state. Error checking is performed to ensure a valid EIM instance.
 *
 * @param pHandle A pointer to the EIM handle structure identifying the EIM instance to deinitialize.
 *
 * @note The error reporting macros are conditionally compiled based on `EIM_DEV_ERROR_REPORT` definition.
 */
void EIM_Deinit(EIM_HandleType *const pHandle)
{
#if EIM_DEV_ERROR_REPORT == STD_ON
    if (pHandle == NULL)
    {
        EIM_ReportDevError(EIM_DEINIT_ID, EIM_E_PARAM_NULLPTR);
    }
    else if (pHandle->eInstance >= EIM_INSTANCE_COUNT)
    {
        EIM_ReportDevError(EIM_DEINIT_ID, EIM_E_PARAM_INSTANCE);
    }
    else
#endif
    {
        EIM_Type *const pEim = s_apEimBase[pHandle->eInstance];
        uint8_t u8loop;

        for (u8loop = 0U; u8loop < EIM_CTRL_REG_COUNT; u8loop++)
        {
            EIM_HWA_SetCtrlRegn(pEim, u8loop, 0U);
        }
        for (u8loop = 0U; u8loop < 4U; u8loop++)
        {
            EIM_HWA_SetBusRegn(pEim, u8loop, 0U);
        }

        EIM_HWA_SetLockstep(pEim, 0U, 0U);
#ifdef EIM_LOCKSTEP_CPU1_SUPPORT
        EIM_HWA_SetLockstep(pEim, 1U, 0U);
#endif
#ifdef EIM_LOCKSTEP_DMA0_SUPPORT
        EIM_HWA_SetLockstep(pEim, 2U, 0U);
#endif
#ifdef EIM_LOCKSTEP_CPU2_SUPPORT
        EIM_HWA_SetLockstep(pEim, 3U, 0U);
#endif
    }
}

/**
 * @brief Disables error injection in the EIM module.
 *
 * This function disables error injection in the specified EIM module instance. For lockstep channels, it sets the lockstep configuration.
 *
 * @param pHandle Pointer to the EIM handle structure.
 *
 * @note If the handle pointer is NULL or the instance index is out of range, a device error will be reported.
 */
void EIM_DisableInjection(EIM_HandleType *const pHandle)
{
#if EIM_DEV_ERROR_REPORT == STD_ON
    if (pHandle == NULL)
    {
        EIM_ReportDevError(EIM_DISABLEINJECTION_ID, EIM_E_PARAM_NULLPTR);
    }
    else if (pHandle->eInstance >= EIM_INSTANCE_COUNT)
    {
        EIM_ReportDevError(EIM_DISABLEINJECTION_ID, EIM_E_PARAM_INSTANCE);
    }
    else
#endif
    {
        EIM_Type *const pEim = s_apEimBase[pHandle->eInstance];
        if (pHandle->tStatus.u8EimChn >= EIM_LOCKSTEP_CHANNEL_CPU0_LOCKSTEP)
        {
            EIM_HWA_SetLockstep(pEim,
                                (uint8_t)(pHandle->tStatus.u8EimChn - EIM_LOCKSTEP_CHANNEL_CPU0_LOCKSTEP),
                                0x03U);
            DSB();
            EIM_HWA_SetLockstep(pEim,
                                (uint8_t)(pHandle->tStatus.u8EimChn - EIM_LOCKSTEP_CHANNEL_CPU0_LOCKSTEP),
                                0x00U);
            DSB();
        }
        else
        {
            EIM_HWA_DisableGlobalErrorInjection(pEim);
            DSB();
        }
    }
}

#endif /* (EIM_INSTANCE_COUNT > 0U) */
