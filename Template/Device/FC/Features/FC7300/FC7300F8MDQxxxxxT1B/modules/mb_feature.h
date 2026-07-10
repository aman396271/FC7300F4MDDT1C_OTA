#ifndef _DEVICE_FEATURES_FC7300F8MDQxxxxxT1B_MB_COMMON_H_
#define _DEVICE_FEATURES_FC7300F8MDQxxxxxT1B_MB_COMMON_H_

#define MB_COM_CHANNEL_COUNT				16u
#define MB_INTR_CHANNEL_COUNT				5u
#define MB_MASTER_ID_TABLE					{0u, 2u, 4u, 8u, 6u}

#define MB_CORE_INDEX_VALID(c)				((uint8_t)(c) < 5u ? 1u : 0u)
enum
{
	MB_CORE_INDEX_CORE_0	= 0,	/*!< Core index of core 0 */
	MB_CORE_INDEX_CORE_1,			/*!< Core index of core 1 */
	MB_CORE_INDEX_CORE_2,			/*!< Core index of core 2 */
	MB_CORE_INDEX_HSM,				/*!< Core index of HSM */
	MB_CORE_INDEX_CORE_3,			/*!< Core index of core 3 */
};

#define MB_SEMA_EXSIST

#endif /* _DEVICE_FEATURES_FC7300F8MDQxxxxxT1B_MB_COMMON_H_ */
