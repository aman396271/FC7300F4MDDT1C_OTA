/**
 * @file HwA_cpm.h
 * @author Flagchip
 * @brief CPM register API
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
   *   0.1.0      2023-12-15     Flagchip120   N/A          First version for FC7300
   *   2.0.0      2024-10-12     Flagchip120   N/A          Change version and release
   ******************************************************************************** */

#ifndef HWA_INCLUDE_HWA_CPM_H_
#define HWA_INCLUDE_HWA_CPM_H_
#include "device_header.h"

#if CPM_INSTANCE_COUNT > 0U

/* ################################################################################## */
/* ####################################### Macro #################################### */

/** FPSCR  Bit Fields */
#define FPSCR_IOC_MASK            0x00000001U
#define FPSCR_DZC_MASK            0x00000002U
#define FPSCR_OFC_MASK            0x00000004U
#define FPSCR_UFC_MASK            0x00000008U
#define FPSCR_IXC_MASK            0x00000010U
#define FPSCR_IDC_MASK            0x00000080U
#define CPM_FPU_INTFLAGMASK       0x0000003FU

/**
 * @defgroup HwA_cpm HwA_cpm
 * @ingroup module_driver_cpm
 * @{
 */

/**
 * @brief Get the value of CPM FISCR.
 *
 * This function returns FISCR value.
 *
 * @param pCpm the base address of the CPM instance.
 * @return uint32_t the value of the FISCR register.
 */
LOCAL_INLINE uint32_t CPM_HWA_GetFiscr(CPM_Type *const pCpm)
{
    uint32_t u32TmpVal = pCpm->FISCR;
#if (CPM_ERRATA == STD_ON)
    __asm volatile(
        "dmb                            \n"
        "ldr r8, [%[TCMRCR]]			\n"/* Must Read 0xE0080020 after set or read CPM register. */
        : : [TCMRCR] "r"(&pCpm->TCMRCR) : "r8", "memory"
    );
#endif
    return u32TmpVal;
}

/**
 * @brief Return CPM_FISCR FIOC value
 *
 * @param pCpm the base address of the CPM instance.
 * @return 0: No interrupt; 1: Interrupt occurred
 */
LOCAL_INLINE bool CPM_HWA_GetFpuFiocFlag(CPM_Type *const pCpm)
{
    uint32_t u32TmpVal = pCpm->FISCR;
#if (CPM_ERRATA == STD_ON)
    __asm volatile(
        "dmb                            \n"
        "ldr r8, [%[TCMRCR]]			\n"/* Must Read 0xE0080020 after set or read CPM register. */
        : : [TCMRCR] "r"(&pCpm->TCMRCR) : "r8", "memory"
    );
#endif
    u32TmpVal = (u32TmpVal & CPM_FISCR_FIOC_MASK) >> CPM_FISCR_FIOC_SHIFT;
    return (bool)((u32TmpVal != 0U) ? true : false);
}

/**
 * @brief Return CPM_FISCR FDZC value
 *
 * @param pCpm the base address of the CPM instance.
 * @return 0: No interrupt; 1: Interrupt occurred
 */
LOCAL_INLINE bool CPM_HWA_GetFpuFdzcFlag(CPM_Type *const pCpm)
{
    uint32_t u32TmpVal = pCpm->FISCR;
#if (CPM_ERRATA == STD_ON)
    __asm volatile(
        "dmb                            \n"
        "ldr r8, [%[TCMRCR]]			\n"/* Must Read 0xE0080020 after set or read CPM register. */
        : : [TCMRCR] "r"(&pCpm->TCMRCR) : "r8", "memory"
    ); 
#endif
    u32TmpVal = (u32TmpVal & CPM_FISCR_FDZC_MASK) >> CPM_FISCR_FDZC_SHIFT;
    return (bool)((u32TmpVal != 0U) ? true : false);
}

/**
 * @brief Return CPM_FISCR FOFC value
 *
 * @param pCpm the base address of the CPM instance.
 * @return 0: No interrupt; 1: Interrupt occurred
 */
LOCAL_INLINE bool CPM_HWA_GetFpuFofcFlag(CPM_Type *const pCpm)
{
    uint32_t u32TmpVal = pCpm->FISCR;
#if (CPM_ERRATA == STD_ON)
    __asm volatile(
        "dmb                            \n"
        "ldr r8, [%[TCMRCR]]			\n"/* Must Read 0xE0080020 after set or read CPM register. */
        : : [TCMRCR] "r"(&pCpm->TCMRCR) : "r8", "memory"
    );
#endif
    u32TmpVal = (u32TmpVal & CPM_FISCR_FOFC_MASK) >> CPM_FISCR_FOFC_SHIFT;
    return (bool)((u32TmpVal != 0U) ? true : false);
}

/**
 * @brief Return CPM_FISCR FUFC value
 *
 * @param pCpm the base address of the CPM instance.
 * @return 0: No interrupt; 1: Interrupt occurred
 */
LOCAL_INLINE bool CPM_HWA_GetFpuFufcFlag(CPM_Type *const pCpm)
{
    uint32_t u32TmpVal = pCpm->FISCR;
#if (CPM_ERRATA == STD_ON)
    __asm volatile(
        "dmb                            \n"
        "ldr r8, [%[TCMRCR]]			\n"/* Must Read 0xE0080020 after set or read CPM register. */
        : : [TCMRCR] "r"(&pCpm->TCMRCR) : "r8", "memory"
    );  
#endif
    u32TmpVal = (u32TmpVal & CPM_FISCR_FUFC_MASK) >> CPM_FISCR_FUFC_SHIFT;
    return (bool)((u32TmpVal != 0U) ? true : false);
}

/**
 * @brief Return CPM_FISCR FIXC value
 *
 * @param pCpm the base address of the CPM instance.
 * @return 0: No interrupt; 1: Interrupt occurred
 */
LOCAL_INLINE bool CPM_HWA_GetFpuFixcFlag(CPM_Type *const pCpm)
{
    uint32_t u32TmpVal = pCpm->FISCR;
#if (CPM_ERRATA == STD_ON)
    __asm volatile(
        "dmb                            \n"
        "ldr r8, [%[TCMRCR]]			\n"/* Must Read 0xE0080020 after set or read CPM register. */
        : : [TCMRCR] "r"(&pCpm->TCMRCR) : "r8", "memory"
    ); 
#endif
    u32TmpVal = (u32TmpVal & CPM_FISCR_FIXC_MASK) >> CPM_FISCR_FIXC_SHIFT;
    return (bool)((u32TmpVal != 0U) ? true : false);
}

/**
 * @brief Return CPM_FISCR FIDC value
 *
 * @param pCpm the base address of the CPM instance.
 * @return 0: No interrupt; 1: Interrupt occurred
 */
LOCAL_INLINE bool CPM_HWA_GetFpuFidcFlag(CPM_Type *const pCpm)
{
    uint32_t u32TmpVal = pCpm->FISCR;
#if (CPM_ERRATA == STD_ON)
    __asm volatile(
        "dmb                            \n"
        "ldr r8, [%[TCMRCR]]			\n"/* Must Read 0xE0080020 after set or read CPM register. */
        : : [TCMRCR] "r"(&pCpm->TCMRCR) : "r8", "memory"
    );  
#endif
    u32TmpVal = (u32TmpVal & CPM_FISCR_FIDC_MASK) >> CPM_FISCR_FIDC_SHIFT;
    return (bool)((u32TmpVal != 0U) ? true : false);
}

/**
 * @brief Set FIOCE interrupt
 *
 * @param pCpm the base address of the CPM instance.
 * @param bEnable 1: enable interrupt 0: disable interrupt
 */
LOCAL_INLINE void CPM_HWA_SetFioceInt(CPM_Type *const pCpm, bool bEnable)
{
    pCpm->FISCR = ((pCpm->FISCR & (~CPM_FISCR_FIOCE_MASK)) | ((uint32_t)(bEnable ? 1U : 0U) << CPM_FISCR_FIOCE_SHIFT));
#if (CPM_ERRATA == STD_ON)
    __asm volatile(
        "dmb                            \n"
        "ldr r8, [%[TCMRCR]]			\n"/* Must Read 0xE0080020 after set or read CPM register. */
        : : [TCMRCR] "r"(&pCpm->TCMRCR) : "r8", "memory"
    ); 
#endif
}

/**
 * @brief Set FDZCE interrupt
 *
 * @param pCpm the base address of the CPM instance.
 * @param bEnable 1: enable interrupt 0: disable interrupt
 */
LOCAL_INLINE void CPM_HWA_SetFdzceInt(CPM_Type *const pCpm, bool bEnable)
{
    pCpm->FISCR = ((pCpm->FISCR & (~CPM_FISCR_FDZCE_MASK)) | ((uint32_t)(bEnable ? 1U : 0U) << CPM_FISCR_FDZCE_SHIFT));
#if (CPM_ERRATA == STD_ON)
    __asm volatile(
        "dmb                            \n"
        "ldr r8, [%[TCMRCR]]			\n"/* Must Read 0xE0080020 after set or read CPM register. */
        : : [TCMRCR] "r"(&pCpm->TCMRCR) : "r8", "memory"
    );
#endif
}

/**
 * @brief Set FOFCE interrupt
 *
 * @param pCpm the base address of the CPM instance.
 * @param bEnable 1: enable interrupt 0: disable interrupt
 */
LOCAL_INLINE void CPM_HWA_SetFofceInt(CPM_Type *const pCpm, bool bEnable)
{
    pCpm->FISCR = ((pCpm->FISCR & (~CPM_FISCR_FOFCE_MASK)) | ((uint32_t)(bEnable ? 1U : 0U) << CPM_FISCR_FOFCE_SHIFT));
#if (CPM_ERRATA == STD_ON)
    __asm volatile(
        "dmb                            \n"
        "ldr r8, [%[TCMRCR]]			\n"/* Must Read 0xE0080020 after set or read CPM register. */
        : : [TCMRCR] "r"(&pCpm->TCMRCR) : "r8", "memory"
    );  
#endif
}

/**
 * @brief Set FUFCE interrupt
 *
 * @param pCpm the base address of the CPM instance.
 * @param bEnable 1: enable interrupt 0: disable interrupt
 */
LOCAL_INLINE void CPM_HWA_SetFufceInt(CPM_Type *const pCpm, bool bEnable)
{
    pCpm->FISCR = ((pCpm->FISCR & (~CPM_FISCR_FUFCE_MASK)) | ((uint32_t)(bEnable ? 1U : 0U) << CPM_FISCR_FUFCE_SHIFT));
#if (CPM_ERRATA == STD_ON)
    __asm volatile(
        "dmb                            \n"
        "ldr r8, [%[TCMRCR]]			\n"/* Must Read 0xE0080020 after set or read CPM register. */
        : : [TCMRCR] "r"(&pCpm->TCMRCR) : "r8", "memory"
    );
#endif
}

/**
 * @brief Set FIXCE interrupt
 *
 * @param pCpm the base address of the CPM instance.
 * @param bEnable 1: enable interrupt 0: disable interrupt
 */
LOCAL_INLINE void CPM_HWA_SetFixceInt(CPM_Type *const pCpm, bool bEnable)
{
    pCpm->FISCR = ((pCpm->FISCR & (~CPM_FISCR_FIXCE_MASK)) | ((uint32_t)(bEnable ? 1U : 0U) << CPM_FISCR_FIXCE_SHIFT));
#if (CPM_ERRATA == STD_ON)
    __asm volatile(
        "dmb                            \n"
        "ldr r8, [%[TCMRCR]]			\n"/* Must Read 0xE0080020 after set or read CPM register. */
        : : [TCMRCR] "r"(&pCpm->TCMRCR) : "r8", "memory"
    );
#endif
}

/**
 * @brief Set FIDCE interrupt
 *
 * @param pCpm the base address of the CPM instance.
 * @param bEnable 1: enable interrupt 0: disable interrupt
 */
LOCAL_INLINE void CPM_HWA_SetFidceInt(CPM_Type *const pCpm, bool bEnable)
{
    pCpm->FISCR = ((pCpm->FISCR & (~CPM_FISCR_FIDCE_MASK)) | ((uint32_t)(bEnable ? 1U : 0U) << CPM_FISCR_FIDCE_SHIFT));
#if (CPM_ERRATA == STD_ON)
    __asm volatile(
        "dmb                            \n"
        "ldr r8, [%[TCMRCR]]			\n"/* Must Read 0xE0080020 after set or read CPM register. */
        : : [TCMRCR] "r"(&pCpm->TCMRCR) : "r8", "memory"
    );
#endif
}

/**
 * @brief Set FISCR value
 *
 * @param pCpm the base address of the CPM instance.
 * @param u32Val the value want to set the register
 */
LOCAL_INLINE void CPM_HWA_SetFiscr(CPM_Type *const pCpm, uint32_t u32Val)
{
    pCpm->FISCR = u32Val;
#if (CPM_ERRATA == STD_ON)
    __asm volatile(
        "dmb                            \n"
        "ldr r8, [%[TCMRCR]]			\n"/* Must Read 0xE0080020 after set or read CPM register. */
        : : [TCMRCR] "r"(&pCpm->TCMRCR) : "r8", "memory"
    );   
#endif
}

#if (CPM_CONTAIN_CPUID == STD_ON)
/**
 * @brief Return CPM_CoreID value
 *
 * @param pCpm the base address of the CPM instance.
 * @return uint32_t the core ID value
 */
LOCAL_INLINE uint32_t CPM_HWA_GetCoreIDValve(CPM_Type *const pCpm)
{
    uint32_t u32TmpVal = pCpm->MISCR;
#if (CPM_ERRATA == STD_ON)
    __asm volatile(
        "dmb                            \n"
        "ldr r8, [%[TCMRCR]]			\n"/* Must Read 0xE0080020 after set or read CPM register. */
        : : [TCMRCR] "r"(&pCpm->TCMRCR) : "r8", "memory"
    ); 
#endif 
    u32TmpVal = (u32TmpVal & CPM_MISCR_CPU_ID_MASK) >> CPM_MISCR_CPU_ID_SHIFT;
    return (uint32_t)u32TmpVal;
}
#endif

/** @}*/

#endif

#endif /* HWA_INCLUDE_HWA_CPM_H_ */
