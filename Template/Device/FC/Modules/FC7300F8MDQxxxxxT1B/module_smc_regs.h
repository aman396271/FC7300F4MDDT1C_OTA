#ifndef _MODULE_SMC_gmbhdijq96_REGS_H_SMC_H_
#define _MODULE_SMC_gmbhdijq96_REGS_H_SMC_H_

/* ----------------------------------------------------------------------------
   -- SMC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SMC_Peripheral_Access_Layer SMC Peripheral Access Layer
 * @{
 */

/** SMC - Size of Registers Arrays */

/** SMC - Register Layout Typedef */

typedef struct {

       uint8_t  RESERVED_0[8];
  __IO uint32_t PMPROT                        ; /* Power Mode Protection Register, offset: 0x8 */
  __IO uint32_t PMCTRL                        ; /* Power Mode Control Register, offset: 0xc */
  __IO uint32_t STANDBY_CFG                   ; /* Standby Mode Configuration Register, offset: 0x10 */
       uint8_t  RESERVED_1[4];
  __IO uint32_t WAKEUP                        ; /* Wakeup Configuration Register, offset: 0x18 */
  __IO uint32_t IOLOCK                        ; /* IO LOCK Register, offset: 0x1C */
  __IO uint32_t RAMRET                        ; /* RAM Retention Register, offset: 0x20 */
  __IO uint32_t PGCTRL                        ; /* Power Good Control Register, offset: 0x24 */
       uint8_t  RESERVED_2[40];
  __IO uint32_t AONCLKSR                      ; /* AON Clock Select Register, offset: 0x50 */
  __IO uint32_t PCU_CTRL                      ; /* PCU Control Register, offset: 0x54 */
  __IO uint32_t ISO_CTRL                      ; /* Isolation Control Register, offset: 0x58 */
  __IO uint32_t SCG_WAKEUP                    ; /* SCG Wakeup Configuration Register, offset: 0x5C */
  __IO uint32_t CCM_LPCTRL                    ; /* CCM LP Control Register, offset: 0x60 */
       uint8_t  RESERVED_3[4];
  __IO uint32_t SW_BANK0                      ; /* Software Bank Register 0, offset: 0x68 */
  __IO uint32_t SW_BANK1                      ; /* Software Bank Register 1, offset: 0x6C */
  struct {
     __IO uint32_t CFG0                       ; /* ADC Configuration0 Register, offset: 0x70 + i * 12 */
     __IO uint32_t CFG1                       ; /* ADC Configuration1 Register, offset: 0x74 + i * 12 */
     __I  uint32_t RES                        ; /* ADC Result Register, offset: 0x78 + i * 12 */
  } ADC[2];
  __IO uint32_t CLKOUT_CTRL                   ; /* CLKOUT Control Register, offset: 0x88 */

} SMC_Type, *SMC_MemMapPtr;


/* SMC - Peripheral instance base addresses */
/** Peripheral SMC base address */
#define SMC_BASE                                 (0x40045000u)
/** Peripheral SMC base pointer */
#define SMC                                      ((SMC_Type *)SMC_BASE)
// need fill by yourself
///** Number of interrupt vector arrays for the SMC module. */
//#define SMC_IRQS_ARR_COUNT                       (1u)
///** Number of interrupt channels for the SMC module. */
//#define SMC_IRQS_CH_COUNT                        (1u)
///** Interrupt vectors for the SMC peripheral type */
//#define SMC_IRQS                                 {SMC_IRQn}


/* ----------------------------------------------------------------------------
   -- SMC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SMC_Register_Masks SMC Register Masks
 * @{
 */

/* PMPROT Bit Fields */
#define SMC_PMPROT_PGCTRL_PROT_MASK    0x200u
#define SMC_PMPROT_PGCTRL_PROT_SHIFT   9u
#define SMC_PMPROT_PGCTRL_PROT_WIDTH   1u
#define SMC_PMPROT_PGCTRL_PROT(x)      (((uint32_t)(((uint32_t)(x))<<SMC_PMPROT_PGCTRL_PROT_SHIFT))&SMC_PMPROT_PGCTRL_PROT_MASK)
#define SMC_PMPROT_RAMRET_PROT_MASK    0x100u
#define SMC_PMPROT_RAMRET_PROT_SHIFT   8u
#define SMC_PMPROT_RAMRET_PROT_WIDTH   1u
#define SMC_PMPROT_RAMRET_PROT(x)      (((uint32_t)(((uint32_t)(x))<<SMC_PMPROT_RAMRET_PROT_SHIFT))&SMC_PMPROT_RAMRET_PROT_MASK)
#define SMC_PMPROT_IOLOCK_PROT_MASK    0x80u
#define SMC_PMPROT_IOLOCK_PROT_SHIFT   7u
#define SMC_PMPROT_IOLOCK_PROT_WIDTH   1u
#define SMC_PMPROT_IOLOCK_PROT(x)      (((uint32_t)(((uint32_t)(x))<<SMC_PMPROT_IOLOCK_PROT_SHIFT))&SMC_PMPROT_IOLOCK_PROT_MASK)
#define SMC_PMPROT_WAKEUP_PROT_MASK    0x40u
#define SMC_PMPROT_WAKEUP_PROT_SHIFT   6u
#define SMC_PMPROT_WAKEUP_PROT_WIDTH   1u
#define SMC_PMPROT_WAKEUP_PROT(x)      (((uint32_t)(((uint32_t)(x))<<SMC_PMPROT_WAKEUP_PROT_SHIFT))&SMC_PMPROT_WAKEUP_PROT_MASK)
#define SMC_PMPROT_STANDBY_CFG_PROT_MASK 0x10u
#define SMC_PMPROT_STANDBY_CFG_PROT_SHIFT 4u
#define SMC_PMPROT_STANDBY_CFG_PROT_WIDTH 1u
#define SMC_PMPROT_STANDBY_CFG_PROT(x) (((uint32_t)(((uint32_t)(x))<<SMC_PMPROT_STANDBY_CFG_PROT_SHIFT))&SMC_PMPROT_STANDBY_CFG_PROT_MASK)
#define SMC_PMPROT_PMCTRL_PROT_MASK    0x8u
#define SMC_PMPROT_PMCTRL_PROT_SHIFT   3u
#define SMC_PMPROT_PMCTRL_PROT_WIDTH   1u
#define SMC_PMPROT_PMCTRL_PROT(x)      (((uint32_t)(((uint32_t)(x))<<SMC_PMPROT_PMCTRL_PROT_SHIFT))&SMC_PMPROT_PMCTRL_PROT_MASK)
/* PMPROT Reg Mask */
#define SMC_PMPROT_MASK                0x000003D8u

/* PMCTRL Bit Fields */
#define SMC_PMCTRL_STOP_MODE_MASK      0x7u
#define SMC_PMCTRL_STOP_MODE_SHIFT     0u
#define SMC_PMCTRL_STOP_MODE_WIDTH     3u
#define SMC_PMCTRL_STOP_MODE(x)        (((uint32_t)(((uint32_t)(x))<<SMC_PMCTRL_STOP_MODE_SHIFT))&SMC_PMCTRL_STOP_MODE_MASK)
/* PMCTRL Reg Mask */
#define SMC_PMCTRL_MASK                0x00000007u

/* STANDBY_CFG Bit Fields */
#define SMC_STANDBY_CFG_OPTION_MASK    0x3u
#define SMC_STANDBY_CFG_OPTION_SHIFT   0u
#define SMC_STANDBY_CFG_OPTION_WIDTH   2u
#define SMC_STANDBY_CFG_OPTION(x)      (((uint32_t)(((uint32_t)(x))<<SMC_STANDBY_CFG_OPTION_SHIFT))&SMC_STANDBY_CFG_OPTION_MASK)
/* STANDBY_CFG Reg Mask */
#define SMC_STANDBY_CFG_MASK           0x00000003u

/* WAKEUP Bit Fields */
#define SMC_WAKEUP_LP_WAKEUP_CFG0_MASK 0xF0000000u
#define SMC_WAKEUP_LP_WAKEUP_CFG0_SHIFT 28u
#define SMC_WAKEUP_LP_WAKEUP_CFG0_WIDTH 4u
#define SMC_WAKEUP_LP_WAKEUP_CFG0(x)   (((uint32_t)(((uint32_t)(x))<<SMC_WAKEUP_LP_WAKEUP_CFG0_SHIFT))&SMC_WAKEUP_LP_WAKEUP_CFG0_MASK)
#define SMC_WAKEUP_LP_WAKEUP_CFG1_MASK 0xF000000u
#define SMC_WAKEUP_LP_WAKEUP_CFG1_SHIFT 24u
#define SMC_WAKEUP_LP_WAKEUP_CFG1_WIDTH 4u
#define SMC_WAKEUP_LP_WAKEUP_CFG1(x)   (((uint32_t)(((uint32_t)(x))<<SMC_WAKEUP_LP_WAKEUP_CFG1_SHIFT))&SMC_WAKEUP_LP_WAKEUP_CFG1_MASK)
#define SMC_WAKEUP_LP_WAKEUP_CFG2_MASK 0xF00000u
#define SMC_WAKEUP_LP_WAKEUP_CFG2_SHIFT 20u
#define SMC_WAKEUP_LP_WAKEUP_CFG2_WIDTH 4u
#define SMC_WAKEUP_LP_WAKEUP_CFG2(x)   (((uint32_t)(((uint32_t)(x))<<SMC_WAKEUP_LP_WAKEUP_CFG2_SHIFT))&SMC_WAKEUP_LP_WAKEUP_CFG2_MASK)
#define SMC_WAKEUP_LP_WAKEUP_CFG3_MASK 0xF0000u
#define SMC_WAKEUP_LP_WAKEUP_CFG3_SHIFT 16u
#define SMC_WAKEUP_LP_WAKEUP_CFG3_WIDTH 4u
#define SMC_WAKEUP_LP_WAKEUP_CFG3(x)   (((uint32_t)(((uint32_t)(x))<<SMC_WAKEUP_LP_WAKEUP_CFG3_SHIFT))&SMC_WAKEUP_LP_WAKEUP_CFG3_MASK)
#define SMC_WAKEUP_LP_WAKEUP_CFG4_MASK 0xF000u
#define SMC_WAKEUP_LP_WAKEUP_CFG4_SHIFT 12u
#define SMC_WAKEUP_LP_WAKEUP_CFG4_WIDTH 4u
#define SMC_WAKEUP_LP_WAKEUP_CFG4(x)   (((uint32_t)(((uint32_t)(x))<<SMC_WAKEUP_LP_WAKEUP_CFG4_SHIFT))&SMC_WAKEUP_LP_WAKEUP_CFG4_MASK)
#define SMC_WAKEUP_LP_WAKEUP_POL0_MASK 0x80u
#define SMC_WAKEUP_LP_WAKEUP_POL0_SHIFT 7u
#define SMC_WAKEUP_LP_WAKEUP_POL0_WIDTH 1u
#define SMC_WAKEUP_LP_WAKEUP_POL0(x)   (((uint32_t)(((uint32_t)(x))<<SMC_WAKEUP_LP_WAKEUP_POL0_SHIFT))&SMC_WAKEUP_LP_WAKEUP_POL0_MASK)
#define SMC_WAKEUP_LP_WAKEUP_POL1_MASK 0x40u
#define SMC_WAKEUP_LP_WAKEUP_POL1_SHIFT 6u
#define SMC_WAKEUP_LP_WAKEUP_POL1_WIDTH 1u
#define SMC_WAKEUP_LP_WAKEUP_POL1(x)   (((uint32_t)(((uint32_t)(x))<<SMC_WAKEUP_LP_WAKEUP_POL1_SHIFT))&SMC_WAKEUP_LP_WAKEUP_POL1_MASK)
#define SMC_WAKEUP_LP_WAKEUP_POL2_MASK 0x20u
#define SMC_WAKEUP_LP_WAKEUP_POL2_SHIFT 5u
#define SMC_WAKEUP_LP_WAKEUP_POL2_WIDTH 1u
#define SMC_WAKEUP_LP_WAKEUP_POL2(x)   (((uint32_t)(((uint32_t)(x))<<SMC_WAKEUP_LP_WAKEUP_POL2_SHIFT))&SMC_WAKEUP_LP_WAKEUP_POL2_MASK)
#define SMC_WAKEUP_LP_WAKEUP_POL3_MASK 0x10u
#define SMC_WAKEUP_LP_WAKEUP_POL3_SHIFT 4u
#define SMC_WAKEUP_LP_WAKEUP_POL3_WIDTH 1u
#define SMC_WAKEUP_LP_WAKEUP_POL3(x)   (((uint32_t)(((uint32_t)(x))<<SMC_WAKEUP_LP_WAKEUP_POL3_SHIFT))&SMC_WAKEUP_LP_WAKEUP_POL3_MASK)
#define SMC_WAKEUP_LP_WAKEUP_POL4_MASK 0x8u
#define SMC_WAKEUP_LP_WAKEUP_POL4_SHIFT 3u
#define SMC_WAKEUP_LP_WAKEUP_POL4_WIDTH 1u
#define SMC_WAKEUP_LP_WAKEUP_POL4(x)   (((uint32_t)(((uint32_t)(x))<<SMC_WAKEUP_LP_WAKEUP_POL4_SHIFT))&SMC_WAKEUP_LP_WAKEUP_POL4_MASK)
/* WAKEUP Reg Mask */
#define SMC_WAKEUP_MASK                0xFFFFF0F8u

/* IOLOCK Bit Fields */
#define SMC_IOLOCK_IOLOCK_CTRL0_MASK   0x80u
#define SMC_IOLOCK_IOLOCK_CTRL0_SHIFT  7u
#define SMC_IOLOCK_IOLOCK_CTRL0_WIDTH  1u
#define SMC_IOLOCK_IOLOCK_CTRL0(x)     (((uint32_t)(((uint32_t)(x))<<SMC_IOLOCK_IOLOCK_CTRL0_SHIFT))&SMC_IOLOCK_IOLOCK_CTRL0_MASK)
#define SMC_IOLOCK_IOLOCK_CTRL1_MASK   0x40u
#define SMC_IOLOCK_IOLOCK_CTRL1_SHIFT  6u
#define SMC_IOLOCK_IOLOCK_CTRL1_WIDTH  1u
#define SMC_IOLOCK_IOLOCK_CTRL1(x)     (((uint32_t)(((uint32_t)(x))<<SMC_IOLOCK_IOLOCK_CTRL1_SHIFT))&SMC_IOLOCK_IOLOCK_CTRL1_MASK)
#define SMC_IOLOCK_IOLOCK_CTRL2_MASK   0x20u
#define SMC_IOLOCK_IOLOCK_CTRL2_SHIFT  5u
#define SMC_IOLOCK_IOLOCK_CTRL2_WIDTH  1u
#define SMC_IOLOCK_IOLOCK_CTRL2(x)     (((uint32_t)(((uint32_t)(x))<<SMC_IOLOCK_IOLOCK_CTRL2_SHIFT))&SMC_IOLOCK_IOLOCK_CTRL2_MASK)
#define SMC_IOLOCK_IOLOCK_CTRL3_MASK   0x10u
#define SMC_IOLOCK_IOLOCK_CTRL3_SHIFT  4u
#define SMC_IOLOCK_IOLOCK_CTRL3_WIDTH  1u
#define SMC_IOLOCK_IOLOCK_CTRL3(x)     (((uint32_t)(((uint32_t)(x))<<SMC_IOLOCK_IOLOCK_CTRL3_SHIFT))&SMC_IOLOCK_IOLOCK_CTRL3_MASK)
#define SMC_IOLOCK_IOLOCK_CTRL4_MASK   0x8u
#define SMC_IOLOCK_IOLOCK_CTRL4_SHIFT  3u
#define SMC_IOLOCK_IOLOCK_CTRL4_WIDTH  1u
#define SMC_IOLOCK_IOLOCK_CTRL4(x)     (((uint32_t)(((uint32_t)(x))<<SMC_IOLOCK_IOLOCK_CTRL4_SHIFT))&SMC_IOLOCK_IOLOCK_CTRL4_MASK)
/* IOLOCK Reg Mask */
#define SMC_IOLOCK_MASK                0x000000F8u

/* RAMRET Bit Fields */
#define SMC_RAMRET_RETEN_MASK          0xFFFu
#define SMC_RAMRET_RETEN_SHIFT         0u
#define SMC_RAMRET_RETEN_WIDTH         12u
#define SMC_RAMRET_RETEN(x)            (((uint32_t)(((uint32_t)(x))<<SMC_RAMRET_RETEN_SHIFT))&SMC_RAMRET_RETEN_MASK)
/* RAMRET Reg Mask */
#define SMC_RAMRET_MASK                0x00000FFFu

/* PGCTRL Bit Fields */
#define SMC_PGCTRL_PG_LOCK_EN_MASK     0x80u
#define SMC_PGCTRL_PG_LOCK_EN_SHIFT    7u
#define SMC_PGCTRL_PG_LOCK_EN_WIDTH    1u
#define SMC_PGCTRL_PG_LOCK_EN(x)       (((uint32_t)(((uint32_t)(x))<<SMC_PGCTRL_PG_LOCK_EN_SHIFT))&SMC_PGCTRL_PG_LOCK_EN_MASK)
#define SMC_PGCTRL_PG_LOCK_SEL_MASK    0x30u
#define SMC_PGCTRL_PG_LOCK_SEL_SHIFT   4u
#define SMC_PGCTRL_PG_LOCK_SEL_WIDTH   2u
#define SMC_PGCTRL_PG_LOCK_SEL(x)      (((uint32_t)(((uint32_t)(x))<<SMC_PGCTRL_PG_LOCK_SEL_SHIFT))&SMC_PGCTRL_PG_LOCK_SEL_MASK)
#define SMC_PGCTRL_PG_POL_MASK         0x2u
#define SMC_PGCTRL_PG_POL_SHIFT        1u
#define SMC_PGCTRL_PG_POL_WIDTH        1u
#define SMC_PGCTRL_PG_POL(x)           (((uint32_t)(((uint32_t)(x))<<SMC_PGCTRL_PG_POL_SHIFT))&SMC_PGCTRL_PG_POL_MASK)
#define SMC_PGCTRL_PG_EN_MASK          0x1u
#define SMC_PGCTRL_PG_EN_SHIFT         0u
#define SMC_PGCTRL_PG_EN_WIDTH         1u
#define SMC_PGCTRL_PG_EN(x)            (((uint32_t)(((uint32_t)(x))<<SMC_PGCTRL_PG_EN_SHIFT))&SMC_PGCTRL_PG_EN_MASK)
/* PGCTRL Reg Mask */
#define SMC_PGCTRL_MASK                0x000000B3u

/* AONCLKSR Bit Fields */
#define SMC_AONCLKSR_AON32KCLKSEL_MASK 0xC000u
#define SMC_AONCLKSR_AON32KCLKSEL_SHIFT 14u
#define SMC_AONCLKSR_AON32KCLKSEL_WIDTH 2u
#define SMC_AONCLKSR_AON32KCLKSEL(x)   (((uint32_t)(((uint32_t)(x))<<SMC_AONCLKSR_AON32KCLKSEL_SHIFT))&SMC_AONCLKSR_AON32KCLKSEL_MASK)
#define SMC_AONCLKSR_RTCCLKSEL_MASK    0x3000u
#define SMC_AONCLKSR_RTCCLKSEL_SHIFT   12u
#define SMC_AONCLKSR_RTCCLKSEL_WIDTH   2u
#define SMC_AONCLKSR_RTCCLKSEL(x)      (((uint32_t)(((uint32_t)(x))<<SMC_AONCLKSR_RTCCLKSEL_SHIFT))&SMC_AONCLKSR_RTCCLKSEL_MASK)
#define SMC_AONCLKSR_AONCLKSEL_MASK    0xC00u
#define SMC_AONCLKSR_AONCLKSEL_SHIFT   10u
#define SMC_AONCLKSR_AONCLKSEL_WIDTH   2u
#define SMC_AONCLKSR_AONCLKSEL(x)      (((uint32_t)(((uint32_t)(x))<<SMC_AONCLKSR_AONCLKSEL_SHIFT))&SMC_AONCLKSR_AONCLKSEL_MASK)
#define SMC_AONCLKSR_SIRCDIV32KEN_MASK 0x200u
#define SMC_AONCLKSR_SIRCDIV32KEN_SHIFT 9u
#define SMC_AONCLKSR_SIRCDIV32KEN_WIDTH 1u
#define SMC_AONCLKSR_SIRCDIV32KEN(x)   (((uint32_t)(((uint32_t)(x))<<SMC_AONCLKSR_SIRCDIV32KEN_SHIFT))&SMC_AONCLKSR_SIRCDIV32KEN_MASK)
#define SMC_AONCLKSR_AON1KCLKEN_MASK   0x100u
#define SMC_AONCLKSR_AON1KCLKEN_SHIFT  8u
#define SMC_AONCLKSR_AON1KCLKEN_WIDTH  1u
#define SMC_AONCLKSR_AON1KCLKEN(x)     (((uint32_t)(((uint32_t)(x))<<SMC_AONCLKSR_AON1KCLKEN_SHIFT))&SMC_AONCLKSR_AON1KCLKEN_MASK)
#define SMC_AONCLKSR_LOCK_MASK         0x1u
#define SMC_AONCLKSR_LOCK_SHIFT        0u
#define SMC_AONCLKSR_LOCK_WIDTH        1u
#define SMC_AONCLKSR_LOCK(x)           (((uint32_t)(((uint32_t)(x))<<SMC_AONCLKSR_LOCK_SHIFT))&SMC_AONCLKSR_LOCK_MASK)
/* AONCLKSR Reg Mask */
#define SMC_AONCLKSR_MASK              0x0000FF01u

/* PCU_CTRL Bit Fields */
#define SMC_PCU_CTRL_RPM_EXIT_CNT_MASK 0x3FFF0000u
#define SMC_PCU_CTRL_RPM_EXIT_CNT_SHIFT 16u
#define SMC_PCU_CTRL_RPM_EXIT_CNT_WIDTH 14u
#define SMC_PCU_CTRL_RPM_EXIT_CNT(x)   (((uint32_t)(((uint32_t)(x))<<SMC_PCU_CTRL_RPM_EXIT_CNT_SHIFT))&SMC_PCU_CTRL_RPM_EXIT_CNT_MASK)
#define SMC_PCU_CTRL_LOCK_MASK         0x1u
#define SMC_PCU_CTRL_LOCK_SHIFT        0u
#define SMC_PCU_CTRL_LOCK_WIDTH        1u
#define SMC_PCU_CTRL_LOCK(x)           (((uint32_t)(((uint32_t)(x))<<SMC_PCU_CTRL_LOCK_SHIFT))&SMC_PCU_CTRL_LOCK_MASK)
/* PCU_CTRL Reg Mask */
#define SMC_PCU_CTRL_MASK              0x3FFF0001u

/* ISO_CTRL Bit Fields */
#define SMC_ISO_CTRL_PAD_ISO_HOLD_MASK 0x80u
#define SMC_ISO_CTRL_PAD_ISO_HOLD_SHIFT 7u
#define SMC_ISO_CTRL_PAD_ISO_HOLD_WIDTH 1u
#define SMC_ISO_CTRL_PAD_ISO_HOLD(x)   (((uint32_t)(((uint32_t)(x))<<SMC_ISO_CTRL_PAD_ISO_HOLD_SHIFT))&SMC_ISO_CTRL_PAD_ISO_HOLD_MASK)
#define SMC_ISO_CTRL_PAD_ISO_HOLD_CLR_MASK 0x40u
#define SMC_ISO_CTRL_PAD_ISO_HOLD_CLR_SHIFT 6u
#define SMC_ISO_CTRL_PAD_ISO_HOLD_CLR_WIDTH 1u
#define SMC_ISO_CTRL_PAD_ISO_HOLD_CLR(x) (((uint32_t)(((uint32_t)(x))<<SMC_ISO_CTRL_PAD_ISO_HOLD_CLR_SHIFT))&SMC_ISO_CTRL_PAD_ISO_HOLD_CLR_MASK)
#define SMC_ISO_CTRL_LOCK_MASK         0x1u
#define SMC_ISO_CTRL_LOCK_SHIFT        0u
#define SMC_ISO_CTRL_LOCK_WIDTH        1u
#define SMC_ISO_CTRL_LOCK(x)           (((uint32_t)(((uint32_t)(x))<<SMC_ISO_CTRL_LOCK_SHIFT))&SMC_ISO_CTRL_LOCK_MASK)
/* ISO_CTRL Reg Mask */
#define SMC_ISO_CTRL_MASK              0x000000C1u

/* SCG_WAKEUP Bit Fields */
#define SMC_SCG_WAKEUP_SCG_WAKEUP_CFG_MASK 0xF0000000u
#define SMC_SCG_WAKEUP_SCG_WAKEUP_CFG_SHIFT 28u
#define SMC_SCG_WAKEUP_SCG_WAKEUP_CFG_WIDTH 4u
#define SMC_SCG_WAKEUP_SCG_WAKEUP_CFG(x) (((uint32_t)(((uint32_t)(x))<<SMC_SCG_WAKEUP_SCG_WAKEUP_CFG_SHIFT))&SMC_SCG_WAKEUP_SCG_WAKEUP_CFG_MASK)
#define SMC_SCG_WAKEUP_SCG_POL_MASK    0x8000000u
#define SMC_SCG_WAKEUP_SCG_POL_SHIFT   27u
#define SMC_SCG_WAKEUP_SCG_POL_WIDTH   1u
#define SMC_SCG_WAKEUP_SCG_POL(x)      (((uint32_t)(((uint32_t)(x))<<SMC_SCG_WAKEUP_SCG_POL_SHIFT))&SMC_SCG_WAKEUP_SCG_POL_MASK)
#define SMC_SCG_WAKEUP_SCG_TRGSEL_MASK 0x3000000u
#define SMC_SCG_WAKEUP_SCG_TRGSEL_SHIFT 24u
#define SMC_SCG_WAKEUP_SCG_TRGSEL_WIDTH 2u
#define SMC_SCG_WAKEUP_SCG_TRGSEL(x)   (((uint32_t)(((uint32_t)(x))<<SMC_SCG_WAKEUP_SCG_TRGSEL_SHIFT))&SMC_SCG_WAKEUP_SCG_TRGSEL_MASK)
#define SMC_SCG_WAKEUP_LOCK_MASK       0x1u
#define SMC_SCG_WAKEUP_LOCK_SHIFT      0u
#define SMC_SCG_WAKEUP_LOCK_WIDTH      1u
#define SMC_SCG_WAKEUP_LOCK(x)         (((uint32_t)(((uint32_t)(x))<<SMC_SCG_WAKEUP_LOCK_SHIFT))&SMC_SCG_WAKEUP_LOCK_MASK)
/* SCG_WAKEUP Reg Mask */
#define SMC_SCG_WAKEUP_MASK            0xFB000001u

/* CCM_LPCTRL Bit Fields */
#define SMC_CCM_LPCTRL_GPR_CCM_STANDBY_ABORT_DIS_MASK 0xF000000u
#define SMC_CCM_LPCTRL_GPR_CCM_STANDBY_ABORT_DIS_SHIFT 24u
#define SMC_CCM_LPCTRL_GPR_CCM_STANDBY_ABORT_DIS_WIDTH 4u
#define SMC_CCM_LPCTRL_GPR_CCM_STANDBY_ABORT_DIS(x) (((uint32_t)(((uint32_t)(x))<<SMC_CCM_LPCTRL_GPR_CCM_STANDBY_ABORT_DIS_SHIFT))&SMC_CCM_LPCTRL_GPR_CCM_STANDBY_ABORT_DIS_MASK)
#define SMC_CCM_LPCTRL_LOCK_MASK       0x1u
#define SMC_CCM_LPCTRL_LOCK_SHIFT      0u
#define SMC_CCM_LPCTRL_LOCK_WIDTH      1u
#define SMC_CCM_LPCTRL_LOCK(x)         (((uint32_t)(((uint32_t)(x))<<SMC_CCM_LPCTRL_LOCK_SHIFT))&SMC_CCM_LPCTRL_LOCK_MASK)
/* CCM_LPCTRL Reg Mask */
#define SMC_CCM_LPCTRL_MASK            0x0F000001u

/* SW_BANK0 Bit Fields */
#define SMC_SW_BANK0_BANK_MASK         0xFFFFFFFFu
#define SMC_SW_BANK0_BANK_SHIFT        0u
#define SMC_SW_BANK0_BANK_WIDTH        32u
#define SMC_SW_BANK0_BANK(x)           (((uint32_t)(((uint32_t)(x))<<SMC_SW_BANK0_BANK_SHIFT))&SMC_SW_BANK0_BANK_MASK)
/* SW_BANK0 Reg Mask */
#define SMC_SW_BANK0_MASK              0xFFFFFFFFu

/* SW_BANK1 Bit Fields */
#define SMC_SW_BANK1_BANK_MASK         0xFFFFFFFFu
#define SMC_SW_BANK1_BANK_SHIFT        0u
#define SMC_SW_BANK1_BANK_WIDTH        32u
#define SMC_SW_BANK1_BANK(x)           (((uint32_t)(((uint32_t)(x))<<SMC_SW_BANK1_BANK_SHIFT))&SMC_SW_BANK1_BANK_MASK)
/* SW_BANK1 Reg Mask */
#define SMC_SW_BANK1_MASK              0xFFFFFFFFu

/* ADC_CFG0 Bit Fields */
#define SMC_ADC_CFG0_SGCMP_EN_MASK     0x80000000u
#define SMC_ADC_CFG0_SGCMP_EN_SHIFT    31u
#define SMC_ADC_CFG0_SGCMP_EN_WIDTH    1u
#define SMC_ADC_CFG0_SGCMP_EN(x)       (((uint32_t)(((uint32_t)(x))<<SMC_ADC_CFG0_SGCMP_EN_SHIFT))&SMC_ADC_CFG0_SGCMP_EN_MASK)
#define SMC_ADC_CFG0_SGCMP_IEN_MASK    0x40000000u
#define SMC_ADC_CFG0_SGCMP_IEN_SHIFT   30u
#define SMC_ADC_CFG0_SGCMP_IEN_WIDTH   1u
#define SMC_ADC_CFG0_SGCMP_IEN(x)      (((uint32_t)(((uint32_t)(x))<<SMC_ADC_CFG0_SGCMP_IEN_SHIFT))&SMC_ADC_CFG0_SGCMP_IEN_MASK)
#define SMC_ADC_CFG0_SGCMP_FLAG_CLR_MASK 0x8000000u
#define SMC_ADC_CFG0_SGCMP_FLAG_CLR_SHIFT 27u
#define SMC_ADC_CFG0_SGCMP_FLAG_CLR_WIDTH 1u
#define SMC_ADC_CFG0_SGCMP_FLAG_CLR(x) (((uint32_t)(((uint32_t)(x))<<SMC_ADC_CFG0_SGCMP_FLAG_CLR_SHIFT))&SMC_ADC_CFG0_SGCMP_FLAG_CLR_MASK)
#define SMC_ADC_CFG0_SGCMP_REF_SEL_MASK 0xFFFFFFu
#define SMC_ADC_CFG0_SGCMP_REF_SEL_SHIFT 0u
#define SMC_ADC_CFG0_SGCMP_REF_SEL_WIDTH 24u
#define SMC_ADC_CFG0_SGCMP_REF_SEL(x)  (((uint32_t)(((uint32_t)(x))<<SMC_ADC_CFG0_SGCMP_REF_SEL_SHIFT))&SMC_ADC_CFG0_SGCMP_REF_SEL_MASK)
/* ADC_CFG0 Reg Mask */
#define SMC_ADC_CFG0_MASK              0xC8FFFFFFu

/* ADC_CFG1 Bit Fields */
#define SMC_ADC_CFG1_SGCMP_ACT_SEL_MASK 0xFFFFFFu
#define SMC_ADC_CFG1_SGCMP_ACT_SEL_SHIFT 0u
#define SMC_ADC_CFG1_SGCMP_ACT_SEL_WIDTH 24u
#define SMC_ADC_CFG1_SGCMP_ACT_SEL(x)  (((uint32_t)(((uint32_t)(x))<<SMC_ADC_CFG1_SGCMP_ACT_SEL_SHIFT))&SMC_ADC_CFG1_SGCMP_ACT_SEL_MASK)
/* ADC_CFG1 Reg Mask */
#define SMC_ADC_CFG1_MASK              0x00FFFFFFu

/* ADC_RES Bit Fields */
#define SMC_ADC_RES_SGCMP_ON_MASK      0x80000000u
#define SMC_ADC_RES_SGCMP_ON_SHIFT     31u
#define SMC_ADC_RES_SGCMP_ON_WIDTH     1u
#define SMC_ADC_RES_SGCMP_ON(x)        (((uint32_t)(((uint32_t)(x))<<SMC_ADC_RES_SGCMP_ON_SHIFT))&SMC_ADC_RES_SGCMP_ON_MASK)
#define SMC_ADC_RES_SGCMP_FLAG_MASK    0x40000000u
#define SMC_ADC_RES_SGCMP_FLAG_SHIFT   30u
#define SMC_ADC_RES_SGCMP_FLAG_WIDTH   1u
#define SMC_ADC_RES_SGCMP_FLAG(x)      (((uint32_t)(((uint32_t)(x))<<SMC_ADC_RES_SGCMP_FLAG_SHIFT))&SMC_ADC_RES_SGCMP_FLAG_MASK)
#define SMC_ADC_RES_SGCMP_RES_MASK     0xFFFFFFu
#define SMC_ADC_RES_SGCMP_RES_SHIFT    0u
#define SMC_ADC_RES_SGCMP_RES_WIDTH    24u
#define SMC_ADC_RES_SGCMP_RES(x)       (((uint32_t)(((uint32_t)(x))<<SMC_ADC_RES_SGCMP_RES_SHIFT))&SMC_ADC_RES_SGCMP_RES_MASK)
/* ADC_RES Reg Mask */
#define SMC_ADC_RES_MASK               0xC0FFFFFFu

/* ADC2_CFG0 Bit Fields */
#define SMC_ADC2_CFG0_SGCMP_EN_MASK    0x80000000u
#define SMC_ADC2_CFG0_SGCMP_EN_SHIFT   31u
#define SMC_ADC2_CFG0_SGCMP_EN_WIDTH   1u
#define SMC_ADC2_CFG0_SGCMP_EN(x)      (((uint32_t)(((uint32_t)(x))<<SMC_ADC2_CFG0_SGCMP_EN_SHIFT))&SMC_ADC2_CFG0_SGCMP_EN_MASK)
#define SMC_ADC2_CFG0_SGCMP_IEN_MASK   0x40000000u
#define SMC_ADC2_CFG0_SGCMP_IEN_SHIFT  30u
#define SMC_ADC2_CFG0_SGCMP_IEN_WIDTH  1u
#define SMC_ADC2_CFG0_SGCMP_IEN(x)     (((uint32_t)(((uint32_t)(x))<<SMC_ADC2_CFG0_SGCMP_IEN_SHIFT))&SMC_ADC2_CFG0_SGCMP_IEN_MASK)
#define SMC_ADC2_CFG0_SGCMP_FLAG_CLR_MASK 0x8000000u
#define SMC_ADC2_CFG0_SGCMP_FLAG_CLR_SHIFT 27u
#define SMC_ADC2_CFG0_SGCMP_FLAG_CLR_WIDTH 1u
#define SMC_ADC2_CFG0_SGCMP_FLAG_CLR(x) (((uint32_t)(((uint32_t)(x))<<SMC_ADC2_CFG0_SGCMP_FLAG_CLR_SHIFT))&SMC_ADC2_CFG0_SGCMP_FLAG_CLR_MASK)
#define SMC_ADC2_CFG0_SGCMP_REF_SEL_MASK 0xFFFFFFu
#define SMC_ADC2_CFG0_SGCMP_REF_SEL_SHIFT 0u
#define SMC_ADC2_CFG0_SGCMP_REF_SEL_WIDTH 24u
#define SMC_ADC2_CFG0_SGCMP_REF_SEL(x) (((uint32_t)(((uint32_t)(x))<<SMC_ADC2_CFG0_SGCMP_REF_SEL_SHIFT))&SMC_ADC2_CFG0_SGCMP_REF_SEL_MASK)
/* ADC2_CFG0 Reg Mask */
#define SMC_ADC2_CFG0_MASK             0xC8FFFFFFu

/* ADC2_CFG1 Bit Fields */
#define SMC_ADC2_CFG1_SGCMP_ACT_SEL_MASK 0xFFFFFFu
#define SMC_ADC2_CFG1_SGCMP_ACT_SEL_SHIFT 0u
#define SMC_ADC2_CFG1_SGCMP_ACT_SEL_WIDTH 24u
#define SMC_ADC2_CFG1_SGCMP_ACT_SEL(x) (((uint32_t)(((uint32_t)(x))<<SMC_ADC2_CFG1_SGCMP_ACT_SEL_SHIFT))&SMC_ADC2_CFG1_SGCMP_ACT_SEL_MASK)
/* ADC2_CFG1 Reg Mask */
#define SMC_ADC2_CFG1_MASK             0x00FFFFFFu

/* ADC2_RES Bit Fields */
#define SMC_ADC2_RES_SGCMP_ON_MASK     0x80000000u
#define SMC_ADC2_RES_SGCMP_ON_SHIFT    31u
#define SMC_ADC2_RES_SGCMP_ON_WIDTH    1u
#define SMC_ADC2_RES_SGCMP_ON(x)       (((uint32_t)(((uint32_t)(x))<<SMC_ADC2_RES_SGCMP_ON_SHIFT))&SMC_ADC2_RES_SGCMP_ON_MASK)
#define SMC_ADC2_RES_SGCMP_FLAG_MASK   0x40000000u
#define SMC_ADC2_RES_SGCMP_FLAG_SHIFT  30u
#define SMC_ADC2_RES_SGCMP_FLAG_WIDTH  1u
#define SMC_ADC2_RES_SGCMP_FLAG(x)     (((uint32_t)(((uint32_t)(x))<<SMC_ADC2_RES_SGCMP_FLAG_SHIFT))&SMC_ADC2_RES_SGCMP_FLAG_MASK)
#define SMC_ADC2_RES_SGCMP_RES_MASK    0xFFFFFFu
#define SMC_ADC2_RES_SGCMP_RES_SHIFT   0u
#define SMC_ADC2_RES_SGCMP_RES_WIDTH   24u
#define SMC_ADC2_RES_SGCMP_RES(x)      (((uint32_t)(((uint32_t)(x))<<SMC_ADC2_RES_SGCMP_RES_SHIFT))&SMC_ADC2_RES_SGCMP_RES_MASK)
/* ADC2_RES Reg Mask */
#define SMC_ADC2_RES_MASK              0xC0FFFFFFu

/* CLKOUT_CTRL Bit Fields */
#define SMC_CLKOUT_CTRL_EN_MASK        0x80000000u
#define SMC_CLKOUT_CTRL_EN_SHIFT       31u
#define SMC_CLKOUT_CTRL_EN_WIDTH       1u
#define SMC_CLKOUT_CTRL_EN(x)          (((uint32_t)(((uint32_t)(x))<<SMC_CLKOUT_CTRL_EN_SHIFT))&SMC_CLKOUT_CTRL_EN_MASK)
#define SMC_CLKOUT_CTRL_DIV_MASK       0x70000000u
#define SMC_CLKOUT_CTRL_DIV_SHIFT      28u
#define SMC_CLKOUT_CTRL_DIV_WIDTH      3u
#define SMC_CLKOUT_CTRL_DIV(x)         (((uint32_t)(((uint32_t)(x))<<SMC_CLKOUT_CTRL_DIV_SHIFT))&SMC_CLKOUT_CTRL_DIV_MASK)
#define SMC_CLKOUT_CTRL_SEL_MASK       0xF000000u
#define SMC_CLKOUT_CTRL_SEL_SHIFT      24u
#define SMC_CLKOUT_CTRL_SEL_WIDTH      4u
#define SMC_CLKOUT_CTRL_SEL(x)         (((uint32_t)(((uint32_t)(x))<<SMC_CLKOUT_CTRL_SEL_SHIFT))&SMC_CLKOUT_CTRL_SEL_MASK)
#define SMC_CLKOUT_CTRL_LOCK_MASK      0x1u
#define SMC_CLKOUT_CTRL_LOCK_SHIFT     0u
#define SMC_CLKOUT_CTRL_LOCK_WIDTH     1u
#define SMC_CLKOUT_CTRL_LOCK(x)        (((uint32_t)(((uint32_t)(x))<<SMC_CLKOUT_CTRL_LOCK_SHIFT))&SMC_CLKOUT_CTRL_LOCK_MASK)
/* CLKOUT_CTRL Reg Mask */
#define SMC_CLKOUT_CTRL_MASK           0xFF000001u


/*!
 * @}
 */ /* end of group SMC_Register_Masks */

/*!
 * @}
 */ /* end of group SMC_Peripheral_Access_Layer */

#endif
