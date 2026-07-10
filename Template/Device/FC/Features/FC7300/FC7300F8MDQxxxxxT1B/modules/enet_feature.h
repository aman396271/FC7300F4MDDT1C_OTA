#ifndef _DEVICE_FEATURES_FC7300F8MDQxxxxxT1B_ENET_COMMON_H_
#define _DEVICE_FEATURES_FC7300F8MDQxxxxxT1B_ENET_COMMON_H_

/*********************** ENET Features ****************************/

/** Number of instances of the ENET module. */
#define ENET_INSTANCE_COUNT                             (1u)

/** ENET system control in SMISC module */
#define ENET_SYSTEM_CONTROL_SMISC                       (0u)

/** ENET system control in SCM module */
#define ENET_SYSTEM_CONTROL_SCM                         (1u)

/** ENET control status register clock from core or bus(default) */
#define ENET_CSR_INTERFACE_CORE_CLOCK                   (0u)

/** ENET DMA data bus width in bits */
#define ENET_DATA_BUS_WIDTH_BITS                        (32u)

/** ENET MTL Transmit FIFO total size in bytes */
#define ENET_MTL_TX_FIFO_SIZE                           (8192u)

/** ENET MTL Receive FIFO total size in bytes */
#define ENET_MTL_RX_FIFO_SIZE                           (8192u)

/** ENET MAC hash table bits width */
#define ENET_MAC_HASH_WIDTH_BITS                        (6u)

/** ENET VLAN hash table bits width */
#define ENET_VLAN_HASH_WIDTH_BITS                       (4u)

/** Number of ENET VLAN perfect filters */
#define ENET_VLAN_FILTER_COUNT                          (4u)

/** ENET support 1000Mbps (10M and 100M are always supported) */
#define ENET_SUPPORT_1000MBPS                           (1u)

/** ENET supported RMII mode */
#define ENET_SUPPORT_RMII                               (1u)

/** ENET supported RGMII mode */
#define ENET_SUPPORT_RGMII                              (1u)

/** ENET support reference clock pin */
#define ENET_SUPPORT_REFCLK_PIN                         (1u)

/** ENET support time sensitive networking */
#define ENET_SUPPORT_TIME_SENSITIVE_NETWORK             (1u)

/** Depth of ENET Gate Control List */
#define ENET_TSN_GCL_DEPTH                              (256u)

/** ENET Gate Control List interval time width */
#define ENET_TSN_GCL_INTERVAL_WIDTH_BITS                (24u)

/** ENET support automotive safety features */
#define ENET_SUPPORT_AUTOMOTIVE_SAFETY                  (1u)

/** ENET all tx queues support checksum offload feature */
#define ENET_ALL_TXQUEUES_SUPPORT_CHECKSUM              (1u)

/** TCM memory support SMP mode */
#define ENET_SUPPORT_TCM_SMP_MODE                       (1u)

/** ENET DTCM back door address offset */
#define ENET_DTCM_BACKDOOR_OFFSET(coreId, smp)          (0x2000000u + ((coreId) * (0x100000u - ((smp) * 0x20000u))))

/** ENET buffer in DTCM */
#define ENET_CHECK_ADDR_IN_DTCM(addr)                   (((uint32_t)(addr) >= 0x20000000u) && ((uint32_t)(addr) < 0x20070000u))

/** ENET buffer in SRAM */
#define ENET_CHECK_ADDR_IN_SRAM(addr)                   (((uint32_t)(addr) >= 0x21000000u) && ((uint32_t)(addr) < 0x210E0000u))

#endif /* _DEVICE_FEATURES_FC7300F8MDQxxxxxT1B_ENET_COMMON_H_ */
