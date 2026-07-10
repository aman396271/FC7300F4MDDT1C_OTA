/**
 * @file module_driver_hsm.h
 * @author flagchip
 * @brief HSM driver type definition and API
 * @version 2.0.0
 * @date 2024-08-20
 *
 * SDK Version: 2.6.0
 *

 * @copyright Copyright (c) 2024 Flagchip Semiconductors Co., Ltd.
 *
 */
/* ********************************************************************************
 *   Revision History:
 *
 *   Version     Date          Initials      CR#          Descriptions
 *   ---------   ----------    ------------  ----------   ---------------
 *   0.1.0       2023-12-15    Flagchip051   N/A          First version for FC7300
 *   2.0.0       2024-10-12    Flagchip071   N/A          Change version and release
 ******************************************************************************** */
#ifndef _DRIVER_MODULE_DRIVER_HSM_H_
#define _DRIVER_MODULE_DRIVER_HSM_H_

#ifdef CRYPTO_HSM_MCAL
#include "Mcal.h"
#else
#include "device_header.h"
#endif

#if defined(__cplusplus)
extern "C"
{
#endif

#ifdef CRYPTO_HSM_MCAL
typedef uint32 hsm_uint32_t;
typedef uint16 hsm_uint16_t;
typedef uint8  hsm_uint8_t;
typedef sint32 hsm_int32_t;
typedef sint8  hsm_int8_t;
#else
typedef uint32_t hsm_uint32_t;
typedef uint16_t hsm_uint16_t;
typedef uint8_t  hsm_uint8_t;
typedef int32_t  hsm_int32_t;
typedef int8_t   hsm_int8_t;
#endif

#define TYPE_CONVERT(from_type, to_type, data) ((to_type)(data))

/**
 * @addtogroup fc7xxx_driver_hsm
 * @{
 */
/**
 * @name definitions for HSM_BoolType
 *
 */
/**@{*/
/**
 * @brief Boolean false value definition for type HSM_BoolType used by HSM
 *
 */
#define HSM_FALSE                              (0u)

/**
 * @brief Boolean true value definition for type HSM_BoolType used by HSM
 *
 */
#define HSM_TRUE                               (1u)

/**
 * @brief Boolean type for HSM
 *
 */
typedef hsm_uint32_t HSM_BoolType;
/**@}*/

#define HSM_KEY_LOCATION_NVR_RAM   (0x1u)
#define HSM_KEY_LOCATION_NVR_FLASH (0x0u)
#define HSM_KEY_ID(id, location) \
    (((((hsm_uint32_t)(id)) << 8u)) | (((hsm_uint32_t)(location)) & 0x1u))

/* ------------------------------------------------------------------------------- */
/**
 * @brief the true random count return by the API
 *
 */
#define HSM_TRNG_RAND_U32_CNT 16

/**
 * @brief Status returned by HSM SDK CM7 side APIs
 *
 */
typedef enum
{
    HSM_STATUS_SUCCESS = 0U, /*!< return this when HSM API execute successfully */
    HSM_STATUS_BUSY,         /*!< return this when hsm driver or the hardware is busy now */
    HSM_STATUS_PARAM_ERR,    /*!< return this when parameter error */
    HSM_STATUS_ERROR,        /*!< return this when some error happen in HSM API */
    HSM_STATUS_ECC_ERROR,    /*!< return this when flash ecc error */
    HSM_STATUS_IDLE,         /*!< return this when driver has nothing to do */
    HSM_STATUS_ERROR_STOP,   /*!< return this when the continous operation in poll API or ISR is
                                stopped due to some error happen */
    HSM_STATUS_FINISH, /*!< return this only when FC4150F512 CMAC/XMAC push data into hardware finish */
    HSM_STATUS_PASS,  /*!< return this when ecc/sm2 verify pass, or check pass in CMAC/XMAC/CCM/GCM
                         which icv check enabled */
    HSM_STATUS_FAIL,  /*!< return this when ecc/sm2 verify fail, or check fail in CMAC/XMAC/CCM/GCM
                         which icv check enabled, or get random data fail */
    HSM_STATUS_AGAIN, /*!< return this when the HSM API need call again */
    HSM_STATUS_LOGIC_ERR,        /*!< return this when HSM API called in wrong logic */
    HSM_STATUS_HW_ERR,           /*!< return this when the HSM hardware error happen */
    HSM_STATUS_HW_IDLE,          /*!< return this when the HSM hardware has nothing to do */
    HSM_STATUS_ALREADY_FINISHED, /*!< return this only when FC4150F512 CMAC/XMAC has pushed all data
                                    into the hardware */
    HSM_STATUS_SEND_FAIL,        /*!< return this when send the command to HSM core fail */
    HSM_STATUS_BUFFER_SIZE_ERR,  /*!< return this when the result buffer size not enough */
    HSM_STATUS_TIMEOUT_ERR,
    HSM_STATUS_NOT_EXIST,
    HSM_STATUS_EXIST,
    HSM_STATUS_ZOMBIE,
    HSM_STATUS_SPACE_FULL
} HSM_StatusType;

/**
 * @name definitions for HSM_MailboxApiRetType
 *
 */
/**@{*/
/**
 * @brief success status (HSM_MailboxApiRetType) returned by HSM subsystem APIs
 *
 */
#define MAILBOXAPI_RET_SUCCESS         (0u)

/**
 * @brief error status (HSM_MailboxApiRetType) returned by HSM subsystem APIs
 *
 */
#define MAILBOXAPI_RET_ERROR           (1u)

/**
 * @brief failure status (HSM_MailboxApiRetType) returned by HSM subsystem APIs
 *
 */
#define MAILBOXAPI_RET_FAIL            (2u)

/**
 * @brief verify pass status (HSM_MailboxApiRetType) returned by HSM subsystem APIs
 *
 */
#define MAILBOXAPI_RET_PASS            (3u)

/**
 * @brief function not support status (HSM_MailboxApiRetType) returned by HSM subsystem APIs
 *
 */
#define MAILBOXAPI_RET_NOT_SUPPORT     (4u)

/**
 * @brief hardware error status (HSM_MailboxApiRetType) returned by HSM subsystem APIs
 *
 */
#define MAILBOXAPI_RET_HW_ERROR        (5u)

/**
 * @brief have no permission status (HSM_MailboxApiRetType) returned by HSM subsystem APIs
 *
 */
#define MAILBOXAPI_RET_NO_PRIVILEGES   (6u)

/**
 * @brief parameters error status (HSM_MailboxApiRetType) returned by HSM subsystem APIs
 *
 */
#define MAILBOXAPI_RET_PARAMETER_ERROR (7u)

/**
 * @brief authority error status (HSM_MailboxApiRetType) returned by HSM subsystem APIs
 *
 */
#define MAILBOXAPI_RET_AUTHORITY_ERROR (8u)

/**
 * @brief hardware busy status (HSM_MailboxApiRetType) returned by HSM subsystem APIs
 *
 */
#define MAILBOXAPI_RET_BUSY            (9u)

/**
 * @brief flash ecc error status (HSM_MailboxApiRetType) returned by HSM subsystem APIs
 *
 */
#define MAILBOXAPI_RET_ECC_ERR         (10u)

/**
 * @brief time expire error status (HSM_MailboxApiRetType) returned by HSM subsystem APIs
 *
 */
#define MAILBOXAPI_RET_TIMEOUT         (11u)

#define MAILBOXAPI_RET_NONE            (0xFFFFFFFFu)
/**
 * @brief status type definition returned by HSM subsystem APIs
 *
 */
typedef hsm_uint32_t HSM_MailboxApiRetType;
/**@}*/

/**
 * @name Type definition for HSM Isr/Poll mode
 *
 */
/**@{*/

/* ------------------------------------------------------------------------------- */
/**
 * @brief the true random count return by the API
 *
 */
#define HSM_TRNG_RAND_U32_CNT    16

#define HSMCOM_TRNG_SRC_0        0x40cau
#define HSMCOM_TRNG_SRC_1        0xc51cu
#define HSMCOM_TRNG_SRC_ANY      0x359bu
#define HSMCOM_TRNG_SRC_XOR      0x80a5u
#define HSMCOM_TRNG_SRC_SHIFTXOR 0x648Cu

typedef hsm_uint32_t HSM_RndSrcType;

/* ------------------------------------------------------------------------------- */
/**
 * @brief HSM cmd type definition
 *
 */
typedef struct
{
    hsm_uint32_t u32Cmd;  /*!< current command id to HSM core via mailbox */
    hsm_uint32_t u32Addr; /*!< current parameter address to HSM core via mailbox */
} HSM_CmdType;

/**
 * @brief the true random information passed to HSM core by mailbox
 *
 */
typedef struct
{
    HSM_MailboxApiRetType u32HSMStatusRet; /*!< HSM core write return status value in this */
    hsm_uint32_t u32Timeout; /*!< current command timeout Millisecond count, max 916000ms, if set to
                                0, means 1000ms */
    hsm_uint32_t (
        *aRandom)[HSM_TRNG_RAND_U32_CNT]; /*!< address is 4bytes aligned, the buffer address, HSM
                                             core will write random data to this buffer */
} HSMCom_TrueRandType;

/**
 * @brief the true random extend information passed to HSM core by mailbox
 *
 */
typedef struct
{
    HSM_MailboxApiRetType u32HSMStatusRet; /*!< HSM core write return status value in this */
    hsm_uint32_t u32Timeout; /*!< current command timeout Millisecond count, max 916000ms, if set to
                                0, means 1000ms */
    hsm_uint32_t (
        *aRandom)[HSM_TRNG_RAND_U32_CNT]; /*!< address is 4bytes aligned, the buffer address, HSM
                                             core will write random data to this buffer */
    HSM_RndSrcType u32RandSrc;            /*!< which random source will be selected */
} HSMCom_TrueRandExType;

#define HSMCOM_FASTTRNG_SRC_NORMAL 0x0u
#define HSMCOM_FASTTRNG_SRC_XOR    0x1u

typedef hsm_uint32_t HSM_FastTrngSrcType;

typedef struct
{
    uint32_t entropy_delay;
    uint32_t samp_size;
    uint32_t freq_min;
    uint32_t freq_max;
    uint32_t lrun_max;
    uint32_t retry_max;
    uint32_t mono_max;
    uint32_t mono_range;
    uint32_t run_range;
    uint32_t run_max;
    uint32_t poker_range;

    uint32_t u32RngCtrlBitsOr;
} HSM_TrngInitCfgType;

typedef struct
{
    HSM_MailboxApiRetType u32HSMStatusRet; /*!< HSM core write return status value in this */
    uint32_t u32Timeout; /*!< current command timeout tick count, tick refer to the HSM bus clock */
    uint32_t (*aRandom)[HSM_TRNG_RAND_U32_CNT]; /*!< the buffer address, HSM core will write random
                                                   data to this buffer */
    uint32_t            u32CtrlBit;
    HSM_TrngInitCfgType tTrngCfg;
} HSMCom_FastTrueRandType;
/* ------------------------------------------------------------------------------- */

/**
 * @name Type definition for HSM Isr/Poll mode
 *
 */
/**@{*/

/**
 * @brief Poll mode value for type "HSM_TriggerSrcType"
 *
 * HSM driver can work in two mode:Isr mode and poll mode.
 * In poll mode, Hsm interrupt is disabled, if the algorithm need more than one step in driver,
 * driver API user should call the API to trigger the internal state machine go to next state.
 * If don't need trigger the process any more, user should call the specific API to get the result
 * state more than one time until driver API return it actually.
 */
#define HSM_TRIGGER_SRC_USER_POLL (0U)

/**
 * @brief Isr mode value for type "HSM_TriggerSrcType"
 *
 * HSM driver can work in two mode:Isr mode and poll mode.
 * In Isr mode, Hsm interrupt is enabled, driver API user only call the specific API to start the
 * process. If the algorithm need more than one step in driver, the isr will trigger the next
 * process step in driver internal. After all steps finished, and the result will be passed to the
 * callback registered in the init API called by driver user.
 */
#define HSM_TRIGGER_SRC_ISR       (1U)

/**
 * @brief type definition for hsm state machine trigger source used by cortex side hsm driver
 *
 * HSM driver can work in two mode:Isr mode and poll mode.
 * Isr mode's detail can refer to HSM_TRIGGER_SRC_ISR.
 * Poll mode's detail can refer to HSM_TRIGGER_SRC_USER_POLL
 */
typedef hsm_uint32_t HSM_TriggerSrcType;
/**
 * @brief HSM 4bytes unit data format for HSM_DataFormatType
 * for example, if data is 0x000102030405060708090a0b0c0d0e0f, use this format, should be divided as
 * following. 0x00010203, 0x04050607, 0x08090a0b, 0x0c0d0e0f
 */
#define HSM_DATA_FORMAT_4B                    0u

/**
 * @brief HSM 1byte unit data format for HSM_DataFormatType
 * for example, if data is 0x000102030405060708090a0b0c0d0e0f, use this format, should be divided as
 * following. 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d,
 * 0x0e, 0x0f
 */
#define HSM_DATA_FORMAT_1B                    1u

/**
 * @brief HSM 1byte unit data format for HSM_DataFormatType
 * for example, if data is 0x000102030405060708090a0b0c0d0e0f, the buffer size is 18bytes, use this
 * format, should be divided as following. 0x00(pad), 0x00(pad), 0x00, 0x01, 0x02, 0x03, 0x04, 0x05,
 * 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f
 */
#define HSM_DATA_FORMAT_1B_PAD_0_LEFT_FIT_BUF 3u

/**
 * @brief HSM  data format
 * refer to HSM_DATA_FORMAT_4B, HSM_DATA_FORMAT_1B
 */
typedef hsm_uint32_t HSM_DataFormatType;

/**
 * @name definitions for HSM_ShaAlgType
 *
 */
/**@{*/
/**
 * @brief SHA160 algorithm value for type "HSM_ShaAlgType"
 * @note  it's the so-called SHA1
 */
#define HSM_SHA_160     (1U)

/**
 * @brief SHA224 algorithm value for type "HSM_ShaAlgType"
 * @note  it's the so-called SHA2-224
 */
#define HSM_SHA_224     (2U)

/**
 * @brief SHA256 algorithm value for type "HSM_ShaAlgType"
 * @note  it's the so-called SHA2-256
 */
#define HSM_SHA_256     (3U)

/**
 * @brief SHA384 algorithm value for type "HSM_ShaAlgType"
 * @note  it's the so-called SHA2-384
 */
#define HSM_SHA_384     (4U)

/**
 * @brief SHA512 algorithm value for type "HSM_ShaAlgType"
 * @note  it's the so-called SHA2-512
 */
#define HSM_SHA_512     (5U)

/**
 * @brief SHA512/224 algorithm value for type "HSM_ShaAlgType"
 * @note  it's the so-called SHA2-512/224
 */
#define HSM_SHA_512_224 (6U)

/**
 * @brief SHA512/256 algorithm value for type "HSM_ShaAlgType"
 * @note  it's the so-called SHA2-512/256
 */
#define HSM_SHA_512_256 (7U)

/**
 * @brief type definition for SHA algorithm
 * refer to HSM_SHA_160,HSM_SHA_224,HSM_SHA_256,HSM_SHA_384,HSM_SHA_512,HSM_SHA_512_224,HSM_SHA_512_256
 */
typedef hsm_uint32_t HSM_ShaAlgType;
/**@}*/

/**
 * @name definitions for HSM_HfamMacType
 *
 */
/**@{*/
/**
 * @brief SMAC mode value for type "HSM_HfamMacType"
 *
 */
#define HSM_HFAM_MAC_SMAC (0U)

/**
 * @brief HMAC mode value for type "HSM_HfamMacType"
 *
 */
#define HSM_HFAM_MAC_HMAC (1U)

/**
 * @brief SM3/MD5/SHA can generate MAC, use this to select the type of MAC
 * SMAC refer to HSM_HFAM_MAC_SMAC
 * HMAC refer to HSM_HFAM_MAC_HMAC
 */
typedef hsm_uint32_t HSM_HfamMacType;
/**@}*/

/**
 * @brief SHA/MD5/SM3 context information used by driver when call specific API
 *
 */
typedef struct
{
    HSM_BoolType    bGenerateMacEn; /*!< whether generate MAC */
    HSM_HfamMacType eMacType;       /*!< if enable generating MAC, this should configure */
    union
    {
        const void *pKeyData; /*!< address is 4bytes aligned, key to generate MAC, if enable
                                 generating MAC, this should configure */
        hsm_uint32_t u32KeyId;
    } tKeyInfo;
    hsm_uint32_t u32KeyByteCnt;         /*!< the byte count of key data */
    hsm_uint32_t u32GenerateMacByteCnt; /*!< the byte count of MAC data output */

    hsm_uint32_t u32InputDataByteCnt; /*!< the byte count of input data */
    const void  *pInputData;          /*!< address is 4bytes aligned, point to the input data */
} HSM_SmsCfgType;                     /* sms is short for sha/md5/sm3 */

/**
 * @brief SHA context information used by driver when call specific API
 *
 */
typedef HSM_SmsCfgType HSM_ShaCtxType;

/**
 * @brief type definition for driver to store information
 *
 */
typedef struct
{
    hsm_uint32_t aResult[0x10];   /*!< store the sha result, max size 0x10 is for SHA512 */
    hsm_uint32_t u32ResultU32Cnt; /*!< store the result hsm_uint32_t count, it's set by driver */
} HSM_ShaResultBufType;

/**
 * @brief SHA information used by driver when call specific API
 *
 */
typedef struct
{
    HSM_ShaAlgType        eAlg;    /*!< select sha algorithm type */
    HSM_ShaCtxType        tCfg;    /*!< sha algorithm parameter set by user */
    HSM_ShaResultBufType *pResult; /*!< point to the memory that HSM core to write result */
} HSM_ShaType;

/**
 * @brief SHA information used by driver when call specific API
 *
 */
typedef struct
{
    HSM_MailboxApiRetType u32HSMStatusRet; /*!< HSM core write return status value in this */
    hsm_uint32_t u32Timeout; /*!< current command timeout Millisecond count, max 916000ms, if set to
                                0, means 1000ms */
    HSM_ShaType tCfg;        /*!< sha algorithm parameter set by user */
} HSMCom_ShaType;

/**
 * @brief SHA extend information used by driver when call specific API
 *
 */
typedef struct
{
    HSM_ShaAlgType        eAlg;    /*!< select sha algorithm type */
    HSM_ShaCtxType        tCfg;    /*!< sha algorithm parameter set by user */
    HSM_ShaResultBufType *pResult; /*!< point to the memory that HSM core to write result */
    HSM_DataFormatType    eInputFmt;
    HSM_DataFormatType    eOutputFmt;
} HSM_ShaExType;

/**
 * @brief SHA extend information used by driver when call specific API
 *
 */
typedef struct
{
    HSM_MailboxApiRetType u32HSMStatusRet; /*!< HSM core write return status value in this */
    hsm_uint32_t u32Timeout; /*!< current command timeout Millisecond count, max 916000ms, if set to
                                0, means 1000ms */
    HSM_ShaExType tCfg;      /*!< sha algorithm parameter set by user */
} HSMCom_ShaExType;

/**
 * @brief SHA information used by driver when call specific API
 *
 */
typedef struct
{
    HSM_ShaAlgType eAlg;    /*!< select sha algorithm type */
    HSM_ShaCtxType tCfg;    /*!< sha algorithm parameter set by user */
    hsm_uint8_t   *pResult; /*!< point to the memory that HSM core to write result */
} HSM_Sha2Type;

/**
 * @brief SHA information used by driver when call specific API
 *
 */
typedef struct
{
    HSM_MailboxApiRetType u32HSMStatusRet; /*!< HSM core write return status value in this */
    hsm_uint32_t u32Timeout; /*!< current command timeout Millisecond count, max 916000ms, if set to
                                0, means 1000ms */
    HSM_Sha2Type tCfg;       /*!< sha algorithm parameter set by user */
} HSMCom_Sha2Type;

/**
 * @brief Scatter Hash information used by driver when call specific API
 *
 */
typedef struct
{
    HSM_ShaAlgType eAlg;         /*!< select sha algorithm type */
    HSM_ShaCtxType tCfg;         /*!< sha algorithm parameter set by user */
    hsm_uint32_t (*pResult)[18]; /*!< point to the memory that HSM core to write result */
} HSM_ScatterHashType;

/**
 * @brief Scatter Hash information used by driver when call specific API
 *
 */
typedef struct
{
    HSM_MailboxApiRetType u32HSMStatusRet; /*!< HSM core write return status value in this */
    hsm_uint32_t u32Timeout; /*!< current command timeout Millisecond count, max 916000ms, if set to
                                0, means 1000ms */
    HSM_ScatterHashType tCfg; /*!< sha algorithm parameter set by user */
} HSMCom_ScatterHashType;
/* ------------------------------------------------------------------------------- */
/**
 * @name definitions for HSM_DrvEccCurvePrmIndexType
 *
 */
/**@{*/
/**
 * @brief ECC curve NIST SECP224R1 value for type "HSM_DrvEccCurvePrmIndexType"
 *
 */
#define HSM_DRV_ECC_CURVE_PRM_IDX_SECP224R1 (4U)

/**
 * @brief ECC curve NIST SECP256R1 value for type "HSM_DrvEccCurvePrmIndexType"
 *
 */
#define HSM_DRV_ECC_CURVE_PRM_IDX_SECP256R1 (1U)

/**
 * @brief ECC curve NIST SECP384R1 value for type "HSM_DrvEccCurvePrmIndexType"
 *
 */
#define HSM_DRV_ECC_CURVE_PRM_IDX_SECP384R1 (2U)

/**
 * @brief ECC curve NIST SECP521R1 value for type "HSM_DrvEccCurvePrmIndexType"
 *
 */
#define HSM_DRV_ECC_CURVE_PRM_IDX_SECP521R1 (3U)

/**
 * @brief max count of ECC curve supported for type "HSM_DrvEccCurvePrmIndexType"
 *
 */
#define HSM_DRV_ECC_CURVE_PRM_IDX_MAX       (0xFFFFFFFFU)

/**
 * @brief type definition for ECC curve data that defined by NIST
 *
 */
typedef hsm_uint32_t HSM_DrvEccCurvePrmIndexType;
/**@}*/

/**
 * @brief ECC curve information used by driver when call specific API
 *
 */
typedef struct
{
    const hsm_uint32_t *pP; /*!< address is 4bytes aligned, ecc curve modulus */
    const hsm_uint32_t *pN; /*!< address is 4bytes aligned, ecc curve order; size; the count of all
                               possible EC points */
    const hsm_uint32_t *pA; /*!< address is 4bytes aligned, the constant "a" in y^2 = x^3 + a*x + b
                               (mod p) */
    const hsm_uint32_t *pB; /*!< address is 4bytes aligned, the constant "b" in y^2 = x^3 + a*x + b
                               (mod p) */
    const hsm_uint32_t *pGx; /*!< address is 4bytes aligned, x of the curve generator point G {x, y} */
    const hsm_uint32_t *pGy; /*!< address is 4bytes aligned, y of the curve generator point G {x, y} */
} HSM_DrvEccCurveParamType;

/**
 * @brief ECC sign information used by driver when call specific API
 *
 */
typedef struct
{
    hsm_uint32_t             u32ByteCount; /*!< all the data size, it should contains all N data */
    HSM_DrvEccCurveParamType tCurve;       /*!< ecc curve parameters */
    const hsm_uint32_t      *pPrivateKey;  /*!< address is 4bytes aligned, private key  */
    const hsm_uint32_t *pHashData; /*!< address is 4bytes aligned, hash of the data to verify */

    /* the following the sign output */
    hsm_uint32_t *pR; /*!< address is 4bytes aligned, driver internal use this buffer to store the
                         sign result R of the data to sign */
    hsm_uint32_t *pS; /*!< address is 4bytes aligned, driver internal use this buffer to store the
                         sign result S of the data to sign */
} HSM_EccSignType;

/**
 * @brief ECC sign information used by driver when call specific API
 *
 */
typedef struct
{
    HSM_MailboxApiRetType u32HSMStatusRet; /*!< HSM core write return status value in this */
    hsm_uint32_t u32Timeout; /*!< current command timeout Millisecond count, max 916000ms, if set to
                                0, means 1000ms */
    hsm_uint32_t u32UserKeyID_PrivateKey;    /*!< 0 means use key from HSM internal key space,
                                                otherwise would load key with KEYID from key space */
    hsm_uint32_t                u32BitCnt;   /*!< ECC parameter N bit count */
    HSM_DrvEccCurvePrmIndexType u32EccCurve; /*!< select hsm rom internal ecc curve parameters, if
                                                use user's self curve, set it to
                                                HSM_DRV_ECC_CURVE_PRM_IDX_MAX */
    HSM_EccSignType tCfg;                    /*!< ecc sign parameters */
} HSMCom_EccSignType;

/* ------------------------------------------------------------------------------- */
/**
 * @brief ECC verify information used by driver when call specific API
 *
 */
typedef struct
{
    hsm_uint32_t             u32DataByteCnt; /*!< the byte count of all ecc curve parameter */
    HSM_DrvEccCurveParamType tCurve;         /*!< ecc curve parameters */
    const hsm_uint32_t      *pkG_x;          /*!< address is 4bytes aligned, public key axis x */
    const hsm_uint32_t      *pkG_y;          /*!< address is 4bytes aligned, public key axis y */
    const hsm_uint32_t *pHashData; /*!< address is 4bytes aligned, hash of the data to verify */
    const hsm_uint32_t *pR; /*!< address is 4bytes aligned, the sign result R of the data to verify */
    const hsm_uint32_t *pS; /*!< address is 4bytes aligned, the sign result S of the data to verify */
} HSM_EccVerifyType;

/**
 * @brief ECC verify information used by driver when call specific API
 *
 */
typedef struct
{
    HSM_MailboxApiRetType u32HSMStatusRet; /*!< HSM core write return status value in this */
    hsm_uint32_t u32Timeout; /*!< current command timeout Millisecond count, max 916000ms, if set to
                                0, means 1000ms */
    hsm_uint32_t u32UserKeyID_PublicKey;     /*!< 0 means don't use key from HSM internal key space,
                                                otherwise would load key with KEYID from HSM */
    hsm_uint32_t                u32BitCnt;   /*!< ECC parameter N bit count */
    HSM_DrvEccCurvePrmIndexType u32EccCurve; /*!< select hsm rom internal ecc curve parameters, if
                                                use user's self curve, set it to
                                                HSM_DRV_ECC_CURVE_PRM_IDX_MAX */
    HSM_EccVerifyType tCfg;                  /*!< ecc verify parameters */
} HSMCom_EccVerifyType;

/* ------------------------------------------------------------------------------- */
/**
 * @brief SM2 key pair generation information used by driver when call specific API
 *
 */
typedef struct
{
    hsm_uint32_t (*pPrivateKey)[8];  /*!< address is 4bytes aligned, private key */
    hsm_uint32_t (*pPublicKey_X)[8]; /*!< address is 4bytes aligned, the public key X */
    hsm_uint32_t (*pPublicKey_Y)[8]; /*!< address is 4bytes aligned, the public key Y */
} HSM_Sm2GenKeyPairType;

/**
 * @brief SM2 key pair generation information used by driver when call specific API
 *
 */
typedef struct
{
    HSM_MailboxApiRetType u32HSMStatusRet; /*!< HSM core write return status value in this */
    hsm_uint32_t u32Timeout; /*!< current command timeout Millisecond count, max 916000ms, if set to
                                0, means 1000ms */
    HSM_Sm2GenKeyPairType tCfg; /*!< sm2 generate key pair  parameters */
} HSMCom_Sm2GenKeyPairType;

/* ------------------------------------------------------------------------------- */
/**
 * @brief SM2 encrypt information used by driver when call specific API
 *
 */
typedef struct
{
    hsm_uint32_t  u32SM2InputByteCnt; /*!< the length should be <= 32bytes */
    hsm_uint32_t *pSM2OutputByteCnt; /*!< address is 4bytes aligned, driver internal will set output
                                        byte count in the memory this pointer point to */
    hsm_uint32_t *pInputData;        /*!< address is 4bytes aligned, length should be more than
                                        u32SM2InputByteCnt, and must be 4bytes align */
    hsm_uint32_t (*pPublicKey_x)[8]; /*!< address is 4bytes aligned, public key axis x data */
    hsm_uint32_t (*pPublicKey_y)[8]; /*!< address is 4bytes aligned, public key axis y data */
    hsm_uint32_t *pOutputData;       /*!< address is 4bytes aligned, length should be more than
                                        u32SM2InputByteCnt+97, and must be 4bytes align */
} HSM_Sm2EncryptType;

/**
 * @brief SM2 encrypt information used by driver when call specific API
 *
 */
typedef struct
{
    HSM_MailboxApiRetType u32HSMStatusRet; /*!< HSM core write return status value in this */
    hsm_uint32_t u32Timeout; /*!< current command timeout Millisecond count, max 916000ms, if set to
                                0, means 1000ms */
    hsm_uint32_t u32UserKeyID_PublicKey; /*!< 0 means don't use key from HSM internal key space,
                                            otherwise would load key with KEYID from HSM */
    HSM_Sm2EncryptType tCfg;             /*!< sm2 encrypt parameters */
} HSMCom_Sm2EncryptType;

/* ------------------------------------------------------------------------------- */
/**
 * @brief SM2 decrypt information used by driver when call specific API
 *
 */
typedef struct
{
    hsm_uint32_t  u32SM2InputByteCnt; /*!< the length should be <= 129bytes */
    hsm_uint32_t *pSM2OutputByteCnt; /*!< address is 4bytes aligned, driver internal will set output
                                        byte count in the memory this pointer point to */
    hsm_uint32_t *pInputData;        /*!< address is 4bytes aligned, length should be more than
                                        u32SM2InputByteCnt, and must be 4bytes align */
    hsm_uint32_t (*pPrivateKey)[8];  /*!< address is 4bytes aligned, private key */
    hsm_uint32_t *pOutputData;       /*!< address is 4bytes aligned, length should be more than
                                        u32SM2InputByteCnt-97, and must be 4bytes align */
} HSM_Sm2DecryptType;

/**
 * @brief SM2 decrypt information used by driver when call specific API
 *
 */
typedef struct
{
    HSM_MailboxApiRetType u32HSMStatusRet; /*!< HSM core write return status value in this */
    hsm_uint32_t u32Timeout; /*!< current command timeout Millisecond count, max 916000ms, if set to
                                0, means 1000ms */
    hsm_uint32_t u32UserKeyID_PrivateKey; /*!< 0 means don't use key from HSM internal key space,
                                             otherwise would load key with KEYID from HSM */
    HSM_Sm2DecryptType tCfg;              /*!< sm2 decrypt parameters */
} HSMCom_Sm2DecryptType;

/* ------------------------------------------------------------------------------- */
/**
 * @brief SM2 sign information used by driver when call specific API
 *
 */
typedef struct
{
    HSM_BoolType bUseDefaultID; /*!< true means use default ID. false means use specific ID with
                                   "pInputData_ID" and "u32SM2InputIDByteCnt" params. */
    HSM_BoolType bHashInput; /*!< true means process hash message. false means process raw M message */
    hsm_uint32_t u32SM2InputMByteCnt;  /*!< the length should be <= 32bytes */
    hsm_uint32_t u32SM2InputIDByteCnt; /*!< the length should be <= 32bytes note: If "bUseDefaultID"
                                          is false, would use this specific ID length with byte unit. */
    hsm_uint32_t *pInputData_ID; /*!< address is 4bytes aligned, note: If "bUseDefaultID" is false,
                                    would use this specific ID. length should be more than
                                    u32SM2InputIDByteCnt, and must be 4bytes align */
    hsm_uint32_t *pInputData_MOrHash; /*!< address is 4bytes aligned, length should be more than
                                         u32SM2InputMOrHashByteCnt, and must be 4bytes align */
    hsm_uint32_t (*pPrivateKey)[8];   /*!< address is 4bytes aligned, private key */
    hsm_uint32_t (*pPublicKey_X)[8];  /*!< address is 4bytes aligned, If bHashInput is false, the
                                         pointer must be not NULL_PTR */
    hsm_uint32_t (*pPublicKey_Y)[8];  /*!< address is 4bytes aligned, If bHashInput is false, the
                                         pointer must be not NULL_PTR */
    hsm_uint32_t (*pOutputData_R)[8]; /*!< address is 4bytes aligned, sign result R */
    hsm_uint32_t (*pOutputData_S)[8]; /*!< address is 4bytes aligned, sign result S */
} HSM_Sm2SignType;

/**
 * @brief SM2 sign information used by driver when call specific API
 *
 */
typedef struct
{
    HSM_MailboxApiRetType u32HSMStatusRet; /*!< HSM core write return status value in this */
    hsm_uint32_t u32Timeout; /*!< current command timeout Millisecond count, max 916000ms, if set to
                                0, means 1000ms */
    hsm_uint32_t u32UserKeyID_PublicKey;  /*!< 0 means don't use key from HSM internal key space,
                                             otherwise would load key with KEYID from HSM */
    hsm_uint32_t u32UserKeyID_PrivateKey; /*!< 0 means don't use key from HSM internal key space,
                                             otherwise would load key with KEYID from HSM */
    HSM_Sm2SignType tCfg;                 /*!< sm2 sign parameters */
} HSMCom_Sm2SignType;

/* ------------------------------------------------------------------------------- */
/**
 * @brief SM2 verify information used by driver when call specific API
 *
 */
typedef struct
{
    HSM_BoolType bUseDefaultID; /*!< true means use default ID. false means use specific ID with
                                   "pInputData_ID" and "u32SM2InputIDByteCnt" params. */
    HSM_BoolType bHashInput; /*!< true means process hash message. false means process raw M message */
    hsm_uint32_t u32SM2InputMByteCnt;  /*!< the length should be <= 32bytes */
    hsm_uint32_t u32SM2InputIDByteCnt; /*!< the length should be <= 32bytes note: If "bUseDefaultID"
                                          is false, would use this specific ID length with byte unit. */
    hsm_uint32_t *pInputData_MOrHash;  /*!< address is 4bytes aligned, length should be more than
                                          u32SM2InputMOrHashByteCnt, and must be 4bytes align */
    hsm_uint32_t *pInputData_ID; /*!< address is 4bytes aligned, note: If "bUseDefaultID" is false,
                                    would use this specific ID. length should be more than
                                    u32SM2InputIDByteCnt, and must be 4bytes align */
    hsm_uint32_t (*pInputData_R)[8]; /*!< address is 4bytes aligned, the sign result R */
    hsm_uint32_t (*pInputData_S)[8]; /*!< address is 4bytes aligned, the sign result S */
    hsm_uint32_t (*pPublicKey_X)[8]; /*!< address is 4bytes aligned, the public key X */
    hsm_uint32_t (*pPublicKey_Y)[8]; /*!< address is 4bytes aligned, the public key Y */
} HSM_Sm2VerifyType;

/**
 * @brief SM2 verify information used by driver when call specific API
 *
 */
typedef struct
{
    HSM_MailboxApiRetType u32HSMStatusRet; /*!< HSM core write return status value in this */
    hsm_uint32_t u32Timeout; /*!< current command timeout Millisecond count, max 916000ms, if set to
                                0, means 1000ms */
    hsm_uint32_t u32UserKeyID_PublicKey; /*!< 0 means don't use key from HSM internal key space,
                                            otherwise would load key with KEYID from HSM */
    HSM_Sm2VerifyType tCfg;              /*!< sm2 verify parameters */
} HSMCom_Sm2VerifyType;

/* ------------------------------------------------------------------------------- */
/**
 * @brief SM2 ZA generation information used by driver when call specific API
 *
 */
typedef struct
{
    HSM_BoolType bUseDefaultID; /*!< true means use default ID. false means use specific ID with
                                   "pInputData_ID" and "u32SM2InputIDByteCnt" params. */
    hsm_uint32_t u32SM2InputIDByteCnt; /*!< the length should be <= 32bytes  note: If "bUseDefaultID"
                                          is false, would use this specific ID length with byte unit.*/
    hsm_uint32_t (*pPublicKey_X)[8];   /*!< address is 4bytes aligned, public key x */
    hsm_uint32_t (*pPublicKey_Y)[8];   /*!< address is 4bytes aligned, public key y */
    hsm_uint32_t *pInputData_ID; /*!< address is 4bytes aligned, note: If "bUseDefaultID" is false,
                                    would use this specific ID. length should be more than
                                    u32SM2InputIDByteCnt, and must be 4bytes align */
    hsm_uint32_t (*pOutputData_Za)[8]; /*!< address is 4bytes aligned, Length is 32bytes, SM3 always
                                          output 256bit */
} HSM_Sm2GenZaType;

/**
 * @brief SM2 ZA generation information used by driver when call specific API
 *
 */
typedef struct
{
    HSM_MailboxApiRetType u32HSMStatusRet; /*!< HSM core write return status value in this */
    hsm_uint32_t u32Timeout; /*!< current command timeout Millisecond count, max 916000ms, if set to
                                0, means 1000ms */
    hsm_uint32_t u32UserKeyID_PublicKey; /*!< 0 means don't use key from HSM internal key space,
                                            otherwise would load key with KEYID from HSM */
    HSM_Sm2GenZaType tCfg;
} HSMCom_Sm2GenZaType;
/* ------------------------------------------------------------------------------- */
/**
 * @brief SM2 HASH generation information used by driver when call specific API
 *
 */
typedef struct
{
    hsm_uint32_t  u32InputDataByteCnt; /*!< input data byte count */
    hsm_uint32_t *pInputData_ZaAndM;   /*!< address is 4bytes aligned, note: it should be ZA||M, the
                                          length should be more than u32InputDataByteCnt, and must be
                                          4bytes align */
    hsm_uint32_t (*pOutputData_Hash)[8]; /*!< address is 4bytes aligned, Length is 32bytes, SM3
                                            always output 256bit */
} HSM_Sm2GenHashType;

/**
 * @brief SM2 HASH generation information used by driver when call specific API
 *
 */
typedef struct
{
    HSM_MailboxApiRetType u32HSMStatusRet; /*!< HSM core write return status value in this */
    hsm_uint32_t u32Timeout; /*!< current command timeout Millisecond count, max 916000ms, if set to
                                0, means 1000ms */
    HSM_Sm2GenHashType tCfg; /*!< sm2 generate hash parameters */
} HSMCom_Sm2GenHashType;
/* ------------------------------------------------------------------------------- */
/**
 * @name definitions for HSM_Sm4KeyType
 *
 */
/**@{*/
/**
 * @brief vendor key value for type "HSM_Sm4KeyType"
 *
 * HSM hardware support accessing the SM4 key stored in nvr flash directly,
 * chip user should program the key in flash already.
 * This way don't need software read data and write it to some place,
 * hardware will read the data itself automatically.
 */
#define HSM_SM4_KEY_CHIP_VENDOR_IFR \
    (0U) /* key has existed in Flash IFR, it provided by chip, not changeable */

/**
 * @brief driver user's new key value for type "HSM_Sm4KeyType"
 *
 * HSM use the key passed by driver API user.
 */
#define HSM_SM4_KEY_NEW (1U) /* user should provide the new key */

typedef hsm_uint32_t HSM_Sm4KeyType;
/**@}*/

/**
 * @name definitions for HSM_SymmEnDecryptAlgType
 *
 */
/**@{*/
/**
 * @brief CTR mode value for type "HSM_SymmEnDecryptAlgType"
 *
 */
#define HSM_SYMM_ENDECRYPT_MODE_CTR (0U)

/**
 * @brief CBC mode value for type "HSM_SymmEnDecryptAlgType"
 *
 */
#define HSM_SYMM_ENDECRYPT_MODE_CBC (1U)

/**
 * @brief ECB mode value for type "HSM_SymmEnDecryptAlgType"
 *
 */
#define HSM_SYMM_ENDECRYPT_MODE_ECB (2U)

/**
 * @brief CFB mode value for type "HSM_SymmEnDecryptAlgType"
 *
 */
#define HSM_SYMM_ENDECRYPT_MODE_CFB (3U)

/**
 * @brief OFB mode value for type "HSM_SymmEnDecryptAlgType"
 *
 */
#define HSM_SYMM_ENDECRYPT_MODE_OFB (4U)

/**
 * @brief type definition for SM4/AES encrypt/decrypt mode
 *
 * HSM support CTR/CBC/ECB/CFB/OFB mode, driver api use this to select the encrypt/decrypt mode.
 */
typedef hsm_uint32_t HSM_SymmEnDecryptAlgType;
/**@}*/

/* ------------------------------------------------------------------------------- */
/**
 * @brief ECC encrypt information used by driver when call specific API
 *
 */
typedef struct
{
    hsm_uint32_t u32ByteCount; /*!< all the data size, it should contains all N data */

    const hsm_uint32_t *pCoeffi_A; /*!< address should align with 4bytes, the constant "a" in y^2 =
                                      x^3 + a*x + b (mod p), all data 8 bytes aligned */
    const hsm_uint32_t *pCoeffi_B; /*!< address should align with 4bytes, the constant "b" in y^2 =
                                      x^3 + a*x + b (mod p) */
    const hsm_uint32_t *pP;        /*!< address should align with 4bytes, ecc curve modulus */
    const hsm_uint32_t *pN; /*!< address should align with 4bytes, ecc curve order; size; the count
                               of all possible EC points */
    const hsm_uint32_t *pOtherSidePublicKey_x; /*!< address should align with 4bytes, decrypt side's
                                                  public key axis x data */
    const hsm_uint32_t *pOtherSidePublicKey_y; /*!< address should align with 4bytes, decrypt side's
                                                  public key axis y data */
    const hsm_uint32_t *pPrivateKey; /*!< address should align with 4bytes, encrypt side private key */
    const hsm_uint32_t *pPlainData; /*!< address should align with 4bytes, data to be encrypted, its
                                       byte count should be same as u32ByteCount */

    hsm_uint32_t *pEncryedData; /*!< address should align with 4bytes, driver internal write the
                                   result to this buffer */
} HSM_EccEasyEncryType;

/**
 * @brief ECC encrypt information used by driver when call specific API
 *
 */
typedef struct
{
    HSM_MailboxApiRetType u32HSMStatusRet; /*!< HSM core write return status value in this */
    hsm_uint32_t u32Timeout; /*!< current command timeout Millisecond count, max 916000ms, if set to
                                0, means 1000ms */
    hsm_uint32_t u32UserKeyID_PrivateKey;    /*!< 0 means don't use key from HSM internal key space,
                                                otherwise would load key with KEYID from HSM */
    hsm_uint32_t u32UserKeyID_PublicKey;     /*!< 0 means don't use key from HSM internal key space,
                                                otherwise would load key with KEYID from HSM */
    hsm_uint32_t                u32BitCnt;   /*!<  ecc encrypt data bit count */
    HSM_DrvEccCurvePrmIndexType u32EccCurve; /*!< ecc curve */
    HSM_EccEasyEncryType        tCfg;        /*!< ecc encrypt parameters */
} HSMCom_EccEasyEncryType;

/* ------------------------------------------------------------------------------- */
/**
 * @brief ECC decrypt information used by driver when call specific API
 *
 */
typedef struct
{
    hsm_uint32_t u32ByteCount; /*!< all the data size, it should contains all N data */

    const hsm_uint32_t *pCoeffi_A; /*!< address should align with 4bytes, the constant "a" in y^2 =
                                      x^3 + a*x + b (mod p), all data 8 bytes aligned */
    const hsm_uint32_t *pCoeffi_B; /*!< address should align with 4bytes, the constant "b" in y^2 =
                                      x^3 + a*x + b (mod p) */
    const hsm_uint32_t *pP;        /*!< address should align with 4bytes, ecc curve modulus */
    const hsm_uint32_t *pN; /*!< address should align with 4bytes, ecc curve order; size; the count
                               of all possible EC points */
    const hsm_uint32_t *pOtherSidePublicKey_x; /*!< address should align with 4bytes, encrypt side's
                                                  public key axis x data */
    const hsm_uint32_t *pOtherSidePublicKey_y; /*!< address should align with 4bytes, encrypt side's
                                                  public key axis y data */
    const hsm_uint32_t *pPrivateKey; /*!< address should align with 4bytes, decrypt side private key */
    const hsm_uint32_t *pEncryedData; /*!< address should align with 4bytes, data to be decrypted,
                                         its byte count should be same as u32ByteCount */

    hsm_uint32_t *pPlainData; /*!< address should align with 4bytes, driver internal write the
                                 result to this buffer */
} HSM_EccEasyDecryType;

/**
 * @brief ECC decrypt information used by driver when call specific API
 *
 */
typedef struct
{
    HSM_MailboxApiRetType u32HSMStatusRet; /*!< HSM core write return status value in this */
    hsm_uint32_t u32Timeout; /*!< current command timeout Millisecond count, max 916000ms, if set to
                                0, means 1000ms */
    hsm_uint32_t u32UserKeyID_PrivateKey;    /*!< 0 means don't use key from HSM internal key space,
                                                otherwise would load key with KEYID from HSM */
    hsm_uint32_t u32UserKeyID_PublicKey;     /*!< 0 means don't use key from HSM internal key space,
                                                otherwise would load key with KEYID from HSM */
    hsm_uint32_t                u32BitCnt;   /*!<  ecc encrypt data bit count */
    HSM_DrvEccCurvePrmIndexType u32EccCurve; /*!< ecc curve */
    HSM_EccEasyDecryType        tCfg;        /*!< ecc decrypt parameters */
} HSMCom_EccEasyDecryType;
/* ------------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------- */
#define HSM_ECC_CALC_PADD 0xFC73F800U
#define HSM_ECC_CALC_PDBL 0xFC73F801U
#define HSM_ECC_CALC_PMUL 0xFC73F802U
#define HSM_ECC_CALC_PCHK 0xFC73F803U

/**
 * @brief ECC point calclulate used by driver when call specific API
 *
 */
typedef struct
{
    hsm_uint32_t u32ByteCount; /*!< all the data size, it should contains all N data */

    const hsm_uint32_t *pCoeffi_A; /*!< address should align with 4bytes, the constant "a" in y^2 =
                                      x^3 + a*x + b (mod p), all data 8 bytes aligned */
    const hsm_uint32_t *pCoeffi_B; /*!< address should align with 4bytes, the constant "b" in y^2 =
                                      x^3 + a*x + b (mod p) */
    const hsm_uint32_t *pP;        /*!< address should align with 4bytes, ecc curve modulus */
    const hsm_uint32_t *pN; /*!< address should align with 4bytes, ecc curve order; size; the count
                               of all possible EC points */
    const hsm_uint32_t *pP1x; /*!< address should align with 4bytes, encrypt side's public key axis x data */
    const hsm_uint32_t *pP1y; /*!< address should align with 4bytes, encrypt side's public key axis y data */
    const hsm_uint32_t *pE;   /*!< address should align with 4bytes, decrypt side private key */
    const hsm_uint32_t *pP2x; /*!< address should align with 4bytes, data to be decrypted, its byte
                                 count should be same as u32ByteCount */

    hsm_uint32_t *pResultx; /*!< address should align with 4bytes, driver internal write the result
                               to this buffer */

    hsm_uint32_t        u32CalcType;
    const hsm_uint32_t *pP2y;
    hsm_uint32_t       *pResulty;
} HSM_EccCalcType;

/**
 * @brief ECC point calclulate used by driver when call specific API
 *
 */
typedef struct
{
    HSM_MailboxApiRetType u32HSMStatusRet; /*!< HSM core write return status value in this */
    hsm_uint32_t u32Timeout; /*!< current command timeout Millisecond count, max 916000ms, if set to
                                0, means 1000ms */
    hsm_uint32_t u32UserKeyID_E;  /*!< 0 means don't use key from HSM internal key space, otherwise
                                     would load key with KEYID from HSM */
    hsm_uint32_t u32UserKeyID_P1; /*!< 0 means don't use key from HSM internal key space, otherwise
                                     would load key with KEYID from HSM */
    hsm_uint32_t                u32BitCnt;   /*!<  ecc encrypt data bit count */
    HSM_DrvEccCurvePrmIndexType u32EccCurve; /*!< ecc curve */
    HSM_EccCalcType             tCfg;        /*!< ecc decrypt parameters */
} HSMCom_EccCalcType;

/* ------------------------------------------------------------------------------- */
#define HSM_COM_REQUEST_AUTH_DATA_U32_CNT 8

/**
 * @brief Request Auth used by driver when call specific API
 *
 */
typedef struct
{
    HSM_MailboxApiRetType u32HSMStatusRet; /*!< HSM core write return status value in this */
    hsm_uint32_t u32Timeout; /*!< current command timeout Millisecond count, max 916000ms, if set to
                                0, means 1000ms */
    hsm_uint32_t (*pData)[HSM_COM_REQUEST_AUTH_DATA_U32_CNT]; /*!< address should align with 4bytes,
                                                                 buffer to store the data */
} HSMCom_RequestAuthType;
/* ------------------------------------------------------------------------------- */
/* #define AUTH_CHECK_DATA_BYTE_CNT 32 */

/**
 * @brief Change lifecycle used by driver when call specific API
 *
 */
typedef struct
{
    HSM_MailboxApiRetType u32HSMStatusRet; /*!< HSM core write return status value in this */
    hsm_uint32_t u32Timeout; /*!< current command timeout Millisecond count, max 916000ms, if set to
                                0, means 1000ms */
    const hsm_uint32_t *pkG_x; /*!< address should align with 4bytes */
    const hsm_uint32_t *pkG_y; /*!< address should align with 4bytes */
    const hsm_uint32_t *pR;    /*!< address should align with 4bytes */
    const hsm_uint32_t *pS;    /*!< address should align with 4bytes */
    /* For user code verify function */
    const hsm_uint32_t *pData;         /*!< address should align with 4bytes */
    hsm_uint32_t        u32DataLength; /*!< the data byte count */
} HSMCom_LifeCycleChangeType;
/* ------------------------------------------------------------------------------- */

/**
 * @brief Cancel job used by driver when call specific API
 *
 */
typedef struct
{
    HSM_MailboxApiRetType u32HSMStatusRet; /*!< HSM core write return status value in this */
    hsm_uint32_t u32Timeout; /*!< current command timeout Millisecond count, max 916000ms, if set to
                                0, means 1000ms */
    hsm_uint32_t u32MailboxChannel; /*!< the mailbox channel of the job to be canceled */
} HSMCom_CancelJobType;
/* ------------------------------------------------------------------------------- */
/**
 * @name definitions for HSMCom_FirmwareLoadStatus
 *
 */
/**@{*/
/**
 * @brief no firmware detected in flash status
 *
 */
#define HSMCOM_FIRMWARE_LOAD_NONE      0U

/**
 * @brief status value represents firmware is loading now
 *
 */
#define HSMCOM_FIRMWARE_LOADING        1U

/**
 * @brief status value represents firmware waiting user to trigger load in CM7 side
 *
 */
#define HSMCOM_FIRMWARE_NEED_USER_LOAD 2U

/**
 * @brief status value represents firmware is loaded successfully
 *
 */
#define HSMCOM_FIRMWARE_LOAD_OK        3U

/**
 * @brief status value represents firmware load fail
 *
 */
#define HSMCOM_FIRMWARE_LOAD_FAIL      4U

/**
 * @brief type definition for firmware load status
 *
 */
typedef hsm_uint32_t HSMCom_FirmwareLoadStatus;
/**@}*/

typedef struct
{
    HSM_MailboxApiRetType u32HSMStatusRet; /*!< HSM core write return status value in this */
    hsm_uint32_t u32Timeout; /*!< current command timeout Millisecond count, max 916000ms, if set to
                                0, means 1000ms */
    hsm_uint32_t u32CommitId;    /*!< HSM repo commit id */
    hsm_uint32_t u32BuildDate;   /*!< HSM repo build id */
    hsm_uint32_t u32FirmVersion; /*!<  firmware version */
    hsm_uint32_t u32FixedValue;  /*!<  FIX to 0x4d6f0000 */
    hsm_uint32_t u32BusClk;      /*!< the hsm bus clock */
    hsm_uint32_t u32Reserved0;
    hsm_uint32_t u32Reserved1;
    hsm_uint32_t u32Reserved2;
    hsm_uint32_t u32Reserved3;
    HSMCom_FirmwareLoadStatus u32FirmwareLoadStatus; /*!< the status of loading firmware, IF >= 4 FAIL */
} HSMCom_SelfTestType;
/* ------------------------------------------------------------------------------- */
#define HSMCOM_NVR_OTP_START_ADDR 0x04400400
#define HSMCOM_NVR_OTP_END_ADDR   0x04401fff
typedef struct
{
    HSM_MailboxApiRetType u32HSMStatusRet; /*!< HSM core write return status value in this */
    hsm_uint32_t u32Timeout; /*!< current command timeout Millisecond count, max 916000ms, if set to
                                0, means 1000ms */
    hsm_uint32_t u32Addr;    /*!< 0x04400400 - 0x04401fff, 16bytes align */
    hsm_uint32_t aData[4];
} HSMCom_NvrOtpType;
/* ------------------------------------------------------------------------------- */
/**
 * @name definitions for HSM_KeyManagerBoolType
 *
 */
/**@{*/
#define KEYMANAGER_FALSE (0u)
#define KEYMANAGER_TRUE  (1u)
typedef hsm_uint32_t HSM_KeyManagerBoolType;
/**@}*/

/**
 * @name definitions for HSM_KeyManagerKeyExportType
 *
 */
/**@{*/
#define KEYMANAGER_KEY_EXPORT_FORBIRD (0u)
#define KEYMANAGER_KEY_EXPORT_PLAIN   (1u)
#define KEYMANAGER_KEY_EXPORT_CIPHER  (2u)
#define KEYMANAGER_KEY_EXPORT_MAX     (3u)
typedef hsm_uint32_t HSM_KeyManagerKeyExportType;
/**@}*/

/**
 * @name definitions for HSM_KeyManagerUserKeyEnDecryType
 *
 */
/**@{*/
#define KEYMANAGER_ENDECRY_NONE   (0u) /* For plain key, no need to encrypt or decrypt. */
#define KEYMANAGER_ENDECRY_AES256 (1u)
#define KEYMANAGER_ENDECRY_SM4    (2u)
#define KEYMANAGER_ENDECRY_MAX    (3u)
typedef hsm_uint32_t HSM_KeyManagerUserKeyEnDecryType;
/**@}*/

/**
 * @name definitions for HSM_KeyManagerUserKeyTypeType
 *
 */
/**@{*/
#define KEYMANAGER_USER_KEY_TYPE_NONE                                                       \
    (0u) /* not configure the key type, HSM shall not check if the key type is matched with \
            de/encrypt ALG. */
#define KEYMANAGER_USER_KEY_TYPE_AES               (1u)
#define KEYMANAGER_USER_KEY_TYPE_SM4               (1u)
#define KEYMANAGER_USER_KEY_TYPE_ECC_PRIVATE       (3u)
#define KEYMANAGER_USER_KEY_TYPE_ECC_PUBLIC        (4u)
#define KEYMANAGER_USER_KEY_TYPE_SM2_PRIVATE       (5u)
#define KEYMANAGER_USER_KEY_TYPE_SM2_PUBLIC        (6u)
#define KEYMANAGER_USER_KEY_TYPE_RSA_E             (7u)
#define KEYMANAGER_USER_KEY_TYPE_RSA_N             (8u)
#define KEYMANAGER_USER_KEY_TYPE_XMAC              (9u)
#define KEYMANAGER_USER_KEY_TYPE_CMAC_KEY          (10u)
#define KEYMANAGER_USER_KEY_TYPE_CCM               (11u)
#define KEYMANAGER_USER_KEY_TYPE_GCM               (12u)
#define KEYMANAGER_USER_KEY_TYPE_ECC_SIGNATURE     (13u)
#define KEYMANAGER_USER_KEY_TYPE_SM2_SIGNATURE     (14u)
#define KEYMANAGER_USER_KEY_TYPE_IV                (15u)
#define KEYMANAGER_USER_KEY_TYPE_CMAC_RESULT       (16u)
#define KEYMANAGER_USER_KEY_TYPE_XMAC_RESULT       (17u)
#define KEYMANAGER_USER_KEY_TYPE_RSA_SIGNATURE     (18u)
#define KEYMANAGER_USER_KEY_TYPE_ED25519_PUBKEY    (19u)
#define KEYMANAGER_USER_KEY_TYPE_ED25519_SIGNATURE (20u)
#define KEYMANAGER_USER_KEY_TYPE_ED25519_PRIVATE   (21u)
#define KEYMANAGER_USER_KEY_TYPE_PBKDF2_PWD        (22u)
#define KEYMANAGER_USER_KEY_TYPE_HASHMAC_KEY       (23u)
#define KEYMANAGER_USER_KEY_TYPE_RSA               (24u)
typedef hsm_uint32_t HSM_KeyManagerUserKeyTypeType;
/**@}*/

/**
 * @name definitions for HSM_KeyManagerEnDecryAlgType
 *
 */
/**@{*/

#define KEYMANAGER_ENDECRY_ALG_CTR (0u)
#define KEYMANAGER_ENDECRY_ALG_CBC (1u)
#define KEYMANAGER_ENDECRY_ALG_ECB (2u)
#define KEYMANAGER_ENDECRY_ALG_CFB (3u)
#define KEYMANAGER_ENDECRY_ALG_OFB (4u)
#define KEYMANAGER_ENDECRY_ALG_MAX (5u)

typedef hsm_uint32_t HSM_KeyManagerEnDecryAlgType;
/**@}*/

typedef struct
{
    hsm_uint32_t *pDataAddr;   /*!< address should align with 4bytes */
    hsm_uint32_t *pDataLength; /*!< address should align with 4bytes, a hsm_uint32_t variable to
                                  store the length */
    hsm_uint32_t                     u32KeyID;
    HSM_KeyManagerUserKeyEnDecryType eEncryType; /*!< indicate if the key exported is need to be
                                                    encrypted */
    /* if the key exported need to be encrypted, below Param need to configure */
    hsm_uint32_t u32EncryKeyID; /*!< 0 means use USRK as encrykey, otherwise load decrykey with
                                   KEYID from hsm key space */
    HSM_KeyManagerEnDecryAlgType eAlgType;
    hsm_uint32_t (*pIV)[4]; /*!< address should align with 4bytes */
} HSM_KeyManagerExportUserKeyType;

typedef struct
{
    HSM_KeyManagerBoolType bStoreInFlash; /* true means store the key in flash, false means store
                                             the key in ram */
    HSM_KeyManagerKeyExportType eExportType;
    hsm_uint32_t *pDataAddr; /*!< address should align with 4bytes, the address of key imported */
    hsm_uint32_t  u32DataLength;                 /*!< the length of key imported */
    hsm_uint32_t *pKeyID;                        /*!< address should align with 4bytes */
    HSM_KeyManagerUserKeyEnDecryType eDecryType; /*!< indicate if the key imported is plain */
    /* if the key imported is encrypted, below Param need to configure */
    hsm_uint32_t u32DecryKeyID; /*!< 0 means use USRK as decrykey, otherwise load decrykey with
                                   KEYID from hsm key space */
    HSM_KeyManagerUserKeyTypeType eUserKeyType;
    HSM_KeyManagerEnDecryAlgType  eAlgType;
    hsm_uint32_t (*pIV)[4]; /*!< address should align with 4bytes */
} HSM_KeyManagerImportUserKeyType;

typedef struct
{
    HSM_KeyManagerBoolType bStoreInFlash; /* true means store the key in flash, false means store
                                             the key in ram */
    HSM_KeyManagerKeyExportType      eExportType;
    const hsm_uint32_t              *pDataAddr;     /* the address of key imported */
    hsm_uint32_t                     u32DataLength; /*  the length of key imported */
    hsm_uint32_t                    *pKeyID;
    HSM_KeyManagerUserKeyEnDecryType eDecryType; /* indicate if the key imported is plain */
    /* if the key imported is encrypted, below Param need to configure */
    hsm_uint32_t u32DecryKeyID; /* 0 means use USRK as decrykey, otherwise load decrykey with KEYID
                                   from hsm key space */
    HSM_KeyManagerUserKeyTypeType eUserKeyType;
    HSM_KeyManagerEnDecryAlgType  eAlgType;
    hsm_uint32_t (*pIV)[4];
    hsm_uint32_t u32KeyIdFix; /* FC7300 fw support */
    hsm_uint32_t u32Protect;  /* support from FC500 */
} HSM_Ln_ImportUserKeyExtType;

typedef struct
{
    hsm_uint32_t           u32SrcKeyID;
    hsm_uint32_t           u32DestKeyID;
    hsm_uint32_t          *pDestKeyID;
    HSM_KeyManagerBoolType bStoreInFlash;
    hsm_uint32_t           eUserKeyType;
} HSM_Ln_CopyUserKeyType;

#define KEYMANAGER_GEN_KEYPAIR_SM2 (0u)
#define KEYMANAGER_GEN_KEYPAIR_ECC (1u)
#define KEYMANAGER_GEN_KEYPAIR_MAX (2u)
typedef hsm_uint32_t HSM_KeyManagerGenKeyPairType;

typedef struct
{
    HSM_KeyManagerGenKeyPairType eKeyPairType;
    HSM_KeyManagerKeyExportType  eExportType;
    HSM_KeyManagerBoolType       bStoreInFlash;
    hsm_uint32_t                *pPrivateKeyID; /*!< address should align with 4bytes */
    hsm_uint32_t                *pPublicKeyID;  /*!< address should align with 4bytes */
} HSM_KeyManagerGenUserKeyType;

typedef struct
{
    HSM_KeyManagerGenUserKeyType tGenKeyPairCfg;
    HSM_DrvEccCurveParamType     tEccParam;       /*!< only for generate ECC key pair */
    hsm_uint32_t                 u32EccBitLength; /*!< only for generate ECC key pair */
} HSMCom_GenUserKeyType;

#if ((FC7XXX_HSM_SUBSYSTEM_TYPE == FC7240_HSM_SUBSYSTEM) || \
     (FC7XXX_HSM_SUBSYSTEM_TYPE == FC7300_HSM_SUBSYSTEM))

#define KEYMANAGER_USERKEY_STATUS_NOT_EXIST     (0u)
#define KEYMANAGER_USERKEY_STATUS_EXIST_VALID   (1u)
#define KEYMANAGER_USERKEY_STATUS_EXIST_INVALID (2u)
#define KEYMANAGER_USERKEY_STATUS_ERROR         (3u)

typedef hsm_uint32_t KeyManager_UserKeyStatusType;

typedef struct
{
    hsm_uint32_t                  u32KeyID;
    KeyManager_UserKeyStatusType *pUserKeyStatus;
} HSM_KeyManagerCheckUserKeyStatusExtType;

#endif

#if ((FC7XXX_HSM_SUBSYSTEM_TYPE == FC7240_HSM_SUBSYSTEM) || \
     (FC7XXX_HSM_SUBSYSTEM_TYPE == FC7300_HSM_SUBSYSTEM))

#else
typedef struct
{
    hsm_uint32_t u32KeyId;
    const void  *pDataAddr;            // the address of key imported
    hsm_uint32_t u32PlainKeyLength;    // the length of key plain

    // if the key imported is encrypted, below Param need to configure
    HSM_KeyManagerUserKeyEnDecryType eDecryType;    // indicate if the key imported is plain
    hsm_uint32_t u32DecryKeyID;    // 0 means use USRK as decrykey, otherwise load decrykey with
                                   // KEYID from hsm key space
    HSM_KeyManagerUserKeyTypeType eUserKeyType;
    HSM_KeyManagerEnDecryAlgType  eAlgType;
    hsm_uint32_t (*pIV)[4];
} HSM_Ln_KeyManagerUpdateUserKeyType;

#endif

typedef struct
{
    HSM_MailboxApiRetType u32HSMStatusRet; /*!< HSM core write return status value in this */
    hsm_uint32_t u32Timeout; /*!< current command timeout Millisecond count, max 916000ms, if set to
                                0, means 1000ms */
    union
    {
        /* For revoke UserKey function*/
        hsm_uint32_t u32RevokeUserKeyID;
        /* For import User Key function*/
        HSM_KeyManagerImportUserKeyType tImportUserKeyCfg;
        /* For export user key function */
        HSM_KeyManagerExportUserKeyType tExportUserKeyCfg;
        /* For generate key pair function */
        HSMCom_GenUserKeyType tGenUserKeyCfg;
        /* For using fixed id to import User Key function */
        HSM_Ln_ImportUserKeyExtType tImportUserKeyExtCfg;
        /* For check key id wheather exsist */
        hsm_uint32_t u32CheckUserKeyIDExt;
        /* For copy key from flash to ram or ram to flash*/
        HSM_Ln_CopyUserKeyType tCopyUserKeyExtCfg;

#if ((FC7XXX_HSM_SUBSYSTEM_TYPE == FC7240_HSM_SUBSYSTEM) || \
     (FC7XXX_HSM_SUBSYSTEM_TYPE == FC7300_HSM_SUBSYSTEM))
        /* For check the key id status */
        HSM_KeyManagerCheckUserKeyStatusExtType tKeyIdStatusExtCfg;
#endif

#if ((FC7XXX_HSM_SUBSYSTEM_TYPE == FC7240_HSM_SUBSYSTEM) || \
     (FC7XXX_HSM_SUBSYSTEM_TYPE == FC7300_HSM_SUBSYSTEM))
#else

        /* For update user key function */
        HSM_Ln_KeyManagerUpdateUserKeyType tUpdateUserKeyCfg;
#endif
    } tKMParam;
} HSMCom_UserKeyManageType;
/* ------------------------------------------------------------------------------- */
typedef struct
{
    /* For Key Flash Space */
    HSM_KeyManagerBoolType bCriticalError;
    HSM_KeyManagerBoolType bKMLackKeyHeadSpace;
    HSM_KeyManagerBoolType bKMLackKeyDataSpace;
    hsm_uint32_t           u32KeyHeadRestSpace; /*!< The unit is number */
    hsm_uint32_t           u32KeyDataRestSpace; /*!< The unit is page */
    hsm_uint32_t           u32InvalidKeyCounter;
    /* For Key ram space */
    hsm_uint32_t u32KeyRamSpaceUsed;
} HSM_Ln_KeySpaceStatusType;

typedef struct
{
    HSM_MailboxApiRetType u32HSMStatusRet; /*!< HSM core write return status value in this */
    hsm_uint32_t u32Timeout; /*!< current command timeout Millisecond count, max 916000ms, if set to
                                0, means 1000ms */
    HSM_Ln_KeySpaceStatusType *pKMSpaceStatus; /*!< address should align with 4bytes */
} HSMCom_KeySpaceStatusType;
/* ------------------------------------------------------------------------------- */

/**
 * @name definitions for HSM_AesKeyType
 *
 */
/**@{*/

/**
 * @brief vendor key value for type "HSM_AesKeyType"
 *
 * HSM hardware support accessing the aes key stored in nvr flash directly,
 * chip user should program the key in flash already.
 * This way don't need software read data and write it to some place,
 * hardware will read the data itself automatically.
 */
#define HSM_AES_KEY_CHIP_VENDOR_IFR \
    (0U) /* key has existed in Flash IFR, it provided by chip hardware, not changeable */

/**
 * @brief driver user's new key value for type "HSM_AesKeyType"
 *
 * HSM use the key passed by driver API user.
 */
#define HSM_AES_KEY_NEW (1U) /* user should provide the new key */

/**
 * @brief type definition for the key source
 *
 * key from the nvr refer to HSM_AES_KEY_CHIP_VENDOR_IFR
 * key from driver user's parameters refer to HSM_AES_KEY_NEW
 */
typedef hsm_uint32_t HSM_AesKeyType;
/**@}*/

/**
 * @name definitions for HSM_AesKeyBitCntType
 *
 */
/**@{*/

/**
 * @brief AES128 key type value for type "HSM_AesKeyBitCntType"
 *
 */
#define HSM_AES_KEY128 (0U)

/**
 * @brief AES192 key type value for type "HSM_AesKeyBitCntType"
 *
 */
#define HSM_AES_KEY192 (1U)

/**
 * @brief AES256 key type value for type "HSM_AesKeyBitCntType"
 *
 */
#define HSM_AES_KEY256 (2U)

/**
 * @brief type definition for AES key
 *
 * HSM support AES128/192/256, driver api use this to select the algorithm.
 */
typedef hsm_uint32_t HSM_AesKeyBitCntType;
/**@}*/

/**
 * @brief key information used by AES when use one key in software
 *
 */
typedef struct
{
    HSM_AesKeyBitCntType eKeyType; /*!< the key bit count, which determine the AES algorithm type */
    const void *pKeyAddr; /*!< the key data pointer, the address should 4bytes align, the buffer
                             array should declared by hsm_uint32_t */
} HSM_AesNewKeyInfType;

/**
 * @brief key information used by AES when use one key in nvr flash
 *
 */
typedef struct
{
    HSM_AesKeyBitCntType eKeyType; /*!< the key bit count, which determine the AES algorithm type */
} HSM_AesVendorKeyInfType;

/**
 * @brief AES encrypt/decrypt information used by driver when call specific API
 *
 */
typedef struct
{
    HSM_AesKeyType eUseKeyType; /*!< the key source:vendor key programmed in nvr flash or new key in
                                   software */
    HSM_AesNewKeyInfType tNewKeyInf; /*!< when eUseKeyType is HSM_AES_KEY_NEW, this MUST configure */
    HSM_AesVendorKeyInfType tVendorKeyInf; /*!< when eUseKeyType is HSM_AES_KEY_CHIP_VENDOR_IFR,
                                              this MUST configure */
    HSM_SymmEnDecryptAlgType eAesAlg;      /*!< encrypt/decrypt mode */

    const hsm_uint32_t *pDataInput;       /*!< address should align with 4bytes */
    hsm_uint32_t        u32InputByteCnt;  /*!< 128bit(16Bytes) align */
    hsm_uint32_t       *pDataOutput;      /*!< address should align with 4bytes */
    hsm_uint32_t        u32OutputMemSize; /*!< the output data buffer "pDataOutput" size, should >=
                                             "u32InputByteCnt" */

    const hsm_uint32_t *pIvData; /*!< address should align with 4bytes, 128bit(16Bytes)
                                    iv(initialization vector) data array, ECB not need configure
                                    this */
} HSM_AesEnDecryptType;

/**
 * @brief Flexiable AES zero padding type for type "HSM_FlexAesPadType"
 * if input data is not aligned with 16bytes, this configuration will make append byte data 0 to
 * keep 16bytes align.
 */
#define HSM_FLEXAES_PAD_ZERO  0u

/**
 * @brief Flexiable AES PKCS7 padding type for type "HSM_FlexAesPadType"
 * if input data is not aligned with 16bytes, this configuration will make append bytes by PKCS7
 * method to keep 16bytes align.
 */
#define HSM_FLEXAES_PAD_PKCS7 1u

/**
 * @brief Flexiable AES padding type definition
 * if use zero padding, refer to HSM_FLEXAES_PAD_ZERO, after decrypt, user should remove the zero
 * manually if use PKCS7 padding, refer to HSM_FLEXAES_PAD_PKCS7
 */
typedef hsm_uint32_t HSM_FlexAesPadType;

/**
 * @brief Flex AES encrypt/decrypt information used by driver when call specific API
 *
 */
typedef struct
{
    HSM_AesKeyType eUseKeyType; /*!< the key source:vendor key programmed in nvr flash or new key in
                                   software */
    HSM_AesNewKeyInfType tNewKeyInf; /*!< when eUseKeyType is HSM_AES_KEY_NEW, this MUST configure */
    HSM_AesVendorKeyInfType tVendorKeyInf; /*!< when eUseKeyType is HSM_AES_KEY_CHIP_VENDOR_IFR,
                                              this MUST configure */
    HSM_SymmEnDecryptAlgType eAesAlg;      /*!< encrypt/decrypt mode */

    const hsm_uint8_t *pDataInput;       /*!< address should align with 4bytes */
    hsm_uint32_t       u32InputByteCnt;  /*!< 128bit(16Bytes) align */
    hsm_uint8_t       *pDataOutput;      /*!< address should align with 4bytes */
    hsm_uint32_t       u32OutputMemSize; /*!< the output data buffer "pDataOutput" size, should >=
                                            "u32InputByteCnt" */

    const hsm_uint8_t *pIvData; /*!< address should align with 4bytes, 128bit(16Bytes) iv(initialization
                                   vector) data array, ECB not need configure this */

    hsm_uint32_t *pGenerateOutByteCnt; /*!< point to the hsm_uint32_t variable to store the result
                                          byte count, can't be NULL_PTR */

    HSM_FlexAesPadType ePad; /*!< for encrypt, if data size not 16bytes aligned, the pad byte should
                               refer to this configuration, for decrypt, driver to process the
                               padding data according to this, however, if zero padding, driver will
                               not remove the padding 0, user should delete the data manually  */
    HSM_DataFormatType eInputFmt;  /*!< key/iv/input data organized format, hsm_uint8_t array, or
                                      hsm_uint32_t array */
    HSM_DataFormatType eOutputFmt; /*!< output result data format  */

} HSM_FlexAesEnDecryptType;

/**
 * @brief AES decrypt information used by driver when call specific API
 *
 */
typedef HSM_AesEnDecryptType HSM_AesEncryptType;

typedef struct
{
    HSM_MailboxApiRetType u32HSMStatusRet; /*!< HSM core write return status value in this */
    hsm_uint32_t u32Timeout; /*!< current command timeout Millisecond count, max 916000ms, if set to
                                0, means 1000ms */
    hsm_uint32_t u32UserKeyID; /*!< 0 means don't use key from HSM internal key space, otherwise
                                  would load key with KEYID from HSM */
    HSM_AesEncryptType tCfg;   /*!< aes parameters */
} HSMCom_AesEncryptType;
/* ------------------------------------------------------------------------------- */
/**
 * @brief AES encrypt information used by driver when call specific API
 *
 */
typedef HSM_AesEnDecryptType HSM_AesDecryptType;

typedef struct
{
    HSM_MailboxApiRetType u32HSMStatusRet; /*!< HSM core write return status value in this */
    hsm_uint32_t u32Timeout; /*!< current command timeout Millisecond count, max 916000ms, if set to
                                0, means 1000ms */
    hsm_uint32_t u32UserKeyID; /*!< 0 means don't use key from HSM internal key space, otherwise
                                  would load key with KEYID from HSM */
    HSM_AesDecryptType tCfg;   /*!< AES decrypt parameters */
} HSMCom_AesDecryptType;
/* ------------------------------------------------------------------------------- */

/**
 * @brief Flex AES decrypt information used by driver when call specific API
 *
 */
typedef HSM_FlexAesEnDecryptType HSM_FlexAesEncryptType;

typedef struct
{
    HSM_MailboxApiRetType u32HSMStatusRet; /*!< HSM core write return status value in this */
    hsm_uint32_t u32Timeout; /*!< current command timeout Millisecond count, max 916000ms, if set to
                                0, means 1000ms */
    hsm_uint32_t u32UserKeyID;   /*!< 0 means don't use key from HSM internal key space, otherwise
                                    would load key with KEYID from HSM */
    HSM_FlexAesEncryptType tCfg; /*!< aes parameters */
} HSMCom_FlexAesEncryptType;

/* ------------------------------------------------------------------------------- */
/**
 * @brief AES encrypt information used by driver when call specific API
 *
 */
typedef HSM_FlexAesEnDecryptType HSM_FlexAesDecryptType;

typedef struct
{
    HSM_MailboxApiRetType u32HSMStatusRet; /*!< HSM core write return status value in this */
    hsm_uint32_t u32Timeout; /*!< current command timeout Millisecond count, max 916000ms, if set to
                                0, means 1000ms */
    hsm_uint32_t u32UserKeyID;   /*!< 0 means don't use key from HSM internal key space, otherwise
                                    would load key with KEYID from HSM */
    HSM_FlexAesDecryptType tCfg; /*!< AES decrypt parameters */
} HSMCom_FlexAesDecryptType;

/**
 * @brief SM4 encrypt/decrypt information used by driver when call specific API
 *
 */
typedef struct
{
    HSM_Sm4KeyType eUseKeyType; /*!< the key source:vendor key programmed in nvr flash or new key in
                                   software */
    const hsm_uint32_t (*pKeyAddr)[4]; /*!< address is 4bytes aligned, when eUseKeyType is
                                          HSM_SM4_KEY_NEW, this MUST configure */
    HSM_SymmEnDecryptAlgType eSm4Alg;  /*!< SM4 encrypt/decrypt mode */

    const hsm_uint32_t *pDataInput;       /*!< address should align with 4bytes */
    hsm_uint32_t        u32InputByteCnt;  /*!< 128bit(16Bytes) align */
    hsm_uint32_t       *pDataOutput;      /*!< address should align with 4bytes */
    hsm_uint32_t        u32OutputMemSize; /*!< the output data buffer "pDataOutput" size, should >=
                                             "u32InputByteCnt" */

    const void *pIvData; /*!< address is 4bytes aligned, 128bit(16Bytes) iv(initialization vector)
                            data array, ECB not need configure this */
} HSM_Sm4EnDecryptType;

typedef struct
{
    HSM_MailboxApiRetType u32HSMStatusRet; /*!< HSM core write return status value in this */
    hsm_uint32_t u32Timeout; /*!< current command timeout Millisecond count, max 916000ms, if set to
                                0, means 1000ms */
    hsm_uint32_t u32UserKeyID; /*!< 0 means don't use key from HSM internal key space, otherwise
                                  would load key with KEYID from HSM */
    HSM_Sm4EnDecryptType tCfg; /*!< sm4 encrypt/decrypt parameters */
} HSMCom_Sm4EnDecryptType;

typedef HSMCom_Sm4EnDecryptType HSMCom_Sm4DecryptType;

typedef HSMCom_Sm4EnDecryptType HSMCom_Sm4EncryptType;

typedef struct
{
    HSMCom_Sm4EncryptType *pParam;
    hsm_uint32_t           u32Remain;
} HSMWrap_Sm4EncryptType;

typedef HSMCom_FlexAesEncryptType HSMCom_Sm4EncryptExType;
typedef HSMCom_FlexAesDecryptType HSMCom_Sm4DecryptExType;

typedef struct
{
    HSMCom_Sm4EncryptExType *pParam;
    hsm_uint32_t             u32Remain;
    HSM_FlexAesPadType       ePad;
    hsm_uint32_t             u32CurrentOutSize;
    hsm_uint32_t             u32OutAlreadyByteCnt;
    hsm_uint32_t            *pOutResultByteCnt;
} HSMWrap_Sm4EncryptExType;
/* ------------------------------------------------------------------------------- */

/**
 * @brief CMAC/XMAC information used by driver when call specific API
 *
 */

typedef struct
{
    HSM_AesKeyType eUseKeyType;      /*!< fix to HSM_AES_KEY_NEW */
    HSM_AesNewKeyInfType tNewKeyInf; /*!< when eUseKeyType is HSM_AES_KEY_NEW, this MUST configure */
    HSM_AesVendorKeyInfType tVendorKeyInf; /*!< when eUseKeyType is HSM_AES_KEY_CHIP_VENDOR_IFR,
                                              this MUST configure */
    hsm_uint32_t u32GenMacByteCnt; /*!< XCMAC API generate MAC data, it's "u32GenMacByteCnt" size
                                      ICV data */
    HSM_BoolType bCheckMacEn; /*!< if enable this check, user should place the data after the input
                                 data, hsm will check the generated data and it, if fail, hsm generate
                                 a interrupt, and if user get hw status, will get a error status */
    const hsm_uint32_t *pDataInput;      /*!< address should align with 4bytes */
    hsm_uint32_t        u32InputByteCnt; /*!< 128bit(16Bytes) align */
    hsm_uint32_t       *pDataOutput;     /*!< address should align with 4bytes */
    hsm_uint32_t u32OutputMemSize; /*!< 4bytes align, the output data buffer "pDataOutput" size,
                                      should >= "u32GenMacByteCnt" */
} HSM_XCMacType;

/**
 * @brief CMAC information used by driver when call specific API
 *
 */
typedef HSM_XCMacType HSM_CMacType;

typedef struct
{
    HSM_MailboxApiRetType u32HSMStatusRet; /*!< HSM core write return status value in this */
    hsm_uint32_t u32Timeout; /*!< current command timeout Millisecond count, max 916000ms, if set to
                                0, means 1000ms */
    hsm_uint32_t u32UserKeyID; /*!< 0 means don't use key from HSM internal key space, otherwise
                                  would load key with KEYID from HSM */
    HSM_CMacType tCfg;         /*!< CMAC parameters */
} HSMCom_CMacType;

#define HSM_XCMAC_ENGINE_SM4 1U
#define HSM_XCMAC_ENGINE_AES 0U
typedef hsm_uint32_t HSM_XCMacEngineType;

typedef struct
{
    HSM_AesKeyType eUseKeyType;      /*!< fix to HSM_AES_KEY_NEW */
    HSM_AesNewKeyInfType tNewKeyInf; /*!< when eUseKeyType is HSM_AES_KEY_NEW, this MUST configure */
    HSM_AesVendorKeyInfType tVendorKeyInf; /*!< when eUseKeyType is HSM_AES_KEY_CHIP_VENDOR_IFR,
                                              this MUST configure */
    hsm_uint32_t u32GenMacByteCnt; /*!< XCMAC API generate MAC data, it's "u32GenMacByteCnt" size
                                      ICV data */
    HSM_BoolType bCheckMacEn; /*!< if enable this check, user should place the data after the input
                                 data, hsm will check the generated data and it, if fail, hsm generate
                                 a interrupt, and if user get hw status, will get a error status */
    const hsm_uint32_t *pDataInput;      /*!< address should align with 4bytes */
    hsm_uint32_t        u32InputByteCnt; /*!< 128bit(16Bytes) align */
    hsm_uint32_t       *pDataOutput;     /*!< address should align with 4bytes */
    hsm_uint32_t u32OutputMemSize; /*!< 4bytes align, the output data buffer "pDataOutput" size,
                                      should >= "u32GenMacByteCnt" */
    HSM_DataFormatType  eInputFmt;
    HSM_DataFormatType  eOutputFmt;
    HSM_XCMacEngineType eEngine;
} HSM_XCMacExType;

typedef HSM_XCMacExType HSM_CMacExType;

typedef struct
{
    HSM_MailboxApiRetType u32HSMStatusRet; /*!< HSM core write return status value in this */
    hsm_uint32_t u32Timeout; /*!< current command timeout Millisecond count, max 916000ms, if set to
                                0, means 1000ms */
    hsm_uint32_t u32UserKeyID; /*!< 0 means don't use key from HSM internal key space, otherwise
                                  would load key with KEYID from HSM */
    HSM_CMacExType tCfg;       /*!< CMAC parameters */
} HSMCom_CMacExType;

/* ------------------------------------------------------------------------------- */
/**
 * @brief XMAC information used by driver when call specific API
 *
 */
typedef HSM_XCMacType HSM_XMacType;
typedef struct
{
    HSM_MailboxApiRetType u32HSMStatusRet; /*!< HSM core write return status value in this */
    hsm_uint32_t u32Timeout; /*!< current command timeout Millisecond count, max 916000ms, if set to
                                0, means 1000ms */
    hsm_uint32_t u32UserKeyID; /*!< 0 means don't use key from HSM internal key space, otherwise
                                  would load key with KEYID from HSM */
    HSM_XMacType tCfg;         /*!< XMAC parameter */
} HSMCom_XMacType;
/* ------------------------------------------------------------------------------- */
/**
 * @brief CCM Encrypt information used by driver when call specific API
 *
 */
typedef struct
{
    HSM_AesKeyType eUseKeyType; /*!< the key source:vendor key programmed in nvr flash or new key in
                                   software */
    HSM_AesNewKeyInfType tNewKeyInf; /*!< when eUseKeyType is HSM_AES_KEY_NEW, this MUST configure */
    HSM_AesVendorKeyInfType tVendorKeyInf; /*!< when eUseKeyType is HSM_AES_KEY_CHIP_VENDOR_IFR,
                                              this MUST configure */

    hsm_uint32_t *pAllData;     /*!< address should align with 4bytes, place AAD data(16bytes align)
                                   first, then input data */
    hsm_uint32_t u32AadByteCnt; /*!< the byte count contain the 2bytes in the head, it's the valid
                                   data size, not after aligned, 128bit(16Bytes) align, if not, only
                                   the aligned data treat as AAD, the left AAD bytes will be treated
                                   as input data  */
    hsm_uint32_t u32InputByteCnt; /*!< 128bit(16Bytes) align, ONLY represent data */

    hsm_uint32_t  u32GenMacByteCnt; /*!< output mac size */
    hsm_uint32_t *pDataOutput;      /*!< address should align with 4bytes */
    hsm_uint32_t  u32OutputMemSize; /*!< the output data buffer "pDataOutput" size, should >=
                                       "u32InputByteCnt" */

    const hsm_uint32_t *pIvData; /*!< address should align with 4bytes, all data 32bytes, iv data,
                                    consist of 16bytes B0 data, and 16bytes CTR,  MUST configure */
    hsm_uint32_t (*pMacOut)[4];  /*!< address should align with 4bytes, HSM generated MAC data */
    hsm_uint32_t (
        *pEmacOut)[4]; /*!< address should align with 4bytes, HSM generated encrypted MAC data */
} HSM_CcmEncryptType;

typedef struct
{
    HSM_MailboxApiRetType u32HSMStatusRet; /*!< HSM core write return status value in this */
    hsm_uint32_t u32Timeout; /*!< current command timeout Millisecond count, max 916000ms, if set to
                                0, means 1000ms */
    hsm_uint32_t u32UserKeyID; /*!< 0 means don't use key from HSM internal key space, otherwise
                                  would load key with KEYID from HSM */
    HSM_CcmEncryptType tCfg;   /*!< CCM encrypt parameters */
} HSMCom_CcmEncryptType;
/* ------------------------------------------------------------------------------- */
/**
 * @brief CCM Decrypt information used by driver when call specific API
 *
 */
typedef struct
{
    HSM_AesKeyType eUseKeyType; /*!< the key source:vendor key programmed in nvr flash or new key in
                                   software */
    HSM_AesNewKeyInfType tNewKeyInf; /*!< when eUseKeyType is HSM_AES_KEY_NEW, this MUST configure */
    HSM_AesVendorKeyInfType tVendorKeyInf; /*!< when eUseKeyType is HSM_AES_KEY_CHIP_VENDOR_IFR,
                                              this MUST configure */

    hsm_uint32_t *pAllData; /*!< address should align with 4bytes, place AAD data(if exist, 16bytes
                               align) first, then input data, then MAC data(if exist) */

    hsm_uint32_t u32AadByteCnt;   /*!< 128bit(16Bytes) align, if not, only the aligned data treat as
                                     AAD, the left AAD bytes will be treated as input data  */
    hsm_uint32_t u32InputByteCnt; /*!< 128bit(16Bytes) align */
    HSM_BoolType bCheckMacEn;     /*!< check the MAC data in input or not */
    hsm_uint32_t u32MacByteCnt;   /*!< 128bit(16Bytes) align */

    hsm_uint32_t *pDataOutput; /*!< address should align with 4bytes, point to the buffer that store
                                  the result */
    hsm_uint32_t u32OutputMemSize; /*!< the output data buffer "pDataOutput" size, should >=
                                      "u32InputByteCnt" */

    const hsm_uint32_t *pIvData; /*!< address should align with 4bytes, all data 32bytes, iv data,
                                    consist of 16bytes B0 data, and 16bytes CTR,  MUST configure */
} HSM_CcmDecryptType;

typedef struct
{
    HSM_MailboxApiRetType u32HSMStatusRet; /*!< HSM core write return status value in this */
    hsm_uint32_t u32Timeout; /*!< current command timeout Millisecond count, max 916000ms, if set to
                                0, means 1000ms */
    hsm_uint32_t u32UserKeyID; /*!< 0 means don't use key from HSM internal key space, otherwise
                                  would load key with KEYID from HSM */
    HSM_CcmDecryptType tCfg;   /*!< CCM decrypt parameter */
} HSMCom_CcmDecryptType;
/* ------------------------------------------------------------------------------- */
/**
 * @brief GCM Encrypt information used by driver when call specific API
 *
 */
typedef struct
{
    HSM_AesKeyType eUseKeyType; /*!< the key source:vendor key programmed in nvr flash or new key in
                                   software */
    HSM_AesNewKeyInfType tNewKeyInf; /*!< when eUseKeyType is HSM_AES_KEY_NEW, this MUST configure */
    HSM_AesVendorKeyInfType tVendorKeyInf; /*!< when eUseKeyType is HSM_AES_KEY_CHIP_VENDOR_IFR,
                                              this MUST configure */

    hsm_uint32_t *pAllData; /*!< address should align with 4bytes, place IV data first, then AAD
                               data(16bytes align), then input data */
    hsm_uint32_t u32IvDataByteCnt; /*!< 64bit(8Bytes) align, if not, only the aligned data treat as
                                      IV, the left IV bytes will be treated as AAD data  */
    hsm_uint32_t u32AadByteCnt;    /*!< 64bit(8Bytes) align, if not, only the aligned data treat as
                                      AAD, the left AAD bytes will be treated as input data  */
    hsm_uint32_t u32InputByteCnt;  /*!< 128bit(16Bytes) align */

    hsm_uint32_t  u32GenMacByteCnt; /*!< set the MAC result byte count */
    hsm_uint32_t *pDataOutput;      /*!< address should align with 4bytes */
    hsm_uint32_t  u32OutputMemSize; /*!< the output data buffer "pDataOutput" size, should >=
                                       "u32InputByteCnt" */
    hsm_uint32_t (*pMacOut)[4]; /*!< address should align with 4bytes, buffer address, this buffer
                                   store the result */
} HSM_GcmEncryptType;

typedef struct
{
    HSM_MailboxApiRetType u32HSMStatusRet; /*!< HSM core write return status value in this */
    hsm_uint32_t u32Timeout; /*!< current command timeout Millisecond count, max 916000ms, if set to
                                0, means 1000ms */
    hsm_uint32_t u32UserKeyID; /*!< 0 means don't use key from HSM internal key space, otherwise
                                  would load key with KEYID from HSM */
    HSM_GcmEncryptType tCfg;   /*!< GCM parameters */
} HSMCom_GcmEncryptType;
/* ------------------------------------------------------------------------------- */
/**
 * @brief GCM Decrypt information used by driver when call specific API
 *
 */
typedef struct
{
    HSM_AesKeyType eUseKeyType; /*!< the key source:vendor key programmed in nvr flash or new key in
                                   software */
    HSM_AesNewKeyInfType tNewKeyInf; /*!< when eUseKeyType is HSM_AES_KEY_NEW, this MUST configure */
    HSM_AesVendorKeyInfType tVendorKeyInf; /*!< when eUseKeyType is HSM_AES_KEY_CHIP_VENDOR_IFR,
                                              this MUST configure */

    hsm_uint32_t *pAllData; /*!< address should align with 4bytes, place IV data first, then AAD data(if
                               exist, 16bytes align), then input data, then MAC data(if exist) */
    hsm_uint32_t u32IvDataByteCnt; /*!< 64bit(8Bytes) align, if not, only the aligned data treat as
                                      IV, the left IV bytes will be treated as AAD data  */
    hsm_uint32_t u32AadByteCnt;    /*!< 64bit(8Bytes) align, if not, only the aligned data treat as
                                      AAD, the left AAD bytes will be treated as input data  */
    hsm_uint32_t u32InputByteCnt;  /*!< 128bit(16Bytes) align */
    HSM_BoolType bCheckMacEn;      /*!< check the MAC data in input or not */
    hsm_uint32_t u32MacByteCnt;    /*!< 128bit(16Bytes) align */

    hsm_uint32_t *pDataOutput; /*!< address should align with 4bytes, point to the buffer that store
                                  the result */
    hsm_uint32_t u32OutputMemSize; /*!< the output data buffer "pDataOutput" size, should >=
                                      "u32InputByteCnt" */
} HSM_GcmDecryptType;

typedef struct
{
    HSM_MailboxApiRetType u32HSMStatusRet; /*!< HSM core write return status value in this */
    hsm_uint32_t u32Timeout; /*!< current command timeout Millisecond count, max 916000ms, if set to
                                0, means 1000ms */
    hsm_uint32_t u32UserKeyID; /*!< 0 means don't use key from HSM internal key space, otherwise
                                  would load key with KEYID from HSM */
    HSM_GcmDecryptType tCfg;   /*!< GCM decrypt parameter */
} HSMCom_GcmDecryptType;
/* ------------------------------------------------------------------------------- */
/**
 * @brief MD5 context information used by driver when call specific API
 *
 */
typedef HSM_SmsCfgType HSM_Md5CtxType;

/**
 * @brief MD5 information used by driver when call specific API
 *
 */
typedef struct
{
    HSM_Md5CtxType tCfg;     /*!< MD5 algorithm parameter set by user */
    hsm_uint32_t (*pRet)[4]; /*!< address should align with 4bytes, point to the memory that driver
                                to store result */
} HSM_Md5Type;

typedef struct
{
    HSM_MailboxApiRetType u32HSMStatusRet; /*!< HSM core write return status value in this */
    hsm_uint32_t u32Timeout; /*!< current command timeout Millisecond count, max 916000ms, if set to
                                0, means 1000ms */
    HSM_Md5Type tCfg;
} HSMCom_Md5Type;

/**
 * @brief MD5 information used by driver when call specific API
 *
 */
typedef struct
{
    HSM_Md5CtxType tCfg;     /*!< MD5 algorithm parameter set by user */
    hsm_uint32_t (*pRet)[4]; /*!< address should align with 4bytes, point to the memory that driver
                                to store result */
    HSM_DataFormatType eInputFmt;
    HSM_DataFormatType eOutputFmt;
} HSM_Md5ExType;

typedef struct
{
    HSM_MailboxApiRetType u32HSMStatusRet; /*!< HSM core write return status value in this */
    hsm_uint32_t u32Timeout; /*!< current command timeout Millisecond count, max 916000ms, if set to
                                0, means 1000ms */
    HSM_Md5ExType tCfg;
} HSMCom_Md5ExType;

/* ------------------------------------------------------------------------------- */
/**
 * @brief SM3 context information used by driver when call specific API
 *
 */
typedef HSM_SmsCfgType HSM_Sm3CtxType;

/**
 * @brief SM3 information used by driver when call specific API
 *
 */
typedef struct
{
    HSM_Sm3CtxType tCfg;     /*!< sm3 algorithm parameter set by user */
    hsm_uint32_t (*pRet)[8]; /*!< address should align with 4bytes, point to the memory that driver
                                to store result */
} HSM_Sm3Type;

typedef struct
{
    HSM_MailboxApiRetType u32HSMStatusRet; /*!< HSM core write return status value in this */
    hsm_uint32_t u32Timeout; /*!< current command timeout Millisecond count, max 916000ms, if set to
                                0, means 1000ms */
    HSM_Sm3Type tCfg;
} HSMCom_Sm3Type;

typedef struct
{
    HSM_Sm3CtxType tCfg;     /*!< sm3 algorithm parameter set by user */
    hsm_uint32_t (*pRet)[8]; /*!< address should align with 4bytes, point to the memory that driver
                                to store result */
    HSM_DataFormatType eInputFmt;
    HSM_DataFormatType eOutputFmt;
} HSM_Sm3ExType;

typedef struct
{
    HSM_MailboxApiRetType u32HSMStatusRet; /*!< HSM core write return status value in this */
    hsm_uint32_t u32Timeout; /*!< current command timeout Millisecond count, max 916000ms, if set to
                                0, means 1000ms */
    HSM_Sm3ExType tCfg;
} HSMCom_Sm3ExType;

/* ------------------------------------------------------------------------------- */
typedef struct
{
    HSM_MailboxApiRetType u32HSMStatusRet; /*!< HSM core write return status value in this */
    hsm_uint32_t u32Timeout; /*!< current command timeout Millisecond count, max 916000ms, if set to
                                0, means 1000ms */
    hsm_uint32_t u32MonotonicIndex; /*!< range 0-13 */
    hsm_uint32_t u32CurrentValue;   /*!< store the monotonic counter value */
} HSMCom_MonCountType;
/* ------------------------------------------------------------------------------- */
/**
 * @brief RSA information used by driver when call specific API
 *
 */
typedef struct
{
    const hsm_uint32_t *pInputData; /*!< address is 4bytes aligned, input data, if not 64bytes align,
                                       the last uint64_t's high byte left to patch 0 to align */
    hsm_uint32_t u32InputDataByteCount; /*!< the byte count of input data */

    const hsm_uint32_t *pKey_E; /*!< address is 4bytes aligned, input key E data for "A = (input
                                   data)^E mod N", if not 64bytes align, the last uint64_t's high
                                   byte left to patch 0 to align */
    hsm_uint32_t u32Key_E_ByteCount; /*!< the byte count of key E */

    const hsm_uint32_t *pKey_N; /*!< address is 4bytes aligned, input key N data for "A = (input
                                   data)^E mod N", if not 64bytes align, the last uint64_t's high
                                   byte left to patch 0 to align */
    hsm_uint32_t u32Key_N_ByteCount; /*!< hw will get the actual key data bit count according to the
                                        non-zero bit count, it means key not generate by multiply 2 */

    hsm_uint32_t *pResult; /*!< address is 4bytes aligned, output buffer, the buffer size should >=
                              "u32Key_N_ByteCount" */
    hsm_uint32_t u32ResultBufByteCnt; /*!< the result buffer size */
} HSM_RsaType;

typedef struct
{
    HSM_MailboxApiRetType u32HSMStatusRet; /*!< HSM core write return status value in this */
    hsm_uint32_t u32Timeout; /*!< current command timeout Millisecond count, max 916000ms, if set to
                                0, means 1000ms */
    hsm_uint32_t u32UserKeyID_KEY_E; /*!< means don't load key from HSM, otherwise would load key
                                        with KEYID from HSM */
    hsm_uint32_t u32UserKeyID_KEY_N; /*!< means don't load key from HSM, otherwise would load key
                                        with KEYID from HSM */
    hsm_uint32_t u32RsaBitCnt;       /*!< the bit count of numbers used in RSA */
    HSM_RsaType  tCfg;               /*!< RSA parameters */
} HSMCom_RsaType;
/* ------------------------------------------------------------------------------- */
#define HSM_BIGNUMBER_CALC_A_ADD_B 0xFC730002
#define HSM_BIGNUMBER_CALC_A_SUB_B 0xFC730003
#define HSM_BIGNUMBER_CALC_B_SUB_A 0xFC730004
#define HSM_BIGNUMBER_CALC_A_MUL_B 0xFC730005
#define HSM_BIGNUMBER_CALC_A_EXP_E 0xFC730006
#define HSM_BIGNUMBER_CALC_A_RED_N 0xFC730007
#define HSM_BIGNUMBER_CALC_A_INV   0xFC730008

/**
 * @brief RSA information used by driver when call specific API
 *
 */
typedef struct
{
    const hsm_uint8_t *pA; /*!< address is 4bytes aligned, input data, if not 64bytes align, the
                              last uint64_t's high byte left to patch 0 to align */
    hsm_uint32_t u32AByteCount; /*!< the byte count of input data */

    const hsm_uint8_t *pE; /*!< address is 4bytes aligned, input key E data for "A = (input data)^E
                              mod N", if not 64bytes align, the last uint64_t's high byte left to
                              patch 0 to align */
    hsm_uint32_t u32EByteCount; /*!< the byte count of key E */

    const hsm_uint8_t *pN; /*!< address is 4bytes aligned, input key N data for "A = (input data)^E
                              mod N", if not 64bytes align, the last uint64_t's high byte left to
                              patch 0 to align */
    hsm_uint32_t u32NByteCount; /*!< hw will get the actual key data bit count according to the
                                   non-zero bit count, it means key not generate by multiply 2 */

    hsm_uint8_t *pResult; /*!< address is 4bytes aligned, output buffer, the buffer size should >=
                             "u32Key_N_ByteCount" */
    hsm_uint32_t u32ResultBufByteCnt; /*!< the result buffer size */

    hsm_uint32_t       u32CalcType;
    const hsm_uint8_t *pB;
    hsm_uint32_t       u32BByteCount;
} HSM_BigNumberCalcType;

typedef struct
{
    HSM_MailboxApiRetType u32HSMStatusRet; /*!< HSM core write return status value in this */
    hsm_uint32_t u32Timeout; /*!< current command timeout Millisecond count, max 916000ms, if set to
                                0, means 1000ms */
    hsm_uint32_t u32UserKeyID_KEY_E; /*!< means don't load key from HSM, otherwise would load key
                                        with KEYID from HSM */
    hsm_uint32_t u32UserKeyID_KEY_N; /*!< means don't load key from HSM, otherwise would load key
                                        with KEYID from HSM */
    hsm_uint32_t          u32BitCnt; /*!< the bit count of numbers used of N */
    HSM_BigNumberCalcType tCfg;      /*!< RSA parameters */
} HSMCom_BigNumberCalcType;

#define HSM_BN_VALID_FLAG_E 0x1u
#define HSM_BN_VALID_FLAG_B 0x2u

typedef struct
{
    const hsm_uint8_t *pA; /*!< address is 4bytes aligned, input data, if not 64bytes align, the
                              last uint64_t's high byte left to patch 0 to align */
    hsm_uint32_t u32AByteCount; /*!< the byte count of input data */

    const hsm_uint8_t *pE; /*!< address is 4bytes aligned, input key E data for "A = (input data)^E
                              mod N", if not 64bytes align, the last uint64_t's high byte left to
                              patch 0 to align */
    hsm_uint32_t u32EByteCount; /*!< the byte count of key E */

    const hsm_uint8_t *pN; /*!< address is 4bytes aligned, input key N data for "A = (input data)^E
                              mod N", if not 64bytes align, the last uint64_t's high byte left to
                              patch 0 to align */
    hsm_uint32_t u32NByteCount; /*!< hw will get the actual key data bit count according to the
                                   non-zero bit count, it means key not generate by multiply 2 */

    hsm_uint8_t *pResult; /*!< address is 4bytes aligned, output buffer, the buffer size should >=
                             "u32Key_N_ByteCount" */
    hsm_uint32_t u32ResultBufByteCnt; /*!< the result buffer size */

    hsm_uint32_t       u32CalcType;
    const hsm_uint8_t *pB;
    hsm_uint32_t       u32BByteCount;

    hsm_uint32_t       u32DataValidFlag;
    HSM_DataFormatType eInputDataFmt;
    HSM_DataFormatType eKeyEFmt;
    HSM_DataFormatType eKeyNFmt;
    HSM_DataFormatType eOutputFmt;
    hsm_uint32_t      *pResultByteCount;
} HSM_BigNumberCalcExtType;

typedef struct
{
    HSM_MailboxApiRetType u32HSMStatusRet; /*!< HSM core write return status value in this */
    hsm_uint32_t u32Timeout; /*!< current command timeout Millisecond count, max 916000ms, if set to
                                0, means 1000ms */
    hsm_uint32_t u32UserKeyID_KEY_E;    /*!< means don't load key from HSM, otherwise would load key
                                           with KEYID from HSM */
    hsm_uint32_t u32UserKeyID_KEY_N;    /*!< means don't load key from HSM, otherwise would load key
                                           with KEYID from HSM */
    hsm_uint32_t             u32BitCnt; /*!< the bit count of numbers used of N */
    HSM_BigNumberCalcExtType tCfg;      /*!< RSA parameters */
} HSMCom_BigNumberCalcExtType;

/* ------------------------------------------------------------------------------- */
typedef struct
{
    HSM_MailboxApiRetType u32HSMStatusRet; /*!< HSM core write return status value in this */
    hsm_uint32_t u32Timeout; /*!< current command timeout Millisecond count, max 916000ms, if set to
                                0, means 1000ms */
} HSMCom_LoadFirmwareType;

/* ------------------------------------------------------------------------------- */

/* #define AUTH_CHECK_DATA_BYTE_CNT 32 */

typedef struct
{
    hsm_uint32_t        u32HSMStatusRet;
    hsm_uint32_t        u32Timeout;
    const hsm_uint32_t *pkG_x; /*!< address should align with 4bytes */
    const hsm_uint32_t *pkG_y; /*!< address should align with 4bytes */
    const hsm_uint32_t *pR;    /*!< address should align with 4bytes */
    const hsm_uint32_t *pS;    /*!< address should align with 4bytes */
    /* For user code verify function */
    const hsm_uint32_t *pData; /*!< address should align with 4bytes */
    hsm_uint32_t        u32DataLength;
} HSMCom_AuthCheckType;

/* ------------------------------------------------------------------------------- */
typedef struct
{
    hsm_uint32_t key_type;
    hsm_uint32_t key_sel;
    void        *key_addr; /* addr */
} HSM_AESM_CFG_KEY_CFG_T;

typedef struct
{
    HSM_AESM_CFG_KEY_CFG_T *key_cfg; /* addr */
    hsm_uint32_t            key_cfg_en;
    hsm_uint32_t            aes_mode;
    hsm_uint32_t            aes_as;
    hsm_uint32_t            enc_dec;
    hsm_uint32_t            eng_sel;
    hsm_uint32_t            mst_en;
    hsm_uint32_t            icv_en;
    hsm_uint32_t            data_len;
    hsm_uint32_t            icv_len;
    hsm_uint32_t            aad_len;
    const void             *in_addr;  /* addr */
    void                   *out_addr; /* addr */
    const void             *iv_addr;  /* addr */
    hsm_uint32_t            dbg_wait;
    hsm_uint32_t            iv_len;
} HSM_AESM_ENTRY_CFG_T;

typedef struct
{
    HSM_AESM_ENTRY_CFG_T   tCfg;
    HSM_AESM_CFG_KEY_CFG_T tKeyCfg;
    hsm_uint32_t (*pCtx1)[16]; /* context 1 has 64bytes */
} HSM_AesmRawApiType;

typedef struct
{
    hsm_uint32_t u32HSMStatusRet;
    hsm_uint32_t u32Timeout;
    hsm_uint32_t u32UserKeyID; /* 0 means don't load key from HSM, otherwise would load key with
                                  KEYID from HSM */
    HSM_AesmRawApiType tCfg;
} HSMCom_AesmRawApiType;

/**
 * @brief RSA SSA input data is the raw message for HSM_RsaSsaInputType
 *
 */
#define HSM_RSA_SSA_INPUT_RAW_MESSAGE 0u

/**
 * @brief RSA SSA input data is the hash value of raw message for HSM_RsaSsaInputType
 *
 */
#define HSM_RSA_SSA_INPUT_HASH_DATA   1u

/**
 * @brief type definition for rsa ssa input data type
 * refer to HSM_RSA_SSA_INPUT_RAW_MESSAGE, HSM_RSA_SSA_INPUT_HASH_DATA
 */
typedef hsm_uint32_t HSM_RsaSsaInputType;

/**
 * @brief MD5 algorithm value for type "HSM_HashAlgType"
 *
 */
#define HSM_HASH_MD5         (0U)

/**
 * @brief SHA160 algorithm value for type "HSM_HashAlgType"
 *
 */
#define HSM_HASH_SHA_160     (1U)

/**
 * @brief SHA224 algorithm value for type "HSM_HashAlgType"
 *
 */
#define HSM_HASH_SHA_224     (2U)

/**
 * @brief SHA256 algorithm value for type "HSM_HashAlgType"
 *
 */
#define HSM_HASH_SHA_256     (3U)

/**
 * @brief SHA384 algorithm value for type "HSM_HashAlgType"
 *
 */
#define HSM_HASH_SHA_384     (4U)

/**
 * @brief SHA512 algorithm value for type "HSM_HashAlgType"
 *
 */
#define HSM_HASH_SHA_512     (5U)

/**
 * @brief SHA512/224 algorithm value for type "HSM_HashAlgType"
 *
 */
#define HSM_HASH_SHA_512_224 (6U)

/**
 * @brief SHA512/256 algorithm value for type "HSM_HashAlgType"
 *
 */
#define HSM_HASH_SHA_512_256 (7U)

/**
 * @brief SM3 algorithm value for type "HSM_HashAlgType"
 *
 */
#define HSM_HASH_SM3         (8U)
/**
 * @brief type definition for SHA algorithm
 * refer to
 * HSM_SHA_160,HSM_SHA_224,HSM_SHA_256,HSM_SHA_384,HSM_SHA_512,HSM_SHA_512_224,HSM_SHA_512_256,HSM_HASH_MD5,HSM_HASH_SM3
 */
typedef hsm_uint32_t HSM_HashAlgType;

/**
 * @brief RSA PSS signature verify information used by driver when call specific API
 *
 */
typedef struct
{
    hsm_uint32_t u32EmBitCnt;      /* RFC8017 require set it to (N's bit count - 1). the em data bit
                                      count, it MUST < N's bit count, should keep same with the signature
                                      generate configuration */
    HSM_HashAlgType eMgfHashType;  /*!< the hash type used by signature */
    HSM_HashAlgType eHashType;     /*!< the hash type used by signature */
    hsm_uint32_t u32SaltByteCount; /*!< the byte count of salt data, it must > 0, suggest use hash
                                      length, for example, if eHashType is HSM_SHA_256, set this to
                                      256/8=32bytes */

    HSM_DataFormatType eInputDataFmt; /*!< input data(raw message or hash data) organized format,
                                         hsm_uint8_t array, or hsm_uint32_t array */
    HSM_RsaSsaInputType eInputType; /*!< input data type, may raw input message, or the hash data of
                                       raw message */
    const hsm_uint8_t *pInputData;  /*!< input data */
    hsm_uint32_t u32InputDataByteCount; /*!< the byte count of input data, when the eInputType is
                                           HSM_RSA_SSA_INPUT_RAW_MESSAGE */

    HSM_DataFormatType eSignDataFmt; /*!< Signature/Public key/N input data organized format,
                                        hsm_uint8_t array, or hsm_uint32_t array */
    const hsm_uint8_t *pSignData;    /*!< input signature data */
    hsm_uint32_t       u32SignDataByteCount; /*!< the byte count of signature data, it must > 0 */

    HSM_DataFormatType ePublicKeyDataFmt;
    const hsm_uint8_t *pPublicKey; /*!< public key, input key E data for "A = (input data)^E mod N" */
    hsm_uint32_t u32PublicKeyByteCnt; /*!< the byte count of key E */

    HSM_DataFormatType eKeyNDataFmt;
    const hsm_uint8_t *pKeyN;            /*!< input key N data for "A = (input data)^E mod N" */
    hsm_uint32_t       u32KeyNByteCount; /*!< key N data byte count */
} HSM_RsaSsaPssVerifyType;

typedef struct
{
    HSM_MailboxApiRetType u32HSMStatusRet; /*!< HSM core write return status value in this */
    hsm_uint32_t u32Timeout; /*!< current command timeout Millisecond count, max 916000ms, if set to
                                0, means 1000ms */
    hsm_uint32_t u32UserKeyID_KEY_E; /*!< means don't load key from HSM, otherwise would load key
                                        with KEYID from HSM */
    hsm_uint32_t u32UserKeyID_KEY_N; /*!< means don't load key from HSM, otherwise would load key
                                        with KEYID from HSM */
    hsm_uint32_t            u32RsaBitCnt; /*!< the bit count of numbers used in RSA */
    HSM_RsaSsaPssVerifyType tCfg;         /*!< RSA parameters */
} HSMCom_RsaSsaPssVerifyType;

/**
 * @brief RSA PKCS1V1.5 signature verify information used by driver when call specific API
 *
 */
typedef struct
{
    HSM_DataFormatType eInputFmt; /*!< input data organized format, hsm_uint8_t array, or
                                     hsm_uint32_t array */

    hsm_uint32_t u32EmByteCnt; /*!< set it 0 to use default value. RFC8017 require set it to N'byte
                                  count, equal to u32KeyNByteCount. the em data byte count, itx8
                                  MUST < N's bit count, should keep same with the signature generate
                                  configuration */

    HSM_HashAlgType eHashType; /*!< the hash type used by signature */

    const hsm_uint8_t *pInputData;            /*!< input data */
    hsm_uint32_t       u32InputDataByteCount; /*!< the byte count of input data */

    const hsm_uint8_t *pSignData;            /*!< input signature data */
    hsm_uint32_t       u32SignDataByteCount; /*!< the byte count of signature data, it must > 0 */

    const hsm_uint8_t *pPublicKey; /*!< public key, input key E data for "A = (input data)^E mod N" */
    hsm_uint32_t u32PublicKeyByteCnt; /*!< the byte count of key E */

    HSM_BoolType bUseInputDer;    /*!< set to HSM_TRUE when RFC8017 not support some hash algorithm,
                                     for example SM3 Hash type, DER encoding of the DigestInfo value,
                                     if use hsm internal data, just set it to HSM_FALSE */
    const hsm_uint8_t *pDer;      /*!< when bUseInputDer is HSM_TRUE, this field point to the DER
                                     encoding of the DigestInfo value, others, ignore */
    hsm_uint32_t u32DerByteCount; /*!< when bUseInputDer is HSM_TRUE, this field represent the byte
                                     count of DER data,  if bUseInputDer is HSM_FALSE, ignore this field */

    const hsm_uint8_t *pKeyN;            /*!< input key N data for "A = (input data)^E mod N" */
    hsm_uint32_t       u32KeyNByteCount; /*!< key N's data byte count */

    HSM_RsaSsaInputType eInputType;
    HSM_DataFormatType  eSignDataFmt;
    HSM_DataFormatType  ePublicKeyFmt;
    HSM_DataFormatType  eKeyNFmt;
} HSM_RsaSsaPkcs1V15VerifyType;

typedef struct
{
    HSM_MailboxApiRetType u32HSMStatusRet; /*!< HSM core write return status value in this */
    hsm_uint32_t u32Timeout; /*!< current command timeout Millisecond count, max 916000ms, if set to
                                0, means 1000ms */
    hsm_uint32_t u32UserKeyID_KEY_E; /*!< means don't load key from HSM, otherwise would load key
                                        with KEYID from HSM */
    hsm_uint32_t u32UserKeyID_KEY_N; /*!< means don't load key from HSM, otherwise would load key
                                        with KEYID from HSM */
    hsm_uint32_t                 u32RsaBitCnt; /*!< the bit count of numbers used in RSA */
    HSM_RsaSsaPkcs1V15VerifyType tCfg;         /*!< RSA parameters */
} HSMCom_RsaSsaPkcs1V15VerifyType;

typedef struct
{
    HSM_BoolType bUsePseudoRand;

    HSM_HashAlgType eMgfHashType; /*!< the hash type used by MGF1 */
    HSM_DataFormatType eInputFmt; /*!< input data organized format, uint8_t array, or uint32_t array */
    HSM_DataFormatType eOutputFmt; /*!< output data organized format, uint8_t array, or uint32_t array */

    hsm_uint32_t u32EmBitCnt; /* RFC8017 require set it to (N's bit count - 1).the em data bit
                                 count, it MUST < N's bit count */

    HSM_HashAlgType     eHashType;  /*!< the hash type used by signature */
    HSM_RsaSsaInputType eInputType; /*!< input data type, may raw input message, or the hash data of
                                       raw message */
    const hsm_uint8_t *pInputData;  /*!< input data */
    hsm_uint32_t       u32InputDataByteCount; /*!< the byte count of input data */

    const hsm_uint8_t *pPrivateKey; /*!< private key, input key E data for "A = (input data)^E mod N" */
    hsm_uint32_t u32PrivateKeyByteCnt; /*!< the byte count of key E */

    HSM_BoolType bUseInputSaltData; /*!< use input salt data or not, , suggest set to HSM_FALSE to
                                       use internal random data */
    const hsm_uint8_t *pSalt;       /*!< input salt data, , suggest set to NULL. if use hsm internal
                                       random data, just set it to NULL */
    hsm_uint32_t u32SaltByteCount;  /*!< the byte count of salt data, it must > 0, suggest use hash
                                       length, for example, if eHashType is HSM_SHA_256, set this to
                                       256/8=32bytes */

    const hsm_uint8_t *pKeyN;            /*!< input key N data for "A = (input data)^E mod N" */
    hsm_uint32_t       u32KeyNByteCount; /*!< key N's data byte count */

    hsm_uint8_t  *pResult; /*!< output buffer, the buffer size should >= "u32KeyNByteCount" */
    hsm_uint32_t  u32ResultBufByteCnt; /*!< the result buffer size */
    hsm_uint32_t *pResultByteCnt;      /*!< the result data byte count */
} HSM_RsaSsaPssSignType;

typedef struct
{
    hsm_uint32_t u32HSMStatusRet;
    hsm_uint32_t u32Timeout;
    hsm_uint32_t u32UserKeyID_KEY_E; /* 0 means don't load key from HSM, otherwise would load key
                                        with KEYID from HSM */
    hsm_uint32_t u32UserKeyID_KEY_N; /* 0 means don't load key from HSM, otherwise would load key
                                        with KEYID from HSM */
    hsm_uint32_t          u32RsaBitCnt;
    HSM_RsaSsaPssSignType tCfg;
} HSMCom_RsaSsaPssSignType;

/**
 * @brief RSA PKCS1 V1.5 signature information used by driver when call specific API
 *
 */
typedef struct
{
    HSM_DataFormatType eInputFmt; /*!< input data organized format, uint8_t array, or uint32_t array */
    HSM_DataFormatType eOutputFmt; /*!< output data organized format, uint8_t array, or uint32_t array */

    hsm_uint32_t u32EmByteCnt; /* RFC8017 require set it to N'byte count, equal to u32KeyNByteCount.
                                  the em data byte count, itx8 MUST < N's bit count, should keep
                                  same with the signature generate configuration */

    HSM_HashAlgType eHashType; /*!< the hash type used by signature */

    const hsm_uint8_t *pInputData;            /*!< input data */
    hsm_uint32_t       u32InputDataByteCount; /*!< the byte count of input data */

    const hsm_uint8_t *pPrivateKey; /*!< private key, input key E data for "A = (input data)^E mod N" */
    hsm_uint32_t u32PrivateKeyByteCnt; /*!< the byte count of key E */

    HSM_BoolType bUseInputDer;    /*!< set to HSM_TRUE when RFC8017 not support some hash algorithm,
                                     for example SM3 Hash type, DER encoding of the DigestInfo value,
                                     if use hsm internal data, just set it to HSM_FALSE */
    const hsm_uint8_t *pDer;      /*!< when bUseInputDer is HSM_TRUE, this field point to the DER
                                     encoding of the DigestInfo value, others, ignore */
    hsm_uint32_t u32DerByteCount; /*!< when bUseInputDer is HSM_TRUE, this field represent the byte
                                     count of DER data,  if bUseInputDer is HSM_FALSE, ignore this field */

    const hsm_uint8_t *pKeyN;            /*!< input key N data for "A = (input data)^E mod N" */
    hsm_uint32_t       u32KeyNByteCount; /*!< key N's data byte count */

    hsm_uint8_t  *pResult; /*!< output buffer, the buffer size should >= "u32KeyNByteCount" */
    hsm_uint32_t  u32ResultBufByteCnt; /*!< the result buffer size */
    hsm_uint32_t *pResultByteCnt;      /*!< the result data byte count */

    HSM_RsaSsaInputType eInputType; /*!< input data type, may raw input message, or the hash data of
                                       raw message */
} HSM_RsaSsaPkcs1V15SignType;

typedef struct
{
    hsm_uint32_t u32HSMStatusRet;
    hsm_uint32_t u32Timeout;
    hsm_uint32_t u32UserKeyID_KEY_E; /* 0 means don't load key from HSM, otherwise would load key
                                        with KEYID from HSM */
    hsm_uint32_t u32UserKeyID_KEY_N; /* 0 means don't load key from HSM, otherwise would load key
                                        with KEYID from HSM */
    hsm_uint32_t               u32RsaBitCnt;
    HSM_RsaSsaPkcs1V15SignType tCfg;
} HSMCom_RsaSsaPkcs1v15SignType;

#if ((FC7XXX_HSM_SUBSYSTEM_TYPE == FC7240_HSM_SUBSYSTEM) || \
     (FC7XXX_HSM_SUBSYSTEM_TYPE == FC7300_HSM_SUBSYSTEM))
#else

#define KEYMANAGER_STATUS_OK              (0u)
#define KEYMANAGER_STATUS_AGAIN           (1u)
#define KEYMANAGER_STATUS_DONE            (2u)
#define KEYMANAGER_STATUS_EXIT            (3u)
#define KEYMANAGER_STATUS_IDLE            (4u)
#define KEYMANAGER_STATUS_PENDING         (5u)
#define KEYMANAGER_STATUS_SUCCESS         (6u)
#define KEYMANAGER_STATUS_ERROR           (7u)
#define KEYMANAGER_STATUS_ID_ERROR        (8u)
#define KEYMANAGER_STATUS_CONSIST_ERROR   (9u)
#define KEYMANAGER_STATUS_SEQUENCE_ERROR  (10u)
#define KEYMANAGER_STATUS_FLASH_ERROR     (11u)
#define KEYMANAGER_STATUS_PARAM_ERROR     (12u)
#define KEYMANAGER_STATUS_SPACE_ERROR     (13u)
#define KEYMANAGER_STATUS_REVOKE_ERROR    (14u)
#define KEYMANAGER_STATUS_ECC_ERROR       (15u)
#define KEYMANAGER_STATUS_INTEGRITY_ERROR (16u)
#define KEYMANAGER_STATUS_AUTHORITY_ERROR (17u)
#define KEYMANAGER_STATUS_BUSY            (18u)

#endif

typedef struct
{
    uint32_t              u32HSMStatusRet;
    uint32_t              u32Timeout;
    HSM_HashAlgType       eAlg;
    HSM_ShaResultBufType *pResult;
} HSMCom_GetRomHashType;

typedef struct
{
    HSM_MailboxApiRetType u32HSMStatusRet; /*!< HSM core write return status value in this */
    hsm_uint32_t u32Timeout; /*!< current command timeout Millisecond count, max 916000ms, if set to
                                0, means 1000ms */
} HSMCom_LifeCycleTakeEffectType;

/**@}*/

/**
 * @name API declaration for HSM
 *
 */
/**@{*/

/**
 * @brief Get the true random data from TRNG 0
 * @note suggest use HSM_TrueRandGetSrcShiftXor to get true random fast
 *
 * @param pCmd  point to the struct variable used to configure the mailbox information send to HSM
 * core
 * @param pCfg  the struct variable address to store the result
 * @return HSM_StatusType HSM_StatusType HSM_STATUS_SUCCESS when succeed. HSM_STATUS_PARAM_ERR,
 * parameter error.
 */
HSM_StatusType HSM_TrueRandGetSrc0(HSM_CmdType *pCmd, const HSMCom_TrueRandType *pCfg);

/**
 * @brief Get the true random data from TRNG 1
 * @note suggest use HSM_TrueRandGetSrcShiftXor to get true random fast
 *
 * @param pCmd  point to the struct variable used to configure the mailbox information send to HSM
 * core
 * @param pCfg  the struct variable address to store the result
 * @return HSM_StatusType HSM_StatusType HSM_STATUS_SUCCESS when succeed. HSM_STATUS_PARAM_ERR,
 * parameter error.
 */
HSM_StatusType HSM_TrueRandGetSrc1(HSM_CmdType *pCmd, const HSMCom_TrueRandType *pCfg);

/**
 * @brief Get the true random data from (TRNG 0 xor TRNG 1)
 * @note suggest use HSM_TrueRandGetSrcShiftXor to get true random fast
 *
 * @param pCmd  point to the struct variable used to configure the mailbox information send to HSM
 * core
 * @param pCfg  the struct variable address to store the result
 * @return HSM_StatusType HSM_StatusType HSM_STATUS_SUCCESS when succeed. HSM_STATUS_PARAM_ERR,
 * parameter error.
 */
HSM_StatusType HSM_TrueRandGetSrcXor(HSM_CmdType *pCmd, const HSMCom_TrueRandType *pCfg);

/**
 * @brief Get the random data from ((TRNG 0 << 1) xor TRNG 1)
 *
 * @param pCmd  point to the struct variable used to configure the mailbox information send to HSM
 * core
 * @param pCfg  the struct variable address to store the result
 * @return HSM_StatusType HSM_StatusType HSM_STATUS_SUCCESS when succeed. HSM_STATUS_PARAM_ERR,
 * parameter error.
 */
HSM_StatusType HSM_TrueRandGetSrcShiftXor(HSM_CmdType *pCmd, const HSMCom_TrueRandType *pCfg);

/**
 * @brief Get the random data from TRNG 0 or TRNG 1
 * @note suggest use HSM_TrueRandGetSrcShiftXor to get true random fast
 *
 * @param pCmd  point to the struct variable used to configure the mailbox information send to HSM
 * core
 * @param pCfg  the struct variable address to store the result
 * @return HSM_StatusType HSM_StatusType HSM_STATUS_SUCCESS when succeed. HSM_STATUS_PARAM_ERR,
 * parameter error.
 */
HSM_StatusType HSM_TrueRandGet(HSM_CmdType *pCmd, const HSMCom_TrueRandExType *pCfg);

/**
 * @brief Get the random data from any TRNG
 * @note suggest use HSM_TrueRandGetSrcShiftXor to get true random fast
 *
 * @param pCmd  point to the struct variable used to configure the mailbox information send to HSM
 * core
 * @param pCfg  the struct variable address to store the result
 * @return HSM_StatusType HSM_StatusType HSM_STATUS_SUCCESS when succeed. HSM_STATUS_PARAM_ERR,
 * parameter error.
 */
HSM_StatusType HSM_TrueRandGetAny(HSM_CmdType *pCmd, const HSMCom_TrueRandType *pCfg);

/**
 * @brief Get the fast trng result
 *
 * @param pCmd  point to the struct variable used to configure the mailbox information send to HSM
 * core
 * @param pCfg  the struct variable address to store the result
 * @return HSM_StatusType HSM_StatusType HSM_STATUS_SUCCESS when succeed. HSM_STATUS_PARAM_ERR,
 * parameter error.
 */
HSM_StatusType HSM_FastTrueRandGet(HSM_CmdType *pCmd, const HSMCom_FastTrueRandType *pCfg);

/**
 * @brief SHA
 *
 * @param pCmd  point to the struct variable used to configure the mailbox information send to HSM
 * core
 * @param pCfg  the struct variable address to store the result
 * @return HSM_StatusType HSM_StatusType HSM_STATUS_SUCCESS when succeed. HSM_STATUS_PARAM_ERR,
 * parameter error.
 */
HSM_StatusType HSM_Sha(HSM_CmdType *pCmd, const HSMCom_ShaType *pCfg);

/**
 * @brief SHA Extend
 *
 * @param pCmd  point to the struct variable used to configure the mailbox information send to HSM
 * core
 * @param pCfg  the struct variable address to store the result
 * @return HSM_StatusType HSM_StatusType HSM_STATUS_SUCCESS when succeed. HSM_STATUS_PARAM_ERR,
 * parameter error.
 */
HSM_StatusType HSM_FW_ShaEx(HSM_CmdType *pCmd, const HSMCom_ShaExType *pCfg, HSM_BoolType bKeyUseId);

/**
 * @brief ECC Verify
 *
 * @param pCmd  point to the struct variable used to configure the mailbox information send to HSM
 * core
 * @param pCfg  the struct variable address to store the result
 * @return HSM_StatusType HSM_StatusType HSM_STATUS_SUCCESS when succeed. HSM_STATUS_PARAM_ERR,
 * parameter error.
 */
HSM_StatusType HSM_EccVerify(HSM_CmdType *pCmd, const HSMCom_EccVerifyType *pCfg);

/**
 * @brief ECC calculate Externd
 *
 * @param pCmd  point to the struct variable used to configure the mailbox information send to HSM
 * core
 * @param pCfg  the struct variable address to store the result
 * @return HSM_StatusType HSM_StatusType HSM_STATUS_SUCCESS when succeed. HSM_STATUS_PARAM_ERR,
 * parameter error.
 */
HSM_StatusType HSM_EccCalculateEx(HSM_CmdType *pCmd, const HSMCom_EccCalcType *pCfg);

/**
 * @brief SM2 decrypt
 *
 * @param pCmd  point to the struct variable used to configure the mailbox information send to HSM
 * core
 * @param pCfg  the struct variable address to store the result
 * @return HSM_StatusType HSM_StatusType HSM_STATUS_SUCCESS when succeed. HSM_STATUS_PARAM_ERR,
 * parameter error.
 */
HSM_StatusType HSM_Sm2Decry(HSM_CmdType *pCmd, const HSMCom_Sm2DecryptType *pCfg);

/**
 * @brief SM2 verify
 *
 * @param pCmd  point to the struct variable used to configure the mailbox information send to HSM
 * core
 * @param pCfg  the struct variable address to store the result
 * @return HSM_StatusType HSM_StatusType HSM_STATUS_SUCCESS when succeed. HSM_STATUS_PARAM_ERR,
 * parameter error.
 */
HSM_StatusType HSM_Sm2Verify(HSM_CmdType *pCmd, const HSMCom_Sm2VerifyType *pCfg);

/**
 * @brief SM2 ZA
 *
 * @param pCmd  point to the struct variable used to configure the mailbox information send to HSM
 * core
 * @param pCfg  the struct variable address to store the result
 * @return HSM_StatusType HSM_StatusType HSM_STATUS_SUCCESS when succeed. HSM_STATUS_PARAM_ERR,
 * parameter error.
 */
HSM_StatusType HSM_Sm2GenZa(HSM_CmdType *pCmd, const HSMCom_Sm2GenZaType *pCfg);

/**
 * @brief SM2 Hash generate
 *
 * @param pCmd  point to the struct variable used to configure the mailbox information send to HSM
 * core
 * @param pCfg  the struct variable address to store the result
 * @return HSM_StatusType HSM_StatusType HSM_STATUS_SUCCESS when succeed. HSM_STATUS_PARAM_ERR,
 * parameter error.
 */
HSM_StatusType HSM_Sm2GenHash(HSM_CmdType *pCmd, const HSMCom_Sm2GenHashType *pCfg);

/**
 * @brief SM4 Encrypt start
 *
 * @param pCmd  point to the struct variable used to configure the mailbox information send to HSM
 * core
 * @param pCfg  the struct variable address to store the result
 * @return HSM_StatusType HSM_StatusType HSM_STATUS_SUCCESS when succeed. HSM_STATUS_PARAM_ERR,
 * parameter error.
 */
HSM_StatusType HSM_Sm4EncryptStart(HSM_CmdType            *pCmd,
                                   HSMWrap_Sm4EncryptType *pCtx,
                                   HSMCom_Sm4EncryptType  *pDecrypt);

/**
 * @brief SM4 Encrypt update
 *
 * @param pCmd  point to the struct variable used to configure the mailbox information send to HSM
 * core
 * @param pCfg  the struct variable address to store the result
 * @return HSM_StatusType HSM_StatusType HSM_STATUS_SUCCESS when succeed. HSM_STATUS_PARAM_ERR,
 * parameter error.
 */
HSM_StatusType HSM_Sm4EncryptUpdate(HSM_CmdType *pCmd, HSMWrap_Sm4EncryptType *pCtx);

/**
 * @brief SM4 Encrypt extend start
 *
 * @param pCmd  point to the struct variable used to configure the mailbox information send to HSM
 * core
 * @param pCfg  the struct variable address to store the result
 * @return HSM_StatusType HSM_StatusType HSM_STATUS_SUCCESS when succeed. HSM_STATUS_PARAM_ERR,
 * parameter error.
 */
HSM_StatusType HSM_Sm4EncryptExStart(HSM_CmdType              *pCmd,
                                     HSMWrap_Sm4EncryptExType *pCtx,
                                     HSMCom_Sm4EncryptExType  *pCfg);

/**
 * @brief SM4 Encrypt extend update
 *
 * @param pCmd  point to the struct variable used to configure the mailbox information send to HSM
 * core
 * @param pCfg  the struct variable address to store the result
 * @return HSM_StatusType HSM_StatusType HSM_STATUS_SUCCESS when succeed. HSM_STATUS_PARAM_ERR,
 * parameter error.
 */
HSM_StatusType HSM_Sm4EncryptExUpdate(HSM_CmdType *pCmd, HSMWrap_Sm4EncryptExType *pCtx);

/**
 * @brief SM4 Decrypt
 *
 * @param pCmd  point to the struct variable used to configure the mailbox information send to HSM
 * core
 * @param pCfg  the struct variable address to store the result
 * @return HSM_StatusType HSM_StatusType HSM_STATUS_SUCCESS when succeed. HSM_STATUS_PARAM_ERR,
 * parameter error.
 */
HSM_StatusType HSM_Sm4Decrypt(HSM_CmdType *pCmd, const HSMCom_Sm4DecryptType *pCfg);

/**
 * @brief SM4 Decrypt extend
 *
 * @param pCmd  point to the struct variable used to configure the mailbox information send to HSM
 * core
 * @param pCfg  the struct variable address to store the result
 * @return HSM_StatusType HSM_StatusType HSM_STATUS_SUCCESS when succeed. HSM_STATUS_PARAM_ERR,
 * parameter error.
 */
HSM_StatusType HSM_Sm4DecryptEx(HSM_CmdType *pCmd, const HSMCom_Sm4DecryptExType *pCfg);

/**
 * @brief ECC decrypt
 *
 * @param pCmd  point to the struct variable used to configure the mailbox information send to HSM
 * core
 * @param pCfg  the struct variable address to store the result
 * @return HSM_StatusType HSM_StatusType HSM_STATUS_SUCCESS when succeed. HSM_STATUS_PARAM_ERR,
 * parameter error.
 */
HSM_StatusType HSM_EccEasyDecry(HSM_CmdType *pCmd, const HSMCom_EccEasyDecryType *pCfg);

/**
 * @brief require challenge data for auth
 *
 * @param pCmd  point to the struct variable used to configure the mailbox information send to HSM
 * core
 * @param pCfg  the struct variable address to store the result
 * @return HSM_StatusType HSM_StatusType HSM_STATUS_SUCCESS when succeed. HSM_STATUS_PARAM_ERR,
 * parameter error.
 */
HSM_StatusType HSM_RequestAuthorization(HSM_CmdType *pCmd, const HSMCom_RequestAuthType *pCfg);

/**
 * @brief Life cycle change take effect
 *
 * @param pCmd  point to the struct variable used to configure the mailbox information send to HSM
 * core
 * @return HSM_StatusType HSM_StatusType HSM_STATUS_SUCCESS when succeed. HSM_STATUS_PARAM_ERR,
 * parameter error.
 */
HSM_StatusType HSM_LifeCycleTakeEffect(HSM_CmdType *pCmd, HSMCom_LifeCycleTakeEffectType *pCfg);

/**
 * @brief Life cycle change to OEM DEV(need call HSM_LifeCycleTakeEffect to take effect)
 * @note You can read/write/erase the USRK,UMRK,DebugAuth,IspAuth,PreFaAuth key data in the data
 * flash in this life cycle
 *
 * @param pCmd  point to the struct variable used to configure the mailbox information send to HSM
 * core
 * @return HSM_StatusType HSM_StatusType HSM_STATUS_SUCCESS when succeed. HSM_STATUS_PARAM_ERR,
 * parameter error.
 */
HSM_StatusType HSM_OemDevEnter(HSM_CmdType *pCmd, const HSMCom_AuthCheckType *pCfg);

/**
 * @brief Life cycle change to OEM PDT(need call HSM_LifeCycleTakeEffect take effect)
 * @note You can only write the USRK,UMRK,DebugAuth,IspAuth,PreFaAuth key data in the data flash in
 * this life cycle
 * @param pCmd  point to the struct variable used to configure the mailbox information send to HSM
 * core
 * @return HSM_StatusType HSM_StatusType HSM_STATUS_SUCCESS when succeed. HSM_STATUS_PARAM_ERR,
 * parameter error.
 */
HSM_StatusType HSM_OemPdtEnter(HSM_CmdType *pCmd, const HSMCom_AuthCheckType *pCfg);

/**
 * @brief Life cycle change to In Field(need call HSM_LifeCycleTakeEffect take effect)
 * @note You can't access the key data in this life cycle, before you enter this, you MUST program
 * you key data. Or you will need to send the chip to us if you program has bugs.
 * @param pCmd  point to the struct variable used to configure the mailbox information send to HSM
 * core
 * @return HSM_StatusType HSM_StatusType HSM_STATUS_SUCCESS when succeed. HSM_STATUS_PARAM_ERR,
 * parameter error.
 */
HSM_StatusType HSM_InFieldEnter(HSM_CmdType *pCmd, const HSMCom_AuthCheckType *pCfg);

/**
 * @brief cancel the current job of the channel
 *
 * @param pCmd  point to the struct variable used to configure the mailbox information send to HSM
 * core
 * @param pCfg  the struct variable address to store the result
 * @return HSM_StatusType HSM_StatusType HSM_STATUS_SUCCESS when succeed. HSM_STATUS_PARAM_ERR,
 * parameter error.
 */
HSM_StatusType HSM_CancelJob(HSM_CmdType *pCmd, const HSMCom_CancelJobType *pCfg);

/**
 * @brief hsm self test
 *
 * @param pCmd  point to the struct variable used to configure the mailbox information send to HSM
 * core
 * @param pCfg  the struct variable address to store the result
 * @return HSM_StatusType HSM_StatusType HSM_STATUS_SUCCESS when succeed. HSM_STATUS_PARAM_ERR,
 * parameter error.
 */
HSM_StatusType HSM_SelfTest(HSM_CmdType *pCmd, volatile HSMCom_SelfTestType *pCfg);

/**
 * @brief NVR OTP program
 *
 * @param pCmd  point to the struct variable used to configure the mailbox information send to HSM
 * core
 * @param pCfg  the struct variable address to store the result
 * @return HSM_StatusType HSM_StatusType HSM_STATUS_SUCCESS when succeed. HSM_STATUS_PARAM_ERR,
 * parameter error.
 */
HSM_StatusType HSM_NvrOtpProgram(HSM_CmdType *pCmd, const HSMCom_NvrOtpType *pCfg);

/**
 * @brief NVR OTP data read
 *
 * @param pCmd  point to the struct variable used to configure the mailbox information send to HSM
 * core
 * @param pCfg  the struct variable address to store the result
 * @return HSM_StatusType HSM_StatusType HSM_STATUS_SUCCESS when succeed. HSM_STATUS_PARAM_ERR,
 * parameter error.
 */

HSM_StatusType HSM_NvrOtpRead(HSM_CmdType *pCmd, const HSMCom_NvrOtpType *pCfg);

/**
 * @brief user key import
 *
 * @param pCmd  point to the struct variable used to configure the mailbox information send to HSM
 * core
 * @param pCfg  the struct variable address to store the result
 * @return HSM_StatusType HSM_StatusType HSM_STATUS_SUCCESS when succeed. HSM_STATUS_PARAM_ERR,
 * parameter error.
 */
HSM_StatusType HSM_UserKeyImport(HSM_CmdType *pCmd, const HSMCom_UserKeyManageType *pCfg);

/**
 * @brief user key export
 *
 * @param pCmd  point to the struct variable used to configure the mailbox information send to HSM
 * core
 * @param pCfg  the struct variable address to store the result
 * @return HSM_StatusType HSM_StatusType HSM_STATUS_SUCCESS when succeed. HSM_STATUS_PARAM_ERR,
 * parameter error.
 */
HSM_StatusType HSM_UserKeyExport(HSM_CmdType *pCmd, const HSMCom_UserKeyManageType *pCfg);

/**
 * @brief get the user key space status in HSM internal
 *
 * @param pCmd  point to the struct variable used to configure the mailbox information send to HSM core
 * @param pCfg  the struct variable address to store the result
 * @return HSM_StatusType HSM_STATUS_SUCCESS when succeed. HSM_STATUS_PARAM_ERR, parameter error.
 */
HSM_StatusType HSM_GetKeySpaceStat(HSM_CmdType *pCmd, const HSMCom_KeySpaceStatusType *pCfg);

/**
 * @brief tidy the user key space in HSM internal, if revoked key exist, it will make the space re-useable
 *
 * @param pCmd  point to the struct variable used to configure the mailbox information send to HSM core
 * @param pCfg  the struct variable address to store the result
 * @return HSM_StatusType HSM_STATUS_SUCCESS when succeed. HSM_STATUS_PARAM_ERR, parameter error.
 */
HSM_StatusType HSM_TidyUpKeySpace(HSM_CmdType *pCmd, const HSMCom_KeySpaceStatusType *pCfg);

/**
 * @brief Revoke user key
 *
 * @param pCmd  point to the struct variable used to configure the mailbox information send to HSM core
 * @param pCfg  the struct variable address to store the result
 * @return HSM_StatusType HSM_STATUS_SUCCESS when succeed. HSM_STATUS_PARAM_ERR, parameter error.
 */
HSM_StatusType HSM_UserKeyRevoke(HSM_CmdType *pCmd, const HSMCom_UserKeyManageType *pCfg);

/**
 * @brief AES encrypt API
 *
 * @param pCmd  point to the struct variable used to configure the mailbox information send to HSM
 * core
 * @param pCfg  the struct variable address to store the result
 * @return HSM_StatusType HSM_StatusType HSM_STATUS_SUCCESS when succeed. HSM_STATUS_PARAM_ERR,
 * parameter error.
 */
HSM_StatusType HSM_AesEncrypt(HSM_CmdType *pCmd, const HSMCom_AesEncryptType *pCfg);
/**
 * @brief AES encrypt extend API
 *
 * @param pCmd  point to the struct variable used to configure the mailbox information send to HSM
 * core
 * @param pCfg  the struct variable address to store the result
 * @return HSM_StatusType HSM_StatusType HSM_STATUS_SUCCESS when succeed. HSM_STATUS_PARAM_ERR,
 * parameter error.
 */
HSM_StatusType HSM_AesEncryptEx(HSM_CmdType *pCmd, const HSMCom_FlexAesEncryptType *pCfg);

/**
 * @brief AES decrypt
 *
 * @param pCmd  point to the struct variable used to configure the mailbox information send to HSM core
 * @param pCfg  the struct variable address to store the result
 * @return HSM_StatusType HSM_STATUS_SUCCESS when succeed. Others, some error occur.
 */
HSM_StatusType HSM_AesDecrypt(HSM_CmdType *pCmd, const HSMCom_AesDecryptType *pCfg);

/**
 * @brief AES decrypt extend
 *
 * @param pCmd  point to the struct variable used to configure the mailbox information send to HSM core
 * @param pCfg  the struct variable address to store the result
 * @return HSM_StatusType HSM_STATUS_SUCCESS when succeed. Others, some error occur.
 */
HSM_StatusType HSM_AesDecryptEx(HSM_CmdType *pCmd, const HSMCom_FlexAesDecryptType *pCfg);

/**
 * @brief CMAC
 *
 * @param pCmd  point to the struct variable used to configure the mailbox information send to HSM
 * core
 * @param pCfg  the struct variable address to store the result
 * @return HSM_StatusType HSM_STATUS_SUCCESS when succeed. HSM_STATUS_BUSY when driver is busy.
 * Others, some error occur.
 */
HSM_StatusType HSM_CMac(HSM_CmdType *pCmd, const HSMCom_CMacType *pCfg);

/**
 * @brief CMAC extend
 *
 * @param pCmd  point to the struct variable used to configure the mailbox information send to HSM
 * core
 * @param pCfg  the struct variable address to store the result
 * @return HSM_StatusType HSM_STATUS_SUCCESS when succeed. HSM_STATUS_BUSY when driver is busy.
 * Others, some error occur.
 */
HSM_StatusType HSM_CMacEx(HSM_CmdType *pCmd, const HSMCom_CMacExType *pCfg);

/**
 * @brief XMAC
 *
 * @param pCmd  point to the struct variable used to configure the mailbox information send to HSM
 * core
 * @param pCfg  the struct variable address to store the result
 * @return HSM_StatusType HSM_STATUS_SUCCESS when succeed. HSM_STATUS_BUSY when driver is busy.
 * Others, some error occur.
 */
HSM_StatusType HSM_XMac(HSM_CmdType *pCmd, const HSMCom_XMacType *pCfg);

/**
 * @brief CCM encrypt
 *
 * @param pCmd  point to the struct variable used to configure the mailbox information send to HSM
 * core
 * @param pCfg  the struct variable address to store the result
 * @return HSM_StatusType HSM_STATUS_SUCCESS when succeed. HSM_STATUS_BUSY when driver is busy.
 * Others, some error occur.
 */
HSM_StatusType HSM_CcmEncry(HSM_CmdType *pCmd, const HSMCom_CcmEncryptType *pCfg);

/**
 * @brief CCM decrypt
 *
 * @param pCmd  point to the struct variable used to configure the mailbox information send to HSM
 * core
 * @param pCfg  the struct variable address to store the result
 * @return HSM_StatusType HSM_STATUS_SUCCESS when succeed. HSM_STATUS_BUSY when driver is busy.
 * Others, some error occur.
 */
HSM_StatusType HSM_CcmDecry(HSM_CmdType *pCmd, const HSMCom_CcmDecryptType *pCfg);

/**
 * @brief GCM encrypt
 *
 * @param pCmd  point to the struct variable used to configure the mailbox information send to HSM
 * core
 * @param pCfg  the struct variable address to store the result
 * @return HSM_StatusType HSM_STATUS_SUCCESS when succeed. HSM_STATUS_BUSY when driver is busy.
 * Others, some error occur.
 */
HSM_StatusType HSM_GcmEncry(HSM_CmdType *pCmd, const HSMCom_GcmEncryptType *pCfg);

/**
 * @brief GCM decrypt
 *
 * @param pCmd  point to the struct variable used to configure the mailbox information send to HSM
 * core
 * @param pCfg  the struct variable address to store the result
 * @return HSM_StatusType HSM_STATUS_SUCCESS when succeed. HSM_STATUS_BUSY when driver is busy.
 * Others, some error occur.
 */
HSM_StatusType HSM_GcmDecry(HSM_CmdType *pCmd, const HSMCom_GcmDecryptType *pCfg);

/**
 * @brief MD5
 *
 * @param pCmd  point to the struct variable used to configure the mailbox information send to HSM
 * core
 * @param pCfg  the struct variable address to store the result
 * @return HSM_StatusType HSM_StatusType HSM_STATUS_SUCCESS when succeed. HSM_STATUS_PARAM_ERR,
 * parameter error.
 */
HSM_StatusType HSM_Md5(HSM_CmdType *pCmd, const HSMCom_Md5Type *pCfg);

/**
 * @brief MD5 extend
 *
 * @param pCmd  point to the struct variable used to configure the mailbox information send to HSM
 * core
 * @param pCfg  the struct variable address to store the result
 * @return HSM_StatusType HSM_StatusType HSM_STATUS_SUCCESS when succeed. HSM_STATUS_PARAM_ERR,
 * parameter error.
 */
HSM_StatusType HSM_FW_Md5Ex(HSM_CmdType *pCmd, const HSMCom_Md5ExType *pCfg, HSM_BoolType bKeyUseId);

/**
 * @brief SM3
 *
 * @param pCmd  point to the struct variable used to configure the mailbox information send to HSM
 * core
 * @param pCfg  the struct variable address to store the result
 * @return HSM_StatusType HSM_StatusType HSM_STATUS_SUCCESS when succeed. HSM_STATUS_PARAM_ERR,
 * parameter error.
 */
HSM_StatusType HSM_Sm3(HSM_CmdType *pCmd, const HSMCom_Sm3Type *pCfg);

/**
 * @brief SM3 extend
 *
 * @param pCmd  point to the struct variable used to configure the mailbox information send to HSM
 * core
 * @param pCfg  the struct variable address to store the result
 * @return HSM_StatusType HSM_StatusType HSM_STATUS_SUCCESS when succeed. HSM_STATUS_PARAM_ERR,
 * parameter error.
 */
HSM_StatusType HSM_FW_Sm3Ex(HSM_CmdType *pCmd, const HSMCom_Sm3ExType *pCfg, HSM_BoolType bKeyUseId);

/**
 * @brief monotonic counter increase 1
 * @note this counter keep value until chip power off
 *
 * @param pCmd  point to the struct variable used to configure the mailbox information send to HSM
 * core
 * @param pCfg  the struct variable address to store the result
 * @return HSM_StatusType HSM_StatusType HSM_STATUS_SUCCESS when succeed. HSM_STATUS_PARAM_ERR,
 * parameter error.
 */
HSM_StatusType HSM_MonotonicCounterIncrease(HSM_CmdType *pCmd, const HSMCom_MonCountType *pCfg);

/**
 * @brief read monotonic counter value
 *
 * @param pCmd  point to the struct variable used to configure the mailbox information send to HSM
 * core
 * @param pCfg  the struct variable address to store the result
 * @return HSM_StatusType HSM_StatusType HSM_STATUS_SUCCESS when succeed. HSM_STATUS_PARAM_ERR,
 * parameter error.
 */
HSM_StatusType HSM_MonotonicCounterRead(HSM_CmdType *pCmd, const HSMCom_MonCountType *pCfg);

/**
 * @brief RSA
 *
 * @param pCmd  point to the struct variable used to configure the mailbox information send to HSM core
 * @param pCfg  the struct variable address to store the result
 * @return HSM_StatusType HSM_STATUS_SUCCESS when succeed. Others, some error occur.
 */
HSM_StatusType HSM_Rsa(HSM_CmdType *pCmd, const HSMCom_RsaType *pCfg);

/**
 * @brief Big number calculate extend
 *
 * @param pCmd  point to the struct variable used to configure the mailbox information send to HSM core
 * @param pCfg  the struct variable address to store the result
 * @return HSM_StatusType HSM_STATUS_SUCCESS when succeed. Others, some error occur.
 */
HSM_StatusType HSM_BigNumberCalculateEx(HSM_CmdType *pCmd, const HSMCom_BigNumberCalcType *pCfg);

/**
 * @brief trigger firware take effect when the firmware is in delay load mode
 *
 * @param pCmd  point to the struct variable used to configure the mailbox information send to HSM core
 * @param pCfg  the struct variable address to store the result
 * @return HSM_StatusType HSM_STATUS_SUCCESS when succeed. Others, some error occur.
 */
HSM_StatusType HSM_LoadFirmware(HSM_CmdType *pCmd, HSMCom_LoadFirmwareType *pCfg);

/**
 * @brief Scatter hash init
 *
 * @param pCmd  point to the struct variable used to configure the mailbox information send to HSM core
 * @param pCfg  the struct variable address to store the result
 * @return HSM_StatusType HSM_STATUS_SUCCESS when succeed. Others, some error occur.
 */
HSM_StatusType HSM_FW_ScatterHashInit(HSM_CmdType                  *pCmd,
                                      const HSMCom_ScatterHashType *pCfg,
                                      HSM_BoolType                  bKeyUseId,
                                      HSM_DataFormatType            eInputFmt);

/**
 * @brief Scatter hash update
 *
 * @param pCmd  point to the struct variable used to configure the mailbox information send to HSM core
 * @param pCfg  the struct variable address to store the result
 * @return HSM_StatusType HSM_STATUS_SUCCESS when succeed. Others, some error occur.
 */
HSM_StatusType HSM_FW_ScatterHashUpdate(HSM_CmdType                  *pCmd,
                                        const HSMCom_ScatterHashType *pCfg,
                                        HSM_BoolType                  bKeyUseId,
                                        HSM_DataFormatType            eInputFmt);

/**
 * @brief Scatter hash final
 *
 * @param pCmd  point to the struct variable used to configure the mailbox information send to HSM core
 * @param pCfg  the struct variable address to store the result
 * @return HSM_StatusType HSM_STATUS_SUCCESS when succeed. Others, some error occur.
 */
HSM_StatusType HSM_FW_ScatterHashFinal(HSM_CmdType                  *pCmd,
                                       const HSMCom_ScatterHashType *pCfg,
                                       HSM_BoolType                  bKeyUseId,
                                       HSM_DataFormatType            eInputFmt);

/**
 * @brief ECC encrypt
 * @note this function is implemented in firmware
 * @param pCmd  point to the struct variable used to configure the mailbox information send to HSM core
 * @param pCfg  the struct variable address to store the result
 * @return HSM_StatusType HSM_STATUS_SUCCESS when succeed. Others, some error occur.
 */
HSM_StatusType HSM_FW_EccEncrypt(HSM_CmdType *pCmd, const HSMCom_EccEasyEncryType *pCfg);

/**
 * @brief Generate SM2/ECC key pair(private key and public key)
 * @note this function is implemented in firmware
 * @param pCmd  point to the struct variable used to configure the mailbox information send to HSM core
 * @param pCfg  user key pair generate parameters for trigger the process
 * @return HSM_StatusType HSM_STATUS_SUCCESS when succeed. HSM_STATUS_PARAM_ERR, parameter error.
 */
HSM_StatusType HSM_FW_UserKeyGenPair(HSM_CmdType *pCmd, const HSMCom_UserKeyManageType *pCfg);

/**
 * @brief ECC Sign
 * @note this function is implemented in firmware
 * @param pCmd  point to the struct variable used to configure the mailbox information send to HSM
 * core
 * @param pCfg  the struct variable address to store the result
 * @return HSM_StatusType HSM_StatusType HSM_STATUS_SUCCESS when succeed. HSM_STATUS_PARAM_ERR,
 * parameter error.
 */
HSM_StatusType HSM_FW_EccSign(HSM_CmdType *pCmd, const HSMCom_EccSignType *pCfg);

/**
 * @brief SM2 key pair generate
 * @note this function is implemented in firmware
 * @param pCmd  point to the struct variable used to configure the mailbox information send to HSM
 * core
 * @param pCfg  the struct variable address to store the result
 * @return HSM_StatusType HSM_StatusType HSM_STATUS_SUCCESS when succeed. HSM_STATUS_PARAM_ERR,
 * parameter error.
 */
HSM_StatusType HSM_FW_Sm2GenKeyPair(HSM_CmdType *pCmd, const HSMCom_Sm2GenKeyPairType *pCfg);

/**
 * @brief SM2 encrypt
 * @note this function is implemented in firmware
 * @param pCmd  point to the struct variable used to configure the mailbox information send to HSM
 * core
 * @param pCfg  the struct variable address to store the result
 * @return HSM_StatusType HSM_StatusType HSM_STATUS_SUCCESS when succeed. HSM_STATUS_PARAM_ERR,
 * parameter error.
 */
HSM_StatusType HSM_FW_Sm2Encry(HSM_CmdType *pCmd, const HSMCom_Sm2EncryptType *pCfg);

/**
 * @brief ECC encrypt
 * @note this function is implemented in firmware
 * @param pCmd  point to the struct variable used to configure the mailbox information send to HSM
 * core
 * @param pCfg  the struct variable address to store the result
 * @return HSM_StatusType HSM_StatusType HSM_STATUS_SUCCESS when succeed. HSM_STATUS_PARAM_ERR,
 * parameter error.
 */
HSM_StatusType HSM_FW_EccEncrypt(HSM_CmdType *pCmd, const HSMCom_EccEasyEncryType *pCfg);

/**
 * @brief SM2 sign
 * @note this function is implemented in firmware
 * @param pCmd  point to the struct variable used to configure the mailbox information send to HSM
 * core
 * @param pCfg  the struct variable address to store the result
 * @return HSM_StatusType HSM_StatusType HSM_STATUS_SUCCESS when succeed. HSM_STATUS_PARAM_ERR,
 * parameter error.
 */
HSM_StatusType HSM_FW_Sm2Sign(HSM_CmdType *pCmd, const HSMCom_Sm2SignType *pCfg);

/**
 * @brief user key revoke(delete ram key or abondon key in flash)
 * @note this function is implemented in firmware
 * @param pCmd  point to the struct variable used to configure the mailbox information send to HSM
 * core
 * @param pCfg  the struct variable address to store the result
 * @return HSM_StatusType HSM_StatusType HSM_STATUS_SUCCESS when succeed. HSM_STATUS_PARAM_ERR,
 * parameter error.
 */
HSM_StatusType HSM_FW_UserKeyRevoke(HSM_CmdType *pCmd, const HSMCom_UserKeyManageType *pCfg);

/**
 * @brief Scatter cmac init
 *
 * @param pCmd  point to the struct variable used to configure the mailbox information send to HSM core
 * @param pCfg  the struct variable address to store the result
 * @return HSM_StatusType HSM_STATUS_SUCCESS when succeed. Others, some error occur.
 */
HSM_StatusType HSM_FW_ScatterCMacInit(HSM_CmdType                 *pCmd,
                                      const HSMCom_AesmRawApiType *pCfg,
                                      HSM_DataFormatType           eInputFmt,
                                      HSM_DataFormatType           eKeyFmt);

/**
 * @brief Scatter cmac update
 *
 * @param pCmd  point to the struct variable used to configure the mailbox information send to HSM core
 * @param pCfg  the struct variable address to store the result
 * @return HSM_StatusType HSM_STATUS_SUCCESS when succeed. Others, some error occur.
 */
HSM_StatusType HSM_FW_ScatterCMacUpdate(HSM_CmdType                 *pCmd,
                                        const HSMCom_AesmRawApiType *pCfg,
                                        HSM_DataFormatType           eInputFmt,
                                        HSM_DataFormatType           eKeyFmt);

/**
 * @brief Scatter cmac final
 *
 * @param pCmd  point to the struct variable used to configure the mailbox information send to HSM core
 * @param pCfg  the struct variable address to store the result
 * @return HSM_StatusType HSM_STATUS_SUCCESS when succeed. Others, some error occur.
 */
HSM_StatusType HSM_FW_ScatterCMacFinal(HSM_CmdType                 *pCmd,
                                       const HSMCom_AesmRawApiType *pCfg,
                                       HSM_DataFormatType           eInputFmt,
                                       HSM_DataFormatType           eKeyFmt);

/**
 * @brief RsaSsa-pss verify
 *
 * @param pCmd  point to the struct variable used to configure the mailbox information send to HSM core
 * @param pCfg  the struct variable address to store the result
 * @return HSM_StatusType HSM_STATUS_SUCCESS when succeed. Others, some error occur.
 */
HSM_StatusType HSM_FW_RsaSsaPssVerify(HSM_CmdType *pCmd, const HSMCom_RsaSsaPssVerifyType *pCfg);

/**
 * @brief RsaSsa-pkcs1-v1_5 verify
 *
 * @param pCmd  point to the struct variable used to configure the mailbox information send to HSM core
 * @param pCfg  the struct variable address to store the result
 * @return HSM_StatusType HSM_STATUS_SUCCESS when succeed. Others, some error occur.
 */
HSM_StatusType HSM_FW_RsaSsaPkcs1v15Verify(HSM_CmdType                           *pCmd,
                                           const HSMCom_RsaSsaPkcs1V15VerifyType *pCfg);

/**
 * @brief Userkey Import
 *
 * @param pCmd  point to the struct variable used to configure the mailbox information send to HSM core
 * @param pCfg  the struct variable address to store the result
 * @return HSM_StatusType HSM_STATUS_SUCCESS when succeed. Others, some error occur.
 */
HSM_StatusType HSM_FW_UserKeyImportNew(HSM_CmdType *pCmd, const HSMCom_UserKeyManageType *pCfg);

/**
 * @brief Check key ID
 *
 * @param pCmd  point to the struct variable used to configure the mailbox information send to HSM core
 * @param pCfg  the struct variable address to store the result
 * @return HSM_StatusType HSM_STATUS_SUCCESS when succeed. Others, some error occur.
 */
HSM_StatusType HSM_FW_CheckKeyIdExt(HSM_CmdType *pCmd, const HSMCom_UserKeyManageType *pCfg);

/**
 * @brief Copy key
 *
 * @param pCmd  point to the struct variable used to configure the mailbox information send to HSM core
 * @param pCfg  the struct variable address to store the result
 * @return HSM_StatusType HSM_STATUS_SUCCESS when succeed. Others, some error occur.
 */
HSM_StatusType HSM_FW_CopyKeyExt(HSM_CmdType *pCmd, const HSMCom_UserKeyManageType *pCfg);

/**
 * @brief Big Number calculate
 *
 * @param pCmd  point to the struct variable used to configure the mailbox information send to HSM core
 * @param pCfg  the struct variable address to store the result
 * @return HSM_StatusType HSM_STATUS_SUCCESS when succeed. Others, some error occur.
 */
HSM_StatusType HSM_FW_BigNumberCalculateEx(HSM_CmdType                       *pCmd,
                                           const HSMCom_BigNumberCalcExtType *pCfg);

/**
 * @brief RsaSsa-pss verify
 *
 * @param pCmd  point to the struct variable used to configure the mailbox information send to HSM core
 * @param pCfg  the struct variable address to store the result
 * @return HSM_StatusType HSM_STATUS_SUCCESS when succeed. Others, some error occur.
 */
HSM_StatusType HSM_FW_RsaSsaPssSign(HSM_CmdType *pCmd, const HSMCom_RsaSsaPssSignType *pCfg);

/**
 * @brief RsaSsa-pss-Pkcs-1v15 verify
 *
 * @param pCmd  point to the struct variable used to configure the mailbox information send to HSM core
 * @param pCfg  the struct variable address to store the result
 * @return HSM_StatusType HSM_STATUS_SUCCESS when succeed. Others, some error occur.
 */
HSM_StatusType HSM_FW_RsaSsaPkcs1v15Sign(HSM_CmdType                         *pCmd,
                                         const HSMCom_RsaSsaPkcs1v15SignType *pCfg);

#if ((FC7XXX_HSM_SUBSYSTEM_TYPE == FC7240_HSM_SUBSYSTEM) || \
     (FC7XXX_HSM_SUBSYSTEM_TYPE == FC7300_HSM_SUBSYSTEM))
/**
 * @brief Get key Id status
 *
 * @param pCmd  point to the struct variable used to configure the mailbox information send to HSM core
 * @param pCfg  the struct variable address to store the result
 * @return HSM_StatusType HSM_STATUS_SUCCESS when succeed. Others, some error occur.
 */
HSM_StatusType HSM_FW_GetKeyIdStatus(HSM_CmdType *pCmd, const HSMCom_UserKeyManageType *pCfg);
#endif

#if ((FC7XXX_HSM_SUBSYSTEM_TYPE == FC7240_HSM_SUBSYSTEM) || \
     (FC7XXX_HSM_SUBSYSTEM_TYPE == FC7300_HSM_SUBSYSTEM))
#else
/**
 * @brief Update key content of special key id
 *
 * @param pCmd  point to the struct variable used to configure the mailbox information send to HSM core
 * @param pCfg  the struct variable address to store the result
 * @return HSM_StatusType HSM_STATUS_SUCCESS when succeed. Others, some error occur.
 */
HSM_StatusType HSM_UpdateKeyContentOfSpecificKeyId(HSM_CmdType                    *pCmd,
                                                   const HSMCom_UserKeyManageType *pCfg);
#endif

/**@}*/
#if defined(__cplusplus)
}
#endif
/** @}*/ /* module_driver_hsm */

#endif /* end of CRYPTO_LEVEL0API_H */
