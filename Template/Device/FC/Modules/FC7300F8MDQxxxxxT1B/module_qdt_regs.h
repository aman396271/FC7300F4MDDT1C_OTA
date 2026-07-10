#ifndef _MODULE_QDT_gmbhdijq107_REGS_H_QDT_H_
#define _MODULE_QDT_gmbhdijq107_REGS_H_QDT_H_

/* ----------------------------------------------------------------------------
   -- QDT Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup QDT_Peripheral_Access_Layer QDT Peripheral Access Layer
 * @{
 */

/** QDT - Size of Registers Arrays */

/** Number of channel of the each QDT instance. */
#define QDT_CHANNEL_COUNT                       (4u)

/** QDT - Register Layout Typedef */

typedef struct {

  __IO uint32_t SC                            ; /* Status and Control Register, offset: 0x0 */
  __IO uint32_t SYNC                          ; /* Synchronization Register, offset: 0x4 */
  __IO uint32_t POL                           ; /* Polarity Register, offset: 0x8 */
  __IO uint32_t FILTER                        ; /* Input Capture Filter Control Register, offset: 0xC */
  __IO uint32_t WDOG                          ; /* Internal WDOG Control Register, offset: 0x10 */
  struct
  {
	  __IO uint32_t CSC                       ; /* Channel n Status and Control Register, offset: 0x14 + 8*n */
	  __IO uint32_t CV                        ; /* Channel n Value Register, offset: 0x18 +  8*n */
  }Channel[QDT_CHANNEL_COUNT];
  __I  uint32_t REVCNT                        ; /* Revolution Counter Register, offset: 0x34 */
  __I  uint32_t REVCNT_HOLD                   ; /* Revolution Hold Counter Register, offset: 0x38 */
  __IO uint32_t POSCNT                        ; /* Position Counter Register, offset: 0x3C */
  __I  uint32_t POSCNT_HOLD                   ; /* Position Hold Counter Register, offset: 0x40 */
  __I  uint32_t POSDCNT                       ; /* Position Difference Counter Register, offset: 0x44 */
  __I  uint32_t POSDCNT_HOLD                  ; /* Position Difference Hold Counter Register, offset: 0x48 */
  __I  uint32_t LECNT                         ; /* Last PHA/B Edge Time Counter Register, offset: 0x4C */
  __I  uint32_t LECNT_HOLD                    ; /* Last PHA/B Edge Time Hold Counter Register, offset: 0x50 */
  __I  uint32_t POSDTMRCNT                    ; /* Position Difference Time Counter Register, offset: 0x54 */
  __I  uint32_t POSDTMRCNT_HOLD               ; /* Position Difference Time Hold Counter Register, offset: 0x58 */

} QDT_Type, *QDT_MemMapPtr;


/* QDT - Peripheral instance base addresses */
/** Peripheral QDT0 base address */
#define QDT0_BASE                                (0x4043f000u)
/** Peripheral QDT0 base pointer */
#define QDT0                                     ((QDT_Type *)QDT0_BASE)
/** Peripheral QDT1 base address */
#define QDT1_BASE                                (0x40440000u)
/** Peripheral QDT1 base pointer */
#define QDT1                                     ((QDT_Type *)QDT1_BASE)
/** Peripheral QDT2 base address */
#define QDT2_BASE                                (0x40441000u)
/** Peripheral QDT2 base pointer */
#define QDT2                                     ((QDT_Type *)QDT2_BASE)
/** Peripheral QDT3 base address */
#define QDT3_BASE                                (0x40442000u)
/** Peripheral QDT3 base pointer */
#define QDT3                                     ((QDT_Type *)QDT3_BASE)
// need fill by yourself
///** Number of interrupt vector arrays for the QDT module. */
//#define QDT_IRQS_ARR_COUNT                       (1u)
///** Number of interrupt channels for the QDT module. */
//#define QDT_IRQS_CH_COUNT                        (1u)
///** Interrupt vectors for the QDT peripheral type */
//#define QDT_IRQS                                 {QDT0_IRQn, QDT1_IRQn, QDT2_IRQn, QDT3_IRQn}


/* ----------------------------------------------------------------------------
   -- QDT Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup QDT_Register_Masks QDT Register Masks
 * @{
 */

/* SC Bit Fields */
#define QDT_SC_EXTCLK_SEL_MASK         0xC0000000u
#define QDT_SC_EXTCLK_SEL_SHIFT        30u
#define QDT_SC_EXTCLK_SEL_WIDTH        2u
#define QDT_SC_EXTCLK_SEL(x)           (((uint32_t)(((uint32_t)(x))<<QDT_SC_EXTCLK_SEL_SHIFT))&QDT_SC_EXTCLK_SEL_MASK)
#define QDT_SC_WDOGF_MASK              0x200000u
#define QDT_SC_WDOGF_SHIFT             21u
#define QDT_SC_WDOGF_WIDTH             1u
#define QDT_SC_WDOGF(x)                (((uint32_t)(((uint32_t)(x))<<QDT_SC_WDOGF_SHIFT))&QDT_SC_WDOGF_MASK)
#define QDT_SC_CHNF_MASK               0x1E0000u
#define QDT_SC_CHNF_SHIFT              17u
#define QDT_SC_CHNF_WIDTH              4u
#define QDT_SC_CHNF(x)                 (((uint32_t)(((uint32_t)(x))<<QDT_SC_CHNF_SHIFT))&QDT_SC_CHNF_MASK)
#define QDT_SC_TOF_MASK                0x10000u
#define QDT_SC_TOF_SHIFT               16u
#define QDT_SC_TOF_WIDTH               1u
#define QDT_SC_TOF(x)                  (((uint32_t)(((uint32_t)(x))<<QDT_SC_TOF_SHIFT))&QDT_SC_TOF_MASK)
#define QDT_SC_TOIE_MASK               0x4000u
#define QDT_SC_TOIE_SHIFT              14u
#define QDT_SC_TOIE_WIDTH              1u
#define QDT_SC_TOIE(x)                 (((uint32_t)(((uint32_t)(x))<<QDT_SC_TOIE_SHIFT))&QDT_SC_TOIE_MASK)
#define QDT_SC_WPDIS_MASK              0x2000u
#define QDT_SC_WPDIS_SHIFT             13u
#define QDT_SC_WPDIS_WIDTH             1u
#define QDT_SC_WPDIS(x)                (((uint32_t)(((uint32_t)(x))<<QDT_SC_WPDIS_SHIFT))&QDT_SC_WPDIS_MASK)
#define QDT_SC_WPEN_MASK               0x1000u
#define QDT_SC_WPEN_SHIFT              12u
#define QDT_SC_WPEN_WIDTH              1u
#define QDT_SC_WPEN(x)                 (((uint32_t)(((uint32_t)(x))<<QDT_SC_WPEN_SHIFT))&QDT_SC_WPEN_MASK)
#define QDT_SC_DBG_MASK                0x400u
#define QDT_SC_DBG_SHIFT               10u
#define QDT_SC_DBG_WIDTH               1u
#define QDT_SC_DBG(x)                  (((uint32_t)(((uint32_t)(x))<<QDT_SC_DBG_SHIFT))&QDT_SC_DBG_MASK)
#define QDT_SC_MTRIGCTRL_MASK          0x200u
#define QDT_SC_MTRIGCTRL_SHIFT         9u
#define QDT_SC_MTRIGCTRL_WIDTH         1u
#define QDT_SC_MTRIGCTRL(x)            (((uint32_t)(((uint32_t)(x))<<QDT_SC_MTRIGCTRL_SHIFT))&QDT_SC_MTRIGCTRL_MASK)
#define QDT_SC_QUADIR_MASK             0x100u
#define QDT_SC_QUADIR_SHIFT            8u
#define QDT_SC_QUADIR_WIDTH            1u
#define QDT_SC_QUADIR(x)               (((uint32_t)(((uint32_t)(x))<<QDT_SC_QUADIR_SHIFT))&QDT_SC_QUADIR_MASK)
#define QDT_SC_TOFDIR_MASK             0x80u
#define QDT_SC_TOFDIR_SHIFT            7u
#define QDT_SC_TOFDIR_WIDTH            1u
#define QDT_SC_TOFDIR(x)               (((uint32_t)(((uint32_t)(x))<<QDT_SC_TOFDIR_SHIFT))&QDT_SC_TOFDIR_MASK)
#define QDT_SC_QUADMODE_MASK           0x40u
#define QDT_SC_QUADMODE_SHIFT          6u
#define QDT_SC_QUADMODE_WIDTH          1u
#define QDT_SC_QUADMODE(x)             (((uint32_t)(((uint32_t)(x))<<QDT_SC_QUADMODE_SHIFT))&QDT_SC_QUADMODE_MASK)
#define QDT_SC_QUADEN_MASK             0x20u
#define QDT_SC_QUADEN_SHIFT            5u
#define QDT_SC_QUADEN_WIDTH            1u
#define QDT_SC_QUADEN(x)               (((uint32_t)(((uint32_t)(x))<<QDT_SC_QUADEN_SHIFT))&QDT_SC_QUADEN_MASK)
#define QDT_SC_CLKS_MASK               0x18u
#define QDT_SC_CLKS_SHIFT              3u
#define QDT_SC_CLKS_WIDTH              2u
#define QDT_SC_CLKS(x)                 (((uint32_t)(((uint32_t)(x))<<QDT_SC_CLKS_SHIFT))&QDT_SC_CLKS_MASK)
#define QDT_SC_PS_MASK                 0x7u
#define QDT_SC_PS_SHIFT                0u
#define QDT_SC_PS_WIDTH                3u
#define QDT_SC_PS(x)                   (((uint32_t)(((uint32_t)(x))<<QDT_SC_PS_SHIFT))&QDT_SC_PS_MASK)
/* SC Reg Mask */
#define QDT_SC_MASK                    0xC03F77FFu

/* SYNC Bit Fields */
#define QDT_SYNC_SYNCMODE_MASK         0x80u
#define QDT_SYNC_SYNCMODE_SHIFT        7u
#define QDT_SYNC_SYNCMODE_WIDTH        1u
#define QDT_SYNC_SYNCMODE(x)           (((uint32_t)(((uint32_t)(x))<<QDT_SYNC_SYNCMODE_SHIFT))&QDT_SYNC_SYNCMODE_MASK)
#define QDT_SYNC_TRIG_UPHOLD_MASK      0x40u
#define QDT_SYNC_TRIG_UPHOLD_SHIFT     6u
#define QDT_SYNC_TRIG_UPHOLD_WIDTH     1u
#define QDT_SYNC_TRIG_UPHOLD(x)        (((uint32_t)(((uint32_t)(x))<<QDT_SYNC_TRIG_UPHOLD_SHIFT))&QDT_SYNC_TRIG_UPHOLD_MASK)
#define QDT_SYNC_TRIG_RSTCNT_MASK      0x20u
#define QDT_SYNC_TRIG_RSTCNT_SHIFT     5u
#define QDT_SYNC_TRIG_RSTCNT_WIDTH     1u
#define QDT_SYNC_TRIG_RSTCNT(x)        (((uint32_t)(((uint32_t)(x))<<QDT_SYNC_TRIG_RSTCNT_SHIFT))&QDT_SYNC_TRIG_RSTCNT_MASK)
#define QDT_SYNC_TRIG0_MASK            0x10u
#define QDT_SYNC_TRIG0_SHIFT           4u
#define QDT_SYNC_TRIG0_WIDTH           1u
#define QDT_SYNC_TRIG0(x)              (((uint32_t)(((uint32_t)(x))<<QDT_SYNC_TRIG0_SHIFT))&QDT_SYNC_TRIG0_MASK)
#define QDT_SYNC_SW_RSTCNT_MASK        0x8u
#define QDT_SYNC_SW_RSTCNT_SHIFT       3u
#define QDT_SYNC_SW_RSTCNT_WIDTH       1u
#define QDT_SYNC_SW_RSTCNT(x)          (((uint32_t)(((uint32_t)(x))<<QDT_SYNC_SW_RSTCNT_SHIFT))&QDT_SYNC_SW_RSTCNT_MASK)
#define QDT_SYNC_SWSYNC_MASK           0x4u
#define QDT_SYNC_SWSYNC_SHIFT          2u
#define QDT_SYNC_SWSYNC_WIDTH          1u
#define QDT_SYNC_SWSYNC(x)             (((uint32_t)(((uint32_t)(x))<<QDT_SYNC_SWSYNC_SHIFT))&QDT_SYNC_SWSYNC_MASK)
/* SYNC Reg Mask */
#define QDT_SYNC_MASK                  0x000000FCu

/* POL Bit Fields */
#define QDT_POL_PHZPOL_MASK            0x4u
#define QDT_POL_PHZPOL_SHIFT           2u
#define QDT_POL_PHZPOL_WIDTH           1u
#define QDT_POL_PHZPOL(x)              (((uint32_t)(((uint32_t)(x))<<QDT_POL_PHZPOL_SHIFT))&QDT_POL_PHZPOL_MASK)
#define QDT_POL_PHBPOL_MASK            0x2u
#define QDT_POL_PHBPOL_SHIFT           1u
#define QDT_POL_PHBPOL_WIDTH           1u
#define QDT_POL_PHBPOL(x)              (((uint32_t)(((uint32_t)(x))<<QDT_POL_PHBPOL_SHIFT))&QDT_POL_PHBPOL_MASK)
#define QDT_POL_PHAPOL_MASK            0x1u
#define QDT_POL_PHAPOL_SHIFT           0u
#define QDT_POL_PHAPOL_WIDTH           1u
#define QDT_POL_PHAPOL(x)              (((uint32_t)(((uint32_t)(x))<<QDT_POL_PHAPOL_SHIFT))&QDT_POL_PHAPOL_MASK)
/* POL Reg Mask */
#define QDT_POL_MASK                   0x00000007u

/* FILTER Bit Fields */
#define QDT_FILTER_HOMEGFVAL_MASK      0xF0000000u
#define QDT_FILTER_HOMEGFVAL_SHIFT     28u
#define QDT_FILTER_HOMEGFVAL_WIDTH     4u
#define QDT_FILTER_HOMEGFVAL(x)        (((uint32_t)(((uint32_t)(x))<<QDT_FILTER_HOMEGFVAL_SHIFT))&QDT_FILTER_HOMEGFVAL_MASK)
#define QDT_FILTER_PHZGFVAL_MASK       0xF000000u
#define QDT_FILTER_PHZGFVAL_SHIFT      24u
#define QDT_FILTER_PHZGFVAL_WIDTH      4u
#define QDT_FILTER_PHZGFVAL(x)         (((uint32_t)(((uint32_t)(x))<<QDT_FILTER_PHZGFVAL_SHIFT))&QDT_FILTER_PHZGFVAL_MASK)
#define QDT_FILTER_PHBGFVAL_MASK       0xF00000u
#define QDT_FILTER_PHBGFVAL_SHIFT      20u
#define QDT_FILTER_PHBGFVAL_WIDTH      4u
#define QDT_FILTER_PHBGFVAL(x)         (((uint32_t)(((uint32_t)(x))<<QDT_FILTER_PHBGFVAL_SHIFT))&QDT_FILTER_PHBGFVAL_MASK)
#define QDT_FILTER_PHAGFVAL_MASK       0xF0000u
#define QDT_FILTER_PHAGFVAL_SHIFT      16u
#define QDT_FILTER_PHAGFVAL_WIDTH      4u
#define QDT_FILTER_PHAGFVAL(x)         (((uint32_t)(((uint32_t)(x))<<QDT_FILTER_PHAGFVAL_SHIFT))&QDT_FILTER_PHAGFVAL_MASK)
#define QDT_FILTER_FLTPS_MASK          0xFu
#define QDT_FILTER_FLTPS_SHIFT         0u
#define QDT_FILTER_FLTPS_WIDTH         4u
#define QDT_FILTER_FLTPS(x)            (((uint32_t)(((uint32_t)(x))<<QDT_FILTER_FLTPS_SHIFT))&QDT_FILTER_FLTPS_MASK)
/* FILTER Reg Mask */
#define QDT_FILTER_MASK                0xFFFF000Fu

/* WDOG Bit Fields */
#define QDT_WDOG_WDOGVAL_MASK          0xFFFF0000u
#define QDT_WDOG_WDOGVAL_SHIFT         16u
#define QDT_WDOG_WDOGVAL_WIDTH         16u
#define QDT_WDOG_WDOGVAL(x)            (((uint32_t)(((uint32_t)(x))<<QDT_WDOG_WDOGVAL_SHIFT))&QDT_WDOG_WDOGVAL_MASK)
#define QDT_WDOG_WDOGF_MASK            0x4u
#define QDT_WDOG_WDOGF_SHIFT           2u
#define QDT_WDOG_WDOGF_WIDTH           1u
#define QDT_WDOG_WDOGF(x)              (((uint32_t)(((uint32_t)(x))<<QDT_WDOG_WDOGF_SHIFT))&QDT_WDOG_WDOGF_MASK)
#define QDT_WDOG_WDOGIE_MASK           0x2u
#define QDT_WDOG_WDOGIE_SHIFT          1u
#define QDT_WDOG_WDOGIE_WIDTH          1u
#define QDT_WDOG_WDOGIE(x)             (((uint32_t)(((uint32_t)(x))<<QDT_WDOG_WDOGIE_SHIFT))&QDT_WDOG_WDOGIE_MASK)
#define QDT_WDOG_WDOGEN_MASK           0x1u
#define QDT_WDOG_WDOGEN_SHIFT          0u
#define QDT_WDOG_WDOGEN_WIDTH          1u
#define QDT_WDOG_WDOGEN(x)             (((uint32_t)(((uint32_t)(x))<<QDT_WDOG_WDOGEN_SHIFT))&QDT_WDOG_WDOGEN_MASK)
/* WDOG Reg Mask */
#define QDT_WDOG_MASK                  0xFFFF0007u

/* CSC Bit Fields */
#define QDT_CSC_ICEXP_NUM_ICM_ECNT_MASK 0xFF000000u
#define QDT_CSC_ICEXP_NUM_ICM_ECNT_SHIFT 24u
#define QDT_CSC_ICEXP_NUM_ICM_ECNT_WIDTH 8u
#define QDT_CSC_ICEXP_NUM_ICM_ECNT(x)  (((uint32_t)(((uint32_t)(x))<<QDT_CSC_ICEXP_NUM_ICM_ECNT_SHIFT))&QDT_CSC_ICEXP_NUM_ICM_ECNT_MASK)
#define QDT_CSC_ICM_SIG_REG_MASK       0x8000u
#define QDT_CSC_ICM_SIG_REG_SHIFT      15u
#define QDT_CSC_ICM_SIG_REG_WIDTH      1u
#define QDT_CSC_ICM_SIG_REG(x)         (((uint32_t)(((uint32_t)(x))<<QDT_CSC_ICM_SIG_REG_SHIFT))&QDT_CSC_ICM_SIG_REG_MASK)
#define QDT_CSC_ICDPM_START_MASK       0x4000u
#define QDT_CSC_ICDPM_START_SHIFT      14u
#define QDT_CSC_ICDPM_START_WIDTH      1u
#define QDT_CSC_ICDPM_START(x)         (((uint32_t)(((uint32_t)(x))<<QDT_CSC_ICDPM_START_SHIFT))&QDT_CSC_ICDPM_START_MASK)
#define QDT_CSC_ICM_CONT_MASK          0x2000u
#define QDT_CSC_ICM_CONT_SHIFT         13u
#define QDT_CSC_ICM_CONT_WIDTH         1u
#define QDT_CSC_ICM_CONT(x)            (((uint32_t)(((uint32_t)(x))<<QDT_CSC_ICM_CONT_SHIFT))&QDT_CSC_ICM_CONT_MASK)
#define QDT_CSC_ICM_MODE_MASK          0x1C00u
#define QDT_CSC_ICM_MODE_SHIFT         10u
#define QDT_CSC_ICM_MODE_WIDTH         3u
#define QDT_CSC_ICM_MODE(x)            (((uint32_t)(((uint32_t)(x))<<QDT_CSC_ICM_MODE_SHIFT))&QDT_CSC_ICM_MODE_MASK)
#define QDT_CSC_REVMODE_MASK           0x100u
#define QDT_CSC_REVMODE_SHIFT          8u
#define QDT_CSC_REVMODE_WIDTH          1u
#define QDT_CSC_REVMODE(x)             (((uint32_t)(((uint32_t)(x))<<QDT_CSC_REVMODE_SHIFT))&QDT_CSC_REVMODE_MASK)
#define QDT_CSC_CHTRIG_MASK            0x80u
#define QDT_CSC_CHTRIG_SHIFT           7u
#define QDT_CSC_CHTRIG_WIDTH           1u
#define QDT_CSC_CHTRIG(x)              (((uint32_t)(((uint32_t)(x))<<QDT_CSC_CHTRIG_SHIFT))&QDT_CSC_CHTRIG_MASK)
#define QDT_CSC_CHIS_MASK              0x40u
#define QDT_CSC_CHIS_SHIFT             6u
#define QDT_CSC_CHIS_WIDTH             1u
#define QDT_CSC_CHIS(x)                (((uint32_t)(((uint32_t)(x))<<QDT_CSC_CHIS_SHIFT))&QDT_CSC_CHIS_MASK)
#define QDT_CSC_FLTCHIS_MASK           0x20u
#define QDT_CSC_FLTCHIS_SHIFT          5u
#define QDT_CSC_FLTCHIS_WIDTH          1u
#define QDT_CSC_FLTCHIS(x)             (((uint32_t)(((uint32_t)(x))<<QDT_CSC_FLTCHIS_SHIFT))&QDT_CSC_FLTCHIS_MASK)
#define QDT_CSC_CHF_MASK               0x10u
#define QDT_CSC_CHF_SHIFT              4u
#define QDT_CSC_CHF_WIDTH              1u
#define QDT_CSC_CHF(x)                 (((uint32_t)(((uint32_t)(x))<<QDT_CSC_CHF_SHIFT))&QDT_CSC_CHF_MASK)
#define QDT_CSC_CHIE_MASK              0x8u
#define QDT_CSC_CHIE_SHIFT             3u
#define QDT_CSC_CHIE_WIDTH             1u
#define QDT_CSC_CHIE(x)                (((uint32_t)(((uint32_t)(x))<<QDT_CSC_CHIE_SHIFT))&QDT_CSC_CHIE_MASK)
#define QDT_CSC_ELSB_MASK              0x4u
#define QDT_CSC_ELSB_SHIFT             2u
#define QDT_CSC_ELSB_WIDTH             1u
#define QDT_CSC_ELSB(x)                (((uint32_t)(((uint32_t)(x))<<QDT_CSC_ELSB_SHIFT))&QDT_CSC_ELSB_MASK)
#define QDT_CSC_ELSA_MASK              0x2u
#define QDT_CSC_ELSA_SHIFT             1u
#define QDT_CSC_ELSA_WIDTH             1u
#define QDT_CSC_ELSA(x)                (((uint32_t)(((uint32_t)(x))<<QDT_CSC_ELSA_SHIFT))&QDT_CSC_ELSA_MASK)
#define QDT_CSC_ICRST_MASK             0x1u
#define QDT_CSC_ICRST_SHIFT            0u
#define QDT_CSC_ICRST_WIDTH            1u
#define QDT_CSC_ICRST(x)               (((uint32_t)(((uint32_t)(x))<<QDT_CSC_ICRST_SHIFT))&QDT_CSC_ICRST_MASK)
/* CSC0 Reg Mask */
#define QDT_CSC_MASK                   0xFF00FDFFu

/* CV Bit Fields */
#define QDT_CV_CV_MASK                 0xFFFFFFFFu
#define QDT_CV_CV_SHIFT                0u
#define QDT_CV_CV_WIDTH                32u
#define QDT_CV_CV(x)                   (((uint32_t)(((uint32_t)(x))<<QDT_CV_CV_SHIFT))&QDT_CV_CV_MASK)
/* CV0 Reg Mask */
#define QDT_CV_MASK                    0xFFFFFFFFu

/* REVCNT Bit Fields */
#define QDT_REVCNT_REVCNT_MASK         0xFFFFu
#define QDT_REVCNT_REVCNT_SHIFT        0u
#define QDT_REVCNT_REVCNT_WIDTH        16u
#define QDT_REVCNT_REVCNT(x)           (((uint32_t)(((uint32_t)(x))<<QDT_REVCNT_REVCNT_SHIFT))&QDT_REVCNT_REVCNT_MASK)
/* REVCNT Reg Mask */
#define QDT_REVCNT_MASK                0x0000FFFFu

/* REVCNT_HOLD Bit Fields */
#define QDT_REVCNT_HOLD_REVCNT_HOLD_MASK 0xFFFFu
#define QDT_REVCNT_HOLD_REVCNT_HOLD_SHIFT 0u
#define QDT_REVCNT_HOLD_REVCNT_HOLD_WIDTH 16u
#define QDT_REVCNT_HOLD_REVCNT_HOLD(x) (((uint32_t)(((uint32_t)(x))<<QDT_REVCNT_HOLD_REVCNT_HOLD_SHIFT))&QDT_REVCNT_HOLD_REVCNT_HOLD_MASK)
/* REVCNT_HOLD Reg Mask */
#define QDT_REVCNT_HOLD_MASK           0x0000FFFFu

/* POSCNT Bit Fields */
#define QDT_POSCNT_POSCNT_MASK         0xFFFFFFFFu
#define QDT_POSCNT_POSCNT_SHIFT        0u
#define QDT_POSCNT_POSCNT_WIDTH        32u
#define QDT_POSCNT_POSCNT(x)           (((uint32_t)(((uint32_t)(x))<<QDT_POSCNT_POSCNT_SHIFT))&QDT_POSCNT_POSCNT_MASK)
/* POSCNT Reg Mask */
#define QDT_POSCNT_MASK                0xFFFFFFFFu

/* POSCNT_HOLD Bit Fields */
#define QDT_POSCNT_HOLD_POSCNT_HOLD_MASK 0xFFFFFFFFu
#define QDT_POSCNT_HOLD_POSCNT_HOLD_SHIFT 0u
#define QDT_POSCNT_HOLD_POSCNT_HOLD_WIDTH 32u
#define QDT_POSCNT_HOLD_POSCNT_HOLD(x) (((uint32_t)(((uint32_t)(x))<<QDT_POSCNT_HOLD_POSCNT_HOLD_SHIFT))&QDT_POSCNT_HOLD_POSCNT_HOLD_MASK)
/* POSCNT_HOLD Reg Mask */
#define QDT_POSCNT_HOLD_MASK           0xFFFFFFFFu

/* POSDCNT Bit Fields */
#define QDT_POSDCNT_POSDCNT_MASK       0xFFFFu
#define QDT_POSDCNT_POSDCNT_SHIFT      0u
#define QDT_POSDCNT_POSDCNT_WIDTH      16u
#define QDT_POSDCNT_POSDCNT(x)         (((uint32_t)(((uint32_t)(x))<<QDT_POSDCNT_POSDCNT_SHIFT))&QDT_POSDCNT_POSDCNT_MASK)
/* POSDCNT Reg Mask */
#define QDT_POSDCNT_MASK               0x0000FFFFu

/* POSDCNT_HOLD Bit Fields */
#define QDT_POSDCNT_HOLD_POSDCNT_HOLD_MASK 0xFFFFu
#define QDT_POSDCNT_HOLD_POSDCNT_HOLD_SHIFT 0u
#define QDT_POSDCNT_HOLD_POSDCNT_HOLD_WIDTH 16u
#define QDT_POSDCNT_HOLD_POSDCNT_HOLD(x) (((uint32_t)(((uint32_t)(x))<<QDT_POSDCNT_HOLD_POSDCNT_HOLD_SHIFT))&QDT_POSDCNT_HOLD_POSDCNT_HOLD_MASK)
/* POSDCNT_HOLD Reg Mask */
#define QDT_POSDCNT_HOLD_MASK          0x0000FFFFu

/* LECNT Bit Fields */
#define QDT_LECNT_LECNT_MASK           0xFFFFu
#define QDT_LECNT_LECNT_SHIFT          0u
#define QDT_LECNT_LECNT_WIDTH          16u
#define QDT_LECNT_LECNT(x)             (((uint32_t)(((uint32_t)(x))<<QDT_LECNT_LECNT_SHIFT))&QDT_LECNT_LECNT_MASK)
/* LECNT Reg Mask */
#define QDT_LECNT_MASK                 0x0000FFFFu

/* LECNT_HOLD Bit Fields */
#define QDT_LECNT_HOLD_LECNT_HOLD_MASK 0xFFFFu
#define QDT_LECNT_HOLD_LECNT_HOLD_SHIFT 0u
#define QDT_LECNT_HOLD_LECNT_HOLD_WIDTH 16u
#define QDT_LECNT_HOLD_LECNT_HOLD(x)   (((uint32_t)(((uint32_t)(x))<<QDT_LECNT_HOLD_LECNT_HOLD_SHIFT))&QDT_LECNT_HOLD_LECNT_HOLD_MASK)
/* LECNT_HOLD Reg Mask */
#define QDT_LECNT_HOLD_MASK            0x0000FFFFu

/* POSDTMRCNT Bit Fields */
#define QDT_POSDTMRCNT_POSDTMRCNT_MASK 0xFFFFu
#define QDT_POSDTMRCNT_POSDTMRCNT_SHIFT 0u
#define QDT_POSDTMRCNT_POSDTMRCNT_WIDTH 16u
#define QDT_POSDTMRCNT_POSDTMRCNT(x)   (((uint32_t)(((uint32_t)(x))<<QDT_POSDTMRCNT_POSDTMRCNT_SHIFT))&QDT_POSDTMRCNT_POSDTMRCNT_MASK)
/* POSDTMRCNT Reg Mask */
#define QDT_POSDTMRCNT_MASK            0x0000FFFFu

/* POSDTMRCNT_HOLD Bit Fields */
#define QDT_POSDTMRCNT_HOLD_POSDTMRCNT_HOLD_MASK 0xFFFFu
#define QDT_POSDTMRCNT_HOLD_POSDTMRCNT_HOLD_SHIFT 0u
#define QDT_POSDTMRCNT_HOLD_POSDTMRCNT_HOLD_WIDTH 16u
#define QDT_POSDTMRCNT_HOLD_POSDTMRCNT_HOLD(x) (((uint32_t)(((uint32_t)(x))<<QDT_POSDTMRCNT_HOLD_POSDTMRCNT_HOLD_SHIFT))&QDT_POSDTMRCNT_HOLD_POSDTMRCNT_HOLD_MASK)
/* POSDTMRCNT_HOLD Reg Mask */
#define QDT_POSDTMRCNT_HOLD_MASK       0x0000FFFFu


/*!
 * @}
 */ /* end of group QDT_Register_Masks */

/*!
 * @}
 */ /* end of group QDT_Peripheral_Access_Layer */

#endif
