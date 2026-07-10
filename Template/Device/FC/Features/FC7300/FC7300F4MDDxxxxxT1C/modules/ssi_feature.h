#ifndef _DEVICE_FEATURES_FC7300F4MDDxxxxxT1C_SSI_COMMON_H_
#define _DEVICE_FEATURES_FC7300F4MDDxxxxxT1C_SSI_COMMON_H_
/** Number of instances of the MAM module. */
#define SSI_INSTANCE_COUNT                       (1u)
#define SSI_INTERNAL_CMP_SUPPORT                 (STD_OFF)


/** Array initializer of FCUART peripheral base addresses */
#define SSI_BASE_ADDRS                        {SSI0_BASE}
/** Array initializer of FCUART peripheral base pointers */
#define SSI_BASE_PTRS                         {SSI0}

typedef enum
{
    SSI_INSTANCE_0 = 0U,
} SSI_InstanceType;

/**
 * @brief Enumeration for SSI sub-instance indices.
 */
typedef enum
{
    SSI_SUB_INS0    = 0x0U, /**< Sub-instance 0 */
    SSI_SUB_INS1    = 0x1U, /**< Sub-instance 1 */
    SSI_SUB_INS2    = 0x2U, /**< Sub-instance 2 */
    SSI_SUB_INS3    = 0x3U, /**< Sub-instance 3 */
    SSI_SUB_INS_NUM = 0x4U  /**< Total number of sub-instances */
} SSI_Sub_Ins_Index;

/**
 * @brief Enumeration for SSI protocol modes.
 */
typedef enum
{
    NORMAL = 0x0U, /**< Normal mode */
    PWM    = 0x1U, /**< PWM mode */
    AK     = 0x2U, /**< AK protocol mode */
    GPWM   = 0x3U  /**< General PWM mode */
} SSI_Protocol_ModeType;

/**
 * @brief Enumeration for SSI channel selection options.
 */
typedef enum
{
    DIGITAL_PAD  = 0x1U, /**< Digital pad input */
    ONCHIP_CMP   = 0x2U, /**< On-chip comparator */
    TRGSEL       = 0x3U  /**< Trigger select */
} SSI_Channel_SelectType;

typedef struct
{
    uint8_t                u8GpwmInv;    /* inverse inout pwm signal*/
    uint8_t                u8RangeChken; /* wheel count range check enable*/
    uint8_t                u8ChlSw;      /* select inh or inm is used for decode input*/
    SSI_Protocol_ModeType  eProtSel;     /* protocol mode select */
    SSI_Channel_SelectType eChnlSel;     /* ssi channel select*/
    uint32_t               u32GpwmToc;   /* general pwm deode timeout set 65536*gpwm_toc */
} SSI_Common_CfgType;

#endif /* _DEVICE_FEATURES_FC7300F4MDDxxxxxT1C_SSI_COMMON_H_ */
