/**
 * @file module_driver_scm.h
 * @author Flagchip
 * @brief SCM driver type definition and API
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
   *   0.1.0       2023-12-15    Flagchip055   N/A          First version for FC7300
   *   2.0.0       2024-10-12    Flagchip055   N/A          Change version and release
   ******************************************************************************** */

#ifndef _DRIVER_MODULE_DRIVER_SCM_H_
#define _DRIVER_MODULE_DRIVER_SCM_H_

#include "HwA_scm.h"

#if SCM_INSTANCE_COUNT > 0U

/**
 * @addtogroup module_driver_scm
 * @{
 */

/********* Local typedef ************/
/** 
 * @brief SCM return status
 * 
 */
typedef enum
{
    SCM_E_OK     = 0U,  /*!< Return ok */
    SCM_E_NOT_OK        /*!< Return not ok */
} SCM_RetStatusType;

/**
 * @brief SCM CRC trigger mode
 */
typedef enum
{
    SCM_CRC_SOFTWARE_MODE = 0U,   /*!< SCM CRC software mode. */
    SCM_CRC_TRIGGER_MODE  = 1U,   /*!< SCM CRC trigger mode. */
} SCM_CrcModeType;

/********* Local function ************/
/**
 * @brief Get unique identification for the chip, loaded from NVR.
 *
 * @param pUid Pointer to UID
 *
 */
void SCM_GetData_UID(uint32 *pUid);

/**
 * @brief Generate SYS-AP system reset
 *
 * @return void
 */
void SCM_PeformReset_SYSAP(void);

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
SCM_RetStatusType SCM_CrcInit(SCM_CrcModeType eMode);

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
void SCM_CrcGenerate(void);

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
void SCM_SetAdcTriggerSel(SCM_AdcInstance eInstance, SCM_AdcTriggerSel eTriggerSel);

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
void SCM_SetAdcPreTriggerSel(SCM_AdcInstance eInstance, SCM_AdcPreTriggerSel ePreTriggerSel);

/** @}*/

#endif /* #if SCM_INSTANCE_COUNT > 0U */

#endif /* end of _DRIVER_MODULE_DRIVER_SCM_H_ */
