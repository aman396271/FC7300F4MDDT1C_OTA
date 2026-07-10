#ifndef _MODULE_DMAMUX_gmbhdijq254_REGS_H_DMAMUX_H_
#define _MODULE_DMAMUX_gmbhdijq254_REGS_H_DMAMUX_H_

/* ----------------------------------------------------------------------------
   -- DMAMUX Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DMAMUX_Peripheral_Access_Layer DMAMUX Peripheral Access Layer
 * @{
 */

/** DMAMUX - Size of Registers Arrays */

/** DMAMUX - Register Layout Typedef */
#define DMAMUX_CHCFG_COUNT 32

typedef struct {

  __IO uint8_t  CHCFG[DMAMUX_CHCFG_COUNT]     ; /* Channel N Configuration Register, offset: 0x0 */
  __IO uint8_t  CHTRG                         ; /* Channel N Trigger Register, offset: 0x20 */

} DMAMUX_Type, *DMAMUX_MemMapPtr;


/* DMAMUX - Peripheral instance base addresses */
/** Peripheral DMAMUX0 base address */
#define DMAMUX0_BASE                             (0x4000a000u)
/** Peripheral DMAMUX0 base pointer */
#define DMAMUX0                                  ((DMAMUX_Type *)DMAMUX0_BASE)
/** Peripheral DMAMUX1 base address */
#define DMAMUX1_BASE                             (0x4040a000u)
/** Peripheral DMAMUX1 base pointer */
#define DMAMUX1                                  ((DMAMUX_Type *)DMAMUX1_BASE)
// need fill by yourself
///** Number of interrupt vector arrays for the DMAMUX module. */
//#define DMAMUX_IRQS_ARR_COUNT                       (1u)
///** Number of interrupt channels for the DMAMUX module. */
//#define DMAMUX_IRQS_CH_COUNT                        (1u)
///** Interrupt vectors for the DMAMUX peripheral type */
//#define DMAMUX_IRQS                              {DMAMUX0_IRQn, DMAMUX1_IRQn}


/* ----------------------------------------------------------------------------
   -- DMAMUX Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DMAMUX_Register_Masks DMAMUX Register Masks
 * @{
 */

/* CHCFG Bit Fields */
#define DMAMUX_CHCFG_ENBL_MASK         0x80u
#define DMAMUX_CHCFG_ENBL_SHIFT        7u
#define DMAMUX_CHCFG_ENBL_WIDTH        1u
#define DMAMUX_CHCFG_ENBL(x)           (((uint8_t)(((uint8_t)(x))<<DMAMUX_CHCFG_ENBL_SHIFT))&DMAMUX_CHCFG_ENBL_MASK)
#define DMAMUX_CHCFG_SOURCE_MASK       0x7Fu
#define DMAMUX_CHCFG_SOURCE_SHIFT      0u
#define DMAMUX_CHCFG_SOURCE_WIDTH      7u
#define DMAMUX_CHCFG_SOURCE(x)         (((uint8_t)(((uint8_t)(x))<<DMAMUX_CHCFG_SOURCE_SHIFT))&DMAMUX_CHCFG_SOURCE_MASK)
/* CHCFG0 Reg Mask */
#define DMAMUX_CHCFG_MASK              0xFFu

/* CHTRG Bit Fields */
#define DMAMUX_CHTRG_TRIG3_MASK        0x8u
#define DMAMUX_CHTRG_TRIG3_SHIFT       3u
#define DMAMUX_CHTRG_TRIG3_WIDTH       1u
#define DMAMUX_CHTRG_TRIG3(x)          (((uint8_t)(((uint8_t)(x))<<DMAMUX_CHTRG_TRIG3_SHIFT))&DMAMUX_CHTRG_TRIG3_MASK)
#define DMAMUX_CHTRG_TRIG2_MASK        0x4u
#define DMAMUX_CHTRG_TRIG2_SHIFT       2u
#define DMAMUX_CHTRG_TRIG2_WIDTH       1u
#define DMAMUX_CHTRG_TRIG2(x)          (((uint8_t)(((uint8_t)(x))<<DMAMUX_CHTRG_TRIG2_SHIFT))&DMAMUX_CHTRG_TRIG2_MASK)
#define DMAMUX_CHTRG_TRIG1_MASK        0x2u
#define DMAMUX_CHTRG_TRIG1_SHIFT       1u
#define DMAMUX_CHTRG_TRIG1_WIDTH       1u
#define DMAMUX_CHTRG_TRIG1(x)          (((uint8_t)(((uint8_t)(x))<<DMAMUX_CHTRG_TRIG1_SHIFT))&DMAMUX_CHTRG_TRIG1_MASK)
#define DMAMUX_CHTRG_TRIG0_MASK        0x1u
#define DMAMUX_CHTRG_TRIG0_SHIFT       0u
#define DMAMUX_CHTRG_TRIG0_WIDTH       1u
#define DMAMUX_CHTRG_TRIG0(x)          (((uint8_t)(((uint8_t)(x))<<DMAMUX_CHTRG_TRIG0_SHIFT))&DMAMUX_CHTRG_TRIG0_MASK)
/* CHTRG Reg Mask */
#define DMAMUX_CHTRG_MASK              0x0Fu


/*!
 * @}
 */ /* end of group DMAMUX_Register_Masks */

/*!
 * @}
 */ /* end of group DMAMUX_Peripheral_Access_Layer */

#endif
