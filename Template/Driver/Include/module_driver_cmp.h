/**
 * @file module_driver_cmp.h
 * @author Flagchip
 * @brief CMP driver type definition and API
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
#ifndef _DRIVER_MODULE_DRIVER_CMP_H_
#define _DRIVER_MODULE_DRIVER_CMP_H_

#include "HwA_cmp.h"

#if CMP_INSTANCE_COUNT > 0

/**
 * @addtogroup module_driver_cmp
 * @{
 */


#if defined(__cplusplus)
extern "C" {
#endif

/********* Local typedef ************/

/**
 * @name  CMP API Service IDs
 *
 * @{
 */
#define CMP_INIT_ID                     0U
#define CMP_DEINIT_ID                   1U
#define CMP_GETDEFAULTINITCFG_ID        2U
#define CMP_ENABLE_ID                   3U
#define CMP_DISABLE_ID                  4U
#define CMP_GETCMPOUT_ID                5U
#define CMP_SETDACDATA_ID               6U
#define CMP_GETOUTFLAGSTATUS_ID         7U
#define CMP_GETCSFLAGSTATUS_ID          8U
#define CMP_ENABLECSCHANNEL_ID          9U
#define CMP_DISABLECSCHANNEL_ID         10U
#define CMP_GETCSCHANNELOUT_ID          11U
#define CMP_GETCMPCSACTIVE_ID           12U
#define CMP_ENTERLPMODE_ID              13U
#define CMP_EXITLPMODE_ID               14U

/** @}*/

/**
 * @name  CMP Dev Error Code
 * @brief Error Code of calling CMP apis
 *
 * @{
 */
#define CMP_E_PARAM_INSTANCE            0x01U
#define CMP_E_PARAM_CHANNEL             0x02U
#define CMP_E_PARAM_POINTER             0x03U
/** @} */

/**
 * @brief The instance index of the CMP Dac parts
 */
typedef struct
{
    bool bDacEn;                           /*!< CMP DAC enable */
    uint8_t u8DacData;                     /*!< CMP DAC output voltage, output = Vin / 256 * (aDacData + 1) */
    CMP_DacEnableSrcType eDacEnsrc;        /*!< CMP DAC enable selection(DCR,CCR0) */
} CMP_DacType;

/**
 * @brief The instance index of the CMP Mux parts
 */
typedef struct
{
    CMP_INSrcSelType eINPSel;                /*!< CMP input positive select(DAC analog mux) */
    CMP_INSrcSelType eINNSel;                /*!< CMP input negative select(DAC analog mux) */
    CMP_MuxSelType ePSelMux;                 /*!< CMP input positive mux select(IN0...IN7) */
    CMP_MuxSelType eNSelMux;                 /*!< CMP input negative mux select(IN0...IN7) */
    #ifdef CMP_SUPPORT_CHANNELSCAN_MODE_FEATURE
    CMP_MuxSelType eCSFIXCMux;               /*!< CMP channel scan fixed channel select(IN0...IN4), this is ignored if DAC is enabled */
    CMP_PortSelType eCSFIXPSel;              /*!< CMP channel scan fixed channel port select(positive or negative) */
    #endif
} CMP_MuxType;

/**
 * @brief The instance index of the CMP Comparator parts
 */
typedef struct
{
    bool bLPModeEn;                        /*!< CMP low power mode enable */
    bool bDmaEn;                           /*!< CMP dma enable */
    bool bOutToPackagePinEn;               /*!< CMP output to package pin enable */
    bool bWinSampleInvertEn;               /*!< CMP window/sample signal invert enable */
    bool bEventCloseWinEn;                 /*!< CMP out event close window enable */
    uint8_t u8FilterPeriod;                /*!< CMP set Filter Sample Period */
    uint32_t u32InitDelay;                 /*!< CMP initialization delay, the max initialization delay is 30us */
    CMP_ModeSelType eModeSel;              /*!< CMP set function mode */
    CMP_InvertType eInvert;                /*!< CMP output Invert or not(invert, non-invert) */
    CMP_OutSelectType eOutSelect;          /*!< CMP output filter or not(CMPO = CMPOUT_FILTER/CMPOUT_WIN) */
    CMP_OutWinLevelType eOutWinLevel;      /*!< CMP output when window close(hold, userdefine) */
    CMP_OutWinLevel_UserDefType eOutWin;   /*!< CMP output under userdefine (0, 1) */
    CMP_EventType eEventSelect;            /*!< CMP output event cause window close(rising edge, falling edge) */
    CMP_FilterCntType eFilterCnt;          /*!< CMP filter count numbers(0,1,2,3,4) */
    CMP_SpeedModeSelType eSpeedMode;       /*!< CMP speed mode(low,high) */
    CMP_HystCtrlType eHystCrtl;            /*!< CMP hysteresis internal control(0,1,2,3) */
} CMP_ComparatorType;

/**
 * @brief The structure of the CMP processing handle
 *
 */
typedef struct _CMP_HandleType
{
    CMP_InstanceType eInstance;         /*!< CMP instance*/

    struct
    {
        bool bLPModeEn;                 /*!< CMP stop mode enable */
        bool bOutToPackagePinEn;        /*!< CMP output to package pin enable */
        bool bRisingIntEn;              /*!< Enable rising interrupt */
        bool bFallingIntEn;             /*!< Enable falling interrupt */
        #ifdef CMP_SUPPORT_CHANNELSCAN_MODE_FEATURE
        bool bChannelScanIntEn;         /*!< Enable/disable channel scan flag interrupt */
        #endif
        uint32_t u32InitDelay;          /*!< CMP initialization delay, the max initialization delay is 30us */
        void (*pRisingNotify)(struct _CMP_HandleType *pCmpHandle);
        void (*pFallingNotify)(struct _CMP_HandleType *pCmpHandle);
        #ifdef CMP_SUPPORT_CHANNELSCAN_MODE_FEATURE
        void (*pChannelScanNotify)(struct _CMP_HandleType *pCmpHandle);
        #endif
    }tSettings;

} CMP_HandleType;

/**
 * @brief Defines the comparator interrupt configuration
 *
 * @note This structure is used to configure CMP interrupt
 *       Implements : CMP_InterruptType
 */
typedef struct
{
    bool bRisingIntEn;                            /*!< Enable rising interrupt */
    bool bFallingIntEn;                           /*!< Enable falling interrupt */
    #ifdef CMP_SUPPORT_CHANNELSCAN_MODE_FEATURE
    bool bChannelScanIntEn;                       /*!< Enable/disable channel scan flag interrupt */
    #endif
    void (*pRisingNotify)(struct _CMP_HandleType *pCmpHandle);                  /*!< CMP rising interrupt callback */
    void (*pFallingNotify)(struct _CMP_HandleType *pCmpHandle);                 /*!< CMP falling interrupt callback */
    #ifdef CMP_SUPPORT_CHANNELSCAN_MODE_FEATURE
    void (*pChannelScanNotify)(struct _CMP_HandleType *pCmpHandle);             /*!< CMP channel scan flag interrupt callback */
    #endif
} CMP_InterruptType;

#ifdef CMP_SUPPORT_CHANNELSCAN_MODE_FEATURE
/**
 * @brief Defines the comparator channel selected in channel scan mode
 *
 * @note This structure is used to configure a CMP channel that want to be enabled in channel scan sequence
 *       Implements : CMP_CSChannelCfgType
 */
typedef struct
{
    CMP_MuxSelType eChannel;        /*!< Enabled channel */
    bool bPreSetState;              /*!< Preset state for the given channel */
} CMP_CSChannelCfgType;

/**
 * @brief Defines the comparator channel scan configuration
 *
 * @note This structure is used to configure CMP channel scan
 *       Implements : CMP_ChannelScanType
 */
typedef struct
{
    uint8_t u8CSInitModulus;           /*!< Compartor and DAC initialization delay modulus */
    uint8_t u8CSNSAM;                  /*!< Number of smaple clocks later the the sample operation takes place */
    bool bCSCompareResultAC;           /*!< Enable/disable comparison result auto clear */
} CMP_ChannelScanType;
#endif

/**
 * @brief Defines the comparator configuration
 *
 * @note This structure is used to configure CMP
 *       Implements : CMP_InitType
 */
typedef struct
{
    CMP_DacType tDacConfig;                /*!< CMP DAC configure */
    CMP_MuxType tMuxConfig;                /*!< CMP MUX configure */
    CMP_ComparatorType tComparatorConfig;  /*!< CMP Comparator configure */
    #ifdef CMP_SUPPORT_CHANNELSCAN_MODE_FEATURE
    CMP_ChannelScanType tChannelScanConfig;/*!< CMP Channel Scan configure */
    #endif
    CMP_InterruptType tInterruptConfig;    /*!< CMP Interrupt configure */
} CMP_InitType;

/********* Public function ************/

/**
 * @brief set CMP module configurations instructure to defalut value
 *
 * @param pInitCfg The basic configurations of the CMP instance
 */
void CMP_GetDefaultInitCfg(CMP_InitType *pInitCfg);

/**
 * @brief set CMP module enable
 *
 * @param pCmpHandle CMP processing handle
 */
void CMP_Enable(CMP_HandleType *pCmpHandle);

/**
 * @brief set CMP module disable
 *
 * @param pCmpHandle CMP processing handle
 */
void CMP_Disable(CMP_HandleType *pCmpHandle);

/**
 * @brief CMP init
 *
 * @param pCmpHandle CMP processing handle
 * @param pInitCfg The basic configurations of the CMP instance
 */
void CMP_Init(CMP_HandleType *pCmpHandle, const CMP_InitType *const pInitCfg);

/**
 * @brief CMP Deinit
 *
 * @param pCmpHandle CMP processing handle
 */
void CMP_Deinit(CMP_HandleType *pCmpHandle);

/**
 * @brief CMP Deinit
 *
 * @param pCmpHandle CMP processing handle
 */
void CMP_Enter_LP_Mode(CMP_HandleType *pCmpHandle);

/**
 * @brief get CMP filtered output
 *
 * @param pCmpHandle CMP processing handle
 * @return CMP filtered output
 */
uint32_t CMP_GetCmpOut(CMP_HandleType *pCmpHandle);

/**
 * @brief set CMP Dac output
 *
 * @param pCmpHandle CMP processing handle
 * @param u8Data input voltage value
 * @note voltage = (VinRef / 256) * (eDacData + 1)
 */
void CMP_SetDacData(CMP_HandleType *pCmpHandle, uint8_t u8Data);

/**
 * @brief get CMP interrupter flag status
 *
 * @param pCmpHandle CMP processing handle
 * @return CMP  output status
 */
CMP_OutStatus CMP_GetOutFlagStatus(CMP_HandleType *pCmpHandle);

/**
 * @brief CMP interrupt process function
 *
 * @param pCmpHandle CMP processing handlee
 */
void CMPn_IRQHandler(CMP_HandleType *pCmpHandle);

#ifdef CMP_SUPPORT_CHANNELSCAN_MODE_FEATURE
/**
 * @brief set CMP module channel scan mode enable
 *
 * @param pCmpHandle CMP processing handle
 */
void CMP_CSEnable(CMP_HandleType *pCmpHandle);

/**
 * @brief set CMP module channel scan mode disable
 *
 * @param pCmpHandle CMP processing handle
 */
void CMP_CSDisable(CMP_HandleType *pCmpHandle);

/**
 * @brief get CMP channel scan flag status
 *
 * @param pCmpHandle CMP processing handle
 * @return CMP channel scan status
 */
bool CMP_GetCSFlagStatus(CMP_HandleType *pCmpHandle);

/**
 * @brief enable CMP channel scan channels
 *
 * @param pCmpHandle CMP processing handle
 * @param e_Channel the CMP channel channel
 * @param bPreSetState preset state for the given channel
 */
void CMP_EnableCSChannel(CMP_HandleType *pCmpHandle, const CMP_MuxSelType eChannel, const bool bPreSetState);

/**
 * @brief disable CMP channel scan channels
 *
 * @param pCmpHandle CMP processing handle
 * @param e_Channel the CMP channel channel
 */
void CMP_DisableCSChannel(CMP_HandleType *pCmpHandle, const CMP_MuxSelType eChannel);

/**
 * @brief get CMP channel scan channel out
 *
 * @param pCmpHandle CMP processing handle
 * @param e_Channel the CMP channel channel
 * @return the CMP channel current status
 */
bool CMP_GetCSChannlOut(CMP_HandleType *pCmpHandle, const CMP_MuxSelType e_Channel);

/**
 * @brief get CMP channel scan status
 *
 * @param pCmpHandle CMP processing handle
 */
bool CMP_GetCmpCSActive(CMP_HandleType *pCmpHandle);

#endif /* CMP_SUPPORT_CHANNELSCAN_MODE_FEATURE */

#ifdef __cplusplus
}
#endif

/** @}*/

#endif /* CMP_INSTANCE_COUNT > 0U */

#endif /* _DRIVER_MODULE_DRIVER_CMP_H_ */
