/**
 * @file module_driver_crm.h
 * @author Flagchip
 * @brief CRM driver type definition and API
 * @version 2.5.0
 * @date 2025-08-22
 *
 * SDK Version: 2.6.0
 *

 * @copyright Copyright (c) 2020-2025 Flagchip Semiconductors Co., Ltd.
 *
 */
/* ********************************************************************************
   *   Revision History:
   *
   *   Version     Date          Initials      CR#          Descriptions
   *   ---------   ----------    ------------  ----------   ---------------
   *   2.5.0       2025-8-22     Flagchip112   N/A          Release version for FC7300FDDT1C
   ******************************************************************************** */
#ifndef _DRIVER_MODULE_DRIVER_crm_H_
#define _DRIVER_MODULE_DRIVER_crm_H_

#include "device_header.h"
#include "HwA_crm.h"

#if CRM_INSTANCE_COUNT > 0U

#if defined(__cplusplus)
extern "C" {
#endif

/** @brief Detection error ID for initialization function */
#define CRM_DET_ERROR_ID_FUNC_INIT 0x01

/** @brief Detection error ID for de-initialization function */
#define CRM_DET_ERROR_ID_FUNC_DEINIT 0x02

/** @brief Operation status: OK */
#define CRM_E_OK 0x00

/** @brief Error code: Null pointer detected */
#define CRM_E_NULL_POINT   0x01

/** @brief Error code: Invalid channel parameter */
#define CRM_E_PARAM_CHANNEL   0x02

/** @brief Macro control for device error reporting */
#ifndef CRM_DEV_ERROR_REPORT
#define CRM_DEV_ERROR_REPORT    STD_OFF
#endif

#if CRM_DEV_ERROR_REPORT == STD_ON
    /**
     * @brief Report development error
     * @param func Function ID where error occurred
     * @param error Specific error code
     */
    #define CRM_ReportDevError(func, error) ReportDevError(CRM_MODULE_ID, func, error)
#endif

/**
 * @brief CRM module processing handle
 */
typedef struct CRM_HandleType
{
    CRM_ChannelIndex eChanIndex; /**< CRM channel index */
    FLEXCAN_IdType u32MatchIdType;    /**< Channel matching IDs [0], [1] */
    uint32_t u32MatchId[2];    /**< Channel matching IDs [0], [1] */
    FLEXCAN_IdType u32RouterIdType;    /**< Channel matching IDs [0], [1] */
    uint32_t u32RouterId[2];   /**< Router IDs [0], [1] */
    CRM_IntMaskType tIntMask;    /**< Interrupt mask configuration */
} CRM_HandleType;

/**
 * @brief CRM module initialization configuration
 */
typedef struct
{
    uint32_t u32MatchMask;     /**< Channel matching mask */
    FLEXCAN_IdType u32MatchIdType;    /**< Channel matching IDs [0], [1] */
    uint32_t u32MatchId[2];    /**< Channel matching IDs [0], [1] */
    FLEXCAN_IdType u32RouterIdType;    /**< Channel matching IDs [0], [1] */
    uint32_t u32RouterId[2];   /**< Router IDs [0], [1] */
    uint32_t u32RouterCs[2];   /**< Router chip selects [0], [1] */
    CRM_IntMaskType tIntMask;    /**< Interrupt mask configuration */
} CRM_InitType;

/**
 * @brief Initialize CRM module
 * @param pCrmHandle Pointer to CRM handle structure
 * @param pInitCfg Pointer to initialization configuration
 */
void CRM_Init(CRM_HandleType *pCrmHandle, const CRM_InitType *const pInitCfg);

#if defined(__cplusplus)
}
#endif

#endif /* CRM_INSTANCE_COUNT > 0U */

/** @} */ /* End of module_driver_crm group */
#endif /* _DRIVER_MODULE_DRIVER_crm_H_ */
