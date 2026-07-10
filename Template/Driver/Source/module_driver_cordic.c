/**
 * @file module_driver_cordic.c
 * @author Flagchip
 * @brief Cordic driver source code
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
 *   0.1.0       2023-02-08    Flagchip054   N/A          First version for FC7300
 ******************************************************************************** */
#include "module_driver_cordic.h"

#if CORDIC_INSTANCE_COUNT > 0U

#ifndef CORDIC_DEV_ERROR_REPORT
#define CORDIC_DEV_ERROR_REPORT STD_OFF
#endif

#if CORDIC_DEV_ERROR_REPORT == STD_ON
#define CORDIC_ReportDevError(func, error) ReportDevError(CORDIC_MODULE_ID, func, error)
#endif

/**
 * @brief Array of pointers to CORDIC module bases.
 *
 * This array contains pointers to the base addresses of all CORDIC modules.
 */
static CORDIC_Type *const s_apCordicBase[CORDIC_INSTANCE_COUNT] = CORDIC_BASE_PTRS;

/**
 * @brief Sign bit for the CORDIC algorithm.
 *
 * Represents the sign bit in a single-precision floating-point number.
 */
#define CORDIC_SIGN_BIT 0x80000000UL

/**
 * @brief Exponent bit for the CORDIC algorithm.
 *
 * Represents the exponent bits in a single-precision floating-point number.
 */
#define CORDIC_EXP_BIT  0x7F800000UL

/**
 * @brief Tail bit for the CORDIC algorithm.
 *
 * Represents the mantissa bits in a single-precision floating-point number.
 */
#define CORDIC_TAIL_BIT 0x007FFFFFUL

#if ((DEVICE_NAME > FC7240F2MDSxxxxxT1A_DEVICE_START) && (DEVICE_NAME < FC7300F4MDSxxxxT1C_DEVICE_END))
/**
 * @brief Scaling factor K for the CORDIC algorithm.
 *
 * Represents the scaling factor used in the CORDIC algorithm.
 */
#define REVERSE_SCALEING_FACTOR_K         0x4dba76b2

#define REVERSE_SCALEING_FACTOR_KF        1304065714.f

#define REVERSE_SCALEING_FACTOR_KF_DIV32  40752053.5625f
/**
 * @brief Adjusted scaling factor KA for the CORDIC algorithm.
 *
 * Represents the adjusted scaling factor used in the CORDIC algorithm.
 */
#define REVERSE_SCALEING_FACTOR_KA        2593080084

#define REVERSE_SCALEING_FACTOR_KA_DIV2   1296540042

#define REVERSE_SCALEING_FACTOR_KA_DIV16  2162067505

#define REVERSE_SCALEING_FACTOR_KAF       2593080084.f

#define REVERSE_SCALEING_FACTOR_KAF_DIV16 162067505.25f

#define MAX_CONVERT_COEFF                 2147483648.f

#define MAX_CONVERT_COEFF_I               2147483648

#define MAX_CONVERT_COEFF_I_DIV2          1073741824

#define MAX_CONVERT_COEFF_DIV180          11930464.711111f

#define MAX_CONVERT_COEFF_DIV32           67108864.f

#define MAX_CONVERT_COEFF_DIV2            1073741824.f

#define MAX_CONVERT_COEFF_DIV4            536870912.f

#define MAX_CONVERT_COEFF_DIV16           134217728.f

#define ARCTANH_XINPUT_FIX_COEFF          MAX_CONVERT_COEFF_I_DIV2

#define ARCTANH_YINPUT_FIX_COEFF(Y)       (int32_t)(Y * MAX_CONVERT_COEFF_DIV2)

#define ARCTANH_OUTPUT_FIX_COEFF          MAX_CONVERT_COEFF_DIV2

#define SINHCOSH_XINPUT1_FIX_COEFF        REVERSE_SCALEING_FACTOR_KA_DIV2

#define SINHCOSH_ZINPUT2_FIX_COEFF(Z)     (int32_t)(Z * MAX_CONVERT_COEFF_DIV2)

#define SINHCOSH_OUTPUT_FIX_COEFF         MAX_CONVERT_COEFF_DIV2

#define LIN_XINPUT_FIX_COEFF(X)           (int32_t)((X + 1.f)*MAX_CONVERT_COEFF_DIV16)

#define LIN_YINPUT_FIX_COEFF(Y)           (int32_t)((Y - 1.f)*MAX_CONVERT_COEFF_DIV16)

#define LIN_OUTPUT_FIX_COEFF              MAX_CONVERT_COEFF_DIV32

#define SQRT_XINPUT_FIX_COEFF(X)          (int32_t)((X + 0.25f)*MAX_CONVERT_COEFF_DIV4)

#define SQRT_YINPUT_FIX_COEFF(Y)          (int32_t)((Y - 0.25f)*MAX_CONVERT_COEFF_DIV4)

#define SQRT_OUTPUT_FIX_COEFF             444614671.4214072f

#else

/**
 * @brief Scaling factor K for the CORDIC algorithm.
 *
 * Represents the scaling factor used in the CORDIC algorithm.
 */
#define REVERSE_SCALEING_FACTOR_K         81504122

#define REVERSE_SCALEING_FACTOR_KF        81504122.f

#define REVERSE_SCALEING_FACTOR_KF_DIV32  2547003.8125f

/**
 * @brief Adjusted scaling factor KA for the CORDIC algorithm.
 *
 * Represents the adjusted scaling factor used in the CORDIC algorithm.
 */
#define REVERSE_SCALEING_FACTOR_KA        162067583

#define REVERSE_SCALEING_FACTOR_KA_DIV2   81033791

#define REVERSE_SCALEING_FACTOR_KA_DIV16  10129224

#define REVERSE_SCALEING_FACTOR_KAF_DIV16 10129223.9375f

#define REVERSE_SCALEING_FACTOR_KAF       162067583.f

#define MAX_CONVERT_COEFF                 134217728.f

#define MAX_CONVERT_COEFF_I               134217728UL

#define MAX_CONVERT_COEFF_I_DIV2          67108864

#define MAX_CONVERT_COEFF_DIV180          10007997.084103f

#define MAX_CONVERT_COEFF_DIV32           4194304.f

#define MAX_CONVERT_COEFF_DIV2            67108864.f

#define MAX_CONVERT_COEFF_DIV16           8388608.f

#define ARCTANH_XINPUT_FIX_COEFF          MAX_CONVERT_COEFF_I

#define ARCTANH_YINPUT_FIX_COEFF(Y)       Float2Fix_Convert(Y)

#define ARCTANH_OUTPUT_FIX_COEFF          MAX_CONVERT_COEFF

#define SINHCOSH_XINPUT1_FIX_COEFF        REVERSE_SCALEING_FACTOR_KA

#define SINHCOSH_ZINPUT2_FIX_COEFF(Z)     Float2Fix_Convert(Z)

#define SINHCOSH_OUTPUT_FIX_COEFF         MAX_CONVERT_COEFF

#define LIN_XINPUT_FIX_COEFF(X)           Float2Fix_Convert(X + 1.f)

#define LIN_YINPUT_FIX_COEFF(Y)           Float2Fix_Convert(Y - 1.f)

#define LIN_OUTPUT_FIX_COEFF              MAX_CONVERT_COEFF_DIV2

#define SQRT_XINPUT_FIX_COEFF(X)          Float2Fix_Convert(X + 0.25f)

#define SQRT_YINPUT_FIX_COEFF(Y)          Float2Fix_Convert(Y - 0.25f)

#define SQRT_OUTPUT_FIX_COEFF             111153667.8553518f

#endif

/*************** Local Functions ***************/
/**
 * @brief Converts a floating-point number to a fixed-point representation.
 *
 * This function converts a floating-point number into a fixed-point
 * representation suitable for use in the CORDIC algorithm.
 *
 * @param nFloat Pointer to the floating-point number to convert.
 * @return The converted fixed-point representation.
 */
static int32_t Float2Fix_Convert(const float nFloat)
{
    int32_t  nFix;
    uint32_t temp;
    int32_t  exp;
    uint32_t tail;
    /* Step1: get the sign bit */
    temp = *(uint32_t *)(&nFloat);
    nFix = (int32_t)(temp & CORDIC_SIGN_BIT);
    /* Step2: get the integer bits */
    exp  = (int32_t)(((temp & CORDIC_EXP_BIT) >> 23) - 127U);
    tail = (temp & CORDIC_TAIL_BIT) | 0x00800000U;
#if ((DEVICE_NAME > FC7240F2MDSxxxxxT1A_DEVICE_START) && (DEVICE_NAME < FC7300F4MDSxxxxT1C_DEVICE_END))
    /* Step3: get the fractional bits */
    if ((8 + exp) < 0)
    {
        nFix = (int32_t)((uint32_t)nFix | (tail & (~(0xFFFFFFFFU << (23 - exp)))) >> (-8 - exp));
    }
    else
    {
        nFix = (int32_t)((uint32_t)nFix | (tail & (~(0xFFFFFFFFU << (23 - exp)))) << (8 + exp));
    }
    if ((uint32_t)nFix & CORDIC_SIGN_BIT)
    {
        nFix = (int32_t)((((uint32_t)nFix ^ 0x7FFFFFFFU) + 1) | CORDIC_SIGN_BIT);
    }
#else
    nFix = (int32_t)((uint32_t)nFix | ((tail >> (23 - exp)) << 27));
    /* Step3: get the fractional bits */
    if ((4 + exp) < 0)
    {
        nFix = (int32_t)((uint32_t)nFix | (tail & (~(0xFFFFFFFFU << (23 - exp)))) >> (-4 - exp));
    }
    else
    {
        nFix = (int32_t)((uint32_t)nFix | (tail & (~(0xFFFFFFFFU << (23 - exp)))) << (4 + exp));
    }
    if ((uint32_t)nFix & CORDIC_SIGN_BIT)
    {
        nFix = (int32_t)((((uint32_t)nFix ^ 0x7FFFFFFFU) + 1) | CORDIC_SIGN_BIT);
    }
#endif
    return nFix;
}

/*****************  Global Functions *******************/
/**
 * @brief The function to calculate sin & cos
 *
 * @param radian the input value to calculate
 *
 * input range (−90°, +90°)/180°
 */
CORDIC_SinCos_Type Cordic_Sin_Cos(CORDIC_InstanceType eInstance, const float radian)
{

    CORDIC_Type *const pCORDIC = s_apCordicBase[eInstance];
    /* angles are expressed in radian, multiplied by a constant number. 𝜃/180 * 𝜋c (where 𝜋c
     * is 13.42177) */
    CORDIC_SinCos_Type tRetVal;
#if CORDIC_DEV_ERROR_REPORT == STD_ON
    if (eInstance >= CORDIC_INSTANCE_COUNT)
    {
        CORDIC_ReportDevError(CORDIC_SIN_COS_ID, CORDIC_E_PARAM_INSTANCE);
    }
    else
    {
#endif
        // float tmp = REVERSE_SCALEING_FACTOR_K;
        float   tmp        = 0;
#if ((DEVICE_NAME > FC7240F2MDSxxxxxT1A_DEVICE_START) && (DEVICE_NAME < FC7300F4MDSxxxxT1C_DEVICE_END))
        int32_t fix_radian = Float2Fix_Convert(radian);
#else
        int32_t fix_radian = Float2Fix_Convert(radian*13.42177f);
#endif
        int32_t x_input    = REVERSE_SCALEING_FACTOR_K;
        Cordic_HWA_Set_XInput(pCORDIC, x_input);
        Cordic_HWA_Set_YInput(pCORDIC, 0);
        Cordic_HWA_Set_ZInput(pCORDIC, fix_radian);
        /* Disable interrupt + Iteration Number16 + Trigonometric system + Rotate mode */
        Cordic_HWA_SetCtrl(pCORDIC,
                           CORDIC_CTR_VAL(0,
                                          false,
                                          (uint32_t)CORDIC_Iteration_16,
                                          (uint32_t)CORDIC_Trigonometric,
                                          (uint32_t)CORDIC_Rotate));
        while (!Cordic_HWA_Get_Stat(pCORDIC))
        {
        }
        Cordic_HWA_Clear_Stat(pCORDIC);
        tmp          = (float)Cordic_HWA_Get_YOutput(pCORDIC) / MAX_CONVERT_COEFF;
        tRetVal.sinx = tmp;
        tmp          = (float)Cordic_HWA_Get_XOutput(pCORDIC) / MAX_CONVERT_COEFF;
        tRetVal.cosx = tmp;
#if CORDIC_DEV_ERROR_REPORT == STD_ON
    }
#endif
    return tRetVal;
}

/**
 * @brief The function to calculate circular radical add
 *
 * @param1 x the first input value
 *
 * @param2 y the second input value
 */
CORDIC_Radical_Type Cordic_Radical_Add(CORDIC_InstanceType eInstance,
                                                const float         x,
                                                const float         y)
{
    CORDIC_Radical_Type tRetVal;
    CORDIC_Type *const  pCORDIC = s_apCordicBase[eInstance];
#if CORDIC_DEV_ERROR_REPORT == STD_ON
    if (eInstance >= CORDIC_INSTANCE_COUNT)
    {
        CORDIC_ReportDevError(CORDIC_RADICAL_ADD_ID, CORDIC_E_PARAM_INSTANCE);
    }
    else
    {
#endif
        int32_t x_input = (int32_t)(REVERSE_SCALEING_FACTOR_KF_DIV32 * x);
        int32_t y_input = (int32_t)(REVERSE_SCALEING_FACTOR_KF_DIV32 * y);
        Cordic_HWA_Set_XInput(pCORDIC, x_input);
        Cordic_HWA_Set_YInput(pCORDIC, y_input);

        Cordic_HWA_Set_ZInput(pCORDIC, 0);
        /* Disable interrupt + Iteration Number16 + Trigonometric system + Vector mode */
        Cordic_HWA_SetCtrl(pCORDIC,
                           CORDIC_CTR_VAL(5,
                                          false,
                                          (uint32_t)CORDIC_Iteration_16,
                                          (uint32_t)CORDIC_Trigonometric,
                                          (uint32_t)CORDIC_Vector));
        while (!Cordic_HWA_Get_Stat(pCORDIC))
        {
        }
        Cordic_HWA_Clear_Stat(pCORDIC);
        tRetVal = (CORDIC_Radical_Type)(Cordic_HWA_Get_XOutput(pCORDIC)) / MAX_CONVERT_COEFF_DIV32;
#if CORDIC_DEV_ERROR_REPORT == STD_ON
    }
#endif
    return tRetVal;
}

/**
 * @brief The function to calculate circular arctan
 *
 * @param y the input value
 */
CORDIC_Arctan_Type Cordic_Arctan_F(CORDIC_InstanceType eInstance, const float y)
{
    CORDIC_Type *const pCORDIC = s_apCordicBase[eInstance];
    CORDIC_Arctan_Type tRetVal;
#if CORDIC_DEV_ERROR_REPORT == STD_ON
    if (eInstance >= CORDIC_INSTANCE_COUNT)
    {
        CORDIC_ReportDevError(CORDIC_ARCTAN_F_ID, CORDIC_E_PARAM_INSTANCE);
    }
    else
    {
#endif
        if ((y > 96.6) || (y < -96.6))
        {
            tRetVal = (float)89.4069;
        }
        else
        {
            int32_t x_input = 1342177;
            int32_t y_input = (int32_t)(y * 1342177);
            Cordic_HWA_Set_XInput(pCORDIC, x_input);
            Cordic_HWA_Set_YInput(pCORDIC, y_input);
            Cordic_HWA_Set_ZInput(pCORDIC, 0);
            /* Disable interrupt + Iteration Number16 + Trigonometric system + Vector mode */
            Cordic_HWA_SetCtrl(pCORDIC,
                               CORDIC_CTR_VAL(0,
                                              false,
                                              (uint32_t)CORDIC_Iteration_16,
                                              (uint32_t)CORDIC_Trigonometric,
                                              (uint32_t)CORDIC_Vector));
            while (!Cordic_HWA_Get_Stat(pCORDIC))
            {
            }
            Cordic_HWA_Clear_Stat(pCORDIC);
            /* 10007997.084103 = 134217728.f * 13.42177 / 180 */;
            tRetVal = (CORDIC_Arctan_Type)(Cordic_HWA_Get_ZOutput(pCORDIC)) /
                      MAX_CONVERT_COEFF_DIV180;
        }
#if CORDIC_DEV_ERROR_REPORT == STD_ON
    }
#endif
    return tRetVal;
}

/**
 * @brief The function to calculate circular arctan
 *
 * @param1 x the first input value
 *
 * @param2 y the second input value
 */
CORDIC_Arctan_Type Cordic_Arctan(CORDIC_InstanceType eInstance,
                                          const int32_t       x,
                                          const int32_t       y)
{
    CORDIC_Type *const pCORDIC = s_apCordicBase[eInstance];
    CORDIC_Arctan_Type tRetVal;
#if CORDIC_DEV_ERROR_REPORT == STD_ON
    if (eInstance >= CORDIC_INSTANCE_COUNT)
    {
        CORDIC_ReportDevError(CORDIC_ARCTAN_ID, CORDIC_E_PARAM_INSTANCE);
    }
    else
    {
#endif
        Cordic_HWA_Set_XInput(pCORDIC, x);
        Cordic_HWA_Set_YInput(pCORDIC, y);
        Cordic_HWA_Set_ZInput(pCORDIC, 0);
        /* Disable interrupt + Iteration Number16 + Trigonometric system + Vector mode */
        Cordic_HWA_SetCtrl(pCORDIC,
                           CORDIC_CTR_VAL(0,
                                          false,
                                          (uint32_t)CORDIC_Iteration_16,
                                          (uint32_t)CORDIC_Trigonometric,
                                          (uint32_t)CORDIC_Vector));
        while (!Cordic_HWA_Get_Stat(pCORDIC))
        {
        }
        Cordic_HWA_Clear_Stat(pCORDIC);
        /*** 11,930,464.711111 = 2147483648.f / 180 ***/;
        tRetVal = (CORDIC_Arctan_Type)(Cordic_HWA_Get_ZOutput(pCORDIC)) / MAX_CONVERT_COEFF_DIV180;
#if CORDIC_DEV_ERROR_REPORT == STD_ON
    }
#endif
    return tRetVal;
}

/**
 * @brief The function to calculate circular Sinh & Cosh
 *
 * @param z the input value
 */
CORDIC_SinhCosh_Type Cordic_Sinh_Cosh(CORDIC_InstanceType eInstance, const float z)
{
    CORDIC_Type *const   pCORDIC = s_apCordicBase[eInstance];
    CORDIC_SinhCosh_Type tRetVal;
    float                tmp = 0;
#if CORDIC_DEV_ERROR_REPORT == STD_ON
    if (eInstance >= CORDIC_INSTANCE_COUNT)
    {
        CORDIC_ReportDevError(CORDIC_SINH_COSH_ID, CORDIC_E_PARAM_INSTANCE);
    }
    else
    {
#endif
        int32_t z_input = SINHCOSH_ZINPUT2_FIX_COEFF(z);
        int32_t x_input = SINHCOSH_XINPUT1_FIX_COEFF;
        Cordic_HWA_Set_XInput(pCORDIC, x_input);
        Cordic_HWA_Set_YInput(pCORDIC, 0);
        Cordic_HWA_Set_ZInput(pCORDIC, z_input);
        /* Disable interrupt + Iteration Number16 + Hyperbolic system + Rotate mode */
        Cordic_HWA_SetCtrl(pCORDIC,
                           CORDIC_CTR_VAL(1,
                                          false,
                                          (uint32_t)CORDIC_Iteration_16,
                                          (uint32_t)CORDIC_Hyperbolic,
                                          (uint32_t)CORDIC_Rotate));
        while (!Cordic_HWA_Get_Stat(pCORDIC))
        {
        }
        Cordic_HWA_Clear_Stat(pCORDIC);
        tmp           = (float)(Cordic_HWA_Get_YOutput(pCORDIC)) / SINHCOSH_OUTPUT_FIX_COEFF;
        tRetVal.sinxh = tmp;
        tmp           = (float)(Cordic_HWA_Get_XOutput(pCORDIC)) / SINHCOSH_OUTPUT_FIX_COEFF;
        tRetVal.cosxh = tmp;
#if CORDIC_DEV_ERROR_REPORT == STD_ON
    }
#endif
    return tRetVal;
}

/**
 * @brief The function to calculate circular radical sub
 *
 * @param1 x the first input value
 *
 * @param2 y the second input value
 */
CORDIC_Radical_Type Cordic_Radical_Sub(CORDIC_InstanceType eInstance,
                                                const float         x,
                                                const float         y)
{
    CORDIC_Type *const  pCORDIC = s_apCordicBase[eInstance];
    CORDIC_Radical_Type tRetVal;

#if CORDIC_DEV_ERROR_REPORT == STD_ON
    if (eInstance >= CORDIC_INSTANCE_COUNT)
    {
        CORDIC_ReportDevError(CORDIC_RADICAL_SUB_ID, CORDIC_E_PARAM_INSTANCE);
    }
    else
    {
#endif
        int32_t x_input = (int32_t)(REVERSE_SCALEING_FACTOR_KAF_DIV16 * x);
        int32_t y_input = (int32_t)(REVERSE_SCALEING_FACTOR_KAF_DIV16 * y);

        Cordic_HWA_Set_XInput(pCORDIC, x_input);
        Cordic_HWA_Set_YInput(pCORDIC, y_input);
        Cordic_HWA_Set_ZInput(pCORDIC, 0);
        /* Disable interrupt + Iteration Number16 + Hyperbolic system + Vector mode */
        Cordic_HWA_SetCtrl(pCORDIC,
                           CORDIC_CTR_VAL(4,
                                          false,
                                          (uint32_t)CORDIC_Iteration_16,
                                          (uint32_t)CORDIC_Hyperbolic,
                                          (uint32_t)CORDIC_Vector));
        while (!Cordic_HWA_Get_Stat(pCORDIC))
        {
        }
        Cordic_HWA_Clear_Stat(pCORDIC);
        tRetVal = (CORDIC_Radical_Type)(Cordic_HWA_Get_XOutput(pCORDIC)) / MAX_CONVERT_COEFF_DIV16;
#if CORDIC_DEV_ERROR_REPORT == STD_ON
    }
#endif
    return tRetVal;
}

/**
 * @brief The function to calculate circular arctanh
 *
 * @param y the input value
 */
CORDIC_Arctanh_Type Cordic_Arctanh(CORDIC_InstanceType eInstance, const float y)
{
    CORDIC_Type *const  pCORDIC = s_apCordicBase[eInstance];
    CORDIC_Arctanh_Type tRetVal;
#if CORDIC_DEV_ERROR_REPORT == STD_ON
    if (eInstance >= CORDIC_INSTANCE_COUNT)
    {
        CORDIC_ReportDevError(CORDIC_ARCTANH_ID, CORDIC_E_PARAM_INSTANCE);
    }
    else
    {
#endif

        int32_t x_input = ARCTANH_XINPUT_FIX_COEFF;
        int32_t y_input = ARCTANH_YINPUT_FIX_COEFF(y);

        Cordic_HWA_Set_XInput(pCORDIC, x_input);
        Cordic_HWA_Set_YInput(pCORDIC, y_input);
        Cordic_HWA_Set_ZInput(pCORDIC, 0);
        /* Disable interrupt + Iteration Number16 + Hyperbolic system + Vector mode */
        Cordic_HWA_SetCtrl(pCORDIC,
                           CORDIC_CTR_VAL(1,
                                          false,
                                          (uint32_t)CORDIC_Iteration_16,
                                          (uint32_t)CORDIC_Hyperbolic,
                                          (uint32_t)CORDIC_Vector));
        while (!Cordic_HWA_Get_Stat(pCORDIC))
        {
        }
        Cordic_HWA_Clear_Stat(pCORDIC);
        /* 10007997.084103 = 134217728.f * 13.42177 / 180 */;
        tRetVal = (CORDIC_Arctanh_Type)(Cordic_HWA_Get_ZOutput(pCORDIC)) / ARCTANH_OUTPUT_FIX_COEFF;
#if CORDIC_DEV_ERROR_REPORT == STD_ON
    }
#endif
    return tRetVal;
}

/**
 * @brief The function to calculate ln
 *
 * @param y the input value (0.1068482375 , 9.3590687463)
 */
CORDIC_Ln_Type Cordic_Extended_LN(CORDIC_InstanceType eInstance, const float y)
{
#if CORDIC_DEV_ERROR_REPORT == STD_ON
    if (eInstance >= CORDIC_INSTANCE_COUNT)
    {
        CORDIC_ReportDevError(CORDIC_EXTENDED_LN_ID, CORDIC_E_PARAM_INSTANCE);
    }
    else
    {
#endif
        CORDIC_Type *const pCORDIC = s_apCordicBase[eInstance];
        CORDIC_Ln_Type     tRetVal;
        /*** 134217728 = 2147483648 / 16 ***/
        int32_t x_input = LIN_XINPUT_FIX_COEFF(y);
        int32_t y_input = LIN_YINPUT_FIX_COEFF(y);
        Cordic_HWA_Set_XInput(pCORDIC, x_input);
        Cordic_HWA_Set_YInput(pCORDIC, y_input);
        Cordic_HWA_Set_ZInput(pCORDIC, 0);
        /* Disable interrupt + Iteration Number16 + Hyperbolic system + Vector mode */
        Cordic_HWA_SetCtrl(pCORDIC,
                           CORDIC_CTR_VAL(4,
                                          false,
                                          (uint32_t)CORDIC_Iteration_16,
                                          (uint32_t)CORDIC_Hyperbolic,
                                          (uint32_t)CORDIC_Vector));
        while (!Cordic_HWA_Get_Stat(pCORDIC))
        {
        }
        Cordic_HWA_Clear_Stat(pCORDIC);
        /*** 67108864 = 2147483648.f.f / 32 ***/;
        tRetVal = (CORDIC_Ln_Type)(Cordic_HWA_Get_ZOutput(pCORDIC)) / LIN_OUTPUT_FIX_COEFF;
        return tRetVal;
#if CORDIC_DEV_ERROR_REPORT == STD_ON
    }
#endif
}

/**
 * @brief The function to calculate sqrt
 *Cordic_Extended_Sqrt
 * @param y the input value (0.0267120594,2.3397671865)
 */
CORDIC_Sqrt_Type Cordic_Extended_Sqrt(CORDIC_InstanceType eInstance, const float y)
{
    CORDIC_Type *const  pCORDIC = s_apCordicBase[eInstance];
    CORDIC_Radical_Type tRetVal;
#if CORDIC_DEV_ERROR_REPORT == STD_ON
    if (eInstance >= CORDIC_INSTANCE_COUNT)
    {
        CORDIC_ReportDevError(CORDIC_EXTENDED_SQRT_ID, CORDIC_E_PARAM_INSTANCE);
    }
    else
    {
#endif
        /*** 648270021 = 2593080084 / 4 ***/
        int32_t x_input = SQRT_XINPUT_FIX_COEFF(y);
        int32_t y_input = SQRT_YINPUT_FIX_COEFF(y);

        Cordic_HWA_Set_XInput(pCORDIC, x_input);
        Cordic_HWA_Set_YInput(pCORDIC, y_input);
        Cordic_HWA_Set_ZInput(pCORDIC, 0);
        /* Disable interrupt + Iteration Number16 + Hyperbolic system + Vector mode */
        Cordic_HWA_SetCtrl(pCORDIC,
                           CORDIC_CTR_VAL(2,
                                          false,
                                          (uint32_t)CORDIC_Iteration_16,
                                          (uint32_t)CORDIC_Hyperbolic,
                                          (uint32_t)CORDIC_Vector));
        while (!Cordic_HWA_Get_Stat(pCORDIC))
        {
        }
        Cordic_HWA_Clear_Stat(pCORDIC);
        /*** 536870912 = 2147483648 / 4 ***/
        tRetVal = (CORDIC_Sqrt_Type)(Cordic_HWA_Get_XOutput(pCORDIC)) / SQRT_OUTPUT_FIX_COEFF;
        return tRetVal;
#if CORDIC_DEV_ERROR_REPORT == STD_ON
    }
#endif
}
/**
 * @}
 */
#endif
