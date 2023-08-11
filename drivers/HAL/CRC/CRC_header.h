/**
 * --------------------------------------------------------------------------------------------------------------------------------------
 * |    @title          :   crc                                                                                                         |
 * |    @file           :   CRC_header.h                                                                                                |
 * |    @author         :   Abdelrahman Mohamed Salem                                                                                   |
 * |    @origin_date    :   10/08/2023                                                                                                  |
 * |    @version        :   1.0.0                                                                                                       |
 * |    @tool_chain     :   GNU Tools for STM32                                                                                         |
 * |    @compiler       :   GCC                                                                                                         |
 * |    @C_standard     :   ISO C99 (-std=c99)                                                                                          |
 * |    @target         :   stm32f407VGTX                                                                                               |
 * |    @notes          :   None                                                                                                        |
 * |    @license        :   MIT License                                                                                                 |
 * |    @brief          :   this header file contains useful functions to interface with the Cyclic Redundancy check (CRC)              |                                                               |
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
 * |    10/08/2023      1.0.0           Abdelrahman Mohamed Salem       Interface Created.                                              |
 * --------------------------------------------------------------------------------------------------------------------------------------
 */

#ifndef HAL_CRC_HEADER_H_
#define HAL_CRC_HEADER_H_

/******************************************************************************
 * Includes
 *******************************************************************************/

/**
 * @reason: contains standard integer definition
 */
#include "../../lib/stdint.h"

/**
 * @reason: contains bits math functions
 */
#include "../../lib/math_btt.h"

/**
 * @reason: contains register definitions
 */
#include "CRC_reg.h"

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
 *  \b Macro                                :       HAL_CRC_StoreTempByte(const uint8_t arg_constu8ByteVal)
 *  \b Description                          :       this macro is used to store a byte into only one temporary register which isn't affected by CRC reset
 *  @param  arg_constu8ByteVal [IN]         :       byte data to be stored
 *  @note                                   :       None.
 *  \b PRE-CONDITION                        :       None.
 *  \b POST-CONDITION                       :       store byte into independent register.
 *  @return                                 :       None.
 *  @see                                    :       HAL_CRC_Encode(const uint32_t *argConst_pu32DataIn, uint32_t arg_u32DataLen, uint32_t *arg_pu32CRCValOut)
 *  @see                                    :       HAL_CRC_GET_TEMP_BYTE()
 *  \b Example:
 * @code
 * #include "CRC_header.h"
 *
 * int main() {
 *
 *  HAL_CRC_STORE_TEMP_BYTE(25);    // store 25 into independent register present in CRC
 *
 *  return 0;
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
#define HAL_CRC_STORE_TEMP_BYTE(arg_constu8ByteVal) \
    LIB_MATH_BTT_ASSIGN_BITS(global_pCRCReg_t->CRC_IDR, HAL_CRC_INDEPENDET_DATA_REG, (uint8_t)arg_constu8ByteVal, 8)

/**
 *  \b Macro                                :       HAL_CRC_GET_TEMP_BYTE()
 *  \b Description                          :       this macro is used to get a byte from only one temporary register.
 *  @note                                   :       None.
 *  \b PRE-CONDITION                        :       None.
 *  \b POST-CONDITION                       :       None.
 *  @return                                 :       byte that's stored into temporary register.
 *  @see                                    :       HAL_CRC_Encode(const uint32_t *argConst_pu32DataIn, uint32_t arg_u32DataLen, uint32_t *arg_pu32CRCValOut)
 *  @see                                    :       HAL_CRC_STORE_TEMP_BYTE(arg_constu8ByteVal)
 *  \b Example:
 * @code
 * #include "CRC_header.h"
 *
 * int main() {
 *
 *  uint8_t tempVal = HAL_CRC_GET_TEMP_BYTE();    // get the stored temporary byte in the CRC
 *
 *  return 0;
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
#define HAL_CRC_GET_TEMP_BYTE() \
    LIB_MATH_BTT_GET_BITS(global_pCRCReg_t->CRC_IDR, HAL_CRC_INDEPENDET_DATA_REG, 8)

/******************************************************************************
 * Tables
 *******************************************************************************/

/******************************************************************************
 * Typedefs
 *******************************************************************************/

/**
 * @enum: Hal_CRC_ErrStates_t
 * @brief: contains all possible errors that can result from dealing with the embedded CRC.
 */
typedef enum
{
    HAL_CRC_OK,                 /**< it means everything has gone as intended so no errors*/
    HAL_CRC_ERR_INVALID_PARAMS, /**< it means that the supplied parameters of the function are invalid*/
} HAL_CRC_ErrStates_t;

/******************************************************************************
 * Variables
 *******************************************************************************/

/******************************************************************************
 * Function Prototypes
 *******************************************************************************/

/**
 *  \b function                             :       HAL_CRC_Encode(const uint32_t *argConst_pu32DataIn, uint32_t arg_u32DataLen, uint32_t *arg_pu32CRCValOut)
 *  \b Description                          :       this functions is used to calculate the Cyclic Redundancy check on array of data to detect any corruption.
 *  @param  argConst_pu32DataIn [IN]        :       this is input parameter which is the address of the first word of array to read data from it.
 *  @param  arg_u32DataLen [IN]             :       this is input parameter which is the length of the given data in words that is going to be given to CRC peripheral.
 *  @param  arg_pu32CRCValOut [OUT]         :       this is output parameter which is the address of first word of data that has been processed.
 *  @note                                   :       Uses CRC-32 (Ethernet) polynomial: 0x4C11DB7.
 *  \b PRE-CONDITION                        :       make sure to enable this peripheral clock from RCC peripheral.
 *  \b POST-CONDITION                       :       None.
 *  @return                                 :       it return one of error states indicating whether a failure or success happened during writing of data (refer to @HAL_CRC_ErrStates_t in "CRC_header.h")
 *  @see                                    :       HAL_CRC_StoreTempByte(const uint8_t arg_constu8ByteVal)
 *  \b Example:
 * @code
 * #include "CRC_header.h"
 * int main() {
 * uint8_t arr[] = "Hello world";   // data to be applied to CRC
 * uint32_t len = 3;      // length of data in words
 * uint32_t result[3];      // this is where the result will be stored
 * // TODO: call RCC_enable for CRC here
 * HAL_CRC_ErrStates_t error_state = HAL_CRC_Encode((uint32_t*)&arr, len, result);  // this will encode the "hello world" message into result
 *
 * if(error_state == HAL_CRC_OK) // check for error state
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
HAL_CRC_ErrStates_t HAL_CRC_Encode(const uint32_t *argConst_pu32DataIn, uint32_t arg_u32DataLen, uint32_t *arg_pu32CRCValOut);

/*** End of File **************************************************************/
#endif /*HAL_CRC_HEADER_H_*/