
/**
 * --------------------------------------------------------------------------------------------------------------------------------------
 * |    @title          :   General Purpose Input/Output                                                                                |
 * |    @file           :   GPIO_private.h                                                                                              |
 * |    @author         :   Abdelrahman Mohamed Salem                                                                                   |
 * |    @origin_date    :   03/09/2023                                                                                                  |
 * |    @version        :   1.0.0                                                                                                       |
 * |    @tool_chain     :   GNU Tools for STM32                                                                                         |
 * |    @compiler       :   GCC                                                                                                         |
 * |    @C_standard     :   ISO C99 (-std=c99)                                                                                          |
 * |    @target         :   stm32f407VGTX                                                                                               |
 * |    @notes          :   None                                                                                                        |
 * |    @license        :   MIT License                                                                                                 |
 * |    @brief          :   this header file contains private functions and variables for the General Purpose Input/Output (GPIO)       |                                                               |
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

#ifndef HAL_GPIO_PRIVATE_H_
#define HAL_GPIO_PRIVATE_H_

/******************************************************************************
 * Includes
 *******************************************************************************/
/**
 * @reason: contains definition for function callback
 */
#include "../../lib/common.h"

/**
 * @reason: contains definitions for standard integers
 */
#include "../../lib/stdint.h"

/**
 * @reason: contains all math bits functions
 */
#include "../../lib/math_btt.h"

/******************************************************************************
 * Preprocessor Constants
 *******************************************************************************/

/******************************************************************************
 * Configuration Constants
 *******************************************************************************/

/******************************************************************************
 * Macros
 *******************************************************************************/

/**
 * @enum: HAL_GPIO__PortsIndexes_t
 * @brief: these are indexes used in globalConstArr_GPIO_PinsConfig_t.
 */
typedef enum
{
    HAL_GPIO_PORTA_INDEX = 0,
    HAL_GPIO_PORTB_INDEX = 1,
    HAL_GPIO_PORTC_INDEX = 2,
    HAL_GPIO_PORTD_INDEX = 3,
    HAL_GPIO_PORTE_INDEX = 4,
    HAL_GPIO_PORTF_INDEX = 5,
    HAL_GPIO_PORTG_INDEX = 6,
    HAL_GPIO_PORTH_INDEX = 7,
    HAL_GPIO_PORTI_INDEX = 8,
    HAL_GPIO_MAX_PORT_INDEX,
} HAL_GPIO__PortsIndexes_t;

/**
 * @enum: HAL_GPIO_PinsIndexes_t
 * @brief: these are indexes used in globalConstArr_GPIO_PinsConfig_t.
 */
typedef enum
{
    HAL_GPIO_PIN0_INDEX = 0,
    HAL_GPIO_PIN1_INDEX = 1,
    HAL_GPIO_PIN2_INDEX = 2,
    HAL_GPIO_PIN3_INDEX = 3,
    HAL_GPIO_PIN4_INDEX = 4,
    HAL_GPIO_PIN5_INDEX = 5,
    HAL_GPIO_PIN6_INDEX = 6,
    HAL_GPIO_PIN7_INDEX = 7,
    HAL_GPIO_PIN8_INDEX = 8,
    HAL_GPIO_PIN9_INDEX = 9,
    HAL_GPIO_PIN10_INDEX = 10,
    HAL_GPIO_PIN11_INDEX = 11,
    HAL_GPIO_PIN12_INDEX = 12,
    HAL_GPIO_PIN13_INDEX = 13,
    HAL_GPIO_PIN14_INDEX = 14,
    HAL_GPIO_PIN15_INDEX = 15,
    HAL_GPIO_MAX_PIN_INDEX,
} HAL_GPIO_PinsIndexes_t;

/******************************************************************************
 * Function Prototypes
 *******************************************************************************/

/*** End of File **************************************************************/
#endif /*HAL_GPIO_PRIVATE_H_*/
