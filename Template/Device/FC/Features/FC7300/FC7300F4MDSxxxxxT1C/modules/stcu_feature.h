#ifndef _DEVICE_FEATURES_FC7300F4MDSxxxxxT1C_STCU_COMMON_H_
#define _DEVICE_FEATURES_FC7300F4MDSxxxxxT1C_STCU_COMMON_H_

typedef enum
{
    STCU_MBIST_SEL_NONE             = 0x0000U,  /**<! No any MBist item selected. >*/
    STCU_MBIST_SEL_SRAM0            = 0x0001U,  /**<! SRAM1 SRAM Select for MBIST. >*/
    STCU_MBIST_SEL_SRAM1            = 0x0002U,  /**<! SRAM1 SRAM Select for MBIST. >*/
    STCU_MBIST_SEL_SRAM2            = 0x0004U,  /**<! SRAM2 SRAM Select for MBIST. >*/
    STCU_MBIST_SEL_ITCM             = 0x0008U,  /**<! ITCM SRAM Select for MBIST. >*/
    STCU_MBIST_SEL_DTCM             = 0x0010U,  /**<! DTCM SRAM Select for MBIST. >*/
    STCU_MBIST_SEL_CACHE            = 0x0020U,  /**<! CACHE SRAM Select for MBIST. >*/
    STCU_MBIST_SEL_SUBSYS           = 0x0040U,  /**<! HSM/FlexCore Subsystem SRAM Select for MBIST. >*/
    STCU_MBIST_SEL_SRAM_HSM         = 0x0080U,  /**<! HSM SRAM Select for MBIST. >*/
    STCU_MBIST_SEL_SRAM_DMACAN      = 0x0100U,  /**<! DMA_FLEXCAN SRAM Select for MBIST. >*/
    STCU_MBIST_SEL_ROM_HOST         = 0x0200U,  /**<! System ROM Select for MBIST. >*/
    STCU_MBIST_SEL_ROM_HSM          = 0x0400U,  /**<! HSM ROM Select for MBIST. >*/
}STCU_MbistSelType;

/** @brief MBIST done status flag. */
typedef enum
{
    STCU_MBIST_DONE_NONE             = 0x0000U,  /**<! No any MBist done flag. >*/
    STCU_MBIST_DONE_SRAM0            = 0x0001U,  /**<! SRAM1 SRAM MBIST done flag. >*/
    STCU_MBIST_DONE_SRAM1            = 0x0002U,  /**<! SRAM1 SRAM MBIST done flag. >*/
    STCU_MBIST_DONE_SRAM2            = 0x0004U,  /**<! SRAM2 SRAM MBIST done flag. >*/
    STCU_MBIST_DONE_ITCM             = 0x0008U,  /**<! ITCM SRAM MBIST done flag. >*/
    STCU_MBIST_DONE_DTCM             = 0x0010U,  /**<! DTCM SRAM MBIST done flag. >*/
    STCU_MBIST_DONE_CACHE            = 0x0020U,  /**<! CACHE SRAM MBIST done flag. >*/
    STCU_MBIST_DONE_SUBSYS           = 0x0040U,  /**<! HSM/FlexCore Subsystem SRAM MBIST done flag. >*/
    STCU_MBIST_DONE_SRAM_HSM         = 0x0080U,  /**<! HSM SRAM MBIST done flag. >*/
    STCU_MBIST_DONE_SRAM_DMACAN      = 0x0100U,  /**<! DMA_FLEXCAN SRAM MBIST done flag. >*/
    STCU_MBIST_DONE_ROM_HOST         = 0x0200U,  /**<! System ROM MBIST done flag. >*/
    STCU_MBIST_DONE_ROM_HSM          = 0x0400U,  /**<! HSM ROM MBIST done flag. >*/
}STCU_MbistDoneType;

/** @brief MBIST fail status flag. */
typedef enum
{
    STCU_MBIST_FAIL_NONE             = 0x0000U,  /**<! No any MBIST Fail Flag. >*/
    STCU_MBIST_FAIL_SRAM0            = 0x0001U,  /**<! SRAM1 SRAM MBIST Fail flag. >*/
    STCU_MBIST_FAIL_SRAM1            = 0x0002U,  /**<! SRAM1 SRAM MBIST Fail flag. >*/
    STCU_MBIST_FAIL_SRAM2            = 0x0004U,  /**<! SRAM2 SRAM MBIST Fail flag. >*/
    STCU_MBIST_FAIL_ITCM             = 0x0008U,  /**<! ITCM SRAM MBIST Fail flag. >*/
    STCU_MBIST_FAIL_DTCM             = 0x0010U,  /**<! DTCM SRAM MBIST Fail flag. >*/
    STCU_MBIST_FAIL_CACHE            = 0x0020U,  /**<! CACHE SRAM MBIST Fail flag. >*/
    STCU_MBIST_FAIL_SUBSYS           = 0x0040U,  /**<! HSM/FlexCore Subsystem SRAM MBIST Fail flag. >*/
    STCU_MBIST_FAIL_SRAM_HSM         = 0x0080U,  /**<! HSM SRAM MBIST Fail flag. >*/
    STCU_MBIST_FAIL_SRAM_DMACAN      = 0x0100U,  /**<! DMA_FLEXCAN SRAM MBIST Fail flag. >*/
    STCU_MBIST_FAIL_ROM_HOST         = 0x0200U,  /**<! System ROM MBIST Fail flag. >*/
    STCU_MBIST_FAIL_ROM_HSM          = 0x0400U,  /**<! HSM ROM MBIST Fail flag. >*/
}STCU_MbistFailedType;

/** @brief The items select for Hardware SRAM Initialization. */
typedef enum
{
    STCU_INIT_RAM_TYPE_NONE        = 0x00U,     /**<! No any SRAM need to be initialized. >*/
    STCU_INIT_RAM_TYPE_SRAM0       = 0x01U,     /**<! SRAM0 SRAM Select for Hardware SRAM Initialization. >*/
    STCU_INIT_RAM_TYPE_SRAM1       = 0x02U,     /**<! SRAM1 SRAM Select for Hardware SRAM Initialization. >*/
    STCU_INIT_RAM_TYPE_SRAM2       = 0x04U,     /**<! SRAM2 SRAM Select for Hardware SRAM Initialization. >*/
    STCU_INIT_RAM_TYPE_ITCM_CPU0   = 0x08U,     /**<! ITCM_CPU0 SRAM Select for Hardware SRAM Initialization. >*/
    STCU_INIT_RAM_TYPE_DTCM_CPU0   = 0x10U,     /**<! DTCM_CPU0 SRAM Select for Hardware SRAM Initialization. >*/
    STCU_INIT_RAM_TYPE_ITCM_CPU1   = 0x20U,     /**<! ITCM_CPU1 SRAM Select for Hardware SRAM Initialization. >*/
    STCU_INIT_RAM_TYPE_DTCM_CPU1   = 0x40U,     /**<! DTCM_CPU1 SRAM Select for Hardware SRAM Initialization. >*/
}STCU_InitRamType;

/** @brief Init Ram done status flag. */
typedef enum
{
    STCU_INIT_RAM_DONE_TYPE_NONE      = 0x00U,  /**<! No any Init Ram done flag. >*/
    STCU_INIT_RAM_DONE_TYPE_SRAM0     = 0x01U,  /**<! SRAM0 SRAM Initialization Done Flag. >*/
    STCU_INIT_RAM_DONE_TYPE_SRAM1     = 0x02U,  /**<! SRAM1 SRAM Initialization Done Flag. >*/
    STCU_INIT_RAM_DONE_TYPE_SRAM2     = 0x04U,  /**<! SRAM2 SRAM Initialization Done Flag. >*/
    STCU_INIT_RAM_DONE_TYPE_ITCM_CPU0 = 0x08U,  /**<! ITCM_CPU0 SRAM Initialization Done Flag. >*/
    STCU_INIT_RAM_DONE_TYPE_DTCM_CPU0 = 0x10U,  /**<! DTCM_CPU0 SRAM Initialization Done Flag. >*/
    STCU_INIT_RAM_DONE_TYPE_ITCM_CPU1 = 0x20U,  /**<! ITCM_CPU1 SRAM Initialization Done Flag. >*/
    STCU_INIT_RAM_DONE_TYPE_DTCM_CPU1 = 0x40U,  /**<! DTCM_CPU1 SRAM Initialization Done Flag. >*/
}STCU_InitRamDoneType;

#define STCU_PATTERN_COUNT       (0x000AU)
#define STCU_EXPECTED_MISR_VALUE (0x0046CBB1UL)

#endif /* _DEVICE_FEATURES_FC7300F4MDSxxxxxT1C_STCU_COMMON_H_ */
