#ifndef _MODULE_LDI_gmbhdijq168_REGS_H_LDI_H_
#define _MODULE_LDI_gmbhdijq168_REGS_H_LDI_H_

/* ----------------------------------------------------------------------------
   -- LDI Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LDI_Peripheral_Access_Layer LDI Peripheral Access Layer
 * @{
 */

/** LDI - Size of Registers Arrays */

/** LDI - Register Layout Typedef */

typedef struct {

  __IO uint32_t CTRL                          ; /* Control Register, offset: 0x0 */
  __IO uint32_t CLK_CTRL                      ; /* Clock Control Register, offset: 0x4 */
       uint8_t  RESERVED_0[8];
  __IO uint32_t IRQ_EN                        ; /* Interrupt Enable Register, offset: 0x10 */
  __IO uint32_t IRQ_ST                        ; /* Interrupt Status Register, offset: 0x14 */
       uint8_t  RESERVED_1[8];
  __IO uint32_t STATUS                        ; /* LDI Status Register, offset: 0x20 */
       uint8_t  RESERVED_2[28];
  __IO uint32_t PX_CTRL                       ; /* Pixel Control Register, offset: 0x40 */
  __IO uint32_t PX_CTRL2                      ; /* Pixel Control Register 2, offset: 0x44 */
       uint8_t  RESERVED_3[8];
  __IO uint32_t PX_STATUS                     ; /* Pixel Status Register, offset: 0x50 */
       uint8_t  RESERVED_4[12];
  __IO uint32_t PXD_RCFG                      ; /* Pixel Display Row Configuration Register, offset: 0x60 */
  __IO uint32_t PXD_GCFG                      ; /* Pixel Display GCLK Configuration Register, offset: 0x64 */
  __IO uint32_t PXD_SCFG                      ; /* Pixel Display SOE Configuration Register, offset: 0x68 */
  __IO uint32_t PXD_DCFG                      ; /* Pixel Display DOE Configuration Register, offset: 0x6C */
  __IO uint32_t PXD_ICFG                      ; /* Pixel Display SDI Configuration Register, offset: 0x70 */
       uint8_t  RESERVED_5[140];
  __IO uint32_t FDR0                          ; /* LDI FIFO0 Data Register, offset: 0x100 */
  __IO uint32_t FCR0                          ; /* LDI FIFO0 Configuration Register, offset: 0x104 */
       uint8_t  RESERVED_6[8];
  __IO uint32_t FDR1                          ; /* LDI FIFO1 Data Register, offset: 0x110 */
  __IO uint32_t FCR1                          ; /* LDI FIFO1 Configuration Register, offset: 0x114 */
       uint8_t  RESERVED_7[8];
  __IO uint32_t FDR2                          ; /* LDI FIFO2 Data Register, offset: 0x120 */
  __IO uint32_t FCR2                          ; /* LDI FIFO2 Configuration Register, offset: 0x124 */
       uint8_t  RESERVED_8[8];
  __IO uint32_t FDR3                          ; /* LDI FIFO3 Data Register, offset: 0x130 */
  __IO uint32_t FCR3                          ; /* LDI FIFO3 Configuration Register, offset: 0x134 */
       uint8_t  RESERVED_9[8];
  __IO uint32_t FSR                           ; /* LDI FIFO Status Register, offset: 0x140 */

} LDI_Type, *LDI_MemMapPtr;


/* LDI - Peripheral instance base addresses */
/** Peripheral LDI base address */
#define LDI_BASE                                 (0x40445000u)
/** Peripheral LDI base pointer */
#define LDI                                      ((LDI_Type *)LDI_BASE)
// need fill by yourself
///** Number of interrupt vector arrays for the LDI module. */
//#define LDI_IRQS_ARR_COUNT                       (1u)
///** Number of interrupt channels for the LDI module. */
//#define LDI_IRQS_CH_COUNT                        (1u)
///** Interrupt vectors for the LDI peripheral type */
//#define LDI_IRQS                                 {LDI0_IRQn}


/* ----------------------------------------------------------------------------
   -- LDI Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LDI_Register_Masks LDI Register Masks
 * @{
 */

/* CTRL Bit Fields */
#define LDI_CTRL_DDRT_MASK             0x80000u
#define LDI_CTRL_DDRT_SHIFT            19u
#define LDI_CTRL_DDRT_WIDTH            1u
#define LDI_CTRL_DDRT(x)               (((uint32_t)(((uint32_t)(x))<<LDI_CTRL_DDRT_SHIFT))&LDI_CTRL_DDRT_MASK)
#define LDI_CTRL_DDR_MASK              0x40000u
#define LDI_CTRL_DDR_SHIFT             18u
#define LDI_CTRL_DDR_WIDTH             1u
#define LDI_CTRL_DDR(x)                (((uint32_t)(((uint32_t)(x))<<LDI_CTRL_DDR_SHIFT))&LDI_CTRL_DDR_MASK)
#define LDI_CTRL_EDME_MASK             0x20000u
#define LDI_CTRL_EDME_SHIFT            17u
#define LDI_CTRL_EDME_WIDTH            1u
#define LDI_CTRL_EDME(x)               (((uint32_t)(((uint32_t)(x))<<LDI_CTRL_EDME_SHIFT))&LDI_CTRL_EDME_MASK)
#define LDI_CTRL_DCLK_INV_MASK         0x10000u
#define LDI_CTRL_DCLK_INV_SHIFT        16u
#define LDI_CTRL_DCLK_INV_WIDTH        1u
#define LDI_CTRL_DCLK_INV(x)           (((uint32_t)(((uint32_t)(x))<<LDI_CTRL_DCLK_INV_SHIFT))&LDI_CTRL_DCLK_INV_MASK)
#define LDI_CTRL_CLR_FIFO3_MASK        0x800u
#define LDI_CTRL_CLR_FIFO3_SHIFT       11u
#define LDI_CTRL_CLR_FIFO3_WIDTH       1u
#define LDI_CTRL_CLR_FIFO3(x)          (((uint32_t)(((uint32_t)(x))<<LDI_CTRL_CLR_FIFO3_SHIFT))&LDI_CTRL_CLR_FIFO3_MASK)
#define LDI_CTRL_CLR_FIFO2_MASK        0x400u
#define LDI_CTRL_CLR_FIFO2_SHIFT       10u
#define LDI_CTRL_CLR_FIFO2_WIDTH       1u
#define LDI_CTRL_CLR_FIFO2(x)          (((uint32_t)(((uint32_t)(x))<<LDI_CTRL_CLR_FIFO2_SHIFT))&LDI_CTRL_CLR_FIFO2_MASK)
#define LDI_CTRL_CLR_FIFO1_MASK        0x200u
#define LDI_CTRL_CLR_FIFO1_SHIFT       9u
#define LDI_CTRL_CLR_FIFO1_WIDTH       1u
#define LDI_CTRL_CLR_FIFO1(x)          (((uint32_t)(((uint32_t)(x))<<LDI_CTRL_CLR_FIFO1_SHIFT))&LDI_CTRL_CLR_FIFO1_MASK)
#define LDI_CTRL_CLR_FIFO0_MASK        0x100u
#define LDI_CTRL_CLR_FIFO0_SHIFT       8u
#define LDI_CTRL_CLR_FIFO0_WIDTH       1u
#define LDI_CTRL_CLR_FIFO0(x)          (((uint32_t)(((uint32_t)(x))<<LDI_CTRL_CLR_FIFO0_SHIFT))&LDI_CTRL_CLR_FIFO0_MASK)
#define LDI_CTRL_SW_RST_MASK           0x1u
#define LDI_CTRL_SW_RST_SHIFT          0u
#define LDI_CTRL_SW_RST_WIDTH          1u
#define LDI_CTRL_SW_RST(x)             (((uint32_t)(((uint32_t)(x))<<LDI_CTRL_SW_RST_SHIFT))&LDI_CTRL_SW_RST_MASK)
/* CTRL Reg Mask */
#define LDI_CTRL_MASK                  0x000F0F01u

/* CLK_CTRL Bit Fields */
#define LDI_CLK_CTRL_FCRE_MASK         0x80000000u
#define LDI_CLK_CTRL_FCRE_SHIFT        31u
#define LDI_CLK_CTRL_FCRE_WIDTH        1u
#define LDI_CLK_CTRL_FCRE(x)           (((uint32_t)(((uint32_t)(x))<<LDI_CLK_CTRL_FCRE_SHIFT))&LDI_CLK_CTRL_FCRE_MASK)
#define LDI_CLK_CTRL_FCE_MASK          0x40000000u
#define LDI_CLK_CTRL_FCE_SHIFT         30u
#define LDI_CLK_CTRL_FCE_WIDTH         1u
#define LDI_CLK_CTRL_FCE(x)            (((uint32_t)(((uint32_t)(x))<<LDI_CLK_CTRL_FCE_SHIFT))&LDI_CLK_CTRL_FCE_MASK)
#define LDI_CLK_CTRL_GCLKMUX_MASK      0x30000000u
#define LDI_CLK_CTRL_GCLKMUX_SHIFT     28u
#define LDI_CLK_CTRL_GCLKMUX_WIDTH     2u
#define LDI_CLK_CTRL_GCLKMUX(x)        (((uint32_t)(((uint32_t)(x))<<LDI_CLK_CTRL_GCLKMUX_SHIFT))&LDI_CLK_CTRL_GCLKMUX_MASK)
#define LDI_CLK_CTRL_GCLKDIV_MASK      0xF000000u
#define LDI_CLK_CTRL_GCLKDIV_SHIFT     24u
#define LDI_CLK_CTRL_GCLKDIV_WIDTH     4u
#define LDI_CLK_CTRL_GCLKDIV(x)        (((uint32_t)(((uint32_t)(x))<<LDI_CLK_CTRL_GCLKDIV_SHIFT))&LDI_CLK_CTRL_GCLKDIV_MASK)
#define LDI_CLK_CTRL_FUT_MASK          0x800000u
#define LDI_CLK_CTRL_FUT_SHIFT         23u
#define LDI_CLK_CTRL_FUT_WIDTH         1u
#define LDI_CLK_CTRL_FUT(x)            (((uint32_t)(((uint32_t)(x))<<LDI_CLK_CTRL_FUT_SHIFT))&LDI_CLK_CTRL_FUT_MASK)
#define LDI_CLK_CTRL_SSD_MASK          0x400000u
#define LDI_CLK_CTRL_SSD_SHIFT         22u
#define LDI_CLK_CTRL_SSD_WIDTH         1u
#define LDI_CLK_CTRL_SSD(x)            (((uint32_t)(((uint32_t)(x))<<LDI_CLK_CTRL_SSD_SHIFT))&LDI_CLK_CTRL_SSD_MASK)
#define LDI_CLK_CTRL_SSM_MASK          0x300000u
#define LDI_CLK_CTRL_SSM_SHIFT         20u
#define LDI_CLK_CTRL_SSM_WIDTH         2u
#define LDI_CLK_CTRL_SSM(x)            (((uint32_t)(((uint32_t)(x))<<LDI_CLK_CTRL_SSM_SHIFT))&LDI_CLK_CTRL_SSM_MASK)
#define LDI_CLK_CTRL_HDC_MASK          0xF0000u
#define LDI_CLK_CTRL_HDC_SHIFT         16u
#define LDI_CLK_CTRL_HDC_WIDTH         4u
#define LDI_CLK_CTRL_HDC(x)            (((uint32_t)(((uint32_t)(x))<<LDI_CLK_CTRL_HDC_SHIFT))&LDI_CLK_CTRL_HDC_MASK)
#define LDI_CLK_CTRL_DEN_MASK          0xFF00u
#define LDI_CLK_CTRL_DEN_SHIFT         8u
#define LDI_CLK_CTRL_DEN_WIDTH         8u
#define LDI_CLK_CTRL_DEN(x)            (((uint32_t)(((uint32_t)(x))<<LDI_CLK_CTRL_DEN_SHIFT))&LDI_CLK_CTRL_DEN_MASK)
#define LDI_CLK_CTRL_NUM_MASK          0xFFu
#define LDI_CLK_CTRL_NUM_SHIFT         0u
#define LDI_CLK_CTRL_NUM_WIDTH         8u
#define LDI_CLK_CTRL_NUM(x)            (((uint32_t)(((uint32_t)(x))<<LDI_CLK_CTRL_NUM_SHIFT))&LDI_CLK_CTRL_NUM_MASK)
/* CLK_CTRL Reg Mask */
#define LDI_CLK_CTRL_MASK              0xFFFFFFFFu

/* IRQ_EN Bit Fields */
#define LDI_IRQ_EN_PX_UPDT_MASK        0x100u
#define LDI_IRQ_EN_PX_UPDT_SHIFT       8u
#define LDI_IRQ_EN_PX_UPDT_WIDTH       1u
#define LDI_IRQ_EN_PX_UPDT(x)          (((uint32_t)(((uint32_t)(x))<<LDI_IRQ_EN_PX_UPDT_SHIFT))&LDI_IRQ_EN_PX_UPDT_MASK)
#define LDI_IRQ_EN_PX_DISP_MASK        0x1u
#define LDI_IRQ_EN_PX_DISP_SHIFT       0u
#define LDI_IRQ_EN_PX_DISP_WIDTH       1u
#define LDI_IRQ_EN_PX_DISP(x)          (((uint32_t)(((uint32_t)(x))<<LDI_IRQ_EN_PX_DISP_SHIFT))&LDI_IRQ_EN_PX_DISP_MASK)
/* IRQ_EN Reg Mask */
#define LDI_IRQ_EN_MASK                0x00000101u

/* IRQ_ST Bit Fields */
#define LDI_IRQ_ST_PX_UPDT_MASK        0x100u
#define LDI_IRQ_ST_PX_UPDT_SHIFT       8u
#define LDI_IRQ_ST_PX_UPDT_WIDTH       1u
#define LDI_IRQ_ST_PX_UPDT(x)          (((uint32_t)(((uint32_t)(x))<<LDI_IRQ_ST_PX_UPDT_SHIFT))&LDI_IRQ_ST_PX_UPDT_MASK)
#define LDI_IRQ_ST_PX_DISP_MASK        0x1u
#define LDI_IRQ_ST_PX_DISP_SHIFT       0u
#define LDI_IRQ_ST_PX_DISP_WIDTH       1u
#define LDI_IRQ_ST_PX_DISP(x)          (((uint32_t)(((uint32_t)(x))<<LDI_IRQ_ST_PX_DISP_SHIFT))&LDI_IRQ_ST_PX_DISP_MASK)
/* IRQ_ST Reg Mask */
#define LDI_IRQ_ST_MASK                0x00000101u

/* STATUS Bit Fields */
#define LDI_STATUS_UP_STATE_MASK       0x100u
#define LDI_STATUS_UP_STATE_SHIFT      8u
#define LDI_STATUS_UP_STATE_WIDTH      1u
#define LDI_STATUS_UP_STATE(x)         (((uint32_t)(((uint32_t)(x))<<LDI_STATUS_UP_STATE_SHIFT))&LDI_STATUS_UP_STATE_MASK)
#define LDI_STATUS_DISP_STATE_MASK     0x1u
#define LDI_STATUS_DISP_STATE_SHIFT    0u
#define LDI_STATUS_DISP_STATE_WIDTH    1u
#define LDI_STATUS_DISP_STATE(x)       (((uint32_t)(((uint32_t)(x))<<LDI_STATUS_DISP_STATE_SHIFT))&LDI_STATUS_DISP_STATE_MASK)
/* STATUS Reg Mask */
#define LDI_STATUS_MASK                0x00000101u

/* PX_CTRL Bit Fields */
#define LDI_PX_CTRL_ROWS_MASK          0xFF000000u
#define LDI_PX_CTRL_ROWS_SHIFT         24u
#define LDI_PX_CTRL_ROWS_WIDTH         8u
#define LDI_PX_CTRL_ROWS(x)            (((uint32_t)(((uint32_t)(x))<<LDI_PX_CTRL_ROWS_SHIFT))&LDI_PX_CTRL_ROWS_MASK)
#define LDI_PX_CTRL_CHNS_MASK          0xFF0000u
#define LDI_PX_CTRL_CHNS_SHIFT         16u
#define LDI_PX_CTRL_CHNS_WIDTH         8u
#define LDI_PX_CTRL_CHNS(x)            (((uint32_t)(((uint32_t)(x))<<LDI_PX_CTRL_CHNS_SHIFT))&LDI_PX_CTRL_CHNS_MASK)
#define LDI_PX_CTRL_CASCDS_MASK        0xFF00u
#define LDI_PX_CTRL_CASCDS_SHIFT       8u
#define LDI_PX_CTRL_CASCDS_WIDTH       8u
#define LDI_PX_CTRL_CASCDS(x)          (((uint32_t)(((uint32_t)(x))<<LDI_PX_CTRL_CASCDS_SHIFT))&LDI_PX_CTRL_CASCDS_MASK)
#define LDI_PX_CTRL_PIXEL_END_MASK     0x10u
#define LDI_PX_CTRL_PIXEL_END_SHIFT    4u
#define LDI_PX_CTRL_PIXEL_END_WIDTH    1u
#define LDI_PX_CTRL_PIXEL_END(x)       (((uint32_t)(((uint32_t)(x))<<LDI_PX_CTRL_PIXEL_END_SHIFT))&LDI_PX_CTRL_PIXEL_END_MASK)
#define LDI_PX_CTRL_DNUMS_MASK         0xFu
#define LDI_PX_CTRL_DNUMS_SHIFT        0u
#define LDI_PX_CTRL_DNUMS_WIDTH        4u
#define LDI_PX_CTRL_DNUMS(x)           (((uint32_t)(((uint32_t)(x))<<LDI_PX_CTRL_DNUMS_SHIFT))&LDI_PX_CTRL_DNUMS_MASK)
/* PX_CTRL Reg Mask */
#define LDI_PX_CTRL_MASK               0xFFFFFF1Fu

/* PX_CTRL2 Bit Fields */
#define LDI_PX_CTRL2_GCLK_CONT_MASK    0x10000000u
#define LDI_PX_CTRL2_GCLK_CONT_SHIFT   28u
#define LDI_PX_CTRL2_GCLK_CONT_WIDTH   1u
#define LDI_PX_CTRL2_GCLK_CONT(x)      (((uint32_t)(((uint32_t)(x))<<LDI_PX_CTRL2_GCLK_CONT_SHIFT))&LDI_PX_CTRL2_GCLK_CONT_MASK)
#define LDI_PX_CTRL2_DCLK_CONT_MASK    0x2000000u
#define LDI_PX_CTRL2_DCLK_CONT_SHIFT   25u
#define LDI_PX_CTRL2_DCLK_CONT_WIDTH   1u
#define LDI_PX_CTRL2_DCLK_CONT(x)      (((uint32_t)(((uint32_t)(x))<<LDI_PX_CTRL2_DCLK_CONT_SHIFT))&LDI_PX_CTRL2_DCLK_CONT_MASK)
#define LDI_PX_CTRL2_DISP_SIZE_EN_MASK 0x1000000u
#define LDI_PX_CTRL2_DISP_SIZE_EN_SHIFT 24u
#define LDI_PX_CTRL2_DISP_SIZE_EN_WIDTH 1u
#define LDI_PX_CTRL2_DISP_SIZE_EN(x)   (((uint32_t)(((uint32_t)(x))<<LDI_PX_CTRL2_DISP_SIZE_EN_SHIFT))&LDI_PX_CTRL2_DISP_SIZE_EN_MASK)
#define LDI_PX_CTRL2_DISP_SIZE_MASK    0xFF0000u
#define LDI_PX_CTRL2_DISP_SIZE_SHIFT   16u
#define LDI_PX_CTRL2_DISP_SIZE_WIDTH   8u
#define LDI_PX_CTRL2_DISP_SIZE(x)      (((uint32_t)(((uint32_t)(x))<<LDI_PX_CTRL2_DISP_SIZE_SHIFT))&LDI_PX_CTRL2_DISP_SIZE_MASK)
#define LDI_PX_CTRL2_DCLK_WT_EN_MASK   0x100u
#define LDI_PX_CTRL2_DCLK_WT_EN_SHIFT  8u
#define LDI_PX_CTRL2_DCLK_WT_EN_WIDTH  1u
#define LDI_PX_CTRL2_DCLK_WT_EN(x)     (((uint32_t)(((uint32_t)(x))<<LDI_PX_CTRL2_DCLK_WT_EN_SHIFT))&LDI_PX_CTRL2_DCLK_WT_EN_MASK)
#define LDI_PX_CTRL2_DCLK_WT_CNT_MASK  0xF0u
#define LDI_PX_CTRL2_DCLK_WT_CNT_SHIFT 4u
#define LDI_PX_CTRL2_DCLK_WT_CNT_WIDTH 4u
#define LDI_PX_CTRL2_DCLK_WT_CNT(x)    (((uint32_t)(((uint32_t)(x))<<LDI_PX_CTRL2_DCLK_WT_CNT_SHIFT))&LDI_PX_CTRL2_DCLK_WT_CNT_MASK)
#define LDI_PX_CTRL2_PINS_MASK         0xFu
#define LDI_PX_CTRL2_PINS_SHIFT        0u
#define LDI_PX_CTRL2_PINS_WIDTH        4u
#define LDI_PX_CTRL2_PINS(x)           (((uint32_t)(((uint32_t)(x))<<LDI_PX_CTRL2_PINS_SHIFT))&LDI_PX_CTRL2_PINS_MASK)
/* PX_CTRL2 Reg Mask */
#define LDI_PX_CTRL2_MASK              0x13FF01FFu

/* PX_STATUS Bit Fields */
#define LDI_PX_STATUS_TR_SIZE_MASK     0xFFFFFF00u
#define LDI_PX_STATUS_TR_SIZE_SHIFT    8u
#define LDI_PX_STATUS_TR_SIZE_WIDTH    24u
#define LDI_PX_STATUS_TR_SIZE(x)       (((uint32_t)(((uint32_t)(x))<<LDI_PX_STATUS_TR_SIZE_SHIFT))&LDI_PX_STATUS_TR_SIZE_MASK)
#define LDI_PX_STATUS_UP_START_MASK    0x2u
#define LDI_PX_STATUS_UP_START_SHIFT   1u
#define LDI_PX_STATUS_UP_START_WIDTH   1u
#define LDI_PX_STATUS_UP_START(x)      (((uint32_t)(((uint32_t)(x))<<LDI_PX_STATUS_UP_START_SHIFT))&LDI_PX_STATUS_UP_START_MASK)
#define LDI_PX_STATUS_DISP_START_MASK  0x1u
#define LDI_PX_STATUS_DISP_START_SHIFT 0u
#define LDI_PX_STATUS_DISP_START_WIDTH 1u
#define LDI_PX_STATUS_DISP_START(x)    (((uint32_t)(((uint32_t)(x))<<LDI_PX_STATUS_DISP_START_SHIFT))&LDI_PX_STATUS_DISP_START_MASK)
/* PX_STATUS Reg Mask */
#define LDI_PX_STATUS_MASK             0xFFFFFF03u

/* PXD_RCFG Bit Fields */
#define LDI_PXD_RCFG_RCFG_MASK         0xFFu
#define LDI_PXD_RCFG_RCFG_SHIFT        0u
#define LDI_PXD_RCFG_RCFG_WIDTH        8u
#define LDI_PXD_RCFG_RCFG(x)           (((uint32_t)(((uint32_t)(x))<<LDI_PXD_RCFG_RCFG_SHIFT))&LDI_PXD_RCFG_RCFG_MASK)
/* PXD_RCFG Reg Mask */
#define LDI_PXD_RCFG_MASK              0x000000FFu

/* PXD_GCFG Bit Fields */
#define LDI_PXD_GCFG_GCLK_START_MASK   0xFF000000u
#define LDI_PXD_GCFG_GCLK_START_SHIFT  24u
#define LDI_PXD_GCFG_GCLK_START_WIDTH  8u
#define LDI_PXD_GCFG_GCLK_START(x)     (((uint32_t)(((uint32_t)(x))<<LDI_PXD_GCFG_GCLK_START_SHIFT))&LDI_PXD_GCFG_GCLK_START_MASK)
#define LDI_PXD_GCFG_GCLK_RMODE_MASK   0x800000u
#define LDI_PXD_GCFG_GCLK_RMODE_SHIFT  23u
#define LDI_PXD_GCFG_GCLK_RMODE_WIDTH  1u
#define LDI_PXD_GCFG_GCLK_RMODE(x)     (((uint32_t)(((uint32_t)(x))<<LDI_PXD_GCFG_GCLK_RMODE_SHIFT))&LDI_PXD_GCFG_GCLK_RMODE_MASK)
#define LDI_PXD_GCFG_GCLK_PERIOD_MASK  0x7FFF00u
#define LDI_PXD_GCFG_GCLK_PERIOD_SHIFT 8u
#define LDI_PXD_GCFG_GCLK_PERIOD_WIDTH 15u
#define LDI_PXD_GCFG_GCLK_PERIOD(x)    (((uint32_t)(((uint32_t)(x))<<LDI_PXD_GCFG_GCLK_PERIOD_SHIFT))&LDI_PXD_GCFG_GCLK_PERIOD_MASK)
#define LDI_PXD_GCFG_GCLK_END_MASK     0xFFu
#define LDI_PXD_GCFG_GCLK_END_SHIFT    0u
#define LDI_PXD_GCFG_GCLK_END_WIDTH    8u
#define LDI_PXD_GCFG_GCLK_END(x)       (((uint32_t)(((uint32_t)(x))<<LDI_PXD_GCFG_GCLK_END_SHIFT))&LDI_PXD_GCFG_GCLK_END_MASK)
/* PXD_GCFG Reg Mask */
#define LDI_PXD_GCFG_MASK              0xFFFFFFFFu

/* PXD_SCFG Bit Fields */
#define LDI_PXD_SCFG_SET_MASK          0xFF000000u
#define LDI_PXD_SCFG_SET_SHIFT         24u
#define LDI_PXD_SCFG_SET_WIDTH         8u
#define LDI_PXD_SCFG_SET(x)            (((uint32_t)(((uint32_t)(x))<<LDI_PXD_SCFG_SET_SHIFT))&LDI_PXD_SCFG_SET_MASK)
#define LDI_PXD_SCFG_CLR_MASK          0xFF0000u
#define LDI_PXD_SCFG_CLR_SHIFT         16u
#define LDI_PXD_SCFG_CLR_WIDTH         8u
#define LDI_PXD_SCFG_CLR(x)            (((uint32_t)(((uint32_t)(x))<<LDI_PXD_SCFG_CLR_SHIFT))&LDI_PXD_SCFG_CLR_MASK)
#define LDI_PXD_SCFG_CLKM_MASK         0x2u
#define LDI_PXD_SCFG_CLKM_SHIFT        1u
#define LDI_PXD_SCFG_CLKM_WIDTH        1u
#define LDI_PXD_SCFG_CLKM(x)           (((uint32_t)(((uint32_t)(x))<<LDI_PXD_SCFG_CLKM_SHIFT))&LDI_PXD_SCFG_CLKM_MASK)
#define LDI_PXD_SCFG_REPEAT_MASK       0x1u
#define LDI_PXD_SCFG_REPEAT_SHIFT      0u
#define LDI_PXD_SCFG_REPEAT_WIDTH      1u
#define LDI_PXD_SCFG_REPEAT(x)         (((uint32_t)(((uint32_t)(x))<<LDI_PXD_SCFG_REPEAT_SHIFT))&LDI_PXD_SCFG_REPEAT_MASK)
/* PXD_SCFG Reg Mask */
#define LDI_PXD_SCFG_MASK              0xFFFF0003u

/* PXD_DCFG Bit Fields */
#define LDI_PXD_DCFG_SET_MASK          0xFF000000u
#define LDI_PXD_DCFG_SET_SHIFT         24u
#define LDI_PXD_DCFG_SET_WIDTH         8u
#define LDI_PXD_DCFG_SET(x)            (((uint32_t)(((uint32_t)(x))<<LDI_PXD_DCFG_SET_SHIFT))&LDI_PXD_DCFG_SET_MASK)
#define LDI_PXD_DCFG_CLR_MASK          0xFF0000u
#define LDI_PXD_DCFG_CLR_SHIFT         16u
#define LDI_PXD_DCFG_CLR_WIDTH         8u
#define LDI_PXD_DCFG_CLR(x)            (((uint32_t)(((uint32_t)(x))<<LDI_PXD_DCFG_CLR_SHIFT))&LDI_PXD_DCFG_CLR_MASK)
#define LDI_PXD_DCFG_CLKM_MASK         0x2u
#define LDI_PXD_DCFG_CLKM_SHIFT        1u
#define LDI_PXD_DCFG_CLKM_WIDTH        1u
#define LDI_PXD_DCFG_CLKM(x)           (((uint32_t)(((uint32_t)(x))<<LDI_PXD_DCFG_CLKM_SHIFT))&LDI_PXD_DCFG_CLKM_MASK)
#define LDI_PXD_DCFG_REPEAT_MASK       0x1u
#define LDI_PXD_DCFG_REPEAT_SHIFT      0u
#define LDI_PXD_DCFG_REPEAT_WIDTH      1u
#define LDI_PXD_DCFG_REPEAT(x)         (((uint32_t)(((uint32_t)(x))<<LDI_PXD_DCFG_REPEAT_SHIFT))&LDI_PXD_DCFG_REPEAT_MASK)
/* PXD_DCFG Reg Mask */
#define LDI_PXD_DCFG_MASK              0xFFFF0003u

/* PXD_ICFG Bit Fields */
#define LDI_PXD_ICFG_SET_MASK          0xFF000000u
#define LDI_PXD_ICFG_SET_SHIFT         24u
#define LDI_PXD_ICFG_SET_WIDTH         8u
#define LDI_PXD_ICFG_SET(x)            (((uint32_t)(((uint32_t)(x))<<LDI_PXD_ICFG_SET_SHIFT))&LDI_PXD_ICFG_SET_MASK)
#define LDI_PXD_ICFG_CLR_MASK          0xFF0000u
#define LDI_PXD_ICFG_CLR_SHIFT         16u
#define LDI_PXD_ICFG_CLR_WIDTH         8u
#define LDI_PXD_ICFG_CLR(x)            (((uint32_t)(((uint32_t)(x))<<LDI_PXD_ICFG_CLR_SHIFT))&LDI_PXD_ICFG_CLR_MASK)
#define LDI_PXD_ICFG_CLKM_MASK         0x2u
#define LDI_PXD_ICFG_CLKM_SHIFT        1u
#define LDI_PXD_ICFG_CLKM_WIDTH        1u
#define LDI_PXD_ICFG_CLKM(x)           (((uint32_t)(((uint32_t)(x))<<LDI_PXD_ICFG_CLKM_SHIFT))&LDI_PXD_ICFG_CLKM_MASK)
#define LDI_PXD_ICFG_REPEAT_MASK       0x1u
#define LDI_PXD_ICFG_REPEAT_SHIFT      0u
#define LDI_PXD_ICFG_REPEAT_WIDTH      1u
#define LDI_PXD_ICFG_REPEAT(x)         (((uint32_t)(((uint32_t)(x))<<LDI_PXD_ICFG_REPEAT_SHIFT))&LDI_PXD_ICFG_REPEAT_MASK)
/* PXD_ICFG Reg Mask */
#define LDI_PXD_ICFG_MASK              0xFFFF0003u

/* FDR0 Bit Fields */
#define LDI_FDR0_DATA_MASK             0xFFFFFFFFu
#define LDI_FDR0_DATA_SHIFT            0u
#define LDI_FDR0_DATA_WIDTH            32u
#define LDI_FDR0_DATA(x)               (((uint32_t)(((uint32_t)(x))<<LDI_FDR0_DATA_SHIFT))&LDI_FDR0_DATA_MASK)
/* FDR0 Reg Mask */
#define LDI_FDR0_MASK                  0xFFFFFFFFu

/* FCR0 Bit Fields */
#define LDI_FCR0_CTR_MASK              0xFFFFFF00u
#define LDI_FCR0_CTR_SHIFT             8u
#define LDI_FCR0_CTR_WIDTH             24u
#define LDI_FCR0_CTR(x)                (((uint32_t)(((uint32_t)(x))<<LDI_FCR0_CTR_SHIFT))&LDI_FCR0_CTR_MASK)
#define LDI_FCR0_FL_MASK               0xF0u
#define LDI_FCR0_FL_SHIFT              4u
#define LDI_FCR0_FL_WIDTH              4u
#define LDI_FCR0_FL(x)                 (((uint32_t)(((uint32_t)(x))<<LDI_FCR0_FL_SHIFT))&LDI_FCR0_FL_MASK)
#define LDI_FCR0_EDC_MASK              0x8u
#define LDI_FCR0_EDC_SHIFT             3u
#define LDI_FCR0_EDC_WIDTH             1u
#define LDI_FCR0_EDC(x)                (((uint32_t)(((uint32_t)(x))<<LDI_FCR0_EDC_SHIFT))&LDI_FCR0_EDC_MASK)
#define LDI_FCR0_WMRK_MASK             0x7u
#define LDI_FCR0_WMRK_SHIFT            0u
#define LDI_FCR0_WMRK_WIDTH            3u
#define LDI_FCR0_WMRK(x)               (((uint32_t)(((uint32_t)(x))<<LDI_FCR0_WMRK_SHIFT))&LDI_FCR0_WMRK_MASK)
/* FCR0 Reg Mask */
#define LDI_FCR0_MASK                  0xFFFFFFFFu

/* FDR1 Bit Fields */
#define LDI_FDR1_DATA_MASK             0xFFFFFFFFu
#define LDI_FDR1_DATA_SHIFT            0u
#define LDI_FDR1_DATA_WIDTH            32u
#define LDI_FDR1_DATA(x)               (((uint32_t)(((uint32_t)(x))<<LDI_FDR1_DATA_SHIFT))&LDI_FDR1_DATA_MASK)
/* FDR1 Reg Mask */
#define LDI_FDR1_MASK                  0xFFFFFFFFu

/* FCR1 Bit Fields */
#define LDI_FCR1_CTR_MASK              0xFFFFFF00u
#define LDI_FCR1_CTR_SHIFT             8u
#define LDI_FCR1_CTR_WIDTH             24u
#define LDI_FCR1_CTR(x)                (((uint32_t)(((uint32_t)(x))<<LDI_FCR1_CTR_SHIFT))&LDI_FCR1_CTR_MASK)
#define LDI_FCR1_FL_MASK               0xF0u
#define LDI_FCR1_FL_SHIFT              4u
#define LDI_FCR1_FL_WIDTH              4u
#define LDI_FCR1_FL(x)                 (((uint32_t)(((uint32_t)(x))<<LDI_FCR1_FL_SHIFT))&LDI_FCR1_FL_MASK)
#define LDI_FCR1_EDC_MASK              0x8u
#define LDI_FCR1_EDC_SHIFT             3u
#define LDI_FCR1_EDC_WIDTH             1u
#define LDI_FCR1_EDC(x)                (((uint32_t)(((uint32_t)(x))<<LDI_FCR1_EDC_SHIFT))&LDI_FCR1_EDC_MASK)
#define LDI_FCR1_WMRK_MASK             0x7u
#define LDI_FCR1_WMRK_SHIFT            0u
#define LDI_FCR1_WMRK_WIDTH            3u
#define LDI_FCR1_WMRK(x)               (((uint32_t)(((uint32_t)(x))<<LDI_FCR1_WMRK_SHIFT))&LDI_FCR1_WMRK_MASK)
/* FCR1 Reg Mask */
#define LDI_FCR1_MASK                  0xFFFFFFFFu

/* FDR2 Bit Fields */
#define LDI_FDR2_DATA_MASK             0xFFFFFFFFu
#define LDI_FDR2_DATA_SHIFT            0u
#define LDI_FDR2_DATA_WIDTH            32u
#define LDI_FDR2_DATA(x)               (((uint32_t)(((uint32_t)(x))<<LDI_FDR2_DATA_SHIFT))&LDI_FDR2_DATA_MASK)
/* FDR2 Reg Mask */
#define LDI_FDR2_MASK                  0xFFFFFFFFu

/* FCR2 Bit Fields */
#define LDI_FCR2_CTR_MASK              0xFFFFFF00u
#define LDI_FCR2_CTR_SHIFT             8u
#define LDI_FCR2_CTR_WIDTH             24u
#define LDI_FCR2_CTR(x)                (((uint32_t)(((uint32_t)(x))<<LDI_FCR2_CTR_SHIFT))&LDI_FCR2_CTR_MASK)
#define LDI_FCR2_FL_MASK               0xF0u
#define LDI_FCR2_FL_SHIFT              4u
#define LDI_FCR2_FL_WIDTH              4u
#define LDI_FCR2_FL(x)                 (((uint32_t)(((uint32_t)(x))<<LDI_FCR2_FL_SHIFT))&LDI_FCR2_FL_MASK)
#define LDI_FCR2_EDC_MASK              0x8u
#define LDI_FCR2_EDC_SHIFT             3u
#define LDI_FCR2_EDC_WIDTH             1u
#define LDI_FCR2_EDC(x)                (((uint32_t)(((uint32_t)(x))<<LDI_FCR2_EDC_SHIFT))&LDI_FCR2_EDC_MASK)
#define LDI_FCR2_WMRK_MASK             0x7u
#define LDI_FCR2_WMRK_SHIFT            0u
#define LDI_FCR2_WMRK_WIDTH            3u
#define LDI_FCR2_WMRK(x)               (((uint32_t)(((uint32_t)(x))<<LDI_FCR2_WMRK_SHIFT))&LDI_FCR2_WMRK_MASK)
/* FCR2 Reg Mask */
#define LDI_FCR2_MASK                  0xFFFFFFFFu

/* FDR3 Bit Fields */
#define LDI_FDR3_DATA_MASK             0xFFFFFFFFu
#define LDI_FDR3_DATA_SHIFT            0u
#define LDI_FDR3_DATA_WIDTH            32u
#define LDI_FDR3_DATA(x)               (((uint32_t)(((uint32_t)(x))<<LDI_FDR3_DATA_SHIFT))&LDI_FDR3_DATA_MASK)
/* FDR3 Reg Mask */
#define LDI_FDR3_MASK                  0xFFFFFFFFu

/* FCR3 Bit Fields */
#define LDI_FCR3_CTR_MASK              0xFFFFFF00u
#define LDI_FCR3_CTR_SHIFT             8u
#define LDI_FCR3_CTR_WIDTH             24u
#define LDI_FCR3_CTR(x)                (((uint32_t)(((uint32_t)(x))<<LDI_FCR3_CTR_SHIFT))&LDI_FCR3_CTR_MASK)
#define LDI_FCR3_FL_MASK               0xF0u
#define LDI_FCR3_FL_SHIFT              4u
#define LDI_FCR3_FL_WIDTH              4u
#define LDI_FCR3_FL(x)                 (((uint32_t)(((uint32_t)(x))<<LDI_FCR3_FL_SHIFT))&LDI_FCR3_FL_MASK)
#define LDI_FCR3_EDC_MASK              0x8u
#define LDI_FCR3_EDC_SHIFT             3u
#define LDI_FCR3_EDC_WIDTH             1u
#define LDI_FCR3_EDC(x)                (((uint32_t)(((uint32_t)(x))<<LDI_FCR3_EDC_SHIFT))&LDI_FCR3_EDC_MASK)
#define LDI_FCR3_WMRK_MASK             0x7u
#define LDI_FCR3_WMRK_SHIFT            0u
#define LDI_FCR3_WMRK_WIDTH            3u
#define LDI_FCR3_WMRK(x)               (((uint32_t)(((uint32_t)(x))<<LDI_FCR3_WMRK_SHIFT))&LDI_FCR3_WMRK_MASK)
/* FCR3 Reg Mask */
#define LDI_FCR3_MASK                  0xFFFFFFFFu

/* FSR Bit Fields */
#define LDI_FSR_FD3_MASK               0x10000000u
#define LDI_FSR_FD3_SHIFT              28u
#define LDI_FSR_FD3_WIDTH              1u
#define LDI_FSR_FD3(x)                 (((uint32_t)(((uint32_t)(x))<<LDI_FSR_FD3_SHIFT))&LDI_FSR_FD3_MASK)
#define LDI_FSR_FWD3_MASK              0x8000000u
#define LDI_FSR_FWD3_SHIFT             27u
#define LDI_FSR_FWD3_WIDTH             1u
#define LDI_FSR_FWD3(x)                (((uint32_t)(((uint32_t)(x))<<LDI_FSR_FWD3_SHIFT))&LDI_FSR_FWD3_MASK)
#define LDI_FSR_FED3_MASK              0x4000000u
#define LDI_FSR_FED3_SHIFT             26u
#define LDI_FSR_FED3_WIDTH             1u
#define LDI_FSR_FED3(x)                (((uint32_t)(((uint32_t)(x))<<LDI_FSR_FED3_SHIFT))&LDI_FSR_FED3_MASK)
#define LDI_FSR_FF3_MASK               0x2000000u
#define LDI_FSR_FF3_SHIFT              25u
#define LDI_FSR_FF3_WIDTH              1u
#define LDI_FSR_FF3(x)                 (((uint32_t)(((uint32_t)(x))<<LDI_FSR_FF3_SHIFT))&LDI_FSR_FF3_MASK)
#define LDI_FSR_FU3_MASK               0x1000000u
#define LDI_FSR_FU3_SHIFT              24u
#define LDI_FSR_FU3_WIDTH              1u
#define LDI_FSR_FU3(x)                 (((uint32_t)(((uint32_t)(x))<<LDI_FSR_FU3_SHIFT))&LDI_FSR_FU3_MASK)
#define LDI_FSR_FD2_MASK               0x100000u
#define LDI_FSR_FD2_SHIFT              20u
#define LDI_FSR_FD2_WIDTH              1u
#define LDI_FSR_FD2(x)                 (((uint32_t)(((uint32_t)(x))<<LDI_FSR_FD2_SHIFT))&LDI_FSR_FD2_MASK)
#define LDI_FSR_FWD2_MASK              0x80000u
#define LDI_FSR_FWD2_SHIFT             19u
#define LDI_FSR_FWD2_WIDTH             1u
#define LDI_FSR_FWD2(x)                (((uint32_t)(((uint32_t)(x))<<LDI_FSR_FWD2_SHIFT))&LDI_FSR_FWD2_MASK)
#define LDI_FSR_FED2_MASK              0x40000u
#define LDI_FSR_FED2_SHIFT             18u
#define LDI_FSR_FED2_WIDTH             1u
#define LDI_FSR_FED2(x)                (((uint32_t)(((uint32_t)(x))<<LDI_FSR_FED2_SHIFT))&LDI_FSR_FED2_MASK)
#define LDI_FSR_FF2_MASK               0x20000u
#define LDI_FSR_FF2_SHIFT              17u
#define LDI_FSR_FF2_WIDTH              1u
#define LDI_FSR_FF2(x)                 (((uint32_t)(((uint32_t)(x))<<LDI_FSR_FF2_SHIFT))&LDI_FSR_FF2_MASK)
#define LDI_FSR_FU2_MASK               0x10000u
#define LDI_FSR_FU2_SHIFT              16u
#define LDI_FSR_FU2_WIDTH              1u
#define LDI_FSR_FU2(x)                 (((uint32_t)(((uint32_t)(x))<<LDI_FSR_FU2_SHIFT))&LDI_FSR_FU2_MASK)
#define LDI_FSR_FD1_MASK               0x1000u
#define LDI_FSR_FD1_SHIFT              12u
#define LDI_FSR_FD1_WIDTH              1u
#define LDI_FSR_FD1(x)                 (((uint32_t)(((uint32_t)(x))<<LDI_FSR_FD1_SHIFT))&LDI_FSR_FD1_MASK)
#define LDI_FSR_FWD1_MASK              0x800u
#define LDI_FSR_FWD1_SHIFT             11u
#define LDI_FSR_FWD1_WIDTH             1u
#define LDI_FSR_FWD1(x)                (((uint32_t)(((uint32_t)(x))<<LDI_FSR_FWD1_SHIFT))&LDI_FSR_FWD1_MASK)
#define LDI_FSR_FED1_MASK              0x400u
#define LDI_FSR_FED1_SHIFT             10u
#define LDI_FSR_FED1_WIDTH             1u
#define LDI_FSR_FED1(x)                (((uint32_t)(((uint32_t)(x))<<LDI_FSR_FED1_SHIFT))&LDI_FSR_FED1_MASK)
#define LDI_FSR_FF1_MASK               0x200u
#define LDI_FSR_FF1_SHIFT              9u
#define LDI_FSR_FF1_WIDTH              1u
#define LDI_FSR_FF1(x)                 (((uint32_t)(((uint32_t)(x))<<LDI_FSR_FF1_SHIFT))&LDI_FSR_FF1_MASK)
#define LDI_FSR_FU1_MASK               0x100u
#define LDI_FSR_FU1_SHIFT              8u
#define LDI_FSR_FU1_WIDTH              1u
#define LDI_FSR_FU1(x)                 (((uint32_t)(((uint32_t)(x))<<LDI_FSR_FU1_SHIFT))&LDI_FSR_FU1_MASK)
#define LDI_FSR_FD0_MASK               0x10u
#define LDI_FSR_FD0_SHIFT              4u
#define LDI_FSR_FD0_WIDTH              1u
#define LDI_FSR_FD0(x)                 (((uint32_t)(((uint32_t)(x))<<LDI_FSR_FD0_SHIFT))&LDI_FSR_FD0_MASK)
#define LDI_FSR_FWD0_MASK              0x8u
#define LDI_FSR_FWD0_SHIFT             3u
#define LDI_FSR_FWD0_WIDTH             1u
#define LDI_FSR_FWD0(x)                (((uint32_t)(((uint32_t)(x))<<LDI_FSR_FWD0_SHIFT))&LDI_FSR_FWD0_MASK)
#define LDI_FSR_FED0_MASK              0x4u
#define LDI_FSR_FED0_SHIFT             2u
#define LDI_FSR_FED0_WIDTH             1u
#define LDI_FSR_FED0(x)                (((uint32_t)(((uint32_t)(x))<<LDI_FSR_FED0_SHIFT))&LDI_FSR_FED0_MASK)
#define LDI_FSR_FF0_MASK               0x2u
#define LDI_FSR_FF0_SHIFT              1u
#define LDI_FSR_FF0_WIDTH              1u
#define LDI_FSR_FF0(x)                 (((uint32_t)(((uint32_t)(x))<<LDI_FSR_FF0_SHIFT))&LDI_FSR_FF0_MASK)
#define LDI_FSR_FU0_MASK               0x1u
#define LDI_FSR_FU0_SHIFT              0u
#define LDI_FSR_FU0_WIDTH              1u
#define LDI_FSR_FU0(x)                 (((uint32_t)(((uint32_t)(x))<<LDI_FSR_FU0_SHIFT))&LDI_FSR_FU0_MASK)
/* FSR Reg Mask */
#define LDI_FSR_MASK                   0x1F1F1F1Fu


/*!
 * @}
 */ /* end of group LDI_Register_Masks */

/*!
 * @}
 */ /* end of group LDI_Peripheral_Access_Layer */

#endif
