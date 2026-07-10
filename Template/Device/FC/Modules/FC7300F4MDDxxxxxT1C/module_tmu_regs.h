#ifndef _MODULE_TMU_gmbhdijq59_REGS_H_TMU_H_
#define _MODULE_TMU_gmbhdijq59_REGS_H_TMU_H_

/* ----------------------------------------------------------------------------
   -- TMU Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TMU_Peripheral_Access_Layer TMU Peripheral Access Layer
 * @{
 */

/** TMU - Size of Registers Arrays */

/** TMU - Register Layout Typedef */

typedef struct {

  __IO uint32_t UNLOCK                        ; /* Unlock Register, offset: 0x0 */
       uint8_t  RESERVED_0[8];
  __IO uint32_t TV_CTRL                       ; /* Temperature Voltage Control Register, offset: 0xC */
  __IO uint32_t TV_STATUS                     ; /* Temperature Voltage Status Register, offset: 0x10 */
       uint8_t  RESERVED_1[8];
  __I  uint32_t TV_TRIM                       ; /* Temperature Voltage Trim Register, offset: 0x1C */

} TMU_Type, *TMU_MemMapPtr;


/* TMU - Peripheral instance base addresses */
/** Peripheral TMU base address */
#define TMU_BASE                                 (0x40043000u)
/** Peripheral TMU base pointer */
#define TMU                                      ((TMU_Type *)TMU_BASE)
// need fill by yourself
///** Number of interrupt vector arrays for the TMU module. */
//#define TMU_IRQS_ARR_COUNT                       (1u)
///** Number of interrupt channels for the TMU module. */
//#define TMU_IRQS_CH_COUNT                        (1u)
///** Interrupt vectors for the TMU peripheral type */
//#define TMU_IRQS                                 {TMU0_IRQn}


/* ----------------------------------------------------------------------------
   -- TMU Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TMU_Register_Masks TMU Register Masks
 * @{
 */

/* UNLOCK Bit Fields */
#define TMU_UNLOCK_UNLOCK_MASK         0x1u
#define TMU_UNLOCK_UNLOCK_SHIFT        0u
#define TMU_UNLOCK_UNLOCK_WIDTH        1u
#define TMU_UNLOCK_UNLOCK(x)           (((uint32_t)(((uint32_t)(x))<<TMU_UNLOCK_UNLOCK_SHIFT))&TMU_UNLOCK_UNLOCK_MASK)
/* UNLOCK Reg Mask */
#define TMU_UNLOCK_MASK                0x00000001u

/* TV_CTRL Bit Fields */
#define TMU_TV_CTRL_TV_CMP1F_IE_MASK   0x4000000u
#define TMU_TV_CTRL_TV_CMP1F_IE_SHIFT  26u
#define TMU_TV_CTRL_TV_CMP1F_IE_WIDTH  1u
#define TMU_TV_CTRL_TV_CMP1F_IE(x)     (((uint32_t)(((uint32_t)(x))<<TMU_TV_CTRL_TV_CMP1F_IE_SHIFT))&TMU_TV_CTRL_TV_CMP1F_IE_MASK)
#define TMU_TV_CTRL_TV_CMP0F_IE_MASK   0x2000000u
#define TMU_TV_CTRL_TV_CMP0F_IE_SHIFT  25u
#define TMU_TV_CTRL_TV_CMP0F_IE_WIDTH  1u
#define TMU_TV_CTRL_TV_CMP0F_IE(x)     (((uint32_t)(((uint32_t)(x))<<TMU_TV_CTRL_TV_CMP0F_IE_SHIFT))&TMU_TV_CTRL_TV_CMP0F_IE_MASK)
#define TMU_TV_CTRL_TV_STOP_EN_MASK    0x4u
#define TMU_TV_CTRL_TV_STOP_EN_SHIFT   2u
#define TMU_TV_CTRL_TV_STOP_EN_WIDTH   1u
#define TMU_TV_CTRL_TV_STOP_EN(x)      (((uint32_t)(((uint32_t)(x))<<TMU_TV_CTRL_TV_STOP_EN_SHIFT))&TMU_TV_CTRL_TV_STOP_EN_MASK)
#define TMU_TV_CTRL_TV_EN_MASK         0x1u
#define TMU_TV_CTRL_TV_EN_SHIFT        0u
#define TMU_TV_CTRL_TV_EN_WIDTH        1u
#define TMU_TV_CTRL_TV_EN(x)           (((uint32_t)(((uint32_t)(x))<<TMU_TV_CTRL_TV_EN_SHIFT))&TMU_TV_CTRL_TV_EN_MASK)
/* TV_CTRL Reg Mask */
#define TMU_TV_CTRL_MASK               0x06000005u

/* TV_STATUS Bit Fields */
#define TMU_TV_STATUS_TV_CMP1_MASK     0x400u
#define TMU_TV_STATUS_TV_CMP1_SHIFT    10u
#define TMU_TV_STATUS_TV_CMP1_WIDTH    1u
#define TMU_TV_STATUS_TV_CMP1(x)       (((uint32_t)(((uint32_t)(x))<<TMU_TV_STATUS_TV_CMP1_SHIFT))&TMU_TV_STATUS_TV_CMP1_MASK)
#define TMU_TV_STATUS_TV_CMP0_MASK     0x200u
#define TMU_TV_STATUS_TV_CMP0_SHIFT    9u
#define TMU_TV_STATUS_TV_CMP0_WIDTH    1u
#define TMU_TV_STATUS_TV_CMP0(x)       (((uint32_t)(((uint32_t)(x))<<TMU_TV_STATUS_TV_CMP0_SHIFT))&TMU_TV_STATUS_TV_CMP0_MASK)
#define TMU_TV_STATUS_TV_CMP1F_MASK    0x4u
#define TMU_TV_STATUS_TV_CMP1F_SHIFT   2u
#define TMU_TV_STATUS_TV_CMP1F_WIDTH   1u
#define TMU_TV_STATUS_TV_CMP1F(x)      (((uint32_t)(((uint32_t)(x))<<TMU_TV_STATUS_TV_CMP1F_SHIFT))&TMU_TV_STATUS_TV_CMP1F_MASK)
#define TMU_TV_STATUS_TV_CMP0F_MASK    0x2u
#define TMU_TV_STATUS_TV_CMP0F_SHIFT   1u
#define TMU_TV_STATUS_TV_CMP0F_WIDTH   1u
#define TMU_TV_STATUS_TV_CMP0F(x)      (((uint32_t)(((uint32_t)(x))<<TMU_TV_STATUS_TV_CMP0F_SHIFT))&TMU_TV_STATUS_TV_CMP0F_MASK)
#define TMU_TV_STATUS_TV_RDYF_MASK     0x1u
#define TMU_TV_STATUS_TV_RDYF_SHIFT    0u
#define TMU_TV_STATUS_TV_RDYF_WIDTH    1u
#define TMU_TV_STATUS_TV_RDYF(x)       (((uint32_t)(((uint32_t)(x))<<TMU_TV_STATUS_TV_RDYF_SHIFT))&TMU_TV_STATUS_TV_RDYF_MASK)
/* TV_STATUS Reg Mask */
#define TMU_TV_STATUS_MASK             0x00000607u

/* TV_TRIM Bit Fields */
#define TMU_TV_TRIM_TV_TCODE_MASK      0xFFF0000u
#define TMU_TV_TRIM_TV_TCODE_SHIFT     16u
#define TMU_TV_TRIM_TV_TCODE_WIDTH     12u
#define TMU_TV_TRIM_TV_TCODE(x)        (((uint32_t)(((uint32_t)(x))<<TMU_TV_TRIM_TV_TCODE_SHIFT))&TMU_TV_TRIM_TV_TCODE_MASK)
#define TMU_TV_TRIM_TV_SLOPE_MASK      0x1FFFu
#define TMU_TV_TRIM_TV_SLOPE_SHIFT     0u
#define TMU_TV_TRIM_TV_SLOPE_WIDTH     13u
#define TMU_TV_TRIM_TV_SLOPE(x)        (((uint32_t)(((uint32_t)(x))<<TMU_TV_TRIM_TV_SLOPE_SHIFT))&TMU_TV_TRIM_TV_SLOPE_MASK)
/* TV_TRIM Reg Mask */
#define TMU_TV_TRIM_MASK               0x0FFF1FFFu


/*!
 * @}
 */ /* end of group TMU_Register_Masks */

/*!
 * @}
 */ /* end of group TMU_Peripheral_Access_Layer */

#endif
