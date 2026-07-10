#ifndef _DEVICE_FEATURES_FC7300F4MDDxxxxxT1B_MAM_COMMON_H_
#define _DEVICE_FEATURES_FC7300F4MDDxxxxxT1B_MAM_COMMON_H_
/** Number of instances of the MAM module. */
#define MAM_INSTANCE_COUNT (3u)
/** Array initializer of MAM peripheral base addresses */
#define MAM_BASE_ADDRS     { MAM0_BASE, MAM1_BASE, MAM2_BASE }
/** Array initializer of MAM peripheral base pointers */
#define MAM_BASE_PTRS      { MAM0, MAM1, MAM2 }

#define MAM_ACR_OFFSET          {13, 9, 40}
#define MAM_BLOCK_REGION_MAX    13
#define MAM_BLOCK_REGION    \
 /* start addr */  /* end addr */  /* block size */  /* base block index */  /* MAM index */                       \
{0x04800000UL,     0x0481FFFFUL,   17UL,/* 128K */   0UL,                    0UL},            /* ROM */            \
{0x01000000UL,     0x013FFFFFUL,   17UL,/* 128K */   1UL,                    0UL},            /* FLASH0 */         \
{0x04400000UL,     0x04401FFFUL,   17UL,/* 128K */   33UL,                   0UL},            /* NVR */            \
{0x04420000UL,     0x04421FFFUL,   17UL,/* 128K */   34UL,                   0UL},            /* Reserved */       \
{0x04000000UL,     0x0403FFFFUL,   13UL,/* 8K */     67UL,                   0UL},            /* FLASH2 */         \
{0x21000000UL,     0x2101FFFFUL,   14UL,/* 16K */    0UL,                    1UL},            /* SRAM0 */          \
{0x21020000UL,     0x2103FFFFUL,   14UL,/* 16K */    8UL,                    1UL},            /* SRAM1 */          \
{0x22000000UL,     0x2201FFFFUL,   14UL,/* 16K */    32UL,                   1UL},            /* CPU0_DTCM */      \
{0x22100000UL,     0x2211FFFFUL,   14UL,/* 16K */    40UL,                   1UL},            /* CPU1_DTCM */      \
{0x24000000UL,     0x2400FFFFUL,   14UL,/* 16K */    56UL,                   1UL},            /* CPU0_ITCM */      \
{0x24100000UL,     0x2410FFFFUL,   14UL,/* 16K */    60UL,                   1UL},            /* CPU1_ITCM */      \
{0x40000000UL,     0x4009FFFFUL,   12UL,/* 4K */     0UL,                    2UL},            /* AFCB0 */          \
{0x40400000UL,     0x4049FFFFUL,   12UL,/* 4K */     160UL,                  2UL},            /* AFCB1 */          \

/**
 * @brief The master index of the mam peripheral
 *
 */
typedef enum
{
    MAM_MASTER_CPU0 = 0,
    MAM_MASTER_CPU1,
    MAM_MASTER_ENET = 3,
    MAM_MASTER_HSM,
    MAM_MASTER_DMA0,
    MAM_MASTER_DMA1,
} MAM_Master_Type;

/**
 * @brief The mam index
 *
 */
typedef enum
{
    MAM_INSTANCE_0 = 0,
    MAM_INSTANCE_1,
    MAM_INSTANCE_2,
} MAM_Index_Type;

#define MAM_SOFT_RESET_SUPPORT

#endif /* _DEVICE_FEATURES_FC7300F4MDDxxxxxT1B_MAM_COMMON_H_ */
