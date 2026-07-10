/**
 * @file module_driver_cpm.h
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
   *   0.1.0       2023-12-15    Flagchip120   N/A          First version for FC7300
   *   2.0.0       2024-10-12    Flagchip120   N/A          Change version and release
   ******************************************************************************** */
#ifndef _DRIVER_MODULE_DRIVER_CPM_H_
#define _DRIVER_MODULE_DRIVER_CPM_H_
#include "device_header.h"
#include "HwA_cpm.h"

#if CPM_INSTANCE_COUNT > 0U

#if defined(__cplusplus)
extern "C" {
#endif

/**
 * @addtogroup module_driver_cpm
 * @{
 */

/** @brief Cpm return type. */

typedef enum
{
    CPM_STATUS_SUCCESS = 0U,          /*!< CPM status success */
    CPM_STATUS_PARAM_INVALID = 1U     /*!< CPM status parameter invalid */
} CPM_RetType;

/**
 * @brief FPU INTERRUPT type.
 *
 * This provides constants for FPU interrupt type for use in the FPU functions.
 * Please refer to Reference Manual chapter 14 CPM, it introduce register FISCR for details.
 *
 */
typedef enum
{
    CPM_FPU_FIO = 1U,         /*!< in function CPM_FpuIntMode, set CPM_FISCR FIOCE bit; in function CPM_GetFpuIntStatus, get CPM_FISCR FIOC Status*/
    CPM_FPU_FDZ = 2U,         /*!< in function CPM_FpuIntMode, set CPM_FISCR FDZCE bit; in function CPM_GetFpuIntStatus, get CPM_FISCR FDZC Status*/
    CPM_FPU_FUF = 4U,         /*!< in function CPM_FpuIntMode, set CPM_FISCR FUFCE bit; in function CPM_GetFpuIntStatus, get CPM_FISCR FUFC Status*/
    CPM_FPU_FOF = 8U,         /*!< in function CPM_FpuIntMode, set CPM_FISCR FOFCE bit; in function CPM_GetFpuIntStatus, get CPM_FISCR FOFC Status*/
    CPM_FPU_FID = 16U,        /*!< in function CPM_FpuIntMode, set CPM_FISCR FIDCE bit; in function CPM_GetFpuIntStatus, get CPM_FISCR FIDC Status*/
    CPM_FPU_FIX = 32U         /*!< in function CPM_FpuIntMode, set CPM_FISCR FIXCE bit; in function CPM_GetFpuIntStatus, get CPM_FISCR FIXC Status*/
} FPU_IntType;

typedef enum
{
    CPM_MISCR_CPUCORE0 = 1U,
    CPM_MISCR_CPUCORE1 = 2U,
    CPM_MISCR_CPUCORE2 = 4U,
    CPM_MISCR_HSM = 8U
} CPM_MISCRCoreActiveType;

/**
 * @brief The instance index of the CPM peripheral
 *
 */
typedef enum
{
	CPM_INSTANCE_0 = 0U
} CPM_InstanceType;


/**
 * @brief The structure of the CPM processing handle
 *
 */
typedef struct _CPM_HandleType
{
	CPM_InstanceType eInstance;		/*!< CPM instance*/
	char _aligned[3];
	struct
	{
		void (*pCpmCallback)(struct _CPM_HandleType *pHandle);		/*!< fault interrupt callback */
	} tSettings;
} CPM_HandleType;


/** @brief Cpm interrupt configuration type */
typedef struct
{
    uint8_t u8CpmEnable;                    /**< whether enable cpm interrupt */
    FPU_IntType eFPU_IntType;                    /**< the type of interrupt */
    void (*pIsrNotify)(CPM_HandleType *pHandle);       /**< Cpm interrupt notification function pointer */
} CPM_InterruptType;


#ifdef FPU_USED_ENABLE
/**
 * @brief CPM_Read_FPSCR
 * Return the current value of FPSCR
 * @return u32RetVal
 */
uint32_t CPM_Read_FPSCR(void);

/**
 * @brief CPM_Write_FPSCR
 *
 * @param u32SetVal set the value for FPSCR
 */
void CPM_Write_FPSCR(uint32_t u32SetVal);

/**
 * @brief Deinit Cpm set interrupt
 *
 * Restore the Cpm FISCR to its reset state
 * 
 * @param pCpmHandle CPM handle
 */
void CPM_DeInitInterrupt(CPM_HandleType* pCpmHandle);

#endif



/* ----------------------------------------------------------------------------
   --   Global Api
   ---------------------------------------------------------------------------- */
/**
 * @brief Configures the CPM module interrupts.
 *
 * This function configures the CPM module interrupts to enable/disable various interrupt sources.
 *
 * @param pCpmHandle CPM handle
 * @param eIntSrc CPM FPU interrupt type. refer CPM FISCR register
 * @param bEnable true: interrupt enable, false:interrupt disable.
 */
void CPM_FpuIntMode(CPM_HandleType* pCpmHandle, FPU_IntType eIntSrc, bool bEnable);

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
bool CPM_GetFpuIntStatus(CPM_HandleType* pCpmHandle, FPU_IntType eIntSrc);

#if (CPM_CONTAIN_CPUID == STD_ON)
/**
 * @brief Get core mode
 *
 *  This function returns the interrupt flag.
 *
 * @return the value of core
 */
uint32_t CPM_MiscrGetCoreMode(CPM_HandleType* pCpmHandle);
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
uint32_t CPM_GetFiscr(CPM_HandleType* pCpmHandle);
/**
 * @brief Cpm set interrupt
 *
 * @param pCpmHandle CPM handle
 * @param pIntStruct interrupt structure pointer
 * @return Cpm return type
 */
CPM_RetType CPM_InitInterrupt(CPM_HandleType* pCpmHandle, const CPM_InterruptType *pIntStruct);

/**
 * @brief CPM interrupt function
 * 
 * @param pCpmHandle CPM handle
 */
void CPM_CommonProcessInterrupt(CPM_HandleType* pCpmHandle);

#if defined(__cplusplus)
}
#endif

#endif

/** @}*/ /* module_driver_cpm */
#endif
