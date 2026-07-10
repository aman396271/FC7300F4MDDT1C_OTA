 /* @file module_driver_cpm.c
 * @author Flagchip
 * @brief CPM driver type definition and API
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
  *   2.0.0       2024-8-26     Flagchip120   N/A          Release version for FC7300
  ******************************************************************************** */
#include "module_driver_cpm.h"

#include "module_driver_fcuart.h"

#if CPM_INSTANCE_COUNT > 0U

static CPM_Type * const s_pCpmBasePtrs[CPM_INSTANCE_COUNT] = CPM_BASE_PTRS;

/* ################################################################################## */
/* ########################### Local Prototype Functions ############################ */

/* ################################################################################## */
/* ################################ Global Functions ################################ */
/**
 *
 * @brief Configures the CPM module interrupts.
 *
 * This function configures the CPM module interrupts to enable/disable various interrupt sources.
 *
 * @param pCpmHandle CPM handle
 * @param eIntSrc CPM FPU interrupt type. refer CPM FISCR register
 * @param bEnable 1: interrupt enable, 0:interrupt disable.
 */
void CPM_FpuIntMode(CPM_HandleType* pCpmHandle, FPU_IntType eIntSrc, bool bEnable)
{
    CPM_Type * const pCpm = s_pCpmBasePtrs[pCpmHandle->eInstance];
    switch (eIntSrc)
    {
        case CPM_FPU_FIO:
            CPM_HWA_SetFioceInt(pCpm, bEnable);
            break;
        case CPM_FPU_FDZ:
            CPM_HWA_SetFdzceInt(pCpm, bEnable);
            break;
        case CPM_FPU_FOF:
            CPM_HWA_SetFofceInt(pCpm, bEnable);
            break;
        case CPM_FPU_FUF:
            CPM_HWA_SetFufceInt(pCpm, bEnable);
            break;
        case CPM_FPU_FIX:
            CPM_HWA_SetFixceInt(pCpm, bEnable);
            break;
        case CPM_FPU_FID:
            CPM_HWA_SetFidceInt(pCpm, bEnable);
            break;
        default :
            /* Invalid parameter: return */
            break;
    }
}

/**
 * @brief Get CPM Interrupt occurred flag
 *
 *  This function returns the interrupt flag.
 *
 * @param pCpmHandle CPM handle
 * @param eIntSrc CPM FPU interrupt type. refer CPM FISCR register
 * @return true interrupt occurred
 * @return false No interrupt
 */
bool CPM_GetFpuIntStatus(CPM_HandleType* pCpmHandle, FPU_IntType eIntSrc)
{
    CPM_Type * const pCpm = s_pCpmBasePtrs[pCpmHandle->eInstance];
    bool bRetVal = false;
    switch(eIntSrc){
    case CPM_FPU_FIO:
        bRetVal = CPM_HWA_GetFpuFiocFlag(pCpm);
        break;
    case CPM_FPU_FDZ:
        bRetVal = CPM_HWA_GetFpuFdzcFlag(pCpm);
        break;
    case CPM_FPU_FOF:
        bRetVal = CPM_HWA_GetFpuFofcFlag(pCpm);
        break;
    case CPM_FPU_FUF:
        bRetVal = CPM_HWA_GetFpuFufcFlag(pCpm);
        break;
    case CPM_FPU_FIX:
        bRetVal = CPM_HWA_GetFpuFixcFlag(pCpm);
        break;
    case CPM_FPU_FID:
        bRetVal = CPM_HWA_GetFpuFidcFlag(pCpm);
        break;
    default:
        break;

    }
    return bRetVal;
}


#ifdef FPU_USED_ENABLE
/**
 * @brief CPM_Read_FPSCR
 * Return the current value of FPSCR
 * @return u32RetVal 
 */
uint32_t CPM_Read_FPSCR(void)
{
    uint32_t u32RetVal = 0U;
    __asm(
            "vmrs %0, fpscr" : "=r" (u32RetVal)
    );
    return u32RetVal;
}

/**
 * @brief CPM_Write_FPSCR
 * 
 * @param u32SetVal set the value for FPSCR 
 */
void CPM_Write_FPSCR(uint32_t u32SetVal)
{
        __asm(
                "vmsr fpscr, %0" : : "r" (u32SetVal)
        );
}

/**
 * @brief Deinit Cpm set interrupt
 *
 * Restore the Cpm FISCR to its reset state
 * 
 * @param pCpmHandle CPM handle
 */
void CPM_DeInitInterrupt(CPM_HandleType* pCpmHandle)
{
	CPM_Type * const pCpm = s_pCpmBasePtrs[pCpmHandle->eInstance];
	uint32_t u32RetVal;
    CPM_HWA_SetFiscr(pCpm, 0x0U);
    u32RetVal = CPM_Read_FPSCR();
    /* Clear FPSCR IDC/IXC/UFC/OPF/DZC/IOC flag*/
    u32RetVal &=0xFFFFFF90u;
    CPM_Write_FPSCR(u32RetVal);
}
#endif



/**
 * @brief Cpm set interrupt
 *
 * @param pCpmHandle CPM handle
 * @param pIntStruct interrupt structure pointer
 * @return Cpm return type
 */
CPM_RetType CPM_InitInterrupt(CPM_HandleType* pCpmHandle, const CPM_InterruptType *pIntStruct)
{
    CPM_RetType eRet = CPM_STATUS_SUCCESS;
    if(NULL == pIntStruct)
    {
        eRet = CPM_STATUS_PARAM_INVALID;
    }
    else
    {
        if(pIntStruct->u8CpmEnable != 0U)
        {
            if(((uint32_t)(pIntStruct->eFPU_IntType) & CPM_FISCR_FIOC_MASK) == CPM_FPU_FIO)
            {
                CPM_FpuIntMode(pCpmHandle, CPM_FPU_FIO,true);
            }
            if(((uint32_t)(pIntStruct->eFPU_IntType) & CPM_FISCR_FDZC_MASK) == CPM_FPU_FDZ)
            {
               	CPM_FpuIntMode(pCpmHandle, CPM_FPU_FDZ,true);
            }
            if(((uint32_t)(pIntStruct->eFPU_IntType) & CPM_FISCR_FUFC_MASK) == CPM_FPU_FUF)
            {
               	CPM_FpuIntMode(pCpmHandle, CPM_FPU_FUF,true);
            }
            if(((uint32_t)(pIntStruct->eFPU_IntType) & CPM_FISCR_FOFC_MASK) == CPM_FPU_FOF)
            {
              	CPM_FpuIntMode(pCpmHandle, CPM_FPU_FOF,true);
            }
            if(((uint32_t)(pIntStruct->eFPU_IntType) & CPM_FISCR_FIDC_MASK) == CPM_FPU_FID)
            {
                CPM_FpuIntMode(pCpmHandle, CPM_FPU_FID,true);
            }
            if(((uint32_t)(pIntStruct->eFPU_IntType) & CPM_FISCR_FIXC_MASK) == CPM_FPU_FIX)
            {
                CPM_FpuIntMode(pCpmHandle, CPM_FPU_FIX,true);
            }
        }
            pCpmHandle->tSettings.pCpmCallback = pIntStruct->pIsrNotify;
    }
    return eRet;
}

#if (CPM_CONTAIN_CPUID == STD_ON)
uint32_t CPM_MiscrGetCoreMode(CPM_HandleType* pCpmHandle)
{
    CPM_Type * const pCpm = s_pCpmBasePtrs[pCpmHandle->eInstance];
    return CPM_HWA_GetCoreIDValve(pCpm);
}
#endif

/**
 * @brief Gets the value of the FIscr register.
 * 
 * This function retrieves the value of the FIscr register using the provided CPM module handle.
 * The FIscr register contains status information about interrupts and exceptions within the CPM module.
 * Reading this register's value provides insight into the current state of interrupts and exceptions.
 * 
 * @param pCpmHandle Pointer to the CPM module handle. This handle identifies the CPM instance to be accessed.
 * @return uint32_t The value of the FIscr register.
 */
uint32_t CPM_GetFiscr(CPM_HandleType* pCpmHandle)
{
    CPM_Type * const pCpm = s_pCpmBasePtrs[pCpmHandle->eInstance];
    return CPM_HWA_GetFiscr(pCpm);    
}

/**
 * @brief CPM interrupt function
 * 
 * @param pCpmHandle CPM handle
 */
void CPM_CommonProcessInterrupt(CPM_HandleType* pCpmHandle)
{
    if(pCpmHandle->tSettings.pCpmCallback != NULL)
    {
    	pCpmHandle->tSettings.pCpmCallback(pCpmHandle);
    }
}

#endif
