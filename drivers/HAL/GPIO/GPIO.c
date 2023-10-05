/**
 * --------------------------------------------------------------------------------------------------------------------------------------
 * |    @title          :   General Purpose Input/Output                                                                                |
 * |    @file           :   GPIO_header.h                                                                                               |
 * |    @author         :   Abdelrahman Mohamed Salem                                                                                   |
 * |    @origin_date    :   03/09/2023                                                                                                  |
 * |    @version        :   1.0.0                                                                                                       |
 * |    @tool_chain     :   GNU Tools for STM32                                                                                         |
 * |    @compiler       :   GCC                                                                                                         |
 * |    @C_standard     :   ISO C99 (-std=c99)                                                                                          |
 * |    @target         :   stm32f407VGTX                                                                                               |
 * |    @notes          :   None                                                                                                        |
 * |    @license        :   MIT License                                                                                                 |
 * |    @brief          :   this header file contains functions implementations regarding the General Purpose Input/Output              |
 * --------------------------------------------------------------------------------------------------------------------------------------
 * |    MIT License                                                                                                                     |
 * |                                                                                                                                    |
 * |    Copyright (c) - 2023 - Abdelrahman Mohamed Salem - All Rights Reserved                                                          |
 * |                                                                                                                                    |
 * |    Permission is hereby granted, free of charge, to any person obtaining a copy                                                    |
 * |    of this software and associated documentation files (the "Software"), to deal                                                   |
 * |    in the Software without restriction, including without limitation the rights                                                    |
 * |    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell                                                       |
 * |    copies of the Software, and to permit persons to whom the Software is                                                           |
 * |    furnished to do so, subject to the following conditions:                                                                        |
 * |                                                                                                                                    |
 * |    The above copyright notice and this permission notice shall be included in all                                                  |
 * |    copies or substantial portions of the Software.                                                                                 |
 * |                                                                                                                                    |
 * |    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR                                                      |
 * |    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,                                                        |
 * |    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE                                                     |
 * |    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER                                                          |
 * |    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,                                                   |
 * |    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE                                                   |
 * |    SOFTWARE.                                                                                                                       |
 * --------------------------------------------------------------------------------------------------------------------------------------
 * |    @history_change_list                                                                                                            |
 * |    ====================                                                                                                            |
 * |    Date            Version         Author                          Description                                                     |
 * |    03/09/2023      1.0.0           Abdelrahman Mohamed Salem       Interface Created.                                              |
 * --------------------------------------------------------------------------------------------------------------------------------------
 */

/******************************************************************************
 * Includes
 *******************************************************************************/
/**
 * @reason: contains standard definitions for standard integers
 */
#include "../../lib/stdint.h"

/**
 * @reason: contains definition for NULL
 */
#include "../../lib/common.h"

/**
 * @reason: contains constants common values
 */
#include "../../lib/constants.h"

/**
 * @reason: contains useful functions that deals with bit level math
 */
#include "../../Lib/math_btt.h"

/**
 * @reason: contains all initial user configurations for GPIO
 */
#include "GPIO_config.h"

/**
 * @reason: contains all the interface functions to be implemented
 */
#include "GPIO_header.h"

/**
 * @reason: contains all register addresses and bit definitions for GPIO registers
 */
#include "GPIO_reg.h"

/**
 * @reason: contains all private function declaration and global variables
 */
#include "GPIO_private.h"

/******************************************************************************
 * Module Preprocessor Constants
 *******************************************************************************/

/******************************************************************************
 * Module Preprocessor Macros
 *******************************************************************************/

/******************************************************************************
 * Module Typedefs
 *******************************************************************************/

/******************************************************************************
 * Module Variable Definitions
 *******************************************************************************/

/******************************************************************************
 * Function Prototypes
 *******************************************************************************/

/******************************************************************************
 * Function Definitions
 *******************************************************************************/

HAL_GPIO_ErrStates_t HAL_GPIO_Init()
{
    // local used variables
    HAL_GPIO_ErrStates_t local_errState = HAL_GPIO_OK;
    uint8_t local_u8Iterator1 = 0;
    uint8_t local_u8Iterator2 = 0;
    uint32_t local_u32TempReg = 0;
    uint32_t local_u32Temp2Reg = 0;

    // check for errors
    for (local_u8Iterator1 = 0; local_u8Iterator1 < HAL_GPIO_MAX_PORT_INDEX; local_u8Iterator1++)
    {
        for (local_u8Iterator2 = 0; local_u8Iterator2 < HAL_GPIO_MAX_PIN_INDEX; local_u8Iterator2++)
        {
            if (globalConstArr_GPIO_PinsConfig_t[local_u8Iterator1][local_u8Iterator2].LockEnable >= LIB_CONSTANTS_MAX_LOCK_STATE ||
                globalConstArr_GPIO_PinsConfig_t[local_u8Iterator1][local_u8Iterator2].Mode >= HAL_GPIO_MAX_PIN_MODE ||
                (globalConstArr_GPIO_PinsConfig_t[local_u8Iterator1][local_u8Iterator2].PINNumber && (globalConstArr_GPIO_PinsConfig_t[local_u8Iterator1][local_u8Iterator2].PINNumber & (globalConstArr_GPIO_PinsConfig_t[local_u8Iterator1][local_u8Iterator2].PINNumber - 1))) ||
                (globalConstArr_GPIO_PinsConfig_t[local_u8Iterator1][local_u8Iterator2].GPIOName && (globalConstArr_GPIO_PinsConfig_t[local_u8Iterator1][local_u8Iterator2].GPIOName & (globalConstArr_GPIO_PinsConfig_t[local_u8Iterator1][local_u8Iterator2].GPIOName - 1))) ||
                globalConstArr_GPIO_PinsConfig_t[local_u8Iterator1][local_u8Iterator2].OutputType >= HAL_GPIO_MAX_OUT_MODE ||
                globalConstArr_GPIO_PinsConfig_t[local_u8Iterator1][local_u8Iterator2].OutputSpeed >= HAL_GPIO_MAX_OUT_SPEED ||
                globalConstArr_GPIO_PinsConfig_t[local_u8Iterator1][local_u8Iterator2].PullUpDown >= HAL_GPIO_MAX_PULL_UP_DOWN)
            {
                local_errState = HAL_GPIO_ERR_INVALID_CONFIG;
                goto label;
            }
        }
    }

label:

    // main function
    if (local_errState == HAL_GPIO_OK)
    {

        for (local_u8Iterator1 = 0; local_u8Iterator1 < HAL_GPIO_MAX_PORT_INDEX; local_u8Iterator1++)
        {
            // Configre MODER
            local_u32TempReg = global_pGPIOs[local_u8Iterator1]->GPIOx_MODER;
            for (local_u8Iterator2 = 0; local_u8Iterator2 < HAL_GPIO_MAX_PIN_INDEX; local_u8Iterator2++)
            {
                LIB_MATH_BTT_ASSIGN_BITS(local_u32TempReg, local_u8Iterator2 * 2, globalConstArr_GPIO_PinsConfig_t[local_u8Iterator1][local_u8Iterator2].Mode, 2);
            }
            global_pGPIOs[local_u8Iterator1]->GPIOx_MODER = local_u32TempReg;

            // Configre OTYPER
            local_u32TempReg = global_pGPIOs[local_u8Iterator1]->GPIOx_OTYPER;
            for (local_u8Iterator2 = 0; local_u8Iterator2 < HAL_GPIO_MAX_PIN_INDEX; local_u8Iterator2++)
            {
                LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, local_u8Iterator2, globalConstArr_GPIO_PinsConfig_t[local_u8Iterator1][local_u8Iterator2].OutputType);
            }
            global_pGPIOs[local_u8Iterator1]->GPIOx_OTYPER = local_u32TempReg;

            // Configre OSPEEDRR
            local_u32TempReg = global_pGPIOs[local_u8Iterator1]->GPIOx_OSPEEDR;
            for (local_u8Iterator2 = 0; local_u8Iterator2 < HAL_GPIO_MAX_PIN_INDEX; local_u8Iterator2++)
            {
                LIB_MATH_BTT_ASSIGN_BITS(local_u32TempReg, local_u8Iterator2 * 2, globalConstArr_GPIO_PinsConfig_t[local_u8Iterator1][local_u8Iterator2].OutputSpeed, 2);
            }
            global_pGPIOs[local_u8Iterator1]->GPIOx_OSPEEDR = local_u32TempReg;

            // Configre PUPDR
            local_u32TempReg = global_pGPIOs[local_u8Iterator1]->GPIOx_PUPDR;
            for (local_u8Iterator2 = 0; local_u8Iterator2 < HAL_GPIO_MAX_PIN_INDEX; local_u8Iterator2++)
            {
                LIB_MATH_BTT_ASSIGN_BITS(local_u32TempReg, local_u8Iterator2 * 2, globalConstArr_GPIO_PinsConfig_t[local_u8Iterator1][local_u8Iterator2].PullUpDown, 2);
            }
            global_pGPIOs[local_u8Iterator1]->GPIOx_PUPDR = local_u32TempReg;

            // Configre LCKR
            local_u32TempReg = global_pGPIOs[local_u8Iterator1]->GPIOx_LCKR;
            for (local_u8Iterator2 = 0; local_u8Iterator2 < HAL_GPIO_MAX_PIN_INDEX; local_u8Iterator2++)
            {
                LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, local_u8Iterator2, globalConstArr_GPIO_PinsConfig_t[local_u8Iterator1][local_u8Iterator2].LockEnable);
            }
            global_pGPIOs[local_u8Iterator1]->GPIOx_LCKR = local_u32TempReg;
            if (local_u32TempReg != 0)
            {
                LIB_MATH_BTT_SET_BIT(global_pGPIOs[local_u8Iterator1]->GPIOx_LCKR, HAL_GPIOx_LCKR_LCKK);
                LIB_MATH_BTT_CLR_BIT(global_pGPIOs[local_u8Iterator1]->GPIOx_LCKR, HAL_GPIOx_LCKR_LCKK);
                LIB_MATH_BTT_SET_BIT(global_pGPIOs[local_u8Iterator1]->GPIOx_LCKR, HAL_GPIOx_LCKR_LCKK);
                local_u32TempReg = global_pGPIOs[local_u8Iterator1]->GPIOx_LCKR;
            }

            // Configre AFRL and AFRL
            local_u32TempReg = global_pGPIOs[local_u8Iterator1]->GPIOx_AFRL;
            local_u32Temp2Reg = global_pGPIOs[local_u8Iterator1]->GPIOx_AFRH;
            for (local_u8Iterator2 = 0; local_u8Iterator2 < HAL_GPIO_MAX_PIN_INDEX; local_u8Iterator2++)
            {
                if (local_u8Iterator2 <= 7)
                {
                    LIB_MATH_BTT_ASSIGN_BITS(local_u32TempReg, local_u8Iterator2 * 4, globalConstArr_GPIO_PinsConfig_t[local_u8Iterator1][local_u8Iterator2].AlternateFunction, 4);
                }
                else
                {
                    LIB_MATH_BTT_ASSIGN_BITS(local_u32Temp2Reg, (local_u8Iterator2 - 8) * 4, globalConstArr_GPIO_PinsConfig_t[local_u8Iterator1][local_u8Iterator2].AlternateFunction, 4);
                }
            }
            global_pGPIOs[local_u8Iterator1]->GPIOx_AFRL = local_u32TempReg;
            global_pGPIOs[local_u8Iterator1]->GPIOx_AFRH = local_u32Temp2Reg;
        }
    }
    else
    {
        // do nothing
    }

    return local_errState;
}

/**
 *
 */
HAL_GPIO_ErrStates_t HAL_GPIO_PinStateModify(uint16_t arg_u16GpioName, uint16_t arg_u16PinNumber, const uint8_t argConst_u8Operation)
{
    // local used variables
    HAL_GPIO_ErrStates_t local_errState = HAL_GPIO_OK;
    uint8_t local_u8BitMSBSetPos = 0;

    // check for errors
    if (arg_u16GpioName > HAL_GPIO_MAX_PORT || arg_u16GpioName == 0 || arg_u16PinNumber == 0 || argConst_u8Operation >= HAL_GPIO_MAX_PIN_OP)
    {
        local_errState = HAL_GPIO_ERR_INVALID_PARAMS;
    }

    // main function
    if (local_errState == HAL_GPIO_OK)
    {
        while (arg_u16GpioName != 0)
        {
            local_u8BitMSBSetPos = LIB_MATH_BTT_u8GetMSBSetPos(arg_u16GpioName);
            LIB_MATH_BTT_CLR_BIT(arg_u16GpioName, local_u8BitMSBSetPos);

            switch (argConst_u8Operation)
            {
            case HAL_GPIO_PIN_OP_WRITE_HIGH:
                global_pGPIOs[local_u8BitMSBSetPos]->GPIOx_BSRR = arg_u16PinNumber;
                break;

            case HAL_GPIO_PIN_OP_WRITE_LOW:
                global_pGPIOs[local_u8BitMSBSetPos]->GPIOx_BSRR = arg_u16PinNumber << 16;
                break;

            case HAL_GPIO_PIN_OP_TOGGLE:
                global_pGPIOs[local_u8BitMSBSetPos]->GPIOx_ODR ^= arg_u16PinNumber;
                break;

            default:
                break;
            }
        }
    }

    return local_errState;
}

/**
 *
 */
HAL_GPIO_ErrStates_t HAL_GPIO_PinStateRead(uint16_t arg_u16GpioName, uint16_t arg_u16PinNumber, uint8_t *const arg_constpu8State)
{
    // local used variables
    HAL_GPIO_ErrStates_t local_errState = HAL_GPIO_OK;
    uint8_t local_u8BitMSBSetPos = 0;

    // check for errors
    if (arg_u16GpioName > HAL_GPIO_MAX_PORT || arg_u16GpioName == 0 || arg_u16PinNumber == 0 || arg_constpu8State == NULL)
    {
        local_errState = HAL_GPIO_ERR_INVALID_PARAMS;
    }

    // main function
    if (local_errState == HAL_GPIO_OK)
    {
        local_u8BitMSBSetPos = LIB_MATH_BTT_u8GetMSBSetPos(arg_u16GpioName);
        *arg_constpu8State = LIB_MATH_BTT_GET_BIT(global_pGPIOs[local_u8BitMSBSetPos]->GPIOx_IDR, local_u8BitMSBSetPos);
    }

    return local_errState;
}

/*************** END OF FUNCTIONS ***************************************************************************/
