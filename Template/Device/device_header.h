/**
 * @file device_header.h
 * @author Flagchip
 * @brief include all peripheral register files
 * @version 2.0.0
 * @date 2023-09-20
 *
 * SDK Version: 2.6.0
 *

 * @copyright Copyright (c) 2020-2024 Flagchip Semiconductors Co., Ltd.
 *
 */
#ifndef DEVICE_HEADER_H
#define DEVICE_HEADER_H

#define FC7300FxMDxxxxxT1B_DEVICE_START  100U
#define FC7300F8MDT2A320T1B              107U
#define FC7300F8MDT2P176T1B              108U
#define FC7300F4MDD1A320T1B              109U
#define FC7300F4MDD2A320T1B              110U
#define FC7300F4MDD2P176T1B              111U
#define FC7300F4MDD3A320T1B              112U
#define FC7300F4MDD1P176T1B              113U
#define FC7300F4MDS1A320T1B              114U
#define FC7300F4MDS1P176T1B              115U
#define FC7300F4MDS2A320T1B              116U
#define FC7300F4MDS2P176T1B              117U
#define FC7300FxMDxxxxxT1B_DEVICE_END    199U

#define FC7240F2MDSxxxxxT1A_DEVICE_START 200U
#define FC7240F2MDS1P100T1A              200U
#define FC7240F2MDS1P144T1A              201U
#define FC7240F2MDS1P176T1A              202U
#define FC7240F2MDS2P100T1A              203U
#define FC7240F2MDS2P144T1A              204U
#define FC7240F2MDS2P176T1A              205U
#define FC7240F2MDSxxxxxT1A_DEVICE_END   299U

#define FC7300FxMDQxxxxT1B_DEVICE_START  300U
#define FC7300F8MDQ1A320T1B              300U
#define FC7300F8MDQ1A257T1B              301U
#define FC7300F8MDQ1P176T1B              302U
#define FC7300FxMDQxxxxT1B_DEVICE_END    399U

#define FC7300F4MDDxxxxT1C_DEVICE_START  400U
#define FC7300F4MDD1A320T1C              401U
#define FC7300F4MDD1A180T1C              402U
#define FC7300F4MDDxxxxT1C_DEVICE_END    499U

#define FC7300F4MDSxxxxT1C_DEVICE_START  500U
#define FC7300F4MDS1A320T1C              500U
#define FC7300F4MDS1A180T1C              501U
#define FC7300F4MDS1P144T1C              502U
#define FC7300F4MDSxxxxT1C_DEVICE_END    599U

#define ADC_MODULE_ID                    1
#define AFCB_MODULE_ID                   2
#define AONTIMER_MODULE_ID               3
#define CACHE_MODULE_ID                  4
#define CMP_MODULE_ID                    5
#define CMU_MODULE_ID                    6
#define CORDIC_MODULE_ID                 7
#define CRC_MODULE_ID                    8
#define DMA_MODULE_ID                    9
#define EIM_MODULE_ID                    10
#define ENET_MODULE_ID                   11
#define ERM_MODULE_ID                    12
#define FCIIC_MODULE_ID                  13
#define FCPIT_MODULE_ID                  14
#define FCSPI_MODULE_ID                  15
#define FCUART_MODULE_ID                 16
#define FLASH_MODULE_ID                  17
#define FLEXCAN_MODULE_ID                18
#define FTU_MODULE_ID                    19
#define FWM_MODULE_ID                    20
#define GPIO_MODULE_ID                   21
#define HSM_MODULE_ID                    22
#define I2S_MODULE_ID                    23
#define INTM_MODULE_ID                   24
#define ISM_MODULE_ID                    25
#define LIN_MODULE_ID                    26
#define LU_MODULE_ID                     27
#define MAP_MODULE_ID                    28
#define MCM_MODULE_ID                    29
#define MPU_MODULE_ID                    30
#define OSPI_MODULE_ID                   31
#define PCC_MODULE_ID                    32
#define PMC_MODULE_ID                    33
#define PORT_MODULE_ID                   34
#define PTIMER_MODULE_ID                 35
#define RGM_MODULE_ID                    36
#define RTC_MODULE_ID                    37
#define SCG_MODULE_ID                    38
#define SCST_MODULE_ID                   39
#define SEC_MODULE_ID                    40
#define SMC_MODULE_ID                    41
#define SCM_MODULE_ID                    42
#define SYSTICK_MODULE_ID                43
#define TRGSEL_MODULE_ID                 44
#define TSTMP_MODULE_ID                  45
#define WDOG_MODULE_ID                   46
#define WKU_MODULE_ID                    47
#define FREQM_MODULE_ID                  48
#define MB_MODULE_ID                     49
#define SEMA_MODULE_ID                   50
#define EFTU_TOM_MODULE_ID               51
#define TMU_MODULE_ID                    52
#define FCSMU_MODULE_ID                  53
#define EFTU_DTM_MODULE_ID               54
#define HRPWM_MODULE_ID                  55
#define CSC0_MODULE_ID                   56
#define SDDF_MODULE_ID                   57
#define MSC_MODULE_ID                    58
#define SDADC_MODULE_ID                  59
#define HSADC_MODULE_ID                  60
#define SSI_MODULE_ID                    61
#define LDI_MODULE_ID                    62
#define SENT_MODULE_ID                   63
#define QDT_MODULE_ID                    64
#define CRM_MODULE_ID                    65

#include "typedef.h"

#include "_device.h"

/****************** module features *************************/

#if DEVICE_NAME == FC7300F8MDT2A320T1B
#include "FC/Features/FC7300/FC7300F8MDTxxxxxT1B/FC7300F8MDT2A320T1B_feature.h"
#endif
#if DEVICE_NAME == FC7300F8MDT2P176T1B
#include "FC/Features/FC7300/FC7300F8MDTxxxxxT1B/FC7300F8MDT2P176T1B_feature.h"
#endif
#if DEVICE_NAME == FC7300F4MDD1A320T1B
#include "FC/Features/FC7300/FC7300F4MDDxxxxxT1B/FC7300F4MDD1A320T1B_feature.h"
#endif
#if DEVICE_NAME == FC7300F4MDD2A320T1B
#include "FC/Features/FC7300/FC7300F4MDDxxxxxT1B/FC7300F4MDD2A320T1B_feature.h"
#endif
#if DEVICE_NAME == FC7300F4MDD2P176T1B
#include "FC/Features/FC7300/FC7300F4MDDxxxxxT1B/FC7300F4MDD2P176T1B_feature.h"
#endif
#if DEVICE_NAME == FC7300F4MDD3A320T1B
#include "FC/Features/FC7300/FC7300F4MDDxxxxxT1B/FC7300F4MDD3A320T1B_feature.h"
#endif
#if DEVICE_NAME == FC7300F4MDD1P176T1B
#include "FC/Features/FC7300/FC7300F4MDDxxxxxT1B/FC7300F4MDD1P176T1B_feature.h"
#endif
#if DEVICE_NAME == FC7300F4MDS1A320T1B
#include "FC/Features/FC7300/FC7300F4MDSxxxxxT1B/FC7300F4MDS1A320T1B_feature.h"
#endif
#if DEVICE_NAME == FC7300F4MDS1P176T1B
#include "FC/Features/FC7300/FC7300F4MDSxxxxxT1B/FC7300F4MDS1P176T1B_feature.h"
#endif
#if DEVICE_NAME == FC7300F4MDS2A320T1B
#include "FC/Features/FC7300/FC7300F4MDSxxxxxT1B/FC7300F4MDS2A320T1B_feature.h"
#endif
#if DEVICE_NAME == FC7300F4MDS2P176T1B
#include "FC/Features/FC7300/FC7300F4MDSxxxxxT1B/FC7300F4MDS2P176T1B_feature.h"
#endif

#if DEVICE_NAME == FC7240F2MDS1P100T1A
#include "FC/Features/FC7240/FC7240F2MDS1xxxxT1A/FC7240F2MDS1P100T1A_feature.h"
#endif
#if DEVICE_NAME == FC7240F2MDS1P144T1A
#include "FC/Features/FC7240/FC7240F2MDS1xxxxT1A/FC7240F2MDS1P144T1A_feature.h"
#endif
#if DEVICE_NAME == FC7240F2MDS1P176T1A
#include "FC/Features/FC7240/FC7240F2MDS1xxxxT1A/FC7240F2MDS1P176T1A_feature.h"
#endif
#if DEVICE_NAME == FC7240F2MDS2P100T1A
#include "FC/Features/FC7240/FC7240F2MDS2xxxxT1A/FC7240F2MDS2P100T1A_feature.h"
#endif
#if DEVICE_NAME == FC7240F2MDS2P144T1A
#include "FC/Features/FC7240/FC7240F2MDS2xxxxT1A/FC7240F2MDS2P144T1A_feature.h"
#endif
#if DEVICE_NAME == FC7240F2MDS2P176T1A
#include "FC/Features/FC7240/FC7240F2MDS2xxxxT1A/FC7240F2MDS2P176T1A_feature.h"
#endif

#if DEVICE_NAME == FC7300F8MDQ1A320T1B
#include "FC/Features/FC7300/FC7300F8MDQxxxxxT1B/FC7300F8MDQ1A320T1B_feature.h"
#endif
#if DEVICE_NAME == FC7300F8MDQ1A257T1B
#include "FC/Features/FC7300/FC7300F8MDQxxxxxT1B/FC7300F8MDQ1A257T1B_feature.h"
#endif
#if DEVICE_NAME == FC7300F8MDQ1P176T1B
#include "FC/Features/FC7300/FC7300F8MDQxxxxxT1B/FC7300F8MDQ1P176T1B_feature.h"
#endif

#if DEVICE_NAME == FC7300F4MDD1A320T1C
#include "FC/Features/FC7300/FC7300F4MDDxxxxxT1C/FC7300F4MDD1A320T1C_feature.h"
#endif

#if DEVICE_NAME == FC7300F4MDS1A320T1C
#include "FC/Features/FC7300/FC7300F4MDSxxxxxT1C/FC7300F4MDS1A320T1C_feature.h"
#endif

#if DEVICE_NAME == FC7300F4MDS1A180T1C
#include "FC/Features/FC7300/FC7300F4MDSxxxxxT1C/FC7300F4MDS1A180T1C_feature.h"
#endif

#if DEVICE_NAME == FC7300F4MDS1P144T1C
#include "FC/Features/FC7300/FC7300F4MDSxxxxxT1C/FC7300F4MDS1P144T1C_feature.h"
#endif

/****************** module regs *************************/
#if (DEVICE_NAME >= FC7300FxMDxxxxxT1B_DEVICE_START) && \
    (DEVICE_NAME <= FC7300FxMDxxxxxT1B_DEVICE_END)
#include "FC/fc7300fxmdxxxxxxt1b_header.h"
#endif

#if (DEVICE_NAME >= FC7240F2MDSxxxxxT1A_DEVICE_START) && \
    (DEVICE_NAME <= FC7240F2MDSxxxxxT1A_DEVICE_END)
#include "FC/fc7240f2mdsxxxxxt1a_header.h"
#endif

#if (DEVICE_NAME >= FC7300FxMDQxxxxT1B_DEVICE_START) && \
    (DEVICE_NAME <= FC7300FxMDQxxxxT1B_DEVICE_END)
#include "FC/fc7300f8mdqxxxxxt1b_header.h"
#endif

#if (DEVICE_NAME >= FC7300F4MDDxxxxT1C_DEVICE_START) && \
    (DEVICE_NAME <= FC7300F4MDDxxxxT1C_DEVICE_END)
#include "FC/fc7300f4mddxxxxxt1c_header.h"
#endif

#if (DEVICE_NAME >= FC7300F4MDSxxxxT1C_DEVICE_START) && \
    (DEVICE_NAME <= FC7300F4MDSxxxxT1C_DEVICE_END)
#include "FC/fc7300f4mdsxxxxxt1c_header.h"
#endif

#include "Arm/CMSIS5_590/Core/Include/core_cm7.h"
#include "Arm/cm7/arm_cortex_asm.h"
#include "FC/fclib/fcmath.h"
#include "FC/fclib/fcfunc.h"

#define ReportDevError(module, func, error) \
    {                                       \
        while (true)                        \
        {                                   \
            (void)module;                   \
            (void)func;                     \
            (void)error;                    \
        }                                   \
    }

#endif /* DEVICE_HEADER_H */

/*******************************************************************************
 * EOF
 ******************************************************************************/
