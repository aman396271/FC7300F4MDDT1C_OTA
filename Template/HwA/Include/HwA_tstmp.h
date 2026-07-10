/**
 * @file HwA_tstmp.h
 * @author Flagchip
 * @brief TSTMP hardware access layer
 * @version 2.0.0
 * @date 2024-08-20
 *
 * SDK Version: 2.6.0
 *

 * @copyright Copyright (c) 2020-2024 Flagchip Semiconductors Co., Ltd.
 *
 * @details
 */
/* ********************************************************************************
   *   Revision History:
   *
   *   Version     Date          Initials      CR#          Descriptions
   *   ---------   ----------    ------------  ----------   ---------------
   *   0.1.0      2023-12-15     Flagchip084   N/A          First version for FC7300
   *   2.0.0      2024-10-12     Flagchip084   N/A          Change version and release
   ******************************************************************************** */
#ifndef _HWA_TSTMP_H_
#define _HWA_TSTMP_H_

#include "device_header.h"

#if TSTMP_INSTANCE_COUNT > 0U

/**
 * @defgroup HwA_tstmp HwA_tstmp
 * @ingroup module_driver_tstmp
 * @{
 */

/********* Local typedef ************/
/** @brief Tstmp modulate number */
typedef enum
{
    TSTMP_MODChn0 = 0U,
    TSTMP_MODChn1,
    TSTMP_MODChn2,
    TSTMP_MODChn3
} TSTMP_ModChannelType;

#if (TSTMP_SUPPORT_MODULATE_SUPPOT == STD_ON)
/** @brief TSTMP counter mode
 * (available on FC7300F1M_B only)*/
typedef enum
{
    TSTMP_MODE_ALWAYS_RUNNING = 0U,
    TSTMP_MODE_PERIOD_RUNNING = 1U
} TSTMP_ModeCounterRunningMode;
#endif
/********* Local inline function ************/
/**
 * @brief Read TSTMP value
 *
 * @param pTstmp TSTMP instance
 * @return TSTMP value
 */
LOCAL_INLINE uint64_t TSTMP_HWA_ReadTstmpValue(TSTMP_Type *pTstmp)
{
    uint32_t u32TstmpL, u32TstmpH;
    uint64_t u64TempValue = 0U;
    u32TstmpL = pTstmp->VALL;
    u32TstmpH = pTstmp->VALH;

    u64TempValue = u32TstmpH;
    u64TempValue = (u64TempValue << 32) + u32TstmpL;
    return u64TempValue;
}

/**
 * @brief Read TSTMP interrupt enable bits
 *
 * @param pTstmp TSTMP instance
 * @return TSTMP interrupt enable bits
 */
LOCAL_INLINE uint32_t TSTMP_HWA_ReadTstmpInterruptEnable(TSTMP_Type *pTstmp)
{
    return (uint32_t)pTstmp->MOD_INTEN;
}

/**
 * @brief Read TSTMP all MOD match flag
 *
 * @param pTstmp TSTMP instance
 * @return TSTMP all MOD match flag
 */
LOCAL_INLINE uint32_t TSTMP_HWA_ReadModMatchFlag(TSTMP_Type *pTstmp)
{
    return ((uint32_t)(pTstmp->MOD_STATUS) & (uint32_t)(TSTMP_MOD_STATUS_MOD0_MATCH_MASK | TSTMP_MOD_STATUS_MOD1_MATCH_MASK
                                                        | TSTMP_MOD_STATUS_MOD2_MATCH_MASK | TSTMP_MOD_STATUS_MOD3_MATCH_MASK));
}

/**
 * @brief Clear TSTMP  MOD match flag
 *
 * @param pTstmp TSTMP instance
 */
LOCAL_INLINE void TSTMP_HWA_ClearModMatchFlag(TSTMP_Type *pTstmp,TSTMP_ModChannelType eMod)
{
    pTstmp->MOD_STATUS = ((uint32_t)1U << (uint32_t)eMod);
}



/**
 * @brief Set MOD match value
 *
 * @param pTstmp TSTMP instance
 * @param eMod MOD number
 * @param u32ModValue MOD value
 */
LOCAL_INLINE void TSTMP_HWA_SetModMatchValue(TSTMP_Type *pTstmp, TSTMP_ModChannelType eMod, uint32_t u32ModValue)
{
    switch(eMod)
    {
    	case TSTMP_MODChn0:
    		pTstmp->MOD0_SETVAL = u32ModValue;
    	break;

    	case TSTMP_MODChn1:
    	    pTstmp->MOD1_SETVAL = u32ModValue;
    	break;

    	case TSTMP_MODChn2:
    	    pTstmp->MOD2_SETVAL = u32ModValue;
    	break;

    	case TSTMP_MODChn3:
    	    pTstmp->MOD3_SETVAL = u32ModValue;
    	break;

    	default:
    		break;
    }
}

/**
 * @brief Enable TSTMP MOD(n) match interrupt
 *
 * @param pTstmp TSTMP instance
 * @param eMod MOD number
 */
LOCAL_INLINE void TSTMP_HWA_EnableModMatchInterrupt(TSTMP_Type *pTstmp, TSTMP_ModChannelType eMod)
{
    pTstmp->MOD_INTEN |= ((uint32_t)1U << (uint32_t)eMod);
}

/**
 * @brief Disable TSTMP MOD(n) match interrupt
 *
 * @param pTstmp TSTMP instance
 * @param eMod MOD number
 */
LOCAL_INLINE void TSTMP_HWA_DisableModMatchInterrupt(TSTMP_Type *pTstmp, TSTMP_ModChannelType eMod)
{
    pTstmp->MOD_INTEN &= ~((uint32_t)1U << (uint32_t)eMod);
}

#if (TSTMP_SUPPORT_MODULATE_SUPPOT == STD_ON)

/**
 * @brief Set the counting modes of TSTMP MOD(n)
 *
 * @param pTstmp TSTMP instance
 * @param eMod MOD number
 * @param eCounterMode Counting mode set
 */
LOCAL_INLINE void TSTMP_HWA_SetModCounterMode(TSTMP_Type *pTstmp, TSTMP_ModChannelType eMod, TSTMP_ModeCounterRunningMode eCounterMode)
{
    pTstmp->MOD_INTEN = (pTstmp->MOD_INTEN & ~((uint32_t)0x100U << (uint32_t)eMod)) |
            (((uint32_t)eCounterMode << 8U) << (uint32_t)eMod);
}

/**
 * @brief Enable TSTMP MOD(n) counter
 *
 * @param pTstmp TSTMP instance
 * @param eMod MOD number
 */
LOCAL_INLINE void TSTMP_HWA_EnableModCounter(TSTMP_Type *pTstmp, TSTMP_ModChannelType eMod)
{
    pTstmp->MOD_INTEN |= ((uint32_t)0x10000U << (uint32_t)eMod);
}

/**
 * @brief Disable TSTMP MOD(n) counter
 *
 * @param pTstmp TSTMP instance
 * @param eMod MOD number
 */
LOCAL_INLINE void TSTMP_HWA_DisableModCounter(TSTMP_Type *pTstmp, TSTMP_ModChannelType eMod)
{
    pTstmp->MOD_INTEN &= ~((uint32_t)0x10000U << (uint32_t)eMod);
}

#endif

/** @}*/

#endif /* #if TSTMP_INSTANCE_COUNT > 0U */

#endif /* #ifndef _HWA_TSTMP_H_ */
