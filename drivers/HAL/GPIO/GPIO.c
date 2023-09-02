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

    // check for errors

    // main function
    if (local_errState == HAL_GPIO_OK)
    {
        /* code */
    }

    return local_errState;
}

HAL_GPIO_ErrStates_t HAL_GPIO_PinStateModify(uint16_t arg_u16GpioName, uint16_t arg_u16PinNumber, const uint8_t argConst_u8Operation)
{
    // local used variables
    HAL_GPIO_ErrStates_t local_errState = HAL_GPIO_OK;

    return local_errState;
}

HAL_GPIO_ErrStates_t HAL_GPIO_PinStateRead(uint16_t arg_u16GpioName, uint16_t arg_u16PinNumber, uint8_t *const arg_constpu8State)
{
    // local used variables
    HAL_GPIO_ErrStates_t local_errState = HAL_GPIO_OK;

    return local_errState;
}

/*************** END OF FUNCTIONS ***************************************************************************/
