#ifndef _MODULE_DMA_gmbhdijq115_REGS_H_DMA_H_
#define _MODULE_DMA_gmbhdijq115_REGS_H_DMA_H_

/* ----------------------------------------------------------------------------
   -- DMA Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DMA_Peripheral_Access_Layer DMA Peripheral Access Layer
 * @{
 */

/** DMA - Size of Registers Arrays */

/** DMA - Register Layout Typedef */
#define DMA_UMO_COUNT 4

typedef struct {

  __IO uint32_t CR                            ; /* Control Register, offset: 0x0 */
  __I  uint32_t ES                            ; /* Error Status Register, offset: 0x4 */
       uint8_t  RESERVED_0[4];
  __IO uint32_t ERQ                           ; /* Enable Request Register, offset: 0xC */
       uint8_t  RESERVED_1[4];
  __IO uint32_t EEI                           ; /* Enable Error Interrupt Register, offset: 0x14 */
  __O  uint8_t  CEEI                          ; /* Clear Enable Error Interrupt Register, offset: 0x18 */
  __O  uint8_t  SEEI                          ; /* Set Enable Error Interrupt Register, offset: 0x19 */
  __O  uint8_t  CERQ                          ; /* Clear Enable Request Register, offset: 0x1A */
  __O  uint8_t  SERQ                          ; /* Set Enable Request Register, offset: 0x1B */
  __O  uint8_t  CDNE                          ; /* Clear DONE Status Bit Register, offset: 0x1C */
  __O  uint8_t  SSRT                          ; /* Set START Bit Register, offset: 0x1D */
  __O  uint8_t  CERR                          ; /* Clear Error Register, offset: 0x1E */
  __O  uint8_t  CINT                          ; /* Clear Interrupt Request Register, offset: 0x1F */
       uint8_t  RESERVED_2[4];
  __IO uint32_t INT                           ; /* Interrupt Request Register, offset: 0x24 */
       uint8_t  RESERVED_3[4];
  __IO uint32_t ERR                           ; /* Error Register, offset: 0x2C */
       uint8_t  RESERVED_4[4];
  __I  uint32_t HRS                           ; /* Hardware Request Status Register, offset: 0x34 */
       uint8_t  RESERVED_5[16];
  __IO uint32_t UME[2]                          ; /* Unaligned Modulo Enable Register 0, offset: 0x48 */
  __IO uint32_t UMO[DMA_UMO_COUNT]            ; /* Unaligned Modulo N Offset Register, offset: 0x50 */
       uint8_t  RESERVED_6[160];
  __IO uint8_t  CHPRI[32]                        ; /* Channel Priority Register, offset: 0x100 */
       uint8_t  RESERVED_7[3808];

  struct {                                      /* offset: 0x1000, array step: 0x20 */
    __IO uint32_t SADDR                       ; /* CFG Source Address, array offset: 0x1000, array step: 0x20 */
    __IO uint16_t SOFF                        ; /* CFG Signed Source Address Offset, array offset: 0x1004, array step: 0x20 */
    __IO uint16_t ATTR                        ; /* CFG Transfer Attributes, array offset: 0x1006, array step: 0x20 */
    union {                                     /* offset: 0x1008, array step: 0x20 */
      __IO uint32_t ILNO                      ; /* CFG Inner Byte Transfer Count (Inner Loop Mapping Disabled), array offset: 0x1008, array step: 0x20 */
      __IO uint32_t ILOFFNO                   ; /* CFG Signed Inner Loop Offset (Inner Loop Mapping Enabled and Offset Disabled), array offset: 0x1008, array step: 0x20 */
      __IO uint32_t ILOFFYES                  ; /* CFG Signed Inner Loop Offset (Inner Loop Mapping and Offset Enabled), array offset: 0x1008, array step: 0x20 */
    } NBYTES;
    __IO uint32_t SLAST                       ; /* CFG Last Source Address Adjustment, array offset: 0x100C, array step: 0x20 */
    __IO uint32_t DADDR                       ; /* CFG Destination Address, array offset: 0x1010, array step: 0x20 */
    __IO uint16_t DOFF                        ; /* CFG Signed Destination Address Offset, array offset: 0x1014, array step: 0x20 */
    union {                                     /* offset: 0x1016, array step: 0x20 */
      __IO uint16_t CHTRGENNO                 ; /* CFG Current Inner Loop Trig, Outer Loop Count (Channel Trig Disabled), array offset: 0x1016, array step: 0x20 */
      __IO uint16_t CHTRGENYES                ; /* CFG Current Inner Loop Trig, Outer Loop Count (Channel Trig Enabled), array offset: 0x1016, array step: 0x20 */
    } CLC;
    __IO uint32_t DLAST                       ; /* CFG Last Destination Address Adjustment, array offset: 0x1018, array step: 0x20 */
    __IO uint16_t CSR                         ; /* CFG Control and Status, array offset: 0x101C, array step: 0x20 */
    union {                                     /* offset: 0x101E, array step: 0x20 */
      __IO uint16_t CHTRGENNO                 ; /* CFG Beginning Inner Loop Trig, Outer Loop Count (Channel Trig Disabled), array offset: 0x101E, array step: 0x20 */
      __IO uint16_t CHTRGENYES                ; /* CFG Beginning Inner Loop Trig, Outer Loop Count (Channel Trig Enabled), array offset: 0x101E, array step: 0x20 */
    } BLC;
  } CFG[32];
       uint8_t  RESERVED_8[128];
  __I  uint32_t MON_ERR_STATUS                ; /* Monitor Error Status Register, offset: 0x1480 */
  __IO uint32_t MON_FAKE_SRC_ADDR             ; /* Monitor Fake Source Address Register, offset: 0x1484 */
  __IO uint32_t MON_FAKE_DST_ADDR             ; /* Monitor Fake Destination Address Register, offset: 0x1488 */
  __IO uint32_t MON_CTRL                      ; /* Monitor Control Register, offset: 0x148C */

} DMA_Type, *DMA_MemMapPtr;


/* DMA - Peripheral instance base addresses */
/** Peripheral DMA0 base address */
#define DMA0_BASE                                (0x40008000u)
/** Peripheral DMA0 base pointer */
#define DMA0                                     ((DMA_Type *)DMA0_BASE)
/** Peripheral DMA1 base address */
#define DMA1_BASE                                (0x40408000u)
/** Peripheral DMA1 base pointer */
#define DMA1                                     ((DMA_Type *)DMA1_BASE)
// need fill by yourself
///** Number of interrupt vector arrays for the DMA module. */
//#define DMA_IRQS_ARR_COUNT                       (1u)
///** Number of interrupt channels for the DMA module. */
//#define DMA_IRQS_CH_COUNT                        (1u)
///** Interrupt vectors for the DMA peripheral type */
//#define DMA_IRQS                                 {DMA0_IRQn, DMA1_IRQn}


/* ----------------------------------------------------------------------------
   -- DMA Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DMA_Register_Masks DMA Register Masks
 * @{
 */

/* CR Bit Fields */
#define DMA_CR_CX_MASK                 0x20000u
#define DMA_CR_CX_SHIFT                17u
#define DMA_CR_CX_WIDTH                1u
#define DMA_CR_CX(x)                   (((uint32_t)(((uint32_t)(x))<<DMA_CR_CX_SHIFT))&DMA_CR_CX_MASK)
#define DMA_CR_ECX_MASK                0x10000u
#define DMA_CR_ECX_SHIFT               16u
#define DMA_CR_ECX_WIDTH               1u
#define DMA_CR_ECX(x)                  (((uint32_t)(((uint32_t)(x))<<DMA_CR_ECX_SHIFT))&DMA_CR_ECX_MASK)
#define DMA_CR_GRP1PRI_MASK            0x400u
#define DMA_CR_GRP1PRI_SHIFT           10u
#define DMA_CR_GRP1PRI_WIDTH           1u
#define DMA_CR_GRP1PRI(x)              (((uint32_t)(((uint32_t)(x))<<DMA_CR_GRP1PRI_SHIFT))&DMA_CR_GRP1PRI_MASK)
#define DMA_CR_GPR0PRI_MASK            0x100u
#define DMA_CR_GPR0PRI_SHIFT           8u
#define DMA_CR_GPR0PRI_WIDTH           1u
#define DMA_CR_GPR0PRI(x)              (((uint32_t)(((uint32_t)(x))<<DMA_CR_GPR0PRI_SHIFT))&DMA_CR_GPR0PRI_MASK)
#define DMA_CR_EILM_MASK               0x80u
#define DMA_CR_EILM_SHIFT              7u
#define DMA_CR_EILM_WIDTH              1u
#define DMA_CR_EILM(x)                 (((uint32_t)(((uint32_t)(x))<<DMA_CR_EILM_SHIFT))&DMA_CR_EILM_MASK)
#define DMA_CR_CTM_MASK                0x40u
#define DMA_CR_CTM_SHIFT               6u
#define DMA_CR_CTM_WIDTH               1u
#define DMA_CR_CTM(x)                  (((uint32_t)(((uint32_t)(x))<<DMA_CR_CTM_SHIFT))&DMA_CR_CTM_MASK)
#define DMA_CR_HALT_MASK               0x20u
#define DMA_CR_HALT_SHIFT              5u
#define DMA_CR_HALT_WIDTH              1u
#define DMA_CR_HALT(x)                 (((uint32_t)(((uint32_t)(x))<<DMA_CR_HALT_SHIFT))&DMA_CR_HALT_MASK)
#define DMA_CR_HOE_MASK                0x10u
#define DMA_CR_HOE_SHIFT               4u
#define DMA_CR_HOE_WIDTH               1u
#define DMA_CR_HOE(x)                  (((uint32_t)(((uint32_t)(x))<<DMA_CR_HOE_SHIFT))&DMA_CR_HOE_MASK)
#define DMA_CR_ERCA_MASK               0x4u
#define DMA_CR_ERCA_SHIFT              2u
#define DMA_CR_ERCA_WIDTH              1u
#define DMA_CR_ERCA(x)                 (((uint32_t)(((uint32_t)(x))<<DMA_CR_ERCA_SHIFT))&DMA_CR_ERCA_MASK)
#define DMA_CR_DBGS_MASK               0x2u
#define DMA_CR_DBGS_SHIFT              1u
#define DMA_CR_DBGS_WIDTH              1u
#define DMA_CR_DBGS(x)                 (((uint32_t)(((uint32_t)(x))<<DMA_CR_DBGS_SHIFT))&DMA_CR_DBGS_MASK)
/* CR Reg Mask */
#define DMA_CR_MASK                    0x000305F6u

/* ES Bit Fields */
#define DMA_ES_VLD_MASK                0x80000000u
#define DMA_ES_VLD_SHIFT               31u
#define DMA_ES_VLD_WIDTH               1u
#define DMA_ES_VLD(x)                  (((uint32_t)(((uint32_t)(x))<<DMA_ES_VLD_SHIFT))&DMA_ES_VLD_MASK)
#define DMA_ES_ECX_MASK                0x10000u
#define DMA_ES_ECX_SHIFT               16u
#define DMA_ES_ECX_WIDTH               1u
#define DMA_ES_ECX(x)                  (((uint32_t)(((uint32_t)(x))<<DMA_ES_ECX_SHIFT))&DMA_ES_ECX_MASK)
#define DMA_ES_GPE_MASK                0x8000u
#define DMA_ES_GPE_SHIFT               15u
#define DMA_ES_GPE_WIDTH               1u
#define DMA_ES_GPE(x)                  (((uint32_t)(((uint32_t)(x))<<DMA_ES_GPE_SHIFT))&DMA_ES_GPE_MASK)
#define DMA_ES_CPE_MASK                0x4000u
#define DMA_ES_CPE_SHIFT               14u
#define DMA_ES_CPE_WIDTH               1u
#define DMA_ES_CPE(x)                  (((uint32_t)(((uint32_t)(x))<<DMA_ES_CPE_SHIFT))&DMA_ES_CPE_MASK)
#define DMA_ES_ERRCHN_MASK             0x1F00u
#define DMA_ES_ERRCHN_SHIFT            8u
#define DMA_ES_ERRCHN_WIDTH            5u
#define DMA_ES_ERRCHN(x)               (((uint32_t)(((uint32_t)(x))<<DMA_ES_ERRCHN_SHIFT))&DMA_ES_ERRCHN_MASK)
#define DMA_ES_SAE_MASK                0x80u
#define DMA_ES_SAE_SHIFT               7u
#define DMA_ES_SAE_WIDTH               1u
#define DMA_ES_SAE(x)                  (((uint32_t)(((uint32_t)(x))<<DMA_ES_SAE_SHIFT))&DMA_ES_SAE_MASK)
#define DMA_ES_SOE_MASK                0x40u
#define DMA_ES_SOE_SHIFT               6u
#define DMA_ES_SOE_WIDTH               1u
#define DMA_ES_SOE(x)                  (((uint32_t)(((uint32_t)(x))<<DMA_ES_SOE_SHIFT))&DMA_ES_SOE_MASK)
#define DMA_ES_DAE_MASK                0x20u
#define DMA_ES_DAE_SHIFT               5u
#define DMA_ES_DAE_WIDTH               1u
#define DMA_ES_DAE(x)                  (((uint32_t)(((uint32_t)(x))<<DMA_ES_DAE_SHIFT))&DMA_ES_DAE_MASK)
#define DMA_ES_DOE_MASK                0x10u
#define DMA_ES_DOE_SHIFT               4u
#define DMA_ES_DOE_WIDTH               1u
#define DMA_ES_DOE(x)                  (((uint32_t)(((uint32_t)(x))<<DMA_ES_DOE_SHIFT))&DMA_ES_DOE_MASK)
#define DMA_ES_NCE_MASK                0x8u
#define DMA_ES_NCE_SHIFT               3u
#define DMA_ES_NCE_WIDTH               1u
#define DMA_ES_NCE(x)                  (((uint32_t)(((uint32_t)(x))<<DMA_ES_NCE_SHIFT))&DMA_ES_NCE_MASK)
#define DMA_ES_SBE_MASK                0x2u
#define DMA_ES_SBE_SHIFT               1u
#define DMA_ES_SBE_WIDTH               1u
#define DMA_ES_SBE(x)                  (((uint32_t)(((uint32_t)(x))<<DMA_ES_SBE_SHIFT))&DMA_ES_SBE_MASK)
#define DMA_ES_DBE_MASK                0x1u
#define DMA_ES_DBE_SHIFT               0u
#define DMA_ES_DBE_WIDTH               1u
#define DMA_ES_DBE(x)                  (((uint32_t)(((uint32_t)(x))<<DMA_ES_DBE_SHIFT))&DMA_ES_DBE_MASK)
/* ES Reg Mask */
#define DMA_ES_MASK                    0x8001DFFBu

/* ERQ Bit Fields */
#define DMA_ERQ_ERQ31_MASK             0x80000000u
#define DMA_ERQ_ERQ31_SHIFT            31u
#define DMA_ERQ_ERQ31_WIDTH            1u
#define DMA_ERQ_ERQ31(x)               (((uint32_t)(((uint32_t)(x))<<DMA_ERQ_ERQ31_SHIFT))&DMA_ERQ_ERQ31_MASK)
#define DMA_ERQ_ERQ30_MASK             0x40000000u
#define DMA_ERQ_ERQ30_SHIFT            30u
#define DMA_ERQ_ERQ30_WIDTH            1u
#define DMA_ERQ_ERQ30(x)               (((uint32_t)(((uint32_t)(x))<<DMA_ERQ_ERQ30_SHIFT))&DMA_ERQ_ERQ30_MASK)
#define DMA_ERQ_ERQ29_MASK             0x20000000u
#define DMA_ERQ_ERQ29_SHIFT            29u
#define DMA_ERQ_ERQ29_WIDTH            1u
#define DMA_ERQ_ERQ29(x)               (((uint32_t)(((uint32_t)(x))<<DMA_ERQ_ERQ29_SHIFT))&DMA_ERQ_ERQ29_MASK)
#define DMA_ERQ_ERQ28_MASK             0x10000000u
#define DMA_ERQ_ERQ28_SHIFT            28u
#define DMA_ERQ_ERQ28_WIDTH            1u
#define DMA_ERQ_ERQ28(x)               (((uint32_t)(((uint32_t)(x))<<DMA_ERQ_ERQ28_SHIFT))&DMA_ERQ_ERQ28_MASK)
#define DMA_ERQ_ERQ27_MASK             0x8000000u
#define DMA_ERQ_ERQ27_SHIFT            27u
#define DMA_ERQ_ERQ27_WIDTH            1u
#define DMA_ERQ_ERQ27(x)               (((uint32_t)(((uint32_t)(x))<<DMA_ERQ_ERQ27_SHIFT))&DMA_ERQ_ERQ27_MASK)
#define DMA_ERQ_ERQ26_MASK             0x4000000u
#define DMA_ERQ_ERQ26_SHIFT            26u
#define DMA_ERQ_ERQ26_WIDTH            1u
#define DMA_ERQ_ERQ26(x)               (((uint32_t)(((uint32_t)(x))<<DMA_ERQ_ERQ26_SHIFT))&DMA_ERQ_ERQ26_MASK)
#define DMA_ERQ_ERQ25_MASK             0x2000000u
#define DMA_ERQ_ERQ25_SHIFT            25u
#define DMA_ERQ_ERQ25_WIDTH            1u
#define DMA_ERQ_ERQ25(x)               (((uint32_t)(((uint32_t)(x))<<DMA_ERQ_ERQ25_SHIFT))&DMA_ERQ_ERQ25_MASK)
#define DMA_ERQ_ERQ24_MASK             0x1000000u
#define DMA_ERQ_ERQ24_SHIFT            24u
#define DMA_ERQ_ERQ24_WIDTH            1u
#define DMA_ERQ_ERQ24(x)               (((uint32_t)(((uint32_t)(x))<<DMA_ERQ_ERQ24_SHIFT))&DMA_ERQ_ERQ24_MASK)
#define DMA_ERQ_ERQ23_MASK             0x800000u
#define DMA_ERQ_ERQ23_SHIFT            23u
#define DMA_ERQ_ERQ23_WIDTH            1u
#define DMA_ERQ_ERQ23(x)               (((uint32_t)(((uint32_t)(x))<<DMA_ERQ_ERQ23_SHIFT))&DMA_ERQ_ERQ23_MASK)
#define DMA_ERQ_ERQ22_MASK             0x400000u
#define DMA_ERQ_ERQ22_SHIFT            22u
#define DMA_ERQ_ERQ22_WIDTH            1u
#define DMA_ERQ_ERQ22(x)               (((uint32_t)(((uint32_t)(x))<<DMA_ERQ_ERQ22_SHIFT))&DMA_ERQ_ERQ22_MASK)
#define DMA_ERQ_ERQ21_MASK             0x200000u
#define DMA_ERQ_ERQ21_SHIFT            21u
#define DMA_ERQ_ERQ21_WIDTH            1u
#define DMA_ERQ_ERQ21(x)               (((uint32_t)(((uint32_t)(x))<<DMA_ERQ_ERQ21_SHIFT))&DMA_ERQ_ERQ21_MASK)
#define DMA_ERQ_ERQ20_MASK             0x100000u
#define DMA_ERQ_ERQ20_SHIFT            20u
#define DMA_ERQ_ERQ20_WIDTH            1u
#define DMA_ERQ_ERQ20(x)               (((uint32_t)(((uint32_t)(x))<<DMA_ERQ_ERQ20_SHIFT))&DMA_ERQ_ERQ20_MASK)
#define DMA_ERQ_ERQ19_MASK             0x80000u
#define DMA_ERQ_ERQ19_SHIFT            19u
#define DMA_ERQ_ERQ19_WIDTH            1u
#define DMA_ERQ_ERQ19(x)               (((uint32_t)(((uint32_t)(x))<<DMA_ERQ_ERQ19_SHIFT))&DMA_ERQ_ERQ19_MASK)
#define DMA_ERQ_ERQ18_MASK             0x40000u
#define DMA_ERQ_ERQ18_SHIFT            18u
#define DMA_ERQ_ERQ18_WIDTH            1u
#define DMA_ERQ_ERQ18(x)               (((uint32_t)(((uint32_t)(x))<<DMA_ERQ_ERQ18_SHIFT))&DMA_ERQ_ERQ18_MASK)
#define DMA_ERQ_ERQ17_MASK             0x20000u
#define DMA_ERQ_ERQ17_SHIFT            17u
#define DMA_ERQ_ERQ17_WIDTH            1u
#define DMA_ERQ_ERQ17(x)               (((uint32_t)(((uint32_t)(x))<<DMA_ERQ_ERQ17_SHIFT))&DMA_ERQ_ERQ17_MASK)
#define DMA_ERQ_ERQ16_MASK             0x10000u
#define DMA_ERQ_ERQ16_SHIFT            16u
#define DMA_ERQ_ERQ16_WIDTH            1u
#define DMA_ERQ_ERQ16(x)               (((uint32_t)(((uint32_t)(x))<<DMA_ERQ_ERQ16_SHIFT))&DMA_ERQ_ERQ16_MASK)
#define DMA_ERQ_ERQ15_MASK             0x8000u
#define DMA_ERQ_ERQ15_SHIFT            15u
#define DMA_ERQ_ERQ15_WIDTH            1u
#define DMA_ERQ_ERQ15(x)               (((uint32_t)(((uint32_t)(x))<<DMA_ERQ_ERQ15_SHIFT))&DMA_ERQ_ERQ15_MASK)
#define DMA_ERQ_ERQ14_MASK             0x4000u
#define DMA_ERQ_ERQ14_SHIFT            14u
#define DMA_ERQ_ERQ14_WIDTH            1u
#define DMA_ERQ_ERQ14(x)               (((uint32_t)(((uint32_t)(x))<<DMA_ERQ_ERQ14_SHIFT))&DMA_ERQ_ERQ14_MASK)
#define DMA_ERQ_ERQ13_MASK             0x2000u
#define DMA_ERQ_ERQ13_SHIFT            13u
#define DMA_ERQ_ERQ13_WIDTH            1u
#define DMA_ERQ_ERQ13(x)               (((uint32_t)(((uint32_t)(x))<<DMA_ERQ_ERQ13_SHIFT))&DMA_ERQ_ERQ13_MASK)
#define DMA_ERQ_ERQ12_MASK             0x1000u
#define DMA_ERQ_ERQ12_SHIFT            12u
#define DMA_ERQ_ERQ12_WIDTH            1u
#define DMA_ERQ_ERQ12(x)               (((uint32_t)(((uint32_t)(x))<<DMA_ERQ_ERQ12_SHIFT))&DMA_ERQ_ERQ12_MASK)
#define DMA_ERQ_ERQ11_MASK             0x800u
#define DMA_ERQ_ERQ11_SHIFT            11u
#define DMA_ERQ_ERQ11_WIDTH            1u
#define DMA_ERQ_ERQ11(x)               (((uint32_t)(((uint32_t)(x))<<DMA_ERQ_ERQ11_SHIFT))&DMA_ERQ_ERQ11_MASK)
#define DMA_ERQ_ERQ10_MASK             0x400u
#define DMA_ERQ_ERQ10_SHIFT            10u
#define DMA_ERQ_ERQ10_WIDTH            1u
#define DMA_ERQ_ERQ10(x)               (((uint32_t)(((uint32_t)(x))<<DMA_ERQ_ERQ10_SHIFT))&DMA_ERQ_ERQ10_MASK)
#define DMA_ERQ_ERQ9_MASK              0x200u
#define DMA_ERQ_ERQ9_SHIFT             9u
#define DMA_ERQ_ERQ9_WIDTH             1u
#define DMA_ERQ_ERQ9(x)                (((uint32_t)(((uint32_t)(x))<<DMA_ERQ_ERQ9_SHIFT))&DMA_ERQ_ERQ9_MASK)
#define DMA_ERQ_ERQ8_MASK              0x100u
#define DMA_ERQ_ERQ8_SHIFT             8u
#define DMA_ERQ_ERQ8_WIDTH             1u
#define DMA_ERQ_ERQ8(x)                (((uint32_t)(((uint32_t)(x))<<DMA_ERQ_ERQ8_SHIFT))&DMA_ERQ_ERQ8_MASK)
#define DMA_ERQ_ERQ7_MASK              0x80u
#define DMA_ERQ_ERQ7_SHIFT             7u
#define DMA_ERQ_ERQ7_WIDTH             1u
#define DMA_ERQ_ERQ7(x)                (((uint32_t)(((uint32_t)(x))<<DMA_ERQ_ERQ7_SHIFT))&DMA_ERQ_ERQ7_MASK)
#define DMA_ERQ_ERQ6_MASK              0x40u
#define DMA_ERQ_ERQ6_SHIFT             6u
#define DMA_ERQ_ERQ6_WIDTH             1u
#define DMA_ERQ_ERQ6(x)                (((uint32_t)(((uint32_t)(x))<<DMA_ERQ_ERQ6_SHIFT))&DMA_ERQ_ERQ6_MASK)
#define DMA_ERQ_ERQ5_MASK              0x20u
#define DMA_ERQ_ERQ5_SHIFT             5u
#define DMA_ERQ_ERQ5_WIDTH             1u
#define DMA_ERQ_ERQ5(x)                (((uint32_t)(((uint32_t)(x))<<DMA_ERQ_ERQ5_SHIFT))&DMA_ERQ_ERQ5_MASK)
#define DMA_ERQ_ERQ4_MASK              0x10u
#define DMA_ERQ_ERQ4_SHIFT             4u
#define DMA_ERQ_ERQ4_WIDTH             1u
#define DMA_ERQ_ERQ4(x)                (((uint32_t)(((uint32_t)(x))<<DMA_ERQ_ERQ4_SHIFT))&DMA_ERQ_ERQ4_MASK)
#define DMA_ERQ_ERQ3_MASK              0x8u
#define DMA_ERQ_ERQ3_SHIFT             3u
#define DMA_ERQ_ERQ3_WIDTH             1u
#define DMA_ERQ_ERQ3(x)                (((uint32_t)(((uint32_t)(x))<<DMA_ERQ_ERQ3_SHIFT))&DMA_ERQ_ERQ3_MASK)
#define DMA_ERQ_ERQ2_MASK              0x4u
#define DMA_ERQ_ERQ2_SHIFT             2u
#define DMA_ERQ_ERQ2_WIDTH             1u
#define DMA_ERQ_ERQ2(x)                (((uint32_t)(((uint32_t)(x))<<DMA_ERQ_ERQ2_SHIFT))&DMA_ERQ_ERQ2_MASK)
#define DMA_ERQ_ERQ1_MASK              0x2u
#define DMA_ERQ_ERQ1_SHIFT             1u
#define DMA_ERQ_ERQ1_WIDTH             1u
#define DMA_ERQ_ERQ1(x)                (((uint32_t)(((uint32_t)(x))<<DMA_ERQ_ERQ1_SHIFT))&DMA_ERQ_ERQ1_MASK)
#define DMA_ERQ_ERQ0_MASK              0x1u
#define DMA_ERQ_ERQ0_SHIFT             0u
#define DMA_ERQ_ERQ0_WIDTH             1u
#define DMA_ERQ_ERQ0(x)                (((uint32_t)(((uint32_t)(x))<<DMA_ERQ_ERQ0_SHIFT))&DMA_ERQ_ERQ0_MASK)
/* ERQ Reg Mask */
#define DMA_ERQ_MASK                   0xFFFFFFFFu

/* EEI Bit Fields */
#define DMA_EEI_EEI31_MASK             0x80000000u
#define DMA_EEI_EEI31_SHIFT            31u
#define DMA_EEI_EEI31_WIDTH            1u
#define DMA_EEI_EEI31(x)               (((uint32_t)(((uint32_t)(x))<<DMA_EEI_EEI31_SHIFT))&DMA_EEI_EEI31_MASK)
#define DMA_EEI_EEI30_MASK             0x40000000u
#define DMA_EEI_EEI30_SHIFT            30u
#define DMA_EEI_EEI30_WIDTH            1u
#define DMA_EEI_EEI30(x)               (((uint32_t)(((uint32_t)(x))<<DMA_EEI_EEI30_SHIFT))&DMA_EEI_EEI30_MASK)
#define DMA_EEI_EEI29_MASK             0x20000000u
#define DMA_EEI_EEI29_SHIFT            29u
#define DMA_EEI_EEI29_WIDTH            1u
#define DMA_EEI_EEI29(x)               (((uint32_t)(((uint32_t)(x))<<DMA_EEI_EEI29_SHIFT))&DMA_EEI_EEI29_MASK)
#define DMA_EEI_EEI28_MASK             0x10000000u
#define DMA_EEI_EEI28_SHIFT            28u
#define DMA_EEI_EEI28_WIDTH            1u
#define DMA_EEI_EEI28(x)               (((uint32_t)(((uint32_t)(x))<<DMA_EEI_EEI28_SHIFT))&DMA_EEI_EEI28_MASK)
#define DMA_EEI_EEI27_MASK             0x8000000u
#define DMA_EEI_EEI27_SHIFT            27u
#define DMA_EEI_EEI27_WIDTH            1u
#define DMA_EEI_EEI27(x)               (((uint32_t)(((uint32_t)(x))<<DMA_EEI_EEI27_SHIFT))&DMA_EEI_EEI27_MASK)
#define DMA_EEI_EEI26_MASK             0x4000000u
#define DMA_EEI_EEI26_SHIFT            26u
#define DMA_EEI_EEI26_WIDTH            1u
#define DMA_EEI_EEI26(x)               (((uint32_t)(((uint32_t)(x))<<DMA_EEI_EEI26_SHIFT))&DMA_EEI_EEI26_MASK)
#define DMA_EEI_EEI25_MASK             0x2000000u
#define DMA_EEI_EEI25_SHIFT            25u
#define DMA_EEI_EEI25_WIDTH            1u
#define DMA_EEI_EEI25(x)               (((uint32_t)(((uint32_t)(x))<<DMA_EEI_EEI25_SHIFT))&DMA_EEI_EEI25_MASK)
#define DMA_EEI_EEI24_MASK             0x1000000u
#define DMA_EEI_EEI24_SHIFT            24u
#define DMA_EEI_EEI24_WIDTH            1u
#define DMA_EEI_EEI24(x)               (((uint32_t)(((uint32_t)(x))<<DMA_EEI_EEI24_SHIFT))&DMA_EEI_EEI24_MASK)
#define DMA_EEI_EEI23_MASK             0x800000u
#define DMA_EEI_EEI23_SHIFT            23u
#define DMA_EEI_EEI23_WIDTH            1u
#define DMA_EEI_EEI23(x)               (((uint32_t)(((uint32_t)(x))<<DMA_EEI_EEI23_SHIFT))&DMA_EEI_EEI23_MASK)
#define DMA_EEI_EEI22_MASK             0x400000u
#define DMA_EEI_EEI22_SHIFT            22u
#define DMA_EEI_EEI22_WIDTH            1u
#define DMA_EEI_EEI22(x)               (((uint32_t)(((uint32_t)(x))<<DMA_EEI_EEI22_SHIFT))&DMA_EEI_EEI22_MASK)
#define DMA_EEI_EEI21_MASK             0x200000u
#define DMA_EEI_EEI21_SHIFT            21u
#define DMA_EEI_EEI21_WIDTH            1u
#define DMA_EEI_EEI21(x)               (((uint32_t)(((uint32_t)(x))<<DMA_EEI_EEI21_SHIFT))&DMA_EEI_EEI21_MASK)
#define DMA_EEI_EEI20_MASK             0x100000u
#define DMA_EEI_EEI20_SHIFT            20u
#define DMA_EEI_EEI20_WIDTH            1u
#define DMA_EEI_EEI20(x)               (((uint32_t)(((uint32_t)(x))<<DMA_EEI_EEI20_SHIFT))&DMA_EEI_EEI20_MASK)
#define DMA_EEI_EEI19_MASK             0x80000u
#define DMA_EEI_EEI19_SHIFT            19u
#define DMA_EEI_EEI19_WIDTH            1u
#define DMA_EEI_EEI19(x)               (((uint32_t)(((uint32_t)(x))<<DMA_EEI_EEI19_SHIFT))&DMA_EEI_EEI19_MASK)
#define DMA_EEI_EEI18_MASK             0x40000u
#define DMA_EEI_EEI18_SHIFT            18u
#define DMA_EEI_EEI18_WIDTH            1u
#define DMA_EEI_EEI18(x)               (((uint32_t)(((uint32_t)(x))<<DMA_EEI_EEI18_SHIFT))&DMA_EEI_EEI18_MASK)
#define DMA_EEI_EEI17_MASK             0x20000u
#define DMA_EEI_EEI17_SHIFT            17u
#define DMA_EEI_EEI17_WIDTH            1u
#define DMA_EEI_EEI17(x)               (((uint32_t)(((uint32_t)(x))<<DMA_EEI_EEI17_SHIFT))&DMA_EEI_EEI17_MASK)
#define DMA_EEI_EEI16_MASK             0x10000u
#define DMA_EEI_EEI16_SHIFT            16u
#define DMA_EEI_EEI16_WIDTH            1u
#define DMA_EEI_EEI16(x)               (((uint32_t)(((uint32_t)(x))<<DMA_EEI_EEI16_SHIFT))&DMA_EEI_EEI16_MASK)
#define DMA_EEI_EEI15_MASK             0x8000u
#define DMA_EEI_EEI15_SHIFT            15u
#define DMA_EEI_EEI15_WIDTH            1u
#define DMA_EEI_EEI15(x)               (((uint32_t)(((uint32_t)(x))<<DMA_EEI_EEI15_SHIFT))&DMA_EEI_EEI15_MASK)
#define DMA_EEI_EEI14_MASK             0x4000u
#define DMA_EEI_EEI14_SHIFT            14u
#define DMA_EEI_EEI14_WIDTH            1u
#define DMA_EEI_EEI14(x)               (((uint32_t)(((uint32_t)(x))<<DMA_EEI_EEI14_SHIFT))&DMA_EEI_EEI14_MASK)
#define DMA_EEI_EEI13_MASK             0x2000u
#define DMA_EEI_EEI13_SHIFT            13u
#define DMA_EEI_EEI13_WIDTH            1u
#define DMA_EEI_EEI13(x)               (((uint32_t)(((uint32_t)(x))<<DMA_EEI_EEI13_SHIFT))&DMA_EEI_EEI13_MASK)
#define DMA_EEI_EEI12_MASK             0x1000u
#define DMA_EEI_EEI12_SHIFT            12u
#define DMA_EEI_EEI12_WIDTH            1u
#define DMA_EEI_EEI12(x)               (((uint32_t)(((uint32_t)(x))<<DMA_EEI_EEI12_SHIFT))&DMA_EEI_EEI12_MASK)
#define DMA_EEI_EEI11_MASK             0x800u
#define DMA_EEI_EEI11_SHIFT            11u
#define DMA_EEI_EEI11_WIDTH            1u
#define DMA_EEI_EEI11(x)               (((uint32_t)(((uint32_t)(x))<<DMA_EEI_EEI11_SHIFT))&DMA_EEI_EEI11_MASK)
#define DMA_EEI_EEI10_MASK             0x400u
#define DMA_EEI_EEI10_SHIFT            10u
#define DMA_EEI_EEI10_WIDTH            1u
#define DMA_EEI_EEI10(x)               (((uint32_t)(((uint32_t)(x))<<DMA_EEI_EEI10_SHIFT))&DMA_EEI_EEI10_MASK)
#define DMA_EEI_EEI9_MASK              0x200u
#define DMA_EEI_EEI9_SHIFT             9u
#define DMA_EEI_EEI9_WIDTH             1u
#define DMA_EEI_EEI9(x)                (((uint32_t)(((uint32_t)(x))<<DMA_EEI_EEI9_SHIFT))&DMA_EEI_EEI9_MASK)
#define DMA_EEI_EEI8_MASK              0x100u
#define DMA_EEI_EEI8_SHIFT             8u
#define DMA_EEI_EEI8_WIDTH             1u
#define DMA_EEI_EEI8(x)                (((uint32_t)(((uint32_t)(x))<<DMA_EEI_EEI8_SHIFT))&DMA_EEI_EEI8_MASK)
#define DMA_EEI_EEI7_MASK              0x80u
#define DMA_EEI_EEI7_SHIFT             7u
#define DMA_EEI_EEI7_WIDTH             1u
#define DMA_EEI_EEI7(x)                (((uint32_t)(((uint32_t)(x))<<DMA_EEI_EEI7_SHIFT))&DMA_EEI_EEI7_MASK)
#define DMA_EEI_EEI6_MASK              0x40u
#define DMA_EEI_EEI6_SHIFT             6u
#define DMA_EEI_EEI6_WIDTH             1u
#define DMA_EEI_EEI6(x)                (((uint32_t)(((uint32_t)(x))<<DMA_EEI_EEI6_SHIFT))&DMA_EEI_EEI6_MASK)
#define DMA_EEI_EEI5_MASK              0x20u
#define DMA_EEI_EEI5_SHIFT             5u
#define DMA_EEI_EEI5_WIDTH             1u
#define DMA_EEI_EEI5(x)                (((uint32_t)(((uint32_t)(x))<<DMA_EEI_EEI5_SHIFT))&DMA_EEI_EEI5_MASK)
#define DMA_EEI_EEI4_MASK              0x10u
#define DMA_EEI_EEI4_SHIFT             4u
#define DMA_EEI_EEI4_WIDTH             1u
#define DMA_EEI_EEI4(x)                (((uint32_t)(((uint32_t)(x))<<DMA_EEI_EEI4_SHIFT))&DMA_EEI_EEI4_MASK)
#define DMA_EEI_EEI3_MASK              0x8u
#define DMA_EEI_EEI3_SHIFT             3u
#define DMA_EEI_EEI3_WIDTH             1u
#define DMA_EEI_EEI3(x)                (((uint32_t)(((uint32_t)(x))<<DMA_EEI_EEI3_SHIFT))&DMA_EEI_EEI3_MASK)
#define DMA_EEI_EEI2_MASK              0x4u
#define DMA_EEI_EEI2_SHIFT             2u
#define DMA_EEI_EEI2_WIDTH             1u
#define DMA_EEI_EEI2(x)                (((uint32_t)(((uint32_t)(x))<<DMA_EEI_EEI2_SHIFT))&DMA_EEI_EEI2_MASK)
#define DMA_EEI_EEI1_MASK              0x2u
#define DMA_EEI_EEI1_SHIFT             1u
#define DMA_EEI_EEI1_WIDTH             1u
#define DMA_EEI_EEI1(x)                (((uint32_t)(((uint32_t)(x))<<DMA_EEI_EEI1_SHIFT))&DMA_EEI_EEI1_MASK)
#define DMA_EEI_EEI0_MASK              0x1u
#define DMA_EEI_EEI0_SHIFT             0u
#define DMA_EEI_EEI0_WIDTH             1u
#define DMA_EEI_EEI0(x)                (((uint32_t)(((uint32_t)(x))<<DMA_EEI_EEI0_SHIFT))&DMA_EEI_EEI0_MASK)
/* EEI Reg Mask */
#define DMA_EEI_MASK                   0xFFFFFFFFu

/* CEEI Bit Fields */
#define DMA_CEEI_NOP_MASK              0x80u
#define DMA_CEEI_NOP_SHIFT             7u
#define DMA_CEEI_NOP_WIDTH             1u
#define DMA_CEEI_NOP(x)                (((uint8_t)(((uint8_t)(x))<<DMA_CEEI_NOP_SHIFT))&DMA_CEEI_NOP_MASK)
#define DMA_CEEI_CAEE_MASK             0x40u
#define DMA_CEEI_CAEE_SHIFT            6u
#define DMA_CEEI_CAEE_WIDTH            1u
#define DMA_CEEI_CAEE(x)               (((uint8_t)(((uint8_t)(x))<<DMA_CEEI_CAEE_SHIFT))&DMA_CEEI_CAEE_MASK)
#define DMA_CEEI_CEEI_MASK             0x1Fu
#define DMA_CEEI_CEEI_SHIFT            0u
#define DMA_CEEI_CEEI_WIDTH            5u
#define DMA_CEEI_CEEI(x)               (((uint8_t)(((uint8_t)(x))<<DMA_CEEI_CEEI_SHIFT))&DMA_CEEI_CEEI_MASK)
/* CEEI Reg Mask */
#define DMA_CEEI_MASK                  0xDFu

/* SEEI Bit Fields */
#define DMA_SEEI_NOP_MASK              0x80u
#define DMA_SEEI_NOP_SHIFT             7u
#define DMA_SEEI_NOP_WIDTH             1u
#define DMA_SEEI_NOP(x)                (((uint8_t)(((uint8_t)(x))<<DMA_SEEI_NOP_SHIFT))&DMA_SEEI_NOP_MASK)
#define DMA_SEEI_SAEE_MASK             0x40u
#define DMA_SEEI_SAEE_SHIFT            6u
#define DMA_SEEI_SAEE_WIDTH            1u
#define DMA_SEEI_SAEE(x)               (((uint8_t)(((uint8_t)(x))<<DMA_SEEI_SAEE_SHIFT))&DMA_SEEI_SAEE_MASK)
#define DMA_SEEI_SEEI_MASK             0x1Fu
#define DMA_SEEI_SEEI_SHIFT            0u
#define DMA_SEEI_SEEI_WIDTH            5u
#define DMA_SEEI_SEEI(x)               (((uint8_t)(((uint8_t)(x))<<DMA_SEEI_SEEI_SHIFT))&DMA_SEEI_SEEI_MASK)
/* SEEI Reg Mask */
#define DMA_SEEI_MASK                  0xDFu

/* CERQ Bit Fields */
#define DMA_CERQ_NOP_MASK              0x80u
#define DMA_CERQ_NOP_SHIFT             7u
#define DMA_CERQ_NOP_WIDTH             1u
#define DMA_CERQ_NOP(x)                (((uint8_t)(((uint8_t)(x))<<DMA_CERQ_NOP_SHIFT))&DMA_CERQ_NOP_MASK)
#define DMA_CERQ_CAER_MASK             0x40u
#define DMA_CERQ_CAER_SHIFT            6u
#define DMA_CERQ_CAER_WIDTH            1u
#define DMA_CERQ_CAER(x)               (((uint8_t)(((uint8_t)(x))<<DMA_CERQ_CAER_SHIFT))&DMA_CERQ_CAER_MASK)
#define DMA_CERQ_CERQ_MASK             0x1Fu
#define DMA_CERQ_CERQ_SHIFT            0u
#define DMA_CERQ_CERQ_WIDTH            5u
#define DMA_CERQ_CERQ(x)               (((uint8_t)(((uint8_t)(x))<<DMA_CERQ_CERQ_SHIFT))&DMA_CERQ_CERQ_MASK)
/* CERQ Reg Mask */
#define DMA_CERQ_MASK                  0xDFu

/* SERQ Bit Fields */
#define DMA_SERQ_NOP_MASK              0x80u
#define DMA_SERQ_NOP_SHIFT             7u
#define DMA_SERQ_NOP_WIDTH             1u
#define DMA_SERQ_NOP(x)                (((uint8_t)(((uint8_t)(x))<<DMA_SERQ_NOP_SHIFT))&DMA_SERQ_NOP_MASK)
#define DMA_SERQ_SAER_MASK             0x40u
#define DMA_SERQ_SAER_SHIFT            6u
#define DMA_SERQ_SAER_WIDTH            1u
#define DMA_SERQ_SAER(x)               (((uint8_t)(((uint8_t)(x))<<DMA_SERQ_SAER_SHIFT))&DMA_SERQ_SAER_MASK)
#define DMA_SERQ_SERQ_MASK             0x1Fu
#define DMA_SERQ_SERQ_SHIFT            0u
#define DMA_SERQ_SERQ_WIDTH            5u
#define DMA_SERQ_SERQ(x)               (((uint8_t)(((uint8_t)(x))<<DMA_SERQ_SERQ_SHIFT))&DMA_SERQ_SERQ_MASK)
/* SERQ Reg Mask */
#define DMA_SERQ_MASK                  0xDFu

/* CDNE Bit Fields */
#define DMA_CDNE_NOP_MASK              0x80u
#define DMA_CDNE_NOP_SHIFT             7u
#define DMA_CDNE_NOP_WIDTH             1u
#define DMA_CDNE_NOP(x)                (((uint8_t)(((uint8_t)(x))<<DMA_CDNE_NOP_SHIFT))&DMA_CDNE_NOP_MASK)
#define DMA_CDNE_CADN_MASK             0x40u
#define DMA_CDNE_CADN_SHIFT            6u
#define DMA_CDNE_CADN_WIDTH            1u
#define DMA_CDNE_CADN(x)               (((uint8_t)(((uint8_t)(x))<<DMA_CDNE_CADN_SHIFT))&DMA_CDNE_CADN_MASK)
#define DMA_CDNE_CDNE_MASK             0x1Fu
#define DMA_CDNE_CDNE_SHIFT            0u
#define DMA_CDNE_CDNE_WIDTH            5u
#define DMA_CDNE_CDNE(x)               (((uint8_t)(((uint8_t)(x))<<DMA_CDNE_CDNE_SHIFT))&DMA_CDNE_CDNE_MASK)
/* CDNE Reg Mask */
#define DMA_CDNE_MASK                  0xDFu

/* SSRT Bit Fields */
#define DMA_SSRT_NOP_MASK              0x80u
#define DMA_SSRT_NOP_SHIFT             7u
#define DMA_SSRT_NOP_WIDTH             1u
#define DMA_SSRT_NOP(x)                (((uint8_t)(((uint8_t)(x))<<DMA_SSRT_NOP_SHIFT))&DMA_SSRT_NOP_MASK)
#define DMA_SSRT_SAST_MASK             0x40u
#define DMA_SSRT_SAST_SHIFT            6u
#define DMA_SSRT_SAST_WIDTH            1u
#define DMA_SSRT_SAST(x)               (((uint8_t)(((uint8_t)(x))<<DMA_SSRT_SAST_SHIFT))&DMA_SSRT_SAST_MASK)
#define DMA_SSRT_SSRT_MASK             0x1Fu
#define DMA_SSRT_SSRT_SHIFT            0u
#define DMA_SSRT_SSRT_WIDTH            5u
#define DMA_SSRT_SSRT(x)               (((uint8_t)(((uint8_t)(x))<<DMA_SSRT_SSRT_SHIFT))&DMA_SSRT_SSRT_MASK)
/* SSRT Reg Mask */
#define DMA_SSRT_MASK                  0xDFu

/* CERR Bit Fields */
#define DMA_CERR_NOP_MASK              0x80u
#define DMA_CERR_NOP_SHIFT             7u
#define DMA_CERR_NOP_WIDTH             1u
#define DMA_CERR_NOP(x)                (((uint8_t)(((uint8_t)(x))<<DMA_CERR_NOP_SHIFT))&DMA_CERR_NOP_MASK)
#define DMA_CERR_CAEI_MASK             0x40u
#define DMA_CERR_CAEI_SHIFT            6u
#define DMA_CERR_CAEI_WIDTH            1u
#define DMA_CERR_CAEI(x)               (((uint8_t)(((uint8_t)(x))<<DMA_CERR_CAEI_SHIFT))&DMA_CERR_CAEI_MASK)
#define DMA_CERR_CERR_MASK             0x1Fu
#define DMA_CERR_CERR_SHIFT            0u
#define DMA_CERR_CERR_WIDTH            5u
#define DMA_CERR_CERR(x)               (((uint8_t)(((uint8_t)(x))<<DMA_CERR_CERR_SHIFT))&DMA_CERR_CERR_MASK)
/* CERR Reg Mask */
#define DMA_CERR_MASK                  0xDFu

/* CINT Bit Fields */
#define DMA_CINT_NOP_MASK              0x80u
#define DMA_CINT_NOP_SHIFT             7u
#define DMA_CINT_NOP_WIDTH             1u
#define DMA_CINT_NOP(x)                (((uint8_t)(((uint8_t)(x))<<DMA_CINT_NOP_SHIFT))&DMA_CINT_NOP_MASK)
#define DMA_CINT_CAIR_MASK             0x40u
#define DMA_CINT_CAIR_SHIFT            6u
#define DMA_CINT_CAIR_WIDTH            1u
#define DMA_CINT_CAIR(x)               (((uint8_t)(((uint8_t)(x))<<DMA_CINT_CAIR_SHIFT))&DMA_CINT_CAIR_MASK)
#define DMA_CINT_CINT_MASK             0x1Fu
#define DMA_CINT_CINT_SHIFT            0u
#define DMA_CINT_CINT_WIDTH            5u
#define DMA_CINT_CINT(x)               (((uint8_t)(((uint8_t)(x))<<DMA_CINT_CINT_SHIFT))&DMA_CINT_CINT_MASK)
/* CINT Reg Mask */
#define DMA_CINT_MASK                  0xDFu

/* INT Bit Fields */
#define DMA_INT_INT31_MASK             0x80000000u
#define DMA_INT_INT31_SHIFT            31u
#define DMA_INT_INT31_WIDTH            1u
#define DMA_INT_INT31(x)               (((uint32_t)(((uint32_t)(x))<<DMA_INT_INT31_SHIFT))&DMA_INT_INT31_MASK)
#define DMA_INT_INT30_MASK             0x40000000u
#define DMA_INT_INT30_SHIFT            30u
#define DMA_INT_INT30_WIDTH            1u
#define DMA_INT_INT30(x)               (((uint32_t)(((uint32_t)(x))<<DMA_INT_INT30_SHIFT))&DMA_INT_INT30_MASK)
#define DMA_INT_INT29_MASK             0x20000000u
#define DMA_INT_INT29_SHIFT            29u
#define DMA_INT_INT29_WIDTH            1u
#define DMA_INT_INT29(x)               (((uint32_t)(((uint32_t)(x))<<DMA_INT_INT29_SHIFT))&DMA_INT_INT29_MASK)
#define DMA_INT_INT28_MASK             0x10000000u
#define DMA_INT_INT28_SHIFT            28u
#define DMA_INT_INT28_WIDTH            1u
#define DMA_INT_INT28(x)               (((uint32_t)(((uint32_t)(x))<<DMA_INT_INT28_SHIFT))&DMA_INT_INT28_MASK)
#define DMA_INT_INT27_MASK             0x8000000u
#define DMA_INT_INT27_SHIFT            27u
#define DMA_INT_INT27_WIDTH            1u
#define DMA_INT_INT27(x)               (((uint32_t)(((uint32_t)(x))<<DMA_INT_INT27_SHIFT))&DMA_INT_INT27_MASK)
#define DMA_INT_INT26_MASK             0x4000000u
#define DMA_INT_INT26_SHIFT            26u
#define DMA_INT_INT26_WIDTH            1u
#define DMA_INT_INT26(x)               (((uint32_t)(((uint32_t)(x))<<DMA_INT_INT26_SHIFT))&DMA_INT_INT26_MASK)
#define DMA_INT_INT25_MASK             0x2000000u
#define DMA_INT_INT25_SHIFT            25u
#define DMA_INT_INT25_WIDTH            1u
#define DMA_INT_INT25(x)               (((uint32_t)(((uint32_t)(x))<<DMA_INT_INT25_SHIFT))&DMA_INT_INT25_MASK)
#define DMA_INT_INT24_MASK             0x1000000u
#define DMA_INT_INT24_SHIFT            24u
#define DMA_INT_INT24_WIDTH            1u
#define DMA_INT_INT24(x)               (((uint32_t)(((uint32_t)(x))<<DMA_INT_INT24_SHIFT))&DMA_INT_INT24_MASK)
#define DMA_INT_INT23_MASK             0x800000u
#define DMA_INT_INT23_SHIFT            23u
#define DMA_INT_INT23_WIDTH            1u
#define DMA_INT_INT23(x)               (((uint32_t)(((uint32_t)(x))<<DMA_INT_INT23_SHIFT))&DMA_INT_INT23_MASK)
#define DMA_INT_INT22_MASK             0x400000u
#define DMA_INT_INT22_SHIFT            22u
#define DMA_INT_INT22_WIDTH            1u
#define DMA_INT_INT22(x)               (((uint32_t)(((uint32_t)(x))<<DMA_INT_INT22_SHIFT))&DMA_INT_INT22_MASK)
#define DMA_INT_INT21_MASK             0x200000u
#define DMA_INT_INT21_SHIFT            21u
#define DMA_INT_INT21_WIDTH            1u
#define DMA_INT_INT21(x)               (((uint32_t)(((uint32_t)(x))<<DMA_INT_INT21_SHIFT))&DMA_INT_INT21_MASK)
#define DMA_INT_INT20_MASK             0x100000u
#define DMA_INT_INT20_SHIFT            20u
#define DMA_INT_INT20_WIDTH            1u
#define DMA_INT_INT20(x)               (((uint32_t)(((uint32_t)(x))<<DMA_INT_INT20_SHIFT))&DMA_INT_INT20_MASK)
#define DMA_INT_INT19_MASK             0x80000u
#define DMA_INT_INT19_SHIFT            19u
#define DMA_INT_INT19_WIDTH            1u
#define DMA_INT_INT19(x)               (((uint32_t)(((uint32_t)(x))<<DMA_INT_INT19_SHIFT))&DMA_INT_INT19_MASK)
#define DMA_INT_INT18_MASK             0x40000u
#define DMA_INT_INT18_SHIFT            18u
#define DMA_INT_INT18_WIDTH            1u
#define DMA_INT_INT18(x)               (((uint32_t)(((uint32_t)(x))<<DMA_INT_INT18_SHIFT))&DMA_INT_INT18_MASK)
#define DMA_INT_INT17_MASK             0x20000u
#define DMA_INT_INT17_SHIFT            17u
#define DMA_INT_INT17_WIDTH            1u
#define DMA_INT_INT17(x)               (((uint32_t)(((uint32_t)(x))<<DMA_INT_INT17_SHIFT))&DMA_INT_INT17_MASK)
#define DMA_INT_INT16_MASK             0x10000u
#define DMA_INT_INT16_SHIFT            16u
#define DMA_INT_INT16_WIDTH            1u
#define DMA_INT_INT16(x)               (((uint32_t)(((uint32_t)(x))<<DMA_INT_INT16_SHIFT))&DMA_INT_INT16_MASK)
#define DMA_INT_INT15_MASK             0x8000u
#define DMA_INT_INT15_SHIFT            15u
#define DMA_INT_INT15_WIDTH            1u
#define DMA_INT_INT15(x)               (((uint32_t)(((uint32_t)(x))<<DMA_INT_INT15_SHIFT))&DMA_INT_INT15_MASK)
#define DMA_INT_INT14_MASK             0x4000u
#define DMA_INT_INT14_SHIFT            14u
#define DMA_INT_INT14_WIDTH            1u
#define DMA_INT_INT14(x)               (((uint32_t)(((uint32_t)(x))<<DMA_INT_INT14_SHIFT))&DMA_INT_INT14_MASK)
#define DMA_INT_INT13_MASK             0x2000u
#define DMA_INT_INT13_SHIFT            13u
#define DMA_INT_INT13_WIDTH            1u
#define DMA_INT_INT13(x)               (((uint32_t)(((uint32_t)(x))<<DMA_INT_INT13_SHIFT))&DMA_INT_INT13_MASK)
#define DMA_INT_INT12_MASK             0x1000u
#define DMA_INT_INT12_SHIFT            12u
#define DMA_INT_INT12_WIDTH            1u
#define DMA_INT_INT12(x)               (((uint32_t)(((uint32_t)(x))<<DMA_INT_INT12_SHIFT))&DMA_INT_INT12_MASK)
#define DMA_INT_INT11_MASK             0x800u
#define DMA_INT_INT11_SHIFT            11u
#define DMA_INT_INT11_WIDTH            1u
#define DMA_INT_INT11(x)               (((uint32_t)(((uint32_t)(x))<<DMA_INT_INT11_SHIFT))&DMA_INT_INT11_MASK)
#define DMA_INT_INT10_MASK             0x400u
#define DMA_INT_INT10_SHIFT            10u
#define DMA_INT_INT10_WIDTH            1u
#define DMA_INT_INT10(x)               (((uint32_t)(((uint32_t)(x))<<DMA_INT_INT10_SHIFT))&DMA_INT_INT10_MASK)
#define DMA_INT_INT9_MASK              0x200u
#define DMA_INT_INT9_SHIFT             9u
#define DMA_INT_INT9_WIDTH             1u
#define DMA_INT_INT9(x)                (((uint32_t)(((uint32_t)(x))<<DMA_INT_INT9_SHIFT))&DMA_INT_INT9_MASK)
#define DMA_INT_INT8_MASK              0x100u
#define DMA_INT_INT8_SHIFT             8u
#define DMA_INT_INT8_WIDTH             1u
#define DMA_INT_INT8(x)                (((uint32_t)(((uint32_t)(x))<<DMA_INT_INT8_SHIFT))&DMA_INT_INT8_MASK)
#define DMA_INT_INT7_MASK              0x80u
#define DMA_INT_INT7_SHIFT             7u
#define DMA_INT_INT7_WIDTH             1u
#define DMA_INT_INT7(x)                (((uint32_t)(((uint32_t)(x))<<DMA_INT_INT7_SHIFT))&DMA_INT_INT7_MASK)
#define DMA_INT_INT6_MASK              0x40u
#define DMA_INT_INT6_SHIFT             6u
#define DMA_INT_INT6_WIDTH             1u
#define DMA_INT_INT6(x)                (((uint32_t)(((uint32_t)(x))<<DMA_INT_INT6_SHIFT))&DMA_INT_INT6_MASK)
#define DMA_INT_INT5_MASK              0x20u
#define DMA_INT_INT5_SHIFT             5u
#define DMA_INT_INT5_WIDTH             1u
#define DMA_INT_INT5(x)                (((uint32_t)(((uint32_t)(x))<<DMA_INT_INT5_SHIFT))&DMA_INT_INT5_MASK)
#define DMA_INT_INT4_MASK              0x10u
#define DMA_INT_INT4_SHIFT             4u
#define DMA_INT_INT4_WIDTH             1u
#define DMA_INT_INT4(x)                (((uint32_t)(((uint32_t)(x))<<DMA_INT_INT4_SHIFT))&DMA_INT_INT4_MASK)
#define DMA_INT_INT3_MASK              0x8u
#define DMA_INT_INT3_SHIFT             3u
#define DMA_INT_INT3_WIDTH             1u
#define DMA_INT_INT3(x)                (((uint32_t)(((uint32_t)(x))<<DMA_INT_INT3_SHIFT))&DMA_INT_INT3_MASK)
#define DMA_INT_INT2_MASK              0x4u
#define DMA_INT_INT2_SHIFT             2u
#define DMA_INT_INT2_WIDTH             1u
#define DMA_INT_INT2(x)                (((uint32_t)(((uint32_t)(x))<<DMA_INT_INT2_SHIFT))&DMA_INT_INT2_MASK)
#define DMA_INT_INT1_MASK              0x2u
#define DMA_INT_INT1_SHIFT             1u
#define DMA_INT_INT1_WIDTH             1u
#define DMA_INT_INT1(x)                (((uint32_t)(((uint32_t)(x))<<DMA_INT_INT1_SHIFT))&DMA_INT_INT1_MASK)
#define DMA_INT_INT0_MASK              0x1u
#define DMA_INT_INT0_SHIFT             0u
#define DMA_INT_INT0_WIDTH             1u
#define DMA_INT_INT0(x)                (((uint32_t)(((uint32_t)(x))<<DMA_INT_INT0_SHIFT))&DMA_INT_INT0_MASK)
/* INT Reg Mask */
#define DMA_INT_MASK                   0xFFFFFFFFu

/* ERR Bit Fields */
#define DMA_ERR_ERR31_MASK             0x80000000u
#define DMA_ERR_ERR31_SHIFT            31u
#define DMA_ERR_ERR31_WIDTH            1u
#define DMA_ERR_ERR31(x)               (((uint32_t)(((uint32_t)(x))<<DMA_ERR_ERR31_SHIFT))&DMA_ERR_ERR31_MASK)
#define DMA_ERR_ERR30_MASK             0x40000000u
#define DMA_ERR_ERR30_SHIFT            30u
#define DMA_ERR_ERR30_WIDTH            1u
#define DMA_ERR_ERR30(x)               (((uint32_t)(((uint32_t)(x))<<DMA_ERR_ERR30_SHIFT))&DMA_ERR_ERR30_MASK)
#define DMA_ERR_ERR29_MASK             0x20000000u
#define DMA_ERR_ERR29_SHIFT            29u
#define DMA_ERR_ERR29_WIDTH            1u
#define DMA_ERR_ERR29(x)               (((uint32_t)(((uint32_t)(x))<<DMA_ERR_ERR29_SHIFT))&DMA_ERR_ERR29_MASK)
#define DMA_ERR_ERR28_MASK             0x10000000u
#define DMA_ERR_ERR28_SHIFT            28u
#define DMA_ERR_ERR28_WIDTH            1u
#define DMA_ERR_ERR28(x)               (((uint32_t)(((uint32_t)(x))<<DMA_ERR_ERR28_SHIFT))&DMA_ERR_ERR28_MASK)
#define DMA_ERR_ERR27_MASK             0x8000000u
#define DMA_ERR_ERR27_SHIFT            27u
#define DMA_ERR_ERR27_WIDTH            1u
#define DMA_ERR_ERR27(x)               (((uint32_t)(((uint32_t)(x))<<DMA_ERR_ERR27_SHIFT))&DMA_ERR_ERR27_MASK)
#define DMA_ERR_ERR26_MASK             0x4000000u
#define DMA_ERR_ERR26_SHIFT            26u
#define DMA_ERR_ERR26_WIDTH            1u
#define DMA_ERR_ERR26(x)               (((uint32_t)(((uint32_t)(x))<<DMA_ERR_ERR26_SHIFT))&DMA_ERR_ERR26_MASK)
#define DMA_ERR_ERR25_MASK             0x2000000u
#define DMA_ERR_ERR25_SHIFT            25u
#define DMA_ERR_ERR25_WIDTH            1u
#define DMA_ERR_ERR25(x)               (((uint32_t)(((uint32_t)(x))<<DMA_ERR_ERR25_SHIFT))&DMA_ERR_ERR25_MASK)
#define DMA_ERR_ERR24_MASK             0x1000000u
#define DMA_ERR_ERR24_SHIFT            24u
#define DMA_ERR_ERR24_WIDTH            1u
#define DMA_ERR_ERR24(x)               (((uint32_t)(((uint32_t)(x))<<DMA_ERR_ERR24_SHIFT))&DMA_ERR_ERR24_MASK)
#define DMA_ERR_ERR23_MASK             0x800000u
#define DMA_ERR_ERR23_SHIFT            23u
#define DMA_ERR_ERR23_WIDTH            1u
#define DMA_ERR_ERR23(x)               (((uint32_t)(((uint32_t)(x))<<DMA_ERR_ERR23_SHIFT))&DMA_ERR_ERR23_MASK)
#define DMA_ERR_ERR22_MASK             0x400000u
#define DMA_ERR_ERR22_SHIFT            22u
#define DMA_ERR_ERR22_WIDTH            1u
#define DMA_ERR_ERR22(x)               (((uint32_t)(((uint32_t)(x))<<DMA_ERR_ERR22_SHIFT))&DMA_ERR_ERR22_MASK)
#define DMA_ERR_ERR21_MASK             0x200000u
#define DMA_ERR_ERR21_SHIFT            21u
#define DMA_ERR_ERR21_WIDTH            1u
#define DMA_ERR_ERR21(x)               (((uint32_t)(((uint32_t)(x))<<DMA_ERR_ERR21_SHIFT))&DMA_ERR_ERR21_MASK)
#define DMA_ERR_ERR20_MASK             0x100000u
#define DMA_ERR_ERR20_SHIFT            20u
#define DMA_ERR_ERR20_WIDTH            1u
#define DMA_ERR_ERR20(x)               (((uint32_t)(((uint32_t)(x))<<DMA_ERR_ERR20_SHIFT))&DMA_ERR_ERR20_MASK)
#define DMA_ERR_ERR19_MASK             0x80000u
#define DMA_ERR_ERR19_SHIFT            19u
#define DMA_ERR_ERR19_WIDTH            1u
#define DMA_ERR_ERR19(x)               (((uint32_t)(((uint32_t)(x))<<DMA_ERR_ERR19_SHIFT))&DMA_ERR_ERR19_MASK)
#define DMA_ERR_ERR18_MASK             0x40000u
#define DMA_ERR_ERR18_SHIFT            18u
#define DMA_ERR_ERR18_WIDTH            1u
#define DMA_ERR_ERR18(x)               (((uint32_t)(((uint32_t)(x))<<DMA_ERR_ERR18_SHIFT))&DMA_ERR_ERR18_MASK)
#define DMA_ERR_ERR17_MASK             0x20000u
#define DMA_ERR_ERR17_SHIFT            17u
#define DMA_ERR_ERR17_WIDTH            1u
#define DMA_ERR_ERR17(x)               (((uint32_t)(((uint32_t)(x))<<DMA_ERR_ERR17_SHIFT))&DMA_ERR_ERR17_MASK)
#define DMA_ERR_ERR16_MASK             0x10000u
#define DMA_ERR_ERR16_SHIFT            16u
#define DMA_ERR_ERR16_WIDTH            1u
#define DMA_ERR_ERR16(x)               (((uint32_t)(((uint32_t)(x))<<DMA_ERR_ERR16_SHIFT))&DMA_ERR_ERR16_MASK)
#define DMA_ERR_ERR15_MASK             0x8000u
#define DMA_ERR_ERR15_SHIFT            15u
#define DMA_ERR_ERR15_WIDTH            1u
#define DMA_ERR_ERR15(x)               (((uint32_t)(((uint32_t)(x))<<DMA_ERR_ERR15_SHIFT))&DMA_ERR_ERR15_MASK)
#define DMA_ERR_ERR14_MASK             0x4000u
#define DMA_ERR_ERR14_SHIFT            14u
#define DMA_ERR_ERR14_WIDTH            1u
#define DMA_ERR_ERR14(x)               (((uint32_t)(((uint32_t)(x))<<DMA_ERR_ERR14_SHIFT))&DMA_ERR_ERR14_MASK)
#define DMA_ERR_ERR13_MASK             0x2000u
#define DMA_ERR_ERR13_SHIFT            13u
#define DMA_ERR_ERR13_WIDTH            1u
#define DMA_ERR_ERR13(x)               (((uint32_t)(((uint32_t)(x))<<DMA_ERR_ERR13_SHIFT))&DMA_ERR_ERR13_MASK)
#define DMA_ERR_ERR12_MASK             0x1000u
#define DMA_ERR_ERR12_SHIFT            12u
#define DMA_ERR_ERR12_WIDTH            1u
#define DMA_ERR_ERR12(x)               (((uint32_t)(((uint32_t)(x))<<DMA_ERR_ERR12_SHIFT))&DMA_ERR_ERR12_MASK)
#define DMA_ERR_ERR11_MASK             0x800u
#define DMA_ERR_ERR11_SHIFT            11u
#define DMA_ERR_ERR11_WIDTH            1u
#define DMA_ERR_ERR11(x)               (((uint32_t)(((uint32_t)(x))<<DMA_ERR_ERR11_SHIFT))&DMA_ERR_ERR11_MASK)
#define DMA_ERR_ERR10_MASK             0x400u
#define DMA_ERR_ERR10_SHIFT            10u
#define DMA_ERR_ERR10_WIDTH            1u
#define DMA_ERR_ERR10(x)               (((uint32_t)(((uint32_t)(x))<<DMA_ERR_ERR10_SHIFT))&DMA_ERR_ERR10_MASK)
#define DMA_ERR_ERR9_MASK              0x200u
#define DMA_ERR_ERR9_SHIFT             9u
#define DMA_ERR_ERR9_WIDTH             1u
#define DMA_ERR_ERR9(x)                (((uint32_t)(((uint32_t)(x))<<DMA_ERR_ERR9_SHIFT))&DMA_ERR_ERR9_MASK)
#define DMA_ERR_ERR8_MASK              0x100u
#define DMA_ERR_ERR8_SHIFT             8u
#define DMA_ERR_ERR8_WIDTH             1u
#define DMA_ERR_ERR8(x)                (((uint32_t)(((uint32_t)(x))<<DMA_ERR_ERR8_SHIFT))&DMA_ERR_ERR8_MASK)
#define DMA_ERR_ERR7_MASK              0x80u
#define DMA_ERR_ERR7_SHIFT             7u
#define DMA_ERR_ERR7_WIDTH             1u
#define DMA_ERR_ERR7(x)                (((uint32_t)(((uint32_t)(x))<<DMA_ERR_ERR7_SHIFT))&DMA_ERR_ERR7_MASK)
#define DMA_ERR_ERR6_MASK              0x40u
#define DMA_ERR_ERR6_SHIFT             6u
#define DMA_ERR_ERR6_WIDTH             1u
#define DMA_ERR_ERR6(x)                (((uint32_t)(((uint32_t)(x))<<DMA_ERR_ERR6_SHIFT))&DMA_ERR_ERR6_MASK)
#define DMA_ERR_ERR5_MASK              0x20u
#define DMA_ERR_ERR5_SHIFT             5u
#define DMA_ERR_ERR5_WIDTH             1u
#define DMA_ERR_ERR5(x)                (((uint32_t)(((uint32_t)(x))<<DMA_ERR_ERR5_SHIFT))&DMA_ERR_ERR5_MASK)
#define DMA_ERR_ERR4_MASK              0x10u
#define DMA_ERR_ERR4_SHIFT             4u
#define DMA_ERR_ERR4_WIDTH             1u
#define DMA_ERR_ERR4(x)                (((uint32_t)(((uint32_t)(x))<<DMA_ERR_ERR4_SHIFT))&DMA_ERR_ERR4_MASK)
#define DMA_ERR_ERR3_MASK              0x8u
#define DMA_ERR_ERR3_SHIFT             3u
#define DMA_ERR_ERR3_WIDTH             1u
#define DMA_ERR_ERR3(x)                (((uint32_t)(((uint32_t)(x))<<DMA_ERR_ERR3_SHIFT))&DMA_ERR_ERR3_MASK)
#define DMA_ERR_ERR2_MASK              0x4u
#define DMA_ERR_ERR2_SHIFT             2u
#define DMA_ERR_ERR2_WIDTH             1u
#define DMA_ERR_ERR2(x)                (((uint32_t)(((uint32_t)(x))<<DMA_ERR_ERR2_SHIFT))&DMA_ERR_ERR2_MASK)
#define DMA_ERR_ERR1_MASK              0x2u
#define DMA_ERR_ERR1_SHIFT             1u
#define DMA_ERR_ERR1_WIDTH             1u
#define DMA_ERR_ERR1(x)                (((uint32_t)(((uint32_t)(x))<<DMA_ERR_ERR1_SHIFT))&DMA_ERR_ERR1_MASK)
#define DMA_ERR_ERR0_MASK              0x1u
#define DMA_ERR_ERR0_SHIFT             0u
#define DMA_ERR_ERR0_WIDTH             1u
#define DMA_ERR_ERR0(x)                (((uint32_t)(((uint32_t)(x))<<DMA_ERR_ERR0_SHIFT))&DMA_ERR_ERR0_MASK)
/* ERR Reg Mask */
#define DMA_ERR_MASK                   0xFFFFFFFFu

/* HRS Bit Fields */
#define DMA_HRS_HRS31_MASK             0x80000000u
#define DMA_HRS_HRS31_SHIFT            31u
#define DMA_HRS_HRS31_WIDTH            1u
#define DMA_HRS_HRS31(x)               (((uint32_t)(((uint32_t)(x))<<DMA_HRS_HRS31_SHIFT))&DMA_HRS_HRS31_MASK)
#define DMA_HRS_HRS30_MASK             0x40000000u
#define DMA_HRS_HRS30_SHIFT            30u
#define DMA_HRS_HRS30_WIDTH            1u
#define DMA_HRS_HRS30(x)               (((uint32_t)(((uint32_t)(x))<<DMA_HRS_HRS30_SHIFT))&DMA_HRS_HRS30_MASK)
#define DMA_HRS_HRS29_MASK             0x20000000u
#define DMA_HRS_HRS29_SHIFT            29u
#define DMA_HRS_HRS29_WIDTH            1u
#define DMA_HRS_HRS29(x)               (((uint32_t)(((uint32_t)(x))<<DMA_HRS_HRS29_SHIFT))&DMA_HRS_HRS29_MASK)
#define DMA_HRS_HRS28_MASK             0x10000000u
#define DMA_HRS_HRS28_SHIFT            28u
#define DMA_HRS_HRS28_WIDTH            1u
#define DMA_HRS_HRS28(x)               (((uint32_t)(((uint32_t)(x))<<DMA_HRS_HRS28_SHIFT))&DMA_HRS_HRS28_MASK)
#define DMA_HRS_HRS27_MASK             0x8000000u
#define DMA_HRS_HRS27_SHIFT            27u
#define DMA_HRS_HRS27_WIDTH            1u
#define DMA_HRS_HRS27(x)               (((uint32_t)(((uint32_t)(x))<<DMA_HRS_HRS27_SHIFT))&DMA_HRS_HRS27_MASK)
#define DMA_HRS_HRS26_MASK             0x4000000u
#define DMA_HRS_HRS26_SHIFT            26u
#define DMA_HRS_HRS26_WIDTH            1u
#define DMA_HRS_HRS26(x)               (((uint32_t)(((uint32_t)(x))<<DMA_HRS_HRS26_SHIFT))&DMA_HRS_HRS26_MASK)
#define DMA_HRS_HRS25_MASK             0x2000000u
#define DMA_HRS_HRS25_SHIFT            25u
#define DMA_HRS_HRS25_WIDTH            1u
#define DMA_HRS_HRS25(x)               (((uint32_t)(((uint32_t)(x))<<DMA_HRS_HRS25_SHIFT))&DMA_HRS_HRS25_MASK)
#define DMA_HRS_HRS24_MASK             0x1000000u
#define DMA_HRS_HRS24_SHIFT            24u
#define DMA_HRS_HRS24_WIDTH            1u
#define DMA_HRS_HRS24(x)               (((uint32_t)(((uint32_t)(x))<<DMA_HRS_HRS24_SHIFT))&DMA_HRS_HRS24_MASK)
#define DMA_HRS_HRS23_MASK             0x800000u
#define DMA_HRS_HRS23_SHIFT            23u
#define DMA_HRS_HRS23_WIDTH            1u
#define DMA_HRS_HRS23(x)               (((uint32_t)(((uint32_t)(x))<<DMA_HRS_HRS23_SHIFT))&DMA_HRS_HRS23_MASK)
#define DMA_HRS_HRS22_MASK             0x400000u
#define DMA_HRS_HRS22_SHIFT            22u
#define DMA_HRS_HRS22_WIDTH            1u
#define DMA_HRS_HRS22(x)               (((uint32_t)(((uint32_t)(x))<<DMA_HRS_HRS22_SHIFT))&DMA_HRS_HRS22_MASK)
#define DMA_HRS_HRS21_MASK             0x200000u
#define DMA_HRS_HRS21_SHIFT            21u
#define DMA_HRS_HRS21_WIDTH            1u
#define DMA_HRS_HRS21(x)               (((uint32_t)(((uint32_t)(x))<<DMA_HRS_HRS21_SHIFT))&DMA_HRS_HRS21_MASK)
#define DMA_HRS_HRS20_MASK             0x100000u
#define DMA_HRS_HRS20_SHIFT            20u
#define DMA_HRS_HRS20_WIDTH            1u
#define DMA_HRS_HRS20(x)               (((uint32_t)(((uint32_t)(x))<<DMA_HRS_HRS20_SHIFT))&DMA_HRS_HRS20_MASK)
#define DMA_HRS_HRS19_MASK             0x80000u
#define DMA_HRS_HRS19_SHIFT            19u
#define DMA_HRS_HRS19_WIDTH            1u
#define DMA_HRS_HRS19(x)               (((uint32_t)(((uint32_t)(x))<<DMA_HRS_HRS19_SHIFT))&DMA_HRS_HRS19_MASK)
#define DMA_HRS_HRS18_MASK             0x40000u
#define DMA_HRS_HRS18_SHIFT            18u
#define DMA_HRS_HRS18_WIDTH            1u
#define DMA_HRS_HRS18(x)               (((uint32_t)(((uint32_t)(x))<<DMA_HRS_HRS18_SHIFT))&DMA_HRS_HRS18_MASK)
#define DMA_HRS_HRS17_MASK             0x20000u
#define DMA_HRS_HRS17_SHIFT            17u
#define DMA_HRS_HRS17_WIDTH            1u
#define DMA_HRS_HRS17(x)               (((uint32_t)(((uint32_t)(x))<<DMA_HRS_HRS17_SHIFT))&DMA_HRS_HRS17_MASK)
#define DMA_HRS_HRS16_MASK             0x10000u
#define DMA_HRS_HRS16_SHIFT            16u
#define DMA_HRS_HRS16_WIDTH            1u
#define DMA_HRS_HRS16(x)               (((uint32_t)(((uint32_t)(x))<<DMA_HRS_HRS16_SHIFT))&DMA_HRS_HRS16_MASK)
#define DMA_HRS_HRS15_MASK             0x8000u
#define DMA_HRS_HRS15_SHIFT            15u
#define DMA_HRS_HRS15_WIDTH            1u
#define DMA_HRS_HRS15(x)               (((uint32_t)(((uint32_t)(x))<<DMA_HRS_HRS15_SHIFT))&DMA_HRS_HRS15_MASK)
#define DMA_HRS_HRS14_MASK             0x4000u
#define DMA_HRS_HRS14_SHIFT            14u
#define DMA_HRS_HRS14_WIDTH            1u
#define DMA_HRS_HRS14(x)               (((uint32_t)(((uint32_t)(x))<<DMA_HRS_HRS14_SHIFT))&DMA_HRS_HRS14_MASK)
#define DMA_HRS_HRS13_MASK             0x2000u
#define DMA_HRS_HRS13_SHIFT            13u
#define DMA_HRS_HRS13_WIDTH            1u
#define DMA_HRS_HRS13(x)               (((uint32_t)(((uint32_t)(x))<<DMA_HRS_HRS13_SHIFT))&DMA_HRS_HRS13_MASK)
#define DMA_HRS_HRS12_MASK             0x1000u
#define DMA_HRS_HRS12_SHIFT            12u
#define DMA_HRS_HRS12_WIDTH            1u
#define DMA_HRS_HRS12(x)               (((uint32_t)(((uint32_t)(x))<<DMA_HRS_HRS12_SHIFT))&DMA_HRS_HRS12_MASK)
#define DMA_HRS_HRS11_MASK             0x800u
#define DMA_HRS_HRS11_SHIFT            11u
#define DMA_HRS_HRS11_WIDTH            1u
#define DMA_HRS_HRS11(x)               (((uint32_t)(((uint32_t)(x))<<DMA_HRS_HRS11_SHIFT))&DMA_HRS_HRS11_MASK)
#define DMA_HRS_HRS10_MASK             0x400u
#define DMA_HRS_HRS10_SHIFT            10u
#define DMA_HRS_HRS10_WIDTH            1u
#define DMA_HRS_HRS10(x)               (((uint32_t)(((uint32_t)(x))<<DMA_HRS_HRS10_SHIFT))&DMA_HRS_HRS10_MASK)
#define DMA_HRS_HRS9_MASK              0x200u
#define DMA_HRS_HRS9_SHIFT             9u
#define DMA_HRS_HRS9_WIDTH             1u
#define DMA_HRS_HRS9(x)                (((uint32_t)(((uint32_t)(x))<<DMA_HRS_HRS9_SHIFT))&DMA_HRS_HRS9_MASK)
#define DMA_HRS_HRS8_MASK              0x100u
#define DMA_HRS_HRS8_SHIFT             8u
#define DMA_HRS_HRS8_WIDTH             1u
#define DMA_HRS_HRS8(x)                (((uint32_t)(((uint32_t)(x))<<DMA_HRS_HRS8_SHIFT))&DMA_HRS_HRS8_MASK)
#define DMA_HRS_HRS7_MASK              0x80u
#define DMA_HRS_HRS7_SHIFT             7u
#define DMA_HRS_HRS7_WIDTH             1u
#define DMA_HRS_HRS7(x)                (((uint32_t)(((uint32_t)(x))<<DMA_HRS_HRS7_SHIFT))&DMA_HRS_HRS7_MASK)
#define DMA_HRS_HRS6_MASK              0x40u
#define DMA_HRS_HRS6_SHIFT             6u
#define DMA_HRS_HRS6_WIDTH             1u
#define DMA_HRS_HRS6(x)                (((uint32_t)(((uint32_t)(x))<<DMA_HRS_HRS6_SHIFT))&DMA_HRS_HRS6_MASK)
#define DMA_HRS_HRS5_MASK              0x20u
#define DMA_HRS_HRS5_SHIFT             5u
#define DMA_HRS_HRS5_WIDTH             1u
#define DMA_HRS_HRS5(x)                (((uint32_t)(((uint32_t)(x))<<DMA_HRS_HRS5_SHIFT))&DMA_HRS_HRS5_MASK)
#define DMA_HRS_HRS4_MASK              0x10u
#define DMA_HRS_HRS4_SHIFT             4u
#define DMA_HRS_HRS4_WIDTH             1u
#define DMA_HRS_HRS4(x)                (((uint32_t)(((uint32_t)(x))<<DMA_HRS_HRS4_SHIFT))&DMA_HRS_HRS4_MASK)
#define DMA_HRS_HRS3_MASK              0x8u
#define DMA_HRS_HRS3_SHIFT             3u
#define DMA_HRS_HRS3_WIDTH             1u
#define DMA_HRS_HRS3(x)                (((uint32_t)(((uint32_t)(x))<<DMA_HRS_HRS3_SHIFT))&DMA_HRS_HRS3_MASK)
#define DMA_HRS_HRS2_MASK              0x4u
#define DMA_HRS_HRS2_SHIFT             2u
#define DMA_HRS_HRS2_WIDTH             1u
#define DMA_HRS_HRS2(x)                (((uint32_t)(((uint32_t)(x))<<DMA_HRS_HRS2_SHIFT))&DMA_HRS_HRS2_MASK)
#define DMA_HRS_HRS1_MASK              0x2u
#define DMA_HRS_HRS1_SHIFT             1u
#define DMA_HRS_HRS1_WIDTH             1u
#define DMA_HRS_HRS1(x)                (((uint32_t)(((uint32_t)(x))<<DMA_HRS_HRS1_SHIFT))&DMA_HRS_HRS1_MASK)
#define DMA_HRS_HRS0_MASK              0x1u
#define DMA_HRS_HRS0_SHIFT             0u
#define DMA_HRS_HRS0_WIDTH             1u
#define DMA_HRS_HRS0(x)                (((uint32_t)(((uint32_t)(x))<<DMA_HRS_HRS0_SHIFT))&DMA_HRS_HRS0_MASK)
/* HRS Reg Mask */
#define DMA_HRS_MASK                   0xFFFFFFFFu

/* UME0 Bit Fields */
#define DMA_UME_SUME15_MASK           0x80000000u
#define DMA_UME_SUME15_SHIFT          31u
#define DMA_UME_SUME15_WIDTH          1u
#define DMA_UME_SUME15(x)             (((uint32_t)(((uint32_t)(x))<<DMA_UME_SUME15_SHIFT))&DMA_UME_SUME15_MASK)
#define DMA_UME_DUME15_MASK           0x40000000u
#define DMA_UME_DUME15_SHIFT          30u
#define DMA_UME_DUME15_WIDTH          1u
#define DMA_UME_DUME15(x)             (((uint32_t)(((uint32_t)(x))<<DMA_UME_DUME15_SHIFT))&DMA_UME_DUME15_MASK)
#define DMA_UME_SUME14_MASK           0x20000000u
#define DMA_UME_SUME14_SHIFT          29u
#define DMA_UME_SUME14_WIDTH          1u
#define DMA_UME_SUME14(x)             (((uint32_t)(((uint32_t)(x))<<DMA_UME_SUME14_SHIFT))&DMA_UME_SUME14_MASK)
#define DMA_UME_DUME14_MASK           0x10000000u
#define DMA_UME_DUME14_SHIFT          28u
#define DMA_UME_DUME14_WIDTH          1u
#define DMA_UME_DUME14(x)             (((uint32_t)(((uint32_t)(x))<<DMA_UME_DUME14_SHIFT))&DMA_UME_DUME14_MASK)
#define DMA_UME_SUME13_MASK           0x8000000u
#define DMA_UME_SUME13_SHIFT          27u
#define DMA_UME_SUME13_WIDTH          1u
#define DMA_UME_SUME13(x)             (((uint32_t)(((uint32_t)(x))<<DMA_UME_SUME13_SHIFT))&DMA_UME_SUME13_MASK)
#define DMA_UME_DUME13_MASK           0x4000000u
#define DMA_UME_DUME13_SHIFT          26u
#define DMA_UME_DUME13_WIDTH          1u
#define DMA_UME_DUME13(x)             (((uint32_t)(((uint32_t)(x))<<DMA_UME_DUME13_SHIFT))&DMA_UME_DUME13_MASK)
#define DMA_UME_SUME12_MASK           0x2000000u
#define DMA_UME_SUME12_SHIFT          25u
#define DMA_UME_SUME12_WIDTH          1u
#define DMA_UME_SUME12(x)             (((uint32_t)(((uint32_t)(x))<<DMA_UME_SUME12_SHIFT))&DMA_UME_SUME12_MASK)
#define DMA_UME_DUME12_MASK           0x1000000u
#define DMA_UME_DUME12_SHIFT          24u
#define DMA_UME_DUME12_WIDTH          1u
#define DMA_UME_DUME12(x)             (((uint32_t)(((uint32_t)(x))<<DMA_UME_DUME12_SHIFT))&DMA_UME_DUME12_MASK)
#define DMA_UME_SUME11_MASK           0x800000u
#define DMA_UME_SUME11_SHIFT          23u
#define DMA_UME_SUME11_WIDTH          1u
#define DMA_UME_SUME11(x)             (((uint32_t)(((uint32_t)(x))<<DMA_UME_SUME11_SHIFT))&DMA_UME_SUME11_MASK)
#define DMA_UME_DUME11_MASK           0x400000u
#define DMA_UME_DUME11_SHIFT          22u
#define DMA_UME_DUME11_WIDTH          1u
#define DMA_UME_DUME11(x)             (((uint32_t)(((uint32_t)(x))<<DMA_UME_DUME11_SHIFT))&DMA_UME_DUME11_MASK)
#define DMA_UME_SUME10_MASK           0x200000u
#define DMA_UME_SUME10_SHIFT          21u
#define DMA_UME_SUME10_WIDTH          1u
#define DMA_UME_SUME10(x)             (((uint32_t)(((uint32_t)(x))<<DMA_UME_SUME10_SHIFT))&DMA_UME_SUME10_MASK)
#define DMA_UME_DUME10_MASK           0x100000u
#define DMA_UME_DUME10_SHIFT          20u
#define DMA_UME_DUME10_WIDTH          1u
#define DMA_UME_DUME10(x)             (((uint32_t)(((uint32_t)(x))<<DMA_UME_DUME10_SHIFT))&DMA_UME_DUME10_MASK)
#define DMA_UME_SUME9_MASK            0x80000u
#define DMA_UME_SUME9_SHIFT           19u
#define DMA_UME_SUME9_WIDTH           1u
#define DMA_UME_SUME9(x)              (((uint32_t)(((uint32_t)(x))<<DMA_UME_SUME9_SHIFT))&DMA_UME_SUME9_MASK)
#define DMA_UME_DUME9_MASK            0x40000u
#define DMA_UME_DUME9_SHIFT           18u
#define DMA_UME_DUME9_WIDTH           1u
#define DMA_UME_DUME9(x)              (((uint32_t)(((uint32_t)(x))<<DMA_UME_DUME9_SHIFT))&DMA_UME_DUME9_MASK)
#define DMA_UME_SUME8_MASK            0x20000u
#define DMA_UME_SUME8_SHIFT           17u
#define DMA_UME_SUME8_WIDTH           1u
#define DMA_UME_SUME8(x)              (((uint32_t)(((uint32_t)(x))<<DMA_UME_SUME8_SHIFT))&DMA_UME_SUME8_MASK)
#define DMA_UME_DUME8_MASK            0x10000u
#define DMA_UME_DUME8_SHIFT           16u
#define DMA_UME_DUME8_WIDTH           1u
#define DMA_UME_DUME8(x)              (((uint32_t)(((uint32_t)(x))<<DMA_UME_DUME8_SHIFT))&DMA_UME_DUME8_MASK)
#define DMA_UME_SUME7_MASK            0x8000u
#define DMA_UME_SUME7_SHIFT           15u
#define DMA_UME_SUME7_WIDTH           1u
#define DMA_UME_SUME7(x)              (((uint32_t)(((uint32_t)(x))<<DMA_UME_SUME7_SHIFT))&DMA_UME_SUME7_MASK)
#define DMA_UME_DUME7_MASK            0x4000u
#define DMA_UME_DUME7_SHIFT           14u
#define DMA_UME_DUME7_WIDTH           1u
#define DMA_UME_DUME7(x)              (((uint32_t)(((uint32_t)(x))<<DMA_UME_DUME7_SHIFT))&DMA_UME_DUME7_MASK)
#define DMA_UME_SUME6_MASK            0x2000u
#define DMA_UME_SUME6_SHIFT           13u
#define DMA_UME_SUME6_WIDTH           1u
#define DMA_UME_SUME6(x)              (((uint32_t)(((uint32_t)(x))<<DMA_UME_SUME6_SHIFT))&DMA_UME_SUME6_MASK)
#define DMA_UME_DUME6_MASK            0x1000u
#define DMA_UME_DUME6_SHIFT           12u
#define DMA_UME_DUME6_WIDTH           1u
#define DMA_UME_DUME6(x)              (((uint32_t)(((uint32_t)(x))<<DMA_UME_DUME6_SHIFT))&DMA_UME_DUME6_MASK)
#define DMA_UME_SUME5_MASK            0x800u
#define DMA_UME_SUME5_SHIFT           11u
#define DMA_UME_SUME5_WIDTH           1u
#define DMA_UME_SUME5(x)              (((uint32_t)(((uint32_t)(x))<<DMA_UME_SUME5_SHIFT))&DMA_UME_SUME5_MASK)
#define DMA_UME_DUME5_MASK            0x400u
#define DMA_UME_DUME5_SHIFT           10u
#define DMA_UME_DUME5_WIDTH           1u
#define DMA_UME_DUME5(x)              (((uint32_t)(((uint32_t)(x))<<DMA_UME_DUME5_SHIFT))&DMA_UME_DUME5_MASK)
#define DMA_UME_SUME4_MASK            0x200u
#define DMA_UME_SUME4_SHIFT           9u
#define DMA_UME_SUME4_WIDTH           1u
#define DMA_UME_SUME4(x)              (((uint32_t)(((uint32_t)(x))<<DMA_UME_SUME4_SHIFT))&DMA_UME_SUME4_MASK)
#define DMA_UME_DUME4_MASK            0x100u
#define DMA_UME_DUME4_SHIFT           8u
#define DMA_UME_DUME4_WIDTH           1u
#define DMA_UME_DUME4(x)              (((uint32_t)(((uint32_t)(x))<<DMA_UME_DUME4_SHIFT))&DMA_UME_DUME4_MASK)
#define DMA_UME_SUME3_MASK            0x80u
#define DMA_UME_SUME3_SHIFT           7u
#define DMA_UME_SUME3_WIDTH           1u
#define DMA_UME_SUME3(x)              (((uint32_t)(((uint32_t)(x))<<DMA_UME_SUME3_SHIFT))&DMA_UME_SUME3_MASK)
#define DMA_UME_DUME3_MASK            0x40u
#define DMA_UME_DUME3_SHIFT           6u
#define DMA_UME_DUME3_WIDTH           1u
#define DMA_UME_DUME3(x)              (((uint32_t)(((uint32_t)(x))<<DMA_UME_DUME3_SHIFT))&DMA_UME_DUME3_MASK)
#define DMA_UME_SUME2_MASK            0x20u
#define DMA_UME_SUME2_SHIFT           5u
#define DMA_UME_SUME2_WIDTH           1u
#define DMA_UME_SUME2(x)              (((uint32_t)(((uint32_t)(x))<<DMA_UME_SUME2_SHIFT))&DMA_UME_SUME2_MASK)
#define DMA_UME_DUME2_MASK            0x10u
#define DMA_UME_DUME2_SHIFT           4u
#define DMA_UME_DUME2_WIDTH           1u
#define DMA_UME_DUME2(x)              (((uint32_t)(((uint32_t)(x))<<DMA_UME_DUME2_SHIFT))&DMA_UME_DUME2_MASK)
#define DMA_UME_SUME1_MASK            0x8u
#define DMA_UME_SUME1_SHIFT           3u
#define DMA_UME_SUME1_WIDTH           1u
#define DMA_UME_SUME1(x)              (((uint32_t)(((uint32_t)(x))<<DMA_UME_SUME1_SHIFT))&DMA_UME_SUME1_MASK)
#define DMA_UME_DUME1_MASK            0x4u
#define DMA_UME_DUME1_SHIFT           2u
#define DMA_UME_DUME1_WIDTH           1u
#define DMA_UME_DUME1(x)              (((uint32_t)(((uint32_t)(x))<<DMA_UME_DUME1_SHIFT))&DMA_UME_DUME1_MASK)
#define DMA_UME_SUME0_MASK            0x2u
#define DMA_UME_SUME0_SHIFT           1u
#define DMA_UME_SUME0_WIDTH           1u
#define DMA_UME_SUME0(x)              (((uint32_t)(((uint32_t)(x))<<DMA_UME_SUME0_SHIFT))&DMA_UME_SUME0_MASK)
#define DMA_UME_DUME0_MASK            0x1u
#define DMA_UME_DUME0_SHIFT           0u
#define DMA_UME_DUME0_WIDTH           1u
#define DMA_UME_DUME0(x)              (((uint32_t)(((uint32_t)(x))<<DMA_UME_DUME0_SHIFT))&DMA_UME_DUME0_MASK)
/* UME0 Reg Mask */
#define DMA_UME_MASK                  0xFFFFFFFFu

/* UMO Bit Fields */
#define DMA_UMO_SUMO_MASK              0xFFFF0000u
#define DMA_UMO_SUMO_SHIFT             16u
#define DMA_UMO_SUMO_WIDTH             16u
#define DMA_UMO_SUMO(x)                (((uint32_t)(((uint32_t)(x))<<DMA_UMO_SUMO_SHIFT))&DMA_UMO_SUMO_MASK)
#define DMA_UMO_DUMO_MASK              0xFFFFu
#define DMA_UMO_DUMO_SHIFT             0u
#define DMA_UMO_DUMO_WIDTH             16u
#define DMA_UMO_DUMO(x)                (((uint32_t)(((uint32_t)(x))<<DMA_UMO_DUMO_SHIFT))&DMA_UMO_DUMO_MASK)
/* UMO0 Reg Mask */
#define DMA_UMO_MASK                   0xFFFFFFFFu

/* CHPRI Bit Fields */
#define DMA_CHPRI_GRPPRI_MASK         0x30u
#define DMA_CHPRI_GRPPRI_SHIFT        4u
#define DMA_CHPRI_GRPPRI_WIDTH        2u
#define DMA_CHPRI_GRPPRI(x)           (((uint8_t)(((uint8_t)(x))<<DMA_CHPRI_GRPPRI_SHIFT))&DMA_CHPRI_GRPPRI_MASK)
#define DMA_CHPRI_CHPRI_MASK          0xFu
#define DMA_CHPRI_CHPRI_SHIFT         0u
#define DMA_CHPRI_CHPRI_WIDTH         4u
#define DMA_CHPRI_CHPRI(x)            (((uint8_t)(((uint8_t)(x))<<DMA_CHPRI_CHPRI_SHIFT))&DMA_CHPRI_CHPRI_MASK)
/* CHPRI Reg Mask */
#define DMA_CHPRI_MASK                0x3Fu


/* CFG_SADDR Bit Fields */
#define DMA_CFG_SADDR_SADDR_MASK       0xFFFFFFFFu
#define DMA_CFG_SADDR_SADDR_SHIFT      0u
#define DMA_CFG_SADDR_SADDR_WIDTH      32u
#define DMA_CFG_SADDR_SADDR(x)         (((uint32_t)(((uint32_t)(x))<<DMA_CFG_SADDR_SADDR_SHIFT))&DMA_CFG_SADDR_SADDR_MASK)
/* CFG_SADDR0 Reg Mask */
#define DMA_CFG_SADDR_MASK             0xFFFFFFFFu

/* CFG_SOFF Bit Fields */
#define DMA_CFG_SOFF_SOFF_MASK         0xFFFFu
#define DMA_CFG_SOFF_SOFF_SHIFT        0u
#define DMA_CFG_SOFF_SOFF_WIDTH        16u
#define DMA_CFG_SOFF_SOFF(x)           (((uint16_t)(((uint16_t)(x))<<DMA_CFG_SOFF_SOFF_SHIFT))&DMA_CFG_SOFF_SOFF_MASK)
/* CFG_SOFF0 Reg Mask */
#define DMA_CFG_SOFF_MASK              0xFFFFu

/* CFG_ATTR Bit Fields */
#define DMA_CFG_ATTR_SMOD_MASK         0xF800u
#define DMA_CFG_ATTR_SMOD_SHIFT        11u
#define DMA_CFG_ATTR_SMOD_WIDTH        5u
#define DMA_CFG_ATTR_SMOD(x)           (((uint16_t)(((uint16_t)(x))<<DMA_CFG_ATTR_SMOD_SHIFT))&DMA_CFG_ATTR_SMOD_MASK)
#define DMA_CFG_ATTR_SSIZE_MASK        0x700u
#define DMA_CFG_ATTR_SSIZE_SHIFT       8u
#define DMA_CFG_ATTR_SSIZE_WIDTH       3u
#define DMA_CFG_ATTR_SSIZE(x)          (((uint16_t)(((uint16_t)(x))<<DMA_CFG_ATTR_SSIZE_SHIFT))&DMA_CFG_ATTR_SSIZE_MASK)
#define DMA_CFG_ATTR_DMOD_MASK         0xF8u
#define DMA_CFG_ATTR_DMOD_SHIFT        3u
#define DMA_CFG_ATTR_DMOD_WIDTH        5u
#define DMA_CFG_ATTR_DMOD(x)           (((uint16_t)(((uint16_t)(x))<<DMA_CFG_ATTR_DMOD_SHIFT))&DMA_CFG_ATTR_DMOD_MASK)
#define DMA_CFG_ATTR_DSIZE_MASK        0x7u
#define DMA_CFG_ATTR_DSIZE_SHIFT       0u
#define DMA_CFG_ATTR_DSIZE_WIDTH       3u
#define DMA_CFG_ATTR_DSIZE(x)          (((uint16_t)(((uint16_t)(x))<<DMA_CFG_ATTR_DSIZE_SHIFT))&DMA_CFG_ATTR_DSIZE_MASK)
/* CFG_ATTR0 Reg Mask */
#define DMA_CFG_ATTR_MASK              0xFFFFu

/* CFG_NBYTES_ILNO Bit Fields */
#define DMA_CFG_NBYTES_ILNO_NBYTES_MASK 0xFFFFFFFFu
#define DMA_CFG_NBYTES_ILNO_NBYTES_SHIFT 0u
#define DMA_CFG_NBYTES_ILNO_NBYTES_WIDTH 32u
#define DMA_CFG_NBYTES_ILNO_NBYTES(x)  (((uint32_t)(((uint32_t)(x))<<DMA_CFG_NBYTES_ILNO_NBYTES_SHIFT))&DMA_CFG_NBYTES_ILNO_NBYTES_MASK)
/* CFG_NBYTES_ILNO0 Reg Mask */
#define DMA_CFG_NBYTES_ILNO_MASK       0xFFFFFFFFu

/* CFG_NBYTES_ILOFFNO Bit Fields */
#define DMA_CFG_NBYTES_ILOFFNO_SILOE_MASK 0x80000000u
#define DMA_CFG_NBYTES_ILOFFNO_SILOE_SHIFT 31u
#define DMA_CFG_NBYTES_ILOFFNO_SILOE_WIDTH 1u
#define DMA_CFG_NBYTES_ILOFFNO_SILOE(x) (((uint32_t)(((uint32_t)(x))<<DMA_CFG_NBYTES_ILOFFNO_SILOE_SHIFT))&DMA_CFG_NBYTES_ILOFFNO_SILOE_MASK)
#define DMA_CFG_NBYTES_ILOFFNO_DILOE_MASK 0x40000000u
#define DMA_CFG_NBYTES_ILOFFNO_DILOE_SHIFT 30u
#define DMA_CFG_NBYTES_ILOFFNO_DILOE_WIDTH 1u
#define DMA_CFG_NBYTES_ILOFFNO_DILOE(x) (((uint32_t)(((uint32_t)(x))<<DMA_CFG_NBYTES_ILOFFNO_DILOE_SHIFT))&DMA_CFG_NBYTES_ILOFFNO_DILOE_MASK)
#define DMA_CFG_NBYTES_ILOFFNO_NBYTES_MASK 0x3FFFFFFFu
#define DMA_CFG_NBYTES_ILOFFNO_NBYTES_SHIFT 0u
#define DMA_CFG_NBYTES_ILOFFNO_NBYTES_WIDTH 30u
#define DMA_CFG_NBYTES_ILOFFNO_NBYTES(x) (((uint32_t)(((uint32_t)(x))<<DMA_CFG_NBYTES_ILOFFNO_NBYTES_SHIFT))&DMA_CFG_NBYTES_ILOFFNO_NBYTES_MASK)
/* CFG_NBYTES_ILOFFNO0 Reg Mask */
#define DMA_CFG_NBYTES_ILOFFNO_MASK    0xFFFFFFFFu

/* CFG_NBYTES_ILOFFYES Bit Fields */
#define DMA_CFG_NBYTES_ILOFFYES_SILOE_MASK 0x80000000u
#define DMA_CFG_NBYTES_ILOFFYES_SILOE_SHIFT 31u
#define DMA_CFG_NBYTES_ILOFFYES_SILOE_WIDTH 1u
#define DMA_CFG_NBYTES_ILOFFYES_SILOE(x) (((uint32_t)(((uint32_t)(x))<<DMA_CFG_NBYTES_ILOFFYES_SILOE_SHIFT))&DMA_CFG_NBYTES_ILOFFYES_SILOE_MASK)
#define DMA_CFG_NBYTES_ILOFFYES_DILOE_MASK 0x40000000u
#define DMA_CFG_NBYTES_ILOFFYES_DILOE_SHIFT 30u
#define DMA_CFG_NBYTES_ILOFFYES_DILOE_WIDTH 1u
#define DMA_CFG_NBYTES_ILOFFYES_DILOE(x) (((uint32_t)(((uint32_t)(x))<<DMA_CFG_NBYTES_ILOFFYES_DILOE_SHIFT))&DMA_CFG_NBYTES_ILOFFYES_DILOE_MASK)
#define DMA_CFG_NBYTES_ILOFFYES_ILOFF_MASK 0x3FFFFC00u
#define DMA_CFG_NBYTES_ILOFFYES_ILOFF_SHIFT 10u
#define DMA_CFG_NBYTES_ILOFFYES_ILOFF_WIDTH 20u
#define DMA_CFG_NBYTES_ILOFFYES_ILOFF(x) (((uint32_t)(((uint32_t)(x))<<DMA_CFG_NBYTES_ILOFFYES_ILOFF_SHIFT))&DMA_CFG_NBYTES_ILOFFYES_ILOFF_MASK)
#define DMA_CFG_NBYTES_ILOFFYES_NBYTES_MASK 0x3FFu
#define DMA_CFG_NBYTES_ILOFFYES_NBYTES_SHIFT 0u
#define DMA_CFG_NBYTES_ILOFFYES_NBYTES_WIDTH 10u
#define DMA_CFG_NBYTES_ILOFFYES_NBYTES(x) (((uint32_t)(((uint32_t)(x))<<DMA_CFG_NBYTES_ILOFFYES_NBYTES_SHIFT))&DMA_CFG_NBYTES_ILOFFYES_NBYTES_MASK)
/* CFG_NBYTES_ILOFFYES0 Reg Mask */
#define DMA_CFG_NBYTES_ILOFFYES_MASK   0xFFFFFFFFu

/* CFG_SLAST Bit Fields */
#define DMA_CFG_SLAST_SLAST_MASK       0xFFFFFFFFu
#define DMA_CFG_SLAST_SLAST_SHIFT      0u
#define DMA_CFG_SLAST_SLAST_WIDTH      32u
#define DMA_CFG_SLAST_SLAST(x)         (((uint32_t)(((uint32_t)(x))<<DMA_CFG_SLAST_SLAST_SHIFT))&DMA_CFG_SLAST_SLAST_MASK)
/* CFG_SLAST0 Reg Mask */
#define DMA_CFG_SLAST_MASK             0xFFFFFFFFu

/* CFG_DADDR Bit Fields */
#define DMA_CFG_DADDR_DADDR_MASK       0xFFFFFFFFu
#define DMA_CFG_DADDR_DADDR_SHIFT      0u
#define DMA_CFG_DADDR_DADDR_WIDTH      32u
#define DMA_CFG_DADDR_DADDR(x)         (((uint32_t)(((uint32_t)(x))<<DMA_CFG_DADDR_DADDR_SHIFT))&DMA_CFG_DADDR_DADDR_MASK)
/* CFG_DADDR0 Reg Mask */
#define DMA_CFG_DADDR_MASK             0xFFFFFFFFu

/* CFG_DOFF Bit Fields */
#define DMA_CFG_DOFF_DOFF_MASK         0xFFFFu
#define DMA_CFG_DOFF_DOFF_SHIFT        0u
#define DMA_CFG_DOFF_DOFF_WIDTH        16u
#define DMA_CFG_DOFF_DOFF(x)           (((uint16_t)(((uint16_t)(x))<<DMA_CFG_DOFF_DOFF_SHIFT))&DMA_CFG_DOFF_DOFF_MASK)
/* CFG_DOFF0 Reg Mask */
#define DMA_CFG_DOFF_MASK              0xFFFFu

/* CFG_CLC_CHTRGENNO Bit Fields */
#define DMA_CFG_CLC_CHTRGENNO_CHTRGEN_MASK 0x8000u
#define DMA_CFG_CLC_CHTRGENNO_CHTRGEN_SHIFT 15u
#define DMA_CFG_CLC_CHTRGENNO_CHTRGEN_WIDTH 1u
#define DMA_CFG_CLC_CHTRGENNO_CHTRGEN(x) (((uint16_t)(((uint16_t)(x))<<DMA_CFG_CLC_CHTRGENNO_CHTRGEN_SHIFT))&DMA_CFG_CLC_CHTRGENNO_CHTRGEN_MASK)
#define DMA_CFG_CLC_CHTRGENNO_CLC_MASK 0x7FFFu
#define DMA_CFG_CLC_CHTRGENNO_CLC_SHIFT 0u
#define DMA_CFG_CLC_CHTRGENNO_CLC_WIDTH 15u
#define DMA_CFG_CLC_CHTRGENNO_CLC(x)   (((uint16_t)(((uint16_t)(x))<<DMA_CFG_CLC_CHTRGENNO_CLC_SHIFT))&DMA_CFG_CLC_CHTRGENNO_CLC_MASK)
/* CFG_CLC_CHTRGENNO0 Reg Mask */
#define DMA_CFG_CLC_CHTRGENNO_MASK     0xFFFFu

/* CFG_CLC_CHTRGENYES Bit Fields */
#define DMA_CFG_CLC_CHTRGENYES_CHTRGEN_MASK 0x8000u
#define DMA_CFG_CLC_CHTRGENYES_CHTRGEN_SHIFT 15u
#define DMA_CFG_CLC_CHTRGENYES_CHTRGEN_WIDTH 1u
#define DMA_CFG_CLC_CHTRGENYES_CHTRGEN(x) (((uint16_t)(((uint16_t)(x))<<DMA_CFG_CLC_CHTRGENYES_CHTRGEN_SHIFT))&DMA_CFG_CLC_CHTRGENYES_CHTRGEN_MASK)
#define DMA_CFG_CLC_CHTRGENYES_TRGCH_MASK 0x3E00u
#define DMA_CFG_CLC_CHTRGENYES_TRGCH_SHIFT 9u
#define DMA_CFG_CLC_CHTRGENYES_TRGCH_WIDTH 5u
#define DMA_CFG_CLC_CHTRGENYES_TRGCH(x) (((uint16_t)(((uint16_t)(x))<<DMA_CFG_CLC_CHTRGENYES_TRGCH_SHIFT))&DMA_CFG_CLC_CHTRGENYES_TRGCH_MASK)
#define DMA_CFG_CLC_CHTRGENYES_CLC_MASK 0x1FFu
#define DMA_CFG_CLC_CHTRGENYES_CLC_SHIFT 0u
#define DMA_CFG_CLC_CHTRGENYES_CLC_WIDTH 9u
#define DMA_CFG_CLC_CHTRGENYES_CLC(x)  (((uint16_t)(((uint16_t)(x))<<DMA_CFG_CLC_CHTRGENYES_CLC_SHIFT))&DMA_CFG_CLC_CHTRGENYES_CLC_MASK)
/* CFG_CLC_CHTRGENYES0 Reg Mask */
#define DMA_CFG_CLC_CHTRGENYES_MASK    0xBFFFu

/* CFG_DLAST Bit Fields */
#define DMA_CFG_DLAST_DLAST_MASK       0xFFFFFFFFu
#define DMA_CFG_DLAST_DLAST_SHIFT      0u
#define DMA_CFG_DLAST_DLAST_WIDTH      32u
#define DMA_CFG_DLAST_DLAST(x)         (((uint32_t)(((uint32_t)(x))<<DMA_CFG_DLAST_DLAST_SHIFT))&DMA_CFG_DLAST_DLAST_MASK)
/* CFG_DLAST0 Reg Mask */
#define DMA_CFG_DLAST_MASK             0xFFFFFFFFu

/* CFG_CSR Bit Fields */
#define DMA_CFG_CSR_UMS_MASK           0x6000u
#define DMA_CFG_CSR_UMS_SHIFT          13u
#define DMA_CFG_CSR_UMS_WIDTH          2u
#define DMA_CFG_CSR_UMS(x)             (((uint16_t)(((uint16_t)(x))<<DMA_CFG_CSR_UMS_SHIFT))&DMA_CFG_CSR_UMS_MASK)
#define DMA_CFG_CSR_OTRGCH_MASK        0x1F00u
#define DMA_CFG_CSR_OTRGCH_SHIFT       8u
#define DMA_CFG_CSR_OTRGCH_WIDTH       5u
#define DMA_CFG_CSR_OTRGCH(x)          (((uint16_t)(((uint16_t)(x))<<DMA_CFG_CSR_OTRGCH_SHIFT))&DMA_CFG_CSR_OTRGCH_MASK)
#define DMA_CFG_CSR_DONE_MASK          0x80u
#define DMA_CFG_CSR_DONE_SHIFT         7u
#define DMA_CFG_CSR_DONE_WIDTH         1u
#define DMA_CFG_CSR_DONE(x)            (((uint16_t)(((uint16_t)(x))<<DMA_CFG_CSR_DONE_SHIFT))&DMA_CFG_CSR_DONE_MASK)
#define DMA_CFG_CSR_ACTIVE_MASK        0x40u
#define DMA_CFG_CSR_ACTIVE_SHIFT       6u
#define DMA_CFG_CSR_ACTIVE_WIDTH       1u
#define DMA_CFG_CSR_ACTIVE(x)          (((uint16_t)(((uint16_t)(x))<<DMA_CFG_CSR_ACTIVE_SHIFT))&DMA_CFG_CSR_ACTIVE_MASK)
#define DMA_CFG_CSR_OCHTRGEN_MASK      0x20u
#define DMA_CFG_CSR_OCHTRGEN_SHIFT     5u
#define DMA_CFG_CSR_OCHTRGEN_WIDTH     1u
#define DMA_CFG_CSR_OCHTRGEN(x)        (((uint16_t)(((uint16_t)(x))<<DMA_CFG_CSR_OCHTRGEN_SHIFT))&DMA_CFG_CSR_OCHTRGEN_MASK)
#define DMA_CFG_CSR_DREQ_MASK          0x8u
#define DMA_CFG_CSR_DREQ_SHIFT         3u
#define DMA_CFG_CSR_DREQ_WIDTH         1u
#define DMA_CFG_CSR_DREQ(x)            (((uint16_t)(((uint16_t)(x))<<DMA_CFG_CSR_DREQ_SHIFT))&DMA_CFG_CSR_DREQ_MASK)
#define DMA_CFG_CSR_INTHALF_MASK       0x4u
#define DMA_CFG_CSR_INTHALF_SHIFT      2u
#define DMA_CFG_CSR_INTHALF_WIDTH      1u
#define DMA_CFG_CSR_INTHALF(x)         (((uint16_t)(((uint16_t)(x))<<DMA_CFG_CSR_INTHALF_SHIFT))&DMA_CFG_CSR_INTHALF_MASK)
#define DMA_CFG_CSR_INTOUTER_MASK      0x2u
#define DMA_CFG_CSR_INTOUTER_SHIFT     1u
#define DMA_CFG_CSR_INTOUTER_WIDTH     1u
#define DMA_CFG_CSR_INTOUTER(x)        (((uint16_t)(((uint16_t)(x))<<DMA_CFG_CSR_INTOUTER_SHIFT))&DMA_CFG_CSR_INTOUTER_MASK)
#define DMA_CFG_CSR_START_MASK         0x1u
#define DMA_CFG_CSR_START_SHIFT        0u
#define DMA_CFG_CSR_START_WIDTH        1u
#define DMA_CFG_CSR_START(x)           (((uint16_t)(((uint16_t)(x))<<DMA_CFG_CSR_START_SHIFT))&DMA_CFG_CSR_START_MASK)
/* CFG_CSR0 Reg Mask */
#define DMA_CFG_CSR_MASK               0x7FEFu

/* CFG_BLC_CHTRGENNO Bit Fields */
#define DMA_CFG_BLC_CHTRGENNO_CHTRGEN_MASK 0x8000u
#define DMA_CFG_BLC_CHTRGENNO_CHTRGEN_SHIFT 15u
#define DMA_CFG_BLC_CHTRGENNO_CHTRGEN_WIDTH 1u
#define DMA_CFG_BLC_CHTRGENNO_CHTRGEN(x) (((uint16_t)(((uint16_t)(x))<<DMA_CFG_BLC_CHTRGENNO_CHTRGEN_SHIFT))&DMA_CFG_BLC_CHTRGENNO_CHTRGEN_MASK)
#define DMA_CFG_BLC_CHTRGENNO_BLC_MASK 0x7FFFu
#define DMA_CFG_BLC_CHTRGENNO_BLC_SHIFT 0u
#define DMA_CFG_BLC_CHTRGENNO_BLC_WIDTH 15u
#define DMA_CFG_BLC_CHTRGENNO_BLC(x)   (((uint16_t)(((uint16_t)(x))<<DMA_CFG_BLC_CHTRGENNO_BLC_SHIFT))&DMA_CFG_BLC_CHTRGENNO_BLC_MASK)
/* CFG_BLC_CHTRGENNO0 Reg Mask */
#define DMA_CFG_BLC_CHTRGENNO_MASK     0xFFFFu

/* CFG_BLC_CHTRGENYES Bit Fields */
#define DMA_CFG_BLC_CHTRGENYES_CHTRGEN_MASK 0x8000u
#define DMA_CFG_BLC_CHTRGENYES_CHTRGEN_SHIFT 15u
#define DMA_CFG_BLC_CHTRGENYES_CHTRGEN_WIDTH 1u
#define DMA_CFG_BLC_CHTRGENYES_CHTRGEN(x) (((uint16_t)(((uint16_t)(x))<<DMA_CFG_BLC_CHTRGENYES_CHTRGEN_SHIFT))&DMA_CFG_BLC_CHTRGENYES_CHTRGEN_MASK)
#define DMA_CFG_BLC_CHTRGENYES_TRGCH_MASK 0x3E00u
#define DMA_CFG_BLC_CHTRGENYES_TRGCH_SHIFT 9u
#define DMA_CFG_BLC_CHTRGENYES_TRGCH_WIDTH 5u
#define DMA_CFG_BLC_CHTRGENYES_TRGCH(x) (((uint16_t)(((uint16_t)(x))<<DMA_CFG_BLC_CHTRGENYES_TRGCH_SHIFT))&DMA_CFG_BLC_CHTRGENYES_TRGCH_MASK)
#define DMA_CFG_BLC_CHTRGENYES_BLC_MASK 0x1FFu
#define DMA_CFG_BLC_CHTRGENYES_BLC_SHIFT 0u
#define DMA_CFG_BLC_CHTRGENYES_BLC_WIDTH 9u
#define DMA_CFG_BLC_CHTRGENYES_BLC(x)  (((uint16_t)(((uint16_t)(x))<<DMA_CFG_BLC_CHTRGENYES_BLC_SHIFT))&DMA_CFG_BLC_CHTRGENYES_BLC_MASK)
/* CFG_BLC_CHTRGENYES0 Reg Mask */
#define DMA_CFG_BLC_CHTRGENYES_MASK    0xBFFFu

/* MON_ERR_STATUS Bit Fields */
#define DMA_MON_ERR_STATUS_RD_ADDR_CMP_ERR_MASK 0x10u
#define DMA_MON_ERR_STATUS_RD_ADDR_CMP_ERR_SHIFT 4u
#define DMA_MON_ERR_STATUS_RD_ADDR_CMP_ERR_WIDTH 1u
#define DMA_MON_ERR_STATUS_RD_ADDR_CMP_ERR(x) (((uint32_t)(((uint32_t)(x))<<DMA_MON_ERR_STATUS_RD_ADDR_CMP_ERR_SHIFT))&DMA_MON_ERR_STATUS_RD_ADDR_CMP_ERR_MASK)
#define DMA_MON_ERR_STATUS_RD_ADDR_CNT_ERR_MASK 0x8u
#define DMA_MON_ERR_STATUS_RD_ADDR_CNT_ERR_SHIFT 3u
#define DMA_MON_ERR_STATUS_RD_ADDR_CNT_ERR_WIDTH 1u
#define DMA_MON_ERR_STATUS_RD_ADDR_CNT_ERR(x) (((uint32_t)(((uint32_t)(x))<<DMA_MON_ERR_STATUS_RD_ADDR_CNT_ERR_SHIFT))&DMA_MON_ERR_STATUS_RD_ADDR_CNT_ERR_MASK)
#define DMA_MON_ERR_STATUS_WR_ADDR_CMP_ERR_MASK 0x4u
#define DMA_MON_ERR_STATUS_WR_ADDR_CMP_ERR_SHIFT 2u
#define DMA_MON_ERR_STATUS_WR_ADDR_CMP_ERR_WIDTH 1u
#define DMA_MON_ERR_STATUS_WR_ADDR_CMP_ERR(x) (((uint32_t)(((uint32_t)(x))<<DMA_MON_ERR_STATUS_WR_ADDR_CMP_ERR_SHIFT))&DMA_MON_ERR_STATUS_WR_ADDR_CMP_ERR_MASK)
#define DMA_MON_ERR_STATUS_WR_ADDR_CNT_ERR_MASK 0x2u
#define DMA_MON_ERR_STATUS_WR_ADDR_CNT_ERR_SHIFT 1u
#define DMA_MON_ERR_STATUS_WR_ADDR_CNT_ERR_WIDTH 1u
#define DMA_MON_ERR_STATUS_WR_ADDR_CNT_ERR(x) (((uint32_t)(((uint32_t)(x))<<DMA_MON_ERR_STATUS_WR_ADDR_CNT_ERR_SHIFT))&DMA_MON_ERR_STATUS_WR_ADDR_CNT_ERR_MASK)
#define DMA_MON_ERR_STATUS_D_ERROR_MASK 0x1u
#define DMA_MON_ERR_STATUS_D_ERROR_SHIFT 0u
#define DMA_MON_ERR_STATUS_D_ERROR_WIDTH 1u
#define DMA_MON_ERR_STATUS_D_ERROR(x)  (((uint32_t)(((uint32_t)(x))<<DMA_MON_ERR_STATUS_D_ERROR_SHIFT))&DMA_MON_ERR_STATUS_D_ERROR_MASK)
/* MON_ERR_STATUS Reg Mask */
#define DMA_MON_ERR_STATUS_MASK        0x0000001Fu

/* MON_FAKE_SRC_ADDR Bit Fields */
#define DMA_MON_FAKE_SRC_ADDR_FAKE_SRC_ADDR_MASK 0xFFFFFFFFu
#define DMA_MON_FAKE_SRC_ADDR_FAKE_SRC_ADDR_SHIFT 0u
#define DMA_MON_FAKE_SRC_ADDR_FAKE_SRC_ADDR_WIDTH 32u
#define DMA_MON_FAKE_SRC_ADDR_FAKE_SRC_ADDR(x) (((uint32_t)(((uint32_t)(x))<<DMA_MON_FAKE_SRC_ADDR_FAKE_SRC_ADDR_SHIFT))&DMA_MON_FAKE_SRC_ADDR_FAKE_SRC_ADDR_MASK)
/* MON_FAKE_SRC_ADDR Reg Mask */
#define DMA_MON_FAKE_SRC_ADDR_MASK     0xFFFFFFFFu

/* MON_FAKE_DST_ADDR Bit Fields */
#define DMA_MON_FAKE_DST_ADDR_FAKE_DST_ADDR_MASK 0xFFFFFFFFu
#define DMA_MON_FAKE_DST_ADDR_FAKE_DST_ADDR_SHIFT 0u
#define DMA_MON_FAKE_DST_ADDR_FAKE_DST_ADDR_WIDTH 32u
#define DMA_MON_FAKE_DST_ADDR_FAKE_DST_ADDR(x) (((uint32_t)(((uint32_t)(x))<<DMA_MON_FAKE_DST_ADDR_FAKE_DST_ADDR_SHIFT))&DMA_MON_FAKE_DST_ADDR_FAKE_DST_ADDR_MASK)
/* MON_FAKE_DST_ADDR Reg Mask */
#define DMA_MON_FAKE_DST_ADDR_MASK     0xFFFFFFFFu

/* MON_CTRL Bit Fields */
#define DMA_MON_CTRL_MON_CHK_EN_MASK   0x80000000u
#define DMA_MON_CTRL_MON_CHK_EN_SHIFT  31u
#define DMA_MON_CTRL_MON_CHK_EN_WIDTH  1u
#define DMA_MON_CTRL_MON_CHK_EN(x)     (((uint32_t)(((uint32_t)(x))<<DMA_MON_CTRL_MON_CHK_EN_SHIFT))&DMA_MON_CTRL_MON_CHK_EN_MASK)
#define DMA_MON_CTRL_MON_SCHK_EN_MASK  0x40000000u
#define DMA_MON_CTRL_MON_SCHK_EN_SHIFT 30u
#define DMA_MON_CTRL_MON_SCHK_EN_WIDTH 1u
#define DMA_MON_CTRL_MON_SCHK_EN(x)    (((uint32_t)(((uint32_t)(x))<<DMA_MON_CTRL_MON_SCHK_EN_SHIFT))&DMA_MON_CTRL_MON_SCHK_EN_MASK)
#define DMA_MON_CTRL_MON_SCHK_LOCK_MASK 0x20000000u
#define DMA_MON_CTRL_MON_SCHK_LOCK_SHIFT 29u
#define DMA_MON_CTRL_MON_SCHK_LOCK_WIDTH 1u
#define DMA_MON_CTRL_MON_SCHK_LOCK(x)  (((uint32_t)(((uint32_t)(x))<<DMA_MON_CTRL_MON_SCHK_LOCK_SHIFT))&DMA_MON_CTRL_MON_SCHK_LOCK_MASK)
#define DMA_MON_CTRL_ERR_CLR_MASK      0x1u
#define DMA_MON_CTRL_ERR_CLR_SHIFT     0u
#define DMA_MON_CTRL_ERR_CLR_WIDTH     1u
#define DMA_MON_CTRL_ERR_CLR(x)        (((uint32_t)(((uint32_t)(x))<<DMA_MON_CTRL_ERR_CLR_SHIFT))&DMA_MON_CTRL_ERR_CLR_MASK)
/* MON_CTRL Reg Mask */
#define DMA_MON_CTRL_MASK              0xE0000001u


/*!
 * @}
 */ /* end of group DMA_Register_Masks */

/*!
 * @}
 */ /* end of group DMA_Peripheral_Access_Layer */

#endif
