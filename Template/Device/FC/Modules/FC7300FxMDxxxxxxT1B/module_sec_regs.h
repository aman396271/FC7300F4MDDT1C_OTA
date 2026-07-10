#ifndef _MODULE_SEC_gmbhdijq283_REGS_H_SEC_H_
#define _MODULE_SEC_gmbhdijq283_REGS_H_SEC_H_

/* ----------------------------------------------------------------------------
   -- SEC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SEC_Peripheral_Access_Layer SEC Peripheral Access Layer
 * @{
 */

/** SEC - Size of Registers Arrays */

/** SEC - Register Layout Typedef */
#define SEC_DEK_COUNT 4

typedef struct {

  __IO uint32_t DEN                           ; /* Debug Enable Register, offset: 0x0 */
  __I  uint32_t FSEC0                         ; /* System Security Control Register0, offset: 0x4 */
  __I  uint32_t FSEC1                         ; /* System Security Control Register1, offset: 0x8 */
  __IO uint32_t DCWOR                         ; /* Debug Control Write Once Register, offset: 0xC */
  __O  uint32_t DEK[SEC_DEK_COUNT]            ; /* Debug Re-Enable Key Register, offset: 0x10 */
  __IO uint32_t TME                           ; /* Test Mode Enable Register, offset: 0x20 */
  __IO uint32_t TMEA                          ; /* Test Mode Re-Enable Allow Register, offset: 0x24 */
  __O  uint32_t TMEK                          ; /* Test Mode Re-Enable Key Register, offset: 0x28 */
       uint8_t  RESERVED_0[4];
  __IO uint32_t FCR0                          ; /* Flash Control Register0, offset: 0x30 */
       uint8_t  RESERVED_1[44];
  __I  uint32_t BCS                           ; /* Boot Configuration Status Register, offset: 0x60 */
  __I  uint32_t UKAC                          ; /* User Key Access Configuration Register, offset: 0x64 */
  __I  uint32_t BRC0                          ; /* BootROM Configuration Register0, offset: 0x68 */
  __I  uint32_t BRC1                          ; /* BootROM Configuration Register1, offset: 0x6C */
  __I  uint32_t FWA                           ; /* HSM Firmware Address Register, offset: 0x70 */
  __I  uint32_t BRC2                          ; /* BootROM Configuration Register2, offset: 0x74 */
  __I  uint32_t IMGEA                         ; /* Image Address Register, offset: 0x78 */
       uint8_t  RESERVED_2[12];
  __I  uint32_t LCSTAT                        ; /* Lifecycle Status Register, offset: 0x88 */
  __I  uint32_t FAC                           ; /* Flash Access Control Register, offset: 0x8C */

} SEC_Type, *SEC_MemMapPtr;


/* SEC - Peripheral instance base addresses */
/** Peripheral SEC base address */
#define SEC_BASE                                 (0x40014000u)
/** Peripheral SEC base pointer */
#define SEC                                      ((SEC_Type *)SEC_BASE)
// need fill by yourself
///** Number of interrupt vector arrays for the SEC module. */
//#define SEC_IRQS_ARR_COUNT                       (1u)
///** Number of interrupt channels for the SEC module. */
//#define SEC_IRQS_CH_COUNT                        (1u)
///** Interrupt vectors for the SEC peripheral type */
//#define SEC_IRQS                                 {SEC_IRQn}


/* ----------------------------------------------------------------------------
   -- SEC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SEC_Register_Masks SEC Register Masks
 * @{
 */

/* DEN Bit Fields */
#define SEC_DEN_DEN_MASK               0xFu
#define SEC_DEN_DEN_SHIFT              0u
#define SEC_DEN_DEN_WIDTH              4u
#define SEC_DEN_DEN(x)                 (((uint32_t)(((uint32_t)(x))<<SEC_DEN_DEN_SHIFT))&SEC_DEN_DEN_MASK)
/* DEN Reg Mask */
#define SEC_DEN_MASK                   0x0000000Fu

/* FSEC0 Bit Fields */
#define SEC_FSEC0_SSC0_MASK            0xFFFFu
#define SEC_FSEC0_SSC0_SHIFT           0u
#define SEC_FSEC0_SSC0_WIDTH           16u
#define SEC_FSEC0_SSC0(x)              (((uint32_t)(((uint32_t)(x))<<SEC_FSEC0_SSC0_SHIFT))&SEC_FSEC0_SSC0_MASK)
/* FSEC0 Reg Mask */
#define SEC_FSEC0_MASK                 0x0000FFFFu

/* FSEC1 Bit Fields */
#define SEC_FSEC1_SSC1_MASK            0xFFFFu
#define SEC_FSEC1_SSC1_SHIFT           0u
#define SEC_FSEC1_SSC1_WIDTH           16u
#define SEC_FSEC1_SSC1(x)              (((uint32_t)(((uint32_t)(x))<<SEC_FSEC1_SSC1_SHIFT))&SEC_FSEC1_SSC1_MASK)
/* FSEC1 Reg Mask */
#define SEC_FSEC1_MASK                 0x0000FFFFu

/* DCWOR Bit Fields */
#define SEC_DCWOR_DEA_MASK             0xFu
#define SEC_DCWOR_DEA_SHIFT            0u
#define SEC_DCWOR_DEA_WIDTH            4u
#define SEC_DCWOR_DEA(x)               (((uint32_t)(((uint32_t)(x))<<SEC_DCWOR_DEA_SHIFT))&SEC_DCWOR_DEA_MASK)
#define SEC_DCWOR_RWL_MASK             0xF0u
#define SEC_DCWOR_RWL_SHIFT            4u
#define SEC_DCWOR_RWL_WIDTH            4u
#define SEC_DCWOR_RWL(x)               (((uint32_t)(((uint32_t)(x))<<SEC_DCWOR_RWL_SHIFT))&SEC_DCWOR_RWL_MASK)
/* DCWOR Reg Mask */
#define SEC_DCWOR_MASK                 0x000000FFu

/* DEK Bit Fields */
#define SEC_DEK_DEK_MASK               0xFFFFFFFFu
#define SEC_DEK_DEK_SHIFT              0u
#define SEC_DEK_DEK_WIDTH              32u
#define SEC_DEK_DEK(x)                 (((uint32_t)(((uint32_t)(x))<<SEC_DEK_DEK_SHIFT))&SEC_DEK_DEK_MASK)
/* DEK0 Reg Mask */
#define SEC_DEK_MASK                   0xFFFFFFFFu

/* TME Bit Fields */
#define SEC_TME_TME_MASK               0xFu
#define SEC_TME_TME_SHIFT              0u
#define SEC_TME_TME_WIDTH              4u
#define SEC_TME_TME(x)                 (((uint32_t)(((uint32_t)(x))<<SEC_TME_TME_SHIFT))&SEC_TME_TME_MASK)
/* TME Reg Mask */
#define SEC_TME_MASK                   0x0000000Fu

/* TMEA Bit Fields */
#define SEC_TMEA_TMEA_MASK             0xFu
#define SEC_TMEA_TMEA_SHIFT            0u
#define SEC_TMEA_TMEA_WIDTH            4u
#define SEC_TMEA_TMEA(x)               (((uint32_t)(((uint32_t)(x))<<SEC_TMEA_TMEA_SHIFT))&SEC_TMEA_TMEA_MASK)
/* TMEA Reg Mask */
#define SEC_TMEA_MASK                  0x0000000Fu

/* TMEK Bit Fields */
#define SEC_TMEK_TMEK_MASK             0xFFFFFFFFu
#define SEC_TMEK_TMEK_SHIFT            0u
#define SEC_TMEK_TMEK_WIDTH            32u
#define SEC_TMEK_TMEK(x)               (((uint32_t)(((uint32_t)(x))<<SEC_TMEK_TMEK_SHIFT))&SEC_TMEK_TMEK_MASK)
/* TMEK Reg Mask */
#define SEC_TMEK_MASK                  0xFFFFFFFFu

/* FCR0 Bit Fields */
#define SEC_FCR0_MED_MASK              0xFu
#define SEC_FCR0_MED_SHIFT             0u
#define SEC_FCR0_MED_WIDTH             4u
#define SEC_FCR0_MED(x)                (((uint32_t)(((uint32_t)(x))<<SEC_FCR0_MED_SHIFT))&SEC_FCR0_MED_MASK)
#define SEC_FCR0_NRP_MASK              0xF0u
#define SEC_FCR0_NRP_SHIFT             4u
#define SEC_FCR0_NRP_WIDTH             4u
#define SEC_FCR0_NRP(x)                (((uint32_t)(((uint32_t)(x))<<SEC_FCR0_NRP_SHIFT))&SEC_FCR0_NRP_MASK)
#define SEC_FCR0_NWP_MASK              0xF00u
#define SEC_FCR0_NWP_SHIFT             8u
#define SEC_FCR0_NWP_WIDTH             4u
#define SEC_FCR0_NWP(x)                (((uint32_t)(((uint32_t)(x))<<SEC_FCR0_NWP_SHIFT))&SEC_FCR0_NWP_MASK)
#define SEC_FCR0_NEP_MASK              0xF000u
#define SEC_FCR0_NEP_SHIFT             12u
#define SEC_FCR0_NEP_WIDTH             4u
#define SEC_FCR0_NEP(x)                (((uint32_t)(((uint32_t)(x))<<SEC_FCR0_NEP_SHIFT))&SEC_FCR0_NEP_MASK)
/* FCR0 Reg Mask */
#define SEC_FCR0_MASK                  0x0000FFFFu

/* BCS Bit Fields */
#define SEC_BCS_FBS_MASK               0x1u
#define SEC_BCS_FBS_SHIFT              0u
#define SEC_BCS_FBS_WIDTH              1u
#define SEC_BCS_FBS(x)                 (((uint32_t)(((uint32_t)(x))<<SEC_BCS_FBS_SHIFT))&SEC_BCS_FBS_MASK)
#define SEC_BCS_NMIDIS_MASK            0x2u
#define SEC_BCS_NMIDIS_SHIFT           1u
#define SEC_BCS_NMIDIS_WIDTH           1u
#define SEC_BCS_NMIDIS(x)              (((uint32_t)(((uint32_t)(x))<<SEC_BCS_NMIDIS_SHIFT))&SEC_BCS_NMIDIS_MASK)
#define SEC_BCS_ISPDIS_MASK            0x4u
#define SEC_BCS_ISPDIS_SHIFT           2u
#define SEC_BCS_ISPDIS_WIDTH           1u
#define SEC_BCS_ISPDIS(x)              (((uint32_t)(((uint32_t)(x))<<SEC_BCS_ISPDIS_SHIFT))&SEC_BCS_ISPDIS_MASK)
#define SEC_BCS_BOOTROM_MASK           0x8u
#define SEC_BCS_BOOTROM_SHIFT          3u
#define SEC_BCS_BOOTROM_WIDTH          1u
#define SEC_BCS_BOOTROM(x)             (((uint32_t)(((uint32_t)(x))<<SEC_BCS_BOOTROM_SHIFT))&SEC_BCS_BOOTROM_MASK)
#define SEC_BCS_ISPMODE_MASK           0x10u
#define SEC_BCS_ISPMODE_SHIFT          4u
#define SEC_BCS_ISPMODE_WIDTH          1u
#define SEC_BCS_ISPMODE(x)             (((uint32_t)(((uint32_t)(x))<<SEC_BCS_ISPMODE_SHIFT))&SEC_BCS_ISPMODE_MASK)
/* BCS Reg Mask */
#define SEC_BCS_MASK                   0x0000001Fu

/* UKAC Bit Fields */
#define SEC_UKAC_UKAE_MASK             0xFu
#define SEC_UKAC_UKAE_SHIFT            0u
#define SEC_UKAC_UKAE_WIDTH            4u
#define SEC_UKAC_UKAE(x)               (((uint32_t)(((uint32_t)(x))<<SEC_UKAC_UKAE_SHIFT))&SEC_UKAC_UKAE_MASK)
/* UKAC Reg Mask */
#define SEC_UKAC_MASK                  0x0000000Fu

/* BRC0 Bit Fields */
#define SEC_BRC0_SECURE_BOOT_DIS_MASK  0xFu
#define SEC_BRC0_SECURE_BOOT_DIS_SHIFT 0u
#define SEC_BRC0_SECURE_BOOT_DIS_WIDTH 4u
#define SEC_BRC0_SECURE_BOOT_DIS(x)    (((uint32_t)(((uint32_t)(x))<<SEC_BRC0_SECURE_BOOT_DIS_SHIFT))&SEC_BRC0_SECURE_BOOT_DIS_MASK)
#define SEC_BRC0_DEBUG_AUTH_EN_MASK    0xF0u
#define SEC_BRC0_DEBUG_AUTH_EN_SHIFT   4u
#define SEC_BRC0_DEBUG_AUTH_EN_WIDTH   4u
#define SEC_BRC0_DEBUG_AUTH_EN(x)      (((uint32_t)(((uint32_t)(x))<<SEC_BRC0_DEBUG_AUTH_EN_SHIFT))&SEC_BRC0_DEBUG_AUTH_EN_MASK)
#define SEC_BRC0_ISP_AUTH_EN_MASK      0xF00u
#define SEC_BRC0_ISP_AUTH_EN_SHIFT     8u
#define SEC_BRC0_ISP_AUTH_EN_WIDTH     4u
#define SEC_BRC0_ISP_AUTH_EN(x)        (((uint32_t)(((uint32_t)(x))<<SEC_BRC0_ISP_AUTH_EN_SHIFT))&SEC_BRC0_ISP_AUTH_EN_MASK)
#define SEC_BRC0_FW_READ_DIS_MASK      0xF000u
#define SEC_BRC0_FW_READ_DIS_SHIFT     12u
#define SEC_BRC0_FW_READ_DIS_WIDTH     4u
#define SEC_BRC0_FW_READ_DIS(x)        (((uint32_t)(((uint32_t)(x))<<SEC_BRC0_FW_READ_DIS_SHIFT))&SEC_BRC0_FW_READ_DIS_MASK)
/* BRC0 Reg Mask */
#define SEC_BRC0_MASK                  0x0000FFFFu

/* BRC1 Bit Fields */
#define SEC_BRC1_FW_VALID_MASK         0xFu
#define SEC_BRC1_FW_VALID_SHIFT        0u
#define SEC_BRC1_FW_VALID_WIDTH        4u
#define SEC_BRC1_FW_VALID(x)           (((uint32_t)(((uint32_t)(x))<<SEC_BRC1_FW_VALID_SHIFT))&SEC_BRC1_FW_VALID_MASK)
#define SEC_BRC1_UARTBR_MASK           0x30u
#define SEC_BRC1_UARTBR_SHIFT          4u
#define SEC_BRC1_UARTBR_WIDTH          2u
#define SEC_BRC1_UARTBR(x)             (((uint32_t)(((uint32_t)(x))<<SEC_BRC1_UARTBR_SHIFT))&SEC_BRC1_UARTBR_MASK)
#define SEC_BRC1_CANBR_MASK            0xC0u
#define SEC_BRC1_CANBR_SHIFT           6u
#define SEC_BRC1_CANBR_WIDTH           2u
#define SEC_BRC1_CANBR(x)              (((uint32_t)(((uint32_t)(x))<<SEC_BRC1_CANBR_SHIFT))&SEC_BRC1_CANBR_MASK)
#define SEC_BRC1_OSCFREQ_MASK          0x700u
#define SEC_BRC1_OSCFREQ_SHIFT         8u
#define SEC_BRC1_OSCFREQ_WIDTH         3u
#define SEC_BRC1_OSCFREQ(x)            (((uint32_t)(((uint32_t)(x))<<SEC_BRC1_OSCFREQ_SHIFT))&SEC_BRC1_OSCFREQ_MASK)
#define SEC_BRC1_OSCA_MASK             0x800u
#define SEC_BRC1_OSCA_SHIFT            11u
#define SEC_BRC1_OSCA_WIDTH            1u
#define SEC_BRC1_OSCA(x)               (((uint32_t)(((uint32_t)(x))<<SEC_BRC1_OSCA_SHIFT))&SEC_BRC1_OSCA_MASK)
#define SEC_BRC1_DBG_MB_BKD_EN_MASK    0xF000u
#define SEC_BRC1_DBG_MB_BKD_EN_SHIFT   12u
#define SEC_BRC1_DBG_MB_BKD_EN_WIDTH   4u
#define SEC_BRC1_DBG_MB_BKD_EN(x)      (((uint32_t)(((uint32_t)(x))<<SEC_BRC1_DBG_MB_BKD_EN_SHIFT))&SEC_BRC1_DBG_MB_BKD_EN_MASK)
#define SEC_BRC1_SW_CFG_ISP_EN_MASK    0x1000000u
#define SEC_BRC1_SW_CFG_ISP_EN_SHIFT   24u
#define SEC_BRC1_SW_CFG_ISP_EN_WIDTH   1u
#define SEC_BRC1_SW_CFG_ISP_EN(x)      (((uint32_t)(((uint32_t)(x))<<SEC_BRC1_SW_CFG_ISP_EN_SHIFT))&SEC_BRC1_SW_CFG_ISP_EN_MASK)
/* BRC1 Reg Mask */
#define SEC_BRC1_MASK                  0x0100FFFFu

/* FWA Bit Fields */
#define SEC_FWA_HSM_FW_ADDR_MASK       0xFFFFFFFFu
#define SEC_FWA_HSM_FW_ADDR_SHIFT      0u
#define SEC_FWA_HSM_FW_ADDR_WIDTH      32u
#define SEC_FWA_HSM_FW_ADDR(x)         (((uint32_t)(((uint32_t)(x))<<SEC_FWA_HSM_FW_ADDR_SHIFT))&SEC_FWA_HSM_FW_ADDR_MASK)
/* FWA Reg Mask */
#define SEC_FWA_MASK                   0xFFFFFFFFu

/* BRC2 Bit Fields */
#define SEC_BRC2_USERCODE_VERIFY_MASK_MASK 0x1FFFFFFu
#define SEC_BRC2_USERCODE_VERIFY_MASK_SHIFT 0u
#define SEC_BRC2_USERCODE_VERIFY_MASK_WIDTH 25u
#define SEC_BRC2_USERCODE_VERIFY_MASK(x) (((uint32_t)(((uint32_t)(x))<<SEC_BRC2_USERCODE_VERIFY_MASK_SHIFT))&SEC_BRC2_USERCODE_VERIFY_MASK_MASK)
#define SEC_BRC2_ISP_INST_SEL_MASK     0xE000000u
#define SEC_BRC2_ISP_INST_SEL_SHIFT    25u
#define SEC_BRC2_ISP_INST_SEL_WIDTH    3u
#define SEC_BRC2_ISP_INST_SEL(x)       (((uint32_t)(((uint32_t)(x))<<SEC_BRC2_ISP_INST_SEL_SHIFT))&SEC_BRC2_ISP_INST_SEL_MASK)
#define SEC_BRC2_USERCODE_VERIFICATION_ALG_MASK 0x70000000u
#define SEC_BRC2_USERCODE_VERIFICATION_ALG_SHIFT 28u
#define SEC_BRC2_USERCODE_VERIFICATION_ALG_WIDTH 3u
#define SEC_BRC2_USERCODE_VERIFICATION_ALG(x) (((uint32_t)(((uint32_t)(x))<<SEC_BRC2_USERCODE_VERIFICATION_ALG_SHIFT))&SEC_BRC2_USERCODE_VERIFICATION_ALG_MASK)
#define SEC_BRC2_DECRP_ALG_MASK        0x80000000u
#define SEC_BRC2_DECRP_ALG_SHIFT       31u
#define SEC_BRC2_DECRP_ALG_WIDTH       1u
#define SEC_BRC2_DECRP_ALG(x)          (((uint32_t)(((uint32_t)(x))<<SEC_BRC2_DECRP_ALG_SHIFT))&SEC_BRC2_DECRP_ALG_MASK)
/* BRC2 Reg Mask */
#define SEC_BRC2_MASK                  0xFFFFFFFFu

/* IMGEA Bit Fields */
#define SEC_IMGEA_IMAGE_ADDR_MASK      0xFFFFFFFFu
#define SEC_IMGEA_IMAGE_ADDR_SHIFT     0u
#define SEC_IMGEA_IMAGE_ADDR_WIDTH     32u
#define SEC_IMGEA_IMAGE_ADDR(x)        (((uint32_t)(((uint32_t)(x))<<SEC_IMGEA_IMAGE_ADDR_SHIFT))&SEC_IMGEA_IMAGE_ADDR_MASK)
/* IMGEA Reg Mask */
#define SEC_IMGEA_MASK                 0xFFFFFFFFu

/* LCSTAT Bit Fields */
#define SEC_LCSTAT_LIFECYCLE_OEM_DEV_MASK 0x1u
#define SEC_LCSTAT_LIFECYCLE_OEM_DEV_SHIFT 0u
#define SEC_LCSTAT_LIFECYCLE_OEM_DEV_WIDTH 1u
#define SEC_LCSTAT_LIFECYCLE_OEM_DEV(x) (((uint32_t)(((uint32_t)(x))<<SEC_LCSTAT_LIFECYCLE_OEM_DEV_SHIFT))&SEC_LCSTAT_LIFECYCLE_OEM_DEV_MASK)
#define SEC_LCSTAT_LIFECYCLE_OEM_PDT_MASK 0x2u
#define SEC_LCSTAT_LIFECYCLE_OEM_PDT_SHIFT 1u
#define SEC_LCSTAT_LIFECYCLE_OEM_PDT_WIDTH 1u
#define SEC_LCSTAT_LIFECYCLE_OEM_PDT(x) (((uint32_t)(((uint32_t)(x))<<SEC_LCSTAT_LIFECYCLE_OEM_PDT_SHIFT))&SEC_LCSTAT_LIFECYCLE_OEM_PDT_MASK)
#define SEC_LCSTAT_LIFECYCLE_IN_FIELD_MASK 0x4u
#define SEC_LCSTAT_LIFECYCLE_IN_FIELD_SHIFT 2u
#define SEC_LCSTAT_LIFECYCLE_IN_FIELD_WIDTH 1u
#define SEC_LCSTAT_LIFECYCLE_IN_FIELD(x) (((uint32_t)(((uint32_t)(x))<<SEC_LCSTAT_LIFECYCLE_IN_FIELD_SHIFT))&SEC_LCSTAT_LIFECYCLE_IN_FIELD_MASK)
#define SEC_LCSTAT_LIFECYCLE_SWFA_MASK 0x8u
#define SEC_LCSTAT_LIFECYCLE_SWFA_SHIFT 3u
#define SEC_LCSTAT_LIFECYCLE_SWFA_WIDTH 1u
#define SEC_LCSTAT_LIFECYCLE_SWFA(x)   (((uint32_t)(((uint32_t)(x))<<SEC_LCSTAT_LIFECYCLE_SWFA_SHIFT))&SEC_LCSTAT_LIFECYCLE_SWFA_MASK)
#define SEC_LCSTAT_LIFECYCLE_HWFA_MASK 0x10u
#define SEC_LCSTAT_LIFECYCLE_HWFA_SHIFT 4u
#define SEC_LCSTAT_LIFECYCLE_HWFA_WIDTH 1u
#define SEC_LCSTAT_LIFECYCLE_HWFA(x)   (((uint32_t)(((uint32_t)(x))<<SEC_LCSTAT_LIFECYCLE_HWFA_SHIFT))&SEC_LCSTAT_LIFECYCLE_HWFA_MASK)
/* LCSTAT Reg Mask */
#define SEC_LCSTAT_MASK                0x0000001Fu

/* FAC Bit Fields */
#define SEC_FAC_HOST_UKEY_RPROT_MASK   0x10000u
#define SEC_FAC_HOST_UKEY_RPROT_SHIFT  16u
#define SEC_FAC_HOST_UKEY_RPROT_WIDTH  1u
#define SEC_FAC_HOST_UKEY_RPROT(x)     (((uint32_t)(((uint32_t)(x))<<SEC_FAC_HOST_UKEY_RPROT_SHIFT))&SEC_FAC_HOST_UKEY_RPROT_MASK)
#define SEC_FAC_HOST_UKEY_WPROT_MASK   0x20000u
#define SEC_FAC_HOST_UKEY_WPROT_SHIFT  17u
#define SEC_FAC_HOST_UKEY_WPROT_WIDTH  1u
#define SEC_FAC_HOST_UKEY_WPROT(x)     (((uint32_t)(((uint32_t)(x))<<SEC_FAC_HOST_UKEY_WPROT_SHIFT))&SEC_FAC_HOST_UKEY_WPROT_MASK)
#define SEC_FAC_HOST_UKEY_EPROT_MASK   0x40000u
#define SEC_FAC_HOST_UKEY_EPROT_SHIFT  18u
#define SEC_FAC_HOST_UKEY_EPROT_WIDTH  1u
#define SEC_FAC_HOST_UKEY_EPROT(x)     (((uint32_t)(((uint32_t)(x))<<SEC_FAC_HOST_UKEY_EPROT_SHIFT))&SEC_FAC_HOST_UKEY_EPROT_MASK)
#define SEC_FAC_HOST_NVR_RPROT_MASK    0x80000u
#define SEC_FAC_HOST_NVR_RPROT_SHIFT   19u
#define SEC_FAC_HOST_NVR_RPROT_WIDTH   1u
#define SEC_FAC_HOST_NVR_RPROT(x)      (((uint32_t)(((uint32_t)(x))<<SEC_FAC_HOST_NVR_RPROT_SHIFT))&SEC_FAC_HOST_NVR_RPROT_MASK)
#define SEC_FAC_HOST_NVR_WPROT_MASK    0x100000u
#define SEC_FAC_HOST_NVR_WPROT_SHIFT   20u
#define SEC_FAC_HOST_NVR_WPROT_WIDTH   1u
#define SEC_FAC_HOST_NVR_WPROT(x)      (((uint32_t)(((uint32_t)(x))<<SEC_FAC_HOST_NVR_WPROT_SHIFT))&SEC_FAC_HOST_NVR_WPROT_MASK)
#define SEC_FAC_HOST_NVR_EPROT_MASK    0x200000u
#define SEC_FAC_HOST_NVR_EPROT_SHIFT   21u
#define SEC_FAC_HOST_NVR_EPROT_WIDTH   1u
#define SEC_FAC_HOST_NVR_EPROT(x)      (((uint32_t)(((uint32_t)(x))<<SEC_FAC_HOST_NVR_EPROT_SHIFT))&SEC_FAC_HOST_NVR_EPROT_MASK)
#define SEC_FAC_HSM_UKEY_EPROT_MASK    0x4000000u
#define SEC_FAC_HSM_UKEY_EPROT_SHIFT   26u
#define SEC_FAC_HSM_UKEY_EPROT_WIDTH   1u
#define SEC_FAC_HSM_UKEY_EPROT(x)      (((uint32_t)(((uint32_t)(x))<<SEC_FAC_HSM_UKEY_EPROT_SHIFT))&SEC_FAC_HSM_UKEY_EPROT_MASK)
#define SEC_FAC_HSM_NVR_EPROT_MASK     0x20000000u
#define SEC_FAC_HSM_NVR_EPROT_SHIFT    29u
#define SEC_FAC_HSM_NVR_EPROT_WIDTH    1u
#define SEC_FAC_HSM_NVR_EPROT(x)       (((uint32_t)(((uint32_t)(x))<<SEC_FAC_HSM_NVR_EPROT_SHIFT))&SEC_FAC_HSM_NVR_EPROT_MASK)
/* FAC Reg Mask */
#define SEC_FAC_MASK                   0x243F0000u


/*!
 * @}
 */ /* end of group SEC_Register_Masks */

/*!
 * @}
 */ /* end of group SEC_Peripheral_Access_Layer */

#endif
