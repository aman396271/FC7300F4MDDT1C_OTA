#ifndef _DEVICE_FEATURES_FC7300F8MDQxxxxxT1B_STCU_COMMON_H_
#define _DEVICE_FEATURES_FC7300F8MDQxxxxxT1B_STCU_COMMON_H_

typedef enum
{
    STCU_MBIST_SEL_NONE        = 0x00U,         /**<! No any MBist item selected. >*/
    STCU_MBIST_SEL_SRAM0_0     = 0x01U,         /**<! SRAM0_0 SRAM Select for MBIST. >*/
    STCU_MBIST_SEL_SRAM0_1     = 0x02U,         /**<! SRAM0_1 SRAM Select for MBIST. >*/
    STCU_MBIST_SEL_SRAM1_0     = 0x04U,         /**<! SRAM1_0 SRAM Select for MBIST. >*/
    STCU_MBIST_SEL_SRAM1_1     = 0x08U,         /**<! SRAM1_1 SRAM Select for MBIST. >*/
    STCU_MBIST_SEL_SRAM2_0     = 0x10U,         /**<! SRAM2_0 SRAM Select for MBIST. >*/
    STCU_MBIST_SEL_SRAM2_1     = 0x20U,         /**<! SRAM2_1 SRAM Select for MBIST. >*/
    STCU_MBIST_SEL_SRAM2_2     = 0x40U,         /**<! SRAM2_2 SRAM Select for MBIST. >*/
    STCU_MBIST_SEL_ITCM_CPU0   = 0x80U,         /**<! ITCM_CPU0 SRAM Select for MBIST. >*/
    STCU_MBIST_SEL_DTCM0_CPU0  = 0x100U,        /**<! DTCM0_CPU0 SRAM Select for MBIST. >*/
    STCU_MBIST_SEL_DTCM1_CPU0  = 0x200U,        /**<! DTCM1_CPU0 SRAM Select for MBIST. >*/
    STCU_MBIST_SEL_ITCM_CPU1   = 0x400U,        /**<! ITCM_CPU1 SRAM Select for MBIST. >*/
    STCU_MBIST_SEL_DTCM0_CPU1  = 0x800U,        /**<! DTCM0_CPU1 SRAM Select for MBIST. >*/
    STCU_MBIST_SEL_DTCM1_CPU1  = 0x1000U,       /**<! DTCM1_CPU1 SRAM Select for MBIST. >*/
    STCU_MBIST_SEL_ITCM_CPU2   = 0x2000U,       /**<! ITCM_CPU2 SRAM Select for MBIST. >*/
    STCU_MBIST_SEL_DTCM0_CPU2  = 0x4000U,       /**<! DTCM0_CPU2 SRAM Select for MBIST. >*/
    STCU_MBIST_SEL_DTCM1_CPU2  = 0x8000U,       /**<! DTCM1_CPU2 SRAM Select for MBIST. >*/
    STCU_MBIST_SEL_ITCM_CPU3   = 0x10000U,      /**<! ITCM_CPU3 SRAM Select for MBIST. >*/
    STCU_MBIST_SEL_DTCM0_CPU3  = 0x20000U,      /**<! DTCM0_CPU3 SRAM Select for MBIST. >*/
    STCU_MBIST_SEL_DTCM1_CPU3  = 0x40000U,      /**<! DTCM1_CPU3 SRAM Select for MBIST. >*/
    STCU_MBIST_SEL_CACHE_CPU0  = 0x80000U,      /**<! CACHE_CPU0 SRAM Select for MBIST. >*/
    STCU_MBIST_SEL_CACHE_CPU1  = 0x100000U,     /**<! CACHE_CPU1 SRAM Select for MBIST. >*/
    STCU_MBIST_SEL_CACHE_CPU2  = 0x200000U,     /**<! CACHE_CPU2 SRAM Select for MBIST. >*/
    STCU_MBIST_SEL_CACHE_CPU3  = 0x400000U,     /**<! CACHE_CPU3 SRAM MBIST fail flag. >*/
    STCU_MBIST_SEL_SRAM_SUBSYS = 0x800000U,     /**<! CACHE_SUBSYS SRAM MBIST fail flag. >*/
    STCU_MBIST_SEL_SRAM_HSM    = 0x1000000U,    /**<! HSM SRAM Select for MBIST. >*/
    STCU_MBIST_SEL_SRAM_DMACAN = 0x2000000U,    /**<! DMA_FLEXCAN SRAM Select for MBIST. >*/
    STCU_MBIST_SEL_SRAM_ENET   = 0x4000000U,    /**<! ENET SRAM Select for MBIST. >*/
    STCU_MBIST_SEL_SRAM_ETB    = 0x8000000U,    /**<! ETB SRAM Select for MBIST. >*/
    STCU_MBIST_SEL_ROM_HOST    = 0x10000000U,   /**<! System ROM Select for MBIST. >*/
    STCU_MBIST_SEL_ROM_HSM     = 0x20000000U    /**<! HSM ROM Select for MBIST. >*/
}STCU_MbistSelType;

/** @brief MBIST done status flag. */
typedef enum
{
    STCU_MBIST_DONE_NONE        = 0x00U,         /**<! No any MBiST done flag. >*/
    STCU_MBIST_DONE_SRAM0_0     = 0x01U,         /**<! SRAM0_0 SRAM MBIST Done Flag. >*/
    STCU_MBIST_DONE_SRAM0_1     = 0x02U,         /**<! SRAM0_1 SRAM MBIST Done Flag. >*/
    STCU_MBIST_DONE_SRAM1_0     = 0x04U,         /**<! SRAM1_0 SRAM MBIST Done Flag. >*/
    STCU_MBIST_DONE_SRAM1_1     = 0x08U,         /**<! SRAM1_1 SRAM MBIST Done Flag. >*/
    STCU_MBIST_DONE_SRAM2_0     = 0x10U,         /**<! SRAM2_0 SRAM MBIST Done Flag. >*/
    STCU_MBIST_DONE_SRAM2_1     = 0x20U,         /**<! SRAM2_1 SRAM MBIST Done Flag. >*/
    STCU_MBIST_DONE_SRAM2_2     = 0x40U,         /**<! SRAM2_2 SRAM MBIST Done Flag. >*/
    STCU_MBIST_DONE_ITCM_CPU0   = 0x80U,         /**<! ITCM_CPU0 SRAM MBIST Done Flag. >*/
    STCU_MBIST_DONE_DTCM0_CPU0  = 0x100U,        /**<! DTCM0_CPU0 SRAM MBIST Done Flag. >*/
    STCU_MBIST_DONE_DTCM1_CPU0  = 0x200U,        /**<! DTCM1_CPU0 SRAM MBIST Done Flag. >*/
    STCU_MBIST_DONE_ITCM_CPU1   = 0x400U,        /**<! ITCM_CPU1 SRAM MBIST Done Flag. >*/
    STCU_MBIST_DONE_DTCM0_CPU1  = 0x800U,        /**<! DTCM0_CPU1 SRAM MBIST Done Flag. >*/
    STCU_MBIST_DONE_DTCM1_CPU1  = 0x1000U,       /**<! DTCM1_CPU1 SRAM MBIST Done Flag. >*/
    STCU_MBIST_DONE_ITCM_CPU2   = 0x2000U,       /**<! ITCM_CPU2  SRAM MBIST Done Flag. >*/
    STCU_MBIST_DONE_DTCM0_CPU2  = 0x4000U,       /**<! DTCM0_CPU2 SRAM MBIST Done Flag. >*/
    STCU_MBIST_DONE_DTCM1_CPU2  = 0x8000U,       /**<! DTCM1_CPU2 SRAM MBIST Done Flag. >*/
    STCU_MBIST_DONE_ITCM_CPU3   = 0x10000U,      /**<! ITCM_CPU3 SRAM BIST Done Flag. >*/
    STCU_MBIST_DONE_DTCM0_CPU3  = 0x20000U,      /**<! DTCM0_CPU3 SRAM MBIST Done Flag. >*/
    STCU_MBIST_DONE_DTCM1_CPU3  = 0x40000U,      /**<! DTCM1_CPU3 SRAM MBIST Done Flag. >*/
    STCU_MBIST_DONE_CACHE_CPU0  = 0x80000U,      /**<! CACHE_CPU0 SRAM MBIST Done Flag. >*/
    STCU_MBIST_DONE_CACHE_CPU1  = 0x100000U,     /**<! CACHE_CPU1 SRAM MBIST Done Flag. >*/
    STCU_MBIST_DONE_CACHE_CPU2  = 0x200000U,     /**<! CACHE_CPU2 SRAM MBIST Done Flag. >*/
    STCU_MBIST_DONE_CACHE_CPU3  = 0x400000U,     /**<! CACHE_CPU3 SRAM MBIST fail flag. >*/
    STCU_MBIST_DONE_SRAM_SUBSYS = 0x800000U,     /**<! CACHE_SUBS SRAM MBIST fail flag. >*/
    STCU_MBIST_DONE_SRAM_HSM    = 0x1000000U,    /**<! HSM SRAM MBIST fail flag. >*/
    STCU_MBIST_DONE_SRAM_DMACAN = 0x2000000U,    /**<! DMA_FLEXCAN SRAM MBIST fail flag. >*/
    STCU_MBIST_DONE_SRAM_ENET   = 0x4000000U,    /**<! ENET SRAM MBIST fail flag. >*/
    STCU_MBIST_DONE_SRAM_ETB    = 0x8000000U,    /**<! ETB SRAM MBIST Fail Flag. >*/
    STCU_MBIST_DONE_ROM_HOST    = 0x10000000U,   /**<! System ROM MBIST Fail Flag. >*/
    STCU_MBIST_DONE_ROM_HSM     = 0x20000000U    /**<! HSM ROM MBIST Fail Flag. >*/
}STCU_MbistDoneType;

/** @brief MBIST fail status flag. */
typedef enum
{
    STCU_MBIST_FAIL_NONE        = 0x00U,         /**<! No any MBiST done flag. >*/
    STCU_MBIST_FAIL_SRAM0_0     = 0x01U,         /**<! SRAM0_0 SRAM MBIST Fail Flag. >*/
    STCU_MBIST_FAIL_SRAM0_1     = 0x02U,         /**<! SRAM0_1 SRAM MBIST Fail Flag. >*/
    STCU_MBIST_FAIL_SRAM1_0     = 0x04U,         /**<! SRAM1_0 SRAM MBIST Fail Flag. >*/
    STCU_MBIST_FAIL_SRAM1_1     = 0x08U,         /**<! SRAM1_1 SRAM MBIST Fail Flag. >*/
    STCU_MBIST_FAIL_SRAM2_0     = 0x10U,         /**<! SRAM2_0 SRAM MBIST Fail Flag. >*/
    STCU_MBIST_FAIL_SRAM2_1     = 0x20U,         /**<! SRAM2_1 SRAM MBIST Fail Flag. >*/
    STCU_MBIST_FAIL_SRAM2_2     = 0x40U,         /**<! SRAM2_2 SRAM MBIST Fail Flag. >*/
    STCU_MBIST_FAIL_ITCM_CPU0   = 0x80U,         /**<! ITCM_CPU0 SRAM MBIST Fail Flag. >*/
    STCU_MBIST_FAIL_DTCM0_CPU0  = 0x100U,        /**<! DTCM0_CPU0 SRAM MBIST Fail Flag. >*/
    STCU_MBIST_FAIL_DTCM1_CPU0  = 0x200U,        /**<! DTCM1_CPU0 SRAM MBIST Fail Flag. >*/
    STCU_MBIST_FAIL_ITCM_CPU1   = 0x400U,        /**<! ITCM_CPU1 SRAM MBIST Fail Flag. >*/
    STCU_MBIST_FAIL_DTCM0_CPU1  = 0x800U,        /**<! DTCM0_CPU1 SRAM MBIST Fail Flag. >*/
    STCU_MBIST_FAIL_DTCM1_CPU1  = 0x1000U,       /**<! DTCM1_CPU1 SRAM MBIST Fail Flag. >*/
    STCU_MBIST_FAIL_ITCM_CPU2   = 0x2000U,       /**<! ITCM_CPU2  SRAM MBIST Fail Flag. >*/
    STCU_MBIST_FAIL_DTCM0_CPU2  = 0x4000U,       /**<! DTCM0_CPU2 SRAM MBIST Fail Flag. >*/
    STCU_MBIST_FAIL_DTCM1_CPU2  = 0x8000U,       /**<! DTCM1_CPU2 SRAM MBIST Fail Flag. >*/
    STCU_MBIST_FAIL_ITCM_CPU3   = 0x10000U,      /**<! ITCM_CPU3 SRAM MBIST Fail Flag. >*/
    STCU_MBIST_FAIL_DTCM0_CPU3  = 0x20000U,      /**<! DTCM0_CPU3 SRAM MBIST Fail Flag. >*/
    STCU_MBIST_FAIL_DTCM1_CPU3  = 0x40000U,      /**<! DTCM1_CPU3 SRAM MBIST Fail Flag. >*/
    STCU_MBIST_FAIL_CACHE_CPU0  = 0x80000U,      /**<! CACHE_CPU0 SRAM MBIST Fail Flag. >*/
    STCU_MBIST_FAIL_CACHE_CPU1  = 0x100000U,     /**<! CACHE_CPU1 SRAM MBIST Fail Flag. >*/
    STCU_MBIST_FAIL_CACHE_CPU2  = 0x200000U,     /**<! CACHE_CPU2 SRAM MBIST fail flag. >*/
    STCU_MBIST_FAIL_CACHE_CPU3  = 0x400000U,     /**<! CACHE_CPU3 SRAM MBIST fail flag. >*/
    STCU_MBIST_FAIL_SRAM_SUBSYS = 0x800000U,     /**<! CACHE_SUBS SRAM MBIST fail flag. >*/
    STCU_MBIST_FAIL_SRAM_HSM    = 0x1000000U,    /**<! HSM SRAM MBIST fail flag. >*/
    STCU_MBIST_FAIL_SRAM_DMACAN = 0x2000000U,    /**<! DMA_FLEXCAN SRAM MBIST fail flag. >*/
    STCU_MBIST_FAIL_SRAM_ENET   = 0x4000000U,    /**<! ENET SRAM MBIST fail flag. >*/
    STCU_MBIST_FAIL_SRAM_ETB    = 0x8000000U,    /**<! ETB SRAM MBIST Fail Flag. >*/
    STCU_MBIST_FAIL_ROM_HOST    = 0x10000000U,   /**<! System ROM MBIST Fail Flag. >*/
    STCU_MBIST_FAIL_ROM_HSM     = 0x20000000U    /**<! HSM ROM MBIST Fail Flag. >*/
}STCU_MbistFailedType;

/** @brief The items select for Hardware SRAM Initialization. */
typedef enum
{
    STCU_INIT_RAM_TYPE_NONE        = 0x00U,            /**<! No any SRAM need to be initialized. >*/
    STCU_INIT_RAM_TYPE_SRAM0_0     = 0x01U,            /**<! SRAM0_0 SRAM Select for Hardware SRAM Initialization. >*/
    STCU_INIT_RAM_TYPE_SRAM0_1     = 0x02U,            /**<! SRAM0_1 SRAM Select for Hardware SRAM Initialization. >*/
    STCU_INIT_RAM_TYPE_SRAM1_0     = 0x04U,            /**<! SRAM1_0 SRAM Select for Hardware SRAM Initialization. >*/
    STCU_INIT_RAM_TYPE_SRAM1_1     = 0x08U,            /**<! SRAM1_1 SRAM Select for Hardware SRAM Initialization. >*/
    STCU_INIT_RAM_TYPE_SRAM2_0     = 0x10U,            /**<! SRAM2_0 SRAM Select for Hardware SRAM Initialization. >*/
    STCU_INIT_RAM_TYPE_SRAM2_1     = 0x20U,            /**<! SRAM2_1 SRAM Select for Hardware SRAM Initialization. >*/
    STCU_INIT_RAM_TYPE_SRAM2_2     = 0x40U,            /**<! SRAM2_2 SRAM Select for Hardware SRAM Initialization. >*/
    STCU_INIT_RAM_TYPE_ITCM_CPU0   = 0x80U,            /**<! ITCM_CPU0 SRAM Select for Hardware SRAM Initialization. >*/
    STCU_INIT_RAM_TYPE_DTCM0_CPU0  = 0x100U,           /**<! DTCM0_CPU0 SRAM Select for Hardware SRAM Initialization. >*/
    STCU_INIT_RAM_TYPE_DTCM1_CPU0  = 0x200U,           /**<! DTCM1_CPU0 SRAM Select for Hardware SRAM Initialization. >*/
    STCU_INIT_RAM_TYPE_ITCM_CPU1   = 0x400U,           /**<! ITCM_CPU1 SRAM Select for Hardware SRAM Initialization. >*/
    STCU_INIT_RAM_TYPE_DTCM0_CPU1  = 0x800U,           /**<! DTCM0_CPU1 SRAM Select for Hardware SRAM Initialization. >*/
    STCU_INIT_RAM_TYPE_DTCM1_CPU1  = 0x1000U,          /**<! DTCM1_CPU1 SRAM Select for Hardware SRAM Initialization. >*/
    STCU_INIT_RAM_TYPE_ITCM_CPU2   = 0x2000U,          /**<! ITCM_CPU2 SRAM Select for Hardware SRAM Initialization. >*/
    STCU_INIT_RAM_TYPE_DTCM0_CPU2  = 0x4000U,          /**<! DTCM0_CPU2 SRAM Select for Hardware SRAM Initialization. >*/
    STCU_INIT_RAM_TYPE_DTCM1_CPU2  = 0x8000U,          /**<! DTCM1_CPU2 SRAM Select for Hardware SRAM Initialization. >*/
    STCU_INIT_RAM_TYPE_ITCM_CPU3   = 0x10000U,         /**<! ITCM_CPU2 SRAM Select for Hardware SRAM Initialization. >*/
    STCU_INIT_RAM_TYPE_DTCM0_CPU3  = 0x20000U,         /**<! DTCM0_CPU2 SRAM Select for Hardware SRAM Initialization. >*/
    STCU_INIT_RAM_TYPE_DTCM1_CPU3  = 0x40000U          /**<! DTCM1_CPU2 SRAM Select for Hardware SRAM Initialization. >*/
}STCU_InitRamType;

/** @brief Init Ram done status flag. */
typedef enum
{
    STCU_INIT_RAM_DONE_TYPE_NONE        = 0x00U,           /**<! No any SRAM need to be initialized. >*/
    STCU_INIT_RAM_DONE_TYPE_SRAM0_0     = 0x01U,           /**<! SRAM0_0 SRAM Select for Hardware SRAM Initialization. >*/
    STCU_INIT_RAM_DONE_TYPE_SRAM0_1     = 0x02U,           /**<! SRAM0_1 SRAM Select for Hardware SRAM Initialization. >*/
    STCU_INIT_RAM_DONE_TYPE_SRAM1_0     = 0x04U,           /**<! SRAM1_0 SRAM Select for Hardware SRAM Initialization. >*/
    STCU_INIT_RAM_DONE_TYPE_SRAM1_1     = 0x08U,           /**<! SRAM1_1 SRAM Select for Hardware SRAM Initialization. >*/
    STCU_INIT_RAM_DONE_TYPE_SRAM2_0     = 0x10U,           /**<! SRAM2_0 SRAM Select for Hardware SRAM Initialization. >*/
    STCU_INIT_RAM_DONE_TYPE_SRAM2_1     = 0x20U,           /**<! SRAM2_1 SRAM Select for Hardware SRAM Initialization. >*/
    STCU_INIT_RAM_DONE_TYPE_SRAM2_2     = 0x40U,           /**<! SRAM2_2 SRAM Select for Hardware SRAM Initialization. >*/
    STCU_INIT_RAM_DONE_TYPE_ITCM_CPU0   = 0x80U,           /**<! ITCM_CPU0 SRAM Select for Hardware SRAM Initialization. >*/
    STCU_INIT_RAM_DONE_TYPE_DTCM0_CPU0  = 0x100U,          /**<! DTCM0_CPU0 SRAM Select for Hardware SRAM Initialization. >*/
    STCU_INIT_RAM_DONE_TYPE_DTCM1_CPU0  = 0x200U,          /**<! DTCM1_CPU0 SRAM Select for Hardware SRAM Initialization. >*/
    STCU_INIT_RAM_DONE_TYPE_ITCM_CPU1   = 0x400U,          /**<! ITCM_CPU1 SRAM Select for Hardware SRAM Initialization. >*/
    STCU_INIT_RAM_DONE_TYPE_DTCM0_CPU1  = 0x800U,          /**<! DTCM0_CPU1 SRAM Select for Hardware SRAM Initialization. >*/
    STCU_INIT_RAM_DONE_TYPE_DTCM1_CPU1  = 0x1000U,         /**<! DTCM1_CPU1 SRAM Select for Hardware SRAM Initialization. >*/
    STCU_INIT_RAM_DONE_TYPE_ITCM_CPU2   = 0x2000U,         /**<! ITCM_CPU2 SRAM Select for Hardware SRAM Initialization. >*/
    STCU_INIT_RAM_DONE_TYPE_DTCM0_CPU2  = 0x4000U,         /**<! DTCM0_CPU2 SRAM Select for Hardware SRAM Initialization. >*/
    STCU_INIT_RAM_DONE_TYPE_DTCM1_CPU2  = 0x8000U,         /**<! DTCM1_CPU2 SRAM Select for Hardware SRAM Initialization. >*/
    STCU_INIT_RAM_DONE_TYPE_ITCM_CPU3   = 0x10000U,        /**<! ITCM_CPU2 SRAM Select for Hardware SRAM Initialization. >*/
    STCU_INIT_RAM_DONE_TYPE_DTCM0_CPU3  = 0x20000U,        /**<! DTCM0_CPU2 SRAM Select for Hardware SRAM Initialization. >*/
    STCU_INIT_RAM_DONE_TYPE_DTCM1_CPU3  = 0x40000U         /**<! DTCM1_CPU2 SRAM Select for Hardware SRAM Initialization. >*/
}STCU_InitRamDoneType;

#define STCU_PATTERN_COUNT       (0x000CU)
#define STCU_EXPECTED_MISR_VALUE (0x009186C8UL)

#endif /* _DEVICE_FEATURES_FC7300F8MDQxxxxxT1B_STCU_COMMON_H_ */
