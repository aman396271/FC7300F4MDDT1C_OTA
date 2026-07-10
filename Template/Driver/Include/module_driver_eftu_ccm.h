/**
 * @file module_driver_eftu_ccm.h
 * @author flagchip
 * @brief eFTU ccm driver type definition and API
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
   *   0.1.0       2023-12-15    Flagchip032   N/A          First version for FC7300
   *   2.0.0       2024-10-12    Flagchip070   N/A          Change version and release
   ******************************************************************************** */

#ifndef DRIVER_INCLUDE_MODULE_DRIVER_EFTU_CCM_H_
#define DRIVER_INCLUDE_MODULE_DRIVER_EFTU_CCM_H_

#include "hwa_eftu_ccm.h"
#include "module_driver_eftu.h"
#include "module_driver_eftu_cmu.h"
#if EFTU_INSTANCE_COUNT > 0U
#define EFTU_CCM_MODULE_ID  				1U

/**
 * @name  CCM API Service IDs
 *
 * @{
 */
#define EFTU_CCM_INIT_ID											0U
#define EFTU_CCM_CONFIG_DEBUG_ID									1U
#define EFTU_CCM_CONFIG_CMP_ID										2U
#define EFTU_CCM_CONFIG_CLUSTER_CMU_CLOCK_ID						3U
#define EFTU_CCM_CONFIG_TIM_ERR_INTERRUPT_ID						4U
#define EFTU_CCM_CONFIG_DMA_REQUEST_ID								5U
#define EFTU_CCM_CONFIG_GLOBAL_TRIGGER_ID							6U
/** @}*/

/**
 * @name  CCM Dev Error Code
 * @brief Error Code of calling CCM apis
 *
 * @{
 */
#define EFTU_CCM_UNINIT							0U
#define EFTU_CCM_E_PARAM_CHANNEL				1U
#define EFTU_CCM_E_PARAM_COUNT					2U
#define EFTU_CCM_E_PARAM_INVALID				3U
#define EFTU_CCM_E_PARAM_INVALID_VALUE			4U
/** @}*/

typedef void (*pEftuCcmIntCallback)(void);

typedef enum
{

    EFTU_CCM_DMA_REQ_TOM1_CH_0 = 0,
    EFTU_CCM_DMA_REQ_TOM1_CH_1,
    EFTU_CCM_DMA_REQ_TOM1_CH_2,
    EFTU_CCM_DMA_REQ_TOM1_CH_3,
    EFTU_CCM_DMA_REQ_TOM1_CH_4,
    EFTU_CCM_DMA_REQ_TOM1_CH_5,
    EFTU_CCM_DMA_REQ_TOM1_CH_6,
    EFTU_CCM_DMA_REQ_TOM1_CH_7,
	EFTU_CCM_DMA_REQ_TOM0_CH_0 ,
	EFTU_CCM_DMA_REQ_TOM0_CH_1,
	EFTU_CCM_DMA_REQ_TOM0_CH_2,
	EFTU_CCM_DMA_REQ_TOM0_CH_3,
	EFTU_CCM_DMA_REQ_TOM0_CH_4,
	EFTU_CCM_DMA_REQ_TOM0_CH_5,
	EFTU_CCM_DMA_REQ_TOM0_CH_6,
	EFTU_CCM_DMA_REQ_TOM0_CH_7,
    EFTU_CCM_DMA_REQ_TIM_CH_0 ,
	EFTU_CCM_DMA_REQ_TIM_CH_1,
	EFTU_CCM_DMA_REQ_TIM_CH_2,
	EFTU_CCM_DMA_REQ_TIM_CH_3,
	EFTU_CCM_DMA_REQ_TIM_CH_4,
	EFTU_CCM_DMA_REQ_TIM_CH_5,
	EFTU_CCM_DMA_REQ_TIM_CH_6,
	EFTU_CCM_DMA_REQ_TIM_CH_7,
} EFTU_CCM_DmaRequestSrcType;



typedef struct										/*Only for EFTU0*/
{
	EFTU_CCM_CmpInstance eCmpInstance;
	uint8_t u8CmpEnMask;								/*Each bit represents a channel*/
	EFTU_CCM_CmpSrcSelectType eCmpSrcX;
	EFTU_CCM_CmpSrcSelectType eCmpSrcY;
	bool bEnInterrupt;
	pEftuCcmIntCallback pEftuCmpIntback;
}EFTU_CCM_CmpConfigStruct;


typedef struct
{
	uint8_t u8TriggerOutMask;
	EFTU_CCM_GlobalTriggerOutType eGtriggerSrc;
}EFTU_CCM_GlobalTriggerMode;

typedef struct
{
    bool bTim0Enable;
    bool bTom0Enable;
    bool bTom1Enable;
    EFTU_CCM_DebugMode   eDebugMode;
} EFTU_CCM_InitStruct;

typedef struct
{
	EFTU_CCM_TimErrChnType eTimChannel;
	bool bEnErrInterrupt;
	uint8_t u8ErrorEnMask;
	pEftuCcmIntCallback pEftuTimErrIntback;
}EFTU_CCM_TimErrIntStruct;


typedef struct
{
	uint8_t u8DmaReqSrcChnIndex;
	EFTU_CCM_DmaRequestSrcType eDmaReqSelect;
	boolean bCcu0IrqEnDmaReq;
	boolean bCcu1IrqEnDmaReq;
}EFTU_CCM_DmaReqStruct;

typedef struct _EFTU_CCM_HandleType
{
    EFTU_InstanceType   eInstance;
    struct
    {
        EFTU_CCM_Type *pCcm;
        bool bTim0En;
        bool bTom0En;
        bool bTom1En;
        EFTU_CCM_DebugMode eDebugMode;
        EFTU_CCM_ClusterCmuClkSelectType eaClusterClkSrc[EFTU_CLUSTER_CLOCK_COUNT];
        pEftuCcmIntCallback g_pEftuCmpIntback[EFTU_CMP_COUNT];
        pEftuCcmIntCallback g_pEftuTimErrIntback[EFTU_TIM_CHANNEL_COUNT];
    }tStatus;
} EFTU_CCM_HandleType;

/**
 * @brief Initialize CCM peripherals
 * @param pCcmHandle EFTU Ccm processing handle
 * @param pConfig Ccm InitStruct
 */
void EFTU_CCM_Init(EFTU_CCM_HandleType *pCcmHandle, EFTU_CCM_InitStruct *pConfig);

/**
 * @brief Config EFTU debug mode
 * @param pCcmHandle EFTU Ccm processing handle
 * @param eDebugMode EFTU debug mode
 */
void EFTU_CCM_ConfigDebugMode(EFTU_CCM_HandleType *pCcmHandle,EFTU_CCM_DebugMode eDebugMode);

/**
 * @brief Enable EFTU Tim0
 * @param pCcmHandle EFTU Ccm processing handle
 */
void EFTU_CCM_EnableTim0(EFTU_CCM_HandleType *pCcmHandle);
/**
 * @brief Enable EFTU Tom0
 * @param pCcmHandle EFTU Ccm processing handle
 */
void EFTU_CCM_EnableTom0(EFTU_CCM_HandleType *pCcmHandle);
/**
 * @brief Enable EFTU Tom1
 * @param pCcmHandle EFTU Ccm processing handle
 */
void EFTU_CCM_EnableTom1(EFTU_CCM_HandleType *pCcmHandle);

/**
 * @brief Disable EFTU Tim0
 * @param pCcmHandle EFTU Ccm processing handle
 */
void EFTU_CCM_DisableTim0(EFTU_CCM_HandleType *pCcmHandle);

/**
 * @brief Disable EFTU Tom0
 * @param pCcmHandle EFTU Ccm processing handle
 */
void EFTU_CCM_DisableTom0(EFTU_CCM_HandleType *pCcmHandle);

/**
 * @brief Disable EFTU Tom1
 * @param pCcmHandle EFTU Ccm processing handle
 */
void EFTU_CCM_DisableTom1(EFTU_CCM_HandleType *pCcmHandle);

/**
 * @brief Config EFTU Cmp peripherals
 * @param pCcmHandle EFTU Ccm processing handle
 * @param  pCmpInitStruct Cmp InitStruct
 */
void EFTU_CCM_ConfigCmp(EFTU_CCM_HandleType *pCcmHandle,EFTU_CCM_CmpConfigStruct *pCmpInitStruct);


/**
 * @brief Config cluster cmu clock source.
 * @param pCcmHandle EFTU Ccm processing handle
 * @param  eClusterClk  Cluster clock index
 * @param  pCmpInitStruct Cluster clock select
 * @param pCmuHandle EFTU cmu processing handle
 * @param  u32Freq user define frequency
 */
void EFTU_CCM_ConfigClusterCmuClock(EFTU_CCM_HandleType *pCcmHandle, EFTU_CCM_ClusterCmuClkType eClusterClk, EFTU_CCM_ClusterCmuClkSelectType eCcmClockSel,EFTU_CMU_HandleType *pCmuHandle,uint32 u32Freq);
/**
 * @brief Config cluster Tim Err Interrupt.
 * @param pCcmHandle EFTU Ccm processing handle
 * @param  pTimErrStruct  Tim Err InitStruct
 */
void EFTU_CCM_ConfigTimErrorInterrupt(EFTU_CCM_HandleType *pCcmHandle,EFTU_CCM_TimErrIntStruct *pTimErrStruct);


/**
 * @brief Config cluster Dma Request.
 * @param pCcmHandle EFTU Ccm processing handle
 * @param  pDmaReqStruct  Tim Dma InitStruct
 */
void EFTU_CCM_ConfigDmaRequest(EFTU_CCM_HandleType *pCcmHandle, EFTU_CCM_DmaReqStruct *pDmaReqStruct);

/**
 * @brief Config global trigger.(Only for EFTU0)
 * @param pCcmHandle EFTU Ccm processing handle
 * @param u8TriggerIndex  Trigger Index
* @param  pTriggerStruct  Trigger InitStruct
 */
void EFTU_CCM_ConfigGlobalTrigger(EFTU_CCM_HandleType *pCcmHandle,uint8_t u8TriggerIndex,EFTU_CCM_GlobalTriggerMode *pTriggerStruct);


/**
 * @brief Ccm Interrupt process
 * @param pCcmHandle EFTU Ccm processing handle
 */
void EFTUn_CCM_IRQHandler(EFTU_CCM_HandleType *pCcmHandle);

#endif

#endif /* DRIVER_INCLUDE_MODULE_DRIVER_EFTU_CCM_H_ */
