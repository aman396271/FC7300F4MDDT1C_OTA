#ifndef _MODULE_LU_gmbhdijq2_REGS_H_LU_H_
#define _MODULE_LU_gmbhdijq2_REGS_H_LU_H_

/* ----------------------------------------------------------------------------
   -- LU Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LU_Peripheral_Access_Layer LU Peripheral Access Layer
 * @{
 */

/** LU - Size of Registers Arrays */

/** LU - Register Layout Typedef */

#define LG_CNT 4
typedef struct {
  struct
  {
     __IO uint32_t LG_CFG                       ; /* Logic Generator Configuration Register, offset: 0x0 */
          uint8_t  RESERVED_0[4];
     __IO uint32_t LG_CTRL                      ; /* Logic Generator Control Register, offset: 0x8 */
     __IO uint32_t LG_FILT                      ; /* Logic Generator Filter Control Register, offset: 0xc */
  }LG[LG_CNT];                  /* Logic Generator Filter Control Register, offset: 0x3c */
       uint8_t  RESERVED_4[64];
  __IO uint32_t CTRL                          ; /* Control Register, offset: 0x80 */
  __IO uint32_t INT_ST                        ; /* Interrupt Status Register, offset: 0x84 */
  __IO uint32_t CFG                           ; /* Configuration Register, offset: 0x88 */
  __IO uint32_t SW_RESET                      ; /* Software Reset Register, offset: 0x8C */
  __IO uint32_t DU_CTRL                       ; /* Data Unit Control Register, offset: 0x90 */
  __IO uint32_t DU_INPUT_SEL                  ; /* Data Unit Input Select Register, offset: 0x94 */
  __IO uint32_t DU_CFG                        ; /* Data Unit Bit Configuration Register, offset: 0x98 */
  __IO uint32_t DU_DATA0                      ; /* Data Unit Data0 Register, offset: 0x9C */
  __IO uint32_t DU_DATA1                      ; /* Data Unit Data1 Register, offset: 0xA0 */
  __IO uint32_t DU_DATA2                      ; /* Data Unit Data2 Register, offset: 0xA4 */
  __I  uint32_t DU_DATA3                      ; /* Data Unit Data3 Register, offset: 0xA8 */
  __I  uint32_t DU_DATA4                      ; /* Data Unit Data4 Register, offset: 0xAC */
  __I  uint32_t DU_DATA5                      ; /* Data Unit Data5 Register, offset: 0xB0 */
  __I  uint32_t DU_DATA6                      ; /* Data Unit Data6 Register, offset: 0xB4 */
  __IO uint32_t DU_DATA7                      ; /* Data Unit Data7 Register, offset: 0xB8 */

} LU_Type, *LU_MemMapPtr;


/* LU - Peripheral instance base addresses */
/** Peripheral LU0 base address */
#define LU0_BASE                                 (0x40070000u)
/** Peripheral LU0 base pointer */
#define LU0                                      ((LU_Type *)LU0_BASE)
/** Peripheral LU1 base address */
#define LU1_BASE                                 (0x40071000u)
/** Peripheral LU1 base pointer */
#define LU1                                      ((LU_Type *)LU1_BASE)
// need fill by yourself
///** Number of interrupt vector arrays for the LU module. */
//#define LU_IRQS_ARR_COUNT                       (1u)
///** Number of interrupt channels for the LU module. */
//#define LU_IRQS_CH_COUNT                        (1u)
///** Interrupt vectors for the LU peripheral type */
//#define LU_IRQS                                  {LU0_IRQn, LU1_IRQn}


/* ----------------------------------------------------------------------------
   -- LU Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LU_Register_Masks LU Register Masks
 * @{
 */

/* LG_CFG Bit Fields */
#define LU_LG_CFG_LUT1_CTRL_MASK       0xFFFF0000u
#define LU_LG_CFG_LUT1_CTRL_SHIFT      16u
#define LU_LG_CFG_LUT1_CTRL_WIDTH      16u
#define LU_LG_CFG_LUT1_CTRL(x)         (((uint32_t)(((uint32_t)(x))<<LU_LG_CFG_LUT1_CTRL_SHIFT))&LU_LG_CFG_LUT1_CTRL_MASK)
#define LU_LG_CFG_LUT0_CTRL_MASK       0xFFFFu
#define LU_LG_CFG_LUT0_CTRL_SHIFT      0u
#define LU_LG_CFG_LUT0_CTRL_WIDTH      16u
#define LU_LG_CFG_LUT0_CTRL(x)         (((uint32_t)(((uint32_t)(x))<<LU_LG_CFG_LUT0_CTRL_SHIFT))&LU_LG_CFG_LUT0_CTRL_MASK)
/* LG_CFG0 Reg Mask */
#define LU_LG_CFG_MASK                 0xFFFFFFFFu

/* LG_CTRL Bit Fields */
#define LU_LG_CTRL_DMASEL_MASK         0x20000000u
#define LU_LG_CTRL_DMASEL_SHIFT        29u
#define LU_LG_CTRL_DMASEL_WIDTH        1u
#define LU_LG_CTRL_DMASEL(x)           (((uint32_t)(((uint32_t)(x))<<LU_LG_CTRL_DMASEL_SHIFT))&LU_LG_CTRL_DMASEL_MASK)
#define LU_LG_CTRL_INTSEL_MASK         0x10000000u
#define LU_LG_CTRL_INTSEL_SHIFT        28u
#define LU_LG_CTRL_INTSEL_WIDTH        1u
#define LU_LG_CTRL_INTSEL(x)           (((uint32_t)(((uint32_t)(x))<<LU_LG_CTRL_INTSEL_SHIFT))&LU_LG_CTRL_INTSEL_MASK)
#define LU_LG_CTRL_INPUTDSEL_MASK      0xC00000u
#define LU_LG_CTRL_INPUTDSEL_SHIFT     22u
#define LU_LG_CTRL_INPUTDSEL_WIDTH     2u
#define LU_LG_CTRL_INPUTDSEL(x)        (((uint32_t)(((uint32_t)(x))<<LU_LG_CTRL_INPUTDSEL_SHIFT))&LU_LG_CTRL_INPUTDSEL_MASK)
#define LU_LG_CTRL_INPUTCSEL_MASK      0x300000u
#define LU_LG_CTRL_INPUTCSEL_SHIFT     20u
#define LU_LG_CTRL_INPUTCSEL_WIDTH     2u
#define LU_LG_CTRL_INPUTCSEL(x)        (((uint32_t)(((uint32_t)(x))<<LU_LG_CTRL_INPUTCSEL_SHIFT))&LU_LG_CTRL_INPUTCSEL_MASK)
#define LU_LG_CTRL_INPUTBSEL_MASK      0xC0000u
#define LU_LG_CTRL_INPUTBSEL_SHIFT     18u
#define LU_LG_CTRL_INPUTBSEL_WIDTH     2u
#define LU_LG_CTRL_INPUTBSEL(x)        (((uint32_t)(((uint32_t)(x))<<LU_LG_CTRL_INPUTBSEL_SHIFT))&LU_LG_CTRL_INPUTBSEL_MASK)
#define LU_LG_CTRL_INPUTASEL_MASK      0x30000u
#define LU_LG_CTRL_INPUTASEL_SHIFT     16u
#define LU_LG_CTRL_INPUTASEL_WIDTH     2u
#define LU_LG_CTRL_INPUTASEL(x)        (((uint32_t)(((uint32_t)(x))<<LU_LG_CTRL_INPUTASEL_SHIFT))&LU_LG_CTRL_INPUTASEL_MASK)
#define LU_LG_CTRL_BYPASS_MASK         0x3000u
#define LU_LG_CTRL_BYPASS_SHIFT        12u
#define LU_LG_CTRL_BYPASS_WIDTH        2u
#define LU_LG_CTRL_BYPASS(x)           (((uint32_t)(((uint32_t)(x))<<LU_LG_CTRL_BYPASS_SHIFT))&LU_LG_CTRL_BYPASS_MASK)
#define LU_LG_CTRL_SYNC_MASK           0xF00u
#define LU_LG_CTRL_SYNC_SHIFT          8u
#define LU_LG_CTRL_SYNC_WIDTH          4u
#define LU_LG_CTRL_SYNC(x)             (((uint32_t)(((uint32_t)(x))<<LU_LG_CTRL_SYNC_SHIFT))&LU_LG_CTRL_SYNC_MASK)
#define LU_LG_CTRL_FB_OVRD_MASK        0xC0u
#define LU_LG_CTRL_FB_OVRD_SHIFT       6u
#define LU_LG_CTRL_FB_OVRD_WIDTH       2u
#define LU_LG_CTRL_FB_OVRD(x)          (((uint32_t)(((uint32_t)(x))<<LU_LG_CTRL_FB_OVRD_SHIFT))&LU_LG_CTRL_FB_OVRD_MASK)
#define LU_LG_CTRL_MOD_MASK            0x1Cu
#define LU_LG_CTRL_MOD_SHIFT           2u
#define LU_LG_CTRL_MOD_WIDTH           3u
#define LU_LG_CTRL_MOD(x)              (((uint32_t)(((uint32_t)(x))<<LU_LG_CTRL_MOD_SHIFT))&LU_LG_CTRL_MOD_MASK)
#define LU_LG_CTRL_INIT_EN_MASK        0x2u
#define LU_LG_CTRL_INIT_EN_SHIFT       1u
#define LU_LG_CTRL_INIT_EN_WIDTH       1u
#define LU_LG_CTRL_INIT_EN(x)          (((uint32_t)(((uint32_t)(x))<<LU_LG_CTRL_INIT_EN_SHIFT))&LU_LG_CTRL_INIT_EN_MASK)
#define LU_LG_CTRL_FF_INIT_MASK        0x1u
#define LU_LG_CTRL_FF_INIT_SHIFT       0u
#define LU_LG_CTRL_FF_INIT_WIDTH       1u
#define LU_LG_CTRL_FF_INIT(x)          (((uint32_t)(((uint32_t)(x))<<LU_LG_CTRL_FF_INIT_SHIFT))&LU_LG_CTRL_FF_INIT_MASK)
/* LG_CTRL0 Reg Mask */
#define LU_LG_CTRL_MASK                0x30FF3FDFu

/* LG_FILT Bit Fields */
#define LU_LG_FILT_CNT0_MASK           0x7000000u
#define LU_LG_FILT_CNT0_SHIFT          24u
#define LU_LG_FILT_CNT0_WIDTH          3u
#define LU_LG_FILT_CNT0(x)             (((uint32_t)(((uint32_t)(x))<<LU_LG_FILT_CNT0_SHIFT))&LU_LG_FILT_CNT0_MASK)
#define LU_LG_FILT_PRE0_MASK           0xFF0000u
#define LU_LG_FILT_PRE0_SHIFT          16u
#define LU_LG_FILT_PRE0_WIDTH          8u
#define LU_LG_FILT_PRE0(x)             (((uint32_t)(((uint32_t)(x))<<LU_LG_FILT_PRE0_SHIFT))&LU_LG_FILT_PRE0_MASK)
#define LU_LG_FILT_CNT1_MASK           0x700u
#define LU_LG_FILT_CNT1_SHIFT          8u
#define LU_LG_FILT_CNT1_WIDTH          3u
#define LU_LG_FILT_CNT1(x)             (((uint32_t)(((uint32_t)(x))<<LU_LG_FILT_CNT1_SHIFT))&LU_LG_FILT_CNT1_MASK)
#define LU_LG_FILT_PRE1_MASK           0xFFu
#define LU_LG_FILT_PRE1_SHIFT          0u
#define LU_LG_FILT_PRE1_WIDTH          8u
#define LU_LG_FILT_PRE1(x)             (((uint32_t)(((uint32_t)(x))<<LU_LG_FILT_PRE1_SHIFT))&LU_LG_FILT_PRE1_MASK)
/* LG_FILT0 Reg Mask */
#define LU_LG_FILT_MASK                0x07FF07FFu

/* CTRL Bit Fields */
#define LU_CTRL_PS_MASK                0x7u
#define LU_CTRL_PS_SHIFT               0u
#define LU_CTRL_PS_WIDTH               3u
#define LU_CTRL_PS(x)                  (((uint32_t)(((uint32_t)(x))<<LU_CTRL_PS_SHIFT))&LU_CTRL_PS_MASK)
/* CTRL Reg Mask */
#define LU_CTRL_MASK                   0x00000007u

/* INT_ST Bit Fields */
#define LU_INT_ST_LUTINTST_MASK        0x1Fu
#define LU_INT_ST_LUTINTST_SHIFT       0u
#define LU_INT_ST_LUTINTST_WIDTH       5u
#define LU_INT_ST_LUTINTST(x)          (((uint32_t)(((uint32_t)(x))<<LU_INT_ST_LUTINTST_SHIFT))&LU_INT_ST_LUTINTST_MASK)
/* INT_ST Reg Mask */
#define LU_INT_ST_MASK                 0x0000001Fu

/* CFG Bit Fields */
#define LU_CFG_INTEN_MASK              0x80000000u
#define LU_CFG_INTEN_SHIFT             31u
#define LU_CFG_INTEN_WIDTH             1u
#define LU_CFG_INTEN(x)                (((uint32_t)(((uint32_t)(x))<<LU_CFG_INTEN_SHIFT))&LU_CFG_INTEN_MASK)
#define LU_CFG_LUOUT3BSEL_MASK         0xC000u
#define LU_CFG_LUOUT3BSEL_SHIFT        14u
#define LU_CFG_LUOUT3BSEL_WIDTH        2u
#define LU_CFG_LUOUT3BSEL(x)           (((uint32_t)(((uint32_t)(x))<<LU_CFG_LUOUT3BSEL_SHIFT))&LU_CFG_LUOUT3BSEL_MASK)
#define LU_CFG_LUOUT2BSEL_MASK         0x3000u
#define LU_CFG_LUOUT2BSEL_SHIFT        12u
#define LU_CFG_LUOUT2BSEL_WIDTH        2u
#define LU_CFG_LUOUT2BSEL(x)           (((uint32_t)(((uint32_t)(x))<<LU_CFG_LUOUT2BSEL_SHIFT))&LU_CFG_LUOUT2BSEL_MASK)
#define LU_CFG_LUOUT1BSEL_MASK         0xC00u
#define LU_CFG_LUOUT1BSEL_SHIFT        10u
#define LU_CFG_LUOUT1BSEL_WIDTH        2u
#define LU_CFG_LUOUT1BSEL(x)           (((uint32_t)(((uint32_t)(x))<<LU_CFG_LUOUT1BSEL_SHIFT))&LU_CFG_LUOUT1BSEL_MASK)
#define LU_CFG_LUOUT0BSEL_MASK         0x300u
#define LU_CFG_LUOUT0BSEL_SHIFT        8u
#define LU_CFG_LUOUT0BSEL_WIDTH        2u
#define LU_CFG_LUOUT0BSEL(x)           (((uint32_t)(((uint32_t)(x))<<LU_CFG_LUOUT0BSEL_SHIFT))&LU_CFG_LUOUT0BSEL_MASK)
#define LU_CFG_LUOUT3ASEL_MASK         0xC0u
#define LU_CFG_LUOUT3ASEL_SHIFT        6u
#define LU_CFG_LUOUT3ASEL_WIDTH        2u
#define LU_CFG_LUOUT3ASEL(x)           (((uint32_t)(((uint32_t)(x))<<LU_CFG_LUOUT3ASEL_SHIFT))&LU_CFG_LUOUT3ASEL_MASK)
#define LU_CFG_LUOUT2ASEL_MASK         0x30u
#define LU_CFG_LUOUT2ASEL_SHIFT        4u
#define LU_CFG_LUOUT2ASEL_WIDTH        2u
#define LU_CFG_LUOUT2ASEL(x)           (((uint32_t)(((uint32_t)(x))<<LU_CFG_LUOUT2ASEL_SHIFT))&LU_CFG_LUOUT2ASEL_MASK)
#define LU_CFG_LUOUT1ASEL_MASK         0xCu
#define LU_CFG_LUOUT1ASEL_SHIFT        2u
#define LU_CFG_LUOUT1ASEL_WIDTH        2u
#define LU_CFG_LUOUT1ASEL(x)           (((uint32_t)(((uint32_t)(x))<<LU_CFG_LUOUT1ASEL_SHIFT))&LU_CFG_LUOUT1ASEL_MASK)
#define LU_CFG_LUOUT0ASEL_MASK         0x3u
#define LU_CFG_LUOUT0ASEL_SHIFT        0u
#define LU_CFG_LUOUT0ASEL_WIDTH        2u
#define LU_CFG_LUOUT0ASEL(x)           (((uint32_t)(((uint32_t)(x))<<LU_CFG_LUOUT0ASEL_SHIFT))&LU_CFG_LUOUT0ASEL_MASK)
/* CFG Reg Mask */
#define LU_CFG_MASK                    0x8000FFFFu

/* SW_RESET Bit Fields */
#define LU_SW_RESET_KEY_MASK           0xFFFFFFFFu
#define LU_SW_RESET_KEY_SHIFT          0u
#define LU_SW_RESET_KEY_WIDTH          32u
#define LU_SW_RESET_KEY(x)             (((uint32_t)(((uint32_t)(x))<<LU_SW_RESET_KEY_SHIFT))&LU_SW_RESET_KEY_MASK)
/* SW_RESET Reg Mask */
#define LU_SW_RESET_MASK               0xFFFFFFFFu

/* DU_CTRL Bit Fields */
#define LU_DU_CTRL_COMP_MASK           0x80000000u
#define LU_DU_CTRL_COMP_SHIFT          31u
#define LU_DU_CTRL_COMP_WIDTH          1u
#define LU_DU_CTRL_COMP(x)             (((uint32_t)(((uint32_t)(x))<<LU_DU_CTRL_COMP_SHIFT))&LU_DU_CTRL_COMP_MASK)
#define LU_DU_CTRL_CONEN_MASK          0x40000000u
#define LU_DU_CTRL_CONEN_SHIFT         30u
#define LU_DU_CTRL_CONEN_WIDTH         1u
#define LU_DU_CTRL_CONEN(x)            (((uint32_t)(((uint32_t)(x))<<LU_DU_CTRL_CONEN_SHIFT))&LU_DU_CTRL_CONEN_MASK)
#define LU_DU_CTRL_CAPMODE_MASK        0x30000000u
#define LU_DU_CTRL_CAPMODE_SHIFT       28u
#define LU_DU_CTRL_CAPMODE_WIDTH       2u
#define LU_DU_CTRL_CAPMODE(x)          (((uint32_t)(((uint32_t)(x))<<LU_DU_CTRL_CAPMODE_SHIFT))&LU_DU_CTRL_CAPMODE_MASK)
#define LU_DU_CTRL_COMPEDGE_MASK       0x8000000u
#define LU_DU_CTRL_COMPEDGE_SHIFT      27u
#define LU_DU_CTRL_COMPEDGE_WIDTH      1u
#define LU_DU_CTRL_COMPEDGE(x)         (((uint32_t)(((uint32_t)(x))<<LU_DU_CTRL_COMPEDGE_SHIFT))&LU_DU_CTRL_COMPEDGE_MASK)
#define LU_DU_CTRL_DMASEL_MASK         0x4000000u
#define LU_DU_CTRL_DMASEL_SHIFT        26u
#define LU_DU_CTRL_DMASEL_WIDTH        1u
#define LU_DU_CTRL_DMASEL(x)           (((uint32_t)(((uint32_t)(x))<<LU_DU_CTRL_DMASEL_SHIFT))&LU_DU_CTRL_DMASEL_MASK)
#define LU_DU_CTRL_INTSEL_MASK         0x2000000u
#define LU_DU_CTRL_INTSEL_SHIFT        25u
#define LU_DU_CTRL_INTSEL_WIDTH        1u
#define LU_DU_CTRL_INTSEL(x)           (((uint32_t)(((uint32_t)(x))<<LU_DU_CTRL_INTSEL_SHIFT))&LU_DU_CTRL_INTSEL_MASK)
#define LU_DU_CTRL_OUTCINIT_MASK       0x1000000u
#define LU_DU_CTRL_OUTCINIT_SHIFT      24u
#define LU_DU_CTRL_OUTCINIT_WIDTH      1u
#define LU_DU_CTRL_OUTCINIT(x)         (((uint32_t)(((uint32_t)(x))<<LU_DU_CTRL_OUTCINIT_SHIFT))&LU_DU_CTRL_OUTCINIT_MASK)
#define LU_DU_CTRL_SAMPINIT_MASK       0x800000u
#define LU_DU_CTRL_SAMPINIT_SHIFT      23u
#define LU_DU_CTRL_SAMPINIT_WIDTH      1u
#define LU_DU_CTRL_SAMPINIT(x)         (((uint32_t)(((uint32_t)(x))<<LU_DU_CTRL_SAMPINIT_SHIFT))&LU_DU_CTRL_SAMPINIT_MASK)
#define LU_DU_CTRL_SHIFTOUTINIT_MASK   0x400000u
#define LU_DU_CTRL_SHIFTOUTINIT_SHIFT  22u
#define LU_DU_CTRL_SHIFTOUTINIT_WIDTH  1u
#define LU_DU_CTRL_SHIFTOUTINIT(x)     (((uint32_t)(((uint32_t)(x))<<LU_DU_CTRL_SHIFTOUTINIT_SHIFT))&LU_DU_CTRL_SHIFTOUTINIT_MASK)
#define LU_DU_CTRL_COMPTYPE_MASK       0x200000u
#define LU_DU_CTRL_COMPTYPE_SHIFT      21u
#define LU_DU_CTRL_COMPTYPE_WIDTH      1u
#define LU_DU_CTRL_COMPTYPE(x)         (((uint32_t)(((uint32_t)(x))<<LU_DU_CTRL_COMPTYPE_SHIFT))&LU_DU_CTRL_COMPTYPE_MASK)
#define LU_DU_CTRL_COMPSIZE_MASK       0x1F0000u
#define LU_DU_CTRL_COMPSIZE_SHIFT      16u
#define LU_DU_CTRL_COMPSIZE_WIDTH      5u
#define LU_DU_CTRL_COMPSIZE(x)         (((uint32_t)(((uint32_t)(x))<<LU_DU_CTRL_COMPSIZE_SHIFT))&LU_DU_CTRL_COMPSIZE_MASK)
#define LU_DU_CTRL_INPUTTRIG_MASK      0xFC00u
#define LU_DU_CTRL_INPUTTRIG_SHIFT     10u
#define LU_DU_CTRL_INPUTTRIG_WIDTH     6u
#define LU_DU_CTRL_INPUTTRIG(x)        (((uint32_t)(((uint32_t)(x))<<LU_DU_CTRL_INPUTTRIG_SHIFT))&LU_DU_CTRL_INPUTTRIG_MASK)
#define LU_DU_CTRL_COMPTOGTYPE_MASK    0x200u
#define LU_DU_CTRL_COMPTOGTYPE_SHIFT   9u
#define LU_DU_CTRL_COMPTOGTYPE_WIDTH   1u
#define LU_DU_CTRL_COMPTOGTYPE(x)      (((uint32_t)(((uint32_t)(x))<<LU_DU_CTRL_COMPTOGTYPE_SHIFT))&LU_DU_CTRL_COMPTOGTYPE_MASK)
#define LU_DU_CTRL_EDGEMODE_MASK       0x100u
#define LU_DU_CTRL_EDGEMODE_SHIFT      8u
#define LU_DU_CTRL_EDGEMODE_WIDTH      1u
#define LU_DU_CTRL_EDGEMODE(x)         (((uint32_t)(((uint32_t)(x))<<LU_DU_CTRL_EDGEMODE_SHIFT))&LU_DU_CTRL_EDGEMODE_MASK)
#define LU_DU_CTRL_FLEX_SAMP_MASK      0xC0u
#define LU_DU_CTRL_FLEX_SAMP_SHIFT     6u
#define LU_DU_CTRL_FLEX_SAMP_WIDTH     2u
#define LU_DU_CTRL_FLEX_SAMP(x)        (((uint32_t)(((uint32_t)(x))<<LU_DU_CTRL_FLEX_SAMP_SHIFT))&LU_DU_CTRL_FLEX_SAMP_MASK)
#define LU_DU_CTRL_CLKINIT_MASK        0x20u
#define LU_DU_CTRL_CLKINIT_SHIFT       5u
#define LU_DU_CTRL_CLKINIT_WIDTH       1u
#define LU_DU_CTRL_CLKINIT(x)          (((uint32_t)(((uint32_t)(x))<<LU_DU_CTRL_CLKINIT_SHIFT))&LU_DU_CTRL_CLKINIT_MASK)
#define LU_DU_CTRL_STARTWIDTH_MASK     0x10u
#define LU_DU_CTRL_STARTWIDTH_SHIFT    4u
#define LU_DU_CTRL_STARTWIDTH_WIDTH    1u
#define LU_DU_CTRL_STARTWIDTH(x)       (((uint32_t)(((uint32_t)(x))<<LU_DU_CTRL_STARTWIDTH_SHIFT))&LU_DU_CTRL_STARTWIDTH_MASK)
#define LU_DU_CTRL_OPC_MASK            0xFu
#define LU_DU_CTRL_OPC_SHIFT           0u
#define LU_DU_CTRL_OPC_WIDTH           4u
#define LU_DU_CTRL_OPC(x)              (((uint32_t)(((uint32_t)(x))<<LU_DU_CTRL_OPC_SHIFT))&LU_DU_CTRL_OPC_MASK)
/* DU_CTRL Reg Mask */
#define LU_DU_CTRL_MASK                0xFFFFFFFFu

/* DU_INPUT_SEL Bit Fields */
#define LU_DU_INPUT_SEL_INPUTCMUX_MASK 0xF00u
#define LU_DU_INPUT_SEL_INPUTCMUX_SHIFT 8u
#define LU_DU_INPUT_SEL_INPUTCMUX_WIDTH 4u
#define LU_DU_INPUT_SEL_INPUTCMUX(x)   (((uint32_t)(((uint32_t)(x))<<LU_DU_INPUT_SEL_INPUTCMUX_SHIFT))&LU_DU_INPUT_SEL_INPUTCMUX_MASK)
#define LU_DU_INPUT_SEL_INPUTBMUX_MASK 0xF0u
#define LU_DU_INPUT_SEL_INPUTBMUX_SHIFT 4u
#define LU_DU_INPUT_SEL_INPUTBMUX_WIDTH 4u
#define LU_DU_INPUT_SEL_INPUTBMUX(x)   (((uint32_t)(((uint32_t)(x))<<LU_DU_INPUT_SEL_INPUTBMUX_SHIFT))&LU_DU_INPUT_SEL_INPUTBMUX_MASK)
#define LU_DU_INPUT_SEL_INPUTAMUX_MASK 0xFu
#define LU_DU_INPUT_SEL_INPUTAMUX_SHIFT 0u
#define LU_DU_INPUT_SEL_INPUTAMUX_WIDTH 4u
#define LU_DU_INPUT_SEL_INPUTAMUX(x)   (((uint32_t)(((uint32_t)(x))<<LU_DU_INPUT_SEL_INPUTAMUX_SHIFT))&LU_DU_INPUT_SEL_INPUTAMUX_MASK)
/* DU_INPUT_SEL Reg Mask */
#define LU_DU_INPUT_SEL_MASK           0x00000FFFu

/* DU_CFG Bit Fields */
#define LU_DU_CFG_BUFFERCLR_MASK       0x80000000u
#define LU_DU_CFG_BUFFERCLR_SHIFT      31u
#define LU_DU_CFG_BUFFERCLR_WIDTH      1u
#define LU_DU_CFG_BUFFERCLR(x)         (((uint32_t)(((uint32_t)(x))<<LU_DU_CFG_BUFFERCLR_SHIFT))&LU_DU_CFG_BUFFERCLR_MASK)
#define LU_DU_CFG_INTMATCH_MASK        0x200000u
#define LU_DU_CFG_INTMATCH_SHIFT       21u
#define LU_DU_CFG_INTMATCH_WIDTH       1u
#define LU_DU_CFG_INTMATCH(x)          (((uint32_t)(((uint32_t)(x))<<LU_DU_CFG_INTMATCH_SHIFT))&LU_DU_CFG_INTMATCH_MASK)
#define LU_DU_CFG_INTUNDERFLOW_MASK    0x100000u
#define LU_DU_CFG_INTUNDERFLOW_SHIFT   20u
#define LU_DU_CFG_INTUNDERFLOW_WIDTH   1u
#define LU_DU_CFG_INTUNDERFLOW(x)      (((uint32_t)(((uint32_t)(x))<<LU_DU_CFG_INTUNDERFLOW_SHIFT))&LU_DU_CFG_INTUNDERFLOW_MASK)
#define LU_DU_CFG_INTOVERFLOW_MASK     0x80000u
#define LU_DU_CFG_INTOVERFLOW_SHIFT    19u
#define LU_DU_CFG_INTOVERFLOW_WIDTH    1u
#define LU_DU_CFG_INTOVERFLOW(x)       (((uint32_t)(((uint32_t)(x))<<LU_DU_CFG_INTOVERFLOW_SHIFT))&LU_DU_CFG_INTOVERFLOW_MASK)
#define LU_DU_CFG_DMAMATCH_MASK        0x40000u
#define LU_DU_CFG_DMAMATCH_SHIFT       18u
#define LU_DU_CFG_DMAMATCH_WIDTH       1u
#define LU_DU_CFG_DMAMATCH(x)          (((uint32_t)(((uint32_t)(x))<<LU_DU_CFG_DMAMATCH_SHIFT))&LU_DU_CFG_DMAMATCH_MASK)
#define LU_DU_CFG_DMAUNDERFLOW_MASK    0x20000u
#define LU_DU_CFG_DMAUNDERFLOW_SHIFT   17u
#define LU_DU_CFG_DMAUNDERFLOW_WIDTH   1u
#define LU_DU_CFG_DMAUNDERFLOW(x)      (((uint32_t)(((uint32_t)(x))<<LU_DU_CFG_DMAUNDERFLOW_SHIFT))&LU_DU_CFG_DMAUNDERFLOW_MASK)
#define LU_DU_CFG_DMAOVERFLOW_MASK     0x10000u
#define LU_DU_CFG_DMAOVERFLOW_SHIFT    16u
#define LU_DU_CFG_DMAOVERFLOW_WIDTH    1u
#define LU_DU_CFG_DMAOVERFLOW(x)       (((uint32_t)(((uint32_t)(x))<<LU_DU_CFG_DMAOVERFLOW_SHIFT))&LU_DU_CFG_DMAOVERFLOW_MASK)
#define LU_DU_CFG_STARTCFG_MASK        0xFF00u
#define LU_DU_CFG_STARTCFG_SHIFT       8u
#define LU_DU_CFG_STARTCFG_WIDTH       8u
#define LU_DU_CFG_STARTCFG(x)          (((uint32_t)(((uint32_t)(x))<<LU_DU_CFG_STARTCFG_SHIFT))&LU_DU_CFG_STARTCFG_MASK)
#define LU_DU_CFG_BITCFG_MASK          0x7Fu
#define LU_DU_CFG_BITCFG_SHIFT         0u
#define LU_DU_CFG_BITCFG_WIDTH         7u
#define LU_DU_CFG_BITCFG(x)            (((uint32_t)(((uint32_t)(x))<<LU_DU_CFG_BITCFG_SHIFT))&LU_DU_CFG_BITCFG_MASK)
/* DU_CFG Reg Mask */
#define LU_DU_CFG_MASK                 0x803FFF7Fu

/* DU_DATA0 Bit Fields */
#define LU_DU_DATA0_DATA0_MASK         0xFFFFFFFFu
#define LU_DU_DATA0_DATA0_SHIFT        0u
#define LU_DU_DATA0_DATA0_WIDTH        32u
#define LU_DU_DATA0_DATA0(x)           (((uint32_t)(((uint32_t)(x))<<LU_DU_DATA0_DATA0_SHIFT))&LU_DU_DATA0_DATA0_MASK)
/* DU_DATA0 Reg Mask */
#define LU_DU_DATA0_MASK               0xFFFFFFFFu

/* DU_DATA1 Bit Fields */
#define LU_DU_DATA1_DATA1_MASK         0xFFFFFFFFu
#define LU_DU_DATA1_DATA1_SHIFT        0u
#define LU_DU_DATA1_DATA1_WIDTH        32u
#define LU_DU_DATA1_DATA1(x)           (((uint32_t)(((uint32_t)(x))<<LU_DU_DATA1_DATA1_SHIFT))&LU_DU_DATA1_DATA1_MASK)
/* DU_DATA1 Reg Mask */
#define LU_DU_DATA1_MASK               0xFFFFFFFFu

/* DU_DATA2 Bit Fields */
#define LU_DU_DATA2_DATA2_MASK         0xFFFFFFFFu
#define LU_DU_DATA2_DATA2_SHIFT        0u
#define LU_DU_DATA2_DATA2_WIDTH        32u
#define LU_DU_DATA2_DATA2(x)           (((uint32_t)(((uint32_t)(x))<<LU_DU_DATA2_DATA2_SHIFT))&LU_DU_DATA2_DATA2_MASK)
/* DU_DATA2 Reg Mask */
#define LU_DU_DATA2_MASK               0xFFFFFFFFu

/* DU_DATA3 Bit Fields */
#define LU_DU_DATA3_DATA3_MASK         0xFFFFFFFFu
#define LU_DU_DATA3_DATA3_SHIFT        0u
#define LU_DU_DATA3_DATA3_WIDTH        32u
#define LU_DU_DATA3_DATA3(x)           (((uint32_t)(((uint32_t)(x))<<LU_DU_DATA3_DATA3_SHIFT))&LU_DU_DATA3_DATA3_MASK)
/* DU_DATA3 Reg Mask */
#define LU_DU_DATA3_MASK               0xFFFFFFFFu

/* DU_DATA4 Bit Fields */
#define LU_DU_DATA4_DATA4_MASK         0xFFFFFFFFu
#define LU_DU_DATA4_DATA4_SHIFT        0u
#define LU_DU_DATA4_DATA4_WIDTH        32u
#define LU_DU_DATA4_DATA4(x)           (((uint32_t)(((uint32_t)(x))<<LU_DU_DATA4_DATA4_SHIFT))&LU_DU_DATA4_DATA4_MASK)
/* DU_DATA4 Reg Mask */
#define LU_DU_DATA4_MASK               0xFFFFFFFFu

/* DU_DATA5 Bit Fields */
#define LU_DU_DATA5_DATA5_MASK         0xFFFFFFFFu
#define LU_DU_DATA5_DATA5_SHIFT        0u
#define LU_DU_DATA5_DATA5_WIDTH        32u
#define LU_DU_DATA5_DATA5(x)           (((uint32_t)(((uint32_t)(x))<<LU_DU_DATA5_DATA5_SHIFT))&LU_DU_DATA5_DATA5_MASK)
/* DU_DATA5 Reg Mask */
#define LU_DU_DATA5_MASK               0xFFFFFFFFu

/* DU_DATA6 Bit Fields */
#define LU_DU_DATA6_DATA6_MASK         0xFFFFFFFFu
#define LU_DU_DATA6_DATA6_SHIFT        0u
#define LU_DU_DATA6_DATA6_WIDTH        32u
#define LU_DU_DATA6_DATA6(x)           (((uint32_t)(((uint32_t)(x))<<LU_DU_DATA6_DATA6_SHIFT))&LU_DU_DATA6_DATA6_MASK)
/* DU_DATA6 Reg Mask */
#define LU_DU_DATA6_MASK               0xFFFFFFFFu

/* DU_DATA7 Bit Fields */
#define LU_DU_DATA7_DATA7_MASK         0xFFFFFFFFu
#define LU_DU_DATA7_DATA7_SHIFT        0u
#define LU_DU_DATA7_DATA7_WIDTH        32u
#define LU_DU_DATA7_DATA7(x)           (((uint32_t)(((uint32_t)(x))<<LU_DU_DATA7_DATA7_SHIFT))&LU_DU_DATA7_DATA7_MASK)
/* DU_DATA7 Reg Mask */
#define LU_DU_DATA7_MASK               0xFFFFFFFFu


/*!
 * @}
 */ /* end of group LU_Register_Masks */

/*!
 * @}
 */ /* end of group LU_Peripheral_Access_Layer */

#endif
