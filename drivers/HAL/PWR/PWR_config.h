/**
 * --------------------------------------------------------------------------------------------------------------------------------------
 * |    @title          :   power controller                                                                                            |
 * |    @file           :   PWR_config.h                                                                                                |
 * |    @author         :   Abdelrahman Mohamed Salem                                                                                   |
 * |    @origin_date    :   11/08/2023                                                                                                  |
 * |    @version        :   1.0.0                                                                                                       |
 * |    @tool_chain     :   GNU Tools for STM32                                                                                         |
 * |    @compiler       :   GCC                                                                                                         |
 * |    @C_standard     :   ISO C99 (-std=c99)                                                                                          |
 * |    @target         :   stm32f407VGTX                                                                                               |
 * |    @notes          :   None                                                                                                        |
 * |    @license        :   MIT License                                                                                                 |
 * |    @brief          :   this header file contains configurations related to the Power Controller (PWR)                              |                                                               |
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

#ifndef HAL_PWR_CONFIG_H_
#define HAL_PWR_CONFIG_H_

/******************************************************************************
 * Includes
 *******************************************************************************/

/**
 * @reason: it contains standard definition for integers
 */
#include "../../lib/stdint.h"

/**
 * @reason: it holds the definitions for (ENABLED and DISABLED)
 */
#include "../../lib/constants.h"

/**
 * @reason: hold possible values for SleepEnterMethod
 */
#include "PWR_header.h"

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

/******************************************************************************
 * Typedefs
 *******************************************************************************/

/**
 * @enum: HAL_PWR_HCLK_MAX_FREQ_t
 * @brief: holds scaling configuration for voltage regulator ouput, higher max speed means higher power consumption
 */
typedef enum
{
    HAL_PWR_HCLK_144_MHZ = 0, /**< this means the maximum reachable Internal AHB clock frequency = 144 MHZ but it means lower power consumption*/
    HAL_PWR_HCLK_168_MHZ = 1, /**< this means the maximum reachable Internal AHB clock frequency = 168 MHZ but it means higher power consumption*/
    HAL_PWR_MAX_HCLK,         /**< this value shall never be used by the user, it's only used by the implementation code to verify the input*/
} HAL_PWR_HCLK_MAX_FREQ_t;

/**
 *  @enum: HAL_PWR_PVDLevelSelection_t
 * @brief: used to select voltage threshold of VDD upon it generates interrupt if level is higher or lower than the selected level
 */
typedef enum
{
    HAL_PWR_PVD_2_0_V = 0, /**< voltage threshold is set to 2.0 Volt*/
    HAL_PWR_PVD_2_1_V = 1, /**< voltage threshold is set to 2.1 Volt*/
    HAL_PWR_PVD_2_3_V = 2, /**< voltage threshold is set to 2.3 Volt*/
    HAL_PWR_PVD_2_5_V = 3, /**< voltage threshold is set to 2.5 Volt*/
    HAL_PWR_PVD_2_6_V = 4, /**< voltage threshold is set to 2.6 Volt*/
    HAL_PWR_PVD_2_7_V = 5, /**< voltage threshold is set to 2.7 Volt*/
    HAL_PWR_PVD_2_8_V = 6, /**< voltage threshold is set to 2.8 Volt*/
    HAL_PWR_PVD_2_9_V = 7, /**< voltage threshold is set to 2.9 Volt*/
    HAL_PWR_MAX_PVD_LEVEL, /**< this value shall never be used by the user, it's only used by the implementation code to verify the input*/
} HAL_PWR_PVDLevelSelection_t;

/**
 * @struct: HAL_PWR_generalConfig_t
 * @brief: for some reasons, the configuration registers of flash has some effect on other different peripherals, so configuration for these unrelated peripherals are gathered here
 */
typedef struct
{
    uint8_t MaxHCLKFreq;              /**< for possible values refer to @HAL_PWR_HCLK_MAX_FREQ_t in "PWR_config.h", this only indicates the maximum reachable clock frequency when the device does not operate at the maximum frequency. it achieves a trade-off between performance and power consumption.*/
    uint8_t FlashPowerDown;           /**< for possible values refer to @LIB_CONSTANTS_DriverStates_t in "constants.h", used to control whether flash memory enters power-down mode when the device enters Stop mode. This allows to achieve a lower consumption in stop mode but a longer restart time.*/
    uint8_t PVDEnable;                /**< for possible values refer to @LIB_CONSTANTS_DriverStates_t in "constants.h", Power voltage detector enable */
    uint8_t PVDLevel;                 /**< for possible values refer to @HAL_PWR_PVDLevelSelection_t in "PWR_config.h", only used if PVDEnable is enabled.  select the voltage threshold detected by the Power Voltage Detector */
    uint8_t BackUpEnable;             /**< for possible values refer to @LIB_CONSTANTS_DriverStates_t in "constants.h", this is used to enable backup SRAM to maintain its content in V_bat mode*/
    uint8_t WakeUpPinEnable;          /**< for possible values refer to @LIB_CONSTANTS_DriverStates_t in "constants.h", used to configure wake up to be used only to wake up MCU from standby mode*/
    uint8_t SleepEnterMethod;         /**< for possible values refer to @HAL_PWR_VAL_SleepMethod_t in "PWR_header.h", it indicates how the MCU shall enter the sleep mode. */
    uint8_t SleepOnExitFromISREnable; /**< for possible values refer to @LIB_CONSTANTS_DriverStates_t in "constants.h", it indicates whether to enable or disable sleeping on exit from ISR*/
} HAL_PWR_generalConfig_t;

/******************************************************************************
 * Variables
 *******************************************************************************/

/**
 * @user_todo: user shall edit this array with his needed configurations
 * @brief: it represents the configurations for anything related to power consumption, these are the default values
 */
const HAL_PWR_generalConfig_t globalConstArr_PWRConfig_t[] = {
    {
        .MaxHCLKFreq = HAL_PWR_HCLK_168_MHZ,
        .FlashPowerDown = LIB_CONSTANTS_ENABLED,
        .PVDEnable = LIB_CONSTANTS_DISABLED,
        .PVDLevel = HAL_PWR_PVD_2_0_V,
        .BackUpEnable = LIB_CONSTANTS_ENABLED,
        .SleepEnterMethod = HAL_PWR_VAL_SLEEP_METHOD_WFE,
        .SleepOnExitFromISREnable = LIB_CONSTANTS_ENABLED,
    }

};

/******************************************************************************
 * Function Prototypes
 *******************************************************************************/

/*** End of File **************************************************************/
#endif /*HAL_PWR_CONFIG_H_*/