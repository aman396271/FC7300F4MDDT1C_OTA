#ifndef _DEVICE_FEATURES_FC7300F4MDSxxxxxT1B_FLASH_COMMON_H_
#define _DEVICE_FEATURES_FC7300F4MDSxxxxxT1B_FLASH_COMMON_H_

#define FLASHDRV_ADDR   					 	             0x04810200U /* flash api address in rom */

#define FLASH									                   ((FLASH_ROM_API_ENTRY_T*)FLASHDRV_ADDR)
#define FLASHDRV_BASE_ADDR						           {FLASH}
#define FLASH_INSTANCE_COUNT                     0x1U

#define FLASH_API_SIZE       					           FLASH_API_SIZE_4M

// #define FLASH_API_FC7300_SUPPORT                 STD_ON
#define FLASH_FC7300F4MDS_T1B                       STD_ON


/** Program maximum */
#define FLASH_PROGRAM_PAGE_MAX_SIZE               0x80U    /* 128 bytes  */
/* ------------------------- PFlash ------------------------ */
/** PFlash start address */
#define PFLASH_ADDR_START                         0x01000000U
/** Program minimum size */
#define PFLASH_PROGRAM_PAGE_MIN_SIZE              0x10U    /* 16 bytes   */
/** Erase size */
#define PFLASH_ERASE_SECTOR_SIZE                  0x2000U   /* 8 KBytes   */
/** Flash end address */
#define PFLASH_ADDR_END                           0x013FFFFFU
/** Erase value of flash memory       */
#define PFLASH_ERASED_VALUE                       0xFFU
/** 4 PFlash Banks, every bank is 2MB */
#define PFLASH_BANK_NUM                           0x02U
/** Flash bank size */
#define PFLASH_BANK_SIZE                          0x200000U
/** Flash phantom offset */
#define PFLASH_PHANTOM_OFFSET                     (PFLASH_BANK_SIZE - FLASH_256KB_SIZE)
/** PFlash total size */
#define PFLASH_SIZE                               0x400000U
#define DFLASH_INDEX                              0x04U
/* ------------------------- DFlash ------------------------ */
/** DFlash total size */
#define DFLASH_SIZE                               0x00040000U  /* 256KB */
/** DFlash start address */
#define DFLASH_ADDR_START                         0x04000000U
/** DFlash end address */
#define DFLASH_ADDR_END                           0x0403FFFFU
/** Program minimum size */
#define DFLASH_PROGRAM_PAGE_MIN_SIZE              0x10U    /* 16 bytes   */
/** Erase size */
#define DFLASH_ERASE_SECTOR_SIZE                  0x2000U  /* 8 KBytes   */
/** Erase value of flash memory       */
#define DFLASH_ERASED_VALUE                       0xFFU
/** 1 DFlash Banks, every bank is 2MB */
#define DFLASH_BANK_NUM                           0x01U
/** DFlash Bank 0 size */
#define DFLASH_BANK_SIZE                         0x00040000U
#define FLASH_256KB_SIZE                          0x00040000U
/* ------------------------- NVR ------------------------ */
/** NVR start address */
#define NVR_FLASH_ADDR_START                      0x04400000U
/** NVR0 end address */
#define NVR_FLASH_ADDR_END                        0x04401FFFU
/** Program minimum size */
#define NVR_PROGRAM_PAGE_MIN_SIZE                 0x10U
/** NVR erase sector size */
#define NVR_ERASE_SECTOR_SIZE                     0x2000U /* 8192 bytes */
/** NVR program maximum */
#define NVRFLASH_PROGRAM_PAGE_MAX_SIZE            0x80U  /* 128 bytes */
// /** NVR num */
// #define NVR_NUM                                   1U
// /** NVR Sector num */
// #define NVR_SECTOR_NUM                            1U
#define FLASH_PORT0_ADDR_START                    0x01000000U
#define FLASH_PORT0_ADDR_END                      0x013FFFFFU
// #define FLASH_PORT1_ADDR_START                    0x01400000U
// #define FLASH_PORT1_ADDR_END                      0x017FFFFFU
#define FLASH_PORT2_ADDR_START                    DFLASH_ADDR_START
#define FLASH_PORT2_ADDR_END                      DFLASH_ADDR_END



#define    FLASH_ECC_CHECK_MASK                 0x011UL
#define    FLASH_SBC_CHECK_MASK                 0x021UL
#define    FLASH_AEE_CHECK_MASK                 0x041UL
#define    FLASH_EDC_CHECK_MASK                 0x081UL
#define    FLASH_ECC_CHECK0_MASK                0x101UL
#define    FLASH_ECC_CHECK1_MASK                0x201UL
#define    FLASH_BLANKH_CHECK_MASK              0x401UL
#define    FLASH_BLANKL_CHECK_MASK              0x801UL
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
#define    FLASH_CLEAR_BLANKH_MASK              0x401UL
#define    FLASH_CLEAR_BLANKL_MASK              0x801UL
#define    FLASH_CLEAR_RWW_MASK                 0x1001UL
#define    FLASH_CLEAR_PEP_MASK                 0x2001UL
#define    FLASH_CLEAR_PES_MASK                 0x4001UL
#define    FLASH_CLEAR_NVR_TIMEOUT_MASK         0x40001UL
#define    FLASH_CLEAR_ARRAY_BP_MASK            0x200001UL

#define    FLASH_API_DISABLE           0x0UL
#define    FLASH_API_ENABLE            0x1UL

#define    FLASH_API_SIZE_8M           0x0UL
#define    FLASH_API_SIZE_4M           0x1UL

#define    FLASH_AUTO_HOLD_DISABLE  0x0UL
#define    FLASH_AUTO_HOLD_ENABLE   0x1UL

#define    STATUS_SUCCESS               0x001UL
#define    STATUS_ERROR                 0x002UL
#define    STATUS_PARA_ERROR            0x003UL
#define    STATUS_ECC_ERROR             0x011UL
#define    STATUS_SBC_ERROR             0x021UL
#define    STATUS_AEE_ERROR             0x041UL
#define    STATUS_EDC_ERROR             0x081UL
#define    STATUS_SPACE_ERROR           0x101UL
#define    STATUS_TWO_ERROR             0x201UL
#define    STATUS_BLANKH_ERROR          0x401UL
#define    STATUS_BLANKL_ERROR          0x801UL
#define    STATUS_RWW_ERROR             0x1001UL
#define    STATUS_PEP_ERROR             0x2001UL
#define    STATUS_PES_ERROR             0x4001UL
#define    STATUS_HVOP                  0x8001UL
#define    STATUS_PEG_FAILED            0x10001UL
#define    STATUS_WDG_ERROR             0x20001UL
#define    STATUS_NVR_TIMEOUT_ERROR     0x40001UL
#define    STATUS_RE_ERROR              0x80001UL
#define    STATUS_NVR_LOCK_ERROR        0x100001UL
#define    STATUS_ARRAY_BP              0x200001UL


typedef uint32_t status_t;

#define     WDG_TUNE_DISABLE    0x1UL
#define     WDG_TUNE_ENABLE     0x0UL

#define     FLASH_BLOCK_SELECT0               0x000UL
#define     FLASH_BLOCK_SELECT1               0x001UL
#define     FLASH_BLOCK_SELECT2               0x002UL
#define     FLASH_BLOCK_SELECT3               0x003UL
#define     FLASH_DATA_BLOCK_SELECT0          0x004UL

typedef struct {
  uint32_t blk_sel;
  uint32_t dest;
} FLASH_API_ERASESECTOR_TYPE;

#define     FLASH_REG_BIT_CFG_DISABLE       0x0UL
#define     FLASH_REG_BIT_CFG_ENABLE        0x1UL
#define     FLASH_REG_BIT_CFG_HOLD          0x2UL

typedef struct {
  uint32_t dest;
  uint32_t size;
  uint32_t *pData;
  uint32_t  wdg_tune;
  uint32_t  pgff;
} FLASH_API_PRGM_CFG_TYPE;

typedef enum
{
    FLASH_MARGIN_LEVEL0              = 0x0UL,
    FLASH_MARGIN_LEVEL1              = 0x1UL
}FLASH_API_MARGIN_LEVEL_TYPE;

typedef struct {
  uint32_t dest;
  uint32_t sed0;
  uint32_t sed1;
  uint32_t sed2;
  uint32_t sed3;
  uint32_t sed4;
  uint32_t sed5;
  uint32_t sed6;
  uint32_t sed7;
  uint32_t sed8;
  uint32_t sed9;
  uint32_t  wait_number;
  FLASH_API_MARGIN_LEVEL_TYPE  mrv;
  uint32_t als;
  uint32_t bpe;
} FLASH_API_TEST_CHECK_CFG_TYPE;

typedef uint32_t FLASH_API_READ_STATUS_CHECK_TYPE;

typedef uint32_t FLASH_API_READ_STATUS_CLEAR_TYPE;

typedef struct {
  uint32_t data0;
  uint32_t data1;
  uint32_t data2;
  uint32_t data3;
  uint32_t data4;
  uint32_t data5;
  uint32_t data6;
  uint32_t data7;
  uint32_t data8;
  uint32_t data9;
} FLASH_API_TEST_CHECK_RESULT;

#define FLASH_WDG_TIMEOUT_SELECT0   0x0UL   /* Timeout set to 10x (400 clock default) */
#define FLASH_WDG_TIMEOUT_SELECT1   0x1UL   /* Timeout set to 5x */
#define FLASH_WDG_TIMEOUT_SELECT2   0x2UL   /* Timeout set to 100x */
#define FLASH_WDG_TIMEOUT_SELECT3   0x3UL   /* Timeout set to 1000x */
#define FLASH_WDG_TIMEOUT_HOLD      0x4UL   /* Timeout configure uncharge */

typedef struct {
  uint32_t time;
  uint32_t wint_en;
  uint32_t wen;
} FLASH_API_WDG_CFG_TYPE;

typedef struct {
  uint32_t data1;
  uint32_t data2;
  uint32_t data3;
  uint32_t data4;
  uint32_t data5;
  uint32_t  size;  //0 8M 1 4M
  uint32_t dest;
} FLASH_API_ECC_CHECK_CFG_TYPE;

typedef struct {
  uint32_t lock_sel;
  uint32_t  wait_number;
} FLASH_API_READ_WAIT_CFG_TYPE;

typedef struct{
    uint32_t ecc_in_cfg;
    uint32_t edc_in_cfg;
    uint32_t ecc_single_bit_cfg;
    uint32_t ae_in_cfg;
    uint32_t ea_in_cfg;
    uint32_t aibpe_in_cfg;
}FLASH_API_TEST_CFG_TYPE;

typedef struct{
    uint32_t safer;
    uint32_t pgff;
    uint32_t ifr_err_clr;
    uint32_t stop_ack_en;
    uint32_t fmc_cg;
    uint32_t bist_cg;
}FLASH_API_CTL_CFG_TYPE;

typedef struct{
    uint32_t ehv;
    uint32_t ers;
    uint32_t ess;
    uint32_t pgm;
    uint32_t wdie;
    uint32_t aeeie;
    uint32_t blankie;
    uint32_t pecie;
}FLASH_API_MCTL_CFG_TYPE;

typedef struct{
    uint32_t aehv;
    uint32_t aers;
    uint32_t aess;
    uint32_t apgm;
    uint32_t awdie;
    uint32_t apecie;
}FLASH_API_AMCTL_CFG_TYPE;

typedef struct
{
    uint16_t u16FlashRomApiMajorVersion;
    uint16_t u16FlashRomApiMinorVersion;

    uint32_t RESERVED0[2U];
    status_t (*FLASH_DRV_EraseSector)(FLASH_API_ERASESECTOR_TYPE * flash_api_cfg,uint32_t int_en,uint32_t type);
    status_t (*FLASH_DRV_EraseSector_Clear)(void);
    status_t (*FLASH_DRV_EraseNvr)(uint32_t int_en);
    status_t (*FLASH_DRV_EraseNvr_Clear)(void);
    status_t (*FLASH_DRV_Program)(FLASH_API_PRGM_CFG_TYPE * flash_api_cfg,uint32_t int_en,uint32_t type);
    status_t (*FLASH_DRV_Program_Clear)(void);
    status_t (*FLASH_DRV_Program_Nvr)(FLASH_API_PRGM_CFG_TYPE *flash_api_cfg,uint32_t int_en);
    status_t (*FLASH_DRV_Program_Nvr_Clear)(void);
    status_t (*FLASH_DRV_Array_Integrity_Check)(FLASH_API_TEST_CHECK_CFG_TYPE * flash_api_cfg);
    status_t (*FLASH_DRV_Margin_Read_Check)(FLASH_API_TEST_CHECK_CFG_TYPE * flash_api_cfg);
    status_t (*FLASH_DRV_Read_Status_Check)(FLASH_API_READ_STATUS_CHECK_TYPE flash_api_cfg);
    status_t (*FLASH_DRV_Read_Status_Check_Clear)(FLASH_API_READ_STATUS_CLEAR_TYPE flash_api_cfg);
    status_t (*FLASH_DRV_HV_Status_Check)(void);
    status_t (*FLASH_DRV_Test_Status_Check)(FLASH_API_TEST_CHECK_RESULT * flash_api_cfg);
    status_t (*FLASH_DRV_Wdog_Configure)(FLASH_API_WDG_CFG_TYPE * flash_api_cfg);
    status_t (*FLASH_DRV_Wdog_Status)(void);
    status_t (*FLASH_DRV_Wdog_Status_Clear)(void);
    status_t (*FLASH_DRV_EDC_Check)(FLASH_API_ECC_CHECK_CFG_TYPE * flash_api_cfg,uint32_t size);
    status_t (*FLASH_DRV_ECC_Check)(FLASH_API_ECC_CHECK_CFG_TYPE * flash_api_cfg,uint32_t size);
    status_t (*FLASH_DRV_Test_Mode_Close)(void);
    status_t (*FLASH_DRV_Read_Wait_CFG)(FLASH_API_READ_WAIT_CFG_TYPE * flash_api_cfg);
    status_t (*FLASH_DRV_ENABLE_HOLD_CFG)(uint32_t  flash_api_cfg);
    status_t (*FLASH_DRV_READ_ADDR_FUNC)(uint32_t *data0);
    status_t (*FLASH_DRV_Test_Cfg_FUNC)(FLASH_API_TEST_CFG_TYPE * flash_api_cfg);
    status_t (*FLASH_DRV_Array_Integrity_Suspend_FUNC)(uint32_t flash_api_cfg);
    status_t (*FLASH_DRV_Test_Mode_Open)(void);
    status_t (*FLASH_DRV_Sector_Program)(uint32_t *dest,uint32_t *addr,uint32_t *info,uint32_t type);
    status_t (*FLASH_DRV_Read_Status_Check_P1)(FLASH_API_READ_STATUS_CHECK_TYPE flash_api_cfg);
    status_t (*FLASH_DRV_Read_Status_Check_P2)(FLASH_API_READ_STATUS_CHECK_TYPE flash_api_cfg);
    status_t (*FLASH_DRV_Read_Status_Check_Clear_P1)(FLASH_API_READ_STATUS_CLEAR_TYPE flash_api_cfg);
    status_t (*FLASH_DRV_Read_Status_Check_Clear_P2)(FLASH_API_READ_STATUS_CLEAR_TYPE flash_api_cfg);
    status_t (*FLASH_DRV_READ_ADDR_FUNC_P1)(uint32_t *data0);
    status_t (*FLASH_DRV_READ_ADDR_FUNC_P2)(uint32_t *data0);
    status_t (*FLASH_DRV_CTL_CFG_FUNC)(FLASH_API_CTL_CFG_TYPE * flash_api_cfg);
    status_t (*FLASH_DRV_READ_MASTER_ID_FUNC)(uint8_t *master_id);
    status_t (*FLASH_DRV_READ_MASTER_ID_FUNC_P1)(uint8_t *master_id);
    status_t (*FLASH_DRV_READ_MASTER_ID_FUNC_P2)(uint8_t *master_id);
    status_t (*FLASH_DRV_EAC_CHECK)(uint32_t addr);
    status_t (*FLASH_DRV_AEC_CHECK)(uint32_t addr);
    status_t (*FLASH_DRV_MCTL_CFG_FUNC)(FLASH_API_MCTL_CFG_TYPE * flash_api_cfg);
    status_t (*FLASH_DRV_AMCTL_CFG_FUNC)(FLASH_API_AMCTL_CFG_TYPE * flash_api_cfg);
    status_t (*FLASH_DRV_READ_PE_MASTER_ID_FUNC)(uint8_t *master_id);
    status_t (*FLASH_DRV_READ_PE_AMASTER_ID_FUNC)(uint8_t *master_id);
}FLASH_ROM_API_ENTRY_T;

#endif /* _DEVICE_FEATURES_FC7300F4MDSxxxxxT1B_FLASH_COMMON_H_ */
