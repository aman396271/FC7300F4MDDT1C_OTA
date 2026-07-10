/**
 * @file HwA_dmamux.h
 * @author flagchip
 * @brief Hardware access layer for DMAMUX
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
   *   0.1.0      2023-12-15     Flagchip030   N/A          First version for FC7300
   *   2.0.0      2024-10-12     Flagchip099   N/A          Change version and release
   ******************************************************************************** */

#ifndef _HWA_DMAMUX_H_
#define _HWA_DMAMUX_H_

#include "device_header.h"

#if DMAMUX_INSTANCE_COUNT > 0U

/**
 * @defgroup HwA_dmamux HwA_dmamux
 * @ingroup module_driver_dma
 * @{
 */

/**
 * @brief Get whether DMAMUX is enabled for the specified DMA channel
 * 
 * @param pDmamux the base address of the DMAMUX instance
 * @param u8Channel the selected DMA channel
 * @return true DMAMUX is enabled for the specified DMA channel
 * @return false DMAMUX is disabled for the specified DMA channel
 */
LOCAL_INLINE bool DMAMUX_HWA_GetEnableFlag(const DMAMUX_Type *const pDmamux, uint8_t u8Channel)
{
    uint8_t u8TmpVal = (pDmamux->CHCFG[u8Channel] & DMAMUX_CHCFG_ENBL_MASK) >> DMAMUX_CHCFG_ENBL_SHIFT;
    return (bool)((u8TmpVal != 0U) ? true : false);
}

/**
 * @brief Get the request source for the specified DMA channel
 * 
 * @param pDmamux the base address of the DMAMUX instance
 * @param u8Channel the selected DMA channel
 * @return DMA_RequestSourceType the request source of the specified DMA channel
 */
LOCAL_INLINE DMA_RequestSourceType DMAMUX_HWA_GetRequestSource(const DMAMUX_Type *const pDmamux, uint8_t u8Channel)
{
    uint8_t u8TmpVal = (pDmamux->CHCFG[u8Channel] & DMAMUX_CHCFG_SOURCE_MASK) >> DMAMUX_CHCFG_SOURCE_SHIFT;
    return (DMA_RequestSourceType)u8TmpVal;
}

/**
 * @brief Set the request source for the specified DMA channel
 * 
 * @param pDmamux the base address of the DMAMUX instance
 * @param u8Channel the selected DMA channel
 * @param bEnable whether to enable DMAMUX for the specified DMA channel
 * @param eReqSrc the request source to set for the specified DMA channel
 */
LOCAL_INLINE void DMAMUX_HWA_SetRequestSource(DMAMUX_Type *const pDmamux, uint8_t u8Channel, bool bEnable,
                                              DMA_RequestSourceType eReqSrc)
{
    pDmamux->CHCFG[u8Channel] = (uint8_t)((pDmamux->CHCFG[u8Channel] & ~(DMAMUX_CHCFG_ENBL_MASK | DMAMUX_CHCFG_SOURCE_MASK)) |
                                DMAMUX_CHCFG_ENBL(bEnable) | DMAMUX_CHCFG_SOURCE(eReqSrc));
}

/**
 * @brief Get whether periodic trig is enabled for the specified DMA channel
 * 
 * @note Only DMA channel 0~3 supports periodic trig
 * 
 * @param pDmamux the base address of the DMAMUX instance
 * @param u8Channel the selected DMA channel
 * @return true periodic trig is enabled for the specified DMA channel
 * @return true periodic trig is disabled for the specified DMA channel
 */
LOCAL_INLINE bool DMAMUX_HWA_GetPeriodicTrigFlag(const DMAMUX_Type *const pDmamux, uint8_t u8Channel)
{
    uint8_t u8TmpVal = (uint8_t)((pDmamux->CHTRG & (DMAMUX_CHTRG_TRIG0_MASK << u8Channel)) >> u8Channel);
    return (bool)((u8TmpVal != 0U) ? true : false);
}

/**
 * @brief Set whether to enable periodic trig for the specified DMA channel
 * 
 * @note Only DMA channel 0~3 supports periodic trig
 * 
 * @param pDmamux the base address of the DMAMUX instance
 * @param u8Channel the selected DMA channel
 * @param bEnable whether to enable periodic trig for the specified DMA channel
 */
LOCAL_INLINE void DMAMUX_HWA_SetPeriodicTrigFlag(DMAMUX_Type *const pDmamux, uint8_t u8Channel, bool bEnable)
{
    pDmamux->CHTRG = (uint8_t)((pDmamux->CHTRG & ~(DMAMUX_CHTRG_TRIG0_MASK << u8Channel)) | (DMAMUX_CHTRG_TRIG0(bEnable) << u8Channel));
}

/** @}*/

#endif /* #if DMAMUX_INSTANCE_COUNT > 0U */

#endif /* _HWA_DMAMUX_H_ */
