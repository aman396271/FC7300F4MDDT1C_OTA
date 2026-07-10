#ifndef _DEVICE_FEATURES_FC7300F4MDDxxxxxT1B_STCU_COMMON_H_
#define _DEVICE_FEATURES_FC7300F4MDDxxxxxT1B_STCU_COMMON_H_

typedef enum
{
    STCU_MBIST_SEL_NONE        = 0x00U,        /**<! No any MBist item selected. >*/
    STCU_MBIST_SEL_SRAM0       = 0x01U,        /**<! SRAM0 SRAM Select for MBIST. >*/
    STCU_MBIST_SEL_SRAM1       = 0x02U,        /**<! SRAM1 SRAM Select for MBIST. >*/
    STCU_MBIST_SEL_ITCM_CPU0   = 0x10U,        /**<! ITCM_CPU0 SRAM Select for MBIST. >*/
    STCU_MBIST_SEL_DTCM0_CPU0  = 0x20U,        /**<! DTCM0_CPU0 SRAM Select for MBIST. >*/
    STCU_MBIST_SEL_DTCM1_CPU0  = 0x40U,        /**<! DTCM1_CPU0 SRAM Select for MBIST. >*/
    STCU_MBIST_SEL_ITCM_CPU1   = 0x80U,        /**<! ITCM_CPU1 SRAM Select for MBIST. >*/
    STCU_MBIST_SEL_DTCM0_CPU1  = 0x100U,       /**<! DTCM0_CPU1 SRAM Select for MBIST. >*/
    STCU_MBIST_SEL_DTCM1_CPU1  = 0x200U,       /**<! DTCM1_CPU1 SRAM Select for MBIST. >*/
    STCU_MBIST_SEL_CACHE_CPU0  = 0x2000U,      /**<! CACHE_CPU0 SRAM Select for MBIST. >*/
    STCU_MBIST_SEL_CACHE_CPU1  = 0x4000U,      /**<! CACHE_CPU1 SRAM Select for MBIST. >*/
    STCU_MBIST_SEL_SRAM_HSM    = 0x10000U,     /**<! HSM SRAM Select for MBIST. >*/
    STCU_MBIST_SEL_SRAM_DMACAN = 0x20000U,     /**<! DMA_FLEXCAN SRAM Select for MBIST. >*/
    STCU_MBIST_SEL_SRAM_ENET   = 0x40000U,     /**<! ENET SRAM Select for MBIST. >*/
    STCU_MBIST_SEL_SRAM_ETB    = 0x80000U,     /**<! ETB SRAM Select for MBIST. >*/
    STCU_MBIST_SEL_ROM_HOST    = 0x100000U,    /**<! System ROM Select for MBIST. >*/
    STCU_MBIST_SEL_ROM_HSM     = 0x200000U     /**<! HSM ROM Select for MBIST. >*/
}STCU_MbistSelType;

/** @brief MBIST done status flag. */
typedef enum
{
    STCU_MBIST_DONE_NONE        = 0x00U,       /**<! No any MBIST done flag. >*/
    STCU_MBIST_DONE_SRAM0       = 0x01U,       /**<! SRAM0 SRAM MBIST Done Flag. >*/
    STCU_MBIST_DONE_SRAM1       = 0x02U,       /**<! SRAM1 SRAM MBIST Done Flag. >*/
    STCU_MBIST_DONE_ITCM_CPU0   = 0x10U,       /**<! ITCM_CPU0 SRAM MBIST Done Flag. >*/
    STCU_MBIST_DONE_DTCM0_CPU0  = 0x20U,       /**<! DTCM0_CPU0 SRAM MBIST Done Flag. >*/
    STCU_MBIST_DONE_DTCM1_CPU0  = 0x40U,       /**<! DTCM1_CPU0 SRAM MBIST Done Flag. >*/
    STCU_MBIST_DONE_ITCM_CPU1   = 0x80U,       /**<! ITCM_CPU1 SRAM MBIST Done Flag. >*/
    STCU_MBIST_DONE_DTCM0_CPU1  = 0x100U,      /**<! DTCM0_CPU1 SRAM MBIST Done Flag. >*/
    STCU_MBIST_DONE_DTCM1_CPU1  = 0x200U,      /**<! DTCM1_CPU1 SRAM MBIST Done Flag. >*/
    STCU_MBIST_DONE_CACHE_CPU0  = 0x2000U,     /**<! CACHE_CPU0 SRAM MBIST Done Flag. >*/
    STCU_MBIST_DONE_CACHE_CPU1  = 0x4000U,     /**<! CACHE_CPU1 SRAM MBIST Done Flag. >*/
    STCU_MBIST_DONE_SRAM_HSM    = 0x10000U,    /**<! HSM SRAM MBIST Done Flag. >*/
    STCU_MBIST_DONE_SRAM_DMACAN = 0x20000U,    /**<! DMA_FLEXCAN SRAM MBIST Done Flag. >*/
    STCU_MBIST_DONE_SRAM_ENET   = 0x40000U,    /**<! ENET SRAM MBIST Done Flag. >*/
    STCU_MBIST_DONE_SRAM_ETB    = 0x80000U,    /**<! ETB SRAM MBIST Done Flag. >*/
    STCU_MBIST_DONE_ROM_HOST    = 0x100000U,   /**<! System ROM MBIST Done Flag. >*/
    STCU_MBIST_DONE_ROM_HSM     = 0x200000U    /**<! HSM ROM MBIST Done Flag. >*/
}STCU_MbistDoneType;

/** @brief MBIST fail status flag. */
typedef enum
{
    STCU_MBIST_FAIL_NONE        = 0x00U,        /**<! No any MBIST fail flag. >*/
    STCU_MBIST_FAIL_SRAM0       = 0x01U,        /**<! SRAM0 SRAM MBIST Fail Flag. >*/
    STCU_MBIST_FAIL_SRAM1       = 0x02U,        /**<! SRAM1 SRAM MBIST Fail Flag. >*/
    STCU_MBIST_FAIL_ITCM_CPU0   = 0x10U,        /**<! ITCM_CPU0 SRAM MBIST Fail Flag. >*/
    STCU_MBIST_FAIL_DTCM0_CPU0  = 0x20U,        /**<! DTCM0_CPU0 SRAM MBIST Fail Flag. >*/
    STCU_MBIST_FAIL_DTCM1_CPU0  = 0x40U,        /**<! DTCM1_CPU0 SRAM MBIST Fail Flag. >*/
    STCU_MBIST_FAIL_ITCM_CPU1   = 0x80U,        /**<! ITCM_CPU1 SRAM MBIST Fail Flag. >*/
    STCU_MBIST_FAIL_DTCM0_CPU1  = 0x100U,       /**<! DTCM0_CPU1 SRAM MBIST Fail Flag. >*/
    STCU_MBIST_FAIL_DTCM1_CPU1  = 0x200U,       /**<! DTCM1_CPU1 SRAM MBIST Fail Flag. >*/
    STCU_MBIST_FAIL_CACHE_CPU0  = 0x2000U,      /**<! CACHE_CPU0 SRAM MBIST Fail Flag. >*/
    STCU_MBIST_FAIL_CACHE_CPU1  = 0x4000U,      /**<! CACHE_CPU1 SRAM MBIST Fail Flag. >*/
    STCU_MBIST_FAIL_SRAM_HSM    = 0x10000U,     /**<! HSM SRAM MBIST fail flag. >*/
    STCU_MBIST_FAIL_SRAM_DMACAN = 0x20000U,     /**<! DMA_FLEXCAN SRAM MBIST fail flag. >*/
    STCU_MBIST_FAIL_SRAM_ENET   = 0x40000U,     /**<! ENET SRAM MBIST fail flag. >*/
    STCU_MBIST_FAIL_SRAM_ETB    = 0x80000U,     /**<! ETB SRAM MBIST Fail Flag. >*/
    STCU_MBIST_FAIL_ROM_HOST    = 0x100000U,    /**<! System ROM MBIST Fail Flag. >*/
    STCU_MBIST_FAIL_ROM_HSM     = 0x200000U     /**<! HSM ROM MBIST Fail Flag. >*/
}STCU_MbistFailedType;

/** @brief The items select for Hardware SRAM Initialization. */
typedef enum
{
    STCU_INIT_RAM_TYPE_NONE        = 0x00U,           /**<! No any SRAM need to be initialized. >*/
    STCU_INIT_RAM_TYPE_SRAM0       = 0x01U,           /**<! SRAM0 SRAM Select for Hardware SRAM Initialization. >*/
    STCU_INIT_RAM_TYPE_SRAM1       = 0x02U,           /**<! SRAM1 SRAM Select for Hardware SRAM Initialization. >*/
    STCU_INIT_RAM_TYPE_ITCM_CPU0   = 0x10U,           /**<! ITCM_CPU0 SRAM Select for Hardware SRAM Initialization. >*/
    STCU_INIT_RAM_TYPE_DTCM0_CPU0  = 0x20U,           /**<! DTCM0_CPU0 SRAM Select for Hardware SRAM Initialization. >*/
    STCU_INIT_RAM_TYPE_DTCM1_CPU0  = 0x40U,           /**<! DTCM1_CPU0 SRAM Select for Hardware SRAM Initialization. >*/
    STCU_INIT_RAM_TYPE_ITCM_CPU1   = 0x80U,           /**<! ITCM_CPU1 SRAM Select for Hardware SRAM Initialization. >*/
    STCU_INIT_RAM_TYPE_DTCM0_CPU1  = 0x100U,          /**<! DTCM0_CPU1 SRAM Select for Hardware SRAM Initialization. >*/
    STCU_INIT_RAM_TYPE_DTCM1_CPU1  = 0x200U,          /**<! DTCM1_CPU1 SRAM Select for Hardware SRAM Initialization. >*/
}STCU_InitRamType;

/** @brief Init Ram done status flag. */
typedef enum
{
    STCU_INIT_RAM_DONE_TYPE_NONE        = 0x00U,       /**<! No any Init Ram done flag. >*/
    STCU_INIT_RAM_DONE_TYPE_SRAM0       = 0x01U,       /**<! SRAM0 SRAM Initialization Done Flag. >*/
    STCU_INIT_RAM_DONE_TYPE_SRAM1       = 0x02U,       /**<! SRAM1 SRAM Initialization Done Flag. >*/
    STCU_INIT_RAM_DONE_TYPE_ITCM_CPU0   = 0x10U,       /**<! ITCM_CPU0 SRAM Initialization Done Flag. >*/
    STCU_INIT_RAM_DONE_TYPE_DTCM0_CPU0  = 0x20U,       /**<! DTCM0_CPU0 SRAM Initialization Done Flag. >*/
    STCU_INIT_RAM_DONE_TYPE_DTCM1_CPU0  = 0x40U,       /**<! DTCM1_CPU0 SRAM Initialization Done Flag. >*/
    STCU_INIT_RAM_DONE_TYPE_ITCM_CPU1   = 0x80U,       /**<! ITCM_CPU1 SRAM Initialization Done Flag. >*/
    STCU_INIT_RAM_DONE_TYPE_DTCM0_CPU1  = 0x100U,      /**<! DTCM0_CPU1 SRAM Initialization Done Flag. >*/
    STCU_INIT_RAM_DONE_TYPE_DTCM1_CPU1  = 0x200U,      /**<! DTCM1_CPU1 SRAM Initialization Done Flag. >*/
}STCU_InitRamDoneType;

#define STCU_PATTERN_COUNT       (0x0009U)
#define STCU_EXPECTED_MISR_VALUE (0x00E983EAUL)

#endif /* _DEVICE_FEATURES_FC7300F4MDDxxxxxT1B_STCU_COMMON_H_ */
