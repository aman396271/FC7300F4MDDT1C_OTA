/**
*   @file    Crypto_Level2Api.c
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
/********************************************* Level1 function *********************************************************/
HSM_StatusType hsm_1B4B_convert_from_idx(HSM_DataFormatType eDstFmt, void *pDst, hsm_uint32_t u32DstStartIdx, hsm_uint32_t u32DstBufByteSize,
                                         HSM_DataFormatType eSrcFmt, const void *pSrc, hsm_uint32_t u32SrcStartIdx, hsm_uint32_t u32SrcStopIdx);
void hsm_bidi_memcpy(void *pDstMem, const void *pSrcMem, hsm_uint32_t u32OpCnt, hsm_int32_t sOpDirection);
void hsm_memcpy(void *pDstMem, const void *pSrcMem, hsm_uint32_t u32Cnt);
void hsm_memset(void *pDstMem, hsm_uint8_t u8Val, hsm_uint32_t u32Cnt);
hsm_int32_t hsm_memcmp(const void *pDst, const void *pSrc, hsm_uint32_t u32OpCnt);
HSM_StatusType hsm_hash_get_result_byte_count(HFAM_MODE_E eMode, hsm_uint32_t *pRetByteCnt);
void hsm_u32_array_swap(hsm_uint32_t *pData, hsm_uint32_t u32WordCnt);
void hsm_u32_array_swap_to(hsm_uint32_t *pData, const hsm_uint32_t *pSrc, hsm_uint32_t u32WordCnt);
void hsm_rm_prefix_zeros(
            HSM_DataFormatType eInputFmt, const hsm_uint8_t *pData, hsm_uint32_t u32ByteCount, const hsm_uint8_t **ppActualData, hsm_uint32_t *pActualByteCnt);
void hsm_core_swap_u32_array_pad(
            hsm_uint32_t *pAlignedDest, hsm_uint32_t u32DestWordCnt, const hsm_uint8_t *pSrc,
            hsm_uint32_t u32SrcOpByteCnt, hsm_uint8_t u8PadByte, HSM_BoolType bPadFromMSB, HSM_BoolType bSwap);
void HSM_L1_CleanEnv(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_CommonExitEnv(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_Abort(HSM_L1_RtCtxType *pCtx);
void HSM_L1_Init(HSM_L1_RtCtxType *pCtx, HSM_L1_InitParmType *pParm);
HSM_StatusType HSM_L1_Md5SetupEnv(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_Md5Reset(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_Md5ExitEnv(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_Md5(HSM_L1_RtCtxType *pCtx, const HSM_Ln_Md5Type *pCfg,  hsm_uint32_t u32TimeoutMs);
HSM_StatusType HSM_L1_Md5_Isr(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_Md5Poll(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_Sm3SetupEnv(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_Sm3Reset(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_Sm3ExitEnv(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_Sm3(HSM_L1_RtCtxType *pCtx, const HSM_Ln_Sm3Type *pCfg,  hsm_uint32_t u32TimeoutMs);
HSM_StatusType HSM_L1_Sm3_Isr(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_Sm3Poll(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_ShaSetupEnv(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_ShaReset(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_ShaExitEnv(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_Sha(HSM_L1_RtCtxType *pCtx, const HSM_Ln_ShaType *pCfg,  hsm_uint32_t u32TimeoutMs);
HSM_StatusType HSM_L1_Sha_Isr(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_ShaPoll(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_RngSetupEnv(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_RngReset(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_RngExitEnv(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_Rng(HSM_L1_RtCtxType *pCtx, const HSM_Ln_RngType *pCfg,  hsm_uint32_t u32TimeoutMs);
HSM_StatusType HSM_L1_Rng_Isr(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_RngPoll(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_EccVerifySetupEnv(HSM_L1_RtCtxType *pCtx, hsm_uint32_t u32BitCnt);
HSM_StatusType HSM_L1_EccVerifyExitEnv(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_EccVerify(HSM_L1_RtCtxType *pCtx, const HSM_L1_EccVerifyType *pCfg,  hsm_uint32_t u32TimeoutMs);
HSM_StatusType HSM_L1_EccVerify_Isr(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_EccVerifyPoll(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_EccVerifyReset(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_EccDecryptSetupEnv(HSM_L1_RtCtxType *pCtx, hsm_uint32_t u32BitCnt);
HSM_StatusType HSM_L1_EccDecryptExitEnv(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_EccDecrypt(HSM_L1_RtCtxType *pCtx, const HSM_Ln_EccDecryptType *pCfg,  hsm_uint32_t u32TimeoutMs);
HSM_StatusType HSM_L1_EccDecrypt_Isr(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_EccDecryptPoll(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_EccDecryptReset(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_EccCalculateSetupEnv(HSM_L1_RtCtxType *pCtx, hsm_uint32_t u32BitCnt);
HSM_StatusType HSM_L1_EccCalculateExitEnv(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_EccCalculateKP(HSM_L1_RtCtxType *pCtx, const HSM_Ln_EccKPType *pCfg,  hsm_uint32_t u32TimeoutMs);
HSM_StatusType HSM_L1_EccCalculate_Isr(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_EccCalculatePoll(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_EccCalculateReset(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_CMacSetupEnv(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_CMacReset(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_CMacExitEnv(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_CMac(HSM_L1_RtCtxType *pCtx, const HSM_Ln_CMacType *pCfg,  hsm_uint32_t u32TimeoutMs);
HSM_StatusType HSM_L1_CMac_Isr(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_CMacPoll(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_AesEncryptSetupEnv(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_AesEncryptReset(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_AesEncryptExitEnv(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_AesEncrypt(HSM_L1_RtCtxType *pCtx, const HSM_Ln_AesEncryptType *pCfg,  hsm_uint32_t u32TimeoutMs);
HSM_StatusType HSM_L1_AesEncrypt_Isr(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_AesEncryptPoll(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_AesDecryptSetupEnv(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_AesDecryptReset(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_AesDecryptExitEnv(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_AesDecrypt(HSM_L1_RtCtxType *pCtx, const HSM_Ln_AesDecryptType *pCfg,  hsm_uint32_t u32TimeoutMs);
HSM_StatusType HSM_L1_AesDecrypt_Isr(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_AesDecryptPoll(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_Sm4EncryptSetupEnv(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_Sm4EncryptReset(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_Sm4EncryptExitEnv(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_Sm4Encrypt(HSM_L1_RtCtxType *pCtx, const HSM_Ln_Sm4EncryptType *pCfg, hsm_uint32_t u32TimeoutMs);
HSM_StatusType HSM_L1_Sm4Encrypt_Isr(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_Sm4EncryptPoll(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_Sm4DecryptSetupEnv(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_Sm4DecryptReset(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_Sm4DecryptExitEnv(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_Sm4Decrypt(HSM_L1_RtCtxType *pCtx, const HSM_Ln_Sm4DecryptType *pCfg,  hsm_uint32_t u32TimeoutMs);
HSM_StatusType HSM_L1_Sm4Decrypt_Isr(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_Sm4DecryptPoll(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_BnCalcSetupEnv(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_BnCalcExitEnv(HSM_L1_RtCtxType *pCtx);
hsm_uint32_t hsm_pkam_get_actual_size(HSM_DataFormatType eDataFormat, const void *pData, hsm_uint32_t u32ByteCount, const hsm_uint8_t **ppLastNonZero);
HSM_StatusType hsm_pkam_get_bn_bit_count(HSM_DataFormatType eFmt, const hsm_uint8_t *pData, hsm_uint32_t u32ByteCnt, hsm_uint32_t *pBitCnt);
HSM_StatusType HSM_L1_BnCalc(HSM_L1_RtCtxType *pCtx, const HSM_L1_BnCalcType *pCfg,  hsm_uint32_t u32TimeoutMs);
HSM_StatusType HSM_L1_BnCalc_Isr(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_BnCalcPoll(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_BnCalcReset(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_ScatterHashSetupEnv(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_ScatterHashSetMacCfg(HSM_L1_RtCtxType *pCtx, HSM_Ln_HashMacCfgType *ptCfg);
HSM_StatusType HSM_L1_ScatterHashInit(HSM_L1_RtCtxType *pCtx, const HSM_ShaAlgType eAlg, const HSM_Ln_ScatterHashType *pCfg, hsm_uint32_t u32TimeoutMs);
HSM_StatusType HSM_L1_ScatterHashUpdate(HSM_L1_RtCtxType *pCtx, const HSM_Ln_ScatterHashType *pCfg, hsm_uint32_t u32TimeoutMs);
HSM_StatusType hsm_aux_get_empty_data_hash(HSM_ShaAlgType eHash, const hsm_uint8_t **ppHashData, hsm_uint32_t *pByteCnt);
HSM_StatusType HSM_L1_ScatterHashFinal(HSM_L1_RtCtxType *pCtx, const HSM_Ln_ScatterHashType *pCfg, const HSM_Ln_ResultBufInfoType *pResult, hsm_uint32_t u32TimeoutMs);
HSM_StatusType HSM_L1_ScatterHash_Isr(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_ScatterHashPoll(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_ScatterHashExitEnv(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_ScatterCMacSetupEnv(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_ScatterCMacInit(HSM_L1_RtCtxType *pCtx, const HSM_Ln_CMacCfgParmsType *pKeyCfg, const HSM_Ln_ScatterCMacType *pCfg, hsm_uint32_t u32TimeoutMs);
HSM_StatusType HSM_L1_ScatterCMacUpdate(HSM_L1_RtCtxType *pCtx, const HSM_Ln_ScatterCMacType *pCfg, hsm_uint32_t u32TimeoutMs);
HSM_StatusType HSM_L1_ScatterCMacFinal(HSM_L1_RtCtxType *pCtx, const HSM_Ln_ScatterCMacType *pCfg, const HSM_Ln_ResultBufInfoType *pResult, hsm_uint32_t u32TimeoutMs);
HSM_StatusType HSM_L1_ScatterCMac_Isr(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_ScatterCMacPoll(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_ScatterCMacExitEnv(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_EccSignSetupEnv(HSM_L1_RtCtxType *pCtx, hsm_uint32_t u32BitCnt);
HSM_StatusType HSM_L1_EccSignExitEnv(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_EccSign(HSM_L1_RtCtxType *pCtx, const HSM_Ln_EccSignType *pCfg,  hsm_uint32_t u32TimeoutMs);
HSM_StatusType HSM_L1_EccSign_Isr(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_EccSignPoll(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_EccSignReset(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_RsaSsaPssVerifySetupEnv(HSM_L1_RtCtxType *pCtx, hsm_uint32_t u32RsaBitCnt);
HSM_StatusType HSM_L1_RsaSsaPssVerify(HSM_L1_RtCtxType *pCtx, const HSM_Ln_RsaSsaPssVerifyType *pCfg, hsm_uint32_t u32TimeoutMs);
HSM_StatusType HSM_L1_RsaSsaPssVerifyPoll(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_RsaSsaPssVerifyReset(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_RsaSsaPssVerify_Isr(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_RsaSsaPssVerifyExitEnv(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_RsaSsaPkcs1V15VerifySetupEnv(HSM_L1_RtCtxType *pCtx, hsm_uint32_t u32RsaBitCnt);
HSM_StatusType HSM_L1_RsaSsaPkcs1V15Verify(HSM_L1_RtCtxType *pCtx, const HSM_Ln_RsaSsaPkcs1v15VerifyType *pCfg, hsm_uint32_t u32TimeoutMs);
HSM_StatusType HSM_L1_RsaSsaPkcs1V15VerifyPoll(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_RsaSsaPkcs1V15VerifyReset(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_RsaSsaPkcs1V15Verify_Isr(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_RsaSsaPkcs1V15VerifyExitEnv(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_KeyImportSetupEnv(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_KeyImport(HSM_L1_RtCtxType *pCtx, const HSM_Ln_ImportUserKeyExtType *pCfg, hsm_uint32_t u32TimeoutMs);
HSM_StatusType HSM_L1_KeyImportPoll(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_KeyImportReset(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_KeyImportExitEnv(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_KeyImport_Isr(HSM_L1_RtCtxType *pCtx);
#if ((FC7XXX_HSM_SUBSYSTEM_TYPE == FC7240_HSM_SUBSYSTEM) || (FC7XXX_HSM_SUBSYSTEM_TYPE == FC7300_HSM_SUBSYSTEM))
    HSM_StatusType HSM_L1_KeyValidateSetupEnv(HSM_L1_RtCtxType *pCtx);
    HSM_StatusType HSM_L1_KeyValidate(HSM_L1_RtCtxType *pCtx, hsm_uint32_t u32KeyId, hsm_uint32_t u32TimeoutMs);
    HSM_StatusType HSM_L1_KeyValidatePoll(HSM_L1_RtCtxType *pCtx);
    HSM_StatusType HSM_L1_KeyValidateReset(HSM_L1_RtCtxType *pCtx);
    HSM_StatusType HSM_L1_KeyValidateExitEnv(HSM_L1_RtCtxType *pCtx);
    HSM_StatusType HSM_L1_KeyValidate_Isr(HSM_L1_RtCtxType *pCtx);
#endif
#if ((FC7XXX_HSM_SUBSYSTEM_TYPE == FC7240_HSM_SUBSYSTEM) || (FC7XXX_HSM_SUBSYSTEM_TYPE == FC7300_HSM_SUBSYSTEM))
#else
    HSM_StatusType HSM_L1_UpdateKeyIdContentSetupEnv(HSM_L1_RtCtxType *pCtx);
    HSM_StatusType HSM_L1_UpdateKeyIdContent(HSM_L1_RtCtxType *pCtx, const HSM_Ln_KeyManagerUpdateUserKeyType *pCfg, hsm_uint32_t u32TimeoutMs);
    HSM_StatusType HSM_L1_UpdateKeyIdContentPoll(HSM_L1_RtCtxType *pCtx);
    HSM_StatusType HSM_L1_UpdateKeyIdContentReset(HSM_L1_RtCtxType *pCtx);
    HSM_StatusType HSM_L1_UpdateKeyIdContentExitEnv(HSM_L1_RtCtxType *pCtx);
    HSM_StatusType HSM_L1_UpdateKeyIdContent_Isr(HSM_L1_RtCtxType *pCtx);
#endif
HSM_StatusType HSM_L1_KeyCopySetupEnv(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_KeyCopy(HSM_L1_RtCtxType *pCtx, const HSM_Ln_CopyUserKeyType *pCfg, hsm_uint32_t u32TimeoutMs);
HSM_StatusType HSM_L1_KeyCopyPoll(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_KeyCopyReset(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_KeyCopyExitEnv(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_KeyCopy_Isr(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_KeyRevokeSetupEnv(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_KeyRevoke(HSM_L1_RtCtxType *pCtx, hsm_uint32_t u32KeyId, hsm_uint32_t u32TimeoutMs);
HSM_StatusType HSM_L1_KeyRevokePoll(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_KeyRevokeReset(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_KeyRevokeExitEnv(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_KeyRevoke_Isr(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_KeySpaceTidyUpSetupEnv(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_KeySpaceTidyUp(HSM_L1_RtCtxType *pCtx, HSM_Ln_KeySpaceStatusType *pCfg, hsm_uint32_t u32TimeoutMs);
HSM_StatusType HSM_L1_KeySpaceTidyUpPoll(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_KeySpaceTidyUpReset(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_KeySpaceTidyUpExitEnv(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_KeySpaceTidyup_Isr(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_KeySpaceGetStatusSetupEnv(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_KeySpaceGetStatus(HSM_L1_RtCtxType *pCtx, HSM_Ln_KeySpaceStatusType *pCfg, hsm_uint32_t u32TimeoutMs);
HSM_StatusType HSM_L1_KeySpaceGetStatusPoll(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_KeySpaceGetStatusReset(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_KeySpaceGetStatusExitEnv(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_KeySpaceGetStatus_Isr(HSM_L1_RtCtxType *pCtx);
#if ((FC7XXX_HSM_SUBSYSTEM_TYPE == FC7240_HSM_SUBSYSTEM) || (FC7XXX_HSM_SUBSYSTEM_TYPE == FC7300_HSM_SUBSYSTEM))
    HSM_StatusType HSM_L1_GetKeyIdStatusSetupEnv(HSM_L1_RtCtxType *pCtx);
    HSM_StatusType HSM_L1_GetKeyIdStatus(HSM_L1_RtCtxType *pCtx, hsm_uint32_t u32KeyId, hsm_uint32_t u32TimeoutMs);
    HSM_StatusType HSM_L1_GetKeyIdStatusPoll(HSM_L1_RtCtxType *pCtx);
    HSM_StatusType HSM_L1_GetKeyIdStatusReset(HSM_L1_RtCtxType *pCtx);
    HSM_StatusType HSM_L1_GetKeyIdStatusExitEnv(HSM_L1_RtCtxType *pCtx);
    HSM_StatusType HSM_L1_GetKeyIdStatus_Isr(HSM_L1_RtCtxType *pCtx);
#endif
HSM_StatusType HSM_L1_LoadFirmwareSetupEnv(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_LoadFirmware(HSM_L1_RtCtxType *pCtx, uint32 u32TimeoutMs);
HSM_StatusType HSM_L1_LoadFirmwarePoll(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_LoadFirmwareReset(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_LoadFirmwareExitEnv(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_LoadFirmware_Isr(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_RsaSsaPkcs1V15SignSetupEnv(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_RsaSsaPkcs1V15SignHash(HSM_L1_RtCtxType *pCtx, const HSM_Ln_RsaSsaPkcs1V15SignHashType *pCfg, hsm_uint32_t u32TimeoutMs);
HSM_StatusType HSM_L1_RsaSsaPkcs1V15SignData(HSM_L1_RtCtxType *pCtx, const HSM_Ln_RsaSsaPkcs1V15SignDataType *pCfg, hsm_uint32_t u32TimeoutMs);
HSM_StatusType HSM_L1_RsaSsaPkcs1V15SignPoll(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_RsaSsaPkcs1V15SignReset(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_RsaSsaPkcs1V15SignExitEnv(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_RsaSsaPkcs1V15Sign_Isr(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_RsaSsaPssSignSetupEnv(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_RsaSsaPssSignData(HSM_L1_RtCtxType *pCtx, const HSM_Ln_RsaSsaPssSignDataType *pCfg, hsm_uint32_t u32TimeoutMs);
HSM_StatusType HSM_L1_RsaSsaPssSignHash(HSM_L1_RtCtxType *pCtx, const HSM_Ln_RsaSsaPssSignHashType *pCfg, hsm_uint32_t u32TimeoutMs);
HSM_StatusType HSM_L1_RsaSsaPssSignPoll(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_RsaSsaPssSignReset(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_RsaSsaPssSignExitEnv(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_RsaSsaPssSign_Isr(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_Sm2GenZaSetupEnv(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_Sm2GenZaExitEnv(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_Sm2GenZa(HSM_L1_RtCtxType *pCtx, const HSM_LN_Sm2GenZaType *pCfg, hsm_uint32_t u32TimeoutMs);
HSM_StatusType HSM_L1_Sm2GenZa_Isr(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_Sm2GenZaPoll(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_Sm2GenZaReset(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_Sm2VerifySetupEnv(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_Sm2VerifyExitEnv(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_Sm2Verify(HSM_L1_RtCtxType *pCtx, const HSM_L1_Sm2VerifyType *pCfg, hsm_uint32_t u32TimeoutMs);
HSM_StatusType HSM_L1_Sm2Verify_Isr(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_Sm2VerifyPoll(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_Sm2VerifyReset(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_PKCS1_GetRsaPrivateKeyInfFromDer(const hsm_uint8_t *pDer, HSM_L1_PKCS_RsaPrivateKeyInfType *pInf);
HSM_StatusType HSM_L1_PKCS1_GetEccPrivateKeyInfFromDer(const hsm_uint8_t *pDer, HSM_L1_PKCS_EccPrivateKeyInfType *pInf);
HSM_StatusType HSM_L1_PKCS8_GetPrivateKeyInfFromDer(const hsm_uint8_t *pDer, HSM_L1_PKCS8_PrivateKeyInfType *pInf);
HSM_StatusType HSM_L1_PKCS1_GetRsaPublicKeyInfFromDer(const hsm_uint8_t *pDer, HSM_L1_PKCS_RsaPublicKeyInfType *pInf);
HSM_StatusType hsm_l1_subjectpublicinfo_bitstring_geteccpublickeyinf(const hsm_uint8_t *pDer, HSM_L1_PKCS_EccPublicKeyInfType *pInf);
HSM_StatusType HSM_L1_SubjectPublicInfo_GetPublicKeyInfFromDer(const hsm_uint8_t *pDer, HSM_L1_PublicKeyInfType *pInf);
HSM_StatusType HSM_L1_GetPoll(HSM_L1_RtCtxType *pCtx);
void HSM_L1_Ack_IrqHandler(void *pUpperCtx, HSM_StatusType eRet);

/****************************************** Local function declarations ***********************************************/
HSM_StatusType hsm_l2_cmac_empty_process(HSM_L2_RtCtxType *pL2Ctx, HSM_L1_RtCtxType *pL1Ctx, hsm_uint32_t u32TimeoutMs, HSM_L2_DrvCMacEmptyInfType *pCfg,
                                         HSM_StatusType eRetFromPrevious, HSM_TriggerSrcType bTriggerMode);
HSM_StatusType hsm_l2_revoke_key_process(HSM_L2_RtCtxType *pL2Ctx, HSM_L1_RtCtxType *pL1Ctx, hsm_uint32_t u32TimeoutMs, HSM_L2_DrvRevokeKeyInfType *pCfg,
                                         HSM_StatusType eRetFromPrevious, HSM_TriggerSrcType bTriggerMode);
HSM_StatusType hsm_l2_ecc_verify_process(HSM_L2_RtCtxType *pL2Ctx, HSM_L1_RtCtxType *pL1Ctx, hsm_uint32_t u32TimeoutMs, HSM_L2_DrvEccVerifyInfType *pCfg,
                                         HSM_StatusType eRetFromPrevious, HSM_TriggerSrcType bTriggerMode);
HSM_StatusType hsm_l2_sm2_verify_process(HSM_L2_RtCtxType *pL2Ctx, HSM_L1_RtCtxType *pL1Ctx, hsm_uint32_t u32TimeoutMs, HSM_L2_DrvSm2VerifyInfType *pCfg, HSM_StatusType eRetFromPrevious, HSM_TriggerSrcType bTriggerMode);

HSM_StatusType HSM_L2_CMacEmptySetupEnv(HSM_L2_RtCtxType *pL2Ctx, HSM_L1_RtCtxType *pL1Ctx);
HSM_StatusType HSM_L2_CMacEmptyReset(HSM_L2_RtCtxType *pL2Ctx, HSM_L1_RtCtxType *pL1Ctx);
HSM_StatusType HSM_L2_CMacEmptyExitEnv(HSM_L2_RtCtxType *pL2Ctx, HSM_L1_RtCtxType *pL1Ctx);
HSM_StatusType hsm_l2_cmac_empty_process(HSM_L2_RtCtxType *pL2Ctx, HSM_L1_RtCtxType *pL1Ctx, hsm_uint32_t u32TimeoutMs,
                                         HSM_L2_DrvCMacEmptyInfType *pCfg, HSM_StatusType eRetFromPrevious, HSM_TriggerSrcType bTriggerMode);
HSM_StatusType HSM_L2_CMacEmpty(HSM_L2_RtCtxType *pL2Ctx, HSM_L1_RtCtxType *pL1Ctx, const HSM_Ln_CMacCfgParmsType *pKeyCfg, const HSM_Ln_ResultBufInfoType *pResult,
                                hsm_uint32_t u32TimeoutMs);
HSM_StatusType HSM_L2_CMacEmptyPoll(HSM_L2_RtCtxType *pL2Ctx, HSM_L1_RtCtxType *pL1Ctx, hsm_uint32_t u32TimeoutMs);
#if (FC7XXX_HSM_SUBSYSTEM_TYPE == FC7240_HSM_SUBSYSTEM) || (FC7XXX_HSM_SUBSYSTEM_TYPE == FC7300_HSM_SUBSYSTEM)
static HSM_StatusType hsm_update_key_get_id_status(HSM_L1_RtCtxType *pL1Ctx, HSM_L2_DrvUpdateKeyInfType *pCfg, hsm_uint32_t u32TimeoutMs);
static HSM_StatusType hsm_update_key_revoke(HSM_L1_RtCtxType *pL1Ctx, HSM_L2_DrvUpdateKeyInfType *pCfg, hsm_uint32_t u32TimeoutMs);
HSM_StatusType hsm_l2_update_key_process(HSM_L2_RtCtxType *pL2Ctx, HSM_L1_RtCtxType *pL1Ctx, hsm_uint32_t u32TimeoutMs,
                                         HSM_L2_DrvUpdateKeyInfType *pCfg, HSM_StatusType eRetFromPrevious, HSM_TriggerSrcType bTriggerMode);
#else
static HSM_StatusType hsm_update_key_content(HSM_L1_RtCtxType *pL1Ctx, HSM_L2_DrvUpdateKeyInfType *pCfg, hsm_uint32_t u32TimeoutMs);
static HSM_StatusType hsm_update_or_import(HSM_L1_RtCtxType *pL1Ctx, HSM_L2_DrvUpdateKeyInfType *pCfg, hsm_uint32_t u32TimeoutMs);
HSM_StatusType hsm_l2_update_key_process(HSM_L2_RtCtxType *pL2Ctx, HSM_L1_RtCtxType *pL1Ctx, hsm_uint32_t u32TimeoutMs,
                                         HSM_L2_DrvUpdateKeyInfType *pCfg, HSM_StatusType eRetFromPrevious, HSM_TriggerSrcType bTriggerMode);
#endif
HSM_StatusType HSM_L2_UpdateKeySetupEnv(HSM_L2_RtCtxType *pL2Ctx, HSM_L1_RtCtxType *pL1Ctx);
HSM_StatusType HSM_L2_UpdateKeyReset(HSM_L2_RtCtxType *pL2Ctx, HSM_L1_RtCtxType *pL1Ctx);
HSM_StatusType HSM_L2_UpdateKey(HSM_L2_RtCtxType *pL2Ctx, HSM_L1_RtCtxType *pL1Ctx, const HSM_Ln_ImportUserKeyExtType *pKeyCfg, hsm_uint32_t u32TimeoutMs);
HSM_StatusType HSM_L2_UpdateKeyPoll(HSM_L2_RtCtxType *pL2Ctx, HSM_L1_RtCtxType *pL1Ctx, hsm_uint32_t u32TimeoutMs);
HSM_StatusType HSM_L2_UpdateKeyExitEnv(HSM_L2_RtCtxType *pL2Ctx, HSM_L1_RtCtxType *pL1Ctx);
HSM_StatusType HSM_L2_RevokeKeySetupEnv(HSM_L2_RtCtxType *pL2Ctx, HSM_L1_RtCtxType *pL1Ctx);
HSM_StatusType HSM_L2_RevokeKeyReset(HSM_L2_RtCtxType *pL2Ctx, HSM_L1_RtCtxType *pL1Ctx);
HSM_StatusType HSM_L2_RevokeKey(HSM_L2_RtCtxType *pL2Ctx, HSM_L1_RtCtxType *pL1Ctx, hsm_uint32_t u32KeyId, hsm_uint32_t u32TimeoutMs);
HSM_StatusType HSM_L2_RevokeKeyPoll(HSM_L2_RtCtxType *pL2Ctx, HSM_L1_RtCtxType *pL1Ctx, hsm_uint32_t u32TimeoutMs);
HSM_StatusType HSM_L2_RevokeKeyExitEnv(HSM_L2_RtCtxType *pL2Ctx, HSM_L1_RtCtxType *pL1Ctx);
HSM_StatusType hsm_l2_ecc_verify_process(HSM_L2_RtCtxType *pL2Ctx, HSM_L1_RtCtxType *pL1Ctx, hsm_uint32_t u32TimeoutMs,
                                         HSM_L2_DrvEccVerifyInfType *pCfg, HSM_StatusType eRetFromPrevious, HSM_TriggerSrcType bTriggerMode);
HSM_StatusType HSM_L2_EccVerifySetupEnv(HSM_L2_RtCtxType *pL2Ctx, HSM_L1_RtCtxType *pL1Ctx, hsm_uint32_t u32BitCnt);
HSM_StatusType HSM_L2_EccVerifyReset(HSM_L2_RtCtxType *pL2Ctx, HSM_L1_RtCtxType *pL1Ctx);
HSM_StatusType HSM_L2_EccVerify(HSM_L2_RtCtxType *pL2Ctx, HSM_L1_RtCtxType *pL1Ctx, const HSM_Ln_EccVerifyType *pCfg, hsm_uint32_t u32TimeoutMs);
HSM_StatusType HSM_L2_EccVerifyPoll(HSM_L2_RtCtxType *pL2Ctx, HSM_L1_RtCtxType *pL1Ctx, hsm_uint32_t u32TimeoutMs);
HSM_StatusType HSM_L2_EccVerifyExitEnv(HSM_L2_RtCtxType *pL2Ctx, HSM_L1_RtCtxType *pL1Ctx);

HSM_StatusType HSM_L2_Sm2VerifySetupEnv(HSM_L2_RtCtxType *pL2Ctx, HSM_L1_RtCtxType *pL1Ctx);
HSM_StatusType HSM_L2_Sm2VerifyReset(HSM_L2_RtCtxType *pL2Ctx, HSM_L1_RtCtxType *pL1Ctx);
HSM_StatusType HSM_L2_Sm2Verify(HSM_L2_RtCtxType *pL2Ctx, HSM_L1_RtCtxType *pL1Ctx, const HSM_Ln_Sm2VerifyType *pCfg, hsm_uint32_t u32TimeoutMs);
HSM_StatusType HSM_L2_Sm2VerifyPoll(HSM_L2_RtCtxType *pL2Ctx, HSM_L1_RtCtxType *pL1Ctx, hsm_uint32_t u32TimeoutMs);
HSM_StatusType HSM_L2_Sm2VerifyExitEnv(HSM_L2_RtCtxType *pL2Ctx, HSM_L1_RtCtxType *pL1Ctx);

void HSM_L2_Ack_IrqHandler(void *pUpperCtx, HSM_BoolType bIsErrorHappen, HSM_StatusType eRet);
void HSM_L2_Init(HSM_L2_RtCtxType *pCtx, HSM_L2_InitParmType *pParm);
void HSM_L2_CleanEnv(HSM_L2_RtCtxType *pCtx);
void HSM_L2_Abort(HSM_L2_RtCtxType *pCtx);
void HSM_L2_CommonExitEnv(HSM_L2_RtCtxType *pCtx);
HSM_StatusType HSM_L2_GetPoll(HSM_L2_RtCtxType *pL2Ctx, HSM_L1_RtCtxType *pL1Ctx, hsm_uint32_t u32TimeoutMs);
HSM_StatusType hsm_l2_revoke_key_process(HSM_L2_RtCtxType *pL2Ctx, HSM_L1_RtCtxType *pL1Ctx, hsm_uint32_t u32TimeoutMs,
                                         HSM_L2_DrvRevokeKeyInfType *pCfg, HSM_StatusType eRetFromPrevious, HSM_TriggerSrcType bTriggerMode);

#if (FC7XXX_HSM_SUBSYSTEM_TYPE == FC7240_HSM_SUBSYSTEM) || (FC7XXX_HSM_SUBSYSTEM_TYPE == FC7300_HSM_SUBSYSTEM)
    static HSM_StatusType hsm_revoke_key_validate(HSM_L1_RtCtxType *pL1Ctx, HSM_L2_DrvRevokeKeyInfType *pCfg, hsm_uint32_t u32TimeoutMs);
#endif
static HSM_StatusType hsm_cmac_empty_encrypt(HSM_L1_RtCtxType *pL1Ctx, HSM_L2_DrvCMacEmptyInfType *pCfg, hsm_uint32_t u32TimeoutMs);
static HSM_StatusType hsm_update_key_import(HSM_L1_RtCtxType *pL1Ctx, HSM_L2_DrvUpdateKeyInfType *pCfg, hsm_uint32_t u32TimeoutMs);
static HSM_StatusType hsm_update_key_tidy(HSM_L1_RtCtxType *pL1Ctx, HSM_L2_DrvUpdateKeyInfType *pCfg, hsm_uint32_t u32TimeoutMs);
#if (FC7XXX_HSM_SUBSYSTEM_TYPE == FC7240_HSM_SUBSYSTEM) || (FC7XXX_HSM_SUBSYSTEM_TYPE == FC7300_HSM_SUBSYSTEM)
static HSM_StatusType hsm_update_key_get_status(HSM_L1_RtCtxType *pL1Ctx, HSM_L2_DrvUpdateKeyInfType *pCfg, hsm_uint32_t u32TimeoutMs);
#endif
static HSM_StatusType hsm_revoke_key_revoke(HSM_L1_RtCtxType *pL1Ctx, HSM_L2_DrvRevokeKeyInfType *pCfg, hsm_uint32_t u32TimeoutMs);

/********************************************* Global function *********************************************************/
HSM_StatusType HSM_L2_CMacEmptySetupEnv(HSM_L2_RtCtxType *pL2Ctx, HSM_L1_RtCtxType *pL1Ctx)
{
    HSM_StatusType eRet = HSM_STATUS_SUCCESS;

    (void)pL1Ctx;

    if (HSM_LEVEL_2ND_OP_NONE == pL2Ctx->eOperation)
    {
        pL2Ctx->eOperation        = HSM_LEVEL_2ND_OP_CMAC_EMPTY;
        pL2Ctx->tL2AlgCtx.tCMacEmpty.eStat  = HSM_L2_CMAC_EMPTY_SM_READY;
    }
    else
    {
        eRet = HSM_STATUS_BUSY;
    }

    return eRet;
}



HSM_StatusType HSM_L2_CMacEmptyReset(HSM_L2_RtCtxType *pL2Ctx, HSM_L1_RtCtxType *pL1Ctx)
{
    HSM_StatusType eRet = HSM_STATUS_SUCCESS;

    if (HSM_LEVEL_2ND_OP_CMAC_EMPTY == pL2Ctx->eOperation)
    {
        eRet = HSM_L1_Abort(pL1Ctx);
        pL2Ctx->tL2AlgCtx.tCMacEmpty.eStat  = HSM_L2_CMAC_EMPTY_SM_READY;
    }
    else
    {
        eRet = HSM_STATUS_ERROR;
    }
    return eRet;
}


HSM_StatusType HSM_L2_CMacEmptyExitEnv(HSM_L2_RtCtxType *pL2Ctx, HSM_L1_RtCtxType *pL1Ctx)
{
    HSM_StatusType eRet = HSM_STATUS_SUCCESS;

    if (HSM_LEVEL_2ND_OP_CMAC_EMPTY == pL2Ctx->eOperation)
    {
        eRet = HSM_L1_Abort(pL1Ctx);
        pL2Ctx->eOperation = HSM_LEVEL_2ND_OP_NONE;
    }
    else
    {
        eRet = HSM_STATUS_ERROR;
    }

    return eRet;
}

static HSM_StatusType hsm_cmac_empty_encrypt(HSM_L1_RtCtxType *pL1Ctx, HSM_L2_DrvCMacEmptyInfType *pCfg, hsm_uint32_t u32TimeoutMs)
{
    HSM_StatusType eRet = HSM_STATUS_SUCCESS;

    if (HSM_AESM_BACKEND_AES == pCfg->eBackend)
    {
        eRet = HSM_L1_AesEncryptSetupEnv(pL1Ctx);
        if (HSM_STATUS_SUCCESS == eRet)
        {
            eRet = HSM_L1_AesEncrypt(pL1Ctx, &(pCfg->tParm), u32TimeoutMs);

            if (HSM_STATUS_SUCCESS == eRet)
            {
                ;
            }
            else
            {
                HSM_L1_AesEncryptExitEnv(pL1Ctx);
                pCfg->eStat = HSM_L2_CMAC_EMPTY_SM_STOP;
            }
        }
        else
        {
            pCfg->eStat = HSM_L2_CMAC_EMPTY_SM_STOP;
        }
    }
    else
    {
        eRet = HSM_L1_Sm4EncryptSetupEnv(pL1Ctx);
        if (HSM_STATUS_SUCCESS == eRet)
        {
            eRet = HSM_L1_Sm4Encrypt(pL1Ctx, &(pCfg->tParm), u32TimeoutMs);

            if (HSM_STATUS_SUCCESS == eRet)
            {
                ;
            }
            else
            {
                HSM_L1_Sm4EncryptExitEnv(pL1Ctx);
                pCfg->eStat = HSM_L2_CMAC_EMPTY_SM_STOP;
            }
        }
        else
        {
            pCfg->eStat = HSM_L2_CMAC_EMPTY_SM_STOP;
        }
    }

    return eRet;
}

HSM_StatusType hsm_l2_cmac_empty_process(HSM_L2_RtCtxType *pL2Ctx, HSM_L1_RtCtxType *pL1Ctx, hsm_uint32_t u32TimeoutMs,
                                         HSM_L2_DrvCMacEmptyInfType *pCfg, HSM_StatusType eRetFromPrevious, HSM_TriggerSrcType bTriggerMode)
{
    HSM_StatusType  eRet = eRetFromPrevious;
    HSM_StatusType  eTempRetFromPrevious = eRetFromPrevious;
    hsm_uint32_t    u32Temp;

    switch (pCfg->eStat)
    {
        case HSM_L2_CMAC_EMPTY_SM_READY:
        {
            hsm_memset(&(pL2Ctx->tL2AlgCtx.tCMacEmpty.aInputCacheBuf[0]), 0, sizeof(pL2Ctx->tL2AlgCtx.tCMacEmpty.aInputCacheBuf));
            hsm_memset(&(pL2Ctx->tL2AlgCtx.tCMacEmpty.aIvData[0]), 0, sizeof(pL2Ctx->tL2AlgCtx.tCMacEmpty.aIvData));

            pCfg->eStat = HSM_L2_CMAC_EMPTY_SM_GENERATE_L;

            eRet = hsm_cmac_empty_encrypt(pL1Ctx, pCfg, u32TimeoutMs);
            if (HSM_STATUS_SUCCESS == eRet)
            {
                eRet = HSM_STATUS_AGAIN;
            }
            /* else do nothing */
        }
        break;

        case HSM_L2_CMAC_EMPTY_SM_GENERATE_L:
        {
            if (HSM_TRIGGER_SRC_ISR == bTriggerMode)
            {
                HSM_L1_CommonExitEnv(pL1Ctx);
            }
            else
            {
                eTempRetFromPrevious = HSM_L1_AesEncryptPoll(pL1Ctx);
                if (HSM_STATUS_AGAIN != eTempRetFromPrevious)
                {
                    HSM_L1_CommonExitEnv(pL1Ctx);
                }
                /* else do nothing */
            }

            if (HSM_STATUS_SUCCESS == eTempRetFromPrevious)
            {
                /* generate K1 */
                hsm_uint32_t u32Idx;
                hsm_uint8_t  u8Data, u8Data2, u8Data3;
                hsm_uint8_t *pData = (hsm_uint8_t *) & (pCfg->aResultCacheBuf[0]);

                u8Data = pData[0];
                u8Data3 = pData[0];

                for (u32Idx = 0u; u32Idx < 15; ++u32Idx)
                {
                    u8Data2 = pData[u32Idx + 1];
                    u8Data = ((hsm_uint8_t)(u8Data << 1)) | ((hsm_uint8_t)(u8Data2 >> 7));
                    pData[u32Idx] = u8Data;
                    u8Data = u8Data2;
                }

                u8Data = (hsm_uint8_t)(u8Data << 1);
                pData[15] = u8Data;


                if (0u != (u8Data3 & 0x80u))
                {
                    pData[15] = pData[15] ^ 0x87;
                }

                /* generate K2 */
                u8Data = pData[0];
                u8Data3 = pData[0];

                for (u32Idx = 0u; u32Idx < 15; ++u32Idx)
                {
                    u8Data2 = pData[u32Idx + 1];
                    u8Data = ((hsm_uint8_t)(u8Data << 1)) | ((hsm_uint8_t)(u8Data2 >> 7));
                    pData[u32Idx] = u8Data;
                    u8Data = u8Data2;
                }

                u8Data = (hsm_uint8_t)(u8Data << 1);
                pData[15] = u8Data;


                if (0u != (u8Data3 & 0x80u))
                {
                    pData[15] = pData[15] ^ 0x87;
                }

                /* generate msg */
                pData[0] = pData[0] ^ 0x80;


                hsm_memcpy(&(pCfg->aInputCacheBuf[0]), &(pCfg->aResultCacheBuf[0]), 16);
                hsm_memset(&(pCfg->aResultCacheBuf[0]), 0, 16);

                pCfg->eStat = HSM_L2_CMAC_EMPTY_SM_GENERATE_T;

                eRet = hsm_cmac_empty_encrypt(pL1Ctx, pCfg, u32TimeoutMs);
                if (HSM_STATUS_SUCCESS == eRet)
                {
                    eRet = HSM_STATUS_AGAIN;
                }
                /* else do nothing */

            }
            else if ((HSM_TRIGGER_SRC_ISR != bTriggerMode) && (HSM_STATUS_AGAIN == eTempRetFromPrevious))
            {
                eRet = HSM_STATUS_AGAIN;
            }
            else
            {
                eRet = HSM_STATUS_ERROR;
                pCfg->eStat = HSM_L2_CMAC_EMPTY_SM_STOP;
            }
        }
        break;

        case HSM_L2_CMAC_EMPTY_SM_GENERATE_T:
        {
            if (HSM_TRIGGER_SRC_ISR == bTriggerMode)
            {
                HSM_L1_CommonExitEnv(pL1Ctx);
            }
            else
            {
                eTempRetFromPrevious = HSM_L1_AesEncryptPoll(pL1Ctx);
                if (HSM_STATUS_AGAIN != eTempRetFromPrevious)
                {
                    HSM_L1_CommonExitEnv(pL1Ctx);
                }
                /* else do nothing */
            }

            if (HSM_STATUS_SUCCESS == eTempRetFromPrevious)
            {
                eRet = HSM_STATUS_SUCCESS;
                pCfg->eStat = HSM_L2_CMAC_EMPTY_SM_STOP;

                if ((pCfg->pOut != NULL_PTR))
                {
                    u32Temp = 16u;

                    if (HSM_DATA_FORMAT_4B == pCfg->eOutFmt)
                    {
                        hsm_u32_array_swap((hsm_uint32_t *) & (pCfg->aResultCacheBuf[0]), u32Temp / 4U); /* all result data size is 4*N */
                    }
                    else
                    {
                    }

                    if (pCfg->u32OutBufSize <= u32Temp)
                    {
                        u32Temp = pCfg->u32OutBufSize;
                    }
                    /* else do nothing */

                    hsm_memcpy(pCfg->pOut, &(pCfg->aResultCacheBuf[0]), u32Temp);

                    if (NULL_PTR != pCfg->pOutSize)
                    {
                        hsm_memcpy(pCfg->pOutSize, &u32Temp, sizeof(u32Temp));
                    }
                    else
                    {
                        ;
                    }

                }
                /* else do nothing */
            }
            else if ((HSM_TRIGGER_SRC_ISR != bTriggerMode) && (HSM_STATUS_AGAIN == eTempRetFromPrevious))
            {
                eRet = HSM_STATUS_AGAIN;
            }
            else
            {
                eRet = HSM_STATUS_ERROR;
                pCfg->eStat = HSM_L2_CMAC_EMPTY_SM_STOP;
            }
        }
        break;

        case HSM_L2_CMAC_EMPTY_SM_STOP:
        {
            eRet = HSM_STATUS_ERROR;
        }
        break;


        default:
        {
            eRet = HSM_STATUS_ERROR;
        }
        break;
    }

    return eRet;
}


HSM_StatusType HSM_L2_CMacEmpty(HSM_L2_RtCtxType *pL2Ctx, HSM_L1_RtCtxType *pL1Ctx, const HSM_Ln_CMacCfgParmsType *pKeyCfg, const HSM_Ln_ResultBufInfoType *pResult,
                                hsm_uint32_t u32TimeoutMs)
{
    HSM_StatusType eRet = HSM_STATUS_SUCCESS;

    if (HSM_LEVEL_2ND_OP_CMAC_EMPTY == pL2Ctx->eOperation)
    {
        if (pL2Ctx->tL2AlgCtx.tCMacEmpty.eStat  == HSM_L2_CMAC_EMPTY_SM_READY)
        {
            pL2Ctx->tL2AlgCtx.tCMacEmpty.pOut                 = pResult->pData;
            pL2Ctx->tL2AlgCtx.tCMacEmpty.u32OutBufSize        = pResult->u32DataBufSize;
            pL2Ctx->tL2AlgCtx.tCMacEmpty.eOutFmt              = pResult->eDataFmt;
            pL2Ctx->tL2AlgCtx.tCMacEmpty.pOutSize             = pResult->pDataSize;

            pL2Ctx->tL2AlgCtx.tCMacEmpty.eBackend                     = pKeyCfg->eBackend;
            pL2Ctx->tL2AlgCtx.tCMacEmpty.tParm.u32KeyId               = pKeyCfg->u32KeyId;
            pL2Ctx->tL2AlgCtx.tCMacEmpty.tParm.eUseKeyType            = pKeyCfg->eUseKeyType;
            pL2Ctx->tL2AlgCtx.tCMacEmpty.tParm.tNewKeyInf.eKeyType    = pKeyCfg->eKeyType;
            pL2Ctx->tL2AlgCtx.tCMacEmpty.tParm.tNewKeyInf.pKeyAddr    = (const hsm_uint8_t *) & (pL2Ctx->tL2AlgCtx.tCMacEmpty.aKeyData[0]); /* pKeyCfg->pKeyAddr; */
            pL2Ctx->tL2AlgCtx.tCMacEmpty.tParm.tVendorKeyInf.eKeyType = pKeyCfg->eKeyType;
            pL2Ctx->tL2AlgCtx.tCMacEmpty.tParm.eAesAlg                = HSM_SYMM_ENDECRYPT_MODE_CBC;
            pL2Ctx->tL2AlgCtx.tCMacEmpty.tParm.pDataInput             = (const hsm_uint8_t *) & (pL2Ctx->tL2AlgCtx.tCMacEmpty.aInputCacheBuf[0]);
            pL2Ctx->tL2AlgCtx.tCMacEmpty.tParm.u32InputByteCnt        = 0x10;
            pL2Ctx->tL2AlgCtx.tCMacEmpty.tParm.pDataOutput            = (hsm_uint8_t *) & (pL2Ctx->tL2AlgCtx.tCMacEmpty.aResultCacheBuf[0]);
            pL2Ctx->tL2AlgCtx.tCMacEmpty.tParm.u32OutputMemSize       = sizeof(pL2Ctx->tL2AlgCtx.tCMacEmpty.aResultCacheBuf);
            pL2Ctx->tL2AlgCtx.tCMacEmpty.tParm.pIvData                = (const hsm_uint8_t *) & (pL2Ctx->tL2AlgCtx.tCMacEmpty.aIvData[0]);
            pL2Ctx->tL2AlgCtx.tCMacEmpty.tParm.ePad                   = HSM_FLEXAES_PAD_ZERO;
            pL2Ctx->tL2AlgCtx.tCMacEmpty.tParm.eInputFmt              = HSM_DATA_FORMAT_1B;
            pL2Ctx->tL2AlgCtx.tCMacEmpty.tParm.eOutputFmt             = HSM_DATA_FORMAT_1B;
            pL2Ctx->tL2AlgCtx.tCMacEmpty.tParm.pGenerateOutByteCnt    = NULL_PTR;

            if ((HSM_AES_KEY_NEW == pKeyCfg->eUseKeyType) && (0 == pKeyCfg->u32KeyId))
            {
                eRet = hsm_1B4B_convert_from_idx(HSM_DATA_FORMAT_1B, &(pL2Ctx->tL2AlgCtx.tCMacEmpty.aKeyData[0]), 0, sizeof(pL2Ctx->tL2AlgCtx.tCMacEmpty.aKeyData),
                                                 pKeyCfg->eKeyDataFmt, pKeyCfg->pKeyAddr, 0, (pKeyCfg->eKeyType * 8) + 16);
            }

            if (HSM_STATUS_SUCCESS == eRet)
            {
                eRet = hsm_l2_cmac_empty_process(pL2Ctx, pL1Ctx, u32TimeoutMs,
                                                 &(pL2Ctx->tL2AlgCtx.tCMacEmpty), HSM_STATUS_SUCCESS, pL1Ctx->eTriggerSrc);
                if (HSM_STATUS_AGAIN == eRet)
                {
                    eRet = HSM_STATUS_SUCCESS;
                }
                else
                {
                    ;
                }
            }
        }
        else
        {
            eRet = HSM_STATUS_LOGIC_ERR;
        }
    }
    else
    {
        eRet = HSM_STATUS_BUSY;
    }


    return eRet;
}




HSM_StatusType HSM_L2_CMacEmptyPoll(HSM_L2_RtCtxType *pL2Ctx, HSM_L1_RtCtxType *pL1Ctx, hsm_uint32_t u32TimeoutMs)
{
    HSM_StatusType eRet;

    if (HSM_LEVEL_2ND_OP_CMAC_EMPTY == pL2Ctx->eOperation)
    {
        eRet = hsm_l2_cmac_empty_process(pL2Ctx, pL1Ctx, u32TimeoutMs, &pL2Ctx->tL2AlgCtx.tCMacEmpty, HSM_STATUS_SUCCESS, pL1Ctx->eTriggerSrc);
    }
    else
    {
        eRet = HSM_STATUS_ERROR;
    }


    return eRet;
}


/* --------------------------------------------------------------------------- */
/* --------------------------------------------------------------------------- */
#if (FC7XXX_HSM_SUBSYSTEM_TYPE == FC7240_HSM_SUBSYSTEM) || (FC7XXX_HSM_SUBSYSTEM_TYPE == FC7300_HSM_SUBSYSTEM)
static HSM_StatusType hsm_update_key_loadfirmware(HSM_L1_RtCtxType *pL1Ctx, HSM_L2_DrvUpdateKeyInfType *pCfg, uint32 u32TimeoutMs)
{
    HSM_StatusType eRet;
    eRet = HSM_L1_LoadFirmwareSetupEnv(pL1Ctx);
    if (HSM_STATUS_SUCCESS == eRet)
    {
        eRet = HSM_L1_LoadFirmware(pL1Ctx, u32TimeoutMs);
        if (HSM_STATUS_SUCCESS == eRet)
        {
            ;
        }
        else
        {
            (void)HSM_L1_LoadFirmwareExitEnv(pL1Ctx);
            pCfg->eStat = HSM_L2_UPDATE_KEY_SM_STOP;
        }
    }
    else
    {
        pCfg->eStat = HSM_L2_UPDATE_KEY_SM_STOP;
    }
    return eRet;
}
#endif

static HSM_StatusType hsm_update_key_import(HSM_L1_RtCtxType *pL1Ctx, HSM_L2_DrvUpdateKeyInfType *pCfg, hsm_uint32_t u32TimeoutMs)
{
    HSM_StatusType eRet          = HSM_STATUS_SUCCESS;


    eRet = HSM_L1_KeyImportSetupEnv(pL1Ctx);
    if (HSM_STATUS_SUCCESS == eRet)
    {
        eRet = HSM_L1_KeyImport(pL1Ctx, &(pCfg->tImportCfg), u32TimeoutMs);

        if (HSM_STATUS_SUCCESS == eRet)
        {
            ;
        }
        else
        {
            HSM_L1_KeyImportExitEnv(pL1Ctx);
            pCfg->eStat = HSM_L2_UPDATE_KEY_SM_STOP;
        }
    }
    else
    {
        pCfg->eStat = HSM_L2_UPDATE_KEY_SM_STOP;
    }

    return eRet;
}

static HSM_StatusType hsm_update_key_tidy(HSM_L1_RtCtxType *pL1Ctx, HSM_L2_DrvUpdateKeyInfType *pCfg, hsm_uint32_t u32TimeoutMs)
{
    HSM_StatusType eRet;


    eRet = HSM_L1_KeySpaceTidyUpSetupEnv(pL1Ctx);
    if (HSM_STATUS_SUCCESS == eRet)
    {
        eRet = HSM_L1_KeySpaceTidyUp(pL1Ctx, &(pCfg->tKeySpaceStatus), u32TimeoutMs);

        if (HSM_STATUS_SUCCESS == eRet)
        {
            ;
        }
        else
        {
            HSM_L1_KeySpaceTidyUpExitEnv(pL1Ctx);
            pCfg->eStat = HSM_L2_UPDATE_KEY_SM_STOP;
        }
    }
    else
    {
        pCfg->eStat = HSM_L2_UPDATE_KEY_SM_STOP;
    }

    return eRet;
}

#if (FC7XXX_HSM_SUBSYSTEM_TYPE == FC7240_HSM_SUBSYSTEM) || (FC7XXX_HSM_SUBSYSTEM_TYPE == FC7300_HSM_SUBSYSTEM)
static HSM_StatusType hsm_update_key_get_status(HSM_L1_RtCtxType *pL1Ctx, HSM_L2_DrvUpdateKeyInfType *pCfg, hsm_uint32_t u32TimeoutMs)
{
    HSM_StatusType eRet          = HSM_STATUS_SUCCESS;


    eRet = HSM_L1_KeySpaceGetStatusSetupEnv(pL1Ctx);
    if (HSM_STATUS_SUCCESS == eRet)
    {
        eRet = HSM_L1_KeySpaceGetStatus(pL1Ctx, &(pCfg->tKeySpaceStatus), u32TimeoutMs);

        if (HSM_STATUS_SUCCESS == eRet)
        {
            ;
        }
        else
        {
            HSM_L1_KeySpaceGetStatusExitEnv(pL1Ctx);
            pCfg->eStat = HSM_L2_UPDATE_KEY_SM_STOP;
        }
    }
    else
    {
        pCfg->eStat = HSM_L2_UPDATE_KEY_SM_STOP;
    }

    return eRet;
}

static HSM_StatusType hsm_update_key_get_id_status(HSM_L1_RtCtxType *pL1Ctx, HSM_L2_DrvUpdateKeyInfType *pCfg, hsm_uint32_t u32TimeoutMs)
{
    HSM_StatusType eRet;

    eRet = HSM_L1_GetKeyIdStatusSetupEnv(pL1Ctx);
    if (HSM_STATUS_SUCCESS == eRet)
    {
        eRet = HSM_L1_GetKeyIdStatus(pL1Ctx, pCfg->tImportCfg.u32KeyIdFix, u32TimeoutMs);

        if (HSM_STATUS_SUCCESS == eRet)
        {
            ;
        }
        else
        {
            HSM_L1_GetKeyIdStatusExitEnv(pL1Ctx);
            pCfg->eStat = HSM_L2_UPDATE_KEY_SM_STOP;
        }
    }
    else
    {
        pCfg->eStat = HSM_L2_UPDATE_KEY_SM_STOP;
    }

    return eRet;
}








static HSM_StatusType hsm_update_key_revoke(HSM_L1_RtCtxType *pL1Ctx, HSM_L2_DrvUpdateKeyInfType *pCfg, hsm_uint32_t u32TimeoutMs)
{
    HSM_StatusType eRet          = HSM_STATUS_SUCCESS;


    eRet = HSM_L1_KeyRevokeSetupEnv(pL1Ctx);
    if (HSM_STATUS_SUCCESS == eRet)
    {
        eRet = HSM_L1_KeyRevoke(pL1Ctx, pCfg->tImportCfg.u32KeyIdFix, u32TimeoutMs);

        if (HSM_STATUS_SUCCESS == eRet)
        {
            ;
        }
        else
        {
            HSM_L1_KeyRevokeExitEnv(pL1Ctx);
            pCfg->eStat = HSM_L2_UPDATE_KEY_SM_STOP;
        }
    }
    else
    {
        pCfg->eStat = HSM_L2_UPDATE_KEY_SM_STOP;
    }

    return eRet;
}




HSM_StatusType hsm_l2_update_key_process(HSM_L2_RtCtxType *pL2Ctx, HSM_L1_RtCtxType *pL1Ctx, hsm_uint32_t u32TimeoutMs,
                                         HSM_L2_DrvUpdateKeyInfType *pCfg, HSM_StatusType eRetFromPrevious, HSM_TriggerSrcType bTriggerMode)
{
    HSM_StatusType  eRet = eRetFromPrevious;

    (void)pL2Ctx;

    switch (pCfg->eStat)
    {
        case HSM_L2_UPDATE_KEY_SM_READY:
        {
            if (0u != (pCfg->tImportCfg.u32KeyIdFix))
            {
                pCfg->eStat = HSM_L2_UPDATE_KEY_SM_LOADFIRMWARE;


                eRet = hsm_update_key_loadfirmware(pL1Ctx, pCfg, u32TimeoutMs);
                if (HSM_STATUS_SUCCESS == eRet)
                {
                    eRet = HSM_STATUS_AGAIN;
                }
                /* else do nothing */
            }
            else
            {
                pCfg->eStat = HSM_L2_UPDATE_KEY_SM_IMPORT;

                if (KEYMANAGER_FALSE == pCfg->tImportCfg.bStoreInFlash) /* the ram key space always tidy up already */
                {
                    pCfg->bTidyUpAlready = HSM_TRUE;
                }

                eRet = hsm_update_key_import(pL1Ctx, pCfg, u32TimeoutMs);
                if (HSM_STATUS_SUCCESS == eRet)
                {
                    eRet = HSM_STATUS_AGAIN;
                }
                /* else do nothing */
            }
        }
        break;
        case HSM_L2_UPDATE_KEY_SM_LOADFIRMWARE:
        {
            if (HSM_TRIGGER_SRC_ISR == bTriggerMode)
            {
                HSM_L1_CommonExitEnv(pL1Ctx);
            }
            else
            {
                eRetFromPrevious = HSM_L1_LoadFirmwarePoll(pL1Ctx);
                if (HSM_STATUS_AGAIN != eRetFromPrevious)
                {
                    HSM_L1_CommonExitEnv(pL1Ctx);
                }
            }
            if (HSM_STATUS_SUCCESS == eRetFromPrevious)
            {
                if (0u != (pCfg->tImportCfg.u32KeyIdFix))
                {
                    pCfg->eStat = HSM_L2_UPDATE_KEY_SM_CHECK_EXIST;
                    if (0x1u == (pCfg->tImportCfg.u32KeyIdFix & 0x1)) /* the ram key space always tidy up already */
                    {
                        pCfg->bTidyUpAlready = HSM_TRUE;
                    }
                    eRet = hsm_update_key_get_id_status(pL1Ctx, pCfg, u32TimeoutMs);
                    if (HSM_STATUS_SUCCESS == eRet)
                    {
                        eRet = HSM_STATUS_AGAIN;
                    }
                }
                else
                {
                    pCfg->eStat = HSM_L2_UPDATE_KEY_SM_IMPORT;
                    if (KEYMANAGER_FALSE == pCfg->tImportCfg.bStoreInFlash) /* the ram key space always tidy up already */
                    {
                        pCfg->bTidyUpAlready = HSM_TRUE;
                    }
                    eRet = hsm_update_key_import(pL1Ctx, pCfg, u32TimeoutMs);
                    if (HSM_STATUS_SUCCESS == eRet)
                    {
                        eRet = HSM_STATUS_AGAIN;
                    }
                }
            }
            else if (HSM_STATUS_HW_ERR == eRetFromPrevious)
            {
                eRet = HSM_STATUS_HW_ERR;
                pCfg->eStat = HSM_L2_UPDATE_KEY_SM_STOP;
            }
            else if ((HSM_TRIGGER_SRC_ISR != bTriggerMode) && (HSM_STATUS_AGAIN == eRetFromPrevious))
            {
                eRet = HSM_STATUS_AGAIN;
            }
            else
            {
                eRet = HSM_STATUS_ERROR;
                pCfg->eStat = HSM_L2_UPDATE_KEY_SM_STOP;
            }
        }
        break;

        case HSM_L2_UPDATE_KEY_SM_CHECK_EXIST:
        {
            if (HSM_TRIGGER_SRC_ISR == bTriggerMode)
            {
                HSM_L1_CommonExitEnv(pL1Ctx);
            }
            else
            {
                eRetFromPrevious = HSM_L1_GetKeyIdStatusPoll(pL1Ctx);
                if (HSM_STATUS_AGAIN != eRetFromPrevious)
                {
                    HSM_L1_CommonExitEnv(pL1Ctx);
                }
                /* else do nothing */
            }

            if (HSM_STATUS_NOT_EXIST == eRetFromPrevious) /* key id not exist */
            {
                pCfg->eStat = HSM_L2_UPDATE_KEY_SM_IMPORT;

                eRet = hsm_update_key_import(pL1Ctx, pCfg, u32TimeoutMs);
                if (HSM_STATUS_SUCCESS == eRet)
                {
                    eRet = HSM_STATUS_AGAIN;
                }
                /* else do nothing */
            }
            else if (HSM_STATUS_EXIST == eRetFromPrevious) /* key id exist, and valid */
            {
                pCfg->eStat = HSM_L2_UPDATE_KEY_SM_REVOKE;

                eRet = hsm_update_key_revoke(pL1Ctx, pCfg, u32TimeoutMs);
                if (HSM_STATUS_SUCCESS == eRet)
                {
                    eRet = HSM_STATUS_AGAIN;
                }
                /* else do nothing */
            }
            else if (HSM_STATUS_ZOMBIE == eRetFromPrevious) /* key id exist */
            {
                pCfg->eStat = HSM_L2_UPDATE_KEY_SM_TIDYUP;

                pCfg->bTidyUpAlready = HSM_TRUE;

                eRet = hsm_update_key_tidy(pL1Ctx, pCfg, u32TimeoutMs);
                if (HSM_STATUS_SUCCESS == eRet)
                {
                    eRet = HSM_STATUS_AGAIN;
                }
                /* else do nothing */
            }
            else if ((HSM_TRIGGER_SRC_ISR != bTriggerMode) && (HSM_STATUS_AGAIN == eRetFromPrevious))
            {
                eRet = HSM_STATUS_AGAIN;
            }
            else
            {
                eRet = HSM_STATUS_ERROR;
                pCfg->eStat = HSM_L2_UPDATE_KEY_SM_STOP;
            }
        }
        break;

        case HSM_L2_UPDATE_KEY_SM_REVOKE:
        {
            if (HSM_TRIGGER_SRC_ISR == bTriggerMode)
            {
                HSM_L1_CommonExitEnv(pL1Ctx);
            }
            else
            {
                eRetFromPrevious = HSM_L1_KeyRevokePoll(pL1Ctx);
                if (HSM_STATUS_AGAIN != eRetFromPrevious)
                {
                    HSM_L1_CommonExitEnv(pL1Ctx);
                }
                /* else do nothing */
            }

            if (HSM_STATUS_SUCCESS == eRetFromPrevious)
            {
                pCfg->bTidyUpAlready = HSM_TRUE;

                if (pCfg->tImportCfg.u32KeyIdFix & 0x1) /* ram key don't need tidy up */
                {
                    pCfg->eStat = HSM_L2_UPDATE_KEY_SM_IMPORT;
                    eRet = hsm_update_key_import(pL1Ctx, pCfg, u32TimeoutMs);
                }
                else
                {
                    pCfg->eStat = HSM_L2_UPDATE_KEY_SM_TIDYUP;
                    eRet = hsm_update_key_tidy(pL1Ctx, pCfg, u32TimeoutMs);
                }

                if (HSM_STATUS_SUCCESS == eRet)
                {
                    eRet = HSM_STATUS_AGAIN;
                }
                /* else do nothing */
            }
            else if ((HSM_TRIGGER_SRC_ISR != bTriggerMode) && (HSM_STATUS_AGAIN == eRetFromPrevious))
            {
                eRet = HSM_STATUS_AGAIN;
            }
            else
            {
                eRet = HSM_STATUS_ERROR;
                pCfg->eStat = HSM_L2_UPDATE_KEY_SM_STOP;
            }
        }
        break;

        case HSM_L2_UPDATE_KEY_SM_TIDYUP:
        {
            if (HSM_TRIGGER_SRC_ISR == bTriggerMode)
            {
                HSM_L1_CommonExitEnv(pL1Ctx);
            }
            else
            {
                eRetFromPrevious = HSM_L1_KeySpaceTidyUpPoll(pL1Ctx);
                if (HSM_STATUS_AGAIN != eRetFromPrevious)
                {
                    HSM_L1_CommonExitEnv(pL1Ctx);
                }
                /* else do nothing */
            }

            if (HSM_STATUS_SUCCESS == eRetFromPrevious)
            {
                pCfg->eStat = HSM_L2_UPDATE_KEY_SM_IMPORT;

                eRet = hsm_update_key_import(pL1Ctx, pCfg, u32TimeoutMs);
                if (HSM_STATUS_SUCCESS == eRet)
                {
                    eRet = HSM_STATUS_AGAIN;
                }
                /* else do nothing */
            }
            else if ((HSM_TRIGGER_SRC_ISR != bTriggerMode) && (HSM_STATUS_AGAIN == eRetFromPrevious))
            {
                eRet = HSM_STATUS_AGAIN;
            }
            else
            {
                eRet = HSM_STATUS_ERROR;
                pCfg->eStat = HSM_L2_UPDATE_KEY_SM_STOP;
            }
        }
        break;



        case HSM_L2_UPDATE_KEY_SM_IMPORT:
        {
            if (HSM_TRIGGER_SRC_ISR == bTriggerMode)
            {
                HSM_L1_CommonExitEnv(pL1Ctx);
            }
            else
            {
                eRetFromPrevious = HSM_L1_KeyImportPoll(pL1Ctx);
                if (HSM_STATUS_AGAIN != eRetFromPrevious)
                {
                    HSM_L1_CommonExitEnv(pL1Ctx);
                }
                /* else do nothing */
            }

            if (HSM_STATUS_SUCCESS == eRetFromPrevious)
            {
                pCfg->eStat = HSM_L2_UPDATE_KEY_SM_STOP;

                if (0u == pCfg->tImportCfg.u32KeyIdFix)
                {
                    if (NULL_PTR != pCfg->pKeyIdOut)
                    {
                        *pCfg->pKeyIdOut = pCfg->u32Id;
                    }
                }
                else
                {
                    if (NULL_PTR != pCfg->pKeyIdOut)
                    {
                        *pCfg->pKeyIdOut = pCfg->tImportCfg.u32KeyIdFix;
                    }
                }

                eRet = HSM_STATUS_SUCCESS;
            }
            else if ((HSM_TRIGGER_SRC_ISR != bTriggerMode) && (HSM_STATUS_AGAIN == eRetFromPrevious))
            {
                eRet = HSM_STATUS_AGAIN;
            }
            else if (HSM_FALSE == pCfg->bTidyUpAlready)
            {
                pCfg->eStat = HSM_L2_UPDATE_KEY_SM_GET_STATUS;

                eRet = hsm_update_key_get_status(pL1Ctx, pCfg, u32TimeoutMs);
                if (HSM_STATUS_SUCCESS == eRet)
                {
                    eRet = HSM_STATUS_AGAIN;
                }
                /* else do nothing */
            }
            else
            {
                eRet = HSM_STATUS_ERROR;
                pCfg->eStat = HSM_L2_UPDATE_KEY_SM_STOP;
            }
        }
        break;

        case HSM_L2_UPDATE_KEY_SM_GET_STATUS:
        {
            if (HSM_TRIGGER_SRC_ISR == bTriggerMode)
            {
                HSM_L1_CommonExitEnv(pL1Ctx);
            }
            else
            {
                eRetFromPrevious = HSM_L1_KeySpaceGetStatusPoll(pL1Ctx);
                if (HSM_STATUS_AGAIN != eRetFromPrevious)
                {
                    HSM_L1_CommonExitEnv(pL1Ctx);
                }
                /* else do nothing */
            }

            if (HSM_STATUS_SUCCESS == eRetFromPrevious)
            {
                pCfg->bTidyUpAlready = HSM_TRUE;

                if (pCfg->tKeySpaceStatus.u32InvalidKeyCounter > 0u)
                {
                    pCfg->eStat = HSM_L2_UPDATE_KEY_SM_TIDYUP;

                    eRet = hsm_update_key_tidy(pL1Ctx, pCfg, u32TimeoutMs);
                    if (HSM_STATUS_SUCCESS == eRet)
                    {
                        eRet = HSM_STATUS_AGAIN;
                    }
                    /* else do nothing */
                }
                else
                {
                    pCfg->eStat = HSM_L2_UPDATE_KEY_SM_STOP;
                    eRet = HSM_STATUS_ERROR;
                }
            }
            else if ((HSM_TRIGGER_SRC_ISR != bTriggerMode) && (HSM_STATUS_AGAIN == eRetFromPrevious))
            {
                eRet = HSM_STATUS_AGAIN;
            }
            else
            {
                eRet = HSM_STATUS_ERROR;
                pCfg->eStat = HSM_L2_UPDATE_KEY_SM_STOP;
            }
        }
        break;

        case HSM_L2_UPDATE_KEY_SM_STOP:
        {
            eRet = HSM_STATUS_ERROR;
        }
        break;


        default:
        {
            eRet = HSM_STATUS_ERROR;
        }
        break;
    }

    return eRet;
}
#else
static HSM_StatusType hsm_update_key_content(HSM_L1_RtCtxType *pL1Ctx, HSM_L2_DrvUpdateKeyInfType *pCfg, hsm_uint32_t u32TimeoutMs)
{
    HSM_StatusType eRet;

    eRet = HSM_L1_UpdateKeyIdContentSetupEnv(pL1Ctx);
    if (HSM_STATUS_SUCCESS == eRet)
    {
        eRet = HSM_L1_UpdateKeyIdContent(pL1Ctx, &(pCfg->tUpdateKeyCfg), u32TimeoutMs);

        if (HSM_STATUS_SUCCESS == eRet)
        {
            ;
        }
        else
        {
            HSM_L1_UpdateKeyIdContentExitEnv(pL1Ctx);
            pCfg->eStat = HSM_L2_UPDATE_KEY_SM_STOP;
        }
    }
    else
    {
        pCfg->eStat = HSM_L2_UPDATE_KEY_SM_STOP;
    }

    return eRet;
}

static HSM_StatusType hsm_update_or_import(HSM_L1_RtCtxType *pL1Ctx, HSM_L2_DrvUpdateKeyInfType *pCfg, hsm_uint32_t u32TimeoutMs)
{
    HSM_StatusType eRet;

    if (0u != (pCfg->tImportCfg.u32KeyIdFix))
    {
        pCfg->tUpdateKeyCfg.u32KeyId            = pCfg->tImportCfg.u32KeyIdFix;
        pCfg->tUpdateKeyCfg.pDataAddr           = pCfg->tImportCfg.pDataAddr;
        pCfg->tUpdateKeyCfg.u32PlainKeyLength   = pCfg->tImportCfg.u32DataLength;
        pCfg->tUpdateKeyCfg.eDecryType          = pCfg->tImportCfg.eDecryType;
        pCfg->tUpdateKeyCfg.u32DecryKeyID       = pCfg->tImportCfg.u32DecryKeyID;
        pCfg->tUpdateKeyCfg.eUserKeyType        = pCfg->tImportCfg.eUserKeyType;
        pCfg->tUpdateKeyCfg.eAlgType            = pCfg->tImportCfg.eAlgType;
        pCfg->tUpdateKeyCfg.pIV                 = pCfg->tImportCfg.pIV;

        pCfg->eStat = HSM_L2_UPDATE_KEY_SM_UPDATE;

        if (0x1u == (pCfg->tImportCfg.u32KeyIdFix & 0x1)) /* the ram key space always tidy up already */
        {
            pCfg->bTidyUpAlready = HSM_TRUE;
        }

        eRet = hsm_update_key_content(pL1Ctx, pCfg, u32TimeoutMs);
        if (HSM_STATUS_SUCCESS == eRet)
        {
            eRet = HSM_STATUS_AGAIN;
        }
        /* else do nothing */
    }
    else
    {
        pCfg->eStat = HSM_L2_UPDATE_KEY_SM_IMPORT;

        if (KEYMANAGER_FALSE == pCfg->tImportCfg.bStoreInFlash) /* the ram key space always tidy up already */
        {
            pCfg->bTidyUpAlready = HSM_TRUE;
        }

        eRet = hsm_update_key_import(pL1Ctx, pCfg, u32TimeoutMs);
        if (HSM_STATUS_SUCCESS == eRet)
        {
            eRet = HSM_STATUS_AGAIN;
        }
        /* else do nothing */
    }

    return eRet;
}


HSM_StatusType hsm_l2_update_key_process(HSM_L2_RtCtxType *pL2Ctx, HSM_L1_RtCtxType *pL1Ctx, hsm_uint32_t u32TimeoutMs,
                                         HSM_L2_DrvUpdateKeyInfType *pCfg, HSM_StatusType eRetFromPrevious, HSM_TriggerSrcType bTriggerMode)
{
    HSM_StatusType  eRet = eRetFromPrevious;

    (void)pL2Ctx;

    switch (pCfg->eStat)
    {
        case HSM_L2_UPDATE_KEY_SM_READY:
        {
            eRet = hsm_update_or_import(pL1Ctx, pCfg, u32TimeoutMs);

                /* else do nothing */

        }
        break;

        case HSM_L2_UPDATE_KEY_SM_UPDATE:
        {
            if (HSM_TRIGGER_SRC_ISR == bTriggerMode)
            {
                HSM_L1_CommonExitEnv(pL1Ctx);
            }
            else
            {
                eRetFromPrevious = HSM_L1_UpdateKeyIdContentPoll(pL1Ctx);
                if (HSM_STATUS_AGAIN != eRetFromPrevious)
                {
                    HSM_L1_CommonExitEnv(pL1Ctx);
                }
                /* else do nothing */
            }

            if (HSM_STATUS_SUCCESS == eRetFromPrevious)
            {
                pCfg->eStat = HSM_L2_UPDATE_KEY_SM_STOP;

                if (0u == pCfg->tImportCfg.u32KeyIdFix)
                {
                    if (NULL_PTR != pCfg->pKeyIdOut)
                    {
                        *pCfg->pKeyIdOut = pCfg->u32Id;
                    }
                }
                else
                {
                    if (NULL_PTR != pCfg->pKeyIdOut)
                    {
                        *pCfg->pKeyIdOut = pCfg->tImportCfg.u32KeyIdFix;
                    }
                }

                eRet = HSM_STATUS_SUCCESS;
            }
            else if ((HSM_TRIGGER_SRC_ISR != bTriggerMode) && (HSM_STATUS_AGAIN == eRetFromPrevious))
            {
                eRet = HSM_STATUS_AGAIN;
            }
            else if (HSM_STATUS_NOT_EXIST == eRetFromPrevious) /* the fix key id not exist */
            {
                pCfg->eStat = HSM_L2_UPDATE_KEY_SM_IMPORT;

                if (KEYMANAGER_FALSE == pCfg->tImportCfg.bStoreInFlash) /* the ram key space always tidy up already */
                {
                    pCfg->bTidyUpAlready = HSM_TRUE;
                }

                eRet = hsm_update_key_import(pL1Ctx, pCfg, u32TimeoutMs);
                if (HSM_STATUS_SUCCESS == eRet)
                {
                    eRet = HSM_STATUS_AGAIN;
                }
                /* else do nothing */
            }
            else if (HSM_STATUS_SPACE_FULL == eRetFromPrevious)
            {
                if (HSM_FALSE == pCfg->bTidyUpAlready)
            {
                    pCfg->bTidyUpAlready = HSM_TRUE;
                    pCfg->eStat = HSM_L2_UPDATE_KEY_SM_TIDYUP;

                    eRet = hsm_update_key_tidy(pL1Ctx, pCfg, u32TimeoutMs);
                if (HSM_STATUS_SUCCESS == eRet)
                {
                    eRet = HSM_STATUS_AGAIN;
                    }
                }
                else
                {
                    eRet = HSM_STATUS_ERROR;
                    pCfg->eStat = HSM_L2_UPDATE_KEY_SM_STOP;
                }
                /* else do nothing */
            }
            else
            {
                eRet = HSM_STATUS_ERROR;
                pCfg->eStat = HSM_L2_UPDATE_KEY_SM_STOP;
            }
        }
        break;

        case HSM_L2_UPDATE_KEY_SM_IMPORT:
        {
            if (HSM_TRIGGER_SRC_ISR == bTriggerMode)
            {
                HSM_L1_CommonExitEnv(pL1Ctx);
            }
            else
            {
                eRetFromPrevious = HSM_L1_KeyImportPoll(pL1Ctx);
                if (HSM_STATUS_AGAIN != eRetFromPrevious)
                {
                    HSM_L1_CommonExitEnv(pL1Ctx);
                }
                /* else do nothing */
            }

            if (HSM_STATUS_SUCCESS == eRetFromPrevious)
            {
                pCfg->eStat = HSM_L2_UPDATE_KEY_SM_STOP;

                if (0u == pCfg->tImportCfg.u32KeyIdFix)
                {
                    if (NULL_PTR != pCfg->pKeyIdOut)
                    {
                        *pCfg->pKeyIdOut = pCfg->u32Id;
                    }
                }
                else
                {
                    if (NULL_PTR != pCfg->pKeyIdOut)
                    {
                        *pCfg->pKeyIdOut = pCfg->tImportCfg.u32KeyIdFix;
                    }
                }

                eRet = HSM_STATUS_SUCCESS;
            }
            else if ((HSM_TRIGGER_SRC_ISR != bTriggerMode) && (HSM_STATUS_AGAIN == eRetFromPrevious))
            {
                eRet = HSM_STATUS_AGAIN;
            }
            else if (HSM_STATUS_SPACE_FULL == eRetFromPrevious)
            {
                if (HSM_FALSE == pCfg->bTidyUpAlready)
            {
                    pCfg->bTidyUpAlready = HSM_TRUE;
                    pCfg->eStat = HSM_L2_UPDATE_KEY_SM_TIDYUP;

                    eRet = hsm_update_key_tidy(pL1Ctx, pCfg, u32TimeoutMs);
                if (HSM_STATUS_SUCCESS == eRet)
                {
                    eRet = HSM_STATUS_AGAIN;
                    }
                }
                else
                {
                    eRet = HSM_STATUS_ERROR;
                    pCfg->eStat = HSM_L2_UPDATE_KEY_SM_STOP;
                }
                /* else do nothing */
            }
            else
            {
                eRet = HSM_STATUS_ERROR;
                pCfg->eStat = HSM_L2_UPDATE_KEY_SM_STOP;
            }
        }
        break;

        case HSM_L2_UPDATE_KEY_SM_TIDYUP:
        {
            if (HSM_TRIGGER_SRC_ISR == bTriggerMode)
            {
                HSM_L1_CommonExitEnv(pL1Ctx);
            }
            else
            {
                eRetFromPrevious = HSM_L1_KeySpaceTidyUpPoll(pL1Ctx);
                if (HSM_STATUS_AGAIN != eRetFromPrevious)
                {
                    HSM_L1_CommonExitEnv(pL1Ctx);
                }
                /* else do nothing */
            }

            if (HSM_STATUS_SUCCESS == eRetFromPrevious)
            {


                eRet = hsm_update_or_import(pL1Ctx, pCfg, u32TimeoutMs);
                    /* else do nothing */
            }
            else if ((HSM_TRIGGER_SRC_ISR != bTriggerMode) && (HSM_STATUS_AGAIN == eRetFromPrevious))
            {
                eRet = HSM_STATUS_AGAIN;
            }
            else
            {
                eRet = HSM_STATUS_ERROR;
                pCfg->eStat = HSM_L2_UPDATE_KEY_SM_STOP;
            }
        }
        break;

        case HSM_L2_UPDATE_KEY_SM_STOP:
        {
            eRet = HSM_STATUS_ERROR;
        }
        break;


        default:
        {
            eRet = HSM_STATUS_ERROR;
        }
        break;
    }

    return eRet;
}



#endif

HSM_StatusType HSM_L2_UpdateKeySetupEnv(HSM_L2_RtCtxType *pL2Ctx, HSM_L1_RtCtxType *pL1Ctx)
{
    HSM_StatusType eRet = HSM_STATUS_SUCCESS;

    (void)pL1Ctx;

    if (HSM_LEVEL_2ND_OP_NONE == pL2Ctx->eOperation)
    {
        pL2Ctx->eOperation        = HSM_LEVEL_2ND_OP_UPDATE_KEY;
        pL2Ctx->tL2AlgCtx.tUpdateKey.eStat  = HSM_L2_UPDATE_KEY_SM_READY;
    }
    else
    {
        eRet = HSM_STATUS_BUSY;
    }

    return eRet;
}



HSM_StatusType HSM_L2_UpdateKeyReset(HSM_L2_RtCtxType *pL2Ctx, HSM_L1_RtCtxType *pL1Ctx)
{
    HSM_StatusType eRet = HSM_STATUS_SUCCESS;

    if (HSM_LEVEL_2ND_OP_UPDATE_KEY == pL2Ctx->eOperation)
    {
        eRet = HSM_L1_Abort(pL1Ctx);
        pL2Ctx->tL2AlgCtx.tUpdateKey.eStat  = HSM_L2_UPDATE_KEY_SM_READY;
    }
    else
    {
        eRet = HSM_STATUS_ERROR;
    }
    return eRet;
}

HSM_StatusType HSM_L2_UpdateKey(HSM_L2_RtCtxType *pL2Ctx, HSM_L1_RtCtxType *pL1Ctx, const HSM_Ln_ImportUserKeyExtType *pKeyCfg, hsm_uint32_t u32TimeoutMs)
{
    HSM_StatusType eRet = HSM_STATUS_SUCCESS;

    if (HSM_LEVEL_2ND_OP_UPDATE_KEY == pL2Ctx->eOperation)
    {
        if (pL2Ctx->tL2AlgCtx.tUpdateKey.eStat  == HSM_L2_UPDATE_KEY_SM_READY)
        {

            hsm_memcpy(&(pL2Ctx->tL2AlgCtx.tUpdateKey.tImportCfg), pKeyCfg, sizeof(pL2Ctx->tL2AlgCtx.tUpdateKey.tImportCfg));

            pL2Ctx->tL2AlgCtx.tUpdateKey.u32Id                = 0u;
            pL2Ctx->tL2AlgCtx.tUpdateKey.pKeyIdOut            = pL2Ctx->tL2AlgCtx.tUpdateKey.tImportCfg.pKeyID;
            pL2Ctx->tL2AlgCtx.tUpdateKey.tImportCfg.pKeyID    = &(pL2Ctx->tL2AlgCtx.tUpdateKey.u32Id);
            pL2Ctx->tL2AlgCtx.tUpdateKey.bTidyUpAlready       = HSM_FALSE;

            if (HSM_STATUS_SUCCESS == eRet)
            {
                eRet = hsm_l2_update_key_process(pL2Ctx, pL1Ctx, u32TimeoutMs,
                                                 &(pL2Ctx->tL2AlgCtx.tUpdateKey), HSM_STATUS_SUCCESS, pL1Ctx->eTriggerSrc);
                if (HSM_STATUS_AGAIN == eRet)
                {
                    eRet = HSM_STATUS_SUCCESS;
                }
                else
                {
                    ;
                }
            }

        }
        else
        {
            eRet = HSM_STATUS_LOGIC_ERR;
        }
    }
    else
    {
        eRet = HSM_STATUS_BUSY;
    }


    return eRet;
}

HSM_StatusType HSM_L2_UpdateKeyPoll(HSM_L2_RtCtxType *pL2Ctx, HSM_L1_RtCtxType *pL1Ctx, hsm_uint32_t u32TimeoutMs)
{
    HSM_StatusType eRet;

    if (HSM_LEVEL_2ND_OP_UPDATE_KEY == pL2Ctx->eOperation)
    {
        eRet = hsm_l2_update_key_process(pL2Ctx, pL1Ctx, u32TimeoutMs, &pL2Ctx->tL2AlgCtx.tUpdateKey, HSM_STATUS_SUCCESS, pL1Ctx->eTriggerSrc);
    }
    else
    {
        eRet = HSM_STATUS_ERROR;
    }


    return eRet;
}

HSM_StatusType HSM_L2_UpdateKeyExitEnv(HSM_L2_RtCtxType *pL2Ctx, HSM_L1_RtCtxType *pL1Ctx)
{
    HSM_StatusType eRet = HSM_STATUS_SUCCESS;

    if (HSM_LEVEL_2ND_OP_UPDATE_KEY == pL2Ctx->eOperation)
    {
        eRet = HSM_L1_Abort(pL1Ctx);
        pL2Ctx->eOperation = HSM_LEVEL_2ND_OP_NONE;
    }
    else
    {
        eRet = HSM_STATUS_ERROR;
    }

    return eRet;
}

/* --------------------------------------------------------------------------- */
/* --------------------------------------------------------------------------- */
#if (FC7XXX_HSM_SUBSYSTEM_TYPE == FC7240_HSM_SUBSYSTEM) || (FC7XXX_HSM_SUBSYSTEM_TYPE == FC7300_HSM_SUBSYSTEM)
static HSM_StatusType hsm_revoke_key_validate(HSM_L1_RtCtxType *pL1Ctx, HSM_L2_DrvRevokeKeyInfType *pCfg, hsm_uint32_t u32TimeoutMs)
{
    HSM_StatusType eRet;

    eRet = HSM_L1_GetKeyIdStatusSetupEnv(pL1Ctx);
    if (HSM_STATUS_SUCCESS == eRet)
    {
        eRet = HSM_L1_GetKeyIdStatus(pL1Ctx, pCfg->u32Id, u32TimeoutMs);

        if (HSM_STATUS_SUCCESS == eRet)
        {
            ;
        }
        else
        {
            HSM_L1_GetKeyIdStatusExitEnv(pL1Ctx);
            pCfg->eStat = HSM_L2_REVOKE_KEY_SM_STOP;
        }
    }
    else
    {
        pCfg->eStat = HSM_L2_REVOKE_KEY_SM_STOP;
    }

    return eRet;
}
#endif

#if 0
static HSM_StatusType hsm_revoke_key_tidy(HSM_L1_RtCtxType *pL1Ctx, HSM_L2_DrvRevokeKeyInfType *pCfg, hsm_uint32_t u32TimeoutMs)
{
    HSM_StatusType eRet;


    eRet = HSM_L1_KeySpaceTidyUpSetupEnv(pL1Ctx);
    if (HSM_STATUS_SUCCESS == eRet)
    {
        eRet = HSM_L1_KeySpaceTidyUp(pL1Ctx, &(pCfg->tRevokeInfo.tKeySpaceStatus), u32TimeoutMs);

        if (HSM_STATUS_SUCCESS == eRet)
        {
            ;
        }
        else
        {
            HSM_L1_KeySpaceTidyUpExitEnv(pL1Ctx);
            pCfg->eStat = HSM_L2_REVOKE_KEY_SM_STOP;
        }
    }
    else
    {
        pCfg->eStat = HSM_L2_REVOKE_KEY_SM_STOP;
    }

    return eRet;
}
#endif

static HSM_StatusType hsm_revoke_key_revoke(HSM_L1_RtCtxType *pL1Ctx, HSM_L2_DrvRevokeKeyInfType *pCfg, hsm_uint32_t u32TimeoutMs)
{
    HSM_StatusType eRet          = HSM_STATUS_SUCCESS;


    eRet = HSM_L1_KeyRevokeSetupEnv(pL1Ctx);
    if (HSM_STATUS_SUCCESS == eRet)
    {
        eRet = HSM_L1_KeyRevoke(pL1Ctx, pCfg->u32Id, u32TimeoutMs);

        if (HSM_STATUS_SUCCESS == eRet)
        {
            ;
        }
        else
        {
            HSM_L1_KeyRevokeExitEnv(pL1Ctx);
            pCfg->eStat = HSM_L2_REVOKE_KEY_SM_STOP;
        }
    }
    else
    {
        pCfg->eStat = HSM_L2_REVOKE_KEY_SM_STOP;
    }

    return eRet;
}

HSM_StatusType hsm_l2_revoke_key_process(HSM_L2_RtCtxType *pL2Ctx, HSM_L1_RtCtxType *pL1Ctx, hsm_uint32_t u32TimeoutMs,
                                         HSM_L2_DrvRevokeKeyInfType *pCfg, HSM_StatusType eRetFromPrevious, HSM_TriggerSrcType bTriggerMode)
{
    HSM_StatusType  eRet = eRetFromPrevious;

    (void)pL2Ctx;

    switch (pCfg->eStat)
    {
        case HSM_L2_REVOKE_KEY_SM_READY:
        {
            #if (FC7XXX_HSM_SUBSYSTEM_TYPE == FC7240_HSM_SUBSYSTEM) || (FC7XXX_HSM_SUBSYSTEM_TYPE == FC7300_HSM_SUBSYSTEM)

            pCfg->eStat = HSM_L2_REVOKE_KEY_SM_CHECK_EXIST;

            eRet = hsm_revoke_key_validate(pL1Ctx, pCfg, u32TimeoutMs);
            if (HSM_STATUS_SUCCESS == eRet)
            {
                eRet = HSM_STATUS_AGAIN;
            }
            /* else do nothing */

            #else
            pCfg->eStat = HSM_L2_REVOKE_KEY_SM_REVOKE;

            eRet = hsm_revoke_key_revoke(pL1Ctx, pCfg, u32TimeoutMs);
            if (HSM_STATUS_SUCCESS == eRet)
            {
                eRet = HSM_STATUS_AGAIN;
            }
            /* else do nothing */
            #endif
        }
        break;

        case HSM_L2_REVOKE_KEY_SM_CHECK_EXIST:
        {
#if (FC7XXX_HSM_SUBSYSTEM_TYPE == FC7240_HSM_SUBSYSTEM) || (FC7XXX_HSM_SUBSYSTEM_TYPE == FC7300_HSM_SUBSYSTEM)
            if (HSM_TRIGGER_SRC_ISR == bTriggerMode)
            {
                HSM_L1_CommonExitEnv(pL1Ctx);
            }
            else
            {
                eRetFromPrevious = HSM_L1_GetKeyIdStatusPoll(pL1Ctx);
                if (HSM_STATUS_AGAIN != eRetFromPrevious)
                {
                    HSM_L1_CommonExitEnv(pL1Ctx);
                }
                /* else do nothing */
            }

            if (HSM_STATUS_NOT_EXIST == eRetFromPrevious) /* key id not exist */
            {
                pCfg->eStat = HSM_L2_REVOKE_KEY_SM_STOP;

                eRet = HSM_STATUS_SUCCESS;
            }
            else if (HSM_STATUS_EXIST == eRetFromPrevious) /* key id exist */
            {
                pCfg->eStat = HSM_L2_REVOKE_KEY_SM_REVOKE;

                eRet = hsm_revoke_key_revoke(pL1Ctx, pCfg, u32TimeoutMs);
                if (HSM_STATUS_SUCCESS == eRet)
                {
                    eRet = HSM_STATUS_AGAIN;
                }
                /* else do nothing */
            }
            else if (HSM_STATUS_ZOMBIE == eRetFromPrevious) /* key id exist */
            {
                #if 0
                pCfg->eStat = HSM_L2_REVOKE_KEY_SM_TIDYUP;

                eRet = hsm_revoke_key_tidy(pL1Ctx, pCfg, u32TimeoutMs);
                if (HSM_STATUS_SUCCESS == eRet)
                {
                    eRet = HSM_STATUS_AGAIN;
                }
                /* else do nothing */
                #else
                pCfg->eStat = HSM_L2_REVOKE_KEY_SM_STOP;

                eRet = HSM_STATUS_SUCCESS;

                #endif
            }
            else if ((HSM_TRIGGER_SRC_ISR != bTriggerMode) && (HSM_STATUS_AGAIN == eRetFromPrevious))
            {
                eRet = HSM_STATUS_AGAIN;
            }
            else
            {
                eRet = HSM_STATUS_ERROR;
                pCfg->eStat = HSM_L2_REVOKE_KEY_SM_STOP;
            }
#endif
        }
        break;

        case HSM_L2_REVOKE_KEY_SM_REVOKE:
        {
            if (HSM_TRIGGER_SRC_ISR == bTriggerMode)
            {
                HSM_L1_CommonExitEnv(pL1Ctx);
            }
            else
            {
                eRetFromPrevious = HSM_L1_KeyRevokePoll(pL1Ctx);
                if (HSM_STATUS_AGAIN != eRetFromPrevious)
                {
                    HSM_L1_CommonExitEnv(pL1Ctx);
                }
                /* else do nothing */
            }

            if ((HSM_STATUS_SUCCESS == eRetFromPrevious)
            #if (FC7XXX_HSM_SUBSYSTEM_TYPE == FC7240_HSM_SUBSYSTEM) || (FC7XXX_HSM_SUBSYSTEM_TYPE == FC7300_HSM_SUBSYSTEM)
            #else
                || (HSM_STATUS_NOT_EXIST == eRetFromPrevious)
            #endif
               )
            {
                if (0x1u == (pCfg->u32Id & 0x1u))
                {
                    eRet = HSM_STATUS_SUCCESS;
                    pCfg->eStat = HSM_L2_REVOKE_KEY_SM_STOP;
                }
                else
                {
                    #if (FC7XXX_HSM_SUBSYSTEM_TYPE == FC7240_HSM_SUBSYSTEM) || (FC7XXX_HSM_SUBSYSTEM_TYPE == FC7300_HSM_SUBSYSTEM)


                    #if 0
                    pCfg->eStat = HSM_L2_REVOKE_KEY_SM_TIDYUP;

                    eRet = hsm_revoke_key_tidy(pL1Ctx, pCfg, u32TimeoutMs);
                    if (HSM_STATUS_SUCCESS == eRet)
                    {
                        eRet = HSM_STATUS_AGAIN;
                    }
                    /* else do nothing */
                    #else
                    eRet = HSM_STATUS_SUCCESS;
                    pCfg->eStat = HSM_L2_REVOKE_KEY_SM_STOP;
                    #endif


                    #else
                    eRet = HSM_STATUS_SUCCESS;
                    pCfg->eStat = HSM_L2_REVOKE_KEY_SM_STOP;
                    #endif
                }
            }
            else if ((HSM_TRIGGER_SRC_ISR != bTriggerMode) && (HSM_STATUS_AGAIN == eRetFromPrevious))
            {
                eRet = HSM_STATUS_AGAIN;
            }
            else
            {
                eRet = HSM_STATUS_ERROR;
                pCfg->eStat = HSM_L2_REVOKE_KEY_SM_STOP;
            }
        }
        break;
        #if 0
        case HSM_L2_REVOKE_KEY_SM_TIDYUP:
        {
            if (HSM_TRIGGER_SRC_ISR == bTriggerMode)
            {
                HSM_L1_CommonExitEnv(pL1Ctx);
            }
            else
            {
                eRetFromPrevious = HSM_L1_KeySpaceTidyUpPoll(pL1Ctx);
                if (HSM_STATUS_AGAIN != eRetFromPrevious)
                {
                    HSM_L1_CommonExitEnv(pL1Ctx);
                }
                /* else do nothing */
            }

            if (HSM_STATUS_SUCCESS == eRetFromPrevious)
            {
                pCfg->eStat = HSM_L2_REVOKE_KEY_SM_STOP;

                eRet = HSM_STATUS_SUCCESS;
            }
            else if ((HSM_TRIGGER_SRC_ISR != bTriggerMode) && (HSM_STATUS_AGAIN == eRetFromPrevious))
            {
                eRet = HSM_STATUS_AGAIN;
            }
            else
            {
                eRet = HSM_STATUS_ERROR;
                pCfg->eStat = HSM_L2_REVOKE_KEY_SM_STOP;
            }
        }
        break;
        #endif

        case HSM_L2_REVOKE_KEY_SM_STOP:
        {
            eRet = HSM_STATUS_ERROR;
        }
        break;


        default:
        {
            eRet = HSM_STATUS_ERROR;
        }
        break;
    }

    return eRet;
}



HSM_StatusType HSM_L2_RevokeKeySetupEnv(HSM_L2_RtCtxType *pL2Ctx, HSM_L1_RtCtxType *pL1Ctx)
{
    HSM_StatusType eRet = HSM_STATUS_SUCCESS;

    (void)pL1Ctx;

    if (HSM_LEVEL_2ND_OP_NONE == pL2Ctx->eOperation)
    {
        pL2Ctx->eOperation        = HSM_LEVEL_2ND_OP_REVOKE_KEY;
        pL2Ctx->tL2AlgCtx.tRevokeKey.eStat  = HSM_L2_REVOKE_KEY_SM_READY;
    }
    else
    {
        eRet = HSM_STATUS_BUSY;
    }

    return eRet;
}



HSM_StatusType HSM_L2_RevokeKeyReset(HSM_L2_RtCtxType *pL2Ctx, HSM_L1_RtCtxType *pL1Ctx)
{
    HSM_StatusType eRet = HSM_STATUS_SUCCESS;

    if (HSM_LEVEL_2ND_OP_REVOKE_KEY == pL2Ctx->eOperation)
    {
        eRet = HSM_L1_Abort(pL1Ctx);
        pL2Ctx->tL2AlgCtx.tRevokeKey.eStat  = HSM_L2_REVOKE_KEY_SM_READY;
    }
    else
    {
        eRet = HSM_STATUS_ERROR;
    }
    return eRet;
}

HSM_StatusType HSM_L2_RevokeKey(HSM_L2_RtCtxType *pL2Ctx, HSM_L1_RtCtxType *pL1Ctx, hsm_uint32_t u32KeyId, hsm_uint32_t u32TimeoutMs)
{
    HSM_StatusType eRet = HSM_STATUS_SUCCESS;

    if (HSM_LEVEL_2ND_OP_REVOKE_KEY == pL2Ctx->eOperation)
    {
        if (pL2Ctx->tL2AlgCtx.tRevokeKey.eStat  == HSM_L2_REVOKE_KEY_SM_READY)
        {
            if (0u != u32KeyId)
            {
                pL2Ctx->tL2AlgCtx.tRevokeKey.u32Id = u32KeyId;

                eRet = hsm_l2_revoke_key_process(pL2Ctx, pL1Ctx, u32TimeoutMs,
                                                 &(pL2Ctx->tL2AlgCtx.tRevokeKey), HSM_STATUS_SUCCESS, pL1Ctx->eTriggerSrc);
                if (HSM_STATUS_AGAIN == eRet)
                {
                    eRet = HSM_STATUS_SUCCESS;
                }
                else
                {
                    ;
                }
            }
            else
            {
                eRet = HSM_STATUS_PARAM_ERR;
            }
        }
        else
        {
            eRet = HSM_STATUS_LOGIC_ERR;
        }
    }
    else
    {
        eRet = HSM_STATUS_BUSY;
    }


    return eRet;
}

HSM_StatusType HSM_L2_RevokeKeyPoll(HSM_L2_RtCtxType *pL2Ctx, HSM_L1_RtCtxType *pL1Ctx, hsm_uint32_t u32TimeoutMs)
{
    HSM_StatusType eRet;

    if (HSM_LEVEL_2ND_OP_REVOKE_KEY == pL2Ctx->eOperation)
    {
        eRet = hsm_l2_revoke_key_process(pL2Ctx, pL1Ctx, u32TimeoutMs, &pL2Ctx->tL2AlgCtx.tRevokeKey, HSM_STATUS_SUCCESS, pL1Ctx->eTriggerSrc);
    }
    else
    {
        eRet = HSM_STATUS_ERROR;
    }


    return eRet;
}

HSM_StatusType HSM_L2_RevokeKeyExitEnv(HSM_L2_RtCtxType *pL2Ctx, HSM_L1_RtCtxType *pL1Ctx)
{
    HSM_StatusType eRet = HSM_STATUS_SUCCESS;

    if (HSM_LEVEL_2ND_OP_REVOKE_KEY == pL2Ctx->eOperation)
    {
        eRet = HSM_L1_Abort(pL1Ctx);
        pL2Ctx->eOperation = HSM_LEVEL_2ND_OP_NONE;
    }
    else
    {
        eRet = HSM_STATUS_ERROR;
    }

    return eRet;
}




/* --------------------------------------------------------------------------- */
HSM_StatusType hsm_l2_ecc_verify_process(HSM_L2_RtCtxType *pL2Ctx, HSM_L1_RtCtxType *pL1Ctx, hsm_uint32_t u32TimeoutMs,
                                         HSM_L2_DrvEccVerifyInfType *pCfg, HSM_StatusType eRetFromPrevious, HSM_TriggerSrcType bTriggerMode)
{
    HSM_StatusType  eRet = eRetFromPrevious;

    (void)pL2Ctx;

    switch (pCfg->eStat)
    {
        case HSM_L2_ECC_VERIFY_SM_READY:
        {
            if (HSM_ECC_VERIFY_INPUT_HASH_DATA == pCfg->tEccCfg.eInputType)
            {
                pCfg->eStat = HSM_L2_ECC_VERIFY_SM_VERIFY;

                eRet = HSM_L1_EccVerifySetupEnv(pL1Ctx, pCfg->u32BitCnt);
                if (HSM_STATUS_SUCCESS == eRet)
                {
                    eRet = HSM_L1_EccVerify(pL1Ctx, &(pCfg->tEccCfg.tVerifyParm), u32TimeoutMs);
                    if (HSM_STATUS_SUCCESS == eRet)
                    {
                        eRet = HSM_STATUS_AGAIN;
                    }
                    else
                    {
                        (void)HSM_L1_EccVerifyExitEnv(pL1Ctx);

                        pCfg->eStat = HSM_L2_ECC_VERIFY_SM_STOP;
                        eRet = HSM_STATUS_ERROR;
                    }
                }
                else
                {
                    pCfg->eStat = HSM_L2_ECC_VERIFY_SM_STOP;
                }
            }
            else
            {
                pCfg->eStat = HSM_L2_ECC_VERIFY_SM_HASH;
                eRet = HSM_L1_ShaSetupEnv(pL1Ctx);
                if (HSM_STATUS_SUCCESS == eRet)
                {
                    pCfg->tShaParm.eAlg                     = pCfg->tEccCfg.eAlg;
                    pCfg->tShaParm.tCfg.bGenerateMacEn      = HSM_FALSE;
                    pCfg->tShaParm.tCfg.u32InputDataByteCnt = pCfg->tEccCfg.tVerifyParm.u32DataByteCnt;
                    pCfg->tShaParm.tCfg.pInputData          = pCfg->tEccCfg.tVerifyParm.pData;
                    pCfg->tShaParm.pResult                  = (hsm_uint8_t *) & (pCfg->aCache[0u]);
                    pCfg->tShaParm.u32ResultBufSize         = sizeof(pCfg->aCache);
                    pCfg->tShaParm.pResultSize              = &(pCfg->tEccCfg.tVerifyParm.u32DataByteCnt);
                    pCfg->tShaParm.eInputFmt                = pCfg->tEccCfg.tVerifyParm.eDataFmt;
                    pCfg->tShaParm.eOutputFmt               = pCfg->tEccCfg.tVerifyParm.eDataFmt;
                    pCfg->tShaParm.bKeyUseId                = HSM_FALSE;

                    pCfg->tEccCfg.tVerifyParm.pData         = (const hsm_uint8_t *) & (pCfg->aCache[0u]);

                    eRet = HSM_L1_Sha(pL1Ctx, &(pCfg->tShaParm), u32TimeoutMs);
                    if (HSM_STATUS_SUCCESS == eRet)
                    {
                        eRet = HSM_STATUS_AGAIN;
                    }
                    else
                    {
                        (void)HSM_L1_ShaExitEnv(pL1Ctx);

                        pCfg->eStat = HSM_L2_ECC_VERIFY_SM_STOP;
                        eRet = HSM_STATUS_ERROR;
                    }
                }
                else
                {
                    pCfg->eStat = HSM_L2_ECC_VERIFY_SM_STOP;
                }
            }
        }
        break;

        case HSM_L2_ECC_VERIFY_SM_HASH:
        {
            if (HSM_TRIGGER_SRC_ISR == bTriggerMode)
            {
                HSM_L1_CommonExitEnv(pL1Ctx);
            }
            else
            {
                eRetFromPrevious = HSM_L1_ShaPoll(pL1Ctx);
                if (HSM_STATUS_AGAIN != eRetFromPrevious)
                {
                    HSM_L1_CommonExitEnv(pL1Ctx);
                }
                /* else do nothing */
            }

            if (HSM_STATUS_SUCCESS == eRetFromPrevious)
            {
                pCfg->eStat = HSM_L2_ECC_VERIFY_SM_VERIFY;

                eRet = HSM_L1_EccVerifySetupEnv(pL1Ctx, pCfg->u32BitCnt);
                if (HSM_STATUS_SUCCESS == eRet)
                {
                    eRet = HSM_L1_EccVerify(pL1Ctx, &(pCfg->tEccCfg.tVerifyParm), u32TimeoutMs);
                    if (HSM_STATUS_SUCCESS == eRet)
                    {
                        eRet = HSM_STATUS_AGAIN;
                    }
                    else
                    {
                        (void)HSM_L1_EccVerifyExitEnv(pL1Ctx);

                        pCfg->eStat = HSM_L2_ECC_VERIFY_SM_STOP;
                        eRet = HSM_STATUS_ERROR;
                    }
                }
                else
                {
                    pCfg->eStat = HSM_L2_ECC_VERIFY_SM_STOP;
                }
            }
            else if ((HSM_TRIGGER_SRC_ISR != bTriggerMode) && (HSM_STATUS_AGAIN == eRetFromPrevious))
            {
                eRet = HSM_STATUS_AGAIN;
            }
            else
            {
                eRet = HSM_STATUS_ERROR;
                pCfg->eStat = HSM_L2_ECC_VERIFY_SM_STOP;
            }
        }
        break;

        case HSM_L2_ECC_VERIFY_SM_VERIFY:
        {
            if (HSM_TRIGGER_SRC_ISR == bTriggerMode)
            {
                HSM_L1_CommonExitEnv(pL1Ctx);
            }
            else
            {
                eRetFromPrevious = HSM_L1_EccVerifyPoll(pL1Ctx);
                if (HSM_STATUS_AGAIN != eRetFromPrevious)
                {
                    HSM_L1_CommonExitEnv(pL1Ctx);
                }
                /* else do nothing */
            }

            if (HSM_STATUS_PASS == eRetFromPrevious)
            {
                pCfg->eStat = HSM_L2_ECC_VERIFY_SM_STOP;

                if (NULL_PTR != pCfg->tEccCfg.pVerifyResult)
                {
                    *(pCfg->tEccCfg.pVerifyResult) = CRYPTO_E_VER_OK;
                }
                /* else do nothing */
                eRet = eRetFromPrevious;
            }
            else if (HSM_STATUS_FAIL == eRetFromPrevious)
            {
                pCfg->eStat = HSM_L2_ECC_VERIFY_SM_STOP;

                if (NULL_PTR != pCfg->tEccCfg.pVerifyResult)
                {
                    *(pCfg->tEccCfg.pVerifyResult) = CRYPTO_E_VER_NOT_OK;
                }
                /* else do nothing */
                eRet = eRetFromPrevious;
            }
            else if ((HSM_TRIGGER_SRC_ISR != bTriggerMode) && (HSM_STATUS_AGAIN == eRetFromPrevious))
            {
                eRet = HSM_STATUS_AGAIN;
            }
            else
            {
                eRet = HSM_STATUS_ERROR;
                pCfg->eStat = HSM_L2_ECC_VERIFY_SM_STOP;
            }
        }
        break;



        case HSM_L2_ECC_VERIFY_SM_STOP:
        {
            eRet = HSM_STATUS_ERROR;
        }
        break;


        default:
        {
            eRet = HSM_STATUS_ERROR;
        }
        break;
    }

    return eRet;
}


HSM_StatusType HSM_L2_EccVerifySetupEnv(HSM_L2_RtCtxType *pL2Ctx, HSM_L1_RtCtxType *pL1Ctx, hsm_uint32_t u32BitCnt)
{
    HSM_StatusType eRet = HSM_STATUS_SUCCESS;

    (void)pL1Ctx;

    if (HSM_LEVEL_2ND_OP_NONE == pL2Ctx->eOperation)
    {
        pL2Ctx->eOperation              = HSM_LEVEL_2ND_OP_ECC_VERIFY;
        pL2Ctx->tL2AlgCtx.tEccVerify.eStat        = HSM_L2_ECC_VERIFY_SM_READY;
        pL2Ctx->tL2AlgCtx.tEccVerify.u32BitCnt    = u32BitCnt;
    }
    else
    {
        eRet = HSM_STATUS_BUSY;
    }

    return eRet;
}



HSM_StatusType HSM_L2_EccVerifyReset(HSM_L2_RtCtxType *pL2Ctx, HSM_L1_RtCtxType *pL1Ctx)
{
    HSM_StatusType eRet = HSM_STATUS_SUCCESS;

    if (HSM_LEVEL_2ND_OP_ECC_VERIFY == pL2Ctx->eOperation)
    {
        eRet = HSM_L1_Abort(pL1Ctx);
        pL2Ctx->tL2AlgCtx.tEccVerify.eStat  = HSM_L2_ECC_VERIFY_SM_READY;
    }
    else
    {
        eRet = HSM_STATUS_ERROR;
    }

    return eRet;
}

HSM_StatusType HSM_L2_EccVerify(HSM_L2_RtCtxType *pL2Ctx, HSM_L1_RtCtxType *pL1Ctx, const HSM_Ln_EccVerifyType *pCfg, hsm_uint32_t u32TimeoutMs)
{
    HSM_StatusType eRet = HSM_STATUS_SUCCESS;

    if (HSM_LEVEL_2ND_OP_ECC_VERIFY == pL2Ctx->eOperation)
    {
        if (pL2Ctx->tL2AlgCtx.tEccVerify.eStat  == HSM_L2_ECC_VERIFY_SM_READY)
        {
            hsm_memcpy(&(pL2Ctx->tL2AlgCtx.tEccVerify.tEccCfg), pCfg, sizeof(HSM_Ln_EccVerifyType));

            eRet = hsm_l2_ecc_verify_process(pL2Ctx, pL1Ctx, u32TimeoutMs,
                                             &(pL2Ctx->tL2AlgCtx.tEccVerify), HSM_STATUS_SUCCESS, pL1Ctx->eTriggerSrc);
            if (HSM_STATUS_AGAIN == eRet)
            {
                eRet = HSM_STATUS_SUCCESS;
            }
            /* else do nothing */
        }
        else
        {
            eRet = HSM_STATUS_LOGIC_ERR;
        }
    }
    else
    {
        eRet = HSM_STATUS_BUSY;
    }


    return eRet;
}

HSM_StatusType HSM_L2_EccVerifyPoll(HSM_L2_RtCtxType *pL2Ctx, HSM_L1_RtCtxType *pL1Ctx, hsm_uint32_t u32TimeoutMs)
{
    HSM_StatusType eRet;

    if (HSM_LEVEL_2ND_OP_ECC_VERIFY == pL2Ctx->eOperation)
    {
        eRet = hsm_l2_ecc_verify_process(pL2Ctx, pL1Ctx, u32TimeoutMs, &(pL2Ctx->tL2AlgCtx.tEccVerify), HSM_STATUS_SUCCESS, pL1Ctx->eTriggerSrc);
    }
    else
    {
        eRet = HSM_STATUS_ERROR;
    }

    return eRet;
}

HSM_StatusType HSM_L2_EccVerifyExitEnv(HSM_L2_RtCtxType *pL2Ctx, HSM_L1_RtCtxType *pL1Ctx)
{
    HSM_StatusType eRet = HSM_STATUS_SUCCESS;

    if (HSM_LEVEL_2ND_OP_ECC_VERIFY == pL2Ctx->eOperation)
    {
        eRet = HSM_L1_Abort(pL1Ctx);
        pL2Ctx->eOperation = HSM_LEVEL_2ND_OP_NONE;
    }
    else
    {
        eRet = HSM_STATUS_ERROR;
    }

    return eRet;
}

HSM_StatusType hsm_l2_sm2_verify_process(HSM_L2_RtCtxType *pL2Ctx, HSM_L1_RtCtxType *pL1Ctx, hsm_uint32_t u32TimeoutMs,
        HSM_L2_DrvSm2VerifyInfType *pCfg, HSM_StatusType eRetFromPrevious, HSM_TriggerSrcType bTriggerMode)
{
    HSM_StatusType  eRet = eRetFromPrevious;

    (void)pL2Ctx;

    switch (pCfg->eStat)
    {
        case HSM_L2_SM2_VERIFY_SM_READY:
        {
            if (HSM_SM2_VERIFY_INPUT_HASH_DATA == pCfg->tSm2Cfg.eInputType)
            {
                pCfg->eStat = HSM_L2_SM2_VERIFY_SM_VERIFY;

                eRet = HSM_L1_Sm2VerifySetupEnv(pL1Ctx);
                if (HSM_STATUS_SUCCESS == eRet)
                {
                    eRet = HSM_L1_Sm2Verify(pL1Ctx, &(pCfg->tSm2Cfg.tVerifyParm), u32TimeoutMs);
                    if (HSM_STATUS_SUCCESS == eRet)
                    {
                        eRet = HSM_STATUS_AGAIN;
                    }
                    else
                    {
                        (void)HSM_L1_Sm2VerifyExitEnv(pL1Ctx);

                        pCfg->eStat = HSM_L2_SM2_VERIFY_SM_STOP;
                        eRet = HSM_STATUS_ERROR;
                    }
                }
                else
                {
                    pCfg->eStat = HSM_L2_SM2_VERIFY_SM_STOP;
                }
            }
            else
            {
                pCfg->eStat = HSM_L2_SM2_VERIFY_SM_GEN_ZA;

                eRet = HSM_L1_Sm2GenZaSetupEnv(pL1Ctx);
                if (HSM_STATUS_SUCCESS == eRet)
                {
                    pCfg->tSm2GenZaCfg.bUseDefaultID = pCfg->tSm2Cfg.tVerifyParm.bUseDefaultID;
                    pCfg->tSm2GenZaCfg.eDataFmt = pCfg->tSm2Cfg.tVerifyParm.eDataFmt;
                    pCfg->tSm2GenZaCfg.pkGx = pCfg->tSm2Cfg.tVerifyParm.pkGx;
                    pCfg->tSm2GenZaCfg.pkGy = pCfg->tSm2Cfg.tVerifyParm.pkGy;
                    pCfg->tSm2GenZaCfg.pInputData_ID = pCfg->tSm2Cfg.tVerifyParm.pInputData_ID;
                    pCfg->tSm2GenZaCfg.u32SM2InputIDByteCnt = pCfg->tSm2Cfg.tVerifyParm.u32SM2InputIDByteCnt;
                    pCfg->tSm2GenZaCfg.ekGxyDataFmt = pCfg->tSm2Cfg.tVerifyParm.ekGxyDataFmt;
                    pCfg->tSm2GenZaCfg.u32PublicKeyId = pCfg->tSm2Cfg.tVerifyParm.u32PublicKeyId;
                    pCfg->tSm2GenZaCfg.u32kGxByteCnt = pCfg->tSm2Cfg.tVerifyParm.u32kGxByteCnt;
                    pCfg->tSm2GenZaCfg.u32kGyByteCnt = pCfg->tSm2Cfg.tVerifyParm.u32kGyByteCnt;
                    pCfg->tSm2GenZaCfg.pOutputData_Za = &pCfg->aCache;
                    pCfg->tSm2GenZaCfg.eOutputFmt = pCfg->tSm2Cfg.tVerifyParm.eDataFmt;

                    eRet = HSM_L1_Sm2GenZa(pL1Ctx, &(pCfg->tSm2GenZaCfg), u32TimeoutMs);
                    if (HSM_STATUS_SUCCESS == eRet)
                    {
                        eRet = HSM_STATUS_AGAIN;
                    }
                    else
                    {
                        (void)HSM_L1_Sm2GenZaExitEnv(pL1Ctx);
                        pCfg->eStat = HSM_L2_SM2_VERIFY_SM_STOP;
                        eRet = HSM_STATUS_ERROR;
                    }
                }
                else
                {
                    pCfg->eStat = HSM_L2_SM2_VERIFY_SM_STOP;
                }
            }
        }
        break;

        case HSM_L2_SM2_VERIFY_SM_GEN_ZA:
        {
            if (HSM_TRIGGER_SRC_ISR == bTriggerMode)
            {
                HSM_L1_CommonExitEnv(pL1Ctx);
            }
            else
            {
                eRetFromPrevious = HSM_L1_Sm2GenZaPoll(pL1Ctx);
                if (HSM_STATUS_AGAIN != eRetFromPrevious)
                {
                    HSM_L1_CommonExitEnv(pL1Ctx);
                }
                /* else do nothing */
            }

            if (HSM_STATUS_SUCCESS == eRetFromPrevious)
            {
                eRet = HSM_L1_ScatterHashSetupEnv(pL1Ctx);
                if (HSM_STATUS_SUCCESS == eRet)
                {
                    pCfg->tScatterSm3Cfg.pData = (const hsm_uint8_t *)(&pCfg->aCache[0]);
                    pCfg->tScatterSm3Cfg.u32DataSize = 32u;
                    pCfg->tScatterSm3Cfg.eDataFmt = pCfg->tSm2GenZaCfg.eOutputFmt;

                    eRet = HSM_L1_ScatterHashInit(pL1Ctx, HSM_HASH_SM3,&pCfg->tScatterSm3Cfg ,u32TimeoutMs);
                    if(HSM_STATUS_AGAIN == eRet)
                    {
                        pCfg->eStat = HSM_L2_SM2_VERIFY_SM_HASH_UPDATE;
                        pCfg->tScatterSm3Cfg.pData = pCfg->tSm2Cfg.tVerifyParm.pData;
                        pCfg->tScatterSm3Cfg.u32DataSize = pCfg->tSm2Cfg.tVerifyParm.u32DataByteCnt;
                        pCfg->tScatterSm3Cfg.eDataFmt = pCfg->tSm2Cfg.tVerifyParm.eDataFmt;

                        eRet = HSM_L1_ScatterHashUpdate(pL1Ctx,&pCfg->tScatterSm3Cfg ,u32TimeoutMs);
                        if (HSM_STATUS_SUCCESS == eRet)
                        {
                            eRet = HSM_STATUS_AGAIN;
                        }
                        else if(HSM_STATUS_AGAIN == eRet)
                        {
                            pCfg->eStat = HSM_L2_SM2_VERIFY_SM_HASH_FINALLY;
                            pCfg->tScatterSm3Cfg.pData = NULL_PTR;
                            pCfg->tScatterSm3Cfg.u32DataSize = 0;
                            pCfg->tScatterSm3Cfg.eDataFmt = pCfg->tSm2Cfg.tVerifyParm.eDataFmt;
                            pCfg->tScatterSm3Result.pData = (hsm_uint8_t *)(&pCfg->aCache[0]);
                            pCfg->tScatterSm3Result.u32DataBufSize = sizeof(pCfg->aCache);
                            pCfg->tScatterSm3Result.eDataFmt = pCfg->tSm2Cfg.tVerifyParm.eDataFmt;
                            pCfg->tScatterSm3Result.pDataSize = &pCfg->tSm2Cfg.tVerifyParm.u32DataByteCnt;
                            pCfg->tSm2Cfg.tVerifyParm.pData = pCfg->tScatterSm3Result.pData;

                            eRet = HSM_L1_ScatterHashFinal(pL1Ctx,&pCfg->tScatterSm3Cfg,&pCfg->tScatterSm3Result,u32TimeoutMs);
                            if (HSM_STATUS_SUCCESS == eRet)
                            {
                                eRet = HSM_STATUS_AGAIN;
                            }
                            else
                            {
                                (void)HSM_L1_ScatterHashExitEnv(pL1Ctx);
                                pCfg->eStat = HSM_L2_SM2_VERIFY_SM_STOP;
                                eRet = HSM_STATUS_ERROR;
                            }
                        }
                        else
                        {
                            (void)HSM_L1_ScatterHashExitEnv(pL1Ctx);
                            pCfg->eStat = HSM_L2_SM2_VERIFY_SM_STOP;
                            eRet = HSM_STATUS_ERROR;                            
                        } 
                    }
                    else
                    {
                        (void)HSM_L1_ScatterHashExitEnv(pL1Ctx);
                        pCfg->eStat = HSM_L2_SM2_VERIFY_SM_STOP;
                        eRet = HSM_STATUS_ERROR;
                    }
                }
                else
                {
                    pCfg->eStat = HSM_L2_SM2_VERIFY_SM_STOP;
                }
            }
            else if ((HSM_TRIGGER_SRC_ISR != bTriggerMode) && (HSM_STATUS_AGAIN == eRetFromPrevious))
            {
                eRet = HSM_STATUS_AGAIN;
            }
            else
            {
                eRet = HSM_STATUS_ERROR;
                pCfg->eStat = HSM_L2_SM2_VERIFY_SM_STOP;
            }
        }
        break;

        case HSM_L2_SM2_VERIFY_SM_HASH_UPDATE:
            if (HSM_TRIGGER_SRC_USER_POLL == bTriggerMode)
            {
                eRetFromPrevious = HSM_L1_ScatterHashPoll(pL1Ctx);
            }

            if (HSM_STATUS_SUCCESS == eRetFromPrevious)
            {
                pCfg->eStat = HSM_L2_SM2_VERIFY_SM_HASH_FINALLY;
                pCfg->tScatterSm3Cfg.pData = NULL_PTR;
                pCfg->tScatterSm3Cfg.u32DataSize = 0;
                pCfg->tScatterSm3Cfg.eDataFmt = pCfg->tSm2Cfg.tVerifyParm.eDataFmt;
                pCfg->tScatterSm3Result.pData = (hsm_uint8_t *)(&pCfg->aCache[0]);
                pCfg->tScatterSm3Result.u32DataBufSize = sizeof(pCfg->aCache);
                pCfg->tScatterSm3Result.eDataFmt = pCfg->tSm2Cfg.tVerifyParm.eDataFmt;
                pCfg->tScatterSm3Result.pDataSize = &pCfg->tSm2Cfg.tVerifyParm.u32DataByteCnt;
                pCfg->tSm2Cfg.tVerifyParm.pData = pCfg->tScatterSm3Result.pData;

                eRet = HSM_L1_ScatterHashFinal(pL1Ctx,&pCfg->tScatterSm3Cfg,&pCfg->tScatterSm3Result,u32TimeoutMs);
                if (HSM_STATUS_SUCCESS == eRet)
                {
                    eRet = HSM_STATUS_AGAIN;
                }
                else
                {
                    (void)HSM_L1_ScatterHashExitEnv(pL1Ctx);
                    pCfg->eStat = HSM_L2_SM2_VERIFY_SM_STOP;
                    eRet = HSM_STATUS_ERROR;
                }

            }
            else if ((HSM_TRIGGER_SRC_ISR != bTriggerMode) && (HSM_STATUS_AGAIN == eRetFromPrevious))
            {
                eRet = HSM_STATUS_AGAIN;
            }
            else
            {
                eRet = HSM_STATUS_ERROR;
                pCfg->eStat = HSM_L2_SM2_VERIFY_SM_STOP;
            }

            break;

        case HSM_L2_SM2_VERIFY_SM_HASH_FINALLY:
            if (HSM_TRIGGER_SRC_ISR == bTriggerMode)
            {
                HSM_L1_CommonExitEnv(pL1Ctx);
            }
            else
            {
                eRetFromPrevious = HSM_L1_ScatterHashPoll(pL1Ctx);
                if (HSM_STATUS_AGAIN != eRetFromPrevious)
                {
                    HSM_L1_CommonExitEnv(pL1Ctx);
                }
                /* else do nothing */
            }

            if (HSM_STATUS_SUCCESS == eRetFromPrevious)
            {
                pCfg->eStat = HSM_L2_SM2_VERIFY_SM_VERIFY;

                eRet = HSM_L1_Sm2VerifySetupEnv(pL1Ctx);
                if (HSM_STATUS_SUCCESS == eRet)
                {
                    eRet = HSM_L1_Sm2Verify(pL1Ctx, &(pCfg->tSm2Cfg.tVerifyParm), u32TimeoutMs);
                    if (HSM_STATUS_SUCCESS == eRet)
                    {
                        eRet = HSM_STATUS_AGAIN;
                    }
                    else
                    {
                        (void)HSM_L1_Sm2VerifyExitEnv(pL1Ctx);

                        pCfg->eStat = HSM_L2_SM2_VERIFY_SM_STOP;
                        eRet = HSM_STATUS_ERROR;
                    }
                }
                else
                {
                    pCfg->eStat = HSM_L2_SM2_VERIFY_SM_STOP;
                }

            }
            else if ((HSM_TRIGGER_SRC_ISR != bTriggerMode) && (HSM_STATUS_AGAIN == eRetFromPrevious))
            {
                eRet = HSM_STATUS_AGAIN;
            }
            else
            {
                eRet = HSM_STATUS_ERROR;
                pCfg->eStat = HSM_L2_SM2_VERIFY_SM_STOP;
            }

            break;

        case HSM_L2_SM2_VERIFY_SM_VERIFY:
        {
            if (HSM_TRIGGER_SRC_ISR == bTriggerMode)
            {
                HSM_L1_CommonExitEnv(pL1Ctx);
            }
            else
            {
                eRetFromPrevious = HSM_L1_Sm2VerifyPoll(pL1Ctx);
                if (HSM_STATUS_AGAIN != eRetFromPrevious)
                {
                    HSM_L1_CommonExitEnv(pL1Ctx);
                }
                /* else do nothing */
            }

            if (HSM_STATUS_PASS == eRetFromPrevious)
            {
                pCfg->eStat = HSM_L2_SM2_VERIFY_SM_STOP;

                if (NULL_PTR != pCfg->tSm2Cfg.pVerifyResult)
                {
                    *(pCfg->tSm2Cfg.pVerifyResult) = CRYPTO_E_VER_OK;
                }
                /* else do nothing */
                eRet = eRetFromPrevious;
            }
            else if (HSM_STATUS_FAIL == eRetFromPrevious)
            {
                pCfg->eStat = HSM_L2_SM2_VERIFY_SM_STOP;

                if (NULL_PTR != pCfg->tSm2Cfg.pVerifyResult)
                {
                    *(pCfg->tSm2Cfg.pVerifyResult) = CRYPTO_E_VER_NOT_OK;
                }
                /* else do nothing */
                eRet = eRetFromPrevious;
            }
            else if ((HSM_TRIGGER_SRC_ISR != bTriggerMode) && (HSM_STATUS_AGAIN == eRetFromPrevious))
            {
                eRet = HSM_STATUS_AGAIN;
            }
            else
            {
                eRet = HSM_STATUS_ERROR;
                pCfg->eStat = HSM_L2_SM2_VERIFY_SM_STOP;
            }
        }
        break;

        case HSM_L2_SM2_VERIFY_SM_STOP:
        {
            eRet = HSM_STATUS_ERROR;
        }
        break;

        default:
        {
            eRet = HSM_STATUS_ERROR;
        }
        break;
    }

    return eRet;
}

HSM_StatusType HSM_L2_Sm2VerifySetupEnv(HSM_L2_RtCtxType *pL2Ctx, HSM_L1_RtCtxType *pL1Ctx)
{
    HSM_StatusType eRet = HSM_STATUS_SUCCESS;

    (void)pL1Ctx;

    if (HSM_LEVEL_2ND_OP_NONE == pL2Ctx->eOperation)
    {
        pL2Ctx->eOperation              = HSM_LEVEL_2ND_OP_SM2_VERIFY;
        pL2Ctx->tL2AlgCtx.tSm2Verify.eStat        = HSM_L2_SM2_VERIFY_SM_READY;
    }
    else
    {
        eRet = HSM_STATUS_BUSY;
    }

    return eRet;
}

HSM_StatusType HSM_L2_Sm2VerifyReset(HSM_L2_RtCtxType *pL2Ctx, HSM_L1_RtCtxType *pL1Ctx)
{
    HSM_StatusType eRet = HSM_STATUS_SUCCESS;

    if (HSM_LEVEL_2ND_OP_SM2_VERIFY == pL2Ctx->eOperation)
    {
        eRet = HSM_L1_Abort(pL1Ctx);
        pL2Ctx->tL2AlgCtx.tSm2Verify.eStat  = HSM_L2_SM2_VERIFY_SM_READY;
    }
    else
    {
        eRet = HSM_STATUS_ERROR;
    }

    return eRet;
}

HSM_StatusType HSM_L2_Sm2Verify(HSM_L2_RtCtxType *pL2Ctx, HSM_L1_RtCtxType *pL1Ctx, const HSM_Ln_Sm2VerifyType *pCfg, hsm_uint32_t u32TimeoutMs)
{
    HSM_StatusType eRet = HSM_STATUS_SUCCESS;

    if (HSM_LEVEL_2ND_OP_SM2_VERIFY == pL2Ctx->eOperation)
    {
        if (pL2Ctx->tL2AlgCtx.tSm2Verify.eStat  == HSM_L2_SM2_VERIFY_SM_READY)
        {
            hsm_memcpy(&(pL2Ctx->tL2AlgCtx.tSm2Verify.tSm2Cfg), pCfg, sizeof(HSM_Ln_Sm2VerifyType));

            eRet = hsm_l2_sm2_verify_process(pL2Ctx, pL1Ctx, u32TimeoutMs,
                &(pL2Ctx->tL2AlgCtx.tSm2Verify), HSM_STATUS_SUCCESS, pL1Ctx->eTriggerSrc);

            if (HSM_STATUS_AGAIN == eRet)
            {
                eRet = HSM_STATUS_SUCCESS;
            }
            /* else do nothing */
        }
        else
        {
            eRet = HSM_STATUS_LOGIC_ERR;
        }
    }
    else
    {
        eRet = HSM_STATUS_BUSY;
    }

    return eRet;
}

HSM_StatusType HSM_L2_Sm2VerifyPoll(HSM_L2_RtCtxType *pL2Ctx, HSM_L1_RtCtxType *pL1Ctx, hsm_uint32_t u32TimeoutMs)
{
    HSM_StatusType eRet;

    if (HSM_LEVEL_2ND_OP_SM2_VERIFY == pL2Ctx->eOperation)
    {
        eRet = hsm_l2_sm2_verify_process(pL2Ctx, pL1Ctx, u32TimeoutMs, &(pL2Ctx->tL2AlgCtx.tSm2Verify), HSM_STATUS_SUCCESS, pL1Ctx->eTriggerSrc);
    }
    else
    {
        eRet = HSM_STATUS_ERROR;
    }

    return eRet;
}
HSM_StatusType HSM_L2_Sm2VerifyExitEnv(HSM_L2_RtCtxType *pL2Ctx, HSM_L1_RtCtxType *pL1Ctx)
{
    HSM_StatusType eRet = HSM_STATUS_SUCCESS;

    if (HSM_LEVEL_2ND_OP_SM2_VERIFY == pL2Ctx->eOperation)
    {
        eRet = HSM_L1_Abort(pL1Ctx);
        pL2Ctx->eOperation = HSM_LEVEL_2ND_OP_NONE;
    }
    else
    {
        eRet = HSM_STATUS_ERROR;
    }

    return eRet;
}

/* --------------------------------------------------------------------------- */
/* --------------------------------------------------------------------------- */
void HSM_L2_Ack_IrqHandler(void *pUpperCtx, HSM_BoolType bIsErrorHappen, HSM_StatusType eRet)
{
    HSM_StatusType    eCurStat = eRet;
    HSM_BoolType      bLevel2Running = HSM_TRUE;
    HSM_Ln_RtCtxType *pLnCtx = (HSM_Ln_RtCtxType *)pUpperCtx;
    HSM_L2_RtCtxType *pL2Ctx = &(pLnCtx->tHsmL2Ctx);
    HSM_L1_RtCtxType *pL1Ctx = &(pLnCtx->tHsmL1Ctx);
    HSM_BoolType bErrorHappen = bIsErrorHappen;
    
    switch (pL2Ctx->eOperation)
    {
        case HSM_LEVEL_2ND_OP_CMAC_EMPTY:
        {
            eCurStat = hsm_l2_cmac_empty_process(pL2Ctx, pL1Ctx, pLnCtx->u32OpLimitMs, &pL2Ctx->tL2AlgCtx.tCMacEmpty, eRet, pL1Ctx->eTriggerSrc);
            if (HSM_STATUS_AGAIN != eCurStat)
            {
                if (HSM_STATUS_SUCCESS != eCurStat)
                {
                    bErrorHappen = HSM_TRUE;
                }
                else
                {
                    bErrorHappen = HSM_FALSE;
                }
            }
            /* else do nothing */
        }
        break;

        case HSM_LEVEL_2ND_OP_UPDATE_KEY:
        {
            eCurStat = hsm_l2_update_key_process(pL2Ctx, pL1Ctx, pLnCtx->u32OpLimitMs, &pL2Ctx->tL2AlgCtx.tUpdateKey, eRet, pL1Ctx->eTriggerSrc);
            if (HSM_STATUS_AGAIN != eCurStat)
            {
                if (HSM_STATUS_SUCCESS != eCurStat)
                {
                    bErrorHappen = HSM_TRUE;
                }
                else
                {
                    bErrorHappen = HSM_FALSE;
                }
            }
            /* else do nothing */
        }
        break;

        case HSM_LEVEL_2ND_OP_REVOKE_KEY:
        {
            eCurStat = hsm_l2_revoke_key_process(pL2Ctx, pL1Ctx, pLnCtx->u32OpLimitMs, &pL2Ctx->tL2AlgCtx.tRevokeKey, eRet, pL1Ctx->eTriggerSrc);
            if (HSM_STATUS_AGAIN != eCurStat)
            {
                if (HSM_STATUS_SUCCESS != eCurStat)
                {
                    bErrorHappen = HSM_TRUE;
                }
                else
                {
                    bErrorHappen = HSM_FALSE;
                }
            }
            /* else do nothing */
        }
        break;

        case HSM_LEVEL_2ND_OP_ECC_VERIFY:
        {
            eCurStat = hsm_l2_ecc_verify_process(pL2Ctx, pL1Ctx, pLnCtx->u32OpLimitMs, &pL2Ctx->tL2AlgCtx.tEccVerify, eRet, pL1Ctx->eTriggerSrc);
            if (HSM_STATUS_AGAIN != eCurStat)
            {
                if ((HSM_STATUS_PASS != eCurStat) && (HSM_STATUS_FAIL != eCurStat))
                {
                    bErrorHappen = HSM_TRUE;
                }
                else
                {
                    bErrorHappen = HSM_FALSE;
                }
            }
            /* else do nothing */
        }
        break;

        case HSM_LEVEL_2ND_OP_SM2_VERIFY:
        {
            eCurStat = hsm_l2_sm2_verify_process(pL2Ctx, pL1Ctx, pLnCtx->u32OpLimitMs, &pL2Ctx->tL2AlgCtx.tSm2Verify, eRet, pL1Ctx->eTriggerSrc);
            if (HSM_STATUS_AGAIN != eCurStat)
            {
                if ((HSM_STATUS_PASS != eCurStat) && (HSM_STATUS_FAIL != eCurStat))
                {
                    bErrorHappen = HSM_TRUE;
                }
                else
                {
                    bErrorHappen = HSM_FALSE;
                }
            }
            /* else do nothing */
        }
        break;
        
        default:
            eCurStat = eRet;
            bLevel2Running = HSM_FALSE;
            break;
    }

    if ((HSM_FALSE == bLevel2Running) || (HSM_STATUS_AGAIN != eCurStat))
    {
        if (NULL_PTR != pL2Ctx->pStopCb)
        {
            pL2Ctx->pStopCb(pUpperCtx, bErrorHappen, eCurStat);
        }
        /* else nothing */
    }
    /* else do nothing */
}


void HSM_L2_Init(HSM_L2_RtCtxType *pCtx, HSM_L2_InitParmType *pParm)
{
    pCtx->eOperation = HSM_LEVEL_2ND_OP_NONE;
    pCtx->pStopCb    = pParm->pStopCb;

}

void HSM_L2_CleanEnv(HSM_L2_RtCtxType *pCtx)
{
    pCtx->eOperation = HSM_LEVEL_2ND_OP_NONE;
}

/* abort the second level operation, the operation goto none */
void HSM_L2_Abort(HSM_L2_RtCtxType *pCtx)
{
    pCtx->eOperation = HSM_LEVEL_2ND_OP_NONE;
}

void HSM_L2_CommonExitEnv(HSM_L2_RtCtxType *pCtx)
{
    pCtx->eOperation = HSM_LEVEL_2ND_OP_NONE;
}

HSM_StatusType HSM_L2_GetPoll(HSM_L2_RtCtxType *pL2Ctx, HSM_L1_RtCtxType *pL1Ctx, hsm_uint32_t u32TimeoutMs)
{
    HSM_StatusType eRet;

    switch (pL2Ctx->eOperation)
    {
        case HSM_LEVEL_2ND_OP_CMAC_EMPTY:
        {
            eRet = HSM_L2_CMacEmptyPoll(pL2Ctx, pL1Ctx, u32TimeoutMs);
        }
        break;

        case HSM_LEVEL_2ND_OP_UPDATE_KEY:
        {
            eRet = HSM_L2_UpdateKeyPoll(pL2Ctx, pL1Ctx, u32TimeoutMs);
        }
        break;

        case HSM_LEVEL_2ND_OP_REVOKE_KEY:
        {
            eRet = HSM_L2_RevokeKeyPoll(pL2Ctx, pL1Ctx, u32TimeoutMs);
        }
        break;

        case HSM_LEVEL_2ND_OP_ECC_VERIFY:
        {
            eRet = HSM_L2_EccVerifyPoll(pL2Ctx, pL1Ctx, u32TimeoutMs);
        }
        break;

        case HSM_LEVEL_2ND_OP_SM2_VERIFY:
        {
            eRet = HSM_L2_Sm2VerifyPoll(pL2Ctx, pL1Ctx, u32TimeoutMs);
        }
        break;


        default:
        {
            eRet = HSM_STATUS_ERROR;
        }
        break;
    }

    return eRet;
}


