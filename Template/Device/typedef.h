/**
 * @file typedef.h
 * @author Flagchip
 * @brief type defines
 * @version 2.0.0
 * @date 2023-09-20
 *
 * SDK Version: 2.6.0
 *

 * @copyright Copyright (c) 2020-2024 Flagchip Semiconductors Co., Ltd.
 *
 */
#ifndef DEVICE_TYPEDEF_H_
#define DEVICE_TYPEDEF_H_


#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include "v_def.h"
#include "compiler.h"

#define STD_ON                   1
#define STD_OFF                  0

#ifdef NDEBUG
    #define DEV_ASSERT(x) ((void)0)
#else
    #define DEV_ASSERT(x) do{}while((x) != 1)
#endif

#ifndef __IO
#define __IO volatile
#endif

#ifndef __I
#define __I const
#endif

#endif /* DEVICE_TYPEDEF_H_ */
