/**
 * @file module_driver_mam.c
 * @author Flagchip
 * @brief MAM driver source code
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
 *   0.1.0       2023-02-08    Flagchip054   N/A          First version for FC7300
 *   2.5.0       2025-08-20    Flagchip0100  N/A          Add FC7300F4MDDxxxT1C support
 ******************************************************************************** */

#include "module_driver_mam.h"

#if MAM_INSTANCE_COUNT > 0U

/**
 * @struct MAM_Inf_Type
 * @brief Matrix Access Monitor Information Structure
 */
typedef struct
{
    uint16_t error;
    uint16_t mam_num;
    uint32_t block_num;
} MAM_Inf_Type;

/**
 * @struct MAM_Block_Region_Type
 * @brief Matrix Access Monitor Block Region Configuration Structure
 */
typedef struct
{
    uint32_t start_addr;
    uint32_t end_addr;
    uint32_t block_size;
    uint16_t block_base;
    uint16_t mam_idx;
} MAM_Block_Region_Type;

static MAM_Type *const s_apMamBase[MAM_INSTANCE_COUNT] = MAM_BASE_PTRS;
static const uint32_t s_u32MamAcr[MAM_INSTANCE_COUNT] = MAM_ACR_OFFSET;
static const MAM_Block_Region_Type block_region[MAM_BLOCK_REGION_MAX] = {MAM_BLOCK_REGION};

/**
 * @brief Get MAM information for a given memory address
 * 
 * This function searches through all configured memory regions to determine
 * which MAM instance and block number corresponds to the specified address.
 * 
 * @param u32Addr Memory address to lookup (32-bit physical address)
 * 
 * @return MAM_Inf_Type Structure containing:
 *         - error: 0 if address found in valid region, 1 if not found
 *         - mam_num: MAM instance index responsible for the address
 *         - block_num: Calculated block number within the MAM instance
 */
static MAM_Inf_Type MAM_GetMamInf(uint32_t u32Addr);

/*************** Local Functions ***************/
/**
 * @brief Get MAM information for a given memory address
 * 
 * This function searches through all configured memory regions to determine
 * which MAM instance and block number corresponds to the specified address.
 * 
 * @param u32Addr Memory address to lookup (32-bit physical address)
 * 
 * @return MAM_Inf_Type Structure containing:
 *         - error: 0 if address found in valid region, 1 if not found
 *         - mam_num: MAM instance index responsible for the address
 *         - block_num: Calculated block number within the MAM instance
 */
static MAM_Inf_Type MAM_GetMamInf(uint32_t u32Addr)
{
    uint32_t u32AddrOffset;
    uint32_t u32LoopI;
    MAM_Inf_Type inf = { .error = 1 };

    for (u32LoopI = 0u; u32LoopI < MAM_BLOCK_REGION_MAX; ++u32LoopI)
    {
        if ((block_region[u32LoopI].start_addr <= u32Addr) &&
            (u32Addr <= block_region[u32LoopI].end_addr))
        {
            u32AddrOffset = u32Addr - block_region[u32LoopI].start_addr;
            inf.error     = 0;
            inf.mam_num   = block_region[u32LoopI].mam_idx;
            inf.block_num = (u32AddrOffset >> block_region[u32LoopI].block_size) + block_region[u32LoopI].block_base;

            break;
        }
    }

    return inf;
}

#ifdef MAM_SOFT_RESET_SUPPORT
/*****************  Global Functions *******************/
/**
 * @brief Perform software reset of the specified Matrix Access Monitor instance
 * 
 * This function resets the Matrix Access Monitor (MAM) hardware to its default
 * state by toggling the matrix configuration bit. The reset clears all MAM
 * configuration registers and monitoring states.
 * 
 * @param eMam MAM instance index to reset (MAM_INDEX_0, MAM_INDEX_1, etc.)
 */
void MAM_Reset(MAM_Index_Type eMam)
{
    MAM_Type *const pMam = s_apMamBase[(uint32_t)eMam];

    Mam_HWA_SetMatrixCfg(pMam, 0x01U);
    DSB();
    Mam_HWA_SetMatrixCfg(pMam, 0x00U);
    DSB();
}
#endif

/**
 * @brief Enable watchdog for a specific master on the Matrix Access Monitor
 * 
 * This function configures and enables the watchdog timer for a specified master
 * interface on the MAM. The watchdog monitors access violations and can generate
 * interrupts or system resets on timeout.
 * 
 * @param eMam MAM instance index (MAM_INDEX_0, MAM_INDEX_1, etc.)
 * @param eMaster Master interface to monitor (MAM_MASTER_0, MAM_MASTER_1, etc.)
 * @param eWdgTo Watchdog timeout value selection
 * @param eWdgDiv Watchdog clock divider ratio
 */
void MAM_WdogEnable(MAM_Index_Type eMam, MAM_Master_Type eMaster, MAM_Wdog_Timeout_Type eWdgTo, MAM_Wdog_Div_Type eWdgDiv)
{
    uint32_t     regval  = 0U;
    uint32_t     bit_idx = 0U;
    MAM_Type *const pMam = s_apMamBase[(uint32_t)eMam];

#ifdef MAM_WDOG_DIV_SUPPORT
    bit_idx = (uint32_t)eMaster << 2;
    regval = Mam_HWA_GetWdgDiv(pMam);
    regval = (regval & ~(0xFUL << bit_idx)) | ((uint32_t)eWdgDiv << bit_idx);
    Mam_HWA_SetWdgDiv(pMam, regval);
#else
    regval = ((uint32_t)eWdgDiv << bit_idx);
#endif

    bit_idx = (uint32_t)eMaster << 1;
    regval = Mam_HWA_GetWdgToCr(pMam);
    regval = (regval & ~(0x3UL << bit_idx)) | ((uint32_t)eWdgTo << bit_idx);
    Mam_HWA_SetWdgToCr(pMam, regval);

    bit_idx = (uint32_t)eMaster;
    regval = Mam_HWA_GetWdgCr(pMam);
    regval |= 1UL << bit_idx;
    Mam_HWA_SetWdgCr(pMam, regval);
}

/**
 * @brief Disable watchdog for a specific master on the Matrix Access Monitor
 * 
 * This function disables the watchdog timer for a specified master interface
 * on the MAM, preventing further access violation monitoring for that master.
 * 
 * @param eMam MAM instance index (MAM_INDEX_0, MAM_INDEX_1, etc.)
 * @param eMaster Master interface to disable watchdog for (MAM_MASTER_0, MAM_MASTER_1, etc.)
 */
void MAM_WdogDisable(MAM_Index_Type eMam, MAM_Master_Type eMaster)
{
    uint32_t     regval  = 0U;
    uint32_t     bit_idx = 0U;
    MAM_Type *const pMam = s_apMamBase[(uint32_t)eMam];

    bit_idx = (uint32_t)eMaster;
    regval = Mam_HWA_GetWdgCr(pMam);
    regval &= ~(1UL << bit_idx);
    Mam_HWA_SetWdgCr(pMam, regval);
}

/**
 * @brief Configure access control for a specific memory address and master
 * 
 * This function sets the access control permissions for a memory block
 * corresponding to the specified address for a particular master interface.
 * The configuration determines what type of access (read/write) is allowed.
 * 
 * @param eMaster Master interface to configure (MAM_MASTER_0, MAM_MASTER_1, etc.)
 * @param u32Addr Memory address within the block to configure
 * @param u32Val Access control value (4-bit field) to set
 *               Typically defines read/write permissions for the master
 * 
 * @return uint8_t Status code:
 *         - 0: Configuration successful
 *         - 1: Error - address not found in any configured MAM region
 */
uint8_t MAM_Config(MAM_Master_Type eMaster, uint32_t u32Addr, uint32_t u32Val)
{
    MAM_Inf_Type inf     = MAM_GetMamInf(u32Addr);
    MAM_Type *pMam;
    uint32_t     reg_idx = 0U;
    uint32_t     bit_idx = 0U;
    uint32_t     regval  = 0U;
    uint8_t      status  = 0U;

    if (inf.error == 1U)
    {
        status = 1U;
    }
    else
    {
        pMam = s_apMamBase[inf.mam_num];

        reg_idx = (inf.block_num >> 3U) + s_u32MamAcr[inf.mam_num] * (uint32_t)eMaster;
        bit_idx = (inf.block_num & 0x7U) << 2;
        regval = Mam_HWA_Get_ACR(pMam, reg_idx);
        regval = (regval & ~(0xFUL << bit_idx)) | (u32Val << bit_idx);
        Mam_HWA_Set_ACR(pMam, reg_idx, regval);
    }
    return status;
}

/**
 * @brief Lock access control configuration for a specific memory block
 * 
 * This function sets the lock bit for the memory block containing the specified
 * address, preventing further modifications to its access control configuration.
 * Once locked, the access permissions cannot be changed until system reset.
 * 
 * @param u32Addr Memory address within the block to lock
 * 
 * @return uint8_t Status code:
 *         - 0: Lock operation successful
 *         - 1: Error - address not found in any configured MAM region
 */
uint8_t MAM_ConfigLock(uint32_t u32Addr)
{
    MAM_Inf_Type inf     = MAM_GetMamInf(u32Addr);
    MAM_Type *pMam;
    uint32_t     reg_idx = 0U;
    uint32_t     bit_idx = 0U;
    uint32_t     regval  = 0U;
    uint8_t      status  = 0U;

    if (inf.error == 1U)
    {
        status = 1U;
    }
    else
    {
        pMam = s_apMamBase[inf.mam_num];

        reg_idx = (inf.block_num >> 5U);
        bit_idx = inf.block_num & 0x1FU;
        regval = Mam_HWA_Get_ACLR(pMam, reg_idx);
        regval |= 1UL << bit_idx;
        Mam_HWA_Set_ACLR(pMam, reg_idx, regval);
    }

    return status;
}

#ifdef MAM_PORT_MONITOR_SUPPORT
/**
 * @brief Enable monitoring for a specific port on the Matrix Access Monitor
 * 
 * This function enables access monitoring for a specified port interface
 * on the MAM. When enabled, the MAM will track and report access events
 * through the specified monitor port.
 * 
 * @param eMam MAM instance index (MAM_INDEX_0, MAM_INDEX_1, etc.)
 * @param eMonitor Monitor port to enable (MAM_MONITOR_0, MAM_MONITOR_1, etc.)
 */
void MAM_MonitorEnable(MAM_Index_Type eMam, MAM_Monitor_Type eMonitor)
{
    uint32_t regVal;
    MAM_Type *const pMam = s_apMamBase[(uint32_t)eMam];
    regVal = Mam_HWA_Get_CCLR(pMam);
    regVal |= (1UL << (uint32_t)eMonitor);
    Mam_HWA_Set_CCLR(pMam, regVal);
}

/**
 * @brief Disable monitoring for a specific port on the Matrix Access Monitor
 * 
 * This function disables access monitoring for a specified port interface
 * on the MAM. When disabled, the MAM will no longer track or report
 * access events through the specified monitor port.
 * 
 * @param eMam MAM instance index (MAM_INDEX_0, MAM_INDEX_1, etc.)
 * @param eMonitor Monitor port to disable (MAM_MONITOR_0, MAM_MONITOR_1, etc.)
 */
void MAM_MonitorDisable(MAM_Index_Type eMam, MAM_Monitor_Type eMonitor)
{
    uint32_t regVal;
    MAM_Type *const pMam = s_apMamBase[(uint32_t)eMam];
    regVal = Mam_HWA_Get_CCLR(pMam);
    regVal &= ~(1UL << (uint32_t)eMonitor);
    Mam_HWA_Set_CCLR(pMam, regVal);
}
#endif

#ifdef MAM_SLAVE_PRIORITY_SUPPORT
/**
 * @brief Enable priority arbitration for a specific slave interface
 * 
 * This function configures and enables priority-based arbitration for a
 * specified slave interface on the MAM. It assigns a priority master that
 * will be granted access when multiple masters attempt to access the same slave.
 * 
 * @param eMam MAM instance index (MAM_INDEX_0, MAM_INDEX_1, etc.)
 * @param eSlave Slave interface to configure priority for (MAM_SLAVE_0 to MAM_SLAVE_15)
 * @param eMaster Master interface to assign as priority master for the slave
 */
void MAM_SlavePriorityEnable(MAM_Index_Type eMam, MAM_Slave_Type eSlave, MAM_Master_Type eMaster)
{
    uint32_t regVal;
    MAM_Type *const pMam = s_apMamBase[(uint32_t)eMam];

    if ((uint32_t)eSlave < MAM_SLAVE_8)
    {
        regVal = Mam_HWA_Get_PRI_ID_SLVGRP0(pMam);
        regVal = (regVal & ~(0xF << ((uint32_t)eSlave << 2))) | ((uint32_t)eMaster << ((uint32_t)eSlave << 2));
        Mam_HWA_Set_PRI_ID_SLVGRP0(pMam, regVal);
    }
    else
    {
        regVal = (uint32_t)eMaster;
        Mam_HWA_Set_PRI_ID_SLVGRP1(pMam, regVal);
    }

    regVal = Mam_HWA_Get_PRI_EN(pMam);
    regVal |= (1UL << (uint32_t)eSlave);
    Mam_HWA_Set_PRI_EN(pMam, regVal);
}

/**
 * @brief Disable priority arbitration for a specific slave interface
 * 
 * This function disables priority-based arbitration for a specified slave
 * interface on the MAM, returning it to default round-robin arbitration.
 * 
 * @param eMam MAM instance index (MAM_INDEX_0, MAM_INDEX_1, etc.)
 * @param eSlave Slave interface to disable priority for (MAM_SLAVE_0 to MAM_SLAVE_15)
 */
void MAM_SlavePriorityDisable(MAM_Index_Type eMam, MAM_Slave_Type eSlave)
{
    uint32_t regVal;
    MAM_Type *const pMam = s_apMamBase[(uint32_t)eMam];

    regVal = Mam_HWA_Get_PRI_EN(pMam);
    regVal &= ~(1UL << (uint32_t)eSlave);
    Mam_HWA_Set_PRI_EN(pMam, regVal);
}
#endif

#endif /* #if MAM_INSTANCE_COUNT > 0U */
