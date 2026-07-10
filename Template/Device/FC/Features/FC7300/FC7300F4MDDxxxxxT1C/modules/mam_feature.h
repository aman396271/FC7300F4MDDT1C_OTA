#ifndef _DEVICE_FEATURES_FC7300F4MDDxxxxxT1C_MAM_COMMON_H_
#define _DEVICE_FEATURES_FC7300F4MDDxxxxxT1C_MAM_COMMON_H_
/** Number of instances of the MAM module. */
#define MAM_INSTANCE_COUNT                       (2u)
/** Array initializer of MAM peripheral base addresses */
#define MAM_BASE_ADDRS                           {MAM0_BASE, MAM1_BASE}
/** Array initializer of MAM peripheral base pointers */
#define MAM_BASE_PTRS                            {MAM0, MAM1}

#define MAM_PRIORITY_EN_KEY     0xFC7313CF
#define MAM_ACR_OFFSET          {28, 40}
#define MAM_BLOCK_REGION_MAX    15
#define MAM_BLOCK_REGION    \
 /* start addr */  /* end addr */  /* block size */  /* base block index */  /* MAM index */                       \
{0x04800000UL,     0x04813FFFUL,   17UL,/* 128K */   0UL,                    0UL},            /* ROM */            \
{0x01000000UL,     0x013FFFFFUL,   15UL,/* 32K */    1UL,                    0UL},            /* FLASH0(PFLASH) */ \
{0x04400000UL,     0x0440FFFFUL,   15UL,/* 32K */    129UL,                  0UL},            /* NVR0_0/NVR0_1 */  \
{0x04480000UL,     0x044817FFUL,   15UL,/* 32K */    131UL,                  0UL},            /* Reserved */       \
{0x04000000UL,     0x0403FFFFUL,   13UL,/* 8K */     132UL,                  0UL},            /* DFLASH */         \
{0x04420000UL,     0x04423FFFUL,   13UL,/* 8K */     164UL,                  0UL},            /* NVR2 */           \
{0x21000000UL,     0x2101FFFFUL,   14UL,/* 16K */    166UL,                  0UL},            /* SRAM0 */          \
{0x21020000UL,     0x2103FFFFUL,   14UL,/* 16K */    174UL,                  0UL},            /* SRAM1 */          \
{0x21040000UL,     0x2107FFFFUL,   14UL,/* 16K */    182UL,                  0UL},            /* SRAM2 */          \
{0x22000000UL,     0x2201FFFFUL,   14UL,/* 16K */    198UL,                  0UL},            /* CPU0_DTCM */      \
{0x24000000UL,     0x2400FFFFUL,   14UL,/* 16K */    206UL,                  0UL},            /* CPU0_ITCM */      \
{0x22100000UL,     0x2211FFFFUL,   14UL,/* 16K */    210UL,                  0UL},            /* CPU1_DTCM */      \
{0x24100000UL,     0x2410FFFFUL,   14UL,/* 16K */    218UL,                  0UL},            /* CPU1_ITCM */      \
{0x40000000UL,     0x4009FFFFUL,   12UL,/* 4K */     0UL,                    1UL},            /* AFCB0 */          \
{0x40400000UL,     0x4049FFFFUL,   12UL,/* 4K */     160UL,                  1UL},            /* AFCB1 */          \

/**
 * @brief The master index of the mam peripheral
 *
 */
typedef enum
{
    MAM_MASTER_CPU0 = 0,
    MAM_MASTER_CPU1,
    MAM_MASTER_ENET,
    MAM_MASTER_HSM,
    MAM_MASTER_DMA,
} MAM_Master_Type;

/**
 * @brief The mam index
 *
 */
typedef enum
{
    MAM_INSTANCE_0 = 0,
    MAM_INSTANCE_1,
} MAM_Index_Type;

/**
 * @brief The mam monitor index
 *
 */
typedef enum
{
    MAM_MONITOR_MASTER_0 = 0,
    MAM_MONITOR_MASTER_1,
    MAM_MONITOR_MASTER_2,
    MAM_MONITOR_MASTER_3,
    MAM_MONITOR_MASTER_4,
    MAM_MONITOR_SLAVE_0 = 16,
    MAM_MONITOR_SLAVE_1,
    MAM_MONITOR_SLAVE_2,
    MAM_MONITOR_SLAVE_3,
    MAM_MONITOR_SLAVE_4,
    MAM_MONITOR_SLAVE_5,
    MAM_MONITOR_SLAVE_6,
    MAM_MONITOR_SLAVE_7,
    MAM_MONITOR_SLAVE_8,
} MAM_Monitor_Type;

/**
 * @brief The mam slave index
 *
 */
typedef enum
{
    MAM_SLAVE_0 = 0,
    MAM_SLAVE_1,
    MAM_SLAVE_2,
    MAM_SLAVE_3,
    MAM_SLAVE_4,
    MAM_SLAVE_5,
    MAM_SLAVE_6,
    MAM_SLAVE_7,
    MAM_SLAVE_8,
} MAM_Slave_Type;

#define MAM_WDOG_DIV_SUPPORT
#define MAM_PORT_MONITOR_SUPPORT
#define MAM_SLAVE_PRIORITY_SUPPORT

#endif /* _DEVICE_FEATURES_FC7300F4MDDxxxxxT1C_MAM_COMMON_H_ */
