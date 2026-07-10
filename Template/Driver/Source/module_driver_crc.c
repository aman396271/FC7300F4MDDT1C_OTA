/**
 * @file module_driver_crc.c
 * @author Flagchip
 * @brief CRC driver source code
 * @version 2.0.0
 * @date 2024-08-20
 *
 * SDK Version: 2.6.0
 *

 * @copyright Copyright (c) 2020-2024 Flagchip Semiconductors Co., Ltd.
 *
 */
/********************************************************************************
*   Revision History:
*
*   Version     Date          Initials       CR#          Descriptions
*   ---------   ----------    ------------   ----------   ---------------
*   0.1.0      2023-12-15    Flagchip055     N/A          First version for FC7300
*   0.2.0      2024-10-12    Flagchip055     N/A          Change version and release
********************************************************************************/

#include "module_driver_crc.h"

#if CRC_INSTANCE_COUNT > 0U

#ifndef NULL
    #define NULL ((void *)0)
#endif


#ifndef CRC_DEV_ERROR_REPORT
#define CRC_DEV_ERROR_REPORT    STD_ON
#endif

#if CRC_DEV_ERROR_REPORT == STD_ON
#define CRC_ReportDevError(func, error) ReportDevError(CRC_MODULE_ID, func, error)
#endif


/********* Local Variables ************/
static CRC_Type *const s_apCrcBase[CRC_INSTANCE_COUNT] = CRC_BASE_PTRS;


/********* Global Functions ************/

void CRC_Init(Crc_HandleType *pCrcHandle, const Crc_ConfigType *const pInitCfg)
{
#if CRC_DEV_ERROR_REPORT == STD_ON
    if ((pCrcHandle == NULL) || (pInitCfg == NULL))
    {
        CRC_ReportDevError(CRC_INIT_ID, CRC_E_PARAM_POINTER);
    }
    else if(TRUE == pCrcHandle->tStatus.bInitStatus)
    {
        CRC_ReportDevError(CRC_INIT_ID, CRC_E_ALREADY_INIT);
    }
    else if (pCrcHandle->eInstance >= CRC_INSTANCE_COUNT)
    {
        CRC_ReportDevError(CRC_INIT_ID, CRC_E_PARAM_INSTANCE);
    }
    else
    {
#endif
        CRC_Type *const pCrc = s_apCrcBase[pCrcHandle->eInstance];

        if (pInitCfg->eBitWidth == CRC_BIT_8)
        {
            CRC_HWA_SetBitWidth(pCrc, (CRC_BitWidthType)0);
#if CRC_8_BIT_HARDWARE_SUPPORT
            CRC_HWA_Set_8Bit_Width(pCrc, (CRC_BitWidthType)1);
#endif
        }
        else
        {
            /* set CRC bit width(16-bit or 32-bit) */
#if CRC_8_BIT_HARDWARE_SUPPORT
            CRC_HWA_Set_8Bit_Width(pCrc, (CRC_BitWidthType)0);
#endif
            CRC_HWA_SetBitWidth(pCrc, pInitCfg->eBitWidth);
        }

        /* set CRC write/read swap and FXOR */
        CRC_HWA_SetWriteDataSwap(pCrc, pInitCfg->eWriteDataSwap);
        CRC_HWA_SetReadDataSwap(pCrc, pInitCfg->eReadDataSwap);
        CRC_HWA_SetReadDataFXOR(pCrc, pInitCfg->eReadDataFXOR);

        /* set CRC polynomial value */
        CRC_HWA_SetPolyVal(pCrc, pInitCfg->u32Polynomial);

        /* set CRC seed value */
        CRC_SetSeed(pCrcHandle, pInitCfg->u32SeedValue);
        pCrcHandle->tStatus.bInitStatus = TRUE;
#if CRC_DEV_ERROR_REPORT == STD_ON
    }
#endif
}

void CRC_DeInit(Crc_HandleType *pCrcHandle)
{
#if CRC_DEV_ERROR_REPORT == STD_ON
    if (pCrcHandle == NULL)
    {
        CRC_ReportDevError(CRC_DEINIT_ID, CRC_E_PARAM_POINTER);
    }
    else if(FALSE == pCrcHandle->tStatus.bInitStatus)
    {
        CRC_ReportDevError(CRC_DEINIT_ID, CRC_E_UNINIT);
    }
    else if (pCrcHandle->eInstance >= CRC_INSTANCE_COUNT)
    {
        CRC_ReportDevError(CRC_DEINIT_ID, CRC_E_PARAM_INSTANCE);
    }
    else
    {
#endif
        CRC_Type *const pCrc = s_apCrcBase[pCrcHandle->eInstance];

        /* set CRC bit width(32-bit) */
        CRC_HWA_SetBitWidth(pCrc, CRC_BIT_32);

        /* set CRC write/read swap and FXOR */
        CRC_HWA_SetWriteDataSwap(pCrc, WRITE_DATASWAP_NONE);
        CRC_HWA_SetReadDataSwap(pCrc, READ_DATASWAP_NONE);
        CRC_HWA_SetReadDataFXOR(pCrc, READ_DATA_NORMAL);

        /* set CRC polynomial value */
        CRC_HWA_SetPolyVal(pCrc, CRC_DEFAULT_POLY);

        /* set CRC seed value */
        CRC_SetSeed(pCrcHandle, CRC_DEFAULT_INTVAL);
        pCrcHandle->tStatus.bInitStatus = FALSE;
#if CRC_DEV_ERROR_REPORT == STD_ON
    }
#endif
}

uint32_t CRC_GetCrcResult(Crc_HandleType *pCrcHandle)
{
#if CRC_DEV_ERROR_REPORT == STD_ON
    if(FALSE == pCrcHandle->tStatus.bInitStatus)
    {
        CRC_ReportDevError(CRC_GETRST, CRC_E_UNINIT);
    }
    else
    {
#endif
        CRC_Type *const pCrc = s_apCrcBase[pCrcHandle->eInstance];
        CRC_ReadDataSwapType eTempVal;
        uint32_t u32Ret = 0U;

        u32Ret = CRC_HWA_GetData_U32(pCrc);

        eTempVal = CRC_HWA_GetReadDataSwap(pCrc);

#if CRC_8_BIT_HARDWARE_SUPPORT
        if (CRC_BIT_8 == CRC_HWA_Get8BitWidth(pCrc))
        {
            /* Returns upper 8 bits of CRC because of swap in 8 bits mode */
            if ((eTempVal == READ_DATASWAP_BIT_BYTE) || (eTempVal == READ_DATASWAP_BYTE))
            {
                u32Ret = (u32Ret & 0xFF00) >> 8;
            }
            else
            {
                u32Ret = (uint8_t)u32Ret;
            }
        }
        else if (CRC_BIT_16 == CRC_HWA_GetBitWidth(pCrc))
#else
        if (CRC_BIT_16 == CRC_HWA_GetBitWidth(pCrc))
#endif
        {
            /* Returns upper 16 bits of CRC because of swap in 16 bits mode */
            if ((eTempVal == READ_DATASWAP_BIT_BYTE) || (eTempVal == READ_DATASWAP_BYTE))
            {
                u32Ret = u32Ret >> 16U;
            }
            else
            {
                u32Ret = (uint16_t)u32Ret;
            }
        }
        else
        {
            /* do nothing */
        }

        return u32Ret;
#if CRC_DEV_ERROR_REPORT == STD_ON
    }
#endif
}

void CRC_SetCalcData_U8(Crc_HandleType *pCrcHandle, uint8_t u8Data)
{
#if CRC_DEV_ERROR_REPORT == STD_ON
    if(FALSE == pCrcHandle->tStatus.bInitStatus)
    {
        CRC_ReportDevError(CRC_SETCALCDATA8, CRC_E_UNINIT);
    }
    else
    {
#endif
        CRC_Type *const pCrc = s_apCrcBase[pCrcHandle->eInstance];

        CRC_HWA_SetData_U8(pCrc, u8Data);
#if CRC_DEV_ERROR_REPORT == STD_ON
    }
#endif
}

void CRC_SetCalcData_U16(Crc_HandleType *pCrcHandle, uint16_t u16Data)
{
#if CRC_DEV_ERROR_REPORT == STD_ON
    if(FALSE == pCrcHandle->tStatus.bInitStatus)
    {
        CRC_ReportDevError(CRC_SETCALCDATA16, CRC_E_UNINIT);
    }
    else
    {
#endif
        CRC_Type *const pCrc = s_apCrcBase[pCrcHandle->eInstance];

        CRC_HWA_SetData_U16(pCrc, u16Data);
#if CRC_DEV_ERROR_REPORT == STD_ON
    }
#endif
}

void CRC_SetCalcData_U32(Crc_HandleType *pCrcHandle, uint32_t u32Data)
{
#if CRC_DEV_ERROR_REPORT == STD_ON
    if(FALSE == pCrcHandle->tStatus.bInitStatus)
    {
        CRC_ReportDevError(CRC_SETCALCDATA32, CRC_E_UNINIT);
    }
    else
    {
#endif
        CRC_Type *const pCrc = s_apCrcBase[pCrcHandle->eInstance];

        CRC_HWA_SetData_U32(pCrc, u32Data);
#if CRC_DEV_ERROR_REPORT == STD_ON
    }
#endif
}

void CRC_SetSeed(Crc_HandleType *pCrcHandle, uint32_t u32SeedVal)
{
	CRC_Type *const pCrc = s_apCrcBase[pCrcHandle->eInstance];

	CRC_HWA_SetDataOrSeed(pCrc, WRITE_COMMAND_SEED);
	CRC_HWA_SetData_U32(pCrc, u32SeedVal);
	CRC_HWA_SetDataOrSeed(pCrc, WRITE_COMMAND_DATA);

}

void CRC_SetInputData(Crc_HandleType *pCrcHandle, const uint8_t pData[], uint32_t u32DataSize)
{
#if CRC_DEV_ERROR_REPORT == STD_ON
    if(FALSE == pCrcHandle->tStatus.bInitStatus)
    {
        CRC_ReportDevError(CRC_SETINPUTDATA, CRC_E_UNINIT);
    }
    else
    {
#endif
        uint32_t i;

        for (i = 0U; i < u32DataSize; i++)
        {
            CRC_SetCalcData_U8(pCrcHandle, pData[i]);
        }
#if CRC_DEV_ERROR_REPORT == STD_ON
    }
#endif
}

#endif


