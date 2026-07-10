#ifndef _DEVICE_FEATURES_FC7300F8MDQxxxxxT1B_MAM_COMMON_H_
#define _DEVICE_FEATURES_FC7300F8MDQxxxxxT1B_MAM_COMMON_H_
/** Number of instances of the MAM module. */
#define MAM_INSTANCE_COUNT      (2u)
/** Array initializer of MAM peripheral base addresses */
#define MAM_BASE_ADDRS          { MAM0_BASE, MAM1_BASE }
/** Array initializer of MAM peripheral base pointers */
#define MAM_BASE_PTRS           { MAM0, MAM1 }

#define MAM_ACR_OFFSET          {52, 60}
#define MAM_BLOCK_REGION_MAX    26
#define MAM_BLOCK_REGION    \
 /* start addr */  /* end addr */  /* block size */  /* base block index */  /* MAM index */                       \
{0x04800000UL,     0x0481FFFFUL,   17UL,/* 128K */   0UL,                    0UL},            /* ROM */            \
{0x01000000UL,     0x011FFFFFUL,   15UL,/* 32K */    1UL,                    0UL},            /* FLASH0(PFLASH) */ \
{0x01400000UL,     0x015FFFFFUL,   15UL,/* 32K */    65UL,                   0UL},            /* FLASH1(PFLASH) */ \
{0x04400000UL,     0x04407FFFUL,   15UL,/* 32K */    129UL,                  0UL},            /* NVR0 */           \
{0x04410000UL,     0x04417FFFUL,   15UL,/* 32K */    130UL,                  0UL},            /* NVR0 */           \
{0x04480000UL,     0x044817FFUL,   15UL,/* 32K */    131UL,                  0UL},            /* NVR_CFG */        \
{0x01200000UL,     0x013FFFFFUL,   15UL,/* 32K */    132UL,                  0UL},            /* FLASH0(PFLASH) */ \
{0x01600000UL,     0x017FFFFFUL,   15UL,/* 32K */    196UL,                  0UL},            /* FLASH1(PFLASH) */ \
{0x04408000UL,     0x0440FFFFUL,   15UL,/* 32K */    260UL,                  0UL},            /* NVR1 */           \
{0x04418000UL,     0x0441FFFFUL,   15UL,/* 32K */    261UL,                  0UL},            /* NVR1 */           \
{0x04000000UL,     0x0405FFFFUL,   13UL,/* 8K */     262UL,                  0UL},            /* DFLASH */         \
{0x04420000UL,     0x04425FFFUL,   13UL,/* 8K */     310UL,                  0UL},            /* NVR2 */           \
{0x21000000UL,     0x2103FFFFUL,   14UL,/* 16K */    313UL,                  0UL},            /* SRAM0 */          \
{0x21040000UL,     0x2107FFFFUL,   14UL,/* 16K */    329UL,                  0UL},            /* SRAM1 */          \
{0x21080000UL,     0x210DFFFFUL,   14UL,/* 16K */    345UL,                  0UL},            /* SRAM2 */          \
{0x22000000UL,     0x2201FFFFUL,   14UL,/* 16K */    369UL,                  0UL},            /* CPU0_DTCM */      \
{0x24000000UL,     0x2400FFFFUL,   14UL,/* 16K */    377UL,                  0UL},            /* CPU0_ITCM */      \
{0x22100000UL,     0x2211FFFFUL,   14UL,/* 16K */    381UL,                  0UL},            /* CPU1_DTCM */      \
{0x24100000UL,     0x2410FFFFUL,   14UL,/* 16K */    389UL,                  0UL},            /* CPU1_ITCM */      \
{0x22200000UL,     0x2221FFFFUL,   14UL,/* 16K */    393UL,                  0UL},            /* CPU2_DTCM */      \
{0x24200000UL,     0x2420FFFFUL,   14UL,/* 16K */    401UL,                  0UL},            /* CPU2_ITCM */      \
{0x22300000UL,     0x2230FFFFUL,   14UL,/* 16K */    405UL,                  0UL},            /* CPU3_DTCM */      \
{0x24300000UL,     0x24307FFFUL,   14UL,/* 16K */    409UL,                  0UL},            /* CPU3_ITCM */      \
{0x40000000UL,     0x4009FFFFUL,   12UL,/* 4K */     0UL,                    1UL},            /* AFCB0 */          \
{0x40400000UL,     0x4049FFFFUL,   12UL,/* 4K */     160UL,                  1UL},            /* AFCB1 */          \
{0x40800000UL,     0x4089FFFFUL,   12UL,/* 4K */     320UL,                  1UL},            /* AFCB2 */          \


/**
 * @brief The master index of the mam peripheral
 *
 */
typedef enum
{
    MAM_MASTER_CPU0 = 0,
    MAM_MASTER_CPU1,
    MAM_MASTER_CPU2,
    MAM_MASTER_CPU3,
    MAM_MASTER_ENET,
    MAM_MASTER_HSM,
    MAM_MASTER_DMA0,
    MAM_MASTER_MDA1,
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
    MAM_MONITOR_MASTER_5,
    MAM_MONITOR_MASTER_6,
    MAM_MONITOR_MASTER_7,
    MAM_MONITOR_SLAVE_0 = 16,
    MAM_MONITOR_SLAVE_1,
    MAM_MONITOR_SLAVE_2,
    MAM_MONITOR_SLAVE_3,
    MAM_MONITOR_SLAVE_4,
    MAM_MONITOR_SLAVE_5,
    MAM_MONITOR_SLAVE_6,
    MAM_MONITOR_SLAVE_7,
    MAM_MONITOR_SLAVE_8,
    MAM_MONITOR_SLAVE_9,
    MAM_MONITOR_SLAVE_10,
} MAM_Monitor_Type;

#define MAM_WDOG_DIV_SUPPORT
#define MAM_PORT_MONITOR_SUPPORT

#endif /* _DEVICE_FEATURES_FC7300F8MDQxxxxxT1B_MAM_COMMON_H_ */
