/**
 * @file module_driver_sec.c
 * @author flagchip
 * @brief SEC driver type definition and API
 * @version 2.0.0
 * @date 2022-2-7
 *
 * SDK Version: 2.6.0
 *

 * @copyright Copyright (c) 2020-2024 Flagchip Semiconductors Co., Ltd.
 *
 * @details
 */
/********************************************************************************
*   Revision History:
*
*   Version     Date          Initials       CR#          Descriptions
*   ---------   ----------    ------------   ----------   ---------------
*     2.0.0    2024-8-23       Flagchip120    N/A         Release version
********************************************************************************/
#include "module_driver_sec.h"


#if SEC_INSTANCE_COUNT > 0U

#ifndef SEC_DEV_ERROR_REPORT
#define SEC_DEV_ERROR_REPORT	STD_OFF
#endif

#if SEC_DEV_ERROR_REPORT == STD_ON
#define SEC_ReportDevError(func, error) ReportDevError(SEC_MODULE_ID, func, error)
#endif

static SEC_Type *const s_pSEC_Instance = SEC;

/**
 * @brief This function can be used to enable the Debug mode.
 * @return  true means enable debug success ,false means enable debug failed.
 * */
bool SEC_EnDebugMode(void)
{
    bool ret = false;
    if (SEC_HWA_GetWritePer(s_pSEC_Instance))
    {
        SEC_HWA_EnDebug(s_pSEC_Instance);
        ret = true;
    }
    return ret;
}

/**
 * @brief This function can be used to  re-enable the Debug mode by the re-enable keys.
 * @param keys The Debug mode re-enable keys.
 * @return true means re-enable success,false means re-enable failed.
 * */
bool SEC_ReEnDebugMode(ReEnDebug_Keys keys)
{
    bool ret = false;
    if (SEC_HWA_GetReEnDebug(s_pSEC_Instance))
    {
        SEC_HWA_WriteReEnKeyn(s_pSEC_Instance, 0u, keys.Re_key0);
        SEC_HWA_WriteReEnKeyn(s_pSEC_Instance, 1u, keys.Re_key1);
        SEC_HWA_WriteReEnKeyn(s_pSEC_Instance, 2u, keys.Re_key2);
        SEC_HWA_WriteReEnKeyn(s_pSEC_Instance, 3u, keys.Re_key3);
        ret = true;
    }
    return ret;
}

/**
 * @brief This function can get the system state (secured or no secured).
 * */
Systemstate SEC_SystemSecureState(void)
{
    Systemstate  ret =  Securedstate ;
    uint16_t sskey0 = SEC_HWA_GetSScontrol0(s_pSEC_Instance);
    uint16_t sskey1 = SEC_HWA_GetSScontrol1(s_pSEC_Instance);
    if ((sskey0 == 0xC35AU) && (sskey1 == 0xFFFFU))
    {
        ret = UnSecuredstate;
    }
    return ret ;
}


/**
 * @brief This function can enable the test mode.
 * @return true means enable test mode success,false means enable test mode failed.
 * */
bool SEC_EnTestMode(void)
{

    bool ret = false;
    if (SEC_HWA_GetWritePer(s_pSEC_Instance))
    {
        SEC_HWA_EnTest(s_pSEC_Instance);
        ret = true;
    }
    return ret;
}



/**
 *@brief This function can Re-enable the test mode by the re-enable key.
 *@param key The test mode re-enable key.The key is up to the user to decide in advance.
 *@return true means re-enable success,false means re-enable failed.
 * */
bool SEC_ReEnTestMode(uint32_t key)
{
    bool ret = false;

    bool writeper = SEC_HWA_GetWritePer(s_pSEC_Instance);
    bool reentest = SEC_HWA_GetReEnTest(s_pSEC_Instance);
    if ((true == writeper) && (true == reentest))
    {
        SEC_HWA_ReEnTestKey(s_pSEC_Instance, key);
        ret = true;
    }
    return ret;
}



/**
 * @brief This function can used to set the NVR write and read permission.
 * @return true means setPer success,false means setPer failed.
 * */
bool SEC_SetNvrPer(NVR_Per per)
{
    bool ret = false;
    if (SEC_HWA_GetWritePer(s_pSEC_Instance))
    {
#if SEC_FCR0_NRP_MASK
        if (per.ReadEn == true)
        {
            SEC_HWA_EnReadB0NVR(s_pSEC_Instance);
        }
        else
        {
            SEC_HWA_DisReadB0NVR(s_pSEC_Instance);
        }
#elif SEC_NKRP_NKRP_MASK
        if (per.ReadEn == true)
        {
            SEC_HWA_EnReadB0NVRKey(s_pSEC_Instance);
        }
        else
        {
            SEC_HWA_DisReadB0NVRKey(s_pSEC_Instance);
        }        
#endif
        if (per.WritEn == true)
        {
            SEC_HWA_EnWriteB0NVR(s_pSEC_Instance);
        }
        else
        {
            SEC_HWA_DisWriteB0NVR(s_pSEC_Instance);
        }

        if (per.EraseEn == true)
        {
            SEC_HWA_EnEraseB0NVR(s_pSEC_Instance);
        }
        else
        {
            SEC_HWA_DisEraseB0NVR(s_pSEC_Instance);
        }

        ret = true;
    }
    return ret;
}


/**
 * @brief Get Secure Boot Enable Status
 *
 * @return true is enable and false is disable
 */
bool SEC_GetSecureStatus(void)
{
    return SEC_HWA_GetSB(s_pSEC_Instance);
}

/**
 * @brief Get ISP Status
 *
 * @return true is active and false is inactive
 */
bool SEC_GetISPModeStatus(void)
{
    return SEC_HWA_GetIspStatus(s_pSEC_Instance);
}

/**
 * @brief Get User setting bootloader address
 *
 * @return bootloader address
 */
uint32_t SEC_GetBootAddress(void)
{
    return SEC_HWA_GetBLAddr(s_pSEC_Instance);
}

#if SEC_FWA_MASK
/**
 * @brief Get the HSM Firmware Address
 *
 * @return the HSM Firmware address
 */
uint32_t SEC_GetHsmFwAddress(void)
{
    return SEC_HWA_GetHsmAddr(s_pSEC_Instance);
}
#endif

/**
 * @brief Get the lifecycle.
 *
 * @return the lifecycle.
 */

SC_LifeCycle SEC_GetLifeCycle(void)
{
    SC_LifeCycle lifecycle  = LIFECYCLE_INVALID;

    uint8_t lifecycle_status;
    lifecycle_status = SEC_HWA_GetLCStaus(s_pSEC_Instance);

    switch (lifecycle_status)
    {
    case 1u:
        lifecycle = LIFECYCLE_OEM_DEV;
        break;
    case 2u:
        lifecycle = LIFECYCLE_OEM_PDT;
        break;
    case 4u:
        lifecycle = LIFECYCLE_INFIELD;
        break;
    case 8u:
        lifecycle = LIFECYCLE_PREFA;
        break;
    case 16u:
        lifecycle = LIFECYCLE_FA;
        break;
    default:
        break;

    }
    return lifecycle;
}



/**
 * @brief User Key Access Enable. Only valid under non-secure boot
 * @return true means User key can be read/programmed/erased by host CPU
 * */
bool SEC_HostUKAccess(void)
{
    return SEC_HWA_GetUKAS(s_pSEC_Instance);
}

#if SEC_BRC0_FW_READ_DIS_MASK
/**
 * @brief Firmware Read Disable/Enable. (Value loaded from NVR sector)
 * @return  true means Host core read access to firmware read is disabled, false means - Host core read access to firmware read is enabled.
 */
bool SEC_GetHostFwDisAccess(void)
{
    return SEC_HWA_GetFWRE(s_pSEC_Instance);
}
#endif

#if SEC_BRC1_FW_VALID_MASK
/**
 * @brief  Get whether Flash Firmware is valid.
 * @return true means Flash Firmware  is valid. false means Flash Firmware is not Valid
 * */
bool SEC_GetFwValid(void)
{
    return SEC_HWA_GetFwValid(s_pSEC_Instance);
}
#endif

/**
 * @brief get the Bootloader Verification Algorithm
 *  @return the Bootloader Verification Algorithm
 * */
BL_VerifyAlgorithm SEC_GetBLVerifyAlgorithm(void)
{

    return (BL_VerifyAlgorithm)(uint8_t)(SEC_HWA_GetBLVer(s_pSEC_Instance));
}

#if SEC_BRC2_DECRP_ALG_MASK
/**
 * @brief get the Debug/ISP/PREFA Authentication and USRK decryption algorithm
 *  @return decryption algorithm
 * */
Decryption_Algorithm SEC_GetDecryptAlgorithm(void)
{
    return (Decryption_Algorithm)(uint8_t)(SEC_HWA_GetDecrypt(s_pSEC_Instance));


}
#endif


/**
 * @brief Indicate the Host User Key Read/Write/Erase Protection
 * @param PHostUKAccess the structure for information
 *
 * */
void SEC_GetHostUKAccess(HostUKPermission *const PHostUKAccess)
{
    PHostUKAccess->HostUKEraseEn =  SEC_HWA_GetHUKErase(s_pSEC_Instance);
    PHostUKAccess->HostUKReadEn = SEC_HWA_GetHUKRead(s_pSEC_Instance);
    PHostUKAccess->HostUKWriteEn = SEC_HWA_GetHUKWrite(s_pSEC_Instance);
}



/**
 * @brief Indicate the Host NVR Read/Write/Erase Protection
 *@param PHostNvrAccess the structure to initialize
 * */
void SEC_GetHostNVRAccess(HostNVRPermission *const PHostNVRAccess)
{
    PHostNVRAccess->HostNVREraseEn = SEC_HWA_GetHostNvrErase(s_pSEC_Instance);
    PHostNVRAccess->HostNVRReadEn = SEC_HWA_GetHostNvrRead(s_pSEC_Instance);
    PHostNVRAccess->HostNVRWriteEn = SEC_HWA_GetHostNvrWrite(s_pSEC_Instance);

}



/**
 * @brief Get the HSM User Key Erase Protection
 * @return true - HSM erase access to User Key region is enabled
 *          false -HSM erase access to User Key region is disabled
 * */
bool SEC_GethsmUKEraseAccess(void)
{
    return SEC_HWA_GetHsmUKErase(s_pSEC_Instance);

}


/**
 * @brief Get the HSM NVR Erase Protection
 * @return true - HSM erase access to NVR region is enabled
 *          false -HSM erase access to NVR region is disabled
 * */
bool SEC_GethsmNVREraseAccess(void)
{
    return  SEC_HWA_GetHsmNvrErase(s_pSEC_Instance);

}

/**
 * @brief Get Bootloader Verification Mask
 * @return Bootloader Verification Mask.
 * */
uint32_t SEC_GetBLVerMask(void)
{
    return SEC_HWA_GetBLMask(s_pSEC_Instance);
}

/**
 * @brief Get whether Debug Mailbox Backdoor Key Enable.
 * @return  true means  user can enable debug by writing debug backdoor key, false means user can  not enable debug
 * */
bool SEC_GetDMBDkeyEn(void)
{
    return SEC_HWA_GetMBBKEN(s_pSEC_Instance);
}


/**
 * @brief Host Debug Auth Enable. Only valid in secure boot. (Value loaded from NVR sector)
 * @return  true means Host debug authentication enable. false means Host debug authentication disable.
 */
bool SEC_GetDebugAuthEn(void)
{
    return SEC_HWA_GetDEAUEn(s_pSEC_Instance);
}


/**
 * @brief Get the isp information.
 * @param pIspInfo the structure to information
 * @return Get whether operation is success.
 *
 * */
SEC_RetType SEC_GetIspInfo(SEC_IspInfo *const pIspInfo)
{

    SEC_RetType eRet ;

    if (NULL == pIspInfo)
    {
        eRet = SEC_STATUS_FAILED;
    }
    else
    {
        bool ispen =  SEC_HWA_GetIspStatus(s_pSEC_Instance);
        if (!ispen)
        {
            eRet = SEC_STATUS_FAILED;
        }
        else
        {
            pIspInfo->IspModeEn = SEC_HWA_GetIspStatus(s_pSEC_Instance);
#if SEC_BCS_ISPDIS_MASK
            pIspInfo->IspPinEn = SEC_HWA_GetIspEn(s_pSEC_Instance);
#endif
            pIspInfo->IspAuthEn = SEC_HWA_GetISPAU(s_pSEC_Instance);
            Isp_Instance ispins = (Isp_Instance)(uint8_t)(SEC_HWA_GetIspIns(s_pSEC_Instance));
            if ((ispins == ISP_FCUART1) || (ispins == ISP_FCUART3))
            {
                pIspInfo->Ispfcuartbaudrate = (FCUART_ISP_BAUDRATE)(uint8_t)(SEC_HWA_GetUartBR(s_pSEC_Instance));
                pIspInfo->Ispflexcanbaudrate = ISP_FLEXCAN_INVALID;
            }
            else if ((ispins == ISP_FLEXCAN1) || (ispins == ISP_FLEXCAN5))
            {
                pIspInfo->Ispfcuartbaudrate = ISP_FCUART_INVALID;
                pIspInfo->Ispflexcanbaudrate = (FLEXCAN_ISP_BAUDRATE)(uint8_t)(SEC_HWA_GetCanBR(s_pSEC_Instance));
            }
            else
            {
                /*do nothing*/
            }
            eRet = SEC_STATUS_SUCCESS;
        }
    }
    return eRet;
}

/**
 * @brief Get the boot information.
 * @param pBootInfo the structure for information
 * @return Get whether operation is success.
 *
 * */
SEC_RetType SEC_GetBootInfo(SEC_BootInfo *const pBootInfo)
{

    SEC_RetType eRet ;
    if (NULL == pBootInfo)
    {
        eRet = SEC_STATUS_FAILED;
    }
    else
    {
        pBootInfo->BootRom = SEC_HWA_GetBootRom(s_pSEC_Instance);
        pBootInfo->NmiPinEn = SEC_HWA_GetNmiPin(s_pSEC_Instance);
        pBootInfo->SecBootEn = SEC_HWA_GetSB(s_pSEC_Instance);
        pBootInfo->OscEn = SEC_HWA_GetOSCAvail(s_pSEC_Instance);
        pBootInfo->OscFreq = (Osc_FreqInfo)(uint8_t)(SEC_HWA_GetOSCFre(s_pSEC_Instance));
        pBootInfo->FastBootSpeed = (FastBoot_Speed)(uint8_t)(SEC_HWA_GetFastBootClock(s_pSEC_Instance));
        eRet = SEC_STATUS_SUCCESS;
    }
    return eRet;
}

#endif
