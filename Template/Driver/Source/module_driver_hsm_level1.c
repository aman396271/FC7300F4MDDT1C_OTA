/**
 *   @file    Crypto_Level1Api.c
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
/********************************************* Level0 function
 * *********************************************************/
HSM_StatusType HSM_TrueRandGetSrc0(HSM_CmdType *pCmd, const HSMCom_TrueRandType *pCfg);
HSM_StatusType HSM_TrueRandGetSrc1(HSM_CmdType *pCmd, const HSMCom_TrueRandType *pCfg);
HSM_StatusType HSM_TrueRandGetSrcXor(HSM_CmdType *pCmd, const HSMCom_TrueRandType *pCfg);
HSM_StatusType HSM_TrueRandGetSrcShiftXor(HSM_CmdType *pCmd, const HSMCom_TrueRandType *pCfg);
HSM_StatusType HSM_TrueRandGet(HSM_CmdType *pCmd, const HSMCom_TrueRandExType *pCfg);
HSM_StatusType HSM_TrueRandGetAny(HSM_CmdType *pCmd, const HSMCom_TrueRandType *pCfg);
HSM_StatusType HSM_Sha(HSM_CmdType *pCmd, const HSMCom_ShaType *pCfg);
HSM_StatusType HSM_FW_ShaEx(HSM_CmdType *pCmd, const HSMCom_ShaExType *pCfg, HSM_BoolType bKeyUseId);
HSM_StatusType HSM_EccVerify(HSM_CmdType *pCmd, const HSMCom_EccVerifyType *pCfg);
HSM_StatusType HSM_EccCalculateEx(HSM_CmdType *pCmd, const HSMCom_EccCalcType *pCfg);
HSM_StatusType HSM_Sm2Decry(HSM_CmdType *pCmd, const HSMCom_Sm2DecryptType *pCfg);
HSM_StatusType HSM_Sm2Verify(HSM_CmdType *pCmd, const HSMCom_Sm2VerifyType *pCfg);
HSM_StatusType HSM_Sm2GenZa(HSM_CmdType *pCmd, const HSMCom_Sm2GenZaType *pCfg);
HSM_StatusType HSM_Sm2GenHash(HSM_CmdType *pCmd, const HSMCom_Sm2GenHashType *pCfg);
HSM_StatusType HSM_Sm4EncryptStart(HSM_CmdType            *pCmd,
                                   HSMWrap_Sm4EncryptType *pCtx,
                                   HSMCom_Sm4EncryptType  *pDecrypt);
HSM_StatusType HSM_Sm4EncryptUpdate(HSM_CmdType *pCmd, HSMWrap_Sm4EncryptType *pCtx);
HSM_StatusType HSM_Sm4DecryptEx(HSM_CmdType *pCmd, const HSMCom_Sm4DecryptExType *pCfg);
HSM_StatusType HSM_Sm4EncryptExStart(HSM_CmdType              *pCmd,
                                     HSMWrap_Sm4EncryptExType *pCtx,
                                     HSMCom_Sm4EncryptExType  *pCfg);
HSM_StatusType HSM_Sm4EncryptExUpdate(HSM_CmdType *pCmd, HSMWrap_Sm4EncryptExType *pCtx);
HSM_StatusType HSM_Sm4Decrypt(HSM_CmdType *pCmd, const HSMCom_Sm4DecryptType *pCfg);
HSM_StatusType HSM_EccEasyDecry(HSM_CmdType *pCmd, const HSMCom_EccEasyDecryType *pCfg);
HSM_StatusType HSM_RequestAuthorization(HSM_CmdType *pCmd, const HSMCom_RequestAuthType *pCfg);
HSM_StatusType HSM_LifeCycleTakeEffect(HSM_CmdType *pCmd, HSMCom_LifeCycleTakeEffectType *pCfg);
HSM_StatusType HSM_OemDevEnter(HSM_CmdType *pCmd, const HSMCom_AuthCheckType *pCfg);
HSM_StatusType HSM_OemPdtEnter(HSM_CmdType *pCmd, const HSMCom_AuthCheckType *pCfg);
HSM_StatusType HSM_InFieldEnter(HSM_CmdType *pCmd, const HSMCom_AuthCheckType *pCfg);
HSM_StatusType HSM_CancelJob(HSM_CmdType *pCmd, const HSMCom_CancelJobType *pCfg);
HSM_StatusType HSM_SelfTest(HSM_CmdType *pCmd, volatile HSMCom_SelfTestType *pCfg);
HSM_StatusType HSM_NvrOtpProgram(HSM_CmdType *pCmd, const HSMCom_NvrOtpType *pCfg);
HSM_StatusType HSM_NvrOtpRead(HSM_CmdType *pCmd, const HSMCom_NvrOtpType *pCfg);
HSM_StatusType HSM_UserKeyImport(HSM_CmdType *pCmd, const HSMCom_UserKeyManageType *pCfg);
HSM_StatusType HSM_UserKeyExport(HSM_CmdType *pCmd, const HSMCom_UserKeyManageType *pCfg);
HSM_StatusType HSM_GetKeySpaceStat(HSM_CmdType *pCmd, const HSMCom_KeySpaceStatusType *pCfg);
HSM_StatusType HSM_TidyUpKeySpace(HSM_CmdType *pCmd, const HSMCom_KeySpaceStatusType *pCfg);
HSM_StatusType HSM_UserKeyRevoke(HSM_CmdType *pCmd, const HSMCom_UserKeyManageType *pCfg);
HSM_StatusType HSM_AesEncrypt(HSM_CmdType *pCmd, const HSMCom_AesEncryptType *pCfg);
HSM_StatusType HSM_AesEncryptEx(HSM_CmdType *pCmd, const HSMCom_FlexAesEncryptType *pCfg);
HSM_StatusType HSM_AesDecrypt(HSM_CmdType *pCmd, const HSMCom_AesDecryptType *pCfg);
HSM_StatusType HSM_AesDecryptEx(HSM_CmdType *pCmd, const HSMCom_FlexAesDecryptType *pCfg);
HSM_StatusType HSM_CMac(HSM_CmdType *pCmd, const HSMCom_CMacType *pCfg);
HSM_StatusType HSM_CMacEx(HSM_CmdType *pCmd, const HSMCom_CMacExType *pCfg);
HSM_StatusType HSM_XMac(HSM_CmdType *pCmd, const HSMCom_XMacType *pCfg);
HSM_StatusType HSM_CcmEncry(HSM_CmdType *pCmd, const HSMCom_CcmEncryptType *pCfg);
HSM_StatusType HSM_CcmDecry(HSM_CmdType *pCmd, const HSMCom_CcmDecryptType *pCfg);
HSM_StatusType HSM_GcmEncry(HSM_CmdType *pCmd, const HSMCom_GcmEncryptType *pCfg);
HSM_StatusType HSM_GcmDecry(HSM_CmdType *pCmd, const HSMCom_GcmDecryptType *pCfg);
HSM_StatusType HSM_Md5(HSM_CmdType *pCmd, const HSMCom_Md5Type *pCfg);
HSM_StatusType HSM_FW_Md5Ex(HSM_CmdType *pCmd, const HSMCom_Md5ExType *pCfg, HSM_BoolType bKeyUseId);
HSM_StatusType HSM_Sm3(HSM_CmdType *pCmd, const HSMCom_Sm3Type *pCfg);
HSM_StatusType HSM_FW_Sm3Ex(HSM_CmdType *pCmd, const HSMCom_Sm3ExType *pCfg, HSM_BoolType bKeyUseId);
HSM_StatusType HSM_MonotonicCounterIncrease(HSM_CmdType *pCmd, const HSMCom_MonCountType *pCfg);
HSM_StatusType HSM_MonotonicCounterRead(HSM_CmdType *pCmd, const HSMCom_MonCountType *pCfg);
HSM_StatusType HSM_Rsa(HSM_CmdType *pCmd, const HSMCom_RsaType *pCfg);
HSM_StatusType HSM_BigNumberCalculateEx(HSM_CmdType *pCmd, const HSMCom_BigNumberCalcType *pCfg);
HSM_StatusType HSM_LoadFirmware(HSM_CmdType *pCmd, HSMCom_LoadFirmwareType *pCfg);
HSM_StatusType HSM_FW_ScatterHashInit(HSM_CmdType                  *pCmd,
                                      const HSMCom_ScatterHashType *pCfg,
                                      HSM_BoolType                  bKeyUseId,
                                      HSM_DataFormatType            eInputFmt);
HSM_StatusType HSM_FW_ScatterHashUpdate(HSM_CmdType                  *pCmd,
                                        const HSMCom_ScatterHashType *pCfg,
                                        HSM_BoolType                  bKeyUseId,
                                        HSM_DataFormatType            eInputFmt);
HSM_StatusType HSM_FW_ScatterHashFinal(HSM_CmdType                  *pCmd,
                                       const HSMCom_ScatterHashType *pCfg,
                                       HSM_BoolType                  bKeyUseId,
                                       HSM_DataFormatType            eInputFmt);
HSM_StatusType HSM_FW_EccEncrypt(HSM_CmdType *pCmd, const HSMCom_EccEasyEncryType *pCfg);
HSM_StatusType HSM_FW_UserKeyGenPair(HSM_CmdType *pCmd, const HSMCom_UserKeyManageType *pCfg);
HSM_StatusType HSM_FW_EccSign(HSM_CmdType *pCmd, const HSMCom_EccSignType *pCfg);
HSM_StatusType HSM_FW_Sm2GenKeyPair(HSM_CmdType *pCmd, const HSMCom_Sm2GenKeyPairType *pCfg);
HSM_StatusType HSM_FW_Sm2Encry(HSM_CmdType *pCmd, const HSMCom_Sm2EncryptType *pCfg);
HSM_StatusType HSM_FW_EccEncrypt(HSM_CmdType *pCmd, const HSMCom_EccEasyEncryType *pCfg);
HSM_StatusType HSM_FW_Sm2Sign(HSM_CmdType *pCmd, const HSMCom_Sm2SignType *pCfg);
HSM_StatusType HSM_FW_UserKeyRevoke(HSM_CmdType *pCmd, const HSMCom_UserKeyManageType *pCfg);
HSM_StatusType HSM_FW_ScatterCMacInit(HSM_CmdType                 *pCmd,
                                      const HSMCom_AesmRawApiType *pCfg,
                                      HSM_DataFormatType           eInputFmt,
                                      HSM_DataFormatType           eKeyFmt);
HSM_StatusType HSM_FW_ScatterCMacUpdate(HSM_CmdType                 *pCmd,
                                        const HSMCom_AesmRawApiType *pCfg,
                                        HSM_DataFormatType           eInputFmt,
                                        HSM_DataFormatType           eKeyFmt);
HSM_StatusType HSM_FW_ScatterCMacFinal(HSM_CmdType                 *pCmd,
                                       const HSMCom_AesmRawApiType *pCfg,
                                       HSM_DataFormatType           eInputFmt,
                                       HSM_DataFormatType           eKeyFmt);
HSM_StatusType HSM_FW_RsaSsaPssVerify(HSM_CmdType *pCmd, const HSMCom_RsaSsaPssVerifyType *pCfg);
HSM_StatusType HSM_FW_RsaSsaPkcs1v15Verify(HSM_CmdType                           *pCmd,
                                           const HSMCom_RsaSsaPkcs1V15VerifyType *pCfg);
HSM_StatusType HSM_FW_UserKeyImportNew(HSM_CmdType *pCmd, const HSMCom_UserKeyManageType *pCfg);
HSM_StatusType HSM_FW_CheckKeyIdExt(HSM_CmdType *pCmd, const HSMCom_UserKeyManageType *pCfg);
HSM_StatusType HSM_FW_CopyKeyExt(HSM_CmdType *pCmd, const HSMCom_UserKeyManageType *pCfg);
HSM_StatusType HSM_FW_BigNumberCalculateEx(HSM_CmdType                       *pCmd,
                                           const HSMCom_BigNumberCalcExtType *pCfg);
HSM_StatusType HSM_FW_RsaSsaPssSign(HSM_CmdType *pCmd, const HSMCom_RsaSsaPssSignType *pCfg);
HSM_StatusType HSM_FW_RsaSsaPkcs1v15Sign(HSM_CmdType                         *pCmd,
                                         const HSMCom_RsaSsaPkcs1v15SignType *pCfg);
#if ((FC7XXX_HSM_SUBSYSTEM_TYPE == FC7240_HSM_SUBSYSTEM) || \
     (FC7XXX_HSM_SUBSYSTEM_TYPE == FC7300_HSM_SUBSYSTEM))
HSM_StatusType HSM_FW_GetKeyIdStatus(HSM_CmdType *pCmd, const HSMCom_UserKeyManageType *pCfg);
#endif
#if ((FC7XXX_HSM_SUBSYSTEM_TYPE == FC7240_HSM_SUBSYSTEM) || \
     (FC7XXX_HSM_SUBSYSTEM_TYPE == FC7300_HSM_SUBSYSTEM))
#else
HSM_StatusType HSM_UpdateKeyContentOfSpecificKeyId(HSM_CmdType                    *pCmd,
                                                   const HSMCom_UserKeyManageType *pCfg);
#endif

/****************************************** Local function declarations
 * ***********************************************/
HSM_StatusType hsm_1B4B_convert_from_idx(HSM_DataFormatType eDstFmt,
                                         void              *pDst,
                                         hsm_uint32_t       u32DstStartIdx,
                                         hsm_uint32_t       u32DstBufByteSize,
                                         HSM_DataFormatType eSrcFmt,
                                         const void        *pSrc,
                                         hsm_uint32_t       u32SrcStartIdx,
                                         hsm_uint32_t       u32SrcStopIdx);
void           hsm_bidi_memcpy(void        *pDstMem,
                               const void  *pSrcMem,
                               hsm_uint32_t u32OpCnt,
                               hsm_int32_t  sOpDirection);
void           hsm_memcpy(void *pDstMem, const void *pSrcMem, hsm_uint32_t u32Cnt);
void           hsm_memset(void *pDstMem, hsm_uint8_t u8Val, hsm_uint32_t u32Cnt);
hsm_int32_t    hsm_memcmp(const void *pDst, const void *pSrc, hsm_uint32_t u32OpCnt);
HSM_StatusType hsm_hash_get_result_byte_count(HFAM_MODE_E eMode, hsm_uint32_t *pRetByteCnt);
void           hsm_u32_array_swap(hsm_uint32_t *pData, hsm_uint32_t u32WordCnt);
void hsm_u32_array_swap_to(hsm_uint32_t *pData, const hsm_uint32_t *pSrc, hsm_uint32_t u32WordCnt);
void hsm_rm_prefix_zeros(HSM_DataFormatType  eInputFmt,
                         const hsm_uint8_t  *pData,
                         hsm_uint32_t        u32ByteCount,
                         const hsm_uint8_t **ppActualData,
                         hsm_uint32_t       *pActualByteCnt);
void hsm_core_swap_u32_array_pad(hsm_uint32_t      *pAlignedDest,
                                 hsm_uint32_t       u32DestWordCnt,
                                 const hsm_uint8_t *pSrc,
                                 hsm_uint32_t       u32SrcOpByteCnt,
                                 hsm_uint8_t        u8PadByte,
                                 HSM_BoolType       bPadFromMSB,
                                 HSM_BoolType       bSwap);
void HSM_L1_CleanEnv(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_CommonExitEnv(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_Abort(HSM_L1_RtCtxType *pCtx);
void           HSM_L1_Init(HSM_L1_RtCtxType *pCtx, HSM_L1_InitParmType *pParm);
HSM_StatusType HSM_L1_Md5SetupEnv(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_Md5Reset(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_Md5ExitEnv(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_Md5(HSM_L1_RtCtxType     *pCtx,
                          const HSM_Ln_Md5Type *pCfg,
                          hsm_uint32_t          u32TimeoutMs);
HSM_StatusType HSM_L1_Md5_Isr(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_Md5Poll(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_Sm3SetupEnv(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_Sm3Reset(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_Sm3ExitEnv(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_Sm3(HSM_L1_RtCtxType     *pCtx,
                          const HSM_Ln_Sm3Type *pCfg,
                          hsm_uint32_t          u32TimeoutMs);
HSM_StatusType HSM_L1_Sm3_Isr(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_Sm3Poll(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_ShaSetupEnv(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_ShaReset(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_ShaExitEnv(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_Sha(HSM_L1_RtCtxType     *pCtx,
                          const HSM_Ln_ShaType *pCfg,
                          hsm_uint32_t          u32TimeoutMs);
HSM_StatusType HSM_L1_Sha_Isr(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_ShaPoll(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_RngSetupEnv(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_RngReset(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_RngExitEnv(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_Rng(HSM_L1_RtCtxType     *pCtx,
                          const HSM_Ln_RngType *pCfg,
                          hsm_uint32_t          u32TimeoutMs);
HSM_StatusType HSM_L1_Rng_Isr(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_RngPoll(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_EccVerifySetupEnv(HSM_L1_RtCtxType *pCtx, hsm_uint32_t u32BitCnt);
HSM_StatusType HSM_L1_EccVerifyExitEnv(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_EccVerify(HSM_L1_RtCtxType           *pCtx,
                                const HSM_L1_EccVerifyType *pCfg,
                                hsm_uint32_t                u32TimeoutMs);
HSM_StatusType HSM_L1_EccVerify_Isr(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_EccVerifyPoll(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_EccVerifyReset(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_EccDecryptSetupEnv(HSM_L1_RtCtxType *pCtx, hsm_uint32_t u32BitCnt);
HSM_StatusType HSM_L1_EccDecryptExitEnv(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_EccDecrypt(HSM_L1_RtCtxType            *pCtx,
                                 const HSM_Ln_EccDecryptType *pCfg,
                                 hsm_uint32_t                 u32TimeoutMs);
HSM_StatusType HSM_L1_EccDecrypt_Isr(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_EccDecryptPoll(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_EccDecryptReset(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_EccCalculateSetupEnv(HSM_L1_RtCtxType *pCtx, hsm_uint32_t u32BitCnt);
HSM_StatusType HSM_L1_EccCalculateExitEnv(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_EccCalculateKP(HSM_L1_RtCtxType       *pCtx,
                                     const HSM_Ln_EccKPType *pCfg,
                                     hsm_uint32_t            u32TimeoutMs);
HSM_StatusType HSM_L1_EccCalculate_Isr(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_EccCalculatePoll(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_EccCalculateReset(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_CMacSetupEnv(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_CMacReset(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_CMacExitEnv(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_CMac(HSM_L1_RtCtxType      *pCtx,
                           const HSM_Ln_CMacType *pCfg,
                           hsm_uint32_t           u32TimeoutMs);
HSM_StatusType HSM_L1_CMac_Isr(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_CMacPoll(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_AesEncryptSetupEnv(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_AesEncryptReset(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_AesEncryptExitEnv(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_AesEncrypt(HSM_L1_RtCtxType            *pCtx,
                                 const HSM_Ln_AesEncryptType *pCfg,
                                 hsm_uint32_t                 u32TimeoutMs);
HSM_StatusType HSM_L1_AesEncrypt_Isr(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_AesEncryptPoll(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_AesDecryptSetupEnv(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_AesDecryptReset(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_AesDecryptExitEnv(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_AesDecrypt(HSM_L1_RtCtxType            *pCtx,
                                 const HSM_Ln_AesDecryptType *pCfg,
                                 hsm_uint32_t                 u32TimeoutMs);
HSM_StatusType HSM_L1_AesDecrypt_Isr(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_AesDecryptPoll(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_Sm4EncryptSetupEnv(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_Sm4EncryptReset(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_Sm4EncryptExitEnv(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_Sm4Encrypt(HSM_L1_RtCtxType            *pCtx,
                                 const HSM_Ln_Sm4EncryptType *pCfg,
                                 hsm_uint32_t                 u32TimeoutMs);
HSM_StatusType HSM_L1_Sm4Encrypt_Isr(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_Sm4EncryptPoll(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_Sm4DecryptSetupEnv(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_Sm4DecryptReset(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_Sm4DecryptExitEnv(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_Sm4Decrypt(HSM_L1_RtCtxType            *pCtx,
                                 const HSM_Ln_Sm4DecryptType *pCfg,
                                 hsm_uint32_t                 u32TimeoutMs);
HSM_StatusType HSM_L1_Sm4Decrypt_Isr(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_Sm4DecryptPoll(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_BnCalcSetupEnv(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_BnCalcExitEnv(HSM_L1_RtCtxType *pCtx);
hsm_uint32_t   hsm_pkam_get_actual_size(HSM_DataFormatType  eDataFormat,
                                        const void         *pData,
                                        hsm_uint32_t        u32ByteCount,
                                        const hsm_uint8_t **ppLastNonZero);
HSM_StatusType hsm_pkam_get_bn_bit_count(HSM_DataFormatType eFmt,
                                         const hsm_uint8_t *pData,
                                         hsm_uint32_t       u32ByteCnt,
                                         hsm_uint32_t      *pBitCnt);
HSM_StatusType HSM_L1_BnCalc(HSM_L1_RtCtxType        *pCtx,
                             const HSM_L1_BnCalcType *pCfg,
                             hsm_uint32_t             u32TimeoutMs);
HSM_StatusType HSM_L1_BnCalc_Isr(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_BnCalcPoll(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_BnCalcReset(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_ScatterHashSetupEnv(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_ScatterHashSetMacCfg(HSM_L1_RtCtxType *pCtx, HSM_Ln_HashMacCfgType *ptCfg);
HSM_StatusType HSM_L1_ScatterHashInit(HSM_L1_RtCtxType             *pCtx,
                                      const HSM_ShaAlgType          eAlg,
                                      const HSM_Ln_ScatterHashType *pCfg,
                                      hsm_uint32_t                  u32TimeoutMs);
HSM_StatusType HSM_L1_ScatterHashUpdate(HSM_L1_RtCtxType             *pCtx,
                                        const HSM_Ln_ScatterHashType *pCfg,
                                        hsm_uint32_t                  u32TimeoutMs);
HSM_StatusType hsm_aux_get_empty_data_hash(HSM_ShaAlgType      eHash,
                                           const hsm_uint8_t **ppHashData,
                                           hsm_uint32_t       *pByteCnt);
HSM_StatusType HSM_L1_ScatterHashFinal(HSM_L1_RtCtxType               *pCtx,
                                       const HSM_Ln_ScatterHashType   *pCfg,
                                       const HSM_Ln_ResultBufInfoType *pResult,
                                       hsm_uint32_t                    u32TimeoutMs);
HSM_StatusType HSM_L1_ScatterHash_Isr(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_ScatterHashPoll(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_ScatterHashExitEnv(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_ScatterCMacSetupEnv(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_ScatterCMacInit(HSM_L1_RtCtxType              *pCtx,
                                      const HSM_Ln_CMacCfgParmsType *pKeyCfg,
                                      const HSM_Ln_ScatterCMacType  *pCfg,
                                      hsm_uint32_t                   u32TimeoutMs);
HSM_StatusType HSM_L1_ScatterCMacUpdate(HSM_L1_RtCtxType             *pCtx,
                                        const HSM_Ln_ScatterCMacType *pCfg,
                                        hsm_uint32_t                  u32TimeoutMs);
HSM_StatusType HSM_L1_ScatterCMacFinal(HSM_L1_RtCtxType               *pCtx,
                                       const HSM_Ln_ScatterCMacType   *pCfg,
                                       const HSM_Ln_ResultBufInfoType *pResult,
                                       hsm_uint32_t                    u32TimeoutMs);
HSM_StatusType HSM_L1_ScatterCMac_Isr(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_ScatterCMacPoll(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_ScatterCMacExitEnv(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_EccSignSetupEnv(HSM_L1_RtCtxType *pCtx, hsm_uint32_t u32BitCnt);
HSM_StatusType HSM_L1_EccSignExitEnv(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_EccSign(HSM_L1_RtCtxType         *pCtx,
                              const HSM_Ln_EccSignType *pCfg,
                              hsm_uint32_t              u32TimeoutMs);
HSM_StatusType HSM_L1_EccSign_Isr(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_EccSignPoll(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_EccSignReset(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_RsaSsaPssVerifySetupEnv(HSM_L1_RtCtxType *pCtx, hsm_uint32_t u32RsaBitCnt);
HSM_StatusType HSM_L1_RsaSsaPssVerify(HSM_L1_RtCtxType                 *pCtx,
                                      const HSM_Ln_RsaSsaPssVerifyType *pCfg,
                                      hsm_uint32_t                      u32TimeoutMs);
HSM_StatusType HSM_L1_RsaSsaPssVerifyPoll(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_RsaSsaPssVerifyReset(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_RsaSsaPssVerify_Isr(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_RsaSsaPssVerifyExitEnv(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_RsaSsaPkcs1V15VerifySetupEnv(HSM_L1_RtCtxType *pCtx, hsm_uint32_t u32RsaBitCnt);
HSM_StatusType HSM_L1_RsaSsaPkcs1V15Verify(HSM_L1_RtCtxType                      *pCtx,
                                           const HSM_Ln_RsaSsaPkcs1v15VerifyType *pCfg,
                                           hsm_uint32_t                           u32TimeoutMs);
HSM_StatusType HSM_L1_RsaSsaPkcs1V15VerifyPoll(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_RsaSsaPkcs1V15VerifyReset(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_RsaSsaPkcs1V15Verify_Isr(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_RsaSsaPkcs1V15VerifyExitEnv(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_KeyImportSetupEnv(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_KeyImport(HSM_L1_RtCtxType                  *pCtx,
                                const HSM_Ln_ImportUserKeyExtType *pCfg,
                                hsm_uint32_t                       u32TimeoutMs);
HSM_StatusType HSM_L1_KeyImportPoll(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_KeyImportReset(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_KeyImportExitEnv(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_KeyImport_Isr(HSM_L1_RtCtxType *pCtx);
#if ((FC7XXX_HSM_SUBSYSTEM_TYPE == FC7240_HSM_SUBSYSTEM) || \
     (FC7XXX_HSM_SUBSYSTEM_TYPE == FC7300_HSM_SUBSYSTEM))
HSM_StatusType HSM_L1_KeyValidateSetupEnv(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_KeyValidate(HSM_L1_RtCtxType *pCtx,
                                  hsm_uint32_t      u32KeyId,
                                  hsm_uint32_t      u32TimeoutMs);
HSM_StatusType HSM_L1_KeyValidatePoll(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_KeyValidateReset(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_KeyValidateExitEnv(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_KeyValidate_Isr(HSM_L1_RtCtxType *pCtx);
#endif
#if ((FC7XXX_HSM_SUBSYSTEM_TYPE == FC7240_HSM_SUBSYSTEM) || \
     (FC7XXX_HSM_SUBSYSTEM_TYPE == FC7300_HSM_SUBSYSTEM))
#else
HSM_StatusType HSM_L1_UpdateKeyIdContentSetupEnv(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_UpdateKeyIdContent(HSM_L1_RtCtxType                         *pCtx,
                                         const HSM_Ln_KeyManagerUpdateUserKeyType *pCfg,
                                         hsm_uint32_t                              u32TimeoutMs);
HSM_StatusType HSM_L1_UpdateKeyIdContentPoll(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_UpdateKeyIdContentReset(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_UpdateKeyIdContentExitEnv(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_UpdateKeyIdContent_Isr(HSM_L1_RtCtxType *pCtx);
#endif
HSM_StatusType HSM_L1_KeyCopySetupEnv(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_KeyCopy(HSM_L1_RtCtxType             *pCtx,
                              const HSM_Ln_CopyUserKeyType *pCfg,
                              hsm_uint32_t                  u32TimeoutMs);
HSM_StatusType HSM_L1_KeyCopyPoll(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_KeyCopyReset(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_KeyCopyExitEnv(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_KeyCopy_Isr(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_KeyRevokeSetupEnv(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_KeyRevoke(HSM_L1_RtCtxType *pCtx,
                                hsm_uint32_t      u32KeyId,
                                hsm_uint32_t      u32TimeoutMs);
HSM_StatusType HSM_L1_KeyRevokePoll(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_KeyRevokeReset(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_KeyRevokeExitEnv(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_KeyRevoke_Isr(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_KeySpaceTidyUpSetupEnv(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_KeySpaceTidyUp(HSM_L1_RtCtxType          *pCtx,
                                     HSM_Ln_KeySpaceStatusType *pCfg,
                                     hsm_uint32_t               u32TimeoutMs);
HSM_StatusType HSM_L1_KeySpaceTidyUpPoll(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_KeySpaceTidyUpReset(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_KeySpaceTidyUpExitEnv(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_KeySpaceTidyup_Isr(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_KeySpaceGetStatusSetupEnv(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_KeySpaceGetStatus(HSM_L1_RtCtxType          *pCtx,
                                        HSM_Ln_KeySpaceStatusType *pCfg,
                                        hsm_uint32_t               u32TimeoutMs);
HSM_StatusType HSM_L1_KeySpaceGetStatusPoll(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_KeySpaceGetStatusReset(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_KeySpaceGetStatusExitEnv(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_KeySpaceGetStatus_Isr(HSM_L1_RtCtxType *pCtx);
#if ((FC7XXX_HSM_SUBSYSTEM_TYPE == FC7240_HSM_SUBSYSTEM) || \
     (FC7XXX_HSM_SUBSYSTEM_TYPE == FC7300_HSM_SUBSYSTEM))
HSM_StatusType HSM_L1_GetKeyIdStatusSetupEnv(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_GetKeyIdStatus(HSM_L1_RtCtxType *pCtx,
                                     hsm_uint32_t      u32KeyId,
                                     hsm_uint32_t      u32TimeoutMs);
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
HSM_StatusType HSM_L1_RsaSsaPkcs1V15SignHash(HSM_L1_RtCtxType                        *pCtx,
                                             const HSM_Ln_RsaSsaPkcs1V15SignHashType *pCfg,
                                             hsm_uint32_t                             u32TimeoutMs);
HSM_StatusType HSM_L1_RsaSsaPkcs1V15SignData(HSM_L1_RtCtxType                        *pCtx,
                                             const HSM_Ln_RsaSsaPkcs1V15SignDataType *pCfg,
                                             hsm_uint32_t                             u32TimeoutMs);
HSM_StatusType HSM_L1_RsaSsaPkcs1V15SignPoll(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_RsaSsaPkcs1V15SignReset(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_RsaSsaPkcs1V15SignExitEnv(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_RsaSsaPkcs1V15Sign_Isr(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_RsaSsaPssSignSetupEnv(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_RsaSsaPssSignData(HSM_L1_RtCtxType                   *pCtx,
                                        const HSM_Ln_RsaSsaPssSignDataType *pCfg,
                                        hsm_uint32_t                        u32TimeoutMs);
HSM_StatusType HSM_L1_RsaSsaPssSignHash(HSM_L1_RtCtxType                   *pCtx,
                                        const HSM_Ln_RsaSsaPssSignHashType *pCfg,
                                        hsm_uint32_t                        u32TimeoutMs);
HSM_StatusType HSM_L1_RsaSsaPssSignPoll(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_RsaSsaPssSignReset(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_RsaSsaPssSignExitEnv(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_RsaSsaPssSign_Isr(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_Sm2GenZaSetupEnv(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_Sm2GenZaExitEnv(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_Sm2GenZa(HSM_L1_RtCtxType          *pCtx,
                               const HSM_LN_Sm2GenZaType *pCfg,
                               hsm_uint32_t               u32TimeoutMs);
HSM_StatusType HSM_L1_Sm2GenZa_Isr(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_Sm2GenZaPoll(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_Sm2GenZaReset(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_Sm2VerifySetupEnv(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_Sm2VerifyExitEnv(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_Sm2Verify(HSM_L1_RtCtxType           *pCtx,
                                const HSM_L1_Sm2VerifyType *pCfg,
                                hsm_uint32_t                u32TimeoutMs);
HSM_StatusType HSM_L1_Sm2Verify_Isr(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_Sm2VerifyPoll(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_Sm2VerifyReset(HSM_L1_RtCtxType *pCtx);
HSM_StatusType HSM_L1_PKCS1_GetRsaPrivateKeyInfFromDer(const hsm_uint8_t                *pDer,
                                                       HSM_L1_PKCS_RsaPrivateKeyInfType *pInf);
HSM_StatusType HSM_L1_PKCS1_GetEccPrivateKeyInfFromDer(const hsm_uint8_t                *pDer,
                                                       HSM_L1_PKCS_EccPrivateKeyInfType *pInf);
HSM_StatusType HSM_L1_PKCS8_GetPrivateKeyInfFromDer(const hsm_uint8_t              *pDer,
                                                    HSM_L1_PKCS8_PrivateKeyInfType *pInf);
HSM_StatusType HSM_L1_PKCS1_GetRsaPublicKeyInfFromDer(const hsm_uint8_t               *pDer,
                                                      HSM_L1_PKCS_RsaPublicKeyInfType *pInf);
HSM_StatusType hsm_l1_subjectpublicinfo_bitstring_geteccpublickeyinf(
    const hsm_uint8_t               *pDer,
    HSM_L1_PKCS_EccPublicKeyInfType *pInf);
HSM_StatusType HSM_L1_SubjectPublicInfo_GetPublicKeyInfFromDer(const hsm_uint8_t       *pDer,
                                                               HSM_L1_PublicKeyInfType *pInf);
HSM_StatusType HSM_L1_GetPoll(HSM_L1_RtCtxType *pCtx);
void           HSM_L1_Ack_IrqHandler(void *pUpperCtx, HSM_StatusType eRet);

static HSM_StatusType hsm_l1_scatter_hash_init(HSM_L1_RtCtxType *pCtx, HSM_DataFormatType eInputFmt);
static HSM_StatusType hsm_l1_scatter_hash_update(HSM_L1_RtCtxType  *pCtx,
                                                 HSM_DataFormatType eInputFmt);
static HSM_StatusType hsm_l1_scatter_hash_final(HSM_L1_RtCtxType *pCtx, HSM_DataFormatType eInputFmt);
static HSM_StatusType hsm_l1_scatter_hash_init2final(HSM_L1_RtCtxType *pCtx,
                                                     HSMCom_ShaExType *pShaParm);
static HSM_StatusType hsm_l1_scatter_cmac_init(HSM_L1_RtCtxType  *pCtx,
                                               HSM_DataFormatType eInputFmt,
                                               HSM_DataFormatType eKeyFmt);
static HSM_StatusType hsm_l1_scatter_cmac_update(HSM_L1_RtCtxType  *pCtx,
                                                 HSM_DataFormatType eInputFmt,
                                                 HSM_DataFormatType eKeyFmt);
static HSM_StatusType hsm_l1_scatter_cmac_final(HSM_L1_RtCtxType  *pCtx,
                                                HSM_DataFormatType eInputFmt,
                                                HSM_DataFormatType eKeyFmt);
static HSM_StatusType hsm_l1_scatter_cmac_init2final(HSM_L1_RtCtxType  *pCtx,
                                                     HSMCom_CMacExType *pParm);
/********************************************* Global function
 * *********************************************************/
HSM_StatusType hsm_1B4B_convert_from_idx(HSM_DataFormatType eDstFmt,
                                         void              *pDst,
                                         hsm_uint32_t       u32DstStartIdx,
                                         hsm_uint32_t       u32DstBufByteSize,
                                         HSM_DataFormatType eSrcFmt,
                                         const void        *pSrc,
                                         hsm_uint32_t       u32SrcStartIdx,
                                         hsm_uint32_t       u32SrcStopIdx)
{
    HSM_StatusType eRet = HSM_STATUS_SUCCESS;
    hsm_uint32_t   u32Idx, u32Idx2;

    if ((u32SrcStopIdx - u32SrcStartIdx) <= (u32DstBufByteSize - u32DstStartIdx))
    {
        if (HSM_DATA_FORMAT_4B == eDstFmt)
        {
            if (HSM_DATA_FORMAT_4B == eSrcFmt)
            {
                for (u32Idx = u32SrcStartIdx, u32Idx2 = u32DstStartIdx; u32Idx < u32SrcStopIdx;
                     ++u32Idx, ++u32Idx2)
                {
                    *(((hsm_uint8_t *)pDst) + HSM_4B_BYTE_INDEX_TO_OFFSET(u32Idx2)) = *(
                        ((hsm_uint8_t *)pSrc) + HSM_4B_BYTE_INDEX_TO_OFFSET(u32Idx));
                }
            }
            else
            {
                for (u32Idx = u32SrcStartIdx, u32Idx2 = u32DstStartIdx; u32Idx < u32SrcStopIdx;
                     ++u32Idx, ++u32Idx2)
                {
                    *(((hsm_uint8_t *)pDst) +
                      HSM_4B_BYTE_INDEX_TO_OFFSET(u32Idx2)) = *(((hsm_uint8_t *)pSrc) + (u32Idx));
                }
            }
        }
        else
        {
            if (HSM_DATA_FORMAT_4B == eSrcFmt)
            {
                for (u32Idx = u32SrcStartIdx, u32Idx2 = u32DstStartIdx; u32Idx < u32SrcStopIdx;
                     ++u32Idx, ++u32Idx2)
                {
                    *(((hsm_uint8_t *)pDst) + (u32Idx2)) = *(((hsm_uint8_t *)pSrc) +
                                                             HSM_4B_BYTE_INDEX_TO_OFFSET(u32Idx));
                }
            }
            else
            {
                for (u32Idx = u32SrcStartIdx, u32Idx2 = u32DstStartIdx; u32Idx < u32SrcStopIdx;
                     ++u32Idx, ++u32Idx2)
                {
                    *(((hsm_uint8_t *)pDst) + (u32Idx2)) = *(((hsm_uint8_t *)pSrc) + (u32Idx));
                }
            }
        }
    }
    else
    {
        eRet = HSM_STATUS_PARAM_ERR;
    }

    return eRet;
}

void hsm_bidi_memcpy(void *pDstMem, const void *pSrcMem, hsm_uint32_t u32OpCnt, hsm_int32_t sOpDirection)
{
    hsm_uint8_t       *pDstByte   = pDstMem;
    const hsm_uint8_t *pSrcByte   = pSrcMem;
    hsm_int32_t        sDirection = sOpDirection;
    hsm_uint32_t       u32Cnt     = u32OpCnt;

    if ((pSrcMem != pDstMem) && (u32Cnt > 0))
    {
        if (sDirection >= 0)
        {
            if (((hsm_uint32_t)pDstMem) > ((hsm_uint32_t)pSrcMem)) /* for safe */
            {
                pDstByte += u32Cnt;
                pSrcByte += u32Cnt;
                pDstByte -= 1;
                pSrcByte -= 1;
                sDirection = -1;
            }
            else
            {
                sDirection = 1;
            }
        }
        else
        {
            if (((hsm_uint32_t)pDstMem) < ((hsm_uint32_t)pSrcMem)) /* for safe */
            {
                pDstByte -= u32Cnt;
                pSrcByte -= u32Cnt;
                pDstByte += 1;
                pSrcByte += 1;
                sDirection = 1;
            }
            else
            {
                sDirection = -1;
            }
        }

        while (u32Cnt > 0u)
        {
            *pDstByte = *pSrcByte;
            pDstByte += sDirection;
            pSrcByte += sDirection;
            u32Cnt--;
        }
    }
    else
    {
        ; /* nothing to do */
    }
}

void hsm_memcpy(void *pDstMem, const void *pSrcMem, hsm_uint32_t u32Cnt)
{
    hsm_bidi_memcpy(pDstMem, pSrcMem, u32Cnt, 1U);
}

void hsm_memset(void *pDstMem, hsm_uint8_t u8Val, hsm_uint32_t u32Cnt)
{
    hsm_uint8_t *pData = (hsm_uint8_t *)pDstMem;
    hsm_uint32_t u32Idx;

    for (u32Idx = 0; u32Idx < u32Cnt; ++u32Idx)
    {
        pData[u32Idx] = u8Val;
    }
}

hsm_int32_t hsm_memcmp(const void *pDst, const void *pSrc, hsm_uint32_t u32OpCnt)
{
    const hsm_uint8_t *pByteData1 = (const hsm_uint8_t *)pDst;
    const hsm_uint8_t *pByteData2 = (const hsm_uint8_t *)pSrc;
    hsm_int32_t        sRet, sData1, sData2;
    hsm_uint32_t       u32Cnt = u32OpCnt;

    sRet = 0;
    while (u32Cnt > 0u)
    {
        sData1 = (hsm_int32_t)(*pByteData1);
        sData2 = (hsm_int32_t)(*pByteData2);
        sRet   = sData1 - sData2;
        if (0u != sRet)
        {
            break;
        }
        u32Cnt--;
        pByteData1++;
        pByteData2++;
    }

    return sRet;
}

HSM_StatusType hsm_hash_get_result_byte_count(HFAM_MODE_E eMode, hsm_uint32_t *pRetByteCnt)
{
    hsm_uint32_t   u32ByteCnt;
    HSM_StatusType eRet = HSM_STATUS_SUCCESS;

    switch (eMode)
    {
        case HFA_MD5:
            u32ByteCnt = 16u; /* 16 */
            break;

        case HFA_SHA160:
            u32ByteCnt = 160 / 8; /* 20 */
            break;

        case HFA_SHA224:
            u32ByteCnt = 224 / 8; /* 28 */
            break;

        case HFA_SHA256:
            u32ByteCnt = 256 / 8; /* 32 */
            break;

        case HFA_SHA384:
            u32ByteCnt = 384 / 8; /* 48 */
            break;

        case HFA_SHA512:
            u32ByteCnt = 512 / 8; /* 64 */
            break;

        case HFA_SHA512_224:
            u32ByteCnt = 224 / 8; /* 28 */
            break;

        case HFA_SHA512_256:
            u32ByteCnt = 256 / 8; /* 32 */
            break;

        case HFA_SM3:
            u32ByteCnt = 32u; /* 32 */
            break;

        default:
            u32ByteCnt = 0;
            eRet       = HSM_STATUS_PARAM_ERR;
            break;
    }

    if (NULL_PTR != pRetByteCnt)
    {
        *pRetByteCnt = u32ByteCnt;
    }

    return eRet;
}

void hsm_u32_array_swap(hsm_uint32_t *pData, hsm_uint32_t u32WordCnt)
{
    hsm_uint32_t u32Idx;

    for (u32Idx = 0u; u32Idx < u32WordCnt; ++u32Idx)
    {
        pData[u32Idx] = hsm_hw_swap_u32(pData[u32Idx]);
    }
}

void hsm_u32_array_swap_to(hsm_uint32_t *pData, const hsm_uint32_t *pSrc, hsm_uint32_t u32WordCnt)
{
    hsm_uint32_t u32Idx;

    for (u32Idx = 0u; u32Idx < u32WordCnt; ++u32Idx)
    {
        pData[u32Idx] = hsm_hw_swap_u32(pSrc[u32Idx]);
    }
}

void hsm_rm_prefix_zeros(HSM_DataFormatType  eInputFmt,
                         const hsm_uint8_t  *pData,
                         hsm_uint32_t        u32ByteCount,
                         const hsm_uint8_t **ppActualData,
                         hsm_uint32_t       *pActualByteCnt)
{
    const hsm_uint8_t  *pInter       = (const hsm_uint8_t *)pData;
    const hsm_uint32_t *pInterU32    = (const hsm_uint32_t *)pData;
    hsm_uint32_t        u32DataCount = u32ByteCount;

    if (HSM_DATA_FORMAT_1B == eInputFmt)
    {
        while ((0u == *pInter) && (u32DataCount > 0u))
        {
            pInter++;
            u32DataCount--;
        }
    }
    else
    {
        if (0x3u == (((hsm_uint32_t)pData) & 0x3u))
        {
            while ((u32DataCount >= 4u) && (0u == pInter[0]) && (0u == pInter[1]) &&
                   (0u == pInter[2]) && (0u == pInter[3]))
            {
                pInter += 4u;
                u32DataCount -= 4u;
            }
        }
        else
        {
            while ((0u == *pInterU32) && (u32DataCount >= 4u))
            {
                pInterU32++;
                u32DataCount -= 4U;
            }
        }

        pInter = (const hsm_uint8_t *)pInterU32;
    }

    if (NULL_PTR != ppActualData)
    {
        *ppActualData = pInter;
    }
    /* else do nothing */

    if (NULL_PTR != pActualByteCnt)
    {
        *pActualByteCnt = u32DataCount;
    }
    /* else do nothing */
}

void hsm_core_swap_u32_array_pad(hsm_uint32_t      *pAlignedDest,
                                 hsm_uint32_t       u32DestWordCnt,
                                 const hsm_uint8_t *pSrc,
                                 hsm_uint32_t       u32SrcOpByteCnt,
                                 hsm_uint8_t        u8PadByte,
                                 HSM_BoolType       bPadFromMSB,
                                 HSM_BoolType       bSwap)
{
    hsm_uint32_t        u32Idx = 0;
    hsm_uint32_t        u32Temp;
    hsm_uint32_t        u32Data;
    hsm_uint32_t        u32DestIdx;
    const hsm_uint32_t *pSrcWord      = (const hsm_uint32_t *)pSrc;
    hsm_uint32_t        u32SrcByteCnt = u32SrcOpByteCnt;

    if ((u32DestWordCnt << 2u) < u32SrcByteCnt)
    {
        u32SrcByteCnt = (u32DestWordCnt << 2u);
    }

    u32Temp = u32SrcByteCnt >> 2u;

    if (0u == (((hsm_uint32_t)pSrc) & 0x3u))
    {
        if (HSM_FALSE != bSwap)
        {
            for (; u32Idx < u32Temp; ++u32Idx)
            {
                pAlignedDest[u32Idx] = hsm_hw_swap_u32(pSrcWord[u32Idx]);
            }
        }
        else
        {
            for (; u32Idx < u32Temp; ++u32Idx)
            {
                pAlignedDest[u32Idx] = pSrcWord[u32Idx];
            }
        }
    }
    else
    {
        if (HSM_FALSE != bSwap)
        {
            for (; u32Idx < u32Temp; ++u32Idx)
            {
                u32DestIdx = (hsm_uint32_t)pSrc + (u32Idx * 4);

                u32Data = *((hsm_uint8_t *)u32DestIdx + 3);
                u32Data = (u32Data << 8u) | (*((hsm_uint8_t *)u32DestIdx + 2));
                u32Data = (u32Data << 8u) | (*((hsm_uint8_t *)u32DestIdx + 1));
                u32Data = (u32Data << 8u) | (*((hsm_uint8_t *)u32DestIdx + 0));

                pAlignedDest[u32Idx] = hsm_hw_swap_u32(u32Data);
            }
        }
        else
        {
            for (; u32Idx < u32Temp; ++u32Idx)
            {
                u32DestIdx = (hsm_uint32_t)pSrc + (u32Idx * 4);

                u32Data = *((hsm_uint8_t *)u32DestIdx + 3);
                u32Data = (u32Data << 8u) | (*((hsm_uint8_t *)u32DestIdx + 2));
                u32Data = (u32Data << 8u) | (*((hsm_uint8_t *)u32DestIdx + 1));
                u32Data = (u32Data << 8u) | (*((hsm_uint8_t *)u32DestIdx + 0));

                pAlignedDest[u32Idx] = (u32Data);
            }
        }
    }

    u32DestIdx = u32Idx;

    u32Temp = (u32SrcByteCnt % 4u);
    if (0u != u32Temp)
    {
        u32Temp = 4u - u32Temp;

        if (0u == (((hsm_uint32_t)pSrcWord) & 0x3u))
        {
            u32Data = pSrcWord[u32Idx];
        }
        else
        {
            u32SrcByteCnt = (hsm_uint32_t)pSrc + (u32Idx * 4);

            u32Data = *((hsm_uint8_t *)u32SrcByteCnt + 3);
            u32Data = (u32Data << 8u) | (*((hsm_uint8_t *)u32SrcByteCnt + 2));
            u32Data = (u32Data << 8u) | (*((hsm_uint8_t *)u32SrcByteCnt + 1));
            u32Data = (u32Data << 8u) | (*((hsm_uint8_t *)u32SrcByteCnt + 0));
        }

        if (HSM_FALSE != bPadFromMSB)
        {
            u32Data = u32Data << (u32Temp * 8u);

            for (u32Idx = 0; u32Idx < u32Temp; ++u32Idx)
            {
                u32Data = (u32Data >> 8u) | (((hsm_uint32_t)u8PadByte) << 24u);
            }
        }
        else
        {
            u32Data = u32Data >> (u32Temp * 8u);

            for (u32Idx = 0; u32Idx < u32Temp; ++u32Idx)
            {
                u32Data = (u32Data << 8u) | (((hsm_uint32_t)u8PadByte));
            }
        }

        if (HSM_FALSE != bSwap)
        {
            pAlignedDest[u32DestIdx] = hsm_hw_swap_u32(u32Data);
        }
        else
        {
            pAlignedDest[u32DestIdx] = (u32Data);
        }
        u32DestIdx++;
    }

    hsm_memset(pAlignedDest + u32DestIdx, u8PadByte, (u32DestWordCnt << 2u) - (u32DestIdx << 2u));
}

void HSM_L1_CleanEnv(HSM_L1_RtCtxType *pCtx)
{
    pCtx->eLastestHsmRet = HSM_STATUS_IDLE;
    pCtx->bInProcess     = HSM_FALSE;
    pCtx->eOperationCata = HSM_OP_NONE;
}

HSM_StatusType HSM_L1_CommonExitEnv(HSM_L1_RtCtxType *pCtx)
{
    HSM_BoolType     bInProcess = pCtx->bInProcess;
    HSM_StatusType   eRet       = HSM_STATUS_SUCCESS;
    HSM_L1_DrvSMType eState     = pCtx->eStat;

    HSM_L1_CleanEnv(pCtx);

    if (HSM_TRUE == bInProcess)
    {
        if (HSM_DRV_SM_ARITH == eState)
        {
            eRet = pCtx->pCancelCmdCb();
        }
    }

    return eRet;
}

/* abort current operation, the operation will goto None */
HSM_StatusType HSM_L1_Abort(HSM_L1_RtCtxType *pCtx)
{
    HSM_BoolType     bInProcess = pCtx->bInProcess;
    HSM_StatusType   eRet       = HSM_STATUS_SUCCESS;
    HSM_L1_DrvSMType eState     = pCtx->eStat;

    HSM_L1_CleanEnv(pCtx);

    if (HSM_TRUE == bInProcess)
    {
        if (HSM_DRV_SM_ARITH == eState)
        {
            eRet = pCtx->pCancelCmdCb();
        }
    }

    return eRet;
}

void HSM_L1_Init(HSM_L1_RtCtxType *pCtx, HSM_L1_InitParmType *pParm)
{
    pCtx->eTriggerSrc          = pParm->eTriggerSrc;
    pCtx->pStopCb              = pParm->pStopCb;
    pCtx->pSendCmdCb           = pParm->pSendCmdCb;
    pCtx->pReadAckCb           = pParm->pReadAckCb;
    pCtx->pCancelCmdCb         = pParm->pCancelCmdCb;
    pCtx->pCleanDCache         = pParm->pCleanDCache;
    pCtx->pCleanAndFlushDcache = pParm->pCleanAndFlushDcache;

    HSM_L1_CleanEnv(pCtx);
}

#if 0
/*
 * IF use key id of RSA E/D/N, the key data in key space of HSM side,
 * only support 4B format,
 * and the N size must 8bytes aligned,
 * the D/E size should equal to N size.
 * So use HSM_L1_BnCalc instead.
 */

HSM_StatusType HSM_L1_RsaSetupEnv(HSM_L1_RtCtxType *pCtx, hsm_uint32_t u32RsaBitCnt)
{
    HSM_BoolType  bInProcess  = HSM_FALSE;
    HSM_StatusType      eRet  = HSM_STATUS_SUCCESS;

    if ((u32RsaBitCnt <= 4096u) && (u32RsaBitCnt >= 1u))
    {
        bInProcess = pCtx->bInProcess;
        if (HSM_FALSE == bInProcess)
        {
            pCtx->bInProcess                                 = HSM_TRUE;
            pCtx->eOperationCata                             = HSM_OP_RSA;
            pCtx->tL1AlgCtx.tRsaInf.u32NBitCnt                         = u32RsaBitCnt;
            pCtx->eStat                                      = HSM_DRV_SM_READY;
            pCtx->tL1AlgCtx.tRsaInf.pRsaParm                           = (HSMCom_RsaType *)HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tRsaInf.aRsaParmBuf[0]));
            pCtx->tL1AlgCtx.tRsaInf.pRsaParm->tCfg.pInputData          = (const hsm_uint32_t *)HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tRsaInf.aRsaInputAndResult[0]));
            pCtx->tL1AlgCtx.tRsaInf.pRsaParm->tCfg.pKey_E              = (const hsm_uint32_t *)HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tRsaInf.aRsaE[0]));
            pCtx->tL1AlgCtx.tRsaInf.pRsaParm->tCfg.pKey_N              = (const hsm_uint32_t *)HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tRsaInf.aRsaN[0]));
            pCtx->tL1AlgCtx.tRsaInf.pRsaParm->tCfg.pResult             = (hsm_uint32_t *)HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tRsaInf.aRsaInputAndResult[0]));
            pCtx->tL1AlgCtx.tRsaInf.pRsaParm->tCfg.u32ResultBufByteCnt = sizeof(pCtx->tL1AlgCtx.tRsaInf.aRsaInputAndResult) - 4;


            eRet = HSM_STATUS_SUCCESS;
        }
        else
        {
            eRet = HSM_STATUS_LOGIC_ERR;
        }
    }
    else
    {
        eRet = HSM_STATUS_PARAM_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_RsaExitEnv(HSM_L1_RtCtxType *pCtx)
{
    HSM_BoolType     bInProcess = pCtx->bInProcess;
    HSM_StatusType         eRet = HSM_STATUS_SUCCESS;


    if ((HSM_TRUE == bInProcess) &&
        (HSM_OP_RSA == pCtx->eOperationCata))
    {
        eRet = HSM_L1_CommonExitEnv(pCtx);
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}


/* For interrupt usage */
HSM_StatusType HSM_L1_Rsa(HSM_L1_RtCtxType *pCtx, const HSM_L1_RsaType *pCfg,  hsm_uint32_t u32TimeoutMs)
{
    hsm_uint32_t         u32NByteCnt;
    HSM_StatusType eRet = HSM_STATUS_SUCCESS;
    HSM_BoolType   bInProcess = HSM_FALSE;
    const hsm_uint8_t   *pStart;
    hsm_uint32_t         u32ActualSize;

    if ((NULL_PTR != pCtx) && (NULL_PTR != pCfg))
    {
        bInProcess = pCtx->bInProcess;

        if ((HSM_TRUE == bInProcess) &&
            (HSM_OP_RSA == pCtx->eOperationCata))
        {
            if (HSM_DRV_SM_ARITH != pCtx->eStat)
            {
                u32NByteCnt = ((pCtx->tL1AlgCtx.tRsaInf.u32NBitCnt + 63u) / 64u) * 8u;

                pCtx->tL1AlgCtx.tRsaInf.pRsaParm->u32HSMStatusRet             = MAILBOXAPI_RET_NONE;
                pCtx->tL1AlgCtx.tRsaInf.pRsaParm->u32Timeout                  = u32TimeoutMs;
                pCtx->tL1AlgCtx.tRsaInf.pRsaParm->u32RsaBitCnt                = pCtx->tL1AlgCtx.tRsaInf.u32NBitCnt;

                pCtx->tL1AlgCtx.tRsaInf.pRsaParm->tCfg.u32InputDataByteCount  = u32NByteCnt;
                hsm_rm_prefix_zeros(pCfg->eInputDataFmt, pCfg->pInputData, pCfg->u32InputDataByteCount, &pStart, &u32ActualSize);
                hsm_memset((void *)HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tRsaInf.aRsaInputAndResult[0])), 0, u32NByteCnt - u32ActualSize);
                hsm_memcpy(((hsm_uint8_t *)HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tRsaInf.aRsaInputAndResult[0]))) + (u32NByteCnt - u32ActualSize), pStart, u32ActualSize);
                if (HSM_DATA_FORMAT_1B == pCfg->eInputDataFmt)
                {
                    hsm_u32_array_swap((hsm_uint32_t *)HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tRsaInf.aRsaInputAndResult[0])), u32NByteCnt / 4U);
                }
                else
                {
                    ;
                }

                if (pCfg->u32KeyEId)
                {
                    pCtx->tL1AlgCtx.tRsaInf.pRsaParm->u32UserKeyID_KEY_E      = pCfg->u32KeyEId;
                    pCtx->tL1AlgCtx.tRsaInf.pRsaParm->tCfg.u32Key_E_ByteCount = pCfg->u32KeyEByteCount;
                }
                else
                {
                    pCtx->tL1AlgCtx.tRsaInf.pRsaParm->tCfg.u32Key_E_ByteCount    = u32NByteCnt;
                    hsm_rm_prefix_zeros(pCfg->eKeyEFmt, pCfg->pKeyE, pCfg->u32KeyEByteCount, &pStart, &u32ActualSize);
                    hsm_memset((void *)HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tRsaInf.aRsaE[0])), 0, u32NByteCnt - u32ActualSize);
                    hsm_memcpy(((hsm_uint8_t *)HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tRsaInf.aRsaE[0]))) + (u32NByteCnt - u32ActualSize), pStart, u32ActualSize);
                    if (HSM_DATA_FORMAT_1B == pCfg->eKeyEFmt)
                    {
                        hsm_u32_array_swap((hsm_uint32_t *)HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tRsaInf.aRsaE[0])), u32NByteCnt / 4U);
                    }
                    else
                    {
                        ;
                    }
                }

                if (pCfg->u32KeyNId)
                {
                    pCtx->tL1AlgCtx.tRsaInf.pRsaParm->u32UserKeyID_KEY_N = pCfg->u32KeyNId;
                    pCtx->tL1AlgCtx.tRsaInf.pRsaParm->tCfg.u32Key_N_ByteCount    = pCfg->u32KeyNByteCount;
                }
                else
                {
                    pCtx->tL1AlgCtx.tRsaInf.pRsaParm->tCfg.u32Key_N_ByteCount    = u32NByteCnt;
                    hsm_rm_prefix_zeros(pCfg->eKeyNFmt, pCfg->pKeyN, pCfg->u32KeyNByteCount, &pStart, &u32ActualSize);
                    hsm_memset((void *)HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tRsaInf.aRsaN[0])), 0, u32NByteCnt - u32ActualSize);
                    hsm_memcpy(((hsm_uint8_t *)HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tRsaInf.aRsaN[0]))) + (u32NByteCnt - u32ActualSize), pStart, u32ActualSize);

                    if (HSM_DATA_FORMAT_1B == pCfg->eKeyNFmt)
                    {
                        hsm_u32_array_swap((hsm_uint32_t *)HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tRsaInf.aRsaN[0])), u32NByteCnt / 4U);
                    }
                    else
                    {
                        ;
                    }
                }

                pCtx->tL1AlgCtx.tRsaInf.pResultBuf        = pCfg->pResult;
                pCtx->tL1AlgCtx.tRsaInf.u32ResultBufSize  = pCfg->u32ResultBufByteCnt;
                pCtx->tL1AlgCtx.tRsaInf.pResultByteCnt    = pCfg->pResultByteCnt;
                pCtx->tL1AlgCtx.tRsaInf.eOutFmt           = pCfg->eOutputFmt;


                eRet = HSM_Rsa(&(pCtx->tCmd), pCtx->tL1AlgCtx.tRsaInf.pRsaParm);
                if (HSM_STATUS_SUCCESS == eRet)
                {
                    pCtx->eStat = HSM_DRV_SM_ARITH;
                    eRet = pCtx->pSendCmdCb(&(pCtx->tCmd));
                    if (HSM_STATUS_SUCCESS != eRet)
                    {
                        pCtx->eStat = HSM_DRV_SM_STOP;
                        eRet = HSM_STATUS_SEND_FAIL;
                    }
                }
                else
                {
                    ;
                }
            }
            else
            {
                eRet = HSM_STATUS_BUSY;
            }

        }
        else
        {
            eRet = HSM_STATUS_LOGIC_ERR;
        }
    }
    else
    {
        eRet = HSM_STATUS_PARAM_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_Rsa_Isr(HSM_L1_RtCtxType *pCtx)
{
    const hsm_uint8_t    *pStart;
    hsm_uint32_t          u32ActualSize;
    HSM_StatusType  eRet;

    if (MAILBOXAPI_RET_SUCCESS == pCtx->tL1AlgCtx.tRsaInf.pRsaParm->u32HSMStatusRet)
    {
        if (HSM_DATA_FORMAT_1B == pCtx->tL1AlgCtx.tRsaInf.eOutFmt)
        {
            hsm_u32_array_swap((hsm_uint32_t *)HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tRsaInf.aRsaInputAndResult[0])), pCtx->tL1AlgCtx.tRsaInf.pRsaParm->tCfg.u32Key_N_ByteCount / 4U);

            hsm_rm_prefix_zeros(HSM_DATA_FORMAT_1B, (const hsm_uint8_t *)pCtx->tL1AlgCtx.tRsaInf.pRsaParm->tCfg.pResult, pCtx->tL1AlgCtx.tRsaInf.pRsaParm->tCfg.u32Key_N_ByteCount, &pStart,
                                &u32ActualSize);

            if (u32ActualSize > pCtx->tL1AlgCtx.tRsaInf.u32ResultBufSize)
            {
                eRet = HSM_STATUS_BUFFER_SIZE_ERR;
            }
            else
            {
                hsm_memcpy(pCtx->tL1AlgCtx.tRsaInf.pResultBuf, pStart, u32ActualSize);
                if (NULL_PTR != pCtx->tL1AlgCtx.tRsaInf.pResultByteCnt)
                {
                    *pCtx->tL1AlgCtx.tRsaInf.pResultByteCnt = u32ActualSize;
                }

                eRet = HSM_STATUS_SUCCESS;
            }
        }
        else if (HSM_DATA_FORMAT_1B_PAD_0_LEFT_FIT_BUF == pCtx->tL1AlgCtx.tRsaInf.eOutFmt)
        {
            hsm_u32_array_swap((hsm_uint32_t *)HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tRsaInf.aRsaInputAndResult[0])), pCtx->tL1AlgCtx.tRsaInf.pRsaParm->tCfg.u32Key_N_ByteCount / 4U);

            hsm_rm_prefix_zeros(HSM_DATA_FORMAT_1B, (const hsm_uint8_t *)pCtx->tL1AlgCtx.tRsaInf.pRsaParm->tCfg.pResult, pCtx->tL1AlgCtx.tRsaInf.pRsaParm->tCfg.u32Key_N_ByteCount, &pStart,
                                &u32ActualSize);

            if (u32ActualSize > pCtx->tL1AlgCtx.tRsaInf.u32ResultBufSize)
            {
                eRet = HSM_STATUS_BUFFER_SIZE_ERR;
            }
            else
            {
                hsm_memset(pCtx->tL1AlgCtx.tRsaInf.pResultBuf, 0, pCtx->tL1AlgCtx.tRsaInf.u32ResultBufSize - u32ActualSize);
                hsm_memcpy(((hsm_uint8_t *)pCtx->tL1AlgCtx.tRsaInf.pResultBuf) + (pCtx->tL1AlgCtx.tRsaInf.u32ResultBufSize - u32ActualSize), pStart, u32ActualSize);
                if (NULL_PTR != pCtx->tL1AlgCtx.tRsaInf.pResultByteCnt)
                {
                    *pCtx->tL1AlgCtx.tRsaInf.pResultByteCnt = pCtx->tL1AlgCtx.tRsaInf.u32ResultBufSize;
                }

                eRet = HSM_STATUS_SUCCESS;
            }
        }
        else
        {
            hsm_rm_prefix_zeros(HSM_DATA_FORMAT_4B, (const hsm_uint8_t *)pCtx->tL1AlgCtx.tRsaInf.pRsaParm->tCfg.pResult, pCtx->tL1AlgCtx.tRsaInf.pRsaParm->tCfg.u32Key_N_ByteCount, &pStart,
                                &u32ActualSize);

            if (u32ActualSize > pCtx->tL1AlgCtx.tRsaInf.u32ResultBufSize)
            {
                eRet = HSM_STATUS_BUFFER_SIZE_ERR;
            }
            else
            {
                hsm_memcpy(pCtx->tL1AlgCtx.tRsaInf.pResultBuf, pStart, u32ActualSize);
                *pCtx->tL1AlgCtx.tRsaInf.pResultByteCnt = u32ActualSize;
                eRet = HSM_STATUS_SUCCESS;
            }
        }


        pCtx->eStat = HSM_DRV_SM_STOP;
    }
    else
    {
        eRet = HSM_STATUS_HW_ERR;
        pCtx->eStat = HSM_DRV_SM_STOP;
    }

    return eRet;
}


HSM_StatusType HSM_L1_RsaPoll(HSM_L1_RtCtxType *pCtx)
{
    HSM_StatusType  eRet = HSM_STATUS_SUCCESS;
    HSM_BoolType    bInProcess = HSM_FALSE;

    bInProcess = pCtx->bInProcess;

    if ((HSM_TRUE == bInProcess) &&
        (HSM_OP_RSA == pCtx->eOperationCata))
    {
        if (HSM_DRV_SM_ARITH == pCtx->eStat)
        {
            eRet = pCtx->pReadAckCb();
            if (HSM_STATUS_BUSY == eRet)
            {
                eRet = HSM_STATUS_AGAIN;
            }
            else if (HSM_STATUS_SUCCESS == eRet)
            {
                eRet = HSM_L1_Rsa_Isr(pCtx);
            }
            else
            {
                pCtx->eStat = HSM_DRV_SM_STOP;
            }
        }
        else
        {
            eRet = HSM_STATUS_HW_IDLE;
        }
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }


    return eRet;
}


HSM_StatusType HSM_L1_RsaReset(HSM_L1_RtCtxType *pCtx)
{
    HSM_BoolType     bInProcess = HSM_FALSE;
    HSM_StatusType         eRet = HSM_STATUS_SUCCESS;

    bInProcess = pCtx->bInProcess;

    if ((HSM_TRUE == bInProcess) &&
        (HSM_OP_RSA == pCtx->eOperationCata))
    {
        if (HSM_DRV_SM_ARITH == pCtx->eStat)
        {
            eRet = pCtx->pCancelCmdCb();
        }

        if (HSM_STATUS_SUCCESS == eRet)
        {
            pCtx->eStat      = HSM_DRV_SM_READY;
        }
        else
        {
            ;
        }
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}
#endif

HSM_StatusType HSM_L1_Md5SetupEnv(HSM_L1_RtCtxType *pCtx)
{
    HSM_BoolType   bInProcess = HSM_FALSE;
    HSM_StatusType eRet       = HSM_STATUS_SUCCESS;

    bInProcess = pCtx->bInProcess;
    if (HSM_FALSE == bInProcess)
    {
        pCtx->bInProcess              = HSM_TRUE;
        pCtx->eOperationCata          = HSM_OP_MD5;
        pCtx->eStat                   = HSM_DRV_SM_READY;
        pCtx->tL1AlgCtx.tMd5Inf.pParm = (HSMCom_Md5ExType *)HSM_ADDRESS_UP_ALIGN(
            &(pCtx->tL1AlgCtx.tMd5Inf.aParmBuf[0]));
        eRet = HSM_STATUS_SUCCESS;
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_Md5Reset(HSM_L1_RtCtxType *pCtx)
{
    HSM_BoolType   bInProcess = HSM_FALSE;
    HSM_StatusType eRet       = HSM_STATUS_SUCCESS;

    bInProcess = pCtx->bInProcess;

    if ((HSM_TRUE == bInProcess) && (HSM_OP_MD5 == pCtx->eOperationCata))
    {
        if (HSM_DRV_SM_ARITH == pCtx->eStat)
        {
            eRet = pCtx->pCancelCmdCb();
        }

        if (HSM_STATUS_SUCCESS == eRet)
        {
            pCtx->eStat = HSM_DRV_SM_READY;
        }
        else
        {
            ;
        }
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_Md5ExitEnv(HSM_L1_RtCtxType *pCtx)
{
    HSM_BoolType   bInProcess = pCtx->bInProcess;
    HSM_StatusType eRet       = HSM_STATUS_SUCCESS;

    if ((HSM_TRUE == bInProcess) && (HSM_OP_MD5 == pCtx->eOperationCata))
    {
        eRet = HSM_L1_CommonExitEnv(pCtx);
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_Md5(HSM_L1_RtCtxType *pCtx, const HSM_Ln_Md5Type *pCfg, hsm_uint32_t u32TimeoutMs)
{
    HSM_StatusType eRet       = HSM_STATUS_SUCCESS;
    HSM_BoolType   bInProcess = HSM_FALSE;

    if ((NULL_PTR != pCtx) && (NULL_PTR != pCfg) && (NULL_PTR != pCfg->pResult) &&
        (pCfg->u32ResultBufSize > 0) &&
        ((HSM_DATA_FORMAT_1B == pCfg->eOutputFmt) ||
         ((pCfg->u32ResultBufSize >= 4u) &&
          (0u == (pCfg->u32ResultBufSize & 0x3))))) /* not check the input address 4byte aligned
                                                       here for eco support this */
    {
        bInProcess = pCtx->bInProcess;

        if ((HSM_TRUE == bInProcess) && (HSM_OP_MD5 == pCtx->eOperationCata))
        {
            if (HSM_DRV_SM_ARITH != pCtx->eStat)
            {
                pCtx->tL1AlgCtx.tMd5Inf.pParm->u32HSMStatusRet = MAILBOXAPI_RET_NONE;
                pCtx->tL1AlgCtx.tMd5Inf.pParm->u32Timeout      = u32TimeoutMs;
                pCtx->tL1AlgCtx.tMd5Inf.pResultBuf             = pCfg->pResult;

                if (pCfg->u32ResultBufSize > 16u)
                {
                    pCtx->tL1AlgCtx.tMd5Inf.u32ResultBufSize = 16u;
                }
                else
                {
                    pCtx->tL1AlgCtx.tMd5Inf.u32ResultBufSize = pCfg->u32ResultBufSize;
                    ;
                }

                pCtx->tL1AlgCtx.tMd5Inf.pOutResultSize = pCfg->pResultSize;

                hsm_memcpy(&(pCtx->tL1AlgCtx.tMd5Inf.pParm->tCfg.tCfg),
                           &(pCfg->tCfg),
                           sizeof(HSM_Md5CtxType));
                pCtx->tL1AlgCtx.tMd5Inf.pParm->tCfg.pRet = (hsm_uint32_t(*)[4])HSM_ADDRESS_UP_ALIGN(
                    &(pCtx->tL1AlgCtx.tMd5Inf.aResultCacheBuf[0]));

                pCtx->tL1AlgCtx.tMd5Inf.pParm->tCfg.eInputFmt = pCfg->eInputFmt;
                pCtx->tL1AlgCtx.tMd5Inf.pParm->tCfg.eOutputFmt =
                    HSM_DATA_FORMAT_4B; /* require output 4B format */

                if (HSM_DATA_FORMAT_1B == pCfg->eOutputFmt)
                {
                    pCtx->tL1AlgCtx.tMd5Inf.bSwapOut = HSM_TRUE;
                }
                else
                {
                    pCtx->tL1AlgCtx.tMd5Inf.bSwapOut = HSM_FALSE;
                }

                eRet = HSM_FW_Md5Ex(&(pCtx->tCmd), pCtx->tL1AlgCtx.tMd5Inf.pParm, pCfg->bKeyUseId);
                if (HSM_STATUS_SUCCESS == eRet)
                {
                    pCtx->eStat = HSM_DRV_SM_ARITH;
                    eRet        = pCtx->pSendCmdCb(&(pCtx->tCmd));
                    if (HSM_STATUS_SUCCESS != eRet)
                    {
                        pCtx->eStat = HSM_DRV_SM_STOP;
                        eRet        = HSM_STATUS_SEND_FAIL;
                    }
                }
                else
                {
                    ;
                }
            }
            else
            {
                eRet = HSM_STATUS_BUSY;
            }
        }
        else
        {
            eRet = HSM_STATUS_LOGIC_ERR;
        }
    }
    else
    {
        eRet = HSM_STATUS_PARAM_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_Md5_Isr(HSM_L1_RtCtxType *pCtx)
{
    HSM_StatusType eRet;

    if (MAILBOXAPI_RET_SUCCESS == pCtx->tL1AlgCtx.tMd5Inf.pParm->u32HSMStatusRet)
    {
        if (HSM_TRUE == pCtx->tL1AlgCtx.tMd5Inf.bSwapOut) /* 1B format output */
        {
            hsm_u32_array_swap(
                (hsm_uint32_t *)HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tMd5Inf.aResultCacheBuf[0])),
                16 / 4U); /* md5 has 16bytes result data */
        }
        else
        {
        }

        hsm_memcpy(pCtx->tL1AlgCtx.tMd5Inf.pResultBuf,
                   pCtx->tL1AlgCtx.tMd5Inf.pParm->tCfg.pRet,
                   pCtx->tL1AlgCtx.tMd5Inf.u32ResultBufSize);

        if (NULL_PTR != (pCtx->tL1AlgCtx.tMd5Inf.pOutResultSize))
        {
            hsm_memcpy(pCtx->tL1AlgCtx.tMd5Inf.pOutResultSize,
                       &(pCtx->tL1AlgCtx.tMd5Inf.u32ResultBufSize),
                       sizeof(pCtx->tL1AlgCtx.tMd5Inf.u32ResultBufSize));
        }
        else
        {
            ;
        }
        eRet = HSM_STATUS_SUCCESS;

        pCtx->eStat = HSM_DRV_SM_STOP;
    }
    else
    {
        eRet        = HSM_STATUS_HW_ERR;
        pCtx->eStat = HSM_DRV_SM_STOP;
    }

    return eRet;
}

HSM_StatusType HSM_L1_Md5Poll(HSM_L1_RtCtxType *pCtx)
{
    HSM_StatusType eRet       = HSM_STATUS_SUCCESS;
    HSM_BoolType   bInProcess = HSM_FALSE;

    bInProcess = pCtx->bInProcess;

    if ((HSM_TRUE == bInProcess) && (HSM_OP_MD5 == pCtx->eOperationCata))
    {
        if (HSM_DRV_SM_ARITH == pCtx->eStat)
        {
            eRet = pCtx->pReadAckCb();
            if (HSM_STATUS_BUSY == eRet)
            {
                eRet = HSM_STATUS_AGAIN;
            }
            else if (HSM_STATUS_SUCCESS == eRet)
            {
                eRet = HSM_L1_Md5_Isr(pCtx);
            }
            else
            {
                pCtx->eStat = HSM_DRV_SM_STOP;
            }
        }
        else
        {
            eRet = HSM_STATUS_HW_IDLE;
        }
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_Sm3SetupEnv(HSM_L1_RtCtxType *pCtx)
{
    HSM_BoolType   bInProcess = HSM_FALSE;
    HSM_StatusType eRet       = HSM_STATUS_SUCCESS;

    bInProcess = pCtx->bInProcess;
    if (HSM_FALSE == bInProcess)
    {
        pCtx->bInProcess              = HSM_TRUE;
        pCtx->eOperationCata          = HSM_OP_SM3;
        pCtx->eStat                   = HSM_DRV_SM_READY;
        pCtx->tL1AlgCtx.tSm3Inf.pParm = (HSMCom_Sm3ExType *)HSM_ADDRESS_UP_ALIGN(
            &(pCtx->tL1AlgCtx.tSm3Inf.aParmBuf[0]));
        eRet = HSM_STATUS_SUCCESS;
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_Sm3Reset(HSM_L1_RtCtxType *pCtx)
{
    HSM_BoolType   bInProcess = HSM_FALSE;
    HSM_StatusType eRet       = HSM_STATUS_SUCCESS;

    bInProcess = pCtx->bInProcess;

    if ((HSM_TRUE == bInProcess) && (HSM_OP_SM3 == pCtx->eOperationCata))
    {
        if (HSM_DRV_SM_ARITH == pCtx->eStat)
        {
            eRet = pCtx->pCancelCmdCb();
        }

        if (HSM_STATUS_SUCCESS == eRet)
        {
            pCtx->eStat = HSM_DRV_SM_READY;
        }
        else
        {
            ;
        }
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_Sm3ExitEnv(HSM_L1_RtCtxType *pCtx)
{
    HSM_BoolType   bInProcess = pCtx->bInProcess;
    HSM_StatusType eRet       = HSM_STATUS_SUCCESS;

    if ((HSM_TRUE == bInProcess) && (HSM_OP_SM3 == pCtx->eOperationCata))
    {
        eRet = HSM_L1_CommonExitEnv(pCtx);
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_Sm3(HSM_L1_RtCtxType *pCtx, const HSM_Ln_Sm3Type *pCfg, hsm_uint32_t u32TimeoutMs)
{
    HSM_StatusType eRet       = HSM_STATUS_SUCCESS;
    HSM_BoolType   bInProcess = HSM_FALSE;

    if ((NULL_PTR != pCtx) && (NULL_PTR != pCfg) && (NULL_PTR != pCfg->pResult) &&
        (pCfg->u32ResultBufSize > 0) &&
        ((HSM_DATA_FORMAT_1B == pCfg->eOutputFmt) ||
         ((pCfg->u32ResultBufSize >= 4u) &&
          (0u == (pCfg->u32ResultBufSize & 0x3))))) /* not check the input address 4byte aligned
                                                       here for eco support this */
    {
        bInProcess = pCtx->bInProcess;

        if ((HSM_TRUE == bInProcess) && (HSM_OP_SM3 == pCtx->eOperationCata))
        {
            if (HSM_DRV_SM_ARITH != pCtx->eStat)
            {
                pCtx->tL1AlgCtx.tSm3Inf.pParm->u32HSMStatusRet = MAILBOXAPI_RET_NONE;
                pCtx->tL1AlgCtx.tSm3Inf.pParm->u32Timeout      = u32TimeoutMs;
                pCtx->tL1AlgCtx.tSm3Inf.pResultBuf             = pCfg->pResult;

                if (pCfg->u32ResultBufSize > 32U)
                {
                    pCtx->tL1AlgCtx.tSm3Inf.u32ResultBufSize = 32u;
                }
                else
                {
                    pCtx->tL1AlgCtx.tSm3Inf.u32ResultBufSize = pCfg->u32ResultBufSize;
                }

                pCtx->tL1AlgCtx.tSm3Inf.pOutResultSize = pCfg->pResultSize;

                hsm_memcpy(&(pCtx->tL1AlgCtx.tSm3Inf.pParm->tCfg.tCfg),
                           &(pCfg->tCfg),
                           sizeof(HSM_Sm3CtxType));
                pCtx->tL1AlgCtx.tSm3Inf.pParm->tCfg.pRet = (hsm_uint32_t(*)[8])(hsm_uint32_t(*)[8])
                    HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tSm3Inf.aResultCacheBuf[0]));

                pCtx->tL1AlgCtx.tSm3Inf.pParm->tCfg.eInputFmt  = pCfg->eInputFmt;
                pCtx->tL1AlgCtx.tSm3Inf.pParm->tCfg.eOutputFmt = HSM_DATA_FORMAT_4B;

                if (HSM_DATA_FORMAT_1B == pCfg->eOutputFmt)
                {
                    pCtx->tL1AlgCtx.tSm3Inf.bSwapOut = HSM_TRUE;
                }
                else
                {
                    pCtx->tL1AlgCtx.tSm3Inf.bSwapOut = HSM_FALSE;
                }

                eRet = HSM_FW_Sm3Ex(&(pCtx->tCmd), pCtx->tL1AlgCtx.tSm3Inf.pParm, pCfg->bKeyUseId);
                if (HSM_STATUS_SUCCESS == eRet)
                {
                    pCtx->eStat = HSM_DRV_SM_ARITH;
                    eRet        = pCtx->pSendCmdCb(&(pCtx->tCmd));
                    if (HSM_STATUS_SUCCESS != eRet)
                    {
                        pCtx->eStat = HSM_DRV_SM_STOP;
                        eRet        = HSM_STATUS_SEND_FAIL;
                    }
                }
                else
                {
                    ;
                }
            }
            else
            {
                eRet = HSM_STATUS_BUSY;
            }
        }
        else
        {
            eRet = HSM_STATUS_LOGIC_ERR;
        }
    }
    else
    {
        eRet = HSM_STATUS_PARAM_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_Sm3_Isr(HSM_L1_RtCtxType *pCtx)
{
    HSM_StatusType eRet;

    if (MAILBOXAPI_RET_SUCCESS == pCtx->tL1AlgCtx.tSm3Inf.pParm->u32HSMStatusRet)
    {
        if (HSM_TRUE == pCtx->tL1AlgCtx.tSm3Inf.bSwapOut)
        {
            hsm_u32_array_swap(
                (hsm_uint32_t *)HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tSm3Inf.aResultCacheBuf[0])),
                32u / 4U); /* sm3 has 32bytes result data */
        }
        else
        {
        }

        hsm_memcpy(pCtx->tL1AlgCtx.tSm3Inf.pResultBuf,
                   pCtx->tL1AlgCtx.tSm3Inf.pParm->tCfg.pRet,
                   pCtx->tL1AlgCtx.tSm3Inf.u32ResultBufSize);

        if (NULL_PTR != pCtx->tL1AlgCtx.tSm3Inf.pOutResultSize)
        {
            hsm_memcpy(pCtx->tL1AlgCtx.tSm3Inf.pOutResultSize,
                       &(pCtx->tL1AlgCtx.tSm3Inf.u32ResultBufSize),
                       sizeof(pCtx->tL1AlgCtx.tSm3Inf.u32ResultBufSize));
        }
        else
        {
            ;
        }
        eRet = HSM_STATUS_SUCCESS;

        pCtx->eStat = HSM_DRV_SM_STOP;
    }
    else
    {
        eRet        = HSM_STATUS_HW_ERR;
        pCtx->eStat = HSM_DRV_SM_STOP;
    }

    return eRet;
}

HSM_StatusType HSM_L1_Sm3Poll(HSM_L1_RtCtxType *pCtx)
{
    HSM_StatusType eRet       = HSM_STATUS_SUCCESS;
    HSM_BoolType   bInProcess = HSM_FALSE;

    bInProcess = pCtx->bInProcess;

    if ((HSM_TRUE == bInProcess) && (HSM_OP_SM3 == pCtx->eOperationCata))
    {
        if (HSM_DRV_SM_ARITH == pCtx->eStat)
        {
            eRet = pCtx->pReadAckCb();
            if (HSM_STATUS_BUSY == eRet)
            {
                eRet = HSM_STATUS_AGAIN;
            }
            else if (HSM_STATUS_SUCCESS == eRet)
            {
                eRet = HSM_L1_Sm3_Isr(pCtx);
            }
            else
            {
                pCtx->eStat = HSM_DRV_SM_STOP;
            }
        }
        else
        {
            eRet = HSM_STATUS_HW_IDLE;
        }
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_ShaSetupEnv(HSM_L1_RtCtxType *pCtx)
{
    HSM_BoolType   bInProcess = HSM_FALSE;
    HSM_StatusType eRet       = HSM_STATUS_SUCCESS;

    bInProcess = pCtx->bInProcess;
    if (HSM_FALSE == bInProcess)
    {
        pCtx->bInProcess              = HSM_TRUE;
        pCtx->eOperationCata          = HSM_OP_SHA;
        pCtx->eStat                   = HSM_DRV_SM_READY;
        pCtx->tL1AlgCtx.tShaInf.pParm = (HSMCom_ShaExType *)HSM_ADDRESS_UP_ALIGN(
            &(pCtx->tL1AlgCtx.tShaInf.aParmBuf[0]));
        pCtx->tL1AlgCtx.tShaInf.pParm->tCfg.pResult = (HSM_ShaResultBufType *)HSM_ADDRESS_UP_ALIGN(
            &(pCtx->tL1AlgCtx.tShaInf.aShaResultCache[0]));
        ;
        eRet = HSM_STATUS_SUCCESS;
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_ShaReset(HSM_L1_RtCtxType *pCtx)
{
    HSM_BoolType   bInProcess = HSM_FALSE;
    HSM_StatusType eRet       = HSM_STATUS_SUCCESS;

    bInProcess = pCtx->bInProcess;

    if ((HSM_TRUE == bInProcess) && (HSM_OP_SHA == pCtx->eOperationCata))
    {
        if (HSM_DRV_SM_ARITH == pCtx->eStat)
        {
            eRet = pCtx->pCancelCmdCb();
        }

        if (HSM_STATUS_SUCCESS == eRet)
        {
            pCtx->eStat = HSM_DRV_SM_READY;
        }
        else
        {
            ;
        }
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_ShaExitEnv(HSM_L1_RtCtxType *pCtx)
{
    HSM_BoolType   bInProcess = pCtx->bInProcess;
    HSM_StatusType eRet       = HSM_STATUS_SUCCESS;

    if ((HSM_TRUE == bInProcess) && (HSM_OP_SHA == pCtx->eOperationCata))
    {
        eRet = HSM_L1_CommonExitEnv(pCtx);
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_Sha(HSM_L1_RtCtxType *pCtx, const HSM_Ln_ShaType *pCfg, hsm_uint32_t u32TimeoutMs)
{
    HSM_StatusType eRet       = HSM_STATUS_SUCCESS;
    HSM_BoolType   bInProcess = HSM_FALSE;
    hsm_uint32_t   u32HashRetSize;

    if ((NULL_PTR != pCtx) && (NULL_PTR != pCfg) && (NULL_PTR != pCfg->pResult) &&
        (pCfg->u32ResultBufSize > 0) &&
        ((HSM_DATA_FORMAT_1B == pCfg->eOutputFmt) ||
         ((pCfg->u32ResultBufSize >= 4u) &&
          (0u == (pCfg->u32ResultBufSize & 0x3))))) /* not check the input address 4byte aligned
                                                       here for eco support this */
    {
        eRet = hsm_hash_get_result_byte_count((HFAM_MODE_E)pCfg->eAlg, &u32HashRetSize);
        if (HSM_STATUS_SUCCESS == eRet)
        {
            bInProcess = pCtx->bInProcess;

            if ((HSM_TRUE == bInProcess) && (HSM_OP_SHA == pCtx->eOperationCata))
            {
                if (HSM_DRV_SM_ARITH != pCtx->eStat)
                {
                    pCtx->tL1AlgCtx.tShaInf.pParm->u32HSMStatusRet = MAILBOXAPI_RET_NONE;
                    pCtx->tL1AlgCtx.tShaInf.pParm->u32Timeout      = u32TimeoutMs;
                    pCtx->tL1AlgCtx.tShaInf.pResultBuf             = pCfg->pResult;
                    if (pCfg->u32ResultBufSize >= u32HashRetSize)
                    {
                        pCtx->tL1AlgCtx.tShaInf.u32ResultBufSize = u32HashRetSize;
                    }
                    else
                    {
                        pCtx->tL1AlgCtx.tShaInf.u32ResultBufSize = pCfg->u32ResultBufSize;
                    }

                    pCtx->tL1AlgCtx.tShaInf.pOutResultSize   = pCfg->pResultSize;
                    pCtx->tL1AlgCtx.tShaInf.pParm->tCfg.eAlg = pCfg->eAlg;

                    hsm_memcpy(&(pCtx->tL1AlgCtx.tShaInf.pParm->tCfg.tCfg),
                               &(pCfg->tCfg),
                               sizeof(HSM_ShaCtxType));
                    pCtx->tL1AlgCtx.tShaInf.pParm->tCfg.eInputFmt  = pCfg->eInputFmt;
                    pCtx->tL1AlgCtx.tShaInf.pParm->tCfg.eOutputFmt = HSM_DATA_FORMAT_4B;

                    if (HSM_DATA_FORMAT_1B == pCfg->eOutputFmt)
                    {
                        pCtx->tL1AlgCtx.tShaInf.bSwapOut = HSM_TRUE;
                    }
                    else
                    {
                        pCtx->tL1AlgCtx.tShaInf.bSwapOut = HSM_FALSE;
                    }

                    eRet = HSM_FW_ShaEx(&(pCtx->tCmd), pCtx->tL1AlgCtx.tShaInf.pParm, pCfg->bKeyUseId);
                    if (HSM_STATUS_SUCCESS == eRet)
                    {
                        pCtx->eStat = HSM_DRV_SM_ARITH;
                        eRet        = pCtx->pSendCmdCb(&(pCtx->tCmd));
                        if (HSM_STATUS_SUCCESS != eRet)
                        {
                            pCtx->eStat = HSM_DRV_SM_STOP;
                            eRet        = HSM_STATUS_SEND_FAIL;
                        }
                    }
                    else
                    {
                        ;
                    }
                }
                else
                {
                    eRet = HSM_STATUS_BUSY;
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
        eRet = HSM_STATUS_PARAM_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_Sha_Isr(HSM_L1_RtCtxType *pCtx)
{
    HSM_StatusType eRet;
    hsm_uint32_t   u32HashRetSize;

    if (MAILBOXAPI_RET_SUCCESS == pCtx->tL1AlgCtx.tShaInf.pParm->u32HSMStatusRet)
    {
        eRet = hsm_hash_get_result_byte_count((HFAM_MODE_E)pCtx->tL1AlgCtx.tShaInf.pParm->tCfg.eAlg,
                                              &u32HashRetSize);
        if (HSM_STATUS_SUCCESS == eRet)
        {
            if (HSM_TRUE == pCtx->tL1AlgCtx.tShaInf.bSwapOut)
            {
                hsm_u32_array_swap(
                    (hsm_uint32_t *)&(pCtx->tL1AlgCtx.tShaInf.pParm->tCfg.pResult->aResult[0]),
                    u32HashRetSize / 4U); /* all result data size is 4*N */
            }
            else
            {
            }

            hsm_memcpy(pCtx->tL1AlgCtx.tShaInf.pResultBuf,
                       &(pCtx->tL1AlgCtx.tShaInf.pParm->tCfg.pResult->aResult[0]),
                       pCtx->tL1AlgCtx.tShaInf.u32ResultBufSize);

            if (NULL_PTR != pCtx->tL1AlgCtx.tShaInf.pOutResultSize)
            {
                hsm_memcpy(pCtx->tL1AlgCtx.tShaInf.pOutResultSize,
                           &(pCtx->tL1AlgCtx.tShaInf.u32ResultBufSize),
                           sizeof(pCtx->tL1AlgCtx.tShaInf.u32ResultBufSize));
            }
            else
            {
                ;
            }
            eRet        = HSM_STATUS_SUCCESS;
            pCtx->eStat = HSM_DRV_SM_STOP;
        }
        else
        {
            eRet        = HSM_STATUS_HW_ERR;
            pCtx->eStat = HSM_DRV_SM_STOP;
        }
    }
    else
    {
        eRet        = HSM_STATUS_HW_ERR;
        pCtx->eStat = HSM_DRV_SM_STOP;
    }

    return eRet;
}

HSM_StatusType HSM_L1_ShaPoll(HSM_L1_RtCtxType *pCtx)
{
    HSM_StatusType eRet       = HSM_STATUS_SUCCESS;
    HSM_BoolType   bInProcess = HSM_FALSE;

    bInProcess = pCtx->bInProcess;

    if ((HSM_TRUE == bInProcess) && (HSM_OP_SHA == pCtx->eOperationCata))
    {
        if (HSM_DRV_SM_ARITH == pCtx->eStat)
        {
            eRet = pCtx->pReadAckCb();
            if (HSM_STATUS_BUSY == eRet)
            {
                eRet = HSM_STATUS_AGAIN;
            }
            else if (HSM_STATUS_SUCCESS == eRet)
            {
                eRet = HSM_L1_Sha_Isr(pCtx);
            }
            else
            {
                pCtx->eStat = HSM_DRV_SM_STOP;
            }
        }
        else
        {
            eRet = HSM_STATUS_HW_IDLE;
        }
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_RngSetupEnv(HSM_L1_RtCtxType *pCtx)
{
    HSM_BoolType   bInProcess = HSM_FALSE;
    HSM_StatusType eRet       = HSM_STATUS_SUCCESS;

    bInProcess = pCtx->bInProcess;
    if (HSM_FALSE == bInProcess)
    {
        pCtx->bInProcess              = HSM_TRUE;
        pCtx->eOperationCata          = HSM_OP_RNG;
        pCtx->eStat                   = HSM_DRV_SM_READY;
        pCtx->tL1AlgCtx.tRngInf.pParm = (HSMCom_TrueRandExType *)HSM_ADDRESS_UP_ALIGN(
            &(pCtx->tL1AlgCtx.tRngInf.aParmBuf[0]));
        pCtx->tL1AlgCtx.tRngInf.pParm->aRandom = (hsm_uint32_t(*)[HSM_TRNG_RAND_U32_CNT])
            HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tRngInf.aRandom[0]));
        eRet = HSM_STATUS_SUCCESS;
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_RngReset(HSM_L1_RtCtxType *pCtx)
{
    HSM_BoolType   bInProcess = HSM_FALSE;
    HSM_StatusType eRet       = HSM_STATUS_SUCCESS;

    bInProcess = pCtx->bInProcess;

    if ((HSM_TRUE == bInProcess) && (HSM_OP_RNG == pCtx->eOperationCata))
    {
        if (HSM_DRV_SM_ARITH == pCtx->eStat)
        {
            eRet = pCtx->pCancelCmdCb();
        }

        if (HSM_STATUS_SUCCESS == eRet)
        {
            pCtx->eStat = HSM_DRV_SM_READY;
        }
        else
        {
            ;
        }
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_RngExitEnv(HSM_L1_RtCtxType *pCtx)
{
    HSM_BoolType   bInProcess = pCtx->bInProcess;
    HSM_StatusType eRet       = HSM_STATUS_SUCCESS;

    if ((HSM_TRUE == bInProcess) && (HSM_OP_RNG == pCtx->eOperationCata))
    {
        eRet = HSM_L1_CommonExitEnv(pCtx);
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_Rng(HSM_L1_RtCtxType *pCtx, const HSM_Ln_RngType *pCfg, hsm_uint32_t u32TimeoutMs)
{
    HSM_StatusType eRet       = HSM_STATUS_SUCCESS;
    HSM_BoolType   bInProcess = HSM_FALSE;

    if ((NULL_PTR != pCtx) && (NULL_PTR != pCfg) && (pCfg->u32ResultBufSize > 0))
    {
        bInProcess = pCtx->bInProcess;

        if ((HSM_TRUE == bInProcess) && (HSM_OP_RNG == pCtx->eOperationCata))
        {
            if (HSM_DRV_SM_ARITH != pCtx->eStat)
            {
                pCtx->tL1AlgCtx.tRngInf.pParm->u32HSMStatusRet = MAILBOXAPI_RET_NONE;
                pCtx->tL1AlgCtx.tRngInf.pParm->u32Timeout      = u32TimeoutMs;
                pCtx->tL1AlgCtx.tRngInf.pParm->u32RandSrc      = pCfg->eSrc;
                pCtx->tL1AlgCtx.tRngInf.pResultBuf             = pCfg->pResult;
                pCtx->tL1AlgCtx.tRngInf.u32ResultBufSize       = pCfg->u32ResultBufSize;
                pCtx->tL1AlgCtx.tRngInf.u32GetSize             = 0u;

                eRet = HSM_TrueRandGet(&(pCtx->tCmd), pCtx->tL1AlgCtx.tRngInf.pParm);
                if (HSM_STATUS_SUCCESS == eRet)
                {
                    pCtx->eStat = HSM_DRV_SM_ARITH;
                    eRet        = pCtx->pSendCmdCb(&(pCtx->tCmd));
                    if (HSM_STATUS_SUCCESS != eRet)
                    {
                        pCtx->eStat = HSM_DRV_SM_STOP;
                        eRet        = HSM_STATUS_SEND_FAIL;
                    }
                }
                else
                {
                    ;
                }
            }
            else
            {
                eRet = HSM_STATUS_BUSY;
            }
        }
        else
        {
            eRet = HSM_STATUS_LOGIC_ERR;
        }
    }
    else
    {
        eRet = HSM_STATUS_PARAM_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_Rng_Isr(HSM_L1_RtCtxType *pCtx)
{
    HSM_StatusType eRet;

    if (MAILBOXAPI_RET_SUCCESS == pCtx->tL1AlgCtx.tRngInf.pParm->u32HSMStatusRet)
    {
        if ((pCtx->tL1AlgCtx.tRngInf.u32GetSize + (sizeof(hsm_uint32_t) * HSM_TRNG_RAND_U32_CNT)) <
            pCtx->tL1AlgCtx.tRngInf.u32ResultBufSize)
        {
            hsm_memcpy(((hsm_uint8_t *)pCtx->tL1AlgCtx.tRngInf.pResultBuf) +
                           pCtx->tL1AlgCtx.tRngInf.u32GetSize,
                       &((*(pCtx->tL1AlgCtx.tRngInf.pParm->aRandom))[0]),
                       (sizeof(hsm_uint32_t) * HSM_TRNG_RAND_U32_CNT));
            pCtx->tL1AlgCtx.tRngInf.u32GetSize += (sizeof(hsm_uint32_t) * HSM_TRNG_RAND_U32_CNT);

            pCtx->tL1AlgCtx.tRngInf.pParm->u32HSMStatusRet = MAILBOXAPI_RET_NONE;

            eRet = HSM_TrueRandGet(&(pCtx->tCmd), pCtx->tL1AlgCtx.tRngInf.pParm);
            if (HSM_STATUS_SUCCESS == eRet)
            {
                eRet = pCtx->pSendCmdCb(&(pCtx->tCmd));
                if (HSM_STATUS_SUCCESS != eRet)
                {
                    pCtx->eStat = HSM_DRV_SM_STOP;
                    eRet        = HSM_STATUS_SEND_FAIL;
                }
                else
                {
                    eRet = HSM_STATUS_AGAIN;
                }
            }
            else
            {
                pCtx->eStat = HSM_DRV_SM_STOP;
                eRet        = HSM_STATUS_ERROR_STOP;
            }
        }
        else
        {
            hsm_memcpy(((hsm_uint8_t *)pCtx->tL1AlgCtx.tRngInf.pResultBuf) +
                           pCtx->tL1AlgCtx.tRngInf.u32GetSize,
                       &((*(pCtx->tL1AlgCtx.tRngInf.pParm->aRandom))[0]),
                       pCtx->tL1AlgCtx.tRngInf.u32ResultBufSize - pCtx->tL1AlgCtx.tRngInf.u32GetSize);
            pCtx->tL1AlgCtx.tRngInf.u32GetSize = pCtx->tL1AlgCtx.tRngInf.u32ResultBufSize;
            pCtx->eStat                        = HSM_DRV_SM_STOP;
            eRet                               = HSM_STATUS_SUCCESS;
        }
    }
    else
    {
        eRet        = HSM_STATUS_HW_ERR;
        pCtx->eStat = HSM_DRV_SM_STOP;
    }

    return eRet;
}

HSM_StatusType HSM_L1_RngPoll(HSM_L1_RtCtxType *pCtx)
{
    HSM_StatusType eRet       = HSM_STATUS_SUCCESS;
    HSM_BoolType   bInProcess = HSM_FALSE;

    bInProcess = pCtx->bInProcess;

    if ((HSM_TRUE == bInProcess) && (HSM_OP_RNG == pCtx->eOperationCata))
    {
        if (HSM_DRV_SM_ARITH == pCtx->eStat)
        {
            eRet = pCtx->pReadAckCb();
            if (HSM_STATUS_BUSY == eRet)
            {
                eRet = HSM_STATUS_AGAIN;
            }
            else if (HSM_STATUS_SUCCESS == eRet)
            {
                eRet = HSM_L1_Rng_Isr(pCtx);
            }
            else
            {
                pCtx->eStat = HSM_DRV_SM_STOP;
            }
        }
        else
        {
            eRet = HSM_STATUS_HW_IDLE;
        }
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_EccVerifySetupEnv(HSM_L1_RtCtxType *pCtx, hsm_uint32_t u32BitCnt)
{
    HSM_BoolType   bInProcess = HSM_FALSE;
    HSM_StatusType eRet       = HSM_STATUS_SUCCESS;

    if ((u32BitCnt <= 1024) && (u32BitCnt >= 1u))
    {
        bInProcess = pCtx->bInProcess;
        if (HSM_FALSE == bInProcess)
        {
            pCtx->bInProcess                         = HSM_TRUE;
            pCtx->eOperationCata                     = HSM_OP_ECC_VERIFY;
            pCtx->tL1AlgCtx.tEccVerifyInf.u32NBitCnt = u32BitCnt;
            pCtx->eStat                              = HSM_DRV_SM_READY;
            pCtx->tL1AlgCtx.tEccVerifyInf.pParm      = (HSMCom_EccVerifyType *)HSM_ADDRESS_UP_ALIGN(
                &(pCtx->tL1AlgCtx.tEccVerifyInf.aParmBuf[0]));
            pCtx->tL1AlgCtx.tEccVerifyInf.pParm->tCfg.tCurve.pP =
                (const hsm_uint32_t *)HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tEccVerifyInf.aP[0]));
            pCtx->tL1AlgCtx.tEccVerifyInf.pParm->tCfg.tCurve.pN =
                (const hsm_uint32_t *)HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tEccVerifyInf.aN[0]));
            pCtx->tL1AlgCtx.tEccVerifyInf.pParm->tCfg.tCurve.pA =
                (const hsm_uint32_t *)HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tEccVerifyInf.aA[0]));
            pCtx->tL1AlgCtx.tEccVerifyInf.pParm->tCfg.tCurve.pB =
                (const hsm_uint32_t *)HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tEccVerifyInf.aB[0]));
            pCtx->tL1AlgCtx.tEccVerifyInf.pParm->tCfg.tCurve.pGx =
                (const hsm_uint32_t *)HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tEccVerifyInf.aGx[0]));
            pCtx->tL1AlgCtx.tEccVerifyInf.pParm->tCfg.tCurve.pGy =
                (const hsm_uint32_t *)HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tEccVerifyInf.aGy[0]));
            pCtx->tL1AlgCtx.tEccVerifyInf.pParm->tCfg.pkG_x =
                (const hsm_uint32_t *)HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tEccVerifyInf.akGx[0]));
            pCtx->tL1AlgCtx.tEccVerifyInf.pParm->tCfg.pkG_y =
                (const hsm_uint32_t *)HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tEccVerifyInf.akGy[0]));
            pCtx->tL1AlgCtx.tEccVerifyInf.pParm->tCfg.pHashData =
                (const hsm_uint32_t *)HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tEccVerifyInf.aHash[0]));
            pCtx->tL1AlgCtx.tEccVerifyInf.pParm->tCfg.pR =
                (const hsm_uint32_t *)HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tEccVerifyInf.aR[0]));
            pCtx->tL1AlgCtx.tEccVerifyInf.pParm->tCfg.pS =
                (const hsm_uint32_t *)HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tEccVerifyInf.aS[0]));

            eRet = HSM_STATUS_SUCCESS;
        }
        else
        {
            eRet = HSM_STATUS_LOGIC_ERR;
        }
    }
    else
    {
        eRet = HSM_STATUS_PARAM_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_EccVerifyExitEnv(HSM_L1_RtCtxType *pCtx)
{
    HSM_BoolType   bInProcess = pCtx->bInProcess;
    HSM_StatusType eRet       = HSM_STATUS_SUCCESS;

    if ((HSM_TRUE == bInProcess) && (HSM_OP_ECC_VERIFY == pCtx->eOperationCata))
    {
        eRet = HSM_L1_CommonExitEnv(pCtx);
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}

/* For interrupt usage */
HSM_StatusType HSM_L1_EccVerify(HSM_L1_RtCtxType           *pCtx,
                                const HSM_L1_EccVerifyType *pCfg,
                                hsm_uint32_t                u32TimeoutMs)
{
    hsm_uint32_t       u32NByteCnt;
    HSM_StatusType     eRet       = HSM_STATUS_SUCCESS;
    HSM_BoolType       bInProcess = HSM_FALSE;
    const hsm_uint8_t *pStart;
    hsm_uint32_t       u32ActualSize;

    if ((NULL_PTR != pCtx) && (NULL_PTR != pCfg))
    {
        bInProcess = pCtx->bInProcess;

        if ((HSM_TRUE == bInProcess) && (HSM_OP_ECC_VERIFY == pCtx->eOperationCata))
        {
            if (HSM_DRV_SM_ARITH != pCtx->eStat)
            {
                u32NByteCnt = ((pCtx->tL1AlgCtx.tEccVerifyInf.u32NBitCnt + 63u) / 64u) * 8u;

                pCtx->tL1AlgCtx.tEccVerifyInf.pParm->u32HSMStatusRet        = MAILBOXAPI_RET_NONE;
                pCtx->tL1AlgCtx.tEccVerifyInf.pParm->u32Timeout             = u32TimeoutMs;
                pCtx->tL1AlgCtx.tEccVerifyInf.pParm->u32UserKeyID_PublicKey = pCfg->u32PublicKeyId;
                pCtx->tL1AlgCtx.tEccVerifyInf.pParm->u32BitCnt =
                    pCtx->tL1AlgCtx.tEccVerifyInf.u32NBitCnt;
                pCtx->tL1AlgCtx.tEccVerifyInf.pParm->u32EccCurve         = pCfg->u32EccCurve;
                pCtx->tL1AlgCtx.tEccVerifyInf.pParm->tCfg.u32DataByteCnt = u32NByteCnt;

                if (HSM_DRV_ECC_CURVE_PRM_IDX_MAX <= pCfg->u32EccCurve)
                {
                    hsm_rm_prefix_zeros(pCfg->eCurveDataFmt,
                                        pCfg->tCurve.pP,
                                        pCfg->tCurve.u32PByteCnt,
                                        &pStart,
                                        &u32ActualSize);
                    hsm_memset((void *)HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tEccVerifyInf.aP[0])),
                               0,
                               u32NByteCnt - u32ActualSize);
                    hsm_memcpy(
                        ((hsm_uint8_t *)HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tEccVerifyInf.aP[0]))) +
                            (u32NByteCnt - u32ActualSize),
                        pStart,
                        u32ActualSize);

                    hsm_rm_prefix_zeros(pCfg->eCurveDataFmt,
                                        pCfg->tCurve.pN,
                                        pCfg->tCurve.u32NByteCnt,
                                        &pStart,
                                        &u32ActualSize);
                    hsm_memset((void *)HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tEccVerifyInf.aN[0])),
                               0,
                               u32NByteCnt - u32ActualSize);
                    hsm_memcpy(
                        ((hsm_uint8_t *)HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tEccVerifyInf.aN[0]))) +
                            (u32NByteCnt - u32ActualSize),
                        pStart,
                        u32ActualSize);

                    hsm_rm_prefix_zeros(pCfg->eCurveDataFmt,
                                        pCfg->tCurve.pA,
                                        pCfg->tCurve.u32AByteCnt,
                                        &pStart,
                                        &u32ActualSize);
                    hsm_memset((void *)HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tEccVerifyInf.aA[0])),
                               0,
                               u32NByteCnt - u32ActualSize);
                    hsm_memcpy(
                        ((hsm_uint8_t *)HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tEccVerifyInf.aA[0]))) +
                            (u32NByteCnt - u32ActualSize),
                        pStart,
                        u32ActualSize);

                    hsm_rm_prefix_zeros(pCfg->eCurveDataFmt,
                                        pCfg->tCurve.pB,
                                        pCfg->tCurve.u32BByteCnt,
                                        &pStart,
                                        &u32ActualSize);
                    hsm_memset((void *)HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tEccVerifyInf.aB[0])),
                               0,
                               u32NByteCnt - u32ActualSize);
                    hsm_memcpy(
                        ((hsm_uint8_t *)HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tEccVerifyInf.aB[0]))) +
                            (u32NByteCnt - u32ActualSize),
                        pStart,
                        u32ActualSize);

                    hsm_rm_prefix_zeros(pCfg->eCurveDataFmt,
                                        pCfg->tCurve.pGx,
                                        pCfg->tCurve.u32GxByteCnt,
                                        &pStart,
                                        &u32ActualSize);
                    hsm_memset((void *)HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tEccVerifyInf.aGx[0])),
                               0,
                               u32NByteCnt - u32ActualSize);
                    hsm_memcpy(((hsm_uint8_t *)HSM_ADDRESS_UP_ALIGN(
                                   &(pCtx->tL1AlgCtx.tEccVerifyInf.aGx[0]))) +
                                   (u32NByteCnt - u32ActualSize),
                               pStart,
                               u32ActualSize);

                    hsm_rm_prefix_zeros(pCfg->eCurveDataFmt,
                                        pCfg->tCurve.pGy,
                                        pCfg->tCurve.u32GyByteCnt,
                                        &pStart,
                                        &u32ActualSize);
                    hsm_memset((void *)HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tEccVerifyInf.aGy[0])),
                               0,
                               u32NByteCnt - u32ActualSize);
                    hsm_memcpy(((hsm_uint8_t *)HSM_ADDRESS_UP_ALIGN(
                                   &(pCtx->tL1AlgCtx.tEccVerifyInf.aGy[0]))) +
                                   (u32NByteCnt - u32ActualSize),
                               pStart,
                               u32ActualSize);

                    if (HSM_DATA_FORMAT_1B == pCfg->eCurveDataFmt)
                    {
                        hsm_u32_array_swap((hsm_uint32_t *)HSM_ADDRESS_UP_ALIGN(
                                               &(pCtx->tL1AlgCtx.tEccVerifyInf.aP[0])),
                                           u32NByteCnt / 4U);
                        hsm_u32_array_swap((hsm_uint32_t *)HSM_ADDRESS_UP_ALIGN(
                                               &(pCtx->tL1AlgCtx.tEccVerifyInf.aN[0])),
                                           u32NByteCnt / 4U);
                        hsm_u32_array_swap((hsm_uint32_t *)HSM_ADDRESS_UP_ALIGN(
                                               &(pCtx->tL1AlgCtx.tEccVerifyInf.aA[0])),
                                           u32NByteCnt / 4U);
                        hsm_u32_array_swap((hsm_uint32_t *)HSM_ADDRESS_UP_ALIGN(
                                               &(pCtx->tL1AlgCtx.tEccVerifyInf.aB[0])),
                                           u32NByteCnt / 4U);
                        hsm_u32_array_swap((hsm_uint32_t *)HSM_ADDRESS_UP_ALIGN(
                                               &(pCtx->tL1AlgCtx.tEccVerifyInf.aGx[0])),
                                           u32NByteCnt / 4U);
                        hsm_u32_array_swap((hsm_uint32_t *)HSM_ADDRESS_UP_ALIGN(
                                               &(pCtx->tL1AlgCtx.tEccVerifyInf.aGy[0])),
                                           u32NByteCnt / 4U);
                    }
                    else
                    {
                        ;
                    }
                }
                else
                {
                    ;
                }

                if (0u == pCfg->u32PublicKeyId)
                {
                    hsm_rm_prefix_zeros(pCfg->ekGxyDataFmt,
                                        pCfg->pkGx,
                                        pCfg->u32kGxByteCnt,
                                        &pStart,
                                        &u32ActualSize);
                    hsm_memset((void *)HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tEccVerifyInf.akGx[0])),
                               0,
                               u32NByteCnt - u32ActualSize);
                    hsm_memcpy(((hsm_uint8_t *)HSM_ADDRESS_UP_ALIGN(
                                   &(pCtx->tL1AlgCtx.tEccVerifyInf.akGx[0]))) +
                                   (u32NByteCnt - u32ActualSize),
                               pStart,
                               u32ActualSize);

                    hsm_rm_prefix_zeros(pCfg->ekGxyDataFmt,
                                        pCfg->pkGy,
                                        pCfg->u32kGyByteCnt,
                                        &pStart,
                                        &u32ActualSize);
                    hsm_memset((void *)HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tEccVerifyInf.akGy[0])),
                               0,
                               u32NByteCnt - u32ActualSize);
                    hsm_memcpy(((hsm_uint8_t *)HSM_ADDRESS_UP_ALIGN(
                                   &(pCtx->tL1AlgCtx.tEccVerifyInf.akGy[0]))) +
                                   (u32NByteCnt - u32ActualSize),
                               pStart,
                               u32ActualSize);

                    if (HSM_DATA_FORMAT_1B == pCfg->ekGxyDataFmt)
                    {
                        hsm_u32_array_swap((hsm_uint32_t *)HSM_ADDRESS_UP_ALIGN(
                                               &(pCtx->tL1AlgCtx.tEccVerifyInf.akGx[0])),
                                           u32NByteCnt / 4U);
                        hsm_u32_array_swap((hsm_uint32_t *)HSM_ADDRESS_UP_ALIGN(
                                               &(pCtx->tL1AlgCtx.tEccVerifyInf.akGy[0])),
                                           u32NByteCnt / 4U);
                    }
                    else
                    {
                        ;
                    }
                }
                else
                {
                    ;
                }

                hsm_rm_prefix_zeros(pCfg->eDataFmt,
                                    pCfg->pData,
                                    pCfg->u32DataByteCnt,
                                    &pStart,
                                    &u32ActualSize);
                hsm_memset((void *)HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tEccVerifyInf.aHash[0])),
                           0,
                           u32NByteCnt - u32ActualSize);
                hsm_memcpy(
                    ((hsm_uint8_t *)HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tEccVerifyInf.aHash[0]))) +
                        (u32NByteCnt - u32ActualSize),
                    pStart,
                    u32ActualSize);
                if (HSM_DATA_FORMAT_1B == pCfg->eDataFmt)
                {
                    hsm_u32_array_swap((hsm_uint32_t *)HSM_ADDRESS_UP_ALIGN(
                                           &(pCtx->tL1AlgCtx.tEccVerifyInf.aHash[0])),
                                       u32NByteCnt / 4U);
                }
                else
                {
                    ;
                }

                hsm_rm_prefix_zeros(pCfg->eRDataFmt,
                                    pCfg->pR,
                                    pCfg->u32RByteCnt,
                                    &pStart,
                                    &u32ActualSize);
                hsm_memset((void *)HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tEccVerifyInf.aR[0])),
                           0,
                           u32NByteCnt - u32ActualSize);
                hsm_memcpy(
                    ((hsm_uint8_t *)HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tEccVerifyInf.aR[0]))) +
                        (u32NByteCnt - u32ActualSize),
                    pStart,
                    u32ActualSize);
                if (HSM_DATA_FORMAT_1B == pCfg->eRDataFmt)
                {
                    hsm_u32_array_swap(
                        (hsm_uint32_t *)HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tEccVerifyInf.aR[0])),
                        u32NByteCnt / 4U);
                }
                else
                {
                    ;
                }

                hsm_rm_prefix_zeros(pCfg->eSDataFmt,
                                    pCfg->pS,
                                    pCfg->u32SByteCnt,
                                    &pStart,
                                    &u32ActualSize);
                hsm_memset((void *)HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tEccVerifyInf.aS[0])),
                           0,
                           u32NByteCnt - u32ActualSize);
                hsm_memcpy(
                    ((hsm_uint8_t *)HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tEccVerifyInf.aS[0]))) +
                        (u32NByteCnt - u32ActualSize),
                    pStart,
                    u32ActualSize);
                if (HSM_DATA_FORMAT_1B == pCfg->eSDataFmt)
                {
                    hsm_u32_array_swap(
                        (hsm_uint32_t *)HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tEccVerifyInf.aS[0])),
                        u32NByteCnt / 4U);
                }
                else
                {
                    ;
                }

                eRet = HSM_EccVerify(&(pCtx->tCmd), pCtx->tL1AlgCtx.tEccVerifyInf.pParm);
                if (HSM_STATUS_SUCCESS == eRet)
                {
                    pCtx->eStat = HSM_DRV_SM_ARITH;
                    eRet        = pCtx->pSendCmdCb(&(pCtx->tCmd));
                    if (HSM_STATUS_SUCCESS != eRet)
                    {
                        pCtx->eStat = HSM_DRV_SM_STOP;
                        eRet        = HSM_STATUS_SEND_FAIL;
                    }
                }
                else
                {
                    ;
                }
            }
            else
            {
                eRet = HSM_STATUS_BUSY;
            }
        }
        else
        {
            eRet = HSM_STATUS_LOGIC_ERR;
        }
    }
    else
    {
        eRet = HSM_STATUS_PARAM_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_EccVerify_Isr(HSM_L1_RtCtxType *pCtx)
{
    HSM_StatusType eRet;

    if (MAILBOXAPI_RET_PASS == pCtx->tL1AlgCtx.tEccVerifyInf.pParm->u32HSMStatusRet)
    {
        eRet        = HSM_STATUS_PASS;
        pCtx->eStat = HSM_DRV_SM_STOP;
    }
    else if (MAILBOXAPI_RET_FAIL == pCtx->tL1AlgCtx.tEccVerifyInf.pParm->u32HSMStatusRet)
    {
        eRet        = HSM_STATUS_FAIL;
        pCtx->eStat = HSM_DRV_SM_STOP;
    }
    else
    {
        eRet        = HSM_STATUS_ERROR;
        pCtx->eStat = HSM_DRV_SM_STOP;
    }

    return eRet;
}

HSM_StatusType HSM_L1_EccVerifyPoll(HSM_L1_RtCtxType *pCtx)
{
    HSM_StatusType eRet       = HSM_STATUS_SUCCESS;
    HSM_BoolType   bInProcess = HSM_FALSE;

    bInProcess = pCtx->bInProcess;

    if ((HSM_TRUE == bInProcess) && (HSM_OP_ECC_VERIFY == pCtx->eOperationCata))
    {
        if (HSM_DRV_SM_ARITH == pCtx->eStat)
        {
            eRet = pCtx->pReadAckCb();
            if (HSM_STATUS_BUSY == eRet)
            {
                eRet = HSM_STATUS_AGAIN;
            }
            else if (HSM_STATUS_SUCCESS == eRet)
            {
                eRet = HSM_L1_EccVerify_Isr(pCtx);
            }
            else
            {
                pCtx->eStat = HSM_DRV_SM_STOP;
            }
        }
        else
        {
            eRet = HSM_STATUS_HW_IDLE;
        }
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_EccVerifyReset(HSM_L1_RtCtxType *pCtx)
{
    HSM_BoolType   bInProcess = HSM_FALSE;
    HSM_StatusType eRet       = HSM_STATUS_SUCCESS;

    bInProcess = pCtx->bInProcess;

    if ((HSM_TRUE == bInProcess) && (HSM_OP_ECC_VERIFY == pCtx->eOperationCata))
    {
        if (HSM_DRV_SM_ARITH == pCtx->eStat)
        {
            eRet = pCtx->pCancelCmdCb();
        }

        if (HSM_STATUS_SUCCESS == eRet)
        {
            pCtx->eStat = HSM_DRV_SM_READY;
        }
        else
        {
            ;
        }
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_EccDecryptSetupEnv(HSM_L1_RtCtxType *pCtx, hsm_uint32_t u32BitCnt)
{
    HSM_BoolType   bInProcess = HSM_FALSE;
    HSM_StatusType eRet       = HSM_STATUS_SUCCESS;

    if ((u32BitCnt <= 1024) && (u32BitCnt >= 1u))
    {
        bInProcess = pCtx->bInProcess;
        if (HSM_FALSE == bInProcess)
        {
            pCtx->bInProcess                          = HSM_TRUE;
            pCtx->eOperationCata                      = HSM_OP_ECC_EASYDECRY;
            pCtx->tL1AlgCtx.tEccDecryptInf.u32NBitCnt = u32BitCnt;
            pCtx->eStat                               = HSM_DRV_SM_READY;
            pCtx->tL1AlgCtx.tEccDecryptInf.pParm = (HSMCom_EccEasyDecryType *)HSM_ADDRESS_UP_ALIGN(
                &(pCtx->tL1AlgCtx.tEccDecryptInf.aParmBuf[0]));
            pCtx->tL1AlgCtx.tEccDecryptInf.pParm->u32BitCnt = u32BitCnt;
            pCtx->tL1AlgCtx.tEccDecryptInf.pParm->tCfg.pP =
                (const hsm_uint32_t *)HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tEccDecryptInf.aP[0]));
            pCtx->tL1AlgCtx.tEccDecryptInf.pParm->tCfg.pN =
                (const hsm_uint32_t *)HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tEccDecryptInf.aN[0]));
            pCtx->tL1AlgCtx.tEccDecryptInf.pParm->tCfg.pCoeffi_A =
                (const hsm_uint32_t *)HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tEccDecryptInf.aA[0]));
            pCtx->tL1AlgCtx.tEccDecryptInf.pParm->tCfg.pCoeffi_B =
                (const hsm_uint32_t *)HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tEccDecryptInf.aB[0]));
            pCtx->tL1AlgCtx.tEccDecryptInf.pParm->tCfg.pOtherSidePublicKey_x =
                (const hsm_uint32_t *)HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tEccDecryptInf.akGx[0]));
            pCtx->tL1AlgCtx.tEccDecryptInf.pParm->tCfg.pOtherSidePublicKey_y =
                (const hsm_uint32_t *)HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tEccDecryptInf.akGy[0]));
            pCtx->tL1AlgCtx.tEccDecryptInf.pParm->tCfg.pPrivateKey = (const hsm_uint32_t *)
                HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tEccDecryptInf.aPrivate[0]));
            pCtx->tL1AlgCtx.tEccDecryptInf.pParm->tCfg.pEncryedData = (const hsm_uint32_t *)
                HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tEccDecryptInf.aEncrypted[0]));
            pCtx->tL1AlgCtx.tEccDecryptInf.pParm->tCfg.pPlainData =
                (hsm_uint32_t *)HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tEccDecryptInf.aPlain[0]));

            eRet = HSM_STATUS_SUCCESS;
        }
        else
        {
            eRet = HSM_STATUS_LOGIC_ERR;
        }
    }
    else
    {
        eRet = HSM_STATUS_PARAM_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_EccDecryptExitEnv(HSM_L1_RtCtxType *pCtx)
{
    HSM_BoolType   bInProcess = pCtx->bInProcess;
    HSM_StatusType eRet       = HSM_STATUS_SUCCESS;

    if ((HSM_TRUE == bInProcess) && (HSM_OP_ECC_EASYDECRY == pCtx->eOperationCata))
    {
        eRet = HSM_L1_CommonExitEnv(pCtx);
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_EccDecrypt(HSM_L1_RtCtxType            *pCtx,
                                 const HSM_Ln_EccDecryptType *pCfg,
                                 hsm_uint32_t                 u32TimeoutMs)
{
    hsm_uint32_t       u32NByteCnt;
    HSM_StatusType     eRet       = HSM_STATUS_SUCCESS;
    HSM_BoolType       bInProcess = HSM_FALSE;
    const hsm_uint8_t *pStart;
    hsm_uint32_t       u32ActualSize;

    if ((NULL_PTR != pCtx) && (NULL_PTR != pCfg))
    {
        bInProcess = pCtx->bInProcess;

        if ((HSM_TRUE == bInProcess) && (HSM_OP_ECC_EASYDECRY == pCtx->eOperationCata))
        {
            if (HSM_DRV_SM_ARITH != pCtx->eStat)
            {
                u32NByteCnt = ((pCtx->tL1AlgCtx.tEccDecryptInf.u32NBitCnt + 63u) / 64u) * 8u;

                pCtx->tL1AlgCtx.tEccDecryptInf.eOutFmt          = pCfg->eOutputDataFmt;
                pCtx->tL1AlgCtx.tEccDecryptInf.pResultBuf       = pCfg->pPlainData;
                pCtx->tL1AlgCtx.tEccDecryptInf.u32ResultBufSize = pCfg->u32PlainDataBufferByteCnt;
                pCtx->tL1AlgCtx.tEccDecryptInf.pResultByteCnt   = pCfg->pPlainResultByteCnt;

                pCtx->tL1AlgCtx.tEccDecryptInf.pParm->u32HSMStatusRet = MAILBOXAPI_RET_NONE;
                pCtx->tL1AlgCtx.tEccDecryptInf.pParm->u32Timeout      = u32TimeoutMs;
                pCtx->tL1AlgCtx.tEccDecryptInf.pParm->u32UserKeyID_PrivateKey = pCfg->u32PrivateKeyId;
                pCtx->tL1AlgCtx.tEccDecryptInf.pParm->u32UserKeyID_PublicKey = pCfg->u32PublicKeyId;
                pCtx->tL1AlgCtx.tEccDecryptInf.pParm->u32BitCnt =
                    pCtx->tL1AlgCtx.tEccDecryptInf.u32NBitCnt;
                pCtx->tL1AlgCtx.tEccDecryptInf.pParm->u32EccCurve       = pCfg->u32EccCurve;
                pCtx->tL1AlgCtx.tEccDecryptInf.pParm->tCfg.u32ByteCount = u32NByteCnt;

                if (HSM_DRV_ECC_CURVE_PRM_IDX_MAX <= pCfg->u32EccCurve)
                {
                    hsm_rm_prefix_zeros(pCfg->eInputDataFmt,
                                        pCfg->tCurve.pP,
                                        pCfg->tCurve.u32PByteCnt,
                                        &pStart,
                                        &u32ActualSize);
                    hsm_memset((void *)HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tEccDecryptInf.aP[0])),
                               0,
                               u32NByteCnt - u32ActualSize);
                    hsm_memcpy(((hsm_uint8_t *)HSM_ADDRESS_UP_ALIGN(
                                   &(pCtx->tL1AlgCtx.tEccDecryptInf.aP[0]))) +
                                   (u32NByteCnt - u32ActualSize),
                               pStart,
                               u32ActualSize);

                    hsm_rm_prefix_zeros(pCfg->eInputDataFmt,
                                        pCfg->tCurve.pN,
                                        pCfg->tCurve.u32NByteCnt,
                                        &pStart,
                                        &u32ActualSize);
                    hsm_memset((void *)HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tEccDecryptInf.aN[0])),
                               0,
                               u32NByteCnt - u32ActualSize);
                    hsm_memcpy(((hsm_uint8_t *)HSM_ADDRESS_UP_ALIGN(
                                   &(pCtx->tL1AlgCtx.tEccDecryptInf.aN[0]))) +
                                   (u32NByteCnt - u32ActualSize),
                               pStart,
                               u32ActualSize);

                    hsm_rm_prefix_zeros(pCfg->eInputDataFmt,
                                        pCfg->tCurve.pA,
                                        pCfg->tCurve.u32AByteCnt,
                                        &pStart,
                                        &u32ActualSize);
                    hsm_memset((void *)HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tEccDecryptInf.aA[0])),
                               0,
                               u32NByteCnt - u32ActualSize);
                    hsm_memcpy(((hsm_uint8_t *)HSM_ADDRESS_UP_ALIGN(
                                   &(pCtx->tL1AlgCtx.tEccDecryptInf.aA[0]))) +
                                   (u32NByteCnt - u32ActualSize),
                               pStart,
                               u32ActualSize);

                    hsm_rm_prefix_zeros(pCfg->eInputDataFmt,
                                        pCfg->tCurve.pB,
                                        pCfg->tCurve.u32BByteCnt,
                                        &pStart,
                                        &u32ActualSize);
                    hsm_memset((void *)HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tEccDecryptInf.aB[0])),
                               0,
                               u32NByteCnt - u32ActualSize);
                    hsm_memcpy(((hsm_uint8_t *)HSM_ADDRESS_UP_ALIGN(
                                   &(pCtx->tL1AlgCtx.tEccDecryptInf.aB[0]))) +
                                   (u32NByteCnt - u32ActualSize),
                               pStart,
                               u32ActualSize);

                    if (HSM_DATA_FORMAT_1B == pCfg->eInputDataFmt)
                    {
                        hsm_u32_array_swap((hsm_uint32_t *)HSM_ADDRESS_UP_ALIGN(
                                               &(pCtx->tL1AlgCtx.tEccDecryptInf.aA[0])),
                                           u32NByteCnt / 4U);
                        hsm_u32_array_swap((hsm_uint32_t *)HSM_ADDRESS_UP_ALIGN(
                                               &(pCtx->tL1AlgCtx.tEccDecryptInf.aB[0])),
                                           u32NByteCnt / 4U);
                        hsm_u32_array_swap((hsm_uint32_t *)HSM_ADDRESS_UP_ALIGN(
                                               &(pCtx->tL1AlgCtx.tEccDecryptInf.aP[0])),
                                           u32NByteCnt / 4U);
                        hsm_u32_array_swap((hsm_uint32_t *)HSM_ADDRESS_UP_ALIGN(
                                               &(pCtx->tL1AlgCtx.tEccDecryptInf.aN[0])),
                                           u32NByteCnt / 4U);
                    }
                    else
                    {
                        ;
                    }
                }
                else
                {
                    ;
                }

                if (0u == pCfg->u32PublicKeyId)
                {
                    hsm_rm_prefix_zeros(pCfg->eInputDataFmt,
                                        pCfg->pkGx,
                                        pCfg->u32kGxByteCnt,
                                        &pStart,
                                        &u32ActualSize);
                    hsm_memset((void *)HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tEccDecryptInf.akGx[0])),
                               0,
                               u32NByteCnt - u32ActualSize);
                    hsm_memcpy(((hsm_uint8_t *)HSM_ADDRESS_UP_ALIGN(
                                   &(pCtx->tL1AlgCtx.tEccDecryptInf.akGx[0]))) +
                                   (u32NByteCnt - u32ActualSize),
                               pStart,
                               u32ActualSize);

                    hsm_rm_prefix_zeros(pCfg->eInputDataFmt,
                                        pCfg->pkGy,
                                        pCfg->u32kGyByteCnt,
                                        &pStart,
                                        &u32ActualSize);
                    hsm_memset((void *)HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tEccDecryptInf.akGy[0])),
                               0,
                               u32NByteCnt - u32ActualSize);
                    hsm_memcpy(((hsm_uint8_t *)HSM_ADDRESS_UP_ALIGN(
                                   &(pCtx->tL1AlgCtx.tEccDecryptInf.akGy[0]))) +
                                   (u32NByteCnt - u32ActualSize),
                               pStart,
                               u32ActualSize);

                    if (HSM_DATA_FORMAT_1B == pCfg->eInputDataFmt)
                    {
                        hsm_u32_array_swap((hsm_uint32_t *)HSM_ADDRESS_UP_ALIGN(
                                               &(pCtx->tL1AlgCtx.tEccDecryptInf.akGx[0])),
                                           u32NByteCnt / 4U);
                        hsm_u32_array_swap((hsm_uint32_t *)HSM_ADDRESS_UP_ALIGN(
                                               &(pCtx->tL1AlgCtx.tEccDecryptInf.akGy[0])),
                                           u32NByteCnt / 4U);
                    }
                    else
                    {
                        ;
                    }
                }
                else
                {
                    ;
                }

                if (0u == pCfg->u32PrivateKeyId)
                {
                    hsm_rm_prefix_zeros(pCfg->eInputDataFmt,
                                        pCfg->pPrivateKey,
                                        pCfg->u32PrivateKeyByteCnt,
                                        &pStart,
                                        &u32ActualSize);
                    hsm_memset(
                        (void *)HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tEccDecryptInf.aPrivate[0])),
                        0,
                        u32NByteCnt - u32ActualSize);
                    hsm_memcpy(((hsm_uint8_t *)HSM_ADDRESS_UP_ALIGN(
                                   &(pCtx->tL1AlgCtx.tEccDecryptInf.aPrivate[0]))) +
                                   (u32NByteCnt - u32ActualSize),
                               pStart,
                               u32ActualSize);

                    if (HSM_DATA_FORMAT_1B == pCfg->eInputDataFmt)
                    {
                        hsm_u32_array_swap((hsm_uint32_t *)HSM_ADDRESS_UP_ALIGN(
                                               &(pCtx->tL1AlgCtx.tEccDecryptInf.aPrivate[0])),
                                           u32NByteCnt / 4U);
                    }
                    else
                    {
                        ;
                    }
                }
                else
                {
                    ;
                }

                hsm_rm_prefix_zeros(pCfg->eInputDataFmt,
                                    pCfg->pEncryptedData,
                                    pCfg->u32EncryptedDataByteCnt,
                                    &pStart,
                                    &u32ActualSize);
                hsm_memset(
                    (void *)HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tEccDecryptInf.aEncrypted[0])),
                    0,
                    u32NByteCnt - u32ActualSize);
                hsm_memcpy(((hsm_uint8_t *)HSM_ADDRESS_UP_ALIGN(
                               &(pCtx->tL1AlgCtx.tEccDecryptInf.aEncrypted[0]))) +
                               (u32NByteCnt - u32ActualSize),
                           pStart,
                           u32ActualSize);
                if (HSM_DATA_FORMAT_1B == pCfg->eInputDataFmt)
                {
                    hsm_u32_array_swap((hsm_uint32_t *)HSM_ADDRESS_UP_ALIGN(
                                           &(pCtx->tL1AlgCtx.tEccDecryptInf.aEncrypted[0])),
                                       u32NByteCnt / 4U);
                }
                else
                {
                    ;
                }

                eRet = HSM_EccEasyDecry(&(pCtx->tCmd), pCtx->tL1AlgCtx.tEccDecryptInf.pParm);
                if (HSM_STATUS_SUCCESS == eRet)
                {
                    pCtx->eStat = HSM_DRV_SM_ARITH;
                    eRet        = pCtx->pSendCmdCb(&(pCtx->tCmd));
                    if (HSM_STATUS_SUCCESS != eRet)
                    {
                        pCtx->eStat = HSM_DRV_SM_STOP;
                        eRet        = HSM_STATUS_SEND_FAIL;
                    }
                }
                else
                {
                    ;
                }
            }
            else
            {
                eRet = HSM_STATUS_BUSY;
            }
        }
        else
        {
            eRet = HSM_STATUS_LOGIC_ERR;
        }
    }
    else
    {
        eRet = HSM_STATUS_PARAM_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_EccDecrypt_Isr(HSM_L1_RtCtxType *pCtx)
{
    const hsm_uint8_t *pStart;
    hsm_uint32_t       u32ActualSize;
    HSM_StatusType     eRet;

    if (MAILBOXAPI_RET_SUCCESS == pCtx->tL1AlgCtx.tEccDecryptInf.pParm->u32HSMStatusRet)
    {
        if (HSM_DATA_FORMAT_1B == pCtx->tL1AlgCtx.tEccDecryptInf.eOutFmt)
        {
            hsm_u32_array_swap(pCtx->tL1AlgCtx.tEccDecryptInf.pParm->tCfg.pPlainData,
                               pCtx->tL1AlgCtx.tEccDecryptInf.pParm->tCfg.u32ByteCount /
                                   4U); /* 4B -> 1B */

            hsm_rm_prefix_zeros(
                HSM_DATA_FORMAT_1B,
                (const hsm_uint8_t *)pCtx->tL1AlgCtx.tEccDecryptInf.pParm->tCfg.pPlainData,
                pCtx->tL1AlgCtx.tEccDecryptInf.pParm->tCfg.u32ByteCount,
                &pStart,
                &u32ActualSize);

            if (u32ActualSize > pCtx->tL1AlgCtx.tEccDecryptInf.u32ResultBufSize)
            {
                eRet = HSM_STATUS_BUFFER_SIZE_ERR;
            }
            else
            {
                hsm_memcpy(pCtx->tL1AlgCtx.tEccDecryptInf.pResultBuf, pStart, u32ActualSize);
                if (0u != pCtx->tL1AlgCtx.tEccDecryptInf.pResultByteCnt)
                {
                    *pCtx->tL1AlgCtx.tEccDecryptInf.pResultByteCnt = u32ActualSize;
                }
                eRet = HSM_STATUS_SUCCESS;
            }
        }
        else
        {
            hsm_rm_prefix_zeros(
                HSM_DATA_FORMAT_4B,
                (const hsm_uint8_t *)pCtx->tL1AlgCtx.tEccDecryptInf.pParm->tCfg.pPlainData,
                pCtx->tL1AlgCtx.tEccDecryptInf.pParm->tCfg.u32ByteCount,
                &pStart,
                &u32ActualSize);

            if (u32ActualSize > pCtx->tL1AlgCtx.tEccDecryptInf.u32ResultBufSize)
            {
                eRet = HSM_STATUS_BUFFER_SIZE_ERR;
            }
            else
            {
                hsm_memcpy(pCtx->tL1AlgCtx.tEccDecryptInf.pResultBuf, pStart, u32ActualSize);
                if (0u != pCtx->tL1AlgCtx.tEccDecryptInf.pResultByteCnt)
                {
                    *pCtx->tL1AlgCtx.tEccDecryptInf.pResultByteCnt = u32ActualSize;
                }
                eRet = HSM_STATUS_SUCCESS;
            }
        }

        pCtx->eStat = HSM_DRV_SM_STOP;
    }
    else
    {
        eRet        = HSM_STATUS_HW_ERR;
        pCtx->eStat = HSM_DRV_SM_STOP;
    }

    return eRet;
}

HSM_StatusType HSM_L1_EccDecryptPoll(HSM_L1_RtCtxType *pCtx)
{
    HSM_StatusType eRet       = HSM_STATUS_SUCCESS;
    HSM_BoolType   bInProcess = HSM_FALSE;

    bInProcess = pCtx->bInProcess;

    if ((HSM_TRUE == bInProcess) && (HSM_OP_ECC_EASYDECRY == pCtx->eOperationCata))
    {
        if (HSM_DRV_SM_ARITH == pCtx->eStat)
        {
            eRet = pCtx->pReadAckCb();
            if (HSM_STATUS_BUSY == eRet)
            {
                eRet = HSM_STATUS_AGAIN;
            }
            else if (HSM_STATUS_SUCCESS == eRet)
            {
                eRet = HSM_L1_EccDecrypt_Isr(pCtx);
            }
            else
            {
                pCtx->eStat = HSM_DRV_SM_STOP;
            }
        }
        else
        {
            eRet = HSM_STATUS_HW_IDLE;
        }
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_EccDecryptReset(HSM_L1_RtCtxType *pCtx)
{
    HSM_BoolType   bInProcess = HSM_FALSE;
    HSM_StatusType eRet       = HSM_STATUS_SUCCESS;

    bInProcess = pCtx->bInProcess;

    if ((HSM_TRUE == bInProcess) && (HSM_OP_ECC_EASYDECRY == pCtx->eOperationCata))
    {
        if (HSM_DRV_SM_ARITH == pCtx->eStat)
        {
            eRet = pCtx->pCancelCmdCb();
        }

        if (HSM_STATUS_SUCCESS == eRet)
        {
            pCtx->eStat = HSM_DRV_SM_READY;
        }
        else
        {
            ;
        }
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_EccCalculateSetupEnv(HSM_L1_RtCtxType *pCtx, hsm_uint32_t u32BitCnt)
{
    HSM_BoolType   bInProcess = HSM_FALSE;
    HSM_StatusType eRet       = HSM_STATUS_SUCCESS;

    if ((u32BitCnt <= 1024) && (u32BitCnt >= 1u))
    {
        bInProcess = pCtx->bInProcess;
        if (HSM_FALSE == bInProcess)
        {
            pCtx->bInProcess                    = HSM_TRUE;
            pCtx->eOperationCata                = HSM_OP_ECC_CALC;
            pCtx->tL1AlgCtx.tEccCalc.u32NBitCnt = u32BitCnt;
            pCtx->eStat                         = HSM_DRV_SM_READY;
            pCtx->tL1AlgCtx.tEccCalc.pParm      = (HSMCom_EccCalcType *)HSM_ADDRESS_UP_ALIGN(
                &(pCtx->tL1AlgCtx.tEccCalc.aParmBuf[0]));
            pCtx->tL1AlgCtx.tEccCalc.pParm->u32BitCnt = u32BitCnt;
            pCtx->tL1AlgCtx.tEccCalc.pParm->tCfg.pCoeffi_A =
                (const hsm_uint32_t *)HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tEccCalc.aA[0]));
            pCtx->tL1AlgCtx.tEccCalc.pParm->tCfg.pCoeffi_B =
                (const hsm_uint32_t *)HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tEccCalc.aB[0]));
            pCtx->tL1AlgCtx.tEccCalc.pParm->tCfg.pP = (const hsm_uint32_t *)HSM_ADDRESS_UP_ALIGN(
                &(pCtx->tL1AlgCtx.tEccCalc.aP[0]));
            pCtx->tL1AlgCtx.tEccCalc.pParm->tCfg.pN = (const hsm_uint32_t *)HSM_ADDRESS_UP_ALIGN(
                &(pCtx->tL1AlgCtx.tEccCalc.aN[0]));
            pCtx->tL1AlgCtx.tEccCalc.pParm->tCfg.pP1x = (const hsm_uint32_t *)HSM_ADDRESS_UP_ALIGN(
                &(pCtx->tL1AlgCtx.tEccCalc.aP1x[0]));
            pCtx->tL1AlgCtx.tEccCalc.pParm->tCfg.pP1y = (const hsm_uint32_t *)HSM_ADDRESS_UP_ALIGN(
                &(pCtx->tL1AlgCtx.tEccCalc.aP1y[0]));
            pCtx->tL1AlgCtx.tEccCalc.pParm->tCfg.pE = (const hsm_uint32_t *)HSM_ADDRESS_UP_ALIGN(
                &(pCtx->tL1AlgCtx.tEccCalc.aE[0]));
            pCtx->tL1AlgCtx.tEccCalc.pParm->tCfg.pP2x = (const hsm_uint32_t *)HSM_ADDRESS_UP_ALIGN(
                &(pCtx->tL1AlgCtx.tEccCalc.aP2x[0]));
            pCtx->tL1AlgCtx.tEccCalc.pParm->tCfg.pResultx = (hsm_uint32_t *)HSM_ADDRESS_UP_ALIGN(
                &(pCtx->tL1AlgCtx.tEccCalc.aResultX[0]));
            pCtx->tL1AlgCtx.tEccCalc.pParm->tCfg.pP2y = (const hsm_uint32_t *)HSM_ADDRESS_UP_ALIGN(
                &(pCtx->tL1AlgCtx.tEccCalc.aP2y[0]));
            pCtx->tL1AlgCtx.tEccCalc.pParm->tCfg.pResulty = (hsm_uint32_t *)HSM_ADDRESS_UP_ALIGN(
                &(pCtx->tL1AlgCtx.tEccCalc.aResultY[0]));

            eRet = HSM_STATUS_SUCCESS;
        }
        else
        {
            eRet = HSM_STATUS_LOGIC_ERR;
        }
    }
    else
    {
        eRet = HSM_STATUS_PARAM_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_EccCalculateExitEnv(HSM_L1_RtCtxType *pCtx)
{
    HSM_BoolType   bInProcess = pCtx->bInProcess;
    HSM_StatusType eRet       = HSM_STATUS_SUCCESS;

    if ((HSM_TRUE == bInProcess) && (HSM_OP_ECC_CALC == pCtx->eOperationCata))
    {
        eRet = HSM_L1_CommonExitEnv(pCtx);
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_EccCalculateKP(HSM_L1_RtCtxType       *pCtx,
                                     const HSM_Ln_EccKPType *pCfg,
                                     hsm_uint32_t            u32TimeoutMs)
{
    hsm_uint32_t       u32NByteCnt;
    HSM_StatusType     eRet       = HSM_STATUS_SUCCESS;
    HSM_BoolType       bInProcess = HSM_FALSE;
    const hsm_uint8_t *pStart;
    hsm_uint32_t       u32ActualSize;

    if ((NULL_PTR != pCtx) && (NULL_PTR != pCfg))
    {
        bInProcess = pCtx->bInProcess;

        if ((HSM_TRUE == bInProcess) && (HSM_OP_ECC_CALC == pCtx->eOperationCata))
        {
            if (HSM_DRV_SM_ARITH != pCtx->eStat)
            {
                u32NByteCnt = ((pCtx->tL1AlgCtx.tEccCalc.u32NBitCnt + 63u) / 64u) * 8u;

                pCtx->tL1AlgCtx.tEccCalc.eOutFmt           = pCfg->eOutputDataFmt;
                pCtx->tL1AlgCtx.tEccCalc.pResultBufX       = pCfg->pResultX;
                pCtx->tL1AlgCtx.tEccCalc.u32ResultBufSizeX = pCfg->u32ResultXBufferByteCnt;
                pCtx->tL1AlgCtx.tEccCalc.pResultByteCntX   = pCfg->pResultXByteCnt;
                pCtx->tL1AlgCtx.tEccCalc.pResultBufY       = pCfg->pResultY;
                pCtx->tL1AlgCtx.tEccCalc.u32ResultBufSizeY = pCfg->u32ResultYBufferByteCnt;
                pCtx->tL1AlgCtx.tEccCalc.pResultByteCntY   = pCfg->pResultYByteCnt;

                pCtx->tL1AlgCtx.tEccCalc.pParm->u32HSMStatusRet = MAILBOXAPI_RET_NONE;
                pCtx->tL1AlgCtx.tEccCalc.pParm->u32Timeout      = u32TimeoutMs;
                pCtx->tL1AlgCtx.tEccCalc.pParm->u32UserKeyID_E  = pCfg->u32KId;
                pCtx->tL1AlgCtx.tEccCalc.pParm->u32UserKeyID_P1 = pCfg->u32PointId;
                pCtx->tL1AlgCtx.tEccCalc.pParm->u32BitCnt   = pCtx->tL1AlgCtx.tEccCalc.u32NBitCnt;
                pCtx->tL1AlgCtx.tEccCalc.pParm->u32EccCurve = pCfg->u32EccCurve;
                pCtx->tL1AlgCtx.tEccCalc.pParm->tCfg.u32ByteCount = u32NByteCnt;

                if (HSM_DRV_ECC_CURVE_PRM_IDX_MAX <= pCfg->u32EccCurve)
                {
                    hsm_rm_prefix_zeros(pCfg->eInputDataFmt,
                                        pCfg->tCurve.pP,
                                        pCfg->tCurve.u32PByteCnt,
                                        &pStart,
                                        &u32ActualSize);
                    hsm_memset((void *)HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tEccCalc.aP[0])),
                               0,
                               u32NByteCnt - u32ActualSize);
                    hsm_memcpy(
                        ((hsm_uint8_t *)HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tEccCalc.aP[0]))) +
                            (u32NByteCnt - u32ActualSize),
                        pStart,
                        u32ActualSize);

                    hsm_rm_prefix_zeros(pCfg->eInputDataFmt,
                                        pCfg->tCurve.pN,
                                        pCfg->tCurve.u32NByteCnt,
                                        &pStart,
                                        &u32ActualSize);
                    hsm_memset((void *)HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tEccCalc.aN[0])),
                               0,
                               u32NByteCnt - u32ActualSize);
                    hsm_memcpy(
                        ((hsm_uint8_t *)HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tEccCalc.aN[0]))) +
                            (u32NByteCnt - u32ActualSize),
                        pStart,
                        u32ActualSize);

                    hsm_rm_prefix_zeros(pCfg->eInputDataFmt,
                                        pCfg->tCurve.pA,
                                        pCfg->tCurve.u32AByteCnt,
                                        &pStart,
                                        &u32ActualSize);
                    hsm_memset((void *)HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tEccCalc.aA[0])),
                               0,
                               u32NByteCnt - u32ActualSize);
                    hsm_memcpy(
                        ((hsm_uint8_t *)HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tEccCalc.aA[0]))) +
                            (u32NByteCnt - u32ActualSize),
                        pStart,
                        u32ActualSize);

                    hsm_rm_prefix_zeros(pCfg->eInputDataFmt,
                                        pCfg->tCurve.pB,
                                        pCfg->tCurve.u32BByteCnt,
                                        &pStart,
                                        &u32ActualSize);
                    hsm_memset((void *)HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tEccCalc.aB[0])),
                               0,
                               u32NByteCnt - u32ActualSize);
                    hsm_memcpy(
                        ((hsm_uint8_t *)HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tEccCalc.aB[0]))) +
                            (u32NByteCnt - u32ActualSize),
                        pStart,
                        u32ActualSize);

                    if (HSM_DATA_FORMAT_1B == pCfg->eInputDataFmt)
                    {
                        hsm_u32_array_swap(
                            (hsm_uint32_t *)HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tEccCalc.aA[0])),
                            u32NByteCnt / 4U);
                        hsm_u32_array_swap(
                            (hsm_uint32_t *)HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tEccCalc.aB[0])),
                            u32NByteCnt / 4U);
                        hsm_u32_array_swap(
                            (hsm_uint32_t *)HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tEccCalc.aP[0])),
                            u32NByteCnt / 4U);
                        hsm_u32_array_swap(
                            (hsm_uint32_t *)HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tEccCalc.aN[0])),
                            u32NByteCnt / 4U);
                    }
                    else
                    {
                        ;
                    }
                }
                else
                {
                    ;
                }

                if (0u == pCfg->u32PointId)
                {
                    hsm_rm_prefix_zeros(pCfg->eInputDataFmt,
                                        pCfg->pPointX,
                                        pCfg->u32PointXByteCnt,
                                        &pStart,
                                        &u32ActualSize);
                    hsm_memset((void *)HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tEccCalc.aP1x[0])),
                               0,
                               u32NByteCnt - u32ActualSize);
                    hsm_memcpy(
                        ((hsm_uint8_t *)HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tEccCalc.aP1x[0]))) +
                            (u32NByteCnt - u32ActualSize),
                        pStart,
                        u32ActualSize);

                    hsm_rm_prefix_zeros(pCfg->eInputDataFmt,
                                        pCfg->pPointY,
                                        pCfg->u32PointYByteCnt,
                                        &pStart,
                                        &u32ActualSize);
                    hsm_memset((void *)HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tEccCalc.aP1y[0])),
                               0,
                               u32NByteCnt - u32ActualSize);
                    hsm_memcpy(
                        ((hsm_uint8_t *)HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tEccCalc.aP1y[0]))) +
                            (u32NByteCnt - u32ActualSize),
                        pStart,
                        u32ActualSize);

                    if (HSM_DATA_FORMAT_1B == pCfg->eInputDataFmt)
                    {
                        hsm_u32_array_swap((hsm_uint32_t *)HSM_ADDRESS_UP_ALIGN(
                                               &(pCtx->tL1AlgCtx.tEccCalc.aP1x[0])),
                                           u32NByteCnt / 4U);
                        hsm_u32_array_swap((hsm_uint32_t *)HSM_ADDRESS_UP_ALIGN(
                                               &(pCtx->tL1AlgCtx.tEccCalc.aP1y[0])),
                                           u32NByteCnt / 4U);
                    }
                    else
                    {
                        ;
                    }
                }
                else
                {
                    ;
                }

                if (0u == pCfg->u32KId)
                {
                    hsm_rm_prefix_zeros(pCfg->eInputDataFmt,
                                        pCfg->pK,
                                        pCfg->u32KByteCnt,
                                        &pStart,
                                        &u32ActualSize);
                    hsm_memset((void *)HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tEccCalc.aE[0])),
                               0,
                               u32NByteCnt - u32ActualSize);
                    hsm_memcpy(
                        ((hsm_uint8_t *)HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tEccCalc.aE[0]))) +
                            (u32NByteCnt - u32ActualSize),
                        pStart,
                        u32ActualSize);

                    if (HSM_DATA_FORMAT_1B == pCfg->eInputDataFmt)
                    {
                        hsm_u32_array_swap(
                            (hsm_uint32_t *)HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tEccCalc.aE[0])),
                            u32NByteCnt / 4U);
                    }
                    else
                    {
                        ;
                    }
                }
                else
                {
                    ;
                }

                hsm_memset((void *)HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tEccCalc.aP2x[0])),
                           0,
                           sizeof(pCtx->tL1AlgCtx.tEccCalc.aP2x));
                hsm_memset((void *)HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tEccCalc.aP2y[0])),
                           0,
                           sizeof(pCtx->tL1AlgCtx.tEccCalc.aP2y));

                pCtx->tL1AlgCtx.tEccCalc.pParm->tCfg.u32CalcType = HSM_ECC_CALC_PMUL;

                eRet = HSM_EccCalculateEx(&(pCtx->tCmd), pCtx->tL1AlgCtx.tEccCalc.pParm);
                if (HSM_STATUS_SUCCESS == eRet)
                {
                    pCtx->eStat = HSM_DRV_SM_ARITH;
                    eRet        = pCtx->pSendCmdCb(&(pCtx->tCmd));
                    if (HSM_STATUS_SUCCESS != eRet)
                    {
                        pCtx->eStat = HSM_DRV_SM_STOP;
                        eRet        = HSM_STATUS_SEND_FAIL;
                    }
                }
                else
                {
                    ;
                }
            }
            else
            {
                eRet = HSM_STATUS_BUSY;
            }
        }
        else
        {
            eRet = HSM_STATUS_LOGIC_ERR;
        }
    }
    else
    {
        eRet = HSM_STATUS_PARAM_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_EccCalculate_Isr(HSM_L1_RtCtxType *pCtx)
{
    const hsm_uint8_t *pStart;
    hsm_uint32_t       u32ActualSize;
    HSM_StatusType     eRet;

    if (MAILBOXAPI_RET_SUCCESS == pCtx->tL1AlgCtx.tEccCalc.pParm->u32HSMStatusRet)
    {
        if (HSM_DATA_FORMAT_1B == pCtx->tL1AlgCtx.tEccCalc.eOutFmt)
        {
            hsm_u32_array_swap(pCtx->tL1AlgCtx.tEccCalc.pParm->tCfg.pResultx,
                               pCtx->tL1AlgCtx.tEccCalc.pParm->tCfg.u32ByteCount / 4U); /* 4B -> 1B */

            hsm_rm_prefix_zeros(HSM_DATA_FORMAT_1B,
                                (const hsm_uint8_t *)pCtx->tL1AlgCtx.tEccCalc.pParm->tCfg.pResultx,
                                pCtx->tL1AlgCtx.tEccCalc.pParm->tCfg.u32ByteCount,
                                &pStart,
                                &u32ActualSize);

            if (u32ActualSize > pCtx->tL1AlgCtx.tEccCalc.u32ResultBufSizeX)
            {
                eRet = HSM_STATUS_BUFFER_SIZE_ERR;
            }
            else
            {
                hsm_memcpy(pCtx->tL1AlgCtx.tEccCalc.pResultBufX, pStart, u32ActualSize);
                if (0u != pCtx->tL1AlgCtx.tEccCalc.pResultByteCntX)
                {
                    *pCtx->tL1AlgCtx.tEccCalc.pResultByteCntX = u32ActualSize;
                }
                eRet = HSM_STATUS_SUCCESS;
            }
        }
        else
        {
            hsm_rm_prefix_zeros(HSM_DATA_FORMAT_4B,
                                (const hsm_uint8_t *)pCtx->tL1AlgCtx.tEccCalc.pParm->tCfg.pResultx,
                                pCtx->tL1AlgCtx.tEccCalc.pParm->tCfg.u32ByteCount,
                                &pStart,
                                &u32ActualSize);

            if (u32ActualSize > pCtx->tL1AlgCtx.tEccCalc.u32ResultBufSizeX)
            {
                eRet = HSM_STATUS_BUFFER_SIZE_ERR;
            }
            else
            {
                hsm_memcpy(pCtx->tL1AlgCtx.tEccCalc.pResultBufX, pStart, u32ActualSize);
                if (pCtx->tL1AlgCtx.tEccCalc.pResultByteCntX)
                {
                    *pCtx->tL1AlgCtx.tEccCalc.pResultByteCntX = u32ActualSize;
                }
                eRet = HSM_STATUS_SUCCESS;
            }
        }

        if (HSM_STATUS_SUCCESS == eRet)
        {
            if (HSM_DATA_FORMAT_1B == pCtx->tL1AlgCtx.tEccCalc.eOutFmt)
            {
                hsm_u32_array_swap(pCtx->tL1AlgCtx.tEccCalc.pParm->tCfg.pResulty,
                                   pCtx->tL1AlgCtx.tEccCalc.pParm->tCfg.u32ByteCount /
                                       4U); /* 4B -> 1B */

                hsm_rm_prefix_zeros(HSM_DATA_FORMAT_1B,
                                    (const hsm_uint8_t *)pCtx->tL1AlgCtx.tEccCalc.pParm->tCfg.pResulty,
                                    pCtx->tL1AlgCtx.tEccCalc.pParm->tCfg.u32ByteCount,
                                    &pStart,
                                    &u32ActualSize);

                if (u32ActualSize > pCtx->tL1AlgCtx.tEccCalc.u32ResultBufSizeX)
                {
                    eRet = HSM_STATUS_BUFFER_SIZE_ERR;
                }
                else
                {
                    hsm_memcpy(pCtx->tL1AlgCtx.tEccCalc.pResultBufY, pStart, u32ActualSize);
                    if (pCtx->tL1AlgCtx.tEccCalc.pResultByteCntY)
                    {
                        *pCtx->tL1AlgCtx.tEccCalc.pResultByteCntY = u32ActualSize;
                    }
                    eRet = HSM_STATUS_SUCCESS;
                }
            }
            else
            {
                hsm_rm_prefix_zeros(HSM_DATA_FORMAT_4B,
                                    (const hsm_uint8_t *)pCtx->tL1AlgCtx.tEccCalc.pParm->tCfg.pResulty,
                                    pCtx->tL1AlgCtx.tEccCalc.pParm->tCfg.u32ByteCount,
                                    &pStart,
                                    &u32ActualSize);

                if (u32ActualSize > pCtx->tL1AlgCtx.tEccCalc.u32ResultBufSizeY)
                {
                    eRet = HSM_STATUS_BUFFER_SIZE_ERR;
                }
                else
                {
                    hsm_memcpy(pCtx->tL1AlgCtx.tEccCalc.pResultBufY, pStart, u32ActualSize);
                    if (0u != pCtx->tL1AlgCtx.tEccCalc.pResultByteCntY)
                    {
                        *pCtx->tL1AlgCtx.tEccCalc.pResultByteCntY = u32ActualSize;
                    }
                    eRet = HSM_STATUS_SUCCESS;
                }
            }
        }
        /* else do nothing */

        pCtx->eStat = HSM_DRV_SM_STOP;
    }
    else
    {
        eRet        = HSM_STATUS_HW_ERR;
        pCtx->eStat = HSM_DRV_SM_STOP;
    }

    return eRet;
}

HSM_StatusType HSM_L1_EccCalculatePoll(HSM_L1_RtCtxType *pCtx)
{
    HSM_StatusType eRet       = HSM_STATUS_SUCCESS;
    HSM_BoolType   bInProcess = HSM_FALSE;

    bInProcess = pCtx->bInProcess;

    if ((HSM_TRUE == bInProcess) && (HSM_OP_ECC_CALC == pCtx->eOperationCata))
    {
        if (HSM_DRV_SM_ARITH == pCtx->eStat)
        {
            eRet = pCtx->pReadAckCb();
            if (HSM_STATUS_BUSY == eRet)
            {
                eRet = HSM_STATUS_AGAIN;
            }
            else if (HSM_STATUS_SUCCESS == eRet)
            {
                if (pCtx->tL1AlgCtx.tEccCalc.pParm->tCfg.u32CalcType != HSM_ECC_CALC_PCHK)
                {
                    eRet = HSM_L1_EccDecrypt_Isr(pCtx);
                }
                else
                {
                    pCtx->eStat = HSM_DRV_SM_STOP;
                    eRet        = HSM_STATUS_ERROR_STOP;
                }
            }
            else
            {
                pCtx->eStat = HSM_DRV_SM_STOP;
            }
        }
        else
        {
            eRet = HSM_STATUS_HW_IDLE;
        }
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_EccCalculateReset(HSM_L1_RtCtxType *pCtx)
{
    HSM_BoolType   bInProcess = HSM_FALSE;
    HSM_StatusType eRet       = HSM_STATUS_SUCCESS;

    bInProcess = pCtx->bInProcess;

    if ((HSM_TRUE == bInProcess) && (HSM_OP_ECC_CALC == pCtx->eOperationCata))
    {
        if (HSM_DRV_SM_ARITH == pCtx->eStat)
        {
            eRet = pCtx->pCancelCmdCb();
        }

        if (HSM_STATUS_SUCCESS == eRet)
        {
            pCtx->eStat = HSM_DRV_SM_READY;
        }
        else
        {
            ;
        }
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_CMacSetupEnv(HSM_L1_RtCtxType *pCtx)
{
    HSM_BoolType   bInProcess = HSM_FALSE;
    HSM_StatusType eRet       = HSM_STATUS_SUCCESS;

    bInProcess = pCtx->bInProcess;
    if (HSM_FALSE == bInProcess)
    {
        pCtx->bInProcess               = HSM_TRUE;
        pCtx->eOperationCata           = HSM_OP_CMAC;
        pCtx->eStat                    = HSM_DRV_SM_READY;
        pCtx->tL1AlgCtx.tCMacInf.pParm = (HSMCom_CMacExType *)HSM_ADDRESS_UP_ALIGN(
            &(pCtx->tL1AlgCtx.tCMacInf.aParmBuf[0]));
        pCtx->tL1AlgCtx.tCMacInf.pParm->tCfg.pDataOutput = (hsm_uint32_t *)HSM_ADDRESS_UP_ALIGN(
            &pCtx->tL1AlgCtx.tCMacInf.aResultCacheBuf[0]);
        pCtx->tL1AlgCtx.tCMacInf.pParm->tCfg.u32OutputMemSize = sizeof(
            pCtx->tL1AlgCtx.tCMacInf.aResultCacheBuf);

        eRet = HSM_STATUS_SUCCESS;
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_CMacReset(HSM_L1_RtCtxType *pCtx)
{
    HSM_BoolType   bInProcess = HSM_FALSE;
    HSM_StatusType eRet       = HSM_STATUS_SUCCESS;

    bInProcess = pCtx->bInProcess;

    if ((HSM_TRUE == bInProcess) && (HSM_OP_CMAC == pCtx->eOperationCata))
    {
        if (HSM_DRV_SM_ARITH == pCtx->eStat)
        {
            eRet = pCtx->pCancelCmdCb();
        }

        if (HSM_STATUS_SUCCESS == eRet)
        {
            pCtx->eStat = HSM_DRV_SM_READY;
        }
        else
        {
            ;
        }
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_CMacExitEnv(HSM_L1_RtCtxType *pCtx)
{
    HSM_BoolType   bInProcess = pCtx->bInProcess;
    HSM_StatusType eRet       = HSM_STATUS_SUCCESS;

    if ((HSM_TRUE == bInProcess) && (HSM_OP_CMAC == pCtx->eOperationCata))
    {
        eRet = HSM_L1_CommonExitEnv(pCtx);
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_CMac(HSM_L1_RtCtxType      *pCtx,
                           const HSM_Ln_CMacType *pCfg,
                           hsm_uint32_t           u32TimeoutMs)
{
    HSM_StatusType eRet       = HSM_STATUS_SUCCESS;
    HSM_BoolType   bInProcess = HSM_FALSE;
    hsm_uint32_t  *pInputCache;
    hsm_uint32_t   u32GenMacByteCnt;
    hsm_uint32_t   u32ActualGenMacByteCnt;

    if ((NULL_PTR != pCtx) && (NULL_PTR != pCfg) &&
        ((NULL_PTR != pCfg->pDataOutput) ||
         ((HSM_FALSE != pCfg->bCheckMacEn) && (NULL_PTR != pCfg->pVerifyResult))) &&
        ((HSM_DATA_FORMAT_1B == pCfg->eOutputFmt) ||
         ((pCfg->u32ResultBufSize >= 4u) && (0u == (pCfg->u32ResultBufSize & 0x3)))) &&
        ((HSM_FALSE == pCfg->bCheckMacEn) || (HSM_DATA_FORMAT_1B == pCfg->eOutputFmt) ||
         ((pCfg->u32CheckByteCnt >= 4u) &&
          (0u == (pCfg->u32CheckByteCnt & 0x3))))) /* not check the input address 4byte aligned here
                                                      for eco support this */
    {
        bInProcess = pCtx->bInProcess;

        if (HSM_XCMAC_ENGINE_AES == pCfg->eEngine)
        {
            if (HSM_AES_KEY_NEW == pCfg->eUseKeyType)
            {
                if (HSM_AES_KEY128 == pCfg->tNewKeyInf.eKeyType)
                {
                    u32ActualGenMacByteCnt = 16u;
                    if (pCfg->u32GenMacByteCnt > 16u)
                    {
                        u32GenMacByteCnt = 16u;
                    }
                    else
                    {
                        u32GenMacByteCnt = pCfg->u32GenMacByteCnt;
                    }
                }
                else if (HSM_AES_KEY192 == pCfg->tNewKeyInf.eKeyType)
                {
                    u32ActualGenMacByteCnt = 16u;

                    if (pCfg->u32GenMacByteCnt > 16u)
                    {
                        u32GenMacByteCnt = 16u;
                    }
                    else
                    {
                        u32GenMacByteCnt = pCfg->u32GenMacByteCnt;
                    }
                }
                else if (HSM_AES_KEY256 == pCfg->tNewKeyInf.eKeyType)
                {
                    u32ActualGenMacByteCnt = 16u;

                    if (pCfg->u32GenMacByteCnt > 16u)
                    {
                        u32GenMacByteCnt = 16u;
                    }
                    else
                    {
                        u32GenMacByteCnt = pCfg->u32GenMacByteCnt;
                    }
                }
                else
                {
                    eRet = HSM_STATUS_PARAM_ERR;
                }
            }
            else if (HSM_AES_KEY_CHIP_VENDOR_IFR == pCfg->eUseKeyType)
            {
                if (HSM_AES_KEY128 == pCfg->tVendorKeyInf.eKeyType)
                {
                    u32ActualGenMacByteCnt = 16u;
                    if (pCfg->u32GenMacByteCnt > 16u)
                    {
                        u32GenMacByteCnt = 16u;
                    }
                    else
                    {
                        u32GenMacByteCnt = pCfg->u32GenMacByteCnt;
                    }
                }
                else if (HSM_AES_KEY192 == pCfg->tVendorKeyInf.eKeyType)
                {
                    u32ActualGenMacByteCnt = 16u;

                    if (pCfg->u32GenMacByteCnt > 16u)
                    {
                        u32GenMacByteCnt = 16u;
                    }
                    else
                    {
                        u32GenMacByteCnt = pCfg->u32GenMacByteCnt;
                    }
                }
                else if (HSM_AES_KEY256 == pCfg->tVendorKeyInf.eKeyType)
                {
                    u32ActualGenMacByteCnt = 16u;

                    if (pCfg->u32GenMacByteCnt > 16u)
                    {
                        u32GenMacByteCnt = 16u;
                    }
                    else
                    {
                        u32GenMacByteCnt = pCfg->u32GenMacByteCnt;
                    }
                }
                else
                {
                    eRet = HSM_STATUS_PARAM_ERR;
                }
            }
            else
            {
                eRet = HSM_STATUS_PARAM_ERR;
            }
        }
        else
        {
            if (HSM_AES_KEY_NEW == pCfg->eUseKeyType)
            {
                if (HSM_AES_KEY128 == pCfg->tNewKeyInf.eKeyType)
                {
                    u32ActualGenMacByteCnt = 16u;
                    if (pCfg->u32GenMacByteCnt > 16u)
                    {
                        u32GenMacByteCnt = 16u;
                    }
                    else
                    {
                        u32GenMacByteCnt = pCfg->u32GenMacByteCnt;
                    }
                }
                else
                {
                    eRet = HSM_STATUS_PARAM_ERR;
                }
            }
            else if (HSM_AES_KEY_CHIP_VENDOR_IFR == pCfg->eUseKeyType)
            {
                if (HSM_AES_KEY128 == pCfg->tVendorKeyInf.eKeyType)
                {
                    u32ActualGenMacByteCnt = 16u;
                    if (pCfg->u32GenMacByteCnt > 16u)
                    {
                        u32GenMacByteCnt = 16u;
                    }
                    else
                    {
                        u32GenMacByteCnt = pCfg->u32GenMacByteCnt;
                    }
                }
                else
                {
                    eRet = HSM_STATUS_PARAM_ERR;
                }
            }
            else
            {
                eRet = HSM_STATUS_PARAM_ERR;
            }
        }

        if (HSM_STATUS_SUCCESS == eRet)
        {
            if ((HSM_TRUE == bInProcess) && (HSM_OP_CMAC == pCtx->eOperationCata))
            {
                if (HSM_DRV_SM_ARITH != pCtx->eStat)
                {
                    if (u32GenMacByteCnt > pCfg->u32ResultBufSize)
                    {
                        u32GenMacByteCnt = pCfg->u32ResultBufSize;
                    }

                    pCtx->tL1AlgCtx.tCMacInf.pResultBuf              = pCfg->pDataOutput;
                    pCtx->tL1AlgCtx.tCMacInf.u32ResultBufByteCnt     = u32GenMacByteCnt;
                    pCtx->tL1AlgCtx.tCMacInf.pOutResultSize          = pCfg->pResultSize;
                    pCtx->tL1AlgCtx.tCMacInf.bCheckMac               = pCfg->bCheckMacEn;
                    pCtx->tL1AlgCtx.tCMacInf.pMacToCheck             = pCfg->pCheckExternalMac;
                    pCtx->tL1AlgCtx.tCMacInf.u32MacToCheckByteCnt    = pCfg->u32CheckByteCnt;
                    pCtx->tL1AlgCtx.tCMacInf.pVerifyResult           = pCfg->pVerifyResult;
                    pCtx->tL1AlgCtx.tCMacInf.pParm->u32HSMStatusRet  = MAILBOXAPI_RET_NONE;
                    pCtx->tL1AlgCtx.tCMacInf.pParm->u32Timeout       = u32TimeoutMs;
                    pCtx->tL1AlgCtx.tCMacInf.pParm->u32UserKeyID     = pCfg->u32NewKeyId;
                    pCtx->tL1AlgCtx.tCMacInf.pParm->tCfg.eUseKeyType = pCfg->eUseKeyType;
                    hsm_memcpy(&(pCtx->tL1AlgCtx.tCMacInf.pParm->tCfg.tNewKeyInf),
                               &(pCfg->tNewKeyInf),
                               sizeof(HSM_AesNewKeyInfType));
                    hsm_memcpy(&(pCtx->tL1AlgCtx.tCMacInf.pParm->tCfg.tVendorKeyInf),
                               &(pCfg->tVendorKeyInf),
                               sizeof(HSM_AesVendorKeyInfType));
                    pCtx->tL1AlgCtx.tCMacInf.pParm->tCfg.u32GenMacByteCnt = u32ActualGenMacByteCnt;
                    pCtx->tL1AlgCtx.tCMacInf.pParm->tCfg.bCheckMacEn      = HSM_FALSE;
                    pCtx->tL1AlgCtx.tCMacInf.pParm->tCfg.pDataInput =
                        (const hsm_uint32_t *)pCfg->pDataInput;
                    pCtx->tL1AlgCtx.tCMacInf.pParm->tCfg.u32InputByteCnt = pCfg->u32InputByteCnt;
                    pCtx->tL1AlgCtx.tCMacInf.pParm->tCfg.eEngine         = pCfg->eEngine;

                    if ((HSM_DATA_FORMAT_1B == pCfg->eInputFmt) && (0u == pCfg->u32NewKeyId) &&
                        (pCfg->u32InputByteCnt <=
                         (sizeof(pCtx->tL1AlgCtx.tCMacInf.aInputCacheBuf) - 4u)))
                    {
                        pInputCache = (hsm_uint32_t *)HSM_ADDRESS_UP_ALIGN(
                            &(pCtx->tL1AlgCtx.tCMacInf.aInputCacheBuf[0]));
                        hsm_core_swap_u32_array_pad(pInputCache,
                                                    (pCfg->u32InputByteCnt + 3u) >> 2u,
                                                    pCfg->pDataInput,
                                                    pCfg->u32InputByteCnt,
                                                    0u,
                                                    HSM_TRUE,
                                                    HSM_TRUE);

                        pCtx->tL1AlgCtx.tCMacInf.pParm->tCfg.pDataInput = pInputCache;

                        if (HSM_AES_KEY_NEW == pCfg->eUseKeyType)
                        {
                            pInputCache = (hsm_uint32_t *)HSM_ADDRESS_UP_ALIGN(
                                &(pCtx->tL1AlgCtx.tCMacInf.aResultCacheBuf[0]));
                            if (HSM_AES_KEY128 == pCfg->tNewKeyInf.eKeyType)
                            {
                                hsm_core_swap_u32_array_pad(pInputCache,
                                                            4U,
                                                            pCfg->tNewKeyInf.pKeyAddr,
                                                            16U,
                                                            0u,
                                                            HSM_TRUE,
                                                            HSM_TRUE);
                            }
                            else if (HSM_AES_KEY192 == pCfg->tNewKeyInf.eKeyType)
                            {
                                hsm_core_swap_u32_array_pad(pInputCache,
                                                            6U,
                                                            pCfg->tNewKeyInf.pKeyAddr,
                                                            24U,
                                                            0u,
                                                            HSM_TRUE,
                                                            HSM_TRUE);
                            }
                            else /* AES 256 */
                            {
                                hsm_core_swap_u32_array_pad(pInputCache,
                                                            8U,
                                                            pCfg->tNewKeyInf.pKeyAddr,
                                                            32U,
                                                            0u,
                                                            HSM_TRUE,
                                                            HSM_TRUE);
                            }

                            pCtx->tL1AlgCtx.tCMacInf.pParm->tCfg.tNewKeyInf.pKeyAddr =
                                (const hsm_uint8_t *)pInputCache;
                        }

                        pCtx->tL1AlgCtx.tCMacInf.pParm->tCfg.eInputFmt = HSM_DATA_FORMAT_4B;
                    }
                    else
                    {
                        pCtx->tL1AlgCtx.tCMacInf.pParm->tCfg.eInputFmt = pCfg->eInputFmt;
                    }

                    pCtx->tL1AlgCtx.tCMacInf.pParm->tCfg.eOutputFmt = HSM_DATA_FORMAT_4B;

                    if (HSM_DATA_FORMAT_1B == pCfg->eOutputFmt)
                    {
                        pCtx->tL1AlgCtx.tCMacInf.bSwapOut = HSM_TRUE;
                    }
                    else
                    {
                        pCtx->tL1AlgCtx.tCMacInf.bSwapOut = HSM_FALSE;
                    }

                    eRet = HSM_CMacEx(&(pCtx->tCmd), pCtx->tL1AlgCtx.tCMacInf.pParm);
                    if (HSM_STATUS_SUCCESS == eRet)
                    {
                        pCtx->eStat = HSM_DRV_SM_ARITH;
                        eRet        = pCtx->pSendCmdCb(&(pCtx->tCmd));
                        if (HSM_STATUS_SUCCESS != eRet)
                        {
                            pCtx->eStat = HSM_DRV_SM_STOP;
                            eRet        = HSM_STATUS_SEND_FAIL;
                        }
                    }
                    else
                    {
                        ;
                    }
                }
                else
                {
                    eRet = HSM_STATUS_BUSY;
                }
            }
            else
            {
                eRet = HSM_STATUS_LOGIC_ERR;
            }
        }
    }
    else
    {
        eRet = HSM_STATUS_PARAM_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_CMac_Isr(HSM_L1_RtCtxType *pCtx)
{
    HSM_StatusType          eRet;
    Crypto_VerifyResultType eVerifyRet;

    if (MAILBOXAPI_RET_SUCCESS == pCtx->tL1AlgCtx.tCMacInf.pParm->u32HSMStatusRet)
    {
        if (HSM_TRUE == pCtx->tL1AlgCtx.tCMacInf.bSwapOut)
        {
            hsm_u32_array_swap(pCtx->tL1AlgCtx.tCMacInf.pParm->tCfg.pDataOutput,
                               (pCtx->tL1AlgCtx.tCMacInf.pParm->tCfg.u32GenMacByteCnt + 3u) >> 2u);
        }
        else
        {
        }

        if (HSM_TRUE == (pCtx->tL1AlgCtx.tCMacInf.bCheckMac))
        {
            if (0 == hsm_memcmp(pCtx->tL1AlgCtx.tCMacInf.pParm->tCfg.pDataOutput,
                                pCtx->tL1AlgCtx.tCMacInf.pMacToCheck,
                                pCtx->tL1AlgCtx.tCMacInf.u32MacToCheckByteCnt))
            {
                eVerifyRet = CRYPTO_E_VER_OK;
            }
            else
            {
                eVerifyRet = CRYPTO_E_VER_NOT_OK;
            }

            if (NULL_PTR != (pCtx->tL1AlgCtx.tCMacInf.pVerifyResult))
            {
                hsm_memcpy(pCtx->tL1AlgCtx.tCMacInf.pVerifyResult, &eVerifyRet, sizeof(eVerifyRet));
            }
            else
            {
                ;
            }
        }

        if (NULL_PTR != (pCtx->tL1AlgCtx.tCMacInf.pResultBuf))
        {
            hsm_memcpy(pCtx->tL1AlgCtx.tCMacInf.pResultBuf,
                       pCtx->tL1AlgCtx.tCMacInf.pParm->tCfg.pDataOutput,
                       pCtx->tL1AlgCtx.tCMacInf.u32ResultBufByteCnt);
        }
        else
        {
        }

        if (NULL_PTR != pCtx->tL1AlgCtx.tCMacInf.pOutResultSize)
        {
            hsm_memcpy(pCtx->tL1AlgCtx.tCMacInf.pOutResultSize,
                       &(pCtx->tL1AlgCtx.tCMacInf.u32ResultBufByteCnt),
                       sizeof(pCtx->tL1AlgCtx.tCMacInf.u32ResultBufByteCnt));
        }
        else
        {
        }

        eRet        = HSM_STATUS_SUCCESS;
        pCtx->eStat = HSM_DRV_SM_STOP;
    }
    else
    {
        eRet        = HSM_STATUS_HW_ERR;
        pCtx->eStat = HSM_DRV_SM_STOP;
    }

    return eRet;
}

HSM_StatusType HSM_L1_CMacPoll(HSM_L1_RtCtxType *pCtx)
{
    HSM_StatusType eRet       = HSM_STATUS_SUCCESS;
    HSM_BoolType   bInProcess = HSM_FALSE;

    bInProcess = pCtx->bInProcess;

    if ((HSM_TRUE == bInProcess) && (HSM_OP_CMAC == pCtx->eOperationCata))
    {
        if (HSM_DRV_SM_ARITH == pCtx->eStat)
        {
            eRet = pCtx->pReadAckCb();
            if (HSM_STATUS_BUSY == eRet)
            {
                eRet = HSM_STATUS_AGAIN;
            }
            else if (HSM_STATUS_SUCCESS == eRet)
            {
                eRet = HSM_L1_CMac_Isr(pCtx);
            }
            else
            {
                pCtx->eStat = HSM_DRV_SM_STOP;
            }
        }
        else
        {
            eRet = HSM_STATUS_HW_IDLE;
        }
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_AesEncryptSetupEnv(HSM_L1_RtCtxType *pCtx)
{
    HSM_BoolType   bInProcess = HSM_FALSE;
    HSM_StatusType eRet       = HSM_STATUS_SUCCESS;

    bInProcess = pCtx->bInProcess;
    if (HSM_FALSE == bInProcess)
    {
        pCtx->bInProcess                     = HSM_TRUE;
        pCtx->eOperationCata                 = HSM_OP_AES_ENCRYPT;
        pCtx->eStat                          = HSM_DRV_SM_READY;
        pCtx->tL1AlgCtx.tAesEncryptInf.pParm = (HSMCom_FlexAesEncryptType *)HSM_ADDRESS_UP_ALIGN(
            &(pCtx->tL1AlgCtx.tAesEncryptInf.aParmBuf[0]));

        eRet = HSM_STATUS_SUCCESS;
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_AesEncryptReset(HSM_L1_RtCtxType *pCtx)
{
    HSM_BoolType   bInProcess = HSM_FALSE;
    HSM_StatusType eRet       = HSM_STATUS_SUCCESS;

    bInProcess = pCtx->bInProcess;

    if ((HSM_TRUE == bInProcess) && (HSM_OP_AES_ENCRYPT == pCtx->eOperationCata))
    {
        if (HSM_DRV_SM_ARITH == pCtx->eStat)
        {
            eRet = pCtx->pCancelCmdCb();
        }

        if (HSM_STATUS_SUCCESS == eRet)
        {
            pCtx->eStat = HSM_DRV_SM_READY;
        }
        else
        {
            ;
        }
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_AesEncryptExitEnv(HSM_L1_RtCtxType *pCtx)
{
    HSM_BoolType   bInProcess = pCtx->bInProcess;
    HSM_StatusType eRet       = HSM_STATUS_SUCCESS;

    if ((HSM_TRUE == bInProcess) && (HSM_OP_AES_ENCRYPT == pCtx->eOperationCata))
    {
        eRet = HSM_L1_CommonExitEnv(pCtx);
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_AesEncrypt(HSM_L1_RtCtxType            *pCtx,
                                 const HSM_Ln_AesEncryptType *pCfg,
                                 hsm_uint32_t                 u32TimeoutMs)
{
    HSM_StatusType eRet       = HSM_STATUS_SUCCESS;
    HSM_BoolType   bInProcess = HSM_FALSE;
    hsm_uint32_t  *pInputCache;
    hsm_uint32_t   u32ResultLen;

    if ((NULL_PTR != pCtx) && (NULL_PTR != pCfg) &&
        (pCfg->u32InputByteCnt >
         0u)) /* not check the input address 4byte aligned here for eco support this */
    {
        if (HSM_FLEXAES_PAD_ZERO == pCfg->ePad)
        {
            u32ResultLen = (pCfg->u32InputByteCnt + 0xfu) & 0xfffffff0u;
        }
        else /* HSM_FLEXAES_PAD_PKCS7 */
        {
            u32ResultLen = (pCfg->u32InputByteCnt + 0x10u) & 0xfffffff0u;
        }

        if (u32ResultLen <= pCfg->u32OutputMemSize)
        {
            bInProcess = pCtx->bInProcess;
            if ((HSM_TRUE == bInProcess) && (HSM_OP_AES_ENCRYPT == pCtx->eOperationCata))
            {
                if (HSM_DRV_SM_ARITH != pCtx->eStat)
                {
                    pCtx->tL1AlgCtx.tAesEncryptInf.pParm->u32HSMStatusRet  = MAILBOXAPI_RET_NONE;
                    pCtx->tL1AlgCtx.tAesEncryptInf.pParm->u32Timeout       = u32TimeoutMs;
                    pCtx->tL1AlgCtx.tAesEncryptInf.pParm->u32UserKeyID     = pCfg->u32KeyId;
                    pCtx->tL1AlgCtx.tAesEncryptInf.pParm->tCfg.eUseKeyType = pCfg->eUseKeyType;
                    hsm_memcpy(&(pCtx->tL1AlgCtx.tAesEncryptInf.pParm->tCfg.tNewKeyInf),
                               &(pCfg->tNewKeyInf),
                               sizeof(HSM_AesNewKeyInfType));
                    hsm_memcpy(&(pCtx->tL1AlgCtx.tAesEncryptInf.pParm->tCfg.tVendorKeyInf),
                               &(pCfg->tVendorKeyInf),
                               sizeof(HSM_AesVendorKeyInfType));
                    pCtx->tL1AlgCtx.tAesEncryptInf.pParm->tCfg.eAesAlg    = pCfg->eAesAlg;
                    pCtx->tL1AlgCtx.tAesEncryptInf.pParm->tCfg.pDataInput = pCfg->pDataInput;
                    pCtx->tL1AlgCtx.tAesEncryptInf.pParm->tCfg.u32InputByteCnt = pCfg->u32InputByteCnt;
                    pCtx->tL1AlgCtx.tAesEncryptInf.pParm->tCfg.pDataOutput = pCfg->pDataOutput;
                    pCtx->tL1AlgCtx.tAesEncryptInf.pParm->tCfg.u32OutputMemSize =
                        pCfg->u32OutputMemSize;
                    pCtx->tL1AlgCtx.tAesEncryptInf.pParm->tCfg.pIvData = (hsm_uint8_t *)
                        HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tAesEncryptInf.aIvData[0]));
                    pCtx->tL1AlgCtx.tAesEncryptInf.pParm->tCfg.ePad       = pCfg->ePad;
                    pCtx->tL1AlgCtx.tAesEncryptInf.pParm->tCfg.eInputFmt  = pCfg->eInputFmt;
                    pCtx->tL1AlgCtx.tAesEncryptInf.pParm->tCfg.eOutputFmt = pCfg->eOutputFmt;

                    if (NULL_PTR != pCfg->pGenerateOutByteCnt)
                    {
                        pCtx->tL1AlgCtx.tAesEncryptInf.pParm->tCfg.pGenerateOutByteCnt =
                            pCfg->pGenerateOutByteCnt;
                    }
                    else
                    {
                        pCtx->tL1AlgCtx.tAesEncryptInf.pParm->tCfg.pGenerateOutByteCnt = &(
                            pCtx->tL1AlgCtx.tAesEncryptInf.u32HsmRetResultSize);
                    }

                    if ((HSM_DATA_FORMAT_1B == pCfg->eInputFmt) && (0u == pCfg->u32KeyId) &&
                        (pCfg->u32InputByteCnt <=
                         (sizeof(pCtx->tL1AlgCtx.tAesEncryptInf.aInputCacheBuf) - 4u)))
                    {
                        pInputCache = (hsm_uint32_t *)HSM_ADDRESS_UP_ALIGN(
                            &(pCtx->tL1AlgCtx.tAesEncryptInf.aInputCacheBuf[0]));
                        hsm_core_swap_u32_array_pad(pInputCache,
                                                    (pCfg->u32InputByteCnt + 3u) >> 2u,
                                                    pCfg->pDataInput,
                                                    pCfg->u32InputByteCnt,
                                                    0u,
                                                    HSM_TRUE,
                                                    HSM_TRUE);

                        if (HSM_SYMM_ENDECRYPT_MODE_ECB != pCfg->eAesAlg)
                        {
                            hsm_core_swap_u32_array_pad(
                                (hsm_uint32_t *)HSM_ADDRESS_UP_ALIGN(
                                    &(pCtx->tL1AlgCtx.tAesEncryptInf.aIvData[0])),
                                4u,
                                pCfg->pIvData,
                                16u,
                                0u,
                                HSM_TRUE,
                                HSM_TRUE);
                        }

                        pCtx->tL1AlgCtx.tAesEncryptInf.pParm->tCfg.pDataInput =
                            (const hsm_uint8_t *)pInputCache;
                        pCtx->tL1AlgCtx.tAesEncryptInf.pParm->tCfg.eInputFmt  = HSM_DATA_FORMAT_4B;
                        pCtx->tL1AlgCtx.tAesEncryptInf.pParm->tCfg.eOutputFmt = HSM_DATA_FORMAT_4B;

                        if (HSM_DATA_FORMAT_1B == pCfg->eOutputFmt)
                        {
                            pCtx->tL1AlgCtx.tAesEncryptInf.pParm->tCfg.pDataOutput =
                                (hsm_uint8_t *)&(pCtx->tL1AlgCtx.tAesEncryptInf.aResultCacheBuf[0]);
                            pCtx->tL1AlgCtx.tAesEncryptInf.bSwapOut = HSM_TRUE;
                        }
                        else
                        {
                            pCtx->tL1AlgCtx.tAesEncryptInf.bSwapOut = HSM_FALSE;
                        }
                        pCtx->tL1AlgCtx.tAesEncryptInf.pResultBuf       = pCfg->pDataOutput;
                        pCtx->tL1AlgCtx.tAesEncryptInf.u32ResultByteCnt = u32ResultLen;

                        if (HSM_AES_KEY_NEW == pCfg->eUseKeyType)
                        {
                            pInputCache = (hsm_uint32_t *)HSM_ADDRESS_UP_ALIGN(
                                &(pCtx->tL1AlgCtx.tAesEncryptInf.aResultCacheBuf[0]));
                            if (HSM_AES_KEY128 == pCfg->tNewKeyInf.eKeyType)
                            {
                                hsm_core_swap_u32_array_pad(pInputCache,
                                                            4U,
                                                            pCfg->tNewKeyInf.pKeyAddr,
                                                            16U,
                                                            0u,
                                                            HSM_TRUE,
                                                            HSM_TRUE);
                            }
                            else if (HSM_AES_KEY192 == pCfg->tNewKeyInf.eKeyType)
                            {
                                hsm_core_swap_u32_array_pad(pInputCache,
                                                            6U,
                                                            pCfg->tNewKeyInf.pKeyAddr,
                                                            24U,
                                                            0u,
                                                            HSM_TRUE,
                                                            HSM_TRUE);
                            }
                            else /* AES 256 */
                            {
                                hsm_core_swap_u32_array_pad(pInputCache,
                                                            8U,
                                                            pCfg->tNewKeyInf.pKeyAddr,
                                                            32U,
                                                            0u,
                                                            HSM_TRUE,
                                                            HSM_TRUE);
                            }

                            pCtx->tL1AlgCtx.tAesEncryptInf.pParm->tCfg.tNewKeyInf.pKeyAddr =
                                (const hsm_uint8_t *)pInputCache;
                        }
                        /* else do nothing */
                    }
                    else
                    {
                        if (HSM_SYMM_ENDECRYPT_MODE_ECB != pCfg->eAesAlg)
                        {
                            hsm_memcpy((hsm_uint8_t *)HSM_ADDRESS_UP_ALIGN(
                                           &(pCtx->tL1AlgCtx.tAesEncryptInf.aIvData[0])),
                                       pCfg->pIvData,
                                       16u);
                        }
                        pCtx->tL1AlgCtx.tAesEncryptInf.bSwapOut         = HSM_FALSE;
                        pCtx->tL1AlgCtx.tAesEncryptInf.pResultBuf       = pCfg->pDataOutput;
                        pCtx->tL1AlgCtx.tAesEncryptInf.u32ResultByteCnt = u32ResultLen;
                    }

                    eRet = HSM_AesEncryptEx(&(pCtx->tCmd), pCtx->tL1AlgCtx.tAesEncryptInf.pParm);
                    if (HSM_STATUS_SUCCESS == eRet)
                    {
                        pCtx->eStat = HSM_DRV_SM_ARITH;
                        eRet        = pCtx->pSendCmdCb(&(pCtx->tCmd));
                        if (HSM_STATUS_SUCCESS != eRet)
                        {
                            pCtx->eStat = HSM_DRV_SM_STOP;
                            eRet        = HSM_STATUS_SEND_FAIL;
                        }
                    }
                    else
                    {
                        ;
                    }
                }
                else
                {
                    eRet = HSM_STATUS_BUSY;
                }
            }
            else
            {
                eRet = HSM_STATUS_LOGIC_ERR;
            }
        }
        else
        {
            eRet = HSM_STATUS_PARAM_ERR;
        }
    }
    else
    {
        eRet = HSM_STATUS_PARAM_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_AesEncrypt_Isr(HSM_L1_RtCtxType *pCtx)
{
    HSM_StatusType eRet;

    if (MAILBOXAPI_RET_SUCCESS == pCtx->tL1AlgCtx.tAesEncryptInf.pParm->u32HSMStatusRet)
    {
        if (HSM_TRUE == pCtx->tL1AlgCtx.tAesEncryptInf.bSwapOut)
        {
            hsm_u32_array_swap(
                (hsm_uint32_t *)(pCtx->tL1AlgCtx.tAesEncryptInf.pParm->tCfg.pDataOutput),
                pCtx->tL1AlgCtx.tAesEncryptInf.u32ResultByteCnt >> 2u);
            hsm_memcpy(pCtx->tL1AlgCtx.tAesEncryptInf.pResultBuf,
                       pCtx->tL1AlgCtx.tAesEncryptInf.pParm->tCfg.pDataOutput,
                       pCtx->tL1AlgCtx.tAesEncryptInf.u32ResultByteCnt);
            eRet = HSM_STATUS_SUCCESS;
        }
        else
        {
            eRet = HSM_STATUS_SUCCESS;
        }

        pCtx->eStat = HSM_DRV_SM_STOP;
    }
    else
    {
        eRet        = HSM_STATUS_HW_ERR;
        pCtx->eStat = HSM_DRV_SM_STOP;
    }

    return eRet;
}

HSM_StatusType HSM_L1_AesEncryptPoll(HSM_L1_RtCtxType *pCtx)
{
    HSM_StatusType eRet       = HSM_STATUS_SUCCESS;
    HSM_BoolType   bInProcess = HSM_FALSE;

    bInProcess = pCtx->bInProcess;

    if ((HSM_TRUE == bInProcess) && (HSM_OP_AES_ENCRYPT == pCtx->eOperationCata))
    {
        if (HSM_DRV_SM_ARITH == pCtx->eStat)
        {
            eRet = pCtx->pReadAckCb();
            if (HSM_STATUS_BUSY == eRet)
            {
                eRet = HSM_STATUS_AGAIN;
            }
            else if (HSM_STATUS_SUCCESS == eRet)
            {
                eRet = HSM_L1_AesEncrypt_Isr(pCtx);
            }
            else
            {
                pCtx->eStat = HSM_DRV_SM_STOP;
            }
        }
        else
        {
            eRet = HSM_STATUS_HW_IDLE;
        }
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_AesDecryptSetupEnv(HSM_L1_RtCtxType *pCtx)
{
    HSM_BoolType   bInProcess = HSM_FALSE;
    HSM_StatusType eRet       = HSM_STATUS_SUCCESS;

    bInProcess = pCtx->bInProcess;
    if (HSM_FALSE == bInProcess)
    {
        pCtx->bInProcess                     = HSM_TRUE;
        pCtx->eOperationCata                 = HSM_OP_AES_DECRYPT;
        pCtx->eStat                          = HSM_DRV_SM_READY;
        pCtx->tL1AlgCtx.tAesDecryptInf.pParm = (HSMCom_FlexAesDecryptType *)HSM_ADDRESS_UP_ALIGN(
            &(pCtx->tL1AlgCtx.tAesDecryptInf.aParmBuf[0]));

        eRet = HSM_STATUS_SUCCESS;
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_AesDecryptReset(HSM_L1_RtCtxType *pCtx)
{
    HSM_BoolType   bInProcess = HSM_FALSE;
    HSM_StatusType eRet       = HSM_STATUS_SUCCESS;

    bInProcess = pCtx->bInProcess;

    if ((HSM_TRUE == bInProcess) && (HSM_OP_AES_DECRYPT == pCtx->eOperationCata))
    {
        if (HSM_DRV_SM_ARITH == pCtx->eStat)
        {
            eRet = pCtx->pCancelCmdCb();
        }

        if (HSM_STATUS_SUCCESS == eRet)
        {
            pCtx->eStat = HSM_DRV_SM_READY;
        }
        else
        {
            ;
        }
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_AesDecryptExitEnv(HSM_L1_RtCtxType *pCtx)
{
    HSM_BoolType   bInProcess = pCtx->bInProcess;
    HSM_StatusType eRet       = HSM_STATUS_SUCCESS;

    if ((HSM_TRUE == bInProcess) && (HSM_OP_AES_DECRYPT == pCtx->eOperationCata))
    {
        eRet = HSM_L1_CommonExitEnv(pCtx);
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_AesDecrypt(HSM_L1_RtCtxType            *pCtx,
                                 const HSM_Ln_AesDecryptType *pCfg,
                                 hsm_uint32_t                 u32TimeoutMs)
{
    HSM_StatusType eRet       = HSM_STATUS_SUCCESS;
    HSM_BoolType   bInProcess = HSM_FALSE;
    hsm_uint8_t   *pU8Cache;

    if ((NULL_PTR != pCtx) && (NULL_PTR != pCfg) && (pCfg->u32InputByteCnt > 0u) &&
        (!(pCfg->u32InputByteCnt & 0xf))) /* not check the input address 4byte aligned here for eco
                                             support this */
    {
        bInProcess = pCtx->bInProcess;
        if ((HSM_TRUE == bInProcess) && (HSM_OP_AES_DECRYPT == pCtx->eOperationCata))
        {
            if (HSM_DRV_SM_ARITH != pCtx->eStat)
            {
                pU8Cache = (hsm_uint8_t *)HSM_ADDRESS_UP_ALIGN(
                    &(pCtx->tL1AlgCtx.tAesDecryptInf.aIvData[0]));

                pCtx->tL1AlgCtx.tAesDecryptInf.pParm->u32HSMStatusRet  = MAILBOXAPI_RET_NONE;
                pCtx->tL1AlgCtx.tAesDecryptInf.pParm->u32Timeout       = u32TimeoutMs;
                pCtx->tL1AlgCtx.tAesDecryptInf.pParm->u32UserKeyID     = pCfg->u32KeyId;
                pCtx->tL1AlgCtx.tAesDecryptInf.pParm->tCfg.eUseKeyType = pCfg->eUseKeyType;
                hsm_memcpy(&(pCtx->tL1AlgCtx.tAesDecryptInf.pParm->tCfg.tNewKeyInf),
                           &(pCfg->tNewKeyInf),
                           sizeof(HSM_AesNewKeyInfType));
                hsm_memcpy(&(pCtx->tL1AlgCtx.tAesDecryptInf.pParm->tCfg.tVendorKeyInf),
                           &(pCfg->tVendorKeyInf),
                           sizeof(HSM_AesVendorKeyInfType));
                pCtx->tL1AlgCtx.tAesDecryptInf.pParm->tCfg.eAesAlg         = pCfg->eAesAlg;
                pCtx->tL1AlgCtx.tAesDecryptInf.pParm->tCfg.pDataInput      = pCfg->pDataInput;
                pCtx->tL1AlgCtx.tAesDecryptInf.pParm->tCfg.u32InputByteCnt = pCfg->u32InputByteCnt;
                pCtx->tL1AlgCtx.tAesDecryptInf.pParm->tCfg.pDataOutput     = pCfg->pDataOutput;
                pCtx->tL1AlgCtx.tAesDecryptInf.pParm->tCfg.u32OutputMemSize = pCfg->u32OutputMemSize;
                pCtx->tL1AlgCtx.tAesDecryptInf.pParm->tCfg.pIvData = pU8Cache; /* pCfg->pIvData; */
                pCtx->tL1AlgCtx.tAesDecryptInf.pParm->tCfg.ePad    = pCfg->ePad;
                pCtx->tL1AlgCtx.tAesDecryptInf.pParm->tCfg.eInputFmt  = pCfg->eInputFmt;
                pCtx->tL1AlgCtx.tAesDecryptInf.pParm->tCfg.eOutputFmt = pCfg->eOutputFmt;

                if (HSM_SYMM_ENDECRYPT_MODE_ECB != pCfg->eAesAlg)
                {
                    hsm_memcpy(pU8Cache, pCfg->pIvData, 16u);
                }

                if (NULL_PTR != pCfg->pGenerateOutByteCnt)
                {
                    pCtx->tL1AlgCtx.tAesDecryptInf.pParm->tCfg.pGenerateOutByteCnt =
                        pCfg->pGenerateOutByteCnt;
                }
                else
                {
                    pCtx->tL1AlgCtx.tAesDecryptInf.pParm->tCfg.pGenerateOutByteCnt = &(
                        pCtx->tL1AlgCtx.tAesDecryptInf.u32HsmRetResultSize);
                }

                eRet = HSM_AesDecryptEx(&(pCtx->tCmd), pCtx->tL1AlgCtx.tAesDecryptInf.pParm);
                if (HSM_STATUS_SUCCESS == eRet)
                {
                    pCtx->eStat = HSM_DRV_SM_ARITH;
                    eRet        = pCtx->pSendCmdCb(&(pCtx->tCmd));
                    if (HSM_STATUS_SUCCESS != eRet)
                    {
                        pCtx->eStat = HSM_DRV_SM_STOP;
                        eRet        = HSM_STATUS_SEND_FAIL;
                    }
                }
                else
                {
                    ;
                }
            }
            else
            {
                eRet = HSM_STATUS_BUSY;
            }
        }
        else
        {
            eRet = HSM_STATUS_LOGIC_ERR;
        }
    }
    else
    {
        eRet = HSM_STATUS_PARAM_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_AesDecrypt_Isr(HSM_L1_RtCtxType *pCtx)
{
    HSM_StatusType eRet;

    if (MAILBOXAPI_RET_SUCCESS == pCtx->tL1AlgCtx.tAesDecryptInf.pParm->u32HSMStatusRet)
    {
        eRet        = HSM_STATUS_SUCCESS;
        pCtx->eStat = HSM_DRV_SM_STOP;
    }
    else
    {
        eRet        = HSM_STATUS_HW_ERR;
        pCtx->eStat = HSM_DRV_SM_STOP;
    }

    return eRet;
}

HSM_StatusType HSM_L1_AesDecryptPoll(HSM_L1_RtCtxType *pCtx)
{
    HSM_StatusType eRet       = HSM_STATUS_SUCCESS;
    HSM_BoolType   bInProcess = HSM_FALSE;

    bInProcess = pCtx->bInProcess;

    if ((HSM_TRUE == bInProcess) && (HSM_OP_AES_DECRYPT == pCtx->eOperationCata))
    {
        if (HSM_DRV_SM_ARITH == pCtx->eStat)
        {
            eRet = pCtx->pReadAckCb();
            if (HSM_STATUS_BUSY == eRet)
            {
                eRet = HSM_STATUS_AGAIN;
            }
            else if (HSM_STATUS_SUCCESS == eRet)
            {
                eRet = HSM_L1_AesDecrypt_Isr(pCtx);
            }
            else
            {
                pCtx->eStat = HSM_DRV_SM_STOP;
            }
        }
        else
        {
            eRet = HSM_STATUS_HW_IDLE;
        }
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_Sm4EncryptSetupEnv(HSM_L1_RtCtxType *pCtx)
{
    HSM_BoolType   bInProcess = HSM_FALSE;
    HSM_StatusType eRet       = HSM_STATUS_SUCCESS;

    bInProcess = pCtx->bInProcess;
    if (HSM_FALSE == bInProcess)
    {
        pCtx->bInProcess                     = HSM_TRUE;
        pCtx->eOperationCata                 = HSM_OP_SM4_ENCRYPT;
        pCtx->eStat                          = HSM_DRV_SM_READY;
        pCtx->tL1AlgCtx.tSm4EncryptInf.pParm = (HSMCom_Sm4EncryptExType *)HSM_ADDRESS_UP_ALIGN(
            &(pCtx->tL1AlgCtx.tSm4EncryptInf.aParmBuf[0]));

        eRet = HSM_STATUS_SUCCESS;
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_Sm4EncryptReset(HSM_L1_RtCtxType *pCtx)
{
    HSM_BoolType   bInProcess = HSM_FALSE;
    HSM_StatusType eRet       = HSM_STATUS_SUCCESS;

    bInProcess = pCtx->bInProcess;

    if ((HSM_TRUE == bInProcess) && (HSM_OP_SM4_ENCRYPT == pCtx->eOperationCata))
    {
        if (HSM_DRV_SM_ARITH == pCtx->eStat)
        {
            eRet = pCtx->pCancelCmdCb();
        }

        if (HSM_STATUS_SUCCESS == eRet)
        {
            pCtx->eStat = HSM_DRV_SM_READY;
        }
        else
        {
            ;
        }
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_Sm4EncryptExitEnv(HSM_L1_RtCtxType *pCtx)
{
    HSM_BoolType   bInProcess = pCtx->bInProcess;
    HSM_StatusType eRet       = HSM_STATUS_SUCCESS;

    if ((HSM_TRUE == bInProcess) && (HSM_OP_SM4_ENCRYPT == pCtx->eOperationCata))
    {
        eRet = HSM_L1_CommonExitEnv(pCtx);
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_Sm4Encrypt(HSM_L1_RtCtxType            *pCtx,
                                 const HSM_Ln_Sm4EncryptType *pCfg,
                                 hsm_uint32_t                 u32TimeoutMs)
{
    HSM_StatusType eRet       = HSM_STATUS_SUCCESS;
    HSM_BoolType   bInProcess = HSM_FALSE;
    hsm_uint32_t  *pInputCache;
    hsm_uint32_t   u32ResultLen;
    hsm_uint8_t   *pU8Cache;

    if ((NULL_PTR != pCtx) && (NULL_PTR != pCfg) &&
        (pCfg->u32InputByteCnt >
         0u)) /* not check the input address 4byte aligned here for eco support this */
    {
        if (HSM_FLEXAES_PAD_ZERO == pCfg->ePad)
        {
            u32ResultLen = (pCfg->u32InputByteCnt + 0xfu) & 0xfffffff0u;
        }
        else /* HSM_FLEXAES_PAD_PKCS7 */
        {
            u32ResultLen = (pCfg->u32InputByteCnt + 0x10u) & 0xfffffff0u;
        }

        if (u32ResultLen <= pCfg->u32OutputMemSize)
        {
            bInProcess = pCtx->bInProcess;
            if ((HSM_TRUE == bInProcess) && (HSM_OP_SM4_ENCRYPT == pCtx->eOperationCata))
            {
                if (HSM_DRV_SM_ARITH != pCtx->eStat)
                {
                    pU8Cache = (hsm_uint8_t *)HSM_ADDRESS_UP_ALIGN(
                        &(pCtx->tL1AlgCtx.tSm4EncryptInf.aIvData[0]));

                    pCtx->tL1AlgCtx.tSm4EncryptInf.pParm->u32HSMStatusRet  = MAILBOXAPI_RET_NONE;
                    pCtx->tL1AlgCtx.tSm4EncryptInf.pParm->u32Timeout       = u32TimeoutMs;
                    pCtx->tL1AlgCtx.tSm4EncryptInf.pParm->u32UserKeyID     = pCfg->u32KeyId;
                    pCtx->tL1AlgCtx.tSm4EncryptInf.pParm->tCfg.eUseKeyType = pCfg->eUseKeyType;
                    hsm_memcpy(&(pCtx->tL1AlgCtx.tSm4EncryptInf.pParm->tCfg.tNewKeyInf),
                               &(pCfg->tNewKeyInf),
                               sizeof(HSM_AesNewKeyInfType));
                    hsm_memcpy(&(pCtx->tL1AlgCtx.tSm4EncryptInf.pParm->tCfg.tVendorKeyInf),
                               &(pCfg->tVendorKeyInf),
                               sizeof(HSM_AesVendorKeyInfType));
                    pCtx->tL1AlgCtx.tSm4EncryptInf.pParm->tCfg.eAesAlg    = pCfg->eAesAlg;
                    pCtx->tL1AlgCtx.tSm4EncryptInf.pParm->tCfg.pDataInput = pCfg->pDataInput;
                    pCtx->tL1AlgCtx.tSm4EncryptInf.pParm->tCfg.u32InputByteCnt = pCfg->u32InputByteCnt;
                    pCtx->tL1AlgCtx.tSm4EncryptInf.pParm->tCfg.pDataOutput = pCfg->pDataOutput;
                    pCtx->tL1AlgCtx.tSm4EncryptInf.pParm->tCfg.u32OutputMemSize =
                        pCfg->u32OutputMemSize;
                    pCtx->tL1AlgCtx.tSm4EncryptInf.pParm->tCfg.pIvData    = pU8Cache;
                    pCtx->tL1AlgCtx.tSm4EncryptInf.pParm->tCfg.ePad       = pCfg->ePad;
                    pCtx->tL1AlgCtx.tSm4EncryptInf.pParm->tCfg.eInputFmt  = pCfg->eInputFmt;
                    pCtx->tL1AlgCtx.tSm4EncryptInf.pParm->tCfg.eOutputFmt = pCfg->eOutputFmt;

                    if (NULL_PTR != pCfg->pGenerateOutByteCnt)
                    {
                        pCtx->tL1AlgCtx.tSm4EncryptInf.pParm->tCfg.pGenerateOutByteCnt =
                            pCfg->pGenerateOutByteCnt;
                    }
                    else
                    {
                        pCtx->tL1AlgCtx.tSm4EncryptInf.pParm->tCfg.pGenerateOutByteCnt = &(
                            pCtx->tL1AlgCtx.tSm4EncryptInf.u32HsmRetResultSize);
                    }

                    if ((HSM_DATA_FORMAT_1B == pCfg->eInputFmt) && (0u == pCfg->u32KeyId) &&
                        (pCfg->u32InputByteCnt <=
                         (sizeof(pCtx->tL1AlgCtx.tSm4EncryptInf.aInputCacheBuf) - 4u)))
                    {
                        pInputCache = (hsm_uint32_t *)HSM_ADDRESS_UP_ALIGN(
                            &(pCtx->tL1AlgCtx.tSm4EncryptInf.aInputCacheBuf[0]));
                        hsm_core_swap_u32_array_pad(pInputCache,
                                                    (pCfg->u32InputByteCnt + 3u) >> 2u,
                                                    pCfg->pDataInput,
                                                    pCfg->u32InputByteCnt,
                                                    0u,
                                                    HSM_TRUE,
                                                    HSM_TRUE);

                        if (HSM_SYMM_ENDECRYPT_MODE_ECB != pCfg->eAesAlg)
                        {
                            hsm_core_swap_u32_array_pad((hsm_uint32_t *)pU8Cache,
                                                        4u,
                                                        pCfg->pIvData,
                                                        16u,
                                                        0u,
                                                        HSM_TRUE,
                                                        HSM_TRUE);
                        }

                        pCtx->tL1AlgCtx.tSm4EncryptInf.pParm->tCfg.pDataInput =
                            (const hsm_uint8_t *)pInputCache;
                        pCtx->tL1AlgCtx.tSm4EncryptInf.pParm->tCfg.eInputFmt  = HSM_DATA_FORMAT_4B;
                        pCtx->tL1AlgCtx.tSm4EncryptInf.pParm->tCfg.eOutputFmt = HSM_DATA_FORMAT_4B;

                        if (HSM_DATA_FORMAT_1B == pCfg->eOutputFmt)
                        {
                            pCtx->tL1AlgCtx.tSm4EncryptInf.pParm->tCfg.pDataOutput =
                                (hsm_uint8_t *)&(pCtx->tL1AlgCtx.tSm4EncryptInf.aResultCacheBuf[0]);
                            pCtx->tL1AlgCtx.tSm4EncryptInf.bSwapOut = HSM_TRUE;
                        }
                        else
                        {
                            pCtx->tL1AlgCtx.tSm4EncryptInf.bSwapOut = HSM_FALSE;
                        }
                        pCtx->tL1AlgCtx.tSm4EncryptInf.pResultBuf       = pCfg->pDataOutput;
                        pCtx->tL1AlgCtx.tSm4EncryptInf.u32ResultByteCnt = u32ResultLen;

                        if (HSM_AES_KEY_NEW == pCfg->eUseKeyType)
                        {
                            pInputCache = (hsm_uint32_t *)HSM_ADDRESS_UP_ALIGN(
                                &(pCtx->tL1AlgCtx.tSm4EncryptInf.aResultCacheBuf[0]));
                            hsm_core_swap_u32_array_pad(pInputCache,
                                                        4U,
                                                        pCfg->tNewKeyInf.pKeyAddr,
                                                        16,
                                                        0u,
                                                        HSM_TRUE,
                                                        HSM_TRUE);
                            pCtx->tL1AlgCtx.tSm4EncryptInf.pParm->tCfg.tNewKeyInf.pKeyAddr =
                                (const hsm_uint8_t *)pInputCache;
                        }
                    }
                    else
                    {
                        if (HSM_SYMM_ENDECRYPT_MODE_ECB != pCfg->eAesAlg)
                        {
                            hsm_memcpy(pU8Cache, pCfg->pIvData, 16U);
                        }
                        pCtx->tL1AlgCtx.tSm4EncryptInf.bSwapOut         = HSM_FALSE;
                        pCtx->tL1AlgCtx.tSm4EncryptInf.pResultBuf       = pCfg->pDataOutput;
                        pCtx->tL1AlgCtx.tSm4EncryptInf.u32ResultByteCnt = u32ResultLen;
                    }

                    eRet = HSM_Sm4EncryptExStart(&(pCtx->tCmd),
                                                 &(pCtx->tL1AlgCtx.tSm4EncryptInf.tWrapper),
                                                 pCtx->tL1AlgCtx.tSm4EncryptInf.pParm);
                    if ((HSM_STATUS_AGAIN == eRet) || (HSM_STATUS_FINISH == eRet))
                    {
                        pCtx->eStat = HSM_DRV_SM_ARITH;
                        eRet        = pCtx->pSendCmdCb(&(pCtx->tCmd));
                        if (HSM_STATUS_SUCCESS != eRet)
                        {
                            pCtx->eStat = HSM_DRV_SM_STOP;
                            eRet        = HSM_STATUS_SEND_FAIL;
                        }
                    }
                    else
                    {
                        ;
                    }
                }
                else
                {
                    eRet = HSM_STATUS_BUSY;
                }
            }
            else
            {
                eRet = HSM_STATUS_LOGIC_ERR;
            }
        }
        else
        {
            eRet = HSM_STATUS_PARAM_ERR;
        }
    }
    else
    {
        eRet = HSM_STATUS_PARAM_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_Sm4Encrypt_Isr(HSM_L1_RtCtxType *pCtx)
{
    HSM_StatusType eRet;

    if (MAILBOXAPI_RET_SUCCESS == pCtx->tL1AlgCtx.tSm4EncryptInf.pParm->u32HSMStatusRet)
    {
        if (HSM_TRUE == pCtx->tL1AlgCtx.tSm4EncryptInf.bSwapOut)
        {
            hsm_u32_array_swap((hsm_uint32_t *)pCtx->tL1AlgCtx.tSm4EncryptInf.pParm->tCfg.pDataOutput,
                               pCtx->tL1AlgCtx.tSm4EncryptInf.u32ResultByteCnt >> 2u);
            hsm_memcpy(pCtx->tL1AlgCtx.tSm4EncryptInf.pResultBuf,
                       pCtx->tL1AlgCtx.tSm4EncryptInf.pParm->tCfg.pDataOutput,
                       pCtx->tL1AlgCtx.tSm4EncryptInf.u32ResultByteCnt);
        }
        else
        {
            ;
        }

        eRet = HSM_Sm4EncryptExUpdate(&(pCtx->tCmd), &(pCtx->tL1AlgCtx.tSm4EncryptInf.tWrapper));
        if ((HSM_STATUS_AGAIN == eRet) || (HSM_STATUS_FINISH == eRet))
        {
            eRet = pCtx->pSendCmdCb(&(pCtx->tCmd));
            if (HSM_STATUS_SUCCESS != eRet)
            {
                pCtx->eStat = HSM_DRV_SM_STOP;
                eRet        = HSM_STATUS_SEND_FAIL;
            }
            else
            {
                eRet = HSM_STATUS_AGAIN;
            }
        }
        else if (HSM_STATUS_ALREADY_FINISHED == eRet)
        {
            pCtx->eStat = HSM_DRV_SM_STOP;
            eRet        = HSM_STATUS_SUCCESS;
        }
        else
        {
            pCtx->eStat = HSM_DRV_SM_STOP;
            eRet        = HSM_STATUS_ERROR;
        }
    }
    else
    {
        eRet        = HSM_STATUS_HW_ERR;
        pCtx->eStat = HSM_DRV_SM_STOP;
    }

    return eRet;
}

HSM_StatusType HSM_L1_Sm4EncryptPoll(HSM_L1_RtCtxType *pCtx)
{
    HSM_StatusType eRet       = HSM_STATUS_SUCCESS;
    HSM_BoolType   bInProcess = HSM_FALSE;

    bInProcess = pCtx->bInProcess;

    if ((HSM_TRUE == bInProcess) && (HSM_OP_SM4_ENCRYPT == pCtx->eOperationCata))
    {
        if (HSM_DRV_SM_ARITH == pCtx->eStat)
        {
            eRet = pCtx->pReadAckCb();
            if (HSM_STATUS_BUSY == eRet)
            {
                eRet = HSM_STATUS_AGAIN;
            }
            else if (HSM_STATUS_SUCCESS == eRet)
            {
                eRet = HSM_L1_Sm4Encrypt_Isr(pCtx);
            }
            else
            {
                pCtx->eStat = HSM_DRV_SM_STOP;
            }
        }
        else
        {
            eRet = HSM_STATUS_HW_IDLE;
        }
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_Sm4DecryptSetupEnv(HSM_L1_RtCtxType *pCtx)
{
    HSM_BoolType   bInProcess = HSM_FALSE;
    HSM_StatusType eRet       = HSM_STATUS_SUCCESS;

    bInProcess = pCtx->bInProcess;
    if (HSM_FALSE == bInProcess)
    {
        pCtx->bInProcess                     = HSM_TRUE;
        pCtx->eOperationCata                 = HSM_OP_SM4_DECRYPT;
        pCtx->eStat                          = HSM_DRV_SM_READY;
        pCtx->tL1AlgCtx.tSm4DecryptInf.pParm = (HSMCom_Sm4DecryptExType *)HSM_ADDRESS_UP_ALIGN(
            &(pCtx->tL1AlgCtx.tSm4DecryptInf.aParmBuf[0]));

        eRet = HSM_STATUS_SUCCESS;
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_Sm4DecryptReset(HSM_L1_RtCtxType *pCtx)
{
    HSM_BoolType   bInProcess = HSM_FALSE;
    HSM_StatusType eRet       = HSM_STATUS_SUCCESS;

    bInProcess = pCtx->bInProcess;

    if ((HSM_TRUE == bInProcess) && (HSM_OP_SM4_DECRYPT == pCtx->eOperationCata))
    {
        if (HSM_DRV_SM_ARITH == pCtx->eStat)
        {
            eRet = pCtx->pCancelCmdCb();
        }

        if (HSM_STATUS_SUCCESS == eRet)
        {
            pCtx->eStat = HSM_DRV_SM_READY;
        }
        else
        {
            ;
        }
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_Sm4DecryptExitEnv(HSM_L1_RtCtxType *pCtx)
{
    HSM_BoolType   bInProcess = pCtx->bInProcess;
    HSM_StatusType eRet       = HSM_STATUS_SUCCESS;

    if ((HSM_TRUE == bInProcess) && (HSM_OP_SM4_DECRYPT == pCtx->eOperationCata))
    {
        eRet = HSM_L1_CommonExitEnv(pCtx);
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_Sm4Decrypt(HSM_L1_RtCtxType            *pCtx,
                                 const HSM_Ln_Sm4DecryptType *pCfg,
                                 hsm_uint32_t                 u32TimeoutMs)
{
    HSM_StatusType eRet       = HSM_STATUS_SUCCESS;
    HSM_BoolType   bInProcess = HSM_FALSE;

    if ((NULL_PTR != pCtx) && (NULL_PTR != pCfg) && (pCfg->u32InputByteCnt > 0u) &&
        (!(pCfg->u32InputByteCnt & 0xf))) /* not check the input address 4byte aligned here for eco
                                             support this */
    {
        bInProcess = pCtx->bInProcess;
        if ((HSM_TRUE == bInProcess) && (HSM_OP_SM4_DECRYPT == pCtx->eOperationCata))
        {
            if (HSM_DRV_SM_ARITH != pCtx->eStat)
            {
                pCtx->tL1AlgCtx.tSm4DecryptInf.pParm->u32HSMStatusRet  = MAILBOXAPI_RET_NONE;
                pCtx->tL1AlgCtx.tSm4DecryptInf.pParm->u32Timeout       = u32TimeoutMs;
                pCtx->tL1AlgCtx.tSm4DecryptInf.pParm->u32UserKeyID     = pCfg->u32KeyId;
                pCtx->tL1AlgCtx.tSm4DecryptInf.pParm->tCfg.eUseKeyType = pCfg->eUseKeyType;
                hsm_memcpy(&(pCtx->tL1AlgCtx.tSm4DecryptInf.pParm->tCfg.tNewKeyInf),
                           &(pCfg->tNewKeyInf),
                           sizeof(HSM_AesNewKeyInfType));
                hsm_memcpy(&(pCtx->tL1AlgCtx.tSm4DecryptInf.pParm->tCfg.tVendorKeyInf),
                           &(pCfg->tVendorKeyInf),
                           sizeof(HSM_AesVendorKeyInfType));
                pCtx->tL1AlgCtx.tSm4DecryptInf.pParm->tCfg.eAesAlg         = pCfg->eAesAlg;
                pCtx->tL1AlgCtx.tSm4DecryptInf.pParm->tCfg.pDataInput      = pCfg->pDataInput;
                pCtx->tL1AlgCtx.tSm4DecryptInf.pParm->tCfg.u32InputByteCnt = pCfg->u32InputByteCnt;
                pCtx->tL1AlgCtx.tSm4DecryptInf.pParm->tCfg.pDataOutput     = pCfg->pDataOutput;
                pCtx->tL1AlgCtx.tSm4DecryptInf.pParm->tCfg.u32OutputMemSize = pCfg->u32OutputMemSize;
                pCtx->tL1AlgCtx.tSm4DecryptInf.pParm->tCfg.pIvData =
                    (hsm_uint8_t *)HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tSm4DecryptInf.aIvData[0]));
                pCtx->tL1AlgCtx.tSm4DecryptInf.pParm->tCfg.ePad       = pCfg->ePad;
                pCtx->tL1AlgCtx.tSm4DecryptInf.pParm->tCfg.eInputFmt  = pCfg->eInputFmt;
                pCtx->tL1AlgCtx.tSm4DecryptInf.pParm->tCfg.eOutputFmt = pCfg->eOutputFmt;

                if (HSM_SYMM_ENDECRYPT_MODE_ECB != pCfg->eAesAlg)
                {
                    hsm_memcpy((hsm_uint8_t *)HSM_ADDRESS_UP_ALIGN(
                                   &(pCtx->tL1AlgCtx.tSm4DecryptInf.aIvData[0])),
                               pCfg->pIvData,
                               16U);
                }

                if (NULL_PTR != pCfg->pGenerateOutByteCnt)
                {
                    pCtx->tL1AlgCtx.tSm4DecryptInf.pParm->tCfg.pGenerateOutByteCnt =
                        pCfg->pGenerateOutByteCnt;
                }
                else
                {
                    pCtx->tL1AlgCtx.tSm4DecryptInf.pParm->tCfg.pGenerateOutByteCnt = &(
                        pCtx->tL1AlgCtx.tSm4DecryptInf.u32HsmRetResultSize);
                }

                eRet = HSM_Sm4DecryptEx(&(pCtx->tCmd), pCtx->tL1AlgCtx.tSm4DecryptInf.pParm);
                if (HSM_STATUS_SUCCESS == eRet)
                {
                    pCtx->eStat = HSM_DRV_SM_ARITH;
                    eRet        = pCtx->pSendCmdCb(&(pCtx->tCmd));
                    if (HSM_STATUS_SUCCESS != eRet)
                    {
                        pCtx->eStat = HSM_DRV_SM_STOP;
                        eRet        = HSM_STATUS_SEND_FAIL;
                    }
                }
                else
                {
                    ;
                }
            }
            else
            {
                eRet = HSM_STATUS_BUSY;
            }
        }
        else
        {
            eRet = HSM_STATUS_LOGIC_ERR;
        }
    }
    else
    {
        eRet = HSM_STATUS_PARAM_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_Sm4Decrypt_Isr(HSM_L1_RtCtxType *pCtx)
{
    HSM_StatusType eRet;

    if (MAILBOXAPI_RET_SUCCESS == pCtx->tL1AlgCtx.tSm4DecryptInf.pParm->u32HSMStatusRet)
    {
        eRet = HSM_STATUS_SUCCESS;

        pCtx->eStat = HSM_DRV_SM_STOP;
    }
    else
    {
        eRet        = HSM_STATUS_HW_ERR;
        pCtx->eStat = HSM_DRV_SM_STOP;
    }

    return eRet;
}

HSM_StatusType HSM_L1_Sm4DecryptPoll(HSM_L1_RtCtxType *pCtx)
{
    HSM_StatusType eRet       = HSM_STATUS_SUCCESS;
    HSM_BoolType   bInProcess = HSM_FALSE;

    bInProcess = pCtx->bInProcess;

    if ((HSM_TRUE == bInProcess) && (HSM_OP_SM4_DECRYPT == pCtx->eOperationCata))
    {
        if (HSM_DRV_SM_ARITH == pCtx->eStat)
        {
            eRet = pCtx->pReadAckCb();
            if (HSM_STATUS_BUSY == eRet)
            {
                eRet = HSM_STATUS_AGAIN;
            }
            else if (HSM_STATUS_SUCCESS == eRet)
            {
                eRet = HSM_L1_Sm4Decrypt_Isr(pCtx);
            }
            else
            {
                pCtx->eStat = HSM_DRV_SM_STOP;
            }
        }
        else
        {
            eRet = HSM_STATUS_HW_IDLE;
        }
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_BnCalcSetupEnv(HSM_L1_RtCtxType *pCtx)
{
    HSM_BoolType   bInProcess = HSM_FALSE;
    HSM_StatusType eRet       = HSM_STATUS_SUCCESS;

    bInProcess = pCtx->bInProcess;
    if (HSM_FALSE == bInProcess)
    {
        pCtx->bInProcess     = HSM_TRUE;
        pCtx->eOperationCata = HSM_OP_BN_CALC;
        pCtx->eStat          = HSM_DRV_SM_READY;
        pCtx->tL1AlgCtx.tBnCalcInf.pBnCalcParm = (HSMCom_BigNumberCalcExtType *)HSM_ADDRESS_UP_ALIGN(
            &(pCtx->tL1AlgCtx.tBnCalcInf.aBnCalcParmBuf[0]));

        eRet = HSM_STATUS_SUCCESS;
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_BnCalcExitEnv(HSM_L1_RtCtxType *pCtx)
{
    HSM_BoolType   bInProcess = pCtx->bInProcess;
    HSM_StatusType eRet       = HSM_STATUS_SUCCESS;

    if ((HSM_TRUE == bInProcess) && (HSM_OP_BN_CALC == pCtx->eOperationCata))
    {
        eRet = HSM_L1_CommonExitEnv(pCtx);
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}

hsm_uint32_t hsm_pkam_get_actual_size(HSM_DataFormatType  eDataFormat,
                                      const void         *pData,
                                      hsm_uint32_t        u32ByteCount,
                                      const hsm_uint8_t **ppLastNonZero)
{
    hsm_int32_t        s32Idx;
    HSM_BoolType       bFindNonZero      = HSM_FALSE;
    const hsm_uint8_t *pLastNoneZeroByte = (const hsm_uint8_t *)pData;
    const hsm_uint8_t *pInterU8          = (const hsm_uint8_t *)pData;

    if (HSM_DATA_FORMAT_1B == eDataFormat)
    {
        while ((u32ByteCount > 0u) && (0u == *pInterU8))
        {
            pInterU8++;
            u32ByteCount--;
        }

        pLastNoneZeroByte = pInterU8;
    }
    else
    {
        while (u32ByteCount > 3u)
        {
            for (s32Idx = 3; s32Idx >= 0; --s32Idx)
            {
                if (0u == pInterU8[s32Idx])
                {
                    u32ByteCount--;
                }
                else
                {
                    bFindNonZero      = HSM_TRUE;
                    pLastNoneZeroByte = (const hsm_uint8_t *)pInterU8 + s32Idx;
                    break;
                }
            }

            if (HSM_TRUE == bFindNonZero)
            {
                break;
            }
            else
            {
                ; /* nothing to do */
            }

            pInterU8 += 4u;
        }

        if (HSM_TRUE != bFindNonZero)
        {
            for (s32Idx = 3; s32Idx >= (4 - (hsm_int8_t)u32ByteCount); --s32Idx)
            {
                if (0u == pInterU8[s32Idx])
                {
                    u32ByteCount--;
                }
                else
                {
                    bFindNonZero      = HSM_TRUE;
                    pLastNoneZeroByte = pInterU8 + s32Idx;
                    break;
                }
            }
        }
    }

    if (NULL_PTR != ppLastNonZero)
    {
        *ppLastNonZero = pLastNoneZeroByte;
    }
    else
    {
        ; /* nothing to do */
    }

    return u32ByteCount;
}

/* if 4B format input, but size error, return HSM_STATUS_PARAM_ERR, others, HSM_STATUS_SUCCESS */
HSM_StatusType hsm_pkam_get_bn_bit_count(HSM_DataFormatType eFmt,
                                         const hsm_uint8_t *pData,
                                         hsm_uint32_t       u32ByteCnt,
                                         hsm_uint32_t      *pBitCnt)
{
    HSM_StatusType     eRet = HSM_STATUS_SUCCESS;
    const hsm_uint8_t *pLastNonZero;
    hsm_uint32_t       u32Size;
    hsm_uint32_t       u32Idx;
    hsm_uint32_t       u32Data;

    if (u32ByteCnt > 0)
    {
        if (HSM_DATA_FORMAT_1B == eFmt)
        {
            u32Size = hsm_pkam_get_actual_size(eFmt, pData, u32ByteCnt, &pLastNonZero);
            if (u32Size > 0u)
            {
                for (u32Idx = 8u; u32Idx > 0u; u32Idx--)
                {
                    if (pLastNonZero[0] & (((hsm_uint8_t)0x1u) << (u32Idx - 1u)))
                    {
                        break;
                    }
                }

                u32Size = u32Idx + ((u32Size - 1u) * 8u);
            }
            /* else do nothing */
        }
        else if ((HSM_DATA_FORMAT_4B == eFmt) && (u32ByteCnt >= 4u) && (0u == (u32ByteCnt & 0x3u)))
        {
            u32Size = hsm_pkam_get_actual_size(eFmt, pData, u32ByteCnt, &pLastNonZero);
            if (u32Size > 0u)
            {
                u32Data = ((hsm_uint32_t)pLastNonZero[0u]);
                for (u32Idx = 8u; u32Idx > 0u; u32Idx--)
                {

                    if (u32Data & ((hsm_uint32_t)(((hsm_uint8_t)0x1u) << (u32Idx - 1u))))
                    {
                        break;
                    }
                }

                u32Size = u32Idx + ((u32Size - 1u) * 8u);
            }
            /* else do nothing */
        }
        else
        {
            eRet = HSM_STATUS_PARAM_ERR;
        }
    }
    else
    {
        u32Size = 0u;
    }

    if ((HSM_STATUS_SUCCESS == eRet) && (pBitCnt))
    {
        hsm_memcpy(pBitCnt, &u32Size, sizeof(u32Size));
    }
    /* else do nothing */

    return eRet;
}

/* For interrupt usage */
HSM_StatusType HSM_L1_BnCalc(HSM_L1_RtCtxType        *pCtx,
                             const HSM_L1_BnCalcType *pCfg,
                             hsm_uint32_t             u32TimeoutMs)
{
    HSM_StatusType     eRet       = HSM_STATUS_SUCCESS;
    HSM_BoolType       bInProcess = HSM_FALSE;
    const hsm_uint8_t *pStart;
    hsm_uint32_t       u32ActualSize;
    hsm_uint32_t       u32PassToHsmCoreSize;

    if ((NULL_PTR != pCtx) && (NULL_PTR != pCfg) && (pCfg->u32BitCnt <= 4096U) &&
        (pCfg->eCalcType <= HSM_L1_BNCALC_A_RECIPROCAL) && (NULL_PTR != pCfg->pA) &&
        (pCfg->u32AByteCount > 0u) &&
        ((pCfg->eCalcType > HSM_L1_BNCALC_A_x_B) ||
         ((NULL_PTR != pCfg->pB) && (pCfg->u32BByteCount > 0u))) &&
        ((pCfg->eCalcType != HSM_L1_BNCALC_A_Exp_E) ||
         ((0u != pCfg->u32KeyEId) || ((NULL_PTR != pCfg->pE) && (pCfg->u32EByteCount > 0u)))) &&
        ((0u != pCfg->u32KeyNId) || ((NULL_PTR != pCfg->pN) && (pCfg->u32NByteCount > 0u))) &&
        (NULL_PTR != pCfg->pResult))
    {
        bInProcess = pCtx->bInProcess;

        if ((HSM_TRUE == bInProcess) && (HSM_OP_BN_CALC == pCtx->eOperationCata))
        {
            if (HSM_DRV_SM_ARITH != pCtx->eStat)
            {
                pCtx->tL1AlgCtx.tBnCalcInf.pBnCalcParm->tCfg.u32DataValidFlag = 0u;

                pCtx->tL1AlgCtx.tBnCalcInf.pBnCalcParm->u32HSMStatusRet    = MAILBOXAPI_RET_NONE;
                pCtx->tL1AlgCtx.tBnCalcInf.pBnCalcParm->u32Timeout         = u32TimeoutMs;
                pCtx->tL1AlgCtx.tBnCalcInf.pBnCalcParm->u32UserKeyID_KEY_E = pCfg->u32KeyEId;
                pCtx->tL1AlgCtx.tBnCalcInf.pBnCalcParm->u32UserKeyID_KEY_N = pCfg->u32KeyNId;
                pCtx->tL1AlgCtx.tBnCalcInf.pBnCalcParm->u32BitCnt          = pCfg->u32BitCnt;

                pCtx->tL1AlgCtx.tBnCalcInf.pBnCalcParm->tCfg.pA            = pCfg->pA;
                pCtx->tL1AlgCtx.tBnCalcInf.pBnCalcParm->tCfg.u32AByteCount = pCfg->u32AByteCount;
                pCtx->tL1AlgCtx.tBnCalcInf.pBnCalcParm->tCfg.eInputDataFmt = pCfg->eAFmt;

                /* load e */
                if (pCfg->eCalcType == HSM_L1_BNCALC_A_Exp_E)
                {
                    pCtx->tL1AlgCtx.tBnCalcInf.pBnCalcParm->tCfg.eKeyEFmt = pCfg->eEFmt;
                    pCtx->tL1AlgCtx.tBnCalcInf.pBnCalcParm->tCfg.u32EByteCount = pCfg->u32EByteCount;

                    if (pCfg->u32KeyEId)
                    {
                        pCtx->tL1AlgCtx.tBnCalcInf.pBnCalcParm->tCfg.pE = NULL_PTR;
                    }
                    else
                    {
                        pCtx->tL1AlgCtx.tBnCalcInf.pBnCalcParm->tCfg.pE = pCfg->pE;
                    }

                    pCtx->tL1AlgCtx.tBnCalcInf.pBnCalcParm->tCfg.u32DataValidFlag |=
                        HSM_BN_VALID_FLAG_E;
                }
                else
                {
                    pCtx->tL1AlgCtx.tBnCalcInf.pBnCalcParm->u32UserKeyID_KEY_E = 0u;
                    pCtx->tL1AlgCtx.tBnCalcInf.pBnCalcParm->tCfg.u32EByteCount = 0u;
                    pCtx->tL1AlgCtx.tBnCalcInf.pBnCalcParm->tCfg.pE            = NULL_PTR;
                    pCtx->tL1AlgCtx.tBnCalcInf.pBnCalcParm->tCfg.eKeyEFmt      = HSM_DATA_FORMAT_4B;
                }

                if (pCfg->u32KeyNId)
                {
                    pCtx->tL1AlgCtx.tBnCalcInf.pBnCalcParm->tCfg.pN = NULL_PTR;
                }
                else
                {
                    pCtx->tL1AlgCtx.tBnCalcInf.pBnCalcParm->tCfg.pN = pCfg->pN;
                }

                pCtx->tL1AlgCtx.tBnCalcInf.pBnCalcParm->tCfg.u32NByteCount = pCfg->u32NByteCount;
                pCtx->tL1AlgCtx.tBnCalcInf.pBnCalcParm->tCfg.eKeyNFmt      = pCfg->eNFmt;

                if (HSM_DATA_FORMAT_1B_PAD_0_LEFT_FIT_BUF != pCfg->eResultFmt)
                {
                    pCtx->tL1AlgCtx.tBnCalcInf.pBnCalcParm->tCfg.pResult = pCfg->pResult;
                    pCtx->tL1AlgCtx.tBnCalcInf.pBnCalcParm->tCfg.u32ResultBufByteCnt =
                        pCfg->u32ResultBufByteCnt;
                    pCtx->tL1AlgCtx.tBnCalcInf.pBnCalcParm->tCfg.pResultByteCount =
                        pCfg->pResultByteCnt;
                    pCtx->tL1AlgCtx.tBnCalcInf.pBnCalcParm->tCfg.eOutputFmt = pCfg->eResultFmt;

                    if (NULL_PTR == pCfg->pResultByteCnt)
                    {
                        pCtx->tL1AlgCtx.tBnCalcInf.pBnCalcParm->tCfg.pResultByteCount = &(
                            pCtx->tL1AlgCtx.tBnCalcInf.u32ResultByteCnt);
                    }

                    if (NULL_PTR == pCfg->pResult)
                    {
                        pCtx->tL1AlgCtx.tBnCalcInf.pBnCalcParm->tCfg.u32ResultBufByteCnt = 0u;
                    }

                    if (0u == pCtx->tL1AlgCtx.tBnCalcInf.pBnCalcParm->tCfg.u32ResultBufByteCnt)
                    {
                        pCtx->tL1AlgCtx.tBnCalcInf.pBnCalcParm->tCfg.pResult = (hsm_uint8_t *)
                            HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tBnCalcInf.aResultCache[0]));
                    }
                }
                else
                {
                    pCtx->tL1AlgCtx.tBnCalcInf.pResultBuf       = pCfg->pResult;
                    pCtx->tL1AlgCtx.tBnCalcInf.u32ResultBufSize = pCfg->u32ResultBufByteCnt;
                    pCtx->tL1AlgCtx.tBnCalcInf.pResultByteCnt   = pCfg->pResultByteCnt;
                    pCtx->tL1AlgCtx.tBnCalcInf.eOutFmt          = pCfg->eResultFmt;

                    pCtx->tL1AlgCtx.tBnCalcInf.pBnCalcParm->tCfg.pResult = (hsm_uint8_t *)
                        HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tBnCalcInf.aResultCache[0]));
                    pCtx->tL1AlgCtx.tBnCalcInf.pBnCalcParm->tCfg.u32ResultBufByteCnt =
                        sizeof(pCtx->tL1AlgCtx.tBnCalcInf.aResultCache) - 4u;
                    pCtx->tL1AlgCtx.tBnCalcInf.pBnCalcParm->tCfg.pResultByteCount = &(
                        pCtx->tL1AlgCtx.tBnCalcInf.u32ResultByteCnt);
                    pCtx->tL1AlgCtx.tBnCalcInf.pBnCalcParm->tCfg.eOutputFmt = HSM_DATA_FORMAT_1B;
                }

                pCtx->tL1AlgCtx.tBnCalcInf.pBnCalcParm->tCfg.u32CalcType =
                    (hsm_uint32_t)(pCfg->eCalcType) + HSM_BIGNUMBER_CALC_A_ADD_B;

                /* load b */
                if (pCfg->eCalcType <= HSM_L1_BNCALC_A_x_B)
                {

                    if (pCtx->tL1AlgCtx.tBnCalcInf.pBnCalcParm->tCfg.eInputDataFmt != pCfg->eBFmt)
                    {
                        u32PassToHsmCoreSize = ((pCfg->u32BByteCount + 7u) >> 3u) << 3u;

                        pCtx->tL1AlgCtx.tBnCalcInf.pBnCalcParm->tCfg.pB = (const hsm_uint8_t *)&(
                            pCtx->tL1AlgCtx.tBnCalcInf.aB[0]);
                        pCtx->tL1AlgCtx.tBnCalcInf.pBnCalcParm->tCfg.u32BByteCount =
                            u32PassToHsmCoreSize;

                        hsm_rm_prefix_zeros(pCfg->eBFmt,
                                            pCfg->pB,
                                            pCfg->u32BByteCount,
                                            &pStart,
                                            &u32ActualSize);
                        hsm_memset((void *)HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tBnCalcInf.aB[0])),
                                   0,
                                   u32PassToHsmCoreSize - u32ActualSize);
                        hsm_memcpy(((hsm_uint8_t *)HSM_ADDRESS_UP_ALIGN(
                                       &(pCtx->tL1AlgCtx.tBnCalcInf.aB[0]))) +
                                       (u32PassToHsmCoreSize - u32ActualSize),
                                   pStart,
                                   u32ActualSize);
                        hsm_u32_array_swap((hsm_uint32_t *)HSM_ADDRESS_UP_ALIGN(
                                               &(pCtx->tL1AlgCtx.tBnCalcInf.aB[0])),
                                           u32PassToHsmCoreSize >> 2u);
                    }
                    else
                    {
                        pCtx->tL1AlgCtx.tBnCalcInf.pBnCalcParm->tCfg.pB = pCfg->pB;
                        pCtx->tL1AlgCtx.tBnCalcInf.pBnCalcParm->tCfg.u32BByteCount =
                            pCfg->u32BByteCount;
                    }

                    pCtx->tL1AlgCtx.tBnCalcInf.pBnCalcParm->tCfg.u32DataValidFlag |=
                        HSM_BN_VALID_FLAG_B;
                }
                else
                {
                    pCtx->tL1AlgCtx.tBnCalcInf.pBnCalcParm->tCfg.pB            = NULL_PTR;
                    pCtx->tL1AlgCtx.tBnCalcInf.pBnCalcParm->tCfg.u32BByteCount = 0u;
                }

                eRet = HSM_FW_BigNumberCalculateEx(&(pCtx->tCmd),
                                                   pCtx->tL1AlgCtx.tBnCalcInf.pBnCalcParm);
                if (HSM_STATUS_SUCCESS == eRet)
                {
                    pCtx->eStat = HSM_DRV_SM_ARITH;
                    eRet        = pCtx->pSendCmdCb(&(pCtx->tCmd));
                    if (HSM_STATUS_SUCCESS != eRet)
                    {
                        pCtx->eStat = HSM_DRV_SM_STOP;
                        eRet        = HSM_STATUS_SEND_FAIL;
                    }
                    /* else do nothing */
                }
                /* else do nothing */
            }
            else
            {
                eRet = HSM_STATUS_BUSY;
            }
        }
        else
        {
            eRet = HSM_STATUS_LOGIC_ERR;
        }
    }
    else
    {
        eRet = HSM_STATUS_PARAM_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_BnCalc_Isr(HSM_L1_RtCtxType *pCtx)
{
    const hsm_uint8_t *pStart;
    hsm_uint32_t       u32ActualSize;
    HSM_StatusType     eRet;

    if (MAILBOXAPI_RET_SUCCESS == pCtx->tL1AlgCtx.tBnCalcInf.pBnCalcParm->u32HSMStatusRet)
    {
        if (HSM_DATA_FORMAT_1B_PAD_0_LEFT_FIT_BUF == pCtx->tL1AlgCtx.tBnCalcInf.eOutFmt)
        {
            hsm_rm_prefix_zeros(
                HSM_DATA_FORMAT_1B,
                (const hsm_uint8_t *)pCtx->tL1AlgCtx.tBnCalcInf.pBnCalcParm->tCfg.pResult,
                pCtx->tL1AlgCtx.tBnCalcInf.u32ResultByteCnt,
                &pStart,
                &u32ActualSize);

            if (u32ActualSize > pCtx->tL1AlgCtx.tBnCalcInf.u32ResultBufSize)
            {
                eRet = HSM_STATUS_BUFFER_SIZE_ERR;
            }
            else
            {
                if (NULL_PTR != pCtx->tL1AlgCtx.tBnCalcInf.pResultBuf)
                {
                    hsm_memset(pCtx->tL1AlgCtx.tBnCalcInf.pResultBuf,
                               0,
                               pCtx->tL1AlgCtx.tBnCalcInf.u32ResultBufSize - u32ActualSize);
                    hsm_memcpy(((hsm_uint8_t *)pCtx->tL1AlgCtx.tBnCalcInf.pResultBuf) +
                                   (pCtx->tL1AlgCtx.tBnCalcInf.u32ResultBufSize - u32ActualSize),
                               pStart,
                               u32ActualSize);
                }

                if (NULL_PTR != pCtx->tL1AlgCtx.tBnCalcInf.pResultByteCnt)
                {
                    *pCtx->tL1AlgCtx.tBnCalcInf.pResultByteCnt =
                        pCtx->tL1AlgCtx.tBnCalcInf.u32ResultBufSize;
                }

                eRet = HSM_STATUS_SUCCESS;
            }
        }

        pCtx->eStat = HSM_DRV_SM_STOP;
    }
    else
    {
        eRet        = HSM_STATUS_HW_ERR;
        pCtx->eStat = HSM_DRV_SM_STOP;
    }

    return eRet;
}

HSM_StatusType HSM_L1_BnCalcPoll(HSM_L1_RtCtxType *pCtx)
{
    HSM_StatusType eRet       = HSM_STATUS_SUCCESS;
    HSM_BoolType   bInProcess = HSM_FALSE;

    bInProcess = pCtx->bInProcess;

    if ((HSM_TRUE == bInProcess) && (HSM_OP_BN_CALC == pCtx->eOperationCata))
    {
        if (HSM_DRV_SM_ARITH == pCtx->eStat)
        {
            eRet = pCtx->pReadAckCb();
            if (HSM_STATUS_BUSY == eRet)
            {
                eRet = HSM_STATUS_AGAIN;
            }
            else if (HSM_STATUS_SUCCESS == eRet)
            {
                eRet = HSM_L1_BnCalc_Isr(pCtx);
            }
            else
            {
                pCtx->eStat = HSM_DRV_SM_STOP;
            }
        }
        else
        {
            eRet = HSM_STATUS_HW_IDLE;
        }
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_BnCalcReset(HSM_L1_RtCtxType *pCtx)
{
    HSM_BoolType   bInProcess = HSM_FALSE;
    HSM_StatusType eRet       = HSM_STATUS_SUCCESS;

    bInProcess = pCtx->bInProcess;

    if ((HSM_TRUE == bInProcess) && (HSM_OP_BN_CALC == pCtx->eOperationCata))
    {
        if (HSM_DRV_SM_ARITH == pCtx->eStat)
        {
            eRet = pCtx->pCancelCmdCb();
        }

        if (HSM_STATUS_SUCCESS == eRet)
        {
            pCtx->eStat = HSM_DRV_SM_READY;
        }
        else
        {
            ;
        }
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_ScatterHashSetupEnv(HSM_L1_RtCtxType *pCtx)
{
    HSM_BoolType   bInProcess;
    HSM_StatusType eRet;

    bInProcess = pCtx->bInProcess;
    if (HSM_FALSE == bInProcess)
    {
        pCtx->bInProcess     = HSM_TRUE;
        pCtx->eOperationCata = HSM_OP_SCATTER_HASH;
        pCtx->eStat          = HSM_DRV_SM_READY;

        hsm_memset(&(pCtx->tL1AlgCtx.tScatterHash), 0, sizeof(pCtx->tL1AlgCtx.tScatterHash));

        pCtx->tL1AlgCtx.tScatterHash.tMacCfg.bGenerateMacEn           = HSM_FALSE;
        pCtx->tL1AlgCtx.tScatterHash.tMacCfg.tHashMacKeyInfo.pKeyData = (const hsm_uint8_t *)
            HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tScatterHash.aMacKeyCache[0]));

        pCtx->tL1AlgCtx.tScatterHash.pOut       = NULL_PTR;
        pCtx->tL1AlgCtx.tScatterHash.pOutSize   = NULL_PTR;
        pCtx->tL1AlgCtx.tScatterHash.eState     = HSM_L1_SCATTER_HASH_READY;
        pCtx->tL1AlgCtx.tScatterHash.pInputData = NULL_PTR;
        pCtx->tL1AlgCtx.tScatterHash.pScatterHashParm = (HSMCom_ScatterHashType *)HSM_ADDRESS_UP_ALIGN(
            &(pCtx->tL1AlgCtx.tScatterHash.tScatterHashParamShared.aScatterHashParmBuf[0]));

        pCtx->tL1AlgCtx.tScatterHash.pScatterHashParm->tCfg.pResult = &(
            pCtx->tL1AlgCtx.tScatterHash.tScatterHashResultShared.aHashCtx);
        pCtx->tL1AlgCtx.tScatterHash.pScatterHashParm->tCfg.tCfg.bGenerateMacEn =
            pCtx->tL1AlgCtx.tScatterHash.tMacCfg.bGenerateMacEn;
        pCtx->tL1AlgCtx.tScatterHash.pScatterHashParm->tCfg.tCfg.tKeyInfo.pKeyData =
            pCtx->tL1AlgCtx.tScatterHash.tMacCfg.tHashMacKeyInfo.pKeyData;

        eRet = HSM_STATUS_SUCCESS;
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_ScatterHashSetMacCfg(HSM_L1_RtCtxType *pCtx, HSM_Ln_HashMacCfgType *ptCfg)
{
    HSM_StatusType eRet = HSM_STATUS_SUCCESS;
    HSM_BoolType   bInProcess;

    hsm_uint32_t u32Temp;

    bInProcess = pCtx->bInProcess;
    if ((HSM_TRUE == bInProcess) && (HSM_OP_SCATTER_HASH == pCtx->eOperationCata) &&
        (HSM_L1_SCATTER_HASH_READY == pCtx->tL1AlgCtx.tScatterHash.eState))
    {
        if (HSM_DRV_SM_ARITH != pCtx->eStat)
        {
            if (ptCfg->u32KeyByteCnt <= (4 * 0x20))
            {
                pCtx->tL1AlgCtx.tScatterHash.tMacCfg.bGenerateMacEn = ptCfg->bGenerateMacEn;
                pCtx->tL1AlgCtx.tScatterHash.pScatterHashParm->tCfg.tCfg.bGenerateMacEn =
                    ptCfg->bGenerateMacEn;

                if (HSM_FALSE != ptCfg->bGenerateMacEn)
                {
                    pCtx->tL1AlgCtx.tScatterHash.tMacCfg.eMacType      = ptCfg->eMacType;
                    pCtx->tL1AlgCtx.tScatterHash.tMacCfg.u32KeyByteCnt = ptCfg->u32KeyByteCnt;
                    pCtx->tL1AlgCtx.tScatterHash.tMacCfg.u32GenerateMacByteCnt =
                        ptCfg->u32GenerateMacByteCnt;
                    pCtx->tL1AlgCtx.tScatterHash.tMacCfg.eKeyDataFmt = ptCfg->eKeyDataFmt;
                    pCtx->tL1AlgCtx.tScatterHash.tMacCfg.bKeyUseId   = ptCfg->bKeyUseId;

                    if (HSM_FALSE == ptCfg->bKeyUseId)
                    {
                        u32Temp = ((ptCfg->u32KeyByteCnt + 3u) >> 2u) << 2u;
                        hsm_memset((void *)HSM_ADDRESS_UP_ALIGN(
                                       &(pCtx->tL1AlgCtx.tScatterHash.aMacKeyCache[0])),
                                   0,
                                   u32Temp);
                        hsm_memcpy((hsm_uint8_t *)HSM_ADDRESS_UP_ALIGN(
                                       &(pCtx->tL1AlgCtx.tScatterHash.aMacKeyCache[0])),
                                   ptCfg->tHashMacKeyInfo.pKeyData,
                                   ptCfg->u32KeyByteCnt);
                        if (HSM_DATA_FORMAT_1B == ptCfg->eKeyDataFmt)
                        {
                            hsm_u32_array_swap((hsm_uint32_t *)HSM_ADDRESS_UP_ALIGN(
                                                   &(pCtx->tL1AlgCtx.tScatterHash.aMacKeyCache[0])),
                                               u32Temp >> 2u);
                        }
                        /* else do nothing */

                        pCtx->tL1AlgCtx.tScatterHash.tMacCfg.tHashMacKeyInfo.pKeyData =
                            (const hsm_uint8_t *)HSM_ADDRESS_UP_ALIGN(
                                &(pCtx->tL1AlgCtx.tScatterHash.aMacKeyCache[0]));
                        pCtx->tL1AlgCtx.tScatterHash.pScatterHashParm->tCfg.tCfg.tKeyInfo.pKeyData =
                            pCtx->tL1AlgCtx.tScatterHash.tMacCfg.tHashMacKeyInfo.pKeyData;
                    }
                    else
                    {
                        pCtx->tL1AlgCtx.tScatterHash.tMacCfg.tHashMacKeyInfo.u32KeyId =
                            ptCfg->tHashMacKeyInfo.u32KeyId;
                        pCtx->tL1AlgCtx.tScatterHash.pScatterHashParm->tCfg.tCfg.tKeyInfo.u32KeyId =
                            pCtx->tL1AlgCtx.tScatterHash.tMacCfg.tHashMacKeyInfo.u32KeyId;
                    }

                    pCtx->tL1AlgCtx.tScatterHash.pScatterHashParm->tCfg.tCfg.eMacType =
                        pCtx->tL1AlgCtx.tScatterHash.tMacCfg.eMacType;

                    pCtx->tL1AlgCtx.tScatterHash.pScatterHashParm->tCfg.tCfg.u32KeyByteCnt =
                        pCtx->tL1AlgCtx.tScatterHash.tMacCfg.u32KeyByteCnt;
                    pCtx->tL1AlgCtx.tScatterHash.pScatterHashParm->tCfg.tCfg.u32GenerateMacByteCnt =
                        pCtx->tL1AlgCtx.tScatterHash.tMacCfg.u32GenerateMacByteCnt;
                }
                else
                {
                    pCtx->tL1AlgCtx.tScatterHash.tMacCfg.tHashMacKeyInfo.pKeyData =
                        (const hsm_uint8_t *)HSM_ADDRESS_UP_ALIGN(
                            &(pCtx->tL1AlgCtx.tScatterHash.aMacKeyCache[0]));
                    pCtx->tL1AlgCtx.tScatterHash.pScatterHashParm->tCfg.tCfg.tKeyInfo.pKeyData =
                        pCtx->tL1AlgCtx.tScatterHash.tMacCfg.tHashMacKeyInfo.pKeyData;
                }
            }
            else
            {
                eRet = HSM_STATUS_PARAM_ERR;
            }
        }
        else
        {
            eRet = HSM_STATUS_BUSY;
        }
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}

static HSM_StatusType hsm_l1_scatter_hash_init(HSM_L1_RtCtxType *pCtx, HSM_DataFormatType eInputFmt)
{
    HSM_StatusType eRet = HSM_FW_ScatterHashInit(&(pCtx->tCmd),
                                                 pCtx->tL1AlgCtx.tScatterHash.pScatterHashParm,
                                                 pCtx->tL1AlgCtx.tScatterHash.tMacCfg.bKeyUseId,
                                                 eInputFmt);

    if (HSM_STATUS_SUCCESS == eRet)
    {
        pCtx->eStat = HSM_DRV_SM_ARITH;
        eRet        = pCtx->pSendCmdCb(&(pCtx->tCmd));
        if (HSM_STATUS_SUCCESS != eRet)
        {
            pCtx->eStat                         = HSM_DRV_SM_STOP;
            pCtx->tL1AlgCtx.tScatterHash.eState = HSM_L1_SCATTER_HASH_STOP;
            eRet                                = HSM_STATUS_ERROR;
        }
        /* else do nothing */
    }
    else
    {
        pCtx->tL1AlgCtx.tScatterHash.eState = HSM_L1_SCATTER_HASH_STOP;
        eRet                                = HSM_STATUS_ERROR;
    }

    return eRet;
}

static HSM_StatusType hsm_l1_scatter_hash_update(HSM_L1_RtCtxType *pCtx, HSM_DataFormatType eInputFmt)
{
    HSM_StatusType eRet = HSM_FW_ScatterHashUpdate(&(pCtx->tCmd),
                                                   pCtx->tL1AlgCtx.tScatterHash.pScatterHashParm,
                                                   pCtx->tL1AlgCtx.tScatterHash.tMacCfg.bKeyUseId,
                                                   eInputFmt);
    if (HSM_STATUS_SUCCESS == eRet)
    {
        pCtx->eStat = HSM_DRV_SM_ARITH;
        eRet        = pCtx->pSendCmdCb(&(pCtx->tCmd));
        if (HSM_STATUS_SUCCESS != eRet)
        {
            pCtx->eStat                         = HSM_DRV_SM_STOP;
            pCtx->tL1AlgCtx.tScatterHash.eState = HSM_L1_SCATTER_HASH_STOP;
            eRet                                = HSM_STATUS_ERROR;
        }
        /* else do nothing */
    }
    else
    {
        pCtx->tL1AlgCtx.tScatterHash.eState = HSM_L1_SCATTER_HASH_STOP;
        eRet                                = HSM_STATUS_ERROR;
    }

    return eRet;
}

static HSM_StatusType hsm_l1_scatter_hash_final(HSM_L1_RtCtxType *pCtx, HSM_DataFormatType eInputFmt)
{
    HSM_StatusType eRet = HSM_FW_ScatterHashFinal(&(pCtx->tCmd),
                                                  pCtx->tL1AlgCtx.tScatterHash.pScatterHashParm,
                                                  pCtx->tL1AlgCtx.tScatterHash.tMacCfg.bKeyUseId,
                                                  eInputFmt);
    if (HSM_STATUS_SUCCESS == eRet)
    {
        pCtx->eStat = HSM_DRV_SM_ARITH;
        eRet        = pCtx->pSendCmdCb(&(pCtx->tCmd));
        if (HSM_STATUS_SUCCESS != eRet)
        {
            pCtx->eStat                         = HSM_DRV_SM_STOP;
            pCtx->tL1AlgCtx.tScatterHash.eState = HSM_L1_SCATTER_HASH_STOP;
            eRet                                = HSM_STATUS_ERROR;
        }
        /* else do nothing */
    }
    else
    {
        pCtx->tL1AlgCtx.tScatterHash.eState = HSM_L1_SCATTER_HASH_STOP;
        eRet                                = HSM_STATUS_ERROR;
    }

    return eRet;
}

static HSM_StatusType hsm_l1_scatter_hash_init2final(HSM_L1_RtCtxType *pCtx,
                                                     HSMCom_ShaExType *pShaParm)
{
    HSM_StatusType eRet =
        HSM_FW_ShaEx(&(pCtx->tCmd), pShaParm, pCtx->tL1AlgCtx.tScatterHash.tMacCfg.bKeyUseId);
    if (HSM_STATUS_SUCCESS == eRet)
    {
        pCtx->eStat = HSM_DRV_SM_ARITH;
        eRet        = pCtx->pSendCmdCb(&(pCtx->tCmd));
        if (HSM_STATUS_SUCCESS != eRet)
        {
            pCtx->eStat                         = HSM_DRV_SM_STOP;
            pCtx->tL1AlgCtx.tScatterHash.eState = HSM_L1_SCATTER_HASH_STOP;
            eRet                                = HSM_STATUS_ERROR;
        }
    }
    else
    {
        pCtx->tL1AlgCtx.tScatterHash.eState = HSM_L1_SCATTER_HASH_STOP;
        eRet                                = HSM_STATUS_ERROR;
    }

    return eRet;
}

/* when need more data, return again, when trigger successfully, return success, others error */
HSM_StatusType HSM_L1_ScatterHashInit(HSM_L1_RtCtxType             *pCtx,
                                      const HSM_ShaAlgType          eAlg,
                                      const HSM_Ln_ScatterHashType *pCfg,
                                      hsm_uint32_t                  u32TimeoutMs)
{
    HSM_StatusType     eRet = HSM_STATUS_SUCCESS;
    HSM_BoolType       bInProcess;
    HSM_DataFormatType eCurDataFmt;

    bInProcess = pCtx->bInProcess;
    if ((HSM_TRUE == bInProcess) && (HSM_OP_SCATTER_HASH == pCtx->eOperationCata) &&
        (HSM_L1_SCATTER_HASH_READY == pCtx->tL1AlgCtx.tScatterHash.eState))
    {
        if (HSM_DRV_SM_ARITH != pCtx->eStat)
        {
            pCtx->tL1AlgCtx.tScatterHash.u32TimeoutMs        = u32TimeoutMs;
            pCtx->tL1AlgCtx.tScatterHash.eAlg                = eAlg;
            pCtx->tL1AlgCtx.tScatterHash.pOut                = NULL_PTR;
            pCtx->tL1AlgCtx.tScatterHash.u32OutBufSize       = 0;
            pCtx->tL1AlgCtx.tScatterHash.eOutFmt             = HSM_DATA_FORMAT_4B;
            pCtx->tL1AlgCtx.tScatterHash.pOutSize            = NULL_PTR;
            pCtx->tL1AlgCtx.tScatterHash.pInputData          = NULL_PTR;
            pCtx->tL1AlgCtx.tScatterHash.eInputFmt           = pCfg->eDataFmt;
            pCtx->tL1AlgCtx.tScatterHash.u32InputTotalSize   = 0;
            pCtx->tL1AlgCtx.tScatterHash.u32ProcessedSize    = 0;
            pCtx->tL1AlgCtx.tScatterHash.u32CacheDataByteCnt = 0;

            if (pCfg->u32DataSize <= HSM_HFAM_HW_PROCESS_ALIGN(eAlg))
            {
                eRet = hsm_1B4B_convert_from_idx(HSM_DATA_FORMAT_4B,
                                                 &(pCtx->tL1AlgCtx.tScatterHash.aDataBuf[0]),
                                                 0,
                                                 sizeof(pCtx->tL1AlgCtx.tScatterHash.aDataBuf),
                                                 pCfg->eDataFmt,
                                                 pCfg->pData,
                                                 0,
                                                 pCfg->u32DataSize);
                if (HSM_STATUS_SUCCESS == eRet)
                {
                    pCtx->tL1AlgCtx.tScatterHash.eState = HSM_L1_SCATTER_HASH_NEED_MORE_BEFORE_INIT;
                    pCtx->tL1AlgCtx.tScatterHash.u32CacheDataByteCnt = pCfg->u32DataSize;

                    eRet = HSM_STATUS_AGAIN;
                }
                else
                {
                    pCtx->tL1AlgCtx.tScatterHash.eState = HSM_L1_SCATTER_HASH_STOP;
                }
            }
            else /* data is enough for once at least */
            {
                pCtx->tL1AlgCtx.tScatterHash.eState            = HSM_L1_SCATTER_HASH_INIT;
                pCtx->tL1AlgCtx.tScatterHash.pInputData        = pCfg->pData;
                pCtx->tL1AlgCtx.tScatterHash.eInputFmt         = pCfg->eDataFmt;
                pCtx->tL1AlgCtx.tScatterHash.u32InputTotalSize = pCfg->u32DataSize;

                pCtx->tL1AlgCtx.tScatterHash.pScatterHashParm->u32HSMStatusRet = MAILBOXAPI_RET_NONE;
                pCtx->tL1AlgCtx.tScatterHash.pScatterHashParm->u32Timeout = u32TimeoutMs;
                pCtx->tL1AlgCtx.tScatterHash.pScatterHashParm->tCfg.eAlg  = eAlg;

                if ((0x3u == (((hsm_uint32_t)pCfg->pData) & 0x3u))
#if (FC7XXX_HSM_SUBSYSTEM_TYPE == FC7300_HSM_SUBSYSTEM)
                    || (HSM_DATA_FORMAT_1B == pCfg->eDataFmt)
#endif
                )
                {
                    if (pCfg->u32DataSize > sizeof(pCtx->tL1AlgCtx.tScatterHash.aDataBuf))
                    {
                        pCtx->tL1AlgCtx.tScatterHash.u32ProcessedSize = sizeof(
                            pCtx->tL1AlgCtx.tScatterHash.aDataBuf);
                    }
                    else
                    {
                        if (0u == (pCfg->u32DataSize % HSM_HFAM_HW_PROCESS_ALIGN(eAlg)))
                        {
                            pCtx->tL1AlgCtx.tScatterHash.u32ProcessedSize =
                                pCfg->u32DataSize - HSM_HFAM_HW_PROCESS_ALIGN(eAlg);
                        }
                        else
                        {
                            pCtx->tL1AlgCtx.tScatterHash.u32ProcessedSize =
                                (pCfg->u32DataSize / HSM_HFAM_HW_PROCESS_ALIGN(eAlg)) *
                                HSM_HFAM_HW_PROCESS_ALIGN(eAlg);
                        }
                    }

                    eRet = hsm_1B4B_convert_from_idx(HSM_DATA_FORMAT_4B,
                                                     &(pCtx->tL1AlgCtx.tScatterHash.aDataBuf[0]),
                                                     0,
                                                     sizeof(pCtx->tL1AlgCtx.tScatterHash.aDataBuf),
                                                     pCfg->eDataFmt,
                                                     pCfg->pData,
                                                     0,
                                                     pCtx->tL1AlgCtx.tScatterHash.u32ProcessedSize);

                    if (HSM_STATUS_SUCCESS == eRet)
                    {
                        pCtx->tL1AlgCtx.tScatterHash.pScatterHashParm->tCfg.tCfg.u32InputDataByteCnt =
                            pCtx->tL1AlgCtx.tScatterHash.u32ProcessedSize;
                        pCtx->tL1AlgCtx.tScatterHash.pScatterHashParm->tCfg.tCfg.pInputData =
                            (const hsm_uint8_t *)&(pCtx->tL1AlgCtx.tScatterHash.aDataBuf[0]);
                    }

                    eCurDataFmt = HSM_DATA_FORMAT_4B;
                }
                else /* start address 4 aligned */
                {
                    if (0u == (pCfg->u32DataSize % HSM_HFAM_HW_PROCESS_ALIGN(eAlg)))
                    {
                        pCtx->tL1AlgCtx.tScatterHash.u32ProcessedSize =
                            pCfg->u32DataSize - HSM_HFAM_HW_PROCESS_ALIGN(eAlg);
                    }
                    else
                    {
                        pCtx->tL1AlgCtx.tScatterHash.u32ProcessedSize =
                            (pCfg->u32DataSize / HSM_HFAM_HW_PROCESS_ALIGN(eAlg)) *
                            HSM_HFAM_HW_PROCESS_ALIGN(eAlg);
                    }

                    pCtx->tL1AlgCtx.tScatterHash.pScatterHashParm->tCfg.tCfg.u32InputDataByteCnt =
                        pCtx->tL1AlgCtx.tScatterHash.u32ProcessedSize;
                    pCtx->tL1AlgCtx.tScatterHash.pScatterHashParm->tCfg.tCfg.pInputData = pCfg->pData;

                    eCurDataFmt = pCfg->eDataFmt;
                }

                if (HSM_STATUS_SUCCESS == eRet)
                {
                    eRet = hsm_l1_scatter_hash_init(pCtx, eCurDataFmt);
                }
                else
                {
                    pCtx->tL1AlgCtx.tScatterHash.eState = HSM_L1_SCATTER_HASH_STOP;
                    eRet                                = HSM_STATUS_ERROR;
                }
            }
        }
        else
        {
            eRet = HSM_STATUS_BUSY;
        }
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}

/* when need more data, return again, when trigger successfully, return success, others error */
HSM_StatusType HSM_L1_ScatterHashUpdate(HSM_L1_RtCtxType             *pCtx,
                                        const HSM_Ln_ScatterHashType *pCfg,
                                        hsm_uint32_t                  u32TimeoutMs)
{
    HSM_StatusType        eRet      = HSM_STATUS_SUCCESS;
    HSM_ScatterHashSMType eCurState = pCtx->tL1AlgCtx.tScatterHash.eState;
    HSM_BoolType          bInProcess;
    HSM_DataFormatType    eCurDataFmt;

    bInProcess = pCtx->bInProcess;
    if ((HSM_TRUE == bInProcess) && (HSM_OP_SCATTER_HASH == pCtx->eOperationCata) &&
        ((HSM_L1_SCATTER_HASH_NEED_MORE_BEFORE_INIT == eCurState) ||
         (HSM_L1_SCATTER_HASH_INIT_OK == eCurState) ||
         (HSM_L1_SCATTER_HASH_NEED_MORE_BEFORE_UPDATE_FINAL == eCurState) ||
         (HSM_L1_SCATTER_HASH_UPDATE_OK == eCurState)))
    {
        if (HSM_DRV_SM_ARITH != pCtx->eStat)
        {
            pCtx->tL1AlgCtx.tScatterHash.u32TimeoutMs      = u32TimeoutMs;
            pCtx->tL1AlgCtx.tScatterHash.pInputData        = NULL_PTR;
            pCtx->tL1AlgCtx.tScatterHash.eInputFmt         = pCfg->eDataFmt;
            pCtx->tL1AlgCtx.tScatterHash.u32InputTotalSize = 0;
            pCtx->tL1AlgCtx.tScatterHash.u32ProcessedSize  = 0;

            if ((HSM_L1_SCATTER_HASH_NEED_MORE_BEFORE_INIT == eCurState) ||
                (HSM_L1_SCATTER_HASH_NEED_MORE_BEFORE_UPDATE_FINAL == eCurState))
            {
                if ((pCtx->tL1AlgCtx.tScatterHash.u32CacheDataByteCnt + pCfg->u32DataSize) >
                    sizeof(pCtx->tL1AlgCtx.tScatterHash.aDataBuf))
                {
                    pCtx->tL1AlgCtx.tScatterHash.eState = HSM_L1_SCATTER_HASH_UPDATE;

                    pCtx->tL1AlgCtx.tScatterHash.pInputData        = pCfg->pData;
                    pCtx->tL1AlgCtx.tScatterHash.eInputFmt         = pCfg->eDataFmt;
                    pCtx->tL1AlgCtx.tScatterHash.u32InputTotalSize = pCfg->u32DataSize;
                    pCtx->tL1AlgCtx.tScatterHash.u32ProcessedSize =
                        sizeof(pCtx->tL1AlgCtx.tScatterHash.aDataBuf) -
                        pCtx->tL1AlgCtx.tScatterHash.u32CacheDataByteCnt;

                    eRet = hsm_1B4B_convert_from_idx(HSM_DATA_FORMAT_4B,
                                                     &(pCtx->tL1AlgCtx.tScatterHash.aDataBuf[0]),
                                                     pCtx->tL1AlgCtx.tScatterHash.u32CacheDataByteCnt,
                                                     sizeof(pCtx->tL1AlgCtx.tScatterHash.aDataBuf),
                                                     pCfg->eDataFmt,
                                                     pCfg->pData,
                                                     0,
                                                     pCtx->tL1AlgCtx.tScatterHash.u32ProcessedSize);

                    pCtx->tL1AlgCtx.tScatterHash.pScatterHashParm->tCfg.tCfg.u32InputDataByteCnt =
                        sizeof(pCtx->tL1AlgCtx.tScatterHash.aDataBuf);
                    pCtx->tL1AlgCtx.tScatterHash.pScatterHashParm->tCfg.tCfg.pInputData =
                        (const hsm_uint8_t *)&(pCtx->tL1AlgCtx.tScatterHash.aDataBuf[0]);

                    pCtx->tL1AlgCtx.tScatterHash.u32CacheDataByteCnt = 0u;

                    pCtx->tL1AlgCtx.tScatterHash.pScatterHashParm->u32HSMStatusRet =
                        MAILBOXAPI_RET_NONE;
                    pCtx->tL1AlgCtx.tScatterHash.pScatterHashParm->u32Timeout = u32TimeoutMs;
                    pCtx->tL1AlgCtx.tScatterHash.pScatterHashParm->tCfg.eAlg =
                        pCtx->tL1AlgCtx.tScatterHash.eAlg;

                    eCurDataFmt = HSM_DATA_FORMAT_4B;

                    if (HSM_STATUS_SUCCESS == eRet)
                    {
                        if (HSM_L1_SCATTER_HASH_NEED_MORE_BEFORE_INIT == eCurState)
                        {
                            eRet = hsm_l1_scatter_hash_init(pCtx, eCurDataFmt);
                        }
                        else
                        {
                            eRet = hsm_l1_scatter_hash_update(pCtx, eCurDataFmt);
                        }
                    }
                    else
                    {
                        pCtx->tL1AlgCtx.tScatterHash.eState = HSM_L1_SCATTER_HASH_STOP;
                        eRet                                = HSM_STATUS_ERROR;
                    }
                }
                else
                {
                    eRet = hsm_1B4B_convert_from_idx(HSM_DATA_FORMAT_4B,
                                                     &(pCtx->tL1AlgCtx.tScatterHash.aDataBuf[0]),
                                                     pCtx->tL1AlgCtx.tScatterHash.u32CacheDataByteCnt,
                                                     sizeof(pCtx->tL1AlgCtx.tScatterHash.aDataBuf),
                                                     pCfg->eDataFmt,
                                                     pCfg->pData,
                                                     0,
                                                     pCfg->u32DataSize);

                    if (HSM_STATUS_SUCCESS == eRet)
                    {
                        /* NOT change the state */
                        pCtx->tL1AlgCtx.tScatterHash.u32CacheDataByteCnt += pCfg->u32DataSize;
                        eRet = HSM_STATUS_AGAIN;
                    }
                    else
                    {
                        pCtx->tL1AlgCtx.tScatterHash.eState = HSM_L1_SCATTER_HASH_STOP;
                    }
                }
            }
            else /* init ok / update ok */
            {
                if (pCfg->u32DataSize <= HSM_HFAM_HW_PROCESS_ALIGN(pCtx->tL1AlgCtx.tScatterHash.eAlg))
                {
                    eRet = hsm_1B4B_convert_from_idx(HSM_DATA_FORMAT_4B,
                                                     &(pCtx->tL1AlgCtx.tScatterHash.aDataBuf[0]),
                                                     0,
                                                     sizeof(pCtx->tL1AlgCtx.tScatterHash.aDataBuf),
                                                     pCfg->eDataFmt,
                                                     pCfg->pData,
                                                     0,
                                                     pCfg->u32DataSize);
                    if (HSM_STATUS_SUCCESS == eRet)
                    {
                        pCtx->tL1AlgCtx.tScatterHash.eState =
                            HSM_L1_SCATTER_HASH_NEED_MORE_BEFORE_UPDATE_FINAL;
                        pCtx->tL1AlgCtx.tScatterHash.u32CacheDataByteCnt = pCfg->u32DataSize;

                        eRet = HSM_STATUS_AGAIN;
                    }
                    else
                    {
                        pCtx->tL1AlgCtx.tScatterHash.eState = HSM_L1_SCATTER_HASH_STOP;
                    }
                }
                else /* data is enough for once at least */
                {
                    pCtx->tL1AlgCtx.tScatterHash.eState            = HSM_L1_SCATTER_HASH_UPDATE;
                    pCtx->tL1AlgCtx.tScatterHash.pInputData        = pCfg->pData;
                    pCtx->tL1AlgCtx.tScatterHash.eInputFmt         = pCfg->eDataFmt;
                    pCtx->tL1AlgCtx.tScatterHash.u32InputTotalSize = pCfg->u32DataSize;

                    pCtx->tL1AlgCtx.tScatterHash.u32CacheDataByteCnt = 0u;

                    pCtx->tL1AlgCtx.tScatterHash.pScatterHashParm->u32HSMStatusRet =
                        MAILBOXAPI_RET_NONE;
                    pCtx->tL1AlgCtx.tScatterHash.pScatterHashParm->u32Timeout = u32TimeoutMs;
                    pCtx->tL1AlgCtx.tScatterHash.pScatterHashParm->tCfg.eAlg =
                        pCtx->tL1AlgCtx.tScatterHash.eAlg;

                    if ((0x3u == (((hsm_uint32_t)pCfg->pData) & 0x3))
#if (FC7XXX_HSM_SUBSYSTEM_TYPE == FC7300_HSM_SUBSYSTEM)
                        || (HSM_DATA_FORMAT_1B == pCfg->eDataFmt)
#endif
                    )
                    {
                        if (pCfg->u32DataSize > sizeof(pCtx->tL1AlgCtx.tScatterHash.aDataBuf))
                        {
                            pCtx->tL1AlgCtx.tScatterHash.u32ProcessedSize = sizeof(
                                pCtx->tL1AlgCtx.tScatterHash.aDataBuf);
                        }
                        else
                        {
                            if (0u == (pCfg->u32DataSize %
                                       HSM_HFAM_HW_PROCESS_ALIGN(pCtx->tL1AlgCtx.tScatterHash.eAlg)))
                            {
                                pCtx->tL1AlgCtx.tScatterHash.u32ProcessedSize =
                                    pCfg->u32DataSize -
                                    HSM_HFAM_HW_PROCESS_ALIGN(pCtx->tL1AlgCtx.tScatterHash.eAlg);
                            }
                            else
                            {
                                pCtx->tL1AlgCtx.tScatterHash.u32ProcessedSize =
                                    (pCfg->u32DataSize /
                                     HSM_HFAM_HW_PROCESS_ALIGN(pCtx->tL1AlgCtx.tScatterHash.eAlg)) *
                                    HSM_HFAM_HW_PROCESS_ALIGN(pCtx->tL1AlgCtx.tScatterHash.eAlg);
                            }
                        }

                        eRet = hsm_1B4B_convert_from_idx(
                            HSM_DATA_FORMAT_4B,
                            &(pCtx->tL1AlgCtx.tScatterHash.aDataBuf[0]),
                            0,
                            sizeof(pCtx->tL1AlgCtx.tScatterHash.aDataBuf),
                            pCfg->eDataFmt,
                            pCfg->pData,
                            0,
                            pCtx->tL1AlgCtx.tScatterHash.u32ProcessedSize);
                        if (HSM_STATUS_SUCCESS == eRet)
                        {
                            pCtx->tL1AlgCtx.tScatterHash.pScatterHashParm->tCfg.tCfg.u32InputDataByteCnt =
                                pCtx->tL1AlgCtx.tScatterHash.u32ProcessedSize;
                            pCtx->tL1AlgCtx.tScatterHash.pScatterHashParm->tCfg.tCfg.pInputData =
                                (const hsm_uint8_t *)&(pCtx->tL1AlgCtx.tScatterHash.aDataBuf[0]);
                        }

                        eCurDataFmt = HSM_DATA_FORMAT_4B;
                    }
                    else /* start address 4 aligned */
                    {
                        if (0u == (pCfg->u32DataSize %
                                   HSM_HFAM_HW_PROCESS_ALIGN(pCtx->tL1AlgCtx.tScatterHash.eAlg)))
                        {
                            pCtx->tL1AlgCtx.tScatterHash.u32ProcessedSize =
                                pCfg->u32DataSize -
                                HSM_HFAM_HW_PROCESS_ALIGN(pCtx->tL1AlgCtx.tScatterHash.eAlg);
                        }
                        else
                        {
                            pCtx->tL1AlgCtx.tScatterHash.u32ProcessedSize =
                                (pCfg->u32DataSize /
                                 HSM_HFAM_HW_PROCESS_ALIGN(pCtx->tL1AlgCtx.tScatterHash.eAlg)) *
                                HSM_HFAM_HW_PROCESS_ALIGN(pCtx->tL1AlgCtx.tScatterHash.eAlg);
                        }

                        pCtx->tL1AlgCtx.tScatterHash.pScatterHashParm->tCfg.tCfg.u32InputDataByteCnt =
                            pCtx->tL1AlgCtx.tScatterHash.u32ProcessedSize;
                        pCtx->tL1AlgCtx.tScatterHash.pScatterHashParm->tCfg.tCfg.pInputData =
                            pCfg->pData;

                        eCurDataFmt = pCfg->eDataFmt;
                    }

                    if (HSM_STATUS_SUCCESS == eRet)
                    {
                        eRet = hsm_l1_scatter_hash_update(pCtx, eCurDataFmt);
                    }
                    else
                    {
                        pCtx->tL1AlgCtx.tScatterHash.eState = HSM_L1_SCATTER_HASH_STOP;
                        eRet                                = HSM_STATUS_ERROR;
                    }
                }
            }
        }
        else
        {
            eRet = HSM_STATUS_BUSY;
        }
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}

static const hsm_uint8_t aMd5[]    = { 0xd4, 0x1d, 0x8c, 0xd9, 0x8f, 0x00, 0xb2, 0x04,
                                       0xe9, 0x80, 0x09, 0x98, 0xec, 0xf8, 0x42, 0x7e };
static const hsm_uint8_t aSha160[] = { 0xda, 0x39, 0xa3, 0xee, 0x5e, 0x6b, 0x4b, 0x0d, 0x32, 0x55,
                                       0xbf, 0xef, 0x95, 0x60, 0x18, 0x90, 0xaf, 0xd8, 0x07, 0x09 };
static const hsm_uint8_t aSha224[] = { 0xd1, 0x4a, 0x02, 0x8c, 0x2a, 0x3a, 0x2b, 0xc9, 0x47, 0x61,
                                       0x02, 0xbb, 0x28, 0x82, 0x34, 0xc4, 0x15, 0xa2, 0xb0, 0x1f,
                                       0x82, 0x8e, 0xa6, 0x2a, 0xc5, 0xb3, 0xe4, 0x2f };
static const hsm_uint8_t aSha256[] = { 0xe3, 0xb0, 0xc4, 0x42, 0x98, 0xfc, 0x1c, 0x14,
                                       0x9a, 0xfb, 0xf4, 0xc8, 0x99, 0x6f, 0xb9, 0x24,
                                       0x27, 0xae, 0x41, 0xe4, 0x64, 0x9b, 0x93, 0x4c,
                                       0xa4, 0x95, 0x99, 0x1b, 0x78, 0x52, 0xb8, 0x55 };
static const hsm_uint8_t aSha384[] = { 0x38, 0xb0, 0x60, 0xa7, 0x51, 0xac, 0x96, 0x38, 0x4c, 0xd9,
                                       0x32, 0x7e, 0xb1, 0xb1, 0xe3, 0x6a, 0x21, 0xfd, 0xb7, 0x11,
                                       0x14, 0xbe, 0x7,  0x43, 0x4c, 0xc,  0xc7, 0xbf, 0x63, 0xf6,
                                       0xe1, 0xda, 0x27, 0x4e, 0xde, 0xbf, 0xe7, 0x6f, 0x65, 0xfb,
                                       0xd5, 0x1a, 0xd2, 0xf1, 0x48, 0x98, 0xb9, 0x5b };
static const hsm_uint8_t aSha512[] = {
    0xcf, 0x83, 0xe1, 0x35, 0x7e, 0xef, 0xb8, 0xbd, 0xf1, 0x54, 0x28, 0x50, 0xd6, 0x6d, 0x80, 0x7,
    0xd6, 0x20, 0xe4, 0x5,  0xb,  0x57, 0x15, 0xdc, 0x83, 0xf4, 0xa9, 0x21, 0xd3, 0x6c, 0xe9, 0xce,
    0x47, 0xd0, 0xd1, 0x3c, 0x5d, 0x85, 0xf2, 0xb0, 0xff, 0x83, 0x18, 0xd2, 0x87, 0x7e, 0xec, 0x2f,
    0x63, 0xb9, 0x31, 0xbd, 0x47, 0x41, 0x7a, 0x81, 0xa5, 0x38, 0x32, 0x7a, 0xf9, 0x27, 0xda, 0x3e
};
static const hsm_uint8_t aSha512_224[] = { 0x6e, 0xd0, 0xdd, 0x2,  0x80, 0x6f, 0xa8,
                                           0x9e, 0x25, 0xde, 0x6,  0xc,  0x19, 0xd3,
                                           0xac, 0x86, 0xca, 0xbb, 0x87, 0xd6, 0xa0,
                                           0xdd, 0xd0, 0x5c, 0x33, 0x3b, 0x84, 0xf4 };
static const hsm_uint8_t aSha512_256[] = { 0xc6, 0x72, 0xb8, 0xd1, 0xef, 0x56, 0xed, 0x28,
                                           0xab, 0x87, 0xc3, 0x62, 0x2c, 0x51, 0x14, 0x6,
                                           0x9b, 0xdd, 0x3a, 0xd7, 0xb8, 0xf9, 0x73, 0x74,
                                           0x98, 0xd0, 0xc0, 0x1e, 0xce, 0xf0, 0x96, 0x7a };
static const hsm_uint8_t aSm3[]        = { 0x1a, 0xb2, 0x1d, 0x83, 0x55, 0xcf, 0xa1, 0x7f,
                                           0x8e, 0x61, 0x19, 0x48, 0x31, 0xe8, 0x1a, 0x8f,
                                           0x22, 0xbe, 0xc8, 0xc7, 0x28, 0xfe, 0xfb, 0x74,
                                           0x7e, 0xd0, 0x35, 0xeb, 0x50, 0x82, 0xaa, 0x2b };

static const hsm_uint8_t *aHashArray[]    = { &(aMd5[0]),        &(aSha160[0]),     &(aSha224[0]),
                                              &(aSha256[0]),     &(aSha384[0]),     &(aSha512[0]),
                                              &(aSha512_224[0]), &(aSha512_256[0]), &(aSm3[0]) };
static const hsm_uint8_t  aHashDataSize[] = {
    sizeof(aMd5),    sizeof(aSha160),     sizeof(aSha224),     sizeof(aSha256), sizeof(aSha384),
    sizeof(aSha512), sizeof(aSha512_224), sizeof(aSha512_256), sizeof(aSm3)
};

HSM_StatusType hsm_aux_get_empty_data_hash(HSM_ShaAlgType      eHash,
                                           const hsm_uint8_t **ppHashData,
                                           hsm_uint32_t       *pByteCnt)
{
    HSM_StatusType eRet;

    if (eHash < (sizeof(aHashArray) / sizeof(hsm_uint8_t *)))
    {
        *ppHashData = aHashArray[eHash];
        *pByteCnt   = aHashDataSize[eHash];

        eRet = HSM_STATUS_SUCCESS;
    }
    else
    {
        eRet = HSM_STATUS_PARAM_ERR;
    }

    return eRet;
}

/* when need more data, return again, when trigger successfully, return success, others error */
HSM_StatusType HSM_L1_ScatterHashFinal(HSM_L1_RtCtxType               *pCtx,
                                       const HSM_Ln_ScatterHashType   *pCfg,
                                       const HSM_Ln_ResultBufInfoType *pResult,
                                       hsm_uint32_t                    u32TimeoutMs)
{
    HSM_StatusType        eRet      = HSM_STATUS_SUCCESS;
    HSM_ScatterHashSMType eCurState = pCtx->tL1AlgCtx.tScatterHash.eState;
    HSM_BoolType          bInProcess;
    HSM_DataFormatType    eCurDataFmt;

    bInProcess = pCtx->bInProcess;
    if ((HSM_TRUE == bInProcess) && (HSM_OP_SCATTER_HASH == pCtx->eOperationCata) &&
        ((HSM_L1_SCATTER_HASH_NEED_MORE_BEFORE_INIT == eCurState) ||
         (HSM_L1_SCATTER_HASH_INIT_OK == eCurState) ||
         (HSM_L1_SCATTER_HASH_NEED_MORE_BEFORE_UPDATE_FINAL == eCurState) ||
         (HSM_L1_SCATTER_HASH_UPDATE_OK == eCurState)))
    {
        if (HSM_DRV_SM_ARITH != pCtx->eStat)
        {
            pCtx->tL1AlgCtx.tScatterHash.u32TimeoutMs = u32TimeoutMs;

            pCtx->tL1AlgCtx.tScatterHash.pOut              = pResult->pData;
            pCtx->tL1AlgCtx.tScatterHash.u32OutBufSize     = pResult->u32DataBufSize;
            pCtx->tL1AlgCtx.tScatterHash.eOutFmt           = pResult->eDataFmt;
            pCtx->tL1AlgCtx.tScatterHash.pOutSize          = pResult->pDataSize;
            pCtx->tL1AlgCtx.tScatterHash.eState            = HSM_L1_SCATTER_HASH_FINAL;
            pCtx->tL1AlgCtx.tScatterHash.pInputData        = NULL_PTR;
            pCtx->tL1AlgCtx.tScatterHash.eInputFmt         = pCfg->eDataFmt;
            pCtx->tL1AlgCtx.tScatterHash.u32InputTotalSize = 0;
            pCtx->tL1AlgCtx.tScatterHash.u32ProcessedSize  = 0;

            if ((HSM_L1_SCATTER_HASH_NEED_MORE_BEFORE_INIT == eCurState) ||
                (HSM_L1_SCATTER_HASH_NEED_MORE_BEFORE_UPDATE_FINAL == eCurState) ||
                (((hsm_uint32_t)pCfg->pData) & 0x3)

#if (FC7XXX_HSM_SUBSYSTEM_TYPE == FC7300_HSM_SUBSYSTEM)
                || (HSM_DATA_FORMAT_1B == pCfg->eDataFmt)
#endif
            )
            {
                if ((pCtx->tL1AlgCtx.tScatterHash.u32CacheDataByteCnt + pCfg->u32DataSize) >
                    sizeof(pCtx->tL1AlgCtx.tScatterHash.aDataBuf))
                {
                    pCtx->tL1AlgCtx.tScatterHash.pInputData        = pCfg->pData;
                    pCtx->tL1AlgCtx.tScatterHash.eInputFmt         = pCfg->eDataFmt;
                    pCtx->tL1AlgCtx.tScatterHash.u32InputTotalSize = pCfg->u32DataSize;
                    pCtx->tL1AlgCtx.tScatterHash.u32ProcessedSize =
                        sizeof(pCtx->tL1AlgCtx.tScatterHash.aDataBuf) -
                        pCtx->tL1AlgCtx.tScatterHash.u32CacheDataByteCnt;

                    eRet = hsm_1B4B_convert_from_idx(HSM_DATA_FORMAT_4B,
                                                     &(pCtx->tL1AlgCtx.tScatterHash.aDataBuf[0]),
                                                     pCtx->tL1AlgCtx.tScatterHash.u32CacheDataByteCnt,
                                                     sizeof(pCtx->tL1AlgCtx.tScatterHash.aDataBuf),
                                                     pCfg->eDataFmt,
                                                     pCfg->pData,
                                                     0,
                                                     pCtx->tL1AlgCtx.tScatterHash.u32ProcessedSize);

                    pCtx->tL1AlgCtx.tScatterHash.u32CacheDataByteCnt = 0u;

                    pCtx->tL1AlgCtx.tScatterHash.pScatterHashParm->u32HSMStatusRet =
                        MAILBOXAPI_RET_NONE;
                    pCtx->tL1AlgCtx.tScatterHash.pScatterHashParm->u32Timeout = u32TimeoutMs;
                    pCtx->tL1AlgCtx.tScatterHash.pScatterHashParm->tCfg.eAlg =
                        pCtx->tL1AlgCtx.tScatterHash.eAlg;
                    pCtx->tL1AlgCtx.tScatterHash.pScatterHashParm->tCfg.tCfg.u32InputDataByteCnt =
                        sizeof(pCtx->tL1AlgCtx.tScatterHash.aDataBuf);
                    pCtx->tL1AlgCtx.tScatterHash.pScatterHashParm->tCfg.tCfg.pInputData =
                        (const hsm_uint8_t *)&(pCtx->tL1AlgCtx.tScatterHash.aDataBuf[0]);

                    eCurDataFmt = HSM_DATA_FORMAT_4B;

                    if (HSM_STATUS_SUCCESS == eRet)
                    {
                        if (HSM_L1_SCATTER_HASH_NEED_MORE_BEFORE_INIT == eCurState)
                        {
                            eRet = hsm_l1_scatter_hash_init(pCtx, eCurDataFmt);
                        }
                        else
                        {
                            eRet = hsm_l1_scatter_hash_update(pCtx, eCurDataFmt);
                        }
                    }
                    else
                    {
                        pCtx->tL1AlgCtx.tScatterHash.eState = HSM_L1_SCATTER_HASH_STOP;
                        eRet                                = HSM_STATUS_ERROR;
                    }
                }
                else if ((pCtx->tL1AlgCtx.tScatterHash.u32CacheDataByteCnt + pCfg->u32DataSize) > 0)
                {
                    eRet = hsm_1B4B_convert_from_idx(HSM_DATA_FORMAT_4B,
                                                     &(pCtx->tL1AlgCtx.tScatterHash.aDataBuf[0]),
                                                     pCtx->tL1AlgCtx.tScatterHash.u32CacheDataByteCnt,
                                                     sizeof(pCtx->tL1AlgCtx.tScatterHash.aDataBuf),
                                                     pCfg->eDataFmt,
                                                     pCfg->pData,
                                                     0,
                                                     pCfg->u32DataSize);

                    if (HSM_STATUS_SUCCESS == eRet)
                    {
                        pCtx->tL1AlgCtx.tScatterHash.u32CacheDataByteCnt += pCfg->u32DataSize;

                        if (HSM_L1_SCATTER_HASH_NEED_MORE_BEFORE_INIT == eCurState)
                        {
                            HSMCom_ShaExType *pShaParm = (HSMCom_ShaExType *)HSM_ADDRESS_UP_ALIGN(&(
                                pCtx->tL1AlgCtx.tScatterHash.tScatterHashParamShared.aShaParmBuf[0]));

                            pShaParm->u32HSMStatusRet = MAILBOXAPI_RET_NONE;
                            pShaParm->u32Timeout      = u32TimeoutMs;
                            pShaParm->tCfg.eAlg       = pCtx->tL1AlgCtx.tScatterHash.eAlg;
                            pShaParm->tCfg.tCfg.bGenerateMacEn =
                                pCtx->tL1AlgCtx.tScatterHash.tMacCfg.bGenerateMacEn;
                            pShaParm->tCfg.tCfg.eMacType =
                                pCtx->tL1AlgCtx.tScatterHash.tMacCfg.eMacType;

                            if (HSM_TRUE == (pCtx->tL1AlgCtx.tScatterHash.tMacCfg.bKeyUseId))
                            {
                                pShaParm->tCfg.tCfg.tKeyInfo.u32KeyId =
                                    pCtx->tL1AlgCtx.tScatterHash.tMacCfg.tHashMacKeyInfo.u32KeyId;
                            }
                            else
                            {
                                pShaParm->tCfg.tCfg.tKeyInfo.pKeyData =
                                    pCtx->tL1AlgCtx.tScatterHash.tMacCfg.tHashMacKeyInfo.pKeyData;
                            }

                            pShaParm->tCfg.tCfg.u32KeyByteCnt =
                                pCtx->tL1AlgCtx.tScatterHash.tMacCfg.u32KeyByteCnt;
                            pShaParm->tCfg.tCfg.u32GenerateMacByteCnt =
                                pCtx->tL1AlgCtx.tScatterHash.tMacCfg.u32GenerateMacByteCnt;
                            pShaParm->tCfg.tCfg.pInputData = (const hsm_uint8_t *)&(
                                pCtx->tL1AlgCtx.tScatterHash.aDataBuf[0]);
                            pShaParm->tCfg.tCfg.u32InputDataByteCnt =
                                pCtx->tL1AlgCtx.tScatterHash.u32CacheDataByteCnt;
                            pShaParm->tCfg.pResult = (HSM_ShaResultBufType *)HSM_ADDRESS_UP_ALIGN(&(
                                pCtx->tL1AlgCtx.tScatterHash.tScatterHashResultShared.aShaResultBuf[0]));
                            pShaParm->tCfg.eInputFmt  = HSM_DATA_FORMAT_4B;
                            pShaParm->tCfg.eOutputFmt = HSM_DATA_FORMAT_4B;

                            pCtx->tL1AlgCtx.tScatterHash.u32CacheDataByteCnt = 0;
                            eRet = hsm_l1_scatter_hash_init2final(pCtx, pShaParm);
                        }
                        else
                        {
                            pCtx->tL1AlgCtx.tScatterHash.pScatterHashParm->u32HSMStatusRet =
                                MAILBOXAPI_RET_NONE;
                            pCtx->tL1AlgCtx.tScatterHash.pScatterHashParm->u32Timeout = u32TimeoutMs;
                            pCtx->tL1AlgCtx.tScatterHash.pScatterHashParm->tCfg.eAlg =
                                pCtx->tL1AlgCtx.tScatterHash.eAlg;
                            pCtx->tL1AlgCtx.tScatterHash.pScatterHashParm->tCfg.tCfg.u32InputDataByteCnt =
                                pCtx->tL1AlgCtx.tScatterHash.u32CacheDataByteCnt;
                            pCtx->tL1AlgCtx.tScatterHash.pScatterHashParm->tCfg.tCfg.pInputData =
                                (const hsm_uint8_t *)&(pCtx->tL1AlgCtx.tScatterHash.aDataBuf[0]);

                            pCtx->tL1AlgCtx.tScatterHash.u32CacheDataByteCnt = 0u;

                            eCurDataFmt = HSM_DATA_FORMAT_4B;

                            eRet = hsm_l1_scatter_hash_final(pCtx, eCurDataFmt);
                        }
                    }
                    else
                    {
                        pCtx->tL1AlgCtx.tScatterHash.eState = HSM_L1_SCATTER_HASH_STOP;
                    }
                }
                else
                {
                    if (HSM_L1_SCATTER_HASH_NEED_MORE_BEFORE_INIT == eCurState)
                    {
                        eRet = HSM_STATUS_FINISH;

                        if (pResult->pData != NULL_PTR)
                        {
                            hsm_uint32_t       u32Size;
                            const hsm_uint8_t *pHashData;

                            eRet = hsm_aux_get_empty_data_hash(pCtx->tL1AlgCtx.tScatterHash.eAlg,
                                                               &pHashData,
                                                               &u32Size);
                            if (HSM_STATUS_SUCCESS == eRet)
                            {
                                if (pResult->u32DataBufSize > u32Size)
                                {
                                    hsm_1B4B_convert_from_idx(pResult->eDataFmt,
                                                              pResult->pData,
                                                              0,
                                                              pResult->u32DataBufSize,
                                                              HSM_DATA_FORMAT_1B,
                                                              pHashData,
                                                              0,
                                                              u32Size);
                                }
                                else
                                {
                                    u32Size = pResult->u32DataBufSize;

                                    hsm_1B4B_convert_from_idx(pResult->eDataFmt,
                                                              pResult->pData,
                                                              0,
                                                              pResult->u32DataBufSize,
                                                              HSM_DATA_FORMAT_1B,
                                                              pHashData,
                                                              0,
                                                              pResult->u32DataBufSize);
                                }

                                if (pResult->pDataSize != NULL_PTR)
                                {
                                    hsm_memcpy(pResult->pDataSize, &u32Size, sizeof(u32Size));
                                }
                                /* else do nothing */
                            }
                            /* else do nothing */
                        }
                    }
                    else
                    {
                        eRet = HSM_STATUS_ERROR_STOP;
                    }

                    pCtx->tL1AlgCtx.tScatterHash.eState = HSM_L1_SCATTER_HASH_STOP;
                }
            }
            else /* init ok/update ok, 4B, input address 4bytes aligned */
            {
                pCtx->tL1AlgCtx.tScatterHash.pScatterHashParm->u32HSMStatusRet = MAILBOXAPI_RET_NONE;
                pCtx->tL1AlgCtx.tScatterHash.pScatterHashParm->u32Timeout = u32TimeoutMs;
                pCtx->tL1AlgCtx.tScatterHash.pScatterHashParm->tCfg.eAlg =
                    pCtx->tL1AlgCtx.tScatterHash.eAlg;
                pCtx->tL1AlgCtx.tScatterHash.pScatterHashParm->tCfg.tCfg.u32InputDataByteCnt =
                    pCfg->u32DataSize;
                pCtx->tL1AlgCtx.tScatterHash.pScatterHashParm->tCfg.tCfg.pInputData =
                    (const hsm_uint8_t *)pCfg->pData;

                pCtx->tL1AlgCtx.tScatterHash.u32CacheDataByteCnt = 0u;

                eCurDataFmt = pCfg->eDataFmt;

                eRet = hsm_l1_scatter_hash_final(pCtx, eCurDataFmt);
            }
        }
        else
        {
            eRet = HSM_STATUS_BUSY;
        }
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}

/* get result return success, trigger next process return again, others error */
HSM_StatusType HSM_L1_ScatterHash_Isr(HSM_L1_RtCtxType *pCtx)
{
    HSM_StatusType        eRet      = HSM_STATUS_SUCCESS;
    HSM_ScatterHashSMType eCurState = pCtx->tL1AlgCtx.tScatterHash.eState;
    hsm_uint32_t          u32Temp;
    HSM_DataFormatType    eCurDataFmt;

    if (MAILBOXAPI_RET_SUCCESS == pCtx->tL1AlgCtx.tScatterHash.pScatterHashParm->u32HSMStatusRet)
    {
        pCtx->tL1AlgCtx.tScatterHash.u32CacheDataByteCnt = 0;

        if ((HSM_L1_SCATTER_HASH_INIT == eCurState) || (HSM_L1_SCATTER_HASH_UPDATE == eCurState))
        {
            if (pCtx->tL1AlgCtx.tScatterHash.u32InputTotalSize <=
                pCtx->tL1AlgCtx.tScatterHash.u32ProcessedSize)
            {
                if (HSM_L1_SCATTER_HASH_INIT == eCurState)
                {
                    pCtx->tL1AlgCtx.tScatterHash.eState = HSM_L1_SCATTER_HASH_INIT_OK;
                }
                else
                {
                    pCtx->tL1AlgCtx.tScatterHash.eState = HSM_L1_SCATTER_HASH_UPDATE_OK;
                }

                pCtx->eStat                                    = HSM_DRV_SM_STOP;
                pCtx->tL1AlgCtx.tScatterHash.pInputData        = NULL_PTR;
                pCtx->tL1AlgCtx.tScatterHash.eInputFmt         = HSM_DATA_FORMAT_4B;
                pCtx->tL1AlgCtx.tScatterHash.u32InputTotalSize = 0;
                pCtx->tL1AlgCtx.tScatterHash.u32ProcessedSize  = 0;
            }
            else
            {
                u32Temp = pCtx->tL1AlgCtx.tScatterHash.u32InputTotalSize -
                          pCtx->tL1AlgCtx.tScatterHash.u32ProcessedSize;

                if (u32Temp <= HSM_HFAM_HW_PROCESS_ALIGN(pCtx->tL1AlgCtx.tScatterHash.eAlg))
                {
                    pCtx->eStat = HSM_DRV_SM_STOP;

                    eRet = hsm_1B4B_convert_from_idx(HSM_DATA_FORMAT_4B,
                                                     &(pCtx->tL1AlgCtx.tScatterHash.aDataBuf[0]),
                                                     0,
                                                     sizeof(pCtx->tL1AlgCtx.tScatterHash.aDataBuf),
                                                     pCtx->tL1AlgCtx.tScatterHash.eInputFmt,
                                                     pCtx->tL1AlgCtx.tScatterHash.pInputData,
                                                     pCtx->tL1AlgCtx.tScatterHash.u32ProcessedSize,
                                                     pCtx->tL1AlgCtx.tScatterHash.u32InputTotalSize);

                    pCtx->tL1AlgCtx.tScatterHash.pInputData        = NULL_PTR;
                    pCtx->tL1AlgCtx.tScatterHash.eInputFmt         = HSM_DATA_FORMAT_4B;
                    pCtx->tL1AlgCtx.tScatterHash.u32InputTotalSize = 0;
                    pCtx->tL1AlgCtx.tScatterHash.u32ProcessedSize  = 0;

                    if (HSM_STATUS_SUCCESS == eRet)
                    {
                        pCtx->tL1AlgCtx.tScatterHash.eState =
                            HSM_L1_SCATTER_HASH_NEED_MORE_BEFORE_UPDATE_FINAL;
                        pCtx->tL1AlgCtx.tScatterHash.u32CacheDataByteCnt = u32Temp;
                    }
                    else
                    {
                        pCtx->tL1AlgCtx.tScatterHash.eState = HSM_L1_SCATTER_HASH_STOP;
                    }
                }
                else /* data is enough for once at least */
                {
                    pCtx->tL1AlgCtx.tScatterHash.pScatterHashParm->u32HSMStatusRet =
                        MAILBOXAPI_RET_NONE;
                    pCtx->tL1AlgCtx.tScatterHash.pScatterHashParm->u32Timeout =
                        pCtx->tL1AlgCtx.tScatterHash.u32TimeoutMs;
                    pCtx->tL1AlgCtx.tScatterHash.pScatterHashParm->tCfg.eAlg =
                        pCtx->tL1AlgCtx.tScatterHash.eAlg;

                    if (
#if (FC7XXX_HSM_SUBSYSTEM_TYPE == FC7300_HSM_SUBSYSTEM)
                        (HSM_DATA_FORMAT_1B == pCtx->tL1AlgCtx.tScatterHash.eInputFmt) ||
#endif
                        (((hsm_uint32_t)pCtx->tL1AlgCtx.tScatterHash.pInputData) & 0x3) ||
                        (pCtx->tL1AlgCtx.tScatterHash.u32ProcessedSize & 0x3))
                    {
                        if (u32Temp > sizeof(pCtx->tL1AlgCtx.tScatterHash.aDataBuf))
                        {
                            u32Temp = sizeof(pCtx->tL1AlgCtx.tScatterHash.aDataBuf);
                        }
                        else
                        {
                            if (0u == (u32Temp %
                                       HSM_HFAM_HW_PROCESS_ALIGN(pCtx->tL1AlgCtx.tScatterHash.eAlg)))
                            {
                                u32Temp = (u32Temp - HSM_HFAM_HW_PROCESS_ALIGN(
                                                         pCtx->tL1AlgCtx.tScatterHash.eAlg));
                            }
                            else
                            {
                                u32Temp =
                                    ((u32Temp /
                                      HSM_HFAM_HW_PROCESS_ALIGN(pCtx->tL1AlgCtx.tScatterHash.eAlg)) *
                                     HSM_HFAM_HW_PROCESS_ALIGN(pCtx->tL1AlgCtx.tScatterHash.eAlg));
                            }
                        }

                        eRet = hsm_1B4B_convert_from_idx(
                            HSM_DATA_FORMAT_4B,
                            &(pCtx->tL1AlgCtx.tScatterHash.aDataBuf[0]),
                            0,
                            sizeof(pCtx->tL1AlgCtx.tScatterHash.aDataBuf),
                            pCtx->tL1AlgCtx.tScatterHash.eInputFmt,
                            pCtx->tL1AlgCtx.tScatterHash.pInputData,
                            pCtx->tL1AlgCtx.tScatterHash.u32ProcessedSize,
                            pCtx->tL1AlgCtx.tScatterHash.u32ProcessedSize + u32Temp);

                        if (HSM_STATUS_SUCCESS == eRet)
                        {
                            pCtx->tL1AlgCtx.tScatterHash.pScatterHashParm->tCfg.tCfg.u32InputDataByteCnt =
                                u32Temp;
                            pCtx->tL1AlgCtx.tScatterHash.pScatterHashParm->tCfg.tCfg.pInputData =
                                (const hsm_uint8_t *)&(pCtx->tL1AlgCtx.tScatterHash.aDataBuf[0]);
                        }

                        pCtx->tL1AlgCtx.tScatterHash.u32ProcessedSize += u32Temp;

                        eCurDataFmt = HSM_DATA_FORMAT_4B;
                    }
                    else /* start address 4 aligned */
                    {
                        if (0u ==
                            (u32Temp % HSM_HFAM_HW_PROCESS_ALIGN(pCtx->tL1AlgCtx.tScatterHash.eAlg)))
                        {
                            u32Temp = u32Temp -
                                      HSM_HFAM_HW_PROCESS_ALIGN(pCtx->tL1AlgCtx.tScatterHash.eAlg);
                        }
                        else
                        {
                            u32Temp = (u32Temp /
                                       HSM_HFAM_HW_PROCESS_ALIGN(pCtx->tL1AlgCtx.tScatterHash.eAlg)) *
                                      HSM_HFAM_HW_PROCESS_ALIGN(pCtx->tL1AlgCtx.tScatterHash.eAlg);
                        }

                        pCtx->tL1AlgCtx.tScatterHash.pScatterHashParm->tCfg.tCfg.u32InputDataByteCnt =
                            u32Temp;
                        pCtx->tL1AlgCtx.tScatterHash.pScatterHashParm->tCfg.tCfg.pInputData =
                            pCtx->tL1AlgCtx.tScatterHash.pInputData +
                            pCtx->tL1AlgCtx.tScatterHash.u32ProcessedSize;

                        pCtx->tL1AlgCtx.tScatterHash.u32ProcessedSize += u32Temp;

                        eCurDataFmt = pCtx->tL1AlgCtx.tScatterHash.eInputFmt;
                    }

                    if (HSM_STATUS_SUCCESS == eRet)
                    {
                        eRet = hsm_l1_scatter_hash_update(pCtx, eCurDataFmt);
                        if (HSM_STATUS_SUCCESS == eRet)
                        {
                            eRet = HSM_STATUS_AGAIN;
                        }
                        /* else do nothing */
                    }
                    else
                    {
                        pCtx->tL1AlgCtx.tScatterHash.eState = HSM_L1_SCATTER_HASH_STOP;
                        eRet                                = HSM_STATUS_ERROR;
                    }
                    /* else do nothing */
                }
            }
        }
        else if (HSM_L1_SCATTER_HASH_FINAL == eCurState)
        {
            pCtx->eStat = HSM_DRV_SM_STOP;

            if (pCtx->tL1AlgCtx.tScatterHash.u32InputTotalSize <=
                pCtx->tL1AlgCtx.tScatterHash.u32ProcessedSize)
            {
                pCtx->tL1AlgCtx.tScatterHash.eState = HSM_L1_SCATTER_HASH_STOP;

                if ((pCtx->tL1AlgCtx.tScatterHash.pOut != NULL_PTR))
                {
                    eRet = hsm_hash_get_result_byte_count(
                        (HFAM_MODE_E)pCtx->tL1AlgCtx.tScatterHash.eAlg,
                        &u32Temp);
                    if (HSM_STATUS_SUCCESS == eRet)
                    {
                        if (HSM_DATA_FORMAT_1B == pCtx->tL1AlgCtx.tScatterHash.eOutFmt)
                        {
                            hsm_u32_array_swap((hsm_uint32_t *)(pCtx->tL1AlgCtx.tScatterHash
                                                                    .pScatterHashParm->tCfg.pResult),
                                               u32Temp / 4U); /* all result data size is 4*N */
                        }
                        else
                        {
                        }

                        if (pCtx->tL1AlgCtx.tScatterHash.u32OutBufSize <= u32Temp)
                        {
                            u32Temp = pCtx->tL1AlgCtx.tScatterHash.u32OutBufSize;
                        }
                        /* else do nothing */

                        hsm_memcpy(pCtx->tL1AlgCtx.tScatterHash.pOut,
                                   pCtx->tL1AlgCtx.tScatterHash.pScatterHashParm->tCfg.pResult,
                                   u32Temp);

                        if (NULL_PTR != pCtx->tL1AlgCtx.tScatterHash.pOutSize)
                        {
                            hsm_memcpy(pCtx->tL1AlgCtx.tScatterHash.pOutSize,
                                       &u32Temp,
                                       sizeof(u32Temp));
                        }
                        else
                        {
                            ;
                        }
                    }
                    else
                    {
                        eRet = HSM_STATUS_HW_ERR;
                    }
                }
                /* else do nothing */

                pCtx->tL1AlgCtx.tScatterHash.pOut              = NULL_PTR;
                pCtx->tL1AlgCtx.tScatterHash.u32OutBufSize     = 0;
                pCtx->tL1AlgCtx.tScatterHash.eOutFmt           = HSM_DATA_FORMAT_4B;
                pCtx->tL1AlgCtx.tScatterHash.pOutSize          = NULL_PTR;
                pCtx->tL1AlgCtx.tScatterHash.pInputData        = NULL_PTR;
                pCtx->tL1AlgCtx.tScatterHash.eInputFmt         = HSM_DATA_FORMAT_4B;
                pCtx->tL1AlgCtx.tScatterHash.u32InputTotalSize = 0;
                pCtx->tL1AlgCtx.tScatterHash.u32ProcessedSize  = 0;
            }
            else
            {
                u32Temp = pCtx->tL1AlgCtx.tScatterHash.u32InputTotalSize -
                          pCtx->tL1AlgCtx.tScatterHash.u32ProcessedSize;

                if (u32Temp <= HSM_HFAM_HW_PROCESS_ALIGN(pCtx->tL1AlgCtx.tScatterHash.eAlg))
                {
                    eRet = hsm_1B4B_convert_from_idx(HSM_DATA_FORMAT_4B,
                                                     &(pCtx->tL1AlgCtx.tScatterHash.aDataBuf[0]),
                                                     0,
                                                     sizeof(pCtx->tL1AlgCtx.tScatterHash.aDataBuf),
                                                     pCtx->tL1AlgCtx.tScatterHash.eInputFmt,
                                                     pCtx->tL1AlgCtx.tScatterHash.pInputData,
                                                     pCtx->tL1AlgCtx.tScatterHash.u32ProcessedSize,
                                                     pCtx->tL1AlgCtx.tScatterHash.u32InputTotalSize);

                    pCtx->tL1AlgCtx.tScatterHash.u32ProcessedSize += u32Temp;

                    if (HSM_STATUS_SUCCESS == eRet)
                    {
                        pCtx->tL1AlgCtx.tScatterHash.pScatterHashParm->u32HSMStatusRet =
                            MAILBOXAPI_RET_NONE;
                        pCtx->tL1AlgCtx.tScatterHash.pScatterHashParm->u32Timeout =
                            pCtx->tL1AlgCtx.tScatterHash.u32TimeoutMs;
                        pCtx->tL1AlgCtx.tScatterHash.pScatterHashParm->tCfg.eAlg =
                            pCtx->tL1AlgCtx.tScatterHash.eAlg;
                        pCtx->tL1AlgCtx.tScatterHash.pScatterHashParm->tCfg.tCfg.u32InputDataByteCnt =
                            u32Temp;
                        pCtx->tL1AlgCtx.tScatterHash.pScatterHashParm->tCfg.tCfg.pInputData =
                            (const hsm_uint8_t *)&(pCtx->tL1AlgCtx.tScatterHash.aDataBuf[0]);

                        eCurDataFmt = HSM_DATA_FORMAT_4B;

                        eRet = hsm_l1_scatter_hash_final(pCtx, eCurDataFmt);
                        if (HSM_STATUS_SUCCESS == eRet)
                        {
                            eRet = HSM_STATUS_AGAIN;
                        }
                        /* else do nothing */
                    }
                    else
                    {
                        pCtx->tL1AlgCtx.tScatterHash.eState = HSM_L1_SCATTER_HASH_STOP;
                    }
                }
                else /* data is enough for once at least */
                {
                    pCtx->tL1AlgCtx.tScatterHash.pScatterHashParm->u32HSMStatusRet =
                        MAILBOXAPI_RET_NONE;
                    pCtx->tL1AlgCtx.tScatterHash.pScatterHashParm->u32Timeout =
                        pCtx->tL1AlgCtx.tScatterHash.u32TimeoutMs;
                    pCtx->tL1AlgCtx.tScatterHash.pScatterHashParm->tCfg.eAlg =
                        pCtx->tL1AlgCtx.tScatterHash.eAlg;

                    if (
#if (FC7XXX_HSM_SUBSYSTEM_TYPE == FC7300_HSM_SUBSYSTEM)
                        (HSM_DATA_FORMAT_1B == pCtx->tL1AlgCtx.tScatterHash.eInputFmt) ||
#endif
                        (((hsm_uint32_t)pCtx->tL1AlgCtx.tScatterHash.pInputData) & 0x3) ||
                        (pCtx->tL1AlgCtx.tScatterHash.u32ProcessedSize & 0x3))
                    {
                        if (u32Temp > sizeof(pCtx->tL1AlgCtx.tScatterHash.aDataBuf))
                        {
                            u32Temp = sizeof(pCtx->tL1AlgCtx.tScatterHash.aDataBuf);
                        }
                        else
                        {
                            if (0u == (u32Temp %
                                       HSM_HFAM_HW_PROCESS_ALIGN(pCtx->tL1AlgCtx.tScatterHash.eAlg)))
                            {
                                u32Temp = (u32Temp - HSM_HFAM_HW_PROCESS_ALIGN(
                                                         pCtx->tL1AlgCtx.tScatterHash.eAlg));
                            }
                            else
                            {
                                u32Temp =
                                    ((u32Temp /
                                      HSM_HFAM_HW_PROCESS_ALIGN(pCtx->tL1AlgCtx.tScatterHash.eAlg)) *
                                     HSM_HFAM_HW_PROCESS_ALIGN(pCtx->tL1AlgCtx.tScatterHash.eAlg));
                            }
                        }

                        eRet = hsm_1B4B_convert_from_idx(
                            HSM_DATA_FORMAT_4B,
                            &(pCtx->tL1AlgCtx.tScatterHash.aDataBuf[0]),
                            0,
                            sizeof(pCtx->tL1AlgCtx.tScatterHash.aDataBuf),
                            pCtx->tL1AlgCtx.tScatterHash.eInputFmt,
                            pCtx->tL1AlgCtx.tScatterHash.pInputData,
                            pCtx->tL1AlgCtx.tScatterHash.u32ProcessedSize,
                            pCtx->tL1AlgCtx.tScatterHash.u32ProcessedSize + u32Temp);

                        if (HSM_STATUS_SUCCESS == eRet)
                        {
                            pCtx->tL1AlgCtx.tScatterHash.pScatterHashParm->tCfg.tCfg.u32InputDataByteCnt =
                                u32Temp;
                            pCtx->tL1AlgCtx.tScatterHash.pScatterHashParm->tCfg.tCfg.pInputData =
                                (const hsm_uint8_t *)&(pCtx->tL1AlgCtx.tScatterHash.aDataBuf[0]);
                        }

                        pCtx->tL1AlgCtx.tScatterHash.u32ProcessedSize += u32Temp;

                        eCurDataFmt = HSM_DATA_FORMAT_4B;

                        if (HSM_STATUS_SUCCESS == eRet)
                        {
                            eRet = hsm_l1_scatter_hash_update(pCtx, eCurDataFmt);
                            if (HSM_STATUS_SUCCESS == eRet)
                            {
                                eRet = HSM_STATUS_AGAIN;
                            }
                            /* else do nothing */
                        }
                        else
                        {
                            pCtx->tL1AlgCtx.tScatterHash.eState = HSM_L1_SCATTER_HASH_STOP;
                            eRet                                = HSM_STATUS_ERROR;
                        }
                    }
                    else /* start address 4 aligned */
                    {
                        pCtx->tL1AlgCtx.tScatterHash.pScatterHashParm->tCfg.tCfg.u32InputDataByteCnt =
                            u32Temp;
                        pCtx->tL1AlgCtx.tScatterHash.pScatterHashParm->tCfg.tCfg.pInputData =
                            pCtx->tL1AlgCtx.tScatterHash.pInputData +
                            pCtx->tL1AlgCtx.tScatterHash.u32ProcessedSize;

                        pCtx->tL1AlgCtx.tScatterHash.u32ProcessedSize += u32Temp;

                        eCurDataFmt = pCtx->tL1AlgCtx.tScatterHash.eInputFmt;

                        if (HSM_STATUS_SUCCESS == eRet)
                        {
                            eRet = hsm_l1_scatter_hash_final(pCtx, eCurDataFmt);
                            if (HSM_STATUS_SUCCESS == eRet)
                            {
                                eRet = HSM_STATUS_AGAIN;
                            }
                            /* else do nothing */
                        }
                        else
                        {
                            pCtx->tL1AlgCtx.tScatterHash.eState = HSM_L1_SCATTER_HASH_STOP;
                            eRet                                = HSM_STATUS_ERROR;
                        }
                    }
                }
            }
        }
        else
        {
            eRet                                = HSM_STATUS_LOGIC_ERR;
            pCtx->tL1AlgCtx.tScatterHash.eState = HSM_L1_SCATTER_HASH_STOP;
            pCtx->eStat                         = HSM_DRV_SM_STOP;
        }
    }
    else
    {
        eRet                                = HSM_STATUS_HW_ERR;
        pCtx->tL1AlgCtx.tScatterHash.eState = HSM_L1_SCATTER_HASH_STOP;
        pCtx->eStat                         = HSM_DRV_SM_STOP;
    }

    return eRet;
}

HSM_StatusType HSM_L1_ScatterHashPoll(HSM_L1_RtCtxType *pCtx)
{
    HSM_StatusType eRet       = HSM_STATUS_SUCCESS;
    HSM_BoolType   bInProcess = HSM_FALSE;

    bInProcess = pCtx->bInProcess;

    if ((HSM_TRUE == bInProcess) && (HSM_OP_SCATTER_HASH == pCtx->eOperationCata))
    {
        if (HSM_DRV_SM_ARITH == pCtx->eStat)
        {
            eRet = pCtx->pReadAckCb();
            if (HSM_STATUS_BUSY == eRet)
            {
                eRet = HSM_STATUS_AGAIN;
            }
            else if (HSM_STATUS_SUCCESS == eRet)
            {
                eRet = HSM_L1_ScatterHash_Isr(pCtx);
            }
            else
            {
                pCtx->eStat = HSM_DRV_SM_STOP;
            }
        }
        else
        {
            eRet = HSM_STATUS_HW_IDLE;
        }
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_ScatterHashExitEnv(HSM_L1_RtCtxType *pCtx)
{
    HSM_BoolType   bInProcess = pCtx->bInProcess;
    HSM_StatusType eRet       = HSM_STATUS_SUCCESS;

    if ((HSM_TRUE == bInProcess) && (HSM_OP_SCATTER_HASH == pCtx->eOperationCata))
    {
        eRet = HSM_L1_CommonExitEnv(pCtx);
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_ScatterCMacSetupEnv(HSM_L1_RtCtxType *pCtx)
{
    HSM_BoolType   bInProcess;
    HSM_StatusType eRet;

    bInProcess = pCtx->bInProcess;
    if (HSM_FALSE == bInProcess)
    {
        pCtx->bInProcess     = HSM_TRUE;
        pCtx->eOperationCata = HSM_OP_SCATTER_CMAC;
        pCtx->eStat          = HSM_DRV_SM_READY;

        hsm_memset(&(pCtx->tL1AlgCtx.tScatterCMac), 0, sizeof(pCtx->tL1AlgCtx.tScatterCMac));

        pCtx->tL1AlgCtx.tScatterCMac.eState = HSM_L1_SCATTER_CMAC_READY;

        pCtx->tL1AlgCtx.tScatterCMac.pOut       = NULL_PTR;
        pCtx->tL1AlgCtx.tScatterCMac.pOutSize   = NULL_PTR;
        pCtx->tL1AlgCtx.tScatterCMac.pInputData = NULL_PTR;

        pCtx->tL1AlgCtx.tScatterCMac.pScatterCMacParm = (HSMCom_AesmRawApiType *)HSM_ADDRESS_UP_ALIGN(
            &(pCtx->tL1AlgCtx.tScatterCMac.tScatterCMacParamShared.aScatterCMacParmBuf[0]));
        pCtx->tL1AlgCtx.tScatterCMac.pScatterCMacParm->tCfg.pCtx1 = &(
            pCtx->tL1AlgCtx.tScatterCMac.tScatterCMacResultShared.aCMacCtx);
        pCtx->tL1AlgCtx.tScatterCMac.pScatterCMacParm->tCfg.tCfg.key_cfg = &(
            pCtx->tL1AlgCtx.tScatterCMac.pScatterCMacParm->tCfg.tKeyCfg);
        pCtx->tL1AlgCtx.tScatterCMac.pScatterCMacParm->tCfg.tKeyCfg.key_addr = &(
            pCtx->tL1AlgCtx.tScatterCMac.aKeyData[0]);

        pCtx->tL1AlgCtx.tScatterCMac.pScatterCMacParm->tCfg.tCfg.key_cfg_en = 0x1; /* key enable */
        pCtx->tL1AlgCtx.tScatterCMac.pScatterCMacParm->tCfg.tCfg.aes_mode   = 0x6; /* cmac */
        pCtx->tL1AlgCtx.tScatterCMac.pScatterCMacParm->tCfg.tCfg.enc_dec    = 0x1; /* encrypt */

        pCtx->tL1AlgCtx.tScatterCMac.pScatterCMacParm->tCfg.tCfg.mst_en = 0x1; /* ahb enable */
        pCtx->tL1AlgCtx.tScatterCMac.pScatterCMacParm->tCfg.tCfg.icv_en = 0x0; /* not check result */
        pCtx->tL1AlgCtx.tScatterCMac.pScatterCMacParm->tCfg.tCfg.icv_len =
            0x10; /* cmac result length */
        pCtx->tL1AlgCtx.tScatterCMac.pScatterCMacParm->tCfg.tCfg.aad_len = 0x0; /* not check result */
        pCtx->tL1AlgCtx.tScatterCMac.pScatterCMacParm->tCfg.tCfg.out_addr = &(
            pCtx->tL1AlgCtx.tScatterCMac.tScatterCMacParamShared.aCMacParmBuf[0]);
        pCtx->tL1AlgCtx.tScatterCMac.pScatterCMacParm->tCfg.tCfg.iv_addr  = NULL_PTR;
        pCtx->tL1AlgCtx.tScatterCMac.pScatterCMacParm->tCfg.tCfg.dbg_wait = 0x0;
        pCtx->tL1AlgCtx.tScatterCMac.pScatterCMacParm->tCfg.tCfg.iv_len   = 0x0;

        eRet = HSM_STATUS_SUCCESS;
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}

static HSM_StatusType hsm_l1_scatter_cmac_init(HSM_L1_RtCtxType  *pCtx,
                                               HSM_DataFormatType eInputFmt,
                                               HSM_DataFormatType eKeyFmt)
{
    HSM_StatusType eRet = HSM_FW_ScatterCMacInit(&(pCtx->tCmd),
                                                 pCtx->tL1AlgCtx.tScatterCMac.pScatterCMacParm,
                                                 eInputFmt,
                                                 eKeyFmt);
    if (HSM_STATUS_SUCCESS == eRet)
    {
        pCtx->tL1AlgCtx.tScatterCMac.pScatterCMacParm->tCfg.tCfg.aes_as = 0x1; /* init */

        pCtx->eStat = HSM_DRV_SM_ARITH;
        eRet        = pCtx->pSendCmdCb(&(pCtx->tCmd));
        if (HSM_STATUS_SUCCESS != eRet)
        {
            pCtx->eStat                         = HSM_DRV_SM_STOP;
            pCtx->tL1AlgCtx.tScatterCMac.eState = HSM_L1_SCATTER_CMAC_STOP;
            eRet                                = HSM_STATUS_ERROR;
        }
    }
    else
    {
        pCtx->tL1AlgCtx.tScatterCMac.eState = HSM_L1_SCATTER_CMAC_STOP;
        eRet                                = HSM_STATUS_ERROR;
    }

    return eRet;
}

static HSM_StatusType hsm_l1_scatter_cmac_update(HSM_L1_RtCtxType  *pCtx,
                                                 HSM_DataFormatType eInputFmt,
                                                 HSM_DataFormatType eKeyFmt)
{
    HSM_StatusType eRet = HSM_FW_ScatterCMacUpdate(&(pCtx->tCmd),
                                                   pCtx->tL1AlgCtx.tScatterCMac.pScatterCMacParm,
                                                   eInputFmt,
                                                   eKeyFmt);
    if (HSM_STATUS_SUCCESS == eRet)
    {
        pCtx->tL1AlgCtx.tScatterCMac.pScatterCMacParm->tCfg.tCfg.aes_as = 0x0; /* update */

        pCtx->eStat = HSM_DRV_SM_ARITH;
        eRet        = pCtx->pSendCmdCb(&(pCtx->tCmd));
        if (HSM_STATUS_SUCCESS != eRet)
        {
            pCtx->eStat                         = HSM_DRV_SM_STOP;
            pCtx->tL1AlgCtx.tScatterCMac.eState = HSM_L1_SCATTER_CMAC_STOP;
            eRet                                = HSM_STATUS_ERROR;
        }
    }
    else
    {
        pCtx->tL1AlgCtx.tScatterCMac.eState = HSM_L1_SCATTER_CMAC_STOP;
        eRet                                = HSM_STATUS_ERROR;
    }

    return eRet;
}

static HSM_StatusType hsm_l1_scatter_cmac_final(HSM_L1_RtCtxType  *pCtx,
                                                HSM_DataFormatType eInputFmt,
                                                HSM_DataFormatType eKeyFmt)
{
    HSM_StatusType eRet = HSM_FW_ScatterCMacFinal(&(pCtx->tCmd),
                                                  pCtx->tL1AlgCtx.tScatterCMac.pScatterCMacParm,
                                                  eInputFmt,
                                                  eKeyFmt);
    if (HSM_STATUS_SUCCESS == eRet)
    {
        pCtx->tL1AlgCtx.tScatterCMac.pScatterCMacParm->tCfg.tCfg.aes_as = 0x2; /* final */

        pCtx->eStat = HSM_DRV_SM_ARITH;
        eRet        = pCtx->pSendCmdCb(&(pCtx->tCmd));
        if (HSM_STATUS_SUCCESS != eRet)
        {
            pCtx->eStat                         = HSM_DRV_SM_STOP;
            pCtx->tL1AlgCtx.tScatterCMac.eState = HSM_L1_SCATTER_CMAC_STOP;
            eRet                                = HSM_STATUS_ERROR;
        }
    }
    else
    {
        pCtx->tL1AlgCtx.tScatterCMac.eState = HSM_L1_SCATTER_CMAC_STOP;
        eRet                                = HSM_STATUS_ERROR;
    }

    return eRet;
}

static HSM_StatusType hsm_l1_scatter_cmac_init2final(HSM_L1_RtCtxType *pCtx, HSMCom_CMacExType *pParm)
{
    HSM_StatusType eRet = HSM_CMacEx(&(pCtx->tCmd), pParm);

    if (HSM_STATUS_SUCCESS == eRet)
    {
        pCtx->eStat = HSM_DRV_SM_ARITH;
        eRet        = pCtx->pSendCmdCb(&(pCtx->tCmd));
        if (HSM_STATUS_SUCCESS != eRet)
        {
            pCtx->eStat                         = HSM_DRV_SM_STOP;
            pCtx->tL1AlgCtx.tScatterCMac.eState = HSM_L1_SCATTER_CMAC_STOP;
            eRet                                = HSM_STATUS_ERROR;
        }
    }
    else
    {
        pCtx->tL1AlgCtx.tScatterCMac.eState = HSM_L1_SCATTER_CMAC_STOP;
        eRet                                = HSM_STATUS_ERROR;
    }

    return eRet;
}

/* when need more data, return again, when trigger successfully, return success, others error */
HSM_StatusType HSM_L1_ScatterCMacInit(HSM_L1_RtCtxType              *pCtx,
                                      const HSM_Ln_CMacCfgParmsType *pKeyCfg,
                                      const HSM_Ln_ScatterCMacType  *pCfg,
                                      hsm_uint32_t                   u32TimeoutMs)
{
    HSM_StatusType     eRet = HSM_STATUS_SUCCESS;
    HSM_BoolType       bInProcess;
    hsm_uint32_t       u32Temp = (pKeyCfg->eKeyType * 8) + 16;
    HSM_DataFormatType eCurDataFmt;

    bInProcess = pCtx->bInProcess;
    if ((HSM_TRUE == bInProcess) && (HSM_OP_SCATTER_CMAC == pCtx->eOperationCata) &&
        (HSM_L1_SCATTER_CMAC_READY == pCtx->tL1AlgCtx.tScatterCMac.eState))
    {
        if (HSM_DRV_SM_ARITH != pCtx->eStat)
        {
            pCtx->tL1AlgCtx.tScatterCMac.u32TimeoutMs        = u32TimeoutMs;
            pCtx->tL1AlgCtx.tScatterCMac.pOut                = NULL_PTR;
            pCtx->tL1AlgCtx.tScatterCMac.u32OutBufSize       = 0;
            pCtx->tL1AlgCtx.tScatterCMac.eOutFmt             = HSM_DATA_FORMAT_4B;
            pCtx->tL1AlgCtx.tScatterCMac.pOutSize            = NULL_PTR;
            pCtx->tL1AlgCtx.tScatterCMac.pInputData          = NULL_PTR;
            pCtx->tL1AlgCtx.tScatterCMac.eInputFmt           = HSM_DATA_FORMAT_4B;
            pCtx->tL1AlgCtx.tScatterCMac.u32InputTotalSize   = 0;
            pCtx->tL1AlgCtx.tScatterCMac.u32ProcessedSize    = 0;
            pCtx->tL1AlgCtx.tScatterCMac.u32CacheDataByteCnt = 0;
            pCtx->tL1AlgCtx.tScatterCMac.u32CacheProcByteCnt = 0;
            pCtx->tL1AlgCtx.tScatterCMac.eUseKeyType         = pKeyCfg->eUseKeyType;
            pCtx->tL1AlgCtx.tScatterCMac.u32KeyId            = pKeyCfg->u32KeyId;
            pCtx->tL1AlgCtx.tScatterCMac.eKeyType            = pKeyCfg->eKeyType;

            pCtx->tL1AlgCtx.tScatterCMac.eBackend = pKeyCfg->eBackend;

            pCtx->tL1AlgCtx.tScatterCMac.pScatterCMacParm->u32UserKeyID =
                pCtx->tL1AlgCtx.tScatterCMac.u32KeyId;
            pCtx->tL1AlgCtx.tScatterCMac.pScatterCMacParm->tCfg.tKeyCfg.key_type =
                pCtx->tL1AlgCtx.tScatterCMac.eKeyType; /* normal key */
            pCtx->tL1AlgCtx.tScatterCMac.pScatterCMacParm->tCfg.tKeyCfg.key_sel =
                0x1 - (pCtx->tL1AlgCtx.tScatterCMac.eUseKeyType & 0x1); /* normal key */
            pCtx->tL1AlgCtx.tScatterCMac.pScatterCMacParm->tCfg.tCfg.eng_sel =
                pKeyCfg->eBackend; /* aes-cmac */

            if ((HSM_AES_KEY_NEW == pKeyCfg->eUseKeyType))
            {
                if (0 == pCtx->tL1AlgCtx.tScatterCMac.u32KeyId)
                {
                    if (u32Temp <= sizeof(pCtx->tL1AlgCtx.tScatterCMac.aKeyData))
                    {
                        eRet = hsm_1B4B_convert_from_idx(HSM_DATA_FORMAT_1B,
                                                         &(pCtx->tL1AlgCtx.tScatterCMac.aKeyData[0]),
                                                         0,
                                                         sizeof(pCtx->tL1AlgCtx.tScatterCMac.aKeyData),
                                                         pKeyCfg->eKeyDataFmt,
                                                         pKeyCfg->pKeyAddr,
                                                         0,
                                                         u32Temp);
                    }
                    else
                    {
                        eRet = HSM_STATUS_PARAM_ERR;
                    }
                }
                /* else do nothing */
            }
            else if (u32Temp > 32) /* max 256bits support */
            {
                eRet = HSM_STATUS_PARAM_ERR;
            }
            else
            {
                /* else do nothing */
            }

            if (HSM_STATUS_SUCCESS == eRet)
            {
                if (NULL_PTR == pCfg)
                {
                    pCtx->tL1AlgCtx.tScatterCMac.eState = HSM_L1_SCATTER_CMAC_NEED_MORE_BEFORE_INIT;
                    eRet                                = HSM_STATUS_AGAIN;
                }
                else if (pCfg->u32DataSize < (2 * HSM_AESM_SCATTER_CMAC_HW_PROCESS_ALIGN()))
                {
                    eRet = hsm_1B4B_convert_from_idx(HSM_DATA_FORMAT_4B,
                                                     &(pCtx->tL1AlgCtx.tScatterCMac.aDataBuf[0]),
                                                     0,
                                                     sizeof(pCtx->tL1AlgCtx.tScatterCMac.aDataBuf),
                                                     pCfg->eDataFmt,
                                                     pCfg->pData,
                                                     0,
                                                     pCfg->u32DataSize);
                    if (HSM_STATUS_SUCCESS == eRet)
                    {
                        pCtx->tL1AlgCtx.tScatterCMac.eState = HSM_L1_SCATTER_CMAC_NEED_MORE_BEFORE_INIT;
                        pCtx->tL1AlgCtx.tScatterCMac.u32CacheDataByteCnt = pCfg->u32DataSize;

                        eRet = HSM_STATUS_AGAIN;
                    }
                    else
                    {
                        pCtx->tL1AlgCtx.tScatterCMac.eState = HSM_L1_SCATTER_CMAC_STOP;
                    }
                }
                else /* data is enough for once at least */
                {
                    pCtx->tL1AlgCtx.tScatterCMac.eState            = HSM_L1_SCATTER_CMAC_INIT;
                    pCtx->tL1AlgCtx.tScatterCMac.pInputData        = pCfg->pData;
                    pCtx->tL1AlgCtx.tScatterCMac.eInputFmt         = pCfg->eDataFmt;
                    pCtx->tL1AlgCtx.tScatterCMac.u32InputTotalSize = pCfg->u32DataSize;

                    pCtx->tL1AlgCtx.tScatterCMac.pScatterCMacParm->u32HSMStatusRet =
                        MAILBOXAPI_RET_NONE;
                    pCtx->tL1AlgCtx.tScatterCMac.pScatterCMacParm->u32Timeout = u32TimeoutMs;

                    if ((((hsm_uint32_t)pCfg->pData) & 0x3u)
#if (FC7XXX_HSM_SUBSYSTEM_TYPE == FC7300_HSM_SUBSYSTEM)
                        || (HSM_DATA_FORMAT_1B == pCfg->eDataFmt)
#endif
                    )
                    {
                        if (pCfg->u32DataSize >= (sizeof(pCtx->tL1AlgCtx.tScatterCMac.aDataBuf) +
                                                  HSM_AESM_SCATTER_CMAC_HW_PROCESS_ALIGN()))
                        {
                            pCtx->tL1AlgCtx.tScatterCMac.u32ProcessedSize = sizeof(
                                pCtx->tL1AlgCtx.tScatterCMac.aDataBuf);
                        }
                        else
                        {
                            if (0u == (pCfg->u32DataSize % HSM_AESM_SCATTER_CMAC_HW_PROCESS_ALIGN()))
                            {
                                pCtx->tL1AlgCtx.tScatterCMac.u32ProcessedSize =
                                    pCfg->u32DataSize - HSM_AESM_SCATTER_CMAC_HW_PROCESS_ALIGN();
                            }
                            else
                            {
                                pCtx->tL1AlgCtx.tScatterCMac.u32ProcessedSize =
                                    (pCfg->u32DataSize / HSM_AESM_SCATTER_CMAC_HW_PROCESS_ALIGN()) *
                                    HSM_AESM_SCATTER_CMAC_HW_PROCESS_ALIGN();
                                pCtx->tL1AlgCtx.tScatterCMac.u32ProcessedSize -=
                                    HSM_AESM_SCATTER_CMAC_HW_PROCESS_ALIGN();
                            }
                        }

                        eRet = hsm_1B4B_convert_from_idx(
                            HSM_DATA_FORMAT_4B,
                            &(pCtx->tL1AlgCtx.tScatterCMac.aDataBuf[0]),
                            0,
                            sizeof(pCtx->tL1AlgCtx.tScatterCMac.aDataBuf),
                            pCfg->eDataFmt,
                            pCfg->pData,
                            0,
                            pCtx->tL1AlgCtx.tScatterCMac.u32ProcessedSize);
                        if (HSM_STATUS_SUCCESS == eRet)
                        {
                            pCtx->tL1AlgCtx.tScatterCMac.pScatterCMacParm->tCfg.tCfg.data_len =
                                pCtx->tL1AlgCtx.tScatterCMac.u32ProcessedSize;
                            pCtx->tL1AlgCtx.tScatterCMac.pScatterCMacParm->tCfg.tCfg.in_addr = &(
                                pCtx->tL1AlgCtx.tScatterCMac.aDataBuf[0]);
                        }

                        eCurDataFmt = HSM_DATA_FORMAT_4B;
                    }
                    else /* start address 4 aligned */
                    {
                        if (0u == (pCfg->u32DataSize % HSM_AESM_SCATTER_CMAC_HW_PROCESS_ALIGN()))
                        {
                            pCtx->tL1AlgCtx.tScatterCMac.u32ProcessedSize =
                                pCfg->u32DataSize - HSM_AESM_SCATTER_CMAC_HW_PROCESS_ALIGN();
                        }
                        else
                        {
                            pCtx->tL1AlgCtx.tScatterCMac.u32ProcessedSize =
                                (pCfg->u32DataSize / HSM_AESM_SCATTER_CMAC_HW_PROCESS_ALIGN()) *
                                HSM_AESM_SCATTER_CMAC_HW_PROCESS_ALIGN();
                            pCtx->tL1AlgCtx.tScatterCMac.u32ProcessedSize -=
                                HSM_AESM_SCATTER_CMAC_HW_PROCESS_ALIGN();
                        }

                        pCtx->tL1AlgCtx.tScatterCMac.pScatterCMacParm->tCfg.tCfg.data_len =
                            pCtx->tL1AlgCtx.tScatterCMac.u32ProcessedSize;
                        pCtx->tL1AlgCtx.tScatterCMac.pScatterCMacParm->tCfg.tCfg.in_addr = pCfg->pData;

                        eCurDataFmt = pCfg->eDataFmt;
                    }

                    if (HSM_STATUS_SUCCESS == eRet)
                    {
                        eRet = hsm_l1_scatter_cmac_init(pCtx, eCurDataFmt, HSM_DATA_FORMAT_1B);
                    }
                    else
                    {
                        pCtx->tL1AlgCtx.tScatterCMac.eState = HSM_L1_SCATTER_CMAC_STOP;
                        eRet                                = HSM_STATUS_ERROR;
                    }
                }
            }
        }
        else
        {
            eRet = HSM_STATUS_BUSY;
        }
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}

/* when need more data, return again, when trigger successfully, return success, others error */
HSM_StatusType HSM_L1_ScatterCMacUpdate(HSM_L1_RtCtxType             *pCtx,
                                        const HSM_Ln_ScatterCMacType *pCfg,
                                        hsm_uint32_t                  u32TimeoutMs)
{
    HSM_StatusType        eRet      = HSM_STATUS_SUCCESS;
    HSM_ScatterCMacSMType eCurState = pCtx->tL1AlgCtx.tScatterCMac.eState;
    HSM_BoolType          bInProcess;
    HSM_DataFormatType    eCurFmt;

    bInProcess = pCtx->bInProcess;
    if ((HSM_TRUE == bInProcess) && (HSM_OP_SCATTER_CMAC == pCtx->eOperationCata) &&
        ((HSM_L1_SCATTER_CMAC_NEED_MORE_BEFORE_INIT == eCurState) ||
         (HSM_L1_SCATTER_CMAC_INIT_OK == eCurState) ||
         (HSM_L1_SCATTER_CMAC_NEED_MORE_BEFORE_UPDATE_FINAL == eCurState) ||
         (HSM_L1_SCATTER_CMAC_UPDATE_OK == eCurState)))
    {
        if (HSM_DRV_SM_ARITH != pCtx->eStat)
        {
            pCtx->tL1AlgCtx.tScatterCMac.u32TimeoutMs      = u32TimeoutMs;
            pCtx->tL1AlgCtx.tScatterCMac.pInputData        = NULL_PTR;
            pCtx->tL1AlgCtx.tScatterCMac.eInputFmt         = HSM_DATA_FORMAT_4B;
            pCtx->tL1AlgCtx.tScatterCMac.u32InputTotalSize = 0;
            pCtx->tL1AlgCtx.tScatterCMac.u32ProcessedSize  = 0;

            if ((HSM_L1_SCATTER_CMAC_NEED_MORE_BEFORE_INIT == eCurState) ||
                (HSM_L1_SCATTER_CMAC_NEED_MORE_BEFORE_UPDATE_FINAL == eCurState))
            {
                if (NULL_PTR == pCfg)
                {
                    eRet = HSM_STATUS_AGAIN;
                }
                else if ((pCtx->tL1AlgCtx.tScatterCMac.u32CacheDataByteCnt + pCfg->u32DataSize) <
                         (2 * HSM_AESM_SCATTER_CMAC_HW_PROCESS_ALIGN()))
                {
                    eRet = hsm_1B4B_convert_from_idx(HSM_DATA_FORMAT_4B,
                                                     &(pCtx->tL1AlgCtx.tScatterCMac.aDataBuf[0]),
                                                     pCtx->tL1AlgCtx.tScatterCMac.u32CacheDataByteCnt,
                                                     sizeof(pCtx->tL1AlgCtx.tScatterCMac.aDataBuf),
                                                     pCfg->eDataFmt,
                                                     pCfg->pData,
                                                     0,
                                                     pCfg->u32DataSize);

                    if (HSM_STATUS_SUCCESS == eRet)
                    {
                        pCtx->tL1AlgCtx.tScatterCMac.u32CacheDataByteCnt += pCfg->u32DataSize;
                        eRet = HSM_STATUS_AGAIN;
                    }
                    else
                    {
                        pCtx->tL1AlgCtx.tScatterCMac.eState = HSM_L1_SCATTER_CMAC_STOP;
                    }
                }
                else
                {
                    pCtx->tL1AlgCtx.tScatterCMac.eState = HSM_L1_SCATTER_CMAC_UPDATE;

                    pCtx->tL1AlgCtx.tScatterCMac.pInputData        = pCfg->pData;
                    pCtx->tL1AlgCtx.tScatterCMac.eInputFmt         = pCfg->eDataFmt;
                    pCtx->tL1AlgCtx.tScatterCMac.u32InputTotalSize = pCfg->u32DataSize;
                    pCtx->tL1AlgCtx.tScatterCMac.u32ProcessedSize =
                        sizeof(pCtx->tL1AlgCtx.tScatterCMac.aDataBuf) -
                        pCtx->tL1AlgCtx.tScatterCMac.u32CacheDataByteCnt;

                    if (pCtx->tL1AlgCtx.tScatterCMac.u32ProcessedSize >
                        pCfg->u32DataSize) /* can cache all data */
                    {
                        pCtx->tL1AlgCtx.tScatterCMac.u32ProcessedSize = pCfg->u32DataSize;

                        eRet = hsm_1B4B_convert_from_idx(
                            HSM_DATA_FORMAT_4B,
                            &(pCtx->tL1AlgCtx.tScatterCMac.aDataBuf[0]),
                            pCtx->tL1AlgCtx.tScatterCMac.u32CacheDataByteCnt,
                            sizeof(pCtx->tL1AlgCtx.tScatterCMac.aDataBuf),
                            pCfg->eDataFmt,
                            pCfg->pData,
                            0,
                            pCtx->tL1AlgCtx.tScatterCMac.u32ProcessedSize);

                        pCtx->tL1AlgCtx.tScatterCMac.u32CacheDataByteCnt +=
                            pCtx->tL1AlgCtx.tScatterCMac.u32ProcessedSize;
                    }
                    else
                    {
                        eRet = hsm_1B4B_convert_from_idx(
                            HSM_DATA_FORMAT_4B,
                            &(pCtx->tL1AlgCtx.tScatterCMac.aDataBuf[0]),
                            pCtx->tL1AlgCtx.tScatterCMac.u32CacheDataByteCnt,
                            sizeof(pCtx->tL1AlgCtx.tScatterCMac.aDataBuf),
                            pCfg->eDataFmt,
                            pCfg->pData,
                            0,
                            pCtx->tL1AlgCtx.tScatterCMac.u32ProcessedSize);

                        pCtx->tL1AlgCtx.tScatterCMac.u32CacheDataByteCnt +=
                            pCtx->tL1AlgCtx.tScatterCMac.u32ProcessedSize;
                    }

                    pCtx->tL1AlgCtx.tScatterCMac.u32CacheProcByteCnt =
                        (pCtx->tL1AlgCtx.tScatterCMac.u32CacheDataByteCnt /
                         HSM_AESM_SCATTER_CMAC_HW_PROCESS_ALIGN()) *
                        HSM_AESM_SCATTER_CMAC_HW_PROCESS_ALIGN();

                    if (((pCtx->tL1AlgCtx.tScatterCMac.u32CacheDataByteCnt -
                          pCtx->tL1AlgCtx.tScatterCMac.u32CacheProcByteCnt) +
                         (pCtx->tL1AlgCtx.tScatterCMac.u32InputTotalSize -
                          pCtx->tL1AlgCtx.tScatterCMac.u32ProcessedSize)) < 16)
                    {
                        pCtx->tL1AlgCtx.tScatterCMac.u32CacheProcByteCnt -= 16u;
                    }

                    pCtx->tL1AlgCtx.tScatterCMac.pScatterCMacParm->u32HSMStatusRet =
                        MAILBOXAPI_RET_NONE;
                    pCtx->tL1AlgCtx.tScatterCMac.pScatterCMacParm->u32Timeout = u32TimeoutMs;
                    pCtx->tL1AlgCtx.tScatterCMac.pScatterCMacParm->tCfg.tCfg.data_len =
                        pCtx->tL1AlgCtx.tScatterCMac.u32CacheProcByteCnt;
                    pCtx->tL1AlgCtx.tScatterCMac.pScatterCMacParm->tCfg.tCfg.in_addr = &(
                        pCtx->tL1AlgCtx.tScatterCMac.aDataBuf[0]);

                    eCurFmt = HSM_DATA_FORMAT_4B;

                    if (HSM_STATUS_SUCCESS == eRet)
                    {
                        if (HSM_L1_SCATTER_CMAC_NEED_MORE_BEFORE_INIT == eCurState)
                        {
                            eRet = hsm_l1_scatter_cmac_init(pCtx, eCurFmt, HSM_DATA_FORMAT_1B);
                        }
                        else
                        {
                            eRet = hsm_l1_scatter_cmac_update(pCtx, eCurFmt, HSM_DATA_FORMAT_1B);
                        }
                    }
                    else
                    {
                        pCtx->tL1AlgCtx.tScatterCMac.eState = HSM_L1_SCATTER_CMAC_STOP;
                        eRet                                = HSM_STATUS_ERROR;
                    }
                }
            }
            else /* init ok / update ok */
            {
                if (NULL_PTR == pCfg)
                {
                    eRet = HSM_STATUS_AGAIN;
                }
                else if (pCfg->u32DataSize < (2 * HSM_AESM_SCATTER_CMAC_HW_PROCESS_ALIGN()))
                {
                    eRet = hsm_1B4B_convert_from_idx(HSM_DATA_FORMAT_4B,
                                                     &(pCtx->tL1AlgCtx.tScatterCMac.aDataBuf[0]),
                                                     0,
                                                     sizeof(pCtx->tL1AlgCtx.tScatterCMac.aDataBuf),
                                                     pCfg->eDataFmt,
                                                     pCfg->pData,
                                                     0,
                                                     pCfg->u32DataSize);
                    if (HSM_STATUS_SUCCESS == eRet)
                    {
                        pCtx->tL1AlgCtx.tScatterCMac.eState =
                            HSM_L1_SCATTER_CMAC_NEED_MORE_BEFORE_UPDATE_FINAL;
                        pCtx->tL1AlgCtx.tScatterCMac.u32CacheDataByteCnt = pCfg->u32DataSize;

                        eRet = HSM_STATUS_AGAIN;
                    }
                    else
                    {
                        pCtx->tL1AlgCtx.tScatterCMac.eState = HSM_L1_SCATTER_CMAC_STOP;
                    }
                }
                else /* data is enough for once at least */
                {
                    pCtx->tL1AlgCtx.tScatterCMac.eState              = HSM_L1_SCATTER_CMAC_UPDATE;
                    pCtx->tL1AlgCtx.tScatterCMac.pInputData          = pCfg->pData;
                    pCtx->tL1AlgCtx.tScatterCMac.eInputFmt           = pCfg->eDataFmt;
                    pCtx->tL1AlgCtx.tScatterCMac.u32InputTotalSize   = pCfg->u32DataSize;
                    pCtx->tL1AlgCtx.tScatterCMac.u32CacheProcByteCnt = 0u;
                    pCtx->tL1AlgCtx.tScatterCMac.u32CacheDataByteCnt = 0u;

                    pCtx->tL1AlgCtx.tScatterCMac.pScatterCMacParm->u32HSMStatusRet =
                        MAILBOXAPI_RET_NONE;
                    pCtx->tL1AlgCtx.tScatterCMac.pScatterCMacParm->u32Timeout = u32TimeoutMs;

                    if ((((hsm_uint32_t)pCfg->pData) & 0x3)
#if (FC7XXX_HSM_SUBSYSTEM_TYPE == FC7300_HSM_SUBSYSTEM)
                        || (HSM_DATA_FORMAT_1B == pCfg->eDataFmt)
#endif
                    )
                    {
                        if (pCfg->u32DataSize >= (sizeof(pCtx->tL1AlgCtx.tScatterCMac.aDataBuf) +
                                                  HSM_AESM_SCATTER_CMAC_HW_PROCESS_ALIGN()))
                        {
                            pCtx->tL1AlgCtx.tScatterCMac.u32ProcessedSize = sizeof(
                                pCtx->tL1AlgCtx.tScatterCMac.aDataBuf);
                        }
                        else
                        {
                            if (0u == (pCfg->u32DataSize % HSM_AESM_SCATTER_CMAC_HW_PROCESS_ALIGN()))
                            {
                                pCtx->tL1AlgCtx.tScatterCMac.u32ProcessedSize =
                                    pCfg->u32DataSize - HSM_AESM_SCATTER_CMAC_HW_PROCESS_ALIGN();
                            }
                            else
                            {
                                pCtx->tL1AlgCtx.tScatterCMac.u32ProcessedSize =
                                    (pCfg->u32DataSize / HSM_AESM_SCATTER_CMAC_HW_PROCESS_ALIGN()) *
                                    HSM_AESM_SCATTER_CMAC_HW_PROCESS_ALIGN();
                                pCtx->tL1AlgCtx.tScatterCMac.u32ProcessedSize -=
                                    HSM_AESM_SCATTER_CMAC_HW_PROCESS_ALIGN();
                            }
                        }

                        eRet = hsm_1B4B_convert_from_idx(
                            HSM_DATA_FORMAT_4B,
                            &(pCtx->tL1AlgCtx.tScatterCMac.aDataBuf[0]),
                            0,
                            sizeof(pCtx->tL1AlgCtx.tScatterCMac.aDataBuf),
                            pCfg->eDataFmt,
                            pCfg->pData,
                            0,
                            pCtx->tL1AlgCtx.tScatterCMac.u32ProcessedSize);
                        if (HSM_STATUS_SUCCESS == eRet)
                        {
                            pCtx->tL1AlgCtx.tScatterCMac.pScatterCMacParm->tCfg.tCfg.data_len =
                                pCtx->tL1AlgCtx.tScatterCMac.u32ProcessedSize;
                            pCtx->tL1AlgCtx.tScatterCMac.pScatterCMacParm->tCfg.tCfg.in_addr = &(
                                pCtx->tL1AlgCtx.tScatterCMac.aDataBuf[0]);
                        }

                        eCurFmt = HSM_DATA_FORMAT_4B;
                    }
                    else /* start address 4 aligned */
                    {
                        if (0u == (pCfg->u32DataSize % HSM_AESM_SCATTER_CMAC_HW_PROCESS_ALIGN()))
                        {
                            pCtx->tL1AlgCtx.tScatterCMac.u32ProcessedSize =
                                pCfg->u32DataSize - HSM_AESM_SCATTER_CMAC_HW_PROCESS_ALIGN();
                        }
                        else
                        {
                            pCtx->tL1AlgCtx.tScatterCMac.u32ProcessedSize =
                                (pCfg->u32DataSize / HSM_AESM_SCATTER_CMAC_HW_PROCESS_ALIGN()) *
                                HSM_AESM_SCATTER_CMAC_HW_PROCESS_ALIGN();
                            pCtx->tL1AlgCtx.tScatterCMac.u32ProcessedSize -=
                                HSM_AESM_SCATTER_CMAC_HW_PROCESS_ALIGN();
                        }

                        pCtx->tL1AlgCtx.tScatterCMac.pScatterCMacParm->tCfg.tCfg.data_len =
                            pCtx->tL1AlgCtx.tScatterCMac.u32ProcessedSize;
                        pCtx->tL1AlgCtx.tScatterCMac.pScatterCMacParm->tCfg.tCfg.in_addr = pCfg->pData;

                        eCurFmt = pCfg->eDataFmt;
                    }

                    if (HSM_STATUS_SUCCESS == eRet)
                    {
                        eRet = hsm_l1_scatter_cmac_update(pCtx, eCurFmt, HSM_DATA_FORMAT_1B);
                    }
                    else
                    {
                        pCtx->tL1AlgCtx.tScatterCMac.eState = HSM_L1_SCATTER_CMAC_STOP;
                        eRet                                = HSM_STATUS_ERROR;
                    }
                }
            }
        }
        else
        {
            eRet = HSM_STATUS_BUSY;
        }
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}

/* when trigger successfully, return success, others error */
HSM_StatusType HSM_L1_ScatterCMacFinal(HSM_L1_RtCtxType               *pCtx,
                                       const HSM_Ln_ScatterCMacType   *pCfg,
                                       const HSM_Ln_ResultBufInfoType *pResult,
                                       hsm_uint32_t                    u32TimeoutMs)
{
    HSM_StatusType        eRet      = HSM_STATUS_SUCCESS;
    HSM_ScatterCMacSMType eCurState = pCtx->tL1AlgCtx.tScatterCMac.eState;
    HSM_BoolType          bInProcess;
    HSM_DataFormatType    eCurFmt;

    bInProcess = pCtx->bInProcess;
    if ((HSM_TRUE == bInProcess) && (HSM_OP_SCATTER_CMAC == pCtx->eOperationCata) &&
        ((HSM_L1_SCATTER_CMAC_NEED_MORE_BEFORE_INIT == eCurState) ||
         (HSM_L1_SCATTER_CMAC_INIT_OK == eCurState) ||
         (HSM_L1_SCATTER_CMAC_NEED_MORE_BEFORE_UPDATE_FINAL == eCurState) ||
         (HSM_L1_SCATTER_CMAC_UPDATE_OK == eCurState)))
    {
        if (HSM_DRV_SM_ARITH != pCtx->eStat)
        {
            pCtx->tL1AlgCtx.tScatterCMac.u32TimeoutMs = u32TimeoutMs;

            pCtx->tL1AlgCtx.tScatterCMac.pOut              = pResult->pData;
            pCtx->tL1AlgCtx.tScatterCMac.u32OutBufSize     = pResult->u32DataBufSize;
            pCtx->tL1AlgCtx.tScatterCMac.eOutFmt           = pResult->eDataFmt;
            pCtx->tL1AlgCtx.tScatterCMac.pOutSize          = pResult->pDataSize;
            pCtx->tL1AlgCtx.tScatterCMac.eState            = HSM_L1_SCATTER_CMAC_FINAL;
            pCtx->tL1AlgCtx.tScatterCMac.pInputData        = NULL_PTR;
            pCtx->tL1AlgCtx.tScatterCMac.eInputFmt         = HSM_DATA_FORMAT_4B;
            pCtx->tL1AlgCtx.tScatterCMac.u32InputTotalSize = 0;
            pCtx->tL1AlgCtx.tScatterCMac.u32ProcessedSize  = 0;

            pCtx->tL1AlgCtx.tScatterCMac.u32CacheProcByteCnt = 0;

            if ((HSM_L1_SCATTER_CMAC_NEED_MORE_BEFORE_INIT == eCurState) ||
                (HSM_L1_SCATTER_CMAC_NEED_MORE_BEFORE_UPDATE_FINAL == eCurState))
            {
                if ((pCtx->tL1AlgCtx.tScatterCMac.u32CacheDataByteCnt + pCfg->u32DataSize) <
                    (2 * HSM_AESM_SCATTER_CMAC_HW_PROCESS_ALIGN()))
                {
                    eRet = hsm_1B4B_convert_from_idx(HSM_DATA_FORMAT_4B,
                                                     &(pCtx->tL1AlgCtx.tScatterCMac.aDataBuf[0]),
                                                     pCtx->tL1AlgCtx.tScatterCMac.u32CacheDataByteCnt,
                                                     sizeof(pCtx->tL1AlgCtx.tScatterCMac.aDataBuf),
                                                     pCfg->eDataFmt,
                                                     pCfg->pData,
                                                     0,
                                                     pCfg->u32DataSize);

                    if (HSM_STATUS_SUCCESS == eRet)
                    {
                        pCtx->tL1AlgCtx.tScatterCMac.u32CacheDataByteCnt += pCfg->u32DataSize;

                        if (HSM_L1_SCATTER_CMAC_NEED_MORE_BEFORE_INIT == eCurState)
                        {
                            HSMCom_CMacExType *pParm = (HSMCom_CMacExType *)HSM_ADDRESS_UP_ALIGN(&(
                                pCtx->tL1AlgCtx.tScatterCMac.tScatterCMacParamShared.aCMacParmBuf[0]));

                            /* convert from 4B to 1B */
                            hsm_u32_array_swap(
                                (hsm_uint32_t *)&(pCtx->tL1AlgCtx.tScatterCMac.aDataBuf[0]),
                                (pCtx->tL1AlgCtx.tScatterCMac.u32CacheDataByteCnt + 3u) >> 2u);

                            pParm->u32HSMStatusRet          = MAILBOXAPI_RET_NONE;
                            pParm->u32Timeout               = u32TimeoutMs;
                            pParm->u32UserKeyID             = pCtx->tL1AlgCtx.tScatterCMac.u32KeyId;
                            pParm->tCfg.eUseKeyType         = HSM_AES_KEY_NEW;
                            pParm->tCfg.tNewKeyInf.eKeyType = pCtx->tL1AlgCtx.tScatterCMac.eKeyType;
                            pParm->tCfg.tNewKeyInf.pKeyAddr = (const hsm_uint8_t *)&(
                                pCtx->tL1AlgCtx.tScatterCMac.aKeyData[0]);
                            pParm->tCfg.u32GenMacByteCnt = 0x10;
                            pParm->tCfg.bCheckMacEn      = HSM_FALSE;
                            pParm->tCfg.pDataInput       = (const hsm_uint32_t *)&(
                                pCtx->tL1AlgCtx.tScatterCMac.aDataBuf[0]);
                            pParm->tCfg.u32InputByteCnt =
                                pCtx->tL1AlgCtx.tScatterCMac.u32CacheDataByteCnt;
                            pParm->tCfg.pDataOutput = (hsm_uint32_t *)HSM_ADDRESS_UP_ALIGN(
                                &(pCtx->tL1AlgCtx.tScatterCMac.tScatterCMacResultShared
                                      .aCMacResultBuf[0]));
                            pParm->tCfg.u32OutputMemSize = sizeof(
                                pCtx->tL1AlgCtx.tScatterCMac.tScatterCMacResultShared.aCMacResultBuf);
                            pParm->tCfg.eInputFmt  = HSM_DATA_FORMAT_1B;
                            pParm->tCfg.eOutputFmt = HSM_DATA_FORMAT_4B;
                            pParm->tCfg.eEngine    = pCtx->tL1AlgCtx.tScatterCMac.eBackend;

                            pCtx->tL1AlgCtx.tScatterCMac.u32CacheDataByteCnt = 0;

                            eRet = hsm_l1_scatter_cmac_init2final(pCtx, pParm);
                        }
                        else
                        {
                            pCtx->tL1AlgCtx.tScatterCMac.pScatterCMacParm->u32HSMStatusRet =
                                MAILBOXAPI_RET_NONE;
                            pCtx->tL1AlgCtx.tScatterCMac.pScatterCMacParm->u32Timeout = u32TimeoutMs;

                            pCtx->tL1AlgCtx.tScatterCMac.pScatterCMacParm->tCfg.tCfg.data_len =
                                pCtx->tL1AlgCtx.tScatterCMac.u32CacheDataByteCnt;
                            pCtx->tL1AlgCtx.tScatterCMac.pScatterCMacParm->tCfg.tCfg.in_addr =
                                (const hsm_uint8_t *)&(pCtx->tL1AlgCtx.tScatterCMac.aDataBuf[0]);

                            pCtx->tL1AlgCtx.tScatterCMac.u32CacheDataByteCnt = 0u;

                            eRet = hsm_l1_scatter_cmac_final(pCtx,
                                                             HSM_DATA_FORMAT_4B,
                                                             HSM_DATA_FORMAT_1B);
                        }
                    }
                    else
                    {
                        pCtx->tL1AlgCtx.tScatterCMac.eState = HSM_L1_SCATTER_CMAC_STOP;
                    }
                }
                else
                {
                    pCtx->tL1AlgCtx.tScatterCMac.pInputData        = pCfg->pData;
                    pCtx->tL1AlgCtx.tScatterCMac.eInputFmt         = pCfg->eDataFmt;
                    pCtx->tL1AlgCtx.tScatterCMac.u32InputTotalSize = pCfg->u32DataSize;
                    pCtx->tL1AlgCtx.tScatterCMac.u32ProcessedSize =
                        sizeof(pCtx->tL1AlgCtx.tScatterCMac.aDataBuf) -
                        pCtx->tL1AlgCtx.tScatterCMac.u32CacheDataByteCnt;

                    if (pCtx->tL1AlgCtx.tScatterCMac.u32ProcessedSize >
                        pCfg->u32DataSize) /* can cache all data */
                    {
                        pCtx->tL1AlgCtx.tScatterCMac.u32ProcessedSize = pCfg->u32DataSize;

                        eRet = hsm_1B4B_convert_from_idx(
                            HSM_DATA_FORMAT_4B,
                            &(pCtx->tL1AlgCtx.tScatterCMac.aDataBuf[0]),
                            pCtx->tL1AlgCtx.tScatterCMac.u32CacheDataByteCnt,
                            sizeof(pCtx->tL1AlgCtx.tScatterCMac.aDataBuf),
                            pCfg->eDataFmt,
                            pCfg->pData,
                            0,
                            pCtx->tL1AlgCtx.tScatterCMac.u32ProcessedSize);

                        pCtx->tL1AlgCtx.tScatterCMac.u32CacheDataByteCnt +=
                            pCtx->tL1AlgCtx.tScatterCMac.u32ProcessedSize;
                    }
                    else
                    {
                        eRet = hsm_1B4B_convert_from_idx(
                            HSM_DATA_FORMAT_4B,
                            &(pCtx->tL1AlgCtx.tScatterCMac.aDataBuf[0]),
                            pCtx->tL1AlgCtx.tScatterCMac.u32CacheDataByteCnt,
                            sizeof(pCtx->tL1AlgCtx.tScatterCMac.aDataBuf),
                            pCfg->eDataFmt,
                            pCfg->pData,
                            0,
                            pCtx->tL1AlgCtx.tScatterCMac.u32ProcessedSize);

                        pCtx->tL1AlgCtx.tScatterCMac.u32CacheDataByteCnt +=
                            pCtx->tL1AlgCtx.tScatterCMac.u32ProcessedSize;
                    }

                    pCtx->tL1AlgCtx.tScatterCMac.u32CacheProcByteCnt =
                        (pCtx->tL1AlgCtx.tScatterCMac.u32CacheDataByteCnt /
                         HSM_AESM_SCATTER_CMAC_HW_PROCESS_ALIGN()) *
                        HSM_AESM_SCATTER_CMAC_HW_PROCESS_ALIGN();

                    if (((pCtx->tL1AlgCtx.tScatterCMac.u32CacheDataByteCnt -
                          pCtx->tL1AlgCtx.tScatterCMac.u32CacheProcByteCnt) +
                         (pCtx->tL1AlgCtx.tScatterCMac.u32InputTotalSize -
                          pCtx->tL1AlgCtx.tScatterCMac.u32ProcessedSize)) < 16)
                    {
                        pCtx->tL1AlgCtx.tScatterCMac.u32CacheProcByteCnt -= 16u;
                    }

                    pCtx->tL1AlgCtx.tScatterCMac.pScatterCMacParm->u32HSMStatusRet =
                        MAILBOXAPI_RET_NONE;
                    pCtx->tL1AlgCtx.tScatterCMac.pScatterCMacParm->u32Timeout = u32TimeoutMs;

                    pCtx->tL1AlgCtx.tScatterCMac.pScatterCMacParm->tCfg.tCfg.data_len =
                        pCtx->tL1AlgCtx.tScatterCMac.u32CacheProcByteCnt;
                    pCtx->tL1AlgCtx.tScatterCMac.pScatterCMacParm->tCfg.tCfg.in_addr = &(
                        pCtx->tL1AlgCtx.tScatterCMac.aDataBuf[0]);

                    if (HSM_STATUS_SUCCESS == eRet)
                    {
                        if (HSM_L1_SCATTER_CMAC_NEED_MORE_BEFORE_INIT == eCurState)
                        {
                            eRet = hsm_l1_scatter_cmac_init(pCtx,
                                                            HSM_DATA_FORMAT_4B,
                                                            HSM_DATA_FORMAT_1B);
                        }
                        else
                        {
                            eRet = hsm_l1_scatter_cmac_update(pCtx,
                                                              HSM_DATA_FORMAT_4B,
                                                              HSM_DATA_FORMAT_1B);
                        }
                    }
                    else
                    {
                        pCtx->tL1AlgCtx.tScatterCMac.eState = HSM_L1_SCATTER_CMAC_STOP;
                        eRet                                = HSM_STATUS_ERROR;
                    }
                }
            }
            else /* init ok / update ok */
            {
                if (pCfg->u32DataSize < (2 * HSM_AESM_SCATTER_CMAC_HW_PROCESS_ALIGN()))
                {
                    eRet = hsm_1B4B_convert_from_idx(HSM_DATA_FORMAT_4B,
                                                     &(pCtx->tL1AlgCtx.tScatterCMac.aDataBuf[0]),
                                                     0,
                                                     sizeof(pCtx->tL1AlgCtx.tScatterCMac.aDataBuf),
                                                     pCfg->eDataFmt,
                                                     pCfg->pData,
                                                     0,
                                                     pCfg->u32DataSize);
                    if (HSM_STATUS_SUCCESS == eRet)
                    {
                        pCtx->tL1AlgCtx.tScatterCMac.u32CacheDataByteCnt = pCfg->u32DataSize;

                        pCtx->tL1AlgCtx.tScatterCMac.pScatterCMacParm->u32HSMStatusRet =
                            MAILBOXAPI_RET_NONE;
                        pCtx->tL1AlgCtx.tScatterCMac.pScatterCMacParm->u32Timeout = u32TimeoutMs;

                        pCtx->tL1AlgCtx.tScatterCMac.pScatterCMacParm->tCfg.tCfg.data_len =
                            pCtx->tL1AlgCtx.tScatterCMac.u32CacheDataByteCnt;
                        pCtx->tL1AlgCtx.tScatterCMac.pScatterCMacParm->tCfg.tCfg.in_addr =
                            (const hsm_uint8_t *)&(pCtx->tL1AlgCtx.tScatterCMac.aDataBuf[0]);

                        pCtx->tL1AlgCtx.tScatterCMac.u32CacheDataByteCnt = 0u;

                        eRet = hsm_l1_scatter_cmac_final(pCtx, HSM_DATA_FORMAT_4B, HSM_DATA_FORMAT_1B);
                    }
                    else
                    {
                        pCtx->tL1AlgCtx.tScatterCMac.eState = HSM_L1_SCATTER_CMAC_STOP;
                    }
                }
                else /* data is enough for once at least */
                {
                    pCtx->tL1AlgCtx.tScatterCMac.pInputData          = pCfg->pData;
                    pCtx->tL1AlgCtx.tScatterCMac.eInputFmt           = pCfg->eDataFmt;
                    pCtx->tL1AlgCtx.tScatterCMac.u32InputTotalSize   = pCfg->u32DataSize;
                    pCtx->tL1AlgCtx.tScatterCMac.u32CacheProcByteCnt = 0u;
                    pCtx->tL1AlgCtx.tScatterCMac.u32CacheDataByteCnt = 0u;

                    pCtx->tL1AlgCtx.tScatterCMac.pScatterCMacParm->u32HSMStatusRet =
                        MAILBOXAPI_RET_NONE;
                    pCtx->tL1AlgCtx.tScatterCMac.pScatterCMacParm->u32Timeout = u32TimeoutMs;

                    if ((((hsm_uint32_t)pCfg->pData) & 0x3)
#if (FC7XXX_HSM_SUBSYSTEM_TYPE == FC7300_HSM_SUBSYSTEM)
                        || (HSM_DATA_FORMAT_1B == pCfg->eDataFmt)
#endif
                    )
                    {
                        if (pCfg->u32DataSize >= (sizeof(pCtx->tL1AlgCtx.tScatterCMac.aDataBuf) +
                                                  HSM_AESM_SCATTER_CMAC_HW_PROCESS_ALIGN()))
                        {
                            pCtx->tL1AlgCtx.tScatterCMac.u32ProcessedSize = sizeof(
                                pCtx->tL1AlgCtx.tScatterCMac.aDataBuf);
                        }
                        else
                        {
                            if (0u == (pCfg->u32DataSize % HSM_AESM_SCATTER_CMAC_HW_PROCESS_ALIGN()))
                            {
                                pCtx->tL1AlgCtx.tScatterCMac.u32ProcessedSize =
                                    pCfg->u32DataSize - HSM_AESM_SCATTER_CMAC_HW_PROCESS_ALIGN();
                            }
                            else
                            {
                                pCtx->tL1AlgCtx.tScatterCMac.u32ProcessedSize =
                                    (pCfg->u32DataSize / HSM_AESM_SCATTER_CMAC_HW_PROCESS_ALIGN()) *
                                    HSM_AESM_SCATTER_CMAC_HW_PROCESS_ALIGN();
                                pCtx->tL1AlgCtx.tScatterCMac.u32ProcessedSize -=
                                    HSM_AESM_SCATTER_CMAC_HW_PROCESS_ALIGN();
                            }
                        }

                        eRet = hsm_1B4B_convert_from_idx(
                            HSM_DATA_FORMAT_4B,
                            &(pCtx->tL1AlgCtx.tScatterCMac.aDataBuf[0]),
                            0,
                            sizeof(pCtx->tL1AlgCtx.tScatterCMac.aDataBuf),
                            pCfg->eDataFmt,
                            pCfg->pData,
                            0,
                            pCtx->tL1AlgCtx.tScatterCMac.u32ProcessedSize);
                        if (HSM_STATUS_SUCCESS == eRet)
                        {
                            pCtx->tL1AlgCtx.tScatterCMac.pScatterCMacParm->tCfg.tCfg.data_len =
                                pCtx->tL1AlgCtx.tScatterCMac.u32ProcessedSize;
                            pCtx->tL1AlgCtx.tScatterCMac.pScatterCMacParm->tCfg.tCfg.in_addr = &(
                                pCtx->tL1AlgCtx.tScatterCMac.aDataBuf[0]);
                        }

                        eCurFmt = HSM_DATA_FORMAT_4B;
                    }
                    else /* start address 4 aligned */
                    {
                        if (0u == (pCfg->u32DataSize % HSM_AESM_SCATTER_CMAC_HW_PROCESS_ALIGN()))
                        {
                            pCtx->tL1AlgCtx.tScatterCMac.u32ProcessedSize =
                                pCfg->u32DataSize - HSM_AESM_SCATTER_CMAC_HW_PROCESS_ALIGN();
                        }
                        else
                        {
                            pCtx->tL1AlgCtx.tScatterCMac.u32ProcessedSize =
                                (pCfg->u32DataSize / HSM_AESM_SCATTER_CMAC_HW_PROCESS_ALIGN()) *
                                HSM_AESM_SCATTER_CMAC_HW_PROCESS_ALIGN();
                            pCtx->tL1AlgCtx.tScatterCMac.u32ProcessedSize -=
                                HSM_AESM_SCATTER_CMAC_HW_PROCESS_ALIGN();
                        }

                        pCtx->tL1AlgCtx.tScatterCMac.pScatterCMacParm->tCfg.tCfg.data_len =
                            pCtx->tL1AlgCtx.tScatterCMac.u32ProcessedSize;
                        pCtx->tL1AlgCtx.tScatterCMac.pScatterCMacParm->tCfg.tCfg.in_addr = pCfg->pData;

                        eCurFmt = pCfg->eDataFmt;
                    }

                    if (HSM_STATUS_SUCCESS == eRet)
                    {
                        eRet = hsm_l1_scatter_cmac_update(pCtx, eCurFmt, HSM_DATA_FORMAT_1B);
                    }
                    else
                    {
                        pCtx->tL1AlgCtx.tScatterCMac.eState = HSM_L1_SCATTER_CMAC_STOP;
                        eRet                                = HSM_STATUS_ERROR;
                    }
                }
            }
        }
        else
        {
            eRet = HSM_STATUS_BUSY;
        }
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}

/* get result return success, trigger next process return again, others error */
HSM_StatusType HSM_L1_ScatterCMac_Isr(HSM_L1_RtCtxType *pCtx)
{
    HSM_StatusType        eRet      = HSM_STATUS_SUCCESS;
    HSM_ScatterCMacSMType eCurState = pCtx->tL1AlgCtx.tScatterCMac.eState;
    hsm_uint32_t          u32Temp, u32Temp2;

    if (MAILBOXAPI_RET_SUCCESS == pCtx->tL1AlgCtx.tScatterCMac.pScatterCMacParm->u32HSMStatusRet)
    {
        pCtx->eStat = HSM_DRV_SM_STOP;

        if ((pCtx->tL1AlgCtx.tScatterCMac.u32CacheProcByteCnt != 0u) &&
            (pCtx->tL1AlgCtx.tScatterCMac.u32CacheProcByteCnt <
             pCtx->tL1AlgCtx.tScatterCMac.u32CacheDataByteCnt))
        {
            hsm_memcpy(&(pCtx->tL1AlgCtx.tScatterCMac.aDataBuf[0]),
                       ((hsm_uint8_t *)&(pCtx->tL1AlgCtx.tScatterCMac.aDataBuf[0])) +
                           pCtx->tL1AlgCtx.tScatterCMac.u32CacheProcByteCnt,
                       (((pCtx->tL1AlgCtx.tScatterCMac.u32CacheDataByteCnt -
                          pCtx->tL1AlgCtx.tScatterCMac.u32CacheProcByteCnt) +
                         3) >>
                        2) << 2);

            pCtx->tL1AlgCtx.tScatterCMac.u32CacheDataByteCnt =
                pCtx->tL1AlgCtx.tScatterCMac.u32CacheDataByteCnt -
                pCtx->tL1AlgCtx.tScatterCMac.u32CacheProcByteCnt;
            pCtx->tL1AlgCtx.tScatterCMac.u32CacheProcByteCnt = 0u;
        }
        else
        {
            pCtx->tL1AlgCtx.tScatterCMac.u32CacheProcByteCnt = 0u;
            pCtx->tL1AlgCtx.tScatterCMac.u32CacheDataByteCnt = 0u;
        }

        if ((HSM_L1_SCATTER_CMAC_INIT == eCurState) || (HSM_L1_SCATTER_CMAC_UPDATE == eCurState))
        {
            if (pCtx->tL1AlgCtx.tScatterCMac.u32InputTotalSize <=
                pCtx->tL1AlgCtx.tScatterCMac.u32ProcessedSize)
            {
                if (pCtx->tL1AlgCtx.tScatterCMac.u32CacheDataByteCnt > 0u)
                {
                    pCtx->tL1AlgCtx.tScatterCMac.eState =
                        HSM_L1_SCATTER_CMAC_NEED_MORE_BEFORE_UPDATE_FINAL;
                }
                else
                {
                    if (HSM_L1_SCATTER_CMAC_INIT == eCurState)
                    {
                        pCtx->tL1AlgCtx.tScatterCMac.eState = HSM_L1_SCATTER_CMAC_INIT_OK;
                    }
                    else
                    {
                        pCtx->tL1AlgCtx.tScatterCMac.eState = HSM_L1_SCATTER_CMAC_UPDATE_OK;
                    }
                }

                pCtx->tL1AlgCtx.tScatterCMac.pInputData        = NULL_PTR;
                pCtx->tL1AlgCtx.tScatterCMac.eInputFmt         = HSM_DATA_FORMAT_4B;
                pCtx->tL1AlgCtx.tScatterCMac.u32InputTotalSize = 0;
                pCtx->tL1AlgCtx.tScatterCMac.u32ProcessedSize  = 0;
            }
            else
            {
                u32Temp = pCtx->tL1AlgCtx.tScatterCMac.u32InputTotalSize -
                          pCtx->tL1AlgCtx.tScatterCMac.u32ProcessedSize;

                if ((pCtx->tL1AlgCtx.tScatterCMac.u32CacheDataByteCnt + u32Temp) <
                    (2 * HSM_AESM_SCATTER_CMAC_HW_PROCESS_ALIGN()))
                {
                    eRet = hsm_1B4B_convert_from_idx(HSM_DATA_FORMAT_4B,
                                                     &(pCtx->tL1AlgCtx.tScatterCMac.aDataBuf[0]),
                                                     pCtx->tL1AlgCtx.tScatterCMac.u32CacheDataByteCnt,
                                                     sizeof(pCtx->tL1AlgCtx.tScatterCMac.aDataBuf),
                                                     pCtx->tL1AlgCtx.tScatterCMac.eInputFmt,
                                                     pCtx->tL1AlgCtx.tScatterCMac.pInputData,
                                                     pCtx->tL1AlgCtx.tScatterCMac.u32ProcessedSize,
                                                     pCtx->tL1AlgCtx.tScatterCMac.u32InputTotalSize);

                    if (HSM_STATUS_SUCCESS == eRet)
                    {
                        pCtx->tL1AlgCtx.tScatterCMac.u32CacheDataByteCnt += u32Temp;

                        pCtx->tL1AlgCtx.tScatterCMac.pInputData        = NULL_PTR;
                        pCtx->tL1AlgCtx.tScatterCMac.eInputFmt         = HSM_DATA_FORMAT_4B;
                        pCtx->tL1AlgCtx.tScatterCMac.u32InputTotalSize = 0u;
                        pCtx->tL1AlgCtx.tScatterCMac.u32ProcessedSize =
                            0u; /* has cache all input data */

                        pCtx->tL1AlgCtx.tScatterCMac.eState =
                            HSM_L1_SCATTER_CMAC_NEED_MORE_BEFORE_UPDATE_FINAL;
                    }
                    else
                    {
                        pCtx->tL1AlgCtx.tScatterCMac.eState = HSM_L1_SCATTER_CMAC_STOP;
                    }
                }
                else
                {
                    u32Temp2 = sizeof(pCtx->tL1AlgCtx.tScatterCMac.aDataBuf) -
                               pCtx->tL1AlgCtx.tScatterCMac.u32CacheDataByteCnt;

                    if (u32Temp2 > u32Temp) /* can cache all data */
                    {
                        eRet = hsm_1B4B_convert_from_idx(
                            HSM_DATA_FORMAT_4B,
                            &(pCtx->tL1AlgCtx.tScatterCMac.aDataBuf[0]),
                            pCtx->tL1AlgCtx.tScatterCMac.u32CacheDataByteCnt,
                            sizeof(pCtx->tL1AlgCtx.tScatterCMac.aDataBuf),
                            pCtx->tL1AlgCtx.tScatterCMac.eInputFmt,
                            pCtx->tL1AlgCtx.tScatterCMac.pInputData,
                            pCtx->tL1AlgCtx.tScatterCMac.u32ProcessedSize,
                            pCtx->tL1AlgCtx.tScatterCMac.u32InputTotalSize);

                        pCtx->tL1AlgCtx.tScatterCMac.u32ProcessedSize += u32Temp;
                        pCtx->tL1AlgCtx.tScatterCMac.u32CacheDataByteCnt += u32Temp;
                    }
                    else
                    {
                        eRet = hsm_1B4B_convert_from_idx(
                            HSM_DATA_FORMAT_4B,
                            &(pCtx->tL1AlgCtx.tScatterCMac.aDataBuf[0]),
                            pCtx->tL1AlgCtx.tScatterCMac.u32CacheDataByteCnt,
                            sizeof(pCtx->tL1AlgCtx.tScatterCMac.aDataBuf),
                            pCtx->tL1AlgCtx.tScatterCMac.eInputFmt,
                            pCtx->tL1AlgCtx.tScatterCMac.pInputData,
                            pCtx->tL1AlgCtx.tScatterCMac.u32ProcessedSize,
                            pCtx->tL1AlgCtx.tScatterCMac.u32ProcessedSize + u32Temp2);

                        pCtx->tL1AlgCtx.tScatterCMac.u32ProcessedSize += u32Temp2;
                        pCtx->tL1AlgCtx.tScatterCMac.u32CacheDataByteCnt += u32Temp2;
                    }

                    pCtx->tL1AlgCtx.tScatterCMac.u32CacheProcByteCnt =
                        (pCtx->tL1AlgCtx.tScatterCMac.u32CacheDataByteCnt /
                         HSM_AESM_SCATTER_CMAC_HW_PROCESS_ALIGN()) *
                        HSM_AESM_SCATTER_CMAC_HW_PROCESS_ALIGN();

                    if (((pCtx->tL1AlgCtx.tScatterCMac.u32CacheDataByteCnt -
                          pCtx->tL1AlgCtx.tScatterCMac.u32CacheProcByteCnt) +
                         (pCtx->tL1AlgCtx.tScatterCMac.u32InputTotalSize -
                          pCtx->tL1AlgCtx.tScatterCMac.u32ProcessedSize)) < 16)
                    {
                        pCtx->tL1AlgCtx.tScatterCMac.u32CacheProcByteCnt -= 16u;
                    }

                    pCtx->tL1AlgCtx.tScatterCMac.pScatterCMacParm->u32HSMStatusRet =
                        MAILBOXAPI_RET_NONE;
                    pCtx->tL1AlgCtx.tScatterCMac.pScatterCMacParm->u32Timeout =
                        pCtx->tL1AlgCtx.tScatterCMac.u32TimeoutMs;

                    pCtx->tL1AlgCtx.tScatterCMac.pScatterCMacParm->tCfg.tCfg.data_len =
                        pCtx->tL1AlgCtx.tScatterCMac.u32CacheProcByteCnt;
                    pCtx->tL1AlgCtx.tScatterCMac.pScatterCMacParm->tCfg.tCfg.in_addr = &(
                        pCtx->tL1AlgCtx.tScatterCMac.aDataBuf[0]);

                    if (HSM_STATUS_SUCCESS == eRet)
                    {
                        eRet = hsm_l1_scatter_cmac_update(pCtx, HSM_DATA_FORMAT_4B, HSM_DATA_FORMAT_1B);
                        if (HSM_STATUS_SUCCESS == eRet)
                        {
                            eRet = HSM_STATUS_AGAIN;
                        }
                        /* else do nothing */
                    }
                    else
                    {
                        pCtx->tL1AlgCtx.tScatterCMac.eState = HSM_L1_SCATTER_CMAC_STOP;
                        eRet                                = HSM_STATUS_ERROR;
                    }
                }
            }
        }
        else if (HSM_L1_SCATTER_CMAC_FINAL == eCurState)
        {
            if ((pCtx->tL1AlgCtx.tScatterCMac.u32InputTotalSize <=
                 pCtx->tL1AlgCtx.tScatterCMac.u32ProcessedSize) &&
                (pCtx->tL1AlgCtx.tScatterCMac.u32CacheDataByteCnt ==
                 0u)) /* has processed all input data */
            {
                pCtx->tL1AlgCtx.tScatterCMac.eState = HSM_L1_SCATTER_CMAC_STOP;

                if ((pCtx->tL1AlgCtx.tScatterCMac.pOut != NULL_PTR))
                {
                    u32Temp = 16u;

                    if (HSM_STATUS_SUCCESS == eRet)
                    {
                        if (HSM_DATA_FORMAT_1B == pCtx->tL1AlgCtx.tScatterCMac.eOutFmt)
                        {
                            hsm_u32_array_swap((hsm_uint32_t *)(pCtx->tL1AlgCtx.tScatterCMac
                                                                    .pScatterCMacParm->tCfg.pCtx1),
                                               u32Temp / 4U); /* all result data size is 4*N */
                        }
                        else
                        {
                        }

                        if (pCtx->tL1AlgCtx.tScatterCMac.u32OutBufSize <= u32Temp)
                        {
                            u32Temp = pCtx->tL1AlgCtx.tScatterCMac.u32OutBufSize;
                        }
                        /* else do nothing */

                        hsm_memcpy(pCtx->tL1AlgCtx.tScatterCMac.pOut,
                                   pCtx->tL1AlgCtx.tScatterCMac.pScatterCMacParm->tCfg.pCtx1,
                                   u32Temp);

                        if (NULL_PTR != pCtx->tL1AlgCtx.tScatterCMac.pOutSize)
                        {
                            hsm_memcpy(pCtx->tL1AlgCtx.tScatterCMac.pOutSize,
                                       &u32Temp,
                                       sizeof(u32Temp));
                        }
                        else
                        {
                            ;
                        }
                    }
                    else
                    {
                        eRet = HSM_STATUS_HW_ERR;
                    }
                }
                /* else do nothing */

                pCtx->tL1AlgCtx.tScatterCMac.pOut              = NULL_PTR;
                pCtx->tL1AlgCtx.tScatterCMac.u32OutBufSize     = 0;
                pCtx->tL1AlgCtx.tScatterCMac.eOutFmt           = HSM_DATA_FORMAT_4B;
                pCtx->tL1AlgCtx.tScatterCMac.pOutSize          = NULL_PTR;
                pCtx->tL1AlgCtx.tScatterCMac.pInputData        = NULL_PTR;
                pCtx->tL1AlgCtx.tScatterCMac.eInputFmt         = HSM_DATA_FORMAT_4B;
                pCtx->tL1AlgCtx.tScatterCMac.u32InputTotalSize = 0;
                pCtx->tL1AlgCtx.tScatterCMac.u32ProcessedSize  = 0;
            }
            else
            {
                u32Temp = pCtx->tL1AlgCtx.tScatterCMac.u32InputTotalSize -
                          pCtx->tL1AlgCtx.tScatterCMac.u32ProcessedSize;

                if ((pCtx->tL1AlgCtx.tScatterCMac.u32CacheDataByteCnt + u32Temp) <
                    (2 * HSM_AESM_SCATTER_CMAC_HW_PROCESS_ALIGN()))
                {
                    eRet = hsm_1B4B_convert_from_idx(HSM_DATA_FORMAT_4B,
                                                     &(pCtx->tL1AlgCtx.tScatterCMac.aDataBuf[0]),
                                                     pCtx->tL1AlgCtx.tScatterCMac.u32CacheDataByteCnt,
                                                     sizeof(pCtx->tL1AlgCtx.tScatterCMac.aDataBuf),
                                                     pCtx->tL1AlgCtx.tScatterCMac.eInputFmt,
                                                     pCtx->tL1AlgCtx.tScatterCMac.pInputData,
                                                     pCtx->tL1AlgCtx.tScatterCMac.u32ProcessedSize,
                                                     pCtx->tL1AlgCtx.tScatterCMac.u32InputTotalSize);

                    if (HSM_STATUS_SUCCESS == eRet)
                    {
                        pCtx->tL1AlgCtx.tScatterCMac.u32CacheDataByteCnt += u32Temp;

                        pCtx->tL1AlgCtx.tScatterCMac.pInputData        = NULL_PTR;
                        pCtx->tL1AlgCtx.tScatterCMac.eInputFmt         = HSM_DATA_FORMAT_4B;
                        pCtx->tL1AlgCtx.tScatterCMac.u32InputTotalSize = 0;
                        pCtx->tL1AlgCtx.tScatterCMac.u32ProcessedSize =
                            0u; /* has cache all input data */

                        pCtx->tL1AlgCtx.tScatterCMac.pScatterCMacParm->u32HSMStatusRet =
                            MAILBOXAPI_RET_NONE;
                        pCtx->tL1AlgCtx.tScatterCMac.pScatterCMacParm->u32Timeout =
                            pCtx->tL1AlgCtx.tScatterCMac.u32TimeoutMs;

                        pCtx->tL1AlgCtx.tScatterCMac.pScatterCMacParm->tCfg.tCfg.data_len =
                            pCtx->tL1AlgCtx.tScatterCMac.u32CacheDataByteCnt;
                        pCtx->tL1AlgCtx.tScatterCMac.pScatterCMacParm->tCfg.tCfg.in_addr = &(
                            pCtx->tL1AlgCtx.tScatterCMac.aDataBuf[0]);

                        pCtx->tL1AlgCtx.tScatterCMac.u32CacheDataByteCnt = 0u;

                        eRet = hsm_l1_scatter_cmac_final(pCtx, HSM_DATA_FORMAT_4B, HSM_DATA_FORMAT_1B);
                        if (HSM_STATUS_SUCCESS == eRet)
                        {
                            eRet = HSM_STATUS_AGAIN;
                        }
                        /* else do nothing */
                    }
                    else
                    {
                        pCtx->tL1AlgCtx.tScatterCMac.eState = HSM_L1_SCATTER_CMAC_STOP;
                    }
                }
                else
                {
                    u32Temp2 = sizeof(pCtx->tL1AlgCtx.tScatterCMac.aDataBuf) -
                               pCtx->tL1AlgCtx.tScatterCMac.u32CacheDataByteCnt;

                    if (u32Temp2 > u32Temp) /* can cache all data */
                    {
                        eRet = hsm_1B4B_convert_from_idx(
                            HSM_DATA_FORMAT_4B,
                            &(pCtx->tL1AlgCtx.tScatterCMac.aDataBuf[0]),
                            pCtx->tL1AlgCtx.tScatterCMac.u32CacheDataByteCnt,
                            sizeof(pCtx->tL1AlgCtx.tScatterCMac.aDataBuf),
                            pCtx->tL1AlgCtx.tScatterCMac.eInputFmt,
                            pCtx->tL1AlgCtx.tScatterCMac.pInputData,
                            pCtx->tL1AlgCtx.tScatterCMac.u32ProcessedSize,
                            pCtx->tL1AlgCtx.tScatterCMac.u32InputTotalSize);

                        pCtx->tL1AlgCtx.tScatterCMac.u32ProcessedSize += u32Temp;
                        pCtx->tL1AlgCtx.tScatterCMac.u32CacheDataByteCnt += u32Temp;
                    }
                    else
                    {
                        eRet = hsm_1B4B_convert_from_idx(
                            HSM_DATA_FORMAT_4B,
                            &(pCtx->tL1AlgCtx.tScatterCMac.aDataBuf[0]),
                            pCtx->tL1AlgCtx.tScatterCMac.u32CacheDataByteCnt,
                            sizeof(pCtx->tL1AlgCtx.tScatterCMac.aDataBuf),
                            pCtx->tL1AlgCtx.tScatterCMac.eInputFmt,
                            pCtx->tL1AlgCtx.tScatterCMac.pInputData,
                            pCtx->tL1AlgCtx.tScatterCMac.u32ProcessedSize,
                            pCtx->tL1AlgCtx.tScatterCMac.u32ProcessedSize + u32Temp2);

                        pCtx->tL1AlgCtx.tScatterCMac.u32ProcessedSize += u32Temp2;
                        pCtx->tL1AlgCtx.tScatterCMac.u32CacheDataByteCnt += u32Temp2;
                    }

                    pCtx->tL1AlgCtx.tScatterCMac.u32CacheProcByteCnt =
                        (pCtx->tL1AlgCtx.tScatterCMac.u32CacheDataByteCnt /
                         HSM_AESM_SCATTER_CMAC_HW_PROCESS_ALIGN()) *
                        HSM_AESM_SCATTER_CMAC_HW_PROCESS_ALIGN();

                    if (((pCtx->tL1AlgCtx.tScatterCMac.u32CacheDataByteCnt -
                          pCtx->tL1AlgCtx.tScatterCMac.u32CacheProcByteCnt) +
                         (pCtx->tL1AlgCtx.tScatterCMac.u32InputTotalSize -
                          pCtx->tL1AlgCtx.tScatterCMac.u32ProcessedSize)) < 16)
                    {
                        pCtx->tL1AlgCtx.tScatterCMac.u32CacheProcByteCnt -= 16u;
                    }

                    pCtx->tL1AlgCtx.tScatterCMac.pScatterCMacParm->u32HSMStatusRet =
                        MAILBOXAPI_RET_NONE;
                    pCtx->tL1AlgCtx.tScatterCMac.pScatterCMacParm->u32Timeout =
                        pCtx->tL1AlgCtx.tScatterCMac.u32TimeoutMs;

                    pCtx->tL1AlgCtx.tScatterCMac.pScatterCMacParm->tCfg.tCfg.data_len =
                        pCtx->tL1AlgCtx.tScatterCMac.u32CacheProcByteCnt;
                    pCtx->tL1AlgCtx.tScatterCMac.pScatterCMacParm->tCfg.tCfg.in_addr = &(
                        pCtx->tL1AlgCtx.tScatterCMac.aDataBuf[0]);

                    if (HSM_STATUS_SUCCESS == eRet)
                    {
                        eRet = hsm_l1_scatter_cmac_update(pCtx, HSM_DATA_FORMAT_4B, HSM_DATA_FORMAT_1B);
                        if (HSM_STATUS_SUCCESS == eRet)
                        {
                            eRet = HSM_STATUS_AGAIN;
                        }
                        /* else do nothing */
                    }
                    else
                    {
                        pCtx->tL1AlgCtx.tScatterCMac.eState = HSM_L1_SCATTER_CMAC_STOP;
                        eRet                                = HSM_STATUS_ERROR;
                    }
                }
            }
        }
        else
        {
            eRet                                = HSM_STATUS_LOGIC_ERR;
            pCtx->tL1AlgCtx.tScatterCMac.eState = HSM_L1_SCATTER_CMAC_STOP;
            pCtx->eStat                         = HSM_DRV_SM_STOP;
        }
    }
    else
    {
        eRet                                = HSM_STATUS_HW_ERR;
        pCtx->tL1AlgCtx.tScatterCMac.eState = HSM_L1_SCATTER_CMAC_STOP;
        pCtx->eStat                         = HSM_DRV_SM_STOP;
    }

    return eRet;
}

HSM_StatusType HSM_L1_ScatterCMacPoll(HSM_L1_RtCtxType *pCtx)
{
    HSM_StatusType eRet       = HSM_STATUS_SUCCESS;
    HSM_BoolType   bInProcess = HSM_FALSE;

    bInProcess = pCtx->bInProcess;

    if ((HSM_TRUE == bInProcess) && (HSM_OP_SCATTER_CMAC == pCtx->eOperationCata))
    {
        if (HSM_DRV_SM_ARITH == pCtx->eStat)
        {
            eRet = pCtx->pReadAckCb();
            if (HSM_STATUS_BUSY == eRet)
            {
                eRet = HSM_STATUS_AGAIN;
            }
            else if (HSM_STATUS_SUCCESS == eRet)
            {
                eRet = HSM_L1_ScatterCMac_Isr(pCtx);
            }
            else
            {
                pCtx->eStat = HSM_DRV_SM_STOP;
            }
        }
        else
        {
            eRet = HSM_STATUS_HW_IDLE;
        }
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_ScatterCMacExitEnv(HSM_L1_RtCtxType *pCtx)
{
    HSM_BoolType   bInProcess = pCtx->bInProcess;
    HSM_StatusType eRet       = HSM_STATUS_SUCCESS;

    if ((HSM_TRUE == bInProcess) && (HSM_OP_SCATTER_CMAC == pCtx->eOperationCata))
    {
        eRet = HSM_L1_CommonExitEnv(pCtx);
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_EccSignSetupEnv(HSM_L1_RtCtxType *pCtx, hsm_uint32_t u32BitCnt)
{
    HSM_BoolType   bInProcess = HSM_FALSE;
    HSM_StatusType eRet       = HSM_STATUS_SUCCESS;

    if ((u32BitCnt <= 1024) && (u32BitCnt >= 1u))
    {
        bInProcess = pCtx->bInProcess;
        if (HSM_FALSE == bInProcess)
        {
            pCtx->bInProcess                       = HSM_TRUE;
            pCtx->eOperationCata                   = HSM_OP_ECC_SIGN;
            pCtx->tL1AlgCtx.tEccSignInf.u32NBitCnt = u32BitCnt;
            pCtx->eStat                            = HSM_DRV_SM_READY;
            pCtx->tL1AlgCtx.tEccSignInf.pParm      = (HSMCom_EccSignType *)HSM_ADDRESS_UP_ALIGN(
                &(pCtx->tL1AlgCtx.tEccSignInf.aParmBuf[0]));
            pCtx->tL1AlgCtx.tEccSignInf.pParm->tCfg.tCurve.pP =
                (const hsm_uint32_t *)HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tEccSignInf.aP[0]));
            pCtx->tL1AlgCtx.tEccSignInf.pParm->tCfg.tCurve.pN =
                (const hsm_uint32_t *)HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tEccSignInf.aN[0]));
            pCtx->tL1AlgCtx.tEccSignInf.pParm->tCfg.tCurve.pA =
                (const hsm_uint32_t *)HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tEccSignInf.aA[0]));
            pCtx->tL1AlgCtx.tEccSignInf.pParm->tCfg.tCurve.pB =
                (const hsm_uint32_t *)HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tEccSignInf.aB[0]));
            pCtx->tL1AlgCtx.tEccSignInf.pParm->tCfg.tCurve.pGx =
                (const hsm_uint32_t *)HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tEccSignInf.aGx[0]));
            pCtx->tL1AlgCtx.tEccSignInf.pParm->tCfg.tCurve.pGy =
                (const hsm_uint32_t *)HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tEccSignInf.aGy[0]));
            pCtx->tL1AlgCtx.tEccSignInf.pParm->tCfg.pPrivateKey = (const hsm_uint32_t *)
                HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tEccSignInf.aPrivate[0]));
            pCtx->tL1AlgCtx.tEccSignInf.pParm->tCfg.pHashData =
                (const hsm_uint32_t *)HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tEccSignInf.aHash[0]));
            pCtx->tL1AlgCtx.tEccSignInf.pParm->tCfg.pR = (hsm_uint32_t *)HSM_ADDRESS_UP_ALIGN(
                &(pCtx->tL1AlgCtx.tEccSignInf.aR[0]));
            pCtx->tL1AlgCtx.tEccSignInf.pParm->tCfg.pS = (hsm_uint32_t *)HSM_ADDRESS_UP_ALIGN(
                &(pCtx->tL1AlgCtx.tEccSignInf.aS[0]));

            eRet = HSM_STATUS_SUCCESS;
        }
        else
        {
            eRet = HSM_STATUS_LOGIC_ERR;
        }
    }
    else
    {
        eRet = HSM_STATUS_PARAM_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_EccSignExitEnv(HSM_L1_RtCtxType *pCtx)
{
    HSM_BoolType   bInProcess = pCtx->bInProcess;
    HSM_StatusType eRet       = HSM_STATUS_SUCCESS;

    if ((HSM_TRUE == bInProcess) && (HSM_OP_ECC_SIGN == pCtx->eOperationCata))
    {
        eRet = HSM_L1_CommonExitEnv(pCtx);
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}

/* For interrupt usage */
HSM_StatusType HSM_L1_EccSign(HSM_L1_RtCtxType         *pCtx,
                              const HSM_Ln_EccSignType *pCfg,
                              hsm_uint32_t              u32TimeoutMs)
{
    hsm_uint32_t       u32NByteCnt;
    HSM_StatusType     eRet       = HSM_STATUS_SUCCESS;
    HSM_BoolType       bInProcess = HSM_FALSE;
    const hsm_uint8_t *pStart;
    hsm_uint32_t       u32ActualSize;

    if ((NULL_PTR != pCtx) && (NULL_PTR != pCfg))
    {
        bInProcess = pCtx->bInProcess;

        if ((HSM_TRUE == bInProcess) && (HSM_OP_ECC_SIGN == pCtx->eOperationCata))
        {
            u32NByteCnt = ((pCtx->tL1AlgCtx.tEccSignInf.u32NBitCnt + 7u) / 8u);

            if (HSM_DATA_FORMAT_1B == pCfg->eDataFmt)
            {
                if (pCfg->u32RBufByteCnt < u32NByteCnt)
                {
                    eRet = HSM_STATUS_PARAM_ERR;
                }
                /* else do nothing */

                if (pCfg->u32SBufByteCnt < u32NByteCnt)
                {
                    eRet = HSM_STATUS_PARAM_ERR;
                }
                /* else do nothing */
            }
            else
            {
                u32NByteCnt = (((u32NByteCnt + 3u) / 4u) * 4u);

                if (pCfg->u32RBufByteCnt < u32NByteCnt)
                {
                    eRet = HSM_STATUS_PARAM_ERR;
                }
                /* else do nothing */

                if (pCfg->u32SBufByteCnt < u32NByteCnt)
                {
                    eRet = HSM_STATUS_PARAM_ERR;
                }
                /* else do nothing */
            }

            if (HSM_STATUS_SUCCESS == eRet)
            {
                if (HSM_DRV_SM_ARITH != pCtx->eStat)
                {
                    u32NByteCnt = ((pCtx->tL1AlgCtx.tEccSignInf.u32NBitCnt + 63u) / 64u) * 8u;

                    pCtx->tL1AlgCtx.tEccSignInf.pParm->u32HSMStatusRet = MAILBOXAPI_RET_NONE;
                    pCtx->tL1AlgCtx.tEccSignInf.pParm->u32Timeout      = u32TimeoutMs;
                    pCtx->tL1AlgCtx.tEccSignInf.pParm->u32UserKeyID_PrivateKey = pCfg->u32PrivateKeyId;
                    pCtx->tL1AlgCtx.tEccSignInf.pParm->u32BitCnt =
                        pCtx->tL1AlgCtx.tEccSignInf.u32NBitCnt;
                    pCtx->tL1AlgCtx.tEccSignInf.pParm->u32EccCurve       = pCfg->u32EccCurve;
                    pCtx->tL1AlgCtx.tEccSignInf.pParm->tCfg.u32ByteCount = u32NByteCnt;

                    pCtx->tL1AlgCtx.tEccSignInf.eOutFmt        = pCfg->eDataFmt;
                    pCtx->tL1AlgCtx.tEccSignInf.pR             = pCfg->pR;
                    pCtx->tL1AlgCtx.tEccSignInf.u32RBufByteCnt = pCfg->u32RBufByteCnt;
                    pCtx->tL1AlgCtx.tEccSignInf.pS             = pCfg->pS;
                    pCtx->tL1AlgCtx.tEccSignInf.u32SBufByteCnt = pCfg->u32SBufByteCnt;

                    if (HSM_DRV_ECC_CURVE_PRM_IDX_MAX <= pCfg->u32EccCurve)
                    {
                        hsm_rm_prefix_zeros(pCfg->eDataFmt,
                                            pCfg->tCurve.pP,
                                            pCfg->tCurve.u32PByteCnt,
                                            &pStart,
                                            &u32ActualSize);
                        hsm_memset((void *)HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tEccSignInf.aP[0])),
                                   0,
                                   u32NByteCnt - u32ActualSize);
                        hsm_memcpy(((hsm_uint8_t *)HSM_ADDRESS_UP_ALIGN(
                                       &(pCtx->tL1AlgCtx.tEccSignInf.aP[0]))) +
                                       (u32NByteCnt - u32ActualSize),
                                   pStart,
                                   u32ActualSize);

                        hsm_rm_prefix_zeros(pCfg->eDataFmt,
                                            pCfg->tCurve.pN,
                                            pCfg->tCurve.u32NByteCnt,
                                            &pStart,
                                            &u32ActualSize);
                        hsm_memset((void *)HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tEccSignInf.aN[0])),
                                   0,
                                   u32NByteCnt - u32ActualSize);
                        hsm_memcpy(((hsm_uint8_t *)HSM_ADDRESS_UP_ALIGN(
                                       &(pCtx->tL1AlgCtx.tEccSignInf.aN[0]))) +
                                       (u32NByteCnt - u32ActualSize),
                                   pStart,
                                   u32ActualSize);

                        hsm_rm_prefix_zeros(pCfg->eDataFmt,
                                            pCfg->tCurve.pA,
                                            pCfg->tCurve.u32AByteCnt,
                                            &pStart,
                                            &u32ActualSize);
                        hsm_memset((void *)HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tEccSignInf.aA[0])),
                                   0,
                                   u32NByteCnt - u32ActualSize);
                        hsm_memcpy(((hsm_uint8_t *)HSM_ADDRESS_UP_ALIGN(
                                       &(pCtx->tL1AlgCtx.tEccSignInf.aA[0]))) +
                                       (u32NByteCnt - u32ActualSize),
                                   pStart,
                                   u32ActualSize);

                        hsm_rm_prefix_zeros(pCfg->eDataFmt,
                                            pCfg->tCurve.pB,
                                            pCfg->tCurve.u32BByteCnt,
                                            &pStart,
                                            &u32ActualSize);
                        hsm_memset((void *)HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tEccSignInf.aB[0])),
                                   0,
                                   u32NByteCnt - u32ActualSize);
                        hsm_memcpy(((hsm_uint8_t *)HSM_ADDRESS_UP_ALIGN(
                                       &(pCtx->tL1AlgCtx.tEccSignInf.aB[0]))) +
                                       (u32NByteCnt - u32ActualSize),
                                   pStart,
                                   u32ActualSize);

                        hsm_rm_prefix_zeros(pCfg->eDataFmt,
                                            pCfg->tCurve.pGx,
                                            pCfg->tCurve.u32GxByteCnt,
                                            &pStart,
                                            &u32ActualSize);
                        hsm_memset((void *)HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tEccSignInf.aGx[0])),
                                   0,
                                   u32NByteCnt - u32ActualSize);
                        hsm_memcpy(((hsm_uint8_t *)HSM_ADDRESS_UP_ALIGN(
                                       &(pCtx->tL1AlgCtx.tEccSignInf.aGx[0]))) +
                                       (u32NByteCnt - u32ActualSize),
                                   pStart,
                                   u32ActualSize);

                        hsm_rm_prefix_zeros(pCfg->eDataFmt,
                                            pCfg->tCurve.pGy,
                                            pCfg->tCurve.u32GyByteCnt,
                                            &pStart,
                                            &u32ActualSize);
                        hsm_memset((void *)HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tEccSignInf.aGy[0])),
                                   0,
                                   u32NByteCnt - u32ActualSize);
                        hsm_memcpy(((hsm_uint8_t *)HSM_ADDRESS_UP_ALIGN(
                                       &(pCtx->tL1AlgCtx.tEccSignInf.aGy[0]))) +
                                       (u32NByteCnt - u32ActualSize),
                                   pStart,
                                   u32ActualSize);

                        if (HSM_DATA_FORMAT_1B == pCfg->eDataFmt)
                        {
                            hsm_u32_array_swap((hsm_uint32_t *)HSM_ADDRESS_UP_ALIGN(
                                                   &(pCtx->tL1AlgCtx.tEccSignInf.aP[0])),
                                               u32NByteCnt / 4U);
                            hsm_u32_array_swap((hsm_uint32_t *)HSM_ADDRESS_UP_ALIGN(
                                                   &(pCtx->tL1AlgCtx.tEccSignInf.aN[0])),
                                               u32NByteCnt / 4U);
                            hsm_u32_array_swap((hsm_uint32_t *)HSM_ADDRESS_UP_ALIGN(
                                                   &(pCtx->tL1AlgCtx.tEccSignInf.aA[0])),
                                               u32NByteCnt / 4U);
                            hsm_u32_array_swap((hsm_uint32_t *)HSM_ADDRESS_UP_ALIGN(
                                                   &(pCtx->tL1AlgCtx.tEccSignInf.aB[0])),
                                               u32NByteCnt / 4U);
                            hsm_u32_array_swap((hsm_uint32_t *)HSM_ADDRESS_UP_ALIGN(
                                                   &(pCtx->tL1AlgCtx.tEccSignInf.aGx[0])),
                                               u32NByteCnt / 4U);
                            hsm_u32_array_swap((hsm_uint32_t *)HSM_ADDRESS_UP_ALIGN(
                                                   &(pCtx->tL1AlgCtx.tEccSignInf.aGy[0])),
                                               u32NByteCnt / 4U);
                        }
                        else
                        {
                            ;
                        }
                    }
                    else
                    {
                        ;
                    }

                    if (0u == pCfg->u32PrivateKeyId)
                    {
                        hsm_rm_prefix_zeros(pCfg->eDataFmt,
                                            pCfg->pPrivate,
                                            pCfg->u32PrivateByteCnt,
                                            &pStart,
                                            &u32ActualSize);
                        hsm_memset(
                            (void *)HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tEccSignInf.aPrivate[0])),
                            0,
                            u32NByteCnt - u32ActualSize);
                        hsm_memcpy(((hsm_uint8_t *)HSM_ADDRESS_UP_ALIGN(
                                       &(pCtx->tL1AlgCtx.tEccSignInf.aPrivate[0]))) +
                                       (u32NByteCnt - u32ActualSize),
                                   pStart,
                                   u32ActualSize);

                        if (HSM_DATA_FORMAT_1B == pCfg->eDataFmt)
                        {
                            hsm_u32_array_swap((hsm_uint32_t *)HSM_ADDRESS_UP_ALIGN(
                                                   &(pCtx->tL1AlgCtx.tEccSignInf.aPrivate[0])),
                                               u32NByteCnt / 4U);
                        }
                        else
                        {
                            ;
                        }
                    }
                    else
                    {
                        ;
                    }

                    hsm_rm_prefix_zeros(pCfg->eDataFmt,
                                        pCfg->pHashData,
                                        pCfg->u32HashDataByteCnt,
                                        &pStart,
                                        &u32ActualSize);
                    hsm_memset((void *)HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tEccSignInf.aHash[0])),
                               0,
                               u32NByteCnt - u32ActualSize);
                    hsm_memcpy(((hsm_uint8_t *)HSM_ADDRESS_UP_ALIGN(
                                   &(pCtx->tL1AlgCtx.tEccSignInf.aHash[0]))) +
                                   (u32NByteCnt - u32ActualSize),
                               pStart,
                               u32ActualSize);
                    if (HSM_DATA_FORMAT_1B == pCfg->eDataFmt)
                    {
                        hsm_u32_array_swap((hsm_uint32_t *)HSM_ADDRESS_UP_ALIGN(
                                               &(pCtx->tL1AlgCtx.tEccSignInf.aHash[0])),
                                           u32NByteCnt / 4U);
                    }
                    else
                    {
                        ;
                    }

                    eRet = HSM_FW_EccSign(&(pCtx->tCmd), pCtx->tL1AlgCtx.tEccSignInf.pParm);
                    if (HSM_STATUS_SUCCESS == eRet)
                    {
                        pCtx->eStat = HSM_DRV_SM_ARITH;
                        eRet        = pCtx->pSendCmdCb(&(pCtx->tCmd));
                        if (HSM_STATUS_SUCCESS != eRet)
                        {
                            pCtx->eStat = HSM_DRV_SM_STOP;
                            eRet        = HSM_STATUS_SEND_FAIL;
                        }
                    }
                    else
                    {
                        ;
                    }
                }
                else
                {
                    eRet = HSM_STATUS_BUSY;
                }
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
        eRet = HSM_STATUS_PARAM_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_EccSign_Isr(HSM_L1_RtCtxType *pCtx)
{
    HSM_StatusType     eRet;
    hsm_uint32_t       u32OutSize;
    const hsm_uint8_t *pStart;
    hsm_uint32_t       u32ActualSize;

    if (MAILBOXAPI_RET_SUCCESS == pCtx->tL1AlgCtx.tEccSignInf.pParm->u32HSMStatusRet)
    {
        eRet = HSM_STATUS_SUCCESS;

        if (HSM_DATA_FORMAT_1B == pCtx->tL1AlgCtx.tEccSignInf.eOutFmt)
        {
            hsm_u32_array_swap(
                (hsm_uint32_t *)HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tEccSignInf.aR[0])),
                pCtx->tL1AlgCtx.tEccSignInf.pParm->tCfg.u32ByteCount / 4U);
            hsm_u32_array_swap(
                (hsm_uint32_t *)HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tEccSignInf.aS[0])),
                pCtx->tL1AlgCtx.tEccSignInf.pParm->tCfg.u32ByteCount / 4U);
        }

        hsm_rm_prefix_zeros(
            pCtx->tL1AlgCtx.tEccSignInf.eOutFmt,
            (const hsm_uint8_t *)HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tEccSignInf.aR[0])),
            pCtx->tL1AlgCtx.tEccSignInf.pParm->tCfg.u32ByteCount,
            &pStart,
            &u32ActualSize);

        if (HSM_DATA_FORMAT_1B == pCtx->tL1AlgCtx.tEccSignInf.eOutFmt)
        {
            u32OutSize = ((pCtx->tL1AlgCtx.tEccSignInf.u32NBitCnt + 7u) / 8u);

            if (u32ActualSize <= u32OutSize)
            {
                hsm_memcpy(pCtx->tL1AlgCtx.tEccSignInf.pR,
                           ((hsm_uint8_t *)HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tEccSignInf.aR[0]))) +
                               pCtx->tL1AlgCtx.tEccSignInf.pParm->tCfg.u32ByteCount - u32OutSize,
                           u32OutSize);
            }
            else
            {
                eRet = HSM_STATUS_ERROR;
            }
        }
        else
        {
            u32OutSize = ((pCtx->tL1AlgCtx.tEccSignInf.u32NBitCnt + 31u) / 32u) * 4u;

            if (u32ActualSize <= u32OutSize)
            {
                hsm_memcpy(pCtx->tL1AlgCtx.tEccSignInf.pR,
                           ((hsm_uint8_t *)HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tEccSignInf.aR[0]))) +
                               pCtx->tL1AlgCtx.tEccSignInf.pParm->tCfg.u32ByteCount - u32OutSize,
                           u32OutSize);
            }
            else
            {
                eRet = HSM_STATUS_ERROR;
            }
        }

        hsm_rm_prefix_zeros(
            pCtx->tL1AlgCtx.tEccSignInf.eOutFmt,
            (const hsm_uint8_t *)HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tEccSignInf.aS[0])),
            pCtx->tL1AlgCtx.tEccSignInf.pParm->tCfg.u32ByteCount,
            &pStart,
            &u32ActualSize);

        if (HSM_DATA_FORMAT_1B == pCtx->tL1AlgCtx.tEccSignInf.eOutFmt)
        {
            u32OutSize = ((pCtx->tL1AlgCtx.tEccSignInf.u32NBitCnt + 7u) / 8u);

            if (u32ActualSize <= u32OutSize)
            {
                hsm_memcpy(pCtx->tL1AlgCtx.tEccSignInf.pS,
                           ((hsm_uint8_t *)HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tEccSignInf.aS[0]))) +
                               pCtx->tL1AlgCtx.tEccSignInf.pParm->tCfg.u32ByteCount - u32OutSize,
                           u32OutSize);
            }
            else
            {
                eRet = HSM_STATUS_ERROR;
            }
        }
        else
        {
            u32OutSize = ((pCtx->tL1AlgCtx.tEccSignInf.u32NBitCnt + 31u) / 32u) * 4u;

            if (u32ActualSize <= u32OutSize)
            {
                hsm_memcpy(pCtx->tL1AlgCtx.tEccSignInf.pS,
                           ((hsm_uint8_t *)HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tEccSignInf.aS[0]))) +
                               pCtx->tL1AlgCtx.tEccSignInf.pParm->tCfg.u32ByteCount - u32OutSize,
                           u32OutSize);
            }
            else
            {
                eRet = HSM_STATUS_ERROR;
            }
        }

        pCtx->eStat = HSM_DRV_SM_STOP;
    }
    else
    {
        eRet        = HSM_STATUS_ERROR;
        pCtx->eStat = HSM_DRV_SM_STOP;
    }

    return eRet;
}

HSM_StatusType HSM_L1_EccSignPoll(HSM_L1_RtCtxType *pCtx)
{
    HSM_StatusType eRet       = HSM_STATUS_SUCCESS;
    HSM_BoolType   bInProcess = HSM_FALSE;

    bInProcess = pCtx->bInProcess;

    if ((HSM_TRUE == bInProcess) && (HSM_OP_ECC_SIGN == pCtx->eOperationCata))
    {
        if (HSM_DRV_SM_ARITH == pCtx->eStat)
        {
            eRet = pCtx->pReadAckCb();
            if (HSM_STATUS_BUSY == eRet)
            {
                eRet = HSM_STATUS_AGAIN;
            }
            else if (HSM_STATUS_SUCCESS == eRet)
            {
                eRet = HSM_L1_EccSign_Isr(pCtx);
            }
            else
            {
                pCtx->eStat = HSM_DRV_SM_STOP;
            }
        }
        else
        {
            eRet = HSM_STATUS_HW_IDLE;
        }
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_EccSignReset(HSM_L1_RtCtxType *pCtx)
{
    HSM_BoolType   bInProcess = HSM_FALSE;
    HSM_StatusType eRet       = HSM_STATUS_SUCCESS;

    bInProcess = pCtx->bInProcess;

    if ((HSM_TRUE == bInProcess) && (HSM_OP_ECC_SIGN == pCtx->eOperationCata))
    {
        if (HSM_DRV_SM_ARITH == pCtx->eStat)
        {
            eRet = pCtx->pCancelCmdCb();
        }

        if (HSM_STATUS_SUCCESS == eRet)
        {
            pCtx->eStat = HSM_DRV_SM_READY;
        }
        else
        {
            ;
        }
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_RsaSsaPssVerifySetupEnv(HSM_L1_RtCtxType *pCtx, hsm_uint32_t u32RsaBitCnt)
{
    HSM_BoolType   bInProcess = HSM_FALSE;
    HSM_StatusType eRet       = HSM_STATUS_SUCCESS;

    if ((u32RsaBitCnt <= 4096) && (u32RsaBitCnt >= 1u))
    {
        bInProcess = pCtx->bInProcess;
        if (HSM_FALSE == bInProcess)
        {
            pCtx->bInProcess                           = HSM_TRUE;
            pCtx->eOperationCata                       = HSM_OP_RSA_SSA_PSS_VERIFY;
            pCtx->tL1AlgCtx.tRsaSsaPssVerify.u32BitCnt = u32RsaBitCnt;
            pCtx->eStat                                = HSM_DRV_SM_READY;
            pCtx->tL1AlgCtx.tRsaSsaPssVerify.pParm     = (HSMCom_RsaSsaPssVerifyType *)
                HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tRsaSsaPssVerify.aParmBuf[0]));

            eRet = HSM_STATUS_SUCCESS;
        }
        else
        {
            eRet = HSM_STATUS_LOGIC_ERR;
        }
    }
    else
    {
        eRet = HSM_STATUS_PARAM_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_RsaSsaPssVerify(HSM_L1_RtCtxType                 *pCtx,
                                      const HSM_Ln_RsaSsaPssVerifyType *pCfg,
                                      hsm_uint32_t                      u32TimeoutMs)
{
    HSM_StatusType eRet = HSM_STATUS_SUCCESS;
    HSM_BoolType   bInProcess;
    hsm_uint32_t   u32HashLen;

    if ((NULL_PTR != pCtx) && (NULL_PTR != pCfg) &&
        (HSM_STATUS_SUCCESS ==
         hsm_hash_get_result_byte_count((HFAM_MODE_E)pCfg->eHashType, &u32HashLen)) &&
        (HSM_STATUS_SUCCESS ==
         hsm_hash_get_result_byte_count((HFAM_MODE_E)pCfg->eMgfHashType, NULL_PTR)) &&
        (((pCfg->u32EmBitCnt + 7u) >> 3u) >= (u32HashLen + pCfg->u32SaltByteCount + 2)))
    {
        bInProcess = pCtx->bInProcess;

        if ((HSM_TRUE == bInProcess) && (HSM_OP_RSA_SSA_PSS_VERIFY == pCtx->eOperationCata))
        {
            if (HSM_DRV_SM_ARITH != pCtx->eStat)
            {
                pCtx->tL1AlgCtx.tRsaSsaPssVerify.pParm->u32HSMStatusRet    = MAILBOXAPI_RET_NONE;
                pCtx->tL1AlgCtx.tRsaSsaPssVerify.pParm->u32Timeout         = u32TimeoutMs;
                pCtx->tL1AlgCtx.tRsaSsaPssVerify.pParm->u32UserKeyID_KEY_E = pCfg->u32KeyEId;
                pCtx->tL1AlgCtx.tRsaSsaPssVerify.pParm->u32UserKeyID_KEY_N = pCfg->u32KeyNId;
                pCtx->tL1AlgCtx.tRsaSsaPssVerify.pParm->u32RsaBitCnt =
                    pCtx->tL1AlgCtx.tRsaSsaPssVerify.u32BitCnt;
                pCtx->tL1AlgCtx.tRsaSsaPssVerify.pParm->tCfg.u32EmBitCnt  = pCfg->u32EmBitCnt;
                pCtx->tL1AlgCtx.tRsaSsaPssVerify.pParm->tCfg.eMgfHashType = pCfg->eMgfHashType;
                pCtx->tL1AlgCtx.tRsaSsaPssVerify.pParm->tCfg.eHashType    = pCfg->eHashType;
                pCtx->tL1AlgCtx.tRsaSsaPssVerify.pParm->tCfg.u32SaltByteCount = pCfg->u32SaltByteCount;
                pCtx->tL1AlgCtx.tRsaSsaPssVerify.pParm->tCfg.eInputDataFmt = pCfg->eInputDataFmt;
                pCtx->tL1AlgCtx.tRsaSsaPssVerify.pParm->tCfg.eInputType    = pCfg->eInputType;
                pCtx->tL1AlgCtx.tRsaSsaPssVerify.pParm->tCfg.pInputData    = pCfg->pInputData;
                pCtx->tL1AlgCtx.tRsaSsaPssVerify.pParm->tCfg.u32InputDataByteCount =
                    pCfg->u32InputDataByteCount;
                pCtx->tL1AlgCtx.tRsaSsaPssVerify.pParm->tCfg.eSignDataFmt = pCfg->eSignDataFmt;
                pCtx->tL1AlgCtx.tRsaSsaPssVerify.pParm->tCfg.pSignData    = pCfg->pSignData;
                pCtx->tL1AlgCtx.tRsaSsaPssVerify.pParm->tCfg.u32SignDataByteCount =
                    pCfg->u32SignDataByteCount;
                pCtx->tL1AlgCtx.tRsaSsaPssVerify.pParm->tCfg.ePublicKeyDataFmt =
                    pCfg->ePublicKeyDataFmt;
                pCtx->tL1AlgCtx.tRsaSsaPssVerify.pParm->tCfg.pPublicKey = pCfg->pPublicKey;
                pCtx->tL1AlgCtx.tRsaSsaPssVerify.pParm->tCfg.u32PublicKeyByteCnt =
                    pCfg->u32PublicKeyByteCnt;
                pCtx->tL1AlgCtx.tRsaSsaPssVerify.pParm->tCfg.eKeyNDataFmt = pCfg->eKeyNDataFmt;
                pCtx->tL1AlgCtx.tRsaSsaPssVerify.pParm->tCfg.pKeyN        = pCfg->pKeyN;
                pCtx->tL1AlgCtx.tRsaSsaPssVerify.pParm->tCfg.u32KeyNByteCount = pCfg->u32KeyNByteCount;
                pCtx->tL1AlgCtx.tRsaSsaPssVerify.pVerifyResult = pCfg->pVerifyResult;

                eRet = HSM_FW_RsaSsaPssVerify(&(pCtx->tCmd), pCtx->tL1AlgCtx.tRsaSsaPssVerify.pParm);
                if (HSM_STATUS_SUCCESS == eRet)
                {
                    pCtx->eStat = HSM_DRV_SM_ARITH;
                    eRet        = pCtx->pSendCmdCb(&(pCtx->tCmd));
                    if (HSM_STATUS_SUCCESS != eRet)
                    {
                        pCtx->eStat = HSM_DRV_SM_STOP;
                        eRet        = HSM_STATUS_SEND_FAIL;
                    }
                }
                else
                {
                    ;
                }
            }
            else
            {
                eRet = HSM_STATUS_BUSY;
            }
        }
        else
        {
            eRet = HSM_STATUS_LOGIC_ERR;
        }
    }
    else
    {
        eRet = HSM_STATUS_PARAM_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_RsaSsaPssVerifyPoll(HSM_L1_RtCtxType *pCtx)
{
    HSM_StatusType eRet = HSM_STATUS_SUCCESS;
    HSM_BoolType   bInProcess;

    bInProcess = pCtx->bInProcess;

    if ((HSM_TRUE == bInProcess) && (HSM_OP_RSA_SSA_PSS_VERIFY == pCtx->eOperationCata))
    {
        if (HSM_DRV_SM_ARITH == pCtx->eStat)
        {
            eRet = pCtx->pReadAckCb();
            if (HSM_STATUS_BUSY == eRet)
            {
                eRet = HSM_STATUS_AGAIN;
            }
            else if (HSM_STATUS_SUCCESS == eRet)
            {
                eRet = HSM_L1_RsaSsaPssVerify_Isr(pCtx);
            }
            else
            {
                pCtx->eStat = HSM_DRV_SM_STOP;
            }
        }
        else
        {
            eRet = HSM_STATUS_HW_IDLE;
        }
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_RsaSsaPssVerifyReset(HSM_L1_RtCtxType *pCtx)
{
    HSM_BoolType   bInProcess;
    HSM_StatusType eRet = HSM_STATUS_SUCCESS;

    bInProcess = pCtx->bInProcess;

    if ((HSM_TRUE == bInProcess) && (HSM_OP_RSA_SSA_PSS_VERIFY == pCtx->eOperationCata))
    {
        if (HSM_DRV_SM_ARITH == pCtx->eStat)
        {
            eRet = pCtx->pCancelCmdCb();
        }

        if (HSM_STATUS_SUCCESS == eRet)
        {
            pCtx->eStat = HSM_DRV_SM_READY;
        }
        else
        {
            ;
        }
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_RsaSsaPssVerify_Isr(HSM_L1_RtCtxType *pCtx)
{
    HSM_StatusType eRet;

    if (MAILBOXAPI_RET_PASS == pCtx->tL1AlgCtx.tRsaSsaPssVerify.pParm->u32HSMStatusRet)
    {
        eRet = HSM_STATUS_PASS;

        if (NULL_PTR != pCtx->tL1AlgCtx.tRsaSsaPssVerify.pVerifyResult)
        {
            *pCtx->tL1AlgCtx.tRsaSsaPssVerify.pVerifyResult = CRYPTO_E_VER_OK;
        }

        pCtx->eStat = HSM_DRV_SM_STOP;
    }
    else if (MAILBOXAPI_RET_FAIL == pCtx->tL1AlgCtx.tRsaSsaPssVerify.pParm->u32HSMStatusRet)
    {
        eRet = HSM_STATUS_FAIL;

        if (NULL_PTR != pCtx->tL1AlgCtx.tRsaSsaPssVerify.pVerifyResult)
        {
            *pCtx->tL1AlgCtx.tRsaSsaPssVerify.pVerifyResult = CRYPTO_E_VER_NOT_OK;
        }

        pCtx->eStat = HSM_DRV_SM_STOP;
    }
    else
    {
        eRet = HSM_STATUS_ERROR;

        if (NULL_PTR != pCtx->tL1AlgCtx.tRsaSsaPssVerify.pVerifyResult)
        {
            *pCtx->tL1AlgCtx.tRsaSsaPssVerify.pVerifyResult = CRYPTO_E_VER_NOT_OK;
        }

        pCtx->eStat = HSM_DRV_SM_STOP;
    }

    return eRet;
}

HSM_StatusType HSM_L1_RsaSsaPssVerifyExitEnv(HSM_L1_RtCtxType *pCtx)
{
    HSM_BoolType   bInProcess = pCtx->bInProcess;
    HSM_StatusType eRet;

    if ((HSM_TRUE == bInProcess) && (HSM_OP_RSA_SSA_PSS_VERIFY == pCtx->eOperationCata))
    {
        eRet = HSM_L1_CommonExitEnv(pCtx);
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_RsaSsaPkcs1V15VerifySetupEnv(HSM_L1_RtCtxType *pCtx, hsm_uint32_t u32RsaBitCnt)
{
    HSM_BoolType   bInProcess = HSM_FALSE;
    HSM_StatusType eRet       = HSM_STATUS_SUCCESS;

    if ((u32RsaBitCnt <= 4096u) && (u32RsaBitCnt >= 1u))
    {
        bInProcess = pCtx->bInProcess;
        if (HSM_FALSE == bInProcess)
        {
            pCtx->bInProcess                                = HSM_TRUE;
            pCtx->eOperationCata                            = HSM_OP_RSA_SSA_PKCS1V15_VERIFY;
            pCtx->tL1AlgCtx.tRsaSsaPkcs1V15Verify.u32BitCnt = u32RsaBitCnt;
            pCtx->eStat                                     = HSM_DRV_SM_READY;
            pCtx->tL1AlgCtx.tRsaSsaPkcs1V15Verify.pParm     = (HSMCom_RsaSsaPkcs1V15VerifyType *)
                HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tRsaSsaPkcs1V15Verify.aParmBuf[0]));

            eRet = HSM_STATUS_SUCCESS;
        }
        else
        {
            eRet = HSM_STATUS_LOGIC_ERR;
        }
    }
    else
    {
        eRet = HSM_STATUS_PARAM_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_RsaSsaPkcs1V15Verify(HSM_L1_RtCtxType                      *pCtx,
                                           const HSM_Ln_RsaSsaPkcs1v15VerifyType *pCfg,
                                           hsm_uint32_t                           u32TimeoutMs)
{
    HSM_StatusType eRet = HSM_STATUS_SUCCESS;
    HSM_BoolType   bInProcess;
    hsm_uint32_t   u32HashLen;

    if ((NULL_PTR != pCtx) && (NULL_PTR != pCfg) &&
        (HSM_STATUS_SUCCESS ==
         hsm_hash_get_result_byte_count((HFAM_MODE_E)pCfg->eHashType, &u32HashLen)))
    {
        bInProcess = pCtx->bInProcess;

        if ((HSM_TRUE == bInProcess) && (HSM_OP_RSA_SSA_PKCS1V15_VERIFY == pCtx->eOperationCata))
        {
            if (HSM_DRV_SM_ARITH != pCtx->eStat)
            {
                pCtx->tL1AlgCtx.tRsaSsaPkcs1V15Verify.pParm->u32HSMStatusRet = MAILBOXAPI_RET_NONE;
                pCtx->tL1AlgCtx.tRsaSsaPkcs1V15Verify.pParm->u32Timeout      = u32TimeoutMs;
                pCtx->tL1AlgCtx.tRsaSsaPkcs1V15Verify.pParm->u32UserKeyID_KEY_E = pCfg->u32KeyEId;
                pCtx->tL1AlgCtx.tRsaSsaPkcs1V15Verify.pParm->u32UserKeyID_KEY_N = pCfg->u32KeyNId;
                pCtx->tL1AlgCtx.tRsaSsaPkcs1V15Verify.pParm->u32RsaBitCnt =
                    pCtx->tL1AlgCtx.tRsaSsaPkcs1V15Verify.u32BitCnt;
                pCtx->tL1AlgCtx.tRsaSsaPkcs1V15Verify.pParm->tCfg.eInputFmt = pCfg->eInputDataFmt;
                pCtx->tL1AlgCtx.tRsaSsaPkcs1V15Verify.pParm->tCfg.u32EmByteCnt = pCfg->u32EmByteCnt;
                pCtx->tL1AlgCtx.tRsaSsaPkcs1V15Verify.pParm->tCfg.eHashType    = pCfg->eHashType;
                pCtx->tL1AlgCtx.tRsaSsaPkcs1V15Verify.pParm->tCfg.pInputData   = pCfg->pInputData;
                pCtx->tL1AlgCtx.tRsaSsaPkcs1V15Verify.pParm->tCfg.u32InputDataByteCount =
                    pCfg->u32InputDataByteCount;
                pCtx->tL1AlgCtx.tRsaSsaPkcs1V15Verify.pParm->tCfg.pSignData = pCfg->pSignData;
                pCtx->tL1AlgCtx.tRsaSsaPkcs1V15Verify.pParm->tCfg.u32SignDataByteCount =
                    pCfg->u32SignDataByteCount;
                pCtx->tL1AlgCtx.tRsaSsaPkcs1V15Verify.pParm->tCfg.pPublicKey = pCfg->pPublicKey;
                pCtx->tL1AlgCtx.tRsaSsaPkcs1V15Verify.pParm->tCfg.u32PublicKeyByteCnt =
                    pCfg->u32PublicKeyByteCnt;
                pCtx->tL1AlgCtx.tRsaSsaPkcs1V15Verify.pParm->tCfg.bUseInputDer = pCfg->bUseInputDer;
                pCtx->tL1AlgCtx.tRsaSsaPkcs1V15Verify.pParm->tCfg.pDer         = pCfg->pDer;
                pCtx->tL1AlgCtx.tRsaSsaPkcs1V15Verify.pParm->tCfg.u32DerByteCount =
                    pCfg->u32DerByteCount;
                pCtx->tL1AlgCtx.tRsaSsaPkcs1V15Verify.pParm->tCfg.pKeyN = pCfg->pKeyN;
                pCtx->tL1AlgCtx.tRsaSsaPkcs1V15Verify.pParm->tCfg.u32KeyNByteCount =
                    pCfg->u32KeyNByteCount;
                pCtx->tL1AlgCtx.tRsaSsaPkcs1V15Verify.pParm->tCfg.eInputType =
                    HSM_RSA_SSA_INPUT_RAW_MESSAGE;
                pCtx->tL1AlgCtx.tRsaSsaPkcs1V15Verify.pParm->tCfg.eSignDataFmt = pCfg->eSignDataFmt;
                pCtx->tL1AlgCtx.tRsaSsaPkcs1V15Verify.pParm->tCfg.ePublicKeyFmt = pCfg->ePublicKeyFmt;
                pCtx->tL1AlgCtx.tRsaSsaPkcs1V15Verify.pParm->tCfg.eKeyNFmt = pCfg->eKeyNFmt;
                pCtx->tL1AlgCtx.tRsaSsaPkcs1V15Verify.pVerifyResult        = pCfg->pVerifyResult;

                eRet = HSM_FW_RsaSsaPkcs1v15Verify(&(pCtx->tCmd),
                                                   pCtx->tL1AlgCtx.tRsaSsaPkcs1V15Verify.pParm);
                if (HSM_STATUS_SUCCESS == eRet)
                {
                    pCtx->eStat = HSM_DRV_SM_ARITH;
                    eRet        = pCtx->pSendCmdCb(&(pCtx->tCmd));
                    if (HSM_STATUS_SUCCESS != eRet)
                    {
                        pCtx->eStat = HSM_DRV_SM_STOP;
                        eRet        = HSM_STATUS_SEND_FAIL;
                    }
                }
                else
                {
                    ;
                }
            }
            else
            {
                eRet = HSM_STATUS_BUSY;
            }
        }
        else
        {
            eRet = HSM_STATUS_LOGIC_ERR;
        }
    }
    else
    {
        eRet = HSM_STATUS_PARAM_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_RsaSsaPkcs1V15VerifyPoll(HSM_L1_RtCtxType *pCtx)
{
    HSM_StatusType eRet = HSM_STATUS_SUCCESS;
    HSM_BoolType   bInProcess;

    bInProcess = pCtx->bInProcess;

    if ((HSM_TRUE == bInProcess) && (HSM_OP_RSA_SSA_PKCS1V15_VERIFY == pCtx->eOperationCata))
    {
        if (HSM_DRV_SM_ARITH == pCtx->eStat)
        {
            eRet = pCtx->pReadAckCb();
            if (HSM_STATUS_BUSY == eRet)
            {
                eRet = HSM_STATUS_AGAIN;
            }
            else if (HSM_STATUS_SUCCESS == eRet)
            {
                eRet = HSM_L1_RsaSsaPkcs1V15Verify_Isr(pCtx);
            }
            else
            {
                pCtx->eStat = HSM_DRV_SM_STOP;
            }
        }
        else
        {
            eRet = HSM_STATUS_HW_IDLE;
        }
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_RsaSsaPkcs1V15VerifyReset(HSM_L1_RtCtxType *pCtx)
{
    HSM_BoolType   bInProcess;
    HSM_StatusType eRet = HSM_STATUS_SUCCESS;

    bInProcess = pCtx->bInProcess;

    if ((HSM_TRUE == bInProcess) && (HSM_OP_RSA_SSA_PKCS1V15_VERIFY == pCtx->eOperationCata))
    {
        if (HSM_DRV_SM_ARITH == pCtx->eStat)
        {
            eRet = pCtx->pCancelCmdCb();
        }

        if (HSM_STATUS_SUCCESS == eRet)
        {
            pCtx->eStat = HSM_DRV_SM_READY;
        }
        else
        {
            ;
        }
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_RsaSsaPkcs1V15Verify_Isr(HSM_L1_RtCtxType *pCtx)
{
    HSM_StatusType eRet;

    if (MAILBOXAPI_RET_PASS == pCtx->tL1AlgCtx.tRsaSsaPkcs1V15Verify.pParm->u32HSMStatusRet)
    {
        eRet = HSM_STATUS_PASS;

        if (NULL_PTR != pCtx->tL1AlgCtx.tRsaSsaPkcs1V15Verify.pVerifyResult)
        {
            *pCtx->tL1AlgCtx.tRsaSsaPkcs1V15Verify.pVerifyResult = CRYPTO_E_VER_OK;
        }

        pCtx->eStat = HSM_DRV_SM_STOP;
    }
    else if (MAILBOXAPI_RET_FAIL == pCtx->tL1AlgCtx.tRsaSsaPkcs1V15Verify.pParm->u32HSMStatusRet)
    {
        eRet = HSM_STATUS_FAIL;

        if (NULL_PTR != pCtx->tL1AlgCtx.tRsaSsaPkcs1V15Verify.pVerifyResult)
        {
            *pCtx->tL1AlgCtx.tRsaSsaPkcs1V15Verify.pVerifyResult = CRYPTO_E_VER_NOT_OK;
        }

        pCtx->eStat = HSM_DRV_SM_STOP;
    }
    else
    {
        eRet = HSM_STATUS_ERROR;

        if (NULL_PTR != pCtx->tL1AlgCtx.tRsaSsaPkcs1V15Verify.pVerifyResult)
        {
            *pCtx->tL1AlgCtx.tRsaSsaPkcs1V15Verify.pVerifyResult = CRYPTO_E_VER_NOT_OK;
        }

        pCtx->eStat = HSM_DRV_SM_STOP;
    }

    return eRet;
}

HSM_StatusType HSM_L1_RsaSsaPkcs1V15VerifyExitEnv(HSM_L1_RtCtxType *pCtx)
{
    HSM_BoolType   bInProcess = pCtx->bInProcess;
    HSM_StatusType eRet;

    if ((HSM_TRUE == bInProcess) && (HSM_OP_RSA_SSA_PKCS1V15_VERIFY == pCtx->eOperationCata))
    {
        eRet = HSM_L1_CommonExitEnv(pCtx);
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_KeyImportSetupEnv(HSM_L1_RtCtxType *pCtx)
{
    HSM_BoolType   bInProcess = HSM_FALSE;
    HSM_StatusType eRet       = HSM_STATUS_SUCCESS;

    bInProcess = pCtx->bInProcess;
    if (HSM_FALSE == bInProcess)
    {
        pCtx->bInProcess     = HSM_TRUE;
        pCtx->eOperationCata = HSM_OP_KEY_MANAGE_IMPORT;
        pCtx->eStat          = HSM_DRV_SM_READY;

        pCtx->tL1AlgCtx.tKeyInf.pParm = (HSMCom_UserKeyManageType *)HSM_ADDRESS_UP_ALIGN(
            &(pCtx->tL1AlgCtx.tKeyInf.aParmBuf[0]));
        eRet = HSM_STATUS_SUCCESS;
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_KeyImport(HSM_L1_RtCtxType                  *pCtx,
                                const HSM_Ln_ImportUserKeyExtType *pCfg,
                                hsm_uint32_t                       u32TimeoutMs)
{
    HSM_StatusType eRet       = HSM_STATUS_SUCCESS;
    HSM_BoolType   bInProcess = HSM_FALSE;
    void          *pCache;

    if ((NULL_PTR != pCtx) && (NULL_PTR != pCfg))
    {
        bInProcess = pCtx->bInProcess;
        if ((HSM_TRUE == bInProcess) && (HSM_OP_KEY_MANAGE_IMPORT == pCtx->eOperationCata))
        {
            if (HSM_DRV_SM_ARITH != pCtx->eStat)
            {
                if (pCfg->u32DataLength > 0u)
                {
                    pCtx->tL1AlgCtx.tKeyInf.pParm->u32HSMStatusRet = MAILBOXAPI_RET_NONE;
                    pCtx->tL1AlgCtx.tKeyInf.pParm->u32Timeout      = u32TimeoutMs;

                    hsm_memcpy(&(pCtx->tL1AlgCtx.tKeyInf.pParm->tKMParam.tImportUserKeyExtCfg),
                               pCfg,
                               sizeof(pCtx->tL1AlgCtx.tKeyInf.pParm->tKMParam.tImportUserKeyExtCfg));

                    if (0u != (pCfg->u32KeyIdFix))
                    {
                        pCtx->tL1AlgCtx.tKeyInf.pParm->tKMParam.tImportUserKeyExtCfg.pKeyID = NULL_PTR;
                    }

                    if ((((hsm_uint32_t)(pCfg->pDataAddr)) & 0x3u) &&
                        (pCfg->u32DataLength <=
                         (sizeof(pCtx->tL1AlgCtx.tKeyInf.tKeyInfoShared.aAlignedDataBuffer) - 4u)))
                    {
                        pCache = (void *)HSM_ADDRESS_UP_ALIGN(
                            &(pCtx->tL1AlgCtx.tKeyInf.tKeyInfoShared.aAlignedDataBuffer[0]));

                        hsm_memcpy(pCache, pCfg->pDataAddr, pCfg->u32DataLength);

                        pCtx->tL1AlgCtx.tKeyInf.pParm->tKMParam.tImportUserKeyExtCfg.pDataAddr = pCache;
                    }

                    eRet = HSM_FW_UserKeyImportNew(&(pCtx->tCmd), pCtx->tL1AlgCtx.tKeyInf.pParm);
                    if (HSM_STATUS_SUCCESS == eRet)
                    {
                        pCtx->eStat = HSM_DRV_SM_ARITH;
                        eRet        = pCtx->pSendCmdCb(&(pCtx->tCmd));
                        if (HSM_STATUS_SUCCESS != eRet)
                        {
                            pCtx->eStat = HSM_DRV_SM_STOP;
                            eRet        = HSM_STATUS_SEND_FAIL;
                        }
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
                eRet = HSM_STATUS_BUSY;
            }
        }
        else
        {
            eRet = HSM_STATUS_LOGIC_ERR;
        }
    }
    else
    {
        eRet = HSM_STATUS_PARAM_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_KeyImportPoll(HSM_L1_RtCtxType *pCtx)
{
    HSM_StatusType eRet = HSM_STATUS_SUCCESS;
    HSM_BoolType   bInProcess;

    bInProcess = pCtx->bInProcess;

    if ((HSM_TRUE == bInProcess) && (HSM_OP_KEY_MANAGE_IMPORT == pCtx->eOperationCata))
    {
        if (HSM_DRV_SM_ARITH == pCtx->eStat)
        {
            eRet = pCtx->pReadAckCb();
            if (HSM_STATUS_BUSY == eRet)
            {
                eRet = HSM_STATUS_AGAIN;
            }
            else if (HSM_STATUS_SUCCESS == eRet)
            {
                eRet = HSM_L1_KeyImport_Isr(pCtx);
            }
            else
            {
                pCtx->eStat = HSM_DRV_SM_STOP;
            }
        }
        else
        {
            eRet = HSM_STATUS_HW_IDLE;
        }
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_KeyImportReset(HSM_L1_RtCtxType *pCtx)
{
    HSM_BoolType   bInProcess;
    HSM_StatusType eRet = HSM_STATUS_SUCCESS;

    bInProcess = pCtx->bInProcess;

    if ((HSM_TRUE == bInProcess) && (HSM_OP_KEY_MANAGE_IMPORT == pCtx->eOperationCata))
    {
        if (HSM_DRV_SM_ARITH == pCtx->eStat)
        {
            eRet = pCtx->pCancelCmdCb();
        }

        if (HSM_STATUS_SUCCESS == eRet)
        {
            pCtx->eStat = HSM_DRV_SM_READY;
        }
        else
        {
            ;
        }
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_KeyImportExitEnv(HSM_L1_RtCtxType *pCtx)
{
    HSM_BoolType   bInProcess = pCtx->bInProcess;
    HSM_StatusType eRet       = HSM_STATUS_SUCCESS;

    if ((HSM_TRUE == bInProcess) && (HSM_OP_KEY_MANAGE_IMPORT == pCtx->eOperationCata))
    {
        eRet = HSM_L1_CommonExitEnv(pCtx);
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_KeyImport_Isr(HSM_L1_RtCtxType *pCtx)
{
    HSM_StatusType eRet;
    if (MAILBOXAPI_RET_SUCCESS == pCtx->tL1AlgCtx.tKeyInf.pParm->u32HSMStatusRet)
    {
        eRet        = HSM_STATUS_SUCCESS;
        pCtx->eStat = HSM_DRV_SM_STOP;
    }
#if ((FC7XXX_HSM_SUBSYSTEM_TYPE == FC7240_HSM_SUBSYSTEM) || \
     (FC7XXX_HSM_SUBSYSTEM_TYPE == FC7300_HSM_SUBSYSTEM))
#else
    else if ((KEYMANAGER_STATUS_ID_ERROR | 0x80000000u) ==
             pCtx->tL1AlgCtx.tKeyInf.pParm->u32HSMStatusRet)
    {
        eRet        = HSM_STATUS_EXIST;
        pCtx->eStat = HSM_DRV_SM_STOP;
    }
    else if ((KEYMANAGER_STATUS_SPACE_ERROR | 0x80000000u) ==
             pCtx->tL1AlgCtx.tKeyInf.pParm->u32HSMStatusRet)
    {
        eRet        = HSM_STATUS_SPACE_FULL;
        pCtx->eStat = HSM_DRV_SM_STOP;
    }
#endif

    else
    {
        eRet        = HSM_STATUS_HW_ERR;
        pCtx->eStat = HSM_DRV_SM_STOP;
    }

    return eRet;
}

#if ((FC7XXX_HSM_SUBSYSTEM_TYPE == FC7240_HSM_SUBSYSTEM) || \
     (FC7XXX_HSM_SUBSYSTEM_TYPE == FC7300_HSM_SUBSYSTEM))

HSM_StatusType HSM_L1_KeyValidateSetupEnv(HSM_L1_RtCtxType *pCtx)
{
    HSM_BoolType   bInProcess = HSM_FALSE;
    HSM_StatusType eRet       = HSM_STATUS_SUCCESS;

    bInProcess = pCtx->bInProcess;
    if (HSM_FALSE == bInProcess)
    {
        pCtx->bInProcess              = HSM_TRUE;
        pCtx->eOperationCata          = HSM_OP_KEY_MANAGE_VALIDATE;
        pCtx->eStat                   = HSM_DRV_SM_READY;
        pCtx->tL1AlgCtx.tKeyInf.pParm = (HSMCom_UserKeyManageType *)HSM_ADDRESS_UP_ALIGN(
            &(pCtx->tL1AlgCtx.tKeyInf.aParmBuf[0]));

        eRet = HSM_STATUS_SUCCESS;
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_KeyValidate(HSM_L1_RtCtxType *pCtx,
                                  hsm_uint32_t      u32KeyId,
                                  hsm_uint32_t      u32TimeoutMs)
{
    HSM_StatusType eRet       = HSM_STATUS_SUCCESS;
    HSM_BoolType   bInProcess = HSM_FALSE;

    if (NULL_PTR != pCtx)
    {
        bInProcess = pCtx->bInProcess;

        if ((HSM_TRUE == bInProcess) && (HSM_OP_KEY_MANAGE_VALIDATE == pCtx->eOperationCata))
        {
            if (HSM_DRV_SM_ARITH != pCtx->eStat)
            {

                pCtx->tL1AlgCtx.tKeyInf.pParm->u32HSMStatusRet               = MAILBOXAPI_RET_NONE;
                pCtx->tL1AlgCtx.tKeyInf.pParm->tKMParam.u32CheckUserKeyIDExt = u32KeyId;
                pCtx->tL1AlgCtx.tKeyInf.pParm->u32Timeout                    = u32TimeoutMs;

                eRet = HSM_FW_CheckKeyIdExt(&(pCtx->tCmd), pCtx->tL1AlgCtx.tKeyInf.pParm);
                if (HSM_STATUS_SUCCESS == eRet)
                {
                    pCtx->eStat = HSM_DRV_SM_ARITH;
                    eRet        = pCtx->pSendCmdCb(&(pCtx->tCmd));
                    if (HSM_STATUS_SUCCESS != eRet)
                    {
                        pCtx->eStat = HSM_DRV_SM_STOP;
                        eRet        = HSM_STATUS_SEND_FAIL;
                    }
                }
                else
                {
                    ;
                }
            }
            else
            {
                eRet = HSM_STATUS_BUSY;
            }
        }
        else
        {
            eRet = HSM_STATUS_LOGIC_ERR;
        }
    }
    else
    {
        eRet = HSM_STATUS_PARAM_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_KeyValidatePoll(HSM_L1_RtCtxType *pCtx)
{
    HSM_StatusType eRet = HSM_STATUS_SUCCESS;
    HSM_BoolType   bInProcess;

    bInProcess = pCtx->bInProcess;

    if ((HSM_TRUE == bInProcess) && (HSM_OP_KEY_MANAGE_VALIDATE == pCtx->eOperationCata))
    {
        if (HSM_DRV_SM_ARITH == pCtx->eStat)
        {
            eRet = pCtx->pReadAckCb();
            if (HSM_STATUS_BUSY == eRet)
            {
                eRet = HSM_STATUS_AGAIN;
            }
            else if (HSM_STATUS_SUCCESS == eRet)
            {
                eRet = HSM_L1_KeyValidate_Isr(pCtx);
            }
            else
            {
                pCtx->eStat = HSM_DRV_SM_STOP;
            }
        }
        else
        {
            eRet = HSM_STATUS_HW_IDLE;
        }
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_KeyValidateReset(HSM_L1_RtCtxType *pCtx)
{
    HSM_BoolType   bInProcess;
    HSM_StatusType eRet = HSM_STATUS_SUCCESS;

    bInProcess = pCtx->bInProcess;

    if ((HSM_TRUE == bInProcess) && (HSM_OP_KEY_MANAGE_VALIDATE == pCtx->eOperationCata))
    {
        if (HSM_DRV_SM_ARITH == pCtx->eStat)
        {
            eRet = pCtx->pCancelCmdCb();
        }

        if (HSM_STATUS_SUCCESS == eRet)
        {
            pCtx->eStat = HSM_DRV_SM_READY;
        }
        else
        {
            ;
        }
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_KeyValidateExitEnv(HSM_L1_RtCtxType *pCtx)
{
    HSM_BoolType   bInProcess = pCtx->bInProcess;
    HSM_StatusType eRet       = HSM_STATUS_SUCCESS;

    if ((HSM_TRUE == bInProcess) && (HSM_OP_KEY_MANAGE_VALIDATE == pCtx->eOperationCata))
    {
        eRet = HSM_L1_CommonExitEnv(pCtx);
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_KeyValidate_Isr(HSM_L1_RtCtxType *pCtx)
{
    HSM_StatusType eRet;

    if (MAILBOXAPI_RET_FAIL == pCtx->tL1AlgCtx.tKeyInf.pParm->u32HSMStatusRet)
    {
        eRet        = HSM_STATUS_NOT_EXIST;
        pCtx->eStat = HSM_DRV_SM_STOP;
    }
    else if (MAILBOXAPI_RET_PASS == pCtx->tL1AlgCtx.tKeyInf.pParm->u32HSMStatusRet)
    {
        eRet        = HSM_STATUS_EXIST;
        pCtx->eStat = HSM_DRV_SM_STOP;
    }
    else
    {
        eRet        = HSM_STATUS_HW_ERR;
        pCtx->eStat = HSM_DRV_SM_STOP;
    }

    return eRet;
}

#endif

#if ((FC7XXX_HSM_SUBSYSTEM_TYPE == FC7240_HSM_SUBSYSTEM) || \
     (FC7XXX_HSM_SUBSYSTEM_TYPE == FC7300_HSM_SUBSYSTEM))
#else

HSM_StatusType HSM_L1_UpdateKeyIdContentSetupEnv(HSM_L1_RtCtxType *pCtx)
{
    HSM_BoolType   bInProcess = HSM_FALSE;
    HSM_StatusType eRet       = HSM_STATUS_SUCCESS;

    bInProcess = pCtx->bInProcess;
    if (HSM_FALSE == bInProcess)
    {
        pCtx->bInProcess              = HSM_TRUE;
        pCtx->eOperationCata          = HSM_OP_KEY_MANAGE_UPDATE_KEY_ID_CONTENT;
        pCtx->eStat                   = HSM_DRV_SM_READY;
        pCtx->tL1AlgCtx.tKeyInf.pParm = (HSMCom_UserKeyManageType *)HSM_ADDRESS_UP_ALIGN(
            &(pCtx->tL1AlgCtx.tKeyInf.aParmBuf[0]));

        eRet = HSM_STATUS_SUCCESS;
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_UpdateKeyIdContent(HSM_L1_RtCtxType                         *pCtx,
                                         const HSM_Ln_KeyManagerUpdateUserKeyType *pCfg,
                                         hsm_uint32_t                              u32TimeoutMs)
{
    HSM_StatusType eRet       = HSM_STATUS_SUCCESS;
    HSM_BoolType   bInProcess = HSM_FALSE;

    if (NULL_PTR != pCtx)
    {
        bInProcess = pCtx->bInProcess;

        if ((HSM_TRUE == bInProcess) &&
            (HSM_OP_KEY_MANAGE_UPDATE_KEY_ID_CONTENT == pCtx->eOperationCata))
        {
            if (HSM_DRV_SM_ARITH != pCtx->eStat)
            {

                pCtx->tL1AlgCtx.tKeyInf.pParm->u32HSMStatusRet = MAILBOXAPI_RET_NONE;
                pCtx->tL1AlgCtx.tKeyInf.pParm->u32Timeout      = u32TimeoutMs;

                hsm_memcpy(&(pCtx->tL1AlgCtx.tKeyInf.pParm->tKMParam.tUpdateUserKeyCfg),
                           pCfg,
                           sizeof(*pCfg));

                eRet = HSM_UpdateKeyContentOfSpecificKeyId(&(pCtx->tCmd),
                                                           pCtx->tL1AlgCtx.tKeyInf.pParm);
                if (HSM_STATUS_SUCCESS == eRet)
                {
                    pCtx->eStat = HSM_DRV_SM_ARITH;
                    eRet        = pCtx->pSendCmdCb(&(pCtx->tCmd));
                    if (HSM_STATUS_SUCCESS != eRet)
                    {
                        pCtx->eStat = HSM_DRV_SM_STOP;
                        eRet        = HSM_STATUS_SEND_FAIL;
                    }
                }
                else
                {
                    ;
                }
            }
            else
            {
                eRet = HSM_STATUS_BUSY;
            }
        }
        else
        {
            eRet = HSM_STATUS_LOGIC_ERR;
        }
    }
    else
    {
        eRet = HSM_STATUS_PARAM_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_UpdateKeyIdContentPoll(HSM_L1_RtCtxType *pCtx)
{
    HSM_StatusType eRet = HSM_STATUS_SUCCESS;
    HSM_BoolType   bInProcess;

    bInProcess = pCtx->bInProcess;

    if ((HSM_TRUE == bInProcess) && (HSM_OP_KEY_MANAGE_UPDATE_KEY_ID_CONTENT == pCtx->eOperationCata))
    {
        if (HSM_DRV_SM_ARITH == pCtx->eStat)
        {
            eRet = pCtx->pReadAckCb();
            if (HSM_STATUS_BUSY == eRet)
            {
                eRet = HSM_STATUS_AGAIN;
            }
            else if (HSM_STATUS_SUCCESS == eRet)
            {
                eRet = HSM_L1_UpdateKeyIdContent_Isr(pCtx);
            }
            else
            {
                pCtx->eStat = HSM_DRV_SM_STOP;
            }
        }
        else
        {
            eRet = HSM_STATUS_HW_IDLE;
        }
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_UpdateKeyIdContentReset(HSM_L1_RtCtxType *pCtx)
{
    HSM_BoolType   bInProcess;
    HSM_StatusType eRet = HSM_STATUS_SUCCESS;

    bInProcess = pCtx->bInProcess;

    if ((HSM_TRUE == bInProcess) && (HSM_OP_KEY_MANAGE_UPDATE_KEY_ID_CONTENT == pCtx->eOperationCata))
    {
        if (HSM_DRV_SM_ARITH == pCtx->eStat)
        {
            eRet = pCtx->pCancelCmdCb();
        }

        if (HSM_STATUS_SUCCESS == eRet)
        {
            pCtx->eStat = HSM_DRV_SM_READY;
        }
        else
        {
            ;
        }
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_UpdateKeyIdContentExitEnv(HSM_L1_RtCtxType *pCtx)
{
    HSM_BoolType   bInProcess = pCtx->bInProcess;
    HSM_StatusType eRet       = HSM_STATUS_SUCCESS;

    if ((HSM_TRUE == bInProcess) && (HSM_OP_KEY_MANAGE_UPDATE_KEY_ID_CONTENT == pCtx->eOperationCata))
    {
        eRet = HSM_L1_CommonExitEnv(pCtx);
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_UpdateKeyIdContent_Isr(HSM_L1_RtCtxType *pCtx)
{
    HSM_StatusType eRet;

    if (MAILBOXAPI_RET_SUCCESS == pCtx->tL1AlgCtx.tKeyInf.pParm->u32HSMStatusRet)
    {
        eRet        = HSM_STATUS_SUCCESS;
        pCtx->eStat = HSM_DRV_SM_STOP;
    }
    else if ((KEYMANAGER_STATUS_ID_ERROR | 0x80000000u) ==
             pCtx->tL1AlgCtx.tKeyInf.pParm->u32HSMStatusRet)
    {
        eRet        = HSM_STATUS_NOT_EXIST;
        pCtx->eStat = HSM_DRV_SM_STOP;
    }
    else if (((KEYMANAGER_STATUS_SPACE_ERROR | 0x80000000u) ==
              pCtx->tL1AlgCtx.tKeyInf.pParm->u32HSMStatusRet) ||
             (KEYMANAGER_STATUS_ERROR == pCtx->tL1AlgCtx.tKeyInf.pParm->u32HSMStatusRet))
    {
        eRet        = HSM_STATUS_SPACE_FULL;
        pCtx->eStat = HSM_DRV_SM_STOP;
    }
    else
    {
        eRet        = HSM_STATUS_HW_ERR;
        pCtx->eStat = HSM_DRV_SM_STOP;
    }

    return eRet;
}

#endif

HSM_StatusType HSM_L1_KeyCopySetupEnv(HSM_L1_RtCtxType *pCtx)
{
    HSM_BoolType   bInProcess = HSM_FALSE;
    HSM_StatusType eRet       = HSM_STATUS_SUCCESS;

    bInProcess = pCtx->bInProcess;
    if (HSM_FALSE == bInProcess)
    {
        pCtx->bInProcess              = HSM_TRUE;
        pCtx->eOperationCata          = HSM_OP_KEY_MANAGE_COPY;
        pCtx->eStat                   = HSM_DRV_SM_READY;
        pCtx->tL1AlgCtx.tKeyInf.pParm = (HSMCom_UserKeyManageType *)HSM_ADDRESS_UP_ALIGN(
            &(pCtx->tL1AlgCtx.tKeyInf.aParmBuf[0]));

        eRet = HSM_STATUS_SUCCESS;
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_KeyCopy(HSM_L1_RtCtxType             *pCtx,
                              const HSM_Ln_CopyUserKeyType *pCfg,
                              hsm_uint32_t                  u32TimeoutMs)
{
    HSM_StatusType eRet       = HSM_STATUS_SUCCESS;
    HSM_BoolType   bInProcess = HSM_FALSE;

    if ((NULL_PTR != pCtx) && (NULL_PTR != pCfg))
    {
        bInProcess = pCtx->bInProcess;

        if ((HSM_TRUE == bInProcess) && (HSM_OP_KEY_MANAGE_COPY == pCtx->eOperationCata))
        {
            if (HSM_DRV_SM_ARITH != pCtx->eStat)
            {
                pCtx->tL1AlgCtx.tKeyInf.pParm->u32HSMStatusRet = MAILBOXAPI_RET_NONE;
                pCtx->tL1AlgCtx.tKeyInf.pParm->u32Timeout      = u32TimeoutMs;

                hsm_memcpy(&(pCtx->tL1AlgCtx.tKeyInf.pParm->tKMParam.tCopyUserKeyExtCfg),
                           pCfg,
                           sizeof(pCtx->tL1AlgCtx.tKeyInf.pParm->tKMParam.tCopyUserKeyExtCfg));

                eRet = HSM_FW_CopyKeyExt(&(pCtx->tCmd), pCtx->tL1AlgCtx.tKeyInf.pParm);
                if (HSM_STATUS_SUCCESS == eRet)
                {
                    pCtx->eStat = HSM_DRV_SM_ARITH;
                    eRet        = pCtx->pSendCmdCb(&(pCtx->tCmd));
                    if (HSM_STATUS_SUCCESS != eRet)
                    {
                        pCtx->eStat = HSM_DRV_SM_STOP;
                        eRet        = HSM_STATUS_SEND_FAIL;
                    }
                }
                else
                {
                    ;
                }
            }
            else
            {
                eRet = HSM_STATUS_BUSY;
            }
        }
        else
        {
            eRet = HSM_STATUS_LOGIC_ERR;
        }
    }
    else
    {
        eRet = HSM_STATUS_PARAM_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_KeyCopyPoll(HSM_L1_RtCtxType *pCtx)
{
    HSM_StatusType eRet = HSM_STATUS_SUCCESS;
    HSM_BoolType   bInProcess;

    bInProcess = pCtx->bInProcess;

    if ((HSM_TRUE == bInProcess) && (HSM_OP_KEY_MANAGE_COPY == pCtx->eOperationCata))
    {
        if (HSM_DRV_SM_ARITH == pCtx->eStat)
        {
            eRet = pCtx->pReadAckCb();
            if (HSM_STATUS_BUSY == eRet)
            {
                eRet = HSM_STATUS_AGAIN;
            }
            else if (HSM_STATUS_SUCCESS == eRet)
            {
                eRet = HSM_L1_KeyCopy_Isr(pCtx);
            }
            else
            {
                pCtx->eStat = HSM_DRV_SM_STOP;
            }
        }
        else
        {
            eRet = HSM_STATUS_HW_IDLE;
        }
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_KeyCopyReset(HSM_L1_RtCtxType *pCtx)
{
    HSM_BoolType   bInProcess;
    HSM_StatusType eRet = HSM_STATUS_SUCCESS;

    bInProcess = pCtx->bInProcess;

    if ((HSM_TRUE == bInProcess) && (HSM_OP_KEY_MANAGE_COPY == pCtx->eOperationCata))
    {
        if (HSM_DRV_SM_ARITH == pCtx->eStat)
        {
            eRet = pCtx->pCancelCmdCb();
        }

        if (HSM_STATUS_SUCCESS == eRet)
        {
            pCtx->eStat = HSM_DRV_SM_READY;
        }
        else
        {
            ;
        }
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_KeyCopyExitEnv(HSM_L1_RtCtxType *pCtx)
{
    HSM_BoolType   bInProcess = pCtx->bInProcess;
    HSM_StatusType eRet       = HSM_STATUS_SUCCESS;

    if ((HSM_TRUE == bInProcess) && (HSM_OP_KEY_MANAGE_COPY == pCtx->eOperationCata))
    {
        eRet = HSM_L1_CommonExitEnv(pCtx);
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_KeyCopy_Isr(HSM_L1_RtCtxType *pCtx)
{
    HSM_StatusType eRet;

    if (MAILBOXAPI_RET_SUCCESS == pCtx->tL1AlgCtx.tKeyInf.pParm->u32HSMStatusRet)
    {
        eRet        = HSM_STATUS_SUCCESS;
        pCtx->eStat = HSM_DRV_SM_STOP;
    }
    else
    {
        eRet        = HSM_STATUS_HW_ERR;
        pCtx->eStat = HSM_DRV_SM_STOP;
    }

    return eRet;
}

HSM_StatusType HSM_L1_KeyRevokeSetupEnv(HSM_L1_RtCtxType *pCtx)
{
    HSM_BoolType   bInProcess = HSM_FALSE;
    HSM_StatusType eRet       = HSM_STATUS_SUCCESS;

    bInProcess = pCtx->bInProcess;
    if (HSM_FALSE == bInProcess)
    {
        pCtx->bInProcess              = HSM_TRUE;
        pCtx->eOperationCata          = HSM_OP_KEY_MANAGE_REVOKE;
        pCtx->eStat                   = HSM_DRV_SM_READY;
        pCtx->tL1AlgCtx.tKeyInf.pParm = (HSMCom_UserKeyManageType *)HSM_ADDRESS_UP_ALIGN(
            &(pCtx->tL1AlgCtx.tKeyInf.aParmBuf[0]));
        eRet = HSM_STATUS_SUCCESS;
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_KeyRevoke(HSM_L1_RtCtxType *pCtx, hsm_uint32_t u32KeyId, hsm_uint32_t u32TimeoutMs)
{
    HSM_StatusType eRet       = HSM_STATUS_SUCCESS;
    HSM_BoolType   bInProcess = HSM_FALSE;

    if (NULL_PTR != pCtx)
    {
        bInProcess = pCtx->bInProcess;

        if ((HSM_TRUE == bInProcess) && (HSM_OP_KEY_MANAGE_REVOKE == pCtx->eOperationCata))
        {
            if (HSM_DRV_SM_ARITH != pCtx->eStat)
            {
                pCtx->tL1AlgCtx.tKeyInf.pParm->u32HSMStatusRet             = MAILBOXAPI_RET_NONE;
                pCtx->tL1AlgCtx.tKeyInf.pParm->u32Timeout                  = u32TimeoutMs;
                pCtx->tL1AlgCtx.tKeyInf.pParm->tKMParam.u32RevokeUserKeyID = u32KeyId;

                eRet = HSM_UserKeyRevoke(&(pCtx->tCmd), pCtx->tL1AlgCtx.tKeyInf.pParm);
                if (HSM_STATUS_SUCCESS == eRet)
                {
                    pCtx->eStat = HSM_DRV_SM_ARITH;
                    eRet        = pCtx->pSendCmdCb(&(pCtx->tCmd));
                    if (HSM_STATUS_SUCCESS != eRet)
                    {
                        pCtx->eStat = HSM_DRV_SM_STOP;
                        eRet        = HSM_STATUS_SEND_FAIL;
                    }
                }
                else
                {
                    ;
                }
            }
            else
            {
                eRet = HSM_STATUS_BUSY;
            }
        }
        else
        {
            eRet = HSM_STATUS_LOGIC_ERR;
        }
    }
    else
    {
        eRet = HSM_STATUS_PARAM_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_KeyRevokePoll(HSM_L1_RtCtxType *pCtx)
{
    HSM_StatusType eRet = HSM_STATUS_SUCCESS;
    HSM_BoolType   bInProcess;

    bInProcess = pCtx->bInProcess;

    if ((HSM_TRUE == bInProcess) && (HSM_OP_KEY_MANAGE_REVOKE == pCtx->eOperationCata))
    {
        if (HSM_DRV_SM_ARITH == pCtx->eStat)
        {
            eRet = pCtx->pReadAckCb();
            if (HSM_STATUS_BUSY == eRet)
            {
                eRet = HSM_STATUS_AGAIN;
            }
            else if (HSM_STATUS_SUCCESS == eRet)
            {
                eRet = HSM_L1_KeyRevoke_Isr(pCtx);
            }
            else
            {
                pCtx->eStat = HSM_DRV_SM_STOP;
            }
        }
        else
        {
            eRet = HSM_STATUS_HW_IDLE;
        }
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_KeyRevokeReset(HSM_L1_RtCtxType *pCtx)
{
    HSM_BoolType   bInProcess;
    HSM_StatusType eRet = HSM_STATUS_SUCCESS;

    bInProcess = pCtx->bInProcess;

    if ((HSM_TRUE == bInProcess) && (HSM_OP_KEY_MANAGE_REVOKE == pCtx->eOperationCata))
    {
        if (HSM_DRV_SM_ARITH == pCtx->eStat)
        {
            eRet = pCtx->pCancelCmdCb();
        }

        if (HSM_STATUS_SUCCESS == eRet)
        {
            pCtx->eStat = HSM_DRV_SM_READY;
        }
        else
        {
            ;
        }
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_KeyRevokeExitEnv(HSM_L1_RtCtxType *pCtx)
{
    HSM_BoolType   bInProcess = pCtx->bInProcess;
    HSM_StatusType eRet       = HSM_STATUS_SUCCESS;

    if ((HSM_TRUE == bInProcess) && (HSM_OP_KEY_MANAGE_REVOKE == pCtx->eOperationCata))
    {
        eRet = HSM_L1_CommonExitEnv(pCtx);
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_KeyRevoke_Isr(HSM_L1_RtCtxType *pCtx)
{
    HSM_StatusType eRet;
    if (MAILBOXAPI_RET_SUCCESS == pCtx->tL1AlgCtx.tKeyInf.pParm->u32HSMStatusRet)
    {
        eRet        = HSM_STATUS_SUCCESS;
        pCtx->eStat = HSM_DRV_SM_STOP;
    }
#if ((FC7XXX_HSM_SUBSYSTEM_TYPE == FC7240_HSM_SUBSYSTEM) || \
     (FC7XXX_HSM_SUBSYSTEM_TYPE == FC7300_HSM_SUBSYSTEM))
#else
    else if ((KEYMANAGER_STATUS_ID_ERROR | 0x80000000u) ==
             pCtx->tL1AlgCtx.tKeyInf.pParm->u32HSMStatusRet)
    {
        eRet        = HSM_STATUS_NOT_EXIST;
        pCtx->eStat = HSM_DRV_SM_STOP;
    }
#endif

    else
    {
        eRet        = HSM_STATUS_HW_ERR;
        pCtx->eStat = HSM_DRV_SM_STOP;
    }

    return eRet;
}

HSM_StatusType HSM_L1_KeySpaceTidyUpSetupEnv(HSM_L1_RtCtxType *pCtx)
{
    HSM_BoolType   bInProcess = HSM_FALSE;
    HSM_StatusType eRet       = HSM_STATUS_SUCCESS;

    bInProcess = pCtx->bInProcess;
    if (HSM_FALSE == bInProcess)
    {
        pCtx->bInProcess                        = HSM_TRUE;
        pCtx->eOperationCata                    = HSM_OP_KEY_MANAGE_TIDYUP;
        pCtx->eStat                             = HSM_DRV_SM_READY;
        pCtx->tL1AlgCtx.tKeySpaceInf.pSpaceParm = (HSMCom_KeySpaceStatusType *)HSM_ADDRESS_UP_ALIGN(
            &(pCtx->tL1AlgCtx.tKeySpaceInf.aParmBuf[0]));
        eRet = HSM_STATUS_SUCCESS;
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_KeySpaceTidyUp(HSM_L1_RtCtxType          *pCtx,
                                     HSM_Ln_KeySpaceStatusType *pCfg,
                                     hsm_uint32_t               u32TimeoutMs)
{
    HSM_StatusType             eRet               = HSM_STATUS_SUCCESS;
    HSM_BoolType               bInProcess         = HSM_FALSE;
    HSM_Ln_KeySpaceStatusType *pKeySpaceStatusCfg = pCfg;

    if (NULL_PTR == pCfg)
    {
        pKeySpaceStatusCfg = &(pCtx->tL1AlgCtx.tKeySpaceInf.tKeySpaceStatus);
    }

    if ((NULL_PTR != pCtx))
    {
        bInProcess = pCtx->bInProcess;

        if ((HSM_TRUE == bInProcess) && (HSM_OP_KEY_MANAGE_TIDYUP == pCtx->eOperationCata))
        {
            if (HSM_DRV_SM_ARITH != pCtx->eStat)
            {
                pCtx->tL1AlgCtx.tKeySpaceInf.pSpaceParm->u32HSMStatusRet = MAILBOXAPI_RET_NONE;
                pCtx->tL1AlgCtx.tKeySpaceInf.pSpaceParm->pKMSpaceStatus  = pKeySpaceStatusCfg;
                pCtx->tL1AlgCtx.tKeySpaceInf.pSpaceParm->u32Timeout      = u32TimeoutMs;

                eRet = HSM_TidyUpKeySpace(&(pCtx->tCmd), pCtx->tL1AlgCtx.tKeySpaceInf.pSpaceParm);
                if (HSM_STATUS_SUCCESS == eRet)
                {
                    pCtx->eStat = HSM_DRV_SM_ARITH;
                    eRet        = pCtx->pSendCmdCb(&(pCtx->tCmd));
                    if (HSM_STATUS_SUCCESS != eRet)
                    {
                        pCtx->eStat = HSM_DRV_SM_STOP;
                        eRet        = HSM_STATUS_SEND_FAIL;
                    }
                }
                else
                {
                    ;
                }
            }
            else
            {
                eRet = HSM_STATUS_BUSY;
            }
        }
        else
        {
            eRet = HSM_STATUS_LOGIC_ERR;
        }
    }
    else
    {
        eRet = HSM_STATUS_PARAM_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_KeySpaceTidyUpPoll(HSM_L1_RtCtxType *pCtx)
{
    HSM_StatusType eRet = HSM_STATUS_SUCCESS;
    HSM_BoolType   bInProcess;

    bInProcess = pCtx->bInProcess;

    if ((HSM_TRUE == bInProcess) && (HSM_OP_KEY_MANAGE_TIDYUP == pCtx->eOperationCata))
    {
        if (HSM_DRV_SM_ARITH == pCtx->eStat)
        {
            eRet = pCtx->pReadAckCb();
            if (HSM_STATUS_BUSY == eRet)
            {
                eRet = HSM_STATUS_AGAIN;
            }
            else if (HSM_STATUS_SUCCESS == eRet)
            {
                eRet = HSM_L1_KeySpaceTidyup_Isr(pCtx);
            }
            else
            {
                pCtx->eStat = HSM_DRV_SM_STOP;
            }
        }
        else
        {
            eRet = HSM_STATUS_HW_IDLE;
        }
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_KeySpaceTidyUpReset(HSM_L1_RtCtxType *pCtx)
{
    HSM_BoolType   bInProcess;
    HSM_StatusType eRet = HSM_STATUS_SUCCESS;

    bInProcess = pCtx->bInProcess;

    if ((HSM_TRUE == bInProcess) && (HSM_OP_KEY_MANAGE_TIDYUP == pCtx->eOperationCata))
    {
        if (HSM_DRV_SM_ARITH == pCtx->eStat)
        {
            eRet = pCtx->pCancelCmdCb();
        }

        if (HSM_STATUS_SUCCESS == eRet)
        {
            pCtx->eStat = HSM_DRV_SM_READY;
        }
        else
        {
            ;
        }
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_KeySpaceTidyUpExitEnv(HSM_L1_RtCtxType *pCtx)
{
    HSM_BoolType   bInProcess = pCtx->bInProcess;
    HSM_StatusType eRet       = HSM_STATUS_SUCCESS;

    if ((HSM_TRUE == bInProcess) && (HSM_OP_KEY_MANAGE_TIDYUP == pCtx->eOperationCata))
    {
        eRet = HSM_L1_CommonExitEnv(pCtx);
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_KeySpaceTidyup_Isr(HSM_L1_RtCtxType *pCtx)
{
    HSM_StatusType eRet;
    if (MAILBOXAPI_RET_SUCCESS == pCtx->tL1AlgCtx.tKeySpaceInf.pSpaceParm->u32HSMStatusRet)
    {
        eRet        = HSM_STATUS_SUCCESS;
        pCtx->eStat = HSM_DRV_SM_STOP;
    }
    else
    {
        eRet        = HSM_STATUS_HW_ERR;
        pCtx->eStat = HSM_DRV_SM_STOP;
    }

    return eRet;
}

HSM_StatusType HSM_L1_KeySpaceGetStatusSetupEnv(HSM_L1_RtCtxType *pCtx)
{
    HSM_BoolType   bInProcess = HSM_FALSE;
    HSM_StatusType eRet       = HSM_STATUS_SUCCESS;

    bInProcess = pCtx->bInProcess;
    if (HSM_FALSE == bInProcess)
    {
        pCtx->bInProcess                        = HSM_TRUE;
        pCtx->eOperationCata                    = HSM_OP_KEY_MANAGE_GETSTATUS;
        pCtx->eStat                             = HSM_DRV_SM_READY;
        pCtx->tL1AlgCtx.tKeySpaceInf.pSpaceParm = (HSMCom_KeySpaceStatusType *)HSM_ADDRESS_UP_ALIGN(
            &(pCtx->tL1AlgCtx.tKeySpaceInf.aParmBuf[0]));
        eRet = HSM_STATUS_SUCCESS;
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_KeySpaceGetStatus(HSM_L1_RtCtxType          *pCtx,
                                        HSM_Ln_KeySpaceStatusType *pCfg,
                                        hsm_uint32_t               u32TimeoutMs)
{
    HSM_StatusType eRet       = HSM_STATUS_SUCCESS;
    HSM_BoolType   bInProcess = HSM_FALSE;

    if ((NULL_PTR != pCtx) && (NULL_PTR != pCfg))
    {
        bInProcess = pCtx->bInProcess;

        if ((HSM_TRUE == bInProcess) && (HSM_OP_KEY_MANAGE_GETSTATUS == pCtx->eOperationCata))
        {
            if (HSM_DRV_SM_ARITH != pCtx->eStat)
            {
                pCtx->tL1AlgCtx.tKeySpaceInf.pSpaceParm->u32HSMStatusRet = MAILBOXAPI_RET_NONE;
                pCtx->tL1AlgCtx.tKeySpaceInf.pSpaceParm->pKMSpaceStatus  = pCfg;
                pCtx->tL1AlgCtx.tKeySpaceInf.pSpaceParm->u32Timeout      = u32TimeoutMs;

                eRet = HSM_GetKeySpaceStat(&(pCtx->tCmd), pCtx->tL1AlgCtx.tKeySpaceInf.pSpaceParm);
                if (HSM_STATUS_SUCCESS == eRet)
                {
                    pCtx->eStat = HSM_DRV_SM_ARITH;
                    eRet        = pCtx->pSendCmdCb(&(pCtx->tCmd));
                    if (HSM_STATUS_SUCCESS != eRet)
                    {
                        pCtx->eStat = HSM_DRV_SM_STOP;
                        eRet        = HSM_STATUS_SEND_FAIL;
                    }
                }
                else
                {
                    ;
                }
            }
            else
            {
                eRet = HSM_STATUS_BUSY;
            }
        }
        else
        {
            eRet = HSM_STATUS_LOGIC_ERR;
        }
    }
    else
    {
        eRet = HSM_STATUS_PARAM_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_KeySpaceGetStatusPoll(HSM_L1_RtCtxType *pCtx)
{
    HSM_StatusType eRet = HSM_STATUS_SUCCESS;
    HSM_BoolType   bInProcess;

    bInProcess = pCtx->bInProcess;

    if ((HSM_TRUE == bInProcess) && (HSM_OP_KEY_MANAGE_GETSTATUS == pCtx->eOperationCata))
    {
        if (HSM_DRV_SM_ARITH == pCtx->eStat)
        {
            eRet = pCtx->pReadAckCb();
            if (HSM_STATUS_BUSY == eRet)
            {
                eRet = HSM_STATUS_AGAIN;
            }
            else if (HSM_STATUS_SUCCESS == eRet)
            {
                eRet = HSM_L1_KeySpaceTidyup_Isr(pCtx);
            }
            else
            {
                pCtx->eStat = HSM_DRV_SM_STOP;
            }
        }
        else
        {
            eRet = HSM_STATUS_HW_IDLE;
        }
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_KeySpaceGetStatusReset(HSM_L1_RtCtxType *pCtx)
{
    HSM_BoolType   bInProcess;
    HSM_StatusType eRet = HSM_STATUS_SUCCESS;

    bInProcess = pCtx->bInProcess;

    if ((HSM_TRUE == bInProcess) && (HSM_OP_KEY_MANAGE_GETSTATUS == pCtx->eOperationCata))
    {
        if (HSM_DRV_SM_ARITH == pCtx->eStat)
        {
            eRet = pCtx->pCancelCmdCb();
        }

        if (HSM_STATUS_SUCCESS == eRet)
        {
            pCtx->eStat = HSM_DRV_SM_READY;
        }
        else
        {
            ;
        }
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_KeySpaceGetStatusExitEnv(HSM_L1_RtCtxType *pCtx)
{
    HSM_BoolType   bInProcess = pCtx->bInProcess;
    HSM_StatusType eRet       = HSM_STATUS_SUCCESS;

    if ((HSM_TRUE == bInProcess) && (HSM_OP_KEY_MANAGE_GETSTATUS == pCtx->eOperationCata))
    {
        eRet = HSM_L1_CommonExitEnv(pCtx);
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_KeySpaceGetStatus_Isr(HSM_L1_RtCtxType *pCtx)
{
    HSM_StatusType eRet;
    if (MAILBOXAPI_RET_SUCCESS == pCtx->tL1AlgCtx.tKeySpaceInf.pSpaceParm->u32HSMStatusRet)
    {
        eRet        = HSM_STATUS_SUCCESS;
        pCtx->eStat = HSM_DRV_SM_STOP;
    }
    else
    {
        eRet        = HSM_STATUS_HW_ERR;
        pCtx->eStat = HSM_DRV_SM_STOP;
    }

    return eRet;
}

#if ((FC7XXX_HSM_SUBSYSTEM_TYPE == FC7240_HSM_SUBSYSTEM) || \
     (FC7XXX_HSM_SUBSYSTEM_TYPE == FC7300_HSM_SUBSYSTEM))
HSM_StatusType HSM_L1_GetKeyIdStatusSetupEnv(HSM_L1_RtCtxType *pCtx)
{
    HSM_BoolType   bInProcess = HSM_FALSE;
    HSM_StatusType eRet       = HSM_STATUS_SUCCESS;

    bInProcess = pCtx->bInProcess;
    if (HSM_FALSE == bInProcess)
    {
        pCtx->bInProcess              = HSM_TRUE;
        pCtx->eOperationCata          = HSM_OP_KEY_MANAGE_GET_ID_STATUS;
        pCtx->eStat                   = HSM_DRV_SM_READY;
        pCtx->tL1AlgCtx.tKeyInf.pParm = (HSMCom_UserKeyManageType *)HSM_ADDRESS_UP_ALIGN(
            &(pCtx->tL1AlgCtx.tKeyInf.aParmBuf[0]));

        eRet = HSM_STATUS_SUCCESS;
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_GetKeyIdStatus(HSM_L1_RtCtxType *pCtx,
                                     hsm_uint32_t      u32KeyId,
                                     hsm_uint32_t      u32TimeoutMs)
{
    HSM_StatusType eRet       = HSM_STATUS_SUCCESS;
    HSM_BoolType   bInProcess = HSM_FALSE;

    if (NULL_PTR != pCtx)
    {
        bInProcess = pCtx->bInProcess;

        if ((HSM_TRUE == bInProcess) && (HSM_OP_KEY_MANAGE_GET_ID_STATUS == pCtx->eOperationCata))
        {
            if (HSM_DRV_SM_ARITH != pCtx->eStat)
            {
                pCtx->tL1AlgCtx.tKeyInf.pParm->u32HSMStatusRet = MAILBOXAPI_RET_NONE;
                pCtx->tL1AlgCtx.tKeyInf.pParm->u32Timeout      = u32TimeoutMs;

                pCtx->tL1AlgCtx.tKeyInf.pParm->tKMParam.tKeyIdStatusExtCfg.u32KeyID = u32KeyId;
                pCtx->tL1AlgCtx.tKeyInf.pParm->tKMParam.tKeyIdStatusExtCfg.pUserKeyStatus = &(
                    pCtx->tL1AlgCtx.tKeyInf.tKeyInfoShared.tKeyIdStatus);

                eRet = HSM_FW_GetKeyIdStatus(&(pCtx->tCmd), pCtx->tL1AlgCtx.tKeyInf.pParm);
                if (HSM_STATUS_SUCCESS == eRet)
                {
                    pCtx->eStat = HSM_DRV_SM_ARITH;
                    eRet        = pCtx->pSendCmdCb(&(pCtx->tCmd));
                    if (HSM_STATUS_SUCCESS != eRet)
                    {
                        pCtx->eStat = HSM_DRV_SM_STOP;
                        eRet        = HSM_STATUS_SEND_FAIL;
                    }
                }
                else
                {
                    ;
                }
            }
            else
            {
                eRet = HSM_STATUS_BUSY;
            }
        }
        else
        {
            eRet = HSM_STATUS_LOGIC_ERR;
        }
    }
    else
    {
        eRet = HSM_STATUS_PARAM_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_GetKeyIdStatusPoll(HSM_L1_RtCtxType *pCtx)
{
    HSM_StatusType eRet = HSM_STATUS_SUCCESS;
    HSM_BoolType   bInProcess;

    bInProcess = pCtx->bInProcess;

    if ((HSM_TRUE == bInProcess) && (HSM_OP_KEY_MANAGE_GET_ID_STATUS == pCtx->eOperationCata))
    {
        if (HSM_DRV_SM_ARITH == pCtx->eStat)
        {
            eRet = pCtx->pReadAckCb();
            if (HSM_STATUS_BUSY == eRet)
            {
                eRet = HSM_STATUS_AGAIN;
            }
            else if (HSM_STATUS_SUCCESS == eRet)
            {
                eRet = HSM_L1_GetKeyIdStatus_Isr(pCtx);
            }
            else
            {
                pCtx->eStat = HSM_DRV_SM_STOP;
            }
        }
        else
        {
            eRet = HSM_STATUS_HW_IDLE;
        }
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_GetKeyIdStatusReset(HSM_L1_RtCtxType *pCtx)
{
    HSM_BoolType   bInProcess;
    HSM_StatusType eRet = HSM_STATUS_SUCCESS;

    bInProcess = pCtx->bInProcess;

    if ((HSM_TRUE == bInProcess) && (HSM_OP_KEY_MANAGE_GET_ID_STATUS == pCtx->eOperationCata))
    {
        if (HSM_DRV_SM_ARITH == pCtx->eStat)
        {
            eRet = pCtx->pCancelCmdCb();
        }

        if (HSM_STATUS_SUCCESS == eRet)
        {
            pCtx->eStat = HSM_DRV_SM_READY;
        }
        else
        {
            ;
        }
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_GetKeyIdStatusExitEnv(HSM_L1_RtCtxType *pCtx)
{
    HSM_BoolType   bInProcess = pCtx->bInProcess;
    HSM_StatusType eRet       = HSM_STATUS_SUCCESS;

    if ((HSM_TRUE == bInProcess) && (HSM_OP_KEY_MANAGE_GET_ID_STATUS == pCtx->eOperationCata))
    {
        eRet = HSM_L1_CommonExitEnv(pCtx);
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_GetKeyIdStatus_Isr(HSM_L1_RtCtxType *pCtx)
{
    HSM_StatusType eRet;

    if (MAILBOXAPI_RET_SUCCESS == pCtx->tL1AlgCtx.tKeyInf.pParm->u32HSMStatusRet)
    {
        if (KEYMANAGER_USERKEY_STATUS_NOT_EXIST == pCtx->tL1AlgCtx.tKeyInf.tKeyInfoShared.tKeyIdStatus)
        {
            eRet = HSM_STATUS_NOT_EXIST;
        }
        else if (KEYMANAGER_USERKEY_STATUS_EXIST_VALID ==
                 pCtx->tL1AlgCtx.tKeyInf.tKeyInfoShared.tKeyIdStatus)
        {
            eRet = HSM_STATUS_EXIST;
        }
        else if (KEYMANAGER_USERKEY_STATUS_EXIST_INVALID ==
                 pCtx->tL1AlgCtx.tKeyInf.tKeyInfoShared.tKeyIdStatus)
        {
            eRet = HSM_STATUS_ZOMBIE;
        }
        else
        {
            eRet = HSM_STATUS_ERROR;
        }

        pCtx->eStat = HSM_DRV_SM_STOP;
    }
    else
    {
        eRet        = HSM_STATUS_HW_ERR;
        pCtx->eStat = HSM_DRV_SM_STOP;
    }

    return eRet;
}
#endif

HSM_StatusType HSM_L1_RsaSsaPkcs1V15SignSetupEnv(HSM_L1_RtCtxType *pCtx)
{
    HSM_BoolType   bInProcess = HSM_FALSE;
    HSM_StatusType eRet       = HSM_STATUS_SUCCESS;

    bInProcess = pCtx->bInProcess;
    if (HSM_FALSE == bInProcess)
    {
        pCtx->bInProcess                          = HSM_TRUE;
        pCtx->eOperationCata                      = HSM_OP_RSA_SSA_PKCS1V15_SIGN;
        pCtx->eStat                               = HSM_DRV_SM_READY;
        pCtx->tL1AlgCtx.tRsaSsaPkcs1v15Sign.pParm = (HSMCom_RsaSsaPkcs1v15SignType *)
            HSM_ADDRESS_UP_ALIGN(&(pCtx->tL1AlgCtx.tRsaSsaPkcs1v15Sign.aParmBuf[0]));

        eRet = HSM_STATUS_SUCCESS;
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_RsaSsaPkcs1V15SignHash(HSM_L1_RtCtxType                        *pCtx,
                                             const HSM_Ln_RsaSsaPkcs1V15SignHashType *pCfg,
                                             hsm_uint32_t                             u32TimeoutMs)
{
    HSM_StatusType eRet       = HSM_STATUS_SUCCESS;
    HSM_BoolType   bInProcess = HSM_FALSE;

    if ((NULL_PTR != pCtx) && (NULL_PTR != pCfg))
    {
        bInProcess = pCtx->bInProcess;

        if ((HSM_TRUE == bInProcess) && (HSM_OP_RSA_SSA_PKCS1V15_SIGN == pCtx->eOperationCata))
        {
            if (HSM_DRV_SM_ARITH != pCtx->eStat)
            {
                pCtx->tL1AlgCtx.tRsaSsaPkcs1v15Sign.pParm->u32HSMStatusRet = MAILBOXAPI_RET_NONE;
                pCtx->tL1AlgCtx.tRsaSsaPkcs1v15Sign.pParm->u32Timeout      = u32TimeoutMs;
                pCtx->tL1AlgCtx.tRsaSsaPkcs1v15Sign.pParm->u32UserKeyID_KEY_E = pCfg->u32PrivateKeyId;
                pCtx->tL1AlgCtx.tRsaSsaPkcs1v15Sign.pParm->u32UserKeyID_KEY_N = pCfg->u32KeyNId;
                pCtx->tL1AlgCtx.tRsaSsaPkcs1v15Sign.pParm->u32RsaBitCnt       = pCfg->u32RsaBitCnt;
                pCtx->tL1AlgCtx.tRsaSsaPkcs1v15Sign.pParm->tCfg.eInputFmt     = pCfg->eInputFmt;
                pCtx->tL1AlgCtx.tRsaSsaPkcs1v15Sign.pParm->tCfg.eOutputFmt    = pCfg->eOutputFmt;
                if (pCfg->u32RsaBitCnt > 0u)
                {
                    pCtx->tL1AlgCtx.tRsaSsaPkcs1v15Sign.pParm->tCfg.u32EmByteCnt =
                        (pCfg->u32RsaBitCnt + 7u) >> 3u;
                }
                else
                {
                    pCtx->tL1AlgCtx.tRsaSsaPkcs1v15Sign.pParm->tCfg.u32EmByteCnt = 0u;
                }
                pCtx->tL1AlgCtx.tRsaSsaPkcs1v15Sign.pParm->tCfg.eHashType  = pCfg->eHashType;
                pCtx->tL1AlgCtx.tRsaSsaPkcs1v15Sign.pParm->tCfg.pInputData = pCfg->pHashData;
                pCtx->tL1AlgCtx.tRsaSsaPkcs1v15Sign.pParm->tCfg.u32InputDataByteCount =
                    pCfg->u32HashDataByteCount;
                pCtx->tL1AlgCtx.tRsaSsaPkcs1v15Sign.pParm->tCfg.pPrivateKey = pCfg->pPrivateKey;
                pCtx->tL1AlgCtx.tRsaSsaPkcs1v15Sign.pParm->tCfg.u32PrivateKeyByteCnt =
                    pCfg->u32PrivateKeyByteCnt;
                pCtx->tL1AlgCtx.tRsaSsaPkcs1v15Sign.pParm->tCfg.bUseInputDer    = HSM_FALSE;
                pCtx->tL1AlgCtx.tRsaSsaPkcs1v15Sign.pParm->tCfg.pDer            = NULL_PTR;
                pCtx->tL1AlgCtx.tRsaSsaPkcs1v15Sign.pParm->tCfg.u32DerByteCount = 0u;
                pCtx->tL1AlgCtx.tRsaSsaPkcs1v15Sign.pParm->tCfg.pKeyN           = pCfg->pKeyN;
                pCtx->tL1AlgCtx.tRsaSsaPkcs1v15Sign.pParm->tCfg.u32KeyNByteCount =
                    pCfg->u32KeyNByteCount;
                pCtx->tL1AlgCtx.tRsaSsaPkcs1v15Sign.pParm->tCfg.pResult = pCfg->pResult;
                pCtx->tL1AlgCtx.tRsaSsaPkcs1v15Sign.pParm->tCfg.u32ResultBufByteCnt =
                    pCfg->u32ResultBufByteCnt;
                pCtx->tL1AlgCtx.tRsaSsaPkcs1v15Sign.pParm->tCfg.pResultByteCnt = pCfg->pResultByteCnt;
                pCtx->tL1AlgCtx.tRsaSsaPkcs1v15Sign.pParm->tCfg.eInputType =
                    HSM_RSA_SSA_INPUT_HASH_DATA;

#if (FC7XXX_HSM_SUBSYSTEM_TYPE != FC7240_HSM_SUBSYSTEM)
                if (0u != pCtx->tL1AlgCtx.tRsaSsaPkcs1v15Sign.pParm->u32UserKeyID_KEY_E)
                {
                    pCtx->tL1AlgCtx.tRsaSsaPkcs1v15Sign.pParm->tCfg.pPrivateKey          = NULL_PTR;
                    pCtx->tL1AlgCtx.tRsaSsaPkcs1v15Sign.pParm->tCfg.u32PrivateKeyByteCnt = 0u;
                }

                if (0u != pCtx->tL1AlgCtx.tRsaSsaPkcs1v15Sign.pParm->u32UserKeyID_KEY_N)
                {
                    pCtx->tL1AlgCtx.tRsaSsaPkcs1v15Sign.pParm->tCfg.pKeyN            = NULL_PTR;
                    pCtx->tL1AlgCtx.tRsaSsaPkcs1v15Sign.pParm->tCfg.u32KeyNByteCount = 0u;
                }
                /* else do nothing */
#endif

                eRet = HSM_FW_RsaSsaPkcs1v15Sign(&(pCtx->tCmd),
                                                 pCtx->tL1AlgCtx.tRsaSsaPkcs1v15Sign.pParm);
                if (HSM_STATUS_SUCCESS == eRet)
                {
                    pCtx->eStat = HSM_DRV_SM_ARITH;
                    eRet        = pCtx->pSendCmdCb(&(pCtx->tCmd));
                    if (HSM_STATUS_SUCCESS != eRet)
                    {
                        pCtx->eStat = HSM_DRV_SM_STOP;
                        eRet        = HSM_STATUS_SEND_FAIL;
                    }
                }
                else
                {
                    ;
                }
            }
            else
            {
                eRet = HSM_STATUS_BUSY;
            }
        }
        else
        {
            eRet = HSM_STATUS_LOGIC_ERR;
        }
    }
    else
    {
        eRet = HSM_STATUS_PARAM_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_RsaSsaPkcs1V15SignData(HSM_L1_RtCtxType                        *pCtx,
                                             const HSM_Ln_RsaSsaPkcs1V15SignDataType *pCfg,
                                             hsm_uint32_t                             u32TimeoutMs)
{
    HSM_StatusType eRet       = HSM_STATUS_SUCCESS;
    HSM_BoolType   bInProcess = HSM_FALSE;

    if ((NULL_PTR != pCtx) && (NULL_PTR != pCfg))
    {
        bInProcess = pCtx->bInProcess;

        if ((HSM_TRUE == bInProcess) && (HSM_OP_RSA_SSA_PKCS1V15_SIGN == pCtx->eOperationCata))
        {
            if (HSM_DRV_SM_ARITH != pCtx->eStat)
            {
                pCtx->tL1AlgCtx.tRsaSsaPkcs1v15Sign.pParm->u32HSMStatusRet = MAILBOXAPI_RET_NONE;
                pCtx->tL1AlgCtx.tRsaSsaPkcs1v15Sign.pParm->u32Timeout      = u32TimeoutMs;
                pCtx->tL1AlgCtx.tRsaSsaPkcs1v15Sign.pParm->u32UserKeyID_KEY_E = pCfg->u32PrivateKeyId;
                pCtx->tL1AlgCtx.tRsaSsaPkcs1v15Sign.pParm->u32UserKeyID_KEY_N = pCfg->u32KeyNId;
                pCtx->tL1AlgCtx.tRsaSsaPkcs1v15Sign.pParm->u32RsaBitCnt       = pCfg->u32RsaBitCnt;
                pCtx->tL1AlgCtx.tRsaSsaPkcs1v15Sign.pParm->tCfg.eInputFmt     = pCfg->eInputFmt;
                pCtx->tL1AlgCtx.tRsaSsaPkcs1v15Sign.pParm->tCfg.eOutputFmt    = pCfg->eOutputFmt;
                if (pCfg->u32RsaBitCnt > 0u)
                {
                    pCtx->tL1AlgCtx.tRsaSsaPkcs1v15Sign.pParm->tCfg.u32EmByteCnt =
                        (pCfg->u32RsaBitCnt + 7u) >> 3u;
                }
                else
                {
                    pCtx->tL1AlgCtx.tRsaSsaPkcs1v15Sign.pParm->tCfg.u32EmByteCnt = 0u;
                }
                pCtx->tL1AlgCtx.tRsaSsaPkcs1v15Sign.pParm->tCfg.eHashType  = pCfg->eHashType;
                pCtx->tL1AlgCtx.tRsaSsaPkcs1v15Sign.pParm->tCfg.pInputData = pCfg->pInputData;
                pCtx->tL1AlgCtx.tRsaSsaPkcs1v15Sign.pParm->tCfg.u32InputDataByteCount =
                    pCfg->u32InputDataByteCount;
                pCtx->tL1AlgCtx.tRsaSsaPkcs1v15Sign.pParm->tCfg.pPrivateKey = pCfg->pPrivateKey;
                pCtx->tL1AlgCtx.tRsaSsaPkcs1v15Sign.pParm->tCfg.u32PrivateKeyByteCnt =
                    pCfg->u32PrivateKeyByteCnt;
                pCtx->tL1AlgCtx.tRsaSsaPkcs1v15Sign.pParm->tCfg.bUseInputDer    = HSM_FALSE;
                pCtx->tL1AlgCtx.tRsaSsaPkcs1v15Sign.pParm->tCfg.pDer            = NULL_PTR;
                pCtx->tL1AlgCtx.tRsaSsaPkcs1v15Sign.pParm->tCfg.u32DerByteCount = 0u;
                pCtx->tL1AlgCtx.tRsaSsaPkcs1v15Sign.pParm->tCfg.pKeyN           = pCfg->pKeyN;
                pCtx->tL1AlgCtx.tRsaSsaPkcs1v15Sign.pParm->tCfg.u32KeyNByteCount =
                    pCfg->u32KeyNByteCount;
                pCtx->tL1AlgCtx.tRsaSsaPkcs1v15Sign.pParm->tCfg.pResult = pCfg->pResult;
                pCtx->tL1AlgCtx.tRsaSsaPkcs1v15Sign.pParm->tCfg.u32ResultBufByteCnt =
                    pCfg->u32ResultBufByteCnt;
                pCtx->tL1AlgCtx.tRsaSsaPkcs1v15Sign.pParm->tCfg.pResultByteCnt = pCfg->pResultByteCnt;
                pCtx->tL1AlgCtx.tRsaSsaPkcs1v15Sign.pParm->tCfg.eInputType =
                    HSM_RSA_SSA_INPUT_RAW_MESSAGE;

#if (FC7XXX_HSM_SUBSYSTEM_TYPE != FC7240_HSM_SUBSYSTEM)
                if (0u != pCtx->tL1AlgCtx.tRsaSsaPkcs1v15Sign.pParm->u32UserKeyID_KEY_E)
                {
                    pCtx->tL1AlgCtx.tRsaSsaPkcs1v15Sign.pParm->tCfg.pPrivateKey          = NULL_PTR;
                    pCtx->tL1AlgCtx.tRsaSsaPkcs1v15Sign.pParm->tCfg.u32PrivateKeyByteCnt = 0u;
                }

                if (0u != pCtx->tL1AlgCtx.tRsaSsaPkcs1v15Sign.pParm->u32UserKeyID_KEY_N)
                {
                    pCtx->tL1AlgCtx.tRsaSsaPkcs1v15Sign.pParm->tCfg.pKeyN            = NULL_PTR;
                    pCtx->tL1AlgCtx.tRsaSsaPkcs1v15Sign.pParm->tCfg.u32KeyNByteCount = 0u;
                }
                /* else do nothing */
#endif

                eRet = HSM_FW_RsaSsaPkcs1v15Sign(&(pCtx->tCmd),
                                                 pCtx->tL1AlgCtx.tRsaSsaPkcs1v15Sign.pParm);
                if (HSM_STATUS_SUCCESS == eRet)
                {
                    pCtx->eStat = HSM_DRV_SM_ARITH;
                    eRet        = pCtx->pSendCmdCb(&(pCtx->tCmd));
                    if (HSM_STATUS_SUCCESS != eRet)
                    {
                        pCtx->eStat = HSM_DRV_SM_STOP;
                        eRet        = HSM_STATUS_SEND_FAIL;
                    }
                }
                else
                {
                    ;
                }
            }
            else
            {
                eRet = HSM_STATUS_BUSY;
            }
        }
        else
        {
            eRet = HSM_STATUS_LOGIC_ERR;
        }
    }
    else
    {
        eRet = HSM_STATUS_PARAM_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_RsaSsaPkcs1V15SignPoll(HSM_L1_RtCtxType *pCtx)
{
    HSM_StatusType eRet = HSM_STATUS_SUCCESS;
    HSM_BoolType   bInProcess;

    bInProcess = pCtx->bInProcess;

    if ((HSM_TRUE == bInProcess) && (HSM_OP_RSA_SSA_PKCS1V15_SIGN == pCtx->eOperationCata))
    {
        if (HSM_DRV_SM_ARITH == pCtx->eStat)
        {
            eRet = pCtx->pReadAckCb();
            if (HSM_STATUS_BUSY == eRet)
            {
                eRet = HSM_STATUS_AGAIN;
            }
            else if (HSM_STATUS_SUCCESS == eRet)
            {
                eRet = HSM_L1_RsaSsaPkcs1V15Sign_Isr(pCtx);
            }
            else
            {
                pCtx->eStat = HSM_DRV_SM_STOP;
            }
        }
        else
        {
            eRet = HSM_STATUS_HW_IDLE;
        }
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_RsaSsaPkcs1V15SignReset(HSM_L1_RtCtxType *pCtx)
{
    HSM_BoolType   bInProcess;
    HSM_StatusType eRet = HSM_STATUS_SUCCESS;

    bInProcess = pCtx->bInProcess;

    if ((HSM_TRUE == bInProcess) && (HSM_OP_RSA_SSA_PKCS1V15_SIGN == pCtx->eOperationCata))
    {
        if (HSM_DRV_SM_ARITH == pCtx->eStat)
        {
            eRet = pCtx->pCancelCmdCb();
        }

        if (HSM_STATUS_SUCCESS == eRet)
        {
            pCtx->eStat = HSM_DRV_SM_READY;
        }
        else
        {
            ;
        }
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_RsaSsaPkcs1V15SignExitEnv(HSM_L1_RtCtxType *pCtx)
{
    HSM_BoolType   bInProcess = pCtx->bInProcess;
    HSM_StatusType eRet       = HSM_STATUS_SUCCESS;

    if ((HSM_TRUE == bInProcess) && (HSM_OP_RSA_SSA_PKCS1V15_SIGN == pCtx->eOperationCata))
    {
        eRet = HSM_L1_CommonExitEnv(pCtx);
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_RsaSsaPkcs1V15Sign_Isr(HSM_L1_RtCtxType *pCtx)
{
    HSM_StatusType eRet;

    if (MAILBOXAPI_RET_SUCCESS == pCtx->tL1AlgCtx.tRsaSsaPkcs1v15Sign.pParm->u32HSMStatusRet)
    {
        eRet        = HSM_STATUS_SUCCESS;
        pCtx->eStat = HSM_DRV_SM_STOP;
    }
    else
    {
        eRet        = HSM_STATUS_HW_ERR;
        pCtx->eStat = HSM_DRV_SM_STOP;
    }

    return eRet;
}

HSM_StatusType HSM_L1_RsaSsaPssSignSetupEnv(HSM_L1_RtCtxType *pCtx)
{
    HSM_BoolType   bInProcess = HSM_FALSE;
    HSM_StatusType eRet       = HSM_STATUS_SUCCESS;

    bInProcess = pCtx->bInProcess;
    if (HSM_FALSE == bInProcess)
    {
        pCtx->bInProcess                     = HSM_TRUE;
        pCtx->eOperationCata                 = HSM_OP_RSA_SSA_PSS_SIGN;
        pCtx->eStat                          = HSM_DRV_SM_READY;
        pCtx->tL1AlgCtx.tRsaSsaPssSign.pParm = (HSMCom_RsaSsaPssSignType *)HSM_ADDRESS_UP_ALIGN(
            &(pCtx->tL1AlgCtx.tRsaSsaPssSign.aParmBuf[0]));

        eRet = HSM_STATUS_SUCCESS;
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_RsaSsaPssSignData(HSM_L1_RtCtxType                   *pCtx,
                                        const HSM_Ln_RsaSsaPssSignDataType *pCfg,
                                        hsm_uint32_t                        u32TimeoutMs)
{
    HSM_StatusType eRet       = HSM_STATUS_SUCCESS;
    HSM_BoolType   bInProcess = HSM_FALSE;

    if ((NULL_PTR != pCtx) && (NULL_PTR != pCfg))
    {
        bInProcess = pCtx->bInProcess;

        if ((HSM_TRUE == bInProcess) && (HSM_OP_RSA_SSA_PSS_SIGN == pCtx->eOperationCata))
        {
            if (HSM_DRV_SM_ARITH != pCtx->eStat)
            {
                pCtx->tL1AlgCtx.tRsaSsaPssSign.pParm->u32HSMStatusRet     = MAILBOXAPI_RET_NONE;
                pCtx->tL1AlgCtx.tRsaSsaPssSign.pParm->u32Timeout          = u32TimeoutMs;
                pCtx->tL1AlgCtx.tRsaSsaPssSign.pParm->u32UserKeyID_KEY_E  = pCfg->u32PrivateKeyId;
                pCtx->tL1AlgCtx.tRsaSsaPssSign.pParm->u32UserKeyID_KEY_N  = pCfg->u32KeyNId;
                pCtx->tL1AlgCtx.tRsaSsaPssSign.pParm->u32RsaBitCnt        = pCfg->u32RsaBitCnt;
                pCtx->tL1AlgCtx.tRsaSsaPssSign.pParm->tCfg.bUsePseudoRand = HSM_TRUE;
                pCtx->tL1AlgCtx.tRsaSsaPssSign.pParm->tCfg.eMgfHashType   = pCfg->eHashType;
                pCtx->tL1AlgCtx.tRsaSsaPssSign.pParm->tCfg.eInputFmt      = pCfg->eInputFmt;
                pCtx->tL1AlgCtx.tRsaSsaPssSign.pParm->tCfg.eOutputFmt     = pCfg->eOutputFmt;
                if (pCfg->u32RsaBitCnt > 0u)
                {
                    pCtx->tL1AlgCtx.tRsaSsaPssSign.pParm->tCfg.u32EmBitCnt = pCfg->u32RsaBitCnt - 1u;
                }
                else
                {
                    pCtx->tL1AlgCtx.tRsaSsaPssSign.pParm->tCfg.u32EmBitCnt = 0u;
                }
                pCtx->tL1AlgCtx.tRsaSsaPssSign.pParm->tCfg.eHashType = pCfg->eHashType;
                pCtx->tL1AlgCtx.tRsaSsaPssSign.pParm->tCfg.eInputType = HSM_RSA_SSA_INPUT_RAW_MESSAGE;
                pCtx->tL1AlgCtx.tRsaSsaPssSign.pParm->tCfg.pInputData = pCfg->pInputData;
                pCtx->tL1AlgCtx.tRsaSsaPssSign.pParm->tCfg.u32InputDataByteCount =
                    pCfg->u32InputDataByteCount;
                pCtx->tL1AlgCtx.tRsaSsaPssSign.pParm->tCfg.pPrivateKey = pCfg->pPrivateKey;
                pCtx->tL1AlgCtx.tRsaSsaPssSign.pParm->tCfg.u32PrivateKeyByteCnt =
                    pCfg->u32PrivateKeyByteCnt;
                pCtx->tL1AlgCtx.tRsaSsaPssSign.pParm->tCfg.bUseInputSaltData = HSM_FALSE;
                pCtx->tL1AlgCtx.tRsaSsaPssSign.pParm->tCfg.pSalt             = NULL_PTR;
                hsm_hash_get_result_byte_count(
                    (HFAM_MODE_E)pCfg->eHashType,
                    &pCtx->tL1AlgCtx.tRsaSsaPssSign.pParm->tCfg.u32SaltByteCount);
                pCtx->tL1AlgCtx.tRsaSsaPssSign.pParm->tCfg.pKeyN = pCfg->pKeyN;
                pCtx->tL1AlgCtx.tRsaSsaPssSign.pParm->tCfg.u32KeyNByteCount = pCfg->u32KeyNByteCount;
                pCtx->tL1AlgCtx.tRsaSsaPssSign.pParm->tCfg.pResult = pCfg->pResult;
                pCtx->tL1AlgCtx.tRsaSsaPssSign.pParm->tCfg.u32ResultBufByteCnt =
                    pCfg->u32ResultBufByteCnt;
                pCtx->tL1AlgCtx.tRsaSsaPssSign.pParm->tCfg.pResultByteCnt = pCfg->pResultByteCnt;

#if (FC7XXX_HSM_SUBSYSTEM_TYPE != FC7240_HSM_SUBSYSTEM)
                if (0u != pCtx->tL1AlgCtx.tRsaSsaPssSign.pParm->u32UserKeyID_KEY_E)
                {
                    pCtx->tL1AlgCtx.tRsaSsaPssSign.pParm->tCfg.pPrivateKey          = NULL_PTR;
                    pCtx->tL1AlgCtx.tRsaSsaPssSign.pParm->tCfg.u32PrivateKeyByteCnt = 0u;
                }

                if (0u != pCtx->tL1AlgCtx.tRsaSsaPssSign.pParm->u32UserKeyID_KEY_N)
                {
                    pCtx->tL1AlgCtx.tRsaSsaPssSign.pParm->tCfg.pKeyN            = NULL_PTR;
                    pCtx->tL1AlgCtx.tRsaSsaPssSign.pParm->tCfg.u32KeyNByteCount = 0u;
                }
                /* else do nothing */
#endif

                eRet = HSM_FW_RsaSsaPssSign(&(pCtx->tCmd), pCtx->tL1AlgCtx.tRsaSsaPssSign.pParm);
                if (HSM_STATUS_SUCCESS == eRet)
                {
                    pCtx->eStat = HSM_DRV_SM_ARITH;
                    eRet        = pCtx->pSendCmdCb(&(pCtx->tCmd));
                    if (HSM_STATUS_SUCCESS != eRet)
                    {
                        pCtx->eStat = HSM_DRV_SM_STOP;
                        eRet        = HSM_STATUS_SEND_FAIL;
                    }
                }
                else
                {
                    ;
                }
            }
            else
            {
                eRet = HSM_STATUS_BUSY;
            }
        }
        else
        {
            eRet = HSM_STATUS_LOGIC_ERR;
        }
    }
    else
    {
        eRet = HSM_STATUS_PARAM_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_RsaSsaPssSignHash(HSM_L1_RtCtxType                   *pCtx,
                                        const HSM_Ln_RsaSsaPssSignHashType *pCfg,
                                        hsm_uint32_t                        u32TimeoutMs)
{
    HSM_StatusType eRet       = HSM_STATUS_SUCCESS;
    HSM_BoolType   bInProcess = HSM_FALSE;

    if ((NULL_PTR != pCtx) && (NULL_PTR != pCfg))
    {
        bInProcess = pCtx->bInProcess;

        if ((HSM_TRUE == bInProcess) && (HSM_OP_RSA_SSA_PSS_SIGN == pCtx->eOperationCata))
        {
            if (HSM_DRV_SM_ARITH != pCtx->eStat)
            {
                pCtx->tL1AlgCtx.tRsaSsaPssSign.pParm->u32HSMStatusRet     = MAILBOXAPI_RET_NONE;
                pCtx->tL1AlgCtx.tRsaSsaPssSign.pParm->u32Timeout          = u32TimeoutMs;
                pCtx->tL1AlgCtx.tRsaSsaPssSign.pParm->u32UserKeyID_KEY_E  = pCfg->u32PrivateKeyId;
                pCtx->tL1AlgCtx.tRsaSsaPssSign.pParm->u32UserKeyID_KEY_N  = pCfg->u32KeyNId;
                pCtx->tL1AlgCtx.tRsaSsaPssSign.pParm->u32RsaBitCnt        = pCfg->u32RsaBitCnt;
                pCtx->tL1AlgCtx.tRsaSsaPssSign.pParm->tCfg.bUsePseudoRand = HSM_TRUE;
                pCtx->tL1AlgCtx.tRsaSsaPssSign.pParm->tCfg.eMgfHashType   = pCfg->eHashType;
                pCtx->tL1AlgCtx.tRsaSsaPssSign.pParm->tCfg.eInputFmt      = pCfg->eInputFmt;
                pCtx->tL1AlgCtx.tRsaSsaPssSign.pParm->tCfg.eOutputFmt     = pCfg->eOutputFmt;
                if (pCfg->u32RsaBitCnt > 0u)
                {
                    pCtx->tL1AlgCtx.tRsaSsaPssSign.pParm->tCfg.u32EmBitCnt = pCfg->u32RsaBitCnt - 1u;
                }
                else
                {
                    pCtx->tL1AlgCtx.tRsaSsaPssSign.pParm->tCfg.u32EmBitCnt = 0u;
                }
                pCtx->tL1AlgCtx.tRsaSsaPssSign.pParm->tCfg.eHashType  = pCfg->eHashType;
                pCtx->tL1AlgCtx.tRsaSsaPssSign.pParm->tCfg.eInputType = HSM_RSA_SSA_INPUT_HASH_DATA;
                pCtx->tL1AlgCtx.tRsaSsaPssSign.pParm->tCfg.pInputData = pCfg->pHashData;
                pCtx->tL1AlgCtx.tRsaSsaPssSign.pParm->tCfg.u32InputDataByteCount =
                    pCfg->u32HashDataByteCount;
                pCtx->tL1AlgCtx.tRsaSsaPssSign.pParm->tCfg.pPrivateKey = pCfg->pPrivateKey;
                pCtx->tL1AlgCtx.tRsaSsaPssSign.pParm->tCfg.u32PrivateKeyByteCnt =
                    pCfg->u32PrivateKeyByteCnt;
                pCtx->tL1AlgCtx.tRsaSsaPssSign.pParm->tCfg.bUseInputSaltData = HSM_FALSE;
                pCtx->tL1AlgCtx.tRsaSsaPssSign.pParm->tCfg.pSalt             = NULL_PTR;
                hsm_hash_get_result_byte_count(
                    (HFAM_MODE_E)pCfg->eHashType,
                    &pCtx->tL1AlgCtx.tRsaSsaPssSign.pParm->tCfg.u32SaltByteCount);
                pCtx->tL1AlgCtx.tRsaSsaPssSign.pParm->tCfg.pKeyN = pCfg->pKeyN;
                pCtx->tL1AlgCtx.tRsaSsaPssSign.pParm->tCfg.u32KeyNByteCount = pCfg->u32KeyNByteCount;
                pCtx->tL1AlgCtx.tRsaSsaPssSign.pParm->tCfg.pResult = pCfg->pResult;
                pCtx->tL1AlgCtx.tRsaSsaPssSign.pParm->tCfg.u32ResultBufByteCnt =
                    pCfg->u32ResultBufByteCnt;
                pCtx->tL1AlgCtx.tRsaSsaPssSign.pParm->tCfg.pResultByteCnt = pCfg->pResultByteCnt;

#if (FC7XXX_HSM_SUBSYSTEM_TYPE != FC7240_HSM_SUBSYSTEM)
                if (0u != pCtx->tL1AlgCtx.tRsaSsaPssSign.pParm->u32UserKeyID_KEY_E)
                {
                    pCtx->tL1AlgCtx.tRsaSsaPssSign.pParm->tCfg.pPrivateKey          = NULL_PTR;
                    pCtx->tL1AlgCtx.tRsaSsaPssSign.pParm->tCfg.u32PrivateKeyByteCnt = 0u;
                }

                if (0u != pCtx->tL1AlgCtx.tRsaSsaPssSign.pParm->u32UserKeyID_KEY_N)
                {
                    pCtx->tL1AlgCtx.tRsaSsaPssSign.pParm->tCfg.pKeyN            = NULL_PTR;
                    pCtx->tL1AlgCtx.tRsaSsaPssSign.pParm->tCfg.u32KeyNByteCount = 0u;
                }
                /* else do nothing */
#endif

                eRet = HSM_FW_RsaSsaPssSign(&(pCtx->tCmd), pCtx->tL1AlgCtx.tRsaSsaPssSign.pParm);
                if (HSM_STATUS_SUCCESS == eRet)
                {
                    pCtx->eStat = HSM_DRV_SM_ARITH;
                    eRet        = pCtx->pSendCmdCb(&(pCtx->tCmd));
                    if (HSM_STATUS_SUCCESS != eRet)
                    {
                        pCtx->eStat = HSM_DRV_SM_STOP;
                        eRet        = HSM_STATUS_SEND_FAIL;
                    }
                }
                else
                {
                    ;
                }
            }
            else
            {
                eRet = HSM_STATUS_BUSY;
            }
        }
        else
        {
            eRet = HSM_STATUS_LOGIC_ERR;
        }
    }
    else
    {
        eRet = HSM_STATUS_PARAM_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_RsaSsaPssSignPoll(HSM_L1_RtCtxType *pCtx)
{
    HSM_StatusType eRet = HSM_STATUS_SUCCESS;
    HSM_BoolType   bInProcess;

    bInProcess = pCtx->bInProcess;

    if ((HSM_TRUE == bInProcess) && (HSM_OP_RSA_SSA_PSS_SIGN == pCtx->eOperationCata))
    {
        if (HSM_DRV_SM_ARITH == pCtx->eStat)
        {
            eRet = pCtx->pReadAckCb();
            if (HSM_STATUS_BUSY == eRet)
            {
                eRet = HSM_STATUS_AGAIN;
            }
            else if (HSM_STATUS_SUCCESS == eRet)
            {
                eRet = HSM_L1_RsaSsaPssSign_Isr(pCtx);
            }
            else
            {
                pCtx->eStat = HSM_DRV_SM_STOP;
            }
        }
        else
        {
            eRet = HSM_STATUS_HW_IDLE;
        }
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_RsaSsaPssSignReset(HSM_L1_RtCtxType *pCtx)
{
    HSM_BoolType   bInProcess;
    HSM_StatusType eRet = HSM_STATUS_SUCCESS;

    bInProcess = pCtx->bInProcess;

    if ((HSM_TRUE == bInProcess) && (HSM_OP_RSA_SSA_PSS_SIGN == pCtx->eOperationCata))
    {
        if (HSM_DRV_SM_ARITH == pCtx->eStat)
        {
            eRet = pCtx->pCancelCmdCb();
        }

        if (HSM_STATUS_SUCCESS == eRet)
        {
            pCtx->eStat = HSM_DRV_SM_READY;
        }
        else
        {
            ;
        }
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_RsaSsaPssSignExitEnv(HSM_L1_RtCtxType *pCtx)
{
    HSM_BoolType   bInProcess = pCtx->bInProcess;
    HSM_StatusType eRet       = HSM_STATUS_SUCCESS;

    if ((HSM_TRUE == bInProcess) && (HSM_OP_RSA_SSA_PSS_SIGN == pCtx->eOperationCata))
    {
        eRet = HSM_L1_CommonExitEnv(pCtx);
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_RsaSsaPssSign_Isr(HSM_L1_RtCtxType *pCtx)
{
    HSM_StatusType eRet;

    if (MAILBOXAPI_RET_SUCCESS == pCtx->tL1AlgCtx.tRsaSsaPssSign.pParm->u32HSMStatusRet)
    {
        eRet        = HSM_STATUS_SUCCESS;
        pCtx->eStat = HSM_DRV_SM_STOP;
    }
    else
    {
        eRet        = HSM_STATUS_HW_ERR;
        pCtx->eStat = HSM_DRV_SM_STOP;
    }

    return eRet;
}

HSM_StatusType HSM_L1_Sm2VerifySetupEnv(HSM_L1_RtCtxType *pCtx)
{
    HSM_BoolType   bInProcess = HSM_FALSE;
    HSM_StatusType eRet       = HSM_STATUS_SUCCESS;

    bInProcess = pCtx->bInProcess;
    if (HSM_FALSE == bInProcess)
    {
        pCtx->bInProcess     = HSM_TRUE;
        pCtx->eOperationCata = HSM_OP_SM2_VERIFY;
        pCtx->eStat          = HSM_DRV_SM_READY;

        pCtx->tL1AlgCtx.tSm2VerifyInf.pParm =
            (HSMCom_Sm2VerifyType *)(&(pCtx->tL1AlgCtx.tSm2VerifyInf.aParmBuf[0]));
        pCtx->tL1AlgCtx.tSm2VerifyInf.pParm->tCfg.pInputData_MOrHash =
            pCtx->tL1AlgCtx.tSm2VerifyInf.aHash;
        pCtx->tL1AlgCtx.tSm2VerifyInf.pParm->tCfg.pInputData_R = &pCtx->tL1AlgCtx.tSm2VerifyInf.aR;
        pCtx->tL1AlgCtx.tSm2VerifyInf.pParm->tCfg.pInputData_S = &pCtx->tL1AlgCtx.tSm2VerifyInf.aS;
        pCtx->tL1AlgCtx.tSm2VerifyInf.pParm->tCfg.pPublicKey_X = &pCtx->tL1AlgCtx.tSm2VerifyInf.akGx;
        pCtx->tL1AlgCtx.tSm2VerifyInf.pParm->tCfg.pPublicKey_Y = &pCtx->tL1AlgCtx.tSm2VerifyInf.akGy;
        pCtx->tL1AlgCtx.tSm2VerifyInf.pParm->tCfg.pInputData_ID = pCtx->tL1AlgCtx.tSm2VerifyInf.aUserID;

        eRet = HSM_STATUS_SUCCESS;
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_Sm2VerifyExitEnv(HSM_L1_RtCtxType *pCtx)
{
    HSM_BoolType   bInProcess = pCtx->bInProcess;
    HSM_StatusType eRet       = HSM_STATUS_SUCCESS;

    if ((HSM_TRUE == bInProcess) && (HSM_OP_SM2_VERIFY == pCtx->eOperationCata))
    {
        eRet = HSM_L1_CommonExitEnv(pCtx);
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_Sm2Verify(HSM_L1_RtCtxType           *pCtx,
                                const HSM_L1_Sm2VerifyType *pCfg,
                                hsm_uint32_t                u32TimeoutMs)
{
    HSM_StatusType eRet       = HSM_STATUS_SUCCESS;
    HSM_BoolType   bInProcess = HSM_FALSE;

    if ((NULL_PTR != pCtx) && (NULL_PTR != pCfg))
    {
        bInProcess = pCtx->bInProcess;

        if ((HSM_TRUE == bInProcess) && (HSM_OP_SM2_VERIFY == pCtx->eOperationCata))
        {
            if (HSM_DRV_SM_ARITH != pCtx->eStat)
            {
                if ((pCfg->u32kGxByteCnt == 32u) && (pCfg->u32kGyByteCnt == 32u) &&
                    (pCfg->u32SM2InputIDByteCnt <= (sizeof(pCtx->tL1AlgCtx.tSm2VerifyInf.aUserID))) &&
                    (pCfg->u32RByteCnt == 32u) && (pCfg->u32SByteCnt == 32u))
                {
                    pCtx->tL1AlgCtx.tSm2VerifyInf.pParm->u32HSMStatusRet = MAILBOXAPI_RET_NONE;
                    pCtx->tL1AlgCtx.tSm2VerifyInf.pParm->u32Timeout      = u32TimeoutMs;
                    pCtx->tL1AlgCtx.tSm2VerifyInf.pParm->u32UserKeyID_PublicKey = pCfg->u32PublicKeyId;
                    pCtx->tL1AlgCtx.tSm2VerifyInf.pParm->tCfg.bHashInput    = HSM_TRUE;
                    pCtx->tL1AlgCtx.tSm2VerifyInf.pParm->tCfg.bUseDefaultID = pCfg->bUseDefaultID;

                    if (0u == pCfg->u32PublicKeyId)
                    {
                        hsm_memcpy((void *)(&(pCtx->tL1AlgCtx.tSm2VerifyInf.akGx[0])), pCfg->pkGx, 32u);
                        hsm_memcpy((void *)(&(pCtx->tL1AlgCtx.tSm2VerifyInf.akGy[0])), pCfg->pkGy, 32u);

                        if (HSM_DATA_FORMAT_1B == pCfg->ekGxyDataFmt)
                        {
                            hsm_u32_array_swap(
                                (hsm_uint32_t *)(&(pCtx->tL1AlgCtx.tSm2VerifyInf.akGx[0])),
                                8u);
                            hsm_u32_array_swap(
                                (hsm_uint32_t *)(&(pCtx->tL1AlgCtx.tSm2VerifyInf.akGy[0])),
                                8u);
                        }
                    }

                    hsm_memcpy((void *)(&(pCtx->tL1AlgCtx.tSm2VerifyInf.aHash[0])), pCfg->pData, 32u);
                    if (HSM_DATA_FORMAT_1B == pCfg->eDataFmt)
                    {
                        hsm_u32_array_swap((hsm_uint32_t *)(&(pCtx->tL1AlgCtx.tSm2VerifyInf.aHash[0])),
                                           8u);
                    }

                    hsm_memcpy((void *)(&(pCtx->tL1AlgCtx.tSm2VerifyInf.aR[0])), pCfg->pR, 32u);
                    hsm_memcpy((void *)(&(pCtx->tL1AlgCtx.tSm2VerifyInf.aS[0])), pCfg->pS, 32u);
                    if (HSM_DATA_FORMAT_1B == pCfg->eRSDataFmt)
                    {
                        hsm_u32_array_swap((hsm_uint32_t *)(&(pCtx->tL1AlgCtx.tSm2VerifyInf.aR[0])),
                                           8u);
                        hsm_u32_array_swap((hsm_uint32_t *)(&(pCtx->tL1AlgCtx.tSm2VerifyInf.aS[0])),
                                           8u);
                    }

                    if (HSM_FALSE == pCfg->bUseDefaultID)
                    {
                        hsm_memset(&(pCtx->tL1AlgCtx.tSm2VerifyInf.aUserID[0]),
                                   0,
                                   sizeof(pCtx->tL1AlgCtx.tSm2VerifyInf.aUserID));
                        if (HSM_DATA_FORMAT_1B == pCfg->eDataFmt)
                        {
                            hsm_memcpy((void *)(&(pCtx->tL1AlgCtx.tSm2VerifyInf.aUserID[0])),
                                       pCfg->pInputData_ID,
                                       pCfg->u32SM2InputIDByteCnt);
                            hsm_u32_array_swap(
                                (hsm_uint32_t *)(&(pCtx->tL1AlgCtx.tSm2VerifyInf.aUserID[0])),
                                HSM_ADDRESS_UP_ALIGN(pCfg->u32SM2InputIDByteCnt) >> 2u);
                        }
                        else
                        {
                            hsm_memcpy((void *)(&(pCtx->tL1AlgCtx.tSm2VerifyInf.aUserID[0])),
                                       pCfg->pInputData_ID,
                                       HSM_ADDRESS_UP_ALIGN(pCfg->u32SM2InputIDByteCnt));
                        }
                        pCtx->tL1AlgCtx.tSm2VerifyInf.pParm->tCfg.u32SM2InputIDByteCnt =
                            pCfg->u32SM2InputIDByteCnt;
                    }

                    eRet = HSM_Sm2Verify(&(pCtx->tCmd), pCtx->tL1AlgCtx.tSm2VerifyInf.pParm);
                    if (HSM_STATUS_SUCCESS == eRet)
                    {
                        pCtx->eStat = HSM_DRV_SM_ARITH;
                        eRet        = pCtx->pSendCmdCb(&(pCtx->tCmd));
                        if (HSM_STATUS_SUCCESS != eRet)
                        {
                            pCtx->eStat = HSM_DRV_SM_STOP;
                            eRet        = HSM_STATUS_SEND_FAIL;
                        }
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
                eRet = HSM_STATUS_BUSY;
            }
        }
        else
        {
            eRet = HSM_STATUS_LOGIC_ERR;
        }
    }
    else
    {
        eRet = HSM_STATUS_PARAM_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_Sm2Verify_Isr(HSM_L1_RtCtxType *pCtx)
{
    HSM_StatusType eRet;

    if (MAILBOXAPI_RET_PASS == pCtx->tL1AlgCtx.tSm2VerifyInf.pParm->u32HSMStatusRet)
    {
        eRet        = HSM_STATUS_PASS;
        pCtx->eStat = HSM_DRV_SM_STOP;
    }
    else if (MAILBOXAPI_RET_FAIL == pCtx->tL1AlgCtx.tSm2VerifyInf.pParm->u32HSMStatusRet)
    {
        eRet        = HSM_STATUS_FAIL;
        pCtx->eStat = HSM_DRV_SM_STOP;
    }
    else
    {
        eRet        = HSM_STATUS_ERROR;
        pCtx->eStat = HSM_DRV_SM_STOP;
    }

    return eRet;
}

HSM_StatusType HSM_L1_Sm2VerifyPoll(HSM_L1_RtCtxType *pCtx)
{
    HSM_StatusType eRet       = HSM_STATUS_SUCCESS;
    HSM_BoolType   bInProcess = HSM_FALSE;

    bInProcess = pCtx->bInProcess;

    if ((HSM_TRUE == bInProcess) && (HSM_OP_SM2_VERIFY == pCtx->eOperationCata))
    {
        if (HSM_DRV_SM_ARITH == pCtx->eStat)
        {
            eRet = pCtx->pReadAckCb();
            if (HSM_STATUS_BUSY == eRet)
            {
                eRet = HSM_STATUS_AGAIN;
            }
            else if (HSM_STATUS_SUCCESS == eRet)
            {
                eRet = HSM_L1_Sm2Verify_Isr(pCtx);
            }
            else
            {
                pCtx->eStat = HSM_DRV_SM_STOP;
            }
        }
        else
        {
            eRet = HSM_STATUS_HW_IDLE;
        }
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_Sm2VerifyReset(HSM_L1_RtCtxType *pCtx)
{
    HSM_BoolType   bInProcess = HSM_FALSE;
    HSM_StatusType eRet       = HSM_STATUS_SUCCESS;

    bInProcess = pCtx->bInProcess;

    if ((HSM_TRUE == bInProcess) && (HSM_OP_SM2_VERIFY == pCtx->eOperationCata))
    {
        if (HSM_DRV_SM_ARITH == pCtx->eStat)
        {
            eRet = pCtx->pCancelCmdCb();
        }

        if (HSM_STATUS_SUCCESS == eRet)
        {
            pCtx->eStat = HSM_DRV_SM_READY;
        }
        else
        {
            ;
        }
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_Sm2GenZaSetupEnv(HSM_L1_RtCtxType *pCtx)
{
    HSM_BoolType   bInProcess = HSM_FALSE;
    HSM_StatusType eRet       = HSM_STATUS_SUCCESS;

    bInProcess = pCtx->bInProcess;
    if (HSM_FALSE == bInProcess)
    {
        pCtx->bInProcess     = HSM_TRUE;
        pCtx->eOperationCata = HSM_OP_SM2_GEN_ZA;
        pCtx->eStat          = HSM_DRV_SM_READY;

        pCtx->tL1AlgCtx.tSm2GenZaInf.pParm =
            (HSMCom_Sm2GenZaType *)(&(pCtx->tL1AlgCtx.tSm2GenZaInf.aParmBuf[0]));
        pCtx->tL1AlgCtx.tSm2GenZaInf.pParm->tCfg.pPublicKey_X = &pCtx->tL1AlgCtx.tSm2GenZaInf.akGx;
        pCtx->tL1AlgCtx.tSm2GenZaInf.pParm->tCfg.pPublicKey_Y = &pCtx->tL1AlgCtx.tSm2GenZaInf.akGy;
        pCtx->tL1AlgCtx.tSm2GenZaInf.pParm->tCfg.pInputData_ID = pCtx->tL1AlgCtx.tSm2GenZaInf.aUserID;

        eRet = HSM_STATUS_SUCCESS;
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_Sm2GenZaExitEnv(HSM_L1_RtCtxType *pCtx)
{
    HSM_BoolType   bInProcess = pCtx->bInProcess;
    HSM_StatusType eRet       = HSM_STATUS_SUCCESS;

    if ((HSM_TRUE == bInProcess) && (HSM_OP_SM2_GEN_ZA == pCtx->eOperationCata))
    {
        eRet = HSM_L1_CommonExitEnv(pCtx);
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_Sm2GenZa(HSM_L1_RtCtxType          *pCtx,
                               const HSM_LN_Sm2GenZaType *pCfg,
                               hsm_uint32_t               u32TimeoutMs)
{
    HSM_StatusType eRet       = HSM_STATUS_SUCCESS;
    HSM_BoolType   bInProcess = HSM_FALSE;

    if ((NULL_PTR != pCtx) && (NULL_PTR != pCfg))
    {
        bInProcess = pCtx->bInProcess;

        if ((HSM_TRUE == bInProcess) && (HSM_OP_SM2_GEN_ZA == pCtx->eOperationCata))
        {
            if (HSM_DRV_SM_ARITH != pCtx->eStat)
            {
                if ((pCfg->u32kGxByteCnt == 32u) && (pCfg->u32kGyByteCnt == 32u) &&
                    (pCfg->u32SM2InputIDByteCnt <= (sizeof(pCtx->tL1AlgCtx.tSm2GenZaInf.aUserID))))
                {
                    pCtx->tL1AlgCtx.tSm2GenZaInf.pParm->u32HSMStatusRet = MAILBOXAPI_RET_NONE;
                    pCtx->tL1AlgCtx.tSm2GenZaInf.pParm->u32Timeout      = u32TimeoutMs;
                    pCtx->tL1AlgCtx.tSm2GenZaInf.pParm->u32UserKeyID_PublicKey = pCfg->u32PublicKeyId;
                    pCtx->tL1AlgCtx.tSm2GenZaInf.pParm->tCfg.bUseDefaultID  = pCfg->bUseDefaultID;
                    pCtx->tL1AlgCtx.tSm2GenZaInf.pParm->tCfg.pOutputData_Za = pCfg->pOutputData_Za;

                    if (HSM_DATA_FORMAT_1B == pCfg->eOutputFmt)
                    {
                        pCtx->tL1AlgCtx.tSm2GenZaInf.bSwapOut = HSM_TRUE;
                    }
                    else
                    {
                        pCtx->tL1AlgCtx.tSm2GenZaInf.bSwapOut = HSM_FALSE;
                    }

                    if (0u == pCfg->u32PublicKeyId)
                    {
                        hsm_memcpy((void *)(&(pCtx->tL1AlgCtx.tSm2GenZaInf.akGx[0])), pCfg->pkGx, 32u);
                        hsm_memcpy((void *)(&(pCtx->tL1AlgCtx.tSm2GenZaInf.akGy[0])), pCfg->pkGy, 32u);
                        if (HSM_DATA_FORMAT_1B == pCfg->ekGxyDataFmt)
                        {
                            hsm_u32_array_swap(
                                (hsm_uint32_t *)(&(pCtx->tL1AlgCtx.tSm2GenZaInf.akGx[0])),
                                8u);
                            hsm_u32_array_swap(
                                (hsm_uint32_t *)(&(pCtx->tL1AlgCtx.tSm2GenZaInf.akGy[0])),
                                8u);
                        }
                    }

                    if (HSM_FALSE == pCfg->bUseDefaultID)
                    {
                        hsm_memset(&(pCtx->tL1AlgCtx.tSm2GenZaInf.aUserID[0]),
                                   0,
                                   sizeof(pCtx->tL1AlgCtx.tSm2GenZaInf.aUserID));
                        if (HSM_DATA_FORMAT_1B == pCfg->eDataFmt)
                        {
                            hsm_memcpy((void *)(&(pCtx->tL1AlgCtx.tSm2GenZaInf.aUserID[0])),
                                       pCfg->pInputData_ID,
                                       pCfg->u32SM2InputIDByteCnt);
                            hsm_u32_array_swap(
                                (hsm_uint32_t *)(&(pCtx->tL1AlgCtx.tSm2GenZaInf.aUserID[0])),
                                HSM_ADDRESS_UP_ALIGN(pCfg->u32SM2InputIDByteCnt) >> 2u);
                        }
                        else
                        {
                            hsm_memcpy((void *)(&(pCtx->tL1AlgCtx.tSm2GenZaInf.aUserID[0])),
                                       pCfg->pInputData_ID,
                                       HSM_ADDRESS_UP_ALIGN(pCfg->u32SM2InputIDByteCnt));
                        }
                        pCtx->tL1AlgCtx.tSm2GenZaInf.pParm->tCfg.u32SM2InputIDByteCnt =
                            pCfg->u32SM2InputIDByteCnt;
                    }

                    eRet = HSM_Sm2GenZa(&(pCtx->tCmd), pCtx->tL1AlgCtx.tSm2GenZaInf.pParm);
                    if (HSM_STATUS_SUCCESS == eRet)
                    {
                        pCtx->eStat = HSM_DRV_SM_ARITH;
                        eRet        = pCtx->pSendCmdCb(&(pCtx->tCmd));
                        if (HSM_STATUS_SUCCESS != eRet)
                        {
                            pCtx->eStat = HSM_DRV_SM_STOP;
                            eRet        = HSM_STATUS_SEND_FAIL;
                        }
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
                eRet = HSM_STATUS_BUSY;
            }
        }
        else
        {
            eRet = HSM_STATUS_LOGIC_ERR;
        }
    }
    else
    {
        eRet = HSM_STATUS_PARAM_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_Sm2GenZa_Isr(HSM_L1_RtCtxType *pCtx)
{
    HSM_StatusType eRet;

    if (MAILBOXAPI_RET_SUCCESS == pCtx->tL1AlgCtx.tSm2GenZaInf.pParm->u32HSMStatusRet)
    {
        if (HSM_TRUE == pCtx->tL1AlgCtx.tSm2GenZaInf.bSwapOut)
        {
            hsm_u32_array_swap(
                (hsm_uint32_t *)(pCtx->tL1AlgCtx.tSm2GenZaInf.pParm->tCfg.pOutputData_Za),
                8u);
        }

        eRet        = HSM_STATUS_SUCCESS;
        pCtx->eStat = HSM_DRV_SM_STOP;
    }
    else
    {
        eRet        = HSM_STATUS_ERROR;
        pCtx->eStat = HSM_DRV_SM_STOP;
    }

    return eRet;
}

HSM_StatusType HSM_L1_Sm2GenZaPoll(HSM_L1_RtCtxType *pCtx)
{
    HSM_StatusType eRet       = HSM_STATUS_SUCCESS;
    HSM_BoolType   bInProcess = HSM_FALSE;

    bInProcess = pCtx->bInProcess;

    if ((HSM_TRUE == bInProcess) && (HSM_OP_SM2_GEN_ZA == pCtx->eOperationCata))
    {
        if (HSM_DRV_SM_ARITH == pCtx->eStat)
        {
            eRet = pCtx->pReadAckCb();
            if (HSM_STATUS_BUSY == eRet)
            {
                eRet = HSM_STATUS_AGAIN;
            }
            else if (HSM_STATUS_SUCCESS == eRet)
            {
                eRet = HSM_L1_Sm2GenZa_Isr(pCtx);
            }
            else
            {
                pCtx->eStat = HSM_DRV_SM_STOP;
            }
        }
        else
        {
            eRet = HSM_STATUS_HW_IDLE;
        }
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_Sm2GenZaReset(HSM_L1_RtCtxType *pCtx)
{
    HSM_BoolType   bInProcess = HSM_FALSE;
    HSM_StatusType eRet       = HSM_STATUS_SUCCESS;

    bInProcess = pCtx->bInProcess;

    if ((HSM_TRUE == bInProcess) && (HSM_OP_SM2_GEN_ZA == pCtx->eOperationCata))
    {
        if (HSM_DRV_SM_ARITH == pCtx->eStat)
        {
            eRet = pCtx->pCancelCmdCb();
        }

        if (HSM_STATUS_SUCCESS == eRet)
        {
            pCtx->eStat = HSM_DRV_SM_READY;
        }
        else
        {
            ;
        }
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }

    return eRet;
}

HSM_StatusType HSM_L1_PKCS1_GetRsaPrivateKeyInfFromDer(const hsm_uint8_t                *pDer,
                                                       HSM_L1_PKCS_RsaPrivateKeyInfType *pInf)
{
    HSM_StatusType     eRet = HSM_STATUS_ERROR;
    hsm_uint32_t       aLength[3u];
    const hsm_uint8_t *aDataPointer[3u];
    hsm_uint32_t       u32Temp;
    hsm_uint32_t       u32Idx;
    hsm_uint32_t       u32Length;
    const hsm_uint8_t *pPerData = pDer;

    if (0x30u == (*pPerData))
    {
        pPerData++;

        if (0x80u & (*pPerData))
        {
            pPerData += ((*pPerData) & 0x7Fu);
        }

        pPerData++;

        /* version */
        pPerData += 3u;

        /* n */

        for (u32Idx = 0u; u32Idx < 3u; u32Idx++)
        {
            if (0x02u == (*pPerData))
            {
                pPerData++;

                if (0x80u & (*pPerData))
                {
                    u32Temp = ((*pPerData) & 0x7Fu);

                    u32Length = 0u;

                    while (u32Temp > 0u)
                    {
                        pPerData++;

                        u32Length = (u32Length << 8u) | (*pPerData);

                        u32Temp--;
                    }
                }
                else
                {
                    u32Length = (*pPerData);
                }

                pPerData++;

                aDataPointer[u32Idx] = pPerData;
                aLength[u32Idx]      = u32Length;

                pPerData += u32Length;
            }
            else
            {
                break; /* error */
            }
        }

        if (u32Idx == 3u)
        {
            for (u32Idx = 0u; u32Idx < 3u; u32Idx++)
            {
                while ((*(aDataPointer[u32Idx]) == 0u) && (aLength[u32Idx] > 1u))
                {
                    aDataPointer[u32Idx]++;
                    aLength[u32Idx]--;
                }
            }

            pInf->pN = aDataPointer[0u];
            pInf->pE = aDataPointer[1u];
            pInf->pD = aDataPointer[2u];

            pInf->u32NByteCnt = aLength[0u];
            pInf->u32EByteCnt = aLength[1u];
            pInf->u32DByteCnt = aLength[2u];

            eRet = HSM_STATUS_SUCCESS;
        }
    }

    return eRet;
}

HSM_StatusType HSM_L1_PKCS1_GetEccPrivateKeyInfFromDer(const hsm_uint8_t                *pDer,
                                                       HSM_L1_PKCS_EccPrivateKeyInfType *pInf)
{
    HSM_StatusType     eRet = HSM_STATUS_ERROR;
    hsm_uint32_t       aLength[1u];
    const hsm_uint8_t *aDataPointer[1u];
    hsm_uint32_t       u32Temp;
    hsm_uint32_t       u32Length;
    const hsm_uint8_t *pPerData = pDer;

    if (0x30u == (*pPerData))
    {
        pPerData++;

        if (0x80u & (*pPerData))
        {
            pPerData += ((*pPerData) & 0x7Fu);
        }

        pPerData++;

        /* version */
        pPerData += 3u;

        /* privateKey */

        if (0x04u == (*pPerData))
        {
            pPerData++;

            if (0x80u & (*pPerData))
            {
                u32Temp = (hsm_uint32_t)((hsm_uint32_t)(*pPerData) & 0x7Fu);

                u32Length = 0u;

                while (u32Temp > 0u)
                {
                    pPerData++;

                    u32Length = (u32Length << 8u) | (*pPerData);

                    u32Temp--;
                }
            }
            else
            {
                u32Length = (*pPerData);
            }

            pPerData++;

            aDataPointer[0u] = pPerData;
            aLength[0u]      = u32Length;

            pPerData += u32Length;

            eRet = HSM_STATUS_SUCCESS;
            /* to be continue */
        }
        /* else do nothing */
    }

    if (HSM_STATUS_SUCCESS == eRet)
    {
        while ((*(aDataPointer[0u]) == 0u) && (aLength[0u] > 1u))
        {
            aDataPointer[0u]++;
            aLength[0u]--;
        }

        pInf->pPrivate          = aDataPointer[0u];
        pInf->u32PrivateByteCnt = aLength[0u];
    }

    return eRet;
}

HSM_StatusType HSM_L1_PKCS8_GetPrivateKeyInfFromDer(const hsm_uint8_t              *pDer,
                                                    HSM_L1_PKCS8_PrivateKeyInfType *pInf)
{
    HSM_StatusType     eRet     = HSM_STATUS_ERROR;
    const hsm_uint8_t *pPerData = pDer;

    if (0x30u == (*pPerData))
    {
        pPerData++;

        if (0x80u & (*pPerData))
        {
            pPerData += ((*pPerData) & 0x7Fu);
        }

        pPerData++;

        /* version */
        pPerData += 3u;

        /* privateKeyAlgorithm */
        pPerData += 3u;
        if (0x9u == (*pPerData)) /* RSA OID length */
        {
            pPerData += (*pPerData);
            /* 2a864886f70d010101 privateKeyAlgorithm.algorithm */
            if (0x1u == (*pPerData)) /* oid last byte check */
            {
                pPerData++;
                /* privateKeyAlgorithm.parameter */

                pPerData += 2u;
                /* privateKey */

                if (0x04u == (*pPerData))
                {
                    pPerData++;

                    if (0x80u & (*pPerData))
                    {
                        pPerData += ((*pPerData) & 0x7Fu);
                    }

                    pPerData++;
                    /* RSAPrivateKey, pkcs1 format */

                    eRet = HSM_L1_PKCS1_GetRsaPrivateKeyInfFromDer(pPerData,
                                                                   &(pInf->tPrivateInfo.tRsaKeyInf));
                    if (HSM_STATUS_SUCCESS == eRet)
                    {
                        pInf->eKeyType = HSM_L1_PKCS8_RSA_PRIVATE_KEY;
                    }
                    /* else do nothing */
                }
            }
        }
        else if (0x7u == (*pPerData)) /* ECC OID length */
        {
            pPerData += (*pPerData);
            /* 2a8648ce3d0201 privateKeyAlgorithm.algorithm */
            if (0x1u == (*pPerData)) /* oid last byte check */
            {
                pPerData++;
                /* privateKeyAlgorithm.parameter */

                pPerData++; /* after pPerData address, the following is the curve type OID */
                pPerData += (*pPerData);

                pPerData++;
                /* privateKey */

                if (0x04u == (*pPerData))
                {
                    pPerData++;

                    if (0x80u & (*pPerData))
                    {
                        pPerData += ((*pPerData) & 0x7Fu);
                    }

                    pPerData++;
                    /* ECPrivateKey, pkcs1 format */
                    eRet = HSM_L1_PKCS1_GetEccPrivateKeyInfFromDer(pPerData,
                                                                   &(pInf->tPrivateInfo.tEccKeyInf));
                    if (HSM_STATUS_SUCCESS == eRet)
                    {
                        pInf->eKeyType = HSM_L1_PKCS8_ECC_PRIVATE_KEY;
                    }
                    /* else do nothing */
                }
            }
        }
        else
        {
            /* PRQA S 2013 */
        }
    }

    return eRet;
}

HSM_StatusType HSM_L1_PKCS1_GetRsaPublicKeyInfFromDer(const hsm_uint8_t               *pDer,
                                                      HSM_L1_PKCS_RsaPublicKeyInfType *pInf)
{
    HSM_StatusType     eRet = HSM_STATUS_ERROR;
    hsm_uint32_t       aLength[2u];
    const hsm_uint8_t *aDataPointer[2u];
    hsm_uint32_t       u32Temp;
    hsm_uint32_t       u32Idx;
    hsm_uint32_t       u32Length;
    const hsm_uint8_t *pPerData = pDer;

    if (0x30u == (*pPerData))
    {
        pPerData++;

        if (0x80u & (*pPerData))
        {
            pPerData += ((*pPerData) & 0x7Fu);
        }

        pPerData++;

        for (u32Idx = 0u; u32Idx < 2u; u32Idx++)
        {
            if (0x02u == (*pPerData))
            {
                pPerData++;

                if (0x80u & (*pPerData))
                {
                    u32Temp = (hsm_uint32_t)((hsm_uint32_t)(*pPerData) & 0x7Fu);

                    u32Length = 0u;

                    while (u32Temp > 0u)
                    {
                        pPerData++;

                        u32Length = (u32Length << 8u) | (*pPerData);

                        u32Temp--;
                    }
                }
                else
                {
                    u32Length = (*pPerData);
                }

                pPerData++;

                aDataPointer[u32Idx] = pPerData;
                aLength[u32Idx]      = u32Length;

                pPerData += u32Length;
            }
            else
            {
                break; /* error */
            }
        }

        if (u32Idx == 2u)
        {
            for (u32Idx = 0u; u32Idx < 2u; u32Idx++)
            {
                while ((*(aDataPointer[u32Idx]) == 0u) && (aLength[u32Idx] > 1u))
                {
                    aDataPointer[u32Idx]++;
                    aLength[u32Idx]--;
                }
            }

            pInf->pN          = aDataPointer[0u];
            pInf->u32NByteCnt = aLength[0u];
            pInf->pE          = aDataPointer[1u];
            pInf->u32EByteCnt = aLength[1u];

            eRet = HSM_STATUS_SUCCESS;
        }
    }

    return eRet;
}

HSM_StatusType hsm_l1_subjectpublicinfo_bitstring_geteccpublickeyinf(
    const hsm_uint8_t               *pDer,
    HSM_L1_PKCS_EccPublicKeyInfType *pInf)
{
    HSM_StatusType     eRet = HSM_STATUS_ERROR;
    hsm_uint32_t       aLength[2u];
    const hsm_uint8_t *aDataPointer[2u];
    hsm_uint32_t       u32Temp;
    hsm_uint32_t       u32Length;
    const hsm_uint8_t *pPerData = pDer;

    if (0x03u == (*pPerData))
    {
        pPerData++;

        if (0x80u & (*pPerData))
        {
            u32Temp = (hsm_uint32_t)((hsm_uint32_t)(*pPerData) & 0x7Fu);

            u32Length = 0u;

            while (u32Temp > 0u)
            {
                pPerData++;

                u32Length = (u32Length << 8u) | (*pPerData);

                u32Temp--;
            }
        }
        else
        {
            u32Length = (*pPerData);
        }

        pPerData++;

        u32Length -= 2u; /* byte count remove leading byte and compressed/uncompressed format byte */

        if (0x0u == (*pPerData)) /* not support bit string shift now */
        {
            pPerData++;

            if (0x04u == (*pPerData)) /* uncompressed format */
            {
                pPerData++;

                aDataPointer[0u] = pPerData;
                aLength[0u]      = u32Length >> 1u;
                aDataPointer[1u] = pPerData + aLength[0u];
                aLength[1u]      = u32Length >> 1u;

                eRet = HSM_STATUS_SUCCESS;
            }
        }
    }

    if (HSM_STATUS_SUCCESS == eRet)
    {
        pInf->pKGx = aDataPointer[0u];
        pInf->pKGy = aDataPointer[1u];

        pInf->u32KGxByteCnt = aLength[0u];
        pInf->u32KGyByteCnt = aLength[1u];
    }

    return eRet;
}

HSM_StatusType HSM_L1_SubjectPublicInfo_GetPublicKeyInfFromDer(const hsm_uint8_t       *pDer,
                                                               HSM_L1_PublicKeyInfType *pInf)
{
    HSM_StatusType     eRet     = HSM_STATUS_ERROR;
    const hsm_uint8_t *pPerData = pDer;

    if (0x30u == (*pPerData))
    {
        pPerData++;

        if (0x80u & (*pPerData))
        {
            pPerData += ((*pPerData) & 0x7Fu);
        }

        pPerData++;

        /* algorithm  AlgorithmIdentifier */
        pPerData += 3u;
        if (0x9u == (*pPerData)) /* RSA OID length */
        {
            pPerData += (*pPerData);
            /* 2a864886f70d010101 algorithm */
            if (0x1u == (*pPerData)) /* oid last byte check */
            {
                pPerData++;
                /* parameter */

                pPerData += 2u;
                /*  bit string RSAPublicKey wrapper */

                if (0x03u == (*pPerData))
                {
                    pPerData++;

                    if (0x80u & (*pPerData))
                    {
                        pPerData += ((*pPerData) & 0x7Fu);
                    }

                    pPerData++;
                    /* bit string leading byte */

                    if (0x0u == (*pPerData))
                    {
                        pPerData++;
                        /* RSAPublicKey */

                        eRet = HSM_L1_PKCS1_GetRsaPublicKeyInfFromDer(pPerData,
                                                                      &(pInf->tPublicInf.tRsaKeyInf));
                        if (HSM_STATUS_SUCCESS == eRet)
                        {
                            pInf->eKeyType = HSM_L1_RSA_PUBLIC_KEY;
                        }
                        /* else do nothing */
                    }
                }
            }
        }
        else if (0x7u == (*pPerData)) /* ECC OID length */
        {
            pPerData += (*pPerData);
            /* 2a8648ce3d0201 OBJ_X9_62_id_ecPublicKey */
            if (0x1u == (*pPerData)) /* oid last byte check */
            {
                pPerData++;
                /* parameter */

                pPerData++; /* after pPerData address, the following is the curve type OID */
                pPerData += (*pPerData);

                pPerData++;
                /* public key  */

                eRet = hsm_l1_subjectpublicinfo_bitstring_geteccpublickeyinf(
                    pPerData,
                    &(pInf->tPublicInf.tEccKeyInf));
                if (HSM_STATUS_SUCCESS == eRet)
                {
                    pInf->eKeyType = HSM_L1_ECC_PUBLIC_KEY;
                }
                /* else do nothing */
            }
        }
        else
        {
            /* PRQA S 2013 */
        }
    }

    return eRet;
}

HSM_StatusType HSM_L1_LoadFirmwareSetupEnv(HSM_L1_RtCtxType *pCtx)
{
    HSM_BoolType   bInProcess = HSM_FALSE;
    HSM_StatusType eRet       = HSM_STATUS_SUCCESS;
    bInProcess                = pCtx->bInProcess;
    if (HSM_FALSE == bInProcess)
    {
        pCtx->bInProcess                    = HSM_TRUE;
        pCtx->eOperationCata                = HSM_OP_LOAD_FIRMWARE;
        pCtx->eStat                         = HSM_DRV_SM_READY;
        pCtx->tL1AlgCtx.tLoadFirmware.pParm = (HSMCom_LoadFirmwareType *)HSM_ADDRESS_UP_ALIGN(
            &(pCtx->tL1AlgCtx.tLoadFirmware.aParmBuf[0]));
        eRet = HSM_STATUS_SUCCESS;
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }
    return eRet;
}
HSM_StatusType HSM_L1_LoadFirmware(HSM_L1_RtCtxType *pCtx, uint32 u32TimeoutMs)
{
    HSM_StatusType eRet       = HSM_STATUS_SUCCESS;
    HSM_BoolType   bInProcess = HSM_FALSE;
    if (NULL_PTR != pCtx)
    {
        bInProcess = pCtx->bInProcess;
        if ((HSM_TRUE == bInProcess) && (HSM_OP_LOAD_FIRMWARE == pCtx->eOperationCata))
        {
            if (HSM_DRV_SM_ARITH != pCtx->eStat)
            {
                pCtx->tL1AlgCtx.tLoadFirmware.pParm->u32HSMStatusRet = MAILBOXAPI_RET_NONE;
                pCtx->tL1AlgCtx.tLoadFirmware.pParm->u32Timeout      = u32TimeoutMs;
                eRet = HSM_LoadFirmware(&(pCtx->tCmd), pCtx->tL1AlgCtx.tLoadFirmware.pParm);
                if (HSM_STATUS_SUCCESS == eRet)
                {
                    pCtx->eStat = HSM_DRV_SM_ARITH;
                    eRet        = pCtx->pSendCmdCb(&(pCtx->tCmd));
                    if (HSM_STATUS_SUCCESS != eRet)
                    {
                        pCtx->eStat = HSM_DRV_SM_STOP;
                        eRet        = HSM_STATUS_SEND_FAIL;
                    }
                }
                else
                {
                    ;
                }
            }
            else
            {
                eRet = HSM_STATUS_BUSY;
            }
        }
        else
        {
            eRet = HSM_STATUS_LOGIC_ERR;
        }
    }
    else
    {
        eRet = HSM_STATUS_PARAM_ERR;
    }
    return eRet;
}
HSM_StatusType HSM_L1_LoadFirmwarePoll(HSM_L1_RtCtxType *pCtx)
{
    HSM_StatusType eRet = HSM_STATUS_SUCCESS;
    HSM_BoolType   bInProcess;
    bInProcess = pCtx->bInProcess;
    if ((HSM_TRUE == bInProcess) && (HSM_OP_LOAD_FIRMWARE == pCtx->eOperationCata))
    {
        if (HSM_DRV_SM_ARITH == pCtx->eStat)
        {
            eRet = pCtx->pReadAckCb();
            if (HSM_STATUS_BUSY == eRet)
            {
                eRet = HSM_STATUS_AGAIN;
            }
            else if (HSM_STATUS_SUCCESS == eRet)
            {
                eRet = HSM_L1_LoadFirmware_Isr(pCtx);
            }
            else
            {
                pCtx->eStat = HSM_DRV_SM_STOP;
            }
        }
        else
        {
            eRet = HSM_STATUS_HW_IDLE;
        }
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }
    return eRet;
}
HSM_StatusType HSM_L1_LoadFirmwareReset(HSM_L1_RtCtxType *pCtx)
{
    HSM_BoolType   bInProcess;
    HSM_StatusType eRet = HSM_STATUS_SUCCESS;
    bInProcess          = pCtx->bInProcess;
    if ((HSM_TRUE == bInProcess) && (HSM_OP_LOAD_FIRMWARE == pCtx->eOperationCata))
    {
        if (HSM_DRV_SM_ARITH == pCtx->eStat)
        {
            eRet = pCtx->pCancelCmdCb();
        }
        if (HSM_STATUS_SUCCESS == eRet)
        {
            pCtx->eStat = HSM_DRV_SM_READY;
        }
        else
        {
            ;
        }
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }
    return eRet;
}
HSM_StatusType HSM_L1_LoadFirmwareExitEnv(HSM_L1_RtCtxType *pCtx)
{
    HSM_BoolType   bInProcess = pCtx->bInProcess;
    HSM_StatusType eRet       = HSM_STATUS_SUCCESS;
    if ((HSM_TRUE == bInProcess) && (HSM_OP_LOAD_FIRMWARE == pCtx->eOperationCata))
    {
        eRet = HSM_L1_CommonExitEnv(pCtx);
    }
    else
    {
        eRet = HSM_STATUS_LOGIC_ERR;
    }
    return eRet;
}
HSM_StatusType HSM_L1_LoadFirmware_Isr(HSM_L1_RtCtxType *pCtx)
{
    HSM_StatusType eRet;
    if (MAILBOXAPI_RET_SUCCESS == pCtx->tL1AlgCtx.tLoadFirmware.pParm->u32HSMStatusRet)
    {
        eRet        = HSM_STATUS_SUCCESS;
        pCtx->eStat = HSM_DRV_SM_STOP;
    }
    else
    {
        eRet        = HSM_STATUS_HW_ERR;
        pCtx->eStat = HSM_DRV_SM_STOP;
    }
    return eRet;
}

HSM_StatusType HSM_L1_GetPoll(HSM_L1_RtCtxType *pCtx)
{
    HSM_StatusType eRet       = HSM_STATUS_SUCCESS;
    HSM_BoolType   bInProcess = HSM_FALSE;

    bInProcess = pCtx->bInProcess;

    if (HSM_TRUE == bInProcess)
    {
        switch (pCtx->eOperationCata)
        {
            case HSM_OP_AES_ENCRYPT:
            {
                eRet = HSM_L1_AesEncryptPoll(pCtx);
            }
            break;

            case HSM_OP_AES_DECRYPT:
            {
                eRet = HSM_L1_AesDecryptPoll(pCtx);
            }
            break;

            case HSM_OP_SM4_ENCRYPT:
            {
                eRet = HSM_L1_Sm4EncryptPoll(pCtx);
            }
            break;

            case HSM_OP_SM4_DECRYPT:
            {
                eRet = HSM_L1_Sm4DecryptPoll(pCtx);
            }
            break;

            case HSM_OP_CMAC:
            {
                eRet = HSM_L1_CMacPoll(pCtx);
            }
            break;

            case HSM_OP_RNG:
            {
                eRet = HSM_L1_RngPoll(pCtx);
            }
            break;

            case HSM_OP_SHA:
            {
                eRet = HSM_L1_RngPoll(pCtx);
            }
            break;

            case HSM_OP_MD5:
            {
                eRet = HSM_L1_Md5Poll(pCtx);
            }
            break;

            case HSM_OP_SM3:
            {
                eRet = HSM_L1_Sm3Poll(pCtx);
            }
            break;

#if 0
            /*
             * IF use key id of RSA E/D/N, the key data in key space of HSM side,
             * only support 4B format,
             * and the N size must 8bytes aligned,
             * the D/E size should equal to N size.
             * So use HSM_L1_BnCalc instead.
             */

            case HSM_OP_RSA:
            {
                eRet = HSM_L1_RsaPoll(pCtx);
            }
            break;
#endif

            case HSM_OP_BN_CALC:
            {
                eRet = HSM_L1_BnCalcPoll(pCtx);
            }
            break;

            case HSM_OP_ECC_VERIFY:
            {
                eRet = HSM_L1_EccVerifyPoll(pCtx);
            }
            break;

            case HSM_OP_ECC_EASYDECRY:
            {
                eRet = HSM_L1_EccDecryptPoll(pCtx);
            }
            break;

            case HSM_OP_SCATTER_HASH:
            {
                eRet = HSM_L1_ScatterHashPoll(pCtx);
            }
            break;

            case HSM_OP_SCATTER_CMAC:
            {
                eRet = HSM_L1_ScatterCMacPoll(pCtx);
            }
            break;

            case HSM_OP_ECC_SIGN:
            {
                eRet = HSM_L1_EccSignPoll(pCtx);
            }
            break;

            case HSM_OP_ECC_CALC:
            {
                eRet = HSM_L1_EccCalculatePoll(pCtx);
            }
            break;

            case HSM_OP_KEY_MANAGE_IMPORT:
            {
                eRet = HSM_L1_KeyImportPoll(pCtx);
            }
            break;

#if ((FC7XXX_HSM_SUBSYSTEM_TYPE == FC7240_HSM_SUBSYSTEM) || \
     (FC7XXX_HSM_SUBSYSTEM_TYPE == FC7300_HSM_SUBSYSTEM))

            case HSM_OP_KEY_MANAGE_VALIDATE:
            {
                eRet = HSM_L1_KeyValidatePoll(pCtx);
            }
            break;
#endif

            case HSM_OP_KEY_MANAGE_COPY:
            {
                eRet = HSM_L1_KeyCopyPoll(pCtx);
            }
            break;

            case HSM_OP_KEY_MANAGE_REVOKE:
            {
                eRet = HSM_L1_KeyRevokePoll(pCtx);
            }
            break;

            case HSM_OP_KEY_MANAGE_TIDYUP:
            {
                eRet = HSM_L1_KeySpaceTidyUpPoll(pCtx);
            }
            break;

            case HSM_OP_RSA_SSA_PSS_VERIFY:
            {
                eRet = HSM_L1_RsaSsaPssVerifyPoll(pCtx);
            }
            break;

            case HSM_OP_RSA_SSA_PKCS1V15_VERIFY:
            {
                eRet = HSM_L1_RsaSsaPkcs1V15VerifyPoll(pCtx);
            }
            break;

            case HSM_OP_KEY_MANAGE_GETSTATUS:
            {
                eRet = HSM_L1_KeySpaceGetStatusPoll(pCtx);
            }
            break;

            case HSM_OP_RSA_SSA_PKCS1V15_SIGN:
            {
                eRet = HSM_L1_RsaSsaPkcs1V15SignPoll(pCtx);
            }
            break;

            case HSM_OP_RSA_SSA_PSS_SIGN:
            {
                eRet = HSM_L1_RsaSsaPssSignPoll(pCtx);
            }
            break;

#if ((FC7XXX_HSM_SUBSYSTEM_TYPE == FC7240_HSM_SUBSYSTEM) || \
     (FC7XXX_HSM_SUBSYSTEM_TYPE == FC7300_HSM_SUBSYSTEM))

            case HSM_OP_KEY_MANAGE_GET_ID_STATUS:
            {
                eRet = HSM_L1_GetKeyIdStatusPoll(pCtx);
            }
            break;

#endif

#if ((FC7XXX_HSM_SUBSYSTEM_TYPE == FC7240_HSM_SUBSYSTEM) || \
     (FC7XXX_HSM_SUBSYSTEM_TYPE == FC7300_HSM_SUBSYSTEM))
#else

            case HSM_OP_KEY_MANAGE_UPDATE_KEY_ID_CONTENT:
            {
                eRet = HSM_L1_UpdateKeyIdContentPoll(pCtx);
            }
            break;
#endif

            default:
            {
                eRet = HSM_STATUS_LOGIC_ERR;
            }
            break;
        }
    }
    else
    {
        eRet = HSM_STATUS_IDLE;
    }

    return eRet;
}

void HSM_L1_Ack_IrqHandler(void *pUpperCtx, HSM_StatusType eRet)
{
    HSM_Ln_RtCtxType *pLnCtx       = (HSM_Ln_RtCtxType *)pUpperCtx;
    HSM_L1_RtCtxType *pCtx         = &(pLnCtx->tHsmL1Ctx);
    HSM_BoolType      bInProcess   = pCtx->bInProcess;
    HSM_BoolType      bErrorHappen = HSM_FALSE;

    if (NULL_PTR != (pCtx->pCleanAndFlushDcache))
    {
        pCtx->pCleanAndFlushDcache();
    }
    /* else do nothing */

    if (HSM_TRUE == bInProcess)
    {
        switch (pCtx->eOperationCata)
        {
            case HSM_OP_SHA:
            {
                eRet = HSM_L1_Sha_Isr(pCtx);
                if (NULL_PTR != pCtx->pStopCb)
                {
                    if (HSM_STATUS_SUCCESS != eRet)
                    {
                        bErrorHappen = HSM_TRUE;
                    }
                    pCtx->pStopCb(pUpperCtx, bErrorHappen, eRet);
                }
                /* else do nothing */
            }
            break;

            case HSM_OP_MD5:
            {
                eRet = HSM_L1_Md5_Isr(pCtx);
                if (NULL_PTR != pCtx->pStopCb)
                {
                    if (HSM_STATUS_SUCCESS != eRet)
                    {
                        bErrorHappen = HSM_TRUE;
                    }

                    pCtx->pStopCb(pUpperCtx, bErrorHappen, eRet);
                }
                /* else do nothing */
            }
            break;

            case HSM_OP_SM3:
            {
                eRet = HSM_L1_Sm3_Isr(pCtx);
                if (NULL_PTR != pCtx->pStopCb)
                {
                    if (HSM_STATUS_SUCCESS != eRet)
                    {
                        bErrorHappen = HSM_TRUE;
                    }

                    pCtx->pStopCb(pUpperCtx, bErrorHappen, eRet);
                }
                /* else do nothing */
            }
            break;

#if 0
            /*
             * IF use key id of RSA E/D/N, the key data in key space of HSM side,
             * only support 4B format,
             * and the N size must 8bytes aligned,
             * the D/E size should equal to N size.
             * So use HSM_L1_BnCalc instead.
             */

            case HSM_OP_RSA:
            {
                eRet = HSM_L1_Rsa_Isr(pCtx);
                if (NULL_PTR != pCtx->pStopCb)
                {
                    if (HSM_STATUS_SUCCESS != eRet)
                    {
                        bErrorHappen = HSM_TRUE;
                    }

                    pCtx->pStopCb(pUpperCtx, bErrorHappen, eRet);
                }
                /* else do nothing */
            }
            break;
#endif

            case HSM_OP_BN_CALC:
            {
                eRet = HSM_L1_BnCalc_Isr(pCtx);
                if (NULL_PTR != pCtx->pStopCb)
                {
                    if (HSM_STATUS_SUCCESS != eRet)
                    {
                        bErrorHappen = HSM_TRUE;
                    }

                    pCtx->pStopCb(pUpperCtx, bErrorHappen, eRet);
                }
                /* else do nothing */
            }
            break;

            case HSM_OP_RNG:
            {
                eRet = HSM_L1_Rng_Isr(pCtx);
                if (HSM_STATUS_AGAIN != eRet)
                {
                    if (HSM_STATUS_SUCCESS != eRet)
                    {
                        bErrorHappen = HSM_TRUE;
                    }

                    if (NULL_PTR != pCtx->pStopCb)
                    {
                        pCtx->pStopCb(pUpperCtx, bErrorHappen, eRet);
                    }
                    /* else do nothing */
                }
                /* else do nothing */
            }
            break;

            case HSM_OP_ECC_VERIFY:
            {
                eRet = HSM_L1_EccVerify_Isr(pCtx);
                if (NULL_PTR != pCtx->pStopCb)
                {
                    if (HSM_STATUS_ERROR == eRet)
                    {
                        bErrorHappen = HSM_TRUE;
                    }

                    pCtx->pStopCb(pUpperCtx, bErrorHappen, eRet);
                }
                /* else do nothing */
            }
            break;

            case HSM_OP_ECC_EASYDECRY:
            {
                eRet = HSM_L1_EccDecrypt_Isr(pCtx);
                if (NULL_PTR != pCtx->pStopCb)
                {
                    if (HSM_STATUS_SUCCESS != eRet)
                    {
                        bErrorHappen = HSM_TRUE;
                    }

                    pCtx->pStopCb(pUpperCtx, bErrorHappen, eRet);
                }
                /* else do nothing */
            }
            break;

            case HSM_OP_CMAC:
            {
                eRet = HSM_L1_CMac_Isr(pCtx);
                if (NULL_PTR != pCtx->pStopCb)
                {
                    if (HSM_STATUS_SUCCESS != eRet)
                    {
                        bErrorHappen = HSM_TRUE;
                    }

                    pCtx->pStopCb(pUpperCtx, bErrorHappen, eRet);
                }
                /* else do nothing */
            }
            break;

            case HSM_OP_AES_ENCRYPT:
            {
                eRet = HSM_L1_AesEncrypt_Isr(pCtx);
                if (NULL_PTR != pCtx->pStopCb)
                {
                    if (HSM_STATUS_SUCCESS != eRet)
                    {
                        bErrorHappen = HSM_TRUE;
                    }

                    pCtx->pStopCb(pUpperCtx, bErrorHappen, eRet);
                }
                /* else do nothing */
            }
            break;

            case HSM_OP_AES_DECRYPT:
            {
                eRet = HSM_L1_AesDecrypt_Isr(pCtx);
                if (NULL_PTR != pCtx->pStopCb)
                {
                    if (HSM_STATUS_SUCCESS != eRet)
                    {
                        bErrorHappen = HSM_TRUE;
                    }

                    pCtx->pStopCb(pUpperCtx, bErrorHappen, eRet);
                }
                /* else do nothing */
            }
            break;

            case HSM_OP_SM4_ENCRYPT:
            {
                eRet = HSM_L1_Sm4Encrypt_Isr(pCtx);
                if (HSM_STATUS_AGAIN != eRet)
                {
                    if (NULL_PTR != pCtx->pStopCb)
                    {
                        if (HSM_STATUS_SUCCESS != eRet)
                        {
                            bErrorHappen = HSM_TRUE;
                        }

                        pCtx->pStopCb(pUpperCtx, bErrorHappen, eRet);
                    }
                    else
                    {
                        ;
                    }
                }
                /* else nothing, need more process revoke */
            }
            break;

            case HSM_OP_SM4_DECRYPT:
            {
                eRet = HSM_L1_Sm4Decrypt_Isr(pCtx);
                if (NULL_PTR != pCtx->pStopCb)
                {
                    if (HSM_STATUS_SUCCESS != eRet)
                    {
                        bErrorHappen = HSM_TRUE;
                    }

                    pCtx->pStopCb(pUpperCtx, bErrorHappen, eRet);
                }
                /* else do nothing */
            }
            break;

            case HSM_OP_SCATTER_HASH:
            {
                eRet = HSM_L1_ScatterHash_Isr(pCtx);
                if (HSM_STATUS_AGAIN != eRet)
                {
                    if (NULL_PTR != pCtx->pStopCb)
                    {
                        if (HSM_STATUS_SUCCESS != eRet)
                        {
                            bErrorHappen = HSM_TRUE;
                        }

                        pCtx->pStopCb(pUpperCtx, bErrorHappen, eRet);
                    }
                    /* else do nothing */
                }
            }
            break;

            case HSM_OP_SCATTER_CMAC:
            {
                eRet = HSM_L1_ScatterCMac_Isr(pCtx);
                if (HSM_STATUS_AGAIN != eRet)
                {
                    if (NULL_PTR != pCtx->pStopCb)
                    {
                        if (HSM_STATUS_SUCCESS != eRet)
                        {
                            bErrorHappen = HSM_TRUE;
                        }

                        pCtx->pStopCb(pUpperCtx, bErrorHappen, eRet);
                    }
                    /* else do nothing */
                }
            }
            break;

            case HSM_OP_ECC_SIGN:
            {
                eRet = HSM_L1_EccSign_Isr(pCtx);
                if (NULL_PTR != pCtx->pStopCb)
                {
                    if (HSM_STATUS_ERROR == eRet)
                    {
                        bErrorHappen = HSM_TRUE;
                    }

                    pCtx->pStopCb(pUpperCtx, bErrorHappen, eRet);
                }
                /* else do nothing */
            }
            break;

            case HSM_OP_RSA_SSA_PSS_VERIFY:
            {
                eRet = HSM_L1_RsaSsaPssVerify_Isr(pCtx);
                if (NULL_PTR != pCtx->pStopCb)
                {
                    if (HSM_STATUS_ERROR == eRet)
                    {
                        bErrorHappen = HSM_TRUE;
                    }

                    pCtx->pStopCb(pUpperCtx, bErrorHappen, eRet);
                }
                /* else do nothing */
            }
            break;

            case HSM_OP_RSA_SSA_PKCS1V15_VERIFY:
            {
                eRet = HSM_L1_RsaSsaPkcs1V15Verify_Isr(pCtx);
                if (NULL_PTR != pCtx->pStopCb)
                {
                    if (HSM_STATUS_ERROR == eRet)
                    {
                        bErrorHappen = HSM_TRUE;
                    }

                    pCtx->pStopCb(pUpperCtx, bErrorHappen, eRet);
                }
                /* else do nothing */
            }
            break;

            case HSM_OP_ECC_CALC:
            {
                eRet = HSM_L1_EccCalculate_Isr(pCtx);
                if (NULL_PTR != pCtx->pStopCb)
                {
                    if (HSM_STATUS_SUCCESS != eRet)
                    {
                        bErrorHappen = HSM_TRUE;
                    }

                    pCtx->pStopCb(pUpperCtx, bErrorHappen, eRet);
                }
                /* else do nothing */
            }
            break;

            case HSM_OP_KEY_MANAGE_IMPORT:
            {
                eRet = HSM_L1_KeyImport_Isr(pCtx);
                if (NULL_PTR != pCtx->pStopCb)
                {
                    if (HSM_STATUS_SUCCESS != eRet)
                    {
                        bErrorHappen = HSM_TRUE;
                    }

                    pCtx->pStopCb(pUpperCtx, bErrorHappen, eRet);
                }
                /* else do nothing */
            }
            break;

#if ((FC7XXX_HSM_SUBSYSTEM_TYPE == FC7240_HSM_SUBSYSTEM) || \
     (FC7XXX_HSM_SUBSYSTEM_TYPE == FC7300_HSM_SUBSYSTEM))
            case HSM_OP_KEY_MANAGE_VALIDATE:
            {
                eRet = HSM_L1_KeyValidate_Isr(pCtx);
                if (NULL_PTR != pCtx->pStopCb)
                {
                    if ((HSM_STATUS_EXIST != eRet) && (HSM_STATUS_NOT_EXIST != eRet))
                    {
                        bErrorHappen = HSM_TRUE;
                    }

                    pCtx->pStopCb(pUpperCtx, bErrorHappen, eRet);
                }
                /* else do nothing */
            }
            break;
#endif

            case HSM_OP_KEY_MANAGE_COPY:
            {
                eRet = HSM_L1_KeyCopy_Isr(pCtx);
                if (NULL_PTR != pCtx->pStopCb)
                {
                    if (HSM_STATUS_SUCCESS != eRet)
                    {
                        bErrorHappen = HSM_TRUE;
                    }

                    pCtx->pStopCb(pUpperCtx, bErrorHappen, eRet);
                }
                /* else do nothing */
            }
            break;

            case HSM_OP_KEY_MANAGE_REVOKE:
            {
                eRet = HSM_L1_KeyRevoke_Isr(pCtx);
                if (NULL_PTR != pCtx->pStopCb)
                {
                    if (HSM_STATUS_SUCCESS != eRet)
                    {
                        bErrorHappen = HSM_TRUE;
                    }

                    pCtx->pStopCb(pUpperCtx, bErrorHappen, eRet);
                }
                /* else do nothing */
            }
            break;

            case HSM_OP_KEY_MANAGE_TIDYUP:
            {
                eRet = HSM_L1_KeySpaceTidyup_Isr(pCtx);
                if (NULL_PTR != pCtx->pStopCb)
                {
                    if (HSM_STATUS_SUCCESS != eRet)
                    {
                        bErrorHappen = HSM_TRUE;
                    }

                    pCtx->pStopCb(pUpperCtx, bErrorHappen, eRet);
                }
                /* else do nothing */
            }
            break;

            case HSM_OP_KEY_MANAGE_GETSTATUS:
            {
                eRet = HSM_L1_KeySpaceGetStatus_Isr(pCtx);
                if (NULL_PTR != pCtx->pStopCb)
                {
                    if (HSM_STATUS_SUCCESS != eRet)
                    {
                        bErrorHappen = HSM_TRUE;
                    }

                    pCtx->pStopCb(pUpperCtx, bErrorHappen, eRet);
                }
                /* else do nothing */
            }
            break;

            case HSM_OP_RSA_SSA_PKCS1V15_SIGN:
            {
                eRet = HSM_L1_RsaSsaPkcs1V15Sign_Isr(pCtx);
                if (NULL_PTR != pCtx->pStopCb)
                {
                    if (HSM_STATUS_SUCCESS != eRet)
                    {
                        bErrorHappen = HSM_TRUE;
                    }

                    pCtx->pStopCb(pUpperCtx, bErrorHappen, eRet);
                }
                /* else do nothing */
            }
            break;

            case HSM_OP_RSA_SSA_PSS_SIGN:
            {
                eRet = HSM_L1_RsaSsaPssSign_Isr(pCtx);
                if (NULL_PTR != pCtx->pStopCb)
                {
                    if (HSM_STATUS_SUCCESS != eRet)
                    {
                        bErrorHappen = HSM_TRUE;
                    }

                    pCtx->pStopCb(pUpperCtx, bErrorHappen, eRet);
                }
                /* else do nothing */
            }
            break;

#if ((FC7XXX_HSM_SUBSYSTEM_TYPE == FC7240_HSM_SUBSYSTEM) || \
     (FC7XXX_HSM_SUBSYSTEM_TYPE == FC7300_HSM_SUBSYSTEM))

            case HSM_OP_KEY_MANAGE_GET_ID_STATUS:
            {
                eRet = HSM_L1_GetKeyIdStatus_Isr(pCtx);
                if (NULL_PTR != pCtx->pStopCb)
                {
                    if ((HSM_STATUS_ERROR == eRet) || (HSM_STATUS_HW_ERR == eRet))
                    {
                        bErrorHappen = HSM_TRUE;
                    }

                    pCtx->pStopCb(pUpperCtx, bErrorHappen, eRet);
                }
                /* else do nothing */
            }
            break;
#endif

            case HSM_OP_LOAD_FIRMWARE:
            {
                eRet = HSM_L1_LoadFirmware_Isr(pCtx);
                if (NULL_PTR != pCtx->pStopCb)
                {
                    if (HSM_STATUS_HW_ERR == eRet)
                    {
                        bErrorHappen = HSM_TRUE;
                    }
                    pCtx->pStopCb(pUpperCtx, bErrorHappen, eRet);
                }
            }
            break;
#if ((FC7XXX_HSM_SUBSYSTEM_TYPE == FC7240_HSM_SUBSYSTEM) || \
     (FC7XXX_HSM_SUBSYSTEM_TYPE == FC7300_HSM_SUBSYSTEM))
#else

            case HSM_OP_KEY_MANAGE_UPDATE_KEY_ID_CONTENT:
            {
                eRet = HSM_L1_UpdateKeyIdContent_Isr(pCtx);
                if (NULL_PTR != pCtx->pStopCb)
                {
                    if (HSM_STATUS_SUCCESS != eRet)
                    {
                        bErrorHappen = HSM_TRUE;
                    }

                    pCtx->pStopCb(pUpperCtx, bErrorHappen, eRet);
                }
                /* else do nothing */
            }
            break;
#endif

            case HSM_OP_SM2_VERIFY:
            {
                eRet = HSM_L1_Sm2Verify_Isr(pCtx);
                if (NULL_PTR != pCtx->pStopCb)
                {
                    if (HSM_STATUS_SUCCESS != eRet)
                    {
                        bErrorHappen = HSM_TRUE;
                    }

                    pCtx->pStopCb(pUpperCtx, bErrorHappen, eRet);
                }
                /* else do nothing */
            }
            break;

            case HSM_OP_SM2_GEN_ZA:
            {
                eRet = HSM_L1_Sm2GenZa_Isr(pCtx);
                if (NULL_PTR != pCtx->pStopCb)
                {
                    if (HSM_STATUS_SUCCESS != eRet)
                    {
                        bErrorHappen = HSM_TRUE;
                    }

                    pCtx->pStopCb(pUpperCtx, bErrorHappen, eRet);
                }
                /* else do nothing */
            }
            break;

            /* PRQA S 2016 ++ #Misra-C:Rule-16.4 Every switch statement shall have a default label
             * Reason: It doesn't go to the default branch */
            default:
                break;
                /* PRQA S 2016 -- */
        }
    }
    else
    {
        ;
    }
}
