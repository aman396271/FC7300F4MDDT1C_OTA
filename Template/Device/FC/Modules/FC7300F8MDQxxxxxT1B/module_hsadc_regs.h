#ifndef _MODULE_HSADC_gmbhdijq71_REGS_H_HSADC_H_
#define _MODULE_HSADC_gmbhdijq71_REGS_H_HSADC_H_

/* ----------------------------------------------------------------------------
   -- HSADC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup HSADC_Peripheral_Access_Layer HSADC Peripheral Access Layer
 * @{
 */

/** HSADC - Size of Registers Arrays */

/** HSADC - Register Layout Typedef */
#define HSADC_SGCSR_COUNT 2
#define HSADC_SC_COUNT 16
#define HSADC_RESULT_COUNT 16

typedef struct {

  __IO uint32_t INT_STATUS                    ; /* Interrupt Status Register, offset: 0x0 */
  __IO uint32_t INT_ENABLE                    ; /* Interrupt Enable Register, offset: 0x4 */
  __IO uint32_t CTRL                          ; /* Control Register, offset: 0x8 */
  __IO uint32_t CFG1                          ; /* Configuration1 Register, offset: 0xC */
  __IO uint32_t CFG2                          ; /* Configuration2 Register, offset: 0x10 */
  __IO uint32_t SMPR                          ; /* Sampling Rate Register, offset: 0x14 */
  __IO uint32_t CMP_CTRL                      ; /* Compare Control Register, offset: 0x18 */
  __IO uint32_t CMP_TR                        ; /* Compare Threshold Register, offset: 0x1C */
       uint8_t  RESERVED_0[4];
  __IO uint32_t CFG3                          ; /* Configuration3 Register, offset: 0x24 */
  __IO uint32_t SGCSR[HSADC_SGCSR_COUNT]      ; /* Sequence Group Control and Status Register, offset: 0x28 */
       uint8_t  RESERVED_1[20];
  __IO uint32_t OGCR                          ; /* Offset and Gain Compensation Register, offset: 0x44 */
  __IO uint32_t CCAL                          ; /* Cap Calibration Register, offset: 0x48 */
  __I  uint32_t FIFO_DATA                     ; /* FIFO Data Register, offset: 0x4C */
  __IO uint32_t SC[HSADC_SC_COUNT]            ; /* Sequence Configuration Register, offset: 0x50 */
       uint8_t  RESERVED_2[64];
  __I  uint32_t RESULT[HSADC_RESULT_COUNT]    ; /* Result Register, offset: 0xd0 */
       uint8_t  RESERVED_3[64];
  __I  uint32_t RESULT_CAL                    ; /* Result Register for Calibration, offset: 0x150 */
  __IO uint32_t DCAPWT0                       ; /* Delta Cap Weight Register 0, offset: 0x154 */
  __IO uint32_t DCAPWT1                       ; /* Delta Cap Weight Register 1, offset: 0x158 */
  __IO uint32_t DCAPWT2                       ; /* Delta Cap Weight Register 2, offset: 0x15C */
  __IO uint32_t DCAPWT3                       ; /* Delta Cap Weight Register 3, offset: 0x160 */
  __IO uint32_t DCAPWT4                       ; /* Delta Cap Weight Register 4, offset: 0x164 */
  __IO uint32_t DCAPWT5                       ; /* Delta Cap Weight Register 5, offset: 0x168 */
  __IO uint32_t DCAPWT6                       ; /* Delta Cap Weight Register 6, offset: 0x16C */
  __IO uint32_t FCMP_CTRL                     ; /* Fast Compare Control Register, offset: 0x170 */
  __IO uint32_t FCREF                         ; /* Fast Compare Reference Register, offset: 0x174 */
  __IO uint32_t FCRAMP0                       ; /* Fast Compare Ramp Register 0, offset: 0x178 */
  __IO uint32_t FCRAMP1                       ; /* Fast Compare Ramp Register 1, offset: 0x17C */
  __IO uint32_t FCHYST                        ; /* Fast Compare Hysteresis Register, offset: 0x180 */
  __IO uint32_t FCBFR                         ; /* Fast Compare Boundary Flag Register, offset: 0x184 */

} HSADC_Type, *HSADC_MemMapPtr;


/* HSADC - Peripheral instance base addresses */
/** Peripheral HSADC0 base address */
#define HSADC0_BASE                              (0x4042c000u)
/** Peripheral HSADC0 base pointer */
#define HSADC0                                   ((HSADC_Type *)HSADC0_BASE)
/** Peripheral HSADC1 base address */
#define HSADC1_BASE                              (0x4042d000u)
/** Peripheral HSADC1 base pointer */
#define HSADC1                                   ((HSADC_Type *)HSADC1_BASE)
/** Peripheral HSADC2 base address */
#define HSADC2_BASE                              (0x4042e000u)
/** Peripheral HSADC2 base pointer */
#define HSADC2                                   ((HSADC_Type *)HSADC2_BASE)
/** Peripheral HSADC3 base address */
#define HSADC3_BASE                              (0x4042f000u)
/** Peripheral HSADC3 base pointer */
#define HSADC3                                   ((HSADC_Type *)HSADC3_BASE)
// need fill by yourself
///** Number of interrupt vector arrays for the HSADC module. */
//#define HSADC_IRQS_ARR_COUNT                       (1u)
///** Number of interrupt channels for the HSADC module. */
//#define HSADC_IRQS_CH_COUNT                        (1u)
///** Interrupt vectors for the HSADC peripheral type */
//#define HSADC_IRQS                               {HSADC0_IRQn, HSADC1_IRQn, HSADC2_IRQn, HSADC3_IRQn}


/* ----------------------------------------------------------------------------
   -- HSADC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup HSADC_Register_Masks HSADC Register Masks
 * @{
 */

/* INT_STATUS Bit Fields */
#define HSADC_INT_STATUS_TRGERR_MASK   0x3000000u
#define HSADC_INT_STATUS_TRGERR_SHIFT  24u
#define HSADC_INT_STATUS_TRGERR_WIDTH  2u
#define HSADC_INT_STATUS_TRGERR(x)     (((uint32_t)(((uint32_t)(x))<<HSADC_INT_STATUS_TRGERR_SHIFT))&HSADC_INT_STATUS_TRGERR_MASK)
#define HSADC_INT_STATUS_TRG_PRO_NUM_MASK 0x2000u
#define HSADC_INT_STATUS_TRG_PRO_NUM_SHIFT 13u
#define HSADC_INT_STATUS_TRG_PRO_NUM_WIDTH 1u
#define HSADC_INT_STATUS_TRG_PRO_NUM(x) (((uint32_t)(((uint32_t)(x))<<HSADC_INT_STATUS_TRG_PRO_NUM_SHIFT))&HSADC_INT_STATUS_TRG_PRO_NUM_MASK)
#define HSADC_INT_STATUS_FCR_F_MASK    0x1000u
#define HSADC_INT_STATUS_FCR_F_SHIFT   12u
#define HSADC_INT_STATUS_FCR_F_WIDTH   1u
#define HSADC_INT_STATUS_FCR_F(x)      (((uint32_t)(((uint32_t)(x))<<HSADC_INT_STATUS_FCR_F_SHIFT))&HSADC_INT_STATUS_FCR_F_MASK)
#define HSADC_INT_STATUS_FCR_R_MASK    0x800u
#define HSADC_INT_STATUS_FCR_R_SHIFT   11u
#define HSADC_INT_STATUS_FCR_R_WIDTH   1u
#define HSADC_INT_STATUS_FCR_R(x)      (((uint32_t)(((uint32_t)(x))<<HSADC_INT_STATUS_FCR_R_SHIFT))&HSADC_INT_STATUS_FCR_R_MASK)
#define HSADC_INT_STATUS_RPCNT_RDY_MASK 0x400u
#define HSADC_INT_STATUS_RPCNT_RDY_SHIFT 10u
#define HSADC_INT_STATUS_RPCNT_RDY_WIDTH 1u
#define HSADC_INT_STATUS_RPCNT_RDY(x)  (((uint32_t)(((uint32_t)(x))<<HSADC_INT_STATUS_RPCNT_RDY_SHIFT))&HSADC_INT_STATUS_RPCNT_RDY_MASK)
#define HSADC_INT_STATUS_FCETRG_LVL_MASK 0x200u
#define HSADC_INT_STATUS_FCETRG_LVL_SHIFT 9u
#define HSADC_INT_STATUS_FCETRG_LVL_WIDTH 1u
#define HSADC_INT_STATUS_FCETRG_LVL(x) (((uint32_t)(((uint32_t)(x))<<HSADC_INT_STATUS_FCETRG_LVL_SHIFT))&HSADC_INT_STATUS_FCETRG_LVL_MASK)
#define HSADC_INT_STATUS_FIFO_RDY_MASK 0x100u
#define HSADC_INT_STATUS_FIFO_RDY_SHIFT 8u
#define HSADC_INT_STATUS_FIFO_RDY_WIDTH 1u
#define HSADC_INT_STATUS_FIFO_RDY(x)   (((uint32_t)(((uint32_t)(x))<<HSADC_INT_STATUS_FIFO_RDY_SHIFT))&HSADC_INT_STATUS_FIFO_RDY_MASK)
#define HSADC_INT_STATUS_ACMP_MASK     0x80u
#define HSADC_INT_STATUS_ACMP_SHIFT    7u
#define HSADC_INT_STATUS_ACMP_WIDTH    1u
#define HSADC_INT_STATUS_ACMP(x)       (((uint32_t)(((uint32_t)(x))<<HSADC_INT_STATUS_ACMP_SHIFT))&HSADC_INT_STATUS_ACMP_MASK)
#define HSADC_INT_STATUS_EMPTY_MASK    0x40u
#define HSADC_INT_STATUS_EMPTY_SHIFT   6u
#define HSADC_INT_STATUS_EMPTY_WIDTH   1u
#define HSADC_INT_STATUS_EMPTY(x)      (((uint32_t)(((uint32_t)(x))<<HSADC_INT_STATUS_EMPTY_SHIFT))&HSADC_INT_STATUS_EMPTY_MASK)
#define HSADC_INT_STATUS_FULL_MASK     0x20u
#define HSADC_INT_STATUS_FULL_SHIFT    5u
#define HSADC_INT_STATUS_FULL_WIDTH    1u
#define HSADC_INT_STATUS_FULL(x)       (((uint32_t)(((uint32_t)(x))<<HSADC_INT_STATUS_FULL_SHIFT))&HSADC_INT_STATUS_FULL_MASK)
#define HSADC_INT_STATUS_OVR_MASK      0x10u
#define HSADC_INT_STATUS_OVR_SHIFT     4u
#define HSADC_INT_STATUS_OVR_WIDTH     1u
#define HSADC_INT_STATUS_OVR(x)        (((uint32_t)(((uint32_t)(x))<<HSADC_INT_STATUS_OVR_SHIFT))&HSADC_INT_STATUS_OVR_MASK)
#define HSADC_INT_STATUS_EOSEQ_MASK    0x8u
#define HSADC_INT_STATUS_EOSEQ_SHIFT   3u
#define HSADC_INT_STATUS_EOSEQ_WIDTH   1u
#define HSADC_INT_STATUS_EOSEQ(x)      (((uint32_t)(((uint32_t)(x))<<HSADC_INT_STATUS_EOSEQ_SHIFT))&HSADC_INT_STATUS_EOSEQ_MASK)
#define HSADC_INT_STATUS_EOC_MASK      0x4u
#define HSADC_INT_STATUS_EOC_SHIFT     2u
#define HSADC_INT_STATUS_EOC_WIDTH     1u
#define HSADC_INT_STATUS_EOC(x)        (((uint32_t)(((uint32_t)(x))<<HSADC_INT_STATUS_EOC_SHIFT))&HSADC_INT_STATUS_EOC_MASK)
#define HSADC_INT_STATUS_EOSMP_MASK    0x2u
#define HSADC_INT_STATUS_EOSMP_SHIFT   1u
#define HSADC_INT_STATUS_EOSMP_WIDTH   1u
#define HSADC_INT_STATUS_EOSMP(x)      (((uint32_t)(((uint32_t)(x))<<HSADC_INT_STATUS_EOSMP_SHIFT))&HSADC_INT_STATUS_EOSMP_MASK)
#define HSADC_INT_STATUS_ADRDY_MASK    0x1u
#define HSADC_INT_STATUS_ADRDY_SHIFT   0u
#define HSADC_INT_STATUS_ADRDY_WIDTH   1u
#define HSADC_INT_STATUS_ADRDY(x)      (((uint32_t)(((uint32_t)(x))<<HSADC_INT_STATUS_ADRDY_SHIFT))&HSADC_INT_STATUS_ADRDY_MASK)
/* INT_STATUS Reg Mask */
#define HSADC_INT_STATUS_MASK          0x03003FFFu

/* INT_ENABLE Bit Fields */
#define HSADC_INT_ENABLE_FCR_F_IE_MASK 0x2000u
#define HSADC_INT_ENABLE_FCR_F_IE_SHIFT 13u
#define HSADC_INT_ENABLE_FCR_F_IE_WIDTH 1u
#define HSADC_INT_ENABLE_FCR_F_IE(x)   (((uint32_t)(((uint32_t)(x))<<HSADC_INT_ENABLE_FCR_F_IE_SHIFT))&HSADC_INT_ENABLE_FCR_F_IE_MASK)
#define HSADC_INT_ENABLE_FCR_R_IE_MASK 0x1000u
#define HSADC_INT_ENABLE_FCR_R_IE_SHIFT 12u
#define HSADC_INT_ENABLE_FCR_R_IE_WIDTH 1u
#define HSADC_INT_ENABLE_FCR_R_IE(x)   (((uint32_t)(((uint32_t)(x))<<HSADC_INT_ENABLE_FCR_R_IE_SHIFT))&HSADC_INT_ENABLE_FCR_R_IE_MASK)
#define HSADC_INT_ENABLE_RPCNT_RDY_IE_MASK 0x800u
#define HSADC_INT_ENABLE_RPCNT_RDY_IE_SHIFT 11u
#define HSADC_INT_ENABLE_RPCNT_RDY_IE_WIDTH 1u
#define HSADC_INT_ENABLE_RPCNT_RDY_IE(x) (((uint32_t)(((uint32_t)(x))<<HSADC_INT_ENABLE_RPCNT_RDY_IE_SHIFT))&HSADC_INT_ENABLE_RPCNT_RDY_IE_MASK)
#define HSADC_INT_ENABLE_TRGERR_IE_MASK 0x400u
#define HSADC_INT_ENABLE_TRGERR_IE_SHIFT 10u
#define HSADC_INT_ENABLE_TRGERR_IE_WIDTH 1u
#define HSADC_INT_ENABLE_TRGERR_IE(x)  (((uint32_t)(((uint32_t)(x))<<HSADC_INT_ENABLE_TRGERR_IE_SHIFT))&HSADC_INT_ENABLE_TRGERR_IE_MASK)
#define HSADC_INT_ENABLE_FIFO_RDY_IE_MASK 0x100u
#define HSADC_INT_ENABLE_FIFO_RDY_IE_SHIFT 8u
#define HSADC_INT_ENABLE_FIFO_RDY_IE_WIDTH 1u
#define HSADC_INT_ENABLE_FIFO_RDY_IE(x) (((uint32_t)(((uint32_t)(x))<<HSADC_INT_ENABLE_FIFO_RDY_IE_SHIFT))&HSADC_INT_ENABLE_FIFO_RDY_IE_MASK)
#define HSADC_INT_ENABLE_ACMP_IE_MASK  0x80u
#define HSADC_INT_ENABLE_ACMP_IE_SHIFT 7u
#define HSADC_INT_ENABLE_ACMP_IE_WIDTH 1u
#define HSADC_INT_ENABLE_ACMP_IE(x)    (((uint32_t)(((uint32_t)(x))<<HSADC_INT_ENABLE_ACMP_IE_SHIFT))&HSADC_INT_ENABLE_ACMP_IE_MASK)
#define HSADC_INT_ENABLE_OVRIE_MASK    0x10u
#define HSADC_INT_ENABLE_OVRIE_SHIFT   4u
#define HSADC_INT_ENABLE_OVRIE_WIDTH   1u
#define HSADC_INT_ENABLE_OVRIE(x)      (((uint32_t)(((uint32_t)(x))<<HSADC_INT_ENABLE_OVRIE_SHIFT))&HSADC_INT_ENABLE_OVRIE_MASK)
#define HSADC_INT_ENABLE_EOSEQIE_MASK  0x8u
#define HSADC_INT_ENABLE_EOSEQIE_SHIFT 3u
#define HSADC_INT_ENABLE_EOSEQIE_WIDTH 1u
#define HSADC_INT_ENABLE_EOSEQIE(x)    (((uint32_t)(((uint32_t)(x))<<HSADC_INT_ENABLE_EOSEQIE_SHIFT))&HSADC_INT_ENABLE_EOSEQIE_MASK)
#define HSADC_INT_ENABLE_EOCIE_MASK    0x4u
#define HSADC_INT_ENABLE_EOCIE_SHIFT   2u
#define HSADC_INT_ENABLE_EOCIE_WIDTH   1u
#define HSADC_INT_ENABLE_EOCIE(x)      (((uint32_t)(((uint32_t)(x))<<HSADC_INT_ENABLE_EOCIE_SHIFT))&HSADC_INT_ENABLE_EOCIE_MASK)
#define HSADC_INT_ENABLE_EOSMPIE_MASK  0x2u
#define HSADC_INT_ENABLE_EOSMPIE_SHIFT 1u
#define HSADC_INT_ENABLE_EOSMPIE_WIDTH 1u
#define HSADC_INT_ENABLE_EOSMPIE(x)    (((uint32_t)(((uint32_t)(x))<<HSADC_INT_ENABLE_EOSMPIE_SHIFT))&HSADC_INT_ENABLE_EOSMPIE_MASK)
#define HSADC_INT_ENABLE_ADRDYIE_MASK  0x1u
#define HSADC_INT_ENABLE_ADRDYIE_SHIFT 0u
#define HSADC_INT_ENABLE_ADRDYIE_WIDTH 1u
#define HSADC_INT_ENABLE_ADRDYIE(x)    (((uint32_t)(((uint32_t)(x))<<HSADC_INT_ENABLE_ADRDYIE_SHIFT))&HSADC_INT_ENABLE_ADRDYIE_MASK)
/* INT_ENABLE Reg Mask */
#define HSADC_INT_ENABLE_MASK          0x00003D9Fu

/* CTRL Bit Fields */
#define HSADC_CTRL_FCLK_SEL_MASK       0x20u
#define HSADC_CTRL_FCLK_SEL_SHIFT      5u
#define HSADC_CTRL_FCLK_SEL_WIDTH      1u
#define HSADC_CTRL_FCLK_SEL(x)         (((uint32_t)(((uint32_t)(x))<<HSADC_CTRL_FCLK_SEL_SHIFT))&HSADC_CTRL_FCLK_SEL_MASK)
#define HSADC_CTRL_ADRST_MASK          0x10u
#define HSADC_CTRL_ADRST_SHIFT         4u
#define HSADC_CTRL_ADRST_WIDTH         1u
#define HSADC_CTRL_ADRST(x)            (((uint32_t)(((uint32_t)(x))<<HSADC_CTRL_ADRST_SHIFT))&HSADC_CTRL_ADRST_MASK)
#define HSADC_CTRL_ADSTP_MASK          0x8u
#define HSADC_CTRL_ADSTP_SHIFT         3u
#define HSADC_CTRL_ADSTP_WIDTH         1u
#define HSADC_CTRL_ADSTP(x)            (((uint32_t)(((uint32_t)(x))<<HSADC_CTRL_ADSTP_SHIFT))&HSADC_CTRL_ADSTP_MASK)
#define HSADC_CTRL_ADSTART_MASK        0x4u
#define HSADC_CTRL_ADSTART_SHIFT       2u
#define HSADC_CTRL_ADSTART_WIDTH       1u
#define HSADC_CTRL_ADSTART(x)          (((uint32_t)(((uint32_t)(x))<<HSADC_CTRL_ADSTART_SHIFT))&HSADC_CTRL_ADSTART_MASK)
#define HSADC_CTRL_ADDIS_MASK          0x2u
#define HSADC_CTRL_ADDIS_SHIFT         1u
#define HSADC_CTRL_ADDIS_WIDTH         1u
#define HSADC_CTRL_ADDIS(x)            (((uint32_t)(((uint32_t)(x))<<HSADC_CTRL_ADDIS_SHIFT))&HSADC_CTRL_ADDIS_MASK)
#define HSADC_CTRL_ADEN_MASK           0x1u
#define HSADC_CTRL_ADEN_SHIFT          0u
#define HSADC_CTRL_ADEN_WIDTH          1u
#define HSADC_CTRL_ADEN(x)             (((uint32_t)(((uint32_t)(x))<<HSADC_CTRL_ADEN_SHIFT))&HSADC_CTRL_ADEN_MASK)
/* CTRL Reg Mask */
#define HSADC_CTRL_MASK                0x0000003Fu

/* CFG1 Bit Fields */
#define HSADC_CFG1_OVRMOD_MASK         0x40000000u
#define HSADC_CFG1_OVRMOD_SHIFT        30u
#define HSADC_CFG1_OVRMOD_WIDTH        1u
#define HSADC_CFG1_OVRMOD(x)           (((uint32_t)(((uint32_t)(x))<<HSADC_CFG1_OVRMOD_SHIFT))&HSADC_CFG1_OVRMOD_MASK)
#define HSADC_CFG1_SEQGP_EN_MASK       0x20000000u
#define HSADC_CFG1_SEQGP_EN_SHIFT      29u
#define HSADC_CFG1_SEQGP_EN_WIDTH      1u
#define HSADC_CFG1_SEQGP_EN(x)         (((uint32_t)(((uint32_t)(x))<<HSADC_CFG1_SEQGP_EN_SHIFT))&HSADC_CFG1_SEQGP_EN_MASK)
#define HSADC_CFG1_SEQ_LEN_MASK        0xF000000u
#define HSADC_CFG1_SEQ_LEN_SHIFT       24u
#define HSADC_CFG1_SEQ_LEN_WIDTH       4u
#define HSADC_CFG1_SEQ_LEN(x)          (((uint32_t)(((uint32_t)(x))<<HSADC_CFG1_SEQ_LEN_SHIFT))&HSADC_CFG1_SEQ_LEN_MASK)
#define HSADC_CFG1_SEQ_MOD_MASK        0xC00000u
#define HSADC_CFG1_SEQ_MOD_SHIFT       22u
#define HSADC_CFG1_SEQ_MOD_WIDTH       2u
#define HSADC_CFG1_SEQ_MOD(x)          (((uint32_t)(((uint32_t)(x))<<HSADC_CFG1_SEQ_MOD_SHIFT))&HSADC_CFG1_SEQ_MOD_MASK)
#define HSADC_CFG1_AUTO_DIS_MASK       0x200000u
#define HSADC_CFG1_AUTO_DIS_SHIFT      21u
#define HSADC_CFG1_AUTO_DIS_WIDTH      1u
#define HSADC_CFG1_AUTO_DIS(x)         (((uint32_t)(((uint32_t)(x))<<HSADC_CFG1_AUTO_DIS_SHIFT))&HSADC_CFG1_AUTO_DIS_MASK)
#define HSADC_CFG1_WAIT_MASK           0x100000u
#define HSADC_CFG1_WAIT_SHIFT          20u
#define HSADC_CFG1_WAIT_WIDTH          1u
#define HSADC_CFG1_WAIT(x)             (((uint32_t)(((uint32_t)(x))<<HSADC_CFG1_WAIT_SHIFT))&HSADC_CFG1_WAIT_MASK)
#define HSADC_CFG1_TRIGSRC_MASK        0x70000u
#define HSADC_CFG1_TRIGSRC_SHIFT       16u
#define HSADC_CFG1_TRIGSRC_WIDTH       3u
#define HSADC_CFG1_TRIGSRC(x)          (((uint32_t)(((uint32_t)(x))<<HSADC_CFG1_TRIGSRC_SHIFT))&HSADC_CFG1_TRIGSRC_MASK)
#define HSADC_CFG1_TRIGMODE_MASK       0x3800u
#define HSADC_CFG1_TRIGMODE_SHIFT      11u
#define HSADC_CFG1_TRIGMODE_WIDTH      3u
#define HSADC_CFG1_TRIGMODE(x)         (((uint32_t)(((uint32_t)(x))<<HSADC_CFG1_TRIGMODE_SHIFT))&HSADC_CFG1_TRIGMODE_MASK)
#define HSADC_CFG1_ALIGN_MASK          0x400u
#define HSADC_CFG1_ALIGN_SHIFT         10u
#define HSADC_CFG1_ALIGN_WIDTH         1u
#define HSADC_CFG1_ALIGN(x)            (((uint32_t)(((uint32_t)(x))<<HSADC_CFG1_ALIGN_SHIFT))&HSADC_CFG1_ALIGN_MASK)
#define HSADC_CFG1_SGDMA_SEL_MASK      0x4u
#define HSADC_CFG1_SGDMA_SEL_SHIFT     2u
#define HSADC_CFG1_SGDMA_SEL_WIDTH     1u
#define HSADC_CFG1_SGDMA_SEL(x)        (((uint32_t)(((uint32_t)(x))<<HSADC_CFG1_SGDMA_SEL_SHIFT))&HSADC_CFG1_SGDMA_SEL_MASK)
#define HSADC_CFG1_SGDMAEN_MASK        0x2u
#define HSADC_CFG1_SGDMAEN_SHIFT       1u
#define HSADC_CFG1_SGDMAEN_WIDTH       1u
#define HSADC_CFG1_SGDMAEN(x)          (((uint32_t)(((uint32_t)(x))<<HSADC_CFG1_SGDMAEN_SHIFT))&HSADC_CFG1_SGDMAEN_MASK)
#define HSADC_CFG1_DMAEN_MASK          0x1u
#define HSADC_CFG1_DMAEN_SHIFT         0u
#define HSADC_CFG1_DMAEN_WIDTH         1u
#define HSADC_CFG1_DMAEN(x)            (((uint32_t)(((uint32_t)(x))<<HSADC_CFG1_DMAEN_SHIFT))&HSADC_CFG1_DMAEN_MASK)
/* CFG1 Reg Mask */
#define HSADC_CFG1_MASK                0x6FF73C07u

/* CFG2 Bit Fields */
#define HSADC_CFG2_EXT_CH_EN_MASK      0x80000000u
#define HSADC_CFG2_EXT_CH_EN_SHIFT     31u
#define HSADC_CFG2_EXT_CH_EN_WIDTH     1u
#define HSADC_CFG2_EXT_CH_EN(x)        (((uint32_t)(((uint32_t)(x))<<HSADC_CFG2_EXT_CH_EN_SHIFT))&HSADC_CFG2_EXT_CH_EN_MASK)
#define HSADC_CFG2_FWMARK_MASK         0xF000000u
#define HSADC_CFG2_FWMARK_SHIFT        24u
#define HSADC_CFG2_FWMARK_WIDTH        4u
#define HSADC_CFG2_FWMARK(x)           (((uint32_t)(((uint32_t)(x))<<HSADC_CFG2_FWMARK_SHIFT))&HSADC_CFG2_FWMARK_MASK)
#define HSADC_CFG2_SMP_SPARE_EN_MASK   0x200000u
#define HSADC_CFG2_SMP_SPARE_EN_SHIFT  21u
#define HSADC_CFG2_SMP_SPARE_EN_WIDTH  1u
#define HSADC_CFG2_SMP_SPARE_EN(x)     (((uint32_t)(((uint32_t)(x))<<HSADC_CFG2_SMP_SPARE_EN_SHIFT))&HSADC_CFG2_SMP_SPARE_EN_MASK)
#define HSADC_CFG2_TRG_PRI_MASK        0x100000u
#define HSADC_CFG2_TRG_PRI_SHIFT       20u
#define HSADC_CFG2_TRG_PRI_WIDTH       1u
#define HSADC_CFG2_TRG_PRI(x)          (((uint32_t)(((uint32_t)(x))<<HSADC_CFG2_TRG_PRI_SHIFT))&HSADC_CFG2_TRG_PRI_MASK)
#define HSADC_CFG2_TRG_CLR_MASK        0x80000u
#define HSADC_CFG2_TRG_CLR_SHIFT       19u
#define HSADC_CFG2_TRG_CLR_WIDTH       1u
#define HSADC_CFG2_TRG_CLR(x)          (((uint32_t)(((uint32_t)(x))<<HSADC_CFG2_TRG_CLR_SHIFT))&HSADC_CFG2_TRG_CLR_MASK)
#define HSADC_CFG2_AVG_EN_MASK         0x40000u
#define HSADC_CFG2_AVG_EN_SHIFT        18u
#define HSADC_CFG2_AVG_EN_WIDTH        1u
#define HSADC_CFG2_AVG_EN(x)           (((uint32_t)(((uint32_t)(x))<<HSADC_CFG2_AVG_EN_SHIFT))&HSADC_CFG2_AVG_EN_MASK)
#define HSADC_CFG2_AVG_LEN_MASK        0x30000u
#define HSADC_CFG2_AVG_LEN_SHIFT       16u
#define HSADC_CFG2_AVG_LEN_WIDTH       2u
#define HSADC_CFG2_AVG_LEN(x)          (((uint32_t)(((uint32_t)(x))<<HSADC_CFG2_AVG_LEN_SHIFT))&HSADC_CFG2_AVG_LEN_MASK)
#define HSADC_CFG2_CG_ACK_MASK         0x4000u
#define HSADC_CFG2_CG_ACK_SHIFT        14u
#define HSADC_CFG2_CG_ACK_WIDTH        1u
#define HSADC_CFG2_CG_ACK(x)           (((uint32_t)(((uint32_t)(x))<<HSADC_CFG2_CG_ACK_SHIFT))&HSADC_CFG2_CG_ACK_MASK)
#define HSADC_CFG2_CG_MASK             0x2000u
#define HSADC_CFG2_CG_SHIFT            13u
#define HSADC_CFG2_CG_WIDTH            1u
#define HSADC_CFG2_CG(x)               (((uint32_t)(((uint32_t)(x))<<HSADC_CFG2_CG_SHIFT))&HSADC_CFG2_CG_MASK)
#define HSADC_CFG2_DIV_MASK            0x300u
#define HSADC_CFG2_DIV_SHIFT           8u
#define HSADC_CFG2_DIV_WIDTH           2u
#define HSADC_CFG2_DIV(x)              (((uint32_t)(((uint32_t)(x))<<HSADC_CFG2_DIV_SHIFT))&HSADC_CFG2_DIV_MASK)
#define HSADC_CFG2_STCNT_MASK          0xFFu
#define HSADC_CFG2_STCNT_SHIFT         0u
#define HSADC_CFG2_STCNT_WIDTH         8u
#define HSADC_CFG2_STCNT(x)            (((uint32_t)(((uint32_t)(x))<<HSADC_CFG2_STCNT_SHIFT))&HSADC_CFG2_STCNT_MASK)
/* CFG2 Reg Mask */
#define HSADC_CFG2_MASK                0x8F3F63FFu

/* SMPR Bit Fields */
#define HSADC_SMPR_SMP_OPT3_MASK       0xFF000000u
#define HSADC_SMPR_SMP_OPT3_SHIFT      24u
#define HSADC_SMPR_SMP_OPT3_WIDTH      8u
#define HSADC_SMPR_SMP_OPT3(x)         (((uint32_t)(((uint32_t)(x))<<HSADC_SMPR_SMP_OPT3_SHIFT))&HSADC_SMPR_SMP_OPT3_MASK)
#define HSADC_SMPR_SMP_OPT2_MASK       0xFF0000u
#define HSADC_SMPR_SMP_OPT2_SHIFT      16u
#define HSADC_SMPR_SMP_OPT2_WIDTH      8u
#define HSADC_SMPR_SMP_OPT2(x)         (((uint32_t)(((uint32_t)(x))<<HSADC_SMPR_SMP_OPT2_SHIFT))&HSADC_SMPR_SMP_OPT2_MASK)
#define HSADC_SMPR_SMP_OPT1_MASK       0xFF00u
#define HSADC_SMPR_SMP_OPT1_SHIFT      8u
#define HSADC_SMPR_SMP_OPT1_WIDTH      8u
#define HSADC_SMPR_SMP_OPT1(x)         (((uint32_t)(((uint32_t)(x))<<HSADC_SMPR_SMP_OPT1_SHIFT))&HSADC_SMPR_SMP_OPT1_MASK)
#define HSADC_SMPR_SMP_OPT0_MASK       0xFFu
#define HSADC_SMPR_SMP_OPT0_SHIFT      0u
#define HSADC_SMPR_SMP_OPT0_WIDTH      8u
#define HSADC_SMPR_SMP_OPT0(x)         (((uint32_t)(((uint32_t)(x))<<HSADC_SMPR_SMP_OPT0_SHIFT))&HSADC_SMPR_SMP_OPT0_MASK)
/* SMPR Reg Mask */
#define HSADC_SMPR_MASK                0xFFFFFFFFu

/* CMP_CTRL Bit Fields */
#define HSADC_CMP_CTRL_ACMPEN_MASK     0x80u
#define HSADC_CMP_CTRL_ACMPEN_SHIFT    7u
#define HSADC_CMP_CTRL_ACMPEN_WIDTH    1u
#define HSADC_CMP_CTRL_ACMPEN(x)       (((uint32_t)(((uint32_t)(x))<<HSADC_CMP_CTRL_ACMPEN_SHIFT))&HSADC_CMP_CTRL_ACMPEN_MASK)
#define HSADC_CMP_CTRL_ACMPSGL_MASK    0x40u
#define HSADC_CMP_CTRL_ACMPSGL_SHIFT   6u
#define HSADC_CMP_CTRL_ACMPSGL_WIDTH   1u
#define HSADC_CMP_CTRL_ACMPSGL(x)      (((uint32_t)(((uint32_t)(x))<<HSADC_CMP_CTRL_ACMPSGL_SHIFT))&HSADC_CMP_CTRL_ACMPSGL_MASK)
#define HSADC_CMP_CTRL_ACMPCH_MASK     0x3Fu
#define HSADC_CMP_CTRL_ACMPCH_SHIFT    0u
#define HSADC_CMP_CTRL_ACMPCH_WIDTH    6u
#define HSADC_CMP_CTRL_ACMPCH(x)       (((uint32_t)(((uint32_t)(x))<<HSADC_CMP_CTRL_ACMPCH_SHIFT))&HSADC_CMP_CTRL_ACMPCH_MASK)
/* CMP_CTRL Reg Mask */
#define HSADC_CMP_CTRL_MASK            0x000000FFu

/* CMP_TR Bit Fields */
#define HSADC_CMP_TR_HT_MASK           0xFFF0000u
#define HSADC_CMP_TR_HT_SHIFT          16u
#define HSADC_CMP_TR_HT_WIDTH          12u
#define HSADC_CMP_TR_HT(x)             (((uint32_t)(((uint32_t)(x))<<HSADC_CMP_TR_HT_SHIFT))&HSADC_CMP_TR_HT_MASK)
#define HSADC_CMP_TR_LT_MASK           0xFFFu
#define HSADC_CMP_TR_LT_SHIFT          0u
#define HSADC_CMP_TR_LT_WIDTH          12u
#define HSADC_CMP_TR_LT(x)             (((uint32_t)(((uint32_t)(x))<<HSADC_CMP_TR_LT_SHIFT))&HSADC_CMP_TR_LT_MASK)
/* CMP_TR Reg Mask */
#define HSADC_CMP_TR_MASK              0x0FFF0FFFu

/* CFG3 Bit Fields */
#define HSADC_CFG3_EOSG_OSEL_MASK      0x20000000u
#define HSADC_CFG3_EOSG_OSEL_SHIFT     29u
#define HSADC_CFG3_EOSG_OSEL_WIDTH     1u
#define HSADC_CFG3_EOSG_OSEL(x)        (((uint32_t)(((uint32_t)(x))<<HSADC_CFG3_EOSG_OSEL_SHIFT))&HSADC_CFG3_EOSG_OSEL_MASK)
#define HSADC_CFG3_COCO_OSEL_MASK      0xF000000u
#define HSADC_CFG3_COCO_OSEL_SHIFT     24u
#define HSADC_CFG3_COCO_OSEL_WIDTH     4u
#define HSADC_CFG3_COCO_OSEL(x)        (((uint32_t)(((uint32_t)(x))<<HSADC_CFG3_COCO_OSEL_SHIFT))&HSADC_CFG3_COCO_OSEL_MASK)
#define HSADC_CFG3_ACMPR_OEN_MASK      0x100000u
#define HSADC_CFG3_ACMPR_OEN_SHIFT     20u
#define HSADC_CFG3_ACMPR_OEN_WIDTH     1u
#define HSADC_CFG3_ACMPR_OEN(x)        (((uint32_t)(((uint32_t)(x))<<HSADC_CFG3_ACMPR_OEN_SHIFT))&HSADC_CFG3_ACMPR_OEN_MASK)
#define HSADC_CFG3_ACMPF_OEN_MASK      0x80000u
#define HSADC_CFG3_ACMPF_OEN_SHIFT     19u
#define HSADC_CFG3_ACMPF_OEN_WIDTH     1u
#define HSADC_CFG3_ACMPF_OEN(x)        (((uint32_t)(((uint32_t)(x))<<HSADC_CFG3_ACMPF_OEN_SHIFT))&HSADC_CFG3_ACMPF_OEN_MASK)
#define HSADC_CFG3_BFL_OEN_MASK        0x40000u
#define HSADC_CFG3_BFL_OEN_SHIFT       18u
#define HSADC_CFG3_BFL_OEN_WIDTH       1u
#define HSADC_CFG3_BFL_OEN(x)          (((uint32_t)(((uint32_t)(x))<<HSADC_CFG3_BFL_OEN_SHIFT))&HSADC_CFG3_BFL_OEN_MASK)
#define HSADC_CFG3_FCR_R_OEN_MASK      0x20000u
#define HSADC_CFG3_FCR_R_OEN_SHIFT     17u
#define HSADC_CFG3_FCR_R_OEN_WIDTH     1u
#define HSADC_CFG3_FCR_R_OEN(x)        (((uint32_t)(((uint32_t)(x))<<HSADC_CFG3_FCR_R_OEN_SHIFT))&HSADC_CFG3_FCR_R_OEN_MASK)
#define HSADC_CFG3_FCR_F_OEN_MASK      0x10000u
#define HSADC_CFG3_FCR_F_OEN_SHIFT     16u
#define HSADC_CFG3_FCR_F_OEN_WIDTH     1u
#define HSADC_CFG3_FCR_F_OEN(x)        (((uint32_t)(((uint32_t)(x))<<HSADC_CFG3_FCR_F_OEN_SHIFT))&HSADC_CFG3_FCR_F_OEN_MASK)
#define HSADC_CFG3_PTRGIV_MASK         0x3FFu
#define HSADC_CFG3_PTRGIV_SHIFT        0u
#define HSADC_CFG3_PTRGIV_WIDTH        10u
#define HSADC_CFG3_PTRGIV(x)           (((uint32_t)(((uint32_t)(x))<<HSADC_CFG3_PTRGIV_SHIFT))&HSADC_CFG3_PTRGIV_MASK)
/* CFG3 Reg Mask */
#define HSADC_CFG3_MASK                0x2F1F03FFu

/* SGCSR Bit Fields */
#define HSADC_SGCSR_EOSG_MASK          0x1000000u
#define HSADC_SGCSR_EOSG_SHIFT         24u
#define HSADC_SGCSR_EOSG_WIDTH         1u
#define HSADC_SGCSR_EOSG(x)            (((uint32_t)(((uint32_t)(x))<<HSADC_SGCSR_EOSG_SHIFT))&HSADC_SGCSR_EOSG_MASK)
#define HSADC_SGCSR_EOSGIE_MASK        0x10000u
#define HSADC_SGCSR_EOSGIE_SHIFT       16u
#define HSADC_SGCSR_EOSGIE_WIDTH       1u
#define HSADC_SGCSR_EOSGIE(x)          (((uint32_t)(((uint32_t)(x))<<HSADC_SGCSR_EOSGIE_SHIFT))&HSADC_SGCSR_EOSGIE_MASK)
#define HSADC_SGCSR_SG_END_MASK        0xF00u
#define HSADC_SGCSR_SG_END_SHIFT       8u
#define HSADC_SGCSR_SG_END_WIDTH       4u
#define HSADC_SGCSR_SG_END(x)          (((uint32_t)(((uint32_t)(x))<<HSADC_SGCSR_SG_END_SHIFT))&HSADC_SGCSR_SG_END_MASK)
#define HSADC_SGCSR_SG_START_MASK      0xFu
#define HSADC_SGCSR_SG_START_SHIFT     0u
#define HSADC_SGCSR_SG_START_WIDTH     4u
#define HSADC_SGCSR_SG_START(x)        (((uint32_t)(((uint32_t)(x))<<HSADC_SGCSR_SG_START_SHIFT))&HSADC_SGCSR_SG_START_MASK)
/* SGCSR0 Reg Mask */
#define HSADC_SGCSR_MASK               0x01010F0Fu

/* OGCR Bit Fields */
#define HSADC_OGCR_OGC_EN_MASK         0x80000000u
#define HSADC_OGCR_OGC_EN_SHIFT        31u
#define HSADC_OGCR_OGC_EN_WIDTH        1u
#define HSADC_OGCR_OGC_EN(x)           (((uint32_t)(((uint32_t)(x))<<HSADC_OGCR_OGC_EN_SHIFT))&HSADC_OGCR_OGC_EN_MASK)
#define HSADC_OGCR_OFFSET_MASK         0x3FF0000u
#define HSADC_OGCR_OFFSET_SHIFT        16u
#define HSADC_OGCR_OFFSET_WIDTH        10u
#define HSADC_OGCR_OFFSET(x)           (((uint32_t)(((uint32_t)(x))<<HSADC_OGCR_OFFSET_SHIFT))&HSADC_OGCR_OFFSET_MASK)
#define HSADC_OGCR_GAIN_MASK           0xFFFu
#define HSADC_OGCR_GAIN_SHIFT          0u
#define HSADC_OGCR_GAIN_WIDTH          12u
#define HSADC_OGCR_GAIN(x)             (((uint32_t)(((uint32_t)(x))<<HSADC_OGCR_GAIN_SHIFT))&HSADC_OGCR_GAIN_MASK)
/* OGCR Reg Mask */
#define HSADC_OGCR_MASK                0x83FF0FFFu

/* CCAL Bit Fields */
#define HSADC_CCAL_CCAL_EN_MASK        0x80000000u
#define HSADC_CCAL_CCAL_EN_SHIFT       31u
#define HSADC_CCAL_CCAL_EN_WIDTH       1u
#define HSADC_CCAL_CCAL_EN(x)          (((uint32_t)(((uint32_t)(x))<<HSADC_CCAL_CCAL_EN_SHIFT))&HSADC_CCAL_CCAL_EN_MASK)
/* CCAL Reg Mask */
#define HSADC_CCAL_MASK                0x80000000u

/* FIFO_DATA Bit Fields */
#define HSADC_FIFO_DATA_FIFO_DATA_MASK 0xFFFFu
#define HSADC_FIFO_DATA_FIFO_DATA_SHIFT 0u
#define HSADC_FIFO_DATA_FIFO_DATA_WIDTH 16u
#define HSADC_FIFO_DATA_FIFO_DATA(x)   (((uint32_t)(((uint32_t)(x))<<HSADC_FIFO_DATA_FIFO_DATA_SHIFT))&HSADC_FIFO_DATA_FIFO_DATA_MASK)
/* FIFO_DATA Reg Mask */
#define HSADC_FIFO_DATA_MASK           0x0000FFFFu

/* SC Bit Fields */
#define HSADC_SC_SMPSEL_MASK           0x300u
#define HSADC_SC_SMPSEL_SHIFT          8u
#define HSADC_SC_SMPSEL_WIDTH          2u
#define HSADC_SC_SMPSEL(x)             (((uint32_t)(((uint32_t)(x))<<HSADC_SC_SMPSEL_SHIFT))&HSADC_SC_SMPSEL_MASK)
#define HSADC_SC_COCO_MASK             0x80u
#define HSADC_SC_COCO_SHIFT            7u
#define HSADC_SC_COCO_WIDTH            1u
#define HSADC_SC_COCO(x)               (((uint32_t)(((uint32_t)(x))<<HSADC_SC_COCO_SHIFT))&HSADC_SC_COCO_MASK)
#define HSADC_SC_AIEN_MASK             0x40u
#define HSADC_SC_AIEN_SHIFT            6u
#define HSADC_SC_AIEN_WIDTH            1u
#define HSADC_SC_AIEN(x)               (((uint32_t)(((uint32_t)(x))<<HSADC_SC_AIEN_SHIFT))&HSADC_SC_AIEN_MASK)
#define HSADC_SC_CHS_MASK              0x3Fu
#define HSADC_SC_CHS_SHIFT             0u
#define HSADC_SC_CHS_WIDTH             6u
#define HSADC_SC_CHS(x)                (((uint32_t)(((uint32_t)(x))<<HSADC_SC_CHS_SHIFT))&HSADC_SC_CHS_MASK)
/* SC0 Reg Mask */
#define HSADC_SC_MASK                  0x000003FFu

/* RESULT Bit Fields */
#define HSADC_RESULT_RESULT_MASK       0xFFFFu
#define HSADC_RESULT_RESULT_SHIFT      0u
#define HSADC_RESULT_RESULT_WIDTH      16u
#define HSADC_RESULT_RESULT(x)         (((uint32_t)(((uint32_t)(x))<<HSADC_RESULT_RESULT_SHIFT))&HSADC_RESULT_RESULT_MASK)
/* RESULT0 Reg Mask */
#define HSADC_RESULT_MASK              0x0000FFFFu

/* RESULT_CAL Bit Fields */
#define HSADC_RESULT_CAL_DATA_MASK     0x3FFFu
#define HSADC_RESULT_CAL_DATA_SHIFT    0u
#define HSADC_RESULT_CAL_DATA_WIDTH    14u
#define HSADC_RESULT_CAL_DATA(x)       (((uint32_t)(((uint32_t)(x))<<HSADC_RESULT_CAL_DATA_SHIFT))&HSADC_RESULT_CAL_DATA_MASK)
/* RESULT_CAL Reg Mask */
#define HSADC_RESULT_CAL_MASK          0x00003FFFu

/* DCAPWT0 Bit Fields */
#define HSADC_DCAPWT0_CAP5_MASK        0xFF0000u
#define HSADC_DCAPWT0_CAP5_SHIFT       16u
#define HSADC_DCAPWT0_CAP5_WIDTH       8u
#define HSADC_DCAPWT0_CAP5(x)          (((uint32_t)(((uint32_t)(x))<<HSADC_DCAPWT0_CAP5_SHIFT))&HSADC_DCAPWT0_CAP5_MASK)
#define HSADC_DCAPWT0_CAP4_MASK        0xFFu
#define HSADC_DCAPWT0_CAP4_SHIFT       0u
#define HSADC_DCAPWT0_CAP4_WIDTH       8u
#define HSADC_DCAPWT0_CAP4(x)          (((uint32_t)(((uint32_t)(x))<<HSADC_DCAPWT0_CAP4_SHIFT))&HSADC_DCAPWT0_CAP4_MASK)
/* DCAPWT0 Reg Mask */
#define HSADC_DCAPWT0_MASK             0x00FF00FFu

/* DCAPWT1 Bit Fields */
#define HSADC_DCAPWT1_CAP7_MASK        0x1FF0000u
#define HSADC_DCAPWT1_CAP7_SHIFT       16u
#define HSADC_DCAPWT1_CAP7_WIDTH       9u
#define HSADC_DCAPWT1_CAP7(x)          (((uint32_t)(((uint32_t)(x))<<HSADC_DCAPWT1_CAP7_SHIFT))&HSADC_DCAPWT1_CAP7_MASK)
#define HSADC_DCAPWT1_CAP6_MASK        0xFFu
#define HSADC_DCAPWT1_CAP6_SHIFT       0u
#define HSADC_DCAPWT1_CAP6_WIDTH       8u
#define HSADC_DCAPWT1_CAP6(x)          (((uint32_t)(((uint32_t)(x))<<HSADC_DCAPWT1_CAP6_SHIFT))&HSADC_DCAPWT1_CAP6_MASK)
/* DCAPWT1 Reg Mask */
#define HSADC_DCAPWT1_MASK             0x01FF00FFu

/* DCAPWT2 Bit Fields */
#define HSADC_DCAPWT2_CAP9_MASK        0x3FF0000u
#define HSADC_DCAPWT2_CAP9_SHIFT       16u
#define HSADC_DCAPWT2_CAP9_WIDTH       10u
#define HSADC_DCAPWT2_CAP9(x)          (((uint32_t)(((uint32_t)(x))<<HSADC_DCAPWT2_CAP9_SHIFT))&HSADC_DCAPWT2_CAP9_MASK)
#define HSADC_DCAPWT2_CAP8_MASK        0x1FFu
#define HSADC_DCAPWT2_CAP8_SHIFT       0u
#define HSADC_DCAPWT2_CAP8_WIDTH       9u
#define HSADC_DCAPWT2_CAP8(x)          (((uint32_t)(((uint32_t)(x))<<HSADC_DCAPWT2_CAP8_SHIFT))&HSADC_DCAPWT2_CAP8_MASK)
/* DCAPWT2 Reg Mask */
#define HSADC_DCAPWT2_MASK             0x03FF01FFu

/* DCAPWT3 Bit Fields */
#define HSADC_DCAPWT3_CAP11_MASK       0x7FF0000u
#define HSADC_DCAPWT3_CAP11_SHIFT      16u
#define HSADC_DCAPWT3_CAP11_WIDTH      11u
#define HSADC_DCAPWT3_CAP11(x)         (((uint32_t)(((uint32_t)(x))<<HSADC_DCAPWT3_CAP11_SHIFT))&HSADC_DCAPWT3_CAP11_MASK)
#define HSADC_DCAPWT3_CAP10_MASK       0x7FFu
#define HSADC_DCAPWT3_CAP10_SHIFT      0u
#define HSADC_DCAPWT3_CAP10_WIDTH      11u
#define HSADC_DCAPWT3_CAP10(x)         (((uint32_t)(((uint32_t)(x))<<HSADC_DCAPWT3_CAP10_SHIFT))&HSADC_DCAPWT3_CAP10_MASK)
/* DCAPWT3 Reg Mask */
#define HSADC_DCAPWT3_MASK             0x07FF07FFu

/* DCAPWT4 Bit Fields */
#define HSADC_DCAPWT4_CAP13_MASK       0xFFF0000u
#define HSADC_DCAPWT4_CAP13_SHIFT      16u
#define HSADC_DCAPWT4_CAP13_WIDTH      12u
#define HSADC_DCAPWT4_CAP13(x)         (((uint32_t)(((uint32_t)(x))<<HSADC_DCAPWT4_CAP13_SHIFT))&HSADC_DCAPWT4_CAP13_MASK)
#define HSADC_DCAPWT4_CAP12_MASK       0xFFFu
#define HSADC_DCAPWT4_CAP12_SHIFT      0u
#define HSADC_DCAPWT4_CAP12_WIDTH      12u
#define HSADC_DCAPWT4_CAP12(x)         (((uint32_t)(((uint32_t)(x))<<HSADC_DCAPWT4_CAP12_SHIFT))&HSADC_DCAPWT4_CAP12_MASK)
/* DCAPWT4 Reg Mask */
#define HSADC_DCAPWT4_MASK             0x0FFF0FFFu

/* DCAPWT5 Bit Fields */
#define HSADC_DCAPWT5_CAP15_MASK       0x3FFF0000u
#define HSADC_DCAPWT5_CAP15_SHIFT      16u
#define HSADC_DCAPWT5_CAP15_WIDTH      14u
#define HSADC_DCAPWT5_CAP15(x)         (((uint32_t)(((uint32_t)(x))<<HSADC_DCAPWT5_CAP15_SHIFT))&HSADC_DCAPWT5_CAP15_MASK)
#define HSADC_DCAPWT5_CAP14_MASK       0x1FFFu
#define HSADC_DCAPWT5_CAP14_SHIFT      0u
#define HSADC_DCAPWT5_CAP14_WIDTH      13u
#define HSADC_DCAPWT5_CAP14(x)         (((uint32_t)(((uint32_t)(x))<<HSADC_DCAPWT5_CAP14_SHIFT))&HSADC_DCAPWT5_CAP14_MASK)
/* DCAPWT5 Reg Mask */
#define HSADC_DCAPWT5_MASK             0x3FFF1FFFu

/* DCAPWT6 Bit Fields */
#define HSADC_DCAPWT6_CAP17_MASK       0x7FFF0000u
#define HSADC_DCAPWT6_CAP17_SHIFT      16u
#define HSADC_DCAPWT6_CAP17_WIDTH      15u
#define HSADC_DCAPWT6_CAP17(x)         (((uint32_t)(((uint32_t)(x))<<HSADC_DCAPWT6_CAP17_SHIFT))&HSADC_DCAPWT6_CAP17_MASK)
#define HSADC_DCAPWT6_CAP16_MASK       0x7FFFu
#define HSADC_DCAPWT6_CAP16_SHIFT      0u
#define HSADC_DCAPWT6_CAP16_WIDTH      15u
#define HSADC_DCAPWT6_CAP16(x)         (((uint32_t)(((uint32_t)(x))<<HSADC_DCAPWT6_CAP16_SHIFT))&HSADC_DCAPWT6_CAP16_MASK)
/* DCAPWT6 Reg Mask */
#define HSADC_DCAPWT6_MASK             0x7FFF7FFFu

/* FCMP_CTRL Bit Fields */
#define HSADC_FCMP_CTRL_DATA_SAVE_MASK 0x800u
#define HSADC_FCMP_CTRL_DATA_SAVE_SHIFT 11u
#define HSADC_FCMP_CTRL_DATA_SAVE_WIDTH 1u
#define HSADC_FCMP_CTRL_DATA_SAVE(x)   (((uint32_t)(((uint32_t)(x))<<HSADC_FCMP_CTRL_DATA_SAVE_SHIFT))&HSADC_FCMP_CTRL_DATA_SAVE_MASK)
#define HSADC_FCMP_CTRL_RPTRG_SEL_MASK 0x600u
#define HSADC_FCMP_CTRL_RPTRG_SEL_SHIFT 9u
#define HSADC_FCMP_CTRL_RPTRG_SEL_WIDTH 2u
#define HSADC_FCMP_CTRL_RPTRG_SEL(x)   (((uint32_t)(((uint32_t)(x))<<HSADC_FCMP_CTRL_RPTRG_SEL_SHIFT))&HSADC_FCMP_CTRL_RPTRG_SEL_MASK)
#define HSADC_FCMP_CTRL_RPCNT_EN_MASK  0x100u
#define HSADC_FCMP_CTRL_RPCNT_EN_SHIFT 8u
#define HSADC_FCMP_CTRL_RPCNT_EN_WIDTH 1u
#define HSADC_FCMP_CTRL_RPCNT_EN(x)    (((uint32_t)(((uint32_t)(x))<<HSADC_FCMP_CTRL_RPCNT_EN_SHIFT))&HSADC_FCMP_CTRL_RPCNT_EN_MASK)
#define HSADC_FCMP_CTRL_RP_SWTRG_MASK  0x10u
#define HSADC_FCMP_CTRL_RP_SWTRG_SHIFT 4u
#define HSADC_FCMP_CTRL_RP_SWTRG_WIDTH 1u
#define HSADC_FCMP_CTRL_RP_SWTRG(x)    (((uint32_t)(((uint32_t)(x))<<HSADC_FCMP_CTRL_RP_SWTRG_SHIFT))&HSADC_FCMP_CTRL_RP_SWTRG_MASK)
#define HSADC_FCMP_CTRL_ETRG_POL_MASK  0x8u
#define HSADC_FCMP_CTRL_ETRG_POL_SHIFT 3u
#define HSADC_FCMP_CTRL_ETRG_POL_WIDTH 1u
#define HSADC_FCMP_CTRL_ETRG_POL(x)    (((uint32_t)(((uint32_t)(x))<<HSADC_FCMP_CTRL_ETRG_POL_SHIFT))&HSADC_FCMP_CTRL_ETRG_POL_MASK)
#define HSADC_FCMP_CTRL_FCMOD_ALT_MASK 0x4u
#define HSADC_FCMP_CTRL_FCMOD_ALT_SHIFT 2u
#define HSADC_FCMP_CTRL_FCMOD_ALT_WIDTH 1u
#define HSADC_FCMP_CTRL_FCMOD_ALT(x)   (((uint32_t)(((uint32_t)(x))<<HSADC_FCMP_CTRL_FCMOD_ALT_SHIFT))&HSADC_FCMP_CTRL_FCMOD_ALT_MASK)
#define HSADC_FCMP_CTRL_FC_DSEL_MASK   0x2u
#define HSADC_FCMP_CTRL_FC_DSEL_SHIFT  1u
#define HSADC_FCMP_CTRL_FC_DSEL_WIDTH  1u
#define HSADC_FCMP_CTRL_FC_DSEL(x)     (((uint32_t)(((uint32_t)(x))<<HSADC_FCMP_CTRL_FC_DSEL_SHIFT))&HSADC_FCMP_CTRL_FC_DSEL_MASK)
#define HSADC_FCMP_CTRL_FC_EN_MASK     0x1u
#define HSADC_FCMP_CTRL_FC_EN_SHIFT    0u
#define HSADC_FCMP_CTRL_FC_EN_WIDTH    1u
#define HSADC_FCMP_CTRL_FC_EN(x)       (((uint32_t)(((uint32_t)(x))<<HSADC_FCMP_CTRL_FC_EN_SHIFT))&HSADC_FCMP_CTRL_FC_EN_MASK)
/* FCMP_CTRL Reg Mask */
#define HSADC_FCMP_CTRL_MASK           0x00000F1Fu

/* FCREF Bit Fields */
#define HSADC_FCREF_FCREF_MASK         0x1FFFu
#define HSADC_FCREF_FCREF_SHIFT        0u
#define HSADC_FCREF_FCREF_WIDTH        13u
#define HSADC_FCREF_FCREF(x)           (((uint32_t)(((uint32_t)(x))<<HSADC_FCREF_FCREF_SHIFT))&HSADC_FCREF_FCREF_MASK)
/* FCREF Reg Mask */
#define HSADC_FCREF_MASK               0x00001FFFu

/* FCRAMP0 Bit Fields */
#define HSADC_FCRAMP0_FCREF_A_MASK     0x1FFF0000u
#define HSADC_FCRAMP0_FCREF_A_SHIFT    16u
#define HSADC_FCRAMP0_FCREF_A_WIDTH    13u
#define HSADC_FCRAMP0_FCREF_A(x)       (((uint32_t)(((uint32_t)(x))<<HSADC_FCRAMP0_FCREF_A_SHIFT))&HSADC_FCRAMP0_FCREF_A_MASK)
#define HSADC_FCRAMP0_RPSTEP_MASK      0xFFu
#define HSADC_FCRAMP0_RPSTEP_SHIFT     0u
#define HSADC_FCRAMP0_RPSTEP_WIDTH     8u
#define HSADC_FCRAMP0_RPSTEP(x)        (((uint32_t)(((uint32_t)(x))<<HSADC_FCRAMP0_RPSTEP_SHIFT))&HSADC_FCRAMP0_RPSTEP_MASK)
/* FCRAMP0 Reg Mask */
#define HSADC_FCRAMP0_MASK             0x1FFF00FFu

/* FCRAMP1 Bit Fields */
#define HSADC_FCRAMP1_FCREF_B_MASK     0x1FFF0000u
#define HSADC_FCRAMP1_FCREF_B_SHIFT    16u
#define HSADC_FCRAMP1_FCREF_B_WIDTH    13u
#define HSADC_FCRAMP1_FCREF_B(x)       (((uint32_t)(((uint32_t)(x))<<HSADC_FCRAMP1_FCREF_B_SHIFT))&HSADC_FCRAMP1_FCREF_B_MASK)
#define HSADC_FCRAMP1_RPDIR_MASK       0x1u
#define HSADC_FCRAMP1_RPDIR_SHIFT      0u
#define HSADC_FCRAMP1_RPDIR_WIDTH      1u
#define HSADC_FCRAMP1_RPDIR(x)         (((uint32_t)(((uint32_t)(x))<<HSADC_FCRAMP1_RPDIR_SHIFT))&HSADC_FCRAMP1_RPDIR_MASK)
/* FCRAMP1 Reg Mask */
#define HSADC_FCRAMP1_MASK             0x1FFF0001u

/* FCHYST Bit Fields */
#define HSADC_FCHYST_DELTAP_MASK       0xFFF0000u
#define HSADC_FCHYST_DELTAP_SHIFT      16u
#define HSADC_FCHYST_DELTAP_WIDTH      12u
#define HSADC_FCHYST_DELTAP(x)         (((uint32_t)(((uint32_t)(x))<<HSADC_FCHYST_DELTAP_SHIFT))&HSADC_FCHYST_DELTAP_MASK)
#define HSADC_FCHYST_DELTAN_MASK       0xFFFu
#define HSADC_FCHYST_DELTAN_SHIFT      0u
#define HSADC_FCHYST_DELTAN_WIDTH      12u
#define HSADC_FCHYST_DELTAN(x)         (((uint32_t)(((uint32_t)(x))<<HSADC_FCHYST_DELTAN_SHIFT))&HSADC_FCHYST_DELTAN_MASK)
/* FCHYST Reg Mask */
#define HSADC_FCHYST_MASK              0x0FFF0FFFu

/* FCBFR Bit Fields */
#define HSADC_FCBFR_BFL_MASK           0x80000000u
#define HSADC_FCBFR_BFL_SHIFT          31u
#define HSADC_FCBFR_BFL_WIDTH          1u
#define HSADC_FCBFR_BFL(x)             (((uint32_t)(((uint32_t)(x))<<HSADC_FCBFR_BFL_SHIFT))&HSADC_FCBFR_BFL_MASK)
#define HSADC_FCBFR_FCR_MASK           0x40000000u
#define HSADC_FCBFR_FCR_SHIFT          30u
#define HSADC_FCBFR_FCR_WIDTH          1u
#define HSADC_FCBFR_FCR(x)             (((uint32_t)(((uint32_t)(x))<<HSADC_FCBFR_FCR_SHIFT))&HSADC_FCBFR_FCR_MASK)
#define HSADC_FCBFR_BFI_MASK           0x80u
#define HSADC_FCBFR_BFI_SHIFT          7u
#define HSADC_FCBFR_BFI_WIDTH          1u
#define HSADC_FCBFR_BFI(x)             (((uint32_t)(((uint32_t)(x))<<HSADC_FCBFR_BFI_SHIFT))&HSADC_FCBFR_BFI_MASK)
#define HSADC_FCBFR_BFVG_POL_MASK      0x40u
#define HSADC_FCBFR_BFVG_POL_SHIFT     6u
#define HSADC_FCBFR_BFVG_POL_WIDTH     1u
#define HSADC_FCBFR_BFVG_POL(x)        (((uint32_t)(((uint32_t)(x))<<HSADC_FCBFR_BFVG_POL_SHIFT))&HSADC_FCBFR_BFVG_POL_MASK)
#define HSADC_FCBFR_BFV_MASK           0x20u
#define HSADC_FCBFR_BFV_SHIFT          5u
#define HSADC_FCBFR_BFV_WIDTH          1u
#define HSADC_FCBFR_BFV(x)             (((uint32_t)(((uint32_t)(x))<<HSADC_FCBFR_BFV_SHIFT))&HSADC_FCBFR_BFV_MASK)
#define HSADC_FCBFR_BFS_MASK           0x18u
#define HSADC_FCBFR_BFS_SHIFT          3u
#define HSADC_FCBFR_BFS_WIDTH          2u
#define HSADC_FCBFR_BFS(x)             (((uint32_t)(((uint32_t)(x))<<HSADC_FCBFR_BFS_SHIFT))&HSADC_FCBFR_BFS_MASK)
#define HSADC_FCBFR_BFA_MASK           0x4u
#define HSADC_FCBFR_BFA_SHIFT          2u
#define HSADC_FCBFR_BFA_WIDTH          1u
#define HSADC_FCBFR_BFA(x)             (((uint32_t)(((uint32_t)(x))<<HSADC_FCBFR_BFA_SHIFT))&HSADC_FCBFR_BFA_MASK)
#define HSADC_FCBFR_BFM_MASK           0x2u
#define HSADC_FCBFR_BFM_SHIFT          1u
#define HSADC_FCBFR_BFM_WIDTH          1u
#define HSADC_FCBFR_BFM(x)             (((uint32_t)(((uint32_t)(x))<<HSADC_FCBFR_BFM_SHIFT))&HSADC_FCBFR_BFM_MASK)
#define HSADC_FCBFR_FCR_INIT_MASK      0x1u
#define HSADC_FCBFR_FCR_INIT_SHIFT     0u
#define HSADC_FCBFR_FCR_INIT_WIDTH     1u
#define HSADC_FCBFR_FCR_INIT(x)        (((uint32_t)(((uint32_t)(x))<<HSADC_FCBFR_FCR_INIT_SHIFT))&HSADC_FCBFR_FCR_INIT_MASK)
/* FCBFR Reg Mask */
#define HSADC_FCBFR_MASK               0xC00000FFu


/*!
 * @}
 */ /* end of group HSADC_Register_Masks */

/*!
 * @}
 */ /* end of group HSADC_Peripheral_Access_Layer */

#endif
