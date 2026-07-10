#ifndef _DEVICE_FEATURES_FC7300F4MDSxxxxxT1B_EIM_COMMON_H_
#define _DEVICE_FEATURES_FC7300F4MDSxxxxxT1B_EIM_COMMON_H_

/**
 * @brief EIM channel number define
 *
 */
#define EIM_CHANNEL_MAM0_S0                     0U      /* Channel 0 SCM Matrix Access Monitor Error Inection0(MAM0_S0) */
#define EIM_CHANNEL_MAM0_S1                     1U      /* Channel 1 SCM Matrix Access Monitor Error Inection1(MAM0_S1) */
#define EIM_CHANNEL_MAM0_S3                     3U      /* Channel 3 SCM Matrix Access Monitor Error Inection3(MAM0_S3) */
#define EIM_CHANNEL_MAM1_S0                     4U      /* Channel 4 SCM Matrix Access Monitor Error Inection4(MAM1_S0) */
#define EIM_CHANNEL_MAM1_S1                     5U      /* Channel 5 SCM Matrix Access Monitor Error Inection5(MAM1_S1) */
#define EIM_CHANNEL_MAM1_S2                     6U      /* Channel 6 SCM Matrix Access Monitor Error Inection6(MAM1_S2) */
#define EIM_CHANNEL_MAM1_S3                     7U      /* Channel 7 SCM Matrix Access Monitor Error Inection7(MAM1_S3) */
#define EIM_CHANNEL_MAM2_S0                     8U      /* Channel 8 SCM Matrix Access Monitor Error Inection8(MAM2_S0) */
#define EIM_CHANNEL_MAM2_S1                     9U      /* Channel 9 SCM Matrix Access Monitor Error Inection9(MAM2_S1) */
#define EIM_CHANNEL_MAM2_S2                     10U     /* Channel 10 SCM Matrix Access Monitor Error Inection10(MAM2_S2) */
#define EIM_CHANNEL_CPU0_AHBM                   11U     /* Channel 11 SCM Matrix Access Monitor Error Inection11(CPU0_AHBM) */
#define EIM_CHANNEL_CPU0_AHBP                   12U     /* Channel 12 SCM Matrix Access Monitor Error Inection12(CPU0_AHBP) */
#define EIM_CHANNEL_HSM                         18U     /* Channel 18 SCM Matrix Access Monitor Error Inection18(HSM) */
#define EIM_CHANNEL_DMA0                        19U     /* Channel 19 SCM Matrix Access Monitor Error Inection19(DMA0) */
#define EIM_CHANNEL_CPU0_AHBS                   21U     /* Channel 21 SCM Matrix Access Monitor Error Inection21(CPU0_AHBS) */
#define EIM_CHANNEL_CPU0_ITCM                   24U     /* Channel 24 CPU0 ITCM Injection */
#define EIM_CHANNEL_CPU0_DTCM0                  25U     /* Channel 25 CPU0_DTCM0 Injection */
#define EIM_CHANNEL_SRAM0                       33U     /* Channel 33 SRAM0 Injection */
#define EIM_CHANNEL_SRAM1                       34U     /* Channel 34 SRAM1 Injection */
#define EIM_CHANNEL_SRAM2                       35U     /* Channel 35 SRAM2 Injection */
#define EIM_CHANNEL_CPU0_DCACHE_DATA0_01        36U     /* Channel 36 CPU0_DCACHE_DATA0_01 Injection */
#define EIM_CHANNEL_CPU0_DCACHE_DATA0_23        37U     /* Channel 37 CPU0_DCACHE_DATA0_23 Injection */
#define EIM_CHANNEL_CPU0_DCACHE_DATA1_01        38U     /* Channel 38 CPU0_DCACHE_DATA1_01 Injection */
#define EIM_CHANNEL_CPU0_DCACHE_DATA1_23        39U     /* Channel 39 CPU0_DCACHE_DATA1_23 Injection */
#define EIM_CHANNEL_CPU0_DCACHE_TAG_01          40U     /* Channel 40 CPU0_DCACHE_TAG_01 Injection */
#define EIM_CHANNEL_CPU0_DCACHE_TAG_23          41U     /* Channel 41 CPU0_DCACHE_TAG_23 Injection */
#define EIM_CHANNEL_CPU0_ICACHE_DATA0           42U     /* Channel 42 CPU0_ICACHE_DATA1_0 Injection */
#define EIM_CHANNEL_CPU0_ICACHE_DATA1           43U     /* Channel 43 CPU0_ICACHE_DATA1_1 Injection */
#define EIM_CHANNEL_CPU0_ICACHE_TAG             44U     /* Channel 44 CPU0_CPU0_ICACHE_TAG Injection */
#define EIM_CHANNEL_MAM1_S3_SLAVEDOWNSIZE       63U     /* Channel 63 SCM MAM1_S3 Slave DownSize Injection */
#define EIM_CHANNEL_MAM1_S3_MASTERDOWNSIZE      64U     /* Channel 64 SCM MAM1_S3 Master DownSize Injection */
#define EIM_CHANNEL_DMA0_CFG                    65U     /* Channel 65 DMA0_CFG_ECC Injection */
#define EIM_CHANNEL_ROM_ECC                     67U     /* Channel 67 ROM_ECC Injection */
#define EIM_CHANNEL_MAM1_S3_MONITOR             68U     /* Channel 68 SCM MAM1_S3 MonitorInjection */
#define EIM_CHANNEL_CPU0_AHBM0_AHBM1_MONITOR    69U     /* Channel 69 SCM CPU0 AHBM0 and AHBM1 Monitor */
#define EIM_CHANNEL_CPU0_AHBP_AHBS_MONITOR      70U     /* Channel 70 SCM CPU0 AHBP and AHBS Monitor */
#define EIM_CHANNEL_MAM2_S2_SLAVEDOWNSIZE       75U     /* Channel 75 SCM MAM2_S2 Slave DownSize Injection */
#define EIM_CHANNEL_MAM2_S2_MASTERDOWNSIZE      76U     /* Channel 76 SCM MAM2_S2 Master DownSize Injection */
#define EIM_CHANNEL_RAM_DECODER_MONITOR         77U     /* Channel 77 RAM Decoder Monitor Error Injection */

/** 
 * @brief EIM lockstep channel define
 * 
 */
#define EIM_LOCKSTEP_CHANNEL_CPU0_LOCKSTEP      100U    /* Lockstep Channel 0 CPU0 Lockstep Error Injection */

/**
 * @brief Define the EIM DWP mode
 *
 */
#define EIM_DWP_MODE_ALLCPUALLOWED              0U      /**< ALL CPUs are allowed to access */
#define EIM_DWP_MODE_CPU0ALLOWED                1U      /**< cpu0 is allowed to access */
#define EIM_DWP_MODE_ALLCPUFORBIDDEN            7U      /**< All CPUs are forbidden */

#endif /* _DEVICE_FEATURES_FC7300F4MDSxxxxxT1B_EIM_COMMON_H_ */
