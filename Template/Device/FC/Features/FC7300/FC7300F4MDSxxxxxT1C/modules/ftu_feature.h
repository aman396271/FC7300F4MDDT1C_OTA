#ifndef _DEVICE_FEATURES_FC7300F4MDSxxxxxT1C_FTU_COMMON_H_
#define _DEVICE_FEATURES_FC7300F4MDSxxxxxT1C_FTU_COMMON_H_

/************ FTU Features **************/

/** Number of instances of the FTU module. */
#define FTU_INSTANCE_COUNT                       (6u)
/** Array initializer of FTU peripheral base addresses */
#define FTU_BASE_ADDRS                           {FTU0_BASE, FTU1_BASE, FTU2_BASE, FTU3_BASE, FTU4_BASE, FTU5_BASE}
/** Array initializer of FTU peripheral base pointers */
#define FTU_BASE_PTRS                            {FTU0, FTU1, FTU2, FTU3, FTU4, FTU5}

#define FTU_TCKSEL_EXIST
#define FTU_FAULT_INPUT_COUNT(base)               2U
#define FTU_GET_MAX_COUNTER(base)                 ((((uint32_t)base) == FTU1_BASE) || (((uint32_t)base) == FTU2_BASE) ? 0xFFFFFFU : 0xFFFF)
#define FTU_INSTANCE_QD_SUPPORT(base)             ((((uint32_t)base) == FTU1_BASE) || (((uint32_t)base) == FTU2_BASE) ? 1 : 0)
#define FTU_GTB_CTRL_IN_SCM
#define FTU_FDUTYCTL_EXIST
#define FTU_CNT_SEL_EXIST
#define FTU_FAULT_DIS_DELAY_FEATURE
#define FTU_ICM_FEATURE
#define FTU_UPDOWN_DIS_FEATURE
#define FTU_GTB_ADVANCED_CTRL
#define FTU_GTB_CTRL_IN_SCM

#endif /* _DEVICE_FEATURES_FC7300F4MDSxxxxxT1C_FTU_COMMON_H_ */
