#ifndef _MODULE_EFTU_TIM_gmbhdijq26_REGS_H_EFTU_TIM_H_
#define _MODULE_EFTU_TIM_gmbhdijq26_REGS_H_EFTU_TIM_H_

/* ----------------------------------------------------------------------------
   -- EFTU_TIM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup EFTU_TIM_Peripheral_Access_Layer EFTU_TIM Peripheral Access Layer
 * @{
 */

/** EFTU_TIM - Size of Registers Arrays */

/** EFTU_TIM - Register Layout Typedef */

typedef struct {

	struct{
	  __IO uint32_t CH_GPR0                      ; /* TIM[i] channel [x] general purpose 0 register, offset: 0x0 */
	  __IO uint32_t CH_GPR1                      ; /* TIM[i] channel [x] general purpose 1 register, offset: 0x4 */
	  __I  uint32_t CH_CNT                       ; /* TIM[i] channel [x] SMU counter register, offset: 0x8 */
	  __I  uint32_t CH_ECNT                      ; /* TIM[i] channel [x] SMU edge counter register, offset: 0xc */
	  __IO uint32_t CH_CNTS                      ; /* TIM[i] channel [x] SMU shadow counter register, offset: 0x10 */
	  __IO uint32_t CH_EGC                       ; /* TIM[i] channel [x] TDU counter register, offset: 0x14 */
	  __IO uint32_t CH_EGV                       ; /* TIM[i] channel [x] TDU control register, offset: 0x18 */
	  __IO uint32_t CH_FLT_RE                    ; /* TIM[i] channel [x] filter parameter 0 register, offset: 0x1c */
	  __IO uint32_t CH_FLT_FE                    ; /* TIM[i] channel [x] filter parameter 1 register, offset: 0x20 */
	  __IO uint32_t CH_CTRL                      ; /* TIM[i] channel [x] control register, offset: 0x24 */
	  __IO uint32_t CH_ECTRL                     ; /* TIM[i] channel [x] extended control register, offset: 0x28 */
	  __IO uint32_t CH_IRQ_ST                    ; /* TIM[i] channel [x] interrupt notification register, offset: 0x2c */
	  __IO uint32_t CH_IRQ_EN                    ; /* TIM[i] channel [x] interrupt enable register, offset: 0x30 */
		   uint8_t  RESERVED_0[76];
 }CONTROL[8];
  __I  uint32_t INP_VAL                       ; /* Input Value Observation Register, offset: 0x400 */
  __IO uint32_t IN_SRC                        ; /* AUX IN Source Selection Register, offset: 0x404 */
  __IO uint32_t RST                           ; /* Global Software Reset Register, offset: 0x408 */
  __IO uint32_t TIM_SPEC_LOCK                 ; /* Special Lock Register, offset: 0x40C */

} EFTU_TIM_Type, *EFTU_TIM_MemMapPtr;


/* EFTU_TIM - Peripheral instance base addresses */
/** Peripheral EFTU_TIM base address */
#define EFTU_TIM_BASE                            (0x800u)
/** Peripheral EFTU_TIM base pointer */
#define EFTU_TIM                                 ((EFTU_TIM_Type *)EFTU_TIM_BASE)
// need fill by yourself
///** Number of interrupt vector arrays for the EFTU_TIM module. */
//#define EFTU_TIM_IRQS_ARR_COUNT                       (1u)
///** Number of interrupt channels for the EFTU_TIM module. */
//#define EFTU_TIM_IRQS_CH_COUNT                        (1u)
///** Interrupt vectors for the EFTU_TIM peripheral type */
//#define EFTU_TIM_IRQS                            {EFTU_TIM_IRQn}


/* ----------------------------------------------------------------------------
   -- EFTU_TIM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup EFTU_TIM_Register_Masks EFTU_TIM Register Masks
 * @{
 */

/* CHn_GPR0 Bit Fields */
#define EFTU_TIM_CHn_GPR0_GPR0_MASK    0xFFFFFFu
#define EFTU_TIM_CHn_GPR0_GPR0_SHIFT   0u
#define EFTU_TIM_CHn_GPR0_GPR0_WIDTH   24u
#define EFTU_TIM_CHn_GPR0_GPR0(x)      (((uint32_t)(((uint32_t)(x))<<EFTU_TIM_CHn_GPR0_GPR0_SHIFT))&EFTU_TIM_CHn_GPR0_GPR0_MASK)
#define EFTU_TIM_CHn_GPR0_ECNT_MASK    0xFF000000u
#define EFTU_TIM_CHn_GPR0_ECNT_SHIFT   24u
#define EFTU_TIM_CHn_GPR0_ECNT_WIDTH   8u
#define EFTU_TIM_CHn_GPR0_ECNT(x)      (((uint32_t)(((uint32_t)(x))<<EFTU_TIM_CHn_GPR0_ECNT_SHIFT))&EFTU_TIM_CHn_GPR0_ECNT_MASK)
/* CH0_GPR0 Reg Mask */
#define EFTU_TIM_CHn_GPR0_MASK         0xFFFFFFFFu

/* CHn_GPR1 Bit Fields */
#define EFTU_TIM_CHn_GPR1_GPR1_MASK    0xFFFFFFu
#define EFTU_TIM_CHn_GPR1_GPR1_SHIFT   0u
#define EFTU_TIM_CHn_GPR1_GPR1_WIDTH   24u
#define EFTU_TIM_CHn_GPR1_GPR1(x)      (((uint32_t)(((uint32_t)(x))<<EFTU_TIM_CHn_GPR1_GPR1_SHIFT))&EFTU_TIM_CHn_GPR1_GPR1_MASK)
#define EFTU_TIM_CHn_GPR1_ECNT_MASK    0xFF000000u
#define EFTU_TIM_CHn_GPR1_ECNT_SHIFT   24u
#define EFTU_TIM_CHn_GPR1_ECNT_WIDTH   8u
#define EFTU_TIM_CHn_GPR1_ECNT(x)      (((uint32_t)(((uint32_t)(x))<<EFTU_TIM_CHn_GPR1_ECNT_SHIFT))&EFTU_TIM_CHn_GPR1_ECNT_MASK)
/* CH0_GPR1 Reg Mask */
#define EFTU_TIM_CHn_GPR1_MASK         0xFFFFFFFFu

/* CHn_CNT Bit Fields */
#define EFTU_TIM_CHn_CNT_CNT_MASK      0xFFFFFFu
#define EFTU_TIM_CHn_CNT_CNT_SHIFT     0u
#define EFTU_TIM_CHn_CNT_CNT_WIDTH     24u
#define EFTU_TIM_CHn_CNT_CNT(x)        (((uint32_t)(((uint32_t)(x))<<EFTU_TIM_CHn_CNT_CNT_SHIFT))&EFTU_TIM_CHn_CNT_CNT_MASK)
/* CH0_CNT Reg Mask */
#define EFTU_TIM_CHn_CNT_MASK          0x00FFFFFFu

/* CHn_ECNT Bit Fields */
#define EFTU_TIM_CHn_ECNT_ECNT_MASK    0xFFFFu
#define EFTU_TIM_CHn_ECNT_ECNT_SHIFT   0u
#define EFTU_TIM_CHn_ECNT_ECNT_WIDTH   16u
#define EFTU_TIM_CHn_ECNT_ECNT(x)      (((uint32_t)(((uint32_t)(x))<<EFTU_TIM_CHn_ECNT_ECNT_SHIFT))&EFTU_TIM_CHn_ECNT_ECNT_MASK)
/* CH0_ECNT Reg Mask */
#define EFTU_TIM_CHn_ECNT_MASK         0x0000FFFFu

/* CHn_CNTS Bit Fields */
#define EFTU_TIM_CHn_CNTS_CNTS_MASK    0xFFFFFFu
#define EFTU_TIM_CHn_CNTS_CNTS_SHIFT   0u
#define EFTU_TIM_CHn_CNTS_CNTS_WIDTH   24u
#define EFTU_TIM_CHn_CNTS_CNTS(x)      (((uint32_t)(((uint32_t)(x))<<EFTU_TIM_CHn_CNTS_CNTS_SHIFT))&EFTU_TIM_CHn_CNTS_CNTS_MASK)
#define EFTU_TIM_CHn_CNTS_ECNT_MASK    0xFF000000u
#define EFTU_TIM_CHn_CNTS_ECNT_SHIFT   24u
#define EFTU_TIM_CHn_CNTS_ECNT_WIDTH   8u
#define EFTU_TIM_CHn_CNTS_ECNT(x)      (((uint32_t)(((uint32_t)(x))<<EFTU_TIM_CHn_CNTS_ECNT_SHIFT))&EFTU_TIM_CHn_CNTS_ECNT_MASK)
/* CH0_CNTS Reg Mask */
#define EFTU_TIM_CHn_CNTS_MASK         0xFFFFFFFFu

/* CHn_EGC Bit Fields */
#define EFTU_TIM_CHn_EGC_TO_CNT_MASK   0xFFu
#define EFTU_TIM_CHn_EGC_TO_CNT_SHIFT  0u
#define EFTU_TIM_CHn_EGC_TO_CNT_WIDTH  8u
#define EFTU_TIM_CHn_EGC_TO_CNT(x)     (((uint32_t)(((uint32_t)(x))<<EFTU_TIM_CHn_EGC_TO_CNT_SHIFT))&EFTU_TIM_CHn_EGC_TO_CNT_MASK)
#define EFTU_TIM_CHn_EGC_TO_CNT1_MASK  0xFF00u
#define EFTU_TIM_CHn_EGC_TO_CNT1_SHIFT 8u
#define EFTU_TIM_CHn_EGC_TO_CNT1_WIDTH 8u
#define EFTU_TIM_CHn_EGC_TO_CNT1(x)    (((uint32_t)(((uint32_t)(x))<<EFTU_TIM_CHn_EGC_TO_CNT1_SHIFT))&EFTU_TIM_CHn_EGC_TO_CNT1_MASK)
#define EFTU_TIM_CHn_EGC_TO_CNT2_MASK  0xFF0000u
#define EFTU_TIM_CHn_EGC_TO_CNT2_SHIFT 16u
#define EFTU_TIM_CHn_EGC_TO_CNT2_WIDTH 8u
#define EFTU_TIM_CHn_EGC_TO_CNT2(x)    (((uint32_t)(((uint32_t)(x))<<EFTU_TIM_CHn_EGC_TO_CNT2_SHIFT))&EFTU_TIM_CHn_EGC_TO_CNT2_MASK)
/* CH0_EGC Reg Mask */
#define EFTU_TIM_CHn_EGC_MASK          0x00FFFFFFu

/* CHn_EGV Bit Fields */
#define EFTU_TIM_CHn_EGV_TOV_MASK      0xFFu
#define EFTU_TIM_CHn_EGV_TOV_SHIFT     0u
#define EFTU_TIM_CHn_EGV_TOV_WIDTH     8u
#define EFTU_TIM_CHn_EGV_TOV(x)        (((uint32_t)(((uint32_t)(x))<<EFTU_TIM_CHn_EGV_TOV_SHIFT))&EFTU_TIM_CHn_EGV_TOV_MASK)
#define EFTU_TIM_CHn_EGV_TOV1_MASK     0xFF00u
#define EFTU_TIM_CHn_EGV_TOV1_SHIFT    8u
#define EFTU_TIM_CHn_EGV_TOV1_WIDTH    8u
#define EFTU_TIM_CHn_EGV_TOV1(x)       (((uint32_t)(((uint32_t)(x))<<EFTU_TIM_CHn_EGV_TOV1_SHIFT))&EFTU_TIM_CHn_EGV_TOV1_MASK)
#define EFTU_TIM_CHn_EGV_TOV2_MASK     0xFF0000u
#define EFTU_TIM_CHn_EGV_TOV2_SHIFT    16u
#define EFTU_TIM_CHn_EGV_TOV2_WIDTH    8u
#define EFTU_TIM_CHn_EGV_TOV2(x)       (((uint32_t)(((uint32_t)(x))<<EFTU_TIM_CHn_EGV_TOV2_SHIFT))&EFTU_TIM_CHn_EGV_TOV2_MASK)
#define EFTU_TIM_CHn_EGV_SLICING_MASK  0x3000000u
#define EFTU_TIM_CHn_EGV_SLICING_SHIFT 24u
#define EFTU_TIM_CHn_EGV_SLICING_WIDTH 2u
#define EFTU_TIM_CHn_EGV_SLICING(x)    (((uint32_t)(((uint32_t)(x))<<EFTU_TIM_CHn_EGV_SLICING_SHIFT))&EFTU_TIM_CHn_EGV_SLICING_MASK)
#define EFTU_TIM_CHn_EGV_TCS_USE_SAMPLE_EVT_MASK 0x4000000u
#define EFTU_TIM_CHn_EGV_TCS_USE_SAMPLE_EVT_SHIFT 26u
#define EFTU_TIM_CHn_EGV_TCS_USE_SAMPLE_EVT_WIDTH 1u
#define EFTU_TIM_CHn_EGV_TCS_USE_SAMPLE_EVT(x) (((uint32_t)(((uint32_t)(x))<<EFTU_TIM_CHn_EGV_TCS_USE_SAMPLE_EVT_SHIFT))&EFTU_TIM_CHn_EGV_TCS_USE_SAMPLE_EVT_MASK)
#define EFTU_TIM_CHn_EGV_EG_SAME_CNT_CLK_MASK 0x8000000u
#define EFTU_TIM_CHn_EGV_EG_SAME_CNT_CLK_SHIFT 27u
#define EFTU_TIM_CHn_EGV_EG_SAME_CNT_CLK_WIDTH 1u
#define EFTU_TIM_CHn_EGV_EG_SAME_CNT_CLK(x) (((uint32_t)(((uint32_t)(x))<<EFTU_TIM_CHn_EGV_EG_SAME_CNT_CLK_SHIFT))&EFTU_TIM_CHn_EGV_EG_SAME_CNT_CLK_MASK)
#define EFTU_TIM_CHn_EGV_TCS_MASK      0x70000000u
#define EFTU_TIM_CHn_EGV_TCS_SHIFT     28u
#define EFTU_TIM_CHn_EGV_TCS_WIDTH     3u
#define EFTU_TIM_CHn_EGV_TCS(x)        (((uint32_t)(((uint32_t)(x))<<EFTU_TIM_CHn_EGV_TCS_SHIFT))&EFTU_TIM_CHn_EGV_TCS_MASK)
/* CH0_EGV Reg Mask */
#define EFTU_TIM_CHn_EGV_MASK          0x7FFFFFFFu

/* CHn_FLT_RE Bit Fields */
#define EFTU_TIM_CHn_FLT_RE_FLT_RE_MASK 0xFFu
#define EFTU_TIM_CHn_FLT_RE_FLT_RE_SHIFT 0u
#define EFTU_TIM_CHn_FLT_RE_FLT_RE_WIDTH 8u
#define EFTU_TIM_CHn_FLT_RE_FLT_RE(x)  (((uint32_t)(((uint32_t)(x))<<EFTU_TIM_CHn_FLT_RE_FLT_RE_SHIFT))&EFTU_TIM_CHn_FLT_RE_FLT_RE_MASK)
/* CH0_FLT_RE Reg Mask */
#define EFTU_TIM_CHn_FLT_RE_MASK       0x000000FFu

/* CHn_FLT_FE Bit Fields */
#define EFTU_TIM_CHn_FLT_FE_FLT_FE_MASK 0xFFu
#define EFTU_TIM_CHn_FLT_FE_FLT_FE_SHIFT 0u
#define EFTU_TIM_CHn_FLT_FE_FLT_FE_WIDTH 8u
#define EFTU_TIM_CHn_FLT_FE_FLT_FE(x)  (((uint32_t)(((uint32_t)(x))<<EFTU_TIM_CHn_FLT_FE_FLT_FE_SHIFT))&EFTU_TIM_CHn_FLT_FE_FLT_FE_MASK)
/* CH0_FLT_FE Reg Mask */
#define EFTU_TIM_CHn_FLT_FE_MASK       0x000000FFu

/* CHn_CTRL Bit Fields */
#define EFTU_TIM_CHn_CTRL_TIM_EN_MASK  0x1u
#define EFTU_TIM_CHn_CTRL_TIM_EN_SHIFT 0u
#define EFTU_TIM_CHn_CTRL_TIM_EN_WIDTH 1u
#define EFTU_TIM_CHn_CTRL_TIM_EN(x)    (((uint32_t)(((uint32_t)(x))<<EFTU_TIM_CHn_CTRL_TIM_EN_SHIFT))&EFTU_TIM_CHn_CTRL_TIM_EN_MASK)
#define EFTU_TIM_CHn_CTRL_TIM_MODE_MASK 0xEu
#define EFTU_TIM_CHn_CTRL_TIM_MODE_SHIFT 1u
#define EFTU_TIM_CHn_CTRL_TIM_MODE_WIDTH 3u
#define EFTU_TIM_CHn_CTRL_TIM_MODE(x)  (((uint32_t)(((uint32_t)(x))<<EFTU_TIM_CHn_CTRL_TIM_MODE_SHIFT))&EFTU_TIM_CHn_CTRL_TIM_MODE_MASK)
#define EFTU_TIM_CHn_CTRL_OSM_MASK     0x10u
#define EFTU_TIM_CHn_CTRL_OSM_SHIFT    4u
#define EFTU_TIM_CHn_CTRL_OSM_WIDTH    1u
#define EFTU_TIM_CHn_CTRL_OSM(x)       (((uint32_t)(((uint32_t)(x))<<EFTU_TIM_CHn_CTRL_OSM_SHIFT))&EFTU_TIM_CHn_CTRL_OSM_MASK)
#define EFTU_TIM_CHn_CTRL_CICTRL_MASK  0x40u
#define EFTU_TIM_CHn_CTRL_CICTRL_SHIFT 6u
#define EFTU_TIM_CHn_CTRL_CICTRL_WIDTH 1u
#define EFTU_TIM_CHn_CTRL_CICTRL(x)    (((uint32_t)(((uint32_t)(x))<<EFTU_TIM_CHn_CTRL_CICTRL_SHIFT))&EFTU_TIM_CHn_CTRL_CICTRL_MASK)
#define EFTU_TIM_CHn_CTRL_GPR0_SEL_MASK 0x380u
#define EFTU_TIM_CHn_CTRL_GPR0_SEL_SHIFT 7u
#define EFTU_TIM_CHn_CTRL_GPR0_SEL_WIDTH 3u
#define EFTU_TIM_CHn_CTRL_GPR0_SEL(x)  (((uint32_t)(((uint32_t)(x))<<EFTU_TIM_CHn_CTRL_GPR0_SEL_SHIFT))&EFTU_TIM_CHn_CTRL_GPR0_SEL_MASK)
#define EFTU_TIM_CHn_CTRL_GPR1_SEL_MASK 0x1C00u
#define EFTU_TIM_CHn_CTRL_GPR1_SEL_SHIFT 10u
#define EFTU_TIM_CHn_CTRL_GPR1_SEL_WIDTH 3u
#define EFTU_TIM_CHn_CTRL_GPR1_SEL(x)  (((uint32_t)(((uint32_t)(x))<<EFTU_TIM_CHn_CTRL_GPR1_SEL_SHIFT))&EFTU_TIM_CHn_CTRL_GPR1_SEL_MASK)
#define EFTU_TIM_CHn_CTRL_DSL_MASK     0x2000u
#define EFTU_TIM_CHn_CTRL_DSL_SHIFT    13u
#define EFTU_TIM_CHn_CTRL_DSL_WIDTH    1u
#define EFTU_TIM_CHn_CTRL_DSL(x)       (((uint32_t)(((uint32_t)(x))<<EFTU_TIM_CHn_CTRL_DSL_SHIFT))&EFTU_TIM_CHn_CTRL_DSL_MASK)
#define EFTU_TIM_CHn_CTRL_ISL_MASK     0x4000u
#define EFTU_TIM_CHn_CTRL_ISL_SHIFT    14u
#define EFTU_TIM_CHn_CTRL_ISL_WIDTH    1u
#define EFTU_TIM_CHn_CTRL_ISL(x)       (((uint32_t)(((uint32_t)(x))<<EFTU_TIM_CHn_CTRL_ISL_SHIFT))&EFTU_TIM_CHn_CTRL_ISL_MASK)
#define EFTU_TIM_CHn_CTRL_ECNT_RESET_MASK 0x8000u
#define EFTU_TIM_CHn_CTRL_ECNT_RESET_SHIFT 15u
#define EFTU_TIM_CHn_CTRL_ECNT_RESET_WIDTH 1u
#define EFTU_TIM_CHn_CTRL_ECNT_RESET(x) (((uint32_t)(((uint32_t)(x))<<EFTU_TIM_CHn_CTRL_ECNT_RESET_SHIFT))&EFTU_TIM_CHn_CTRL_ECNT_RESET_MASK)
#define EFTU_TIM_CHn_CTRL_FLT_EN_MASK  0x10000u
#define EFTU_TIM_CHn_CTRL_FLT_EN_SHIFT 16u
#define EFTU_TIM_CHn_CTRL_FLT_EN_WIDTH 1u
#define EFTU_TIM_CHn_CTRL_FLT_EN(x)    (((uint32_t)(((uint32_t)(x))<<EFTU_TIM_CHn_CTRL_FLT_EN_SHIFT))&EFTU_TIM_CHn_CTRL_FLT_EN_MASK)
#define EFTU_TIM_CHn_CTRL_FLT_CNT_FRQ_MASK 0x60000u
#define EFTU_TIM_CHn_CTRL_FLT_CNT_FRQ_SHIFT 17u
#define EFTU_TIM_CHn_CTRL_FLT_CNT_FRQ_WIDTH 2u
#define EFTU_TIM_CHn_CTRL_FLT_CNT_FRQ(x) (((uint32_t)(((uint32_t)(x))<<EFTU_TIM_CHn_CTRL_FLT_CNT_FRQ_SHIFT))&EFTU_TIM_CHn_CTRL_FLT_CNT_FRQ_MASK)
#define EFTU_TIM_CHn_CTRL_EXT_CAP_EN_MASK 0x80000u
#define EFTU_TIM_CHn_CTRL_EXT_CAP_EN_SHIFT 19u
#define EFTU_TIM_CHn_CTRL_EXT_CAP_EN_WIDTH 1u
#define EFTU_TIM_CHn_CTRL_EXT_CAP_EN(x) (((uint32_t)(((uint32_t)(x))<<EFTU_TIM_CHn_CTRL_EXT_CAP_EN_SHIFT))&EFTU_TIM_CHn_CTRL_EXT_CAP_EN_MASK)
#define EFTU_TIM_CHn_CTRL_FLT_MODE_RE_MASK 0x100000u
#define EFTU_TIM_CHn_CTRL_FLT_MODE_RE_SHIFT 20u
#define EFTU_TIM_CHn_CTRL_FLT_MODE_RE_WIDTH 1u
#define EFTU_TIM_CHn_CTRL_FLT_MODE_RE(x) (((uint32_t)(((uint32_t)(x))<<EFTU_TIM_CHn_CTRL_FLT_MODE_RE_SHIFT))&EFTU_TIM_CHn_CTRL_FLT_MODE_RE_MASK)
#define EFTU_TIM_CHn_CTRL_FLT_CTR_RE_MASK 0x200000u
#define EFTU_TIM_CHn_CTRL_FLT_CTR_RE_SHIFT 21u
#define EFTU_TIM_CHn_CTRL_FLT_CTR_RE_WIDTH 1u
#define EFTU_TIM_CHn_CTRL_FLT_CTR_RE(x) (((uint32_t)(((uint32_t)(x))<<EFTU_TIM_CHn_CTRL_FLT_CTR_RE_SHIFT))&EFTU_TIM_CHn_CTRL_FLT_CTR_RE_MASK)
#define EFTU_TIM_CHn_CTRL_FLT_MODE_FE_MASK 0x400000u
#define EFTU_TIM_CHn_CTRL_FLT_MODE_FE_SHIFT 22u
#define EFTU_TIM_CHn_CTRL_FLT_MODE_FE_WIDTH 1u
#define EFTU_TIM_CHn_CTRL_FLT_MODE_FE(x) (((uint32_t)(((uint32_t)(x))<<EFTU_TIM_CHn_CTRL_FLT_MODE_FE_SHIFT))&EFTU_TIM_CHn_CTRL_FLT_MODE_FE_MASK)
#define EFTU_TIM_CHn_CTRL_FLT_CTR_FE_MASK 0x800000u
#define EFTU_TIM_CHn_CTRL_FLT_CTR_FE_SHIFT 23u
#define EFTU_TIM_CHn_CTRL_FLT_CTR_FE_WIDTH 1u
#define EFTU_TIM_CHn_CTRL_FLT_CTR_FE(x) (((uint32_t)(((uint32_t)(x))<<EFTU_TIM_CHn_CTRL_FLT_CTR_FE_SHIFT))&EFTU_TIM_CHn_CTRL_FLT_CTR_FE_MASK)
#define EFTU_TIM_CHn_CTRL_CLK_SEL_MASK 0x7000000u
#define EFTU_TIM_CHn_CTRL_CLK_SEL_SHIFT 24u
#define EFTU_TIM_CHn_CTRL_CLK_SEL_WIDTH 3u
#define EFTU_TIM_CHn_CTRL_CLK_SEL(x)   (((uint32_t)(((uint32_t)(x))<<EFTU_TIM_CHn_CTRL_CLK_SEL_SHIFT))&EFTU_TIM_CHn_CTRL_CLK_SEL_MASK)
#define EFTU_TIM_CHn_CTRL_FR_ECNT_OFL_MASK 0x8000000u
#define EFTU_TIM_CHn_CTRL_FR_ECNT_OFL_SHIFT 27u
#define EFTU_TIM_CHn_CTRL_FR_ECNT_OFL_WIDTH 1u
#define EFTU_TIM_CHn_CTRL_FR_ECNT_OFL(x) (((uint32_t)(((uint32_t)(x))<<EFTU_TIM_CHn_CTRL_FR_ECNT_OFL_SHIFT))&EFTU_TIM_CHn_CTRL_FR_ECNT_OFL_MASK)
#define EFTU_TIM_CHn_CTRL_TBU0_SEL_MASK 0x10000000u
#define EFTU_TIM_CHn_CTRL_TBU0_SEL_SHIFT 28u
#define EFTU_TIM_CHn_CTRL_TBU0_SEL_WIDTH 1u
#define EFTU_TIM_CHn_CTRL_TBU0_SEL(x)  (((uint32_t)(((uint32_t)(x))<<EFTU_TIM_CHn_CTRL_TBU0_SEL_SHIFT))&EFTU_TIM_CHn_CTRL_TBU0_SEL_MASK)
#define EFTU_TIM_CHn_CTRL_CNTS_SEL_MASK 0x20000000u
#define EFTU_TIM_CHn_CTRL_CNTS_SEL_SHIFT 29u
#define EFTU_TIM_CHn_CTRL_CNTS_SEL_WIDTH 1u
#define EFTU_TIM_CHn_CTRL_CNTS_SEL(x)  (((uint32_t)(((uint32_t)(x))<<EFTU_TIM_CHn_CTRL_CNTS_SEL_SHIFT))&EFTU_TIM_CHn_CTRL_CNTS_SEL_MASK)
#define EFTU_TIM_CHn_CTRL_TOCTRL_MASK  0xC0000000u
#define EFTU_TIM_CHn_CTRL_TOCTRL_SHIFT 30u
#define EFTU_TIM_CHn_CTRL_TOCTRL_WIDTH 2u
#define EFTU_TIM_CHn_CTRL_TOCTRL(x)    (((uint32_t)(((uint32_t)(x))<<EFTU_TIM_CHn_CTRL_TOCTRL_SHIFT))&EFTU_TIM_CHn_CTRL_TOCTRL_MASK)
/* CH0_CTRL Reg Mask */
#define EFTU_TIM_CHn_CTRL_MASK         0xFFFFFFDFu

/* CHn_ECTRL Bit Fields */
#define EFTU_TIM_CHn_ECTRL_EXT_CAP_SRC_MASK 0xFu
#define EFTU_TIM_CHn_ECTRL_EXT_CAP_SRC_SHIFT 0u
#define EFTU_TIM_CHn_ECTRL_EXT_CAP_SRC_WIDTH 4u
#define EFTU_TIM_CHn_ECTRL_EXT_CAP_SRC(x) (((uint32_t)(((uint32_t)(x))<<EFTU_TIM_CHn_ECTRL_EXT_CAP_SRC_SHIFT))&EFTU_TIM_CHn_ECTRL_EXT_CAP_SRC_MASK)
#define EFTU_TIM_CHn_ECTRL_USE_PREV_EG_IN_MASK 0x20u
#define EFTU_TIM_CHn_ECTRL_USE_PREV_EG_IN_SHIFT 5u
#define EFTU_TIM_CHn_ECTRL_USE_PREV_EG_IN_WIDTH 1u
#define EFTU_TIM_CHn_ECTRL_USE_PREV_EG_IN(x) (((uint32_t)(((uint32_t)(x))<<EFTU_TIM_CHn_ECTRL_USE_PREV_EG_IN_SHIFT))&EFTU_TIM_CHn_ECTRL_USE_PREV_EG_IN_MASK)
#define EFTU_TIM_CHn_ECTRL_TODET_IRQ_SRC_MASK 0xC0u
#define EFTU_TIM_CHn_ECTRL_TODET_IRQ_SRC_SHIFT 6u
#define EFTU_TIM_CHn_ECTRL_TODET_IRQ_SRC_WIDTH 2u
#define EFTU_TIM_CHn_ECTRL_TODET_IRQ_SRC(x) (((uint32_t)(((uint32_t)(x))<<EFTU_TIM_CHn_ECTRL_TODET_IRQ_SRC_SHIFT))&EFTU_TIM_CHn_ECTRL_TODET_IRQ_SRC_MASK)
#define EFTU_TIM_CHn_ECTRL_EG_START_MASK 0x700u
#define EFTU_TIM_CHn_ECTRL_EG_START_SHIFT 8u
#define EFTU_TIM_CHn_ECTRL_EG_START_WIDTH 3u
#define EFTU_TIM_CHn_ECTRL_EG_START(x) (((uint32_t)(((uint32_t)(x))<<EFTU_TIM_CHn_ECTRL_EG_START_SHIFT))&EFTU_TIM_CHn_ECTRL_EG_START_MASK)
#define EFTU_TIM_CHn_ECTRL_EG_STOP_MASK 0x7000u
#define EFTU_TIM_CHn_ECTRL_EG_STOP_SHIFT 12u
#define EFTU_TIM_CHn_ECTRL_EG_STOP_WIDTH 3u
#define EFTU_TIM_CHn_ECTRL_EG_STOP(x)  (((uint32_t)(((uint32_t)(x))<<EFTU_TIM_CHn_ECTRL_EG_STOP_SHIFT))&EFTU_TIM_CHn_ECTRL_EG_STOP_MASK)
#define EFTU_TIM_CHn_ECTRL_EG_RESYNC_MASK 0xF0000u
#define EFTU_TIM_CHn_ECTRL_EG_RESYNC_SHIFT 16u
#define EFTU_TIM_CHn_ECTRL_EG_RESYNC_WIDTH 4u
#define EFTU_TIM_CHn_ECTRL_EG_RESYNC(x) (((uint32_t)(((uint32_t)(x))<<EFTU_TIM_CHn_ECTRL_EG_RESYNC_SHIFT))&EFTU_TIM_CHn_ECTRL_EG_RESYNC_MASK)
#define EFTU_TIM_CHn_ECTRL_EFLT_CTR_RE_MASK 0x100000u
#define EFTU_TIM_CHn_ECTRL_EFLT_CTR_RE_SHIFT 20u
#define EFTU_TIM_CHn_ECTRL_EFLT_CTR_RE_WIDTH 1u
#define EFTU_TIM_CHn_ECTRL_EFLT_CTR_RE(x) (((uint32_t)(((uint32_t)(x))<<EFTU_TIM_CHn_ECTRL_EFLT_CTR_RE_SHIFT))&EFTU_TIM_CHn_ECTRL_EFLT_CTR_RE_MASK)
#define EFTU_TIM_CHn_ECTRL_EFLT_CTR_FE_MASK 0x200000u
#define EFTU_TIM_CHn_ECTRL_EFLT_CTR_FE_SHIFT 21u
#define EFTU_TIM_CHn_ECTRL_EFLT_CTR_FE_WIDTH 1u
#define EFTU_TIM_CHn_ECTRL_EFLT_CTR_FE(x) (((uint32_t)(((uint32_t)(x))<<EFTU_TIM_CHn_ECTRL_EFLT_CTR_FE_SHIFT))&EFTU_TIM_CHn_ECTRL_EFLT_CTR_FE_MASK)
#define EFTU_TIM_CHn_ECTRL_USE_LUT_MASK 0xC00000u
#define EFTU_TIM_CHn_ECTRL_USE_LUT_SHIFT 22u
#define EFTU_TIM_CHn_ECTRL_USE_LUT_WIDTH 2u
#define EFTU_TIM_CHn_ECTRL_USE_LUT(x)  (((uint32_t)(((uint32_t)(x))<<EFTU_TIM_CHn_ECTRL_USE_LUT_SHIFT))&EFTU_TIM_CHn_ECTRL_USE_LUT_MASK)
#define EFTU_TIM_CHn_ECTRL_TIM_TRG_SRC_MASK 0xF000000u
#define EFTU_TIM_CHn_ECTRL_TIM_TRG_SRC_SHIFT 24u
#define EFTU_TIM_CHn_ECTRL_TIM_TRG_SRC_WIDTH 4u
#define EFTU_TIM_CHn_ECTRL_TIM_TRG_SRC(x) (((uint32_t)(((uint32_t)(x))<<EFTU_TIM_CHn_ECTRL_TIM_TRG_SRC_SHIFT))&EFTU_TIM_CHn_ECTRL_TIM_TRG_SRC_MASK)
#define EFTU_TIM_CHn_ECTRL_SWAP_CAPTURE_MASK 0x10000000u
#define EFTU_TIM_CHn_ECTRL_SWAP_CAPTURE_SHIFT 28u
#define EFTU_TIM_CHn_ECTRL_SWAP_CAPTURE_WIDTH 1u
#define EFTU_TIM_CHn_ECTRL_SWAP_CAPTURE(x) (((uint32_t)(((uint32_t)(x))<<EFTU_TIM_CHn_ECTRL_SWAP_CAPTURE_SHIFT))&EFTU_TIM_CHn_ECTRL_SWAP_CAPTURE_MASK)
#define EFTU_TIM_CHn_ECTRL_IMM_START_MASK 0x20000000u
#define EFTU_TIM_CHn_ECTRL_IMM_START_SHIFT 29u
#define EFTU_TIM_CHn_ECTRL_IMM_START_WIDTH 1u
#define EFTU_TIM_CHn_ECTRL_IMM_START(x) (((uint32_t)(((uint32_t)(x))<<EFTU_TIM_CHn_ECTRL_IMM_START_SHIFT))&EFTU_TIM_CHn_ECTRL_IMM_START_MASK)
#define EFTU_TIM_CHn_ECTRL_ECLK_SEL_MASK 0x40000000u
#define EFTU_TIM_CHn_ECTRL_ECLK_SEL_SHIFT 30u
#define EFTU_TIM_CHn_ECTRL_ECLK_SEL_WIDTH 1u
#define EFTU_TIM_CHn_ECTRL_ECLK_SEL(x) (((uint32_t)(((uint32_t)(x))<<EFTU_TIM_CHn_ECTRL_ECLK_SEL_SHIFT))&EFTU_TIM_CHn_ECTRL_ECLK_SEL_MASK)
#define EFTU_TIM_CHn_ECTRL_USE_PREV_CH_IN_MASK 0x80000000u
#define EFTU_TIM_CHn_ECTRL_USE_PREV_CH_IN_SHIFT 31u
#define EFTU_TIM_CHn_ECTRL_USE_PREV_CH_IN_WIDTH 1u
#define EFTU_TIM_CHn_ECTRL_USE_PREV_CH_IN(x) (((uint32_t)(((uint32_t)(x))<<EFTU_TIM_CHn_ECTRL_USE_PREV_CH_IN_SHIFT))&EFTU_TIM_CHn_ECTRL_USE_PREV_CH_IN_MASK)
/* CH0_ECTRL Reg Mask */
#define EFTU_TIM_CHn_ECTRL_MASK        0xFFFF77EFu

/* CHn_IRQ_ST Bit Fields */
#define EFTU_TIM_CHn_IRQ_ST_NEWVAL_MASK 0x1u
#define EFTU_TIM_CHn_IRQ_ST_NEWVAL_SHIFT 0u
#define EFTU_TIM_CHn_IRQ_ST_NEWVAL_WIDTH 1u
#define EFTU_TIM_CHn_IRQ_ST_NEWVAL(x)  (((uint32_t)(((uint32_t)(x))<<EFTU_TIM_CHn_IRQ_ST_NEWVAL_SHIFT))&EFTU_TIM_CHn_IRQ_ST_NEWVAL_MASK)
#define EFTU_TIM_CHn_IRQ_ST_ECNTOFL_MASK 0x2u
#define EFTU_TIM_CHn_IRQ_ST_ECNTOFL_SHIFT 1u
#define EFTU_TIM_CHn_IRQ_ST_ECNTOFL_WIDTH 1u
#define EFTU_TIM_CHn_IRQ_ST_ECNTOFL(x) (((uint32_t)(((uint32_t)(x))<<EFTU_TIM_CHn_IRQ_ST_ECNTOFL_SHIFT))&EFTU_TIM_CHn_IRQ_ST_ECNTOFL_MASK)
#define EFTU_TIM_CHn_IRQ_ST_CNTOFL_MASK 0x4u
#define EFTU_TIM_CHn_IRQ_ST_CNTOFL_SHIFT 2u
#define EFTU_TIM_CHn_IRQ_ST_CNTOFL_WIDTH 1u
#define EFTU_TIM_CHn_IRQ_ST_CNTOFL(x)  (((uint32_t)(((uint32_t)(x))<<EFTU_TIM_CHn_IRQ_ST_CNTOFL_SHIFT))&EFTU_TIM_CHn_IRQ_ST_CNTOFL_MASK)
#define EFTU_TIM_CHn_IRQ_ST_GPROFL_MASK 0x8u
#define EFTU_TIM_CHn_IRQ_ST_GPROFL_SHIFT 3u
#define EFTU_TIM_CHn_IRQ_ST_GPROFL_WIDTH 1u
#define EFTU_TIM_CHn_IRQ_ST_GPROFL(x)  (((uint32_t)(((uint32_t)(x))<<EFTU_TIM_CHn_IRQ_ST_GPROFL_SHIFT))&EFTU_TIM_CHn_IRQ_ST_GPROFL_MASK)
#define EFTU_TIM_CHn_IRQ_ST_TODET_MASK 0x10u
#define EFTU_TIM_CHn_IRQ_ST_TODET_SHIFT 4u
#define EFTU_TIM_CHn_IRQ_ST_TODET_WIDTH 1u
#define EFTU_TIM_CHn_IRQ_ST_TODET(x)   (((uint32_t)(((uint32_t)(x))<<EFTU_TIM_CHn_IRQ_ST_TODET_SHIFT))&EFTU_TIM_CHn_IRQ_ST_TODET_MASK)
#define EFTU_TIM_CHn_IRQ_ST_GLITCHDET_MASK 0x20u
#define EFTU_TIM_CHn_IRQ_ST_GLITCHDET_SHIFT 5u
#define EFTU_TIM_CHn_IRQ_ST_GLITCHDET_WIDTH 1u
#define EFTU_TIM_CHn_IRQ_ST_GLITCHDET(x) (((uint32_t)(((uint32_t)(x))<<EFTU_TIM_CHn_IRQ_ST_GLITCHDET_SHIFT))&EFTU_TIM_CHn_IRQ_ST_GLITCHDET_MASK)
/* CH0_IRQ_ST Reg Mask */
#define EFTU_TIM_CHn_IRQ_ST_MASK       0x0000003Fu

/* CHn_IRQ_EN Bit Fields */
#define EFTU_TIM_CHn_IRQ_EN_NEWVAL_IRQ_EN_MASK 0x1u
#define EFTU_TIM_CHn_IRQ_EN_NEWVAL_IRQ_EN_SHIFT 0u
#define EFTU_TIM_CHn_IRQ_EN_NEWVAL_IRQ_EN_WIDTH 1u
#define EFTU_TIM_CHn_IRQ_EN_NEWVAL_IRQ_EN(x) (((uint32_t)(((uint32_t)(x))<<EFTU_TIM_CHn_IRQ_EN_NEWVAL_IRQ_EN_SHIFT))&EFTU_TIM_CHn_IRQ_EN_NEWVAL_IRQ_EN_MASK)
#define EFTU_TIM_CHn_IRQ_EN_ECNTOFL_IRQ_EN_MASK 0x2u
#define EFTU_TIM_CHn_IRQ_EN_ECNTOFL_IRQ_EN_SHIFT 1u
#define EFTU_TIM_CHn_IRQ_EN_ECNTOFL_IRQ_EN_WIDTH 1u
#define EFTU_TIM_CHn_IRQ_EN_ECNTOFL_IRQ_EN(x) (((uint32_t)(((uint32_t)(x))<<EFTU_TIM_CHn_IRQ_EN_ECNTOFL_IRQ_EN_SHIFT))&EFTU_TIM_CHn_IRQ_EN_ECNTOFL_IRQ_EN_MASK)
#define EFTU_TIM_CHn_IRQ_EN_CNTOFL_IRQ_EN_MASK 0x4u
#define EFTU_TIM_CHn_IRQ_EN_CNTOFL_IRQ_EN_SHIFT 2u
#define EFTU_TIM_CHn_IRQ_EN_CNTOFL_IRQ_EN_WIDTH 1u
#define EFTU_TIM_CHn_IRQ_EN_CNTOFL_IRQ_EN(x) (((uint32_t)(((uint32_t)(x))<<EFTU_TIM_CHn_IRQ_EN_CNTOFL_IRQ_EN_SHIFT))&EFTU_TIM_CHn_IRQ_EN_CNTOFL_IRQ_EN_MASK)
#define EFTU_TIM_CHn_IRQ_EN_GPROFL_IRQ_EN_MASK 0x8u
#define EFTU_TIM_CHn_IRQ_EN_GPROFL_IRQ_EN_SHIFT 3u
#define EFTU_TIM_CHn_IRQ_EN_GPROFL_IRQ_EN_WIDTH 1u
#define EFTU_TIM_CHn_IRQ_EN_GPROFL_IRQ_EN(x) (((uint32_t)(((uint32_t)(x))<<EFTU_TIM_CHn_IRQ_EN_GPROFL_IRQ_EN_SHIFT))&EFTU_TIM_CHn_IRQ_EN_GPROFL_IRQ_EN_MASK)
#define EFTU_TIM_CHn_IRQ_EN_TODET_IRQ_EN_MASK 0x10u
#define EFTU_TIM_CHn_IRQ_EN_TODET_IRQ_EN_SHIFT 4u
#define EFTU_TIM_CHn_IRQ_EN_TODET_IRQ_EN_WIDTH 1u
#define EFTU_TIM_CHn_IRQ_EN_TODET_IRQ_EN(x) (((uint32_t)(((uint32_t)(x))<<EFTU_TIM_CHn_IRQ_EN_TODET_IRQ_EN_SHIFT))&EFTU_TIM_CHn_IRQ_EN_TODET_IRQ_EN_MASK)
#define EFTU_TIM_CHn_IRQ_EN_GLITCHDET_IRQ_EN_MASK 0x20u
#define EFTU_TIM_CHn_IRQ_EN_GLITCHDET_IRQ_EN_SHIFT 5u
#define EFTU_TIM_CHn_IRQ_EN_GLITCHDET_IRQ_EN_WIDTH 1u
#define EFTU_TIM_CHn_IRQ_EN_GLITCHDET_IRQ_EN(x) (((uint32_t)(((uint32_t)(x))<<EFTU_TIM_CHn_IRQ_EN_GLITCHDET_IRQ_EN_SHIFT))&EFTU_TIM_CHn_IRQ_EN_GLITCHDET_IRQ_EN_MASK)
/* CH0_IRQ_EN Reg Mask */
#define EFTU_TIM_CHn_IRQ_EN_MASK       0x0000003Fu

/* RST Bit Fields */
#define EFTU_TIM_RST_RST_CH_MASK       0xFFu
#define EFTU_TIM_RST_RST_CH_SHIFT      0u
#define EFTU_TIM_RST_RST_CH_WIDTH      8u
#define EFTU_TIM_RST_RST_CH(x)         (((uint32_t)(((uint32_t)(x))<<EFTU_TIM_RST_RST_CH_SHIFT))&EFTU_TIM_RST_RST_CH_MASK)
/* RST Reg Mask */
#define EFTU_TIM_RST_MASK              0x000000FFu

/* IN_SRC Bit Fields */
#define EFTU_TIM_IN_SRC_VAL_0_MASK     0x3u
#define EFTU_TIM_IN_SRC_VAL_0_SHIFT    0u
#define EFTU_TIM_IN_SRC_VAL_0_WIDTH    2u
#define EFTU_TIM_IN_SRC_VAL_0(x)       (((uint32_t)(((uint32_t)(x))<<EFTU_TIM_IN_SRC_VAL_0_SHIFT))&EFTU_TIM_IN_SRC_VAL_0_MASK)
#define EFTU_TIM_IN_SRC_MODE_0_MASK    0xCu
#define EFTU_TIM_IN_SRC_MODE_0_SHIFT   2u
#define EFTU_TIM_IN_SRC_MODE_0_WIDTH   2u
#define EFTU_TIM_IN_SRC_MODE_0(x)      (((uint32_t)(((uint32_t)(x))<<EFTU_TIM_IN_SRC_MODE_0_SHIFT))&EFTU_TIM_IN_SRC_MODE_0_MASK)
#define EFTU_TIM_IN_SRC_VAL_1_MASK     0x30u
#define EFTU_TIM_IN_SRC_VAL_1_SHIFT    4u
#define EFTU_TIM_IN_SRC_VAL_1_WIDTH    2u
#define EFTU_TIM_IN_SRC_VAL_1(x)       (((uint32_t)(((uint32_t)(x))<<EFTU_TIM_IN_SRC_VAL_1_SHIFT))&EFTU_TIM_IN_SRC_VAL_1_MASK)
#define EFTU_TIM_IN_SRC_MODE_1_MASK    0xC0u
#define EFTU_TIM_IN_SRC_MODE_1_SHIFT   6u
#define EFTU_TIM_IN_SRC_MODE_1_WIDTH   2u
#define EFTU_TIM_IN_SRC_MODE_1(x)      (((uint32_t)(((uint32_t)(x))<<EFTU_TIM_IN_SRC_MODE_1_SHIFT))&EFTU_TIM_IN_SRC_MODE_1_MASK)
#define EFTU_TIM_IN_SRC_VAL_2_MASK     0x300u
#define EFTU_TIM_IN_SRC_VAL_2_SHIFT    8u
#define EFTU_TIM_IN_SRC_VAL_2_WIDTH    2u
#define EFTU_TIM_IN_SRC_VAL_2(x)       (((uint32_t)(((uint32_t)(x))<<EFTU_TIM_IN_SRC_VAL_2_SHIFT))&EFTU_TIM_IN_SRC_VAL_2_MASK)
#define EFTU_TIM_IN_SRC_MODE_2_MASK    0xC00u
#define EFTU_TIM_IN_SRC_MODE_2_SHIFT   10u
#define EFTU_TIM_IN_SRC_MODE_2_WIDTH   2u
#define EFTU_TIM_IN_SRC_MODE_2(x)      (((uint32_t)(((uint32_t)(x))<<EFTU_TIM_IN_SRC_MODE_2_SHIFT))&EFTU_TIM_IN_SRC_MODE_2_MASK)
#define EFTU_TIM_IN_SRC_VAL_3_MASK     0x3000u
#define EFTU_TIM_IN_SRC_VAL_3_SHIFT    12u
#define EFTU_TIM_IN_SRC_VAL_3_WIDTH    2u
#define EFTU_TIM_IN_SRC_VAL_3(x)       (((uint32_t)(((uint32_t)(x))<<EFTU_TIM_IN_SRC_VAL_3_SHIFT))&EFTU_TIM_IN_SRC_VAL_3_MASK)
#define EFTU_TIM_IN_SRC_MODE_3_MASK    0xC000u
#define EFTU_TIM_IN_SRC_MODE_3_SHIFT   14u
#define EFTU_TIM_IN_SRC_MODE_3_WIDTH   2u
#define EFTU_TIM_IN_SRC_MODE_3(x)      (((uint32_t)(((uint32_t)(x))<<EFTU_TIM_IN_SRC_MODE_3_SHIFT))&EFTU_TIM_IN_SRC_MODE_3_MASK)
#define EFTU_TIM_IN_SRC_VAL_4_MASK     0x30000u
#define EFTU_TIM_IN_SRC_VAL_4_SHIFT    16u
#define EFTU_TIM_IN_SRC_VAL_4_WIDTH    2u
#define EFTU_TIM_IN_SRC_VAL_4(x)       (((uint32_t)(((uint32_t)(x))<<EFTU_TIM_IN_SRC_VAL_4_SHIFT))&EFTU_TIM_IN_SRC_VAL_4_MASK)
#define EFTU_TIM_IN_SRC_MODE_4_MASK    0xC0000u
#define EFTU_TIM_IN_SRC_MODE_4_SHIFT   18u
#define EFTU_TIM_IN_SRC_MODE_4_WIDTH   2u
#define EFTU_TIM_IN_SRC_MODE_4(x)      (((uint32_t)(((uint32_t)(x))<<EFTU_TIM_IN_SRC_MODE_4_SHIFT))&EFTU_TIM_IN_SRC_MODE_4_MASK)
#define EFTU_TIM_IN_SRC_VAL_5_MASK     0x300000u
#define EFTU_TIM_IN_SRC_VAL_5_SHIFT    20u
#define EFTU_TIM_IN_SRC_VAL_5_WIDTH    2u
#define EFTU_TIM_IN_SRC_VAL_5(x)       (((uint32_t)(((uint32_t)(x))<<EFTU_TIM_IN_SRC_VAL_5_SHIFT))&EFTU_TIM_IN_SRC_VAL_5_MASK)
#define EFTU_TIM_IN_SRC_MODE_5_MASK    0xC00000u
#define EFTU_TIM_IN_SRC_MODE_5_SHIFT   22u
#define EFTU_TIM_IN_SRC_MODE_5_WIDTH   2u
#define EFTU_TIM_IN_SRC_MODE_5(x)      (((uint32_t)(((uint32_t)(x))<<EFTU_TIM_IN_SRC_MODE_5_SHIFT))&EFTU_TIM_IN_SRC_MODE_5_MASK)
#define EFTU_TIM_IN_SRC_VAL_6_MASK     0x3000000u
#define EFTU_TIM_IN_SRC_VAL_6_SHIFT    24u
#define EFTU_TIM_IN_SRC_VAL_6_WIDTH    2u
#define EFTU_TIM_IN_SRC_VAL_6(x)       (((uint32_t)(((uint32_t)(x))<<EFTU_TIM_IN_SRC_VAL_6_SHIFT))&EFTU_TIM_IN_SRC_VAL_6_MASK)
#define EFTU_TIM_IN_SRC_MODE_6_MASK    0xC000000u
#define EFTU_TIM_IN_SRC_MODE_6_SHIFT   26u
#define EFTU_TIM_IN_SRC_MODE_6_WIDTH   2u
#define EFTU_TIM_IN_SRC_MODE_6(x)      (((uint32_t)(((uint32_t)(x))<<EFTU_TIM_IN_SRC_MODE_6_SHIFT))&EFTU_TIM_IN_SRC_MODE_6_MASK)
#define EFTU_TIM_IN_SRC_VAL_7_MASK     0x30000000u
#define EFTU_TIM_IN_SRC_VAL_7_SHIFT    28u
#define EFTU_TIM_IN_SRC_VAL_7_WIDTH    2u
#define EFTU_TIM_IN_SRC_VAL_7(x)       (((uint32_t)(((uint32_t)(x))<<EFTU_TIM_IN_SRC_VAL_7_SHIFT))&EFTU_TIM_IN_SRC_VAL_7_MASK)
#define EFTU_TIM_IN_SRC_MODE_7_MASK    0xC0000000u
#define EFTU_TIM_IN_SRC_MODE_7_SHIFT   30u
#define EFTU_TIM_IN_SRC_MODE_7_WIDTH   2u
#define EFTU_TIM_IN_SRC_MODE_7(x)      (((uint32_t)(((uint32_t)(x))<<EFTU_TIM_IN_SRC_MODE_7_SHIFT))&EFTU_TIM_IN_SRC_MODE_7_MASK)
/* IN_SRC Reg Mask */
#define EFTU_TIM_IN_SRC_MASK           0xFFFFFFFFu

/* INP_VAL Bit Fields */
#define EFTU_TIM_INP_VAL_F_OUT_MASK    0xFFu
#define EFTU_TIM_INP_VAL_F_OUT_SHIFT   0u
#define EFTU_TIM_INP_VAL_F_OUT_WIDTH   8u
#define EFTU_TIM_INP_VAL_F_OUT(x)      (((uint32_t)(((uint32_t)(x))<<EFTU_TIM_INP_VAL_F_OUT_SHIFT))&EFTU_TIM_INP_VAL_F_OUT_MASK)
#define EFTU_TIM_INP_VAL_F_IN_MASK     0xFF00u
#define EFTU_TIM_INP_VAL_F_IN_SHIFT    8u
#define EFTU_TIM_INP_VAL_F_IN_WIDTH    8u
#define EFTU_TIM_INP_VAL_F_IN(x)       (((uint32_t)(((uint32_t)(x))<<EFTU_TIM_INP_VAL_F_IN_SHIFT))&EFTU_TIM_INP_VAL_F_IN_MASK)
#define EFTU_TIM_INP_VAL_TIM_IN_MASK   0xFF0000u
#define EFTU_TIM_INP_VAL_TIM_IN_SHIFT  16u
#define EFTU_TIM_INP_VAL_TIM_IN_WIDTH  8u
#define EFTU_TIM_INP_VAL_TIM_IN(x)     (((uint32_t)(((uint32_t)(x))<<EFTU_TIM_INP_VAL_TIM_IN_SHIFT))&EFTU_TIM_INP_VAL_TIM_IN_MASK)
/* INP_VAL Reg Mask */
#define EFTU_TIM_INP_VAL_MASK          0x00FFFFFFu

/* TIM_SPEC_LOCK Bit Fields */
#define EFTU_TIM_TIM_SPEC_LOCK_SPEC_LOCK_MASK 0xFFFFFFFFu
#define EFTU_TIM_TIM_SPEC_LOCK_SPEC_LOCK_SHIFT 0u
#define EFTU_TIM_TIM_SPEC_LOCK_SPEC_LOCK_WIDTH 32u
#define EFTU_TIM_TIM_SPEC_LOCK_SPEC_LOCK(x) (((uint32_t)(((uint32_t)(x))<<EFTU_TIM_TIM_SPEC_LOCK_SPEC_LOCK_SHIFT))&EFTU_TIM_TIM_SPEC_LOCK_SPEC_LOCK_MASK)
/* TIM_SPEC_LOCK Reg Mask */
#define EFTU_TIM_TIM_SPEC_LOCK_MASK    0xFFFFFFFFu


/*!
 * @}
 */ /* end of group EFTU_TIM_Register_Masks */

/*!
 * @}
 */ /* end of group EFTU_TIM_Peripheral_Access_Layer */

#endif
