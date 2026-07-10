#ifndef _MODULE_EFTU_TBU_gmbhdijq1_REGS_H_EFTU_TBU_H_
#define _MODULE_EFTU_TBU_gmbhdijq1_REGS_H_EFTU_TBU_H_

/* ----------------------------------------------------------------------------
   -- EFTU_TBU Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup EFTU_TBU_Peripheral_Access_Layer EFTU_TBU Peripheral Access Layer
 * @{
 */

/** EFTU_TBU - Size of Registers Arrays */

/** EFTU_TBU - Register Layout Typedef */

typedef struct {

  __IO uint32_t CNTEN                         ; /* TBU Global Counter Enable Register, offset: 0x00 */
  __IO uint32_t CNT0_CTRL                     ; /* TBU Counter 0 Control Register, offset: 0x04 */
  __IO uint32_t CNT0_BASE                     ; /* TBU Counter 0 Base Register, offset: 0x08 */
  __IO uint32_t CNT1_CTRL                     ; /* TBU Counter 1 Control Register, offset: 0x0C */
  __IO uint32_t CNT1_BASE                     ; /* TBU Counter 1 Base Register, offset: 0x10 */
  __IO uint32_t CNT2_CTRL                     ; /* TBU Counter 2 Control Register, offset: 0x14 */
  __IO uint32_t CNT2_BASE                     ; /* TBU Counter 2 Base Register, offset: 0x18 */
  __IO uint32_t CNT3_CTRL                     ; /* TBU Counter 3 Control Register, offset: 0x1C */
  __IO uint32_t CNT3_BASE                     ; /* TBU Counter 3 Base Register, offset: 0x20 */
  __IO uint32_t CNT3_MARK                     ; /* TBU Counter 3 Modulo Value Register, offset: 0x24 */
  __IO uint32_t CNT3_CAPTURE                  ; /* TBU Counter 3 Base Captured Register, offset: 0x28 */
       uint8_t  RESERVED_0[84];
  __IO uint32_t EAC_TPR                       ; /* Time Base Region - Tooth Program Register, offset: 0x80 */
  __IO uint32_t EAC_TRR                       ; /* Time Base Region - Tick Rate Register, offset: 0x84 */
  __IO uint32_t EAC_CNT                       ; /* Counter Register, offset: 0x88 */
  __IO uint32_t EAC_CNTS                      ; /* CNTS Register, offset: 0x8c */
  __IO uint32_t EAC_WINDOW_S                  ; /* Window Start Configuration Register, offset: 0x90 */
  __IO uint32_t EAC_WINDOW_E                  ; /* Window End Configuration Register, offset: 0x94 */
  __IO uint32_t EAC_CTRL                      ; /* Control Register, offset: 0x98 */
  __IO uint32_t EAC_STAT                      ; /* Status Reigister, offset: 0x9c */
  __IO uint32_t EAC_IRQEN                     ; /* Interrupt Enable register, offset: 0xa0 */

} EFTU_TBU_Type, *EFTU_TBU_MemMapPtr;


/* EFTU_TBU - Peripheral instance base addresses */
/** Peripheral EFTU_TBU base address */
#define EFTU_TBU_BASE                            (0x500u)
/** Peripheral EFTU_TBU base pointer */
#define EFTU_TBU                                 ((EFTU_TBU_Type *)EFTU_TBU_BASE)
// need fill by yourself
///** Number of interrupt vector arrays for the EFTU_TBU module. */
//#define EFTU_TBU_IRQS_ARR_COUNT                       (1u)
///** Number of interrupt channels for the EFTU_TBU module. */
//#define EFTU_TBU_IRQS_CH_COUNT                        (1u)
///** Interrupt vectors for the EFTU_TBU peripheral type */
//#define EFTU_TBU_IRQS                            {EFTU_TBU_IRQn}


/* ----------------------------------------------------------------------------
   -- EFTU_TBU Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup EFTU_TBU_Register_Masks EFTU_TBU Register Masks
 * @{
 */

/* CNTEN Bit Fields */
#define EFTU_TBU_CNTEN_ENDIS_CNT0_MASK 0x3u
#define EFTU_TBU_CNTEN_ENDIS_CNT0_SHIFT 0u
#define EFTU_TBU_CNTEN_ENDIS_CNT0_WIDTH 2u
#define EFTU_TBU_CNTEN_ENDIS_CNT0(x)   (((uint32_t)(((uint32_t)(x))<<EFTU_TBU_CNTEN_ENDIS_CNT0_SHIFT))&EFTU_TBU_CNTEN_ENDIS_CNT0_MASK)
#define EFTU_TBU_CNTEN_ENDIS_CNT1_MASK 0xCu
#define EFTU_TBU_CNTEN_ENDIS_CNT1_SHIFT 2u
#define EFTU_TBU_CNTEN_ENDIS_CNT1_WIDTH 2u
#define EFTU_TBU_CNTEN_ENDIS_CNT1(x)   (((uint32_t)(((uint32_t)(x))<<EFTU_TBU_CNTEN_ENDIS_CNT1_SHIFT))&EFTU_TBU_CNTEN_ENDIS_CNT1_MASK)
#define EFTU_TBU_CNTEN_ENDIS_CNT2_MASK 0x30u
#define EFTU_TBU_CNTEN_ENDIS_CNT2_SHIFT 4u
#define EFTU_TBU_CNTEN_ENDIS_CNT2_WIDTH 2u
#define EFTU_TBU_CNTEN_ENDIS_CNT2(x)   (((uint32_t)(((uint32_t)(x))<<EFTU_TBU_CNTEN_ENDIS_CNT2_SHIFT))&EFTU_TBU_CNTEN_ENDIS_CNT2_MASK)
#define EFTU_TBU_CNTEN_ENDIS_CNT3_MASK 0xC0u
#define EFTU_TBU_CNTEN_ENDIS_CNT3_SHIFT 6u
#define EFTU_TBU_CNTEN_ENDIS_CNT3_WIDTH 2u
#define EFTU_TBU_CNTEN_ENDIS_CNT3(x)   (((uint32_t)(((uint32_t)(x))<<EFTU_TBU_CNTEN_ENDIS_CNT3_SHIFT))&EFTU_TBU_CNTEN_ENDIS_CNT3_MASK)
/* CNTEN Reg Mask */
#define EFTU_TBU_CNTEN_MASK            0x000000FFu

/* CNT0_CTRL Bit Fields */
#define EFTU_TBU_CNT0_CTRL_LOW_RES_MASK 0x1u
#define EFTU_TBU_CNT0_CTRL_LOW_RES_SHIFT 0u
#define EFTU_TBU_CNT0_CTRL_LOW_RES_WIDTH 1u
#define EFTU_TBU_CNT0_CTRL_LOW_RES(x)  (((uint32_t)(((uint32_t)(x))<<EFTU_TBU_CNT0_CTRL_LOW_RES_SHIFT))&EFTU_TBU_CNT0_CTRL_LOW_RES_MASK)
#define EFTU_TBU_CNT0_CTRL_CNT_CLK_SRC_MASK 0xEu
#define EFTU_TBU_CNT0_CTRL_CNT_CLK_SRC_SHIFT 1u
#define EFTU_TBU_CNT0_CTRL_CNT_CLK_SRC_WIDTH 3u
#define EFTU_TBU_CNT0_CTRL_CNT_CLK_SRC(x) (((uint32_t)(((uint32_t)(x))<<EFTU_TBU_CNT0_CTRL_CNT_CLK_SRC_SHIFT))&EFTU_TBU_CNT0_CTRL_CNT_CLK_SRC_MASK)
/* CNT0_CTRL Reg Mask */
#define EFTU_TBU_CNT0_CTRL_MASK        0x0000000Fu

/* CNT0_BASE Bit Fields */
#define EFTU_TBU_CNT0_BASE_BASE_MASK   0x7FFFFFFu
#define EFTU_TBU_CNT0_BASE_BASE_SHIFT  0u
#define EFTU_TBU_CNT0_BASE_BASE_WIDTH  27u
#define EFTU_TBU_CNT0_BASE_BASE(x)     (((uint32_t)(((uint32_t)(x))<<EFTU_TBU_CNT0_BASE_BASE_SHIFT))&EFTU_TBU_CNT0_BASE_BASE_MASK)
/* CNT0_BASE Reg Mask */
#define EFTU_TBU_CNT0_BASE_MASK        0x07FFFFFFu

/* CNT1_CTRL Bit Fields */
#define EFTU_TBU_CNT1_CTRL_CNT_CLK_SRC_MASK 0xEu
#define EFTU_TBU_CNT1_CTRL_CNT_CLK_SRC_SHIFT 1u
#define EFTU_TBU_CNT1_CTRL_CNT_CLK_SRC_WIDTH 3u
#define EFTU_TBU_CNT1_CTRL_CNT_CLK_SRC(x) (((uint32_t)(((uint32_t)(x))<<EFTU_TBU_CNT1_CTRL_CNT_CLK_SRC_SHIFT))&EFTU_TBU_CNT1_CTRL_CNT_CLK_SRC_MASK)
/* CNT1_CTRL Reg Mask */
#define EFTU_TBU_CNT1_CTRL_MASK        0x0000000Eu

/* CNT2_CTRL Bit Fields */
#define EFTU_TBU_CNT2_CTRL_CNT_CLK_SRC_MASK 0xEu
#define EFTU_TBU_CNT2_CTRL_CNT_CLK_SRC_SHIFT 1u
#define EFTU_TBU_CNT2_CTRL_CNT_CLK_SRC_WIDTH 3u
#define EFTU_TBU_CNT2_CTRL_CNT_CLK_SRC(x) (((uint32_t)(((uint32_t)(x))<<EFTU_TBU_CNT2_CTRL_CNT_CLK_SRC_SHIFT))&EFTU_TBU_CNT2_CTRL_CNT_CLK_SRC_MASK)
/* CNT2_CTRL Reg Mask */
#define EFTU_TBU_CNT2_CTRL_MASK        0x0000000Eu

/* CNT1_BASE Bit Fields */
#define EFTU_TBU_CNT1_BASE_BASE_MASK   0xFFFFFFu
#define EFTU_TBU_CNT1_BASE_BASE_SHIFT  0u
#define EFTU_TBU_CNT1_BASE_BASE_WIDTH  24u
#define EFTU_TBU_CNT1_BASE_BASE(x)     (((uint32_t)(((uint32_t)(x))<<EFTU_TBU_CNT1_BASE_BASE_SHIFT))&EFTU_TBU_CNT1_BASE_BASE_MASK)
/* CNT1_BASE Reg Mask */
#define EFTU_TBU_CNT1_BASE_MASK        0x00FFFFFFu

/* CNT2_BASE Bit Fields */
#define EFTU_TBU_CNT2_BASE_BASE_MASK   0xFFFFFFu
#define EFTU_TBU_CNT2_BASE_BASE_SHIFT  0u
#define EFTU_TBU_CNT2_BASE_BASE_WIDTH  24u
#define EFTU_TBU_CNT2_BASE_BASE(x)     (((uint32_t)(((uint32_t)(x))<<EFTU_TBU_CNT2_BASE_BASE_SHIFT))&EFTU_TBU_CNT2_BASE_BASE_MASK)
/* CNT2_BASE Reg Mask */
#define EFTU_TBU_CNT2_BASE_MASK        0x00FFFFFFu

/* CNT3_CTRL Bit Fields */
#define EFTU_TBU_CNT3_CTRL_CNT_MODE_MASK 0x1u
#define EFTU_TBU_CNT3_CTRL_CNT_MODE_SHIFT 0u
#define EFTU_TBU_CNT3_CTRL_CNT_MODE_WIDTH 1u
#define EFTU_TBU_CNT3_CTRL_CNT_MODE(x) (((uint32_t)(((uint32_t)(x))<<EFTU_TBU_CNT3_CTRL_CNT_MODE_SHIFT))&EFTU_TBU_CNT3_CTRL_CNT_MODE_MASK)
#define EFTU_TBU_CNT3_CTRL_CNT_EMODE_MASK 0x2u
#define EFTU_TBU_CNT3_CTRL_CNT_EMODE_SHIFT 1u
#define EFTU_TBU_CNT3_CTRL_CNT_EMODE_WIDTH 1u
#define EFTU_TBU_CNT3_CTRL_CNT_EMODE(x) (((uint32_t)(((uint32_t)(x))<<EFTU_TBU_CNT3_CTRL_CNT_EMODE_SHIFT))&EFTU_TBU_CNT3_CTRL_CNT_EMODE_MASK)
#define EFTU_TBU_CNT3_CTRL_USE_CNT2_MASK 0x10u
#define EFTU_TBU_CNT3_CTRL_USE_CNT2_SHIFT 4u
#define EFTU_TBU_CNT3_CTRL_USE_CNT2_WIDTH 1u
#define EFTU_TBU_CNT3_CTRL_USE_CNT2(x) (((uint32_t)(((uint32_t)(x))<<EFTU_TBU_CNT3_CTRL_USE_CNT2_SHIFT))&EFTU_TBU_CNT3_CTRL_USE_CNT2_MASK)
/* CNT3_CTRL Reg Mask */
#define EFTU_TBU_CNT3_CTRL_MASK        0x00000013u

/* CNT3_BASE Bit Fields */
#define EFTU_TBU_CNT3_BASE_BASE_MASK   0xFFFFFFu
#define EFTU_TBU_CNT3_BASE_BASE_SHIFT  0u
#define EFTU_TBU_CNT3_BASE_BASE_WIDTH  24u
#define EFTU_TBU_CNT3_BASE_BASE(x)     (((uint32_t)(((uint32_t)(x))<<EFTU_TBU_CNT3_BASE_BASE_SHIFT))&EFTU_TBU_CNT3_BASE_BASE_MASK)
#define EFTU_TBU_CNT3_BASE_CIP_MASK    0x7000000u
#define EFTU_TBU_CNT3_BASE_CIP_SHIFT   24u
#define EFTU_TBU_CNT3_BASE_CIP_WIDTH   3u
#define EFTU_TBU_CNT3_BASE_CIP(x)      (((uint32_t)(((uint32_t)(x))<<EFTU_TBU_CNT3_BASE_CIP_SHIFT))&EFTU_TBU_CNT3_BASE_CIP_MASK)
/* CNT3_BASE Reg Mask */
#define EFTU_TBU_CNT3_BASE_MASK        0x07FFFFFFu

/* CNT3_MARK Bit Fields */
#define EFTU_TBU_CNT3_MARK_MARK_MASK   0xFFFFFFu
#define EFTU_TBU_CNT3_MARK_MARK_SHIFT  0u
#define EFTU_TBU_CNT3_MARK_MARK_WIDTH  24u
#define EFTU_TBU_CNT3_MARK_MARK(x)     (((uint32_t)(((uint32_t)(x))<<EFTU_TBU_CNT3_MARK_MARK_SHIFT))&EFTU_TBU_CNT3_MARK_MARK_MASK)
/* CNT3_MARK Reg Mask */
#define EFTU_TBU_CNT3_MARK_MASK        0x00FFFFFFu

/* CNT3_CAPTURE Bit Fields */
#define EFTU_TBU_CNT3_CAPTURE_CAPTURE_MASK 0xFFFFFFu
#define EFTU_TBU_CNT3_CAPTURE_CAPTURE_SHIFT 0u
#define EFTU_TBU_CNT3_CAPTURE_CAPTURE_WIDTH 24u
#define EFTU_TBU_CNT3_CAPTURE_CAPTURE(x) (((uint32_t)(((uint32_t)(x))<<EFTU_TBU_CNT3_CAPTURE_CAPTURE_SHIFT))&EFTU_TBU_CNT3_CAPTURE_CAPTURE_MASK)
/* CNT3_CAPTURE Reg Mask */
#define EFTU_TBU_CNT3_CAPTURE_MASK     0x00FFFFFFu

/* EAC_TPR Bit Fields */
#define EFTU_TBU_EAC_TPR_MISSCNT_MASK  0xE000u
#define EFTU_TBU_EAC_TPR_MISSCNT_SHIFT 13u
#define EFTU_TBU_EAC_TPR_MISSCNT_WIDTH 3u
#define EFTU_TBU_EAC_TPR_MISSCNT(x)    (((uint32_t)(((uint32_t)(x))<<EFTU_TBU_EAC_TPR_MISSCNT_SHIFT))&EFTU_TBU_EAC_TPR_MISSCNT_MASK)
#define EFTU_TBU_EAC_TPR_IPH_MASK      0x1000u
#define EFTU_TBU_EAC_TPR_IPH_SHIFT     12u
#define EFTU_TBU_EAC_TPR_IPH_WIDTH     1u
#define EFTU_TBU_EAC_TPR_IPH(x)        (((uint32_t)(((uint32_t)(x))<<EFTU_TBU_EAC_TPR_IPH_SHIFT))&EFTU_TBU_EAC_TPR_IPH_MASK)
#define EFTU_TBU_EAC_TPR_HOLD_MASK     0x800u
#define EFTU_TBU_EAC_TPR_HOLD_SHIFT    11u
#define EFTU_TBU_EAC_TPR_HOLD_WIDTH    1u
#define EFTU_TBU_EAC_TPR_HOLD(x)       (((uint32_t)(((uint32_t)(x))<<EFTU_TBU_EAC_TPR_HOLD_SHIFT))&EFTU_TBU_EAC_TPR_HOLD_MASK)
#define EFTU_TBU_EAC_TPR_LAST_MASK     0x400u
#define EFTU_TBU_EAC_TPR_LAST_SHIFT    10u
#define EFTU_TBU_EAC_TPR_LAST_WIDTH    1u
#define EFTU_TBU_EAC_TPR_LAST(x)       (((uint32_t)(((uint32_t)(x))<<EFTU_TBU_EAC_TPR_LAST_SHIFT))&EFTU_TBU_EAC_TPR_LAST_MASK)
#define EFTU_TBU_EAC_TPR_TICKS_MASK    0x3FFu
#define EFTU_TBU_EAC_TPR_TICKS_SHIFT   0u
#define EFTU_TBU_EAC_TPR_TICKS_WIDTH   10u
#define EFTU_TBU_EAC_TPR_TICKS(x)      (((uint32_t)(((uint32_t)(x))<<EFTU_TBU_EAC_TPR_TICKS_SHIFT))&EFTU_TBU_EAC_TPR_TICKS_MASK)
/* EAC_TPR Reg Mask */
#define EFTU_TBU_EAC_TPR_MASK          0x0000FFFFu

/* EAC_TRR Bit Fields */
#define EFTU_TBU_EAC_TRR_INTEGER_MASK  0xFFFE00u
#define EFTU_TBU_EAC_TRR_INTEGER_SHIFT 9u
#define EFTU_TBU_EAC_TRR_INTEGER_WIDTH 15u
#define EFTU_TBU_EAC_TRR_INTEGER(x)    (((uint32_t)(((uint32_t)(x))<<EFTU_TBU_EAC_TRR_INTEGER_SHIFT))&EFTU_TBU_EAC_TRR_INTEGER_MASK)
#define EFTU_TBU_EAC_TRR_FRACTION_MASK 0x1FFu
#define EFTU_TBU_EAC_TRR_FRACTION_SHIFT 0u
#define EFTU_TBU_EAC_TRR_FRACTION_WIDTH 9u
#define EFTU_TBU_EAC_TRR_FRACTION(x)   (((uint32_t)(((uint32_t)(x))<<EFTU_TBU_EAC_TRR_FRACTION_SHIFT))&EFTU_TBU_EAC_TRR_FRACTION_MASK)
/* EAC_TRR Reg Mask */
#define EFTU_TBU_EAC_TRR_MASK          0x00FFFFFFu

/* EAC_CNT Bit Fields */
#define EFTU_TBU_EAC_CNT_CNT_MASK      0xFFFFFFu
#define EFTU_TBU_EAC_CNT_CNT_SHIFT     0u
#define EFTU_TBU_EAC_CNT_CNT_WIDTH     24u
#define EFTU_TBU_EAC_CNT_CNT(x)        (((uint32_t)(((uint32_t)(x))<<EFTU_TBU_EAC_CNT_CNT_SHIFT))&EFTU_TBU_EAC_CNT_CNT_MASK)
/* EAC_CNT Reg Mask */
#define EFTU_TBU_EAC_CNT_MASK          0x00FFFFFFu

/* EAC_CNTS Bit Fields */
#define EFTU_TBU_EAC_CNTS_CH_CNTS_WE_MASK 0x80000000u
#define EFTU_TBU_EAC_CNTS_CH_CNTS_WE_SHIFT 31u
#define EFTU_TBU_EAC_CNTS_CH_CNTS_WE_WIDTH 1u
#define EFTU_TBU_EAC_CNTS_CH_CNTS_WE(x) (((uint32_t)(((uint32_t)(x))<<EFTU_TBU_EAC_CNTS_CH_CNTS_WE_SHIFT))&EFTU_TBU_EAC_CNTS_CH_CNTS_WE_MASK)
#define EFTU_TBU_EAC_CNTS_CH_CNTS_MASK 0x7F000000u
#define EFTU_TBU_EAC_CNTS_CH_CNTS_SHIFT 24u
#define EFTU_TBU_EAC_CNTS_CH_CNTS_WIDTH 7u
#define EFTU_TBU_EAC_CNTS_CH_CNTS(x)   (((uint32_t)(((uint32_t)(x))<<EFTU_TBU_EAC_CNTS_CH_CNTS_SHIFT))&EFTU_TBU_EAC_CNTS_CH_CNTS_MASK)
#define EFTU_TBU_EAC_CNTS_CNTS_MASK    0xFFFFFFu
#define EFTU_TBU_EAC_CNTS_CNTS_SHIFT   0u
#define EFTU_TBU_EAC_CNTS_CNTS_WIDTH   24u
#define EFTU_TBU_EAC_CNTS_CNTS(x)      (((uint32_t)(((uint32_t)(x))<<EFTU_TBU_EAC_CNTS_CNTS_SHIFT))&EFTU_TBU_EAC_CNTS_CNTS_MASK)
/* EAC_CNTS Reg Mask */
#define EFTU_TBU_EAC_CNTS_MASK         0xFFFFFFFFu

/* EAC_WINDOW_S Bit Fields */
#define EFTU_TBU_EAC_WINDOW_S_START_MASK 0x1FFFFFFu
#define EFTU_TBU_EAC_WINDOW_S_START_SHIFT 0u
#define EFTU_TBU_EAC_WINDOW_S_START_WIDTH 25u
#define EFTU_TBU_EAC_WINDOW_S_START(x) (((uint32_t)(((uint32_t)(x))<<EFTU_TBU_EAC_WINDOW_S_START_SHIFT))&EFTU_TBU_EAC_WINDOW_S_START_MASK)
/* EAC_WINDOW_S Reg Mask */
#define EFTU_TBU_EAC_WINDOW_S_MASK     0x01FFFFFFu

/* EAC_WINDOW_E Bit Fields */
#define EFTU_TBU_EAC_WINDOW_E_END_MASK 0x1FFFFFFu
#define EFTU_TBU_EAC_WINDOW_E_END_SHIFT 0u
#define EFTU_TBU_EAC_WINDOW_E_END_WIDTH 25u
#define EFTU_TBU_EAC_WINDOW_E_END(x)   (((uint32_t)(((uint32_t)(x))<<EFTU_TBU_EAC_WINDOW_E_END_SHIFT))&EFTU_TBU_EAC_WINDOW_E_END_MASK)
/* EAC_WINDOW_E Reg Mask */
#define EFTU_TBU_EAC_WINDOW_E_MASK     0x01FFFFFFu

/* EAC_CTRL Bit Fields */
#define EFTU_TBU_EAC_CTRL_ANGLE_MODE_MASK 0x10000000u
#define EFTU_TBU_EAC_CTRL_ANGLE_MODE_SHIFT 28u
#define EFTU_TBU_EAC_CTRL_ANGLE_MODE_WIDTH 1u
#define EFTU_TBU_EAC_CTRL_ANGLE_MODE(x) (((uint32_t)(((uint32_t)(x))<<EFTU_TBU_EAC_CTRL_ANGLE_MODE_SHIFT))&EFTU_TBU_EAC_CTRL_ANGLE_MODE_MASK)
#define EFTU_TBU_EAC_CTRL_HALT_ENABLE_MASK 0x1000000u
#define EFTU_TBU_EAC_CTRL_HALT_ENABLE_SHIFT 24u
#define EFTU_TBU_EAC_CTRL_HALT_ENABLE_WIDTH 1u
#define EFTU_TBU_EAC_CTRL_HALT_ENABLE(x) (((uint32_t)(((uint32_t)(x))<<EFTU_TBU_EAC_CTRL_HALT_ENABLE_SHIFT))&EFTU_TBU_EAC_CTRL_HALT_ENABLE_MASK)
#define EFTU_TBU_EAC_CTRL_CNT_SW_CLR_MASK 0x800000u
#define EFTU_TBU_EAC_CTRL_CNT_SW_CLR_SHIFT 23u
#define EFTU_TBU_EAC_CTRL_CNT_SW_CLR_WIDTH 1u
#define EFTU_TBU_EAC_CTRL_CNT_SW_CLR(x) (((uint32_t)(((uint32_t)(x))<<EFTU_TBU_EAC_CTRL_CNT_SW_CLR_SHIFT))&EFTU_TBU_EAC_CTRL_CNT_SW_CLR_MASK)
#define EFTU_TBU_EAC_CTRL_CNT_NO_UP_MASK 0x400000u
#define EFTU_TBU_EAC_CTRL_CNT_NO_UP_SHIFT 22u
#define EFTU_TBU_EAC_CTRL_CNT_NO_UP_WIDTH 1u
#define EFTU_TBU_EAC_CTRL_CNT_NO_UP(x) (((uint32_t)(((uint32_t)(x))<<EFTU_TBU_EAC_CTRL_CNT_NO_UP_SHIFT))&EFTU_TBU_EAC_CTRL_CNT_NO_UP_MASK)
#define EFTU_TBU_EAC_CTRL_TCRCF_MASK   0x300000u
#define EFTU_TBU_EAC_CTRL_TCRCF_SHIFT  20u
#define EFTU_TBU_EAC_CTRL_TCRCF_WIDTH  2u
#define EFTU_TBU_EAC_CTRL_TCRCF(x)     (((uint32_t)(((uint32_t)(x))<<EFTU_TBU_EAC_CTRL_TCRCF_SHIFT))&EFTU_TBU_EAC_CTRL_TCRCF_MASK)
#define EFTU_TBU_EAC_CTRL_EDGE_SEL_MASK 0x30000u
#define EFTU_TBU_EAC_CTRL_EDGE_SEL_SHIFT 16u
#define EFTU_TBU_EAC_CTRL_EDGE_SEL_WIDTH 2u
#define EFTU_TBU_EAC_CTRL_EDGE_SEL(x)  (((uint32_t)(((uint32_t)(x))<<EFTU_TBU_EAC_CTRL_EDGE_SEL_SHIFT))&EFTU_TBU_EAC_CTRL_EDGE_SEL_MASK)
#define EFTU_TBU_EAC_CTRL_FPSCK_MASK   0x700u
#define EFTU_TBU_EAC_CTRL_FPSCK_SHIFT  8u
#define EFTU_TBU_EAC_CTRL_FPSCK_WIDTH  3u
#define EFTU_TBU_EAC_CTRL_FPSCK(x)     (((uint32_t)(((uint32_t)(x))<<EFTU_TBU_EAC_CTRL_FPSCK_SHIFT))&EFTU_TBU_EAC_CTRL_FPSCK_MASK)
#define EFTU_TBU_EAC_CTRL_PRESCALER_MASK 0x3Fu
#define EFTU_TBU_EAC_CTRL_PRESCALER_SHIFT 0u
#define EFTU_TBU_EAC_CTRL_PRESCALER_WIDTH 6u
#define EFTU_TBU_EAC_CTRL_PRESCALER(x) (((uint32_t)(((uint32_t)(x))<<EFTU_TBU_EAC_CTRL_PRESCALER_SHIFT))&EFTU_TBU_EAC_CTRL_PRESCALER_MASK)
/* EAC_CTRL Reg Mask */
#define EFTU_TBU_EAC_CTRL_MASK         0x11F3073Fu

/* EAC_STAT Bit Fields */
#define EFTU_TBU_EAC_STAT_WINDOW_S_MASK 0x10u
#define EFTU_TBU_EAC_STAT_WINDOW_S_SHIFT 4u
#define EFTU_TBU_EAC_STAT_WINDOW_S_WIDTH 1u
#define EFTU_TBU_EAC_STAT_WINDOW_S(x)  (((uint32_t)(((uint32_t)(x))<<EFTU_TBU_EAC_STAT_WINDOW_S_SHIFT))&EFTU_TBU_EAC_STAT_WINDOW_S_MASK)
#define EFTU_TBU_EAC_STAT_WINDOW_E_MASK 0x8u
#define EFTU_TBU_EAC_STAT_WINDOW_E_SHIFT 3u
#define EFTU_TBU_EAC_STAT_WINDOW_E_WIDTH 1u
#define EFTU_TBU_EAC_STAT_WINDOW_E(x)  (((uint32_t)(((uint32_t)(x))<<EFTU_TBU_EAC_STAT_WINDOW_E_SHIFT))&EFTU_TBU_EAC_STAT_WINDOW_E_MASK)
#define EFTU_TBU_EAC_STAT_TOOTH_TO_MASK 0x4u
#define EFTU_TBU_EAC_STAT_TOOTH_TO_SHIFT 2u
#define EFTU_TBU_EAC_STAT_TOOTH_TO_WIDTH 1u
#define EFTU_TBU_EAC_STAT_TOOTH_TO(x)  (((uint32_t)(((uint32_t)(x))<<EFTU_TBU_EAC_STAT_TOOTH_TO_SHIFT))&EFTU_TBU_EAC_STAT_TOOTH_TO_MASK)
#define EFTU_TBU_EAC_STAT_TOOTH_ERR_MASK 0x2u
#define EFTU_TBU_EAC_STAT_TOOTH_ERR_SHIFT 1u
#define EFTU_TBU_EAC_STAT_TOOTH_ERR_WIDTH 1u
#define EFTU_TBU_EAC_STAT_TOOTH_ERR(x) (((uint32_t)(((uint32_t)(x))<<EFTU_TBU_EAC_STAT_TOOTH_ERR_SHIFT))&EFTU_TBU_EAC_STAT_TOOTH_ERR_MASK)
#define EFTU_TBU_EAC_STAT_TOOTH_DET_MASK 0x1u
#define EFTU_TBU_EAC_STAT_TOOTH_DET_SHIFT 0u
#define EFTU_TBU_EAC_STAT_TOOTH_DET_WIDTH 1u
#define EFTU_TBU_EAC_STAT_TOOTH_DET(x) (((uint32_t)(((uint32_t)(x))<<EFTU_TBU_EAC_STAT_TOOTH_DET_SHIFT))&EFTU_TBU_EAC_STAT_TOOTH_DET_MASK)
/* EAC_STAT Reg Mask */
#define EFTU_TBU_EAC_STAT_MASK         0x0000001Fu

/* EAC_IRQEN Bit Fields */
#define EFTU_TBU_EAC_IRQEN_TOOTH_TO_IEN_MASK 0x4u
#define EFTU_TBU_EAC_IRQEN_TOOTH_TO_IEN_SHIFT 2u
#define EFTU_TBU_EAC_IRQEN_TOOTH_TO_IEN_WIDTH 1u
#define EFTU_TBU_EAC_IRQEN_TOOTH_TO_IEN(x) (((uint32_t)(((uint32_t)(x))<<EFTU_TBU_EAC_IRQEN_TOOTH_TO_IEN_SHIFT))&EFTU_TBU_EAC_IRQEN_TOOTH_TO_IEN_MASK)
#define EFTU_TBU_EAC_IRQEN_TOOTH_ERR_IEN_MASK 0x2u
#define EFTU_TBU_EAC_IRQEN_TOOTH_ERR_IEN_SHIFT 1u
#define EFTU_TBU_EAC_IRQEN_TOOTH_ERR_IEN_WIDTH 1u
#define EFTU_TBU_EAC_IRQEN_TOOTH_ERR_IEN(x) (((uint32_t)(((uint32_t)(x))<<EFTU_TBU_EAC_IRQEN_TOOTH_ERR_IEN_SHIFT))&EFTU_TBU_EAC_IRQEN_TOOTH_ERR_IEN_MASK)
#define EFTU_TBU_EAC_IRQEN_TOOTH_DET_IEN_MASK 0x1u
#define EFTU_TBU_EAC_IRQEN_TOOTH_DET_IEN_SHIFT 0u
#define EFTU_TBU_EAC_IRQEN_TOOTH_DET_IEN_WIDTH 1u
#define EFTU_TBU_EAC_IRQEN_TOOTH_DET_IEN(x) (((uint32_t)(((uint32_t)(x))<<EFTU_TBU_EAC_IRQEN_TOOTH_DET_IEN_SHIFT))&EFTU_TBU_EAC_IRQEN_TOOTH_DET_IEN_MASK)
/* EAC_IRQEN Reg Mask */
#define EFTU_TBU_EAC_IRQEN_MASK        0x00000007u


/*!
 * @}
 */ /* end of group EFTU_TBU_Register_Masks */

/*!
 * @}
 */ /* end of group EFTU_TBU_Peripheral_Access_Layer */

#endif
