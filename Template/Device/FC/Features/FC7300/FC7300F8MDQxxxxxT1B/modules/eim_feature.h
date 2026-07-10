#ifndef _DEVICE_FEATURES_FC7300F8MDQxxxxxT1B_EIM_COMMON_H_
#define _DEVICE_FEATURES_FC7300F8MDQxxxxxT1B_EIM_COMMON_H_

/**
 * @brief EIM channel number define
 *
 */
#define EIM_CHANNEL_MAM0_S0                     0U      /* Channel 0 SCM Matrix Access Monitor Error Inection0(MAM0_S0) ROM */
#define EIM_CHANNEL_MAM0_S1                     1U      /* Channel 1 SCM Matrix Access Monitor Error Inection1(MAM0_S1) PFlash0 */
#define EIM_CHANNEL_MAM0_S2                     2U      /* Channel 2 SCM Matrix Access Monitor Error Inection2(MAM0_S2) PFlash1 */
#define EIM_CHANNEL_MAM0_S3                     3U      /* Channel 3 SCM Matrix Access Monitor Error Inection3(MAM0_S3) DFlash */
#define EIM_CHANNEL_MAM0_S4                     4U      /* Channel 4 SCM Matrix Access Monitor Error Inection4(MAM0_S4) SRAM0 */
#define EIM_CHANNEL_MAM0_S5                     5U      /* Channel 5 SCM Matrix Access Monitor Error Inection5(MAM0_S5) SRAM1 */
#define EIM_CHANNEL_MAM0_S6                     6U      /* Channel 6 SCM Matrix Access Monitor Error Inection6(MAM0_S6) SRAM2 */
#define EIM_CHANNEL_MAM0_S7                     7U      /* Channel 7 SCM Matrix Access Monitor Error Inection7(MAM0_S7) Backdoor of CPU */
#define EIM_CHANNEL_MAM1_S0                     8U      /* Channel 8 SCM Matrix Access Monitor Error Inection8(MAM1_S0) AFCB0 */
#define EIM_CHANNEL_MAM1_S1                     9U      /* Channel 9 SCM Matrix Access Monitor Error Inection9(MAM1_S1) AFCB1 */
#define EIM_CHANNEL_MAM1_S2                     10U     /* Channel 10 SCM Matrix Access Monitor Error Inection10(MAM1_S2) GPIO */
#define EIM_CHANNEL_CPU0_AHBM                   11U     /* Channel 11 SCM Matrix Access Monitor Error Inection11(CPU0_AHBM) */
#define EIM_CHANNEL_CPU0_AHBP                   12U     /* Channel 12 SCM Matrix Access Monitor Error Inection12(CPU0_AHBP) */
#define EIM_CHANNEL_CPU1_AHBM                   13U     /* Channel 13 SCM Matrix Access Monitor Error Inection13(CPU1_AHBM) */
#define EIM_CHANNEL_CPU1_AHBP                   14U     /* Channel 14 SCM Matrix Access Monitor Error Inection14(CPU1_AHBP) */
#define EIM_CHANNEL_CPU2_AHBM                   15U     /* Channel 15 SCM Matrix Access Monitor Error Inection15(CPU2_AHBM) */
#define EIM_CHANNEL_CPU2_AHBP                   16U     /* Channel 16 SCM Matrix Access Monitor Error Inection16(CPU2_AHBP) */
#define EIM_CHANNEL_ENET                        17U     /* Channel 17 SCM Matrix Access Monitor Error Inection17(ENET) */
#define EIM_CHANNEL_HSM                         18U     /* Channel 18 SCM Matrix Access Monitor Error Inection18(HSM) */
#define EIM_CHANNEL_DMA0                        19U     /* Channel 19 SCM Matrix Access Monitor Error Inection19(DMA0) */
#define EIM_CHANNEL_DMA1                        20U     /* Channel 20 SCM Matrix Access Monitor Error Inection20(DMA1) */
#define EIM_CHANNEL_CPU0_ITCM                   24U     /* Channel 24 CPU0 ITCM Injection */
#define EIM_CHANNEL_CPU0_DTCM0                  25U     /* Channel 25 CPU0_DTCM0 Injection */
#define EIM_CHANNEL_CPU0_DTCM1                  26U     /* Channel 26 CPU0_DTCM1 Injection */
#define EIM_CHANNEL_CPU1_ITCM                   27U     /* Channel 27 CPU1_ITCM Injection */
#define EIM_CHANNEL_CPU1_DTCM0                  28U     /* Channel 28 CPU1_DTCM0 Injection */
#define EIM_CHANNEL_CPU1_DTCM1                  29U     /* Channel 29 CPU1_DTCM1 Injection */
#define EIM_CHANNEL_CPU2_ITCM                   30U     /* Channel 30 CPU2_ITCM Injection */
#define EIM_CHANNEL_CPU2_DTCM0                  31U     /* Channel 31 CPU2_DTCM0 Injection */
#define EIM_CHANNEL_CPU2_DTCM1                  32U     /* Channel 32 CPU2_DTCM1 Injection */
#define EIM_CHANNEL_SRAM0                       33U     /* Channel 33 SRAM0 Injection(including address) */
#define EIM_CHANNEL_SRAM1                       34U     /* Channel 34 SRAM1 Injection(including address) */
#define EIM_CHANNEL_SRAM2                       35U     /* Channel 35 SRAM2 Injection(including address) */
#define EIM_CHANNEL_CPU0_DCACHE_DATA0_01        36U     /* Channel 36 CPU0_DCACHE_DATA0_01 Injection */
#define EIM_CHANNEL_CPU0_DCACHE_DATA0_23        37U     /* Channel 37 CPU0_DCACHE_DATA0_23 Injection */
#define EIM_CHANNEL_CPU0_DCACHE_DATA1_01        38U     /* Channel 38 CPU0_DCACHE_DATA1_01 Injection */
#define EIM_CHANNEL_CPU0_DCACHE_DATA1_23        39U     /* Channel 39 CPU0_DCACHE_DATA1_23 Injection */
#define EIM_CHANNEL_CPU0_DCACHE_TAG_01          40U     /* Channel 40 CPU0_DCACHE_TAG_01 Injection */
#define EIM_CHANNEL_CPU0_DCACHE_TAG_23          41U     /* Channel 41 CPU0_DCACHE_TAG_23 Injection */
#define EIM_CHANNEL_CPU0_ICACHE_DATA0           42U     /* Channel 42 CPU0_ICACHE_DATA1_0 Injection */
#define EIM_CHANNEL_CPU0_ICACHE_DATA1           43U     /* Channel 43 CPU0_ICACHE_DATA1_1 Injection */
#define EIM_CHANNEL_CPU0_ICACHE_TAG             44U     /* Channel 44 CPU0_CPU0_ICACHE_TAG Injection */
#define EIM_CHANNEL_CPU1_DCACHE_DATA0_01        45U     /* Channel 45 CPU1_DCACHE_DATA0_01 Injection */
#define EIM_CHANNEL_CPU1_DCACHE_DATA0_23        46U     /* Channel 46 CPU1_DCACHE_DATA0_23 Injection */
#define EIM_CHANNEL_CPU1_DCACHE_DATA1_01        47U     /* Channel 47 CPU1_DCACHE_DATA1_01 Injection */
#define EIM_CHANNEL_CPU1_DCACHE_DATA1_23        48U     /* Channel 48 CPU1_DCACHE_DATA1_23 Injection */
#define EIM_CHANNEL_CPU1_DCACHE_TAG_01          49U     /* Channel 49 CPU1_DCACHE_TAG_01 Injection */
#define EIM_CHANNEL_CPU1_DCACHE_TAG_23          50U     /* Channel 50 CPU1_DCACHE_TAG_23 Injection */
#define EIM_CHANNEL_CPU1_ICACHE_DATA0           51U     /* Channel 51 CPU1_ICACHE_DATA1_0 Injection */
#define EIM_CHANNEL_CPU1_ICACHE_DATA1           52U     /* Channel 52 CPU1_ICACHE_DATA1_1 Injection */
#define EIM_CHANNEL_CPU1_ICACHE_TAG             53U     /* Channel 53 CPU1_ICACHE_TAG Injection */
#define EIM_CHANNEL_CPU2_DCACHE_DATA0_01        54U     /* Channel 54 CPU2_DCACHE_DATA0_01 Injection */
#define EIM_CHANNEL_CPU2_DCACHE_DATA0_23        55U     /* Channel 55 CPU2_DCACHE_DATA0_23 Injection */
#define EIM_CHANNEL_CPU2_DCACHE_DATA1_01        56U     /* Channel 56 CPU2_DCACHE_DATA1_01 Injection */
#define EIM_CHANNEL_CPU2_DCACHE_DATA1_23        57U     /* Channel 57 CPU2_DCACHE_DATA1_23 Injection */
#define EIM_CHANNEL_CPU2_DCACHE_TAG_01          58U     /* Channel 58 CPU2_DCACHE_TAG_01 Injection */
#define EIM_CHANNEL_CPU2_DCACHE_TAG_23          59U     /* Channel 59 CPU2_DCACHE_TAG_23 Injection */
#define EIM_CHANNEL_CPU2_ICACHE_DATA0           60U     /* Channel 60 CPU2_ICACHE_DATA1_0 Injection */
#define EIM_CHANNEL_CPU2_ICACHE_DATA1           61U     /* Channel 61 CPU2_ICACHE_DATA1_1 Injection */
#define EIM_CHANNEL_CPU2_ICACHE_TAG             62U     /* Channel 62 CPU2_ICACHE_TAG Injection */
#define EIM_CHANNEL_MAM0_S7_DOWNSIZE            63U     /* Channel 63 SCM MAM0_S7 DownSize Monitor Error Injection - Backdoor CPU 64:32 */
#define EIM_CHANNEL_DMA0_CFG                    65U     /* Channel 65 DMA0_CFG_ECC Injection(including address) */
#define EIM_CHANNEL_DMA1_CFG                    66U     /* Channel 66 DMA1_CFG_ECC Injection(including address) */
#define EIM_CHANNEL_ROM_ECC                     67U     /* Channel 67 ROM_ECC Injection */
#define EIM_CHANNEL_CPU0_AHBP_AHBS_MONITOR      70U     /* Channel 70 SCM CPU0 AHBP and AHBS Monitor Error Injection - CPU AHBP and AHBS F2S and S2F monitor */
#define EIM_CHANNEL_CPU1_AHBP_AHBS_MONITOR      72U     /* Channel 72 SCM CPU1 AHBP and AHBS Monitor Error Injection - CPU AHBP and AHBS F2S and S2F monitor */
#define EIM_CHANNEL_CPU2_AHBP_AHBS_MONITOR      74U     /* Channel 74 SCM CPU2 AHBP and AHBS Monitor Error Injection - CPU AHBP and AHBS F2S and S2F monitor */
#define EIM_CHANNEL_MAM1_S2_DOWNSIZE            75U     /* Channel 75 SCM MAM1_S2 DownSize Error Injection - GPIO 64:32 */
#define EIM_CHANNEL_RAM_DECODER_MONITOR         77U     /* Channel 77 RAM Decoder Monitor Error Injection */
#define EIM_CHANNEL_AFCB0_MONITOR               78U     /* Channel 78 AFCB0 Monitor Error Injection */
#define EIM_CHANNEL_AFCB1_MONITOR               79U     /* Channel 79 AFCB1 Monitor Error Injection */
#define EIM_CHANNEL_AFCB2_MONITOR               80U     /* Channel 80 AFCB2 Monitor Error Injection */
#define EIM_CHANNEL_MAM1_S3_MONITOR             81U     /* Channel 81 SCM Matrix Access Monitor Error Injection24 (MAM1_S3) - AFCB2 */
#define EIM_CHANNEL_FLEXHSM_DRAM_ECC            82U     /* Channel 82 FLEXHSM DRAM ECC Error Injection (including address) */
#define EIM_CHANNEL_FLEXHSM_IRAM_ECC            83U     /* Channel 83 FLEXHSM IRAM ECC Error Injection (including address) */
#define EIM_CHANNEL_CPU0_OVERLAY_MONITOR        84U     /* Channel 84 CPU0 Overlay Monitor */
#define EIM_CHANNEL_CPU1_OVERLAY_MONITOR        85U     /* Channel 85 CPU1 Overlay Monitor */
#define EIM_CHANNEL_CPU2_OVERLAY_MONITOR        86U     /* Channel 86 CPU2 Overlay Monitor */
#define EIM_CHANNEL_CPU3_AHBM_MONITOR           88U     /* Channel 88 SCM Matrix Access Monitor Error Injection25 (CPU3_AHBM) */
#define EIM_CHANNEL_CPU3_AHBP_MONITOR           89U     /* Channel 89 SCM Matrix Access Monitor Error Injection26 (CPU3_AHBP) */
#define EIM_CHANNEL_CPU3_AHBP_AHBS_MONITOR      91U     /* Channel 91 SCM CPU3 AHBP and AHBS Monitor Error Injection - CPU AHBP and AHBS F2S and S2F monitor */
#define EIM_CHANNEL_CPU3_ITCM                   92U     /* Channel 92 CPU3_ITCM Injection */
#define EIM_CHANNEL_CPU3_DTCM0                  93U     /* Channel 93 CPU3_DTCM0 Injection */
#define EIM_CHANNEL_CPU3_DTCM1                  94U     /* Channel 94 CPU3_DTCM1 Injection */
#define EIM_CHANNEL_CPU3_DCACHE_DATA0_01        95U     /* Channel 95 CPU3_DCACHE_DATA0_01 Injection */
#define EIM_CHANNEL_CPU3_DCACHE_DATA0_23        96U     /* Channel 96 CPU3_DCACHE_DATA0_23 Injection */
#define EIM_CHANNEL_CPU3_DCACHE_DATA1_01        97U     /* Channel 97 CPU3_DCACHE_DATA1_01 Injection */
#define EIM_CHANNEL_CPU3_DCACHE_DATA1_23        98U     /* Channel 98 CPU3_DCACHE_DATA1_23 Injection */
#define EIM_CHANNEL_CPU3_DCACHE_TAG_01          99U     /* Channel 99 CPU3_DCACHE_TAG_01 Injection */
#define EIM_CHANNEL_CPU3_DCACHE_TAG_23          100U    /* Channel 100 CPU3_DCACHE_TAG_23 Injection */
#define EIM_CHANNEL_CPU3_ICACHE_DATA0           101U    /* Channel 101 CPU3_ICACHE_DATA1_0 Injection */
#define EIM_CHANNEL_CPU3_ICACHE_DATA1           102U    /* Channel 102 CPU3_ICACHE_DATA1_1 Injection */
#define EIM_CHANNEL_CPU3_ICACHE_TAG             103U    /* Channel 103 CPU3_ICACHE_TAG Injection */
#define EIM_CHANNEL_MAM0_S8                     104U    /* Channel 104 SCM Matrix Access Monitor Error Inection8(MAM0_S8) Backdoor of CPU */
#define EIM_CHANNEL_MAM0_S8_DOWNSIZE            105U    /* Channel 105 SCM MAM0_S8 DownSize Monitor Error Injection - Backdoor CPU 64:32 */
#define EIM_CHANNEL_MAM0_S9                     107U    /* Channel 107 SCM Matrix Access Monitor Error Inection9(MAM0_S9) Backdoor of CPU */
#define EIM_CHANNEL_MAM0_S9_DOWNSIZE            108U    /* Channel 108 SCM MAM0_S9 DownSize Monitor Error Injection - Backdoor CPU 64:32 */
#define EIM_CHANNEL_MAM0_S10                    110U    /* Channel 110 SCM Matrix Access Monitor Error Inection10(MAM0_S10) Backdoor of CPU */
#define EIM_CHANNEL_MAM0_S10_DOWNSIZE           111U    /* Channel 111 SCM MAM0_S10 DownSize Monitor Error Injection - Backdoor CPU 64:32 */

/** 
 * @brief EIM lockstep channel define
 * 
 */
#define EIM_LOCKSTEP_CPU1_SUPPORT
#define EIM_LOCKSTEP_CPU2_SUPPORT
#define EIM_LOCKSTEP_DMA0_SUPPORT
#define EIM_LOCKSTEP_CHANNEL_CPU0_LOCKSTEP      100U    /* Lockstep Channel 0 CPU0 Lockstep Error Injection */
#define EIM_LOCKSTEP_CHANNEL_CPU1_LOCKSTEP      101U    /* Lockstep Channel 1 CPU1 Lockstep Error Injection */
#define EIM_LOCKSTEP_CHANNEL_DMA0_LOCKSTEP      102U    /* Lockstep Channel 2 DMA0 Lockstep Error Injection */
#define EIM_LOCKSTEP_CHANNEL_CPU2_LOCKSTEP      103U    /* Lockstep Channel 3 CPU2 Lockstep Error Injection */

/**
 * @brief Define the EIM DWP mode
 *
 */
#define EIM_DWP_MODE_ALLCPUALLOWED              0U      /**< ALL CPUs are allowed to access */
#define EIM_DWP_MODE_CPU0ALLOWED                1U      /**< cpu0 is allowed to access */
#define EIM_DWP_MODE_CPU1ALLOWED                2U      /**< cpu1 is allowed to access */
#define EIM_DWP_MODE_CPU2ALLOWED                3U      /**< cpu2 is allowed to access */
#define EIM_DWP_MODE_CPU3ALLOWED                4U      /**< cpu3 is allowed to access */
#define EIM_DWP_MODE_ALLCPUFORBIDDEN            7U      /**< All CPUs are forbidden */

#endif /* _DEVICE_FEATURES_FC7300F8MDQxxxxxT1B_EIM_COMMON_H_ */
