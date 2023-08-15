/**
 * --------------------------------------------------------------------------------------------------------------------------------------
 * |    @title          :   PWR                                                                                                         |
 * |    @file           :   PWR_header.h                                                                                                |
 * |    @author         :   Abdelrahman Mohamed Salem                                                                                   |
 * |    @origin_date    :   12/08/2023                                                                                                  |
 * |    @version        :   1.0.0                                                                                                       |
 * |    @tool_chain     :   GNU Tools for STM32                                                                                         |
 * |    @compiler       :   GCC                                                                                                         |
 * |    @C_standard     :   ISO C99 (-std=c99)                                                                                          |
 * |    @target         :   stm32f407VGTX                                                                                               |
 * |    @notes          :   None                                                                                                        |
 * |    @license        :   MIT License                                                                                                 |
 * |    @brief          :   this header file contains useful functions to interface with the Power Controller (PWR)                     |                                                               |
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
 * |    12/08/2023      1.0.0           Abdelrahman Mohamed Salem       Interface Created.                                              |
 * --------------------------------------------------------------------------------------------------------------------------------------
 */

#ifndef HAL_PWR_HEADER_H_
#define HAL_PWR_HEADER_H_

/******************************************************************************
 * Includes
 *******************************************************************************/

/**
 * @reason: contains standard integer definition
 */
#include "../../lib/stdint.h"

/**
 * @reason: contains register definitions and addresses
 */
#include "PWR_reg.h"

/******************************************************************************
 * Preprocessor Constants
 *******************************************************************************/

/******************************************************************************
 * Configuration Constants
 *******************************************************************************/

/******************************************************************************
 * Macros
 *******************************************************************************/

// TODO: add the functionality for enabling backup domain access (RTC & SRAM)

/******************************************************************************
 * Variables
 *******************************************************************************/

/******************************************************************************
 * Function Prototypes
 *******************************************************************************/

/**
 *  \b function                             :       HAL_PWR_Encode(const uint32_t *argConst_pu32DataIn, uint32_t arg_u32DataLen, uint32_t *arg_pu32PWRValOut)
 *  \b Description                          :       this functions is used to calculate the Cyclic Redundancy check on array of data to detect any corruption.
 *  @param  argConst_pu32DataIn [IN]        :       this is input parameter which is the address of the first word of array to read data from it.
 *  @param  arg_u32DataLen [IN]             :       this is input parameter which is the length of the given data in words that is going to be given to PWR peripheral.
 *  @param  arg_pu32PWRValOut [OUT]         :       this is output parameter which is the address of first word of data that has been processed.
 *  @note                                   :       Uses PWR-32 (Ethernet) polynomial: 0x4C11DB7.
 *  \b PRE-CONDITION                        :       make sure to enable this peripheral clock from RCC peripheral.
 *  \b POST-CONDITION                       :       None.
 *  @return                                 :       it return one of error states indicating whether a failure or success happened during writing of data (refer to @HAL_PWR_ErrStates_t in "PWR_header.h")
 *  @see                                    :       HAL_PWR_StoreTempByte(const uint8_t arg_constu8ByteVal)
 *  \b Example:
 * @code
 * #include "PWR_header.h"
 * int main() {
 * uint8_t arr[] = "Hello world";   // data to be applied to PWR
 * uint32_t len = 3;      // length of data in words
 * uint32_t result[3];      // this is where the result will be stored
 * // TODO: call RCC_enable for PWR here
 * HAL_PWR_ErrStates_t error_state = HAL_PWR_Encode((uint32_t*)&arr, len, result);  // this will encode the "hello world" message into result
 *
 * if(error_state == HAL_PWR_OK) // check for error state
 * {
 *      // data was encoded successfully
 * }
 * return 0;
 * }
 * @endcode
 *
 * <br><b> - HISTORY OF CHANGES - </b>
 * <table align="left" style="width:800px">
 * <tr><td> Date       </td><td> Software Version </td><td> Initials </td><td> Description </td></tr>
 * <tr><td> 11/08/2023 </td><td> 1.0.0            </td><td> AMS      </td><td> Interface Created </td></tr>
 * </table><br><br>
 * <hr>
 */
HAL_PWR_ErrStates_t HAL_PWR_Encode(const uint32_t *argConst_pu32DataIn, uint32_t arg_u32DataLen, uint32_t *arg_pu32PWRValOut);

/*** End of File **************************************************************/
#endif /*HAL_PWR_HEADER_H_*/