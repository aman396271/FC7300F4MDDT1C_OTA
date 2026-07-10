#ifndef _MODULE_PCC_gmbhdijq16_REGS_H_PCC_H_
#define _MODULE_PCC_gmbhdijq16_REGS_H_PCC_H_

/* ----------------------------------------------------------------------------
   -- PCC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PCC_Peripheral_Access_Layer PCC Peripheral Access Layer
 * @{
 */

/** PCC - Size of Registers Arrays */

/** PCC - Register Layout Typedef */

typedef struct {

       uint8_t  RESERVED_0[32];
  __IO uint32_t PCC_DMA0                      ; /* DMA0 Clock Control Register, offset: 0x20 */
       uint8_t  RESERVED_1[4];
  __IO uint32_t PCC_DMAMUX0                   ; /* DMAMUX0 Clock Control Register, offset: 0x28 */
       uint8_t  RESERVED_2[32];
  __IO uint32_t PCC_ROM                       ; /* ROM Clock Control Register, offset: 0x4C */
       uint8_t  RESERVED_3[16];
  __IO uint32_t PCC_ERM0                      ; /* ERM0 Clock Control Register, offset: 0x60 */
  __IO uint32_t PCC_EIM0                      ; /* EIM0 Clock Control Register, offset: 0x64 */
  __IO uint32_t PCC_INTM0                     ; /* INTM0 Clock Control Register, offset: 0x68 */
  __IO uint32_t PCC_ISM0                      ; /* ISM0 Clock Control Register, offset: 0x6C */
       uint8_t  RESERVED_4[24];
  __IO uint32_t PCC_WDOG0                     ; /* WDOG0 Clock Control Register, offset: 0x88 */
       uint8_t  RESERVED_5[12];
  __IO uint32_t PCC_TRGSEL0                   ; /* TRGSEL0 Clock Control Register, offset: 0x98 */
  __IO uint32_t PCC_TRGSEL1                   ; /* TRGSEL1 Clock Control Register, offset: 0x9C */
  __IO uint32_t PCC_TRGSEL2                   ; /* TRGSEL2 Clock Control Register, offset: 0xA0 */
  __IO uint32_t PCC_TRGSEL3                   ; /* TRGSEL3 Clock Control Register, offset: 0xA4 */
  __IO uint32_t PCC_CRC0                      ; /* CRC0 Clock Control Register, offset: 0xA8 */
  __IO uint32_t PCC_CORDIC                    ; /* CORDIC Clock Control Register, offset: 0xAC */
  __IO uint32_t PCC_TSTMP0                    ; /* TSTMP0 Clock Control Register, offset: 0xB0 */
  __IO uint32_t PCC_TSTMP1                    ; /* TSTMP1 Clock Control Register, offset: 0xB4 */
  __IO uint32_t PCC_FCPIT0                    ; /* FCPIT0 Clock Control Register, offset: 0xB8 */
  __IO uint32_t PCC_AONTIMER0                 ; /* AONTIMER0 Clock Control Register, offset: 0xBC */
  __IO uint32_t PCC_RTC                       ; /* RTC Clock Control Register, offset: 0xC0 */
  __IO uint32_t PCC_CMU0                      ; /* CMU0 Clock Control Register, offset: 0xC4 */
  __IO uint32_t PCC_CMU1                      ; /* CMU1 Clock Control Register, offset: 0xC8 */
  __IO uint32_t PCC_CMU2                      ; /* CMU2 Clock Control Register, offset: 0xCC */
  __IO uint32_t PCC_CMU3                      ; /* CMU3 Clock Control Register, offset: 0xD0 */
  __IO uint32_t PCC_CMU4                      ; /* CMU4 Clock Control Register, offset: 0xD4 */
       uint8_t  RESERVED_6[4];
  __IO uint32_t PCC_PTIMER0                   ; /* PTIMER0 Clock Control Register, offset: 0xDC */
  __IO uint32_t PCC_PTIMER1                   ; /* PTIMER1 Clock Control Register, offset: 0xE0 */
       uint8_t  RESERVED_7[8];
  __IO uint32_t PCC_ADC0                      ; /* ADC0 Clock Control Register, offset: 0xEC */
  __IO uint32_t PCC_ADC1                      ; /* ADC1 Clock Control Register, offset: 0xF0 */
       uint8_t  RESERVED_8[8];
  __IO uint32_t PCC_WKU0                      ; /* WKU0 Clock Control Register, offset: 0xFC */
  __IO uint32_t PCC_CMP0                      ; /* CMP0 Clock Control Register, offset: 0x100 */
       uint8_t  RESERVED_9[8];
  __IO uint32_t PCC_TMU0                      ; /* TMU0 Clock Control Register, offset: 0x10C */
       uint8_t  RESERVED_10[64];
  __IO uint32_t PCC_SENT0                     ; /* SENT0 Clock Control Register, offset: 0x150 */
       uint8_t  RESERVED_11[12];
  __IO uint32_t PCC_MB0                       ; /* MB0 Clock Control Register, offset: 0x160 */
       uint8_t  RESERVED_12[12];
  __IO uint32_t PCC_FTU0                      ; /* FTU0 Clock Control Register, offset: 0x170 */
  __IO uint32_t PCC_FTU1                      ; /* FTU1 Clock Control Register, offset: 0x174 */
  __IO uint32_t PCC_FTU2                      ; /* FTU2 Clock Control Register, offset: 0x178 */
  __IO uint32_t PCC_FTU3                      ; /* FTU3 Clock Control Register, offset: 0x17C */
       uint8_t  RESERVED_13[8];
  __IO uint32_t PCC_FCSPI0                    ; /* FCSPI0 Clock Control Register, offset: 0x188 */
  __IO uint32_t PCC_FCSPI1                    ; /* FCSPI1 Clock Control Register, offset: 0x18C */
  __IO uint32_t PCC_FCSPI2                    ; /* FCSPI2 Clock Control Register, offset: 0x190 */
  __IO uint32_t PCC_FCSPI3                    ; /* FCSPI3 Clock Control Register, offset: 0x194 */
  __IO uint32_t PCC_FCIIC0                    ; /* FCIIC0 Clock Control Register, offset: 0x198 */
       uint8_t  RESERVED_14[4];
  __IO uint32_t PCC_FCUART0                   ; /* FCUART0 Clock Control Register, offset: 0x1A0 */
  __IO uint32_t PCC_FCUART1                   ; /* FCUART1 Clock Control Register, offset: 0x1A4 */
  __IO uint32_t PCC_FCUART2                   ; /* FCUART2 Clock Control Register, offset: 0x1A8 */
  __IO uint32_t PCC_FCUART3                   ; /* FCUART3 Clock Control Register, offset: 0x1AC */
       uint8_t  RESERVED_15[16];
  __IO uint32_t PCC_LU0                       ; /* LU0 Clock Control Register, offset: 0x1C0 */
  __IO uint32_t PCC_LU1                       ; /* LU1 Clock Control Register, offset: 0x1C4 */
       uint8_t  RESERVED_16[8];
  __IO uint32_t PCC_ENET                      ; /* ENET Clock Control Register, offset: 0x1D0 */
       uint8_t  RESERVED_17[12];
  __IO uint32_t PCC_FREQM                     ; /* FREQM Clock Control Register, offset: 0x1E0 */
       uint8_t  RESERVED_18[24];
  __IO uint32_t PCC_STCU                      ; /* STCU Clock Control Register, offset: 0x1FC */
  __IO uint32_t PCC_FLEXCAN0                  ; /* FLEXCAN0 Clock Control Register, offset: 0x200 */
       uint8_t  RESERVED_19[12];
  __IO uint32_t PCC_FLEXCAN1                  ; /* FLEXCAN1 Clock Control Register, offset: 0x210 */
       uint8_t  RESERVED_20[12];
  __IO uint32_t PCC_FLEXCAN2                  ; /* FLEXCAN2 Clock Control Register, offset: 0x220 */
       uint8_t  RESERVED_21[12];
  __IO uint32_t PCC_FLEXCAN3                  ; /* FLEXCAN3 Clock Control Register, offset: 0x230 */
       uint8_t  RESERVED_22[12];
  __IO uint32_t PCC_FLEXCAN4                  ; /* FLEXCAN4 Clock Control Register, offset: 0x240 */
       uint8_t  RESERVED_23[144];
  __IO uint32_t PCC_INTM1                     ; /* INTM1 Clock Control Register, offset: 0x2D4 */
       uint8_t  RESERVED_24[48];
  __IO uint32_t PCC_PTIMER2                   ; /* PTIMER2 Clock Control Register, offset: 0x308 */
  __IO uint32_t PCC_PTIMER3                   ; /* PTIMER3 Clock Control Register, offset: 0x30C */
       uint8_t  RESERVED_25[8];
  __IO uint32_t PCC_ADC2                      ; /* ADC2 Clock Control Register, offset: 0x318 */
  __IO uint32_t PCC_ADC3                      ; /* ADC3 Clock Control Register, offset: 0x31C */
       uint8_t  RESERVED_26[12];
  __IO uint32_t PCC_SDADC0                    ; /* SDADC0 Clock Control Register, offset: 0x32C */
       uint8_t  RESERVED_27[28];
  __IO uint32_t PCC_WDOG1                     ; /* WDOG1 Clock Control Register, offset: 0x34C */
       uint8_t  RESERVED_28[16];
  __IO uint32_t PCC_TSTMP2                    ; /* TSTMP2 Clock Control Register, offset: 0x360 */
       uint8_t  RESERVED_29[16];
  __IO uint32_t PCC_TRGSEL4                   ; /* TRGSEL4 Clock Control Register, offset: 0x374 */
  __IO uint32_t PCC_TRGSEL5                   ; /* TRGSEL5 Clock Control Register, offset: 0x378 */
  __IO uint32_t PCC_TRGSEL6                   ; /* TRGSEL6 Clock Control Register, offset: 0x37C */
  __IO uint32_t PCC_TRGSEL7                   ; /* TRGSEL7 Clock Control Register, offset: 0x380 */
  __IO uint32_t PCC_TRGSEL8                   ; /* TRGSEL8 Clock Control Register, offset: 0x384 */
       uint8_t  RESERVED_30[4];
  __IO uint32_t PCC_SSI0                      ; /* SSI0 Clock Control Register, offset: 0x38C */
  __IO uint32_t PCC_CRM0                      ; /* CRM0 Clock Control Register, offset: 0x390 */
  __IO uint32_t PCC_LDI0                      ; /* LDI0 Clock Control Register, offset: 0x394 */
       uint8_t  RESERVED_31[56];
  __IO uint32_t PCC_SENT1                     ; /* SENT1 Clock Control Register, offset: 0x3D0 */
       uint8_t  RESERVED_32[32];
  __IO uint32_t PCC_FTU4                      ; /* FTU4 Clock Control Register, offset: 0x3F4 */
  __IO uint32_t PCC_FTU5                      ; /* FTU5 Clock Control Register, offset: 0x3F8 */
  __IO uint32_t PCC_FTU6                      ; /* FTU6 Clock Control Register, offset: 0x3FC */
  __IO uint32_t PCC_FTU7                      ; /* FTU7 Clock Control Register, offset: 0x400 */
       uint8_t  RESERVED_33[24];
  __IO uint32_t PCC_FCIIC1                    ; /* FCIIC1 Clock Control Register, offset: 0x41C */
  __IO uint32_t PCC_FCUART4                   ; /* FCUART4 Clock Control Register, offset: 0x420 */
  __IO uint32_t PCC_FCUART5                   ; /* FCUART5 Clock Control Register, offset: 0x424 */
  __IO uint32_t PCC_FCUART6                   ; /* FCUART6 Clock Control Register, offset: 0x428 */
  __IO uint32_t PCC_FCUART7                   ; /* FCUART7 Clock Control Register, offset: 0x42C */
       uint8_t  RESERVED_34[16];
  __IO uint32_t PCC_FCSPI4                    ; /* FCSPI4 Clock Control Register, offset: 0x440 */
  __IO uint32_t PCC_FCSPI5                    ; /* FCSPI5 Clock Control Register, offset: 0x444 */
       uint8_t  RESERVED_35[8];
  __IO uint32_t PCC_MSC0                      ; /* MSC0 Clock Control Register, offset: 0x450 */
       uint8_t  RESERVED_36[4];
  __IO uint32_t PCC_EFTU0                     ; /* EFTU0 Clock Control Register, offset: 0x458 */
       uint8_t  RESERVED_37[36];
  __IO uint32_t PCC_FLEXCAN5                  ; /* FLEXCAN5 Clock Control Register, offset: 0x480 */
       uint8_t  RESERVED_38[12];
  __IO uint32_t PCC_FLEXCAN6                  ; /* FLEXCAN6 Clock Control Register, offset: 0x490 */
       uint8_t  RESERVED_39[12];
  __IO uint32_t PCC_FLEXCAN7                  ; /* FLEXCAN7 Clock Control Register, offset: 0x4A0 */

} PCC_Type, *PCC_MemMapPtr;


/* PCC - Peripheral instance base addresses */
/** Peripheral PCC base address */
#define PCC_BASE                                 (0x40024000u)
/** Peripheral PCC base pointer */
#define PCC                                      ((PCC_Type *)PCC_BASE)
// need fill by yourself
///** Number of interrupt vector arrays for the PCC module. */
//#define PCC_IRQS_ARR_COUNT                       (1u)
///** Number of interrupt channels for the PCC module. */
//#define PCC_IRQS_CH_COUNT                        (1u)
///** Interrupt vectors for the PCC peripheral type */
//#define PCC_IRQS                                 {PCC_IRQn}


/* ----------------------------------------------------------------------------
   -- PCC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PCC_Register_Masks PCC Register Masks
 * @{
 */

/* DMA0 Bit Fields */
#define PCC_DMA0_DWPLK_MASK            0x80000000u
#define PCC_DMA0_DWPLK_SHIFT           31u
#define PCC_DMA0_DWPLK_WIDTH           1u
#define PCC_DMA0_DWPLK(x)              (((uint32_t)(((uint32_t)(x))<<PCC_DMA0_DWPLK_SHIFT))&PCC_DMA0_DWPLK_MASK)
#define PCC_DMA0_DWP_MASK              0x70000000u
#define PCC_DMA0_DWP_SHIFT             28u
#define PCC_DMA0_DWP_WIDTH             3u
#define PCC_DMA0_DWP(x)                (((uint32_t)(((uint32_t)(x))<<PCC_DMA0_DWP_SHIFT))&PCC_DMA0_DWP_MASK)
#define PCC_DMA0_CGC_MASK              0x800000u
#define PCC_DMA0_CGC_SHIFT             23u
#define PCC_DMA0_CGC_WIDTH             1u
#define PCC_DMA0_CGC(x)                (((uint32_t)(((uint32_t)(x))<<PCC_DMA0_CGC_SHIFT))&PCC_DMA0_CGC_MASK)
#define PCC_DMA0_SWR_MASK              0x10000u
#define PCC_DMA0_SWR_SHIFT             16u
#define PCC_DMA0_SWR_WIDTH             1u
#define PCC_DMA0_SWR(x)                (((uint32_t)(((uint32_t)(x))<<PCC_DMA0_SWR_SHIFT))&PCC_DMA0_SWR_MASK)
/* DMA0 Reg Mask */
#define PCC_DMA0_MASK                  0xF0810000u

/* DMAMUX0 Bit Fields */
#define PCC_DMAMUX0_DWPLK_MASK         0x80000000u
#define PCC_DMAMUX0_DWPLK_SHIFT        31u
#define PCC_DMAMUX0_DWPLK_WIDTH        1u
#define PCC_DMAMUX0_DWPLK(x)           (((uint32_t)(((uint32_t)(x))<<PCC_DMAMUX0_DWPLK_SHIFT))&PCC_DMAMUX0_DWPLK_MASK)
#define PCC_DMAMUX0_DWP_MASK           0x70000000u
#define PCC_DMAMUX0_DWP_SHIFT          28u
#define PCC_DMAMUX0_DWP_WIDTH          3u
#define PCC_DMAMUX0_DWP(x)             (((uint32_t)(((uint32_t)(x))<<PCC_DMAMUX0_DWP_SHIFT))&PCC_DMAMUX0_DWP_MASK)
#define PCC_DMAMUX0_CGC_MASK           0x800000u
#define PCC_DMAMUX0_CGC_SHIFT          23u
#define PCC_DMAMUX0_CGC_WIDTH          1u
#define PCC_DMAMUX0_CGC(x)             (((uint32_t)(((uint32_t)(x))<<PCC_DMAMUX0_CGC_SHIFT))&PCC_DMAMUX0_CGC_MASK)
#define PCC_DMAMUX0_SWR_MASK           0x10000u
#define PCC_DMAMUX0_SWR_SHIFT          16u
#define PCC_DMAMUX0_SWR_WIDTH          1u
#define PCC_DMAMUX0_SWR(x)             (((uint32_t)(((uint32_t)(x))<<PCC_DMAMUX0_SWR_SHIFT))&PCC_DMAMUX0_SWR_MASK)
/* DMAMUX0 Reg Mask */
#define PCC_DMAMUX0_MASK               0xF0810000u

/* ROM Bit Fields */
#define PCC_ROM_DWPLK_MASK             0x80000000u
#define PCC_ROM_DWPLK_SHIFT            31u
#define PCC_ROM_DWPLK_WIDTH            1u
#define PCC_ROM_DWPLK(x)               (((uint32_t)(((uint32_t)(x))<<PCC_ROM_DWPLK_SHIFT))&PCC_ROM_DWPLK_MASK)
#define PCC_ROM_DWP_MASK               0x70000000u
#define PCC_ROM_DWP_SHIFT              28u
#define PCC_ROM_DWP_WIDTH              3u
#define PCC_ROM_DWP(x)                 (((uint32_t)(((uint32_t)(x))<<PCC_ROM_DWP_SHIFT))&PCC_ROM_DWP_MASK)
#define PCC_ROM_CGC_MASK               0x800000u
#define PCC_ROM_CGC_SHIFT              23u
#define PCC_ROM_CGC_WIDTH              1u
#define PCC_ROM_CGC(x)                 (((uint32_t)(((uint32_t)(x))<<PCC_ROM_CGC_SHIFT))&PCC_ROM_CGC_MASK)
/* ROM Reg Mask */
#define PCC_ROM_MASK                   0xF0800000u

/* ERM0 Bit Fields */
#define PCC_ERM0_DWPLK_MASK            0x80000000u
#define PCC_ERM0_DWPLK_SHIFT           31u
#define PCC_ERM0_DWPLK_WIDTH           1u
#define PCC_ERM0_DWPLK(x)              (((uint32_t)(((uint32_t)(x))<<PCC_ERM0_DWPLK_SHIFT))&PCC_ERM0_DWPLK_MASK)
#define PCC_ERM0_DWP_MASK              0x70000000u
#define PCC_ERM0_DWP_SHIFT             28u
#define PCC_ERM0_DWP_WIDTH             3u
#define PCC_ERM0_DWP(x)                (((uint32_t)(((uint32_t)(x))<<PCC_ERM0_DWP_SHIFT))&PCC_ERM0_DWP_MASK)
#define PCC_ERM0_CGC_MASK              0x800000u
#define PCC_ERM0_CGC_SHIFT             23u
#define PCC_ERM0_CGC_WIDTH             1u
#define PCC_ERM0_CGC(x)                (((uint32_t)(((uint32_t)(x))<<PCC_ERM0_CGC_SHIFT))&PCC_ERM0_CGC_MASK)
#define PCC_ERM0_SWR_MASK              0x10000u
#define PCC_ERM0_SWR_SHIFT             16u
#define PCC_ERM0_SWR_WIDTH             1u
#define PCC_ERM0_SWR(x)                (((uint32_t)(((uint32_t)(x))<<PCC_ERM0_SWR_SHIFT))&PCC_ERM0_SWR_MASK)
/* ERM0 Reg Mask */
#define PCC_ERM0_MASK                  0xF0810000u

/* EIM0 Bit Fields */
#define PCC_EIM0_DWPLK_MASK            0x80000000u
#define PCC_EIM0_DWPLK_SHIFT           31u
#define PCC_EIM0_DWPLK_WIDTH           1u
#define PCC_EIM0_DWPLK(x)              (((uint32_t)(((uint32_t)(x))<<PCC_EIM0_DWPLK_SHIFT))&PCC_EIM0_DWPLK_MASK)
#define PCC_EIM0_DWP_MASK              0x70000000u
#define PCC_EIM0_DWP_SHIFT             28u
#define PCC_EIM0_DWP_WIDTH             3u
#define PCC_EIM0_DWP(x)                (((uint32_t)(((uint32_t)(x))<<PCC_EIM0_DWP_SHIFT))&PCC_EIM0_DWP_MASK)
#define PCC_EIM0_CGC_MASK              0x800000u
#define PCC_EIM0_CGC_SHIFT             23u
#define PCC_EIM0_CGC_WIDTH             1u
#define PCC_EIM0_CGC(x)                (((uint32_t)(((uint32_t)(x))<<PCC_EIM0_CGC_SHIFT))&PCC_EIM0_CGC_MASK)
#define PCC_EIM0_SWR_MASK              0x10000u
#define PCC_EIM0_SWR_SHIFT             16u
#define PCC_EIM0_SWR_WIDTH             1u
#define PCC_EIM0_SWR(x)                (((uint32_t)(((uint32_t)(x))<<PCC_EIM0_SWR_SHIFT))&PCC_EIM0_SWR_MASK)
/* EIM0 Reg Mask */
#define PCC_EIM0_MASK                  0xF0810000u

/* INTM0 Bit Fields */
#define PCC_INTM0_DWPLK_MASK           0x80000000u
#define PCC_INTM0_DWPLK_SHIFT          31u
#define PCC_INTM0_DWPLK_WIDTH          1u
#define PCC_INTM0_DWPLK(x)             (((uint32_t)(((uint32_t)(x))<<PCC_INTM0_DWPLK_SHIFT))&PCC_INTM0_DWPLK_MASK)
#define PCC_INTM0_DWP_MASK             0x70000000u
#define PCC_INTM0_DWP_SHIFT            28u
#define PCC_INTM0_DWP_WIDTH            3u
#define PCC_INTM0_DWP(x)               (((uint32_t)(((uint32_t)(x))<<PCC_INTM0_DWP_SHIFT))&PCC_INTM0_DWP_MASK)
#define PCC_INTM0_CGC_MASK             0x800000u
#define PCC_INTM0_CGC_SHIFT            23u
#define PCC_INTM0_CGC_WIDTH            1u
#define PCC_INTM0_CGC(x)               (((uint32_t)(((uint32_t)(x))<<PCC_INTM0_CGC_SHIFT))&PCC_INTM0_CGC_MASK)
#define PCC_INTM0_SWR_MASK             0x10000u
#define PCC_INTM0_SWR_SHIFT            16u
#define PCC_INTM0_SWR_WIDTH            1u
#define PCC_INTM0_SWR(x)               (((uint32_t)(((uint32_t)(x))<<PCC_INTM0_SWR_SHIFT))&PCC_INTM0_SWR_MASK)
/* INTM0 Reg Mask */
#define PCC_INTM0_MASK                 0xF0810000u

/* ISM0 Bit Fields */
#define PCC_ISM0_DWPLK_MASK            0x80000000u
#define PCC_ISM0_DWPLK_SHIFT           31u
#define PCC_ISM0_DWPLK_WIDTH           1u
#define PCC_ISM0_DWPLK(x)              (((uint32_t)(((uint32_t)(x))<<PCC_ISM0_DWPLK_SHIFT))&PCC_ISM0_DWPLK_MASK)
#define PCC_ISM0_DWP_MASK              0x70000000u
#define PCC_ISM0_DWP_SHIFT             28u
#define PCC_ISM0_DWP_WIDTH             3u
#define PCC_ISM0_DWP(x)                (((uint32_t)(((uint32_t)(x))<<PCC_ISM0_DWP_SHIFT))&PCC_ISM0_DWP_MASK)
#define PCC_ISM0_CGC_MASK              0x800000u
#define PCC_ISM0_CGC_SHIFT             23u
#define PCC_ISM0_CGC_WIDTH             1u
#define PCC_ISM0_CGC(x)                (((uint32_t)(((uint32_t)(x))<<PCC_ISM0_CGC_SHIFT))&PCC_ISM0_CGC_MASK)
#define PCC_ISM0_SWR_MASK              0x10000u
#define PCC_ISM0_SWR_SHIFT             16u
#define PCC_ISM0_SWR_WIDTH             1u
#define PCC_ISM0_SWR(x)                (((uint32_t)(((uint32_t)(x))<<PCC_ISM0_SWR_SHIFT))&PCC_ISM0_SWR_MASK)
/* ISM0 Reg Mask */
#define PCC_ISM0_MASK                  0xF0810000u

/* WDOG0 Bit Fields */
#define PCC_WDOG0_DWPLK_MASK           0x80000000u
#define PCC_WDOG0_DWPLK_SHIFT          31u
#define PCC_WDOG0_DWPLK_WIDTH          1u
#define PCC_WDOG0_DWPLK(x)             (((uint32_t)(((uint32_t)(x))<<PCC_WDOG0_DWPLK_SHIFT))&PCC_WDOG0_DWPLK_MASK)
#define PCC_WDOG0_DWP_MASK             0x70000000u
#define PCC_WDOG0_DWP_SHIFT            28u
#define PCC_WDOG0_DWP_WIDTH            3u
#define PCC_WDOG0_DWP(x)               (((uint32_t)(((uint32_t)(x))<<PCC_WDOG0_DWP_SHIFT))&PCC_WDOG0_DWP_MASK)
/* WDOG0 Reg Mask */
#define PCC_WDOG0_MASK                 0xF0000000u

/* TRGSEL0 Bit Fields */
#define PCC_TRGSEL0_DWPLK_MASK         0x80000000u
#define PCC_TRGSEL0_DWPLK_SHIFT        31u
#define PCC_TRGSEL0_DWPLK_WIDTH        1u
#define PCC_TRGSEL0_DWPLK(x)           (((uint32_t)(((uint32_t)(x))<<PCC_TRGSEL0_DWPLK_SHIFT))&PCC_TRGSEL0_DWPLK_MASK)
#define PCC_TRGSEL0_DWP_MASK           0x70000000u
#define PCC_TRGSEL0_DWP_SHIFT          28u
#define PCC_TRGSEL0_DWP_WIDTH          3u
#define PCC_TRGSEL0_DWP(x)             (((uint32_t)(((uint32_t)(x))<<PCC_TRGSEL0_DWP_SHIFT))&PCC_TRGSEL0_DWP_MASK)
#define PCC_TRGSEL0_CGC_MASK           0x800000u
#define PCC_TRGSEL0_CGC_SHIFT          23u
#define PCC_TRGSEL0_CGC_WIDTH          1u
#define PCC_TRGSEL0_CGC(x)             (((uint32_t)(((uint32_t)(x))<<PCC_TRGSEL0_CGC_SHIFT))&PCC_TRGSEL0_CGC_MASK)
#define PCC_TRGSEL0_SWR_MASK           0x10000u
#define PCC_TRGSEL0_SWR_SHIFT          16u
#define PCC_TRGSEL0_SWR_WIDTH          1u
#define PCC_TRGSEL0_SWR(x)             (((uint32_t)(((uint32_t)(x))<<PCC_TRGSEL0_SWR_SHIFT))&PCC_TRGSEL0_SWR_MASK)
/* TRGSEL0 Reg Mask */
#define PCC_TRGSEL0_MASK               0xF0810000u

/* TRGSEL1 Bit Fields */
#define PCC_TRGSEL1_DWPLK_MASK         0x80000000u
#define PCC_TRGSEL1_DWPLK_SHIFT        31u
#define PCC_TRGSEL1_DWPLK_WIDTH        1u
#define PCC_TRGSEL1_DWPLK(x)           (((uint32_t)(((uint32_t)(x))<<PCC_TRGSEL1_DWPLK_SHIFT))&PCC_TRGSEL1_DWPLK_MASK)
#define PCC_TRGSEL1_DWP_MASK           0x70000000u
#define PCC_TRGSEL1_DWP_SHIFT          28u
#define PCC_TRGSEL1_DWP_WIDTH          3u
#define PCC_TRGSEL1_DWP(x)             (((uint32_t)(((uint32_t)(x))<<PCC_TRGSEL1_DWP_SHIFT))&PCC_TRGSEL1_DWP_MASK)
#define PCC_TRGSEL1_CGC_MASK           0x800000u
#define PCC_TRGSEL1_CGC_SHIFT          23u
#define PCC_TRGSEL1_CGC_WIDTH          1u
#define PCC_TRGSEL1_CGC(x)             (((uint32_t)(((uint32_t)(x))<<PCC_TRGSEL1_CGC_SHIFT))&PCC_TRGSEL1_CGC_MASK)
#define PCC_TRGSEL1_SWR_MASK           0x10000u
#define PCC_TRGSEL1_SWR_SHIFT          16u
#define PCC_TRGSEL1_SWR_WIDTH          1u
#define PCC_TRGSEL1_SWR(x)             (((uint32_t)(((uint32_t)(x))<<PCC_TRGSEL1_SWR_SHIFT))&PCC_TRGSEL1_SWR_MASK)
/* TRGSEL1 Reg Mask */
#define PCC_TRGSEL1_MASK               0xF0810000u

/* TRGSEL2 Bit Fields */
#define PCC_TRGSEL2_DWPLK_MASK         0x80000000u
#define PCC_TRGSEL2_DWPLK_SHIFT        31u
#define PCC_TRGSEL2_DWPLK_WIDTH        1u
#define PCC_TRGSEL2_DWPLK(x)           (((uint32_t)(((uint32_t)(x))<<PCC_TRGSEL2_DWPLK_SHIFT))&PCC_TRGSEL2_DWPLK_MASK)
#define PCC_TRGSEL2_DWP_MASK           0x70000000u
#define PCC_TRGSEL2_DWP_SHIFT          28u
#define PCC_TRGSEL2_DWP_WIDTH          3u
#define PCC_TRGSEL2_DWP(x)             (((uint32_t)(((uint32_t)(x))<<PCC_TRGSEL2_DWP_SHIFT))&PCC_TRGSEL2_DWP_MASK)
#define PCC_TRGSEL2_CGC_MASK           0x800000u
#define PCC_TRGSEL2_CGC_SHIFT          23u
#define PCC_TRGSEL2_CGC_WIDTH          1u
#define PCC_TRGSEL2_CGC(x)             (((uint32_t)(((uint32_t)(x))<<PCC_TRGSEL2_CGC_SHIFT))&PCC_TRGSEL2_CGC_MASK)
#define PCC_TRGSEL2_SWR_MASK           0x10000u
#define PCC_TRGSEL2_SWR_SHIFT          16u
#define PCC_TRGSEL2_SWR_WIDTH          1u
#define PCC_TRGSEL2_SWR(x)             (((uint32_t)(((uint32_t)(x))<<PCC_TRGSEL2_SWR_SHIFT))&PCC_TRGSEL2_SWR_MASK)
/* TRGSEL2 Reg Mask */
#define PCC_TRGSEL2_MASK               0xF0810000u

/* TRGSEL3 Bit Fields */
#define PCC_TRGSEL3_DWPLK_MASK         0x80000000u
#define PCC_TRGSEL3_DWPLK_SHIFT        31u
#define PCC_TRGSEL3_DWPLK_WIDTH        1u
#define PCC_TRGSEL3_DWPLK(x)           (((uint32_t)(((uint32_t)(x))<<PCC_TRGSEL3_DWPLK_SHIFT))&PCC_TRGSEL3_DWPLK_MASK)
#define PCC_TRGSEL3_DWP_MASK           0x70000000u
#define PCC_TRGSEL3_DWP_SHIFT          28u
#define PCC_TRGSEL3_DWP_WIDTH          3u
#define PCC_TRGSEL3_DWP(x)             (((uint32_t)(((uint32_t)(x))<<PCC_TRGSEL3_DWP_SHIFT))&PCC_TRGSEL3_DWP_MASK)
#define PCC_TRGSEL3_CGC_MASK           0x800000u
#define PCC_TRGSEL3_CGC_SHIFT          23u
#define PCC_TRGSEL3_CGC_WIDTH          1u
#define PCC_TRGSEL3_CGC(x)             (((uint32_t)(((uint32_t)(x))<<PCC_TRGSEL3_CGC_SHIFT))&PCC_TRGSEL3_CGC_MASK)
#define PCC_TRGSEL3_SWR_MASK           0x10000u
#define PCC_TRGSEL3_SWR_SHIFT          16u
#define PCC_TRGSEL3_SWR_WIDTH          1u
#define PCC_TRGSEL3_SWR(x)             (((uint32_t)(((uint32_t)(x))<<PCC_TRGSEL3_SWR_SHIFT))&PCC_TRGSEL3_SWR_MASK)
/* TRGSEL3 Reg Mask */
#define PCC_TRGSEL3_MASK               0xF0810000u

/* CRC0 Bit Fields */
#define PCC_CRC0_DWPLK_MASK            0x80000000u
#define PCC_CRC0_DWPLK_SHIFT           31u
#define PCC_CRC0_DWPLK_WIDTH           1u
#define PCC_CRC0_DWPLK(x)              (((uint32_t)(((uint32_t)(x))<<PCC_CRC0_DWPLK_SHIFT))&PCC_CRC0_DWPLK_MASK)
#define PCC_CRC0_DWP_MASK              0x70000000u
#define PCC_CRC0_DWP_SHIFT             28u
#define PCC_CRC0_DWP_WIDTH             3u
#define PCC_CRC0_DWP(x)                (((uint32_t)(((uint32_t)(x))<<PCC_CRC0_DWP_SHIFT))&PCC_CRC0_DWP_MASK)
#define PCC_CRC0_CGC_MASK              0x800000u
#define PCC_CRC0_CGC_SHIFT             23u
#define PCC_CRC0_CGC_WIDTH             1u
#define PCC_CRC0_CGC(x)                (((uint32_t)(((uint32_t)(x))<<PCC_CRC0_CGC_SHIFT))&PCC_CRC0_CGC_MASK)
#define PCC_CRC0_SWR_MASK              0x10000u
#define PCC_CRC0_SWR_SHIFT             16u
#define PCC_CRC0_SWR_WIDTH             1u
#define PCC_CRC0_SWR(x)                (((uint32_t)(((uint32_t)(x))<<PCC_CRC0_SWR_SHIFT))&PCC_CRC0_SWR_MASK)
/* CRC0 Reg Mask */
#define PCC_CRC0_MASK                  0xF0810000u

/* CORDIC Bit Fields */
#define PCC_CORDIC_DWPLK_MASK          0x80000000u
#define PCC_CORDIC_DWPLK_SHIFT         31u
#define PCC_CORDIC_DWPLK_WIDTH         1u
#define PCC_CORDIC_DWPLK(x)            (((uint32_t)(((uint32_t)(x))<<PCC_CORDIC_DWPLK_SHIFT))&PCC_CORDIC_DWPLK_MASK)
#define PCC_CORDIC_DWP_MASK            0x70000000u
#define PCC_CORDIC_DWP_SHIFT           28u
#define PCC_CORDIC_DWP_WIDTH           3u
#define PCC_CORDIC_DWP(x)              (((uint32_t)(((uint32_t)(x))<<PCC_CORDIC_DWP_SHIFT))&PCC_CORDIC_DWP_MASK)
#define PCC_CORDIC_CGC_MASK            0x800000u
#define PCC_CORDIC_CGC_SHIFT           23u
#define PCC_CORDIC_CGC_WIDTH           1u
#define PCC_CORDIC_CGC(x)              (((uint32_t)(((uint32_t)(x))<<PCC_CORDIC_CGC_SHIFT))&PCC_CORDIC_CGC_MASK)
#define PCC_CORDIC_SWR_MASK            0x10000u
#define PCC_CORDIC_SWR_SHIFT           16u
#define PCC_CORDIC_SWR_WIDTH           1u
#define PCC_CORDIC_SWR(x)              (((uint32_t)(((uint32_t)(x))<<PCC_CORDIC_SWR_SHIFT))&PCC_CORDIC_SWR_MASK)
/* CORDIC Reg Mask */
#define PCC_CORDIC_MASK                0xF0810000u

/* TSTMP0 Bit Fields */
#define PCC_TSTMP0_DWPLK_MASK          0x80000000u
#define PCC_TSTMP0_DWPLK_SHIFT         31u
#define PCC_TSTMP0_DWPLK_WIDTH         1u
#define PCC_TSTMP0_DWPLK(x)            (((uint32_t)(((uint32_t)(x))<<PCC_TSTMP0_DWPLK_SHIFT))&PCC_TSTMP0_DWPLK_MASK)
#define PCC_TSTMP0_DWP_MASK            0x70000000u
#define PCC_TSTMP0_DWP_SHIFT           28u
#define PCC_TSTMP0_DWP_WIDTH           3u
#define PCC_TSTMP0_DWP(x)              (((uint32_t)(((uint32_t)(x))<<PCC_TSTMP0_DWP_SHIFT))&PCC_TSTMP0_DWP_MASK)
#define PCC_TSTMP0_CGC_MASK            0x800000u
#define PCC_TSTMP0_CGC_SHIFT           23u
#define PCC_TSTMP0_CGC_WIDTH           1u
#define PCC_TSTMP0_CGC(x)              (((uint32_t)(((uint32_t)(x))<<PCC_TSTMP0_CGC_SHIFT))&PCC_TSTMP0_CGC_MASK)
/* TSTMP0 Reg Mask */
#define PCC_TSTMP0_MASK                0xF0800000u

/* TSTMP1 Bit Fields */
#define PCC_TSTMP1_DWPLK_MASK          0x80000000u
#define PCC_TSTMP1_DWPLK_SHIFT         31u
#define PCC_TSTMP1_DWPLK_WIDTH         1u
#define PCC_TSTMP1_DWPLK(x)            (((uint32_t)(((uint32_t)(x))<<PCC_TSTMP1_DWPLK_SHIFT))&PCC_TSTMP1_DWPLK_MASK)
#define PCC_TSTMP1_DWP_MASK            0x70000000u
#define PCC_TSTMP1_DWP_SHIFT           28u
#define PCC_TSTMP1_DWP_WIDTH           3u
#define PCC_TSTMP1_DWP(x)              (((uint32_t)(((uint32_t)(x))<<PCC_TSTMP1_DWP_SHIFT))&PCC_TSTMP1_DWP_MASK)
#define PCC_TSTMP1_CGC_MASK            0x800000u
#define PCC_TSTMP1_CGC_SHIFT           23u
#define PCC_TSTMP1_CGC_WIDTH           1u
#define PCC_TSTMP1_CGC(x)              (((uint32_t)(((uint32_t)(x))<<PCC_TSTMP1_CGC_SHIFT))&PCC_TSTMP1_CGC_MASK)
#define PCC_TSTMP1_SWR_MASK            0x10000u
#define PCC_TSTMP1_SWR_SHIFT           16u
#define PCC_TSTMP1_SWR_WIDTH           1u
#define PCC_TSTMP1_SWR(x)              (((uint32_t)(((uint32_t)(x))<<PCC_TSTMP1_SWR_SHIFT))&PCC_TSTMP1_SWR_MASK)
/* TSTMP1 Reg Mask */
#define PCC_TSTMP1_MASK                0xF0810000u

/* FCPIT0 Bit Fields */
#define PCC_FCPIT0_DWPLK_MASK          0x80000000u
#define PCC_FCPIT0_DWPLK_SHIFT         31u
#define PCC_FCPIT0_DWPLK_WIDTH         1u
#define PCC_FCPIT0_DWPLK(x)            (((uint32_t)(((uint32_t)(x))<<PCC_FCPIT0_DWPLK_SHIFT))&PCC_FCPIT0_DWPLK_MASK)
#define PCC_FCPIT0_DWP_MASK            0x70000000u
#define PCC_FCPIT0_DWP_SHIFT           28u
#define PCC_FCPIT0_DWP_WIDTH           3u
#define PCC_FCPIT0_DWP(x)              (((uint32_t)(((uint32_t)(x))<<PCC_FCPIT0_DWP_SHIFT))&PCC_FCPIT0_DWP_MASK)
#define PCC_FCPIT0_CGC_MASK            0x800000u
#define PCC_FCPIT0_CGC_SHIFT           23u
#define PCC_FCPIT0_CGC_WIDTH           1u
#define PCC_FCPIT0_CGC(x)              (((uint32_t)(((uint32_t)(x))<<PCC_FCPIT0_CGC_SHIFT))&PCC_FCPIT0_CGC_MASK)
#define PCC_FCPIT0_SEL_MASK            0x700000u
#define PCC_FCPIT0_SEL_SHIFT           20u
#define PCC_FCPIT0_SEL_WIDTH           3u
#define PCC_FCPIT0_SEL(x)              (((uint32_t)(((uint32_t)(x))<<PCC_FCPIT0_SEL_SHIFT))&PCC_FCPIT0_SEL_MASK)
#define PCC_FCPIT0_SWR_MASK            0x10000u
#define PCC_FCPIT0_SWR_SHIFT           16u
#define PCC_FCPIT0_SWR_WIDTH           1u
#define PCC_FCPIT0_SWR(x)              (((uint32_t)(((uint32_t)(x))<<PCC_FCPIT0_SWR_SHIFT))&PCC_FCPIT0_SWR_MASK)
/* FCPIT0 Reg Mask */
#define PCC_FCPIT0_MASK                0xF0F10000u

/* AONTIMER0 Bit Fields */
#define PCC_AONTIMER0_DWPLK_MASK       0x80000000u
#define PCC_AONTIMER0_DWPLK_SHIFT      31u
#define PCC_AONTIMER0_DWPLK_WIDTH      1u
#define PCC_AONTIMER0_DWPLK(x)         (((uint32_t)(((uint32_t)(x))<<PCC_AONTIMER0_DWPLK_SHIFT))&PCC_AONTIMER0_DWPLK_MASK)
#define PCC_AONTIMER0_DWP_MASK         0x70000000u
#define PCC_AONTIMER0_DWP_SHIFT        28u
#define PCC_AONTIMER0_DWP_WIDTH        3u
#define PCC_AONTIMER0_DWP(x)           (((uint32_t)(((uint32_t)(x))<<PCC_AONTIMER0_DWP_SHIFT))&PCC_AONTIMER0_DWP_MASK)
#define PCC_AONTIMER0_CGC_MASK         0x800000u
#define PCC_AONTIMER0_CGC_SHIFT        23u
#define PCC_AONTIMER0_CGC_WIDTH        1u
#define PCC_AONTIMER0_CGC(x)           (((uint32_t)(((uint32_t)(x))<<PCC_AONTIMER0_CGC_SHIFT))&PCC_AONTIMER0_CGC_MASK)
#define PCC_AONTIMER0_SEL_MASK         0x700000u
#define PCC_AONTIMER0_SEL_SHIFT        20u
#define PCC_AONTIMER0_SEL_WIDTH        3u
#define PCC_AONTIMER0_SEL(x)           (((uint32_t)(((uint32_t)(x))<<PCC_AONTIMER0_SEL_SHIFT))&PCC_AONTIMER0_SEL_MASK)
#define PCC_AONTIMER0_DIV_DIS_MASK     0x8000u
#define PCC_AONTIMER0_DIV_DIS_SHIFT    15u
#define PCC_AONTIMER0_DIV_DIS_WIDTH    1u
#define PCC_AONTIMER0_DIV_DIS(x)       (((uint32_t)(((uint32_t)(x))<<PCC_AONTIMER0_DIV_DIS_SHIFT))&PCC_AONTIMER0_DIV_DIS_MASK)
#define PCC_AONTIMER0_DIV_MASK         0x7u
#define PCC_AONTIMER0_DIV_SHIFT        0u
#define PCC_AONTIMER0_DIV_WIDTH        3u
#define PCC_AONTIMER0_DIV(x)           (((uint32_t)(((uint32_t)(x))<<PCC_AONTIMER0_DIV_SHIFT))&PCC_AONTIMER0_DIV_MASK)
/* AONTIMER0 Reg Mask */
#define PCC_AONTIMER0_MASK             0xF0F08007u

/* RTC Bit Fields */
#define PCC_RTC_DWPLK_MASK             0x80000000u
#define PCC_RTC_DWPLK_SHIFT            31u
#define PCC_RTC_DWPLK_WIDTH            1u
#define PCC_RTC_DWPLK(x)               (((uint32_t)(((uint32_t)(x))<<PCC_RTC_DWPLK_SHIFT))&PCC_RTC_DWPLK_MASK)
#define PCC_RTC_DWP_MASK               0x70000000u
#define PCC_RTC_DWP_SHIFT              28u
#define PCC_RTC_DWP_WIDTH              3u
#define PCC_RTC_DWP(x)                 (((uint32_t)(((uint32_t)(x))<<PCC_RTC_DWP_SHIFT))&PCC_RTC_DWP_MASK)
/* RTC Reg Mask */
#define PCC_RTC_MASK                   0xF0000000u

/* CMU0 Bit Fields */
#define PCC_CMU0_DWPLK_MASK            0x80000000u
#define PCC_CMU0_DWPLK_SHIFT           31u
#define PCC_CMU0_DWPLK_WIDTH           1u
#define PCC_CMU0_DWPLK(x)              (((uint32_t)(((uint32_t)(x))<<PCC_CMU0_DWPLK_SHIFT))&PCC_CMU0_DWPLK_MASK)
#define PCC_CMU0_DWP_MASK              0x70000000u
#define PCC_CMU0_DWP_SHIFT             28u
#define PCC_CMU0_DWP_WIDTH             3u
#define PCC_CMU0_DWP(x)                (((uint32_t)(((uint32_t)(x))<<PCC_CMU0_DWP_SHIFT))&PCC_CMU0_DWP_MASK)
#define PCC_CMU0_CGC_MASK              0x800000u
#define PCC_CMU0_CGC_SHIFT             23u
#define PCC_CMU0_CGC_WIDTH             1u
#define PCC_CMU0_CGC(x)                (((uint32_t)(((uint32_t)(x))<<PCC_CMU0_CGC_SHIFT))&PCC_CMU0_CGC_MASK)
#define PCC_CMU0_SWR_MASK              0x10000u
#define PCC_CMU0_SWR_SHIFT             16u
#define PCC_CMU0_SWR_WIDTH             1u
#define PCC_CMU0_SWR(x)                (((uint32_t)(((uint32_t)(x))<<PCC_CMU0_SWR_SHIFT))&PCC_CMU0_SWR_MASK)
/* CMU0 Reg Mask */
#define PCC_CMU0_MASK                  0xF0810000u

/* CMU1 Bit Fields */
#define PCC_CMU1_DWPLK_MASK            0x80000000u
#define PCC_CMU1_DWPLK_SHIFT           31u
#define PCC_CMU1_DWPLK_WIDTH           1u
#define PCC_CMU1_DWPLK(x)              (((uint32_t)(((uint32_t)(x))<<PCC_CMU1_DWPLK_SHIFT))&PCC_CMU1_DWPLK_MASK)
#define PCC_CMU1_DWP_MASK              0x70000000u
#define PCC_CMU1_DWP_SHIFT             28u
#define PCC_CMU1_DWP_WIDTH             3u
#define PCC_CMU1_DWP(x)                (((uint32_t)(((uint32_t)(x))<<PCC_CMU1_DWP_SHIFT))&PCC_CMU1_DWP_MASK)
#define PCC_CMU1_CGC_MASK              0x800000u
#define PCC_CMU1_CGC_SHIFT             23u
#define PCC_CMU1_CGC_WIDTH             1u
#define PCC_CMU1_CGC(x)                (((uint32_t)(((uint32_t)(x))<<PCC_CMU1_CGC_SHIFT))&PCC_CMU1_CGC_MASK)
#define PCC_CMU1_SWR_MASK              0x10000u
#define PCC_CMU1_SWR_SHIFT             16u
#define PCC_CMU1_SWR_WIDTH             1u
#define PCC_CMU1_SWR(x)                (((uint32_t)(((uint32_t)(x))<<PCC_CMU1_SWR_SHIFT))&PCC_CMU1_SWR_MASK)
/* CMU1 Reg Mask */
#define PCC_CMU1_MASK                  0xF0810000u

/* CMU2 Bit Fields */
#define PCC_CMU2_DWPLK_MASK            0x80000000u
#define PCC_CMU2_DWPLK_SHIFT           31u
#define PCC_CMU2_DWPLK_WIDTH           1u
#define PCC_CMU2_DWPLK(x)              (((uint32_t)(((uint32_t)(x))<<PCC_CMU2_DWPLK_SHIFT))&PCC_CMU2_DWPLK_MASK)
#define PCC_CMU2_DWP_MASK              0x70000000u
#define PCC_CMU2_DWP_SHIFT             28u
#define PCC_CMU2_DWP_WIDTH             3u
#define PCC_CMU2_DWP(x)                (((uint32_t)(((uint32_t)(x))<<PCC_CMU2_DWP_SHIFT))&PCC_CMU2_DWP_MASK)
#define PCC_CMU2_CGC_MASK              0x800000u
#define PCC_CMU2_CGC_SHIFT             23u
#define PCC_CMU2_CGC_WIDTH             1u
#define PCC_CMU2_CGC(x)                (((uint32_t)(((uint32_t)(x))<<PCC_CMU2_CGC_SHIFT))&PCC_CMU2_CGC_MASK)
#define PCC_CMU2_SWR_MASK              0x10000u
#define PCC_CMU2_SWR_SHIFT             16u
#define PCC_CMU2_SWR_WIDTH             1u
#define PCC_CMU2_SWR(x)                (((uint32_t)(((uint32_t)(x))<<PCC_CMU2_SWR_SHIFT))&PCC_CMU2_SWR_MASK)
/* CMU2 Reg Mask */
#define PCC_CMU2_MASK                  0xF0810000u

/* CMU3 Bit Fields */
#define PCC_CMU3_DWPLK_MASK            0x80000000u
#define PCC_CMU3_DWPLK_SHIFT           31u
#define PCC_CMU3_DWPLK_WIDTH           1u
#define PCC_CMU3_DWPLK(x)              (((uint32_t)(((uint32_t)(x))<<PCC_CMU3_DWPLK_SHIFT))&PCC_CMU3_DWPLK_MASK)
#define PCC_CMU3_DWP_MASK              0x70000000u
#define PCC_CMU3_DWP_SHIFT             28u
#define PCC_CMU3_DWP_WIDTH             3u
#define PCC_CMU3_DWP(x)                (((uint32_t)(((uint32_t)(x))<<PCC_CMU3_DWP_SHIFT))&PCC_CMU3_DWP_MASK)
#define PCC_CMU3_CGC_MASK              0x800000u
#define PCC_CMU3_CGC_SHIFT             23u
#define PCC_CMU3_CGC_WIDTH             1u
#define PCC_CMU3_CGC(x)                (((uint32_t)(((uint32_t)(x))<<PCC_CMU3_CGC_SHIFT))&PCC_CMU3_CGC_MASK)
#define PCC_CMU3_SWR_MASK              0x10000u
#define PCC_CMU3_SWR_SHIFT             16u
#define PCC_CMU3_SWR_WIDTH             1u
#define PCC_CMU3_SWR(x)                (((uint32_t)(((uint32_t)(x))<<PCC_CMU3_SWR_SHIFT))&PCC_CMU3_SWR_MASK)
/* CMU3 Reg Mask */
#define PCC_CMU3_MASK                  0xF0810000u

/* CMU4 Bit Fields */
#define PCC_CMU4_DWPLK_MASK            0x80000000u
#define PCC_CMU4_DWPLK_SHIFT           31u
#define PCC_CMU4_DWPLK_WIDTH           1u
#define PCC_CMU4_DWPLK(x)              (((uint32_t)(((uint32_t)(x))<<PCC_CMU4_DWPLK_SHIFT))&PCC_CMU4_DWPLK_MASK)
#define PCC_CMU4_DWP_MASK              0x70000000u
#define PCC_CMU4_DWP_SHIFT             28u
#define PCC_CMU4_DWP_WIDTH             3u
#define PCC_CMU4_DWP(x)                (((uint32_t)(((uint32_t)(x))<<PCC_CMU4_DWP_SHIFT))&PCC_CMU4_DWP_MASK)
#define PCC_CMU4_CGC_MASK              0x800000u
#define PCC_CMU4_CGC_SHIFT             23u
#define PCC_CMU4_CGC_WIDTH             1u
#define PCC_CMU4_CGC(x)                (((uint32_t)(((uint32_t)(x))<<PCC_CMU4_CGC_SHIFT))&PCC_CMU4_CGC_MASK)
#define PCC_CMU4_SWR_MASK              0x10000u
#define PCC_CMU4_SWR_SHIFT             16u
#define PCC_CMU4_SWR_WIDTH             1u
#define PCC_CMU4_SWR(x)                (((uint32_t)(((uint32_t)(x))<<PCC_CMU4_SWR_SHIFT))&PCC_CMU4_SWR_MASK)
/* CMU4 Reg Mask */
#define PCC_CMU4_MASK                  0xF0810000u

/* PTIMER0 Bit Fields */
#define PCC_PTIMER0_DWPLK_MASK         0x80000000u
#define PCC_PTIMER0_DWPLK_SHIFT        31u
#define PCC_PTIMER0_DWPLK_WIDTH        1u
#define PCC_PTIMER0_DWPLK(x)           (((uint32_t)(((uint32_t)(x))<<PCC_PTIMER0_DWPLK_SHIFT))&PCC_PTIMER0_DWPLK_MASK)
#define PCC_PTIMER0_DWP_MASK           0x70000000u
#define PCC_PTIMER0_DWP_SHIFT          28u
#define PCC_PTIMER0_DWP_WIDTH          3u
#define PCC_PTIMER0_DWP(x)             (((uint32_t)(((uint32_t)(x))<<PCC_PTIMER0_DWP_SHIFT))&PCC_PTIMER0_DWP_MASK)
#define PCC_PTIMER0_CGC_MASK           0x800000u
#define PCC_PTIMER0_CGC_SHIFT          23u
#define PCC_PTIMER0_CGC_WIDTH          1u
#define PCC_PTIMER0_CGC(x)             (((uint32_t)(((uint32_t)(x))<<PCC_PTIMER0_CGC_SHIFT))&PCC_PTIMER0_CGC_MASK)
#define PCC_PTIMER0_SWR_MASK           0x10000u
#define PCC_PTIMER0_SWR_SHIFT          16u
#define PCC_PTIMER0_SWR_WIDTH          1u
#define PCC_PTIMER0_SWR(x)             (((uint32_t)(((uint32_t)(x))<<PCC_PTIMER0_SWR_SHIFT))&PCC_PTIMER0_SWR_MASK)
/* PTIMER0 Reg Mask */
#define PCC_PTIMER0_MASK               0xF0810000u

/* PTIMER1 Bit Fields */
#define PCC_PTIMER1_DWPLK_MASK         0x80000000u
#define PCC_PTIMER1_DWPLK_SHIFT        31u
#define PCC_PTIMER1_DWPLK_WIDTH        1u
#define PCC_PTIMER1_DWPLK(x)           (((uint32_t)(((uint32_t)(x))<<PCC_PTIMER1_DWPLK_SHIFT))&PCC_PTIMER1_DWPLK_MASK)
#define PCC_PTIMER1_DWP_MASK           0x70000000u
#define PCC_PTIMER1_DWP_SHIFT          28u
#define PCC_PTIMER1_DWP_WIDTH          3u
#define PCC_PTIMER1_DWP(x)             (((uint32_t)(((uint32_t)(x))<<PCC_PTIMER1_DWP_SHIFT))&PCC_PTIMER1_DWP_MASK)
#define PCC_PTIMER1_CGC_MASK           0x800000u
#define PCC_PTIMER1_CGC_SHIFT          23u
#define PCC_PTIMER1_CGC_WIDTH          1u
#define PCC_PTIMER1_CGC(x)             (((uint32_t)(((uint32_t)(x))<<PCC_PTIMER1_CGC_SHIFT))&PCC_PTIMER1_CGC_MASK)
#define PCC_PTIMER1_SWR_MASK           0x10000u
#define PCC_PTIMER1_SWR_SHIFT          16u
#define PCC_PTIMER1_SWR_WIDTH          1u
#define PCC_PTIMER1_SWR(x)             (((uint32_t)(((uint32_t)(x))<<PCC_PTIMER1_SWR_SHIFT))&PCC_PTIMER1_SWR_MASK)
/* PTIMER1 Reg Mask */
#define PCC_PTIMER1_MASK               0xF0810000u

/* ADC0 Bit Fields */
#define PCC_ADC0_DWPLK_MASK            0x80000000u
#define PCC_ADC0_DWPLK_SHIFT           31u
#define PCC_ADC0_DWPLK_WIDTH           1u
#define PCC_ADC0_DWPLK(x)              (((uint32_t)(((uint32_t)(x))<<PCC_ADC0_DWPLK_SHIFT))&PCC_ADC0_DWPLK_MASK)
#define PCC_ADC0_DWP_MASK              0x70000000u
#define PCC_ADC0_DWP_SHIFT             28u
#define PCC_ADC0_DWP_WIDTH             3u
#define PCC_ADC0_DWP(x)                (((uint32_t)(((uint32_t)(x))<<PCC_ADC0_DWP_SHIFT))&PCC_ADC0_DWP_MASK)
#define PCC_ADC0_CGC_MASK              0x800000u
#define PCC_ADC0_CGC_SHIFT             23u
#define PCC_ADC0_CGC_WIDTH             1u
#define PCC_ADC0_CGC(x)                (((uint32_t)(((uint32_t)(x))<<PCC_ADC0_CGC_SHIFT))&PCC_ADC0_CGC_MASK)
#define PCC_ADC0_SEL_MASK              0x700000u
#define PCC_ADC0_SEL_SHIFT             20u
#define PCC_ADC0_SEL_WIDTH             3u
#define PCC_ADC0_SEL(x)                (((uint32_t)(((uint32_t)(x))<<PCC_ADC0_SEL_SHIFT))&PCC_ADC0_SEL_MASK)
#define PCC_ADC0_SWR_MASK              0x10000u
#define PCC_ADC0_SWR_SHIFT             16u
#define PCC_ADC0_SWR_WIDTH             1u
#define PCC_ADC0_SWR(x)                (((uint32_t)(((uint32_t)(x))<<PCC_ADC0_SWR_SHIFT))&PCC_ADC0_SWR_MASK)
#define PCC_ADC0_DIV_DIS_MASK          0x8000u
#define PCC_ADC0_DIV_DIS_SHIFT         15u
#define PCC_ADC0_DIV_DIS_WIDTH         1u
#define PCC_ADC0_DIV_DIS(x)            (((uint32_t)(((uint32_t)(x))<<PCC_ADC0_DIV_DIS_SHIFT))&PCC_ADC0_DIV_DIS_MASK)
#define PCC_ADC0_DIV_MASK              0x7u
#define PCC_ADC0_DIV_SHIFT             0u
#define PCC_ADC0_DIV_WIDTH             3u
#define PCC_ADC0_DIV(x)                (((uint32_t)(((uint32_t)(x))<<PCC_ADC0_DIV_SHIFT))&PCC_ADC0_DIV_MASK)
/* ADC0 Reg Mask */
#define PCC_ADC0_MASK                  0xF0F18007u

/* ADC1 Bit Fields */
#define PCC_ADC1_DWPLK_MASK            0x80000000u
#define PCC_ADC1_DWPLK_SHIFT           31u
#define PCC_ADC1_DWPLK_WIDTH           1u
#define PCC_ADC1_DWPLK(x)              (((uint32_t)(((uint32_t)(x))<<PCC_ADC1_DWPLK_SHIFT))&PCC_ADC1_DWPLK_MASK)
#define PCC_ADC1_DWP_MASK              0x70000000u
#define PCC_ADC1_DWP_SHIFT             28u
#define PCC_ADC1_DWP_WIDTH             3u
#define PCC_ADC1_DWP(x)                (((uint32_t)(((uint32_t)(x))<<PCC_ADC1_DWP_SHIFT))&PCC_ADC1_DWP_MASK)
#define PCC_ADC1_CGC_MASK              0x800000u
#define PCC_ADC1_CGC_SHIFT             23u
#define PCC_ADC1_CGC_WIDTH             1u
#define PCC_ADC1_CGC(x)                (((uint32_t)(((uint32_t)(x))<<PCC_ADC1_CGC_SHIFT))&PCC_ADC1_CGC_MASK)
#define PCC_ADC1_SEL_MASK              0x700000u
#define PCC_ADC1_SEL_SHIFT             20u
#define PCC_ADC1_SEL_WIDTH             3u
#define PCC_ADC1_SEL(x)                (((uint32_t)(((uint32_t)(x))<<PCC_ADC1_SEL_SHIFT))&PCC_ADC1_SEL_MASK)
#define PCC_ADC1_SWR_MASK              0x10000u
#define PCC_ADC1_SWR_SHIFT             16u
#define PCC_ADC1_SWR_WIDTH             1u
#define PCC_ADC1_SWR(x)                (((uint32_t)(((uint32_t)(x))<<PCC_ADC1_SWR_SHIFT))&PCC_ADC1_SWR_MASK)
#define PCC_ADC1_DIV_DIS_MASK          0x8000u
#define PCC_ADC1_DIV_DIS_SHIFT         15u
#define PCC_ADC1_DIV_DIS_WIDTH         1u
#define PCC_ADC1_DIV_DIS(x)            (((uint32_t)(((uint32_t)(x))<<PCC_ADC1_DIV_DIS_SHIFT))&PCC_ADC1_DIV_DIS_MASK)
#define PCC_ADC1_DIV_MASK              0x7u
#define PCC_ADC1_DIV_SHIFT             0u
#define PCC_ADC1_DIV_WIDTH             3u
#define PCC_ADC1_DIV(x)                (((uint32_t)(((uint32_t)(x))<<PCC_ADC1_DIV_SHIFT))&PCC_ADC1_DIV_MASK)
/* ADC1 Reg Mask */
#define PCC_ADC1_MASK                  0xF0F18007u

/* WKU0 Bit Fields */
#define PCC_WKU0_DWPLK_MASK            0x80000000u
#define PCC_WKU0_DWPLK_SHIFT           31u
#define PCC_WKU0_DWPLK_WIDTH           1u
#define PCC_WKU0_DWPLK(x)              (((uint32_t)(((uint32_t)(x))<<PCC_WKU0_DWPLK_SHIFT))&PCC_WKU0_DWPLK_MASK)
#define PCC_WKU0_DWP_MASK              0x70000000u
#define PCC_WKU0_DWP_SHIFT             28u
#define PCC_WKU0_DWP_WIDTH             3u
#define PCC_WKU0_DWP(x)                (((uint32_t)(((uint32_t)(x))<<PCC_WKU0_DWP_SHIFT))&PCC_WKU0_DWP_MASK)
#define PCC_WKU0_CGC_MASK              0x800000u
#define PCC_WKU0_CGC_SHIFT             23u
#define PCC_WKU0_CGC_WIDTH             1u
#define PCC_WKU0_CGC(x)                (((uint32_t)(((uint32_t)(x))<<PCC_WKU0_CGC_SHIFT))&PCC_WKU0_CGC_MASK)
/* WKU0 Reg Mask */
#define PCC_WKU0_MASK                  0xF0800000u

/* CMP0 Bit Fields */
#define PCC_CMP0_DWPLK_MASK            0x80000000u
#define PCC_CMP0_DWPLK_SHIFT           31u
#define PCC_CMP0_DWPLK_WIDTH           1u
#define PCC_CMP0_DWPLK(x)              (((uint32_t)(((uint32_t)(x))<<PCC_CMP0_DWPLK_SHIFT))&PCC_CMP0_DWPLK_MASK)
#define PCC_CMP0_DWP_MASK              0x70000000u
#define PCC_CMP0_DWP_SHIFT             28u
#define PCC_CMP0_DWP_WIDTH             3u
#define PCC_CMP0_DWP(x)                (((uint32_t)(((uint32_t)(x))<<PCC_CMP0_DWP_SHIFT))&PCC_CMP0_DWP_MASK)
#define PCC_CMP0_CGC_MASK              0x800000u
#define PCC_CMP0_CGC_SHIFT             23u
#define PCC_CMP0_CGC_WIDTH             1u
#define PCC_CMP0_CGC(x)                (((uint32_t)(((uint32_t)(x))<<PCC_CMP0_CGC_SHIFT))&PCC_CMP0_CGC_MASK)
#define PCC_CMP0_SWR_MASK              0x10000u
#define PCC_CMP0_SWR_SHIFT             16u
#define PCC_CMP0_SWR_WIDTH             1u
#define PCC_CMP0_SWR(x)                (((uint32_t)(((uint32_t)(x))<<PCC_CMP0_SWR_SHIFT))&PCC_CMP0_SWR_MASK)
/* CMP0 Reg Mask */
#define PCC_CMP0_MASK                  0xF0810000u

/* TMU0 Bit Fields */
#define PCC_TMU0_DWPLK_MASK            0x80000000u
#define PCC_TMU0_DWPLK_SHIFT           31u
#define PCC_TMU0_DWPLK_WIDTH           1u
#define PCC_TMU0_DWPLK(x)              (((uint32_t)(((uint32_t)(x))<<PCC_TMU0_DWPLK_SHIFT))&PCC_TMU0_DWPLK_MASK)
#define PCC_TMU0_DWP_MASK              0x70000000u
#define PCC_TMU0_DWP_SHIFT             28u
#define PCC_TMU0_DWP_WIDTH             3u
#define PCC_TMU0_DWP(x)                (((uint32_t)(((uint32_t)(x))<<PCC_TMU0_DWP_SHIFT))&PCC_TMU0_DWP_MASK)
#define PCC_TMU0_CGC_MASK              0x800000u
#define PCC_TMU0_CGC_SHIFT             23u
#define PCC_TMU0_CGC_WIDTH             1u
#define PCC_TMU0_CGC(x)                (((uint32_t)(((uint32_t)(x))<<PCC_TMU0_CGC_SHIFT))&PCC_TMU0_CGC_MASK)
#define PCC_TMU0_SWR_MASK              0x10000u
#define PCC_TMU0_SWR_SHIFT             16u
#define PCC_TMU0_SWR_WIDTH             1u
#define PCC_TMU0_SWR(x)                (((uint32_t)(((uint32_t)(x))<<PCC_TMU0_SWR_SHIFT))&PCC_TMU0_SWR_MASK)
/* TMU0 Reg Mask */
#define PCC_TMU0_MASK                  0xF0810000u

/* SENT0 Bit Fields */
#define PCC_SENT0_DWPLK_MASK           0x80000000u
#define PCC_SENT0_DWPLK_SHIFT          31u
#define PCC_SENT0_DWPLK_WIDTH          1u
#define PCC_SENT0_DWPLK(x)             (((uint32_t)(((uint32_t)(x))<<PCC_SENT0_DWPLK_SHIFT))&PCC_SENT0_DWPLK_MASK)
#define PCC_SENT0_DWP_MASK             0x70000000u
#define PCC_SENT0_DWP_SHIFT            28u
#define PCC_SENT0_DWP_WIDTH            3u
#define PCC_SENT0_DWP(x)               (((uint32_t)(((uint32_t)(x))<<PCC_SENT0_DWP_SHIFT))&PCC_SENT0_DWP_MASK)
#define PCC_SENT0_CGC_MASK             0x800000u
#define PCC_SENT0_CGC_SHIFT            23u
#define PCC_SENT0_CGC_WIDTH            1u
#define PCC_SENT0_CGC(x)               (((uint32_t)(((uint32_t)(x))<<PCC_SENT0_CGC_SHIFT))&PCC_SENT0_CGC_MASK)
#define PCC_SENT0_SEL_MASK             0x700000u
#define PCC_SENT0_SEL_SHIFT            20u
#define PCC_SENT0_SEL_WIDTH            3u
#define PCC_SENT0_SEL(x)               (((uint32_t)(((uint32_t)(x))<<PCC_SENT0_SEL_SHIFT))&PCC_SENT0_SEL_MASK)
#define PCC_SENT0_SWR_MASK             0x10000u
#define PCC_SENT0_SWR_SHIFT            16u
#define PCC_SENT0_SWR_WIDTH            1u
#define PCC_SENT0_SWR(x)               (((uint32_t)(((uint32_t)(x))<<PCC_SENT0_SWR_SHIFT))&PCC_SENT0_SWR_MASK)
#define PCC_SENT0_DIV_DIS_MASK         0x8000u
#define PCC_SENT0_DIV_DIS_SHIFT        15u
#define PCC_SENT0_DIV_DIS_WIDTH        1u
#define PCC_SENT0_DIV_DIS(x)           (((uint32_t)(((uint32_t)(x))<<PCC_SENT0_DIV_DIS_SHIFT))&PCC_SENT0_DIV_DIS_MASK)
#define PCC_SENT0_DIV_MASK             0x7u
#define PCC_SENT0_DIV_SHIFT            0u
#define PCC_SENT0_DIV_WIDTH            3u
#define PCC_SENT0_DIV(x)               (((uint32_t)(((uint32_t)(x))<<PCC_SENT0_DIV_SHIFT))&PCC_SENT0_DIV_MASK)
/* SENT0 Reg Mask */
#define PCC_SENT0_MASK                 0xF0F18007u

/* MB0 Bit Fields */
#define PCC_MB0_DWPLK_MASK             0x80000000u
#define PCC_MB0_DWPLK_SHIFT            31u
#define PCC_MB0_DWPLK_WIDTH            1u
#define PCC_MB0_DWPLK(x)               (((uint32_t)(((uint32_t)(x))<<PCC_MB0_DWPLK_SHIFT))&PCC_MB0_DWPLK_MASK)
#define PCC_MB0_DWP_MASK               0x70000000u
#define PCC_MB0_DWP_SHIFT              28u
#define PCC_MB0_DWP_WIDTH              3u
#define PCC_MB0_DWP(x)                 (((uint32_t)(((uint32_t)(x))<<PCC_MB0_DWP_SHIFT))&PCC_MB0_DWP_MASK)
/* MB0 Reg Mask */
#define PCC_MB0_MASK                   0xF0000000u

/* FTU0 Bit Fields */
#define PCC_FTU0_DWPLK_MASK            0x80000000u
#define PCC_FTU0_DWPLK_SHIFT           31u
#define PCC_FTU0_DWPLK_WIDTH           1u
#define PCC_FTU0_DWPLK(x)              (((uint32_t)(((uint32_t)(x))<<PCC_FTU0_DWPLK_SHIFT))&PCC_FTU0_DWPLK_MASK)
#define PCC_FTU0_DWP_MASK              0x70000000u
#define PCC_FTU0_DWP_SHIFT             28u
#define PCC_FTU0_DWP_WIDTH             3u
#define PCC_FTU0_DWP(x)                (((uint32_t)(((uint32_t)(x))<<PCC_FTU0_DWP_SHIFT))&PCC_FTU0_DWP_MASK)
#define PCC_FTU0_CGC_MASK              0x800000u
#define PCC_FTU0_CGC_SHIFT             23u
#define PCC_FTU0_CGC_WIDTH             1u
#define PCC_FTU0_CGC(x)                (((uint32_t)(((uint32_t)(x))<<PCC_FTU0_CGC_SHIFT))&PCC_FTU0_CGC_MASK)
#define PCC_FTU0_SEL_MASK              0x700000u
#define PCC_FTU0_SEL_SHIFT             20u
#define PCC_FTU0_SEL_WIDTH             3u
#define PCC_FTU0_SEL(x)                (((uint32_t)(((uint32_t)(x))<<PCC_FTU0_SEL_SHIFT))&PCC_FTU0_SEL_MASK)
#define PCC_FTU0_SWR_MASK              0x10000u
#define PCC_FTU0_SWR_SHIFT             16u
#define PCC_FTU0_SWR_WIDTH             1u
#define PCC_FTU0_SWR(x)                (((uint32_t)(((uint32_t)(x))<<PCC_FTU0_SWR_SHIFT))&PCC_FTU0_SWR_MASK)
/* FTU0 Reg Mask */
#define PCC_FTU0_MASK                  0xF0F10000u

/* FTU1 Bit Fields */
#define PCC_FTU1_DWPLK_MASK            0x80000000u
#define PCC_FTU1_DWPLK_SHIFT           31u
#define PCC_FTU1_DWPLK_WIDTH           1u
#define PCC_FTU1_DWPLK(x)              (((uint32_t)(((uint32_t)(x))<<PCC_FTU1_DWPLK_SHIFT))&PCC_FTU1_DWPLK_MASK)
#define PCC_FTU1_DWP_MASK              0x70000000u
#define PCC_FTU1_DWP_SHIFT             28u
#define PCC_FTU1_DWP_WIDTH             3u
#define PCC_FTU1_DWP(x)                (((uint32_t)(((uint32_t)(x))<<PCC_FTU1_DWP_SHIFT))&PCC_FTU1_DWP_MASK)
#define PCC_FTU1_CGC_MASK              0x800000u
#define PCC_FTU1_CGC_SHIFT             23u
#define PCC_FTU1_CGC_WIDTH             1u
#define PCC_FTU1_CGC(x)                (((uint32_t)(((uint32_t)(x))<<PCC_FTU1_CGC_SHIFT))&PCC_FTU1_CGC_MASK)
#define PCC_FTU1_SEL_MASK              0x700000u
#define PCC_FTU1_SEL_SHIFT             20u
#define PCC_FTU1_SEL_WIDTH             3u
#define PCC_FTU1_SEL(x)                (((uint32_t)(((uint32_t)(x))<<PCC_FTU1_SEL_SHIFT))&PCC_FTU1_SEL_MASK)
#define PCC_FTU1_SWR_MASK              0x10000u
#define PCC_FTU1_SWR_SHIFT             16u
#define PCC_FTU1_SWR_WIDTH             1u
#define PCC_FTU1_SWR(x)                (((uint32_t)(((uint32_t)(x))<<PCC_FTU1_SWR_SHIFT))&PCC_FTU1_SWR_MASK)
/* FTU1 Reg Mask */
#define PCC_FTU1_MASK                  0xF0F10000u

/* FTU2 Bit Fields */
#define PCC_FTU2_DWPLK_MASK            0x80000000u
#define PCC_FTU2_DWPLK_SHIFT           31u
#define PCC_FTU2_DWPLK_WIDTH           1u
#define PCC_FTU2_DWPLK(x)              (((uint32_t)(((uint32_t)(x))<<PCC_FTU2_DWPLK_SHIFT))&PCC_FTU2_DWPLK_MASK)
#define PCC_FTU2_DWP_MASK              0x70000000u
#define PCC_FTU2_DWP_SHIFT             28u
#define PCC_FTU2_DWP_WIDTH             3u
#define PCC_FTU2_DWP(x)                (((uint32_t)(((uint32_t)(x))<<PCC_FTU2_DWP_SHIFT))&PCC_FTU2_DWP_MASK)
#define PCC_FTU2_CGC_MASK              0x800000u
#define PCC_FTU2_CGC_SHIFT             23u
#define PCC_FTU2_CGC_WIDTH             1u
#define PCC_FTU2_CGC(x)                (((uint32_t)(((uint32_t)(x))<<PCC_FTU2_CGC_SHIFT))&PCC_FTU2_CGC_MASK)
#define PCC_FTU2_SEL_MASK              0x700000u
#define PCC_FTU2_SEL_SHIFT             20u
#define PCC_FTU2_SEL_WIDTH             3u
#define PCC_FTU2_SEL(x)                (((uint32_t)(((uint32_t)(x))<<PCC_FTU2_SEL_SHIFT))&PCC_FTU2_SEL_MASK)
#define PCC_FTU2_SWR_MASK              0x10000u
#define PCC_FTU2_SWR_SHIFT             16u
#define PCC_FTU2_SWR_WIDTH             1u
#define PCC_FTU2_SWR(x)                (((uint32_t)(((uint32_t)(x))<<PCC_FTU2_SWR_SHIFT))&PCC_FTU2_SWR_MASK)
/* FTU2 Reg Mask */
#define PCC_FTU2_MASK                  0xF0F10000u

/* FTU3 Bit Fields */
#define PCC_FTU3_DWPLK_MASK            0x80000000u
#define PCC_FTU3_DWPLK_SHIFT           31u
#define PCC_FTU3_DWPLK_WIDTH           1u
#define PCC_FTU3_DWPLK(x)              (((uint32_t)(((uint32_t)(x))<<PCC_FTU3_DWPLK_SHIFT))&PCC_FTU3_DWPLK_MASK)
#define PCC_FTU3_DWP_MASK              0x70000000u
#define PCC_FTU3_DWP_SHIFT             28u
#define PCC_FTU3_DWP_WIDTH             3u
#define PCC_FTU3_DWP(x)                (((uint32_t)(((uint32_t)(x))<<PCC_FTU3_DWP_SHIFT))&PCC_FTU3_DWP_MASK)
#define PCC_FTU3_CGC_MASK              0x800000u
#define PCC_FTU3_CGC_SHIFT             23u
#define PCC_FTU3_CGC_WIDTH             1u
#define PCC_FTU3_CGC(x)                (((uint32_t)(((uint32_t)(x))<<PCC_FTU3_CGC_SHIFT))&PCC_FTU3_CGC_MASK)
#define PCC_FTU3_SEL_MASK              0x700000u
#define PCC_FTU3_SEL_SHIFT             20u
#define PCC_FTU3_SEL_WIDTH             3u
#define PCC_FTU3_SEL(x)                (((uint32_t)(((uint32_t)(x))<<PCC_FTU3_SEL_SHIFT))&PCC_FTU3_SEL_MASK)
#define PCC_FTU3_SWR_MASK              0x10000u
#define PCC_FTU3_SWR_SHIFT             16u
#define PCC_FTU3_SWR_WIDTH             1u
#define PCC_FTU3_SWR(x)                (((uint32_t)(((uint32_t)(x))<<PCC_FTU3_SWR_SHIFT))&PCC_FTU3_SWR_MASK)
/* FTU3 Reg Mask */
#define PCC_FTU3_MASK                  0xF0F10000u

/* FCSPI0 Bit Fields */
#define PCC_FCSPI0_DWPLK_MASK          0x80000000u
#define PCC_FCSPI0_DWPLK_SHIFT         31u
#define PCC_FCSPI0_DWPLK_WIDTH         1u
#define PCC_FCSPI0_DWPLK(x)            (((uint32_t)(((uint32_t)(x))<<PCC_FCSPI0_DWPLK_SHIFT))&PCC_FCSPI0_DWPLK_MASK)
#define PCC_FCSPI0_DWP_MASK            0x70000000u
#define PCC_FCSPI0_DWP_SHIFT           28u
#define PCC_FCSPI0_DWP_WIDTH           3u
#define PCC_FCSPI0_DWP(x)              (((uint32_t)(((uint32_t)(x))<<PCC_FCSPI0_DWP_SHIFT))&PCC_FCSPI0_DWP_MASK)
#define PCC_FCSPI0_CGC_MASK            0x800000u
#define PCC_FCSPI0_CGC_SHIFT           23u
#define PCC_FCSPI0_CGC_WIDTH           1u
#define PCC_FCSPI0_CGC(x)              (((uint32_t)(((uint32_t)(x))<<PCC_FCSPI0_CGC_SHIFT))&PCC_FCSPI0_CGC_MASK)
#define PCC_FCSPI0_SEL_MASK            0x700000u
#define PCC_FCSPI0_SEL_SHIFT           20u
#define PCC_FCSPI0_SEL_WIDTH           3u
#define PCC_FCSPI0_SEL(x)              (((uint32_t)(((uint32_t)(x))<<PCC_FCSPI0_SEL_SHIFT))&PCC_FCSPI0_SEL_MASK)
#define PCC_FCSPI0_SWR_MASK            0x10000u
#define PCC_FCSPI0_SWR_SHIFT           16u
#define PCC_FCSPI0_SWR_WIDTH           1u
#define PCC_FCSPI0_SWR(x)              (((uint32_t)(((uint32_t)(x))<<PCC_FCSPI0_SWR_SHIFT))&PCC_FCSPI0_SWR_MASK)
/* FCSPI0 Reg Mask */
#define PCC_FCSPI0_MASK                0xF0F10000u

/* FCSPI1 Bit Fields */
#define PCC_FCSPI1_DWPLK_MASK          0x80000000u
#define PCC_FCSPI1_DWPLK_SHIFT         31u
#define PCC_FCSPI1_DWPLK_WIDTH         1u
#define PCC_FCSPI1_DWPLK(x)            (((uint32_t)(((uint32_t)(x))<<PCC_FCSPI1_DWPLK_SHIFT))&PCC_FCSPI1_DWPLK_MASK)
#define PCC_FCSPI1_DWP_MASK            0x70000000u
#define PCC_FCSPI1_DWP_SHIFT           28u
#define PCC_FCSPI1_DWP_WIDTH           3u
#define PCC_FCSPI1_DWP(x)              (((uint32_t)(((uint32_t)(x))<<PCC_FCSPI1_DWP_SHIFT))&PCC_FCSPI1_DWP_MASK)
#define PCC_FCSPI1_CGC_MASK            0x800000u
#define PCC_FCSPI1_CGC_SHIFT           23u
#define PCC_FCSPI1_CGC_WIDTH           1u
#define PCC_FCSPI1_CGC(x)              (((uint32_t)(((uint32_t)(x))<<PCC_FCSPI1_CGC_SHIFT))&PCC_FCSPI1_CGC_MASK)
#define PCC_FCSPI1_SEL_MASK            0x700000u
#define PCC_FCSPI1_SEL_SHIFT           20u
#define PCC_FCSPI1_SEL_WIDTH           3u
#define PCC_FCSPI1_SEL(x)              (((uint32_t)(((uint32_t)(x))<<PCC_FCSPI1_SEL_SHIFT))&PCC_FCSPI1_SEL_MASK)
#define PCC_FCSPI1_SWR_MASK            0x10000u
#define PCC_FCSPI1_SWR_SHIFT           16u
#define PCC_FCSPI1_SWR_WIDTH           1u
#define PCC_FCSPI1_SWR(x)              (((uint32_t)(((uint32_t)(x))<<PCC_FCSPI1_SWR_SHIFT))&PCC_FCSPI1_SWR_MASK)
/* FCSPI1 Reg Mask */
#define PCC_FCSPI1_MASK                0xF0F10000u

/* FCSPI2 Bit Fields */
#define PCC_FCSPI2_DWPLK_MASK          0x80000000u
#define PCC_FCSPI2_DWPLK_SHIFT         31u
#define PCC_FCSPI2_DWPLK_WIDTH         1u
#define PCC_FCSPI2_DWPLK(x)            (((uint32_t)(((uint32_t)(x))<<PCC_FCSPI2_DWPLK_SHIFT))&PCC_FCSPI2_DWPLK_MASK)
#define PCC_FCSPI2_DWP_MASK            0x70000000u
#define PCC_FCSPI2_DWP_SHIFT           28u
#define PCC_FCSPI2_DWP_WIDTH           3u
#define PCC_FCSPI2_DWP(x)              (((uint32_t)(((uint32_t)(x))<<PCC_FCSPI2_DWP_SHIFT))&PCC_FCSPI2_DWP_MASK)
#define PCC_FCSPI2_CGC_MASK            0x800000u
#define PCC_FCSPI2_CGC_SHIFT           23u
#define PCC_FCSPI2_CGC_WIDTH           1u
#define PCC_FCSPI2_CGC(x)              (((uint32_t)(((uint32_t)(x))<<PCC_FCSPI2_CGC_SHIFT))&PCC_FCSPI2_CGC_MASK)
#define PCC_FCSPI2_SEL_MASK            0x700000u
#define PCC_FCSPI2_SEL_SHIFT           20u
#define PCC_FCSPI2_SEL_WIDTH           3u
#define PCC_FCSPI2_SEL(x)              (((uint32_t)(((uint32_t)(x))<<PCC_FCSPI2_SEL_SHIFT))&PCC_FCSPI2_SEL_MASK)
#define PCC_FCSPI2_SWR_MASK            0x10000u
#define PCC_FCSPI2_SWR_SHIFT           16u
#define PCC_FCSPI2_SWR_WIDTH           1u
#define PCC_FCSPI2_SWR(x)              (((uint32_t)(((uint32_t)(x))<<PCC_FCSPI2_SWR_SHIFT))&PCC_FCSPI2_SWR_MASK)
/* FCSPI2 Reg Mask */
#define PCC_FCSPI2_MASK                0xF0F10000u

/* FCSPI3 Bit Fields */
#define PCC_FCSPI3_DWPLK_MASK          0x80000000u
#define PCC_FCSPI3_DWPLK_SHIFT         31u
#define PCC_FCSPI3_DWPLK_WIDTH         1u
#define PCC_FCSPI3_DWPLK(x)            (((uint32_t)(((uint32_t)(x))<<PCC_FCSPI3_DWPLK_SHIFT))&PCC_FCSPI3_DWPLK_MASK)
#define PCC_FCSPI3_DWP_MASK            0x70000000u
#define PCC_FCSPI3_DWP_SHIFT           28u
#define PCC_FCSPI3_DWP_WIDTH           3u
#define PCC_FCSPI3_DWP(x)              (((uint32_t)(((uint32_t)(x))<<PCC_FCSPI3_DWP_SHIFT))&PCC_FCSPI3_DWP_MASK)
#define PCC_FCSPI3_CGC_MASK            0x800000u
#define PCC_FCSPI3_CGC_SHIFT           23u
#define PCC_FCSPI3_CGC_WIDTH           1u
#define PCC_FCSPI3_CGC(x)              (((uint32_t)(((uint32_t)(x))<<PCC_FCSPI3_CGC_SHIFT))&PCC_FCSPI3_CGC_MASK)
#define PCC_FCSPI3_SEL_MASK            0x700000u
#define PCC_FCSPI3_SEL_SHIFT           20u
#define PCC_FCSPI3_SEL_WIDTH           3u
#define PCC_FCSPI3_SEL(x)              (((uint32_t)(((uint32_t)(x))<<PCC_FCSPI3_SEL_SHIFT))&PCC_FCSPI3_SEL_MASK)
#define PCC_FCSPI3_SWR_MASK            0x10000u
#define PCC_FCSPI3_SWR_SHIFT           16u
#define PCC_FCSPI3_SWR_WIDTH           1u
#define PCC_FCSPI3_SWR(x)              (((uint32_t)(((uint32_t)(x))<<PCC_FCSPI3_SWR_SHIFT))&PCC_FCSPI3_SWR_MASK)
/* FCSPI3 Reg Mask */
#define PCC_FCSPI3_MASK                0xF0F10000u

/* FCIIC0 Bit Fields */
#define PCC_FCIIC0_DWPLK_MASK          0x80000000u
#define PCC_FCIIC0_DWPLK_SHIFT         31u
#define PCC_FCIIC0_DWPLK_WIDTH         1u
#define PCC_FCIIC0_DWPLK(x)            (((uint32_t)(((uint32_t)(x))<<PCC_FCIIC0_DWPLK_SHIFT))&PCC_FCIIC0_DWPLK_MASK)
#define PCC_FCIIC0_DWP_MASK            0x70000000u
#define PCC_FCIIC0_DWP_SHIFT           28u
#define PCC_FCIIC0_DWP_WIDTH           3u
#define PCC_FCIIC0_DWP(x)              (((uint32_t)(((uint32_t)(x))<<PCC_FCIIC0_DWP_SHIFT))&PCC_FCIIC0_DWP_MASK)
#define PCC_FCIIC0_CGC_MASK            0x800000u
#define PCC_FCIIC0_CGC_SHIFT           23u
#define PCC_FCIIC0_CGC_WIDTH           1u
#define PCC_FCIIC0_CGC(x)              (((uint32_t)(((uint32_t)(x))<<PCC_FCIIC0_CGC_SHIFT))&PCC_FCIIC0_CGC_MASK)
#define PCC_FCIIC0_SEL_MASK            0x700000u
#define PCC_FCIIC0_SEL_SHIFT           20u
#define PCC_FCIIC0_SEL_WIDTH           3u
#define PCC_FCIIC0_SEL(x)              (((uint32_t)(((uint32_t)(x))<<PCC_FCIIC0_SEL_SHIFT))&PCC_FCIIC0_SEL_MASK)
#define PCC_FCIIC0_SWR_MASK            0x10000u
#define PCC_FCIIC0_SWR_SHIFT           16u
#define PCC_FCIIC0_SWR_WIDTH           1u
#define PCC_FCIIC0_SWR(x)              (((uint32_t)(((uint32_t)(x))<<PCC_FCIIC0_SWR_SHIFT))&PCC_FCIIC0_SWR_MASK)
/* FCIIC0 Reg Mask */
#define PCC_FCIIC0_MASK                0xF0F10000u

/* FCUART0 Bit Fields */
#define PCC_FCUART0_DWPLK_MASK         0x80000000u
#define PCC_FCUART0_DWPLK_SHIFT        31u
#define PCC_FCUART0_DWPLK_WIDTH        1u
#define PCC_FCUART0_DWPLK(x)           (((uint32_t)(((uint32_t)(x))<<PCC_FCUART0_DWPLK_SHIFT))&PCC_FCUART0_DWPLK_MASK)
#define PCC_FCUART0_DWP_MASK           0x70000000u
#define PCC_FCUART0_DWP_SHIFT          28u
#define PCC_FCUART0_DWP_WIDTH          3u
#define PCC_FCUART0_DWP(x)             (((uint32_t)(((uint32_t)(x))<<PCC_FCUART0_DWP_SHIFT))&PCC_FCUART0_DWP_MASK)
#define PCC_FCUART0_CGC_MASK           0x800000u
#define PCC_FCUART0_CGC_SHIFT          23u
#define PCC_FCUART0_CGC_WIDTH          1u
#define PCC_FCUART0_CGC(x)             (((uint32_t)(((uint32_t)(x))<<PCC_FCUART0_CGC_SHIFT))&PCC_FCUART0_CGC_MASK)
#define PCC_FCUART0_SEL_MASK           0x700000u
#define PCC_FCUART0_SEL_SHIFT          20u
#define PCC_FCUART0_SEL_WIDTH          3u
#define PCC_FCUART0_SEL(x)             (((uint32_t)(((uint32_t)(x))<<PCC_FCUART0_SEL_SHIFT))&PCC_FCUART0_SEL_MASK)
#define PCC_FCUART0_SWR_MASK           0x10000u
#define PCC_FCUART0_SWR_SHIFT          16u
#define PCC_FCUART0_SWR_WIDTH          1u
#define PCC_FCUART0_SWR(x)             (((uint32_t)(((uint32_t)(x))<<PCC_FCUART0_SWR_SHIFT))&PCC_FCUART0_SWR_MASK)
/* FCUART0 Reg Mask */
#define PCC_FCUART0_MASK               0xF0F10000u

/* FCUART1 Bit Fields */
#define PCC_FCUART1_DWPLK_MASK         0x80000000u
#define PCC_FCUART1_DWPLK_SHIFT        31u
#define PCC_FCUART1_DWPLK_WIDTH        1u
#define PCC_FCUART1_DWPLK(x)           (((uint32_t)(((uint32_t)(x))<<PCC_FCUART1_DWPLK_SHIFT))&PCC_FCUART1_DWPLK_MASK)
#define PCC_FCUART1_DWP_MASK           0x70000000u
#define PCC_FCUART1_DWP_SHIFT          28u
#define PCC_FCUART1_DWP_WIDTH          3u
#define PCC_FCUART1_DWP(x)             (((uint32_t)(((uint32_t)(x))<<PCC_FCUART1_DWP_SHIFT))&PCC_FCUART1_DWP_MASK)
#define PCC_FCUART1_CGC_MASK           0x800000u
#define PCC_FCUART1_CGC_SHIFT          23u
#define PCC_FCUART1_CGC_WIDTH          1u
#define PCC_FCUART1_CGC(x)             (((uint32_t)(((uint32_t)(x))<<PCC_FCUART1_CGC_SHIFT))&PCC_FCUART1_CGC_MASK)
#define PCC_FCUART1_SEL_MASK           0x700000u
#define PCC_FCUART1_SEL_SHIFT          20u
#define PCC_FCUART1_SEL_WIDTH          3u
#define PCC_FCUART1_SEL(x)             (((uint32_t)(((uint32_t)(x))<<PCC_FCUART1_SEL_SHIFT))&PCC_FCUART1_SEL_MASK)
#define PCC_FCUART1_SWR_MASK           0x10000u
#define PCC_FCUART1_SWR_SHIFT          16u
#define PCC_FCUART1_SWR_WIDTH          1u
#define PCC_FCUART1_SWR(x)             (((uint32_t)(((uint32_t)(x))<<PCC_FCUART1_SWR_SHIFT))&PCC_FCUART1_SWR_MASK)
/* FCUART1 Reg Mask */
#define PCC_FCUART1_MASK               0xF0F10000u

/* FCUART2 Bit Fields */
#define PCC_FCUART2_DWPLK_MASK         0x80000000u
#define PCC_FCUART2_DWPLK_SHIFT        31u
#define PCC_FCUART2_DWPLK_WIDTH        1u
#define PCC_FCUART2_DWPLK(x)           (((uint32_t)(((uint32_t)(x))<<PCC_FCUART2_DWPLK_SHIFT))&PCC_FCUART2_DWPLK_MASK)
#define PCC_FCUART2_DWP_MASK           0x70000000u
#define PCC_FCUART2_DWP_SHIFT          28u
#define PCC_FCUART2_DWP_WIDTH          3u
#define PCC_FCUART2_DWP(x)             (((uint32_t)(((uint32_t)(x))<<PCC_FCUART2_DWP_SHIFT))&PCC_FCUART2_DWP_MASK)
#define PCC_FCUART2_CGC_MASK           0x800000u
#define PCC_FCUART2_CGC_SHIFT          23u
#define PCC_FCUART2_CGC_WIDTH          1u
#define PCC_FCUART2_CGC(x)             (((uint32_t)(((uint32_t)(x))<<PCC_FCUART2_CGC_SHIFT))&PCC_FCUART2_CGC_MASK)
#define PCC_FCUART2_SEL_MASK           0x700000u
#define PCC_FCUART2_SEL_SHIFT          20u
#define PCC_FCUART2_SEL_WIDTH          3u
#define PCC_FCUART2_SEL(x)             (((uint32_t)(((uint32_t)(x))<<PCC_FCUART2_SEL_SHIFT))&PCC_FCUART2_SEL_MASK)
#define PCC_FCUART2_SWR_MASK           0x10000u
#define PCC_FCUART2_SWR_SHIFT          16u
#define PCC_FCUART2_SWR_WIDTH          1u
#define PCC_FCUART2_SWR(x)             (((uint32_t)(((uint32_t)(x))<<PCC_FCUART2_SWR_SHIFT))&PCC_FCUART2_SWR_MASK)
/* FCUART2 Reg Mask */
#define PCC_FCUART2_MASK               0xF0F10000u

/* FCUART3 Bit Fields */
#define PCC_FCUART3_DWPLK_MASK         0x80000000u
#define PCC_FCUART3_DWPLK_SHIFT        31u
#define PCC_FCUART3_DWPLK_WIDTH        1u
#define PCC_FCUART3_DWPLK(x)           (((uint32_t)(((uint32_t)(x))<<PCC_FCUART3_DWPLK_SHIFT))&PCC_FCUART3_DWPLK_MASK)
#define PCC_FCUART3_DWP_MASK           0x70000000u
#define PCC_FCUART3_DWP_SHIFT          28u
#define PCC_FCUART3_DWP_WIDTH          3u
#define PCC_FCUART3_DWP(x)             (((uint32_t)(((uint32_t)(x))<<PCC_FCUART3_DWP_SHIFT))&PCC_FCUART3_DWP_MASK)
#define PCC_FCUART3_CGC_MASK           0x800000u
#define PCC_FCUART3_CGC_SHIFT          23u
#define PCC_FCUART3_CGC_WIDTH          1u
#define PCC_FCUART3_CGC(x)             (((uint32_t)(((uint32_t)(x))<<PCC_FCUART3_CGC_SHIFT))&PCC_FCUART3_CGC_MASK)
#define PCC_FCUART3_SEL_MASK           0x700000u
#define PCC_FCUART3_SEL_SHIFT          20u
#define PCC_FCUART3_SEL_WIDTH          3u
#define PCC_FCUART3_SEL(x)             (((uint32_t)(((uint32_t)(x))<<PCC_FCUART3_SEL_SHIFT))&PCC_FCUART3_SEL_MASK)
#define PCC_FCUART3_SWR_MASK           0x10000u
#define PCC_FCUART3_SWR_SHIFT          16u
#define PCC_FCUART3_SWR_WIDTH          1u
#define PCC_FCUART3_SWR(x)             (((uint32_t)(((uint32_t)(x))<<PCC_FCUART3_SWR_SHIFT))&PCC_FCUART3_SWR_MASK)
/* FCUART3 Reg Mask */
#define PCC_FCUART3_MASK               0xF0F10000u

/* LU0 Bit Fields */
#define PCC_LU0_DWPLK_MASK             0x80000000u
#define PCC_LU0_DWPLK_SHIFT            31u
#define PCC_LU0_DWPLK_WIDTH            1u
#define PCC_LU0_DWPLK(x)               (((uint32_t)(((uint32_t)(x))<<PCC_LU0_DWPLK_SHIFT))&PCC_LU0_DWPLK_MASK)
#define PCC_LU0_DWP_MASK               0x70000000u
#define PCC_LU0_DWP_SHIFT              28u
#define PCC_LU0_DWP_WIDTH              3u
#define PCC_LU0_DWP(x)                 (((uint32_t)(((uint32_t)(x))<<PCC_LU0_DWP_SHIFT))&PCC_LU0_DWP_MASK)
#define PCC_LU0_CGC_MASK               0x800000u
#define PCC_LU0_CGC_SHIFT              23u
#define PCC_LU0_CGC_WIDTH              1u
#define PCC_LU0_CGC(x)                 (((uint32_t)(((uint32_t)(x))<<PCC_LU0_CGC_SHIFT))&PCC_LU0_CGC_MASK)
#define PCC_LU0_SWR_MASK               0x10000u
#define PCC_LU0_SWR_SHIFT              16u
#define PCC_LU0_SWR_WIDTH              1u
#define PCC_LU0_SWR(x)                 (((uint32_t)(((uint32_t)(x))<<PCC_LU0_SWR_SHIFT))&PCC_LU0_SWR_MASK)
/* LU0 Reg Mask */
#define PCC_LU0_MASK                   0xF0810000u

/* LU1 Bit Fields */
#define PCC_LU1_DWPLK_MASK             0x80000000u
#define PCC_LU1_DWPLK_SHIFT            31u
#define PCC_LU1_DWPLK_WIDTH            1u
#define PCC_LU1_DWPLK(x)               (((uint32_t)(((uint32_t)(x))<<PCC_LU1_DWPLK_SHIFT))&PCC_LU1_DWPLK_MASK)
#define PCC_LU1_DWP_MASK               0x70000000u
#define PCC_LU1_DWP_SHIFT              28u
#define PCC_LU1_DWP_WIDTH              3u
#define PCC_LU1_DWP(x)                 (((uint32_t)(((uint32_t)(x))<<PCC_LU1_DWP_SHIFT))&PCC_LU1_DWP_MASK)
#define PCC_LU1_CGC_MASK               0x800000u
#define PCC_LU1_CGC_SHIFT              23u
#define PCC_LU1_CGC_WIDTH              1u
#define PCC_LU1_CGC(x)                 (((uint32_t)(((uint32_t)(x))<<PCC_LU1_CGC_SHIFT))&PCC_LU1_CGC_MASK)
#define PCC_LU1_SWR_MASK               0x10000u
#define PCC_LU1_SWR_SHIFT              16u
#define PCC_LU1_SWR_WIDTH              1u
#define PCC_LU1_SWR(x)                 (((uint32_t)(((uint32_t)(x))<<PCC_LU1_SWR_SHIFT))&PCC_LU1_SWR_MASK)
/* LU1 Reg Mask */
#define PCC_LU1_MASK                   0xF0810000u

/* ENET Bit Fields */
#define PCC_ENET_DWPLK_MASK            0x80000000u
#define PCC_ENET_DWPLK_SHIFT           31u
#define PCC_ENET_DWPLK_WIDTH           1u
#define PCC_ENET_DWPLK(x)              (((uint32_t)(((uint32_t)(x))<<PCC_ENET_DWPLK_SHIFT))&PCC_ENET_DWPLK_MASK)
#define PCC_ENET_DWP_MASK              0x70000000u
#define PCC_ENET_DWP_SHIFT             28u
#define PCC_ENET_DWP_WIDTH             3u
#define PCC_ENET_DWP(x)                (((uint32_t)(((uint32_t)(x))<<PCC_ENET_DWP_SHIFT))&PCC_ENET_DWP_MASK)
#define PCC_ENET_CGC_MASK              0x800000u
#define PCC_ENET_CGC_SHIFT             23u
#define PCC_ENET_CGC_WIDTH             1u
#define PCC_ENET_CGC(x)                (((uint32_t)(((uint32_t)(x))<<PCC_ENET_CGC_SHIFT))&PCC_ENET_CGC_MASK)
#define PCC_ENET_SEL_MASK              0x700000u
#define PCC_ENET_SEL_SHIFT             20u
#define PCC_ENET_SEL_WIDTH             3u
#define PCC_ENET_SEL(x)                (((uint32_t)(((uint32_t)(x))<<PCC_ENET_SEL_SHIFT))&PCC_ENET_SEL_MASK)
#define PCC_ENET_SWR_MASK              0x10000u
#define PCC_ENET_SWR_SHIFT             16u
#define PCC_ENET_SWR_WIDTH             1u
#define PCC_ENET_SWR(x)                (((uint32_t)(((uint32_t)(x))<<PCC_ENET_SWR_SHIFT))&PCC_ENET_SWR_MASK)
#define PCC_ENET_DIV_DIS_MASK          0x8000u
#define PCC_ENET_DIV_DIS_SHIFT         15u
#define PCC_ENET_DIV_DIS_WIDTH         1u
#define PCC_ENET_DIV_DIS(x)            (((uint32_t)(((uint32_t)(x))<<PCC_ENET_DIV_DIS_SHIFT))&PCC_ENET_DIV_DIS_MASK)
#define PCC_ENET_DIV_MASK              0x7u
#define PCC_ENET_DIV_SHIFT             0u
#define PCC_ENET_DIV_WIDTH             3u
#define PCC_ENET_DIV(x)                (((uint32_t)(((uint32_t)(x))<<PCC_ENET_DIV_SHIFT))&PCC_ENET_DIV_MASK)
/* ENET Reg Mask */
#define PCC_ENET_MASK                  0xF0F18007u

/* FREQM Bit Fields */
#define PCC_FREQM_DWPLK_MASK           0x80000000u
#define PCC_FREQM_DWPLK_SHIFT          31u
#define PCC_FREQM_DWPLK_WIDTH          1u
#define PCC_FREQM_DWPLK(x)             (((uint32_t)(((uint32_t)(x))<<PCC_FREQM_DWPLK_SHIFT))&PCC_FREQM_DWPLK_MASK)
#define PCC_FREQM_DWP_MASK             0x70000000u
#define PCC_FREQM_DWP_SHIFT            28u
#define PCC_FREQM_DWP_WIDTH            3u
#define PCC_FREQM_DWP(x)               (((uint32_t)(((uint32_t)(x))<<PCC_FREQM_DWP_SHIFT))&PCC_FREQM_DWP_MASK)
#define PCC_FREQM_CGC_MASK             0x800000u
#define PCC_FREQM_CGC_SHIFT            23u
#define PCC_FREQM_CGC_WIDTH            1u
#define PCC_FREQM_CGC(x)               (((uint32_t)(((uint32_t)(x))<<PCC_FREQM_CGC_SHIFT))&PCC_FREQM_CGC_MASK)
#define PCC_FREQM_SWR_MASK             0x10000u
#define PCC_FREQM_SWR_SHIFT            16u
#define PCC_FREQM_SWR_WIDTH            1u
#define PCC_FREQM_SWR(x)               (((uint32_t)(((uint32_t)(x))<<PCC_FREQM_SWR_SHIFT))&PCC_FREQM_SWR_MASK)
/* FREQM Reg Mask */
#define PCC_FREQM_MASK                 0xF0810000u

/* STCU Bit Fields */
#define PCC_STCU_DWPLK_MASK            0x80000000u
#define PCC_STCU_DWPLK_SHIFT           31u
#define PCC_STCU_DWPLK_WIDTH           1u
#define PCC_STCU_DWPLK(x)              (((uint32_t)(((uint32_t)(x))<<PCC_STCU_DWPLK_SHIFT))&PCC_STCU_DWPLK_MASK)
#define PCC_STCU_DWP_MASK              0x70000000u
#define PCC_STCU_DWP_SHIFT             28u
#define PCC_STCU_DWP_WIDTH             3u
#define PCC_STCU_DWP(x)                (((uint32_t)(((uint32_t)(x))<<PCC_STCU_DWP_SHIFT))&PCC_STCU_DWP_MASK)
#define PCC_STCU_CGC_MASK              0x800000u
#define PCC_STCU_CGC_SHIFT             23u
#define PCC_STCU_CGC_WIDTH             1u
#define PCC_STCU_CGC(x)                (((uint32_t)(((uint32_t)(x))<<PCC_STCU_CGC_SHIFT))&PCC_STCU_CGC_MASK)
/* STCU Reg Mask */
#define PCC_STCU_MASK                  0xF0800000u

/* FLEXCAN0 Bit Fields */
#define PCC_FLEXCAN0_DWPLK_MASK        0x80000000u
#define PCC_FLEXCAN0_DWPLK_SHIFT       31u
#define PCC_FLEXCAN0_DWPLK_WIDTH       1u
#define PCC_FLEXCAN0_DWPLK(x)          (((uint32_t)(((uint32_t)(x))<<PCC_FLEXCAN0_DWPLK_SHIFT))&PCC_FLEXCAN0_DWPLK_MASK)
#define PCC_FLEXCAN0_DWP_MASK          0x70000000u
#define PCC_FLEXCAN0_DWP_SHIFT         28u
#define PCC_FLEXCAN0_DWP_WIDTH         3u
#define PCC_FLEXCAN0_DWP(x)            (((uint32_t)(((uint32_t)(x))<<PCC_FLEXCAN0_DWP_SHIFT))&PCC_FLEXCAN0_DWP_MASK)
#define PCC_FLEXCAN0_CGC_MASK          0x800000u
#define PCC_FLEXCAN0_CGC_SHIFT         23u
#define PCC_FLEXCAN0_CGC_WIDTH         1u
#define PCC_FLEXCAN0_CGC(x)            (((uint32_t)(((uint32_t)(x))<<PCC_FLEXCAN0_CGC_SHIFT))&PCC_FLEXCAN0_CGC_MASK)
#define PCC_FLEXCAN0_SEL_MASK          0x700000u
#define PCC_FLEXCAN0_SEL_SHIFT         20u
#define PCC_FLEXCAN0_SEL_WIDTH         3u
#define PCC_FLEXCAN0_SEL(x)            (((uint32_t)(((uint32_t)(x))<<PCC_FLEXCAN0_SEL_SHIFT))&PCC_FLEXCAN0_SEL_MASK)
#define PCC_FLEXCAN0_SWR_MASK          0x10000u
#define PCC_FLEXCAN0_SWR_SHIFT         16u
#define PCC_FLEXCAN0_SWR_WIDTH         1u
#define PCC_FLEXCAN0_SWR(x)            (((uint32_t)(((uint32_t)(x))<<PCC_FLEXCAN0_SWR_SHIFT))&PCC_FLEXCAN0_SWR_MASK)
#define PCC_FLEXCAN0_DIV_DIS_MASK      0x8000u
#define PCC_FLEXCAN0_DIV_DIS_SHIFT     15u
#define PCC_FLEXCAN0_DIV_DIS_WIDTH     1u
#define PCC_FLEXCAN0_DIV_DIS(x)        (((uint32_t)(((uint32_t)(x))<<PCC_FLEXCAN0_DIV_DIS_SHIFT))&PCC_FLEXCAN0_DIV_DIS_MASK)
#define PCC_FLEXCAN0_DIV_MASK          0x7u
#define PCC_FLEXCAN0_DIV_SHIFT         0u
#define PCC_FLEXCAN0_DIV_WIDTH         3u
#define PCC_FLEXCAN0_DIV(x)            (((uint32_t)(((uint32_t)(x))<<PCC_FLEXCAN0_DIV_SHIFT))&PCC_FLEXCAN0_DIV_MASK)
/* FLEXCAN0 Reg Mask */
#define PCC_FLEXCAN0_MASK              0xF0F18007u

/* FLEXCAN1 Bit Fields */
#define PCC_FLEXCAN1_DWPLK_MASK        0x80000000u
#define PCC_FLEXCAN1_DWPLK_SHIFT       31u
#define PCC_FLEXCAN1_DWPLK_WIDTH       1u
#define PCC_FLEXCAN1_DWPLK(x)          (((uint32_t)(((uint32_t)(x))<<PCC_FLEXCAN1_DWPLK_SHIFT))&PCC_FLEXCAN1_DWPLK_MASK)
#define PCC_FLEXCAN1_DWP_MASK          0x70000000u
#define PCC_FLEXCAN1_DWP_SHIFT         28u
#define PCC_FLEXCAN1_DWP_WIDTH         3u
#define PCC_FLEXCAN1_DWP(x)            (((uint32_t)(((uint32_t)(x))<<PCC_FLEXCAN1_DWP_SHIFT))&PCC_FLEXCAN1_DWP_MASK)
#define PCC_FLEXCAN1_CGC_MASK          0x800000u
#define PCC_FLEXCAN1_CGC_SHIFT         23u
#define PCC_FLEXCAN1_CGC_WIDTH         1u
#define PCC_FLEXCAN1_CGC(x)            (((uint32_t)(((uint32_t)(x))<<PCC_FLEXCAN1_CGC_SHIFT))&PCC_FLEXCAN1_CGC_MASK)
#define PCC_FLEXCAN1_SEL_MASK          0x700000u
#define PCC_FLEXCAN1_SEL_SHIFT         20u
#define PCC_FLEXCAN1_SEL_WIDTH         3u
#define PCC_FLEXCAN1_SEL(x)            (((uint32_t)(((uint32_t)(x))<<PCC_FLEXCAN1_SEL_SHIFT))&PCC_FLEXCAN1_SEL_MASK)
#define PCC_FLEXCAN1_SWR_MASK          0x10000u
#define PCC_FLEXCAN1_SWR_SHIFT         16u
#define PCC_FLEXCAN1_SWR_WIDTH         1u
#define PCC_FLEXCAN1_SWR(x)            (((uint32_t)(((uint32_t)(x))<<PCC_FLEXCAN1_SWR_SHIFT))&PCC_FLEXCAN1_SWR_MASK)
#define PCC_FLEXCAN1_DIV_DIS_MASK      0x8000u
#define PCC_FLEXCAN1_DIV_DIS_SHIFT     15u
#define PCC_FLEXCAN1_DIV_DIS_WIDTH     1u
#define PCC_FLEXCAN1_DIV_DIS(x)        (((uint32_t)(((uint32_t)(x))<<PCC_FLEXCAN1_DIV_DIS_SHIFT))&PCC_FLEXCAN1_DIV_DIS_MASK)
#define PCC_FLEXCAN1_DIV_MASK          0x7u
#define PCC_FLEXCAN1_DIV_SHIFT         0u
#define PCC_FLEXCAN1_DIV_WIDTH         3u
#define PCC_FLEXCAN1_DIV(x)            (((uint32_t)(((uint32_t)(x))<<PCC_FLEXCAN1_DIV_SHIFT))&PCC_FLEXCAN1_DIV_MASK)
/* FLEXCAN1 Reg Mask */
#define PCC_FLEXCAN1_MASK              0xF0F18007u

/* FLEXCAN2 Bit Fields */
#define PCC_FLEXCAN2_DWPLK_MASK        0x80000000u
#define PCC_FLEXCAN2_DWPLK_SHIFT       31u
#define PCC_FLEXCAN2_DWPLK_WIDTH       1u
#define PCC_FLEXCAN2_DWPLK(x)          (((uint32_t)(((uint32_t)(x))<<PCC_FLEXCAN2_DWPLK_SHIFT))&PCC_FLEXCAN2_DWPLK_MASK)
#define PCC_FLEXCAN2_DWP_MASK          0x70000000u
#define PCC_FLEXCAN2_DWP_SHIFT         28u
#define PCC_FLEXCAN2_DWP_WIDTH         3u
#define PCC_FLEXCAN2_DWP(x)            (((uint32_t)(((uint32_t)(x))<<PCC_FLEXCAN2_DWP_SHIFT))&PCC_FLEXCAN2_DWP_MASK)
#define PCC_FLEXCAN2_CGC_MASK          0x800000u
#define PCC_FLEXCAN2_CGC_SHIFT         23u
#define PCC_FLEXCAN2_CGC_WIDTH         1u
#define PCC_FLEXCAN2_CGC(x)            (((uint32_t)(((uint32_t)(x))<<PCC_FLEXCAN2_CGC_SHIFT))&PCC_FLEXCAN2_CGC_MASK)
#define PCC_FLEXCAN2_SEL_MASK          0x700000u
#define PCC_FLEXCAN2_SEL_SHIFT         20u
#define PCC_FLEXCAN2_SEL_WIDTH         3u
#define PCC_FLEXCAN2_SEL(x)            (((uint32_t)(((uint32_t)(x))<<PCC_FLEXCAN2_SEL_SHIFT))&PCC_FLEXCAN2_SEL_MASK)
#define PCC_FLEXCAN2_SWR_MASK          0x10000u
#define PCC_FLEXCAN2_SWR_SHIFT         16u
#define PCC_FLEXCAN2_SWR_WIDTH         1u
#define PCC_FLEXCAN2_SWR(x)            (((uint32_t)(((uint32_t)(x))<<PCC_FLEXCAN2_SWR_SHIFT))&PCC_FLEXCAN2_SWR_MASK)
#define PCC_FLEXCAN2_DIV_DIS_MASK      0x8000u
#define PCC_FLEXCAN2_DIV_DIS_SHIFT     15u
#define PCC_FLEXCAN2_DIV_DIS_WIDTH     1u
#define PCC_FLEXCAN2_DIV_DIS(x)        (((uint32_t)(((uint32_t)(x))<<PCC_FLEXCAN2_DIV_DIS_SHIFT))&PCC_FLEXCAN2_DIV_DIS_MASK)
#define PCC_FLEXCAN2_DIV_MASK          0x7u
#define PCC_FLEXCAN2_DIV_SHIFT         0u
#define PCC_FLEXCAN2_DIV_WIDTH         3u
#define PCC_FLEXCAN2_DIV(x)            (((uint32_t)(((uint32_t)(x))<<PCC_FLEXCAN2_DIV_SHIFT))&PCC_FLEXCAN2_DIV_MASK)
/* FLEXCAN2 Reg Mask */
#define PCC_FLEXCAN2_MASK              0xF0F18007u

/* FLEXCAN3 Bit Fields */
#define PCC_FLEXCAN3_DWPLK_MASK        0x80000000u
#define PCC_FLEXCAN3_DWPLK_SHIFT       31u
#define PCC_FLEXCAN3_DWPLK_WIDTH       1u
#define PCC_FLEXCAN3_DWPLK(x)          (((uint32_t)(((uint32_t)(x))<<PCC_FLEXCAN3_DWPLK_SHIFT))&PCC_FLEXCAN3_DWPLK_MASK)
#define PCC_FLEXCAN3_DWP_MASK          0x70000000u
#define PCC_FLEXCAN3_DWP_SHIFT         28u
#define PCC_FLEXCAN3_DWP_WIDTH         3u
#define PCC_FLEXCAN3_DWP(x)            (((uint32_t)(((uint32_t)(x))<<PCC_FLEXCAN3_DWP_SHIFT))&PCC_FLEXCAN3_DWP_MASK)
#define PCC_FLEXCAN3_CGC_MASK          0x800000u
#define PCC_FLEXCAN3_CGC_SHIFT         23u
#define PCC_FLEXCAN3_CGC_WIDTH         1u
#define PCC_FLEXCAN3_CGC(x)            (((uint32_t)(((uint32_t)(x))<<PCC_FLEXCAN3_CGC_SHIFT))&PCC_FLEXCAN3_CGC_MASK)
#define PCC_FLEXCAN3_SEL_MASK          0x700000u
#define PCC_FLEXCAN3_SEL_SHIFT         20u
#define PCC_FLEXCAN3_SEL_WIDTH         3u
#define PCC_FLEXCAN3_SEL(x)            (((uint32_t)(((uint32_t)(x))<<PCC_FLEXCAN3_SEL_SHIFT))&PCC_FLEXCAN3_SEL_MASK)
#define PCC_FLEXCAN3_SWR_MASK          0x10000u
#define PCC_FLEXCAN3_SWR_SHIFT         16u
#define PCC_FLEXCAN3_SWR_WIDTH         1u
#define PCC_FLEXCAN3_SWR(x)            (((uint32_t)(((uint32_t)(x))<<PCC_FLEXCAN3_SWR_SHIFT))&PCC_FLEXCAN3_SWR_MASK)
#define PCC_FLEXCAN3_DIV_DIS_MASK      0x8000u
#define PCC_FLEXCAN3_DIV_DIS_SHIFT     15u
#define PCC_FLEXCAN3_DIV_DIS_WIDTH     1u
#define PCC_FLEXCAN3_DIV_DIS(x)        (((uint32_t)(((uint32_t)(x))<<PCC_FLEXCAN3_DIV_DIS_SHIFT))&PCC_FLEXCAN3_DIV_DIS_MASK)
#define PCC_FLEXCAN3_DIV_MASK          0x7u
#define PCC_FLEXCAN3_DIV_SHIFT         0u
#define PCC_FLEXCAN3_DIV_WIDTH         3u
#define PCC_FLEXCAN3_DIV(x)            (((uint32_t)(((uint32_t)(x))<<PCC_FLEXCAN3_DIV_SHIFT))&PCC_FLEXCAN3_DIV_MASK)
/* FLEXCAN3 Reg Mask */
#define PCC_FLEXCAN3_MASK              0xF0F18007u

/* FLEXCAN4 Bit Fields */
#define PCC_FLEXCAN4_DWPLK_MASK        0x80000000u
#define PCC_FLEXCAN4_DWPLK_SHIFT       31u
#define PCC_FLEXCAN4_DWPLK_WIDTH       1u
#define PCC_FLEXCAN4_DWPLK(x)          (((uint32_t)(((uint32_t)(x))<<PCC_FLEXCAN4_DWPLK_SHIFT))&PCC_FLEXCAN4_DWPLK_MASK)
#define PCC_FLEXCAN4_DWP_MASK          0x70000000u
#define PCC_FLEXCAN4_DWP_SHIFT         28u
#define PCC_FLEXCAN4_DWP_WIDTH         3u
#define PCC_FLEXCAN4_DWP(x)            (((uint32_t)(((uint32_t)(x))<<PCC_FLEXCAN4_DWP_SHIFT))&PCC_FLEXCAN4_DWP_MASK)
#define PCC_FLEXCAN4_CGC_MASK          0x800000u
#define PCC_FLEXCAN4_CGC_SHIFT         23u
#define PCC_FLEXCAN4_CGC_WIDTH         1u
#define PCC_FLEXCAN4_CGC(x)            (((uint32_t)(((uint32_t)(x))<<PCC_FLEXCAN4_CGC_SHIFT))&PCC_FLEXCAN4_CGC_MASK)
#define PCC_FLEXCAN4_SEL_MASK          0x700000u
#define PCC_FLEXCAN4_SEL_SHIFT         20u
#define PCC_FLEXCAN4_SEL_WIDTH         3u
#define PCC_FLEXCAN4_SEL(x)            (((uint32_t)(((uint32_t)(x))<<PCC_FLEXCAN4_SEL_SHIFT))&PCC_FLEXCAN4_SEL_MASK)
#define PCC_FLEXCAN4_SWR_MASK          0x10000u
#define PCC_FLEXCAN4_SWR_SHIFT         16u
#define PCC_FLEXCAN4_SWR_WIDTH         1u
#define PCC_FLEXCAN4_SWR(x)            (((uint32_t)(((uint32_t)(x))<<PCC_FLEXCAN4_SWR_SHIFT))&PCC_FLEXCAN4_SWR_MASK)
#define PCC_FLEXCAN4_DIV_DIS_MASK      0x8000u
#define PCC_FLEXCAN4_DIV_DIS_SHIFT     15u
#define PCC_FLEXCAN4_DIV_DIS_WIDTH     1u
#define PCC_FLEXCAN4_DIV_DIS(x)        (((uint32_t)(((uint32_t)(x))<<PCC_FLEXCAN4_DIV_DIS_SHIFT))&PCC_FLEXCAN4_DIV_DIS_MASK)
#define PCC_FLEXCAN4_DIV_MASK          0x7u
#define PCC_FLEXCAN4_DIV_SHIFT         0u
#define PCC_FLEXCAN4_DIV_WIDTH         3u
#define PCC_FLEXCAN4_DIV(x)            (((uint32_t)(((uint32_t)(x))<<PCC_FLEXCAN4_DIV_SHIFT))&PCC_FLEXCAN4_DIV_MASK)
/* FLEXCAN4 Reg Mask */
#define PCC_FLEXCAN4_MASK              0xF0F18007u

/* INTM1 Bit Fields */
#define PCC_INTM1_DWPLK_MASK           0x80000000u
#define PCC_INTM1_DWPLK_SHIFT          31u
#define PCC_INTM1_DWPLK_WIDTH          1u
#define PCC_INTM1_DWPLK(x)             (((uint32_t)(((uint32_t)(x))<<PCC_INTM1_DWPLK_SHIFT))&PCC_INTM1_DWPLK_MASK)
#define PCC_INTM1_DWP_MASK             0x70000000u
#define PCC_INTM1_DWP_SHIFT            28u
#define PCC_INTM1_DWP_WIDTH            3u
#define PCC_INTM1_DWP(x)               (((uint32_t)(((uint32_t)(x))<<PCC_INTM1_DWP_SHIFT))&PCC_INTM1_DWP_MASK)
#define PCC_INTM1_CGC_MASK             0x800000u
#define PCC_INTM1_CGC_SHIFT            23u
#define PCC_INTM1_CGC_WIDTH            1u
#define PCC_INTM1_CGC(x)               (((uint32_t)(((uint32_t)(x))<<PCC_INTM1_CGC_SHIFT))&PCC_INTM1_CGC_MASK)
#define PCC_INTM1_SWR_MASK             0x10000u
#define PCC_INTM1_SWR_SHIFT            16u
#define PCC_INTM1_SWR_WIDTH            1u
#define PCC_INTM1_SWR(x)               (((uint32_t)(((uint32_t)(x))<<PCC_INTM1_SWR_SHIFT))&PCC_INTM1_SWR_MASK)
/* INTM1 Reg Mask */
#define PCC_INTM1_MASK                 0xF0810000u

/* PTIMER2 Bit Fields */
#define PCC_PTIMER2_DWPLK_MASK         0x80000000u
#define PCC_PTIMER2_DWPLK_SHIFT        31u
#define PCC_PTIMER2_DWPLK_WIDTH        1u
#define PCC_PTIMER2_DWPLK(x)           (((uint32_t)(((uint32_t)(x))<<PCC_PTIMER2_DWPLK_SHIFT))&PCC_PTIMER2_DWPLK_MASK)
#define PCC_PTIMER2_DWP_MASK           0x70000000u
#define PCC_PTIMER2_DWP_SHIFT          28u
#define PCC_PTIMER2_DWP_WIDTH          3u
#define PCC_PTIMER2_DWP(x)             (((uint32_t)(((uint32_t)(x))<<PCC_PTIMER2_DWP_SHIFT))&PCC_PTIMER2_DWP_MASK)
#define PCC_PTIMER2_CGC_MASK           0x800000u
#define PCC_PTIMER2_CGC_SHIFT          23u
#define PCC_PTIMER2_CGC_WIDTH          1u
#define PCC_PTIMER2_CGC(x)             (((uint32_t)(((uint32_t)(x))<<PCC_PTIMER2_CGC_SHIFT))&PCC_PTIMER2_CGC_MASK)
#define PCC_PTIMER2_SWR_MASK           0x10000u
#define PCC_PTIMER2_SWR_SHIFT          16u
#define PCC_PTIMER2_SWR_WIDTH          1u
#define PCC_PTIMER2_SWR(x)             (((uint32_t)(((uint32_t)(x))<<PCC_PTIMER2_SWR_SHIFT))&PCC_PTIMER2_SWR_MASK)
/* PTIMER2 Reg Mask */
#define PCC_PTIMER2_MASK               0xF0810000u

/* PTIMER3 Bit Fields */
#define PCC_PTIMER3_DWPLK_MASK         0x80000000u
#define PCC_PTIMER3_DWPLK_SHIFT        31u
#define PCC_PTIMER3_DWPLK_WIDTH        1u
#define PCC_PTIMER3_DWPLK(x)           (((uint32_t)(((uint32_t)(x))<<PCC_PTIMER3_DWPLK_SHIFT))&PCC_PTIMER3_DWPLK_MASK)
#define PCC_PTIMER3_DWP_MASK           0x70000000u
#define PCC_PTIMER3_DWP_SHIFT          28u
#define PCC_PTIMER3_DWP_WIDTH          3u
#define PCC_PTIMER3_DWP(x)             (((uint32_t)(((uint32_t)(x))<<PCC_PTIMER3_DWP_SHIFT))&PCC_PTIMER3_DWP_MASK)
#define PCC_PTIMER3_CGC_MASK           0x800000u
#define PCC_PTIMER3_CGC_SHIFT          23u
#define PCC_PTIMER3_CGC_WIDTH          1u
#define PCC_PTIMER3_CGC(x)             (((uint32_t)(((uint32_t)(x))<<PCC_PTIMER3_CGC_SHIFT))&PCC_PTIMER3_CGC_MASK)
#define PCC_PTIMER3_SWR_MASK           0x10000u
#define PCC_PTIMER3_SWR_SHIFT          16u
#define PCC_PTIMER3_SWR_WIDTH          1u
#define PCC_PTIMER3_SWR(x)             (((uint32_t)(((uint32_t)(x))<<PCC_PTIMER3_SWR_SHIFT))&PCC_PTIMER3_SWR_MASK)
/* PTIMER3 Reg Mask */
#define PCC_PTIMER3_MASK               0xF0810000u

/* ADC2 Bit Fields */
#define PCC_ADC2_DWPLK_MASK            0x80000000u
#define PCC_ADC2_DWPLK_SHIFT           31u
#define PCC_ADC2_DWPLK_WIDTH           1u
#define PCC_ADC2_DWPLK(x)              (((uint32_t)(((uint32_t)(x))<<PCC_ADC2_DWPLK_SHIFT))&PCC_ADC2_DWPLK_MASK)
#define PCC_ADC2_DWP_MASK              0x70000000u
#define PCC_ADC2_DWP_SHIFT             28u
#define PCC_ADC2_DWP_WIDTH             3u
#define PCC_ADC2_DWP(x)                (((uint32_t)(((uint32_t)(x))<<PCC_ADC2_DWP_SHIFT))&PCC_ADC2_DWP_MASK)
#define PCC_ADC2_CGC_MASK              0x800000u
#define PCC_ADC2_CGC_SHIFT             23u
#define PCC_ADC2_CGC_WIDTH             1u
#define PCC_ADC2_CGC(x)                (((uint32_t)(((uint32_t)(x))<<PCC_ADC2_CGC_SHIFT))&PCC_ADC2_CGC_MASK)
#define PCC_ADC2_SEL_MASK              0x700000u
#define PCC_ADC2_SEL_SHIFT             20u
#define PCC_ADC2_SEL_WIDTH             3u
#define PCC_ADC2_SEL(x)                (((uint32_t)(((uint32_t)(x))<<PCC_ADC2_SEL_SHIFT))&PCC_ADC2_SEL_MASK)
#define PCC_ADC2_SWR_MASK              0x10000u
#define PCC_ADC2_SWR_SHIFT             16u
#define PCC_ADC2_SWR_WIDTH             1u
#define PCC_ADC2_SWR(x)                (((uint32_t)(((uint32_t)(x))<<PCC_ADC2_SWR_SHIFT))&PCC_ADC2_SWR_MASK)
#define PCC_ADC2_DIV_DIS_MASK          0x8000u
#define PCC_ADC2_DIV_DIS_SHIFT         15u
#define PCC_ADC2_DIV_DIS_WIDTH         1u
#define PCC_ADC2_DIV_DIS(x)            (((uint32_t)(((uint32_t)(x))<<PCC_ADC2_DIV_DIS_SHIFT))&PCC_ADC2_DIV_DIS_MASK)
#define PCC_ADC2_DIV_MASK              0x7u
#define PCC_ADC2_DIV_SHIFT             0u
#define PCC_ADC2_DIV_WIDTH             3u
#define PCC_ADC2_DIV(x)                (((uint32_t)(((uint32_t)(x))<<PCC_ADC2_DIV_SHIFT))&PCC_ADC2_DIV_MASK)
/* ADC2 Reg Mask */
#define PCC_ADC2_MASK                  0xF0F18007u

/* ADC3 Bit Fields */
#define PCC_ADC3_DWPLK_MASK            0x80000000u
#define PCC_ADC3_DWPLK_SHIFT           31u
#define PCC_ADC3_DWPLK_WIDTH           1u
#define PCC_ADC3_DWPLK(x)              (((uint32_t)(((uint32_t)(x))<<PCC_ADC3_DWPLK_SHIFT))&PCC_ADC3_DWPLK_MASK)
#define PCC_ADC3_DWP_MASK              0x70000000u
#define PCC_ADC3_DWP_SHIFT             28u
#define PCC_ADC3_DWP_WIDTH             3u
#define PCC_ADC3_DWP(x)                (((uint32_t)(((uint32_t)(x))<<PCC_ADC3_DWP_SHIFT))&PCC_ADC3_DWP_MASK)
#define PCC_ADC3_CGC_MASK              0x800000u
#define PCC_ADC3_CGC_SHIFT             23u
#define PCC_ADC3_CGC_WIDTH             1u
#define PCC_ADC3_CGC(x)                (((uint32_t)(((uint32_t)(x))<<PCC_ADC3_CGC_SHIFT))&PCC_ADC3_CGC_MASK)
#define PCC_ADC3_SEL_MASK              0x700000u
#define PCC_ADC3_SEL_SHIFT             20u
#define PCC_ADC3_SEL_WIDTH             3u
#define PCC_ADC3_SEL(x)                (((uint32_t)(((uint32_t)(x))<<PCC_ADC3_SEL_SHIFT))&PCC_ADC3_SEL_MASK)
#define PCC_ADC3_SWR_MASK              0x10000u
#define PCC_ADC3_SWR_SHIFT             16u
#define PCC_ADC3_SWR_WIDTH             1u
#define PCC_ADC3_SWR(x)                (((uint32_t)(((uint32_t)(x))<<PCC_ADC3_SWR_SHIFT))&PCC_ADC3_SWR_MASK)
#define PCC_ADC3_DIV_DIS_MASK          0x8000u
#define PCC_ADC3_DIV_DIS_SHIFT         15u
#define PCC_ADC3_DIV_DIS_WIDTH         1u
#define PCC_ADC3_DIV_DIS(x)            (((uint32_t)(((uint32_t)(x))<<PCC_ADC3_DIV_DIS_SHIFT))&PCC_ADC3_DIV_DIS_MASK)
#define PCC_ADC3_DIV_MASK              0x7u
#define PCC_ADC3_DIV_SHIFT             0u
#define PCC_ADC3_DIV_WIDTH             3u
#define PCC_ADC3_DIV(x)                (((uint32_t)(((uint32_t)(x))<<PCC_ADC3_DIV_SHIFT))&PCC_ADC3_DIV_MASK)
/* ADC3 Reg Mask */
#define PCC_ADC3_MASK                  0xF0F18007u

/* SDADC0 Bit Fields */
#define PCC_SDADC0_DWPLK_MASK          0x80000000u
#define PCC_SDADC0_DWPLK_SHIFT         31u
#define PCC_SDADC0_DWPLK_WIDTH         1u
#define PCC_SDADC0_DWPLK(x)            (((uint32_t)(((uint32_t)(x))<<PCC_SDADC0_DWPLK_SHIFT))&PCC_SDADC0_DWPLK_MASK)
#define PCC_SDADC0_DWP_MASK            0x70000000u
#define PCC_SDADC0_DWP_SHIFT           28u
#define PCC_SDADC0_DWP_WIDTH           3u
#define PCC_SDADC0_DWP(x)              (((uint32_t)(((uint32_t)(x))<<PCC_SDADC0_DWP_SHIFT))&PCC_SDADC0_DWP_MASK)
#define PCC_SDADC0_CGC_MASK            0x800000u
#define PCC_SDADC0_CGC_SHIFT           23u
#define PCC_SDADC0_CGC_WIDTH           1u
#define PCC_SDADC0_CGC(x)              (((uint32_t)(((uint32_t)(x))<<PCC_SDADC0_CGC_SHIFT))&PCC_SDADC0_CGC_MASK)
#define PCC_SDADC0_SEL_MASK            0x700000u
#define PCC_SDADC0_SEL_SHIFT           20u
#define PCC_SDADC0_SEL_WIDTH           3u
#define PCC_SDADC0_SEL(x)              (((uint32_t)(((uint32_t)(x))<<PCC_SDADC0_SEL_SHIFT))&PCC_SDADC0_SEL_MASK)
#define PCC_SDADC0_SWR_MASK            0x10000u
#define PCC_SDADC0_SWR_SHIFT           16u
#define PCC_SDADC0_SWR_WIDTH           1u
#define PCC_SDADC0_SWR(x)              (((uint32_t)(((uint32_t)(x))<<PCC_SDADC0_SWR_SHIFT))&PCC_SDADC0_SWR_MASK)
#define PCC_SDADC0_DIV_DIS_MASK        0x8000u
#define PCC_SDADC0_DIV_DIS_SHIFT       15u
#define PCC_SDADC0_DIV_DIS_WIDTH       1u
#define PCC_SDADC0_DIV_DIS(x)          (((uint32_t)(((uint32_t)(x))<<PCC_SDADC0_DIV_DIS_SHIFT))&PCC_SDADC0_DIV_DIS_MASK)
#define PCC_SDADC0_DIV_MASK            0x7u
#define PCC_SDADC0_DIV_SHIFT           0u
#define PCC_SDADC0_DIV_WIDTH           3u
#define PCC_SDADC0_DIV(x)              (((uint32_t)(((uint32_t)(x))<<PCC_SDADC0_DIV_SHIFT))&PCC_SDADC0_DIV_MASK)
/* SDADC0 Reg Mask */
#define PCC_SDADC0_MASK                0xF0F18007u

/* WDOG1 Bit Fields */
#define PCC_WDOG1_DWPLK_MASK           0x80000000u
#define PCC_WDOG1_DWPLK_SHIFT          31u
#define PCC_WDOG1_DWPLK_WIDTH          1u
#define PCC_WDOG1_DWPLK(x)             (((uint32_t)(((uint32_t)(x))<<PCC_WDOG1_DWPLK_SHIFT))&PCC_WDOG1_DWPLK_MASK)
#define PCC_WDOG1_DWP_MASK             0x70000000u
#define PCC_WDOG1_DWP_SHIFT            28u
#define PCC_WDOG1_DWP_WIDTH            3u
#define PCC_WDOG1_DWP(x)               (((uint32_t)(((uint32_t)(x))<<PCC_WDOG1_DWP_SHIFT))&PCC_WDOG1_DWP_MASK)
/* WDOG1 Reg Mask */
#define PCC_WDOG1_MASK                 0xF0000000u

/* TSTMP2 Bit Fields */
#define PCC_TSTMP2_DWPLK_MASK          0x80000000u
#define PCC_TSTMP2_DWPLK_SHIFT         31u
#define PCC_TSTMP2_DWPLK_WIDTH         1u
#define PCC_TSTMP2_DWPLK(x)            (((uint32_t)(((uint32_t)(x))<<PCC_TSTMP2_DWPLK_SHIFT))&PCC_TSTMP2_DWPLK_MASK)
#define PCC_TSTMP2_DWP_MASK            0x70000000u
#define PCC_TSTMP2_DWP_SHIFT           28u
#define PCC_TSTMP2_DWP_WIDTH           3u
#define PCC_TSTMP2_DWP(x)              (((uint32_t)(((uint32_t)(x))<<PCC_TSTMP2_DWP_SHIFT))&PCC_TSTMP2_DWP_MASK)
#define PCC_TSTMP2_CGC_MASK            0x800000u
#define PCC_TSTMP2_CGC_SHIFT           23u
#define PCC_TSTMP2_CGC_WIDTH           1u
#define PCC_TSTMP2_CGC(x)              (((uint32_t)(((uint32_t)(x))<<PCC_TSTMP2_CGC_SHIFT))&PCC_TSTMP2_CGC_MASK)
#define PCC_TSTMP2_SWR_MASK            0x10000u
#define PCC_TSTMP2_SWR_SHIFT           16u
#define PCC_TSTMP2_SWR_WIDTH           1u
#define PCC_TSTMP2_SWR(x)              (((uint32_t)(((uint32_t)(x))<<PCC_TSTMP2_SWR_SHIFT))&PCC_TSTMP2_SWR_MASK)
/* TSTMP2 Reg Mask */
#define PCC_TSTMP2_MASK                0xF0810000u

/* TRGSEL4 Bit Fields */
#define PCC_TRGSEL4_DWPLK_MASK         0x80000000u
#define PCC_TRGSEL4_DWPLK_SHIFT        31u
#define PCC_TRGSEL4_DWPLK_WIDTH        1u
#define PCC_TRGSEL4_DWPLK(x)           (((uint32_t)(((uint32_t)(x))<<PCC_TRGSEL4_DWPLK_SHIFT))&PCC_TRGSEL4_DWPLK_MASK)
#define PCC_TRGSEL4_DWP_MASK           0x70000000u
#define PCC_TRGSEL4_DWP_SHIFT          28u
#define PCC_TRGSEL4_DWP_WIDTH          3u
#define PCC_TRGSEL4_DWP(x)             (((uint32_t)(((uint32_t)(x))<<PCC_TRGSEL4_DWP_SHIFT))&PCC_TRGSEL4_DWP_MASK)
#define PCC_TRGSEL4_CGC_MASK           0x800000u
#define PCC_TRGSEL4_CGC_SHIFT          23u
#define PCC_TRGSEL4_CGC_WIDTH          1u
#define PCC_TRGSEL4_CGC(x)             (((uint32_t)(((uint32_t)(x))<<PCC_TRGSEL4_CGC_SHIFT))&PCC_TRGSEL4_CGC_MASK)
#define PCC_TRGSEL4_SWR_MASK           0x10000u
#define PCC_TRGSEL4_SWR_SHIFT          16u
#define PCC_TRGSEL4_SWR_WIDTH          1u
#define PCC_TRGSEL4_SWR(x)             (((uint32_t)(((uint32_t)(x))<<PCC_TRGSEL4_SWR_SHIFT))&PCC_TRGSEL4_SWR_MASK)
/* TRGSEL4 Reg Mask */
#define PCC_TRGSEL4_MASK               0xF0810000u

/* TRGSEL5 Bit Fields */
#define PCC_TRGSEL5_DWPLK_MASK         0x80000000u
#define PCC_TRGSEL5_DWPLK_SHIFT        31u
#define PCC_TRGSEL5_DWPLK_WIDTH        1u
#define PCC_TRGSEL5_DWPLK(x)           (((uint32_t)(((uint32_t)(x))<<PCC_TRGSEL5_DWPLK_SHIFT))&PCC_TRGSEL5_DWPLK_MASK)
#define PCC_TRGSEL5_DWP_MASK           0x70000000u
#define PCC_TRGSEL5_DWP_SHIFT          28u
#define PCC_TRGSEL5_DWP_WIDTH          3u
#define PCC_TRGSEL5_DWP(x)             (((uint32_t)(((uint32_t)(x))<<PCC_TRGSEL5_DWP_SHIFT))&PCC_TRGSEL5_DWP_MASK)
#define PCC_TRGSEL5_CGC_MASK           0x800000u
#define PCC_TRGSEL5_CGC_SHIFT          23u
#define PCC_TRGSEL5_CGC_WIDTH          1u
#define PCC_TRGSEL5_CGC(x)             (((uint32_t)(((uint32_t)(x))<<PCC_TRGSEL5_CGC_SHIFT))&PCC_TRGSEL5_CGC_MASK)
#define PCC_TRGSEL5_SWR_MASK           0x10000u
#define PCC_TRGSEL5_SWR_SHIFT          16u
#define PCC_TRGSEL5_SWR_WIDTH          1u
#define PCC_TRGSEL5_SWR(x)             (((uint32_t)(((uint32_t)(x))<<PCC_TRGSEL5_SWR_SHIFT))&PCC_TRGSEL5_SWR_MASK)
/* TRGSEL5 Reg Mask */
#define PCC_TRGSEL5_MASK               0xF0810000u

/* TRGSEL6 Bit Fields */
#define PCC_TRGSEL6_DWPLK_MASK         0x80000000u
#define PCC_TRGSEL6_DWPLK_SHIFT        31u
#define PCC_TRGSEL6_DWPLK_WIDTH        1u
#define PCC_TRGSEL6_DWPLK(x)           (((uint32_t)(((uint32_t)(x))<<PCC_TRGSEL6_DWPLK_SHIFT))&PCC_TRGSEL6_DWPLK_MASK)
#define PCC_TRGSEL6_DWP_MASK           0x70000000u
#define PCC_TRGSEL6_DWP_SHIFT          28u
#define PCC_TRGSEL6_DWP_WIDTH          3u
#define PCC_TRGSEL6_DWP(x)             (((uint32_t)(((uint32_t)(x))<<PCC_TRGSEL6_DWP_SHIFT))&PCC_TRGSEL6_DWP_MASK)
#define PCC_TRGSEL6_CGC_MASK           0x800000u
#define PCC_TRGSEL6_CGC_SHIFT          23u
#define PCC_TRGSEL6_CGC_WIDTH          1u
#define PCC_TRGSEL6_CGC(x)             (((uint32_t)(((uint32_t)(x))<<PCC_TRGSEL6_CGC_SHIFT))&PCC_TRGSEL6_CGC_MASK)
#define PCC_TRGSEL6_SWR_MASK           0x10000u
#define PCC_TRGSEL6_SWR_SHIFT          16u
#define PCC_TRGSEL6_SWR_WIDTH          1u
#define PCC_TRGSEL6_SWR(x)             (((uint32_t)(((uint32_t)(x))<<PCC_TRGSEL6_SWR_SHIFT))&PCC_TRGSEL6_SWR_MASK)
/* TRGSEL6 Reg Mask */
#define PCC_TRGSEL6_MASK               0xF0810000u

/* TRGSEL7 Bit Fields */
#define PCC_TRGSEL7_DWPLK_MASK         0x80000000u
#define PCC_TRGSEL7_DWPLK_SHIFT        31u
#define PCC_TRGSEL7_DWPLK_WIDTH        1u
#define PCC_TRGSEL7_DWPLK(x)           (((uint32_t)(((uint32_t)(x))<<PCC_TRGSEL7_DWPLK_SHIFT))&PCC_TRGSEL7_DWPLK_MASK)
#define PCC_TRGSEL7_DWP_MASK           0x70000000u
#define PCC_TRGSEL7_DWP_SHIFT          28u
#define PCC_TRGSEL7_DWP_WIDTH          3u
#define PCC_TRGSEL7_DWP(x)             (((uint32_t)(((uint32_t)(x))<<PCC_TRGSEL7_DWP_SHIFT))&PCC_TRGSEL7_DWP_MASK)
#define PCC_TRGSEL7_CGC_MASK           0x800000u
#define PCC_TRGSEL7_CGC_SHIFT          23u
#define PCC_TRGSEL7_CGC_WIDTH          1u
#define PCC_TRGSEL7_CGC(x)             (((uint32_t)(((uint32_t)(x))<<PCC_TRGSEL7_CGC_SHIFT))&PCC_TRGSEL7_CGC_MASK)
#define PCC_TRGSEL7_SWR_MASK           0x10000u
#define PCC_TRGSEL7_SWR_SHIFT          16u
#define PCC_TRGSEL7_SWR_WIDTH          1u
#define PCC_TRGSEL7_SWR(x)             (((uint32_t)(((uint32_t)(x))<<PCC_TRGSEL7_SWR_SHIFT))&PCC_TRGSEL7_SWR_MASK)
/* TRGSEL7 Reg Mask */
#define PCC_TRGSEL7_MASK               0xF0810000u

/* TRGSEL8 Bit Fields */
#define PCC_TRGSEL8_DWPLK_MASK         0x80000000u
#define PCC_TRGSEL8_DWPLK_SHIFT        31u
#define PCC_TRGSEL8_DWPLK_WIDTH        1u
#define PCC_TRGSEL8_DWPLK(x)           (((uint32_t)(((uint32_t)(x))<<PCC_TRGSEL8_DWPLK_SHIFT))&PCC_TRGSEL8_DWPLK_MASK)
#define PCC_TRGSEL8_DWP_MASK           0x70000000u
#define PCC_TRGSEL8_DWP_SHIFT          28u
#define PCC_TRGSEL8_DWP_WIDTH          3u
#define PCC_TRGSEL8_DWP(x)             (((uint32_t)(((uint32_t)(x))<<PCC_TRGSEL8_DWP_SHIFT))&PCC_TRGSEL8_DWP_MASK)
#define PCC_TRGSEL8_CGC_MASK           0x800000u
#define PCC_TRGSEL8_CGC_SHIFT          23u
#define PCC_TRGSEL8_CGC_WIDTH          1u
#define PCC_TRGSEL8_CGC(x)             (((uint32_t)(((uint32_t)(x))<<PCC_TRGSEL8_CGC_SHIFT))&PCC_TRGSEL8_CGC_MASK)
#define PCC_TRGSEL8_SWR_MASK           0x10000u
#define PCC_TRGSEL8_SWR_SHIFT          16u
#define PCC_TRGSEL8_SWR_WIDTH          1u
#define PCC_TRGSEL8_SWR(x)             (((uint32_t)(((uint32_t)(x))<<PCC_TRGSEL8_SWR_SHIFT))&PCC_TRGSEL8_SWR_MASK)
/* TRGSEL8 Reg Mask */
#define PCC_TRGSEL8_MASK               0xF0810000u

/* SSI0 Bit Fields */
#define PCC_SSI0_DWPLK_MASK            0x80000000u
#define PCC_SSI0_DWPLK_SHIFT           31u
#define PCC_SSI0_DWPLK_WIDTH           1u
#define PCC_SSI0_DWPLK(x)              (((uint32_t)(((uint32_t)(x))<<PCC_SSI0_DWPLK_SHIFT))&PCC_SSI0_DWPLK_MASK)
#define PCC_SSI0_DWP_MASK              0x70000000u
#define PCC_SSI0_DWP_SHIFT             28u
#define PCC_SSI0_DWP_WIDTH             3u
#define PCC_SSI0_DWP(x)                (((uint32_t)(((uint32_t)(x))<<PCC_SSI0_DWP_SHIFT))&PCC_SSI0_DWP_MASK)
#define PCC_SSI0_CGC_MASK              0x800000u
#define PCC_SSI0_CGC_SHIFT             23u
#define PCC_SSI0_CGC_WIDTH             1u
#define PCC_SSI0_CGC(x)                (((uint32_t)(((uint32_t)(x))<<PCC_SSI0_CGC_SHIFT))&PCC_SSI0_CGC_MASK)
#define PCC_SSI0_SEL_MASK              0x700000u
#define PCC_SSI0_SEL_SHIFT             20u
#define PCC_SSI0_SEL_WIDTH             3u
#define PCC_SSI0_SEL(x)                (((uint32_t)(((uint32_t)(x))<<PCC_SSI0_SEL_SHIFT))&PCC_SSI0_SEL_MASK)
#define PCC_SSI0_SWR_MASK              0x10000u
#define PCC_SSI0_SWR_SHIFT             16u
#define PCC_SSI0_SWR_WIDTH             1u
#define PCC_SSI0_SWR(x)                (((uint32_t)(((uint32_t)(x))<<PCC_SSI0_SWR_SHIFT))&PCC_SSI0_SWR_MASK)
#define PCC_SSI0_DIV_DIS_MASK          0x8000u
#define PCC_SSI0_DIV_DIS_SHIFT         15u
#define PCC_SSI0_DIV_DIS_WIDTH         1u
#define PCC_SSI0_DIV_DIS(x)            (((uint32_t)(((uint32_t)(x))<<PCC_SSI0_DIV_DIS_SHIFT))&PCC_SSI0_DIV_DIS_MASK)
#define PCC_SSI0_DIV_MASK              0x7u
#define PCC_SSI0_DIV_SHIFT             0u
#define PCC_SSI0_DIV_WIDTH             3u
#define PCC_SSI0_DIV(x)                (((uint32_t)(((uint32_t)(x))<<PCC_SSI0_DIV_SHIFT))&PCC_SSI0_DIV_MASK)
/* SSI0 Reg Mask */
#define PCC_SSI0_MASK                  0xF0F18007u

/* CRM0 Bit Fields */
#define PCC_CRM0_DWPLK_MASK            0x80000000u
#define PCC_CRM0_DWPLK_SHIFT           31u
#define PCC_CRM0_DWPLK_WIDTH           1u
#define PCC_CRM0_DWPLK(x)              (((uint32_t)(((uint32_t)(x))<<PCC_CRM0_DWPLK_SHIFT))&PCC_CRM0_DWPLK_MASK)
#define PCC_CRM0_DWP_MASK              0x70000000u
#define PCC_CRM0_DWP_SHIFT             28u
#define PCC_CRM0_DWP_WIDTH             3u
#define PCC_CRM0_DWP(x)                (((uint32_t)(((uint32_t)(x))<<PCC_CRM0_DWP_SHIFT))&PCC_CRM0_DWP_MASK)
#define PCC_CRM0_CGC_MASK              0x800000u
#define PCC_CRM0_CGC_SHIFT             23u
#define PCC_CRM0_CGC_WIDTH             1u
#define PCC_CRM0_CGC(x)                (((uint32_t)(((uint32_t)(x))<<PCC_CRM0_CGC_SHIFT))&PCC_CRM0_CGC_MASK)
#define PCC_CRM0_SWR_MASK              0x10000u
#define PCC_CRM0_SWR_SHIFT             16u
#define PCC_CRM0_SWR_WIDTH             1u
#define PCC_CRM0_SWR(x)                (((uint32_t)(((uint32_t)(x))<<PCC_CRM0_SWR_SHIFT))&PCC_CRM0_SWR_MASK)
/* CRM0 Reg Mask */
#define PCC_CRM0_MASK                  0xF0810000u

/* LDI0 Bit Fields */
#define PCC_LDI0_DWPLK_MASK            0x80000000u
#define PCC_LDI0_DWPLK_SHIFT           31u
#define PCC_LDI0_DWPLK_WIDTH           1u
#define PCC_LDI0_DWPLK(x)              (((uint32_t)(((uint32_t)(x))<<PCC_LDI0_DWPLK_SHIFT))&PCC_LDI0_DWPLK_MASK)
#define PCC_LDI0_DWP_MASK              0x70000000u
#define PCC_LDI0_DWP_SHIFT             28u
#define PCC_LDI0_DWP_WIDTH             3u
#define PCC_LDI0_DWP(x)                (((uint32_t)(((uint32_t)(x))<<PCC_LDI0_DWP_SHIFT))&PCC_LDI0_DWP_MASK)
#define PCC_LDI0_CGC_MASK              0x800000u
#define PCC_LDI0_CGC_SHIFT             23u
#define PCC_LDI0_CGC_WIDTH             1u
#define PCC_LDI0_CGC(x)                (((uint32_t)(((uint32_t)(x))<<PCC_LDI0_CGC_SHIFT))&PCC_LDI0_CGC_MASK)
#define PCC_LDI0_SEL_MASK              0x700000u
#define PCC_LDI0_SEL_SHIFT             20u
#define PCC_LDI0_SEL_WIDTH             3u
#define PCC_LDI0_SEL(x)                (((uint32_t)(((uint32_t)(x))<<PCC_LDI0_SEL_SHIFT))&PCC_LDI0_SEL_MASK)
#define PCC_LDI0_SWR_MASK              0x10000u
#define PCC_LDI0_SWR_SHIFT             16u
#define PCC_LDI0_SWR_WIDTH             1u
#define PCC_LDI0_SWR(x)                (((uint32_t)(((uint32_t)(x))<<PCC_LDI0_SWR_SHIFT))&PCC_LDI0_SWR_MASK)
#define PCC_LDI0_DIV_DIS_MASK          0x8000u
#define PCC_LDI0_DIV_DIS_SHIFT         15u
#define PCC_LDI0_DIV_DIS_WIDTH         1u
#define PCC_LDI0_DIV_DIS(x)            (((uint32_t)(((uint32_t)(x))<<PCC_LDI0_DIV_DIS_SHIFT))&PCC_LDI0_DIV_DIS_MASK)
#define PCC_LDI0_DIV_MASK              0x7u
#define PCC_LDI0_DIV_SHIFT             0u
#define PCC_LDI0_DIV_WIDTH             3u
#define PCC_LDI0_DIV(x)                (((uint32_t)(((uint32_t)(x))<<PCC_LDI0_DIV_SHIFT))&PCC_LDI0_DIV_MASK)
/* LDI0 Reg Mask */
#define PCC_LDI0_MASK                  0xF0F18007u

/* SENT1 Bit Fields */
#define PCC_SENT1_DWPLK_MASK           0x80000000u
#define PCC_SENT1_DWPLK_SHIFT          31u
#define PCC_SENT1_DWPLK_WIDTH          1u
#define PCC_SENT1_DWPLK(x)             (((uint32_t)(((uint32_t)(x))<<PCC_SENT1_DWPLK_SHIFT))&PCC_SENT1_DWPLK_MASK)
#define PCC_SENT1_DWP_MASK             0x70000000u
#define PCC_SENT1_DWP_SHIFT            28u
#define PCC_SENT1_DWP_WIDTH            3u
#define PCC_SENT1_DWP(x)               (((uint32_t)(((uint32_t)(x))<<PCC_SENT1_DWP_SHIFT))&PCC_SENT1_DWP_MASK)
#define PCC_SENT1_CGC_MASK             0x800000u
#define PCC_SENT1_CGC_SHIFT            23u
#define PCC_SENT1_CGC_WIDTH            1u
#define PCC_SENT1_CGC(x)               (((uint32_t)(((uint32_t)(x))<<PCC_SENT1_CGC_SHIFT))&PCC_SENT1_CGC_MASK)
#define PCC_SENT1_SEL_MASK             0x700000u
#define PCC_SENT1_SEL_SHIFT            20u
#define PCC_SENT1_SEL_WIDTH            3u
#define PCC_SENT1_SEL(x)               (((uint32_t)(((uint32_t)(x))<<PCC_SENT1_SEL_SHIFT))&PCC_SENT1_SEL_MASK)
#define PCC_SENT1_SWR_MASK             0x10000u
#define PCC_SENT1_SWR_SHIFT            16u
#define PCC_SENT1_SWR_WIDTH            1u
#define PCC_SENT1_SWR(x)               (((uint32_t)(((uint32_t)(x))<<PCC_SENT1_SWR_SHIFT))&PCC_SENT1_SWR_MASK)
#define PCC_SENT1_DIV_DIS_MASK         0x8000u
#define PCC_SENT1_DIV_DIS_SHIFT        15u
#define PCC_SENT1_DIV_DIS_WIDTH        1u
#define PCC_SENT1_DIV_DIS(x)           (((uint32_t)(((uint32_t)(x))<<PCC_SENT1_DIV_DIS_SHIFT))&PCC_SENT1_DIV_DIS_MASK)
#define PCC_SENT1_DIV_MASK             0x7u
#define PCC_SENT1_DIV_SHIFT            0u
#define PCC_SENT1_DIV_WIDTH            3u
#define PCC_SENT1_DIV(x)               (((uint32_t)(((uint32_t)(x))<<PCC_SENT1_DIV_SHIFT))&PCC_SENT1_DIV_MASK)
/* SENT1 Reg Mask */
#define PCC_SENT1_MASK                 0xF0F18007u

/* FTU4 Bit Fields */
#define PCC_FTU4_DWPLK_MASK            0x80000000u
#define PCC_FTU4_DWPLK_SHIFT           31u
#define PCC_FTU4_DWPLK_WIDTH           1u
#define PCC_FTU4_DWPLK(x)              (((uint32_t)(((uint32_t)(x))<<PCC_FTU4_DWPLK_SHIFT))&PCC_FTU4_DWPLK_MASK)
#define PCC_FTU4_DWP_MASK              0x70000000u
#define PCC_FTU4_DWP_SHIFT             28u
#define PCC_FTU4_DWP_WIDTH             3u
#define PCC_FTU4_DWP(x)                (((uint32_t)(((uint32_t)(x))<<PCC_FTU4_DWP_SHIFT))&PCC_FTU4_DWP_MASK)
#define PCC_FTU4_CGC_MASK              0x800000u
#define PCC_FTU4_CGC_SHIFT             23u
#define PCC_FTU4_CGC_WIDTH             1u
#define PCC_FTU4_CGC(x)                (((uint32_t)(((uint32_t)(x))<<PCC_FTU4_CGC_SHIFT))&PCC_FTU4_CGC_MASK)
#define PCC_FTU4_SEL_MASK              0x700000u
#define PCC_FTU4_SEL_SHIFT             20u
#define PCC_FTU4_SEL_WIDTH             3u
#define PCC_FTU4_SEL(x)                (((uint32_t)(((uint32_t)(x))<<PCC_FTU4_SEL_SHIFT))&PCC_FTU4_SEL_MASK)
#define PCC_FTU4_SWR_MASK              0x10000u
#define PCC_FTU4_SWR_SHIFT             16u
#define PCC_FTU4_SWR_WIDTH             1u
#define PCC_FTU4_SWR(x)                (((uint32_t)(((uint32_t)(x))<<PCC_FTU4_SWR_SHIFT))&PCC_FTU4_SWR_MASK)
/* FTU4 Reg Mask */
#define PCC_FTU4_MASK                  0xF0F10000u

/* FTU5 Bit Fields */
#define PCC_FTU5_DWPLK_MASK            0x80000000u
#define PCC_FTU5_DWPLK_SHIFT           31u
#define PCC_FTU5_DWPLK_WIDTH           1u
#define PCC_FTU5_DWPLK(x)              (((uint32_t)(((uint32_t)(x))<<PCC_FTU5_DWPLK_SHIFT))&PCC_FTU5_DWPLK_MASK)
#define PCC_FTU5_DWP_MASK              0x70000000u
#define PCC_FTU5_DWP_SHIFT             28u
#define PCC_FTU5_DWP_WIDTH             3u
#define PCC_FTU5_DWP(x)                (((uint32_t)(((uint32_t)(x))<<PCC_FTU5_DWP_SHIFT))&PCC_FTU5_DWP_MASK)
#define PCC_FTU5_CGC_MASK              0x800000u
#define PCC_FTU5_CGC_SHIFT             23u
#define PCC_FTU5_CGC_WIDTH             1u
#define PCC_FTU5_CGC(x)                (((uint32_t)(((uint32_t)(x))<<PCC_FTU5_CGC_SHIFT))&PCC_FTU5_CGC_MASK)
#define PCC_FTU5_SEL_MASK              0x700000u
#define PCC_FTU5_SEL_SHIFT             20u
#define PCC_FTU5_SEL_WIDTH             3u
#define PCC_FTU5_SEL(x)                (((uint32_t)(((uint32_t)(x))<<PCC_FTU5_SEL_SHIFT))&PCC_FTU5_SEL_MASK)
#define PCC_FTU5_SWR_MASK              0x10000u
#define PCC_FTU5_SWR_SHIFT             16u
#define PCC_FTU5_SWR_WIDTH             1u
#define PCC_FTU5_SWR(x)                (((uint32_t)(((uint32_t)(x))<<PCC_FTU5_SWR_SHIFT))&PCC_FTU5_SWR_MASK)
/* FTU5 Reg Mask */
#define PCC_FTU5_MASK                  0xF0F10000u

/* FTU6 Bit Fields */
#define PCC_FTU6_DWPLK_MASK            0x80000000u
#define PCC_FTU6_DWPLK_SHIFT           31u
#define PCC_FTU6_DWPLK_WIDTH           1u
#define PCC_FTU6_DWPLK(x)              (((uint32_t)(((uint32_t)(x))<<PCC_FTU6_DWPLK_SHIFT))&PCC_FTU6_DWPLK_MASK)
#define PCC_FTU6_DWP_MASK              0x70000000u
#define PCC_FTU6_DWP_SHIFT             28u
#define PCC_FTU6_DWP_WIDTH             3u
#define PCC_FTU6_DWP(x)                (((uint32_t)(((uint32_t)(x))<<PCC_FTU6_DWP_SHIFT))&PCC_FTU6_DWP_MASK)
#define PCC_FTU6_CGC_MASK              0x800000u
#define PCC_FTU6_CGC_SHIFT             23u
#define PCC_FTU6_CGC_WIDTH             1u
#define PCC_FTU6_CGC(x)                (((uint32_t)(((uint32_t)(x))<<PCC_FTU6_CGC_SHIFT))&PCC_FTU6_CGC_MASK)
#define PCC_FTU6_SEL_MASK              0x700000u
#define PCC_FTU6_SEL_SHIFT             20u
#define PCC_FTU6_SEL_WIDTH             3u
#define PCC_FTU6_SEL(x)                (((uint32_t)(((uint32_t)(x))<<PCC_FTU6_SEL_SHIFT))&PCC_FTU6_SEL_MASK)
#define PCC_FTU6_SWR_MASK              0x10000u
#define PCC_FTU6_SWR_SHIFT             16u
#define PCC_FTU6_SWR_WIDTH             1u
#define PCC_FTU6_SWR(x)                (((uint32_t)(((uint32_t)(x))<<PCC_FTU6_SWR_SHIFT))&PCC_FTU6_SWR_MASK)
/* FTU6 Reg Mask */
#define PCC_FTU6_MASK                  0xF0F10000u

/* FTU7 Bit Fields */
#define PCC_FTU7_DWPLK_MASK            0x80000000u
#define PCC_FTU7_DWPLK_SHIFT           31u
#define PCC_FTU7_DWPLK_WIDTH           1u
#define PCC_FTU7_DWPLK(x)              (((uint32_t)(((uint32_t)(x))<<PCC_FTU7_DWPLK_SHIFT))&PCC_FTU7_DWPLK_MASK)
#define PCC_FTU7_DWP_MASK              0x70000000u
#define PCC_FTU7_DWP_SHIFT             28u
#define PCC_FTU7_DWP_WIDTH             3u
#define PCC_FTU7_DWP(x)                (((uint32_t)(((uint32_t)(x))<<PCC_FTU7_DWP_SHIFT))&PCC_FTU7_DWP_MASK)
#define PCC_FTU7_CGC_MASK              0x800000u
#define PCC_FTU7_CGC_SHIFT             23u
#define PCC_FTU7_CGC_WIDTH             1u
#define PCC_FTU7_CGC(x)                (((uint32_t)(((uint32_t)(x))<<PCC_FTU7_CGC_SHIFT))&PCC_FTU7_CGC_MASK)
#define PCC_FTU7_SEL_MASK              0x700000u
#define PCC_FTU7_SEL_SHIFT             20u
#define PCC_FTU7_SEL_WIDTH             3u
#define PCC_FTU7_SEL(x)                (((uint32_t)(((uint32_t)(x))<<PCC_FTU7_SEL_SHIFT))&PCC_FTU7_SEL_MASK)
#define PCC_FTU7_SWR_MASK              0x10000u
#define PCC_FTU7_SWR_SHIFT             16u
#define PCC_FTU7_SWR_WIDTH             1u
#define PCC_FTU7_SWR(x)                (((uint32_t)(((uint32_t)(x))<<PCC_FTU7_SWR_SHIFT))&PCC_FTU7_SWR_MASK)
/* FTU7 Reg Mask */
#define PCC_FTU7_MASK                  0xF0F10000u

/* FCIIC1 Bit Fields */
#define PCC_FCIIC1_DWPLK_MASK          0x80000000u
#define PCC_FCIIC1_DWPLK_SHIFT         31u
#define PCC_FCIIC1_DWPLK_WIDTH         1u
#define PCC_FCIIC1_DWPLK(x)            (((uint32_t)(((uint32_t)(x))<<PCC_FCIIC1_DWPLK_SHIFT))&PCC_FCIIC1_DWPLK_MASK)
#define PCC_FCIIC1_DWP_MASK            0x70000000u
#define PCC_FCIIC1_DWP_SHIFT           28u
#define PCC_FCIIC1_DWP_WIDTH           3u
#define PCC_FCIIC1_DWP(x)              (((uint32_t)(((uint32_t)(x))<<PCC_FCIIC1_DWP_SHIFT))&PCC_FCIIC1_DWP_MASK)
#define PCC_FCIIC1_CGC_MASK            0x800000u
#define PCC_FCIIC1_CGC_SHIFT           23u
#define PCC_FCIIC1_CGC_WIDTH           1u
#define PCC_FCIIC1_CGC(x)              (((uint32_t)(((uint32_t)(x))<<PCC_FCIIC1_CGC_SHIFT))&PCC_FCIIC1_CGC_MASK)
#define PCC_FCIIC1_SEL_MASK            0x700000u
#define PCC_FCIIC1_SEL_SHIFT           20u
#define PCC_FCIIC1_SEL_WIDTH           3u
#define PCC_FCIIC1_SEL(x)              (((uint32_t)(((uint32_t)(x))<<PCC_FCIIC1_SEL_SHIFT))&PCC_FCIIC1_SEL_MASK)
#define PCC_FCIIC1_SWR_MASK            0x10000u
#define PCC_FCIIC1_SWR_SHIFT           16u
#define PCC_FCIIC1_SWR_WIDTH           1u
#define PCC_FCIIC1_SWR(x)              (((uint32_t)(((uint32_t)(x))<<PCC_FCIIC1_SWR_SHIFT))&PCC_FCIIC1_SWR_MASK)
/* FCIIC1 Reg Mask */
#define PCC_FCIIC1_MASK                0xF0F10000u

/* FCUART4 Bit Fields */
#define PCC_FCUART4_DWPLK_MASK         0x80000000u
#define PCC_FCUART4_DWPLK_SHIFT        31u
#define PCC_FCUART4_DWPLK_WIDTH        1u
#define PCC_FCUART4_DWPLK(x)           (((uint32_t)(((uint32_t)(x))<<PCC_FCUART4_DWPLK_SHIFT))&PCC_FCUART4_DWPLK_MASK)
#define PCC_FCUART4_DWP_MASK           0x70000000u
#define PCC_FCUART4_DWP_SHIFT          28u
#define PCC_FCUART4_DWP_WIDTH          3u
#define PCC_FCUART4_DWP(x)             (((uint32_t)(((uint32_t)(x))<<PCC_FCUART4_DWP_SHIFT))&PCC_FCUART4_DWP_MASK)
#define PCC_FCUART4_CGC_MASK           0x800000u
#define PCC_FCUART4_CGC_SHIFT          23u
#define PCC_FCUART4_CGC_WIDTH          1u
#define PCC_FCUART4_CGC(x)             (((uint32_t)(((uint32_t)(x))<<PCC_FCUART4_CGC_SHIFT))&PCC_FCUART4_CGC_MASK)
#define PCC_FCUART4_SEL_MASK           0x700000u
#define PCC_FCUART4_SEL_SHIFT          20u
#define PCC_FCUART4_SEL_WIDTH          3u
#define PCC_FCUART4_SEL(x)             (((uint32_t)(((uint32_t)(x))<<PCC_FCUART4_SEL_SHIFT))&PCC_FCUART4_SEL_MASK)
#define PCC_FCUART4_SWR_MASK           0x10000u
#define PCC_FCUART4_SWR_SHIFT          16u
#define PCC_FCUART4_SWR_WIDTH          1u
#define PCC_FCUART4_SWR(x)             (((uint32_t)(((uint32_t)(x))<<PCC_FCUART4_SWR_SHIFT))&PCC_FCUART4_SWR_MASK)
/* FCUART4 Reg Mask */
#define PCC_FCUART4_MASK               0xF0F10000u

/* FCUART5 Bit Fields */
#define PCC_FCUART5_DWPLK_MASK         0x80000000u
#define PCC_FCUART5_DWPLK_SHIFT        31u
#define PCC_FCUART5_DWPLK_WIDTH        1u
#define PCC_FCUART5_DWPLK(x)           (((uint32_t)(((uint32_t)(x))<<PCC_FCUART5_DWPLK_SHIFT))&PCC_FCUART5_DWPLK_MASK)
#define PCC_FCUART5_DWP_MASK           0x70000000u
#define PCC_FCUART5_DWP_SHIFT          28u
#define PCC_FCUART5_DWP_WIDTH          3u
#define PCC_FCUART5_DWP(x)             (((uint32_t)(((uint32_t)(x))<<PCC_FCUART5_DWP_SHIFT))&PCC_FCUART5_DWP_MASK)
#define PCC_FCUART5_CGC_MASK           0x800000u
#define PCC_FCUART5_CGC_SHIFT          23u
#define PCC_FCUART5_CGC_WIDTH          1u
#define PCC_FCUART5_CGC(x)             (((uint32_t)(((uint32_t)(x))<<PCC_FCUART5_CGC_SHIFT))&PCC_FCUART5_CGC_MASK)
#define PCC_FCUART5_SEL_MASK           0x700000u
#define PCC_FCUART5_SEL_SHIFT          20u
#define PCC_FCUART5_SEL_WIDTH          3u
#define PCC_FCUART5_SEL(x)             (((uint32_t)(((uint32_t)(x))<<PCC_FCUART5_SEL_SHIFT))&PCC_FCUART5_SEL_MASK)
#define PCC_FCUART5_SWR_MASK           0x10000u
#define PCC_FCUART5_SWR_SHIFT          16u
#define PCC_FCUART5_SWR_WIDTH          1u
#define PCC_FCUART5_SWR(x)             (((uint32_t)(((uint32_t)(x))<<PCC_FCUART5_SWR_SHIFT))&PCC_FCUART5_SWR_MASK)
/* FCUART5 Reg Mask */
#define PCC_FCUART5_MASK               0xF0F10000u

/* FCUART6 Bit Fields */
#define PCC_FCUART6_DWPLK_MASK         0x80000000u
#define PCC_FCUART6_DWPLK_SHIFT        31u
#define PCC_FCUART6_DWPLK_WIDTH        1u
#define PCC_FCUART6_DWPLK(x)           (((uint32_t)(((uint32_t)(x))<<PCC_FCUART6_DWPLK_SHIFT))&PCC_FCUART6_DWPLK_MASK)
#define PCC_FCUART6_DWP_MASK           0x70000000u
#define PCC_FCUART6_DWP_SHIFT          28u
#define PCC_FCUART6_DWP_WIDTH          3u
#define PCC_FCUART6_DWP(x)             (((uint32_t)(((uint32_t)(x))<<PCC_FCUART6_DWP_SHIFT))&PCC_FCUART6_DWP_MASK)
#define PCC_FCUART6_CGC_MASK           0x800000u
#define PCC_FCUART6_CGC_SHIFT          23u
#define PCC_FCUART6_CGC_WIDTH          1u
#define PCC_FCUART6_CGC(x)             (((uint32_t)(((uint32_t)(x))<<PCC_FCUART6_CGC_SHIFT))&PCC_FCUART6_CGC_MASK)
#define PCC_FCUART6_SEL_MASK           0x700000u
#define PCC_FCUART6_SEL_SHIFT          20u
#define PCC_FCUART6_SEL_WIDTH          3u
#define PCC_FCUART6_SEL(x)             (((uint32_t)(((uint32_t)(x))<<PCC_FCUART6_SEL_SHIFT))&PCC_FCUART6_SEL_MASK)
#define PCC_FCUART6_SWR_MASK           0x10000u
#define PCC_FCUART6_SWR_SHIFT          16u
#define PCC_FCUART6_SWR_WIDTH          1u
#define PCC_FCUART6_SWR(x)             (((uint32_t)(((uint32_t)(x))<<PCC_FCUART6_SWR_SHIFT))&PCC_FCUART6_SWR_MASK)
/* FCUART6 Reg Mask */
#define PCC_FCUART6_MASK               0xF0F10000u

/* FCUART7 Bit Fields */
#define PCC_FCUART7_DWPLK_MASK         0x80000000u
#define PCC_FCUART7_DWPLK_SHIFT        31u
#define PCC_FCUART7_DWPLK_WIDTH        1u
#define PCC_FCUART7_DWPLK(x)           (((uint32_t)(((uint32_t)(x))<<PCC_FCUART7_DWPLK_SHIFT))&PCC_FCUART7_DWPLK_MASK)
#define PCC_FCUART7_DWP_MASK           0x70000000u
#define PCC_FCUART7_DWP_SHIFT          28u
#define PCC_FCUART7_DWP_WIDTH          3u
#define PCC_FCUART7_DWP(x)             (((uint32_t)(((uint32_t)(x))<<PCC_FCUART7_DWP_SHIFT))&PCC_FCUART7_DWP_MASK)
#define PCC_FCUART7_CGC_MASK           0x800000u
#define PCC_FCUART7_CGC_SHIFT          23u
#define PCC_FCUART7_CGC_WIDTH          1u
#define PCC_FCUART7_CGC(x)             (((uint32_t)(((uint32_t)(x))<<PCC_FCUART7_CGC_SHIFT))&PCC_FCUART7_CGC_MASK)
#define PCC_FCUART7_SEL_MASK           0x700000u
#define PCC_FCUART7_SEL_SHIFT          20u
#define PCC_FCUART7_SEL_WIDTH          3u
#define PCC_FCUART7_SEL(x)             (((uint32_t)(((uint32_t)(x))<<PCC_FCUART7_SEL_SHIFT))&PCC_FCUART7_SEL_MASK)
#define PCC_FCUART7_SWR_MASK           0x10000u
#define PCC_FCUART7_SWR_SHIFT          16u
#define PCC_FCUART7_SWR_WIDTH          1u
#define PCC_FCUART7_SWR(x)             (((uint32_t)(((uint32_t)(x))<<PCC_FCUART7_SWR_SHIFT))&PCC_FCUART7_SWR_MASK)
/* FCUART7 Reg Mask */
#define PCC_FCUART7_MASK               0xF0F10000u

/* FCSPI4 Bit Fields */
#define PCC_FCSPI4_DWPLK_MASK          0x80000000u
#define PCC_FCSPI4_DWPLK_SHIFT         31u
#define PCC_FCSPI4_DWPLK_WIDTH         1u
#define PCC_FCSPI4_DWPLK(x)            (((uint32_t)(((uint32_t)(x))<<PCC_FCSPI4_DWPLK_SHIFT))&PCC_FCSPI4_DWPLK_MASK)
#define PCC_FCSPI4_DWP_MASK            0x70000000u
#define PCC_FCSPI4_DWP_SHIFT           28u
#define PCC_FCSPI4_DWP_WIDTH           3u
#define PCC_FCSPI4_DWP(x)              (((uint32_t)(((uint32_t)(x))<<PCC_FCSPI4_DWP_SHIFT))&PCC_FCSPI4_DWP_MASK)
#define PCC_FCSPI4_CGC_MASK            0x800000u
#define PCC_FCSPI4_CGC_SHIFT           23u
#define PCC_FCSPI4_CGC_WIDTH           1u
#define PCC_FCSPI4_CGC(x)              (((uint32_t)(((uint32_t)(x))<<PCC_FCSPI4_CGC_SHIFT))&PCC_FCSPI4_CGC_MASK)
#define PCC_FCSPI4_SEL_MASK            0x700000u
#define PCC_FCSPI4_SEL_SHIFT           20u
#define PCC_FCSPI4_SEL_WIDTH           3u
#define PCC_FCSPI4_SEL(x)              (((uint32_t)(((uint32_t)(x))<<PCC_FCSPI4_SEL_SHIFT))&PCC_FCSPI4_SEL_MASK)
#define PCC_FCSPI4_SWR_MASK            0x10000u
#define PCC_FCSPI4_SWR_SHIFT           16u
#define PCC_FCSPI4_SWR_WIDTH           1u
#define PCC_FCSPI4_SWR(x)              (((uint32_t)(((uint32_t)(x))<<PCC_FCSPI4_SWR_SHIFT))&PCC_FCSPI4_SWR_MASK)
/* FCSPI4 Reg Mask */
#define PCC_FCSPI4_MASK                0xF0F10000u

/* FCSPI5 Bit Fields */
#define PCC_FCSPI5_DWPLK_MASK          0x80000000u
#define PCC_FCSPI5_DWPLK_SHIFT         31u
#define PCC_FCSPI5_DWPLK_WIDTH         1u
#define PCC_FCSPI5_DWPLK(x)            (((uint32_t)(((uint32_t)(x))<<PCC_FCSPI5_DWPLK_SHIFT))&PCC_FCSPI5_DWPLK_MASK)
#define PCC_FCSPI5_DWP_MASK            0x70000000u
#define PCC_FCSPI5_DWP_SHIFT           28u
#define PCC_FCSPI5_DWP_WIDTH           3u
#define PCC_FCSPI5_DWP(x)              (((uint32_t)(((uint32_t)(x))<<PCC_FCSPI5_DWP_SHIFT))&PCC_FCSPI5_DWP_MASK)
#define PCC_FCSPI5_CGC_MASK            0x800000u
#define PCC_FCSPI5_CGC_SHIFT           23u
#define PCC_FCSPI5_CGC_WIDTH           1u
#define PCC_FCSPI5_CGC(x)              (((uint32_t)(((uint32_t)(x))<<PCC_FCSPI5_CGC_SHIFT))&PCC_FCSPI5_CGC_MASK)
#define PCC_FCSPI5_SEL_MASK            0x700000u
#define PCC_FCSPI5_SEL_SHIFT           20u
#define PCC_FCSPI5_SEL_WIDTH           3u
#define PCC_FCSPI5_SEL(x)              (((uint32_t)(((uint32_t)(x))<<PCC_FCSPI5_SEL_SHIFT))&PCC_FCSPI5_SEL_MASK)
#define PCC_FCSPI5_SWR_MASK            0x10000u
#define PCC_FCSPI5_SWR_SHIFT           16u
#define PCC_FCSPI5_SWR_WIDTH           1u
#define PCC_FCSPI5_SWR(x)              (((uint32_t)(((uint32_t)(x))<<PCC_FCSPI5_SWR_SHIFT))&PCC_FCSPI5_SWR_MASK)
/* FCSPI5 Reg Mask */
#define PCC_FCSPI5_MASK                0xF0F10000u

/* MSC0 Bit Fields */
#define PCC_MSC0_DWPLK_MASK            0x80000000u
#define PCC_MSC0_DWPLK_SHIFT           31u
#define PCC_MSC0_DWPLK_WIDTH           1u
#define PCC_MSC0_DWPLK(x)              (((uint32_t)(((uint32_t)(x))<<PCC_MSC0_DWPLK_SHIFT))&PCC_MSC0_DWPLK_MASK)
#define PCC_MSC0_DWP_MASK              0x70000000u
#define PCC_MSC0_DWP_SHIFT             28u
#define PCC_MSC0_DWP_WIDTH             3u
#define PCC_MSC0_DWP(x)                (((uint32_t)(((uint32_t)(x))<<PCC_MSC0_DWP_SHIFT))&PCC_MSC0_DWP_MASK)
#define PCC_MSC0_CGC_MASK              0x800000u
#define PCC_MSC0_CGC_SHIFT             23u
#define PCC_MSC0_CGC_WIDTH             1u
#define PCC_MSC0_CGC(x)                (((uint32_t)(((uint32_t)(x))<<PCC_MSC0_CGC_SHIFT))&PCC_MSC0_CGC_MASK)
#define PCC_MSC0_SEL_MASK              0x700000u
#define PCC_MSC0_SEL_SHIFT             20u
#define PCC_MSC0_SEL_WIDTH             3u
#define PCC_MSC0_SEL(x)                (((uint32_t)(((uint32_t)(x))<<PCC_MSC0_SEL_SHIFT))&PCC_MSC0_SEL_MASK)
#define PCC_MSC0_SWR_MASK              0x10000u
#define PCC_MSC0_SWR_SHIFT             16u
#define PCC_MSC0_SWR_WIDTH             1u
#define PCC_MSC0_SWR(x)                (((uint32_t)(((uint32_t)(x))<<PCC_MSC0_SWR_SHIFT))&PCC_MSC0_SWR_MASK)
#define PCC_MSC0_DIV_DIS_MASK          0x8000u
#define PCC_MSC0_DIV_DIS_SHIFT         15u
#define PCC_MSC0_DIV_DIS_WIDTH         1u
#define PCC_MSC0_DIV_DIS(x)            (((uint32_t)(((uint32_t)(x))<<PCC_MSC0_DIV_DIS_SHIFT))&PCC_MSC0_DIV_DIS_MASK)
#define PCC_MSC0_DIV_MASK              0x7u
#define PCC_MSC0_DIV_SHIFT             0u
#define PCC_MSC0_DIV_WIDTH             3u
#define PCC_MSC0_DIV(x)                (((uint32_t)(((uint32_t)(x))<<PCC_MSC0_DIV_SHIFT))&PCC_MSC0_DIV_MASK)
/* MSC0 Reg Mask */
#define PCC_MSC0_MASK                  0xF0F18007u

/* EFTU0 Bit Fields */
#define PCC_EFTU0_DWPLK_MASK           0x80000000u
#define PCC_EFTU0_DWPLK_SHIFT          31u
#define PCC_EFTU0_DWPLK_WIDTH          1u
#define PCC_EFTU0_DWPLK(x)             (((uint32_t)(((uint32_t)(x))<<PCC_EFTU0_DWPLK_SHIFT))&PCC_EFTU0_DWPLK_MASK)
#define PCC_EFTU0_DWP_MASK             0x70000000u
#define PCC_EFTU0_DWP_SHIFT            28u
#define PCC_EFTU0_DWP_WIDTH            3u
#define PCC_EFTU0_DWP(x)               (((uint32_t)(((uint32_t)(x))<<PCC_EFTU0_DWP_SHIFT))&PCC_EFTU0_DWP_MASK)
#define PCC_EFTU0_CGC_MASK             0x800000u
#define PCC_EFTU0_CGC_SHIFT            23u
#define PCC_EFTU0_CGC_WIDTH            1u
#define PCC_EFTU0_CGC(x)               (((uint32_t)(((uint32_t)(x))<<PCC_EFTU0_CGC_SHIFT))&PCC_EFTU0_CGC_MASK)
#define PCC_EFTU0_SWR_MASK             0x10000u
#define PCC_EFTU0_SWR_SHIFT            16u
#define PCC_EFTU0_SWR_WIDTH            1u
#define PCC_EFTU0_SWR(x)               (((uint32_t)(((uint32_t)(x))<<PCC_EFTU0_SWR_SHIFT))&PCC_EFTU0_SWR_MASK)
/* EFTU0 Reg Mask */
#define PCC_EFTU0_MASK                 0xF0810000u

/* FLEXCAN5 Bit Fields */
#define PCC_FLEXCAN5_DWPLK_MASK        0x80000000u
#define PCC_FLEXCAN5_DWPLK_SHIFT       31u
#define PCC_FLEXCAN5_DWPLK_WIDTH       1u
#define PCC_FLEXCAN5_DWPLK(x)          (((uint32_t)(((uint32_t)(x))<<PCC_FLEXCAN5_DWPLK_SHIFT))&PCC_FLEXCAN5_DWPLK_MASK)
#define PCC_FLEXCAN5_DWP_MASK          0x70000000u
#define PCC_FLEXCAN5_DWP_SHIFT         28u
#define PCC_FLEXCAN5_DWP_WIDTH         3u
#define PCC_FLEXCAN5_DWP(x)            (((uint32_t)(((uint32_t)(x))<<PCC_FLEXCAN5_DWP_SHIFT))&PCC_FLEXCAN5_DWP_MASK)
#define PCC_FLEXCAN5_CGC_MASK          0x800000u
#define PCC_FLEXCAN5_CGC_SHIFT         23u
#define PCC_FLEXCAN5_CGC_WIDTH         1u
#define PCC_FLEXCAN5_CGC(x)            (((uint32_t)(((uint32_t)(x))<<PCC_FLEXCAN5_CGC_SHIFT))&PCC_FLEXCAN5_CGC_MASK)
#define PCC_FLEXCAN5_SEL_MASK          0x700000u
#define PCC_FLEXCAN5_SEL_SHIFT         20u
#define PCC_FLEXCAN5_SEL_WIDTH         3u
#define PCC_FLEXCAN5_SEL(x)            (((uint32_t)(((uint32_t)(x))<<PCC_FLEXCAN5_SEL_SHIFT))&PCC_FLEXCAN5_SEL_MASK)
#define PCC_FLEXCAN5_SWR_MASK          0x10000u
#define PCC_FLEXCAN5_SWR_SHIFT         16u
#define PCC_FLEXCAN5_SWR_WIDTH         1u
#define PCC_FLEXCAN5_SWR(x)            (((uint32_t)(((uint32_t)(x))<<PCC_FLEXCAN5_SWR_SHIFT))&PCC_FLEXCAN5_SWR_MASK)
#define PCC_FLEXCAN5_DIV_DIS_MASK      0x8000u
#define PCC_FLEXCAN5_DIV_DIS_SHIFT     15u
#define PCC_FLEXCAN5_DIV_DIS_WIDTH     1u
#define PCC_FLEXCAN5_DIV_DIS(x)        (((uint32_t)(((uint32_t)(x))<<PCC_FLEXCAN5_DIV_DIS_SHIFT))&PCC_FLEXCAN5_DIV_DIS_MASK)
#define PCC_FLEXCAN5_DIV_MASK          0x7u
#define PCC_FLEXCAN5_DIV_SHIFT         0u
#define PCC_FLEXCAN5_DIV_WIDTH         3u
#define PCC_FLEXCAN5_DIV(x)            (((uint32_t)(((uint32_t)(x))<<PCC_FLEXCAN5_DIV_SHIFT))&PCC_FLEXCAN5_DIV_MASK)
/* FLEXCAN5 Reg Mask */
#define PCC_FLEXCAN5_MASK              0xF0F18007u

/* FLEXCAN6 Bit Fields */
#define PCC_FLEXCAN6_DWPLK_MASK        0x80000000u
#define PCC_FLEXCAN6_DWPLK_SHIFT       31u
#define PCC_FLEXCAN6_DWPLK_WIDTH       1u
#define PCC_FLEXCAN6_DWPLK(x)          (((uint32_t)(((uint32_t)(x))<<PCC_FLEXCAN6_DWPLK_SHIFT))&PCC_FLEXCAN6_DWPLK_MASK)
#define PCC_FLEXCAN6_DWP_MASK          0x70000000u
#define PCC_FLEXCAN6_DWP_SHIFT         28u
#define PCC_FLEXCAN6_DWP_WIDTH         3u
#define PCC_FLEXCAN6_DWP(x)            (((uint32_t)(((uint32_t)(x))<<PCC_FLEXCAN6_DWP_SHIFT))&PCC_FLEXCAN6_DWP_MASK)
#define PCC_FLEXCAN6_CGC_MASK          0x800000u
#define PCC_FLEXCAN6_CGC_SHIFT         23u
#define PCC_FLEXCAN6_CGC_WIDTH         1u
#define PCC_FLEXCAN6_CGC(x)            (((uint32_t)(((uint32_t)(x))<<PCC_FLEXCAN6_CGC_SHIFT))&PCC_FLEXCAN6_CGC_MASK)
#define PCC_FLEXCAN6_SEL_MASK          0x700000u
#define PCC_FLEXCAN6_SEL_SHIFT         20u
#define PCC_FLEXCAN6_SEL_WIDTH         3u
#define PCC_FLEXCAN6_SEL(x)            (((uint32_t)(((uint32_t)(x))<<PCC_FLEXCAN6_SEL_SHIFT))&PCC_FLEXCAN6_SEL_MASK)
#define PCC_FLEXCAN6_SWR_MASK          0x10000u
#define PCC_FLEXCAN6_SWR_SHIFT         16u
#define PCC_FLEXCAN6_SWR_WIDTH         1u
#define PCC_FLEXCAN6_SWR(x)            (((uint32_t)(((uint32_t)(x))<<PCC_FLEXCAN6_SWR_SHIFT))&PCC_FLEXCAN6_SWR_MASK)
#define PCC_FLEXCAN6_DIV_DIS_MASK      0x8000u
#define PCC_FLEXCAN6_DIV_DIS_SHIFT     15u
#define PCC_FLEXCAN6_DIV_DIS_WIDTH     1u
#define PCC_FLEXCAN6_DIV_DIS(x)        (((uint32_t)(((uint32_t)(x))<<PCC_FLEXCAN6_DIV_DIS_SHIFT))&PCC_FLEXCAN6_DIV_DIS_MASK)
#define PCC_FLEXCAN6_DIV_MASK          0x7u
#define PCC_FLEXCAN6_DIV_SHIFT         0u
#define PCC_FLEXCAN6_DIV_WIDTH         3u
#define PCC_FLEXCAN6_DIV(x)            (((uint32_t)(((uint32_t)(x))<<PCC_FLEXCAN6_DIV_SHIFT))&PCC_FLEXCAN6_DIV_MASK)
/* FLEXCAN6 Reg Mask */
#define PCC_FLEXCAN6_MASK              0xF0F18007u

/* FLEXCAN7 Bit Fields */
#define PCC_FLEXCAN7_DWPLK_MASK        0x80000000u
#define PCC_FLEXCAN7_DWPLK_SHIFT       31u
#define PCC_FLEXCAN7_DWPLK_WIDTH       1u
#define PCC_FLEXCAN7_DWPLK(x)          (((uint32_t)(((uint32_t)(x))<<PCC_FLEXCAN7_DWPLK_SHIFT))&PCC_FLEXCAN7_DWPLK_MASK)
#define PCC_FLEXCAN7_DWP_MASK          0x70000000u
#define PCC_FLEXCAN7_DWP_SHIFT         28u
#define PCC_FLEXCAN7_DWP_WIDTH         3u
#define PCC_FLEXCAN7_DWP(x)            (((uint32_t)(((uint32_t)(x))<<PCC_FLEXCAN7_DWP_SHIFT))&PCC_FLEXCAN7_DWP_MASK)
#define PCC_FLEXCAN7_CGC_MASK          0x800000u
#define PCC_FLEXCAN7_CGC_SHIFT         23u
#define PCC_FLEXCAN7_CGC_WIDTH         1u
#define PCC_FLEXCAN7_CGC(x)            (((uint32_t)(((uint32_t)(x))<<PCC_FLEXCAN7_CGC_SHIFT))&PCC_FLEXCAN7_CGC_MASK)
#define PCC_FLEXCAN7_SEL_MASK          0x700000u
#define PCC_FLEXCAN7_SEL_SHIFT         20u
#define PCC_FLEXCAN7_SEL_WIDTH         3u
#define PCC_FLEXCAN7_SEL(x)            (((uint32_t)(((uint32_t)(x))<<PCC_FLEXCAN7_SEL_SHIFT))&PCC_FLEXCAN7_SEL_MASK)
#define PCC_FLEXCAN7_SWR_MASK          0x10000u
#define PCC_FLEXCAN7_SWR_SHIFT         16u
#define PCC_FLEXCAN7_SWR_WIDTH         1u
#define PCC_FLEXCAN7_SWR(x)            (((uint32_t)(((uint32_t)(x))<<PCC_FLEXCAN7_SWR_SHIFT))&PCC_FLEXCAN7_SWR_MASK)
#define PCC_FLEXCAN7_DIV_DIS_MASK      0x8000u
#define PCC_FLEXCAN7_DIV_DIS_SHIFT     15u
#define PCC_FLEXCAN7_DIV_DIS_WIDTH     1u
#define PCC_FLEXCAN7_DIV_DIS(x)        (((uint32_t)(((uint32_t)(x))<<PCC_FLEXCAN7_DIV_DIS_SHIFT))&PCC_FLEXCAN7_DIV_DIS_MASK)
#define PCC_FLEXCAN7_DIV_MASK          0x7u
#define PCC_FLEXCAN7_DIV_SHIFT         0u
#define PCC_FLEXCAN7_DIV_WIDTH         3u
#define PCC_FLEXCAN7_DIV(x)            (((uint32_t)(((uint32_t)(x))<<PCC_FLEXCAN7_DIV_SHIFT))&PCC_FLEXCAN7_DIV_MASK)
/* FLEXCAN7 Reg Mask */
#define PCC_FLEXCAN7_MASK              0xF0F18007u


/*!
 * @}
 */ /* end of group PCC_Register_Masks */

/*!
 * @}
 */ /* end of group PCC_Peripheral_Access_Layer */

#endif
