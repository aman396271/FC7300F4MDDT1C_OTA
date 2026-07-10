#ifndef _DEVICE_FEATURES_FC7300F8MDTxxxxxT1B_MB_COMMON_H_
#define _DEVICE_FEATURES_FC7300F8MDTxxxxxT1B_MB_COMMON_H_

#define MB_COM_CHANNEL_COUNT				16u
#define MB_INTR_CHANNEL_COUNT				4u
#define MB_MASTER_ID_TABLE                  {0u, 2u, 4u, 8u}

#define MB_CORE_INDEX_VALID(c)				((uint8_t)(c) < 4u ? 1u : 0u)
enum
{
	MB_CORE_INDEX_CORE_0	= 0,	/*!< Core index of core 0 */
	MB_CORE_INDEX_CORE_1,			/*!< Core index of core 1 */
	MB_CORE_INDEX_CORE_2,			/*!< Core index of core 2 */
	MB_CORE_INDEX_HSM,				/*!< Core index of HSM */
};
#endif /* _DEVICE_FEATURES_FC7300F8MDTxxxxxT1B_MB_COMMON_H_ */
