#ifndef _MODULE_FMC_gmbhdijq262_REGS_H_FMC_H_
#define _MODULE_FMC_gmbhdijq262_REGS_H_FMC_H_

/* ----------------------------------------------------------------------------
   -- FMC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FMC_Peripheral_Access_Layer FMC Peripheral Access Layer
 * @{
 */

/** FMC - Size of Registers Arrays */

/** FMC - Register Layout Typedef */
#define FMC_FB_FPELCK_COUNT 5
#define FMC_FB_CPELCK_COUNT 4
#define FMC_FB_SETFLCK_COUNT 5
#define FMC_FB_SETCLCK_COUNT 5
#define FMC_FB0_FLCKM_COUNT 8
#define FMC_FB1_FLCKM_COUNT 8
#define FMC_FB2_FLCKM_COUNT 8
#define FMC_FB3_FLCKM_COUNT 8
#define FMC_FB4_FLCKM_COUNT 8
#define FMC_FB0_CLCKM_COUNT 3
#define FMC_FB1_CLCKM_COUNT 3
#define FMC_FB2_CLCKM_COUNT 3
#define FMC_FB3_CLCKM_COUNT 3
#define FMC_OTA_CTRL_COUNT 2
#define FMC_OTA_VER_LOC_COUNT 2
#define FMC_OTA_ACT_VER_COUNT 2

typedef struct {

  __IO uint32_t FAPC0                         ; /* Flash Access Port Control Register0, offset: 0x0 */
  __IO uint32_t FAPC1                         ; /* Flash Access Port Control Register1, offset: 0x4 */
  __IO uint32_t FAPC2                         ; /* Flash Access Port Control Register2, offset: 0x8 */
       uint8_t  RESERVED_0[4];
  __IO uint32_t FEEC                          ; /* Flash ECC Error Control Register, offset: 0x10 */
       uint8_t  RESERVED_1[4];
  __IO uint32_t FEIPC                         ; /* Flash ECC Inject Position Control Register, offset: 0x18 */
       uint8_t  RESERVED_2[740];
  __IO uint32_t FPESA_L                       ; /* Flash Program Erase Start Address Logical Register, offset: 0x300 */
  __I  uint32_t FPESA_P                       ; /* Flash Program Erase Start Address Physical Register, offset: 0x304 */
       uint8_t  RESERVED_3[56];
  __IO uint32_t FB_FPELCK[FMC_FB_FPELCK_COUNT]; /* Flash Block n Fine Program Erase Lock Register, offset: 0x340 */
       uint8_t  RESERVED_4[4];
  __IO uint32_t FN_FPELCK                     ; /* Flash NVR Fine Program Erase Lock Register, offset: 0x358 */
  __IO uint32_t FB_CPELCK[FMC_FB_CPELCK_COUNT]; /* Flash Block n Coarse Program Erase Lock Register, offset: 0x35c */
       uint8_t  RESERVED_5[20];
  __IO uint32_t FB_SETFLCK[FMC_FB_SETFLCK_COUNT]; /* Flash Block n Set Fine Lock Register, offset: 0x380 */
       uint8_t  RESERVED_6[4];
  __IO uint32_t FN_SETFLCK                    ; /* FLASH NVR Set Fine Lock Register, offset: 0x398 */
  __IO uint32_t FB_SETCLCK[FMC_FB_SETCLCK_COUNT]; /* Flash Block n Set Super Sector Lock, offset: 0x39c */
       uint8_t  RESERVED_7[16];
  __I  uint32_t FB0_FLCKM[FMC_FB0_FLCKM_COUNT]; /* FLASH Block0 Fine Lock Master Register, offset: 0x3c0 */
  __I  uint32_t FB1_FLCKM[FMC_FB1_FLCKM_COUNT]; /* FLASH Block1 Fine Lock Master Register, offset: 0x3e0 */
  __I  uint32_t FB2_FLCKM[FMC_FB2_FLCKM_COUNT]; /* FLASH Block2 Fine Lock Master Register, offset: 0x400 */
  __I  uint32_t FB3_FLCKM[FMC_FB3_FLCKM_COUNT]; /* FLASH Block3 Fine Lock Master Register, offset: 0x420 */
  __I  uint32_t FB4_FLCKM[FMC_FB4_FLCKM_COUNT]; /* FLASH Block4 Fine Lock Master Register, offset: 0x440 */
       uint8_t  RESERVED_8[32];
  __I  uint32_t FN_FLCKM                      ; /* FLASH NVR Fine Lock Master Register, offset: 0x480 */
  __I  uint32_t FB0_CLCKM[FMC_FB0_CLCKM_COUNT]; /* FLASH Block0 Coarse Lock Master Register, offset: 0x484 */
       uint8_t  RESERVED_9[4];
  __I  uint32_t FB1_CLCKM[FMC_FB1_CLCKM_COUNT]; /* FLASH Block1 Coarse Lock Master Register, offset: 0x494 */
       uint8_t  RESERVED_10[4];
  __I  uint32_t FB2_CLCKM[FMC_FB2_CLCKM_COUNT]; /* FLASH Block2 Coarse Lock Master Register, offset: 0x4a4 */
       uint8_t  RESERVED_11[4];
  __I  uint32_t FB3_CLCKM[FMC_FB3_CLCKM_COUNT]; /* FLASH Block3 Coarse Lock Master Register, offset: 0x4b4 */
       uint8_t  RESERVED_12[64];
  __IO uint32_t OTA_CTRL[FMC_OTA_CTRL_COUNT]  ; /* OTA Control Register, offset: 0x500 */
  __I  uint32_t OTA_VER_LOC[FMC_OTA_VER_LOC_COUNT]; /* OTA Version Location Register, offset: 0x508 */
  __I  uint32_t OTA_ACT_VER[FMC_OTA_ACT_VER_COUNT]; /* OTA Active Version Register, offset: 0x510 */

} FMC_Type, *FMC_MemMapPtr;


/* FMC - Peripheral instance base addresses */
/** Peripheral FMC base address */
#define FMC0_BASE                                 (0x4001e000u)
/** Peripheral FMC base pointer */
#define FMC0                                      ((FMC_Type *)FMC0_BASE)  
// need fill by yourself
///** Number of interrupt vector arrays for the FMC module. */
//#define FMC_IRQS_ARR_COUNT                       (1u)
///** Number of interrupt channels for the FMC module. */
//#define FMC_IRQS_CH_COUNT                        (1u)
///** Interrupt vectors for the FMC peripheral type */
//#define FMC_IRQS                                 {FMC_IRQn}


/* ----------------------------------------------------------------------------
   -- FMC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FMC_Register_Masks FMC Register Masks
 * @{
 */

/* FAPC0 Bit Fields */
#define FMC_FAPC0_DBPEN_MASK           0x20u
#define FMC_FAPC0_DBPEN_SHIFT          5u
#define FMC_FAPC0_DBPEN_WIDTH          1u
#define FMC_FAPC0_DBPEN(x)             (((uint32_t)(((uint32_t)(x))<<FMC_FAPC0_DBPEN_SHIFT))&FMC_FAPC0_DBPEN_MASK)
#define FMC_FAPC0_CBPEN_MASK           0x10u
#define FMC_FAPC0_CBPEN_SHIFT          4u
#define FMC_FAPC0_CBPEN_WIDTH          1u
#define FMC_FAPC0_CBPEN(x)             (((uint32_t)(((uint32_t)(x))<<FMC_FAPC0_CBPEN_SHIFT))&FMC_FAPC0_CBPEN_MASK)
#define FMC_FAPC0_DBBEN_MASK           0x2u
#define FMC_FAPC0_DBBEN_SHIFT          1u
#define FMC_FAPC0_DBBEN_WIDTH          1u
#define FMC_FAPC0_DBBEN(x)             (((uint32_t)(((uint32_t)(x))<<FMC_FAPC0_DBBEN_SHIFT))&FMC_FAPC0_DBBEN_MASK)
#define FMC_FAPC0_CBBEN_MASK           0x1u
#define FMC_FAPC0_CBBEN_SHIFT          0u
#define FMC_FAPC0_CBBEN_WIDTH          1u
#define FMC_FAPC0_CBBEN(x)             (((uint32_t)(((uint32_t)(x))<<FMC_FAPC0_CBBEN_SHIFT))&FMC_FAPC0_CBBEN_MASK)
/* FAPC0 Reg Mask */
#define FMC_FAPC0_MASK                 0x00000033u

/* FAPC1 Bit Fields */
#define FMC_FAPC1_DBPEN_MASK           0x20u
#define FMC_FAPC1_DBPEN_SHIFT          5u
#define FMC_FAPC1_DBPEN_WIDTH          1u
#define FMC_FAPC1_DBPEN(x)             (((uint32_t)(((uint32_t)(x))<<FMC_FAPC1_DBPEN_SHIFT))&FMC_FAPC1_DBPEN_MASK)
#define FMC_FAPC1_CBPEN_MASK           0x10u
#define FMC_FAPC1_CBPEN_SHIFT          4u
#define FMC_FAPC1_CBPEN_WIDTH          1u
#define FMC_FAPC1_CBPEN(x)             (((uint32_t)(((uint32_t)(x))<<FMC_FAPC1_CBPEN_SHIFT))&FMC_FAPC1_CBPEN_MASK)
#define FMC_FAPC1_DBBEN_MASK           0x2u
#define FMC_FAPC1_DBBEN_SHIFT          1u
#define FMC_FAPC1_DBBEN_WIDTH          1u
#define FMC_FAPC1_DBBEN(x)             (((uint32_t)(((uint32_t)(x))<<FMC_FAPC1_DBBEN_SHIFT))&FMC_FAPC1_DBBEN_MASK)
#define FMC_FAPC1_CBBEN_MASK           0x1u
#define FMC_FAPC1_CBBEN_SHIFT          0u
#define FMC_FAPC1_CBBEN_WIDTH          1u
#define FMC_FAPC1_CBBEN(x)             (((uint32_t)(((uint32_t)(x))<<FMC_FAPC1_CBBEN_SHIFT))&FMC_FAPC1_CBBEN_MASK)
/* FAPC1 Reg Mask */
#define FMC_FAPC1_MASK                 0x00000033u

/* FAPC2 Bit Fields */
#define FMC_FAPC2_DBPEN_MASK           0x20u
#define FMC_FAPC2_DBPEN_SHIFT          5u
#define FMC_FAPC2_DBPEN_WIDTH          1u
#define FMC_FAPC2_DBPEN(x)             (((uint32_t)(((uint32_t)(x))<<FMC_FAPC2_DBPEN_SHIFT))&FMC_FAPC2_DBPEN_MASK)
#define FMC_FAPC2_CBPEN_MASK           0x10u
#define FMC_FAPC2_CBPEN_SHIFT          4u
#define FMC_FAPC2_CBPEN_WIDTH          1u
#define FMC_FAPC2_CBPEN(x)             (((uint32_t)(((uint32_t)(x))<<FMC_FAPC2_CBPEN_SHIFT))&FMC_FAPC2_CBPEN_MASK)
#define FMC_FAPC2_DBBEN_MASK           0x2u
#define FMC_FAPC2_DBBEN_SHIFT          1u
#define FMC_FAPC2_DBBEN_WIDTH          1u
#define FMC_FAPC2_DBBEN(x)             (((uint32_t)(((uint32_t)(x))<<FMC_FAPC2_DBBEN_SHIFT))&FMC_FAPC2_DBBEN_MASK)
#define FMC_FAPC2_CBBEN_MASK           0x1u
#define FMC_FAPC2_CBBEN_SHIFT          0u
#define FMC_FAPC2_CBBEN_WIDTH          1u
#define FMC_FAPC2_CBBEN(x)             (((uint32_t)(((uint32_t)(x))<<FMC_FAPC2_CBBEN_SHIFT))&FMC_FAPC2_CBBEN_MASK)
/* FAPC2 Reg Mask */
#define FMC_FAPC2_MASK                 0x00000033u

/* FEEC Bit Fields */
#define FMC_FEEC_CEIE_SET_MASK         0xF0000000u
#define FMC_FEEC_CEIE_SET_SHIFT        28u
#define FMC_FEEC_CEIE_SET_WIDTH        4u
#define FMC_FEEC_CEIE_SET(x)           (((uint32_t)(((uint32_t)(x))<<FMC_FEEC_CEIE_SET_SHIFT))&FMC_FEEC_CEIE_SET_MASK)
#define FMC_FEEC_EIE_SET_MASK          0xF000000u
#define FMC_FEEC_EIE_SET_SHIFT         24u
#define FMC_FEEC_EIE_SET_WIDTH         4u
#define FMC_FEEC_EIE_SET(x)            (((uint32_t)(((uint32_t)(x))<<FMC_FEEC_EIE_SET_SHIFT))&FMC_FEEC_EIE_SET_MASK)
#define FMC_FEEC_EDATAC_POS2_MASK      0xF00000u
#define FMC_FEEC_EDATAC_POS2_SHIFT     20u
#define FMC_FEEC_EDATAC_POS2_WIDTH     4u
#define FMC_FEEC_EDATAC_POS2(x)        (((uint32_t)(((uint32_t)(x))<<FMC_FEEC_EDATAC_POS2_SHIFT))&FMC_FEEC_EDATAC_POS2_MASK)
#define FMC_FEEC_EDATAC_POS1_MASK      0xF0000u
#define FMC_FEEC_EDATAC_POS1_SHIFT     16u
#define FMC_FEEC_EDATAC_POS1_WIDTH     4u
#define FMC_FEEC_EDATAC_POS1(x)        (((uint32_t)(((uint32_t)(x))<<FMC_FEEC_EDATAC_POS1_SHIFT))&FMC_FEEC_EDATAC_POS1_MASK)
#define FMC_FEEC_DDBEE_MASK            0x80u
#define FMC_FEEC_DDBEE_SHIFT           7u
#define FMC_FEEC_DDBEE_WIDTH           1u
#define FMC_FEEC_DDBEE(x)              (((uint32_t)(((uint32_t)(x))<<FMC_FEEC_DDBEE_SHIFT))&FMC_FEEC_DDBEE_MASK)
#define FMC_FEEC_DES_MASK              0x1u
#define FMC_FEEC_DES_SHIFT             0u
#define FMC_FEEC_DES_WIDTH             1u
#define FMC_FEEC_DES(x)                (((uint32_t)(((uint32_t)(x))<<FMC_FEEC_DES_SHIFT))&FMC_FEEC_DES_MASK)
/* FEEC Reg Mask */
#define FMC_FEEC_MASK                  0xFFFF0081u

/* FEIPC Bit Fields */
#define FMC_FEIPC_EDATA_POS1_MASK      0x1FFu
#define FMC_FEIPC_EDATA_POS1_SHIFT     0u
#define FMC_FEIPC_EDATA_POS1_WIDTH     9u
#define FMC_FEIPC_EDATA_POS1(x)        (((uint32_t)(((uint32_t)(x))<<FMC_FEIPC_EDATA_POS1_SHIFT))&FMC_FEIPC_EDATA_POS1_MASK)
#define FMC_FEIPC_EDATA_POS2_MASK      0x1FF0000u
#define FMC_FEIPC_EDATA_POS2_SHIFT     16u
#define FMC_FEIPC_EDATA_POS2_WIDTH     9u
#define FMC_FEIPC_EDATA_POS2(x)        (((uint32_t)(((uint32_t)(x))<<FMC_FEIPC_EDATA_POS2_SHIFT))&FMC_FEIPC_EDATA_POS2_MASK)
/* FEIPC Reg Mask */
#define FMC_FEIPC_MASK                 0x01FF01FFu

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

/* FB_SETFLCK Bit Fields */
#define FMC_FB_SETFLCK_SETFLCK_MASK    0xFFFFFFFFu
#define FMC_FB_SETFLCK_SETFLCK_SHIFT   0u
#define FMC_FB_SETFLCK_SETFLCK_WIDTH   32u
#define FMC_FB_SETFLCK_SETFLCK(x)      (((uint32_t)(((uint32_t)(x))<<FMC_FB_SETFLCK_SETFLCK_SHIFT))&FMC_FB_SETFLCK_SETFLCK_MASK)
/* FB_SETFLCK0 Reg Mask */
#define FMC_FB_SETFLCK_MASK            0xFFFFFFFFu

/* FN_SETFLCK Bit Fields */
#define FMC_FN_SETFLCK_SETFLCK_MASK    0x1u
#define FMC_FN_SETFLCK_SETFLCK_SHIFT   0u
#define FMC_FN_SETFLCK_SETFLCK_WIDTH   1u
#define FMC_FN_SETFLCK_SETFLCK(x)      (((uint32_t)(((uint32_t)(x))<<FMC_FN_SETFLCK_SETFLCK_SHIFT))&FMC_FN_SETFLCK_SETFLCK_MASK)
/* FN_SETFLCK Reg Mask */
#define FMC_FN_SETFLCK_MASK            0x00000001u

/* FB_SETCLCK Bit Fields */
#define FMC_FB_SETCLCK_SETCLCK_MASK    0xFFFFFFFFu
#define FMC_FB_SETCLCK_SETCLCK_SHIFT   0u
#define FMC_FB_SETCLCK_SETCLCK_WIDTH   32u
#define FMC_FB_SETCLCK_SETCLCK(x)      (((uint32_t)(((uint32_t)(x))<<FMC_FB_SETCLCK_SETCLCK_SHIFT))&FMC_FB_SETCLCK_SETCLCK_MASK)
/* FB_SETCLCK0 Reg Mask */
#define FMC_FB_SETCLCK_MASK            0xFFFFFFFFu

/* FB0_FLCKM Bit Fields */
#define FMC_FB0_FLCKM_FLCKM_MASK       0xFFFFFFFFu
#define FMC_FB0_FLCKM_FLCKM_SHIFT      0u
#define FMC_FB0_FLCKM_FLCKM_WIDTH      32u
#define FMC_FB0_FLCKM_FLCKM(x)         (((uint32_t)(((uint32_t)(x))<<FMC_FB0_FLCKM_FLCKM_SHIFT))&FMC_FB0_FLCKM_FLCKM_MASK)
/* FB0_FLCKM0 Reg Mask */
#define FMC_FB0_FLCKM_MASK             0xFFFFFFFFu

/* FB1_FLCKM Bit Fields */
#define FMC_FB1_FLCKM_FLCKM_MASK       0xFFFFFFFFu
#define FMC_FB1_FLCKM_FLCKM_SHIFT      0u
#define FMC_FB1_FLCKM_FLCKM_WIDTH      32u
#define FMC_FB1_FLCKM_FLCKM(x)         (((uint32_t)(((uint32_t)(x))<<FMC_FB1_FLCKM_FLCKM_SHIFT))&FMC_FB1_FLCKM_FLCKM_MASK)
/* FB1_FLCKM0 Reg Mask */
#define FMC_FB1_FLCKM_MASK             0xFFFFFFFFu

/* FB2_FLCKM Bit Fields */
#define FMC_FB2_FLCKM_FLCKM_MASK       0xFFFFFFFFu
#define FMC_FB2_FLCKM_FLCKM_SHIFT      0u
#define FMC_FB2_FLCKM_FLCKM_WIDTH      32u
#define FMC_FB2_FLCKM_FLCKM(x)         (((uint32_t)(((uint32_t)(x))<<FMC_FB2_FLCKM_FLCKM_SHIFT))&FMC_FB2_FLCKM_FLCKM_MASK)
/* FB2_FLCKM0 Reg Mask */
#define FMC_FB2_FLCKM_MASK             0xFFFFFFFFu

/* FB3_FLCKM Bit Fields */
#define FMC_FB3_FLCKM_FLCKM_MASK       0xFFFFFFFFu
#define FMC_FB3_FLCKM_FLCKM_SHIFT      0u
#define FMC_FB3_FLCKM_FLCKM_WIDTH      32u
#define FMC_FB3_FLCKM_FLCKM(x)         (((uint32_t)(((uint32_t)(x))<<FMC_FB3_FLCKM_FLCKM_SHIFT))&FMC_FB3_FLCKM_FLCKM_MASK)
/* FB3_FLCKM0 Reg Mask */
#define FMC_FB3_FLCKM_MASK             0xFFFFFFFFu

/* FB4_FLCKM Bit Fields */
#define FMC_FB4_FLCKM_FLCKM_MASK       0xFFFFFFFFu
#define FMC_FB4_FLCKM_FLCKM_SHIFT      0u
#define FMC_FB4_FLCKM_FLCKM_WIDTH      32u
#define FMC_FB4_FLCKM_FLCKM(x)         (((uint32_t)(((uint32_t)(x))<<FMC_FB4_FLCKM_FLCKM_SHIFT))&FMC_FB4_FLCKM_FLCKM_MASK)
/* FB4_FLCKM0 Reg Mask */
#define FMC_FB4_FLCKM_MASK             0xFFFFFFFFu

/* FN_FLCKM Bit Fields */
#define FMC_FN_FLCKM_FLCKM_MASK        0xFFu
#define FMC_FN_FLCKM_FLCKM_SHIFT       0u
#define FMC_FN_FLCKM_FLCKM_WIDTH       8u
#define FMC_FN_FLCKM_FLCKM(x)          (((uint32_t)(((uint32_t)(x))<<FMC_FN_FLCKM_FLCKM_SHIFT))&FMC_FN_FLCKM_FLCKM_MASK)
/* FN_FLCKM Reg Mask */
#define FMC_FN_FLCKM_MASK              0x000000FFu

/* FB0_CLCKM Bit Fields */
#define FMC_FB0_CLCKM_CLCKM_MASK       0xFFFFFFFFu
#define FMC_FB0_CLCKM_CLCKM_SHIFT      0u
#define FMC_FB0_CLCKM_CLCKM_WIDTH      32u
#define FMC_FB0_CLCKM_CLCKM(x)         (((uint32_t)(((uint32_t)(x))<<FMC_FB0_CLCKM_CLCKM_SHIFT))&FMC_FB0_CLCKM_CLCKM_MASK)
/* FB0_CLCKM0 Reg Mask */
#define FMC_FB0_CLCKM_MASK             0xFFFFFFFFu

/* FB1_CLCKM Bit Fields */
#define FMC_FB1_CLCKM_CLCKM_MASK       0xFFFFFFFFu
#define FMC_FB1_CLCKM_CLCKM_SHIFT      0u
#define FMC_FB1_CLCKM_CLCKM_WIDTH      32u
#define FMC_FB1_CLCKM_CLCKM(x)         (((uint32_t)(((uint32_t)(x))<<FMC_FB1_CLCKM_CLCKM_SHIFT))&FMC_FB1_CLCKM_CLCKM_MASK)
/* FB1_CLCKM0 Reg Mask */
#define FMC_FB1_CLCKM_MASK             0xFFFFFFFFu

/* FB2_CLCKM Bit Fields */
#define FMC_FB2_CLCKM_CLCKM_MASK       0xFFFFFFFFu
#define FMC_FB2_CLCKM_CLCKM_SHIFT      0u
#define FMC_FB2_CLCKM_CLCKM_WIDTH      32u
#define FMC_FB2_CLCKM_CLCKM(x)         (((uint32_t)(((uint32_t)(x))<<FMC_FB2_CLCKM_CLCKM_SHIFT))&FMC_FB2_CLCKM_CLCKM_MASK)
/* FB2_CLCKM0 Reg Mask */
#define FMC_FB2_CLCKM_MASK             0xFFFFFFFFu

/* FB3_CLCKM Bit Fields */
#define FMC_FB3_CLCKM_CLCKM_MASK       0xFFFFFFFFu
#define FMC_FB3_CLCKM_CLCKM_SHIFT      0u
#define FMC_FB3_CLCKM_CLCKM_WIDTH      32u
#define FMC_FB3_CLCKM_CLCKM(x)         (((uint32_t)(((uint32_t)(x))<<FMC_FB3_CLCKM_CLCKM_SHIFT))&FMC_FB3_CLCKM_CLCKM_MASK)
/* FB3_CLCKM0 Reg Mask */
#define FMC_FB3_CLCKM_MASK             0xFFFFFFFFu

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

/* OTA_VER_LOC Bit Fields */
#define FMC_OTA_VER_LOC_OTA_VER_LOC_MASK 0x3FFFFFu
#define FMC_OTA_VER_LOC_OTA_VER_LOC_SHIFT 0u
#define FMC_OTA_VER_LOC_OTA_VER_LOC_WIDTH 22u
#define FMC_OTA_VER_LOC_OTA_VER_LOC(x) (((uint32_t)(((uint32_t)(x))<<FMC_OTA_VER_LOC_OTA_VER_LOC_SHIFT))&FMC_OTA_VER_LOC_OTA_VER_LOC_MASK)
/* OTA_VER_LOC0 Reg Mask */
#define FMC_OTA_VER_LOC_MASK           0x003FFFFFu

/* OTA_ACT_VER Bit Fields */
#define FMC_OTA_ACT_VER_OTA_ACT_VER_MASK 0xFFFFu
#define FMC_OTA_ACT_VER_OTA_ACT_VER_SHIFT 0u
#define FMC_OTA_ACT_VER_OTA_ACT_VER_WIDTH 16u
#define FMC_OTA_ACT_VER_OTA_ACT_VER(x) (((uint32_t)(((uint32_t)(x))<<FMC_OTA_ACT_VER_OTA_ACT_VER_SHIFT))&FMC_OTA_ACT_VER_OTA_ACT_VER_MASK)
/* OTA_ACT_VER0 Reg Mask */
#define FMC_OTA_ACT_VER_MASK           0x0000FFFFu


/*!
 * @}
 */ /* end of group FMC_Register_Masks */

/*!
 * @}
 */ /* end of group FMC_Peripheral_Access_Layer */

#endif
