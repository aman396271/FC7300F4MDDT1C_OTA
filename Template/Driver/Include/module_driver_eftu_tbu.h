/**
 * @file module_driver_eftu_tbu.h
 * @author flagchip
 * @brief eFTU tbu driver type definition and API
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


#ifndef DRIVER_INCLUDE_MODULE_DRIVER_EFTU_TBU_H_
#define DRIVER_INCLUDE_MODULE_DRIVER_EFTU_TBU_H_

#include "hwa_eftu_tbu.h"
#include "module_driver_eftu.h"

#if defined(EFTU_INSTANCE_COUNT) && (EFTU_INSTANCE_COUNT > 0)


typedef struct  /* Only for TS0 */
{
    EFTU_TBU_ClkSrcType eClkSrc;
    uint32_t u32InitialValue;
    EFTU_TBU_Ch0ResType eResolution;
    bool bEnable;
} EFTU_TBU_Ts0ChannelConfigStruct;


typedef struct  /* For TS 1/2 */
{
	EFTU_TBU_ChnCntType eChannel; /*Only for counter 1/2*/
    EFTU_TBU_ClkSrcType eClkSrc;
    uint32_t u32InitialValue;
    bool bEnable;
}EFTU_TBU_Ts12ChannelConfigStruct;

typedef struct   /* Only for TS 3*/
{
    EFTU_TBU_QDModeType TbuCnt3QDMode;
	EFTU_TBU_QDInputSrcType  eTbuch3CounterSrc;
	uint32_t  u32Modulo;
} EFTU_TBU_QDConfigStruct;

#if EFTU_EAC_SUPPORT == STD_ON

/*
*@brief Select the measuremnt edge.
*/
typedef enum
{
    EFTU_TBU_EAC_RISING_EDGE = 1U,
    EFTU_TBU_EAC_FALLING_EDGE,
    EFTU_TBU_EAC_BOTH_EDGE
} EFTU_TBU_EACEdgeSelect;

/*
*@brief Select the TCR Clock Frequency
*/
typedef enum
{
    EFTU_TBU_EAC_TCR_CLOCK_DIV_NOT_USED = 0U,
    EFTU_TBU_EAC_TCR_CLOCK_DIV_2 = 1U,
    EFTU_TBU_EAC_TCR_CLOCK_DIV_4 = 2U,
    EFTU_TBU_EAC_TCR_CLOCK_DIV_8 = 3U,
}EFTU_TBU_EACTcrDivType;

/*
*@brief Filter Prescaler Clock Control
*/
typedef enum
{
    EFTU_TBU_EAC_TCR_SAMPLE_DIV_2 = 0U,     
    EFTU_TBU_EAC_TCR_SAMPLE_DIV_4   ,
    EFTU_TBU_EAC_TCR_SAMPLE_DIV_8   ,
    EFTU_TBU_EAC_TCR_SAMPLE_DIV_16  ,
    EFTU_TBU_EAC_TCR_SAMPLE_DIV_32  ,
    EFTU_TBU_EAC_TCR_SAMPLE_DIV_64  ,
    EFTU_TBU_EAC_TCR_SAMPLE_DIV_128 ,
    EFTU_TBU_EAC_TCR_SAMPLE_DIV_256 ,
}EFTU_TBU_EACFpsck;

typedef struct 
{
    boolean bUpdateErrCnt;                    
    boolean bHaltInDebug;
    struct Tcr_Pin_ConfigType
    {
        EFTU_TBU_EACEdgeSelect  eEacEdgeSelect;
        EFTU_TBU_EACTcrDivType  eTcrDiv;
        EFTU_TBU_EACFpsck       eFpsck;
    }activeEdge;

}EFTU_TBU_EAC_ConfigType;



void EFTU_TBU_EAC_Init(EFTU_TBU_InstanceType eInstance, EFTU_TBU_EAC_ConfigType *pConfig);

#endif


/**
 * @brief Set Timestamp Counter 0 configuration
 * @param eInstance 	TBU Instance Index
 * @param pConfig Timestamp 0 InitStruct
 */
void EFTU_TBU_SetTS0(EFTU_TBU_InstanceType eInstance, EFTU_TBU_Ts0ChannelConfigStruct *pConfig);

/**
 * @brief Set Timestamp Counter 1/2 configuration
 * @param eInstance TBU Instance Index
 * @param pConfig Timestamp 1/2 InitStruct
 */
void EFTU_TBU_SetTS12(EFTU_TBU_InstanceType eInstance,  EFTU_TBU_Ts12ChannelConfigStruct *pConfig);

/**
 * @brief Set Timestamp Counter 3 configuration
 * @param eInstance TBU Instance Index
 * @param pConfig Orthogonal decoding InitStruct
 */
void EFTU_TBU_SetQD(EFTU_TBU_InstanceType eInstance, EFTU_TBU_QDConfigStruct *pConfig);


/**
 * @brief Get the QD Counter
 * @param eInstance TBU Instance Index
 * @return The QD counter
 */
uint32_t  EFTU_TBU_GetQDCounter(EFTU_TBU_InstanceType  eInstance);

/**
 * @brief Get the QD Counter Capture Value.
 * @param eInstance TBU Instance Index
 * @return The QD Counter Capture Value.
 */
uint32_t EFTU_TBU_GetQDCapture(EFTU_TBU_InstanceType  eInstance);


#endif /* defined(EFTU_INSTANCE_COUNT) && (EFTU_INSTANCE_COUNT > 0) */
#endif /*#ifndef _DRIVER_EFTU_TBU_H_*/
