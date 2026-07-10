/**
 * @file HwA_scm.h
 * @author flagchip
 * @brief Hardware access layer for SCM
 * @version 2.0.0
 * @date 2024-08-20
 *
 * SDK Version: 2.6.0
 *

 * @copyright Copyright (c) 2020-2024 Flagchip Semiconductors Co., Ltd.
 *
 */
/* ********************************************************************************
   *   Revision History:
   *
   *   Version     Date          Initials      CR#          Descriptions
   *   ---------   ----------    ------------  ----------   ---------------
   *   0.1.0      2023-12-15     Flagchip055   N/A          First version for FC7300
   *   2.0.0      2024-10-12     Flagchip055   N/A          Change version and release
   ******************************************************************************** */

#ifndef _HWA_SCM_H_
#define _HWA_SCM_H_
#include "device_header.h"

#if SCM_INSTANCE_COUNT > 0U

/**
 * @brief SCM adc trigger selection
 */
typedef enum
{
    SCM_ADC_INSTANCE_0 = 0U,
    SCM_ADC_INSTANCE_1 = 1U,
    SCM_ADC_INSTANCE_2 = 2U,
    SCM_ADC_INSTANCE_3 = 3U,
    SCM_ADC_INSTANCE_4 = 4U,
    SCM_ADC_INSTANCE_5 = 5U,
} SCM_AdcInstance;

/**
 * @brief SCM adc trigger selection
 */
typedef enum
{
    SCM_ADC_TRIGGER_PTIMER = 0U,
    SCM_ADC_TRIGGER_TRGSEL = 1U,
} SCM_AdcTriggerSel;

/**
 * @brief SCM adc pre-trigger selection
 */
typedef enum
{
    SCM_ADC_PRE_TRIGGER_PTIMER = 0U,
    SCM_ADC_PRE_TRIGGER_TRGSEL = 1U,
    SCM_ADC_PRE_TRIGGER_SCM_SOFTWARE_PRE_TRIGGER = 2U,
} SCM_AdcPreTriggerSel;

/**
 * @brief SCM software trigger source
 */
typedef enum
{
    SCM_SOFTWARE_PRE_TRIGGER_0 = 0U,   /*!< SCM software pre-trigger 0 */
    SCM_SOFTWARE_PRE_TRIGGER_1 = 1U,   /*!< SCM software pre-trigger 1 */
    SCM_SOFTWARE_PRE_TRIGGER_2 = 2U,   /*!< SCM software pre-trigger 2 */
    SCM_SOFTWARE_PRE_TRIGGER_3 = 3U,   /*!< SCM software pre-trigger 3 */
} SCM_SoftwarePreTrigger;

/**
 * @defgroup HwA_scm HwA_scm
 * @ingroup module_driver_scm
 * @{
 */

/********* Local typedef ************/


/********* Local inline function ************/
/**
 * @brief Get UIDL data(Unique identification for the chip. Loaded from NVR)
 *
 * @return return value
 */
LOCAL_INLINE uint32_t SCM_HWA_GetData_UIDL(void)
{
    return SCM->UIDL;
}

/**
 * @brief Get UIDML data(Unique identification for the chip. Loaded from NVR)
 *
 * @return return value
 */
LOCAL_INLINE uint32_t SCM_HWA_GetData_UIDML(void)
{
    return SCM->UIDML;
}

/**
 * @brief Get UIDMH data(Unique identification for the chip. Loaded from NVR)
 *
 * @return return value
 */
LOCAL_INLINE uint32_t SCM_HWA_GetData_UIDMH(void)
{
    return SCM->UIDMH;
}

/**
 * @brief Get UIDH data(Unique identification for the chip. Loaded from NVR)
 *
 * @return return value
 */
LOCAL_INLINE uint32_t SCM_HWA_GetData_UIDH(void)
{
    return SCM->UIDH;
}

/**
 * @brief Get Family Identification
 *
 * @return return value
 */
LOCAL_INLINE uint8_t SCM_HWA_GetData_FamilyID(void)
{
    return (uint8_t)((SCM->PARTID0 & (uint32_t)SCM_PARTID0_FAM_ID_MASK) >> (uint32_t)SCM_PARTID0_FAM_ID_SHIFT);
}

/**
 * @brief Get Revision Identification
 *
 * @return return value
 */
LOCAL_INLINE uint8_t SCM_HWA_GetData_RevID(void)
{
    return (uint8_t)((SCM->PARTID0 & (uint32_t)SCM_PARTID0_REVID_MASK));
}

/**
 * @brief Set the ISM_ROUTING register value
 *
 * @param  u32Val value to be set
 */
LOCAL_INLINE void SCM_HWA_Set_ISM_ROUTING(uint32_t u32Val)
{
    SCM->ISM_ROUTING = u32Val;
}

/**
 * @brief Get CHIPCFG0 register status
 *
 * @return  return value
 */
LOCAL_INLINE uint32_t SCM_HWA_Get_CHIPCFG0(void)
{
    return SCM->CHIPCFG0;
}

/**
 * @brief Set the SOCMISC register value
 *
 * @param  u32Val value to be set
 */
LOCAL_INLINE void SCM_HWA_Set_SOCMISC(uint32_t u32Val)
{
    SCM->SOCMISC = u32Val;
}

/**
 * @brief Get the SOCMISC register status
 *
 * @return Lock status
 */
LOCAL_INLINE uint32_t SCM_HWA_Get_SOCMISC(void)
{
    return SCM->SOCMISC;
}

#if SCM_GET_DEVICEID_SUPPORT
/**
 * @brief Get device ID
 *
 * @return return value
 */
LOCAL_INLINE uint32_t SCM_HWA_GetData_DeviceID(void)
{
    return ((SCM->CHIPCFG1 & (uint32_t)SCM_CHIPCFG1_DEVICE_ID_MASK) >> (uint32_t)SCM_CHIPCFG1_DEVICE_ID_SHIFT);
}
#endif

/**
 * @brief Get SYSAP_CTRL register status
 *
 * @return Register status
 */
LOCAL_INLINE uint32_t SCM_HWA_Get_SYSAP_CTRL(void)
{
    return SCM->SYSAP_CTRL;
}

#if SCM_CRC_SUPPORT
/**
 * @brief Set the CRCCSR register value
 *
 * @param  u32Val value to be set
 */
LOCAL_INLINE void SCM_HWA_Set_CRCCSR(uint32_t u32Val)
{
    SCM->CRCCSR = u32Val;
}

/**
 * @brief Get CRCCSR register status
 *
 * @return Register status
 */
LOCAL_INLINE uint32_t SCM_HWA_Get_CRCCSR(void)
{
    return SCM->CRCCSR;
}

/**
 * @brief Set CRC check enable/disable
 *
 * @param bEnable Enable/Disable
 */
LOCAL_INLINE void SCM_HWA_SetCrcCheckEnable(bool bEnable)
{
    SCM->CRCCSR = (SCM->CRCCSR & (~(SCM_CRCCSR_CHKEN_MASK))) | SCM_CRCCSR_CHKEN(bEnable);
}

/**
 * @brief Set CRC trigger enable/disable
 *
 * @param bEnable Enable/Disable
 */
LOCAL_INLINE void SCM_HWA_SetCrcTriggerEnable(bool bEnable)
{
    SCM->CRCCSR = (SCM->CRCCSR & (~(SCM_CRCCSR_TRGEN_MASK))) | SCM_CRCCSR_TRGEN(bEnable);
}

/**
 * @brief Set CRC error out enable/disable
 *
 * @param bEnable Enable/Disable
 */
LOCAL_INLINE void SCM_HWA_SetCrcErrorOutEnable(bool bEnable)
{
    SCM->CRCCSR = (SCM->CRCCSR & (~(SCM_CRCCSR_EOEN_MASK))) | SCM_CRCCSR_EOEN(bEnable);
}

/**
 * @brief Clear CRC error flag
 */
LOCAL_INLINE void SCM_HWA_ClearCrcErrorFlag(void)
{
    SCM->CRCCSR |= SCM_CRCCSR_ERR_MASK;
}

/**
 * @brief Get CRC Done Flag
 *
 * @return CRC Done Flag
 */
LOCAL_INLINE bool SCM_HWA_GetCrcDoneFlag(void)
{
    return ((SCM->CRCCSR & SCM_CRCCSR_BUY_MASK) == SCM_CRCCSR_BUY_MASK) ? false : true;
}

/**
 * @brief Set CRC software generate enable/disable
 *
 * @param bEnable Enable/Disable
 */
LOCAL_INLINE void SCM_HWA_SetCrcGenerateEnable(bool bEnable)
{
    SCM->CRCCSR = (SCM->CRCCSR & (~(SCM_CRCCSR_GEN_MASK))) | SCM_CRCCSR_GEN(bEnable);
}

/**
 * @brief Get CRC result
 *
 * @return CRC result
 */
LOCAL_INLINE uint32_t SCM_HWA_GetCrcResult(void)
{
    return SCM->CRCRES;
}
#endif
/**
 * @brief Set the FTU_GTBC register value
 *
 * @param  u32Val value to be set
 */
LOCAL_INLINE void SCM_HWA_Set_FTU_GTBC(uint32_t u32Val)
{
#if defined (SCM_FTU_GTBC_FTU_GTBC_MASK)
    SCM->FTU_GTBC = u32Val;
#elif defined (SCM_FTU_GTBC_FTU0_GTBC_MASK)
    SCM->FTU_GTBC = u32Val;
#else
#error "No valid SCM_FTU_GTB*_FTU*_GTBC_MASK definition"
#endif
}

#if defined(SCM_GTBC_TPU_SELECT_SUPPORT) && (SCM_GTBC_TPU_SELECT_SUPPORT)
/**
 * @brief Configure TPU global time base control selection
 *
 * @param bEn Enable or disable TPU Global Time Base
 */
LOCAL_INLINE void SCM_HWA_ConfigTpuGTBSelect(bool bEn)
{
#if defined(SCM_FTU_GTBC_ETPU_GTBC_MASK)
    SCM->FTU_GTBC &= ~(uint32_t)SCM_FTU_GTBC_ETPU_GTBC_MASK;
    SCM->FTU_GTBC |= (uint32_t)SCM_FTU_GTBC_ETPU_GTBC(bEn);
#elif defined(SCM_FTU_GTBC_TPU_GTBC_MASK)
    SCM->FTU_GTBC &= ~(uint32_t)SCM_FTU_GTBC_TPU_GTBC_MASK;
	SCM->FTU_GTBC |= (uint32_t)SCM_FTU_GTBC_TPU_GTBC(bEn);
#else
#error "No valid SCM_FTU_GTBC_*TPU definition"
#endif
}

#endif

/**
 * @brief Set TPU clock enable/disable
 *
 * @param bEnable Enable/Disable
 */
LOCAL_INLINE void SCM_HWA_SUBSYS_PCC_SetEnable_TPUClock(bool bEnable)
{
#if defined(SCM_SUBSYSPCC_SUPPORT) && defined(SCM_SUBSYSPCC_SUPPORT)
    SCM->SUBSYS_PCC = ((SCM->SUBSYS_PCC & (~(uint32_t)SCM_SUBSYS_PCC_CLKEN_TPU_MASK)) |
                        SCM_SUBSYS_PCC_CLKEN_TPU(bEnable));
#elif (SCM_TPUPCC_SUPPORT && SCM_TPUPCC_SUPPORT)
    SCM->TPU_PCC = ((SCM->TPU_PCC & (~(uint32_t)SCM_TPU_PCC_CLKEN_TPU_MASK)) |
    SCM_TPU_PCC_CLKEN_TPU(bEnable));
#else
    PROCESS_UNUSED_VAR(bEnable);
#endif
}

/**
 * @brief Set SubSystem clock enable/disable
 *
 * @param bEnable Enable/Disable
 */
LOCAL_INLINE void SCM_HWA_SUBSYS_PCC_SetEnable_SubSystemClock(bool bEnable)
{
#if (SCM_FLEXHSM_PCC_SUPPORT && SCM_FLEXHSM_PCC_SUPPORT)
    SCM->FLEXHSM_PCC = ((SCM->FLEXHSM_PCC & (~(uint32_t)SCM_FLEXHSM_PCC_CLKEN_FLEXHSM_MASK)) |
                        SCM_FLEXHSM_PCC_CLKEN_FLEXHSM(bEnable));
#elif (SCM_SUBSYSPCC_SUPPORT && SCM_SUBSYSPCC_SUPPORT)
    SCM->SUBSYS_PCC = ((SCM->SUBSYS_PCC & (~(uint32_t)SCM_SUBSYS_PCC_CLKEN_SUBSYS_MASK)) |
                        SCM_SUBSYS_PCC_CLKEN_SUBSYS(bEnable));
#else
    PROCESS_UNUSED_VAR(bEnable);
#endif
}

#if defined(SCM_GTBC_FTU_SELECT_SUPPORT) && (SCM_GTBC_FTU_SELECT_SUPPORT)
/**
 * @brief Set FTU global time base control selection
 *
 * @param u32SelectedFtu The GTBC mask of Selected Ftu instance,it is the or value of SCM_FTUGTBCtrlType.
 *        eg.u32SelectedFtu == 1 means FTU0 selected, u32SelectedFtu == 5 means FTU0 and FTU2 selected.
 */
LOCAL_INLINE void SCM_HWA_SetFtuGTBSelect(uint32_t u32SelectedFtu)
{
    SCM->FTU_GTBC |= (u32SelectedFtu & 0xFFu) << SCM_FTU_GTBC_FTU0_GTBC_SHIFT;
}

/**
 * @brief Clear FTU global time base control selection
 *
 * @param u32SelectedFtu The GTBC mask of Selected Ftu instance,it is the or value of SCM_FTUGTBCtrlType.
 *        eg.u32SelectedFtu == 1 means FTU0 selected, u32SelectedFtu == 5 means FTU0 and FTU2 selected.
 */
LOCAL_INLINE void SCM_HWA_ClearFtuGTBSelect(uint32_t u32SelectedFtu)
{
    SCM->FTU_GTBC &= ~(uint32_t)((u32SelectedFtu & 0xFFu) << SCM_FTU_GTBC_FTU0_GTBC_SHIFT);
}
#endif

#if defined(SCM_FTU_GTBC_TSTMP_TRIG_SUPPORT) && (SCM_FTU_GTBC_TSTMP_TRIG_SUPPORT)
/**
 * @brief Configure FTU Global Time Base Control Mask Register
 *
 * @param u8FtuIndex The selected FTU instance (must be 0 ~ 7)
 * @param u32Value Value to be set (must be 0 ~ 15)
 */
LOCAL_INLINE void SCM_HWA_ConfigFtuGTBMask(uint8_t u8FtuIndex, uint32_t u32Value)
{
#if defined(SCM_FTU_GTBEM_FTU0_GTBEM_MASK)
    SCM->FTU_GTBEM = 	(SCM->FTU_GTBEM & (~((uint32_t)SCM_FTU_GTBEM_FTU0_GTBEM_MASK << (SCM_FTU_GTBEM_FTU0_GTBEM_WIDTH * u8FtuIndex))))
    					| (((uint32_t)u32Value & SCM_FTU_GTBEM_FTU0_GTBEM_MASK) << (SCM_FTU_GTBEM_FTU0_GTBEM_WIDTH * u8FtuIndex));
#elif defined(SCM_FTU_GTBCM_FTU0_GTBCM_MASK)
    SCM->FTU_GTBCM = 	(SCM->FTU_GTBCM & (~((uint32_t)SCM_FTU_GTBCM_FTU0_GTBCM_MASK << (SCM_FTU_GTBCM_FTU0_GTBCM_WIDTH * u8FtuIndex))))
        				| (((uint32_t)u32Value & SCM_FTU_GTBCM_FTU0_GTBCM_MASK) << (SCM_FTU_GTBCM_FTU0_GTBCM_WIDTH * u8FtuIndex));

#else
#error "No valid SCM_FTU_GTB*M_FTU*_GTB*M definition"
#endif
}

/**
 * @brief Clear FTU Global Time Base Control Mask Register
 *
 * @param u8FtuIndex The selected FTU instance (must be 0 ~ 7)
 */
LOCAL_INLINE void SCM_HWA_ClearFtuGTBMask(uint8_t u8FtuIndex)
{
#if defined(SCM_FTU_GTBEM_FTU0_GTBEM_MASK)
    SCM->FTU_GTBEM &= ~ ((uint32_t)SCM_FTU_GTBEM_FTU0_GTBEM_MASK << (SCM_FTU_GTBEM_FTU0_GTBEM_WIDTH * u8FtuIndex));
#elif defined(SCM_FTU_GTBCM_FTU0_GTBCM_MASK)
    SCM->FTU_GTBCM &= ~ ((uint32_t)SCM_FTU_GTBCM_FTU0_GTBCM_MASK << (SCM_FTU_GTBCM_FTU0_GTBCM_WIDTH * u8FtuIndex));
#else
#error "No valid SCM_FTU_GTB*M_FTU*_GTB*M definition"
#endif
}
#endif


#if SCM_PTIMER_CHANNEL_SELECTION_SUPPORT
/**
 * @brief Set the ADC_ROUTING2 register value
 *
 * @param  u32Val value to be set
 */
LOCAL_INLINE void SCM_HWA_Set_ADC_ROUTING2(uint32_t u32Val)
{
    SCM->ADC_ROUTING2 = u32Val;
}

/**
 * @brief Get the ADC_ROUTING2 register status
 *
 * @return Lock status
 */
LOCAL_INLINE uint32_t SCM_HWA_Get_ADC_ROUTING2(void)
{
    return SCM->ADC_ROUTING2;
}
#endif

#ifdef SCM_CPU1VTOR_CPU1_INIT_VECTOR_MASK
/**
 * @brief Set the CPU1VTOR register value
 *
 * @param  u32Val value to be set
 */
LOCAL_INLINE void SCM_HWA_Set_CPU1VTOR(uint32_t u32Val)
{
    SCM->CPU1VTOR = u32Val;
}

/**
 * @brief Get the CPU1VTOR register status
 *
 * @return Lock status
 */
LOCAL_INLINE uint32_t SCM_HWA_Get_CPU1VTOR(void)
{
    return SCM->CPU1VTOR;
}

/**
 * @brief Set CPU1 Vector Table Register vector initial vector
 *
 * @param u32Value value to be set
 */
LOCAL_INLINE void SCM_HWA_CPU1VTOR_SetVector(uint32_t u32Value)
{
    uint32_t u32RegVal = SCM->CPU1VTOR;
    SCM->CPU1VTOR = ((u32RegVal & (~(uint32_t)SCM_CPU1VTOR_CPU1_INIT_VECTOR_MASK)) | SCM_CPU1VTOR_CPU1_INIT_VECTOR(u32Value));
}
#endif

#ifdef SCM_CPU2VTOR_CPU2_INIT_VECTOR_MASK
/**
 * @brief Set the CPU2VTOR register value
 *
 * @param  u32Val value to be set
 */
LOCAL_INLINE void SCM_HWA_Set_CPU2VTOR(uint32_t u32Val)
{
    SCM->CPU2VTOR = u32Val;
}

/**
 * @brief Get the CPU2VTOR register status
 *
 * @return Lock status
 */
LOCAL_INLINE uint32_t SCM_HWA_Get_CPU2VTOR(void)
{
    return SCM->CPU2VTOR;
}

/**
 * @brief Set Core Hold Register vector initial vector
 *
 * @param u32Value value to be set
 */
LOCAL_INLINE void SCM_HWA_CPU2VTOR_SetVector(uint32_t u32Value)
{
    uint32_t u32RegVal = SCM->CPU2VTOR;
    SCM->CPU2VTOR = ((u32RegVal & (~(uint32_t)SCM_CPU2VTOR_CPU2_INIT_VECTOR_MASK)) | SCM_CPU2VTOR_CPU2_INIT_VECTOR(u32Value));
}
#endif

#ifdef SCM_CPU3VTOR_CPU3_INIT_VECTOR_MASK
/**
 * @brief Set the CPU3VTOR register value
 *
 * @param  u32Val value to be set
 */
LOCAL_INLINE void SCM_HWA_Set_CPU3VTOR(uint32_t u32Val)
{
    SCM->CPU3VTOR = u32Val;
}

/**
 * @brief Get the CPU3VTOR register status
 *
 * @return Lock status
 */
LOCAL_INLINE uint32_t SCM_HWA_Get_CPU3VTOR(void)
{
    return SCM->CPU3VTOR;
}

/**
 * @brief Set Core Hold Register vector initial vector
 *
 * @param u32Value value to be set
 */
LOCAL_INLINE void SCM_HWA_CPU3VTOR_SetVector(uint32_t u32Value)
{
    uint32_t u32RegVal = SCM->CPU3VTOR;
    SCM->CPU3VTOR = ((u32RegVal & (~(uint32_t)SCM_CPU3VTOR_CPU3_INIT_VECTOR_MASK)) | SCM_CPU3VTOR_CPU3_INIT_VECTOR(u32Value));
}
#endif

#ifdef SCM_CORE_HOLD_CPU1_CORE_HOLD_MASK
/**
 * @brief Set cpu1 hold enable status
 *
 * @param bEnable Enable/Disable status
 */
LOCAL_INLINE void SCM_HWA_SetCOREHOLD_Cpu1Hold(bool bEnable)
{
    if (true == bEnable)
    {
        SCM->CORE_HOLD |= (uint32_t)SCM_CORE_HOLD_CPU1_CORE_HOLD_MASK;
    }
    else
    {
        SCM->CORE_HOLD &= ~(uint32_t)SCM_CORE_HOLD_CPU1_CORE_HOLD_MASK;
    }
}
#endif
#ifdef SCM_CORE_HOLD_CPU2_CORE_HOLD_MASK
/**
 * @brief Set cpu2 hold enable status
 *
 * @param bEnable Enable/Disable status
 */
LOCAL_INLINE void SCM_HWA_SetCOREHOLD_Cpu2Hold(bool bEnable)
{
    if (true == bEnable)
    {
        SCM->CORE_HOLD |= (uint32_t)SCM_CORE_HOLD_CPU2_CORE_HOLD_MASK;
    }
    else
    {
        SCM->CORE_HOLD &= ~(uint32_t)SCM_CORE_HOLD_CPU2_CORE_HOLD_MASK;
    }
}
#endif
#ifdef SCM_CORE_HOLD_CPU3_CORE_HOLD_MASK
/**
 * @brief Set cpu3 hold enable status
 *
 * @param bEnable Enable/Disable status
 */
LOCAL_INLINE void SCM_HWA_SetCOREHOLD_Cpu3Hold(bool bEnable)
{
    if (true == bEnable)
    {
        SCM->CORE_HOLD |= (uint32_t)SCM_CORE_HOLD_CPU3_CORE_HOLD_MASK;
    }
    else
    {
        SCM->CORE_HOLD &= ~(uint32_t)SCM_CORE_HOLD_CPU3_CORE_HOLD_MASK;
    }
}
#endif

#if SCM_ADC_PRE_TRIGGER_SEL_SUPPORT
LOCAL_INLINE void SCM_HWA_SetAdcPretriggerSel(SCM_AdcInstance eInstance, SCM_AdcPreTriggerSel ePreTriggerSel)
{
    #if ADC_INSTANCE_COUNT > 5U
    if (eInstance == SCM_ADC_INSTANCE_5)
    {
        SCM->ADC_ROUTING1 = (SCM->ADC_ROUTING1 & ~SCM_ADC_ROUTING1_ADC5_PRETRGSEL_MASK) |
                            SCM_ADC_ROUTING1_ADC5_PRETRGSEL(ePreTriggerSel);
    }
    else
    #endif
    #if ADC_INSTANCE_COUNT > 4U
    if (eInstance == SCM_ADC_INSTANCE_4)
    {
        SCM->ADC_ROUTING1 = (SCM->ADC_ROUTING1 & ~SCM_ADC_ROUTING1_ADC4_PRETRGSEL_MASK) |
                            SCM_ADC_ROUTING1_ADC4_PRETRGSEL(ePreTriggerSel);
    }
    else
    #endif
    #if ADC_INSTANCE_COUNT > 3U
    if (eInstance == SCM_ADC_INSTANCE_3)
    {
        SCM->ADC_ROUTING = (SCM->ADC_ROUTING & ~SCM_ADC_ROUTING_ADC3_PRETRGSEL_MASK) |
                           SCM_ADC_ROUTING_ADC3_PRETRGSEL(ePreTriggerSel);
    }
    else
    #endif
    #if ADC_INSTANCE_COUNT > 2U
    if (eInstance == SCM_ADC_INSTANCE_2)
    {
        SCM->ADC_ROUTING = (SCM->ADC_ROUTING & ~SCM_ADC_ROUTING_ADC2_PRETRGSEL_MASK) |
                           SCM_ADC_ROUTING_ADC2_PRETRGSEL(ePreTriggerSel);
    }
    else
    #endif
    #if ADC_INSTANCE_COUNT > 1U
    if (eInstance == SCM_ADC_INSTANCE_1)
    {
        SCM->ADC_ROUTING = (SCM->ADC_ROUTING & ~SCM_ADC_ROUTING_ADC1_PRETRGSEL_MASK) |
                           SCM_ADC_ROUTING_ADC1_PRETRGSEL(ePreTriggerSel);
    }
    else
    #endif
    #if ADC_INSTANCE_COUNT > 0U
    if (eInstance == SCM_ADC_INSTANCE_0)
    {
        SCM->ADC_ROUTING = (SCM->ADC_ROUTING & ~SCM_ADC_ROUTING_ADC0_PRETRGSEL_MASK) |
                           SCM_ADC_ROUTING_ADC0_PRETRGSEL(ePreTriggerSel);
    }
    #endif
}
#endif

#if SCM_ADC_TRIGGER_SEL_SUPPORT
LOCAL_INLINE void SCM_HWA_SetAdcTriggerSel(SCM_AdcInstance eInstance, SCM_AdcTriggerSel eTriggerSel)
{
    #if ADC_INSTANCE_COUNT > 5U
    if (eInstance == SCM_ADC_INSTANCE_5)
    {
        SCM->ADC_ROUTING1 = (SCM->ADC_ROUTING1 & ~SCM_ADC_ROUTING1_ADC5_TRGSEL_MASK) |
                            SCM_ADC_ROUTING1_ADC5_TRGSEL(eTriggerSel);
    }
    else
    #endif
    #if ADC_INSTANCE_COUNT > 4U
    if (eInstance == SCM_ADC_INSTANCE_4)
    {
        SCM->ADC_ROUTING1 = (SCM->ADC_ROUTING1 & ~SCM_ADC_ROUTING1_ADC4_TRGSEL_MASK) |
                            SCM_ADC_ROUTING1_ADC4_TRGSEL(eTriggerSel);
    }
    else
    #endif
    #if ADC_INSTANCE_COUNT > 3U
    if (eInstance == SCM_ADC_INSTANCE_3)
    {
        SCM->ADC_ROUTING = (SCM->ADC_ROUTING & ~SCM_ADC_ROUTING_ADC3_TRGSEL_MASK) |
                           SCM_ADC_ROUTING_ADC3_TRGSEL(eTriggerSel);
    }
    else
    #endif
    #if ADC_INSTANCE_COUNT > 2U
    if (eInstance == SCM_ADC_INSTANCE_2)
    {
        SCM->ADC_ROUTING = (SCM->ADC_ROUTING & ~SCM_ADC_ROUTING_ADC2_TRGSEL_MASK) |
                           SCM_ADC_ROUTING_ADC2_TRGSEL(eTriggerSel);
    }
    else
    #endif
    #if ADC_INSTANCE_COUNT > 1U
    if (eInstance == SCM_ADC_INSTANCE_1)
    {
        SCM->ADC_ROUTING = (SCM->ADC_ROUTING & ~SCM_ADC_ROUTING_ADC1_TRGSEL_MASK) |
                           SCM_ADC_ROUTING_ADC1_TRGSEL(eTriggerSel);
    }
    else
    #endif
    #if ADC_INSTANCE_COUNT > 0U
    if (eInstance == SCM_ADC_INSTANCE_0)
    {
        SCM->ADC_ROUTING = (SCM->ADC_ROUTING & ~SCM_ADC_ROUTING_ADC0_TRGSEL_MASK) |
                           SCM_ADC_ROUTING_ADC0_TRGSEL(eTriggerSel);
    }
    #endif
}
#endif

#if SCM_HSADC_BIAS_FORCE_ENABLE_SUPPORT

LOCAL_INLINE void SCM_HWA_SetHsadcBiasForceEnable(void)
{
    SCM->ADC_CFG = SCM->ADC_CFG | (1U << 31U);
}

#endif

/** @}*/

#endif /* #if SCM_INSTANCE_COUNT > 0U */

#endif  /*#ifndef _HWA_SCM_H_ */
