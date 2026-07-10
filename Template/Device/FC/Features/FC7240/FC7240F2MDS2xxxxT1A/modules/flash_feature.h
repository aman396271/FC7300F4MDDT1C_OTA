#ifndef _DEVICE_FEATURES_FC7240F2MDS2_FLASH_COMMON_H_
#define _DEVICE_FEATURES_FC7240F2MDS2_FLASH_COMMON_H_

#define SRAM_ADDR_START            0x21000000U
#define SRAM_ADDR_END              0x21017FFFU

#define FLASHDRV_ADDR                             0x04810200U /* flash api address in rom */

#define CHECK_PARALLEL_ENABLE                     (((*(uint32_t*)0x044000E8) & 0x0000000F) != 0x00000005)  /* 1 is 128bit mode, 0 is 64bit mode */

#define FLASH                                     ((FLASH_ROM_API_ENTRY_T*)FLASHDRV_ADDR)
#define FLASHDRV_BASE_ADDR                        {FLASH}
#define FLASH_INSTANCE_COUNT                      0x1U
#define FLASH_API_SIZE                            FLASH_API_SIZE_2M
//#define FLASH_API_FC7240_SUPPORT                  STD_ON
#define FLASH_FC7240F2MDS                         STD_ON

/** Program maximum */
#define FLASH_PROGRAM_PAGE_MAX_SIZE               0x80U    /* 128 bytes  */
/* ------------------------- PFlash ------------------------ */
/** PFlash start address */
#define PFLASH_ADDR_START                         0x01000000U
#define PFLASH_ADDR_END                           0x011FFFFFU
#define PFLASH_SIZE                               0x00200000U  /* 256KB */
#define PFLASH_BANK_SIZE                          0x00100000U
#define PFLASH_LAST256K_OFFSET                    0xC0000UL
/** Program minimum size */
#define PFLASH_PROGRAM_PAGE_MIN_SIZE              0x08U    /* 8 bytes   */
/** Erase size */
#define PFLASH_ERASE_SECTOR_SIZE                  (CHECK_PARALLEL_ENABLE ? 0x1000U : 0x800U)   /* 2 KBytes or 4 KBytes  */
/** Erase value of flash memory       */
#define PFLASH_ERASED_VALUE                       0xFFU
/** 4 PFlash Banks, every bank is 2MB */
#define PFLASH_BANK_NUM                           0x02U
/** Flash phantom offset */
#define PFLASH_PHANTOM_OFFSET                     (PFLASH_BANK_SIZE - FLASH_256KB_SIZE)
#define DFLASH_INDEX                              0x02U
/* ------------------------- DFlash ------------------------ */
/** DFlash total size */
#define DFLASH_SIZE                               0x00040000U  /* 256KB */
/** DFlash start address */
#define DFLASH_ADDR_START                         0x04000000U
/** DFlash end address */
#define DFLASH_ADDR_END                           0x0401FFFFU
/** Program minimum size */
#define DFLASH_PROGRAM_PAGE_MIN_SIZE              0x08U    /* 8 bytes   */
/** Erase size */
#define DFLASH_ERASE_SECTOR_SIZE                  0x800U  /* 2 KBytes   */
/** Erase value of flash memory       */
#define DFLASH_ERASED_VALUE                       0xFFU
/** 1 DFlash Banks, every bank is 2MB */
#define DFLASH_BANK_NUM                           0x01U
/** DFlash Bank size */
#define DFLASH_BANK_SIZE                          0x00040000U
#define FLASH_256KB_SIZE                          0x00040000U
/* ------------------------- NVR ------------------------ */
/** NVR0 start address */
#define NVR0_FLASH_ADDR_START                      0x04400000U
/** NVR0 end address */
#define NVR0_FLASH_ADDR_END                        0x04403FFFU
/** NVR1 start address */
#define NVR1_FLASH_ADDR_START                      0x04408000U
/** NVR1 end address */
#define NVR1_FLASH_ADDR_END                        0x0440BFFFU
/** NVR2 start address */
#define NVR2_FLASH_ADDR_START                      0x04410000U
/** NVR2 end address */
#define NVR2_FLASH_ADDR_END                        0x04411FFFU
/** Program minimum size */
#define NVR_PROGRAM_PAGE_MIN_SIZE                  0x08U
/** NVR erase sector size */
#define NVR_ERASE_SECTOR_SIZE                      0x800U /* 2048 bytes */
/** NVR program maximum */
#define NVRFLASH_PROGRAM_PAGE_MAX_SIZE             0x80U  /* 128 bytes */
// /** NVR num */
// #define NVR_NUM                                    3U
/** NVR Sector num */
// #define NVR_SECTOR_NUM                             20U



#define    FLASH_API_SIZE_2M           0x0UL

#define    STATUS_SUCCESS                0x001UL
#define    STATUS_ERROR                  0x002UL
#define    STATUS_PARA_ERROR             0x003UL
#define    STATUS_ECC_ERROR              0x011UL
#define    STATUS_SBC_ERROR              0x021UL
#define    STATUS_AEE_ERROR              0x041UL
#define    STATUS_EDC_ERROR              0x081UL
#define    STATUS_SPACE_ERROR            0x101UL
#define    STATUS_TWO_ERROR              0x201UL
#define    STATUS_ONE_ERROR              0x401UL
#define    STATUS_BLANK_ERROR            0x801UL
#define    STATUS_RWW_ERROR              0x1001UL
#define    STATUS_PEP_ERROR              0x2001UL
#define    STATUS_PES_ERROR              0x4001UL
#define    STATUS_HVOP                   0x8001UL
#define    STATUS_PEG_FAILED             0x10001UL
#define    STATUS_WDG_ERROR              0x20001UL
#define    STATUS_NVR_TIMEOUT_ERROR      0x40001UL
#define    STATUS_RE_ERROR               0x80001UL
#define    STATUS_NVR_LOCK_ERROR         0x100001UL
#define    STATUS_ARRAY_BP               0x200001UL

typedef uint32_t status_t;

#define    FLASH_ECC_CHECK_MASK                 0x011UL
#define    FLASH_SBC_CHECK_MASK                 0x021UL
#define    FLASH_AEE_CHECK_MASK                 0x041UL
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

#define    FLASH_CLEAR_ECC_MASK                 0x011UL
#define    FLASH_CLEAR_SBC_MASK                 0x021UL
#define    FLASH_CLEAR_AEE_MASK                 0x041UL
#define    FLASH_CLEAR_EDC_MASK                 0x081UL
#define    FLASH_CLEAR_ECC_ERR0_MASK            0x101UL
#define    FLASH_CLEAR_ECC_ERR1_MASK            0x201UL
#define    FLASH_CLEAR_SBC_ERR0_MASK            0x401UL
#define    FLASH_CLEAR_ECC_ERR2_MASK            0x801UL

#define    FLASH_API_DISABLE                       0x0UL
#define    FLASH_API_ENABLE                        0x1UL

#define    WDG_TUNE_DISABLE                        0x1UL
#define    WDG_TUNE_ENABLE                         0x0UL

#define    FLASH_AUTO_HOLD_DISABLE                 0x0UL
#define    FLASH_AUTO_HOLD_ENABLE                  0x1UL

#define    FLASH_REG_BIT_CFG_DISABLE               0x0UL
#define    FLASH_REG_BIT_CFG_ENABLE                0x1UL
#define    FLASH_REG_BIT_CFG_HOLD                  0x2UL

#define    FLASH_BLOCK_SELECT0                     0x000UL
#define    FLASH_BLOCK_SELECT1                     0x001UL
#define    FLASH_DATA_BLOCK_SELECT0                0x002UL

#define FLASH_WDG_TIMEOUT_SELECT0   0x0UL   /* Timeout set to 10x (400 clock default) */
#define FLASH_WDG_TIMEOUT_SELECT1   0x1UL   /* Timeout set to 5x */
#define FLASH_WDG_TIMEOUT_SELECT2   0x2UL   /* Timeout set to 100x */
#define FLASH_WDG_TIMEOUT_SELECT3   0x3UL   /* Timeout set to 1000x */
#define FLASH_WDG_TIMEOUT_HOLD      0x4UL   /* Timeout configure uncharge */

typedef struct
{
    uint32_t blk_sel;
    uint32_t dest;
} FLASH_API_ERASESECTOR_TYPE;

typedef struct
{
    uint32_t dest;
    uint32_t size;
    uint32_t *pData;
    uint32_t  wdg_tune;
    uint32_t  pgff;
} FLASH_API_PRGM_CFG_TYPE;

typedef struct {
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
    uint16_t u16FlashRomApiMajorVersion;
    uint16_t u16FlashRomApiMinorVersion;

    uint32_t RESERVED0[2U];
    status_t (*FLASH_DRV_EraseSector)(FLASH_API_ERASESECTOR_TYPE *flash_api_cfg, uint32_t int_en, uint32_t type);
    status_t (*FLASH_DRV_EraseSector_Clear)(void);
    status_t (*FLASH_DRV_EraseNvr)(uint32_t addr, uint32_t int_en);
    status_t (*FLASH_DRV_EraseNvr_Clear)(void);
    status_t (*FLASH_DRV_Program)(FLASH_API_PRGM_CFG_TYPE *flash_api_cfg, uint32_t int_en, uint32_t type);
    status_t (*FLASH_DRV_Program_Clear)(void);
    status_t (*FLASH_DRV_Program_Nvr)(FLASH_API_PRGM_CFG_TYPE *flash_api_cfg, uint32_t int_en);
    status_t (*FLASH_DRV_Program_Nvr_Clear)(void);
    uint32_t RESERVED3[2U];
    status_t (*FLASH_DRV_Read_Status_Check)(uint32_t flash_api_cfg);
    status_t (*FLASH_DRV_Read_Status_Check_Clear)(uint32_t flash_api_cfg);
    status_t (*FLASH_DRV_HV_Status_Check)(void);
    uint32_t RESERVED4[1U];
    status_t (*FLASH_DRV_Wdog_Configure)(FLASH_API_WDG_CFG_TYPE * flash_api_cfg);
    status_t (*FLASH_DRV_Wdog_Status)(void);
    status_t (*FLASH_DRV_Wdog_Status_Clear)(void);
    uint32_t RESERVED5[1U];
    status_t (*FLASH_DRV_ECC_Check)(FLASH_API_ECC_CHECK_CFG_TYPE *flash_api_cfg);
    status_t (*FLASH_DRV_Test_Mode_Close)(void);
    uint32_t RESERVED6[1U];
    status_t (*FLASH_DRV_ENABLE_HOLD_CFG)(uint32_t  flash_api_cfg);
    uint32_t RESERVED7[3U];
    status_t (*FLASH_DRV_Test_Mode_Open)(void);
    uint32_t RESERVED8[1U];
    uint32_t (*FLASH_DRV_Read_Status_Check_128)(uint32_t flash_api_cfg);
    status_t (*FLASH_DRV_Read_Status_Check_Clear_128)(uint32_t flash_api_cfg);
    uint32_t RESERVED9[5u];
    status_t (*FLASH_DRV_ECC_Check_128)(FLASH_API_ECC_CHECK_CFG_TYPE * flash_api_cfg);
} FLASH_ROM_API_ENTRY_T;

#endif /* _DEVICE_FEATURES_FC7240F2MDS2_FLASH_COMMON_H_ */
