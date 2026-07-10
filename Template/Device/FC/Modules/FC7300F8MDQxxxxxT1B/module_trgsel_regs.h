#ifndef _MODULE_TRGSEL_gmbhdijq112_REGS_H_TRGSEL_H_
#define _MODULE_TRGSEL_gmbhdijq112_REGS_H_TRGSEL_H_

/* ----------------------------------------------------------------------------
   -- TRGSEL Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TRGSEL_Peripheral_Access_Layer TRGSEL Peripheral Access Layer
 * @{
 */

/** TRGSEL - Size of Registers Arrays */

/** TRGSEL - Register Layout Typedef */
#define TRGSEL_OUT_SEL_COUNT 32

typedef struct {

  __IO uint32_t OUT_SEL[TRGSEL_OUT_SEL_COUNT] ; /* OUT SEL for N, offset: 0x0 */

} TRGSEL_Type, *TRGSEL_MemMapPtr;


/* TRGSEL - Peripheral instance base addresses */
/** Peripheral TRGSEL0 base address */
#define TRGSEL0_BASE                             (0x40026000u)
/** Peripheral TRGSEL0 base pointer */
#define TRGSEL0                                  ((TRGSEL_Type *)TRGSEL0_BASE)
/** Peripheral TRGSEL1 base address */
#define TRGSEL1_BASE                             (0x40027000u)
/** Peripheral TRGSEL1 base pointer */
#define TRGSEL1                                  ((TRGSEL_Type *)TRGSEL1_BASE)
/** Peripheral TRGSEL2 base address */
#define TRGSEL2_BASE                             (0x40028000u)
/** Peripheral TRGSEL2 base pointer */
#define TRGSEL2                                  ((TRGSEL_Type *)TRGSEL2_BASE)
/** Peripheral TRGSEL3 base address */
#define TRGSEL3_BASE                             (0x40029000u)
/** Peripheral TRGSEL3 base pointer */
#define TRGSEL3                                  ((TRGSEL_Type *)TRGSEL3_BASE)
/** Peripheral TRGSEL4 base address */
#define TRGSEL4_BASE                             (0x40039000u)
/** Peripheral TRGSEL4 base pointer */
#define TRGSEL4                                  ((TRGSEL_Type *)TRGSEL4_BASE)
/** Peripheral TRGSEL5 base address */
#define TRGSEL5_BASE                             (0x4003a000u)
/** Peripheral TRGSEL5 base pointer */
#define TRGSEL5                                  ((TRGSEL_Type *)TRGSEL5_BASE)
/** Peripheral TRGSEL6 base address */
#define TRGSEL6_BASE                             (0x4003b000u)
/** Peripheral TRGSEL6 base pointer */
#define TRGSEL6                                  ((TRGSEL_Type *)TRGSEL6_BASE)
/** Peripheral TRGSEL7 base address */
#define TRGSEL7_BASE                             (0x4003c000u)
/** Peripheral TRGSEL7 base pointer */
#define TRGSEL7                                  ((TRGSEL_Type *)TRGSEL7_BASE)
/** Peripheral TRGSEL8 base address */
#define TRGSEL8_BASE                             (0x4003d000u)
/** Peripheral TRGSEL8 base pointer */
#define TRGSEL8                                  ((TRGSEL_Type *)TRGSEL8_BASE)
// need fill by yourself
///** Number of interrupt vector arrays for the TRGSEL module. */
//#define TRGSEL_IRQS_ARR_COUNT                       (1u)
///** Number of interrupt channels for the TRGSEL module. */
//#define TRGSEL_IRQS_CH_COUNT                        (1u)
///** Interrupt vectors for the TRGSEL peripheral type */
//#define TRGSEL_IRQS                              {TRGSEL0_IRQn, TRGSEL1_IRQn, TRGSEL2_IRQn, TRGSEL3_IRQn, TRGSEL4_IRQn, TRGSEL5_IRQn, TRGSEL6_IRQn, TRGSEL7_IRQn, TRGSEL8_IRQn}


/* ----------------------------------------------------------------------------
   -- TRGSEL Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TRGSEL_Register_Masks TRGSEL Register Masks
 * @{
 */

/* OUT_SEL Bit Fields */
#define TRGSEL_OUT_SEL_LOCK_MASK       0x80000000u
#define TRGSEL_OUT_SEL_LOCK_SHIFT      31u
#define TRGSEL_OUT_SEL_LOCK_WIDTH      1u
#define TRGSEL_OUT_SEL_LOCK(x)         (((uint32_t)(((uint32_t)(x))<<TRGSEL_OUT_SEL_LOCK_SHIFT))&TRGSEL_OUT_SEL_LOCK_MASK)
#define TRGSEL_OUT_SEL_SEL_3_MASK      0x7F000000u
#define TRGSEL_OUT_SEL_SEL_3_SHIFT     24u
#define TRGSEL_OUT_SEL_SEL_3_WIDTH     7u
#define TRGSEL_OUT_SEL_SEL_3(x)        (((uint32_t)(((uint32_t)(x))<<TRGSEL_OUT_SEL_SEL_3_SHIFT))&TRGSEL_OUT_SEL_SEL_3_MASK)
#define TRGSEL_OUT_SEL_SEL_2_MASK      0x7F0000u
#define TRGSEL_OUT_SEL_SEL_2_SHIFT     16u
#define TRGSEL_OUT_SEL_SEL_2_WIDTH     7u
#define TRGSEL_OUT_SEL_SEL_2(x)        (((uint32_t)(((uint32_t)(x))<<TRGSEL_OUT_SEL_SEL_2_SHIFT))&TRGSEL_OUT_SEL_SEL_2_MASK)
#define TRGSEL_OUT_SEL_SEL_1_MASK      0x7F00u
#define TRGSEL_OUT_SEL_SEL_1_SHIFT     8u
#define TRGSEL_OUT_SEL_SEL_1_WIDTH     7u
#define TRGSEL_OUT_SEL_SEL_1(x)        (((uint32_t)(((uint32_t)(x))<<TRGSEL_OUT_SEL_SEL_1_SHIFT))&TRGSEL_OUT_SEL_SEL_1_MASK)
#define TRGSEL_OUT_SEL_SEL_0_MASK      0x7Fu
#define TRGSEL_OUT_SEL_SEL_0_SHIFT     0u
#define TRGSEL_OUT_SEL_SEL_0_WIDTH     7u
#define TRGSEL_OUT_SEL_SEL_0(x)        (((uint32_t)(((uint32_t)(x))<<TRGSEL_OUT_SEL_SEL_0_SHIFT))&TRGSEL_OUT_SEL_SEL_0_MASK)
/* OUT_SEL0 Reg Mask */
#define TRGSEL_OUT_SEL_MASK            0xFF7F7F7Fu


/*!
 * @}
 */ /* end of group TRGSEL_Register_Masks */

/*!
 * @}
 */ /* end of group TRGSEL_Peripheral_Access_Layer */

#endif
