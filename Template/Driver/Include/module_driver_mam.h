/**
 * @file module_driver_mam.h
 * @author Flagchip
 * @brief MAM driver type definition and API
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
   *   0.1.0       2023-12-15    Flagchip054   N/A          First version for FC7300
   *   2.0.0       2024-10-12    Flagchip054   N/A          Change version and release
   *   2.5.0       2025-08-20    Flagchip0100  N/A          Add FC7300F4MDDxxxT1C support
   ******************************************************************************** */
#ifndef _DRIVER_MODULE_DRIVER_MAM_H_
#define _DRIVER_MODULE_DRIVER_MAM_H_

#include "HwA_mam.h"

#if MAM_INSTANCE_COUNT > 0U

/**
 * @addtogroup module_driver_mam
 * @{
 */

#if defined(__cplusplus)
extern "C" {
#endif

/**
 * @enum MAM_Wdog_Timeout_Type
 * @brief Watchdog timeout response configuration options
 * 
 * Defines the system response when a Matrix Access Monitor watchdog timeout occurs.
 * These options determine what happens when a master violates access permissions
 * or fails to complete a transaction within the watchdog period.
 */
typedef enum {
    MAM_WDOG_TIMEOUT_NO_RESPOND          = 0, /**< After the WDOG counter overflows, it does not respond */
    MAM_WDOG_TIMEOUT_INTERRUPT           = 1, /**< After the WDOG counter overflows, an interrupt is generated */
    MAM_WDOG_TIMEOUT_HARDFAULT           = 2, /**< After the WDOG counter overflows, a hard fault is generated */
    MAM_WDOG_TIMEOUT_INTERRUPT_HARDFAULT = 3, /**< After the WDOG counter overflows, an interrupt and a hard fault are generated */
} MAM_Wdog_Timeout_Type;

/**
 * @enum MAM_Wdog_Div_Type
 * @brief Watchdog clock divider configuration options
 * 
 * Defines the clock divider ratios for the Matrix Access Monitor watchdog timer.
 * The watchdog timeout period is calculated as: 512 bus clocks × (divider value + 1)
 */
typedef enum {
    MAM_WDOG_DIV_1  = 0,  /**< WDOG no division; default is 512 bus clocks */
    MAM_WDOG_DIV_2  = 1,  /**< WDOG division, 512*2 bus clocks */
    MAM_WDOG_DIV_3  = 2,  /**< WDOG division, 512*3 bus clocks */
    MAM_WDOG_DIV_4  = 3,  /**< WDOG division, 512*4 bus clocks */
    MAM_WDOG_DIV_5  = 4,  /**< WDOG division, 512*5 bus clocks */
    MAM_WDOG_DIV_6  = 5,  /**< WDOG division, 512*6 bus clocks */
    MAM_WDOG_DIV_7  = 6,  /**< WDOG division, 512*7 bus clocks */
    MAM_WDOG_DIV_8  = 7,  /**< WDOG division, 512*8 bus clocks */
    MAM_WDOG_DIV_9  = 8,  /**< WDOG division, 512*9 bus clocks */
    MAM_WDOG_DIV_10 = 9,  /**< WDOG division, 512*10 bus clocks */
    MAM_WDOG_DIV_11 = 10, /**< WDOG division, 512*11 bus clocks */
    MAM_WDOG_DIV_12 = 11, /**< WDOG division, 512*12 bus clocks */
    MAM_WDOG_DIV_13 = 12, /**< WDOG division, 512*13 bus clocks */
    MAM_WDOG_DIV_14 = 13, /**< WDOG division, 512*14 bus clocks */
    MAM_WDOG_DIV_15 = 14, /**< WDOG division, 512*15 bus clocks */
    MAM_WDOG_DIV_16 = 15, /**< WDOG division, 512*16 bus clocks */
} MAM_Wdog_Div_Type;

/**
 * @enum MAM_Forbid_Access_Type
 * @brief Memory access restriction bitmask options
 * 
 * Defines the access restriction types that can be configured for memory blocks
 * in the Matrix Access Monitor. These values are used as bitmasks to specify
 * which types of access should be forbidden for a particular master.
 */
typedef enum {
    MAM_FORBID_READ_ACCESS    = 1,  /**< Forbid read operations */
    MAM_FORBID_WRITE_ACCESS   = 2,  /**< Forbid write operations */
    MAM_FORBID_EXECUTE_ACCESS = 4,  /**< Forbid instruction fetch/execution */
    MAM_FORBID_USER_ACCESS    = 8,  /**< Forbid user mode access (privileged only) */
} MAM_Forbid_Access_Type;

#ifdef MAM_SOFT_RESET_SUPPORT
/**
 * @brief Perform software reset of the specified Matrix Access Monitor instance
 * 
 * This function resets the Matrix Access Monitor (MAM) hardware to its default
 * state by toggling the matrix configuration bit. The reset clears all MAM
 * configuration registers and monitoring states.
 * 
 * @param eMam MAM instance index to reset (MAM_INDEX_0, MAM_INDEX_1, etc.)
 */
void MAM_Reset(MAM_Index_Type eMam);
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
void MAM_WdogEnable(MAM_Index_Type eMam, MAM_Master_Type eMaster, MAM_Wdog_Timeout_Type eWdgTo, MAM_Wdog_Div_Type eWdgDiv);

/**
 * @brief Disable watchdog for a specific master on the Matrix Access Monitor
 * 
 * This function disables the watchdog timer for a specified master interface
 * on the MAM, preventing further access violation monitoring for that master.
 * 
 * @param eMam MAM instance index (MAM_INDEX_0, MAM_INDEX_1, etc.)
 * @param eMaster Master interface to disable watchdog for (MAM_MASTER_0, MAM_MASTER_1, etc.)
 */
void MAM_WdogDisable(MAM_Index_Type eMam, MAM_Master_Type eMaster);

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
uint8_t MAM_Config(MAM_Master_Type eMaster, uint32_t u32Addr, uint32_t u32Val);

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
uint8_t MAM_ConfigLock(uint32_t u32Addr);

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
void MAM_MonitorEnable(MAM_Index_Type eMam, MAM_Monitor_Type eMonitor);

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
void MAM_MonitorDisable(MAM_Index_Type eMam, MAM_Monitor_Type eMonitor);
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
void MAM_SlavePriorityEnable(MAM_Index_Type eMam, MAM_Slave_Type eSlave, MAM_Master_Type eMaster);

/**
 * @brief Disable priority arbitration for a specific slave interface
 * 
 * This function disables priority-based arbitration for a specified slave
 * interface on the MAM, returning it to default round-robin arbitration.
 * 
 * @param eMam MAM instance index (MAM_INDEX_0, MAM_INDEX_1, etc.)
 * @param eSlave Slave interface to disable priority for (MAM_SLAVE_0 to MAM_SLAVE_15)
 */
void MAM_SlavePriorityDisable(MAM_Index_Type eMam, MAM_Slave_Type eSlave);
#endif

#if defined(__cplusplus)
}
#endif

/** @}*/

#endif /* #if MAM_INSTANCE_COUNT > 0U */

#endif /* end of DRIVER_UART_H_ */
