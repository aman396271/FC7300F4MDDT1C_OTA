/**
*   @file    Crypto_Level0Api.c
*   @version 0.8.0
*
*   @brief   AUTOSAR Crypto - Low level part of CRY driver.
*   @details Hardware security module (HSM) provides several standards based cryptographic
*            services and security services.
*
*   @addtogroup CRYPTO
*   @{
*/
/*==================================================================================================
*   PERIPHERAL           : CRYPTO,MAILBOX
*   PLATFORM             : Flagchip FC7300
*   AUTOSAR VERSION      : 4.6.0
*   AUTOSAR REVISION     : ASR_REL_R20-11
*   SOFTWARE VERSION     : 0.8.0
*   VENDOR               : Flagchip Semiconductors
*
*   Copyright 2020-2023 Flagchip Semiconductors Co., Ltd.
*   All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
*   Revision History:
*
*   Version     Date          Initials      CR#          Descriptions
*   ---------   ----------    ------------- ----------   ---------------
*   0.1.0       15/02/2024    QXW0051       N/A          CRYPTO Initial Version
*   0.6.0       23/03/2024    QXW0071       N/A          Add Support For FC7240
==================================================================================================*/

#include "module_driver_hsm.h"
#include "module_driver_hsm_level1_leveln.h"


/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/
typedef enum {
    HSM_CMD_ID_TRNG                         = 0xb55du,
    HSM_CMD_ID_SHA                          = 0xfce2u,
    HSM_CMD_ID_ECC_SIGN                     = 0xde41u,
    HSM_CMD_ID_ECC_VERIFY                   = 0xa522u,
    HSM_CMD_ID_SM2_GENKEYPAIR               = 0xc9ddu,
    HSM_CMD_ID_SM2_ENCRY                    = 0x30f1u,
    HSM_CMD_ID_SM2_DECRY                    = 0x6351u,
    HSM_CMD_ID_SM2_SIGN                     = 0xe814u,
    HSM_CMD_ID_SM2_VERIFY                   = 0x6e1eu,
    HSM_CMD_ID_SM2_GENZA                    = 0xdbbeu,
    HSM_CMD_ID_SM2_GENHASH                  = 0x5ce5u,
    HSM_CMD_ID_SM4_ENCRY                    = 0xfd5au,
    HSM_CMD_ID_SM4_DECRY                    = 0x4aedu,
    HSM_CMD_ID_ECC_ENCRY                    = 0x4d3fu,
    HSM_CMD_ID_ECC_DECRY                    = 0x97e4u,
    HSM_CMD_ID_REQUEST_AUTH                 = 0x33d9u,
    HSM_CMD_ID_LIFECYCLE_CHANGE             = 0xbe63u, /* prefa,fa not support in sdk */
    HSM_CMD_ID_CANCEL_JOB                   = 0x17c3u,
    HSM_CMD_ID_SELF_TEST                    = 0x4e93u,
    HSM_CMD_ID_NVR_OTP                      = 0x2cd8u,
    HSM_CMD_ID_LIFECYCLE_CHANGE_TAKE_EFFECT = 0x30fau,
    HSM_CMD_ID_USER_KEY_MANAGE              = 0xf4cfu,
    HSM_CMD_ID_SPACE_MANAGE                 = 0x4ac0u,
    HSM_CMD_ID_AES_ENCRY                    = 0xa2c6u,
    HSM_CMD_ID_AES_DECRY                    = 0x6576u,
    HSM_CMD_ID_CMAC_GEN                     = 0xf0b9u,
    HSM_CMD_ID_XMAC_GEN                     = 0x32acu,
    HSM_CMD_ID_CCM_ENCRY                    = 0x862fu,
    HSM_CMD_ID_CCM_DECRY                    = 0x79a4u,
    HSM_CMD_ID_GCM_ENCRY                    = 0xd1a6u,
    HSM_CMD_ID_GCM_DECRY                    = 0xc0a3u,
    HSM_CMD_ID_MD5                          = 0x9371u,
    HSM_CMD_ID_SM3                          = 0xcfe5u,
    HSM_CMD_ID_MONOTONIC_COUNTER            = 0xdc97u,
    HSM_CMD_ID_RSA                          = 0x866cu,
    HSM_CMD_ID_LOAD_FIRMWARE                = 0x503du,
    HSM_CMD_ID_SCATTER_HASH                 = 0x465du,
    HSM_CMD_ID_AESM_RAW_API                 = 0x42fdu,
    HSM_CMD_ID_RSA_SSA_PSS_VERIFY           = 0x0076u,
    HSM_CMD_ID_RSA_SSA_PKCS1V15_VERIFY      = 0x1577u,
    HSM_CMD_ID_RSA_SSA_PKCS1V15_SIGN        = 0xd047u,
    HSM_CMD_ID_RSA_SSA_PSS_SIGN             = 0xd873u,
    HSM_CMD_ID_FAST_TRNG                    = 0x64f0u,
    HSM_CMD_ID_ROM_HASH                     = 0x8436u
} HSM_CmdIdType;


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#define HSMCOM_LIFECYCLE_OEM_DEV            0x4792u
#define HSMCOM_LIFECYCLE_OEM_PDT            0xA4F1u
#define HSMCOM_LIFECYCLE_IN_FIELD           0xaddcu

#define HSMCOM_INCREASE_COUNTER             0xd27fu
#define HSMCOM_READ_COUNTER                 0x1875u

#define HSMCOM_NVR_OTP_READ                 0x9C2Fu


#define HSMCOM_KEYMANAGER_IMPORT_USER_KEY     0xdcf1u
#define HSMCOM_KEYMANAGER_IMPORT_USER_KEY_NEW 0xdcf2u
#define HSMCOM_KEYMANAGER_REVOKE_USER_KEY     0x7278u
#define HSMCOM_KEYMANAGER_EXPORT_USER_KEY     0xd8c9u
#define HSMCOM_KEYMANAGER_GEN_UESR_KEY        0x1853u

#define HSMCOM_KEYSPACE_GET_STATUS          0xe39cu
#define HSMCOM_KEYSPACE_NEATEN              0xb12bu

#define HSMCOM_KEYMANAGER_CHECK_KEYID_EXIST_EXT     0xbd3e
#define HSMCOM_KEYMANAGER_COPY_KEY                  0xb9d3
#define HSMCOM_KEYMANAGER_CHECK_KEYID_STATUS_EXT    0x9f73

#define HSMCOM_KEYMANAGER_UPDATE_KEY                0xa47d
/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
void hsm_memcpy(void *pDstMem, const void *pSrcMem, uint32_t u32Cnt);
static HSM_StatusType hsm_assign_val(HSM_CmdType *pCmd, hsm_uint32_t u32Cmd, hsm_uint32_t u32Address);
HSM_StatusType hsm_fw_scattercmaciuf(HSM_CmdType *pCmd, const HSMCom_AesmRawApiType *pCfg, HSM_DataFormatType eInputFmt, HSM_DataFormatType eKeyFmt, hsm_uint32_t u32AuxId);
/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/
static HSM_StatusType hsm_assign_val(HSM_CmdType *pCmd, hsm_uint32_t u32Cmd, hsm_uint32_t u32Address)
{
    HSM_StatusType eRet = HSM_STATUS_SUCCESS;

    if (NULL_PTR != pCmd)
    {
        pCmd->u32Cmd  = u32Cmd;
        pCmd->u32Addr = u32Address;
    }
    else
    {
        eRet = HSM_STATUS_PARAM_ERR;
    }

    return eRet;
}

/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/
HSM_StatusType HSM_TrueRandGetSrc0(HSM_CmdType *pCmd, const HSMCom_TrueRandType*pCfg)
{
    return hsm_assign_val(pCmd, ((hsm_uint32_t)HSM_CMD_ID_TRNG << 16u) | HSMCOM_TRNG_SRC_0, (hsm_uint32_t)pCfg);
}

HSM_StatusType HSM_TrueRandGetSrc1(HSM_CmdType *pCmd, const HSMCom_TrueRandType*pCfg)
{
    return hsm_assign_val(pCmd, ((hsm_uint32_t)HSM_CMD_ID_TRNG << 16u) | HSMCOM_TRNG_SRC_1, (hsm_uint32_t)pCfg);
}

HSM_StatusType HSM_TrueRandGetSrcXor(HSM_CmdType *pCmd, const HSMCom_TrueRandType*pCfg)
{
    return hsm_assign_val(pCmd, ((hsm_uint32_t)HSM_CMD_ID_TRNG << 16u) | HSMCOM_TRNG_SRC_XOR, (hsm_uint32_t)pCfg);
}

HSM_StatusType HSM_TrueRandGet(HSM_CmdType *pCmd, const HSMCom_TrueRandExType*pCfg)
{
    return hsm_assign_val(pCmd, ((hsm_uint32_t)HSM_CMD_ID_TRNG << 16u) | pCfg->u32RandSrc, (hsm_uint32_t)pCfg);
}

HSM_StatusType HSM_TrueRandGetAny(HSM_CmdType *pCmd, const HSMCom_TrueRandType*pCfg)
{
    return hsm_assign_val(pCmd, ((hsm_uint32_t)HSM_CMD_ID_TRNG << 16u) | HSMCOM_TRNG_SRC_ANY, (hsm_uint32_t)pCfg);
}

HSM_StatusType HSM_TrueRandGetSrcShiftXor(HSM_CmdType *pCmd, const HSMCom_TrueRandType*pCfg)
{
    return hsm_assign_val(pCmd, ((hsm_uint32_t)HSM_CMD_ID_TRNG << 16u) | HSMCOM_TRNG_SRC_SHIFTXOR, (hsm_uint32_t)pCfg);
}

HSM_StatusType HSM_FastTrueRandGet(HSM_CmdType *pCmd, const HSMCom_FastTrueRandType*pCfg)
{
    return hsm_assign_val(pCmd,(uint32_t)(HSM_CMD_ID_FAST_TRNG << 16u) , (uint32_t)pCfg);
}

HSM_StatusType HSM_Sha(HSM_CmdType *pCmd, const HSMCom_ShaType *pCfg)
{
    return hsm_assign_val(pCmd, ((hsm_uint32_t)HSM_CMD_ID_SHA << 16u), (hsm_uint32_t)pCfg);
}

HSM_StatusType HSM_EccVerify(HSM_CmdType *pCmd, const HSMCom_EccVerifyType *pCfg)
{
    return hsm_assign_val(pCmd, ((hsm_uint32_t)HSM_CMD_ID_ECC_VERIFY << 16u), (hsm_uint32_t)pCfg);
}

HSM_StatusType HSM_Sm2Decry(HSM_CmdType *pCmd, const HSMCom_Sm2DecryptType *pCfg)
{
    return hsm_assign_val(pCmd, ((hsm_uint32_t)HSM_CMD_ID_SM2_DECRY << 16u), (hsm_uint32_t)pCfg);
}

HSM_StatusType HSM_Sm2Verify(HSM_CmdType *pCmd, const HSMCom_Sm2VerifyType *pCfg)
{
    return hsm_assign_val(pCmd, ((hsm_uint32_t)HSM_CMD_ID_SM2_VERIFY << 16u), (hsm_uint32_t)pCfg);
}

HSM_StatusType HSM_Sm2GenZa(HSM_CmdType *pCmd, const HSMCom_Sm2GenZaType *pCfg)
{
    return hsm_assign_val(pCmd, ((hsm_uint32_t)HSM_CMD_ID_SM2_GENZA << 16u), (hsm_uint32_t)pCfg);
}

HSM_StatusType HSM_Sm2GenHash(HSM_CmdType *pCmd, const HSMCom_Sm2GenHashType *pCfg)
{
    return hsm_assign_val(pCmd, ((hsm_uint32_t)HSM_CMD_ID_SM2_GENHASH << 16u), (hsm_uint32_t)pCfg);
}

/* two N bits add max generate 1 overflow, (2^N -1) + (2^N -1) only can generate one 2^N overflow, left 2^N -2 use N bit enough */
static hsm_uint32_t hsm_u32_add_u32(hsm_uint32_t *pN, hsm_uint32_t u32Num)
{
    hsm_uint32_t u32Ret = 1u;

    if ((((hsm_uint32_t)0xffffffffu) - (*pN))   >= u32Num)
    {
        u32Ret = 0u;
    }

    (*pN) += u32Num;

    return u32Ret;
}

static hsm_uint32_t hsm_u8_add_u8(hsm_uint8_t *pN, hsm_uint8_t u8Num)
{
    hsm_uint32_t u32Ret = 1u;

    if ((((hsm_uint8_t)0xffu) - (*pN))   >= u8Num)
    {
        u32Ret = 0u;
    }

    (*pN) = (hsm_uint8_t)((hsm_uint8_t)(*pN) + (hsm_uint8_t)u8Num);

    return u32Ret;
}


static hsm_uint32_t hsm_bn128_u32_array_add_u32(hsm_uint32_t (*pN)[4], hsm_uint32_t u32Num)
{
    /* the 0x12345678123456781234567812345679, store use array of hsm_uint32_t {0x12345678, 0x12345678, 0x12345678, 0x12345679} */
    /* should the last word in the array code, add number to 0x12345679 */
    hsm_int32_t s32Idx = 3;
    hsm_uint32_t u32Data = u32Num;

    if (u32Data > 0u)
    {
        while (s32Idx >= 0)
        {
            u32Data = hsm_u32_add_u32(&((*pN)[s32Idx]), u32Data);
            if (0u == u32Data)
              break;

            s32Idx--;
        }
    }


    return u32Data;
}

static hsm_uint32_t hsm_bn128_u8_array_add_u32(hsm_uint8_t (*pN)[16], hsm_uint32_t u32Num)
{
    /* the 0x12345678123456781234567812345679, store use array of hsm_uint8_t {0x12, 0x34, 0x56, 0x78, 0x12, 0x34, 0x56, 0x78, 0x12, 0x34, 0x56, 0x78, 0x12, 0x34, 0x56, 0x79} */
    /* should the last word in the array code, add number to 0x12345679 */
    hsm_int32_t s32Idx = 15;
    hsm_uint32_t  u32Overflow = 0u;
    hsm_uint32_t u32Data = u32Num;

    if (u32Data > 0u)
    {
        while (s32Idx >= 0)
        {
            u32Overflow = hsm_u8_add_u8(&((*pN)[s32Idx]), (hsm_uint8_t)u32Overflow);
            u32Overflow += hsm_u8_add_u8(&((*pN)[s32Idx]), u32Data & 0xffu);
            u32Data = u32Data >> 8u;

            if ((0u == u32Overflow) && (0u == u32Data))
            {
                break;
            }

            s32Idx--;
        }
    }


    return u32Overflow;
}

HSM_StatusType HSM_Sm4EncryptStart(HSM_CmdType *pCmd, HSMWrap_Sm4EncryptType *pCtx, HSMCom_Sm4EncryptType *pParm)
{
    HSM_StatusType eRet        = hsm_assign_val(pCmd, ((hsm_uint32_t)HSM_CMD_ID_SM4_ENCRY << 16u), (hsm_uint32_t)pParm);
    hsm_uint32_t       u32MaxBytes;

    const hsm_uint8_t *pLsbByte;

    if (HSM_STATUS_SUCCESS == eRet)
    {
        if (HSM_SYMM_ENDECRYPT_MODE_CTR == pParm->tCfg.eSm4Alg)
        {
            pLsbByte = ((const hsm_uint8_t *)(pParm->tCfg.pIvData));

            u32MaxBytes = ((0xffu - (pLsbByte[12] & 0xffu)) + 1u) * 0x10u;
            if (pParm->tCfg.u32InputByteCnt > u32MaxBytes)
            {
                pCtx->pParam                  = pParm;
                pCtx->u32Remain               = pParm->tCfg.u32InputByteCnt - u32MaxBytes;
                pParm->tCfg.u32InputByteCnt = u32MaxBytes;
                eRet = HSM_STATUS_AGAIN;
            }
            else
            {
                pCtx->u32Remain = 0u;
                pCtx->pParam    = pParm;
                eRet = HSM_STATUS_FINISH;
            }
        }
        else
        {
            pCtx->u32Remain = 0u;
            pCtx->pParam    = pParm;
            eRet = HSM_STATUS_FINISH;
        }
    }

    return eRet;
}

HSM_StatusType HSM_Sm4EncryptUpdate(HSM_CmdType *pCmd, HSMWrap_Sm4EncryptType *pCtx)
{
    HSM_StatusType eRet        = hsm_assign_val(pCmd, ((hsm_uint32_t)HSM_CMD_ID_SM4_ENCRY << 16u), (hsm_uint32_t)(pCtx->pParam));
    hsm_uint32_t       u32MaxBytes;
    HSMCom_Sm4EncryptType *pParam = pCtx->pParam;
    const hsm_uint8_t *pLsbByte;

    if (HSM_STATUS_SUCCESS == eRet)
    {
        if (0u != pCtx->u32Remain)
        {
            pLsbByte = ((const hsm_uint8_t *)(pParam->tCfg.pIvData));

            hsm_bn128_u32_array_add_u32((hsm_uint32_t (*)[4])(pParam->tCfg.pIvData), pParam->tCfg.u32InputByteCnt / 0x10u);
            u32MaxBytes = ((0xffu - (pLsbByte[12] & 0xffu)) + 1u) * 0x10u;

            pParam->tCfg.pDataInput = (const hsm_uint32_t *)(((const hsm_uint8_t *)(pParam->tCfg.pDataInput)) + pParam->tCfg.u32InputByteCnt);
            pParam->tCfg.pDataOutput = (hsm_uint32_t *)(((hsm_uint8_t *)(pParam->tCfg.pDataOutput)) + pParam->tCfg.u32InputByteCnt);
            pParam->tCfg.u32OutputMemSize -= pParam->tCfg.u32InputByteCnt;
            pParam->tCfg.u32InputByteCnt = pCtx->u32Remain;

            if (pParam->tCfg.u32InputByteCnt > u32MaxBytes)
            {
                pCtx->u32Remain               = pParam->tCfg.u32InputByteCnt - u32MaxBytes;
                pParam->tCfg.u32InputByteCnt = u32MaxBytes;
                eRet = HSM_STATUS_AGAIN;
            }
            else
            {
                pCtx->u32Remain = 0u;
                eRet = HSM_STATUS_FINISH;
            }
        }
        else
        {
            eRet = HSM_STATUS_ALREADY_FINISHED;
        }
    }

    return eRet;
}

HSM_StatusType HSM_Sm4EncryptExStart(HSM_CmdType *pCmd, HSMWrap_Sm4EncryptExType *pCtx, HSMCom_Sm4EncryptExType *pCfg)
{
    HSM_StatusType  eRet, eRet2;
    hsm_uint32_t          u32MaxBytes;
    hsm_uint32_t          u32Flag = 0x0u;

    pCtx->u32CurrentOutSize = 0u;

    if (HSM_SYMM_ENDECRYPT_MODE_CTR == pCfg->tCfg.eAesAlg)
    {
        if (HSM_DATA_FORMAT_1B == pCfg->tCfg.eInputFmt)
        {
            u32MaxBytes = (hsm_uint32_t)((hsm_uint32_t)(0xffu - ((pCfg->tCfg.pIvData)[15] & 0xffu)) + 1u) * 0x10u;
        }
        else
        {
            u32MaxBytes = (hsm_uint32_t)((hsm_uint32_t)(0xffu - (pCfg->tCfg.pIvData[12] & 0xffu)) + 1u) * 0x10u;
        }

        if (pCfg->tCfg.u32InputByteCnt > u32MaxBytes)
        {
            pCtx->pParam                  = pCfg;
            pCtx->u32Remain               = pCfg->tCfg.u32InputByteCnt - u32MaxBytes;
            pCtx->ePad                    = pCfg->tCfg.ePad;
            pCtx->pOutResultByteCnt       = pCfg->tCfg.pGenerateOutByteCnt;
            pCtx->u32OutAlreadyByteCnt    = 0U;

            pCfg->tCfg.u32InputByteCnt    = u32MaxBytes;
            pCfg->tCfg.ePad               = HSM_FLEXAES_PAD_ZERO;

            eRet = HSM_STATUS_AGAIN;
        }
        else
        {
            pCtx->u32Remain = 0u;
            pCtx->pParam    = pCfg;
            pCtx->ePad                    = pCfg->tCfg.ePad;
            pCtx->pOutResultByteCnt       = pCfg->tCfg.pGenerateOutByteCnt;
            pCtx->u32OutAlreadyByteCnt    = 0U;

            eRet = HSM_STATUS_FINISH;
        }
    }
    else
    {
        pCtx->u32Remain = 0u;
        pCtx->pParam    = pCfg;
        pCtx->ePad                    = pCfg->tCfg.ePad;
        pCtx->pOutResultByteCnt       = pCfg->tCfg.pGenerateOutByteCnt;
        pCtx->u32OutAlreadyByteCnt    = 0U;

        eRet = HSM_STATUS_FINISH;
    }

    pCfg->tCfg.pGenerateOutByteCnt= &(pCtx->u32CurrentOutSize);
    u32Flag |= 0x1;

    u32Flag |= ((pCfg->tCfg.ePad & 0x1u) << 1u) | ((pCfg->tCfg.eInputFmt & 0x1u) << 2u) | ((pCfg->tCfg.eOutputFmt & 0x1u) << 3u);


    eRet2 = hsm_assign_val(pCmd, ((hsm_uint32_t)HSM_CMD_ID_AES_ENCRY << 16u) | u32Flag | 0x10, (hsm_uint32_t)pCfg);
    if (HSM_STATUS_SUCCESS != eRet2)
    {
        eRet = eRet2;
    }


    return eRet;
}

HSM_StatusType HSM_Sm4EncryptExUpdate(HSM_CmdType *pCmd, HSMWrap_Sm4EncryptExType *pCtx)
{
    HSM_StatusType eRet, eRet2;
    hsm_uint32_t       u32MaxBytes;
    HSMCom_Sm4EncryptExType *pParam = pCtx->pParam;

    hsm_uint32_t u32Flag = 0x0u;


    if (0u != pCtx->u32Remain)
    {
        if (HSM_DATA_FORMAT_1B == pParam->tCfg.eInputFmt)
        {
            hsm_bn128_u8_array_add_u32((hsm_uint8_t (*)[16])(pParam->tCfg.pIvData), pParam->tCfg.u32InputByteCnt / 0x10u);
        }
        else
        {
            hsm_bn128_u32_array_add_u32((hsm_uint32_t (*)[4])(pParam->tCfg.pIvData), pParam->tCfg.u32InputByteCnt / 0x10u);
        }

        if (HSM_DATA_FORMAT_1B == pParam->tCfg.eInputFmt)
        {
            u32MaxBytes = (hsm_uint32_t)((hsm_uint32_t)(0xffu - ((pParam->tCfg.pIvData)[15] & 0xffu)) + 1u) * 0x10u;
        }
        else
        {
            u32MaxBytes = (hsm_uint32_t)((hsm_uint32_t)(0xffu - ((pParam->tCfg.pIvData)[12] & 0xffu)) + 1u) * 0x10u;
        }

        pCtx->u32OutAlreadyByteCnt += pCtx->u32CurrentOutSize;


        pParam->tCfg.pDataInput         = (const hsm_uint8_t *)(((const hsm_uint8_t *)(pParam->tCfg.pDataInput)) + pParam->tCfg.u32InputByteCnt);
        pParam->tCfg.pDataOutput        = (hsm_uint8_t *)(((hsm_uint8_t *)(pParam->tCfg.pDataOutput)) + pParam->tCfg.u32InputByteCnt);
        pParam->tCfg.u32OutputMemSize  -= pParam->tCfg.u32InputByteCnt;
        pParam->tCfg.u32InputByteCnt    = pCtx->u32Remain;

        pCtx->u32CurrentOutSize = 0u;

        if (pParam->tCfg.u32InputByteCnt > u32MaxBytes)
        {
            pCtx->u32Remain               = pParam->tCfg.u32InputByteCnt - u32MaxBytes;
            pParam->tCfg.u32InputByteCnt = u32MaxBytes;
            eRet = HSM_STATUS_AGAIN;
        }
        else
        {
            pCtx->u32Remain = 0u;
            pParam->tCfg.ePad = pCtx->ePad;
            eRet = HSM_STATUS_FINISH;
        }

        u32Flag |= 0x1;
        u32Flag |= ((pParam->tCfg.ePad & 0x1u) << 1u) | ((pParam->tCfg.eInputFmt & 0x1u) << 2u) | ((pParam->tCfg.eOutputFmt & 0x1u) << 3u);

        eRet2 = hsm_assign_val(pCmd, ((hsm_uint32_t)HSM_CMD_ID_AES_ENCRY << 16u) | u32Flag | 0x10, (hsm_uint32_t)pParam);
        if (HSM_STATUS_SUCCESS != eRet2)
        {
            eRet = eRet2;
        }
    }
    else
    {
        pCtx->u32OutAlreadyByteCnt += pCtx->u32CurrentOutSize;
        pCtx->u32CurrentOutSize = 0u;

        if (NULL_PTR != pCtx->pOutResultByteCnt)
        {
            hsm_memcpy(pCtx->pOutResultByteCnt, &(pCtx->u32OutAlreadyByteCnt), sizeof(pCtx->u32OutAlreadyByteCnt));
        }

        eRet = HSM_STATUS_ALREADY_FINISHED;
    }


    return eRet;
}


HSM_StatusType HSM_Sm4DecryptEx(HSM_CmdType *pCmd, const HSMCom_Sm4DecryptExType *pCfg)
{
    hsm_uint32_t u32Flag = ((pCfg->tCfg.ePad & 0x1u) << 1u) | ((pCfg->tCfg.eInputFmt & 0x1u) << 2u) | ((pCfg->tCfg.eOutputFmt & 0x1u) << 3u);

    if (NULL_PTR != (pCfg->tCfg.pGenerateOutByteCnt))
    {
        u32Flag |= 0x1;
    }
    else
    {
        ;
    }
    return hsm_assign_val(pCmd, ((hsm_uint32_t)HSM_CMD_ID_AES_DECRY << 16u) | u32Flag | 0x10, (hsm_uint32_t)pCfg);
}

HSM_StatusType HSM_Sm4Decrypt(HSM_CmdType *pCmd, const HSMCom_Sm4DecryptType *pCfg)
{
    return hsm_assign_val(pCmd, ((hsm_uint32_t)HSM_CMD_ID_SM4_DECRY << 16u), (hsm_uint32_t)pCfg);
}

HSM_StatusType HSM_EccEasyDecry(HSM_CmdType *pCmd, const HSMCom_EccEasyDecryType *pCfg)
{
    return hsm_assign_val(pCmd, ((hsm_uint32_t)HSM_CMD_ID_ECC_DECRY << 16u), (hsm_uint32_t)pCfg);
}

HSM_StatusType HSM_EccCalculateEx(HSM_CmdType *pCmd, const HSMCom_EccCalcType *pCfg)
{
    return hsm_assign_val(pCmd, ((hsm_uint32_t)HSM_CMD_ID_ECC_DECRY << 16u) | ((hsm_uint32_t)0x1u), (hsm_uint32_t)pCfg);
}

HSM_StatusType HSM_RequestAuthorization(HSM_CmdType *pCmd, const HSMCom_RequestAuthType *pCfg)
{
    return hsm_assign_val(pCmd, ((hsm_uint32_t)HSM_CMD_ID_REQUEST_AUTH << 16u), (hsm_uint32_t)pCfg);
}

HSM_StatusType HSM_OemDevEnter(HSM_CmdType *pCmd, const HSMCom_AuthCheckType *pCfg)
{
    return hsm_assign_val(pCmd, ((hsm_uint32_t)HSM_CMD_ID_LIFECYCLE_CHANGE << 16u) | HSMCOM_LIFECYCLE_OEM_DEV, (hsm_uint32_t)pCfg);
}

HSM_StatusType HSM_OemPdtEnter(HSM_CmdType *pCmd, const HSMCom_AuthCheckType *pCfg)
{
    return hsm_assign_val(pCmd, ((hsm_uint32_t)HSM_CMD_ID_LIFECYCLE_CHANGE << 16u) | HSMCOM_LIFECYCLE_OEM_PDT, (hsm_uint32_t)pCfg);
}

HSM_StatusType HSM_InFieldEnter(HSM_CmdType *pCmd, const HSMCom_AuthCheckType *pCfg)
{
    return hsm_assign_val(pCmd, ((hsm_uint32_t)HSM_CMD_ID_LIFECYCLE_CHANGE << 16u) | HSMCOM_LIFECYCLE_IN_FIELD, (hsm_uint32_t)pCfg);
}

HSM_StatusType HSM_CancelJob(HSM_CmdType *pCmd, const HSMCom_CancelJobType *pCfg)
{
    return hsm_assign_val(pCmd, ((hsm_uint32_t)HSM_CMD_ID_CANCEL_JOB << 16u), (hsm_uint32_t)pCfg);
}

HSM_StatusType HSM_SelfTest(HSM_CmdType *pCmd,  volatile HSMCom_SelfTestType *pCfg)
{
    return hsm_assign_val(pCmd, ((hsm_uint32_t)HSM_CMD_ID_SELF_TEST << 16u), (hsm_uint32_t)pCfg);
}



HSM_StatusType HSM_NvrOtpRead(HSM_CmdType *pCmd, const HSMCom_NvrOtpType *pCfg)
{
    return hsm_assign_val(pCmd, ((hsm_uint32_t)HSM_CMD_ID_NVR_OTP << 16u) | HSMCOM_NVR_OTP_READ, (hsm_uint32_t)pCfg);
}

HSM_StatusType HSM_LifeCycleTakeEffect(HSM_CmdType *pCmd, HSMCom_LifeCycleTakeEffectType *pCfg)
{
    return hsm_assign_val(pCmd, ((hsm_uint32_t)HSM_CMD_ID_LIFECYCLE_CHANGE_TAKE_EFFECT << 16u), (hsm_uint32_t)pCfg);
}

HSM_StatusType HSM_UserKeyImport(HSM_CmdType *pCmd, const HSMCom_UserKeyManageType *pCfg)
{
    return hsm_assign_val(pCmd, ((hsm_uint32_t)HSM_CMD_ID_USER_KEY_MANAGE << 16u) | HSMCOM_KEYMANAGER_IMPORT_USER_KEY, (hsm_uint32_t)pCfg);
}

HSM_StatusType HSM_UserKeyExport(HSM_CmdType *pCmd, const HSMCom_UserKeyManageType *pCfg)
{
    return hsm_assign_val(pCmd, ((hsm_uint32_t)HSM_CMD_ID_USER_KEY_MANAGE << 16u) | HSMCOM_KEYMANAGER_EXPORT_USER_KEY, (hsm_uint32_t)pCfg);
}

HSM_StatusType HSM_GetKeySpaceStat(HSM_CmdType *pCmd, const HSMCom_KeySpaceStatusType *pCfg)
{
    return hsm_assign_val(pCmd, ((hsm_uint32_t)HSM_CMD_ID_SPACE_MANAGE << 16u) | HSMCOM_KEYSPACE_GET_STATUS, (hsm_uint32_t)pCfg);
}

HSM_StatusType HSM_TidyUpKeySpace(HSM_CmdType *pCmd, const HSMCom_KeySpaceStatusType *pCfg)
{
    return hsm_assign_val(pCmd, ((hsm_uint32_t)HSM_CMD_ID_SPACE_MANAGE << 16u) | HSMCOM_KEYSPACE_NEATEN, (hsm_uint32_t)pCfg);
}

HSM_StatusType HSM_UserKeyRevoke(HSM_CmdType *pCmd, const HSMCom_UserKeyManageType *pCfg)
{
    return hsm_assign_val(pCmd, ((hsm_uint32_t)HSM_CMD_ID_USER_KEY_MANAGE << 16u) | HSMCOM_KEYMANAGER_REVOKE_USER_KEY, (hsm_uint32_t)pCfg);
}

HSM_StatusType HSM_AesEncrypt(HSM_CmdType *pCmd, const HSMCom_AesEncryptType *pCfg)
{
    return hsm_assign_val(pCmd, ((hsm_uint32_t)HSM_CMD_ID_AES_ENCRY << 16u), (hsm_uint32_t)pCfg);
}

HSM_StatusType HSM_AesEncryptEx(HSM_CmdType *pCmd, const HSMCom_FlexAesEncryptType *pCfg)
{
    hsm_uint32_t u32Flag = ((pCfg->tCfg.ePad & 0x1u) << 1u) | ((pCfg->tCfg.eInputFmt & 0x1u) << 2u) | ((pCfg->tCfg.eOutputFmt & 0x1u) << 3u);

    if (NULL_PTR != (pCfg->tCfg.pGenerateOutByteCnt))
    {
        u32Flag |= 0x1;
    }
    else
    {
        ;
    }
    return hsm_assign_val(pCmd, ((hsm_uint32_t)HSM_CMD_ID_AES_ENCRY << 16u) | u32Flag, (hsm_uint32_t)pCfg);
}


HSM_StatusType HSM_AesDecrypt(HSM_CmdType *pCmd, const HSMCom_AesDecryptType *pCfg)
{
    return hsm_assign_val(pCmd, ((hsm_uint32_t)HSM_CMD_ID_AES_DECRY << 16u), (hsm_uint32_t)pCfg);
}

HSM_StatusType HSM_AesDecryptEx(HSM_CmdType *pCmd, const HSMCom_FlexAesDecryptType *pCfg)
{
    hsm_uint32_t u32Flag = ((pCfg->tCfg.ePad & 0x1u) << 1u) | ((pCfg->tCfg.eInputFmt & 0x1u) << 2u) | ((pCfg->tCfg.eOutputFmt & 0x1u) << 3u);

    if (NULL_PTR != (pCfg->tCfg.pGenerateOutByteCnt))
    {
        u32Flag |= 0x1;
    }
    else
    {
        ;
    }
    return hsm_assign_val(pCmd, ((hsm_uint32_t)HSM_CMD_ID_AES_DECRY << 16u) | u32Flag, (hsm_uint32_t)pCfg);
}


HSM_StatusType HSM_CMac(HSM_CmdType *pCmd, const HSMCom_CMacType *pCfg)
{
    return hsm_assign_val(pCmd, ((hsm_uint32_t)HSM_CMD_ID_CMAC_GEN << 16u), (hsm_uint32_t)pCfg);
}

HSM_StatusType HSM_CMacEx(HSM_CmdType *pCmd, const HSMCom_CMacExType *pCfg)
{
    return hsm_assign_val(pCmd, ((hsm_uint32_t)HSM_CMD_ID_CMAC_GEN << 16u) | (pCfg->tCfg.eEngine & 0x1u) | ((pCfg->tCfg.eInputFmt & 0x1u) << 1u) | ((pCfg->tCfg.eOutputFmt & 0x1u) << 2u), (hsm_uint32_t)pCfg);
}


HSM_StatusType HSM_XMac(HSM_CmdType *pCmd, const HSMCom_XMacType *pCfg)
{
    return hsm_assign_val(pCmd, ((hsm_uint32_t)HSM_CMD_ID_XMAC_GEN << 16u), (hsm_uint32_t)pCfg);
}

HSM_StatusType HSM_CcmEncry(HSM_CmdType *pCmd, const HSMCom_CcmEncryptType *pCfg)
{
    return hsm_assign_val(pCmd, ((hsm_uint32_t)HSM_CMD_ID_CCM_ENCRY << 16u), (hsm_uint32_t)pCfg);
}

HSM_StatusType HSM_CcmDecry(HSM_CmdType *pCmd, const HSMCom_CcmDecryptType *pCfg)
{
    return hsm_assign_val(pCmd, ((hsm_uint32_t)HSM_CMD_ID_CCM_DECRY << 16u), (hsm_uint32_t)pCfg);
}

HSM_StatusType HSM_GcmEncry(HSM_CmdType *pCmd, const HSMCom_GcmEncryptType *pCfg)
{
    return hsm_assign_val(pCmd, ((hsm_uint32_t)HSM_CMD_ID_GCM_ENCRY << 16u), (hsm_uint32_t)pCfg);
}

HSM_StatusType HSM_GcmDecry(HSM_CmdType *pCmd, const HSMCom_GcmDecryptType *pCfg)
{
    return hsm_assign_val(pCmd, ((hsm_uint32_t)HSM_CMD_ID_GCM_DECRY << 16u), (hsm_uint32_t)pCfg);
}

HSM_StatusType HSM_Md5(HSM_CmdType *pCmd, const HSMCom_Md5Type *pCfg)
{
    return hsm_assign_val(pCmd, ((hsm_uint32_t)HSM_CMD_ID_MD5 << 16u), (hsm_uint32_t)pCfg);
}

HSM_StatusType HSM_Sm3(HSM_CmdType *pCmd, const HSMCom_Sm3Type *pCfg)
{
    return hsm_assign_val(pCmd, ((hsm_uint32_t)HSM_CMD_ID_SM3 << 16u), (hsm_uint32_t)pCfg);
}

HSM_StatusType HSM_MonotonicCounterIncrease(HSM_CmdType *pCmd, const HSMCom_MonCountType *pCfg)
{
    return hsm_assign_val(pCmd, ((hsm_uint32_t)HSM_CMD_ID_MONOTONIC_COUNTER << 16u) | HSMCOM_INCREASE_COUNTER, (hsm_uint32_t)pCfg);
}

HSM_StatusType HSM_MonotonicCounterRead(HSM_CmdType *pCmd, const HSMCom_MonCountType *pCfg)
{
    return hsm_assign_val(pCmd, ((hsm_uint32_t)HSM_CMD_ID_MONOTONIC_COUNTER << 16u) | HSMCOM_READ_COUNTER, (hsm_uint32_t)pCfg);
}

HSM_StatusType HSM_Rsa(HSM_CmdType *pCmd, const HSMCom_RsaType *pCfg)
{
    return hsm_assign_val(pCmd, ((hsm_uint32_t)HSM_CMD_ID_RSA << 16u), (hsm_uint32_t)pCfg);
}

HSM_StatusType HSM_BigNumberCalculateEx(HSM_CmdType *pCmd, const HSMCom_BigNumberCalcType *pCfg)
{
    return hsm_assign_val(pCmd, ((hsm_uint32_t)HSM_CMD_ID_RSA << 16u) | 0x1u, (hsm_uint32_t)pCfg);
}

HSM_StatusType HSM_LoadFirmware(HSM_CmdType *pCmd, HSMCom_LoadFirmwareType *pCfg)
{
    return hsm_assign_val(pCmd, ((hsm_uint32_t)HSM_CMD_ID_LOAD_FIRMWARE << 16u), (hsm_uint32_t)pCfg);
}


/* fc7300 fw, fc7240 fw */
HSM_StatusType HSM_FW_ShaEx(HSM_CmdType *pCmd, const HSMCom_ShaExType *pCfg, HSM_BoolType  bKeyUseId)
{
    return hsm_assign_val(pCmd,
        ((hsm_uint32_t)HSM_CMD_ID_SHA << 16u) |
        (pCfg->tCfg.eInputFmt & 0x1u) |
        ((pCfg->tCfg.eOutputFmt & 0x1u) << 1u) |
        ((bKeyUseId & 0x1u) << 3u), (hsm_uint32_t)pCfg);
}

/* fc7300 fw, fc7240 fw */
HSM_StatusType HSM_FW_Md5Ex(HSM_CmdType *pCmd, const HSMCom_Md5ExType *pCfg, HSM_BoolType  bKeyUseId)
{
    return hsm_assign_val(pCmd,
        ((hsm_uint32_t)HSM_CMD_ID_MD5 << 16u) |
        (pCfg->tCfg.eInputFmt & 0x1u) |
        ((pCfg->tCfg.eOutputFmt & 0x1u) << 1u) |
        (((bKeyUseId & 0x1u) << 2u)),
        (hsm_uint32_t)pCfg);
}

/* fc7300 fw, fc7240 fw */
HSM_StatusType HSM_FW_Sm3Ex (HSM_CmdType *pCmd, const HSMCom_Sm3ExType *pCfg, HSM_BoolType  bKeyUseId)
{
    return hsm_assign_val(pCmd,
        ((hsm_uint32_t)HSM_CMD_ID_SM3 << 16u) |
        (pCfg->tCfg.eInputFmt & 0x1u) |
        ((pCfg->tCfg.eOutputFmt & 0x1u) << 1u) |
        (((bKeyUseId & 0x1u) << 2u)),
        (hsm_uint32_t)pCfg);
}


HSM_StatusType HSM_FW_ScatterHashInit(HSM_CmdType *pCmd, const HSMCom_ScatterHashType *pCfg, HSM_BoolType bKeyUseId, HSM_DataFormatType eInputFmt)
{
    HSM_StatusType eRet = HSM_STATUS_SUCCESS;
    hsm_uint32_t u32AuxId = 0u;

    if ((HSM_FALSE != pCfg->tCfg.tCfg.bGenerateMacEn) && (HSM_FALSE != bKeyUseId))
    {
        u32AuxId |= (((hsm_uint32_t)0x1u) << 7u);
    }
    /* else do nothing */

#if (FC7XXX_HSM_SUBSYSTEM_TYPE != FC7300_HSM_SUBSYSTEM)
    if (HSM_DATA_FORMAT_1B == eInputFmt)
    {
        u32AuxId |= (((hsm_uint32_t)0x1u) << 3u);
    }
    /* else do nothing */
#else
    if (HSM_DATA_FORMAT_4B != eInputFmt)
    {
        eRet = HSM_STATUS_HW_ERR;
    }
#endif

    if (HSM_STATUS_SUCCESS == eRet)
    {
        eRet = hsm_assign_val(pCmd, ((hsm_uint32_t)HSM_CMD_ID_SCATTER_HASH << 16u) | u32AuxId, (hsm_uint32_t)pCfg);
    }
    /* else do nothing */

    return eRet;
}

HSM_StatusType HSM_FW_ScatterHashUpdate(HSM_CmdType *pCmd, const HSMCom_ScatterHashType *pCfg, HSM_BoolType bKeyUseId, HSM_DataFormatType eInputFmt)
{
    HSM_StatusType eRet = HSM_STATUS_SUCCESS;
    hsm_uint32_t u32AuxId = 0u;

    if ((HSM_FALSE != pCfg->tCfg.tCfg.bGenerateMacEn) && (HSM_FALSE != bKeyUseId))
    {
        u32AuxId |= (((hsm_uint32_t)0x1u) << 7u);
    }
    /* else do nothing */

#if (FC7XXX_HSM_SUBSYSTEM_TYPE != FC7300_HSM_SUBSYSTEM)
    if (HSM_DATA_FORMAT_1B == eInputFmt)
    {
        u32AuxId |= (((hsm_uint32_t)0x1u) << 3u);
    }
    /* else do nothing */
#else
    if (HSM_DATA_FORMAT_4B != eInputFmt)
    {
        eRet = HSM_STATUS_HW_ERR;
    }
#endif

    if (HSM_STATUS_SUCCESS == eRet)
    {
        eRet = hsm_assign_val(pCmd, ((hsm_uint32_t)HSM_CMD_ID_SCATTER_HASH << 16u) | 0x1 | 0x4 | u32AuxId, (hsm_uint32_t)pCfg);
    }
    /* else do nothing */

    return eRet;
}

HSM_StatusType HSM_FW_ScatterHashFinal(HSM_CmdType *pCmd, const HSMCom_ScatterHashType *pCfg, HSM_BoolType bKeyUseId, HSM_DataFormatType eInputFmt)
{
    HSM_StatusType eRet = HSM_STATUS_SUCCESS;
    hsm_uint32_t u32AuxId = 0u;

    if ((HSM_FALSE != pCfg->tCfg.tCfg.bGenerateMacEn) && (HSM_FALSE != bKeyUseId))
    {
        u32AuxId |= (((hsm_uint32_t)0x1u) << 7u);
    }
    /* else do nothing */

#if (FC7XXX_HSM_SUBSYSTEM_TYPE != FC7300_HSM_SUBSYSTEM)
    if (HSM_DATA_FORMAT_1B == eInputFmt)
    {
        u32AuxId |= (((hsm_uint32_t)0x1u) << 3u);
    }
    /* else do nothing */
#else
    if (HSM_DATA_FORMAT_4B != eInputFmt)
    {
        eRet = HSM_STATUS_HW_ERR;
    }
#endif

    if (HSM_STATUS_SUCCESS == eRet)
    {
        eRet = hsm_assign_val(pCmd, ((hsm_uint32_t)HSM_CMD_ID_SCATTER_HASH << 16u) | 0x2 | 0x4 | u32AuxId, (hsm_uint32_t)pCfg);
    }
    /* else do nothing */

    return eRet;
}

HSM_StatusType hsm_fw_scattercmaciuf(HSM_CmdType *pCmd, const HSMCom_AesmRawApiType *pCfg, HSM_DataFormatType eInputFmt, HSM_DataFormatType eKeyFmt, hsm_uint32_t u32AuxId)
{
    HSM_StatusType eRet = HSM_STATUS_SUCCESS;

#if (FC7XXX_HSM_SUBSYSTEM_TYPE != FC7300_HSM_SUBSYSTEM)
    if (HSM_DATA_FORMAT_1B == eInputFmt)
    {
        u32AuxId |= (((hsm_uint32_t)0x1u) << 1u);
    }
    /* else do nothing */
#else
    if (HSM_DATA_FORMAT_4B != eInputFmt)
    {
        eRet = HSM_STATUS_HW_ERR;
    }
#endif

    if (HSM_DATA_FORMAT_1B == eKeyFmt)
    {
        u32AuxId |= (((hsm_uint32_t)0x1u) << 3u);
    }
    /* else do nothing */

    if (HSM_STATUS_SUCCESS == eRet)
    {
        eRet = hsm_assign_val(pCmd, ((hsm_uint32_t)HSM_CMD_ID_AESM_RAW_API << 16u) | u32AuxId, (hsm_uint32_t)pCfg);
    }
    /* else do nothing */

    return eRet;
}

HSM_StatusType HSM_FW_ScatterCMacInit(HSM_CmdType *pCmd, const HSMCom_AesmRawApiType *pCfg, HSM_DataFormatType eInputFmt, HSM_DataFormatType eKeyFmt)
{
    return hsm_fw_scattercmaciuf(pCmd, pCfg, eInputFmt, eKeyFmt, 0x0);
}

HSM_StatusType HSM_FW_ScatterCMacUpdate(HSM_CmdType *pCmd, const HSMCom_AesmRawApiType *pCfg, HSM_DataFormatType eInputFmt, HSM_DataFormatType eKeyFmt)
{
    return hsm_fw_scattercmaciuf(pCmd, pCfg, eInputFmt, eKeyFmt, 0x1);
}

HSM_StatusType HSM_FW_ScatterCMacFinal(HSM_CmdType *pCmd, const HSMCom_AesmRawApiType *pCfg, HSM_DataFormatType eInputFmt, HSM_DataFormatType eKeyFmt)
{
    return hsm_fw_scattercmaciuf(pCmd, pCfg, eInputFmt, eKeyFmt, 0x1);
}

/* 7300 fw, 7240 rom */
HSM_StatusType HSM_FW_EccEncrypt(HSM_CmdType *pCmd, const HSMCom_EccEasyEncryType *pCfg)
{
    return hsm_assign_val(pCmd, ((hsm_uint32_t)HSM_CMD_ID_ECC_ENCRY << 16u), (hsm_uint32_t)pCfg);
}

/* 7300 fw, 7240 rom */
HSM_StatusType HSM_FW_EccSign(HSM_CmdType *pCmd, const HSMCom_EccSignType *pCfg)
{
    return hsm_assign_val(pCmd, ((hsm_uint32_t)HSM_CMD_ID_ECC_SIGN << 16u), (hsm_uint32_t)pCfg);
}

/* 7300 fw, 7240 rom */
HSM_StatusType HSM_FW_Sm2GenKeyPair(HSM_CmdType *pCmd, const HSMCom_Sm2GenKeyPairType *pCfg)
{
    return hsm_assign_val(pCmd, ((hsm_uint32_t)HSM_CMD_ID_SM2_GENKEYPAIR << 16u), (hsm_uint32_t)pCfg);
}

/* 7300 fw, 7240 rom */
HSM_StatusType HSM_FW_Sm2Encry(HSM_CmdType *pCmd, const HSMCom_Sm2EncryptType *pCfg)
{
    return hsm_assign_val(pCmd, ((hsm_uint32_t)HSM_CMD_ID_SM2_ENCRY << 16u), (hsm_uint32_t)pCfg);
}

/* 7300 fw, 7240 fw, fc7300gt rom */
HSM_StatusType HSM_FW_UserKeyGenPair(HSM_CmdType *pCmd, const HSMCom_UserKeyManageType *pCfg)
{
    return hsm_assign_val(pCmd, ((hsm_uint32_t)HSM_CMD_ID_USER_KEY_MANAGE << 16u) | HSMCOM_KEYMANAGER_GEN_UESR_KEY, (hsm_uint32_t)pCfg);
}

/* 7300 fw, 7240 fw, fc7300gt rom */
HSM_StatusType HSM_FW_Sm2Sign(HSM_CmdType *pCmd, const HSMCom_Sm2SignType *pCfg)
{
    return hsm_assign_val(pCmd, ((hsm_uint32_t)HSM_CMD_ID_SM2_SIGN << 16u), (hsm_uint32_t)pCfg);
}

/* 7300 fw, 7240 fw, fc7300gt rom */
HSM_StatusType HSM_FW_UserKeyRevoke(HSM_CmdType *pCmd, const HSMCom_UserKeyManageType *pCfg)
{
    return hsm_assign_val(pCmd, ((hsm_uint32_t)HSM_CMD_ID_USER_KEY_MANAGE << 16u) | ((hsm_uint32_t)HSMCOM_KEYMANAGER_REVOKE_USER_KEY), (hsm_uint32_t)pCfg);
}

/* 7300 fw, 7240 fw, fc7300gt rom */
HSM_StatusType HSM_FW_RsaSsaPssVerify(HSM_CmdType *pCmd, const HSMCom_RsaSsaPssVerifyType *pCfg)
{
    return hsm_assign_val(pCmd, ((hsm_uint32_t)HSM_CMD_ID_RSA_SSA_PSS_VERIFY << 16u), (hsm_uint32_t)pCfg);
}

/* 7300 fw, 7240 fw, fc7300gt rom */
HSM_StatusType HSM_FW_RsaSsaPkcs1v15Verify(HSM_CmdType *pCmd, const HSMCom_RsaSsaPkcs1V15VerifyType *pCfg)
{
    HSM_StatusType eRet = HSM_STATUS_SUCCESS;
    hsm_uint32_t u32AuxId = 0u;

#if (FC7XXX_HSM_SUBSYSTEM_TYPE != FC7240_HSM_SUBSYSTEM)
    u32AuxId |= 0x1u;
#else
    if ((HSM_RSA_SSA_INPUT_RAW_MESSAGE == pCfg->tCfg.eInputType) &&
        (pCfg->tCfg.eInputFmt == pCfg->tCfg.eSignDataFmt) &&
        (pCfg->tCfg.ePublicKeyFmt == pCfg->tCfg.eSignDataFmt) &&
        (pCfg->tCfg.eKeyNFmt == pCfg->tCfg.eSignDataFmt))
    {
        ;
    }
    else
    {
        eRet = HSM_STATUS_HW_ERR;
    }

#endif


    if (HSM_STATUS_SUCCESS == eRet)
    {
        eRet = hsm_assign_val(pCmd, ((hsm_uint32_t)HSM_CMD_ID_RSA_SSA_PKCS1V15_VERIFY << 16u) | u32AuxId, (hsm_uint32_t)pCfg);
    }
    /* else do nothing */

    return eRet;
}

/* fc7300 fw, fc7240 fw */
HSM_StatusType HSM_FW_UserKeyImportNew(HSM_CmdType *pCmd, const HSMCom_UserKeyManageType *pCfg)
{
    return hsm_assign_val(pCmd, ((hsm_uint32_t)HSM_CMD_ID_USER_KEY_MANAGE << 16u) | HSMCOM_KEYMANAGER_IMPORT_USER_KEY_NEW, (hsm_uint32_t)pCfg);
}

#if ((FC7XXX_HSM_SUBSYSTEM_TYPE == FC7240_HSM_SUBSYSTEM) || (FC7XXX_HSM_SUBSYSTEM_TYPE == FC7300_HSM_SUBSYSTEM))
/* fc7300 fw, fc7240 fw */
HSM_StatusType HSM_FW_CheckKeyIdExt(HSM_CmdType *pCmd, const HSMCom_UserKeyManageType *pCfg)
{
    return hsm_assign_val(pCmd, ((hsm_uint32_t)HSM_CMD_ID_USER_KEY_MANAGE << 16u) | ((hsm_uint32_t)HSMCOM_KEYMANAGER_CHECK_KEYID_EXIST_EXT), (hsm_uint32_t)pCfg);
}
#endif

/* fc7300 fw, fc7240 fw */
HSM_StatusType HSM_FW_CopyKeyExt(HSM_CmdType *pCmd, const HSMCom_UserKeyManageType *pCfg)
{
    return hsm_assign_val(pCmd, ((hsm_uint32_t)HSM_CMD_ID_USER_KEY_MANAGE << 16u) | ((hsm_uint32_t)HSMCOM_KEYMANAGER_COPY_KEY), (hsm_uint32_t)pCfg);
}

/* fc7300 fw, fc7240 fw */
HSM_StatusType HSM_FW_BigNumberCalculateEx(HSM_CmdType *pCmd, const HSMCom_BigNumberCalcExtType *pCfg)
{
    return hsm_assign_val(pCmd, ((hsm_uint32_t)HSM_CMD_ID_RSA << 16u) | 0x2u, (hsm_uint32_t)pCfg);
}

/* fc7300 fw, fc7240 fw */
HSM_StatusType HSM_FW_RsaSsaPssSign(HSM_CmdType *pCmd, const HSMCom_RsaSsaPssSignType *pCfg)
{
    return hsm_assign_val(pCmd, ((hsm_uint32_t)HSM_CMD_ID_RSA_SSA_PSS_SIGN << 16u), (hsm_uint32_t)pCfg);
}

/* fc7300 fw, fc7240 fw */
HSM_StatusType HSM_FW_RsaSsaPkcs1v15Sign(HSM_CmdType *pCmd, const HSMCom_RsaSsaPkcs1v15SignType *pCfg)
{
    HSM_StatusType eRet = HSM_STATUS_SUCCESS;
    hsm_uint32_t u32AuxId = 0u;

#if FC7XXX_HSM_SUBSYSTEM_TYPE != FC7240_HSM_SUBSYSTEM
    u32AuxId |= 0x1u;
#else
    if (HSM_RSA_SSA_INPUT_RAW_MESSAGE == pCfg->tCfg.eInputType)
    {
        ;
    }
    else
    {
        eRet = HSM_STATUS_HW_ERR;
    }

#endif

    if (HSM_STATUS_SUCCESS == eRet)
    {
        eRet = hsm_assign_val(pCmd, ((hsm_uint32_t)HSM_CMD_ID_RSA_SSA_PKCS1V15_SIGN << 16u) | u32AuxId, (hsm_uint32_t)pCfg);
    }
    /* else do nothing */

    return eRet;
}

/* fc7300 fw, fc7240 fw */
#if ((FC7XXX_HSM_SUBSYSTEM_TYPE == FC7240_HSM_SUBSYSTEM) || (FC7XXX_HSM_SUBSYSTEM_TYPE == FC7300_HSM_SUBSYSTEM))
HSM_StatusType HSM_FW_GetKeyIdStatus(HSM_CmdType *pCmd, const HSMCom_UserKeyManageType *pCfg)
{
    return hsm_assign_val(pCmd, ((hsm_uint32_t)HSM_CMD_ID_USER_KEY_MANAGE << 16u) | HSMCOM_KEYMANAGER_CHECK_KEYID_STATUS_EXT, (hsm_uint32_t)pCfg);
}
#endif

#if ((FC7XXX_HSM_SUBSYSTEM_TYPE == FC7240_HSM_SUBSYSTEM) || (FC7XXX_HSM_SUBSYSTEM_TYPE == FC7300_HSM_SUBSYSTEM))
#else

HSM_StatusType HSM_UpdateKeyContentOfSpecificKeyId(HSM_CmdType *pCmd, const HSMCom_UserKeyManageType *pCfg)
{
    return hsm_assign_val(pCmd, ((hsm_uint32_t)HSM_CMD_ID_USER_KEY_MANAGE << 16u) | HSMCOM_KEYMANAGER_UPDATE_KEY, (hsm_uint32_t)pCfg);
}
#endif

HSM_StatusType HSM_RomHash(HSM_CmdType *pCmd, const HSMCom_GetRomHashType*pCfg)
{
    return hsm_assign_val(pCmd,(uint32_t)(HSM_CMD_ID_ROM_HASH << 16), (uint32_t)pCfg);
}
