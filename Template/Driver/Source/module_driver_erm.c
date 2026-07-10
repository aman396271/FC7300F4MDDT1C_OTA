/**
 * @file        module_driver_erm.c
 * @author      Flagchip0100
 * @brief       ERM Module driver type definition and API
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

#include "module_driver_erm.h"

#if (ERM_INSTANCE_COUNT > 0U)

/*******************************************************************************
 * Definitions
 ******************************************************************************/

#ifndef ERM_DEV_ERROR_REPORT
#define ERM_DEV_ERROR_REPORT            STD_OFF
#endif

#if ERM_DEV_ERROR_REPORT == STD_ON
#define ERM_ReportDevError(func, error)     ReportDevError(ERM_MODULE_ID, func, error)
#endif

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/

static ERM_Type *const s_apErmBase[ERM_INSTANCE_COUNT] = ERM_BASE_PTRS;

/*******************************************************************************
 * Code
 ******************************************************************************/

/**
 * @brief Initializes the Error Reporting Module (ERM) for the specified instance
 *
 * This function initializes the ERM module with the provided configuration structure.
 * It performs parameter validation, sets up the control register based on the configuration,
 * and clears the status. If an error occurs or the handle is invalid, an error report will
 * be generated, and the function will return a failure status.
 *
 * @param pHandle Pointer to an ERM handle structure containing the instance information
 * @param pInitCfg Pointer to an ERM configuration structure with desired settings
 *
 * @return Status of the initialization operation
 *         - ERM_STATUS_SUCCESS: Initialization successful
 *         - ERM_STATUS_FAIL: Initialization failed due to an error
 *
 * @preconditions
 * - A valid ERM handle and configuration structure pointers must be provided
 * - The ERM instance number should be within the supported range
 *
 * @postconditions
 * - The ERM will be configured according to the provided settings
 * - The status will be cleared
 * - The error callback function pointer in the handle will be set to the one from the configuration
 *
 * @note Error reporting is enabled when `ERM_DEV_ERROR_REPORT` is set to `STD_ON`.
 */
ERM_StatusType ERM_Init(ERM_HandleType *const pHandle, const ERM_CfgType *const pInitCfg)
{
    ERM_StatusType eStatus = ERM_STATUS_SUCCESS;
#if ERM_DEV_ERROR_REPORT == STD_ON
    if (pHandle == NULL)
    {
        ERM_ReportDevError(ERM_INIT_ID, ERM_E_PARAM_NULLPTR);
        eStatus = ERM_STATUS_FAIL;
    }
    else if (pInitCfg == NULL)
    {
        ERM_ReportDevError(ERM_INIT_ID, ERM_E_PARAM_NULLPTR);
        eStatus = ERM_STATUS_FAIL;
    }
    else if (pHandle->eInstance >= ERM_INSTANCE_COUNT)
    {
        ERM_ReportDevError(ERM_INIT_ID, ERM_E_PARAM_INSTANCE);
        eStatus = ERM_STATUS_FAIL;
    }
    else
#endif
    {
        ERM_Type *const pErm = s_apErmBase[pHandle->eInstance];
        uint32_t u32CRnValue = 0U;
        uint8_t u8CRnIdx = (pInitCfg->u8Channel >> 3U) & 0x1FU;
        uint8_t u8CRnPos = (uint8_t)(30U - 4U * (pInitCfg->u8Channel & 0x7U));

        ERM_HWA_SetSRn(pErm, u8CRnIdx, (uint32_t)0x03U << u8CRnPos);
        u32CRnValue = ERM_HWA_GetCRn(pErm, u8CRnIdx);
        /* Enable ERM Channel */
        if(pInitCfg->u8ErmEnable != 0U)
        {
            u32CRnValue |= (uint32_t)pInitCfg->u8IntType << u8CRnPos;
        }
        /* Disable ERM Channel */
        else
        {
            u32CRnValue &= ~((uint32_t)pInitCfg->u8IntType << u8CRnPos);
        }
        ERM_HWA_SetCRn(pErm, u8CRnIdx, u32CRnValue);
    }

    return eStatus;
}

/**
 * @brief Deinitializes the ERM module.
 *
 * This function deinitializes the specified ERM module instance by clearing its control and status registers.
 *
 * @param pHandle Pointer to the ERM handle structure.
 *
 * @return ERM_StatusType Indicates the status of the operation (ERM_STATUS_SUCCESS or ERM_STATUS_FAIL).
 *
 * @note If the handle pointer is NULL or the instance index is out of range, a device error will be reported, and the function returns ERM_STATUS_FAIL.
 */
ERM_StatusType ERM_DeInit(ERM_HandleType *const pHandle)
{
    ERM_StatusType eStatus = ERM_STATUS_SUCCESS;

#if ERM_DEV_ERROR_REPORT == STD_ON
    if (pHandle == NULL)
    {
        ERM_ReportDevError(ERM_DEINIT_ID, ERM_E_PARAM_NULLPTR);
        eStatus = ERM_STATUS_FAIL;
    }
    else if (pHandle->eInstance >= ERM_INSTANCE_COUNT)
    {
        ERM_ReportDevError(ERM_DEINIT_ID, ERM_E_PARAM_INSTANCE);
        eStatus = ERM_STATUS_FAIL;
    }
    else
#endif
    {
        ERM_Type *const pErm = s_apErmBase[pHandle->eInstance];
        uint8_t u8loop;

        for (u8loop = 0U; u8loop < ERM_CR_SR_COUNT_MAX; u8loop++)
        {
            ERM_HWA_SetCRn(pErm, u8loop, 0x0U);
            ERM_HWA_SetSRn(pErm, u8loop, ERM_SR0_MASK);
        }
    }

    return eStatus;
}

/**
 * @brief Handles common Error Reporting Module (ERM) interrupts and invokes error callbacks
 *
 * This function serves as the common interrupt handler for the ERM, checking for errors in various channels
 * (CTCM, DTCM, PFLASH, optionally DFLASH, and DMA) and invoking the error callback function when an error
 * is detected. It also clears the status flags after processing the interrupts.
 *
 * @param pHandle Pointer to an ERM handle structure containing the instance information and error callback
 *
 * @preconditions
 * - A valid ERM handle must be provided with a potentially registered error callback
 *
 * @postconditions
 * - If an error is detected, the corresponding error callback will be called with details
 *   including the channel, error type, and the address where the error occurred
 * - All ERM status flags will be cleared after handling the interrupts
 *
 * @note This function is designed to be used within an interrupt context.
 * @note Support for DFLASH depends on the compile-time configuration `ERM_DFLASH_SUPPORT`.
 */
void ERM_CommonIRQHandler(ERM_HandleType *const pHandle)
{
#if ERM_DEV_ERROR_REPORT == STD_ON
    if (pHandle == NULL)
    {
        ERM_ReportDevError(ERM_COMMONIRQHANDLER_ID, ERM_E_PARAM_NULLPTR);
    }
    else if (pHandle->eInstance >= ERM_INSTANCE_COUNT)
    {
        ERM_ReportDevError(ERM_COMMONIRQHANDLER_ID, ERM_E_PARAM_INSTANCE);
    }
    else
#endif
    {
        ERM_Type *const pErm = s_apErmBase[pHandle->eInstance];
        uint32_t u32SRnValue;
        uint8_t u8LoopI, u8LoopJ, u8Channel, u8ErrorType;

        for (u8LoopI = 0U; u8LoopI < ERM_CR_SR_COUNT_MAX; u8LoopI++)
        {
            u32SRnValue = ERM_HWA_GetSRn(pErm, u8LoopI);
            if (u32SRnValue != 0U)
            {
                for (u8LoopJ = 0U; u8LoopJ < 8U; u8LoopJ++)
                {
                    u8ErrorType = (u32SRnValue >> (30U - 4U * u8LoopJ)) & 0x3U;
                    if (u8ErrorType != 0)
                    {
                        u8Channel = (uint8_t)((u8LoopI << 3U) + u8LoopJ);
                        if (pHandle->tSettings.pErrorCallback[u8Channel] != NULL)
                        {
                            pHandle->tSettings.pErrorCallback[u8Channel](pHandle, u8ErrorType, ERM_HWA_GetEARn(pErm, u8Channel));
                        }
                    }
                }
                ERM_HWA_SetSRn(pErm, u8LoopI, u32SRnValue);
            }
        }
    }
}

#endif /* (ERM_INSTANCE_COUNT > 0U) */
