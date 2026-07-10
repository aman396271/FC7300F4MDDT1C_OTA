#ifndef _DEVICE_FEATURES_FC7300F8MDQxxxxxT1B_FLASH_COMMON_H_
#define _DEVICE_FEATURES_FC7300F8MDQxxxxxT1B_FLASH_COMMON_H_

#define SRAM_ADDR_START                           0x21000000U
#define SRAM_ADDR_END                             0x21017FFFU

#define FLASHDRV_ADDR                             0x04810400U /* flash api address in rom */

#define FLASH                                     ((FLASH_ROM_API_ENTRY_T*)FLASHDRV_ADDR)
#define FLASHDRV_BASE_ADDR                        {FLASH}
#define FLASH_INSTANCE_COUNT                      0x1U

#define FLASH_FC7300F8MDQ                        STD_ON


/** Program maximum */
#define FLASH_PROGRAM_PAGE_MAX_SIZE               0x80U    /* 128 bytes  */
#define FLASH_256KB_SIZE                          0x00040000U
/* ------------------------- PFlash ------------------------ */
/** PFlash start address */
#define PFLASH_ADDR_START                         0x01000000U
/** Program minimum size */
#define PFLASH_PROGRAM_PAGE_MIN_SIZE              0x08U    /* 8 bytes   */
/** Erase size */
#define PFLASH_ERASE_SECTOR_SIZE                  0x1000U   /* 4 KBytes   */
/** Flash end address */
#define PFLASH_ADDR_END                           0x017FFFFFU
/** Erase value of flash memory       */
#define PFLASH_ERASED_VALUE                       0xFFU
/** 8 PFlash Banks, every bank is 2MB */
#define PFLASH_BANK_NUM                           0x08U
/** Flash bank size */
#define PFLASH_BANK_SIZE                          0x100000U
/** Flash phantom offset */
#define PFLASH_PHANTOM_OFFSET                     (PFLASH_BANK_SIZE - FLASH_256KB_SIZE)
/** PFlash total size */
#define PFLASH_SIZE                               0x800000U

/* ------------------------- DFlash ------------------------ */

/** DFlash total size */
#define DFLASH_SIZE                               0x00040000U  /* 256KB */
/** DFlash start address */
#define DFLASH_ADDR_START                         0x04000000U
/** DFlash end address */
#define DFLASH_ADDR_END                           0x0405FFFFU
/** Program minimum size */
#define DFLASH_PROGRAM_PAGE_MIN_SIZE              0x08U    /* 8 bytes   */
/** Erase size */
#define DFLASH_ERASE_SECTOR_SIZE                  0x800U  /* 2 KBytes   */
/** Erase value of flash memory       */
#define DFLASH_ERASED_VALUE                       0xFFU
/** 1 DFlash Banks, every bank is 2MB */
#define DFLASH_BANK_NUM                           0x03U
/** DFlash Bank 0 size */
#define DFLASH_BANK_SIZE                          0x00020000U
#define DFLASH_INDEX                              0x08U

/* ------------------------- NVR ------------------------ */
/** NVR start address */
#define NVR_FLASH_ADDR_START                      0x04400000U
/** NVR0 end address */
#define NVR_FLASH_ADDR_END                        0x04425FFFU
/** Program minimum size */
#define NVR_PROGRAM_PAGE_MIN_SIZE                 0x08U
/** NVR erase sector size */
#define NVR_ERASE_SECTOR_SIZE                     0x800U /* 2048 bytes */
/** NVR program maximum */
#define NVRFLASH_PROGRAM_PAGE_MAX_SIZE            0x80U  /* 128 bytes */
// /** NVR num */
// #define NVR_NUM                                   3U
// /** NVR Sector num */
// #define NVR_SECTOR_NUM                            1U
/** Program minimum size */
#define FLASH_PORT0_ADDR_START                    0x01000000U
#define FLASH_PORT0_ADDR_END                      0x013FFFFFU
#define FLASH_PORT1_ADDR_START                    0x01400000U
#define FLASH_PORT1_ADDR_END                      0x017FFFFFU
#define FLASH_PORT2_ADDR_START                    DFLASH_ADDR_START
#define FLASH_PORT2_ADDR_END                      DFLASH_ADDR_END



/**********************************************************************************************************************/
typedef uint32_t status_t;

#define FLASH_BLOCK_SELECT0               0x000UL
#define FLASH_BLOCK_SELECT1               0x001UL
#define FLASH_BLOCK_SELECT2               0x002UL
#define FLASH_BLOCK_SELECT3               0x003UL
#define FLASH_BLOCK_SELECT4               0x004UL
#define FLASH_BLOCK_SELECT5               0x005UL
#define FLASH_BLOCK_SELECT6               0x006UL
#define FLASH_BLOCK_SELECT7               0x007UL
#define FLASH_DATA_BLOCK_SELECT0          0x008UL
#define FLASH_DATA_BLOCK_SELECT1          0x009UL
#define FLASH_DATA_BLOCK_SELECT2          0x00AUL

#define    STATUS_SUCCESS                0x001UL
#define    STATUS_ERROR                  0x002UL
#define    STATUS_PARA_ERROR             0x003UL
#define    STATUS_ECC_ERROR              0x011UL
#define    STATUS_SBC_ERROR              0x021UL
#define    STATUS_DMA_DONE               0x041UL
#define    STATUS_EDC_ERROR              0x081UL
#define    STATUS_SPACE_ERROR            0x101UL
#define    STATUS_TWO_ERROR              0x201UL
#define    STATUS_ONE_ERROR              0x401UL
#define    STATUS_BLANK_ERROR            0x801UL
#define    STATUS_RWW_ERROR              0x1001UL
#define	   STATUS_PEP_ERROR              0x2001UL
#define	   STATUS_PES_ERROR              0x4001UL
#define	   STATUS_HVOP                   0x8001UL
#define	   STATUS_PEG_FAILED             0x10001UL
#define	   STATUS_WDG_ERROR              0x20001UL
#define    STATUS_NVR_TIMEOUT_ERROR      0x40001UL
#define    STATUS_RE_ERROR               0x80001UL
#define    STATUS_NVR_LOCK_ERROR         0x100001UL
#define    STATUS_ARRAY_BP               0x200001UL
#define    STATUS_ENC_ERROR              0x400001UL
#define    STATUS_NVR_CFG_LD_ERROR       0x800001UL
#define    STATUS_NVR_LD_ERROR           0x1000001UL
#define    STATUS_OTA_LD_ERROR           0x2000001UL
#define    STATUS_ANA_ERROR              0x4000001UL
#define    STATUS_STRICT_PEG_FAILED      0x8000001UL
#define    STATUS_LC_SCAN_ERROR          0x10000001UL
#define    STATUS_HSM_LD_ERROR           0x20000001UL
#define    STATUS_NVR_KEY_ERROR          0x40000001UL
#define    STATUS_DMA_RUN                0x80000001UL

#define    FLASH_ECC_CHECK_MASK                 0x011UL
#define    FLASH_SBC_CHECK_MASK                 0x021UL
#define    FLASH_DMA_DONE_CHECK_MASK            0x041UL
#define    FLASH_EDC_CHECK_MASK                 0x081UL
#define    FLASH_ECC_CHECK0_MASK                0x101UL
#define    FLASH_ECC_CHECK1_MASK                0x201UL
#define    FLASH_SBC_CHECK0_MASK                0x401UL
#define    FLASH_ECC_CHECK2_MASK                0x801UL
#define    FLASH_RWW_CHECK_MASK                 0x1001UL
#define    FLASH_PEP_CHECK_MASK                 0x2001UL
#define    FLASH_PES_CHECK_MASK                 0x4001UL
#define    FLASH_HVOP_CHECK_MASK                0x8001UL
#define    FLASH_PEG_CHECK_MASK                 0x10001UL
#define    FLASH_WDG_CHECK_MASK                 0x20001UL
#define    FLASH_NVR_TIMEOUT_CHECK_MASK         0x40001UL
#define    FLASH_RE_CHECK_MASK                  0x80001UL
#define    FLASH_NVR_LOCK_CHECK_MASK            0x100001UL
#define    FLASH_ARRAY_BP_CHECK_MASK            0x200001UL
#define    FLASH_ENC_CHECK_MASK                 0x400001UL
#define    FLASH_NVR_CFG_LD_CHECK_MASK          0x800001UL
#define    FLASH_NVR_LD_CHECK_MASK              0x1000001UL
#define    FLASH_OTA_LD_CHECK_MASK              0x2000001UL
#define    FLASH_ANA_CHECK_MASK               	0x4000001UL
#define    FLASH_STRICT_PEG_CHECK_MASK          0x8000001UL
#define    FLASH_LC_SCAN_CHECK_MASK             0x10000001UL
#define    FLASH_HSM_LD_CHECK_MASK              0x20000001UL
#define    FLASH_NVR_KEY_CHECK_MASK             0x40000001UL
#define    FLASH_DMA_RUN_CHECK_MASK             0x80000001UL

#define    FLASH_CLEAR_ECC_MASK                 0x011UL
#define    FLASH_CLEAR_SBC_MASK                 0x021UL
#define    FLASH_CLEAR_EDC_MASK                 0x081UL
#define    FLASH_CLEAR_ECC_ERR0_MASK            0x101UL
#define    FLASH_CLEAR_ECC_ERR1_MASK            0x201UL
#define    FLASH_CLEAR_SBC_ERR0_MASK            0x401UL
#define    FLASH_CLEAR_ECC_ERR2_MASK            0x801UL
#define    FLASH_CLEAR_RWW_MASK                 0x1001UL
#define    FLASH_CLEAR_PEP_MASK                 0x2001UL
#define    FLASH_CLEAR_PES_MASK                 0x4001UL
#define    FLASH_CLEAR_NVR_TIMEOUT_MASK         0x40001UL
#define    FLASH_CLEAR_ARRAY_BP_MASK            0x200001UL
#define    FLASH_CLEAR_ENC_MASK                 0x400001UL

#define FLASH_API_DISABLE           0x0UL
#define FLASH_API_ENABLE            0x1UL

#define FLASH_PRGM_SIZE1            0x2UL
#define FLASH_PRGM_SIZE2            0x4UL
#define FLASH_PRGM_SIZE3            0x6UL
#define FLASH_PRGM_SIZE4            0x8UL
#define FLASH_PRGM_SIZE5            0xAUL
#define FLASH_PRGM_SIZE6            0xCUL
#define FLASH_PRGM_SIZE7            0xEUL
#define FLASH_PRGM_SIZE8            0x10UL
#define FLASH_PRGM_SIZE9            0x12UL
#define FLASH_PRGM_SIZE10           0x14UL
#define FLASH_PRGM_SIZE11           0x16UL
#define FLASH_PRGM_SIZE12           0x18UL
#define FLASH_PRGM_SIZE13           0x1AUL
#define FLASH_PRGM_SIZE14           0x1CUL
#define FLASH_PRGM_SIZE15           0x1EUL
#define FLASH_PRGM_SIZE16           0x20UL

#define WDG_TUNE_DISABLE    0x1UL
#define WDG_TUNE_ENABLE     0x0UL
#define WDG_TUNE_DUMMY      0xFFFFFFFFUL

#define FLASH_REG_BIT_CFG_DISABLE  0x0UL
#define FLASH_REG_BIT_CFG_ENABLE   0x1UL
#define FLASH_REG_BIT_CFG_HOLD     0x2UL
#define FLASH_REG_BIT_DUMMY        0xFFFFFFFFUL

#define FLASH_WDG_TIMEOUT_SELECT0   0x0UL   /* Timeout set to 10x (400 clock default) */
#define FLASH_WDG_TIMEOUT_SELECT1   0x1UL   /* Timeout set to 5x */
#define FLASH_WDG_TIMEOUT_SELECT2   0x2UL   /* Timeout set to 100x */
#define FLASH_WDG_TIMEOUT_SELECT3   0x3UL   /* Timeout set to 1000x */
#define FLASH_WDG_TIMEOUT_HOLD      0x4UL   /* Timeout configure uncharge */

/**********************************************************************************************************************/
typedef struct
{
    uint32_t    blk_sel;
    uint32_t    int_en;
    uint32_t    (*func)(uint32_t val);
} FLASH_API_ERASEBLK_TYPE;

typedef struct
{
    uint32_t    blk_sel;
    uint32_t    dest;
    uint32_t    int_en;
    uint32_t    (*func)(uint32_t val);
} FLASH_API_ERASESECTOR_TYPE;

typedef struct
{
    uint32_t    addr;
    uint32_t    int_en;
    uint32_t    (*func)(uint32_t val);
} FLASH_API_ERASENVR_TYPE;

typedef struct
{
    uint32_t    dest;
    uint32_t    size;
    uint32_t    *pData;
    uint32_t    wdg_tune;
    uint32_t    pgff;
    uint32_t    int_en;
    uint32_t    (*func)(uint32_t val);
} FLASH_API_PRGM_CFG_TYPE;

typedef struct
{
    uint32_t dest;
    uint32_t sed0;
    uint32_t sed1;
    uint32_t sed2;
    uint32_t sed3;
    uint32_t sed4;
    uint32_t sed5;
    uint32_t wait_number;
    uint32_t mrv;
    uint32_t als;
    uint32_t bpe;
} FLASH_API_TEST_CHECK_CFG_TYPE;

typedef struct
{
    uint32_t data0;
    uint32_t data1;
    uint32_t data2;
    uint32_t data3;
    uint32_t data4;
    uint32_t data5;
} FLASH_API_TEST_CHECK_RESULT;

typedef struct
{
    uint32_t time;
    uint32_t wint_en;
    uint32_t wen;
} FLASH_API_WDG_CFG_TYPE;

typedef struct
{
    uint32_t data1;
    uint32_t data2;
    uint32_t data3;
    uint32_t dest;
} FLASH_API_ECC_CHECK_CFG_TYPE;

typedef struct
{
    uint32_t lock_sel;
    uint32_t  wait_number;
} FLASH_API_READ_WAIT_CFG_TYPE;

typedef struct
{
    uint32_t ecc_in_cfg;
    uint32_t edc_in_cfg;
    uint32_t ecc_single_bit_cfg;
    uint32_t ae_in_cfg;
    uint32_t ea_in_cfg_hi;
    uint32_t ea_in_cfg_lo;
    uint32_t aibpe_in_cfg;
    uint32_t test128_in_cfg;
    uint32_t edaie_in_cfg_hi;
    uint32_t edaie_in_cfg_lo;
} FLASH_API_TEST_CFG_TYPE;

typedef struct
{
    uint32_t safer;
    uint32_t pgff;
    uint32_t ifr_err_clr;
    uint32_t stop_ack_en;
    uint32_t fmc_cg;
    uint32_t bist_cg;
} FLASH_API_CTL_CFG_TYPE;

typedef struct
{
    uint32_t addr0;
    uint32_t addr1;
} FLASH_API_ADDR_ECC_CFG_TYPE;

typedef struct
{
    uint32_t ehv;
    uint32_t ers;
    uint32_t ess;
    uint32_t pgm;
    uint32_t wdie;
    //uint32_t aeeie;
    uint32_t blankie;
    uint32_t pecie;
    uint32_t encie;
    uint32_t edcie;
    uint32_t blankied;
    uint32_t blankerr;
    uint32_t blankerrd;
} FLASH_API_MCTL_CFG_TYPE;

typedef struct
{
    uint32_t aehv;
    uint32_t aers;
    uint32_t aess;
    uint32_t apgm;
    uint32_t awdie;
    uint32_t apecie;
} FLASH_API_AMCTL_CFG_TYPE;

typedef struct
{
    uint32_t dma_ie;
    uint32_t dma_allow;
    uint32_t dma_en;
} FLASH_API_DMA_CFG_TYPE;

typedef struct
{
    uint32_t dpd_block[11];
    uint32_t dpd;
    uint32_t dpd_stop_en;
    uint32_t dpd_phantom_en;
} FLASH_API_DPD_CFG_TYPE;

typedef struct
{
    uint32_t dest;
    uint32_t size;
    uint32_t *pData;
} FLASH_API_WRITE_DATA_CFG_TYPE;

typedef struct
{
    uint32_t u16FlashRomApiVersion;

    uint32_t RESERVED0[2U];
    status_t (*FLASH_DRV_EraseSector)(FLASH_API_ERASESECTOR_TYPE * flash_api_cfg);
    status_t (*FLASH_DRV_EraseSector_Clear)(void);
    status_t (*FLASH_DRV_EraseNvr)(FLASH_API_ERASENVR_TYPE * flash_api_cfg);
    status_t (*FLASH_DRV_EraseNvr_Clear)(void);
    status_t (*FLASH_DRV_Program)(FLASH_API_PRGM_CFG_TYPE * flash_api_cfg);
    status_t (*FLASH_DRV_Program_Clear)(void);
    status_t (*FLASH_DRV_Program_Nvr)(FLASH_API_PRGM_CFG_TYPE *flash_api_cfg);
    status_t (*FLASH_DRV_Program_Nvr_Clear)(void);
    status_t (*FLASH_DRV_Array_Integrity_Check)(FLASH_API_TEST_CHECK_CFG_TYPE * flash_api_cfg);
    status_t (*FLASH_DRV_Margin_Read_Check)(FLASH_API_TEST_CHECK_CFG_TYPE * flash_api_cfg);
    status_t (*FLASH_DRV_Read_Status_Check)(uint32_t flash_api_cfg);
    status_t (*FLASH_DRV_Read_Status_Check_Clear)(uint32_t flash_api_cfg);
    status_t (*FLASH_DRV_HV_Status_Check)(void);
    status_t (*FLASH_DRV_Test_Status_Check)(FLASH_API_TEST_CHECK_RESULT * flash_api_cfg);
    status_t (*FLASH_DRV_Wdog_Configure)(FLASH_API_WDG_CFG_TYPE * flash_api_cfg);
    status_t (*FLASH_DRV_Wdog_Status)(void);
    status_t (*FLASH_DRV_Wdog_Status_Clear)(void);
    status_t (*FLASH_DRV_EDC_Check)(FLASH_API_ECC_CHECK_CFG_TYPE * flash_api_cfg);
    status_t (*FLASH_DRV_ECC_Check)(FLASH_API_ECC_CHECK_CFG_TYPE * flash_api_cfg);
    status_t (*FLASH_DRV_Test_Mode_Close)(void);
    status_t (*FLASH_DRV_Read_Wait_CFG)(FLASH_API_READ_WAIT_CFG_TYPE * flash_api_cfg);
    status_t (*FLASH_DRV_ENABLE_HOLD_CFG)(uint32_t  flash_api_cfg);
    status_t (*FLASH_DRV_READ_ADDR_FUNC)(uint32_t *data0);
    status_t (*FLASH_DRV_Test_Cfg_FUNC)(FLASH_API_TEST_CFG_TYPE * flash_api_cfg);
    status_t (*FLASH_DRV_Array_Integrity_Suspend_FUNC)(uint32_t flash_api_cfg);
    status_t (*FLASH_DRV_Test_Mode_Open)(void);
    status_t (*FLASH_DRV_Sector_Program)(uint32_t *dest,uint32_t *addr,uint32_t *info);
    status_t (*FLASH_DRV_Read_Status_Check_128)(uint32_t flash_api_cfg);
    status_t (*FLASH_DRV_Read_Status_Check_Clear_128)(uint32_t flash_api_cfg);
    status_t (*FLASH_DRV_Array_Integrity_Check_128)(FLASH_API_TEST_CHECK_CFG_TYPE * flash_api_cfg);
    status_t (*FLASH_DRV_Margin_Read_Check_128)(FLASH_API_TEST_CHECK_CFG_TYPE * flash_api_cfg);
    status_t (*FLASH_DRV_CTL_CFG_FUNC)(FLASH_API_CTL_CFG_TYPE  * flash_api_cfg);
    status_t (*FLASH_DRV_READ_MASTER_ID_FUNC)(uint8_t *master_id);
    status_t (*FLASH_DRV_EDC_Check_128)(FLASH_API_ECC_CHECK_CFG_TYPE * flash_api_cfg);
    status_t (*FLASH_DRV_ECC_Check_128)(FLASH_API_ECC_CHECK_CFG_TYPE * flash_api_cfg);
    status_t (*FLASH_DRV_EAC_CHECK_128_HI)(FLASH_API_ADDR_ECC_CFG_TYPE * flash_api_cfg);
    status_t (*FLASH_DRV_AEC_CHECK)(FLASH_API_ADDR_ECC_CFG_TYPE * flash_api_cfg);
    status_t (*FLASH_DRV_MCTL_CFG_FUNC)(FLASH_API_MCTL_CFG_TYPE * flash_api_cfg);
    status_t (*FLASH_DRV_AMCTL_CFG_FUNC)(FLASH_API_AMCTL_CFG_TYPE * flash_api_cfg);
    status_t (*FLASH_DRV_READ_PE_MASTER_ID_FUNC)(uint8_t *master_id);
    status_t (*FLASH_DRV_READ_PE_AMASTER_ID_FUNC)(uint8_t *master_id);
    status_t (*FLASH_DRV_EAC_CHECK_128_LO)(FLASH_API_ADDR_ECC_CFG_TYPE * flash_api_cfg);
    status_t (*FLASH_DRV_EDCA_CHECK_128_HI)(FLASH_API_ADDR_ECC_CFG_TYPE * flash_api_cfg);
    status_t (*FLASH_DRV_EDCA_CHECK_128_LO)(FLASH_API_ADDR_ECC_CFG_TYPE * flash_api_cfg);
    status_t (*FLASH_DRV_ABORT_PE)(void);
    status_t (*FLASH_DRV_WRITE_ADR_FUNC)(uint32_t data0, uint8_t pflash_prll, uint8_t nvr_prll);
    status_t (*FLASH_DRV_Read_Status_Check_P1)(uint32_t  flash_api_cfg);
    status_t (*FLASH_DRV_Read_Status_Check_P1_128)(uint32_t  flash_api_cfg);
    status_t (*FLASH_DRV_Read_Status_Check_P2)(uint32_t  flash_api_cfg);
    status_t (*FLASH_DRV_Read_Status_Check_Clear_P1)(uint32_t  flash_api_cfg);
    status_t (*FLASH_DRV_Read_Status_Check_Clear_P1_128)(uint32_t  flash_api_cfg);
    status_t (*FLASH_DRV_Read_Status_Check_Clear_P2)(uint32_t  flash_api_cfg);
    status_t (*FLASH_DRV_READ_ADR_P1_FUNC)(uint32_t *data0);
    status_t (*FLASH_DRV_READ_ADR_P2_FUNC)(uint32_t *data0);
    status_t (*FLASH_DRV_WRITE_ADR_P1_FUNC)(uint32_t data0,uint8_t pflash_prll,uint8_t nvr_prll);
    status_t (*FLASH_DRV_WRITE_ADR_P2_FUNC)(uint32_t data0,uint8_t pflash_prll,uint8_t nvr_prll);
    status_t (*FLASH_DRV_READ_MASTER_ID_P1_FUNC)(uint8_t * master_id);
    status_t (*FLASH_DRV_READ_MASTER_ID_P2_FUNC)(uint8_t * master_id);
    status_t (*FLASH_DRV_DMA_CFG_FUNC)(FLASH_API_DMA_CFG_TYPE * flash_api_cfg);
    status_t (*FLASH_DRV_DMA_TRIG_FUNC)(uint32_t dma_addr_cnt);
    status_t (*FLASH_DRV_DMA_ADDR_CNT_READ_FUNC)(uint32_t * dma_addr_cnt);
    status_t (*FLASH_DRV_DPD_CFG_FUNC)(FLASH_API_DPD_CFG_TYPE * flash_api_cfg);
    status_t (*FFLASH_DRV_WRITE_DATA_BUF_FUNC)(FLASH_API_WRITE_DATA_CFG_TYPE * flash_api_cfg);
}FLASH_ROM_API_ENTRY_T;

#endif /* _DEVICE_FEATURES_FC7300F8MDQxxxxxT1B_FLASH_COMMON_H_ */
