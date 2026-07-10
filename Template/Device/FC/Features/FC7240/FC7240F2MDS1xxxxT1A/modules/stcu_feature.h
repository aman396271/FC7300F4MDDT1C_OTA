#ifndef _DEVICE_FEATURES_FC7240F2MDS1_STCU_COMMON_H_
#define _DEVICE_FEATURES_FC7240F2MDS1_STCU_COMMON_H_

/** @brief The items select for MBIST */
typedef enum
{
    STCU_MBIST_SEL_NONE        = 0x00U,        /**<! No any MBist item selected. >*/
    STCU_MBIST_SEL_SRAM        = 0x01U,        /**<! SRAM Select for MBIST. >*/
    STCU_MBIST_SEL_ITCM_CPU0   = 0x02U,        /**<! ITCM_CPU0 SRAM Select for MBIST. >*/
    STCU_MBIST_SEL_DTCM0_CPU0  = 0x04U,        /**<! DTCM0_CPU0 SRAM Select for MBIST. >*/
    STCU_MBIST_SEL_DTCM1_CPU0  = 0x08U,        /**<! DTCM1_CPU0 SRAM Select for MBIST. >*/
    STCU_MBIST_SEL_CACHE_CPU0  = 0x10U,        /**<! CACHE_CPU0 SRAM Select for MBIST. >*/
	STCU_MBIST_SEL_SUBSYS      = 0x20U,        /**<! SUBSYS SRAM Select for MBIST. >*/
    STCU_MBIST_SEL_SRAM_HSM    = 0x40U,        /**<! HSM SRAM Select for MBIST. >*/
    STCU_MBIST_SEL_SRAM_DMACAN = 0x80U,        /**<! DMA_FLEXCAN SRAM Select for MBIST. >*/
    STCU_MBIST_SEL_ROM_HOST    = 0x100U,       /**<! System ROM Select for MBIST. >*/
    STCU_MBIST_SEL_ROM_HSM     = 0x200U        /**<! HSM ROM Select for MBIST. >*/
}STCU_MbistSelType;

/** @brief MBIST done status flag. */
typedef enum
{
    STCU_MBIST_DONE_NONE        = 0x00U,       /**<! No any MBIST done flag. >*/
    STCU_MBIST_DONE_SRAM        = 0x01U,       /**<! SRAM MBIST Done Flag. >*/
    STCU_MBIST_DONE_ITCM_CPU0   = 0x02U,       /**<! ITCM_CPU0 SRAM MBIST Done Flag. >*/
    STCU_MBIST_DONE_DTCM0_CPU0  = 0x04U,       /**<! DTCM0_CPU0 SRAM MBIST Done Flag. >*/
    STCU_MBIST_DONE_DTCM1_CPU0  = 0x08U,       /**<! DTCM1_CPU0 SRAM MBIST Done Flag. >*/
    STCU_MBIST_DONE_CACHE_CPU0  = 0x10U,       /**<! CACHE_CPU0 SRAM MBIST Done Flag. >*/
	STCU_MBIST_DONE_SUBSYS      = 0x20U,       /**<! SUBSYS SRAM MBIST Done. >*/
    STCU_MBIST_DONE_SRAM_HSM    = 0x40U,       /**<! HSM SRAM MBIST Done Flag. >*/
    STCU_MBIST_DONE_SRAM_DMACAN = 0x80U,       /**<! DMA_FLEXCAN SRAM MBIST Done Flag. >*/
    STCU_MBIST_DONE_ROM_HOST    = 0x100U,      /**<! System ROM MBIST Done Flag. >*/
    STCU_MBIST_DONE_ROM_HSM     = 0x200U       /**<! HSM ROM MBIST Done Flag. >*/
}STCU_MbistDoneType;

/** @brief MBIST fail status flag. */
typedef enum
{
    STCU_MBIST_FAIL_NONE        = 0x00U,        /**<! No any MBIST fail flag. >*/
    STCU_MBIST_FAIL_SRAM        = 0x01U,        /**<! SRAM MBIST Fail Flag. >*/
    STCU_MBIST_FAIL_ITCM_CPU0   = 0x02U,        /**<! ITCM_CPU0 SRAM MBIST Fail Flag. >*/
    STCU_MBIST_FAIL_DTCM0_CPU0  = 0x04U,        /**<! DTCM0_CPU0 SRAM MBIST Fail Flag. >*/
    STCU_MBIST_FAIL_DTCM1_CPU0  = 0x08U,        /**<! DTCM1_CPU0 SRAM MBIST Fail Flag. >*/
    STCU_MBIST_FAIL_CACHE_CPU0  = 0x10U,        /**<! CACHE_CPU0 SRAM MBIST Fail Flag. >*/
	STCU_MBIST_FAIL_SUBSYS      = 0x20U,        /**<! SUBSYS SRAM MBIST Fail Flag. >*/
	STCU_MBIST_FAIL_SRAM_HSM    = 0x40U,        /**<! HSM SRAM MBIST Fail Flag. >*/
    STCU_MBIST_FAIL_SRAM_DMACAN = 0x80U,        /**<! DMA_FLEXCAN SRAM MBIST fail flag. >*/
    STCU_MBIST_FAIL_ROM_HOST    = 0x100U,    /**<! System ROM MBIST Fail Flag. >*/
    STCU_MBIST_FAIL_ROM_HSM     = 0x200U     /**<! HSM ROM MBIST Fail Flag. >*/
}STCU_MbistFailedType;

/** @brief The items select for Hardware SRAM Initialization. */
typedef enum
{
    STCU_INIT_RAM_TYPE_NONE        = 0x00U,           /**<! No any SRAM need to be initialized. >*/
    STCU_INIT_RAM_TYPE_SRAM        = 0x01U,           /**<! SRAM Select for Hardware SRAM Initialization. >*/
    STCU_INIT_RAM_TYPE_ITCM_CPU0   = 0x02U,           /**<! ITCM_CPU0 SRAM Select for Hardware SRAM Initialization. >*/
    STCU_INIT_RAM_TYPE_DTCM0_CPU0  = 0x04U,           /**<! DTCM0_CPU0 SRAM Select for Hardware SRAM Initialization. >*/
    STCU_INIT_RAM_TYPE_DTCM1_CPU0  = 0x08U,           /**<! DTCM1_CPU0 SRAM Select for Hardware SRAM Initialization. >*/
}STCU_InitRamType;

/** @brief Init Ram done status flag. */
typedef enum
{
    STCU_INIT_RAM_DONE_TYPE_NONE        = 0x00U,       /**<! No any Init Ram done flag. >*/
    STCU_INIT_RAM_DONE_TYPE_SRAM        = 0x01U,       /**<! SRAM Initialization Done Flag. >*/
    STCU_INIT_RAM_DONE_TYPE_ITCM_CPU0   = 0x02U,       /**<! ITCM_CPU0 SRAM Initialization Done Flag. >*/
    STCU_INIT_RAM_DONE_TYPE_DTCM0_CPU0  = 0x04U,       /**<! DTCM0_CPU0 SRAM Initialization Done Flag. >*/
    STCU_INIT_RAM_DONE_TYPE_DTCM1_CPU0  = 0x08U,       /**<! DTCM1_CPU0 SRAM Initialization Done Flag. >*/
}STCU_InitRamDoneType;

#define STCU_PATTERN_COUNT       (0x000BU)
#define STCU_EXPECTED_MISR_VALUE (0x00AFB99BUL)

#endif /* _DEVICE_FEATURES_FC7240F2MDS1_STCU_COMMON_H_ */
