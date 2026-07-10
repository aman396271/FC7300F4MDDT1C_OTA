#ifndef INCLUDE_DEVICE_H_
#define INCLUDE_DEVICE_H_

/*
 * The imported FC7300 template did not carry the usual project _device.h.
 * Keep the selection explicit for this demo project and PN.
 */
#define DEVICE_NAME FC7300F4MDD1A320T1C

#define DEV_ERROR_REPORT STD_ON

#if DEV_ERROR_REPORT == STD_ON
#define FLASH_DEV_ERROR_REPORT STD_OFF
#endif

#endif /* INCLUDE_DEVICE_H_ */
