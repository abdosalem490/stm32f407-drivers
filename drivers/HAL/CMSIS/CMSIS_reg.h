/**
 * --------------------------------------------------------------------------------------------------------------------------------------
 * |    @title          :   CMSIS                                                                                                       |
 * |    @file           :   CMSIS_reg.h                                                                                              	|
 * |    @author         :   Abdelrahman Mohamed Salem                                                                                   |
 * |    @origin_date    :   17/07/2023                                                                                                  |
 * |    @version        :   1.0.0                                                                                                       |
 * |    @tool_chain     :   GNU Tools for STM32                                                                                         |
 * |    @compiler       :   GCC                                                                                                         |
 * |    @C_standard     :   ISO C99 (-std=c99)                                                                                          |
 * |    @target         :   stm32f407VGTX                                                                                               |
 * |    @notes          :   None                                                                                                        |
 * |    @license        :   MIT License                                                                                                 |
 * |    @brief          :   this file contains register addresses of arm cortex m4 with FPU and bus base addresses                      |
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
 * |    15/07/2023      1.0.0           Abdelrahman Mohamed Salem       file Created.                                              		|
 * --------------------------------------------------------------------------------------------------------------------------------------
 */

#ifndef CMSIS_REG_H_
#define CMSIS_REG_H_

/******************************************************************************
 * Includes
 *******************************************************************************/

/******************************************************************************
 * Preprocessor Constants
 *******************************************************************************/

/**
 * @brief: these are buses base addresses, will be referred to as @HAL_CMSIS_BUSES_BASE_ADDR
 */
#define HAL_CMSIS_AHB3_BASEADDR 0x60000000 /**< boundary address = 0x6000 0000 - 0xA000 0FFF where this bus is advanced high performance bus */
#define HAL_CMSIS_AHB2_BASEADDR 0x50000000 /**< boundary address = 0x5000 0000 - 0x5006 0BFF where this bus is advanced high performance bus */
#define HAL_CMSIS_AHB1_BASEADDR 0x40020000 /**< boundary address = 0x4002 0000 - 0x4007 FFFF where this bus is advanced high performance bus */
#define HAL_CMSIS_APB2_BASEADDR 0x40010000 /**< boundary address = 0x4001 0000 - 0x4001 57FF where this bus is advanced peripheral bus */
#define HAL_CMSIS_APB1_BASEADDR 0x40000000 /**< boundary address = 0x4000 0000 - 0x4000 7FFF where this bus is advanced peripheral bus */

/**
 * @brief: these are some common peripherals base addresses
 */
#define HAL_CMSIS_FLASH_BASE_ADDR 0x08000000	/**< base address of the flash memory, size = 1 Megabyte*/
#define HAL_CMSIS_SRAM1_BASE_ADDR 0x20000000	/**< base address of the sram1 memory, size = 112 KiloByte*/
#define HAL_CMSIS_SRAM2_BASE_ADDR 0x2001C000	/**< base address of the sram2 memory, size = 16 KiloByte*/
#define HAL_CMSIS_CCM_SRAM_BASE_ADDR 0x10000000 /**< base address of the core coupled sram memory, size = 64 KiloByte*/

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

/******************************************************************************
 * Function Prototypes
 *******************************************************************************/

/*** End of File **************************************************************/
#endif /*CMSIS_REG_H_*/