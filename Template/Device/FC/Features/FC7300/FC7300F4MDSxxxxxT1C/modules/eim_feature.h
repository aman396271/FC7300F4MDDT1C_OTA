#ifndef _DEVICE_FEATURES_FC7300F4MDSxxxxxT1C_EIM_COMMON_H_
#define _DEVICE_FEATURES_FC7300F4MDSxxxxxT1C_EIM_COMMON_H_

/**
 * @brief EIM channel number define
 *
 */
#define EIM_CHANNEL_MAM0_S0                     0U      /* Channel 0 SCM Matrix Access Monitor Error Inection0(MAM0_S0) */
#define EIM_CHANNEL_MAM0_S1                     1U      /* Channel 1 SCM Matrix Access Monitor Error Inection1(MAM0_S1) */
#define EIM_CHANNEL_MAM0_S3                     3U      /* Channel 3 SCM Matrix Access Monitor Error Inection3(MAM0_S3) */
#define EIM_CHANNEL_MAM0_S4                     4U      /* Channel 4 SCM Matrix Access Monitor Error Inection4(MAM0_S4) */
#define EIM_CHANNEL_MAM0_S5                     5U      /* Channel 5 SCM Matrix Access Monitor Error Inection5(MAM0_S5) */
#define EIM_CHANNEL_MAM0_S6                     6U      /* Channel 6 SCM Matrix Access Monitor Error Inection6(MAM0_S6) */
#define EIM_CHANNEL_MAM0_S7                     7U      /* Channel 7 SCM Matrix Access Monitor Error Inection6(MAM0_S7) */
#define EIM_CHANNEL_MAM1_S0                     8U      /* Channel 8 SCM Matrix Access Monitor Error Inection8(MAM1_S0) */
#define EIM_CHANNEL_MAM1_S1                     9U      /* Channel 9 SCM Matrix Access Monitor Error Inection9(MAM1_S1) */
#define EIM_CHANNEL_MAM1_S2                     10U     /* Channel 10 SCM Matrix Access Monitor Error Inection10(MAM1_S2) */
#define EIM_CHANNEL_CPU0_AHBM                   11U     /* Channel 11 SCM Matrix Access Monitor Error Inection11(CPU0_AHBM) */
#define EIM_CHANNEL_CPU0_AHBP                   12U     /* Channel 12 SCM Matrix Access Monitor Error Inection12(CPU0_AHBP) */
#define EIM_CHANNEL_CPU1_AHBM                   13U     /* Channel 13 SCM Matrix Access Monitor Error Inection13(CPU1_AHBM) */
#define EIM_CHANNEL_CPU1_AHBP                   14U     /* Channel 14 SCM Matrix Access Monitor Error Inection14(CPU1_AHBP) */
#define EIM_CHANNEL_FLEXHSM                     18U     /* Channel 18 SCM Matrix Access Monitor Error Inection18(FLEXHSM) */
#define EIM_CHANNEL_DMA0                        19U     /* Channel 19 SCM Matrix Access Monitor Error Inection19(DMA0) */
#define EIM_CHANNEL_CPU0_ITCM                   24U     /* Channel 24 CPU0 ITCM Injection */
#define EIM_CHANNEL_CPU0_DTCM0                  25U     /* Channel 25 CPU0_DTCM0 Injection */
#define EIM_CHANNEL_CPU0_DTCM1                  26U     /* Channel 26 CPU0_DTCM1 Injection */
#define EIM_CHANNEL_CPU1_ITCM                   27U     /* Channel 27 CPU1_ITCM Injection */
#define EIM_CHANNEL_CPU1_DTCM0                  28U     /* Channel 28 CPU1_DTCM0 Injection */
#define EIM_CHANNEL_CPU1_DTCM1                  29U     /* Channel 29 CPU1_DTCM1 Injection */
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
#define EIM_CHANNEL_CPU1_DCACHE_DATA0_01        45U     /* Channel 45 CPU1_DCACHE_DATA0_01 Injection */
#define EIM_CHANNEL_CPU1_DCACHE_DATA0_23        46U     /* Channel 46 CPU1_DCACHE_DATA0_23 Injection */
#define EIM_CHANNEL_CPU1_DCACHE_DATA1_01        47U     /* Channel 47 CPU1_DCACHE_DATA1_01 Injection */
#define EIM_CHANNEL_CPU1_DCACHE_DATA1_23        48U     /* Channel 48 CPU1_DCACHE_DATA1_23 Injection */
#define EIM_CHANNEL_CPU1_DCACHE_TAG_01          49U     /* Channel 49 CPU1_DCACHE_TAG_01 Injection */
#define EIM_CHANNEL_CPU1_DCACHE_TAG_23          50U     /* Channel 50 CPU1_DCACHE_TAG_23 Injection */
#define EIM_CHANNEL_CPU1_ICACHE_DATA0           51U     /* Channel 51 CPU1_ICACHE_DATA1_0 Injection */
#define EIM_CHANNEL_CPU1_ICACHE_DATA1           52U     /* Channel 52 CPU1_ICACHE_DATA1_1 Injection */
#define EIM_CHANNEL_CPU1_ICACHE_TAG             53U     /* Channel 53 CPU1_ICACHE_TAG Injection */
#define EIM_CHANNEL_MAM0_S7_DOWNSIZE            63U     /* Channel 63 SCM MAM0_S7 DownSize Monitor Error Injection */
#define EIM_CHANNEL_DMA0_CFG                    65U     /* Channel 65 DMA0_CFG_ECC Injection */
#define EIM_CHANNEL_ROM_ECC                     67U     /* Channel 67 ROM_ECC Injection */
#define EIM_CHANNEL_CPU0_AHBP_AHBS_MONITOR      70U     /* Channel 70 SCM CPU0 AHBP and AHBS Monitor */
#define EIM_CHANNEL_CPU1_AHBP_AHBS_MONITOR      72U     /* Channel 72 SCM CPU1 AHBP and AHBS Monitor */
#define EIM_CHANNEL_MAM1_S2_DOWNSIZE            75U     /* Channel 75 SCM MAM1_S2 DownSize Error Injection */
#define EIM_CHANNEL_RAM_DECODER_MONITOR         77U     /* Channel 77 RAM Decoder Monitor Error Injection */
#define EIM_CHANNEL_AFCB0_MONITOR               78U     /* Channel 78 AFCB0 Monitor Error Injection */
#define EIM_CHANNEL_AFCB1_MONITOR               79U     /* Channel 79 AFCB1 Monitor Error Injection */
#define EIM_CHANNEL_AFCB0_PD0_MONITOR           80U     /* Channel 80 AFCB0 PD0 Monitor Error Injection */
#define EIM_CHANNEL_MAM1_S3                     81U     /* Channel 81 SCM Matrix Access Monitor Error Injection24(MAM1_S3) */
#define EIM_CHANNEL_FLEXHSM_DRAM                82U     /* Channel 82 FLEXHSM DRAM ECC Error Injection */
#define EIM_CHANNEL_FLEXHSM_IRAM                83U     /* Channel 83 FLEXHSM IRAM ECC Error Injection */
#define EIM_CHANNEL_CPU0_OVERLAY_MONITOR        84U     /* Channel 84 CPU0 Overlay Monitor */
#define EIM_CHANNEL_MAM0_S8                     104U    /* Channel 104 SCM Matrix Access Monitor Error Injection28 */
#define EIM_CHANNEL_MAM0_S8_DOWNSIZE            105U    /* Channel 105 SCM MAM0_S8 DownSize Monitor Error Injection */

/** 
 * @brief EIM lockstep channel define
 * 
 */
#define EIM_LOCKSTEP_DMA0_SUPPORT
#define EIM_LOCKSTEP_CHANNEL_CPU0_LOCKSTEP      100U    /* Lockstep Channel 0 CPU0 Lockstep Error Injection */
#define EIM_LOCKSTEP_CHANNEL_DMA0_LOCKSTEP      102U    /* Lockstep Channel 2 DMA0 Lockstep Error Injection */

/**
 * @brief Define the EIM DWP mode
 *
 */
#define EIM_DWP_MODE_ALLCPUALLOWED              0U      /**< ALL CPUs are allowed to access */
#define EIM_DWP_MODE_CPU0ALLOWED                1U      /**< cpu0 is allowed to access */
#define EIM_DWP_MODE_CPU1ALLOWED                2U      /**< cpu1 is allowed to access */
#define EIM_DWP_MODE_ALLCPUFORBIDDEN            7U      /**< All CPUs are forbidden */

#endif /* _DEVICE_FEATURES_FC7300F4MDSxxxxxT1C_EIM_COMMON_H_ */
