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

#ifndef HAL_FLASH_HEADER_H_
#define HAL_FLASH_HEADER_H_

/******************************************************************************
 * Includes
 *******************************************************************************/

/**
 * @reason: contains standard integer definition
 */
#include "../../lib/stdint.h"

/**
 * @reason: contains definition for function callbacks
 */
#include "../../lib/common.h"

/******************************************************************************
 * Preprocessor Constants
 *******************************************************************************/
/**
 * @related: refer to @HAL_FLASH_SECTORS in "flash_header.h"
 * @brief: these are the base addresses of different sectors of flash
 * @reference: @HAL_FLASH_BASEADDR
 */
#define HAL_FLASH_MAIN_MEM_SECTOR_0_BASEADDR 0x08000000  /**< Base address of sector 0 of flash memory*/
#define HAL_FLASH_MAIN_MEM_SECTOR_1_BASEADDR 0x08004000  /**< Base address of sector 1 of flash memory*/
#define HAL_FLASH_MAIN_MEM_SECTOR_2_BASEADDR 0x08008000  /**< Base address of sector 2 of flash memory*/
#define HAL_FLASH_MAIN_MEM_SECTOR_3_BASEADDR 0x0800C000  /**< Base address of sector 3 of flash memory*/
#define HAL_FLASH_MAIN_MEM_SECTOR_4_BASEADDR 0x08010000  /**< Base address of sector 4 of flash memory*/
#define HAL_FLASH_MAIN_MEM_SECTOR_5_BASEADDR 0x08020000  /**< Base address of sector 5 of flash memory*/
#define HAL_FLASH_MAIN_MEM_SECTOR_6_BASEADDR 0x08040000  /**< Base address of sector 6 of flash memory*/
#define HAL_FLASH_MAIN_MEM_SECTOR_7_BASEADDR 0x08060000  /**< Base address of sector 7 of flash memory*/
#define HAL_FLASH_MAIN_MEM_SECTOR_8_BASEADDR 0x08080000  /**< Base address of sector 8 of flash memory*/
#define HAL_FLASH_MAIN_MEM_SECTOR_9_BASEADDR 0x080A0000  /**< Base address of sector 9 of flash memory*/
#define HAL_FLASH_MAIN_MEM_SECTOR_10_BASEADDR 0x080C0000 /**< Base address of sector 10 of flash memory*/
#define HAL_FLASH_MAIN_MEM_SECTOR_11_BASEADDR 0x080E0000 /**< Base address of sector 11 of flash memory*/

/**
 * @related: refer to @HAL_FLASH_SECTORS in "flash_header.h"
 * @brief: these are the base addresses of different sectors of flash
 * @reference: @HAL_FLASH_SIZES
 */
#define HAL_FLASH_MAIN_MEM_SECTOR_1_SIZE 16000   /**< Size of sector 1 of flash memory = 16 Kbytes (showed size is in bytes)*/
#define HAL_FLASH_MAIN_MEM_SECTOR_2_SIZE 16000   /**< Size of sector 2 of flash memory = 16 Kbytes (showed size is in bytes)*/
#define HAL_FLASH_MAIN_MEM_SECTOR_3_SIZE 16000   /**< Size of sector 3 of flash memory = 16 Kbytes (showed size is in bytes)*/
#define HAL_FLASH_MAIN_MEM_SECTOR_4_SIZE 16000   /**< Size of sector 4 of flash memory = 16 Kbytes (showed size is in bytes)*/
#define HAL_FLASH_MAIN_MEM_SECTOR_5_SIZE 64000   /**< Size of sector 5 of flash memory = 64 Kbytes (showed size is in bytes)*/
#define HAL_FLASH_MAIN_MEM_SECTOR_6_SIZE 128000  /**< Size of sector 6 of flash memory = 128 Kbytes (showed size is in bytes)*/
#define HAL_FLASH_MAIN_MEM_SECTOR_7_SIZE 128000  /**< Size of sector 7 of flash memory = 128 Kbytes (showed size is in bytes)*/
#define HAL_FLASH_MAIN_MEM_SECTOR_8_SIZE 128000  /**< Size of sector 8 of flash memory = 128 Kbytes (showed size is in bytes)*/
#define HAL_FLASH_MAIN_MEM_SECTOR_9_SIZE 128000  /**< Size of sector 9 of flash memory = 128 Kbytes (showed size is in bytes)*/
#define HAL_FLASH_MAIN_MEM_SECTOR_10_SIZE 128000 /**< Size of sector 10 of flash memory = 128 Kbytes (showed size is in bytes)*/
#define HAL_FLASH_MAIN_MEM_SECTOR_11_SIZE 128000 /**< Size of sector 11 of flash memory = 128 Kbytes (showed size is in bytes)*/

/**
 * @related: refer to @HAL_FLASH_OTP_Blocks_t in "flash_header.h"
 * @brief: these are the base addresses of different blocks of otp memory
 * @reference: @HAL_FLASH_OPT_BLOCK_ADDR
 */
#define HAL_FLASH_OTP_BLOCK_0_BASEADDR 0x1FFF7800  /**< Base address of Block 0 of OTP (one-time programmable) memory*/
#define HAL_FLASH_OTP_BLOCK_1_BASEADDR 0x1FFF7820  /**< Base address of Block 1 of OTP (one-time programmable) memory*/
#define HAL_FLASH_OTP_BLOCK_2_BASEADDR 0x1FFF7840  /**< Base address of Block 2 of OTP (one-time programmable) memory*/
#define HAL_FLASH_OTP_BLOCK_3_BASEADDR 0x1FFF7860  /**< Base address of Block 3 of OTP (one-time programmable) memory*/
#define HAL_FLASH_OTP_BLOCK_4_BASEADDR 0x1FFF7880  /**< Base address of Block 4 of OTP (one-time programmable) memory*/
#define HAL_FLASH_OTP_BLOCK_5_BASEADDR 0x1FFF78A0  /**< Base address of Block 5 of OTP (one-time programmable) memory*/
#define HAL_FLASH_OTP_BLOCK_6_BASEADDR 0x1FFF78C0  /**< Base address of Block 6 of OTP (one-time programmable) memory*/
#define HAL_FLASH_OTP_BLOCK_7_BASEADDR 0x1FFF78E0  /**< Base address of Block 7 of OTP (one-time programmable) memory*/
#define HAL_FLASH_OTP_BLOCK_8_BASEADDR 0x1FFF7900  /**< Base address of Block 8 of OTP (one-time programmable) memory*/
#define HAL_FLASH_OTP_BLOCK_9_BASEADDR 0x1FFF7920  /**< Base address of Block 9 of OTP (one-time programmable) memory*/
#define HAL_FLASH_OTP_BLOCK_10_BASEADDR 0x1FFF7940 /**< Base address of Block 10 of OTP (one-time programmable) memory*/
#define HAL_FLASH_OTP_BLOCK_11_BASEADDR 0x1FFF7960 /**< Base address of Block 11 of OTP (one-time programmable) memory*/
#define HAL_FLASH_OTP_BLOCK_12_BASEADDR 0x1FFF7980 /**< Base address of Block 12 of OTP (one-time programmable) memory*/
#define HAL_FLASH_OTP_BLOCK_13_BASEADDR 0x1FFF79A0 /**< Base address of Block 13 of OTP (one-time programmable) memory*/
#define HAL_FLASH_OTP_BLOCK_14_BASEADDR 0x1FFF79C0 /**< Base address of Block 14 of OTP (one-time programmable) memory*/
#define HAL_FLASH_OTP_BLOCK_15_BASEADDR 0x1FFF79E0 /**< Base address of Block 15 of OTP (one-time programmable) memory*/

/**
 * @brief: these are the sizes of different blocks of otp memory
 * @reference: @HAL_FLASH_OPT_BLOCK_SIZES
 */
#define HAL_FLASH_OPT_BLOCK_SIZE 32 /**< this size is in bytes*/

/******************************************************************************
 * Configuration Constants
 *******************************************************************************/

/******************************************************************************
 * Macros
 *******************************************************************************/

/******************************************************************************
 * Tables
 *******************************************************************************/

/**
 * @table_name: HAL_FLASH_TABLE_MEM_ORGANIZATION
 * @brief: this table is used to present memory organization of the flash memory
 *
 * +---------------+------------------------------+----------------------------+---------------+
 *  |     Block     |             Name             |    Block base addresses       |      Size     |
 *  +---------------+------------------------------+---------------------------+---------------+
 *  |               | HAL_FLASH_MAIN_MEM_SECTOR_0  | 0x0800 0000 - 0x0800 3FFF |  16 KiloBytes |
 *  |               | HAL_FLASH_MAIN_MEM_SECTOR_1  | 0x0800 4000 - 0x0800 7FFF |  16 KiloBytes |
 *  |               | HAL_FLASH_MAIN_MEM_SECTOR_2  | 0x0800 8000 - 0x0800 BFFF |  16 KiloBytes |
 *  |               | HAL_FLASH_MAIN_MEM_SECTOR_3  | 0x0800 C000 - 0x0800 FFFF |  16 KiloBytes |
 *  |               | HAL_FLASH_MAIN_MEM_SECTOR_4  | 0x0801 0000 - 0x0801 FFFF |  64 KiloBytes |
 *  |               | HAL_FLASH_MAIN_MEM_SECTOR_5  | 0x0802 0000 - 0x0803 FFFF | 128 KiloBytes |
 *  |  Main Memory  | HAL_FLASH_MAIN_MEM_SECTOR_6  | 0x0804 0000 - 0x0805 FFFF | 128 KiloBytes |
 *  |               | HAL_FLASH_MAIN_MEM_SECTOR_7  | 0x0806 0000 - 0x0807 FFFF | 128 KiloBytes |
 *  |               | HAL_FLASH_MAIN_MEM_SECTOR_8  | 0x0808 0000 - 0x0809 FFFF | 128 KiloBytes |
 *  |               | HAL_FLASH_MAIN_MEM_SECTOR_9  | 0x080A 0000 - 0x080B FFFF | 128 KiloBytes |
 *  |               | HAL_FLASH_MAIN_MEM_SECTOR_10 | 0x080C 0000 - 0x080D FFFF | 128 KiloBytes |
 *  |               | HAL_FLASH_MAIN_MEM_SECTOR_11 | 0x080E 0000 - 0x080F FFFF | 128 KiloBytes |
 *  +---------------+------------------------------+---------------------------+---------------+
 *  |               |    HAL_FLASH_OTP_BLOCK_0     | 0x1FFF 7800 - 0x1FFF 781F |    32 bytes   |
 *  |               |    HAL_FLASH_OTP_BLOCK_1     | 0x1FFF 7820 - 0x1FFF 783F |    32 bytes   |
 *  |               |    HAL_FLASH_OTP_BLOCK_2     | 0x1FFF 7840 - 0x1FFF 785F |    32 bytes   |
 *  |               |    HAL_FLASH_OTP_BLOCK_3     | 0x1FFF 7860 - 0x1FFF 787F |    32 bytes   |
 *  |               |    HAL_FLASH_OTP_BLOCK_4     | 0x1FFF 7880 - 0x1FFF 789F |    32 bytes   |
 *  |               |    HAL_FLASH_OTP_BLOCK_5     | 0x1FFF 78A0 - 0x1FFF 78BF |    32 bytes   |
 *  |               |    HAL_FLASH_OTP_BLOCK_6     | 0x1FFF 78C0 - 0x1FFF 78DF |    32 bytes   |
 *  |               |    HAL_FLASH_OTP_BLOCK_7     | 0x1FFF 78E0 - 0x1FFF 78FF |    32 bytes   |
 *  |      OTP      |    HAL_FLASH_OTP_BLOCK_8     | 0x1FFF 7900 - 0x1FFF 791F |    32 bytes   |
 *  |               |    HAL_FLASH_OTP_BLOCK_9     | 0x1FFF 7920 - 0x1FFF 793F |    32 bytes   |
 *  |               |    HAL_FLASH_OTP_BLOCK_10    | 0x1FFF 7940 - 0x1FFF 795F |    32 bytes   |
 *  |               |    HAL_FLASH_OTP_BLOCK_11    | 0x1FFF 7960 - 0x1FFF 797F |    32 bytes   |
 *  |               |    HAL_FLASH_OTP_BLOCK_12    | 0x1FFF 7980 - 0x1FFF 799F |    32 bytes   |
 *  |               |    HAL_FLASH_OTP_BLOCK_13    | 0x1FFF 79A0 - 0x1FFF 79BF |    32 bytes   |
 *  |               |    HAL_FLASH_OTP_BLOCK_14    | 0x1FFF 79C0 - 0x1FFF 79DF |    32 bytes   |
 *  |               |    HAL_FLASH_OTP_BLOCK_15    | 0x1FFF 79E0 - 0x1FFF 79FF |    32 bytes   |
 *  +---------------+------------------------------+---------------------------+---------------+
 *  |          System memory                       | 0x1FFF 0000 - 0x1FFF 77FF |  30 Kilobytes |
 *  |          Option bytes                        | 0x1FFF C000 - 0x1FFF C00F |    16 bytes   |
 *  +---------------+------------------------------+---------------------------+---------------+
 *
 */

/******************************************************************************
 * Typedefs
 *******************************************************************************/

/**
 * @enum: Hal_Flash_ErrStates_t
 * @brief: contains all possible errors that can result from dealing with the embedded flash memory interface.
 */
typedef enum
{
    HAL_FLASH_OK,                          /**< it means everything has gone as intended so no errors*/
    HAL_FLASH_ERR_NOT_ENOUGH_MEM,          /**< it means that there is no enough memory for the given data to be written onto flash*/
    HAL_FLASH_ERR_OUT_OF_RANGE,            /**< it means that you are trying to access an address that isn't in the range of flash memory*/
    HAL_FLASH_ERR_INVALID_PARAMS,          /**< it means that the supplied parameters of the function are invalid*/
    HAL_FLASH_ERR_INVALID_CONFIG,          /**< it means that the supplied configurations in the "flash_config.h" file are incorrect*/
    HAL_FLASH_ERR_FLASH_BUSY,              /**< it means that there is a Flash memory operation still in progress so you can't do anything right now*/
    HAL_FLASH_ERR_PROGRAMMING_SEQUENCE,    /**< it means that the standard programming sequence is not respected (mostly it concerns the implemented code of flash driver so mostly if you get this error, it means there is a problem with the implementation of flash driver)*/
    HAL_FLASH_ERR_PROGRAMMING_PARALLELISM, /**< it means that the parameter ProgramSize in globalConstArr_FlashConfig_t in configuration file have a wrong value associated with it, so please return to "flash_config.h" and configure it properly according to the table in the file and it also happens in case the size of the access program sequence does not correspond to the parallelism (related to the implemented code)*/
    HAL_FLASH_ERR_PROGRAMMING_ALIGNMENT,   /**< it means that program data to written into the Flash memory crossed the 128-bit row boundary (problem related to the implementation code of the flash driver), @details: If everything was aligned to its native size, it would not matter. But unaligned memory accesses may not be able to be written for a case like this. Accesses that cross a 128bit threshold don't need to be over that size-- anything over a single byte could span multiple 128bit 'rows'. As an example, a 16 bit store to address 15 (0xF) will cover part of both the first 128 bit row from addresses 0 to 15 and the second 128 bit row from 16 to 31. If this address was part of the described flash hardware, it would not be written and fail with a program alignment error. A good way to circumvent this is to just use a byte by byte copy-- byte writes can't be unaligned. If you want it to be faster, do a byte copy only around the first/last unaligned parts of the data. Memcpy should be aligned but it's not guaranteed to be. Standard library functions like this aren't really designed with odd memory mapped peripherals in mind.*/
    HAL_FLASH_ERR_WRITE_PROTECTION,        /**< it means that when an address to be erased/programmed belongs to a write-protected part of the Flash memory*/
    HAL_FLASH_ERR_OPERATION,               /**< it means that an unknown error ocurred while trying to program/erase/read a part of the flash memory */
} HAL_FLASH_ErrStates_t;

/**
 * @enum: HAL_FLASH_Sectors_t
 * @brief constants used to tell functions which sector we will be dealing with, refer to @HAL_FLASH_BASEADDR in "flash_header.h" to see the base address and spaces for each memory
 */
typedef enum
{
    HAL_FLASH_MAIN_MEM_SECTOR_0 = 0x0001,    /**< Value = 0b0000 0000 0000 0001, Base Address =  0x0800 0000 to 0x0800 3FFF, size = 16 Kbytes */
    HAL_FLASH_MAIN_MEM_SECTOR_1 = 0x0002,    /**< Value = 0b0000 0000 0000 0010, Base Address =  0x0800 4000 to 0x0800 7FFF, size = 16 Kbytes */
    HAL_FLASH_MAIN_MEM_SECTOR_2 = 0x0004,    /**< Value = 0b0000 0000 0000 0100, Base Address =  0x0800 8000 to 0x0800 BFFF, size = 16 Kbytes */
    HAL_FLASH_MAIN_MEM_SECTOR_3 = 0x0008,    /**< Value = 0b0000 0000 0000 1000, Base Address =  0x0800 C000 to 0x0800 FFFF, size = 16 Kbytes */
    HAL_FLASH_MAIN_MEM_SECTOR_4 = 0x0010,    /**< Value = 0b0000 0000 0001 0000, Base Address =  0x0801 0000 to 0x0801 FFFF, size = 64 Kbytes */
    HAL_FLASH_MAIN_MEM_SECTOR_5 = 0x0020,    /**< Value = 0b0000 0000 0010 0000, Base Address =  0x0802 0000 to 0x0803 FFFF, size = 128 Kbytes */
    HAL_FLASH_MAIN_MEM_SECTOR_6 = 0x0040,    /**< Value = 0b0000 0000 0100 0000, Base Address =  0x0804 0000 to 0x0805 FFFF, size = 128 Kbytes */
    HAL_FLASH_MAIN_MEM_SECTOR_7 = 0x0080,    /**< Value = 0b0000 0000 1000 0000, Base Address =  0x0806 0000 to 0x0807 FFFF, size = 128 Kbytes */
    HAL_FLASH_MAIN_MEM_SECTOR_8 = 0x0100,    /**< Value = 0b0000 0001 0000 0000, Base Address =  0x0808 0000 to 0x0809 FFFF, size = 128 Kbytes */
    HAL_FLASH_MAIN_MEM_SECTOR_9 = 0x0200,    /**< Value = 0b0000 0010 0000 0000, Base Address =  0x080A 0000 to 0x080B FFFF, size = 128 Kbytes */
    HAL_FLASH_MAIN_MEM_SECTOR_10 = 0x0400,   /**< Value = 0b0000 0100 0000 0000, Base Address =  0x080C 0000 to 0x080D FFFF, size = 128 Kbytes */
    HAL_FLASH_MAIN_MEM_SECTOR_11 = 0x0800,   /**< Value = 0b0000 1000 0000 0000, Base Address =  0x080E 0000 to 0x080F FFFF, size = 128 Kbytes */
    HAL_FLASH_MAIN_MEM_ALL_SECTORS = 0x1000, /**< Value = 0b0001 0000 0000 0000, Base Address =  0x0800 0000 to 0x080F FFFF, size = 1 Megabytes */
    HAL_FLASH_MAX_MAIN_MEM_SECTOR,           /**< that value should never be used and it's only used by the implementation code for verifying the input*/
} HAL_FLASH_Sectors_t;

/**
 * @enum: HAL_FLASH_OTP_Blocks_t
 * @brief constants used to tell functions which block from OTP we will be dealing with, refer to @HAL_FLASH_BASEADDR in "flash_header.h" to see the base address and spaces for each memory
 */
typedef enum
{
    HAL_FLASH_OTP_BLOCK_0 = 0x0001,  /**< Value = 0b0000 0000 0000 0001, Base Address =  0x1FFF 7800 to 0x1FFF 781F, size = 32 bytes */
    HAL_FLASH_OTP_BLOCK_1 = 0x0002,  /**< Value = 0b0000 0000 0000 0010, Base Address =  0x1FFF 7820 to 0x1FFF 783F, size = 32 bytes */
    HAL_FLASH_OTP_BLOCK_2 = 0x0004,  /**< Value = 0b0000 0000 0000 0100, Base Address =  0x1FFF 7840 to 0x1FFF 785F, size = 32 bytes */
    HAL_FLASH_OTP_BLOCK_3 = 0x0008,  /**< Value = 0b0000 0000 0000 1000, Base Address =  0x1FFF 7860 to 0x1FFF 787F, size = 32 bytes */
    HAL_FLASH_OTP_BLOCK_4 = 0x0010,  /**< Value = 0b0000 0000 0001 0000, Base Address =  0x1FFF 7880 to 0x1FFF 789F, size = 32 bytes */
    HAL_FLASH_OTP_BLOCK_5 = 0x0020,  /**< Value = 0b0000 0000 0010 0000, Base Address =  0x1FFF 78A0 to 0x1FFF 78BF, size = 32 bytes */
    HAL_FLASH_OTP_BLOCK_6 = 0x0040,  /**< Value = 0b0000 0000 0100 0000, Base Address =  0x1FFF 78C0 to 0x1FFF 78DF, size = 32 bytes */
    HAL_FLASH_OTP_BLOCK_7 = 0x0080,  /**< Value = 0b0000 0000 1000 0000, Base Address =  0x1FFF 78E0 to 0x1FFF 78FF, size = 32 bytes */
    HAL_FLASH_OTP_BLOCK_8 = 0x0100,  /**< Value = 0b0000 0001 0000 0000, Base Address =  0x1FFF 7900 to 0x1FFF 791F, size = 32 bytes */
    HAL_FLASH_OTP_BLOCK_9 = 0x0200,  /**< Value = 0b0000 0010 0000 0000, Base Address =  0x1FFF 7920 to 0x1FFF 793F, size = 32 bytes */
    HAL_FLASH_OTP_BLOCK_10 = 0x0400, /**< Value = 0b0000 0100 0000 0000, Base Address =  0x1FFF 7940 to 0x1FFF 795F, size = 32 bytes */
    HAL_FLASH_OTP_BLOCK_11 = 0x0800, /**< Value = 0b0000 1000 0000 0000, Base Address =  0x1FFF 7960 to 0x1FFF 797F, size = 32 bytes */
    HAL_FLASH_OTP_BLOCK_12 = 0x1000, /**< Value = 0b0001 0000 0000 0000, Base Address =  0x1FFF 7980 to 0x1FFF 799F, size = 32 bytes */
    HAL_FLASH_OTP_BLOCK_13 = 0x2000, /**< Value = 0b0010 0000 0000 0000, Base Address =  0x1FFF 79A0 to 0x1FFF 79BF, size = 32 bytes */
    HAL_FLASH_OTP_BLOCK_14 = 0x4000, /**< Value = 0b0100 0000 0000 0000, Base Address =  0x1FFF 79C0 to 0x1FFF 79DF, size = 32 bytes */
    HAL_FLASH_OTP_BLOCK_15 = 0x8000, /**< Value = 0b1000 0000 0000 0000, Base Address =  0x1FFF 79E0 to 0x1FFF 79FF, size = 32 bytes */
    HAL_FLASH_MAX_OTP_SECTOR,        /**< that value should never be used and it's only used by the implementation code for verifying the input*/
} HAL_FLASH_OTP_Blocks_t;

/**
 * @enum: HAL_FLASH_OTP_Blocks_t
 * @brief: constants used to tell functions which block from OTP we will be dealing with, refer to @HAL_FLASH_BASEADDR in "flash_header.h" to see the base address and spaces for each memory
 */
typedef enum
{
    HAL_FLASH_CALLBACK_TYPE_SUCCESS = 1,                     /**< this is type of callback that indicates the success of the previous operation*/
    HAL_FLASH_CALLBACK_TYPE_ERR_WRITE_PROTECTION = 2,        /**< this is type of callback that indicates the failure of the previous operation due to an attempt to program a write-protected area*/
    HAL_FLASH_CALLBACK_TYPE_ERR_PROGRAMMING_SEQUENCE = 4,    /**< this is type of callback that indicates the failure of the previous operation due to incorrect sequence of steps of driver code*/
    HAL_FLASH_CALLBACK_TYPE_ERR_PROGRAMMING_PARALLELISM = 8, /**< this is type of callback that indicates the failure of the previous operation due to incorrect selection of program size in the configuration file*/
    HAL_FLASH_CALLBACK_TYPE_ERR_PROGRAMMING_ALIGNMENT = 16,  /**< this is type of callback that indicates the failure of the previous operation due to alignment error of data in flash memory*/
    HAL_FLASH_CALLBACK_TYPE_ERR_OPERATION = 32,              /**< this is type of callback that indicates the failure of the previous operation due to unknown reason*/
    HAL_FLASH_MAX_CALLBACK_TYPE,                             /**< that value should never be used and it's only used by the implementation code for verifying the input*/
} HAL_FLASH_CallbacksTypes_t;

/**
 * @enum: HAL_FLASH_ConfigValOperationType_t
 * @brief: this enum contains values to determine whether functions of Flash should behave as interrupt-based or blocking
 */
typedef enum
{
    HAL_FLASH_CONFIG_VAL_OPERATION_TYPE_INTERRUPT = 0, /**< this will make any operation on flash memory is interrupt based so no blocking code*/
    HAL_FLASH_CONFIG_VAL_OPERATION_TYPE_BLOCKING = 1,  /**< this will make any operation on flash memory is blocking based so it will waste CPU cycles on waiting for hardware flags*/
    HAL_FLASH_CONFIG_VAL_MAX_OPERATION_TYPE,           /**< that value should never be used and it's only used by the implementation code for verifying the input*/
} HAL_FLASH_ConfigValOperationType_t;

/**
 * @enum: HAL_FLASH_ConfigKeys_t
 * @brief constants used with the function HAL_FLASH_Config(const uint8_t argConst_u8Key, const uint8_t argConst_u8Value) where it represents the keys as one key represents a variable to configure
 * @note: each key in the below enum has a reference to indicate which possible values are associated with it
 */
typedef enum
{
    HAL_FLASH_CONFIG_KEY_OPERATION_TYPE = 0, /**< this indicates how the functions of embedded flash shall behave (whether interrupt-based or blocking-based), for connected values, refer to @HAL_FLASH_ConfigValOperationType_t in "flash_header.h"*/
    HAL_FLASH_MAX_CONFIG_KEY,                /**< that value should never be used and it's only used by the implementation code for verifying the input*/
} HAL_FLASH_ConfigKeys_t;

/******************************************************************************
 * Variables
 *******************************************************************************/

/******************************************************************************
 * Function Prototypes
 *******************************************************************************/

/**
 *  \b function                     :       HAL_FLASH_Init()
 *  \b Description                  :       this functions initialize the embedded flash memory configuration with the configurations supplied in "flash_config.h"
 *  @param                          :       None
 *  @note                           :       This shall be the first function to be called before using any other function in this interface, also it's a blocking function
 *                                          IT IS ADVISED TO CALL HAL_FLASH_Init() BEFORE CALLING ANY OTHER FUNCTION (YOU MAY EVEN CALL IT IN STARTUP CODE BEFORE CONFIGURING PLL SO IT'S FASTER TO INITIALIZED .DATA AND .BSS SECTIONS)
 *  \b PRE-CONDITION                :       make sure to edit all configurations in file "flash_config.h" (any array labeled with @user_todo shall be edited)
 *  \b POST-CONDITION               :       it configures the following properties of flash memory:
 *                                              -> Data cache enablement
 *                                              -> Instruction cache enablement
 *                                              -> Prefetch enablement
 *                                              -> Latency Adjustment
 *                                              -> locking of control registers of flash so it can be edited
 *                                              -> enabling error interrupts and end of operation interrupts
 *                                              -> data access size (program size)
 *                                              -> read protection of flash memory as a whole
 *                                              -> write protection of some sectors flash memory
 *                                              -> brownout reset level
 *                                              -> type of independent watch dog time
 *                                              -> reset on entering stop mode
 *                                              -> reset on entering standby mode
 *  @return                         :       it return one of error states indicating whether a failure or success happened during initialization (refer to @HAL_FLASH_ErrStates_t in "flash_header.h")
 *  @see                            :       HAL_FLASH_Erase(const uint16_t arg_u8SectorNum)
 *  @see                            :       HAL_FLASH_Write(const uint32_t argConst_u32BaseAddress, uint32_t arg_u32DataLen, const uint8_t *argConst_pu8WriteData)
 *  @see                            :       HAL_FLASH_OTPFuse(const uint16_t argConst_u32OTPBlock)
 *  @see                            :       HAL_FLASH_Fill(const uint32_t argConst_u32BaseAddress, uint32_t arg_u32AddressLen, const uint8_t *argConst_pu8WriteData, uint32_t arg_u32DataLen)
 *  @see                            :       HAL_FLASH_Read(const uint32_t argConst_u32BaseAddress, uint32_t arg_u32AddressLen, uint8_t *arg_pu8ReadData)
 *  @see                            :       HAL_FLASH_RegisterCallback(const uint8_t argConst_u8Type, const functionCallBack_t argConst_pFunctionCallBack)
 *  @see                            :       HAL_FLASH_Config(const uint8_t argConst_u8Key, const uint8_t argConst_u8Value)
 *
 *  \b Example:
 * @code
 * #include "flash_header.h"
 * int main() {
 * HAL_FLASH_Init();    // make sure that you edited any array in "flash_config.h" labeled with @user_todo so that embedded flash memory can be initialized correctly
 * return 0;
 * }
 * @endcode
 *
 * <br><b> - HISTORY OF CHANGES - </b>
 * <table align="left" style="width:800px">
 * <tr><td> Date       </td><td> Software Version </td><td> Initials </td><td> Description </td></tr>
 * <tr><td> 30/07/2023 </td><td> 1.0.0            </td><td> AMS      </td><td> Interface Created </td></tr>
 * </table><br><br>
 * <hr>
 */
HAL_FLASH_ErrStates_t HAL_FLASH_Init();

/**
 *  \b function                         :       HAL_FLASH_Erase(const uint16_t arg_u8SectorNum)
 *  \b Description                      :       this functions is used to erase a whole sector of flash memory
 *  @param  arg_u8SectorNum [IN]        :       for possible values refer to @HAL_FLASH_Sectors_t in "flash_header.h" ,this is input argument used to determine which one of the flash main memory sectors to be erased
 *  @note                               :       None
 *  \b PRE-CONDITION                    :       make sure to call HAL_FLASH_Init() and make sure the sector to be erased isn't write-protected from configuration
 *  \b POST-CONDITION                   :       it erases the selected sector (make its all bytes = 0)
 *  @return                             :       it return one of error states indicating whether a failure or success happened during erase of the sector (refer to @HAL_FLASH_ErrStates_t in "flash_header.h")
 *  @see                                :       HAL_FLASH_Init()
 *  @see                                :       HAL_FLASH_Write(const uint32_t argConst_u32BaseAddress, uint32_t arg_u32DataLen, const uint8_t *argConst_pu8WriteData)
 *  @see                                :       HAL_FLASH_OTPFuse(const uint16_t argConst_u32OTPBlock)
 *  @see                                :       HAL_FLASH_Fill(const uint32_t argConst_u32BaseAddress, uint32_t arg_u32AddressLen, const uint8_t *argConst_pu8WriteData, uint32_t arg_u32DataLen)
 *  @see                                :       HAL_FLASH_Read(const uint32_t argConst_u32BaseAddress, uint32_t arg_u32AddressLen, uint8_t *arg_pu8ReadData)
 *  @see                                :       HAL_FLASH_RegisterCallback(const uint8_t argConst_u8Type, const functionCallBack_t argConst_pFunctionCallBack)
 *  @see                                :       HAL_FLASH_Config(const uint8_t argConst_u8Key, const uint8_t argConst_u8Value)
 *
 *  \b Example:
 * @code
 * #include "flash_header.h"
 * int main() {
 * HAL_FLASH_Init();    // make sure that you edited any array in "flash_config.h" labeled with @user_todo so that embedded flash memory can be initialized correctly
 * HAL_FLASH_ErrStates_t error_state = HAL_FLASH_Erase(HAL_FLASH_MAIN_MEM_SECTOR_3 | HAL_FLASH_MAIN_MEM_SECTOR_4);    // the behavior of this function shall erase sector 3 and 4 (set content of sector 3 and 4 = 0)
 *
 * if(error_state == HAL_FLASH_OK) // check for error state
 * {
 *      // process was done successfully.
 * }
 * return 0;
 * }
 * @endcode
 *
 * <br><b> - HISTORY OF CHANGES - </b>
 * <table align="left" style="width:800px">
 * <tr><td> Date       </td><td> Software Version </td><td> Initials </td><td> Description </td></tr>
 * <tr><td> 30/07/2023 </td><td> 1.0.0            </td><td> AMS      </td><td> Interface Created </td></tr>
 * </table><br><br>
 * <hr>
 */
HAL_FLASH_ErrStates_t HAL_FLASH_Erase(const uint16_t arg_u8SectorNum);

/**
 *  \b function                             :       HAL_FLASH_Write(const uint32_t argConst_u32BaseAddress, uint32_t arg_u32DataLen, const uint8_t *argConst_pu8WriteData)
 *  \b Description                          :       this functions is used to program/write value(s) onto given address of flash memory
 *  @param  argConst_u32BaseAddress [IN]    :       this is input parameter which is the address to write/program first byte of given data into it.
 *                                                  possible addresses are from 0x0800 0000 to 0x080F FFFF in case of main flash memory (for base address of different sectors of main flash memory and their sizes refer to @HAL_FLASH_BASEADDR and @HAL_FLASH_SIZES in "flash_header.h" ),
 *                                                  while in case of OTP (one-time programmable memory) that can be programmed multiple times till fused using function HAL_FLASH_OTPFuse possible address are from 0x1FFF 7800 to  0x1FFF 79F0 (base address of different blocks of otp memory and their sizes refer to @HAL_FLASH_OPT_BLOCK_ADDR and @HAL_FLASH_OPT_BLOCK_SIZES in "flash_header.h")
 *  @param  arg_u32DataLen [IN]             :       this is input parameter which is the length of the given data in bytes that is going to be written to the memory.
 *  @param  argConst_pu8WriteData [IN]      :       this is input parameter which is the address of first byte of Data that is to be written to the Memory.
 *  @note                                   :       you can write to OTP bytes multiple times as long as HAL_FLASH_OTPFuse(uint16_t arg_u32OTPBlockNum) isn't called upon intended Block
 *  \b PRE-CONDITION                        :       make sure to call HAL_FLASH_Init() and make sure the sector to be programed isn't write-protected from configuration or the OTP to be programmed isn't fused.
 *  \b POST-CONDITION                       :       it writes given data into the flash memory
 *  @return                                 :       it return one of error states indicating whether a failure or success happened during writing of data (refer to @HAL_FLASH_ErrStates_t in "flash_header.h")
 *  @see                                    :       HAL_FLASH_Init()
 *  @see                                    :       HAL_FLASH_Erase(const uint16_t arg_u8SectorNum)
 *  @see                                    :       HAL_FLASH_OTPFuse(const uint16_t argConst_u32OTPBlock)
 *  @see                                    :       HAL_FLASH_Fill(const uint32_t argConst_u32BaseAddress, uint32_t arg_u32AddressLen, const uint8_t *argConst_pu8WriteData, uint32_t arg_u32DataLen)
 *  @see                                    :       HAL_FLASH_Read(const uint32_t argConst_u32BaseAddress, uint32_t arg_u32AddressLen, uint8_t *arg_pu8ReadData)
 *  @see                                    :       HAL_FLASH_RegisterCallback(const uint8_t argConst_u8Type, const functionCallBack_t argConst_pFunctionCallBack)
 *  @see                                    :       HAL_FLASH_Config(const uint8_t argConst_u8Key, const uint8_t argConst_u8Value)
 *
 *  \b Example:
 * @code
 * #include "flash_header.h"
 * #include <string.h>
 * int main() {
 * HAL_FLASH_Init();    // make sure that you edited any array in "flash_config.h" labeled with @user_todo so that embedded flash memory can be initialized correctly
 * uint8_t arr[] = "Hello world";   // data to be written
 * uint32_t len = strlen(arr);      // length of data to be written
 * uint32_t baseAddress = HAL_FLASH_MAIN_MEM_SECTOR_5_BASEADDR + 0x024f; // address of first byte of to be stored data, store data in sector 5 of flash memory with offset 0x024f from base address of sector 5
 * uint8_t* dataPointer = (uint8_t*)&arr;   // pointer to the first byte of data to be written
 * HAL_FLASH_ErrStates_t error_state = HAL_FLASH_Write(baseAddress, len, dataPointer);    // the behavior of this function shall write "Hello world" to flash memory where letter 'H' will be stored in the address 0x0802 024F and the later letter follows 'H' in the addresses so 'e' will be stored in 0x0802 0250 and so on
 *
 * if(error_state == HAL_FLASH_OK) // check for error state
 * {
 *      // data was written successfully
 * }
 * return 0;
 * }
 * @endcode
 *
 * <br><b> - HISTORY OF CHANGES - </b>
 * <table align="left" style="width:800px">
 * <tr><td> Date       </td><td> Software Version </td><td> Initials </td><td> Description </td></tr>
 * <tr><td> 30/07/2023 </td><td> 1.0.0            </td><td> AMS      </td><td> Interface Created </td></tr>
 * </table><br><br>
 * <hr>
 */
HAL_FLASH_ErrStates_t HAL_FLASH_Write(const uint32_t argConst_u32BaseAddress, uint32_t arg_u32DataLen, const uint8_t *argConst_pu8WriteData);

/**
 *  \b function                             :       HAL_FLASH_OTPFuse(uint16_t arg_u32OTPBlockNum)
 *  \b Description                          :       this functions is used to fuse OTP block (32 bytes) so it can't be edited again for lifetime.
 *  @param  arg_u32OTPBlockNum [IN]         :       this is input parameter which is determines which OTP black to be fused, (for possible values, refer to @HAL_FLASH_OTP_Blocks_t in "flash_header.h")
 *  @note                                   :       None.
 *  \b PRE-CONDITION                        :       make sure to call HAL_FLASH_Init() and make sure that the block to be fused isn't already fused.
 *  \b POST-CONDITION                       :       it fuses OPT block so it can't be programmed anytime again during MCU lifetime.
 *  @return                                 :       it return one of error states indicating whether a failure or success happened during fusing of OTP blocks (refer to @HAL_FLASH_ErrStates_t in "flash_header.h")
 *  @see                                    :       HAL_FLASH_Init()
 *  @see                                    :       HAL_FLASH_Erase(const uint16_t arg_u8SectorNum)
 *  @see                                    :       HAL_FLASH_Write(const uint32_t argConst_u32BaseAddress, uint32_t arg_u32DataLen, const uint8_t *argConst_pu8WriteData)
 *  @see                                    :       HAL_FLASH_Fill(const uint32_t argConst_u32BaseAddress, uint32_t arg_u32AddressLen, const uint8_t *argConst_pu8WriteData, uint32_t arg_u32DataLen)
 *  @see                                    :       HAL_FLASH_Read(const uint32_t argConst_u32BaseAddress, uint32_t arg_u32AddressLen, uint8_t *arg_pu8ReadData)
 *  @see                                    :       HAL_FLASH_RegisterCallback(const uint8_t argConst_u8Type, const functionCallBack_t argConst_pFunctionCallBack)
 *  @see                                    :       HAL_FLASH_Config(const uint8_t argConst_u8Key, const uint8_t argConst_u8Value)
 *
 *  \b Example:
 * @code
 * #include "flash_header.h"
 * #include <string.h>
 * int main() {
 * HAL_FLASH_Init();    // make sure that you edited any array in "flash_config.h" labeled with @user_todo so that embedded flash memory can be initialized correctly
 *
 * HAL_FLASH_ErrStates_t error_state = HAL_FLASH_OTPFuse(HAL_FLASH_OTP_BLOCK_8);    // the behavior of this function shall fuse bytes from address 0x1FFF 7900 to 0x1FFF 791F (BLOCK 8) so they can't be programmed anytime in the future
 *
 * if(error_state == HAL_FLASH_OK) // check for error state
 * {
 *      // block was fused successfully
 * }
 * return 0;
 * }
 * @endcode
 *
 * <br><b> - HISTORY OF CHANGES - </b>
 * <table align="left" style="width:800px">
 * <tr><td> Date       </td><td> Software Version </td><td> Initials </td><td> Description </td></tr>
 * <tr><td> 30/07/2023 </td><td> 1.0.0            </td><td> AMS      </td><td> Interface Created </td></tr>
 * </table><br><br>
 * <hr>
 */
HAL_FLASH_ErrStates_t HAL_FLASH_OTPFuse(uint16_t arg_u32OTPBlockNum);

/**
 *  \b function                             :       HAL_FLASH_Fill(const uint32_t argConst_u32BaseAddress, uint32_t arg_u32AddressLen, const uint8_t argConst_u8WriteData)
 *  \b Description                          :       this functions is used to program/write a single value (byte) and repeat this value a number of times given how many time to repeat that value, in other words, it's used to fill a specific range of memory with single value
 *  @param  argConst_u32BaseAddress [IN]    :       this is input parameter which is the first address to begin with writing/programming data.
 *                                                  possible addresses are from 0x0800 0000 to 0x080F FFFF in case of main flash memory (for base address of different sectors of main flash memory and their sizes refer to @HAL_FLASH_BASEADDR and @HAL_FLASH_SIZES in "flash_header.h" ),
 *                                                  while in case of OTP (one-time programmable memory) that can be programmed multiple times till fused using function HAL_FLASH_OTPFuse possible address are from 0x1FFF 7800 to  0x1FFF 79F0 (base address of different blocks of otp memory and their sizes refer to @HAL_FLASH_OPT_BLOCK_ADDR and @HAL_FLASH_OPT_BLOCK_SIZES in "flash_header.h")
 *  @param  arg_u32AddressLen [IN]          :       this is input parameter which is the how many times do you want to repeat data..
 *  @param  argConst_u8WriteData [IN]       :       this is input parameter which is the data to be written repeatedly.
 *  @note                                   :       you can write to OTP bytes multiple times as long as HAL_FLASH_OTPFuse(uint16_t arg_u32OTPBlockNum) isn't called upon intended Block
 *  \b PRE-CONDITION                        :       make sure to call HAL_FLASH_Init() and make sure the sector to be programed isn't write-protected from configuration or the OTP to be programmed isn't fused.
 *  \b POST-CONDITION                       :       it repeat write data in memory.
 *  @return                                 :       it return one of error states indicating whether a failure or success happened during the filling of data of data (refer to @HAL_FLASH_ErrStates_t in "flash_header.h")
 *  @see                                    :       HAL_FLASH_Init()
 *  @see                                    :       HAL_FLASH_Erase(const uint16_t arg_u8SectorNum)
 *  @see                                    :       HAL_FLASH_Write(const uint32_t argConst_u32BaseAddress, uint32_t arg_u32DataLen, const uint8_t *argConst_pu8WriteData)
 *  @see                                    :       HAL_FLASH_OTPFuse(const uint16_t argConst_u32OTPBlock)
 *  @see                                    :       HAL_FLASH_Read(const uint32_t argConst_u32BaseAddress, uint32_t arg_u32AddressLen, uint8_t *arg_pu8ReadData)
 *  @see                                    :       HAL_FLASH_RegisterCallback(const uint8_t argConst_u8Type, const functionCallBack_t argConst_pFunctionCallBack)
 *  @see                                    :       HAL_FLASH_Config(const uint8_t argConst_u8Key, const uint8_t argConst_u8Value)
 *
 *  \b Example:
 * @code
 * #include "flash_header.h"
 * #include <string.h>
 * int main() {
 * HAL_FLASH_Init();    // make sure that you edited any array in "flash_config.h" labeled with @user_todo so that embedded flash memory can be initialized correctly
 * uint32_t len = HAL_FLASH_MAIN_MEM_SECTOR_5_SIZE;      // length of data to be repeatedly written
 * uint32 baseAddress = HAL_FLASH_MAIN_MEM_SECTOR_5_BASEADDR; // address of first byte of to be written
 * uint8_t data = 'A';   // data to be repeatedly written
 * HAL_FLASH_ErrStates_t error_state = HAL_FLASH_Fill(baseAddress, len, data);    // the behavior of this function fill the whole sector 5 of flash memory with character 'A', so if you examine contents of sector 5 of flash memory, it will be 'A''A''A''A''A''A''A''A''A''A'.......'A'
 *
 * if(error_state == HAL_FLASH_OK) // check for error state
 * {
 *      // data was written successfully
 * }
 * return 0;
 * }
 * @endcode
 *
 * <br><b> - HISTORY OF CHANGES - </b>
 * <table align="left" style="width:800px">
 * <tr><td> Date       </td><td> Software Version </td><td> Initials </td><td> Description </td></tr>
 * <tr><td> 30/07/2023 </td><td> 1.0.0            </td><td> AMS      </td><td> Interface Created </td></tr>
 * </table><br><br>
 * <hr>
 */
HAL_FLASH_ErrStates_t HAL_FLASH_Fill(const uint32_t argConst_u32BaseAddress, uint32_t arg_u32AddressLen, const uint8_t argConst_u8WriteData);

/**
 *  \b function                             :       HAL_FLASH_Read(const uint32_t argConst_u32BaseAddress, uint32_t arg_u32AddressLen, uint8_t *arg_pu8ReadData)
 *  \b Description                          :       this functions is used to copy data from flash memory to a given buffer given as a parameter.
 *  @param  argConst_u32BaseAddress [IN]    :       this is input parameter which is the address to read first byte of data from it.
 *                                                  possible addresses are from 0x0800 0000 to 0x080F FFFF in case of main flash memory (for base address of different sectors of main flash memory and their sizes refer to @HAL_FLASH_BASEADDR and @HAL_FLASH_SIZES in "flash_header.h" ),
 *                                                  while in case of OTP (one-time programmable memory) possible address are from 0x1FFF 7800 to  0x1FFF 79F0 (base address of different blocks of otp memory and their sizes refer to @HAL_FLASH_OPT_BLOCK_ADDR and @HAL_FLASH_OPT_BLOCK_SIZES in "flash_header.h")
 *  @param  arg_u32DataLen [IN]             :       this is input parameter which is the length of the data in bytes that is going to be read from the memory.
 *  @param  arg_pu8ReadData [OUT]           :       this is output parameter which is the address of first byte of buffer to write data into it from the flash memory.
 *  @note                                   :       None.
 *  \b PRE-CONDITION                        :       make sure to call HAL_FLASH_Init() and make sure there is no read protection on flash memory.
 *  \b POST-CONDITION                       :       it read data from flash memory and write it on your given buffer address.
 *  @return                                 :       it return one of error states indicating whether a failure or success happened during read of data(refer to @HAL_FLASH_ErrStates_t in "flash_header.h")
 *  @see                                    :       HAL_FLASH_Init()
 *  @see                                    :       HAL_FLASH_Erase(const uint16_t arg_u8SectorNum)
 *  @see                                    :       HAL_FLASH_Write(const uint32_t argConst_u32BaseAddress, uint32_t arg_u32DataLen, const uint8_t *argConst_pu8WriteData)
 *  @see                                    :       HAL_FLASH_OTPFuse(const uint16_t argConst_u32OTPBlock)
 *  @see                                    :       HAL_FLASH_Fill(const uint32_t argConst_u32BaseAddress, uint32_t arg_u32AddressLen, const uint8_t *argConst_pu8WriteData, uint32_t arg_u32DataLen)
 *  @see                                    :       HAL_FLASH_RegisterCallback(const uint8_t argConst_u8Type, const functionCallBack_t argConst_pFunctionCallBack)
 *  @see                                    :       HAL_FLASH_Config(const uint8_t argConst_u8Key, const uint8_t argConst_u8Value)
 *
 *  \b Example:
 * @code
 * #include "flash_header.h"
 * int main() {
 * HAL_FLASH_Init();    // make sure that you edited any array in "flash_config.h" labeled with @user_todo so that embedded flash memory can be initialized correctly
 * uint8_t arr[35];   // buffer that will hold data read from the flash memory
 * uint32_t len = 35;      // length of data to be read
 * uint32 baseAddress = HAL_FLASH_MAIN_MEM_SECTOR_5_BASEADDR; // address of first byte of to be read.
 * uint8_t* dataPointer = (uint8_t*)&arr;   // pointer to the first byte of buffer.
 * HAL_FLASH_ErrStates_t error_state = HAL_FLASH_Read(baseAddress, len, dataPointer);    // the behavior of this function shall write the first 35 bytes of sector 5 from flash memory into arr.
 *
 * if(error_state == HAL_FLASH_OK) // check for error state
 * {
 *      // data read written successfully
 * }
 * return 0;
 * }
 * @endcode
 *
 * <br><b> - HISTORY OF CHANGES - </b>
 * <table align="left" style="width:800px">
 * <tr><td> Date       </td><td> Software Version </td><td> Initials </td><td> Description </td></tr>
 * <tr><td> 30/07/2023 </td><td> 1.0.0            </td><td> AMS      </td><td> Interface Created </td></tr>
 * </table><br><br>
 * <hr>
 */
HAL_FLASH_ErrStates_t HAL_FLASH_Read(const uint32_t argConst_u32BaseAddress, uint32_t arg_u32DataLen, uint8_t *arg_pu8ReadData);

/**
 *  \b function                             :       HAL_FLASH_Config(const uint8_t argConst_u8Key, const uint8_t argConst_u8Value)
 *  \b Description                          :       this functions is used to change the behavior of the functions by changing some key configuration values.
 *  @param  argConst_u8Key [IN]             :       this is input parameter which is key of the parameter to be changed, for possible values refer to @HAL_FLASH_ConfigKeys_t in "flash_header.h".
 *  @param  argConst_u8Value [IN]           :       this is input parameter which value of configuration to be assigned to the corresponding selected key. for possible values, every key has its set of values, refer to @HAL_FLASH_ConfigKeys_t in "flash_header.h" as the possible values are written as comments for every key.
 *  @note                                   :       None.
 *  \b PRE-CONDITION                        :       None.
 *  \b POST-CONDITION                       :       it changes the behavior of some functions of the interface.
 *  @return                                 :       it return one of error states indicating whether a failure or success happened during the edit of configuration (refer to @HAL_FLASH_ErrStates_t in "flash_header.h")
 *  @see                                    :       HAL_FLASH_Init()
 *  @see                                    :       HAL_FLASH_Erase(const uint16_t arg_u8SectorNum)
 *  @see                                    :       HAL_FLASH_Write(const uint32_t argConst_u32BaseAddress, uint32_t arg_u32DataLen, const uint8_t *argConst_pu8WriteData)
 *  @see                                    :       HAL_FLASH_OTPFuse(const uint16_t argConst_u32OTPBlock)
 *  @see                                    :       HAL_FLASH_Fill(const uint32_t argConst_u32BaseAddress, uint32_t arg_u32AddressLen, const uint8_t *argConst_pu8WriteData, uint32_t arg_u32DataLen)
 *  @see                                    :       HAL_FLASH_Read(const uint32_t argConst_u32BaseAddress, uint32_t arg_u32AddressLen, uint8_t *arg_pu8ReadData)
 *  @see                                    :       HAL_FLASH_RegisterCallback(const uint8_t argConst_u8Type, const functionCallBack_t argConst_pFunctionCallBack)
 *
 *  \b Example:
 * @code
 * #include "flash_header.h"
 * int main() {
 * HAL_FLASH_Init();    // make sure that you edited any array in "flash_config.h" labeled with @user_todo so that embedded flash memory can be initialized correctly
 * HAL_FLASH_ErrStates_t error_state;
 * error_state = HAL_FLASH_Config(HAL_FLASH_CONFIG_KEY_OPERATION_TYPE, HAL_FLASH_CONFIG_VAL_OPERATION_TYPE_INTERRUPT);  // make flash interrupt based so there is no blocking on any hardware flag
 * if(error_state == HAL_FLASH_OK) // check for error state
 * {
 *      uint8_t arr[] = "Hello world";   // data to be written
 *      uint32_t len = strlen(arr);      // length of data to be written
 *      uint32 baseAddress = HAL_FLASH_MAIN_MEM_SECTOR_5_BASEADDR + 0x024f; // address of first byte of to be stored data, store data in sector 5 of flash memory with offset 0x024f from base address of sector 5
 *      uint8_t* dataPointer = (uint8_t*)&arr;   // pointer to the first byte of data to be written
 *      HAL_FLASH_ErrStates_t error_state = HAL_FLASH_Write(baseAddress, len, dataPointer);    // the behavior of this function shall write "Hello world" to flash memory where letter 'H' will be stored in the address 0x0802 024F and the later letter follows 'H' in the addresses so 'e' will be stored in 0x0802 0250 and so on
 *
 *      if(error_state == HAL_FLASH_OK) // check for error state
 *      {
 *          // data was scheduled to be written successfully (if you want to know when the data was written successfully then you shall register a callback by calling the function HAL_FLASH_Config(const uint8_t argConst_u8Key, const uint8_t argConst_u8Value))
 *      }
 * }

 * return 0;
 * }
 * @endcode
 *
 * <br><b> - HISTORY OF CHANGES - </b>
 * <table align="left" style="width:800px">
 * <tr><td> Date       </td><td> Software Version </td><td> Initials </td><td> Description </td></tr>
 * <tr><td> 30/07/2023 </td><td> 1.0.0            </td><td> AMS      </td><td> Interface Created </td></tr>
 * </table><br><br>
 * <hr>
 */
HAL_FLASH_ErrStates_t HAL_FLASH_Config(const uint8_t argConst_u8Key, const uint8_t argConst_u8Value);

/**
 *  \b function                             :       HAL_FLASH_RegisterCallback(const uint8_t argConst_u8CallBackType, const functionCallBack_t argConst_pFunctionCallBack)
 *  \b Description                          :       this functions is used to register a callback function to be executed from user code when an interrupt happens.
 *  @param  argConst_u8CallBackType [IN]    :       this is input parameter indicates which interrupt handler to attach this function to, for possible values, refer to  @HAL_FLASH_CallbacksTypes_t in "flash_header.h"
 *  @param  argConst_pFunctionCallBack [IN] :       this is the function to be called when the specified action interrupt happens.
 *  @note                                   :       None.
 *  \b PRE-CONDITION                        :       make sure to call HAL_FLASH_Init() and make sure the address of function is valid address and the behavior of flash memory is interrupt based from configuration or using HAL_FLASH_Config(const uint8_t argConst_u8Key, const uint8_t argConst_u8Value).
 *  \b POST-CONDITION                       :       assign the given function to a specific action.
 *  @return                                 :       it return one of error states indicating whether a failure or success happened during the registration of callbacks (refer to @HAL_FLASH_ErrStates_t in "flash_header.h")
 *  @see                                    :       HAL_FLASH_Init()
 *  @see                                    :       HAL_FLASH_Erase(const uint16_t arg_u8SectorNum)
 *  @see                                    :       HAL_FLASH_Write(const uint32_t argConst_u32BaseAddress, uint32_t arg_u32DataLen, const uint8_t *argConst_pu8WriteData)
 *  @see                                    :       HAL_FLASH_OTPFuse(const uint16_t argConst_u32OTPBlock)
 *  @see                                    :       HAL_FLASH_Fill(const uint32_t argConst_u32BaseAddress, uint32_t arg_u32AddressLen, const uint8_t *argConst_pu8WriteData, uint32_t arg_u32DataLen)
 *  @see                                    :       HAL_FLASH_Read(const uint32_t argConst_u32BaseAddress, uint32_t arg_u32AddressLen, uint8_t *arg_pu8ReadData)
 *  @see                                    :       HAL_FLASH_RegisterCallback(const uint8_t argConst_u8Type, const functionCallBack_t argConst_pFunctionCallBack)
 *
 *  \b Example:
 * @code
 * #include "flash_header.h"
 *
 * int code = 0;
 * void successHandler(void)    // this function is to be called when flash memory operation success
 * {
 *  code = 1;
 * }
 *
 * void failureHandler(void)    // this function is to be called when flash memory operation fails
 * {
 *  code = 0;
 * }
 * int main() {
 * HAL_FLASH_Init();    // make sure that you edited any array in "flash_config.h" labeled with @user_todo so that embedded flash memory can be initialized correctly
 * HAL_FLASH_ErrStates_t error_state;
 * error_state = HAL_FLASH_Config(HAL_FLASH_CONFIG_KEY_OPERATION_TYPE, HAL_FLASH_CONFIG_VAL_OPERATION_TYPE_INTERRUPT);  // make flash interrupt based so there is no blocking on any hardware flag
 * if(error_state == HAL_FLASH_OK) // check for error state
 * {
 *      HAL_FLASH_RegisterCallback(HAL_FLASH_CALLBACK_TYPE_SUCCESS, successHandler);  // after the end of any success operation like writing to flash, function successHandler() will be called (don't forget to check for error_state)
 *      HAL_FLASH_RegisterCallback(HAL_FLASH_CALLBACK_TYPE_ERR_WRITE_PROTECTION | HAL_FLASH_CALLBACK_TYPE_ERR_PROGRAMMING_SEQUENCE | HAL_FLASH_CALLBACK_TYPE_ERR_PROGRAMMING_PARALLELISM | HAL_FLASH_CALLBACK_TYPE_ERR_PROGRAMMING_ALIGNMENT |  HAL_FLASH_CALLBACK_TYPE_ERR_OPERATION, failureHandler);  // if any type of error occurred, function failureHandler() will be called (don't forget to check for error_state)
 *
 *      uint8_t arr[] = "Hello world";   // data to be written
 *      uint32_t len = strlen(arr);      // length of data to be written
 *      uint32 baseAddress = HAL_FLASH_MAIN_MEM_SECTOR_5_BASEADDR + 0x024f; // address of first byte of to be stored data, store data in sector 5 of flash memory with offset 0x024f from base address of sector 5
 *      uint8_t* dataPointer = (uint8_t*)&arr;   // pointer to the first byte of data to be written
 *      error_state = HAL_FLASH_Write(baseAddress, len, dataPointer);    // the behavior of this function shall schedule writing "Hello world" to flash memory where letter 'H' will be stored in the address 0x0802 024F and the later letter follows 'H' in the addresses so 'e' will be stored in 0x0802 0250 and so on (don't' forget to check for error_state)
 *
 * }
 *
 * return 0;
 * }
 * @endcode
 *
 * <br><b> - HISTORY OF CHANGES - </b>
 * <table align="left" style="width:800px">
 * <tr><td> Date       </td><td> Software Version </td><td> Initials </td><td> Description </td></tr>
 * <tr><td> 30/07/2023 </td><td> 1.0.0            </td><td> AMS      </td><td> Interface Created </td></tr>
 * </table><br><br>
 * <hr>
 */
HAL_FLASH_ErrStates_t HAL_FLASH_RegisterCallback(const uint8_t argConst_u8CallBackType, const functionCallBack_t argConst_pFunctionCallBack);

/*** End of File **************************************************************/
#endif /*HAL_FLASH_HEADER_H_*/