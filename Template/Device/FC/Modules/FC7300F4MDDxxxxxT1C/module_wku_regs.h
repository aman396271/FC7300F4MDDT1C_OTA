#ifndef _MODULE_WKU_gmbhdijq10_REGS_H_WKU_H_
#define _MODULE_WKU_gmbhdijq10_REGS_H_WKU_H_

/* ----------------------------------------------------------------------------
   -- WKU Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup WKU_Peripheral_Access_Layer WKU Peripheral Access Layer
 * @{
 */

/** WKU - Size of Registers Arrays */

/** WKU - Register Layout Typedef */

typedef struct {

  __IO uint32_t SWW                           ; /* Software Wakeup Register, offset: 0x00 */
  __IO uint32_t MDC                           ; /* Module Delay Configuration Register0, offset: 0x04 */
  __IO uint32_t MWER0                         ; /* Module Wakeup Enable Register0, offset: 0x08 */
  __IO uint32_t MWER1                         ; /* Module Wakeup Enable Register1, offset: 0x0C */
  __IO uint32_t MWER2                         ; /* Module Wakeup Enable Register2, offset: 0x10 */
       uint8_t  RESERVED_0[4];
  __I  uint32_t MWFR0                         ; /* Module Wakeup Flag Register0, offset: 0x18 */
  __I  uint32_t MWFR1                         ; /* Module Wakeup Flag Register1, offset: 0x1C */
  __I  uint32_t MWFR2                         ; /* Module Wakeup Flag Register2, offset: 0x20 */

} WKU_Type, *WKU_MemMapPtr;


/* WKU - Peripheral instance base addresses */
/** Peripheral WKU base address */
#define WKU_BASE                                 (0x4003f000u)
/** Peripheral WKU base pointer */
#define WKU                                      ((WKU_Type *)WKU_BASE)
// need fill by yourself
///** Number of interrupt vector arrays for the WKU module. */
//#define WKU_IRQS_ARR_COUNT                       (1u)
///** Number of interrupt channels for the WKU module. */
//#define WKU_IRQS_CH_COUNT                        (1u)
///** Interrupt vectors for the WKU peripheral type */
//#define WKU_IRQS                                 {WKU_IRQn}


/* ----------------------------------------------------------------------------
   -- WKU Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup WKU_Register_Masks WKU Register Masks
 * @{
 */

/* SWW Bit Fields */
#define WKU_SWW_SOFTWARE_WAKEUP_MASK   0xFFFFFFFFu
#define WKU_SWW_SOFTWARE_WAKEUP_SHIFT  0u
#define WKU_SWW_SOFTWARE_WAKEUP_WIDTH  32u
#define WKU_SWW_SOFTWARE_WAKEUP(x)     (((uint32_t)(((uint32_t)(x))<<WKU_SWW_SOFTWARE_WAKEUP_SHIFT))&WKU_SWW_SOFTWARE_WAKEUP_MASK)
/* SWW Reg Mask */
#define WKU_SWW_MASK                   0xFFFFFFFFu

/* MDC Bit Fields */
#define WKU_MDC_DLYEN_MASK             0x80000000u
#define WKU_MDC_DLYEN_SHIFT            31u
#define WKU_MDC_DLYEN_WIDTH            1u
#define WKU_MDC_DLYEN(x)               (((uint32_t)(((uint32_t)(x))<<WKU_MDC_DLYEN_SHIFT))&WKU_MDC_DLYEN_MASK)
#define WKU_MDC_DELAYTIME_MASK         0x7u
#define WKU_MDC_DELAYTIME_SHIFT        0u
#define WKU_MDC_DELAYTIME_WIDTH        3u
#define WKU_MDC_DELAYTIME(x)           (((uint32_t)(((uint32_t)(x))<<WKU_MDC_DELAYTIME_SHIFT))&WKU_MDC_DELAYTIME_MASK)
/* MDC Reg Mask */
#define WKU_MDC_MASK                   0x80000007u

/* MWER0 Bit Fields */
#define WKU_MWER0_MWE7_MASK            0x80u
#define WKU_MWER0_MWE7_SHIFT           7u
#define WKU_MWER0_MWE7_WIDTH           1u
#define WKU_MWER0_MWE7(x)              (((uint32_t)(((uint32_t)(x))<<WKU_MWER0_MWE7_SHIFT))&WKU_MWER0_MWE7_MASK)
#define WKU_MWER0_MWE6_MASK            0x40u
#define WKU_MWER0_MWE6_SHIFT           6u
#define WKU_MWER0_MWE6_WIDTH           1u
#define WKU_MWER0_MWE6(x)              (((uint32_t)(((uint32_t)(x))<<WKU_MWER0_MWE6_SHIFT))&WKU_MWER0_MWE6_MASK)
#define WKU_MWER0_MWE5_MASK            0x20u
#define WKU_MWER0_MWE5_SHIFT           5u
#define WKU_MWER0_MWE5_WIDTH           1u
#define WKU_MWER0_MWE5(x)              (((uint32_t)(((uint32_t)(x))<<WKU_MWER0_MWE5_SHIFT))&WKU_MWER0_MWE5_MASK)
#define WKU_MWER0_MWE4_MASK            0x10u
#define WKU_MWER0_MWE4_SHIFT           4u
#define WKU_MWER0_MWE4_WIDTH           1u
#define WKU_MWER0_MWE4(x)              (((uint32_t)(((uint32_t)(x))<<WKU_MWER0_MWE4_SHIFT))&WKU_MWER0_MWE4_MASK)
#define WKU_MWER0_MWE3_MASK            0x8u
#define WKU_MWER0_MWE3_SHIFT           3u
#define WKU_MWER0_MWE3_WIDTH           1u
#define WKU_MWER0_MWE3(x)              (((uint32_t)(((uint32_t)(x))<<WKU_MWER0_MWE3_SHIFT))&WKU_MWER0_MWE3_MASK)
#define WKU_MWER0_MWE2_MASK            0x4u
#define WKU_MWER0_MWE2_SHIFT           2u
#define WKU_MWER0_MWE2_WIDTH           1u
#define WKU_MWER0_MWE2(x)              (((uint32_t)(((uint32_t)(x))<<WKU_MWER0_MWE2_SHIFT))&WKU_MWER0_MWE2_MASK)
#define WKU_MWER0_MWE1_MASK            0x2u
#define WKU_MWER0_MWE1_SHIFT           1u
#define WKU_MWER0_MWE1_WIDTH           1u
#define WKU_MWER0_MWE1(x)              (((uint32_t)(((uint32_t)(x))<<WKU_MWER0_MWE1_SHIFT))&WKU_MWER0_MWE1_MASK)
#define WKU_MWER0_MWE0_MASK            0x1u
#define WKU_MWER0_MWE0_SHIFT           0u
#define WKU_MWER0_MWE0_WIDTH           1u
#define WKU_MWER0_MWE0(x)              (((uint32_t)(((uint32_t)(x))<<WKU_MWER0_MWE0_SHIFT))&WKU_MWER0_MWE0_MASK)
/* MWER0 Reg Mask */
#define WKU_MWER0_MASK                 0x000000FFu

/* MWER1 Bit Fields */
#define WKU_MWER1_MWE15_MASK           0x80u
#define WKU_MWER1_MWE15_SHIFT          7u
#define WKU_MWER1_MWE15_WIDTH          1u
#define WKU_MWER1_MWE15(x)             (((uint32_t)(((uint32_t)(x))<<WKU_MWER1_MWE15_SHIFT))&WKU_MWER1_MWE15_MASK)
#define WKU_MWER1_MWE14_MASK           0x40u
#define WKU_MWER1_MWE14_SHIFT          6u
#define WKU_MWER1_MWE14_WIDTH          1u
#define WKU_MWER1_MWE14(x)             (((uint32_t)(((uint32_t)(x))<<WKU_MWER1_MWE14_SHIFT))&WKU_MWER1_MWE14_MASK)
#define WKU_MWER1_MWE13_MASK           0x20u
#define WKU_MWER1_MWE13_SHIFT          5u
#define WKU_MWER1_MWE13_WIDTH          1u
#define WKU_MWER1_MWE13(x)             (((uint32_t)(((uint32_t)(x))<<WKU_MWER1_MWE13_SHIFT))&WKU_MWER1_MWE13_MASK)
#define WKU_MWER1_MWE12_MASK           0x10u
#define WKU_MWER1_MWE12_SHIFT          4u
#define WKU_MWER1_MWE12_WIDTH          1u
#define WKU_MWER1_MWE12(x)             (((uint32_t)(((uint32_t)(x))<<WKU_MWER1_MWE12_SHIFT))&WKU_MWER1_MWE12_MASK)
#define WKU_MWER1_MWE11_MASK           0x8u
#define WKU_MWER1_MWE11_SHIFT          3u
#define WKU_MWER1_MWE11_WIDTH          1u
#define WKU_MWER1_MWE11(x)             (((uint32_t)(((uint32_t)(x))<<WKU_MWER1_MWE11_SHIFT))&WKU_MWER1_MWE11_MASK)
#define WKU_MWER1_MWE10_MASK           0x4u
#define WKU_MWER1_MWE10_SHIFT          2u
#define WKU_MWER1_MWE10_WIDTH          1u
#define WKU_MWER1_MWE10(x)             (((uint32_t)(((uint32_t)(x))<<WKU_MWER1_MWE10_SHIFT))&WKU_MWER1_MWE10_MASK)
#define WKU_MWER1_MWE9_MASK            0x2u
#define WKU_MWER1_MWE9_SHIFT           1u
#define WKU_MWER1_MWE9_WIDTH           1u
#define WKU_MWER1_MWE9(x)              (((uint32_t)(((uint32_t)(x))<<WKU_MWER1_MWE9_SHIFT))&WKU_MWER1_MWE9_MASK)
#define WKU_MWER1_MWE8_MASK            0x1u
#define WKU_MWER1_MWE8_SHIFT           0u
#define WKU_MWER1_MWE8_WIDTH           1u
#define WKU_MWER1_MWE8(x)              (((uint32_t)(((uint32_t)(x))<<WKU_MWER1_MWE8_SHIFT))&WKU_MWER1_MWE8_MASK)
/* MWER1 Reg Mask */
#define WKU_MWER1_MASK                 0x000000FFu

/* MWER2 Bit Fields */
#define WKU_MWER2_MWE23_MASK           0x80u
#define WKU_MWER2_MWE23_SHIFT          7u
#define WKU_MWER2_MWE23_WIDTH          1u
#define WKU_MWER2_MWE23(x)             (((uint32_t)(((uint32_t)(x))<<WKU_MWER2_MWE23_SHIFT))&WKU_MWER2_MWE23_MASK)
#define WKU_MWER2_MWE22_MASK           0x40u
#define WKU_MWER2_MWE22_SHIFT          6u
#define WKU_MWER2_MWE22_WIDTH          1u
#define WKU_MWER2_MWE22(x)             (((uint32_t)(((uint32_t)(x))<<WKU_MWER2_MWE22_SHIFT))&WKU_MWER2_MWE22_MASK)
#define WKU_MWER2_MWE21_MASK           0x20u
#define WKU_MWER2_MWE21_SHIFT          5u
#define WKU_MWER2_MWE21_WIDTH          1u
#define WKU_MWER2_MWE21(x)             (((uint32_t)(((uint32_t)(x))<<WKU_MWER2_MWE21_SHIFT))&WKU_MWER2_MWE21_MASK)
#define WKU_MWER2_MWE20_MASK           0x10u
#define WKU_MWER2_MWE20_SHIFT          4u
#define WKU_MWER2_MWE20_WIDTH          1u
#define WKU_MWER2_MWE20(x)             (((uint32_t)(((uint32_t)(x))<<WKU_MWER2_MWE20_SHIFT))&WKU_MWER2_MWE20_MASK)
#define WKU_MWER2_MWE19_MASK           0x8u
#define WKU_MWER2_MWE19_SHIFT          3u
#define WKU_MWER2_MWE19_WIDTH          1u
#define WKU_MWER2_MWE19(x)             (((uint32_t)(((uint32_t)(x))<<WKU_MWER2_MWE19_SHIFT))&WKU_MWER2_MWE19_MASK)
#define WKU_MWER2_MWE18_MASK           0x4u
#define WKU_MWER2_MWE18_SHIFT          2u
#define WKU_MWER2_MWE18_WIDTH          1u
#define WKU_MWER2_MWE18(x)             (((uint32_t)(((uint32_t)(x))<<WKU_MWER2_MWE18_SHIFT))&WKU_MWER2_MWE18_MASK)
#define WKU_MWER2_MWE17_MASK           0x2u
#define WKU_MWER2_MWE17_SHIFT          1u
#define WKU_MWER2_MWE17_WIDTH          1u
#define WKU_MWER2_MWE17(x)             (((uint32_t)(((uint32_t)(x))<<WKU_MWER2_MWE17_SHIFT))&WKU_MWER2_MWE17_MASK)
#define WKU_MWER2_MWE16_MASK           0x1u
#define WKU_MWER2_MWE16_SHIFT          0u
#define WKU_MWER2_MWE16_WIDTH          1u
#define WKU_MWER2_MWE16(x)             (((uint32_t)(((uint32_t)(x))<<WKU_MWER2_MWE16_SHIFT))&WKU_MWER2_MWE16_MASK)
/* MWER2 Reg Mask */
#define WKU_MWER2_MASK                 0x000000FFu

/* MWFR0 Bit Fields */
#define WKU_MWFR0_MWF7_MASK            0x80u
#define WKU_MWFR0_MWF7_SHIFT           7u
#define WKU_MWFR0_MWF7_WIDTH           1u
#define WKU_MWFR0_MWF7(x)              (((uint32_t)(((uint32_t)(x))<<WKU_MWFR0_MWF7_SHIFT))&WKU_MWFR0_MWF7_MASK)
#define WKU_MWFR0_MWF6_MASK            0x40u
#define WKU_MWFR0_MWF6_SHIFT           6u
#define WKU_MWFR0_MWF6_WIDTH           1u
#define WKU_MWFR0_MWF6(x)              (((uint32_t)(((uint32_t)(x))<<WKU_MWFR0_MWF6_SHIFT))&WKU_MWFR0_MWF6_MASK)
#define WKU_MWFR0_MWF5_MASK            0x20u
#define WKU_MWFR0_MWF5_SHIFT           5u
#define WKU_MWFR0_MWF5_WIDTH           1u
#define WKU_MWFR0_MWF5(x)              (((uint32_t)(((uint32_t)(x))<<WKU_MWFR0_MWF5_SHIFT))&WKU_MWFR0_MWF5_MASK)
#define WKU_MWFR0_MWF4_MASK            0x10u
#define WKU_MWFR0_MWF4_SHIFT           4u
#define WKU_MWFR0_MWF4_WIDTH           1u
#define WKU_MWFR0_MWF4(x)              (((uint32_t)(((uint32_t)(x))<<WKU_MWFR0_MWF4_SHIFT))&WKU_MWFR0_MWF4_MASK)
#define WKU_MWFR0_MWF3_MASK            0x8u
#define WKU_MWFR0_MWF3_SHIFT           3u
#define WKU_MWFR0_MWF3_WIDTH           1u
#define WKU_MWFR0_MWF3(x)              (((uint32_t)(((uint32_t)(x))<<WKU_MWFR0_MWF3_SHIFT))&WKU_MWFR0_MWF3_MASK)
#define WKU_MWFR0_MWF2_MASK            0x4u
#define WKU_MWFR0_MWF2_SHIFT           2u
#define WKU_MWFR0_MWF2_WIDTH           1u
#define WKU_MWFR0_MWF2(x)              (((uint32_t)(((uint32_t)(x))<<WKU_MWFR0_MWF2_SHIFT))&WKU_MWFR0_MWF2_MASK)
#define WKU_MWFR0_MWF1_MASK            0x2u
#define WKU_MWFR0_MWF1_SHIFT           1u
#define WKU_MWFR0_MWF1_WIDTH           1u
#define WKU_MWFR0_MWF1(x)              (((uint32_t)(((uint32_t)(x))<<WKU_MWFR0_MWF1_SHIFT))&WKU_MWFR0_MWF1_MASK)
#define WKU_MWFR0_MWF0_MASK            0x1u
#define WKU_MWFR0_MWF0_SHIFT           0u
#define WKU_MWFR0_MWF0_WIDTH           1u
#define WKU_MWFR0_MWF0(x)              (((uint32_t)(((uint32_t)(x))<<WKU_MWFR0_MWF0_SHIFT))&WKU_MWFR0_MWF0_MASK)
/* MWFR0 Reg Mask */
#define WKU_MWFR0_MASK                 0x000000FFu

/* MWFR1 Bit Fields */
#define WKU_MWFR1_MWF15_MASK           0x80u
#define WKU_MWFR1_MWF15_SHIFT          7u
#define WKU_MWFR1_MWF15_WIDTH          1u
#define WKU_MWFR1_MWF15(x)             (((uint32_t)(((uint32_t)(x))<<WKU_MWFR1_MWF15_SHIFT))&WKU_MWFR1_MWF15_MASK)
#define WKU_MWFR1_MWF14_MASK           0x40u
#define WKU_MWFR1_MWF14_SHIFT          6u
#define WKU_MWFR1_MWF14_WIDTH          1u
#define WKU_MWFR1_MWF14(x)             (((uint32_t)(((uint32_t)(x))<<WKU_MWFR1_MWF14_SHIFT))&WKU_MWFR1_MWF14_MASK)
#define WKU_MWFR1_MWF13_MASK           0x20u
#define WKU_MWFR1_MWF13_SHIFT          5u
#define WKU_MWFR1_MWF13_WIDTH          1u
#define WKU_MWFR1_MWF13(x)             (((uint32_t)(((uint32_t)(x))<<WKU_MWFR1_MWF13_SHIFT))&WKU_MWFR1_MWF13_MASK)
#define WKU_MWFR1_MWF12_MASK           0x10u
#define WKU_MWFR1_MWF12_SHIFT          4u
#define WKU_MWFR1_MWF12_WIDTH          1u
#define WKU_MWFR1_MWF12(x)             (((uint32_t)(((uint32_t)(x))<<WKU_MWFR1_MWF12_SHIFT))&WKU_MWFR1_MWF12_MASK)
#define WKU_MWFR1_MWF11_MASK           0x8u
#define WKU_MWFR1_MWF11_SHIFT          3u
#define WKU_MWFR1_MWF11_WIDTH          1u
#define WKU_MWFR1_MWF11(x)             (((uint32_t)(((uint32_t)(x))<<WKU_MWFR1_MWF11_SHIFT))&WKU_MWFR1_MWF11_MASK)
#define WKU_MWFR1_MWF10_MASK           0x4u
#define WKU_MWFR1_MWF10_SHIFT          2u
#define WKU_MWFR1_MWF10_WIDTH          1u
#define WKU_MWFR1_MWF10(x)             (((uint32_t)(((uint32_t)(x))<<WKU_MWFR1_MWF10_SHIFT))&WKU_MWFR1_MWF10_MASK)
#define WKU_MWFR1_MWF9_MASK            0x2u
#define WKU_MWFR1_MWF9_SHIFT           1u
#define WKU_MWFR1_MWF9_WIDTH           1u
#define WKU_MWFR1_MWF9(x)              (((uint32_t)(((uint32_t)(x))<<WKU_MWFR1_MWF9_SHIFT))&WKU_MWFR1_MWF9_MASK)
#define WKU_MWFR1_MWF8_MASK            0x1u
#define WKU_MWFR1_MWF8_SHIFT           0u
#define WKU_MWFR1_MWF8_WIDTH           1u
#define WKU_MWFR1_MWF8(x)              (((uint32_t)(((uint32_t)(x))<<WKU_MWFR1_MWF8_SHIFT))&WKU_MWFR1_MWF8_MASK)
/* MWFR1 Reg Mask */
#define WKU_MWFR1_MASK                 0x000000FFu

/* MWFR2 Bit Fields */
#define WKU_MWFR2_MWF23_MASK           0x80u
#define WKU_MWFR2_MWF23_SHIFT          7u
#define WKU_MWFR2_MWF23_WIDTH          1u
#define WKU_MWFR2_MWF23(x)             (((uint32_t)(((uint32_t)(x))<<WKU_MWFR2_MWF23_SHIFT))&WKU_MWFR2_MWF23_MASK)
#define WKU_MWFR2_MWF22_MASK           0x40u
#define WKU_MWFR2_MWF22_SHIFT          6u
#define WKU_MWFR2_MWF22_WIDTH          1u
#define WKU_MWFR2_MWF22(x)             (((uint32_t)(((uint32_t)(x))<<WKU_MWFR2_MWF22_SHIFT))&WKU_MWFR2_MWF22_MASK)
#define WKU_MWFR2_MWF21_MASK           0x20u
#define WKU_MWFR2_MWF21_SHIFT          5u
#define WKU_MWFR2_MWF21_WIDTH          1u
#define WKU_MWFR2_MWF21(x)             (((uint32_t)(((uint32_t)(x))<<WKU_MWFR2_MWF21_SHIFT))&WKU_MWFR2_MWF21_MASK)
#define WKU_MWFR2_MWF20_MASK           0x10u
#define WKU_MWFR2_MWF20_SHIFT          4u
#define WKU_MWFR2_MWF20_WIDTH          1u
#define WKU_MWFR2_MWF20(x)             (((uint32_t)(((uint32_t)(x))<<WKU_MWFR2_MWF20_SHIFT))&WKU_MWFR2_MWF20_MASK)
#define WKU_MWFR2_MWF19_MASK           0x8u
#define WKU_MWFR2_MWF19_SHIFT          3u
#define WKU_MWFR2_MWF19_WIDTH          1u
#define WKU_MWFR2_MWF19(x)             (((uint32_t)(((uint32_t)(x))<<WKU_MWFR2_MWF19_SHIFT))&WKU_MWFR2_MWF19_MASK)
#define WKU_MWFR2_MWF18_MASK           0x4u
#define WKU_MWFR2_MWF18_SHIFT          2u
#define WKU_MWFR2_MWF18_WIDTH          1u
#define WKU_MWFR2_MWF18(x)             (((uint32_t)(((uint32_t)(x))<<WKU_MWFR2_MWF18_SHIFT))&WKU_MWFR2_MWF18_MASK)
#define WKU_MWFR2_MWF17_MASK           0x2u
#define WKU_MWFR2_MWF17_SHIFT          1u
#define WKU_MWFR2_MWF17_WIDTH          1u
#define WKU_MWFR2_MWF17(x)             (((uint32_t)(((uint32_t)(x))<<WKU_MWFR2_MWF17_SHIFT))&WKU_MWFR2_MWF17_MASK)
#define WKU_MWFR2_MWF16_MASK           0x1u
#define WKU_MWFR2_MWF16_SHIFT          0u
#define WKU_MWFR2_MWF16_WIDTH          1u
#define WKU_MWFR2_MWF16(x)             (((uint32_t)(((uint32_t)(x))<<WKU_MWFR2_MWF16_SHIFT))&WKU_MWFR2_MWF16_MASK)
/* MWFR2 Reg Mask */
#define WKU_MWFR2_MASK                 0x000000FFu


/*!
 * @}
 */ /* end of group WKU_Register_Masks */

/*!
 * @}
 */ /* end of group WKU_Peripheral_Access_Layer */

#endif
