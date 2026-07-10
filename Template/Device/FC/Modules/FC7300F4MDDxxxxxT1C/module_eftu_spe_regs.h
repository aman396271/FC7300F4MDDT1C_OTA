#ifndef _MODULE_EFTU_SPE_gmbhdijq12_REGS_H_EFTU_SPE_H_
#define _MODULE_EFTU_SPE_gmbhdijq12_REGS_H_EFTU_SPE_H_

/* ----------------------------------------------------------------------------
   -- EFTU_SPE Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup EFTU_SPE_Peripheral_Access_Layer EFTU_SPE Peripheral Access Layer
 * @{
 */

/** EFTU_SPE - Size of Registers Arrays */

/** EFTU_SPE - Register Layout Typedef */
#define EFTU_SPE_PWM_OUT_PAT_COUNT 8

typedef struct {

  __IO uint32_t CTRL                          ; /* Control Register, offset: 0x00 */
  __IO uint32_t HALL_IN_PAT                   ; /* HALL Input Pattern Register, offset: 0x04 */
  __IO uint32_t PWM_OUT_CTRL                  ; /* PWM Output Control Register, offset: 0x08 */
  __IO uint32_t IRQ_EN                        ; /* Interrupt Enable Register, offset: 0x0C */
  __IO uint32_t IRQ_ST                        ; /* Interrupt Status Register, offset: 0x10 */
  __IO uint32_t REV_CNT                       ; /* Revolution Counter Register, offset: 0x14 */
  __IO uint32_t REV_CMP                       ; /* Revolution Counter Register, offset: 0x18 */
  __IO uint32_t CTRL2                         ; /* Control Register 2, offset: 0x1C */
  __IO uint32_t PWM_OUT_PAT[EFTU_SPE_PWM_OUT_PAT_COUNT]; /* PWM Output Pattern Register, offset: 0x20 */
  __IO uint32_t CMD                           ; /* Command Register, offset: 0x40 */

} EFTU_SPE_Type, *EFTU_SPE_MemMapPtr;


/* EFTU_SPE - Peripheral instance base addresses */
/** Peripheral EFTU_SPE0 base address */
#define EFTU_SPE0_BASE                           (0xE00u)
/** Peripheral EFTU_SPE0 base pointer */
#define EFTU_SPE0                                ((EFTU_SPE_Type *)EFTU_SPE0_BASE)
/** Peripheral EFTU_SPE1 base address */
#define EFTU_SPE1_BASE                           (0xE80u)
/** Peripheral EFTU_SPE1 base pointer */
#define EFTU_SPE1                                ((EFTU_SPE_Type *)EFTU_SPE1_BASE)
// need fill by yourself
///** Number of interrupt vector arrays for the EFTU_SPE module. */
//#define EFTU_SPE_IRQS_ARR_COUNT                       (1u)
///** Number of interrupt channels for the EFTU_SPE module. */
//#define EFTU_SPE_IRQS_CH_COUNT                        (1u)
///** Interrupt vectors for the EFTU_SPE peripheral type */
//#define EFTU_SPE_IRQS                            {EFTU_SPE0_IRQn, EFTU_SPE1_IRQn}


/* ----------------------------------------------------------------------------
   -- EFTU_SPE Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup EFTU_SPE_Register_Masks EFTU_SPE Register Masks
 * @{
 */

/* CTRL Bit Fields */
#define EFTU_SPE_CTRL_EN_MASK          0x1u
#define EFTU_SPE_CTRL_EN_SHIFT         0u
#define EFTU_SPE_CTRL_EN_WIDTH         1u
#define EFTU_SPE_CTRL_EN(x)            (((uint32_t)(((uint32_t)(x))<<EFTU_SPE_CTRL_EN_SHIFT))&EFTU_SPE_CTRL_EN_MASK)
#define EFTU_SPE_CTRL_SIE_MASK         0xEu
#define EFTU_SPE_CTRL_SIE_SHIFT        1u
#define EFTU_SPE_CTRL_SIE_WIDTH        3u
#define EFTU_SPE_CTRL_SIE(x)           (((uint32_t)(((uint32_t)(x))<<EFTU_SPE_CTRL_SIE_SHIFT))&EFTU_SPE_CTRL_SIE_MASK)
#define EFTU_SPE_CTRL_TRG_SEL_MASK     0x30u
#define EFTU_SPE_CTRL_TRG_SEL_SHIFT    4u
#define EFTU_SPE_CTRL_TRG_SEL_WIDTH    2u
#define EFTU_SPE_CTRL_TRG_SEL(x)       (((uint32_t)(((uint32_t)(x))<<EFTU_SPE_CTRL_TRG_SEL_SHIFT))&EFTU_SPE_CTRL_TRG_SEL_MASK)
#define EFTU_SPE_CTRL_TRG_ESEL_MASK    0xC0u
#define EFTU_SPE_CTRL_TRG_ESEL_SHIFT   6u
#define EFTU_SPE_CTRL_TRG_ESEL_WIDTH   2u
#define EFTU_SPE_CTRL_TRG_ESEL(x)      (((uint32_t)(((uint32_t)(x))<<EFTU_SPE_CTRL_TRG_ESEL_SHIFT))&EFTU_SPE_CTRL_TRG_ESEL_MASK)
#define EFTU_SPE_CTRL_PAT_PTR_MASK     0x700u
#define EFTU_SPE_CTRL_PAT_PTR_SHIFT    8u
#define EFTU_SPE_CTRL_PAT_PTR_WIDTH    3u
#define EFTU_SPE_CTRL_PAT_PTR(x)       (((uint32_t)(((uint32_t)(x))<<EFTU_SPE_CTRL_PAT_PTR_SHIFT))&EFTU_SPE_CTRL_PAT_PTR_MASK)
#define EFTU_SPE_CTRL_FSOM_MASK        0x800u
#define EFTU_SPE_CTRL_FSOM_SHIFT       11u
#define EFTU_SPE_CTRL_FSOM_WIDTH       1u
#define EFTU_SPE_CTRL_FSOM(x)          (((uint32_t)(((uint32_t)(x))<<EFTU_SPE_CTRL_FSOM_SHIFT))&EFTU_SPE_CTRL_FSOM_MASK)
#define EFTU_SPE_CTRL_AIP_MASK         0x7000u
#define EFTU_SPE_CTRL_AIP_SHIFT        12u
#define EFTU_SPE_CTRL_AIP_WIDTH        3u
#define EFTU_SPE_CTRL_AIP(x)           (((uint32_t)(((uint32_t)(x))<<EFTU_SPE_CTRL_AIP_SHIFT))&EFTU_SPE_CTRL_AIP_MASK)
#define EFTU_SPE_CTRL_ADIR_MASK        0x8000u
#define EFTU_SPE_CTRL_ADIR_SHIFT       15u
#define EFTU_SPE_CTRL_ADIR_WIDTH       1u
#define EFTU_SPE_CTRL_ADIR(x)          (((uint32_t)(((uint32_t)(x))<<EFTU_SPE_CTRL_ADIR_SHIFT))&EFTU_SPE_CTRL_ADIR_MASK)
#define EFTU_SPE_CTRL_PIP_MASK         0x70000u
#define EFTU_SPE_CTRL_PIP_SHIFT        16u
#define EFTU_SPE_CTRL_PIP_WIDTH        3u
#define EFTU_SPE_CTRL_PIP(x)           (((uint32_t)(((uint32_t)(x))<<EFTU_SPE_CTRL_PIP_SHIFT))&EFTU_SPE_CTRL_PIP_MASK)
#define EFTU_SPE_CTRL_PDIR_MASK        0x80000u
#define EFTU_SPE_CTRL_PDIR_SHIFT       19u
#define EFTU_SPE_CTRL_PDIR_WIDTH       1u
#define EFTU_SPE_CTRL_PDIR(x)          (((uint32_t)(((uint32_t)(x))<<EFTU_SPE_CTRL_PDIR_SHIFT))&EFTU_SPE_CTRL_PDIR_MASK)
#define EFTU_SPE_CTRL_NIP_MASK         0x700000u
#define EFTU_SPE_CTRL_NIP_SHIFT        20u
#define EFTU_SPE_CTRL_NIP_WIDTH        3u
#define EFTU_SPE_CTRL_NIP(x)           (((uint32_t)(((uint32_t)(x))<<EFTU_SPE_CTRL_NIP_SHIFT))&EFTU_SPE_CTRL_NIP_MASK)
#define EFTU_SPE_CTRL_FSOL_MASK        0x3F000000u
#define EFTU_SPE_CTRL_FSOL_SHIFT       24u
#define EFTU_SPE_CTRL_FSOL_WIDTH       6u
#define EFTU_SPE_CTRL_FSOL(x)          (((uint32_t)(((uint32_t)(x))<<EFTU_SPE_CTRL_FSOL_SHIFT))&EFTU_SPE_CTRL_FSOL_MASK)
#define EFTU_SPE_CTRL_REF_SEL_MASK     0xC0000000u
#define EFTU_SPE_CTRL_REF_SEL_SHIFT    30u
#define EFTU_SPE_CTRL_REF_SEL_WIDTH    2u
#define EFTU_SPE_CTRL_REF_SEL(x)       (((uint32_t)(((uint32_t)(x))<<EFTU_SPE_CTRL_REF_SEL_SHIFT))&EFTU_SPE_CTRL_REF_SEL_MASK)
/* CTRL Reg Mask */
#define EFTU_SPE_CTRL_MASK             0xFF7FFFFFu

/* HALL_IN_PAT Bit Fields */
#define EFTU_SPE_HALL_IN_PAT_PAT0_VAL_MASK 0x1u
#define EFTU_SPE_HALL_IN_PAT_PAT0_VAL_SHIFT 0u
#define EFTU_SPE_HALL_IN_PAT_PAT0_VAL_WIDTH 1u
#define EFTU_SPE_HALL_IN_PAT_PAT0_VAL(x) (((uint32_t)(((uint32_t)(x))<<EFTU_SPE_HALL_IN_PAT_PAT0_VAL_SHIFT))&EFTU_SPE_HALL_IN_PAT_PAT0_VAL_MASK)
#define EFTU_SPE_HALL_IN_PAT_PAT0_MASK 0xEu
#define EFTU_SPE_HALL_IN_PAT_PAT0_SHIFT 1u
#define EFTU_SPE_HALL_IN_PAT_PAT0_WIDTH 3u
#define EFTU_SPE_HALL_IN_PAT_PAT0(x)   (((uint32_t)(((uint32_t)(x))<<EFTU_SPE_HALL_IN_PAT_PAT0_SHIFT))&EFTU_SPE_HALL_IN_PAT_PAT0_MASK)
#define EFTU_SPE_HALL_IN_PAT_PAT1_VAL_MASK 0x10u
#define EFTU_SPE_HALL_IN_PAT_PAT1_VAL_SHIFT 4u
#define EFTU_SPE_HALL_IN_PAT_PAT1_VAL_WIDTH 1u
#define EFTU_SPE_HALL_IN_PAT_PAT1_VAL(x) (((uint32_t)(((uint32_t)(x))<<EFTU_SPE_HALL_IN_PAT_PAT1_VAL_SHIFT))&EFTU_SPE_HALL_IN_PAT_PAT1_VAL_MASK)
#define EFTU_SPE_HALL_IN_PAT_PAT1_MASK 0xE0u
#define EFTU_SPE_HALL_IN_PAT_PAT1_SHIFT 5u
#define EFTU_SPE_HALL_IN_PAT_PAT1_WIDTH 3u
#define EFTU_SPE_HALL_IN_PAT_PAT1(x)   (((uint32_t)(((uint32_t)(x))<<EFTU_SPE_HALL_IN_PAT_PAT1_SHIFT))&EFTU_SPE_HALL_IN_PAT_PAT1_MASK)
#define EFTU_SPE_HALL_IN_PAT_PAT2_VAL_MASK 0x100u
#define EFTU_SPE_HALL_IN_PAT_PAT2_VAL_SHIFT 8u
#define EFTU_SPE_HALL_IN_PAT_PAT2_VAL_WIDTH 1u
#define EFTU_SPE_HALL_IN_PAT_PAT2_VAL(x) (((uint32_t)(((uint32_t)(x))<<EFTU_SPE_HALL_IN_PAT_PAT2_VAL_SHIFT))&EFTU_SPE_HALL_IN_PAT_PAT2_VAL_MASK)
#define EFTU_SPE_HALL_IN_PAT_PAT2_MASK 0xE00u
#define EFTU_SPE_HALL_IN_PAT_PAT2_SHIFT 9u
#define EFTU_SPE_HALL_IN_PAT_PAT2_WIDTH 3u
#define EFTU_SPE_HALL_IN_PAT_PAT2(x)   (((uint32_t)(((uint32_t)(x))<<EFTU_SPE_HALL_IN_PAT_PAT2_SHIFT))&EFTU_SPE_HALL_IN_PAT_PAT2_MASK)
#define EFTU_SPE_HALL_IN_PAT_PAT3_VAL_MASK 0x1000u
#define EFTU_SPE_HALL_IN_PAT_PAT3_VAL_SHIFT 12u
#define EFTU_SPE_HALL_IN_PAT_PAT3_VAL_WIDTH 1u
#define EFTU_SPE_HALL_IN_PAT_PAT3_VAL(x) (((uint32_t)(((uint32_t)(x))<<EFTU_SPE_HALL_IN_PAT_PAT3_VAL_SHIFT))&EFTU_SPE_HALL_IN_PAT_PAT3_VAL_MASK)
#define EFTU_SPE_HALL_IN_PAT_PAT3_MASK 0xE000u
#define EFTU_SPE_HALL_IN_PAT_PAT3_SHIFT 13u
#define EFTU_SPE_HALL_IN_PAT_PAT3_WIDTH 3u
#define EFTU_SPE_HALL_IN_PAT_PAT3(x)   (((uint32_t)(((uint32_t)(x))<<EFTU_SPE_HALL_IN_PAT_PAT3_SHIFT))&EFTU_SPE_HALL_IN_PAT_PAT3_MASK)
#define EFTU_SPE_HALL_IN_PAT_PAT4_VAL_MASK 0x10000u
#define EFTU_SPE_HALL_IN_PAT_PAT4_VAL_SHIFT 16u
#define EFTU_SPE_HALL_IN_PAT_PAT4_VAL_WIDTH 1u
#define EFTU_SPE_HALL_IN_PAT_PAT4_VAL(x) (((uint32_t)(((uint32_t)(x))<<EFTU_SPE_HALL_IN_PAT_PAT4_VAL_SHIFT))&EFTU_SPE_HALL_IN_PAT_PAT4_VAL_MASK)
#define EFTU_SPE_HALL_IN_PAT_PAT4_MASK 0xE0000u
#define EFTU_SPE_HALL_IN_PAT_PAT4_SHIFT 17u
#define EFTU_SPE_HALL_IN_PAT_PAT4_WIDTH 3u
#define EFTU_SPE_HALL_IN_PAT_PAT4(x)   (((uint32_t)(((uint32_t)(x))<<EFTU_SPE_HALL_IN_PAT_PAT4_SHIFT))&EFTU_SPE_HALL_IN_PAT_PAT4_MASK)
#define EFTU_SPE_HALL_IN_PAT_PAT5_VAL_MASK 0x100000u
#define EFTU_SPE_HALL_IN_PAT_PAT5_VAL_SHIFT 20u
#define EFTU_SPE_HALL_IN_PAT_PAT5_VAL_WIDTH 1u
#define EFTU_SPE_HALL_IN_PAT_PAT5_VAL(x) (((uint32_t)(((uint32_t)(x))<<EFTU_SPE_HALL_IN_PAT_PAT5_VAL_SHIFT))&EFTU_SPE_HALL_IN_PAT_PAT5_VAL_MASK)
#define EFTU_SPE_HALL_IN_PAT_PAT5_MASK 0xE00000u
#define EFTU_SPE_HALL_IN_PAT_PAT5_SHIFT 21u
#define EFTU_SPE_HALL_IN_PAT_PAT5_WIDTH 3u
#define EFTU_SPE_HALL_IN_PAT_PAT5(x)   (((uint32_t)(((uint32_t)(x))<<EFTU_SPE_HALL_IN_PAT_PAT5_SHIFT))&EFTU_SPE_HALL_IN_PAT_PAT5_MASK)
#define EFTU_SPE_HALL_IN_PAT_PAT6_VAL_MASK 0x1000000u
#define EFTU_SPE_HALL_IN_PAT_PAT6_VAL_SHIFT 24u
#define EFTU_SPE_HALL_IN_PAT_PAT6_VAL_WIDTH 1u
#define EFTU_SPE_HALL_IN_PAT_PAT6_VAL(x) (((uint32_t)(((uint32_t)(x))<<EFTU_SPE_HALL_IN_PAT_PAT6_VAL_SHIFT))&EFTU_SPE_HALL_IN_PAT_PAT6_VAL_MASK)
#define EFTU_SPE_HALL_IN_PAT_PAT6_MASK 0xE000000u
#define EFTU_SPE_HALL_IN_PAT_PAT6_SHIFT 25u
#define EFTU_SPE_HALL_IN_PAT_PAT6_WIDTH 3u
#define EFTU_SPE_HALL_IN_PAT_PAT6(x)   (((uint32_t)(((uint32_t)(x))<<EFTU_SPE_HALL_IN_PAT_PAT6_SHIFT))&EFTU_SPE_HALL_IN_PAT_PAT6_MASK)
#define EFTU_SPE_HALL_IN_PAT_PAT7_VAL_MASK 0x10000000u
#define EFTU_SPE_HALL_IN_PAT_PAT7_VAL_SHIFT 28u
#define EFTU_SPE_HALL_IN_PAT_PAT7_VAL_WIDTH 1u
#define EFTU_SPE_HALL_IN_PAT_PAT7_VAL(x) (((uint32_t)(((uint32_t)(x))<<EFTU_SPE_HALL_IN_PAT_PAT7_VAL_SHIFT))&EFTU_SPE_HALL_IN_PAT_PAT7_VAL_MASK)
#define EFTU_SPE_HALL_IN_PAT_PAT7_MASK 0xE0000000u
#define EFTU_SPE_HALL_IN_PAT_PAT7_SHIFT 29u
#define EFTU_SPE_HALL_IN_PAT_PAT7_WIDTH 3u
#define EFTU_SPE_HALL_IN_PAT_PAT7(x)   (((uint32_t)(((uint32_t)(x))<<EFTU_SPE_HALL_IN_PAT_PAT7_SHIFT))&EFTU_SPE_HALL_IN_PAT_PAT7_MASK)
/* HALL_IN_PAT Reg Mask */
#define EFTU_SPE_HALL_IN_PAT_MASK      0xFFFFFFFFu

/* PWM_OUT_CTRL Bit Fields */
#define EFTU_SPE_PWM_OUT_CTRL_PWM0_MASK 0x3u
#define EFTU_SPE_PWM_OUT_CTRL_PWM0_SHIFT 0u
#define EFTU_SPE_PWM_OUT_CTRL_PWM0_WIDTH 2u
#define EFTU_SPE_PWM_OUT_CTRL_PWM0(x)  (((uint32_t)(((uint32_t)(x))<<EFTU_SPE_PWM_OUT_CTRL_PWM0_SHIFT))&EFTU_SPE_PWM_OUT_CTRL_PWM0_MASK)
#define EFTU_SPE_PWM_OUT_CTRL_PWM1_MASK 0xCu
#define EFTU_SPE_PWM_OUT_CTRL_PWM1_SHIFT 2u
#define EFTU_SPE_PWM_OUT_CTRL_PWM1_WIDTH 2u
#define EFTU_SPE_PWM_OUT_CTRL_PWM1(x)  (((uint32_t)(((uint32_t)(x))<<EFTU_SPE_PWM_OUT_CTRL_PWM1_SHIFT))&EFTU_SPE_PWM_OUT_CTRL_PWM1_MASK)
#define EFTU_SPE_PWM_OUT_CTRL_PWM2_MASK 0x30u
#define EFTU_SPE_PWM_OUT_CTRL_PWM2_SHIFT 4u
#define EFTU_SPE_PWM_OUT_CTRL_PWM2_WIDTH 2u
#define EFTU_SPE_PWM_OUT_CTRL_PWM2(x)  (((uint32_t)(((uint32_t)(x))<<EFTU_SPE_PWM_OUT_CTRL_PWM2_SHIFT))&EFTU_SPE_PWM_OUT_CTRL_PWM2_MASK)
#define EFTU_SPE_PWM_OUT_CTRL_PWM3_MASK 0xC0u
#define EFTU_SPE_PWM_OUT_CTRL_PWM3_SHIFT 6u
#define EFTU_SPE_PWM_OUT_CTRL_PWM3_WIDTH 2u
#define EFTU_SPE_PWM_OUT_CTRL_PWM3(x)  (((uint32_t)(((uint32_t)(x))<<EFTU_SPE_PWM_OUT_CTRL_PWM3_SHIFT))&EFTU_SPE_PWM_OUT_CTRL_PWM3_MASK)
#define EFTU_SPE_PWM_OUT_CTRL_PWM4_MASK 0x300u
#define EFTU_SPE_PWM_OUT_CTRL_PWM4_SHIFT 8u
#define EFTU_SPE_PWM_OUT_CTRL_PWM4_WIDTH 2u
#define EFTU_SPE_PWM_OUT_CTRL_PWM4(x)  (((uint32_t)(((uint32_t)(x))<<EFTU_SPE_PWM_OUT_CTRL_PWM4_SHIFT))&EFTU_SPE_PWM_OUT_CTRL_PWM4_MASK)
#define EFTU_SPE_PWM_OUT_CTRL_PWM5_MASK 0xC00u
#define EFTU_SPE_PWM_OUT_CTRL_PWM5_SHIFT 10u
#define EFTU_SPE_PWM_OUT_CTRL_PWM5_WIDTH 2u
#define EFTU_SPE_PWM_OUT_CTRL_PWM5(x)  (((uint32_t)(((uint32_t)(x))<<EFTU_SPE_PWM_OUT_CTRL_PWM5_SHIFT))&EFTU_SPE_PWM_OUT_CTRL_PWM5_MASK)
/* PWM_OUT_CTRL Reg Mask */
#define EFTU_SPE_PWM_OUT_CTRL_MASK     0x00000FFFu

/* IRQ_EN Bit Fields */
#define EFTU_SPE_IRQ_EN_NIPD_EN_MASK   0x1u
#define EFTU_SPE_IRQ_EN_NIPD_EN_SHIFT  0u
#define EFTU_SPE_IRQ_EN_NIPD_EN_WIDTH  1u
#define EFTU_SPE_IRQ_EN_NIPD_EN(x)     (((uint32_t)(((uint32_t)(x))<<EFTU_SPE_IRQ_EN_NIPD_EN_SHIFT))&EFTU_SPE_IRQ_EN_NIPD_EN_MASK)
#define EFTU_SPE_IRQ_EN_DCHG_EN_MASK   0x2u
#define EFTU_SPE_IRQ_EN_DCHG_EN_SHIFT  1u
#define EFTU_SPE_IRQ_EN_DCHG_EN_WIDTH  1u
#define EFTU_SPE_IRQ_EN_DCHG_EN(x)     (((uint32_t)(((uint32_t)(x))<<EFTU_SPE_IRQ_EN_DCHG_EN_SHIFT))&EFTU_SPE_IRQ_EN_DCHG_EN_MASK)
#define EFTU_SPE_IRQ_EN_EIPD_EN_MASK   0x4u
#define EFTU_SPE_IRQ_EN_EIPD_EN_SHIFT  2u
#define EFTU_SPE_IRQ_EN_EIPD_EN_WIDTH  1u
#define EFTU_SPE_IRQ_EN_EIPD_EN(x)     (((uint32_t)(((uint32_t)(x))<<EFTU_SPE_IRQ_EN_EIPD_EN_SHIFT))&EFTU_SPE_IRQ_EN_EIPD_EN_MASK)
#define EFTU_SPE_IRQ_EN_BIE_EN_MASK    0x8u
#define EFTU_SPE_IRQ_EN_BIE_EN_SHIFT   3u
#define EFTU_SPE_IRQ_EN_BIE_EN_WIDTH   1u
#define EFTU_SPE_IRQ_EN_BIE_EN(x)      (((uint32_t)(((uint32_t)(x))<<EFTU_SPE_IRQ_EN_BIE_EN_SHIFT))&EFTU_SPE_IRQ_EN_BIE_EN_MASK)
#define EFTU_SPE_IRQ_EN_RCMP_EN_MASK   0x10u
#define EFTU_SPE_IRQ_EN_RCMP_EN_SHIFT  4u
#define EFTU_SPE_IRQ_EN_RCMP_EN_WIDTH  1u
#define EFTU_SPE_IRQ_EN_RCMP_EN(x)     (((uint32_t)(((uint32_t)(x))<<EFTU_SPE_IRQ_EN_RCMP_EN_SHIFT))&EFTU_SPE_IRQ_EN_RCMP_EN_MASK)
/* IRQ_EN Reg Mask */
#define EFTU_SPE_IRQ_EN_MASK           0x0000001Fu

/* IRQ_ST Bit Fields */
#define EFTU_SPE_IRQ_ST_NIPD_ST_MASK   0x1u
#define EFTU_SPE_IRQ_ST_NIPD_ST_SHIFT  0u
#define EFTU_SPE_IRQ_ST_NIPD_ST_WIDTH  1u
#define EFTU_SPE_IRQ_ST_NIPD_ST(x)     (((uint32_t)(((uint32_t)(x))<<EFTU_SPE_IRQ_ST_NIPD_ST_SHIFT))&EFTU_SPE_IRQ_ST_NIPD_ST_MASK)
#define EFTU_SPE_IRQ_ST_DCHG_ST_MASK   0x2u
#define EFTU_SPE_IRQ_ST_DCHG_ST_SHIFT  1u
#define EFTU_SPE_IRQ_ST_DCHG_ST_WIDTH  1u
#define EFTU_SPE_IRQ_ST_DCHG_ST(x)     (((uint32_t)(((uint32_t)(x))<<EFTU_SPE_IRQ_ST_DCHG_ST_SHIFT))&EFTU_SPE_IRQ_ST_DCHG_ST_MASK)
#define EFTU_SPE_IRQ_ST_EIPD_ST_MASK   0x4u
#define EFTU_SPE_IRQ_ST_EIPD_ST_SHIFT  2u
#define EFTU_SPE_IRQ_ST_EIPD_ST_WIDTH  1u
#define EFTU_SPE_IRQ_ST_EIPD_ST(x)     (((uint32_t)(((uint32_t)(x))<<EFTU_SPE_IRQ_ST_EIPD_ST_SHIFT))&EFTU_SPE_IRQ_ST_EIPD_ST_MASK)
#define EFTU_SPE_IRQ_ST_BIE_ST_MASK    0x8u
#define EFTU_SPE_IRQ_ST_BIE_ST_SHIFT   3u
#define EFTU_SPE_IRQ_ST_BIE_ST_WIDTH   1u
#define EFTU_SPE_IRQ_ST_BIE_ST(x)      (((uint32_t)(((uint32_t)(x))<<EFTU_SPE_IRQ_ST_BIE_ST_SHIFT))&EFTU_SPE_IRQ_ST_BIE_ST_MASK)
#define EFTU_SPE_IRQ_ST_RCMP_ST_MASK   0x10u
#define EFTU_SPE_IRQ_ST_RCMP_ST_SHIFT  4u
#define EFTU_SPE_IRQ_ST_RCMP_ST_WIDTH  1u
#define EFTU_SPE_IRQ_ST_RCMP_ST(x)     (((uint32_t)(((uint32_t)(x))<<EFTU_SPE_IRQ_ST_RCMP_ST_SHIFT))&EFTU_SPE_IRQ_ST_RCMP_ST_MASK)
/* IRQ_ST Reg Mask */
#define EFTU_SPE_IRQ_ST_MASK           0x0000001Fu

/* REV_CNT Bit Fields */
#define EFTU_SPE_REV_CNT_REV_CNT_MASK  0xFFFFFFu
#define EFTU_SPE_REV_CNT_REV_CNT_SHIFT 0u
#define EFTU_SPE_REV_CNT_REV_CNT_WIDTH 24u
#define EFTU_SPE_REV_CNT_REV_CNT(x)    (((uint32_t)(((uint32_t)(x))<<EFTU_SPE_REV_CNT_REV_CNT_SHIFT))&EFTU_SPE_REV_CNT_REV_CNT_MASK)
/* REV_CNT Reg Mask */
#define EFTU_SPE_REV_CNT_MASK          0x00FFFFFFu

/* REV_CMP Bit Fields */
#define EFTU_SPE_REV_CMP_REV_CMP_MASK  0xFFFFFFu
#define EFTU_SPE_REV_CMP_REV_CMP_SHIFT 0u
#define EFTU_SPE_REV_CMP_REV_CMP_WIDTH 24u
#define EFTU_SPE_REV_CMP_REV_CMP(x)    (((uint32_t)(((uint32_t)(x))<<EFTU_SPE_REV_CMP_REV_CMP_SHIFT))&EFTU_SPE_REV_CMP_REV_CMP_MASK)
/* REV_CMP Reg Mask */
#define EFTU_SPE_REV_CMP_MASK          0x00FFFFFFu

/* CTRL2 Bit Fields */
#define EFTU_SPE_CTRL2_DTRG_VAL_MASK   0xFFu
#define EFTU_SPE_CTRL2_DTRG_VAL_SHIFT  0u
#define EFTU_SPE_CTRL2_DTRG_VAL_WIDTH  8u
#define EFTU_SPE_CTRL2_DTRG_VAL(x)     (((uint32_t)(((uint32_t)(x))<<EFTU_SPE_CTRL2_DTRG_VAL_SHIFT))&EFTU_SPE_CTRL2_DTRG_VAL_MASK)
#define EFTU_SPE_CTRL2_PTR_BWD_MASK    0x700u
#define EFTU_SPE_CTRL2_PTR_BWD_SHIFT   8u
#define EFTU_SPE_CTRL2_PTR_BWD_WIDTH   3u
#define EFTU_SPE_CTRL2_PTR_BWD(x)      (((uint32_t)(((uint32_t)(x))<<EFTU_SPE_CTRL2_PTR_BWD_SHIFT))&EFTU_SPE_CTRL2_PTR_BWD_MASK)
#define EFTU_SPE_CTRL2_DTRG_CLK_SEL_MASK 0x3800u
#define EFTU_SPE_CTRL2_DTRG_CLK_SEL_SHIFT 11u
#define EFTU_SPE_CTRL2_DTRG_CLK_SEL_WIDTH 3u
#define EFTU_SPE_CTRL2_DTRG_CLK_SEL(x) (((uint32_t)(((uint32_t)(x))<<EFTU_SPE_CTRL2_DTRG_CLK_SEL_SHIFT))&EFTU_SPE_CTRL2_DTRG_CLK_SEL_MASK)
#define EFTU_SPE_CTRL2_FSOI_SEL_MASK   0x1C000u
#define EFTU_SPE_CTRL2_FSOI_SEL_SHIFT  14u
#define EFTU_SPE_CTRL2_FSOI_SEL_WIDTH  3u
#define EFTU_SPE_CTRL2_FSOI_SEL(x)     (((uint32_t)(((uint32_t)(x))<<EFTU_SPE_CTRL2_FSOI_SEL_SHIFT))&EFTU_SPE_CTRL2_FSOI_SEL_MASK)
/* CTRL2 Reg Mask */
#define EFTU_SPE_CTRL2_MASK            0x0001FFFFu

/* PWM_OUT_PAT Bit Fields */
#define EFTU_SPE_PWM_OUT_PAT_PWM0_MASK 0x3u
#define EFTU_SPE_PWM_OUT_PAT_PWM0_SHIFT 0u
#define EFTU_SPE_PWM_OUT_PAT_PWM0_WIDTH 2u
#define EFTU_SPE_PWM_OUT_PAT_PWM0(x)   (((uint32_t)(((uint32_t)(x))<<EFTU_SPE_PWM_OUT_PAT_PWM0_SHIFT))&EFTU_SPE_PWM_OUT_PAT_PWM0_MASK)
#define EFTU_SPE_PWM_OUT_PAT_PWM1_MASK 0xCu
#define EFTU_SPE_PWM_OUT_PAT_PWM1_SHIFT 2u
#define EFTU_SPE_PWM_OUT_PAT_PWM1_WIDTH 2u
#define EFTU_SPE_PWM_OUT_PAT_PWM1(x)   (((uint32_t)(((uint32_t)(x))<<EFTU_SPE_PWM_OUT_PAT_PWM1_SHIFT))&EFTU_SPE_PWM_OUT_PAT_PWM1_MASK)
#define EFTU_SPE_PWM_OUT_PAT_PWM2_MASK 0x30u
#define EFTU_SPE_PWM_OUT_PAT_PWM2_SHIFT 4u
#define EFTU_SPE_PWM_OUT_PAT_PWM2_WIDTH 2u
#define EFTU_SPE_PWM_OUT_PAT_PWM2(x)   (((uint32_t)(((uint32_t)(x))<<EFTU_SPE_PWM_OUT_PAT_PWM2_SHIFT))&EFTU_SPE_PWM_OUT_PAT_PWM2_MASK)
#define EFTU_SPE_PWM_OUT_PAT_PWM3_MASK 0xC0u
#define EFTU_SPE_PWM_OUT_PAT_PWM3_SHIFT 6u
#define EFTU_SPE_PWM_OUT_PAT_PWM3_WIDTH 2u
#define EFTU_SPE_PWM_OUT_PAT_PWM3(x)   (((uint32_t)(((uint32_t)(x))<<EFTU_SPE_PWM_OUT_PAT_PWM3_SHIFT))&EFTU_SPE_PWM_OUT_PAT_PWM3_MASK)
#define EFTU_SPE_PWM_OUT_PAT_PWM4_MASK 0x300u
#define EFTU_SPE_PWM_OUT_PAT_PWM4_SHIFT 8u
#define EFTU_SPE_PWM_OUT_PAT_PWM4_WIDTH 2u
#define EFTU_SPE_PWM_OUT_PAT_PWM4(x)   (((uint32_t)(((uint32_t)(x))<<EFTU_SPE_PWM_OUT_PAT_PWM4_SHIFT))&EFTU_SPE_PWM_OUT_PAT_PWM4_MASK)
#define EFTU_SPE_PWM_OUT_PAT_PWM5_MASK 0xC00u
#define EFTU_SPE_PWM_OUT_PAT_PWM5_SHIFT 10u
#define EFTU_SPE_PWM_OUT_PAT_PWM5_WIDTH 2u
#define EFTU_SPE_PWM_OUT_PAT_PWM5(x)   (((uint32_t)(((uint32_t)(x))<<EFTU_SPE_PWM_OUT_PAT_PWM5_SHIFT))&EFTU_SPE_PWM_OUT_PAT_PWM5_MASK)
/* PWM_OUT_PAT0 Reg Mask */
#define EFTU_SPE_PWM_OUT_PAT_MASK      0x00000FFFu

/* CMD Bit Fields */
#define EFTU_SPE_CMD_CTRL_CMD_MASK     0x3u
#define EFTU_SPE_CMD_CTRL_CMD_SHIFT    0u
#define EFTU_SPE_CMD_CTRL_CMD_WIDTH    2u
#define EFTU_SPE_CMD_CTRL_CMD(x)       (((uint32_t)(((uint32_t)(x))<<EFTU_SPE_CMD_CTRL_CMD_SHIFT))&EFTU_SPE_CMD_CTRL_CMD_MASK)
#define EFTU_SPE_CMD_SW_UPD_TRG_MASK   0x10000u
#define EFTU_SPE_CMD_SW_UPD_TRG_SHIFT  16u
#define EFTU_SPE_CMD_SW_UPD_TRG_WIDTH  1u
#define EFTU_SPE_CMD_SW_UPD_TRG(x)     (((uint32_t)(((uint32_t)(x))<<EFTU_SPE_CMD_SW_UPD_TRG_SHIFT))&EFTU_SPE_CMD_SW_UPD_TRG_MASK)
/* CMD Reg Mask */
#define EFTU_SPE_CMD_MASK              0x00010003u


/*!
 * @}
 */ /* end of group EFTU_SPE_Register_Masks */

/*!
 * @}
 */ /* end of group EFTU_SPE_Peripheral_Access_Layer */

#endif
