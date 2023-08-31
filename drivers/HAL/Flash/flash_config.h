/**
 * --------------------------------------------------------------------------------------------------------------------------------------
 * |    @title          :   Flash                                                                                                       |
 * |    @file           :   Flash_config.h                                                                                              |
 * |    @author         :   Abdelrahman Mohamed Salem                                                                                   |
 * |    @origin_date    :   19/07/2023                                                                                                  |
 * |    @version        :   1.0.0                                                                                                       |
 * |    @tool_chain     :   GNU Tools for STM32                                                                                         |
 * |    @compiler       :   GCC                                                                                                         |
 * |    @C_standard     :   ISO C99 (-std=c99)                                                                                          |
 * |    @target         :   stm32f407VGTX                                                                                               |
 * |    @notes          :   anything labeled with @user_todo, the user of the code shall edit the related configuration lines           |
 * |    @license        :   MIT License                                                                                                 |
 * |    @brief          :   this is the configuration file that will contains initial configurations for your flash peripheral and      |
 *                          you must edit this file in order to change initial configurations                                           |
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

#ifndef HAL_FLASH_CONFIG_H_
#define HAL_FLASH_CONFIG_H_

/******************************************************************************
 * Includes
 *******************************************************************************/

/**
 * @reason: it contains standard definition for integers
 */
#include "../../lib/stdint.h"

/**
 * @reason: it holds the definitions for (ENABLED and DISABLED) and (LOCKED and UNLOCKED)
 */
#include "../../lib/constants.h"

/**
 * @reason: contains definition for @HAL_FLASH_Sectors_t
 */
#include "flash_header.h"

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
 * Tables
 *******************************************************************************/

/**
 *  @table: HAL_FLASH_TABLE_WAIT_STATES
 *  @brief: Number of wait states to be configured according to CPU clock (HCLK) frequency
 *  +------------------------+------------------+------------------+------------------+-------------------+
 *  |                        |                                HCLK (MHz)                                  |
 *  |   Wait states (WS)     +------------------+------------------+------------------+-------------------+
 *  |      (LATENCY)         |  Voltage range   |   Voltage range  |  Voltage range   |    Voltage range  |
 *  |                        |  2.7 V - 3.6 V   |   2.4 V - 2.7 V  |  2.1 V - 2.4 V   |   1.8 V - 2.1 V   |
 *  |                        |                  |                  |                  |   Prefetch OFF    |
 *  +------------------------+------------------+------------------+------------------+-------------------+
 *  | HAL_FLASH_WAIT_STATE_0 |  0 < HCLK ≤ 30   |  0 < HCLK ≤ 24   |  0 < HCLK ≤ 22   |   0 < HCLK ≤ 20   |
 *  | HAL_FLASH_WAIT_STATE_1 |  30 < HCLK ≤ 60  |  24 < HCLK ≤ 48  |  22 < HCLK ≤ 44  |   20 <HCLK ≤ 40   |
 *  | HAL_FLASH_WAIT_STATE_2 |  60 < HCLK ≤ 90  |  48 < HCLK ≤ 72  |  44 < HCLK ≤ 66  |   40 < HCLK ≤ 60  |
 *  | HAL_FLASH_WAIT_STATE_3 | 90 < HCLK ≤ 120  |  72 < HCLK ≤ 96  |  66 < HCLK ≤ 88  |   60 < HCLK ≤ 80  |
 *  | HAL_FLASH_WAIT_STATE_4 | 120 < HCLK ≤ 150 | 96 < HCLK ≤ 120  | 88 < HCLK ≤ 110  |  80 < HCLK ≤ 100  |
 *  | HAL_FLASH_WAIT_STATE_5 | 150 < HCLK ≤ 168 | 120 < HCLK ≤ 144 | 110 < HCLK ≤ 132 |  100 < HCLK ≤ 120 |
 *  | HAL_FLASH_WAIT_STATE_6 |       ---        | 144 < HCLK ≤ 168 | 132 < HCLK ≤ 154 |  132 < HCLK ≤ 154 |
 *  | HAL_FLASH_WAIT_STATE_7 |       ---        |       ---        | 154 < HCLK ≤ 168 |  140 < HCLK ≤ 160 |
 *  +------------------------+------------------+------------------+------------------+-------------------+
 */

/**
 *  @table: HAL_FLASH_TABLE_PROGRAM_SIZES
 *  @brief: program size to be configured according to Voltage range
 *
 *  +------------------+----------------------------+----------------------------+----------------------------+---------------------------+---------------------------+
 *  |       ---        | Voltage range 2.7 - 3.6 V  |       Voltage range        |       Voltage range        |       Voltage range       |       Voltage range       |
 *  |                  |      with External VPP     |        2.7 - 3.6 V         |        2.4 - 2.7 V         |        2.1 - 2.4 V        |       1.8 V - 2.1 V       |
 *  +------------------+----------------------------+----------------------------+----------------------------+---------------------------+---------------------------+
 *  | ProgramSize      | HAL_FLASH_PROGRAM_SIZE_X64 | HAL_FLASH_PROGRAM_SIZE_X32 |                   HAL_FLASH_PROGRAM_SIZE_X16              | HAL_FLASH_PROGRAM_SIZE_X8 |
 *  +------------------+----------------------------+----------------------------+----------------------------+---------------------------+---------------------------+
 */

/**
 * @table: HAL_FLASH_TABLE_BROWNOUT_LEVELS
 * @brief: this table contains all needed information for correctly configuring brownout level which is just a feature that reset the MCU when its supply voltage reaches a specific range
 *
 *
 *  +-------------------------------+--------------+------+------+------+------+
 *  |                               |  Conditions  | Min  | Typ  | Max  | Unit |
 *  +-------------------------------+--------------+------+------+------+------+
 *  | HAL_FLASH_BROWN_RESET_LVL_OFF | Falling edge | 1.60 | 1.68 | 1.76 |   V  |
 *  |                               | Rising edge  | 1.64 | 1.72 | 1.80 |   V  |
 *  +-------------------------------+--------------+------+------+------+------+
 *  |  HAL_FLASH_BROWN_RESET_LVL_1  | Falling edge | 2.13 | 2.19 | 2.24 |   V  |
 *  |                               | Rising edge  | 2.23 | 2.29 | 2.33 |   V  |
 *  +-------------------------------+--------------+------+------+------+------+
 *  |  HAL_FLASH_BROWN_RESET_LVL_2  | Falling edge | 2.44 | 2.50 | 2.56 |   V  |
 *  |                               | Rising edge  | 2.53 | 2.59 | 2.63 |   V  |
 *  +-------------------------------+--------------+------+------+------+------+
 *  |  HAL_FLASH_BROWN_RESET_LVL_3  | Falling edge | 2.75 | 2.83 | 2.88 |   V  |
 *  |                               | Rising edge  | 2.85 | 2.92 | 2.97 |   V  |
 *  +-------------------------------+--------------+------+------+------+------+
 */

/******************************************************************************
 * Typedefs
 *******************************************************************************/

/**
 * @enum: HAL_FLASH_WaitStates_t
 * @brief: this are the possible value for wait states (ratio of the CPU clock period to the Flash memory access time) that are programmed into FLASH_ACR register
 * @note: refer to @HAL_FLASH_TABLE_WAIT_STATES in file "flash_config.h" to get the suitable value
 */
typedef enum
{
    HAL_FLASH_WAIT_STATE_0 = 0, /**< ratio of the CPU clock period to the Flash memory access time = 0, in other words (0 WS (1 CPU cycle))*/
    HAL_FLASH_WAIT_STATE_1 = 1, /**< ratio of the CPU clock period to the Flash memory access time = 1, in other words (1 WS (2 CPU cycles))*/
    HAL_FLASH_WAIT_STATE_2 = 2, /**< ratio of the CPU clock period to the Flash memory access time = 2, in other words (2 WS (3 CPU cycles))*/
    HAL_FLASH_WAIT_STATE_3 = 3, /**< ratio of the CPU clock period to the Flash memory access time = 3, in other words (3 WS (4 CPU cycles))*/
    HAL_FLASH_WAIT_STATE_4 = 4, /**< ratio of the CPU clock period to the Flash memory access time = 4, in other words (4 WS (5 CPU cycles))*/
    HAL_FLASH_WAIT_STATE_5 = 5, /**< ratio of the CPU clock period to the Flash memory access time = 5, in other words (5 WS (6 CPU cycles))*/
    HAL_FLASH_WAIT_STATE_6 = 6, /**< ratio of the CPU clock period to the Flash memory access time = 6, in other words (6 WS (7 CPU cycles))*/
    HAL_FLASH_WAIT_STATE_7 = 7, /**< ratio of the CPU clock period to the Flash memory access time = 7, in other words (7 WS (8 CPU cycles))*/
    HAL_FLASH_MAX_WAIT_STATE,   /**< that value should never be used and it's only used by the implementation code for verifying the input*/
} HAL_FLASH_WaitStates_t;

/**
 * @enum: HAL_FLASH_ProgramSizeAccess_t
 * @brief: this are the possible value for ProgramSize given in configuration which allows you to setup preferred size of access on bytes on flash memory whether it's (byte, half-word, word, double-word)
 * @note: refer to @HAL_FLASH_TABLE_PROGRAM_SIZES in file "flash_config.h" to get the suitable value
 */
typedef enum
{
    HAL_FLASH_PROGRAM_SIZE_X8 = 0,  /**< Byte access*/
    HAL_FLASH_PROGRAM_SIZE_X16 = 1, /**< Half-word access*/
    HAL_FLASH_PROGRAM_SIZE_X32 = 2, /**< Word access*/
    HAL_FLASH_PROGRAM_SIZE_X64 = 3, /**< Double word access */
    HAL_FLASH_MAX_PROGRAM_SIZE,     /**< that value should never be used and it's only used by the implementation code for verifying the input*/
} HAL_FLASH_ProgramSizeAccess_t;

/**
 * @enum: HAL_FLASH_READ_PROTECT_LVL
 * @brief: this holds the possible levels for read protection of the flash memory
 */
typedef enum
{
    HAL_FLASH_READ_PROTECT_LVL_0 = 0xAA, /**< read protection not active, all read/write operations (if no write protection is set) from/to the Flash memory or the backup SRAM are possible in all boot configurations*/
    HAL_FLASH_READ_PROTECT_LVL_1 = 0x00, /**< read protection of memories active, No access to Flash memory or backup SRAM while debugging or booting from RAM or system memory*/
    HAL_FLASH_READ_PROTECT_LVL_2 = 0xCC, /**< chip read protection active, IMPORTANT NOTE (SETTING A READ PROTECTION TO LEVEL 2 PROTECTION IS IRREVERSIBLE OPERATION FOR THE CHIP EVEN RESET CAN't FIX IT, SO BE VERY CAREFUL WITH THAT), Booting from RAM or system memory bootloader is no more allowed, All protections provided by Level 1 are active,  User option bytes can no longer be changed. */
    HAL_FLASH_MAX_READ_PROTECT_LVL,      /**< that value should never be used and it's only used by the implementation code for verifying the input*/
} HAL_FLASH_ReadProtectLevel_t;

/**
 * @enum: HAL_FLASH_BROWN_RESET_LVL
 * @brief: this holds the possible levels for configuring brownout reset (brownout is just an electric characteristic that makes MCU resets once its VDD has a value in a specific range, these ranges are called levels)
 * @note: refer to @HAL_FLASH_TABLE_BROWNOUT_LEVELS in file "flash_config.h" to get the suitable value
 */
typedef enum
{
    HAL_FLASH_BROWN_RESET_LVL_3 = 0,   /**< brownout threshold level 3, */
    HAL_FLASH_BROWN_RESET_LVL_2 = 1,   /**< brownout threshold level 3, */
    HAL_FLASH_BROWN_RESET_LVL_1 = 2,   /**< brownout threshold level 3, */
    HAL_FLASH_BROWN_RESET_LVL_OFF = 3, /**< brownout threshold level 3, */
    HAL_FLASH_MAX_BROWN_RESET_LVL,     /**< that value should never be used and it's only used by the implementation code for verifying the input*/
} HAL_FLASH_BROWN_RESET_LVL;

/**
 * @enum: HAL_FLASH_INDPEND_WATCH_DOG_TYPE
 * @brief: this holds the possible types of independent watchdog
 * @note: When changing the WDG mode from hardware to software or from software to hardware, a system reset is required to make the change effective
 */
typedef enum
{
    HAL_FLASH_INDPEND_WATCH_DOG_TYPE_HW = 0, /**< Hardware independent watchdog*/
    HAL_FLASH_INDPEND_WATCH_DOG_TYPE_SW = 1, /**< Software independent watchdog*/
    HAL_FLASH_MAX_INDPEND_WATCH_DOG_TYPE,    /**< that value should never be used and it's only used by the implementation code for verifying the input*/
} HAL_FLASH_INDPEND_WATCH_DOG_TYPE;

/**
 * @struct: HAL_FLASH_Config_t
 * @brief: this struct holds all information needed for the initialization of the flash memory
 */
typedef struct
{
    uint8_t DataCacheEnabled;        /**< for possible values refer to @LIB_CONSTANTs_DriverStates_t in the file called "constants.h", @details: If some literal pools are frequently used, then it's recommended to enable the data cache memory where data size is limited to 8 rows of 128 bits*/
    uint8_t InstructionCacheEnabled; /**< for possible values refer to @LIB_CONSTANTs_DriverStates_t in the file called "constants.h", @details: To limit the time lost due to jumps, it is possible to retain 64 lines of 128 bits by enabling instruction cache memory, Once all the instruction cache memory lines have been filled, the LRU (least recently used) policy is used to determine the line to replace in the instruction memory cache*/
    uint8_t PrefetchEnabled;         /**< for possible values refer to @LIB_CONSTANTS_DriverStates_t in the file called "constants.h", @details: This feature is useful if at least one wait state is needed to access the Flash memory as it makes flash keep on reading 128 bits with no stop, for better understanding, refer to "Figure 5. Sequential 32-bit instruction execution" in the technical reference manual  */
    uint8_t WaitStates;              /**< for possible values refer to @HAL_Flash_WaitStates_t in the file called "flash_config.h", @details: To correctly read data from Flash memory, the number of wait states (LATENCY) must be correctly programmed. @note: The prefetch buffer must be disabled when the supply voltage is below 2.1 V.*/
    uint8_t LockConfiguration;       /**< for possible values refer to @LIB_CONSTANTS_LockStates_t in the file called "constants.h", @details: this is used to whether to lock all of your configuration so no one can modify your configuration unless a specific sequence has been followed*/
    uint8_t InterruptsEnabled;       /**< for possible values refer to @LIB_CONSTANTS_DriverStates_t in the file called "constants.h", @details: used to determine whether to enable interrupts due to errors/operations concerning flash memory, @note: you shall register a callback function for interrupt handlers */
    uint8_t ProgramSize;             /**< for possible values refer to @HAL_Flash_ProgramSizeAccess_t in the file called "flash_config.h", @details: it's used to determine the number of bytes to be programmed each time a write operation occurs to the Flash memory. The erase time depends on PSIZE programmed value. @note: It must be correctly configured or it can cause error*/
    uint8_t ReadProtectionLevel;     /**< for possible values refer to @HAL_FLASH_ReadProtectLevel_t in the file called "flash_config.h", @details: The user area in the Flash memory can be protected against read operations by an entrusted code by enabling a specific level of read protection on the flash., @note: When the protection level is increased (0->1, 1->2, 0->2) there is no mass erase otherwise a mass erase is activated*/
} HAL_FLASH_Config_t;

/**
 * @struct: HAL_FLASH_SectorsConfig_t
 * @brief: this struct holds all information needed for the initialization of individual sectors of the flash memory
 */
typedef struct
{
    uint16_t SectorNumber;   /**< for possible values refer to @Hal_FLASH_Sectors_t in the file called "flash_header.h", @details: this holds which sector of flash to be configured*/
    uint8_t WriteProtection; /**< for possible values refer to @LIB_CONSTANTS_DriverStates_t in the file called "constants.h", @details: used to determine whether to enable Write protection or not on a selected sector of memory*/
} HAL_FLASH_SectorsConfig_t;

/**
 * @struct: HAL_FLASH_MiscellaneousConfig_t
 * @brief: for some reasons, the configuration registers of flash has some effect on other different peripherals, so configuration for these unrelated peripherals are gathered here
 */
typedef struct
{
    uint8_t ResetOnStandBy;          /**< for possible values refer to @LIB_CONSTANTS_DriverStates_t in the file called "constants.h", @details: enable or disable Reset generation when entering the Standby mode*/
    uint8_t ResetOnStop;             /**< for possible values refer to @LIB_CONSTANTS_DriverStates_t in the file called "constants.h", @details: enable or disable Reset generation when entering the Stop mode*/
    uint8_t IndependentWatchDogType; /**< for possible values refer to @HAL_FLASH_INDPEND_WATCH_DOG_TYPE in the file called "flash_config.h", @details: choose between Hardware or software independent watchdog, @note:  When changing the WDG mode from hardware to software or from software to hardware, a system reset is required to make the change effective.*/
    uint8_t BrownoutResetLevel;      /**< for possible values refer to @HAL_FLASH_BROWN_RESET_LVL in the file called "flash_config.h", @details: During power on, the Brownout reset (BOR) keeps the device under reset until the supply voltage reaches the specified threshold*/
} HAL_FLASH_MiscellaneousConfig_t;

/******************************************************************************
 * Variables
 *******************************************************************************/

/**
 * @user_todo: user shall edit this array with his needed configurations
 * @brief: it represents the configurations for the embedded flash memory as a whole
 */
const HAL_FLASH_Config_t globalConstArr_FlashConfig_t[] = {
    {
        .DataCacheEnabled = LIB_CONSTANTS_ENABLED,
        .InstructionCacheEnabled = LIB_CONSTANTS_ENABLED,
        .PrefetchEnabled = LIB_CONSTANTS_ENABLED,
        .WaitStates = HAL_FLASH_WAIT_STATE_2, // HAL_FLASH_WAIT_STATE_0,
        .LockConfiguration = LIB_CONSTANTS_UNLOCKED,
        .InterruptsEnabled = LIB_CONSTANTS_DISABLED,
        .ProgramSize = HAL_FLASH_PROGRAM_SIZE_X32,
        .ReadProtectionLevel = HAL_FLASH_READ_PROTECT_LVL_0,
    }

};

/**
 * @user_todo: user shall edit this array with his needed configurations
 * @brief: it represents the configurations for individual sectors of the embedded flash memory
 */
const HAL_FLASH_SectorsConfig_t globalConstArr_SectorsConfig_t[] = {

    {.SectorNumber = HAL_FLASH_MAIN_MEM_SECTOR_0, .WriteProtection = LIB_CONSTANTS_DISABLED},
    {.SectorNumber = HAL_FLASH_MAIN_MEM_SECTOR_1, .WriteProtection = LIB_CONSTANTS_DISABLED},
    {.SectorNumber = HAL_FLASH_MAIN_MEM_SECTOR_2, .WriteProtection = LIB_CONSTANTS_DISABLED},
    {.SectorNumber = HAL_FLASH_MAIN_MEM_SECTOR_3, .WriteProtection = LIB_CONSTANTS_DISABLED},
    {.SectorNumber = HAL_FLASH_MAIN_MEM_SECTOR_4, .WriteProtection = LIB_CONSTANTS_DISABLED},
    {.SectorNumber = HAL_FLASH_MAIN_MEM_SECTOR_5, .WriteProtection = LIB_CONSTANTS_DISABLED},
    {.SectorNumber = HAL_FLASH_MAIN_MEM_SECTOR_6, .WriteProtection = LIB_CONSTANTS_DISABLED},
    {.SectorNumber = HAL_FLASH_MAIN_MEM_SECTOR_7, .WriteProtection = LIB_CONSTANTS_DISABLED},
    {.SectorNumber = HAL_FLASH_MAIN_MEM_SECTOR_8, .WriteProtection = LIB_CONSTANTS_DISABLED},
    {.SectorNumber = HAL_FLASH_MAIN_MEM_SECTOR_9, .WriteProtection = LIB_CONSTANTS_DISABLED},
    {.SectorNumber = HAL_FLASH_MAIN_MEM_SECTOR_10, .WriteProtection = LIB_CONSTANTS_DISABLED},
    {.SectorNumber = HAL_FLASH_MAIN_MEM_SECTOR_11, .WriteProtection = LIB_CONSTANTS_DISABLED},
};

/**
 * @user_todo: user shall edit this array with his needed configurations
 * @brief: it represents the configurations for unrelated peripherals
 */
const HAL_FLASH_MiscellaneousConfig_t globalConstArr_MiscellaneousConfig_t[] = {
    {
        .ResetOnStandBy = LIB_CONSTANTS_DISABLED,
        .ResetOnStop = LIB_CONSTANTS_DISABLED,
        .IndependentWatchDogType = HAL_FLASH_INDPEND_WATCH_DOG_TYPE_SW,
        .BrownoutResetLevel = HAL_FLASH_BROWN_RESET_LVL_OFF,
    }

};

/******************************************************************************
 * Function Prototypes
 *******************************************************************************/

/*** End of File **************************************************************/
#endif /*HAL_FLASH_CONFIG_H_*/
