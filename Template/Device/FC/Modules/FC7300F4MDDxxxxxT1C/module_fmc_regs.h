#ifndef _MODULE_FMC_gmbhdijq36_REGS_H_FMC_H_
#define _MODULE_FMC_gmbhdijq36_REGS_H_FMC_H_

/* ----------------------------------------------------------------------------
   -- FMC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FMC_Peripheral_Access_Layer FMC Peripheral Access Layer
 * @{
 */

/** FMC - Size of Registers Arrays */

/** FMC - Register Layout Typedef */
#define FMC_FB_FPELCK_COUNT 6
#define FMC_FB_CPELCK_COUNT 8
#define FMC_OTA_CTRL_COUNT 1
#define FMC_OTA_START_ADDR_COUNT 1
#define FMC_OTA_START_ADDR_HIGH_COUNT 1
#define FMC_OTA_END_ADDR_COUNT 1
#define FMC_OTA_END_ADDR_HIGH_COUNT 1
#define FMC_OTA_VER_LOC_COUNT 1
#define FMC_OTA_ACT_VER_COUNT 1

typedef struct {

  __IO uint32_t FAPC0                         ; /* Flash Access Port Control Register0, offset: 0x0 */
       uint8_t  RESERVED_0[4];
  __IO uint32_t FAPC2                         ; /* Flash Access Port Control Register2, offset: 0x8 */
       uint8_t  RESERVED_1[4];
  __IO uint32_t FEEC                          ; /* Flash ECC Error Control Register, offset: 0x10 */
       uint8_t  RESERVED_2[12];
  __IO uint32_t FEINTC                        ; /* Flash Error Interrupt Control Register, offset: 0x20 */
  __IO uint32_t FEINT_CPU0                    ; /* Flash Error Interrupt CPU0 Register, offset: 0x24 */
  __IO uint32_t FEINT_CPU1                    ; /* Flash Error Interrupt CPU1 Register, offset: 0x28 */
       uint8_t  RESERVED_3[8];
  __IO uint32_t FEINT_HSM                     ; /* Flash Error Interrupt HSM Register, offset: 0x34 */
  __IO uint32_t LINEBUFC                      ; /* Linebuffer Control Register, offset: 0x38 */
       uint8_t  RESERVED_4[4];
  __IO uint32_t FEIDC_0                       ; /* Flash ECC Injection Data Error Control Register0, offset: 0x40 */
  __IO uint32_t FEIDC_1                       ; /* Flash ECC Injection Data Error Control Register1, offset: 0x44 */
  __IO uint32_t FEIDC_2                       ; /* Flash ECC Injection Data Error Control Register2, offset: 0x48 */
  __IO uint32_t FEIDC_3                       ; /* Flash ECC Injection Data Error Control Register3, offset: 0x4C */
  __IO uint32_t FEIDC_4                       ; /* Flash ECC Injection Data Error Control Register4, offset: 0x50 */
       uint8_t  RESERVED_5[12];
  __IO uint32_t FEIEC                         ; /* Flash ECC Inject ECC Error Control Register, offset: 0x60 */
       uint8_t  RESERVED_6[668];
  __IO uint32_t FPESA_L                       ; /* Flash Program Erase Start Address Logical Register, offset: 0x300 */
  __I  uint32_t FPESA_P                       ; /* Flash Program Erase Start Address Physical Register, offset: 0x304 */
       uint8_t  RESERVED_7[24];
  __IO uint32_t FB_FPELCK8                    ; /* Flash Block n Fine Program Erase Lock Register, offset: 0x320 */
  __IO uint32_t FB_FPELCK9                    ; /* Flash Block n Fine Program Erase Lock Register, offset: 0x324 */
       uint8_t  RESERVED_8[24];
  __IO uint32_t FB_FPELCK[FMC_FB_FPELCK_COUNT]; /* Flash Block n Fine Program Erase Lock Register, offset: 0x340 */
  __IO uint32_t FN_FPELCK                     ; /* Flash NVR Fine Program Erase Lock Register, offset: 0x358 */
  __IO uint32_t FB_CPELCK[FMC_FB_CPELCK_COUNT]; /* Flash Block n Coarse Program Erase Lock Register, offset: 0x35c */
       uint8_t  RESERVED_9[388];
  __IO uint32_t OTA_CTRL[FMC_OTA_CTRL_COUNT]  ; /* OTA Control Register, offset: 0x500 */
       uint8_t  RESERVED_10[8];
  __I  uint32_t OTA_VER_LOC[FMC_OTA_VER_LOC_COUNT]; /* OTA Version Location Register, offset: 0x50c */
       uint8_t  RESERVED_11[8];
  __I  uint32_t OTA_ACT_VER[FMC_OTA_ACT_VER_COUNT]; /* OTA Active Version Register, offset: 0x518 */
       uint8_t  RESERVED_12[8];
 __IO  uint32_t OTA_START_ADDR[FMC_OTA_START_ADDR_COUNT]; /* OTA Start Address Register, offset: 0x524 */
       uint8_t  RESERVED_13[8];
 __IO  uint32_t OTA_START_ADDR_HIGH[FMC_OTA_START_ADDR_HIGH_COUNT]; /* OTA Start Address High Register, offset: 0x530 */
       uint8_t  RESERVED_14[8];
 __IO  uint32_t OTA_END_ADDR[FMC_OTA_END_ADDR_COUNT]; /* OTA End Address Register, offset: 0x53c */
       uint8_t  RESERVED_15[8];
 __IO  uint32_t OTA_END_ADDR_HIGH[FMC_OTA_END_ADDR_HIGH_COUNT]; /* OTA End Address High Register, offset: 0x548 */

} FMC_Type, *FMC_MemMapPtr;


/* FMC - Peripheral instance base addresses */
/** Peripheral FMC0 base address */
#define FMC0_BASE                                (0x4001e000u)
/** Peripheral FMC0 base pointer */
#define FMC0                                     ((FMC_Type *)FMC0_BASE)
/** Peripheral FMC1 base address */
#define FMC1_BASE                                (0x4001f000u)
/** Peripheral FMC1 base pointer */
#define FMC1                                     ((FMC_Type *)FMC1_BASE)
// need fill by yourself
///** Number of interrupt vector arrays for the FMC module. */
//#define FMC_IRQS_ARR_COUNT                       (1u)
///** Number of interrupt channels for the FMC module. */
//#define FMC_IRQS_CH_COUNT                        (1u)
///** Interrupt vectors for the FMC peripheral type */
//#define FMC_IRQS                                 {FMC0_IRQn, FMC1_IRQn}


/* ----------------------------------------------------------------------------
   -- FMC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FMC_Register_Masks FMC Register Masks
 * @{
 */

/* FAPC0 Bit Fields */
#define FMC_FAPC0_BF_DEDI_MASTER_MASK  0xF00u
#define FMC_FAPC0_BF_DEDI_MASTER_SHIFT 8u
#define FMC_FAPC0_BF_DEDI_MASTER_WIDTH 4u
#define FMC_FAPC0_BF_DEDI_MASTER(x)    (((uint32_t)(((uint32_t)(x))<<FMC_FAPC0_BF_DEDI_MASTER_SHIFT))&FMC_FAPC0_BF_DEDI_MASTER_MASK)
#define FMC_FAPC0_DBPEN_MASK           0x20u
#define FMC_FAPC0_DBPEN_SHIFT          5u
#define FMC_FAPC0_DBPEN_WIDTH          1u
#define FMC_FAPC0_DBPEN(x)             (((uint32_t)(((uint32_t)(x))<<FMC_FAPC0_DBPEN_SHIFT))&FMC_FAPC0_DBPEN_MASK)
#define FMC_FAPC0_CBPEN_MASK           0x10u
#define FMC_FAPC0_CBPEN_SHIFT          4u
#define FMC_FAPC0_CBPEN_WIDTH          1u
#define FMC_FAPC0_CBPEN(x)             (((uint32_t)(((uint32_t)(x))<<FMC_FAPC0_CBPEN_SHIFT))&FMC_FAPC0_CBPEN_MASK)
#define FMC_FAPC0_BF_DEDI_EN_MASK      0x4u
#define FMC_FAPC0_BF_DEDI_EN_SHIFT     2u
#define FMC_FAPC0_BF_DEDI_EN_WIDTH     1u
#define FMC_FAPC0_BF_DEDI_EN(x)        (((uint32_t)(((uint32_t)(x))<<FMC_FAPC0_BF_DEDI_EN_SHIFT))&FMC_FAPC0_BF_DEDI_EN_MASK)
#define FMC_FAPC0_DBBEN_MASK           0x2u
#define FMC_FAPC0_DBBEN_SHIFT          1u
#define FMC_FAPC0_DBBEN_WIDTH          1u
#define FMC_FAPC0_DBBEN(x)             (((uint32_t)(((uint32_t)(x))<<FMC_FAPC0_DBBEN_SHIFT))&FMC_FAPC0_DBBEN_MASK)
#define FMC_FAPC0_CBBEN_MASK           0x1u
#define FMC_FAPC0_CBBEN_SHIFT          0u
#define FMC_FAPC0_CBBEN_WIDTH          1u
#define FMC_FAPC0_CBBEN(x)             (((uint32_t)(((uint32_t)(x))<<FMC_FAPC0_CBBEN_SHIFT))&FMC_FAPC0_CBBEN_MASK)
/* FAPC0 Reg Mask */
#define FMC_FAPC0_MASK                 0x00000F37u

/* FAPC2 Bit Fields */
#define FMC_FAPC2_DBBEN_MASK           0x2u
#define FMC_FAPC2_DBBEN_SHIFT          1u
#define FMC_FAPC2_DBBEN_WIDTH          1u
#define FMC_FAPC2_DBBEN(x)             (((uint32_t)(((uint32_t)(x))<<FMC_FAPC2_DBBEN_SHIFT))&FMC_FAPC2_DBBEN_MASK)
#define FMC_FAPC2_CBBEN_MASK           0x1u
#define FMC_FAPC2_CBBEN_SHIFT          0u
#define FMC_FAPC2_CBBEN_WIDTH          1u
#define FMC_FAPC2_CBBEN(x)             (((uint32_t)(((uint32_t)(x))<<FMC_FAPC2_CBBEN_SHIFT))&FMC_FAPC2_CBBEN_MASK)
/* FAPC2 Reg Mask */
#define FMC_FAPC2_MASK                 0x00000003u

/* FEEC Bit Fields */
#define FMC_FEEC_EIE_SET_SEL_MASK      0xF000000u
#define FMC_FEEC_EIE_SET_SEL_SHIFT     24u
#define FMC_FEEC_EIE_SET_SEL_WIDTH     4u
#define FMC_FEEC_EIE_SET_SEL(x)        (((uint32_t)(((uint32_t)(x))<<FMC_FEEC_EIE_SET_SEL_SHIFT))&FMC_FEEC_EIE_SET_SEL_MASK)
#define FMC_FEEC_EIE_SET_MASK          0x2000u
#define FMC_FEEC_EIE_SET_SHIFT         13u
#define FMC_FEEC_EIE_SET_WIDTH         1u
#define FMC_FEEC_EIE_SET(x)            (((uint32_t)(((uint32_t)(x))<<FMC_FEEC_EIE_SET_SHIFT))&FMC_FEEC_EIE_SET_MASK)
#define FMC_FEEC_DDBEE_MASK            0x80u
#define FMC_FEEC_DDBEE_SHIFT           7u
#define FMC_FEEC_DDBEE_WIDTH           1u
#define FMC_FEEC_DDBEE(x)              (((uint32_t)(((uint32_t)(x))<<FMC_FEEC_DDBEE_SHIFT))&FMC_FEEC_DDBEE_MASK)
#define FMC_FEEC_DES_MASK              0x1u
#define FMC_FEEC_DES_SHIFT             0u
#define FMC_FEEC_DES_WIDTH             1u
#define FMC_FEEC_DES(x)                (((uint32_t)(((uint32_t)(x))<<FMC_FEEC_DES_SHIFT))&FMC_FEEC_DES_MASK)
/* FEEC Reg Mask */
#define FMC_FEEC_MASK                  0x0F002081u

/* FEINTC Bit Fields */
#define FMC_FEINTC_LOCK_MASK           0x80000000u
#define FMC_FEINTC_LOCK_SHIFT          31u
#define FMC_FEINTC_LOCK_WIDTH          1u
#define FMC_FEINTC_LOCK(x)             (((uint32_t)(((uint32_t)(x))<<FMC_FEINTC_LOCK_SHIFT))&FMC_FEINTC_LOCK_MASK)
#define FMC_FEINTC_PFLASH_ERROR_INT_EN_MASK 0x40000000u
#define FMC_FEINTC_PFLASH_ERROR_INT_EN_SHIFT 30u
#define FMC_FEINTC_PFLASH_ERROR_INT_EN_WIDTH 1u
#define FMC_FEINTC_PFLASH_ERROR_INT_EN(x) (((uint32_t)(((uint32_t)(x))<<FMC_FEINTC_PFLASH_ERROR_INT_EN_SHIFT))&FMC_FEINTC_PFLASH_ERROR_INT_EN_MASK)
#define FMC_FEINTC_ERR_INT_MERGE_HSM_MASK 0x100000u
#define FMC_FEINTC_ERR_INT_MERGE_HSM_SHIFT 20u
#define FMC_FEINTC_ERR_INT_MERGE_HSM_WIDTH 1u
#define FMC_FEINTC_ERR_INT_MERGE_HSM(x) (((uint32_t)(((uint32_t)(x))<<FMC_FEINTC_ERR_INT_MERGE_HSM_SHIFT))&FMC_FEINTC_ERR_INT_MERGE_HSM_MASK)
#define FMC_FEINTC_ERR_INT_MERGE_CPU1_MASK 0x20000u
#define FMC_FEINTC_ERR_INT_MERGE_CPU1_SHIFT 17u
#define FMC_FEINTC_ERR_INT_MERGE_CPU1_WIDTH 1u
#define FMC_FEINTC_ERR_INT_MERGE_CPU1(x) (((uint32_t)(((uint32_t)(x))<<FMC_FEINTC_ERR_INT_MERGE_CPU1_SHIFT))&FMC_FEINTC_ERR_INT_MERGE_CPU1_MASK)
#define FMC_FEINTC_ERR_INT_MERGE_CPU0_MASK 0x10000u
#define FMC_FEINTC_ERR_INT_MERGE_CPU0_SHIFT 16u
#define FMC_FEINTC_ERR_INT_MERGE_CPU0_WIDTH 1u
#define FMC_FEINTC_ERR_INT_MERGE_CPU0(x) (((uint32_t)(((uint32_t)(x))<<FMC_FEINTC_ERR_INT_MERGE_CPU0_SHIFT))&FMC_FEINTC_ERR_INT_MERGE_CPU0_MASK)
#define FMC_FEINTC_FC_INTE_HSM_MASK    0x1000u
#define FMC_FEINTC_FC_INTE_HSM_SHIFT   12u
#define FMC_FEINTC_FC_INTE_HSM_WIDTH   1u
#define FMC_FEINTC_FC_INTE_HSM(x)      (((uint32_t)(((uint32_t)(x))<<FMC_FEINTC_FC_INTE_HSM_SHIFT))&FMC_FEINTC_FC_INTE_HSM_MASK)
#define FMC_FEINTC_FC_INTE_CPU1_MASK   0x200u
#define FMC_FEINTC_FC_INTE_CPU1_SHIFT  9u
#define FMC_FEINTC_FC_INTE_CPU1_WIDTH  1u
#define FMC_FEINTC_FC_INTE_CPU1(x)     (((uint32_t)(((uint32_t)(x))<<FMC_FEINTC_FC_INTE_CPU1_SHIFT))&FMC_FEINTC_FC_INTE_CPU1_MASK)
#define FMC_FEINTC_FC_INTE_CPU0_MASK   0x100u
#define FMC_FEINTC_FC_INTE_CPU0_SHIFT  8u
#define FMC_FEINTC_FC_INTE_CPU0_WIDTH  1u
#define FMC_FEINTC_FC_INTE_CPU0(x)     (((uint32_t)(((uint32_t)(x))<<FMC_FEINTC_FC_INTE_CPU0_SHIFT))&FMC_FEINTC_FC_INTE_CPU0_MASK)
#define FMC_FEINTC_ERR_INTE_HSM_MASK   0x10u
#define FMC_FEINTC_ERR_INTE_HSM_SHIFT  4u
#define FMC_FEINTC_ERR_INTE_HSM_WIDTH  1u
#define FMC_FEINTC_ERR_INTE_HSM(x)     (((uint32_t)(((uint32_t)(x))<<FMC_FEINTC_ERR_INTE_HSM_SHIFT))&FMC_FEINTC_ERR_INTE_HSM_MASK)
#define FMC_FEINTC_ERR_INTE_CPU1_MASK  0x2u
#define FMC_FEINTC_ERR_INTE_CPU1_SHIFT 1u
#define FMC_FEINTC_ERR_INTE_CPU1_WIDTH 1u
#define FMC_FEINTC_ERR_INTE_CPU1(x)    (((uint32_t)(((uint32_t)(x))<<FMC_FEINTC_ERR_INTE_CPU1_SHIFT))&FMC_FEINTC_ERR_INTE_CPU1_MASK)
#define FMC_FEINTC_ERR_INTE_CPU0_MASK  0x1u
#define FMC_FEINTC_ERR_INTE_CPU0_SHIFT 0u
#define FMC_FEINTC_ERR_INTE_CPU0_WIDTH 1u
#define FMC_FEINTC_ERR_INTE_CPU0(x)    (((uint32_t)(((uint32_t)(x))<<FMC_FEINTC_ERR_INTE_CPU0_SHIFT))&FMC_FEINTC_ERR_INTE_CPU0_MASK)
/* FEINTC Reg Mask */
#define FMC_FEINTC_MASK                0xC0131313u

/* FEINT_CPU0 Bit Fields */
#define FMC_FEINT_CPU0_P2_ERR_INT_MASK 0x4u
#define FMC_FEINT_CPU0_P2_ERR_INT_SHIFT 2u
#define FMC_FEINT_CPU0_P2_ERR_INT_WIDTH 1u
#define FMC_FEINT_CPU0_P2_ERR_INT(x)   (((uint32_t)(((uint32_t)(x))<<FMC_FEINT_CPU0_P2_ERR_INT_SHIFT))&FMC_FEINT_CPU0_P2_ERR_INT_MASK)
#define FMC_FEINT_CPU0_P0_ERR_INT_MASK 0x1u
#define FMC_FEINT_CPU0_P0_ERR_INT_SHIFT 0u
#define FMC_FEINT_CPU0_P0_ERR_INT_WIDTH 1u
#define FMC_FEINT_CPU0_P0_ERR_INT(x)   (((uint32_t)(((uint32_t)(x))<<FMC_FEINT_CPU0_P0_ERR_INT_SHIFT))&FMC_FEINT_CPU0_P0_ERR_INT_MASK)
/* FEINT_CPU0 Reg Mask */
#define FMC_FEINT_CPU0_MASK            0x00000005u

/* FEINT_CPU1 Bit Fields */
#define FMC_FEINT_CPU1_P2_ERR_INT_MASK 0x4u
#define FMC_FEINT_CPU1_P2_ERR_INT_SHIFT 2u
#define FMC_FEINT_CPU1_P2_ERR_INT_WIDTH 1u
#define FMC_FEINT_CPU1_P2_ERR_INT(x)   (((uint32_t)(((uint32_t)(x))<<FMC_FEINT_CPU1_P2_ERR_INT_SHIFT))&FMC_FEINT_CPU1_P2_ERR_INT_MASK)
#define FMC_FEINT_CPU1_P0_ERR_INT_MASK 0x1u
#define FMC_FEINT_CPU1_P0_ERR_INT_SHIFT 0u
#define FMC_FEINT_CPU1_P0_ERR_INT_WIDTH 1u
#define FMC_FEINT_CPU1_P0_ERR_INT(x)   (((uint32_t)(((uint32_t)(x))<<FMC_FEINT_CPU1_P0_ERR_INT_SHIFT))&FMC_FEINT_CPU1_P0_ERR_INT_MASK)
/* FEINT_CPU1 Reg Mask */
#define FMC_FEINT_CPU1_MASK            0x00000005u

/* FEINT_HSM Bit Fields */
#define FMC_FEINT_HSM_P2_ERR_INT_MASK  0x4u
#define FMC_FEINT_HSM_P2_ERR_INT_SHIFT 2u
#define FMC_FEINT_HSM_P2_ERR_INT_WIDTH 1u
#define FMC_FEINT_HSM_P2_ERR_INT(x)    (((uint32_t)(((uint32_t)(x))<<FMC_FEINT_HSM_P2_ERR_INT_SHIFT))&FMC_FEINT_HSM_P2_ERR_INT_MASK)
#define FMC_FEINT_HSM_P1_ERR_INT_MASK  0x2u
#define FMC_FEINT_HSM_P1_ERR_INT_SHIFT 1u
#define FMC_FEINT_HSM_P1_ERR_INT_WIDTH 1u
#define FMC_FEINT_HSM_P1_ERR_INT(x)    (((uint32_t)(((uint32_t)(x))<<FMC_FEINT_HSM_P1_ERR_INT_SHIFT))&FMC_FEINT_HSM_P1_ERR_INT_MASK)
#define FMC_FEINT_HSM_P0_ERR_INT_MASK  0x1u
#define FMC_FEINT_HSM_P0_ERR_INT_SHIFT 0u
#define FMC_FEINT_HSM_P0_ERR_INT_WIDTH 1u
#define FMC_FEINT_HSM_P0_ERR_INT(x)    (((uint32_t)(((uint32_t)(x))<<FMC_FEINT_HSM_P0_ERR_INT_SHIFT))&FMC_FEINT_HSM_P0_ERR_INT_MASK)
/* FEINT_HSM Reg Mask */
#define FMC_FEINT_HSM_MASK             0x00000007u

/* LINEBUFC Bit Fields */
#define FMC_LINEBUFC_LB_INV_WHEN_ERR_MASK 0x1u
#define FMC_LINEBUFC_LB_INV_WHEN_ERR_SHIFT 0u
#define FMC_LINEBUFC_LB_INV_WHEN_ERR_WIDTH 1u
#define FMC_LINEBUFC_LB_INV_WHEN_ERR(x) (((uint32_t)(((uint32_t)(x))<<FMC_LINEBUFC_LB_INV_WHEN_ERR_SHIFT))&FMC_LINEBUFC_LB_INV_WHEN_ERR_MASK)
/* LINEBUFC Reg Mask */
#define FMC_LINEBUFC_MASK              0x00000001u

/* FEIDC_0 Bit Fields */
#define FMC_FEIDC_0_EDATA_INJECT_0_MASK 0xFFFFFFFFu
#define FMC_FEIDC_0_EDATA_INJECT_0_SHIFT 0u
#define FMC_FEIDC_0_EDATA_INJECT_0_WIDTH 32u
#define FMC_FEIDC_0_EDATA_INJECT_0(x)  (((uint32_t)(((uint32_t)(x))<<FMC_FEIDC_0_EDATA_INJECT_0_SHIFT))&FMC_FEIDC_0_EDATA_INJECT_0_MASK)
/* FEIDC_0 Reg Mask */
#define FMC_FEIDC_0_MASK               0xFFFFFFFFu

/* FEIDC_1 Bit Fields */
#define FMC_FEIDC_1_EDATA_INJECT_1_MASK 0xFFFFFFFFu
#define FMC_FEIDC_1_EDATA_INJECT_1_SHIFT 0u
#define FMC_FEIDC_1_EDATA_INJECT_1_WIDTH 32u
#define FMC_FEIDC_1_EDATA_INJECT_1(x)  (((uint32_t)(((uint32_t)(x))<<FMC_FEIDC_1_EDATA_INJECT_1_SHIFT))&FMC_FEIDC_1_EDATA_INJECT_1_MASK)
/* FEIDC_1 Reg Mask */
#define FMC_FEIDC_1_MASK               0xFFFFFFFFu

/* FEIDC_2 Bit Fields */
#define FMC_FEIDC_2_EDATA_INJECT_2_MASK 0xFFFFFFFFu
#define FMC_FEIDC_2_EDATA_INJECT_2_SHIFT 0u
#define FMC_FEIDC_2_EDATA_INJECT_2_WIDTH 32u
#define FMC_FEIDC_2_EDATA_INJECT_2(x)  (((uint32_t)(((uint32_t)(x))<<FMC_FEIDC_2_EDATA_INJECT_2_SHIFT))&FMC_FEIDC_2_EDATA_INJECT_2_MASK)
/* FEIDC_2 Reg Mask */
#define FMC_FEIDC_2_MASK               0xFFFFFFFFu

/* FEIDC_3 Bit Fields */
#define FMC_FEIDC_3_EDATA_INJECT_3_MASK 0xFFFFFFFFu
#define FMC_FEIDC_3_EDATA_INJECT_3_SHIFT 0u
#define FMC_FEIDC_3_EDATA_INJECT_3_WIDTH 32u
#define FMC_FEIDC_3_EDATA_INJECT_3(x)  (((uint32_t)(((uint32_t)(x))<<FMC_FEIDC_3_EDATA_INJECT_3_SHIFT))&FMC_FEIDC_3_EDATA_INJECT_3_MASK)
/* FEIDC_3 Reg Mask */
#define FMC_FEIDC_3_MASK               0xFFFFFFFFu

/* FEIDC_4 Bit Fields */
#define FMC_FEIDC_4_EDATA_INJECT_4_MASK 0x1FFFFFFu
#define FMC_FEIDC_4_EDATA_INJECT_4_SHIFT 0u
#define FMC_FEIDC_4_EDATA_INJECT_4_WIDTH 25u
#define FMC_FEIDC_4_EDATA_INJECT_4(x)  (((uint32_t)(((uint32_t)(x))<<FMC_FEIDC_4_EDATA_INJECT_4_SHIFT))&FMC_FEIDC_4_EDATA_INJECT_4_MASK)
/* FEIDC_4 Reg Mask */
#define FMC_FEIDC_4_MASK               0x01FFFFFFu

/* FEIEC Bit Fields */
#define FMC_FEIEC_EDATAC_INJECT_MASK   0x1FFu
#define FMC_FEIEC_EDATAC_INJECT_SHIFT  0u
#define FMC_FEIEC_EDATAC_INJECT_WIDTH  9u
#define FMC_FEIEC_EDATAC_INJECT(x)     (((uint32_t)(((uint32_t)(x))<<FMC_FEIEC_EDATAC_INJECT_SHIFT))&FMC_FEIEC_EDATAC_INJECT_MASK)
/* FEIEC Reg Mask */
#define FMC_FEIEC_MASK                 0x000001FFu

/* FPESA_L Bit Fields */
#define FMC_FPESA_L_PESA_L_MASK        0xFFFFFFFFu
#define FMC_FPESA_L_PESA_L_SHIFT       0u
#define FMC_FPESA_L_PESA_L_WIDTH       32u
#define FMC_FPESA_L_PESA_L(x)          (((uint32_t)(((uint32_t)(x))<<FMC_FPESA_L_PESA_L_SHIFT))&FMC_FPESA_L_PESA_L_MASK)
/* FPESA_L Reg Mask */
#define FMC_FPESA_L_MASK               0xFFFFFFFFu

/* FPESA_P Bit Fields */
#define FMC_FPESA_P_PESA_P_MASK        0xFFFFFFFFu
#define FMC_FPESA_P_PESA_P_SHIFT       0u
#define FMC_FPESA_P_PESA_P_WIDTH       32u
#define FMC_FPESA_P_PESA_P(x)          (((uint32_t)(((uint32_t)(x))<<FMC_FPESA_P_PESA_P_SHIFT))&FMC_FPESA_P_PESA_P_MASK)
/* FPESA_P Reg Mask */
#define FMC_FPESA_P_MASK               0xFFFFFFFFu

/* FB_FPELCK Bit Fields */
#define FMC_FB_FPELCK_FPELCK_MASK      0xFFFFFFFFu
#define FMC_FB_FPELCK_FPELCK_SHIFT     0u
#define FMC_FB_FPELCK_FPELCK_WIDTH     32u
#define FMC_FB_FPELCK_FPELCK(x)        (((uint32_t)(((uint32_t)(x))<<FMC_FB_FPELCK_FPELCK_SHIFT))&FMC_FB_FPELCK_FPELCK_MASK)
/* FB_FPELCK0 Reg Mask */
#define FMC_FB_FPELCK_MASK             0xFFFFFFFFu

/* FB_FPELCK8 Bit Fields */
#define FMC_FB_FPELCK8_FPELCK_MASK     0xFFFFFFFFu
#define FMC_FB_FPELCK8_FPELCK_SHIFT    0u
#define FMC_FB_FPELCK8_FPELCK_WIDTH    32u
#define FMC_FB_FPELCK8_FPELCK(x)       (((uint32_t)(((uint32_t)(x))<<FMC_FB_FPELCK8_FPELCK_SHIFT))&FMC_FB_FPELCK8_FPELCK_MASK)
/* FB_FPELCK8 Reg Mask */
#define FMC_FB_FPELCK8_MASK            0xFFFFFFFFu

/* FB_FPELCK9 Bit Fields */
#define FMC_FB_FPELCK9_FPELCK_MASK     0xFFFFFFFFu
#define FMC_FB_FPELCK9_FPELCK_SHIFT    0u
#define FMC_FB_FPELCK9_FPELCK_WIDTH    32u
#define FMC_FB_FPELCK9_FPELCK(x)       (((uint32_t)(((uint32_t)(x))<<FMC_FB_FPELCK9_FPELCK_SHIFT))&FMC_FB_FPELCK9_FPELCK_MASK)
/* FB_FPELCK9 Reg Mask */
#define FMC_FB_FPELCK9_MASK            0xFFFFFFFFu

/* FN_FPELCK Bit Fields */
#define FMC_FN_FPELCK_FPELCK_MASK      0x1u
#define FMC_FN_FPELCK_FPELCK_SHIFT     0u
#define FMC_FN_FPELCK_FPELCK_WIDTH     1u
#define FMC_FN_FPELCK_FPELCK(x)        (((uint32_t)(((uint32_t)(x))<<FMC_FN_FPELCK_FPELCK_SHIFT))&FMC_FN_FPELCK_FPELCK_MASK)
/* FN_FPELCK Reg Mask */
#define FMC_FN_FPELCK_MASK             0x00000001u

/* FB_CPELCK Bit Fields */
#define FMC_FB_CPELCK_CPELCK_MASK      0xFFFFFFFFu
#define FMC_FB_CPELCK_CPELCK_SHIFT     0u
#define FMC_FB_CPELCK_CPELCK_WIDTH     32u
#define FMC_FB_CPELCK_CPELCK(x)        (((uint32_t)(((uint32_t)(x))<<FMC_FB_CPELCK_CPELCK_SHIFT))&FMC_FB_CPELCK_CPELCK_MASK)
/* FB_CPELCK0 Reg Mask */
#define FMC_FB_CPELCK_MASK             0xFFFFFFFFu

/* OTA_CTRL Bit Fields */
#define FMC_OTA_CTRL_OTA_LOCK_MASK     0x40u
#define FMC_OTA_CTRL_OTA_LOCK_SHIFT    6u
#define FMC_OTA_CTRL_OTA_LOCK_WIDTH    1u
#define FMC_OTA_CTRL_OTA_LOCK(x)       (((uint32_t)(((uint32_t)(x))<<FMC_OTA_CTRL_OTA_LOCK_SHIFT))&FMC_OTA_CTRL_OTA_LOCK_MASK)
#define FMC_OTA_CTRL_OTA_ACTIVE_MASK   0x20u
#define FMC_OTA_CTRL_OTA_ACTIVE_SHIFT  5u
#define FMC_OTA_CTRL_OTA_ACTIVE_WIDTH  1u
#define FMC_OTA_CTRL_OTA_ACTIVE(x)     (((uint32_t)(((uint32_t)(x))<<FMC_OTA_CTRL_OTA_ACTIVE_SHIFT))&FMC_OTA_CTRL_OTA_ACTIVE_MASK)
#define FMC_OTA_CTRL_OTA_EN_MASK       0x1Fu
#define FMC_OTA_CTRL_OTA_EN_SHIFT      0u
#define FMC_OTA_CTRL_OTA_EN_WIDTH      5u
#define FMC_OTA_CTRL_OTA_EN(x)         (((uint32_t)(((uint32_t)(x))<<FMC_OTA_CTRL_OTA_EN_SHIFT))&FMC_OTA_CTRL_OTA_EN_MASK)
/* OTA_CTRL0 Reg Mask */
#define FMC_OTA_CTRL_MASK              0x0000007Fu

/* OTA_START_ADDR Bit Fields */
#define FMC_OTA_START_ADDR_OTA_START_ADDR_MASK 0xFE000u
#define FMC_OTA_START_ADDR_OTA_START_ADDR_SHIFT 13u
#define FMC_OTA_START_ADDR_OTA_START_ADDR_WIDTH 7u
#define FMC_OTA_START_ADDR_OTA_START_ADDR(x) (((uint32_t)(((uint32_t)(x))<<FMC_OTA_START_ADDR_OTA_START_ADDR_SHIFT))&FMC_OTA_START_ADDR_OTA_START_ADDR_MASK)
/* OTA_START_ADDR0 Reg Mask */
#define FMC_OTA_START_ADDR_MASK        0x000FE000u

/* OTA_START_ADDR_HIGH Bit Fields */
#define FMC_OTA_START_ADDR_HIGH_OTA_START_ADDR_MASK 0xFE000u
#define FMC_OTA_START_ADDR_HIGH_OTA_START_ADDR_SHIFT 13u
#define FMC_OTA_START_ADDR_HIGH_OTA_START_ADDR_WIDTH 7u
#define FMC_OTA_START_ADDR_HIGH_OTA_START_ADDR(x) (((uint32_t)(((uint32_t)(x))<<FMC_OTA_START_ADDR_HIGH_OTA_START_ADDR_SHIFT))&FMC_OTA_START_ADDR_HIGH_OTA_START_ADDR_MASK)
/* OTA_START_ADDR_HIGH0 Reg Mask */
#define FMC_OTA_START_ADDR_HIGH_MASK   0x000FE000u

/* OTA_END_ADDR Bit Fields */
#define FMC_OTA_END_ADDR_OTA_END_ADDR_MASK 0xFE000u
#define FMC_OTA_END_ADDR_OTA_END_ADDR_SHIFT 13u
#define FMC_OTA_END_ADDR_OTA_END_ADDR_WIDTH 7u
#define FMC_OTA_END_ADDR_OTA_END_ADDR(x) (((uint32_t)(((uint32_t)(x))<<FMC_OTA_END_ADDR_OTA_END_ADDR_SHIFT))&FMC_OTA_END_ADDR_OTA_END_ADDR_MASK)
/* OTA_END_ADDR0 Reg Mask */
#define FMC_OTA_END_ADDR_MASK          0x000FE000u

/* OTA_END_ADDR_HIGH Bit Fields */
#define FMC_OTA_END_ADDR_HIGH_OTA_END_ADDR_MASK 0xFE000u
#define FMC_OTA_END_ADDR_HIGH_OTA_END_ADDR_SHIFT 13u
#define FMC_OTA_END_ADDR_HIGH_OTA_END_ADDR_WIDTH 7u
#define FMC_OTA_END_ADDR_HIGH_OTA_END_ADDR(x) (((uint32_t)(((uint32_t)(x))<<FMC_OTA_END_ADDR_HIGH_OTA_END_ADDR_SHIFT))&FMC_OTA_END_ADDR_HIGH_OTA_END_ADDR_MASK)
/* OTA_END_ADDR_HIGH0 Reg Mask */
#define FMC_OTA_END_ADDR_HIGH_MASK     0x000FE000u

/* OTA_VER_LOC Bit Fields */
#define FMC_OTA_VER_LOC_OTA_VER_LOC_MASK 0xFFFFFu
#define FMC_OTA_VER_LOC_OTA_VER_LOC_SHIFT 0u
#define FMC_OTA_VER_LOC_OTA_VER_LOC_WIDTH 20u
#define FMC_OTA_VER_LOC_OTA_VER_LOC(x) (((uint32_t)(((uint32_t)(x))<<FMC_OTA_VER_LOC_OTA_VER_LOC_SHIFT))&FMC_OTA_VER_LOC_OTA_VER_LOC_MASK)
/* OTA_VER_LOC0 Reg Mask */
#define FMC_OTA_VER_LOC_MASK           0x000FFFFFu

/* OTA_ACT_VER Bit Fields */
#define FMC_OTA_ACT_VER_OTA_ACT_VER_MASK 0xFFFFFFFFu
#define FMC_OTA_ACT_VER_OTA_ACT_VER_SHIFT 0u
#define FMC_OTA_ACT_VER_OTA_ACT_VER_WIDTH 32u
#define FMC_OTA_ACT_VER_OTA_ACT_VER(x) (((uint32_t)(((uint32_t)(x))<<FMC_OTA_ACT_VER_OTA_ACT_VER_SHIFT))&FMC_OTA_ACT_VER_OTA_ACT_VER_MASK)
/* OTA_ACT_VER0 Reg Mask */
#define FMC_OTA_ACT_VER_MASK           0xFFFFFFFFu


/*!
 * @}
 */ /* end of group FMC_Register_Masks */

/*!
 * @}
 */ /* end of group FMC_Peripheral_Access_Layer */

#endif
