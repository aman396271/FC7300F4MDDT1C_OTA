/**
*  @file module_driver_pmc.h
* @author Flagchip032
* @brief FC7xxx PMC driver type definition and API
* @version 2.0.0
 * @date 2024-08-20
*
* @copyright Copyright (c) 2022 Flagchip Semiconductors Co., Ltd.
*
*/
/* ********************************************************************************
   *   Revision History:
   *
   *   Version     Date          Initials      CR#          Descriptions
   *   ---------   ----------    ------------  ----------   ---------------
   *   0.1.0       2023-12-15    Flagchip032   N/A          First version for FC7300
   *   2.0.0       2024-10-12    Flagchip032   N/A          Change version and release
   ******************************************************************************** */
#ifndef _DRIVER_MODULE_DRIVER_PMC_H_
#define _DRIVER_MODULE_DRIVER_PMC_H_
#include "HwA_pmc.h"

#if PMC_INSTANCE_COUNT > 0U

#if defined(__cplusplus)
extern "C" {
#endif


/**
 * @addtogroup module_driver_pmc
 * @{
 */

/**
 * @name  PMC API Service IDs
 *
 * @{
 */
#define PMC_INIT_ID     0x00U
/** @}*/

/**
 * @name  PMC Dev Error Code
 * @brief Error Code of calling PCC apis
 *
 * @{
 */
#define PMC_E_PARAM_INSTANCE               0x01U
#define PMC_E_PARAM_POINTER                0x02U
/** @}*/

/**
 * @name  PMC interrupt mask micros
 *
 * @{
 */
#define LVD_INTERRUPT  PMC_CONFIG_LVD_IE_MASK
#define HVD_INTERRUPT  PMC_CONFIG_HVD_IE_MASK
/* @} */

/* @} */


/***************** typedef *********************/
/**
 * @brief PMC fault type.
 * This provides constants for the PMC fault type for use in the PMC interrupt callback functions.
 */
typedef enum
{
    PMC_NONE = 0,       /**< PMC no fault */
    PMC_HVD5V,          /**< PMC HVD5V fault */
#if PMC_HVD5VB_SUPPORT
    PMC_HVD5VB,          /**< PMC HVD5V fault */
#endif /* PMC_HVD5VB_SUPPORT */
    PMC_HVD2P5V,        /**< PMC HVD2P5V fault */
    PMC_HVD1P1V,        /**< PMC HVD1P1V fault */
    PMC_LVD5V,          /**< PMC LVD5V fault */
#if PMC_V15_CTRL_SUPPORT
    PMC_LVD1P5V,        /**< PMC LVD1P5V fault */
    PMC_HVD1P5V         /**< PMC HVD1P5V fault */
#endif /* PMC_V15_CTRL_SUPPORT */
} PMC_Fault_Type;

/**
 * @brief PMC voltage flags.
 * 
 */
typedef enum
{
    PMC_HVD5V_FLAG       = PMC_LVSCR_HVD5V_FLAG_MASK,       /**< interrupt flag on V5 domain in FPM */
#if PMC_HVD5VB_SUPPORT
    PMC_HVD5VB_FLAG      = PMC_LVSCR_HVD5VB_FLAG_MASK,      /**< interrupt flag on V5B domain in FPM */
#endif /* PMC_HVD5VB_SUPPORT */
    PMC_HVD2P5V_FLAG     = PMC_LVSCR_HVD2P5V_FLAG_MASK,     /**< interrupt flag on V25 domain in FPM */
    PMC_HVD1P1V_FLAG     = PMC_LVSCR_HVD1P1V_FLAG_MASK,     /**< interrupt flag on V11 domain in FPM */
    PMC_LVD5V_FLAG       = PMC_LVSCR_LVD5V_FLAG_MASK,       /**< interrupt flag on V5 domain in FPM */
#if PMC_V15_FLAG_SUPPORT
    PMC_LVD1P5V_FLAG     = PMC_LVSCR_LVD1P5V_FLAG_MASK,     /**< interrupt flag on V15 domain in FPM */
    PMC_HVD1P5V_FLAG     = PMC_LVSCR_HVD1P5V_FLAG_MASK,     /**< interrupt flag on V15 domain in FPM */
#endif /* PMC_V15_FLAG_SUPPORT */
    PMC_LVR5V_FPM_FLAG   = PMC_LVSCR_LVR5V_FPM_FLAG_MASK,   /**< Low voltage reset flag of V5 domain in FPM */
    PMC_LVR5V_RPM_FLAG   = PMC_LVSCR_LVR5V_RPM_FLAG_MASK,   /**< Low voltage reset flag of V5 domain in RPM */
#if PMC_HVD5VB_SUPPORT
    PMC_LVR5VB_FPM_FLAG  = PMC_LVSCR_LVR5VB_FPM_FLAG_MASK,  /**< Low voltage reset flag of V5B domain in FPM  */
    PMC_LVR5VB_RPM_FLAG  = PMC_LVSCR_LVR5VB_RPM_FLAG_MASK,  /**< Low voltage reset flag of V5B domain in RPM */
#endif /* PMC_HVD5VB_SUPPORT */
    PMC_LVR2P5V_FPM_FLAG = PMC_LVSCR_LVR2P5V_FPM_FLAG_MASK, /**< Low voltage reset flag of V25 domain in FPM */
    PMC_LVR2P5V_RPM_FLAG = PMC_LVSCR_LVR2P5V_RPM_FLAG_MASK, /**< Low voltage reset flag of V25 domain in RPM */
    PMC_LVR1P1V_FPM_FLAG = PMC_LVSCR_LVR1P1V_FPM_FLAG_MASK, /**< Low voltage reset flag of V11 domain in FPM */
    PMC_LVR1P1V_RPM_FLAG = PMC_LVSCR_LVR1P1V_RPM_FLAG_MASK, /**< Low voltage reset flag of V11 domain in RPM */
#if PMC_VX_DOUBLE_FLAG_SUPPORT
    PMC_V25DOUBLE_FLAG   = PMC_LVSCR_V25DOUBLE_FLAG_MASK,  /**< V25 double voltage flag */
    PMC_V11DOUBLE_FLAG   = PMC_LVSCR_V11DOUBLE_FLAG_MASK,  /**< V11 double voltage flag */
#endif /* PMC_VX_DOUBLE_FLAG_SUPPORT */
    PMC_POR_FLAG         = PMC_LVSCR_POR_FLAG_MASK          /**< POR flag */
} PMC_FlagType;

/**
 * @brief PMC voltage status.
 * 
 */
typedef enum
{
    PMC_HVD5V_STATUS   = PMC_LVSCR_HVD5V_STATUS_MASK,             /**< HVD5V status on V5 domain in FPM */
#if PMC_HVD5VB_SUPPORT
    PMC_HVD5VB_STATUS  = PMC_LVSCR_HVD5VB_STATUS_MASK,            /**< HVD5VB status on V5B domain in FPM */
#endif /* PMC_HVD5VB_SUPPORT */
    PMC_HVD2P5V_STATUS = PMC_LVSCR_HVD2P5V_STATUS_MASK,           /**< HVD25 status on V25 domain in FPM */
    PMC_HVD1P1V_STATUS = PMC_LVSCR_HVD1P1V_STATUS_MASK,           /**< HVD11 status on V11 domain in FPM */
    PMC_LVD5V_STATUS   = PMC_LVSCR_LVD5V_STATUS_MASK,             /**< LVD5V status on V5 domain in FPM */
#if PMC_V15_STATUS_SUPPORT
    PMC_LVD1P5V_STATUS = PMC_LVSCR_LVD1P5V_STATUS_MASK,           /**< LVD1P5V status on V15 domain in FPM */
    PMC_HVD1P5V_STATUS = PMC_LVSCR_HVD1P5V_STATUS_MASK,           /**< HVD1P5V status on V15 domain in FPM */
    PMC_V15_STATUS     = PMC_LVSCR_V15_STATUS_MASK                /**< V11 Supply Driver Status */
#endif
#if PMC_V11_STATUS_SUPPORT
    PMC_V11_STATUS     = PMC_LVSCR_V11_STATUS_MASK                /**< V11 Supply Driver Status */
#endif
} PMC_StatusType;

/**
 * @brief The interrupt enable/disable mask of PMC
 *
 */
typedef enum
{
    PMC_INTR_MASK_HVD = 1U,            /**< interrupt mask of HVD */
    PMC_INTR_MASK_LVD = 2U             /**< interrupt mask of LVD */
} PMC_IntrMaskType;

/**
 * @brief The structure of the SCG processing handle
 *
 */
typedef struct _PMC_HandleType
{
    void (*pPmcFaultNotify)(struct _PMC_HandleType *pHandle, PMC_Fault_Type eFault);    /**< PMC fault interrupt callback */
    void (*pPmcRecoveryNotify)(struct _PMC_HandleType *pHandle, PMC_Fault_Type eFault); /**< PMC recovery fault interrupt callback */
} PMC_HandleType;

/** @brief Pmc control type */
typedef struct
{
#if PMC_HVD5VB_SUPPORT
    boolean b5VBMonEn;                /**< bit6, VDD5V_B LVR monitor enable during RPM */
#endif /* PMC_HVD5VB_SUPPORT */
#if PMC_V15_CTRL_SUPPORT
    boolean bV15CtrlEn;               /**< bit5, V15 controller with on board NPN enable */
    boolean bV15AutoswEn;             /**< bit4, V15 auto switch enable */
#endif
    boolean bRpmV25En;                /**< bit3, V25 domain enable during RPM  */
    uint32_t u32InterruptMask;          /**< interrupt enable mask */
    void (*pPmcFaultNotify)(PMC_HandleType *pHandle, PMC_Fault_Type eFault);    /**< PMC fault interrupt callback */
    void (*pPmcRecoveryNotify)(PMC_HandleType *pHandle, PMC_Fault_Type eFault); /**< PMC recovery interrupt callback */
} PMC_ConfigType;

/***************** API *********************/
/**
 * @brief PMC get status flag
 *
 * This function returns the state of a status flag.
 *
 * @param eFlag PMC flag type
 * @return true the flag bit is 1,false the flag bit is 0
 */
bool PMC_GetFlag(PMC_FlagType eFlag);

/**
 * @brief PMC clears an individual status flag.
 *
 * This function clears an individual status flag (see pmc_status_flag_t for list of status bits).
 *
 * @param eFlag PMC flag type
 */
void PMC_ClearFlag(PMC_FlagType eFlag);

/**
 * @brief PMC get status
 *
 * @param eStatus the status type
 * @return true the status bit return 1
 * @return false the status bit return 0
 */
bool PMC_GetStatus(PMC_StatusType eStatus);

/**
 * @brief Enable PMC interrupt
 * @param the parameter of interrupt flag
 */
void Pmc_EnableInterrupt(uint32 u32Val);

/**
 * @brief Disable PMC interrupt
 * @param the parameter of interrupt flag
 */
void Pmc_DisableInterrupt(uint32 u32Val);

/**
 * @brief PMC Init
 *
 * @param pPmcHandle Pmc handle
 * @param pIntCfg    Pmc initialize configuration
 */
void Pmc_Init(PMC_HandleType* pPmcHandle, PMC_ConfigType *pIntCfg);

/**
 * @brief Clear all PMC register
 *
 */
void PMC_Deinit(void);

/**
 * @brief PMC_UserIRQHandler function
 * Customer needs to write this function according by customer's requirement. This function is only resolve compile conflict
 *
 * @param pPmcHandle Pmc handle
 *
 */
void PMC_UserIRQHandler(PMC_HandleType* pPmcHandle);


#if defined(__cplusplus)
}
#endif
/** @}*/  /* module_driver_pmc */

#endif /* #if PMC_INSTANCE_COUNT > 0U */

#endif
