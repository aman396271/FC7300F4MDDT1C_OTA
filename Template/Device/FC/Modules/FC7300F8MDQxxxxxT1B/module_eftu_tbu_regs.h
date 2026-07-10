#ifndef _MODULE_EFTU_TBU_gmbhdijq61_REGS_H_EFTU_TBU_H_
#define _MODULE_EFTU_TBU_gmbhdijq61_REGS_H_EFTU_TBU_H_

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
#define EFTU_TBU_CNT3_CTRL_USE_CNT2_MASK 0x10u
#define EFTU_TBU_CNT3_CTRL_USE_CNT2_SHIFT 4u
#define EFTU_TBU_CNT3_CTRL_USE_CNT2_WIDTH 1u
#define EFTU_TBU_CNT3_CTRL_USE_CNT2(x) (((uint32_t)(((uint32_t)(x))<<EFTU_TBU_CNT3_CTRL_USE_CNT2_SHIFT))&EFTU_TBU_CNT3_CTRL_USE_CNT2_MASK)
/* CNT3_CTRL Reg Mask */
#define EFTU_TBU_CNT3_CTRL_MASK        0x00000011u

/* CNT3_BASE Bit Fields */
#define EFTU_TBU_CNT3_BASE_BASE_MASK   0xFFFFFFu
#define EFTU_TBU_CNT3_BASE_BASE_SHIFT  0u
#define EFTU_TBU_CNT3_BASE_BASE_WIDTH  24u
#define EFTU_TBU_CNT3_BASE_BASE(x)     (((uint32_t)(((uint32_t)(x))<<EFTU_TBU_CNT3_BASE_BASE_SHIFT))&EFTU_TBU_CNT3_BASE_BASE_MASK)
/* CNT3_BASE Reg Mask */
#define EFTU_TBU_CNT3_BASE_MASK        0x00FFFFFFu

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


/*!
 * @}
 */ /* end of group EFTU_TBU_Register_Masks */

/*!
 * @}
 */ /* end of group EFTU_TBU_Peripheral_Access_Layer */

#endif
