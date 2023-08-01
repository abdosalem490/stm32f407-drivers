/**
 * --------------------------------------------------------------------------------------------------------------------------------------
 * |    @title          :   Flash                                                                                                       |
 * |    @file           :   flash_private.h                                                                                             |
 * |    @author         :   Abdelrahman Mohamed Salem                                                                                   |
 * |    @origin_date    :   31/07/2023                                                                                                  |
 * |    @version        :   1.0.0                                                                                                       |
 * |    @tool_chain     :   GNU Tools for STM32                                                                                         |
 * |    @compiler       :   GCC                                                                                                         |
 * |    @C_standard     :   ISO C99 (-std=c99)                                                                                          |
 * |    @target         :   stm32f407VGTX                                                                                               |
 * |    @notes          :   None                                                                                                        |
 * |    @license        :   MIT License                                                                                                 |
 * |    @brief          :   this file contains private variables and function used internally in implementation code                    |
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
 * |    31/07/2023      1.0.0           Abdelrahman Mohamed Salem       Interface Created.                                              |
 * --------------------------------------------------------------------------------------------------------------------------------------
 */

#ifndef HAL_FLASH_PRIVATE_H_
#define HAL_FLASH_PRIVATE_H_

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
 * @reason: assign initial values for configuration variables
 */
#include "flash_header.h"

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
 * Typedefs
 *******************************************************************************/

/******************************************************************************
 * Variables
 *******************************************************************************/
/**
 *  @reference: HAL_FLASH_CALLBACKS
 *  @brief: callback functions used when configuring operation of flash to be interrupt based
 *  @related: @HAL_FLASH_CallbacksTypes_t in "flash_header.h"
 */
functionCallBack_t global_pOperationSuccess_t = NULL;          /**< this is the function to be called when an embedded flash memory operation is success*/
functionCallBack_t global_pErrWriteProtection_t = NULL;        /**< this is the function to be called when a write protection error happens*/
functionCallBack_t global_pErrProgrammingSequence_t = NULL;    /**< this is the function to be called when a programming sequence error happens*/
functionCallBack_t global_pErrProgrammingParallelism_t = NULL; /**< this is the function to be called when a programming parallelism error happens*/
functionCallBack_t global_pErrProgrammingAlignment_t = NULL;   /**< this is the function to be called when a programming alignment error happens*/
functionCallBack_t global_pErrOperation_t = NULL;              /**< this is the function to be called when an unidentified error happens*/

/**
 * @brief: these are some configuration variables that changes the behavior of some interfaces
 * @reference: HAL_FLASH_CONFIG_VARS
 * @related: @HAL_FLASH_ConfigKeys_t in "flash_header.h"
 */
uint8_t global_u8BehaviorType = HAL_FLASH_CONFIG_VAL_OPERATION_TYPE_BLOCKING;

/******************************************************************************
 * Function Prototypes
 *******************************************************************************/

/*** End of File **************************************************************/
#endif /*HAL_FLASH_PRIVATE_H_*/