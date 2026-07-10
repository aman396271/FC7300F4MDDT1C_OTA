/**
 * @file module_driver_gpio.h
 * @author Flagchip
 * @brief GPIO driver type definition and API
 * @version 2.0.0
 * @date 2024-08-20
 *
 * SDK Version: 2.6.0
 *

 * @copyright Copyright (c) 2020-2024 Flagchip Semiconductors Co., Ltd.
 *
 * @details
 */
/********************************************************************************
*   Revision History:
*
*   Version     Date          Initials       CR#          Descriptions
*   ---------   ----------    ------------   ----------   ---------------
*   0.1.0       31/12/2022    Flagchip071    N/A          First version for FC7300
*   0.2.0       4/2/2022      Flagchip071    N/A          0.2.0 release
********************************************************************************/

#include "module_driver_gpio.h"

#if GPIO_INSTANCE_COUNT > 0U


#ifndef GPIO_DEV_ERROR_REPORT
    #define GPIO_DEV_ERROR_REPORT   STD_OFF
#endif

#if GPIO_DEV_ERROR_REPORT == STD_ON
    #define CPIO_ReportDevError(func, error) ReportDevError(GPIO_MODULE_ID, func, error)
#endif

/********* Local Variables ************/
/** @brief Gpio instance list */
static GPIO_Type *const s_pGpioDriverInstanceTable[GPIO_INSTANCE_COUNT] = GPIO_BASE_PTRS;
#if GPIO_DEV_ERROR_REPORT == STD_ON
    /** @brief Pin mask list */
    static uint32_t const s_pPinMaskTable[GPIO_INSTANCE_COUNT] = GPIO_PIN_MASK;
#endif
/***************PORT GPIO Functions*****************/
/**
 * @brief Toggle gpio api
 *
 * @param GPIO_InstanceType eGpio GPIO Instance
 * @param u32Pins The bit of u8Pins indicate the pin number of this Port.
 */
void GPIO_Toggle(const GPIO_InstanceType eGpio, const uint32_t u32Pins)
{
    #if GPIO_DEV_ERROR_REPORT == STD_ON

    if (eGpio >= GPIO_INSTANCE_COUNT)
    {
        CPIO_ReportDevError(GPIO_Toggle_ID, GPIO_E_PARAM_INSTANCE);
    }
    else
    {
        uint32_t u32DetPins = u32Pins;
        uint32_t u32ValidPins = (uint32_t)s_pPinMaskTable[eGpio];

        if (u32DetPins != (u32DetPins & u32ValidPins))
        {
            CPIO_ReportDevError(GPIO_Toggle_ID, GPIO_E_PARAM_PIN);
        }
        else
        {
    #endif

            GPIO_Type *const pGpio = s_pGpioDriverInstanceTable[eGpio];

            GPIO_HWA_TogglePort(pGpio, u32Pins);

    #if GPIO_DEV_ERROR_REPORT == STD_ON
        }
    }
    #endif
}

/**
 * @brief Read level of input port pins.
 *
 * @param GPIO_InstanceType eGpio GPIO Instance
 * @param u32Pins The bit of u8Pins indicate the pin number of this Port.
 * @return Pins level
 */
uint32_t GPIO_ReadPins(const GPIO_InstanceType eGpio, const uint32_t u32Pins)
{
    #if GPIO_DEV_ERROR_REPORT == STD_ON

    if (eGpio >= GPIO_INSTANCE_COUNT)
    {
        CPIO_ReportDevError(GPIO_Toggle_ID, GPIO_E_PARAM_INSTANCE);
    }
    else
    {
        uint32_t u32DetPins = u32Pins;
        uint32_t u32ValidPins = (uint32_t)s_pPinMaskTable[eGpio];

        if (u32DetPins != (u32DetPins & u32ValidPins))
        {
            CPIO_ReportDevError(GPIO_Toggle_ID, GPIO_E_PARAM_PIN);
        }
        else
        {
    #endif

            GPIO_Type *const pGpio = s_pGpioDriverInstanceTable[eGpio];

            uint32_t u32PinLevels = 0x00000000;

            u32PinLevels = (GPIO_HWA_ReadPortDataInput(pGpio) & u32Pins);

            return u32PinLevels;

    #if GPIO_DEV_ERROR_REPORT == STD_ON
        }
    }
    #endif
}

/**
 * @brief Write gpio level to u8Pins.
 *
 * @param GPIO_InstanceType eGpio GPIO Instance
 * @param u32Pins The bit of u8Pins indicate the pin number of this Port.
 * @param eOutput Output level enumeration
 */
void GPIO_WritePins(const GPIO_InstanceType eGpio, const uint32_t u32Pins, const Gpio_LevelType eOutput)
{
    #if GPIO_DEV_ERROR_REPORT == STD_ON

    if (eGpio >= GPIO_INSTANCE_COUNT)
    {
        CPIO_ReportDevError(GPIO_WritePins_ID, GPIO_E_PARAM_INSTANCE);
    }
    else
    {
        uint32_t u32DetPins = u32Pins;
        uint32_t u32ValidPins = (uint32_t)s_pPinMaskTable[eGpio];
        if (eOutput > GPIO_HIGH)
        {
            CPIO_ReportDevError(GPIO_WritePins_ID, GPIO_E_PARAM_LEVEL);
        }
        else if (u32DetPins != (u32DetPins & u32ValidPins))
        {
            CPIO_ReportDevError(GPIO_WritePins_ID, GPIO_E_PARAM_PIN);
        }
        else
        {
    #endif

            GPIO_Type *const pGpio = s_pGpioDriverInstanceTable[eGpio];

            if (GPIO_HIGH == eOutput)
            {
                GPIO_HWA_SetPortOutput(pGpio, u32Pins);
            }
            else
            {
                GPIO_HWA_ClearPortOutput(pGpio, u32Pins);
            }
    #if GPIO_DEV_ERROR_REPORT == STD_ON
        }
    }
    #endif
}

/**
 * @brief Set Pins Direction.
 *
 * @param GPIO_InstanceType eGpio GPIO Instance
 * @param u32Pins The bit of u8Pins indicate the pin number of this Port.
 * @param ePindir Pin direction enumeration
 */
void GPIO_SetPinsDir(const GPIO_InstanceType eGpio, const uint32_t u32Pins, const Gpio_Direction ePindir)
{
    #if GPIO_DEV_ERROR_REPORT == STD_ON

    if (eGpio >= GPIO_INSTANCE_COUNT)
    {
        CPIO_ReportDevError(GPIO_SetPinsDir_ID, GPIO_E_PARAM_INSTANCE);
    }
    else
    {
        uint32_t u32DetPins = u32Pins;
        uint32_t u32ValidPins = (uint32_t)s_pPinMaskTable[eGpio];

        if (ePindir > GPIO_OUT)
        {
            CPIO_ReportDevError(GPIO_SetPinsDir_ID, GPIO_E_PARAM_DIRECTION);
        }
        else if (u32DetPins != (u32DetPins & u32ValidPins))
        {
            CPIO_ReportDevError(GPIO_SetPinsDir_ID, GPIO_E_PARAM_PIN);
        }
        else
        {
    #endif

            GPIO_Type *const pGpio = s_pGpioDriverInstanceTable[eGpio];

            if (GPIO_IN == ePindir)
            {
                GPIO_HWA_SetPortDirectionInput(pGpio, u32Pins);
            }
            else
            {
                GPIO_HWA_SetPortDirectionOutput(pGpio, u32Pins);
            }
    #if GPIO_DEV_ERROR_REPORT == STD_ON
        }
    }
    #endif
}

#endif
