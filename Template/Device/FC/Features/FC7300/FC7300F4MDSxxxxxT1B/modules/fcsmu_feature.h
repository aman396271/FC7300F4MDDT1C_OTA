#ifndef _DEVICE_FEATURES_FC7300F4MDSxxxxxT1B_FCSMU_COMMON_H_
#define _DEVICE_FEATURES_FC7300F4MDSxxxxxT1B_FCSMU_COMMON_H_

/**
 * @brief FCSMU channel define.
 *
 */
#define FCSMU_CHANNEL_NONE_MASK                     0x0U
#define FCSMU_CHANNEL_TEMP_ERROR_MASK               0x1U         /* Event from temperature sensor. */
#define FCSMU_CHANNEL_TEMP_ERROR_SHIFT              0U
#define FCSMU_CHANNEL_PMC_ERROR_MASK                0x2U         /* Voltage out of range indication from PMC. */
#define FCSMU_CHANNEL_PMC_ERROR_SHIFT               1U
#define FCSMU_CHANNEL_NVR_ERROR_MASK                0x4U         /* NVR load error. */
#define FCSMU_CHANNEL_NVR_ERROR_SHIFT               2U
#define FCSMU_CHANNEL_STCU_BIST_ERROR_MASK          0x8U         /* STCU MBIST or LBIST fail. */
#define FCSMU_CHANNEL_STCU_BIST_ERROR_SHIFT         3U
#define FCSMU_CHANNEL_LS0_ERROR_MASK                0x10U        /* CPU0 lockstep compare fault. */
#define FCSMU_CHANNEL_LS0_ERROR_SHIFT               4U
#define FCSMU_CHANNEL_SYSTEM_CPU0_ERROR_MASK        0x40U        /* System RAM CPU0 access error. */
#define FCSMU_CHANNEL_SYSTEM_CPU0_ERROR_SHIFT       6U
#define FCSMU_CHANNEL_SYSTEM_NON_CPU_ERROR_MASK     0x200U       /* System RAM None CPU access error. */
#define FCSMU_CHANNEL_SYSTEM_NON_CPU_ERROR_SHIFT    9U
#define FCSMU_CHANNEL_SCM_CPU0_ERROR_MASK           0x400U       /* Matrix Access Monitor ECC check CPU0 error. */
#define FCSMU_CHANNEL_SCM_CPU0_ERROR_SHIFT          10U
#define FCSMU_CHANNEL_SCM_NON_CPU_ERROR_MASK        0x2000U      /* Matrix Access Monitor ECC check non CPU error. */
#define FCSMU_CHANNEL_SCM_NON_CPU_ERROR_SHIFT       13U
#define FCSMU_CHANNEL_CPU0_ECC_ERROR_MASK           0x4000U      /* Including ITCM/DTCM/ICACHE/DCACHE. */
#define FCSMU_CHANNEL_CPU0_ECC_ERROR_SHIFT          14U
#define FCSMU_CHANNEL_SYS_ABNORMAL_ALM_ERROR_MASK   0x20000U     /* System abnormal alarm signals including LBIST active, MBIST active, and Test Mode active. */
#define FCSMU_CHANNEL_SYS_ABNORMAL_ALM_ERROR_SHIFT  17U
#define FCSMU_CHANNEL_SOFTWARE_TRIGGER_ERROR_MASK   0x40000U     /* Software trigger error. */
#define FCSMU_CHANNEL_SOFTWARE_TRIGGER_ERROR_SHIFT  18U
#define FCSMU_CHANNEL_CMU4_FAIL_ERROR_MASK          0x80000U     /* CMU4 failure interrupt. */
#define FCSMU_CHANNEL_CMU4_FAIL_ERROR_SHIFT         19U
#define FCSMU_CHANNEL_CMU_FAIL_ERROR_MASK           0x100000U    /* CMU1/2 failure interrupt. */
#define FCSMU_CHANNEL_CMU_FAIL_ERROR_SHIFT          20U
#define FCSMU_CHANNEL_FLASH_ECC_ERROR_MASK          0x200000U    /* Flash ECC error. */
#define FCSMU_CHANNEL_FLASH_ECC_ERROR_SHIFT         21U
#define FCSMU_CHANNEL_SCG_SYS_PLL_ERROR_MASK        0x400000U    /* PLL loss of lock. */
#define FCSMU_CHANNEL_SCG_SYS_PLL_ERROR_SHIFT       22U
#define FCSMU_CHANNEL_DMA0_AHB_ERROR_MASK           0x800000U    /* DM0 AHB Error. */
#define FCSMU_CHANNEL_DMA0_AHB_ERROR_SHIFT          23U
#define FCSMU_CHANNEL_INTM0_ERROR_MASK              0x2000000U   /* Interrupt Monitor error. */
#define FCSMU_CHANNEL_INTM0_ERROR_SHIFT             25U
#define FCSMU_CHANNEL_FMC_ERROR_MASK                0x10000000U  /* ECC error. */
#define FCSMU_CHANNEL_FMC_ERROR_SHIFT               28U
#define FCSMU_CHANNEL_SCG_CRC_ERROR_MASK            0x20000000U  /* CRC check error. */
#define FCSMU_CHANNEL_SCG_CRC_ERROR_SHIFT           29U
#define FCSMU_CHANNEL_SCM_CRC_ERROR_MASK            0x40000000U  /* CRC check error. */
#define FCSMU_CHANNEL_SCM_CRC_ERROR_SHIFT           30U
#define FCSMU_CHANNEL_MAM_WDG_ERROR_MASK            0x80000000U  /* MAM0/1/2 master access time out error. */
#define FCSMU_CHANNEL_MAM_WDG_ERROR_SHIFT           31U

#endif /* _DEVICE_FEATURES_FC7300F4MDSxxxxxT1B_FCSMU_COMMON_H_ */
