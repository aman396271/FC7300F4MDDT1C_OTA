#ifndef _MODULE_ENET_gmbhdijq276_REGS_H_ENET_H_
#define _MODULE_ENET_gmbhdijq276_REGS_H_ENET_H_

/* ----------------------------------------------------------------------------
   -- ENET Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ENET_Peripheral_Access_Layer ENET Peripheral Access Layer
 * @{
 */

/** ENET - Size of Registers Arrays */

/** Number of MTL queues and DMA channels */
#define ENET_CHANNEL_COUNT                              (2u)

/** Number of ENET layer 3 and layer 4 filters */
#define ENET_L3L4_FILTER_COUNT                          (4u)

/** Number of ENET PPS channels */
#define ENET_PPS_CHANNEL_COUNT                          (4u)

/** ENET - Register Layout Typedef */

typedef struct
{
  __IO uint32_t MAC_CONFIGURATION             ; /* MAC_CONFIGURATION, offset: 0x0 */
  __IO uint32_t MAC_EXT_CONFIGURATION         ; /* MAC_EXT_CONFIGURATION, offset: 0x4 */
  __IO uint32_t MAC_PACKET_FILTER             ; /* MAC_PACKET_FILTER, offset: 0x8 */
  __IO uint32_t MAC_WATCHDOG_TIMEOUT          ; /* MAC_WATCHDOG_TIMEOUT, offset: 0xc */
  __IO uint32_t MAC_HASH_TABLE_REG0           ; /* MAC_HASH_TABLE_REG0, offset: 0x10 */
  __IO uint32_t MAC_HASH_TABLE_REG1           ; /* MAC_HASH_TABLE_REG1, offset: 0x14 */
       uint8_t  RESERVED_0[56];
  __IO uint32_t MAC_VLAN_TAG_CTRL             ; /* MAC_VLAN_TAG_CTRL, offset: 0x50 */
  __IO uint32_t MAC_VLAN_TAG_DATA             ; /* MAC_VLAN_TAG_DATA, offset: 0x54 */
  __IO uint32_t MAC_VLAN_HASH_TABLE           ; /* MAC_VLAN_HASH_TABLE, offset: 0x58 */
       uint8_t  RESERVED_1[4];
  __IO uint32_t MAC_VLAN_INCL_DATA            ; /* MAC_VLAN_INCL_DATA, offset: 0x60 */
  __IO uint32_t MAC_INNER_VLAN_INCL           ; /* MAC_INNER_VLAN_INCL, offset: 0x64 */
       uint8_t  RESERVED_2[8];
  __IO uint32_t MAC_Qn_TX_FLOW_CTRL[ENET_CHANNEL_COUNT]; /* MAC_Qn_TX_FLOW_CTRL, offset: 0x70 + (0x4 * n) */
       uint8_t  RESERVED_3[24];
  __IO uint32_t MAC_RX_FLOW_CTRL              ; /* MAC_RX_FLOW_CTRL, offset: 0x90 */
  __IO uint32_t MAC_RXQ_CTRL4                 ; /* MAC_RXQ_CTRL4, offset: 0x94 */
  __IO uint32_t MAC_TXQ_PRTY_MAP0             ; /* MAC_TXQ_PRTY_MAP0, offset: 0x98 */
  __IO uint32_t MAC_TXQ_PRTY_MAP1             ; /* MAC_TXQ_PRTY_MAP1, offset: 0x9c */
  __IO uint32_t MAC_RXQ_CTRL0                 ; /* MAC_RXQ_CTRL0, offset: 0xa0 */
  __IO uint32_t MAC_RXQ_CTRL1                 ; /* MAC_RXQ_CTRL1, offset: 0xa4 */
  __IO uint32_t MAC_RXQ_CTRL2                 ; /* MAC_RXQ_CTRL2, offset: 0xa8 */
  __IO uint32_t MAC_RXQ_CTRL3                 ; /* MAC_RXQ_CTRL3, offset: 0xac */
  __IO uint32_t MAC_INTERRUPT_STATUS          ; /* MAC_INTERRUPT_STATUS, offset: 0xb0 */
  __IO uint32_t MAC_INTERRUPT_ENABLE          ; /* MAC_INTERRUPT_ENABLE, offset: 0xb4 */
  __IO uint32_t MAC_RX_TX_STATUS              ; /* MAC_RX_TX_STATUS, offset: 0xb8 */
       uint8_t  RESERVED_4[60];
  __IO uint32_t MAC_PHYIF_CONTROL_STATUS      ; /* MAC_PHYIF_CONTROL_STATUS, offset: 0xf8 */
       uint8_t  RESERVED_5[20];
  __I  uint32_t MAC_VERSION                   ; /* MAC_VERSION, offset: 0x110 */
  __I  uint32_t MAC_DEBUG                     ; /* MAC_DEBUG, offset: 0x114 */
       uint8_t  RESERVED_6[4];
  __I  uint32_t MAC_HW_FEATURE0               ; /* MAC_HW_FEATURE0, offset: 0x11c */
  __I  uint32_t MAC_HW_FEATURE1               ; /* MAC_HW_FEATURE1, offset: 0x120 */
  __I  uint32_t MAC_HW_FEATURE2               ; /* MAC_HW_FEATURE2, offset: 0x124 */
  __I  uint32_t MAC_HW_FEATURE3               ; /* MAC_HW_FEATURE3, offset: 0x128 */
       uint8_t  RESERVED_7[20];
  __IO uint32_t MAC_DPP_FSM_INTERRUPT_STATUS  ; /* MAC_DPP_FSM_INTERRUPT_STATUS, offset: 0x140 */
       uint8_t  RESERVED_8[4];
  __IO uint32_t MAC_FSM_CONTROL               ; /* MAC_FSM_CONTROL, offset: 0x148 */
  __IO uint32_t MAC_FSM_ACT_TIMER             ; /* MAC_FSM_ACT_TIMER, offset: 0x14c */
  __IO uint32_t SNPS_SCS_REG1                 ; /* SNPS_SCS_REG1, offset: 0x150 */
       uint8_t  RESERVED_9[172];
  __IO uint32_t MAC_MDIO_ADDRESS              ; /* MAC_MDIO_ADDRESS, offset: 0x200 */
  __IO uint32_t MAC_MDIO_DATA                 ; /* MAC_MDIO_DATA, offset: 0x204 */
       uint8_t  RESERVED_10[40];
  __IO uint32_t MAC_CSR_SW_CTRL               ; /* MAC_CSR_SW_CTRL, offset: 0x230 */
  __IO uint32_t MAC_FPE_CTRL_STS              ; /* MAC_FPE_CTRL_STS, offset: 0x234 */
       uint8_t  RESERVED_11[8];
  __I  uint32_t MAC_PRESN_TIME_NS             ; /* MAC_PRESN_TIME_NS, offset: 0x240 */
  __IO uint32_t MAC_PRESN_TIME_UPDT           ; /* MAC_PRESN_TIME_UPDT, offset: 0x244 */
       uint8_t  RESERVED_12[184];
  __IO uint32_t MAC_ADDRESS0_HIGH             ; /* MAC_ADDRESS0_HIGH, offset: 0x300 */
  __IO uint32_t MAC_ADDRESS0_LOW              ; /* MAC_ADDRESS0_LOW, offset: 0x304 */
  __IO uint32_t MAC_ADDRESS1_HIGH             ; /* MAC_ADDRESS1_HIGH, offset: 0x308 */
  __IO uint32_t MAC_ADDRESS1_LOW              ; /* MAC_ADDRESS1_LOW, offset: 0x30C */
  __IO uint32_t MAC_ADDRESS2_HIGH             ; /* MAC_ADDRESS2_HIGH, offset: 0x310 */
  __IO uint32_t MAC_ADDRESS2_LOW              ; /* MAC_ADDRESS2_LOW, offset: 0x314 */
       uint8_t  RESERVED_13[1000];
  __IO uint32_t MMC_CONTROL                   ; /* MMC_CONTROL, offset: 0x700 */
  __I  uint32_t MMC_RX_INTERRUPT              ; /* MMC_RX_INTERRUPT, offset: 0x704 */
  __I  uint32_t MMC_TX_INTERRUPT              ; /* MMC_TX_INTERRUPT, offset: 0x708 */
  __IO uint32_t MMC_RX_INTERRUPT_MASK         ; /* MMC_RX_INTERRUPT_MASK, offset: 0x70c */
  __IO uint32_t MMC_TX_INTERRUPT_MASK         ; /* MMC_TX_INTERRUPT_MASK, offset: 0x710 */
  __I  uint32_t TX_OCTET_COUNT_GOOD_BAD       ; /* TX_OCTET_COUNT_GOOD_BAD, offset: 0x714 */
  __I  uint32_t TX_PACKET_COUNT_GOOD_BAD      ; /* TX_PACKET_COUNT_GOOD_BAD, offset: 0x718 */
  __I  uint32_t TX_BROADCAST_PACKETS_GOOD     ; /* TX_BROADCAST_PACKETS_GOOD, offset: 0x71c */
  __I  uint32_t TX_MULTICAST_PACKETS_GOOD     ; /* TX_MULTICAST_PACKETS_GOOD, offset: 0x720 */
  __I  uint32_t TX_64OCTETS_PACKETS_GOOD_BAD  ; /* TX_64OCTETS_PACKETS_GOOD_BAD, offset: 0x724 */
  __I  uint32_t TX_65TO127OCTETS_PACKETS_GOOD_BAD; /* TX_65TO127OCTETS_PACKETS_GOOD_BAD, offset: 0x728 */
  __I  uint32_t TX_128TO255OCTETS_PACKETS_GOOD_BAD; /* TX_128TO255OCTETS_PACKETS_GOOD_BAD, offset: 0x72c */
  __I  uint32_t TX_256TO511OCTETS_PACKETS_GOOD_BAD; /* TX_256TO511OCTETS_PACKETS_GOOD_BAD, offset: 0x730 */
  __I  uint32_t TX_512TO1023OCTETS_PACKETS_GOOD_BAD; /* TX_512TO1023OCTETS_PACKETS_GOOD_BAD, offset: 0x734 */
  __I  uint32_t TX_1024TOMAXOCTETS_PACKETS_GOOD_BAD; /* TX_1024TOMAXOCTETS_PACKETS_GOOD_BAD, offset: 0x738 */
  __I  uint32_t TX_UNICAST_PACKETS_GOOD_BAD   ; /* TX_UNICAST_PACKETS_GOOD_BAD, offset: 0x73c */
  __I  uint32_t TX_MULTICAST_PACKETS_GOOD_BAD ; /* TX_MULTICAST_PACKETS_GOOD_BAD, offset: 0x740 */
  __I  uint32_t TX_BROADCAST_PACKETS_GOOD_BAD ; /* TX_BROADCAST_PACKETS_GOOD_BAD, offset: 0x744 */
  __I  uint32_t TX_UNDERFLOW_ERROR_PACKETS    ; /* TX_UNDERFLOW_ERROR_PACKETS, offset: 0x748 */
  __I  uint32_t TX_SINGLE_COLLISION_GOOD_PACKETS; /* TX_SINGLE_COLLISION_GOOD_PACKETS, offset: 0x74c */
  __I  uint32_t TX_MULTIPLE_COLLISION_GOOD_PACKETS; /* TX_MULTIPLE_COLLISION_GOOD_PACKETS, offset: 0x750 */
  __I  uint32_t TX_DEFERRED_PACKETS           ; /* TX_DEFERRED_PACKETS, offset: 0x754 */
  __I  uint32_t TX_LATE_COLLISION_PACKETS     ; /* TX_LATE_COLLISION_PACKETS, offset: 0x758 */
  __I  uint32_t TX_EXCESSIVE_COLLISION_PACKETS; /* TX_EXCESSIVE_COLLISION_PACKETS, offset: 0x75c */
  __I  uint32_t TX_CARRIER_ERROR_PACKETS      ; /* TX_CARRIER_ERROR_PACKETS, offset: 0x760 */
  __I  uint32_t TX_OCTET_COUNT_GOOD           ; /* TX_OCTET_COUNT_GOOD, offset: 0x764 */
  __I  uint32_t TX_PACKET_COUNT_GOOD          ; /* TX_PACKET_COUNT_GOOD, offset: 0x768 */
  __I  uint32_t TX_EXCESSIVE_DEFERRAL_ERROR   ; /* TX_EXCESSIVE_DEFERRAL_ERROR, offset: 0x76c */
  __I  uint32_t TX_PAUSE_PACKETS              ; /* TX_PAUSE_PACKETS, offset: 0x770 */
  __I  uint32_t TX_VLAN_PACKETS_GOOD          ; /* TX_VLAN_PACKETS_GOOD, offset: 0x774 */
  __I  uint32_t TX_OSIZE_PACKETS_GOOD         ; /* TX_OSIZE_PACKETS_GOOD, offset: 0x778 */
       uint8_t  RESERVED_14[4];
  __I  uint32_t RX_PACKETS_COUNT_GOOD_BAD     ; /* RX_PACKETS_COUNT_GOOD_BAD, offset: 0x780 */
  __I  uint32_t RX_OCTET_COUNT_GOOD_BAD       ; /* RX_OCTET_COUNT_GOOD_BAD, offset: 0x784 */
  __I  uint32_t RX_OCTET_COUNT_GOOD           ; /* RX_OCTET_COUNT_GOOD, offset: 0x788 */
  __I  uint32_t RX_BROADCAST_PACKETS_GOOD     ; /* RX_BROADCAST_PACKETS_GOOD, offset: 0x78c */
  __I  uint32_t RX_MULTICAST_PACKETS_GOOD     ; /* RX_MULTICAST_PACKETS_GOOD, offset: 0x790 */
  __I  uint32_t RX_CRC_ERROR_PACKETS          ; /* RX_CRC_ERROR_PACKETS, offset: 0x794 */
  __I  uint32_t RX_ALIGNMENT_ERROR_PACKETS    ; /* RX_ALIGNMENT_ERROR_PACKETS, offset: 0x798 */
  __I  uint32_t RX_RUNT_ERROR_PACKETS         ; /* RX_RUNT_ERROR_PACKETS, offset: 0x79c */
  __I  uint32_t RX_JABBER_ERROR_PACKETS       ; /* RX_JABBER_ERROR_PACKETS, offset: 0x7a0 */
  __I  uint32_t RX_UNDERSIZE_PACKETS_GOOD     ; /* RX_UNDERSIZE_PACKETS_GOOD, offset: 0x7a4 */
  __I  uint32_t RX_OVERSIZE_PACKETS_GOOD      ; /* RX_OVERSIZE_PACKETS_GOOD, offset: 0x7a8 */
  __I  uint32_t RX_64OCTETS_PACKETS_GOOD_BAD  ; /* RX_64OCTETS_PACKETS_GOOD_BAD, offset: 0x7ac */
  __I  uint32_t RX_65TO127OCTETS_PACKETS_GOOD_BAD; /* RX_65TO127OCTETS_PACKETS_GOOD_BAD, offset: 0x7b0 */
  __I  uint32_t RX_128TO255OCTETS_PACKETS_GOOD_BAD; /* RX_128TO255OCTETS_PACKETS_GOOD_BAD, offset: 0x7b4 */
  __I  uint32_t RX_256TO511OCTETS_PACKETS_GOOD_BAD; /* RX_256TO511OCTETS_PACKETS_GOOD_BAD, offset: 0x7b8 */
  __I  uint32_t RX_512TO1023OCTETS_PACKETS_GOOD_BAD; /* RX_512TO1023OCTETS_PACKETS_GOOD_BAD, offset: 0x7bc */
  __I  uint32_t RX_1024TOMAXOCTETS_PACKETS_GOOD_BAD; /* RX_1024TOMAXOCTETS_PACKETS_GOOD_BAD, offset: 0x7c0 */
  __I  uint32_t RX_UNICAST_PACKETS_GOOD       ; /* RX_UNICAST_PACKETS_GOOD, offset: 0x7c4 */
  __I  uint32_t RX_LENGTH_ERROR_PACKETS       ; /* RX_LENGTH_ERROR_PACKETS, offset: 0x7c8 */
  __I  uint32_t RX_OUT_OF_RANGE_TYPE_PACKETS  ; /* RX_OUT_OF_RANGE_TYPE_PACKETS, offset: 0x7cc */
  __I  uint32_t RX_PAUSE_PACKETS              ; /* RX_PAUSE_PACKETS, offset: 0x7d0 */
  __I  uint32_t RX_FIFO_OVERFLOW_PACKETS      ; /* RX_FIFO_OVERFLOW_PACKETS, offset: 0x7d4 */
  __I  uint32_t RX_VLAN_PACKETS_GOOD_BAD      ; /* RX_VLAN_PACKETS_GOOD_BAD, offset: 0x7d8 */
  __I  uint32_t RX_WATCHDOG_ERROR_PACKETS     ; /* RX_WATCHDOG_ERROR_PACKETS, offset: 0x7dc */
  __I  uint32_t RX_RECEIVE_ERROR_PACKETS      ; /* RX_RECEIVE_ERROR_PACKETS, offset: 0x7e0 */
  __I  uint32_t RX_CONTROL_PACKETS_GOOD       ; /* RX_CONTROL_PACKETS_GOOD, offset: 0x7e4 */
       uint8_t  RESERVED_15[24];
  __IO uint32_t MMC_IPC_RX_INTERRUPT_MASK     ; /* MMC_IPC_RX_INTERRUPT_MASK, offset: 0x800 */
       uint8_t  RESERVED_16[4];
  __I  uint32_t MMC_IPC_RX_INTERRUPT          ; /* MMC_IPC_RX_INTERRUPT, offset: 0x808 */
       uint8_t  RESERVED_17[4];
  __I  uint32_t RXIPV4_GOOD_PACKETS           ; /* RXIPV4_GOOD_PACKETS, offset: 0x810 */
  __I  uint32_t RXIPV4_HEADER_ERROR_PACKETS   ; /* RXIPV4_HEADER_ERROR_PACKETS, offset: 0x814 */
  __I  uint32_t RXIPV4_NO_PAYLOAD_PACKETS     ; /* RXIPV4_NO_PAYLOAD_PACKETS, offset: 0x818 */
  __I  uint32_t RXIPV4_FRAGMENTED_PACKETS     ; /* RXIPV4_FRAGMENTED_PACKETS, offset: 0x81c */
  __I  uint32_t RXIPV4_UDP_CHECKSUM_DISABLED_PACKETS; /* RXIPV4_UDP_CHECKSUM_DISABLED_PACKETS, offset: 0x820 */
  __I  uint32_t RXIPV6_GOOD_PACKETS           ; /* RXIPV6_GOOD_PACKETS, offset: 0x824 */
  __I  uint32_t RXIPV6_HEADER_ERROR_PACKETS   ; /* RXIPV6_HEADER_ERROR_PACKETS, offset: 0x828 */
  __I  uint32_t RXIPV6_NO_PAYLOAD_PACKETS     ; /* RXIPV6_NO_PAYLOAD_PACKETS, offset: 0x82c */
  __I  uint32_t RXUDP_GOOD_PACKETS            ; /* RXUDP_GOOD_PACKETS, offset: 0x830 */
  __I  uint32_t RXUDP_ERROR_PACKETS           ; /* RXUDP_ERROR_PACKETS, offset: 0x834 */
  __I  uint32_t RXTCP_GOOD_PACKETS            ; /* RXTCP_GOOD_PACKETS, offset: 0x838 */
  __I  uint32_t RXTCP_ERROR_PACKETS           ; /* RXTCP_ERROR_PACKETS, offset: 0x83c */
  __I  uint32_t RXICMP_GOOD_PACKETS           ; /* RXICMP_GOOD_PACKETS, offset: 0x840 */
  __I  uint32_t RXICMP_ERROR_PACKETS          ; /* RXICMP_ERROR_PACKETS, offset: 0x844 */
       uint8_t  RESERVED_18[8];
  __I  uint32_t RXIPV4_GOOD_OCTETS            ; /* RXIPV4_GOOD_OCTETS, offset: 0x850 */
  __I  uint32_t RXIPV4_HEADER_ERROR_OCTETS    ; /* RXIPV4_HEADER_ERROR_OCTETS, offset: 0x854 */
  __I  uint32_t RXIPV4_NO_PAYLOAD_OCTETS      ; /* RXIPV4_NO_PAYLOAD_OCTETS, offset: 0x858 */
  __I  uint32_t RXIPV4_FRAGMENTED_OCTETS      ; /* RXIPV4_FRAGMENTED_OCTETS, offset: 0x85c */
  __I  uint32_t RXIPV4_UDP_CHECKSUM_DISABLE_OCTETS; /* RXIPV4_UDP_CHECKSUM_DISABLE_OCTETS, offset: 0x860 */
  __I  uint32_t RXIPV6_GOOD_OCTETS            ; /* RXIPV6_GOOD_OCTETS, offset: 0x864 */
  __I  uint32_t RXIPV6_HEADER_ERROR_OCTETS    ; /* RXIPV6_HEADER_ERROR_OCTETS, offset: 0x868 */
  __I  uint32_t RXIPV6_NO_PAYLOAD_OCTETS      ; /* RXIPV6_NO_PAYLOAD_OCTETS, offset: 0x86c */
  __I  uint32_t RXUDP_GOOD_OCTETS             ; /* RXUDP_GOOD_OCTETS, offset: 0x870 */
  __I  uint32_t RXUDP_ERROR_OCTETS            ; /* RXUDP_ERROR_OCTETS, offset: 0x874 */
  __I  uint32_t RXTCP_GOOD_OCTETS             ; /* RXTCP_GOOD_OCTETS, offset: 0x878 */
  __I  uint32_t RXTCP_ERROR_OCTETS            ; /* RXTCP_ERROR_OCTETS, offset: 0x87c */
  __I  uint32_t RXICMP_GOOD_OCTETS            ; /* RXICMP_GOOD_OCTETS, offset: 0x880 */
  __I  uint32_t RXICMP_ERROR_OCTETS           ; /* RXICMP_ERROR_OCTETS, offset: 0x884 */
       uint8_t  RESERVED_19[24];
  __I  uint32_t MMC_FPE_TX_INTERRUPT          ; /* MMC_FPE_TX_INTERRUPT, offset: 0x8a0 */
  __IO uint32_t MMC_FPE_TX_INTERRUPT_MASK     ; /* MMC_FPE_TX_INTERRUPT_MASK, offset: 0x8a4 */
  __I  uint32_t MMC_TX_FPE_FRAGMENT_CNTR      ; /* MMC_TX_FPE_FRAGMENT_CNTR, offset: 0x8a8 */
  __I  uint32_t MMC_TX_HOLD_REQ_CNTR          ; /* MMC_TX_HOLD_REQ_CNTR, offset: 0x8ac */
       uint8_t  RESERVED_20[16];
  __I  uint32_t MMC_FPE_RX_INTERRUPT          ; /* MMC_FPE_RX_INTERRUPT, offset: 0x8c0 */
  __IO uint32_t MMC_FPE_RX_INTERRUPT_MASK     ; /* MMC_FPE_RX_INTERRUPT_MASK, offset: 0x8c4 */
  __I  uint32_t MMC_RX_PACKET_ASSEMBLY_ERR_CNTR; /* MMC_RX_PACKET_ASSEMBLY_ERR_CNTR, offset: 0x8c8 */
  __I  uint32_t MMC_RX_PACKET_SMD_ERR_CNTR    ; /* MMC_RX_PACKET_SMD_ERR_CNTR, offset: 0x8cc */
  __I  uint32_t MMC_RX_PACKET_ASSEMBLY_OK_CNTR; /* MMC_RX_PACKET_ASSEMBLY_OK_CNTR, offset: 0x8d0 */
  __I  uint32_t MMC_RX_FPE_FRAGMENT_CNTR      ; /* MMC_RX_FPE_FRAGMENT_CNTR, offset: 0x8d4 */
       uint8_t  RESERVED_21[40];
  struct
  {
    __IO uint32_t MAC_L3_L4_CONTROL           ; /* MAC_L3_L4_CONTROLn, offset: 0x900 + (0x30 * n) */
    __IO uint32_t MAC_LAYER4_ADDRESS          ; /* MAC_LAYER4_ADDRESSn, offset: 0x904 + (0x30 * n) */
         uint8_t  RESERVED_22[8];
    __IO uint32_t MAC_LAYER3_ADDR0_REG        ; /* MAC_LAYER3_ADDR0_REGn, offset: 0x910 + (0x30 * n) */
    __IO uint32_t MAC_LAYER3_ADDR1_REG        ; /* MAC_LAYER3_ADDR1_REGn, offset: 0x914 + (0x30 * n) */
    __IO uint32_t MAC_LAYER3_ADDR2_REG        ; /* MAC_LAYER3_ADDR2_REGn, offset: 0x918 + (0x30 * n) */
    __IO uint32_t MAC_LAYER3_ADDR3_REG        ; /* MAC_LAYER3_ADDR3_REGn, offset: 0x91c + (0x30 * n) */
    uint8_t  RESERVED_23[16];
  } L3_L4_FILTER[ENET_L3L4_FILTER_COUNT];
  uint8_t  RESERVED_24[176];
  __IO uint32_t MAC_INDIR_ACCESS_CTRL         ; /* MAC_INDIR_ACCESS_CTRL, offset: 0xa70 */
  __IO uint32_t MAC_INDIR_ACCESS_DATA         ; /* MAC_INDIR_ACCESS_DATA, offset: 0xa74 */
       uint8_t  RESERVED_25[136];
  __IO uint32_t MAC_TIMESTAMP_CONTROL         ; /* MAC_TIMESTAMP_CONTROL, offset: 0xb00 */
  __IO uint32_t MAC_SUB_SECOND_INCREMENT      ; /* MAC_SUB_SECOND_INCREMENT, offset: 0xb04 */
  __I  uint32_t MAC_SYSTEM_TIME_SECONDS       ; /* MAC_SYSTEM_TIME_SECONDS, offset: 0xb08 */
  __I  uint32_t MAC_SYSTEM_TIME_NANOSECONDS   ; /* MAC_SYSTEM_TIME_NANOSECONDS, offset: 0xb0c */
  __IO uint32_t MAC_SYSTEM_TIME_SECONDS_UPDATE; /* MAC_SYSTEM_TIME_SECONDS_UPDATE, offset: 0xb10 */
  __IO uint32_t MAC_SYSTEM_TIME_NANOSECONDS_UPDATE; /* MAC_SYSTEM_TIME_NANOSECONDS_UPDATE, offset: 0xb14 */
  __IO uint32_t MAC_TIMESTAMP_ADDEND          ; /* MAC_TIMESTAMP_ADDEND, offset: 0xb18 */
  __IO uint32_t MAC_SYSTEM_TIME_HIGHER_WORD_SECONDS; /* MAC_SYSTEM_TIME_HIGHER_WORD_SECONDS, offset: 0xb1c */
  __IO uint32_t MAC_TIMESTAMP_STATUS          ; /* MAC_TIMESTAMP_STATUS, offset: 0xb20 */
       uint8_t  RESERVED_26[12];
  __I  uint32_t MAC_TX_TIMESTAMP_STATUS_NANOSECONDS; /* MAC_TX_TIMESTAMP_STATUS_NANOSECONDS, offset: 0xb30 */
  __IO uint32_t MAC_TX_TIMESTAMP_STATUS_SECONDS; /* MAC_TX_TIMESTAMP_STATUS_SECONDS, offset: 0xb34 */
       uint8_t  RESERVED_27[24];
  __IO uint32_t MAC_TIMESTAMP_INGRESS_ASYM_CORR; /* MAC_TIMESTAMP_INGRESS_ASYM_CORR, offset: 0xb50 */
  __IO uint32_t MAC_TIMESTAMP_EGRESS_ASYM_CORR; /* MAC_TIMESTAMP_EGRESS_ASYM_CORR, offset: 0xb54 */
  __IO uint32_t MAC_TIMESTAMP_INGRESS_CORR_NANOSECOND; /* MAC_TIMESTAMP_INGRESS_CORR_NANOSECOND, offset: 0xb58 */
  __IO uint32_t MAC_TIMESTAMP_EGRESS_CORR_NANOSECOND; /* MAC_TIMESTAMP_EGRESS_CORR_NANOSECOND, offset: 0xb5c */
  __IO uint32_t MAC_TIMESTAMP_INGRESS_CORR_SUBNANOSEC; /* MAC_TIMESTAMP_INGRESS_CORR_SUBNANOSEC, offset: 0xb60 */
  __IO uint32_t MAC_TIMESTAMP_EGRESS_CORR_SUBNANOSEC; /* MAC_TIMESTAMP_EGRESS_CORR_SUBNANOSEC, offset: 0xb64 */
  __I  uint32_t MAC_TIMESTAMP_INGRESS_LATENCY ; /* MAC_TIMESTAMP_INGRESS_LATENCY, offset: 0xb68 */
  __I  uint32_t MAC_TIMESTAMP_EGRESS_LATENCY  ; /* MAC_TIMESTAMP_EGRESS_LATENCY, offset: 0xb6c */
  struct
  {
    __IO uint32_t CONTROL                     ; /* MAC_PPS_CONTROL, offset: 0xb70 */
         uint8_t  RESERVED_28[12];
    struct
    {
      __IO uint32_t TARGET_TIME_SECONDS       ; /* MAC_PPSn_TARGET_TIME_SECONDS, offset: 0xb80 + (0x10 * n) */
      __IO uint32_t TARGET_TIME_NANOSECONDS   ; /* MAC_PPSn_TARGET_TIME_NANOSECONDS, offset: 0xb84 + (0x10 * n) */
      __IO uint32_t INTERVAL                  ; /* MAC_PPSn_INTERVAL, offset: 0xb88 + (0x10 * n) */
      __IO uint32_t WIDTH                     ; /* MAC_PPSn_WIDTH, offset: 0xb8c + (0x10 * n) */
    } CH[ENET_PPS_CHANNEL_COUNT];
  } PPS;
  __IO uint32_t MAC_PTO_CONTROL               ; /* MAC_PTO_CONTROL, offset: 0xbc0 */
  __IO uint32_t MAC_SOURCE_PORT_IDENTITY0     ; /* MAC_SOURCE_PORT_IDENTITY0, offset: 0xbc4 */
  __IO uint32_t MAC_SOURCE_PORT_IDENTITY1     ; /* MAC_SOURCE_PORT_IDENTITY1, offset: 0xbc8 */
  __IO uint32_t MAC_SOURCE_PORT_IDENTITY2     ; /* MAC_SOURCE_PORT_IDENTITY2, offset: 0xbcc */
  __IO uint32_t MAC_LOG_MESSAGE_INTERVAL      ; /* MAC_LOG_MESSAGE_INTERVAL, offset: 0xbd0 */
  uint8_t  RESERVED_29[44];
  struct
  {
    __IO uint32_t OPERATION_MODE              ; /* MTL_OPERATION_MODE, offset: 0xc00 */
         uint8_t  RESERVED_30[4];
    __IO uint32_t DBG_CTL                     ; /* MTL_DBG_CTL, offset: 0xc08 */
    __IO uint32_t DBG_STS                     ; /* MTL_DBG_STS, offset: 0xc0c */
    __IO uint32_t FIFO_DEBUG_DATA             ; /* MTL_FIFO_DEBUG_DATA, offset: 0xc10 */
         uint8_t  RESERVED_31[12];
    __I  uint32_t INTERRUPT_STATUS            ; /* MTL_INTERRUPT_STATUS, offset: 0xc20 */
         uint8_t  RESERVED_32[12];
    __IO uint32_t RXQ_DMA_MAP0                ; /* MTL_RXQ_DMA_MAP0, offset: 0xc30 */
    __IO uint32_t RXQ_DMA_MAP1                ; /* MTL_RXQ_DMA_MAP1, offset: 0xc34 */
         uint8_t  RESERVED_33[8];
    __IO uint32_t TBS_CTRL                    ; /* MTL_TBS_CTRL, offset: 0xc40 */
         uint8_t  RESERVED_34[12];
    __IO uint32_t EST_CONTROL                 ; /* MTL_EST_CONTROL, offset: 0xc50 */
    __IO uint32_t EST_EXT_CONTROL             ; /* MTL_EST_EXT_CONTROL, offset: 0xc54 */
    __IO uint32_t EST_STATUS                  ; /* MTL_EST_STATUS, offset: 0xc58 */
         uint8_t  RESERVED_35[4];
    __IO uint32_t EST_SCH_ERROR               ; /* MTL_EST_SCH_ERROR, offset: 0xc60 */
    __IO uint32_t EST_FRM_SIZE_ERROR          ; /* MTL_EST_FRM_SIZE_ERROR, offset: 0xc64 */
    __I  uint32_t EST_FRM_SIZE_CAPTURE        ; /* MTL_EST_FRM_SIZE_CAPTURE, offset: 0xc68 */
         uint8_t  RESERVED_36[4];
    __IO uint32_t EST_INTR_ENABLE             ; /* MTL_EST_INTR_ENABLE, offset: 0xc70 */
         uint8_t  RESERVED_37[12];
    __IO uint32_t EST_GCL_CONTROL             ; /* MTL_EST_GCL_CONTROL, offset: 0xc80 */
    __IO uint32_t EST_GCL_DATA                ; /* MTL_EST_GCL_DATA, offset: 0xc84 */
         uint8_t  RESERVED_38[8];
    __IO uint32_t FPE_CTRL_STS                ; /* MTL_FPE_CTRL_STS, offset: 0xc90 */
    __IO uint32_t FPE_ADVANCE                 ; /* MTL_FPE_ADVANCE, offset: 0xc94 */
         uint8_t  RESERVED_39[8];
    __IO uint32_t RXP_CONTROL_STATUS          ; /* MTL_RXP_CONTROL_STATUS, offset: 0xca0 */
    __IO uint32_t RXP_INTERRUPT_CONTROL_STATUS; /* MTL_RXP_INTERRUPT_CONTROL_STATUS, offset: 0xca4 */
    __I  uint32_t RXP_DROP_CNT                ; /* MTL_RXP_DROP_CNT, offset: 0xca8 */
    __I  uint32_t RXP_ERROR_CNT               ; /* MTL_RXP_ERROR_CNT, offset: 0xcac */
    __IO uint32_t RXP_INDIRECT_ACC_CONTROL_STATUS; /* MTL_RXP_INDIRECT_ACC_CONTROL_STATUS, offset: 0xcb0 */
    __I  uint32_t RXP_INDIRECT_ACC_DATA       ; /* MTL_RXP_INDIRECT_ACC_DATA, offset: 0xcb4 */
    __IO uint32_t RXP_BYPASS_CNT              ; /* MTL_RXP_BYPASS_CNT, offset: 0xcb8 */
         uint8_t  RESERVED_40[4];
    __IO uint32_t ECC_CONTROL                 ; /* MTL_ECC_CONTROL, offset: 0xcc0 */
    __I  uint32_t SAFETY_INTERRUPT_STATUS     ; /* MTL_SAFETY_INTERRUPT_STATUS, offset: 0xcc4 */
    __IO uint32_t ECC_INTERRUPT_ENABLE        ; /* MTL_ECC_INTERRUPT_ENABLE, offset: 0xcc8 */
    __IO uint32_t ECC_INTERRUPT_STATUS        ; /* MTL_ECC_INTERRUPT_STATUS, offset: 0xccc */
    __IO uint32_t ECC_ERR_STS_RCTL            ; /* MTL_ECC_ERR_STS_RCTL, offset: 0xcd0 */
    __I  uint32_t ECC_ERR_ADDR_STATUS         ; /* MTL_ECC_ERR_ADDR_STATUS, offset: 0xcd4 */
    __I  uint32_t ECC_ERR_CNTR_STATUS         ; /* MTL_ECC_ERR_CNTR_STATUS, offset: 0xcd8 */
         uint8_t  RESERVED_41[4];
    __IO uint32_t DPP_CONTROL                 ; /* MTL_DPP_CONTROL, offset: 0xce0 */
    __IO uint32_t DPP_ECC_EIC                 ; /* MTL_DPP_ECC_EIC, offset: 0xce4 */
         uint8_t  RESERVED_42[24];
    struct
    {
      __IO uint32_t TX_OPERATION_MODE       ; /* MTL_TXQn_OPERATION_MODE, offset: 0xd00 + (0x40 * n) */
      __I  uint32_t TX_UNDERFLOW            ; /* MTL_TXQn_UNDERFLOW, offset: 0xd04 + (0x40 * n) */
      __I  uint32_t TX_DEBUG                ; /* MTL_TXQn_DEBUG, offset: 0xd08 + (0x40 * n) */
           uint8_t  RESERVED_43[4];
      __IO uint32_t TX_ETS_CONTROL          ; /* MTL_TXQn_ETS_CONTROL, offset: 0xd10 + (0x40 * n) */
      __I  uint32_t TX_ETS_STATUS           ; /* MTL_TXQn_ETS_STATUS, offset: 0xd14 + (0x40 * n) */
      __IO uint32_t TX_QUANTUM_WEIGHT       ; /* MTL_TXQn_QUANTUM_WEIGHT, offset: 0xd18 + (0x40 * n) */
      __IO uint32_t TX_SENDSLOPECREDIT      ; /* MTL_TXQn_SENDSLOPECREDIT, offset: 0xd1c + (0x40 * n) */
      __IO uint32_t TX_HICREDIT             ; /* MTL_TXQn_HICREDIT, offset: 0xd20 + (0x40 * n) */
      __IO uint32_t TX_LOCREDIT             ; /* MTL_TXQn_LOCREDIT, offset: 0xd24 + (0x40 * n) */
           uint8_t  RESERVED_44[4];
      __IO uint32_t INTERRUPT_CONTROL_STATUS; /* MTL_Qn_INTERRUPT_CONTROL_STATUS, offset: 0xd2c + (0x40 * n) */
      __IO uint32_t RX_OPERATION_MODE       ; /* MTL_RXQn_OPERATION_MODE, offset: 0xd30 + (0x40 * n) */
      __I  uint32_t RX_MISSED_PACKET_OVERFLOW_CNT; /* MTL_RXQn_MISSED_PACKET_OVERFLOW_CNT, offset: 0xd34 + (0x40 * n) */
      __I  uint32_t RX_DEBUG                ; /* MTL_RXQn_DEBUG, offset: 0xd38 + (0x40 * n) */
      __IO uint32_t RX_CONTROL              ; /* MTL_RXQn_CONTROL, offset: 0xd3c + (0x40 * n) */
    } QUEUE[ENET_CHANNEL_COUNT];
  } MTL;
  uint8_t  RESERVED_45[640];
  struct
  {
    __IO uint32_t MODE                      ; /* DMA_MODE, offset: 0x1000 */
    __IO uint32_t SYSBUS_MODE               ; /* DMA_SYSBUS_MODE, offset: 0x1004 */
    __I  uint32_t INTERRUPT_STATUS          ; /* DMA_INTERRUPT_STATUS, offset: 0x1008 */
    __I  uint32_t DEBUG_STATUS0             ; /* DMA_DEBUG_STATUS0, offset: 0x100c */
         uint8_t  RESERVED_46[64];
    __IO uint32_t TBS_CTRL[4]               ; /* DMA_TBS_CTRLn, offset: 0x1050 + (0x4 * n) */
         uint8_t  RESERVED_47[32];
    __I  uint32_t SAFETY_INTERRUPT_STATUS   ; /* DMA_SAFETY_INTERRUPT_STATUS, offset: 0x1080 */
    __IO uint32_t ECC_INTERRUPT_ENABLE      ; /* DMA_ECC_INTERRUPT_ENABLE, offset: 0x1084 */
    __IO uint32_t ECC_INTERRUPT_STATUS      ; /* DMA_ECC_INTERRUPT_STATUS, offset: 0x1088 */
         uint8_t  RESERVED_48[116];
    struct
    {
      __IO uint32_t CONTROL               ; /* DMA_CHn_CONTROL, offset: 0x1100 */
      __IO uint32_t TX_CONTROL            ; /* DMA_CHn_TX_CONTROL, offset: 0x1104 */
      __IO uint32_t RX_CONTROL            ; /* DMA_CHn_RX_CONTROL, offset: 0x1108 */
           uint8_t  RESERVED_49[8];
      __IO uint32_t TXDESC_LIST_ADDRESS   ; /* DMA_CHn_TXDESC_LIST_ADDRESS, offset: 0x1114 */
           uint8_t  RESERVED_50[4];
      __IO uint32_t RXDESC_LIST_ADDRESS   ; /* DMA_CHn_RXDESC_LIST_ADDRESS, offset: 0x111c */
      __IO uint32_t TXDESC_TAIL_POINTER   ; /* DMA_CHn_TXDESC_TAIL_POINTER, offset: 0x1120 */
           uint8_t  RESERVED_51[4];
      __IO uint32_t RXDESC_TAIL_POINTER   ; /* DMA_CHn_RXDESC_TAIL_POINTER, offset: 0x1128 */
      __IO uint32_t TXDESC_RING_LENGTH    ; /* DMA_CHn_TXDESC_RING_LENGTH, offset: 0x112c */
      __IO uint32_t RX_CONTROL2           ; /* DMA_CH0_RX_CONTROL2, offset: 0x1130 */
      __IO uint32_t INTERRUPT_ENABLE      ; /* DMA_CH0_INTERRUPT_ENABLE, offset: 0x1134 */
      __IO uint32_t RX_INTERRUPT_WATCHDOG_TIMER; /* DMA_CH0_RX_INTERRUPT_WATCHDOG_TIMER, offset: 0x1138 */
      __IO uint32_t SLOT_FUNCTION_CONTROL_STATUS; /* DMA_CH0_SLOT_FUNCTION_CONTROL_STATUS, offset: 0x113c */
           uint8_t  RESERVED_52[4];
      __I  uint32_t CURRENT_APP_TXDESC    ; /* DMA_CH0_CURRENT_APP_TXDESC, offset: 0x1144 */
           uint8_t  RESERVED_53[4];
      __I  uint32_t CURRENT_APP_RXDESC    ; /* DMA_CH0_CURRENT_APP_RXDESC, offset: 0x114c */
           uint8_t  RESERVED_54[4];
      __I  uint32_t CURRENT_APP_TXBUFFER  ; /* DMA_CH0_CURRENT_APP_TXBUFFER, offset: 0x1154 */
           uint8_t  RESERVED_55[4];
      __I  uint32_t CURRENT_APP_RXBUFFER  ; /* DMA_CH0_CURRENT_APP_RXBUFFER, offset: 0x115C */
      __IO uint32_t STATUS                ; /* DMA_CH0_STATUS, offset: 0x1160 */
      __I  uint32_t MISS_FRAME_CNT        ; /* DMA_CH0_MISS_FRAME_CNT, offset: 0x1164 */
      __I  uint32_t RXP_ACCEPT_CNT        ; /* DMA_CH0_RXP_ACCEPT_CNT, offset: 0x1168 */
      __I  uint32_t RX_ERI_CNT            ; /* DMA_CH0_RX_ERI_CNT, offset: 0x116C */
           uint8_t  RESERVED_56[16];
    } CH[ENET_CHANNEL_COUNT];
  } ENET_DMA;
} ENET_Type, *ENET_MemMapPtr;

/** Number of instances of the ENET module. */

/* ENET - Peripheral instance base addresses */
/** Peripheral ENET base address */
#define ENET_BASE                                (0x40074000u)
/** Peripheral ENET base pointer */
#define ENET                                     ((ENET_Type *)ENET_BASE)
/** Array initializer of ENET peripheral base addresses */
#define ENET_BASE_ADDRS                          {ENET_BASE}
/** Array initializer of ENET peripheral base pointers */
#define ENET_BASE_PTRS                           {ENET}
// need fill by yourself
///** Number of interrupt vector arrays for the ENET module. */
//#define ENET_IRQS_ARR_COUNT                    (5u)
///** Number of interrupt channels for the ENET module. */
//#define ENET_IRQS_CH_COUNT                     (2u)
///** Interrupt vectors for the ENET peripheral type */
//#define ENET_IRQS                              {ENET_Tx0_IRQn,ENET_Tx1_IRQn,ENET_Rx0_IRQn,ENET_Rx1_IRQn,ENET_System_IRQn}


/* ----------------------------------------------------------------------------
   -- ENET Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ENET_Register_Masks ENET Register Masks
 * @{
 */

/* MAC_CONFIGURATION Bit Fields */
#define ENET_MAC_CONFIGURATION_SARC_MASK 0x70000000u
#define ENET_MAC_CONFIGURATION_SARC_SHIFT 28u
#define ENET_MAC_CONFIGURATION_SARC_WIDTH 3u
#define ENET_MAC_CONFIGURATION_SARC(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_CONFIGURATION_SARC_SHIFT))&ENET_MAC_CONFIGURATION_SARC_MASK)
#define ENET_MAC_CONFIGURATION_IPC_MASK 0x8000000u
#define ENET_MAC_CONFIGURATION_IPC_SHIFT 27u
#define ENET_MAC_CONFIGURATION_IPC_WIDTH 1u
#define ENET_MAC_CONFIGURATION_IPC(x)  (((uint32_t)(((uint32_t)(x))<<ENET_MAC_CONFIGURATION_IPC_SHIFT))&ENET_MAC_CONFIGURATION_IPC_MASK)
#define ENET_MAC_CONFIGURATION_IPG_MASK 0x7000000u
#define ENET_MAC_CONFIGURATION_IPG_SHIFT 24u
#define ENET_MAC_CONFIGURATION_IPG_WIDTH 3u
#define ENET_MAC_CONFIGURATION_IPG(x)  (((uint32_t)(((uint32_t)(x))<<ENET_MAC_CONFIGURATION_IPG_SHIFT))&ENET_MAC_CONFIGURATION_IPG_MASK)
#define ENET_MAC_CONFIGURATION_GPSLCE_MASK 0x800000u
#define ENET_MAC_CONFIGURATION_GPSLCE_SHIFT 23u
#define ENET_MAC_CONFIGURATION_GPSLCE_WIDTH 1u
#define ENET_MAC_CONFIGURATION_GPSLCE(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_CONFIGURATION_GPSLCE_SHIFT))&ENET_MAC_CONFIGURATION_GPSLCE_MASK)
#define ENET_MAC_CONFIGURATION_S2KP_MASK 0x400000u
#define ENET_MAC_CONFIGURATION_S2KP_SHIFT 22u
#define ENET_MAC_CONFIGURATION_S2KP_WIDTH 1u
#define ENET_MAC_CONFIGURATION_S2KP(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_CONFIGURATION_S2KP_SHIFT))&ENET_MAC_CONFIGURATION_S2KP_MASK)
#define ENET_MAC_CONFIGURATION_CST_MASK 0x200000u
#define ENET_MAC_CONFIGURATION_CST_SHIFT 21u
#define ENET_MAC_CONFIGURATION_CST_WIDTH 1u
#define ENET_MAC_CONFIGURATION_CST(x)  (((uint32_t)(((uint32_t)(x))<<ENET_MAC_CONFIGURATION_CST_SHIFT))&ENET_MAC_CONFIGURATION_CST_MASK)
#define ENET_MAC_CONFIGURATION_ACS_MASK 0x100000u
#define ENET_MAC_CONFIGURATION_ACS_SHIFT 20u
#define ENET_MAC_CONFIGURATION_ACS_WIDTH 1u
#define ENET_MAC_CONFIGURATION_ACS(x)  (((uint32_t)(((uint32_t)(x))<<ENET_MAC_CONFIGURATION_ACS_SHIFT))&ENET_MAC_CONFIGURATION_ACS_MASK)
#define ENET_MAC_CONFIGURATION_WD_MASK 0x80000u
#define ENET_MAC_CONFIGURATION_WD_SHIFT 19u
#define ENET_MAC_CONFIGURATION_WD_WIDTH 1u
#define ENET_MAC_CONFIGURATION_WD(x)   (((uint32_t)(((uint32_t)(x))<<ENET_MAC_CONFIGURATION_WD_SHIFT))&ENET_MAC_CONFIGURATION_WD_MASK)
#define ENET_MAC_CONFIGURATION_BE_MASK 0x40000u
#define ENET_MAC_CONFIGURATION_BE_SHIFT 18u
#define ENET_MAC_CONFIGURATION_BE_WIDTH 1u
#define ENET_MAC_CONFIGURATION_BE(x)   (((uint32_t)(((uint32_t)(x))<<ENET_MAC_CONFIGURATION_BE_SHIFT))&ENET_MAC_CONFIGURATION_BE_MASK)
#define ENET_MAC_CONFIGURATION_JD_MASK 0x20000u
#define ENET_MAC_CONFIGURATION_JD_SHIFT 17u
#define ENET_MAC_CONFIGURATION_JD_WIDTH 1u
#define ENET_MAC_CONFIGURATION_JD(x)   (((uint32_t)(((uint32_t)(x))<<ENET_MAC_CONFIGURATION_JD_SHIFT))&ENET_MAC_CONFIGURATION_JD_MASK)
#define ENET_MAC_CONFIGURATION_JE_MASK 0x10000u
#define ENET_MAC_CONFIGURATION_JE_SHIFT 16u
#define ENET_MAC_CONFIGURATION_JE_WIDTH 1u
#define ENET_MAC_CONFIGURATION_JE(x)   (((uint32_t)(((uint32_t)(x))<<ENET_MAC_CONFIGURATION_JE_SHIFT))&ENET_MAC_CONFIGURATION_JE_MASK)
#define ENET_MAC_CONFIGURATION_PS_MASK 0x8000u
#define ENET_MAC_CONFIGURATION_PS_SHIFT 15u
#define ENET_MAC_CONFIGURATION_PS_WIDTH 1u
#define ENET_MAC_CONFIGURATION_PS(x)   (((uint32_t)(((uint32_t)(x))<<ENET_MAC_CONFIGURATION_PS_SHIFT))&ENET_MAC_CONFIGURATION_PS_MASK)
#define ENET_MAC_CONFIGURATION_FES_MASK 0x4000u
#define ENET_MAC_CONFIGURATION_FES_SHIFT 14u
#define ENET_MAC_CONFIGURATION_FES_WIDTH 1u
#define ENET_MAC_CONFIGURATION_FES(x)  (((uint32_t)(((uint32_t)(x))<<ENET_MAC_CONFIGURATION_FES_SHIFT))&ENET_MAC_CONFIGURATION_FES_MASK)
#define ENET_MAC_CONFIGURATION_DM_MASK 0x2000u
#define ENET_MAC_CONFIGURATION_DM_SHIFT 13u
#define ENET_MAC_CONFIGURATION_DM_WIDTH 1u
#define ENET_MAC_CONFIGURATION_DM(x)   (((uint32_t)(((uint32_t)(x))<<ENET_MAC_CONFIGURATION_DM_SHIFT))&ENET_MAC_CONFIGURATION_DM_MASK)
#define ENET_MAC_CONFIGURATION_LM_MASK 0x1000u
#define ENET_MAC_CONFIGURATION_LM_SHIFT 12u
#define ENET_MAC_CONFIGURATION_LM_WIDTH 1u
#define ENET_MAC_CONFIGURATION_LM(x)   (((uint32_t)(((uint32_t)(x))<<ENET_MAC_CONFIGURATION_LM_SHIFT))&ENET_MAC_CONFIGURATION_LM_MASK)
#define ENET_MAC_CONFIGURATION_ECRSFD_MASK 0x800u
#define ENET_MAC_CONFIGURATION_ECRSFD_SHIFT 11u
#define ENET_MAC_CONFIGURATION_ECRSFD_WIDTH 1u
#define ENET_MAC_CONFIGURATION_ECRSFD(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_CONFIGURATION_ECRSFD_SHIFT))&ENET_MAC_CONFIGURATION_ECRSFD_MASK)
#define ENET_MAC_CONFIGURATION_DO_MASK 0x400u
#define ENET_MAC_CONFIGURATION_DO_SHIFT 10u
#define ENET_MAC_CONFIGURATION_DO_WIDTH 1u
#define ENET_MAC_CONFIGURATION_DO(x)   (((uint32_t)(((uint32_t)(x))<<ENET_MAC_CONFIGURATION_DO_SHIFT))&ENET_MAC_CONFIGURATION_DO_MASK)
#define ENET_MAC_CONFIGURATION_DCRS_MASK 0x200u
#define ENET_MAC_CONFIGURATION_DCRS_SHIFT 9u
#define ENET_MAC_CONFIGURATION_DCRS_WIDTH 1u
#define ENET_MAC_CONFIGURATION_DCRS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_CONFIGURATION_DCRS_SHIFT))&ENET_MAC_CONFIGURATION_DCRS_MASK)
#define ENET_MAC_CONFIGURATION_DR_MASK 0x100u
#define ENET_MAC_CONFIGURATION_DR_SHIFT 8u
#define ENET_MAC_CONFIGURATION_DR_WIDTH 1u
#define ENET_MAC_CONFIGURATION_DR(x)   (((uint32_t)(((uint32_t)(x))<<ENET_MAC_CONFIGURATION_DR_SHIFT))&ENET_MAC_CONFIGURATION_DR_MASK)
#define ENET_MAC_CONFIGURATION_BL_MASK 0x60u
#define ENET_MAC_CONFIGURATION_BL_SHIFT 5u
#define ENET_MAC_CONFIGURATION_BL_WIDTH 2u
#define ENET_MAC_CONFIGURATION_BL(x)   (((uint32_t)(((uint32_t)(x))<<ENET_MAC_CONFIGURATION_BL_SHIFT))&ENET_MAC_CONFIGURATION_BL_MASK)
#define ENET_MAC_CONFIGURATION_DC_MASK 0x10u
#define ENET_MAC_CONFIGURATION_DC_SHIFT 4u
#define ENET_MAC_CONFIGURATION_DC_WIDTH 1u
#define ENET_MAC_CONFIGURATION_DC(x)   (((uint32_t)(((uint32_t)(x))<<ENET_MAC_CONFIGURATION_DC_SHIFT))&ENET_MAC_CONFIGURATION_DC_MASK)
#define ENET_MAC_CONFIGURATION_PRELEN_MASK 0xCu
#define ENET_MAC_CONFIGURATION_PRELEN_SHIFT 2u
#define ENET_MAC_CONFIGURATION_PRELEN_WIDTH 2u
#define ENET_MAC_CONFIGURATION_PRELEN(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_CONFIGURATION_PRELEN_SHIFT))&ENET_MAC_CONFIGURATION_PRELEN_MASK)
#define ENET_MAC_CONFIGURATION_TE_MASK 0x2u
#define ENET_MAC_CONFIGURATION_TE_SHIFT 1u
#define ENET_MAC_CONFIGURATION_TE_WIDTH 1u
#define ENET_MAC_CONFIGURATION_TE(x)   (((uint32_t)(((uint32_t)(x))<<ENET_MAC_CONFIGURATION_TE_SHIFT))&ENET_MAC_CONFIGURATION_TE_MASK)
#define ENET_MAC_CONFIGURATION_RE_MASK 0x1u
#define ENET_MAC_CONFIGURATION_RE_SHIFT 0u
#define ENET_MAC_CONFIGURATION_RE_WIDTH 1u
#define ENET_MAC_CONFIGURATION_RE(x)   (((uint32_t)(((uint32_t)(x))<<ENET_MAC_CONFIGURATION_RE_SHIFT))&ENET_MAC_CONFIGURATION_RE_MASK)
/* MAC_CONFIGURATION Reg Mask */
#define ENET_MAC_CONFIGURATION_MASK    0x7FFFFF7Fu

/* MAC_EXT_CONFIGURATION Bit Fields */
#define ENET_MAC_EXT_CONFIGURATION_EIPG_MASK 0x3E000000u
#define ENET_MAC_EXT_CONFIGURATION_EIPG_SHIFT 25u
#define ENET_MAC_EXT_CONFIGURATION_EIPG_WIDTH 5u
#define ENET_MAC_EXT_CONFIGURATION_EIPG(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_EXT_CONFIGURATION_EIPG_SHIFT))&ENET_MAC_EXT_CONFIGURATION_EIPG_MASK)
#define ENET_MAC_EXT_CONFIGURATION_EIPGEN_MASK 0x1000000u
#define ENET_MAC_EXT_CONFIGURATION_EIPGEN_SHIFT 24u
#define ENET_MAC_EXT_CONFIGURATION_EIPGEN_WIDTH 1u
#define ENET_MAC_EXT_CONFIGURATION_EIPGEN(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_EXT_CONFIGURATION_EIPGEN_SHIFT))&ENET_MAC_EXT_CONFIGURATION_EIPGEN_MASK)
#define ENET_MAC_EXT_CONFIGURATION_PDC_MASK 0x80000u
#define ENET_MAC_EXT_CONFIGURATION_PDC_SHIFT 19u
#define ENET_MAC_EXT_CONFIGURATION_PDC_WIDTH 1u
#define ENET_MAC_EXT_CONFIGURATION_PDC(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_EXT_CONFIGURATION_PDC_SHIFT))&ENET_MAC_EXT_CONFIGURATION_PDC_MASK)
#define ENET_MAC_EXT_CONFIGURATION_USP_MASK 0x40000u
#define ENET_MAC_EXT_CONFIGURATION_USP_SHIFT 18u
#define ENET_MAC_EXT_CONFIGURATION_USP_WIDTH 1u
#define ENET_MAC_EXT_CONFIGURATION_USP(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_EXT_CONFIGURATION_USP_SHIFT))&ENET_MAC_EXT_CONFIGURATION_USP_MASK)
#define ENET_MAC_EXT_CONFIGURATION_SPEN_MASK 0x20000u
#define ENET_MAC_EXT_CONFIGURATION_SPEN_SHIFT 17u
#define ENET_MAC_EXT_CONFIGURATION_SPEN_WIDTH 1u
#define ENET_MAC_EXT_CONFIGURATION_SPEN(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_EXT_CONFIGURATION_SPEN_SHIFT))&ENET_MAC_EXT_CONFIGURATION_SPEN_MASK)
#define ENET_MAC_EXT_CONFIGURATION_DCRCC_MASK 0x10000u
#define ENET_MAC_EXT_CONFIGURATION_DCRCC_SHIFT 16u
#define ENET_MAC_EXT_CONFIGURATION_DCRCC_WIDTH 1u
#define ENET_MAC_EXT_CONFIGURATION_DCRCC(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_EXT_CONFIGURATION_DCRCC_SHIFT))&ENET_MAC_EXT_CONFIGURATION_DCRCC_MASK)
#define ENET_MAC_EXT_CONFIGURATION_GPSL_MASK 0x3FFFu
#define ENET_MAC_EXT_CONFIGURATION_GPSL_SHIFT 0u
#define ENET_MAC_EXT_CONFIGURATION_GPSL_WIDTH 14u
#define ENET_MAC_EXT_CONFIGURATION_GPSL(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_EXT_CONFIGURATION_GPSL_SHIFT))&ENET_MAC_EXT_CONFIGURATION_GPSL_MASK)
/* MAC_EXT_CONFIGURATION Reg Mask */
#define ENET_MAC_EXT_CONFIGURATION_MASK 0x3F0F3FFFu

/* MAC_PACKET_FILTER Bit Fields */
#define ENET_MAC_PACKET_FILTER_RA_MASK 0x80000000u
#define ENET_MAC_PACKET_FILTER_RA_SHIFT 31u
#define ENET_MAC_PACKET_FILTER_RA_WIDTH 1u
#define ENET_MAC_PACKET_FILTER_RA(x)   (((uint32_t)(((uint32_t)(x))<<ENET_MAC_PACKET_FILTER_RA_SHIFT))&ENET_MAC_PACKET_FILTER_RA_MASK)
#define ENET_MAC_PACKET_FILTER_DNTU_MASK 0x200000u
#define ENET_MAC_PACKET_FILTER_DNTU_SHIFT 21u
#define ENET_MAC_PACKET_FILTER_DNTU_WIDTH 1u
#define ENET_MAC_PACKET_FILTER_DNTU(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_PACKET_FILTER_DNTU_SHIFT))&ENET_MAC_PACKET_FILTER_DNTU_MASK)
#define ENET_MAC_PACKET_FILTER_IPFE_MASK 0x100000u
#define ENET_MAC_PACKET_FILTER_IPFE_SHIFT 20u
#define ENET_MAC_PACKET_FILTER_IPFE_WIDTH 1u
#define ENET_MAC_PACKET_FILTER_IPFE(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_PACKET_FILTER_IPFE_SHIFT))&ENET_MAC_PACKET_FILTER_IPFE_MASK)
#define ENET_MAC_PACKET_FILTER_VTFE_MASK 0x10000u
#define ENET_MAC_PACKET_FILTER_VTFE_SHIFT 16u
#define ENET_MAC_PACKET_FILTER_VTFE_WIDTH 1u
#define ENET_MAC_PACKET_FILTER_VTFE(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_PACKET_FILTER_VTFE_SHIFT))&ENET_MAC_PACKET_FILTER_VTFE_MASK)
#define ENET_MAC_PACKET_FILTER_HPF_MASK 0x400u
#define ENET_MAC_PACKET_FILTER_HPF_SHIFT 10u
#define ENET_MAC_PACKET_FILTER_HPF_WIDTH 1u
#define ENET_MAC_PACKET_FILTER_HPF(x)  (((uint32_t)(((uint32_t)(x))<<ENET_MAC_PACKET_FILTER_HPF_SHIFT))&ENET_MAC_PACKET_FILTER_HPF_MASK)
#define ENET_MAC_PACKET_FILTER_SAF_MASK 0x200u
#define ENET_MAC_PACKET_FILTER_SAF_SHIFT 9u
#define ENET_MAC_PACKET_FILTER_SAF_WIDTH 1u
#define ENET_MAC_PACKET_FILTER_SAF(x)  (((uint32_t)(((uint32_t)(x))<<ENET_MAC_PACKET_FILTER_SAF_SHIFT))&ENET_MAC_PACKET_FILTER_SAF_MASK)
#define ENET_MAC_PACKET_FILTER_SAIF_MASK 0x100u
#define ENET_MAC_PACKET_FILTER_SAIF_SHIFT 8u
#define ENET_MAC_PACKET_FILTER_SAIF_WIDTH 1u
#define ENET_MAC_PACKET_FILTER_SAIF(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_PACKET_FILTER_SAIF_SHIFT))&ENET_MAC_PACKET_FILTER_SAIF_MASK)
#define ENET_MAC_PACKET_FILTER_PCF_MASK 0xC0u
#define ENET_MAC_PACKET_FILTER_PCF_SHIFT 6u
#define ENET_MAC_PACKET_FILTER_PCF_WIDTH 2u
#define ENET_MAC_PACKET_FILTER_PCF(x)  (((uint32_t)(((uint32_t)(x))<<ENET_MAC_PACKET_FILTER_PCF_SHIFT))&ENET_MAC_PACKET_FILTER_PCF_MASK)
#define ENET_MAC_PACKET_FILTER_DBF_MASK 0x20u
#define ENET_MAC_PACKET_FILTER_DBF_SHIFT 5u
#define ENET_MAC_PACKET_FILTER_DBF_WIDTH 1u
#define ENET_MAC_PACKET_FILTER_DBF(x)  (((uint32_t)(((uint32_t)(x))<<ENET_MAC_PACKET_FILTER_DBF_SHIFT))&ENET_MAC_PACKET_FILTER_DBF_MASK)
#define ENET_MAC_PACKET_FILTER_PM_MASK 0x10u
#define ENET_MAC_PACKET_FILTER_PM_SHIFT 4u
#define ENET_MAC_PACKET_FILTER_PM_WIDTH 1u
#define ENET_MAC_PACKET_FILTER_PM(x)   (((uint32_t)(((uint32_t)(x))<<ENET_MAC_PACKET_FILTER_PM_SHIFT))&ENET_MAC_PACKET_FILTER_PM_MASK)
#define ENET_MAC_PACKET_FILTER_DAIF_MASK 0x8u
#define ENET_MAC_PACKET_FILTER_DAIF_SHIFT 3u
#define ENET_MAC_PACKET_FILTER_DAIF_WIDTH 1u
#define ENET_MAC_PACKET_FILTER_DAIF(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_PACKET_FILTER_DAIF_SHIFT))&ENET_MAC_PACKET_FILTER_DAIF_MASK)
#define ENET_MAC_PACKET_FILTER_HMC_MASK 0x4u
#define ENET_MAC_PACKET_FILTER_HMC_SHIFT 2u
#define ENET_MAC_PACKET_FILTER_HMC_WIDTH 1u
#define ENET_MAC_PACKET_FILTER_HMC(x)  (((uint32_t)(((uint32_t)(x))<<ENET_MAC_PACKET_FILTER_HMC_SHIFT))&ENET_MAC_PACKET_FILTER_HMC_MASK)
#define ENET_MAC_PACKET_FILTER_HUC_MASK 0x2u
#define ENET_MAC_PACKET_FILTER_HUC_SHIFT 1u
#define ENET_MAC_PACKET_FILTER_HUC_WIDTH 1u
#define ENET_MAC_PACKET_FILTER_HUC(x)  (((uint32_t)(((uint32_t)(x))<<ENET_MAC_PACKET_FILTER_HUC_SHIFT))&ENET_MAC_PACKET_FILTER_HUC_MASK)
#define ENET_MAC_PACKET_FILTER_PR_MASK 0x1u
#define ENET_MAC_PACKET_FILTER_PR_SHIFT 0u
#define ENET_MAC_PACKET_FILTER_PR_WIDTH 1u
#define ENET_MAC_PACKET_FILTER_PR(x)   (((uint32_t)(((uint32_t)(x))<<ENET_MAC_PACKET_FILTER_PR_SHIFT))&ENET_MAC_PACKET_FILTER_PR_MASK)
/* MAC_PACKET_FILTER Reg Mask */
#define ENET_MAC_PACKET_FILTER_MASK    0x803107FFu

/* MAC_WATCHDOG_TIMEOUT Bit Fields */
#define ENET_MAC_WATCHDOG_TIMEOUT_PWE_MASK 0x100u
#define ENET_MAC_WATCHDOG_TIMEOUT_PWE_SHIFT 8u
#define ENET_MAC_WATCHDOG_TIMEOUT_PWE_WIDTH 1u
#define ENET_MAC_WATCHDOG_TIMEOUT_PWE(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_WATCHDOG_TIMEOUT_PWE_SHIFT))&ENET_MAC_WATCHDOG_TIMEOUT_PWE_MASK)
#define ENET_MAC_WATCHDOG_TIMEOUT_WTO_MASK 0xFu
#define ENET_MAC_WATCHDOG_TIMEOUT_WTO_SHIFT 0u
#define ENET_MAC_WATCHDOG_TIMEOUT_WTO_WIDTH 4u
#define ENET_MAC_WATCHDOG_TIMEOUT_WTO(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_WATCHDOG_TIMEOUT_WTO_SHIFT))&ENET_MAC_WATCHDOG_TIMEOUT_WTO_MASK)
/* MAC_WATCHDOG_TIMEOUT Reg Mask */
#define ENET_MAC_WATCHDOG_TIMEOUT_MASK 0x0000010Fu

/* MAC_HASH_TABLE_REG0 Bit Fields */
#define ENET_MAC_HASH_TABLE_REG0_HT31T0_MASK 0xFFFFFFFFu
#define ENET_MAC_HASH_TABLE_REG0_HT31T0_SHIFT 0u
#define ENET_MAC_HASH_TABLE_REG0_HT31T0_WIDTH 32u
#define ENET_MAC_HASH_TABLE_REG0_HT31T0(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_HASH_TABLE_REG0_HT31T0_SHIFT))&ENET_MAC_HASH_TABLE_REG0_HT31T0_MASK)
/* MAC_HASH_TABLE_REG0 Reg Mask */
#define ENET_MAC_HASH_TABLE_REG0_MASK  0xFFFFFFFFu

/* MAC_HASH_TABLE_REG1 Bit Fields */
#define ENET_MAC_HASH_TABLE_REG1_HT63T32_MASK 0xFFFFFFFFu
#define ENET_MAC_HASH_TABLE_REG1_HT63T32_SHIFT 0u
#define ENET_MAC_HASH_TABLE_REG1_HT63T32_WIDTH 32u
#define ENET_MAC_HASH_TABLE_REG1_HT63T32(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_HASH_TABLE_REG1_HT63T32_SHIFT))&ENET_MAC_HASH_TABLE_REG1_HT63T32_MASK)
/* MAC_HASH_TABLE_REG1 Reg Mask */
#define ENET_MAC_HASH_TABLE_REG1_MASK  0xFFFFFFFFu

/* MAC_VLAN_TAG_CTRL Bit Fields */
#define ENET_MAC_VLAN_TAG_CTRL_EIVLRXS_MASK 0x80000000u
#define ENET_MAC_VLAN_TAG_CTRL_EIVLRXS_SHIFT 31u
#define ENET_MAC_VLAN_TAG_CTRL_EIVLRXS_WIDTH 1u
#define ENET_MAC_VLAN_TAG_CTRL_EIVLRXS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_VLAN_TAG_CTRL_EIVLRXS_SHIFT))&ENET_MAC_VLAN_TAG_CTRL_EIVLRXS_MASK)
#define ENET_MAC_VLAN_TAG_CTRL_EIVLS_MASK 0x30000000u
#define ENET_MAC_VLAN_TAG_CTRL_EIVLS_SHIFT 28u
#define ENET_MAC_VLAN_TAG_CTRL_EIVLS_WIDTH 2u
#define ENET_MAC_VLAN_TAG_CTRL_EIVLS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_VLAN_TAG_CTRL_EIVLS_SHIFT))&ENET_MAC_VLAN_TAG_CTRL_EIVLS_MASK)
#define ENET_MAC_VLAN_TAG_CTRL_ERIVLT_MASK 0x8000000u
#define ENET_MAC_VLAN_TAG_CTRL_ERIVLT_SHIFT 27u
#define ENET_MAC_VLAN_TAG_CTRL_ERIVLT_WIDTH 1u
#define ENET_MAC_VLAN_TAG_CTRL_ERIVLT(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_VLAN_TAG_CTRL_ERIVLT_SHIFT))&ENET_MAC_VLAN_TAG_CTRL_ERIVLT_MASK)
#define ENET_MAC_VLAN_TAG_CTRL_EDVLP_MASK 0x4000000u
#define ENET_MAC_VLAN_TAG_CTRL_EDVLP_SHIFT 26u
#define ENET_MAC_VLAN_TAG_CTRL_EDVLP_WIDTH 1u
#define ENET_MAC_VLAN_TAG_CTRL_EDVLP(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_VLAN_TAG_CTRL_EDVLP_SHIFT))&ENET_MAC_VLAN_TAG_CTRL_EDVLP_MASK)
#define ENET_MAC_VLAN_TAG_CTRL_VTHM_MASK 0x2000000u
#define ENET_MAC_VLAN_TAG_CTRL_VTHM_SHIFT 25u
#define ENET_MAC_VLAN_TAG_CTRL_VTHM_WIDTH 1u
#define ENET_MAC_VLAN_TAG_CTRL_VTHM(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_VLAN_TAG_CTRL_VTHM_SHIFT))&ENET_MAC_VLAN_TAG_CTRL_VTHM_MASK)
#define ENET_MAC_VLAN_TAG_CTRL_EVLRXS_MASK 0x1000000u
#define ENET_MAC_VLAN_TAG_CTRL_EVLRXS_SHIFT 24u
#define ENET_MAC_VLAN_TAG_CTRL_EVLRXS_WIDTH 1u
#define ENET_MAC_VLAN_TAG_CTRL_EVLRXS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_VLAN_TAG_CTRL_EVLRXS_SHIFT))&ENET_MAC_VLAN_TAG_CTRL_EVLRXS_MASK)
#define ENET_MAC_VLAN_TAG_CTRL_EVLS_MASK 0x600000u
#define ENET_MAC_VLAN_TAG_CTRL_EVLS_SHIFT 21u
#define ENET_MAC_VLAN_TAG_CTRL_EVLS_WIDTH 2u
#define ENET_MAC_VLAN_TAG_CTRL_EVLS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_VLAN_TAG_CTRL_EVLS_SHIFT))&ENET_MAC_VLAN_TAG_CTRL_EVLS_MASK)
#define ENET_MAC_VLAN_TAG_CTRL_DOVLTC_MASK 0x100000u
#define ENET_MAC_VLAN_TAG_CTRL_DOVLTC_SHIFT 20u
#define ENET_MAC_VLAN_TAG_CTRL_DOVLTC_WIDTH 1u
#define ENET_MAC_VLAN_TAG_CTRL_DOVLTC(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_VLAN_TAG_CTRL_DOVLTC_SHIFT))&ENET_MAC_VLAN_TAG_CTRL_DOVLTC_MASK)
#define ENET_MAC_VLAN_TAG_CTRL_ERSVLM_MASK 0x80000u
#define ENET_MAC_VLAN_TAG_CTRL_ERSVLM_SHIFT 19u
#define ENET_MAC_VLAN_TAG_CTRL_ERSVLM_WIDTH 1u
#define ENET_MAC_VLAN_TAG_CTRL_ERSVLM(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_VLAN_TAG_CTRL_ERSVLM_SHIFT))&ENET_MAC_VLAN_TAG_CTRL_ERSVLM_MASK)
#define ENET_MAC_VLAN_TAG_CTRL_ESVL_MASK 0x40000u
#define ENET_MAC_VLAN_TAG_CTRL_ESVL_SHIFT 18u
#define ENET_MAC_VLAN_TAG_CTRL_ESVL_WIDTH 1u
#define ENET_MAC_VLAN_TAG_CTRL_ESVL(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_VLAN_TAG_CTRL_ESVL_SHIFT))&ENET_MAC_VLAN_TAG_CTRL_ESVL_MASK)
#define ENET_MAC_VLAN_TAG_CTRL_VTIM_MASK 0x20000u
#define ENET_MAC_VLAN_TAG_CTRL_VTIM_SHIFT 17u
#define ENET_MAC_VLAN_TAG_CTRL_VTIM_WIDTH 1u
#define ENET_MAC_VLAN_TAG_CTRL_VTIM(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_VLAN_TAG_CTRL_VTIM_SHIFT))&ENET_MAC_VLAN_TAG_CTRL_VTIM_MASK)
#define ENET_MAC_VLAN_TAG_CTRL_ETV_MASK 0x10000u
#define ENET_MAC_VLAN_TAG_CTRL_ETV_SHIFT 16u
#define ENET_MAC_VLAN_TAG_CTRL_ETV_WIDTH 1u
#define ENET_MAC_VLAN_TAG_CTRL_ETV(x)  (((uint32_t)(((uint32_t)(x))<<ENET_MAC_VLAN_TAG_CTRL_ETV_SHIFT))&ENET_MAC_VLAN_TAG_CTRL_ETV_MASK)
#define ENET_MAC_VLAN_TAG_CTRL_OFS_MASK 0xCu
#define ENET_MAC_VLAN_TAG_CTRL_OFS_SHIFT 2u
#define ENET_MAC_VLAN_TAG_CTRL_OFS_WIDTH 2u
#define ENET_MAC_VLAN_TAG_CTRL_OFS(x)  (((uint32_t)(((uint32_t)(x))<<ENET_MAC_VLAN_TAG_CTRL_OFS_SHIFT))&ENET_MAC_VLAN_TAG_CTRL_OFS_MASK)
#define ENET_MAC_VLAN_TAG_CTRL_CT_MASK 0x2u
#define ENET_MAC_VLAN_TAG_CTRL_CT_SHIFT 1u
#define ENET_MAC_VLAN_TAG_CTRL_CT_WIDTH 1u
#define ENET_MAC_VLAN_TAG_CTRL_CT(x)   (((uint32_t)(((uint32_t)(x))<<ENET_MAC_VLAN_TAG_CTRL_CT_SHIFT))&ENET_MAC_VLAN_TAG_CTRL_CT_MASK)
#define ENET_MAC_VLAN_TAG_CTRL_OB_MASK 0x1u
#define ENET_MAC_VLAN_TAG_CTRL_OB_SHIFT 0u
#define ENET_MAC_VLAN_TAG_CTRL_OB_WIDTH 1u
#define ENET_MAC_VLAN_TAG_CTRL_OB(x)   (((uint32_t)(((uint32_t)(x))<<ENET_MAC_VLAN_TAG_CTRL_OB_SHIFT))&ENET_MAC_VLAN_TAG_CTRL_OB_MASK)
/* MAC_VLAN_TAG_CTRL Reg Mask */
#define ENET_MAC_VLAN_TAG_CTRL_MASK    0xBF7F000Fu

/* MAC_VLAN_TAG_DATA Bit Fields */
#define ENET_MAC_VLAN_TAG_DATA_DMACHN_MASK 0x2000000u
#define ENET_MAC_VLAN_TAG_DATA_DMACHN_SHIFT 25u
#define ENET_MAC_VLAN_TAG_DATA_DMACHN_WIDTH 1u
#define ENET_MAC_VLAN_TAG_DATA_DMACHN(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_VLAN_TAG_DATA_DMACHN_SHIFT))&ENET_MAC_VLAN_TAG_DATA_DMACHN_MASK)
#define ENET_MAC_VLAN_TAG_DATA_DMACHEN_MASK 0x1000000u
#define ENET_MAC_VLAN_TAG_DATA_DMACHEN_SHIFT 24u
#define ENET_MAC_VLAN_TAG_DATA_DMACHEN_WIDTH 1u
#define ENET_MAC_VLAN_TAG_DATA_DMACHEN(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_VLAN_TAG_DATA_DMACHEN_SHIFT))&ENET_MAC_VLAN_TAG_DATA_DMACHEN_MASK)
#define ENET_MAC_VLAN_TAG_DATA_ERIVLT_MASK 0x100000u
#define ENET_MAC_VLAN_TAG_DATA_ERIVLT_SHIFT 20u
#define ENET_MAC_VLAN_TAG_DATA_ERIVLT_WIDTH 1u
#define ENET_MAC_VLAN_TAG_DATA_ERIVLT(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_VLAN_TAG_DATA_ERIVLT_SHIFT))&ENET_MAC_VLAN_TAG_DATA_ERIVLT_MASK)
#define ENET_MAC_VLAN_TAG_DATA_ERSVLM_MASK 0x80000u
#define ENET_MAC_VLAN_TAG_DATA_ERSVLM_SHIFT 19u
#define ENET_MAC_VLAN_TAG_DATA_ERSVLM_WIDTH 1u
#define ENET_MAC_VLAN_TAG_DATA_ERSVLM(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_VLAN_TAG_DATA_ERSVLM_SHIFT))&ENET_MAC_VLAN_TAG_DATA_ERSVLM_MASK)
#define ENET_MAC_VLAN_TAG_DATA_DOVLTC_MASK 0x40000u
#define ENET_MAC_VLAN_TAG_DATA_DOVLTC_SHIFT 18u
#define ENET_MAC_VLAN_TAG_DATA_DOVLTC_WIDTH 1u
#define ENET_MAC_VLAN_TAG_DATA_DOVLTC(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_VLAN_TAG_DATA_DOVLTC_SHIFT))&ENET_MAC_VLAN_TAG_DATA_DOVLTC_MASK)
#define ENET_MAC_VLAN_TAG_DATA_ETV_MASK 0x20000u
#define ENET_MAC_VLAN_TAG_DATA_ETV_SHIFT 17u
#define ENET_MAC_VLAN_TAG_DATA_ETV_WIDTH 1u
#define ENET_MAC_VLAN_TAG_DATA_ETV(x)  (((uint32_t)(((uint32_t)(x))<<ENET_MAC_VLAN_TAG_DATA_ETV_SHIFT))&ENET_MAC_VLAN_TAG_DATA_ETV_MASK)
#define ENET_MAC_VLAN_TAG_DATA_VEN_MASK 0x10000u
#define ENET_MAC_VLAN_TAG_DATA_VEN_SHIFT 16u
#define ENET_MAC_VLAN_TAG_DATA_VEN_WIDTH 1u
#define ENET_MAC_VLAN_TAG_DATA_VEN(x)  (((uint32_t)(((uint32_t)(x))<<ENET_MAC_VLAN_TAG_DATA_VEN_SHIFT))&ENET_MAC_VLAN_TAG_DATA_VEN_MASK)
#define ENET_MAC_VLAN_TAG_DATA_VID_MASK 0xFFFFu
#define ENET_MAC_VLAN_TAG_DATA_VID_SHIFT 0u
#define ENET_MAC_VLAN_TAG_DATA_VID_WIDTH 16u
#define ENET_MAC_VLAN_TAG_DATA_VID(x)  (((uint32_t)(((uint32_t)(x))<<ENET_MAC_VLAN_TAG_DATA_VID_SHIFT))&ENET_MAC_VLAN_TAG_DATA_VID_MASK)
/* MAC_VLAN_TAG_DATA Reg Mask */
#define ENET_MAC_VLAN_TAG_DATA_MASK    0x031FFFFFu

/* MAC_VLAN_HASH_TABLE Bit Fields */
#define ENET_MAC_VLAN_HASH_TABLE_VLHT_MASK 0xFFFFu
#define ENET_MAC_VLAN_HASH_TABLE_VLHT_SHIFT 0u
#define ENET_MAC_VLAN_HASH_TABLE_VLHT_WIDTH 16u
#define ENET_MAC_VLAN_HASH_TABLE_VLHT(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_VLAN_HASH_TABLE_VLHT_SHIFT))&ENET_MAC_VLAN_HASH_TABLE_VLHT_MASK)
/* MAC_VLAN_HASH_TABLE Reg Mask */
#define ENET_MAC_VLAN_HASH_TABLE_MASK  0x0000FFFFu

/* MAC_VLAN_INCL Bit Fields */
#define ENET_MAC_VLAN_INCL_BUSY_MASK   0x80000000u
#define ENET_MAC_VLAN_INCL_BUSY_SHIFT  31u
#define ENET_MAC_VLAN_INCL_BUSY_WIDTH  1u
#define ENET_MAC_VLAN_INCL_BUSY(x)     (((uint32_t)(((uint32_t)(x))<<ENET_MAC_VLAN_INCL_BUSY_SHIFT))&ENET_MAC_VLAN_INCL_BUSY_MASK)
#define ENET_MAC_VLAN_INCL_RDWR_MASK   0x40000000u
#define ENET_MAC_VLAN_INCL_RDWR_SHIFT  30u
#define ENET_MAC_VLAN_INCL_RDWR_WIDTH  1u
#define ENET_MAC_VLAN_INCL_RDWR(x)     (((uint32_t)(((uint32_t)(x))<<ENET_MAC_VLAN_INCL_RDWR_SHIFT))&ENET_MAC_VLAN_INCL_RDWR_MASK)
#define ENET_MAC_VLAN_INCL_ADDR_MASK   0x1000000u
#define ENET_MAC_VLAN_INCL_ADDR_SHIFT  24u
#define ENET_MAC_VLAN_INCL_ADDR_WIDTH  1u
#define ENET_MAC_VLAN_INCL_ADDR(x)     (((uint32_t)(((uint32_t)(x))<<ENET_MAC_VLAN_INCL_ADDR_SHIFT))&ENET_MAC_VLAN_INCL_ADDR_MASK)
#define ENET_MAC_VLAN_INCL_CBTI_MASK   0x200000u
#define ENET_MAC_VLAN_INCL_CBTI_SHIFT  21u
#define ENET_MAC_VLAN_INCL_CBTI_WIDTH  1u
#define ENET_MAC_VLAN_INCL_CBTI(x)     (((uint32_t)(((uint32_t)(x))<<ENET_MAC_VLAN_INCL_CBTI_SHIFT))&ENET_MAC_VLAN_INCL_CBTI_MASK)
#define ENET_MAC_VLAN_INCL_VLTI_MASK   0x100000u
#define ENET_MAC_VLAN_INCL_VLTI_SHIFT  20u
#define ENET_MAC_VLAN_INCL_VLTI_WIDTH  1u
#define ENET_MAC_VLAN_INCL_VLTI(x)     (((uint32_t)(((uint32_t)(x))<<ENET_MAC_VLAN_INCL_VLTI_SHIFT))&ENET_MAC_VLAN_INCL_VLTI_MASK)
#define ENET_MAC_VLAN_INCL_CSVL_MASK   0x80000u
#define ENET_MAC_VLAN_INCL_CSVL_SHIFT  19u
#define ENET_MAC_VLAN_INCL_CSVL_WIDTH  1u
#define ENET_MAC_VLAN_INCL_CSVL(x)     (((uint32_t)(((uint32_t)(x))<<ENET_MAC_VLAN_INCL_CSVL_SHIFT))&ENET_MAC_VLAN_INCL_CSVL_MASK)
#define ENET_MAC_VLAN_INCL_VLP_MASK    0x40000u
#define ENET_MAC_VLAN_INCL_VLP_SHIFT   18u
#define ENET_MAC_VLAN_INCL_VLP_WIDTH   1u
#define ENET_MAC_VLAN_INCL_VLP(x)      (((uint32_t)(((uint32_t)(x))<<ENET_MAC_VLAN_INCL_VLP_SHIFT))&ENET_MAC_VLAN_INCL_VLP_MASK)
#define ENET_MAC_VLAN_INCL_VLC_MASK    0x30000u
#define ENET_MAC_VLAN_INCL_VLC_SHIFT   16u
#define ENET_MAC_VLAN_INCL_VLC_WIDTH   2u
#define ENET_MAC_VLAN_INCL_VLC(x)      (((uint32_t)(((uint32_t)(x))<<ENET_MAC_VLAN_INCL_VLC_SHIFT))&ENET_MAC_VLAN_INCL_VLC_MASK)
#define ENET_MAC_VLAN_INCL_VLT_MASK    0xFFFFu
#define ENET_MAC_VLAN_INCL_VLT_SHIFT   0u
#define ENET_MAC_VLAN_INCL_VLT_WIDTH   16u
#define ENET_MAC_VLAN_INCL_VLT(x)      (((uint32_t)(((uint32_t)(x))<<ENET_MAC_VLAN_INCL_VLT_SHIFT))&ENET_MAC_VLAN_INCL_VLT_MASK)
/* MAC_VLAN_INCL Reg Mask */
#define ENET_MAC_VLAN_INCL_MASK        0xC13FFFFFu

/* MAC_INNER_VLAN_INCL Bit Fields */
#define ENET_MAC_INNER_VLAN_INCL_VLTI_MASK 0x100000u
#define ENET_MAC_INNER_VLAN_INCL_VLTI_SHIFT 20u
#define ENET_MAC_INNER_VLAN_INCL_VLTI_WIDTH 1u
#define ENET_MAC_INNER_VLAN_INCL_VLTI(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_INNER_VLAN_INCL_VLTI_SHIFT))&ENET_MAC_INNER_VLAN_INCL_VLTI_MASK)
#define ENET_MAC_INNER_VLAN_INCL_CSVL_MASK 0x80000u
#define ENET_MAC_INNER_VLAN_INCL_CSVL_SHIFT 19u
#define ENET_MAC_INNER_VLAN_INCL_CSVL_WIDTH 1u
#define ENET_MAC_INNER_VLAN_INCL_CSVL(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_INNER_VLAN_INCL_CSVL_SHIFT))&ENET_MAC_INNER_VLAN_INCL_CSVL_MASK)
#define ENET_MAC_INNER_VLAN_INCL_VLP_MASK 0x40000u
#define ENET_MAC_INNER_VLAN_INCL_VLP_SHIFT 18u
#define ENET_MAC_INNER_VLAN_INCL_VLP_WIDTH 1u
#define ENET_MAC_INNER_VLAN_INCL_VLP(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_INNER_VLAN_INCL_VLP_SHIFT))&ENET_MAC_INNER_VLAN_INCL_VLP_MASK)
#define ENET_MAC_INNER_VLAN_INCL_VLC_MASK 0x30000u
#define ENET_MAC_INNER_VLAN_INCL_VLC_SHIFT 16u
#define ENET_MAC_INNER_VLAN_INCL_VLC_WIDTH 2u
#define ENET_MAC_INNER_VLAN_INCL_VLC(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_INNER_VLAN_INCL_VLC_SHIFT))&ENET_MAC_INNER_VLAN_INCL_VLC_MASK)
#define ENET_MAC_INNER_VLAN_INCL_VLT_MASK 0xFFFFu
#define ENET_MAC_INNER_VLAN_INCL_VLT_SHIFT 0u
#define ENET_MAC_INNER_VLAN_INCL_VLT_WIDTH 16u
#define ENET_MAC_INNER_VLAN_INCL_VLT(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_INNER_VLAN_INCL_VLT_SHIFT))&ENET_MAC_INNER_VLAN_INCL_VLT_MASK)
/* MAC_INNER_VLAN_INCL Reg Mask */
#define ENET_MAC_INNER_VLAN_INCL_MASK  0x001FFFFFu

/* MAC_Qn_TX_FLOW_CTRL Bit Fields */
#define ENET_MAC_Qn_TX_FLOW_CTRL_PT_MASK 0xFFFF0000u
#define ENET_MAC_Qn_TX_FLOW_CTRL_PT_SHIFT 16u
#define ENET_MAC_Qn_TX_FLOW_CTRL_PT_WIDTH 16u
#define ENET_MAC_Qn_TX_FLOW_CTRL_PT(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_Qn_TX_FLOW_CTRL_PT_SHIFT))&ENET_MAC_Qn_TX_FLOW_CTRL_PT_MASK)
#define ENET_MAC_Qn_TX_FLOW_CTRL_DZPQ_MASK 0x80u
#define ENET_MAC_Qn_TX_FLOW_CTRL_DZPQ_SHIFT 7u
#define ENET_MAC_Qn_TX_FLOW_CTRL_DZPQ_WIDTH 1u
#define ENET_MAC_Qn_TX_FLOW_CTRL_DZPQ(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_Qn_TX_FLOW_CTRL_DZPQ_SHIFT))&ENET_MAC_Qn_TX_FLOW_CTRL_DZPQ_MASK)
#define ENET_MAC_Qn_TX_FLOW_CTRL_PLT_MASK 0x70u
#define ENET_MAC_Qn_TX_FLOW_CTRL_PLT_SHIFT 4u
#define ENET_MAC_Qn_TX_FLOW_CTRL_PLT_WIDTH 3u
#define ENET_MAC_Qn_TX_FLOW_CTRL_PLT(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_Qn_TX_FLOW_CTRL_PLT_SHIFT))&ENET_MAC_Qn_TX_FLOW_CTRL_PLT_MASK)
#define ENET_MAC_Qn_TX_FLOW_CTRL_TFE_MASK 0x2u
#define ENET_MAC_Qn_TX_FLOW_CTRL_TFE_SHIFT 1u
#define ENET_MAC_Qn_TX_FLOW_CTRL_TFE_WIDTH 1u
#define ENET_MAC_Qn_TX_FLOW_CTRL_TFE(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_Qn_TX_FLOW_CTRL_TFE_SHIFT))&ENET_MAC_Qn_TX_FLOW_CTRL_TFE_MASK)
#define ENET_MAC_Qn_TX_FLOW_CTRL_FCB_BPA_MASK 0x1u
#define ENET_MAC_Qn_TX_FLOW_CTRL_FCB_BPA_SHIFT 0u
#define ENET_MAC_Qn_TX_FLOW_CTRL_FCB_BPA_WIDTH 1u
#define ENET_MAC_Qn_TX_FLOW_CTRL_FCB_BPA(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_Qn_TX_FLOW_CTRL_FCB_BPA_SHIFT))&ENET_MAC_Qn_TX_FLOW_CTRL_FCB_BPA_MASK)
/* MAC_Q1_TX_FLOW_CTRL Reg Mask */
#define ENET_MAC_Qn_TX_FLOW_CTRL_MASK  0xFFFF00F3u

/* MAC_RX_FLOW_CTRL Bit Fields */
#define ENET_MAC_RX_FLOW_CTRL_UP_MASK  0x2u
#define ENET_MAC_RX_FLOW_CTRL_UP_SHIFT 1u
#define ENET_MAC_RX_FLOW_CTRL_UP_WIDTH 1u
#define ENET_MAC_RX_FLOW_CTRL_UP(x)    (((uint32_t)(((uint32_t)(x))<<ENET_MAC_RX_FLOW_CTRL_UP_SHIFT))&ENET_MAC_RX_FLOW_CTRL_UP_MASK)
#define ENET_MAC_RX_FLOW_CTRL_RFE_MASK 0x1u
#define ENET_MAC_RX_FLOW_CTRL_RFE_SHIFT 0u
#define ENET_MAC_RX_FLOW_CTRL_RFE_WIDTH 1u
#define ENET_MAC_RX_FLOW_CTRL_RFE(x)   (((uint32_t)(((uint32_t)(x))<<ENET_MAC_RX_FLOW_CTRL_RFE_SHIFT))&ENET_MAC_RX_FLOW_CTRL_RFE_MASK)
/* MAC_RX_FLOW_CTRL Reg Mask */
#define ENET_MAC_RX_FLOW_CTRL_MASK     0x00000003u

/* MAC_RXQ_CTRL4 Bit Fields */
#define ENET_MAC_RXQ_CTRL4_VFFQ_MASK   0x20000u
#define ENET_MAC_RXQ_CTRL4_VFFQ_SHIFT  17u
#define ENET_MAC_RXQ_CTRL4_VFFQ_WIDTH  1u
#define ENET_MAC_RXQ_CTRL4_VFFQ(x)     (((uint32_t)(((uint32_t)(x))<<ENET_MAC_RXQ_CTRL4_VFFQ_SHIFT))&ENET_MAC_RXQ_CTRL4_VFFQ_MASK)
#define ENET_MAC_RXQ_CTRL4_VFFQE_MASK  0x10000u
#define ENET_MAC_RXQ_CTRL4_VFFQE_SHIFT 16u
#define ENET_MAC_RXQ_CTRL4_VFFQE_WIDTH 1u
#define ENET_MAC_RXQ_CTRL4_VFFQE(x)    (((uint32_t)(((uint32_t)(x))<<ENET_MAC_RXQ_CTRL4_VFFQE_SHIFT))&ENET_MAC_RXQ_CTRL4_VFFQE_MASK)
#define ENET_MAC_RXQ_CTRL4_MFFQ_MASK   0x200u
#define ENET_MAC_RXQ_CTRL4_MFFQ_SHIFT  9u
#define ENET_MAC_RXQ_CTRL4_MFFQ_WIDTH  1u
#define ENET_MAC_RXQ_CTRL4_MFFQ(x)     (((uint32_t)(((uint32_t)(x))<<ENET_MAC_RXQ_CTRL4_MFFQ_SHIFT))&ENET_MAC_RXQ_CTRL4_MFFQ_MASK)
#define ENET_MAC_RXQ_CTRL4_MFFQE_MASK  0x100u
#define ENET_MAC_RXQ_CTRL4_MFFQE_SHIFT 8u
#define ENET_MAC_RXQ_CTRL4_MFFQE_WIDTH 1u
#define ENET_MAC_RXQ_CTRL4_MFFQE(x)    (((uint32_t)(((uint32_t)(x))<<ENET_MAC_RXQ_CTRL4_MFFQE_SHIFT))&ENET_MAC_RXQ_CTRL4_MFFQE_MASK)
#define ENET_MAC_RXQ_CTRL4_UFFQ_MASK   0x2u
#define ENET_MAC_RXQ_CTRL4_UFFQ_SHIFT  1u
#define ENET_MAC_RXQ_CTRL4_UFFQ_WIDTH  1u
#define ENET_MAC_RXQ_CTRL4_UFFQ(x)     (((uint32_t)(((uint32_t)(x))<<ENET_MAC_RXQ_CTRL4_UFFQ_SHIFT))&ENET_MAC_RXQ_CTRL4_UFFQ_MASK)
#define ENET_MAC_RXQ_CTRL4_UFFQE_MASK  0x1u
#define ENET_MAC_RXQ_CTRL4_UFFQE_SHIFT 0u
#define ENET_MAC_RXQ_CTRL4_UFFQE_WIDTH 1u
#define ENET_MAC_RXQ_CTRL4_UFFQE(x)    (((uint32_t)(((uint32_t)(x))<<ENET_MAC_RXQ_CTRL4_UFFQE_SHIFT))&ENET_MAC_RXQ_CTRL4_UFFQE_MASK)
/* MAC_RXQ_CTRL4 Reg Mask */
#define ENET_MAC_RXQ_CTRL4_MASK        0x00030303u

/* MAC_TXQ_PRTY_MAP0 Bit Fields */
#define ENET_MAC_TXQ_PRTY_MAP0_PSTQ1_MASK 0xFF00u
#define ENET_MAC_TXQ_PRTY_MAP0_PSTQ1_SHIFT 8u
#define ENET_MAC_TXQ_PRTY_MAP0_PSTQ1_WIDTH 8u
#define ENET_MAC_TXQ_PRTY_MAP0_PSTQ1(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_TXQ_PRTY_MAP0_PSTQ1_SHIFT))&ENET_MAC_TXQ_PRTY_MAP0_PSTQ1_MASK)
#define ENET_MAC_TXQ_PRTY_MAP0_PSTQ0_MASK 0xFFu
#define ENET_MAC_TXQ_PRTY_MAP0_PSTQ0_SHIFT 0u
#define ENET_MAC_TXQ_PRTY_MAP0_PSTQ0_WIDTH 8u
#define ENET_MAC_TXQ_PRTY_MAP0_PSTQ0(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_TXQ_PRTY_MAP0_PSTQ0_SHIFT))&ENET_MAC_TXQ_PRTY_MAP0_PSTQ0_MASK)
/* MAC_TXQ_PRTY_MAP0 Reg Mask */
#define ENET_MAC_TXQ_PRTY_MAP0_MASK    0x0000FFFFu

/* MAC_TXQ_PRTY_MAP1 Bit Fields */
/* MAC_TXQ_PRTY_MAP1 Reg Mask */
#define ENET_MAC_TXQ_PRTY_MAP1_MASK    0x00000000u

/* MAC_RXQ_CTRL0 Bit Fields */
#define ENET_MAC_RXQ_CTRL0_RXQ1EN_MASK 0xCu
#define ENET_MAC_RXQ_CTRL0_RXQ1EN_SHIFT 2u
#define ENET_MAC_RXQ_CTRL0_RXQ1EN_WIDTH 2u
#define ENET_MAC_RXQ_CTRL0_RXQ1EN(x)   (((uint32_t)(((uint32_t)(x))<<ENET_MAC_RXQ_CTRL0_RXQ1EN_SHIFT))&ENET_MAC_RXQ_CTRL0_RXQ1EN_MASK)
#define ENET_MAC_RXQ_CTRL0_RXQ0EN_MASK 0x3u
#define ENET_MAC_RXQ_CTRL0_RXQ0EN_SHIFT 0u
#define ENET_MAC_RXQ_CTRL0_RXQ0EN_WIDTH 2u
#define ENET_MAC_RXQ_CTRL0_RXQ0EN(x)   (((uint32_t)(((uint32_t)(x))<<ENET_MAC_RXQ_CTRL0_RXQ0EN_SHIFT))&ENET_MAC_RXQ_CTRL0_RXQ0EN_MASK)
/* MAC_RXQ_CTRL0 Reg Mask */
#define ENET_MAC_RXQ_CTRL0_MASK        0x0000000Fu

/* MAC_RXQ_CTRL1 Bit Fields */
#define ENET_MAC_RXQ_CTRL1_TBRQE_MASK  0x20000000u
#define ENET_MAC_RXQ_CTRL1_TBRQE_SHIFT 29u
#define ENET_MAC_RXQ_CTRL1_TBRQE_WIDTH 1u
#define ENET_MAC_RXQ_CTRL1_TBRQE(x)    (((uint32_t)(((uint32_t)(x))<<ENET_MAC_RXQ_CTRL1_TBRQE_SHIFT))&ENET_MAC_RXQ_CTRL1_TBRQE_MASK)
#define ENET_MAC_RXQ_CTRL1_OMCBCQ_MASK 0x10000000u
#define ENET_MAC_RXQ_CTRL1_OMCBCQ_SHIFT 28u
#define ENET_MAC_RXQ_CTRL1_OMCBCQ_WIDTH 1u
#define ENET_MAC_RXQ_CTRL1_OMCBCQ(x)   (((uint32_t)(((uint32_t)(x))<<ENET_MAC_RXQ_CTRL1_OMCBCQ_SHIFT))&ENET_MAC_RXQ_CTRL1_OMCBCQ_MASK)
#define ENET_MAC_RXQ_CTRL1_FPRQ_MASK   0x7000000u
#define ENET_MAC_RXQ_CTRL1_FPRQ_SHIFT  24u
#define ENET_MAC_RXQ_CTRL1_FPRQ_WIDTH  3u
#define ENET_MAC_RXQ_CTRL1_FPRQ(x)     (((uint32_t)(((uint32_t)(x))<<ENET_MAC_RXQ_CTRL1_FPRQ_SHIFT))&ENET_MAC_RXQ_CTRL1_FPRQ_MASK)
#define ENET_MAC_RXQ_CTRL1_TPQC_MASK   0xC00000u
#define ENET_MAC_RXQ_CTRL1_TPQC_SHIFT  22u
#define ENET_MAC_RXQ_CTRL1_TPQC_WIDTH  2u
#define ENET_MAC_RXQ_CTRL1_TPQC(x)     (((uint32_t)(((uint32_t)(x))<<ENET_MAC_RXQ_CTRL1_TPQC_SHIFT))&ENET_MAC_RXQ_CTRL1_TPQC_MASK)
#define ENET_MAC_RXQ_CTRL1_TACPQE_MASK 0x200000u
#define ENET_MAC_RXQ_CTRL1_TACPQE_SHIFT 21u
#define ENET_MAC_RXQ_CTRL1_TACPQE_WIDTH 1u
#define ENET_MAC_RXQ_CTRL1_TACPQE(x)   (((uint32_t)(((uint32_t)(x))<<ENET_MAC_RXQ_CTRL1_TACPQE_SHIFT))&ENET_MAC_RXQ_CTRL1_TACPQE_MASK)
#define ENET_MAC_RXQ_CTRL1_MCBCQEN_MASK 0x100000u
#define ENET_MAC_RXQ_CTRL1_MCBCQEN_SHIFT 20u
#define ENET_MAC_RXQ_CTRL1_MCBCQEN_WIDTH 1u
#define ENET_MAC_RXQ_CTRL1_MCBCQEN(x)  (((uint32_t)(((uint32_t)(x))<<ENET_MAC_RXQ_CTRL1_MCBCQEN_SHIFT))&ENET_MAC_RXQ_CTRL1_MCBCQEN_MASK)
#define ENET_MAC_RXQ_CTRL1_MCBCQ_MASK  0x70000u
#define ENET_MAC_RXQ_CTRL1_MCBCQ_SHIFT 16u
#define ENET_MAC_RXQ_CTRL1_MCBCQ_WIDTH 3u
#define ENET_MAC_RXQ_CTRL1_MCBCQ(x)    (((uint32_t)(((uint32_t)(x))<<ENET_MAC_RXQ_CTRL1_MCBCQ_SHIFT))&ENET_MAC_RXQ_CTRL1_MCBCQ_MASK)
#define ENET_MAC_RXQ_CTRL1_UPQ_MASK    0x7000u
#define ENET_MAC_RXQ_CTRL1_UPQ_SHIFT   12u
#define ENET_MAC_RXQ_CTRL1_UPQ_WIDTH   3u
#define ENET_MAC_RXQ_CTRL1_UPQ(x)      (((uint32_t)(((uint32_t)(x))<<ENET_MAC_RXQ_CTRL1_UPQ_SHIFT))&ENET_MAC_RXQ_CTRL1_UPQ_MASK)
#define ENET_MAC_RXQ_CTRL1_PTPQ_MASK   0x70u
#define ENET_MAC_RXQ_CTRL1_PTPQ_SHIFT  4u
#define ENET_MAC_RXQ_CTRL1_PTPQ_WIDTH  3u
#define ENET_MAC_RXQ_CTRL1_PTPQ(x)     (((uint32_t)(((uint32_t)(x))<<ENET_MAC_RXQ_CTRL1_PTPQ_SHIFT))&ENET_MAC_RXQ_CTRL1_PTPQ_MASK)
#define ENET_MAC_RXQ_CTRL1_AVCPQ_MASK  0x7u
#define ENET_MAC_RXQ_CTRL1_AVCPQ_SHIFT 0u
#define ENET_MAC_RXQ_CTRL1_AVCPQ_WIDTH 3u
#define ENET_MAC_RXQ_CTRL1_AVCPQ(x)    (((uint32_t)(((uint32_t)(x))<<ENET_MAC_RXQ_CTRL1_AVCPQ_SHIFT))&ENET_MAC_RXQ_CTRL1_AVCPQ_MASK)
/* MAC_RXQ_CTRL1 Reg Mask */
#define ENET_MAC_RXQ_CTRL1_MASK        0x37F77077u

/* MAC_RXQ_CTRL2 Bit Fields */
#define ENET_MAC_RXQ_CTRL2_PSRQ1_MASK  0xFF00u
#define ENET_MAC_RXQ_CTRL2_PSRQ1_SHIFT 8u
#define ENET_MAC_RXQ_CTRL2_PSRQ1_WIDTH 8u
#define ENET_MAC_RXQ_CTRL2_PSRQ1(x)    (((uint32_t)(((uint32_t)(x))<<ENET_MAC_RXQ_CTRL2_PSRQ1_SHIFT))&ENET_MAC_RXQ_CTRL2_PSRQ1_MASK)
#define ENET_MAC_RXQ_CTRL2_PSRQ0_MASK  0xFFu
#define ENET_MAC_RXQ_CTRL2_PSRQ0_SHIFT 0u
#define ENET_MAC_RXQ_CTRL2_PSRQ0_WIDTH 8u
#define ENET_MAC_RXQ_CTRL2_PSRQ0(x)    (((uint32_t)(((uint32_t)(x))<<ENET_MAC_RXQ_CTRL2_PSRQ0_SHIFT))&ENET_MAC_RXQ_CTRL2_PSRQ0_MASK)
/* MAC_RXQ_CTRL2 Reg Mask */
#define ENET_MAC_RXQ_CTRL2_MASK        0x0000FFFFu

/* MAC_RXQ_CTRL3 Bit Fields */
/* MAC_RXQ_CTRL3 Reg Mask */
#define ENET_MAC_RXQ_CTRL3_MASK        0x00000000u

/* MAC_INTERRUPT_STATUS Bit Fields */
#define ENET_MAC_INTERRUPT_STATUS_MFRIS_MASK 0x100000u
#define ENET_MAC_INTERRUPT_STATUS_MFRIS_SHIFT 20u
#define ENET_MAC_INTERRUPT_STATUS_MFRIS_WIDTH 1u
#define ENET_MAC_INTERRUPT_STATUS_MFRIS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_INTERRUPT_STATUS_MFRIS_SHIFT))&ENET_MAC_INTERRUPT_STATUS_MFRIS_MASK)
#define ENET_MAC_INTERRUPT_STATUS_MFTIS_MASK 0x80000u
#define ENET_MAC_INTERRUPT_STATUS_MFTIS_SHIFT 19u
#define ENET_MAC_INTERRUPT_STATUS_MFTIS_WIDTH 1u
#define ENET_MAC_INTERRUPT_STATUS_MFTIS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_INTERRUPT_STATUS_MFTIS_SHIFT))&ENET_MAC_INTERRUPT_STATUS_MFTIS_MASK)
#define ENET_MAC_INTERRUPT_STATUS_MDIOIS_MASK 0x40000u
#define ENET_MAC_INTERRUPT_STATUS_MDIOIS_SHIFT 18u
#define ENET_MAC_INTERRUPT_STATUS_MDIOIS_WIDTH 1u
#define ENET_MAC_INTERRUPT_STATUS_MDIOIS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_INTERRUPT_STATUS_MDIOIS_SHIFT))&ENET_MAC_INTERRUPT_STATUS_MDIOIS_MASK)
#define ENET_MAC_INTERRUPT_STATUS_FPEIS_MASK 0x20000u
#define ENET_MAC_INTERRUPT_STATUS_FPEIS_SHIFT 17u
#define ENET_MAC_INTERRUPT_STATUS_FPEIS_WIDTH 1u
#define ENET_MAC_INTERRUPT_STATUS_FPEIS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_INTERRUPT_STATUS_FPEIS_SHIFT))&ENET_MAC_INTERRUPT_STATUS_FPEIS_MASK)
#define ENET_MAC_INTERRUPT_STATUS_RXSTSIS_MASK 0x4000u
#define ENET_MAC_INTERRUPT_STATUS_RXSTSIS_SHIFT 14u
#define ENET_MAC_INTERRUPT_STATUS_RXSTSIS_WIDTH 1u
#define ENET_MAC_INTERRUPT_STATUS_RXSTSIS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_INTERRUPT_STATUS_RXSTSIS_SHIFT))&ENET_MAC_INTERRUPT_STATUS_RXSTSIS_MASK)
#define ENET_MAC_INTERRUPT_STATUS_TXSTSIS_MASK 0x2000u
#define ENET_MAC_INTERRUPT_STATUS_TXSTSIS_SHIFT 13u
#define ENET_MAC_INTERRUPT_STATUS_TXSTSIS_WIDTH 1u
#define ENET_MAC_INTERRUPT_STATUS_TXSTSIS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_INTERRUPT_STATUS_TXSTSIS_SHIFT))&ENET_MAC_INTERRUPT_STATUS_TXSTSIS_MASK)
#define ENET_MAC_INTERRUPT_STATUS_TSIS_MASK 0x1000u
#define ENET_MAC_INTERRUPT_STATUS_TSIS_SHIFT 12u
#define ENET_MAC_INTERRUPT_STATUS_TSIS_WIDTH 1u
#define ENET_MAC_INTERRUPT_STATUS_TSIS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_INTERRUPT_STATUS_TSIS_SHIFT))&ENET_MAC_INTERRUPT_STATUS_TSIS_MASK)
#define ENET_MAC_INTERRUPT_STATUS_MMCTXIS_MASK 0x400u
#define ENET_MAC_INTERRUPT_STATUS_MMCTXIS_SHIFT 10u
#define ENET_MAC_INTERRUPT_STATUS_MMCTXIS_WIDTH 1u
#define ENET_MAC_INTERRUPT_STATUS_MMCTXIS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_INTERRUPT_STATUS_MMCTXIS_SHIFT))&ENET_MAC_INTERRUPT_STATUS_MMCTXIS_MASK)
#define ENET_MAC_INTERRUPT_STATUS_MMCRXIS_MASK 0x200u
#define ENET_MAC_INTERRUPT_STATUS_MMCRXIS_SHIFT 9u
#define ENET_MAC_INTERRUPT_STATUS_MMCRXIS_WIDTH 1u
#define ENET_MAC_INTERRUPT_STATUS_MMCRXIS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_INTERRUPT_STATUS_MMCRXIS_SHIFT))&ENET_MAC_INTERRUPT_STATUS_MMCRXIS_MASK)
#define ENET_MAC_INTERRUPT_STATUS_MMCIS_MASK 0x100u
#define ENET_MAC_INTERRUPT_STATUS_MMCIS_SHIFT 8u
#define ENET_MAC_INTERRUPT_STATUS_MMCIS_WIDTH 1u
#define ENET_MAC_INTERRUPT_STATUS_MMCIS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_INTERRUPT_STATUS_MMCIS_SHIFT))&ENET_MAC_INTERRUPT_STATUS_MMCIS_MASK)
#define ENET_MAC_INTERRUPT_STATUS_PHYIS_MASK 0x8u
#define ENET_MAC_INTERRUPT_STATUS_PHYIS_SHIFT 3u
#define ENET_MAC_INTERRUPT_STATUS_PHYIS_WIDTH 1u
#define ENET_MAC_INTERRUPT_STATUS_PHYIS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_INTERRUPT_STATUS_PHYIS_SHIFT))&ENET_MAC_INTERRUPT_STATUS_PHYIS_MASK)
#define ENET_MAC_INTERRUPT_STATUS_RGSMIIIS_MASK 0x1u
#define ENET_MAC_INTERRUPT_STATUS_RGSMIIIS_SHIFT 0u
#define ENET_MAC_INTERRUPT_STATUS_RGSMIIIS_WIDTH 1u
#define ENET_MAC_INTERRUPT_STATUS_RGSMIIIS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_INTERRUPT_STATUS_RGSMIIIS_SHIFT))&ENET_MAC_INTERRUPT_STATUS_RGSMIIIS_MASK)
/* MAC_INTERRUPT_STATUS Reg Mask */
#define ENET_MAC_INTERRUPT_STATUS_MASK 0x001E7709u

/* MAC_INTERRUPT_ENABLE Bit Fields */
#define ENET_MAC_INTERRUPT_ENABLE_MDIOIE_MASK 0x40000u
#define ENET_MAC_INTERRUPT_ENABLE_MDIOIE_SHIFT 18u
#define ENET_MAC_INTERRUPT_ENABLE_MDIOIE_WIDTH 1u
#define ENET_MAC_INTERRUPT_ENABLE_MDIOIE(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_INTERRUPT_ENABLE_MDIOIE_SHIFT))&ENET_MAC_INTERRUPT_ENABLE_MDIOIE_MASK)
#define ENET_MAC_INTERRUPT_ENABLE_FPEIE_MASK 0x20000u
#define ENET_MAC_INTERRUPT_ENABLE_FPEIE_SHIFT 17u
#define ENET_MAC_INTERRUPT_ENABLE_FPEIE_WIDTH 1u
#define ENET_MAC_INTERRUPT_ENABLE_FPEIE(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_INTERRUPT_ENABLE_FPEIE_SHIFT))&ENET_MAC_INTERRUPT_ENABLE_FPEIE_MASK)
#define ENET_MAC_INTERRUPT_ENABLE_RXSTSIE_MASK 0x4000u
#define ENET_MAC_INTERRUPT_ENABLE_RXSTSIE_SHIFT 14u
#define ENET_MAC_INTERRUPT_ENABLE_RXSTSIE_WIDTH 1u
#define ENET_MAC_INTERRUPT_ENABLE_RXSTSIE(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_INTERRUPT_ENABLE_RXSTSIE_SHIFT))&ENET_MAC_INTERRUPT_ENABLE_RXSTSIE_MASK)
#define ENET_MAC_INTERRUPT_ENABLE_TXSTSIE_MASK 0x2000u
#define ENET_MAC_INTERRUPT_ENABLE_TXSTSIE_SHIFT 13u
#define ENET_MAC_INTERRUPT_ENABLE_TXSTSIE_WIDTH 1u
#define ENET_MAC_INTERRUPT_ENABLE_TXSTSIE(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_INTERRUPT_ENABLE_TXSTSIE_SHIFT))&ENET_MAC_INTERRUPT_ENABLE_TXSTSIE_MASK)
#define ENET_MAC_INTERRUPT_ENABLE_TSIE_MASK 0x1000u
#define ENET_MAC_INTERRUPT_ENABLE_TSIE_SHIFT 12u
#define ENET_MAC_INTERRUPT_ENABLE_TSIE_WIDTH 1u
#define ENET_MAC_INTERRUPT_ENABLE_TSIE(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_INTERRUPT_ENABLE_TSIE_SHIFT))&ENET_MAC_INTERRUPT_ENABLE_TSIE_MASK)
#define ENET_MAC_INTERRUPT_ENABLE_PHYIE_MASK 0x8u
#define ENET_MAC_INTERRUPT_ENABLE_PHYIE_SHIFT 3u
#define ENET_MAC_INTERRUPT_ENABLE_PHYIE_WIDTH 1u
#define ENET_MAC_INTERRUPT_ENABLE_PHYIE(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_INTERRUPT_ENABLE_PHYIE_SHIFT))&ENET_MAC_INTERRUPT_ENABLE_PHYIE_MASK)
#define ENET_MAC_INTERRUPT_ENABLE_RGSMIIIE_MASK 0x1u
#define ENET_MAC_INTERRUPT_ENABLE_RGSMIIIE_SHIFT 0u
#define ENET_MAC_INTERRUPT_ENABLE_RGSMIIIE_WIDTH 1u
#define ENET_MAC_INTERRUPT_ENABLE_RGSMIIIE(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_INTERRUPT_ENABLE_RGSMIIIE_SHIFT))&ENET_MAC_INTERRUPT_ENABLE_RGSMIIIE_MASK)
/* MAC_INTERRUPT_ENABLE Reg Mask */
#define ENET_MAC_INTERRUPT_ENABLE_MASK 0x00067009u

/* MAC_RX_TX_STATUS Bit Fields */
#define ENET_MAC_RX_TX_STATUS_RWT_MASK 0x100u
#define ENET_MAC_RX_TX_STATUS_RWT_SHIFT 8u
#define ENET_MAC_RX_TX_STATUS_RWT_WIDTH 1u
#define ENET_MAC_RX_TX_STATUS_RWT(x)   (((uint32_t)(((uint32_t)(x))<<ENET_MAC_RX_TX_STATUS_RWT_SHIFT))&ENET_MAC_RX_TX_STATUS_RWT_MASK)
#define ENET_MAC_RX_TX_STATUS_EXCOL_MASK 0x20u
#define ENET_MAC_RX_TX_STATUS_EXCOL_SHIFT 5u
#define ENET_MAC_RX_TX_STATUS_EXCOL_WIDTH 1u
#define ENET_MAC_RX_TX_STATUS_EXCOL(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_RX_TX_STATUS_EXCOL_SHIFT))&ENET_MAC_RX_TX_STATUS_EXCOL_MASK)
#define ENET_MAC_RX_TX_STATUS_LCOL_MASK 0x10u
#define ENET_MAC_RX_TX_STATUS_LCOL_SHIFT 4u
#define ENET_MAC_RX_TX_STATUS_LCOL_WIDTH 1u
#define ENET_MAC_RX_TX_STATUS_LCOL(x)  (((uint32_t)(((uint32_t)(x))<<ENET_MAC_RX_TX_STATUS_LCOL_SHIFT))&ENET_MAC_RX_TX_STATUS_LCOL_MASK)
#define ENET_MAC_RX_TX_STATUS_EXDEF_MASK 0x8u
#define ENET_MAC_RX_TX_STATUS_EXDEF_SHIFT 3u
#define ENET_MAC_RX_TX_STATUS_EXDEF_WIDTH 1u
#define ENET_MAC_RX_TX_STATUS_EXDEF(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_RX_TX_STATUS_EXDEF_SHIFT))&ENET_MAC_RX_TX_STATUS_EXDEF_MASK)
#define ENET_MAC_RX_TX_STATUS_LCARR_MASK 0x4u
#define ENET_MAC_RX_TX_STATUS_LCARR_SHIFT 2u
#define ENET_MAC_RX_TX_STATUS_LCARR_WIDTH 1u
#define ENET_MAC_RX_TX_STATUS_LCARR(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_RX_TX_STATUS_LCARR_SHIFT))&ENET_MAC_RX_TX_STATUS_LCARR_MASK)
#define ENET_MAC_RX_TX_STATUS_NCARR_MASK 0x2u
#define ENET_MAC_RX_TX_STATUS_NCARR_SHIFT 1u
#define ENET_MAC_RX_TX_STATUS_NCARR_WIDTH 1u
#define ENET_MAC_RX_TX_STATUS_NCARR(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_RX_TX_STATUS_NCARR_SHIFT))&ENET_MAC_RX_TX_STATUS_NCARR_MASK)
#define ENET_MAC_RX_TX_STATUS_TJT_MASK 0x1u
#define ENET_MAC_RX_TX_STATUS_TJT_SHIFT 0u
#define ENET_MAC_RX_TX_STATUS_TJT_WIDTH 1u
#define ENET_MAC_RX_TX_STATUS_TJT(x)   (((uint32_t)(((uint32_t)(x))<<ENET_MAC_RX_TX_STATUS_TJT_SHIFT))&ENET_MAC_RX_TX_STATUS_TJT_MASK)
/* MAC_RX_TX_STATUS Reg Mask */
#define ENET_MAC_RX_TX_STATUS_MASK     0x0000013Fu

/* MAC_PHYIF_CONTROL_STATUS Bit Fields */
#define ENET_MAC_PHYIF_CONTROL_STATUS_LNKSTS_MASK 0x80000u
#define ENET_MAC_PHYIF_CONTROL_STATUS_LNKSTS_SHIFT 19u
#define ENET_MAC_PHYIF_CONTROL_STATUS_LNKSTS_WIDTH 1u
#define ENET_MAC_PHYIF_CONTROL_STATUS_LNKSTS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_PHYIF_CONTROL_STATUS_LNKSTS_SHIFT))&ENET_MAC_PHYIF_CONTROL_STATUS_LNKSTS_MASK)
#define ENET_MAC_PHYIF_CONTROL_STATUS_LNKSPEED_MASK 0x60000u
#define ENET_MAC_PHYIF_CONTROL_STATUS_LNKSPEED_SHIFT 17u
#define ENET_MAC_PHYIF_CONTROL_STATUS_LNKSPEED_WIDTH 2u
#define ENET_MAC_PHYIF_CONTROL_STATUS_LNKSPEED(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_PHYIF_CONTROL_STATUS_LNKSPEED_SHIFT))&ENET_MAC_PHYIF_CONTROL_STATUS_LNKSPEED_MASK)
#define ENET_MAC_PHYIF_CONTROL_STATUS_LNKMOD_MASK 0x10000u
#define ENET_MAC_PHYIF_CONTROL_STATUS_LNKMOD_SHIFT 16u
#define ENET_MAC_PHYIF_CONTROL_STATUS_LNKMOD_WIDTH 1u
#define ENET_MAC_PHYIF_CONTROL_STATUS_LNKMOD(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_PHYIF_CONTROL_STATUS_LNKMOD_SHIFT))&ENET_MAC_PHYIF_CONTROL_STATUS_LNKMOD_MASK)
#define ENET_MAC_PHYIF_CONTROL_STATUS_SMIDRXS_MASK 0x10u
#define ENET_MAC_PHYIF_CONTROL_STATUS_SMIDRXS_SHIFT 4u
#define ENET_MAC_PHYIF_CONTROL_STATUS_SMIDRXS_WIDTH 1u
#define ENET_MAC_PHYIF_CONTROL_STATUS_SMIDRXS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_PHYIF_CONTROL_STATUS_SMIDRXS_SHIFT))&ENET_MAC_PHYIF_CONTROL_STATUS_SMIDRXS_MASK)
#define ENET_MAC_PHYIF_CONTROL_STATUS_LUD_MASK 0x2u
#define ENET_MAC_PHYIF_CONTROL_STATUS_LUD_SHIFT 1u
#define ENET_MAC_PHYIF_CONTROL_STATUS_LUD_WIDTH 1u
#define ENET_MAC_PHYIF_CONTROL_STATUS_LUD(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_PHYIF_CONTROL_STATUS_LUD_SHIFT))&ENET_MAC_PHYIF_CONTROL_STATUS_LUD_MASK)
#define ENET_MAC_PHYIF_CONTROL_STATUS_TC_MASK 0x1u
#define ENET_MAC_PHYIF_CONTROL_STATUS_TC_SHIFT 0u
#define ENET_MAC_PHYIF_CONTROL_STATUS_TC_WIDTH 1u
#define ENET_MAC_PHYIF_CONTROL_STATUS_TC(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_PHYIF_CONTROL_STATUS_TC_SHIFT))&ENET_MAC_PHYIF_CONTROL_STATUS_TC_MASK)
/* MAC_PHYIF_CONTROL_STATUS Reg Mask */
#define ENET_MAC_PHYIF_CONTROL_STATUS_MASK 0x000F0013u

/* MAC_VERSION Bit Fields */
#define ENET_MAC_VERSION_USERVER_MASK  0xFF00u
#define ENET_MAC_VERSION_USERVER_SHIFT 8u
#define ENET_MAC_VERSION_USERVER_WIDTH 8u
#define ENET_MAC_VERSION_USERVER(x)    (((uint32_t)(((uint32_t)(x))<<ENET_MAC_VERSION_USERVER_SHIFT))&ENET_MAC_VERSION_USERVER_MASK)
#define ENET_MAC_VERSION_SNPSVER_MASK  0xFFu
#define ENET_MAC_VERSION_SNPSVER_SHIFT 0u
#define ENET_MAC_VERSION_SNPSVER_WIDTH 8u
#define ENET_MAC_VERSION_SNPSVER(x)    (((uint32_t)(((uint32_t)(x))<<ENET_MAC_VERSION_SNPSVER_SHIFT))&ENET_MAC_VERSION_SNPSVER_MASK)
/* MAC_VERSION Reg Mask */
#define ENET_MAC_VERSION_MASK          0x0000FFFFu

/* MAC_DEBUG Bit Fields */
#define ENET_MAC_DEBUG_TFCSTS_MASK     0x60000u
#define ENET_MAC_DEBUG_TFCSTS_SHIFT    17u
#define ENET_MAC_DEBUG_TFCSTS_WIDTH    2u
#define ENET_MAC_DEBUG_TFCSTS(x)       (((uint32_t)(((uint32_t)(x))<<ENET_MAC_DEBUG_TFCSTS_SHIFT))&ENET_MAC_DEBUG_TFCSTS_MASK)
#define ENET_MAC_DEBUG_TPESTS_MASK     0x10000u
#define ENET_MAC_DEBUG_TPESTS_SHIFT    16u
#define ENET_MAC_DEBUG_TPESTS_WIDTH    1u
#define ENET_MAC_DEBUG_TPESTS(x)       (((uint32_t)(((uint32_t)(x))<<ENET_MAC_DEBUG_TPESTS_SHIFT))&ENET_MAC_DEBUG_TPESTS_MASK)
#define ENET_MAC_DEBUG_RFCFCSTS_MASK   0x6u
#define ENET_MAC_DEBUG_RFCFCSTS_SHIFT  1u
#define ENET_MAC_DEBUG_RFCFCSTS_WIDTH  2u
#define ENET_MAC_DEBUG_RFCFCSTS(x)     (((uint32_t)(((uint32_t)(x))<<ENET_MAC_DEBUG_RFCFCSTS_SHIFT))&ENET_MAC_DEBUG_RFCFCSTS_MASK)
#define ENET_MAC_DEBUG_RPESTS_MASK     0x1u
#define ENET_MAC_DEBUG_RPESTS_SHIFT    0u
#define ENET_MAC_DEBUG_RPESTS_WIDTH    1u
#define ENET_MAC_DEBUG_RPESTS(x)       (((uint32_t)(((uint32_t)(x))<<ENET_MAC_DEBUG_RPESTS_SHIFT))&ENET_MAC_DEBUG_RPESTS_MASK)
/* MAC_DEBUG Reg Mask */
#define ENET_MAC_DEBUG_MASK            0x00070007u

/* MAC_HW_FEATURE0 Bit Fields */
#define ENET_MAC_HW_FEATURE0_ACTPHYSEL_MASK 0x70000000u
#define ENET_MAC_HW_FEATURE0_ACTPHYSEL_SHIFT 28u
#define ENET_MAC_HW_FEATURE0_ACTPHYSEL_WIDTH 3u
#define ENET_MAC_HW_FEATURE0_ACTPHYSEL(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_HW_FEATURE0_ACTPHYSEL_SHIFT))&ENET_MAC_HW_FEATURE0_ACTPHYSEL_MASK)
#define ENET_MAC_HW_FEATURE0_SAVLANINS_MASK 0x8000000u
#define ENET_MAC_HW_FEATURE0_SAVLANINS_SHIFT 27u
#define ENET_MAC_HW_FEATURE0_SAVLANINS_WIDTH 1u
#define ENET_MAC_HW_FEATURE0_SAVLANINS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_HW_FEATURE0_SAVLANINS_SHIFT))&ENET_MAC_HW_FEATURE0_SAVLANINS_MASK)
#define ENET_MAC_HW_FEATURE0_TSSTSSEL_MASK 0x6000000u
#define ENET_MAC_HW_FEATURE0_TSSTSSEL_SHIFT 25u
#define ENET_MAC_HW_FEATURE0_TSSTSSEL_WIDTH 2u
#define ENET_MAC_HW_FEATURE0_TSSTSSEL(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_HW_FEATURE0_TSSTSSEL_SHIFT))&ENET_MAC_HW_FEATURE0_TSSTSSEL_MASK)
#define ENET_MAC_HW_FEATURE0_MACADR64SEL_MASK 0x1000000u
#define ENET_MAC_HW_FEATURE0_MACADR64SEL_SHIFT 24u
#define ENET_MAC_HW_FEATURE0_MACADR64SEL_WIDTH 1u
#define ENET_MAC_HW_FEATURE0_MACADR64SEL(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_HW_FEATURE0_MACADR64SEL_SHIFT))&ENET_MAC_HW_FEATURE0_MACADR64SEL_MASK)
#define ENET_MAC_HW_FEATURE0_MACADR32SEL_MASK 0x800000u
#define ENET_MAC_HW_FEATURE0_MACADR32SEL_SHIFT 23u
#define ENET_MAC_HW_FEATURE0_MACADR32SEL_WIDTH 1u
#define ENET_MAC_HW_FEATURE0_MACADR32SEL(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_HW_FEATURE0_MACADR32SEL_SHIFT))&ENET_MAC_HW_FEATURE0_MACADR32SEL_MASK)
#define ENET_MAC_HW_FEATURE0_ADDMACADRSEL_MASK 0x7C0000u
#define ENET_MAC_HW_FEATURE0_ADDMACADRSEL_SHIFT 18u
#define ENET_MAC_HW_FEATURE0_ADDMACADRSEL_WIDTH 5u
#define ENET_MAC_HW_FEATURE0_ADDMACADRSEL(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_HW_FEATURE0_ADDMACADRSEL_SHIFT))&ENET_MAC_HW_FEATURE0_ADDMACADRSEL_MASK)
#define ENET_MAC_HW_FEATURE0_RXCOESEL_MASK 0x10000u
#define ENET_MAC_HW_FEATURE0_RXCOESEL_SHIFT 16u
#define ENET_MAC_HW_FEATURE0_RXCOESEL_WIDTH 1u
#define ENET_MAC_HW_FEATURE0_RXCOESEL(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_HW_FEATURE0_RXCOESEL_SHIFT))&ENET_MAC_HW_FEATURE0_RXCOESEL_MASK)
#define ENET_MAC_HW_FEATURE0_TXCOESEL_MASK 0x4000u
#define ENET_MAC_HW_FEATURE0_TXCOESEL_SHIFT 14u
#define ENET_MAC_HW_FEATURE0_TXCOESEL_WIDTH 1u
#define ENET_MAC_HW_FEATURE0_TXCOESEL(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_HW_FEATURE0_TXCOESEL_SHIFT))&ENET_MAC_HW_FEATURE0_TXCOESEL_MASK)
#define ENET_MAC_HW_FEATURE0_EEESEL_MASK 0x2000u
#define ENET_MAC_HW_FEATURE0_EEESEL_SHIFT 13u
#define ENET_MAC_HW_FEATURE0_EEESEL_WIDTH 1u
#define ENET_MAC_HW_FEATURE0_EEESEL(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_HW_FEATURE0_EEESEL_SHIFT))&ENET_MAC_HW_FEATURE0_EEESEL_MASK)
#define ENET_MAC_HW_FEATURE0_TSSEL_MASK 0x1000u
#define ENET_MAC_HW_FEATURE0_TSSEL_SHIFT 12u
#define ENET_MAC_HW_FEATURE0_TSSEL_WIDTH 1u
#define ENET_MAC_HW_FEATURE0_TSSEL(x)  (((uint32_t)(((uint32_t)(x))<<ENET_MAC_HW_FEATURE0_TSSEL_SHIFT))&ENET_MAC_HW_FEATURE0_TSSEL_MASK)
#define ENET_MAC_HW_FEATURE0_ARPOFFSEL_MASK 0x200u
#define ENET_MAC_HW_FEATURE0_ARPOFFSEL_SHIFT 9u
#define ENET_MAC_HW_FEATURE0_ARPOFFSEL_WIDTH 1u
#define ENET_MAC_HW_FEATURE0_ARPOFFSEL(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_HW_FEATURE0_ARPOFFSEL_SHIFT))&ENET_MAC_HW_FEATURE0_ARPOFFSEL_MASK)
#define ENET_MAC_HW_FEATURE0_MMCSEL_MASK 0x100u
#define ENET_MAC_HW_FEATURE0_MMCSEL_SHIFT 8u
#define ENET_MAC_HW_FEATURE0_MMCSEL_WIDTH 1u
#define ENET_MAC_HW_FEATURE0_MMCSEL(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_HW_FEATURE0_MMCSEL_SHIFT))&ENET_MAC_HW_FEATURE0_MMCSEL_MASK)
#define ENET_MAC_HW_FEATURE0_MGKSEL_MASK 0x80u
#define ENET_MAC_HW_FEATURE0_MGKSEL_SHIFT 7u
#define ENET_MAC_HW_FEATURE0_MGKSEL_WIDTH 1u
#define ENET_MAC_HW_FEATURE0_MGKSEL(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_HW_FEATURE0_MGKSEL_SHIFT))&ENET_MAC_HW_FEATURE0_MGKSEL_MASK)
#define ENET_MAC_HW_FEATURE0_RWKSEL_MASK 0x40u
#define ENET_MAC_HW_FEATURE0_RWKSEL_SHIFT 6u
#define ENET_MAC_HW_FEATURE0_RWKSEL_WIDTH 1u
#define ENET_MAC_HW_FEATURE0_RWKSEL(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_HW_FEATURE0_RWKSEL_SHIFT))&ENET_MAC_HW_FEATURE0_RWKSEL_MASK)
#define ENET_MAC_HW_FEATURE0_SMASEL_MASK 0x20u
#define ENET_MAC_HW_FEATURE0_SMASEL_SHIFT 5u
#define ENET_MAC_HW_FEATURE0_SMASEL_WIDTH 1u
#define ENET_MAC_HW_FEATURE0_SMASEL(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_HW_FEATURE0_SMASEL_SHIFT))&ENET_MAC_HW_FEATURE0_SMASEL_MASK)
#define ENET_MAC_HW_FEATURE0_VLHASH_MASK 0x10u
#define ENET_MAC_HW_FEATURE0_VLHASH_SHIFT 4u
#define ENET_MAC_HW_FEATURE0_VLHASH_WIDTH 1u
#define ENET_MAC_HW_FEATURE0_VLHASH(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_HW_FEATURE0_VLHASH_SHIFT))&ENET_MAC_HW_FEATURE0_VLHASH_MASK)
#define ENET_MAC_HW_FEATURE0_PCSSEL_MASK 0x8u
#define ENET_MAC_HW_FEATURE0_PCSSEL_SHIFT 3u
#define ENET_MAC_HW_FEATURE0_PCSSEL_WIDTH 1u
#define ENET_MAC_HW_FEATURE0_PCSSEL(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_HW_FEATURE0_PCSSEL_SHIFT))&ENET_MAC_HW_FEATURE0_PCSSEL_MASK)
#define ENET_MAC_HW_FEATURE0_HDSEL_MASK 0x4u
#define ENET_MAC_HW_FEATURE0_HDSEL_SHIFT 2u
#define ENET_MAC_HW_FEATURE0_HDSEL_WIDTH 1u
#define ENET_MAC_HW_FEATURE0_HDSEL(x)  (((uint32_t)(((uint32_t)(x))<<ENET_MAC_HW_FEATURE0_HDSEL_SHIFT))&ENET_MAC_HW_FEATURE0_HDSEL_MASK)
#define ENET_MAC_HW_FEATURE0_GMIISEL_MASK 0x2u
#define ENET_MAC_HW_FEATURE0_GMIISEL_SHIFT 1u
#define ENET_MAC_HW_FEATURE0_GMIISEL_WIDTH 1u
#define ENET_MAC_HW_FEATURE0_GMIISEL(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_HW_FEATURE0_GMIISEL_SHIFT))&ENET_MAC_HW_FEATURE0_GMIISEL_MASK)
#define ENET_MAC_HW_FEATURE0_MIISEL_MASK 0x1u
#define ENET_MAC_HW_FEATURE0_MIISEL_SHIFT 0u
#define ENET_MAC_HW_FEATURE0_MIISEL_WIDTH 1u
#define ENET_MAC_HW_FEATURE0_MIISEL(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_HW_FEATURE0_MIISEL_SHIFT))&ENET_MAC_HW_FEATURE0_MIISEL_MASK)
/* MAC_HW_FEATURE0 Reg Mask */
#define ENET_MAC_HW_FEATURE0_MASK      0x7FFD73FFu

/* MAC_HW_FEATURE1 Bit Fields */
#define ENET_MAC_HW_FEATURE1_L3L4FNUM_MASK 0x78000000u
#define ENET_MAC_HW_FEATURE1_L3L4FNUM_SHIFT 27u
#define ENET_MAC_HW_FEATURE1_L3L4FNUM_WIDTH 4u
#define ENET_MAC_HW_FEATURE1_L3L4FNUM(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_HW_FEATURE1_L3L4FNUM_SHIFT))&ENET_MAC_HW_FEATURE1_L3L4FNUM_MASK)
#define ENET_MAC_HW_FEATURE1_HASHTBLSZ_MASK 0x3000000u
#define ENET_MAC_HW_FEATURE1_HASHTBLSZ_SHIFT 24u
#define ENET_MAC_HW_FEATURE1_HASHTBLSZ_WIDTH 2u
#define ENET_MAC_HW_FEATURE1_HASHTBLSZ(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_HW_FEATURE1_HASHTBLSZ_SHIFT))&ENET_MAC_HW_FEATURE1_HASHTBLSZ_MASK)
#define ENET_MAC_HW_FEATURE1_POUOST_MASK 0x800000u
#define ENET_MAC_HW_FEATURE1_POUOST_SHIFT 23u
#define ENET_MAC_HW_FEATURE1_POUOST_WIDTH 1u
#define ENET_MAC_HW_FEATURE1_POUOST(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_HW_FEATURE1_POUOST_SHIFT))&ENET_MAC_HW_FEATURE1_POUOST_MASK)
#define ENET_MAC_HW_FEATURE1_RAVSEL_MASK 0x200000u
#define ENET_MAC_HW_FEATURE1_RAVSEL_SHIFT 21u
#define ENET_MAC_HW_FEATURE1_RAVSEL_WIDTH 1u
#define ENET_MAC_HW_FEATURE1_RAVSEL(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_HW_FEATURE1_RAVSEL_SHIFT))&ENET_MAC_HW_FEATURE1_RAVSEL_MASK)
#define ENET_MAC_HW_FEATURE1_AVSEL_MASK 0x100000u
#define ENET_MAC_HW_FEATURE1_AVSEL_SHIFT 20u
#define ENET_MAC_HW_FEATURE1_AVSEL_WIDTH 1u
#define ENET_MAC_HW_FEATURE1_AVSEL(x)  (((uint32_t)(((uint32_t)(x))<<ENET_MAC_HW_FEATURE1_AVSEL_SHIFT))&ENET_MAC_HW_FEATURE1_AVSEL_MASK)
#define ENET_MAC_HW_FEATURE1_DBGMEMA_MASK 0x80000u
#define ENET_MAC_HW_FEATURE1_DBGMEMA_SHIFT 19u
#define ENET_MAC_HW_FEATURE1_DBGMEMA_WIDTH 1u
#define ENET_MAC_HW_FEATURE1_DBGMEMA(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_HW_FEATURE1_DBGMEMA_SHIFT))&ENET_MAC_HW_FEATURE1_DBGMEMA_MASK)
#define ENET_MAC_HW_FEATURE1_TSOEN_MASK 0x40000u
#define ENET_MAC_HW_FEATURE1_TSOEN_SHIFT 18u
#define ENET_MAC_HW_FEATURE1_TSOEN_WIDTH 1u
#define ENET_MAC_HW_FEATURE1_TSOEN(x)  (((uint32_t)(((uint32_t)(x))<<ENET_MAC_HW_FEATURE1_TSOEN_SHIFT))&ENET_MAC_HW_FEATURE1_TSOEN_MASK)
#define ENET_MAC_HW_FEATURE1_SPHEN_MASK 0x20000u
#define ENET_MAC_HW_FEATURE1_SPHEN_SHIFT 17u
#define ENET_MAC_HW_FEATURE1_SPHEN_WIDTH 1u
#define ENET_MAC_HW_FEATURE1_SPHEN(x)  (((uint32_t)(((uint32_t)(x))<<ENET_MAC_HW_FEATURE1_SPHEN_SHIFT))&ENET_MAC_HW_FEATURE1_SPHEN_MASK)
#define ENET_MAC_HW_FEATURE1_DCBEN_MASK 0x10000u
#define ENET_MAC_HW_FEATURE1_DCBEN_SHIFT 16u
#define ENET_MAC_HW_FEATURE1_DCBEN_WIDTH 1u
#define ENET_MAC_HW_FEATURE1_DCBEN(x)  (((uint32_t)(((uint32_t)(x))<<ENET_MAC_HW_FEATURE1_DCBEN_SHIFT))&ENET_MAC_HW_FEATURE1_DCBEN_MASK)
#define ENET_MAC_HW_FEATURE1_ADDR64_MASK 0xC000u
#define ENET_MAC_HW_FEATURE1_ADDR64_SHIFT 14u
#define ENET_MAC_HW_FEATURE1_ADDR64_WIDTH 2u
#define ENET_MAC_HW_FEATURE1_ADDR64(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_HW_FEATURE1_ADDR64_SHIFT))&ENET_MAC_HW_FEATURE1_ADDR64_MASK)
#define ENET_MAC_HW_FEATURE1_ADVTHWORD_MASK 0x2000u
#define ENET_MAC_HW_FEATURE1_ADVTHWORD_SHIFT 13u
#define ENET_MAC_HW_FEATURE1_ADVTHWORD_WIDTH 1u
#define ENET_MAC_HW_FEATURE1_ADVTHWORD(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_HW_FEATURE1_ADVTHWORD_SHIFT))&ENET_MAC_HW_FEATURE1_ADVTHWORD_MASK)
#define ENET_MAC_HW_FEATURE1_PTOEN_MASK 0x1000u
#define ENET_MAC_HW_FEATURE1_PTOEN_SHIFT 12u
#define ENET_MAC_HW_FEATURE1_PTOEN_WIDTH 1u
#define ENET_MAC_HW_FEATURE1_PTOEN(x)  (((uint32_t)(((uint32_t)(x))<<ENET_MAC_HW_FEATURE1_PTOEN_SHIFT))&ENET_MAC_HW_FEATURE1_PTOEN_MASK)
#define ENET_MAC_HW_FEATURE1_OSTEN_MASK 0x800u
#define ENET_MAC_HW_FEATURE1_OSTEN_SHIFT 11u
#define ENET_MAC_HW_FEATURE1_OSTEN_WIDTH 1u
#define ENET_MAC_HW_FEATURE1_OSTEN(x)  (((uint32_t)(((uint32_t)(x))<<ENET_MAC_HW_FEATURE1_OSTEN_SHIFT))&ENET_MAC_HW_FEATURE1_OSTEN_MASK)
#define ENET_MAC_HW_FEATURE1_TXFIFOSIZE_MASK 0x7C0u
#define ENET_MAC_HW_FEATURE1_TXFIFOSIZE_SHIFT 6u
#define ENET_MAC_HW_FEATURE1_TXFIFOSIZE_WIDTH 5u
#define ENET_MAC_HW_FEATURE1_TXFIFOSIZE(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_HW_FEATURE1_TXFIFOSIZE_SHIFT))&ENET_MAC_HW_FEATURE1_TXFIFOSIZE_MASK)
#define ENET_MAC_HW_FEATURE1_SPRAM_MASK 0x20u
#define ENET_MAC_HW_FEATURE1_SPRAM_SHIFT 5u
#define ENET_MAC_HW_FEATURE1_SPRAM_WIDTH 1u
#define ENET_MAC_HW_FEATURE1_SPRAM(x)  (((uint32_t)(((uint32_t)(x))<<ENET_MAC_HW_FEATURE1_SPRAM_SHIFT))&ENET_MAC_HW_FEATURE1_SPRAM_MASK)
#define ENET_MAC_HW_FEATURE1_RXFIFOSIZE_MASK 0x1Fu
#define ENET_MAC_HW_FEATURE1_RXFIFOSIZE_SHIFT 0u
#define ENET_MAC_HW_FEATURE1_RXFIFOSIZE_WIDTH 5u
#define ENET_MAC_HW_FEATURE1_RXFIFOSIZE(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_HW_FEATURE1_RXFIFOSIZE_SHIFT))&ENET_MAC_HW_FEATURE1_RXFIFOSIZE_MASK)
/* MAC_HW_FEATURE1 Reg Mask */
#define ENET_MAC_HW_FEATURE1_MASK      0x7BBFFFFFu

/* MAC_HW_FEATURE2 Bit Fields */
#define ENET_MAC_HW_FEATURE2_AUXSNAPNUM_MASK 0x70000000u
#define ENET_MAC_HW_FEATURE2_AUXSNAPNUM_SHIFT 28u
#define ENET_MAC_HW_FEATURE2_AUXSNAPNUM_WIDTH 3u
#define ENET_MAC_HW_FEATURE2_AUXSNAPNUM(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_HW_FEATURE2_AUXSNAPNUM_SHIFT))&ENET_MAC_HW_FEATURE2_AUXSNAPNUM_MASK)
#define ENET_MAC_HW_FEATURE2_PPSOUTNUM_MASK 0x7000000u
#define ENET_MAC_HW_FEATURE2_PPSOUTNUM_SHIFT 24u
#define ENET_MAC_HW_FEATURE2_PPSOUTNUM_WIDTH 3u
#define ENET_MAC_HW_FEATURE2_PPSOUTNUM(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_HW_FEATURE2_PPSOUTNUM_SHIFT))&ENET_MAC_HW_FEATURE2_PPSOUTNUM_MASK)
#define ENET_MAC_HW_FEATURE2_TDCSZ_MASK 0xC00000u
#define ENET_MAC_HW_FEATURE2_TDCSZ_SHIFT 22u
#define ENET_MAC_HW_FEATURE2_TDCSZ_WIDTH 2u
#define ENET_MAC_HW_FEATURE2_TDCSZ(x)  (((uint32_t)(((uint32_t)(x))<<ENET_MAC_HW_FEATURE2_TDCSZ_SHIFT))&ENET_MAC_HW_FEATURE2_TDCSZ_MASK)
#define ENET_MAC_HW_FEATURE2_TXCHCNT_MASK 0x3C0000u
#define ENET_MAC_HW_FEATURE2_TXCHCNT_SHIFT 18u
#define ENET_MAC_HW_FEATURE2_TXCHCNT_WIDTH 4u
#define ENET_MAC_HW_FEATURE2_TXCHCNT(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_HW_FEATURE2_TXCHCNT_SHIFT))&ENET_MAC_HW_FEATURE2_TXCHCNT_MASK)
#define ENET_MAC_HW_FEATURE2_RDCSZ_MASK 0x30000u
#define ENET_MAC_HW_FEATURE2_RDCSZ_SHIFT 16u
#define ENET_MAC_HW_FEATURE2_RDCSZ_WIDTH 2u
#define ENET_MAC_HW_FEATURE2_RDCSZ(x)  (((uint32_t)(((uint32_t)(x))<<ENET_MAC_HW_FEATURE2_RDCSZ_SHIFT))&ENET_MAC_HW_FEATURE2_RDCSZ_MASK)
#define ENET_MAC_HW_FEATURE2_RXCHCNT_MASK 0xF000u
#define ENET_MAC_HW_FEATURE2_RXCHCNT_SHIFT 12u
#define ENET_MAC_HW_FEATURE2_RXCHCNT_WIDTH 4u
#define ENET_MAC_HW_FEATURE2_RXCHCNT(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_HW_FEATURE2_RXCHCNT_SHIFT))&ENET_MAC_HW_FEATURE2_RXCHCNT_MASK)
#define ENET_MAC_HW_FEATURE2_TXQCNT_MASK 0x3C0u
#define ENET_MAC_HW_FEATURE2_TXQCNT_SHIFT 6u
#define ENET_MAC_HW_FEATURE2_TXQCNT_WIDTH 4u
#define ENET_MAC_HW_FEATURE2_TXQCNT(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_HW_FEATURE2_TXQCNT_SHIFT))&ENET_MAC_HW_FEATURE2_TXQCNT_MASK)
#define ENET_MAC_HW_FEATURE2_RXQCNT_MASK 0xFu
#define ENET_MAC_HW_FEATURE2_RXQCNT_SHIFT 0u
#define ENET_MAC_HW_FEATURE2_RXQCNT_WIDTH 4u
#define ENET_MAC_HW_FEATURE2_RXQCNT(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_HW_FEATURE2_RXQCNT_SHIFT))&ENET_MAC_HW_FEATURE2_RXQCNT_MASK)
/* MAC_HW_FEATURE2 Reg Mask */
#define ENET_MAC_HW_FEATURE2_MASK      0x77FFF3CFu

/* MAC_HW_FEATURE3 Bit Fields */
#define ENET_MAC_HW_FEATURE3_ASP_MASK  0x30000000u
#define ENET_MAC_HW_FEATURE3_ASP_SHIFT 28u
#define ENET_MAC_HW_FEATURE3_ASP_WIDTH 2u
#define ENET_MAC_HW_FEATURE3_ASP(x)    (((uint32_t)(((uint32_t)(x))<<ENET_MAC_HW_FEATURE3_ASP_SHIFT))&ENET_MAC_HW_FEATURE3_ASP_MASK)
#define ENET_MAC_HW_FEATURE3_TBSSEL_MASK 0x8000000u
#define ENET_MAC_HW_FEATURE3_TBSSEL_SHIFT 27u
#define ENET_MAC_HW_FEATURE3_TBSSEL_WIDTH 1u
#define ENET_MAC_HW_FEATURE3_TBSSEL(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_HW_FEATURE3_TBSSEL_SHIFT))&ENET_MAC_HW_FEATURE3_TBSSEL_MASK)
#define ENET_MAC_HW_FEATURE3_FPESEL_MASK 0x4000000u
#define ENET_MAC_HW_FEATURE3_FPESEL_SHIFT 26u
#define ENET_MAC_HW_FEATURE3_FPESEL_WIDTH 1u
#define ENET_MAC_HW_FEATURE3_FPESEL(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_HW_FEATURE3_FPESEL_SHIFT))&ENET_MAC_HW_FEATURE3_FPESEL_MASK)
#define ENET_MAC_HW_FEATURE3_ESTWID_MASK 0x300000u
#define ENET_MAC_HW_FEATURE3_ESTWID_SHIFT 20u
#define ENET_MAC_HW_FEATURE3_ESTWID_WIDTH 2u
#define ENET_MAC_HW_FEATURE3_ESTWID(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_HW_FEATURE3_ESTWID_SHIFT))&ENET_MAC_HW_FEATURE3_ESTWID_MASK)
#define ENET_MAC_HW_FEATURE3_ESTDEP_MASK 0xE0000u
#define ENET_MAC_HW_FEATURE3_ESTDEP_SHIFT 17u
#define ENET_MAC_HW_FEATURE3_ESTDEP_WIDTH 3u
#define ENET_MAC_HW_FEATURE3_ESTDEP(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_HW_FEATURE3_ESTDEP_SHIFT))&ENET_MAC_HW_FEATURE3_ESTDEP_MASK)
#define ENET_MAC_HW_FEATURE3_ESTSEL_MASK 0x10000u
#define ENET_MAC_HW_FEATURE3_ESTSEL_SHIFT 16u
#define ENET_MAC_HW_FEATURE3_ESTSEL_WIDTH 1u
#define ENET_MAC_HW_FEATURE3_ESTSEL(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_HW_FEATURE3_ESTSEL_SHIFT))&ENET_MAC_HW_FEATURE3_ESTSEL_MASK)
#define ENET_MAC_HW_FEATURE3_FRPES_MASK 0x6000u
#define ENET_MAC_HW_FEATURE3_FRPES_SHIFT 13u
#define ENET_MAC_HW_FEATURE3_FRPES_WIDTH 2u
#define ENET_MAC_HW_FEATURE3_FRPES(x)  (((uint32_t)(((uint32_t)(x))<<ENET_MAC_HW_FEATURE3_FRPES_SHIFT))&ENET_MAC_HW_FEATURE3_FRPES_MASK)
#define ENET_MAC_HW_FEATURE3_FRPBS_MASK 0x1800u
#define ENET_MAC_HW_FEATURE3_FRPBS_SHIFT 11u
#define ENET_MAC_HW_FEATURE3_FRPBS_WIDTH 2u
#define ENET_MAC_HW_FEATURE3_FRPBS(x)  (((uint32_t)(((uint32_t)(x))<<ENET_MAC_HW_FEATURE3_FRPBS_SHIFT))&ENET_MAC_HW_FEATURE3_FRPBS_MASK)
#define ENET_MAC_HW_FEATURE3_FRPSEL_MASK 0x400u
#define ENET_MAC_HW_FEATURE3_FRPSEL_SHIFT 10u
#define ENET_MAC_HW_FEATURE3_FRPSEL_WIDTH 1u
#define ENET_MAC_HW_FEATURE3_FRPSEL(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_HW_FEATURE3_FRPSEL_SHIFT))&ENET_MAC_HW_FEATURE3_FRPSEL_MASK)
#define ENET_MAC_HW_FEATURE3_PDUPSEL_MASK 0x200u
#define ENET_MAC_HW_FEATURE3_PDUPSEL_SHIFT 9u
#define ENET_MAC_HW_FEATURE3_PDUPSEL_WIDTH 1u
#define ENET_MAC_HW_FEATURE3_PDUPSEL(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_HW_FEATURE3_PDUPSEL_SHIFT))&ENET_MAC_HW_FEATURE3_PDUPSEL_MASK)
#define ENET_MAC_HW_FEATURE3_DVLAN_MASK 0x20u
#define ENET_MAC_HW_FEATURE3_DVLAN_SHIFT 5u
#define ENET_MAC_HW_FEATURE3_DVLAN_WIDTH 1u
#define ENET_MAC_HW_FEATURE3_DVLAN(x)  (((uint32_t)(((uint32_t)(x))<<ENET_MAC_HW_FEATURE3_DVLAN_SHIFT))&ENET_MAC_HW_FEATURE3_DVLAN_MASK)
#define ENET_MAC_HW_FEATURE3_CBTISEL_MASK 0x10u
#define ENET_MAC_HW_FEATURE3_CBTISEL_SHIFT 4u
#define ENET_MAC_HW_FEATURE3_CBTISEL_WIDTH 1u
#define ENET_MAC_HW_FEATURE3_CBTISEL(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_HW_FEATURE3_CBTISEL_SHIFT))&ENET_MAC_HW_FEATURE3_CBTISEL_MASK)
#define ENET_MAC_HW_FEATURE3_NRVF_MASK 0x7u
#define ENET_MAC_HW_FEATURE3_NRVF_SHIFT 0u
#define ENET_MAC_HW_FEATURE3_NRVF_WIDTH 3u
#define ENET_MAC_HW_FEATURE3_NRVF(x)   (((uint32_t)(((uint32_t)(x))<<ENET_MAC_HW_FEATURE3_NRVF_SHIFT))&ENET_MAC_HW_FEATURE3_NRVF_MASK)
/* MAC_HW_FEATURE3 Reg Mask */
#define ENET_MAC_HW_FEATURE3_MASK      0x3C3F7E37u

/* MAC_DPP_FSM_INTERRUPT_STATUS Bit Fields */
#define ENET_MAC_DPP_FSM_INTERRUPT_STATUS_MRWCPES_MASK 0x8000000u
#define ENET_MAC_DPP_FSM_INTERRUPT_STATUS_MRWCPES_SHIFT 27u
#define ENET_MAC_DPP_FSM_INTERRUPT_STATUS_MRWCPES_WIDTH 1u
#define ENET_MAC_DPP_FSM_INTERRUPT_STATUS_MRWCPES(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_DPP_FSM_INTERRUPT_STATUS_MRWCPES_SHIFT))&ENET_MAC_DPP_FSM_INTERRUPT_STATUS_MRWCPES_MASK)
#define ENET_MAC_DPP_FSM_INTERRUPT_STATUS_MTFCPES_MASK 0x4000000u
#define ENET_MAC_DPP_FSM_INTERRUPT_STATUS_MTFCPES_SHIFT 26u
#define ENET_MAC_DPP_FSM_INTERRUPT_STATUS_MTFCPES_WIDTH 1u
#define ENET_MAC_DPP_FSM_INTERRUPT_STATUS_MTFCPES(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_DPP_FSM_INTERRUPT_STATUS_MTFCPES_SHIFT))&ENET_MAC_DPP_FSM_INTERRUPT_STATUS_MTFCPES_MASK)
#define ENET_MAC_DPP_FSM_INTERRUPT_STATUS_MTBUPES_MASK 0x2000000u
#define ENET_MAC_DPP_FSM_INTERRUPT_STATUS_MTBUPES_SHIFT 25u
#define ENET_MAC_DPP_FSM_INTERRUPT_STATUS_MTBUPES_WIDTH 1u
#define ENET_MAC_DPP_FSM_INTERRUPT_STATUS_MTBUPES(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_DPP_FSM_INTERRUPT_STATUS_MTBUPES_SHIFT))&ENET_MAC_DPP_FSM_INTERRUPT_STATUS_MTBUPES_MASK)
#define ENET_MAC_DPP_FSM_INTERRUPT_STATUS_FSMPES_MASK 0x1000000u
#define ENET_MAC_DPP_FSM_INTERRUPT_STATUS_FSMPES_SHIFT 24u
#define ENET_MAC_DPP_FSM_INTERRUPT_STATUS_FSMPES_WIDTH 1u
#define ENET_MAC_DPP_FSM_INTERRUPT_STATUS_FSMPES(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_DPP_FSM_INTERRUPT_STATUS_FSMPES_SHIFT))&ENET_MAC_DPP_FSM_INTERRUPT_STATUS_FSMPES_MASK)
#define ENET_MAC_DPP_FSM_INTERRUPT_STATUS_MSTTES_MASK 0x10000u
#define ENET_MAC_DPP_FSM_INTERRUPT_STATUS_MSTTES_SHIFT 16u
#define ENET_MAC_DPP_FSM_INTERRUPT_STATUS_MSTTES_WIDTH 1u
#define ENET_MAC_DPP_FSM_INTERRUPT_STATUS_MSTTES(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_DPP_FSM_INTERRUPT_STATUS_MSTTES_SHIFT))&ENET_MAC_DPP_FSM_INTERRUPT_STATUS_MSTTES_MASK)
#define ENET_MAC_DPP_FSM_INTERRUPT_STATUS_PTES_MASK 0x1000u
#define ENET_MAC_DPP_FSM_INTERRUPT_STATUS_PTES_SHIFT 12u
#define ENET_MAC_DPP_FSM_INTERRUPT_STATUS_PTES_WIDTH 1u
#define ENET_MAC_DPP_FSM_INTERRUPT_STATUS_PTES(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_DPP_FSM_INTERRUPT_STATUS_PTES_SHIFT))&ENET_MAC_DPP_FSM_INTERRUPT_STATUS_PTES_MASK)
#define ENET_MAC_DPP_FSM_INTERRUPT_STATUS_ATES_MASK 0x800u
#define ENET_MAC_DPP_FSM_INTERRUPT_STATUS_ATES_SHIFT 11u
#define ENET_MAC_DPP_FSM_INTERRUPT_STATUS_ATES_WIDTH 1u
#define ENET_MAC_DPP_FSM_INTERRUPT_STATUS_ATES(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_DPP_FSM_INTERRUPT_STATUS_ATES_SHIFT))&ENET_MAC_DPP_FSM_INTERRUPT_STATUS_ATES_MASK)
#define ENET_MAC_DPP_FSM_INTERRUPT_STATUS_RTES_MASK 0x200u
#define ENET_MAC_DPP_FSM_INTERRUPT_STATUS_RTES_SHIFT 9u
#define ENET_MAC_DPP_FSM_INTERRUPT_STATUS_RTES_WIDTH 1u
#define ENET_MAC_DPP_FSM_INTERRUPT_STATUS_RTES(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_DPP_FSM_INTERRUPT_STATUS_RTES_SHIFT))&ENET_MAC_DPP_FSM_INTERRUPT_STATUS_RTES_MASK)
#define ENET_MAC_DPP_FSM_INTERRUPT_STATUS_TTES_MASK 0x100u
#define ENET_MAC_DPP_FSM_INTERRUPT_STATUS_TTES_SHIFT 8u
#define ENET_MAC_DPP_FSM_INTERRUPT_STATUS_TTES_WIDTH 1u
#define ENET_MAC_DPP_FSM_INTERRUPT_STATUS_TTES(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_DPP_FSM_INTERRUPT_STATUS_TTES_SHIFT))&ENET_MAC_DPP_FSM_INTERRUPT_STATUS_TTES_MASK)
#define ENET_MAC_DPP_FSM_INTERRUPT_STATUS_ARPES_MASK 0x20u
#define ENET_MAC_DPP_FSM_INTERRUPT_STATUS_ARPES_SHIFT 5u
#define ENET_MAC_DPP_FSM_INTERRUPT_STATUS_ARPES_WIDTH 1u
#define ENET_MAC_DPP_FSM_INTERRUPT_STATUS_ARPES(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_DPP_FSM_INTERRUPT_STATUS_ARPES_SHIFT))&ENET_MAC_DPP_FSM_INTERRUPT_STATUS_ARPES_MASK)
#define ENET_MAC_DPP_FSM_INTERRUPT_STATUS_MTSPES_MASK 0x10u
#define ENET_MAC_DPP_FSM_INTERRUPT_STATUS_MTSPES_SHIFT 4u
#define ENET_MAC_DPP_FSM_INTERRUPT_STATUS_MTSPES_WIDTH 1u
#define ENET_MAC_DPP_FSM_INTERRUPT_STATUS_MTSPES(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_DPP_FSM_INTERRUPT_STATUS_MTSPES_SHIFT))&ENET_MAC_DPP_FSM_INTERRUPT_STATUS_MTSPES_MASK)
#define ENET_MAC_DPP_FSM_INTERRUPT_STATUS_MPES_MASK 0x8u
#define ENET_MAC_DPP_FSM_INTERRUPT_STATUS_MPES_SHIFT 3u
#define ENET_MAC_DPP_FSM_INTERRUPT_STATUS_MPES_WIDTH 1u
#define ENET_MAC_DPP_FSM_INTERRUPT_STATUS_MPES(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_DPP_FSM_INTERRUPT_STATUS_MPES_SHIFT))&ENET_MAC_DPP_FSM_INTERRUPT_STATUS_MPES_MASK)
#define ENET_MAC_DPP_FSM_INTERRUPT_STATUS_RDPES_MASK 0x4u
#define ENET_MAC_DPP_FSM_INTERRUPT_STATUS_RDPES_SHIFT 2u
#define ENET_MAC_DPP_FSM_INTERRUPT_STATUS_RDPES_WIDTH 1u
#define ENET_MAC_DPP_FSM_INTERRUPT_STATUS_RDPES(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_DPP_FSM_INTERRUPT_STATUS_RDPES_SHIFT))&ENET_MAC_DPP_FSM_INTERRUPT_STATUS_RDPES_MASK)
/* MAC_DPP_FSM_INTERRUPT_STATUS Reg Mask */
#define ENET_MAC_DPP_FSM_INTERRUPT_STATUS_MASK 0x0F011B3Cu

/* MAC_FSM_CONTROL Bit Fields */
#define ENET_MAC_FSM_CONTROL_RVCLGRNML_MASK 0x80000000u
#define ENET_MAC_FSM_CONTROL_RVCLGRNML_SHIFT 31u
#define ENET_MAC_FSM_CONTROL_RVCLGRNML_WIDTH 1u
#define ENET_MAC_FSM_CONTROL_RVCLGRNML(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_FSM_CONTROL_RVCLGRNML_SHIFT))&ENET_MAC_FSM_CONTROL_RVCLGRNML_MASK)
#define ENET_MAC_FSM_CONTROL_PLGRNML_MASK 0x10000000u
#define ENET_MAC_FSM_CONTROL_PLGRNML_SHIFT 28u
#define ENET_MAC_FSM_CONTROL_PLGRNML_WIDTH 1u
#define ENET_MAC_FSM_CONTROL_PLGRNML(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_FSM_CONTROL_PLGRNML_SHIFT))&ENET_MAC_FSM_CONTROL_PLGRNML_MASK)
#define ENET_MAC_FSM_CONTROL_ALGRNML_MASK 0x8000000u
#define ENET_MAC_FSM_CONTROL_ALGRNML_SHIFT 27u
#define ENET_MAC_FSM_CONTROL_ALGRNML_WIDTH 1u
#define ENET_MAC_FSM_CONTROL_ALGRNML(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_FSM_CONTROL_ALGRNML_SHIFT))&ENET_MAC_FSM_CONTROL_ALGRNML_MASK)
#define ENET_MAC_FSM_CONTROL_RLGRNML_MASK 0x2000000u
#define ENET_MAC_FSM_CONTROL_RLGRNML_SHIFT 25u
#define ENET_MAC_FSM_CONTROL_RLGRNML_WIDTH 1u
#define ENET_MAC_FSM_CONTROL_RLGRNML(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_FSM_CONTROL_RLGRNML_SHIFT))&ENET_MAC_FSM_CONTROL_RLGRNML_MASK)
#define ENET_MAC_FSM_CONTROL_TLGRNML_MASK 0x1000000u
#define ENET_MAC_FSM_CONTROL_TLGRNML_SHIFT 24u
#define ENET_MAC_FSM_CONTROL_TLGRNML_WIDTH 1u
#define ENET_MAC_FSM_CONTROL_TLGRNML(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_FSM_CONTROL_TLGRNML_SHIFT))&ENET_MAC_FSM_CONTROL_TLGRNML_MASK)
#define ENET_MAC_FSM_CONTROL_RVCPEIN_MASK 0x800000u
#define ENET_MAC_FSM_CONTROL_RVCPEIN_SHIFT 23u
#define ENET_MAC_FSM_CONTROL_RVCPEIN_WIDTH 1u
#define ENET_MAC_FSM_CONTROL_RVCPEIN(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_FSM_CONTROL_RVCPEIN_SHIFT))&ENET_MAC_FSM_CONTROL_RVCPEIN_MASK)
#define ENET_MAC_FSM_CONTROL_PPEIN_MASK 0x100000u
#define ENET_MAC_FSM_CONTROL_PPEIN_SHIFT 20u
#define ENET_MAC_FSM_CONTROL_PPEIN_WIDTH 1u
#define ENET_MAC_FSM_CONTROL_PPEIN(x)  (((uint32_t)(((uint32_t)(x))<<ENET_MAC_FSM_CONTROL_PPEIN_SHIFT))&ENET_MAC_FSM_CONTROL_PPEIN_MASK)
#define ENET_MAC_FSM_CONTROL_APEIN_MASK 0x80000u
#define ENET_MAC_FSM_CONTROL_APEIN_SHIFT 19u
#define ENET_MAC_FSM_CONTROL_APEIN_WIDTH 1u
#define ENET_MAC_FSM_CONTROL_APEIN(x)  (((uint32_t)(((uint32_t)(x))<<ENET_MAC_FSM_CONTROL_APEIN_SHIFT))&ENET_MAC_FSM_CONTROL_APEIN_MASK)
#define ENET_MAC_FSM_CONTROL_RPEIN_MASK 0x20000u
#define ENET_MAC_FSM_CONTROL_RPEIN_SHIFT 17u
#define ENET_MAC_FSM_CONTROL_RPEIN_WIDTH 1u
#define ENET_MAC_FSM_CONTROL_RPEIN(x)  (((uint32_t)(((uint32_t)(x))<<ENET_MAC_FSM_CONTROL_RPEIN_SHIFT))&ENET_MAC_FSM_CONTROL_RPEIN_MASK)
#define ENET_MAC_FSM_CONTROL_TPEIN_MASK 0x10000u
#define ENET_MAC_FSM_CONTROL_TPEIN_SHIFT 16u
#define ENET_MAC_FSM_CONTROL_TPEIN_WIDTH 1u
#define ENET_MAC_FSM_CONTROL_TPEIN(x)  (((uint32_t)(((uint32_t)(x))<<ENET_MAC_FSM_CONTROL_TPEIN_SHIFT))&ENET_MAC_FSM_CONTROL_TPEIN_MASK)
#define ENET_MAC_FSM_CONTROL_RVCTEIN_MASK 0x8000u
#define ENET_MAC_FSM_CONTROL_RVCTEIN_SHIFT 15u
#define ENET_MAC_FSM_CONTROL_RVCTEIN_WIDTH 1u
#define ENET_MAC_FSM_CONTROL_RVCTEIN(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_FSM_CONTROL_RVCTEIN_SHIFT))&ENET_MAC_FSM_CONTROL_RVCTEIN_MASK)
#define ENET_MAC_FSM_CONTROL_PTEIN_MASK 0x1000u
#define ENET_MAC_FSM_CONTROL_PTEIN_SHIFT 12u
#define ENET_MAC_FSM_CONTROL_PTEIN_WIDTH 1u
#define ENET_MAC_FSM_CONTROL_PTEIN(x)  (((uint32_t)(((uint32_t)(x))<<ENET_MAC_FSM_CONTROL_PTEIN_SHIFT))&ENET_MAC_FSM_CONTROL_PTEIN_MASK)
#define ENET_MAC_FSM_CONTROL_ATEIN_MASK 0x800u
#define ENET_MAC_FSM_CONTROL_ATEIN_SHIFT 11u
#define ENET_MAC_FSM_CONTROL_ATEIN_WIDTH 1u
#define ENET_MAC_FSM_CONTROL_ATEIN(x)  (((uint32_t)(((uint32_t)(x))<<ENET_MAC_FSM_CONTROL_ATEIN_SHIFT))&ENET_MAC_FSM_CONTROL_ATEIN_MASK)
#define ENET_MAC_FSM_CONTROL_RTEIN_MASK 0x200u
#define ENET_MAC_FSM_CONTROL_RTEIN_SHIFT 9u
#define ENET_MAC_FSM_CONTROL_RTEIN_WIDTH 1u
#define ENET_MAC_FSM_CONTROL_RTEIN(x)  (((uint32_t)(((uint32_t)(x))<<ENET_MAC_FSM_CONTROL_RTEIN_SHIFT))&ENET_MAC_FSM_CONTROL_RTEIN_MASK)
#define ENET_MAC_FSM_CONTROL_TTEIN_MASK 0x100u
#define ENET_MAC_FSM_CONTROL_TTEIN_SHIFT 8u
#define ENET_MAC_FSM_CONTROL_TTEIN_WIDTH 1u
#define ENET_MAC_FSM_CONTROL_TTEIN(x)  (((uint32_t)(((uint32_t)(x))<<ENET_MAC_FSM_CONTROL_TTEIN_SHIFT))&ENET_MAC_FSM_CONTROL_TTEIN_MASK)
#define ENET_MAC_FSM_CONTROL_PRTYEN_MASK 0x2u
#define ENET_MAC_FSM_CONTROL_PRTYEN_SHIFT 1u
#define ENET_MAC_FSM_CONTROL_PRTYEN_WIDTH 1u
#define ENET_MAC_FSM_CONTROL_PRTYEN(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_FSM_CONTROL_PRTYEN_SHIFT))&ENET_MAC_FSM_CONTROL_PRTYEN_MASK)
#define ENET_MAC_FSM_CONTROL_TMOUTEN_MASK 0x1u
#define ENET_MAC_FSM_CONTROL_TMOUTEN_SHIFT 0u
#define ENET_MAC_FSM_CONTROL_TMOUTEN_WIDTH 1u
#define ENET_MAC_FSM_CONTROL_TMOUTEN(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_FSM_CONTROL_TMOUTEN_SHIFT))&ENET_MAC_FSM_CONTROL_TMOUTEN_MASK)
/* MAC_FSM_CONTROL Reg Mask */
#define ENET_MAC_FSM_CONTROL_MASK      0x9B9B9B03u

/* MAC_FSM_ACT_TIMER Bit Fields */
#define ENET_MAC_FSM_ACT_TIMER_LTMRMD_MASK 0xF00000u
#define ENET_MAC_FSM_ACT_TIMER_LTMRMD_SHIFT 20u
#define ENET_MAC_FSM_ACT_TIMER_LTMRMD_WIDTH 4u
#define ENET_MAC_FSM_ACT_TIMER_LTMRMD(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_FSM_ACT_TIMER_LTMRMD_SHIFT))&ENET_MAC_FSM_ACT_TIMER_LTMRMD_MASK)
#define ENET_MAC_FSM_ACT_TIMER_NTMRMD_MASK 0xF0000u
#define ENET_MAC_FSM_ACT_TIMER_NTMRMD_SHIFT 16u
#define ENET_MAC_FSM_ACT_TIMER_NTMRMD_WIDTH 4u
#define ENET_MAC_FSM_ACT_TIMER_NTMRMD(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_FSM_ACT_TIMER_NTMRMD_SHIFT))&ENET_MAC_FSM_ACT_TIMER_NTMRMD_MASK)
#define ENET_MAC_FSM_ACT_TIMER_TMR_MASK 0x3FFu
#define ENET_MAC_FSM_ACT_TIMER_TMR_SHIFT 0u
#define ENET_MAC_FSM_ACT_TIMER_TMR_WIDTH 10u
#define ENET_MAC_FSM_ACT_TIMER_TMR(x)  (((uint32_t)(((uint32_t)(x))<<ENET_MAC_FSM_ACT_TIMER_TMR_SHIFT))&ENET_MAC_FSM_ACT_TIMER_TMR_MASK)
/* MAC_FSM_ACT_TIMER Reg Mask */
#define ENET_MAC_FSM_ACT_TIMER_MASK    0x00FF03FFu

/* SNPS_SCS_REG1 Bit Fields */
#define ENET_SNPS_SCS_REG1_MAC_SCS1_MASK 0xFFFFFFFFu
#define ENET_SNPS_SCS_REG1_MAC_SCS1_SHIFT 0u
#define ENET_SNPS_SCS_REG1_MAC_SCS1_WIDTH 32u
#define ENET_SNPS_SCS_REG1_MAC_SCS1(x) (((uint32_t)(((uint32_t)(x))<<ENET_SNPS_SCS_REG1_MAC_SCS1_SHIFT))&ENET_SNPS_SCS_REG1_MAC_SCS1_MASK)
/* SNPS_SCS_REG1 Reg Mask */
#define ENET_SNPS_SCS_REG1_MASK        0xFFFFFFFFu

/* MAC_MDIO_ADDRESS Bit Fields */
#define ENET_MAC_MDIO_ADDRESS_PSE_MASK 0x8000000u
#define ENET_MAC_MDIO_ADDRESS_PSE_SHIFT 27u
#define ENET_MAC_MDIO_ADDRESS_PSE_WIDTH 1u
#define ENET_MAC_MDIO_ADDRESS_PSE(x)   (((uint32_t)(((uint32_t)(x))<<ENET_MAC_MDIO_ADDRESS_PSE_SHIFT))&ENET_MAC_MDIO_ADDRESS_PSE_MASK)
#define ENET_MAC_MDIO_ADDRESS_BTB_MASK 0x4000000u
#define ENET_MAC_MDIO_ADDRESS_BTB_SHIFT 26u
#define ENET_MAC_MDIO_ADDRESS_BTB_WIDTH 1u
#define ENET_MAC_MDIO_ADDRESS_BTB(x)   (((uint32_t)(((uint32_t)(x))<<ENET_MAC_MDIO_ADDRESS_BTB_SHIFT))&ENET_MAC_MDIO_ADDRESS_BTB_MASK)
#define ENET_MAC_MDIO_ADDRESS_PA_MASK  0x3E00000u
#define ENET_MAC_MDIO_ADDRESS_PA_SHIFT 21u
#define ENET_MAC_MDIO_ADDRESS_PA_WIDTH 5u
#define ENET_MAC_MDIO_ADDRESS_PA(x)    (((uint32_t)(((uint32_t)(x))<<ENET_MAC_MDIO_ADDRESS_PA_SHIFT))&ENET_MAC_MDIO_ADDRESS_PA_MASK)
#define ENET_MAC_MDIO_ADDRESS_RDA_MASK 0x1F0000u
#define ENET_MAC_MDIO_ADDRESS_RDA_SHIFT 16u
#define ENET_MAC_MDIO_ADDRESS_RDA_WIDTH 5u
#define ENET_MAC_MDIO_ADDRESS_RDA(x)   (((uint32_t)(((uint32_t)(x))<<ENET_MAC_MDIO_ADDRESS_RDA_SHIFT))&ENET_MAC_MDIO_ADDRESS_RDA_MASK)
#define ENET_MAC_MDIO_ADDRESS_NTC_MASK 0x7000u
#define ENET_MAC_MDIO_ADDRESS_NTC_SHIFT 12u
#define ENET_MAC_MDIO_ADDRESS_NTC_WIDTH 3u
#define ENET_MAC_MDIO_ADDRESS_NTC(x)   (((uint32_t)(((uint32_t)(x))<<ENET_MAC_MDIO_ADDRESS_NTC_SHIFT))&ENET_MAC_MDIO_ADDRESS_NTC_MASK)
#define ENET_MAC_MDIO_ADDRESS_CR_MASK  0xF00u
#define ENET_MAC_MDIO_ADDRESS_CR_SHIFT 8u
#define ENET_MAC_MDIO_ADDRESS_CR_WIDTH 4u
#define ENET_MAC_MDIO_ADDRESS_CR(x)    (((uint32_t)(((uint32_t)(x))<<ENET_MAC_MDIO_ADDRESS_CR_SHIFT))&ENET_MAC_MDIO_ADDRESS_CR_MASK)
#define ENET_MAC_MDIO_ADDRESS_SKAP_MASK 0x10u
#define ENET_MAC_MDIO_ADDRESS_SKAP_SHIFT 4u
#define ENET_MAC_MDIO_ADDRESS_SKAP_WIDTH 1u
#define ENET_MAC_MDIO_ADDRESS_SKAP(x)  (((uint32_t)(((uint32_t)(x))<<ENET_MAC_MDIO_ADDRESS_SKAP_SHIFT))&ENET_MAC_MDIO_ADDRESS_SKAP_MASK)
#define ENET_MAC_MDIO_ADDRESS_GOC_1_MASK 0x8u
#define ENET_MAC_MDIO_ADDRESS_GOC_1_SHIFT 3u
#define ENET_MAC_MDIO_ADDRESS_GOC_1_WIDTH 1u
#define ENET_MAC_MDIO_ADDRESS_GOC_1(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_MDIO_ADDRESS_GOC_1_SHIFT))&ENET_MAC_MDIO_ADDRESS_GOC_1_MASK)
#define ENET_MAC_MDIO_ADDRESS_GOC_0_MASK 0x4u
#define ENET_MAC_MDIO_ADDRESS_GOC_0_SHIFT 2u
#define ENET_MAC_MDIO_ADDRESS_GOC_0_WIDTH 1u
#define ENET_MAC_MDIO_ADDRESS_GOC_0(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_MDIO_ADDRESS_GOC_0_SHIFT))&ENET_MAC_MDIO_ADDRESS_GOC_0_MASK)
#define ENET_MAC_MDIO_ADDRESS_C45E_MASK 0x2u
#define ENET_MAC_MDIO_ADDRESS_C45E_SHIFT 1u
#define ENET_MAC_MDIO_ADDRESS_C45E_WIDTH 1u
#define ENET_MAC_MDIO_ADDRESS_C45E(x)  (((uint32_t)(((uint32_t)(x))<<ENET_MAC_MDIO_ADDRESS_C45E_SHIFT))&ENET_MAC_MDIO_ADDRESS_C45E_MASK)
#define ENET_MAC_MDIO_ADDRESS_GB_MASK  0x1u
#define ENET_MAC_MDIO_ADDRESS_GB_SHIFT 0u
#define ENET_MAC_MDIO_ADDRESS_GB_WIDTH 1u
#define ENET_MAC_MDIO_ADDRESS_GB(x)    (((uint32_t)(((uint32_t)(x))<<ENET_MAC_MDIO_ADDRESS_GB_SHIFT))&ENET_MAC_MDIO_ADDRESS_GB_MASK)
/* MAC_MDIO_ADDRESS Reg Mask */
#define ENET_MAC_MDIO_ADDRESS_MASK     0x0FFF7F1Fu

/* MAC_MDIO_DATA Bit Fields */
#define ENET_MAC_MDIO_DATA_RA_MASK     0xFFFF0000u
#define ENET_MAC_MDIO_DATA_RA_SHIFT    16u
#define ENET_MAC_MDIO_DATA_RA_WIDTH    16u
#define ENET_MAC_MDIO_DATA_RA(x)       (((uint32_t)(((uint32_t)(x))<<ENET_MAC_MDIO_DATA_RA_SHIFT))&ENET_MAC_MDIO_DATA_RA_MASK)
#define ENET_MAC_MDIO_DATA_GD_MASK     0xFFFFu
#define ENET_MAC_MDIO_DATA_GD_SHIFT    0u
#define ENET_MAC_MDIO_DATA_GD_WIDTH    16u
#define ENET_MAC_MDIO_DATA_GD(x)       (((uint32_t)(((uint32_t)(x))<<ENET_MAC_MDIO_DATA_GD_SHIFT))&ENET_MAC_MDIO_DATA_GD_MASK)
/* MAC_MDIO_DATA Reg Mask */
#define ENET_MAC_MDIO_DATA_MASK        0xFFFFFFFFu

/* MAC_CSR_SW_CTRL Bit Fields */
#define ENET_MAC_CSR_SW_CTRL_SEEN_MASK 0x100u
#define ENET_MAC_CSR_SW_CTRL_SEEN_SHIFT 8u
#define ENET_MAC_CSR_SW_CTRL_SEEN_WIDTH 1u
#define ENET_MAC_CSR_SW_CTRL_SEEN(x)   (((uint32_t)(((uint32_t)(x))<<ENET_MAC_CSR_SW_CTRL_SEEN_SHIFT))&ENET_MAC_CSR_SW_CTRL_SEEN_MASK)
#define ENET_MAC_CSR_SW_CTRL_RCWE_MASK 0x1u
#define ENET_MAC_CSR_SW_CTRL_RCWE_SHIFT 0u
#define ENET_MAC_CSR_SW_CTRL_RCWE_WIDTH 1u
#define ENET_MAC_CSR_SW_CTRL_RCWE(x)   (((uint32_t)(((uint32_t)(x))<<ENET_MAC_CSR_SW_CTRL_RCWE_SHIFT))&ENET_MAC_CSR_SW_CTRL_RCWE_MASK)
/* MAC_CSR_SW_CTRL Reg Mask */
#define ENET_MAC_CSR_SW_CTRL_MASK      0x00000101u

/* MAC_FPE_CTRL_STS Bit Fields */
#define ENET_MAC_FPE_CTRL_STS_TRSP_MASK 0x80000u
#define ENET_MAC_FPE_CTRL_STS_TRSP_SHIFT 19u
#define ENET_MAC_FPE_CTRL_STS_TRSP_WIDTH 1u
#define ENET_MAC_FPE_CTRL_STS_TRSP(x)  (((uint32_t)(((uint32_t)(x))<<ENET_MAC_FPE_CTRL_STS_TRSP_SHIFT))&ENET_MAC_FPE_CTRL_STS_TRSP_MASK)
#define ENET_MAC_FPE_CTRL_STS_TVER_MASK 0x40000u
#define ENET_MAC_FPE_CTRL_STS_TVER_SHIFT 18u
#define ENET_MAC_FPE_CTRL_STS_TVER_WIDTH 1u
#define ENET_MAC_FPE_CTRL_STS_TVER(x)  (((uint32_t)(((uint32_t)(x))<<ENET_MAC_FPE_CTRL_STS_TVER_SHIFT))&ENET_MAC_FPE_CTRL_STS_TVER_MASK)
#define ENET_MAC_FPE_CTRL_STS_RRSP_MASK 0x20000u
#define ENET_MAC_FPE_CTRL_STS_RRSP_SHIFT 17u
#define ENET_MAC_FPE_CTRL_STS_RRSP_WIDTH 1u
#define ENET_MAC_FPE_CTRL_STS_RRSP(x)  (((uint32_t)(((uint32_t)(x))<<ENET_MAC_FPE_CTRL_STS_RRSP_SHIFT))&ENET_MAC_FPE_CTRL_STS_RRSP_MASK)
#define ENET_MAC_FPE_CTRL_STS_RVER_MASK 0x10000u
#define ENET_MAC_FPE_CTRL_STS_RVER_SHIFT 16u
#define ENET_MAC_FPE_CTRL_STS_RVER_WIDTH 1u
#define ENET_MAC_FPE_CTRL_STS_RVER(x)  (((uint32_t)(((uint32_t)(x))<<ENET_MAC_FPE_CTRL_STS_RVER_SHIFT))&ENET_MAC_FPE_CTRL_STS_RVER_MASK)
#define ENET_MAC_FPE_CTRL_STS_S1_SET_0_MASK 0x8u
#define ENET_MAC_FPE_CTRL_STS_S1_SET_0_SHIFT 3u
#define ENET_MAC_FPE_CTRL_STS_S1_SET_0_WIDTH 1u
#define ENET_MAC_FPE_CTRL_STS_S1_SET_0(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_FPE_CTRL_STS_S1_SET_0_SHIFT))&ENET_MAC_FPE_CTRL_STS_S1_SET_0_MASK)
#define ENET_MAC_FPE_CTRL_STS_SRSP_MASK 0x4u
#define ENET_MAC_FPE_CTRL_STS_SRSP_SHIFT 2u
#define ENET_MAC_FPE_CTRL_STS_SRSP_WIDTH 1u
#define ENET_MAC_FPE_CTRL_STS_SRSP(x)  (((uint32_t)(((uint32_t)(x))<<ENET_MAC_FPE_CTRL_STS_SRSP_SHIFT))&ENET_MAC_FPE_CTRL_STS_SRSP_MASK)
#define ENET_MAC_FPE_CTRL_STS_SVER_MASK 0x2u
#define ENET_MAC_FPE_CTRL_STS_SVER_SHIFT 1u
#define ENET_MAC_FPE_CTRL_STS_SVER_WIDTH 1u
#define ENET_MAC_FPE_CTRL_STS_SVER(x)  (((uint32_t)(((uint32_t)(x))<<ENET_MAC_FPE_CTRL_STS_SVER_SHIFT))&ENET_MAC_FPE_CTRL_STS_SVER_MASK)
#define ENET_MAC_FPE_CTRL_STS_EFPE_MASK 0x1u
#define ENET_MAC_FPE_CTRL_STS_EFPE_SHIFT 0u
#define ENET_MAC_FPE_CTRL_STS_EFPE_WIDTH 1u
#define ENET_MAC_FPE_CTRL_STS_EFPE(x)  (((uint32_t)(((uint32_t)(x))<<ENET_MAC_FPE_CTRL_STS_EFPE_SHIFT))&ENET_MAC_FPE_CTRL_STS_EFPE_MASK)
/* MAC_FPE_CTRL_STS Reg Mask */
#define ENET_MAC_FPE_CTRL_STS_MASK     0x000F000Fu

/* MAC_EXT_CFG1 Bit Fields */
#define ENET_MAC_EXT_CFG1_SAVE_MASK    0x1000000u
#define ENET_MAC_EXT_CFG1_SAVE_SHIFT   24u
#define ENET_MAC_EXT_CFG1_SAVE_WIDTH   1u
#define ENET_MAC_EXT_CFG1_SAVE(x)      (((uint32_t)(((uint32_t)(x))<<ENET_MAC_EXT_CFG1_SAVE_SHIFT))&ENET_MAC_EXT_CFG1_SAVE_MASK)
#define ENET_MAC_EXT_CFG1_SAVO_MASK    0x7F0000u
#define ENET_MAC_EXT_CFG1_SAVO_SHIFT   16u
#define ENET_MAC_EXT_CFG1_SAVO_WIDTH   7u
#define ENET_MAC_EXT_CFG1_SAVO(x)      (((uint32_t)(((uint32_t)(x))<<ENET_MAC_EXT_CFG1_SAVO_SHIFT))&ENET_MAC_EXT_CFG1_SAVO_MASK)
#define ENET_MAC_EXT_CFG1_SPLM_MASK    0x300u
#define ENET_MAC_EXT_CFG1_SPLM_SHIFT   8u
#define ENET_MAC_EXT_CFG1_SPLM_WIDTH   2u
#define ENET_MAC_EXT_CFG1_SPLM(x)      (((uint32_t)(((uint32_t)(x))<<ENET_MAC_EXT_CFG1_SPLM_SHIFT))&ENET_MAC_EXT_CFG1_SPLM_MASK)
#define ENET_MAC_EXT_CFG1_SPLOFST_MASK 0x7Fu
#define ENET_MAC_EXT_CFG1_SPLOFST_SHIFT 0u
#define ENET_MAC_EXT_CFG1_SPLOFST_WIDTH 7u
#define ENET_MAC_EXT_CFG1_SPLOFST(x)   (((uint32_t)(((uint32_t)(x))<<ENET_MAC_EXT_CFG1_SPLOFST_SHIFT))&ENET_MAC_EXT_CFG1_SPLOFST_MASK)
/* MAC_EXT_CFG1 Reg Mask */
#define ENET_MAC_EXT_CFG1_MASK         0x017F037Fu

/* MAC_PRESN_TIME_NS Bit Fields */
#define ENET_MAC_PRESN_TIME_NS_MPTN_MASK 0xFFFFFFFFu
#define ENET_MAC_PRESN_TIME_NS_MPTN_SHIFT 0u
#define ENET_MAC_PRESN_TIME_NS_MPTN_WIDTH 32u
#define ENET_MAC_PRESN_TIME_NS_MPTN(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_PRESN_TIME_NS_MPTN_SHIFT))&ENET_MAC_PRESN_TIME_NS_MPTN_MASK)
/* MAC_PRESN_TIME_NS Reg Mask */
#define ENET_MAC_PRESN_TIME_NS_MASK    0xFFFFFFFFu

/* MAC_PRESN_TIME_UPDT Bit Fields */
#define ENET_MAC_PRESN_TIME_UPDT_MPTU_MASK 0xFFFFFFFFu
#define ENET_MAC_PRESN_TIME_UPDT_MPTU_SHIFT 0u
#define ENET_MAC_PRESN_TIME_UPDT_MPTU_WIDTH 32u
#define ENET_MAC_PRESN_TIME_UPDT_MPTU(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_PRESN_TIME_UPDT_MPTU_SHIFT))&ENET_MAC_PRESN_TIME_UPDT_MPTU_MASK)
/* MAC_PRESN_TIME_UPDT Reg Mask */
#define ENET_MAC_PRESN_TIME_UPDT_MASK  0xFFFFFFFFu

/* MAC_ADDRESS0_HIGH Bit Fields */
#define ENET_MAC_ADDRESS0_HIGH_AE_MASK 0x80000000u
#define ENET_MAC_ADDRESS0_HIGH_AE_SHIFT 31u
#define ENET_MAC_ADDRESS0_HIGH_AE_WIDTH 1u
#define ENET_MAC_ADDRESS0_HIGH_AE(x)   (((uint32_t)(((uint32_t)(x))<<ENET_MAC_ADDRESS0_HIGH_AE_SHIFT))&ENET_MAC_ADDRESS0_HIGH_AE_MASK)
#define ENET_MAC_ADDRESS0_HIGH_DCS_MASK 0x30000u
#define ENET_MAC_ADDRESS0_HIGH_DCS_SHIFT 16u
#define ENET_MAC_ADDRESS0_HIGH_DCS_WIDTH 2u
#define ENET_MAC_ADDRESS0_HIGH_DCS(x)  (((uint32_t)(((uint32_t)(x))<<ENET_MAC_ADDRESS0_HIGH_DCS_SHIFT))&ENET_MAC_ADDRESS0_HIGH_DCS_MASK)
#define ENET_MAC_ADDRESS0_HIGH_ADDRHI_MASK 0xFFFFu
#define ENET_MAC_ADDRESS0_HIGH_ADDRHI_SHIFT 0u
#define ENET_MAC_ADDRESS0_HIGH_ADDRHI_WIDTH 16u
#define ENET_MAC_ADDRESS0_HIGH_ADDRHI(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_ADDRESS0_HIGH_ADDRHI_SHIFT))&ENET_MAC_ADDRESS0_HIGH_ADDRHI_MASK)
/* MAC_ADDRESS0_HIGH Reg Mask */
#define ENET_MAC_ADDRESS0_HIGH_MASK    0x8003FFFFu

/* MAC_ADDRESS0_LOW Bit Fields */
#define ENET_MAC_ADDRESS0_LOW_ADDRLO_MASK 0xFFFFFFFFu
#define ENET_MAC_ADDRESS0_LOW_ADDRLO_SHIFT 0u
#define ENET_MAC_ADDRESS0_LOW_ADDRLO_WIDTH 32u
#define ENET_MAC_ADDRESS0_LOW_ADDRLO(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_ADDRESS0_LOW_ADDRLO_SHIFT))&ENET_MAC_ADDRESS0_LOW_ADDRLO_MASK)
/* MAC_ADDRESS0_LOW Reg Mask */
#define ENET_MAC_ADDRESS0_LOW_MASK     0xFFFFFFFFu

/* MAC_ADDRESS1_HIGH Bit Fields */
#define ENET_MAC_ADDRESS1_HIGH_AE_MASK 0x80000000u
#define ENET_MAC_ADDRESS1_HIGH_AE_SHIFT 31u
#define ENET_MAC_ADDRESS1_HIGH_AE_WIDTH 1u
#define ENET_MAC_ADDRESS1_HIGH_AE(x)   (((uint32_t)(((uint32_t)(x))<<ENET_MAC_ADDRESS1_HIGH_AE_SHIFT))&ENET_MAC_ADDRESS1_HIGH_AE_MASK)
#define ENET_MAC_ADDRESS1_HIGH_SA_MASK 0x40000000u
#define ENET_MAC_ADDRESS1_HIGH_SA_SHIFT 30u
#define ENET_MAC_ADDRESS1_HIGH_SA_WIDTH 1u
#define ENET_MAC_ADDRESS1_HIGH_SA(x)   (((uint32_t)(((uint32_t)(x))<<ENET_MAC_ADDRESS1_HIGH_SA_SHIFT))&ENET_MAC_ADDRESS1_HIGH_SA_MASK)
#define ENET_MAC_ADDRESS1_HIGH_MBC_MASK 0x3F000000u
#define ENET_MAC_ADDRESS1_HIGH_MBC_SHIFT 24u
#define ENET_MAC_ADDRESS1_HIGH_MBC_WIDTH 6u
#define ENET_MAC_ADDRESS1_HIGH_MBC(x)  (((uint32_t)(((uint32_t)(x))<<ENET_MAC_ADDRESS1_HIGH_MBC_SHIFT))&ENET_MAC_ADDRESS1_HIGH_MBC_MASK)
#define ENET_MAC_ADDRESS1_HIGH_DCS_MASK 0x30000u
#define ENET_MAC_ADDRESS1_HIGH_DCS_SHIFT 16u
#define ENET_MAC_ADDRESS1_HIGH_DCS_WIDTH 2u
#define ENET_MAC_ADDRESS1_HIGH_DCS(x)  (((uint32_t)(((uint32_t)(x))<<ENET_MAC_ADDRESS1_HIGH_DCS_SHIFT))&ENET_MAC_ADDRESS1_HIGH_DCS_MASK)
#define ENET_MAC_ADDRESS1_HIGH_ADDRHI_MASK 0xFFFFu
#define ENET_MAC_ADDRESS1_HIGH_ADDRHI_SHIFT 0u
#define ENET_MAC_ADDRESS1_HIGH_ADDRHI_WIDTH 16u
#define ENET_MAC_ADDRESS1_HIGH_ADDRHI(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_ADDRESS1_HIGH_ADDRHI_SHIFT))&ENET_MAC_ADDRESS1_HIGH_ADDRHI_MASK)
/* MAC_ADDRESS1_HIGH Reg Mask */
#define ENET_MAC_ADDRESS1_HIGH_MASK    0xFF03FFFFu

/* MAC_ADDRESS1_LOW Bit Fields */
#define ENET_MAC_ADDRESS1_LOW_ADDRLO_MASK 0xFFFFFFFFu
#define ENET_MAC_ADDRESS1_LOW_ADDRLO_SHIFT 0u
#define ENET_MAC_ADDRESS1_LOW_ADDRLO_WIDTH 32u
#define ENET_MAC_ADDRESS1_LOW_ADDRLO(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_ADDRESS1_LOW_ADDRLO_SHIFT))&ENET_MAC_ADDRESS1_LOW_ADDRLO_MASK)
/* MAC_ADDRESS1_LOW Reg Mask */
#define ENET_MAC_ADDRESS1_LOW_MASK     0xFFFFFFFFu

/* MAC_ADDRESS2_HIGH Bit Fields */
#define ENET_MAC_ADDRESS2_HIGH_AE_MASK 0x80000000u
#define ENET_MAC_ADDRESS2_HIGH_AE_SHIFT 31u
#define ENET_MAC_ADDRESS2_HIGH_AE_WIDTH 1u
#define ENET_MAC_ADDRESS2_HIGH_AE(x)   (((uint32_t)(((uint32_t)(x))<<ENET_MAC_ADDRESS2_HIGH_AE_SHIFT))&ENET_MAC_ADDRESS2_HIGH_AE_MASK)
#define ENET_MAC_ADDRESS2_HIGH_SA_MASK 0x40000000u
#define ENET_MAC_ADDRESS2_HIGH_SA_SHIFT 30u
#define ENET_MAC_ADDRESS2_HIGH_SA_WIDTH 1u
#define ENET_MAC_ADDRESS2_HIGH_SA(x)   (((uint32_t)(((uint32_t)(x))<<ENET_MAC_ADDRESS2_HIGH_SA_SHIFT))&ENET_MAC_ADDRESS2_HIGH_SA_MASK)
#define ENET_MAC_ADDRESS2_HIGH_MBC_MASK 0x3F000000u
#define ENET_MAC_ADDRESS2_HIGH_MBC_SHIFT 24u
#define ENET_MAC_ADDRESS2_HIGH_MBC_WIDTH 6u
#define ENET_MAC_ADDRESS2_HIGH_MBC(x)  (((uint32_t)(((uint32_t)(x))<<ENET_MAC_ADDRESS2_HIGH_MBC_SHIFT))&ENET_MAC_ADDRESS2_HIGH_MBC_MASK)
#define ENET_MAC_ADDRESS2_HIGH_DCS_MASK 0x30000u
#define ENET_MAC_ADDRESS2_HIGH_DCS_SHIFT 16u
#define ENET_MAC_ADDRESS2_HIGH_DCS_WIDTH 2u
#define ENET_MAC_ADDRESS2_HIGH_DCS(x)  (((uint32_t)(((uint32_t)(x))<<ENET_MAC_ADDRESS2_HIGH_DCS_SHIFT))&ENET_MAC_ADDRESS2_HIGH_DCS_MASK)
#define ENET_MAC_ADDRESS2_HIGH_ADDRHI_MASK 0xFFFFu
#define ENET_MAC_ADDRESS2_HIGH_ADDRHI_SHIFT 0u
#define ENET_MAC_ADDRESS2_HIGH_ADDRHI_WIDTH 16u
#define ENET_MAC_ADDRESS2_HIGH_ADDRHI(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_ADDRESS2_HIGH_ADDRHI_SHIFT))&ENET_MAC_ADDRESS2_HIGH_ADDRHI_MASK)
/* MAC_ADDRESS2_HIGH Reg Mask */
#define ENET_MAC_ADDRESS2_HIGH_MASK    0xFF03FFFFu

/* MAC_ADDRESS2_LOW Bit Fields */
#define ENET_MAC_ADDRESS2_LOW_ADDRLO_MASK 0xFFFFFFFFu
#define ENET_MAC_ADDRESS2_LOW_ADDRLO_SHIFT 0u
#define ENET_MAC_ADDRESS2_LOW_ADDRLO_WIDTH 32u
#define ENET_MAC_ADDRESS2_LOW_ADDRLO(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_ADDRESS2_LOW_ADDRLO_SHIFT))&ENET_MAC_ADDRESS2_LOW_ADDRLO_MASK)
/* MAC_ADDRESS2_LOW Reg Mask */
#define ENET_MAC_ADDRESS2_LOW_MASK     0xFFFFFFFFu

/* MMC_CONTROL Bit Fields */
#define ENET_MMC_CONTROL_UCDBC_MASK    0x100u
#define ENET_MMC_CONTROL_UCDBC_SHIFT   8u
#define ENET_MMC_CONTROL_UCDBC_WIDTH   1u
#define ENET_MMC_CONTROL_UCDBC(x)      (((uint32_t)(((uint32_t)(x))<<ENET_MMC_CONTROL_UCDBC_SHIFT))&ENET_MMC_CONTROL_UCDBC_MASK)
#define ENET_MMC_CONTROL_CNTPRSTLVL_MASK 0x20u
#define ENET_MMC_CONTROL_CNTPRSTLVL_SHIFT 5u
#define ENET_MMC_CONTROL_CNTPRSTLVL_WIDTH 1u
#define ENET_MMC_CONTROL_CNTPRSTLVL(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_CONTROL_CNTPRSTLVL_SHIFT))&ENET_MMC_CONTROL_CNTPRSTLVL_MASK)
#define ENET_MMC_CONTROL_CNTPRST_MASK  0x10u
#define ENET_MMC_CONTROL_CNTPRST_SHIFT 4u
#define ENET_MMC_CONTROL_CNTPRST_WIDTH 1u
#define ENET_MMC_CONTROL_CNTPRST(x)    (((uint32_t)(((uint32_t)(x))<<ENET_MMC_CONTROL_CNTPRST_SHIFT))&ENET_MMC_CONTROL_CNTPRST_MASK)
#define ENET_MMC_CONTROL_CNTFREEZ_MASK 0x8u
#define ENET_MMC_CONTROL_CNTFREEZ_SHIFT 3u
#define ENET_MMC_CONTROL_CNTFREEZ_WIDTH 1u
#define ENET_MMC_CONTROL_CNTFREEZ(x)   (((uint32_t)(((uint32_t)(x))<<ENET_MMC_CONTROL_CNTFREEZ_SHIFT))&ENET_MMC_CONTROL_CNTFREEZ_MASK)
#define ENET_MMC_CONTROL_RSTONRD_MASK  0x4u
#define ENET_MMC_CONTROL_RSTONRD_SHIFT 2u
#define ENET_MMC_CONTROL_RSTONRD_WIDTH 1u
#define ENET_MMC_CONTROL_RSTONRD(x)    (((uint32_t)(((uint32_t)(x))<<ENET_MMC_CONTROL_RSTONRD_SHIFT))&ENET_MMC_CONTROL_RSTONRD_MASK)
#define ENET_MMC_CONTROL_CNTSTOPRO_MASK 0x2u
#define ENET_MMC_CONTROL_CNTSTOPRO_SHIFT 1u
#define ENET_MMC_CONTROL_CNTSTOPRO_WIDTH 1u
#define ENET_MMC_CONTROL_CNTSTOPRO(x)  (((uint32_t)(((uint32_t)(x))<<ENET_MMC_CONTROL_CNTSTOPRO_SHIFT))&ENET_MMC_CONTROL_CNTSTOPRO_MASK)
#define ENET_MMC_CONTROL_CNTRST_MASK   0x1u
#define ENET_MMC_CONTROL_CNTRST_SHIFT  0u
#define ENET_MMC_CONTROL_CNTRST_WIDTH  1u
#define ENET_MMC_CONTROL_CNTRST(x)     (((uint32_t)(((uint32_t)(x))<<ENET_MMC_CONTROL_CNTRST_SHIFT))&ENET_MMC_CONTROL_CNTRST_MASK)
/* MMC_CONTROL Reg Mask */
#define ENET_MMC_CONTROL_MASK          0x0000013Fu

/* MMC_RX_INTERRUPT Bit Fields */
#define ENET_MMC_RX_INTERRUPT_RXCTRLPIS_MASK 0x2000000u
#define ENET_MMC_RX_INTERRUPT_RXCTRLPIS_SHIFT 25u
#define ENET_MMC_RX_INTERRUPT_RXCTRLPIS_WIDTH 1u
#define ENET_MMC_RX_INTERRUPT_RXCTRLPIS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_RX_INTERRUPT_RXCTRLPIS_SHIFT))&ENET_MMC_RX_INTERRUPT_RXCTRLPIS_MASK)
#define ENET_MMC_RX_INTERRUPT_RXRCVERRPIS_MASK 0x1000000u
#define ENET_MMC_RX_INTERRUPT_RXRCVERRPIS_SHIFT 24u
#define ENET_MMC_RX_INTERRUPT_RXRCVERRPIS_WIDTH 1u
#define ENET_MMC_RX_INTERRUPT_RXRCVERRPIS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_RX_INTERRUPT_RXRCVERRPIS_SHIFT))&ENET_MMC_RX_INTERRUPT_RXRCVERRPIS_MASK)
#define ENET_MMC_RX_INTERRUPT_RXWDOGPIS_MASK 0x800000u
#define ENET_MMC_RX_INTERRUPT_RXWDOGPIS_SHIFT 23u
#define ENET_MMC_RX_INTERRUPT_RXWDOGPIS_WIDTH 1u
#define ENET_MMC_RX_INTERRUPT_RXWDOGPIS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_RX_INTERRUPT_RXWDOGPIS_SHIFT))&ENET_MMC_RX_INTERRUPT_RXWDOGPIS_MASK)
#define ENET_MMC_RX_INTERRUPT_RXVLANGBPIS_MASK 0x400000u
#define ENET_MMC_RX_INTERRUPT_RXVLANGBPIS_SHIFT 22u
#define ENET_MMC_RX_INTERRUPT_RXVLANGBPIS_WIDTH 1u
#define ENET_MMC_RX_INTERRUPT_RXVLANGBPIS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_RX_INTERRUPT_RXVLANGBPIS_SHIFT))&ENET_MMC_RX_INTERRUPT_RXVLANGBPIS_MASK)
#define ENET_MMC_RX_INTERRUPT_RXFOVPIS_MASK 0x200000u
#define ENET_MMC_RX_INTERRUPT_RXFOVPIS_SHIFT 21u
#define ENET_MMC_RX_INTERRUPT_RXFOVPIS_WIDTH 1u
#define ENET_MMC_RX_INTERRUPT_RXFOVPIS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_RX_INTERRUPT_RXFOVPIS_SHIFT))&ENET_MMC_RX_INTERRUPT_RXFOVPIS_MASK)
#define ENET_MMC_RX_INTERRUPT_RXPAUSPIS_MASK 0x100000u
#define ENET_MMC_RX_INTERRUPT_RXPAUSPIS_SHIFT 20u
#define ENET_MMC_RX_INTERRUPT_RXPAUSPIS_WIDTH 1u
#define ENET_MMC_RX_INTERRUPT_RXPAUSPIS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_RX_INTERRUPT_RXPAUSPIS_SHIFT))&ENET_MMC_RX_INTERRUPT_RXPAUSPIS_MASK)
#define ENET_MMC_RX_INTERRUPT_RXORANGEPIS_MASK 0x80000u
#define ENET_MMC_RX_INTERRUPT_RXORANGEPIS_SHIFT 19u
#define ENET_MMC_RX_INTERRUPT_RXORANGEPIS_WIDTH 1u
#define ENET_MMC_RX_INTERRUPT_RXORANGEPIS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_RX_INTERRUPT_RXORANGEPIS_SHIFT))&ENET_MMC_RX_INTERRUPT_RXORANGEPIS_MASK)
#define ENET_MMC_RX_INTERRUPT_RXLENERPIS_MASK 0x40000u
#define ENET_MMC_RX_INTERRUPT_RXLENERPIS_SHIFT 18u
#define ENET_MMC_RX_INTERRUPT_RXLENERPIS_WIDTH 1u
#define ENET_MMC_RX_INTERRUPT_RXLENERPIS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_RX_INTERRUPT_RXLENERPIS_SHIFT))&ENET_MMC_RX_INTERRUPT_RXLENERPIS_MASK)
#define ENET_MMC_RX_INTERRUPT_RXUCGPIS_MASK 0x20000u
#define ENET_MMC_RX_INTERRUPT_RXUCGPIS_SHIFT 17u
#define ENET_MMC_RX_INTERRUPT_RXUCGPIS_WIDTH 1u
#define ENET_MMC_RX_INTERRUPT_RXUCGPIS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_RX_INTERRUPT_RXUCGPIS_SHIFT))&ENET_MMC_RX_INTERRUPT_RXUCGPIS_MASK)
#define ENET_MMC_RX_INTERRUPT_RX1024TMAXOCTGBPIS_MASK 0x10000u
#define ENET_MMC_RX_INTERRUPT_RX1024TMAXOCTGBPIS_SHIFT 16u
#define ENET_MMC_RX_INTERRUPT_RX1024TMAXOCTGBPIS_WIDTH 1u
#define ENET_MMC_RX_INTERRUPT_RX1024TMAXOCTGBPIS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_RX_INTERRUPT_RX1024TMAXOCTGBPIS_SHIFT))&ENET_MMC_RX_INTERRUPT_RX1024TMAXOCTGBPIS_MASK)
#define ENET_MMC_RX_INTERRUPT_RX512T1023OCTGBPIS_MASK 0x8000u
#define ENET_MMC_RX_INTERRUPT_RX512T1023OCTGBPIS_SHIFT 15u
#define ENET_MMC_RX_INTERRUPT_RX512T1023OCTGBPIS_WIDTH 1u
#define ENET_MMC_RX_INTERRUPT_RX512T1023OCTGBPIS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_RX_INTERRUPT_RX512T1023OCTGBPIS_SHIFT))&ENET_MMC_RX_INTERRUPT_RX512T1023OCTGBPIS_MASK)
#define ENET_MMC_RX_INTERRUPT_RX256T511OCTGBPIS_MASK 0x4000u
#define ENET_MMC_RX_INTERRUPT_RX256T511OCTGBPIS_SHIFT 14u
#define ENET_MMC_RX_INTERRUPT_RX256T511OCTGBPIS_WIDTH 1u
#define ENET_MMC_RX_INTERRUPT_RX256T511OCTGBPIS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_RX_INTERRUPT_RX256T511OCTGBPIS_SHIFT))&ENET_MMC_RX_INTERRUPT_RX256T511OCTGBPIS_MASK)
#define ENET_MMC_RX_INTERRUPT_RX128T255OCTGBPIS_MASK 0x2000u
#define ENET_MMC_RX_INTERRUPT_RX128T255OCTGBPIS_SHIFT 13u
#define ENET_MMC_RX_INTERRUPT_RX128T255OCTGBPIS_WIDTH 1u
#define ENET_MMC_RX_INTERRUPT_RX128T255OCTGBPIS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_RX_INTERRUPT_RX128T255OCTGBPIS_SHIFT))&ENET_MMC_RX_INTERRUPT_RX128T255OCTGBPIS_MASK)
#define ENET_MMC_RX_INTERRUPT_RX65T127OCTGBPIS_MASK 0x1000u
#define ENET_MMC_RX_INTERRUPT_RX65T127OCTGBPIS_SHIFT 12u
#define ENET_MMC_RX_INTERRUPT_RX65T127OCTGBPIS_WIDTH 1u
#define ENET_MMC_RX_INTERRUPT_RX65T127OCTGBPIS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_RX_INTERRUPT_RX65T127OCTGBPIS_SHIFT))&ENET_MMC_RX_INTERRUPT_RX65T127OCTGBPIS_MASK)
#define ENET_MMC_RX_INTERRUPT_RX64OCTGBPIS_MASK 0x800u
#define ENET_MMC_RX_INTERRUPT_RX64OCTGBPIS_SHIFT 11u
#define ENET_MMC_RX_INTERRUPT_RX64OCTGBPIS_WIDTH 1u
#define ENET_MMC_RX_INTERRUPT_RX64OCTGBPIS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_RX_INTERRUPT_RX64OCTGBPIS_SHIFT))&ENET_MMC_RX_INTERRUPT_RX64OCTGBPIS_MASK)
#define ENET_MMC_RX_INTERRUPT_RXOSIZEGPIS_MASK 0x400u
#define ENET_MMC_RX_INTERRUPT_RXOSIZEGPIS_SHIFT 10u
#define ENET_MMC_RX_INTERRUPT_RXOSIZEGPIS_WIDTH 1u
#define ENET_MMC_RX_INTERRUPT_RXOSIZEGPIS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_RX_INTERRUPT_RXOSIZEGPIS_SHIFT))&ENET_MMC_RX_INTERRUPT_RXOSIZEGPIS_MASK)
#define ENET_MMC_RX_INTERRUPT_RXUSIZEGPIS_MASK 0x200u
#define ENET_MMC_RX_INTERRUPT_RXUSIZEGPIS_SHIFT 9u
#define ENET_MMC_RX_INTERRUPT_RXUSIZEGPIS_WIDTH 1u
#define ENET_MMC_RX_INTERRUPT_RXUSIZEGPIS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_RX_INTERRUPT_RXUSIZEGPIS_SHIFT))&ENET_MMC_RX_INTERRUPT_RXUSIZEGPIS_MASK)
#define ENET_MMC_RX_INTERRUPT_RXJABERPIS_MASK 0x100u
#define ENET_MMC_RX_INTERRUPT_RXJABERPIS_SHIFT 8u
#define ENET_MMC_RX_INTERRUPT_RXJABERPIS_WIDTH 1u
#define ENET_MMC_RX_INTERRUPT_RXJABERPIS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_RX_INTERRUPT_RXJABERPIS_SHIFT))&ENET_MMC_RX_INTERRUPT_RXJABERPIS_MASK)
#define ENET_MMC_RX_INTERRUPT_RXRUNTPIS_MASK 0x80u
#define ENET_MMC_RX_INTERRUPT_RXRUNTPIS_SHIFT 7u
#define ENET_MMC_RX_INTERRUPT_RXRUNTPIS_WIDTH 1u
#define ENET_MMC_RX_INTERRUPT_RXRUNTPIS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_RX_INTERRUPT_RXRUNTPIS_SHIFT))&ENET_MMC_RX_INTERRUPT_RXRUNTPIS_MASK)
#define ENET_MMC_RX_INTERRUPT_RXALGNERPIS_MASK 0x40u
#define ENET_MMC_RX_INTERRUPT_RXALGNERPIS_SHIFT 6u
#define ENET_MMC_RX_INTERRUPT_RXALGNERPIS_WIDTH 1u
#define ENET_MMC_RX_INTERRUPT_RXALGNERPIS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_RX_INTERRUPT_RXALGNERPIS_SHIFT))&ENET_MMC_RX_INTERRUPT_RXALGNERPIS_MASK)
#define ENET_MMC_RX_INTERRUPT_RXCRCERPIS_MASK 0x20u
#define ENET_MMC_RX_INTERRUPT_RXCRCERPIS_SHIFT 5u
#define ENET_MMC_RX_INTERRUPT_RXCRCERPIS_WIDTH 1u
#define ENET_MMC_RX_INTERRUPT_RXCRCERPIS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_RX_INTERRUPT_RXCRCERPIS_SHIFT))&ENET_MMC_RX_INTERRUPT_RXCRCERPIS_MASK)
#define ENET_MMC_RX_INTERRUPT_RXMCGPIS_MASK 0x10u
#define ENET_MMC_RX_INTERRUPT_RXMCGPIS_SHIFT 4u
#define ENET_MMC_RX_INTERRUPT_RXMCGPIS_WIDTH 1u
#define ENET_MMC_RX_INTERRUPT_RXMCGPIS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_RX_INTERRUPT_RXMCGPIS_SHIFT))&ENET_MMC_RX_INTERRUPT_RXMCGPIS_MASK)
#define ENET_MMC_RX_INTERRUPT_RXBCGPIS_MASK 0x8u
#define ENET_MMC_RX_INTERRUPT_RXBCGPIS_SHIFT 3u
#define ENET_MMC_RX_INTERRUPT_RXBCGPIS_WIDTH 1u
#define ENET_MMC_RX_INTERRUPT_RXBCGPIS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_RX_INTERRUPT_RXBCGPIS_SHIFT))&ENET_MMC_RX_INTERRUPT_RXBCGPIS_MASK)
#define ENET_MMC_RX_INTERRUPT_RXGOCTIS_MASK 0x4u
#define ENET_MMC_RX_INTERRUPT_RXGOCTIS_SHIFT 2u
#define ENET_MMC_RX_INTERRUPT_RXGOCTIS_WIDTH 1u
#define ENET_MMC_RX_INTERRUPT_RXGOCTIS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_RX_INTERRUPT_RXGOCTIS_SHIFT))&ENET_MMC_RX_INTERRUPT_RXGOCTIS_MASK)
#define ENET_MMC_RX_INTERRUPT_RXGBOCTIS_MASK 0x2u
#define ENET_MMC_RX_INTERRUPT_RXGBOCTIS_SHIFT 1u
#define ENET_MMC_RX_INTERRUPT_RXGBOCTIS_WIDTH 1u
#define ENET_MMC_RX_INTERRUPT_RXGBOCTIS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_RX_INTERRUPT_RXGBOCTIS_SHIFT))&ENET_MMC_RX_INTERRUPT_RXGBOCTIS_MASK)
#define ENET_MMC_RX_INTERRUPT_RXGBPKTIS_MASK 0x1u
#define ENET_MMC_RX_INTERRUPT_RXGBPKTIS_SHIFT 0u
#define ENET_MMC_RX_INTERRUPT_RXGBPKTIS_WIDTH 1u
#define ENET_MMC_RX_INTERRUPT_RXGBPKTIS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_RX_INTERRUPT_RXGBPKTIS_SHIFT))&ENET_MMC_RX_INTERRUPT_RXGBPKTIS_MASK)
/* MMC_RX_INTERRUPT Reg Mask */
#define ENET_MMC_RX_INTERRUPT_MASK     0x03FFFFFFu

/* MMC_TX_INTERRUPT Bit Fields */
#define ENET_MMC_TX_INTERRUPT_TXOSIZEGPIS_MASK 0x2000000u
#define ENET_MMC_TX_INTERRUPT_TXOSIZEGPIS_SHIFT 25u
#define ENET_MMC_TX_INTERRUPT_TXOSIZEGPIS_WIDTH 1u
#define ENET_MMC_TX_INTERRUPT_TXOSIZEGPIS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_TX_INTERRUPT_TXOSIZEGPIS_SHIFT))&ENET_MMC_TX_INTERRUPT_TXOSIZEGPIS_MASK)
#define ENET_MMC_TX_INTERRUPT_TXVLANGPIS_MASK 0x1000000u
#define ENET_MMC_TX_INTERRUPT_TXVLANGPIS_SHIFT 24u
#define ENET_MMC_TX_INTERRUPT_TXVLANGPIS_WIDTH 1u
#define ENET_MMC_TX_INTERRUPT_TXVLANGPIS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_TX_INTERRUPT_TXVLANGPIS_SHIFT))&ENET_MMC_TX_INTERRUPT_TXVLANGPIS_MASK)
#define ENET_MMC_TX_INTERRUPT_TXPAUSPIS_MASK 0x800000u
#define ENET_MMC_TX_INTERRUPT_TXPAUSPIS_SHIFT 23u
#define ENET_MMC_TX_INTERRUPT_TXPAUSPIS_WIDTH 1u
#define ENET_MMC_TX_INTERRUPT_TXPAUSPIS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_TX_INTERRUPT_TXPAUSPIS_SHIFT))&ENET_MMC_TX_INTERRUPT_TXPAUSPIS_MASK)
#define ENET_MMC_TX_INTERRUPT_TXEXDEFPIS_MASK 0x400000u
#define ENET_MMC_TX_INTERRUPT_TXEXDEFPIS_SHIFT 22u
#define ENET_MMC_TX_INTERRUPT_TXEXDEFPIS_WIDTH 1u
#define ENET_MMC_TX_INTERRUPT_TXEXDEFPIS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_TX_INTERRUPT_TXEXDEFPIS_SHIFT))&ENET_MMC_TX_INTERRUPT_TXEXDEFPIS_MASK)
#define ENET_MMC_TX_INTERRUPT_TXGPKTIS_MASK 0x200000u
#define ENET_MMC_TX_INTERRUPT_TXGPKTIS_SHIFT 21u
#define ENET_MMC_TX_INTERRUPT_TXGPKTIS_WIDTH 1u
#define ENET_MMC_TX_INTERRUPT_TXGPKTIS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_TX_INTERRUPT_TXGPKTIS_SHIFT))&ENET_MMC_TX_INTERRUPT_TXGPKTIS_MASK)
#define ENET_MMC_TX_INTERRUPT_TXGOCTIS_MASK 0x100000u
#define ENET_MMC_TX_INTERRUPT_TXGOCTIS_SHIFT 20u
#define ENET_MMC_TX_INTERRUPT_TXGOCTIS_WIDTH 1u
#define ENET_MMC_TX_INTERRUPT_TXGOCTIS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_TX_INTERRUPT_TXGOCTIS_SHIFT))&ENET_MMC_TX_INTERRUPT_TXGOCTIS_MASK)
#define ENET_MMC_TX_INTERRUPT_TXCARERPIS_MASK 0x80000u
#define ENET_MMC_TX_INTERRUPT_TXCARERPIS_SHIFT 19u
#define ENET_MMC_TX_INTERRUPT_TXCARERPIS_WIDTH 1u
#define ENET_MMC_TX_INTERRUPT_TXCARERPIS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_TX_INTERRUPT_TXCARERPIS_SHIFT))&ENET_MMC_TX_INTERRUPT_TXCARERPIS_MASK)
#define ENET_MMC_TX_INTERRUPT_TXEXCOLPIS_MASK 0x40000u
#define ENET_MMC_TX_INTERRUPT_TXEXCOLPIS_SHIFT 18u
#define ENET_MMC_TX_INTERRUPT_TXEXCOLPIS_WIDTH 1u
#define ENET_MMC_TX_INTERRUPT_TXEXCOLPIS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_TX_INTERRUPT_TXEXCOLPIS_SHIFT))&ENET_MMC_TX_INTERRUPT_TXEXCOLPIS_MASK)
#define ENET_MMC_TX_INTERRUPT_TXLATCOLPIS_MASK 0x20000u
#define ENET_MMC_TX_INTERRUPT_TXLATCOLPIS_SHIFT 17u
#define ENET_MMC_TX_INTERRUPT_TXLATCOLPIS_WIDTH 1u
#define ENET_MMC_TX_INTERRUPT_TXLATCOLPIS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_TX_INTERRUPT_TXLATCOLPIS_SHIFT))&ENET_MMC_TX_INTERRUPT_TXLATCOLPIS_MASK)
#define ENET_MMC_TX_INTERRUPT_TXDEFPIS_MASK 0x10000u
#define ENET_MMC_TX_INTERRUPT_TXDEFPIS_SHIFT 16u
#define ENET_MMC_TX_INTERRUPT_TXDEFPIS_WIDTH 1u
#define ENET_MMC_TX_INTERRUPT_TXDEFPIS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_TX_INTERRUPT_TXDEFPIS_SHIFT))&ENET_MMC_TX_INTERRUPT_TXDEFPIS_MASK)
#define ENET_MMC_TX_INTERRUPT_TXMCOLGPIS_MASK 0x8000u
#define ENET_MMC_TX_INTERRUPT_TXMCOLGPIS_SHIFT 15u
#define ENET_MMC_TX_INTERRUPT_TXMCOLGPIS_WIDTH 1u
#define ENET_MMC_TX_INTERRUPT_TXMCOLGPIS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_TX_INTERRUPT_TXMCOLGPIS_SHIFT))&ENET_MMC_TX_INTERRUPT_TXMCOLGPIS_MASK)
#define ENET_MMC_TX_INTERRUPT_TXSCOLGPIS_MASK 0x4000u
#define ENET_MMC_TX_INTERRUPT_TXSCOLGPIS_SHIFT 14u
#define ENET_MMC_TX_INTERRUPT_TXSCOLGPIS_WIDTH 1u
#define ENET_MMC_TX_INTERRUPT_TXSCOLGPIS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_TX_INTERRUPT_TXSCOLGPIS_SHIFT))&ENET_MMC_TX_INTERRUPT_TXSCOLGPIS_MASK)
#define ENET_MMC_TX_INTERRUPT_TXUFLOWERPIS_MASK 0x2000u
#define ENET_MMC_TX_INTERRUPT_TXUFLOWERPIS_SHIFT 13u
#define ENET_MMC_TX_INTERRUPT_TXUFLOWERPIS_WIDTH 1u
#define ENET_MMC_TX_INTERRUPT_TXUFLOWERPIS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_TX_INTERRUPT_TXUFLOWERPIS_SHIFT))&ENET_MMC_TX_INTERRUPT_TXUFLOWERPIS_MASK)
#define ENET_MMC_TX_INTERRUPT_TXBCGBPIS_MASK 0x1000u
#define ENET_MMC_TX_INTERRUPT_TXBCGBPIS_SHIFT 12u
#define ENET_MMC_TX_INTERRUPT_TXBCGBPIS_WIDTH 1u
#define ENET_MMC_TX_INTERRUPT_TXBCGBPIS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_TX_INTERRUPT_TXBCGBPIS_SHIFT))&ENET_MMC_TX_INTERRUPT_TXBCGBPIS_MASK)
#define ENET_MMC_TX_INTERRUPT_TXMCGBPIS_MASK 0x800u
#define ENET_MMC_TX_INTERRUPT_TXMCGBPIS_SHIFT 11u
#define ENET_MMC_TX_INTERRUPT_TXMCGBPIS_WIDTH 1u
#define ENET_MMC_TX_INTERRUPT_TXMCGBPIS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_TX_INTERRUPT_TXMCGBPIS_SHIFT))&ENET_MMC_TX_INTERRUPT_TXMCGBPIS_MASK)
#define ENET_MMC_TX_INTERRUPT_TXUCGBPIS_MASK 0x400u
#define ENET_MMC_TX_INTERRUPT_TXUCGBPIS_SHIFT 10u
#define ENET_MMC_TX_INTERRUPT_TXUCGBPIS_WIDTH 1u
#define ENET_MMC_TX_INTERRUPT_TXUCGBPIS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_TX_INTERRUPT_TXUCGBPIS_SHIFT))&ENET_MMC_TX_INTERRUPT_TXUCGBPIS_MASK)
#define ENET_MMC_TX_INTERRUPT_TX1024TMAXOCTGBPIS_MASK 0x200u
#define ENET_MMC_TX_INTERRUPT_TX1024TMAXOCTGBPIS_SHIFT 9u
#define ENET_MMC_TX_INTERRUPT_TX1024TMAXOCTGBPIS_WIDTH 1u
#define ENET_MMC_TX_INTERRUPT_TX1024TMAXOCTGBPIS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_TX_INTERRUPT_TX1024TMAXOCTGBPIS_SHIFT))&ENET_MMC_TX_INTERRUPT_TX1024TMAXOCTGBPIS_MASK)
#define ENET_MMC_TX_INTERRUPT_TX512T1023OCTGBPIS_MASK 0x100u
#define ENET_MMC_TX_INTERRUPT_TX512T1023OCTGBPIS_SHIFT 8u
#define ENET_MMC_TX_INTERRUPT_TX512T1023OCTGBPIS_WIDTH 1u
#define ENET_MMC_TX_INTERRUPT_TX512T1023OCTGBPIS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_TX_INTERRUPT_TX512T1023OCTGBPIS_SHIFT))&ENET_MMC_TX_INTERRUPT_TX512T1023OCTGBPIS_MASK)
#define ENET_MMC_TX_INTERRUPT_TX256T511OCTGBPIS_MASK 0x80u
#define ENET_MMC_TX_INTERRUPT_TX256T511OCTGBPIS_SHIFT 7u
#define ENET_MMC_TX_INTERRUPT_TX256T511OCTGBPIS_WIDTH 1u
#define ENET_MMC_TX_INTERRUPT_TX256T511OCTGBPIS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_TX_INTERRUPT_TX256T511OCTGBPIS_SHIFT))&ENET_MMC_TX_INTERRUPT_TX256T511OCTGBPIS_MASK)
#define ENET_MMC_TX_INTERRUPT_TX128T255OCTGBPIS_MASK 0x40u
#define ENET_MMC_TX_INTERRUPT_TX128T255OCTGBPIS_SHIFT 6u
#define ENET_MMC_TX_INTERRUPT_TX128T255OCTGBPIS_WIDTH 1u
#define ENET_MMC_TX_INTERRUPT_TX128T255OCTGBPIS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_TX_INTERRUPT_TX128T255OCTGBPIS_SHIFT))&ENET_MMC_TX_INTERRUPT_TX128T255OCTGBPIS_MASK)
#define ENET_MMC_TX_INTERRUPT_TX65T127OCTGBPIS_MASK 0x20u
#define ENET_MMC_TX_INTERRUPT_TX65T127OCTGBPIS_SHIFT 5u
#define ENET_MMC_TX_INTERRUPT_TX65T127OCTGBPIS_WIDTH 1u
#define ENET_MMC_TX_INTERRUPT_TX65T127OCTGBPIS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_TX_INTERRUPT_TX65T127OCTGBPIS_SHIFT))&ENET_MMC_TX_INTERRUPT_TX65T127OCTGBPIS_MASK)
#define ENET_MMC_TX_INTERRUPT_TX64OCTGBPIS_MASK 0x10u
#define ENET_MMC_TX_INTERRUPT_TX64OCTGBPIS_SHIFT 4u
#define ENET_MMC_TX_INTERRUPT_TX64OCTGBPIS_WIDTH 1u
#define ENET_MMC_TX_INTERRUPT_TX64OCTGBPIS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_TX_INTERRUPT_TX64OCTGBPIS_SHIFT))&ENET_MMC_TX_INTERRUPT_TX64OCTGBPIS_MASK)
#define ENET_MMC_TX_INTERRUPT_TXMCGPIS_MASK 0x8u
#define ENET_MMC_TX_INTERRUPT_TXMCGPIS_SHIFT 3u
#define ENET_MMC_TX_INTERRUPT_TXMCGPIS_WIDTH 1u
#define ENET_MMC_TX_INTERRUPT_TXMCGPIS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_TX_INTERRUPT_TXMCGPIS_SHIFT))&ENET_MMC_TX_INTERRUPT_TXMCGPIS_MASK)
#define ENET_MMC_TX_INTERRUPT_TXBCGPIS_MASK 0x4u
#define ENET_MMC_TX_INTERRUPT_TXBCGPIS_SHIFT 2u
#define ENET_MMC_TX_INTERRUPT_TXBCGPIS_WIDTH 1u
#define ENET_MMC_TX_INTERRUPT_TXBCGPIS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_TX_INTERRUPT_TXBCGPIS_SHIFT))&ENET_MMC_TX_INTERRUPT_TXBCGPIS_MASK)
#define ENET_MMC_TX_INTERRUPT_TXGBPKTIS_MASK 0x2u
#define ENET_MMC_TX_INTERRUPT_TXGBPKTIS_SHIFT 1u
#define ENET_MMC_TX_INTERRUPT_TXGBPKTIS_WIDTH 1u
#define ENET_MMC_TX_INTERRUPT_TXGBPKTIS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_TX_INTERRUPT_TXGBPKTIS_SHIFT))&ENET_MMC_TX_INTERRUPT_TXGBPKTIS_MASK)
#define ENET_MMC_TX_INTERRUPT_TXGBOCTIS_MASK 0x1u
#define ENET_MMC_TX_INTERRUPT_TXGBOCTIS_SHIFT 0u
#define ENET_MMC_TX_INTERRUPT_TXGBOCTIS_WIDTH 1u
#define ENET_MMC_TX_INTERRUPT_TXGBOCTIS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_TX_INTERRUPT_TXGBOCTIS_SHIFT))&ENET_MMC_TX_INTERRUPT_TXGBOCTIS_MASK)
/* MMC_TX_INTERRUPT Reg Mask */
#define ENET_MMC_TX_INTERRUPT_MASK     0x03FFFFFFu

/* MMC_RX_INTERRUPT_MASK Bit Fields */
#define ENET_MMC_RX_INTERRUPT_MASK_RXCTRLPIM_MASK 0x2000000u
#define ENET_MMC_RX_INTERRUPT_MASK_RXCTRLPIM_SHIFT 25u
#define ENET_MMC_RX_INTERRUPT_MASK_RXCTRLPIM_WIDTH 1u
#define ENET_MMC_RX_INTERRUPT_MASK_RXCTRLPIM(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_RX_INTERRUPT_MASK_RXCTRLPIM_SHIFT))&ENET_MMC_RX_INTERRUPT_MASK_RXCTRLPIM_MASK)
#define ENET_MMC_RX_INTERRUPT_MASK_RXRCVERRPIM_MASK 0x1000000u
#define ENET_MMC_RX_INTERRUPT_MASK_RXRCVERRPIM_SHIFT 24u
#define ENET_MMC_RX_INTERRUPT_MASK_RXRCVERRPIM_WIDTH 1u
#define ENET_MMC_RX_INTERRUPT_MASK_RXRCVERRPIM(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_RX_INTERRUPT_MASK_RXRCVERRPIM_SHIFT))&ENET_MMC_RX_INTERRUPT_MASK_RXRCVERRPIM_MASK)
#define ENET_MMC_RX_INTERRUPT_MASK_RXWDOGPIM_MASK 0x800000u
#define ENET_MMC_RX_INTERRUPT_MASK_RXWDOGPIM_SHIFT 23u
#define ENET_MMC_RX_INTERRUPT_MASK_RXWDOGPIM_WIDTH 1u
#define ENET_MMC_RX_INTERRUPT_MASK_RXWDOGPIM(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_RX_INTERRUPT_MASK_RXWDOGPIM_SHIFT))&ENET_MMC_RX_INTERRUPT_MASK_RXWDOGPIM_MASK)
#define ENET_MMC_RX_INTERRUPT_MASK_RXVLANGBPIM_MASK 0x400000u
#define ENET_MMC_RX_INTERRUPT_MASK_RXVLANGBPIM_SHIFT 22u
#define ENET_MMC_RX_INTERRUPT_MASK_RXVLANGBPIM_WIDTH 1u
#define ENET_MMC_RX_INTERRUPT_MASK_RXVLANGBPIM(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_RX_INTERRUPT_MASK_RXVLANGBPIM_SHIFT))&ENET_MMC_RX_INTERRUPT_MASK_RXVLANGBPIM_MASK)
#define ENET_MMC_RX_INTERRUPT_MASK_RXFOVPIM_MASK 0x200000u
#define ENET_MMC_RX_INTERRUPT_MASK_RXFOVPIM_SHIFT 21u
#define ENET_MMC_RX_INTERRUPT_MASK_RXFOVPIM_WIDTH 1u
#define ENET_MMC_RX_INTERRUPT_MASK_RXFOVPIM(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_RX_INTERRUPT_MASK_RXFOVPIM_SHIFT))&ENET_MMC_RX_INTERRUPT_MASK_RXFOVPIM_MASK)
#define ENET_MMC_RX_INTERRUPT_MASK_RXPAUSPIM_MASK 0x100000u
#define ENET_MMC_RX_INTERRUPT_MASK_RXPAUSPIM_SHIFT 20u
#define ENET_MMC_RX_INTERRUPT_MASK_RXPAUSPIM_WIDTH 1u
#define ENET_MMC_RX_INTERRUPT_MASK_RXPAUSPIM(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_RX_INTERRUPT_MASK_RXPAUSPIM_SHIFT))&ENET_MMC_RX_INTERRUPT_MASK_RXPAUSPIM_MASK)
#define ENET_MMC_RX_INTERRUPT_MASK_RXORANGEPIM_MASK 0x80000u
#define ENET_MMC_RX_INTERRUPT_MASK_RXORANGEPIM_SHIFT 19u
#define ENET_MMC_RX_INTERRUPT_MASK_RXORANGEPIM_WIDTH 1u
#define ENET_MMC_RX_INTERRUPT_MASK_RXORANGEPIM(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_RX_INTERRUPT_MASK_RXORANGEPIM_SHIFT))&ENET_MMC_RX_INTERRUPT_MASK_RXORANGEPIM_MASK)
#define ENET_MMC_RX_INTERRUPT_MASK_RXLENERPIM_MASK 0x40000u
#define ENET_MMC_RX_INTERRUPT_MASK_RXLENERPIM_SHIFT 18u
#define ENET_MMC_RX_INTERRUPT_MASK_RXLENERPIM_WIDTH 1u
#define ENET_MMC_RX_INTERRUPT_MASK_RXLENERPIM(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_RX_INTERRUPT_MASK_RXLENERPIM_SHIFT))&ENET_MMC_RX_INTERRUPT_MASK_RXLENERPIM_MASK)
#define ENET_MMC_RX_INTERRUPT_MASK_RXUCGPIM_MASK 0x20000u
#define ENET_MMC_RX_INTERRUPT_MASK_RXUCGPIM_SHIFT 17u
#define ENET_MMC_RX_INTERRUPT_MASK_RXUCGPIM_WIDTH 1u
#define ENET_MMC_RX_INTERRUPT_MASK_RXUCGPIM(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_RX_INTERRUPT_MASK_RXUCGPIM_SHIFT))&ENET_MMC_RX_INTERRUPT_MASK_RXUCGPIM_MASK)
#define ENET_MMC_RX_INTERRUPT_MASK_RX1024TMAXOCTGBPIM_MASK 0x10000u
#define ENET_MMC_RX_INTERRUPT_MASK_RX1024TMAXOCTGBPIM_SHIFT 16u
#define ENET_MMC_RX_INTERRUPT_MASK_RX1024TMAXOCTGBPIM_WIDTH 1u
#define ENET_MMC_RX_INTERRUPT_MASK_RX1024TMAXOCTGBPIM(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_RX_INTERRUPT_MASK_RX1024TMAXOCTGBPIM_SHIFT))&ENET_MMC_RX_INTERRUPT_MASK_RX1024TMAXOCTGBPIM_MASK)
#define ENET_MMC_RX_INTERRUPT_MASK_RX512T1023OCTGBPIM_MASK 0x8000u
#define ENET_MMC_RX_INTERRUPT_MASK_RX512T1023OCTGBPIM_SHIFT 15u
#define ENET_MMC_RX_INTERRUPT_MASK_RX512T1023OCTGBPIM_WIDTH 1u
#define ENET_MMC_RX_INTERRUPT_MASK_RX512T1023OCTGBPIM(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_RX_INTERRUPT_MASK_RX512T1023OCTGBPIM_SHIFT))&ENET_MMC_RX_INTERRUPT_MASK_RX512T1023OCTGBPIM_MASK)
#define ENET_MMC_RX_INTERRUPT_MASK_RX256T511OCTGBPIM_MASK 0x4000u
#define ENET_MMC_RX_INTERRUPT_MASK_RX256T511OCTGBPIM_SHIFT 14u
#define ENET_MMC_RX_INTERRUPT_MASK_RX256T511OCTGBPIM_WIDTH 1u
#define ENET_MMC_RX_INTERRUPT_MASK_RX256T511OCTGBPIM(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_RX_INTERRUPT_MASK_RX256T511OCTGBPIM_SHIFT))&ENET_MMC_RX_INTERRUPT_MASK_RX256T511OCTGBPIM_MASK)
#define ENET_MMC_RX_INTERRUPT_MASK_RX128T255OCTGBPIM_MASK 0x2000u
#define ENET_MMC_RX_INTERRUPT_MASK_RX128T255OCTGBPIM_SHIFT 13u
#define ENET_MMC_RX_INTERRUPT_MASK_RX128T255OCTGBPIM_WIDTH 1u
#define ENET_MMC_RX_INTERRUPT_MASK_RX128T255OCTGBPIM(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_RX_INTERRUPT_MASK_RX128T255OCTGBPIM_SHIFT))&ENET_MMC_RX_INTERRUPT_MASK_RX128T255OCTGBPIM_MASK)
#define ENET_MMC_RX_INTERRUPT_MASK_RX65T127OCTGBPIM_MASK 0x1000u
#define ENET_MMC_RX_INTERRUPT_MASK_RX65T127OCTGBPIM_SHIFT 12u
#define ENET_MMC_RX_INTERRUPT_MASK_RX65T127OCTGBPIM_WIDTH 1u
#define ENET_MMC_RX_INTERRUPT_MASK_RX65T127OCTGBPIM(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_RX_INTERRUPT_MASK_RX65T127OCTGBPIM_SHIFT))&ENET_MMC_RX_INTERRUPT_MASK_RX65T127OCTGBPIM_MASK)
#define ENET_MMC_RX_INTERRUPT_MASK_RX64OCTGBPIM_MASK 0x800u
#define ENET_MMC_RX_INTERRUPT_MASK_RX64OCTGBPIM_SHIFT 11u
#define ENET_MMC_RX_INTERRUPT_MASK_RX64OCTGBPIM_WIDTH 1u
#define ENET_MMC_RX_INTERRUPT_MASK_RX64OCTGBPIM(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_RX_INTERRUPT_MASK_RX64OCTGBPIM_SHIFT))&ENET_MMC_RX_INTERRUPT_MASK_RX64OCTGBPIM_MASK)
#define ENET_MMC_RX_INTERRUPT_MASK_RXOSIZEGPIM_MASK 0x400u
#define ENET_MMC_RX_INTERRUPT_MASK_RXOSIZEGPIM_SHIFT 10u
#define ENET_MMC_RX_INTERRUPT_MASK_RXOSIZEGPIM_WIDTH 1u
#define ENET_MMC_RX_INTERRUPT_MASK_RXOSIZEGPIM(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_RX_INTERRUPT_MASK_RXOSIZEGPIM_SHIFT))&ENET_MMC_RX_INTERRUPT_MASK_RXOSIZEGPIM_MASK)
#define ENET_MMC_RX_INTERRUPT_MASK_RXUSIZEGPIM_MASK 0x200u
#define ENET_MMC_RX_INTERRUPT_MASK_RXUSIZEGPIM_SHIFT 9u
#define ENET_MMC_RX_INTERRUPT_MASK_RXUSIZEGPIM_WIDTH 1u
#define ENET_MMC_RX_INTERRUPT_MASK_RXUSIZEGPIM(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_RX_INTERRUPT_MASK_RXUSIZEGPIM_SHIFT))&ENET_MMC_RX_INTERRUPT_MASK_RXUSIZEGPIM_MASK)
#define ENET_MMC_RX_INTERRUPT_MASK_RXJABERPIM_MASK 0x100u
#define ENET_MMC_RX_INTERRUPT_MASK_RXJABERPIM_SHIFT 8u
#define ENET_MMC_RX_INTERRUPT_MASK_RXJABERPIM_WIDTH 1u
#define ENET_MMC_RX_INTERRUPT_MASK_RXJABERPIM(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_RX_INTERRUPT_MASK_RXJABERPIM_SHIFT))&ENET_MMC_RX_INTERRUPT_MASK_RXJABERPIM_MASK)
#define ENET_MMC_RX_INTERRUPT_MASK_RXRUNTPIM_MASK 0x80u
#define ENET_MMC_RX_INTERRUPT_MASK_RXRUNTPIM_SHIFT 7u
#define ENET_MMC_RX_INTERRUPT_MASK_RXRUNTPIM_WIDTH 1u
#define ENET_MMC_RX_INTERRUPT_MASK_RXRUNTPIM(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_RX_INTERRUPT_MASK_RXRUNTPIM_SHIFT))&ENET_MMC_RX_INTERRUPT_MASK_RXRUNTPIM_MASK)
#define ENET_MMC_RX_INTERRUPT_MASK_RXALGNERPIM_MASK 0x40u
#define ENET_MMC_RX_INTERRUPT_MASK_RXALGNERPIM_SHIFT 6u
#define ENET_MMC_RX_INTERRUPT_MASK_RXALGNERPIM_WIDTH 1u
#define ENET_MMC_RX_INTERRUPT_MASK_RXALGNERPIM(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_RX_INTERRUPT_MASK_RXALGNERPIM_SHIFT))&ENET_MMC_RX_INTERRUPT_MASK_RXALGNERPIM_MASK)
#define ENET_MMC_RX_INTERRUPT_MASK_RXCRCERPIM_MASK 0x20u
#define ENET_MMC_RX_INTERRUPT_MASK_RXCRCERPIM_SHIFT 5u
#define ENET_MMC_RX_INTERRUPT_MASK_RXCRCERPIM_WIDTH 1u
#define ENET_MMC_RX_INTERRUPT_MASK_RXCRCERPIM(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_RX_INTERRUPT_MASK_RXCRCERPIM_SHIFT))&ENET_MMC_RX_INTERRUPT_MASK_RXCRCERPIM_MASK)
#define ENET_MMC_RX_INTERRUPT_MASK_RXMCGPIM_MASK 0x10u
#define ENET_MMC_RX_INTERRUPT_MASK_RXMCGPIM_SHIFT 4u
#define ENET_MMC_RX_INTERRUPT_MASK_RXMCGPIM_WIDTH 1u
#define ENET_MMC_RX_INTERRUPT_MASK_RXMCGPIM(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_RX_INTERRUPT_MASK_RXMCGPIM_SHIFT))&ENET_MMC_RX_INTERRUPT_MASK_RXMCGPIM_MASK)
#define ENET_MMC_RX_INTERRUPT_MASK_RXBCGPIM_MASK 0x8u
#define ENET_MMC_RX_INTERRUPT_MASK_RXBCGPIM_SHIFT 3u
#define ENET_MMC_RX_INTERRUPT_MASK_RXBCGPIM_WIDTH 1u
#define ENET_MMC_RX_INTERRUPT_MASK_RXBCGPIM(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_RX_INTERRUPT_MASK_RXBCGPIM_SHIFT))&ENET_MMC_RX_INTERRUPT_MASK_RXBCGPIM_MASK)
#define ENET_MMC_RX_INTERRUPT_MASK_RXGOCTIM_MASK 0x4u
#define ENET_MMC_RX_INTERRUPT_MASK_RXGOCTIM_SHIFT 2u
#define ENET_MMC_RX_INTERRUPT_MASK_RXGOCTIM_WIDTH 1u
#define ENET_MMC_RX_INTERRUPT_MASK_RXGOCTIM(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_RX_INTERRUPT_MASK_RXGOCTIM_SHIFT))&ENET_MMC_RX_INTERRUPT_MASK_RXGOCTIM_MASK)
#define ENET_MMC_RX_INTERRUPT_MASK_RXGBOCTIM_MASK 0x2u
#define ENET_MMC_RX_INTERRUPT_MASK_RXGBOCTIM_SHIFT 1u
#define ENET_MMC_RX_INTERRUPT_MASK_RXGBOCTIM_WIDTH 1u
#define ENET_MMC_RX_INTERRUPT_MASK_RXGBOCTIM(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_RX_INTERRUPT_MASK_RXGBOCTIM_SHIFT))&ENET_MMC_RX_INTERRUPT_MASK_RXGBOCTIM_MASK)
#define ENET_MMC_RX_INTERRUPT_MASK_RXGBPKTIM_MASK 0x1u
#define ENET_MMC_RX_INTERRUPT_MASK_RXGBPKTIM_SHIFT 0u
#define ENET_MMC_RX_INTERRUPT_MASK_RXGBPKTIM_WIDTH 1u
#define ENET_MMC_RX_INTERRUPT_MASK_RXGBPKTIM(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_RX_INTERRUPT_MASK_RXGBPKTIM_SHIFT))&ENET_MMC_RX_INTERRUPT_MASK_RXGBPKTIM_MASK)
/* MMC_RX_INTERRUPT_MASK Reg Mask */
#define ENET_MMC_RX_INTERRUPT_MASK_MASK 0x03FFFFFFu

/* MMC_TX_INTERRUPT_MASK Bit Fields */
#define ENET_MMC_TX_INTERRUPT_MASK_TXOSIZEGPIM_MASK 0x2000000u
#define ENET_MMC_TX_INTERRUPT_MASK_TXOSIZEGPIM_SHIFT 25u
#define ENET_MMC_TX_INTERRUPT_MASK_TXOSIZEGPIM_WIDTH 1u
#define ENET_MMC_TX_INTERRUPT_MASK_TXOSIZEGPIM(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_TX_INTERRUPT_MASK_TXOSIZEGPIM_SHIFT))&ENET_MMC_TX_INTERRUPT_MASK_TXOSIZEGPIM_MASK)
#define ENET_MMC_TX_INTERRUPT_MASK_TXVLANGPIM_MASK 0x1000000u
#define ENET_MMC_TX_INTERRUPT_MASK_TXVLANGPIM_SHIFT 24u
#define ENET_MMC_TX_INTERRUPT_MASK_TXVLANGPIM_WIDTH 1u
#define ENET_MMC_TX_INTERRUPT_MASK_TXVLANGPIM(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_TX_INTERRUPT_MASK_TXVLANGPIM_SHIFT))&ENET_MMC_TX_INTERRUPT_MASK_TXVLANGPIM_MASK)
#define ENET_MMC_TX_INTERRUPT_MASK_TXPAUSPIM_MASK 0x800000u
#define ENET_MMC_TX_INTERRUPT_MASK_TXPAUSPIM_SHIFT 23u
#define ENET_MMC_TX_INTERRUPT_MASK_TXPAUSPIM_WIDTH 1u
#define ENET_MMC_TX_INTERRUPT_MASK_TXPAUSPIM(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_TX_INTERRUPT_MASK_TXPAUSPIM_SHIFT))&ENET_MMC_TX_INTERRUPT_MASK_TXPAUSPIM_MASK)
#define ENET_MMC_TX_INTERRUPT_MASK_TXEXDEFPIM_MASK 0x400000u
#define ENET_MMC_TX_INTERRUPT_MASK_TXEXDEFPIM_SHIFT 22u
#define ENET_MMC_TX_INTERRUPT_MASK_TXEXDEFPIM_WIDTH 1u
#define ENET_MMC_TX_INTERRUPT_MASK_TXEXDEFPIM(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_TX_INTERRUPT_MASK_TXEXDEFPIM_SHIFT))&ENET_MMC_TX_INTERRUPT_MASK_TXEXDEFPIM_MASK)
#define ENET_MMC_TX_INTERRUPT_MASK_TXGPKTIM_MASK 0x200000u
#define ENET_MMC_TX_INTERRUPT_MASK_TXGPKTIM_SHIFT 21u
#define ENET_MMC_TX_INTERRUPT_MASK_TXGPKTIM_WIDTH 1u
#define ENET_MMC_TX_INTERRUPT_MASK_TXGPKTIM(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_TX_INTERRUPT_MASK_TXGPKTIM_SHIFT))&ENET_MMC_TX_INTERRUPT_MASK_TXGPKTIM_MASK)
#define ENET_MMC_TX_INTERRUPT_MASK_TXGOCTIM_MASK 0x100000u
#define ENET_MMC_TX_INTERRUPT_MASK_TXGOCTIM_SHIFT 20u
#define ENET_MMC_TX_INTERRUPT_MASK_TXGOCTIM_WIDTH 1u
#define ENET_MMC_TX_INTERRUPT_MASK_TXGOCTIM(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_TX_INTERRUPT_MASK_TXGOCTIM_SHIFT))&ENET_MMC_TX_INTERRUPT_MASK_TXGOCTIM_MASK)
#define ENET_MMC_TX_INTERRUPT_MASK_TXCARERPIM_MASK 0x80000u
#define ENET_MMC_TX_INTERRUPT_MASK_TXCARERPIM_SHIFT 19u
#define ENET_MMC_TX_INTERRUPT_MASK_TXCARERPIM_WIDTH 1u
#define ENET_MMC_TX_INTERRUPT_MASK_TXCARERPIM(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_TX_INTERRUPT_MASK_TXCARERPIM_SHIFT))&ENET_MMC_TX_INTERRUPT_MASK_TXCARERPIM_MASK)
#define ENET_MMC_TX_INTERRUPT_MASK_TXEXCOLPIM_MASK 0x40000u
#define ENET_MMC_TX_INTERRUPT_MASK_TXEXCOLPIM_SHIFT 18u
#define ENET_MMC_TX_INTERRUPT_MASK_TXEXCOLPIM_WIDTH 1u
#define ENET_MMC_TX_INTERRUPT_MASK_TXEXCOLPIM(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_TX_INTERRUPT_MASK_TXEXCOLPIM_SHIFT))&ENET_MMC_TX_INTERRUPT_MASK_TXEXCOLPIM_MASK)
#define ENET_MMC_TX_INTERRUPT_MASK_TXLATCOLPIM_MASK 0x20000u
#define ENET_MMC_TX_INTERRUPT_MASK_TXLATCOLPIM_SHIFT 17u
#define ENET_MMC_TX_INTERRUPT_MASK_TXLATCOLPIM_WIDTH 1u
#define ENET_MMC_TX_INTERRUPT_MASK_TXLATCOLPIM(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_TX_INTERRUPT_MASK_TXLATCOLPIM_SHIFT))&ENET_MMC_TX_INTERRUPT_MASK_TXLATCOLPIM_MASK)
#define ENET_MMC_TX_INTERRUPT_MASK_TXDEFPIM_MASK 0x10000u
#define ENET_MMC_TX_INTERRUPT_MASK_TXDEFPIM_SHIFT 16u
#define ENET_MMC_TX_INTERRUPT_MASK_TXDEFPIM_WIDTH 1u
#define ENET_MMC_TX_INTERRUPT_MASK_TXDEFPIM(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_TX_INTERRUPT_MASK_TXDEFPIM_SHIFT))&ENET_MMC_TX_INTERRUPT_MASK_TXDEFPIM_MASK)
#define ENET_MMC_TX_INTERRUPT_MASK_TXMCOLGPIM_MASK 0x8000u
#define ENET_MMC_TX_INTERRUPT_MASK_TXMCOLGPIM_SHIFT 15u
#define ENET_MMC_TX_INTERRUPT_MASK_TXMCOLGPIM_WIDTH 1u
#define ENET_MMC_TX_INTERRUPT_MASK_TXMCOLGPIM(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_TX_INTERRUPT_MASK_TXMCOLGPIM_SHIFT))&ENET_MMC_TX_INTERRUPT_MASK_TXMCOLGPIM_MASK)
#define ENET_MMC_TX_INTERRUPT_MASK_TXSCOLGPIM_MASK 0x4000u
#define ENET_MMC_TX_INTERRUPT_MASK_TXSCOLGPIM_SHIFT 14u
#define ENET_MMC_TX_INTERRUPT_MASK_TXSCOLGPIM_WIDTH 1u
#define ENET_MMC_TX_INTERRUPT_MASK_TXSCOLGPIM(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_TX_INTERRUPT_MASK_TXSCOLGPIM_SHIFT))&ENET_MMC_TX_INTERRUPT_MASK_TXSCOLGPIM_MASK)
#define ENET_MMC_TX_INTERRUPT_MASK_TXUFLOWERPIM_MASK 0x2000u
#define ENET_MMC_TX_INTERRUPT_MASK_TXUFLOWERPIM_SHIFT 13u
#define ENET_MMC_TX_INTERRUPT_MASK_TXUFLOWERPIM_WIDTH 1u
#define ENET_MMC_TX_INTERRUPT_MASK_TXUFLOWERPIM(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_TX_INTERRUPT_MASK_TXUFLOWERPIM_SHIFT))&ENET_MMC_TX_INTERRUPT_MASK_TXUFLOWERPIM_MASK)
#define ENET_MMC_TX_INTERRUPT_MASK_TXBCGBPIM_MASK 0x1000u
#define ENET_MMC_TX_INTERRUPT_MASK_TXBCGBPIM_SHIFT 12u
#define ENET_MMC_TX_INTERRUPT_MASK_TXBCGBPIM_WIDTH 1u
#define ENET_MMC_TX_INTERRUPT_MASK_TXBCGBPIM(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_TX_INTERRUPT_MASK_TXBCGBPIM_SHIFT))&ENET_MMC_TX_INTERRUPT_MASK_TXBCGBPIM_MASK)
#define ENET_MMC_TX_INTERRUPT_MASK_TXMCGBPIM_MASK 0x800u
#define ENET_MMC_TX_INTERRUPT_MASK_TXMCGBPIM_SHIFT 11u
#define ENET_MMC_TX_INTERRUPT_MASK_TXMCGBPIM_WIDTH 1u
#define ENET_MMC_TX_INTERRUPT_MASK_TXMCGBPIM(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_TX_INTERRUPT_MASK_TXMCGBPIM_SHIFT))&ENET_MMC_TX_INTERRUPT_MASK_TXMCGBPIM_MASK)
#define ENET_MMC_TX_INTERRUPT_MASK_TXUCGBPIM_MASK 0x400u
#define ENET_MMC_TX_INTERRUPT_MASK_TXUCGBPIM_SHIFT 10u
#define ENET_MMC_TX_INTERRUPT_MASK_TXUCGBPIM_WIDTH 1u
#define ENET_MMC_TX_INTERRUPT_MASK_TXUCGBPIM(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_TX_INTERRUPT_MASK_TXUCGBPIM_SHIFT))&ENET_MMC_TX_INTERRUPT_MASK_TXUCGBPIM_MASK)
#define ENET_MMC_TX_INTERRUPT_MASK_TX1024TMAXOCTGBPIM_MASK 0x200u
#define ENET_MMC_TX_INTERRUPT_MASK_TX1024TMAXOCTGBPIM_SHIFT 9u
#define ENET_MMC_TX_INTERRUPT_MASK_TX1024TMAXOCTGBPIM_WIDTH 1u
#define ENET_MMC_TX_INTERRUPT_MASK_TX1024TMAXOCTGBPIM(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_TX_INTERRUPT_MASK_TX1024TMAXOCTGBPIM_SHIFT))&ENET_MMC_TX_INTERRUPT_MASK_TX1024TMAXOCTGBPIM_MASK)
#define ENET_MMC_TX_INTERRUPT_MASK_TX512T1023OCTGBPIM_MASK 0x100u
#define ENET_MMC_TX_INTERRUPT_MASK_TX512T1023OCTGBPIM_SHIFT 8u
#define ENET_MMC_TX_INTERRUPT_MASK_TX512T1023OCTGBPIM_WIDTH 1u
#define ENET_MMC_TX_INTERRUPT_MASK_TX512T1023OCTGBPIM(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_TX_INTERRUPT_MASK_TX512T1023OCTGBPIM_SHIFT))&ENET_MMC_TX_INTERRUPT_MASK_TX512T1023OCTGBPIM_MASK)
#define ENET_MMC_TX_INTERRUPT_MASK_TX256T511OCTGBPIM_MASK 0x80u
#define ENET_MMC_TX_INTERRUPT_MASK_TX256T511OCTGBPIM_SHIFT 7u
#define ENET_MMC_TX_INTERRUPT_MASK_TX256T511OCTGBPIM_WIDTH 1u
#define ENET_MMC_TX_INTERRUPT_MASK_TX256T511OCTGBPIM(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_TX_INTERRUPT_MASK_TX256T511OCTGBPIM_SHIFT))&ENET_MMC_TX_INTERRUPT_MASK_TX256T511OCTGBPIM_MASK)
#define ENET_MMC_TX_INTERRUPT_MASK_TX128T255OCTGBPIM_MASK 0x40u
#define ENET_MMC_TX_INTERRUPT_MASK_TX128T255OCTGBPIM_SHIFT 6u
#define ENET_MMC_TX_INTERRUPT_MASK_TX128T255OCTGBPIM_WIDTH 1u
#define ENET_MMC_TX_INTERRUPT_MASK_TX128T255OCTGBPIM(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_TX_INTERRUPT_MASK_TX128T255OCTGBPIM_SHIFT))&ENET_MMC_TX_INTERRUPT_MASK_TX128T255OCTGBPIM_MASK)
#define ENET_MMC_TX_INTERRUPT_MASK_TX65T127OCTGBPIM_MASK 0x20u
#define ENET_MMC_TX_INTERRUPT_MASK_TX65T127OCTGBPIM_SHIFT 5u
#define ENET_MMC_TX_INTERRUPT_MASK_TX65T127OCTGBPIM_WIDTH 1u
#define ENET_MMC_TX_INTERRUPT_MASK_TX65T127OCTGBPIM(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_TX_INTERRUPT_MASK_TX65T127OCTGBPIM_SHIFT))&ENET_MMC_TX_INTERRUPT_MASK_TX65T127OCTGBPIM_MASK)
#define ENET_MMC_TX_INTERRUPT_MASK_TX64OCTGBPIM_MASK 0x10u
#define ENET_MMC_TX_INTERRUPT_MASK_TX64OCTGBPIM_SHIFT 4u
#define ENET_MMC_TX_INTERRUPT_MASK_TX64OCTGBPIM_WIDTH 1u
#define ENET_MMC_TX_INTERRUPT_MASK_TX64OCTGBPIM(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_TX_INTERRUPT_MASK_TX64OCTGBPIM_SHIFT))&ENET_MMC_TX_INTERRUPT_MASK_TX64OCTGBPIM_MASK)
#define ENET_MMC_TX_INTERRUPT_MASK_TXMCGPIM_MASK 0x8u
#define ENET_MMC_TX_INTERRUPT_MASK_TXMCGPIM_SHIFT 3u
#define ENET_MMC_TX_INTERRUPT_MASK_TXMCGPIM_WIDTH 1u
#define ENET_MMC_TX_INTERRUPT_MASK_TXMCGPIM(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_TX_INTERRUPT_MASK_TXMCGPIM_SHIFT))&ENET_MMC_TX_INTERRUPT_MASK_TXMCGPIM_MASK)
#define ENET_MMC_TX_INTERRUPT_MASK_TXBCGPIM_MASK 0x4u
#define ENET_MMC_TX_INTERRUPT_MASK_TXBCGPIM_SHIFT 2u
#define ENET_MMC_TX_INTERRUPT_MASK_TXBCGPIM_WIDTH 1u
#define ENET_MMC_TX_INTERRUPT_MASK_TXBCGPIM(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_TX_INTERRUPT_MASK_TXBCGPIM_SHIFT))&ENET_MMC_TX_INTERRUPT_MASK_TXBCGPIM_MASK)
#define ENET_MMC_TX_INTERRUPT_MASK_TXGBPKTIM_MASK 0x2u
#define ENET_MMC_TX_INTERRUPT_MASK_TXGBPKTIM_SHIFT 1u
#define ENET_MMC_TX_INTERRUPT_MASK_TXGBPKTIM_WIDTH 1u
#define ENET_MMC_TX_INTERRUPT_MASK_TXGBPKTIM(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_TX_INTERRUPT_MASK_TXGBPKTIM_SHIFT))&ENET_MMC_TX_INTERRUPT_MASK_TXGBPKTIM_MASK)
#define ENET_MMC_TX_INTERRUPT_MASK_TXGBOCTIM_MASK 0x1u
#define ENET_MMC_TX_INTERRUPT_MASK_TXGBOCTIM_SHIFT 0u
#define ENET_MMC_TX_INTERRUPT_MASK_TXGBOCTIM_WIDTH 1u
#define ENET_MMC_TX_INTERRUPT_MASK_TXGBOCTIM(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_TX_INTERRUPT_MASK_TXGBOCTIM_SHIFT))&ENET_MMC_TX_INTERRUPT_MASK_TXGBOCTIM_MASK)
/* MMC_TX_INTERRUPT_MASK Reg Mask */
#define ENET_MMC_TX_INTERRUPT_MASK_MASK 0x03FFFFFFu

/* TX_OCTET_COUNT_GOOD_BAD Bit Fields */
#define ENET_TX_OCTET_COUNT_GOOD_BAD_TXOCTGB_MASK 0xFFFFFFFFu
#define ENET_TX_OCTET_COUNT_GOOD_BAD_TXOCTGB_SHIFT 0u
#define ENET_TX_OCTET_COUNT_GOOD_BAD_TXOCTGB_WIDTH 32u
#define ENET_TX_OCTET_COUNT_GOOD_BAD_TXOCTGB(x) (((uint32_t)(((uint32_t)(x))<<ENET_TX_OCTET_COUNT_GOOD_BAD_TXOCTGB_SHIFT))&ENET_TX_OCTET_COUNT_GOOD_BAD_TXOCTGB_MASK)
/* TX_OCTET_COUNT_GOOD_BAD Reg Mask */
#define ENET_TX_OCTET_COUNT_GOOD_BAD_MASK 0xFFFFFFFFu

/* TX_PACKET_COUNT_GOOD_BAD Bit Fields */
#define ENET_TX_PACKET_COUNT_GOOD_BAD_TXPKTGB_MASK 0xFFFFFFFFu
#define ENET_TX_PACKET_COUNT_GOOD_BAD_TXPKTGB_SHIFT 0u
#define ENET_TX_PACKET_COUNT_GOOD_BAD_TXPKTGB_WIDTH 32u
#define ENET_TX_PACKET_COUNT_GOOD_BAD_TXPKTGB(x) (((uint32_t)(((uint32_t)(x))<<ENET_TX_PACKET_COUNT_GOOD_BAD_TXPKTGB_SHIFT))&ENET_TX_PACKET_COUNT_GOOD_BAD_TXPKTGB_MASK)
/* TX_PACKET_COUNT_GOOD_BAD Reg Mask */
#define ENET_TX_PACKET_COUNT_GOOD_BAD_MASK 0xFFFFFFFFu

/* TX_BROADCAST_PACKETS_GOOD Bit Fields */
#define ENET_TX_BROADCAST_PACKETS_GOOD_TXBCASTG_MASK 0xFFFFFFFFu
#define ENET_TX_BROADCAST_PACKETS_GOOD_TXBCASTG_SHIFT 0u
#define ENET_TX_BROADCAST_PACKETS_GOOD_TXBCASTG_WIDTH 32u
#define ENET_TX_BROADCAST_PACKETS_GOOD_TXBCASTG(x) (((uint32_t)(((uint32_t)(x))<<ENET_TX_BROADCAST_PACKETS_GOOD_TXBCASTG_SHIFT))&ENET_TX_BROADCAST_PACKETS_GOOD_TXBCASTG_MASK)
/* TX_BROADCAST_PACKETS_GOOD Reg Mask */
#define ENET_TX_BROADCAST_PACKETS_GOOD_MASK 0xFFFFFFFFu

/* TX_MULTICAST_PACKETS_GOOD Bit Fields */
#define ENET_TX_MULTICAST_PACKETS_GOOD_TXMCASTG_MASK 0xFFFFFFFFu
#define ENET_TX_MULTICAST_PACKETS_GOOD_TXMCASTG_SHIFT 0u
#define ENET_TX_MULTICAST_PACKETS_GOOD_TXMCASTG_WIDTH 32u
#define ENET_TX_MULTICAST_PACKETS_GOOD_TXMCASTG(x) (((uint32_t)(((uint32_t)(x))<<ENET_TX_MULTICAST_PACKETS_GOOD_TXMCASTG_SHIFT))&ENET_TX_MULTICAST_PACKETS_GOOD_TXMCASTG_MASK)
/* TX_MULTICAST_PACKETS_GOOD Reg Mask */
#define ENET_TX_MULTICAST_PACKETS_GOOD_MASK 0xFFFFFFFFu

/* TX_64OCTETS_PACKETS_GOOD_BAD Bit Fields */
#define ENET_TX_64OCTETS_PACKETS_GOOD_BAD_TX64OCTGB_MASK 0xFFFFFFFFu
#define ENET_TX_64OCTETS_PACKETS_GOOD_BAD_TX64OCTGB_SHIFT 0u
#define ENET_TX_64OCTETS_PACKETS_GOOD_BAD_TX64OCTGB_WIDTH 32u
#define ENET_TX_64OCTETS_PACKETS_GOOD_BAD_TX64OCTGB(x) (((uint32_t)(((uint32_t)(x))<<ENET_TX_64OCTETS_PACKETS_GOOD_BAD_TX64OCTGB_SHIFT))&ENET_TX_64OCTETS_PACKETS_GOOD_BAD_TX64OCTGB_MASK)
/* TX_64OCTETS_PACKETS_GOOD_BAD Reg Mask */
#define ENET_TX_64OCTETS_PACKETS_GOOD_BAD_MASK 0xFFFFFFFFu

/* TX_65TO127OCTETS_PACKETS_GOOD_BAD Bit Fields */
#define ENET_TX_65TO127OCTETS_PACKETS_GOOD_BAD_TX65_127OCTGB_MASK 0xFFFFFFFFu
#define ENET_TX_65TO127OCTETS_PACKETS_GOOD_BAD_TX65_127OCTGB_SHIFT 0u
#define ENET_TX_65TO127OCTETS_PACKETS_GOOD_BAD_TX65_127OCTGB_WIDTH 32u
#define ENET_TX_65TO127OCTETS_PACKETS_GOOD_BAD_TX65_127OCTGB(x) (((uint32_t)(((uint32_t)(x))<<ENET_TX_65TO127OCTETS_PACKETS_GOOD_BAD_TX65_127OCTGB_SHIFT))&ENET_TX_65TO127OCTETS_PACKETS_GOOD_BAD_TX65_127OCTGB_MASK)
/* TX_65TO127OCTETS_PACKETS_GOOD_BAD Reg Mask */
#define ENET_TX_65TO127OCTETS_PACKETS_GOOD_BAD_MASK 0xFFFFFFFFu

/* TX_128TO255OCTETS_PACKETS_GOOD_BAD Bit Fields */
#define ENET_TX_128TO255OCTETS_PACKETS_GOOD_BAD_TX128_255OCTGB_MASK 0xFFFFFFFFu
#define ENET_TX_128TO255OCTETS_PACKETS_GOOD_BAD_TX128_255OCTGB_SHIFT 0u
#define ENET_TX_128TO255OCTETS_PACKETS_GOOD_BAD_TX128_255OCTGB_WIDTH 32u
#define ENET_TX_128TO255OCTETS_PACKETS_GOOD_BAD_TX128_255OCTGB(x) (((uint32_t)(((uint32_t)(x))<<ENET_TX_128TO255OCTETS_PACKETS_GOOD_BAD_TX128_255OCTGB_SHIFT))&ENET_TX_128TO255OCTETS_PACKETS_GOOD_BAD_TX128_255OCTGB_MASK)
/* TX_128TO255OCTETS_PACKETS_GOOD_BAD Reg Mask */
#define ENET_TX_128TO255OCTETS_PACKETS_GOOD_BAD_MASK 0xFFFFFFFFu

/* TX_256TO511OCTETS_PACKETS_GOOD_BAD Bit Fields */
#define ENET_TX_256TO511OCTETS_PACKETS_GOOD_BAD_TX256_511OCTGB_MASK 0xFFFFFFFFu
#define ENET_TX_256TO511OCTETS_PACKETS_GOOD_BAD_TX256_511OCTGB_SHIFT 0u
#define ENET_TX_256TO511OCTETS_PACKETS_GOOD_BAD_TX256_511OCTGB_WIDTH 32u
#define ENET_TX_256TO511OCTETS_PACKETS_GOOD_BAD_TX256_511OCTGB(x) (((uint32_t)(((uint32_t)(x))<<ENET_TX_256TO511OCTETS_PACKETS_GOOD_BAD_TX256_511OCTGB_SHIFT))&ENET_TX_256TO511OCTETS_PACKETS_GOOD_BAD_TX256_511OCTGB_MASK)
/* TX_256TO511OCTETS_PACKETS_GOOD_BAD Reg Mask */
#define ENET_TX_256TO511OCTETS_PACKETS_GOOD_BAD_MASK 0xFFFFFFFFu

/* TX_512TO1023OCTETS_PACKETS_GOOD_BAD Bit Fields */
#define ENET_TX_512TO1023OCTETS_PACKETS_GOOD_BAD_TX512_1023OCTGB_MASK 0xFFFFFFFFu
#define ENET_TX_512TO1023OCTETS_PACKETS_GOOD_BAD_TX512_1023OCTGB_SHIFT 0u
#define ENET_TX_512TO1023OCTETS_PACKETS_GOOD_BAD_TX512_1023OCTGB_WIDTH 32u
#define ENET_TX_512TO1023OCTETS_PACKETS_GOOD_BAD_TX512_1023OCTGB(x) (((uint32_t)(((uint32_t)(x))<<ENET_TX_512TO1023OCTETS_PACKETS_GOOD_BAD_TX512_1023OCTGB_SHIFT))&ENET_TX_512TO1023OCTETS_PACKETS_GOOD_BAD_TX512_1023OCTGB_MASK)
/* TX_512TO1023OCTETS_PACKETS_GOOD_BAD Reg Mask */
#define ENET_TX_512TO1023OCTETS_PACKETS_GOOD_BAD_MASK 0xFFFFFFFFu

/* TX_1024TOMAXOCTETS_PACKETS_GOOD_BAD Bit Fields */
#define ENET_TX_1024TOMAXOCTETS_PACKETS_GOOD_BAD_TX1024_MAXOCTGB_MASK 0xFFFFFFFFu
#define ENET_TX_1024TOMAXOCTETS_PACKETS_GOOD_BAD_TX1024_MAXOCTGB_SHIFT 0u
#define ENET_TX_1024TOMAXOCTETS_PACKETS_GOOD_BAD_TX1024_MAXOCTGB_WIDTH 32u
#define ENET_TX_1024TOMAXOCTETS_PACKETS_GOOD_BAD_TX1024_MAXOCTGB(x) (((uint32_t)(((uint32_t)(x))<<ENET_TX_1024TOMAXOCTETS_PACKETS_GOOD_BAD_TX1024_MAXOCTGB_SHIFT))&ENET_TX_1024TOMAXOCTETS_PACKETS_GOOD_BAD_TX1024_MAXOCTGB_MASK)
/* TX_1024TOMAXOCTETS_PACKETS_GOOD_BAD Reg Mask */
#define ENET_TX_1024TOMAXOCTETS_PACKETS_GOOD_BAD_MASK 0xFFFFFFFFu

/* TX_UNICAST_PACKETS_GOOD_BAD Bit Fields */
#define ENET_TX_UNICAST_PACKETS_GOOD_BAD_TXUCASTGB_MASK 0xFFFFFFFFu
#define ENET_TX_UNICAST_PACKETS_GOOD_BAD_TXUCASTGB_SHIFT 0u
#define ENET_TX_UNICAST_PACKETS_GOOD_BAD_TXUCASTGB_WIDTH 32u
#define ENET_TX_UNICAST_PACKETS_GOOD_BAD_TXUCASTGB(x) (((uint32_t)(((uint32_t)(x))<<ENET_TX_UNICAST_PACKETS_GOOD_BAD_TXUCASTGB_SHIFT))&ENET_TX_UNICAST_PACKETS_GOOD_BAD_TXUCASTGB_MASK)
/* TX_UNICAST_PACKETS_GOOD_BAD Reg Mask */
#define ENET_TX_UNICAST_PACKETS_GOOD_BAD_MASK 0xFFFFFFFFu

/* TX_MULTICAST_PACKETS_GOOD_BAD Bit Fields */
#define ENET_TX_MULTICAST_PACKETS_GOOD_BAD_TXMCASTGB_MASK 0xFFFFFFFFu
#define ENET_TX_MULTICAST_PACKETS_GOOD_BAD_TXMCASTGB_SHIFT 0u
#define ENET_TX_MULTICAST_PACKETS_GOOD_BAD_TXMCASTGB_WIDTH 32u
#define ENET_TX_MULTICAST_PACKETS_GOOD_BAD_TXMCASTGB(x) (((uint32_t)(((uint32_t)(x))<<ENET_TX_MULTICAST_PACKETS_GOOD_BAD_TXMCASTGB_SHIFT))&ENET_TX_MULTICAST_PACKETS_GOOD_BAD_TXMCASTGB_MASK)
/* TX_MULTICAST_PACKETS_GOOD_BAD Reg Mask */
#define ENET_TX_MULTICAST_PACKETS_GOOD_BAD_MASK 0xFFFFFFFFu

/* TX_BROADCAST_PACKETS_GOOD_BAD Bit Fields */
#define ENET_TX_BROADCAST_PACKETS_GOOD_BAD_TXBCASTGB_MASK 0xFFFFFFFFu
#define ENET_TX_BROADCAST_PACKETS_GOOD_BAD_TXBCASTGB_SHIFT 0u
#define ENET_TX_BROADCAST_PACKETS_GOOD_BAD_TXBCASTGB_WIDTH 32u
#define ENET_TX_BROADCAST_PACKETS_GOOD_BAD_TXBCASTGB(x) (((uint32_t)(((uint32_t)(x))<<ENET_TX_BROADCAST_PACKETS_GOOD_BAD_TXBCASTGB_SHIFT))&ENET_TX_BROADCAST_PACKETS_GOOD_BAD_TXBCASTGB_MASK)
/* TX_BROADCAST_PACKETS_GOOD_BAD Reg Mask */
#define ENET_TX_BROADCAST_PACKETS_GOOD_BAD_MASK 0xFFFFFFFFu

/* TX_UNDERFLOW_ERROR_PACKETS Bit Fields */
#define ENET_TX_UNDERFLOW_ERROR_PACKETS_TXUNDRFLW_MASK 0xFFFFFFFFu
#define ENET_TX_UNDERFLOW_ERROR_PACKETS_TXUNDRFLW_SHIFT 0u
#define ENET_TX_UNDERFLOW_ERROR_PACKETS_TXUNDRFLW_WIDTH 32u
#define ENET_TX_UNDERFLOW_ERROR_PACKETS_TXUNDRFLW(x) (((uint32_t)(((uint32_t)(x))<<ENET_TX_UNDERFLOW_ERROR_PACKETS_TXUNDRFLW_SHIFT))&ENET_TX_UNDERFLOW_ERROR_PACKETS_TXUNDRFLW_MASK)
/* TX_UNDERFLOW_ERROR_PACKETS Reg Mask */
#define ENET_TX_UNDERFLOW_ERROR_PACKETS_MASK 0xFFFFFFFFu

/* TX_SINGLE_COLLISION_GOOD_PACKETS Bit Fields */
#define ENET_TX_SINGLE_COLLISION_GOOD_PACKETS_TXSNGLCOLG_MASK 0xFFFFFFFFu
#define ENET_TX_SINGLE_COLLISION_GOOD_PACKETS_TXSNGLCOLG_SHIFT 0u
#define ENET_TX_SINGLE_COLLISION_GOOD_PACKETS_TXSNGLCOLG_WIDTH 32u
#define ENET_TX_SINGLE_COLLISION_GOOD_PACKETS_TXSNGLCOLG(x) (((uint32_t)(((uint32_t)(x))<<ENET_TX_SINGLE_COLLISION_GOOD_PACKETS_TXSNGLCOLG_SHIFT))&ENET_TX_SINGLE_COLLISION_GOOD_PACKETS_TXSNGLCOLG_MASK)
/* TX_SINGLE_COLLISION_GOOD_PACKETS Reg Mask */
#define ENET_TX_SINGLE_COLLISION_GOOD_PACKETS_MASK 0xFFFFFFFFu

/* TX_MULTIPLE_COLLISION_GOOD_PACKETS Bit Fields */
#define ENET_TX_MULTIPLE_COLLISION_GOOD_PACKETS_TXMULTCOLG_MASK 0xFFFFFFFFu
#define ENET_TX_MULTIPLE_COLLISION_GOOD_PACKETS_TXMULTCOLG_SHIFT 0u
#define ENET_TX_MULTIPLE_COLLISION_GOOD_PACKETS_TXMULTCOLG_WIDTH 32u
#define ENET_TX_MULTIPLE_COLLISION_GOOD_PACKETS_TXMULTCOLG(x) (((uint32_t)(((uint32_t)(x))<<ENET_TX_MULTIPLE_COLLISION_GOOD_PACKETS_TXMULTCOLG_SHIFT))&ENET_TX_MULTIPLE_COLLISION_GOOD_PACKETS_TXMULTCOLG_MASK)
/* TX_MULTIPLE_COLLISION_GOOD_PACKETS Reg Mask */
#define ENET_TX_MULTIPLE_COLLISION_GOOD_PACKETS_MASK 0xFFFFFFFFu

/* TX_DEFERRED_PACKETS Bit Fields */
#define ENET_TX_DEFERRED_PACKETS_TXDEFRD_MASK 0xFFFFFFFFu
#define ENET_TX_DEFERRED_PACKETS_TXDEFRD_SHIFT 0u
#define ENET_TX_DEFERRED_PACKETS_TXDEFRD_WIDTH 32u
#define ENET_TX_DEFERRED_PACKETS_TXDEFRD(x) (((uint32_t)(((uint32_t)(x))<<ENET_TX_DEFERRED_PACKETS_TXDEFRD_SHIFT))&ENET_TX_DEFERRED_PACKETS_TXDEFRD_MASK)
/* TX_DEFERRED_PACKETS Reg Mask */
#define ENET_TX_DEFERRED_PACKETS_MASK  0xFFFFFFFFu

/* TX_LATE_COLLISION_PACKETS Bit Fields */
#define ENET_TX_LATE_COLLISION_PACKETS_TXLATECOL_MASK 0xFFFFFFFFu
#define ENET_TX_LATE_COLLISION_PACKETS_TXLATECOL_SHIFT 0u
#define ENET_TX_LATE_COLLISION_PACKETS_TXLATECOL_WIDTH 32u
#define ENET_TX_LATE_COLLISION_PACKETS_TXLATECOL(x) (((uint32_t)(((uint32_t)(x))<<ENET_TX_LATE_COLLISION_PACKETS_TXLATECOL_SHIFT))&ENET_TX_LATE_COLLISION_PACKETS_TXLATECOL_MASK)
/* TX_LATE_COLLISION_PACKETS Reg Mask */
#define ENET_TX_LATE_COLLISION_PACKETS_MASK 0xFFFFFFFFu

/* TX_EXCESSIVE_COLLISION_PACKETS Bit Fields */
#define ENET_TX_EXCESSIVE_COLLISION_PACKETS_TXEXSCOL_MASK 0xFFFFFFFFu
#define ENET_TX_EXCESSIVE_COLLISION_PACKETS_TXEXSCOL_SHIFT 0u
#define ENET_TX_EXCESSIVE_COLLISION_PACKETS_TXEXSCOL_WIDTH 32u
#define ENET_TX_EXCESSIVE_COLLISION_PACKETS_TXEXSCOL(x) (((uint32_t)(((uint32_t)(x))<<ENET_TX_EXCESSIVE_COLLISION_PACKETS_TXEXSCOL_SHIFT))&ENET_TX_EXCESSIVE_COLLISION_PACKETS_TXEXSCOL_MASK)
/* TX_EXCESSIVE_COLLISION_PACKETS Reg Mask */
#define ENET_TX_EXCESSIVE_COLLISION_PACKETS_MASK 0xFFFFFFFFu

/* TX_CARRIER_ERROR_PACKETS Bit Fields */
#define ENET_TX_CARRIER_ERROR_PACKETS_TXCARR_MASK 0xFFFFFFFFu
#define ENET_TX_CARRIER_ERROR_PACKETS_TXCARR_SHIFT 0u
#define ENET_TX_CARRIER_ERROR_PACKETS_TXCARR_WIDTH 32u
#define ENET_TX_CARRIER_ERROR_PACKETS_TXCARR(x) (((uint32_t)(((uint32_t)(x))<<ENET_TX_CARRIER_ERROR_PACKETS_TXCARR_SHIFT))&ENET_TX_CARRIER_ERROR_PACKETS_TXCARR_MASK)
/* TX_CARRIER_ERROR_PACKETS Reg Mask */
#define ENET_TX_CARRIER_ERROR_PACKETS_MASK 0xFFFFFFFFu

/* TX_OCTET_COUNT_GOOD Bit Fields */
#define ENET_TX_OCTET_COUNT_GOOD_TXOCTG_MASK 0xFFFFFFFFu
#define ENET_TX_OCTET_COUNT_GOOD_TXOCTG_SHIFT 0u
#define ENET_TX_OCTET_COUNT_GOOD_TXOCTG_WIDTH 32u
#define ENET_TX_OCTET_COUNT_GOOD_TXOCTG(x) (((uint32_t)(((uint32_t)(x))<<ENET_TX_OCTET_COUNT_GOOD_TXOCTG_SHIFT))&ENET_TX_OCTET_COUNT_GOOD_TXOCTG_MASK)
/* TX_OCTET_COUNT_GOOD Reg Mask */
#define ENET_TX_OCTET_COUNT_GOOD_MASK  0xFFFFFFFFu

/* TX_PACKET_COUNT_GOOD Bit Fields */
#define ENET_TX_PACKET_COUNT_GOOD_TXPKTG_MASK 0xFFFFFFFFu
#define ENET_TX_PACKET_COUNT_GOOD_TXPKTG_SHIFT 0u
#define ENET_TX_PACKET_COUNT_GOOD_TXPKTG_WIDTH 32u
#define ENET_TX_PACKET_COUNT_GOOD_TXPKTG(x) (((uint32_t)(((uint32_t)(x))<<ENET_TX_PACKET_COUNT_GOOD_TXPKTG_SHIFT))&ENET_TX_PACKET_COUNT_GOOD_TXPKTG_MASK)
/* TX_PACKET_COUNT_GOOD Reg Mask */
#define ENET_TX_PACKET_COUNT_GOOD_MASK 0xFFFFFFFFu

/* TX_EXCESSIVE_DEFERRAL_ERROR Bit Fields */
#define ENET_TX_EXCESSIVE_DEFERRAL_ERROR_TXEXSDEF_MASK 0xFFFFFFFFu
#define ENET_TX_EXCESSIVE_DEFERRAL_ERROR_TXEXSDEF_SHIFT 0u
#define ENET_TX_EXCESSIVE_DEFERRAL_ERROR_TXEXSDEF_WIDTH 32u
#define ENET_TX_EXCESSIVE_DEFERRAL_ERROR_TXEXSDEF(x) (((uint32_t)(((uint32_t)(x))<<ENET_TX_EXCESSIVE_DEFERRAL_ERROR_TXEXSDEF_SHIFT))&ENET_TX_EXCESSIVE_DEFERRAL_ERROR_TXEXSDEF_MASK)
/* TX_EXCESSIVE_DEFERRAL_ERROR Reg Mask */
#define ENET_TX_EXCESSIVE_DEFERRAL_ERROR_MASK 0xFFFFFFFFu

/* TX_PAUSE_PACKETS Bit Fields */
#define ENET_TX_PAUSE_PACKETS_TXPAUSE_MASK 0xFFFFFFFFu
#define ENET_TX_PAUSE_PACKETS_TXPAUSE_SHIFT 0u
#define ENET_TX_PAUSE_PACKETS_TXPAUSE_WIDTH 32u
#define ENET_TX_PAUSE_PACKETS_TXPAUSE(x) (((uint32_t)(((uint32_t)(x))<<ENET_TX_PAUSE_PACKETS_TXPAUSE_SHIFT))&ENET_TX_PAUSE_PACKETS_TXPAUSE_MASK)
/* TX_PAUSE_PACKETS Reg Mask */
#define ENET_TX_PAUSE_PACKETS_MASK     0xFFFFFFFFu

/* TX_VLAN_PACKETS_GOOD Bit Fields */
#define ENET_TX_VLAN_PACKETS_GOOD_TXVLANG_MASK 0xFFFFFFFFu
#define ENET_TX_VLAN_PACKETS_GOOD_TXVLANG_SHIFT 0u
#define ENET_TX_VLAN_PACKETS_GOOD_TXVLANG_WIDTH 32u
#define ENET_TX_VLAN_PACKETS_GOOD_TXVLANG(x) (((uint32_t)(((uint32_t)(x))<<ENET_TX_VLAN_PACKETS_GOOD_TXVLANG_SHIFT))&ENET_TX_VLAN_PACKETS_GOOD_TXVLANG_MASK)
/* TX_VLAN_PACKETS_GOOD Reg Mask */
#define ENET_TX_VLAN_PACKETS_GOOD_MASK 0xFFFFFFFFu

/* TX_OSIZE_PACKETS_GOOD Bit Fields */
#define ENET_TX_OSIZE_PACKETS_GOOD_TXOSIZG_MASK 0xFFFFFFFFu
#define ENET_TX_OSIZE_PACKETS_GOOD_TXOSIZG_SHIFT 0u
#define ENET_TX_OSIZE_PACKETS_GOOD_TXOSIZG_WIDTH 32u
#define ENET_TX_OSIZE_PACKETS_GOOD_TXOSIZG(x) (((uint32_t)(((uint32_t)(x))<<ENET_TX_OSIZE_PACKETS_GOOD_TXOSIZG_SHIFT))&ENET_TX_OSIZE_PACKETS_GOOD_TXOSIZG_MASK)
/* TX_OSIZE_PACKETS_GOOD Reg Mask */
#define ENET_TX_OSIZE_PACKETS_GOOD_MASK 0xFFFFFFFFu

/* RX_PACKETS_COUNT_GOOD_BAD Bit Fields */
#define ENET_RX_PACKETS_COUNT_GOOD_BAD_RXPKTGB_MASK 0xFFFFFFFFu
#define ENET_RX_PACKETS_COUNT_GOOD_BAD_RXPKTGB_SHIFT 0u
#define ENET_RX_PACKETS_COUNT_GOOD_BAD_RXPKTGB_WIDTH 32u
#define ENET_RX_PACKETS_COUNT_GOOD_BAD_RXPKTGB(x) (((uint32_t)(((uint32_t)(x))<<ENET_RX_PACKETS_COUNT_GOOD_BAD_RXPKTGB_SHIFT))&ENET_RX_PACKETS_COUNT_GOOD_BAD_RXPKTGB_MASK)
/* RX_PACKETS_COUNT_GOOD_BAD Reg Mask */
#define ENET_RX_PACKETS_COUNT_GOOD_BAD_MASK 0xFFFFFFFFu

/* RX_OCTET_COUNT_GOOD_BAD Bit Fields */
#define ENET_RX_OCTET_COUNT_GOOD_BAD_RXOCTGB_MASK 0xFFFFFFFFu
#define ENET_RX_OCTET_COUNT_GOOD_BAD_RXOCTGB_SHIFT 0u
#define ENET_RX_OCTET_COUNT_GOOD_BAD_RXOCTGB_WIDTH 32u
#define ENET_RX_OCTET_COUNT_GOOD_BAD_RXOCTGB(x) (((uint32_t)(((uint32_t)(x))<<ENET_RX_OCTET_COUNT_GOOD_BAD_RXOCTGB_SHIFT))&ENET_RX_OCTET_COUNT_GOOD_BAD_RXOCTGB_MASK)
/* RX_OCTET_COUNT_GOOD_BAD Reg Mask */
#define ENET_RX_OCTET_COUNT_GOOD_BAD_MASK 0xFFFFFFFFu

/* RX_OCTET_COUNT_GOOD Bit Fields */
#define ENET_RX_OCTET_COUNT_GOOD_RXOCTG_MASK 0xFFFFFFFFu
#define ENET_RX_OCTET_COUNT_GOOD_RXOCTG_SHIFT 0u
#define ENET_RX_OCTET_COUNT_GOOD_RXOCTG_WIDTH 32u
#define ENET_RX_OCTET_COUNT_GOOD_RXOCTG(x) (((uint32_t)(((uint32_t)(x))<<ENET_RX_OCTET_COUNT_GOOD_RXOCTG_SHIFT))&ENET_RX_OCTET_COUNT_GOOD_RXOCTG_MASK)
/* RX_OCTET_COUNT_GOOD Reg Mask */
#define ENET_RX_OCTET_COUNT_GOOD_MASK  0xFFFFFFFFu

/* RX_BROADCAST_PACKETS_GOOD Bit Fields */
#define ENET_RX_BROADCAST_PACKETS_GOOD_RXBCASTG_MASK 0xFFFFFFFFu
#define ENET_RX_BROADCAST_PACKETS_GOOD_RXBCASTG_SHIFT 0u
#define ENET_RX_BROADCAST_PACKETS_GOOD_RXBCASTG_WIDTH 32u
#define ENET_RX_BROADCAST_PACKETS_GOOD_RXBCASTG(x) (((uint32_t)(((uint32_t)(x))<<ENET_RX_BROADCAST_PACKETS_GOOD_RXBCASTG_SHIFT))&ENET_RX_BROADCAST_PACKETS_GOOD_RXBCASTG_MASK)
/* RX_BROADCAST_PACKETS_GOOD Reg Mask */
#define ENET_RX_BROADCAST_PACKETS_GOOD_MASK 0xFFFFFFFFu

/* RX_MULTICAST_PACKETS_GOOD Bit Fields */
#define ENET_RX_MULTICAST_PACKETS_GOOD_RXMCASTG_MASK 0xFFFFFFFFu
#define ENET_RX_MULTICAST_PACKETS_GOOD_RXMCASTG_SHIFT 0u
#define ENET_RX_MULTICAST_PACKETS_GOOD_RXMCASTG_WIDTH 32u
#define ENET_RX_MULTICAST_PACKETS_GOOD_RXMCASTG(x) (((uint32_t)(((uint32_t)(x))<<ENET_RX_MULTICAST_PACKETS_GOOD_RXMCASTG_SHIFT))&ENET_RX_MULTICAST_PACKETS_GOOD_RXMCASTG_MASK)
/* RX_MULTICAST_PACKETS_GOOD Reg Mask */
#define ENET_RX_MULTICAST_PACKETS_GOOD_MASK 0xFFFFFFFFu

/* RX_CRC_ERROR_PACKETS Bit Fields */
#define ENET_RX_CRC_ERROR_PACKETS_RXCRCERR_MASK 0xFFFFFFFFu
#define ENET_RX_CRC_ERROR_PACKETS_RXCRCERR_SHIFT 0u
#define ENET_RX_CRC_ERROR_PACKETS_RXCRCERR_WIDTH 32u
#define ENET_RX_CRC_ERROR_PACKETS_RXCRCERR(x) (((uint32_t)(((uint32_t)(x))<<ENET_RX_CRC_ERROR_PACKETS_RXCRCERR_SHIFT))&ENET_RX_CRC_ERROR_PACKETS_RXCRCERR_MASK)
/* RX_CRC_ERROR_PACKETS Reg Mask */
#define ENET_RX_CRC_ERROR_PACKETS_MASK 0xFFFFFFFFu

/* RX_ALIGNMENT_ERROR_PACKETS Bit Fields */
#define ENET_RX_ALIGNMENT_ERROR_PACKETS_RXALGNERR_MASK 0xFFFFFFFFu
#define ENET_RX_ALIGNMENT_ERROR_PACKETS_RXALGNERR_SHIFT 0u
#define ENET_RX_ALIGNMENT_ERROR_PACKETS_RXALGNERR_WIDTH 32u
#define ENET_RX_ALIGNMENT_ERROR_PACKETS_RXALGNERR(x) (((uint32_t)(((uint32_t)(x))<<ENET_RX_ALIGNMENT_ERROR_PACKETS_RXALGNERR_SHIFT))&ENET_RX_ALIGNMENT_ERROR_PACKETS_RXALGNERR_MASK)
/* RX_ALIGNMENT_ERROR_PACKETS Reg Mask */
#define ENET_RX_ALIGNMENT_ERROR_PACKETS_MASK 0xFFFFFFFFu

/* RX_RUNT_ERROR_PACKETS Bit Fields */
#define ENET_RX_RUNT_ERROR_PACKETS_RXRUNTERR_MASK 0xFFFFFFFFu
#define ENET_RX_RUNT_ERROR_PACKETS_RXRUNTERR_SHIFT 0u
#define ENET_RX_RUNT_ERROR_PACKETS_RXRUNTERR_WIDTH 32u
#define ENET_RX_RUNT_ERROR_PACKETS_RXRUNTERR(x) (((uint32_t)(((uint32_t)(x))<<ENET_RX_RUNT_ERROR_PACKETS_RXRUNTERR_SHIFT))&ENET_RX_RUNT_ERROR_PACKETS_RXRUNTERR_MASK)
/* RX_RUNT_ERROR_PACKETS Reg Mask */
#define ENET_RX_RUNT_ERROR_PACKETS_MASK 0xFFFFFFFFu

/* RX_JABBER_ERROR_PACKETS Bit Fields */
#define ENET_RX_JABBER_ERROR_PACKETS_RXJABERR_MASK 0xFFFFFFFFu
#define ENET_RX_JABBER_ERROR_PACKETS_RXJABERR_SHIFT 0u
#define ENET_RX_JABBER_ERROR_PACKETS_RXJABERR_WIDTH 32u
#define ENET_RX_JABBER_ERROR_PACKETS_RXJABERR(x) (((uint32_t)(((uint32_t)(x))<<ENET_RX_JABBER_ERROR_PACKETS_RXJABERR_SHIFT))&ENET_RX_JABBER_ERROR_PACKETS_RXJABERR_MASK)
/* RX_JABBER_ERROR_PACKETS Reg Mask */
#define ENET_RX_JABBER_ERROR_PACKETS_MASK 0xFFFFFFFFu

/* RX_UNDERSIZE_PACKETS_GOOD Bit Fields */
#define ENET_RX_UNDERSIZE_PACKETS_GOOD_RXUNDERSZG_MASK 0xFFFFFFFFu
#define ENET_RX_UNDERSIZE_PACKETS_GOOD_RXUNDERSZG_SHIFT 0u
#define ENET_RX_UNDERSIZE_PACKETS_GOOD_RXUNDERSZG_WIDTH 32u
#define ENET_RX_UNDERSIZE_PACKETS_GOOD_RXUNDERSZG(x) (((uint32_t)(((uint32_t)(x))<<ENET_RX_UNDERSIZE_PACKETS_GOOD_RXUNDERSZG_SHIFT))&ENET_RX_UNDERSIZE_PACKETS_GOOD_RXUNDERSZG_MASK)
/* RX_UNDERSIZE_PACKETS_GOOD Reg Mask */
#define ENET_RX_UNDERSIZE_PACKETS_GOOD_MASK 0xFFFFFFFFu

/* RX_OVERSIZE_PACKETS_GOOD Bit Fields */
#define ENET_RX_OVERSIZE_PACKETS_GOOD_RXOVERSZG_MASK 0xFFFFFFFFu
#define ENET_RX_OVERSIZE_PACKETS_GOOD_RXOVERSZG_SHIFT 0u
#define ENET_RX_OVERSIZE_PACKETS_GOOD_RXOVERSZG_WIDTH 32u
#define ENET_RX_OVERSIZE_PACKETS_GOOD_RXOVERSZG(x) (((uint32_t)(((uint32_t)(x))<<ENET_RX_OVERSIZE_PACKETS_GOOD_RXOVERSZG_SHIFT))&ENET_RX_OVERSIZE_PACKETS_GOOD_RXOVERSZG_MASK)
/* RX_OVERSIZE_PACKETS_GOOD Reg Mask */
#define ENET_RX_OVERSIZE_PACKETS_GOOD_MASK 0xFFFFFFFFu

/* RX_64OCTETS_PACKETS_GOOD_BAD Bit Fields */
#define ENET_RX_64OCTETS_PACKETS_GOOD_BAD_RX64OCTGB_MASK 0xFFFFFFFFu
#define ENET_RX_64OCTETS_PACKETS_GOOD_BAD_RX64OCTGB_SHIFT 0u
#define ENET_RX_64OCTETS_PACKETS_GOOD_BAD_RX64OCTGB_WIDTH 32u
#define ENET_RX_64OCTETS_PACKETS_GOOD_BAD_RX64OCTGB(x) (((uint32_t)(((uint32_t)(x))<<ENET_RX_64OCTETS_PACKETS_GOOD_BAD_RX64OCTGB_SHIFT))&ENET_RX_64OCTETS_PACKETS_GOOD_BAD_RX64OCTGB_MASK)
/* RX_64OCTETS_PACKETS_GOOD_BAD Reg Mask */
#define ENET_RX_64OCTETS_PACKETS_GOOD_BAD_MASK 0xFFFFFFFFu

/* RX_65TO127OCTETS_PACKETS_GOOD_BAD Bit Fields */
#define ENET_RX_65TO127OCTETS_PACKETS_GOOD_BAD_RX65_127OCTGB_MASK 0xFFFFFFFFu
#define ENET_RX_65TO127OCTETS_PACKETS_GOOD_BAD_RX65_127OCTGB_SHIFT 0u
#define ENET_RX_65TO127OCTETS_PACKETS_GOOD_BAD_RX65_127OCTGB_WIDTH 32u
#define ENET_RX_65TO127OCTETS_PACKETS_GOOD_BAD_RX65_127OCTGB(x) (((uint32_t)(((uint32_t)(x))<<ENET_RX_65TO127OCTETS_PACKETS_GOOD_BAD_RX65_127OCTGB_SHIFT))&ENET_RX_65TO127OCTETS_PACKETS_GOOD_BAD_RX65_127OCTGB_MASK)
/* RX_65TO127OCTETS_PACKETS_GOOD_BAD Reg Mask */
#define ENET_RX_65TO127OCTETS_PACKETS_GOOD_BAD_MASK 0xFFFFFFFFu

/* RX_128TO255OCTETS_PACKETS_GOOD_BAD Bit Fields */
#define ENET_RX_128TO255OCTETS_PACKETS_GOOD_BAD_RX128_255OCTGB_MASK 0xFFFFFFFFu
#define ENET_RX_128TO255OCTETS_PACKETS_GOOD_BAD_RX128_255OCTGB_SHIFT 0u
#define ENET_RX_128TO255OCTETS_PACKETS_GOOD_BAD_RX128_255OCTGB_WIDTH 32u
#define ENET_RX_128TO255OCTETS_PACKETS_GOOD_BAD_RX128_255OCTGB(x) (((uint32_t)(((uint32_t)(x))<<ENET_RX_128TO255OCTETS_PACKETS_GOOD_BAD_RX128_255OCTGB_SHIFT))&ENET_RX_128TO255OCTETS_PACKETS_GOOD_BAD_RX128_255OCTGB_MASK)
/* RX_128TO255OCTETS_PACKETS_GOOD_BAD Reg Mask */
#define ENET_RX_128TO255OCTETS_PACKETS_GOOD_BAD_MASK 0xFFFFFFFFu

/* RX_256TO511OCTETS_PACKETS_GOOD_BAD Bit Fields */
#define ENET_RX_256TO511OCTETS_PACKETS_GOOD_BAD_RX256_511OCTGB_MASK 0xFFFFFFFFu
#define ENET_RX_256TO511OCTETS_PACKETS_GOOD_BAD_RX256_511OCTGB_SHIFT 0u
#define ENET_RX_256TO511OCTETS_PACKETS_GOOD_BAD_RX256_511OCTGB_WIDTH 32u
#define ENET_RX_256TO511OCTETS_PACKETS_GOOD_BAD_RX256_511OCTGB(x) (((uint32_t)(((uint32_t)(x))<<ENET_RX_256TO511OCTETS_PACKETS_GOOD_BAD_RX256_511OCTGB_SHIFT))&ENET_RX_256TO511OCTETS_PACKETS_GOOD_BAD_RX256_511OCTGB_MASK)
/* RX_256TO511OCTETS_PACKETS_GOOD_BAD Reg Mask */
#define ENET_RX_256TO511OCTETS_PACKETS_GOOD_BAD_MASK 0xFFFFFFFFu

/* RX_512TO1023OCTETS_PACKETS_GOOD_BAD Bit Fields */
#define ENET_RX_512TO1023OCTETS_PACKETS_GOOD_BAD_RX512_1023OCTGB_MASK 0xFFFFFFFFu
#define ENET_RX_512TO1023OCTETS_PACKETS_GOOD_BAD_RX512_1023OCTGB_SHIFT 0u
#define ENET_RX_512TO1023OCTETS_PACKETS_GOOD_BAD_RX512_1023OCTGB_WIDTH 32u
#define ENET_RX_512TO1023OCTETS_PACKETS_GOOD_BAD_RX512_1023OCTGB(x) (((uint32_t)(((uint32_t)(x))<<ENET_RX_512TO1023OCTETS_PACKETS_GOOD_BAD_RX512_1023OCTGB_SHIFT))&ENET_RX_512TO1023OCTETS_PACKETS_GOOD_BAD_RX512_1023OCTGB_MASK)
/* RX_512TO1023OCTETS_PACKETS_GOOD_BAD Reg Mask */
#define ENET_RX_512TO1023OCTETS_PACKETS_GOOD_BAD_MASK 0xFFFFFFFFu

/* RX_1024TOMAXOCTETS_PACKETS_GOOD_BAD Bit Fields */
#define ENET_RX_1024TOMAXOCTETS_PACKETS_GOOD_BAD_RX1024_MAXOCTGB_MASK 0xFFFFFFFFu
#define ENET_RX_1024TOMAXOCTETS_PACKETS_GOOD_BAD_RX1024_MAXOCTGB_SHIFT 0u
#define ENET_RX_1024TOMAXOCTETS_PACKETS_GOOD_BAD_RX1024_MAXOCTGB_WIDTH 32u
#define ENET_RX_1024TOMAXOCTETS_PACKETS_GOOD_BAD_RX1024_MAXOCTGB(x) (((uint32_t)(((uint32_t)(x))<<ENET_RX_1024TOMAXOCTETS_PACKETS_GOOD_BAD_RX1024_MAXOCTGB_SHIFT))&ENET_RX_1024TOMAXOCTETS_PACKETS_GOOD_BAD_RX1024_MAXOCTGB_MASK)
/* RX_1024TOMAXOCTETS_PACKETS_GOOD_BAD Reg Mask */
#define ENET_RX_1024TOMAXOCTETS_PACKETS_GOOD_BAD_MASK 0xFFFFFFFFu

/* RX_UNICAST_PACKETS_GOOD Bit Fields */
#define ENET_RX_UNICAST_PACKETS_GOOD_RXUCASTG_MASK 0xFFFFFFFFu
#define ENET_RX_UNICAST_PACKETS_GOOD_RXUCASTG_SHIFT 0u
#define ENET_RX_UNICAST_PACKETS_GOOD_RXUCASTG_WIDTH 32u
#define ENET_RX_UNICAST_PACKETS_GOOD_RXUCASTG(x) (((uint32_t)(((uint32_t)(x))<<ENET_RX_UNICAST_PACKETS_GOOD_RXUCASTG_SHIFT))&ENET_RX_UNICAST_PACKETS_GOOD_RXUCASTG_MASK)
/* RX_UNICAST_PACKETS_GOOD Reg Mask */
#define ENET_RX_UNICAST_PACKETS_GOOD_MASK 0xFFFFFFFFu

/* RX_LENGTH_ERROR_PACKETS Bit Fields */
#define ENET_RX_LENGTH_ERROR_PACKETS_RXLENERR_MASK 0xFFFFFFFFu
#define ENET_RX_LENGTH_ERROR_PACKETS_RXLENERR_SHIFT 0u
#define ENET_RX_LENGTH_ERROR_PACKETS_RXLENERR_WIDTH 32u
#define ENET_RX_LENGTH_ERROR_PACKETS_RXLENERR(x) (((uint32_t)(((uint32_t)(x))<<ENET_RX_LENGTH_ERROR_PACKETS_RXLENERR_SHIFT))&ENET_RX_LENGTH_ERROR_PACKETS_RXLENERR_MASK)
/* RX_LENGTH_ERROR_PACKETS Reg Mask */
#define ENET_RX_LENGTH_ERROR_PACKETS_MASK 0xFFFFFFFFu

/* RX_OUT_OF_RANGE_TYPE_PACKETS Bit Fields */
#define ENET_RX_OUT_OF_RANGE_TYPE_PACKETS_RXOUTOFRNG_MASK 0xFFFFFFFFu
#define ENET_RX_OUT_OF_RANGE_TYPE_PACKETS_RXOUTOFRNG_SHIFT 0u
#define ENET_RX_OUT_OF_RANGE_TYPE_PACKETS_RXOUTOFRNG_WIDTH 32u
#define ENET_RX_OUT_OF_RANGE_TYPE_PACKETS_RXOUTOFRNG(x) (((uint32_t)(((uint32_t)(x))<<ENET_RX_OUT_OF_RANGE_TYPE_PACKETS_RXOUTOFRNG_SHIFT))&ENET_RX_OUT_OF_RANGE_TYPE_PACKETS_RXOUTOFRNG_MASK)
/* RX_OUT_OF_RANGE_TYPE_PACKETS Reg Mask */
#define ENET_RX_OUT_OF_RANGE_TYPE_PACKETS_MASK 0xFFFFFFFFu

/* RX_PAUSE_PACKETS Bit Fields */
#define ENET_RX_PAUSE_PACKETS_RXPAUSEPKT_MASK 0xFFFFFFFFu
#define ENET_RX_PAUSE_PACKETS_RXPAUSEPKT_SHIFT 0u
#define ENET_RX_PAUSE_PACKETS_RXPAUSEPKT_WIDTH 32u
#define ENET_RX_PAUSE_PACKETS_RXPAUSEPKT(x) (((uint32_t)(((uint32_t)(x))<<ENET_RX_PAUSE_PACKETS_RXPAUSEPKT_SHIFT))&ENET_RX_PAUSE_PACKETS_RXPAUSEPKT_MASK)
/* RX_PAUSE_PACKETS Reg Mask */
#define ENET_RX_PAUSE_PACKETS_MASK     0xFFFFFFFFu

/* RX_FIFO_OVERFLOW_PACKETS Bit Fields */
#define ENET_RX_FIFO_OVERFLOW_PACKETS_RXFIFOOVFL_MASK 0xFFFFFFFFu
#define ENET_RX_FIFO_OVERFLOW_PACKETS_RXFIFOOVFL_SHIFT 0u
#define ENET_RX_FIFO_OVERFLOW_PACKETS_RXFIFOOVFL_WIDTH 32u
#define ENET_RX_FIFO_OVERFLOW_PACKETS_RXFIFOOVFL(x) (((uint32_t)(((uint32_t)(x))<<ENET_RX_FIFO_OVERFLOW_PACKETS_RXFIFOOVFL_SHIFT))&ENET_RX_FIFO_OVERFLOW_PACKETS_RXFIFOOVFL_MASK)
/* RX_FIFO_OVERFLOW_PACKETS Reg Mask */
#define ENET_RX_FIFO_OVERFLOW_PACKETS_MASK 0xFFFFFFFFu

/* RX_VLAN_PACKETS_GOOD_BAD Bit Fields */
#define ENET_RX_VLAN_PACKETS_GOOD_BAD_RXVLANPKTGB_MASK 0xFFFFFFFFu
#define ENET_RX_VLAN_PACKETS_GOOD_BAD_RXVLANPKTGB_SHIFT 0u
#define ENET_RX_VLAN_PACKETS_GOOD_BAD_RXVLANPKTGB_WIDTH 32u
#define ENET_RX_VLAN_PACKETS_GOOD_BAD_RXVLANPKTGB(x) (((uint32_t)(((uint32_t)(x))<<ENET_RX_VLAN_PACKETS_GOOD_BAD_RXVLANPKTGB_SHIFT))&ENET_RX_VLAN_PACKETS_GOOD_BAD_RXVLANPKTGB_MASK)
/* RX_VLAN_PACKETS_GOOD_BAD Reg Mask */
#define ENET_RX_VLAN_PACKETS_GOOD_BAD_MASK 0xFFFFFFFFu

/* RX_WATCHDOG_ERROR_PACKETS Bit Fields */
#define ENET_RX_WATCHDOG_ERROR_PACKETS_RXWDGERR_MASK 0xFFFFFFFFu
#define ENET_RX_WATCHDOG_ERROR_PACKETS_RXWDGERR_SHIFT 0u
#define ENET_RX_WATCHDOG_ERROR_PACKETS_RXWDGERR_WIDTH 32u
#define ENET_RX_WATCHDOG_ERROR_PACKETS_RXWDGERR(x) (((uint32_t)(((uint32_t)(x))<<ENET_RX_WATCHDOG_ERROR_PACKETS_RXWDGERR_SHIFT))&ENET_RX_WATCHDOG_ERROR_PACKETS_RXWDGERR_MASK)
/* RX_WATCHDOG_ERROR_PACKETS Reg Mask */
#define ENET_RX_WATCHDOG_ERROR_PACKETS_MASK 0xFFFFFFFFu

/* RX_RECEIVE_ERROR_PACKETS Bit Fields */
#define ENET_RX_RECEIVE_ERROR_PACKETS_RXRCVERR_MASK 0xFFFFFFFFu
#define ENET_RX_RECEIVE_ERROR_PACKETS_RXRCVERR_SHIFT 0u
#define ENET_RX_RECEIVE_ERROR_PACKETS_RXRCVERR_WIDTH 32u
#define ENET_RX_RECEIVE_ERROR_PACKETS_RXRCVERR(x) (((uint32_t)(((uint32_t)(x))<<ENET_RX_RECEIVE_ERROR_PACKETS_RXRCVERR_SHIFT))&ENET_RX_RECEIVE_ERROR_PACKETS_RXRCVERR_MASK)
/* RX_RECEIVE_ERROR_PACKETS Reg Mask */
#define ENET_RX_RECEIVE_ERROR_PACKETS_MASK 0xFFFFFFFFu

/* RX_CONTROL_PACKETS_GOOD Bit Fields */
#define ENET_RX_CONTROL_PACKETS_GOOD_RXCTRLG_MASK 0xFFFFFFFFu
#define ENET_RX_CONTROL_PACKETS_GOOD_RXCTRLG_SHIFT 0u
#define ENET_RX_CONTROL_PACKETS_GOOD_RXCTRLG_WIDTH 32u
#define ENET_RX_CONTROL_PACKETS_GOOD_RXCTRLG(x) (((uint32_t)(((uint32_t)(x))<<ENET_RX_CONTROL_PACKETS_GOOD_RXCTRLG_SHIFT))&ENET_RX_CONTROL_PACKETS_GOOD_RXCTRLG_MASK)
/* RX_CONTROL_PACKETS_GOOD Reg Mask */
#define ENET_RX_CONTROL_PACKETS_GOOD_MASK 0xFFFFFFFFu

/* MMC_IPC_RX_INTERRUPT_MASK Bit Fields */
/* MMC_IPC_RX_INTERRUPT_MASK Reg Mask */
#define ENET_MMC_IPC_RX_INTERRUPT_MASK_MASK 0x00000000u

/* MMC_IPC_RX_INTERRUPT Bit Fields */
/* MMC_IPC_RX_INTERRUPT Reg Mask */
#define ENET_MMC_IPC_RX_INTERRUPT_MASK 0x00000000u

/* RXIPV4_GOOD_PACKETS Bit Fields */
#define ENET_RXIPV4_GOOD_PACKETS_RXIPV4GDPKT_MASK 0xFFFFFFFFu
#define ENET_RXIPV4_GOOD_PACKETS_RXIPV4GDPKT_SHIFT 0u
#define ENET_RXIPV4_GOOD_PACKETS_RXIPV4GDPKT_WIDTH 32u
#define ENET_RXIPV4_GOOD_PACKETS_RXIPV4GDPKT(x) (((uint32_t)(((uint32_t)(x))<<ENET_RXIPV4_GOOD_PACKETS_RXIPV4GDPKT_SHIFT))&ENET_RXIPV4_GOOD_PACKETS_RXIPV4GDPKT_MASK)
/* RXIPV4_GOOD_PACKETS Reg Mask */
#define ENET_RXIPV4_GOOD_PACKETS_MASK  0xFFFFFFFFu

/* RXIPV4_HEADER_ERROR_PACKETS Bit Fields */
#define ENET_RXIPV4_HEADER_ERROR_PACKETS_RXIPV4HDRERRPKT_MASK 0xFFFFFFFFu
#define ENET_RXIPV4_HEADER_ERROR_PACKETS_RXIPV4HDRERRPKT_SHIFT 0u
#define ENET_RXIPV4_HEADER_ERROR_PACKETS_RXIPV4HDRERRPKT_WIDTH 32u
#define ENET_RXIPV4_HEADER_ERROR_PACKETS_RXIPV4HDRERRPKT(x) (((uint32_t)(((uint32_t)(x))<<ENET_RXIPV4_HEADER_ERROR_PACKETS_RXIPV4HDRERRPKT_SHIFT))&ENET_RXIPV4_HEADER_ERROR_PACKETS_RXIPV4HDRERRPKT_MASK)
/* RXIPV4_HEADER_ERROR_PACKETS Reg Mask */
#define ENET_RXIPV4_HEADER_ERROR_PACKETS_MASK 0xFFFFFFFFu

/* RXIPV4_NO_PAYLOAD_PACKETS Bit Fields */
#define ENET_RXIPV4_NO_PAYLOAD_PACKETS_RXIPV4NOPAYPKT_MASK 0xFFFFFFFFu
#define ENET_RXIPV4_NO_PAYLOAD_PACKETS_RXIPV4NOPAYPKT_SHIFT 0u
#define ENET_RXIPV4_NO_PAYLOAD_PACKETS_RXIPV4NOPAYPKT_WIDTH 32u
#define ENET_RXIPV4_NO_PAYLOAD_PACKETS_RXIPV4NOPAYPKT(x) (((uint32_t)(((uint32_t)(x))<<ENET_RXIPV4_NO_PAYLOAD_PACKETS_RXIPV4NOPAYPKT_SHIFT))&ENET_RXIPV4_NO_PAYLOAD_PACKETS_RXIPV4NOPAYPKT_MASK)
/* RXIPV4_NO_PAYLOAD_PACKETS Reg Mask */
#define ENET_RXIPV4_NO_PAYLOAD_PACKETS_MASK 0xFFFFFFFFu

/* RXIPV4_FRAGMENTED_PACKETS Bit Fields */
#define ENET_RXIPV4_FRAGMENTED_PACKETS_RXIPV4FRAGPKT_MASK 0xFFFFFFFFu
#define ENET_RXIPV4_FRAGMENTED_PACKETS_RXIPV4FRAGPKT_SHIFT 0u
#define ENET_RXIPV4_FRAGMENTED_PACKETS_RXIPV4FRAGPKT_WIDTH 32u
#define ENET_RXIPV4_FRAGMENTED_PACKETS_RXIPV4FRAGPKT(x) (((uint32_t)(((uint32_t)(x))<<ENET_RXIPV4_FRAGMENTED_PACKETS_RXIPV4FRAGPKT_SHIFT))&ENET_RXIPV4_FRAGMENTED_PACKETS_RXIPV4FRAGPKT_MASK)
/* RXIPV4_FRAGMENTED_PACKETS Reg Mask */
#define ENET_RXIPV4_FRAGMENTED_PACKETS_MASK 0xFFFFFFFFu

/* RXIPV4_UDP_CHECKSUM_DISABLED_PACKETS Bit Fields */
#define ENET_RXIPV4_UDP_CHECKSUM_DISABLED_PACKETS_RXIPV4UDSBLPKT_MASK 0xFFFFFFFFu
#define ENET_RXIPV4_UDP_CHECKSUM_DISABLED_PACKETS_RXIPV4UDSBLPKT_SHIFT 0u
#define ENET_RXIPV4_UDP_CHECKSUM_DISABLED_PACKETS_RXIPV4UDSBLPKT_WIDTH 32u
#define ENET_RXIPV4_UDP_CHECKSUM_DISABLED_PACKETS_RXIPV4UDSBLPKT(x) (((uint32_t)(((uint32_t)(x))<<ENET_RXIPV4_UDP_CHECKSUM_DISABLED_PACKETS_RXIPV4UDSBLPKT_SHIFT))&ENET_RXIPV4_UDP_CHECKSUM_DISABLED_PACKETS_RXIPV4UDSBLPKT_MASK)
/* RXIPV4_UDP_CHECKSUM_DISABLED_PACKETS Reg Mask */
#define ENET_RXIPV4_UDP_CHECKSUM_DISABLED_PACKETS_MASK 0xFFFFFFFFu

/* RXIPV6_GOOD_PACKETS Bit Fields */
#define ENET_RXIPV6_GOOD_PACKETS_RXIPV6GDPKT_MASK 0xFFFFFFFFu
#define ENET_RXIPV6_GOOD_PACKETS_RXIPV6GDPKT_SHIFT 0u
#define ENET_RXIPV6_GOOD_PACKETS_RXIPV6GDPKT_WIDTH 32u
#define ENET_RXIPV6_GOOD_PACKETS_RXIPV6GDPKT(x) (((uint32_t)(((uint32_t)(x))<<ENET_RXIPV6_GOOD_PACKETS_RXIPV6GDPKT_SHIFT))&ENET_RXIPV6_GOOD_PACKETS_RXIPV6GDPKT_MASK)
/* RXIPV6_GOOD_PACKETS Reg Mask */
#define ENET_RXIPV6_GOOD_PACKETS_MASK  0xFFFFFFFFu

/* RXIPV6_HEADER_ERROR_PACKETS Bit Fields */
#define ENET_RXIPV6_HEADER_ERROR_PACKETS_RXIPV6HDRERRPKT_MASK 0xFFFFFFFFu
#define ENET_RXIPV6_HEADER_ERROR_PACKETS_RXIPV6HDRERRPKT_SHIFT 0u
#define ENET_RXIPV6_HEADER_ERROR_PACKETS_RXIPV6HDRERRPKT_WIDTH 32u
#define ENET_RXIPV6_HEADER_ERROR_PACKETS_RXIPV6HDRERRPKT(x) (((uint32_t)(((uint32_t)(x))<<ENET_RXIPV6_HEADER_ERROR_PACKETS_RXIPV6HDRERRPKT_SHIFT))&ENET_RXIPV6_HEADER_ERROR_PACKETS_RXIPV6HDRERRPKT_MASK)
/* RXIPV6_HEADER_ERROR_PACKETS Reg Mask */
#define ENET_RXIPV6_HEADER_ERROR_PACKETS_MASK 0xFFFFFFFFu

/* RXIPV6_NO_PAYLOAD_PACKETS Bit Fields */
#define ENET_RXIPV6_NO_PAYLOAD_PACKETS_RXIPV6NOPAYPKT_MASK 0xFFFFFFFFu
#define ENET_RXIPV6_NO_PAYLOAD_PACKETS_RXIPV6NOPAYPKT_SHIFT 0u
#define ENET_RXIPV6_NO_PAYLOAD_PACKETS_RXIPV6NOPAYPKT_WIDTH 32u
#define ENET_RXIPV6_NO_PAYLOAD_PACKETS_RXIPV6NOPAYPKT(x) (((uint32_t)(((uint32_t)(x))<<ENET_RXIPV6_NO_PAYLOAD_PACKETS_RXIPV6NOPAYPKT_SHIFT))&ENET_RXIPV6_NO_PAYLOAD_PACKETS_RXIPV6NOPAYPKT_MASK)
/* RXIPV6_NO_PAYLOAD_PACKETS Reg Mask */
#define ENET_RXIPV6_NO_PAYLOAD_PACKETS_MASK 0xFFFFFFFFu

/* RXUDP_GOOD_PACKETS Bit Fields */
#define ENET_RXUDP_GOOD_PACKETS_RXUDPGDPKT_MASK 0xFFFFFFFFu
#define ENET_RXUDP_GOOD_PACKETS_RXUDPGDPKT_SHIFT 0u
#define ENET_RXUDP_GOOD_PACKETS_RXUDPGDPKT_WIDTH 32u
#define ENET_RXUDP_GOOD_PACKETS_RXUDPGDPKT(x) (((uint32_t)(((uint32_t)(x))<<ENET_RXUDP_GOOD_PACKETS_RXUDPGDPKT_SHIFT))&ENET_RXUDP_GOOD_PACKETS_RXUDPGDPKT_MASK)
/* RXUDP_GOOD_PACKETS Reg Mask */
#define ENET_RXUDP_GOOD_PACKETS_MASK   0xFFFFFFFFu

/* RXUDP_ERROR_PACKETS Bit Fields */
#define ENET_RXUDP_ERROR_PACKETS_RXUDPERRPKT_MASK 0xFFFFFFFFu
#define ENET_RXUDP_ERROR_PACKETS_RXUDPERRPKT_SHIFT 0u
#define ENET_RXUDP_ERROR_PACKETS_RXUDPERRPKT_WIDTH 32u
#define ENET_RXUDP_ERROR_PACKETS_RXUDPERRPKT(x) (((uint32_t)(((uint32_t)(x))<<ENET_RXUDP_ERROR_PACKETS_RXUDPERRPKT_SHIFT))&ENET_RXUDP_ERROR_PACKETS_RXUDPERRPKT_MASK)
/* RXUDP_ERROR_PACKETS Reg Mask */
#define ENET_RXUDP_ERROR_PACKETS_MASK  0xFFFFFFFFu

/* RXTCP_GOOD_PACKETS Bit Fields */
#define ENET_RXTCP_GOOD_PACKETS_RXTCPGDPKT_MASK 0xFFFFFFFFu
#define ENET_RXTCP_GOOD_PACKETS_RXTCPGDPKT_SHIFT 0u
#define ENET_RXTCP_GOOD_PACKETS_RXTCPGDPKT_WIDTH 32u
#define ENET_RXTCP_GOOD_PACKETS_RXTCPGDPKT(x) (((uint32_t)(((uint32_t)(x))<<ENET_RXTCP_GOOD_PACKETS_RXTCPGDPKT_SHIFT))&ENET_RXTCP_GOOD_PACKETS_RXTCPGDPKT_MASK)
/* RXTCP_GOOD_PACKETS Reg Mask */
#define ENET_RXTCP_GOOD_PACKETS_MASK   0xFFFFFFFFu

/* RXTCP_ERROR_PACKETS Bit Fields */
#define ENET_RXTCP_ERROR_PACKETS_RXTCPERRPKT_MASK 0xFFFFFFFFu
#define ENET_RXTCP_ERROR_PACKETS_RXTCPERRPKT_SHIFT 0u
#define ENET_RXTCP_ERROR_PACKETS_RXTCPERRPKT_WIDTH 32u
#define ENET_RXTCP_ERROR_PACKETS_RXTCPERRPKT(x) (((uint32_t)(((uint32_t)(x))<<ENET_RXTCP_ERROR_PACKETS_RXTCPERRPKT_SHIFT))&ENET_RXTCP_ERROR_PACKETS_RXTCPERRPKT_MASK)
/* RXTCP_ERROR_PACKETS Reg Mask */
#define ENET_RXTCP_ERROR_PACKETS_MASK  0xFFFFFFFFu

/* RXICMP_GOOD_PACKETS Bit Fields */
#define ENET_RXICMP_GOOD_PACKETS_RXICMPGDPKT_MASK 0xFFFFFFFFu
#define ENET_RXICMP_GOOD_PACKETS_RXICMPGDPKT_SHIFT 0u
#define ENET_RXICMP_GOOD_PACKETS_RXICMPGDPKT_WIDTH 32u
#define ENET_RXICMP_GOOD_PACKETS_RXICMPGDPKT(x) (((uint32_t)(((uint32_t)(x))<<ENET_RXICMP_GOOD_PACKETS_RXICMPGDPKT_SHIFT))&ENET_RXICMP_GOOD_PACKETS_RXICMPGDPKT_MASK)
/* RXICMP_GOOD_PACKETS Reg Mask */
#define ENET_RXICMP_GOOD_PACKETS_MASK  0xFFFFFFFFu

/* RXICMP_ERROR_PACKETS Bit Fields */
#define ENET_RXICMP_ERROR_PACKETS_RXICMPERRPKT_MASK 0xFFFFFFFFu
#define ENET_RXICMP_ERROR_PACKETS_RXICMPERRPKT_SHIFT 0u
#define ENET_RXICMP_ERROR_PACKETS_RXICMPERRPKT_WIDTH 32u
#define ENET_RXICMP_ERROR_PACKETS_RXICMPERRPKT(x) (((uint32_t)(((uint32_t)(x))<<ENET_RXICMP_ERROR_PACKETS_RXICMPERRPKT_SHIFT))&ENET_RXICMP_ERROR_PACKETS_RXICMPERRPKT_MASK)
/* RXICMP_ERROR_PACKETS Reg Mask */
#define ENET_RXICMP_ERROR_PACKETS_MASK 0xFFFFFFFFu

/* RXIPV4_GOOD_OCTETS Bit Fields */
#define ENET_RXIPV4_GOOD_OCTETS_RXIPV4GDOCT_MASK 0xFFFFFFFFu
#define ENET_RXIPV4_GOOD_OCTETS_RXIPV4GDOCT_SHIFT 0u
#define ENET_RXIPV4_GOOD_OCTETS_RXIPV4GDOCT_WIDTH 32u
#define ENET_RXIPV4_GOOD_OCTETS_RXIPV4GDOCT(x) (((uint32_t)(((uint32_t)(x))<<ENET_RXIPV4_GOOD_OCTETS_RXIPV4GDOCT_SHIFT))&ENET_RXIPV4_GOOD_OCTETS_RXIPV4GDOCT_MASK)
/* RXIPV4_GOOD_OCTETS Reg Mask */
#define ENET_RXIPV4_GOOD_OCTETS_MASK   0xFFFFFFFFu

/* RXIPV4_HEADER_ERROR_OCTETS Bit Fields */
#define ENET_RXIPV4_HEADER_ERROR_OCTETS_RXIPV4HDRERROCT_MASK 0xFFFFFFFFu
#define ENET_RXIPV4_HEADER_ERROR_OCTETS_RXIPV4HDRERROCT_SHIFT 0u
#define ENET_RXIPV4_HEADER_ERROR_OCTETS_RXIPV4HDRERROCT_WIDTH 32u
#define ENET_RXIPV4_HEADER_ERROR_OCTETS_RXIPV4HDRERROCT(x) (((uint32_t)(((uint32_t)(x))<<ENET_RXIPV4_HEADER_ERROR_OCTETS_RXIPV4HDRERROCT_SHIFT))&ENET_RXIPV4_HEADER_ERROR_OCTETS_RXIPV4HDRERROCT_MASK)
/* RXIPV4_HEADER_ERROR_OCTETS Reg Mask */
#define ENET_RXIPV4_HEADER_ERROR_OCTETS_MASK 0xFFFFFFFFu

/* RXIPV4_NO_PAYLOAD_OCTETS Bit Fields */
#define ENET_RXIPV4_NO_PAYLOAD_OCTETS_RXIPV4NOPAYOCT_MASK 0xFFFFFFFFu
#define ENET_RXIPV4_NO_PAYLOAD_OCTETS_RXIPV4NOPAYOCT_SHIFT 0u
#define ENET_RXIPV4_NO_PAYLOAD_OCTETS_RXIPV4NOPAYOCT_WIDTH 32u
#define ENET_RXIPV4_NO_PAYLOAD_OCTETS_RXIPV4NOPAYOCT(x) (((uint32_t)(((uint32_t)(x))<<ENET_RXIPV4_NO_PAYLOAD_OCTETS_RXIPV4NOPAYOCT_SHIFT))&ENET_RXIPV4_NO_PAYLOAD_OCTETS_RXIPV4NOPAYOCT_MASK)
/* RXIPV4_NO_PAYLOAD_OCTETS Reg Mask */
#define ENET_RXIPV4_NO_PAYLOAD_OCTETS_MASK 0xFFFFFFFFu

/* RXIPV4_FRAGMENTED_OCTETS Bit Fields */
#define ENET_RXIPV4_FRAGMENTED_OCTETS_RXIPV4FRAGOCT_MASK 0xFFFFFFFFu
#define ENET_RXIPV4_FRAGMENTED_OCTETS_RXIPV4FRAGOCT_SHIFT 0u
#define ENET_RXIPV4_FRAGMENTED_OCTETS_RXIPV4FRAGOCT_WIDTH 32u
#define ENET_RXIPV4_FRAGMENTED_OCTETS_RXIPV4FRAGOCT(x) (((uint32_t)(((uint32_t)(x))<<ENET_RXIPV4_FRAGMENTED_OCTETS_RXIPV4FRAGOCT_SHIFT))&ENET_RXIPV4_FRAGMENTED_OCTETS_RXIPV4FRAGOCT_MASK)
/* RXIPV4_FRAGMENTED_OCTETS Reg Mask */
#define ENET_RXIPV4_FRAGMENTED_OCTETS_MASK 0xFFFFFFFFu

/* RXIPV4_UDP_CHECKSUM_DISABLE_OCTETS Bit Fields */
#define ENET_RXIPV4_UDP_CHECKSUM_DISABLE_OCTETS_RXIPV4UDSBLOCT_MASK 0xFFFFFFFFu
#define ENET_RXIPV4_UDP_CHECKSUM_DISABLE_OCTETS_RXIPV4UDSBLOCT_SHIFT 0u
#define ENET_RXIPV4_UDP_CHECKSUM_DISABLE_OCTETS_RXIPV4UDSBLOCT_WIDTH 32u
#define ENET_RXIPV4_UDP_CHECKSUM_DISABLE_OCTETS_RXIPV4UDSBLOCT(x) (((uint32_t)(((uint32_t)(x))<<ENET_RXIPV4_UDP_CHECKSUM_DISABLE_OCTETS_RXIPV4UDSBLOCT_SHIFT))&ENET_RXIPV4_UDP_CHECKSUM_DISABLE_OCTETS_RXIPV4UDSBLOCT_MASK)
/* RXIPV4_UDP_CHECKSUM_DISABLE_OCTETS Reg Mask */
#define ENET_RXIPV4_UDP_CHECKSUM_DISABLE_OCTETS_MASK 0xFFFFFFFFu

/* RXIPV6_GOOD_OCTETS Bit Fields */
#define ENET_RXIPV6_GOOD_OCTETS_RXIPV6GDOCT_MASK 0xFFFFFFFFu
#define ENET_RXIPV6_GOOD_OCTETS_RXIPV6GDOCT_SHIFT 0u
#define ENET_RXIPV6_GOOD_OCTETS_RXIPV6GDOCT_WIDTH 32u
#define ENET_RXIPV6_GOOD_OCTETS_RXIPV6GDOCT(x) (((uint32_t)(((uint32_t)(x))<<ENET_RXIPV6_GOOD_OCTETS_RXIPV6GDOCT_SHIFT))&ENET_RXIPV6_GOOD_OCTETS_RXIPV6GDOCT_MASK)
/* RXIPV6_GOOD_OCTETS Reg Mask */
#define ENET_RXIPV6_GOOD_OCTETS_MASK   0xFFFFFFFFu

/* RXIPV6_HEADER_ERROR_OCTETS Bit Fields */
#define ENET_RXIPV6_HEADER_ERROR_OCTETS_RXIPV6HDRERROCT_MASK 0xFFFFFFFFu
#define ENET_RXIPV6_HEADER_ERROR_OCTETS_RXIPV6HDRERROCT_SHIFT 0u
#define ENET_RXIPV6_HEADER_ERROR_OCTETS_RXIPV6HDRERROCT_WIDTH 32u
#define ENET_RXIPV6_HEADER_ERROR_OCTETS_RXIPV6HDRERROCT(x) (((uint32_t)(((uint32_t)(x))<<ENET_RXIPV6_HEADER_ERROR_OCTETS_RXIPV6HDRERROCT_SHIFT))&ENET_RXIPV6_HEADER_ERROR_OCTETS_RXIPV6HDRERROCT_MASK)
/* RXIPV6_HEADER_ERROR_OCTETS Reg Mask */
#define ENET_RXIPV6_HEADER_ERROR_OCTETS_MASK 0xFFFFFFFFu

/* RXIPV6_NO_PAYLOAD_OCTETS Bit Fields */
#define ENET_RXIPV6_NO_PAYLOAD_OCTETS_RXIPV6NOPAYOCT_MASK 0xFFFFFFFFu
#define ENET_RXIPV6_NO_PAYLOAD_OCTETS_RXIPV6NOPAYOCT_SHIFT 0u
#define ENET_RXIPV6_NO_PAYLOAD_OCTETS_RXIPV6NOPAYOCT_WIDTH 32u
#define ENET_RXIPV6_NO_PAYLOAD_OCTETS_RXIPV6NOPAYOCT(x) (((uint32_t)(((uint32_t)(x))<<ENET_RXIPV6_NO_PAYLOAD_OCTETS_RXIPV6NOPAYOCT_SHIFT))&ENET_RXIPV6_NO_PAYLOAD_OCTETS_RXIPV6NOPAYOCT_MASK)
/* RXIPV6_NO_PAYLOAD_OCTETS Reg Mask */
#define ENET_RXIPV6_NO_PAYLOAD_OCTETS_MASK 0xFFFFFFFFu

/* RXUDP_GOOD_OCTETS Bit Fields */
#define ENET_RXUDP_GOOD_OCTETS_RXUDPGDOCT_MASK 0xFFFFFFFFu
#define ENET_RXUDP_GOOD_OCTETS_RXUDPGDOCT_SHIFT 0u
#define ENET_RXUDP_GOOD_OCTETS_RXUDPGDOCT_WIDTH 32u
#define ENET_RXUDP_GOOD_OCTETS_RXUDPGDOCT(x) (((uint32_t)(((uint32_t)(x))<<ENET_RXUDP_GOOD_OCTETS_RXUDPGDOCT_SHIFT))&ENET_RXUDP_GOOD_OCTETS_RXUDPGDOCT_MASK)
/* RXUDP_GOOD_OCTETS Reg Mask */
#define ENET_RXUDP_GOOD_OCTETS_MASK    0xFFFFFFFFu

/* RXUDP_ERROR_OCTETS Bit Fields */
#define ENET_RXUDP_ERROR_OCTETS_RXUDPERROCT_MASK 0xFFFFFFFFu
#define ENET_RXUDP_ERROR_OCTETS_RXUDPERROCT_SHIFT 0u
#define ENET_RXUDP_ERROR_OCTETS_RXUDPERROCT_WIDTH 32u
#define ENET_RXUDP_ERROR_OCTETS_RXUDPERROCT(x) (((uint32_t)(((uint32_t)(x))<<ENET_RXUDP_ERROR_OCTETS_RXUDPERROCT_SHIFT))&ENET_RXUDP_ERROR_OCTETS_RXUDPERROCT_MASK)
/* RXUDP_ERROR_OCTETS Reg Mask */
#define ENET_RXUDP_ERROR_OCTETS_MASK   0xFFFFFFFFu

/* RXTCP_GOOD_OCTETS Bit Fields */
#define ENET_RXTCP_GOOD_OCTETS_RXTCPGDOCT_MASK 0xFFFFFFFFu
#define ENET_RXTCP_GOOD_OCTETS_RXTCPGDOCT_SHIFT 0u
#define ENET_RXTCP_GOOD_OCTETS_RXTCPGDOCT_WIDTH 32u
#define ENET_RXTCP_GOOD_OCTETS_RXTCPGDOCT(x) (((uint32_t)(((uint32_t)(x))<<ENET_RXTCP_GOOD_OCTETS_RXTCPGDOCT_SHIFT))&ENET_RXTCP_GOOD_OCTETS_RXTCPGDOCT_MASK)
/* RXTCP_GOOD_OCTETS Reg Mask */
#define ENET_RXTCP_GOOD_OCTETS_MASK    0xFFFFFFFFu

/* RXTCP_ERROR_OCTETS Bit Fields */
#define ENET_RXTCP_ERROR_OCTETS_RXTCPERROCT_MASK 0xFFFFFFFFu
#define ENET_RXTCP_ERROR_OCTETS_RXTCPERROCT_SHIFT 0u
#define ENET_RXTCP_ERROR_OCTETS_RXTCPERROCT_WIDTH 32u
#define ENET_RXTCP_ERROR_OCTETS_RXTCPERROCT(x) (((uint32_t)(((uint32_t)(x))<<ENET_RXTCP_ERROR_OCTETS_RXTCPERROCT_SHIFT))&ENET_RXTCP_ERROR_OCTETS_RXTCPERROCT_MASK)
/* RXTCP_ERROR_OCTETS Reg Mask */
#define ENET_RXTCP_ERROR_OCTETS_MASK   0xFFFFFFFFu

/* RXICMP_GOOD_OCTETS Bit Fields */
#define ENET_RXICMP_GOOD_OCTETS_RXICMPGDOCT_MASK 0xFFFFFFFFu
#define ENET_RXICMP_GOOD_OCTETS_RXICMPGDOCT_SHIFT 0u
#define ENET_RXICMP_GOOD_OCTETS_RXICMPGDOCT_WIDTH 32u
#define ENET_RXICMP_GOOD_OCTETS_RXICMPGDOCT(x) (((uint32_t)(((uint32_t)(x))<<ENET_RXICMP_GOOD_OCTETS_RXICMPGDOCT_SHIFT))&ENET_RXICMP_GOOD_OCTETS_RXICMPGDOCT_MASK)
/* RXICMP_GOOD_OCTETS Reg Mask */
#define ENET_RXICMP_GOOD_OCTETS_MASK   0xFFFFFFFFu

/* RXICMP_ERROR_OCTETS Bit Fields */
#define ENET_RXICMP_ERROR_OCTETS_RXICMPERROCT_MASK 0xFFFFFFFFu
#define ENET_RXICMP_ERROR_OCTETS_RXICMPERROCT_SHIFT 0u
#define ENET_RXICMP_ERROR_OCTETS_RXICMPERROCT_WIDTH 32u
#define ENET_RXICMP_ERROR_OCTETS_RXICMPERROCT(x) (((uint32_t)(((uint32_t)(x))<<ENET_RXICMP_ERROR_OCTETS_RXICMPERROCT_SHIFT))&ENET_RXICMP_ERROR_OCTETS_RXICMPERROCT_MASK)
/* RXICMP_ERROR_OCTETS Reg Mask */
#define ENET_RXICMP_ERROR_OCTETS_MASK  0xFFFFFFFFu

/* MMC_FPE_TX_INTERRUPT Bit Fields */
#define ENET_MMC_FPE_TX_INTERRUPT_HRCIS_MASK 0x2u
#define ENET_MMC_FPE_TX_INTERRUPT_HRCIS_SHIFT 1u
#define ENET_MMC_FPE_TX_INTERRUPT_HRCIS_WIDTH 1u
#define ENET_MMC_FPE_TX_INTERRUPT_HRCIS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_FPE_TX_INTERRUPT_HRCIS_SHIFT))&ENET_MMC_FPE_TX_INTERRUPT_HRCIS_MASK)
#define ENET_MMC_FPE_TX_INTERRUPT_FCIS_MASK 0x1u
#define ENET_MMC_FPE_TX_INTERRUPT_FCIS_SHIFT 0u
#define ENET_MMC_FPE_TX_INTERRUPT_FCIS_WIDTH 1u
#define ENET_MMC_FPE_TX_INTERRUPT_FCIS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_FPE_TX_INTERRUPT_FCIS_SHIFT))&ENET_MMC_FPE_TX_INTERRUPT_FCIS_MASK)
/* MMC_FPE_TX_INTERRUPT Reg Mask */
#define ENET_MMC_FPE_TX_INTERRUPT_MASK 0x00000003u

/* MMC_FPE_TX_INTERRUPT_MASK Bit Fields */
#define ENET_MMC_FPE_TX_INTERRUPT_MASK_HRCIM_MASK 0x2u
#define ENET_MMC_FPE_TX_INTERRUPT_MASK_HRCIM_SHIFT 1u
#define ENET_MMC_FPE_TX_INTERRUPT_MASK_HRCIM_WIDTH 1u
#define ENET_MMC_FPE_TX_INTERRUPT_MASK_HRCIM(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_FPE_TX_INTERRUPT_MASK_HRCIM_SHIFT))&ENET_MMC_FPE_TX_INTERRUPT_MASK_HRCIM_MASK)
#define ENET_MMC_FPE_TX_INTERRUPT_MASK_FCIM_MASK 0x1u
#define ENET_MMC_FPE_TX_INTERRUPT_MASK_FCIM_SHIFT 0u
#define ENET_MMC_FPE_TX_INTERRUPT_MASK_FCIM_WIDTH 1u
#define ENET_MMC_FPE_TX_INTERRUPT_MASK_FCIM(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_FPE_TX_INTERRUPT_MASK_FCIM_SHIFT))&ENET_MMC_FPE_TX_INTERRUPT_MASK_FCIM_MASK)
/* MMC_FPE_TX_INTERRUPT_MASK Reg Mask */
#define ENET_MMC_FPE_TX_INTERRUPT_MASK_MASK 0x00000003u

/* MMC_TX_FPE_FRAGMENT_CNTR Bit Fields */
#define ENET_MMC_TX_FPE_FRAGMENT_CNTR_TXFFC_MASK 0xFFFFFFFFu
#define ENET_MMC_TX_FPE_FRAGMENT_CNTR_TXFFC_SHIFT 0u
#define ENET_MMC_TX_FPE_FRAGMENT_CNTR_TXFFC_WIDTH 32u
#define ENET_MMC_TX_FPE_FRAGMENT_CNTR_TXFFC(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_TX_FPE_FRAGMENT_CNTR_TXFFC_SHIFT))&ENET_MMC_TX_FPE_FRAGMENT_CNTR_TXFFC_MASK)
/* MMC_TX_FPE_FRAGMENT_CNTR Reg Mask */
#define ENET_MMC_TX_FPE_FRAGMENT_CNTR_MASK 0xFFFFFFFFu

/* MMC_TX_HOLD_REQ_CNTR Bit Fields */
#define ENET_MMC_TX_HOLD_REQ_CNTR_TXHRC_MASK 0xFFFFFFFFu
#define ENET_MMC_TX_HOLD_REQ_CNTR_TXHRC_SHIFT 0u
#define ENET_MMC_TX_HOLD_REQ_CNTR_TXHRC_WIDTH 32u
#define ENET_MMC_TX_HOLD_REQ_CNTR_TXHRC(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_TX_HOLD_REQ_CNTR_TXHRC_SHIFT))&ENET_MMC_TX_HOLD_REQ_CNTR_TXHRC_MASK)
/* MMC_TX_HOLD_REQ_CNTR Reg Mask */
#define ENET_MMC_TX_HOLD_REQ_CNTR_MASK 0xFFFFFFFFu

/* MMC_FPE_RX_INTERRUPT Bit Fields */
#define ENET_MMC_FPE_RX_INTERRUPT_FCIS_MASK 0x8u
#define ENET_MMC_FPE_RX_INTERRUPT_FCIS_SHIFT 3u
#define ENET_MMC_FPE_RX_INTERRUPT_FCIS_WIDTH 1u
#define ENET_MMC_FPE_RX_INTERRUPT_FCIS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_FPE_RX_INTERRUPT_FCIS_SHIFT))&ENET_MMC_FPE_RX_INTERRUPT_FCIS_MASK)
#define ENET_MMC_FPE_RX_INTERRUPT_PAOCIS_MASK 0x4u
#define ENET_MMC_FPE_RX_INTERRUPT_PAOCIS_SHIFT 2u
#define ENET_MMC_FPE_RX_INTERRUPT_PAOCIS_WIDTH 1u
#define ENET_MMC_FPE_RX_INTERRUPT_PAOCIS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_FPE_RX_INTERRUPT_PAOCIS_SHIFT))&ENET_MMC_FPE_RX_INTERRUPT_PAOCIS_MASK)
#define ENET_MMC_FPE_RX_INTERRUPT_PSECIS_MASK 0x2u
#define ENET_MMC_FPE_RX_INTERRUPT_PSECIS_SHIFT 1u
#define ENET_MMC_FPE_RX_INTERRUPT_PSECIS_WIDTH 1u
#define ENET_MMC_FPE_RX_INTERRUPT_PSECIS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_FPE_RX_INTERRUPT_PSECIS_SHIFT))&ENET_MMC_FPE_RX_INTERRUPT_PSECIS_MASK)
#define ENET_MMC_FPE_RX_INTERRUPT_PAECIS_MASK 0x1u
#define ENET_MMC_FPE_RX_INTERRUPT_PAECIS_SHIFT 0u
#define ENET_MMC_FPE_RX_INTERRUPT_PAECIS_WIDTH 1u
#define ENET_MMC_FPE_RX_INTERRUPT_PAECIS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_FPE_RX_INTERRUPT_PAECIS_SHIFT))&ENET_MMC_FPE_RX_INTERRUPT_PAECIS_MASK)
/* MMC_FPE_RX_INTERRUPT Reg Mask */
#define ENET_MMC_FPE_RX_INTERRUPT_MASK 0x0000000Fu

/* MMC_FPE_RX_INTERRUPT_MASK Bit Fields */
#define ENET_MMC_FPE_RX_INTERRUPT_MASK_FCIM_MASK 0x8u
#define ENET_MMC_FPE_RX_INTERRUPT_MASK_FCIM_SHIFT 3u
#define ENET_MMC_FPE_RX_INTERRUPT_MASK_FCIM_WIDTH 1u
#define ENET_MMC_FPE_RX_INTERRUPT_MASK_FCIM(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_FPE_RX_INTERRUPT_MASK_FCIM_SHIFT))&ENET_MMC_FPE_RX_INTERRUPT_MASK_FCIM_MASK)
#define ENET_MMC_FPE_RX_INTERRUPT_MASK_PAOCIM_MASK 0x4u
#define ENET_MMC_FPE_RX_INTERRUPT_MASK_PAOCIM_SHIFT 2u
#define ENET_MMC_FPE_RX_INTERRUPT_MASK_PAOCIM_WIDTH 1u
#define ENET_MMC_FPE_RX_INTERRUPT_MASK_PAOCIM(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_FPE_RX_INTERRUPT_MASK_PAOCIM_SHIFT))&ENET_MMC_FPE_RX_INTERRUPT_MASK_PAOCIM_MASK)
#define ENET_MMC_FPE_RX_INTERRUPT_MASK_PSECIM_MASK 0x2u
#define ENET_MMC_FPE_RX_INTERRUPT_MASK_PSECIM_SHIFT 1u
#define ENET_MMC_FPE_RX_INTERRUPT_MASK_PSECIM_WIDTH 1u
#define ENET_MMC_FPE_RX_INTERRUPT_MASK_PSECIM(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_FPE_RX_INTERRUPT_MASK_PSECIM_SHIFT))&ENET_MMC_FPE_RX_INTERRUPT_MASK_PSECIM_MASK)
#define ENET_MMC_FPE_RX_INTERRUPT_MASK_PAECIM_MASK 0x1u
#define ENET_MMC_FPE_RX_INTERRUPT_MASK_PAECIM_SHIFT 0u
#define ENET_MMC_FPE_RX_INTERRUPT_MASK_PAECIM_WIDTH 1u
#define ENET_MMC_FPE_RX_INTERRUPT_MASK_PAECIM(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_FPE_RX_INTERRUPT_MASK_PAECIM_SHIFT))&ENET_MMC_FPE_RX_INTERRUPT_MASK_PAECIM_MASK)
/* MMC_FPE_RX_INTERRUPT_MASK Reg Mask */
#define ENET_MMC_FPE_RX_INTERRUPT_MASK_MASK 0x0000000Fu

/* MMC_RX_PACKET_ASSEMBLY_ERR_CNTR Bit Fields */
#define ENET_MMC_RX_PACKET_ASSEMBLY_ERR_CNTR_PAEC_MASK 0xFFFFFFFFu
#define ENET_MMC_RX_PACKET_ASSEMBLY_ERR_CNTR_PAEC_SHIFT 0u
#define ENET_MMC_RX_PACKET_ASSEMBLY_ERR_CNTR_PAEC_WIDTH 32u
#define ENET_MMC_RX_PACKET_ASSEMBLY_ERR_CNTR_PAEC(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_RX_PACKET_ASSEMBLY_ERR_CNTR_PAEC_SHIFT))&ENET_MMC_RX_PACKET_ASSEMBLY_ERR_CNTR_PAEC_MASK)
/* MMC_RX_PACKET_ASSEMBLY_ERR_CNTR Reg Mask */
#define ENET_MMC_RX_PACKET_ASSEMBLY_ERR_CNTR_MASK 0xFFFFFFFFu

/* MMC_RX_PACKET_SMD_ERR_CNTR Bit Fields */
#define ENET_MMC_RX_PACKET_SMD_ERR_CNTR_PSEC_MASK 0xFFFFFFFFu
#define ENET_MMC_RX_PACKET_SMD_ERR_CNTR_PSEC_SHIFT 0u
#define ENET_MMC_RX_PACKET_SMD_ERR_CNTR_PSEC_WIDTH 32u
#define ENET_MMC_RX_PACKET_SMD_ERR_CNTR_PSEC(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_RX_PACKET_SMD_ERR_CNTR_PSEC_SHIFT))&ENET_MMC_RX_PACKET_SMD_ERR_CNTR_PSEC_MASK)
/* MMC_RX_PACKET_SMD_ERR_CNTR Reg Mask */
#define ENET_MMC_RX_PACKET_SMD_ERR_CNTR_MASK 0xFFFFFFFFu

/* MMC_RX_PACKET_ASSEMBLY_OK_CNTR Bit Fields */
#define ENET_MMC_RX_PACKET_ASSEMBLY_OK_CNTR_PAOC_MASK 0xFFFFFFFFu
#define ENET_MMC_RX_PACKET_ASSEMBLY_OK_CNTR_PAOC_SHIFT 0u
#define ENET_MMC_RX_PACKET_ASSEMBLY_OK_CNTR_PAOC_WIDTH 32u
#define ENET_MMC_RX_PACKET_ASSEMBLY_OK_CNTR_PAOC(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_RX_PACKET_ASSEMBLY_OK_CNTR_PAOC_SHIFT))&ENET_MMC_RX_PACKET_ASSEMBLY_OK_CNTR_PAOC_MASK)
/* MMC_RX_PACKET_ASSEMBLY_OK_CNTR Reg Mask */
#define ENET_MMC_RX_PACKET_ASSEMBLY_OK_CNTR_MASK 0xFFFFFFFFu

/* MMC_RX_FPE_FRAGMENT_CNTR Bit Fields */
#define ENET_MMC_RX_FPE_FRAGMENT_CNTR_FFC_MASK 0xFFFFFFFFu
#define ENET_MMC_RX_FPE_FRAGMENT_CNTR_FFC_SHIFT 0u
#define ENET_MMC_RX_FPE_FRAGMENT_CNTR_FFC_WIDTH 32u
#define ENET_MMC_RX_FPE_FRAGMENT_CNTR_FFC(x) (((uint32_t)(((uint32_t)(x))<<ENET_MMC_RX_FPE_FRAGMENT_CNTR_FFC_SHIFT))&ENET_MMC_RX_FPE_FRAGMENT_CNTR_FFC_MASK)
/* MMC_RX_FPE_FRAGMENT_CNTR Reg Mask */
#define ENET_MMC_RX_FPE_FRAGMENT_CNTR_MASK 0xFFFFFFFFu

/* MAC_L3_L4_CONTROL Bit Fields */
#define ENET_MAC_L3_L4_CONTROL_DMCHEN0_MASK 0x10000000u
#define ENET_MAC_L3_L4_CONTROL_DMCHEN0_SHIFT 28u
#define ENET_MAC_L3_L4_CONTROL_DMCHEN0_WIDTH 1u
#define ENET_MAC_L3_L4_CONTROL_DMCHEN0(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_L3_L4_CONTROL_DMCHEN0_SHIFT))&ENET_MAC_L3_L4_CONTROL_DMCHEN0_MASK)
#define ENET_MAC_L3_L4_CONTROL_DMCHN0_MASK 0x1000000u
#define ENET_MAC_L3_L4_CONTROL_DMCHN0_SHIFT 24u
#define ENET_MAC_L3_L4_CONTROL_DMCHN0_WIDTH 1u
#define ENET_MAC_L3_L4_CONTROL_DMCHN0(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_L3_L4_CONTROL_DMCHN0_SHIFT))&ENET_MAC_L3_L4_CONTROL_DMCHN0_MASK)
#define ENET_MAC_L3_L4_CONTROL_L4DPIM0_MASK 0x200000u
#define ENET_MAC_L3_L4_CONTROL_L4DPIM0_SHIFT 21u
#define ENET_MAC_L3_L4_CONTROL_L4DPIM0_WIDTH 1u
#define ENET_MAC_L3_L4_CONTROL_L4DPIM0(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_L3_L4_CONTROL_L4DPIM0_SHIFT))&ENET_MAC_L3_L4_CONTROL_L4DPIM0_MASK)
#define ENET_MAC_L3_L4_CONTROL_L4DPM0_MASK 0x100000u
#define ENET_MAC_L3_L4_CONTROL_L4DPM0_SHIFT 20u
#define ENET_MAC_L3_L4_CONTROL_L4DPM0_WIDTH 1u
#define ENET_MAC_L3_L4_CONTROL_L4DPM0(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_L3_L4_CONTROL_L4DPM0_SHIFT))&ENET_MAC_L3_L4_CONTROL_L4DPM0_MASK)
#define ENET_MAC_L3_L4_CONTROL_L4SPIM0_MASK 0x80000u
#define ENET_MAC_L3_L4_CONTROL_L4SPIM0_SHIFT 19u
#define ENET_MAC_L3_L4_CONTROL_L4SPIM0_WIDTH 1u
#define ENET_MAC_L3_L4_CONTROL_L4SPIM0(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_L3_L4_CONTROL_L4SPIM0_SHIFT))&ENET_MAC_L3_L4_CONTROL_L4SPIM0_MASK)
#define ENET_MAC_L3_L4_CONTROL_L4SPM0_MASK 0x40000u
#define ENET_MAC_L3_L4_CONTROL_L4SPM0_SHIFT 18u
#define ENET_MAC_L3_L4_CONTROL_L4SPM0_WIDTH 1u
#define ENET_MAC_L3_L4_CONTROL_L4SPM0(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_L3_L4_CONTROL_L4SPM0_SHIFT))&ENET_MAC_L3_L4_CONTROL_L4SPM0_MASK)
#define ENET_MAC_L3_L4_CONTROL_L4PEN0_MASK 0x10000u
#define ENET_MAC_L3_L4_CONTROL_L4PEN0_SHIFT 16u
#define ENET_MAC_L3_L4_CONTROL_L4PEN0_WIDTH 1u
#define ENET_MAC_L3_L4_CONTROL_L4PEN0(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_L3_L4_CONTROL_L4PEN0_SHIFT))&ENET_MAC_L3_L4_CONTROL_L4PEN0_MASK)
#define ENET_MAC_L3_L4_CONTROL_L3HDBM0_MASK 0xF800u
#define ENET_MAC_L3_L4_CONTROL_L3HDBM0_SHIFT 11u
#define ENET_MAC_L3_L4_CONTROL_L3HDBM0_WIDTH 5u
#define ENET_MAC_L3_L4_CONTROL_L3HDBM0(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_L3_L4_CONTROL_L3HDBM0_SHIFT))&ENET_MAC_L3_L4_CONTROL_L3HDBM0_MASK)
#define ENET_MAC_L3_L4_CONTROL_L3HSBM0_MASK 0x7C0u
#define ENET_MAC_L3_L4_CONTROL_L3HSBM0_SHIFT 6u
#define ENET_MAC_L3_L4_CONTROL_L3HSBM0_WIDTH 5u
#define ENET_MAC_L3_L4_CONTROL_L3HSBM0(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_L3_L4_CONTROL_L3HSBM0_SHIFT))&ENET_MAC_L3_L4_CONTROL_L3HSBM0_MASK)
#define ENET_MAC_L3_L4_CONTROL_L3DAIM0_MASK 0x20u
#define ENET_MAC_L3_L4_CONTROL_L3DAIM0_SHIFT 5u
#define ENET_MAC_L3_L4_CONTROL_L3DAIM0_WIDTH 1u
#define ENET_MAC_L3_L4_CONTROL_L3DAIM0(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_L3_L4_CONTROL_L3DAIM0_SHIFT))&ENET_MAC_L3_L4_CONTROL_L3DAIM0_MASK)
#define ENET_MAC_L3_L4_CONTROL_L3DAM0_MASK 0x10u
#define ENET_MAC_L3_L4_CONTROL_L3DAM0_SHIFT 4u
#define ENET_MAC_L3_L4_CONTROL_L3DAM0_WIDTH 1u
#define ENET_MAC_L3_L4_CONTROL_L3DAM0(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_L3_L4_CONTROL_L3DAM0_SHIFT))&ENET_MAC_L3_L4_CONTROL_L3DAM0_MASK)
#define ENET_MAC_L3_L4_CONTROL_L3SAIM0_MASK 0x8u
#define ENET_MAC_L3_L4_CONTROL_L3SAIM0_SHIFT 3u
#define ENET_MAC_L3_L4_CONTROL_L3SAIM0_WIDTH 1u
#define ENET_MAC_L3_L4_CONTROL_L3SAIM0(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_L3_L4_CONTROL_L3SAIM0_SHIFT))&ENET_MAC_L3_L4_CONTROL_L3SAIM0_MASK)
#define ENET_MAC_L3_L4_CONTROL_L3SAM0_MASK 0x4u
#define ENET_MAC_L3_L4_CONTROL_L3SAM0_SHIFT 2u
#define ENET_MAC_L3_L4_CONTROL_L3SAM0_WIDTH 1u
#define ENET_MAC_L3_L4_CONTROL_L3SAM0(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_L3_L4_CONTROL_L3SAM0_SHIFT))&ENET_MAC_L3_L4_CONTROL_L3SAM0_MASK)
#define ENET_MAC_L3_L4_CONTROL_L3PEN0_MASK 0x1u
#define ENET_MAC_L3_L4_CONTROL_L3PEN0_SHIFT 0u
#define ENET_MAC_L3_L4_CONTROL_L3PEN0_WIDTH 1u
#define ENET_MAC_L3_L4_CONTROL_L3PEN0(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_L3_L4_CONTROL_L3PEN0_SHIFT))&ENET_MAC_L3_L4_CONTROL_L3PEN0_MASK)
/* MAC_L3_L4_CONTROL0 Reg Mask */
#define ENET_MAC_L3_L4_CONTROL_MASK    0x113DFFFDu

/* MAC_LAYER4_ADDRESS Bit Fields */
#define ENET_MAC_LAYER4_ADDRESS_L4DP0_MASK 0xFFFF0000u
#define ENET_MAC_LAYER4_ADDRESS_L4DP0_SHIFT 16u
#define ENET_MAC_LAYER4_ADDRESS_L4DP0_WIDTH 16u
#define ENET_MAC_LAYER4_ADDRESS_L4DP0(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_LAYER4_ADDRESS_L4DP0_SHIFT))&ENET_MAC_LAYER4_ADDRESS_L4DP0_MASK)
#define ENET_MAC_LAYER4_ADDRESS_L4SP0_MASK 0xFFFFu
#define ENET_MAC_LAYER4_ADDRESS_L4SP0_SHIFT 0u
#define ENET_MAC_LAYER4_ADDRESS_L4SP0_WIDTH 16u
#define ENET_MAC_LAYER4_ADDRESS_L4SP0(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_LAYER4_ADDRESS_L4SP0_SHIFT))&ENET_MAC_LAYER4_ADDRESS_L4SP0_MASK)
/* MAC_LAYER4_ADDRESS0 Reg Mask */
#define ENET_MAC_LAYER4_ADDRESS_MASK   0xFFFFFFFFu

/* MAC_LAYER3_ADDR0_REG Bit Fields */
#define ENET_MAC_LAYER3_ADDR0_REG_L3A00_MASK 0xFFFFFFFFu
#define ENET_MAC_LAYER3_ADDR0_REG_L3A00_SHIFT 0u
#define ENET_MAC_LAYER3_ADDR0_REG_L3A00_WIDTH 32u
#define ENET_MAC_LAYER3_ADDR0_REG_L3A00(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_LAYER3_ADDR0_REG_L3A00_SHIFT))&ENET_MAC_LAYER3_ADDR0_REG_L3A00_MASK)
/* MAC_LAYER3_ADDR0_REG0 Reg Mask */
#define ENET_MAC_LAYER3_ADDR0_REG_MASK 0xFFFFFFFFu

/* MAC_LAYER3_ADDR1_REG Bit Fields */
#define ENET_MAC_LAYER3_ADDR1_REG_L3A10_MASK 0xFFFFFFFFu
#define ENET_MAC_LAYER3_ADDR1_REG_L3A10_SHIFT 0u
#define ENET_MAC_LAYER3_ADDR1_REG_L3A10_WIDTH 32u
#define ENET_MAC_LAYER3_ADDR1_REG_L3A10(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_LAYER3_ADDR1_REG_L3A10_SHIFT))&ENET_MAC_LAYER3_ADDR1_REG_L3A10_MASK)
/* MAC_LAYER3_ADDR1_REG0 Reg Mask */
#define ENET_MAC_LAYER3_ADDR1_REG_MASK 0xFFFFFFFFu

/* MAC_LAYER3_ADDR2_REG Bit Fields */
#define ENET_MAC_LAYER3_ADDR2_REG_L3A20_MASK 0xFFFFFFFFu
#define ENET_MAC_LAYER3_ADDR2_REG_L3A20_SHIFT 0u
#define ENET_MAC_LAYER3_ADDR2_REG_L3A20_WIDTH 32u
#define ENET_MAC_LAYER3_ADDR2_REG_L3A20(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_LAYER3_ADDR2_REG_L3A20_SHIFT))&ENET_MAC_LAYER3_ADDR2_REG_L3A20_MASK)
/* MAC_LAYER3_ADDR2_REG0 Reg Mask */
#define ENET_MAC_LAYER3_ADDR2_REG_MASK 0xFFFFFFFFu

/* MAC_LAYER3_ADDR3_REG Bit Fields */
#define ENET_MAC_LAYER3_ADDR3_REG_L3A30_MASK 0xFFFFFFFFu
#define ENET_MAC_LAYER3_ADDR3_REG_L3A30_SHIFT 0u
#define ENET_MAC_LAYER3_ADDR3_REG_L3A30_WIDTH 32u
#define ENET_MAC_LAYER3_ADDR3_REG_L3A30(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_LAYER3_ADDR3_REG_L3A30_SHIFT))&ENET_MAC_LAYER3_ADDR3_REG_L3A30_MASK)
/* MAC_LAYER3_ADDR3_REG0 Reg Mask */
#define ENET_MAC_LAYER3_ADDR3_REG_MASK 0xFFFFFFFFu

/* MAC_INDIR_ACCESS_CTRL Bit Fields */
#define ENET_MAC_INDIR_ACCESS_CTRL_MSEL_MASK 0xF0000u
#define ENET_MAC_INDIR_ACCESS_CTRL_MSEL_SHIFT 16u
#define ENET_MAC_INDIR_ACCESS_CTRL_MSEL_WIDTH 4u
#define ENET_MAC_INDIR_ACCESS_CTRL_MSEL(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_INDIR_ACCESS_CTRL_MSEL_SHIFT))&ENET_MAC_INDIR_ACCESS_CTRL_MSEL_MASK)
#define ENET_MAC_INDIR_ACCESS_CTRL_AOFF_MASK 0xFF00u
#define ENET_MAC_INDIR_ACCESS_CTRL_AOFF_SHIFT 8u
#define ENET_MAC_INDIR_ACCESS_CTRL_AOFF_WIDTH 8u
#define ENET_MAC_INDIR_ACCESS_CTRL_AOFF(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_INDIR_ACCESS_CTRL_AOFF_SHIFT))&ENET_MAC_INDIR_ACCESS_CTRL_AOFF_MASK)
#define ENET_MAC_INDIR_ACCESS_CTRL_AUTO_MASK 0x20u
#define ENET_MAC_INDIR_ACCESS_CTRL_AUTO_SHIFT 5u
#define ENET_MAC_INDIR_ACCESS_CTRL_AUTO_WIDTH 1u
#define ENET_MAC_INDIR_ACCESS_CTRL_AUTO(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_INDIR_ACCESS_CTRL_AUTO_SHIFT))&ENET_MAC_INDIR_ACCESS_CTRL_AUTO_MASK)
#define ENET_MAC_INDIR_ACCESS_CTRL_COM_MASK 0x2u
#define ENET_MAC_INDIR_ACCESS_CTRL_COM_SHIFT 1u
#define ENET_MAC_INDIR_ACCESS_CTRL_COM_WIDTH 1u
#define ENET_MAC_INDIR_ACCESS_CTRL_COM(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_INDIR_ACCESS_CTRL_COM_SHIFT))&ENET_MAC_INDIR_ACCESS_CTRL_COM_MASK)
#define ENET_MAC_INDIR_ACCESS_CTRL_OB_MASK 0x1u
#define ENET_MAC_INDIR_ACCESS_CTRL_OB_SHIFT 0u
#define ENET_MAC_INDIR_ACCESS_CTRL_OB_WIDTH 1u
#define ENET_MAC_INDIR_ACCESS_CTRL_OB(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_INDIR_ACCESS_CTRL_OB_SHIFT))&ENET_MAC_INDIR_ACCESS_CTRL_OB_MASK)
/* MAC_INDIR_ACCESS_CTRL Reg Mask */
#define ENET_MAC_INDIR_ACCESS_CTRL_MASK 0x000FFF23u

/* MAC_TMRQ_REGS Bit Fields */
#define ENET_MAC_TMRQ_REGS_PFEX_MASK   0x100000u
#define ENET_MAC_TMRQ_REGS_PFEX_SHIFT  20u
#define ENET_MAC_TMRQ_REGS_PFEX_WIDTH  1u
#define ENET_MAC_TMRQ_REGS_PFEX(x)     (((uint32_t)(((uint32_t)(x))<<ENET_MAC_TMRQ_REGS_PFEX_SHIFT))&ENET_MAC_TMRQ_REGS_PFEX_MASK)
#define ENET_MAC_TMRQ_REGS_TMRQ_MASK   0x70000u
#define ENET_MAC_TMRQ_REGS_TMRQ_SHIFT  16u
#define ENET_MAC_TMRQ_REGS_TMRQ_WIDTH  3u
#define ENET_MAC_TMRQ_REGS_TMRQ(x)     (((uint32_t)(((uint32_t)(x))<<ENET_MAC_TMRQ_REGS_TMRQ_SHIFT))&ENET_MAC_TMRQ_REGS_TMRQ_MASK)
#define ENET_MAC_TMRQ_REGS_TYP_MASK    0xFFFFu
#define ENET_MAC_TMRQ_REGS_TYP_SHIFT   0u
#define ENET_MAC_TMRQ_REGS_TYP_WIDTH   16u
#define ENET_MAC_TMRQ_REGS_TYP(x)      (((uint32_t)(((uint32_t)(x))<<ENET_MAC_TMRQ_REGS_TYP_SHIFT))&ENET_MAC_TMRQ_REGS_TYP_MASK)
/* MAC_TMRQ_REGS0 Reg Mask */
#define ENET_MAC_TMRQ_REGS_MASK        0x0017FFFFu

/* MAC_INDIR_ACCESS_DATA Bit Fields */
#define ENET_MAC_INDIR_ACCESS_DATA_DATA_MASK 0xFFFFFFFFu
#define ENET_MAC_INDIR_ACCESS_DATA_DATA_SHIFT 0u
#define ENET_MAC_INDIR_ACCESS_DATA_DATA_WIDTH 32u
#define ENET_MAC_INDIR_ACCESS_DATA_DATA(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_INDIR_ACCESS_DATA_DATA_SHIFT))&ENET_MAC_INDIR_ACCESS_DATA_DATA_MASK)
/* MAC_INDIR_ACCESS_DATA Reg Mask */
#define ENET_MAC_INDIR_ACCESS_DATA_MASK 0xFFFFFFFFu

/* MAC_TIMESTAMP_CONTROL Bit Fields */
#define ENET_MAC_TIMESTAMP_CONTROL_AV8021ASMEN_MASK 0x10000000u
#define ENET_MAC_TIMESTAMP_CONTROL_AV8021ASMEN_SHIFT 28u
#define ENET_MAC_TIMESTAMP_CONTROL_AV8021ASMEN_WIDTH 1u
#define ENET_MAC_TIMESTAMP_CONTROL_AV8021ASMEN(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_TIMESTAMP_CONTROL_AV8021ASMEN_SHIFT))&ENET_MAC_TIMESTAMP_CONTROL_AV8021ASMEN_MASK)
#define ENET_MAC_TIMESTAMP_CONTROL_TXTSSTSM_MASK 0x1000000u
#define ENET_MAC_TIMESTAMP_CONTROL_TXTSSTSM_SHIFT 24u
#define ENET_MAC_TIMESTAMP_CONTROL_TXTSSTSM_WIDTH 1u
#define ENET_MAC_TIMESTAMP_CONTROL_TXTSSTSM(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_TIMESTAMP_CONTROL_TXTSSTSM_SHIFT))&ENET_MAC_TIMESTAMP_CONTROL_TXTSSTSM_MASK)
#define ENET_MAC_TIMESTAMP_CONTROL_TSENMACADDR_MASK 0x40000u
#define ENET_MAC_TIMESTAMP_CONTROL_TSENMACADDR_SHIFT 18u
#define ENET_MAC_TIMESTAMP_CONTROL_TSENMACADDR_WIDTH 1u
#define ENET_MAC_TIMESTAMP_CONTROL_TSENMACADDR(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_TIMESTAMP_CONTROL_TSENMACADDR_SHIFT))&ENET_MAC_TIMESTAMP_CONTROL_TSENMACADDR_MASK)
#define ENET_MAC_TIMESTAMP_CONTROL_SNAPTYPSEL_MASK 0x30000u
#define ENET_MAC_TIMESTAMP_CONTROL_SNAPTYPSEL_SHIFT 16u
#define ENET_MAC_TIMESTAMP_CONTROL_SNAPTYPSEL_WIDTH 2u
#define ENET_MAC_TIMESTAMP_CONTROL_SNAPTYPSEL(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_TIMESTAMP_CONTROL_SNAPTYPSEL_SHIFT))&ENET_MAC_TIMESTAMP_CONTROL_SNAPTYPSEL_MASK)
#define ENET_MAC_TIMESTAMP_CONTROL_TSMSTRENA_MASK 0x8000u
#define ENET_MAC_TIMESTAMP_CONTROL_TSMSTRENA_SHIFT 15u
#define ENET_MAC_TIMESTAMP_CONTROL_TSMSTRENA_WIDTH 1u
#define ENET_MAC_TIMESTAMP_CONTROL_TSMSTRENA(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_TIMESTAMP_CONTROL_TSMSTRENA_SHIFT))&ENET_MAC_TIMESTAMP_CONTROL_TSMSTRENA_MASK)
#define ENET_MAC_TIMESTAMP_CONTROL_TSEVNTENA_MASK 0x4000u
#define ENET_MAC_TIMESTAMP_CONTROL_TSEVNTENA_SHIFT 14u
#define ENET_MAC_TIMESTAMP_CONTROL_TSEVNTENA_WIDTH 1u
#define ENET_MAC_TIMESTAMP_CONTROL_TSEVNTENA(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_TIMESTAMP_CONTROL_TSEVNTENA_SHIFT))&ENET_MAC_TIMESTAMP_CONTROL_TSEVNTENA_MASK)
#define ENET_MAC_TIMESTAMP_CONTROL_TSIPV4ENA_MASK 0x2000u
#define ENET_MAC_TIMESTAMP_CONTROL_TSIPV4ENA_SHIFT 13u
#define ENET_MAC_TIMESTAMP_CONTROL_TSIPV4ENA_WIDTH 1u
#define ENET_MAC_TIMESTAMP_CONTROL_TSIPV4ENA(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_TIMESTAMP_CONTROL_TSIPV4ENA_SHIFT))&ENET_MAC_TIMESTAMP_CONTROL_TSIPV4ENA_MASK)
#define ENET_MAC_TIMESTAMP_CONTROL_TSIPV6ENA_MASK 0x1000u
#define ENET_MAC_TIMESTAMP_CONTROL_TSIPV6ENA_SHIFT 12u
#define ENET_MAC_TIMESTAMP_CONTROL_TSIPV6ENA_WIDTH 1u
#define ENET_MAC_TIMESTAMP_CONTROL_TSIPV6ENA(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_TIMESTAMP_CONTROL_TSIPV6ENA_SHIFT))&ENET_MAC_TIMESTAMP_CONTROL_TSIPV6ENA_MASK)
#define ENET_MAC_TIMESTAMP_CONTROL_TSIPENA_MASK 0x800u
#define ENET_MAC_TIMESTAMP_CONTROL_TSIPENA_SHIFT 11u
#define ENET_MAC_TIMESTAMP_CONTROL_TSIPENA_WIDTH 1u
#define ENET_MAC_TIMESTAMP_CONTROL_TSIPENA(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_TIMESTAMP_CONTROL_TSIPENA_SHIFT))&ENET_MAC_TIMESTAMP_CONTROL_TSIPENA_MASK)
#define ENET_MAC_TIMESTAMP_CONTROL_TSVER2ENA_MASK 0x400u
#define ENET_MAC_TIMESTAMP_CONTROL_TSVER2ENA_SHIFT 10u
#define ENET_MAC_TIMESTAMP_CONTROL_TSVER2ENA_WIDTH 1u
#define ENET_MAC_TIMESTAMP_CONTROL_TSVER2ENA(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_TIMESTAMP_CONTROL_TSVER2ENA_SHIFT))&ENET_MAC_TIMESTAMP_CONTROL_TSVER2ENA_MASK)
#define ENET_MAC_TIMESTAMP_CONTROL_TSCTRLSSR_MASK 0x200u
#define ENET_MAC_TIMESTAMP_CONTROL_TSCTRLSSR_SHIFT 9u
#define ENET_MAC_TIMESTAMP_CONTROL_TSCTRLSSR_WIDTH 1u
#define ENET_MAC_TIMESTAMP_CONTROL_TSCTRLSSR(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_TIMESTAMP_CONTROL_TSCTRLSSR_SHIFT))&ENET_MAC_TIMESTAMP_CONTROL_TSCTRLSSR_MASK)
#define ENET_MAC_TIMESTAMP_CONTROL_TSENALL_MASK 0x100u
#define ENET_MAC_TIMESTAMP_CONTROL_TSENALL_SHIFT 8u
#define ENET_MAC_TIMESTAMP_CONTROL_TSENALL_WIDTH 1u
#define ENET_MAC_TIMESTAMP_CONTROL_TSENALL(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_TIMESTAMP_CONTROL_TSENALL_SHIFT))&ENET_MAC_TIMESTAMP_CONTROL_TSENALL_MASK)
#define ENET_MAC_TIMESTAMP_CONTROL_PTGE_MASK 0x40u
#define ENET_MAC_TIMESTAMP_CONTROL_PTGE_SHIFT 6u
#define ENET_MAC_TIMESTAMP_CONTROL_PTGE_WIDTH 1u
#define ENET_MAC_TIMESTAMP_CONTROL_PTGE(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_TIMESTAMP_CONTROL_PTGE_SHIFT))&ENET_MAC_TIMESTAMP_CONTROL_PTGE_MASK)
#define ENET_MAC_TIMESTAMP_CONTROL_TSADDREG_MASK 0x20u
#define ENET_MAC_TIMESTAMP_CONTROL_TSADDREG_SHIFT 5u
#define ENET_MAC_TIMESTAMP_CONTROL_TSADDREG_WIDTH 1u
#define ENET_MAC_TIMESTAMP_CONTROL_TSADDREG(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_TIMESTAMP_CONTROL_TSADDREG_SHIFT))&ENET_MAC_TIMESTAMP_CONTROL_TSADDREG_MASK)
#define ENET_MAC_TIMESTAMP_CONTROL_TSUPDT_MASK 0x8u
#define ENET_MAC_TIMESTAMP_CONTROL_TSUPDT_SHIFT 3u
#define ENET_MAC_TIMESTAMP_CONTROL_TSUPDT_WIDTH 1u
#define ENET_MAC_TIMESTAMP_CONTROL_TSUPDT(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_TIMESTAMP_CONTROL_TSUPDT_SHIFT))&ENET_MAC_TIMESTAMP_CONTROL_TSUPDT_MASK)
#define ENET_MAC_TIMESTAMP_CONTROL_TSINIT_MASK 0x4u
#define ENET_MAC_TIMESTAMP_CONTROL_TSINIT_SHIFT 2u
#define ENET_MAC_TIMESTAMP_CONTROL_TSINIT_WIDTH 1u
#define ENET_MAC_TIMESTAMP_CONTROL_TSINIT(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_TIMESTAMP_CONTROL_TSINIT_SHIFT))&ENET_MAC_TIMESTAMP_CONTROL_TSINIT_MASK)
#define ENET_MAC_TIMESTAMP_CONTROL_TSCFUPDT_MASK 0x2u
#define ENET_MAC_TIMESTAMP_CONTROL_TSCFUPDT_SHIFT 1u
#define ENET_MAC_TIMESTAMP_CONTROL_TSCFUPDT_WIDTH 1u
#define ENET_MAC_TIMESTAMP_CONTROL_TSCFUPDT(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_TIMESTAMP_CONTROL_TSCFUPDT_SHIFT))&ENET_MAC_TIMESTAMP_CONTROL_TSCFUPDT_MASK)
#define ENET_MAC_TIMESTAMP_CONTROL_TSENA_MASK 0x1u
#define ENET_MAC_TIMESTAMP_CONTROL_TSENA_SHIFT 0u
#define ENET_MAC_TIMESTAMP_CONTROL_TSENA_WIDTH 1u
#define ENET_MAC_TIMESTAMP_CONTROL_TSENA(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_TIMESTAMP_CONTROL_TSENA_SHIFT))&ENET_MAC_TIMESTAMP_CONTROL_TSENA_MASK)
/* MAC_TIMESTAMP_CONTROL Reg Mask */
#define ENET_MAC_TIMESTAMP_CONTROL_MASK 0x1107FF6Fu

/* MAC_SUB_SECOND_INCREMENT Bit Fields */
#define ENET_MAC_SUB_SECOND_INCREMENT_SSINC_MASK 0xFF0000u
#define ENET_MAC_SUB_SECOND_INCREMENT_SSINC_SHIFT 16u
#define ENET_MAC_SUB_SECOND_INCREMENT_SSINC_WIDTH 8u
#define ENET_MAC_SUB_SECOND_INCREMENT_SSINC(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_SUB_SECOND_INCREMENT_SSINC_SHIFT))&ENET_MAC_SUB_SECOND_INCREMENT_SSINC_MASK)
#define ENET_MAC_SUB_SECOND_INCREMENT_SNSINC_MASK 0xFF00u
#define ENET_MAC_SUB_SECOND_INCREMENT_SNSINC_SHIFT 8u
#define ENET_MAC_SUB_SECOND_INCREMENT_SNSINC_WIDTH 8u
#define ENET_MAC_SUB_SECOND_INCREMENT_SNSINC(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_SUB_SECOND_INCREMENT_SNSINC_SHIFT))&ENET_MAC_SUB_SECOND_INCREMENT_SNSINC_MASK)
/* MAC_SUB_SECOND_INCREMENT Reg Mask */
#define ENET_MAC_SUB_SECOND_INCREMENT_MASK 0x00FFFF00u

/* MAC_SYSTEM_TIME_SECONDS Bit Fields */
#define ENET_MAC_SYSTEM_TIME_SECONDS_TSS_MASK 0xFFFFFFFFu
#define ENET_MAC_SYSTEM_TIME_SECONDS_TSS_SHIFT 0u
#define ENET_MAC_SYSTEM_TIME_SECONDS_TSS_WIDTH 32u
#define ENET_MAC_SYSTEM_TIME_SECONDS_TSS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_SYSTEM_TIME_SECONDS_TSS_SHIFT))&ENET_MAC_SYSTEM_TIME_SECONDS_TSS_MASK)
/* MAC_SYSTEM_TIME_SECONDS Reg Mask */
#define ENET_MAC_SYSTEM_TIME_SECONDS_MASK 0xFFFFFFFFu

/* MAC_SYSTEM_TIME_NANOSECONDS Bit Fields */
#define ENET_MAC_SYSTEM_TIME_NANOSECONDS_TSSS_MASK 0x7FFFFFFFu
#define ENET_MAC_SYSTEM_TIME_NANOSECONDS_TSSS_SHIFT 0u
#define ENET_MAC_SYSTEM_TIME_NANOSECONDS_TSSS_WIDTH 31u
#define ENET_MAC_SYSTEM_TIME_NANOSECONDS_TSSS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_SYSTEM_TIME_NANOSECONDS_TSSS_SHIFT))&ENET_MAC_SYSTEM_TIME_NANOSECONDS_TSSS_MASK)
/* MAC_SYSTEM_TIME_NANOSECONDS Reg Mask */
#define ENET_MAC_SYSTEM_TIME_NANOSECONDS_MASK 0x7FFFFFFFu

/* MAC_SYSTEM_TIME_SECONDS_UPDATE Bit Fields */
#define ENET_MAC_SYSTEM_TIME_SECONDS_UPDATE_TSS_MASK 0xFFFFFFFFu
#define ENET_MAC_SYSTEM_TIME_SECONDS_UPDATE_TSS_SHIFT 0u
#define ENET_MAC_SYSTEM_TIME_SECONDS_UPDATE_TSS_WIDTH 32u
#define ENET_MAC_SYSTEM_TIME_SECONDS_UPDATE_TSS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_SYSTEM_TIME_SECONDS_UPDATE_TSS_SHIFT))&ENET_MAC_SYSTEM_TIME_SECONDS_UPDATE_TSS_MASK)
/* MAC_SYSTEM_TIME_SECONDS_UPDATE Reg Mask */
#define ENET_MAC_SYSTEM_TIME_SECONDS_UPDATE_MASK 0xFFFFFFFFu

/* MAC_SYSTEM_TIME_NANOSECONDS_UPDATE Bit Fields */
#define ENET_MAC_SYSTEM_TIME_NANOSECONDS_UPDATE_ADDSUB_MASK 0x80000000u
#define ENET_MAC_SYSTEM_TIME_NANOSECONDS_UPDATE_ADDSUB_SHIFT 31u
#define ENET_MAC_SYSTEM_TIME_NANOSECONDS_UPDATE_ADDSUB_WIDTH 1u
#define ENET_MAC_SYSTEM_TIME_NANOSECONDS_UPDATE_ADDSUB(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_SYSTEM_TIME_NANOSECONDS_UPDATE_ADDSUB_SHIFT))&ENET_MAC_SYSTEM_TIME_NANOSECONDS_UPDATE_ADDSUB_MASK)
#define ENET_MAC_SYSTEM_TIME_NANOSECONDS_UPDATE_TSSS_MASK 0x7FFFFFFFu
#define ENET_MAC_SYSTEM_TIME_NANOSECONDS_UPDATE_TSSS_SHIFT 0u
#define ENET_MAC_SYSTEM_TIME_NANOSECONDS_UPDATE_TSSS_WIDTH 31u
#define ENET_MAC_SYSTEM_TIME_NANOSECONDS_UPDATE_TSSS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_SYSTEM_TIME_NANOSECONDS_UPDATE_TSSS_SHIFT))&ENET_MAC_SYSTEM_TIME_NANOSECONDS_UPDATE_TSSS_MASK)
/* MAC_SYSTEM_TIME_NANOSECONDS_UPDATE Reg Mask */
#define ENET_MAC_SYSTEM_TIME_NANOSECONDS_UPDATE_MASK 0xFFFFFFFFu

/* MAC_TIMESTAMP_ADDEND Bit Fields */
#define ENET_MAC_TIMESTAMP_ADDEND_TSAR_MASK 0xFFFFFFFFu
#define ENET_MAC_TIMESTAMP_ADDEND_TSAR_SHIFT 0u
#define ENET_MAC_TIMESTAMP_ADDEND_TSAR_WIDTH 32u
#define ENET_MAC_TIMESTAMP_ADDEND_TSAR(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_TIMESTAMP_ADDEND_TSAR_SHIFT))&ENET_MAC_TIMESTAMP_ADDEND_TSAR_MASK)
/* MAC_TIMESTAMP_ADDEND Reg Mask */
#define ENET_MAC_TIMESTAMP_ADDEND_MASK 0xFFFFFFFFu

/* MAC_SYSTEM_TIME_HIGHER_WORD_SECONDS Bit Fields */
#define ENET_MAC_SYSTEM_TIME_HIGHER_WORD_SECONDS_TSHWR_MASK 0xFFFFu
#define ENET_MAC_SYSTEM_TIME_HIGHER_WORD_SECONDS_TSHWR_SHIFT 0u
#define ENET_MAC_SYSTEM_TIME_HIGHER_WORD_SECONDS_TSHWR_WIDTH 16u
#define ENET_MAC_SYSTEM_TIME_HIGHER_WORD_SECONDS_TSHWR(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_SYSTEM_TIME_HIGHER_WORD_SECONDS_TSHWR_SHIFT))&ENET_MAC_SYSTEM_TIME_HIGHER_WORD_SECONDS_TSHWR_MASK)
/* MAC_SYSTEM_TIME_HIGHER_WORD_SECONDS Reg Mask */
#define ENET_MAC_SYSTEM_TIME_HIGHER_WORD_SECONDS_MASK 0x0000FFFFu

/* MAC_TIMESTAMP_STATUS Bit Fields */
#define ENET_MAC_TIMESTAMP_STATUS_TXTSSIS_MASK 0x8000u
#define ENET_MAC_TIMESTAMP_STATUS_TXTSSIS_SHIFT 15u
#define ENET_MAC_TIMESTAMP_STATUS_TXTSSIS_WIDTH 1u
#define ENET_MAC_TIMESTAMP_STATUS_TXTSSIS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_TIMESTAMP_STATUS_TXTSSIS_SHIFT))&ENET_MAC_TIMESTAMP_STATUS_TXTSSIS_MASK)
#define ENET_MAC_TIMESTAMP_STATUS_TSTRGTERR3_MASK 0x200u
#define ENET_MAC_TIMESTAMP_STATUS_TSTRGTERR3_SHIFT 9u
#define ENET_MAC_TIMESTAMP_STATUS_TSTRGTERR3_WIDTH 1u
#define ENET_MAC_TIMESTAMP_STATUS_TSTRGTERR3(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_TIMESTAMP_STATUS_TSTRGTERR3_SHIFT))&ENET_MAC_TIMESTAMP_STATUS_TSTRGTERR3_MASK)
#define ENET_MAC_TIMESTAMP_STATUS_TSTARGT3_MASK 0x100u
#define ENET_MAC_TIMESTAMP_STATUS_TSTARGT3_SHIFT 8u
#define ENET_MAC_TIMESTAMP_STATUS_TSTARGT3_WIDTH 1u
#define ENET_MAC_TIMESTAMP_STATUS_TSTARGT3(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_TIMESTAMP_STATUS_TSTARGT3_SHIFT))&ENET_MAC_TIMESTAMP_STATUS_TSTARGT3_MASK)
#define ENET_MAC_TIMESTAMP_STATUS_TSTRGTERR2_MASK 0x80u
#define ENET_MAC_TIMESTAMP_STATUS_TSTRGTERR2_SHIFT 7u
#define ENET_MAC_TIMESTAMP_STATUS_TSTRGTERR2_WIDTH 1u
#define ENET_MAC_TIMESTAMP_STATUS_TSTRGTERR2(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_TIMESTAMP_STATUS_TSTRGTERR2_SHIFT))&ENET_MAC_TIMESTAMP_STATUS_TSTRGTERR2_MASK)
#define ENET_MAC_TIMESTAMP_STATUS_TSTARGT2_MASK 0x40u
#define ENET_MAC_TIMESTAMP_STATUS_TSTARGT2_SHIFT 6u
#define ENET_MAC_TIMESTAMP_STATUS_TSTARGT2_WIDTH 1u
#define ENET_MAC_TIMESTAMP_STATUS_TSTARGT2(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_TIMESTAMP_STATUS_TSTARGT2_SHIFT))&ENET_MAC_TIMESTAMP_STATUS_TSTARGT2_MASK)
#define ENET_MAC_TIMESTAMP_STATUS_TSTRGTERR1_MASK 0x20u
#define ENET_MAC_TIMESTAMP_STATUS_TSTRGTERR1_SHIFT 5u
#define ENET_MAC_TIMESTAMP_STATUS_TSTRGTERR1_WIDTH 1u
#define ENET_MAC_TIMESTAMP_STATUS_TSTRGTERR1(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_TIMESTAMP_STATUS_TSTRGTERR1_SHIFT))&ENET_MAC_TIMESTAMP_STATUS_TSTRGTERR1_MASK)
#define ENET_MAC_TIMESTAMP_STATUS_TSTARGT1_MASK 0x10u
#define ENET_MAC_TIMESTAMP_STATUS_TSTARGT1_SHIFT 4u
#define ENET_MAC_TIMESTAMP_STATUS_TSTARGT1_WIDTH 1u
#define ENET_MAC_TIMESTAMP_STATUS_TSTARGT1(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_TIMESTAMP_STATUS_TSTARGT1_SHIFT))&ENET_MAC_TIMESTAMP_STATUS_TSTARGT1_MASK)
#define ENET_MAC_TIMESTAMP_STATUS_TSTRGTERR0_MASK 0x8u
#define ENET_MAC_TIMESTAMP_STATUS_TSTRGTERR0_SHIFT 3u
#define ENET_MAC_TIMESTAMP_STATUS_TSTRGTERR0_WIDTH 1u
#define ENET_MAC_TIMESTAMP_STATUS_TSTRGTERR0(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_TIMESTAMP_STATUS_TSTRGTERR0_SHIFT))&ENET_MAC_TIMESTAMP_STATUS_TSTRGTERR0_MASK)
#define ENET_MAC_TIMESTAMP_STATUS_TSTARGT0_MASK 0x2u
#define ENET_MAC_TIMESTAMP_STATUS_TSTARGT0_SHIFT 1u
#define ENET_MAC_TIMESTAMP_STATUS_TSTARGT0_WIDTH 1u
#define ENET_MAC_TIMESTAMP_STATUS_TSTARGT0(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_TIMESTAMP_STATUS_TSTARGT0_SHIFT))&ENET_MAC_TIMESTAMP_STATUS_TSTARGT0_MASK)
#define ENET_MAC_TIMESTAMP_STATUS_TSSOVF_MASK 0x1u
#define ENET_MAC_TIMESTAMP_STATUS_TSSOVF_SHIFT 0u
#define ENET_MAC_TIMESTAMP_STATUS_TSSOVF_WIDTH 1u
#define ENET_MAC_TIMESTAMP_STATUS_TSSOVF(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_TIMESTAMP_STATUS_TSSOVF_SHIFT))&ENET_MAC_TIMESTAMP_STATUS_TSSOVF_MASK)
/* MAC_TIMESTAMP_STATUS Reg Mask */
#define ENET_MAC_TIMESTAMP_STATUS_MASK 0x000083FBu

/* MAC_TX_TIMESTAMP_STATUS_NANOSECONDS Bit Fields */
#define ENET_MAC_TX_TIMESTAMP_STATUS_NANOSECONDS_TXTSSMIS_MASK 0x80000000u
#define ENET_MAC_TX_TIMESTAMP_STATUS_NANOSECONDS_TXTSSMIS_SHIFT 31u
#define ENET_MAC_TX_TIMESTAMP_STATUS_NANOSECONDS_TXTSSMIS_WIDTH 1u
#define ENET_MAC_TX_TIMESTAMP_STATUS_NANOSECONDS_TXTSSMIS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_TX_TIMESTAMP_STATUS_NANOSECONDS_TXTSSMIS_SHIFT))&ENET_MAC_TX_TIMESTAMP_STATUS_NANOSECONDS_TXTSSMIS_MASK)
#define ENET_MAC_TX_TIMESTAMP_STATUS_NANOSECONDS_TXTSSLO_MASK 0x7FFFFFFFu
#define ENET_MAC_TX_TIMESTAMP_STATUS_NANOSECONDS_TXTSSLO_SHIFT 0u
#define ENET_MAC_TX_TIMESTAMP_STATUS_NANOSECONDS_TXTSSLO_WIDTH 31u
#define ENET_MAC_TX_TIMESTAMP_STATUS_NANOSECONDS_TXTSSLO(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_TX_TIMESTAMP_STATUS_NANOSECONDS_TXTSSLO_SHIFT))&ENET_MAC_TX_TIMESTAMP_STATUS_NANOSECONDS_TXTSSLO_MASK)
/* MAC_TX_TIMESTAMP_STATUS_NANOSECONDS Reg Mask */
#define ENET_MAC_TX_TIMESTAMP_STATUS_NANOSECONDS_MASK 0xFFFFFFFFu

/* MAC_TX_TIMESTAMP_STATUS_SECONDS Bit Fields */
#define ENET_MAC_TX_TIMESTAMP_STATUS_SECONDS_TXTSSHI_MASK 0xFFFFFFFFu
#define ENET_MAC_TX_TIMESTAMP_STATUS_SECONDS_TXTSSHI_SHIFT 0u
#define ENET_MAC_TX_TIMESTAMP_STATUS_SECONDS_TXTSSHI_WIDTH 32u
#define ENET_MAC_TX_TIMESTAMP_STATUS_SECONDS_TXTSSHI(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_TX_TIMESTAMP_STATUS_SECONDS_TXTSSHI_SHIFT))&ENET_MAC_TX_TIMESTAMP_STATUS_SECONDS_TXTSSHI_MASK)
/* MAC_TX_TIMESTAMP_STATUS_SECONDS Reg Mask */
#define ENET_MAC_TX_TIMESTAMP_STATUS_SECONDS_MASK 0xFFFFFFFFu

/* MAC_TIMESTAMP_INGRESS_ASYM_CORR Bit Fields */
#define ENET_MAC_TIMESTAMP_INGRESS_ASYM_CORR_OSTIAC_MASK 0xFFFFFFFFu
#define ENET_MAC_TIMESTAMP_INGRESS_ASYM_CORR_OSTIAC_SHIFT 0u
#define ENET_MAC_TIMESTAMP_INGRESS_ASYM_CORR_OSTIAC_WIDTH 32u
#define ENET_MAC_TIMESTAMP_INGRESS_ASYM_CORR_OSTIAC(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_TIMESTAMP_INGRESS_ASYM_CORR_OSTIAC_SHIFT))&ENET_MAC_TIMESTAMP_INGRESS_ASYM_CORR_OSTIAC_MASK)
/* MAC_TIMESTAMP_INGRESS_ASYM_CORR Reg Mask */
#define ENET_MAC_TIMESTAMP_INGRESS_ASYM_CORR_MASK 0xFFFFFFFFu

/* MAC_TIMESTAMP_EGRESS_ASYM_CORR Bit Fields */
#define ENET_MAC_TIMESTAMP_EGRESS_ASYM_CORR_OSTEAC_MASK 0xFFFFFFFFu
#define ENET_MAC_TIMESTAMP_EGRESS_ASYM_CORR_OSTEAC_SHIFT 0u
#define ENET_MAC_TIMESTAMP_EGRESS_ASYM_CORR_OSTEAC_WIDTH 32u
#define ENET_MAC_TIMESTAMP_EGRESS_ASYM_CORR_OSTEAC(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_TIMESTAMP_EGRESS_ASYM_CORR_OSTEAC_SHIFT))&ENET_MAC_TIMESTAMP_EGRESS_ASYM_CORR_OSTEAC_MASK)
/* MAC_TIMESTAMP_EGRESS_ASYM_CORR Reg Mask */
#define ENET_MAC_TIMESTAMP_EGRESS_ASYM_CORR_MASK 0xFFFFFFFFu

/* MAC_TIMESTAMP_INGRESS_CORR_NANOSECOND Bit Fields */
#define ENET_MAC_TIMESTAMP_INGRESS_CORR_NANOSECOND_TSIC_MASK 0xFFFFFFFFu
#define ENET_MAC_TIMESTAMP_INGRESS_CORR_NANOSECOND_TSIC_SHIFT 0u
#define ENET_MAC_TIMESTAMP_INGRESS_CORR_NANOSECOND_TSIC_WIDTH 32u
#define ENET_MAC_TIMESTAMP_INGRESS_CORR_NANOSECOND_TSIC(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_TIMESTAMP_INGRESS_CORR_NANOSECOND_TSIC_SHIFT))&ENET_MAC_TIMESTAMP_INGRESS_CORR_NANOSECOND_TSIC_MASK)
/* MAC_TIMESTAMP_INGRESS_CORR_NANOSECOND Reg Mask */
#define ENET_MAC_TIMESTAMP_INGRESS_CORR_NANOSECOND_MASK 0xFFFFFFFFu

/* MAC_TIMESTAMP_EGRESS_CORR_NANOSECOND Bit Fields */
#define ENET_MAC_TIMESTAMP_EGRESS_CORR_NANOSECOND_TSEC_MASK 0xFFFFFFFFu
#define ENET_MAC_TIMESTAMP_EGRESS_CORR_NANOSECOND_TSEC_SHIFT 0u
#define ENET_MAC_TIMESTAMP_EGRESS_CORR_NANOSECOND_TSEC_WIDTH 32u
#define ENET_MAC_TIMESTAMP_EGRESS_CORR_NANOSECOND_TSEC(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_TIMESTAMP_EGRESS_CORR_NANOSECOND_TSEC_SHIFT))&ENET_MAC_TIMESTAMP_EGRESS_CORR_NANOSECOND_TSEC_MASK)
/* MAC_TIMESTAMP_EGRESS_CORR_NANOSECOND Reg Mask */
#define ENET_MAC_TIMESTAMP_EGRESS_CORR_NANOSECOND_MASK 0xFFFFFFFFu

/* MAC_TIMESTAMP_INGRESS_CORR_SUBNANOSEC Bit Fields */
#define ENET_MAC_TIMESTAMP_INGRESS_CORR_SUBNANOSEC_TSICSNS_MASK 0xFF00u
#define ENET_MAC_TIMESTAMP_INGRESS_CORR_SUBNANOSEC_TSICSNS_SHIFT 8u
#define ENET_MAC_TIMESTAMP_INGRESS_CORR_SUBNANOSEC_TSICSNS_WIDTH 8u
#define ENET_MAC_TIMESTAMP_INGRESS_CORR_SUBNANOSEC_TSICSNS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_TIMESTAMP_INGRESS_CORR_SUBNANOSEC_TSICSNS_SHIFT))&ENET_MAC_TIMESTAMP_INGRESS_CORR_SUBNANOSEC_TSICSNS_MASK)
/* MAC_TIMESTAMP_INGRESS_CORR_SUBNANOSEC Reg Mask */
#define ENET_MAC_TIMESTAMP_INGRESS_CORR_SUBNANOSEC_MASK 0x0000FF00u

/* MAC_TIMESTAMP_EGRESS_CORR_SUBNANOSEC Bit Fields */
#define ENET_MAC_TIMESTAMP_EGRESS_CORR_SUBNANOSEC_TSECSNS_MASK 0xFF00u
#define ENET_MAC_TIMESTAMP_EGRESS_CORR_SUBNANOSEC_TSECSNS_SHIFT 8u
#define ENET_MAC_TIMESTAMP_EGRESS_CORR_SUBNANOSEC_TSECSNS_WIDTH 8u
#define ENET_MAC_TIMESTAMP_EGRESS_CORR_SUBNANOSEC_TSECSNS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_TIMESTAMP_EGRESS_CORR_SUBNANOSEC_TSECSNS_SHIFT))&ENET_MAC_TIMESTAMP_EGRESS_CORR_SUBNANOSEC_TSECSNS_MASK)
/* MAC_TIMESTAMP_EGRESS_CORR_SUBNANOSEC Reg Mask */
#define ENET_MAC_TIMESTAMP_EGRESS_CORR_SUBNANOSEC_MASK 0x0000FF00u

/* MAC_TIMESTAMP_INGRESS_LATENCY Bit Fields */
#define ENET_MAC_TIMESTAMP_INGRESS_LATENCY_ITLNS_MASK 0xFFF0000u
#define ENET_MAC_TIMESTAMP_INGRESS_LATENCY_ITLNS_SHIFT 16u
#define ENET_MAC_TIMESTAMP_INGRESS_LATENCY_ITLNS_WIDTH 12u
#define ENET_MAC_TIMESTAMP_INGRESS_LATENCY_ITLNS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_TIMESTAMP_INGRESS_LATENCY_ITLNS_SHIFT))&ENET_MAC_TIMESTAMP_INGRESS_LATENCY_ITLNS_MASK)
#define ENET_MAC_TIMESTAMP_INGRESS_LATENCY_ITLSNS_MASK 0xFF00u
#define ENET_MAC_TIMESTAMP_INGRESS_LATENCY_ITLSNS_SHIFT 8u
#define ENET_MAC_TIMESTAMP_INGRESS_LATENCY_ITLSNS_WIDTH 8u
#define ENET_MAC_TIMESTAMP_INGRESS_LATENCY_ITLSNS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_TIMESTAMP_INGRESS_LATENCY_ITLSNS_SHIFT))&ENET_MAC_TIMESTAMP_INGRESS_LATENCY_ITLSNS_MASK)
/* MAC_TIMESTAMP_INGRESS_LATENCY Reg Mask */
#define ENET_MAC_TIMESTAMP_INGRESS_LATENCY_MASK 0x0FFFFF00u

/* MAC_TIMESTAMP_EGRESS_LATENCY Bit Fields */
#define ENET_MAC_TIMESTAMP_EGRESS_LATENCY_ETLNS_MASK 0xFFF0000u
#define ENET_MAC_TIMESTAMP_EGRESS_LATENCY_ETLNS_SHIFT 16u
#define ENET_MAC_TIMESTAMP_EGRESS_LATENCY_ETLNS_WIDTH 12u
#define ENET_MAC_TIMESTAMP_EGRESS_LATENCY_ETLNS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_TIMESTAMP_EGRESS_LATENCY_ETLNS_SHIFT))&ENET_MAC_TIMESTAMP_EGRESS_LATENCY_ETLNS_MASK)
#define ENET_MAC_TIMESTAMP_EGRESS_LATENCY_ETLSNS_MASK 0xFF00u
#define ENET_MAC_TIMESTAMP_EGRESS_LATENCY_ETLSNS_SHIFT 8u
#define ENET_MAC_TIMESTAMP_EGRESS_LATENCY_ETLSNS_WIDTH 8u
#define ENET_MAC_TIMESTAMP_EGRESS_LATENCY_ETLSNS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_TIMESTAMP_EGRESS_LATENCY_ETLSNS_SHIFT))&ENET_MAC_TIMESTAMP_EGRESS_LATENCY_ETLSNS_MASK)
/* MAC_TIMESTAMP_EGRESS_LATENCY Reg Mask */
#define ENET_MAC_TIMESTAMP_EGRESS_LATENCY_MASK 0x0FFFFF00u

/* MAC_PPS_CONTROL Bit Fields */
#define ENET_MAC_PPS_CONTROL_MCGREN3_MASK 0x80000000u
#define ENET_MAC_PPS_CONTROL_MCGREN3_SHIFT 31u
#define ENET_MAC_PPS_CONTROL_MCGREN3_WIDTH 1u
#define ENET_MAC_PPS_CONTROL_MCGREN3(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_PPS_CONTROL_MCGREN3_SHIFT))&ENET_MAC_PPS_CONTROL_MCGREN3_MASK)
#define ENET_MAC_PPS_CONTROL_TRGTMODSEL3_MASK 0x60000000u
#define ENET_MAC_PPS_CONTROL_TRGTMODSEL3_SHIFT 29u
#define ENET_MAC_PPS_CONTROL_TRGTMODSEL3_WIDTH 2u
#define ENET_MAC_PPS_CONTROL_TRGTMODSEL3(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_PPS_CONTROL_TRGTMODSEL3_SHIFT))&ENET_MAC_PPS_CONTROL_TRGTMODSEL3_MASK)
#define ENET_MAC_PPS_CONTROL_TIMESEL_MASK 0x10000000u
#define ENET_MAC_PPS_CONTROL_TIMESEL_SHIFT 28u
#define ENET_MAC_PPS_CONTROL_TIMESEL_WIDTH 1u
#define ENET_MAC_PPS_CONTROL_TIMESEL(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_PPS_CONTROL_TIMESEL_SHIFT))&ENET_MAC_PPS_CONTROL_TIMESEL_MASK)
#define ENET_MAC_PPS_CONTROL_PPSCMD3_MASK 0xF000000u
#define ENET_MAC_PPS_CONTROL_PPSCMD3_SHIFT 24u
#define ENET_MAC_PPS_CONTROL_PPSCMD3_WIDTH 4u
#define ENET_MAC_PPS_CONTROL_PPSCMD3(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_PPS_CONTROL_PPSCMD3_SHIFT))&ENET_MAC_PPS_CONTROL_PPSCMD3_MASK)
#define ENET_MAC_PPS_CONTROL_MCGREN2_MASK 0x800000u
#define ENET_MAC_PPS_CONTROL_MCGREN2_SHIFT 23u
#define ENET_MAC_PPS_CONTROL_MCGREN2_WIDTH 1u
#define ENET_MAC_PPS_CONTROL_MCGREN2(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_PPS_CONTROL_MCGREN2_SHIFT))&ENET_MAC_PPS_CONTROL_MCGREN2_MASK)
#define ENET_MAC_PPS_CONTROL_TRGTMODSEL2_MASK 0x600000u
#define ENET_MAC_PPS_CONTROL_TRGTMODSEL2_SHIFT 21u
#define ENET_MAC_PPS_CONTROL_TRGTMODSEL2_WIDTH 2u
#define ENET_MAC_PPS_CONTROL_TRGTMODSEL2(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_PPS_CONTROL_TRGTMODSEL2_SHIFT))&ENET_MAC_PPS_CONTROL_TRGTMODSEL2_MASK)
#define ENET_MAC_PPS_CONTROL_PPSCMD2_MASK 0xF0000u
#define ENET_MAC_PPS_CONTROL_PPSCMD2_SHIFT 16u
#define ENET_MAC_PPS_CONTROL_PPSCMD2_WIDTH 4u
#define ENET_MAC_PPS_CONTROL_PPSCMD2(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_PPS_CONTROL_PPSCMD2_SHIFT))&ENET_MAC_PPS_CONTROL_PPSCMD2_MASK)
#define ENET_MAC_PPS_CONTROL_MCGREN1_MASK 0x8000u
#define ENET_MAC_PPS_CONTROL_MCGREN1_SHIFT 15u
#define ENET_MAC_PPS_CONTROL_MCGREN1_WIDTH 1u
#define ENET_MAC_PPS_CONTROL_MCGREN1(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_PPS_CONTROL_MCGREN1_SHIFT))&ENET_MAC_PPS_CONTROL_MCGREN1_MASK)
#define ENET_MAC_PPS_CONTROL_TRGTMODSEL1_MASK 0x6000u
#define ENET_MAC_PPS_CONTROL_TRGTMODSEL1_SHIFT 13u
#define ENET_MAC_PPS_CONTROL_TRGTMODSEL1_WIDTH 2u
#define ENET_MAC_PPS_CONTROL_TRGTMODSEL1(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_PPS_CONTROL_TRGTMODSEL1_SHIFT))&ENET_MAC_PPS_CONTROL_TRGTMODSEL1_MASK)
#define ENET_MAC_PPS_CONTROL_PPSCMD1_MASK 0xF00u
#define ENET_MAC_PPS_CONTROL_PPSCMD1_SHIFT 8u
#define ENET_MAC_PPS_CONTROL_PPSCMD1_WIDTH 4u
#define ENET_MAC_PPS_CONTROL_PPSCMD1(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_PPS_CONTROL_PPSCMD1_SHIFT))&ENET_MAC_PPS_CONTROL_PPSCMD1_MASK)
#define ENET_MAC_PPS_CONTROL_MCGREN0_MASK 0x80u
#define ENET_MAC_PPS_CONTROL_MCGREN0_SHIFT 7u
#define ENET_MAC_PPS_CONTROL_MCGREN0_WIDTH 1u
#define ENET_MAC_PPS_CONTROL_MCGREN0(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_PPS_CONTROL_MCGREN0_SHIFT))&ENET_MAC_PPS_CONTROL_MCGREN0_MASK)
#define ENET_MAC_PPS_CONTROL_TRGTMODSEL0_MASK 0x60u
#define ENET_MAC_PPS_CONTROL_TRGTMODSEL0_SHIFT 5u
#define ENET_MAC_PPS_CONTROL_TRGTMODSEL0_WIDTH 2u
#define ENET_MAC_PPS_CONTROL_TRGTMODSEL0(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_PPS_CONTROL_TRGTMODSEL0_SHIFT))&ENET_MAC_PPS_CONTROL_TRGTMODSEL0_MASK)
#define ENET_MAC_PPS_CONTROL_PPSEN0_MASK 0x10u
#define ENET_MAC_PPS_CONTROL_PPSEN0_SHIFT 4u
#define ENET_MAC_PPS_CONTROL_PPSEN0_WIDTH 1u
#define ENET_MAC_PPS_CONTROL_PPSEN0(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_PPS_CONTROL_PPSEN0_SHIFT))&ENET_MAC_PPS_CONTROL_PPSEN0_MASK)
#define ENET_MAC_PPS_CONTROL_PPSCTRL_PPSCMD_MASK 0xFu
#define ENET_MAC_PPS_CONTROL_PPSCTRL_PPSCMD_SHIFT 0u
#define ENET_MAC_PPS_CONTROL_PPSCTRL_PPSCMD_WIDTH 4u
#define ENET_MAC_PPS_CONTROL_PPSCTRL_PPSCMD(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_PPS_CONTROL_PPSCTRL_PPSCMD_SHIFT))&ENET_MAC_PPS_CONTROL_PPSCTRL_PPSCMD_MASK)
/* MAC_PPS_CONTROL Reg Mask */
#define ENET_MAC_PPS_CONTROL_MASK      0xFFEFEFFFu

/* MAC_PPSn_TARGET_TIME_SECONDS Bit Fields */
#define ENET_MAC_PPSn_TARGET_TIME_SECONDS_TSTRH0_MASK 0xFFFFFFFFu
#define ENET_MAC_PPSn_TARGET_TIME_SECONDS_TSTRH0_SHIFT 0u
#define ENET_MAC_PPSn_TARGET_TIME_SECONDS_TSTRH0_WIDTH 32u
#define ENET_MAC_PPSn_TARGET_TIME_SECONDS_TSTRH0(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_PPSn_TARGET_TIME_SECONDS_TSTRH0_SHIFT))&ENET_MAC_PPSn_TARGET_TIME_SECONDS_TSTRH0_MASK)
/* MAC_PPS0_TARGET_TIME_SECONDS Reg Mask */
#define ENET_MAC_PPSn_TARGET_TIME_SECONDS_MASK 0xFFFFFFFFu

/* MAC_PPSn_TARGET_TIME_NANOSECONDS Bit Fields */
#define ENET_MAC_PPSn_TARGET_TIME_NANOSECONDS_TRGTBUSY0_MASK 0x80000000u
#define ENET_MAC_PPSn_TARGET_TIME_NANOSECONDS_TRGTBUSY0_SHIFT 31u
#define ENET_MAC_PPSn_TARGET_TIME_NANOSECONDS_TRGTBUSY0_WIDTH 1u
#define ENET_MAC_PPSn_TARGET_TIME_NANOSECONDS_TRGTBUSY0(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_PPSn_TARGET_TIME_NANOSECONDS_TRGTBUSY0_SHIFT))&ENET_MAC_PPSn_TARGET_TIME_NANOSECONDS_TRGTBUSY0_MASK)
#define ENET_MAC_PPSn_TARGET_TIME_NANOSECONDS_TTSL0_MASK 0x7FFFFFFFu
#define ENET_MAC_PPSn_TARGET_TIME_NANOSECONDS_TTSL0_SHIFT 0u
#define ENET_MAC_PPSn_TARGET_TIME_NANOSECONDS_TTSL0_WIDTH 31u
#define ENET_MAC_PPSn_TARGET_TIME_NANOSECONDS_TTSL0(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_PPSn_TARGET_TIME_NANOSECONDS_TTSL0_SHIFT))&ENET_MAC_PPSn_TARGET_TIME_NANOSECONDS_TTSL0_MASK)
/* MAC_PPS0_TARGET_TIME_NANOSECONDS Reg Mask */
#define ENET_MAC_PPSn_TARGET_TIME_NANOSECONDS_MASK 0xFFFFFFFFu

/* MAC_PPSn_INTERVAL Bit Fields */
#define ENET_MAC_PPSn_INTERVAL_PPSINT0_MASK 0xFFFFFFFFu
#define ENET_MAC_PPSn_INTERVAL_PPSINT0_SHIFT 0u
#define ENET_MAC_PPSn_INTERVAL_PPSINT0_WIDTH 32u
#define ENET_MAC_PPSn_INTERVAL_PPSINT0(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_PPSn_INTERVAL_PPSINT0_SHIFT))&ENET_MAC_PPSn_INTERVAL_PPSINT0_MASK)
/* MAC_PPS0_INTERVAL Reg Mask */
#define ENET_MAC_PPSn_INTERVAL_MASK    0xFFFFFFFFu

/* MAC_PPSn_WIDTH Bit Fields */
#define ENET_MAC_PPSn_WIDTH_PPSWIDTH0_MASK 0xFFFFFFFFu
#define ENET_MAC_PPSn_WIDTH_PPSWIDTH0_SHIFT 0u
#define ENET_MAC_PPSn_WIDTH_PPSWIDTH0_WIDTH 32u
#define ENET_MAC_PPSn_WIDTH_PPSWIDTH0(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_PPSn_WIDTH_PPSWIDTH0_SHIFT))&ENET_MAC_PPSn_WIDTH_PPSWIDTH0_MASK)
/* MAC_PPS0_WIDTH Reg Mask */
#define ENET_MAC_PPSn_WIDTH_MASK       0xFFFFFFFFu

/* MAC_PTO_CONTROL Bit Fields */
#define ENET_MAC_PTO_CONTROL_DN_MASK   0xFF00u
#define ENET_MAC_PTO_CONTROL_DN_SHIFT  8u
#define ENET_MAC_PTO_CONTROL_DN_WIDTH  8u
#define ENET_MAC_PTO_CONTROL_DN(x)     (((uint32_t)(((uint32_t)(x))<<ENET_MAC_PTO_CONTROL_DN_SHIFT))&ENET_MAC_PTO_CONTROL_DN_MASK)
#define ENET_MAC_PTO_CONTROL_PDRDIS_MASK 0x80u
#define ENET_MAC_PTO_CONTROL_PDRDIS_SHIFT 7u
#define ENET_MAC_PTO_CONTROL_PDRDIS_WIDTH 1u
#define ENET_MAC_PTO_CONTROL_PDRDIS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_PTO_CONTROL_PDRDIS_SHIFT))&ENET_MAC_PTO_CONTROL_PDRDIS_MASK)
#define ENET_MAC_PTO_CONTROL_DRRDIS_MASK 0x40u
#define ENET_MAC_PTO_CONTROL_DRRDIS_SHIFT 6u
#define ENET_MAC_PTO_CONTROL_DRRDIS_WIDTH 1u
#define ENET_MAC_PTO_CONTROL_DRRDIS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_PTO_CONTROL_DRRDIS_SHIFT))&ENET_MAC_PTO_CONTROL_DRRDIS_MASK)
#define ENET_MAC_PTO_CONTROL_APDREQTRIG_MASK 0x20u
#define ENET_MAC_PTO_CONTROL_APDREQTRIG_SHIFT 5u
#define ENET_MAC_PTO_CONTROL_APDREQTRIG_WIDTH 1u
#define ENET_MAC_PTO_CONTROL_APDREQTRIG(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_PTO_CONTROL_APDREQTRIG_SHIFT))&ENET_MAC_PTO_CONTROL_APDREQTRIG_MASK)
#define ENET_MAC_PTO_CONTROL_ASYNCTRIG_MASK 0x10u
#define ENET_MAC_PTO_CONTROL_ASYNCTRIG_SHIFT 4u
#define ENET_MAC_PTO_CONTROL_ASYNCTRIG_WIDTH 1u
#define ENET_MAC_PTO_CONTROL_ASYNCTRIG(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_PTO_CONTROL_ASYNCTRIG_SHIFT))&ENET_MAC_PTO_CONTROL_ASYNCTRIG_MASK)
#define ENET_MAC_PTO_CONTROL_APDREQEN_MASK 0x4u
#define ENET_MAC_PTO_CONTROL_APDREQEN_SHIFT 2u
#define ENET_MAC_PTO_CONTROL_APDREQEN_WIDTH 1u
#define ENET_MAC_PTO_CONTROL_APDREQEN(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_PTO_CONTROL_APDREQEN_SHIFT))&ENET_MAC_PTO_CONTROL_APDREQEN_MASK)
#define ENET_MAC_PTO_CONTROL_ASYNCEN_MASK 0x2u
#define ENET_MAC_PTO_CONTROL_ASYNCEN_SHIFT 1u
#define ENET_MAC_PTO_CONTROL_ASYNCEN_WIDTH 1u
#define ENET_MAC_PTO_CONTROL_ASYNCEN(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_PTO_CONTROL_ASYNCEN_SHIFT))&ENET_MAC_PTO_CONTROL_ASYNCEN_MASK)
#define ENET_MAC_PTO_CONTROL_PTOEN_MASK 0x1u
#define ENET_MAC_PTO_CONTROL_PTOEN_SHIFT 0u
#define ENET_MAC_PTO_CONTROL_PTOEN_WIDTH 1u
#define ENET_MAC_PTO_CONTROL_PTOEN(x)  (((uint32_t)(((uint32_t)(x))<<ENET_MAC_PTO_CONTROL_PTOEN_SHIFT))&ENET_MAC_PTO_CONTROL_PTOEN_MASK)
/* MAC_PTO_CONTROL Reg Mask */
#define ENET_MAC_PTO_CONTROL_MASK      0x0000FFF7u

/* MAC_SOURCE_PORT_IDENTITY0 Bit Fields */
#define ENET_MAC_SOURCE_PORT_IDENTITY0_SPI0_MASK 0xFFFFFFFFu
#define ENET_MAC_SOURCE_PORT_IDENTITY0_SPI0_SHIFT 0u
#define ENET_MAC_SOURCE_PORT_IDENTITY0_SPI0_WIDTH 32u
#define ENET_MAC_SOURCE_PORT_IDENTITY0_SPI0(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_SOURCE_PORT_IDENTITY0_SPI0_SHIFT))&ENET_MAC_SOURCE_PORT_IDENTITY0_SPI0_MASK)
/* MAC_SOURCE_PORT_IDENTITY0 Reg Mask */
#define ENET_MAC_SOURCE_PORT_IDENTITY0_MASK 0xFFFFFFFFu

/* MAC_SOURCE_PORT_IDENTITY1 Bit Fields */
#define ENET_MAC_SOURCE_PORT_IDENTITY1_SPI1_MASK 0xFFFFFFFFu
#define ENET_MAC_SOURCE_PORT_IDENTITY1_SPI1_SHIFT 0u
#define ENET_MAC_SOURCE_PORT_IDENTITY1_SPI1_WIDTH 32u
#define ENET_MAC_SOURCE_PORT_IDENTITY1_SPI1(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_SOURCE_PORT_IDENTITY1_SPI1_SHIFT))&ENET_MAC_SOURCE_PORT_IDENTITY1_SPI1_MASK)
/* MAC_SOURCE_PORT_IDENTITY1 Reg Mask */
#define ENET_MAC_SOURCE_PORT_IDENTITY1_MASK 0xFFFFFFFFu

/* MAC_SOURCE_PORT_IDENTITY2 Bit Fields */
#define ENET_MAC_SOURCE_PORT_IDENTITY2_SPI2_MASK 0xFFFFu
#define ENET_MAC_SOURCE_PORT_IDENTITY2_SPI2_SHIFT 0u
#define ENET_MAC_SOURCE_PORT_IDENTITY2_SPI2_WIDTH 16u
#define ENET_MAC_SOURCE_PORT_IDENTITY2_SPI2(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_SOURCE_PORT_IDENTITY2_SPI2_SHIFT))&ENET_MAC_SOURCE_PORT_IDENTITY2_SPI2_MASK)
/* MAC_SOURCE_PORT_IDENTITY2 Reg Mask */
#define ENET_MAC_SOURCE_PORT_IDENTITY2_MASK 0x0000FFFFu

/* MAC_LOG_MESSAGE_INTERVAL Bit Fields */
#define ENET_MAC_LOG_MESSAGE_INTERVAL_LMPDRI_MASK 0xFF000000u
#define ENET_MAC_LOG_MESSAGE_INTERVAL_LMPDRI_SHIFT 24u
#define ENET_MAC_LOG_MESSAGE_INTERVAL_LMPDRI_WIDTH 8u
#define ENET_MAC_LOG_MESSAGE_INTERVAL_LMPDRI(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_LOG_MESSAGE_INTERVAL_LMPDRI_SHIFT))&ENET_MAC_LOG_MESSAGE_INTERVAL_LMPDRI_MASK)
#define ENET_MAC_LOG_MESSAGE_INTERVAL_DRSYNCR_MASK 0x700u
#define ENET_MAC_LOG_MESSAGE_INTERVAL_DRSYNCR_SHIFT 8u
#define ENET_MAC_LOG_MESSAGE_INTERVAL_DRSYNCR_WIDTH 3u
#define ENET_MAC_LOG_MESSAGE_INTERVAL_DRSYNCR(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_LOG_MESSAGE_INTERVAL_DRSYNCR_SHIFT))&ENET_MAC_LOG_MESSAGE_INTERVAL_DRSYNCR_MASK)
#define ENET_MAC_LOG_MESSAGE_INTERVAL_LSI_MASK 0xFFu
#define ENET_MAC_LOG_MESSAGE_INTERVAL_LSI_SHIFT 0u
#define ENET_MAC_LOG_MESSAGE_INTERVAL_LSI_WIDTH 8u
#define ENET_MAC_LOG_MESSAGE_INTERVAL_LSI(x) (((uint32_t)(((uint32_t)(x))<<ENET_MAC_LOG_MESSAGE_INTERVAL_LSI_SHIFT))&ENET_MAC_LOG_MESSAGE_INTERVAL_LSI_MASK)
/* MAC_LOG_MESSAGE_INTERVAL Reg Mask */
#define ENET_MAC_LOG_MESSAGE_INTERVAL_MASK 0xFF0007FFu

/* MTL_OPERATION_MODE Bit Fields */
#define ENET_MTL_OPERATION_MODE_FRPE_MASK 0x8000u
#define ENET_MTL_OPERATION_MODE_FRPE_SHIFT 15u
#define ENET_MTL_OPERATION_MODE_FRPE_WIDTH 1u
#define ENET_MTL_OPERATION_MODE_FRPE(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_OPERATION_MODE_FRPE_SHIFT))&ENET_MTL_OPERATION_MODE_FRPE_MASK)
#define ENET_MTL_OPERATION_MODE_RXPED_MASK 0x4000u
#define ENET_MTL_OPERATION_MODE_RXPED_SHIFT 14u
#define ENET_MTL_OPERATION_MODE_RXPED_WIDTH 1u
#define ENET_MTL_OPERATION_MODE_RXPED(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_OPERATION_MODE_RXPED_SHIFT))&ENET_MTL_OPERATION_MODE_RXPED_MASK)
#define ENET_MTL_OPERATION_MODE_CNTCLR_MASK 0x200u
#define ENET_MTL_OPERATION_MODE_CNTCLR_SHIFT 9u
#define ENET_MTL_OPERATION_MODE_CNTCLR_WIDTH 1u
#define ENET_MTL_OPERATION_MODE_CNTCLR(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_OPERATION_MODE_CNTCLR_SHIFT))&ENET_MTL_OPERATION_MODE_CNTCLR_MASK)
#define ENET_MTL_OPERATION_MODE_CNTPRST_MASK 0x100u
#define ENET_MTL_OPERATION_MODE_CNTPRST_SHIFT 8u
#define ENET_MTL_OPERATION_MODE_CNTPRST_WIDTH 1u
#define ENET_MTL_OPERATION_MODE_CNTPRST(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_OPERATION_MODE_CNTPRST_SHIFT))&ENET_MTL_OPERATION_MODE_CNTPRST_MASK)
#define ENET_MTL_OPERATION_MODE_SCHALG_MASK 0x60u
#define ENET_MTL_OPERATION_MODE_SCHALG_SHIFT 5u
#define ENET_MTL_OPERATION_MODE_SCHALG_WIDTH 2u
#define ENET_MTL_OPERATION_MODE_SCHALG(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_OPERATION_MODE_SCHALG_SHIFT))&ENET_MTL_OPERATION_MODE_SCHALG_MASK)
#define ENET_MTL_OPERATION_MODE_RAA_MASK 0x4u
#define ENET_MTL_OPERATION_MODE_RAA_SHIFT 2u
#define ENET_MTL_OPERATION_MODE_RAA_WIDTH 1u
#define ENET_MTL_OPERATION_MODE_RAA(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_OPERATION_MODE_RAA_SHIFT))&ENET_MTL_OPERATION_MODE_RAA_MASK)
#define ENET_MTL_OPERATION_MODE_DTXSTS_MASK 0x2u
#define ENET_MTL_OPERATION_MODE_DTXSTS_SHIFT 1u
#define ENET_MTL_OPERATION_MODE_DTXSTS_WIDTH 1u
#define ENET_MTL_OPERATION_MODE_DTXSTS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_OPERATION_MODE_DTXSTS_SHIFT))&ENET_MTL_OPERATION_MODE_DTXSTS_MASK)
/* MTL_OPERATION_MODE Reg Mask */
#define ENET_MTL_OPERATION_MODE_MASK   0x0000C366u

/* MTL_DBG_CTL Bit Fields */
#define ENET_MTL_DBG_CTL_EIEC_MASK     0x40000u
#define ENET_MTL_DBG_CTL_EIEC_SHIFT    18u
#define ENET_MTL_DBG_CTL_EIEC_WIDTH    1u
#define ENET_MTL_DBG_CTL_EIEC(x)       (((uint32_t)(((uint32_t)(x))<<ENET_MTL_DBG_CTL_EIEC_SHIFT))&ENET_MTL_DBG_CTL_EIEC_MASK)
#define ENET_MTL_DBG_CTL_EIAEE_MASK    0x20000u
#define ENET_MTL_DBG_CTL_EIAEE_SHIFT   17u
#define ENET_MTL_DBG_CTL_EIAEE_WIDTH   1u
#define ENET_MTL_DBG_CTL_EIAEE(x)      (((uint32_t)(((uint32_t)(x))<<ENET_MTL_DBG_CTL_EIAEE_SHIFT))&ENET_MTL_DBG_CTL_EIAEE_MASK)
#define ENET_MTL_DBG_CTL_EIEE_MASK     0x10000u
#define ENET_MTL_DBG_CTL_EIEE_SHIFT    16u
#define ENET_MTL_DBG_CTL_EIEE_WIDTH    1u
#define ENET_MTL_DBG_CTL_EIEE(x)       (((uint32_t)(((uint32_t)(x))<<ENET_MTL_DBG_CTL_EIEE_SHIFT))&ENET_MTL_DBG_CTL_EIEE_MASK)
#define ENET_MTL_DBG_CTL_STSIE_MASK    0x8000u
#define ENET_MTL_DBG_CTL_STSIE_SHIFT   15u
#define ENET_MTL_DBG_CTL_STSIE_WIDTH   1u
#define ENET_MTL_DBG_CTL_STSIE(x)      (((uint32_t)(((uint32_t)(x))<<ENET_MTL_DBG_CTL_STSIE_SHIFT))&ENET_MTL_DBG_CTL_STSIE_MASK)
#define ENET_MTL_DBG_CTL_PKTIE_MASK    0x4000u
#define ENET_MTL_DBG_CTL_PKTIE_SHIFT   14u
#define ENET_MTL_DBG_CTL_PKTIE_WIDTH   1u
#define ENET_MTL_DBG_CTL_PKTIE(x)      (((uint32_t)(((uint32_t)(x))<<ENET_MTL_DBG_CTL_PKTIE_SHIFT))&ENET_MTL_DBG_CTL_PKTIE_MASK)
#define ENET_MTL_DBG_CTL_FIFOSEL_MASK  0x3000u
#define ENET_MTL_DBG_CTL_FIFOSEL_SHIFT 12u
#define ENET_MTL_DBG_CTL_FIFOSEL_WIDTH 2u
#define ENET_MTL_DBG_CTL_FIFOSEL(x)    (((uint32_t)(((uint32_t)(x))<<ENET_MTL_DBG_CTL_FIFOSEL_SHIFT))&ENET_MTL_DBG_CTL_FIFOSEL_MASK)
#define ENET_MTL_DBG_CTL_FIFOWREN_MASK 0x800u
#define ENET_MTL_DBG_CTL_FIFOWREN_SHIFT 11u
#define ENET_MTL_DBG_CTL_FIFOWREN_WIDTH 1u
#define ENET_MTL_DBG_CTL_FIFOWREN(x)   (((uint32_t)(((uint32_t)(x))<<ENET_MTL_DBG_CTL_FIFOWREN_SHIFT))&ENET_MTL_DBG_CTL_FIFOWREN_MASK)
#define ENET_MTL_DBG_CTL_FIFORDEN_MASK 0x400u
#define ENET_MTL_DBG_CTL_FIFORDEN_SHIFT 10u
#define ENET_MTL_DBG_CTL_FIFORDEN_WIDTH 1u
#define ENET_MTL_DBG_CTL_FIFORDEN(x)   (((uint32_t)(((uint32_t)(x))<<ENET_MTL_DBG_CTL_FIFORDEN_SHIFT))&ENET_MTL_DBG_CTL_FIFORDEN_MASK)
#define ENET_MTL_DBG_CTL_RSTSEL_MASK   0x200u
#define ENET_MTL_DBG_CTL_RSTSEL_SHIFT  9u
#define ENET_MTL_DBG_CTL_RSTSEL_WIDTH  1u
#define ENET_MTL_DBG_CTL_RSTSEL(x)     (((uint32_t)(((uint32_t)(x))<<ENET_MTL_DBG_CTL_RSTSEL_SHIFT))&ENET_MTL_DBG_CTL_RSTSEL_MASK)
#define ENET_MTL_DBG_CTL_RSTALL_MASK   0x100u
#define ENET_MTL_DBG_CTL_RSTALL_SHIFT  8u
#define ENET_MTL_DBG_CTL_RSTALL_WIDTH  1u
#define ENET_MTL_DBG_CTL_RSTALL(x)     (((uint32_t)(((uint32_t)(x))<<ENET_MTL_DBG_CTL_RSTALL_SHIFT))&ENET_MTL_DBG_CTL_RSTALL_MASK)
#define ENET_MTL_DBG_CTL_PKTSTATE_MASK 0x60u
#define ENET_MTL_DBG_CTL_PKTSTATE_SHIFT 5u
#define ENET_MTL_DBG_CTL_PKTSTATE_WIDTH 2u
#define ENET_MTL_DBG_CTL_PKTSTATE(x)   (((uint32_t)(((uint32_t)(x))<<ENET_MTL_DBG_CTL_PKTSTATE_SHIFT))&ENET_MTL_DBG_CTL_PKTSTATE_MASK)
#define ENET_MTL_DBG_CTL_BYTEEN_MASK   0xCu
#define ENET_MTL_DBG_CTL_BYTEEN_SHIFT  2u
#define ENET_MTL_DBG_CTL_BYTEEN_WIDTH  2u
#define ENET_MTL_DBG_CTL_BYTEEN(x)     (((uint32_t)(((uint32_t)(x))<<ENET_MTL_DBG_CTL_BYTEEN_SHIFT))&ENET_MTL_DBG_CTL_BYTEEN_MASK)
#define ENET_MTL_DBG_CTL_DBGMOD_MASK   0x2u
#define ENET_MTL_DBG_CTL_DBGMOD_SHIFT  1u
#define ENET_MTL_DBG_CTL_DBGMOD_WIDTH  1u
#define ENET_MTL_DBG_CTL_DBGMOD(x)     (((uint32_t)(((uint32_t)(x))<<ENET_MTL_DBG_CTL_DBGMOD_SHIFT))&ENET_MTL_DBG_CTL_DBGMOD_MASK)
#define ENET_MTL_DBG_CTL_FDBGEN_MASK   0x1u
#define ENET_MTL_DBG_CTL_FDBGEN_SHIFT  0u
#define ENET_MTL_DBG_CTL_FDBGEN_WIDTH  1u
#define ENET_MTL_DBG_CTL_FDBGEN(x)     (((uint32_t)(((uint32_t)(x))<<ENET_MTL_DBG_CTL_FDBGEN_SHIFT))&ENET_MTL_DBG_CTL_FDBGEN_MASK)
/* MTL_DBG_CTL Reg Mask */
#define ENET_MTL_DBG_CTL_MASK          0x0007FF6Fu

/* MTL_DBG_STS Bit Fields */
#define ENET_MTL_DBG_STS_LOCR_MASK     0xFFFF8000u
#define ENET_MTL_DBG_STS_LOCR_SHIFT    15u
#define ENET_MTL_DBG_STS_LOCR_WIDTH    17u
#define ENET_MTL_DBG_STS_LOCR(x)       (((uint32_t)(((uint32_t)(x))<<ENET_MTL_DBG_STS_LOCR_SHIFT))&ENET_MTL_DBG_STS_LOCR_MASK)
#define ENET_MTL_DBG_STS_STSI_MASK     0x200u
#define ENET_MTL_DBG_STS_STSI_SHIFT    9u
#define ENET_MTL_DBG_STS_STSI_WIDTH    1u
#define ENET_MTL_DBG_STS_STSI(x)       (((uint32_t)(((uint32_t)(x))<<ENET_MTL_DBG_STS_STSI_SHIFT))&ENET_MTL_DBG_STS_STSI_MASK)
#define ENET_MTL_DBG_STS_PKTI_MASK     0x100u
#define ENET_MTL_DBG_STS_PKTI_SHIFT    8u
#define ENET_MTL_DBG_STS_PKTI_WIDTH    1u
#define ENET_MTL_DBG_STS_PKTI(x)       (((uint32_t)(((uint32_t)(x))<<ENET_MTL_DBG_STS_PKTI_SHIFT))&ENET_MTL_DBG_STS_PKTI_MASK)
#define ENET_MTL_DBG_STS_BYTEEN_MASK   0x18u
#define ENET_MTL_DBG_STS_BYTEEN_SHIFT  3u
#define ENET_MTL_DBG_STS_BYTEEN_WIDTH  2u
#define ENET_MTL_DBG_STS_BYTEEN(x)     (((uint32_t)(((uint32_t)(x))<<ENET_MTL_DBG_STS_BYTEEN_SHIFT))&ENET_MTL_DBG_STS_BYTEEN_MASK)
#define ENET_MTL_DBG_STS_PKTSTATE_MASK 0x6u
#define ENET_MTL_DBG_STS_PKTSTATE_SHIFT 1u
#define ENET_MTL_DBG_STS_PKTSTATE_WIDTH 2u
#define ENET_MTL_DBG_STS_PKTSTATE(x)   (((uint32_t)(((uint32_t)(x))<<ENET_MTL_DBG_STS_PKTSTATE_SHIFT))&ENET_MTL_DBG_STS_PKTSTATE_MASK)
#define ENET_MTL_DBG_STS_FIFOBUSY_MASK 0x1u
#define ENET_MTL_DBG_STS_FIFOBUSY_SHIFT 0u
#define ENET_MTL_DBG_STS_FIFOBUSY_WIDTH 1u
#define ENET_MTL_DBG_STS_FIFOBUSY(x)   (((uint32_t)(((uint32_t)(x))<<ENET_MTL_DBG_STS_FIFOBUSY_SHIFT))&ENET_MTL_DBG_STS_FIFOBUSY_MASK)
/* MTL_DBG_STS Reg Mask */
#define ENET_MTL_DBG_STS_MASK          0xFFFF831Fu

/* MTL_FIFO_DEBUG_DATA Bit Fields */
#define ENET_MTL_FIFO_DEBUG_DATA_FDBGDATA_MASK 0xFFFFFFFFu
#define ENET_MTL_FIFO_DEBUG_DATA_FDBGDATA_SHIFT 0u
#define ENET_MTL_FIFO_DEBUG_DATA_FDBGDATA_WIDTH 32u
#define ENET_MTL_FIFO_DEBUG_DATA_FDBGDATA(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_FIFO_DEBUG_DATA_FDBGDATA_SHIFT))&ENET_MTL_FIFO_DEBUG_DATA_FDBGDATA_MASK)
/* MTL_FIFO_DEBUG_DATA Reg Mask */
#define ENET_MTL_FIFO_DEBUG_DATA_MASK  0xFFFFFFFFu

/* MTL_INTERRUPT_STATUS Bit Fields */
#define ENET_MTL_INTERRUPT_STATUS_MTLPIS_MASK 0x800000u
#define ENET_MTL_INTERRUPT_STATUS_MTLPIS_SHIFT 23u
#define ENET_MTL_INTERRUPT_STATUS_MTLPIS_WIDTH 1u
#define ENET_MTL_INTERRUPT_STATUS_MTLPIS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_INTERRUPT_STATUS_MTLPIS_SHIFT))&ENET_MTL_INTERRUPT_STATUS_MTLPIS_MASK)
#define ENET_MTL_INTERRUPT_STATUS_ESTIS_MASK 0x40000u
#define ENET_MTL_INTERRUPT_STATUS_ESTIS_SHIFT 18u
#define ENET_MTL_INTERRUPT_STATUS_ESTIS_WIDTH 1u
#define ENET_MTL_INTERRUPT_STATUS_ESTIS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_INTERRUPT_STATUS_ESTIS_SHIFT))&ENET_MTL_INTERRUPT_STATUS_ESTIS_MASK)
#define ENET_MTL_INTERRUPT_STATUS_DBGIS_MASK 0x20000u
#define ENET_MTL_INTERRUPT_STATUS_DBGIS_SHIFT 17u
#define ENET_MTL_INTERRUPT_STATUS_DBGIS_WIDTH 1u
#define ENET_MTL_INTERRUPT_STATUS_DBGIS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_INTERRUPT_STATUS_DBGIS_SHIFT))&ENET_MTL_INTERRUPT_STATUS_DBGIS_MASK)
#define ENET_MTL_INTERRUPT_STATUS_Q1IS_MASK 0x2u
#define ENET_MTL_INTERRUPT_STATUS_Q1IS_SHIFT 1u
#define ENET_MTL_INTERRUPT_STATUS_Q1IS_WIDTH 1u
#define ENET_MTL_INTERRUPT_STATUS_Q1IS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_INTERRUPT_STATUS_Q1IS_SHIFT))&ENET_MTL_INTERRUPT_STATUS_Q1IS_MASK)
#define ENET_MTL_INTERRUPT_STATUS_Q0IS_MASK 0x1u
#define ENET_MTL_INTERRUPT_STATUS_Q0IS_SHIFT 0u
#define ENET_MTL_INTERRUPT_STATUS_Q0IS_WIDTH 1u
#define ENET_MTL_INTERRUPT_STATUS_Q0IS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_INTERRUPT_STATUS_Q0IS_SHIFT))&ENET_MTL_INTERRUPT_STATUS_Q0IS_MASK)
/* MTL_INTERRUPT_STATUS Reg Mask */
#define ENET_MTL_INTERRUPT_STATUS_MASK 0x00860003u

/* MTL_RXQ_DMA_MAP0 Bit Fields */
#define ENET_MTL_RXQ_DMA_MAP0_Q1DDMACH_MASK 0x1000u
#define ENET_MTL_RXQ_DMA_MAP0_Q1DDMACH_SHIFT 12u
#define ENET_MTL_RXQ_DMA_MAP0_Q1DDMACH_WIDTH 1u
#define ENET_MTL_RXQ_DMA_MAP0_Q1DDMACH(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_RXQ_DMA_MAP0_Q1DDMACH_SHIFT))&ENET_MTL_RXQ_DMA_MAP0_Q1DDMACH_MASK)
#define ENET_MTL_RXQ_DMA_MAP0_Q1MDMACH_MASK 0x100u
#define ENET_MTL_RXQ_DMA_MAP0_Q1MDMACH_SHIFT 8u
#define ENET_MTL_RXQ_DMA_MAP0_Q1MDMACH_WIDTH 1u
#define ENET_MTL_RXQ_DMA_MAP0_Q1MDMACH(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_RXQ_DMA_MAP0_Q1MDMACH_SHIFT))&ENET_MTL_RXQ_DMA_MAP0_Q1MDMACH_MASK)
#define ENET_MTL_RXQ_DMA_MAP0_Q0DDMACH_MASK 0x10u
#define ENET_MTL_RXQ_DMA_MAP0_Q0DDMACH_SHIFT 4u
#define ENET_MTL_RXQ_DMA_MAP0_Q0DDMACH_WIDTH 1u
#define ENET_MTL_RXQ_DMA_MAP0_Q0DDMACH(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_RXQ_DMA_MAP0_Q0DDMACH_SHIFT))&ENET_MTL_RXQ_DMA_MAP0_Q0DDMACH_MASK)
#define ENET_MTL_RXQ_DMA_MAP0_Q0MDMACH_MASK 0x1u
#define ENET_MTL_RXQ_DMA_MAP0_Q0MDMACH_SHIFT 0u
#define ENET_MTL_RXQ_DMA_MAP0_Q0MDMACH_WIDTH 1u
#define ENET_MTL_RXQ_DMA_MAP0_Q0MDMACH(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_RXQ_DMA_MAP0_Q0MDMACH_SHIFT))&ENET_MTL_RXQ_DMA_MAP0_Q0MDMACH_MASK)
/* MTL_RXQ_DMA_MAP0 Reg Mask */
#define ENET_MTL_RXQ_DMA_MAP0_MASK     0x00001111u

/* MTL_RXQ_DMA_MAP1 Bit Fields */
/* MTL_RXQ_DMA_MAP1 Reg Mask */
#define ENET_MTL_RXQ_DMA_MAP1_MASK     0x00000000u

/* MTL_TBS_CTRL Bit Fields */
#define ENET_MTL_TBS_CTRL_LEOS_MASK    0xFFFFFF00u
#define ENET_MTL_TBS_CTRL_LEOS_SHIFT   8u
#define ENET_MTL_TBS_CTRL_LEOS_WIDTH   24u
#define ENET_MTL_TBS_CTRL_LEOS(x)      (((uint32_t)(((uint32_t)(x))<<ENET_MTL_TBS_CTRL_LEOS_SHIFT))&ENET_MTL_TBS_CTRL_LEOS_MASK)
#define ENET_MTL_TBS_CTRL_LEGOS_MASK   0x70u
#define ENET_MTL_TBS_CTRL_LEGOS_SHIFT  4u
#define ENET_MTL_TBS_CTRL_LEGOS_WIDTH  3u
#define ENET_MTL_TBS_CTRL_LEGOS(x)     (((uint32_t)(((uint32_t)(x))<<ENET_MTL_TBS_CTRL_LEGOS_SHIFT))&ENET_MTL_TBS_CTRL_LEGOS_MASK)
#define ENET_MTL_TBS_CTRL_LEOV_MASK    0x2u
#define ENET_MTL_TBS_CTRL_LEOV_SHIFT   1u
#define ENET_MTL_TBS_CTRL_LEOV_WIDTH   1u
#define ENET_MTL_TBS_CTRL_LEOV(x)      (((uint32_t)(((uint32_t)(x))<<ENET_MTL_TBS_CTRL_LEOV_SHIFT))&ENET_MTL_TBS_CTRL_LEOV_MASK)
#define ENET_MTL_TBS_CTRL_ESTM_MASK    0x1u
#define ENET_MTL_TBS_CTRL_ESTM_SHIFT   0u
#define ENET_MTL_TBS_CTRL_ESTM_WIDTH   1u
#define ENET_MTL_TBS_CTRL_ESTM(x)      (((uint32_t)(((uint32_t)(x))<<ENET_MTL_TBS_CTRL_ESTM_SHIFT))&ENET_MTL_TBS_CTRL_ESTM_MASK)
/* MTL_TBS_CTRL Reg Mask */
#define ENET_MTL_TBS_CTRL_MASK         0xFFFFFF73u

/* MTL_EST_CONTROL Bit Fields */
#define ENET_MTL_EST_CONTROL_PTOV_MASK 0xFF000000u
#define ENET_MTL_EST_CONTROL_PTOV_SHIFT 24u
#define ENET_MTL_EST_CONTROL_PTOV_WIDTH 8u
#define ENET_MTL_EST_CONTROL_PTOV(x)   (((uint32_t)(((uint32_t)(x))<<ENET_MTL_EST_CONTROL_PTOV_SHIFT))&ENET_MTL_EST_CONTROL_PTOV_MASK)
#define ENET_MTL_EST_CONTROL_CTOV_MASK 0xFFF000u
#define ENET_MTL_EST_CONTROL_CTOV_SHIFT 12u
#define ENET_MTL_EST_CONTROL_CTOV_WIDTH 12u
#define ENET_MTL_EST_CONTROL_CTOV(x)   (((uint32_t)(((uint32_t)(x))<<ENET_MTL_EST_CONTROL_CTOV_SHIFT))&ENET_MTL_EST_CONTROL_CTOV_MASK)
#define ENET_MTL_EST_CONTROL_TILS_MASK 0x700u
#define ENET_MTL_EST_CONTROL_TILS_SHIFT 8u
#define ENET_MTL_EST_CONTROL_TILS_WIDTH 3u
#define ENET_MTL_EST_CONTROL_TILS(x)   (((uint32_t)(((uint32_t)(x))<<ENET_MTL_EST_CONTROL_TILS_SHIFT))&ENET_MTL_EST_CONTROL_TILS_MASK)
#define ENET_MTL_EST_CONTROL_LCSE_MASK 0xC0u
#define ENET_MTL_EST_CONTROL_LCSE_SHIFT 6u
#define ENET_MTL_EST_CONTROL_LCSE_WIDTH 2u
#define ENET_MTL_EST_CONTROL_LCSE(x)   (((uint32_t)(((uint32_t)(x))<<ENET_MTL_EST_CONTROL_LCSE_SHIFT))&ENET_MTL_EST_CONTROL_LCSE_MASK)
#define ENET_MTL_EST_CONTROL_DFBS_MASK 0x20u
#define ENET_MTL_EST_CONTROL_DFBS_SHIFT 5u
#define ENET_MTL_EST_CONTROL_DFBS_WIDTH 1u
#define ENET_MTL_EST_CONTROL_DFBS(x)   (((uint32_t)(((uint32_t)(x))<<ENET_MTL_EST_CONTROL_DFBS_SHIFT))&ENET_MTL_EST_CONTROL_DFBS_MASK)
#define ENET_MTL_EST_CONTROL_DDBF_MASK 0x10u
#define ENET_MTL_EST_CONTROL_DDBF_SHIFT 4u
#define ENET_MTL_EST_CONTROL_DDBF_WIDTH 1u
#define ENET_MTL_EST_CONTROL_DDBF(x)   (((uint32_t)(((uint32_t)(x))<<ENET_MTL_EST_CONTROL_DDBF_SHIFT))&ENET_MTL_EST_CONTROL_DDBF_MASK)
#define ENET_MTL_EST_CONTROL_SSWL_MASK 0x2u
#define ENET_MTL_EST_CONTROL_SSWL_SHIFT 1u
#define ENET_MTL_EST_CONTROL_SSWL_WIDTH 1u
#define ENET_MTL_EST_CONTROL_SSWL(x)   (((uint32_t)(((uint32_t)(x))<<ENET_MTL_EST_CONTROL_SSWL_SHIFT))&ENET_MTL_EST_CONTROL_SSWL_MASK)
#define ENET_MTL_EST_CONTROL_EEST_MASK 0x1u
#define ENET_MTL_EST_CONTROL_EEST_SHIFT 0u
#define ENET_MTL_EST_CONTROL_EEST_WIDTH 1u
#define ENET_MTL_EST_CONTROL_EEST(x)   (((uint32_t)(((uint32_t)(x))<<ENET_MTL_EST_CONTROL_EEST_SHIFT))&ENET_MTL_EST_CONTROL_EEST_MASK)
/* MTL_EST_CONTROL Reg Mask */
#define ENET_MTL_EST_CONTROL_MASK      0xFFFFF7F3u

/* MTL_EST_EXT_CONTROL Bit Fields */
#define ENET_MTL_EST_EXT_CONTROL_OVHD_MASK 0x3Fu
#define ENET_MTL_EST_EXT_CONTROL_OVHD_SHIFT 0u
#define ENET_MTL_EST_EXT_CONTROL_OVHD_WIDTH 6u
#define ENET_MTL_EST_EXT_CONTROL_OVHD(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_EST_EXT_CONTROL_OVHD_SHIFT))&ENET_MTL_EST_EXT_CONTROL_OVHD_MASK)
/* MTL_EST_EXT_CONTROL Reg Mask */
#define ENET_MTL_EST_EXT_CONTROL_MASK  0x0000003Fu

/* MTL_EST_STATUS Bit Fields */
#define ENET_MTL_EST_STATUS_CGSN_MASK  0xF0000u
#define ENET_MTL_EST_STATUS_CGSN_SHIFT 16u
#define ENET_MTL_EST_STATUS_CGSN_WIDTH 4u
#define ENET_MTL_EST_STATUS_CGSN(x)    (((uint32_t)(((uint32_t)(x))<<ENET_MTL_EST_STATUS_CGSN_SHIFT))&ENET_MTL_EST_STATUS_CGSN_MASK)
#define ENET_MTL_EST_STATUS_BTRL_MASK  0xFF00u
#define ENET_MTL_EST_STATUS_BTRL_SHIFT 8u
#define ENET_MTL_EST_STATUS_BTRL_WIDTH 8u
#define ENET_MTL_EST_STATUS_BTRL(x)    (((uint32_t)(((uint32_t)(x))<<ENET_MTL_EST_STATUS_BTRL_SHIFT))&ENET_MTL_EST_STATUS_BTRL_MASK)
#define ENET_MTL_EST_STATUS_SWOL_MASK  0x80u
#define ENET_MTL_EST_STATUS_SWOL_SHIFT 7u
#define ENET_MTL_EST_STATUS_SWOL_WIDTH 1u
#define ENET_MTL_EST_STATUS_SWOL(x)    (((uint32_t)(((uint32_t)(x))<<ENET_MTL_EST_STATUS_SWOL_SHIFT))&ENET_MTL_EST_STATUS_SWOL_MASK)
#define ENET_MTL_EST_STATUS_CGCE_MASK  0x10u
#define ENET_MTL_EST_STATUS_CGCE_SHIFT 4u
#define ENET_MTL_EST_STATUS_CGCE_WIDTH 1u
#define ENET_MTL_EST_STATUS_CGCE(x)    (((uint32_t)(((uint32_t)(x))<<ENET_MTL_EST_STATUS_CGCE_SHIFT))&ENET_MTL_EST_STATUS_CGCE_MASK)
#define ENET_MTL_EST_STATUS_HLBS_MASK  0x8u
#define ENET_MTL_EST_STATUS_HLBS_SHIFT 3u
#define ENET_MTL_EST_STATUS_HLBS_WIDTH 1u
#define ENET_MTL_EST_STATUS_HLBS(x)    (((uint32_t)(((uint32_t)(x))<<ENET_MTL_EST_STATUS_HLBS_SHIFT))&ENET_MTL_EST_STATUS_HLBS_MASK)
#define ENET_MTL_EST_STATUS_HLBF_MASK  0x4u
#define ENET_MTL_EST_STATUS_HLBF_SHIFT 2u
#define ENET_MTL_EST_STATUS_HLBF_WIDTH 1u
#define ENET_MTL_EST_STATUS_HLBF(x)    (((uint32_t)(((uint32_t)(x))<<ENET_MTL_EST_STATUS_HLBF_SHIFT))&ENET_MTL_EST_STATUS_HLBF_MASK)
#define ENET_MTL_EST_STATUS_BTRE_MASK  0x2u
#define ENET_MTL_EST_STATUS_BTRE_SHIFT 1u
#define ENET_MTL_EST_STATUS_BTRE_WIDTH 1u
#define ENET_MTL_EST_STATUS_BTRE(x)    (((uint32_t)(((uint32_t)(x))<<ENET_MTL_EST_STATUS_BTRE_SHIFT))&ENET_MTL_EST_STATUS_BTRE_MASK)
#define ENET_MTL_EST_STATUS_SWLC_MASK  0x1u
#define ENET_MTL_EST_STATUS_SWLC_SHIFT 0u
#define ENET_MTL_EST_STATUS_SWLC_WIDTH 1u
#define ENET_MTL_EST_STATUS_SWLC(x)    (((uint32_t)(((uint32_t)(x))<<ENET_MTL_EST_STATUS_SWLC_SHIFT))&ENET_MTL_EST_STATUS_SWLC_MASK)
/* MTL_EST_STATUS Reg Mask */
#define ENET_MTL_EST_STATUS_MASK       0x000FFF9Fu

/* MTL_EST_SCH_ERROR Bit Fields */
#define ENET_MTL_EST_SCH_ERROR_SEQN_MASK 0x3u
#define ENET_MTL_EST_SCH_ERROR_SEQN_SHIFT 0u
#define ENET_MTL_EST_SCH_ERROR_SEQN_WIDTH 2u
#define ENET_MTL_EST_SCH_ERROR_SEQN(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_EST_SCH_ERROR_SEQN_SHIFT))&ENET_MTL_EST_SCH_ERROR_SEQN_MASK)
/* MTL_EST_SCH_ERROR Reg Mask */
#define ENET_MTL_EST_SCH_ERROR_MASK    0x00000003u

/* MTL_EST_FRM_SIZE_ERROR Bit Fields */
#define ENET_MTL_EST_FRM_SIZE_ERROR_FEQN_MASK 0x3u
#define ENET_MTL_EST_FRM_SIZE_ERROR_FEQN_SHIFT 0u
#define ENET_MTL_EST_FRM_SIZE_ERROR_FEQN_WIDTH 2u
#define ENET_MTL_EST_FRM_SIZE_ERROR_FEQN(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_EST_FRM_SIZE_ERROR_FEQN_SHIFT))&ENET_MTL_EST_FRM_SIZE_ERROR_FEQN_MASK)
/* MTL_EST_FRM_SIZE_ERROR Reg Mask */
#define ENET_MTL_EST_FRM_SIZE_ERROR_MASK 0x00000003u

/* MTL_EST_FRM_SIZE_CAPTURE Bit Fields */
#define ENET_MTL_EST_FRM_SIZE_CAPTURE_HBFQ_MASK 0x10000u
#define ENET_MTL_EST_FRM_SIZE_CAPTURE_HBFQ_SHIFT 16u
#define ENET_MTL_EST_FRM_SIZE_CAPTURE_HBFQ_WIDTH 1u
#define ENET_MTL_EST_FRM_SIZE_CAPTURE_HBFQ(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_EST_FRM_SIZE_CAPTURE_HBFQ_SHIFT))&ENET_MTL_EST_FRM_SIZE_CAPTURE_HBFQ_MASK)
#define ENET_MTL_EST_FRM_SIZE_CAPTURE_HBFS_MASK 0x7FFFu
#define ENET_MTL_EST_FRM_SIZE_CAPTURE_HBFS_SHIFT 0u
#define ENET_MTL_EST_FRM_SIZE_CAPTURE_HBFS_WIDTH 15u
#define ENET_MTL_EST_FRM_SIZE_CAPTURE_HBFS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_EST_FRM_SIZE_CAPTURE_HBFS_SHIFT))&ENET_MTL_EST_FRM_SIZE_CAPTURE_HBFS_MASK)
/* MTL_EST_FRM_SIZE_CAPTURE Reg Mask */
#define ENET_MTL_EST_FRM_SIZE_CAPTURE_MASK 0x00017FFFu

/* MTL_EST_INTR_ENABLE Bit Fields */
#define ENET_MTL_EST_INTR_ENABLE_CGCE_MASK 0x10u
#define ENET_MTL_EST_INTR_ENABLE_CGCE_SHIFT 4u
#define ENET_MTL_EST_INTR_ENABLE_CGCE_WIDTH 1u
#define ENET_MTL_EST_INTR_ENABLE_CGCE(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_EST_INTR_ENABLE_CGCE_SHIFT))&ENET_MTL_EST_INTR_ENABLE_CGCE_MASK)
#define ENET_MTL_EST_INTR_ENABLE_IEHS_MASK 0x8u
#define ENET_MTL_EST_INTR_ENABLE_IEHS_SHIFT 3u
#define ENET_MTL_EST_INTR_ENABLE_IEHS_WIDTH 1u
#define ENET_MTL_EST_INTR_ENABLE_IEHS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_EST_INTR_ENABLE_IEHS_SHIFT))&ENET_MTL_EST_INTR_ENABLE_IEHS_MASK)
#define ENET_MTL_EST_INTR_ENABLE_IEHF_MASK 0x4u
#define ENET_MTL_EST_INTR_ENABLE_IEHF_SHIFT 2u
#define ENET_MTL_EST_INTR_ENABLE_IEHF_WIDTH 1u
#define ENET_MTL_EST_INTR_ENABLE_IEHF(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_EST_INTR_ENABLE_IEHF_SHIFT))&ENET_MTL_EST_INTR_ENABLE_IEHF_MASK)
#define ENET_MTL_EST_INTR_ENABLE_IEBE_MASK 0x2u
#define ENET_MTL_EST_INTR_ENABLE_IEBE_SHIFT 1u
#define ENET_MTL_EST_INTR_ENABLE_IEBE_WIDTH 1u
#define ENET_MTL_EST_INTR_ENABLE_IEBE(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_EST_INTR_ENABLE_IEBE_SHIFT))&ENET_MTL_EST_INTR_ENABLE_IEBE_MASK)
#define ENET_MTL_EST_INTR_ENABLE_IECC_MASK 0x1u
#define ENET_MTL_EST_INTR_ENABLE_IECC_SHIFT 0u
#define ENET_MTL_EST_INTR_ENABLE_IECC_WIDTH 1u
#define ENET_MTL_EST_INTR_ENABLE_IECC(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_EST_INTR_ENABLE_IECC_SHIFT))&ENET_MTL_EST_INTR_ENABLE_IECC_MASK)
/* MTL_EST_INTR_ENABLE Reg Mask */
#define ENET_MTL_EST_INTR_ENABLE_MASK  0x0000001Fu

/* MTL_EST_GCL_CONTROL Bit Fields */
#define ENET_MTL_EST_GCL_CONTROL_ESTEIEC_MASK 0x800000u
#define ENET_MTL_EST_GCL_CONTROL_ESTEIEC_SHIFT 23u
#define ENET_MTL_EST_GCL_CONTROL_ESTEIEC_WIDTH 1u
#define ENET_MTL_EST_GCL_CONTROL_ESTEIEC(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_EST_GCL_CONTROL_ESTEIEC_SHIFT))&ENET_MTL_EST_GCL_CONTROL_ESTEIEC_MASK)
#define ENET_MTL_EST_GCL_CONTROL_ESTEIAEE_MASK 0x400000u
#define ENET_MTL_EST_GCL_CONTROL_ESTEIAEE_SHIFT 22u
#define ENET_MTL_EST_GCL_CONTROL_ESTEIAEE_WIDTH 1u
#define ENET_MTL_EST_GCL_CONTROL_ESTEIAEE(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_EST_GCL_CONTROL_ESTEIAEE_SHIFT))&ENET_MTL_EST_GCL_CONTROL_ESTEIAEE_MASK)
#define ENET_MTL_EST_GCL_CONTROL_ESTEIEE_MASK 0x200000u
#define ENET_MTL_EST_GCL_CONTROL_ESTEIEE_SHIFT 21u
#define ENET_MTL_EST_GCL_CONTROL_ESTEIEE_WIDTH 1u
#define ENET_MTL_EST_GCL_CONTROL_ESTEIEE(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_EST_GCL_CONTROL_ESTEIEE_SHIFT))&ENET_MTL_EST_GCL_CONTROL_ESTEIEE_MASK)
#define ENET_MTL_EST_GCL_CONTROL_ADDR_MASK 0xFF00u
#define ENET_MTL_EST_GCL_CONTROL_ADDR_SHIFT 8u
#define ENET_MTL_EST_GCL_CONTROL_ADDR_WIDTH 8u
#define ENET_MTL_EST_GCL_CONTROL_ADDR(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_EST_GCL_CONTROL_ADDR_SHIFT))&ENET_MTL_EST_GCL_CONTROL_ADDR_MASK)
#define ENET_MTL_EST_GCL_CONTROL_DBGB_MASK 0x20u
#define ENET_MTL_EST_GCL_CONTROL_DBGB_SHIFT 5u
#define ENET_MTL_EST_GCL_CONTROL_DBGB_WIDTH 1u
#define ENET_MTL_EST_GCL_CONTROL_DBGB(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_EST_GCL_CONTROL_DBGB_SHIFT))&ENET_MTL_EST_GCL_CONTROL_DBGB_MASK)
#define ENET_MTL_EST_GCL_CONTROL_DBGM_MASK 0x10u
#define ENET_MTL_EST_GCL_CONTROL_DBGM_SHIFT 4u
#define ENET_MTL_EST_GCL_CONTROL_DBGM_WIDTH 1u
#define ENET_MTL_EST_GCL_CONTROL_DBGM(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_EST_GCL_CONTROL_DBGM_SHIFT))&ENET_MTL_EST_GCL_CONTROL_DBGM_MASK)
#define ENET_MTL_EST_GCL_CONTROL_GCRR_MASK 0x4u
#define ENET_MTL_EST_GCL_CONTROL_GCRR_SHIFT 2u
#define ENET_MTL_EST_GCL_CONTROL_GCRR_WIDTH 1u
#define ENET_MTL_EST_GCL_CONTROL_GCRR(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_EST_GCL_CONTROL_GCRR_SHIFT))&ENET_MTL_EST_GCL_CONTROL_GCRR_MASK)
#define ENET_MTL_EST_GCL_CONTROL_R1W0_MASK 0x2u
#define ENET_MTL_EST_GCL_CONTROL_R1W0_SHIFT 1u
#define ENET_MTL_EST_GCL_CONTROL_R1W0_WIDTH 1u
#define ENET_MTL_EST_GCL_CONTROL_R1W0(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_EST_GCL_CONTROL_R1W0_SHIFT))&ENET_MTL_EST_GCL_CONTROL_R1W0_MASK)
#define ENET_MTL_EST_GCL_CONTROL_SRWO_MASK 0x1u
#define ENET_MTL_EST_GCL_CONTROL_SRWO_SHIFT 0u
#define ENET_MTL_EST_GCL_CONTROL_SRWO_WIDTH 1u
#define ENET_MTL_EST_GCL_CONTROL_SRWO(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_EST_GCL_CONTROL_SRWO_SHIFT))&ENET_MTL_EST_GCL_CONTROL_SRWO_MASK)
/* MTL_EST_GCL_CONTROL Reg Mask */
#define ENET_MTL_EST_GCL_CONTROL_MASK  0x00E0FF37u

/* MTL_EST_GCL_DATA Bit Fields */
#define ENET_MTL_EST_GCL_DATA_GCD_MASK 0xFFFFFFFFu
#define ENET_MTL_EST_GCL_DATA_GCD_SHIFT 0u
#define ENET_MTL_EST_GCL_DATA_GCD_WIDTH 32u
#define ENET_MTL_EST_GCL_DATA_GCD(x)   (((uint32_t)(((uint32_t)(x))<<ENET_MTL_EST_GCL_DATA_GCD_SHIFT))&ENET_MTL_EST_GCL_DATA_GCD_MASK)
/* MTL_EST_GCL_DATA Reg Mask */
#define ENET_MTL_EST_GCL_DATA_MASK     0xFFFFFFFFu

/* MTL_FPE_CTRL_STS Bit Fields */
#define ENET_MTL_FPE_CTRL_STS_HRS_MASK 0x10000000u
#define ENET_MTL_FPE_CTRL_STS_HRS_SHIFT 28u
#define ENET_MTL_FPE_CTRL_STS_HRS_WIDTH 1u
#define ENET_MTL_FPE_CTRL_STS_HRS(x)   (((uint32_t)(((uint32_t)(x))<<ENET_MTL_FPE_CTRL_STS_HRS_SHIFT))&ENET_MTL_FPE_CTRL_STS_HRS_MASK)
#define ENET_MTL_FPE_CTRL_STS_PEC_MASK 0x300u
#define ENET_MTL_FPE_CTRL_STS_PEC_SHIFT 8u
#define ENET_MTL_FPE_CTRL_STS_PEC_WIDTH 2u
#define ENET_MTL_FPE_CTRL_STS_PEC(x)   (((uint32_t)(((uint32_t)(x))<<ENET_MTL_FPE_CTRL_STS_PEC_SHIFT))&ENET_MTL_FPE_CTRL_STS_PEC_MASK)
#define ENET_MTL_FPE_CTRL_STS_AFSZ_MASK 0x3u
#define ENET_MTL_FPE_CTRL_STS_AFSZ_SHIFT 0u
#define ENET_MTL_FPE_CTRL_STS_AFSZ_WIDTH 2u
#define ENET_MTL_FPE_CTRL_STS_AFSZ(x)  (((uint32_t)(((uint32_t)(x))<<ENET_MTL_FPE_CTRL_STS_AFSZ_SHIFT))&ENET_MTL_FPE_CTRL_STS_AFSZ_MASK)
/* MTL_FPE_CTRL_STS Reg Mask */
#define ENET_MTL_FPE_CTRL_STS_MASK     0x10000303u

/* MTL_FPE_ADVANCE Bit Fields */
#define ENET_MTL_FPE_ADVANCE_RADV_MASK 0xFFFF0000u
#define ENET_MTL_FPE_ADVANCE_RADV_SHIFT 16u
#define ENET_MTL_FPE_ADVANCE_RADV_WIDTH 16u
#define ENET_MTL_FPE_ADVANCE_RADV(x)   (((uint32_t)(((uint32_t)(x))<<ENET_MTL_FPE_ADVANCE_RADV_SHIFT))&ENET_MTL_FPE_ADVANCE_RADV_MASK)
#define ENET_MTL_FPE_ADVANCE_HADV_MASK 0xFFFFu
#define ENET_MTL_FPE_ADVANCE_HADV_SHIFT 0u
#define ENET_MTL_FPE_ADVANCE_HADV_WIDTH 16u
#define ENET_MTL_FPE_ADVANCE_HADV(x)   (((uint32_t)(((uint32_t)(x))<<ENET_MTL_FPE_ADVANCE_HADV_SHIFT))&ENET_MTL_FPE_ADVANCE_HADV_MASK)
/* MTL_FPE_ADVANCE Reg Mask */
#define ENET_MTL_FPE_ADVANCE_MASK      0xFFFFFFFFu

/* MTL_RXP_CONTROL_STATUS Bit Fields */
#define ENET_MTL_RXP_CONTROL_STATUS_RXPI_MASK 0x80000000u
#define ENET_MTL_RXP_CONTROL_STATUS_RXPI_SHIFT 31u
#define ENET_MTL_RXP_CONTROL_STATUS_RXPI_WIDTH 1u
#define ENET_MTL_RXP_CONTROL_STATUS_RXPI(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_RXP_CONTROL_STATUS_RXPI_SHIFT))&ENET_MTL_RXP_CONTROL_STATUS_RXPI_MASK)
#define ENET_MTL_RXP_CONTROL_STATUS_ELIRS_MASK 0x40000000u
#define ENET_MTL_RXP_CONTROL_STATUS_ELIRS_SHIFT 30u
#define ENET_MTL_RXP_CONTROL_STATUS_ELIRS_WIDTH 1u
#define ENET_MTL_RXP_CONTROL_STATUS_ELIRS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_RXP_CONTROL_STATUS_ELIRS_SHIFT))&ENET_MTL_RXP_CONTROL_STATUS_ELIRS_MASK)
#define ENET_MTL_RXP_CONTROL_STATUS_NPE_MASK 0xFF0000u
#define ENET_MTL_RXP_CONTROL_STATUS_NPE_SHIFT 16u
#define ENET_MTL_RXP_CONTROL_STATUS_NPE_WIDTH 8u
#define ENET_MTL_RXP_CONTROL_STATUS_NPE(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_RXP_CONTROL_STATUS_NPE_SHIFT))&ENET_MTL_RXP_CONTROL_STATUS_NPE_MASK)
#define ENET_MTL_RXP_CONTROL_STATUS_NVE_MASK 0xFFu
#define ENET_MTL_RXP_CONTROL_STATUS_NVE_SHIFT 0u
#define ENET_MTL_RXP_CONTROL_STATUS_NVE_WIDTH 8u
#define ENET_MTL_RXP_CONTROL_STATUS_NVE(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_RXP_CONTROL_STATUS_NVE_SHIFT))&ENET_MTL_RXP_CONTROL_STATUS_NVE_MASK)
/* MTL_RXP_CONTROL_STATUS Reg Mask */
#define ENET_MTL_RXP_CONTROL_STATUS_MASK 0xC0FF00FFu

/* MTL_RXP_INTERRUPT_CONTROL_STATUS Bit Fields */
#define ENET_MTL_RXP_INTERRUPT_CONTROL_STATUS_PDRFIE_MASK 0x80000u
#define ENET_MTL_RXP_INTERRUPT_CONTROL_STATUS_PDRFIE_SHIFT 19u
#define ENET_MTL_RXP_INTERRUPT_CONTROL_STATUS_PDRFIE_WIDTH 1u
#define ENET_MTL_RXP_INTERRUPT_CONTROL_STATUS_PDRFIE(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_RXP_INTERRUPT_CONTROL_STATUS_PDRFIE_SHIFT))&ENET_MTL_RXP_INTERRUPT_CONTROL_STATUS_PDRFIE_MASK)
#define ENET_MTL_RXP_INTERRUPT_CONTROL_STATUS_FOOVIE_MASK 0x40000u
#define ENET_MTL_RXP_INTERRUPT_CONTROL_STATUS_FOOVIE_SHIFT 18u
#define ENET_MTL_RXP_INTERRUPT_CONTROL_STATUS_FOOVIE_WIDTH 1u
#define ENET_MTL_RXP_INTERRUPT_CONTROL_STATUS_FOOVIE(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_RXP_INTERRUPT_CONTROL_STATUS_FOOVIE_SHIFT))&ENET_MTL_RXP_INTERRUPT_CONTROL_STATUS_FOOVIE_MASK)
#define ENET_MTL_RXP_INTERRUPT_CONTROL_STATUS_NPEOVIE_MASK 0x20000u
#define ENET_MTL_RXP_INTERRUPT_CONTROL_STATUS_NPEOVIE_SHIFT 17u
#define ENET_MTL_RXP_INTERRUPT_CONTROL_STATUS_NPEOVIE_WIDTH 1u
#define ENET_MTL_RXP_INTERRUPT_CONTROL_STATUS_NPEOVIE(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_RXP_INTERRUPT_CONTROL_STATUS_NPEOVIE_SHIFT))&ENET_MTL_RXP_INTERRUPT_CONTROL_STATUS_NPEOVIE_MASK)
#define ENET_MTL_RXP_INTERRUPT_CONTROL_STATUS_NVEOVIE_MASK 0x10000u
#define ENET_MTL_RXP_INTERRUPT_CONTROL_STATUS_NVEOVIE_SHIFT 16u
#define ENET_MTL_RXP_INTERRUPT_CONTROL_STATUS_NVEOVIE_WIDTH 1u
#define ENET_MTL_RXP_INTERRUPT_CONTROL_STATUS_NVEOVIE(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_RXP_INTERRUPT_CONTROL_STATUS_NVEOVIE_SHIFT))&ENET_MTL_RXP_INTERRUPT_CONTROL_STATUS_NVEOVIE_MASK)
#define ENET_MTL_RXP_INTERRUPT_CONTROL_STATUS_PDRFIS_MASK 0x8u
#define ENET_MTL_RXP_INTERRUPT_CONTROL_STATUS_PDRFIS_SHIFT 3u
#define ENET_MTL_RXP_INTERRUPT_CONTROL_STATUS_PDRFIS_WIDTH 1u
#define ENET_MTL_RXP_INTERRUPT_CONTROL_STATUS_PDRFIS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_RXP_INTERRUPT_CONTROL_STATUS_PDRFIS_SHIFT))&ENET_MTL_RXP_INTERRUPT_CONTROL_STATUS_PDRFIS_MASK)
#define ENET_MTL_RXP_INTERRUPT_CONTROL_STATUS_FOOVIS_MASK 0x4u
#define ENET_MTL_RXP_INTERRUPT_CONTROL_STATUS_FOOVIS_SHIFT 2u
#define ENET_MTL_RXP_INTERRUPT_CONTROL_STATUS_FOOVIS_WIDTH 1u
#define ENET_MTL_RXP_INTERRUPT_CONTROL_STATUS_FOOVIS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_RXP_INTERRUPT_CONTROL_STATUS_FOOVIS_SHIFT))&ENET_MTL_RXP_INTERRUPT_CONTROL_STATUS_FOOVIS_MASK)
#define ENET_MTL_RXP_INTERRUPT_CONTROL_STATUS_NPEOVIS_MASK 0x2u
#define ENET_MTL_RXP_INTERRUPT_CONTROL_STATUS_NPEOVIS_SHIFT 1u
#define ENET_MTL_RXP_INTERRUPT_CONTROL_STATUS_NPEOVIS_WIDTH 1u
#define ENET_MTL_RXP_INTERRUPT_CONTROL_STATUS_NPEOVIS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_RXP_INTERRUPT_CONTROL_STATUS_NPEOVIS_SHIFT))&ENET_MTL_RXP_INTERRUPT_CONTROL_STATUS_NPEOVIS_MASK)
#define ENET_MTL_RXP_INTERRUPT_CONTROL_STATUS_NVEOVIS_MASK 0x1u
#define ENET_MTL_RXP_INTERRUPT_CONTROL_STATUS_NVEOVIS_SHIFT 0u
#define ENET_MTL_RXP_INTERRUPT_CONTROL_STATUS_NVEOVIS_WIDTH 1u
#define ENET_MTL_RXP_INTERRUPT_CONTROL_STATUS_NVEOVIS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_RXP_INTERRUPT_CONTROL_STATUS_NVEOVIS_SHIFT))&ENET_MTL_RXP_INTERRUPT_CONTROL_STATUS_NVEOVIS_MASK)
/* MTL_RXP_INTERRUPT_CONTROL_STATUS Reg Mask */
#define ENET_MTL_RXP_INTERRUPT_CONTROL_STATUS_MASK 0x000F000Fu

/* MTL_RXP_DROP_CNT Bit Fields */
#define ENET_MTL_RXP_DROP_CNT_RXPDCOVF_MASK 0x80000000u
#define ENET_MTL_RXP_DROP_CNT_RXPDCOVF_SHIFT 31u
#define ENET_MTL_RXP_DROP_CNT_RXPDCOVF_WIDTH 1u
#define ENET_MTL_RXP_DROP_CNT_RXPDCOVF(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_RXP_DROP_CNT_RXPDCOVF_SHIFT))&ENET_MTL_RXP_DROP_CNT_RXPDCOVF_MASK)
#define ENET_MTL_RXP_DROP_CNT_RXPDC_MASK 0x7FFFFFFFu
#define ENET_MTL_RXP_DROP_CNT_RXPDC_SHIFT 0u
#define ENET_MTL_RXP_DROP_CNT_RXPDC_WIDTH 31u
#define ENET_MTL_RXP_DROP_CNT_RXPDC(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_RXP_DROP_CNT_RXPDC_SHIFT))&ENET_MTL_RXP_DROP_CNT_RXPDC_MASK)
/* MTL_RXP_DROP_CNT Reg Mask */
#define ENET_MTL_RXP_DROP_CNT_MASK     0xFFFFFFFFu

/* MTL_RXP_ERROR_CNT Bit Fields */
#define ENET_MTL_RXP_ERROR_CNT_RXPECOVF_MASK 0x80000000u
#define ENET_MTL_RXP_ERROR_CNT_RXPECOVF_SHIFT 31u
#define ENET_MTL_RXP_ERROR_CNT_RXPECOVF_WIDTH 1u
#define ENET_MTL_RXP_ERROR_CNT_RXPECOVF(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_RXP_ERROR_CNT_RXPECOVF_SHIFT))&ENET_MTL_RXP_ERROR_CNT_RXPECOVF_MASK)
#define ENET_MTL_RXP_ERROR_CNT_RXPEC_MASK 0x7FFFFFFFu
#define ENET_MTL_RXP_ERROR_CNT_RXPEC_SHIFT 0u
#define ENET_MTL_RXP_ERROR_CNT_RXPEC_WIDTH 31u
#define ENET_MTL_RXP_ERROR_CNT_RXPEC(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_RXP_ERROR_CNT_RXPEC_SHIFT))&ENET_MTL_RXP_ERROR_CNT_RXPEC_MASK)
/* MTL_RXP_ERROR_CNT Reg Mask */
#define ENET_MTL_RXP_ERROR_CNT_MASK    0xFFFFFFFFu

/* MTL_RXP_INDIRECT_ACC_CONTROL_STATUS Bit Fields */
#define ENET_MTL_RXP_INDIRECT_ACC_CONTROL_STATUS_STARTBUSY_MASK 0x80000000u
#define ENET_MTL_RXP_INDIRECT_ACC_CONTROL_STATUS_STARTBUSY_SHIFT 31u
#define ENET_MTL_RXP_INDIRECT_ACC_CONTROL_STATUS_STARTBUSY_WIDTH 1u
#define ENET_MTL_RXP_INDIRECT_ACC_CONTROL_STATUS_STARTBUSY(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_RXP_INDIRECT_ACC_CONTROL_STATUS_STARTBUSY_SHIFT))&ENET_MTL_RXP_INDIRECT_ACC_CONTROL_STATUS_STARTBUSY_MASK)
#define ENET_MTL_RXP_INDIRECT_ACC_CONTROL_STATUS_RXPEIEC_MASK 0x400000u
#define ENET_MTL_RXP_INDIRECT_ACC_CONTROL_STATUS_RXPEIEC_SHIFT 22u
#define ENET_MTL_RXP_INDIRECT_ACC_CONTROL_STATUS_RXPEIEC_WIDTH 1u
#define ENET_MTL_RXP_INDIRECT_ACC_CONTROL_STATUS_RXPEIEC(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_RXP_INDIRECT_ACC_CONTROL_STATUS_RXPEIEC_SHIFT))&ENET_MTL_RXP_INDIRECT_ACC_CONTROL_STATUS_RXPEIEC_MASK)
#define ENET_MTL_RXP_INDIRECT_ACC_CONTROL_STATUS_RXPEIAEE_MASK 0x200000u
#define ENET_MTL_RXP_INDIRECT_ACC_CONTROL_STATUS_RXPEIAEE_SHIFT 21u
#define ENET_MTL_RXP_INDIRECT_ACC_CONTROL_STATUS_RXPEIAEE_WIDTH 1u
#define ENET_MTL_RXP_INDIRECT_ACC_CONTROL_STATUS_RXPEIAEE(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_RXP_INDIRECT_ACC_CONTROL_STATUS_RXPEIAEE_SHIFT))&ENET_MTL_RXP_INDIRECT_ACC_CONTROL_STATUS_RXPEIAEE_MASK)
#define ENET_MTL_RXP_INDIRECT_ACC_CONTROL_STATUS_RXPEIEE_MASK 0x100000u
#define ENET_MTL_RXP_INDIRECT_ACC_CONTROL_STATUS_RXPEIEE_SHIFT 20u
#define ENET_MTL_RXP_INDIRECT_ACC_CONTROL_STATUS_RXPEIEE_WIDTH 1u
#define ENET_MTL_RXP_INDIRECT_ACC_CONTROL_STATUS_RXPEIEE(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_RXP_INDIRECT_ACC_CONTROL_STATUS_RXPEIEE_SHIFT))&ENET_MTL_RXP_INDIRECT_ACC_CONTROL_STATUS_RXPEIEE_MASK)
#define ENET_MTL_RXP_INDIRECT_ACC_CONTROL_STATUS_WRRDN_MASK 0x10000u
#define ENET_MTL_RXP_INDIRECT_ACC_CONTROL_STATUS_WRRDN_SHIFT 16u
#define ENET_MTL_RXP_INDIRECT_ACC_CONTROL_STATUS_WRRDN_WIDTH 1u
#define ENET_MTL_RXP_INDIRECT_ACC_CONTROL_STATUS_WRRDN(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_RXP_INDIRECT_ACC_CONTROL_STATUS_WRRDN_SHIFT))&ENET_MTL_RXP_INDIRECT_ACC_CONTROL_STATUS_WRRDN_MASK)
#define ENET_MTL_RXP_INDIRECT_ACC_CONTROL_STATUS_ADDR_MASK 0xFFu
#define ENET_MTL_RXP_INDIRECT_ACC_CONTROL_STATUS_ADDR_SHIFT 0u
#define ENET_MTL_RXP_INDIRECT_ACC_CONTROL_STATUS_ADDR_WIDTH 8u
#define ENET_MTL_RXP_INDIRECT_ACC_CONTROL_STATUS_ADDR(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_RXP_INDIRECT_ACC_CONTROL_STATUS_ADDR_SHIFT))&ENET_MTL_RXP_INDIRECT_ACC_CONTROL_STATUS_ADDR_MASK)
/* MTL_RXP_INDIRECT_ACC_CONTROL_STATUS Reg Mask */
#define ENET_MTL_RXP_INDIRECT_ACC_CONTROL_STATUS_MASK 0x807100FFu

/* MTL_RXP_INDIRECT_ACC_DATA Bit Fields */
#define ENET_MTL_RXP_INDIRECT_ACC_DATA_DATA_MASK 0xFFFFFFFFu
#define ENET_MTL_RXP_INDIRECT_ACC_DATA_DATA_SHIFT 0u
#define ENET_MTL_RXP_INDIRECT_ACC_DATA_DATA_WIDTH 32u
#define ENET_MTL_RXP_INDIRECT_ACC_DATA_DATA(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_RXP_INDIRECT_ACC_DATA_DATA_SHIFT))&ENET_MTL_RXP_INDIRECT_ACC_DATA_DATA_MASK)
/* MTL_RXP_INDIRECT_ACC_DATA Reg Mask */
#define ENET_MTL_RXP_INDIRECT_ACC_DATA_MASK 0xFFFFFFFFu

/* MTL_RXP_BYPASS_CNT Bit Fields */
#define ENET_MTL_RXP_BYPASS_CNT_RXPBCOF_MASK 0x80000000u
#define ENET_MTL_RXP_BYPASS_CNT_RXPBCOF_SHIFT 31u
#define ENET_MTL_RXP_BYPASS_CNT_RXPBCOF_WIDTH 1u
#define ENET_MTL_RXP_BYPASS_CNT_RXPBCOF(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_RXP_BYPASS_CNT_RXPBCOF_SHIFT))&ENET_MTL_RXP_BYPASS_CNT_RXPBCOF_MASK)
#define ENET_MTL_RXP_BYPASS_CNT_RXPBC_MASK 0x7FFFFFFFu
#define ENET_MTL_RXP_BYPASS_CNT_RXPBC_SHIFT 0u
#define ENET_MTL_RXP_BYPASS_CNT_RXPBC_WIDTH 31u
#define ENET_MTL_RXP_BYPASS_CNT_RXPBC(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_RXP_BYPASS_CNT_RXPBC_SHIFT))&ENET_MTL_RXP_BYPASS_CNT_RXPBC_MASK)
/* MTL_RXP_BYPASS_CNT Reg Mask */
#define ENET_MTL_RXP_BYPASS_CNT_MASK   0xFFFFFFFFu

/* MTL_ECC_CONTROL Bit Fields */
#define ENET_MTL_ECC_CONTROL_MEEAO_MASK 0x100u
#define ENET_MTL_ECC_CONTROL_MEEAO_SHIFT 8u
#define ENET_MTL_ECC_CONTROL_MEEAO_WIDTH 1u
#define ENET_MTL_ECC_CONTROL_MEEAO(x)  (((uint32_t)(((uint32_t)(x))<<ENET_MTL_ECC_CONTROL_MEEAO_SHIFT))&ENET_MTL_ECC_CONTROL_MEEAO_MASK)
#define ENET_MTL_ECC_CONTROL_MRXPEE_MASK 0x8u
#define ENET_MTL_ECC_CONTROL_MRXPEE_SHIFT 3u
#define ENET_MTL_ECC_CONTROL_MRXPEE_WIDTH 1u
#define ENET_MTL_ECC_CONTROL_MRXPEE(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_ECC_CONTROL_MRXPEE_SHIFT))&ENET_MTL_ECC_CONTROL_MRXPEE_MASK)
#define ENET_MTL_ECC_CONTROL_MESTEE_MASK 0x4u
#define ENET_MTL_ECC_CONTROL_MESTEE_SHIFT 2u
#define ENET_MTL_ECC_CONTROL_MESTEE_WIDTH 1u
#define ENET_MTL_ECC_CONTROL_MESTEE(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_ECC_CONTROL_MESTEE_SHIFT))&ENET_MTL_ECC_CONTROL_MESTEE_MASK)
#define ENET_MTL_ECC_CONTROL_MRXEE_MASK 0x2u
#define ENET_MTL_ECC_CONTROL_MRXEE_SHIFT 1u
#define ENET_MTL_ECC_CONTROL_MRXEE_WIDTH 1u
#define ENET_MTL_ECC_CONTROL_MRXEE(x)  (((uint32_t)(((uint32_t)(x))<<ENET_MTL_ECC_CONTROL_MRXEE_SHIFT))&ENET_MTL_ECC_CONTROL_MRXEE_MASK)
#define ENET_MTL_ECC_CONTROL_MTXEE_MASK 0x1u
#define ENET_MTL_ECC_CONTROL_MTXEE_SHIFT 0u
#define ENET_MTL_ECC_CONTROL_MTXEE_WIDTH 1u
#define ENET_MTL_ECC_CONTROL_MTXEE(x)  (((uint32_t)(((uint32_t)(x))<<ENET_MTL_ECC_CONTROL_MTXEE_SHIFT))&ENET_MTL_ECC_CONTROL_MTXEE_MASK)
/* MTL_ECC_CONTROL Reg Mask */
#define ENET_MTL_ECC_CONTROL_MASK      0x0000010Fu

/* MTL_SAFETY_INTERRUPT_STATUS Bit Fields */
#define ENET_MTL_SAFETY_INTERRUPT_STATUS_MEUIS_MASK 0x2u
#define ENET_MTL_SAFETY_INTERRUPT_STATUS_MEUIS_SHIFT 1u
#define ENET_MTL_SAFETY_INTERRUPT_STATUS_MEUIS_WIDTH 1u
#define ENET_MTL_SAFETY_INTERRUPT_STATUS_MEUIS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_SAFETY_INTERRUPT_STATUS_MEUIS_SHIFT))&ENET_MTL_SAFETY_INTERRUPT_STATUS_MEUIS_MASK)
#define ENET_MTL_SAFETY_INTERRUPT_STATUS_MECIS_MASK 0x1u
#define ENET_MTL_SAFETY_INTERRUPT_STATUS_MECIS_SHIFT 0u
#define ENET_MTL_SAFETY_INTERRUPT_STATUS_MECIS_WIDTH 1u
#define ENET_MTL_SAFETY_INTERRUPT_STATUS_MECIS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_SAFETY_INTERRUPT_STATUS_MECIS_SHIFT))&ENET_MTL_SAFETY_INTERRUPT_STATUS_MECIS_MASK)
/* MTL_SAFETY_INTERRUPT_STATUS Reg Mask */
#define ENET_MTL_SAFETY_INTERRUPT_STATUS_MASK 0x00000003u

/* MTL_ECC_INTERRUPT_ENABLE Bit Fields */
#define ENET_MTL_ECC_INTERRUPT_ENABLE_RPCEIE_MASK 0x1000u
#define ENET_MTL_ECC_INTERRUPT_ENABLE_RPCEIE_SHIFT 12u
#define ENET_MTL_ECC_INTERRUPT_ENABLE_RPCEIE_WIDTH 1u
#define ENET_MTL_ECC_INTERRUPT_ENABLE_RPCEIE(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_ECC_INTERRUPT_ENABLE_RPCEIE_SHIFT))&ENET_MTL_ECC_INTERRUPT_ENABLE_RPCEIE_MASK)
#define ENET_MTL_ECC_INTERRUPT_ENABLE_ECEIE_MASK 0x100u
#define ENET_MTL_ECC_INTERRUPT_ENABLE_ECEIE_SHIFT 8u
#define ENET_MTL_ECC_INTERRUPT_ENABLE_ECEIE_WIDTH 1u
#define ENET_MTL_ECC_INTERRUPT_ENABLE_ECEIE(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_ECC_INTERRUPT_ENABLE_ECEIE_SHIFT))&ENET_MTL_ECC_INTERRUPT_ENABLE_ECEIE_MASK)
#define ENET_MTL_ECC_INTERRUPT_ENABLE_RXCEIE_MASK 0x10u
#define ENET_MTL_ECC_INTERRUPT_ENABLE_RXCEIE_SHIFT 4u
#define ENET_MTL_ECC_INTERRUPT_ENABLE_RXCEIE_WIDTH 1u
#define ENET_MTL_ECC_INTERRUPT_ENABLE_RXCEIE(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_ECC_INTERRUPT_ENABLE_RXCEIE_SHIFT))&ENET_MTL_ECC_INTERRUPT_ENABLE_RXCEIE_MASK)
#define ENET_MTL_ECC_INTERRUPT_ENABLE_TXCEIE_MASK 0x1u
#define ENET_MTL_ECC_INTERRUPT_ENABLE_TXCEIE_SHIFT 0u
#define ENET_MTL_ECC_INTERRUPT_ENABLE_TXCEIE_WIDTH 1u
#define ENET_MTL_ECC_INTERRUPT_ENABLE_TXCEIE(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_ECC_INTERRUPT_ENABLE_TXCEIE_SHIFT))&ENET_MTL_ECC_INTERRUPT_ENABLE_TXCEIE_MASK)
/* MTL_ECC_INTERRUPT_ENABLE Reg Mask */
#define ENET_MTL_ECC_INTERRUPT_ENABLE_MASK 0x00001111u

/* MTL_ECC_INTERRUPT_STATUS Bit Fields */
#define ENET_MTL_ECC_INTERRUPT_STATUS_RPUES_MASK 0x4000u
#define ENET_MTL_ECC_INTERRUPT_STATUS_RPUES_SHIFT 14u
#define ENET_MTL_ECC_INTERRUPT_STATUS_RPUES_WIDTH 1u
#define ENET_MTL_ECC_INTERRUPT_STATUS_RPUES(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_ECC_INTERRUPT_STATUS_RPUES_SHIFT))&ENET_MTL_ECC_INTERRUPT_STATUS_RPUES_MASK)
#define ENET_MTL_ECC_INTERRUPT_STATUS_RPAMS_MASK 0x2000u
#define ENET_MTL_ECC_INTERRUPT_STATUS_RPAMS_SHIFT 13u
#define ENET_MTL_ECC_INTERRUPT_STATUS_RPAMS_WIDTH 1u
#define ENET_MTL_ECC_INTERRUPT_STATUS_RPAMS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_ECC_INTERRUPT_STATUS_RPAMS_SHIFT))&ENET_MTL_ECC_INTERRUPT_STATUS_RPAMS_MASK)
#define ENET_MTL_ECC_INTERRUPT_STATUS_RPCES_MASK 0x1000u
#define ENET_MTL_ECC_INTERRUPT_STATUS_RPCES_SHIFT 12u
#define ENET_MTL_ECC_INTERRUPT_STATUS_RPCES_WIDTH 1u
#define ENET_MTL_ECC_INTERRUPT_STATUS_RPCES(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_ECC_INTERRUPT_STATUS_RPCES_SHIFT))&ENET_MTL_ECC_INTERRUPT_STATUS_RPCES_MASK)
#define ENET_MTL_ECC_INTERRUPT_STATUS_EUES_MASK 0x400u
#define ENET_MTL_ECC_INTERRUPT_STATUS_EUES_SHIFT 10u
#define ENET_MTL_ECC_INTERRUPT_STATUS_EUES_WIDTH 1u
#define ENET_MTL_ECC_INTERRUPT_STATUS_EUES(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_ECC_INTERRUPT_STATUS_EUES_SHIFT))&ENET_MTL_ECC_INTERRUPT_STATUS_EUES_MASK)
#define ENET_MTL_ECC_INTERRUPT_STATUS_EAMS_MASK 0x200u
#define ENET_MTL_ECC_INTERRUPT_STATUS_EAMS_SHIFT 9u
#define ENET_MTL_ECC_INTERRUPT_STATUS_EAMS_WIDTH 1u
#define ENET_MTL_ECC_INTERRUPT_STATUS_EAMS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_ECC_INTERRUPT_STATUS_EAMS_SHIFT))&ENET_MTL_ECC_INTERRUPT_STATUS_EAMS_MASK)
#define ENET_MTL_ECC_INTERRUPT_STATUS_ECES_MASK 0x100u
#define ENET_MTL_ECC_INTERRUPT_STATUS_ECES_SHIFT 8u
#define ENET_MTL_ECC_INTERRUPT_STATUS_ECES_WIDTH 1u
#define ENET_MTL_ECC_INTERRUPT_STATUS_ECES(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_ECC_INTERRUPT_STATUS_ECES_SHIFT))&ENET_MTL_ECC_INTERRUPT_STATUS_ECES_MASK)
#define ENET_MTL_ECC_INTERRUPT_STATUS_RXUES_MASK 0x40u
#define ENET_MTL_ECC_INTERRUPT_STATUS_RXUES_SHIFT 6u
#define ENET_MTL_ECC_INTERRUPT_STATUS_RXUES_WIDTH 1u
#define ENET_MTL_ECC_INTERRUPT_STATUS_RXUES(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_ECC_INTERRUPT_STATUS_RXUES_SHIFT))&ENET_MTL_ECC_INTERRUPT_STATUS_RXUES_MASK)
#define ENET_MTL_ECC_INTERRUPT_STATUS_RXAMS_MASK 0x20u
#define ENET_MTL_ECC_INTERRUPT_STATUS_RXAMS_SHIFT 5u
#define ENET_MTL_ECC_INTERRUPT_STATUS_RXAMS_WIDTH 1u
#define ENET_MTL_ECC_INTERRUPT_STATUS_RXAMS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_ECC_INTERRUPT_STATUS_RXAMS_SHIFT))&ENET_MTL_ECC_INTERRUPT_STATUS_RXAMS_MASK)
#define ENET_MTL_ECC_INTERRUPT_STATUS_RXCES_MASK 0x10u
#define ENET_MTL_ECC_INTERRUPT_STATUS_RXCES_SHIFT 4u
#define ENET_MTL_ECC_INTERRUPT_STATUS_RXCES_WIDTH 1u
#define ENET_MTL_ECC_INTERRUPT_STATUS_RXCES(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_ECC_INTERRUPT_STATUS_RXCES_SHIFT))&ENET_MTL_ECC_INTERRUPT_STATUS_RXCES_MASK)
#define ENET_MTL_ECC_INTERRUPT_STATUS_TXUES_MASK 0x4u
#define ENET_MTL_ECC_INTERRUPT_STATUS_TXUES_SHIFT 2u
#define ENET_MTL_ECC_INTERRUPT_STATUS_TXUES_WIDTH 1u
#define ENET_MTL_ECC_INTERRUPT_STATUS_TXUES(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_ECC_INTERRUPT_STATUS_TXUES_SHIFT))&ENET_MTL_ECC_INTERRUPT_STATUS_TXUES_MASK)
#define ENET_MTL_ECC_INTERRUPT_STATUS_TXAMS_MASK 0x2u
#define ENET_MTL_ECC_INTERRUPT_STATUS_TXAMS_SHIFT 1u
#define ENET_MTL_ECC_INTERRUPT_STATUS_TXAMS_WIDTH 1u
#define ENET_MTL_ECC_INTERRUPT_STATUS_TXAMS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_ECC_INTERRUPT_STATUS_TXAMS_SHIFT))&ENET_MTL_ECC_INTERRUPT_STATUS_TXAMS_MASK)
#define ENET_MTL_ECC_INTERRUPT_STATUS_TXCES_MASK 0x1u
#define ENET_MTL_ECC_INTERRUPT_STATUS_TXCES_SHIFT 0u
#define ENET_MTL_ECC_INTERRUPT_STATUS_TXCES_WIDTH 1u
#define ENET_MTL_ECC_INTERRUPT_STATUS_TXCES(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_ECC_INTERRUPT_STATUS_TXCES_SHIFT))&ENET_MTL_ECC_INTERRUPT_STATUS_TXCES_MASK)
/* MTL_ECC_INTERRUPT_STATUS Reg Mask */
#define ENET_MTL_ECC_INTERRUPT_STATUS_MASK 0x00007777u

/* MTL_ECC_ERR_STS_RCTL Bit Fields */
#define ENET_MTL_ECC_ERR_STS_RCTL_CUES_MASK 0x20u
#define ENET_MTL_ECC_ERR_STS_RCTL_CUES_SHIFT 5u
#define ENET_MTL_ECC_ERR_STS_RCTL_CUES_WIDTH 1u
#define ENET_MTL_ECC_ERR_STS_RCTL_CUES(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_ECC_ERR_STS_RCTL_CUES_SHIFT))&ENET_MTL_ECC_ERR_STS_RCTL_CUES_MASK)
#define ENET_MTL_ECC_ERR_STS_RCTL_CCES_MASK 0x10u
#define ENET_MTL_ECC_ERR_STS_RCTL_CCES_SHIFT 4u
#define ENET_MTL_ECC_ERR_STS_RCTL_CCES_WIDTH 1u
#define ENET_MTL_ECC_ERR_STS_RCTL_CCES(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_ECC_ERR_STS_RCTL_CCES_SHIFT))&ENET_MTL_ECC_ERR_STS_RCTL_CCES_MASK)
#define ENET_MTL_ECC_ERR_STS_RCTL_EMS_MASK 0xEu
#define ENET_MTL_ECC_ERR_STS_RCTL_EMS_SHIFT 1u
#define ENET_MTL_ECC_ERR_STS_RCTL_EMS_WIDTH 3u
#define ENET_MTL_ECC_ERR_STS_RCTL_EMS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_ECC_ERR_STS_RCTL_EMS_SHIFT))&ENET_MTL_ECC_ERR_STS_RCTL_EMS_MASK)
#define ENET_MTL_ECC_ERR_STS_RCTL_EESRE_MASK 0x1u
#define ENET_MTL_ECC_ERR_STS_RCTL_EESRE_SHIFT 0u
#define ENET_MTL_ECC_ERR_STS_RCTL_EESRE_WIDTH 1u
#define ENET_MTL_ECC_ERR_STS_RCTL_EESRE(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_ECC_ERR_STS_RCTL_EESRE_SHIFT))&ENET_MTL_ECC_ERR_STS_RCTL_EESRE_MASK)
/* MTL_ECC_ERR_STS_RCTL Reg Mask */
#define ENET_MTL_ECC_ERR_STS_RCTL_MASK 0x0000003Fu

/* MTL_ECC_ERR_ADDR_STATUS Bit Fields */
#define ENET_MTL_ECC_ERR_ADDR_STATUS_EUEAS_MASK 0xFFFF0000u
#define ENET_MTL_ECC_ERR_ADDR_STATUS_EUEAS_SHIFT 16u
#define ENET_MTL_ECC_ERR_ADDR_STATUS_EUEAS_WIDTH 16u
#define ENET_MTL_ECC_ERR_ADDR_STATUS_EUEAS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_ECC_ERR_ADDR_STATUS_EUEAS_SHIFT))&ENET_MTL_ECC_ERR_ADDR_STATUS_EUEAS_MASK)
#define ENET_MTL_ECC_ERR_ADDR_STATUS_ECEAS_MASK 0xFFFFu
#define ENET_MTL_ECC_ERR_ADDR_STATUS_ECEAS_SHIFT 0u
#define ENET_MTL_ECC_ERR_ADDR_STATUS_ECEAS_WIDTH 16u
#define ENET_MTL_ECC_ERR_ADDR_STATUS_ECEAS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_ECC_ERR_ADDR_STATUS_ECEAS_SHIFT))&ENET_MTL_ECC_ERR_ADDR_STATUS_ECEAS_MASK)
/* MTL_ECC_ERR_ADDR_STATUS Reg Mask */
#define ENET_MTL_ECC_ERR_ADDR_STATUS_MASK 0xFFFFFFFFu

/* MTL_ECC_ERR_CNTR_STATUS Bit Fields */
#define ENET_MTL_ECC_ERR_CNTR_STATUS_EUECS_MASK 0xF0000u
#define ENET_MTL_ECC_ERR_CNTR_STATUS_EUECS_SHIFT 16u
#define ENET_MTL_ECC_ERR_CNTR_STATUS_EUECS_WIDTH 4u
#define ENET_MTL_ECC_ERR_CNTR_STATUS_EUECS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_ECC_ERR_CNTR_STATUS_EUECS_SHIFT))&ENET_MTL_ECC_ERR_CNTR_STATUS_EUECS_MASK)
#define ENET_MTL_ECC_ERR_CNTR_STATUS_ECECS_MASK 0xFFu
#define ENET_MTL_ECC_ERR_CNTR_STATUS_ECECS_SHIFT 0u
#define ENET_MTL_ECC_ERR_CNTR_STATUS_ECECS_WIDTH 8u
#define ENET_MTL_ECC_ERR_CNTR_STATUS_ECECS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_ECC_ERR_CNTR_STATUS_ECECS_SHIFT))&ENET_MTL_ECC_ERR_CNTR_STATUS_ECECS_MASK)
/* MTL_ECC_ERR_CNTR_STATUS Reg Mask */
#define ENET_MTL_ECC_ERR_CNTR_STATUS_MASK 0x000F00FFu

/* MTL_DPP_CONTROL Bit Fields */
#define ENET_MTL_DPP_CONTROL_IPEMRWC_MASK 0x8000u
#define ENET_MTL_DPP_CONTROL_IPEMRWC_SHIFT 15u
#define ENET_MTL_DPP_CONTROL_IPEMRWC_WIDTH 1u
#define ENET_MTL_DPP_CONTROL_IPEMRWC(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_DPP_CONTROL_IPEMRWC_SHIFT))&ENET_MTL_DPP_CONTROL_IPEMRWC_MASK)
#define ENET_MTL_DPP_CONTROL_IPEMTFC_MASK 0x4000u
#define ENET_MTL_DPP_CONTROL_IPEMTFC_SHIFT 14u
#define ENET_MTL_DPP_CONTROL_IPEMTFC_WIDTH 1u
#define ENET_MTL_DPP_CONTROL_IPEMTFC(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_DPP_CONTROL_IPEMTFC_SHIFT))&ENET_MTL_DPP_CONTROL_IPEMTFC_MASK)
#define ENET_MTL_DPP_CONTROL_IPEMTBU_MASK 0x2000u
#define ENET_MTL_DPP_CONTROL_IPEMTBU_SHIFT 13u
#define ENET_MTL_DPP_CONTROL_IPEMTBU_WIDTH 1u
#define ENET_MTL_DPP_CONTROL_IPEMTBU(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_DPP_CONTROL_IPEMTBU_SHIFT))&ENET_MTL_DPP_CONTROL_IPEMTBU_MASK)
#define ENET_MTL_DPP_CONTROL_IPERID_MASK 0x200u
#define ENET_MTL_DPP_CONTROL_IPERID_SHIFT 9u
#define ENET_MTL_DPP_CONTROL_IPERID_WIDTH 1u
#define ENET_MTL_DPP_CONTROL_IPERID(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_DPP_CONTROL_IPERID_SHIFT))&ENET_MTL_DPP_CONTROL_IPERID_MASK)
#define ENET_MTL_DPP_CONTROL_IPEMTS_MASK 0x100u
#define ENET_MTL_DPP_CONTROL_IPEMTS_SHIFT 8u
#define ENET_MTL_DPP_CONTROL_IPEMTS_WIDTH 1u
#define ENET_MTL_DPP_CONTROL_IPEMTS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_DPP_CONTROL_IPEMTS_SHIFT))&ENET_MTL_DPP_CONTROL_IPEMTS_MASK)
#define ENET_MTL_DPP_CONTROL_IPEMTF_MASK 0x80u
#define ENET_MTL_DPP_CONTROL_IPEMTF_SHIFT 7u
#define ENET_MTL_DPP_CONTROL_IPEMTF_WIDTH 1u
#define ENET_MTL_DPP_CONTROL_IPEMTF(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_DPP_CONTROL_IPEMTF_SHIFT))&ENET_MTL_DPP_CONTROL_IPEMTF_MASK)
#define ENET_MTL_DPP_CONTROL_IPETRD_MASK 0x40u
#define ENET_MTL_DPP_CONTROL_IPETRD_SHIFT 6u
#define ENET_MTL_DPP_CONTROL_IPETRD_WIDTH 1u
#define ENET_MTL_DPP_CONTROL_IPETRD(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_DPP_CONTROL_IPETRD_SHIFT))&ENET_MTL_DPP_CONTROL_IPETRD_MASK)
#define ENET_MTL_DPP_CONTROL_OPE_MASK  0x2u
#define ENET_MTL_DPP_CONTROL_OPE_SHIFT 1u
#define ENET_MTL_DPP_CONTROL_OPE_WIDTH 1u
#define ENET_MTL_DPP_CONTROL_OPE(x)    (((uint32_t)(((uint32_t)(x))<<ENET_MTL_DPP_CONTROL_OPE_SHIFT))&ENET_MTL_DPP_CONTROL_OPE_MASK)
#define ENET_MTL_DPP_CONTROL_EDPP_MASK 0x1u
#define ENET_MTL_DPP_CONTROL_EDPP_SHIFT 0u
#define ENET_MTL_DPP_CONTROL_EDPP_WIDTH 1u
#define ENET_MTL_DPP_CONTROL_EDPP(x)   (((uint32_t)(((uint32_t)(x))<<ENET_MTL_DPP_CONTROL_EDPP_SHIFT))&ENET_MTL_DPP_CONTROL_EDPP_MASK)
/* MTL_DPP_CONTROL Reg Mask */
#define ENET_MTL_DPP_CONTROL_MASK      0x0000E3C3u

/* MTL_DPP_ECC_EIC Bit Fields */
#define ENET_MTL_DPP_ECC_EIC_EIM_MASK  0x10000u
#define ENET_MTL_DPP_ECC_EIC_EIM_SHIFT 16u
#define ENET_MTL_DPP_ECC_EIC_EIM_WIDTH 1u
#define ENET_MTL_DPP_ECC_EIC_EIM(x)    (((uint32_t)(((uint32_t)(x))<<ENET_MTL_DPP_ECC_EIC_EIM_SHIFT))&ENET_MTL_DPP_ECC_EIC_EIM_MASK)
#define ENET_MTL_DPP_ECC_EIC_BLEI_MASK 0xFFu
#define ENET_MTL_DPP_ECC_EIC_BLEI_SHIFT 0u
#define ENET_MTL_DPP_ECC_EIC_BLEI_WIDTH 8u
#define ENET_MTL_DPP_ECC_EIC_BLEI(x)   (((uint32_t)(((uint32_t)(x))<<ENET_MTL_DPP_ECC_EIC_BLEI_SHIFT))&ENET_MTL_DPP_ECC_EIC_BLEI_MASK)
/* MTL_DPP_ECC_EIC Reg Mask */
#define ENET_MTL_DPP_ECC_EIC_MASK      0x000100FFu

/* MTL_TXQn_OPERATION_MODE Bit Fields */
#define ENET_MTL_TXQn_OPERATION_MODE_TQS_MASK 0x1F0000u
#define ENET_MTL_TXQn_OPERATION_MODE_TQS_SHIFT 16u
#define ENET_MTL_TXQn_OPERATION_MODE_TQS_WIDTH 5u
#define ENET_MTL_TXQn_OPERATION_MODE_TQS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_TXQn_OPERATION_MODE_TQS_SHIFT))&ENET_MTL_TXQn_OPERATION_MODE_TQS_MASK)
#define ENET_MTL_TXQn_OPERATION_MODE_TTC_MASK 0x70u
#define ENET_MTL_TXQn_OPERATION_MODE_TTC_SHIFT 4u
#define ENET_MTL_TXQn_OPERATION_MODE_TTC_WIDTH 3u
#define ENET_MTL_TXQn_OPERATION_MODE_TTC(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_TXQn_OPERATION_MODE_TTC_SHIFT))&ENET_MTL_TXQn_OPERATION_MODE_TTC_MASK)
#define ENET_MTL_TXQn_OPERATION_MODE_TXQEN_MASK 0xCu
#define ENET_MTL_TXQn_OPERATION_MODE_TXQEN_SHIFT 2u
#define ENET_MTL_TXQn_OPERATION_MODE_TXQEN_WIDTH 2u
#define ENET_MTL_TXQn_OPERATION_MODE_TXQEN(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_TXQn_OPERATION_MODE_TXQEN_SHIFT))&ENET_MTL_TXQn_OPERATION_MODE_TXQEN_MASK)
#define ENET_MTL_TXQn_OPERATION_MODE_TSF_MASK 0x2u
#define ENET_MTL_TXQn_OPERATION_MODE_TSF_SHIFT 1u
#define ENET_MTL_TXQn_OPERATION_MODE_TSF_WIDTH 1u
#define ENET_MTL_TXQn_OPERATION_MODE_TSF(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_TXQn_OPERATION_MODE_TSF_SHIFT))&ENET_MTL_TXQn_OPERATION_MODE_TSF_MASK)
#define ENET_MTL_TXQn_OPERATION_MODE_FTQ_MASK 0x1u
#define ENET_MTL_TXQn_OPERATION_MODE_FTQ_SHIFT 0u
#define ENET_MTL_TXQn_OPERATION_MODE_FTQ_WIDTH 1u
#define ENET_MTL_TXQn_OPERATION_MODE_FTQ(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_TXQn_OPERATION_MODE_FTQ_SHIFT))&ENET_MTL_TXQn_OPERATION_MODE_FTQ_MASK)
/* MTL_TXQ1_OPERATION_MODE Reg Mask */
#define ENET_MTL_TXQn_OPERATION_MODE_MASK 0x001F007Fu

/* MTL_TXQn_UNDERFLOW Bit Fields */
#define ENET_MTL_TXQn_UNDERFLOW_UFCNTOVF_MASK 0x800u
#define ENET_MTL_TXQn_UNDERFLOW_UFCNTOVF_SHIFT 11u
#define ENET_MTL_TXQn_UNDERFLOW_UFCNTOVF_WIDTH 1u
#define ENET_MTL_TXQn_UNDERFLOW_UFCNTOVF(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_TXQn_UNDERFLOW_UFCNTOVF_SHIFT))&ENET_MTL_TXQn_UNDERFLOW_UFCNTOVF_MASK)
#define ENET_MTL_TXQn_UNDERFLOW_UFFRMCNT_MASK 0x7FFu
#define ENET_MTL_TXQn_UNDERFLOW_UFFRMCNT_SHIFT 0u
#define ENET_MTL_TXQn_UNDERFLOW_UFFRMCNT_WIDTH 11u
#define ENET_MTL_TXQn_UNDERFLOW_UFFRMCNT(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_TXQn_UNDERFLOW_UFFRMCNT_SHIFT))&ENET_MTL_TXQn_UNDERFLOW_UFFRMCNT_MASK)
/* MTL_TXQ1_UNDERFLOW Reg Mask */
#define ENET_MTL_TXQn_UNDERFLOW_MASK   0x00000FFFu

/* MTL_TXQn_DEBUG Bit Fields */
#define ENET_MTL_TXQn_DEBUG_STXSTSF_MASK 0x700000u
#define ENET_MTL_TXQn_DEBUG_STXSTSF_SHIFT 20u
#define ENET_MTL_TXQn_DEBUG_STXSTSF_WIDTH 3u
#define ENET_MTL_TXQn_DEBUG_STXSTSF(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_TXQn_DEBUG_STXSTSF_SHIFT))&ENET_MTL_TXQn_DEBUG_STXSTSF_MASK)
#define ENET_MTL_TXQn_DEBUG_PTXQ_MASK  0x70000u
#define ENET_MTL_TXQn_DEBUG_PTXQ_SHIFT 16u
#define ENET_MTL_TXQn_DEBUG_PTXQ_WIDTH 3u
#define ENET_MTL_TXQn_DEBUG_PTXQ(x)    (((uint32_t)(((uint32_t)(x))<<ENET_MTL_TXQn_DEBUG_PTXQ_SHIFT))&ENET_MTL_TXQn_DEBUG_PTXQ_MASK)
#define ENET_MTL_TXQn_DEBUG_TXSTSFSTS_MASK 0x20u
#define ENET_MTL_TXQn_DEBUG_TXSTSFSTS_SHIFT 5u
#define ENET_MTL_TXQn_DEBUG_TXSTSFSTS_WIDTH 1u
#define ENET_MTL_TXQn_DEBUG_TXSTSFSTS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_TXQn_DEBUG_TXSTSFSTS_SHIFT))&ENET_MTL_TXQn_DEBUG_TXSTSFSTS_MASK)
#define ENET_MTL_TXQn_DEBUG_TXQSTS_MASK 0x10u
#define ENET_MTL_TXQn_DEBUG_TXQSTS_SHIFT 4u
#define ENET_MTL_TXQn_DEBUG_TXQSTS_WIDTH 1u
#define ENET_MTL_TXQn_DEBUG_TXQSTS(x)  (((uint32_t)(((uint32_t)(x))<<ENET_MTL_TXQn_DEBUG_TXQSTS_SHIFT))&ENET_MTL_TXQn_DEBUG_TXQSTS_MASK)
#define ENET_MTL_TXQn_DEBUG_TWCSTS_MASK 0x8u
#define ENET_MTL_TXQn_DEBUG_TWCSTS_SHIFT 3u
#define ENET_MTL_TXQn_DEBUG_TWCSTS_WIDTH 1u
#define ENET_MTL_TXQn_DEBUG_TWCSTS(x)  (((uint32_t)(((uint32_t)(x))<<ENET_MTL_TXQn_DEBUG_TWCSTS_SHIFT))&ENET_MTL_TXQn_DEBUG_TWCSTS_MASK)
#define ENET_MTL_TXQn_DEBUG_TRCSTS_MASK 0x6u
#define ENET_MTL_TXQn_DEBUG_TRCSTS_SHIFT 1u
#define ENET_MTL_TXQn_DEBUG_TRCSTS_WIDTH 2u
#define ENET_MTL_TXQn_DEBUG_TRCSTS(x)  (((uint32_t)(((uint32_t)(x))<<ENET_MTL_TXQn_DEBUG_TRCSTS_SHIFT))&ENET_MTL_TXQn_DEBUG_TRCSTS_MASK)
#define ENET_MTL_TXQn_DEBUG_TXQPAUSED_MASK 0x1u
#define ENET_MTL_TXQn_DEBUG_TXQPAUSED_SHIFT 0u
#define ENET_MTL_TXQn_DEBUG_TXQPAUSED_WIDTH 1u
#define ENET_MTL_TXQn_DEBUG_TXQPAUSED(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_TXQn_DEBUG_TXQPAUSED_SHIFT))&ENET_MTL_TXQn_DEBUG_TXQPAUSED_MASK)
/* MTL_TXQ1_DEBUG Reg Mask */
#define ENET_MTL_TXQn_DEBUG_MASK       0x0077003Fu

/* MTL_TXQn_ETS_CONTROL Bit Fields */
#define ENET_MTL_TXQn_ETS_CONTROL_SLC_MASK 0x70u
#define ENET_MTL_TXQn_ETS_CONTROL_SLC_SHIFT 4u
#define ENET_MTL_TXQn_ETS_CONTROL_SLC_WIDTH 3u
#define ENET_MTL_TXQn_ETS_CONTROL_SLC(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_TXQn_ETS_CONTROL_SLC_SHIFT))&ENET_MTL_TXQn_ETS_CONTROL_SLC_MASK)
#define ENET_MTL_TXQn_ETS_CONTROL_CC_MASK 0x8u
#define ENET_MTL_TXQn_ETS_CONTROL_CC_SHIFT 3u
#define ENET_MTL_TXQn_ETS_CONTROL_CC_WIDTH 1u
#define ENET_MTL_TXQn_ETS_CONTROL_CC(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_TXQn_ETS_CONTROL_CC_SHIFT))&ENET_MTL_TXQn_ETS_CONTROL_CC_MASK)
#define ENET_MTL_TXQn_ETS_CONTROL_AVALG_MASK 0x4u
#define ENET_MTL_TXQn_ETS_CONTROL_AVALG_SHIFT 2u
#define ENET_MTL_TXQn_ETS_CONTROL_AVALG_WIDTH 1u
#define ENET_MTL_TXQn_ETS_CONTROL_AVALG(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_TXQn_ETS_CONTROL_AVALG_SHIFT))&ENET_MTL_TXQn_ETS_CONTROL_AVALG_MASK)
/* MTL_TXQ1_ETS_CONTROL Reg Mask */
#define ENET_MTL_TXQn_ETS_CONTROL_MASK 0x0000007Cu

/* MTL_TXQn_ETS_STATUS Bit Fields */
#define ENET_MTL_TXQn_ETS_STATUS_ABS_MASK 0xFFFFFFu
#define ENET_MTL_TXQn_ETS_STATUS_ABS_SHIFT 0u
#define ENET_MTL_TXQn_ETS_STATUS_ABS_WIDTH 24u
#define ENET_MTL_TXQn_ETS_STATUS_ABS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_TXQn_ETS_STATUS_ABS_SHIFT))&ENET_MTL_TXQn_ETS_STATUS_ABS_MASK)
/* MTL_TXQ1_ETS_STATUS Reg Mask */
#define ENET_MTL_TXQn_ETS_STATUS_MASK  0x00FFFFFFu

/* MTL_TXQn_QUANTUM_WEIGHT Bit Fields */
#define ENET_MTL_TXQn_QUANTUM_WEIGHT_ISCQW_MASK 0x1FFFFFu
#define ENET_MTL_TXQn_QUANTUM_WEIGHT_ISCQW_SHIFT 0u
#define ENET_MTL_TXQn_QUANTUM_WEIGHT_ISCQW_WIDTH 21u
#define ENET_MTL_TXQn_QUANTUM_WEIGHT_ISCQW(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_TXQn_QUANTUM_WEIGHT_ISCQW_SHIFT))&ENET_MTL_TXQn_QUANTUM_WEIGHT_ISCQW_MASK)
/* MTL_TXQ1_QUANTUM_WEIGHT Reg Mask */
#define ENET_MTL_TXQn_QUANTUM_WEIGHT_MASK 0x001FFFFFu

/* MTL_TXQn_SENDSLOPECREDIT Bit Fields */
#define ENET_MTL_TXQn_SENDSLOPECREDIT_SSC_MASK 0x3FFFu
#define ENET_MTL_TXQn_SENDSLOPECREDIT_SSC_SHIFT 0u
#define ENET_MTL_TXQn_SENDSLOPECREDIT_SSC_WIDTH 14u
#define ENET_MTL_TXQn_SENDSLOPECREDIT_SSC(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_TXQn_SENDSLOPECREDIT_SSC_SHIFT))&ENET_MTL_TXQn_SENDSLOPECREDIT_SSC_MASK)
/* MTL_TXQ1_SENDSLOPECREDIT Reg Mask */
#define ENET_MTL_TXQn_SENDSLOPECREDIT_MASK 0x00003FFFu

/* MTL_TXQn_HICREDIT Bit Fields */
#define ENET_MTL_TXQn_HICREDIT_HC_MASK 0x1FFFFFFFu
#define ENET_MTL_TXQn_HICREDIT_HC_SHIFT 0u
#define ENET_MTL_TXQn_HICREDIT_HC_WIDTH 29u
#define ENET_MTL_TXQn_HICREDIT_HC(x)   (((uint32_t)(((uint32_t)(x))<<ENET_MTL_TXQn_HICREDIT_HC_SHIFT))&ENET_MTL_TXQn_HICREDIT_HC_MASK)
/* MTL_TXQ1_HICREDIT Reg Mask */
#define ENET_MTL_TXQn_HICREDIT_MASK    0x1FFFFFFFu

/* MTL_TXQn_LOCREDIT Bit Fields */
#define ENET_MTL_TXQn_LOCREDIT_LC_MASK 0x1FFFFFFFu
#define ENET_MTL_TXQn_LOCREDIT_LC_SHIFT 0u
#define ENET_MTL_TXQn_LOCREDIT_LC_WIDTH 29u
#define ENET_MTL_TXQn_LOCREDIT_LC(x)   (((uint32_t)(((uint32_t)(x))<<ENET_MTL_TXQn_LOCREDIT_LC_SHIFT))&ENET_MTL_TXQn_LOCREDIT_LC_MASK)
/* MTL_TXQ1_LOCREDIT Reg Mask */
#define ENET_MTL_TXQn_LOCREDIT_MASK    0x1FFFFFFFu

/* MTL_Qn_INTERRUPT_CONTROL_STATUS Bit Fields */
#define ENET_MTL_Qn_INTERRUPT_CONTROL_STATUS_RXOIE_MASK 0x1000000u
#define ENET_MTL_Qn_INTERRUPT_CONTROL_STATUS_RXOIE_SHIFT 24u
#define ENET_MTL_Qn_INTERRUPT_CONTROL_STATUS_RXOIE_WIDTH 1u
#define ENET_MTL_Qn_INTERRUPT_CONTROL_STATUS_RXOIE(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_Qn_INTERRUPT_CONTROL_STATUS_RXOIE_SHIFT))&ENET_MTL_Qn_INTERRUPT_CONTROL_STATUS_RXOIE_MASK)
#define ENET_MTL_Qn_INTERRUPT_CONTROL_STATUS_RXOVFIS_MASK 0x10000u
#define ENET_MTL_Qn_INTERRUPT_CONTROL_STATUS_RXOVFIS_SHIFT 16u
#define ENET_MTL_Qn_INTERRUPT_CONTROL_STATUS_RXOVFIS_WIDTH 1u
#define ENET_MTL_Qn_INTERRUPT_CONTROL_STATUS_RXOVFIS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_Qn_INTERRUPT_CONTROL_STATUS_RXOVFIS_SHIFT))&ENET_MTL_Qn_INTERRUPT_CONTROL_STATUS_RXOVFIS_MASK)
#define ENET_MTL_Qn_INTERRUPT_CONTROL_STATUS_ABPSIE_MASK 0x200u
#define ENET_MTL_Qn_INTERRUPT_CONTROL_STATUS_ABPSIE_SHIFT 9u
#define ENET_MTL_Qn_INTERRUPT_CONTROL_STATUS_ABPSIE_WIDTH 1u
#define ENET_MTL_Qn_INTERRUPT_CONTROL_STATUS_ABPSIE(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_Qn_INTERRUPT_CONTROL_STATUS_ABPSIE_SHIFT))&ENET_MTL_Qn_INTERRUPT_CONTROL_STATUS_ABPSIE_MASK)
#define ENET_MTL_Qn_INTERRUPT_CONTROL_STATUS_TXUIE_MASK 0x100u
#define ENET_MTL_Qn_INTERRUPT_CONTROL_STATUS_TXUIE_SHIFT 8u
#define ENET_MTL_Qn_INTERRUPT_CONTROL_STATUS_TXUIE_WIDTH 1u
#define ENET_MTL_Qn_INTERRUPT_CONTROL_STATUS_TXUIE(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_Qn_INTERRUPT_CONTROL_STATUS_TXUIE_SHIFT))&ENET_MTL_Qn_INTERRUPT_CONTROL_STATUS_TXUIE_MASK)
#define ENET_MTL_Qn_INTERRUPT_CONTROL_STATUS_ABPSIS_MASK 0x2u
#define ENET_MTL_Qn_INTERRUPT_CONTROL_STATUS_ABPSIS_SHIFT 1u
#define ENET_MTL_Qn_INTERRUPT_CONTROL_STATUS_ABPSIS_WIDTH 1u
#define ENET_MTL_Qn_INTERRUPT_CONTROL_STATUS_ABPSIS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_Qn_INTERRUPT_CONTROL_STATUS_ABPSIS_SHIFT))&ENET_MTL_Qn_INTERRUPT_CONTROL_STATUS_ABPSIS_MASK)
#define ENET_MTL_Qn_INTERRUPT_CONTROL_STATUS_TXUNFIS_MASK 0x1u
#define ENET_MTL_Qn_INTERRUPT_CONTROL_STATUS_TXUNFIS_SHIFT 0u
#define ENET_MTL_Qn_INTERRUPT_CONTROL_STATUS_TXUNFIS_WIDTH 1u
#define ENET_MTL_Qn_INTERRUPT_CONTROL_STATUS_TXUNFIS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_Qn_INTERRUPT_CONTROL_STATUS_TXUNFIS_SHIFT))&ENET_MTL_Qn_INTERRUPT_CONTROL_STATUS_TXUNFIS_MASK)
/* MTL_Q1_INTERRUPT_CONTROL_STATUS Reg Mask */
#define ENET_MTL_Qn_INTERRUPT_CONTROL_STATUS_MASK 0x01010303u

/* MTL_RXQn_OPERATION_MODE Bit Fields */
#define ENET_MTL_RXQn_OPERATION_MODE_RQS_MASK 0x1F00000u
#define ENET_MTL_RXQn_OPERATION_MODE_RQS_SHIFT 20u
#define ENET_MTL_RXQn_OPERATION_MODE_RQS_WIDTH 5u
#define ENET_MTL_RXQn_OPERATION_MODE_RQS(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_RXQn_OPERATION_MODE_RQS_SHIFT))&ENET_MTL_RXQn_OPERATION_MODE_RQS_MASK)
#define ENET_MTL_RXQn_OPERATION_MODE_RFD_MASK 0x3C000u
#define ENET_MTL_RXQn_OPERATION_MODE_RFD_SHIFT 14u
#define ENET_MTL_RXQn_OPERATION_MODE_RFD_WIDTH 4u
#define ENET_MTL_RXQn_OPERATION_MODE_RFD(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_RXQn_OPERATION_MODE_RFD_SHIFT))&ENET_MTL_RXQn_OPERATION_MODE_RFD_MASK)
#define ENET_MTL_RXQn_OPERATION_MODE_RFA_MASK 0xF00u
#define ENET_MTL_RXQn_OPERATION_MODE_RFA_SHIFT 8u
#define ENET_MTL_RXQn_OPERATION_MODE_RFA_WIDTH 4u
#define ENET_MTL_RXQn_OPERATION_MODE_RFA(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_RXQn_OPERATION_MODE_RFA_SHIFT))&ENET_MTL_RXQn_OPERATION_MODE_RFA_MASK)
#define ENET_MTL_RXQn_OPERATION_MODE_EHFC_MASK 0x80u
#define ENET_MTL_RXQn_OPERATION_MODE_EHFC_SHIFT 7u
#define ENET_MTL_RXQn_OPERATION_MODE_EHFC_WIDTH 1u
#define ENET_MTL_RXQn_OPERATION_MODE_EHFC(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_RXQn_OPERATION_MODE_EHFC_SHIFT))&ENET_MTL_RXQn_OPERATION_MODE_EHFC_MASK)
#define ENET_MTL_RXQn_OPERATION_MODE_DIS_TCP_EF_MASK 0x40u
#define ENET_MTL_RXQn_OPERATION_MODE_DIS_TCP_EF_SHIFT 6u
#define ENET_MTL_RXQn_OPERATION_MODE_DIS_TCP_EF_WIDTH 1u
#define ENET_MTL_RXQn_OPERATION_MODE_DIS_TCP_EF(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_RXQn_OPERATION_MODE_DIS_TCP_EF_SHIFT))&ENET_MTL_RXQn_OPERATION_MODE_DIS_TCP_EF_MASK)
#define ENET_MTL_RXQn_OPERATION_MODE_RSF_MASK 0x20u
#define ENET_MTL_RXQn_OPERATION_MODE_RSF_SHIFT 5u
#define ENET_MTL_RXQn_OPERATION_MODE_RSF_WIDTH 1u
#define ENET_MTL_RXQn_OPERATION_MODE_RSF(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_RXQn_OPERATION_MODE_RSF_SHIFT))&ENET_MTL_RXQn_OPERATION_MODE_RSF_MASK)
#define ENET_MTL_RXQn_OPERATION_MODE_FEP_MASK 0x10u
#define ENET_MTL_RXQn_OPERATION_MODE_FEP_SHIFT 4u
#define ENET_MTL_RXQn_OPERATION_MODE_FEP_WIDTH 1u
#define ENET_MTL_RXQn_OPERATION_MODE_FEP(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_RXQn_OPERATION_MODE_FEP_SHIFT))&ENET_MTL_RXQn_OPERATION_MODE_FEP_MASK)
#define ENET_MTL_RXQn_OPERATION_MODE_FUP_MASK 0x8u
#define ENET_MTL_RXQn_OPERATION_MODE_FUP_SHIFT 3u
#define ENET_MTL_RXQn_OPERATION_MODE_FUP_WIDTH 1u
#define ENET_MTL_RXQn_OPERATION_MODE_FUP(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_RXQn_OPERATION_MODE_FUP_SHIFT))&ENET_MTL_RXQn_OPERATION_MODE_FUP_MASK)
#define ENET_MTL_RXQn_OPERATION_MODE_RTC_MASK 0x3u
#define ENET_MTL_RXQn_OPERATION_MODE_RTC_SHIFT 0u
#define ENET_MTL_RXQn_OPERATION_MODE_RTC_WIDTH 2u
#define ENET_MTL_RXQn_OPERATION_MODE_RTC(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_RXQn_OPERATION_MODE_RTC_SHIFT))&ENET_MTL_RXQn_OPERATION_MODE_RTC_MASK)
/* MTL_RXQ1_OPERATION_MODE Reg Mask */
#define ENET_MTL_RXQn_OPERATION_MODE_MASK 0x01F3CFFBu

/* MTL_RXQn_MISSED_PACKET_OVERFLOW_CNT Bit Fields */
#define ENET_MTL_RXQn_MISSED_PACKET_OVERFLOW_CNT_MISCNTOVF_MASK 0x8000000u
#define ENET_MTL_RXQn_MISSED_PACKET_OVERFLOW_CNT_MISCNTOVF_SHIFT 27u
#define ENET_MTL_RXQn_MISSED_PACKET_OVERFLOW_CNT_MISCNTOVF_WIDTH 1u
#define ENET_MTL_RXQn_MISSED_PACKET_OVERFLOW_CNT_MISCNTOVF(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_RXQn_MISSED_PACKET_OVERFLOW_CNT_MISCNTOVF_SHIFT))&ENET_MTL_RXQn_MISSED_PACKET_OVERFLOW_CNT_MISCNTOVF_MASK)
#define ENET_MTL_RXQn_MISSED_PACKET_OVERFLOW_CNT_MISPKTCNT_MASK 0x7FF0000u
#define ENET_MTL_RXQn_MISSED_PACKET_OVERFLOW_CNT_MISPKTCNT_SHIFT 16u
#define ENET_MTL_RXQn_MISSED_PACKET_OVERFLOW_CNT_MISPKTCNT_WIDTH 11u
#define ENET_MTL_RXQn_MISSED_PACKET_OVERFLOW_CNT_MISPKTCNT(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_RXQn_MISSED_PACKET_OVERFLOW_CNT_MISPKTCNT_SHIFT))&ENET_MTL_RXQn_MISSED_PACKET_OVERFLOW_CNT_MISPKTCNT_MASK)
#define ENET_MTL_RXQn_MISSED_PACKET_OVERFLOW_CNT_OVFCNTOVF_MASK 0x800u
#define ENET_MTL_RXQn_MISSED_PACKET_OVERFLOW_CNT_OVFCNTOVF_SHIFT 11u
#define ENET_MTL_RXQn_MISSED_PACKET_OVERFLOW_CNT_OVFCNTOVF_WIDTH 1u
#define ENET_MTL_RXQn_MISSED_PACKET_OVERFLOW_CNT_OVFCNTOVF(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_RXQn_MISSED_PACKET_OVERFLOW_CNT_OVFCNTOVF_SHIFT))&ENET_MTL_RXQn_MISSED_PACKET_OVERFLOW_CNT_OVFCNTOVF_MASK)
#define ENET_MTL_RXQn_MISSED_PACKET_OVERFLOW_CNT_OVFPKTCNT_MASK 0x7FFu
#define ENET_MTL_RXQn_MISSED_PACKET_OVERFLOW_CNT_OVFPKTCNT_SHIFT 0u
#define ENET_MTL_RXQn_MISSED_PACKET_OVERFLOW_CNT_OVFPKTCNT_WIDTH 11u
#define ENET_MTL_RXQn_MISSED_PACKET_OVERFLOW_CNT_OVFPKTCNT(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_RXQn_MISSED_PACKET_OVERFLOW_CNT_OVFPKTCNT_SHIFT))&ENET_MTL_RXQn_MISSED_PACKET_OVERFLOW_CNT_OVFPKTCNT_MASK)
/* MTL_RXQ1_MISSED_PACKET_OVERFLOW_CNT Reg Mask */
#define ENET_MTL_RXQn_MISSED_PACKET_OVERFLOW_CNT_MASK 0x0FFF0FFFu

/* MTL_RXQn_DEBUG Bit Fields */
#define ENET_MTL_RXQn_DEBUG_PRXQ_MASK  0x3FFF0000u
#define ENET_MTL_RXQn_DEBUG_PRXQ_SHIFT 16u
#define ENET_MTL_RXQn_DEBUG_PRXQ_WIDTH 14u
#define ENET_MTL_RXQn_DEBUG_PRXQ(x)    (((uint32_t)(((uint32_t)(x))<<ENET_MTL_RXQn_DEBUG_PRXQ_SHIFT))&ENET_MTL_RXQn_DEBUG_PRXQ_MASK)
#define ENET_MTL_RXQn_DEBUG_RXQSTS_MASK 0x30u
#define ENET_MTL_RXQn_DEBUG_RXQSTS_SHIFT 4u
#define ENET_MTL_RXQn_DEBUG_RXQSTS_WIDTH 2u
#define ENET_MTL_RXQn_DEBUG_RXQSTS(x)  (((uint32_t)(((uint32_t)(x))<<ENET_MTL_RXQn_DEBUG_RXQSTS_SHIFT))&ENET_MTL_RXQn_DEBUG_RXQSTS_MASK)
#define ENET_MTL_RXQn_DEBUG_RRCSTS_MASK 0x6u
#define ENET_MTL_RXQn_DEBUG_RRCSTS_SHIFT 1u
#define ENET_MTL_RXQn_DEBUG_RRCSTS_WIDTH 2u
#define ENET_MTL_RXQn_DEBUG_RRCSTS(x)  (((uint32_t)(((uint32_t)(x))<<ENET_MTL_RXQn_DEBUG_RRCSTS_SHIFT))&ENET_MTL_RXQn_DEBUG_RRCSTS_MASK)
#define ENET_MTL_RXQn_DEBUG_RWCSTS_MASK 0x1u
#define ENET_MTL_RXQn_DEBUG_RWCSTS_SHIFT 0u
#define ENET_MTL_RXQn_DEBUG_RWCSTS_WIDTH 1u
#define ENET_MTL_RXQn_DEBUG_RWCSTS(x)  (((uint32_t)(((uint32_t)(x))<<ENET_MTL_RXQn_DEBUG_RWCSTS_SHIFT))&ENET_MTL_RXQn_DEBUG_RWCSTS_MASK)
/* MTL_RXQ1_DEBUG Reg Mask */
#define ENET_MTL_RXQn_DEBUG_MASK       0x3FFF0037u

/* MTL_RXQn_CONTROL Bit Fields */
#define ENET_MTL_RXQn_CONTROL_RXQ_FRM_ARBIT_MASK 0x8u
#define ENET_MTL_RXQn_CONTROL_RXQ_FRM_ARBIT_SHIFT 3u
#define ENET_MTL_RXQn_CONTROL_RXQ_FRM_ARBIT_WIDTH 1u
#define ENET_MTL_RXQn_CONTROL_RXQ_FRM_ARBIT(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_RXQn_CONTROL_RXQ_FRM_ARBIT_SHIFT))&ENET_MTL_RXQn_CONTROL_RXQ_FRM_ARBIT_MASK)
#define ENET_MTL_RXQn_CONTROL_RXQ_WEGT_MASK 0x7u
#define ENET_MTL_RXQn_CONTROL_RXQ_WEGT_SHIFT 0u
#define ENET_MTL_RXQn_CONTROL_RXQ_WEGT_WIDTH 3u
#define ENET_MTL_RXQn_CONTROL_RXQ_WEGT(x) (((uint32_t)(((uint32_t)(x))<<ENET_MTL_RXQn_CONTROL_RXQ_WEGT_SHIFT))&ENET_MTL_RXQn_CONTROL_RXQ_WEGT_MASK)
/* MTL_RXQ1_CONTROL Reg Mask */
#define ENET_MTL_RXQn_CONTROL_MASK     0x0000000Fu

/* DMA_MODE Bit Fields */
#define ENET_DMA_MODE_INTM_MASK        0x30000u
#define ENET_DMA_MODE_INTM_SHIFT       16u
#define ENET_DMA_MODE_INTM_WIDTH       2u
#define ENET_DMA_MODE_INTM(x)          (((uint32_t)(((uint32_t)(x))<<ENET_DMA_MODE_INTM_SHIFT))&ENET_DMA_MODE_INTM_MASK)
#define ENET_DMA_MODE_PR_MASK          0x7000u
#define ENET_DMA_MODE_PR_SHIFT         12u
#define ENET_DMA_MODE_PR_WIDTH         3u
#define ENET_DMA_MODE_PR(x)            (((uint32_t)(((uint32_t)(x))<<ENET_DMA_MODE_PR_SHIFT))&ENET_DMA_MODE_PR_MASK)
#define ENET_DMA_MODE_TXPR_MASK        0x800u
#define ENET_DMA_MODE_TXPR_SHIFT       11u
#define ENET_DMA_MODE_TXPR_WIDTH       1u
#define ENET_DMA_MODE_TXPR(x)          (((uint32_t)(((uint32_t)(x))<<ENET_DMA_MODE_TXPR_SHIFT))&ENET_DMA_MODE_TXPR_MASK)
#define ENET_DMA_MODE_ARBC_MASK        0x200u
#define ENET_DMA_MODE_ARBC_SHIFT       9u
#define ENET_DMA_MODE_ARBC_WIDTH       1u
#define ENET_DMA_MODE_ARBC(x)          (((uint32_t)(((uint32_t)(x))<<ENET_DMA_MODE_ARBC_SHIFT))&ENET_DMA_MODE_ARBC_MASK)
#define ENET_DMA_MODE_DSPW_MASK        0x100u
#define ENET_DMA_MODE_DSPW_SHIFT       8u
#define ENET_DMA_MODE_DSPW_WIDTH       1u
#define ENET_DMA_MODE_DSPW(x)          (((uint32_t)(((uint32_t)(x))<<ENET_DMA_MODE_DSPW_SHIFT))&ENET_DMA_MODE_DSPW_MASK)
#define ENET_DMA_MODE_TAA_MASK         0x1Cu
#define ENET_DMA_MODE_TAA_SHIFT        2u
#define ENET_DMA_MODE_TAA_WIDTH        3u
#define ENET_DMA_MODE_TAA(x)           (((uint32_t)(((uint32_t)(x))<<ENET_DMA_MODE_TAA_SHIFT))&ENET_DMA_MODE_TAA_MASK)
#define ENET_DMA_MODE_DA_MASK          0x2u
#define ENET_DMA_MODE_DA_SHIFT         1u
#define ENET_DMA_MODE_DA_WIDTH         1u
#define ENET_DMA_MODE_DA(x)            (((uint32_t)(((uint32_t)(x))<<ENET_DMA_MODE_DA_SHIFT))&ENET_DMA_MODE_DA_MASK)
#define ENET_DMA_MODE_SWR_MASK         0x1u
#define ENET_DMA_MODE_SWR_SHIFT        0u
#define ENET_DMA_MODE_SWR_WIDTH        1u
#define ENET_DMA_MODE_SWR(x)           (((uint32_t)(((uint32_t)(x))<<ENET_DMA_MODE_SWR_SHIFT))&ENET_DMA_MODE_SWR_MASK)
/* DMA_MODE Reg Mask */
#define ENET_DMA_MODE_MASK             0x00037803u

/* DMA_SYSBUS_MODE Bit Fields */
#define ENET_DMA_SYSBUS_MODE_RB_MASK   0x8000u
#define ENET_DMA_SYSBUS_MODE_RB_SHIFT  15u
#define ENET_DMA_SYSBUS_MODE_RB_WIDTH  1u
#define ENET_DMA_SYSBUS_MODE_RB(x)     (((uint32_t)(((uint32_t)(x))<<ENET_DMA_SYSBUS_MODE_RB_SHIFT))&ENET_DMA_SYSBUS_MODE_RB_MASK)
#define ENET_DMA_SYSBUS_MODE_MB_MASK   0x4000u
#define ENET_DMA_SYSBUS_MODE_MB_SHIFT  14u
#define ENET_DMA_SYSBUS_MODE_MB_WIDTH  1u
#define ENET_DMA_SYSBUS_MODE_MB(x)     (((uint32_t)(((uint32_t)(x))<<ENET_DMA_SYSBUS_MODE_MB_SHIFT))&ENET_DMA_SYSBUS_MODE_MB_MASK)
#define ENET_DMA_SYSBUS_MODE_AAL_MASK  0x1000u
#define ENET_DMA_SYSBUS_MODE_AAL_SHIFT 12u
#define ENET_DMA_SYSBUS_MODE_AAL_WIDTH 1u
#define ENET_DMA_SYSBUS_MODE_AAL(x)    (((uint32_t)(((uint32_t)(x))<<ENET_DMA_SYSBUS_MODE_AAL_SHIFT))&ENET_DMA_SYSBUS_MODE_AAL_MASK)
#define ENET_DMA_SYSBUS_MODE_FB_MASK   0x1u
#define ENET_DMA_SYSBUS_MODE_FB_SHIFT  0u
#define ENET_DMA_SYSBUS_MODE_FB_WIDTH  1u
#define ENET_DMA_SYSBUS_MODE_FB(x)     (((uint32_t)(((uint32_t)(x))<<ENET_DMA_SYSBUS_MODE_FB_SHIFT))&ENET_DMA_SYSBUS_MODE_FB_MASK)
/* DMA_SYSBUS_MODE Reg Mask */
#define ENET_DMA_SYSBUS_MODE_MASK      0x0000D001u

/* DMA_INTERRUPT_STATUS Bit Fields */
#define ENET_DMA_INTERRUPT_STATUS_MACIS_MASK 0x20000u
#define ENET_DMA_INTERRUPT_STATUS_MACIS_SHIFT 17u
#define ENET_DMA_INTERRUPT_STATUS_MACIS_WIDTH 1u
#define ENET_DMA_INTERRUPT_STATUS_MACIS(x) (((uint32_t)(((uint32_t)(x))<<ENET_DMA_INTERRUPT_STATUS_MACIS_SHIFT))&ENET_DMA_INTERRUPT_STATUS_MACIS_MASK)
#define ENET_DMA_INTERRUPT_STATUS_MTLIS_MASK 0x10000u
#define ENET_DMA_INTERRUPT_STATUS_MTLIS_SHIFT 16u
#define ENET_DMA_INTERRUPT_STATUS_MTLIS_WIDTH 1u
#define ENET_DMA_INTERRUPT_STATUS_MTLIS(x) (((uint32_t)(((uint32_t)(x))<<ENET_DMA_INTERRUPT_STATUS_MTLIS_SHIFT))&ENET_DMA_INTERRUPT_STATUS_MTLIS_MASK)
#define ENET_DMA_INTERRUPT_STATUS_DC1IS_MASK 0x2u
#define ENET_DMA_INTERRUPT_STATUS_DC1IS_SHIFT 1u
#define ENET_DMA_INTERRUPT_STATUS_DC1IS_WIDTH 1u
#define ENET_DMA_INTERRUPT_STATUS_DC1IS(x) (((uint32_t)(((uint32_t)(x))<<ENET_DMA_INTERRUPT_STATUS_DC1IS_SHIFT))&ENET_DMA_INTERRUPT_STATUS_DC1IS_MASK)
#define ENET_DMA_INTERRUPT_STATUS_DC0IS_MASK 0x1u
#define ENET_DMA_INTERRUPT_STATUS_DC0IS_SHIFT 0u
#define ENET_DMA_INTERRUPT_STATUS_DC0IS_WIDTH 1u
#define ENET_DMA_INTERRUPT_STATUS_DC0IS(x) (((uint32_t)(((uint32_t)(x))<<ENET_DMA_INTERRUPT_STATUS_DC0IS_SHIFT))&ENET_DMA_INTERRUPT_STATUS_DC0IS_MASK)
/* DMA_INTERRUPT_STATUS Reg Mask */
#define ENET_DMA_INTERRUPT_STATUS_MASK 0x00030003u

/* DMA_DEBUG_STATUS0 Bit Fields */
#define ENET_DMA_DEBUG_STATUS0_TPS1_MASK 0xF00000u
#define ENET_DMA_DEBUG_STATUS0_TPS1_SHIFT 20u
#define ENET_DMA_DEBUG_STATUS0_TPS1_WIDTH 4u
#define ENET_DMA_DEBUG_STATUS0_TPS1(x) (((uint32_t)(((uint32_t)(x))<<ENET_DMA_DEBUG_STATUS0_TPS1_SHIFT))&ENET_DMA_DEBUG_STATUS0_TPS1_MASK)
#define ENET_DMA_DEBUG_STATUS0_RPS1_MASK 0xF0000u
#define ENET_DMA_DEBUG_STATUS0_RPS1_SHIFT 16u
#define ENET_DMA_DEBUG_STATUS0_RPS1_WIDTH 4u
#define ENET_DMA_DEBUG_STATUS0_RPS1(x) (((uint32_t)(((uint32_t)(x))<<ENET_DMA_DEBUG_STATUS0_RPS1_SHIFT))&ENET_DMA_DEBUG_STATUS0_RPS1_MASK)
#define ENET_DMA_DEBUG_STATUS0_TPS0_MASK 0xF000u
#define ENET_DMA_DEBUG_STATUS0_TPS0_SHIFT 12u
#define ENET_DMA_DEBUG_STATUS0_TPS0_WIDTH 4u
#define ENET_DMA_DEBUG_STATUS0_TPS0(x) (((uint32_t)(((uint32_t)(x))<<ENET_DMA_DEBUG_STATUS0_TPS0_SHIFT))&ENET_DMA_DEBUG_STATUS0_TPS0_MASK)
#define ENET_DMA_DEBUG_STATUS0_RPS0_MASK 0xF00u
#define ENET_DMA_DEBUG_STATUS0_RPS0_SHIFT 8u
#define ENET_DMA_DEBUG_STATUS0_RPS0_WIDTH 4u
#define ENET_DMA_DEBUG_STATUS0_RPS0(x) (((uint32_t)(((uint32_t)(x))<<ENET_DMA_DEBUG_STATUS0_RPS0_SHIFT))&ENET_DMA_DEBUG_STATUS0_RPS0_MASK)
#define ENET_DMA_DEBUG_STATUS0_AXWHSTS_MASK 0x1u
#define ENET_DMA_DEBUG_STATUS0_AXWHSTS_SHIFT 0u
#define ENET_DMA_DEBUG_STATUS0_AXWHSTS_WIDTH 1u
#define ENET_DMA_DEBUG_STATUS0_AXWHSTS(x) (((uint32_t)(((uint32_t)(x))<<ENET_DMA_DEBUG_STATUS0_AXWHSTS_SHIFT))&ENET_DMA_DEBUG_STATUS0_AXWHSTS_MASK)
/* DMA_DEBUG_STATUS0 Reg Mask */
#define ENET_DMA_DEBUG_STATUS0_MASK    0x00FFFF01u

/* DMA_TBS_CTRL Bit Fields */
#define ENET_DMA_TBS_CTRL_FTOS_MASK    0xFFFFFF00u
#define ENET_DMA_TBS_CTRL_FTOS_SHIFT   8u
#define ENET_DMA_TBS_CTRL_FTOS_WIDTH   24u
#define ENET_DMA_TBS_CTRL_FTOS(x)      (((uint32_t)(((uint32_t)(x))<<ENET_DMA_TBS_CTRL_FTOS_SHIFT))&ENET_DMA_TBS_CTRL_FTOS_MASK)
#define ENET_DMA_TBS_CTRL_FGOS_MASK    0x70u
#define ENET_DMA_TBS_CTRL_FGOS_SHIFT   4u
#define ENET_DMA_TBS_CTRL_FGOS_WIDTH   3u
#define ENET_DMA_TBS_CTRL_FGOS(x)      (((uint32_t)(((uint32_t)(x))<<ENET_DMA_TBS_CTRL_FGOS_SHIFT))&ENET_DMA_TBS_CTRL_FGOS_MASK)
#define ENET_DMA_TBS_CTRL_FTOV_MASK    0x1u
#define ENET_DMA_TBS_CTRL_FTOV_SHIFT   0u
#define ENET_DMA_TBS_CTRL_FTOV_WIDTH   1u
#define ENET_DMA_TBS_CTRL_FTOV(x)      (((uint32_t)(((uint32_t)(x))<<ENET_DMA_TBS_CTRL_FTOV_SHIFT))&ENET_DMA_TBS_CTRL_FTOV_MASK)
/* DMA_TBS_CTRL Reg Mask */
#define ENET_DMA_TBS_CTRL_MASK         0xFFFFFF71u

/* DMA_SAFETY_INTERRUPT_STATUS Bit Fields */
#define ENET_DMA_SAFETY_INTERRUPT_STATUS_MCSIS_MASK 0x80000000u
#define ENET_DMA_SAFETY_INTERRUPT_STATUS_MCSIS_SHIFT 31u
#define ENET_DMA_SAFETY_INTERRUPT_STATUS_MCSIS_WIDTH 1u
#define ENET_DMA_SAFETY_INTERRUPT_STATUS_MCSIS(x) (((uint32_t)(((uint32_t)(x))<<ENET_DMA_SAFETY_INTERRUPT_STATUS_MCSIS_SHIFT))&ENET_DMA_SAFETY_INTERRUPT_STATUS_MCSIS_MASK)
#define ENET_DMA_SAFETY_INTERRUPT_STATUS_MSUIS_MASK 0x20000000u
#define ENET_DMA_SAFETY_INTERRUPT_STATUS_MSUIS_SHIFT 29u
#define ENET_DMA_SAFETY_INTERRUPT_STATUS_MSUIS_WIDTH 1u
#define ENET_DMA_SAFETY_INTERRUPT_STATUS_MSUIS(x) (((uint32_t)(((uint32_t)(x))<<ENET_DMA_SAFETY_INTERRUPT_STATUS_MSUIS_SHIFT))&ENET_DMA_SAFETY_INTERRUPT_STATUS_MSUIS_MASK)
#define ENET_DMA_SAFETY_INTERRUPT_STATUS_MSCIS_MASK 0x10000000u
#define ENET_DMA_SAFETY_INTERRUPT_STATUS_MSCIS_SHIFT 28u
#define ENET_DMA_SAFETY_INTERRUPT_STATUS_MSCIS_WIDTH 1u
#define ENET_DMA_SAFETY_INTERRUPT_STATUS_MSCIS(x) (((uint32_t)(((uint32_t)(x))<<ENET_DMA_SAFETY_INTERRUPT_STATUS_MSCIS_SHIFT))&ENET_DMA_SAFETY_INTERRUPT_STATUS_MSCIS_MASK)
#define ENET_DMA_SAFETY_INTERRUPT_STATUS_DEUIS_MASK 0x2u
#define ENET_DMA_SAFETY_INTERRUPT_STATUS_DEUIS_SHIFT 1u
#define ENET_DMA_SAFETY_INTERRUPT_STATUS_DEUIS_WIDTH 1u
#define ENET_DMA_SAFETY_INTERRUPT_STATUS_DEUIS(x) (((uint32_t)(((uint32_t)(x))<<ENET_DMA_SAFETY_INTERRUPT_STATUS_DEUIS_SHIFT))&ENET_DMA_SAFETY_INTERRUPT_STATUS_DEUIS_MASK)
#define ENET_DMA_SAFETY_INTERRUPT_STATUS_DECIS_MASK 0x1u
#define ENET_DMA_SAFETY_INTERRUPT_STATUS_DECIS_SHIFT 0u
#define ENET_DMA_SAFETY_INTERRUPT_STATUS_DECIS_WIDTH 1u
#define ENET_DMA_SAFETY_INTERRUPT_STATUS_DECIS(x) (((uint32_t)(((uint32_t)(x))<<ENET_DMA_SAFETY_INTERRUPT_STATUS_DECIS_SHIFT))&ENET_DMA_SAFETY_INTERRUPT_STATUS_DECIS_MASK)
/* DMA_SAFETY_INTERRUPT_STATUS Reg Mask */
#define ENET_DMA_SAFETY_INTERRUPT_STATUS_MASK 0xB0000003u

/* DMA_ECC_INTERRUPT_ENABLE Bit Fields */
/* DMA_ECC_INTERRUPT_ENABLE Reg Mask */
#define ENET_DMA_ECC_INTERRUPT_ENABLE_MASK 0x00000000u

/* DMA_ECC_INTERRUPT_STATUS Bit Fields */
/* DMA_ECC_INTERRUPT_STATUS Reg Mask */
#define ENET_DMA_ECC_INTERRUPT_STATUS_MASK 0x00000000u

/* DMA_CHn_CONTROL Bit Fields */
#define ENET_DMA_CHn_CONTROL_DSL_MASK  0x1C0000u
#define ENET_DMA_CHn_CONTROL_DSL_SHIFT 18u
#define ENET_DMA_CHn_CONTROL_DSL_WIDTH 3u
#define ENET_DMA_CHn_CONTROL_DSL(x)    (((uint32_t)(((uint32_t)(x))<<ENET_DMA_CHn_CONTROL_DSL_SHIFT))&ENET_DMA_CHn_CONTROL_DSL_MASK)
#define ENET_DMA_CHn_CONTROL_PBLX8_MASK 0x10000u
#define ENET_DMA_CHn_CONTROL_PBLX8_SHIFT 16u
#define ENET_DMA_CHn_CONTROL_PBLX8_WIDTH 1u
#define ENET_DMA_CHn_CONTROL_PBLX8(x)  (((uint32_t)(((uint32_t)(x))<<ENET_DMA_CHn_CONTROL_PBLX8_SHIFT))&ENET_DMA_CHn_CONTROL_PBLX8_MASK)
#define ENET_DMA_CHn_CONTROL_MSS_MASK  0x3FFFu
#define ENET_DMA_CHn_CONTROL_MSS_SHIFT 0u
#define ENET_DMA_CHn_CONTROL_MSS_WIDTH 14u
#define ENET_DMA_CHn_CONTROL_MSS(x)    (((uint32_t)(((uint32_t)(x))<<ENET_DMA_CHn_CONTROL_MSS_SHIFT))&ENET_DMA_CHn_CONTROL_MSS_MASK)
/* DMA_CH0_CONTROL Reg Mask */
#define ENET_DMA_CHn_CONTROL_MASK      0x001D3FFFu

/* DMA_CHn_TX_CONTROL Bit Fields */
#define ENET_DMA_CHn_TX_CONTROL_TFSEL_MASK 0x60000000u
#define ENET_DMA_CHn_TX_CONTROL_TFSEL_SHIFT 29u
#define ENET_DMA_CHn_TX_CONTROL_TFSEL_WIDTH 2u
#define ENET_DMA_CHn_TX_CONTROL_TFSEL(x) (((uint32_t)(((uint32_t)(x))<<ENET_DMA_CHn_TX_CONTROL_TFSEL_SHIFT))&ENET_DMA_CHn_TX_CONTROL_TFSEL_MASK)
#define ENET_DMA_CHn_TX_CONTROL_EDSE_MASK 0x10000000u
#define ENET_DMA_CHn_TX_CONTROL_EDSE_SHIFT 28u
#define ENET_DMA_CHn_TX_CONTROL_EDSE_WIDTH 1u
#define ENET_DMA_CHn_TX_CONTROL_EDSE(x) (((uint32_t)(((uint32_t)(x))<<ENET_DMA_CHn_TX_CONTROL_EDSE_SHIFT))&ENET_DMA_CHn_TX_CONTROL_EDSE_MASK)
#define ENET_DMA_CHn_TX_CONTROL_ETIC_MASK 0x400000u
#define ENET_DMA_CHn_TX_CONTROL_ETIC_SHIFT 22u
#define ENET_DMA_CHn_TX_CONTROL_ETIC_WIDTH 1u
#define ENET_DMA_CHn_TX_CONTROL_ETIC(x) (((uint32_t)(((uint32_t)(x))<<ENET_DMA_CHn_TX_CONTROL_ETIC_SHIFT))&ENET_DMA_CHn_TX_CONTROL_ETIC_MASK)
#define ENET_DMA_CHn_TX_CONTROL_TXPBL_MASK 0x3F0000u
#define ENET_DMA_CHn_TX_CONTROL_TXPBL_SHIFT 16u
#define ENET_DMA_CHn_TX_CONTROL_TXPBL_WIDTH 6u
#define ENET_DMA_CHn_TX_CONTROL_TXPBL(x) (((uint32_t)(((uint32_t)(x))<<ENET_DMA_CHn_TX_CONTROL_TXPBL_SHIFT))&ENET_DMA_CHn_TX_CONTROL_TXPBL_MASK)
#define ENET_DMA_CHn_TX_CONTROL_IPBL_MASK 0x8000u
#define ENET_DMA_CHn_TX_CONTROL_IPBL_SHIFT 15u
#define ENET_DMA_CHn_TX_CONTROL_IPBL_WIDTH 1u
#define ENET_DMA_CHn_TX_CONTROL_IPBL(x) (((uint32_t)(((uint32_t)(x))<<ENET_DMA_CHn_TX_CONTROL_IPBL_SHIFT))&ENET_DMA_CHn_TX_CONTROL_IPBL_MASK)
#define ENET_DMA_CHn_TX_CONTROL_OSF_MASK 0x10u
#define ENET_DMA_CHn_TX_CONTROL_OSF_SHIFT 4u
#define ENET_DMA_CHn_TX_CONTROL_OSF_WIDTH 1u
#define ENET_DMA_CHn_TX_CONTROL_OSF(x) (((uint32_t)(((uint32_t)(x))<<ENET_DMA_CHn_TX_CONTROL_OSF_SHIFT))&ENET_DMA_CHn_TX_CONTROL_OSF_MASK)
#define ENET_DMA_CHn_TX_CONTROL_TCW_MASK 0xEu
#define ENET_DMA_CHn_TX_CONTROL_TCW_SHIFT 1u
#define ENET_DMA_CHn_TX_CONTROL_TCW_WIDTH 3u
#define ENET_DMA_CHn_TX_CONTROL_TCW(x) (((uint32_t)(((uint32_t)(x))<<ENET_DMA_CHn_TX_CONTROL_TCW_SHIFT))&ENET_DMA_CHn_TX_CONTROL_TCW_MASK)
#define ENET_DMA_CHn_TX_CONTROL_ST_MASK 0x1u
#define ENET_DMA_CHn_TX_CONTROL_ST_SHIFT 0u
#define ENET_DMA_CHn_TX_CONTROL_ST_WIDTH 1u
#define ENET_DMA_CHn_TX_CONTROL_ST(x)  (((uint32_t)(((uint32_t)(x))<<ENET_DMA_CHn_TX_CONTROL_ST_SHIFT))&ENET_DMA_CHn_TX_CONTROL_ST_MASK)
/* DMA_CH0_TX_CONTROL Reg Mask */
#define ENET_DMA_CHn_TX_CONTROL_MASK   0x707F801Fu

/* DMA_CHn_RX_CONTROL Bit Fields */
#define ENET_DMA_CHn_RX_CONTROL_RPF_MASK 0x80000000u
#define ENET_DMA_CHn_RX_CONTROL_RPF_SHIFT 31u
#define ENET_DMA_CHn_RX_CONTROL_RPF_WIDTH 1u
#define ENET_DMA_CHn_RX_CONTROL_RPF(x) (((uint32_t)(((uint32_t)(x))<<ENET_DMA_CHn_RX_CONTROL_RPF_SHIFT))&ENET_DMA_CHn_RX_CONTROL_RPF_MASK)
#define ENET_DMA_CHn_RX_CONTROL_ERIC_MASK 0x400000u
#define ENET_DMA_CHn_RX_CONTROL_ERIC_SHIFT 22u
#define ENET_DMA_CHn_RX_CONTROL_ERIC_WIDTH 1u
#define ENET_DMA_CHn_RX_CONTROL_ERIC(x) (((uint32_t)(((uint32_t)(x))<<ENET_DMA_CHn_RX_CONTROL_ERIC_SHIFT))&ENET_DMA_CHn_RX_CONTROL_ERIC_MASK)
#define ENET_DMA_CHn_RX_CONTROL_RXPBL_MASK 0x3F0000u
#define ENET_DMA_CHn_RX_CONTROL_RXPBL_SHIFT 16u
#define ENET_DMA_CHn_RX_CONTROL_RXPBL_WIDTH 6u
#define ENET_DMA_CHn_RX_CONTROL_RXPBL(x) (((uint32_t)(((uint32_t)(x))<<ENET_DMA_CHn_RX_CONTROL_RXPBL_SHIFT))&ENET_DMA_CHn_RX_CONTROL_RXPBL_MASK)
#define ENET_DMA_CHn_RX_CONTROL_RBSZ_13_Y_MASK 0x7FF8u
#define ENET_DMA_CHn_RX_CONTROL_RBSZ_13_Y_SHIFT 3u
#define ENET_DMA_CHn_RX_CONTROL_RBSZ_13_Y_WIDTH 12u
#define ENET_DMA_CHn_RX_CONTROL_RBSZ_13_Y(x) (((uint32_t)(((uint32_t)(x))<<ENET_DMA_CHn_RX_CONTROL_RBSZ_13_Y_SHIFT))&ENET_DMA_CHn_RX_CONTROL_RBSZ_13_Y_MASK)
#define ENET_DMA_CHn_RX_CONTROL_RBSZ_X_0_MASK 0x6u
#define ENET_DMA_CHn_RX_CONTROL_RBSZ_X_0_SHIFT 1u
#define ENET_DMA_CHn_RX_CONTROL_RBSZ_X_0_WIDTH 2u
#define ENET_DMA_CHn_RX_CONTROL_RBSZ_X_0(x) (((uint32_t)(((uint32_t)(x))<<ENET_DMA_CHn_RX_CONTROL_RBSZ_X_0_SHIFT))&ENET_DMA_CHn_RX_CONTROL_RBSZ_X_0_MASK)
#define ENET_DMA_CHn_RX_CONTROL_SR_MASK 0x1u
#define ENET_DMA_CHn_RX_CONTROL_SR_SHIFT 0u
#define ENET_DMA_CHn_RX_CONTROL_SR_WIDTH 1u
#define ENET_DMA_CHn_RX_CONTROL_SR(x)  (((uint32_t)(((uint32_t)(x))<<ENET_DMA_CHn_RX_CONTROL_SR_SHIFT))&ENET_DMA_CHn_RX_CONTROL_SR_MASK)
/* DMA_CH0_RX_CONTROL Reg Mask */
#define ENET_DMA_CHn_RX_CONTROL_MASK   0x807F7FFFu

/* DMA_CHn_TXDESC_LIST_ADDRESS Bit Fields */
#define ENET_DMA_CHn_TXDESC_LIST_ADDRESS_TDESLA_MASK 0xFFFFFFFCu
#define ENET_DMA_CHn_TXDESC_LIST_ADDRESS_TDESLA_SHIFT 2u
#define ENET_DMA_CHn_TXDESC_LIST_ADDRESS_TDESLA_WIDTH 30u
#define ENET_DMA_CHn_TXDESC_LIST_ADDRESS_TDESLA(x) (((uint32_t)(((uint32_t)(x))<<ENET_DMA_CHn_TXDESC_LIST_ADDRESS_TDESLA_SHIFT))&ENET_DMA_CHn_TXDESC_LIST_ADDRESS_TDESLA_MASK)
/* DMA_CH0_TXDESC_LIST_ADDRESS Reg Mask */
#define ENET_DMA_CHn_TXDESC_LIST_ADDRESS_MASK 0xFFFFFFFCu

/* DMA_CHn_RXDESC_LIST_ADDRESS Bit Fields */
#define ENET_DMA_CHn_RXDESC_LIST_ADDRESS_RDESLA_MASK 0xFFFFFFFCu
#define ENET_DMA_CHn_RXDESC_LIST_ADDRESS_RDESLA_SHIFT 2u
#define ENET_DMA_CHn_RXDESC_LIST_ADDRESS_RDESLA_WIDTH 30u
#define ENET_DMA_CHn_RXDESC_LIST_ADDRESS_RDESLA(x) (((uint32_t)(((uint32_t)(x))<<ENET_DMA_CHn_RXDESC_LIST_ADDRESS_RDESLA_SHIFT))&ENET_DMA_CHn_RXDESC_LIST_ADDRESS_RDESLA_MASK)
/* DMA_CH0_RXDESC_LIST_ADDRESS Reg Mask */
#define ENET_DMA_CHn_RXDESC_LIST_ADDRESS_MASK 0xFFFFFFFCu

/* DMA_CHn_TXDESC_TAIL_POINTER Bit Fields */
#define ENET_DMA_CHn_TXDESC_TAIL_POINTER_TDTP_MASK 0xFFFFFFFCu
#define ENET_DMA_CHn_TXDESC_TAIL_POINTER_TDTP_SHIFT 2u
#define ENET_DMA_CHn_TXDESC_TAIL_POINTER_TDTP_WIDTH 30u
#define ENET_DMA_CHn_TXDESC_TAIL_POINTER_TDTP(x) (((uint32_t)(((uint32_t)(x))<<ENET_DMA_CHn_TXDESC_TAIL_POINTER_TDTP_SHIFT))&ENET_DMA_CHn_TXDESC_TAIL_POINTER_TDTP_MASK)
/* DMA_CH0_TXDESC_TAIL_POINTER Reg Mask */
#define ENET_DMA_CHn_TXDESC_TAIL_POINTER_MASK 0xFFFFFFFCu

/* DMA_CHn_RXDESC_TAIL_POINTER Bit Fields */
#define ENET_DMA_CHn_RXDESC_TAIL_POINTER_RDTP_MASK 0xFFFFFFFCu
#define ENET_DMA_CHn_RXDESC_TAIL_POINTER_RDTP_SHIFT 2u
#define ENET_DMA_CHn_RXDESC_TAIL_POINTER_RDTP_WIDTH 30u
#define ENET_DMA_CHn_RXDESC_TAIL_POINTER_RDTP(x) (((uint32_t)(((uint32_t)(x))<<ENET_DMA_CHn_RXDESC_TAIL_POINTER_RDTP_SHIFT))&ENET_DMA_CHn_RXDESC_TAIL_POINTER_RDTP_MASK)
/* DMA_CH0_RXDESC_TAIL_POINTER Reg Mask */
#define ENET_DMA_CHn_RXDESC_TAIL_POINTER_MASK 0xFFFFFFFCu

/* DMA_CHn_TXDESC_RING_LENGTH Bit Fields */
#define ENET_DMA_CHn_TXDESC_RING_LENGTH_TDRL_MASK 0x3FFu
#define ENET_DMA_CHn_TXDESC_RING_LENGTH_TDRL_SHIFT 0u
#define ENET_DMA_CHn_TXDESC_RING_LENGTH_TDRL_WIDTH 10u
#define ENET_DMA_CHn_TXDESC_RING_LENGTH_TDRL(x) (((uint32_t)(((uint32_t)(x))<<ENET_DMA_CHn_TXDESC_RING_LENGTH_TDRL_SHIFT))&ENET_DMA_CHn_TXDESC_RING_LENGTH_TDRL_MASK)
/* DMA_CH0_TXDESC_RING_LENGTH Reg Mask */
#define ENET_DMA_CHn_TXDESC_RING_LENGTH_MASK 0x000003FFu

/* DMA_CHn_RX_CONTROL2 Bit Fields */
#define ENET_DMA_CHn_RX_CONTROL2_ARBS_MASK 0xFF0000u
#define ENET_DMA_CHn_RX_CONTROL2_ARBS_SHIFT 16u
#define ENET_DMA_CHn_RX_CONTROL2_ARBS_WIDTH 8u
#define ENET_DMA_CHn_RX_CONTROL2_ARBS(x) (((uint32_t)(((uint32_t)(x))<<ENET_DMA_CHn_RX_CONTROL2_ARBS_SHIFT))&ENET_DMA_CHn_RX_CONTROL2_ARBS_MASK)
#define ENET_DMA_CHn_RX_CONTROL2_RDRL_MASK 0x3FFu
#define ENET_DMA_CHn_RX_CONTROL2_RDRL_SHIFT 0u
#define ENET_DMA_CHn_RX_CONTROL2_RDRL_WIDTH 10u
#define ENET_DMA_CHn_RX_CONTROL2_RDRL(x) (((uint32_t)(((uint32_t)(x))<<ENET_DMA_CHn_RX_CONTROL2_RDRL_SHIFT))&ENET_DMA_CHn_RX_CONTROL2_RDRL_MASK)
/* DMA_CH0_RX_CONTROL2 Reg Mask */
#define ENET_DMA_CHn_RX_CONTROL2_MASK  0x00FF03FFu

/* DMA_CHn_INTERRUPT_ENABLE Bit Fields */
#define ENET_DMA_CHn_INTERRUPT_ENABLE_NIE_MASK 0x8000u
#define ENET_DMA_CHn_INTERRUPT_ENABLE_NIE_SHIFT 15u
#define ENET_DMA_CHn_INTERRUPT_ENABLE_NIE_WIDTH 1u
#define ENET_DMA_CHn_INTERRUPT_ENABLE_NIE(x) (((uint32_t)(((uint32_t)(x))<<ENET_DMA_CHn_INTERRUPT_ENABLE_NIE_SHIFT))&ENET_DMA_CHn_INTERRUPT_ENABLE_NIE_MASK)
#define ENET_DMA_CHn_INTERRUPT_ENABLE_AIE_MASK 0x4000u
#define ENET_DMA_CHn_INTERRUPT_ENABLE_AIE_SHIFT 14u
#define ENET_DMA_CHn_INTERRUPT_ENABLE_AIE_WIDTH 1u
#define ENET_DMA_CHn_INTERRUPT_ENABLE_AIE(x) (((uint32_t)(((uint32_t)(x))<<ENET_DMA_CHn_INTERRUPT_ENABLE_AIE_SHIFT))&ENET_DMA_CHn_INTERRUPT_ENABLE_AIE_MASK)
#define ENET_DMA_CHn_INTERRUPT_ENABLE_CDEE_MASK 0x2000u
#define ENET_DMA_CHn_INTERRUPT_ENABLE_CDEE_SHIFT 13u
#define ENET_DMA_CHn_INTERRUPT_ENABLE_CDEE_WIDTH 1u
#define ENET_DMA_CHn_INTERRUPT_ENABLE_CDEE(x) (((uint32_t)(((uint32_t)(x))<<ENET_DMA_CHn_INTERRUPT_ENABLE_CDEE_SHIFT))&ENET_DMA_CHn_INTERRUPT_ENABLE_CDEE_MASK)
#define ENET_DMA_CHn_INTERRUPT_ENABLE_FBEE_MASK 0x1000u
#define ENET_DMA_CHn_INTERRUPT_ENABLE_FBEE_SHIFT 12u
#define ENET_DMA_CHn_INTERRUPT_ENABLE_FBEE_WIDTH 1u
#define ENET_DMA_CHn_INTERRUPT_ENABLE_FBEE(x) (((uint32_t)(((uint32_t)(x))<<ENET_DMA_CHn_INTERRUPT_ENABLE_FBEE_SHIFT))&ENET_DMA_CHn_INTERRUPT_ENABLE_FBEE_MASK)
#define ENET_DMA_CHn_INTERRUPT_ENABLE_ERIE_MASK 0x800u
#define ENET_DMA_CHn_INTERRUPT_ENABLE_ERIE_SHIFT 11u
#define ENET_DMA_CHn_INTERRUPT_ENABLE_ERIE_WIDTH 1u
#define ENET_DMA_CHn_INTERRUPT_ENABLE_ERIE(x) (((uint32_t)(((uint32_t)(x))<<ENET_DMA_CHn_INTERRUPT_ENABLE_ERIE_SHIFT))&ENET_DMA_CHn_INTERRUPT_ENABLE_ERIE_MASK)
#define ENET_DMA_CHn_INTERRUPT_ENABLE_ETIE_MASK 0x400u
#define ENET_DMA_CHn_INTERRUPT_ENABLE_ETIE_SHIFT 10u
#define ENET_DMA_CHn_INTERRUPT_ENABLE_ETIE_WIDTH 1u
#define ENET_DMA_CHn_INTERRUPT_ENABLE_ETIE(x) (((uint32_t)(((uint32_t)(x))<<ENET_DMA_CHn_INTERRUPT_ENABLE_ETIE_SHIFT))&ENET_DMA_CHn_INTERRUPT_ENABLE_ETIE_MASK)
#define ENET_DMA_CHn_INTERRUPT_ENABLE_RWTE_MASK 0x200u
#define ENET_DMA_CHn_INTERRUPT_ENABLE_RWTE_SHIFT 9u
#define ENET_DMA_CHn_INTERRUPT_ENABLE_RWTE_WIDTH 1u
#define ENET_DMA_CHn_INTERRUPT_ENABLE_RWTE(x) (((uint32_t)(((uint32_t)(x))<<ENET_DMA_CHn_INTERRUPT_ENABLE_RWTE_SHIFT))&ENET_DMA_CHn_INTERRUPT_ENABLE_RWTE_MASK)
#define ENET_DMA_CHn_INTERRUPT_ENABLE_RSE_MASK 0x100u
#define ENET_DMA_CHn_INTERRUPT_ENABLE_RSE_SHIFT 8u
#define ENET_DMA_CHn_INTERRUPT_ENABLE_RSE_WIDTH 1u
#define ENET_DMA_CHn_INTERRUPT_ENABLE_RSE(x) (((uint32_t)(((uint32_t)(x))<<ENET_DMA_CHn_INTERRUPT_ENABLE_RSE_SHIFT))&ENET_DMA_CHn_INTERRUPT_ENABLE_RSE_MASK)
#define ENET_DMA_CHn_INTERRUPT_ENABLE_RBUE_MASK 0x80u
#define ENET_DMA_CHn_INTERRUPT_ENABLE_RBUE_SHIFT 7u
#define ENET_DMA_CHn_INTERRUPT_ENABLE_RBUE_WIDTH 1u
#define ENET_DMA_CHn_INTERRUPT_ENABLE_RBUE(x) (((uint32_t)(((uint32_t)(x))<<ENET_DMA_CHn_INTERRUPT_ENABLE_RBUE_SHIFT))&ENET_DMA_CHn_INTERRUPT_ENABLE_RBUE_MASK)
#define ENET_DMA_CHn_INTERRUPT_ENABLE_RIE_MASK 0x40u
#define ENET_DMA_CHn_INTERRUPT_ENABLE_RIE_SHIFT 6u
#define ENET_DMA_CHn_INTERRUPT_ENABLE_RIE_WIDTH 1u
#define ENET_DMA_CHn_INTERRUPT_ENABLE_RIE(x) (((uint32_t)(((uint32_t)(x))<<ENET_DMA_CHn_INTERRUPT_ENABLE_RIE_SHIFT))&ENET_DMA_CHn_INTERRUPT_ENABLE_RIE_MASK)
#define ENET_DMA_CHn_INTERRUPT_ENABLE_TBUE_MASK 0x4u
#define ENET_DMA_CHn_INTERRUPT_ENABLE_TBUE_SHIFT 2u
#define ENET_DMA_CHn_INTERRUPT_ENABLE_TBUE_WIDTH 1u
#define ENET_DMA_CHn_INTERRUPT_ENABLE_TBUE(x) (((uint32_t)(((uint32_t)(x))<<ENET_DMA_CHn_INTERRUPT_ENABLE_TBUE_SHIFT))&ENET_DMA_CHn_INTERRUPT_ENABLE_TBUE_MASK)
#define ENET_DMA_CHn_INTERRUPT_ENABLE_TXSE_MASK 0x2u
#define ENET_DMA_CHn_INTERRUPT_ENABLE_TXSE_SHIFT 1u
#define ENET_DMA_CHn_INTERRUPT_ENABLE_TXSE_WIDTH 1u
#define ENET_DMA_CHn_INTERRUPT_ENABLE_TXSE(x) (((uint32_t)(((uint32_t)(x))<<ENET_DMA_CHn_INTERRUPT_ENABLE_TXSE_SHIFT))&ENET_DMA_CHn_INTERRUPT_ENABLE_TXSE_MASK)
#define ENET_DMA_CHn_INTERRUPT_ENABLE_TIE_MASK 0x1u
#define ENET_DMA_CHn_INTERRUPT_ENABLE_TIE_SHIFT 0u
#define ENET_DMA_CHn_INTERRUPT_ENABLE_TIE_WIDTH 1u
#define ENET_DMA_CHn_INTERRUPT_ENABLE_TIE(x) (((uint32_t)(((uint32_t)(x))<<ENET_DMA_CHn_INTERRUPT_ENABLE_TIE_SHIFT))&ENET_DMA_CHn_INTERRUPT_ENABLE_TIE_MASK)
/* DMA_CH0_INTERRUPT_ENABLE Reg Mask */
#define ENET_DMA_CHn_INTERRUPT_ENABLE_MASK 0x0000FFC7u

/* DMA_CHn_RX_INTERRUPT_WATCHDOG_TIMER Bit Fields */
#define ENET_DMA_CHn_RX_INTERRUPT_WATCHDOG_TIMER_RWTU_MASK 0x30000u
#define ENET_DMA_CHn_RX_INTERRUPT_WATCHDOG_TIMER_RWTU_SHIFT 16u
#define ENET_DMA_CHn_RX_INTERRUPT_WATCHDOG_TIMER_RWTU_WIDTH 2u
#define ENET_DMA_CHn_RX_INTERRUPT_WATCHDOG_TIMER_RWTU(x) (((uint32_t)(((uint32_t)(x))<<ENET_DMA_CHn_RX_INTERRUPT_WATCHDOG_TIMER_RWTU_SHIFT))&ENET_DMA_CHn_RX_INTERRUPT_WATCHDOG_TIMER_RWTU_MASK)
#define ENET_DMA_CHn_RX_INTERRUPT_WATCHDOG_TIMER_RWT_MASK 0xFFu
#define ENET_DMA_CHn_RX_INTERRUPT_WATCHDOG_TIMER_RWT_SHIFT 0u
#define ENET_DMA_CHn_RX_INTERRUPT_WATCHDOG_TIMER_RWT_WIDTH 8u
#define ENET_DMA_CHn_RX_INTERRUPT_WATCHDOG_TIMER_RWT(x) (((uint32_t)(((uint32_t)(x))<<ENET_DMA_CHn_RX_INTERRUPT_WATCHDOG_TIMER_RWT_SHIFT))&ENET_DMA_CHn_RX_INTERRUPT_WATCHDOG_TIMER_RWT_MASK)
/* DMA_CH0_RX_INTERRUPT_WATCHDOG_TIMER Reg Mask */
#define ENET_DMA_CHn_RX_INTERRUPT_WATCHDOG_TIMER_MASK 0x000300FFu

/* DMA_CHn_SLOT_FUNCTION_CONTROL_STATUS Bit Fields */
#define ENET_DMA_CHn_SLOT_FUNCTION_CONTROL_STATUS_RSN_MASK 0xF0000u
#define ENET_DMA_CHn_SLOT_FUNCTION_CONTROL_STATUS_RSN_SHIFT 16u
#define ENET_DMA_CHn_SLOT_FUNCTION_CONTROL_STATUS_RSN_WIDTH 4u
#define ENET_DMA_CHn_SLOT_FUNCTION_CONTROL_STATUS_RSN(x) (((uint32_t)(((uint32_t)(x))<<ENET_DMA_CHn_SLOT_FUNCTION_CONTROL_STATUS_RSN_SHIFT))&ENET_DMA_CHn_SLOT_FUNCTION_CONTROL_STATUS_RSN_MASK)
#define ENET_DMA_CHn_SLOT_FUNCTION_CONTROL_STATUS_SIV_MASK 0xFFF0u
#define ENET_DMA_CHn_SLOT_FUNCTION_CONTROL_STATUS_SIV_SHIFT 4u
#define ENET_DMA_CHn_SLOT_FUNCTION_CONTROL_STATUS_SIV_WIDTH 12u
#define ENET_DMA_CHn_SLOT_FUNCTION_CONTROL_STATUS_SIV(x) (((uint32_t)(((uint32_t)(x))<<ENET_DMA_CHn_SLOT_FUNCTION_CONTROL_STATUS_SIV_SHIFT))&ENET_DMA_CHn_SLOT_FUNCTION_CONTROL_STATUS_SIV_MASK)
#define ENET_DMA_CHn_SLOT_FUNCTION_CONTROL_STATUS_ASC_MASK 0x2u
#define ENET_DMA_CHn_SLOT_FUNCTION_CONTROL_STATUS_ASC_SHIFT 1u
#define ENET_DMA_CHn_SLOT_FUNCTION_CONTROL_STATUS_ASC_WIDTH 1u
#define ENET_DMA_CHn_SLOT_FUNCTION_CONTROL_STATUS_ASC(x) (((uint32_t)(((uint32_t)(x))<<ENET_DMA_CHn_SLOT_FUNCTION_CONTROL_STATUS_ASC_SHIFT))&ENET_DMA_CHn_SLOT_FUNCTION_CONTROL_STATUS_ASC_MASK)
#define ENET_DMA_CHn_SLOT_FUNCTION_CONTROL_STATUS_ESC_MASK 0x1u
#define ENET_DMA_CHn_SLOT_FUNCTION_CONTROL_STATUS_ESC_SHIFT 0u
#define ENET_DMA_CHn_SLOT_FUNCTION_CONTROL_STATUS_ESC_WIDTH 1u
#define ENET_DMA_CHn_SLOT_FUNCTION_CONTROL_STATUS_ESC(x) (((uint32_t)(((uint32_t)(x))<<ENET_DMA_CHn_SLOT_FUNCTION_CONTROL_STATUS_ESC_SHIFT))&ENET_DMA_CHn_SLOT_FUNCTION_CONTROL_STATUS_ESC_MASK)
/* DMA_CH0_SLOT_FUNCTION_CONTROL_STATUS Reg Mask */
#define ENET_DMA_CHn_SLOT_FUNCTION_CONTROL_STATUS_MASK 0x000FFFF3u

/* DMA_CHn_CURRENT_APP_TXDESC Bit Fields */
#define ENET_DMA_CHn_CURRENT_APP_TXDESC_CURTDESAPTR_MASK 0xFFFFFFFFu
#define ENET_DMA_CHn_CURRENT_APP_TXDESC_CURTDESAPTR_SHIFT 0u
#define ENET_DMA_CHn_CURRENT_APP_TXDESC_CURTDESAPTR_WIDTH 32u
#define ENET_DMA_CHn_CURRENT_APP_TXDESC_CURTDESAPTR(x) (((uint32_t)(((uint32_t)(x))<<ENET_DMA_CHn_CURRENT_APP_TXDESC_CURTDESAPTR_SHIFT))&ENET_DMA_CHn_CURRENT_APP_TXDESC_CURTDESAPTR_MASK)
/* DMA_CH0_CURRENT_APP_TXDESC Reg Mask */
#define ENET_DMA_CHn_CURRENT_APP_TXDESC_MASK 0xFFFFFFFFu

/* DMA_CHn_CURRENT_APP_RXDESC Bit Fields */
#define ENET_DMA_CHn_CURRENT_APP_RXDESC_CURRDESAPTR_MASK 0xFFFFFFFFu
#define ENET_DMA_CHn_CURRENT_APP_RXDESC_CURRDESAPTR_SHIFT 0u
#define ENET_DMA_CHn_CURRENT_APP_RXDESC_CURRDESAPTR_WIDTH 32u
#define ENET_DMA_CHn_CURRENT_APP_RXDESC_CURRDESAPTR(x) (((uint32_t)(((uint32_t)(x))<<ENET_DMA_CHn_CURRENT_APP_RXDESC_CURRDESAPTR_SHIFT))&ENET_DMA_CHn_CURRENT_APP_RXDESC_CURRDESAPTR_MASK)
/* DMA_CH0_CURRENT_APP_RXDESC Reg Mask */
#define ENET_DMA_CHn_CURRENT_APP_RXDESC_MASK 0xFFFFFFFFu

/* DMA_CHn_CURRENT_APP_TXBUFFER Bit Fields */
#define ENET_DMA_CHn_CURRENT_APP_TXBUFFER_CURTBUFAPTR_MASK 0xFFFFFFFFu
#define ENET_DMA_CHn_CURRENT_APP_TXBUFFER_CURTBUFAPTR_SHIFT 0u
#define ENET_DMA_CHn_CURRENT_APP_TXBUFFER_CURTBUFAPTR_WIDTH 32u
#define ENET_DMA_CHn_CURRENT_APP_TXBUFFER_CURTBUFAPTR(x) (((uint32_t)(((uint32_t)(x))<<ENET_DMA_CHn_CURRENT_APP_TXBUFFER_CURTBUFAPTR_SHIFT))&ENET_DMA_CHn_CURRENT_APP_TXBUFFER_CURTBUFAPTR_MASK)
/* DMA_CH0_CURRENT_APP_TXBUFFER Reg Mask */
#define ENET_DMA_CHn_CURRENT_APP_TXBUFFER_MASK 0xFFFFFFFFu

/* DMA_CHn_CURRENT_APP_RXBUFFER Bit Fields */
#define ENET_DMA_CHn_CURRENT_APP_RXBUFFER_CURRBUFAPTR_MASK 0xFFFFFFFFu
#define ENET_DMA_CHn_CURRENT_APP_RXBUFFER_CURRBUFAPTR_SHIFT 0u
#define ENET_DMA_CHn_CURRENT_APP_RXBUFFER_CURRBUFAPTR_WIDTH 32u
#define ENET_DMA_CHn_CURRENT_APP_RXBUFFER_CURRBUFAPTR(x) (((uint32_t)(((uint32_t)(x))<<ENET_DMA_CHn_CURRENT_APP_RXBUFFER_CURRBUFAPTR_SHIFT))&ENET_DMA_CHn_CURRENT_APP_RXBUFFER_CURRBUFAPTR_MASK)
/* DMA_CH0_CURRENT_APP_RXBUFFER Reg Mask */
#define ENET_DMA_CHn_CURRENT_APP_RXBUFFER_MASK 0xFFFFFFFFu

/* DMA_CHn_STATUS Bit Fields */
#define ENET_DMA_CHn_STATUS_REB_MASK   0x380000u
#define ENET_DMA_CHn_STATUS_REB_SHIFT  19u
#define ENET_DMA_CHn_STATUS_REB_WIDTH  3u
#define ENET_DMA_CHn_STATUS_REB(x)     (((uint32_t)(((uint32_t)(x))<<ENET_DMA_CHn_STATUS_REB_SHIFT))&ENET_DMA_CHn_STATUS_REB_MASK)
#define ENET_DMA_CHn_STATUS_TEB_MASK   0x70000u
#define ENET_DMA_CHn_STATUS_TEB_SHIFT  16u
#define ENET_DMA_CHn_STATUS_TEB_WIDTH  3u
#define ENET_DMA_CHn_STATUS_TEB(x)     (((uint32_t)(((uint32_t)(x))<<ENET_DMA_CHn_STATUS_TEB_SHIFT))&ENET_DMA_CHn_STATUS_TEB_MASK)
#define ENET_DMA_CHn_STATUS_NIS_MASK   0x8000u
#define ENET_DMA_CHn_STATUS_NIS_SHIFT  15u
#define ENET_DMA_CHn_STATUS_NIS_WIDTH  1u
#define ENET_DMA_CHn_STATUS_NIS(x)     (((uint32_t)(((uint32_t)(x))<<ENET_DMA_CHn_STATUS_NIS_SHIFT))&ENET_DMA_CHn_STATUS_NIS_MASK)
#define ENET_DMA_CHn_STATUS_AIS_MASK   0x4000u
#define ENET_DMA_CHn_STATUS_AIS_SHIFT  14u
#define ENET_DMA_CHn_STATUS_AIS_WIDTH  1u
#define ENET_DMA_CHn_STATUS_AIS(x)     (((uint32_t)(((uint32_t)(x))<<ENET_DMA_CHn_STATUS_AIS_SHIFT))&ENET_DMA_CHn_STATUS_AIS_MASK)
#define ENET_DMA_CHn_STATUS_CDE_MASK   0x2000u
#define ENET_DMA_CHn_STATUS_CDE_SHIFT  13u
#define ENET_DMA_CHn_STATUS_CDE_WIDTH  1u
#define ENET_DMA_CHn_STATUS_CDE(x)     (((uint32_t)(((uint32_t)(x))<<ENET_DMA_CHn_STATUS_CDE_SHIFT))&ENET_DMA_CHn_STATUS_CDE_MASK)
#define ENET_DMA_CHn_STATUS_FBE_MASK   0x1000u
#define ENET_DMA_CHn_STATUS_FBE_SHIFT  12u
#define ENET_DMA_CHn_STATUS_FBE_WIDTH  1u
#define ENET_DMA_CHn_STATUS_FBE(x)     (((uint32_t)(((uint32_t)(x))<<ENET_DMA_CHn_STATUS_FBE_SHIFT))&ENET_DMA_CHn_STATUS_FBE_MASK)
#define ENET_DMA_CHn_STATUS_ERI_MASK   0x800u
#define ENET_DMA_CHn_STATUS_ERI_SHIFT  11u
#define ENET_DMA_CHn_STATUS_ERI_WIDTH  1u
#define ENET_DMA_CHn_STATUS_ERI(x)     (((uint32_t)(((uint32_t)(x))<<ENET_DMA_CHn_STATUS_ERI_SHIFT))&ENET_DMA_CHn_STATUS_ERI_MASK)
#define ENET_DMA_CHn_STATUS_ETI_MASK   0x400u
#define ENET_DMA_CHn_STATUS_ETI_SHIFT  10u
#define ENET_DMA_CHn_STATUS_ETI_WIDTH  1u
#define ENET_DMA_CHn_STATUS_ETI(x)     (((uint32_t)(((uint32_t)(x))<<ENET_DMA_CHn_STATUS_ETI_SHIFT))&ENET_DMA_CHn_STATUS_ETI_MASK)
#define ENET_DMA_CHn_STATUS_RWT_MASK   0x200u
#define ENET_DMA_CHn_STATUS_RWT_SHIFT  9u
#define ENET_DMA_CHn_STATUS_RWT_WIDTH  1u
#define ENET_DMA_CHn_STATUS_RWT(x)     (((uint32_t)(((uint32_t)(x))<<ENET_DMA_CHn_STATUS_RWT_SHIFT))&ENET_DMA_CHn_STATUS_RWT_MASK)
#define ENET_DMA_CHn_STATUS_RPS_MASK   0x100u
#define ENET_DMA_CHn_STATUS_RPS_SHIFT  8u
#define ENET_DMA_CHn_STATUS_RPS_WIDTH  1u
#define ENET_DMA_CHn_STATUS_RPS(x)     (((uint32_t)(((uint32_t)(x))<<ENET_DMA_CHn_STATUS_RPS_SHIFT))&ENET_DMA_CHn_STATUS_RPS_MASK)
#define ENET_DMA_CHn_STATUS_RBU_MASK   0x80u
#define ENET_DMA_CHn_STATUS_RBU_SHIFT  7u
#define ENET_DMA_CHn_STATUS_RBU_WIDTH  1u
#define ENET_DMA_CHn_STATUS_RBU(x)     (((uint32_t)(((uint32_t)(x))<<ENET_DMA_CHn_STATUS_RBU_SHIFT))&ENET_DMA_CHn_STATUS_RBU_MASK)
#define ENET_DMA_CHn_STATUS_RI_MASK    0x40u
#define ENET_DMA_CHn_STATUS_RI_SHIFT   6u
#define ENET_DMA_CHn_STATUS_RI_WIDTH   1u
#define ENET_DMA_CHn_STATUS_RI(x)      (((uint32_t)(((uint32_t)(x))<<ENET_DMA_CHn_STATUS_RI_SHIFT))&ENET_DMA_CHn_STATUS_RI_MASK)
#define ENET_DMA_CHn_STATUS_TBU_MASK   0x4u
#define ENET_DMA_CHn_STATUS_TBU_SHIFT  2u
#define ENET_DMA_CHn_STATUS_TBU_WIDTH  1u
#define ENET_DMA_CHn_STATUS_TBU(x)     (((uint32_t)(((uint32_t)(x))<<ENET_DMA_CHn_STATUS_TBU_SHIFT))&ENET_DMA_CHn_STATUS_TBU_MASK)
#define ENET_DMA_CHn_STATUS_TPS_MASK   0x2u
#define ENET_DMA_CHn_STATUS_TPS_SHIFT  1u
#define ENET_DMA_CHn_STATUS_TPS_WIDTH  1u
#define ENET_DMA_CHn_STATUS_TPS(x)     (((uint32_t)(((uint32_t)(x))<<ENET_DMA_CHn_STATUS_TPS_SHIFT))&ENET_DMA_CHn_STATUS_TPS_MASK)
#define ENET_DMA_CHn_STATUS_TI_MASK    0x1u
#define ENET_DMA_CHn_STATUS_TI_SHIFT   0u
#define ENET_DMA_CHn_STATUS_TI_WIDTH   1u
#define ENET_DMA_CHn_STATUS_TI(x)      (((uint32_t)(((uint32_t)(x))<<ENET_DMA_CHn_STATUS_TI_SHIFT))&ENET_DMA_CHn_STATUS_TI_MASK)
/* DMA_CH0_STATUS Reg Mask */
#define ENET_DMA_CHn_STATUS_MASK       0x003FFFC7u

/* DMA_CHn_MISS_FRAME_CNT Bit Fields */
#define ENET_DMA_CHn_MISS_FRAME_CNT_MFCO_MASK 0x8000u
#define ENET_DMA_CHn_MISS_FRAME_CNT_MFCO_SHIFT 15u
#define ENET_DMA_CHn_MISS_FRAME_CNT_MFCO_WIDTH 1u
#define ENET_DMA_CHn_MISS_FRAME_CNT_MFCO(x) (((uint32_t)(((uint32_t)(x))<<ENET_DMA_CHn_MISS_FRAME_CNT_MFCO_SHIFT))&ENET_DMA_CHn_MISS_FRAME_CNT_MFCO_MASK)
#define ENET_DMA_CHn_MISS_FRAME_CNT_MFC_MASK 0x7FFu
#define ENET_DMA_CHn_MISS_FRAME_CNT_MFC_SHIFT 0u
#define ENET_DMA_CHn_MISS_FRAME_CNT_MFC_WIDTH 11u
#define ENET_DMA_CHn_MISS_FRAME_CNT_MFC(x) (((uint32_t)(((uint32_t)(x))<<ENET_DMA_CHn_MISS_FRAME_CNT_MFC_SHIFT))&ENET_DMA_CHn_MISS_FRAME_CNT_MFC_MASK)
/* DMA_CH0_MISS_FRAME_CNT Reg Mask */
#define ENET_DMA_CHn_MISS_FRAME_CNT_MASK 0x000087FFu

/* DMA_CHn_RXP_ACCEPT_CNT Bit Fields */
#define ENET_DMA_CHn_RXP_ACCEPT_CNT_RXPACOF_MASK 0x80000000u
#define ENET_DMA_CHn_RXP_ACCEPT_CNT_RXPACOF_SHIFT 31u
#define ENET_DMA_CHn_RXP_ACCEPT_CNT_RXPACOF_WIDTH 1u
#define ENET_DMA_CHn_RXP_ACCEPT_CNT_RXPACOF(x) (((uint32_t)(((uint32_t)(x))<<ENET_DMA_CHn_RXP_ACCEPT_CNT_RXPACOF_SHIFT))&ENET_DMA_CHn_RXP_ACCEPT_CNT_RXPACOF_MASK)
#define ENET_DMA_CHn_RXP_ACCEPT_CNT_RXPAC_MASK 0x7FFFFFFFu
#define ENET_DMA_CHn_RXP_ACCEPT_CNT_RXPAC_SHIFT 0u
#define ENET_DMA_CHn_RXP_ACCEPT_CNT_RXPAC_WIDTH 31u
#define ENET_DMA_CHn_RXP_ACCEPT_CNT_RXPAC(x) (((uint32_t)(((uint32_t)(x))<<ENET_DMA_CHn_RXP_ACCEPT_CNT_RXPAC_SHIFT))&ENET_DMA_CHn_RXP_ACCEPT_CNT_RXPAC_MASK)
/* DMA_CH0_RXP_ACCEPT_CNT Reg Mask */
#define ENET_DMA_CHn_RXP_ACCEPT_CNT_MASK 0xFFFFFFFFu

/* DMA_CHn_RX_ERI_CNT Bit Fields */
#define ENET_DMA_CHn_RX_ERI_CNT_ECNT_MASK 0xFFFu
#define ENET_DMA_CHn_RX_ERI_CNT_ECNT_SHIFT 0u
#define ENET_DMA_CHn_RX_ERI_CNT_ECNT_WIDTH 12u
#define ENET_DMA_CHn_RX_ERI_CNT_ECNT(x) (((uint32_t)(((uint32_t)(x))<<ENET_DMA_CHn_RX_ERI_CNT_ECNT_SHIFT))&ENET_DMA_CHn_RX_ERI_CNT_ECNT_MASK)
/* DMA_CH0_RX_ERI_CNT Reg Mask */
#define ENET_DMA_CHn_RX_ERI_CNT_MASK   0x00000FFFu


/*!
 * @}
 */ /* end of group ENET_Register_Masks */

/*!
 * @}
 */ /* end of group ENET_Peripheral_Access_Layer */

#endif
