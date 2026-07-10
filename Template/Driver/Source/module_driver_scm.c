/**
 * @file module_driver_scm.h
 * @author Flagchip
 * @brief csc driver type definition and API
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
   *   2.0.0       2024-08-30    Flagchip055    N/A          Update file structures
   ******************************************************************************** */

#include "module_driver_scm.h"

#if SCM_INSTANCE_COUNT > 0U

/**
 * @brief Get unique identification for the chip, loaded from NVR.
 *
 * @param pUid Pointer to UID
 *
 */
void SCM_GetData_UID(uint32 *pUid)
{
    pUid[0] = SCM_HWA_GetData_UIDL();
    pUid[1] = SCM_HWA_GetData_UIDML();
    pUid[2] = SCM_HWA_GetData_UIDMH();
    pUid[3] = SCM_HWA_GetData_UIDH();
}

#if SCM_CRC_SUPPORT
/**
 * @brief Initializes the CRC module based on the specified mode.
 *
 * This function initializes the CRC module by first deinitializing the CRC registers,
 * generating the original CRC result, and then configuring the CRC module according
 * to the specified mode. If the CRC generation completes successfully, the function
 * enables the CRC trigger, error output, and check features based on the mode.
 *
 * @param eMode The CRC mode to be configured. It can be either `SCM_CRC_TRIGGER_MODE`
 *              or another mode depending on the implementation.
 *
 * @return SCM_RetStatusType Returns `SCM_E_OK` if the CRC initialization is successful.
 *                           Returns `SCM_E_NOT_OK` if a timeout occurs during CRC generation.
 */
SCM_RetStatusType SCM_CrcInit(SCM_CrcModeType eMode)
{
    SCM_RetStatusType eStatusVal = SCM_E_OK;
    uint32_t u32Timeout = 0xFFFFU;

    /* Deinit CRC register */
    SCM_HWA_SetCrcGenerateEnable(false);
    SCM_HWA_SetCrcCheckEnable(false);
    SCM_HWA_SetCrcTriggerEnable(false);
    SCM_HWA_SetCrcErrorOutEnable(false);
    SCM_HWA_ClearCrcErrorFlag();

    /* Generate original CRC result */
    SCM_CrcGenerate();
    while (SCM_HWA_GetCrcDoneFlag() == false)
    {
        u32Timeout--;
        if (u32Timeout == 0U)
        {
            eStatusVal = SCM_E_NOT_OK;
            break;
        }
    }

    if (eStatusVal == SCM_E_OK)
    {
        if (eMode == SCM_CRC_TRIGGER_MODE)
        {
            SCM_HWA_SetCrcTriggerEnable(true);
        }

        /* Generate CRC error output */
        SCM_HWA_SetCrcErrorOutEnable(true);
        /* Generate CRC check */
        SCM_HWA_SetCrcCheckEnable(true);
    }
    return eStatusVal;
}

/**
 * @brief Generates the CRC (Cyclic Redundancy Check) by enabling the CRC generation in the hardware.
 * 
 * This function sets the CRC generation enable bit in the hardware, which initiates the CRC generation process.
 * The CRC is typically used for error detection in data transmission or storage.
 * 
 * @note This function does not return any value and does not take any parameters.
 * 
 * @see SCM_HWA_SetCrcGenerateEnable
 */
void SCM_CrcGenerate(void)
{
    SCM_HWA_SetCrcGenerateEnable(true);
}
#endif /* SCM_CRC_SUPPORT */

#if SCM_ADC_TRIGGER_SEL_SUPPORT
/**
 * @brief Set ADC trigger selection
 * 
 * This function configures the trigger source selection for the specified ADC instance
 * by calling the underlying hardware abstraction layer function.
 * 
 * @param eInstance ADC instance identifier, specifying which ADC module to configure
 * @param eTriggerSel ADC trigger selection enumeration value, specifying the trigger source for ADC conversion
 * 
 * @return None
 */
void SCM_SetAdcTriggerSel(SCM_AdcInstance eInstance, SCM_AdcTriggerSel eTriggerSel)
{
    SCM_HWA_SetAdcTriggerSel(eInstance, eTriggerSel);
}

/**
 * @brief Set ADC pre-trigger selection
 * 
 * This function configures the ADC pre-trigger selection for the specified ADC instance.
 * It calls the hardware abstraction layer function to set the pre-trigger source for ADC conversion.
 * 
 * @param eInstance ADC instance identifier specifying which ADC module to configure
 * @param ePreTriggerSel ADC pre-trigger selection configuration specifying the pre-trigger source
 * 
 * @return None
 */
void SCM_SetAdcPreTriggerSel(SCM_AdcInstance eInstance, SCM_AdcPreTriggerSel ePreTriggerSel)
{
    SCM_HWA_SetAdcPretriggerSel(eInstance, ePreTriggerSel);
}
#endif

#endif /* #if SCM_INSTANCE_COUNT > 0U */

