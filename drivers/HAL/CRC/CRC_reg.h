/**
 * --------------------------------------------------------------------------------------------------------------------------------------
 * |    @title          :   crc                                                                                                         |
 * |    @file           :   CRC_reg.h                                                                                                   |
 * |    @author         :   Abdelrahman Mohamed Salem                                                                                   |
 * |    @origin_date    :   11/08/2023                                                                                                  |
 * |    @version        :   1.0.0                                                                                                       |
 * |    @tool_chain     :   GNU Tools for STM32                                                                                         |
 * |    @compiler       :   GCC                                                                                                         |
 * |    @C_standard     :   ISO C99 (-std=c99)                                                                                          |
 * |    @target         :   stm32f407VGTX                                                                                               |
 * |    @notes          :   None                                                                                                        |
 * |    @license        :   MIT License                                                                                                 |
 * |    @brief          :   this file contains registers addresses and definitions structs that deals with CRC registers                |
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
 * |    11/08/2023      1.0.0           Abdelrahman Mohamed Salem       Interface Created.                                              |
 * --------------------------------------------------------------------------------------------------------------------------------------
 */

#ifndef HAL_CRC_REG_H_
#define HAL_CRC_REG_H_

/******************************************************************************
 * Includes
 *******************************************************************************/
/**
 * @reason: contains standard definitions for the variables
 */
#include "../../lib/stdint.h"

/**
 * @reason: contains base addresses of AHB1 bus
 */
#include "../CM4F/CM4F_reg.h"

/**
 * @reason: contains volatile keyword definition regarding selected compiler
 */
#include "../../lib/common.h"

/******************************************************************************
 * Preprocessor Constants
 *******************************************************************************/

/**
 * @brief: this is the base address of CRC registers used to configure some of the CRC behaviors
 * @note: it will be referred to as @HAL_CRC_BASE_ADDR
 */
#define HAL_CRC_OFFSET 0x00003000 /**< this is the offset of the CRC register from AHB1 bus base address*/

/**
 * @brief: bit position definitions for CRC_IDR (CRC Independent data register)
 */
#define HAL_CRC_INDEPENDET_DATA_REG 0 /**< temporary data register for temporary memory*/
/**
 * @brief: bit position definitions for CRC_CR (CRC Control register)
 */
#define HAL_CRC_CR_RESET 0 /**< RESET bit,  Resets the CRC calculation unit and sets the data register to 0xFFFF FFFF. This bit can only be set, it is automatically cleared by hardware.*/

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
 * @brief: this holds all registers used to configure embedded CRC
 */
typedef struct
{
    __io uint32_t CRC_DR;  /**< Used as an input register when writing new data into the CRC calculator. Holds the previous CRC calculation result when it is read.*/
    __io uint32_t CRC_IDR; /**< contains independent data register for temporary memory not affected by reset*/
    __io uint32_t CRC_CR;  /**< just constains reset bit that resets CRC for additional operation*/
} HAL_CRC_RegDef_t;

/******************************************************************************
 * Variables
 *******************************************************************************/
__io HAL_CRC_RegDef_t *global_pCRCReg_t = ((HAL_CRC_RegDef_t *)(HAL_CM4F_AHB1_BASEADDR + HAL_CRC_OFFSET)); /**< this is a pointer variable through which we will access our CRC registers to configure them*/

/******************************************************************************
 * Function Prototypes
 *******************************************************************************/

/*** End of File **************************************************************/
#endif /*HAL_CRC_REG_H_*/