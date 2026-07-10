#ifndef _DEVICE_FEATURES_FC7300F4MDSxxxxxT1C_AHBOVERLAY_COMMON_H_
#define _DEVICE_FEATURES_FC7300F4MDSxxxxxT1C_AHBOVERLAY_COMMON_H_

#define AHB_OVERLAY_INSTANCE_COUNT       1
#define AHB_OVERLAY_CROS__INTR_SUPPORT   STD_OFF
#define AHB_OVERLAY_FAR_SUPPORT          STD_OFF
#define AHB_OVERLAY_EN_UNLOCK            STD_ON

/**
 * @brief OVERlay Region size
 *
 */
typedef enum
{
	OVERLAY_OVERLAYSIZE_4KB  = 0x1,      /**< OVERLAY_OVERLAYSIZE_4KB, remapping overlay region size to 4KB          */
	OVERLAY_OVERLAYSIZE_8KB  = 0x2,      /**< OVERLAY_OVERLAYSIZE_8KB, remapping overlay region size to 8KB          */
	OVERLAY_OVERLAYSIZE_16KB  = 0x4,     /**< OVERLAY_OVERLAYSIZE_16KB, remapping overlay region size to 16KB          */
	OVERLAY_OVERLAYSIZE_32KB  = 0x8,     /**< OVERLAY_OVERLAYSIZE_32KB, remapping overlay region size to 32KB          */
	OVERLAY_OVERLAYSIZE_64KB = 0x10,     /**< OVERLAY_OVERLAYSIZE_64KB, remapping overlay region size to 64KB        */
	OVERLAY_OVERLAYSIZE_128KB = 0x20,    /**< OVERLAY_OVERLAYSIZE_128KB, remapping overlay region size to 128KB        */
	OVERLAY_OVERLAYSIZE_256KB = 0x40,    /**< OVERLAY_OVERLAYSIZE_256KB, remapping overlay region size to 256KB        */
	OVERLAY_OVERLAYSIZE_512KB = 0x80,    /**< OVERLAY_OVERLAYSIZE_128KB, remapping overlay region size to 512KB        */
	OVERLAY_OVERLAYSIZE_1M = 0x100       /**< OVERLAY_OVERLAYSIZE_256KB, remapping overlay region size to 1M        */
}OVERLAY_OverlaySizeType;

/** Array initializer of AHB_OVERLAY peripheral base addresses */
#define AHB_OVERLAY_BASE_ADDRS                   {AHB_OVERLAY_BASE}
/** Array initializer of AHB_OVERLAY peripheral base pointers */
#define AHB_OVERLAY_BASE_PTRS                    {AHB_OVERLAY}

#endif /* _DEVICE_FEATURES_FC7300F4MDSxxxxxT1C_AHBOVERLAY_COMMON_H_ */
