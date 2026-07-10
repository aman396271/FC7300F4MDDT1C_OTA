/**
 * @file module_driver_flash.h
 * @author Flagchip
 * @brief Flash driver type definition and API
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
   *   0.1.0       2023-12-15    Flagchip051   N/A          First version for FC7300
   *   2.0.0       2024-10-12    Flagchip120   N/A          Change version and release
   *   2.3.5       10/06/2025    HowardWang    N/A          Add flash DMA abort, update flash DMA error process.
   ******************************************************************************** */
#ifndef _DRIVER_MODULE_DRIVER_FLASH_H_
#define _DRIVER_MODULE_DRIVER_FLASH_H_

#include "device_header.h"

#if FLASH_INSTANCE_COUNT > 0U

/**
 * @addtogroup module_driver_flash
 * @{
 */
/***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/

/**
 * @name  FLASH API Service IDs
 *
 * @{
 */
#define FLASH_SYNC_ERASE_ID                  0U
#define FLASH_SYNC_WRITE_ID                  1U
#define FLASH_ASYNC_ERASE_ID                 2U
#define FLASH_ASYNC_WRITE_ID                 3U
#define FLASH_INTERRUPT_ERASE_ID             4U
#define FLASH_INTERRUPT_WRITE_ID             5U
#define NVR_SYNC_ERASE_ID                    6U
#define NVR_SYNC_WRITE_ID                    7U
/**@}*/

/**
 * @name  FLASH Dev Error Code
 *
 * @{
 */
#define FLASH_E_PARAM_POINTER   		0x01U
/**@}*/

/**
 * @brief FLASH instance
 *
 */
typedef enum
{
    FLASH_INSTANCE_0 = 0U,
} FLASH_InstanceType;

typedef enum fls_Ret
{
    FLS_IDLE = 0,    /**< Indicate that a function was successfully processed.*/
    FLS_ERASING = 1, /**< Indicate that a function was NOT successfully processed.*/
    FLS_WRITING = 2,
    FLS_READING = 3,
    FLS_ERASE_ERROR = 4,
    FLS_WRITE_ERROR = 5,
    FLS_PARA_ERROR = 6,
    FLS_DMA_WRITING = 7,
    FLS_ASYNC_ERASE_PENDING = 8,
    FLS_ASYNC_WRITE_PENDING = 9,
    FLS_WRITING_ECC = 10,
} Fls_Status_t;


/**
 * @brief FLASH API error status
 *
 */
typedef enum
{
    FLASH_ERROR_OK                  =  0x00U,/**< FLASH_ERROR_OK means no error */
    FLASH_ERROR_NO_INIT,                     /**< FLASH_ERROR_NO_INIT means rom code api address is not initialed */
    FLASH_ERROR_INVALID_VERSION,             /**< FLASH_ERROR_INVALID_VERSION means rom code api version is not same */
    FLASH_ERROR_FAILED,                      /**< FLASH_ERROR_FAILED means operation is failed */
    FLASH_ERROR_INVALID_PARAM,               /**< FLASH_ERROR_INVALID_PARAM means parameters are invalid */
    FLASH_ERROR_INVALID_ADDR,                /**< FLASH_ERROR_INVALID_ADDR means address is invalid */
    FLASH_ERROR_INVALID_SIZE,                /**< FLASH_ERROR_INVALID_SIZE means size is invalid */
    FLASH_ERROR_INVALID_SEQUENCE,            /**< FLASH_ERROR_INVALID_SEQUENCE means sequence is error */
    FLASH_ERROR_TIMEOUT,                     /**< FLASH_ERROR_TIMEOUT means operation is timeout */
    FLASH_ERROR_ECC,                         /**< FLASH_ERROR_ECC means operation have ECC */
    FLASH_ERROR_END           = 0xFFFFFFFFU  /**< FLASH_ERROR_END make aligned 32bits */
}FLASH_StatusType;

/**
 * @brief FLASH ECC error status
 *
 */
typedef enum
{
    FLASH_ECC_ERROR_NONE,
    FLASH_ECC_ERROR_SBC,
    FLASH_ECC_ERROR_DBC
} ECC_StatusType;

/**
 * @brief FLASH async prog/erase status
 *
 */
typedef enum Async_Return
{
    FLASH_ASYNC_ERR_OK = 0,     /**< Indicate that a function was successfully processed.*/
    FLASH_ASYNC_ERR_NOT_OK = 1, /**< Indicate that a function was NOT successfully processed.*/
    FLASH_ASYNC_ERR_BUSY = 2,   /**< Indicate that a function was busy .*/
} Async_Return_t; /**< Some values from a called function.*/

/**
 * @brief FLASH interrupt prog/erase status
 *
 */
typedef enum Interrupt_Return
{
    FLASH_INTERRUPT_ERR_OK = 0,      /**< Indicate that a function was successfully processed.*/
    FLASH_INTERRUPT_ERR_NOT_OK = 1,  /**< Indicate that a function was NOT successfully processed.*/
    FLASH_INTERRUPT_ERR_BUSY = 2,    /**< Indicate that a function was busy */
} Fls_ReturnType;

/**
 * @brief The structure of the FLASH processing handle
 * 
 **/
typedef struct _FLASH_HandleType
{
    FLASH_InstanceType eInstance;       /*!< Flash instance*/
    char _aligned[3];
    struct
    {
        uint32_t                    u32Address;
        uint32_t                    u32Length;
        uint32_t                    u32CurrentAddress;
        uint32_t                    u32ProgramSize;
        uint32_t                    u32EraseSectorSize;
        uint32_t                    u32ErrorAdress;
        uint8_t                     *pDate;
        Fls_Status_t                eFlsStatus;     /*!< Flash operation status */
        char _aligned1[3];
    } tStatus;
    struct
    {
        FLASH_StatusType(*pUnlockCallback)(uint32_t u32Address);     /**< Unlock callback function. */
    } tSettings;                                             /**< The field of tSettings allows the user to set. */
} FLASH_HandleType;

/**
 * @brief Flash driver parameter define
 *
 */
typedef struct
{
    uint32_t         u32Address;             /**< Logical target address                  */
    uint32_t         u32Length;              /**< Length in logical sectors or bytes      */
    uint8_t          *pData;                 /**< Pointer to data buffer (read only)      */
    uint8_t         (*wdTriggerFct)(void);   /**< Pointer to watchdog handling function   */
    uint32_t         u32ErrorAddress;        /**< Error address                           */
} FLASH_DRIVER_ParamType;

/**
 * \brief FMC lock type
 *
 */
typedef enum
{
    FLASH_UNLOCK           = 0x000u,
    FLASH_LOCK             = 0x001u
} FLASH_LOCK_TYPE;

/**
 * \brief Flash type
 *
 */
typedef enum
{
    PFlash          = 0x000u,
    DFlash          = 0x001u
} FLASH_TYPE;

/**
 * \brief unlock parameter define
 *
 */
typedef struct
{
    uint32_t                    u32Address;             /**< Logical target address                  */
    uint32_t                    u32Length;              /**< Length in logical sectors or pages      */
    FLASH_LOCK_TYPE             bLock;                  /**< lock type                               */
    FLASH_TYPE                  bFlash;                 /**< flash type                              */
} FLASH_Lock_ParamType;

/**
 * @brief Initial Flash api address
 *
 */
void FLASHDRIVER_Init(void);

/**
 * @brief Flash Driver Function for lock/unlock sector
 *
 * @param pUnlockParam flash driver lock/unlock parameter
 * @return ErrorType
 */
FLASH_StatusType FLASHDRIVER_Lock(FLASH_Lock_ParamType *pUnlockParam);

#if((FLASH_FC7300F8MDQ == STD_ON) || (FLASH_FC7300F4MDD_T1C == STD_ON) || (FLASH_FC7300F4MDS_T1C == STD_ON))
/**
 * @brief Flash Driver Function for DMA Write
 *
 * @param pFlashHandle flash handle
 * @param u32DMACount u32DMACount flash DMA count
 * @return ErrorType
 */
FLASH_StatusType FLASHDRIVER_DMAWrite(FLASH_HandleType *pFlashHandle, uint32_t u32DMACount);

/**
 * \brief Flash Driver Function for DMA Abort
 *
 * \param u32DMACount flash DMA count
 * \return complete count
 */
uint32_t FLASHDRIVER_DMAAbort(FLASH_HandleType *pFlashHandle);

#endif

/**
 * @brief Flash Driver Function for Erasing
 *
 * @param pFlashHandle flash handle
 * @param pFlashParam flash driver erase parameter
 * @return ErrorType
 */
FLASH_StatusType FLASHDRIVER_SyncErase(FLASH_HandleType *pFlashHandle, FLASH_DRIVER_ParamType *pFlashParam);

/**
 * @brief Flash Driver Function for Writing
 *
 * @param pFlashHandle flash handle
 * @param pFlashParam flash driver write parameter
 * @return ErrorType
 */
FLASH_StatusType FLASHDRIVER_SyncWrite(FLASH_HandleType *pFlashHandle, FLASH_DRIVER_ParamType *pFlashParam);

/**
* @brief        flash driver for erase
*
* @param        pFlashHandle the Flash instance to use
* @param        pFlashParam flash driver erase parameter
* @return       ErrorType
*/
FLASH_StatusType FLASHDRIVER_AsyncErase(FLASH_HandleType *pFlashHandle, FLASH_DRIVER_ParamType *pFlashParam);

/**
* @brief        flash driver write a fixed size
*
* @param        pFlashHandle the Flash instance to use
* @param        pFlashParam flash driver write parameter
* @return       ErrorType
*/
FLASH_StatusType FLASHDRIVER_AsyncWrite(FLASH_HandleType *pFlashHandle, FLASH_DRIVER_ParamType *pFlashParam);

/**
* @brief        flash driver check current status when erasing
*
* @param        pFlashHandle the Flash instance to use
* @return       Fls_Status_t return the erase status
*/
Fls_Status_t FLASHDRIVER_AsyncEraseMainFunction(FLASH_HandleType *pFlashHandle);

/**
* @brief        flash driver check current status when writing
*
* @param        pFlashHandle the Flash instance to use
* @return       Fls_Status_t return the write status
*/
Fls_Status_t FLASHDRIVER_AsyncWriteMainFunction(FLASH_HandleType *pFlashHandle);

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
FLASH_StatusType NVRDRIVER_SyncWrite(FLASH_HandleType *pFlashHandle, FLASH_DRIVER_ParamType *pFlashParam);

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
FLASH_StatusType NVRDRIVER_SyncErase(FLASH_HandleType *pFlashHandle, FLASH_DRIVER_ParamType *pFlashParam);

/**
* @brief        flash driver interrupt erase
* @param pFlashHandle flash handle
* @param pFlashParam flash driver write parameter
*/
void FLASHDRIVER_InterruptErase(FLASH_HandleType *pFlashHandle, FLASH_DRIVER_ParamType *pFlashParam);

/**
* @brief        flash driver interrupt write
* @param[in]    pFlashHandle Flash handle
* @param pFlashParam flash driver write parameter
*/
void FLASHDRIVER_InterruptProgram(FLASH_HandleType *pFlashHandle, FLASH_DRIVER_ParamType *pFlashParam);

/**
 * @brief Close teset mode
 *
 * @param pFlashHandle the Flash instance to use
 * @return none
 */
void FLASHDRIVER_Close_Test_Mode(FLASH_HandleType *pFlashHandle);

#if ((FLASH_FC7300F8MDQ == STD_ON) || (FLASH_FC7300F4MDD_T1C == STD_ON) || (FLASH_FC7300F4MDS_T1C == STD_ON))
/**
 * @brief Flash Driver Function for enable interrupt
 *
 * @param u32CoreID  core id
 */
void FLASHDRIVER_EnInterrupt(uint32_t u32CoreID);
#endif

/**
 * @brief Process Flash interrupt
 *
 * @param pFlashHandle flash handle point
 * @return process result
 */
Fls_ReturnType Fls_CommonProcessInterrupt(FLASH_HandleType *pFlashHandle);

/**
 * @brief Flash Driver Function for lock/unlock sector
 *
 * @param u32Address sector address
 * @param bLock 0U-unlock, 1U-lock
 */
FLASH_StatusType FLASHDRIVER_LockSector(uint32_t u32Address, FLASH_LOCK_TYPE bLock);

/**
 * @brief Flash Driver Function for lock/unlock nvr sector
 *
 * @param u32Address sector address
 * @param bLock 0U-unlock, 1U-lock
 * @return       none
 */
FLASH_StatusType NVRDRIVER_LockSector(uint32_t u32Address, FLASH_LOCK_TYPE bLock);

/**@}*/

#endif /* #if FLASH_INSTANCE_COUNT > 0U */


#endif /* end of _DRIVER_MODULE_DRIVER_FLASH_H_ */
