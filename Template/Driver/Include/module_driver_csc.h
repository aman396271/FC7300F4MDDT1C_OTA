/**
 * @file module_driver_csc.h
 * @author flagchip
 * @brief csc driver type definition and API
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
#ifndef _DRIVER_MODULE_DRIVER_CSC_H_
#define _DRIVER_MODULE_DRIVER_CSC_H_

#include "HwA_csc.h"

#if CSC0_INSTANCE_COUNT > 0U

/**
 * @addtogroup module_driver_csc
 * @{
 */

/********* Dev Error Report ************/
#ifndef CSC0_DEV_ERROR_REPORT
#define CSC0_DEV_ERROR_REPORT	STD_OFF
#endif

#if CSC0_DEV_ERROR_REPORT == STD_ON
#define CSC0_ReportDevError(func, error) ReportDevError(CSC0_MODULE_ID, func, error)
#endif

/**
 * @name  CSC0 API Service IDs
 * @{
 */
#define CSC0_SET_CLOCK_OUT_ID      0x00U
#define CSC0_SET_AONCLKSRC_ID      0x01U
#define CSC0_GET_CLOCK_FREQ_ID     0x02U
/** @}*/

/**
 * @name  CSC0 Dev Error Code
 * @brief Error Code of calling CSC0 apis
 * @{
 */
#define CSC0_E_PARAM_POINTER   			0x01U
#define CSC0_E_PARAM_OUT_RANGE   		0x02U
/** @}*/

/********* Local defines ************/
#define CSC0_AONCLK_128K      128000U
#define CSC0_AONCLK_32K        32000U
#define CSC0_AONCLK_SOSC_32K   32768U
#define CSC0_AONCLK_1K          1000U


/********* Local typedef ************/
/** 
 * @brief Indicate the clock status for each clock source in clock tree list
 * 
 */
typedef enum
{
    CSC0_CLOCK_UNDEFINE = 0U,  /*!< Clock status undefined from power on  */
    CSC0_CLOCK_DISABLE  = 1U,  /*!< clock source set as disabled  */
    CSC0_CLOCK_VALID    = 2U,  /*!< clock set succeed  */
    CSC0_CLOCK_ERROR    = 3U,  /*!< clock set failed  */
    CSC0_CLOCK_UNKNOWN  = 4U
} CSC0_ClockStatusDef;

/** 
 * @brief CSC0 clock source type for clock infomation querry 
 * 
 */
typedef enum
{
    CSC0_AON32K_CLK    = 0U,  /*!< AON32K_CLK */
    CSC0_RTC_CLK       = 1U,  /*!< RTC_CLK */
    CSC0_AON_CLK       = 2U,  /*!< AON_CLK */
    CSC0_CLKOUT_CLK    = 3U,  /*!< CLKOUT_CLK */
    CSC0_END_OF_CLOCKS = 4U   /*!< End of CSC0 clocks */
} CSC0_ClkSrcType;

/** 
 * @brief CSC return status
 * 
 */
typedef enum
{
    CSC_E_OK     = 0U,  /*!< Return ok */
    CSC_E_NOT_OK        /*!< Return not ok */
} CSC_RetStatusType;

/** 
 * @brief Data type for register CSC0_CLKOUT_CTRL,mainly focus on CLKOUT setting 
 * 
 */
typedef struct
{
    bool bEnable;                      /*!< CSC0 ClockOut enable */
    CSC0_ClockOutSrcType  eClkOutSrc;  /*!< CSC0 ClockOut source select */
    CSC0_ClockOutDivType  eDivider;    /*!< CSC0 ClockOut divide ratio */
} CSC0_ClkoutType;

/** 
 * @brief CSC0_AONCLKSR clock source info
 * 
 */
typedef struct
{
    CSC0_AON32KClkSrcType eAon32KSel;  /*!< CSC0 32 KHz Always-on Clock Source Select */
    CSC0_RTCClkSrcType    eRtcSel;     /*!< CSC0 RTC Clock Source Select */
    CSC0_AONClkSrcType    eAonSel;     /*!< CSC0 AON Clock Source Select */
} CSC0_AONCLKSRType;

/********* Local function ************/
#if CSC0_CLOCKCONFIG_SUPPORT
/**
 * @brief set clock out. with clock out pin configure, the clock would be monitored.
 *        This Function may combined with SCG_ClkOut setting
 *        need to call SCG_SetClkOut,if clock out source set to SCG_CLKOUT. *
 * @param pCsc0ClkOut to Csc0ClkOut instance for clock out configuration
 * @param bLockStatus to lock current register
 *
 * @return Set clock out operation success/failed
 * @note  configuration sequence:
 *           1. Disable CLKOUTEN
 *           2. Set CLKOUTSEL
 *           3. Enable CLKOUTEN
 */
CSC_RetStatusType CSC0_SetClockOut(const CSC0_ClkoutType *const pCsc0ClkOut, bool bLockStatus);

/**
 * @brief set always on clock source configuration include AON32K, RTC, AONCLK clock.
 *
 * @param pAonclkSrcType pointer to AONCLKSR instance for AON clock source configuration
 * @param bLockStatus to lock current register
 *
 * @return Set clock out operation success/failed
 */
CSC_RetStatusType CSC0_SetAonClkSrc(const CSC0_AONCLKSRType *const pAonclkSrcType, bool bLockStatus);

/**
 * @brief Report the clock source status and frequency configured in MCU run time.
 *        The clock frequency and status would change by clock set function.
 *
 * @param eClkkName: the CSC0 clock source to query
 * @param pFreq: frequency variable point to get the frequency value
 * @return true or false. This indicate the clock source status invalid or request clock source out of
 *         range.
 */
CSC_RetStatusType CSC0_GetCSC0ClockFreq(const CSC0_ClkSrcType eClkkName, uint32_t *const pFreq);
#endif /* CSC0_CLOCKCONFIG_SUPPORT */
/** @}*/

#endif /* #if CSC0_INSTANCE_COUNT > 0U */


#endif /* End of _DRIVER_MODULE_DRIVER_CSC_H_ */
