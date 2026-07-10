/**
 * @file module_driver_eftu_cmu.h
 * @author flagchip
 * @brief eFTU cmu driver type definition and API
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
   *   0.1.0       2023-12-15    Flagchip032   N/A          First version for FC7300
   *   2.0.0       2024-10-12    Flagchip070   N/A          Change version and release
   ******************************************************************************** */


#ifndef DRIVER_INCLUDE_MODULE_DRIVER_EFTU_CMU_H_
#define DRIVER_INCLUDE_MODULE_DRIVER_EFTU_CMU_H_

#include "hwa_eftu_cmu.h"
#include "module_driver_eftu.h"
#if defined(EFTU_INSTANCE_COUNT) && (EFTU_INSTANCE_COUNT > 0)
#define EFTU_CMU_MODULE_ID  				0U

/**
 * @name  CMU API Service IDs
 *
 * @{
 */
#define EFTU_CMU_INIT_ID					0U
#define EFTU_CMU_SET_CMUCLK_ID				1U
#define EFTU_CMU_SET_ECLK_ID				2U
#define EFTU_CMU_SET_CLK8_ID				3U
#define EFTU_CMU_ENABLE_CLK_ID				4U
#define EFTU_CMU_DISABLE_CLK_ID				5U
/** @}*/

/** @}*/
/**
 * @name  CMU Dev Error Code
 * @brief Error Code of calling CMU apis
 *
 * @{
 */
#define EFTU_CMU_UNINIT							0U
#define EFTU_CMU_E_PARAM_CHANNEL				1U
#define EFTU_CMU_E_PARAM_COUNT					2U
#define EFTU_CMU_E_PARAM_INVALID				3U
#define EFTU_CMU_E_PARAM_INVALID_VALUE			4U
/** @}*/


typedef struct _EFTU_CMU_HandleType
{
    float fBusClock;				/*User provides*/
    float fGlobalClock; 			/*User provides*/

    struct
    {
        EFTU_CMU_Type * pCmu;
        float afExternalClock[2];
        float fCmuClock[EFTU_INSTANCE_COUNT][8];
        float fClock8;
    }tStatus;

} EFTU_CMU_HandleType;





/**
 * @brief Cmu Global clock configuration.
 * @param pCmuHandle EFTU CMU processing handle
 */
void EFTU_CMU_Init(EFTU_CMU_HandleType *pCmuHandle);

/**
 * @brief Cmu external clock configuration.
 * @param pCmuHandle EFTU CMU processing handle
 * @param eEclk      Cmu external clock Index
 * @param fFrequence Cmu external clock frequency
 */
void EFTU_CMU_SetEClock(EFTU_CMU_HandleType *pCmuHandle,EFTU_CMU_ClkSrcType eEclk, float fFrequence);

/**
 * @brief Cmu  clock configuration.
 * @param pCmuHandle EFTU CMU processing handle
 * @param eClk      Cmu clock Index
 * @param eClockSource Cmu clock source
 * @param fFrequence Cmu  clock frequency
 */
void EFTU_CMU_SetCmuClock(EFTU_CMU_HandleType *pCmuHandle, EFTU_CMU_ClkSrcType eClk,EFTU_CMU_ClkCtrlSrcType eClockSource, float fFrequence);

/**
 * @brief Cmu clock 8 configuration.
 * @param pCmuHandle EFTU CMU processing handle
 * @param eCmu8ClockSrc      Cmu clock 8 source
 */
void EFTU_CMU_SetCmuClk8Src(EFTU_CMU_HandleType *pCmuHandle, EFTU_CMU_Clk8CtrlSrcType eCmu8ClockSrc);

/**
 * @brief Enable Cmu clock
 * @param pCmuHandle EFTU CMU processing handle
 * @param eChannel  Clock Index
 */
void EFTU_CMU_EnableClock(EFTU_CMU_HandleType *pCmuHandle, EFTU_CMU_ClkSrcType eChannel);

/**
 * @brief Disable Cmu clock
 * @param pCmuHandle EFTU CMU processing handle
 * @param eChannel  Clock Index
 */
void EFTU_CMU_DisableClock(EFTU_CMU_HandleType *pCmuHandle, EFTU_CMU_ClkSrcType eChannel);

#endif /* defined(EFTU_INSTANCE_COUNT) && (EFTU_INSTANCE_COUNT > 0) */

#endif /*#ifndef _DRIVER_EFTU_CMU_H_*/
