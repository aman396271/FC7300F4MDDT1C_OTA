/**
 * @file module_driver_ldi.h
 * @author Flagchip
 * @brief LDI driver type definition and API
 * @version 2.0.0
 * @date 2025-06-18
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
   *   0.1.0      2025-06-18     Flagchip0121   N/A         Init version
   ******************************************************************************** */
#ifndef _DRIVER_MODULE_DRIVER_LDI_H_
#define _DRIVER_MODULE_DRIVER_LDI_H_
#include "HwA_ldi.h"


#if LDI_INSTANCE_COUNT > 0U

#include <stddef.h>
/**
 * @addtogroup module_driver_ldi
 * @{
 */

/********* global define ************/
/**
 * @name  LDI API Service IDs
 *
 * @{
 */
#define LDI_Init_ID                         0U
#define LDI_Deinit_ID                       1U
#define LDI_Transmit_ID                     2U
#define LDI_Transmit_IT_ID                  3U
#define LDI_Transmit_DMA_ID                 4U
#define LDI_IRQHandler_ID                   5U
#define LDI_DmaDoneCallback_Tx_ID           6U
/** @}*/

/**
 * @name  LDI Dev Error Code
 * @brief Error Code of calling GPIO apis
 *
 * @{
 */
#define LDI_E_PARAM_INSTANCE           0x01U
#define LDI_E_PARAM_INPUT              0x02U
#define LDI_E_PARAM_STATUS             0x03U
/** @}*/

/** @brief Ldi rcfg max */
#define LDI_RCFG_MAX                   255U
/** @brief Ldi gclk start max */
#define LDI_GCLK_START_MAX             255U
/** @brief Ldi gclk end max */
#define LDI_GCLK_START_END             255U
/** @brief Ldi gclk period max */
#define LDI_GCLK_PERIOD_MAX            32767U
/** @brief Ldi signal window start max */
#define LDI_SIGNAL_WINDOW_START_MAX    255U
/** @brief Ldi signal window end max */
#define LDI_SIGNAL_WINDOW_END_MAX      255U


/********* global typedef ************/
/** @brief Ldi pull status */
typedef enum
{
    LDI_PULL_DOWN = 0U,
    LDI_PULL_UP
} LDI_PullStatusType;

/** @brief Gpio direction */
typedef enum
{
    LDI_GPIO_OUT = 0U,
    LDI_GPIO_IN,
    LDI_GPIO_ZERO
} LDI_GpioDirType;

/** @brief Gpio initialization level */
typedef enum
{
    LDI_GPIO_LOW = 0U,
    LDI_GPIO_HIGH
} LDI_GpioLevelType;

/** @brief Ldi Dclk source */
typedef enum
{
    LDI_DCLK_SDR_MODE = 0U,
    LDI_DCLK_DDR_MODE
} LDI_DclkSrcType;

/** @brief Ldi  Gclk source */
typedef enum
{
    LDI_GCLK_SDR_CLK = 0U,
    LDI_GCLK_DDR_CLK,
    LDI_GCLK_GCLKDIV_CLK
} LDI_GclkSrcType;

/** @brief Ldi  Gclk prediv source */
typedef enum
{
    LDI_GCLKPREDIV_BY1 = 0U,    /**< Divided by 1. */
    LDI_GCLKPREDIV_BY2 = 1U,    /**< Divided by 2. */
    LDI_GCLKPREDIV_BY3 = 2U,    /**< Divided by 3. */
    LDI_GCLKPREDIV_BY4 = 3U,    /**< Divided by 4. */
    LDI_GCLKPREDIV_BY5 = 4U,    /**< Divided by 5. */
    LDI_GCLKPREDIV_BY6 = 5U,    /**< Divided by 6. */
    LDI_GCLKPREDIV_BY7 = 6U,    /**< Divided by 7. */
    LDI_GCLKPREDIV_BY8 = 7U,    /**< Divided by 8. */
    LDI_GCLKPREDIV_BY9 = 8U,    /**< Divided by 9. */
    LDI_GCLKPREDIV_BY10 = 9U,   /**< Divided by 10. */
    LDI_GCLKPREDIV_BY11 = 10U,  /**< Divided by 11. */
    LDI_GCLKPREDIV_BY12 = 11U,  /**< Divided by 12. */
    LDI_GCLKPREDIV_BY13 = 12U,  /**< Divided by 13. */
    LDI_GCLKPREDIV_BY14 = 13U,  /**< Divided by 14. */
    LDI_GCLKPREDIV_BY15 = 14U,  /**< Divided by 15. */
    LDI_GCLKPREDIV_BY16 = 15U   /**< Divided by 16. */
} LDI_GCLkPredivType;

/** @brief Ldi  DDR/SDR prediv source */
typedef enum
{
    LDI_DDRSDRPREDIV_BY1  = 0U,    /**< Divided by 1. */
    LDI_DDRSDRPREDIV_BY2  = 1U,    /**< Divided by 2. */
    LDI_DDRSDRPREDIV_BY4  = 2U,    /**< Divided by 4. */
    LDI_DDRSDRPREDIV_BY8  = 3U,    /**< Divided by 8. */
    LDI_DDRSDRPREDIV_BY12 = 4U,    /**< Divided by 12. */
    LDI_DDRSDRPREDIV_BY16 = 5U     /**< Divided by 16. */
} LDI_DdrSdrPredivType;

/** @brief Ldi Spread Direction */
typedef enum
{
    LDI_SPREAD_DECREASE  = 0U,    /**< Spread decrease. */
    LDI_SPREAD_INCREASE  = 1U     /**< Spread increase. */
} LDI_SpreadDirectType;

/** @brief Ldi  Spread Mode prediv source */
typedef enum
{
    LDI_DISABLE_SPREAD_SPECTRUM  = 0U,    /**< Disable Spread Spectrum Mode. */
    LDI_2BIT_RADND_DATA          = 1U,    /**< Divider will update with 2-bit random data. */
} LDI_SpreadModeType;

/** @brief LDI instance number */
typedef enum
{
    LDI0 = 0U,
} LDI_InstanceType;

/**
 * @brief LDI states 
 *
 */
typedef enum {
    LDI_STATE_UNINIT     = 0x00U,    /*!< Peripheral not Initialized                         */
    LDI_STATE_IDLE       = 0x01U,    /*!< Peripheral Initialized and idle for use           */
    LDI_STATE_BUSY       = 0x02U     /*!< an internal process is ongoing                     */
} LDI_StateType;


/**
 * @brief LDI states 
 *
 */
typedef enum {
    LDI_STATUS_SUCCESS = 0x0U,  /*!< The LDI operation is succeed */
    LDI_STATUS_ERROR   = 0x1U,  /*!< The LDI operation is failed */
    LDI_STATUS_TIMEOUT = 0x2U   /*!< The LDI operation is failed because of time out */
} LDI_StatesType;

/**
 * @brief LDI display states 
 *
 */
typedef enum {
    LDI_DISPLAY_STOP     = 0x00U,    /*!< LDI START display */
    LDI_DISPLAY_START    = 0x01U,    /*!< LDI STOP display */
} LDI_DisplayStateType;

/**
 * @brief LDI data bit order 
 *
 */
typedef enum
{
    LDI_MSB_FIRST = 0,  /**< most significant bit first handle, from msb to lsb */
    LDI_LSB_FIRST = 1   /**< least significant bit first handle, from lsb to msb */
} LDI_DataFirstBitType;

/** @brief Ldi dclk configuration structure */
typedef struct
{
    LDI_DclkSrcType eLdiDclkMode;            /**< Ldi clock mode */
    uint8_t RESERVED_0[3];
} LDI_DclkCfg;

/** @brief Ldi gclk configuration structure */
typedef struct
{
    LDI_GclkSrcType       eLdiGclkSrc;  /**< Ldi Gclk source */
    LDI_GCLkPredivType    eLdiGclkDivider;   /**< Ldi Gclk Prediv mode */
    uint8_t RESERVED_0[2];
} LDI_GclkCfg;

/** @brief Ldi clock configuration structure */
typedef struct
{
    LDI_GclkCfg              tGclkcfg;         /**< Ldi Gclk config */
    LDI_DclkCfg              tDclkcfg;         /**< Ldi Dclk config */
    LDI_DdrSdrPredivType     eDdrSdrDivider;   /**< Ldi Ddr and Sdr Prediv config */
    boolean                  bDdrSdrDelayEn;   /**< Ldi Ddr and Sdr delay enable */
    LDI_SpreadModeType       eSpreadMode;      /**< Ldi Spread Mode Prediv mode */
    LDI_SpreadDirectType     eSpreadDirect;    /**< Ldi Spread Direction mode */
} LDI_ClkCfg;


/** @brief Ldi clock configuration structure */
typedef struct
{
    uint32_t            u32Rows;         /**< Ldi Gclk config */
    uint32_t            u32Channels;     /**< Ldi Dclk config */
    uint32_t            u32Cascds;       /**< Ldi Ddr and Sdr Prediv config */
    uint32_t            u32Dnums;        /**< Data nums per pixel(Size in Bytes) */
} LDI_ScreenCfg;

/** @brief Ldi display row configuration */
typedef uint8_t LDI_PxdRcfgType;

/** @brief Ldi dispaly gclk configuration structure */
typedef struct
{
    uint8_t          u8GclkStart;       /**< Cycles of SDR Clock before GCLK Active Window, Max 255*/
    uint8_t          u8GclkEnd;         /**< Cycles of SDR Clock after GCLK Active Window, Max 255*/
    boolean          bGclkRmodeEn;       /**< CLK is working in Row mode; other config will not be active when this config is enable. */
    uint8_t          RESERVED_0[3];
    uint32_t         u32GclkPeriod;      /**< Period of GCLK Enable during Line Display, Max 32767 */
} LDI_PxdGcfgType;

/** @brief Pixel Display SOE Configuration structure */
typedef struct
{
    uint8_t          u8ScfgSignalwinStart;   /**< Signal Window Start, Max 255*/
    uint8_t          u8ScfgSignalwinEnd;     /**< Signal Window End, Max 255*/
    boolean          bScfgClockModeEn;        /**< Enable clock Mode */
    boolean          bScfgRepeatModeEn;       /**< Enable repeat Mode */
    uint8_t          RESERVED_0[2];
} LDI_PxdScfgType;

/** @brief Pixel Display DOE Configuration structure */
typedef struct
{
    uint8_t          u8DcfgSignalwinStart;   /**< Signal Window Start, Max 255*/
    uint8_t          u8DcfgSignalwinEnd;     /**< Signal Window End, Max 255*/
    boolean          bDcfgClockModeEn;        /**< Enable clock Mode */
    boolean          bDcfgRepeatModeEn;       /**< Enable repeat Mode */
    uint8_t          RESERVED_0[2];
} LDI_PxdDcfgType;

/** @brief Pixel Display SDI Configuration structure */
typedef struct
{
    uint8_t          u8IcfgSignalwinStart;   /**< Signal Window Start, Max 255*/
    uint8_t          u8IcfgSignalwinEnd;     /**< Signal Window End, Max 255*/
    boolean          bIcfgClockModeEn;        /**< Enable clock Mode */
    boolean          bIcfgRepeatModeEn;       /**< Enable repeat Mode */
    uint8_t          RESERVED_0[2];
} LDI_PxdIcfgType;

/** @brief Ldi display configuration structure */
typedef struct
{
    LDI_PxdRcfgType  u8PxdRcfg;   /**< Pixel Display Row Configuration */
    uint8_t          RESERVED_0[3];
    LDI_PxdGcfgType  tPxdGcfg;     /**< Pixel Display GCLK Configuration */
    LDI_PxdScfgType  tPxdScfg;     /**< Pixel Display SOE Configuration */
    LDI_PxdDcfgType  tPxdDcfg;     /**< Pixel Display DOE Configuration */
    LDI_PxdIcfgType  tPxdIcfg;     /**< Pixel Display SDI Configuration */
} LDI_DisplayCfg;


/** @brief Ldi update channel configuration structure */
typedef struct
{
    boolean  bChannel0En;     /**< Enable channel 0, channel 0 must config */
    boolean  bChannel1En;     /**< Enable channel 1 */
    boolean  bChannel2En;     /**< Enable channel 2 */
    boolean  bChannel3En;     /**< Enable channel 3 */
} LDI_EnChannelType;




/** @brief Ldi initialization structure */
typedef struct
{
    const uint16_t      *pLdiData0;     /**< Ldi channel 0 data */
    const uint16_t      *pLdiData1;     /**< Ldi channel 1 data */
    const uint16_t      *pLdiData2;     /**< Ldi channel 2 data */
    const uint16_t      *pLdiData3;     /**< Ldi channel 3 data */
    uint32_t             u32LdiDatalen; /**< The LDI updates the data length, and the data length is the same for all channels  */
} LDI_UpdateType;

/**
 * @brief The structure of the LDI processing handle
 *
 */
typedef struct _LDI_HandleType
{
    LDI_InstanceType        eInstance;         /*!< LDI instance*/
    uint8_t                 RESERVED_0[3];
    struct
    {
        LDI_StateType           eLdiState;         /*!< LDI state*/
        LDI_DisplayStateType    eLdiDisplayState;  /*!< LDI display state*/
        uint8_t                 RESERVED_0[2];
        LDI_EnChannelType       tChannelState;     /*!< LDI channel state*/
        void (*pUpdateCallback)(void);
    } tStatus;
} LDI_HandleType;

/** @brief Ldi initialization structure */
typedef struct
{
    LDI_ClkCfg           tClkcfg;     /**< Ldi Clk config */
    LDI_ScreenCfg        tScreencfg;  /**< Ldi screen config */
    LDI_DisplayCfg       tDisplayfg;  /**< Ldi display config */
    LDI_EnChannelType    tEnChannelfg;  /**< Ldi enable channel config */
    LDI_DataFirstBitType eBitOrder;     /**< MSB or LSB */
    uint8_t              RESERVED_0[3];
    void (*pUpdateCallback)(void);
} LDI_InitType;
/********* global API ************/
/**
 * @brief Initialize ldi
 *
 * @param pLdiHandle pLdiHandle LDI handle for LDI functionality
 * @param pInitStruct Initialization structure of ldi
 */
void LDI_Init(LDI_HandleType *pLdiHandle, const LDI_InitType *const pInitStruct);

/**
 * @brief De-initialize the Ldi instance
 *
 * @param pLdiHandle pLdiHandle LDI handle for LDI functionality
 */
void LDI_Deinit(LDI_HandleType *pLdiHandle);

/**
 * @brief Update data in poll mode (block)
 *
 * @param pLdiHandle pLdiHandle LDI handle for LDI functionality
 * @param pUpdateStruct Ldi update data struct
 * 
 * @return LDI_StatesType 
 */
LDI_StatesType LDI_Update(LDI_HandleType *pLdiHandle, const LDI_UpdateType *const pUpdateStruct);

/**
 * @brief Update data in DMA mode (Non-block)
 *
 * @param pLdiHandle pLdiHandle LDI handle for LDI functionality
 * @param pUpdateStruct Ldi update data struct
 * 
 * @return LDI_StatesType 
 */
LDI_StatesType LDI_Update_DMA(LDI_HandleType *pLdiHandle, const LDI_UpdateType *const pUpdateStruct);

/**
 * @brief Ldi start display
 *
 * @param pLdiHandle pLdiHandle LDI handle for LDI functionality
 */
void LDI_Dispaly_Start(LDI_HandleType *pLdiHandle);

/**
 * @brief Ldi stop display
 *
 * @param pLdiHandle pLdiHandle LDI handle for LDI functionality
 */
void LDI_Dispaly_Stop(LDI_HandleType *pLdiHandle);

/**
 * @brief LDIn Interrupt Handler.
 *
 * @param pLdiHandle pLdiHandle LDI handle for LDI functionality
 */
void LDIn_IRQHandler(LDI_HandleType *pLdiHandle);

/** @}*/ /* module_driver_ldi */

#endif

#endif

