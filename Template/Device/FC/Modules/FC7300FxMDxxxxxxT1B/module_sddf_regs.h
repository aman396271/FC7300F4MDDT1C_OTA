#ifndef _MODULE_SDDF_gmbhdijq241_REGS_H_SDDF_H_
#define _MODULE_SDDF_gmbhdijq241_REGS_H_SDDF_H_

/* ----------------------------------------------------------------------------
   -- SDDF Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SDDF_Peripheral_Access_Layer SDDF Peripheral Access Layer
 * @{
 */

/** SDDF - Size of Registers Arrays */
#define SDDF_CH_CNT  4U
/** SDDF - Register Layout Typedef */

typedef struct {

       uint8_t  RESERVED_0[8];
  __IO uint32_t CTRL                          ; /* Global Control Register, offset: 0x8 */
  __IO uint32_t NIER                          ; /* Normal Interrupt Enable Register, offset: 0xC */
  __IO uint32_t ABNIER0                       ; /* Abnormal Interrupt Enable Register 0, offset: 0x10 */
  __IO uint32_t ABNIER1                       ; /* Abnormal Interrupt Enable Register 1, offset: 0x14 */
  __IO uint32_t NISR                          ; /* Normal Interrupt Status Register, offset: 0x18 */
  __IO uint32_t ABNISR0                       ; /* Abnormal Interrupt Status Register 0, offset: 0x1C */
  __IO uint32_t ABNISR1                       ; /* Abnormal Interrupt Status Register 1, offset: 0x20 */
  __I  uint32_t MSR                           ; /* Main Status Register, offset: 0x24 */
  struct{
  __IO uint32_t CCR                          ; /* Channel Control Register, offset: 0x28 */
  __IO uint32_t CDR                          ; /* Channel Data Rate Register, offset: 0x2c */
  __IO uint32_t CFR                          ; /* Channel Configuration Register, offset: 0x30 */
  __IO uint32_t CPR                          ; /* Channel Protection Register, offset: 0x34 */
  __IO uint32_t CBR                          ; /* Channel Bias Register, offset: 0x38 */
  __IO uint32_t CLLMT                        ; /* Channel Low Limit Register, offset: 0x3c */
  __IO uint32_t CHLMT                        ; /* Channel High Limit Register, offset: 0x40 */
  __I  uint32_t CRDATA                       ; /* Channel Result Data Register, offset: 0x44 */
       uint8_t  RESERVED_1[4];
  }CH[SDDF_CH_CNT];

} SDDF_Type, *SDDF_MemMapPtr;


/* SDDF - Peripheral instance base addresses */
/** Peripheral SDDF base address */
#define SDDF_BASE                                (0x4042b000u)
/** Peripheral SDDF base pointer */
#define SDDF                                     ((SDDF_Type *)SDDF_BASE)
// need fill by yourself
///** Number of interrupt vector arrays for the SDDF module. */
//#define SDDF_IRQS_ARR_COUNT                       (1u)
///** Number of interrupt channels for the SDDF module. */
//#define SDDF_IRQS_CH_COUNT                        (1u)
///** Interrupt vectors for the SDDF peripheral type */
//#define SDDF_IRQS                                {SDDF_IRQn}


/* ----------------------------------------------------------------------------
   -- SDDF Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SDDF_Register_Masks SDDF Register Masks
 * @{
 */

/* CTRL Bit Fields */
#define SDDF_CTRL_CLKO2_DIS_MASK       0x20000000u
#define SDDF_CTRL_CLKO2_DIS_SHIFT      29u
#define SDDF_CTRL_CLKO2_DIS_WIDTH      1u
#define SDDF_CTRL_CLKO2_DIS(x)         (((uint32_t)(((uint32_t)(x))<<SDDF_CTRL_CLKO2_DIS_SHIFT))&SDDF_CTRL_CLKO2_DIS_MASK)
#define SDDF_CTRL_CLKO1_DIS_MASK       0x10000000u
#define SDDF_CTRL_CLKO1_DIS_SHIFT      28u
#define SDDF_CTRL_CLKO1_DIS_WIDTH      1u
#define SDDF_CTRL_CLKO1_DIS(x)         (((uint32_t)(((uint32_t)(x))<<SDDF_CTRL_CLKO1_DIS_SHIFT))&SDDF_CTRL_CLKO1_DIS_MASK)
#define SDDF_CTRL_CLKO0_DIS_MASK       0x8000000u
#define SDDF_CTRL_CLKO0_DIS_SHIFT      27u
#define SDDF_CTRL_CLKO0_DIS_WIDTH      1u
#define SDDF_CTRL_CLKO0_DIS(x)         (((uint32_t)(((uint32_t)(x))<<SDDF_CTRL_CLKO0_DIS_SHIFT))&SDDF_CTRL_CLKO0_DIS_MASK)
#define SDDF_CTRL_PRESCALE_MASK        0x6000000u
#define SDDF_CTRL_PRESCALE_SHIFT       25u
#define SDDF_CTRL_PRESCALE_WIDTH       2u
#define SDDF_CTRL_PRESCALE(x)          (((uint32_t)(((uint32_t)(x))<<SDDF_CTRL_PRESCALE_SHIFT))&SDDF_CTRL_PRESCALE_MASK)
#define SDDF_CTRL_MCLK_DIV_MASK        0xFF0000u
#define SDDF_CTRL_MCLK_DIV_SHIFT       16u
#define SDDF_CTRL_MCLK_DIV_WIDTH       8u
#define SDDF_CTRL_MCLK_DIV(x)          (((uint32_t)(((uint32_t)(x))<<SDDF_CTRL_MCLK_DIV_SHIFT))&SDDF_CTRL_MCLK_DIV_MASK)
#define SDDF_CTRL_MEN_MASK             0x8000u
#define SDDF_CTRL_MEN_SHIFT            15u
#define SDDF_CTRL_MEN_WIDTH            1u
#define SDDF_CTRL_MEN(x)               (((uint32_t)(((uint32_t)(x))<<SDDF_CTRL_MEN_SHIFT))&SDDF_CTRL_MEN_MASK)
#define SDDF_CTRL_RESET_MASK           0x2000u
#define SDDF_CTRL_RESET_SHIFT          13u
#define SDDF_CTRL_RESET_WIDTH          1u
#define SDDF_CTRL_RESET(x)             (((uint32_t)(((uint32_t)(x))<<SDDF_CTRL_RESET_SHIFT))&SDDF_CTRL_RESET_MASK)
#define SDDF_CTRL_DBG_MODE_MASK        0x1000u
#define SDDF_CTRL_DBG_MODE_SHIFT       12u
#define SDDF_CTRL_DBG_MODE_WIDTH       1u
#define SDDF_CTRL_DBG_MODE(x)          (((uint32_t)(((uint32_t)(x))<<SDDF_CTRL_DBG_MODE_SHIFT))&SDDF_CTRL_DBG_MODE_MASK)
#define SDDF_CTRL_DBG_EN_MASK          0x800u
#define SDDF_CTRL_DBG_EN_SHIFT         11u
#define SDDF_CTRL_DBG_EN_WIDTH         1u
#define SDDF_CTRL_DBG_EN(x)            (((uint32_t)(((uint32_t)(x))<<SDDF_CTRL_DBG_EN_SHIFT))&SDDF_CTRL_DBG_EN_MASK)
#define SDDF_CTRL_SWTRIG3_MASK         0x8u
#define SDDF_CTRL_SWTRIG3_SHIFT        3u
#define SDDF_CTRL_SWTRIG3_WIDTH        1u
#define SDDF_CTRL_SWTRIG3(x)           (((uint32_t)(((uint32_t)(x))<<SDDF_CTRL_SWTRIG3_SHIFT))&SDDF_CTRL_SWTRIG3_MASK)
#define SDDF_CTRL_SWTRIG2_MASK         0x4u
#define SDDF_CTRL_SWTRIG2_SHIFT        2u
#define SDDF_CTRL_SWTRIG2_WIDTH        1u
#define SDDF_CTRL_SWTRIG2(x)           (((uint32_t)(((uint32_t)(x))<<SDDF_CTRL_SWTRIG2_SHIFT))&SDDF_CTRL_SWTRIG2_MASK)
#define SDDF_CTRL_SWTRIG1_MASK         0x2u
#define SDDF_CTRL_SWTRIG1_SHIFT        1u
#define SDDF_CTRL_SWTRIG1_WIDTH        1u
#define SDDF_CTRL_SWTRIG1(x)           (((uint32_t)(((uint32_t)(x))<<SDDF_CTRL_SWTRIG1_SHIFT))&SDDF_CTRL_SWTRIG1_MASK)
#define SDDF_CTRL_SWTRIG0_MASK         0x1u
#define SDDF_CTRL_SWTRIG0_SHIFT        0u
#define SDDF_CTRL_SWTRIG0_WIDTH        1u
#define SDDF_CTRL_SWTRIG0(x)           (((uint32_t)(((uint32_t)(x))<<SDDF_CTRL_SWTRIG0_SHIFT))&SDDF_CTRL_SWTRIG0_MASK)
/* CTRL Reg Mask */
#define SDDF_CTRL_MASK                 0x3EFFB80Fu

/* NIER Bit Fields */
#define SDDF_NIER_ZCDIE3_MASK          0x80000u
#define SDDF_NIER_ZCDIE3_SHIFT         19u
#define SDDF_NIER_ZCDIE3_WIDTH         1u
#define SDDF_NIER_ZCDIE3(x)            (((uint32_t)(((uint32_t)(x))<<SDDF_NIER_ZCDIE3_SHIFT))&SDDF_NIER_ZCDIE3_MASK)
#define SDDF_NIER_ZCDIE2_MASK          0x40000u
#define SDDF_NIER_ZCDIE2_SHIFT         18u
#define SDDF_NIER_ZCDIE2_WIDTH         1u
#define SDDF_NIER_ZCDIE2(x)            (((uint32_t)(((uint32_t)(x))<<SDDF_NIER_ZCDIE2_SHIFT))&SDDF_NIER_ZCDIE2_MASK)
#define SDDF_NIER_ZCDIE1_MASK          0x20000u
#define SDDF_NIER_ZCDIE1_SHIFT         17u
#define SDDF_NIER_ZCDIE1_WIDTH         1u
#define SDDF_NIER_ZCDIE1(x)            (((uint32_t)(((uint32_t)(x))<<SDDF_NIER_ZCDIE1_SHIFT))&SDDF_NIER_ZCDIE1_MASK)
#define SDDF_NIER_ZCDIE0_MASK          0x10000u
#define SDDF_NIER_ZCDIE0_SHIFT         16u
#define SDDF_NIER_ZCDIE0_WIDTH         1u
#define SDDF_NIER_ZCDIE0(x)            (((uint32_t)(((uint32_t)(x))<<SDDF_NIER_ZCDIE0_SHIFT))&SDDF_NIER_ZCDIE0_MASK)
#define SDDF_NIER_FRDYIE3_MASK         0x800u
#define SDDF_NIER_FRDYIE3_SHIFT        11u
#define SDDF_NIER_FRDYIE3_WIDTH        1u
#define SDDF_NIER_FRDYIE3(x)           (((uint32_t)(((uint32_t)(x))<<SDDF_NIER_FRDYIE3_SHIFT))&SDDF_NIER_FRDYIE3_MASK)
#define SDDF_NIER_FRDYIE2_MASK         0x400u
#define SDDF_NIER_FRDYIE2_SHIFT        10u
#define SDDF_NIER_FRDYIE2_WIDTH        1u
#define SDDF_NIER_FRDYIE2(x)           (((uint32_t)(((uint32_t)(x))<<SDDF_NIER_FRDYIE2_SHIFT))&SDDF_NIER_FRDYIE2_MASK)
#define SDDF_NIER_FRDYIE1_MASK         0x200u
#define SDDF_NIER_FRDYIE1_SHIFT        9u
#define SDDF_NIER_FRDYIE1_WIDTH        1u
#define SDDF_NIER_FRDYIE1(x)           (((uint32_t)(((uint32_t)(x))<<SDDF_NIER_FRDYIE1_SHIFT))&SDDF_NIER_FRDYIE1_MASK)
#define SDDF_NIER_FRDYIE0_MASK         0x100u
#define SDDF_NIER_FRDYIE0_SHIFT        8u
#define SDDF_NIER_FRDYIE0_WIDTH        1u
#define SDDF_NIER_FRDYIE0(x)           (((uint32_t)(((uint32_t)(x))<<SDDF_NIER_FRDYIE0_SHIFT))&SDDF_NIER_FRDYIE0_MASK)
#define SDDF_NIER_COCIE3_MASK          0x8u
#define SDDF_NIER_COCIE3_SHIFT         3u
#define SDDF_NIER_COCIE3_WIDTH         1u
#define SDDF_NIER_COCIE3(x)            (((uint32_t)(((uint32_t)(x))<<SDDF_NIER_COCIE3_SHIFT))&SDDF_NIER_COCIE3_MASK)
#define SDDF_NIER_COCIE2_MASK          0x4u
#define SDDF_NIER_COCIE2_SHIFT         2u
#define SDDF_NIER_COCIE2_WIDTH         1u
#define SDDF_NIER_COCIE2(x)            (((uint32_t)(((uint32_t)(x))<<SDDF_NIER_COCIE2_SHIFT))&SDDF_NIER_COCIE2_MASK)
#define SDDF_NIER_COCIE1_MASK          0x2u
#define SDDF_NIER_COCIE1_SHIFT         1u
#define SDDF_NIER_COCIE1_WIDTH         1u
#define SDDF_NIER_COCIE1(x)            (((uint32_t)(((uint32_t)(x))<<SDDF_NIER_COCIE1_SHIFT))&SDDF_NIER_COCIE1_MASK)
#define SDDF_NIER_COCIE0_MASK          0x1u
#define SDDF_NIER_COCIE0_SHIFT         0u
#define SDDF_NIER_COCIE0_WIDTH         1u
#define SDDF_NIER_COCIE0(x)            (((uint32_t)(((uint32_t)(x))<<SDDF_NIER_COCIE0_SHIFT))&SDDF_NIER_COCIE0_MASK)
/* NIER Reg Mask */
#define SDDF_NIER_MASK                 0x000F0F0Fu

/* ABNIER0 Bit Fields */
#define SDDF_ABNIER0_HLMTIE3_MASK      0x8000000u
#define SDDF_ABNIER0_HLMTIE3_SHIFT     27u
#define SDDF_ABNIER0_HLMTIE3_WIDTH     1u
#define SDDF_ABNIER0_HLMTIE3(x)        (((uint32_t)(((uint32_t)(x))<<SDDF_ABNIER0_HLMTIE3_SHIFT))&SDDF_ABNIER0_HLMTIE3_MASK)
#define SDDF_ABNIER0_HLMTIE2_MASK      0x4000000u
#define SDDF_ABNIER0_HLMTIE2_SHIFT     26u
#define SDDF_ABNIER0_HLMTIE2_WIDTH     1u
#define SDDF_ABNIER0_HLMTIE2(x)        (((uint32_t)(((uint32_t)(x))<<SDDF_ABNIER0_HLMTIE2_SHIFT))&SDDF_ABNIER0_HLMTIE2_MASK)
#define SDDF_ABNIER0_HLMTIE1_MASK      0x2000000u
#define SDDF_ABNIER0_HLMTIE1_SHIFT     25u
#define SDDF_ABNIER0_HLMTIE1_WIDTH     1u
#define SDDF_ABNIER0_HLMTIE1(x)        (((uint32_t)(((uint32_t)(x))<<SDDF_ABNIER0_HLMTIE1_SHIFT))&SDDF_ABNIER0_HLMTIE1_MASK)
#define SDDF_ABNIER0_HLMTIE0_MASK      0x1000000u
#define SDDF_ABNIER0_HLMTIE0_SHIFT     24u
#define SDDF_ABNIER0_HLMTIE0_WIDTH     1u
#define SDDF_ABNIER0_HLMTIE0(x)        (((uint32_t)(((uint32_t)(x))<<SDDF_ABNIER0_HLMTIE0_SHIFT))&SDDF_ABNIER0_HLMTIE0_MASK)
#define SDDF_ABNIER0_LLMTIE3_MASK      0x80000u
#define SDDF_ABNIER0_LLMTIE3_SHIFT     19u
#define SDDF_ABNIER0_LLMTIE3_WIDTH     1u
#define SDDF_ABNIER0_LLMTIE3(x)        (((uint32_t)(((uint32_t)(x))<<SDDF_ABNIER0_LLMTIE3_SHIFT))&SDDF_ABNIER0_LLMTIE3_MASK)
#define SDDF_ABNIER0_LLMTIE2_MASK      0x40000u
#define SDDF_ABNIER0_LLMTIE2_SHIFT     18u
#define SDDF_ABNIER0_LLMTIE2_WIDTH     1u
#define SDDF_ABNIER0_LLMTIE2(x)        (((uint32_t)(((uint32_t)(x))<<SDDF_ABNIER0_LLMTIE2_SHIFT))&SDDF_ABNIER0_LLMTIE2_MASK)
#define SDDF_ABNIER0_LLMTIE1_MASK      0x20000u
#define SDDF_ABNIER0_LLMTIE1_SHIFT     17u
#define SDDF_ABNIER0_LLMTIE1_WIDTH     1u
#define SDDF_ABNIER0_LLMTIE1(x)        (((uint32_t)(((uint32_t)(x))<<SDDF_ABNIER0_LLMTIE1_SHIFT))&SDDF_ABNIER0_LLMTIE1_MASK)
#define SDDF_ABNIER0_LLMTIE0_MASK      0x10000u
#define SDDF_ABNIER0_LLMTIE0_SHIFT     16u
#define SDDF_ABNIER0_LLMTIE0_WIDTH     1u
#define SDDF_ABNIER0_LLMTIE0(x)        (((uint32_t)(((uint32_t)(x))<<SDDF_ABNIER0_LLMTIE0_SHIFT))&SDDF_ABNIER0_LLMTIE0_MASK)
#define SDDF_ABNIER0_WLMTIE3_MASK      0x800u
#define SDDF_ABNIER0_WLMTIE3_SHIFT     11u
#define SDDF_ABNIER0_WLMTIE3_WIDTH     1u
#define SDDF_ABNIER0_WLMTIE3(x)        (((uint32_t)(((uint32_t)(x))<<SDDF_ABNIER0_WLMTIE3_SHIFT))&SDDF_ABNIER0_WLMTIE3_MASK)
#define SDDF_ABNIER0_WLMTIE2_MASK      0x400u
#define SDDF_ABNIER0_WLMTIE2_SHIFT     10u
#define SDDF_ABNIER0_WLMTIE2_WIDTH     1u
#define SDDF_ABNIER0_WLMTIE2(x)        (((uint32_t)(((uint32_t)(x))<<SDDF_ABNIER0_WLMTIE2_SHIFT))&SDDF_ABNIER0_WLMTIE2_MASK)
#define SDDF_ABNIER0_WLMTIE1_MASK      0x200u
#define SDDF_ABNIER0_WLMTIE1_SHIFT     9u
#define SDDF_ABNIER0_WLMTIE1_WIDTH     1u
#define SDDF_ABNIER0_WLMTIE1(x)        (((uint32_t)(((uint32_t)(x))<<SDDF_ABNIER0_WLMTIE1_SHIFT))&SDDF_ABNIER0_WLMTIE1_MASK)
#define SDDF_ABNIER0_WLMTIE0_MASK      0x100u
#define SDDF_ABNIER0_WLMTIE0_SHIFT     8u
#define SDDF_ABNIER0_WLMTIE0_WIDTH     1u
#define SDDF_ABNIER0_WLMTIE0(x)        (((uint32_t)(((uint32_t)(x))<<SDDF_ABNIER0_WLMTIE0_SHIFT))&SDDF_ABNIER0_WLMTIE0_MASK)
#define SDDF_ABNIER0_SCDIE3_MASK       0x8u
#define SDDF_ABNIER0_SCDIE3_SHIFT      3u
#define SDDF_ABNIER0_SCDIE3_WIDTH      1u
#define SDDF_ABNIER0_SCDIE3(x)         (((uint32_t)(((uint32_t)(x))<<SDDF_ABNIER0_SCDIE3_SHIFT))&SDDF_ABNIER0_SCDIE3_MASK)
#define SDDF_ABNIER0_SCDIE2_MASK       0x4u
#define SDDF_ABNIER0_SCDIE2_SHIFT      2u
#define SDDF_ABNIER0_SCDIE2_WIDTH      1u
#define SDDF_ABNIER0_SCDIE2(x)         (((uint32_t)(((uint32_t)(x))<<SDDF_ABNIER0_SCDIE2_SHIFT))&SDDF_ABNIER0_SCDIE2_MASK)
#define SDDF_ABNIER0_SCDIE1_MASK       0x2u
#define SDDF_ABNIER0_SCDIE1_SHIFT      1u
#define SDDF_ABNIER0_SCDIE1_WIDTH      1u
#define SDDF_ABNIER0_SCDIE1(x)         (((uint32_t)(((uint32_t)(x))<<SDDF_ABNIER0_SCDIE1_SHIFT))&SDDF_ABNIER0_SCDIE1_MASK)
#define SDDF_ABNIER0_SCDIE0_MASK       0x1u
#define SDDF_ABNIER0_SCDIE0_SHIFT      0u
#define SDDF_ABNIER0_SCDIE0_WIDTH      1u
#define SDDF_ABNIER0_SCDIE0(x)         (((uint32_t)(((uint32_t)(x))<<SDDF_ABNIER0_SCDIE0_SHIFT))&SDDF_ABNIER0_SCDIE0_MASK)
/* ABNIER0 Reg Mask */
#define SDDF_ABNIER0_MASK              0x0F0F0F0Fu

/* ABNIER1 Bit Fields */
#define SDDF_ABNIER1_SATIE3_MASK       0x8000000u
#define SDDF_ABNIER1_SATIE3_SHIFT      27u
#define SDDF_ABNIER1_SATIE3_WIDTH      1u
#define SDDF_ABNIER1_SATIE3(x)         (((uint32_t)(((uint32_t)(x))<<SDDF_ABNIER1_SATIE3_SHIFT))&SDDF_ABNIER1_SATIE3_MASK)
#define SDDF_ABNIER1_SATIE2_MASK       0x4000000u
#define SDDF_ABNIER1_SATIE2_SHIFT      26u
#define SDDF_ABNIER1_SATIE2_WIDTH      1u
#define SDDF_ABNIER1_SATIE2(x)         (((uint32_t)(((uint32_t)(x))<<SDDF_ABNIER1_SATIE2_SHIFT))&SDDF_ABNIER1_SATIE2_MASK)
#define SDDF_ABNIER1_SATIE1_MASK       0x2000000u
#define SDDF_ABNIER1_SATIE1_SHIFT      25u
#define SDDF_ABNIER1_SATIE1_WIDTH      1u
#define SDDF_ABNIER1_SATIE1(x)         (((uint32_t)(((uint32_t)(x))<<SDDF_ABNIER1_SATIE1_SHIFT))&SDDF_ABNIER1_SATIE1_MASK)
#define SDDF_ABNIER1_SATIE0_MASK       0x1000000u
#define SDDF_ABNIER1_SATIE0_SHIFT      24u
#define SDDF_ABNIER1_SATIE0_WIDTH      1u
#define SDDF_ABNIER1_SATIE0(x)         (((uint32_t)(((uint32_t)(x))<<SDDF_ABNIER1_SATIE0_SHIFT))&SDDF_ABNIER1_SATIE0_MASK)
#define SDDF_ABNIER1_CADIE3_MASK       0x80000u
#define SDDF_ABNIER1_CADIE3_SHIFT      19u
#define SDDF_ABNIER1_CADIE3_WIDTH      1u
#define SDDF_ABNIER1_CADIE3(x)         (((uint32_t)(((uint32_t)(x))<<SDDF_ABNIER1_CADIE3_SHIFT))&SDDF_ABNIER1_CADIE3_MASK)
#define SDDF_ABNIER1_CADIE2_MASK       0x40000u
#define SDDF_ABNIER1_CADIE2_SHIFT      18u
#define SDDF_ABNIER1_CADIE2_WIDTH      1u
#define SDDF_ABNIER1_CADIE2(x)         (((uint32_t)(((uint32_t)(x))<<SDDF_ABNIER1_CADIE2_SHIFT))&SDDF_ABNIER1_CADIE2_MASK)
#define SDDF_ABNIER1_CADIE1_MASK       0x20000u
#define SDDF_ABNIER1_CADIE1_SHIFT      17u
#define SDDF_ABNIER1_CADIE1_WIDTH      1u
#define SDDF_ABNIER1_CADIE1(x)         (((uint32_t)(((uint32_t)(x))<<SDDF_ABNIER1_CADIE1_SHIFT))&SDDF_ABNIER1_CADIE1_MASK)
#define SDDF_ABNIER1_CADIE0_MASK       0x10000u
#define SDDF_ABNIER1_CADIE0_SHIFT      16u
#define SDDF_ABNIER1_CADIE0_WIDTH      1u
#define SDDF_ABNIER1_CADIE0(x)         (((uint32_t)(((uint32_t)(x))<<SDDF_ABNIER1_CADIE0_SHIFT))&SDDF_ABNIER1_CADIE0_MASK)
#define SDDF_ABNIER1_FOVFIE3_MASK      0x800u
#define SDDF_ABNIER1_FOVFIE3_SHIFT     11u
#define SDDF_ABNIER1_FOVFIE3_WIDTH     1u
#define SDDF_ABNIER1_FOVFIE3(x)        (((uint32_t)(((uint32_t)(x))<<SDDF_ABNIER1_FOVFIE3_SHIFT))&SDDF_ABNIER1_FOVFIE3_MASK)
#define SDDF_ABNIER1_FOVFIE2_MASK      0x400u
#define SDDF_ABNIER1_FOVFIE2_SHIFT     10u
#define SDDF_ABNIER1_FOVFIE2_WIDTH     1u
#define SDDF_ABNIER1_FOVFIE2(x)        (((uint32_t)(((uint32_t)(x))<<SDDF_ABNIER1_FOVFIE2_SHIFT))&SDDF_ABNIER1_FOVFIE2_MASK)
#define SDDF_ABNIER1_FOVFIE1_MASK      0x200u
#define SDDF_ABNIER1_FOVFIE1_SHIFT     9u
#define SDDF_ABNIER1_FOVFIE1_WIDTH     1u
#define SDDF_ABNIER1_FOVFIE1(x)        (((uint32_t)(((uint32_t)(x))<<SDDF_ABNIER1_FOVFIE1_SHIFT))&SDDF_ABNIER1_FOVFIE1_MASK)
#define SDDF_ABNIER1_FOVFIE0_MASK      0x100u
#define SDDF_ABNIER1_FOVFIE0_SHIFT     8u
#define SDDF_ABNIER1_FOVFIE0_WIDTH     1u
#define SDDF_ABNIER1_FOVFIE0(x)        (((uint32_t)(((uint32_t)(x))<<SDDF_ABNIER1_FOVFIE0_SHIFT))&SDDF_ABNIER1_FOVFIE0_MASK)
#define SDDF_ABNIER1_FUNFIE3_MASK      0x8u
#define SDDF_ABNIER1_FUNFIE3_SHIFT     3u
#define SDDF_ABNIER1_FUNFIE3_WIDTH     1u
#define SDDF_ABNIER1_FUNFIE3(x)        (((uint32_t)(((uint32_t)(x))<<SDDF_ABNIER1_FUNFIE3_SHIFT))&SDDF_ABNIER1_FUNFIE3_MASK)
#define SDDF_ABNIER1_FUNFIE2_MASK      0x4u
#define SDDF_ABNIER1_FUNFIE2_SHIFT     2u
#define SDDF_ABNIER1_FUNFIE2_WIDTH     1u
#define SDDF_ABNIER1_FUNFIE2(x)        (((uint32_t)(((uint32_t)(x))<<SDDF_ABNIER1_FUNFIE2_SHIFT))&SDDF_ABNIER1_FUNFIE2_MASK)
#define SDDF_ABNIER1_FUNFIE1_MASK      0x2u
#define SDDF_ABNIER1_FUNFIE1_SHIFT     1u
#define SDDF_ABNIER1_FUNFIE1_WIDTH     1u
#define SDDF_ABNIER1_FUNFIE1(x)        (((uint32_t)(((uint32_t)(x))<<SDDF_ABNIER1_FUNFIE1_SHIFT))&SDDF_ABNIER1_FUNFIE1_MASK)
#define SDDF_ABNIER1_FUNFIE0_MASK      0x1u
#define SDDF_ABNIER1_FUNFIE0_SHIFT     0u
#define SDDF_ABNIER1_FUNFIE0_WIDTH     1u
#define SDDF_ABNIER1_FUNFIE0(x)        (((uint32_t)(((uint32_t)(x))<<SDDF_ABNIER1_FUNFIE0_SHIFT))&SDDF_ABNIER1_FUNFIE0_MASK)
/* ABNIER1 Reg Mask */
#define SDDF_ABNIER1_MASK              0x0F0F0F0Fu

/* NISR Bit Fields */
#define SDDF_NISR_ZCD3_MASK            0x80000u
#define SDDF_NISR_ZCD3_SHIFT           19u
#define SDDF_NISR_ZCD3_WIDTH           1u
#define SDDF_NISR_ZCD3(x)              (((uint32_t)(((uint32_t)(x))<<SDDF_NISR_ZCD3_SHIFT))&SDDF_NISR_ZCD3_MASK)
#define SDDF_NISR_ZCD2_MASK            0x40000u
#define SDDF_NISR_ZCD2_SHIFT           18u
#define SDDF_NISR_ZCD2_WIDTH           1u
#define SDDF_NISR_ZCD2(x)              (((uint32_t)(((uint32_t)(x))<<SDDF_NISR_ZCD2_SHIFT))&SDDF_NISR_ZCD2_MASK)
#define SDDF_NISR_ZCD1_MASK            0x20000u
#define SDDF_NISR_ZCD1_SHIFT           17u
#define SDDF_NISR_ZCD1_WIDTH           1u
#define SDDF_NISR_ZCD1(x)              (((uint32_t)(((uint32_t)(x))<<SDDF_NISR_ZCD1_SHIFT))&SDDF_NISR_ZCD1_MASK)
#define SDDF_NISR_ZCD0_MASK            0x10000u
#define SDDF_NISR_ZCD0_SHIFT           16u
#define SDDF_NISR_ZCD0_WIDTH           1u
#define SDDF_NISR_ZCD0(x)              (((uint32_t)(((uint32_t)(x))<<SDDF_NISR_ZCD0_SHIFT))&SDDF_NISR_ZCD0_MASK)
#define SDDF_NISR_FRDY3_MASK           0x800u
#define SDDF_NISR_FRDY3_SHIFT          11u
#define SDDF_NISR_FRDY3_WIDTH          1u
#define SDDF_NISR_FRDY3(x)             (((uint32_t)(((uint32_t)(x))<<SDDF_NISR_FRDY3_SHIFT))&SDDF_NISR_FRDY3_MASK)
#define SDDF_NISR_FRDY2_MASK           0x400u
#define SDDF_NISR_FRDY2_SHIFT          10u
#define SDDF_NISR_FRDY2_WIDTH          1u
#define SDDF_NISR_FRDY2(x)             (((uint32_t)(((uint32_t)(x))<<SDDF_NISR_FRDY2_SHIFT))&SDDF_NISR_FRDY2_MASK)
#define SDDF_NISR_FRDY1_MASK           0x200u
#define SDDF_NISR_FRDY1_SHIFT          9u
#define SDDF_NISR_FRDY1_WIDTH          1u
#define SDDF_NISR_FRDY1(x)             (((uint32_t)(((uint32_t)(x))<<SDDF_NISR_FRDY1_SHIFT))&SDDF_NISR_FRDY1_MASK)
#define SDDF_NISR_FRDY0_MASK           0x100u
#define SDDF_NISR_FRDY0_SHIFT          8u
#define SDDF_NISR_FRDY0_WIDTH          1u
#define SDDF_NISR_FRDY0(x)             (((uint32_t)(((uint32_t)(x))<<SDDF_NISR_FRDY0_SHIFT))&SDDF_NISR_FRDY0_MASK)
#define SDDF_NISR_COC3_MASK            0x8u
#define SDDF_NISR_COC3_SHIFT           3u
#define SDDF_NISR_COC3_WIDTH           1u
#define SDDF_NISR_COC3(x)              (((uint32_t)(((uint32_t)(x))<<SDDF_NISR_COC3_SHIFT))&SDDF_NISR_COC3_MASK)
#define SDDF_NISR_COC2_MASK            0x4u
#define SDDF_NISR_COC2_SHIFT           2u
#define SDDF_NISR_COC2_WIDTH           1u
#define SDDF_NISR_COC2(x)              (((uint32_t)(((uint32_t)(x))<<SDDF_NISR_COC2_SHIFT))&SDDF_NISR_COC2_MASK)
#define SDDF_NISR_COC1_MASK            0x2u
#define SDDF_NISR_COC1_SHIFT           1u
#define SDDF_NISR_COC1_WIDTH           1u
#define SDDF_NISR_COC1(x)              (((uint32_t)(((uint32_t)(x))<<SDDF_NISR_COC1_SHIFT))&SDDF_NISR_COC1_MASK)
#define SDDF_NISR_COC0_MASK            0x1u
#define SDDF_NISR_COC0_SHIFT           0u
#define SDDF_NISR_COC0_WIDTH           1u
#define SDDF_NISR_COC0(x)              (((uint32_t)(((uint32_t)(x))<<SDDF_NISR_COC0_SHIFT))&SDDF_NISR_COC0_MASK)
/* NISR Reg Mask */
#define SDDF_NISR_MASK                 0x000F0F0Fu

/* ABNISR0 Bit Fields */
#define SDDF_ABNISR0_HLMT3_MASK        0x8000000u
#define SDDF_ABNISR0_HLMT3_SHIFT       27u
#define SDDF_ABNISR0_HLMT3_WIDTH       1u
#define SDDF_ABNISR0_HLMT3(x)          (((uint32_t)(((uint32_t)(x))<<SDDF_ABNISR0_HLMT3_SHIFT))&SDDF_ABNISR0_HLMT3_MASK)
#define SDDF_ABNISR0_HLMT2_MASK        0x4000000u
#define SDDF_ABNISR0_HLMT2_SHIFT       26u
#define SDDF_ABNISR0_HLMT2_WIDTH       1u
#define SDDF_ABNISR0_HLMT2(x)          (((uint32_t)(((uint32_t)(x))<<SDDF_ABNISR0_HLMT2_SHIFT))&SDDF_ABNISR0_HLMT2_MASK)
#define SDDF_ABNISR0_HLMT1_MASK        0x2000000u
#define SDDF_ABNISR0_HLMT1_SHIFT       25u
#define SDDF_ABNISR0_HLMT1_WIDTH       1u
#define SDDF_ABNISR0_HLMT1(x)          (((uint32_t)(((uint32_t)(x))<<SDDF_ABNISR0_HLMT1_SHIFT))&SDDF_ABNISR0_HLMT1_MASK)
#define SDDF_ABNISR0_HLMT0_MASK        0x1000000u
#define SDDF_ABNISR0_HLMT0_SHIFT       24u
#define SDDF_ABNISR0_HLMT0_WIDTH       1u
#define SDDF_ABNISR0_HLMT0(x)          (((uint32_t)(((uint32_t)(x))<<SDDF_ABNISR0_HLMT0_SHIFT))&SDDF_ABNISR0_HLMT0_MASK)
#define SDDF_ABNISR0_LLMT3_MASK        0x80000u
#define SDDF_ABNISR0_LLMT3_SHIFT       19u
#define SDDF_ABNISR0_LLMT3_WIDTH       1u
#define SDDF_ABNISR0_LLMT3(x)          (((uint32_t)(((uint32_t)(x))<<SDDF_ABNISR0_LLMT3_SHIFT))&SDDF_ABNISR0_LLMT3_MASK)
#define SDDF_ABNISR0_LLMT2_MASK        0x40000u
#define SDDF_ABNISR0_LLMT2_SHIFT       18u
#define SDDF_ABNISR0_LLMT2_WIDTH       1u
#define SDDF_ABNISR0_LLMT2(x)          (((uint32_t)(((uint32_t)(x))<<SDDF_ABNISR0_LLMT2_SHIFT))&SDDF_ABNISR0_LLMT2_MASK)
#define SDDF_ABNISR0_LLMT1_MASK        0x20000u
#define SDDF_ABNISR0_LLMT1_SHIFT       17u
#define SDDF_ABNISR0_LLMT1_WIDTH       1u
#define SDDF_ABNISR0_LLMT1(x)          (((uint32_t)(((uint32_t)(x))<<SDDF_ABNISR0_LLMT1_SHIFT))&SDDF_ABNISR0_LLMT1_MASK)
#define SDDF_ABNISR0_LLMT0_MASK        0x10000u
#define SDDF_ABNISR0_LLMT0_SHIFT       16u
#define SDDF_ABNISR0_LLMT0_WIDTH       1u
#define SDDF_ABNISR0_LLMT0(x)          (((uint32_t)(((uint32_t)(x))<<SDDF_ABNISR0_LLMT0_SHIFT))&SDDF_ABNISR0_LLMT0_MASK)
#define SDDF_ABNISR0_WLMT3_MASK        0x800u
#define SDDF_ABNISR0_WLMT3_SHIFT       11u
#define SDDF_ABNISR0_WLMT3_WIDTH       1u
#define SDDF_ABNISR0_WLMT3(x)          (((uint32_t)(((uint32_t)(x))<<SDDF_ABNISR0_WLMT3_SHIFT))&SDDF_ABNISR0_WLMT3_MASK)
#define SDDF_ABNISR0_WLMT2_MASK        0x400u
#define SDDF_ABNISR0_WLMT2_SHIFT       10u
#define SDDF_ABNISR0_WLMT2_WIDTH       1u
#define SDDF_ABNISR0_WLMT2(x)          (((uint32_t)(((uint32_t)(x))<<SDDF_ABNISR0_WLMT2_SHIFT))&SDDF_ABNISR0_WLMT2_MASK)
#define SDDF_ABNISR0_WLMT1_MASK        0x200u
#define SDDF_ABNISR0_WLMT1_SHIFT       9u
#define SDDF_ABNISR0_WLMT1_WIDTH       1u
#define SDDF_ABNISR0_WLMT1(x)          (((uint32_t)(((uint32_t)(x))<<SDDF_ABNISR0_WLMT1_SHIFT))&SDDF_ABNISR0_WLMT1_MASK)
#define SDDF_ABNISR0_WLMT0_MASK        0x100u
#define SDDF_ABNISR0_WLMT0_SHIFT       8u
#define SDDF_ABNISR0_WLMT0_WIDTH       1u
#define SDDF_ABNISR0_WLMT0(x)          (((uint32_t)(((uint32_t)(x))<<SDDF_ABNISR0_WLMT0_SHIFT))&SDDF_ABNISR0_WLMT0_MASK)
#define SDDF_ABNISR0_SCD3_MASK         0x8u
#define SDDF_ABNISR0_SCD3_SHIFT        3u
#define SDDF_ABNISR0_SCD3_WIDTH        1u
#define SDDF_ABNISR0_SCD3(x)           (((uint32_t)(((uint32_t)(x))<<SDDF_ABNISR0_SCD3_SHIFT))&SDDF_ABNISR0_SCD3_MASK)
#define SDDF_ABNISR0_SCD2_MASK         0x4u
#define SDDF_ABNISR0_SCD2_SHIFT        2u
#define SDDF_ABNISR0_SCD2_WIDTH        1u
#define SDDF_ABNISR0_SCD2(x)           (((uint32_t)(((uint32_t)(x))<<SDDF_ABNISR0_SCD2_SHIFT))&SDDF_ABNISR0_SCD2_MASK)
#define SDDF_ABNISR0_SCD1_MASK         0x2u
#define SDDF_ABNISR0_SCD1_SHIFT        1u
#define SDDF_ABNISR0_SCD1_WIDTH        1u
#define SDDF_ABNISR0_SCD1(x)           (((uint32_t)(((uint32_t)(x))<<SDDF_ABNISR0_SCD1_SHIFT))&SDDF_ABNISR0_SCD1_MASK)
#define SDDF_ABNISR0_SCD0_MASK         0x1u
#define SDDF_ABNISR0_SCD0_SHIFT        0u
#define SDDF_ABNISR0_SCD0_WIDTH        1u
#define SDDF_ABNISR0_SCD0(x)           (((uint32_t)(((uint32_t)(x))<<SDDF_ABNISR0_SCD0_SHIFT))&SDDF_ABNISR0_SCD0_MASK)
/* ABNISR0 Reg Mask */
#define SDDF_ABNISR0_MASK              0x0F0F0F0Fu

/* ABNISR1 Bit Fields */
#define SDDF_ABNISR1_SAT3_MASK         0x8000000u
#define SDDF_ABNISR1_SAT3_SHIFT        27u
#define SDDF_ABNISR1_SAT3_WIDTH        1u
#define SDDF_ABNISR1_SAT3(x)           (((uint32_t)(((uint32_t)(x))<<SDDF_ABNISR1_SAT3_SHIFT))&SDDF_ABNISR1_SAT3_MASK)
#define SDDF_ABNISR1_SAT2_MASK         0x4000000u
#define SDDF_ABNISR1_SAT2_SHIFT        26u
#define SDDF_ABNISR1_SAT2_WIDTH        1u
#define SDDF_ABNISR1_SAT2(x)           (((uint32_t)(((uint32_t)(x))<<SDDF_ABNISR1_SAT2_SHIFT))&SDDF_ABNISR1_SAT2_MASK)
#define SDDF_ABNISR1_SAT1_MASK         0x2000000u
#define SDDF_ABNISR1_SAT1_SHIFT        25u
#define SDDF_ABNISR1_SAT1_WIDTH        1u
#define SDDF_ABNISR1_SAT1(x)           (((uint32_t)(((uint32_t)(x))<<SDDF_ABNISR1_SAT1_SHIFT))&SDDF_ABNISR1_SAT1_MASK)
#define SDDF_ABNISR1_SAT0_MASK         0x1000000u
#define SDDF_ABNISR1_SAT0_SHIFT        24u
#define SDDF_ABNISR1_SAT0_WIDTH        1u
#define SDDF_ABNISR1_SAT0(x)           (((uint32_t)(((uint32_t)(x))<<SDDF_ABNISR1_SAT0_SHIFT))&SDDF_ABNISR1_SAT0_MASK)
#define SDDF_ABNISR1_CAD3_MASK         0x80000u
#define SDDF_ABNISR1_CAD3_SHIFT        19u
#define SDDF_ABNISR1_CAD3_WIDTH        1u
#define SDDF_ABNISR1_CAD3(x)           (((uint32_t)(((uint32_t)(x))<<SDDF_ABNISR1_CAD3_SHIFT))&SDDF_ABNISR1_CAD3_MASK)
#define SDDF_ABNISR1_CAD2_MASK         0x40000u
#define SDDF_ABNISR1_CAD2_SHIFT        18u
#define SDDF_ABNISR1_CAD2_WIDTH        1u
#define SDDF_ABNISR1_CAD2(x)           (((uint32_t)(((uint32_t)(x))<<SDDF_ABNISR1_CAD2_SHIFT))&SDDF_ABNISR1_CAD2_MASK)
#define SDDF_ABNISR1_CAD1_MASK         0x20000u
#define SDDF_ABNISR1_CAD1_SHIFT        17u
#define SDDF_ABNISR1_CAD1_WIDTH        1u
#define SDDF_ABNISR1_CAD1(x)           (((uint32_t)(((uint32_t)(x))<<SDDF_ABNISR1_CAD1_SHIFT))&SDDF_ABNISR1_CAD1_MASK)
#define SDDF_ABNISR1_CAD0_MASK         0x10000u
#define SDDF_ABNISR1_CAD0_SHIFT        16u
#define SDDF_ABNISR1_CAD0_WIDTH        1u
#define SDDF_ABNISR1_CAD0(x)           (((uint32_t)(((uint32_t)(x))<<SDDF_ABNISR1_CAD0_SHIFT))&SDDF_ABNISR1_CAD0_MASK)
#define SDDF_ABNISR1_FOVF3_MASK        0x800u
#define SDDF_ABNISR1_FOVF3_SHIFT       11u
#define SDDF_ABNISR1_FOVF3_WIDTH       1u
#define SDDF_ABNISR1_FOVF3(x)          (((uint32_t)(((uint32_t)(x))<<SDDF_ABNISR1_FOVF3_SHIFT))&SDDF_ABNISR1_FOVF3_MASK)
#define SDDF_ABNISR1_FOVF2_MASK        0x400u
#define SDDF_ABNISR1_FOVF2_SHIFT       10u
#define SDDF_ABNISR1_FOVF2_WIDTH       1u
#define SDDF_ABNISR1_FOVF2(x)          (((uint32_t)(((uint32_t)(x))<<SDDF_ABNISR1_FOVF2_SHIFT))&SDDF_ABNISR1_FOVF2_MASK)
#define SDDF_ABNISR1_FOVF1_MASK        0x200u
#define SDDF_ABNISR1_FOVF1_SHIFT       9u
#define SDDF_ABNISR1_FOVF1_WIDTH       1u
#define SDDF_ABNISR1_FOVF1(x)          (((uint32_t)(((uint32_t)(x))<<SDDF_ABNISR1_FOVF1_SHIFT))&SDDF_ABNISR1_FOVF1_MASK)
#define SDDF_ABNISR1_FOVF0_MASK        0x100u
#define SDDF_ABNISR1_FOVF0_SHIFT       8u
#define SDDF_ABNISR1_FOVF0_WIDTH       1u
#define SDDF_ABNISR1_FOVF0(x)          (((uint32_t)(((uint32_t)(x))<<SDDF_ABNISR1_FOVF0_SHIFT))&SDDF_ABNISR1_FOVF0_MASK)
#define SDDF_ABNISR1_FUNF3_MASK        0x8u
#define SDDF_ABNISR1_FUNF3_SHIFT       3u
#define SDDF_ABNISR1_FUNF3_WIDTH       1u
#define SDDF_ABNISR1_FUNF3(x)          (((uint32_t)(((uint32_t)(x))<<SDDF_ABNISR1_FUNF3_SHIFT))&SDDF_ABNISR1_FUNF3_MASK)
#define SDDF_ABNISR1_FUNF2_MASK        0x4u
#define SDDF_ABNISR1_FUNF2_SHIFT       2u
#define SDDF_ABNISR1_FUNF2_WIDTH       1u
#define SDDF_ABNISR1_FUNF2(x)          (((uint32_t)(((uint32_t)(x))<<SDDF_ABNISR1_FUNF2_SHIFT))&SDDF_ABNISR1_FUNF2_MASK)
#define SDDF_ABNISR1_FUNF1_MASK        0x2u
#define SDDF_ABNISR1_FUNF1_SHIFT       1u
#define SDDF_ABNISR1_FUNF1_WIDTH       1u
#define SDDF_ABNISR1_FUNF1(x)          (((uint32_t)(((uint32_t)(x))<<SDDF_ABNISR1_FUNF1_SHIFT))&SDDF_ABNISR1_FUNF1_MASK)
#define SDDF_ABNISR1_FUNF0_MASK        0x1u
#define SDDF_ABNISR1_FUNF0_SHIFT       0u
#define SDDF_ABNISR1_FUNF0_WIDTH       1u
#define SDDF_ABNISR1_FUNF0(x)          (((uint32_t)(((uint32_t)(x))<<SDDF_ABNISR1_FUNF0_SHIFT))&SDDF_ABNISR1_FUNF0_MASK)
/* ABNISR1 Reg Mask */
#define SDDF_ABNISR1_MASK              0x0F0F0F0Fu

/* MSR Bit Fields */
#define SDDF_MSR_CLKO2_RDY_MASK        0x4000000u
#define SDDF_MSR_CLKO2_RDY_SHIFT       26u
#define SDDF_MSR_CLKO2_RDY_WIDTH       1u
#define SDDF_MSR_CLKO2_RDY(x)          (((uint32_t)(((uint32_t)(x))<<SDDF_MSR_CLKO2_RDY_SHIFT))&SDDF_MSR_CLKO2_RDY_MASK)
#define SDDF_MSR_CLKO1_RDY_MASK        0x2000000u
#define SDDF_MSR_CLKO1_RDY_SHIFT       25u
#define SDDF_MSR_CLKO1_RDY_WIDTH       1u
#define SDDF_MSR_CLKO1_RDY(x)          (((uint32_t)(((uint32_t)(x))<<SDDF_MSR_CLKO1_RDY_SHIFT))&SDDF_MSR_CLKO1_RDY_MASK)
#define SDDF_MSR_CLKO0_RDY_MASK        0x1000000u
#define SDDF_MSR_CLKO0_RDY_SHIFT       24u
#define SDDF_MSR_CLKO0_RDY_WIDTH       1u
#define SDDF_MSR_CLKO0_RDY(x)          (((uint32_t)(((uint32_t)(x))<<SDDF_MSR_CLKO0_RDY_SHIFT))&SDDF_MSR_CLKO0_RDY_MASK)
#define SDDF_MSR_CHON3_MASK            0x8u
#define SDDF_MSR_CHON3_SHIFT           3u
#define SDDF_MSR_CHON3_WIDTH           1u
#define SDDF_MSR_CHON3(x)              (((uint32_t)(((uint32_t)(x))<<SDDF_MSR_CHON3_SHIFT))&SDDF_MSR_CHON3_MASK)
#define SDDF_MSR_CHON2_MASK            0x4u
#define SDDF_MSR_CHON2_SHIFT           2u
#define SDDF_MSR_CHON2_WIDTH           1u
#define SDDF_MSR_CHON2(x)              (((uint32_t)(((uint32_t)(x))<<SDDF_MSR_CHON2_SHIFT))&SDDF_MSR_CHON2_MASK)
#define SDDF_MSR_CHON1_MASK            0x2u
#define SDDF_MSR_CHON1_SHIFT           1u
#define SDDF_MSR_CHON1_WIDTH           1u
#define SDDF_MSR_CHON1(x)              (((uint32_t)(((uint32_t)(x))<<SDDF_MSR_CHON1_SHIFT))&SDDF_MSR_CHON1_MASK)
#define SDDF_MSR_CHON0_MASK            0x1u
#define SDDF_MSR_CHON0_SHIFT           0u
#define SDDF_MSR_CHON0_WIDTH           1u
#define SDDF_MSR_CHON0(x)              (((uint32_t)(((uint32_t)(x))<<SDDF_MSR_CHON0_SHIFT))&SDDF_MSR_CHON0_MASK)
/* MSR Reg Mask */
#define SDDF_MSR_MASK                  0x0700000Fu

/* CCR Bit Fields */
#define SDDF_CCR_LMT_SEL_MASK          0x20000000u
#define SDDF_CCR_LMT_SEL_SHIFT         29u
#define SDDF_CCR_LMT_SEL_WIDTH         1u
#define SDDF_CCR_LMT_SEL(x)            (((uint32_t)(((uint32_t)(x))<<SDDF_CCR_LMT_SEL_SHIFT))&SDDF_CCR_LMT_SEL_MASK)
#define SDDF_CCR_ZCD_SEL_MASK          0x10000000u
#define SDDF_CCR_ZCD_SEL_SHIFT         28u
#define SDDF_CCR_ZCD_SEL_WIDTH         1u
#define SDDF_CCR_ZCD_SEL(x)            (((uint32_t)(((uint32_t)(x))<<SDDF_CCR_ZCD_SEL_SHIFT))&SDDF_CCR_ZCD_SEL_MASK)
#define SDDF_CCR_FIFO_EN_MASK          0x4000u
#define SDDF_CCR_FIFO_EN_SHIFT         14u
#define SDDF_CCR_FIFO_EN_WIDTH         1u
#define SDDF_CCR_FIFO_EN(x)            (((uint32_t)(((uint32_t)(x))<<SDDF_CCR_FIFO_EN_SHIFT))&SDDF_CCR_FIFO_EN_MASK)
#define SDDF_CCR_LMT_EN_MASK           0x2000u
#define SDDF_CCR_LMT_EN_SHIFT          13u
#define SDDF_CCR_LMT_EN_WIDTH          1u
#define SDDF_CCR_LMT_EN(x)             (((uint32_t)(((uint32_t)(x))<<SDDF_CCR_LMT_EN_SHIFT))&SDDF_CCR_LMT_EN_MASK)
#define SDDF_CCR_ZCD_EN_MASK           0x1000u
#define SDDF_CCR_ZCD_EN_SHIFT          12u
#define SDDF_CCR_ZCD_EN_WIDTH          1u
#define SDDF_CCR_ZCD_EN(x)             (((uint32_t)(((uint32_t)(x))<<SDDF_CCR_ZCD_EN_SHIFT))&SDDF_CCR_ZCD_EN_MASK)
#define SDDF_CCR_CAD_EN_MASK           0x200u
#define SDDF_CCR_CAD_EN_SHIFT          9u
#define SDDF_CCR_CAD_EN_WIDTH          1u
#define SDDF_CCR_CAD_EN(x)             (((uint32_t)(((uint32_t)(x))<<SDDF_CCR_CAD_EN_SHIFT))&SDDF_CCR_CAD_EN_MASK)
#define SDDF_CCR_SCD_EN_MASK           0x100u
#define SDDF_CCR_SCD_EN_SHIFT          8u
#define SDDF_CCR_SCD_EN_WIDTH          1u
#define SDDF_CCR_SCD_EN(x)             (((uint32_t)(((uint32_t)(x))<<SDDF_CCR_SCD_EN_SHIFT))&SDDF_CCR_SCD_EN_MASK)
#define SDDF_CCR_DMA_EN_MASK           0x8u
#define SDDF_CCR_DMA_EN_SHIFT          3u
#define SDDF_CCR_DMA_EN_WIDTH          1u
#define SDDF_CCR_DMA_EN(x)             (((uint32_t)(((uint32_t)(x))<<SDDF_CCR_DMA_EN_SHIFT))&SDDF_CCR_DMA_EN_MASK)
#define SDDF_CCR_AF_EN_MASK            0x4u
#define SDDF_CCR_AF_EN_SHIFT           2u
#define SDDF_CCR_AF_EN_WIDTH           1u
#define SDDF_CCR_AF_EN(x)              (((uint32_t)(((uint32_t)(x))<<SDDF_CCR_AF_EN_SHIFT))&SDDF_CCR_AF_EN_MASK)
#define SDDF_CCR_MF_EN_MASK            0x2u
#define SDDF_CCR_MF_EN_SHIFT           1u
#define SDDF_CCR_MF_EN_WIDTH           1u
#define SDDF_CCR_MF_EN(x)              (((uint32_t)(((uint32_t)(x))<<SDDF_CCR_MF_EN_SHIFT))&SDDF_CCR_MF_EN_MASK)
#define SDDF_CCR_CH_EN_MASK            0x1u
#define SDDF_CCR_CH_EN_SHIFT           0u
#define SDDF_CCR_CH_EN_WIDTH           1u
#define SDDF_CCR_CH_EN(x)              (((uint32_t)(((uint32_t)(x))<<SDDF_CCR_CH_EN_SHIFT))&SDDF_CCR_CH_EN_MASK)
/* CCR0 Reg Mask */
#define SDDF_CCR_MASK                  0x3000730Fu

/* CDR Bit Fields */
#define SDDF_CDR_AFCM_MASK             0x40000000u
#define SDDF_CDR_AFCM_SHIFT            30u
#define SDDF_CDR_AFCM_WIDTH            1u
#define SDDF_CDR_AFCM(x)               (((uint32_t)(((uint32_t)(x))<<SDDF_CDR_AFCM_SHIFT))&SDDF_CDR_AFCM_MASK)
#define SDDF_CDR_AFORD_MASK            0x18000000u
#define SDDF_CDR_AFORD_SHIFT           27u
#define SDDF_CDR_AFORD_WIDTH           2u
#define SDDF_CDR_AFORD(x)              (((uint32_t)(((uint32_t)(x))<<SDDF_CDR_AFORD_SHIFT))&SDDF_CDR_AFORD_MASK)
#define SDDF_CDR_AFOSR_MASK            0x1FF0000u
#define SDDF_CDR_AFOSR_SHIFT           16u
#define SDDF_CDR_AFOSR_WIDTH           9u
#define SDDF_CDR_AFOSR(x)              (((uint32_t)(((uint32_t)(x))<<SDDF_CDR_AFOSR_SHIFT))&SDDF_CDR_AFOSR_MASK)
#define SDDF_CDR_MFCM_MASK             0xC000u
#define SDDF_CDR_MFCM_SHIFT            14u
#define SDDF_CDR_MFCM_WIDTH            2u
#define SDDF_CDR_MFCM(x)               (((uint32_t)(((uint32_t)(x))<<SDDF_CDR_MFCM_SHIFT))&SDDF_CDR_MFCM_MASK)
#define SDDF_CDR_MFORD_MASK            0x3800u
#define SDDF_CDR_MFORD_SHIFT           11u
#define SDDF_CDR_MFORD_WIDTH           3u
#define SDDF_CDR_MFORD(x)              (((uint32_t)(((uint32_t)(x))<<SDDF_CDR_MFORD_SHIFT))&SDDF_CDR_MFORD_MASK)
#define SDDF_CDR_MFOSR_MASK            0x1FFu
#define SDDF_CDR_MFOSR_SHIFT           0u
#define SDDF_CDR_MFOSR_WIDTH           9u
#define SDDF_CDR_MFOSR(x)              (((uint32_t)(((uint32_t)(x))<<SDDF_CDR_MFOSR_SHIFT))&SDDF_CDR_MFOSR_MASK)
/* CDR0 Reg Mask */
#define SDDF_CDR_MASK                  0x59FFF9FFu

/* CFR Bit Fields */
#define SDDF_CFR_TRGLVL_MASK           0x10000000u
#define SDDF_CFR_TRGLVL_SHIFT          28u
#define SDDF_CFR_TRGLVL_WIDTH          1u
#define SDDF_CFR_TRGLVL(x)             (((uint32_t)(((uint32_t)(x))<<SDDF_CFR_TRGLVL_SHIFT))&SDDF_CFR_TRGLVL_MASK)
#define SDDF_CFR_TRGSEL_MASK           0x1000000u
#define SDDF_CFR_TRGSEL_SHIFT          24u
#define SDDF_CFR_TRGSEL_WIDTH          1u
#define SDDF_CFR_TRGSEL(x)             (((uint32_t)(((uint32_t)(x))<<SDDF_CFR_TRGSEL_SHIFT))&SDDF_CFR_TRGSEL_MASK)
#define SDDF_CFR_CLKEDG_MASK           0xC00000u
#define SDDF_CFR_CLKEDG_SHIFT          22u
#define SDDF_CFR_CLKEDG_WIDTH          2u
#define SDDF_CFR_CLKEDG(x)             (((uint32_t)(((uint32_t)(x))<<SDDF_CFR_CLKEDG_SHIFT))&SDDF_CFR_CLKEDG_MASK)
#define SDDF_CFR_CLKSEL_MASK           0x300000u
#define SDDF_CFR_CLKSEL_SHIFT          20u
#define SDDF_CFR_CLKSEL_WIDTH          2u
#define SDDF_CFR_CLKSEL(x)             (((uint32_t)(((uint32_t)(x))<<SDDF_CFR_CLKSEL_SHIFT))&SDDF_CFR_CLKSEL_MASK)
#define SDDF_CFR_IBFMT_MASK            0x30000u
#define SDDF_CFR_IBFMT_SHIFT           16u
#define SDDF_CFR_IBFMT_WIDTH           2u
#define SDDF_CFR_IBFMT(x)              (((uint32_t)(((uint32_t)(x))<<SDDF_CFR_IBFMT_SHIFT))&SDDF_CFR_IBFMT_MASK)
#define SDDF_CFR_FWMK_MASK             0x1C00u
#define SDDF_CFR_FWMK_SHIFT            10u
#define SDDF_CFR_FWMK_WIDTH            3u
#define SDDF_CFR_FWMK(x)               (((uint32_t)(((uint32_t)(x))<<SDDF_CFR_FWMK_SHIFT))&SDDF_CFR_FWMK_MASK)
#define SDDF_CFR_RDFMT_MASK            0x40u
#define SDDF_CFR_RDFMT_SHIFT           6u
#define SDDF_CFR_RDFMT_WIDTH           1u
#define SDDF_CFR_RDFMT(x)              (((uint32_t)(((uint32_t)(x))<<SDDF_CFR_RDFMT_SHIFT))&SDDF_CFR_RDFMT_MASK)
#define SDDF_CFR_MFSHIFT_MASK          0x1Fu
#define SDDF_CFR_MFSHIFT_SHIFT         0u
#define SDDF_CFR_MFSHIFT_WIDTH         5u
#define SDDF_CFR_MFSHIFT(x)            (((uint32_t)(((uint32_t)(x))<<SDDF_CFR_MFSHIFT_SHIFT))&SDDF_CFR_MFSHIFT_MASK)
/* CFR0 Reg Mask */
#define SDDF_CFR_MASK                  0x11F31C5Fu

/* CPR Bit Fields */
#define SDDF_CPR_HLMT_BKEN_MASK        0x80000000u
#define SDDF_CPR_HLMT_BKEN_SHIFT       31u
#define SDDF_CPR_HLMT_BKEN_WIDTH       1u
#define SDDF_CPR_HLMT_BKEN(x)          (((uint32_t)(((uint32_t)(x))<<SDDF_CPR_HLMT_BKEN_SHIFT))&SDDF_CPR_HLMT_BKEN_MASK)
#define SDDF_CPR_WLMT_BKEN_MASK        0x40000000u
#define SDDF_CPR_WLMT_BKEN_SHIFT       30u
#define SDDF_CPR_WLMT_BKEN_WIDTH       1u
#define SDDF_CPR_WLMT_BKEN(x)          (((uint32_t)(((uint32_t)(x))<<SDDF_CPR_WLMT_BKEN_SHIFT))&SDDF_CPR_WLMT_BKEN_MASK)
#define SDDF_CPR_LLMT_BKEN_MASK        0x20000000u
#define SDDF_CPR_LLMT_BKEN_SHIFT       29u
#define SDDF_CPR_LLMT_BKEN_WIDTH       1u
#define SDDF_CPR_LLMT_BKEN(x)          (((uint32_t)(((uint32_t)(x))<<SDDF_CPR_LLMT_BKEN_SHIFT))&SDDF_CPR_LLMT_BKEN_MASK)
#define SDDF_CPR_SCD_BKEN_MASK         0x8000000u
#define SDDF_CPR_SCD_BKEN_SHIFT        27u
#define SDDF_CPR_SCD_BKEN_WIDTH        1u
#define SDDF_CPR_SCD_BKEN(x)           (((uint32_t)(((uint32_t)(x))<<SDDF_CPR_SCD_BKEN_SHIFT))&SDDF_CPR_SCD_BKEN_MASK)
#define SDDF_CPR_CAD_BKEN_MASK         0x4000000u
#define SDDF_CPR_CAD_BKEN_SHIFT        26u
#define SDDF_CPR_CAD_BKEN_WIDTH        1u
#define SDDF_CPR_CAD_BKEN(x)           (((uint32_t)(((uint32_t)(x))<<SDDF_CPR_CAD_BKEN_SHIFT))&SDDF_CPR_CAD_BKEN_MASK)
#define SDDF_CPR_CADLMT_MASK           0xF0000u
#define SDDF_CPR_CADLMT_SHIFT          16u
#define SDDF_CPR_CADLMT_WIDTH          4u
#define SDDF_CPR_CADLMT(x)             (((uint32_t)(((uint32_t)(x))<<SDDF_CPR_CADLMT_SHIFT))&SDDF_CPR_CADLMT_MASK)
#define SDDF_CPR_LMTOPT_MASK           0xC000u
#define SDDF_CPR_LMTOPT_SHIFT          14u
#define SDDF_CPR_LMTOPT_WIDTH          2u
#define SDDF_CPR_LMTOPT(x)             (((uint32_t)(((uint32_t)(x))<<SDDF_CPR_LMTOPT_SHIFT))&SDDF_CPR_LMTOPT_MASK)
#define SDDF_CPR_SCDOPT_MASK           0x3000u
#define SDDF_CPR_SCDOPT_SHIFT          12u
#define SDDF_CPR_SCDOPT_WIDTH          2u
#define SDDF_CPR_SCDOPT(x)             (((uint32_t)(((uint32_t)(x))<<SDDF_CPR_SCDOPT_SHIFT))&SDDF_CPR_SCDOPT_MASK)
#define SDDF_CPR_SCDCM_MASK            0x800u
#define SDDF_CPR_SCDCM_SHIFT           11u
#define SDDF_CPR_SCDCM_WIDTH           1u
#define SDDF_CPR_SCDCM(x)              (((uint32_t)(((uint32_t)(x))<<SDDF_CPR_SCDCM_SHIFT))&SDDF_CPR_SCDCM_MASK)
#define SDDF_CPR_SCDLMT_MASK           0xFFu
#define SDDF_CPR_SCDLMT_SHIFT          0u
#define SDDF_CPR_SCDLMT_WIDTH          8u
#define SDDF_CPR_SCDLMT(x)             (((uint32_t)(((uint32_t)(x))<<SDDF_CPR_SCDLMT_SHIFT))&SDDF_CPR_SCDLMT_MASK)
/* CPR0 Reg Mask */
#define SDDF_CPR_MASK                  0xEC0FF8FFu

/* CBR Bit Fields */
#define SDDF_CBR_BIAS_MASK             0xFFFFFF00u
#define SDDF_CBR_BIAS_SHIFT            8u
#define SDDF_CBR_BIAS_WIDTH            24u
#define SDDF_CBR_BIAS(x)               (((uint32_t)(((uint32_t)(x))<<SDDF_CBR_BIAS_SHIFT))&SDDF_CBR_BIAS_MASK)
/* CBR0 Reg Mask */
#define SDDF_CBR_MASK                  0xFFFFFF00u

/* CLLMT Bit Fields */
#define SDDF_CLLMT_LOLMT_MASK          0xFFFFFF00u
#define SDDF_CLLMT_LOLMT_SHIFT         8u
#define SDDF_CLLMT_LOLMT_WIDTH         24u
#define SDDF_CLLMT_LOLMT(x)            (((uint32_t)(((uint32_t)(x))<<SDDF_CLLMT_LOLMT_SHIFT))&SDDF_CLLMT_LOLMT_MASK)
/* CLLMT0 Reg Mask */
#define SDDF_CLLMT_MASK                0xFFFFFF00u

/* CHLMT Bit Fields */
#define SDDF_CHLMT_HILMT_MASK          0xFFFFFF00u
#define SDDF_CHLMT_HILMT_SHIFT         8u
#define SDDF_CHLMT_HILMT_WIDTH         24u
#define SDDF_CHLMT_HILMT(x)            (((uint32_t)(((uint32_t)(x))<<SDDF_CHLMT_HILMT_SHIFT))&SDDF_CHLMT_HILMT_MASK)
/* CHLMT0 Reg Mask */
#define SDDF_CHLMT_MASK                0xFFFFFF00u

/* CRDATA Bit Fields */
#define SDDF_CRDATA_RDATA_MASK         0xFFFFFF00u
#define SDDF_CRDATA_RDATA_SHIFT        8u
#define SDDF_CRDATA_RDATA_WIDTH        24u
#define SDDF_CRDATA_RDATA(x)           (((uint32_t)(((uint32_t)(x))<<SDDF_CRDATA_RDATA_SHIFT))&SDDF_CRDATA_RDATA_MASK)
/* CRDATA0 Reg Mask */
#define SDDF_CRDATA_MASK               0xFFFFFF00u


/*!
 * @}
 */ /* end of group SDDF_Register_Masks */

/*!
 * @}
 */ /* end of group SDDF_Peripheral_Access_Layer */

#endif
