#ifndef _MODULE_ADC_gmbhdijq147_REGS_H_ADC_H_
#define _MODULE_ADC_gmbhdijq147_REGS_H_ADC_H_

/* ----------------------------------------------------------------------------
   -- ADC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ADC_Peripheral_Access_Layer ADC Peripheral Access Layer
 * @{
 */

/** ADC - Size of Registers Arrays */

/** ADC - Register Layout Typedef */
#define ADC_SGCSR_COUNT 4
#define ADC_SC_COUNT 32
#define ADC_RESULT_COUNT 32
#define ADC_ECMP_CTRL_COUNT 2
#define ADC_ECMP_TR_COUNT 2

typedef struct {

  __IO uint32_t INT_STATUS                    ; /* Interrupt Status Register, offset: 0x0 */
  __IO uint32_t INT_ENABLE                    ; /* Interrupt Enable Register, offset: 0x4 */
  __IO uint32_t CONTROL                       ; /* Control Register, offset: 0x8 */
  __IO uint32_t CFG1                          ; /* Configuration1 Register, offset: 0xC */
  __IO uint32_t CFG2                          ; /* Configuration2 Register, offset: 0x10 */
  __IO uint32_t SMPR                          ; /* Sampling Rate Register, offset: 0x14 */
  __IO uint32_t CMP_CTRL                      ; /* Compare Control Register, offset: 0x18 */
  __IO uint32_t CMP_TR                        ; /* Compare Threshold Register, offset: 0x1C */
       uint8_t  RESERVED_0[8];
  __IO uint32_t SGCSR[ADC_SGCSR_COUNT]        ; /* Sequence Group Control and Status Register, offset: 0x28 */
       uint8_t  RESERVED_1[12];
  __IO uint32_t CAL                           ; /* Calibration Register, offset: 0x44 */
  __IO uint32_t CFG3                          ; /* Configuration3 Register, offset: 0x48 */
  __IO uint32_t FIFO_DATA                     ; /* FIFO Data Register, offset: 0x4C */
  __IO uint32_t SC[ADC_SC_COUNT]              ; /* Sequence Configuration Register, offset: 0x50 */
  __IO uint32_t RESULT[ADC_RESULT_COUNT]      ; /* Result Register, offset: 0xd0 */
       uint8_t  RESERVED_2[8];
  __IO uint32_t ECMP_CTRL[ADC_ECMP_CTRL_COUNT]; /* Enhanced Compare Control Register, offset: 0x158 */
       uint8_t  RESERVED_3[28];
  __IO uint32_t ECMP_STATUS                   ; /* Enhanced Compare Status Register, offset: 0x17C */
  __IO uint32_t ECMP_INT_EN                   ; /* Enhanced Compare Interrupt Enable Register, offset: 0x180 */
       uint8_t  RESERVED_4[8];
  __IO uint32_t ECMP_TR[ADC_ECMP_TR_COUNT]    ; /* Enhanced Compare Threshold Register, offset: 0x18c */
       uint8_t  RESERVED_5[124];
  __IO uint32_t FCMP_CTRL                     ; /* Fast Compare Control Register, offset: 0x210 */
  __IO uint32_t FCREF                         ; /* Fast Compare Reference Register, offset: 0x214 */
  __IO uint32_t FCRAMP0                       ; /* Fast Compare Ramp Register 0, offset: 0x218 */
  __IO uint32_t FCRAMP1                       ; /* Fast Compare Ramp Register 1, offset: 0x21C */
  __IO uint32_t FCHYST                        ; /* Fast Compare Hysteresis Register, offset: 0x220 */
  __IO uint32_t FCBFR                         ; /* Fast Compare Boundary Flag Register, offset: 0x224 */

} ADC_Type, *ADC_MemMapPtr;


/* ADC - Peripheral instance base addresses */
/** Peripheral ADC0 base address */
#define ADC0_BASE                                (0x4003b000u)
/** Peripheral ADC0 base pointer */
#define ADC0                                     ((ADC_Type *)ADC0_BASE)
/** Peripheral ADC1 base address */
#define ADC1_BASE                                (0x4003c000u)
/** Peripheral ADC1 base pointer */
#define ADC1                                     ((ADC_Type *)ADC1_BASE)
/** Peripheral ADC2 base address */
#define ADC2_BASE                                (0x40426000u)
/** Peripheral ADC2 base pointer */
#define ADC2                                     ((ADC_Type *)ADC2_BASE)
/** Peripheral ADC3 base address */
#define ADC3_BASE                                (0x40427000u)
/** Peripheral ADC3 base pointer */
#define ADC3                                     ((ADC_Type *)ADC3_BASE)
// need fill by yourself
///** Number of interrupt vector arrays for the ADC module. */
//#define ADC_IRQS_ARR_COUNT                       (1u)
///** Number of interrupt channels for the ADC module. */
//#define ADC_IRQS_CH_COUNT                        (1u)
///** Interrupt vectors for the ADC peripheral type */
//#define ADC_IRQS                                 {ADC0_IRQn, ADC1_IRQn, ADC2_IRQn, ADC3_IRQn}


/* ----------------------------------------------------------------------------
   -- ADC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ADC_Register_Masks ADC Register Masks
 * @{
 */

/* INT_STATUS Bit Fields */
#define ADC_INT_STATUS_TRGERR_MASK     0xF000000u
#define ADC_INT_STATUS_TRGERR_SHIFT    24u
#define ADC_INT_STATUS_TRGERR_WIDTH    4u
#define ADC_INT_STATUS_TRGERR(x)       (((uint32_t)(((uint32_t)(x))<<ADC_INT_STATUS_TRGERR_SHIFT))&ADC_INT_STATUS_TRGERR_MASK)
#define ADC_INT_STATUS_TRG_STATUS_MASK 0xF0000u
#define ADC_INT_STATUS_TRG_STATUS_SHIFT 16u
#define ADC_INT_STATUS_TRG_STATUS_WIDTH 4u
#define ADC_INT_STATUS_TRG_STATUS(x)   (((uint32_t)(((uint32_t)(x))<<ADC_INT_STATUS_TRG_STATUS_SHIFT))&ADC_INT_STATUS_TRG_STATUS_MASK)
#define ADC_INT_STATUS_TRG_PRO_NUM_MASK 0x6000u
#define ADC_INT_STATUS_TRG_PRO_NUM_SHIFT 13u
#define ADC_INT_STATUS_TRG_PRO_NUM_WIDTH 2u
#define ADC_INT_STATUS_TRG_PRO_NUM(x)  (((uint32_t)(((uint32_t)(x))<<ADC_INT_STATUS_TRG_PRO_NUM_SHIFT))&ADC_INT_STATUS_TRG_PRO_NUM_MASK)
#define ADC_INT_STATUS_FCR_F_MASK      0x1000u
#define ADC_INT_STATUS_FCR_F_SHIFT     12u
#define ADC_INT_STATUS_FCR_F_WIDTH     1u
#define ADC_INT_STATUS_FCR_F(x)        (((uint32_t)(((uint32_t)(x))<<ADC_INT_STATUS_FCR_F_SHIFT))&ADC_INT_STATUS_FCR_F_MASK)
#define ADC_INT_STATUS_FCR_R_MASK      0x800u
#define ADC_INT_STATUS_FCR_R_SHIFT     11u
#define ADC_INT_STATUS_FCR_R_WIDTH     1u
#define ADC_INT_STATUS_FCR_R(x)        (((uint32_t)(((uint32_t)(x))<<ADC_INT_STATUS_FCR_R_SHIFT))&ADC_INT_STATUS_FCR_R_MASK)
#define ADC_INT_STATUS_RPCNT_RDY_MASK  0x400u
#define ADC_INT_STATUS_RPCNT_RDY_SHIFT 10u
#define ADC_INT_STATUS_RPCNT_RDY_WIDTH 1u
#define ADC_INT_STATUS_RPCNT_RDY(x)    (((uint32_t)(((uint32_t)(x))<<ADC_INT_STATUS_RPCNT_RDY_SHIFT))&ADC_INT_STATUS_RPCNT_RDY_MASK)
#define ADC_INT_STATUS_FIFO_RDY_MASK   0x100u
#define ADC_INT_STATUS_FIFO_RDY_SHIFT  8u
#define ADC_INT_STATUS_FIFO_RDY_WIDTH  1u
#define ADC_INT_STATUS_FIFO_RDY(x)     (((uint32_t)(((uint32_t)(x))<<ADC_INT_STATUS_FIFO_RDY_SHIFT))&ADC_INT_STATUS_FIFO_RDY_MASK)
#define ADC_INT_STATUS_ACMP_MASK       0x80u
#define ADC_INT_STATUS_ACMP_SHIFT      7u
#define ADC_INT_STATUS_ACMP_WIDTH      1u
#define ADC_INT_STATUS_ACMP(x)         (((uint32_t)(((uint32_t)(x))<<ADC_INT_STATUS_ACMP_SHIFT))&ADC_INT_STATUS_ACMP_MASK)
#define ADC_INT_STATUS_EMPTY_MASK      0x40u
#define ADC_INT_STATUS_EMPTY_SHIFT     6u
#define ADC_INT_STATUS_EMPTY_WIDTH     1u
#define ADC_INT_STATUS_EMPTY(x)        (((uint32_t)(((uint32_t)(x))<<ADC_INT_STATUS_EMPTY_SHIFT))&ADC_INT_STATUS_EMPTY_MASK)
#define ADC_INT_STATUS_FULL_MASK       0x20u
#define ADC_INT_STATUS_FULL_SHIFT      5u
#define ADC_INT_STATUS_FULL_WIDTH      1u
#define ADC_INT_STATUS_FULL(x)         (((uint32_t)(((uint32_t)(x))<<ADC_INT_STATUS_FULL_SHIFT))&ADC_INT_STATUS_FULL_MASK)
#define ADC_INT_STATUS_OVR_MASK        0x10u
#define ADC_INT_STATUS_OVR_SHIFT       4u
#define ADC_INT_STATUS_OVR_WIDTH       1u
#define ADC_INT_STATUS_OVR(x)          (((uint32_t)(((uint32_t)(x))<<ADC_INT_STATUS_OVR_SHIFT))&ADC_INT_STATUS_OVR_MASK)
#define ADC_INT_STATUS_EOSEQ_MASK      0x8u
#define ADC_INT_STATUS_EOSEQ_SHIFT     3u
#define ADC_INT_STATUS_EOSEQ_WIDTH     1u
#define ADC_INT_STATUS_EOSEQ(x)        (((uint32_t)(((uint32_t)(x))<<ADC_INT_STATUS_EOSEQ_SHIFT))&ADC_INT_STATUS_EOSEQ_MASK)
#define ADC_INT_STATUS_EOC_MASK        0x4u
#define ADC_INT_STATUS_EOC_SHIFT       2u
#define ADC_INT_STATUS_EOC_WIDTH       1u
#define ADC_INT_STATUS_EOC(x)          (((uint32_t)(((uint32_t)(x))<<ADC_INT_STATUS_EOC_SHIFT))&ADC_INT_STATUS_EOC_MASK)
#define ADC_INT_STATUS_EOSMP_MASK      0x2u
#define ADC_INT_STATUS_EOSMP_SHIFT     1u
#define ADC_INT_STATUS_EOSMP_WIDTH     1u
#define ADC_INT_STATUS_EOSMP(x)        (((uint32_t)(((uint32_t)(x))<<ADC_INT_STATUS_EOSMP_SHIFT))&ADC_INT_STATUS_EOSMP_MASK)
#define ADC_INT_STATUS_ADRDY_MASK      0x1u
#define ADC_INT_STATUS_ADRDY_SHIFT     0u
#define ADC_INT_STATUS_ADRDY_WIDTH     1u
#define ADC_INT_STATUS_ADRDY(x)        (((uint32_t)(((uint32_t)(x))<<ADC_INT_STATUS_ADRDY_SHIFT))&ADC_INT_STATUS_ADRDY_MASK)
/* INT_STATUS Reg Mask */
#define ADC_INT_STATUS_MASK            0x0F0F7DFFu

/* INT_ENABLE Bit Fields */
#define ADC_INT_ENABLE_FCR_F_IE_MASK   0x2000u
#define ADC_INT_ENABLE_FCR_F_IE_SHIFT  13u
#define ADC_INT_ENABLE_FCR_F_IE_WIDTH  1u
#define ADC_INT_ENABLE_FCR_F_IE(x)     (((uint32_t)(((uint32_t)(x))<<ADC_INT_ENABLE_FCR_F_IE_SHIFT))&ADC_INT_ENABLE_FCR_F_IE_MASK)
#define ADC_INT_ENABLE_FCR_R_IE_MASK   0x1000u
#define ADC_INT_ENABLE_FCR_R_IE_SHIFT  12u
#define ADC_INT_ENABLE_FCR_R_IE_WIDTH  1u
#define ADC_INT_ENABLE_FCR_R_IE(x)     (((uint32_t)(((uint32_t)(x))<<ADC_INT_ENABLE_FCR_R_IE_SHIFT))&ADC_INT_ENABLE_FCR_R_IE_MASK)
#define ADC_INT_ENABLE_RPCNT_RDY_IE_MASK 0x800u
#define ADC_INT_ENABLE_RPCNT_RDY_IE_SHIFT 11u
#define ADC_INT_ENABLE_RPCNT_RDY_IE_WIDTH 1u
#define ADC_INT_ENABLE_RPCNT_RDY_IE(x) (((uint32_t)(((uint32_t)(x))<<ADC_INT_ENABLE_RPCNT_RDY_IE_SHIFT))&ADC_INT_ENABLE_RPCNT_RDY_IE_MASK)
#define ADC_INT_ENABLE_TRGERR_IE_MASK  0x400u
#define ADC_INT_ENABLE_TRGERR_IE_SHIFT 10u
#define ADC_INT_ENABLE_TRGERR_IE_WIDTH 1u
#define ADC_INT_ENABLE_TRGERR_IE(x)    (((uint32_t)(((uint32_t)(x))<<ADC_INT_ENABLE_TRGERR_IE_SHIFT))&ADC_INT_ENABLE_TRGERR_IE_MASK)
#define ADC_INT_ENABLE_FIFO_RDY_IE_MASK 0x100u
#define ADC_INT_ENABLE_FIFO_RDY_IE_SHIFT 8u
#define ADC_INT_ENABLE_FIFO_RDY_IE_WIDTH 1u
#define ADC_INT_ENABLE_FIFO_RDY_IE(x)  (((uint32_t)(((uint32_t)(x))<<ADC_INT_ENABLE_FIFO_RDY_IE_SHIFT))&ADC_INT_ENABLE_FIFO_RDY_IE_MASK)
#define ADC_INT_ENABLE_ACMP_IE_MASK    0x80u
#define ADC_INT_ENABLE_ACMP_IE_SHIFT   7u
#define ADC_INT_ENABLE_ACMP_IE_WIDTH   1u
#define ADC_INT_ENABLE_ACMP_IE(x)      (((uint32_t)(((uint32_t)(x))<<ADC_INT_ENABLE_ACMP_IE_SHIFT))&ADC_INT_ENABLE_ACMP_IE_MASK)
#define ADC_INT_ENABLE_OVRIE_MASK      0x10u
#define ADC_INT_ENABLE_OVRIE_SHIFT     4u
#define ADC_INT_ENABLE_OVRIE_WIDTH     1u
#define ADC_INT_ENABLE_OVRIE(x)        (((uint32_t)(((uint32_t)(x))<<ADC_INT_ENABLE_OVRIE_SHIFT))&ADC_INT_ENABLE_OVRIE_MASK)
#define ADC_INT_ENABLE_EOSEQIE_MASK    0x8u
#define ADC_INT_ENABLE_EOSEQIE_SHIFT   3u
#define ADC_INT_ENABLE_EOSEQIE_WIDTH   1u
#define ADC_INT_ENABLE_EOSEQIE(x)      (((uint32_t)(((uint32_t)(x))<<ADC_INT_ENABLE_EOSEQIE_SHIFT))&ADC_INT_ENABLE_EOSEQIE_MASK)
#define ADC_INT_ENABLE_EOCIE_MASK      0x4u
#define ADC_INT_ENABLE_EOCIE_SHIFT     2u
#define ADC_INT_ENABLE_EOCIE_WIDTH     1u
#define ADC_INT_ENABLE_EOCIE(x)        (((uint32_t)(((uint32_t)(x))<<ADC_INT_ENABLE_EOCIE_SHIFT))&ADC_INT_ENABLE_EOCIE_MASK)
#define ADC_INT_ENABLE_EOSMPIE_MASK    0x2u
#define ADC_INT_ENABLE_EOSMPIE_SHIFT   1u
#define ADC_INT_ENABLE_EOSMPIE_WIDTH   1u
#define ADC_INT_ENABLE_EOSMPIE(x)      (((uint32_t)(((uint32_t)(x))<<ADC_INT_ENABLE_EOSMPIE_SHIFT))&ADC_INT_ENABLE_EOSMPIE_MASK)
#define ADC_INT_ENABLE_ADRDYIE_MASK    0x1u
#define ADC_INT_ENABLE_ADRDYIE_SHIFT   0u
#define ADC_INT_ENABLE_ADRDYIE_WIDTH   1u
#define ADC_INT_ENABLE_ADRDYIE(x)      (((uint32_t)(((uint32_t)(x))<<ADC_INT_ENABLE_ADRDYIE_SHIFT))&ADC_INT_ENABLE_ADRDYIE_MASK)
/* INT_ENABLE Reg Mask */
#define ADC_INT_ENABLE_MASK            0x00003D9Fu

/* CONTROL Bit Fields */
#define ADC_CONTROL_ADRST_MASK         0x10u
#define ADC_CONTROL_ADRST_SHIFT        4u
#define ADC_CONTROL_ADRST_WIDTH        1u
#define ADC_CONTROL_ADRST(x)           (((uint32_t)(((uint32_t)(x))<<ADC_CONTROL_ADRST_SHIFT))&ADC_CONTROL_ADRST_MASK)
#define ADC_CONTROL_ADSTP_MASK         0x8u
#define ADC_CONTROL_ADSTP_SHIFT        3u
#define ADC_CONTROL_ADSTP_WIDTH        1u
#define ADC_CONTROL_ADSTP(x)           (((uint32_t)(((uint32_t)(x))<<ADC_CONTROL_ADSTP_SHIFT))&ADC_CONTROL_ADSTP_MASK)
#define ADC_CONTROL_ADSTART_MASK       0x4u
#define ADC_CONTROL_ADSTART_SHIFT      2u
#define ADC_CONTROL_ADSTART_WIDTH      1u
#define ADC_CONTROL_ADSTART(x)         (((uint32_t)(((uint32_t)(x))<<ADC_CONTROL_ADSTART_SHIFT))&ADC_CONTROL_ADSTART_MASK)
#define ADC_CONTROL_ADDIS_MASK         0x2u
#define ADC_CONTROL_ADDIS_SHIFT        1u
#define ADC_CONTROL_ADDIS_WIDTH        1u
#define ADC_CONTROL_ADDIS(x)           (((uint32_t)(((uint32_t)(x))<<ADC_CONTROL_ADDIS_SHIFT))&ADC_CONTROL_ADDIS_MASK)
#define ADC_CONTROL_ADEN_MASK          0x1u
#define ADC_CONTROL_ADEN_SHIFT         0u
#define ADC_CONTROL_ADEN_WIDTH         1u
#define ADC_CONTROL_ADEN(x)            (((uint32_t)(((uint32_t)(x))<<ADC_CONTROL_ADEN_SHIFT))&ADC_CONTROL_ADEN_MASK)
/* CONTROL Reg Mask */
#define ADC_CONTROL_MASK               0x0000001Fu

/* CFG1 Bit Fields */
#define ADC_CFG1_OVRMOD_MASK           0x40000000u
#define ADC_CFG1_OVRMOD_SHIFT          30u
#define ADC_CFG1_OVRMOD_WIDTH          1u
#define ADC_CFG1_OVRMOD(x)             (((uint32_t)(((uint32_t)(x))<<ADC_CFG1_OVRMOD_SHIFT))&ADC_CFG1_OVRMOD_MASK)
#define ADC_CFG1_SEQGP_EN_MASK         0x20000000u
#define ADC_CFG1_SEQGP_EN_SHIFT        29u
#define ADC_CFG1_SEQGP_EN_WIDTH        1u
#define ADC_CFG1_SEQGP_EN(x)           (((uint32_t)(((uint32_t)(x))<<ADC_CFG1_SEQGP_EN_SHIFT))&ADC_CFG1_SEQGP_EN_MASK)
#define ADC_CFG1_SEQ_LEN_MASK          0x1F000000u
#define ADC_CFG1_SEQ_LEN_SHIFT         24u
#define ADC_CFG1_SEQ_LEN_WIDTH         5u
#define ADC_CFG1_SEQ_LEN(x)            (((uint32_t)(((uint32_t)(x))<<ADC_CFG1_SEQ_LEN_SHIFT))&ADC_CFG1_SEQ_LEN_MASK)
#define ADC_CFG1_SEQ_MOD_MASK          0xC00000u
#define ADC_CFG1_SEQ_MOD_SHIFT         22u
#define ADC_CFG1_SEQ_MOD_WIDTH         2u
#define ADC_CFG1_SEQ_MOD(x)            (((uint32_t)(((uint32_t)(x))<<ADC_CFG1_SEQ_MOD_SHIFT))&ADC_CFG1_SEQ_MOD_MASK)
#define ADC_CFG1_AUTO_DIS_MASK         0x200000u
#define ADC_CFG1_AUTO_DIS_SHIFT        21u
#define ADC_CFG1_AUTO_DIS_WIDTH        1u
#define ADC_CFG1_AUTO_DIS(x)           (((uint32_t)(((uint32_t)(x))<<ADC_CFG1_AUTO_DIS_SHIFT))&ADC_CFG1_AUTO_DIS_MASK)
#define ADC_CFG1_WAIT_MASK             0x100000u
#define ADC_CFG1_WAIT_SHIFT            20u
#define ADC_CFG1_WAIT_WIDTH            1u
#define ADC_CFG1_WAIT(x)               (((uint32_t)(((uint32_t)(x))<<ADC_CFG1_WAIT_SHIFT))&ADC_CFG1_WAIT_MASK)
#define ADC_CFG1_TRIGSRC_MASK          0x70000u
#define ADC_CFG1_TRIGSRC_SHIFT         16u
#define ADC_CFG1_TRIGSRC_WIDTH         3u
#define ADC_CFG1_TRIGSRC(x)            (((uint32_t)(((uint32_t)(x))<<ADC_CFG1_TRIGSRC_SHIFT))&ADC_CFG1_TRIGSRC_MASK)
#define ADC_CFG1_TRIGMODE_MASK         0x3800u
#define ADC_CFG1_TRIGMODE_SHIFT        11u
#define ADC_CFG1_TRIGMODE_WIDTH        3u
#define ADC_CFG1_TRIGMODE(x)           (((uint32_t)(((uint32_t)(x))<<ADC_CFG1_TRIGMODE_SHIFT))&ADC_CFG1_TRIGMODE_MASK)
#define ADC_CFG1_ALIGN_MASK            0x400u
#define ADC_CFG1_ALIGN_SHIFT           10u
#define ADC_CFG1_ALIGN_WIDTH           1u
#define ADC_CFG1_ALIGN(x)              (((uint32_t)(((uint32_t)(x))<<ADC_CFG1_ALIGN_SHIFT))&ADC_CFG1_ALIGN_MASK)
#define ADC_CFG1_RES_MASK              0x300u
#define ADC_CFG1_RES_SHIFT             8u
#define ADC_CFG1_RES_WIDTH             2u
#define ADC_CFG1_RES(x)                (((uint32_t)(((uint32_t)(x))<<ADC_CFG1_RES_SHIFT))&ADC_CFG1_RES_MASK)
#define ADC_CFG1_SGDMA_SEL_MASK        0xCu
#define ADC_CFG1_SGDMA_SEL_SHIFT       2u
#define ADC_CFG1_SGDMA_SEL_WIDTH       2u
#define ADC_CFG1_SGDMA_SEL(x)          (((uint32_t)(((uint32_t)(x))<<ADC_CFG1_SGDMA_SEL_SHIFT))&ADC_CFG1_SGDMA_SEL_MASK)
#define ADC_CFG1_SGDMAEN_MASK          0x2u
#define ADC_CFG1_SGDMAEN_SHIFT         1u
#define ADC_CFG1_SGDMAEN_WIDTH         1u
#define ADC_CFG1_SGDMAEN(x)            (((uint32_t)(((uint32_t)(x))<<ADC_CFG1_SGDMAEN_SHIFT))&ADC_CFG1_SGDMAEN_MASK)
#define ADC_CFG1_DMAEN_MASK            0x1u
#define ADC_CFG1_DMAEN_SHIFT           0u
#define ADC_CFG1_DMAEN_WIDTH           1u
#define ADC_CFG1_DMAEN(x)              (((uint32_t)(((uint32_t)(x))<<ADC_CFG1_DMAEN_SHIFT))&ADC_CFG1_DMAEN_MASK)
/* CFG1 Reg Mask */
#define ADC_CFG1_MASK                  0x7FF73F0Fu

/* CFG2 Bit Fields */
#define ADC_CFG2_FWMARK_MASK           0x1F000000u
#define ADC_CFG2_FWMARK_SHIFT          24u
#define ADC_CFG2_FWMARK_WIDTH          5u
#define ADC_CFG2_FWMARK(x)             (((uint32_t)(((uint32_t)(x))<<ADC_CFG2_FWMARK_SHIFT))&ADC_CFG2_FWMARK_MASK)
#define ADC_CFG2_STRIG_INJT_MASK       0x400000u
#define ADC_CFG2_STRIG_INJT_SHIFT      22u
#define ADC_CFG2_STRIG_INJT_WIDTH      1u
#define ADC_CFG2_STRIG_INJT(x)         (((uint32_t)(((uint32_t)(x))<<ADC_CFG2_STRIG_INJT_SHIFT))&ADC_CFG2_STRIG_INJT_MASK)
#define ADC_CFG2_SEQ_INJTEN_MASK       0x200000u
#define ADC_CFG2_SEQ_INJTEN_SHIFT      21u
#define ADC_CFG2_SEQ_INJTEN_WIDTH      1u
#define ADC_CFG2_SEQ_INJTEN(x)         (((uint32_t)(((uint32_t)(x))<<ADC_CFG2_SEQ_INJTEN_SHIFT))&ADC_CFG2_SEQ_INJTEN_MASK)
#define ADC_CFG2_TRG_PRI_MASK          0x100000u
#define ADC_CFG2_TRG_PRI_SHIFT         20u
#define ADC_CFG2_TRG_PRI_WIDTH         1u
#define ADC_CFG2_TRG_PRI(x)            (((uint32_t)(((uint32_t)(x))<<ADC_CFG2_TRG_PRI_SHIFT))&ADC_CFG2_TRG_PRI_MASK)
#define ADC_CFG2_TRG_CLR_MASK          0x80000u
#define ADC_CFG2_TRG_CLR_SHIFT         19u
#define ADC_CFG2_TRG_CLR_WIDTH         1u
#define ADC_CFG2_TRG_CLR(x)            (((uint32_t)(((uint32_t)(x))<<ADC_CFG2_TRG_CLR_SHIFT))&ADC_CFG2_TRG_CLR_MASK)
#define ADC_CFG2_AVG_EN_MASK           0x40000u
#define ADC_CFG2_AVG_EN_SHIFT          18u
#define ADC_CFG2_AVG_EN_WIDTH          1u
#define ADC_CFG2_AVG_EN(x)             (((uint32_t)(((uint32_t)(x))<<ADC_CFG2_AVG_EN_SHIFT))&ADC_CFG2_AVG_EN_MASK)
#define ADC_CFG2_AVG_LEN_MASK          0x30000u
#define ADC_CFG2_AVG_LEN_SHIFT         16u
#define ADC_CFG2_AVG_LEN_WIDTH         2u
#define ADC_CFG2_AVG_LEN(x)            (((uint32_t)(((uint32_t)(x))<<ADC_CFG2_AVG_LEN_SHIFT))&ADC_CFG2_AVG_LEN_MASK)
#define ADC_CFG2_CG_ACK_MASK           0x4000u
#define ADC_CFG2_CG_ACK_SHIFT          14u
#define ADC_CFG2_CG_ACK_WIDTH          1u
#define ADC_CFG2_CG_ACK(x)             (((uint32_t)(((uint32_t)(x))<<ADC_CFG2_CG_ACK_SHIFT))&ADC_CFG2_CG_ACK_MASK)
#define ADC_CFG2_CG_MASK               0x2000u
#define ADC_CFG2_CG_SHIFT              13u
#define ADC_CFG2_CG_WIDTH              1u
#define ADC_CFG2_CG(x)                 (((uint32_t)(((uint32_t)(x))<<ADC_CFG2_CG_SHIFT))&ADC_CFG2_CG_MASK)
#define ADC_CFG2_REF_EXT_MASK          0x1000u
#define ADC_CFG2_REF_EXT_SHIFT         12u
#define ADC_CFG2_REF_EXT_WIDTH         1u
#define ADC_CFG2_REF_EXT(x)            (((uint32_t)(((uint32_t)(x))<<ADC_CFG2_REF_EXT_SHIFT))&ADC_CFG2_REF_EXT_MASK)
#define ADC_CFG2_DIV_MASK              0x300u
#define ADC_CFG2_DIV_SHIFT             8u
#define ADC_CFG2_DIV_WIDTH             2u
#define ADC_CFG2_DIV(x)                (((uint32_t)(((uint32_t)(x))<<ADC_CFG2_DIV_SHIFT))&ADC_CFG2_DIV_MASK)
#define ADC_CFG2_STCNT_MASK            0xFFu
#define ADC_CFG2_STCNT_SHIFT           0u
#define ADC_CFG2_STCNT_WIDTH           8u
#define ADC_CFG2_STCNT(x)              (((uint32_t)(((uint32_t)(x))<<ADC_CFG2_STCNT_SHIFT))&ADC_CFG2_STCNT_MASK)
/* CFG2 Reg Mask */
#define ADC_CFG2_MASK                  0x1F7F73FFu

/* SMPR Bit Fields */
#define ADC_SMPR_SMP_OPT3_MASK         0xFF000000u
#define ADC_SMPR_SMP_OPT3_SHIFT        24u
#define ADC_SMPR_SMP_OPT3_WIDTH        8u
#define ADC_SMPR_SMP_OPT3(x)           (((uint32_t)(((uint32_t)(x))<<ADC_SMPR_SMP_OPT3_SHIFT))&ADC_SMPR_SMP_OPT3_MASK)
#define ADC_SMPR_SMP_OPT2_MASK         0xFF0000u
#define ADC_SMPR_SMP_OPT2_SHIFT        16u
#define ADC_SMPR_SMP_OPT2_WIDTH        8u
#define ADC_SMPR_SMP_OPT2(x)           (((uint32_t)(((uint32_t)(x))<<ADC_SMPR_SMP_OPT2_SHIFT))&ADC_SMPR_SMP_OPT2_MASK)
#define ADC_SMPR_SMP_OPT1_MASK         0xFF00u
#define ADC_SMPR_SMP_OPT1_SHIFT        8u
#define ADC_SMPR_SMP_OPT1_WIDTH        8u
#define ADC_SMPR_SMP_OPT1(x)           (((uint32_t)(((uint32_t)(x))<<ADC_SMPR_SMP_OPT1_SHIFT))&ADC_SMPR_SMP_OPT1_MASK)
#define ADC_SMPR_SMP_OPT0_MASK         0xFFu
#define ADC_SMPR_SMP_OPT0_SHIFT        0u
#define ADC_SMPR_SMP_OPT0_WIDTH        8u
#define ADC_SMPR_SMP_OPT0(x)           (((uint32_t)(((uint32_t)(x))<<ADC_SMPR_SMP_OPT0_SHIFT))&ADC_SMPR_SMP_OPT0_MASK)
/* SMPR Reg Mask */
#define ADC_SMPR_MASK                  0xFFFFFFFFu

/* CMP_CTRL Bit Fields */
#define ADC_CMP_CTRL_ACMPEN_MASK       0x80u
#define ADC_CMP_CTRL_ACMPEN_SHIFT      7u
#define ADC_CMP_CTRL_ACMPEN_WIDTH      1u
#define ADC_CMP_CTRL_ACMPEN(x)         (((uint32_t)(((uint32_t)(x))<<ADC_CMP_CTRL_ACMPEN_SHIFT))&ADC_CMP_CTRL_ACMPEN_MASK)
#define ADC_CMP_CTRL_ACMPSGL_MASK      0x40u
#define ADC_CMP_CTRL_ACMPSGL_SHIFT     6u
#define ADC_CMP_CTRL_ACMPSGL_WIDTH     1u
#define ADC_CMP_CTRL_ACMPSGL(x)        (((uint32_t)(((uint32_t)(x))<<ADC_CMP_CTRL_ACMPSGL_SHIFT))&ADC_CMP_CTRL_ACMPSGL_MASK)
#define ADC_CMP_CTRL_ACMPCH_MASK       0x3Fu
#define ADC_CMP_CTRL_ACMPCH_SHIFT      0u
#define ADC_CMP_CTRL_ACMPCH_WIDTH      6u
#define ADC_CMP_CTRL_ACMPCH(x)         (((uint32_t)(((uint32_t)(x))<<ADC_CMP_CTRL_ACMPCH_SHIFT))&ADC_CMP_CTRL_ACMPCH_MASK)
/* CMP_CTRL Reg Mask */
#define ADC_CMP_CTRL_MASK              0x000000FFu

/* CMP_TR Bit Fields */
#define ADC_CMP_TR_HT_MASK             0xFFF0000u
#define ADC_CMP_TR_HT_SHIFT            16u
#define ADC_CMP_TR_HT_WIDTH            12u
#define ADC_CMP_TR_HT(x)               (((uint32_t)(((uint32_t)(x))<<ADC_CMP_TR_HT_SHIFT))&ADC_CMP_TR_HT_MASK)
#define ADC_CMP_TR_LT_MASK             0xFFFu
#define ADC_CMP_TR_LT_SHIFT            0u
#define ADC_CMP_TR_LT_WIDTH            12u
#define ADC_CMP_TR_LT(x)               (((uint32_t)(((uint32_t)(x))<<ADC_CMP_TR_LT_SHIFT))&ADC_CMP_TR_LT_MASK)
/* CMP_TR Reg Mask */
#define ADC_CMP_TR_MASK                0x0FFF0FFFu

/* SGCSR Bit Fields */
#define ADC_SGCSR_EOSG_MASK            0x1000000u
#define ADC_SGCSR_EOSG_SHIFT           24u
#define ADC_SGCSR_EOSG_WIDTH           1u
#define ADC_SGCSR_EOSG(x)              (((uint32_t)(((uint32_t)(x))<<ADC_SGCSR_EOSG_SHIFT))&ADC_SGCSR_EOSG_MASK)
#define ADC_SGCSR_EOSGIE_MASK          0x10000u
#define ADC_SGCSR_EOSGIE_SHIFT         16u
#define ADC_SGCSR_EOSGIE_WIDTH         1u
#define ADC_SGCSR_EOSGIE(x)            (((uint32_t)(((uint32_t)(x))<<ADC_SGCSR_EOSGIE_SHIFT))&ADC_SGCSR_EOSGIE_MASK)
#define ADC_SGCSR_SG_END_MASK          0x1F00u
#define ADC_SGCSR_SG_END_SHIFT         8u
#define ADC_SGCSR_SG_END_WIDTH         5u
#define ADC_SGCSR_SG_END(x)            (((uint32_t)(((uint32_t)(x))<<ADC_SGCSR_SG_END_SHIFT))&ADC_SGCSR_SG_END_MASK)
#define ADC_SGCSR_SG_START_MASK        0x1Fu
#define ADC_SGCSR_SG_START_SHIFT       0u
#define ADC_SGCSR_SG_START_WIDTH       5u
#define ADC_SGCSR_SG_START(x)          (((uint32_t)(((uint32_t)(x))<<ADC_SGCSR_SG_START_SHIFT))&ADC_SGCSR_SG_START_MASK)
/* SGCSR0 Reg Mask */
#define ADC_SGCSR_MASK                 0x01011F1Fu

/* CAL Bit Fields */
#define ADC_CAL_CAL_EN_MASK            0x80000000u
#define ADC_CAL_CAL_EN_SHIFT           31u
#define ADC_CAL_CAL_EN_WIDTH           1u
#define ADC_CAL_CAL_EN(x)              (((uint32_t)(((uint32_t)(x))<<ADC_CAL_CAL_EN_SHIFT))&ADC_CAL_CAL_EN_MASK)
#define ADC_CAL_OFFSET_MASK            0xFFF0000u
#define ADC_CAL_OFFSET_SHIFT           16u
#define ADC_CAL_OFFSET_WIDTH           12u
#define ADC_CAL_OFFSET(x)              (((uint32_t)(((uint32_t)(x))<<ADC_CAL_OFFSET_SHIFT))&ADC_CAL_OFFSET_MASK)
#define ADC_CAL_GAIN_MASK              0x1FFFu
#define ADC_CAL_GAIN_SHIFT             0u
#define ADC_CAL_GAIN_WIDTH             13u
#define ADC_CAL_GAIN(x)                (((uint32_t)(((uint32_t)(x))<<ADC_CAL_GAIN_SHIFT))&ADC_CAL_GAIN_MASK)
/* CAL Reg Mask */
#define ADC_CAL_MASK                   0x8FFF1FFFu

/* CFG3 Bit Fields */
#define ADC_CFG3_EOSG_OSEL_MASK        0x20000000u
#define ADC_CFG3_EOSG_OSEL_SHIFT       29u
#define ADC_CFG3_EOSG_OSEL_WIDTH       1u
#define ADC_CFG3_EOSG_OSEL(x)          (((uint32_t)(((uint32_t)(x))<<ADC_CFG3_EOSG_OSEL_SHIFT))&ADC_CFG3_EOSG_OSEL_MASK)
#define ADC_CFG3_COCO_OSEL_MASK        0x1F000000u
#define ADC_CFG3_COCO_OSEL_SHIFT       24u
#define ADC_CFG3_COCO_OSEL_WIDTH       5u
#define ADC_CFG3_COCO_OSEL(x)          (((uint32_t)(((uint32_t)(x))<<ADC_CFG3_COCO_OSEL_SHIFT))&ADC_CFG3_COCO_OSEL_MASK)
#define ADC_CFG3_BFL_OEN_MASK          0x40000u
#define ADC_CFG3_BFL_OEN_SHIFT         18u
#define ADC_CFG3_BFL_OEN_WIDTH         1u
#define ADC_CFG3_BFL_OEN(x)            (((uint32_t)(((uint32_t)(x))<<ADC_CFG3_BFL_OEN_SHIFT))&ADC_CFG3_BFL_OEN_MASK)
#define ADC_CFG3_FCR_R_OEN_MASK        0x20000u
#define ADC_CFG3_FCR_R_OEN_SHIFT       17u
#define ADC_CFG3_FCR_R_OEN_WIDTH       1u
#define ADC_CFG3_FCR_R_OEN(x)          (((uint32_t)(((uint32_t)(x))<<ADC_CFG3_FCR_R_OEN_SHIFT))&ADC_CFG3_FCR_R_OEN_MASK)
#define ADC_CFG3_FCR_F_OEN_MASK        0x10000u
#define ADC_CFG3_FCR_F_OEN_SHIFT       16u
#define ADC_CFG3_FCR_F_OEN_WIDTH       1u
#define ADC_CFG3_FCR_F_OEN(x)          (((uint32_t)(((uint32_t)(x))<<ADC_CFG3_FCR_F_OEN_SHIFT))&ADC_CFG3_FCR_F_OEN_MASK)
#define ADC_CFG3_PTRGIV_MASK           0x7FEu
#define ADC_CFG3_PTRGIV_SHIFT          1u
#define ADC_CFG3_PTRGIV_WIDTH          10u
#define ADC_CFG3_PTRGIV(x)             (((uint32_t)(((uint32_t)(x))<<ADC_CFG3_PTRGIV_SHIFT))&ADC_CFG3_PTRGIV_MASK)
#define ADC_CFG3_COCO_PLS_EN_MASK      0x1u
#define ADC_CFG3_COCO_PLS_EN_SHIFT     0u
#define ADC_CFG3_COCO_PLS_EN_WIDTH     1u
#define ADC_CFG3_COCO_PLS_EN(x)        (((uint32_t)(((uint32_t)(x))<<ADC_CFG3_COCO_PLS_EN_SHIFT))&ADC_CFG3_COCO_PLS_EN_MASK)
/* CFG3 Reg Mask */
#define ADC_CFG3_MASK                  0x3F0707FFu

/* FIFO_DATA Bit Fields */
#define ADC_FIFO_DATA_FIFO_DATA_MASK   0xFFFFu
#define ADC_FIFO_DATA_FIFO_DATA_SHIFT  0u
#define ADC_FIFO_DATA_FIFO_DATA_WIDTH  16u
#define ADC_FIFO_DATA_FIFO_DATA(x)     (((uint32_t)(((uint32_t)(x))<<ADC_FIFO_DATA_FIFO_DATA_SHIFT))&ADC_FIFO_DATA_FIFO_DATA_MASK)
/* FIFO_DATA Reg Mask */
#define ADC_FIFO_DATA_MASK             0x0000FFFFu

/* SC Bit Fields */
#define ADC_SC_DIFF_MASK               0x400u
#define ADC_SC_DIFF_SHIFT              10u
#define ADC_SC_DIFF_WIDTH              1u
#define ADC_SC_DIFF(x)                 (((uint32_t)(((uint32_t)(x))<<ADC_SC_DIFF_SHIFT))&ADC_SC_DIFF_MASK)
#define ADC_SC_SMPSEL_MASK             0x300u
#define ADC_SC_SMPSEL_SHIFT            8u
#define ADC_SC_SMPSEL_WIDTH            2u
#define ADC_SC_SMPSEL(x)               (((uint32_t)(((uint32_t)(x))<<ADC_SC_SMPSEL_SHIFT))&ADC_SC_SMPSEL_MASK)
#define ADC_SC_COCO_MASK               0x80u
#define ADC_SC_COCO_SHIFT              7u
#define ADC_SC_COCO_WIDTH              1u
#define ADC_SC_COCO(x)                 (((uint32_t)(((uint32_t)(x))<<ADC_SC_COCO_SHIFT))&ADC_SC_COCO_MASK)
#define ADC_SC_AIEN_MASK               0x40u
#define ADC_SC_AIEN_SHIFT              6u
#define ADC_SC_AIEN_WIDTH              1u
#define ADC_SC_AIEN(x)                 (((uint32_t)(((uint32_t)(x))<<ADC_SC_AIEN_SHIFT))&ADC_SC_AIEN_MASK)
#define ADC_SC_CHS_MASK                0x3Fu
#define ADC_SC_CHS_SHIFT               0u
#define ADC_SC_CHS_WIDTH               6u
#define ADC_SC_CHS(x)                  (((uint32_t)(((uint32_t)(x))<<ADC_SC_CHS_SHIFT))&ADC_SC_CHS_MASK)
/* SC0 Reg Mask */
#define ADC_SC_MASK                    0x000007FFu

/* RESULT Bit Fields */
#define ADC_RESULT_RESULT_MASK         0xFFFFu
#define ADC_RESULT_RESULT_SHIFT        0u
#define ADC_RESULT_RESULT_WIDTH        16u
#define ADC_RESULT_RESULT(x)           (((uint32_t)(((uint32_t)(x))<<ADC_RESULT_RESULT_SHIFT))&ADC_RESULT_RESULT_MASK)
/* RESULT0 Reg Mask */
#define ADC_RESULT_MASK                0x0000FFFFu

/* ECMP_CTRL Bit Fields */
#define ADC_ECMP_CTRL_CMPOPT_MASK      0x300u
#define ADC_ECMP_CTRL_CMPOPT_SHIFT     8u
#define ADC_ECMP_CTRL_CMPOPT_WIDTH     2u
#define ADC_ECMP_CTRL_CMPOPT(x)        (((uint32_t)(((uint32_t)(x))<<ADC_ECMP_CTRL_CMPOPT_SHIFT))&ADC_ECMP_CTRL_CMPOPT_MASK)
#define ADC_ECMP_CTRL_CMPEN_MASK       0x80u
#define ADC_ECMP_CTRL_CMPEN_SHIFT      7u
#define ADC_ECMP_CTRL_CMPEN_WIDTH      1u
#define ADC_ECMP_CTRL_CMPEN(x)         (((uint32_t)(((uint32_t)(x))<<ADC_ECMP_CTRL_CMPEN_SHIFT))&ADC_ECMP_CTRL_CMPEN_MASK)
#define ADC_ECMP_CTRL_CMPSGL_MASK      0x40u
#define ADC_ECMP_CTRL_CMPSGL_SHIFT     6u
#define ADC_ECMP_CTRL_CMPSGL_WIDTH     1u
#define ADC_ECMP_CTRL_CMPSGL(x)        (((uint32_t)(((uint32_t)(x))<<ADC_ECMP_CTRL_CMPSGL_SHIFT))&ADC_ECMP_CTRL_CMPSGL_MASK)
#define ADC_ECMP_CTRL_CMPCH_MASK       0x3Fu
#define ADC_ECMP_CTRL_CMPCH_SHIFT      0u
#define ADC_ECMP_CTRL_CMPCH_WIDTH      6u
#define ADC_ECMP_CTRL_CMPCH(x)         (((uint32_t)(((uint32_t)(x))<<ADC_ECMP_CTRL_CMPCH_SHIFT))&ADC_ECMP_CTRL_CMPCH_MASK)
/* ECMP_CTRL0 Reg Mask */
#define ADC_ECMP_CTRL_MASK             0x000003FFu

/* ECMP_STATUS Bit Fields */
#define ADC_ECMP_STATUS_CMPH1_MASK     0x40u
#define ADC_ECMP_STATUS_CMPH1_SHIFT    6u
#define ADC_ECMP_STATUS_CMPH1_WIDTH    1u
#define ADC_ECMP_STATUS_CMPH1(x)       (((uint32_t)(((uint32_t)(x))<<ADC_ECMP_STATUS_CMPH1_SHIFT))&ADC_ECMP_STATUS_CMPH1_MASK)
#define ADC_ECMP_STATUS_CMPL1_MASK     0x20u
#define ADC_ECMP_STATUS_CMPL1_SHIFT    5u
#define ADC_ECMP_STATUS_CMPL1_WIDTH    1u
#define ADC_ECMP_STATUS_CMPL1(x)       (((uint32_t)(((uint32_t)(x))<<ADC_ECMP_STATUS_CMPL1_SHIFT))&ADC_ECMP_STATUS_CMPL1_MASK)
#define ADC_ECMP_STATUS_CMPW1_MASK     0x10u
#define ADC_ECMP_STATUS_CMPW1_SHIFT    4u
#define ADC_ECMP_STATUS_CMPW1_WIDTH    1u
#define ADC_ECMP_STATUS_CMPW1(x)       (((uint32_t)(((uint32_t)(x))<<ADC_ECMP_STATUS_CMPW1_SHIFT))&ADC_ECMP_STATUS_CMPW1_MASK)
#define ADC_ECMP_STATUS_CMPH0_MASK     0x4u
#define ADC_ECMP_STATUS_CMPH0_SHIFT    2u
#define ADC_ECMP_STATUS_CMPH0_WIDTH    1u
#define ADC_ECMP_STATUS_CMPH0(x)       (((uint32_t)(((uint32_t)(x))<<ADC_ECMP_STATUS_CMPH0_SHIFT))&ADC_ECMP_STATUS_CMPH0_MASK)
#define ADC_ECMP_STATUS_CMPL0_MASK     0x2u
#define ADC_ECMP_STATUS_CMPL0_SHIFT    1u
#define ADC_ECMP_STATUS_CMPL0_WIDTH    1u
#define ADC_ECMP_STATUS_CMPL0(x)       (((uint32_t)(((uint32_t)(x))<<ADC_ECMP_STATUS_CMPL0_SHIFT))&ADC_ECMP_STATUS_CMPL0_MASK)
#define ADC_ECMP_STATUS_CMPW0_MASK     0x1u
#define ADC_ECMP_STATUS_CMPW0_SHIFT    0u
#define ADC_ECMP_STATUS_CMPW0_WIDTH    1u
#define ADC_ECMP_STATUS_CMPW0(x)       (((uint32_t)(((uint32_t)(x))<<ADC_ECMP_STATUS_CMPW0_SHIFT))&ADC_ECMP_STATUS_CMPW0_MASK)
/* ECMP_STATUS Reg Mask */
#define ADC_ECMP_STATUS_MASK           0x00000077u

/* ECMP_INT_EN Bit Fields */
#define ADC_ECMP_INT_EN_CMPH_IE1_MASK  0x40u
#define ADC_ECMP_INT_EN_CMPH_IE1_SHIFT 6u
#define ADC_ECMP_INT_EN_CMPH_IE1_WIDTH 1u
#define ADC_ECMP_INT_EN_CMPH_IE1(x)    (((uint32_t)(((uint32_t)(x))<<ADC_ECMP_INT_EN_CMPH_IE1_SHIFT))&ADC_ECMP_INT_EN_CMPH_IE1_MASK)
#define ADC_ECMP_INT_EN_CMPL_IE1_MASK  0x20u
#define ADC_ECMP_INT_EN_CMPL_IE1_SHIFT 5u
#define ADC_ECMP_INT_EN_CMPL_IE1_WIDTH 1u
#define ADC_ECMP_INT_EN_CMPL_IE1(x)    (((uint32_t)(((uint32_t)(x))<<ADC_ECMP_INT_EN_CMPL_IE1_SHIFT))&ADC_ECMP_INT_EN_CMPL_IE1_MASK)
#define ADC_ECMP_INT_EN_CMPW_IE1_MASK  0x10u
#define ADC_ECMP_INT_EN_CMPW_IE1_SHIFT 4u
#define ADC_ECMP_INT_EN_CMPW_IE1_WIDTH 1u
#define ADC_ECMP_INT_EN_CMPW_IE1(x)    (((uint32_t)(((uint32_t)(x))<<ADC_ECMP_INT_EN_CMPW_IE1_SHIFT))&ADC_ECMP_INT_EN_CMPW_IE1_MASK)
#define ADC_ECMP_INT_EN_CMPH_IE0_MASK  0x4u
#define ADC_ECMP_INT_EN_CMPH_IE0_SHIFT 2u
#define ADC_ECMP_INT_EN_CMPH_IE0_WIDTH 1u
#define ADC_ECMP_INT_EN_CMPH_IE0(x)    (((uint32_t)(((uint32_t)(x))<<ADC_ECMP_INT_EN_CMPH_IE0_SHIFT))&ADC_ECMP_INT_EN_CMPH_IE0_MASK)
#define ADC_ECMP_INT_EN_CMPL_IE0_MASK  0x2u
#define ADC_ECMP_INT_EN_CMPL_IE0_SHIFT 1u
#define ADC_ECMP_INT_EN_CMPL_IE0_WIDTH 1u
#define ADC_ECMP_INT_EN_CMPL_IE0(x)    (((uint32_t)(((uint32_t)(x))<<ADC_ECMP_INT_EN_CMPL_IE0_SHIFT))&ADC_ECMP_INT_EN_CMPL_IE0_MASK)
#define ADC_ECMP_INT_EN_CMPW_IE0_MASK  0x1u
#define ADC_ECMP_INT_EN_CMPW_IE0_SHIFT 0u
#define ADC_ECMP_INT_EN_CMPW_IE0_WIDTH 1u
#define ADC_ECMP_INT_EN_CMPW_IE0(x)    (((uint32_t)(((uint32_t)(x))<<ADC_ECMP_INT_EN_CMPW_IE0_SHIFT))&ADC_ECMP_INT_EN_CMPW_IE0_MASK)
/* ECMP_INT_EN Reg Mask */
#define ADC_ECMP_INT_EN_MASK           0x00000077u

/* ECMP_TR Bit Fields */
#define ADC_ECMP_TR_HT_MASK            0xFFF0000u
#define ADC_ECMP_TR_HT_SHIFT           16u
#define ADC_ECMP_TR_HT_WIDTH           12u
#define ADC_ECMP_TR_HT(x)              (((uint32_t)(((uint32_t)(x))<<ADC_ECMP_TR_HT_SHIFT))&ADC_ECMP_TR_HT_MASK)
#define ADC_ECMP_TR_LT_MASK            0xFFFu
#define ADC_ECMP_TR_LT_SHIFT           0u
#define ADC_ECMP_TR_LT_WIDTH           12u
#define ADC_ECMP_TR_LT(x)              (((uint32_t)(((uint32_t)(x))<<ADC_ECMP_TR_LT_SHIFT))&ADC_ECMP_TR_LT_MASK)
/* ECMP_TR0 Reg Mask */
#define ADC_ECMP_TR_MASK               0x0FFF0FFFu

/* FCMP_CTRL Bit Fields */
#define ADC_FCMP_CTRL_RPTRG_SEL_MASK   0x600u
#define ADC_FCMP_CTRL_RPTRG_SEL_SHIFT  9u
#define ADC_FCMP_CTRL_RPTRG_SEL_WIDTH  2u
#define ADC_FCMP_CTRL_RPTRG_SEL(x)     (((uint32_t)(((uint32_t)(x))<<ADC_FCMP_CTRL_RPTRG_SEL_SHIFT))&ADC_FCMP_CTRL_RPTRG_SEL_MASK)
#define ADC_FCMP_CTRL_RPCNT_EN_MASK    0x100u
#define ADC_FCMP_CTRL_RPCNT_EN_SHIFT   8u
#define ADC_FCMP_CTRL_RPCNT_EN_WIDTH   1u
#define ADC_FCMP_CTRL_RPCNT_EN(x)      (((uint32_t)(((uint32_t)(x))<<ADC_FCMP_CTRL_RPCNT_EN_SHIFT))&ADC_FCMP_CTRL_RPCNT_EN_MASK)
#define ADC_FCMP_CTRL_RP_SWTRG_MASK    0x10u
#define ADC_FCMP_CTRL_RP_SWTRG_SHIFT   4u
#define ADC_FCMP_CTRL_RP_SWTRG_WIDTH   1u
#define ADC_FCMP_CTRL_RP_SWTRG(x)      (((uint32_t)(((uint32_t)(x))<<ADC_FCMP_CTRL_RP_SWTRG_SHIFT))&ADC_FCMP_CTRL_RP_SWTRG_MASK)
#define ADC_FCMP_CTRL_ETRG_POL_MASK    0x8u
#define ADC_FCMP_CTRL_ETRG_POL_SHIFT   3u
#define ADC_FCMP_CTRL_ETRG_POL_WIDTH   1u
#define ADC_FCMP_CTRL_ETRG_POL(x)      (((uint32_t)(((uint32_t)(x))<<ADC_FCMP_CTRL_ETRG_POL_SHIFT))&ADC_FCMP_CTRL_ETRG_POL_MASK)
#define ADC_FCMP_CTRL_FCMOD_ALT_MASK   0x4u
#define ADC_FCMP_CTRL_FCMOD_ALT_SHIFT  2u
#define ADC_FCMP_CTRL_FCMOD_ALT_WIDTH  1u
#define ADC_FCMP_CTRL_FCMOD_ALT(x)     (((uint32_t)(((uint32_t)(x))<<ADC_FCMP_CTRL_FCMOD_ALT_SHIFT))&ADC_FCMP_CTRL_FCMOD_ALT_MASK)
#define ADC_FCMP_CTRL_FC_EN_MASK       0x1u
#define ADC_FCMP_CTRL_FC_EN_SHIFT      0u
#define ADC_FCMP_CTRL_FC_EN_WIDTH      1u
#define ADC_FCMP_CTRL_FC_EN(x)         (((uint32_t)(((uint32_t)(x))<<ADC_FCMP_CTRL_FC_EN_SHIFT))&ADC_FCMP_CTRL_FC_EN_MASK)
/* FCMP_CTRL Reg Mask */
#define ADC_FCMP_CTRL_MASK             0x0000071Du

/* FCREF Bit Fields */
#define ADC_FCREF_FCREF_MASK           0x7FFu
#define ADC_FCREF_FCREF_SHIFT          0u
#define ADC_FCREF_FCREF_WIDTH          11u
#define ADC_FCREF_FCREF(x)             (((uint32_t)(((uint32_t)(x))<<ADC_FCREF_FCREF_SHIFT))&ADC_FCREF_FCREF_MASK)
/* FCREF Reg Mask */
#define ADC_FCREF_MASK                 0x000007FFu

/* FCRAMP0 Bit Fields */
#define ADC_FCRAMP0_FCREF_A_MASK       0x7FF0000u
#define ADC_FCRAMP0_FCREF_A_SHIFT      16u
#define ADC_FCRAMP0_FCREF_A_WIDTH      11u
#define ADC_FCRAMP0_FCREF_A(x)         (((uint32_t)(((uint32_t)(x))<<ADC_FCRAMP0_FCREF_A_SHIFT))&ADC_FCRAMP0_FCREF_A_MASK)
#define ADC_FCRAMP0_RPSTEP_MASK        0xFFu
#define ADC_FCRAMP0_RPSTEP_SHIFT       0u
#define ADC_FCRAMP0_RPSTEP_WIDTH       8u
#define ADC_FCRAMP0_RPSTEP(x)          (((uint32_t)(((uint32_t)(x))<<ADC_FCRAMP0_RPSTEP_SHIFT))&ADC_FCRAMP0_RPSTEP_MASK)
/* FCRAMP0 Reg Mask */
#define ADC_FCRAMP0_MASK               0x07FF00FFu

/* FCRAMP1 Bit Fields */
#define ADC_FCRAMP1_FCREF_B_MASK       0x7FF0000u
#define ADC_FCRAMP1_FCREF_B_SHIFT      16u
#define ADC_FCRAMP1_FCREF_B_WIDTH      11u
#define ADC_FCRAMP1_FCREF_B(x)         (((uint32_t)(((uint32_t)(x))<<ADC_FCRAMP1_FCREF_B_SHIFT))&ADC_FCRAMP1_FCREF_B_MASK)
#define ADC_FCRAMP1_RPDIR_MASK         0x1u
#define ADC_FCRAMP1_RPDIR_SHIFT        0u
#define ADC_FCRAMP1_RPDIR_WIDTH        1u
#define ADC_FCRAMP1_RPDIR(x)           (((uint32_t)(((uint32_t)(x))<<ADC_FCRAMP1_RPDIR_SHIFT))&ADC_FCRAMP1_RPDIR_MASK)
/* FCRAMP1 Reg Mask */
#define ADC_FCRAMP1_MASK               0x07FF0001u

/* FCHYST Bit Fields */
#define ADC_FCHYST_DELTAP_MASK         0x7FF0000u
#define ADC_FCHYST_DELTAP_SHIFT        16u
#define ADC_FCHYST_DELTAP_WIDTH        11u
#define ADC_FCHYST_DELTAP(x)           (((uint32_t)(((uint32_t)(x))<<ADC_FCHYST_DELTAP_SHIFT))&ADC_FCHYST_DELTAP_MASK)
#define ADC_FCHYST_DELTAN_MASK         0x7FFu
#define ADC_FCHYST_DELTAN_SHIFT        0u
#define ADC_FCHYST_DELTAN_WIDTH        11u
#define ADC_FCHYST_DELTAN(x)           (((uint32_t)(((uint32_t)(x))<<ADC_FCHYST_DELTAN_SHIFT))&ADC_FCHYST_DELTAN_MASK)
/* FCHYST Reg Mask */
#define ADC_FCHYST_MASK                0x07FF07FFu

/* FCBFR Bit Fields */
#define ADC_FCBFR_BFL_MASK             0x80000000u
#define ADC_FCBFR_BFL_SHIFT            31u
#define ADC_FCBFR_BFL_WIDTH            1u
#define ADC_FCBFR_BFL(x)               (((uint32_t)(((uint32_t)(x))<<ADC_FCBFR_BFL_SHIFT))&ADC_FCBFR_BFL_MASK)
#define ADC_FCBFR_FCR_MASK             0x40000000u
#define ADC_FCBFR_FCR_SHIFT            30u
#define ADC_FCBFR_FCR_WIDTH            1u
#define ADC_FCBFR_FCR(x)               (((uint32_t)(((uint32_t)(x))<<ADC_FCBFR_FCR_SHIFT))&ADC_FCBFR_FCR_MASK)
#define ADC_FCBFR_FCETRG_LVL_MASK      0x20000000u
#define ADC_FCBFR_FCETRG_LVL_SHIFT     29u
#define ADC_FCBFR_FCETRG_LVL_WIDTH     1u
#define ADC_FCBFR_FCETRG_LVL(x)        (((uint32_t)(((uint32_t)(x))<<ADC_FCBFR_FCETRG_LVL_SHIFT))&ADC_FCBFR_FCETRG_LVL_MASK)
#define ADC_FCBFR_FCR_SYNC_EN_MASK     0x100u
#define ADC_FCBFR_FCR_SYNC_EN_SHIFT    8u
#define ADC_FCBFR_FCR_SYNC_EN_WIDTH    1u
#define ADC_FCBFR_FCR_SYNC_EN(x)       (((uint32_t)(((uint32_t)(x))<<ADC_FCBFR_FCR_SYNC_EN_SHIFT))&ADC_FCBFR_FCR_SYNC_EN_MASK)
#define ADC_FCBFR_BFI_MASK             0x80u
#define ADC_FCBFR_BFI_SHIFT            7u
#define ADC_FCBFR_BFI_WIDTH            1u
#define ADC_FCBFR_BFI(x)               (((uint32_t)(((uint32_t)(x))<<ADC_FCBFR_BFI_SHIFT))&ADC_FCBFR_BFI_MASK)
#define ADC_FCBFR_BFVG_POL_MASK        0x40u
#define ADC_FCBFR_BFVG_POL_SHIFT       6u
#define ADC_FCBFR_BFVG_POL_WIDTH       1u
#define ADC_FCBFR_BFVG_POL(x)          (((uint32_t)(((uint32_t)(x))<<ADC_FCBFR_BFVG_POL_SHIFT))&ADC_FCBFR_BFVG_POL_MASK)
#define ADC_FCBFR_BFV_MASK             0x20u
#define ADC_FCBFR_BFV_SHIFT            5u
#define ADC_FCBFR_BFV_WIDTH            1u
#define ADC_FCBFR_BFV(x)               (((uint32_t)(((uint32_t)(x))<<ADC_FCBFR_BFV_SHIFT))&ADC_FCBFR_BFV_MASK)
#define ADC_FCBFR_BFS_MASK             0x18u
#define ADC_FCBFR_BFS_SHIFT            3u
#define ADC_FCBFR_BFS_WIDTH            2u
#define ADC_FCBFR_BFS(x)               (((uint32_t)(((uint32_t)(x))<<ADC_FCBFR_BFS_SHIFT))&ADC_FCBFR_BFS_MASK)
#define ADC_FCBFR_BFA_MASK             0x4u
#define ADC_FCBFR_BFA_SHIFT            2u
#define ADC_FCBFR_BFA_WIDTH            1u
#define ADC_FCBFR_BFA(x)               (((uint32_t)(((uint32_t)(x))<<ADC_FCBFR_BFA_SHIFT))&ADC_FCBFR_BFA_MASK)
#define ADC_FCBFR_BFM_MASK             0x2u
#define ADC_FCBFR_BFM_SHIFT            1u
#define ADC_FCBFR_BFM_WIDTH            1u
#define ADC_FCBFR_BFM(x)               (((uint32_t)(((uint32_t)(x))<<ADC_FCBFR_BFM_SHIFT))&ADC_FCBFR_BFM_MASK)
#define ADC_FCBFR_FCR_INIT_MASK        0x1u
#define ADC_FCBFR_FCR_INIT_SHIFT       0u
#define ADC_FCBFR_FCR_INIT_WIDTH       1u
#define ADC_FCBFR_FCR_INIT(x)          (((uint32_t)(((uint32_t)(x))<<ADC_FCBFR_FCR_INIT_SHIFT))&ADC_FCBFR_FCR_INIT_MASK)
/* FCBFR Reg Mask */
#define ADC_FCBFR_MASK                 0xE00001FFu


/*!
 * @}
 */ /* end of group ADC_Register_Masks */

/*!
 * @}
 */ /* end of group ADC_Peripheral_Access_Layer */

#endif
