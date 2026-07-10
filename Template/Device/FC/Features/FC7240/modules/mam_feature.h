#ifndef _DEVICE_FEATURES_FC7240_MAM_COMMON_H_
#define _DEVICE_FEATURES_FC7240_MAM_COMMON_H_

/************ MAM Features **************/
/** Number of instances of the MAM module. */
#define MAM_INSTANCE_COUNT   (1u)

#define MAM_BASE_PTRS        { MAM0 }

#define MAM_ACR_OFFSET          {47}
#define MAM_BLOCK_REGION_MAX    11
#define MAM_BLOCK_REGION    \
 /* start addr */  /* end addr */  /* block size */  /* base block index */  /* MAM index */                       \
{0x04800000UL,     0x0481FFFFUL,   17UL,/* 128K */   0UL,                    0UL},            /* ROM */            \
{0x01000000UL,     0x011FFFFFUL,   17UL,/* 128K */   1UL,                    0UL},            /* FLASH0(PFLASH) */ \
{0x04400000UL,     0x04411FFFUL,   17UL,/* 128K */   17UL,                   0UL},            /* NVR0/1/2 */       \
{0x04420000UL,     0x04431FFFUL,   17UL,/* 128K */   18UL,                   0UL},            /* NVR_CFG */        \
{0x04000000UL,     0x0401FFFFUL,   13UL,/* 8K */     19UL,                   0UL},            /* FLASH1(DFLASH) */ \
{0x21000000UL,     0x2100FFFFUL,   14UL,/* 16K */    35UL,                   0UL},            /* SRAM0 */          \
{0x21010000UL,     0x21017FFFUL,   14UL,/* 16K */    39UL,                   0UL},            /* SRAM1 */          \
{0x00000000UL,     0x00007FFFUL,   14UL,/* 16K */    41UL,                   0UL},            /* CPU0_ITCM */      \
{0x20000000UL,     0x2001FFFFUL,   14UL,/* 16K */    43UL,                   0UL},            /* CPU0_DTCM */      \
{0x40000000UL,     0x4009FFFFUL,   12UL,/* 4K */     51UL,                   0UL},            /* AFCB0 */          \
{0x40400000UL,     0x4049FFFFUL,   12UL,/* 4K */     211UL,                  0UL},            /* AFCB1 */          \

/**
 * @brief The master index of the mam peripheral
 *
 */
typedef enum
{
    MAM_MASTER_CPU0_AXIM = 0,
    MAM_MASTER_CPU0_AHBP,
    MAM_MASTER_DMA0,
    MAM_MASTER_HSM,
} MAM_Master_Type;

/**
 * @brief The mam index
 *
 */
typedef enum
{
    MAM_INSTANCE_0 = 0,
} MAM_Index_Type;

#define MAM_WDOG_DIV_SUPPORT

#endif /* _DEVICE_FEATURES_FC7240_MAM_COMMON_H_ */
