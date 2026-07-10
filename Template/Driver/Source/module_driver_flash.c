/**
 * @file module_driver_flash.c
 * @author Flagchip
 * @brief Flash driver source code
 * @version 2.0.0
 * @date 2024-08-20
 *
 * SDK Version: 2.6.0
 *

 * @copyright Copyright (c) 2020-2024 Flagchip Semiconductors Co., Ltd.
 */
/* ********************************************************************************
   *   Revision History:
   *
   *   Version     Date          Initials      CR#          Descriptions
   *   ---------   ----------    ------------  ----------   ---------------
   *   0.1.0       29/12/2022    GuangLong     N/A          First version for FC7300
   *   0.2.0       13/02/2022    GuangLong     N/A          remove the nvr function
   *   2.0.0       30/07/2024    HowardWang    N/A          Vesion 2.0
   *   2.1.0       30/11/2024    HowardWang    N/A          Add support for FC7300F8MDQ
   *   2.3.5       10/06/2025    HowardWang    N/A          Add flash DMA abort, update flash DMA error process.
   ******************************************************************************** */

#include "module_driver_flash.h"

#if FLASH_INSTANCE_COUNT > 0U

#ifndef FLASH_DEV_ERROR_REPORT
    #define FLASH_DEV_ERROR_REPORT  STD_OFF
#endif

#if FLASH_DEV_ERROR_REPORT == STD_ON
    #define FLASH_ReportDevError(func, error) ReportDevError(FLASH_MODULE_ID, func, error)
#endif

/* ################################################################################## */
/* ####################################### Macro #################################### */

/** flash driver header for finding function in special address */

static  FLASH_ROM_API_ENTRY_T *const s_pFlashDriver[FLASH_INSTANCE_COUNT] = FLASHDRV_BASE_ADDR;


/* ################################################################################## */
/* ################################ Local Variables ################################# */


/* ################################################################################## */
/* ########################### Local Prototype Functions ############################ */
static FLASH_StatusType FLASHDRIVER_EraseCheck(FLASH_DRIVER_ParamType *pFlashParam);
static FLASH_StatusType FLASHDRIVER_WriteCheck(FLASH_DRIVER_ParamType *pFlashParam);
static FLASH_StatusType NVRDRIVER_EraseCheck(FLASH_DRIVER_ParamType *pFlashParam);
static FLASH_StatusType NVRDRIVER_WriteCheck(FLASH_DRIVER_ParamType *pFlashParam);
static FLASH_StatusType FLASHDRIVER_GetFlashConfig(uint32_t u32Address, FLASH_API_ERASESECTOR_TYPE *pFlash_api_cfg);
static void FLASHDRIVER_INTSingleErase(FLASH_HandleType *pFlashHandle);
static void FLASHDRIVER_INTSingleProgram(FLASH_HandleType *pFlashHandle);
static ECC_StatusType FLASHDRIVER_EccCheck(FLASH_HandleType *pFlashHandle);
static uint8_t FLASHDRIVER_MsrIsOn(void);


/* ################################################################################## */
/* ########################### Global Prototype Functions ########################### */




/* ################################################################################## */
/* ################################ Local Functions ################################# */

/**
 * @brief Flash Driver Function for Erasing Address Check
 *
 * @param pFlashParam flash driver erase parameter
 */
static FLASH_StatusType FLASHDRIVER_EraseCheck(FLASH_DRIVER_ParamType *pFlashParam)
{
    uint32_t u32Addr, u32Length;
    FLASH_StatusType tRetVal;

    u32Addr = pFlashParam->u32Address;
    u32Length = pFlashParam->u32Length;
    tRetVal = FLASH_ERROR_OK;
    pFlashParam->u32ErrorAddress = 0x0U;

    if ((u32Addr >= PFLASH_ADDR_START) && ((u32Addr + u32Length) <= (PFLASH_ADDR_END + 1)))
    {
        /* check address align */
        if (u32Addr & (PFLASH_ERASE_SECTOR_SIZE - 1U))
        {
            tRetVal = FLASH_ERROR_INVALID_ADDR;
            pFlashParam->u32ErrorAddress = u32Addr;
        }
        else
        {
            /* check length align */
            if (u32Length & (PFLASH_ERASE_SECTOR_SIZE - 1U))
            {
                tRetVal = FLASH_ERROR_INVALID_SIZE;
                pFlashParam->u32ErrorAddress = u32Addr;
            }
        }
    }
    else if ((DFLASH_ADDR_START <= u32Addr)  && ((u32Addr + u32Length) <= (DFLASH_ADDR_END + 1)))
    {
        /* check address align */
        if (u32Addr & (DFLASH_ERASE_SECTOR_SIZE - 1U))
        {
            tRetVal = FLASH_ERROR_INVALID_ADDR;
            pFlashParam->u32ErrorAddress = u32Addr;
        }
        else
        {
            /* check length align */
            if (u32Length & (DFLASH_ERASE_SECTOR_SIZE - 1U))
            {
                tRetVal = FLASH_ERROR_INVALID_SIZE;
                pFlashParam->u32ErrorAddress = u32Addr;
            }
        }
    }
    else
    {
        tRetVal = FLASH_ERROR_INVALID_PARAM;
        pFlashParam->u32ErrorAddress = u32Addr;
    }

    return tRetVal;
}

/**
 * @brief Flash Driver Function for Writing address Check
 *
 * @param pFlashParam flash driver write parameter
 */
static FLASH_StatusType FLASHDRIVER_WriteCheck(FLASH_DRIVER_ParamType *pFlashParam)
{
    uint32_t u32Addr, u32Length;
    FLASH_StatusType tRetVal;
    u32Addr = pFlashParam->u32Address;
    u32Length = pFlashParam->u32Length;
    tRetVal = FLASH_ERROR_OK;
    pFlashParam->u32ErrorAddress = 0x0U;

    if ((u32Addr >= PFLASH_ADDR_START) && ((u32Addr + u32Length) <= (PFLASH_ADDR_END + 1)))
    {
        /* check address align */
        if (u32Addr & (PFLASH_PROGRAM_PAGE_MIN_SIZE - 1U))
        {
            tRetVal = FLASH_ERROR_INVALID_ADDR;
            pFlashParam->u32ErrorAddress = pFlashParam->u32Address;
        }
        /* check length align */
        else
        {
            if (u32Length & (PFLASH_PROGRAM_PAGE_MIN_SIZE - 1U))
            {
                tRetVal = FLASH_ERROR_INVALID_SIZE;
                pFlashParam->u32ErrorAddress = pFlashParam->u32Address;
            }
        }
    }
    else if ((DFLASH_ADDR_START <= u32Addr)  && ((u32Addr + u32Length) <= (DFLASH_ADDR_END + 1)))
    {
        /* check length align */
        if (u32Addr & (DFLASH_PROGRAM_PAGE_MIN_SIZE - 1U))
        {
            tRetVal = FLASH_ERROR_INVALID_ADDR;
            pFlashParam->u32ErrorAddress = pFlashParam->u32Address;
        }
        else
        {
            if (u32Length & (DFLASH_PROGRAM_PAGE_MIN_SIZE - 1U))
            {
                tRetVal = FLASH_ERROR_INVALID_SIZE;
                pFlashParam->u32ErrorAddress = pFlashParam->u32Address;
            }
        }
    }
    else
    {
        tRetVal = FLASH_ERROR_INVALID_PARAM;
        pFlashParam->u32ErrorAddress = u32Addr;
    }
    return tRetVal;
}

/**
 * @brief Flash Driver Function for Erasing NVR Address Check
 *
 * @param pFlashParam flash driver erase NVR parameter
 */
static FLASH_StatusType NVRDRIVER_EraseCheck(FLASH_DRIVER_ParamType *pFlashParam)
{
    uint32_t u32Addr, u32Length;
    FLASH_StatusType tRetVal;
    u32Addr = pFlashParam->u32Address;
    u32Length = pFlashParam->u32Length;
    tRetVal = FLASH_ERROR_OK;

#if(FLASH_FC7240F2MDS == STD_ON)
    if ((NVR0_FLASH_ADDR_START <= u32Addr && (u32Addr + u32Length) <= (NVR0_FLASH_ADDR_END + 1)) \
        || (NVR1_FLASH_ADDR_START <= u32Addr && (u32Addr + u32Length) <= (NVR1_FLASH_ADDR_END + 1)) \
        || (NVR2_FLASH_ADDR_START <= u32Addr && (u32Addr + u32Length) <= (NVR2_FLASH_ADDR_END + 1))
       )
#elif((FLASH_FC7300F4MDD_T1C == STD_ON) || (FLASH_FC7300F4MDS_T1C == STD_ON))
    if ((NVR0_FLASH_ADDR_START <= u32Addr && (u32Addr + u32Length) <= (NVR0_FLASH_ADDR_END + 1)) \
        || (NVR2_FLASH_ADDR_START <= u32Addr && (u32Addr + u32Length) <= (NVR2_FLASH_ADDR_END + 1))
       )
#elif((FLASH_FC7300F8MDT == STD_ON) || (FLASH_FC7300F4MDD_T1B == STD_ON) || (FLASH_FC7300F4MDS_T1B == STD_ON) || (FLASH_FC7300F8MDQ == STD_ON))
        if (NVR_FLASH_ADDR_START <= u32Addr && (u32Addr + u32Length) <= (NVR_FLASH_ADDR_END + 1))
#endif
        {
            /* check address align */
            if (u32Addr & (NVR_ERASE_SECTOR_SIZE - 1U))
            {
                tRetVal = FLASH_ERROR_INVALID_ADDR;
                pFlashParam->u32ErrorAddress = u32Addr;
            }
            else
            {
                /* check length align */
                if (u32Length & (NVR_ERASE_SECTOR_SIZE - 1U))
                {
                    tRetVal = FLASH_ERROR_INVALID_SIZE;
                    pFlashParam->u32ErrorAddress = u32Addr;
                }
            }
        }
        else
        {
            tRetVal = FLASH_ERROR_INVALID_PARAM;
            pFlashParam->u32ErrorAddress = u32Addr;
        }
    return tRetVal;
}

/**
 * @brief Flash Driver Function for Writing NVR address Check
 *
 * @param pFlashParam flash driver write NVR parameter
 */
static FLASH_StatusType NVRDRIVER_WriteCheck(FLASH_DRIVER_ParamType *pFlashParam)
{
    uint32_t u32Addr, u32Length;
    FLASH_StatusType tRetVal;

    u32Addr = pFlashParam->u32Address;
    u32Length = pFlashParam->u32Length;

    tRetVal = FLASH_ERROR_OK;
    pFlashParam->u32ErrorAddress = 0x0U;

#if(FLASH_FC7240F2MDS == STD_ON)
    if ((NVR0_FLASH_ADDR_START <= u32Addr && u32Addr + u32Length  <= NVR0_FLASH_ADDR_END + 1) || \
        (NVR1_FLASH_ADDR_START <= u32Addr && u32Addr + u32Length  <= NVR1_FLASH_ADDR_END + 1) || \
        (NVR2_FLASH_ADDR_START <= u32Addr && u32Addr + u32Length  <= NVR2_FLASH_ADDR_END + 1))
#elif((FLASH_FC7300F4MDD_T1C == STD_ON) || (FLASH_FC7300F4MDS_T1C == STD_ON))
    if ((NVR0_FLASH_ADDR_START <= u32Addr && (u32Addr + u32Length) <= (NVR0_FLASH_ADDR_END + 1)) \
        || (NVR2_FLASH_ADDR_START <= u32Addr && (u32Addr + u32Length) <= (NVR2_FLASH_ADDR_END + 1))
       )
#elif((FLASH_FC7300F8MDT == STD_ON) || (FLASH_FC7300F4MDD_T1B == STD_ON) || (FLASH_FC7300F4MDS_T1B == STD_ON) || (FLASH_FC7300F8MDQ == STD_ON))
        if (NVR_FLASH_ADDR_START <= u32Addr && (u32Addr + u32Length) <= (NVR_FLASH_ADDR_END + 1))
#endif
        {
            /* check address align */
            if (u32Addr & (NVR_PROGRAM_PAGE_MIN_SIZE - 1U))
            {
                tRetVal = FLASH_ERROR_INVALID_ADDR;
                pFlashParam->u32ErrorAddress = pFlashParam->u32Address;
            }
            /* check length align */
            else
            {
                if (u32Length & (NVR_PROGRAM_PAGE_MIN_SIZE - 1U))
                {
                    tRetVal = FLASH_ERROR_INVALID_SIZE;
                    pFlashParam->u32ErrorAddress = pFlashParam->u32Address;
                }
            }
        }
        else
        {
            tRetVal = FLASH_ERROR_INVALID_PARAM;
            pFlashParam->u32ErrorAddress = u32Addr;
        }
    return tRetVal;
}

/**
 * @brief Get Flash Configuration
 *
 * @param u32Address the flash address
 * @param pFlash_api_cfg out flash parameter
 */
static FLASH_StatusType FLASHDRIVER_GetFlashConfig(uint32_t u32Address, FLASH_API_ERASESECTOR_TYPE *pFlash_api_cfg)
{
    FLASH_StatusType tRetVal;
    tRetVal = FLASH_ERROR_OK;
    uint32 u32Index = 0;

    if ((u32Address >= PFLASH_ADDR_START) && (u32Address < PFLASH_ADDR_START + PFLASH_SIZE))
    {
        /* PFLASH bank index */
        u32Index = (u32Address - PFLASH_ADDR_START) / PFLASH_BANK_SIZE;
        pFlash_api_cfg->blk_sel = FLASH_BLOCK_SELECT0 + u32Index;
        pFlash_api_cfg->dest = u32Address;
    }
    else if ((u32Address >= DFLASH_ADDR_START) && (u32Address <= DFLASH_ADDR_END))
    {
        /* DFLASH bank index */
        u32Index = (u32Address - DFLASH_ADDR_START) / DFLASH_BANK_SIZE;
        pFlash_api_cfg->blk_sel = FLASH_DATA_BLOCK_SELECT0 + u32Index;
        pFlash_api_cfg->dest = u32Address;
    }
    else
    {
        tRetVal = FLASH_ERROR_INVALID_ADDR;
    }
    return tRetVal;
}

/**
* @brief        flash driver single erase
* @param[in]    Flash instance
* @return       none
*/
static void FLASHDRIVER_INTSingleErase(FLASH_HandleType *pFlashHandle)
{
    FLASH_ROM_API_ENTRY_T *const s_pFlashDriver_FuncHeader = s_pFlashDriver[pFlashHandle->eInstance];
    FLASH_API_ERASESECTOR_TYPE tFlash_api_cfg = {0};
    uint8_t u8IsEnInterupt;

    (s_pFlashDriver_FuncHeader)->FLASH_DRV_ENABLE_HOLD_CFG(1);
    if(NULL != pFlashHandle->tSettings.pUnlockCallback)
    {
        pFlashHandle->tSettings.pUnlockCallback(pFlashHandle->tStatus.u32CurrentAddress);
    }
    FLASHDRIVER_GetFlashConfig(pFlashHandle->tStatus.u32CurrentAddress, &tFlash_api_cfg);

    pFlashHandle->tStatus.u32CurrentAddress += pFlashHandle->tStatus.u32EraseSectorSize;
    /* Disable Inetrrupt*/
    u8IsEnInterupt = FLASHDRIVER_MsrIsOn();//0 disable ,1 enable
    if(u8IsEnInterupt == 1)
    {
        __asm(" cpsid i");
    }

    if (FLASH_HARDWARE_STATUS_IDLE == (((*(volatile uint32 *)FLASH_HARDWARE_STATUS_ADDR) & FLASH_HARDWARE_STATUS_MASK) >> 16))
    {
#if((FLASH_FC7300F8MDT == STD_ON) || (FLASH_FC7300F4MDD_T1B == STD_ON) || (FLASH_FC7300F4MDS_T1B == STD_ON) || (FLASH_FC7240F2MDS == STD_ON))
        (s_pFlashDriver_FuncHeader)->FLASH_DRV_EraseSector(&tFlash_api_cfg, FLASH_API_ENABLE, FLASH_API_SIZE);
#elif((FLASH_FC7300F8MDQ == STD_ON) || (FLASH_FC7300F4MDD_T1C == STD_ON) || (FLASH_FC7300F4MDS_T1C == STD_ON))
        tFlash_api_cfg.int_en = FLASH_API_ENABLE;
        (s_pFlashDriver_FuncHeader)->FLASH_DRV_EraseSector(&tFlash_api_cfg);
#endif
    }
    /* Recover Inetrrupt*/
    if(u8IsEnInterupt == 1)
    {
        __asm(" cpsie i");
    }
}

/**
* @brief        flash driver single program
* @param[in]    Flash instance
* @return       none
*/
static void FLASHDRIVER_INTSingleProgram(FLASH_HandleType *pFlashHandle)
{
    FLASH_ROM_API_ENTRY_T *const s_pFlashDriver_FuncHeader = s_pFlashDriver[pFlashHandle->eInstance];
    FLASH_API_PRGM_CFG_TYPE tFlash_api_cfg = {0};
    uint32_t u32ProgramEndAddr, u32EndAddr;
    uint8_t u8IsEnInterupt;

    u32EndAddr = pFlashHandle->tStatus.u32Address + pFlashHandle->tStatus.u32Length;
    u32ProgramEndAddr = ((pFlashHandle->tStatus.u32CurrentAddress + FLASH_PROGRAM_PAGE_MAX_SIZE) & ~(FLASH_PROGRAM_PAGE_MAX_SIZE - 1U));
    u32ProgramEndAddr = ((u32ProgramEndAddr > u32EndAddr) ? u32EndAddr : u32ProgramEndAddr);
    pFlashHandle->tStatus.u32ProgramSize = u32ProgramEndAddr - pFlashHandle->tStatus.u32CurrentAddress;
    if(NULL != pFlashHandle->tSettings.pUnlockCallback)
    {
        pFlashHandle->tSettings.pUnlockCallback(pFlashHandle->tStatus.u32CurrentAddress);
    }
    tFlash_api_cfg.dest = pFlashHandle->tStatus.u32CurrentAddress;
    tFlash_api_cfg.size = (uint32_t)(pFlashHandle->tStatus.u32ProgramSize) >> 2;  /* one data is 4 bytes  */
    tFlash_api_cfg.pData = (uint32_t *)(pFlashHandle->tStatus.pDate);
    tFlash_api_cfg.wdg_tune = WDG_TUNE_DISABLE;
    tFlash_api_cfg.pgff = FLASH_REG_BIT_CFG_DISABLE;

    pFlashHandle->tStatus.u32CurrentAddress += pFlashHandle->tStatus.u32ProgramSize;
    /* Disable Inetrrupt*/
    u8IsEnInterupt = FLASHDRIVER_MsrIsOn();//0 disable ,1 enable
    if(u8IsEnInterupt == 1)
    {
        __asm(" cpsid i");
    }
    if (FLASH_HARDWARE_STATUS_IDLE == (((*(volatile uint32 *)FLASH_HARDWARE_STATUS_ADDR) & FLASH_HARDWARE_STATUS_MASK) >> 16))
    {
#if((FLASH_FC7300F8MDT == STD_ON) || (FLASH_FC7300F4MDD_T1B == STD_ON) || (FLASH_FC7300F4MDS_T1B == STD_ON) || (FLASH_FC7240F2MDS == STD_ON))
        (s_pFlashDriver_FuncHeader)->FLASH_DRV_Program(&tFlash_api_cfg, FLASH_API_ENABLE, FLASH_API_SIZE);
#elif((FLASH_FC7300F8MDQ == STD_ON) || (FLASH_FC7300F4MDD_T1C == STD_ON) || (FLASH_FC7300F4MDS_T1C == STD_ON))
        tFlash_api_cfg.int_en = FLASH_API_ENABLE;
        (s_pFlashDriver_FuncHeader)->FLASH_DRV_Program(&tFlash_api_cfg);
#endif
    }
    /* Recover Inetrrupt*/
    if(u8IsEnInterupt == 1)
    {
        __asm(" cpsie i");
    }
}

/**
* @brief        Flash driver single program
* @param[in]    Flash instance
* @return       Have ecc or not
*/
static ECC_StatusType FLASHDRIVER_EccCheck(FLASH_HandleType *pFlashHandle)
{
    FLASH_ROM_API_ENTRY_T *const s_pFlashDriver_FuncHeader = s_pFlashDriver[pFlashHandle->eInstance];
    ECC_StatusType tRetVal;
    volatile uint8_t u8RealData;
    uint32 u32ReadAddr, u32ApiReturnValue;
    uint32 u32EccCont = FMC0->FEEC;
    /* Disable ECC */
    FMC0->FEEC = 0x00000080u;
    /** Clear ECC flag*/
#if(FLASH_FC7240F2MDS == STD_ON)
    (s_pFlashDriver_FuncHeader)->FLASH_DRV_Read_Status_Check_Clear(FLASH_ECC_CHECK_MASK);
    (s_pFlashDriver_FuncHeader)->FLASH_DRV_Read_Status_Check_Clear_128(FLASH_ECC_CHECK_MASK);
#elif((FLASH_FC7300F8MDQ == STD_ON))
    (s_pFlashDriver_FuncHeader)->FLASH_DRV_Read_Status_Check_Clear(FLASH_ECC_CHECK_MASK);
    (s_pFlashDriver_FuncHeader)->FLASH_DRV_Read_Status_Check_Clear_128(FLASH_ECC_CHECK_MASK);
    (s_pFlashDriver_FuncHeader)->FLASH_DRV_Read_Status_Check_Clear_P1(FLASH_ECC_CHECK_MASK);
    (s_pFlashDriver_FuncHeader)->FLASH_DRV_Read_Status_Check_Clear_P1_128(FLASH_ECC_CHECK_MASK);
    (s_pFlashDriver_FuncHeader)->FLASH_DRV_Read_Status_Check_Clear_P2(FLASH_ECC_CHECK_MASK);
#elif((FLASH_FC7300F8MDT == STD_ON) || (FLASH_FC7300F4MDD_T1B == STD_ON) || (FLASH_FC7300F4MDS_T1B == STD_ON))
    (s_pFlashDriver_FuncHeader)->FLASH_DRV_Read_Status_Check_Clear(FLASH_ECC_CHECK_MASK);
    (s_pFlashDriver_FuncHeader)->FLASH_DRV_Read_Status_Check_Clear_P1(FLASH_ECC_CHECK_MASK);
    (s_pFlashDriver_FuncHeader)->FLASH_DRV_Read_Status_Check_Clear_P2(FLASH_ECC_CHECK_MASK);
#elif((FLASH_FC7300F4MDD_T1C == STD_ON) || (FLASH_FC7300F4MDS_T1C == STD_ON))
    (s_pFlashDriver_FuncHeader)->FLASH_DRV_Read_Status_Check_Clear(FLASH_ECC_CHECK_MASK);
    (s_pFlashDriver_FuncHeader)->FLASH_DRV_Read_Status_Check_Clear_128(FLASH_ECC_CHECK_MASK);
    (s_pFlashDriver_FuncHeader)->FLASH_DRV_Read_Status_Check_Clear_P2(FLASH_ECC_CHECK_MASK);
#endif
    /** Readback*/
    for(u32ReadAddr = pFlashHandle->tStatus.u32Address; u32ReadAddr < pFlashHandle->tStatus.u32Address + pFlashHandle->tStatus.u32Length; u32ReadAddr++)
    {
        u8RealData = *(uint8_t *)u32ReadAddr;
    }
    /** Check ECC*/
#if(FLASH_FC7240F2MDS == STD_ON)
    u32ApiReturnValue = (s_pFlashDriver_FuncHeader)->FLASH_DRV_Read_Status_Check(FLASH_ECC_CHECK_MASK);
    u32ApiReturnValue |= (s_pFlashDriver_FuncHeader)->FLASH_DRV_Read_Status_Check_128(FLASH_ECC_CHECK_MASK);
    (s_pFlashDriver_FuncHeader)->FLASH_DRV_Read_Status_Check_Clear(FLASH_ECC_CHECK_MASK);
    (s_pFlashDriver_FuncHeader)->FLASH_DRV_Read_Status_Check_Clear_128(FLASH_ECC_CHECK_MASK);
#elif((FLASH_FC7300F8MDQ == STD_ON))
    u32ApiReturnValue = (s_pFlashDriver_FuncHeader)->FLASH_DRV_Read_Status_Check(FLASH_ECC_CHECK_MASK);
    u32ApiReturnValue |= (s_pFlashDriver_FuncHeader)->FLASH_DRV_Read_Status_Check_128(FLASH_ECC_CHECK_MASK);
    u32ApiReturnValue |= (s_pFlashDriver_FuncHeader)->FLASH_DRV_Read_Status_Check_P1(FLASH_ECC_CHECK_MASK);
    u32ApiReturnValue |= (s_pFlashDriver_FuncHeader)->FLASH_DRV_Read_Status_Check_P1_128(FLASH_ECC_CHECK_MASK);
    u32ApiReturnValue |= (s_pFlashDriver_FuncHeader)->FLASH_DRV_Read_Status_Check_P2(FLASH_ECC_CHECK_MASK);
    (s_pFlashDriver_FuncHeader)->FLASH_DRV_Read_Status_Check_Clear(FLASH_ECC_CHECK_MASK);
    (s_pFlashDriver_FuncHeader)->FLASH_DRV_Read_Status_Check_Clear_128(FLASH_ECC_CHECK_MASK);
    (s_pFlashDriver_FuncHeader)->FLASH_DRV_Read_Status_Check_Clear_P1(FLASH_ECC_CHECK_MASK);
    (s_pFlashDriver_FuncHeader)->FLASH_DRV_Read_Status_Check_Clear_P1_128(FLASH_ECC_CHECK_MASK);
    (s_pFlashDriver_FuncHeader)->FLASH_DRV_Read_Status_Check_Clear_P2(FLASH_ECC_CHECK_MASK);
#elif((FLASH_FC7300F8MDT == STD_ON) || (FLASH_FC7300F4MDD_T1B == STD_ON) || (FLASH_FC7300F4MDS_T1B == STD_ON))
    u32ApiReturnValue = (s_pFlashDriver_FuncHeader)->FLASH_DRV_Read_Status_Check(FLASH_ECC_CHECK_MASK);
    u32ApiReturnValue |= (s_pFlashDriver_FuncHeader)->FLASH_DRV_Read_Status_Check_P1(FLASH_ECC_CHECK_MASK);
    u32ApiReturnValue |= (s_pFlashDriver_FuncHeader)->FLASH_DRV_Read_Status_Check_P2(FLASH_ECC_CHECK_MASK);
    (s_pFlashDriver_FuncHeader)->FLASH_DRV_Read_Status_Check_Clear(FLASH_ECC_CHECK_MASK);
    (s_pFlashDriver_FuncHeader)->FLASH_DRV_Read_Status_Check_Clear_P1(FLASH_ECC_CHECK_MASK);
    (s_pFlashDriver_FuncHeader)->FLASH_DRV_Read_Status_Check_Clear_P2(FLASH_ECC_CHECK_MASK);
#elif((FLASH_FC7300F4MDD_T1C == STD_ON) || (FLASH_FC7300F4MDS_T1C == STD_ON))
    u32ApiReturnValue = (s_pFlashDriver_FuncHeader)->FLASH_DRV_Read_Status_Check(FLASH_ECC_CHECK_MASK);
    u32ApiReturnValue |= (s_pFlashDriver_FuncHeader)->FLASH_DRV_Read_Status_Check_128(FLASH_ECC_CHECK_MASK);
    u32ApiReturnValue |= (s_pFlashDriver_FuncHeader)->FLASH_DRV_Read_Status_Check_P2(FLASH_ECC_CHECK_MASK);
    (s_pFlashDriver_FuncHeader)->FLASH_DRV_Read_Status_Check_Clear(FLASH_ECC_CHECK_MASK);
    (s_pFlashDriver_FuncHeader)->FLASH_DRV_Read_Status_Check_Clear_128(FLASH_ECC_CHECK_MASK);
    (s_pFlashDriver_FuncHeader)->FLASH_DRV_Read_Status_Check_Clear_P2(FLASH_ECC_CHECK_MASK);
#endif
    /* Recover ECC control register*/
    FMC0->FEEC = u32EccCont;
    if(u32ApiReturnValue == STATUS_SUCCESS)
    {
        tRetVal = FLASH_ECC_ERROR_NONE;
    }
    else
    {
        pFlashHandle->tStatus.eFlsStatus = FLS_WRITING_ECC;
        tRetVal = FLASH_ECC_ERROR_DBC;
    }
    (void)u8RealData;
    return tRetVal;
}

/**
* @brief        Flash driver check Interrupt
* @param[in]    void
* @return       1:enable 0:disable
*/
static uint8_t FLASHDRIVER_MsrIsOn(void)
{
    uint8_t u8ReturnValue;
    uint32 u32RegTemp;
#ifdef USER_MODE_SUPPORT
    __asm volatile(" mrs %0, basepri " : "=r"(u32RegTemp));
#else
    __asm volatile(" mrs %0, primask " : "=r"(u32RegTemp));
#endif
    if(0u == (u32RegTemp & 0x00000001U))
    {
        u8ReturnValue = 1U;
    }
    else
    {
        u8ReturnValue = 0U;
    }
    return u8ReturnValue;
}

/* ################################################################################## */
/* ################################# Global Functions ############################### */

/**
 * @brief Flash Driver Function for lock/unlock sector
 *
 * @param u32Address sector address
 * @param bLock 0U-unlock, 1U-lock
 */
FLASH_StatusType FLASHDRIVER_LockSector(uint32_t u32Address, FLASH_LOCK_TYPE bLock)
{
    FLASH_StatusType tRetVal;
    tRetVal = FLASH_ERROR_OK;
    uint32 u32Index = 0;
    uint32 u32Length = 0;
    uint32 u32Temp = 0;

    /* 1 bank contains more than 256KB, used FB_CPELCK for first and last 256KB used FB_FPELCK */
    if ((u32Address <= (PFLASH_ADDR_START + PFLASH_SIZE)) && (u32Address >= PFLASH_ADDR_START))
    {
        /* PFLASH bank index */
        u32Index = (u32Address - PFLASH_ADDR_START) / PFLASH_BANK_SIZE;
        u32Length = ((u32Address - PFLASH_ADDR_START) % PFLASH_BANK_SIZE);
        if (u32Length < (PFLASH_BANK_SIZE - FLASH_256KB_SIZE))
        {
#if((FLASH_FC7300F8MDT == STD_ON) || (FLASH_FC7300F4MDD_T1B == STD_ON) || (FLASH_FC7300F4MDS_T1B == STD_ON) || (FLASH_FC7240F2MDS == STD_ON) || (FLASH_FC7300F8MDQ == STD_ON))
            u32Temp = ((uint32)1UL << ((u32Address - PFLASH_ADDR_START - PFLASH_BANK_SIZE * u32Index) >> 16));
            bLock ? (FMC0->FB_CPELCK[u32Index] |= u32Temp) : ((FMC0->FB_CPELCK[u32Index] &= ~u32Temp));
#elif((FLASH_FC7300F4MDD_T1C == STD_ON) || (FLASH_FC7300F4MDS_T1C == STD_ON))
            if(u32Index < 2)
            {
                u32Temp = ((uint32)1UL << ((u32Address - PFLASH_ADDR_START - PFLASH_BANK_SIZE * u32Index) >> 16));
                bLock ? (FMC0->FB_CPELCK[u32Index] |= u32Temp) : ((FMC0->FB_CPELCK[u32Index] &= ~u32Temp));
            }
            else
            {
                u32Temp = ((uint32)1UL << ((u32Address - PFLASH_ADDR_START - PFLASH_BANK_SIZE * u32Index) >> 16));
                bLock ? (FMC0->FB_CPELCK[u32Index + 2] |= u32Temp) : ((FMC0->FB_CPELCK[u32Index +2] &= ~u32Temp));                
            }
#endif
        }
        else /* last 256KB */
        {
            u32Temp = ((u32Address - PFLASH_ADDR_START - PFLASH_BANK_SIZE * u32Index - PFLASH_PHANTOM_OFFSET) >> 13);
            u32Temp = ((uint32)1UL << u32Temp);
#if((FLASH_FC7300F8MDT == STD_ON) || (FLASH_FC7300F4MDD_T1B == STD_ON) || (FLASH_FC7300F4MDS_T1B == STD_ON) || (FLASH_FC7240F2MDS == STD_ON))
            bLock ? (FMC0->FB_FPELCK[u32Index] |= u32Temp) : ((FMC0->FB_FPELCK[u32Index] &= ~u32Temp));
#elif(FLASH_FC7300F8MDQ == STD_ON)
            if (u32Index <= 5)
            {
            	bLock ? (FMC0->FB_FPELCK[u32Index] |= u32Temp) : ((FMC0->FB_FPELCK[u32Index] &= ~u32Temp));
            }
            else if (u32Index == 6)
            {
            	bLock ? (FMC0->FB_FPELCK6 |= u32Temp) : ((FMC0->FB_FPELCK6 &= ~u32Temp));
            }
            else if (u32Index == 7)
            {
            	bLock ? (FMC0->FB_FPELCK7 |= u32Temp) : ((FMC0->FB_FPELCK7 &= ~u32Temp));
            }
            else
            {}
#elif((FLASH_FC7300F4MDD_T1C == STD_ON) || (FLASH_FC7300F4MDS_T1C == STD_ON))
            if (u32Index < 2)
            {
            	bLock ? (FMC0->FB_FPELCK[u32Index] |= u32Temp) : ((FMC0->FB_FPELCK[u32Index] &= ~u32Temp));
            }
            else
            {
            	bLock ? (FMC0->FB_FPELCK[u32Index + 2] |= u32Temp) : ((FMC0->FB_FPELCK[u32Index + 2] &= ~u32Temp));
            }
#endif

        }
    }
    else if ((u32Address >= DFLASH_ADDR_START) && (u32Address <= DFLASH_ADDR_END))
    {
#if((FLASH_FC7300F8MDT == STD_ON) || (FLASH_FC7300F4MDD_T1B == STD_ON) || (FLASH_FC7300F4MDS_T1B == STD_ON) || (FLASH_FC7240F2MDS == STD_ON))
        u32Temp = (1UL << ((u32Address - DFLASH_ADDR_START) >> 13));
        bLock ? (FMC0->FB_FPELCK[FLASH_DATA_BLOCK_SELECT0] |= u32Temp) : ((FMC0->FB_FPELCK[FLASH_DATA_BLOCK_SELECT0] &= ~u32Temp));
#elif(FLASH_FC7300F8MDQ == STD_ON)
        u32Index = (u32Address - DFLASH_ADDR_START) / DFLASH_BANK_SIZE;
        u32Length = ((u32Address - DFLASH_ADDR_START) % DFLASH_BANK_SIZE);
        u32Temp = ((uint32)1UL << ((u32Address - DFLASH_ADDR_START - DFLASH_BANK_SIZE * u32Index) >> 13));
        if (u32Index == 0)
        {
        	bLock ? (FMC0->FB_FPELCK8 |= u32Temp) : ((FMC0->FB_FPELCK8 &= ~u32Temp));
        }
        else if (u32Index == 1)
        {
        	bLock ? (FMC0->FB_FPELCK9 |= u32Temp) : ((FMC0->FB_FPELCK9 &= ~u32Temp));
        }
        else if (u32Index == 2)
        {
        	bLock ? (FMC0->FB_FPELCK10 |= u32Temp) : ((FMC0->FB_FPELCK10 &= ~u32Temp));
        }
        else
        {}
#elif((FLASH_FC7300F4MDD_T1C == STD_ON) || (FLASH_FC7300F4MDS_T1C == STD_ON))
        u32Index = (u32Address - DFLASH_ADDR_START) / DFLASH_BANK_SIZE;
        u32Length = ((u32Address - DFLASH_ADDR_START) % DFLASH_BANK_SIZE);
        u32Temp = ((uint32)1UL << ((u32Address - DFLASH_ADDR_START - DFLASH_BANK_SIZE * u32Index) >> 13));
        if (u32Index == 0)
        {
        	bLock ? (FMC0->FB_FPELCK8 |= u32Temp) : ((FMC0->FB_FPELCK8 &= ~u32Temp));
        }
        else if (u32Index == 1)
        {
        	bLock ? (FMC0->FB_FPELCK9 |= u32Temp) : ((FMC0->FB_FPELCK9 &= ~u32Temp));
        }
        else
        {}
#endif

    }
    else
    {
        tRetVal = FLASH_ERROR_INVALID_ADDR;
    }
    return tRetVal;
}

/**
 * @brief Flash Driver Function for lock/unlock nvr sector
 *
 * @param u32Address sector address
 * @param bLock 0U-unlock, 1U-lock
 * @return       none
 */
FLASH_StatusType NVRDRIVER_LockSector(uint32_t u32Address, FLASH_LOCK_TYPE bLock)
{
    FLASH_StatusType tRetVal;
    tRetVal = FLASH_ERROR_OK;
#if((FLASH_FC7240F2MDS == STD_ON))
    if(((u32Address >= NVR0_FLASH_ADDR_START) && (u32Address <= NVR0_FLASH_ADDR_END)) || 
        ((u32Address >= NVR1_FLASH_ADDR_START) && (u32Address <= NVR1_FLASH_ADDR_END)) || 
        ((u32Address >= NVR2_FLASH_ADDR_START) && (u32Address <= NVR2_FLASH_ADDR_END)))
#elif((FLASH_FC7300F4MDD_T1C == STD_ON) || (FLASH_FC7300F4MDS_T1C == STD_ON))
	if(((u32Address >= NVR0_FLASH_ADDR_START) && (u32Address <= NVR0_FLASH_ADDR_END)) ||
		((u32Address >= NVR2_FLASH_ADDR_START) && (u32Address <= NVR2_FLASH_ADDR_END)))
#elif((FLASH_FC7300F8MDT == STD_ON) || (FLASH_FC7300F4MDD_T1B == STD_ON) || (FLASH_FC7300F4MDS_T1B == STD_ON) || (FLASH_FC7300F8MDQ == STD_ON))
    if((u32Address >= NVR_FLASH_ADDR_START) && (u32Address <= NVR_FLASH_ADDR_END))
#endif
    {
        if (bLock == FLASH_LOCK)
        {
            FMC0->FN_FPELCK = 0x01;
        }
        else
        {
            FMC0->FN_FPELCK = 0x00;
        }
    }
    else
    {
        tRetVal = FLASH_ERROR_INVALID_ADDR;
    }
    return tRetVal;
}

/**
 * @brief Initial Flash api address
 *
 * @return       none
 */
void FLASHDRIVER_Init(void)
{

}

/**
 * @brief Flash Driver Function for lock/unlock sector
 *
 * @param pFlashParam flash driver lock/unlock parameter
 * @return ErrorType
 */
FLASH_StatusType FLASHDRIVER_Lock(FLASH_Lock_ParamType *pUnlockParam)
{
    uint32_t u32Addr, u32Length, u32StartAddr;
    FLASH_StatusType tRetVal;
    tRetVal = FLASH_ERROR_OK;
    u32Addr = pUnlockParam->u32Address;
    u32Length = pUnlockParam->u32Length;
    if(PFlash == pUnlockParam->bFlash)
    {
        if((u32Addr >= PFLASH_ADDR_START) && ((u32Addr + u32Length) <= (PFLASH_ADDR_END + 1)))
        {
            u32StartAddr = (u32Addr &~ (PFLASH_ERASE_SECTOR_SIZE - 1));
            for(uint32_t u32Temp = u32StartAddr ; u32Temp < (u32Addr + u32Length); u32Temp += PFLASH_ERASE_SECTOR_SIZE)
            {
                tRetVal = FLASHDRIVER_LockSector(u32Temp, pUnlockParam->bLock);
            }
        }
        else
        {
            tRetVal = FLASH_ERROR_INVALID_ADDR;
        }
    }
    else if(DFlash == pUnlockParam->bFlash)
    {
        if((u32Addr >= DFLASH_ADDR_START) && ((u32Addr + u32Length) <= (DFLASH_ADDR_END + 1)))
        {
            u32StartAddr = (u32Addr &~ (DFLASH_ERASE_SECTOR_SIZE - 1));
            for(uint32_t u32Temp = u32StartAddr ; u32Temp < (u32Addr + u32Length); u32Temp += DFLASH_ERASE_SECTOR_SIZE)
            {
                tRetVal = FLASHDRIVER_LockSector(u32Temp, pUnlockParam->bLock);
            }
        }
        else
        {
            tRetVal = FLASH_ERROR_INVALID_ADDR;
        }
    }
    else
    {
        tRetVal = FLASH_ERROR_INVALID_PARAM;
    }
    return tRetVal;
}

#if((FLASH_FC7300F8MDQ == STD_ON) || (FLASH_FC7300F4MDD_T1C == STD_ON) || (FLASH_FC7300F4MDS_T1C == STD_ON))
/**
 * @brief Flash Driver Function for DMA Write
 *
 * @param pFlashHandle the Flash instance to use
 * @param u32DMACount flash DMA count
 * @return ErrorType
 */
FLASH_StatusType FLASHDRIVER_DMAWrite(FLASH_HandleType *pFlashHandle, uint32_t u32DMACount)
{
	FLASH_ROM_API_ENTRY_T *const s_pFlashDriver_FuncHeader = s_pFlashDriver[pFlashHandle->eInstance];
    FLASH_StatusType tRetVal;
    uint32_t u32Temp;
    tRetVal = FLASH_ERROR_OK;
#if(FLASH_FC7300F4MDS_T1C == STD_ON)
    FLASH_API_DMA_TRIG_CFG_TYPE dma_trig_cfg = {.dma_addr_cnt = u32DMACount, .dma_trig_en = FLASH_REG_BIT_CFG_ENABLE};
#endif
    FLASH_API_DMA_CFG_TYPE dma_cfg = {.dma_allow = 0x01,.dma_en = 0x01, .dma_ie = 0x01};
    FLASH_API_WDG_CFG_TYPE wdg_cfg = {.wen = 0x0};
    pFlashHandle->tStatus.eFlsStatus = FLS_DMA_WRITING;
    (s_pFlashDriver_FuncHeader)->FLASH_DRV_DMA_CFG_FUNC(&dma_cfg);
    (s_pFlashDriver_FuncHeader)->FLASH_DRV_Wdog_Configure(&wdg_cfg);
#if(FLASH_FC7300F4MDS_T1C == STD_ON)
    u32Temp = (s_pFlashDriver_FuncHeader)->FLASH_DRV_DMA_TRIG_FUNC(&dma_trig_cfg);
#elif((FLASH_FC7300F8MDQ == STD_ON) || (FLASH_FC7300F4MDD_T1C == STD_ON))
    u32Temp = (s_pFlashDriver_FuncHeader)->FLASH_DRV_DMA_TRIG_FUNC(u32DMACount);
#endif
    tRetVal = ((u32Temp == STATUS_SUCCESS) ? FLASH_ERROR_OK : FLASH_ERROR_FAILED);
    return tRetVal;
}


/**
 * @brief Flash Driver Function for DMA Abort
 *
 * @param pFlashHandle the Flash instance to use
 * @return complete count
 */
uint32_t FLASHDRIVER_DMAAbort(FLASH_HandleType *pFlashHandle)
{
	FLASH_ROM_API_ENTRY_T *const s_pFlashDriver_FuncHeader = s_pFlashDriver[pFlashHandle->eInstance];
    uint32_t tRetVal;

	uint32_t u32TryCount = 0;
	while((((*(uint32*)0x40020004) & 0x00008000) != 0x00008000) && (u32TryCount < 10000))
	{
		u32TryCount++;
	}
	u32TryCount = 0;
	while((((*(uint32*)0x40020004) & 0x00008000) != 0x00000000) && (u32TryCount < 10000))
	{
		u32TryCount++;
	}
    (s_pFlashDriver_FuncHeader)->FLASH_DRV_DMA_ADDR_CNT_READ_FUNC(&tRetVal);
	*(uint32*)0x40020078 &= (~0x00001FFF);
	*(uint32*)0x40020078 |= tRetVal;

    return tRetVal;
}
#endif

/**
 * @brief Flash Driver Function for Erasing
 *
 * @param pFlashHandle the Flash instance to use
 * @param pFlashParam flash driver erase parameter
 * @return ErrorType
 */
FLASH_StatusType FLASHDRIVER_SyncErase(FLASH_HandleType *pFlashHandle, FLASH_DRIVER_ParamType *pFlashParam)
{
#if FLASH_DEV_ERROR_REPORT == STD_ON
    if (NULL == pFlashParam)
    {
        FLASH_ReportDevError(FLASH_SYNC_ERASE_ID, FLASH_E_PARAM_POINTER);
    }
#endif
    FLASH_ROM_API_ENTRY_T *const s_pFlashDriver_FuncHeader = s_pFlashDriver[pFlashHandle->eInstance];
    uint32_t u32Addr, u32Length;
    uint32_t u32TryCount;
    FLASH_API_ERASESECTOR_TYPE tFlash_api_cfg = {0};
    FLASH_StatusType tRetVal;
    uint32_t u32Temp;
    tRetVal = FLASH_ERROR_OK;
    uint8_t u8IsEnInterupt;

    /* FLASH_DRV_WDG_CFG_T tFlash_wdg_cfg; */
    u32Addr = pFlashParam->u32Address;
    u32Length = pFlashParam->u32Length;
    pFlashHandle->tStatus.u32Address = pFlashParam->u32Address;
    pFlashHandle->tStatus.u32CurrentAddress = pFlashParam->u32Address;
    pFlashHandle->tStatus.u32Length = pFlashParam->u32Length;
    pFlashHandle->tStatus.pDate = pFlashParam->pData;
    pFlashHandle->tStatus.u32ErrorAdress = 0x0U;
    if(pFlashHandle->tStatus.u32Address <= PFLASH_ADDR_END)
    {
        pFlashHandle->tStatus.u32EraseSectorSize = PFLASH_ERASE_SECTOR_SIZE;
    }
    else
    {
        pFlashHandle->tStatus.u32EraseSectorSize = DFLASH_ERASE_SECTOR_SIZE;
    }
    tRetVal = FLASH_ERROR_OK;
    tRetVal = FLASHDRIVER_EraseCheck(pFlashParam);

    if (tRetVal == FLASH_ERROR_OK)
    {
        /* flash watchdog config */
        /* tFlash_wdg_cfg.time = FLASH_WDG_TIMEOUT_SELECT3; */
        /* tFlash_wdg_cfg.wen = FLASH_WDG_ENABLE; */
        /* tFlash_wdg_cfg.wint_en = FLASH_WDG_INT_DISABLE; */
        /* (s_pFlashDriver_FuncHeader)->FLASH_DRV_Wdog_Configure(&tFlash_wdg_cfg); */
        (s_pFlashDriver_FuncHeader)->FLASH_DRV_ENABLE_HOLD_CFG(1);
        /* loop erase */
        for (pFlashHandle->tStatus.u32CurrentAddress = u32Addr; pFlashHandle->tStatus.u32CurrentAddress < u32Addr + u32Length;
             pFlashHandle->tStatus.u32CurrentAddress += pFlashHandle->tStatus.u32EraseSectorSize)
        {
            if(NULL != pFlashHandle->tSettings.pUnlockCallback)
            {
                pFlashHandle->tSettings.pUnlockCallback(pFlashHandle->tStatus.u32CurrentAddress);
            }
            FLASHDRIVER_GetFlashConfig(pFlashHandle->tStatus.u32CurrentAddress, &tFlash_api_cfg);
            /* start erase */
            /* Disable Inetrrupt*/
            u8IsEnInterupt = FLASHDRIVER_MsrIsOn();//0 disable ,1 enable
            if(u8IsEnInterupt == 1)
            {
                __asm(" cpsid i");
            }
            if (FLASH_HARDWARE_STATUS_IDLE == (((*(volatile uint32 *)FLASH_HARDWARE_STATUS_ADDR) & FLASH_HARDWARE_STATUS_MASK) >> 16))
            {
#if((FLASH_FC7300F8MDT == STD_ON) || (FLASH_FC7300F4MDD_T1B == STD_ON) || (FLASH_FC7300F4MDS_T1B == STD_ON) || (FLASH_FC7240F2MDS == STD_ON))
                u32Temp = (s_pFlashDriver_FuncHeader)->FLASH_DRV_EraseSector(&tFlash_api_cfg, FLASH_API_DISABLE, FLASH_API_SIZE);
#elif((FLASH_FC7300F8MDQ == STD_ON) || (FLASH_FC7300F4MDD_T1C == STD_ON) || (FLASH_FC7300F4MDS_T1C == STD_ON))
                u32Temp = (s_pFlashDriver_FuncHeader)->FLASH_DRV_EraseSector(&tFlash_api_cfg);
#endif
                tRetVal = (u32Temp == STATUS_SUCCESS) ? FLASH_ERROR_OK : FLASH_ERROR_FAILED;
            }
            else
            {
                tRetVal = FLASH_ERROR_FAILED;
            }
            /* Recover Inetrrupt*/
            if(u8IsEnInterupt == 1)
            {
                __asm(" cpsie i");
            }

            /* check erase operation valid */
            if(tRetVal == FLASH_ERROR_OK)
            {
                /* check erasing still in progress */
                tRetVal = FLASH_ERROR_FAILED;
                u32TryCount = 0;
                while ((tRetVal != FLASH_ERROR_OK) && (u32TryCount++ < 1000000))
                {
                    u32Temp = (s_pFlashDriver_FuncHeader)->FLASH_DRV_HV_Status_Check();
                    /* check if finished */
                    if (u32Temp != STATUS_HVOP)
                    {
                        u32Temp = (s_pFlashDriver_FuncHeader)->FLASH_DRV_EraseSector_Clear();
                        tRetVal = (u32Temp == STATUS_SUCCESS) ? FLASH_ERROR_OK : FLASH_ERROR_FAILED;
                        break;
                    }
                }
            }
            if (tRetVal != FLASH_ERROR_OK)
            {
                /* erasing failed, exit */
                pFlashHandle->tStatus.u32ErrorAdress = pFlashHandle->tStatus.u32CurrentAddress;
                FLASHDRIVER_LockSector(pFlashHandle->tStatus.u32CurrentAddress, FLASH_LOCK);
                break;
            }
            FLASHDRIVER_LockSector(pFlashHandle->tStatus.u32CurrentAddress, FLASH_LOCK);
        }
    }
#if FLASH_DEV_ERROR_REPORT == STD_ON
    else
    {
        FLASH_ReportDevError(FLASH_SYNC_ERASE_ID, FLASH_E_PARAM_POINTER);
    }
#endif
    return tRetVal;
}

/**
 * @brief Flash Driver Function for Writing
 *
 * @param pFlashHandle the Flash instance to use
 * @param pFlashParam flash driver write parameter
 * @return ErrorType
 */
FLASH_StatusType FLASHDRIVER_SyncWrite(FLASH_HandleType *pFlashHandle, FLASH_DRIVER_ParamType *pFlashParam)
{
#if FLASH_DEV_ERROR_REPORT == STD_ON
    if (NULL == pFlashParam)
    {
        FLASH_ReportDevError(FLASH_SYNC_WRITE_ID, FLASH_E_PARAM_POINTER);
    }
#endif
    FLASH_ROM_API_ENTRY_T *const s_pFlashDriver_FuncHeader = s_pFlashDriver[pFlashHandle->eInstance];
    uint32_t u32Addr, u32Length, u32DataAddr, u32AlignLen, u32TempLen;
    /* uint8_t *pTempBuf; */
    uint32_t u32AlignOffset, u32Index, u32Count;
    uint32_t u32TryCount;
    uint8_t u8IsEnInterupt;

    /* FLASH_DRV_WDG_CFG_T tFlash_wdg_cfg; */
    FLASH_API_PRGM_CFG_TYPE tFlash_api_cfg = {0};
    FLASH_StatusType tRetVal;
    uint32_t u32Temp;
    tRetVal = FLASH_ERROR_OK;
    u32Addr = pFlashParam->u32Address;
    u32Length = pFlashParam->u32Length;
    pFlashHandle->tStatus.u32Address = pFlashParam->u32Address;
    pFlashHandle->tStatus.u32CurrentAddress = pFlashParam->u32Address;
    pFlashHandle->tStatus.u32Length = pFlashParam->u32Length;
    pFlashHandle->tStatus.pDate = pFlashParam->pData;
    pFlashHandle->tStatus.u32ErrorAdress = 0x0U;
    tRetVal = FLASHDRIVER_WriteCheck(pFlashParam);
    if (tRetVal == FLASH_ERROR_OK)
    {
        /* flash watchdog config */
        /* tFlash_wdg_cfg.time = 0x03UL; */
        /* tFlash_wdg_cfg.wen = 0x01UL; */
        /* tFlash_wdg_cfg.wint_en = FLASH_WDG_INT_DISABLE; */
        /* (s_pFlashDriver_FuncHeader)->FLASH_DRV_Wdog_Configure(&tFlash_wdg_cfg); */
        (s_pFlashDriver_FuncHeader)->FLASH_DRV_ENABLE_HOLD_CFG(1);

        /* align address, write must align to FLASH_PROGRAM_PAGE_MAX_SIZE */
        u32AlignOffset = u32Addr & (FLASH_PROGRAM_PAGE_MAX_SIZE - 1U);
        u32AlignLen = u32Length + u32AlignOffset;
        u32Count = ((u32AlignLen + (FLASH_PROGRAM_PAGE_MAX_SIZE - 1U)) & ~(FLASH_PROGRAM_PAGE_MAX_SIZE - 1U)) / FLASH_PROGRAM_PAGE_MAX_SIZE;
        u32DataAddr = (uint32_t)pFlashHandle->tStatus.pDate;
        u32TempLen = u32AlignLen;

        for (u32Index = 0U; u32Index < u32Count; u32Index++)
        {
            /* real write length in this cycle */
            u32TempLen = u32Length + u32AlignOffset;
            u32TempLen = u32TempLen >= FLASH_PROGRAM_PAGE_MAX_SIZE ? FLASH_PROGRAM_PAGE_MAX_SIZE : u32TempLen;
            u32TempLen -= u32AlignOffset;

            pFlashHandle->tStatus.u32CurrentAddress = u32Addr;
            pFlashHandle->tStatus.u32ProgramSize = u32TempLen;

            if(NULL != pFlashHandle->tSettings.pUnlockCallback)
            {
                pFlashHandle->tSettings.pUnlockCallback(pFlashHandle->tStatus.u32CurrentAddress);
            }

            tFlash_api_cfg.dest = pFlashHandle->tStatus.u32CurrentAddress;
            tFlash_api_cfg.size = pFlashHandle->tStatus.u32ProgramSize / 4; /* one data is 4 bytes */
            tFlash_api_cfg.pData = (uint32_t *)u32DataAddr;
            tFlash_api_cfg.wdg_tune = WDG_TUNE_DISABLE;
            tFlash_api_cfg.pgff = FLASH_REG_BIT_CFG_DISABLE;

            /* next address and length */
            u32Addr += u32TempLen;
            u32DataAddr += u32TempLen;
            u32Length -= u32TempLen;

            u32AlignOffset = 0U;

            /* start write */
            /* Disable Inetrrupt*/
            u8IsEnInterupt = FLASHDRIVER_MsrIsOn();//0 disable ,1 enable
            if(u8IsEnInterupt == 1)
            {
                __asm(" cpsid i");
            }
            if (FLASH_HARDWARE_STATUS_IDLE == (((*(volatile uint32 *)FLASH_HARDWARE_STATUS_ADDR) & FLASH_HARDWARE_STATUS_MASK) >> 16))
            {
#if((FLASH_FC7300F8MDT == STD_ON) || (FLASH_FC7300F4MDD_T1B == STD_ON) || (FLASH_FC7300F4MDS_T1B == STD_ON) || (FLASH_FC7240F2MDS == STD_ON))
                u32Temp = (s_pFlashDriver_FuncHeader)->FLASH_DRV_Program(&tFlash_api_cfg, FLASH_API_DISABLE, FLASH_API_SIZE);
#elif((FLASH_FC7300F8MDQ == STD_ON) || (FLASH_FC7300F4MDD_T1C == STD_ON) || (FLASH_FC7300F4MDS_T1C == STD_ON))
                u32Temp = (s_pFlashDriver_FuncHeader)->FLASH_DRV_Program(&tFlash_api_cfg);
#endif
                tRetVal = (u32Temp == STATUS_SUCCESS) ? FLASH_ERROR_OK : FLASH_ERROR_FAILED;
            }
            else
            {
                tRetVal = FLASH_ERROR_FAILED;
            }
            /* Recover Inetrrupt*/
            if(u8IsEnInterupt == 1)
            {
                __asm(" cpsie i");
            }
            /* check erase operation valid */
            if(tRetVal == FLASH_ERROR_OK)
            {
                /* check write still in progress */
                tRetVal = FLASH_ERROR_FAILED;
                u32TryCount = 0;
                while ((tRetVal != FLASH_ERROR_OK) && (u32TryCount++ < 10000))
                {
                    u32Temp = (s_pFlashDriver_FuncHeader)->FLASH_DRV_HV_Status_Check();
                    /* check if finished */
                    if (u32Temp != STATUS_HVOP)
                    {
                        u32Temp = (s_pFlashDriver_FuncHeader)->FLASH_DRV_Program_Clear();
                        tRetVal = (u32Temp == STATUS_SUCCESS) ? FLASH_ERROR_OK : FLASH_ERROR_FAILED;
                        break;
                    }
                }
            }
            if (tRetVal != FLASH_ERROR_OK)
            {
                /* erasing timeout, exit */
                pFlashHandle->tStatus.u32ErrorAdress = pFlashHandle->tStatus.u32CurrentAddress;
                FLASHDRIVER_LockSector(pFlashHandle->tStatus.u32CurrentAddress, FLASH_LOCK);
                break;
            }
            FLASHDRIVER_LockSector(pFlashHandle->tStatus.u32CurrentAddress, FLASH_LOCK);
        }
        if(FLASH_ECC_ERROR_NONE != FLASHDRIVER_EccCheck(pFlashHandle))
        {
            tRetVal = FLASH_ERROR_FAILED;
        }
    }
#if FLASH_DEV_ERROR_REPORT == STD_ON
    else
    {
        FLASH_ReportDevError(FLASH_SYNC_WRITE_ID, FLASH_E_PARAM_POINTER);
    }
#endif
    return tRetVal;
}

/**
 * @brief NVR driver erase function
 *    warning:Need to configure the NVR correctly, otherwise there is a risk that the chip will become bricked.
 *    warning:Need to configure the NVR correctly, otherwise there is a risk that the chip will become bricked.
 *    warning:Need to configure the NVR correctly, otherwise there is a risk that the chip will become bricked.
 *   .=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-.       *
 *    |                     ______                     |      *
 *    |                  .-"      "-.                  |      *
 *    |                 /            \                 |      *
 *    |     _          |              |          _     |      *
 *    |    ( \         |,  .-.  .-.  ,|         / )    |      *
 *    |     > "=._     | )(__/  \__)( |     _.=" <     |      *
 *    |    (_/"=._"=._ |/     /\     \| _.="_.="\_)    |      *
 *    |           "=._"(_     ^^     _)"_.="           |      *
 *    |               "=\__|IIIIII|__/="               |      *
 *    |              _.="| \IIIIII/ |"=._              |      *
 *    |    _     _.="_.="\          /"=._"=._     _    |      *
 *    |   ( \_.="_.="     `--------`     "=._"=._/ )   |      *
 *    |    > _.="                            "=._ <    |      *
 *    |   (_/                                    \_)   |      *
 *    |                                                |      *
 *    '-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-='      *
 * @param pFlashHandle the Flash instance to use
 * @param pFlashParam contains flash erase function parameter, address is align to sector, and length is align to sector
 * @return ErrorType
 */
FLASH_StatusType NVRDRIVER_SyncErase(FLASH_HandleType *pFlashHandle, FLASH_DRIVER_ParamType *pFlashParam)
{
#if FLASH_DEV_ERROR_REPORT == STD_ON
    if (NULL == pFlashParam)
    {
        FLASH_ReportDevError(NVR_SYNC_ERASE_ID, FLASH_E_PARAM_POINTER);
    }
#endif
    FLASH_ROM_API_ENTRY_T *const s_pFlashDriver_FuncHeader = s_pFlashDriver[pFlashHandle->eInstance];
    uint32_t u32Addr, u32Length;
    uint32_t u32TryCount;
    FLASH_StatusType tRetVal;
    uint32_t u32Temp;
    tRetVal = FLASH_ERROR_OK;
    uint8_t u8IsEnInterupt;

    /* FLASH_DRV_WDG_CFG_T tFlash_wdg_cfg; */
    u32Addr = pFlashParam->u32Address;
    u32Length = pFlashParam->u32Length;
    pFlashHandle->tStatus.u32Address = pFlashParam->u32Address;
    pFlashHandle->tStatus.u32CurrentAddress = pFlashParam->u32Address;
    pFlashHandle->tStatus.u32Length = pFlashParam->u32Length;
    pFlashHandle->tStatus.pDate = pFlashParam->pData;
    pFlashHandle->tStatus.u32ErrorAdress = 0x0U;
    pFlashHandle->tStatus.u32EraseSectorSize = NVR_ERASE_SECTOR_SIZE;
    tRetVal = NVRDRIVER_EraseCheck(pFlashParam);

    if (tRetVal == FLASH_ERROR_OK)
    {
        (s_pFlashDriver_FuncHeader)->FLASH_DRV_ENABLE_HOLD_CFG(1);

        /* loop erase */
        for (pFlashHandle->tStatus.u32CurrentAddress = u32Addr; pFlashHandle->tStatus.u32CurrentAddress < u32Addr + u32Length;
             pFlashHandle->tStatus.u32CurrentAddress += NVR_ERASE_SECTOR_SIZE)
        {
            if(NULL != pFlashHandle->tSettings.pUnlockCallback)
            {
                pFlashHandle->tSettings.pUnlockCallback(pFlashHandle->tStatus.u32CurrentAddress);
            }
            /* start erase */
            /* Disable Inetrrupt*/
            u8IsEnInterupt = FLASHDRIVER_MsrIsOn();//0 disable ,1 enable
            if(u8IsEnInterupt == 1)
            {
                __asm(" cpsid i");
            }
            if (FLASH_HARDWARE_STATUS_IDLE == (((*(volatile uint32 *)FLASH_HARDWARE_STATUS_ADDR) & FLASH_HARDWARE_STATUS_MASK) >> 16))
            {
#if (FLASH_FC7240F2MDS == STD_ON)
                u32Temp = (s_pFlashDriver_FuncHeader)->FLASH_DRV_EraseNvr(pFlashHandle->tStatus.u32CurrentAddress, FLASH_API_DISABLE);
#elif((FLASH_FC7300F8MDT == STD_ON) || (FLASH_FC7300F4MDD_T1B == STD_ON) || (FLASH_FC7300F4MDS_T1B == STD_ON))
                u32Temp = (s_pFlashDriver_FuncHeader)->FLASH_DRV_EraseNvr(FLASH_API_DISABLE);
#elif((FLASH_FC7300F8MDQ == STD_ON) || (FLASH_FC7300F4MDD_T1C == STD_ON) || (FLASH_FC7300F4MDS_T1C == STD_ON))
                FLASH_API_ERASENVR_TYPE tFlash_api_cfg = {0};
                tFlash_api_cfg.addr = pFlashHandle->tStatus.u32CurrentAddress;
                u32Temp = (s_pFlashDriver_FuncHeader)->FLASH_DRV_EraseNvr(&tFlash_api_cfg);
#endif
                tRetVal = ((u32Temp == STATUS_SUCCESS) ? FLASH_ERROR_OK : FLASH_ERROR_FAILED);
                /* check erase operation valid */
            }
            else
            {
                tRetVal = FLASH_ERROR_FAILED;
            }
            /* Recover Inetrrupt*/
            if(u8IsEnInterupt == 1)
            {
                __asm(" cpsie i");
            }

            /* check erase operation valid */
            if(tRetVal == FLASH_ERROR_OK)
            {
                /* check erasing still in progress */
                tRetVal = FLASH_ERROR_FAILED;
                u32TryCount = 0;
                while ((tRetVal != FLASH_ERROR_OK) && (u32TryCount++ < 1000000))
                {
                    u32Temp = (s_pFlashDriver_FuncHeader)->FLASH_DRV_HV_Status_Check();
                    /* check if finished */
                    if (u32Temp != STATUS_HVOP)
                    {
                        u32Temp = (s_pFlashDriver_FuncHeader)->FLASH_DRV_EraseNvr_Clear();
                        tRetVal = (u32Temp == STATUS_SUCCESS) ? FLASH_ERROR_OK : FLASH_ERROR_FAILED;
                        break;
                    }
                }
            }
            if (tRetVal != FLASH_ERROR_OK)
            {
                /* erase operation failed, exit */
                pFlashHandle->tStatus.u32ErrorAdress = pFlashHandle->tStatus.u32CurrentAddress;
                NVRDRIVER_LockSector(pFlashHandle->tStatus.u32CurrentAddress, FLASH_LOCK);
                break;
            }
            NVRDRIVER_LockSector(pFlashHandle->tStatus.u32CurrentAddress, FLASH_LOCK);
        }
    }
#if FLASH_DEV_ERROR_REPORT == STD_ON
    else
    {
        FLASH_ReportDevError(NVR_SYNC_ERASE_ID, FLASH_E_PARAM_POINTER);
    }
#endif
    return tRetVal;
}

/**
 * @brief NVR driver write function
 *    warning:Need to configure the NVR correctly, otherwise there is a risk that the chip will become bricked.
 *    warning:Need to configure the NVR correctly, otherwise there is a risk that the chip will become bricked.
 *    warning:Need to configure the NVR correctly, otherwise there is a risk that the chip will become bricked.
 *   .=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-.       *
 *    |                     ______                     |      *
 *    |                  .-"      "-.                  |      *
 *    |                 /            \                 |      *
 *    |     _          |              |          _     |      *
 *    |    ( \         |,  .-.  .-.  ,|         / )    |      *
 *    |     > "=._     | )(__/  \__)( |     _.=" <     |      *
 *    |    (_/"=._"=._ |/     /\     \| _.="_.="\_)    |      *
 *    |           "=._"(_     ^^     _)"_.="           |      *
 *    |               "=\__|IIIIII|__/="               |      *
 *    |              _.="| \IIIIII/ |"=._              |      *
 *    |    _     _.="_.="\          /"=._"=._     _    |      *
 *    |   ( \_.="_.="     `--------`     "=._"=._/ )   |      *
 *    |    > _.="                            "=._ <    |      *
 *    |   (_/                                    \_)   |      *
 *    |                                                |      *
 *    '-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-='      *
 * @param pFlashHandle the Flash instance to use
 * @param pFlashParam contains flash write function parameter, address is align to page, and length is align to page
 * @return ErrorType
 */
FLASH_StatusType NVRDRIVER_SyncWrite(FLASH_HandleType *pFlashHandle, FLASH_DRIVER_ParamType *pFlashParam)
{
#if FLASH_DEV_ERROR_REPORT == STD_ON
    if (NULL == pFlashParam)
    {
        FLASH_ReportDevError(NVR_SYNC_WRITE_ID, FLASH_E_PARAM_POINTER);
    }
#endif
    FLASH_ROM_API_ENTRY_T *const s_pFlashDriver_FuncHeader = s_pFlashDriver[pFlashHandle->eInstance];
    uint32_t u32Addr, u32Length, u32DataAddr, u32AlignLen, u32TempLen;
    /* uint8_t *pTempBuf; */
    uint32_t u32AlignOffset, u32Index, u32Count;
    uint32_t u32TryCount;
    uint32_t u32HardwareStatus;
    uint8_t u8IsEnInterupt;

    /* FLASH_DRV_WDG_CFG_T tFlash_wdg_cfg; */
    FLASH_API_PRGM_CFG_TYPE tFlash_api_cfg = {0};
    FLASH_StatusType tRetVal;
    uint32_t u32Temp;
    u32Addr = pFlashParam->u32Address;
    u32Length = pFlashParam->u32Length;
    pFlashHandle->tStatus.u32Address = pFlashParam->u32Address;
    pFlashHandle->tStatus.u32CurrentAddress = pFlashParam->u32Address;
    pFlashHandle->tStatus.u32Length = pFlashParam->u32Length;
    pFlashHandle->tStatus.pDate = pFlashParam->pData;
    pFlashHandle->tStatus.u32ErrorAdress = 0x0U;
    pFlashParam->u32ErrorAddress = 0x0U;
    tRetVal = NVRDRIVER_WriteCheck(pFlashParam);
    u32HardwareStatus = ((*(volatile uint32 *)FLASH_HARDWARE_STATUS_ADDR) & FLASH_HARDWARE_STATUS_MASK) >> 16;
    if ((tRetVal == FLASH_ERROR_OK) && (u32HardwareStatus == FLASH_HARDWARE_STATUS_IDLE))
    {
        (s_pFlashDriver_FuncHeader)->FLASH_DRV_ENABLE_HOLD_CFG(1);
        /* align address, write must align to FLASH_PROGRAM_PAGE_MAX_SIZE */
        u32AlignOffset = u32Addr & (FLASH_PROGRAM_PAGE_MAX_SIZE - 1U);
        u32AlignLen = u32Length + u32AlignOffset;
        u32Count = ((u32AlignLen + (FLASH_PROGRAM_PAGE_MAX_SIZE - 1U)) & ~(FLASH_PROGRAM_PAGE_MAX_SIZE - 1U)) / FLASH_PROGRAM_PAGE_MAX_SIZE;
        u32DataAddr = (uint32_t)pFlashHandle->tStatus.pDate;
        u32TempLen = u32AlignLen;

        for (u32Index = 0U; u32Index < u32Count; u32Index++)
        {
            /* real write length in this cycle */
            u32TempLen = u32Length + u32AlignOffset;
            u32TempLen = u32TempLen >= FLASH_PROGRAM_PAGE_MAX_SIZE ? FLASH_PROGRAM_PAGE_MAX_SIZE : u32TempLen;
            u32TempLen -= u32AlignOffset;

            pFlashHandle->tStatus.u32CurrentAddress = u32Addr;
            pFlashHandle->tStatus.u32ProgramSize = u32TempLen;

            if(NULL != pFlashHandle->tSettings.pUnlockCallback)
            {
                pFlashHandle->tSettings.pUnlockCallback(pFlashHandle->tStatus.u32CurrentAddress);
            }

            tFlash_api_cfg.dest = pFlashHandle->tStatus.u32CurrentAddress;
            tFlash_api_cfg.size = pFlashHandle->tStatus.u32ProgramSize / 4; /* one data is 4 bytes */
            tFlash_api_cfg.pData = (uint32_t *)u32DataAddr;
            tFlash_api_cfg.wdg_tune = WDG_TUNE_DISABLE;
            tFlash_api_cfg.pgff = FLASH_REG_BIT_CFG_DISABLE;

            /* next address and length */
            u32Addr += u32TempLen;
            u32DataAddr += u32TempLen;
            u32Length -= u32TempLen;
            u32AlignOffset = 0U;

            /* start write */
            /* Disable Inetrrupt*/
            u8IsEnInterupt = FLASHDRIVER_MsrIsOn();//0 disable ,1 enable
            if(u8IsEnInterupt == 1)
            {
                __asm(" cpsid i");
            }
            if (FLASH_HARDWARE_STATUS_IDLE == (((*(volatile uint32 *)FLASH_HARDWARE_STATUS_ADDR) & FLASH_HARDWARE_STATUS_MASK) >> 16))
            {
#if((FLASH_FC7300F8MDT == STD_ON) || (FLASH_FC7300F4MDD_T1B == STD_ON) || (FLASH_FC7300F4MDS_T1B == STD_ON) || (FLASH_FC7240F2MDS == STD_ON))
                u32Temp = (s_pFlashDriver_FuncHeader)->FLASH_DRV_Program_Nvr(&tFlash_api_cfg, FLASH_API_DISABLE);
#elif((FLASH_FC7300F8MDQ == STD_ON) || (FLASH_FC7300F4MDD_T1C == STD_ON) || (FLASH_FC7300F4MDS_T1C == STD_ON))
                u32Temp = (s_pFlashDriver_FuncHeader)->FLASH_DRV_Program_Nvr(&tFlash_api_cfg);
#endif
                tRetVal = ((u32Temp == STATUS_SUCCESS) ? FLASH_ERROR_OK : FLASH_ERROR_FAILED);
            }
            else
            {
                tRetVal = FLASH_ERROR_FAILED;
            }
            /* Recover Inetrrupt*/
            if(u8IsEnInterupt == 1)
            {
                __asm(" cpsie i");
            }

            /* check erase operation valid */
            if(tRetVal == FLASH_ERROR_OK)
            {
                /* check write still in progress */
                tRetVal = FLASH_ERROR_FAILED;
                u32TryCount = 0;
                while ((tRetVal != FLASH_ERROR_OK) && (u32TryCount++ < 10000))
                {
                    u32Temp = (s_pFlashDriver_FuncHeader)->FLASH_DRV_HV_Status_Check();
                    /* check if finished */
                    if (u32Temp != STATUS_HVOP)
                    {
                        u32Temp = (s_pFlashDriver_FuncHeader)->FLASH_DRV_Program_Nvr_Clear();
                        tRetVal = (u32Temp == STATUS_SUCCESS) ? FLASH_ERROR_OK : FLASH_ERROR_FAILED;
                        break;
                    }
                }
            }
            /* check erase operation valid */
            if (tRetVal != FLASH_ERROR_OK)
            {
                /* write operation failed, exit */
                pFlashHandle->tStatus.u32ErrorAdress = pFlashHandle->tStatus.u32CurrentAddress;
                NVRDRIVER_LockSector(pFlashHandle->tStatus.u32CurrentAddress, FLASH_LOCK);
                break;
            }
            NVRDRIVER_LockSector(pFlashHandle->tStatus.u32CurrentAddress, FLASH_LOCK);
        }
    }
#if FLASH_DEV_ERROR_REPORT == STD_ON
    else
    {
        FLASH_ReportDevError(NVR_SYNC_WRITE_ID, FLASH_E_PARAM_POINTER);
    }
#endif
    return tRetVal;
}


/**
* @brief        flash driver for erase
* 
* @param        pFlashHandle the Flash instance to use
* @param        pFlashParam flash driver erase parameter
* @return       ErrorType
*/
FLASH_StatusType FLASHDRIVER_AsyncErase(FLASH_HandleType *pFlashHandle, FLASH_DRIVER_ParamType *pFlashParam)
{
#if FLASH_DEV_ERROR_REPORT == STD_ON
    if (NULL == pFlashParam)
    {
        FLASH_ReportDevError(FLASH_ASYNC_ERASE_ID, FLASH_E_PARAM_POINTER);
    }
#endif
    FLASH_StatusType tRetVal;
    tRetVal = FLASH_ERROR_OK;

    /* FLASH_DRV_WDG_CFG_T tFlash_wdg_cfg; */
    tRetVal = FLASH_ERROR_OK;
    pFlashParam->u32ErrorAddress = 0x0U;
    tRetVal = FLASHDRIVER_EraseCheck(pFlashParam);

    if (tRetVal == FLASH_ERROR_OK)
    {
        pFlashHandle->tStatus.eFlsStatus = FLS_ASYNC_ERASE_PENDING;
        pFlashHandle->tStatus.u32Address = pFlashParam->u32Address;
        pFlashHandle->tStatus.u32Length = pFlashParam->u32Length;
        pFlashHandle->tStatus.u32CurrentAddress = pFlashParam->u32Address;
        if(pFlashHandle->tStatus.u32Address <= PFLASH_ADDR_END)
        {
            pFlashHandle->tStatus.u32EraseSectorSize = PFLASH_ERASE_SECTOR_SIZE;
        }
        else
        {
            pFlashHandle->tStatus.u32EraseSectorSize = DFLASH_ERASE_SECTOR_SIZE;
        }
    }
    else
    {
#if FLASH_DEV_ERROR_REPORT == STD_ON
        FLASH_ReportDevError(FLASH_ASYNC_ERASE_ID, FLASH_E_PARAM_POINTER);
#endif
        pFlashHandle->tStatus.eFlsStatus = FLS_PARA_ERROR;
    }
    return tRetVal;
}



/**
* @brief        flash driver write a fixed size
*
* @param        pFlashHandle the Flash instance to use
* @param        pFlashParam flash driver write parameter
* @return       ErrorType
*/
FLASH_StatusType FLASHDRIVER_AsyncWrite(FLASH_HandleType *pFlashHandle, FLASH_DRIVER_ParamType *pFlashParam)
{
#if FLASH_DEV_ERROR_REPORT == STD_ON
    if (NULL == pFlashParam)
    {
        FLASH_ReportDevError(FLASH_ASYNC_WRITE_ID, FLASH_E_PARAM_POINTER);
    }
#endif
    FLASH_StatusType tRetVal;
    tRetVal = FLASH_ERROR_OK;
    pFlashParam->u32ErrorAddress = 0x0U;
    tRetVal = FLASHDRIVER_WriteCheck(pFlashParam);
    if (tRetVal == FLASH_ERROR_OK)
    {
        pFlashHandle->tStatus.eFlsStatus = FLS_ASYNC_WRITE_PENDING;
        pFlashHandle->tStatus.u32Address = pFlashParam->u32Address;
        pFlashHandle->tStatus.u32Length = pFlashParam->u32Length;
        pFlashHandle->tStatus.u32CurrentAddress = pFlashParam->u32Address;
        pFlashHandle->tStatus.pDate = pFlashParam->pData;
    }
    else
    {
#if FLASH_DEV_ERROR_REPORT == STD_ON
        FLASH_ReportDevError(FLASH_ASYNC_ERASE_ID, FLASH_E_PARAM_POINTER);
#endif
        pFlashHandle->tStatus.eFlsStatus = FLS_PARA_ERROR;
    }
    return tRetVal;
}

/**
* @brief        flash driver check current status when erasing
*
* @param        pFlashHandle the Flash instance to use
* @return       Fls_Status_t return the erase status
*/
Fls_Status_t FLASHDRIVER_AsyncEraseMainFunction(FLASH_HandleType *pFlashHandle)
{
    FLASH_ROM_API_ENTRY_T *const s_pFlashDriver_FuncHeader = s_pFlashDriver[pFlashHandle->eInstance];
    Fls_Status_t tRetVal;
    FLASH_API_ERASESECTOR_TYPE tFlash_api_cfg = {0};
    uint8_t u8IsEnInterupt;

    
    if(pFlashHandle->tStatus.eFlsStatus == FLS_ERASING)
    {
        /* check if finished */
        if (STATUS_HVOP == (s_pFlashDriver_FuncHeader)->FLASH_DRV_HV_Status_Check())
        {
            pFlashHandle->tStatus.eFlsStatus = FLS_ERASING;
        }
        else
        {
#if ((FLASH_FC7300F8MDT == STD_ON) || (FLASH_FC7300F4MDD_T1B == STD_ON) || (FLASH_FC7300F4MDS_T1B == STD_ON) || (FLASH_FC7300F8MDQ == STD_ON))
            if (FLASH_PES_CHECK_MASK == ((s_pFlashDriver_FuncHeader)->FLASH_DRV_Read_Status_Check(FLASH_PES_CHECK_MASK) & \
                                         (s_pFlashDriver_FuncHeader)->FLASH_DRV_Read_Status_Check_P1(FLASH_PES_CHECK_MASK) & \
                                         (s_pFlashDriver_FuncHeader)->FLASH_DRV_Read_Status_Check_P2(FLASH_PES_CHECK_MASK) & \
                                         FLASH_PES_CHECK_MASK))
            {
                (s_pFlashDriver_FuncHeader)->FLASH_DRV_EraseSector_Clear();
                (s_pFlashDriver_FuncHeader)->FLASH_DRV_Read_Status_Check_Clear(FLASH_PES_CHECK_MASK);
                (s_pFlashDriver_FuncHeader)->FLASH_DRV_Read_Status_Check_Clear_P1(FLASH_PES_CHECK_MASK);
                (s_pFlashDriver_FuncHeader)->FLASH_DRV_Read_Status_Check_Clear_P2(FLASH_PES_CHECK_MASK);
                pFlashHandle->tStatus.eFlsStatus = FLS_ERASE_ERROR;
            }
#elif ((FLASH_FC7300F4MDD_T1C == STD_ON) || (FLASH_FC7300F4MDS_T1C == STD_ON))
            if (FLASH_PES_CHECK_MASK == ((s_pFlashDriver_FuncHeader)->FLASH_DRV_Read_Status_Check(FLASH_PES_CHECK_MASK) & \
                                         (s_pFlashDriver_FuncHeader)->FLASH_DRV_Read_Status_Check_P2(FLASH_PES_CHECK_MASK) & \
                                         FLASH_PES_CHECK_MASK))
            {
                (s_pFlashDriver_FuncHeader)->FLASH_DRV_EraseSector_Clear();
                (s_pFlashDriver_FuncHeader)->FLASH_DRV_Read_Status_Check_Clear(FLASH_PES_CHECK_MASK);
                (s_pFlashDriver_FuncHeader)->FLASH_DRV_Read_Status_Check_Clear_P2(FLASH_PES_CHECK_MASK);
                pFlashHandle->tStatus.eFlsStatus = FLS_ERASE_ERROR;
            }
#elif (FLASH_FC7240F2MDS == STD_ON)
            if (FLASH_PES_CHECK_MASK == ((s_pFlashDriver_FuncHeader)->FLASH_DRV_Read_Status_Check(FLASH_PES_CHECK_MASK) & FLASH_PES_CHECK_MASK))
            {
                (s_pFlashDriver_FuncHeader)->FLASH_DRV_EraseSector_Clear();
                (s_pFlashDriver_FuncHeader)->FLASH_DRV_Read_Status_Check_Clear(FLASH_PES_CHECK_MASK);
                pFlashHandle->tStatus.eFlsStatus = FLS_ERASE_ERROR;
            }
#endif
            else
            {
                if (STATUS_SUCCESS == (s_pFlashDriver_FuncHeader)->FLASH_DRV_EraseSector_Clear())
                {
                    pFlashHandle->tStatus.eFlsStatus = FLS_ASYNC_ERASE_PENDING;
                    FLASHDRIVER_LockSector(pFlashHandle->tStatus.u32CurrentAddress, FLASH_LOCK);
                    pFlashHandle->tStatus.u32CurrentAddress += pFlashHandle->tStatus.u32EraseSectorSize;
                }
                else
                {
                    pFlashHandle->tStatus.eFlsStatus = FLS_ERASE_ERROR;
                }
            }
        }       
    }

    if(pFlashHandle->tStatus.eFlsStatus == FLS_ASYNC_ERASE_PENDING)
    {
        if(pFlashHandle->tStatus.u32CurrentAddress < (pFlashHandle->tStatus.u32Address + pFlashHandle->tStatus.u32Length))
        {
            (s_pFlashDriver_FuncHeader)->FLASH_DRV_ENABLE_HOLD_CFG(1);
            if(NULL != pFlashHandle->tSettings.pUnlockCallback)
            {
                pFlashHandle->tSettings.pUnlockCallback(pFlashHandle->tStatus.u32CurrentAddress);
            }
            FLASHDRIVER_GetFlashConfig(pFlashHandle->tStatus.u32CurrentAddress, &tFlash_api_cfg);
            /* check erase operation valid */
            /* Disable Inetrrupt*/
            u8IsEnInterupt = FLASHDRIVER_MsrIsOn();//0 disable ,1 enable
            if(u8IsEnInterupt == 1)
            {
                __asm(" cpsid i");
            }
            if (FLASH_HARDWARE_STATUS_IDLE == (((*(volatile uint32 *)FLASH_HARDWARE_STATUS_ADDR) & FLASH_HARDWARE_STATUS_MASK) >> 16))
            {
#if((FLASH_FC7300F8MDT == STD_ON) || (FLASH_FC7300F4MDD_T1B == STD_ON) || (FLASH_FC7300F4MDS_T1B == STD_ON) || (FLASH_FC7240F2MDS == STD_ON))
                if ((s_pFlashDriver_FuncHeader)->FLASH_DRV_EraseSector(&tFlash_api_cfg, FLASH_API_DISABLE, FLASH_API_SIZE) != STATUS_SUCCESS)
#elif((FLASH_FC7300F8MDQ == STD_ON) || (FLASH_FC7300F4MDD_T1C == STD_ON) || (FLASH_FC7300F4MDS_T1C == STD_ON))
                if ((s_pFlashDriver_FuncHeader)->FLASH_DRV_EraseSector(&tFlash_api_cfg) != STATUS_SUCCESS)
#endif
                {
                    pFlashHandle->tStatus.eFlsStatus = FLS_ERASE_ERROR;
                }
                else
                {
                    pFlashHandle->tStatus.eFlsStatus = FLS_ERASING;
                }
            }
            else
            {
                pFlashHandle->tStatus.eFlsStatus = FLS_ERASE_ERROR;
            }
            /* Recover Inetrrupt*/
            if(u8IsEnInterupt == 1)
            {
                __asm(" cpsie i");
            }
        }
        else
        {
            pFlashHandle->tStatus.eFlsStatus = FLS_IDLE;
        }
    }

    tRetVal = pFlashHandle->tStatus.eFlsStatus;
    return tRetVal;
}

/**
* @brief        flash driver check current status when writing
*
* @param        pFlashHandle the Flash instance to use
* @return       Fls_Status_t return the write status
*/
Fls_Status_t FLASHDRIVER_AsyncWriteMainFunction(FLASH_HandleType *pFlashHandle)
{
    FLASH_ROM_API_ENTRY_T *const s_pFlashDriver_FuncHeader = s_pFlashDriver[pFlashHandle->eInstance];
    Fls_Status_t tRetVal;
    FLASH_API_PRGM_CFG_TYPE tFlash_api_cfg = {0};
    uint32_t u32ProgramEndAddr, u32EndAddr;
    uint8_t u8IsEnInterupt;

    
    if(pFlashHandle->tStatus.eFlsStatus == FLS_WRITING)
    {
        /* check if finished */
        if (STATUS_HVOP == (s_pFlashDriver_FuncHeader)->FLASH_DRV_HV_Status_Check())
        {
            pFlashHandle->tStatus.eFlsStatus = FLS_WRITING;
        }
        else
        {
#if ((FLASH_FC7300F8MDT == STD_ON) || (FLASH_FC7300F4MDD_T1B == STD_ON) || (FLASH_FC7300F4MDS_T1B == STD_ON) || (FLASH_FC7300F8MDQ == STD_ON))
            if (FLASH_PES_CHECK_MASK == ((s_pFlashDriver_FuncHeader)->FLASH_DRV_Read_Status_Check(FLASH_PES_CHECK_MASK) & \
                                         (s_pFlashDriver_FuncHeader)->FLASH_DRV_Read_Status_Check_P1(FLASH_PES_CHECK_MASK) & \
                                         (s_pFlashDriver_FuncHeader)->FLASH_DRV_Read_Status_Check_P2(FLASH_PES_CHECK_MASK) & \
                                         FLASH_PES_CHECK_MASK))
            {
                (s_pFlashDriver_FuncHeader)->FLASH_DRV_Program_Clear();
                (s_pFlashDriver_FuncHeader)->FLASH_DRV_Read_Status_Check_Clear(FLASH_PES_CHECK_MASK);
                (s_pFlashDriver_FuncHeader)->FLASH_DRV_Read_Status_Check_Clear_P1(FLASH_PES_CHECK_MASK);
                (s_pFlashDriver_FuncHeader)->FLASH_DRV_Read_Status_Check_Clear_P2(FLASH_PES_CHECK_MASK);
                pFlashHandle->tStatus.eFlsStatus = FLS_WRITE_ERROR;
            }
#elif ((FLASH_FC7300F4MDD_T1C == STD_ON) || (FLASH_FC7300F4MDS_T1C == STD_ON))
            if (FLASH_PES_CHECK_MASK == ((s_pFlashDriver_FuncHeader)->FLASH_DRV_Read_Status_Check(FLASH_PES_CHECK_MASK) & \
                                         (s_pFlashDriver_FuncHeader)->FLASH_DRV_Read_Status_Check_P2(FLASH_PES_CHECK_MASK) & \
                                         FLASH_PES_CHECK_MASK))
            {
                (s_pFlashDriver_FuncHeader)->FLASH_DRV_Program_Clear();
                (s_pFlashDriver_FuncHeader)->FLASH_DRV_Read_Status_Check_Clear(FLASH_PES_CHECK_MASK);
                (s_pFlashDriver_FuncHeader)->FLASH_DRV_Read_Status_Check_Clear_P2(FLASH_PES_CHECK_MASK);
                pFlashHandle->tStatus.eFlsStatus = FLS_WRITE_ERROR;
            }
#elif (FLASH_FC7240F2MDS == STD_ON)
            if (FLASH_PES_CHECK_MASK == ((s_pFlashDriver_FuncHeader)->FLASH_DRV_Read_Status_Check(FLASH_PES_CHECK_MASK) & FLASH_PES_CHECK_MASK))
            {
                (s_pFlashDriver_FuncHeader)->FLASH_DRV_Program_Clear();
                (s_pFlashDriver_FuncHeader)->FLASH_DRV_Read_Status_Check_Clear(FLASH_PES_CHECK_MASK);
                pFlashHandle->tStatus.eFlsStatus = FLS_WRITE_ERROR;
                pFlashHandle->tStatus.u32ErrorAdress = pFlashHandle->tStatus.u32CurrentAddress;
            }
#endif
            else
            {
                if (STATUS_SUCCESS == (s_pFlashDriver_FuncHeader)->FLASH_DRV_Program_Clear())
                {
                    pFlashHandle->tStatus.eFlsStatus = FLS_ASYNC_WRITE_PENDING;
                    FLASHDRIVER_LockSector(pFlashHandle->tStatus.u32CurrentAddress, FLASH_LOCK);
                    pFlashHandle->tStatus.pDate += pFlashHandle->tStatus.u32ProgramSize;
                    pFlashHandle->tStatus.u32CurrentAddress += pFlashHandle->tStatus.u32ProgramSize;
                }
                else
                {
                    pFlashHandle->tStatus.eFlsStatus = FLS_WRITE_ERROR;
                    pFlashHandle->tStatus.u32ErrorAdress = pFlashHandle->tStatus.u32CurrentAddress;
                }
            }
        }       
    }

    if(pFlashHandle->tStatus.eFlsStatus == FLS_ASYNC_WRITE_PENDING)
    {
        if(pFlashHandle->tStatus.u32CurrentAddress < (pFlashHandle->tStatus.u32Address + pFlashHandle->tStatus.u32Length))
        {
            u32EndAddr = pFlashHandle->tStatus.u32Address + pFlashHandle->tStatus.u32Length;
            u32ProgramEndAddr = ((pFlashHandle->tStatus.u32CurrentAddress + FLASH_PROGRAM_PAGE_MAX_SIZE) & ~(FLASH_PROGRAM_PAGE_MAX_SIZE - 1U));
            u32ProgramEndAddr = ((u32ProgramEndAddr > u32EndAddr) ? u32EndAddr : u32ProgramEndAddr);
            pFlashHandle->tStatus.u32ProgramSize = u32ProgramEndAddr - pFlashHandle->tStatus.u32CurrentAddress;

            tFlash_api_cfg.dest = pFlashHandle->tStatus.u32CurrentAddress;
            tFlash_api_cfg.size = (uint32_t)(pFlashHandle->tStatus.u32ProgramSize) >> 2;  /* one data is 4 bytes  */
            tFlash_api_cfg.pData = (uint32_t *)(pFlashHandle->tStatus.pDate);
            tFlash_api_cfg.wdg_tune = WDG_TUNE_DISABLE;
            tFlash_api_cfg.pgff = FLASH_REG_BIT_CFG_DISABLE;
            if(NULL != pFlashHandle->tSettings.pUnlockCallback)
            {
                pFlashHandle->tSettings.pUnlockCallback(pFlashHandle->tStatus.u32CurrentAddress);
            }
            /* Disable Inetrrupt*/
            u8IsEnInterupt = FLASHDRIVER_MsrIsOn();//0 disable ,1 enable
            if(u8IsEnInterupt == 1)
            {
                __asm(" cpsid i");
            }
            if (FLASH_HARDWARE_STATUS_IDLE == (((*(volatile uint32 *)FLASH_HARDWARE_STATUS_ADDR) & FLASH_HARDWARE_STATUS_MASK) >> 16))
            {
#if((FLASH_FC7300F8MDT == STD_ON) || (FLASH_FC7300F4MDD_T1B == STD_ON) || (FLASH_FC7300F4MDS_T1B == STD_ON) || (FLASH_FC7240F2MDS == STD_ON))
                if ((s_pFlashDriver_FuncHeader)->FLASH_DRV_Program(&tFlash_api_cfg, FLASH_API_DISABLE, FLASH_API_SIZE) != STATUS_SUCCESS)
#elif((FLASH_FC7300F8MDQ == STD_ON) || (FLASH_FC7300F4MDD_T1C == STD_ON) || (FLASH_FC7300F4MDS_T1C == STD_ON))
                    if ((s_pFlashDriver_FuncHeader)->FLASH_DRV_Program(&tFlash_api_cfg) != STATUS_SUCCESS)
#endif
                    {
                        pFlashHandle->tStatus.eFlsStatus = FLS_WRITE_ERROR;
                        pFlashHandle->tStatus.u32ErrorAdress = pFlashHandle->tStatus.u32CurrentAddress;
                    }
                    else
                    {
                        pFlashHandle->tStatus.eFlsStatus = FLS_WRITING;
                    }
            }
            else
            {
                pFlashHandle->tStatus.eFlsStatus = FLS_WRITE_ERROR;
                pFlashHandle->tStatus.u32ErrorAdress = pFlashHandle->tStatus.u32CurrentAddress;
            }
            /* Recover Inetrrupt*/
            if(u8IsEnInterupt == 1)
            {
                __asm(" cpsie i");
            }
        }
        else
        {
            pFlashHandle->tStatus.eFlsStatus = FLS_IDLE;
            FLASHDRIVER_EccCheck(pFlashHandle);
        }
    }

    tRetVal = pFlashHandle->tStatus.eFlsStatus;
    return tRetVal;
}

/**
* @brief        flash driver interrupt erase
*
* @param        pFlashHandle the Flash instance to use
* @param        pFlashParam flash driver erase parameter
* @return       none
*/
void FLASHDRIVER_InterruptErase(FLASH_HandleType *pFlashHandle, FLASH_DRIVER_ParamType *pFlashParam)
{
#if FLASH_DEV_ERROR_REPORT == STD_ON
    if (NULL == pFlashParam)
    {
        FLASH_ReportDevError(FLASH_INTERRUPT_ERASE_ID, FLASH_E_PARAM_POINTER);
    }
#endif
    FLASH_StatusType tRetVal;

    tRetVal = FLASH_ERROR_OK;
    pFlashParam->u32ErrorAddress = 0x0U;
    tRetVal = FLASHDRIVER_EraseCheck(pFlashParam);

    if (tRetVal == FLASH_ERROR_OK)
    {
        pFlashHandle->tStatus.eFlsStatus = FLS_ERASING;
        pFlashHandle->tStatus.u32Address = pFlashParam->u32Address;
        pFlashHandle->tStatus.u32Length = pFlashParam->u32Length;
        pFlashHandle->tStatus.u32CurrentAddress = pFlashParam->u32Address;
        if(pFlashHandle->tStatus.u32Address <= PFLASH_ADDR_END)
        {
            pFlashHandle->tStatus.u32EraseSectorSize = PFLASH_ERASE_SECTOR_SIZE;
        }
        else
        {
            pFlashHandle->tStatus.u32EraseSectorSize = DFLASH_ERASE_SECTOR_SIZE;
        }
        FLASHDRIVER_INTSingleErase(pFlashHandle);
    }
    else
    {
#if FLASH_DEV_ERROR_REPORT == STD_ON
        FLASH_ReportDevError(FLASH_INTERRUPT_ERASE_ID, FLASH_E_PARAM_POINTER);
#endif
    }
}

/**
* @brief        flash driver interrupt write
*
* @param        pFlashHandle the Flash instance to use
* @param        pFlashParam flash driver write parameter
* @return       none
*/
void FLASHDRIVER_InterruptProgram(FLASH_HandleType *pFlashHandle, FLASH_DRIVER_ParamType *pFlashParam)
{
#if FLASH_DEV_ERROR_REPORT == STD_ON
    if (NULL == pFlashParam)
    {
        FLASH_ReportDevError(FLASH_INTERRUPT_WRITE_ID, FLASH_E_PARAM_POINTER);
    }
#endif
    FLASH_StatusType tRetVal;
    tRetVal = FLASH_ERROR_OK;
    pFlashParam->u32ErrorAddress = 0x0U;
    tRetVal = FLASHDRIVER_WriteCheck(pFlashParam);
    if (tRetVal == FLASH_ERROR_OK)
    {
        pFlashHandle->tStatus.eFlsStatus = FLS_WRITING;
        pFlashHandle->tStatus.u32Address = pFlashParam->u32Address;
        pFlashHandle->tStatus.u32Length = pFlashParam->u32Length;
        pFlashHandle->tStatus.u32CurrentAddress = pFlashParam->u32Address;
        pFlashHandle->tStatus.pDate = pFlashParam->pData;

        FLASHDRIVER_INTSingleProgram(pFlashHandle);
    }
    else
    {
#if FLASH_DEV_ERROR_REPORT == STD_ON
        FLASH_ReportDevError(FLASH_INTERRUPT_WRITE_ID, FLASH_E_PARAM_POINTER);
#endif
    }
}

/**
 * @brief Close teset mode
 *
 * @param pFlashHandle the Flash instance to use
 * @return none
 */
void FLASHDRIVER_Close_Test_Mode(FLASH_HandleType *pFlashHandle)
{
    FLASH_ROM_API_ENTRY_T *const s_pFlashDriver_FuncHeader = s_pFlashDriver[pFlashHandle->eInstance];
    (s_pFlashDriver_FuncHeader)->FLASH_DRV_Test_Mode_Close();
}

#if ((FLASH_FC7300F8MDQ == STD_ON) || (FLASH_FC7300F4MDD_T1C == STD_ON) || (FLASH_FC7300F4MDS_T1C == STD_ON))
/**
 * @brief Flash Driver Function for enable interrupt
 *
 * @param u32CoreID  core id
 * @return       none
 */
void FLASHDRIVER_EnInterrupt(uint32_t u32CoreID)
{
    FMC0->FEINTC |= (uint32_t)(0x1<<(u32CoreID+8));
}
#endif

/**
 * @brief Process Flash interrupt
 *
 * @param pFlashHandle the Flash instance to use
 * @return process result
 */
Fls_ReturnType Fls_CommonProcessInterrupt(FLASH_HandleType *pFlashHandle)
{
    FLASH_ROM_API_ENTRY_T *const s_pFlashDriver_FuncHeader = s_pFlashDriver[pFlashHandle->eInstance];
    Fls_ReturnType interrupt_ret = FLASH_INTERRUPT_ERR_NOT_OK;
#if((FLASH_FC7300F8MDQ == STD_ON) || (FLASH_FC7300F4MDD_T1C == STD_ON) || (FLASH_FC7300F4MDS_T1C == STD_ON))
    FLASH_API_DMA_CFG_TYPE dma_cfg = {.dma_allow = 0x2,.dma_en = 0x0, .dma_ie = 0x2};
    FLASH_API_WDG_CFG_TYPE wdg_cfg = {.wen = 0x0};
    uint32_t u32DMATargetCount, u32DMACount;
#endif
    if (pFlashHandle->tStatus.eFlsStatus == FLS_WRITING)
    {
        /* check if finished */
        if (STATUS_SUCCESS == (s_pFlashDriver_FuncHeader)->FLASH_DRV_Program_Clear())
        {
            interrupt_ret = FLASH_INTERRUPT_ERR_OK;
            FLASHDRIVER_LockSector(pFlashHandle->tStatus.u32CurrentAddress, FLASH_LOCK);
            if (pFlashHandle->tStatus.u32CurrentAddress < (pFlashHandle->tStatus.u32Address + pFlashHandle->tStatus.u32Length))
            {
            	pFlashHandle->tStatus.pDate += pFlashHandle->tStatus.u32ProgramSize;
                FLASHDRIVER_INTSingleProgram(pFlashHandle);
            }
            else
            {
                if(FLASH_ECC_ERROR_NONE != FLASHDRIVER_EccCheck(pFlashHandle))
                {
                    interrupt_ret = FLASH_INTERRUPT_ERR_NOT_OK;
                }
                else
                {
                    pFlashHandle->tStatus.eFlsStatus = FLS_IDLE;
                }
            }
        }
        else
        {
            interrupt_ret = FLASH_INTERRUPT_ERR_NOT_OK;
        }
    }
    else if (pFlashHandle->tStatus.eFlsStatus == FLS_ERASING)
    {

        if (STATUS_SUCCESS == (s_pFlashDriver_FuncHeader)->FLASH_DRV_EraseSector_Clear())
        {
            interrupt_ret = FLASH_INTERRUPT_ERR_OK;
            FLASHDRIVER_LockSector(pFlashHandle->tStatus.u32CurrentAddress, FLASH_LOCK);
            if (pFlashHandle->tStatus.u32CurrentAddress < (pFlashHandle->tStatus.u32Address + pFlashHandle->tStatus.u32Length))
            {
            	FLASHDRIVER_INTSingleErase(pFlashHandle);
            }
            else
            {
                pFlashHandle->tStatus.eFlsStatus = FLS_IDLE;
            }
        }
        else
        {
            interrupt_ret = FLASH_INTERRUPT_ERR_NOT_OK;
        }
    }
#if((FLASH_FC7300F8MDQ == STD_ON) || (FLASH_FC7300F4MDD_T1C == STD_ON) || (FLASH_FC7300F4MDS_T1C == STD_ON))
    else if(pFlashHandle->tStatus.eFlsStatus == FLS_DMA_WRITING)
    {
        if (FLASH_DMA_DONE_CHECK_MASK == (FLASH_DMA_DONE_CHECK_MASK & (s_pFlashDriver_FuncHeader)->FLASH_DRV_Read_Status_Check(FLASH_DMA_DONE_CHECK_MASK)))
        {
        	u32DMACount = (((*(uint32*)0x40020078) & 0x1FFF0000) >> 16);
			u32DMATargetCount = ((*(uint32*)0x40020078) & 0x00001FFF);
            if(FLASH_WDG_CHECK_MASK == (FLASH_WDG_CHECK_MASK & (s_pFlashDriver_FuncHeader)->FLASH_DRV_Read_Status_Check(FLASH_WDG_CHECK_MASK)))
            {
            	interrupt_ret = FLASH_INTERRUPT_ERR_NOT_OK;
            	(s_pFlashDriver_FuncHeader)->FLASH_DRV_DMA_CFG_FUNC(&dma_cfg);
            	(s_pFlashDriver_FuncHeader)->FLASH_DRV_Program_Clear();
            	(s_pFlashDriver_FuncHeader)->FLASH_DRV_Read_Status_Check_Clear(FLASH_DMA_DONE_CHECK_MASK);
            	pFlashHandle->tStatus.eFlsStatus = FLS_IDLE;
            }
            else if(FLASH_PEP_CHECK_MASK == (FLASH_PEP_CHECK_MASK & (s_pFlashDriver_FuncHeader)->FLASH_DRV_Read_Status_Check(FLASH_PEP_CHECK_MASK)))
            {
            	interrupt_ret = FLASH_INTERRUPT_ERR_NOT_OK;
            	(s_pFlashDriver_FuncHeader)->FLASH_DRV_Read_Status_Check_Clear(FLASH_PEP_CHECK_MASK);
            	(s_pFlashDriver_FuncHeader)->FLASH_DRV_Read_Status_Check_Clear(FLASH_DMA_DONE_CHECK_MASK);
            	(s_pFlashDriver_FuncHeader)->FLASH_DRV_DMA_CFG_FUNC(&dma_cfg);
            	pFlashHandle->tStatus.eFlsStatus = FLS_IDLE;

            }
            else if(FLASH_PES_CHECK_MASK == (FLASH_PES_CHECK_MASK & (s_pFlashDriver_FuncHeader)->FLASH_DRV_Read_Status_Check(FLASH_PES_CHECK_MASK)))
            {
            	interrupt_ret = FLASH_INTERRUPT_ERR_NOT_OK;
            	(s_pFlashDriver_FuncHeader)->FLASH_DRV_Read_Status_Check_Clear(FLASH_PES_CHECK_MASK);
            	(s_pFlashDriver_FuncHeader)->FLASH_DRV_Read_Status_Check_Clear(FLASH_DMA_DONE_CHECK_MASK);
            	(s_pFlashDriver_FuncHeader)->FLASH_DRV_DMA_CFG_FUNC(&dma_cfg);
            	pFlashHandle->tStatus.eFlsStatus = FLS_IDLE;

            }
            else if(u32DMACount != u32DMATargetCount)
            {
            	interrupt_ret = FLASH_INTERRUPT_ERR_NOT_OK;
                (s_pFlashDriver_FuncHeader)->FLASH_DRV_Read_Status_Check_Clear(FLASH_DMA_DONE_CHECK_MASK);
                (s_pFlashDriver_FuncHeader)->FLASH_DRV_DMA_CFG_FUNC(&dma_cfg);
                pFlashHandle->tStatus.eFlsStatus = FLS_IDLE;
            }
            else
            {
            	interrupt_ret = FLASH_INTERRUPT_ERR_OK;
                (s_pFlashDriver_FuncHeader)->FLASH_DRV_Read_Status_Check_Clear(FLASH_DMA_DONE_CHECK_MASK);
                (s_pFlashDriver_FuncHeader)->FLASH_DRV_DMA_CFG_FUNC(&dma_cfg);
                (s_pFlashDriver_FuncHeader)->FLASH_DRV_Wdog_Configure(&wdg_cfg);

                if(FLASH_ECC_ERROR_NONE != FLASHDRIVER_EccCheck(pFlashHandle))
                {
                    interrupt_ret = FLASH_INTERRUPT_ERR_NOT_OK;
                }
                else
                {
                    pFlashHandle->tStatus.eFlsStatus = FLS_IDLE;
                }
            }

        }
        else
        {
        	interrupt_ret = FLASH_INTERRUPT_ERR_NOT_OK;
        }
    }
#endif
    else
    {

    }
    return interrupt_ret;
}

#endif /* #if FLASH_INSTANCE_COUNT > 0U */
