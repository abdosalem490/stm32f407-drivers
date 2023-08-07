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

/**
 * @brief: controls which operation to be executed in interrupt handler
 */
typedef enum
{
    HAL_FLASH_IRQ_OP_NONE,  /**< no operation to be executed*/
    HAL_FLASH_IRQ_OP_ERASE, /**< sector erase to be executed*/
    HAL_FLASH_IRQ_OP_WRITE, /**< flash write to be executed*/
    HAL_FLASH_IRQ_OP_FILL,  /**< flash fill to be executed*/
} HAL_FLASH_IRQ_OP;

/******************************************************************************
 * Variables
 *******************************************************************************/
/**
 *  @reference: HAL_FLASH_CALLBACKS
 *  @brief: callback functions used when configuring operation of flash to be interrupt based
 *  @related: @HAL_FLASH_CallbacksTypes_t in "flash_header.h"
 */
static functionCallBack_t global_pOperationSuccess_t = NULL;          /**< this is the function to be called when an embedded flash memory operation is success*/
static functionCallBack_t global_pErrWriteProtection_t = NULL;        /**< this is the function to be called when a write protection error happens*/
static functionCallBack_t global_pErrProgrammingSequence_t = NULL;    /**< this is the function to be called when a programming sequence error happens*/
static functionCallBack_t global_pErrProgrammingParallelism_t = NULL; /**< this is the function to be called when a programming parallelism error happens*/
static functionCallBack_t global_pErrProgrammingAlignment_t = NULL;   /**< this is the function to be called when a programming alignment error happens*/
static functionCallBack_t global_pErrOperation_t = NULL;              /**< this is the function to be called when an unidentified error happens*/

/**
 * @brief: these are some configuration variables that changes the behavior of some interfaces
 * @reference: HAL_FLASH_CONFIG_VARS
 * @related: @HAL_FLASH_ConfigKeys_t in "flash_header.h"
 */
static uint8_t global_u8BehaviorType = HAL_FLASH_CONFIG_VAL_OPERATION_TYPE_BLOCKING;

/**
 * @brief: this is a variable holding which sector to erase in interrupt based operation
 */
static uint16_t global_u16SectorsToErase = 0;

/**
 * @brief: flag used to indicate the success of interrupt based operation
 */
static uint8_t global_u8SuccessOperationState = LIB_CONSTANTS_FAIL;

/**
 * @brief: these four pointer are used for different access type of flash memory according to program size
 */
uint8_t *global_pu8MemWriteVar = NULL;   /**< used for byte access*/
uint16_t *global_pu16MemWriteVar = NULL; /**< used for half-word access*/
uint32_t *global_pu32MemWriteVar = NULL; /**< used for word access*/
uint64_t *global_pu64MemWriteVar = NULL; /**< used for double-word access*/

/**
 * @brief: these variables are used to keep track of the flash write in interrupt mode
 */
const uint8_t *globalConst_pu8WriteData = NULL; /**< this is the pointer that points to data to be written in interrupt mode*/
uint32_t global_u32DataLen = 0;                 /**< this is the length of data to be written in bytes used in flash write in interrupt mode*/
uint8_t global_u8WriteData = 0;                 /**< this is the data to be written in case of function Fill*/

/**
 * @brief: this variable is used to keep track which operation to be done in interrupt handler
 */
uint8_t global_u8WhichOperationToExecute = HAL_FLASH_IRQ_OP_NONE;

/******************************************************************************
 * Function Prototypes
 *******************************************************************************/
/**
 * @brief: this function gets all hardware errors, used internally by many functions, refer to @HAL_FLASH_ErrStates_t in "flash_header.h" to know what does it return
 */
static HAL_FLASH_ErrStates_t HAL_FLASH_GetHardwareErrors();

/*** End of File **************************************************************/
#endif /*HAL_FLASH_PRIVATE_H_*/