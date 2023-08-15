/**
 * --------------------------------------------------------------------------------------------------------------------------------------
 * |    @title          :   math bit manipulation                                                                                       |
 * |    @file           :   math_btt.h                                                                                                  |
 * |    @author         :   Abdelrahman Mohamed Salem                                                                                   |
 * |    @origin_date    :   25/07/2023                                                                                                  |
 * |    @version        :   1.0.0                                                                                                       |
 * |    @tool_chain     :   GNU Tools for STM32                                                                                         |
 * |    @compiler       :   GCC                                                                                                         |
 * |    @C_standard     :   ISO C99 (-std=c99)                                                                                          |
 * |    @target         :   stm32f407VGTX                                                                                               |
 * |    @notes          :   None                                                                                                        |
 * |    @license        :   MIT License                                                                                                 |
 * |    @brief          :   this file contains some common definitions which seems to be compiler dependent                             |
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
 * |    15/07/2023      1.0.0           Abdelrahman Mohamed Salem       Interface Created.                                              |
 * |    13/08/2023      1.0.1           Abdelrahman Mohamed Salem       solved bug -: LIB_MATH_BTT_ASSIGN_BITS.                         |
 * --------------------------------------------------------------------------------------------------------------------------------------
 */

#ifndef LIB_MATH_BTT_H_
#define LIB_MATH_BTT_H_

/******************************************************************************
 * Includes
 *******************************************************************************/

/**
 * @reason: contains standard integer types
 */
#include "stdint.h"

/**
 * @reason: contains defintion for inline
 */
#include "common.h"

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
 *  \b Macro                        :       LIB_MATH_BTT_DECODE_TO_ONES(NUM)
 *  \b Description                  :       this macro is used to convert a number to the corresponding number of 1s so a number
 *                                          like 5 will be converted to 0b11111 and so on
 *  @param    NUM                   :       this is the required number to be converted.
 *  \b PRE-CONDITION                :       make sure that the variable holding the return value is big enough to hold it
 *  \b POST-CONDITION               :       None
 *  @return                         :       returns a number representing the entered number but as a number of 1s.
 *  @see                            :       LIB_MATH_BTT_SET_BITS
 *  @see                            :       LIB_MATH_BTT_CLR_BITS
 *  @see                            :       LIB_MATH_BTT_TOGGLE_BITS
 *  @see                            :       LIB_MATH_BTT_GET_BITS
 *  @see                            :       LIB_MATH_BTT_ASSIGN_BITS
 *  @see                            :       LIB_MATH_BTT_SET_BIT
 *  @see                            :       LIB_MATH_BTT_CLR_BIT
 *  @see                            :       LIB_MATH_BTT_TOGGLE_BIT
 *  @see                            :       LIB_MATH_BTT_GET_BIT
 *  @see                            :       LIB_MATH_BTT_ASSIGN_BIT
 *  @see                            :       LIB_MATH_BTT_u8GetMSBSetPos
 *  @note                           :       using this function with negative numbers is not defined as shifting with negative numbers is compiler dependent.
 *
 *  \b Example:
 *  if the number 5 was entered to the macro then the return value will be 0001 1111  where the least 5 significant bits are set to 1
 * @code
 * #include "math_btt.h"
 * #include "stdint.h"
 * int main() {
 * uint32_t x = LIB_MATH_BTT_DECODE_TO_ONES(5);
 * printf("%d\n", x);    // x = 31 (0001 1111  in binary)
 * return 0;
 * }
 * @endcode
 *
 * <br><b> - HISTORY OF CHANGES - </b>
 * <table align="left" style="width:800px">
 * <tr><td> Date       </td><td> Software Version </td><td> Initials </td><td> Description </td></tr>
 * <tr><td> 25/07/2023 </td><td> 1.0.0            </td><td> AMS      </td><td> Interface Created </td></tr>
 * </table><br><br>
 * <hr>
 */
#define LIB_MATH_BTT_DECODE_TO_ONES(NUM) \
    ((1 << (NUM)) - 1)

/**
 *  \b Macro                        :       LIB_MATH_BTT_SET_BITS(VAR, BTT_NO, NUM_OF_BITS)
 *  \b Description                  :       this macro is used to force bits of a variable to be 1.
 *  @param    VAR                   :       this is the required number to be modified.
 *  @param    BTT_NO                :       this is the bit position starting from which we will modify bits (number starting by 0).
 *  @param    NUM_OF_BITS           :       this is the number of bits to be modified after BTT_NO and including BTT_NO.
 *  \b PRE-CONDITION                :       None.
 *  \b POST-CONDITION               :       some bits of VAR are forced to be 1.
 *  @return                         :       None.
 *  @see                            :       LIB_MATH_BTT_DECODE_TO_ONES
 *  @see                            :       LIB_MATH_BTT_CLR_BITS
 *  @see                            :       LIB_MATH_BTT_TOGGLE_BITS
 *  @see                            :       LIB_MATH_BTT_GET_BITS
 *  @see                            :       LIB_MATH_BTT_ASSIGN_BITS
 *  @see                            :       LIB_MATH_BTT_SET_BIT
 *  @see                            :       LIB_MATH_BTT_CLR_BIT
 *  @see                            :       LIB_MATH_BTT_TOGGLE_BIT
 *  @see                            :       LIB_MATH_BTT_GET_BIT
 *  @see                            :       LIB_MATH_BTT_ASSIGN_BIT
 *  @see                            :       LIB_MATH_BTT_u8GetMSBSetPos
 *  @note                           :       using this function with negative numbers is not behaviorally defined.
 *
 *  \b Example:
 *  assume variable called x has the value of 0 (x = 0) then if we wanted to SET 5 bits starting from bit number 2 then x = 124 (0111 1100)
 * @code
 * #include "math_btt.h"
 * #include "stdint.h"
 * int main() {
 * uint32_t x = 0;
 * LIB_MATH_BTT_SET_BITS(x, 2, 5);
 * printf("%d\n", x);    // x = 124 (0111 1100  in binary)
 * return 0;
 * }
 * @endcode
 *
 * <br><b> - HISTORY OF CHANGES - </b>
 * <table align="left" style="width:800px">
 * <tr><td> Date       </td><td> Software Version </td><td> Initials </td><td> Description </td></tr>
 * <tr><td> 25/07/2023 </td><td> 1.0.0            </td><td> AMS      </td><td> Interface Created </td></tr>
 * </table><br><br>
 * <hr>
 */
#define LIB_MATH_BTT_SET_BITS(VAR, BTT_NO, NUM_OF_BITS) \
    VAR = ((VAR) | ((LIB_MATH_BTT_DECODE_TO_ONES(NUM_OF_BITS)) << (BTT_NO)))

/**
 *  \b Macro                        :       LIB_MATH_BTT_CLR_BITS(VAR, BTT_NO, NUM_OF_BITS)
 *  \b Description                  :       this macro is used to force bits of a variable to be 0.
 *  @param    VAR                   :       this is the required number to be modified.
 *  @param    BTT_NO                :       this is the bit position starting from which we will modify bits (number starting by 0).
 *  @param    NUM_OF_BITS           :       this is the number of bits to be modified after BTT_NO and including BTT_NO.
 *  \b PRE-CONDITION                :       None.
 *  \b POST-CONDITION               :       some bits of VAR are forced to be 0.
 *  @return                         :       None.
 *  @see                            :       LIB_MATH_BTT_DECODE_TO_ONES
 *  @see                            :       LIB_MATH_BTT_SET_BITS
 *  @see                            :       LIB_MATH_BTT_TOGGLE_BITS
 *  @see                            :       LIB_MATH_BTT_GET_BITS
 *  @see                            :       LIB_MATH_BTT_ASSIGN_BITS
 *  @see                            :       LIB_MATH_BTT_SET_BIT
 *  @see                            :       LIB_MATH_BTT_CLR_BIT
 *  @see                            :       LIB_MATH_BTT_TOGGLE_BIT
 *  @see                            :       LIB_MATH_BTT_GET_BIT
 *  @see                            :       LIB_MATH_BTT_ASSIGN_BIT
 *  @see                            :       LIB_MATH_BTT_u8GetMSBSetPos
 *  @note                           :       using this function with negative numbers is not behaviorally defined.
 *
 *  \b Example:
 *  assume variable called x has the value of 124 (0111 1100 in binary) then if we wanted to CLEAR 2 bits starting from bit number 4 then x = 76 (0100 1100)
 * @code
 * #include "math_btt.h"
 * #include "stdint.h"
 * int main() {
 * uint32_t x = 124;
 * LIB_MATH_BTT_CLR_BITS(x, 4, 2);
 * printf("%d\n", x);    // x = 76 (0100 1100  in binary)
 * return 0;
 * }
 * @endcode
 *
 * <br><b> - HISTORY OF CHANGES - </b>
 * <table align="left" style="width:800px">
 * <tr><td> Date       </td><td> Software Version </td><td> Initials </td><td> Description </td></tr>
 * <tr><td> 25/07/2023 </td><td> 1.0.0            </td><td> AMS      </td><td> Interface Created </td></tr>
 * </table><br><br>
 * <hr>
 */
#define LIB_MATH_BTT_CLR_BITS(VAR, BTT_NO, NUM_OF_BITS) \
    VAR = ((VAR) & (~((LIB_MATH_BTT_DECODE_TO_ONES(NUM_OF_BITS)) << (BTT_NO))))

/**
 *  \b Macro                        :       LIB_MATH_BTT_TOGGLE_BITS(VAR, BTT_NO, NUM_OF_BITS)
 *  \b Description                  :       this macro is used to toggle bits of a variable so that 0 becomes 1 and 1 becomes 0.
 *  @param    VAR                   :       this is the required number to be modified.
 *  @param    BTT_NO                :       this is the bit position starting from which we will modify bits (number starting by 0).
 *  @param    NUM_OF_BITS           :       this is the number of bits to be modified after BTT_NO and including BTT_NO.
 *  \b PRE-CONDITION                :       None.
 *  \b POST-CONDITION               :       some bits of VAR are toggled (0 becomes 1 and 1 becomes 0).
 *  @return                         :       None.
 *  @see                            :       LIB_MATH_BTT_DECODE_TO_ONES
 *  @see                            :       LIB_MATH_BTT_SET_BITS
 *  @see                            :       LIB_MATH_BTT_CLR_BITS
 *  @see                            :       LIB_MATH_BTT_GET_BITS
 *  @see                            :       LIB_MATH_BTT_ASSIGN_BITS
 *  @see                            :       LIB_MATH_BTT_SET_BIT
 *  @see                            :       LIB_MATH_BTT_CLR_BIT
 *  @see                            :       LIB_MATH_BTT_TOGGLE_BIT
 *  @see                            :       LIB_MATH_BTT_GET_BIT
 *  @see                            :       LIB_MATH_BTT_ASSIGN_BIT
 *  @see                            :       LIB_MATH_BTT_u8GetMSBSetPos
 *  @note                           :       using this function with negative numbers is not behaviorally defined.
 *
 *  \b Example:
 *  assume variable called x has the value of 76 (0100 1100 in binary) then if we wanted to TOGGLE 3 bits starting from bit number 6 then x = 396 (0001 1000 1100 in binary)
 * @code
 * #include "math_btt.h"
 * #include "stdint.h"
 * int main() {
 * uint32_t x = 76;
 * LIB_MATH_BTT_TOGGLE_BITS(x, 6, 3);
 * printf("%d\n", x);    // x = 396 (0001 1000 1100 in binary)
 * return 0;
 * }
 * @endcode
 *
 * <br><b> - HISTORY OF CHANGES - </b>
 * <table align="left" style="width:800px">
 * <tr><td> Date       </td><td> Software Version </td><td> Initials </td><td> Description </td></tr>
 * <tr><td> 25/07/2023 </td><td> 1.0.0            </td><td> AMS      </td><td> Interface Created </td></tr>
 * </table><br><br>
 * <hr>
 */
#define LIB_MATH_BTT_TOGGLE_BITS(VAR, BTT_NO, NUM_OF_BITS) \
    VAR = ((VAR) ^ ((LIB_MATH_BTT_DECODE_TO_ONES(NUM_OF_BITS)) << (BTT_NO)))

/**
 *  \b Macro                        :       LIB_MATH_BTT_GET_BITS(VAR, BTT_NO, NUM_OF_BITS)
 *  \b Description                  :       this macro is used to return the value of a range of bits.
 *  @param    VAR                   :       this is the required number to be extract value of range of bits from it.
 *  @param    BTT_NO                :       this is the bit position starting from which we will get bits (number starting by 0).
 *  @param    NUM_OF_BITS           :       this is the number of bits to be returned after BTT_NO and including BTT_NO.
 *  \b PRE-CONDITION                :       None.
 *  \b POST-CONDITION               :       None.
 *  @return                         :       number representing the value of range of selected bits.
 *  @see                            :       LIB_MATH_BTT_DECODE_TO_ONES
 *  @see                            :       LIB_MATH_BTT_SET_BITS
 *  @see                            :       LIB_MATH_BTT_CLR_BITS
 *  @see                            :       LIB_MATH_BTT_TOGGLE_BITS
 *  @see                            :       LIB_MATH_BTT_ASSIGN_BITS
 *  @see                            :       LIB_MATH_BTT_SET_BIT
 *  @see                            :       LIB_MATH_BTT_CLR_BIT
 *  @see                            :       LIB_MATH_BTT_TOGGLE_BIT
 *  @see                            :       LIB_MATH_BTT_GET_BIT
 *  @see                            :       LIB_MATH_BTT_ASSIGN_BIT
 *  @see                            :       LIB_MATH_BTT_u8GetMSBSetPos
 *  @note                           :       None
 *
 *  \b Example:
 *  assume variable called x has the value of 396 (0001 1000 1100 in binary) then if we wanted to GET 5 bits starting from bit number 3 then return value = 17 (0001 0001 in binary)
 * @code
 * #include "math_btt.h"
 * #include "stdint.h"
 * int main() {
 * uint32_t x = 396;
 * x = LIB_MATH_BTT_GET_BITS(x, 3, 5);
 * printf("%d\n", x);    // x = 17 (0001 0001 in binary)
 * return 0;
 * }
 * @endcode
 *
 * <br><b> - HISTORY OF CHANGES - </b>
 * <table align="left" style="width:800px">
 * <tr><td> Date       </td><td> Software Version </td><td> Initials </td><td> Description </td></tr>
 * <tr><td> 25/07/2023 </td><td> 1.0.0            </td><td> AMS      </td><td> Interface Created </td></tr>
 * </table><br><br>
 * <hr>
 */
#define LIB_MATH_BTT_GET_BITS(VAR, BTT_NO, NUM_OF_BITS) \
    ((VAR >> BTT_NO) & (LIB_MATH_BTT_DECODE_TO_ONES(NUM_OF_BITS)))

/**
 *  \b Macro                        :       LIB_MATH_BTT_ASSIGN_BITS(VAR, BTT_NO, VAL, NUM_OF_BITS)
 *  \b Description                  :       this macro is used to force a specific value for range of bits.
 *  @param    VAR                   :       this is the required number to be modified.
 *  @param    BTT_NO                :       this is the bit position starting from which we will assign bits (number starting by 0).
 *  @param    VAL                   :       this is the value to be forced into the selected range of bits.
 *  @param    NUM_OF_BITS           :       this is the number of bits to be modified after BTT_NO and including BTT_NO.
 *  \b PRE-CONDITION                :       None.
 *  \b POST-CONDITION               :       some bits of the variable is modified using parameter VAL.
 *  @return                         :       None.
 *  @see                            :       LIB_MATH_BTT_DECODE_TO_ONES
 *  @see                            :       LIB_MATH_BTT_SET_BITS
 *  @see                            :       LIB_MATH_BTT_CLR_BITS
 *  @see                            :       LIB_MATH_BTT_TOGGLE_BITS
 *  @see                            :       LIB_MATH_BTT_GET_BITS
 *  @see                            :       LIB_MATH_BTT_SET_BIT
 *  @see                            :       LIB_MATH_BTT_CLR_BIT
 *  @see                            :       LIB_MATH_BTT_TOGGLE_BIT
 *  @see                            :       LIB_MATH_BTT_GET_BIT
 *  @see                            :       LIB_MATH_BTT_ASSIGN_BIT
 *  @see                            :       LIB_MATH_BTT_u8GetMSBSetPos
 *  @note                           :       using this function with negative numbers is not behaviorally defined.
 *
 *  \b Example:
 *  assume variable called x has the value of 17 (0001 0001 in binary) then if we wanted to ASSIGN 3 bits starting from bit number 1 with the value 5 then x = 27 (0001 1011 in binary)
 * @code
 * #include "math_btt.h"
 * #include "stdint.h"
 * int main() {
 * uint32_t x = 17;
 * LIB_MATH_BTT_ASSIGN_BITS(x, 1, 5, 3);
 * printf("%d\n", x);    // x = 27 (0001 1011 in binary)
 * return 0;
 * }
 * @endcode
 *
 * <br><b> - HISTORY OF CHANGES - </b>
 * <table align="left" style="width:800px">
 * <tr><td> Date       </td><td> Software Version </td><td> Initials </td><td> Description </td></tr>
 * <tr><td> 25/07/2023 </td><td> 1.0.0            </td><td> AMS      </td><td> Interface Created </td></tr>
 * <tr><td> 13/08/2023 </td><td> 1.0.1            </td><td> AMS      </td><td> solved bug -: VAL being assigned all to part of VAR </td></tr>
 * </table><br><br>
 * <hr>
 */
#define LIB_MATH_BTT_ASSIGN_BITS(VAR, BTT_NO, VAL, NUM_OF_BITS) \
    VAR = ((VAR) & (~((LIB_MATH_BTT_DECODE_TO_ONES(NUM_OF_BITS)) << (BTT_NO)))) | ((((VAL) & (LIB_MATH_BTT_DECODE_TO_ONES(NUM_OF_BITS))) << (BTT_NO)))

/**
 *  \b Macro                        :       LIB_MATH_BTT_SET_BIT(VAR, BTT_NO)
 *  \b Description                  :       this macro is used to force only one bit of a variable to be 1.
 *  @param    VAR                   :       this is the required number to be modified.
 *  @param    BTT_NO                :       this is the bit position that will be forced to be 1.
 *  \b PRE-CONDITION                :       None.
 *  \b POST-CONDITION               :       one bit of VAR is forced to be 1.
 *  @return                         :       None.
 *  @see                            :       LIB_MATH_BTT_DECODE_TO_ONES
 *  @see                            :       LIB_MATH_BTT_SET_BITS
 *  @see                            :       LIB_MATH_BTT_CLR_BITS
 *  @see                            :       LIB_MATH_BTT_TOGGLE_BITS
 *  @see                            :       LIB_MATH_BTT_GET_BITS
 *  @see                            :       LIB_MATH_BTT_ASSIGN_BITS
 *  @see                            :       LIB_MATH_BTT_CLR_BIT
 *  @see                            :       LIB_MATH_BTT_TOGGLE_BIT
 *  @see                            :       LIB_MATH_BTT_GET_BIT
 *  @see                            :       LIB_MATH_BTT_ASSIGN_BIT
 *  @see                            :       LIB_MATH_BTT_u8GetMSBSetPos
 *  @note                           :       using this function with negative numbers is not behaviorally defined.
 *
 *  \b Example:
 *  assume variable called x has the value of 0 (x = 0) then if we wanted to SET bit number 2 then x = 4 (0000 0100 in binary)
 * @code
 * #include "math_btt.h"
 * #include "stdint.h"
 * int main() {
 * uint32_t x = 0;
 * LIB_MATH_BTT_SET_BIT(x, 2);
 * printf("%d\n", x);    // x = 4 (0000 0100  in binary)
 * return 0;
 * }
 * @endcode
 *
 * <br><b> - HISTORY OF CHANGES - </b>
 * <table align="left" style="width:800px">
 * <tr><td> Date       </td><td> Software Version </td><td> Initials </td><td> Description </td></tr>
 * <tr><td> 25/07/2023 </td><td> 1.0.0            </td><td> AMS      </td><td> Interface Created </td></tr>
 * </table><br><br>
 * <hr>
 */
#define LIB_MATH_BTT_SET_BIT(VAR, BTT_NO) \
    VAR = ((VAR) | (1 << (BTT_NO)))

/**
 *  \b Macro                        :       LIB_MATH_BTT_CLR_BIT(VAR, BTT_NO)
 *  \b Description                  :       this macro is used to force only one bit of a variable to be 0.
 *  @param    VAR                   :       this is the required number to be modified.
 *  @param    BTT_NO                :       this is the bit position that will be forced to 0.
 *  \b PRE-CONDITION                :       None.
 *  \b POST-CONDITION               :       only one bit of VAR is forced to be 0.
 *  @return                         :       None.
 *  @see                            :       LIB_MATH_BTT_DECODE_TO_ONES
 *  @see                            :       LIB_MATH_BTT_SET_BITS
 *  @see                            :       LIB_MATH_BTT_CLR_BITS
 *  @see                            :       LIB_MATH_BTT_TOGGLE_BITS
 *  @see                            :       LIB_MATH_BTT_GET_BITS
 *  @see                            :       LIB_MATH_BTT_ASSIGN_BITS
 *  @see                            :       LIB_MATH_BTT_SET_BIT
 *  @see                            :       LIB_MATH_BTT_CLR_BIT
 *  @see                            :       LIB_MATH_BTT_TOGGLE_BIT
 *  @see                            :       LIB_MATH_BTT_GET_BIT
 *  @see                            :       LIB_MATH_BTT_ASSIGN_BIT
 *  @see                            :       LIB_MATH_BTT_u8GetMSBSetPos
 *  @note                           :       using this function with negative numbers is not behaviorally defined.
 *
 *  \b Example:
 *  assume variable called x has the value of 4 (0000 0100 in binary) then if we wanted to CLEAR bit number 2 then x = 0 (0000 0000)
 * @code
 * #include "math_btt.h"
 * #include "stdint.h"
 * int main() {
 * uint32_t x = 4;
 * LIB_MATH_BTT_CLR_BIT(x, 2);
 * printf("%d\n", x);    // x = 0 (0000 0000  in binary)
 * return 0;
 * }
 * @endcode
 *
 * <br><b> - HISTORY OF CHANGES - </b>
 * <table align="left" style="width:800px">
 * <tr><td> Date       </td><td> Software Version </td><td> Initials </td><td> Description </td></tr>
 * <tr><td> 25/07/2023 </td><td> 1.0.0            </td><td> AMS      </td><td> Interface Created </td></tr>
 * </table><br><br>
 * <hr>
 */
#define LIB_MATH_BTT_CLR_BIT(VAR, BTT_NO) \
    VAR = ((VAR) & (~(1 << (BTT_NO))))
/**
 *  \b Macro                        :       LIB_MATH_BTT_TOGGLE_BIT(VAR, BTT_NO)
 *  \b Description                  :       this macro is used to toggle only one bit of a variable so that 0 becomes 1 and 1 becomes 0.
 *  @param    VAR                   :       this is the required number to be modified.
 *  @param    BTT_NO                :       this is the bit position that will be modified.
 *  \b PRE-CONDITION                :       None.
 *  \b POST-CONDITION               :       only one bit of VAR is toggled (0 becomes 1 and 1 becomes 0).
 *  @return                         :       None.
 *  @see                            :       LIB_MATH_BTT_DECODE_TO_ONES
 *  @see                            :       LIB_MATH_BTT_SET_BITS
 *  @see                            :       LIB_MATH_BTT_CLR_BITS
 *  @see                            :       LIB_MATH_BTT_TOGGLE_BITS
 *  @see                            :       LIB_MATH_BTT_GET_BITS
 *  @see                            :       LIB_MATH_BTT_ASSIGN_BITS
 *  @see                            :       LIB_MATH_BTT_SET_BIT
 *  @see                            :       LIB_MATH_BTT_CLR_BIT
 *  @see                            :       LIB_MATH_BTT_GET_BIT
 *  @see                            :       LIB_MATH_BTT_ASSIGN_BIT
 *  @see                            :       LIB_MATH_BTT_u8GetMSBSetPos
 *  @note                           :       using this function with negative numbers is not behaviorally defined.
 *
 *  \b Example:
 *  assume variable called x has the value of 0 (0000 0000 in binary) then if we wanted to TOGGLE bit number 6 then x = 64 (0100 0000 in binary)
 * @code
 * #include "math_btt.h"
 * #include "stdint.h"
 * int main() {
 * uint32_t x = 0;
 * LIB_MATH_BTT_TOGGLE_BIT(x, 6);
 * printf("%d\n", x);    // x = 64 (0100 0000 in binary)
 * return 0;
 * }
 * @endcode
 *
 * <br><b> - HISTORY OF CHANGES - </b>
 * <table align="left" style="width:800px">
 * <tr><td> Date       </td><td> Software Version </td><td> Initials </td><td> Description </td></tr>
 * <tr><td> 25/07/2023 </td><td> 1.0.0            </td><td> AMS      </td><td> Interface Created </td></tr>
 * </table><br><br>
 * <hr>
 */
#define LIB_MATH_BTT_TOGGLE_BIT(VAR, BTT_NO) \
    VAR = ((VAR) ^ (1 << (BTT_NO)))

/**
 *  \b Macro                        :       LIB_MATH_BTT_GET_BIT((VAR, BTT_NO)
 *  \b Description                  :       this macro is used to return the value of a single bit.
 *  @param    VAR                   :       this is the required number to be extract value of one bit from it.
 *  @param    BTT_NO                :       this is the bit position that we want its value (number starting by 0).
 *  \b PRE-CONDITION                :       None.
 *  \b POST-CONDITION               :       None.
 *  @return                         :       0 or 1 number representing the value of selected bit.
 *  @see                            :       LIB_MATH_BTT_DECODE_TO_ONES
 *  @see                            :       LIB_MATH_BTT_SET_BITS
 *  @see                            :       LIB_MATH_BTT_CLR_BITS
 *  @see                            :       LIB_MATH_BTT_TOGGLE_BITS
 *  @see                            :       LIB_MATH_BTT_GET_BITS
 *  @see                            :       LIB_MATH_BTT_ASSIGN_BITS
 *  @see                            :       LIB_MATH_BTT_SET_BIT
 *  @see                            :       LIB_MATH_BTT_CLR_BIT
 *  @see                            :       LIB_MATH_BTT_TOGGLE_BIT
 *  @see                            :       LIB_MATH_BTT_ASSIGN_BIT
 *  @see                            :       LIB_MATH_BTT_u8GetMSBSetPos
 *  @note                           :       None
 *
 *  \b Example:
 *  assume variable called x has the value of 64 (0100 0000 in binary) then if we wanted to GET bit number 6 then return value = 1 (0000 0001 in binary)
 * @code
 * #include "math_btt.h"
 * #include "stdint.h"
 * int main() {
 * uint32_t x = 64;
 * x = LIB_MATH_BTT_GET_BIT(x, 6);
 * printf("%d\n", x);    // x = 1 (0000 0001 in binary)
 * return 0;
 * }
 * @endcode
 *
 * <br><b> - HISTORY OF CHANGES - </b>
 * <table align="left" style="width:800px">
 * <tr><td> Date       </td><td> Software Version </td><td> Initials </td><td> Description </td></tr>
 * <tr><td> 25/07/2023 </td><td> 1.0.0            </td><td> AMS      </td><td> Interface Created </td></tr>
 * </table><br><br>
 * <hr>
 */
#define LIB_MATH_BTT_GET_BIT(VAR, BTT_NO) \
    (((VAR) >> (BTT_NO)) & 1)

/**
 *  \b Macro                        :       LIB_MATH_BTT_ASSIGN_BITS(VAR, BTT_NO, VAL, NUM_OF_BITS)
 *  \b Description                  :       this macro is used to assign a specific value for single bit (either 0 or 1).
 *  @param    VAR                   :       this is the required number to be modified.
 *  @param    BTT_NO                :       this is the bit position to be modified (number starting by 0).
 *  @param    VAL                   :       this is the value to be forced into the selected bit (either 0 or 1).
 *  \b PRE-CONDITION                :       None.
 *  \b POST-CONDITION               :       only one bit of the variable is modified using parameter VAL.
 *  @return                         :       None.
 *  @see                            :       LIB_MATH_BTT_DECODE_TO_ONES
 *  @see                            :       LIB_MATH_BTT_SET_BITS
 *  @see                            :       LIB_MATH_BTT_CLR_BITS
 *  @see                            :       LIB_MATH_BTT_TOGGLE_BITS
 *  @see                            :       LIB_MATH_BTT_GET_BITS
 *  @see                            :       LIB_MATH_BTT_ASSIGN_BITS
 *  @see                            :       LIB_MATH_BTT_SET_BIT
 *  @see                            :       LIB_MATH_BTT_CLR_BIT
 *  @see                            :       LIB_MATH_BTT_TOGGLE_BIT
 *  @see                            :       LIB_MATH_BTT_GET_BIT
 *  @see                            :       LIB_MATH_BTT_u8GetMSBSetPos
 *  @note                           :       using this function with negative numbers is not behaviorally defined.
 *
 *  \b Example:
 *  assume variable called x has the value of 1 (0000 0001 in binary) then if we wanted to ASSIGN bit number 1 with the value 1 then x = 3 (0000 0011 in binary)
 * @code
 * #include "math_btt.h"
 * #include "stdint.h"
 * int main() {
 * uint32_t x = 17;
 * LIB_MATH_BTT_ASSIGN_BIT(x, 1, 1);
 * printf("%d\n", x);    // x = 3 (0000 0011 in binary)
 * return 0;
 * }
 * @endcode
 *
 * <br><b> - HISTORY OF CHANGES - </b>
 * <table align="left" style="width:800px">
 * <tr><td> Date       </td><td> Software Version </td><td> Initials </td><td> Description </td></tr>
 * <tr><td> 25/07/2023 </td><td> 1.0.0            </td><td> AMS      </td><td> Interface Created </td></tr>
 * </table><br><br>
 * <hr>
 */
#define LIB_MATH_BTT_ASSIGN_BIT(VAR, BTT_NO, VAL) \
    VAR = (VAR & (~(1 << BTT_NO))) | (VAL << BTT_NO)

/******************************************************************************
 * Typedefs
 *******************************************************************************/

/******************************************************************************
 * Variables
 *******************************************************************************/

/******************************************************************************
 * Function Prototypes
 *******************************************************************************/

/**
 *  \b function                     :       LIB_MATH_BTT_u8GetMSBSetPos(uint32_t args_u32Variable)
 *  \b Description                  :       this function is used to return the bit position of the MSB having the value 1
 *  @param    args_u32Variable [IN] :       this is the variable to get its MSB set bit from it.
 *  \b PRE-CONDITION                :       None.
 *  \b POST-CONDITION               :       None.
 *  @return                         :       None.
 *  @see                            :       LIB_MATH_BTT_DECODE_TO_ONES
 *  @see                            :       LIB_MATH_BTT_SET_BITS
 *  @see                            :       LIB_MATH_BTT_CLR_BITS
 *  @see                            :       LIB_MATH_BTT_TOGGLE_BITS
 *  @see                            :       LIB_MATH_BTT_GET_BITS
 *  @see                            :       LIB_MATH_BTT_ASSIGN_BITS
 *  @see                            :       LIB_MATH_BTT_SET_BIT
 *  @see                            :       LIB_MATH_BTT_CLR_BIT
 *  @see                            :       LIB_MATH_BTT_TOGGLE_BIT
 *  @see                            :       LIB_MATH_BTT_GET_BIT
 *  @see                            :       LIB_MATH_BTT_ASSIGN_BIT
 *  @note                           :       using this function with negative numbers is not behaviorally defined.
 *
 *  \b Example:
 *  assume variable called x has the value of 17 (0001 0001 in binary) then if we wanted to GET MSB SET bit position then x = 4
 * @code
 * #include "math_btt.h"
 * #include "stdint.h"
 * int main() {
 * uint32_t x = 17;
 * x = LIB_MATH_BTT_u8GetMSBSetPos(x);
 * printf("%d\n", x);    // x = 4
 * return 0;
 * }
 * @endcode
 *
 * <br><b> - HISTORY OF CHANGES - </b>
 * <table align="left" style="width:800px">
 * <tr><td> Date       </td><td> Software Version </td><td> Initials </td><td> Description </td></tr>
 * <tr><td> 25/07/2023 </td><td> 1.0.0            </td><td> AMS      </td><td> Interface Created </td></tr>
 * </table><br><br>
 * <hr>
 */
static __in uint8_t LIB_MATH_BTT_u8GetMSBSetPos(uint32_t args_u32Variable)
{
    uint8_t local_u8MSBSetBitPos = 0;
    args_u32Variable = args_u32Variable >> 1;
    while (args_u32Variable != 0)
    {
        args_u32Variable = args_u32Variable >> 1;
        local_u8MSBSetBitPos++;
    }
    return local_u8MSBSetBitPos;
}

/*** End of File **************************************************************/
#endif /*LIB_MATH_BTT_H_*/
