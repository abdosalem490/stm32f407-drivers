/**
 * --------------------------------------------------------------------------------------------------------------------------------------
 * |    @title          :   Reset and clock control                                                                                     |
 * |    @file           :   RCC_header.h                                                                                                |
 * |    @author         :   Abdelrahman Mohamed Salem                                                                                   |
 * |    @origin_date    :   26/08/2023                                                                                                  |
 * |    @version        :   1.0.0                                                                                                       |
 * |    @tool_chain     :   GNU Tools for STM32                                                                                         |
 * |    @compiler       :   GCC                                                                                                         |
 * |    @C_standard     :   ISO C99 (-std=c99)                                                                                          |
 * |    @target         :   stm32f407VGTX                                                                                               |
 * |    @notes          :   None                                                                                                        |
 * |    @license        :   MIT License                                                                                                 |
 * |    @brief          :   this header file contains functions implementations regarding the Reset and clock control                   |
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
 * |    26/08/2023      1.0.0           Abdelrahman Mohamed Salem       Interface Created.                                              |
 * --------------------------------------------------------------------------------------------------------------------------------------
 */

/******************************************************************************
 * Includes
 *******************************************************************************/
/**
 * @reason: contains standard definitions for standard integers
 */
#include "../../lib/stdint.h"

/**
 * @reason: contains definition for NULL
 */
#include "../../lib/common.h"

/**
 * @reason: contains constants common values
 */
#include "../../lib/constants.h"

/**
 * @reason: contains useful functions that deals with bit level math
 */
#include "../../Lib/math_btt.h"

/**
 * @reason: contains all initial user configurations for RCC
 */
#include "RCC_config.h"

/**
 * @reason: contains all the interface functions to be implemented
 */
#include "RCC_header.h"

/**
 * @reason: contains all register addresses and bit definitions for embedded RCC configuration registers
 */
#include "RCC_reg.h"

/**
 * @reason: contains all private function declaration and global variables
 */
#include "RCC_private.h"

/******************************************************************************
 * Module Preprocessor Constants
 *******************************************************************************/

/******************************************************************************
 * Module Preprocessor Macros
 *******************************************************************************/

/******************************************************************************
 * Module Typedefs
 *******************************************************************************/

/******************************************************************************
 * Module Variable Definitions
 *******************************************************************************/

/******************************************************************************
 * Function Prototypes
 *******************************************************************************/

/******************************************************************************
 * Function Definitions
 *******************************************************************************/

/**
 *
 */
HAL_RCC_ErrStates_t HAL_RCC_Init()
{
    // local used variables
    HAL_RCC_ErrStates_t local_errState = HAL_RCC_OK;
    uint8_t local_u8Iterator = 0;
    uint8_t local_u8PeriArrLen = (sizeof globalConstArr_RCCEnablementConfig_t) / (sizeof globalConstArr_RCCEnablementConfig_t[0]);
    uint32_t local_u32TempReg = 0;
    uint32_t local_u32TempVal = 0;
    uint32_t local_u32VCO1 = 0;
    uint32_t local_u32VCO2 = 0;
    uint8_t local_u8PLLM = 2;
    uint8_t local_u8PLLM_min = 0;
    uint8_t local_u8PLLM_max = 0;
    uint8_t local_u8PLLP = 2;
    uint8_t local_u8PLL48CLKQ = 2;
    uint8_t local_u8PLLI2SR = 2;
    uint16_t local_u16PLLN = 50;
    uint16_t local_u16PLLI2SN = 50;
    uint32_t local_u32PLLSrcSpeed = 0;
    uint8_t local_u8PLLConfigSuccess = LIB_CONSTANTS_FAIL;

    // assign a value for system clock
    if (globalConstArr_RCC_SYSCLK_ClockConfig_t[0].SYSClkClockSource == HAL_RCC_SYSCLK_CLK_SRC_HSI)
    {
        global_u32SystemClock = HAL_RCC_HSI_SPEED;
    }
    else if (globalConstArr_RCC_SYSCLK_ClockConfig_t[0].SYSClkClockSource == HAL_RCC_SYSCLK_CLK_SRC_HSE)
    {
        global_u32SystemClock = globalConstArr_RCC_MiscellaneousConfig_t[0].HSEVal;
    }
    else if (globalConstArr_RCC_SYSCLK_ClockConfig_t[0].SYSClkClockSource == HAL_RCC_SYSCLK_CLK_SRC_PLL)
    {
        global_u32SystemClock = globalConstArr_RCC_PLL_ClockConfig_t[0].PLLOutputValue;
    }

    // validate all configurations
    for (local_u8Iterator = 0; local_u8Iterator < local_u8PeriArrLen; local_u8Iterator++)
    {
        if (globalConstArr_RCCEnablementConfig_t[local_u8Iterator].PeripheralName >= HAL_RCC_MAX_PERIPHERAL ||
            globalConstArr_RCCEnablementConfig_t[local_u8Iterator].EnableInSleepMode >= LIB_CONSTANTS_MAX_DRIVER_STATE ||
            globalConstArr_RCCEnablementConfig_t[local_u8Iterator].EnableInRunMode >= LIB_CONSTANTS_MAX_DRIVER_STATE)
        {
            local_errState = HAL_RCC_ERR_INVALID_CONFIG;
            break;
        }
    }
    if (globalConstArr_RCC_MiscellaneousConfig_t[0].I2SClockSource >= HAL_RCC_MAX_I2S_CLK_SRC ||
        globalConstArr_RCC_MiscellaneousConfig_t[0].EthernetMACPrescalar >= 21 ||
        globalConstArr_RCC_MiscellaneousConfig_t[0].HSEVal > 26000000 || globalConstArr_RCC_MiscellaneousConfig_t[0].HSEVal < 4000000 ||
        globalConstArr_RCC_ClocksEnable_t[0].PLL_ClkEnable >= LIB_CONSTANTS_MAX_DRIVER_STATE ||
        globalConstArr_RCC_ClocksEnable_t[0].PLLI2S_ClkEnable >= LIB_CONSTANTS_MAX_DRIVER_STATE ||
        globalConstArr_RCC_ClocksEnable_t[0].PLL48_ClkEnable >= LIB_CONSTANTS_MAX_DRIVER_STATE ||
        globalConstArr_RCC_ClocksEnable_t[0].HSI_ClkEnable >= LIB_CONSTANTS_MAX_DRIVER_STATE ||
        globalConstArr_RCC_ClocksEnable_t[0].HSE_ClkEnable >= LIB_CONSTANTS_MAX_DRIVER_STATE ||
        globalConstArr_RCC_ClocksEnable_t[0].LSI_ClkEnable >= LIB_CONSTANTS_MAX_DRIVER_STATE ||
        globalConstArr_RCC_ClocksEnable_t[0].LSE_ClkEnable >= LIB_CONSTANTS_MAX_DRIVER_STATE ||
        globalConstArr_RCC_PLL_ClockConfig_t[0].PLLClockSource >= HAL_RCC_MAX_PLL_CLK_SRC ||
        globalConstArr_RCC_PLL_ClockConfig_t[0].PLLOutputValue < 25000000 || globalConstArr_RCC_PLL_ClockConfig_t[0].PLLOutputValue > 168000000 || globalConstArr_RCC_PLL_ClockConfig_t[0].PLLOutputValue % 1000000 != 0 ||
        globalConstArr_RCC_PLL_ClockConfig_t[0].PLLI2SOutputValue > 25000000 || globalConstArr_RCC_PLL_ClockConfig_t[0].PLLI2SOutputValue > 192000000 || globalConstArr_RCC_PLL_ClockConfig_t[0].PLLOutputValue % 1000000 != 0 ||
        globalConstArr_RCC_MCO_ClockConfig_t[0].MCO1Enable >= LIB_CONSTANTS_MAX_DRIVER_STATE ||
        globalConstArr_RCC_MCO_ClockConfig_t[0].MCO1ClockSource >= HAL_RCC_MAX_MCO1_CLK_SRC ||
        globalConstArr_RCC_MCO_ClockConfig_t[0].MCO1Prescalar > 5 ||
        globalConstArr_RCC_MCO_ClockConfig_t[0].MCO2Enable >= LIB_CONSTANTS_MAX_DRIVER_STATE ||
        globalConstArr_RCC_MCO_ClockConfig_t[0].MCO2ClockSource >= HAL_RCC_MAX_MCO2_CLK_SRC ||
        globalConstArr_RCC_MCO_ClockConfig_t[0].MCO2Prescalar > 5 ||
        globalConstArr_RCC_RTC_ClockConfig_t[0].RTCClockSource >= HAL_RCC_MAX_RTC_CLK_SRC ||
        globalConstArr_RCC_SYSCLK_ClockConfig_t[0].SYSClkClockSource >= HAL_RCC_MAX_SYSCLK_CLK_SRC ||
        (globalConstArr_RCC_SYSCLK_ClockConfig_t[0].SYSCLK_to_AHB_Prescalar != 0 && globalConstArr_RCC_SYSCLK_ClockConfig_t[0].SYSCLK_to_AHB_Prescalar <= 16 && (globalConstArr_RCC_SYSCLK_ClockConfig_t[0].SYSCLK_to_AHB_Prescalar & (globalConstArr_RCC_SYSCLK_ClockConfig_t[0].SYSCLK_to_AHB_Prescalar - 1))) ||
        (globalConstArr_RCC_SYSCLK_ClockConfig_t[0].AHB_to_APB1_Prescalar != 0 && globalConstArr_RCC_SYSCLK_ClockConfig_t[0].AHB_to_APB1_Prescalar <= 16 && (globalConstArr_RCC_SYSCLK_ClockConfig_t[0].AHB_to_APB1_Prescalar & (globalConstArr_RCC_SYSCLK_ClockConfig_t[0].AHB_to_APB1_Prescalar - 1))) ||
        (globalConstArr_RCC_SYSCLK_ClockConfig_t[0].AHB_to_APB2_Prescalar != 0 && globalConstArr_RCC_SYSCLK_ClockConfig_t[0].AHB_to_APB2_Prescalar <= 16 && (globalConstArr_RCC_SYSCLK_ClockConfig_t[0].AHB_to_APB2_Prescalar & (globalConstArr_RCC_SYSCLK_ClockConfig_t[0].AHB_to_APB2_Prescalar - 1))) ||
        (globalConstArr_RCC_SYSCLK_ClockConfig_t[0].SYSClkClockSource == HAL_RCC_SYSCLK_CLK_SRC_PLL && globalConstArr_RCC_PLL_ClockConfig_t[0].PLLOutputValue / globalConstArr_RCC_SYSCLK_ClockConfig_t[0].SYSCLK_to_AHB_Prescalar > 168000000) ||
        (globalConstArr_RCC_SYSCLK_ClockConfig_t[0].SYSClkClockSource == HAL_RCC_SYSCLK_CLK_SRC_PLL && globalConstArr_RCC_PLL_ClockConfig_t[0].PLLOutputValue / (globalConstArr_RCC_SYSCLK_ClockConfig_t[0].SYSCLK_to_AHB_Prescalar * globalConstArr_RCC_SYSCLK_ClockConfig_t[0].AHB_to_APB1_Prescalar) > 42000000) ||
        (globalConstArr_RCC_SYSCLK_ClockConfig_t[0].SYSClkClockSource == HAL_RCC_SYSCLK_CLK_SRC_PLL && globalConstArr_RCC_PLL_ClockConfig_t[0].PLLOutputValue / (globalConstArr_RCC_SYSCLK_ClockConfig_t[0].SYSCLK_to_AHB_Prescalar * globalConstArr_RCC_SYSCLK_ClockConfig_t[0].AHB_to_APB2_Prescalar) > 84000000) ||
        ((globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_ETHERNET].EnableInRunMode == LIB_CONSTANTS_ENABLED || globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_ETHERNET].EnableInSleepMode == LIB_CONSTANTS_ENABLED) && (global_u32SystemClock / globalConstArr_RCC_SYSCLK_ClockConfig_t[0].SYSCLK_to_AHB_Prescalar < 25000000)))

    {
        local_errState = HAL_RCC_ERR_INVALID_CONFIG;
    }

    // find configurations for PLL if enabled (UGLIEST CODE I HAVE EVER WRITTEN --> TODO: REFACTOR THE BELOW CODE)
    if (local_errState == HAL_RCC_OK)
    {
        local_u32PLLSrcSpeed = (globalConstArr_RCC_PLL_ClockConfig_t[0].PLLClockSource == HAL_RCC_PLL_CLK_SRC_HSE) ? globalConstArr_RCC_MiscellaneousConfig_t[0].HSEVal : HAL_RCC_HSI_SPEED;

        local_u8PLLM_max = local_u32PLLSrcSpeed / 1000000;
        local_u8PLLM_min = local_u32PLLSrcSpeed / 2000000;

        // optimize for PLL, PLLI2S, PLL48
        if (globalConstArr_RCC_ClocksEnable_t[0].PLL_ClkEnable == LIB_CONSTANTS_ENABLED && globalConstArr_RCC_ClocksEnable_t[0].PLLI2S_ClkEnable == LIB_CONSTANTS_ENABLED && globalConstArr_RCC_ClocksEnable_t[0].PLL48_ClkEnable == LIB_CONSTANTS_ENABLED)
        {
            for (local_u8PLLM = local_u8PLLM_min; local_u8PLLM <= local_u8PLLM_max; local_u8PLLM++)
            {
                for (local_u8PLLP = 2; local_u8PLLP <= 8; local_u8PLLP += 2)
                {
                    for (local_u8PLL48CLKQ = 2; local_u8PLL48CLKQ <= 15; local_u8PLL48CLKQ++)
                    {
                        for (local_u8PLLI2SR = 2; local_u8PLLI2SR <= 7; local_u8PLLI2SR++)
                        {
                            for (local_u16PLLN = 50; local_u16PLLN <= 432; local_u16PLLN++)
                            {
                                for (local_u16PLLI2SN = local_u16PLLI2SN; local_u16PLLI2SN <= 432; local_u16PLLI2SN++)
                                {
                                    local_u32VCO1 = (local_u32PLLSrcSpeed * ((local_u16PLLN * 10) / local_u8PLLM)) / 10;
                                    local_u32VCO2 = (local_u32PLLSrcSpeed * ((local_u16PLLI2SN * 10) / local_u8PLLM)) / 10;
                                    if (globalConstArr_RCC_PLL_ClockConfig_t[0].PLLOutputValue == local_u32VCO1 / local_u8PLLP &&
                                        globalConstArr_RCC_PLL_ClockConfig_t[0].PLLI2SOutputValue == local_u32VCO2 / local_u8PLLI2SR &&
                                        local_u32VCO1 >= HAL_RCC_VCO_MIN_SPEED && local_u32VCO1 <= HAL_RCC_VCO_MAX_SPEED &&
                                        local_u32VCO2 >= HAL_RCC_VCO_MIN_SPEED && local_u32VCO2 <= HAL_RCC_VCO_MAX_SPEED &&
                                        HAL_RCC_PLL48CLK_SPEED * local_u8PLL48CLKQ == local_u32VCO1)
                                    {
                                        local_u8PLLConfigSuccess = LIB_CONSTANTS_SUCCESS;
                                        goto label;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        // optimize for PLL, PLLI2S
        else if (globalConstArr_RCC_ClocksEnable_t[0].PLL_ClkEnable == LIB_CONSTANTS_ENABLED && globalConstArr_RCC_ClocksEnable_t[0].PLLI2S_ClkEnable == LIB_CONSTANTS_ENABLED && globalConstArr_RCC_ClocksEnable_t[0].PLL48_ClkEnable == LIB_CONSTANTS_DISABLED)
        {
            for (local_u8PLLP = 2; local_u8PLLP <= 8; local_u8PLLP += 2)
            {
                for (local_u8PLLI2SR = 2; local_u8PLLI2SR <= 7; local_u8PLLI2SR++)
                {
                    for (local_u16PLLN = 50; local_u16PLLN <= 432; local_u16PLLN++)
                    {
                        for (local_u16PLLI2SN = local_u16PLLI2SN; local_u16PLLI2SN <= 432; local_u16PLLI2SN++)
                        {
                            local_u32VCO1 = (local_u32PLLSrcSpeed * ((local_u16PLLN * 10) / local_u8PLLM)) / 10;
                            local_u32VCO2 = (local_u32PLLSrcSpeed * ((local_u16PLLI2SN * 10) / local_u8PLLM)) / 10;
                            if (globalConstArr_RCC_PLL_ClockConfig_t[0].PLLOutputValue == local_u32VCO1 / local_u8PLLP &&
                                globalConstArr_RCC_PLL_ClockConfig_t[0].PLLI2SOutputValue == local_u32VCO2 / local_u8PLLI2SR &&
                                local_u32VCO1 >= HAL_RCC_VCO_MIN_SPEED && local_u32VCO1 <= HAL_RCC_VCO_MAX_SPEED &&
                                local_u32VCO2 >= HAL_RCC_VCO_MIN_SPEED && local_u32VCO2 <= HAL_RCC_VCO_MAX_SPEED)
                            {
                                local_u8PLLConfigSuccess = LIB_CONSTANTS_SUCCESS;
                                goto label;
                            }
                        }
                    }
                }
            }
        }
        // optimize for PLL, PLL48
        else if (globalConstArr_RCC_ClocksEnable_t[0].PLL_ClkEnable == LIB_CONSTANTS_ENABLED && globalConstArr_RCC_ClocksEnable_t[0].PLLI2S_ClkEnable == LIB_CONSTANTS_DISABLED && globalConstArr_RCC_ClocksEnable_t[0].PLL48_ClkEnable == LIB_CONSTANTS_ENABLED)
        {
            for (local_u8PLLM = local_u8PLLM_min; local_u8PLLM <= local_u8PLLM_max; local_u8PLLM++)
            {
                for (local_u8PLLP = 2; local_u8PLLP <= 8; local_u8PLLP += 2)
                {
                    for (local_u8PLL48CLKQ = 2; local_u8PLL48CLKQ <= 15; local_u8PLL48CLKQ++)
                    {
                        for (local_u16PLLN = 50; local_u16PLLN <= 432; local_u16PLLN++)
                        {
                            local_u32VCO1 = (local_u32PLLSrcSpeed * ((local_u16PLLN * 10) / local_u8PLLM)) / 10;
                            if (globalConstArr_RCC_PLL_ClockConfig_t[0].PLLOutputValue == local_u32VCO1 / local_u8PLLP &&
                                local_u32VCO1 >= HAL_RCC_VCO_MIN_SPEED && local_u32VCO1 <= HAL_RCC_VCO_MAX_SPEED &&
                                HAL_RCC_PLL48CLK_SPEED * local_u8PLL48CLKQ == local_u32VCO1)
                            {
                                local_u8PLLConfigSuccess = LIB_CONSTANTS_SUCCESS;
                                goto label;
                            }
                        }
                    }
                }
            }
        }
        // optimize for PLL
        else if (globalConstArr_RCC_ClocksEnable_t[0].PLL_ClkEnable == LIB_CONSTANTS_ENABLED && globalConstArr_RCC_ClocksEnable_t[0].PLLI2S_ClkEnable == LIB_CONSTANTS_DISABLED && globalConstArr_RCC_ClocksEnable_t[0].PLL48_ClkEnable == LIB_CONSTANTS_DISABLED)
        {
            for (local_u8PLLM = local_u8PLLM_min; local_u8PLLM <= local_u8PLLM_max; local_u8PLLM++)
            {
                for (local_u8PLLP = 2; local_u8PLLP <= 8; local_u8PLLP += 2)
                {
                    for (local_u16PLLN = 50; local_u16PLLN <= 432; local_u16PLLN++)
                    {
                        local_u32VCO1 = (local_u32PLLSrcSpeed * ((local_u16PLLN * 10) / local_u8PLLM)) / 10;
                        if (globalConstArr_RCC_PLL_ClockConfig_t[0].PLLOutputValue == local_u32VCO1 / local_u8PLLP &&
                            local_u32VCO1 >= HAL_RCC_VCO_MIN_SPEED && local_u32VCO1 <= HAL_RCC_VCO_MAX_SPEED)
                        {
                            local_u8PLLConfigSuccess = LIB_CONSTANTS_SUCCESS;
                            goto label;
                        }
                    }
                }
            }
        }
        // optimize for PLLI2S, PLL48
        else if (globalConstArr_RCC_ClocksEnable_t[0].PLL_ClkEnable == LIB_CONSTANTS_DISABLED && globalConstArr_RCC_ClocksEnable_t[0].PLLI2S_ClkEnable == LIB_CONSTANTS_ENABLED && globalConstArr_RCC_ClocksEnable_t[0].PLL48_ClkEnable == LIB_CONSTANTS_ENABLED)
        {
            for (local_u8PLLM = local_u8PLLM_min; local_u8PLLM <= local_u8PLLM_max; local_u8PLLM++)
            {
                for (local_u8PLL48CLKQ = 2; local_u8PLL48CLKQ <= 15; local_u8PLL48CLKQ++)
                {
                    for (local_u8PLLI2SR = 2; local_u8PLLI2SR <= 7; local_u8PLLI2SR++)
                    {
                        for (local_u16PLLN = 50; local_u16PLLN <= 432; local_u16PLLN++)
                        {
                            for (local_u16PLLI2SN = local_u16PLLI2SN; local_u16PLLI2SN <= 432; local_u16PLLI2SN++)
                            {
                                local_u32VCO1 = (local_u32PLLSrcSpeed * ((local_u16PLLN * 10) / local_u8PLLM)) / 10;
                                local_u32VCO2 = (local_u32PLLSrcSpeed * ((local_u16PLLI2SN * 10) / local_u8PLLM)) / 10;
                                if (globalConstArr_RCC_PLL_ClockConfig_t[0].PLLI2SOutputValue == local_u32VCO2 / local_u8PLLI2SR &&
                                    local_u32VCO1 >= HAL_RCC_VCO_MIN_SPEED && local_u32VCO1 <= HAL_RCC_VCO_MAX_SPEED &&
                                    local_u32VCO2 >= HAL_RCC_VCO_MIN_SPEED && local_u32VCO2 <= HAL_RCC_VCO_MAX_SPEED &&
                                    HAL_RCC_PLL48CLK_SPEED * local_u8PLL48CLKQ == local_u32VCO1)
                                {
                                    local_u8PLLConfigSuccess = LIB_CONSTANTS_SUCCESS;
                                    goto label;
                                }
                            }
                        }
                    }
                }
            }
        }
        // optimize for PLLI2S
        else if (globalConstArr_RCC_ClocksEnable_t[0].PLL_ClkEnable == LIB_CONSTANTS_DISABLED && globalConstArr_RCC_ClocksEnable_t[0].PLLI2S_ClkEnable == LIB_CONSTANTS_ENABLED && globalConstArr_RCC_ClocksEnable_t[0].PLL48_ClkEnable == LIB_CONSTANTS_DISABLED)
        {
            for (local_u8PLLM = local_u8PLLM_min; local_u8PLLM <= local_u8PLLM_max; local_u8PLLM++)
            {
                for (local_u8PLLI2SR = 2; local_u8PLLI2SR <= 7; local_u8PLLI2SR++)
                {
                    for (local_u16PLLI2SN = local_u16PLLI2SN; local_u16PLLI2SN <= 432; local_u16PLLI2SN++)
                    {
                        local_u32VCO2 = (local_u32PLLSrcSpeed * ((local_u16PLLI2SN * 10) / local_u8PLLM)) / 10;
                        if (globalConstArr_RCC_PLL_ClockConfig_t[0].PLLI2SOutputValue == local_u32VCO2 / local_u8PLLI2SR &&
                            local_u32VCO2 >= HAL_RCC_VCO_MIN_SPEED && local_u32VCO2 <= HAL_RCC_VCO_MAX_SPEED)
                        {
                            local_u8PLLConfigSuccess = LIB_CONSTANTS_SUCCESS;
                            goto label;
                        }
                    }
                }
            }
        }
        // optimize for PLL48
        else if (globalConstArr_RCC_ClocksEnable_t[0].PLL_ClkEnable == LIB_CONSTANTS_DISABLED && globalConstArr_RCC_ClocksEnable_t[0].PLLI2S_ClkEnable == LIB_CONSTANTS_DISABLED && globalConstArr_RCC_ClocksEnable_t[0].PLL48_ClkEnable == LIB_CONSTANTS_ENABLED)
        {
            for (local_u8PLLM = local_u8PLLM_min; local_u8PLLM <= local_u8PLLM_max; local_u8PLLM++)
            {
                for (local_u8PLL48CLKQ = 2; local_u8PLL48CLKQ <= 15; local_u8PLL48CLKQ++)
                {
                    for (local_u16PLLN = 50; local_u16PLLN <= 432; local_u16PLLN++)
                    {
                        local_u32VCO1 = (local_u32PLLSrcSpeed * ((local_u16PLLN * 10) / local_u8PLLM)) / 10;
                        if (globalConstArr_RCC_PLL_ClockConfig_t[0].PLLOutputValue == local_u32VCO1 / local_u8PLLP &&
                            local_u32VCO1 >= HAL_RCC_VCO_MIN_SPEED && local_u32VCO1 <= HAL_RCC_VCO_MAX_SPEED &&
                            HAL_RCC_PLL48CLK_SPEED * local_u8PLL48CLKQ == local_u32VCO1)
                        {
                            local_u8PLLConfigSuccess = LIB_CONSTANTS_SUCCESS;
                            goto label;
                        }
                    }
                }
            }
        }
        else
        {
            // do nothing
        	local_u8PLLConfigSuccess = LIB_CONSTANTS_SUCCESS;
        }

    label:
        local_errState = (local_u8PLLConfigSuccess == LIB_CONSTANTS_SUCCESS) ? local_errState : HAL_RCC_ERR_INVALID_CLK_VAL;
    }
    else
    {
        // do nothing
    }

    // main initialization
    if (local_errState == HAL_RCC_OK)
    {
        // configure RCC PLL configuration register
        local_u32TempReg = global_pRCCReg_t->RCC_PLLCFGR;
        LIB_MATH_BTT_ASSIGN_BITS(local_u32TempReg, HAL_RCC_PLLCFGR_PLLQ, local_u8PLL48CLKQ, 4);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_PLLCFGR_PLLSRC, globalConstArr_RCC_PLL_ClockConfig_t[0].PLLClockSource);
        LIB_MATH_BTT_ASSIGN_BITS(local_u32TempReg, HAL_RCC_PLLCFGR_PLLP, (local_u8PLLP - 2) / 2, 2);
        LIB_MATH_BTT_ASSIGN_BITS(local_u32TempReg, HAL_RCC_PLLCFGR_PLLN, local_u16PLLN, 9);
        LIB_MATH_BTT_ASSIGN_BITS(local_u32TempReg, HAL_RCC_PLLCFGR_PLLM, local_u8PLLM, 6);
        global_pRCCReg_t->RCC_PLLCFGR = local_u32TempReg;

        // configure RCC clock configuration register
        local_u32TempReg = global_pRCCReg_t->RCC_CFGR;
        LIB_MATH_BTT_ASSIGN_BITS(local_u32TempReg, HAL_RCC_CFGR_MCO2, globalConstArr_RCC_MCO_ClockConfig_t[0].MCO2ClockSource, 2);
        LIB_MATH_BTT_ASSIGN_BITS(local_u32TempReg, HAL_RCC_CFGR_MCO2PRE, globalConstArr_RCC_MCO_ClockConfig_t[0].MCO2Prescalar + 2, 3);
        LIB_MATH_BTT_ASSIGN_BITS(local_u32TempReg, HAL_RCC_CFGR_MCO1PRE, globalConstArr_RCC_MCO_ClockConfig_t[0].MCO1Prescalar + 2, 3);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_CFGR_I2SSRC, globalConstArr_RCC_MiscellaneousConfig_t[0].I2SClockSource);
        LIB_MATH_BTT_ASSIGN_BITS(local_u32TempReg, HAL_RCC_CFGR_MCO1, globalConstArr_RCC_MCO_ClockConfig_t[0].MCO1ClockSource, 2);
        local_u32TempVal = globalConstArr_RCC_MiscellaneousConfig_t[0].HSEVal / 100000;
        if (local_u32TempVal % 10 >= 5)
        {
            local_u32TempVal += 5;
        }
        else
        {
            // do nothing
        }
        global_u32HSEtoRTCClk = globalConstArr_RCC_MiscellaneousConfig_t[0].HSEVal / (local_u32TempVal / 10);
        LIB_MATH_BTT_ASSIGN_BITS(local_u32TempReg, HAL_RCC_CFGR_RTCPRE, local_u32TempVal / 10, 5);
        local_u32TempVal = LIB_MATH_BTT_u8GetMSBSetPos(globalConstArr_RCC_SYSCLK_ClockConfig_t[0].AHB_to_APB2_Prescalar);
        LIB_MATH_BTT_ASSIGN_BITS(local_u32TempReg, HAL_RCC_CFGR_PPRE2, local_u32TempVal + 3, 3);
        local_u32TempVal = LIB_MATH_BTT_u8GetMSBSetPos(globalConstArr_RCC_SYSCLK_ClockConfig_t[0].AHB_to_APB1_Prescalar);
        LIB_MATH_BTT_ASSIGN_BITS(local_u32TempReg, HAL_RCC_CFGR_PPRE1, local_u32TempVal + 3, 3);
        local_u32TempVal = LIB_MATH_BTT_u8GetMSBSetPos(globalConstArr_RCC_SYSCLK_ClockConfig_t[0].SYSCLK_to_AHB_Prescalar);
        LIB_MATH_BTT_ASSIGN_BITS(local_u32TempReg, HAL_RCC_CFGR_HPRE, local_u32TempVal + 7, 3);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_CFGR_SW, globalConstArr_RCC_SYSCLK_ClockConfig_t[0].SYSClkClockSource);
        global_pRCCReg_t->RCC_CFGR = local_u32TempReg;

        // configure RCC clock interrupt register (RCC_CIR)
        // TODO: enable it in case of enabling interrupts for clock stable

        // configure RCC Backup domain control register
        // TODO: configure BDRST and LSEBYP
        // TODO: set DBP bit in PWR_CR in order to change the register value
        local_u32TempReg = global_pRCCReg_t->RCC_BDCR; 
        LIB_MATH_BTT_ASSIGN_BITS(local_u32TempReg, HAL_RCC_BDCR_RTCSEL, globalConstArr_RCC_RTC_ClockConfig_t[0].RTCClockSource, 2);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_BDCR_LSEON, globalConstArr_RCC_ClocksEnable_t[0].LSE_ClkEnable);
        global_pRCCReg_t->RCC_BDCR = local_u32TempReg;

        // configure RCC clock control & status register
        // TODO: use LSIRDY bit
        LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_CSR, HAL_RCC_CSR_LSION, globalConstArr_RCC_ClocksEnable_t[0].LSI_ClkEnable);

        // TODO: configure RCC spread spectrum clock generation register

        // configure RCC PLLI2S configuration register
        local_u32TempReg = global_pRCCReg_t->RCC_PLLI2SCFGR;
        LIB_MATH_BTT_ASSIGN_BITS(local_u32TempReg, HAL_RCC_PLLI2SCFGR_PLLI2SR, local_u8PLLI2SR, 3);
        LIB_MATH_BTT_ASSIGN_BITS(local_u32TempReg, HAL_RCC_PLLI2SCFGR_PLLI2SN, local_u16PLLI2SN, 9);
        global_pRCCReg_t->RCC_PLLI2SCFGR = local_u32TempReg;

        // configure RCC clock control register (TODO: enable/disable HSE bypase , adjust calibration)
        local_u32TempReg = global_pRCCReg_t->RCC_CR;
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_CR_PLLI2SON, globalConstArr_RCC_ClocksEnable_t[0].PLLI2S_ClkEnable);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_CR_PLLON, globalConstArr_RCC_ClocksEnable_t[0].PLL_ClkEnable);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_CR_CSSON, globalConstArr_RCC_MiscellaneousConfig_t[0].ClockSecurityEnable);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_CR_HSEON, globalConstArr_RCC_ClocksEnable_t[0].HSE_ClkEnable);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_CR_HSION, globalConstArr_RCC_ClocksEnable_t[0].HSI_ClkEnable);
        global_pRCCReg_t->RCC_CR = local_u32TempReg;

        // configure RCC AHB1 peripheral clock enable register
        local_u32TempReg = global_pRCCReg_t->RCC_AHB1ENR;
        if (1) // TODO: edit this line with configuration from USB to determine whether to use HS or FS
        {
            LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_AHB1ENR_OTGHSEN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_USB_OTG].EnableInRunMode);
        }
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_AHB1ENR_ETHMACPTPEN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_ETHERNET].EnableInRunMode);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_AHB1ENR_ETHMACRXEN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_ETHERNET].EnableInRunMode);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_AHB1ENR_ETHMACTXEN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_ETHERNET].EnableInRunMode);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_AHB1ENR_ETHMACEN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_ETHERNET].EnableInRunMode);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_AHB1ENR_DMA2EN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_DMA2].EnableInRunMode);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_AHB1ENR_DMA1EN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_DMA1].EnableInRunMode);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_AHB1ENR_CCMDATARAMEN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_CCM].EnableInRunMode);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_AHB1ENR_BKPSRAMEN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_BKP_SRAM].EnableInRunMode);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_AHB1ENR_CRCEN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_CRC].EnableInRunMode);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_AHB1ENR_GPIOAEN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_GPIOA].EnableInRunMode);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_AHB1ENR_GPIOBEN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_GPIOB].EnableInRunMode);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_AHB1ENR_GPIOCEN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_GPIOC].EnableInRunMode);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_AHB1ENR_GPIODEN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_GPIOD].EnableInRunMode);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_AHB1ENR_GPIOEEN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_GPIOE].EnableInRunMode);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_AHB1ENR_GPIOFEN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_GPIOF].EnableInRunMode);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_AHB1ENR_GPIOGEN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_GPIOG].EnableInRunMode);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_AHB1ENR_GPIOHEN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_GPIOH].EnableInRunMode);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_AHB1ENR_GPIOIEN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_GPIOI].EnableInRunMode);
        global_pRCCReg_t->RCC_AHB1ENR = local_u32TempReg;

        // configure RCC AHB2 peripheral clock enable register
        local_u32TempReg = global_pRCCReg_t->RCC_AHB2ENR;
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_AHB2ENR_RNGEN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_RNG].EnableInRunMode);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_AHB2ENR_HASHEN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_HASH].EnableInRunMode);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_AHB2ENR_CRYPEN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_CRYPTO].EnableInRunMode);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_AHB2ENR_DCMIEN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_CAMERA].EnableInRunMode);
        global_pRCCReg_t->RCC_AHB2ENR = local_u32TempReg;

        // configure RCC AHB3 peripheral clock enable register
        HAL_RCC_EN_FSMCEN(globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_FSMC].EnableInRunMode);

        // configure RCC APB1 peripheral clock enable register
        local_u32TempReg = global_pRCCReg_t->RCC_APB1ENR;
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_APB1ENR_DACEN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_DAC].EnableInRunMode);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_APB1ENR_PWREN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_PWR].EnableInRunMode);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_APB1ENR_CAN2EN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_CAN2].EnableInRunMode);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_APB1ENR_CAN1EN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_CAN1].EnableInRunMode);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_APB1ENR_I2C1EN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_I2C3].EnableInRunMode);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_APB1ENR_I2C2EN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_I2C2].EnableInRunMode);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_APB1ENR_I2C3EN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_I2C1].EnableInRunMode);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_APB1ENR_UART5EN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_UART5].EnableInRunMode);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_APB1ENR_UART4EN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_UART4].EnableInRunMode);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_APB1ENR_USART3EN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_USART3].EnableInRunMode);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_APB1ENR_USART2EN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_USART2].EnableInRunMode);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_APB1ENR_SPI3EN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_SPI3].EnableInRunMode);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_APB1ENR_SPI2EN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_SPI2].EnableInRunMode);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_APB1ENR_WWDGEN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_WWDG].EnableInRunMode);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_APB1ENR_TIM14EN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_TIM14].EnableInRunMode);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_APB1ENR_TIM13EN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_TIM13].EnableInRunMode);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_APB1ENR_TIM12EN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_TIM12].EnableInRunMode);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_APB1ENR_TIM7EN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_TIM7].EnableInRunMode);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_APB1ENR_TIM6EN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_TIM6].EnableInRunMode);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_APB1ENR_TIM5EN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_TIM5].EnableInRunMode);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_APB1ENR_TIM4EN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_TIM4].EnableInRunMode);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_APB1ENR_TIM3EN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_TIM3].EnableInRunMode);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_APB1ENR_TIM2EN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_TIM2].EnableInRunMode);
        global_pRCCReg_t->RCC_APB1ENR = local_u32TempReg;

        // Configure RCC APB2 peripheral clock enable register
        local_u32TempReg = global_pRCCReg_t->RCC_APB2ENR;
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_APB2ENR_TIM11EN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_TIM11].EnableInRunMode);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_APB2ENR_TIM10EN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_TIM10].EnableInRunMode);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_APB2ENR_TIM9EN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_TIM9].EnableInRunMode);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_APB2ENR_SYSCFGEN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_SYS_CFG].EnableInRunMode);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_APB2ENR_SPI1EN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_SPI1].EnableInRunMode);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_APB2ENR_SDIOEN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_SDIO].EnableInRunMode);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_APB2ENR_ADC3EN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_ADC3].EnableInRunMode);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_APB2ENR_ADC2EN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_ADC2].EnableInRunMode);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_APB2ENR_ADC1EN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_ADC1].EnableInRunMode);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_APB2ENR_USART6EN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_USART6].EnableInRunMode);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_APB2ENR_USART1EN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_USART1].EnableInRunMode);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_APB2ENR_TIM8EN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_TIM8].EnableInRunMode);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_APB2ENR_TIM1EN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_TIM1].EnableInRunMode);
        global_pRCCReg_t->RCC_APB2ENR = local_u32TempReg;

        // configure RCC AHB1 peripheral clock enable in low power mode register
        local_u32TempReg = global_pRCCReg_t->RCC_AHB1LPENR;
        if (1) // TODO: edit this line with configuration from USB to determine whether to use HS or FS
        {
            LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_AHB1LPENR_OTGHSLPEN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_USB_OTG].EnableInSleepMode);
        }
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_AHB1LPENR_ETHMACPTPLPEN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_ETHERNET].EnableInSleepMode);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_AHB1LPENR_ETHMACRXLPEN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_ETHERNET].EnableInSleepMode);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_AHB1LPENR_ETHMACTXLPEN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_ETHERNET].EnableInSleepMode);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_AHB1LPENR_ETHMACLPEN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_ETHERNET].EnableInSleepMode);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_AHB1LPENR_DMA2LPEN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_DMA2].EnableInSleepMode);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_AHB1LPENR_DMA1LPEN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_DMA1].EnableInSleepMode);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_AHB1LPENR_BKPSRAMLPEN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_BKP_SRAM].EnableInSleepMode);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_AHB1LPENR_SRAM2LPEN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_SRAM2].EnableInSleepMode);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_AHB1LPENR_SRAM1LPEN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_SRAM1].EnableInSleepMode);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_AHB1LPENR_FLITFLPEN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_FLASH_MEM].EnableInSleepMode);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_AHB1LPENR_CRCLPEN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_CRC].EnableInSleepMode);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_AHB1LPENR_GPIOALPEN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_GPIOA].EnableInSleepMode);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_AHB1LPENR_GPIOBLPEN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_GPIOB].EnableInSleepMode);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_AHB1LPENR_GPIOCLPEN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_GPIOC].EnableInSleepMode);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_AHB1LPENR_GPIODLPEN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_GPIOD].EnableInSleepMode);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_AHB1LPENR_GPIOELPEN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_GPIOE].EnableInSleepMode);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_AHB1LPENR_GPIOFLPEN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_GPIOF].EnableInSleepMode);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_AHB1LPENR_GPIOGLPEN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_GPIOG].EnableInSleepMode);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_AHB1LPENR_GPIOHLPEN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_GPIOH].EnableInSleepMode);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_AHB1LPENR_GPIOILPEN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_GPIOI].EnableInSleepMode);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_AHB1LPENR_GPIOILPEN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_GPIOI].EnableInSleepMode);
        global_pRCCReg_t->RCC_AHB1LPENR = local_u32TempReg;

        // configure RCC AHB2 peripheral clock enable in low power mode register
        local_u32TempReg = global_pRCCReg_t->RCC_AHB2LPENR;
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_AHB2LPENR_RNGLPEN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_RNG].EnableInSleepMode);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_AHB2LPENR_HASHLPEN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_HASH].EnableInSleepMode);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_AHB2LPENR_CRYPLPEN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_CRYPTO].EnableInSleepMode);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_AHB2LPENR_DCMILPEN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_CAMERA].EnableInSleepMode);
        global_pRCCReg_t->RCC_AHB2LPENR = local_u32TempReg;

        // configure RCC AHB3 peripheral clock enable in low power mode register
        HAL_RCC_LOW_PWR_FSMCLPEN(globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_FSMC].EnableInSleepMode);

        // configure RCC APB1 peripheral clock enable in low power mode register
        local_u32TempReg = global_pRCCReg_t->RCC_APB1LPENR;
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_APB1LPENR_DACLPEN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_DAC].EnableInSleepMode);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_APB1LPENR_PWRLPEN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_PWR].EnableInSleepMode);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_APB1LPENR_CAN2LPEN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_CAN2].EnableInSleepMode);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_APB1LPENR_CAN1LPEN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_CAN1].EnableInSleepMode);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_APB1LPENR_I2C3LPEN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_I2C3].EnableInSleepMode);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_APB1LPENR_I2C2LPEN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_I2C2].EnableInSleepMode);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_APB1LPENR_I2C1LPEN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_I2C1].EnableInSleepMode);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_APB1LPENR_UART5LPEN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_UART5].EnableInSleepMode);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_APB1LPENR_UART4LPEN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_UART4].EnableInSleepMode);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_APB1LPENR_USART3LPEN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_USART3].EnableInSleepMode);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_APB1LPENR_USART2LPEN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_USART2].EnableInSleepMode);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_APB1LPENR_SPI3LPEN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_SPI3].EnableInSleepMode);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_APB1LPENR_SPI2LPEN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_SPI2].EnableInSleepMode);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_APB1LPENR_WWDGLPEN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_WWDG].EnableInSleepMode);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_APB1LPENR_TIM14LPEN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_TIM14].EnableInSleepMode);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_APB1LPENR_TIM13LPEN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_TIM13].EnableInSleepMode);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_APB1LPENR_TIM12LPEN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_TIM12].EnableInSleepMode);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_APB1LPENR_TIM7LPEN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_TIM7].EnableInSleepMode);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_APB1LPENR_TIM6LPEN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_TIM6].EnableInSleepMode);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_APB1LPENR_TIM5LPEN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_TIM5].EnableInSleepMode);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_APB1LPENR_TIM4LPEN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_TIM4].EnableInSleepMode);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_APB1LPENR_TIM3LPEN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_TIM3].EnableInSleepMode);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_APB1LPENR_TIM2LPEN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_TIM2].EnableInSleepMode);
        global_pRCCReg_t->RCC_APB1LPENR = local_u32TempReg;

        // configure RCC APB2 peripheral clock enabled in low power mode register
        local_u32TempReg = global_pRCCReg_t->RCC_APB2LPENR;
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_APB2LPENR_TIM11LPEN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_TIM11].EnableInSleepMode);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_APB2LPENR_TIM10LPEN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_TIM10].EnableInSleepMode);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_APB2LPENR_TIM9LPEN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_TIM9].EnableInSleepMode);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_APB2LPENR_TIM8LPEN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_TIM8].EnableInSleepMode);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_APB2LPENR_TIM1LPEN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_TIM1].EnableInSleepMode);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_APB2LPENR_SYSCFGLPEN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_SYS_CFG].EnableInSleepMode);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_APB2LPENR_SDIOLPEN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_SDIO].EnableInSleepMode);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_APB2LPENR_ADC3LPEN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_ADC3].EnableInSleepMode);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_APB2LPENR_ADC2LPEN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_ADC2].EnableInSleepMode);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_APB2LPENR_ADC1LPEN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_ADC1].EnableInSleepMode);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_APB2LPENR_USART6LPEN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_USART6].EnableInSleepMode);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_APB2LPENR_USART1LPEN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_USART1].EnableInSleepMode);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_RCC_APB2LPENR_USART1LPEN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_USART1].EnableInSleepMode);
        global_pRCCReg_t->RCC_APB2LPENR = local_u32TempReg;

        // for backup domain
        LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_BDCR, HAL_RCC_BDCR_RTCEN, globalConstArr_RCCEnablementConfig_t[HAL_RCC_PERIPHERAL_RTC].EnableInRunMode);
    }

    return local_errState;
}

/**
 *
 */
HAL_RCC_ErrStates_t HAL_RCC_PeripheralModify(const uint8_t argConst_u8PeripheralName, const uint8_t argConst_u8Operation)
{
    // local used variables
    HAL_RCC_ErrStates_t local_errState = HAL_RCC_OK;

    // check for errors
    if (argConst_u8PeripheralName >= HAL_RCC_MAX_PERIPHERAL || argConst_u8Operation >= HAL_RCC_MAX_PERI_OP)
    {
        local_errState = HAL_RCC_ERR_INVALID_PARAMS;
    }
    else
    {
        // do nothing
    }

    // main function
    if (local_errState == HAL_RCC_OK)
    {
        switch (argConst_u8PeripheralName)
        {

        case HAL_RCC_PERIPHERAL_USB_OTG: // TDDO: check the type of the USB
            if (argConst_u8Operation == HAL_RCC_PERI_OP_RESET)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_AHB1RSTR, HAL_RCC_AHB1RSTR_OTGHSRST);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_ENABLE)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_AHB1ENR, HAL_RCC_AHB1ENR_OTGHSEN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_DISABLE)
            {
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_AHB1ENR, HAL_RCC_AHB1ENR_OTGHSEN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_ENABLE)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_AHB1LPENR, HAL_RCC_AHB1LPENR_OTGHSLPEN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_DISABLE)
            {
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_AHB1LPENR, HAL_RCC_AHB1LPENR_OTGHSLPEN);
            }
            break;

        case HAL_RCC_PERIPHERAL_ETHERNET:
            if (argConst_u8Operation == HAL_RCC_PERI_OP_RESET)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_AHB1RSTR, HAL_RCC_AHB1RSTR_ETHMACRST);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_ENABLE)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_AHB1ENR, HAL_RCC_AHB1ENR_ETHMACPTPEN);
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_AHB1ENR, HAL_RCC_AHB1ENR_ETHMACRXEN);
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_AHB1ENR, HAL_RCC_AHB1ENR_ETHMACTXEN);
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_AHB1ENR, HAL_RCC_AHB1ENR_ETHMACEN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_DISABLE)
            {
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_AHB1ENR, HAL_RCC_AHB1ENR_ETHMACPTPEN);
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_AHB1ENR, HAL_RCC_AHB1ENR_ETHMACRXEN);
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_AHB1ENR, HAL_RCC_AHB1ENR_ETHMACTXEN);
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_AHB1ENR, HAL_RCC_AHB1ENR_ETHMACEN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_ENABLE)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_AHB1LPENR, HAL_RCC_AHB1LPENR_ETHMACPTPLPEN);
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_AHB1LPENR, HAL_RCC_AHB1LPENR_ETHMACRXLPEN);
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_AHB1LPENR, HAL_RCC_AHB1LPENR_ETHMACTXLPEN);
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_AHB1LPENR, HAL_RCC_AHB1LPENR_ETHMACLPEN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_DISABLE)
            {
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_AHB1LPENR, HAL_RCC_AHB1LPENR_ETHMACPTPLPEN);
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_AHB1LPENR, HAL_RCC_AHB1LPENR_ETHMACRXLPEN);
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_AHB1LPENR, HAL_RCC_AHB1LPENR_ETHMACTXLPEN);
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_AHB1LPENR, HAL_RCC_AHB1LPENR_ETHMACLPEN);
            }
            break;

        case HAL_RCC_PERIPHERAL_DMA1:
            if (argConst_u8Operation == HAL_RCC_PERI_OP_RESET)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_AHB1RSTR, HAL_RCC_AHB1RSTR_DMA1RST);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_ENABLE)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_AHB1ENR, HAL_RCC_AHB1ENR_DMA1EN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_DISABLE)
            {
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_AHB1ENR, HAL_RCC_AHB1ENR_DMA1EN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_ENABLE)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_AHB1LPENR, HAL_RCC_AHB1LPENR_DMA1LPEN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_DISABLE)
            {
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_AHB1LPENR, HAL_RCC_AHB1LPENR_DMA1LPEN);
            }
            break;

        case HAL_RCC_PERIPHERAL_DMA2:
            if (argConst_u8Operation == HAL_RCC_PERI_OP_RESET)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_AHB1RSTR, HAL_RCC_AHB1RSTR_DMA2RST);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_ENABLE)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_AHB1ENR, HAL_RCC_AHB1ENR_DMA2EN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_DISABLE)
            {
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_AHB1ENR, HAL_RCC_AHB1ENR_DMA2EN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_ENABLE)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_AHB1LPENR, HAL_RCC_AHB1LPENR_DMA2LPEN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_DISABLE)
            {
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_AHB1LPENR, HAL_RCC_AHB1LPENR_DMA2LPEN);
            }
            break;

        case HAL_RCC_PERIPHERAL_CCM:
            if (argConst_u8Operation == HAL_RCC_PERI_OP_RESET)
            {
                // do nothing
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_ENABLE)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_AHB1ENR, HAL_RCC_AHB1ENR_CCMDATARAMEN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_DISABLE)
            {
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_AHB1ENR, HAL_RCC_AHB1ENR_CCMDATARAMEN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_ENABLE)
            {
                // do nothing
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_DISABLE)
            {
                // do nothing
            }
            break;

        case HAL_RCC_PERIPHERAL_BKP_SRAM:
            if (argConst_u8Operation == HAL_RCC_PERI_OP_RESET)
            {
                // do nothing
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_ENABLE)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_AHB1ENR, HAL_RCC_AHB1ENR_BKPSRAMEN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_DISABLE)
            {
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_AHB1ENR, HAL_RCC_AHB1ENR_BKPSRAMEN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_ENABLE)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_AHB1LPENR, HAL_RCC_AHB1LPENR_BKPSRAMLPEN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_DISABLE)
            {
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_AHB1LPENR, HAL_RCC_AHB1LPENR_BKPSRAMLPEN);
            }
            break;

        case HAL_RCC_PERIPHERAL_SRAM1:
            if (argConst_u8Operation == HAL_RCC_PERI_OP_RESET)
            {
                // do nothing
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_ENABLE)
            {
                // do nothing
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_DISABLE)
            {
                // do nothing
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_ENABLE)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_AHB1LPENR, HAL_RCC_AHB1LPENR_SRAM1LPEN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_DISABLE)
            {
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_AHB1LPENR, HAL_RCC_AHB1LPENR_SRAM1LPEN);
            }
            break;

        case HAL_RCC_PERIPHERAL_SRAM2:
            if (argConst_u8Operation == HAL_RCC_PERI_OP_RESET)
            {
                // do nothing
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_ENABLE)
            {
                // do nothing
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_DISABLE)
            {
                // do nothing
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_ENABLE)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_AHB1LPENR, HAL_RCC_AHB1LPENR_SRAM2LPEN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_DISABLE)
            {
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_AHB1LPENR, HAL_RCC_AHB1LPENR_SRAM2LPEN);
            }
            break;

        case HAL_RCC_PERIPHERAL_CRC:
            if (argConst_u8Operation == HAL_RCC_PERI_OP_RESET)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_AHB1RSTR, HAL_RCC_AHB1RSTR_CRCRST);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_ENABLE)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_AHB1ENR, HAL_RCC_AHB1ENR_CRCEN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_DISABLE)
            {
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_AHB1ENR, HAL_RCC_AHB1ENR_CRCEN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_ENABLE)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_AHB1LPENR, HAL_RCC_AHB1LPENR_CRCLPEN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_DISABLE)
            {
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_AHB1LPENR, HAL_RCC_AHB1LPENR_CRCLPEN);
            }
            break;

        case HAL_RCC_PERIPHERAL_GPIOA:
            if (argConst_u8Operation == HAL_RCC_PERI_OP_RESET)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_AHB1RSTR, HAL_RCC_AHB1RSTR_GPIOARST);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_ENABLE)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_AHB1ENR, HAL_RCC_AHB1ENR_GPIOAEN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_DISABLE)
            {
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_AHB1ENR, HAL_RCC_AHB1ENR_GPIOAEN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_ENABLE)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_AHB1LPENR, HAL_RCC_AHB1LPENR_GPIOALPEN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_DISABLE)
            {
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_AHB1LPENR, HAL_RCC_AHB1LPENR_GPIOALPEN);
            }
            break;

        case HAL_RCC_PERIPHERAL_GPIOB:
            if (argConst_u8Operation == HAL_RCC_PERI_OP_RESET)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_AHB1RSTR, HAL_RCC_AHB1RSTR_GPIOBRST);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_ENABLE)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_AHB1ENR, HAL_RCC_AHB1ENR_GPIOBEN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_DISABLE)
            {
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_AHB1ENR, HAL_RCC_AHB1ENR_GPIOBEN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_ENABLE)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_AHB1LPENR, HAL_RCC_AHB1LPENR_GPIOBLPEN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_DISABLE)
            {
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_AHB1LPENR, HAL_RCC_AHB1LPENR_GPIOBLPEN);
            }
            break;

        case HAL_RCC_PERIPHERAL_GPIOC:
            if (argConst_u8Operation == HAL_RCC_PERI_OP_RESET)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_AHB1RSTR, HAL_RCC_AHB1RSTR_GPIOCRST);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_ENABLE)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_AHB1ENR, HAL_RCC_AHB1ENR_GPIOCEN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_DISABLE)
            {
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_AHB1ENR, HAL_RCC_AHB1ENR_GPIOCEN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_ENABLE)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_AHB1LPENR, HAL_RCC_AHB1LPENR_GPIOCLPEN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_DISABLE)
            {
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_AHB1LPENR, HAL_RCC_AHB1LPENR_GPIOCLPEN);
            }
            break;

        case HAL_RCC_PERIPHERAL_GPIOD:
            if (argConst_u8Operation == HAL_RCC_PERI_OP_RESET)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_AHB1RSTR, HAL_RCC_AHB1RSTR_GPIODRST);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_ENABLE)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_AHB1ENR, HAL_RCC_AHB1ENR_GPIODEN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_DISABLE)
            {
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_AHB1ENR, HAL_RCC_AHB1ENR_GPIODEN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_ENABLE)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_AHB1LPENR, HAL_RCC_AHB1LPENR_GPIODLPEN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_DISABLE)
            {
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_AHB1LPENR, HAL_RCC_AHB1LPENR_GPIODLPEN);
            }
            break;

        case HAL_RCC_PERIPHERAL_GPIOE:
            if (argConst_u8Operation == HAL_RCC_PERI_OP_RESET)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_AHB1RSTR, HAL_RCC_AHB1RSTR_GPIOERST);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_ENABLE)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_AHB1ENR, HAL_RCC_AHB1ENR_GPIOEEN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_DISABLE)
            {
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_AHB1ENR, HAL_RCC_AHB1ENR_GPIOEEN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_ENABLE)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_AHB1LPENR, HAL_RCC_AHB1LPENR_GPIOELPEN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_DISABLE)
            {
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_AHB1LPENR, HAL_RCC_AHB1LPENR_GPIOELPEN);
            }
            break;

        case HAL_RCC_PERIPHERAL_GPIOF:
            if (argConst_u8Operation == HAL_RCC_PERI_OP_RESET)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_AHB1RSTR, HAL_RCC_AHB1RSTR_GPIOFRST);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_ENABLE)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_AHB1ENR, HAL_RCC_AHB1ENR_GPIOFEN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_DISABLE)
            {
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_AHB1ENR, HAL_RCC_AHB1ENR_GPIOFEN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_ENABLE)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_AHB1LPENR, HAL_RCC_AHB1LPENR_GPIOFLPEN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_DISABLE)
            {
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_AHB1LPENR, HAL_RCC_AHB1LPENR_GPIOFLPEN);
            }
            break;

        case HAL_RCC_PERIPHERAL_GPIOG:
            if (argConst_u8Operation == HAL_RCC_PERI_OP_RESET)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_AHB1RSTR, HAL_RCC_AHB1RSTR_GPIOGRST);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_ENABLE)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_AHB1ENR, HAL_RCC_AHB1ENR_GPIOGEN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_DISABLE)
            {
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_AHB1ENR, HAL_RCC_AHB1ENR_GPIOGEN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_ENABLE)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_AHB1LPENR, HAL_RCC_AHB1LPENR_GPIOGLPEN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_DISABLE)
            {
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_AHB1LPENR, HAL_RCC_AHB1LPENR_GPIOGLPEN);
            }
            break;

        case HAL_RCC_PERIPHERAL_GPIOH:
            if (argConst_u8Operation == HAL_RCC_PERI_OP_RESET)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_AHB1RSTR, HAL_RCC_AHB1RSTR_GPIOHRST);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_ENABLE)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_AHB1ENR, HAL_RCC_AHB1ENR_GPIOHEN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_DISABLE)
            {
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_AHB1ENR, HAL_RCC_AHB1ENR_GPIOHEN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_ENABLE)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_AHB1LPENR, HAL_RCC_AHB1LPENR_GPIOHLPEN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_DISABLE)
            {
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_AHB1LPENR, HAL_RCC_AHB1LPENR_GPIOHLPEN);
            }
            break;

        case HAL_RCC_PERIPHERAL_GPIOI:
            if (argConst_u8Operation == HAL_RCC_PERI_OP_RESET)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_AHB1RSTR, HAL_RCC_AHB1RSTR_GPIOIRST);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_ENABLE)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_AHB1ENR, HAL_RCC_AHB1ENR_GPIOIEN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_DISABLE)
            {
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_AHB1ENR, HAL_RCC_AHB1ENR_GPIOIEN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_ENABLE)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_AHB1LPENR, HAL_RCC_AHB1LPENR_GPIOILPEN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_DISABLE)
            {
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_AHB1LPENR, HAL_RCC_AHB1LPENR_GPIOILPEN);
            }
            break;

        case HAL_RCC_PERIPHERAL_RNG:
            if (argConst_u8Operation == HAL_RCC_PERI_OP_RESET)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_AHB2RSTR, HAL_RCC_AHB2RSTR_RNGRST);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_ENABLE)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_AHB2ENR, HAL_RCC_AHB2ENR_RNGEN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_DISABLE)
            {
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_AHB2ENR, HAL_RCC_AHB2ENR_RNGEN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_ENABLE)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_AHB2LPENR, HAL_RCC_AHB2LPENR_RNGLPEN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_DISABLE)
            {
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_AHB2LPENR, HAL_RCC_AHB2LPENR_RNGLPEN);
            }
            break;

        case HAL_RCC_PERIPHERAL_HASH:
            if (argConst_u8Operation == HAL_RCC_PERI_OP_RESET)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_AHB2RSTR, HAL_RCC_AHB2RSTR_HASHRST);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_ENABLE)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_AHB2ENR, HAL_RCC_AHB2ENR_HASHEN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_DISABLE)
            {
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_AHB2ENR, HAL_RCC_AHB2ENR_HASHEN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_ENABLE)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_AHB2LPENR, HAL_RCC_AHB2LPENR_HASHLPEN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_DISABLE)
            {
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_AHB2LPENR, HAL_RCC_AHB2LPENR_HASHLPEN);
            }
            break;

        case HAL_RCC_PERIPHERAL_CRYPTO:
            if (argConst_u8Operation == HAL_RCC_PERI_OP_RESET)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_AHB2RSTR, HAL_RCC_AHB2RSTR_CRYPRST);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_ENABLE)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_AHB2ENR, HAL_RCC_AHB2ENR_CRYPEN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_DISABLE)
            {
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_AHB2ENR, HAL_RCC_AHB2ENR_CRYPEN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_ENABLE)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_AHB2LPENR, HAL_RCC_AHB2LPENR_CRYPLPEN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_DISABLE)
            {
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_AHB2LPENR, HAL_RCC_AHB2LPENR_CRYPLPEN);
            }
            break;

        case HAL_RCC_PERIPHERAL_CAMERA:
            if (argConst_u8Operation == HAL_RCC_PERI_OP_RESET)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_AHB2RSTR, HAL_RCC_AHB2RSTR_DCMIRST);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_ENABLE)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_AHB2ENR, HAL_RCC_AHB2ENR_DCMIEN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_DISABLE)
            {
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_AHB2ENR, HAL_RCC_AHB2ENR_DCMIEN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_ENABLE)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_AHB2LPENR, HAL_RCC_AHB2LPENR_DCMILPEN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_DISABLE)
            {
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_AHB2LPENR, HAL_RCC_AHB2LPENR_DCMILPEN);
            }
            break;

        case HAL_RCC_PERIPHERAL_FSMC:
            if (argConst_u8Operation == HAL_RCC_PERI_OP_RESET)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_AHB3RSTR, HAL_RCC_AHB3RSTR_FSMCRST);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_ENABLE)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_AHB3ENR, HAL_RCC_AHB3ENR_FSMCEN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_DISABLE)
            {
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_AHB3ENR, HAL_RCC_AHB3ENR_FSMCEN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_ENABLE)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_AHB3LPENR, HAL_RCC_AHB3LPENR_FSMCLPEN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_DISABLE)
            {
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_AHB3LPENR, HAL_RCC_AHB3LPENR_FSMCLPEN);
            }
            break;

        case HAL_RCC_PERIPHERAL_DAC:
            if (argConst_u8Operation == HAL_RCC_PERI_OP_RESET)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB1RSTR, HAL_RCC_APB1RSTR_DACRST);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_ENABLE)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB1ENR, HAL_RCC_APB1ENR_DACEN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_DISABLE)
            {
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_APB1ENR, HAL_RCC_APB1ENR_DACEN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_ENABLE)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB1LPENR, HAL_RCC_APB1LPENR_DACLPEN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_DISABLE)
            {
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_APB1LPENR, HAL_RCC_APB1LPENR_DACLPEN);
            }
            break;

        case HAL_RCC_PERIPHERAL_PWR:
            if (argConst_u8Operation == HAL_RCC_PERI_OP_RESET)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB1RSTR, HAL_RCC_APB1RSTR_PWRRST);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_ENABLE)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB1ENR, HAL_RCC_APB1ENR_PWREN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_DISABLE)
            {
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_APB1ENR, HAL_RCC_APB1ENR_PWREN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_ENABLE)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB1LPENR, HAL_RCC_APB1LPENR_PWRLPEN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_DISABLE)
            {
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_APB1LPENR, HAL_RCC_APB1LPENR_PWRLPEN);
            }
            break;

        case HAL_RCC_PERIPHERAL_CAN1:
            if (argConst_u8Operation == HAL_RCC_PERI_OP_RESET)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB1RSTR, HAL_RCC_APB1RSTR_CAN1RST);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_ENABLE)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB1ENR, HAL_RCC_APB1ENR_CAN1EN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_DISABLE)
            {
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_APB1ENR, HAL_RCC_APB1ENR_CAN1EN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_ENABLE)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB1LPENR, HAL_RCC_APB1LPENR_CAN1LPEN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_DISABLE)
            {
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_APB1LPENR, HAL_RCC_APB1LPENR_CAN1LPEN);
            }
            break;

        case HAL_RCC_PERIPHERAL_CAN2:
            if (argConst_u8Operation == HAL_RCC_PERI_OP_RESET)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB1RSTR, HAL_RCC_APB1RSTR_CAN2RST);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_ENABLE)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB1ENR, HAL_RCC_APB1ENR_CAN2EN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_DISABLE)
            {
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_APB1ENR, HAL_RCC_APB1ENR_CAN2EN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_ENABLE)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB1LPENR, HAL_RCC_APB1LPENR_CAN2LPEN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_DISABLE)
            {
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_APB1LPENR, HAL_RCC_APB1LPENR_CAN2LPEN);
            }
            break;

        case HAL_RCC_PERIPHERAL_I2C1:
            if (argConst_u8Operation == HAL_RCC_PERI_OP_RESET)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB1RSTR, HAL_RCC_APB1RSTR_I2C1RST);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_ENABLE)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB1ENR, HAL_RCC_APB1ENR_I2C1EN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_DISABLE)
            {
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_APB1ENR, HAL_RCC_APB1ENR_I2C1EN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_ENABLE)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB1LPENR, HAL_RCC_APB1LPENR_I2C1LPEN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_DISABLE)
            {
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_APB1LPENR, HAL_RCC_APB1LPENR_I2C1LPEN);
            }
            break;

        case HAL_RCC_PERIPHERAL_I2C2:
            if (argConst_u8Operation == HAL_RCC_PERI_OP_RESET)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB1RSTR, HAL_RCC_APB1RSTR_I2C2RST);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_ENABLE)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB1ENR, HAL_RCC_APB1ENR_I2C2EN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_DISABLE)
            {
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_APB1ENR, HAL_RCC_APB1ENR_I2C2EN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_ENABLE)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB1LPENR, HAL_RCC_APB1LPENR_I2C2LPEN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_DISABLE)
            {
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_APB1LPENR, HAL_RCC_APB1LPENR_I2C2LPEN);
            }
            break;

        case HAL_RCC_PERIPHERAL_I2C3:
            if (argConst_u8Operation == HAL_RCC_PERI_OP_RESET)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB1RSTR, HAL_RCC_APB1RSTR_I2C3RST);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_ENABLE)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB1ENR, HAL_RCC_APB1ENR_I2C3EN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_DISABLE)
            {
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_APB1ENR, HAL_RCC_APB1ENR_I2C3EN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_ENABLE)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB1LPENR, HAL_RCC_APB1LPENR_I2C3LPEN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_DISABLE)
            {
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_APB1LPENR, HAL_RCC_APB1LPENR_I2C3LPEN);
            }
            break;

        case HAL_RCC_PERIPHERAL_USART1:
            if (argConst_u8Operation == HAL_RCC_PERI_OP_RESET)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB2RSTR, HAL_RCC_APB2RSTR_USART1RST);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_ENABLE)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB2ENR, HAL_RCC_APB2ENR_USART1EN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_DISABLE)
            {
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_APB2ENR, HAL_RCC_APB2ENR_USART1EN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_ENABLE)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB2LPENR, HAL_RCC_APB2LPENR_USART1LPEN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_DISABLE)
            {
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_APB2LPENR, HAL_RCC_APB2LPENR_USART1LPEN);
            }
            break;

        case HAL_RCC_PERIPHERAL_USART2:
            if (argConst_u8Operation == HAL_RCC_PERI_OP_RESET)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB1RSTR, HAL_RCC_APB1RSTR_USART2RST);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_ENABLE)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB1ENR, HAL_RCC_APB1ENR_USART2EN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_DISABLE)
            {
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_APB1ENR, HAL_RCC_APB1ENR_USART2EN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_ENABLE)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB1LPENR, HAL_RCC_APB1LPENR_USART2LPEN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_DISABLE)
            {
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_APB1LPENR, HAL_RCC_APB1LPENR_USART2LPEN);
            }
            break;

        case HAL_RCC_PERIPHERAL_USART3:
            if (argConst_u8Operation == HAL_RCC_PERI_OP_RESET)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB1RSTR, HAL_RCC_APB1RSTR_USART3RST);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_ENABLE)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB1ENR, HAL_RCC_APB1ENR_USART3EN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_DISABLE)
            {
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_APB1ENR, HAL_RCC_APB1ENR_USART3EN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_ENABLE)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB1LPENR, HAL_RCC_APB1LPENR_USART3LPEN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_DISABLE)
            {
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_APB1LPENR, HAL_RCC_APB1LPENR_USART3LPEN);
            }
            break;

        case HAL_RCC_PERIPHERAL_UART4:
            if (argConst_u8Operation == HAL_RCC_PERI_OP_RESET)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB1RSTR, HAL_RCC_APB1RSTR_UART4RST);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_ENABLE)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB1ENR, HAL_RCC_APB1ENR_UART4EN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_DISABLE)
            {
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_APB1ENR, HAL_RCC_APB1ENR_UART4EN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_ENABLE)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB1LPENR, HAL_RCC_APB1LPENR_UART4LPEN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_DISABLE)
            {
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_APB1LPENR, HAL_RCC_APB1LPENR_UART4LPEN);
            }
            break;

        case HAL_RCC_PERIPHERAL_UART5:
            if (argConst_u8Operation == HAL_RCC_PERI_OP_RESET)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB1RSTR, HAL_RCC_APB1RSTR_UART5RST);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_ENABLE)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB1ENR, HAL_RCC_APB1ENR_UART5EN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_DISABLE)
            {
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_APB1ENR, HAL_RCC_APB1ENR_UART5EN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_ENABLE)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB1LPENR, HAL_RCC_APB1LPENR_UART5LPEN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_DISABLE)
            {
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_APB1LPENR, HAL_RCC_APB1LPENR_UART5LPEN);
            }
            break;

        case HAL_RCC_PERIPHERAL_USART6:
            if (argConst_u8Operation == HAL_RCC_PERI_OP_RESET)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB2RSTR, HAL_RCC_APB2RSTR_USART6RST);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_ENABLE)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB2ENR, HAL_RCC_APB2ENR_USART6EN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_DISABLE)
            {
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_APB2ENR, HAL_RCC_APB2ENR_USART6EN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_ENABLE)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB2LPENR, HAL_RCC_APB2LPENR_USART6LPEN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_DISABLE)
            {
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_APB2LPENR, HAL_RCC_APB2LPENR_USART6LPEN);
            }
            break;

        case HAL_RCC_PERIPHERAL_SPI1:
            if (argConst_u8Operation == HAL_RCC_PERI_OP_RESET)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB2RSTR, HAL_RCC_APB2RSTR_SPI1RST);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_ENABLE)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB2ENR, HAL_RCC_APB2ENR_SPI1EN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_DISABLE)
            {
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_APB2ENR, HAL_RCC_APB2ENR_SPI1EN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_ENABLE)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB2LPENR, HAL_RCC_APB2LPENR_SPI1LPEN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_DISABLE)
            {
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_APB2LPENR, HAL_RCC_APB2LPENR_SPI1LPEN);
            }
            break;

        case HAL_RCC_PERIPHERAL_SPI2:
            if (argConst_u8Operation == HAL_RCC_PERI_OP_RESET)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB1RSTR, HAL_RCC_APB1RSTR_SPI2RST);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_ENABLE)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB1ENR, HAL_RCC_APB1ENR_SPI2EN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_DISABLE)
            {
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_APB1ENR, HAL_RCC_APB1ENR_SPI2EN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_ENABLE)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB1LPENR, HAL_RCC_APB1LPENR_SPI2LPEN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_DISABLE)
            {
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_APB1LPENR, HAL_RCC_APB1LPENR_SPI2LPEN);
            }
            break;

        case HAL_RCC_PERIPHERAL_SPI3:
            if (argConst_u8Operation == HAL_RCC_PERI_OP_RESET)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB1RSTR, HAL_RCC_APB1RSTR_SPI3RST);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_ENABLE)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB1ENR, HAL_RCC_APB1ENR_SPI3EN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_DISABLE)
            {
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_APB1ENR, HAL_RCC_APB1ENR_SPI3EN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_ENABLE)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB1LPENR, HAL_RCC_APB1LPENR_SPI3LPEN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_DISABLE)
            {
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_APB1LPENR, HAL_RCC_APB1LPENR_SPI3LPEN);
            }
            break;

        case HAL_RCC_PERIPHERAL_WWDG:
            if (argConst_u8Operation == HAL_RCC_PERI_OP_RESET)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB1RSTR, HAL_RCC_APB1RSTR_WWDGRST);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_ENABLE)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB1ENR, HAL_RCC_APB1ENR_WWDGEN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_DISABLE)
            {
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_APB1ENR, HAL_RCC_APB1ENR_WWDGEN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_ENABLE)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB1LPENR, HAL_RCC_APB1LPENR_WWDGLPEN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_DISABLE)
            {
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_APB1LPENR, HAL_RCC_APB1LPENR_WWDGLPEN);
            }
            break;

        case HAL_RCC_PERIPHERAL_TIM1:
            if (argConst_u8Operation == HAL_RCC_PERI_OP_RESET)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB2RSTR, HAL_RCC_APB2RSTR_TIM1RST);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_ENABLE)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB2ENR, HAL_RCC_APB2ENR_TIM1EN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_DISABLE)
            {
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_APB2ENR, HAL_RCC_APB2ENR_TIM1EN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_ENABLE)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB2LPENR, HAL_RCC_APB2LPENR_TIM1LPEN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_DISABLE)
            {
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_APB2LPENR, HAL_RCC_APB2LPENR_TIM1LPEN);
            }
            break;

        case HAL_RCC_PERIPHERAL_TIM2:
            if (argConst_u8Operation == HAL_RCC_PERI_OP_RESET)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB1RSTR, HAL_RCC_APB1RSTR_TIM2RST);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_ENABLE)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB1ENR, HAL_RCC_APB1ENR_TIM2EN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_DISABLE)
            {
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_APB1ENR, HAL_RCC_APB1ENR_TIM2EN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_ENABLE)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB1LPENR, HAL_RCC_APB1LPENR_TIM2LPEN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_DISABLE)
            {
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_APB1LPENR, HAL_RCC_APB1LPENR_TIM2LPEN);
            }
            break;

        case HAL_RCC_PERIPHERAL_TIM3:
            if (argConst_u8Operation == HAL_RCC_PERI_OP_RESET)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB1RSTR, HAL_RCC_APB1RSTR_TIM3RST);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_ENABLE)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB1ENR, HAL_RCC_APB1ENR_TIM3EN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_DISABLE)
            {
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_APB1ENR, HAL_RCC_APB1ENR_TIM3EN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_ENABLE)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB1LPENR, HAL_RCC_APB1LPENR_TIM3LPEN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_DISABLE)
            {
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_APB1LPENR, HAL_RCC_APB1LPENR_TIM3LPEN);
            }
            break;

        case HAL_RCC_PERIPHERAL_TIM4:
            if (argConst_u8Operation == HAL_RCC_PERI_OP_RESET)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB1RSTR, HAL_RCC_APB1RSTR_TIM4RST);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_ENABLE)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB1ENR, HAL_RCC_APB1ENR_TIM4EN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_DISABLE)
            {
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_APB1ENR, HAL_RCC_APB1ENR_TIM4EN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_ENABLE)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB1LPENR, HAL_RCC_APB1LPENR_TIM4LPEN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_DISABLE)
            {
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_APB1LPENR, HAL_RCC_APB1LPENR_TIM4LPEN);
            }
            break;

        case HAL_RCC_PERIPHERAL_TIM5:
            if (argConst_u8Operation == HAL_RCC_PERI_OP_RESET)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB1RSTR, HAL_RCC_APB1RSTR_TIM5RST);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_ENABLE)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB1ENR, HAL_RCC_APB1ENR_TIM5EN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_DISABLE)
            {
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_APB1ENR, HAL_RCC_APB1ENR_TIM5EN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_ENABLE)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB1LPENR, HAL_RCC_APB1LPENR_TIM5LPEN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_DISABLE)
            {
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_APB1LPENR, HAL_RCC_APB1LPENR_TIM5LPEN);
            }
            break;

        case HAL_RCC_PERIPHERAL_TIM6:
            if (argConst_u8Operation == HAL_RCC_PERI_OP_RESET)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB1RSTR, HAL_RCC_APB1RSTR_TIM6RST);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_ENABLE)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB1ENR, HAL_RCC_APB1ENR_TIM6EN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_DISABLE)
            {
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_APB1ENR, HAL_RCC_APB1ENR_TIM6EN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_ENABLE)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB1LPENR, HAL_RCC_APB1LPENR_TIM6LPEN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_DISABLE)
            {
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_APB1LPENR, HAL_RCC_APB1LPENR_TIM6LPEN);
            }
            break;

        case HAL_RCC_PERIPHERAL_TIM7:
            if (argConst_u8Operation == HAL_RCC_PERI_OP_RESET)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB1RSTR, HAL_RCC_APB1RSTR_TIM7RST);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_ENABLE)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB1ENR, HAL_RCC_APB1ENR_TIM7EN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_DISABLE)
            {
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_APB1ENR, HAL_RCC_APB1ENR_TIM7EN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_ENABLE)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB1LPENR, HAL_RCC_APB1LPENR_TIM7LPEN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_DISABLE)
            {
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_APB1LPENR, HAL_RCC_APB1LPENR_TIM7LPEN);
            }
            break;

        case HAL_RCC_PERIPHERAL_TIM8:
            if (argConst_u8Operation == HAL_RCC_PERI_OP_RESET)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB2RSTR, HAL_RCC_APB2RSTR_TIM8RST);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_ENABLE)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB2ENR, HAL_RCC_APB2ENR_TIM8EN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_DISABLE)
            {
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_APB2ENR, HAL_RCC_APB2ENR_TIM8EN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_ENABLE)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB2LPENR, HAL_RCC_APB2LPENR_TIM8LPEN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_DISABLE)
            {
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_APB2LPENR, HAL_RCC_APB2LPENR_TIM8LPEN);
            }
            break;

        case HAL_RCC_PERIPHERAL_TIM9:
            if (argConst_u8Operation == HAL_RCC_PERI_OP_RESET)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB2RSTR, HAL_RCC_APB2RSTR_TIM9RST);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_ENABLE)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB2ENR, HAL_RCC_APB2ENR_TIM9EN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_DISABLE)
            {
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_APB2ENR, HAL_RCC_APB2ENR_TIM9EN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_ENABLE)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB2LPENR, HAL_RCC_APB2LPENR_TIM9LPEN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_DISABLE)
            {
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_APB2LPENR, HAL_RCC_APB2LPENR_TIM9LPEN);
            }
            break;

        case HAL_RCC_PERIPHERAL_TIM10:
            if (argConst_u8Operation == HAL_RCC_PERI_OP_RESET)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB2RSTR, HAL_RCC_APB2RSTR_TIM10RST);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_ENABLE)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB2ENR, HAL_RCC_APB2ENR_TIM10EN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_DISABLE)
            {
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_APB2ENR, HAL_RCC_APB2ENR_TIM10EN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_ENABLE)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB2LPENR, HAL_RCC_APB2LPENR_TIM10LPEN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_DISABLE)
            {
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_APB2LPENR, HAL_RCC_APB2LPENR_TIM10LPEN);
            }
            break;

        case HAL_RCC_PERIPHERAL_TIM11:
            if (argConst_u8Operation == HAL_RCC_PERI_OP_RESET)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB2RSTR, HAL_RCC_APB2RSTR_TIM11RST);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_ENABLE)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB2ENR, HAL_RCC_APB2ENR_TIM11EN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_DISABLE)
            {
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_APB2ENR, HAL_RCC_APB2ENR_TIM11EN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_ENABLE)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB2LPENR, HAL_RCC_APB2LPENR_TIM11LPEN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_DISABLE)
            {
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_APB2LPENR, HAL_RCC_APB2LPENR_TIM11LPEN);
            }
            break;

        case HAL_RCC_PERIPHERAL_TIM12:
            if (argConst_u8Operation == HAL_RCC_PERI_OP_RESET)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB1RSTR, HAL_RCC_APB1RSTR_TIM12RST);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_ENABLE)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB1ENR, HAL_RCC_APB1ENR_TIM12EN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_DISABLE)
            {
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_APB1ENR, HAL_RCC_APB1ENR_TIM12EN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_ENABLE)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB1LPENR, HAL_RCC_APB1LPENR_TIM12LPEN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_DISABLE)
            {
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_APB1LPENR, HAL_RCC_APB1LPENR_TIM12LPEN);
            }
            break;

        case HAL_RCC_PERIPHERAL_TIM13:
            if (argConst_u8Operation == HAL_RCC_PERI_OP_RESET)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB1RSTR, HAL_RCC_APB1RSTR_TIM13RST);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_ENABLE)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB1ENR, HAL_RCC_APB1ENR_TIM13EN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_DISABLE)
            {
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_APB1ENR, HAL_RCC_APB1ENR_TIM13EN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_ENABLE)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB1LPENR, HAL_RCC_APB1LPENR_TIM13LPEN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_DISABLE)
            {
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_APB1LPENR, HAL_RCC_APB1LPENR_TIM13LPEN);
            }
            break;

        case HAL_RCC_PERIPHERAL_TIM14:
            if (argConst_u8Operation == HAL_RCC_PERI_OP_RESET)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB1RSTR, HAL_RCC_APB1RSTR_TIM14RST);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_ENABLE)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB1ENR, HAL_RCC_APB1ENR_TIM14EN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_DISABLE)
            {
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_APB1ENR, HAL_RCC_APB1ENR_TIM14EN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_ENABLE)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB1LPENR, HAL_RCC_APB1LPENR_TIM14LPEN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_DISABLE)
            {
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_APB1LPENR, HAL_RCC_APB1LPENR_TIM14LPEN);
            }
            break;

        case HAL_RCC_PERIPHERAL_SYS_CFG:
            if (argConst_u8Operation == HAL_RCC_PERI_OP_RESET)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB2RSTR, HAL_RCC_APB2RSTR_SYSCFGRST);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_ENABLE)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB2ENR, HAL_RCC_APB2ENR_SYSCFGEN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_DISABLE)
            {
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_APB2ENR, HAL_RCC_APB2ENR_SYSCFGEN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_ENABLE)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB2LPENR, HAL_RCC_APB2LPENR_SYSCFGLPEN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_DISABLE)
            {
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_APB2LPENR, HAL_RCC_APB2LPENR_SYSCFGLPEN);
            }
            break;

        case HAL_RCC_PERIPHERAL_SDIO:
            if (argConst_u8Operation == HAL_RCC_PERI_OP_RESET)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB2RSTR, HAL_RCC_APB2RSTR_SDIORST);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_ENABLE)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB2ENR, HAL_RCC_APB2ENR_SDIOEN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_DISABLE)
            {
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_APB2ENR, HAL_RCC_APB2ENR_SDIOEN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_ENABLE)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB2LPENR, HAL_RCC_APB2LPENR_SDIOLPEN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_DISABLE)
            {
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_APB2LPENR, HAL_RCC_APB2LPENR_SDIOLPEN);
            }
            break;

        case HAL_RCC_PERIPHERAL_ADC1:
            if (argConst_u8Operation == HAL_RCC_PERI_OP_RESET)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB2RSTR, HAL_RCC_APB2RSTR_ADCRST);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_ENABLE)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB2ENR, HAL_RCC_APB2ENR_ADC1EN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_DISABLE)
            {
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_APB2ENR, HAL_RCC_APB2ENR_ADC1EN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_ENABLE)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB2LPENR, HAL_RCC_APB2LPENR_ADC1LPEN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_DISABLE)
            {
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_APB2LPENR, HAL_RCC_APB2LPENR_ADC1LPEN);
            }
            break;

        case HAL_RCC_PERIPHERAL_ADC2:
            if (argConst_u8Operation == HAL_RCC_PERI_OP_RESET)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB2RSTR, HAL_RCC_APB2RSTR_ADCRST);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_ENABLE)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB2ENR, HAL_RCC_APB2ENR_ADC2EN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_DISABLE)
            {
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_APB2ENR, HAL_RCC_APB2ENR_ADC2EN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_ENABLE)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB2LPENR, HAL_RCC_APB2LPENR_ADC2LPEN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_DISABLE)
            {
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_APB2LPENR, HAL_RCC_APB2LPENR_ADC2LPEN);
            }
            break;

        case HAL_RCC_PERIPHERAL_ADC3:
            if (argConst_u8Operation == HAL_RCC_PERI_OP_RESET)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB2RSTR, HAL_RCC_APB2RSTR_ADCRST);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_ENABLE)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB2ENR, HAL_RCC_APB2ENR_ADC3EN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_DISABLE)
            {
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_APB2ENR, HAL_RCC_APB2ENR_ADC3EN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_ENABLE)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB2LPENR, HAL_RCC_APB2LPENR_ADC3LPEN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_DISABLE)
            {
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_APB2LPENR, HAL_RCC_APB2LPENR_ADC3LPEN);
            }
            break;

        case HAL_RCC_PERIPHERAL_FLASH_MEM:
            if (argConst_u8Operation == HAL_RCC_PERI_OP_RESET)
            {
                // do nothing
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_ENABLE)
            {
                // do nothing
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_DISABLE)
            {
                // do nothing
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_ENABLE)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_AHB1LPENR, HAL_RCC_AHB1LPENR_FLITFLPEN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_DISABLE)
            {
                LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_AHB1LPENR, HAL_RCC_AHB1LPENR_FLITFLPEN);
            }
            break;

        case HAL_RCC_PERIPHERAL_RTC:
            if (argConst_u8Operation == HAL_RCC_PERI_OP_RESET)
            {
                // do nothing
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_ENABLE)
            {
                LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_BDCR, HAL_RCC_BDCR_RTCEN);
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_DISABLE)
            {
                // do nothing (TODO: edit this line)
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_ENABLE)
            {
                // do nothing
            }
            else if (argConst_u8Operation == HAL_RCC_PERI_OP_LOW_PWR_DISABLE)
            {
                // do nothing
            }
            break;

        default:
            break;
        }
    }

    return local_errState;
}

/**
 *
 */
HAL_RCC_ErrStates_t HAL_RCC_GetSystemResetType(uint8_t * const arg_Constpu8Value)
{
    // local used variables
    HAL_RCC_ErrStates_t local_errState = HAL_RCC_OK;

    // check for errors
    if (arg_Constpu8Value == NULL)
    {
        local_errState = HAL_RCC_ERR_INVALID_PARAMS;
    }

    // main function
    if (local_errState == HAL_RCC_OK)
    {
        if (LIB_MATH_BTT_GET_BIT(global_pRCCReg_t->RCC_CSR, HAL_RCC_CSR_LPWRRSTF) == 1)
        {
            *arg_Constpu8Value = HAL_RCC_RESET_CAUSE_LOW_POWER;
        }
        else if (LIB_MATH_BTT_GET_BIT(global_pRCCReg_t->RCC_CSR, HAL_RCC_CSR_WWDGRSTF) == 1)
        {
            *arg_Constpu8Value = HAL_RCC_RESET_CAUSE_WINDOW_WATCHDOG;
        }
        else if (LIB_MATH_BTT_GET_BIT(global_pRCCReg_t->RCC_CSR, HAL_RCC_CSR_IWDGRSTF) == 1)
        {
            *arg_Constpu8Value = HAL_RCC_RESET_CAUSE_INDEPENDEDNT_WATCHDOG;
        }
        else if (LIB_MATH_BTT_GET_BIT(global_pRCCReg_t->RCC_CSR, HAL_RCC_CSR_IWDGRSTF) == 1)
        {
            *arg_Constpu8Value = HAL_RCC_RESET_CAUSE_SOFTWARE;
        }
        else if (LIB_MATH_BTT_GET_BIT(global_pRCCReg_t->RCC_CSR, HAL_RCC_CSR_PORRSTF) == 1)
        {
            *arg_Constpu8Value = HAL_RCC_RESET_CAUSE_POR_PDR;
        }
        else if (LIB_MATH_BTT_GET_BIT(global_pRCCReg_t->RCC_CSR, HAL_RCC_CSR_PINRSTF) == 1)
        {
            *arg_Constpu8Value = HAL_RCC_RESET_CAUSE_PIN;
        }
        else if (LIB_MATH_BTT_GET_BIT(global_pRCCReg_t->RCC_CSR, HAL_RCC_CSR_BORRSTF) == 1)
        {
            *arg_Constpu8Value = HAL_RCC_RESET_CAUSE_BOR;
        }
        else
        {
            *arg_Constpu8Value = HAL_RCC_NO_RESET_HAPPENED;
        }

        LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_CSR, HAL_RCC_CSR_RMVF);
    }

    return local_errState;
}

/**
 *
 */
HAL_RCC_ErrStates_t HAL_RCC_GetPeripheralInputFrequency(const uint8_t argConst_u8PeripheralName, uint32_t *const arg_Constpu32Value)
{
    // local used variables
    HAL_RCC_ErrStates_t local_errState = HAL_RCC_OK;

    // check for errors
    if (arg_Constpu32Value == NULL || argConst_u8PeripheralName >= HAL_RCC_MAX_PERIPHERAL)
    {
        local_errState = HAL_RCC_ERR_INVALID_PARAMS;
    }
    else
    {
        // do nothing
    }

    // main function
    if (local_errState == HAL_RCC_OK)
    {
        // TODO: add support for ethernet

        // AHB
        if (argConst_u8PeripheralName == HAL_RCC_PERIPHERAL_FSMC ||
            argConst_u8PeripheralName == HAL_RCC_PERIPHERAL_RNG ||
            argConst_u8PeripheralName == HAL_RCC_PERIPHERAL_HASH ||
            argConst_u8PeripheralName == HAL_RCC_PERIPHERAL_CRYPTO ||
            argConst_u8PeripheralName == HAL_RCC_PERIPHERAL_CAMERA ||
            argConst_u8PeripheralName == HAL_RCC_PERIPHERAL_USB_OTG ||
            argConst_u8PeripheralName == HAL_RCC_PERIPHERAL_DMA1 ||
            argConst_u8PeripheralName == HAL_RCC_PERIPHERAL_DMA2 ||
            argConst_u8PeripheralName == HAL_RCC_PERIPHERAL_BKP_SRAM ||
            argConst_u8PeripheralName == HAL_RCC_PERIPHERAL_CRC ||
            argConst_u8PeripheralName == HAL_RCC_PERIPHERAL_GPIOA ||
            argConst_u8PeripheralName == HAL_RCC_PERIPHERAL_GPIOB ||
            argConst_u8PeripheralName == HAL_RCC_PERIPHERAL_GPIOC ||
            argConst_u8PeripheralName == HAL_RCC_PERIPHERAL_GPIOD ||
            argConst_u8PeripheralName == HAL_RCC_PERIPHERAL_GPIOE ||
            argConst_u8PeripheralName == HAL_RCC_PERIPHERAL_GPIOF ||
            argConst_u8PeripheralName == HAL_RCC_PERIPHERAL_GPIOG ||
            argConst_u8PeripheralName == HAL_RCC_PERIPHERAL_GPIOI ||
            argConst_u8PeripheralName == HAL_RCC_PERIPHERAL_CCM ||
            argConst_u8PeripheralName == HAL_RCC_PERIPHERAL_FLASH_MEM ||
            argConst_u8PeripheralName == HAL_RCC_PERIPHERAL_SRAM1 ||
            argConst_u8PeripheralName == HAL_RCC_PERIPHERAL_SRAM2)
        {
            *arg_Constpu32Value = global_u32SystemClock / globalConstArr_RCC_SYSCLK_ClockConfig_t[0].SYSCLK_to_AHB_Prescalar;
        }

        // APB2
        else if (argConst_u8PeripheralName == HAL_RCC_PERIPHERAL_TIM11 ||
                 argConst_u8PeripheralName == HAL_RCC_PERIPHERAL_TIM10 ||
                 argConst_u8PeripheralName == HAL_RCC_PERIPHERAL_TIM9 ||
                 argConst_u8PeripheralName == HAL_RCC_PERIPHERAL_SYS_CFG ||
                 argConst_u8PeripheralName == HAL_RCC_PERIPHERAL_SPI1 ||
                 argConst_u8PeripheralName == HAL_RCC_PERIPHERAL_SDIO ||
                 argConst_u8PeripheralName == HAL_RCC_PERIPHERAL_ADC1 ||
                 argConst_u8PeripheralName == HAL_RCC_PERIPHERAL_ADC2 ||
                 argConst_u8PeripheralName == HAL_RCC_PERIPHERAL_ADC3 ||
                 argConst_u8PeripheralName == HAL_RCC_PERIPHERAL_USART6 ||
                 argConst_u8PeripheralName == HAL_RCC_PERIPHERAL_USART1 ||
                 argConst_u8PeripheralName == HAL_RCC_PERIPHERAL_TIM8 ||
                 argConst_u8PeripheralName == HAL_RCC_PERIPHERAL_TIM1)
        {
            *arg_Constpu32Value = global_u32SystemClock / (globalConstArr_RCC_SYSCLK_ClockConfig_t[0].SYSCLK_to_AHB_Prescalar * globalConstArr_RCC_SYSCLK_ClockConfig_t[0].AHB_to_APB2_Prescalar);
        }

        // APB1
        else if (argConst_u8PeripheralName == HAL_RCC_PERIPHERAL_DAC ||
                 argConst_u8PeripheralName == HAL_RCC_PERIPHERAL_PWR ||
                 argConst_u8PeripheralName == HAL_RCC_PERIPHERAL_CAN1 ||
                 argConst_u8PeripheralName == HAL_RCC_PERIPHERAL_CAN2 ||
                 argConst_u8PeripheralName == HAL_RCC_PERIPHERAL_I2C1 ||
                 argConst_u8PeripheralName == HAL_RCC_PERIPHERAL_I2C2 ||
                 argConst_u8PeripheralName == HAL_RCC_PERIPHERAL_I2C3 ||
                 argConst_u8PeripheralName == HAL_RCC_PERIPHERAL_UART5 ||
                 argConst_u8PeripheralName == HAL_RCC_PERIPHERAL_UART4 ||
                 argConst_u8PeripheralName == HAL_RCC_PERIPHERAL_USART3 ||
                 argConst_u8PeripheralName == HAL_RCC_PERIPHERAL_USART2 ||
                 argConst_u8PeripheralName == HAL_RCC_PERIPHERAL_SPI2 ||
                 argConst_u8PeripheralName == HAL_RCC_PERIPHERAL_SPI3 ||
                 argConst_u8PeripheralName == HAL_RCC_PERIPHERAL_WWDG ||
                 argConst_u8PeripheralName == HAL_RCC_PERIPHERAL_TIM14 ||
                 argConst_u8PeripheralName == HAL_RCC_PERIPHERAL_TIM13 ||
                 argConst_u8PeripheralName == HAL_RCC_PERIPHERAL_TIM12 ||
                 argConst_u8PeripheralName == HAL_RCC_PERIPHERAL_TIM7 ||
                 argConst_u8PeripheralName == HAL_RCC_PERIPHERAL_TIM6 ||
                 argConst_u8PeripheralName == HAL_RCC_PERIPHERAL_TIM5 ||
                 argConst_u8PeripheralName == HAL_RCC_PERIPHERAL_TIM4 ||
                 argConst_u8PeripheralName == HAL_RCC_PERIPHERAL_TIM3 ||
                 argConst_u8PeripheralName == HAL_RCC_PERIPHERAL_TIM2)
        {
            *arg_Constpu32Value = global_u32SystemClock / (globalConstArr_RCC_SYSCLK_ClockConfig_t[0].SYSCLK_to_AHB_Prescalar * globalConstArr_RCC_SYSCLK_ClockConfig_t[0].AHB_to_APB1_Prescalar);
        }
        else if (argConst_u8PeripheralName == HAL_RCC_PERIPHERAL_RTC)
        {
            if (globalConstArr_RCC_RTC_ClockConfig_t[0].RTCClockSource == HAL_RCC_RTC_CLK_SRC_LSI)
            {
                *arg_Constpu32Value = HAL_RCC_LSI_SPEED;
            }
            else if (globalConstArr_RCC_RTC_ClockConfig_t[0].RTCClockSource == HAL_RCC_RTC_CLK_SRC_LSE)
            {
                *arg_Constpu32Value = HAL_RCC_LSE_SPEED;
            }
            else if (globalConstArr_RCC_RTC_ClockConfig_t[0].RTCClockSource == HAL_RCC_RTC_CLK_SRC_HSE)
            {
                *arg_Constpu32Value = global_u32HSEtoRTCClk;
            }
        }
        else
        {
            // do nothing
        }
    }

    return local_errState;
}

/**
 *
 */
HAL_RCC_ErrStates_t HAL_RCC_RegisterCallback(const uint8_t argConst_u8CallBackType, const functionCallBack_t argConst_pFunctionCallBack)
{
    // local used variables
    HAL_RCC_ErrStates_t local_errState = HAL_RCC_OK;

    // check for errors
    if (argConst_u8CallBackType >= HAL_RCC_MAX_CALLBACK_TYPE || argConst_pFunctionCallBack == NULL)
    {
        local_errState = HAL_RCC_ERR_INVALID_PARAMS;
    }

    // main function
    if (local_errState == HAL_RCC_OK)
    {
        if (argConst_u8CallBackType == HAL_RCC_CALLBACK_CLOCK_SECURITY)
        {
            global_pClockUnstableCallBack_t = argConst_pFunctionCallBack;
        }
        else
        {
            // do nothing
        }
    }

    return local_errState;
}

/**
 * @brief: interrupt handler for RCC module
 */
void RCC_IRQHandler(void)
{
    // check if interrupt due to unstable clock
    if (LIB_MATH_BTT_GET_BIT(global_pRCCReg_t->RCC_CIR, HAL_RCC_CIR_CSSF) == 1)
    {
        LIB_MATH_BTT_CLR_BIT(global_pRCCReg_t->RCC_CIR, HAL_RCC_CIR_CSSC);
        if (global_pClockUnstableCallBack_t != NULL)
        {
            global_pClockUnstableCallBack_t();
        }
    }
}

/*************** END OF FUNCTIONS ***************************************************************************/
