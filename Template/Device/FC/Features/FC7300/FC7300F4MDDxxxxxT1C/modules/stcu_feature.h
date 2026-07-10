#ifndef _DEVICE_FEATURES_FC7300F4MDDxxxxxT1C_STCU_COMMON_H_
#define _DEVICE_FEATURES_FC7300F4MDDxxxxxT1C_STCU_COMMON_H_

typedef enum
{
    STCU_MBIST_SEL_NONE             = 0x0000U,  /**<! No any MBist item selected. >*/
    STCU_MBIST_SEL_SRAM1            = 0x0001U,  /**<! SRAM1 SRAM Select for MBIST. >*/
    STCU_MBIST_SEL_SRAM2_0          = 0x0002U,  /**<! SRAM2_0 SRAM Select for MBIST. >*/
    STCU_MBIST_SEL_SRAM2_1          = 0x0004U,  /**<! SRAM2_1 SRAM Select for MBIST. >*/
    STCU_MBIST_SEL_ITCM_CPU0        = 0x0008U,  /**<! ITCM_CPU0 SRAM Select for MBIST. >*/
    STCU_MBIST_SEL_SRAM0_DTCM_CPU0  = 0x0010U,  /**<! SRAM0(0~64k) DTCM_CPU0 SRAM Select for MBIST. >*/
    STCU_MBIST_SEL_ITCM_CPU1        = 0x0020U,  /**<! ITCM_CPU1 SRAM Select for MBIST. >*/
    STCU_MBIST_SEL_SRAM0_DTCM0_CPU1 = 0x0040U,  /**<! SRAM0(64~128k)DTCM_CPU1 SRAM Select for MBIST. >*/
    STCU_MBIST_SEL_CACHE_CPU0       = 0x0080U,  /**<! CACHE_CPU0 SRAM Select for MBIST. >*/
    STCU_MBIST_SEL_CACHE_CPU1       = 0x0100U,  /**<! CACHE_CPU1 SRAM Select for MBIST. >*/
    STCU_MBIST_SEL_SUBSYS           = 0x0200U,  /**<! HSM/FlexCore Subsystem SRAM Select for MBIST. >*/
    STCU_MBIST_SEL_SRAM_HSM         = 0x0400U,  /**<! HSM SRAM Select for MBIST. >*/
    STCU_MBIST_SEL_SRAM_DMACAN      = 0x0800U,  /**<! DMA_FLEXCAN SRAM Select for MBIST. >*/
    STCU_MBIST_SEL_SRAM_ENET        = 0x1000U,  /**<! ENET SRAM Select for MBIST. >*/
    STCU_MBIST_SEL_SRAM_ETB         = 0x2000U,  /**<! ETB SRAM Select for MBIST. >*/
    STCU_MBIST_SEL_ROM_HOST         = 0x4000U,  /**<! System ROM Select for MBIST. >*/
    STCU_MBIST_SEL_ROM_HSM          = 0x8000U,  /**<! HSM ROM Select for MBIST. >*/
}STCU_MbistSelType;

/** @brief MBIST done status flag. */
typedef enum
{
    STCU_MBIST_DONE_NONE             = 0x0000U,  /**<! No any MBIST done flag. >*/
    STCU_MBIST_DONE_SRAM1            = 0x0001U,  /**<! SRAM1 SRAM MBIST done flag. >*/
    STCU_MBIST_DONE_SRAM2_0          = 0x0002U,  /**<! SRAM2_0 SRAM MBIST done flag. >*/
    STCU_MBIST_DONE_SRAM2_1          = 0x0004U,  /**<! SRAM2_1 SRAM MBIST done flag. >*/
    STCU_MBIST_DONE_ITCM_CPU0        = 0x0008U,  /**<! ITCM_CPU0 SRAM MBIST done flag. >*/
    STCU_MBIST_DONE_SRAM0_DTCM_CPU0  = 0x0010U,  /**<! SRAM0(0~64k) DTCM_CPU0 SRAM MBIST done flag. >*/
    STCU_MBIST_DONE_ITCM_CPU1        = 0x0020U,  /**<! ITCM_CPU1 SRAM MBIST done flag. >*/
    STCU_MBIST_DONE_SRAM0_DTCM0_CPU1 = 0x0040U,  /**<! SRAM0(64~128k)DTCM_CPU1 SRAM MBIST done flag. >*/
    STCU_MBIST_DONE_CACHE_CPU0       = 0x0080U,  /**<! CACHE_CPU0 SRAM MBIST done flag. >*/
    STCU_MBIST_DONE_CACHE_CPU1       = 0x0100U,  /**<! CACHE_CPU1 SRAM MBIST done flag. >*/
    STCU_MBIST_DONE_SUBSYS           = 0x0200U,  /**<! HSM/FlexCore Subsystem SRAM MBIST done flag. >*/
    STCU_MBIST_DONE_SRAM_HSM         = 0x0400U,  /**<! HSM SRAM MBIST done flag. >*/
    STCU_MBIST_DONE_SRAM_DMACAN      = 0x0800U,  /**<! DMA_FLEXCAN SRAM MBIST done flag. >*/
    STCU_MBIST_DONE_SRAM_ENET        = 0x1000U,  /**<! ENET SRAM MBIST done flag. >*/
    STCU_MBIST_DONE_SRAM_ETB         = 0x2000U,  /**<! ETB SRAM MBIST done flag. >*/
    STCU_MBIST_DONE_ROM_HOST         = 0x4000U,  /**<! System ROM MBIST done flag. >*/
    STCU_MBIST_DONE_ROM_HSM          = 0x8000U,  /**<! HSM ROM MBIST done flag. >*/
}STCU_MbistDoneType;

/** @brief MBIST fail status flag. */
typedef enum
{
    STCU_MBIST_FAIL_NONE             = 0x0000U,  /**<! No any MBIST Fail Flag. >*/
    STCU_MBIST_FAIL_SRAM1            = 0x0001U,  /**<! SRAM1 SRAM MBIST Fail Flag. >*/
    STCU_MBIST_FAIL_SRAM2_0          = 0x0002U,  /**<! SRAM2_0 SRAM MBIST Fail Flag. >*/
    STCU_MBIST_FAIL_SRAM2_1          = 0x0004U,  /**<! SRAM2_1 SRAM MBIST Fail Flag. >*/
    STCU_MBIST_FAIL_ITCM_CPU0        = 0x0008U,  /**<! ITCM_CPU0 SRAM MBIST Fail Flag. >*/
    STCU_MBIST_FAIL_SRAM0_DTCM_CPU0  = 0x0010U,  /**<! SRAM0(0~64k) DTCM_CPU0 SRAM MBIST Fail Flag. >*/
    STCU_MBIST_FAIL_ITCM_CPU1        = 0x0020U,  /**<! ITCM_CPU1 SRAM MBIST Fail Flag. >*/
    STCU_MBIST_FAIL_SRAM0_DTCM0_CPU1 = 0x0040U,  /**<! SRAM0(64~128k)DTCM_CPU1 SRAM MBIST Fail Flag. >*/
    STCU_MBIST_FAIL_CACHE_CPU0       = 0x0080U,  /**<! CACHE_CPU0 SRAM MBIST Fail Flag. >*/
    STCU_MBIST_FAIL_CACHE_CPU1       = 0x0100U,  /**<! CACHE_CPU1 SRAM MBIST Fail Flag. >*/
    STCU_MBIST_FAIL_SUBSYS           = 0x0200U,  /**<! HSM/FlexCore Subsystem SRAM MBIST Fail Flag. >*/
    STCU_MBIST_FAIL_SRAM_HSM         = 0x0400U,  /**<! HSM SRAM MBIST Fail Flag. >*/
    STCU_MBIST_FAIL_SRAM_DMACAN      = 0x0800U,  /**<! DMA_FLEXCAN SRAM MBIST Fail Flag. >*/
    STCU_MBIST_FAIL_SRAM_ENET        = 0x1000U,  /**<! ENET SRAM MBIST Fail Flag. >*/
    STCU_MBIST_FAIL_SRAM_ETB         = 0x2000U,  /**<! ETB SRAM MBIST Fail Flag. >*/
    STCU_MBIST_FAIL_ROM_HOST         = 0x4000U,  /**<! System ROM MBIST Fail Flag. >*/
    STCU_MBIST_FAIL_ROM_HSM          = 0x8000U,  /**<! HSM ROM MBIST Fail Flag. >*/
}STCU_MbistFailedType;

/** @brief The items select for Hardware SRAM Initialization. */
typedef enum
{
    STCU_INIT_RAM_TYPE_NONE        = 0x00U,     /**<! No any SRAM need to be initialized. >*/
    STCU_INIT_RAM_TYPE_SRAM0       = 0x01U,     /**<! SRAM0 SRAM Select for Hardware SRAM Initialization. >*/
    STCU_INIT_RAM_TYPE_SRAM1       = 0x02U,     /**<! SRAM1 SRAM Select for Hardware SRAM Initialization. >*/
    STCU_INIT_RAM_TYPE_SRAM2_0     = 0x04U,     /**<! SRAM2_0 SRAM Select for Hardware SRAM Initialization. >*/
    STCU_INIT_RAM_TYPE_SRAM2_1     = 0x08U,     /**<! SRAM2_1 SRAM Select for Hardware SRAM Initialization. >*/
    STCU_INIT_RAM_TYPE_ITCM_CPU0   = 0x10U,     /**<! ITCM_CPU0 SRAM Select for Hardware SRAM Initialization. >*/
    STCU_INIT_RAM_TYPE_DTCM_CPU0   = 0x20U,     /**<! DTCM_CPU0 SRAM Select for Hardware SRAM Initialization. >*/
    STCU_INIT_RAM_TYPE_ITCM_CPU1   = 0x40U,     /**<! ITCM_CPU1 SRAM Select for Hardware SRAM Initialization. >*/
    STCU_INIT_RAM_TYPE_DTCM_CPU1   = 0x80U,     /**<! DTCM_CPU1 SRAM Select for Hardware SRAM Initialization. >*/
}STCU_InitRamType;

/** @brief Init Ram done status flag. */
typedef enum
{
    STCU_INIT_RAM_DONE_TYPE_NONE      = 0x00U,  /**<! No any Init Ram done flag. >*/
    STCU_INIT_RAM_DONE_TYPE_SRAM0     = 0x01U,  /**<! SRAM0 SRAM Initialization Done Flag. >*/
    STCU_INIT_RAM_DONE_TYPE_SRAM1     = 0x02U,  /**<! SRAM1 SRAM Initialization Done Flag. >*/
    STCU_INIT_RAM_DONE_TYPE_SRAM2_0   = 0x04U,  /**<! SRAM2_0 SRAM Initialization Done Flag. >*/
    STCU_INIT_RAM_DONE_TYPE_SRAM2_1   = 0x08U,  /**<! SRAM2_1 SRAM Initialization Done Flag. >*/
    STCU_INIT_RAM_DONE_TYPE_ITCM_CPU0 = 0x10U,  /**<! ITCM_CPU0 SRAM Initialization Done Flag. >*/
    STCU_INIT_RAM_DONE_TYPE_DTCM_CPU0 = 0x20U,  /**<! DTCM_CPU0 SRAM Initialization Done Flag. >*/
    STCU_INIT_RAM_DONE_TYPE_ITCM_CPU1 = 0x40U,  /**<! ITCM_CPU1 SRAM Initialization Done Flag. >*/
    STCU_INIT_RAM_DONE_TYPE_DTCM_CPU1 = 0x80U,  /**<! DTCM_CPU1 SRAM Initialization Done Flag. >*/
}STCU_InitRamDoneType;

#define STCU_PATTERN_COUNT       (0x000AU)
#define STCU_EXPECTED_MISR_VALUE (0x00E8F794UL)

#endif /* _DEVICE_FEATURES_FC7300F4MDDxxxxxT1C_STCU_COMMON_H_ */
