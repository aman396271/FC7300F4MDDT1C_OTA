/**
 * @file module_driver_dma.c
 * @author flagchip
 * @brief DMA driver source code
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
   *   Version     Date          Author        CR#          Descriptions
   *   ---------   ----------    ------------  ----------   ---------------
   *   0.1.0       2022-12-10    Flagchip      N/A          First version for FC7300
   *   0.2.0       2023-02-13    Flagchip      N/A          Fix MISRA issues
   *   0.3.0       2024-08-05    Flagchip099   N/A          SDK 2.0 release version
   ******************************************************************************** */

#include "module_driver_dma.h"

#if DMA_INSTANCE_COUNT > 0U

#ifndef DMA_DEV_ERROR_REPORT
    #define DMA_DEV_ERROR_REPORT   STD_OFF
#endif

#if DMA_DEV_ERROR_REPORT == STD_ON
    #define DMA_ReportDevError(func, error) ReportDevError(DMA_MODULE_ID, func, error)
#endif

/**
 * @brief Get the first unused DUMO register index
 *
 * @param [out] pDumoIndex the DUMO register index
 * @return DMA_StatusType whether there is unused DUMO index
 * @return DMA_STATUS_SUCCESS the DUMO register index is successfully get
 * @return DMA_STATUS_NO_RESOURCE all DUMO registers are already occupied
 */
static inline DMA_StatusType DMA_GetDumoIndex(DMA_HandleType *pDmaHandle, uint8_t *pDumoIndex);

/**
 * @brief Check whether the value is power of 2 and return the ceil value of the log2(u32Value)
 *
 * @param [in] u32Value the value to check
 * @param [out] u8Log2 the ceil value of log2(u32Value)
 * @return true the u32Value is power of 2
 * @return false the u32Value is not power of 2
 */
static bool DMA_IsPowerOf2(uint32_t u32Value, uint8_t *u8Log2);

/**
 * @brief Reset the DMAMUX config values
 * @param Dmamux_Instance the selected DMA Instance
 *
 */
static inline void Dmamux_Reset(DMAMUX_Type *const Dmamux_Instance);

/**
 * @brief Get the data offset value of the selected increment mode and data size
 *
 * @param eIncMode the selected increment mode
 * @param eDataSize the selected data size
 * @return int16_t the calculated data offset
 */
static inline uint16_t DMA_GetDataOffset(DMA_IncrementModeType eIncMode,
                                         DMA_TransferSizeType eDataSize);

/**
 * @brief Get the IRQ number of the selected DMA channel
 *
 * @param u8Channel the selected DMA channel
 * @return IRQn_Type the IRQ number of the selected DMA channel
 */
#if ((DEVICE_NAME >= FC7300FxMDxxxxxT1B_DEVICE_START) && (DEVICE_NAME <= FC7300F4MDS2P176T1B))
static inline DMA_StatusType DMA_GetDumoIndex(DMA_HandleType *pDmaHandle, uint8_t *pDumoIndex)
{
    DMA_StatusType ret = DMA_STATUS_ERROR;
    uint8_t u8Dma_Instance = pDmaHandle->tSettings.pInstance->tSettings.u8Instance;
    DMA_Type *aDma[] = DMA_BASE_PTRS;
    DMA_Type *const pDma = aDma[u8Dma_Instance];
    uint8_t u8val;

    if (DMA_HWA_GetOuterLoopTrigEnableFlag(pDma, pDmaHandle->tSettings.u8Channel) == FALSE)
    {
      for (*pDumoIndex = 0U; *pDumoIndex < DMA_UMO_COUNT; (*pDumoIndex)++)
      {
          if (pDmaHandle->tSettings.pInstance->tStatus.u8DmaDumoUsedStatus[*pDumoIndex] == DMA_CHANNEL_INVALID)
          {
              ret = DMA_STATUS_SUCCESS;
              break;
          }
      }
      if (*pDumoIndex == DMA_UMO_COUNT)
      {
          ret = DMA_STATUS_NO_RESOURCE;
      }
    }
    else
    {
        /* Workaround for 12 bit conflict in CFG_CSRn */
        u8val = DMA_HWA_GetOuterLoopTrigChannel(pDma, pDmaHandle->tSettings.u8Channel) >> 4;
        for (*pDumoIndex = 0U; *pDumoIndex < DMA_UMO_COUNT; (*pDumoIndex)++)
        {
            if ((pDmaHandle->tSettings.pInstance->tStatus.u8DmaDumoUsedStatus[*pDumoIndex] == DMA_CHANNEL_INVALID) && ((*pDumoIndex & 1U) == u8val))
            {
              ret = DMA_STATUS_SUCCESS;
              break;
            }
        }
    }
    return ret;
}
#else
static inline DMA_StatusType DMA_GetDumoIndex(DMA_HandleType *pDmaHandle, uint8_t *pDumoIndex)
{
    DMA_StatusType ret = DMA_STATUS_ERROR;

    for (*pDumoIndex = 0U; *pDumoIndex < DMA_UMO_COUNT; (*pDumoIndex)++)
    {
        if (pDmaHandle->tSettings.pInstance->tStatus.u8DmaDumoUsedStatus[*pDumoIndex] == DMA_CHANNEL_INVALID)
        {
            ret = DMA_STATUS_SUCCESS;
            break;
        }
    }
    if (*pDumoIndex == DMA_UMO_COUNT)
    {
        ret = DMA_STATUS_NO_RESOURCE;
    }
    return ret;
}
#endif
static bool DMA_IsPowerOf2(uint32_t u32Value, uint8_t *u8Log2)
{
    bool ret = (bool)false;

    *u8Log2 = 0U;
    while (u32Value > (1UL << *u8Log2))
    {
        (*u8Log2)++;
    }
    if ((u32Value & ((1UL << *u8Log2) - 1U)) == 0U)
    {
        ret = (bool)true;
    }
    return ret;
}

static inline uint16_t DMA_GetDataOffset(DMA_IncrementModeType eIncMode,
                                         DMA_TransferSizeType eDataSize)
{
    uint16_t u16DataOffset = 0U;

    switch (eIncMode)
    {
        case DMA_INCREMENT_DISABLE:
        {
            u16DataOffset = 0U;
            break;
        }

        case DMA_INCREMENT_DATA_SIZE:
        {
            u16DataOffset = (uint16_t)(1UL << ((uint8_t)eDataSize));
            break;
        }

        case DMA_INCREMENT_DATA_SIZE_4BYTE_ALIGNED:
        {
            switch (eDataSize)
            {
                case DMA_TRANSFER_SIZE_1B:
                case DMA_TRANSFER_SIZE_2B:
                case DMA_TRANSFER_SIZE_4B:
                    u16DataOffset = 4U;
                    break;

                case DMA_TRANSFER_SIZE_8B:
                    u16DataOffset = 8U;
                    break;

                case DMA_TRANSFER_SIZE_32B:
                    u16DataOffset = 32U;
                    break;

                default:
                    break;
            }
            break;
        }

        default:
            break;
    }
    return u16DataOffset;
}

void DMA_Transfer_Complete_IRQHandler(DMA_HandleType *pDmaHandle)
{
    uint8_t u8Dma_Instance = pDmaHandle->tSettings.pInstance->tSettings.u8Instance;
    DMA_Type *aDma[] = DMA_BASE_PTRS;
    DMA_Type *const pDma = aDma[u8Dma_Instance];

    DMA_HWA_ClearChannelInterruptFlag(pDma, pDmaHandle->tSettings.u8Channel);
    if (pDmaHandle->tSettings.callback.pTransferCompleteCallback != NULL)
    {
        pDmaHandle->tSettings.callback.pTransferCompleteCallback(pDmaHandle->tSettings.callback.completedata);
    }
}

void DMA_ProcessErrorInterrupt(DMA_InstanceHandleType *pDmaInstanceHandle)
{
    uint8_t u8Dma_Instance = pDmaInstanceHandle->tSettings.u8Instance;
    DMA_Type *aDma[] = DMA_BASE_PTRS;
    DMA_Type *const pDma = aDma[u8Dma_Instance];
    uint8_t u8Channel;

    for (u8Channel = 0U; u8Channel < DMA_CFG_COUNT; u8Channel++)
    {
        if (DMA_HWA_GetChannelErrorFlag(pDma, u8Channel) == true)
        {
            DMA_HWA_ClearChannelErrorFlag(pDma, u8Channel);
            if (pDmaInstanceHandle->tSettings.pTransferErrorCallback[u8Channel] != NULL)
            {
                pDmaInstanceHandle->tSettings.pTransferErrorCallback[u8Channel](pDmaInstanceHandle->tSettings.errdata[u8Channel]);
            }
        }
    }
}

static inline void Dmamux_Reset(DMAMUX_Type *const Dmamux_Instance)
{
    uint8_t u8Index;
    for (u8Index = 0U; u8Index < DMAMUX_CHCFG_COUNT; u8Index++)
    {
        DMAMUX_HWA_SetRequestSource(Dmamux_Instance, u8Index, false, DMA_REQ_DISABLED);
    }
    /* Reset channel0~3 period trigger */
    for (u8Index = 0U; u8Index < DMA_PERIOD_CHANNEL_COUNT; u8Index++)
    {
        DMAMUX_HWA_SetPeriodicTrigFlag(Dmamux_Instance, u8Index, false);
    }
}

#ifdef DMA_HAVE_BACKDOOR
static uint32_t Dma_SrcTranstoBackdoorAddress(uint32_t u32InputSrc)
{
    uint32_t u32SrcAddr = u32InputSrc;

    if ((uint8_t)0U == Dma_GetCoreId())
    {
        if ((u32InputSrc >= DTCM_ADDRESS_START) && (u32InputSrc <= DTCM_ADDRESS_STOP))
        {
            u32SrcAddr = u32InputSrc + DTCM0_BACKDOOR;
        }
        else if (u32InputSrc <= ITCM_ADDRESS_STOP)
        {
            u32SrcAddr = u32InputSrc + ITCM0_BACKDOOR;
        }
        else
        {
            /* SRAM or Reg */
        }
    }
    else if ((uint8_t)1U == Dma_GetCoreId())
    {
        if ((u32InputSrc >= DTCM_ADDRESS_START) && (u32InputSrc <= DTCM_ADDRESS_STOP))
        {
            u32SrcAddr = u32InputSrc + DTCM1_BACKDOOR;
        }
        else if (u32InputSrc <= ITCM_ADDRESS_STOP)
        {
            u32SrcAddr = u32InputSrc + ITCM1_BACKDOOR;
        }
        else
        {
            /* SRAM or Reg */
        }
    }
    else if ((uint8_t)2U == Dma_GetCoreId())
    {
        if ((u32InputSrc >= DTCM_ADDRESS_START) && (u32InputSrc <= DTCM_ADDRESS_STOP))
        {
            u32SrcAddr = u32InputSrc + DTCM2_BACKDOOR;
        }
        else if (u32InputSrc <= ITCM_ADDRESS_STOP)
        {
            u32SrcAddr = u32InputSrc + ITCM2_BACKDOOR;
        }
        else
        {
            /* SRAM or Reg */
        }
    }
    else
    {
        /* It will never go here */
    }
    return u32SrcAddr;
}

static uint32_t Dma_DesTranstoBackdoorAddress(uint32_t u32InputDes)
{
    uint32_t u32DesAddr = u32InputDes;

    if ((uint8_t)0U == Dma_GetCoreId())
    {
        if ((u32InputDes >= DTCM_ADDRESS_START) && (u32InputDes <= DTCM_ADDRESS_STOP))
        {
            /* DTCM0 */
            u32DesAddr = u32InputDes + DTCM0_BACKDOOR;
        }
        else if (u32InputDes <= ITCM_ADDRESS_STOP)
        {
            /* ITCM0 */
            u32DesAddr = u32InputDes + ITCM0_BACKDOOR;
        }
        else
        {
            /* SRAM or Reg */
        }
    }
    else if ((uint8_t)1U == Dma_GetCoreId())
    {
        if ((u32InputDes >= DTCM_ADDRESS_START) && (u32InputDes <= DTCM_ADDRESS_STOP))
        {
            /* DTCM1 */
            u32DesAddr = u32InputDes + DTCM1_BACKDOOR;
        }
        else if (u32InputDes <= ITCM_ADDRESS_STOP)
        {
            /* ITCM1 */
            u32DesAddr = u32InputDes + ITCM1_BACKDOOR;
        }
        else
        {
            /* SRAM or Reg */
        }
    }
    else if ((uint8_t)2U == Dma_GetCoreId())
    {
        if ((u32InputDes >= DTCM_ADDRESS_START) && (u32InputDes <= DTCM_ADDRESS_STOP))
        {
            /* DTCM2 */
            u32DesAddr = u32InputDes + DTCM2_BACKDOOR;
        }
        else if (u32InputDes <= ITCM_ADDRESS_STOP)
        {
            /* ITCM2 */
            u32DesAddr = u32InputDes + ITCM2_BACKDOOR;
        }
        else
        {
            /* SRAM or Reg */
        }
    }
    else
    {
        /* It will never go here */
    }
    return u32DesAddr;
}
#endif

void DMA_Init(DMA_InstanceHandleType *pDmaInstanceHandle, const DMA_InitType *const pInitCfg)
{
    uint8_t u8Dma_Instance = pDmaInstanceHandle->tSettings.u8Instance;
    DMA_Type *aDma[] = DMA_BASE_PTRS;
    DMA_Type *const pDma = aDma[u8Dma_Instance];

    #if DMA_DEV_ERROR_REPORT == STD_ON
    if ((uint32_t)u8Dma_Instance >= DMA_INSTANCE_MAX)
    {
        DMA_ReportDevError(DMA_INIT_ID, DMA_E_PARAM_INSTANCE);
    }
    else if (pInitCfg == NULL)
    {
        DMA_ReportDevError(DMA_INIT_ID, DMA_E_PARAM_INITCFG);
    }
    else
    {
    #endif

        pDmaInstanceHandle->tStatus.u8DmaDumoUsedStatus[0] = 0xFF;
        pDmaInstanceHandle->tStatus.u8DmaDumoUsedStatus[1] = 0xFF;
        pDmaInstanceHandle->tStatus.u8DmaDumoUsedStatus[2] = 0xFF;
        pDmaInstanceHandle->tStatus.u8DmaDumoUsedStatus[3] = 0xFF;

        DMA_DeInit(pDmaInstanceHandle);
        DMA_HWA_SetHaltOnErrorFlag(pDma, pInitCfg->bHaltOnError);
        DMA_HWA_SetArbitrationAlgorithm(pDma, pInitCfg->eArbitrationAlgorithm);
        DMA_HWA_SetInnerLoopMappingEnableFlag(pDma, true);
        #ifdef DMA_HAVE_GPR
        if (true == pInitCfg->bGRP0HighPriority)
        {
            DMA_HWA_SetGPR1PRIClearGPR0PRI(pDma);
        }
        else
        {
            DMA_HWA_SetGPR0PRIClearGPR1PRI(pDma);
        }
        #endif
        #if DMA_DEV_ERROR_REPORT == STD_ON
    }
        #endif
}

void DMA_DeInit(DMA_InstanceHandleType *pDmaInstanceHandle)
{
    uint8_t u8Dma_Instance = pDmaInstanceHandle->tSettings.u8Instance;
    uint8_t u8Index;
    DMA_Type *aDma[] = DMA_BASE_PTRS;
    DMA_Type *const pDma = aDma[u8Dma_Instance];
    DMAMUX_Type *aDmamux[] = DMAMUX_BASE_PTRS;
    DMAMUX_Type *const pDmamux = aDmamux[u8Dma_Instance];

    #if DMA_DEV_ERROR_REPORT == STD_ON
    if ((uint32_t)u8Dma_Instance >= DMA_INSTANCE_MAX)
    {
        DMA_ReportDevError(DMA_INIT_ID, DMA_E_PARAM_INSTANCE);
    }
    else
    {
    #endif

        DMA_HWA_SetControlRegister(pDma, 0U);
        DMA_HWA_DisableAllChannelErrorInterrupt(pDma);
        DMA_HWA_DisableAllChannelRequest(pDma);
        DMA_HWA_ClearAllChannelDoneStatus(pDma);
        DMA_HWA_ClearAllChannelErrorFlag(pDma);
        DMA_HWA_ClearAllChannelInterruptFlag(pDma);

        pDma->UME[0] = 0U;
        #if (DMA_UME_COUNT == 2)
        pDma->UME[1] = 0U;
        #endif
        for (u8Index = 0U; u8Index < DMA_UMO_COUNT; u8Index++)
        {
            DMA_HWA_SetUnalignModulo(pDma, u8Index, 0U, 0U);
        }
        for (u8Index = 0U; u8Index < DMA_CFG_COUNT; u8Index++)
        {
            DMA_HWA_SetPriority(pDma, u8Index, u8Index);
            pDma->CFG[u8Index].SADDR = 0UL;
            pDma->CFG[u8Index].SOFF = 0U;
            pDma->CFG[u8Index].SLAST = 0UL;
            pDma->CFG[u8Index].DADDR = 0UL;
            pDma->CFG[u8Index].DOFF = 0U;
            pDma->CFG[u8Index].DLAST = 0U;
            pDma->CFG[u8Index].ATTR = 0U;
            pDma->CFG[u8Index].NBYTES.ILNO = 0UL;
            pDma->CFG[u8Index].NBYTES.ILOFFNO = 0UL;
            pDma->CFG[u8Index].NBYTES.ILOFFYES = 0UL;
            pDma->CFG[u8Index].CSR = 0U;
            pDma->CFG[u8Index].BLC.CHTRGENNO = 0U;
            pDma->CFG[u8Index].CLC.CHTRGENNO = 0U;
            pDma->CFG[u8Index].BLC.CHTRGENYES = 0U;
            pDma->CFG[u8Index].CLC.CHTRGENYES = 0U;
        }

        Dmamux_Reset(pDmamux);
        #if DMA_DEV_ERROR_REPORT == STD_ON
    }
        #endif
}

DMA_StatusType DMA_InitChannel(DMA_HandleType *pDmaHandle, const DMA_ChannelCfgType *const pChnCfg)
{
    uint8_t u8Dma_Instance = pDmaHandle->tSettings.pInstance->tSettings.u8Instance;
    uint8_t u8Channel = pDmaHandle->tSettings.u8Channel;
    DMA_Type *aDma[] = DMA_BASE_PTRS;
    DMA_Type *const pDma = aDma[u8Dma_Instance];
    DMAMUX_Type *aDmamux[] = DMAMUX_BASE_PTRS;
    DMAMUX_Type *const pDmamux = aDmamux[u8Dma_Instance];
    DMA_StatusType ret;
    uint16_t u16SrcDataOffset = DMA_GetDataOffset(pChnCfg->eSrcIncMode, pChnCfg->eSrcDataSize);
    uint16_t u16DestDataOffset = DMA_GetDataOffset(pChnCfg->eDestIncMode, pChnCfg->eDestDataSize);
    int32_t s32SrcLastOffset;
    int32_t s32DestLastOffset;
    uint8_t u8SrcMod = 0U;
    uint8_t u8DestMod = 0U;
    bool bUseSrcDumo = (bool)false;
    bool bUseDestDumo = (bool)false;
    uint8_t u8DumoIndex = 0U;
    uint16_t u16Sumo = 0U;
    uint16_t u16Dumo = 0U;
    #ifdef DMA_HAVE_BACKDOOR
    uint32_t u32SrcAddr;
    uint32_t u32DesAddr;
    #endif

    #if DMA_DEV_ERROR_REPORT == STD_ON
    if ((uint32_t)u8Dma_Instance >= DMA_INSTANCE_MAX)
    {
        DMA_ReportDevError(DMA_INIT_ID, DMA_E_PARAM_INSTANCE);
    }
    else if ((uint32_t)u8Channel >= DMA_CHANNEL_MAX)
    {
        DMA_ReportDevError(DMA_INIT_CHANNEL_ID, DMA_E_PARAM_CHANNEL);
    }
    else if (pChnCfg == NULL)
    {
        DMA_ReportDevError(DMA_INIT_CHANNEL_ID, DMA_E_PARAM_CHCFG);
    }
    else if (pChnCfg->u16BlockCount == 0U)
    {
        DMA_ReportDevError(DMA_INIT_CHANNEL_ID, DMA_E_PARAM_BLOCKCNT);
    }
    else if (pChnCfg->u32BlockSize == 0U)
    {
        DMA_ReportDevError(DMA_INIT_CHANNEL_ID, DMA_E_PARAM_BLOCKSIZE);
    }
    else if (((pChnCfg->u32BlockSize >> pChnCfg->eSrcDataSize) << pChnCfg->eSrcDataSize != pChnCfg->u32BlockSize) ||
             ((pChnCfg->u32BlockSize >> pChnCfg->eDestDataSize) << pChnCfg->eDestDataSize != pChnCfg->u32BlockSize))
    {
        DMA_ReportDevError(DMA_INIT_CHANNEL_ID, DMA_E_PARAM_BLOCKSIZE_DATASIZE);
    }
    else
    {
    #endif
        if ((pChnCfg->bSrcCircularBufferEn == true) || (pChnCfg->bDestCircularBufferEn == true))
        {
            /* If the circular buffer size is not power of 2 aligned, need to use the DUMO */
            if (pChnCfg->bSrcCircularBufferEn == true)
            {
                #if DMA_DEV_ERROR_REPORT == STD_ON
                if (pChnCfg->u32SrcCircBufferSize == 0U)
                {
                    DMA_ReportDevError(DMA_INIT_CHANNEL_ID, DMA_E_PARAM_SRCCIRCULARBUFSIZE);
                }
                else
                {
                #endif
                    bUseSrcDumo = (bool)(DMA_IsPowerOf2(pChnCfg->u32SrcCircBufferSize, &u8SrcMod) ? false : true);
                    #if DMA_DEV_ERROR_REPORT == STD_ON
                }
                    #endif
            }
            if (pChnCfg->bDestCircularBufferEn == true)
            {
                #if DMA_DEV_ERROR_REPORT == STD_ON
                if (pChnCfg->u32DestCircBufferSize == 0U)
                {
                    DMA_ReportDevError(DMA_INIT_CHANNEL_ID, DMA_E_PARAM_DESTCIRCULARBUFSIZE);
                }
                else
                {
                #endif
                    bUseDestDumo = (bool)(DMA_IsPowerOf2(pChnCfg->u32DestCircBufferSize, &u8DestMod) ? false : true);
                    #if DMA_DEV_ERROR_REPORT == STD_ON
                }
                    #endif
            }

            /* If circular buffer is enabled, the buffer address must be power of 2 aligned */
            if (((pChnCfg->bSrcCircularBufferEn == true) &&
                 (((uint32_t)pChnCfg->pSrcBuffer & ((1UL << u8SrcMod) - 1U)) != 0U)) ||
                ((pChnCfg->bDestCircularBufferEn == true) &&
                 (((uint32_t)pChnCfg->pDestBuffer & ((1UL << u8DestMod) - 1U)) != 0U)))
            {
                ret = DMA_STATUS_INVALID_ADDRESS;
            }
            /* If circular buffer is enabled, the buffer size must not less than the data offset */
            else if (((pChnCfg->bSrcCircularBufferEn == true) &&
                      (pChnCfg->u32SrcCircBufferSize < u16SrcDataOffset)) ||
                     ((pChnCfg->bDestCircularBufferEn == true) &&
                      (pChnCfg->u32DestCircBufferSize < u16SrcDataOffset)))
            {
                ret = DMA_STATUS_UNSUPPORTED;
            }
            /* If source or destination unalign modulo is used, check whether all DUMO registers are occupied */
            else if ((bUseSrcDumo == true) || (bUseDestDumo == true))
            {
                ret = DMA_GetDumoIndex(pDmaHandle, &u8DumoIndex);
                if (ret == DMA_STATUS_SUCCESS)
                {
                    pDmaHandle->tSettings.pInstance->tStatus.u8DmaDumoUsedStatus[u8DumoIndex] = (uint8_t)u8Channel;
                }
            }
            else
            {
                ret = DMA_STATUS_SUCCESS;
            }
        }
        else
        {
            ret = DMA_STATUS_SUCCESS;
        }

        if (ret == DMA_STATUS_SUCCESS)
        {
            if (pChnCfg->bSrcAddrLoopbackEn == true)
            {
                if (pChnCfg->bSrcBlockOffsetEn == false)
                {
                    s32SrcLastOffset = -((int32_t)((pChnCfg->u32BlockSize >> pChnCfg->eSrcDataSize) * u16SrcDataOffset) *
                                         (int32_t)(pChnCfg->u16BlockCount));
                }
                else
                {
                    s32SrcLastOffset = -(((int32_t)((pChnCfg->u32BlockSize >> pChnCfg->eSrcDataSize) * u16SrcDataOffset)) *
                                         (int32_t)(pChnCfg->u16BlockCount)) - ((pChnCfg->s32BlockOffset) * (int32_t)(pChnCfg->u16BlockCount - 1U));
                }
            }
            else
            {
                s32SrcLastOffset = 0;
            }
            if (pChnCfg->bDestAddrLoopbackEn == true)
            {
                if (pChnCfg->bDestBlockOffsetEn == false)
                {
                    s32DestLastOffset = -((int32_t)((pChnCfg->u32BlockSize >> pChnCfg->eDestDataSize) * u16DestDataOffset) *
                                          (pChnCfg->u16BlockCount));
                }
                else
                {
                    s32DestLastOffset = -(((int32_t)((pChnCfg->u32BlockSize >> pChnCfg->eDestDataSize) * u16DestDataOffset)) *
                                          (int32_t)(pChnCfg->u16BlockCount)) - ((pChnCfg->s32BlockOffset) * (int32_t)(pChnCfg->u16BlockCount - 1U));
                }
            }
            else
            {
                s32DestLastOffset = 0;
            }
            #ifdef DMA_HAVE_BACKDOOR
            /* Translation the input src address and des address to backdoor address if necessary*/
            u32SrcAddr = Dma_SrcTranstoBackdoorAddress((uint32_t)pChnCfg->pSrcBuffer);
            u32DesAddr = Dma_DesTranstoBackdoorAddress((uint32_t)pChnCfg->pDestBuffer);
            DMA_HWA_SetSrcAddr(pDma, (uint8_t)u8Channel, (uint32_t)u32SrcAddr);
            DMA_HWA_SetDestAddr(pDma, (uint8_t)u8Channel, (uint32_t)u32DesAddr);
            #else
            DMA_HWA_SetSrcAddr(pDma, (uint8_t)u8Channel, (uint32_t)pChnCfg->pSrcBuffer);
            DMA_HWA_SetDestAddr(pDma, (uint8_t)u8Channel, (uint32_t)pChnCfg->pDestBuffer);
            #endif
            DMA_HWA_SetPriority(pDma, (uint8_t)u8Channel, pChnCfg->u8ChannelPriority);

            if ((pChnCfg->bSrcCircularBufferEn == true) && (pChnCfg->bDestCircularBufferEn == true))
            {
                DMA_HWA_SetSrcDataSize(pDma, (uint8_t)u8Channel, pChnCfg->eSrcDataSize);
                DMA_HWA_SetSrcModulo(pDma, (uint8_t)u8Channel, u8SrcMod);
                DMA_HWA_SetDestDataSize(pDma, (uint8_t)u8Channel, pChnCfg->eDestDataSize);
                DMA_HWA_SetDestModulo(pDma, (uint8_t)u8Channel, u8DestMod);
            }
            else if (pChnCfg->bSrcCircularBufferEn == true)
            {
                DMA_HWA_SetSrcDataSize(pDma, (uint8_t)u8Channel, pChnCfg->eSrcDataSize);
                DMA_HWA_SetSrcModulo(pDma, (uint8_t)u8Channel, u8SrcMod);
                DMA_HWA_SetDestDataSize(pDma, (uint8_t)u8Channel, pChnCfg->eDestDataSize);
                DMA_HWA_SetDestModulo(pDma, (uint8_t)u8Channel, 0U);
            }
            else if (pChnCfg->bDestCircularBufferEn == true)
            {
                DMA_HWA_SetSrcDataSize(pDma, (uint8_t)u8Channel, pChnCfg->eSrcDataSize);
                DMA_HWA_SetSrcModulo(pDma, (uint8_t)u8Channel, 0U);
                DMA_HWA_SetDestDataSize(pDma, (uint8_t)u8Channel, pChnCfg->eDestDataSize);
                DMA_HWA_SetDestModulo(pDma, (uint8_t)u8Channel, u8DestMod);
            }
            else
            {
                DMA_HWA_SetSrcDataSize(pDma, (uint8_t)u8Channel, pChnCfg->eSrcDataSize);
                DMA_HWA_SetSrcModulo(pDma, (uint8_t)u8Channel, 0U);
                DMA_HWA_SetDestDataSize(pDma, (uint8_t)u8Channel, pChnCfg->eDestDataSize);
                DMA_HWA_SetDestModulo(pDma, (uint8_t)u8Channel, 0U);
            }

            if (bUseSrcDumo == true)
            {
                u16Sumo = (uint16_t)((pChnCfg->u32SrcCircBufferSize / u16SrcDataOffset - 1U) * u16SrcDataOffset);
            }
            if (bUseDestDumo == true)
            {
                u16Dumo = (uint16_t)((pChnCfg->u32DestCircBufferSize / u16DestDataOffset - 1U) * u16DestDataOffset);
            }
            if ((bUseSrcDumo == true) || (bUseDestDumo == true))
            {
                DMA_HWA_SetUnalignModulo(pDma, u8DumoIndex, u16Sumo, u16Dumo);
                DMA_HWA_SetUnalignModuloEnableFlag(pDma, (uint8_t)u8Channel, bUseSrcDumo, bUseDestDumo);
                DMA_HWA_SetUnalignModuloSel(pDma, (uint8_t)u8Channel, u8DumoIndex);
            }
            DMA_HWA_SetAutoDisableReuqestEnableFlag(pDma, (uint8_t)u8Channel, pChnCfg->bAutoStop);

            DMA_HWA_SetSrcOffset(pDma, (uint8_t)u8Channel, (int16_t)u16SrcDataOffset);
            DMA_HWA_SetDestOffset(pDma, (uint8_t)u8Channel, (int16_t)u16DestDataOffset);

            DMA_HWA_SetInnerLoopOffset(pDma, (uint8_t)u8Channel, pChnCfg->bSrcBlockOffsetEn, pChnCfg->bDestBlockOffsetEn,
                                       pChnCfg->s32BlockOffset);
            DMA_HWA_SetInnerLoopSize(pDma, (uint8_t)u8Channel, pChnCfg->u32BlockSize);

            if ((pChnCfg->u16BlockCount > 1U) && (true == pChnCfg->bInnerChannelChain))
            {
                DMA_HWA_SetChannelToChannelTrig(pDma, (uint8_t)u8Channel, true, (uint8_t)u8Channel);
                DMA_HWA_SetLoopCount(pDma, (uint8_t)u8Channel, pChnCfg->u16BlockCount);
            }
            else
            {
                DMA_HWA_SetChannelToChannelTrig(pDma, (uint8_t)u8Channel, false, 0U);
                DMA_HWA_SetLoopCount(pDma, (uint8_t)u8Channel, pChnCfg->u16BlockCount);
            }

            DMA_HWA_SetSrcLastAddrAdjustment(pDma, (uint8_t)u8Channel, s32SrcLastOffset);
            DMA_HWA_SetDestLastAddrAdjustment(pDma, (uint8_t)u8Channel, s32DestLastOffset);

            if (pChnCfg->eTriggerSrc == DMA_REQ_DISABLED)
            {
                DMAMUX_HWA_SetRequestSource(pDmamux, (uint8_t)u8Channel, false, DMA_REQ_DISABLED);
            }
            else
            {
                DMAMUX_HWA_SetRequestSource(pDmamux, (uint8_t)u8Channel, true, pChnCfg->eTriggerSrc);
            }
            DMA_InitChannelInterrupt(pDmaHandle, pChnCfg);
        }
        return ret;
        #if DMA_DEV_ERROR_REPORT == STD_ON
    }
        #endif
}

void DMA_DeinitChannel(DMA_HandleType *pDmaHandle)
{
    uint8_t u8Dma_Instance = pDmaHandle->tSettings.pInstance->tSettings.u8Instance;
    uint8_t u8Channel = pDmaHandle->tSettings.u8Channel;
    DMA_Type *aDma[] = DMA_BASE_PTRS;
    DMA_Type *const pDma = aDma[u8Dma_Instance];
    uint8_t u8DumoIndex;

    #if DMA_DEV_ERROR_REPORT == STD_ON
    if ((uint32_t)u8Dma_Instance >= DMA_INSTANCE_MAX)
    {
        DMA_ReportDevError(DMA_DEINIT_CHANNEL_ID, DMA_E_PARAM_INSTANCE);
    }
    else if ((uint32_t)u8Channel >= DMA_CHANNEL_MAX)
    {
        DMA_ReportDevError(DMA_DEINIT_CHANNEL_ID, DMA_E_PARAM_CHANNEL);
    }
    else
    {
    #endif
        for (u8DumoIndex = 0U; u8DumoIndex < DMA_UMO_COUNT; u8DumoIndex++)
        {
            if (pDmaHandle->tSettings.pInstance->tStatus.u8DmaDumoUsedStatus[u8DumoIndex] == (uint8_t)u8Channel)
            {
                pDmaHandle->tSettings.pInstance->tStatus.u8DmaDumoUsedStatus[u8DumoIndex] = DMA_CHANNEL_INVALID;
                DMA_HWA_SetUnalignModulo(pDma, u8DumoIndex, 0U, 0U);
            }
        }
        DMA_HWA_SetUnalignModuloEnableFlag(pDma, (uint8_t)u8Channel, false, false);
        DMA_HWA_DisableChannelErrorInterrupt(pDma, (uint8_t)u8Channel);
        DMA_HWA_DisableChannelRequest(pDma, (uint8_t)u8Channel);
        DMA_HWA_ClearChannelDoneStatus(pDma, (uint8_t)u8Channel);
        DMA_HWA_ClearChannelErrorFlag(pDma, (uint8_t)u8Channel);
        DMA_HWA_ClearChannelInterruptFlag(pDma, (uint8_t)u8Channel);

        pDma->CFG[u8Channel].SADDR = 0UL;
        pDma->CFG[u8Channel].SOFF = 0U;
        pDma->CFG[u8Channel].SLAST = 0UL;
        pDma->CFG[u8Channel].DADDR = 0UL;
        pDma->CFG[u8Channel].DOFF = 0U;
        pDma->CFG[u8Channel].DLAST = 0U;
        pDma->CFG[u8Channel].ATTR = 0U;
        pDma->CFG[u8Channel].NBYTES.ILNO = 0UL;
        pDma->CFG[u8Channel].NBYTES.ILOFFNO = 0UL;
        pDma->CFG[u8Channel].NBYTES.ILOFFYES = 0UL;
        pDma->CFG[u8Channel].CSR = 0U;
        pDma->CFG[u8Channel].BLC.CHTRGENNO = 0U;
        pDma->CFG[u8Channel].CLC.CHTRGENNO = 0U;
        pDma->CFG[u8Channel].BLC.CHTRGENYES = 0U;
        pDma->CFG[u8Channel].CLC.CHTRGENYES = 0U;
        #if DMA_DEV_ERROR_REPORT == STD_ON
    }
        #endif
}

void DMA_InitChannelInterrupt(DMA_HandleType *pDmaHandle, const DMA_ChannelCfgType *const pChnCfg)
{
    uint8_t u8Dma_Instance = pDmaHandle->tSettings.pInstance->tSettings.u8Instance;
    uint8_t u8Channel = pDmaHandle->tSettings.u8Channel;
    DMA_Type *aDma[] = DMA_BASE_PTRS;
    DMA_Type *const pDma = aDma[u8Dma_Instance];

    #if DMA_DEV_ERROR_REPORT == STD_ON
    if ((uint32_t)u8Dma_Instance >= DMA_INSTANCE_MAX)
    {
        DMA_ReportDevError(DMA_INIT_CHANNEL_INT_ID, DMA_E_PARAM_INSTANCE);
    }
    else if ((uint32_t)u8Channel >= DMA_CHANNEL_MAX)
    {
        DMA_ReportDevError(DMA_INIT_CHANNEL_INT_ID, DMA_E_PARAM_CHANNEL);
    }
    else if (pChnCfg == NULL)
    {
        DMA_ReportDevError(DMA_INIT_CHANNEL_INT_ID, DMA_E_PARAM_INTERRUPTCFG);
    }
    else
    {
    #endif
        if (pChnCfg->bTransferCompleteIntEn)
        {
            pDmaHandle->tSettings.callback.pTransferCompleteCallback = pChnCfg->pTransferCompleteNotify;
            pDmaHandle->tSettings.callback.completedata = pChnCfg->completedata;
            DMA_HWA_EnableTransferCompleteInterrupt(pDma, (uint8_t)u8Channel);
        }
        else
        {
            DMA_HWA_DisableTransferCompleteInterrupt(pDma, (uint8_t)u8Channel);
            pDmaHandle->tSettings.callback.pTransferCompleteCallback = NULL;
        }

        if (pChnCfg->bTransferErrorIntEn)
        {
            pDmaHandle->tSettings.pInstance->tSettings.pTransferErrorCallback[pDmaHandle->tSettings.u8Channel] = pChnCfg->pTransferErrorNotify;
            pDmaHandle->tSettings.pInstance->tSettings.errdata[pDmaHandle->tSettings.u8Channel] = pChnCfg->errdata;
            DMA_HWA_EnableChannelErrorInterrupt(pDma, (uint8_t)u8Channel);
        }
        else
        {
            DMA_HWA_DisableChannelErrorInterrupt(pDma, (uint8_t)u8Channel);
            pDmaHandle->tSettings.pInstance->tSettings.pTransferErrorCallback[pDmaHandle->tSettings.u8Channel] = NULL;
        }
        #if DMA_DEV_ERROR_REPORT == STD_ON
    }
        #endif
}

void DMA_ConfigChainedTransfer(DMA_HandleType *pDmaHandle,
                               const DMA_ChainTransferType *const pChainTransferCfg)
{
    uint8_t u8Dma_Instance = pDmaHandle->tSettings.pInstance->tSettings.u8Instance;
    uint8_t u8Channel = pDmaHandle->tSettings.u8Channel;
    DMA_Type *aDma[] = DMA_BASE_PTRS;
    DMA_Type *const pDma = aDma[u8Dma_Instance];

    #if DMA_DEV_ERROR_REPORT == STD_ON
    if ((uint32_t)u8Dma_Instance >= DMA_INSTANCE_MAX)
    {
        DMA_ReportDevError(DMA_CONFIG_CHAINED_TRANS_ID, DMA_E_PARAM_INSTANCE);
    }
    else if ((uint32_t)u8Channel >= DMA_CHANNEL_MAX)
    {
        DMA_ReportDevError(DMA_CONFIG_CHAINED_TRANS_ID, DMA_E_PARAM_CHANNEL);
    }
    else if (pChainTransferCfg == NULL)
    {
        DMA_ReportDevError(DMA_CONFIG_CHAINED_TRANS_ID, DMA_E_PARAM_INTERRUPTCFG);
    }
    else
    {
    #endif
        DMA_HWA_SetOuterLoopTrigEnableFlag(pDma, (uint8_t)u8Channel, pChainTransferCfg->bChanelChainEn);
        DMA_HWA_SetOuterLoopTrigChannel(pDma, (uint8_t)u8Channel, pChainTransferCfg->u8ChainedChannel);
        #if DMA_DEV_ERROR_REPORT == STD_ON
    }
        #endif
}

DMA_StatusType DMA_ModifyAddress(DMA_HandleType *pDmaHandle, const volatile void *pSrcBuffer,
                                 const volatile void *pDestBuffer)
{
    uint8_t u8Dma_Instance = pDmaHandle->tSettings.pInstance->tSettings.u8Instance;
    uint8_t u8Channel = pDmaHandle->tSettings.u8Channel;
    DMA_Type *aDma[] = DMA_BASE_PTRS;
    DMA_Type *const pDma = aDma[u8Dma_Instance];
    DMA_StatusType ret;
    #ifdef DMA_HAVE_BACKDOOR
    uint32_t u32SrcAddr;
    uint32_t u32DesAddr;
    #endif

    #if DMA_DEV_ERROR_REPORT == STD_ON
    if ((uint32_t)u8Dma_Instance >= DMA_INSTANCE_MAX)
    {
        DMA_ReportDevError(DMA_CONFIG_MODIFY_ADDR_ID, DMA_E_PARAM_INSTANCE);
    }
    else if ((uint32_t)u8Channel >= DMA_CHANNEL_MAX)
    {
        DMA_ReportDevError(DMA_CONFIG_MODIFY_ADDR_ID, DMA_E_PARAM_CHANNEL);
    }
    else
    {
    #endif
        if (DMA_GetChannelStatus(pDmaHandle) == DMA_RUNNING_STATUS_IDLE)
        {
            #ifdef DMA_HAVE_BACKDOOR
            /* Translation the input src address and des address to backdoor address if necessary*/
            u32SrcAddr = Dma_SrcTranstoBackdoorAddress((uint32_t)pSrcBuffer);
            u32DesAddr = Dma_DesTranstoBackdoorAddress((uint32_t)pDestBuffer);
            DMA_HWA_SetSrcAddr(pDma, (uint8_t)u8Channel, (uint32_t)u32SrcAddr);
            DMA_HWA_SetDestAddr(pDma, (uint8_t)u8Channel, (uint32_t)u32DesAddr);
            #else
            if (pSrcBuffer != NULL)
            {
                DMA_HWA_SetSrcAddr(pDma, (uint8_t)u8Channel, (uint32_t)pSrcBuffer);
            }
            if (pDestBuffer != NULL)
            {
                DMA_HWA_SetDestAddr(pDma, (uint8_t)u8Channel, (uint32_t)pDestBuffer);
            }
            #endif
            ret = DMA_STATUS_SUCCESS;
        }
        else
        {
            ret = DMA_STATUS_BUSY;
        }
        return ret;
        #if DMA_DEV_ERROR_REPORT == STD_ON
    }
        #endif
}

void DMA_StartChannel(DMA_HandleType *pDmaHandle)
{
    uint8_t u8Dma_Instance = pDmaHandle->tSettings.pInstance->tSettings.u8Instance;
    uint8_t u8Channel = pDmaHandle->tSettings.u8Channel;
    DMA_Type *aDma[] = DMA_BASE_PTRS;
    DMA_Type *const pDma = aDma[u8Dma_Instance];

    #if DMA_DEV_ERROR_REPORT == STD_ON
    if ((uint32_t)u8Dma_Instance >= DMA_INSTANCE_MAX)
    {
        DMA_ReportDevError(DMA_CONFIG_START_CH_ID, DMA_E_PARAM_INSTANCE);
    }
    else if ((uint32_t)u8Channel >= DMA_CHANNEL_MAX)
    {
        DMA_ReportDevError(DMA_CONFIG_START_CH_ID, DMA_E_PARAM_CHANNEL);
    }
    else
    {
    #endif
        if (DMA_GetChannelRequestSrc(pDmaHandle) == DMA_REQ_DISABLED)
        {
            DMA_HWA_SetChannelStart(pDma, (uint8_t)u8Channel);
        }
        else
        {
            DMA_HWA_EnableChannelRequest(pDma, (uint8_t)u8Channel);
        }
        #if DMA_DEV_ERROR_REPORT == STD_ON
    }
        #endif
}

void DMA_StopChannel(DMA_HandleType *pDmaHandle)
{
    uint8_t u8Dma_Instance = pDmaHandle->tSettings.pInstance->tSettings.u8Instance;
    uint8_t u8Channel = pDmaHandle->tSettings.u8Channel;
    DMA_Type *aDma[] = DMA_BASE_PTRS;
    DMA_Type *const pDma = aDma[u8Dma_Instance];

    #if DMA_DEV_ERROR_REPORT == STD_ON
    if ((uint32_t)u8Dma_Instance >= DMA_INSTANCE_MAX)
    {
        DMA_ReportDevError(DMA_CONFIG_STOP_CH_ID, DMA_E_PARAM_INSTANCE);
    }
    else if ((uint32_t)u8Channel >= DMA_CHANNEL_MAX)
    {
        DMA_ReportDevError(DMA_CONFIG_STOP_CH_ID, DMA_E_PARAM_CHANNEL);
    }
    else
    {
    #endif
        DMA_HWA_DisableChannelRequest(pDma, (uint8_t)u8Channel);
        #if DMA_DEV_ERROR_REPORT == STD_ON
    }
        #endif
}

DMA_StatusType DMA_CancelTransfer(DMA_InstanceHandleType *pDmaInstanceHandle, bool bGenerateErr)
{
    uint8_t u8Dma_Instance = pDmaInstanceHandle->tSettings.u8Instance;
    DMA_Type *aDma[] = DMA_BASE_PTRS;
    DMA_Type *const pDma = aDma[u8Dma_Instance];
    DMA_StatusType eRet;
    uint32_t u32TimeOut = 15000000U;

    #if DMA_DEV_ERROR_REPORT == STD_ON
    if ((uint32_t)u8Dma_Instance >= DMA_INSTANCE_MAX)
    {
        DMA_ReportDevError(DMA_CONFIG_CANCEL_TRANS_ID, DMA_E_PARAM_INSTANCE);
    }
    else
    {
    #endif
        if (bGenerateErr)
        {
            DMA_HWA_ErrorCancelTransfer(pDma);
            while ((DMA_HWA_GetErrorCancelTransferStatus(pDma) == true) && (u32TimeOut != 0U))
            {
                u32TimeOut--;
            }
        }
        else
        {
            DMA_HWA_CancelTransfer(pDma);
            while ((DMA_HWA_GetCancelTransferStatus(pDma) == true) && (u32TimeOut != 0U))
            {
                u32TimeOut--;
            }
        }
        if (u32TimeOut != 0U)
        {
            eRet = DMA_STATUS_SUCCESS;
        }
        else
        {
            eRet = DMA_STATUS_TIMEOUT;
        }
        return eRet;
        #if DMA_DEV_ERROR_REPORT == STD_ON
    }
        #endif
}
#ifdef DMA_HAVE_MONCHK
void DMA_EnableMonitorChecker(DMA_InstanceHandleType *pDmaInstanceHandle)
{
    uint8_t u8Dma_Instance = pDmaInstanceHandle->tSettings.u8Instance;
    DMA_Type *aDma[] = DMA_BASE_PTRS;
    DMA_Type *const pDma = aDma[u8Dma_Instance];

    #if DMA_DEV_ERROR_REPORT == STD_ON
    if ((uint32_t)u8Dma_Instance >= DMA_INSTANCE_MAX)
    {
        DMA_ReportDevError(DMA_CONFIG_EN_MON_ID, DMA_E_PARAM_INSTANCE);
    }
    else
    {
    #endif
        #ifdef DMA0_HAVE_LOCKSTEP
        if ((uint32_t)u8Dma_Instance >= DMA_INSTANCE_1)
        #endif
        {
            DMA_HWA_EnableMonitorChecker(pDma);
        }
        #if DMA_DEV_ERROR_REPORT == STD_ON
    }
        #endif
}

void DMA_DisableMonitorChecker(DMA_InstanceHandleType *pDmaInstanceHandle)
{
    uint8_t u8Dma_Instance = pDmaInstanceHandle->tSettings.u8Instance;
    DMA_Type *aDma[] = DMA_BASE_PTRS;
    DMA_Type *const pDma = aDma[u8Dma_Instance];

    #if DMA_DEV_ERROR_REPORT == STD_ON
    if ((uint32_t)u8Dma_Instance >= DMA_INSTANCE_MAX)
    {
        DMA_ReportDevError(DMA_CONFIG_DISABLE_MON_ID, DMA_E_PARAM_INSTANCE);
    }
    else
    {
    #endif
        #ifdef DMA0_HAVE_LOCKSTEP
        if ((uint32_t)u8Dma_Instance >= DMA_INSTANCE_1)
        #endif
        {
            DMA_HWA_DisableMonitorChecker(pDma);
        }
        #if DMA_DEV_ERROR_REPORT == STD_ON
    }
        #endif
}

void DMA_ClearMonitorCheckerAllError(DMA_InstanceHandleType *pDmaInstanceHandle)
{
    uint8_t u8Dma_Instance = pDmaInstanceHandle->tSettings.u8Instance;
    DMA_Type *aDma[] = DMA_BASE_PTRS;
    DMA_Type *const pDma = aDma[u8Dma_Instance];

    #if DMA_DEV_ERROR_REPORT == STD_ON
    if ((uint32_t)u8Dma_Instance >= DMA_INSTANCE_MAX)
    {
        DMA_ReportDevError(DMA_CONFIG_CLEAR_MON_ID, DMA_E_PARAM_INSTANCE);
    }
    else
    {
    #endif
        #ifdef DMA0_HAVE_LOCKSTEP
        if ((uint32_t)u8Dma_Instance >= DMA_INSTANCE_1)
        #endif
        {
            DMA_HWA_ClearMonitorCheckerAllError(pDma);
        }
        #if DMA_DEV_ERROR_REPORT == STD_ON
    }
        #endif
}

uint32_t DMA_GetMonitorCheckerErrStatus(DMA_InstanceHandleType *pDmaInstanceHandle)
{
    uint8_t u8Dma_Instance = pDmaInstanceHandle->tSettings.u8Instance;
    DMA_Type *aDma[] = DMA_BASE_PTRS;
    DMA_Type *const pDma = aDma[u8Dma_Instance];
    uint32_t temp = 0u;

    #if DMA_DEV_ERROR_REPORT == STD_ON
    if ((uint32_t)u8Dma_Instance >= DMA_INSTANCE_MAX)
    {
        DMA_ReportDevError(DMA_CONFIG_GET_MON_ID, DMA_E_PARAM_INSTANCE);
    }
    else
    {
    #endif
        #ifdef DMA0_HAVE_LOCKSTEP
        if ((uint32_t)u8Dma_Instance >= DMA_INSTANCE_1)
        #endif
        {
            temp = DMA_HWA_GetMonitorCheckerErrStatus(pDma);
        }
        #if DMA_DEV_ERROR_REPORT == STD_ON
    }
        #endif
    return temp;
}
#endif
DMA_RequestSourceType DMA_GetChannelRequestSrc(DMA_HandleType *pDmaHandle)
{
    uint8_t u8Dma_Instance = pDmaHandle->tSettings.pInstance->tSettings.u8Instance;
    uint8_t u8Channel = pDmaHandle->tSettings.u8Channel;
    DMAMUX_Type *aDmamux[] = DMAMUX_BASE_PTRS;
    DMAMUX_Type *const pDmamux = aDmamux[u8Dma_Instance];

    #if DMA_DEV_ERROR_REPORT == STD_ON
    if ((uint32_t)u8Dma_Instance >= DMA_INSTANCE_MAX)
    {
        DMA_ReportDevError(DMA_CONFIG_GET_CH_REQ_SOURCE_ID, DMA_E_PARAM_INSTANCE);
    }
    else if ((uint32_t)u8Channel >= DMA_CHANNEL_MAX)
    {
        DMA_ReportDevError(DMA_CONFIG_GET_CH_REQ_SOURCE_ID, DMA_E_PARAM_CHANNEL);
    }
    else
    {
    #endif
        DMA_RequestSourceType eReqSrc = DMAMUX_HWA_GetRequestSource(pDmamux, (uint8_t)u8Channel);

        return eReqSrc;
        #if DMA_DEV_ERROR_REPORT == STD_ON
    }
        #endif
}

#ifdef DMA_CR_ACTIVE_MASK
DMA_RunningStatusType DMA_GetStatus(DMA_InstanceHandleType *pDmaInstanceHandle)
{
    uint8_t u8Dma_Instance = pDmaInstanceHandle->tSettings.u8Instance;
    DMA_Type *aDma[] = DMA_BASE_PTRS;
    DMA_Type *const pDma = aDma[u8Dma_Instance];

    #if DMA_DEV_ERROR_REPORT == STD_ON
    if ((uint32_t)u8Dma_Instance >= DMA_INSTANCE_MAX)
    {
        DMA_ReportDevError(DMA_CONFIG_GET_STATUS_ID, DMA_E_PARAM_INSTANCE);
    }
    else
    {
    #endif
        DMA_RunningStatusType eDMAStatus = DMA_HWA_GetStatus(pDma);
        return eDMAStatus;
        #if DMA_DEV_ERROR_REPORT == STD_ON
    }
        #endif
}
#endif

DMA_RunningStatusType DMA_GetChannelStatus(DMA_HandleType *pDmaHandle)
{
    uint8_t u8Dma_Instance = pDmaHandle->tSettings.pInstance->tSettings.u8Instance;
    uint8_t u8Channel = pDmaHandle->tSettings.u8Channel;
    DMA_Type *aDma[] = DMA_BASE_PTRS;
    DMA_Type *const pDma = aDma[u8Dma_Instance];

    #if DMA_DEV_ERROR_REPORT == STD_ON
    if ((uint32_t)u8Dma_Instance >= DMA_INSTANCE_MAX)
    {
        DMA_ReportDevError(DMA_CONFIG_GET_CH_STATUS_ID, DMA_E_PARAM_INSTANCE);
    }
    else if ((uint32_t)u8Channel >= DMA_CHANNEL_MAX)
    {
        DMA_ReportDevError(DMA_CONFIG_GET_CH_STATUS_ID, DMA_E_PARAM_CHANNEL);
    }
    else
    {
    #endif
        DMA_RunningStatusType eChannelStatus = DMA_HWA_GetChannelActiveStatus(pDma, (uint8_t)u8Channel);
        return eChannelStatus;
        #if DMA_DEV_ERROR_REPORT == STD_ON
    }
        #endif
}

#endif /* #if DMA_INSTANCE_COUNT > 0U */
