/**
*   @file    Crypto_LevelNApi.c
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
HSM_StatusType HSM_L1_PKCS1_GetRsaPrivateKeyInfFromDer(const hsm_uint8_t *pDer, HSM_L1_PKCS_RsaPrivateKeyInfType *pInf);
HSM_StatusType HSM_L1_PKCS1_GetEccPrivateKeyInfFromDer(const hsm_uint8_t *pDer, HSM_L1_PKCS_EccPrivateKeyInfType *pInf);
HSM_StatusType HSM_L1_PKCS8_GetPrivateKeyInfFromDer(const hsm_uint8_t *pDer, HSM_L1_PKCS8_PrivateKeyInfType *pInf);
HSM_StatusType HSM_L1_PKCS1_GetRsaPublicKeyInfFromDer(const hsm_uint8_t *pDer, HSM_L1_PKCS_RsaPublicKeyInfType *pInf);
HSM_StatusType hsm_l1_subjectpublicinfo_bitstring_geteccpublickeyinf(const hsm_uint8_t *pDer, HSM_L1_PKCS_EccPublicKeyInfType *pInf);
HSM_StatusType HSM_L1_SubjectPublicInfo_GetPublicKeyInfFromDer(const hsm_uint8_t *pDer, HSM_L1_PublicKeyInfType *pInf);
HSM_StatusType HSM_L1_GetPoll(HSM_L1_RtCtxType *pCtx);
void HSM_L1_Ack_IrqHandler(void *pUpperCtx, HSM_StatusType eRet);

/********************************************* Level2 function *********************************************************/
HSM_StatusType hsm_l2_cmac_empty_process(HSM_L2_RtCtxType *pL2Ctx, HSM_L1_RtCtxType *pL1Ctx, hsm_uint32_t u32TimeoutMs, HSM_L2_DrvCMacEmptyInfType *pCfg,
                                         HSM_StatusType eRetFromPrevious, HSM_TriggerSrcType bTriggerMode);
HSM_StatusType hsm_l2_revoke_key_process(HSM_L2_RtCtxType *pL2Ctx, HSM_L1_RtCtxType *pL1Ctx, hsm_uint32_t u32TimeoutMs, HSM_L2_DrvRevokeKeyInfType *pCfg,
                                         HSM_StatusType eRetFromPrevious, HSM_TriggerSrcType bTriggerMode);
HSM_StatusType hsm_l2_ecc_verify_process(HSM_L2_RtCtxType *pL2Ctx, HSM_L1_RtCtxType *pL1Ctx, hsm_uint32_t u32TimeoutMs, HSM_L2_DrvEccVerifyInfType *pCfg,
                                         HSM_StatusType eRetFromPrevious, HSM_TriggerSrcType bTriggerMode);

HSM_StatusType HSM_L2_CMacEmptySetupEnv(HSM_L2_RtCtxType *pL2Ctx, HSM_L1_RtCtxType *pL1Ctx);
HSM_StatusType HSM_L2_CMacEmptyReset(HSM_L2_RtCtxType *pL2Ctx, HSM_L1_RtCtxType *pL1Ctx);
HSM_StatusType HSM_L2_CMacEmptyExitEnv(HSM_L2_RtCtxType *pL2Ctx, HSM_L1_RtCtxType *pL1Ctx);
HSM_StatusType hsm_l2_cmac_empty_process(HSM_L2_RtCtxType *pL2Ctx, HSM_L1_RtCtxType *pL1Ctx, hsm_uint32_t u32TimeoutMs,
                                         HSM_L2_DrvCMacEmptyInfType *pCfg, HSM_StatusType eRetFromPrevious, HSM_TriggerSrcType bTriggerMode);
HSM_StatusType HSM_L2_CMacEmpty(HSM_L2_RtCtxType *pL2Ctx, HSM_L1_RtCtxType *pL1Ctx, const HSM_Ln_CMacCfgParmsType *pKeyCfg, const HSM_Ln_ResultBufInfoType *pResult,
                                hsm_uint32_t u32TimeoutMs);
HSM_StatusType HSM_L2_CMacEmptyPoll(HSM_L2_RtCtxType *pL2Ctx, HSM_L1_RtCtxType *pL1Ctx, hsm_uint32_t u32TimeoutMs);
#if (FC7XXX_HSM_SUBSYSTEM_TYPE == FC7240_HSM_SUBSYSTEM) || (FC7XXX_HSM_SUBSYSTEM_TYPE == FC7300_HSM_SUBSYSTEM)
HSM_StatusType hsm_l2_update_key_process(HSM_L2_RtCtxType *pL2Ctx, HSM_L1_RtCtxType *pL1Ctx, hsm_uint32_t u32TimeoutMs,
                                         HSM_L2_DrvUpdateKeyInfType *pCfg, HSM_StatusType eRetFromPrevious, HSM_TriggerSrcType bTriggerMode);
#else
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

/********************************************* Level3 function *********************************************************/
HSM_StatusType HSM_L3_ScatterCMacSetupEnv(HSM_L3_RtCtxType *pL3Ctx, HSM_L2_RtCtxType *pL2Ctx, HSM_L1_RtCtxType *pL1Ctx);
HSM_StatusType HSM_L3_ScatterCMacReset(HSM_L3_RtCtxType *pL3Ctx, HSM_L2_RtCtxType *pL2Ctx, HSM_L1_RtCtxType *pL1Ctx);
HSM_StatusType HSM_L3_ScatterCMacExitEnv(HSM_L3_RtCtxType *pL3Ctx, HSM_L2_RtCtxType *pL2Ctx, HSM_L1_RtCtxType *pL1Ctx);
HSM_StatusType HSM_L3_ScatterCMacInit(HSM_L3_RtCtxType *pL3Ctx, HSM_L2_RtCtxType *pL2Ctx, HSM_L1_RtCtxType *pL1Ctx, const HSM_Ln_CMacCfgParmsType *pKeyCfg,
                                      const HSM_Ln_ScatterCMacType *pCfg, hsm_uint32_t u32TimeoutMs);
HSM_StatusType HSM_L3_ScatterCMacUpdate(HSM_L3_RtCtxType *pL3Ctx, HSM_L2_RtCtxType *pL2Ctx, HSM_L1_RtCtxType *pL1Ctx, const HSM_Ln_ScatterCMacType *pCfg,
                                        hsm_uint32_t u32TimeoutMs);
HSM_StatusType HSM_L3_ScatterCMacFinal(HSM_L3_RtCtxType *pL3Ctx, HSM_L2_RtCtxType *pL2Ctx, HSM_L1_RtCtxType *pL1Ctx, const HSM_Ln_ScatterCMacType *pCfg,
                                       const HSM_Ln_ResultBufInfoType *pResult, hsm_uint32_t u32TimeoutMs);
HSM_StatusType HSM_L3_ScatterCMacPoll(HSM_L3_RtCtxType *pL3Ctx, HSM_L2_RtCtxType *pL2Ctx, HSM_L1_RtCtxType *pL1Ctx, hsm_uint32_t u32TimeoutMs);
HSM_StatusType HSM_L3_UpdateKeySetupEnv(HSM_L3_RtCtxType *pL3Ctx, HSM_L2_RtCtxType *pL2Ctx, HSM_L1_RtCtxType *pL1Ctx);
HSM_StatusType HSM_L3_UpdateKeyReset(HSM_L3_RtCtxType *pL3Ctx, HSM_L2_RtCtxType *pL2Ctx, HSM_L1_RtCtxType *pL1Ctx);
HSM_StatusType HSM_L3_UpdateKeyExitEnv(HSM_L3_RtCtxType *pL3Ctx, HSM_L2_RtCtxType *pL2Ctx, HSM_L1_RtCtxType *pL1Ctx);
void hsm_core_padding_and_swap_array(
            hsm_uint32_t *pAlignedDest, hsm_uint32_t u32DestOpWordCnt, const void *pSrcData,
            hsm_uint32_t u32SrcOpByteCnt, HSM_DataFormatType eSrcFmt, hsm_uint8_t u8PadByte, HSM_BoolType bPadFromMSB, HSM_BoolType bSwap);
void hsm_pkam_u32_array_append_zero_from_left(hsm_uint8_t *pDest, const hsm_uint8_t *pSrc, hsm_uint32_t u32SrcByteCnt, hsm_uint32_t u32ZeroByteCnt);
const hsm_uint32_t *hsm_pkam_get_loadable_buf(HSM_DataFormatType eInputFmt, hsm_uint32_t *pCacheBufferMayUse,
                                              hsm_uint32_t u32LastCacheByteCnt, const hsm_uint32_t *pSrc, hsm_uint32_t u32SrcByteCnt, hsm_uint32_t u32LoadByteCount);
HSM_StatusType HSM_L3_UpdatePlainKey(HSM_L3_RtCtxType *pL3Ctx, HSM_L2_RtCtxType *pL2Ctx, HSM_L1_RtCtxType *pL1Ctx,
                                     const HSM_Ln_PlainKeyImport *pPlainKey, hsm_uint32_t u32TimeoutMs);
HSM_StatusType HSM_L3_UpdateKeyPoll(HSM_L3_RtCtxType *pL3Ctx, HSM_L2_RtCtxType *pL2Ctx, HSM_L1_RtCtxType *pL1Ctx, hsm_uint32_t u32TimeoutMs);
void HSM_L3_Ack_IrqHandler(void *pUpperCtx, HSM_BoolType bErrorHappen, HSM_StatusType eRet);
void HSM_L3_Init(HSM_L3_RtCtxType *pCtx, HSM_L3_InitParmType *pParm);
void HSM_L3_CleanEnv(HSM_L3_RtCtxType *pCtx);
void HSM_L3_Abort(HSM_L3_RtCtxType *pCtx);
void HSM_L3_CommonExitEnv(HSM_L3_RtCtxType *pCtx);
HSM_StatusType HSM_L3_GetPoll(HSM_L3_RtCtxType *pL3Ctx, HSM_L2_RtCtxType *pL2Ctx, HSM_L1_RtCtxType *pL1Ctx, hsm_uint32_t u32TimeoutMs);

/********************************************* global API *********************************************************/
CRYPTO_TEXT_SECTION void HSM_Ln_Init(HSM_Ln_RtCtxType *pLnRt, HSM_Ln_InitParmType *pInitParm)
{
    union
    {
        HSM_L1_InitParmType tL1Parm;
        HSM_L2_InitParmType tL2Parm;
        HSM_L3_InitParmType tL3Parm;
    } tParm;

    tParm.tL1Parm.eTriggerSrc = pInitParm->eTriggerSrc;
    tParm.tL1Parm.pStopCb     = HSM_L2_Ack_IrqHandler;
    tParm.tL1Parm.pSendCmdCb  = pInitParm->pSendCmdCb;
    tParm.tL1Parm.pReadAckCb  = pInitParm->pReadAckCb;
    tParm.tL1Parm.pCancelCmdCb = pInitParm->pCancelCmdCb;
    tParm.tL1Parm.pCleanDCache = pInitParm->pCleanDCache;
    tParm.tL1Parm.pCleanAndFlushDcache = pInitParm->pCleanAndFlushDcache;

    HSM_L1_Init(&(pLnRt->tHsmL1Ctx), &tParm.tL1Parm);

    tParm.tL2Parm.pStopCb = HSM_L3_Ack_IrqHandler;
    HSM_L2_Init(&(pLnRt->tHsmL2Ctx), &tParm.tL2Parm);

    tParm.tL3Parm.pStopCb = pInitParm->pStopCb;
    HSM_L3_Init(&(pLnRt->tHsmL3Ctx), &tParm.tL3Parm);

    pLnRt->u32OpLimitMs = pInitParm->u32OpLimitMs;
}

CRYPTO_TEXT_SECTION void HSM_Ln_Ack_IrqHandler(HSM_Ln_RtCtxType *pLnCtx)
{
    HSM_L1_Ack_IrqHandler(pLnCtx, HSM_STATUS_SUCCESS);
}

CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_Abort(HSM_Ln_RtCtxType *pCtx)
{
    HSM_StatusType eRet;

    eRet = HSM_L1_Abort(&(pCtx->tHsmL1Ctx));
    HSM_L2_Abort(&(pCtx->tHsmL2Ctx));
    HSM_L3_Abort(&(pCtx->tHsmL3Ctx));

    return eRet;
}

CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_CommonExitEnv(HSM_Ln_RtCtxType *pCtx)
{
    HSM_StatusType eRet = HSM_STATUS_SUCCESS;

    eRet = HSM_L1_CommonExitEnv(&(pCtx->tHsmL1Ctx));
    HSM_L2_CommonExitEnv(&(pCtx->tHsmL2Ctx));
    HSM_L3_CommonExitEnv(&(pCtx->tHsmL3Ctx));

    return eRet;
}


CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_RsaSsaPssVerifySetupEnv(HSM_Ln_RtCtxType *pLnCtx, hsm_uint32_t u32RsaBitCnt)
{
    return HSM_L1_RsaSsaPssVerifySetupEnv(&(pLnCtx->tHsmL1Ctx), u32RsaBitCnt);
}

CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_RsaSsaPssVerify(HSM_Ln_RtCtxType *pLnCtx, const HSM_Ln_RsaSsaPssVerifyType *pCfg)
{
    return HSM_L1_RsaSsaPssVerify(&(pLnCtx->tHsmL1Ctx), pCfg, pLnCtx->u32OpLimitMs);
}

CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_RsaSsaPssVerifyPoll(HSM_Ln_RtCtxType *pLnCtx)
{
    return HSM_L1_RsaSsaPssVerifyPoll(&(pLnCtx->tHsmL1Ctx));
}


CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_RsaSsaPssVerifyExitEnv(HSM_Ln_RtCtxType *pLnCtx)
{
    return HSM_L1_RsaSsaPssVerifyExitEnv(&(pLnCtx->tHsmL1Ctx));
}

CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_RsaSsaPkcs1v15VerifySetupEnv(HSM_Ln_RtCtxType *pLnCtx, hsm_uint32_t u32RsaBitCnt)
{
    return HSM_L1_RsaSsaPkcs1V15VerifySetupEnv(&(pLnCtx->tHsmL1Ctx), u32RsaBitCnt);
}

CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_RsaSsaPkcs1v15Verify(HSM_Ln_RtCtxType *pLnCtx, const HSM_Ln_RsaSsaPkcs1v15VerifyType *pCfg)
{
    return HSM_L1_RsaSsaPkcs1V15Verify(&(pLnCtx->tHsmL1Ctx), pCfg, pLnCtx->u32OpLimitMs);
}

CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_RsaSsaPkcs1v15VerifyPoll(HSM_Ln_RtCtxType *pLnCtx)
{
    return HSM_L1_RsaSsaPkcs1V15VerifyPoll(&(pLnCtx->tHsmL1Ctx));
}

CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_RsaSsaPkcs1v15VerifyExitEnv(HSM_Ln_RtCtxType *pLnCtx)
{
    return HSM_L1_RsaSsaPkcs1V15VerifyExitEnv(&(pLnCtx->tHsmL1Ctx));
}


CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_ShaSetupEnv(HSM_Ln_RtCtxType *pLnCtx)
{
    return HSM_L1_ShaSetupEnv(&(pLnCtx->tHsmL1Ctx));
}

CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_ShaExitEnv(HSM_Ln_RtCtxType *pLnCtx)
{
    return HSM_L1_ShaExitEnv(&(pLnCtx->tHsmL1Ctx));
}

CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_Sha(HSM_Ln_RtCtxType *pLnCtx, const HSM_Ln_ShaType *pSha)
{
    return HSM_L1_Sha(&(pLnCtx->tHsmL1Ctx), pSha, pLnCtx->u32OpLimitMs);
}

CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_ShaPoll(HSM_Ln_RtCtxType *pLnCtx)
{
    return HSM_L1_ShaPoll(&(pLnCtx->tHsmL1Ctx));
}


CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_AesEncryptSetupEnv(HSM_Ln_RtCtxType *pLnCtx)
{
    return HSM_L1_AesEncryptSetupEnv(&(pLnCtx->tHsmL1Ctx));
}

CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_AesEncryptExitEnv(HSM_Ln_RtCtxType *pLnCtx)
{
    return HSM_L1_AesEncryptExitEnv(&(pLnCtx->tHsmL1Ctx));
}

CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_AesEncrypt(HSM_Ln_RtCtxType *pLnCtx, const HSM_Ln_AesEncryptType *pCfg)
{
    return HSM_L1_AesEncrypt(&(pLnCtx->tHsmL1Ctx), pCfg, pLnCtx->u32OpLimitMs);
}

CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_AesEncryptPoll(HSM_Ln_RtCtxType *pLnCtx)
{
    return HSM_L1_AesEncryptPoll(&(pLnCtx->tHsmL1Ctx));
}


CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_AesDecryptSetupEnv(HSM_Ln_RtCtxType *pLnCtx)
{
    return HSM_L1_AesDecryptSetupEnv(&(pLnCtx->tHsmL1Ctx));
}

CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_AesDecryptExitEnv(HSM_Ln_RtCtxType *pLnCtx)
{
    return HSM_L1_AesDecryptExitEnv(&(pLnCtx->tHsmL1Ctx));
}

CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_AesDecrypt(HSM_Ln_RtCtxType *pLnCtx, const HSM_Ln_AesDecryptType *pCfg)
{
    return HSM_L1_AesDecrypt(&(pLnCtx->tHsmL1Ctx), pCfg, pLnCtx->u32OpLimitMs);
}

CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_AesDecryptPoll(HSM_Ln_RtCtxType *pLnCtx)
{
    return HSM_L1_AesDecryptPoll(&(pLnCtx->tHsmL1Ctx));
}

CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_Md5SetupEnv(HSM_Ln_RtCtxType *pLnCtx)
{
    return HSM_L1_Md5SetupEnv(&(pLnCtx->tHsmL1Ctx));
}

CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_Md5ExitEnv(HSM_Ln_RtCtxType *pLnCtx)
{
    return HSM_L1_Md5ExitEnv(&(pLnCtx->tHsmL1Ctx));
}

CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_Md5(HSM_Ln_RtCtxType *pLnCtx, const HSM_Ln_Md5Type *pCfg)
{
    return HSM_L1_Md5(&(pLnCtx->tHsmL1Ctx), pCfg, pLnCtx->u32OpLimitMs);
}

CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_Md5Poll(HSM_Ln_RtCtxType *pLnCtx)
{
    return HSM_L1_Md5Poll(&(pLnCtx->tHsmL1Ctx));
}

CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_Sm3SetupEnv(HSM_Ln_RtCtxType *pLnCtx)
{
    return HSM_L1_Sm3SetupEnv(&(pLnCtx->tHsmL1Ctx));
}

CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_Sm3ExitEnv(HSM_Ln_RtCtxType *pLnCtx)
{
    return HSM_L1_Sm3ExitEnv(&(pLnCtx->tHsmL1Ctx));
}

CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_Sm3(HSM_Ln_RtCtxType *pLnCtx, const HSM_Ln_Sm3Type *pCfg)
{
    return HSM_L1_Sm3(&(pLnCtx->tHsmL1Ctx), pCfg, pLnCtx->u32OpLimitMs);
}

CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_Sm3Poll(HSM_Ln_RtCtxType *pLnCtx)
{
    return HSM_L1_Sm3Poll(&(pLnCtx->tHsmL1Ctx));
}


CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_Sm4EncryptSetupEnv(HSM_Ln_RtCtxType *pLnCtx)
{
    return HSM_L1_Sm4EncryptSetupEnv(&(pLnCtx->tHsmL1Ctx));
}

CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_Sm4EncryptExitEnv(HSM_Ln_RtCtxType *pLnCtx)
{
    return HSM_L1_Sm4EncryptExitEnv(&(pLnCtx->tHsmL1Ctx));
}

CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_Sm4Encrypt(HSM_Ln_RtCtxType *pLnCtx, const HSM_Ln_Sm4EncryptType *pCfg)
{
    return HSM_L1_Sm4Encrypt(&(pLnCtx->tHsmL1Ctx), pCfg, pLnCtx->u32OpLimitMs);
}

CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_Sm4EncryptPoll(HSM_Ln_RtCtxType *pLnCtx)
{
    return HSM_L1_Sm4EncryptPoll(&(pLnCtx->tHsmL1Ctx));
}


CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_Sm4DecryptSetupEnv(HSM_Ln_RtCtxType *pLnCtx)
{
    return HSM_L1_Sm4DecryptSetupEnv(&(pLnCtx->tHsmL1Ctx));
}

CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_Sm4DecryptExitEnv(HSM_Ln_RtCtxType *pLnCtx)
{
    return HSM_L1_Sm4DecryptExitEnv(&(pLnCtx->tHsmL1Ctx));
}

CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_Sm4Decrypt(HSM_Ln_RtCtxType *pLnCtx, const HSM_Ln_Sm4DecryptType *pCfg)
{
    return HSM_L1_Sm4Decrypt(&(pLnCtx->tHsmL1Ctx), pCfg, pLnCtx->u32OpLimitMs);
}

CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_Sm4DecryptPoll(HSM_Ln_RtCtxType *pLnCtx)
{
    return HSM_L1_Sm4DecryptPoll(&(pLnCtx->tHsmL1Ctx));
}


CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_EccDecryptSetupEnv(HSM_Ln_RtCtxType *pLnCtx, hsm_uint32_t u32BitCnt)
{
    return HSM_L1_EccDecryptSetupEnv(&(pLnCtx->tHsmL1Ctx), u32BitCnt);
}

CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_EccDecryptExitEnv(HSM_Ln_RtCtxType *pLnCtx)
{
    return HSM_L1_EccDecryptExitEnv(&(pLnCtx->tHsmL1Ctx));
}

CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_EccDecrypt(HSM_Ln_RtCtxType *pLnCtx, const HSM_Ln_EccDecryptType *pCfg)
{
    return HSM_L1_EccDecrypt(&(pLnCtx->tHsmL1Ctx), pCfg, pLnCtx->u32OpLimitMs);
}

CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_EccDecryptPoll(HSM_Ln_RtCtxType *pLnCtx)
{
    return HSM_L1_EccDecryptPoll(&(pLnCtx->tHsmL1Ctx));
}


CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_EccVerifySetupEnv(HSM_Ln_RtCtxType *pLnCtx, hsm_uint32_t u32BitCnt)
{
    return HSM_L2_EccVerifySetupEnv(&(pLnCtx->tHsmL2Ctx), &(pLnCtx->tHsmL1Ctx), u32BitCnt);
}

CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_EccVerifyExitEnv(HSM_Ln_RtCtxType *pLnCtx)
{
    return HSM_L2_EccVerifyExitEnv(&(pLnCtx->tHsmL2Ctx), &(pLnCtx->tHsmL1Ctx));
}

CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_EccVerify(HSM_Ln_RtCtxType *pLnCtx, const HSM_Ln_EccVerifyType *pCfg)
{
    return HSM_L2_EccVerify(&(pLnCtx->tHsmL2Ctx), &(pLnCtx->tHsmL1Ctx), pCfg, pLnCtx->u32OpLimitMs);
}

CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_EccVerifyPoll(HSM_Ln_RtCtxType *pLnCtx)
{
    return HSM_L2_EccVerifyPoll(&(pLnCtx->tHsmL2Ctx), &(pLnCtx->tHsmL1Ctx), pLnCtx->u32OpLimitMs);
}

CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_CMacSetupEnv(HSM_Ln_RtCtxType *pLnCtx)
{
    return HSM_L1_CMacSetupEnv(&(pLnCtx->tHsmL1Ctx));
}

CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_CMacExitEnv(HSM_Ln_RtCtxType *pLnCtx)
{
    return HSM_L1_CMacExitEnv(&(pLnCtx->tHsmL1Ctx));
}

CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_CMac(HSM_Ln_RtCtxType *pLnCtx, const HSM_Ln_CMacType *pCfg)
{
    return HSM_L1_CMac(&(pLnCtx->tHsmL1Ctx), pCfg, pLnCtx->u32OpLimitMs);
}

CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_CMacPoll(HSM_Ln_RtCtxType *pLnCtx)
{
    return HSM_L1_CMacPoll(&(pLnCtx->tHsmL1Ctx));
}


CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_RngSetupEnv(HSM_Ln_RtCtxType *pLnCtx)
{
    return HSM_L1_RngSetupEnv(&(pLnCtx->tHsmL1Ctx));
}

CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_RngExitEnv(HSM_Ln_RtCtxType *pLnCtx)
{
    return HSM_L1_RngExitEnv(&(pLnCtx->tHsmL1Ctx));
}

CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_Rng(HSM_Ln_RtCtxType *pLnCtx, const HSM_Ln_RngType *pCfg)
{
    return HSM_L1_Rng(&(pLnCtx->tHsmL1Ctx), pCfg, pLnCtx->u32OpLimitMs);
}

CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_RngPoll(HSM_Ln_RtCtxType *pLnCtx)
{
    return HSM_L1_RngPoll(&(pLnCtx->tHsmL1Ctx));
}


CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_ScatterCMacSetupEnv(HSM_Ln_RtCtxType *pLnCtx)
{
    return HSM_L3_ScatterCMacSetupEnv(&(pLnCtx->tHsmL3Ctx), &(pLnCtx->tHsmL2Ctx), &(pLnCtx->tHsmL1Ctx));
}

CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_ScatterCMacExitEnv(HSM_Ln_RtCtxType *pLnCtx)
{
    return HSM_L3_ScatterCMacExitEnv(&(pLnCtx->tHsmL3Ctx), &(pLnCtx->tHsmL2Ctx), &(pLnCtx->tHsmL1Ctx));
}

CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_ScatterCMacPoll(HSM_Ln_RtCtxType *pLnCtx)
{
    return HSM_L3_ScatterCMacPoll(&(pLnCtx->tHsmL3Ctx), &(pLnCtx->tHsmL2Ctx), &(pLnCtx->tHsmL1Ctx), pLnCtx->u32OpLimitMs);
}


CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_ScatterCMacInit(HSM_Ln_RtCtxType *pLnCtx, const HSM_Ln_CMacCfgParmsType *pParmCfg, const HSM_Ln_ScatterCMacType *pCfg)
{
    return HSM_L3_ScatterCMacInit(&(pLnCtx->tHsmL3Ctx), &(pLnCtx->tHsmL2Ctx), &(pLnCtx->tHsmL1Ctx), pParmCfg, pCfg, pLnCtx->u32OpLimitMs);
}

CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_ScatterCMacUpdate(HSM_Ln_RtCtxType *pLnCtx, const HSM_Ln_ScatterCMacType *pCfg)
{
    return HSM_L3_ScatterCMacUpdate(&(pLnCtx->tHsmL3Ctx), &(pLnCtx->tHsmL2Ctx), &(pLnCtx->tHsmL1Ctx), pCfg, pLnCtx->u32OpLimitMs);
}

CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_ScatterCMacFinal(HSM_Ln_RtCtxType *pLnCtx, const HSM_Ln_ScatterCMacType *pCfg, const HSM_Ln_ResultBufInfoType *pResult)
{
    return HSM_L3_ScatterCMacFinal(&(pLnCtx->tHsmL3Ctx), &(pLnCtx->tHsmL2Ctx), &(pLnCtx->tHsmL1Ctx), pCfg, pResult, pLnCtx->u32OpLimitMs);
}


CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_ScatterHashSetupEnv(HSM_Ln_RtCtxType *pLnCtx)
{
    return HSM_L1_ScatterHashSetupEnv(&(pLnCtx->tHsmL1Ctx));
}

CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_ScatterHashExitEnv(HSM_Ln_RtCtxType *pLnCtx)
{
    return HSM_L1_ScatterHashExitEnv(&(pLnCtx->tHsmL1Ctx));
}

CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_ScatterHashPoll(HSM_Ln_RtCtxType *pLnCtx)
{
    return HSM_L1_ScatterHashPoll(&(pLnCtx->tHsmL1Ctx));
}

CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_ScatterHashSetMacCfg(HSM_Ln_RtCtxType *pLnCtx, HSM_Ln_HashMacCfgType *pCfg)
{
    return HSM_L1_ScatterHashSetMacCfg(&(pLnCtx->tHsmL1Ctx), pCfg);
}

CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_ScatterHashInit(HSM_Ln_RtCtxType *pLnCtx, const HSM_ShaAlgType eAlg, const HSM_Ln_ScatterHashType *pCfg)
{
    return HSM_L1_ScatterHashInit(&(pLnCtx->tHsmL1Ctx), eAlg, pCfg, pLnCtx->u32OpLimitMs);
}

CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_ScatterHashUpdate(HSM_Ln_RtCtxType *pLnCtx, const HSM_Ln_ScatterHashType *pCfg)
{
    return HSM_L1_ScatterHashUpdate(&(pLnCtx->tHsmL1Ctx),  pCfg, pLnCtx->u32OpLimitMs);
}

CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_ScatterHashFinal(HSM_Ln_RtCtxType *pLnCtx, const HSM_Ln_ScatterHashType *pCfg, const HSM_Ln_ResultBufInfoType *pResult)
{
    return HSM_L1_ScatterHashFinal(&(pLnCtx->tHsmL1Ctx),  pCfg, pResult, pLnCtx->u32OpLimitMs);
}

CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_EccSignSetupEnv(HSM_Ln_RtCtxType *pLnCtx, hsm_uint32_t u32BitCnt)
{
    return HSM_L1_EccSignSetupEnv(&(pLnCtx->tHsmL1Ctx), u32BitCnt);
}

CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_EccSignExitEnv(HSM_Ln_RtCtxType *pLnCtx)
{
    return HSM_L1_EccSignExitEnv(&(pLnCtx->tHsmL1Ctx));
}

CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_EccSign(HSM_Ln_RtCtxType *pLnCtx, const HSM_Ln_EccSignType *pCfg)
{
    return HSM_L1_EccSign(&(pLnCtx->tHsmL1Ctx), pCfg, pLnCtx->u32OpLimitMs);
}

CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_EccSignPoll(HSM_Ln_RtCtxType *pLnCtx)
{
    return HSM_L1_EccSignPoll(&(pLnCtx->tHsmL1Ctx));
}

CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_KeyImportSetupEnv(HSM_Ln_RtCtxType *pLnCtx)
{
    return HSM_L1_KeyImportSetupEnv(&(pLnCtx->tHsmL1Ctx));
}

CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_KeyImport(HSM_Ln_RtCtxType *pLnCtx, const HSM_Ln_ImportUserKeyExtType *pCfg)
{
    return HSM_L1_KeyImport(&(pLnCtx->tHsmL1Ctx), pCfg, pLnCtx->u32OpLimitMs);
}

CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_KeyImportExitEnv(HSM_Ln_RtCtxType *pLnCtx)
{
    return HSM_L1_KeyImportExitEnv(&(pLnCtx->tHsmL1Ctx));
}

#if ((FC7XXX_HSM_SUBSYSTEM_TYPE == FC7240_HSM_SUBSYSTEM) || (FC7XXX_HSM_SUBSYSTEM_TYPE == FC7300_HSM_SUBSYSTEM))

CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_KeyValidateSetupEnv(HSM_Ln_RtCtxType *pLnCtx)
{
    return HSM_L1_KeyValidateSetupEnv(&(pLnCtx->tHsmL1Ctx));
}

CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_KeyValidate(HSM_Ln_RtCtxType *pLnCtx, hsm_uint32_t u32KeyId)
{
    return HSM_L1_KeyValidate(&(pLnCtx->tHsmL1Ctx), u32KeyId, pLnCtx->u32OpLimitMs);
}

CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_KeyValidateExitEnv(HSM_Ln_RtCtxType *pLnCtx)
{
    return HSM_L1_KeyValidateExitEnv(&(pLnCtx->tHsmL1Ctx));
}

#endif

CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_KeyCopySetupEnv(HSM_Ln_RtCtxType *pLnCtx)
{
    return HSM_L1_KeyCopySetupEnv(&(pLnCtx->tHsmL1Ctx));
}

CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_KeyCopy(HSM_Ln_RtCtxType *pLnCtx, const HSM_Ln_CopyUserKeyType *pCfg)
{
    return HSM_L1_KeyCopy(&(pLnCtx->tHsmL1Ctx), pCfg, pLnCtx->u32OpLimitMs);
}

CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_KeyCopyExitEnv(HSM_Ln_RtCtxType *pLnCtx)
{
    return HSM_L1_KeyCopyExitEnv(&(pLnCtx->tHsmL1Ctx));
}

CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_KeyRevokeSetupEnv(HSM_Ln_RtCtxType *pLnCtx)
{
    return HSM_L1_KeyRevokeSetupEnv(&(pLnCtx->tHsmL1Ctx));
}

CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_KeyRevoke(HSM_Ln_RtCtxType *pLnCtx, hsm_uint32_t u32KeyId)
{
    return HSM_L1_KeyRevoke(&(pLnCtx->tHsmL1Ctx), u32KeyId, pLnCtx->u32OpLimitMs);
}

CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_KeyRevokeExitEnv(HSM_Ln_RtCtxType *pLnCtx)
{
    return HSM_L1_KeyRevokeExitEnv(&(pLnCtx->tHsmL1Ctx));
}

CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_KeySpaceTidyUpSetupEnv(HSM_Ln_RtCtxType *pLnCtx)
{
    return HSM_L1_KeySpaceTidyUpSetupEnv(&(pLnCtx->tHsmL1Ctx));
}

CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_KeySpaceTidyUp(HSM_Ln_RtCtxType *pLnCtx, HSM_Ln_KeySpaceStatusType *pCfg)
{
    return HSM_L1_KeySpaceTidyUp(&(pLnCtx->tHsmL1Ctx), pCfg, pLnCtx->u32OpLimitMs);
}

CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_KeySpaceTidyUpExitEnv(HSM_Ln_RtCtxType *pLnCtx)
{
    return HSM_L1_KeySpaceTidyUpExitEnv(&(pLnCtx->tHsmL1Ctx));
}

CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_UpdateKeySetupEnv(HSM_Ln_RtCtxType *pLnCtx)
{
    return HSM_L3_UpdateKeySetupEnv(&(pLnCtx->tHsmL3Ctx), &(pLnCtx->tHsmL2Ctx), &(pLnCtx->tHsmL1Ctx));
}

CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_UpdateKey(HSM_Ln_RtCtxType *pLnCtx, const HSM_Ln_PlainKeyImport *pCfg)
{
    return HSM_L3_UpdatePlainKey(&(pLnCtx->tHsmL3Ctx), &(pLnCtx->tHsmL2Ctx), &(pLnCtx->tHsmL1Ctx), pCfg, pLnCtx->u32OpLimitMs);
}

CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_UpdateKeyExitEnv(HSM_Ln_RtCtxType *pLnCtx)
{
    return HSM_L3_UpdateKeyExitEnv(&(pLnCtx->tHsmL3Ctx), &(pLnCtx->tHsmL2Ctx), &(pLnCtx->tHsmL1Ctx));
}

CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_RevokeKeySetupEnv(HSM_Ln_RtCtxType *pLnCtx)
{
    return HSM_L2_RevokeKeySetupEnv(&(pLnCtx->tHsmL2Ctx), &(pLnCtx->tHsmL1Ctx));
}

CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_RevokeKey(HSM_Ln_RtCtxType *pLnCtx, hsm_uint32_t u32KeyId)
{
    return HSM_L2_RevokeKey(&(pLnCtx->tHsmL2Ctx), &(pLnCtx->tHsmL1Ctx), u32KeyId, pLnCtx->u32OpLimitMs);
}

CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_RevokeKeyExitEnv(HSM_Ln_RtCtxType *pLnCtx)
{
    return HSM_L2_RevokeKeyExitEnv(&(pLnCtx->tHsmL2Ctx), &(pLnCtx->tHsmL1Ctx));
}


CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_RsaSsaPkcs1V15SignSetupEnv(HSM_Ln_RtCtxType *pCtx)
{
    return HSM_L1_RsaSsaPkcs1V15SignSetupEnv(&(pCtx->tHsmL1Ctx));
}

CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_RsaSsaPkcs1V15SignData(HSM_Ln_RtCtxType *pCtx, const HSM_Ln_RsaSsaPkcs1V15SignDataType *pCfg, hsm_uint32_t u32TimeoutMs)
{
    HSM_StatusType eRet;

    HSM_Ln_RsaSsaPkcs1V15SignHashType tCfg;

    if (pCfg != NULL_PTR)
    {
        if (pCfg->u32InputDataByteCount > 0)
        {
            eRet = HSM_L1_RsaSsaPkcs1V15SignData(&(pCtx->tHsmL1Ctx), pCfg, u32TimeoutMs);
        }
        else
        {
            eRet = hsm_aux_get_empty_data_hash(pCfg->eHashType, &tCfg.pHashData, &tCfg.u32HashDataByteCount);
            if (HSM_STATUS_SUCCESS == eRet)
            {
                tCfg.u32RsaBitCnt           = pCfg->u32RsaBitCnt;
                tCfg.eInputFmt              = pCfg->eInputFmt;
                tCfg.eOutputFmt             = pCfg->eOutputFmt;
                tCfg.eHashType              = pCfg->eHashType;
                tCfg.u32PrivateKeyId        = pCfg->u32PrivateKeyId;
                tCfg.pPrivateKey            = pCfg->pPrivateKey;
                tCfg.u32PrivateKeyByteCnt   = pCfg->u32PrivateKeyByteCnt;
                tCfg.u32KeyNId              = pCfg->u32KeyNId;
                tCfg.pKeyN                  = pCfg->pKeyN;
                tCfg.u32KeyNByteCount       = pCfg->u32KeyNByteCount;
                tCfg.pResult                = pCfg->pResult;
                tCfg.u32ResultBufByteCnt    = pCfg->u32ResultBufByteCnt;
                tCfg.pResultByteCnt         = pCfg->pResultByteCnt;

                eRet = HSM_L1_RsaSsaPkcs1V15SignHash(&(pCtx->tHsmL1Ctx), &tCfg, u32TimeoutMs);
            }
            /* else do nothing */
        }
    }
    else
    {
        eRet = HSM_STATUS_PARAM_ERR;
    }

    return eRet;
}

CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_RsaSsaPkcs1V15SignHash(HSM_Ln_RtCtxType *pCtx, const HSM_Ln_RsaSsaPkcs1V15SignHashType *pCfg, hsm_uint32_t u32TimeoutMs)
{
    return HSM_L1_RsaSsaPkcs1V15SignHash(&(pCtx->tHsmL1Ctx), pCfg, u32TimeoutMs);
}

CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_RsaSsaPkcs1V15SignExitEnv(HSM_Ln_RtCtxType *pCtx)
{
    return HSM_L1_RsaSsaPkcs1V15SignExitEnv(&(pCtx->tHsmL1Ctx));
}


CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_RsaSsaPssSignSetupEnv(HSM_Ln_RtCtxType *pCtx)
{
    return HSM_L1_RsaSsaPssSignSetupEnv(&(pCtx->tHsmL1Ctx));
}

CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_RsaSsaPssSignData(HSM_Ln_RtCtxType *pCtx, const HSM_Ln_RsaSsaPssSignDataType *pCfg, hsm_uint32_t u32TimeoutMs)
{
    HSM_StatusType eRet;

    HSM_Ln_RsaSsaPssSignHashType tCfg;

    if (pCfg != NULL_PTR)
    {
        if (pCfg->u32InputDataByteCount > 0)
        {
            eRet = HSM_L1_RsaSsaPssSignData(&(pCtx->tHsmL1Ctx), pCfg, u32TimeoutMs);
        }
        else
        {
            eRet = hsm_aux_get_empty_data_hash(pCfg->eHashType, &tCfg.pHashData, &tCfg.u32HashDataByteCount);
            if (HSM_STATUS_SUCCESS == eRet)
            {
                tCfg.u32RsaBitCnt           = pCfg->u32RsaBitCnt;
                tCfg.bUsePseudoRand         = pCfg->bUsePseudoRand;
                tCfg.eInputFmt              = pCfg->eInputFmt;
                tCfg.eOutputFmt             = pCfg->eOutputFmt;
                tCfg.eHashType              = pCfg->eHashType;
                tCfg.u32PrivateKeyId        = pCfg->u32PrivateKeyId;
                tCfg.pPrivateKey            = pCfg->pPrivateKey;
                tCfg.u32PrivateKeyByteCnt   = pCfg->u32PrivateKeyByteCnt;
                tCfg.u32KeyNId              = pCfg->u32KeyNId;
                tCfg.pKeyN                  = pCfg->pKeyN;
                tCfg.u32KeyNByteCount       = pCfg->u32KeyNByteCount;
                tCfg.pResult                = pCfg->pResult;
                tCfg.u32ResultBufByteCnt    = pCfg->u32ResultBufByteCnt;
                tCfg.pResultByteCnt         = pCfg->pResultByteCnt;

                eRet = HSM_L1_RsaSsaPssSignHash(&(pCtx->tHsmL1Ctx), &tCfg, u32TimeoutMs);
            }
            /* else do nothing */
        }
    }
    else
    {
        eRet = HSM_STATUS_PARAM_ERR;
    }

    return eRet;
}

CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_RsaSsaPssSignHash(HSM_Ln_RtCtxType *pCtx, const HSM_Ln_RsaSsaPssSignHashType *pCfg, hsm_uint32_t u32TimeoutMs)
{
    return HSM_L1_RsaSsaPssSignHash(&(pCtx->tHsmL1Ctx), pCfg, u32TimeoutMs);
}

CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_RsaSsaPssSignExitEnv(HSM_Ln_RtCtxType *pCtx)
{
    return HSM_L1_RsaSsaPssSignExitEnv(&(pCtx->tHsmL1Ctx));
}

CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_Sm2VerifySetupEnv(HSM_Ln_RtCtxType *pLnCtx)
{
    return HSM_L2_Sm2VerifySetupEnv(&(pLnCtx->tHsmL2Ctx), &(pLnCtx->tHsmL1Ctx));
}

CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_Sm2VerifyExitEnv(HSM_Ln_RtCtxType *pLnCtx)
{
    return HSM_L2_Sm2VerifyExitEnv(&(pLnCtx->tHsmL2Ctx), &(pLnCtx->tHsmL1Ctx));
}

CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_Sm2Verify(HSM_Ln_RtCtxType *pLnCtx, const HSM_Ln_Sm2VerifyType *pCfg)
{
    return HSM_L2_Sm2Verify(&(pLnCtx->tHsmL2Ctx), &(pLnCtx->tHsmL1Ctx), pCfg, pLnCtx->u32OpLimitMs);
}

CRYPTO_TEXT_SECTION HSM_StatusType HSM_Ln_Sm2VerifyPoll(HSM_Ln_RtCtxType *pLnCtx)
{
    return HSM_L2_Sm2VerifyPoll(&(pLnCtx->tHsmL2Ctx), &(pLnCtx->tHsmL1Ctx), pLnCtx->u32OpLimitMs);
}

#ifdef CRYPTO_HSM_MCAL
    #define CRYPTO_STOP_SEC_CODE
    #include "Crypto_MemMap.h"
#endif
