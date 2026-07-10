/*
 * module_driver_eftu_spe.h
 *
 *  Created on: 2025年12月3日
 *      Author: qxw0076
 */

#ifndef TEMPLATE_DRIVER_INCLUDE_MODULE_DRIVER_EFTU_SPE_H_
#define TEMPLATE_DRIVER_INCLUDE_MODULE_DRIVER_EFTU_SPE_H_

#include "HwA_eftu_spe.h"

#if (EFTU_INSTANCE_COUNT > 0U) && (EFTU_SPE_SUPPORT == STD_ON) && defined(EFTU_SPE_SUPPORT)

typedef struct _EFTU_SPE_HandleType
{
    EFTU_SPE_HallPattern *pgHallPatTable;
    EFTU_SPE_OutPattern  *pgOutputPartten;
    EFTU_SPE_InstanceType egSpeInstance;
    boolean               bNewInputIrqStatus;
    boolean               bDirChangeIrqStatus;
    boolean               bErrInputIrqStatus;
    boolean               bBouncingInputIrqStatus;
    boolean               bCntCompareIrqStatus;

    void (*pSpeIrqCallback)(struct _EFTU_SPE_HandleType *pHandle);

} EFTU_SPE_HandleType;

typedef struct
{
    boolean              bFastShutEn;
    uint8                u8Shutofflevel;
    EFTU_SPE_FastShutSrc eShutSrc;
} EFTU_SPE_FastShutStruct;

typedef struct
{
    EFTU_SPE_UpdateTriggerType   eUpdateTrigger;
    EFTU_SPE_UpdateExTriggerType eUpdateExTrigger;

    boolean                bTriggerDelayEn;
    uint8                  u8Delaytime;
    EFTU_SPE_DelayClockSrc eDelayClkSrc;
} EFTU_SPE_TriggerStruct;

typedef enum
{
    EFTU_SPE_FOWARD  = 0U,
    EFTU_SPE_REVERSE = 1U,
} EFTU_SPE_RotationType;

typedef struct
{
    EFTU_SPE_HallPattern *pHallPatTable;

    EFTU_SPE_OutPattern *pOutputPartten;

    EFTU_SPE_OutPattern *tOutputStopPat6;
    EFTU_SPE_OutPattern *tOutputStopPat7;

    EFTU_SPE_InstanceType eSpeInstance;
    boolean               bIrqOnNewInput;
    boolean               bIrqOnDirChange;
    boolean               bIrqOnErrInput;
    boolean               bIrqOnBouncing;
    boolean               bIrqOnCntCompare;

    uint32                   u32Cmpcnt;
    EFTU_SPE_RefSelectType   eSpeRefSrc;
    EFTU_SPE_FastShutStruct *tFastShutStruct;
    EFTU_SPE_TriggerStruct  *tTriggerStruct;
    void (*pSpeIrqCallback)(struct _EFTU_SPE_HandleType *pHandle);

} EFTU_SPE_InitStruct;

typedef enum
{
    EFTU_SPE_STOP_PATTERN_6 = 0U,
    EFTU_SPE_STOP_PATTERN_7 = 0U,
} EFTU_SPE_StopType;

void Eftu_SPE_Init(EFTU_SPE_HandleType *pSpeHandle, EFTU_SPE_InitStruct *pSpeInitStruct);

void Eftu_SPE_SetCmd(EFTU_SPE_HandleType *pSpeHandle, EFTU_SPE_ControlCmd eSpeCmd);

void Eftu_SPE_SoftwareTrigger(EFTU_SPE_HandleType *pSpeHandle);

void Eftu_SPE_Start(EFTU_SPE_HandleType *pSpeHandle, EFTU_SPE_RotationType eRationType);

void Eftu_SPE_Stop(EFTU_SPE_HandleType *pSpeHandle, EFTU_SPE_StopType eStopOutPattern);

void Eftu_SPE_DeInit(EFTU_SPE_HandleType *pSpeHandle);

void EFTU_SPE_IrqHandler(EFTU_SPE_HandleType *pSpeHandle);
#endif /* (EFTU_INSTANCE_COUNT > 0U) && (EFTU_SPE_SUPPORT == STD_ON) && defined(EFTU_SPE_SUPPORT)*/

#endif /* TEMPLATE_DRIVER_INCLUDE_MODULE_DRIVER_EFTU_SPE_H_ */
