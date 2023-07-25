/**
 * --------------------------------------------------------------------------------------------------------------------------------------
 * |    @title          :   Flash                                                                                                       |
 * |    @file           :   Flash_header.h                                                                                              |
 * |    @author         :   Abdelrahman Mohamed Salem                                                                                   |
 * |    @origin_date    :   17/07/2023                                                                                                  |
 * |    @version        :   1.0.0                                                                                                       |
 * |    @tool_chain     :   GNU Tools for STM32                                                                                         |
 * |    @compiler       :   GCC                                                                                                         |
 * |    @C_standard     :   ISO C99 (-std=c99)                                                                                          |
 * |    @target         :   stm32f407VGTX                                                                                               |
 * |    @notes          :   None                                                                                                        |
 * |    @license        :   MIT License                                                                                                 |
 * |    @brief          :   this header file contains useful functions to interface with the embedded flash memory inside stm32f407     |
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

#ifndef FLASH_HEADER_H_
#define FLASH_HEADER_H_

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

/******************************************************************************
 * Typedefs
 *******************************************************************************/

/**
 * @enum: Flash_Sectors_t
 * @brief constants used to tell functions which sector we will be dealing with, refer to "flash_config.h" to see the base address and spaces for each memory
 * @note: it will be referred to as @HAL_FLASH_SECTORS
 */
typedef enum
{
    HAL_FLASH_MAIN_MEM_SECTOR_0 = 0x0001,  /**< Value = 0b0000 0000 0000 0001, Base Address =  0x0800 0000 to 0x0800 3FFF, size = 16 Kbytes */
    HAL_FLASH_MAIN_MEM_SECTOR_1 = 0x0002,  /**< Value = 0b0000 0000 0000 0010, Base Address =  0x0800 4000 to 0x0800 7FFF, size = 16 Kbytes */
    HAL_FLASH_MAIN_MEM_SECTOR_2 = 0x0004,  /**< Value = 0b0000 0000 0000 0100, Base Address =  0x0800 8000 to 0x0800 BFFF, size = 16 Kbytes */
    HAL_FLASH_MAIN_MEM_SECTOR_3 = 0x0008,  /**< Value = 0b0000 0000 0000 1000, Base Address =  0x0800 C000 to 0x0800 FFFF, size = 16 Kbytes */
    HAL_FLASH_MAIN_MEM_SECTOR_4 = 0x0010,  /**< Value = 0b0000 0000 0001 0000, Base Address =  0x0801 0000 to 0x0801 FFFF, size = 64 Kbytes */
    HAL_FLASH_MAIN_MEM_SECTOR_5 = 0x0020,  /**< Value = 0b0000 0000 0010 0000, Base Address =  0x0802 0000 to 0x0803 FFFF, size = 128 Kbytes */
    HAL_FLASH_MAIN_MEM_SECTOR_6 = 0x0040,  /**< Value = 0b0000 0000 0100 0000, Base Address =  0x0804 0000 to 0x0805 FFFF, size = 128 Kbytes */
    HAL_FLASH_MAIN_MEM_SECTOR_7 = 0x0080,  /**< Value = 0b0000 0000 1000 0000, Base Address =  0x0806 0000 to 0x0807 FFFF, size = 128 Kbytes */
    HAL_FLASH_MAIN_MEM_SECTOR_8 = 0x0100,  /**< Value = 0b0000 0001 0000 0000, Base Address =  0x0808 0000 to 0x0809 FFFF, size = 128 Kbytes */
    HAL_FLASH_MAIN_MEM_SECTOR_9 = 0x0200,  /**< Value = 0b0000 0010 0000 0000, Base Address =  0x080A 0000 to 0x080B FFFF, size = 128 Kbytes */
    HAL_FLASH_MAIN_MEM_SECTOR_10 = 0x0400, /**< Value = 0b0000 0100 0000 0000, Base Address =  0x080C 0000 to 0x080D FFFF, size = 128 Kbytes */
    HAL_FLASH_MAIN_MEM_SECTOR_11 = 0x0800, /**< Value = 0b0000 1000 0000 0000, Base Address =  0x080E 0000 to 0x080F FFFF, size = 128 Kbytes */
    HAL_FLASH_SYSTEM_MEMORY = 0x1000,      /**< Value = 0b0001 0000 0000 0000, Base Address =  0x1FFF 0000 to 0x1FFF 77FF, size = 30 Kbytes */
    HAL_FLASH_OTP_AREA = 0x200,            /**< Value = 0b0010 0000 0000 0000, Base Address =  0x1FFF 7800 to 0x1FFF 7A0F, size = 512 bytes */
    HAL_FLASH_OPTION_BYTES = 0x4000,       /**< Value = 0b0100 0000 0000 0000, Base Address =  0x1FFF C000 to 0x1FFF C00F, size = 16 bytes */
} Flash_Sectors_t;

/******************************************************************************
 * Variables
 *******************************************************************************/

/******************************************************************************
 * Function Prototypes
 *******************************************************************************/

/*** End of File **************************************************************/
#endif /*FLASH_HEADER_H_*/