/**
 * @file module_driver_crc.h
 * @author Flagchip
 * @brief CRC driver type definition and API
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
   *   0.1.0       2023-12-15    Flagchip055   N/A          First version for FC7300
   *   2.0.0       2024-10-12    Flagchip055   N/A          Change version and release
   ******************************************************************************** */
#ifndef _DRIVER_MODULE_DRIVER_CRC_H_
#define _DRIVER_MODULE_DRIVER_CRC_H_
#include "HwA_crc.h"

#if CRC_INSTANCE_COUNT > 0U

/**
 * @addtogroup module_driver_crc
 * @{
 */

#if defined(__cplusplus)
extern "C" {
#endif

/**
 * @name  SSI API Service IDs
 *
 * @{
 */
#define CRC_INIT_ID        1U
#define CRC_DEINIT_ID      2U
#define CRC_GETRST         3U
#define CRC_SETCALCDATA8   4U
#define CRC_SETCALCDATA16  5U
#define CRC_SETCALCDATA32  6U
#define CRC_SETINPUTDATA   7U

/** @}*/

/**
 * @name  SSI Dev Error Code
 * @brief Error Code of calling ADC apis
 *
 * @{
 */
#define CRC_E_PARAM_INSTANCE    0x01U
#define CRC_E_PARAM_POINTER     0x02U
#define CRC_E_UNINIT            0x03U
#define CRC_E_ALREADY_INIT      0x04U


#define   CRC_DEFAULT_POLY   (0x1021U)
#define   CRC_DEFAULT_INTVAL (0U)


/********* Local typedef ************/
typedef enum
{
    CRC_NONE            = 0,
    CRC_16_CCITT        = 1,
    CRC_16_CCITT_FALSE  = 2,
    CRC_16_MODBUS       = 3,
    CRC_16_USB          = 4,
    CRC_32_USER         = 5
#if CRC_8_BIT_HARDWARE_SUPPORT
    ,
    CRC_8_ROHC          = 6
#endif
} eCrctype;


/**
 * @brief Defines the crc configuration
 *
 * This structure is used to configure the crc
 *
 * Implements : CRC_InitType
 */
typedef struct
{
    CRC_WriteDataSwapType   eWriteDataSwap;       /*!< the data swap for write(none,bits,bytes or both) */
    CRC_ReadDataSwapType    eReadDataSwap;        /*!< the data swap for read(none,bits,bytes or both) */
    CRC_ReadDataFXORType    eReadDataFXOR;        /*!< complement of reading crc data(none or FXOR) */
    CRC_BitWidthType        eBitWidth;            /*!< crc bit width */
    eCrctype                eType;                /*!< crc type */
    uint8_t                 _aligned[2];
    uint32_t                u32Polynomial;        /*!< the polynomial value of crc */
    uint32_t                u32SeedValue;         /*!< the seed value of crc */
} Crc_ConfigType;

/**
 * @brief The structure of the SENT processing handle
 *
 */
typedef struct Crc_HandleType
{
    Crc_InstanceType        eInstance; /**< Crc instance */

    /* tStatus Can't be set by user  */
    struct
    {
        bool                     bInitStatus;         /**< Crc instance initialize status */
    } tStatus;

} Crc_HandleType;


/**
 * @brief Initializes the CRC module with the specified configuration.
 *
 * This function configures the CRC module according to the provided configuration structure.
 * It must be called before any other CRC operations to ensure the module is properly set up.
 *
 * @param pCrcHandle Pointer to the CRC handle structure that contains the instance information.
 * @param pInitCfg   Pointer to the CRC configuration structure containing initialization data.
 *                   Must not be NULL.
 *
 * @return None.
 *
 * @note The CRC module must be uninitialized before calling this function to avoid conflicts.
 */
void CRC_Init(Crc_HandleType *pCrcHandle, const Crc_ConfigType *const pInitCfg);

/**
 * @brief Deinitializes the CRC module and restores default configuration.
 *
 * This function resets the CRC module to its default state, effectively undoing any
 * previous initialization. It is typically used to release the CRC module before
 * reinitialization or system shutdown.
 *
 * @param pCrcHandle Pointer to the CRC handle structure that contains the instance information.
 *                   Must not be NULL.
 *
 * @return None.
 */
void CRC_DeInit(Crc_HandleType *pCrcHandle);

/**
 * @brief get CRC result
 *
 * @param pCrcHandle Pointer to the CRC handle structure.
 */
uint32_t CRC_GetCrcResult(Crc_HandleType *pCrcHandle);

/**
 * @brief set CRC DATA register 8bits
 *
 * @param pCrcHandle Pointer to the CRC handle structure.
 * @param u8Data the data to be set
 */
void CRC_SetCalcData_U8(Crc_HandleType *pCrcHandle, uint8_t u8Data);

/**
 * @brief set CRC DATA register 16bits
 *
 * @param pCrcHandle Pointer to the CRC handle structure.
 * @param u16Data the data to be set
 */
void CRC_SetCalcData_U16(Crc_HandleType *pCrcHandle, uint16_t u16Data);

/**
 * @brief set CRC low lower register
 *
 * @param pCrcHandle Pointer to the CRC handle structure.
 * @param u32Data the data to be set
 */
void CRC_SetCalcData_U32(Crc_HandleType *pCrcHandle, uint32_t u32Data);

/**
 * @brief set CRC seed value
 *
 * @param pCrcHandle Pointer to the CRC handle structure.
 * @param u32SeedVal seed value
 */
void CRC_SetSeed(Crc_HandleType *pCrcHandle, uint32_t u32SeedVal);

/**
 * @brief set CRC input data
 *
 * @param pCrcHandle Pointer to the CRC handle structure.
 * @param pData data pointer
 * @param u32DataSize input data size
 */
void CRC_SetInputData(Crc_HandleType *pCrcHandle, const uint8_t * pData, uint32_t u32DataSize);


/** @}*/ /* module_driver_crc */
#if defined(__cplusplus)
}
#endif

#endif /* #if CRC_INSTANCE_COUNT > 0U */

#endif  /* _DRIVER_MODULE_DRIVER_CRC_H_ */

