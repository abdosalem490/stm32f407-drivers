/**
 * --------------------------------------------------------------------------------------------------------------------------------------
 * |    @title          :   System Configuration Controller                                                                             |
 * |    @file           :   SYSCFG_header.h                                                                                             |
 * |    @author         :   Abdelrahman Mohamed Salem                                                                                   |
 * |    @origin_date    :   04/09/2023                                                                                                  |
 * |    @version        :   1.0.0                                                                                                       |
 * |    @tool_chain     :   GNU Tools for STM32                                                                                         |
 * |    @compiler       :   GCC                                                                                                         |
 * |    @C_standard     :   ISO C99 (-std=c99)                                                                                          |
 * |    @target         :   stm32f407VGTX                                                                                               |
 * |    @notes          :   None                                                                                                        |
 * |    @license        :   MIT License                                                                                                 |
 * |    @brief          :   this header file contains functions implementations regarding the System Configuration Controller           |
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
 * |    04/09/2023      1.0.0           Abdelrahman Mohamed Salem       Interface Created.                                              |
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
 * @reason: contains all initial user configurations for SYSCFG
 */
#include "SYSCFG_config.h"

/**
 * @reason: contains all the interface functions to be implemented
 */
#include "SYSCFG_header.h"

/**
 * @reason: contains all register addresses and bit definitions for SYSCFG registers
 */
#include "SYSCFG_reg.h"

/**
 * @reason: contains all private function declaration and global variables
 */
#include "SYSCFG_private.h"

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

/**
 * @brief: this function is intended to be only used by GPIO peripheral for configuring interrupts
 */
void HAL_SYSCFG_voidAssignEXTILine(const uint8_t argConst_u8EXTILine, const uint8 argConst_u8PortName)
{
    if (argConst_u8EXTILine <= 15 && argConst_u8PortName <= 8)
    {
        LIB_MATH_BTT_ASSIGN_BITS(global_pSYSCFGReg_t->SYSCFG_EXTICR[argConst_u8EXTILine / 4], (argConst_u8EXTILine % 4) * 4, argConst_u8PortName, 4);
    }
}

HAL_SYSCFG_ErrStates_t HAL_SYSCFG_BootFrom(const uint8_t argConst_u8MemoryType)
{
    // local used variables
    HAL_SYSCFG_ErrStates_t local_errState = HAL_SYSCFG_OK;

    // check for errors
    if (argConst_u8MemoryType >= HAL_SYSCFG_MAX_BOOT_MEM)
    {
        local_errState = HAL_SYSCFG_ERR_INVALID_PARAMS;
    }

    // main function
    if (local_errState == HAL_SYSCFG_OK)
    {
        LIB_MATH_BTT_ASSIGN_BITS(global_pSYSCFGReg_t->SYSCFG_MEMRMP, HAL_SYSCFG_MEMRMP_MEM_MODE, argConst_u8MemoryType, 2);
    }

    return local_errState;
}
/*************** END OF FUNCTIONS ***************************************************************************/
