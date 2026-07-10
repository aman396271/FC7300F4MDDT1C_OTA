/**
 * @file HwA_sec.h
 * @author Flagchip
 * @brief sec hardware access layer
 * @version 2.0.0
 * @date 2024-08-20
 *
 * SDK Version: 2.6.0
 *

 * @copyright Copyright (c) 2020-2024 Flagchip Semiconductors Co., Ltd.
 *
 * @details
 */
/* ********************************************************************************
   *   Revision History:
   *
   *   Version     Date          Initials      CR#          Descriptions
   *   ---------   ----------    ------------  ----------   ---------------
   *   0.1.0      2023-12-15     Flagchip120   N/A          First version for FC7300
   *   2.0.0      2024-10-12     Flagchip120   N/A          Change version and release
   ******************************************************************************** */

#ifndef HWA_INCLUDE_HWA_SEC_H_
#define HWA_INCLUDE_HWA_SEC_H_
#include "device_header.h"

#if SEC_INSTANCE_COUNT > 0U

/**
 * @defgroup HwA_sec HwA_sec
 * @ingroup module_driver_sec
 * @{
 */

/* DEN Bit Fields */
/**
 * @brief Enable the debug module
 *
 * @param pSec A pointer to the SEC registers.
 */
LOCAL_INLINE void SEC_HWA_EnDebug(SEC_Type *const pSec)
{
    pSec->DEN = SEC_DEN_DEN(0X5) ;
}

/* FSEC0 Bit Fields */
/**
 * @brief Get the system security KEY0
 * 
 * @param pSec A pointer to the SEC registers.
 * */
LOCAL_INLINE uint16_t SEC_HWA_GetSScontrol0(SEC_Type *const pSec)
{
    return (uint16_t)((pSec->FSEC0) & (SEC_FSEC0_SSC0_MASK));
}

/* FSEC1 Bit Fields */
/**
 * @brief Get the system security KEY1
 * 
 * @param pSec A pointer to the SEC registers.
 * */
LOCAL_INLINE uint16_t SEC_HWA_GetSScontrol1(SEC_Type *const pSec)
{
    return (uint16_t)((pSec->FSEC1) & (SEC_FSEC1_SSC1_MASK));
}

/* DCWOR Bit Fields */
/**
 * @brief Re-enable the Debug mode.
 * @note  This register can only be write once. startup_fc4150.s has lock the register.
 * 
 * @param pSec A pointer to the SEC registers.
 * */
LOCAL_INLINE void SEC_HWA_ReEnDebug(SEC_Type *const pSec)
{
    pSec->DCWOR = ((pSec->DCWOR & (~SEC_DCWOR_DEA_MASK)) | SEC_DCWOR_DEA(0X5));
}

/**
 * @brief Get the Re-enable Debug permission.
 * 
 * @param pSec A pointer to the SEC registers.
 * */
LOCAL_INLINE bool SEC_HWA_GetReEnDebug(SEC_Type *const pSec)
{
    bool ret = false;
    uint8_t  dea = (uint8_t)((pSec->DCWOR & (SEC_DCWOR_DEA_MASK)) >> SEC_DCWOR_DEA_SHIFT);
    if (dea == 0x5U)
    {
        ret = true;
    }
    return ret;
}

/**
 * @brief Enable the write operation for SEC register.
 * @note  This register can only be write once. startup_fc4150.s has lock the register.
 * 
 * @param pSec A pointer to the SEC registers.
 * */
LOCAL_INLINE void SEC_HWA_WriteUnlock(SEC_Type *const pSec)
{
    pSec->DCWOR = ((pSec->DCWOR & (~SEC_DCWOR_RWL_MASK)) | SEC_DCWOR_RWL(0X5));
}

/**
 * @brief Get the sec write permission
 * 
 * @param pSec A pointer to the SEC registers.
 * @return true means allow write. false means  forbid write.
*/
LOCAL_INLINE bool SEC_HWA_GetWritePer(SEC_Type *const pSec)
{
    bool ret = false;
    uint8_t rwl = (uint8_t)((pSec->DCWOR & (SEC_DCWOR_RWL_MASK)) >> SEC_DCWOR_RWL_SHIFT);
    if ((rwl == 0x5U) || (rwl == 0xFU))
    {
        ret = true;
    }
    return ret;
}

/* DEK Bit Fields */
/**
 * @brief Enable the write operation for SEC register.
 * 
 * @param pSec A pointer to the SEC registers.
 * @param count Counter indicating the number of encryption executions
 * @param key New encryption key to be written
 * */
LOCAL_INLINE void SEC_HWA_WriteReEnKeyn(SEC_Type *const pSec, uint8_t count, uint32_t key)
{
    if (count < 4u)
    {
    	pSec->DEN = key;
    }
}

/* TME Bit Fields */
/**
 * @brief Enable the Test module
 * 
 * @param pSec A pointer to the SEC registers.
 * */
LOCAL_INLINE void SEC_HWA_EnTest(SEC_Type *const pSec)
{
    pSec->TME = SEC_TME_TME(0X5) ;
}

/* TMEA Bit Fields */
/**
 * @brief Re-Enable Test mode
 * 
 * @param pSec A pointer to the SEC registers.
 * */
LOCAL_INLINE void SEC_HWA_ReEnTest(SEC_Type *const pSec)
{
    pSec->TMEA = SEC_TMEA_TMEA(0X5) ;
}

/**
 * @brief Get the Re-enable Test permission.
 * 
 * @param pSec A pointer to the SEC registers.
 * */
LOCAL_INLINE bool SEC_HWA_GetReEnTest(SEC_Type *const pSec)
{
    bool ret = false;
    uint8_t  tmea = (uint8_t)((pSec->TMEA & (SEC_TMEA_TMEA_MASK)) >> SEC_TMEA_TMEA_SHIFT);
    if ((tmea == 0x5U) || (tmea == 0xFU))
    {
        ret = true;
    }
    return ret;
}

/* TMEK Bit Fields */
/**
 * @brief write Test re-enable mode key
 *
 * @param pSec A pointer to the SEC registers.
 * @param testkey The test key value to be reloaded into the TMEK register.
 */
LOCAL_INLINE void SEC_HWA_ReEnTestKey(SEC_Type *const pSec, uint32_t testkey)
{
    pSec->TMEK = SEC_TMEK_TMEK(testkey) ;
}

/* FCR0 Bit Fields */
/**
 * @brief Enable the Mass Erase
 * 
 * @param pSec A pointer to the SEC registers.
 */
LOCAL_INLINE void SEC_HWA_EnME(SEC_Type *const pSec)
{
    pSec->FCR0 = ((pSec->FCR0 & (~SEC_FCR0_MED_MASK)) | SEC_FCR0_MED(0x5));
}

#if SEC_FCR0_NRP_MASK
/**
 * @brief Enable the Block 0 NVR read .
 * 
 * @param pSec A pointer to the SEC registers.
 */
LOCAL_INLINE void SEC_HWA_EnReadB0NVR(SEC_Type *const pSec)
{
    pSec->FCR0 = ((pSec->FCR0 & (~SEC_FCR0_NRP_MASK)) | SEC_FCR0_NRP(0x5)) ;
}

/**
 * @brief Disable the Block 0 NVR read .
 * 
 * @param pSec A pointer to the SEC registers.
 */
LOCAL_INLINE void SEC_HWA_DisReadB0NVR(SEC_Type *const pSec)
{
    pSec->FCR0 = ((pSec->FCR0 & (~SEC_FCR0_NRP_MASK)) | SEC_FCR0_NRP(0xA)) ;
}
#endif

#if SEC_NKRP_NKRP_MASK
/**
 * @brief Enable the Block 0 NVR key read .
 *
 * @param pSec A pointer to the SEC registers.
 */
LOCAL_INLINE void SEC_HWA_EnReadB0NVRKey(SEC_Type *const pSec)
{
    pSec->NKRP = ((pSec->NKRP & (~SEC_NKRP_NKRP_MASK)) | SEC_NKRP_NKRP(0x5)) ;
}

/**
 * @brief Disable the Block 0 NVR Key read .
 *
 * @param pSec A pointer to the SEC registers.
 */
LOCAL_INLINE void SEC_HWA_DisReadB0NVRKey(SEC_Type *const pSec)
{
    pSec->NKRP = ((pSec->NKRP & (~SEC_NKRP_NKRP_MASK)) | SEC_NKRP_NKRP(0xA)) ;
}
#endif

/**
 * @brief Enable the Block 0 NVR write .
 * 
 * @param pSec A pointer to the SEC registers.
 */
LOCAL_INLINE void SEC_HWA_EnWriteB0NVR(SEC_Type *const pSec)
{
    pSec->FCR0 = ((pSec->FCR0 & (~SEC_FCR0_NWP_MASK)) | SEC_FCR0_NWP(0x5)) ;
}

/**
 * @brief Disable the Block 0 NVR write .
 * 
 * @param pSec A pointer to the SEC registers.
 */
LOCAL_INLINE void SEC_HWA_DisWriteB0NVR(SEC_Type *const pSec)
{
    pSec->FCR0 = ((pSec->FCR0 & (~SEC_FCR0_NWP_MASK)) | SEC_FCR0_NWP(0xA)) ;
}

/**
 * @brief Enable the Block 0 NVR erase .
 * 
 * @param pSec A pointer to the SEC registers.
 */
LOCAL_INLINE void SEC_HWA_EnEraseB0NVR(SEC_Type *const pSec)
{
    pSec->FCR0 = ((pSec->FCR0 & (~SEC_FCR0_NEP_MASK)) | SEC_FCR0_NEP(0x5)) ;
}

/**
 * @brief Disable the Block 0 NVR erase .
 * 
 * @param pSec A pointer to the SEC registers.
 */
LOCAL_INLINE void SEC_HWA_DisEraseB0NVR(SEC_Type *const pSec)
{
    pSec->FCR0 = ((pSec->FCR0 & (~SEC_FCR0_NEP_MASK)) | SEC_FCR0_NEP(0xA)) ;
}

/* BCS Bit Fields */
/**
 * @brief Get the Fast Boot Select.
 * 
 * @param pSec A pointer to the SEC registers.
 * @return 0b - Select PLL0 as the core clock source; the core clock is 300MHz
 *          1b - Select FIRC as the core clock source; the core clock is 96MHz.
 * */
LOCAL_INLINE uint8_t SEC_HWA_GetFastBootClock(SEC_Type *const pSec)
{
    return (uint8_t)((pSec->BCS & SEC_BCS_FBS_MASK) >> SEC_BCS_FBS_SHIFT);
}

/**
 * @brief NMI Function Enable/Disable
 * 
 * @param pSec A pointer to the SEC registers.
 * @return  false - NMI pin function is disabled after reset.
 *          true - NMI pin function is enabled
 * */
LOCAL_INLINE bool SEC_HWA_GetNmiPin(SEC_Type *const pSec)
{
    return (bool)((pSec->BCS & SEC_BCS_NMIDIS_MASK) >> SEC_BCS_NMIDIS_SHIFT);
}

#if SEC_BCS_ISPDIS_MASK
/**
 * @brief ISP Function Enable/Disable
 * 
 * @param pSec A pointer to the SEC registers.
 * @return  false - ISP pin function is disabled after reset.
 *          true -  ISP pin function is enabled.
 * */
LOCAL_INLINE bool SEC_HWA_GetIspEn(SEC_Type *const pSec)
{
    return (bool)((pSec->BCS & SEC_BCS_ISPDIS_MASK) >> SEC_BCS_ISPDIS_SHIFT);
}
#endif

/**
 * @brief Boot Rom Configuration
 * 
 * @param pSec A pointer to the SEC registers.
 * @return  false - Boot from GPR defined address (except ROM).
 *          true -  Boot from ROM.
 * */
LOCAL_INLINE bool SEC_HWA_GetBootRom(SEC_Type *const pSec)
{
    return (bool)((pSec->BCS & SEC_BCS_BOOTROM_MASK) >> SEC_BCS_BOOTROM_SHIFT);
}

/**
 * @brief ISP Mode Status
 * 
 * @param pSec A pointer to the SEC registers.
 * @return  false - ISP mode is inactive.
 *          true  - ISP mode is active.
 * */
LOCAL_INLINE bool SEC_HWA_GetIspStatus(SEC_Type *const pSec)
{
    return (bool)((pSec->BCS & SEC_BCS_ISPMODE_MASK) >> SEC_BCS_ISPMODE_SHIFT);
}

/* UKAC Bit Fields */

/**
 * @brief User Key Access Enable. Only valid under non-secure boot
 * 
 * @param pSec A pointer to the SEC registers.
 * @return true means User key can be read/programmed/erased by host CPU ,false means User key is not available for host cpu
 * */

LOCAL_INLINE bool SEC_HWA_GetUKAS(SEC_Type *const pSec)
{
    bool ret = false;
    uint8_t uake =(uint8_t)((pSec->UKAC & SEC_UKAC_UKAE_MASK) >> SEC_UKAC_UKAE_SHIFT);
    if ((uake == 0x5U) || (uake == 0xFU))
    {
        ret = true;
    }
    return ret;
}

/* BRC0 Bit Fields */
/**
 * @brief Secure Boot Disable (Value loaded from NVR sector)
 * 
 * @param pSec A pointer to the SEC registers.
 * @return  true means Secure boot mode , false means Non secure boot mode.
 */
LOCAL_INLINE bool SEC_HWA_GetSB(SEC_Type *const pSec)
{
    bool ret = false;
#if SEC_BRC0_SECURE_BOOT_DIS_MASK
    uint8_t sbdis = (uint8_t)((pSec->BRC0 & SEC_BRC0_SECURE_BOOT_DIS_MASK) >> SEC_BRC0_SECURE_BOOT_DIS_SHIFT);

    if (sbdis == 0x0u)
    {
        ret = true;
    }

#elif defined SEC_BRC0_SB_LC_EN_MASK
    uint8_t sbdis = (uint8_t)((pSec->BRC0 & SEC_BRC0_SB_LC_EN_MASK) >> SEC_BRC0_SB_LC_EN_SHIFT);

    if (sbdis == 0x0u)
    {
        ret = true;
    }

#else

#endif

    return ret;
}

/**
 * @brief Host Debug Auth Enable. Only valid in secure boot. (Value loaded from NVR sector)
 * 
 * @param pSec A pointer to the SEC registers.
 * @return  true means Host debug authentication enable. false means Host debug authentication disable.
 */
LOCAL_INLINE bool SEC_HWA_GetDEAUEn(SEC_Type *const pSec)
{
    bool ret = false;
    uint8_t dean = (uint8_t)((pSec->BRC0 & SEC_BRC0_DEBUG_AUTH_EN_MASK) >> SEC_BRC0_DEBUG_AUTH_EN_SHIFT);
    if ((dean == 0x5u) || (dean == 0xFu))
    {
        ret = true;
    }
    return ret;
}

/**
 * @brief ISP Auth Enable. Only valid in secure boot. (Value loaded from NVR sector)
 * 
 * @param pSec A pointer to the SEC registers.
 * @return  true means ISP authentication enable, false means ISP authentication disable.
 */
LOCAL_INLINE bool SEC_HWA_GetISPAU(SEC_Type *const pSec)
{
    bool ret = false;
    uint8_t isp = (uint8_t)((pSec->BRC0 & SEC_BRC0_ISP_AUTH_EN_MASK) >> SEC_BRC0_ISP_AUTH_EN_SHIFT);
    if ((isp == 0x5u) || (isp == 0xFu))
    {
        ret = true;
    }
    return ret;
}

#if SEC_BRC0_FW_READ_DIS_MASK
/**
 * @brief Firmware Read Disable/Enable. (Value loaded from NVR sector)
 * 
 * @param pSec A pointer to the SEC registers.
 * @return  true means Host core read access to firmware read is disabled, false means - Host core read access to firmware read is enabled.
 */
LOCAL_INLINE bool SEC_HWA_GetFWRE(SEC_Type *const pSec)
{
    bool ret = false;
    uint8_t fwre = (uint8_t)((pSec->BRC0 & SEC_BRC0_FW_READ_DIS_MASK) >> SEC_BRC0_FW_READ_DIS_SHIFT);
    if ((fwre == 0x5u) || (fwre == 0xFu))
    {
        ret = true;
    }
    return ret;
}
#endif

#if SEC_BRC1_FW_VALID_MASK
/* BRC1 Bit Fields */
/**
 * @brief  Get whether Flash Firmware is valid.
 * 
 * @param pSec A pointer to the SEC registers.
 * @return true means Flash Firmware is valid. false means Flash Firmware is invalid
 * */
LOCAL_INLINE bool SEC_HWA_GetFwValid(SEC_Type *const pSec)
{
    bool ret = false;
    uint8_t fw = (uint8_t)((pSec->BRC1 & SEC_BRC1_FW_VALID_MASK) >> SEC_BRC1_FW_VALID_SHIFT);
    if (fw != 0xFU)
    {
        ret = true;
    }
    return ret;
}
#endif

/**
 * @brief Get the FCUART Baud Rate for ISP
 * 
 * @param pSec A pointer to the SEC registers.
 * @return FCUART Baud Rate for ISP
 * */
LOCAL_INLINE uint8_t SEC_HWA_GetUartBR(SEC_Type *const pSec)
{
    return (uint8_t)((pSec->BRC1 & SEC_BRC1_UARTBR_MASK) >> SEC_BRC1_UARTBR_SHIFT);
}

/**
 * @brief Get CAN Baud Rate for ISP
 * 
 * @param pSec A pointer to the SEC registers.
 * @return CAN Baud Rate for ISP
 * */
LOCAL_INLINE uint8_t SEC_HWA_GetCanBR(SEC_Type *const pSec)
{
    return (uint8_t)((pSec->BRC1 & SEC_BRC1_CANBR_MASK) >> SEC_BRC1_CANBR_SHIFT);
}

/**
 * @brief Get OSC Frequency
 * 
 * @param pSec A pointer to the SEC registers.
 * @return OSC Frequency
 * */
LOCAL_INLINE uint8_t SEC_HWA_GetOSCFre(SEC_Type *const pSec)
{
    return (uint8_t)((pSec->BRC1 & SEC_BRC1_OSCFREQ_MASK) >> SEC_BRC1_OSCFREQ_SHIFT);
}

/**
 * @brief  Get whether OSC Available.
 * 
 * @param pSec A pointer to the SEC registers.
 * @return true means OSC is available. false means -OSC is not available
 * */
LOCAL_INLINE bool SEC_HWA_GetOSCAvail(SEC_Type *const pSec)
{
    bool ret = false;
    uint8_t osc = (uint8_t)((pSec->BRC1 & SEC_BRC1_OSCA_MASK) >> SEC_BRC1_OSCA_SHIFT);
    if (osc ==  0x0U)
    {
        ret = true;
    }
    return ret;
}

/**
 * @brief Get whether Debug Mailbox Backdoor Key Enable.
 * 
 * @param pSec A pointer to the SEC registers.
 * @return  true means  user can enable debug by writing debug backdoor key, false means user can  not enable debug
 * */

LOCAL_INLINE bool SEC_HWA_GetMBBKEN(SEC_Type *const pSec)
{
    bool ret = false;
#if SEC_BRC1_DBG_MB_BKD_EN_MASK
    uint8_t mbbk = (uint8_t)((pSec->BRC1 & SEC_BRC1_DBG_MB_BKD_EN_MASK) >> SEC_BRC1_DBG_MB_BKD_EN_SHIFT);
    if (mbbk ==  0x5U)
#elif SEC_BRC1_DBK_IN_EN_MASK
    uint8_t mbbk = (uint8_t)((pSec->BRC1 & SEC_BRC1_DBK_IN_EN_MASK) >> SEC_BRC1_DBK_IN_EN_SHIFT);
    if((mbbk == 0x3U) || (mbbk == 0xFU))
#else
#endif
    {
        ret = true;
    }
    return ret;
}

#if SEC_FWA_MASK
/* FWA Bit Fields */
/**
 * @brief Get the HSM Firmware Address.
 * 
 * @param pSec A pointer to the SEC registers.
 * @return the HSM Firmware Address.
 * */
LOCAL_INLINE uint32_t SEC_HWA_GetHsmAddr(SEC_Type *const pSec)
{
    return (uint32_t)(pSec->FWA & SEC_FWA_HSM_FW_ADDR_MASK);
}
#endif

/* BRC2 Bit Fields */
/**
 * @brief Get Bootloader Verification Mask
 * 
 * @param pSec A pointer to the SEC registers.
 * @return Bootloader Verification Mask.
 * */
LOCAL_INLINE uint32_t SEC_HWA_GetBLMask(SEC_Type *const pSec)
{
#if SEC_BRC2_USERCODE_VERIFY_MASK_MASK
	return (uint32_t)((pSec->BRC2 & SEC_BRC2_USERCODE_VERIFY_MASK_MASK) >> SEC_BRC2_USERCODE_VERIFY_MASK_SHIFT);
#elif SEC_BRC2_IMG_VERIFY_MASK_MASK
    return (uint32_t)((pSec->BRC2 & SEC_BRC2_IMG_VERIFY_MASK_MASK) >> SEC_BRC2_IMG_VERIFY_MASK_SHIFT);
#else
#endif
}

/**
 * @brief Get the ISP Instance Select.
 * 
 * @param pSec A pointer to the SEC registers.
 * @return  ISP Instance Select
 * */
LOCAL_INLINE uint8_t SEC_HWA_GetIspIns(SEC_Type *const pSec)
{
    return (uint8_t)((pSec->BRC2 & SEC_BRC2_ISP_INST_SEL_MASK) >> SEC_BRC2_ISP_INST_SEL_SHIFT);
}

/**
 * @brief Get Bootloader Verification Algorithm
 * 
 * @param pSec A pointer to the SEC registers.
 * @return  Bootloader Verification Algorithm
 * */
LOCAL_INLINE uint8_t SEC_HWA_GetBLVer(SEC_Type *const pSec)
{
#if SEC_BRC2_USERCODE_VERIFICATION_ALG_MASK
	return (uint8_t)((pSec->BRC2 & SEC_BRC2_USERCODE_VERIFICATION_ALG_MASK) >> SEC_BRC2_USERCODE_VERIFICATION_ALG_SHIFT);
#elif SEC_BRC2_IMG_VERIF_ALG_MASK
	return (uint8_t)((pSec->BRC2 & SEC_BRC2_IMG_VERIF_ALG_MASK) >> SEC_BRC2_IMG_VERIF_ALG_SHIFT);
#else
#endif

}

#if SEC_BRC2_DECRP_ALG_MASK
/**
 * @brief Get Debug/ISP/PREFA Authentication and USRK decryption algorithm
 * 
 * @param pSec A pointer to the SEC registers.
 * @return 1b - SM2, 0b - ECC256
 * */
LOCAL_INLINE uint8_t SEC_HWA_GetDecrypt(SEC_Type *const pSec)
{
    return (uint8_t)((pSec->BRC2 & SEC_BRC2_DECRP_ALG_MASK) >> SEC_BRC2_DECRP_ALG_SHIFT);
}
#endif

/* BTLA Bit Fields */
/**
 * @brief Get the bootloader address.
 * 
 * @param pSec A pointer to the SEC registers.
 * @return Bootloader Address.
 * */
LOCAL_INLINE uint32_t SEC_HWA_GetBLAddr(SEC_Type *const pSec)
{
    return (uint32_t)((pSec->IMGEA & SEC_IMGEA_IMAGE_ADDR_MASK) >> SEC_IMGEA_IMAGE_ADDR_SHIFT);
}

/* LCSTAT Bit Fields */
/**
 * @brief Get the life cycle  status of the chip.
 * 
 * @param pSec A pointer to the SEC registers.
 * @return The lifecycle status
 * */
LOCAL_INLINE uint8_t SEC_HWA_GetLCStaus(SEC_Type *const pSec)
{
    return (uint8_t)(pSec->LCSTAT & 0XFFU);
}

/* FAC Bit Fields */

/**
 * @brief Get the Host User Key Read Protection
 * 
 * @param pSec A pointer to the SEC registers.
 * @return true - Host read access to User Key region is enabled
 *          false - Host read access to User Key region is disabled
 * */
LOCAL_INLINE bool SEC_HWA_GetHUKRead(SEC_Type *const pSec)
{
    return (bool)(~(((pSec->FAC) & SEC_FAC_HOST_UKEY_RPROT_MASK) >> SEC_FAC_HOST_UKEY_RPROT_SHIFT));
}

/**
 * @brief Get the Host User Key write Protection
 * 
 * @param pSec A pointer to the SEC registers.
 * @return true - Host write access to User Key region is enabled
 *          false - Host write access to User Key region is disabled
 * */
LOCAL_INLINE bool SEC_HWA_GetHUKWrite(SEC_Type *const pSec)
{
    return (bool)(~(((pSec->FAC) & SEC_FAC_HOST_UKEY_WPROT_MASK) >> SEC_FAC_HOST_UKEY_WPROT_SHIFT));
}

/**
 * @brief Get the Host User Key erase Protection
 * 
 * @param pSec A pointer to the SEC registers.
 * @return true - Host erase access to User Key region is enabled
 *          false - Host erase access to User Key region is disabled
 * */
LOCAL_INLINE bool SEC_HWA_GetHUKErase(SEC_Type *const pSec)
{
    return (bool)(~(((pSec->FAC) & SEC_FAC_HOST_UKEY_EPROT_MASK) >> SEC_FAC_HOST_UKEY_EPROT_SHIFT));
}

/**
 * @brief Get the Host NVR Read Protection
 * 
 * @param pSec A pointer to the SEC registers.
 * @return true - Host read access to NVR region is enabled
 *          false - Host read access to NVR region is disabled
 * */
LOCAL_INLINE bool SEC_HWA_GetHostNvrRead(SEC_Type *const pSec)
{
    return (bool)(~(((pSec->FAC) & SEC_FAC_HOST_NVR_RPROT_MASK) >> SEC_FAC_HOST_NVR_RPROT_SHIFT));
}

/**
 * @brief Get the Host NVR write Protection
 * 
 * @param pSec A pointer to the SEC registers.
 * @return true - Host write access to NVR region is enabled
 *          false - Host write access to NVR region is disabled
 * */
LOCAL_INLINE bool SEC_HWA_GetHostNvrWrite(SEC_Type *const pSec)
{
    return (bool)(~(((pSec->FAC) & SEC_FAC_HOST_NVR_WPROT_MASK) >> SEC_FAC_HOST_NVR_WPROT_SHIFT));
}

/**
 * @brief Get the Host NVR erase Protection
 * 
 * @param pSec A pointer to the SEC registers.
 * @return true - Host erase access to NVR region is enabled
 *          false - Host erase access to NVR region is disabled
 * */
LOCAL_INLINE bool SEC_HWA_GetHostNvrErase(SEC_Type *const pSec)
{
    return (bool)(~(((pSec->FAC) & SEC_FAC_HOST_NVR_EPROT_MASK) >> SEC_FAC_HOST_NVR_EPROT_SHIFT));
}

/**
 * @brief Get the HSM User Key Erase Protection
 * 
 * @param pSec A pointer to the SEC registers.
 * @return true - HSM erase access to User Key region is enabled
 *          false -HSM erase access to User Key region is disabled
 * */
LOCAL_INLINE bool SEC_HWA_GetHsmUKErase(SEC_Type *const pSec)
{
#if SEC_FAC_HSM_UKEY_EPROT_MASK
    return (bool)(~(((pSec->FAC) & SEC_FAC_HSM_UKEY_EPROT_MASK) >> SEC_FAC_HSM_UKEY_EPROT_SHIFT));
#elif SEC_FAC_HOST_EUKEY_EPROT_MASK
    return (bool)(~(((pSec->FAC) & SEC_FAC_HOST_EUKEY_EPROT_MASK) >> SEC_FAC_HOST_EUKEY_EPROT_SHIFT));
#else

#endif
}

/**
 * @brief Get the HSM NVR Erase Protection
 * 
 * @param pSec A pointer to the SEC registers.
 * @return true - HSM erase access to NVR region is enabled
 *          false -HSM erase access to NVR region is disabled
 * */
LOCAL_INLINE bool SEC_HWA_GetHsmNvrErase(SEC_Type *const pSec)
{
    return (bool)(~(((pSec->FAC) & SEC_FAC_HSM_NVR_EPROT_MASK) >> SEC_FAC_HSM_NVR_EPROT_SHIFT));
}

/** @}*/ /* HwA_SEC */

#endif /* #if SEC_INSTANCE_COUNT > 0U */

#endif /* HWA_INCLUDE_HWA_SEC_H_ */
