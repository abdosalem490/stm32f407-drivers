/**
 * --------------------------------------------------------------------------------------------------------------------------------------
 * |    @title          :   CRC                                                                                                       |
 * |    @file           :   CRC_header.h                                                                                              |
 * |    @author         :   Abdelrahman Mohamed Salem                                                                                   |
 * |    @origin_date    :   01/08/2023                                                                                                  |
 * |    @version        :   1.0.0                                                                                                       |
 * |    @tool_chain     :   GNU Tools for STM32                                                                                         |
 * |    @compiler       :   GCC                                                                                                         |
 * |    @C_standard     :   ISO C99 (-std=c99)                                                                                          |
 * |    @target         :   stm32f407VGTX                                                                                               |
 * |    @notes          :   None                                                                                                        |
 * |    @license        :   MIT License                                                                                                 |
 * |    @brief          :   this header file contains useful functions to interface with the embedded CRC memory inside stm32f407     |
 * |                        common to cortex-M4 microprocessors with FPU.                                                               |
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
 * |    01/08/2023      1.0.0           Abdelrahman Mohamed Salem       Interface Created.                                              |
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
 * @reason: contains all initial user configurations for CRC
 */
#include "CRC_config.h"

/**
 * @reason: contains all the interface functions to be implemented
 */
#include "CRC_header.h"

/**
 * @reason: contains all register addresses and bit definitions for embedded CRC configuration registers
 */
#include "CRC_reg.h"

/**
 * @reason: contains all private function declaration and global variables
 */
#include "CRC_private.h"

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
 *
 */
HAL_CRC_ErrStates_t HAL_CRC_Encode(const uint32_t *argConst_pu32DataIn, uint32_t arg_u32DataLen, uint32_t *arg_pu32CRCValOut)
{
    // used local variables
    HAL_CRC_ErrStates_t local_errState_t = HAL_CRC_OK;

    // check for errors
    if (argConst_pu32DataIn == NULL || arg_pu32CRCValOut == NULL)
    {
        local_errState_t = HAL_CRC_ERR_INVALID_PARAMS;
    }

    // main function
    if (local_errState_t == HAL_CRC_OK)
    {
        LIB_MATH_BTT_SET_BIT(global_pCRCReg_t->CRC_CR, HAL_CRC_CR_RESET);
        for (; arg_u32DataLen > 0; arg_u32DataLen--)
        {
            global_pCRCReg_t->CRC_DR = *argConst_pu32DataIn;
            argConst_pu32DataIn++;
            *arg_pu32CRCValOut = global_pCRCReg_t->CRC_DR;
            arg_pu32CRCValOut++;
        }
    }

    return local_errState_t;
}

/*************** END OF FUNCTIONS ***************************************************************************/
