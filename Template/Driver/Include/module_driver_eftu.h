/**
 * @file module_driver_eftu.h
 * @author flagchip
 * @brief eFTU driver type definition and API
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

#ifndef _FC500_DRIVER_EFTU_H_
#define _FC500_DRIVER_EFTU_H_
#include <stdint.h>
#include "device_header.h"
#include  <math.h>
#if EFTU_INSTANCE_COUNT > 0U


typedef enum
{
	EFTU_INSTANCE_0 = 0U,
#if EFTU_INSTANCE_COUNT > 1
	EFTU_INSTANCE_1,
#endif
#if EFTU_INSTANCE_COUNT > 2
	EFTU_INSTANCE_2
#endif
} EFTU_InstanceType;

typedef struct
{
	EFTU_InstanceType eInstance;
	struct
	{
		float fGlobalClock;
		float aCmuClock[EFTU_CMU_CLKn_CTRL_COUNT];
		float aExtClock[2];
	}tStatus;
} EFTU_HandleType;

extern const uint32_t g_aEftuBaseAddress[EFTU_INSTANCE_COUNT];

#endif

#endif
