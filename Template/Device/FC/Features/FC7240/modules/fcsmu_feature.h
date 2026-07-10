#ifndef _DEVICE_FEATURES_FC7240_FCSMU_COMMON_H_
#define _DEVICE_FEATURES_FC7240_FCSMU_COMMON_H_

/************ FCSMU Features **************/
/** Number of instances of the FCSMU module. */
#define FCSMU_INSTANCE_COUNT                    (1U)


/** Array initializer of FCSMU peripheral base addresses */
#define FCSMU_BASE_ADDRS                        {FCSMU_BASE}
/** Array initializer of FCSMU peripheral base pointers */
#define FCSMU_BASE_PTRS                         {FCSMU}

/**
 * @brief FCSMU channel define.
 *
 */
#define FCSMU_CHANNEL_NONE_MASK                     0x0U
#define FCSMU_CHANNEL_TEMP_ERROR_MASK               0x1U         /* Event from temperature sensor. */
#define FCSMU_CHANNEL_TEMP_ERROR_SHIFT              0U
#define FCSMU_CHANNEL_PMC_ERROR_MASK                0x2U         /* Voltage out of range indication from PMC. */
#define FCSMU_CHANNEL_PMC_ERROR_SHIFT               1U
#define FCSMU_CHANNEL_MISC_ERROR_MASK               0x4U         /* NVR load error/System abnormal alarm signal, including MBIST active and Test Mode active. */
#define FCSMU_CHANNEL_MISC_ERROR_SHIFT              2U
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
#define FCSMU_CHANNEL_MISC_ERROR1_MASK              0x10000000U  /* FMC_ECC_ERROR/AFCB0&1 monitor error/SRAMx EDC error/HSM error (including SRAM ECC and WDOG). */
#define FCSMU_CHANNEL_MISC_ERROR1_SHIFT             28U
#define FCSMU_CHANNEL_MISC_ERROR2_MASK              0x20000000U  /* SCG and SCM etc. CRC check error. */
#define FCSMU_CHANNEL_MISC_ERROR2_SHIFT             29U
#define FCSMU_CHANNEL_MAM_WDG_ERROR_MASK            0x80000000U  /* MAM0/1/2 master access time out error. */
#define FCSMU_CHANNEL_MAM_WDG_ERROR_SHIFT           31U

#define FCSMU_SOCTRL_DIVEX_SUPPORT
#define FCSMU_STMR_FTTI_SUPPORT
#define FCSMU_STMR_MTE_SUPPORT
#define FCSMU_CRC_CTRL_DONE_SUPPORT

#endif /* _DEVICE_FEATURES_FC7240_FCSMU_COMMON_H_ */
