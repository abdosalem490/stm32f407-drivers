/**
 * --------------------------------------------------------------------------------------------------------------------------------------
 * |    @title          :   CMSIS                                                                                                       |
 * |    @file           :   CMSIS_header.h                                                                                              |
 * |    @author         :   Abdelrahman Mohamed Salem                                                                                   |
 * |    @origin_date    :   15/07/2023                                                                                                  |
 * |    @version        :   1.0.0                                                                                                       |
 * |    @tool_chain     :   GNU Tools for STM32                                                                                         |
 * |    @compiler       :   GCC                                                                                                         |
 * |    @C_standard     :   ISO C99 (-std=c99)                                                                                          |
 * |    @target         :   stm32f407VGTX                                                                                               |
 * |    @notes          :   None                                                                                                        |
 * |    @license        :   MIT License                                                                                                 |
 * |    @brief          :   this is a header file for utility module which contains functions declarations and preprocessor Macros      |
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
 * |    15/07/2023      1.0.0           Abdelrahman Mohamed Salem       Interface Created.                                              |
 * --------------------------------------------------------------------------------------------------------------------------------------
 */

#ifndef CMSIS_H_
#define CMSIS_H_

/******************************************************************************
 * Includes
 *******************************************************************************/

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
 *  \b Macro                        :       CMSIS_BIT_BAND_ALIAS_ADDR(bitBandBaseAddr, byteOffset, bitNumber)
 *  \b Description                  :       this macro is used to map each word in the alias region to a corresponding
 *                                          bit in the bit-band region using the formula:
 *                                          "bit_word_addr = bit_band_base + (byte_offset x 32) + (bit_number × 4)"
 *                                          where bit-band aliasing is useful is to preform read-modify-write operation in 1 cycle
 *                                          so that context switch wouldn't interrupt or affect updating a value.
 *  @param    bitBandBaseAddr       :       the starting address of the alias region.
 *  @param    byteOffset            :       the number of the byte in the bit-band region that contains the targeted bit.
 *  @param    bitNumber             :       the bit position (0-7) of the targeted bit.
 *  \b PRE-CONDITION                :       make sure that bitBandBaseAddr is base address of memory that supports bit band aliasing
 *  \b POST-CONDITION               :       None
 *  @return                         :       it return the alias address of needed bit in the bit band region
 *  @see                            :       None
 *
 *  \b Example:
 * The following example shows how to map bit 2 of the byte located at SRAM address 0x20000300 to the alias region:
 *         0x22006008 = 0x22000000 + (0x300*32) + (2*4)
 * Writing to address 0x22006008 has the same effect as a read-modify-write operation on bit 2 of the byte at SRAM address 0x20000300.
 * Reading address 0x22006008 returns the value (0x01 or 0x00) of bit 2 of the byte at SRAM address 0x20000300 (0x01: bit set; 0x00: bit reset)
 * For more information on bit-banding, please refer to the Cortex®-M4 with FPU programming manual.
 * @code
 * #include "CMSIS_header.h"
 * int main() {
 * int addr = CMSIS_BIT_BAND_ALIAS_ADDR(0x22000000, 0x300, 2);
 * printf("%x\n", addr);    // addr = 0x22006008
 * return 0;
 * }
 * @endcode
 *
 * <br><b> - HISTORY OF CHANGES - </b>
 * <table align="left" style="width:800px">
 * <tr><td> Date       </td><td> Software Version </td><td> Initials </td><td> Description </td></tr>
 * <tr><td> 15/07/2022 </td><td> 1.0.0            </td><td> AMS      </td><td> Interface Created </td></tr>
 * </table><br><br>
 * <hr>
 */
#define CMSIS_BIT_BAND_ALIAS_ADDR(bitBandBaseAddr, byteOffset, bitNumber) \
    ((bitBandBaseAddr) + (32 * byteOffset) + (bitNumber * 4))

/******************************************************************************
 * Typedefs
 *******************************************************************************/

/******************************************************************************
 * Variables
 *******************************************************************************/

/******************************************************************************
 * Function Prototypes
 *******************************************************************************/

/*** End of File **************************************************************/
#endif /*CMSIS_H_*/