/**
 * @file HwA_crm.h
 * @author Flagchip
 * @brief CRM register API
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

#ifndef _HWA_CRM_H_
#define _HWA_CRM_H_
#include "device_header.h"
#include "module_driver_flexcan.h"
#if CRM_INSTANCE_COUNT > 0U

/* ################################################################################## */
/* ####################################### Macro #################################### */

/**
 * @brief CAN router interrupt type
 */
typedef enum
{
    CRM_CANR_INT_MAP_MULTI,  /* Multiple mapping interrupt */
    CRM_CANR_INT_MAP_NONE,   /* No mapping interrupt */
    CRM_CANR_INT_MAP_DONE,   /* Mapping done interrupt */
    CRM_CANR_INT_BUSY,       /* Busy interrupt */
    CRM_CANR_INT_MAP_SELF    /* Self mapping interrupt */
} CRM_IntType;

/**
 * @brief Structure for CRM interrupt mask configuration
 *
 * Bitfield configuration matches CRM_CANR_IEN register layout:
 * - MAP_MULTI_IE: Multiple mapping error flag interrupt enable (bit31)
 * - MAP_NONE_IE: No mapping error flag interrupt enable (bit30)
 * - MAP_DONE_IE: Mapping completion flag interrupt enable (bit24)
 * - BUSY_IE: Busy state flag interrupt enable (bit8)
 * - MAP_SELF_IE: Self-mapping flag interrupt enable (bit0)
 */
typedef struct
{
    bool bMapMultiIE;
    bool bMapNoneIE;
    bool bMapDoneIE;
    bool bBusyIE;
    bool bMapSelfIE;
} CRM_IntMaskType;

/********* Local inline function ************/
/* ---------------------------- Channel Registers ----------------------------- */
/**
 * @brief Set MATCH_ID0 register for specified channel
 * @param ch Channel number (CRM_CH0-CRM_CH3)
 * @param u32val Value to set
 */
LOCAL_INLINE void CRM_HWA_Set_CH_MATCH_ID0(CRM_ChannelIndex eChannel, FLEXCAN_IdType eIdType, uint32_t u32val)
{
	uint32_t u32valtemp = 0;
	if(FLEXCAN_ID_STD == eIdType)
	{
		u32valtemp = u32val << 18;
	}else
	{
		u32valtemp = u32val;
	}
    switch (eChannel)
    {
        case CRM_CH0: CRM->CH0_MATCH_ID0 = u32valtemp; break;
        case CRM_CH1: CRM->CH1_MATCH_ID0 = u32valtemp; break;
        case CRM_CH2: CRM->CH2_MATCH_ID0 = u32valtemp; break;
        case CRM_CH3: CRM->CH3_MATCH_ID0 = u32valtemp; break;
        default: break;
    }
}

/**
 * @brief Set MATCH_ID1 register for specified channel
 * @param ch Channel number (CRM_CH0-CRM_CH3)
 * @param u32val Value to set
 */
LOCAL_INLINE void CRM_HWA_Set_CH_MATCH_ID1(CRM_ChannelIndex eChannel, FLEXCAN_IdType eIdType, uint32_t u32val)
{
	uint32_t u32valtemp = 0;
	if(FLEXCAN_ID_STD == eIdType)
	{
		u32valtemp = u32val << 18;
	}else
	{
		u32valtemp = u32val;
	}
    switch (eChannel)
    {
        case CRM_CH0: CRM->CH0_MATCH_ID1 = u32valtemp; break;
        case CRM_CH1: CRM->CH1_MATCH_ID1 = u32valtemp; break;
        case CRM_CH2: CRM->CH2_MATCH_ID1 = u32valtemp; break;
        case CRM_CH3: CRM->CH3_MATCH_ID1 = u32valtemp; break;
        default: break;
    }
}

/**
 * @brief Set ROUTER_ID0 register for specified channel
 * @param ch Channel number (CRM_CH0-CRM_CH3)
 * @param u32val Value to set
 */
LOCAL_INLINE void CRM_HWA_Set_CH_ROUTER_ID0(CRM_ChannelIndex ch, FLEXCAN_IdType eIdType, uint32_t u32val)
{
	uint32_t u32valtemp = 0;
	if(FLEXCAN_ID_STD == eIdType)
	{
		u32valtemp = u32val << 18;
	}else
	{
		u32valtemp = u32val;
	}
    switch (ch)
    {
        case CRM_CH0: CRM->CH0_ROUTER_ID0 = u32valtemp; break;
        case CRM_CH1: CRM->CH1_ROUTER_ID0 = u32valtemp; break;
        case CRM_CH2: CRM->CH2_ROUTER_ID0 = u32valtemp; break;
        case CRM_CH3: CRM->CH3_ROUTER_ID0 = u32valtemp; break;
        default: break;
    }
}

/**
 * @brief Set ROUTER_CS0 register for specified channel
 * @param ch Channel number (CRM_CH0-CRM_CH3)
 * @param u32val Value to set
 */
LOCAL_INLINE void CRM_HWA_Set_CH_ROUTER_CS0(CRM_ChannelIndex ch, uint32_t u32val)
{
    switch (ch)
    {
        case CRM_CH0: CRM->CH0_ROUTER_CS0 = u32val; break;
        case CRM_CH1: CRM->CH1_ROUTER_CS0 = u32val; break;
        case CRM_CH2: CRM->CH2_ROUTER_CS0 = u32val; break;
        case CRM_CH3: CRM->CH3_ROUTER_CS0 = u32val; break;
        default: break;
    }
}

/**
 * @brief Set ROUTER_ID1 register for specified channel
 * @param ch Channel number (CRM_CH0-CRM_CH3)
 * @param u32val Value to set
 */
LOCAL_INLINE void CRM_HWA_Set_CH_ROUTER_ID1(CRM_ChannelIndex ch, FLEXCAN_IdType eIdType, uint32_t u32val)
{
	uint32_t u32valtemp = 0;
	if(FLEXCAN_ID_STD == eIdType)
	{
		u32valtemp = u32val << 18;
	}else
	{
		u32valtemp = u32val;
	}
    switch (ch)
    {
        case CRM_CH0: CRM->CH0_ROUTER_ID1 = u32valtemp; break;
        case CRM_CH1: CRM->CH1_ROUTER_ID1 = u32valtemp; break;
        case CRM_CH2: CRM->CH2_ROUTER_ID1 = u32valtemp; break;
        case CRM_CH3: CRM->CH3_ROUTER_ID1 = u32valtemp; break;
        default: break;
    }
}

/**
 * @brief Set ROUTER_CS1 register for specified channel
 * @param ch Channel number (CRM_CH0-CRM_CH3)
 * @param u32val Value to set
 */
LOCAL_INLINE void CRM_HWA_Set_CH_ROUTER_CS1(CRM_ChannelIndex ch, uint32_t u32val)
{
    switch (ch)
    {
        case CRM_CH0: CRM->CH0_ROUTER_CS1 = u32val; break;
        case CRM_CH1: CRM->CH1_ROUTER_CS1 = u32val; break;
        case CRM_CH2: CRM->CH2_ROUTER_CS1 = u32val; break;
        case CRM_CH3: CRM->CH3_ROUTER_CS1 = u32val; break;
        default: break;
    }
}

/**
 * @brief Set MATCH_MASK register for specified channel
 * @param ch Channel number (CRM_CH0-CRM_CH3)
 * @param u32val Value to set
 */
LOCAL_INLINE void CRM_HWA_Set_CH_MATCH_MASK(CRM_ChannelIndex ch, FLEXCAN_IdType eIdType, uint32_t u32val)
{
	uint32_t u32valtemp = 0;
	if(FLEXCAN_ID_STD == eIdType)
	{
		u32valtemp = u32val << 18;
	}else
	{
		u32valtemp = u32val;
	}
    switch (ch)
    {
        case CRM_CH0: CRM->CH0_MATCH_MASK = u32valtemp; break;
        case CRM_CH1: CRM->CH1_MATCH_MASK = u32valtemp; break;
        case CRM_CH2: CRM->CH2_MATCH_MASK = u32valtemp; break;
        case CRM_CH3: CRM->CH3_MATCH_MASK = u32valtemp; break;
        default: break;
    }
}

/**
 * @brief Get MAP_CS register value for specified channel (read-only)
 * @param ch Channel number (CRM_CH0-CRM_CH3)
 * @return Register value
 */
LOCAL_INLINE uint32_t CRM_HWA_Get_CH_MAP_CS(CRM_ChannelIndex ch)
{
    switch (ch)
    {
        case CRM_CH0: return CRM->CH0_MAP_CS;
        case CRM_CH1: return CRM->CH1_MAP_CS;
        case CRM_CH2: return CRM->CH2_MAP_CS;
        case CRM_CH3: return CRM->CH3_MAP_CS;
        default: return 0;
    }
}

/**
 * @brief Get MAP_ID register value for specified channel (read-only)
 * @param ch Channel number (CRM_CH0-CRM_CH3)
 * @return Register value
 */
LOCAL_INLINE uint32_t CRM_HWA_Get_CH_MAP_ID(CRM_ChannelIndex ch)
{
    switch (ch)
    {
        case CRM_CH0: return CRM->CH0_MAP_ID;
        case CRM_CH1: return CRM->CH1_MAP_ID;
        case CRM_CH2: return CRM->CH2_MAP_ID;
        case CRM_CH3: return CRM->CH3_MAP_ID;
        default: return 0;
    }
}

/* -------------------------- CAN Router Registers ---------------------------- */
/**
 * @brief Enable specific CAN router interrupt
 * @param eIntType Interrupt type to enable
 * @param chMask Channel mask (only for channel-specific interrupts)
 */
LOCAL_INLINE void CRM_HWA_EnableCanrInt(CRM_ChannelIndex ch, CRM_IntMaskType chMask)
{
    uint32_t u32RegVal = CRM->CANR_IEN;
    u32RegVal |= CRM_CANR_STATUS_MAP_MULTI_FLAG(chMask.bMapMultiIE);
    u32RegVal |= CRM_CANR_STATUS_MAP_NONE_FLAG(chMask.bMapNoneIE);
    u32RegVal |= CRM_CANR_STATUS_MAP_DONE_FLAG((chMask.bMapDoneIE) << ch);
    u32RegVal |= CRM_CANR_STATUS_BUSY_FLAG((chMask.bBusyIE) << ch);
    u32RegVal |= CRM_CANR_STATUS_MAP_SELF_FLAG((chMask.bMapSelfIE) << ch);
    CRM->CANR_IEN = u32RegVal;
}

/**
 * @brief Disable specific CAN router interrupt
 * @param eIntType Interrupt type to disable
 * @param chMask Channel mask (only for channel-specific interrupts)
 */
LOCAL_INLINE void CRM_HWA_DisableCanrInt(CRM_ChannelIndex ch)
{
    uint32_t u32RegVal = 0;
    u32RegVal |= CRM_CANR_STATUS_MAP_MULTI_FLAG(1U);
    u32RegVal |= CRM_CANR_STATUS_MAP_NONE_FLAG(1U);
    u32RegVal |= CRM_CANR_STATUS_MAP_DONE_FLAG(1U << ch);
    u32RegVal |= CRM_CANR_STATUS_BUSY_FLAG(1U << ch);
    u32RegVal |= CRM_CANR_STATUS_MAP_SELF_FLAG(1U << ch);
    CRM->CANR_IEN &= ~u32RegVal;
}

/**
 * @brief Get CANR_STATUS register value
 * @return Register value
 */
LOCAL_INLINE uint32_t CRM_HWA_Get_CANR_STATUS(void)
{
    return CRM->CANR_STATUS;
}

/**
 * @brief Clear specific status flag in CANR_STATUS
 * @param eIntType Status flag type to clear
 * @param chMask Channel mask (only for channel-specific flags)
 */
LOCAL_INLINE void CRM_HWA_ClearCanrStatus(CRM_IntType eIntType, uint8_t chMask)
{
    uint32_t u32RegVal = CRM->CANR_STATUS;

    switch (eIntType)
    {
        case CRM_CANR_INT_MAP_MULTI:
            u32RegVal &= ~CRM_CANR_STATUS_MAP_MULTI_FLAG_MASK;
            break;

        case CRM_CANR_INT_MAP_NONE:
            u32RegVal &= ~CRM_CANR_STATUS_MAP_NONE_FLAG_MASK;
            break;

        case CRM_CANR_INT_MAP_DONE:
            u32RegVal &= ~(chMask << CRM_CANR_STATUS_MAP_DONE_FLAG_SHIFT);
            break;

        case CRM_CANR_INT_BUSY:
            u32RegVal &= ~(chMask << CRM_CANR_STATUS_BUSY_FLAG_SHIFT);
            break;

        case CRM_CANR_INT_MAP_SELF:
            u32RegVal &= ~(chMask << CRM_CANR_STATUS_MAP_SELF_FLAG_SHIFT);
            break;

        default:
            break;
    }

    CRM->CANR_STATUS = u32RegVal;
}

/**
 * @brief Set CANR_CTRL register value
 * @param u32val Value to set
 */
LOCAL_INLINE void CRM_HWA_Set_CANR_CTRL(uint32_t u32val)
{
    CRM->CANR_CTRL = u32val & CRM_CANR_CTRL_MASK;
}

/**
 * @brief Get CANR_CTRL register value
 * @return Register value
 */
LOCAL_INLINE uint32_t CRM_HWA_Get_CANR_CTRL(void)
{
    return CRM->CANR_CTRL;
}

/**
 * @brief Enable specific channel in CAN router
 * @param ch Channel to enable
 */
LOCAL_INLINE void CRM_HWA_EnableChannel(CRM_ChannelIndex ch)
{
    CRM->CANR_CTRL |= (1 << ch);
}

/**
 * @brief Disable specific channel in CAN router
 * @param ch Channel to disable
 */
LOCAL_INLINE void CRM_HWA_DisableChannel(CRM_ChannelIndex ch)
{
    CRM->CANR_CTRL &= ~(1 << ch);
}

/** @}*/

#endif /* CRM_INSTANCE_COUNT > 0U */

#endif /* HWA_INCLUDE_HWA_crm_H_ */
