#ifndef _DEVICE_FEATURES_FC7300F4MDDxxxxxT1B_FTU_COMMON_H_
#define _DEVICE_FEATURES_FC7300F4MDDxxxxxT1B_FTU_COMMON_H_

/************ FTU Features **************/

/** Number of instances of the FTU module. */
#define FTU_INSTANCE_COUNT                       (10u)
/** Array initializer of FTU peripheral base addresses */
#define FTU_BASE_ADDRS                           {FTU0_BASE, FTU1_BASE, FTU2_BASE, FTU3_BASE, FTU4_BASE, FTU5_BASE, FTU6_BASE, FTU7_BASE, FTU8_BASE, FTU9_BASE}
/** Array initializer of FTU peripheral base pointers */
#define FTU_BASE_PTRS                            {FTU0, FTU1, FTU2, FTU3, FTU4, FTU5, FTU6, FTU7, FTU8, FTU9}
#endif /* _DEVICE_FEATURES_FC7300F4MDDxxxxxT1B_FTU_COMMON_H_ */

#define FTU_TCKSEL_EXIST
#define FTU_FAULT_INPUT_COUNT(base)               2U
#define FTU_GET_MAX_COUNTER(base)                 0xFFFFu
#define FTU_INSTANCE_QD_SUPPORT(base)             ((((uint32_t)base) == FTU1_BASE) || (((uint32_t)base) == FTU2_BASE) || (((uint32_t)base) == FTU4_BASE) || (((uint32_t)base) == FTU5_BASE) ? 1 : 0)
#define FTU_GTB_CTRL_IN_SCM
