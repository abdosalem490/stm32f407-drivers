/**
 * --------------------------------------------------------------------------------------------------------------------------------------
 * |    @title          :   power controller                                                                                            |
 * |    @file           :   PWR_private.h                                                                                               |
 * |    @author         :   Abdelrahman Mohamed Salem                                                                                   |
 * |    @origin_date    :   16/08/2023                                                                                                  |
 * |    @version        :   1.0.0                                                                                                       |
 * |    @tool_chain     :   GNU Tools for STM32                                                                                         |
 * |    @compiler       :   GCC                                                                                                         |
 * |    @C_standard     :   ISO C99 (-std=c99)                                                                                          |
 * |    @target         :   stm32f407VGTX                                                                                               |
 * |    @notes          :   None                                                                                                        |
 * |    @license        :   MIT License                                                                                                 |
 * |    @brief          :   this header file contains private functions and variables for the Power Controller (PWR)                    |                                                               |
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
 * |    16/08/2023      1.0.0           Abdelrahman Mohamed Salem       Interface Created.                                              |
 * --------------------------------------------------------------------------------------------------------------------------------------
 */

#ifndef HAL_PWR_PRIVATE_H_
#define HAL_PWR_PRIVATE_H_

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

/******************************************************************************
 * Preprocessor Constants
 *******************************************************************************/

/******************************************************************************
 * Configuration Constants
 *******************************************************************************/

/******************************************************************************
 * Macros
 *******************************************************************************/

/******************************************************************************
 * Tables
 *******************************************************************************/

/******************************************************************************
 * Typedefs
 *******************************************************************************/

/******************************************************************************
 * Variables
 *******************************************************************************/

/**
 * @brief: global configurations variables
 */
static uint8_t global_u8SleepMethod; /**< used to indicates whether to use WFI or WFE for sleep*/

/**
 * @brief: Callback functions
 */
static functionCallBack_t global_pPVDLevelChangeCallBack_t = NULL; /**< used to callback whenever VDD be higher/lower than PVD threshold, but make sure to enable PVD*/

/******************************************************************************
 * Function Prototypes
 *******************************************************************************/

/*** End of File **************************************************************/
#endif /*HAL_PWR_PRIVATE_H_*/