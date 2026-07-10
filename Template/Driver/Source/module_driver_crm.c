/* @file module_driver_crm.c
* @author Flagchip
* @brief crm driver type definition and API
* @version 2.5.0
* @date 2025-08-22
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
#include "module_driver_crm.h"

#if CRM_INSTANCE_COUNT > 0U

void CRM_Init(CRM_HandleType *pCrmHandle, const CRM_InitType *const pInitCfg)
{
    #if CRM_DEV_ERROR_REPORT == STD_ON
    if ((pCrmHandle == NULL) || (pInitCfg == NULL))
    {
        CRM_ReportDevError(CRM_DET_ERROR_ID_FUNC_INIT, CRM_E_NULL_POINT);
        return;
    }
    if (pCrmHandle->eChanIndex >= CRM_CHMAX)
    {
        CRM_ReportDevError(CRM_DET_ERROR_ID_FUNC_INIT, CRM_E_PARAM_CHANNEL);
        return;
    }
    #endif

    CRM_HWA_Set_CH_MATCH_MASK(pCrmHandle->eChanIndex, pCrmHandle->u32MatchIdType, pInitCfg->u32MatchMask);
    CRM_HWA_Set_CH_MATCH_ID0(pCrmHandle->eChanIndex, pCrmHandle->u32MatchIdType, pInitCfg->u32MatchId[0]);
    CRM_HWA_Set_CH_MATCH_ID1(pCrmHandle->eChanIndex, pCrmHandle->u32MatchIdType, pInitCfg->u32MatchId[1]);
    CRM_HWA_Set_CH_ROUTER_ID0(pCrmHandle->eChanIndex, pCrmHandle->u32RouterIdType, pInitCfg->u32RouterId[0]);
    CRM_HWA_Set_CH_ROUTER_ID1(pCrmHandle->eChanIndex, pCrmHandle->u32RouterIdType, pInitCfg->u32RouterId[1]);
    CRM_HWA_Set_CH_ROUTER_CS0(pCrmHandle->eChanIndex, pInitCfg->u32RouterCs[0]);
    CRM_HWA_Set_CH_ROUTER_CS1(pCrmHandle->eChanIndex, pInitCfg->u32RouterCs[1]);
    CRM_HWA_EnableCanrInt(pCrmHandle->eChanIndex, pInitCfg->tIntMask);
    CRM_HWA_EnableChannel(pCrmHandle->eChanIndex);
}

void CRM_DeInit(CRM_HandleType *pCrmHandle)
{
    #if CRM_DEV_ERROR_REPORT == STD_ON
    if ((pCrmHandle == NULL))
    {
        CRM_ReportDevError(CRM_DET_ERROR_ID_FUNC_DEINIT, CRM_E_NULL_POINT);
        return;
    }
    if (pCrmHandle->eChanIndex >= CRM_CHMAX)
    {
        CRM_ReportDevError(CRM_DET_ERROR_ID_FUNC_DEINIT, CRM_E_PARAM_CHANNEL);
        return;
    }
    #endif
    CRM_HWA_DisableCanrInt(pCrmHandle->eChanIndex);
    CRM_HWA_DisableChannel(pCrmHandle->eChanIndex);
}


#endif
