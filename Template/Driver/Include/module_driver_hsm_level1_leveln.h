/**
 * @file module_driver_hsm_level1_leveln.h
 * @author flagchip
 * @brief HSM driver type definition and API
 * @version 2.0.0
 * @date 2024-08-20
 *
 * SDK Version: 2.6.0
 *

 * @copyright Copyright (c) 2020-2024 Flagchip Semiconductors Co., Ltd.
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
#ifndef _DRIVER_MODULE_DRIVER_HSM_LEVEL1_LEVELN_H
#define _DRIVER_MODULE_DRIVER_HSM_LEVEL1_LEVELN_H

#include "module_driver_hsm.h"

/**
 * @addtogroup module_driver_hsm_Level1_LevelN
 * @{
 */

#if defined(__cplusplus)
extern "C" {
#endif

/********************************************* global define *********************************************************/
#ifdef __ghs__
#include <arm_ghs.h>
#define hsm_hw_swap_u32(x) __REV(x)

#elif defined(__GNUC__)
#define hsm_hw_swap_u32(x) __builtin_bswap32(x)

#elif defined(__ICCARM__)
#include "iccarm_builtin.h"
#define hsm_hw_swap_u32(x)     __iar_builtin_REV(x)
#else
#define hsm_hw_swap_u32(x)     ({hsm_uint32_t y; asm volatile ("rev %0, %1\n" :"=r"(y) :"r"(x)); y;})
#endif

#define HSM_ADDRESS_UP_ALIGN(addr)  ((((hsm_uint32_t)(addr)) + 0x3u) & (~((hsm_uint32_t)0x3)))

#define HSM_4B_BYTE_INDEX_TO_OFFSET(idx) (((idx) & 0xFFFFFFFCu) + (3u - ((idx) & 0x3u)))

#define HSM_HFAM_HW_PROCESS_ALIGN(x)  128u

#define HSM_AESM_SCATTER_CMAC_HW_PROCESS_ALIGN()  16u

/**
 * @brief Section define
 *
 */
#define CRYPTO_TEXT_SECTION

/**
 * @brief AESM BACKEND is aes
 *
 */
#define HSM_AESM_BACKEND_AES  0x0

/**
 * @brief AESM BACKEND is SM4
 *
 */
#define HSM_AESM_BACKEND_SM4  0x1

/**
 * @brief AESM BACKEND Type
 *
 */
typedef hsm_uint32_t HSM_AesmBackendType;

/**
 * @brief Trng random number count
 *
 */

#define HSM_L1_PKCS8_RSA_PRIVATE_KEY 0
#define HSM_L1_PKCS8_ECC_PRIVATE_KEY 1
typedef hsm_uint32_t HSM_L1_PKCS8_PrivateKeyType;

#define HSM_L1_RSA_PUBLIC_KEY 0
#define HSM_L1_ECC_PUBLIC_KEY 1
typedef hsm_uint32_t HSM_L1_PublicKeyType;

#define HSM_ECC_VERIFY_INPUT_RAW_MESSAGE  0u
#define HSM_ECC_VERIFY_INPUT_HASH_DATA    1u
typedef hsm_uint32_t HSM_EccVerifyInputType;
/********************************************* global enmu *********************************************************/
/**
 * @brief Level 1 drive SM type
 *
 */
typedef enum
{
    HSM_DRV_SM_READY = 0,
    HSM_DRV_SM_ARITH,
    HSM_DRV_SM_STOP,
} HSM_L1_DrvSMType;

/**
 * @brief verify result type
 *
 */
typedef enum
{
    /**@details The result of the verification is "true",
        i.e. the two compared elements are identical. This return code shall be given as value "0" */
    CRYPTO_E_VER_OK = 0x00U,
    /**@details The result of the verification is "false",
        i.e. the two compared elements are not identical. This return code shall be given as value "1". */
    CRYPTO_E_VER_NOT_OK = 0x01U
} Crypto_VerifyResultType;

/**
 * @brief scatter hash sm type
 *
 */
typedef enum
{
    HSM_L1_SCATTER_HASH_READY,
    HSM_L1_SCATTER_HASH_NEED_MORE_BEFORE_INIT,
    HSM_L1_SCATTER_HASH_INIT,
    HSM_L1_SCATTER_HASH_INIT_OK,
    HSM_L1_SCATTER_HASH_NEED_MORE_BEFORE_UPDATE_FINAL,
    HSM_L1_SCATTER_HASH_UPDATE,
    HSM_L1_SCATTER_HASH_UPDATE_OK,
    HSM_L1_SCATTER_HASH_FINAL,
    HSM_L1_SCATTER_HASH_STOP
} HSM_ScatterHashSMType;

/**
 * @brief scatter hash cmac type
 *
 */
typedef enum
{
    HSM_L1_SCATTER_CMAC_READY,
    HSM_L1_SCATTER_CMAC_NEED_MORE_BEFORE_INIT,
    HSM_L1_SCATTER_CMAC_INIT,
    HSM_L1_SCATTER_CMAC_INIT_OK,
    HSM_L1_SCATTER_CMAC_NEED_MORE_BEFORE_UPDATE_FINAL,
    HSM_L1_SCATTER_CMAC_UPDATE,
    HSM_L1_SCATTER_CMAC_UPDATE_OK,
    HSM_L1_SCATTER_CMAC_FINAL,
    HSM_L1_SCATTER_CMAC_STOP
} HSM_ScatterCMacSMType;

/**
 * @brief Level 2 operation type
 *
 */
typedef enum
{
    HSM_LEVEL_2ND_OP_NONE = 0,

    HSM_LEVEL_2ND_OP_CMAC_EMPTY,

    HSM_LEVEL_2ND_OP_UPDATE_KEY, /* if key not exist, create new */

    HSM_LEVEL_2ND_OP_REVOKE_KEY,
    HSM_LEVEL_2ND_OP_ECC_VERIFY, /* if input is raw data, need hash first */
    HSM_LEVEL_2ND_OP_SM2_VERIFY, /* if input is raw data, need hash first */
} HSM_L2_DrvOpType;

/**
 * @brief Level 2 cmac empty sm type
 *
 */
typedef enum
{
    HSM_L2_CMAC_EMPTY_SM_READY,
    HSM_L2_CMAC_EMPTY_SM_GENERATE_L,
    HSM_L2_CMAC_EMPTY_SM_GENERATE_T,
    HSM_L2_CMAC_EMPTY_SM_STOP,
} HSM_L2_DrvCMacEmptySMType;

/**
 * @brief Level 3 operation type
 *
 */
typedef enum
{
    HSM_LEVEL_3RD_OP_NONE = 0,
    HSM_LEVEL_3RD_OP_SCATTER_CMAC,
    HSM_LEVEL_3RD_OP_UPDATE_KEY,
} HSM_L3_DrvOpType;

/**
 * @brief Level 3 scatter cmac sm type
 *
 */
typedef enum
{
    HSM_L3_SCATTER_CMAC_READY,
    HSM_L3_SCATTER_CMAC_EMPTY_INPUT,
    HSM_L3_SCATTER_CMAC_INIT,
    HSM_L3_SCATTER_CMAC_NEED_MORE_AFTER_INIT,
    HSM_L3_SCATTER_CMAC_INIT_OK,
    HSM_L3_SCATTER_CMAC_UPDATE,
    HSM_L3_SCATTER_CMAC_NEED_MORE_AFTER_UPDATE,
    HSM_L3_SCATTER_CMAC_UPDATE_OK,
    HSM_L3_SCATTER_CMAC_FINAL,
    HSM_L3_SCATTER_CMAC_STOP
} HSM_L3_ScatterCMacSMType;

typedef enum
{
    HSM_LN_KEY_DATA_STORE_FMT_BN_LOADABLE = 0,
    HSM_LN_KEY_DATA_STORE_FMT_4B,
    HSM_LN_KEY_DATA_STORE_FMT_1B,
    HSM_LN_KEY_DATA_STORE_FMT_SPLIT_BN_LOADABLE,
} HSM_Ln_KeyDataStoreFmtType;

typedef enum
{
    HSM_L2_UPDATE_KEY_SM_READY,
    #if (FC7XXX_HSM_SUBSYSTEM_TYPE == FC7240_HSM_SUBSYSTEM) || (FC7XXX_HSM_SUBSYSTEM_TYPE == FC7300_HSM_SUBSYSTEM)
    HSM_L2_UPDATE_KEY_SM_LOADFIRMWARE,
    HSM_L2_UPDATE_KEY_SM_CHECK_EXIST,
    HSM_L2_UPDATE_KEY_SM_REVOKE,
    HSM_L2_UPDATE_KEY_SM_TIDYUP,
    HSM_L2_UPDATE_KEY_SM_IMPORT,
    HSM_L2_UPDATE_KEY_SM_GET_STATUS,

    #else
    HSM_L2_UPDATE_KEY_SM_TIDYUP,
    HSM_L2_UPDATE_KEY_SM_UPDATE,
    HSM_L2_UPDATE_KEY_SM_IMPORT,
    HSM_L2_UPDATE_KEY_SM_GET_STATUS,

    #endif
    HSM_L2_UPDATE_KEY_SM_STOP,
} HSM_L2_DrvUpdateKeySMType;

typedef enum
{
    HSM_L2_REVOKE_KEY_SM_READY,
    HSM_L2_REVOKE_KEY_SM_CHECK_EXIST,
    HSM_L2_REVOKE_KEY_SM_REVOKE,
    #if 0
    HSM_L2_REVOKE_KEY_SM_TIDYUP,
    #endif
    HSM_L2_REVOKE_KEY_SM_STOP,
} HSM_L2_DrvRevokeKeySMType;

typedef enum
{
    HSM_L2_ECC_VERIFY_SM_READY,
    HSM_L2_ECC_VERIFY_SM_HASH,
    HSM_L2_ECC_VERIFY_SM_VERIFY,
    HSM_L2_ECC_VERIFY_SM_STOP,
} HSM_L2_DrvEccVerifySMType;

typedef enum {
    HSM_L2_SM2_VERIFY_SM_READY,
    HSM_L2_SM2_VERIFY_SM_GEN_ZA,
    HSM_L2_SM2_VERIFY_SM_HASH_UPDATE,
    HSM_L2_SM2_VERIFY_SM_HASH_FINALLY,
    HSM_L2_SM2_VERIFY_SM_VERIFY,
    HSM_L2_SM2_VERIFY_SM_STOP,
} HSM_L2_DrvSm2VerifySMType;

typedef enum
{
    HSM_L3_UPDATE_KEY_READY,
    HSM_L3_UPDATE_KEY_PROCESS,
    HSM_L3_UPDATE_KEY_STOP
} HSM_L3_UpdateKeySMType;

typedef enum
{
    HSM_OP_NONE,
    HSM_OP_AES_ENCRYPT,
    HSM_OP_AES_DECRYPT,
    HSM_OP_SM4_ENCRYPT,
    HSM_OP_SM4_DECRYPT,
    HSM_OP_CMAC,
    HSM_OP_RNG,
    HSM_OP_SHA,
    HSM_OP_MD5,
    HSM_OP_SM3,
    #if 0
    /*
     * IF use key id of RSA E/D/N, the key data in key space of HSM side,
     * only support 4B format,
     * and the N size must 8bytes aligned,
     * the D/E size should equal to N size.
     * So use HSM_L1_BnCalc instead.
     */

    HSM_OP_RSA,
    #endif
    HSM_OP_ECC_VERIFY,
    HSM_OP_ECC_EASYDECRY,
    HSM_OP_ECC_CALC,
    HSM_OP_BN_CALC,
    HSM_OP_SCATTER_HASH,
    HSM_OP_SCATTER_CMAC,
    HSM_OP_ECC_SIGN,
    HSM_OP_RSA_SSA_PSS_VERIFY,
    HSM_OP_RSA_SSA_PKCS1V15_VERIFY,
    HSM_OP_KEY_MANAGE_IMPORT,
    HSM_OP_KEY_MANAGE_VALIDATE,
    HSM_OP_KEY_MANAGE_COPY,
    HSM_OP_KEY_MANAGE_REVOKE,
    HSM_OP_KEY_MANAGE_TIDYUP,
    HSM_OP_KEY_MANAGE_GETSTATUS,
    HSM_OP_RSA_SSA_PKCS1V15_SIGN,
    HSM_OP_RSA_SSA_PSS_SIGN,

    HSM_OP_KEY_MANAGE_GET_ID_STATUS,

    #if ((FC7XXX_HSM_SUBSYSTEM_TYPE == FC7240_HSM_SUBSYSTEM) || (FC7XXX_HSM_SUBSYSTEM_TYPE == FC7300_HSM_SUBSYSTEM))
    #else

    HSM_OP_KEY_MANAGE_UPDATE_KEY_ID_CONTENT,
    #endif
    HSM_OP_LOAD_FIRMWARE,
    HSM_OP_SM2_VERIFY,
    HSM_OP_SM2_GEN_ZA,
} HSM_DrvOpCatagoryType;

typedef enum
{
    HFA_MD5 = 0,
    HFA_SHA160 = 1,
    HFA_SHA224 = 2,
    HFA_SHA256 = 3,
    HFA_SHA384 = 4,
    HFA_SHA512 = 5,
    HFA_SHA512_224 = 6,
    HFA_SHA512_256 = 7,
    HFA_SM3 = 8,
} HFAM_MODE_E;

typedef enum
{
    HSM_L1_BNCALC_A_ADD_B = 0,
    HSM_L1_BNCALC_A_SUB_B,
    HSM_L1_BNCALC_B_SUB_A,
    HSM_L1_BNCALC_A_x_B,
    HSM_L1_BNCALC_A_Exp_E,
    HSM_L1_BNCALC_A_MOD,
    HSM_L1_BNCALC_A_RECIPROCAL,
} HSM_L1_BnCalcTypeType;

/********************************************* global typedef *********************************************************/
/**
 * @brief Type definition for algorithm stop callback registered in HSM_Ln_Init API.
 *
 */
typedef void (*HSM_CleanDcacheCbType)(void);

/**
 * @brief Type definition for algorithm stop callback registered in HSM_Ln_Init API.
 *
 */
typedef void (*HSM_CleanAndFlushDcacheCbType)(void);

/**
 * @brief Type definition for algorithm stop callback registered in HSM_Ln_Init API.
 *
 */
typedef void (*HSM_StopCbType)(void *pLnCtx, HSM_BoolType bErrorHappen, HSM_StatusType eRet);

/**
 * @brief Type definition for send command callback registered in HSM_Ln_Init API.
 *
 */
typedef HSM_StatusType(*HSM_SendCommandCbType)(HSM_CmdType *);

/**
 * @brief Type definition for get ack callback registered in HSM_Ln_Init API.
 *
 */
typedef HSM_StatusType(*HSM_GetAckStatCbType)(void);

/**
 * @brief Type definition for cancel command callback registered in HSM_Init API.
 *
 */
typedef HSM_StatusType(*HSM_CancelCmdCbType)(void);

/**
 * @brief Ecc curve type
 *
 */
typedef struct
{
    const hsm_uint8_t *pP;     /*!< address is 4bytes aligned, ecc curve modulus */
    hsm_uint32_t       u32PByteCnt;

    const hsm_uint8_t *pN;     /*!< address is 4bytes aligned, ecc curve order; size; the count of all possible EC points */
    hsm_uint32_t       u32NByteCnt;

    const hsm_uint8_t *pA;     /*!< address is 4bytes aligned, the constant "a" in y^2 = x^3 + a*x + b (mod p) */
    hsm_uint32_t       u32AByteCnt;

    const hsm_uint8_t *pB;     /*!< address is 4bytes aligned, the constant "b" in y^2 = x^3 + a*x + b (mod p) */
    hsm_uint32_t       u32BByteCnt;

    const hsm_uint8_t *pGx;    /*!< address is 4bytes aligned, x of the curve generator point G {x, y} */
    hsm_uint32_t       u32GxByteCnt;

    const hsm_uint8_t *pGy;    /*!< address is 4bytes aligned, y of the curve generator point G {x, y} */
    hsm_uint32_t       u32GyByteCnt;
} HSM_L1_EccCurveParamType;

/**
 * @brief L1 Rsa config type
 *
 */
typedef struct
{
    const hsm_uint8_t        *pInputData;             /*!< address is 4bytes aligned, input data, if not 64bytes align, the last uint64_t's high byte left to patch 0 to align */
    hsm_uint32_t              u32InputDataByteCount;  /*!< the byte count of input data */
    HSM_DataFormatType        eInputDataFmt;

    hsm_uint32_t              u32KeyEId;
    const hsm_uint8_t        *pKeyE;                  /*!< address is 4bytes aligned, input key E data for "A = (input data)^E mod N", if not 64bytes align, the last uint64_t's high byte left to patch 0 to align */
    hsm_uint32_t              u32KeyEByteCount;       /*!< the byte count of key E */
    HSM_DataFormatType        eKeyEFmt;

    hsm_uint32_t              u32KeyNId;
    const hsm_uint8_t        *pKeyN;                  /*!< address is 4bytes aligned, input key N data for "A = (input data)^E mod N", if not 64bytes align, the last uint64_t's high byte left to patch 0 to align */
    hsm_uint32_t              u32KeyNByteCount;       /*!< hw will get the actual key data bit count according to the non-zero bit count, it means key not generate by multiply 2 */
    HSM_DataFormatType        eKeyNFmt;

    hsm_uint8_t              *pResult;                /*!< address is 4bytes aligned, output buffer, the buffer size should >= "u32Key_N_ByteCount" */
    hsm_uint32_t              u32ResultBufByteCnt;    /*!< the result buffer size */
    hsm_uint32_t             *pResultByteCnt;         /*!< the result size */
    HSM_DataFormatType        eOutputFmt;
} HSM_L1_RsaType;

/**
 * @brief Ecc sign config type
 *
 */
typedef struct
{
    HSM_DataFormatType             eDataFmt;
    HSM_DrvEccCurvePrmIndexType    u32EccCurve;
    HSM_L1_EccCurveParamType       tCurve;            /*!< ecc curve parameters */

    hsm_uint32_t                   u32PrivateKeyId;
    const hsm_uint8_t             *pPrivate;          /*!< address is 4bytes aligned, public key axis x */
    hsm_uint32_t                   u32PrivateByteCnt;

    const hsm_uint8_t             *pHashData;         /*!< address is 4bytes aligned, hash of the data to verify */
    hsm_uint32_t                   u32HashDataByteCnt;

    hsm_uint8_t                   *pR;                /*!< address is 4bytes aligned, the sign result R of the data to verify */
    hsm_uint32_t                   u32RBufByteCnt;

    hsm_uint8_t                   *pS;                /*!< address is 4bytes aligned, the sign result S of the data to verify */
    hsm_uint32_t                   u32SBufByteCnt;
} HSM_Ln_EccSignType;



/**
 * @brief Drive rand pool type.
 *
 */
typedef struct
{
    hsm_uint32_t               aTrngBuf0[HSM_TRNG_RAND_U32_CNT];
    hsm_uint32_t               u32LFSR;
    hsm_uint32_t               u32LFSRUsedIndex;
    hsm_uint32_t               u32LFSRUsedCnt;
    hsm_uint32_t               u32NoRepeatCnt;
} HSM_DrvRandPoolType;

/**
 * @brief Rsa information type.
 *
 */
typedef struct
{
    hsm_uint32_t                u32NBitCnt;
    HSMCom_RsaType             *pRsaParm;
    hsm_uint8_t                *pResultBuf;
    hsm_uint32_t                u32ResultBufSize;
    hsm_uint32_t               *pResultByteCnt;
    HSM_DataFormatType          eOutFmt;
    hsm_uint32_t                aRsaInputAndResult[128 + 1]; /**< 4096bit for max pkam big number calculate, 1 for address align */
    hsm_uint32_t                aRsaE[128 + 1]; /**< 4096bit for max pkam big number calculate, 1 for address align */
    hsm_uint32_t                aRsaN[128 + 1]; /**< 4096bit for max pkam big number calculate, 1 for address align */
    hsm_uint32_t                aRsaParmBuf[((sizeof(HSMCom_RsaType) + 3) / 4) + 1];
} HSM_DrvRsaInfType;

/**
 * @brief Md5 information type.
 *
 */
typedef struct
{
    HSMCom_Md5ExType           *pParm;
    hsm_uint8_t                *pResultBuf;
    hsm_uint32_t                u32ResultBufSize;
    hsm_uint32_t               *pOutResultSize;
    HSM_BoolType                bSwapOut;
    hsm_uint32_t                aParmBuf[((sizeof(HSMCom_Md5ExType) + 3) / 4) + 1];
    hsm_uint32_t                aResultCacheBuf[4 + 1]; /**< cache buffer for result */
    hsm_uint32_t                aInputCacheBuf[128 + 1];
} HSM_DrvMd5InfType;

/**
 * @brief Sm3 information type.
 *
 */
typedef struct
{
    HSMCom_Sm3ExType           *pParm;
    hsm_uint8_t                *pResultBuf;
    hsm_uint32_t                u32ResultBufSize;
    hsm_uint32_t               *pOutResultSize;
    HSM_BoolType                bSwapOut;
    hsm_uint32_t                aParmBuf[((sizeof(HSMCom_Sm3ExType) + 3) / 4) + 1];
    hsm_uint32_t                aResultCacheBuf[8 + 1]; /**< cache buffer for result */
    hsm_uint32_t                aInputCacheBuf[128 + 1];
} HSM_DrvSm3InfType;

/**
 * @brief Sha information type.
 *
 */
typedef struct
{
    HSMCom_ShaExType           *pParm;
    hsm_uint8_t                *pResultBuf;
    hsm_uint32_t                u32ResultBufSize;
    hsm_uint32_t               *pOutResultSize;
    HSM_BoolType                bSwapOut;
    hsm_uint32_t                aParmBuf[((sizeof(HSMCom_ShaExType) + 3) / 4) + 1];
    hsm_uint32_t                aInputCacheBuf[128 + 1];
    hsm_uint32_t                aShaResultCache[((sizeof(HSM_ShaResultBufType) + 3) / 4) + 1];
} HSM_DrvShaInfType;

/**
 * @brief Trng information type.
 *
 */
typedef struct
{
    HSMCom_TrueRandExType      *pParm;
    hsm_uint8_t                *pResultBuf;
    hsm_uint32_t                u32ResultBufSize;
    hsm_uint32_t                u32GetSize;
    hsm_uint32_t                aParmBuf[((sizeof(HSMCom_TrueRandExType) + 3) / 4) + 1];
    hsm_uint32_t                aRandom[HSM_TRNG_RAND_U32_CNT + 1];
} HSM_DrvTrngInfType;

/**
 * @brief Ecc verify information type.
 *
 */
typedef struct
{
    hsm_uint32_t                  u32NBitCnt;
    HSMCom_EccVerifyType         *pParm;
    hsm_uint32_t                  aP[32 + 1]; /**< 1024bit for max pkam ECC number calculate, 1 for address align */
    hsm_uint32_t                  aN[32 + 1]; /**< 1024bit for max pkam ECC number calculate, 1 for address align */
    hsm_uint32_t                  aA[32 + 1]; /**< 1024bit for max pkam ECC number calculate, 1 for address align */
    hsm_uint32_t                  aB[32 + 1]; /**< 1024bit for max pkam ECC number calculate, 1 for address align */
    hsm_uint32_t                  aGx[32 + 1]; /**< 1024bit for max pkam ECC number calculate, 1 for address align */
    hsm_uint32_t                  aGy[32 + 1]; /**< 1024bit for max pkam ECC number calculate, 1 for address align */
    hsm_uint32_t                  akGx[32 + 1]; /**< 1024bit for max pkam ECC number calculate, 1 for address align */
    hsm_uint32_t                  akGy[32 + 1]; /**< 1024bit for max pkam ECC number calculate, 1 for address align */
    hsm_uint32_t                  aR[32 + 1]; /**< 1024bit for max pkam ECC number calculate, 1 for address align */
    hsm_uint32_t                  aS[32 + 1]; /**< 1024bit for max pkam ECC number calculate, 1 for address align */
    hsm_uint32_t                  aHash[32 + 1]; /**< 1024bit for max pkam ECC number calculate, 1 for address align */
    hsm_uint32_t                  aParmBuf[((sizeof(HSMCom_EccVerifyType) + 3) / 4) + 1];
} HSM_DrvEccVerifyInfType;

/**
 * @brief Ecc decrypt information type.
 *
 */
typedef struct
{
    hsm_uint32_t                  u32NBitCnt;
    HSMCom_EccEasyDecryType      *pParm;

    HSM_DataFormatType            eOutFmt;
    hsm_uint8_t                  *pResultBuf;
    hsm_uint32_t                  u32ResultBufSize;
    hsm_uint32_t                 *pResultByteCnt;

    hsm_uint32_t                  aP[32 + 1]; /**< 1024bit for max pkam ECC number calculate, 1 for address align */
    hsm_uint32_t                  aN[32 + 1]; /**< 1024bit for max pkam ECC number calculate, 1 for address align */
    hsm_uint32_t                  aA[32 + 1]; /**< 1024bit for max pkam ECC number calculate, 1 for address align */
    hsm_uint32_t                  aB[32 + 1]; /**< 1024bit for max pkam ECC number calculate, 1 for address align */
    hsm_uint32_t                  aPrivate[32 + 1]; /**< 1024bit for max pkam ECC number calculate, 1 for address align */
    hsm_uint32_t                  aPlain[32 + 1]; /**< 1024bit for max pkam ECC number calculate, 1 for address align */
    hsm_uint32_t                  akGx[32 + 1]; /**< 1024bit for max pkam ECC number calculate, 1 for address align */
    hsm_uint32_t                  akGy[32 + 1]; /**< 1024bit for max pkam ECC number calculate, 1 for address align */
    hsm_uint32_t                  aEncrypted[32 + 1]; /**< 1024bit for max pkam ECC number calculate, 1 for address align */
    hsm_uint32_t                  aParmBuf[((sizeof(HSMCom_EccEasyDecryType) + 3) / 4) + 1];
} HSM_DrvEccDecryptInfType;

/**
 * @brief Cmac information type.
 *
 */
typedef struct
{
    HSMCom_CMacExType          *pParm;
    hsm_uint8_t                *pResultBuf;
    hsm_uint32_t                u32ResultBufByteCnt;
    hsm_uint32_t               *pOutResultSize;
    HSM_BoolType                bCheckMac;
    const hsm_uint8_t          *pMacToCheck;
    hsm_uint32_t                u32MacToCheckByteCnt;
    Crypto_VerifyResultType    *pVerifyResult;
    HSM_BoolType                bSwapOut;
    hsm_uint32_t                aParmBuf[((sizeof(HSMCom_CMacExType) + 3) / 4) + 1];
    hsm_uint32_t                aResultCacheBuf[8 + 1]; /**< max aes/sm4 key length is 256bit, so use 32bytes, cache buffer for result */
    hsm_uint32_t                aInputCacheBuf[128 + 1];
} HSM_DrvCMacInfType;

/**
 * @brief Aes encrypt information type.
 *
 */
typedef struct
{
    HSMCom_FlexAesEncryptType  *pParm;
    hsm_uint32_t                aParmBuf[((sizeof(HSMCom_FlexAesEncryptType) + 3) / 4) + 1];
    HSM_BoolType                bSwapOut;
    hsm_uint8_t                *pResultBuf;
    hsm_uint32_t                u32ResultByteCnt;
    hsm_uint32_t                u32HsmRetResultSize;
    hsm_uint32_t                aResultCacheBuf[132 + 1]; /**< pkcs7 result size has more 16bytes than input */
    hsm_uint32_t                aInputCacheBuf[128 + 1];
    hsm_uint32_t                aIvData[4 + 1];
} HSM_DrvAesEncryptInfType;

/**
 * @brief Aes decrypt information type.
 *
 */
typedef struct
{
    HSMCom_FlexAesDecryptType  *pParm;
    hsm_uint32_t                u32HsmRetResultSize;
    hsm_uint32_t                aParmBuf[((sizeof(HSMCom_FlexAesDecryptType) + 3) / 4) + 1];
    hsm_uint32_t                aIvData[4 + 1];
} HSM_DrvAesDecryptInfType;

/**
 * @brief Sm4 encrypt information type.
 *
 */
typedef struct
{
    HSMWrap_Sm4EncryptExType    tWrapper;
    HSMCom_Sm4EncryptExType    *pParm;
    hsm_uint32_t                aParmBuf[((sizeof(HSMCom_FlexAesEncryptType) + 3) / 4) + 1];
    HSM_BoolType                bSwapOut;
    hsm_uint8_t                *pResultBuf;
    hsm_uint32_t                u32ResultByteCnt;
    hsm_uint32_t                u32HsmRetResultSize;
    hsm_uint32_t                aResultCacheBuf[132 + 1]; /**< pkcs7 result size has more 16bytes than input */
    hsm_uint32_t                aInputCacheBuf[128 + 1];
    hsm_uint32_t                aIvData[4 + 1];
} HSM_DrvSm4EncryptInfType;

/**
 * @brief Sm4 decrypt information type.
 *
 */
typedef struct
{
    HSMCom_Sm4DecryptExType    *pParm;
    hsm_uint32_t                u32HsmRetResultSize;
    hsm_uint32_t                aParmBuf[((sizeof(HSMCom_Sm4DecryptExType) + 3) / 4) + 1];
    hsm_uint32_t                aIvData[4 + 1];
} HSM_DrvSm4DecryptInfType;

/**
 * @brief Big number calculator information type.
 *
 */
typedef struct
{
    HSMCom_BigNumberCalcType   *pBnCalcParm;
    hsm_uint8_t                *pResultBuf;
    hsm_uint32_t                u32ResultBufSize;
    hsm_uint32_t               *pResultByteCnt;
    HSM_DataFormatType          eOutFmt;
    hsm_uint32_t                aAAndResult[128 + 1]; /**< 4096bit for max pkam big number calculate, 1 for address align */
    hsm_uint32_t                aB[128 + 1];
    hsm_uint32_t                aE[128 + 1]; /**< 4096bit for max pkam big number calculate, 1 for address align */
    hsm_uint32_t                aN[128 + 1]; /**< 4096bit for max pkam big number calculate, 1 for address align */
    hsm_uint32_t                aBnCalcParmBuf[((sizeof(HSMCom_BigNumberCalcType) + 3) / 4) + 1];
} HSM_DrvBnCalcInfType;

/**
 * @brief Ln hash mac config type.
 *
 */
typedef struct
{
    HSM_BoolType             bGenerateMacEn;          /*!< whether generate MAC */
    HSM_HfamMacType          eMacType;                /*!< if enable generating MAC, this should configure */
    union
    {
        const hsm_uint8_t   *pKeyData;                /*!< address is 4bytes aligned, key to generate MAC, if enable generating MAC, this should configure */
        hsm_uint32_t         u32KeyId;
    } tHashMacKeyInfo;
    hsm_uint32_t             u32KeyByteCnt;           /*!< the byte count of key data */
    hsm_uint32_t             u32GenerateMacByteCnt;   /*!< the byte count of MAC data output */
    HSM_DataFormatType       eKeyDataFmt;
    HSM_BoolType             bKeyUseId;
} HSM_Ln_HashMacCfgType;

/**
 * @brief Scatter hash information type.
 *
 */
typedef struct
{
    hsm_uint32_t                u32TimeoutMs;

    HSM_ShaAlgType              eAlg;


    hsm_uint8_t                 *pOut;
    hsm_uint32_t                 u32OutBufSize;
    HSM_DataFormatType           eOutFmt;
    hsm_uint32_t                *pOutSize;

    HSM_ScatterHashSMType        eState;
    const hsm_uint8_t           *pInputData;
    HSM_DataFormatType           eInputFmt;
    hsm_uint32_t                 u32InputTotalSize;
    hsm_uint32_t                 u32ProcessedSize;



    hsm_uint32_t                 u32CacheDataByteCnt;

    HSMCom_ScatterHashType      *pScatterHashParm;

    union
    {
        hsm_uint32_t             aShaResultBuf[((sizeof(HSM_ShaResultBufType) + 3) / 4) + 1];
        hsm_uint32_t             aHashCtx[18];
    } tScatterHashResultShared;

    union
    {
        hsm_uint32_t             aShaParmBuf[((sizeof(HSMCom_ShaExType) + 3) / 4) + 1];
        hsm_uint32_t             aScatterHashParmBuf[((sizeof(HSMCom_ScatterHashType) + 3) / 4) + 1];
    } tScatterHashParamShared;

    HSM_Ln_HashMacCfgType        tMacCfg;
    hsm_uint32_t                 aMacKeyCache[0x21];

    hsm_uint32_t                 aDataBuf[128];
} HSM_DrvScatterHashInfType;

/**
 * @brief Scatter SM CMac information type.
 *
 */
typedef struct
{
    HSM_ScatterCMacSMType       eState;
    hsm_uint32_t                u32TimeoutMs;

    hsm_uint8_t                *pOut;
    hsm_uint32_t                u32OutBufSize;
    HSM_DataFormatType          eOutFmt;
    hsm_uint32_t               *pOutSize;

    const hsm_uint8_t          *pInputData;
    HSM_DataFormatType          eInputFmt;
    hsm_uint32_t                u32InputTotalSize;
    hsm_uint32_t                u32ProcessedSize;
    hsm_uint32_t                u32CacheDataByteCnt;
    hsm_uint32_t                u32CacheProcByteCnt;



    HSM_AesKeyType              eUseKeyType;
    HSM_AesmBackendType         eBackend;
    hsm_uint32_t                u32KeyId;
    HSM_AesKeyBitCntType        eKeyType; /*!< the key bit count, which determine the AES algorithm type */
    hsm_uint32_t                aKeyData[8]; /**< for max 256bit key */

    HSMCom_AesmRawApiType      *pScatterCMacParm;



    union
    {
        hsm_uint32_t            aCMacResultBuf[16];
        hsm_uint32_t            aCMacCtx[16];
    } tScatterCMacResultShared;

    union
    {
        hsm_uint32_t            aCMacParmBuf[((sizeof(HSMCom_CMacType) + 3) / 4) + 1];
        hsm_uint32_t            aScatterCMacParmBuf[((sizeof(HSMCom_AesmRawApiType) + 3) / 4) + 1];
    } tScatterCMacParamShared;

    hsm_uint32_t                aDataBuf[128];
} HSM_DrvScatterCMacInfType;

/**
 * @brief Ecc sign information type.
 *
 */
typedef struct
{
    hsm_uint32_t                      u32NBitCnt;

    HSM_DataFormatType                eOutFmt;
    hsm_uint8_t                      *pR;
    hsm_uint32_t                      u32RBufByteCnt;
    hsm_uint8_t                      *pS;
    hsm_uint32_t                      u32SBufByteCnt;

    HSMCom_EccSignType               *pParm;
    hsm_uint32_t                      aP[32 + 1]; /**< 1024bit for max pkam ECC number calculate, 1 for address align */
    hsm_uint32_t                      aN[32 + 1]; /**< 1024bit for max pkam ECC number calculate, 1 for address align */
    hsm_uint32_t                      aA[32 + 1]; /**< 1024bit for max pkam ECC number calculate, 1 for address align */
    hsm_uint32_t                      aB[32 + 1]; /**< 1024bit for max pkam ECC number calculate, 1 for address align */
    hsm_uint32_t                      aGx[32 + 1]; /**< 1024bit for max pkam ECC number calculate, 1 for address align */
    hsm_uint32_t                      aGy[32 + 1]; /**< 1024bit for max pkam ECC number calculate, 1 for address align */
    hsm_uint32_t                      aPrivate[32 + 1]; /**< 1024bit for max pkam ECC number calculate, 1 for address align */
    hsm_uint32_t                      aR[32 + 1]; /**< 1024bit for max pkam ECC number calculate, 1 for address align */
    hsm_uint32_t                      aS[32 + 1]; /**< 1024bit for max pkam ECC number calculate, 1 for address align */
    hsm_uint32_t                      aHash[32 + 1]; /**< 1024bit for max pkam ECC number calculate, 1 for address align */
    hsm_uint32_t                      aParmBuf[((sizeof(HSMCom_EccSignType) + 3) / 4) + 1];
} HSM_DrvEccSignInfType;

/**
 * @brief Level 1 RSAssa Pss verify type.
 *
 */
typedef struct
{
    hsm_uint32_t                    u32BitCnt;
    HSMCom_RsaSsaPssVerifyType     *pParm;
    hsm_uint32_t                    aParmBuf[((sizeof(HSMCom_RsaSsaPssVerifyType) + 3) / 4) + 1];
    Crypto_VerifyResultType        *pVerifyResult;
} HSM_L1_DrvRSASsaPssVerifyType;

/**
 * @brief Level 1 RSAssa Pkcs15 verify type.
 *
 */
typedef struct
{
    hsm_uint32_t                         u32BitCnt;
    HSMCom_RsaSsaPkcs1V15VerifyType     *pParm;
    hsm_uint32_t                         aParmBuf[((sizeof(HSMCom_RsaSsaPkcs1V15VerifyType) + 3) / 4) + 1];
    Crypto_VerifyResultType             *pVerifyResult;
} HSM_L1_DrvRSASsaPkcs1V15VerifyType;

/**
 * @brief ECC calculate info type.
 *
 */
typedef struct
{
    hsm_uint32_t                      u32NBitCnt;
    HSMCom_EccCalcType               *pParm;

    HSM_DataFormatType                eOutFmt;
    hsm_uint8_t                      *pResultBufX;
    hsm_uint32_t                      u32ResultBufSizeX;
    hsm_uint32_t                     *pResultByteCntX;
    hsm_uint8_t                      *pResultBufY;
    hsm_uint32_t                      u32ResultBufSizeY;
    hsm_uint32_t                     *pResultByteCntY;

    hsm_uint32_t                      aA[32 + 1]; /* 1024bit for max pkam ECC number calculate, 1 for address align */
    hsm_uint32_t                      aB[32 + 1]; /* 1024bit for max pkam ECC number calculate, 1 for address align */
    hsm_uint32_t                      aP[32 + 1]; /* 1024bit for max pkam ECC number calculate, 1 for address align */
    hsm_uint32_t                      aN[32 + 1]; /* 1024bit for max pkam ECC number calculate, 1 for address align */
    hsm_uint32_t                      aP1x[32 + 1]; /* 1024bit for max pkam ECC number calculate, 1 for address align */
    hsm_uint32_t                      aP1y[32 + 1]; /* 1024bit for max pkam ECC number calculate, 1 for address align */
    hsm_uint32_t                      aE[32 + 1]; /* 1024bit for max pkam ECC number calculate, 1 for address align */
    hsm_uint32_t                      aP2x[32 + 1]; /* 1024bit for max pkam ECC number calculate, 1 for address align */
    hsm_uint32_t                      aP2y[32 + 1]; /* 1024bit for max pkam ECC number calculate, 1 for address align */
    hsm_uint32_t                      aResultX[32 + 1]; /* 1024bit for max pkam ECC number calculate, 1 for address align */
    hsm_uint32_t                      aResultY[32 + 1]; /* 1024bit for max pkam ECC number calculate, 1 for address align */
    hsm_uint32_t                      aParmBuf[((sizeof(HSMCom_EccCalcType) + 3) / 4) + 1];
} HSM_DrvEccCalcInfType;


typedef struct
{
    HSMCom_BigNumberCalcExtType      *pBnCalcParm;
    hsm_uint8_t                      *pResultBuf;
    hsm_uint32_t                      u32ResultBufSize;
    hsm_uint32_t                     *pResultByteCnt;
    HSM_DataFormatType                eOutFmt;

    hsm_uint32_t                      aResultCache[128 + 1]; /* 4096bit for max pkam big number calculate, 1 for address align */
    hsm_uint32_t                      aB[128 + 1];
    hsm_uint32_t                      aBnCalcParmBuf[((sizeof(HSMCom_BigNumberCalcExtType) + 3) / 4) + 1];
    hsm_uint32_t                      u32ResultByteCnt;
} HSM_DrvBnCalcExtInfType;

typedef struct
{
    HSMCom_UserKeyManageType            *pParm;
    hsm_uint32_t                         aParmBuf[((sizeof(HSMCom_UserKeyManageType) + 3) / 4) + 1];

    union
    {
        #if ((FC7XXX_HSM_SUBSYSTEM_TYPE == FC7240_HSM_SUBSYSTEM) || (FC7XXX_HSM_SUBSYSTEM_TYPE == FC7300_HSM_SUBSYSTEM))
        KeyManager_UserKeyStatusType     tKeyIdStatus;
        #endif

        hsm_uint32_t                     aAlignedDataBuffer[(128 * 3) + 1]; /* FC7300/7240/7300GT only use 128 words, following is 128 * 3 */
    } tKeyInfoShared;
} HSM_DrvKeyManageInfType;

typedef struct
{
    HSMCom_KeySpaceStatusType            *pSpaceParm;
    hsm_uint32_t                          aParmBuf[((sizeof(HSMCom_KeySpaceStatusType) + 3) / 4) + 1];
    HSM_Ln_KeySpaceStatusType             tKeySpaceStatus;
} HSM_DrvKeySpaceInfType;

typedef struct
{
    hsm_uint32_t                         u32BitCnt;
    HSMCom_RsaSsaPkcs1v15SignType       *pParm;
    hsm_uint32_t                         aParmBuf[((sizeof(HSMCom_RsaSsaPkcs1v15SignType) + 3) / 4) + 1];
} HSM_L1_DrvRSASsaPkcs1V15SignType;

typedef struct
{
    hsm_uint32_t                    u32BitCnt;
    HSMCom_RsaSsaPssSignType       *pParm;
    hsm_uint32_t                    aParmBuf[((sizeof(HSMCom_RsaSsaPssSignType) + 3) / 4) + 1];
} HSM_L1_DrvRSASsaPssSignType;

typedef struct {
    HSMCom_LoadFirmwareType           *pParm;
    uint32                      aParmBuf[((sizeof(HSMCom_LoadFirmwareType)+3)/4)+1];
} HSM_DrvLoadFirmwareInfType;

#define HSM_SM2_USERID_MAX_LENGTH (128U)/*max length of user id, for mcal ,this parameter is configed by user*/

typedef struct
{
    HSM_BoolType bUseDefaultID;     /*!< true means use default ID. false means use specific ID with "pInputData_ID" and "u32SM2InputIDByteCnt" params. */

    hsm_uint32_t                   u32PublicKeyId;
    const hsm_uint8_t             *pkGx;             /*!< address is 4bytes aligned, public key axis x */
    hsm_uint32_t                   u32kGxByteCnt;
    const hsm_uint8_t             *pkGy;             /*!< address is 4bytes aligned, public key axis y */
    hsm_uint32_t                   u32kGyByteCnt;
    HSM_DataFormatType             ekGxyDataFmt;

    const hsm_uint8_t   *pInputData_ID;
    hsm_uint32_t u32SM2InputIDByteCnt;  /*!< the length should be <= 32bytes note: If "bUseDefaultID" is false, would use this specific ID length with byte unit. */
    const hsm_uint8_t             *pData;         /*!< address is 4bytes aligned, if input hash, hash of the data to verify, if raw data to hash, it point to raw data */
    hsm_uint32_t                   u32DataByteCnt;
    HSM_DataFormatType             eDataFmt;

    const hsm_uint8_t             *pR;                /*!< address is 4bytes aligned, the sign result R of the data to verify */
    hsm_uint32_t                   u32RByteCnt;
    const hsm_uint8_t             *pS;                /*!< address is 4bytes aligned, the sign result S of the data to verify */
    hsm_uint32_t                   u32SByteCnt;
    HSM_DataFormatType             eRSDataFmt;
} HSM_L1_Sm2VerifyType;

typedef struct {
    HSMCom_Sm2VerifyType             *pParm;
    hsm_uint32_t                      akGx[8];
    hsm_uint32_t                      akGy[8];
    hsm_uint32_t                      aR[8];
    hsm_uint32_t                      aS[8];
    hsm_uint32_t                      aHash[8];
    hsm_uint32_t                      aUserID[(HSM_SM2_USERID_MAX_LENGTH + 3)/4];
    hsm_uint32_t                      aParmBuf[((sizeof(HSMCom_Sm2VerifyType)+3)/4)+1];
} HSM_DrvSm2VerifyInfType;

typedef struct {
    HSMCom_Sm2GenZaType             *pParm;
    HSM_BoolType                     bSwapOut;
    hsm_uint32_t                      akGx[8];
    hsm_uint32_t                      akGy[8];
    hsm_uint32_t                      aUserID[(HSM_SM2_USERID_MAX_LENGTH + 3)/4];
    hsm_uint32_t                      aParmBuf[((sizeof(HSMCom_Sm2GenZaType)+3)/4)+1];
} HSM_DrvSm2GenZaInfType;

typedef struct {
    HSM_BoolType bUseDefaultID;     /*!< true means use default ID. false means use specific ID with "pInputData_ID" and "u32SM2InputIDByteCnt" params. */

    hsm_uint32_t                   u32PublicKeyId;
    const hsm_uint8_t             *pkGx;             /*!< address is 4bytes aligned, public key axis x */
    hsm_uint32_t                   u32kGxByteCnt;
    const hsm_uint8_t             *pkGy;             /*!< address is 4bytes aligned, public key axis y */
    hsm_uint32_t                   u32kGyByteCnt;
    HSM_DataFormatType             ekGxyDataFmt;

    const hsm_uint8_t   *pInputData_ID;
    hsm_uint32_t u32SM2InputIDByteCnt;  /*!< the length should be <= 32bytes note: If "bUseDefaultID" is false, would use this specific ID length with byte unit. */
    HSM_DataFormatType             eDataFmt;

    hsm_uint32_t (*pOutputData_Za)[8];
    HSM_DataFormatType             eOutputFmt;
}HSM_LN_Sm2GenZaType;

/**
 * @brief The structure of the HSM level 1 processing handle
 *
 */
typedef struct  HSM_L1_RtCtxType_tag
{
    HSM_TriggerSrcType            eTriggerSrc;
    HSM_StopCbType                pStopCb;
    HSM_SendCommandCbType         pSendCmdCb;
    HSM_GetAckStatCbType          pReadAckCb;
    HSM_CancelCmdCbType           pCancelCmdCb;
    HSM_CleanDcacheCbType         pCleanDCache;
    HSM_CleanAndFlushDcacheCbType pCleanAndFlushDcache;

    HSM_BoolType                  bInProcess;
    hsm_uint32_t                  eOperationCata; /* HSM_DrvOpCatagoryType deceide using which info structure */
    HSM_L1_DrvSMType              eStat;


    hsm_uint32_t                  eLastestHsmRet; /* HSM_StatusType */
    hsm_uint32_t                  u32CurStatInf;
    HSM_DrvRandPoolType           tRandPool;
    HSM_CmdType                   tCmd;



    union
    {
        #if 0
        HSM_DrvRsaInfType         tRsaInf;
        #endif
        HSM_DrvMd5InfType         tMd5Inf;
        HSM_DrvSm3InfType         tSm3Inf;
        HSM_DrvShaInfType         tShaInf;
        HSM_DrvTrngInfType        tRngInf;
        HSM_DrvEccVerifyInfType   tEccVerifyInf;
        HSM_DrvEccDecryptInfType  tEccDecryptInf;
        HSM_DrvCMacInfType        tCMacInf;
        HSM_DrvAesEncryptInfType  tAesEncryptInf;
        HSM_DrvAesDecryptInfType  tAesDecryptInf;
        HSM_DrvSm4EncryptInfType  tSm4EncryptInf;
        HSM_DrvSm4DecryptInfType  tSm4DecryptInf;
        HSM_DrvBnCalcExtInfType   tBnCalcInf;


        HSM_DrvScatterHashInfType tScatterHash;
        HSM_DrvScatterCMacInfType tScatterCMac;

        HSM_DrvEccSignInfType     tEccSignInf;

        HSM_L1_DrvRSASsaPssVerifyType       tRsaSsaPssVerify;
        HSM_L1_DrvRSASsaPkcs1V15VerifyType  tRsaSsaPkcs1V15Verify;
        HSM_DrvEccCalcInfType               tEccCalc;
        HSM_DrvKeyManageInfType             tKeyInf;
        HSM_DrvKeySpaceInfType              tKeySpaceInf;

        HSM_L1_DrvRSASsaPkcs1V15SignType    tRsaSsaPkcs1v15Sign;
        HSM_L1_DrvRSASsaPssSignType         tRsaSsaPssSign;
        HSM_DrvLoadFirmwareInfType tLoadFirmware;
        HSM_DrvSm2VerifyInfType             tSm2VerifyInf;
        HSM_DrvSm2GenZaInfType              tSm2GenZaInf;
        #if 0
        HSM_DrvAesEnDecryInfType  tAesEnDecryInf;
        HSM_DrvSm4EnDecryInfType  tSm4EnDecryptInf;
        HSM_DrvSm2InfType         tSm2Inf;
        HSM_DrvXCMacInfType       tXCMacInf;
        HSM_DrvCcmGcmInfType      tCcmGcmInf;
        HSM_DrvRngmInfType        tRngmInf;
        HSM_DrvHfamInfType        tHfamInf;
        HSM_DrvFlexHfamInfType    tFlexHfamInf;
        HSM_DrvScatterHfamInfType tScatterHfamInf;

        HSM_DrvEccInfType         tEccInf;
        HSM_DrvKdfInfType         tKdfInf;
        HSM_DrvFlexAesInfType     tFlexAes;
        HSM_DrvScatterXCmacType   tScatterXCmacInf;
        HSM_DrvEccCalcType        tEccCalcInf;
        #endif
    } tL1AlgCtx;

} HSM_L1_RtCtxType;

/**
 * @brief The structure of the aes encrypt type
 *
 */
typedef struct
{
    hsm_uint32_t                u32KeyId;
    HSM_AesKeyType              eUseKeyType;        /*!< the key source:vendor key programmed in nvr flash or new key in software */
    HSM_AesNewKeyInfType        tNewKeyInf;         /*!< when eUseKeyType is HSM_AES_KEY_NEW, this MUST configure */
    HSM_AesVendorKeyInfType     tVendorKeyInf;      /*!< when eUseKeyType is HSM_AES_KEY_CHIP_VENDOR_IFR, this MUST configure */
    HSM_SymmEnDecryptAlgType    eAesAlg;            /*!< encrypt/decrypt mode */

    const hsm_uint8_t          *pDataInput;         /*!< address should align with 4bytes */
    hsm_uint32_t                u32InputByteCnt;    /*!< 128bit(16Bytes) align */
    hsm_uint8_t                *pDataOutput;        /*!< address should align with 4bytes */
    hsm_uint32_t                u32OutputMemSize;   /*!< the output data buffer "pDataOutput" size, should >= "u32InputByteCnt" */

    const hsm_uint8_t          *pIvData; /*!< address should align with 4bytes, 128bit(16Bytes) iv(initialization vector) data array, ECB not need configure this */

    HSM_FlexAesPadType          ePad;     /*!< for encrypt, if data size not 16bytes aligned, the pad byte should refer to this configuration,
                                            for decrypt, driver to process the padding data according to this,
                                            however, if zero padding, driver will not remove the padding 0, user should delete the data manually  */
    HSM_DataFormatType          eInputFmt; /*!< key/iv/input data organized format, hsm_uint8_t array, or hsm_uint32_t array */
    HSM_DataFormatType          eOutputFmt; /*!< output result data format  */
    hsm_uint32_t               *pGenerateOutByteCnt; /*!< point to the hsm_uint8_t variable to store the result byte count, can't be NULL */
} HSM_Ln_AesEncryptType;

/**
 * @brief SM4 Encrypt config type
 *
 */
typedef HSM_Ln_AesEncryptType HSM_Ln_Sm4EncryptType;

/**
 * @brief The structure of the HSM level 2 processing handle
 *
 */
typedef struct
{
    HSM_L2_DrvCMacEmptySMType   eStat;
    hsm_uint8_t                *pOut;
    hsm_uint32_t                u32OutBufSize;
    HSM_DataFormatType          eOutFmt;
    hsm_uint32_t               *pOutSize;

    HSM_Ln_AesEncryptType       tParm;
    HSM_AesmBackendType         eBackend;

    hsm_uint32_t                aResultCacheBuf[4 + 1]; /**< pkcs7 result size has more 16bytes than input */
    hsm_uint32_t                aInputCacheBuf[4 + 1];
    hsm_uint32_t                aIvData[4 + 1];
    hsm_uint32_t                aKeyData[8 + 1];
} HSM_L2_DrvCMacEmptyInfType;

typedef struct
{
    HSM_L2_DrvUpdateKeySMType       eStat;
    hsm_uint32_t                    u32Id;
    hsm_uint32_t                   *pKeyIdOut;
    HSM_BoolType                    bTidyUpAlready;

    HSM_Ln_ImportUserKeyExtType     tImportCfg;
    HSM_Ln_KeySpaceStatusType       tKeySpaceStatus;

    #if (FC7XXX_HSM_SUBSYSTEM_TYPE == FC7240_HSM_SUBSYSTEM) || (FC7XXX_HSM_SUBSYSTEM_TYPE == FC7300_HSM_SUBSYSTEM)
    #else

    HSM_Ln_KeyManagerUpdateUserKeyType tUpdateKeyCfg;
    #endif
} HSM_L2_DrvUpdateKeyInfType;

typedef struct
{
    HSM_L2_DrvRevokeKeySMType       eStat;
    hsm_uint32_t                    u32Id;
    union
    {
        HSM_Ln_KeySpaceStatusType   tKeySpaceStatus;
    };
} HSM_L2_DrvRevokeKeyInfType;

/**
 * @brief Ecc decrypt type
 *
 */
typedef struct
{
    HSM_DataFormatType             eInputDataFmt;
    HSM_DataFormatType             eOutputDataFmt;

    HSM_DrvEccCurvePrmIndexType    u32EccCurve;
    HSM_L1_EccCurveParamType       tCurve;            /*!< ecc curve parameters */

    hsm_uint32_t                   u32PublicKeyId;
    const hsm_uint8_t             *pkGx;             /*!< address is 4bytes aligned, public key axis x */
    hsm_uint32_t                   u32kGxByteCnt;
    const hsm_uint8_t             *pkGy;             /*!< address is 4bytes aligned, public key axis y */
    hsm_uint32_t                   u32kGyByteCnt;

    hsm_uint32_t                   u32PrivateKeyId;
    const hsm_uint8_t             *pPrivateKey;         /*!< address is 4bytes aligned, hash of the data to verify */
    hsm_uint32_t                   u32PrivateKeyByteCnt;

    const hsm_uint8_t             *pEncryptedData;                /*!< address is 4bytes aligned, the sign result S of the data to verify */
    hsm_uint32_t                   u32EncryptedDataByteCnt;

    hsm_uint8_t                   *pPlainData;                /*!< address is 4bytes aligned, the sign result R of the data to verify */
    hsm_uint32_t                   u32PlainDataBufferByteCnt;
    hsm_uint32_t                  *pPlainResultByteCnt;
} HSM_Ln_EccDecryptType;

typedef struct
{

    HSM_DrvEccCurvePrmIndexType    u32EccCurve;
    HSM_L1_EccCurveParamType       tCurve;            /*!< ecc curve parameters */
    HSM_DataFormatType             eCurveDataFmt;

    hsm_uint32_t                   u32PublicKeyId;
    const hsm_uint8_t             *pkGx;             /*!< address is 4bytes aligned, public key axis x */
    hsm_uint32_t                   u32kGxByteCnt;
    const hsm_uint8_t             *pkGy;             /*!< address is 4bytes aligned, public key axis y */
    hsm_uint32_t                   u32kGyByteCnt;
    HSM_DataFormatType             ekGxyDataFmt;

    const hsm_uint8_t             *pData;         /*!< address is 4bytes aligned, if input hash, hash of the data to verify, if raw data to hash, it point to raw data */
    hsm_uint32_t                   u32DataByteCnt;
    HSM_DataFormatType             eDataFmt;

    const hsm_uint8_t             *pR;                /*!< address is 4bytes aligned, the sign result R of the data to verify */
    hsm_uint32_t                   u32RByteCnt;
    HSM_DataFormatType             eRDataFmt;

    const hsm_uint8_t             *pS;                /*!< address is 4bytes aligned, the sign result S of the data to verify */
    hsm_uint32_t                   u32SByteCnt;
    HSM_DataFormatType             eSDataFmt;
} HSM_L1_EccVerifyType;


/**
 * @brief Ecc verify type
 *
 */
typedef struct
{
    HSM_EccVerifyInputType         eInputType;
    HSM_ShaAlgType                 eAlg;
    Crypto_VerifyResultType       *pVerifyResult;
    HSM_L1_EccVerifyType           tVerifyParm;
} HSM_Ln_EccVerifyType;

/**
 * @brief Sha information used by driver when call specific API
 *
 */
typedef struct
{
    HSM_ShaAlgType      eAlg;
    HSM_ShaCtxType      tCfg; /*!< algorithm parameter set by user */
    hsm_uint8_t        *pResult; /*!< MD5 result is 16bytes, point to the memory that driver to store result */
    hsm_uint32_t        u32ResultBufSize; /*!< the size of buffer 'pResult' to store result */
    hsm_uint32_t       *pResultSize;
    HSM_DataFormatType  eInputFmt; /*!< input data organized format, hsm_uint8_t array, or hsm_uint32_t array */
    HSM_DataFormatType  eOutputFmt; /*!< output data organized format, hsm_uint8_t array, or hsm_uint32_t array */
    HSM_BoolType        bKeyUseId;
} HSM_Ln_ShaType;

typedef struct
{
    hsm_uint32_t                    u32BitCnt;
    HSM_L2_DrvEccVerifySMType       eStat;
    hsm_uint32_t                    aCache[17]; /* for max sha512 */
    HSM_Ln_EccVerifyType            tEccCfg;
    HSM_Ln_ShaType                  tShaParm;
} HSM_L2_DrvEccVerifyInfType;

/**
 * @brief HSM_ECC_VERIFY_INPUT_RAW_MESSAGE value for type "HSM_EccVerifyInputType"
 */
#define HSM_SM2_VERIFY_INPUT_RAW_MESSAGE  0u

/**
 * @brief HSM_ECC_VERIFY_INPUT_HASH_DATA value for type "HSM_EccVerifyInputType"
 */
#define HSM_SM2_VERIFY_INPUT_HASH_DATA    1u

typedef hsm_uint32_t HSM_Sm2VerifyInputType;

/**
 * @brief Scatter hash level n type
 *
 */
typedef struct
{
    const hsm_uint8_t      *pData;
    hsm_uint32_t            u32DataSize;
    HSM_DataFormatType      eDataFmt;
} HSM_Ln_ScatterHashType;

/**
 * @brief HSM result buffer type
 *
 */
typedef struct
{
    hsm_uint8_t            *pData;
    hsm_uint32_t            u32DataBufSize;
    HSM_DataFormatType      eDataFmt;
    hsm_uint32_t           *pDataSize;
} HSM_Ln_ResultBufInfoType;

typedef struct
{
    HSM_Sm2VerifyInputType         eInputType;
    Crypto_VerifyResultType       *pVerifyResult;
    HSM_L1_Sm2VerifyType           tVerifyParm;
} HSM_Ln_Sm2VerifyType;

typedef struct {
    HSM_L2_DrvSm2VerifySMType       eStat;
    HSM_Ln_Sm2VerifyType            tSm2Cfg;
    HSM_LN_Sm2GenZaType             tSm2GenZaCfg;
    HSM_Ln_ScatterHashType          tScatterSm3Cfg;
    hsm_uint32_t                    aCache[8];
    HSM_Ln_ResultBufInfoType        tScatterSm3Result;
} HSM_L2_DrvSm2VerifyInfType;

/**
 * @brief The structure of the HSM level 2 processing handle
 *
 */
typedef struct HSM_L2_RtCtxType_tag
{
    HSM_L2_DrvOpType      eOperation;
    HSM_StopCbType        pStopCb;
    union
    {

        HSM_L2_DrvCMacEmptyInfType          tCMacEmpty;

        HSM_L2_DrvUpdateKeyInfType          tUpdateKey;

        HSM_L2_DrvRevokeKeyInfType          tRevokeKey;

        HSM_L2_DrvEccVerifyInfType          tEccVerify;

        HSM_L2_DrvSm2VerifyInfType          tSm2Verify;
        #if 0
        HSM_Level2nd_DrvRSASsaPssSignType           tRsaSsaPssSign;

        HSM_Level2nd_DrvRSASsaPkcs1V15SignType      tRsaSsaPkcs1V15Sign;


        HSM_Level2nd_DrvRSAEsPkcs1V15EncryptType    tRsaEsPkcs1V15Encrypt;
        HSM_Level2nd_DrvRSAEsPkcs1V15DecryptType    tRsaEsPkcs1V15Decrypt;
        HSM_Level2nd_DrvRSAEsOaepEncryptType        tRsaEsOaepEncrypt;
        HSM_Level2nd_DrvRSAEsOaepDecryptType        tRsaEsOaepDecrypt;
        #endif
    } tL2AlgCtx;
} HSM_L2_RtCtxType;

/**
 * @brief The structure of the level 3 cmac config type
 *
 */
typedef struct
{
    HSM_AesKeyType          eUseKeyType;
    hsm_uint32_t            u32KeyId;
    HSM_AesKeyBitCntType    eKeyType; /*!< the key bit count, which determine the AES algorithm type */
    const hsm_uint8_t      *pKeyAddr;
    HSM_DataFormatType      eKeyDataFmt;
    HSM_AesmBackendType     eBackend;
} HSM_Ln_CMacCfgParmsType;


/**
 * @brief The structure of the level 3 scatter cmac infomation type
 *
 */
typedef struct
{
    hsm_uint32_t                u32TimeoutMs;
    HSM_L3_ScatterCMacSMType    eState;
    HSM_Ln_CMacCfgParmsType     tCfgParm;
    hsm_uint32_t                u32InputTotalSize;
} HSM_L3_DrvScatterCMacInfType;

typedef struct
{
    hsm_uint32_t                    u32TimeoutMs;
    HSM_L3_UpdateKeySMType          eState;
    hsm_uint32_t                    aKeyDataCache[129];
} HSM_L3_DrvUpdateKeyInfType;

/**
 * @brief The structure of the HSM level 3 processing handle
 *
 */
typedef struct HSM_L3_RtCtxType_tag
{
    HSM_L3_DrvOpType                       eOperation;
    HSM_StopCbType                         pStopCb;
    union
    {
        HSM_L3_DrvScatterCMacInfType       tScatterCMac;
        HSM_L3_DrvUpdateKeyInfType         tUpdateKey;
    } tL3AlgCtx;
} HSM_L3_RtCtxType;

/**
 * @brief The structure of the HSM processing handle
 *
 */
typedef struct
{
    hsm_uint32_t     u32OpLimitMs;
    HSM_L1_RtCtxType tHsmL1Ctx;
    HSM_L2_RtCtxType tHsmL2Ctx;
    HSM_L3_RtCtxType tHsmL3Ctx;
} HSM_Ln_RtCtxType;

/**
 * @brief init information for HSM_Ln_Init
 *
 */
typedef struct
{
    HSM_TriggerSrcType            eTriggerSrc;
    HSM_StopCbType                pStopCb;
    HSM_SendCommandCbType         pSendCmdCb;
    HSM_GetAckStatCbType          pReadAckCb;
    HSM_CancelCmdCbType           pCancelCmdCb;
    HSM_CleanDcacheCbType         pCleanDCache;
    HSM_CleanAndFlushDcacheCbType pCleanAndFlushDcache;
    hsm_uint32_t                  u32OpLimitMs;
} HSM_Ln_InitParmType;


/**
 * @brief RSA PSS signature verify information used by driver when call specific API
 *
 */
typedef struct
{
    hsm_uint32_t              u32EmBitCnt; /* RFC8017 require set it to (N's bit count - 1). the em data bit count, it MUST < N's bit count, should keep same with the signature generate configuration */
    HSM_HashAlgType           eMgfHashType; /*!< the hash type used by signature */
    HSM_HashAlgType           eHashType; /*!< the hash type used by signature */
    hsm_uint32_t              u32SaltByteCount; /*!< the byte count of salt data, it must > 0, suggest use hash length, for example, if eHashType is HSM_SHA_256, set this to 256/8=32bytes */

    HSM_DataFormatType        eInputDataFmt; /*!< input data(raw message or hash data) organized format, hsm_uint8_t array, or hsm_uint32_t array */
    HSM_RsaSsaInputType       eInputType; /*!< input data type, may raw input message, or the hash data of raw message */
    const hsm_uint8_t        *pInputData; /*!< input data */
    hsm_uint32_t              u32InputDataByteCount; /*!< the byte count of input data, when the eInputType is HSM_RSA_SSA_INPUT_RAW_MESSAGE */

    HSM_DataFormatType        eSignDataFmt; /*!< Signature/Public key/N input data organized format, hsm_uint8_t array, or hsm_uint32_t array */
    const hsm_uint8_t        *pSignData; /*!< input signature data */
    hsm_uint32_t              u32SignDataByteCount; /*!< the byte count of signature data, it must > 0 */

    hsm_uint32_t              u32KeyEId;
    HSM_DataFormatType        ePublicKeyDataFmt;
    const hsm_uint8_t        *pPublicKey; /*!< public key, input key E data for "A = (input data)^E mod N" */
    hsm_uint32_t              u32PublicKeyByteCnt; /*!< the byte count of key E */

    hsm_uint32_t              u32KeyNId;
    HSM_DataFormatType        eKeyNDataFmt;
    const hsm_uint8_t        *pKeyN; /*!< input key N data for "A = (input data)^E mod N" */
    hsm_uint32_t              u32KeyNByteCount; /*!< key N data byte count */

    Crypto_VerifyResultType  *pVerifyResult;
} HSM_Ln_RsaSsaPssVerifyType;

/**
 * @brief RSA PKCS1 V1.5 signature verify information used by driver when call specific API
 *
 */
typedef struct
{
    hsm_uint32_t             u32EmByteCnt; /*!< set it 0 to use default value. RFC8017 require set it to N'byte count, equal to u32KeyNByteCount. the em data byte count, itx8 MUST < N's bit count, should keep same with the signature generate configuration */

    HSM_HashAlgType          eHashType; /*!< the hash type used by signature */

    HSM_DataFormatType       eInputDataFmt; /*!< input data organized format, hsm_uint8_t array, or hsm_uint32_t array */
    const hsm_uint8_t       *pInputData; /*!< input data */
    hsm_uint32_t             u32InputDataByteCount; /*!< the byte count of input data */

    HSM_DataFormatType       eSignDataFmt;
    const hsm_uint8_t       *pSignData; /*!< input signature data */
    hsm_uint32_t             u32SignDataByteCount; /*!< the byte count of signature data, it must > 0 */


    hsm_uint32_t             u32KeyEId;
    HSM_DataFormatType       ePublicKeyFmt;
    const hsm_uint8_t       *pPublicKey; /*!< public key, input key E data for "A = (input data)^E mod N" */
    hsm_uint32_t             u32PublicKeyByteCnt; /*!< the byte count of key E */

    HSM_BoolType             bUseInputDer; /*!< set to HSM_TRUE when RFC8017 not support some hash algorithm, for example SM3 Hash type, DER encoding of the DigestInfo value, if use hsm internal data, just set it to HSM_FALSE */
    const hsm_uint8_t       *pDer; /*!< when bUseInputDer is HSM_TRUE, this field point to the DER encoding of the DigestInfo value, others, ignore */
    hsm_uint32_t             u32DerByteCount; /*!< when bUseInputDer is HSM_TRUE, this field represent the byte count of DER data,  if bUseInputDer is HSM_FALSE, ignore this field */

    hsm_uint32_t             u32KeyNId;
    HSM_DataFormatType       eKeyNFmt;
    const hsm_uint8_t       *pKeyN; /*!< input key N data for "A = (input data)^E mod N" */
    hsm_uint32_t             u32KeyNByteCount; /*!< key N's data byte count */

    Crypto_VerifyResultType *pVerifyResult;
} HSM_Ln_RsaSsaPkcs1v15VerifyType;


/**
 * @brief The structure of the aes decrypt type
 *
 */
typedef struct
{
    hsm_uint32_t                u32KeyId;
    HSM_AesKeyType              eUseKeyType;        /*!< the key source:vendor key programmed in nvr flash or new key in software */
    HSM_AesNewKeyInfType        tNewKeyInf;         /*!< when eUseKeyType is HSM_AES_KEY_NEW, this MUST configure */
    HSM_AesVendorKeyInfType     tVendorKeyInf;      /*!< when eUseKeyType is HSM_AES_KEY_CHIP_VENDOR_IFR, this MUST configure */
    HSM_SymmEnDecryptAlgType    eAesAlg;            /*!< encrypt/decrypt mode */

    const hsm_uint8_t          *pDataInput;         /*!< address should align with 4bytes */
    hsm_uint32_t                u32InputByteCnt;    /*!< 128bit(16Bytes) align */
    hsm_uint8_t                *pDataOutput;        /*!< address should align with 4bytes */
    hsm_uint32_t                u32OutputMemSize;   /*!< the output data buffer "pDataOutput" size, should >= "u32InputByteCnt" */

    const hsm_uint8_t          *pIvData; /*!< address should align with 4bytes, 128bit(16Bytes) iv(initialization vector) data array, ECB not need configure this */

    HSM_FlexAesPadType          ePad;     /*!< for encrypt, if data size not 16bytes aligned, the pad byte should refer to this configuration,
                                            for decrypt, driver to process the padding data according to this,
                                            however, if zero padding, driver will not remove the padding 0, user should delete the data manually  */
    HSM_DataFormatType          eInputFmt; /*!< key/iv/input data organized format, hsm_uint8_t array, or hsm_uint32_t array */
    HSM_DataFormatType          eOutputFmt; /*!< output result data format  */
    hsm_uint32_t               *pGenerateOutByteCnt; /*!< point to the hsm_uint32_t variable to store the result byte count, can't be NULL_PTR */
} HSM_Ln_AesDecryptType;

/**
 * @brief The structure of the sm4 decrypt type
 *
 */
typedef HSM_Ln_AesDecryptType HSM_Ln_Sm4DecryptType;

/**
 * @brief MD5 information used by driver when call specific API
 *
 */
typedef struct
{
    HSM_Md5CtxType        tCfg; /*!< MD5 algorithm parameter set by user */
    hsm_uint8_t          *pResult; /*!< MD5 result is 16bytes, point to the memory that driver to store result */
    hsm_uint32_t          u32ResultBufSize; /*!< the size of buffer 'pResult' to store result */
    hsm_uint32_t         *pResultSize;
    HSM_DataFormatType    eInputFmt; /*!< input data organized format, hsm_uint8_t array, or hsm_uint32_t array */
    HSM_DataFormatType    eOutputFmt; /*!< output data organized format, hsm_uint8_t array, or hsm_uint32_t array */
    HSM_BoolType          bKeyUseId;
} HSM_Ln_Md5Type;

/**
 * @brief Sm3 information used by driver when call specific API
 *
 */
typedef struct
{
    HSM_Sm3CtxType        tCfg; /*!< algorithm parameter set by user */
    hsm_uint8_t          *pResult; /*!< MD5 result is 16bytes, point to the memory that driver to store result */
    hsm_uint32_t          u32ResultBufSize; /*!< the size of buffer 'pResult' to store result */
    hsm_uint32_t         *pResultSize;
    HSM_DataFormatType    eInputFmt; /*!< input data organized format, hsm_uint8_t array, or hsm_uint32_t array */
    HSM_DataFormatType    eOutputFmt; /*!< output data organized format, hsm_uint8_t array, or hsm_uint32_t array */
    HSM_BoolType          bKeyUseId;
} HSM_Ln_Sm3Type;

/**
 * @brief CMAC information used by driver when call specific API
 *
 */
typedef struct
{
    hsm_uint32_t                    u32NewKeyId;
    HSM_AesKeyType                  eUseKeyType;        /*!< fix to HSM_AES_KEY_NEW */
    HSM_AesNewKeyInfType            tNewKeyInf;         /*!< when eUseKeyType is HSM_AES_KEY_NEW, this MUST configure */
    HSM_AesVendorKeyInfType         tVendorKeyInf;      /*!< when eUseKeyType is HSM_AES_KEY_CHIP_VENDOR_IFR, this MUST configure */
    hsm_uint32_t                    u32GenMacByteCnt;   /*!< XCMAC API generate MAC data, it's "u32GenMacByteCnt" size ICV data */
    const hsm_uint8_t              *pDataInput;         /*!< address should align with 4bytes */
    hsm_uint32_t                    u32InputByteCnt;    /*!< 128bit(16Bytes) align */

    hsm_uint8_t                    *pDataOutput;        /*!< address should align with 4bytes */
    hsm_uint32_t                    u32ResultBufSize;   /*!< 4bytes align, the output data buffer "pDataOutput" size, should >= "u32GenMacByteCnt" */
    hsm_uint32_t                   *pResultSize;

    HSM_BoolType                    bCheckMacEn;        /*!< if enable this check, user should place the data after the input data, hsm will check the generated data and it, if fail, hsm generate a interrupt, and if user get hw status, will get a error status */
    const hsm_uint8_t              *pCheckExternalMac;
    hsm_uint32_t                    u32CheckByteCnt;
    Crypto_VerifyResultType        *pVerifyResult;

    HSM_DataFormatType              eInputFmt;
    HSM_DataFormatType              eOutputFmt;
    HSM_XCMacEngineType             eEngine;
} HSM_Ln_CMacType;

/**
 * @brief Rng information used by driver when call specific API
 *
 */
typedef struct
{
    hsm_uint8_t        *pResult; /*!< MD5 result is 16bytes, point to the memory that driver to store result */
    hsm_uint32_t        u32ResultBufSize; /*!< the size of buffer 'pResult' to store result */
    HSM_RndSrcType      eSrc;
} HSM_Ln_RngType;

/**
 * @brief Scatter cmac information used by driver when call specific API
 *
 */
typedef struct
{
    const hsm_uint8_t  *pData;
    hsm_uint32_t        u32DataSize;
    HSM_DataFormatType  eDataFmt;
} HSM_Ln_ScatterCMacType;


/**
 * @brief Ecc level 1 init type
 *
 */
typedef struct
{
    HSM_TriggerSrcType            eTriggerSrc;
    HSM_StopCbType                pStopCb;
    HSM_SendCommandCbType         pSendCmdCb;
    HSM_GetAckStatCbType          pReadAckCb;
    HSM_CancelCmdCbType           pCancelCmdCb;
    HSM_CleanDcacheCbType         pCleanDCache;
    HSM_CleanAndFlushDcacheCbType pCleanAndFlushDcache;
} HSM_L1_InitParmType;

/**
 * @brief Ecc level 2 init type
 *
 */
typedef struct
{
    HSM_StopCbType        pStopCb;
} HSM_L2_InitParmType;

/**
 * @brief Ecc level 3 init type
 *
 */
typedef struct
{
    HSM_StopCbType        pStopCb;
} HSM_L3_InitParmType;


typedef struct
{
    const hsm_uint8_t            *pKeyData;
    HSM_DataFormatType            eKeyDataFmt;
    hsm_uint32_t                  u32KeyDataByteCnt;
    hsm_uint32_t                  u32KeyId;
    HSM_Ln_KeyDataStoreFmtType    eKeyStoreFmt;
    HSM_KeyManagerUserKeyTypeType eKeyUsage;
    HSM_KeyManagerKeyExportType   eExportType;
} HSM_Ln_PlainKeyImport;

typedef struct
{
    hsm_uint32_t            u32RsaBitCnt;
    HSM_DataFormatType      eInputFmt; /*!< input data organized format, uint8_t array, or uint32_t array */
    HSM_DataFormatType      eOutputFmt; /*!< output data organized format, uint8_t array, or uint32_t array */
    HSM_HashAlgType         eHashType; /*!< the hash type used by signature */
    const hsm_uint8_t      *pInputData; /*!< input data */
    hsm_uint32_t            u32InputDataByteCount; /*!< the byte count of input data */
    hsm_uint32_t            u32PrivateKeyId;
    const hsm_uint8_t      *pPrivateKey; /*!< private key, input key E data for "A = (input data)^E mod N" */
    hsm_uint32_t            u32PrivateKeyByteCnt; /*!< the byte count of key E */
    hsm_uint32_t            u32KeyNId;
    const hsm_uint8_t      *pKeyN; /*!< input key N data for "A = (input data)^E mod N" */
    hsm_uint32_t            u32KeyNByteCount; /*!< key N's data byte count */
    hsm_uint8_t            *pResult; /*!< output buffer, the buffer size should >= "u32KeyNByteCount" */
    hsm_uint32_t            u32ResultBufByteCnt; /*!< the result buffer size */
    hsm_uint32_t           *pResultByteCnt; /*!< the result data byte count */
} HSM_Ln_RsaSsaPkcs1V15SignDataType;

typedef struct
{
    hsm_uint32_t            u32RsaBitCnt;
    HSM_DataFormatType      eInputFmt; /*!< input data organized format, uint8_t array, or uint32_t array */
    HSM_DataFormatType      eOutputFmt; /*!< output data organized format, uint8_t array, or uint32_t array */
    HSM_HashAlgType         eHashType; /*!< the hash type used by signature */
    const hsm_uint8_t      *pHashData; /*!< input data */
    hsm_uint32_t            u32HashDataByteCount; /*!< the byte count of input data */
    hsm_uint32_t            u32PrivateKeyId;
    const hsm_uint8_t      *pPrivateKey; /*!< private key, input key E data for "A = (input data)^E mod N" */
    hsm_uint32_t            u32PrivateKeyByteCnt; /*!< the byte count of key E */
    hsm_uint32_t            u32KeyNId;
    const hsm_uint8_t      *pKeyN; /*!< input key N data for "A = (input data)^E mod N" */
    hsm_uint32_t            u32KeyNByteCount; /*!< key N's data byte count */
    hsm_uint8_t            *pResult; /*!< output buffer, the buffer size should >= "u32KeyNByteCount" */
    hsm_uint32_t            u32ResultBufByteCnt; /*!< the result buffer size */
    hsm_uint32_t           *pResultByteCnt; /*!< the result data byte count */
} HSM_Ln_RsaSsaPkcs1V15SignHashType;

typedef struct
{
    hsm_uint32_t            u32RsaBitCnt;
    HSM_BoolType            bUsePseudoRand;
    HSM_DataFormatType      eInputFmt; /*!< input data organized format, uint8_t array, or uint32_t array */
    HSM_DataFormatType      eOutputFmt; /*!< output data organized format, uint8_t array, or uint32_t array */
    HSM_HashAlgType         eHashType; /*!< the hash type used by signature */
    const hsm_uint8_t      *pInputData; /*!< input data */
    hsm_uint32_t            u32InputDataByteCount; /*!< the byte count of input data */
    hsm_uint32_t            u32PrivateKeyId;
    const hsm_uint8_t      *pPrivateKey; /*!< private key, input key E data for "A = (input data)^E mod N" */
    hsm_uint32_t            u32PrivateKeyByteCnt; /*!< the byte count of key E */
    hsm_uint32_t            u32KeyNId;
    const hsm_uint8_t      *pKeyN; /*!< input key N data for "A = (input data)^E mod N" */
    hsm_uint32_t            u32KeyNByteCount; /*!< key N's data byte count */
    hsm_uint8_t            *pResult; /*!< output buffer, the buffer size should >= "u32KeyNByteCount" */
    hsm_uint32_t            u32ResultBufByteCnt; /*!< the result buffer size */
    hsm_uint32_t           *pResultByteCnt; /*!< the result data byte count */
} HSM_Ln_RsaSsaPssSignDataType;

typedef struct
{
    hsm_uint32_t            u32RsaBitCnt;
    HSM_BoolType            bUsePseudoRand;
    HSM_DataFormatType      eInputFmt; /*!< input data organized format, uint8_t array, or uint32_t array */
    HSM_DataFormatType      eOutputFmt; /*!< output data organized format, uint8_t array, or uint32_t array */
    HSM_HashAlgType         eHashType; /*!< the hash type used by signature */
    const hsm_uint8_t      *pHashData; /*!< input data */
    hsm_uint32_t            u32HashDataByteCount; /*!< the byte count of input data */
    hsm_uint32_t            u32PrivateKeyId;
    const hsm_uint8_t      *pPrivateKey; /*!< private key, input key E data for "A = (input data)^E mod N" */
    hsm_uint32_t            u32PrivateKeyByteCnt; /*!< the byte count of key E */
    hsm_uint32_t            u32KeyNId;
    const hsm_uint8_t      *pKeyN; /*!< input key N data for "A = (input data)^E mod N" */
    hsm_uint32_t            u32KeyNByteCount; /*!< key N's data byte count */
    hsm_uint8_t            *pResult; /*!< output buffer, the buffer size should >= "u32KeyNByteCount" */
    hsm_uint32_t            u32ResultBufByteCnt; /*!< the result buffer size */
    hsm_uint32_t           *pResultByteCnt; /*!< the result data byte count */
} HSM_Ln_RsaSsaPssSignHashType;

typedef struct
{
    const hsm_uint8_t *pN;
    hsm_uint32_t       u32NByteCnt;

    const hsm_uint8_t *pE;
    hsm_uint32_t       u32EByteCnt;

    const hsm_uint8_t *pD;
    hsm_uint32_t       u32DByteCnt;
} HSM_L1_PKCS_RsaPrivateKeyInfType;

typedef  struct
{
    const hsm_uint8_t *pPrivate;
    hsm_uint32_t       u32PrivateByteCnt;
} HSM_L1_PKCS_EccPrivateKeyInfType;

typedef struct
{
    HSM_L1_PKCS8_PrivateKeyType          eKeyType;
    union
    {
        HSM_L1_PKCS_RsaPrivateKeyInfType tRsaKeyInf;
        HSM_L1_PKCS_EccPrivateKeyInfType tEccKeyInf;
    } tPrivateInfo;
} HSM_L1_PKCS8_PrivateKeyInfType;

typedef struct
{
    const hsm_uint8_t *pN;
    hsm_uint32_t       u32NByteCnt;

    const hsm_uint8_t *pE;
    hsm_uint32_t       u32EByteCnt;
} HSM_L1_PKCS_RsaPublicKeyInfType;

typedef  struct
{
    const hsm_uint8_t *pKGx;
    hsm_uint32_t       u32KGxByteCnt;

    const hsm_uint8_t *pKGy;
    hsm_uint32_t       u32KGyByteCnt;
} HSM_L1_PKCS_EccPublicKeyInfType;

typedef struct
{
    HSM_L1_PublicKeyType                eKeyType;
    union
    {
        HSM_L1_PKCS_RsaPublicKeyInfType tRsaKeyInf;
        HSM_L1_PKCS_EccPublicKeyInfType tEccKeyInf;
    } tPublicInf;
} HSM_L1_PublicKeyInfType;

typedef struct
{
    hsm_uint32_t                  u32KeyEId;           /*!< means don't load key from HSM, otherwise would load key with KEYID from HSM */
    hsm_uint32_t                  u32KeyNId;           /*!< means don't load key from HSM, otherwise would load key with KEYID from HSM */
    hsm_uint32_t                  u32BitCnt;           /*!< the bit count of numbers used of N */
    HSM_L1_BnCalcTypeType         eCalcType;

    const hsm_uint8_t            *pA;                  /*!< address is 4bytes aligned, input data, if not 64bytes align, the last uint64_t's high byte left to patch 0 to align */
    hsm_uint32_t                  u32AByteCount;       /*!< the byte count of input data */
    HSM_DataFormatType            eAFmt;

    const hsm_uint8_t            *pB;
    hsm_uint32_t                  u32BByteCount;
    HSM_DataFormatType            eBFmt;

    const hsm_uint8_t            *pE;                  /*!< address is 4bytes aligned, input key E data for "A = (input data)^E mod N", if not 64bytes align, the last uint64_t's high byte left to patch 0 to align */
    hsm_uint32_t                  u32EByteCount;       /*!< the byte count of key E */
    HSM_DataFormatType            eEFmt;

    const hsm_uint8_t            *pN;                  /*!< address is 4bytes aligned, input key N data for "A = (input data)^E mod N", if not 64bytes align, the last uint64_t's high byte left to patch 0 to align */
    hsm_uint32_t                  u32NByteCount;       /*!< hw will get the actual key data bit count according to the non-zero bit count, it means key not generate by multiply 2 */
    HSM_DataFormatType            eNFmt;

    hsm_uint8_t                  *pResult;             /*!< address is 4bytes aligned, output buffer, the buffer size should >= "u32Key_N_ByteCount" */
    hsm_uint32_t                  u32ResultBufByteCnt; /*!< the result buffer size */
    hsm_uint32_t                 *pResultByteCnt;
    HSM_DataFormatType            eResultFmt;
} HSM_L1_BnCalcType;

typedef struct
{
    HSM_DataFormatType              eInputDataFmt;
    HSM_DataFormatType              eOutputDataFmt;

    HSM_DrvEccCurvePrmIndexType     u32EccCurve;
    HSM_L1_EccCurveParamType        tCurve;                 /*!< ecc curve parameters */

    hsm_uint32_t                    u32PointId;
    const hsm_uint8_t              *pPointX;                /*!< address is 4bytes aligned, public key axis x */
    hsm_uint32_t                    u32PointXByteCnt;
    const hsm_uint8_t              *pPointY;                /*!< address is 4bytes aligned, public key axis y */
    hsm_uint32_t                    u32PointYByteCnt;

    hsm_uint32_t                    u32KId;
    const hsm_uint8_t              *pK;                     /*!< address is 4bytes aligned, hash of the data to verify */
    hsm_uint32_t                    u32KByteCnt;

    hsm_uint8_t                    *pResultX;                /*!< address is 4bytes aligned, the sign result R of the data to verify */
    hsm_uint32_t                    u32ResultXBufferByteCnt;
    hsm_uint32_t                   *pResultXByteCnt;

    hsm_uint8_t                    *pResultY;                /*!< address is 4bytes aligned, the sign result R of the data to verify */
    hsm_uint32_t                    u32ResultYBufferByteCnt;
    hsm_uint32_t                   *pResultYByteCnt;
} HSM_Ln_EccKPType;

#if 0
typedef void (*HSM_IsrEnableCbType)(HSM_BoolType bEnable);

typedef HSM_StatusType(*HSM_ResetHsmHwCbType)(void);


typedef struct
{
    hsm_uint8_t            *pData;
    hsm_uint32_t            u32DataBufSize;
    HSM_DataFormatType      eDataFmt;
    hsm_uint32_t           *pDataSize;
} HSM_L1_ScatterCMacResultType;
#endif
/********************************************* global API *********************************************************/
/**
 * @brief Init config of hsm
 *
 * @param pLnRt Hsm handle for HSM functionality
 * @param pInitParm The init parameter of the Hsm.
 */
CRYPTO_TEXT_SECTION void           HSM_Ln_Init(HSM_Ln_RtCtxType *pLnRt, HSM_Ln_InitParmType *pInitParm);

/**
 * @brief Interrupt handle function
 *
 * @param pLnCtx Hsm handle for HSM functionality
 */
CRYPTO_TEXT_SECTION void           HSM_Ln_Ack_IrqHandler(HSM_Ln_RtCtxType *pLnCtx);

/**
 * @brief HSM abort function
 *
 * @param pCtx Hsm handle for HSM functionality
 * @return hsm status
 */
CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_Abort(HSM_Ln_RtCtxType *pCtx);

/**
 * @brief Rsassa pss verify setup environment
 *
 * @param pLnCtx Hsm handle for HSM functionality
 * @param u32RsaBitCnt RSA byte length
 * @return hsm status
 */
CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_RsaSsaPssVerifySetupEnv(HSM_Ln_RtCtxType *pLnCtx, hsm_uint32_t u32RsaBitCnt);

/**
 * @brief Rsassa pss verify function
 *
 * @param pLnCtx Hsm handle for HSM functionality
 * @param pCfg Rsassa pss config parameter
 * @return hsm status
 */
CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_RsaSsaPssVerify(HSM_Ln_RtCtxType *pLnCtx, const HSM_Ln_RsaSsaPssVerifyType *pCfg);

/**
 * @brief Rsassa pss verify poll function
 *
 * @param pLnCtx Hsm handle for HSM functionality
 * @return hsm status
 */
CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_RsaSsaPssVerifyPoll(HSM_Ln_RtCtxType *pLnCtx);

/**
 * @brief Rsassa pss verify exit environment
 *
 * @param pLnCtx Hsm handle for HSM functionality
 * @return hsm status
 */
CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_RsaSsaPssVerifyExitEnv(HSM_Ln_RtCtxType *pLnCtx);

/**
 * @brief Rsassa pkcs1v15 verify setup environment
 *
 * @param pLnCtx Hsm handle for HSM functionality
 * @param u32RsaBitCnt RSA byte length
 * @return hsm status
 */
CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_RsaSsaPkcs1v15VerifySetupEnv(HSM_Ln_RtCtxType *pLnCtx, hsm_uint32_t u32RsaBitCnt);

/**
 * @brief Rsassa pkcs1v15 verify function
 *
 * @param pLnCtx Hsm handle for HSM functionality
 * @param pCfg Rsassa pkcs1v15 config parameter
 */
CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_RsaSsaPkcs1v15Verify(HSM_Ln_RtCtxType *pLnCtx, const HSM_Ln_RsaSsaPkcs1v15VerifyType *pCfg);

/**
 * @brief Rsassa pkcs1v15 verify poll function
 *
 * @param pLnCtx Hsm handle for HSM functionality
 * @return hsm status
 */
CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_RsaSsaPkcs1v15VerifyPoll(HSM_Ln_RtCtxType *pLnCtx);

/**
 * @brief Rsassa pkcs1v15 verify exit environment
 *
 * @param pLnCtx Hsm handle for HSM functionality
 * @return hsm status
 */
CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_RsaSsaPkcs1v15VerifyExitEnv(HSM_Ln_RtCtxType *pLnCtx);

/**
 * @brief Sha verify setup environment
 *
 * @param pLnCtx Hsm handle for HSM functionality
 * @return hsm status
 */
CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_ShaSetupEnv(HSM_Ln_RtCtxType *pLnCtx);

/**
 * @brief Sha verify exit environment
 *
 * @param pLnCtx Hsm handle for HSM functionality
 */
CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_ShaExitEnv(HSM_Ln_RtCtxType *pLnCtx);

/**
 * @brief Sha function
 *
 * @param pLnCtx Hsm handle for HSM functionality
 * @param pSha sha config parameter
 */
CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_Sha(HSM_Ln_RtCtxType *pLnCtx, const HSM_Ln_ShaType *pSha);

/**
 * @brief Sha poll function
 *
 * @param pLnCtx Hsm handle for HSM functionality
 */
CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_ShaPoll(HSM_Ln_RtCtxType *pLnCtx);

/**
 * @brief Hsm common exit environment
 *
 * @param pCtx Hsm handle for HSM functionality
 */
CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_CommonExitEnv(HSM_Ln_RtCtxType *pCtx);

/**
 * @brief SM4 encrypt setup environment
 *
 * @param pLnCtx Hsm handle for HSM functionality
 */
CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_Sm4EncryptSetupEnv(HSM_Ln_RtCtxType *pLnCtx);

/**
 * @brief SM4 encrypt exit environment
 *
 * @param pLnCtx Hsm handle for HSM functionality
 */
CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_Sm4EncryptExitEnv(HSM_Ln_RtCtxType *pLnCtx);

/**
 * @brief SM4 encrypt function
 *
 * @param pLnCtx Hsm handle for HSM functionality
 * @param pCfg SM4 encrypt config parameter
 */
CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_Sm4Encrypt(HSM_Ln_RtCtxType *pLnCtx, const HSM_Ln_Sm4EncryptType *pCfg);

/**
 * @brief SM4 encrypt poll function
 *
 * @param pLnCtx Hsm handle for HSM functionality
 */
CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_Sm4EncryptPoll(HSM_Ln_RtCtxType *pLnCtx);

/**
 * @brief SM4 decrypt setup environment
 *
 * @param pLnCtx Hsm handle for HSM functionality
 */
CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_Sm4DecryptSetupEnv(HSM_Ln_RtCtxType *pLnCtx);

/**
 * @brief SM4 decrypt exit environment
 *
 * @param pLnCtx Hsm handle for HSM functionality
 */
CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_Sm4DecryptExitEnv(HSM_Ln_RtCtxType *pLnCtx);

/**
 * @brief SM4 decrypt function
 *
 * @param pLnCtx Hsm handle for HSM functionality
 * @param pCfg SM4 decrypt config parameter
 */
CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_Sm4Decrypt(HSM_Ln_RtCtxType *pLnCtx, const HSM_Ln_Sm4DecryptType *pCfg);

/**
 * @brief SM4 decrypt poll function
 *
 * @param pLnCtx Hsm handle for HSM functionality
 */
CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_Sm4DecryptPoll(HSM_Ln_RtCtxType *pLnCtx);

/**
 * @brief AES encrypt setup environment
 *
 * @param pLnCtx Hsm handle for HSM functionality
 */
CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_AesEncryptSetupEnv(HSM_Ln_RtCtxType *pLnCtx);

/**
 * @brief AES encrypt exit environment
 *
 * @param pLnCtx Hsm handle for HSM functionality
 */
CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_AesEncryptExitEnv(HSM_Ln_RtCtxType *pLnCtx);

/**
 * @brief AES encrypt function
 *
 * @param pLnCtx Hsm handle for HSM functionality
 * @param pCfg AES encrypt config parameter
 */
CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_AesEncrypt(HSM_Ln_RtCtxType *pLnCtx, const HSM_Ln_AesEncryptType *pCfg);

/**
 * @brief AES encrypt poll function
 *
 * @param pLnCtx Hsm handle for HSM functionality
 */
CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_AesEncryptPoll(HSM_Ln_RtCtxType *pLnCtx);

/**
 * @brief AES decrypt setup environment
 *
 * @param pLnCtx Hsm handle for HSM functionality
 */
CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_AesDecryptSetupEnv(HSM_Ln_RtCtxType *pLnCtx);

/**
 * @brief AES decrypt exit environment
 *
 * @param pLnCtx Hsm handle for HSM functionality
 */
CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_AesDecryptExitEnv(HSM_Ln_RtCtxType *pLnCtx);

/**
 * @brief AES decrypt function
 *
 * @param pLnCtx Hsm handle for HSM functionality
 * @param pCfg AES decrypt config parameter
 */
CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_AesDecrypt(HSM_Ln_RtCtxType *pLnCtx, const HSM_Ln_AesDecryptType *pCfg);

/**
 * @brief AES decrypt poll function
 *
 * @param pLnCtx Hsm handle for HSM functionality
 */
CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_AesDecryptPoll(HSM_Ln_RtCtxType *pLnCtx);

/**
 * @brief MD5 setup environment
 *
 * @param pLnCtx Hsm handle for HSM functionality
 */
CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_Md5SetupEnv(HSM_Ln_RtCtxType *pLnCtx);

/**
 * @brief MD5 exit environment
 *
 * @param pLnCtx Hsm handle for HSM functionality
 */
CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_Md5ExitEnv(HSM_Ln_RtCtxType *pLnCtx);

/**
 * @brief MD5 function
 *
 * @param pLnCtx Hsm handle for HSM functionality
 * @param pCfg MD5 config parameter
 */
CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_Md5(HSM_Ln_RtCtxType *pLnCtx, const HSM_Ln_Md5Type *pCfg);

/**
 * @brief MD5 poll function
 *
 * @param pLnCtx Hsm handle for HSM functionality
 */
CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_Md5Poll(HSM_Ln_RtCtxType *pLnCtx);

/**
 * @brief SM3 setup environment
 *
 * @param pLnCtx Hsm handle for HSM functionality
 */
CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_Sm3SetupEnv(HSM_Ln_RtCtxType *pLnCtx);

/**
 * @brief SM3 exit environment
 *
 * @param pLnCtx Hsm handle for HSM functionality
 */
CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_Sm3ExitEnv(HSM_Ln_RtCtxType *pLnCtx);

/**
 * @brief SM3 function
 *
 * @param pLnCtx Hsm handle for HSM functionality
 * @param pCfg SM3 config parameter
 */
CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_Sm3(HSM_Ln_RtCtxType *pLnCtx, const HSM_Ln_Sm3Type *pCfg);

/**
 * @brief SM3 poll function
 *
 * @param pLnCtx Hsm handle for HSM functionality
 */
CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_Sm3Poll(HSM_Ln_RtCtxType *pLnCtx);

/**
 * @brief CMAC setup environment
 *
 * @param pLnCtx Hsm handle for HSM functionality
 */
CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_CMacSetupEnv(HSM_Ln_RtCtxType *pLnCtx);

/**
 * @brief CMAC exit environment
 *
 * @param pLnCtx Hsm handle for HSM functionality
 */
CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_CMacExitEnv(HSM_Ln_RtCtxType *pLnCtx);

/**
 * @brief CMAC function
 *
 * @param pLnCtx Hsm handle for HSM functionality
 * @param pCfg CMAC config parameter
 */
CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_CMac(HSM_Ln_RtCtxType *pLnCtx, const HSM_Ln_CMacType *pCfg);

/**
 * @brief CMAC poll function
 *
 * @param pLnCtx Hsm handle for HSM functionality
 */
CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_CMacPoll(HSM_Ln_RtCtxType *pLnCtx);

/**
 * @brief Rng setup environment
 *
 * @param pLnCtx Hsm handle for HSM functionality
 */
CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_RngSetupEnv(HSM_Ln_RtCtxType *pLnCtx);

/**
 * @brief Rng exit environment
 *
 * @param pLnCtx Hsm handle for HSM functionality
 */
CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_RngExitEnv(HSM_Ln_RtCtxType *pLnCtx);

/**
 * @brief Rng function
 *
 * @param pLnCtx Hsm handle for HSM functionality
 * @param pCfg Rng config parameter
 */
CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_Rng(HSM_Ln_RtCtxType *pLnCtx, const HSM_Ln_RngType *pCfg);

/**
 * @brief Rng poll function
 *
 * @param pLnCtx Hsm handle for HSM functionality
 */
CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_RngPoll(HSM_Ln_RtCtxType *pLnCtx);

/**
 * @brief Scatter cmac setup environment
 *
 * @param pLnCtx Hsm handle for HSM functionality
 */
CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_ScatterCMacSetupEnv(HSM_Ln_RtCtxType *pLnCtx);

/**
 * @brief Scatter cmac exit environment
 *
 * @param pLnCtx Hsm handle for HSM functionality
 */
CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_ScatterCMacExitEnv(HSM_Ln_RtCtxType *pLnCtx);

/**
 * @brief Scatter cmac poll function
 *
 * @param pLnCtx Hsm handle for HSM functionality
 */
CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_ScatterCMacPoll(HSM_Ln_RtCtxType *pLnCtx);

/**
 * @brief Scatter cmac init function
 *
 * @param pLnCtx Hsm handle for HSM functionality
 * @param pCfg Scatter cmac config parameter
 */
CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_ScatterCMacInit(HSM_Ln_RtCtxType *pLnCtx, const HSM_Ln_CMacCfgParmsType *pParmCfg, const HSM_Ln_ScatterCMacType *pCfg);

/**
 * @brief Scatter cmac update function
 *
 * @param pLnCtx Hsm handle for HSM functionality
 * @param pCfg Scatter cmac config parameter
 */
CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_ScatterCMacUpdate(HSM_Ln_RtCtxType *pLnCtx, const HSM_Ln_ScatterCMacType *pCfg);

/**
 * @brief Scatter cmac final function
 *
 * @param pLnCtx Hsm handle for HSM functionality
 * @param pCfg Scatter cmac config parameter
 * @param pResult Scatter cmac result
 */
CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_ScatterCMacFinal(HSM_Ln_RtCtxType *pLnCtx, const HSM_Ln_ScatterCMacType *pCfg, const HSM_Ln_ResultBufInfoType *pResult);

/**
 * @brief Scatter hash setup environment
 *
 * @param pLnCtx Hsm handle for HSM functionality
 */
CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_ScatterHashSetupEnv(HSM_Ln_RtCtxType *pLnCtx);

/**
 * @brief Scatter hash exit environment
 *
 * @param pLnCtx Hsm handle for HSM functionality
 */
CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_ScatterHashExitEnv(HSM_Ln_RtCtxType *pLnCtx);

/**
 * @brief Scatter hash poll function
 *
 * @param pLnCtx Hsm handle for HSM functionality
 */
CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_ScatterHashPoll(HSM_Ln_RtCtxType *pLnCtx);

/**
 * @brief Scatter hash init function
 *
 * @param pLnCtx Hsm handle for HSM functionality
 * @param pCfg Scatter hash config parameter
 */
CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_ScatterHashInit(HSM_Ln_RtCtxType *pLnCtx, const HSM_ShaAlgType eAlg, const HSM_Ln_ScatterHashType *pCfg);

/**
 * @brief Scatter hash update function
 *
 * @param pLnCtx Hsm handle for HSM functionality
 * @param pCfg Scatter hash config parameter
 */
CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_ScatterHashUpdate(HSM_Ln_RtCtxType *pLnCtx, const HSM_Ln_ScatterHashType *pCfg);

/**
 * @brief Scatter hash final function
 *
 * @param pLnCtx Hsm handle for HSM functionality
 * @param pCfg Scatter hash config parameter
 * @param pResult Scatter hash result
 */
CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_ScatterHashFinal(HSM_Ln_RtCtxType *pLnCtx, const HSM_Ln_ScatterHashType *pCfg, const HSM_Ln_ResultBufInfoType *pResult);

/**
 * @brief Scatter hash set mac config function
 *
 * @param pLnCtx Hsm handle for HSM functionality
 * @param pCfg Scatter hash config parameter
 */
CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_ScatterHashSetMacCfg(HSM_Ln_RtCtxType *pLnCtx, HSM_Ln_HashMacCfgType *pCfg);

/**
 * @brief Ecc sign setup environment
 *
 * @param pLnCtx Hsm handle for HSM functionality
 */
CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_EccSignSetupEnv(HSM_Ln_RtCtxType *pLnCtx, hsm_uint32_t u32BitCnt);

/**
 * @brief Ecc sign exit environment
 *
 * @param pLnCtx Hsm handle for HSM functionality
 */
CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_EccSignExitEnv(HSM_Ln_RtCtxType *pLnCtx);

/**
 * @brief Ecc sign function
 *
 * @param pLnCtx Hsm handle for HSM functionality
 * @param pCfg Ecc sign config parameter
 */
CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_EccSign(HSM_Ln_RtCtxType *pLnCtx, const HSM_Ln_EccSignType *pCfg);

/**
 * @brief Ecc sign poll function
 *
 * @param pLnCtx Hsm handle for HSM functionality
 * @param pCfg Ecc sign config parameter
 */
CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_EccSignPoll(HSM_Ln_RtCtxType *pLnCtx);

/**
 * @brief Ecc sign poll function
 *
 * @param pLnCtx Hsm handle for HSM functionality
 */
CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_EccSignPoll(HSM_Ln_RtCtxType *pLnCtx);

/**
 * @brief Ecc decrypt setup environment
 *
 * @param pLnCtx Hsm handle for HSM functionality
 * @param u32BitCnt Byte count
 */
CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_EccDecryptSetupEnv(HSM_Ln_RtCtxType *pLnCtx, hsm_uint32_t u32BitCnt);

/**
 * @brief Ecc decrypt exit environment
 *
 * @param pLnCtx Hsm handle for HSM functionality
 */
CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_EccDecryptExitEnv(HSM_Ln_RtCtxType *pLnCtx);

/**
 * @brief Ecc decrypt function
 *
 * @param pLnCtx Hsm handle for HSM functionality
 * @param pCfg Ecc decrypt config parameter
 */
CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_EccDecrypt(HSM_Ln_RtCtxType *pLnCtx, const HSM_Ln_EccDecryptType *pCfg);

/**
 * @brief Ecc decrypt poll function
 *
 * @param pLnCtx Hsm handle for HSM functionality
 */
CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_EccDecryptPoll(HSM_Ln_RtCtxType *pLnCtx);

/**
 * @brief Ecc verify setup environment
 *
 * @param pLnCtx Hsm handle for HSM functionality
 * @param u32BitCnt Byte count
 */
CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_EccVerifySetupEnv(HSM_Ln_RtCtxType *pLnCtx, hsm_uint32_t u32BitCnt);

/**
 * @brief Ecc verify exit environment
 *
 * @param pLnCtx Hsm handle for HSM functionality
 */
CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_EccVerifyExitEnv(HSM_Ln_RtCtxType *pLnCtx);

/**
 * @brief Ecc verify function
 *
 * @param pLnCtx Hsm handle for HSM functionality
 * @param pCfg Ecc verify config parameter
 */
CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_EccVerify(HSM_Ln_RtCtxType *pLnCtx, const HSM_Ln_EccVerifyType *pCfg);

/**
 * @brief Ecc verify poll function
 *
 * @param pLnCtx Hsm handle for HSM functionality
 */
CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_EccVerifyPoll(HSM_Ln_RtCtxType *pLnCtx);

/**
 * @brief Setup an environment for import keys
 *
 * @param pLnCtx Hsm handle for HSM functionality
 */
CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_KeyImportSetupEnv(HSM_Ln_RtCtxType *pLnCtx);

/**
 * @brief Import key 
 *
 * @param pLnCtx Hsm handle for HSM functionality
 * @param pCfg Import key config parameter
 */
CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_KeyImport(HSM_Ln_RtCtxType *pLnCtx, const HSM_Ln_ImportUserKeyExtType *pCfg);

/**
 * @brief Exit an environment for import keys
 *
 * @param pLnCtx Hsm handle for HSM functionality
 */
CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_KeyImportExitEnv(HSM_Ln_RtCtxType *pLnCtx);

/**
 * @brief Setup an environment for valid keys
 *
 * @param pLnCtx Hsm handle for HSM functionality
 */
CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_KeyValidateSetupEnv(HSM_Ln_RtCtxType *pLnCtx);

/**
 * @brief Valid key
 *
 * @param pLnCtx Hsm handle for HSM functionality
 * @param u32KeyId Key id
 */
CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_KeyValidate(HSM_Ln_RtCtxType *pLnCtx, hsm_uint32_t u32KeyId);

/**
 * @brief Exit an environment for valid keys
 *
 * @param pLnCtx Hsm handle for HSM functionality
 */
CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_KeyValidateExitEnv(HSM_Ln_RtCtxType *pLnCtx);

/**
 * @brief Setup an environment for copy keys
 *
 * @param pLnCtx Hsm handle for HSM functionality
 */
CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_KeyCopySetupEnv(HSM_Ln_RtCtxType *pLnCtx);

/**
 * @brief Copy keys
 *
 * @param pLnCtx Hsm handle for HSM functionality
 * @param pCfg Copy key config parameter
 */
CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_KeyCopy(HSM_Ln_RtCtxType *pLnCtx, const HSM_Ln_CopyUserKeyType *pCfg);

/**
 * @brief Exit an environment for copy keys
 *
 * @param pLnCtx Hsm handle for HSM functionality
 */
CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_KeyCopyExitEnv(HSM_Ln_RtCtxType *pLnCtx);

/**
 * @brief Setup an environment for revoke keys
 *
 * @param pLnCtx Hsm handle for HSM functionality
 */
CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_KeyRevokeSetupEnv(HSM_Ln_RtCtxType *pLnCtx);

/**
 * @brief Revoke keys
 *
 * @param pLnCtx Hsm handle for HSM functionality
 * @param u32KeyId Key id
 */
CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_KeyRevoke(HSM_Ln_RtCtxType *pLnCtx, hsm_uint32_t u32KeyId);

/**
 * @brief Exit an environment for revoke keys
 *
 * @param pLnCtx Hsm handle for HSM functionality
 */
CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_KeyRevokeExitEnv(HSM_Ln_RtCtxType *pLnCtx);

/**
 * @brief Setup an environment for tidy up key space
 *
 * @param pLnCtx Hsm handle for HSM functionality
 */
CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_KeySpaceTidyUpSetupEnv(HSM_Ln_RtCtxType *pLnCtx);

/**
 * @brief Tidy up key space
 *
 * @param pLnCtx Hsm handle for HSM functionality
 * @param pCfg Tidy up key space config parameter
 */
CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_KeySpaceTidyUp(HSM_Ln_RtCtxType *pLnCtx, HSM_Ln_KeySpaceStatusType *pCfg);

/**
 * @brief Exit an environment for tidy up key space
 *
 * @param pLnCtx Hsm handle for HSM functionality
 */
CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_KeySpaceTidyUpExitEnv(HSM_Ln_RtCtxType *pLnCtx);

/**
 * @brief Setup an environment for update key
 *
 * @param pLnCtx Hsm handle for HSM functionality
 */
CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_UpdateKeySetupEnv(HSM_Ln_RtCtxType *pLnCtx);

/**
 * @brief Update key
 *
 * @param pLnCtx Hsm handle for HSM functionality
 * @param pCfg Update key
 */
CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_UpdateKey(HSM_Ln_RtCtxType *pLnCtx, const HSM_Ln_PlainKeyImport *pCfg);

/**
 * @brief Exit an environment for update key
 *
 * @param pLnCtx Hsm handle for HSM functionality
 */
CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_UpdateKeyExitEnv(HSM_Ln_RtCtxType *pLnCtx);

/**
 * @brief Setup an environment for revoke key
 *
 * @param pLnCtx Hsm handle for HSM functionality
 */
CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_RevokeKeySetupEnv(HSM_Ln_RtCtxType *pLnCtx);

/**
 * @brief Revoke key
 *
 * @param pLnCtx Hsm handle for HSM functionality
 * @param u32KeyId Key id
 */
CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_RevokeKey(HSM_Ln_RtCtxType *pLnCtx, hsm_uint32_t u32KeyId);

/**
 * @brief Exit an environment for revoke key
 *
 * @param pLnCtx Hsm handle for HSM functionality
 */
CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_RevokeKeyExitEnv(HSM_Ln_RtCtxType *pLnCtx);

/**
 * @brief Setup an environment for revoke key
 *
 * @param pCtx Hsm handle for HSM functionality
 */
CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_RsaSsaPkcs1V15SignSetupEnv(HSM_Ln_RtCtxType *pCtx);

/**
 * @brief RsaSsa-pss-Pkcs-1v15 sign
 *
 * @param pCtx Hsm handle for HSM functionality
 * @param pCfg Sign date type
 * @param u32TimeoutMs Timeout period
 */
CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_RsaSsaPkcs1V15SignData(HSM_Ln_RtCtxType *pCtx, const HSM_Ln_RsaSsaPkcs1V15SignDataType *pCfg, hsm_uint32_t u32TimeoutMs);

/**
 * @brief RsaSsa-pss-Pkcs-1v15 sign hash
 *
 * @param pCtx Hsm handle for HSM functionality
 * @param pCfg Sign date hash type
 * @param u32TimeoutMs Timeout period
 */
CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_RsaSsaPkcs1V15SignHash(HSM_Ln_RtCtxType *pCtx, const HSM_Ln_RsaSsaPkcs1V15SignHashType *pCfg, hsm_uint32_t u32TimeoutMs);

/**
 * @brief Exit an environment for revoke key
 *
 * @param pCtx Hsm handle for HSM functionality
 */
CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_RsaSsaPkcs1V15SignExitEnv(HSM_Ln_RtCtxType *pCtx);

/**
 * @brief Setup an environment for  RsaSsa-pss sign
 *
 * @param pCtx Hsm handle for HSM functionality
 * @param pCfg Sign date type
 * @param u32TimeoutMs Timeout period
 */
CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_RsaSsaPssSignSetupEnv(HSM_Ln_RtCtxType *pCtx);

/**
 * @brief RsaSsa-pss sign
 *
 * @param pCtx Hsm handle for HSM functionality
 * @param pCfg Sign date type
 * @param u32TimeoutMs Timeout period
 */
CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_RsaSsaPssSignData(HSM_Ln_RtCtxType *pCtx, const HSM_Ln_RsaSsaPssSignDataType *pCfg, hsm_uint32_t u32TimeoutMs);

/**
 * @brief RsaSsa-pss sign hash
 *
 * @param pCtx Hsm handle for HSM functionality
 * @param pCfg Sign date type
 * @param u32TimeoutMs Timeout period
 */
CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_RsaSsaPssSignHash(HSM_Ln_RtCtxType *pCtx, const HSM_Ln_RsaSsaPssSignHashType *pCfg, hsm_uint32_t u32TimeoutMs);

/**
 * @brief Exit an environment for  RsaSsa-pss sign
 *
 * @param pCtx Hsm handle for HSM functionality
 * @param pCfg Sign date type
 * @param u32TimeoutMs Timeout period
 */
CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_RsaSsaPssSignExitEnv(HSM_Ln_RtCtxType *pCtx);

CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_Sm2VerifySetupEnv(HSM_Ln_RtCtxType *pLnCtx);

CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_Sm2VerifyExitEnv(HSM_Ln_RtCtxType *pLnCtx);

CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_Sm2Verify(HSM_Ln_RtCtxType *pLnCtx, const HSM_Ln_Sm2VerifyType *pCfg);

CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_Sm2VerifyPoll(HSM_Ln_RtCtxType *pLnCtx);

#if defined(__cplusplus)
}
#endif
/** @}*/ /* module_driver_hsm_Level1_LevelN */

#endif /* end of CRYPTO_LEVELNAPI_H */
