#ifndef _DEVICE_FEATURES_FC7240_PMC_COMMON_H_
#define _DEVICE_FEATURES_FC7240_PMC_COMMON_H_


/************ PMC Features **************/
/** Number of instances of the PMC module. */
#define PMC_INSTANCE_COUNT                       (1u)


/** Array initializer of PMC peripheral base addresses */
#define PMC_BASE_ADDRS                           {PMC_BASE}
/** Array initializer of PMC peripheral base pointers */
#define PMC_BASE_PTRS                            {PMC}

/************ PMC Specfic Features **************/
#define PMC_HVD5VB_SUPPORT         (0u)
#define PMC_V15_CTRL_SUPPORT       (1u)
#define PMC_V15_FLAG_SUPPORT       (1u)
#define PMC_VX_DOUBLE_FLAG_SUPPORT (0u)
#define PMC_V15_STATUS_SUPPORT     (1u)
#define PMC_V11_STATUS_SUPPORT     (0u)

#define LVSCR_DEFAULT_VAL   0x80F3007DU
#define CONFIG_DEFAULT_VAL  0x8000U


#endif /* _DEVICE_FEATURES_FC7240_PMC_COMMON_H_ */
