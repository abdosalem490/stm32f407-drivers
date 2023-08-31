/**
 * --------------------------------------------------------------------------------------------------------------------------------------
 * |    @title          :   power controller                                                                                            |
 * |    @file           :   PWR_header.h                                                                                                |
 * |    @author         :   Abdelrahman Mohamed Salem                                                                                   |
 * |    @origin_date    :   12/08/2023                                                                                                  |
 * |    @version        :   1.0.0                                                                                                       |
 * |    @tool_chain     :   GNU Tools for STM32                                                                                         |
 * |    @compiler       :   GCC                                                                                                         |
 * |    @C_standard     :   ISO C99 (-std=c99)                                                                                          |
 * |    @target         :   stm32f407VGTX                                                                                               |
 * |    @notes          :   None                                                                                                        |
 * |    @license        :   MIT License                                                                                                 |
 * |    @brief          :   this header file contains functions implementations regarding the embedded embedded power controller        |
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
 * |    12/08/2023      1.0.0           Abdelrahman Mohamed Salem       Interface Created.                                              |
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
 * @reason: contains all initial user configurations for PWR
 */
#include "PWR_config.h"

/**
 * @reason: contains all the interface functions to be implemented
 */
#include "PWR_header.h"

/**
 * @reason: contains all register addresses and bit definitions for embedded PWR configuration registers
 */
#include "PWR_reg.h"

/**
 * @reason: contains all private function declaration and global variables
 */
#include "PWR_private.h"

/**
 * @reason: contains sleep modes bits related
 */
#include "../CM4F/CM4F_reg.h"

/**
 * @reason: contains sleep assembly functions
 */
#include "../CM4F/CM4F_header.h"

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
HAL_PWR_ErrStates_t HAL_PWR_Init()
{
    // local used variables
    HAL_PWR_ErrStates_t local_errState_t = HAL_PWR_OK;
    uint32_t local_u32TempReg = 0;

    // validate configurations
    if (globalConstArr_PWRConfig_t[0].MaxHCLKFreq >= HAL_PWR_MAX_HCLK ||
        globalConstArr_PWRConfig_t[0].FlashPowerDown >= LIB_CONSTANTS_MAX_DRIVER_STATE ||
        globalConstArr_PWRConfig_t[0].PVDEnable >= LIB_CONSTANTS_MAX_DRIVER_STATE ||
        globalConstArr_PWRConfig_t[0].PVDLevel >= HAL_PWR_MAX_PVD_LEVEL ||
        globalConstArr_PWRConfig_t[0].BackUpEnable >= LIB_CONSTANTS_MAX_DRIVER_STATE ||
        globalConstArr_PWRConfig_t[0].WakeUpPinEnable >= LIB_CONSTANTS_MAX_DRIVER_STATE ||
        globalConstArr_PWRConfig_t[0].SleepEnterMethod >= HAL_PWR_MAX_VAL_SLEEP_METHOD ||
        globalConstArr_PWRConfig_t[0].SleepOnExitFromISREnable >= LIB_CONSTANTS_MAX_DRIVER_STATE)
    {
        local_errState_t = HAL_PWR_ERR_INVALID_CONFIG;
    }
    else
    {
        // do nothing
    }

    // main function
    if (local_errState_t == HAL_PWR_OK)
    {
        // assign global variable configurations
        global_u8SleepMethod = globalConstArr_PWRConfig_t[0].SleepEnterMethod;

        // configure PWR power control register (PWR_CR)
        local_u32TempReg = global_pPWRReg_t->PWR_CR;
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_PWR_CR_VOS, globalConstArr_PWRConfig_t[0].MaxHCLKFreq);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_PWR_CR_FPDS, globalConstArr_PWRConfig_t[0].FlashPowerDown);
        LIB_MATH_BTT_ASSIGN_BITS(local_u32TempReg, HAL_PWR_CR_PLS, globalConstArr_PWRConfig_t[0].PVDLevel, 3);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_PWR_CR_PVDE, globalConstArr_PWRConfig_t[0].PVDEnable);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_PWR_CR_LPDS, globalConstArr_PWRConfig_t[0].RegulatorPowerDown);
        global_pPWRReg_t->PWR_CR = local_u32TempReg;

        // configure PWR power control/status register (PWR_CSR)
        local_u32TempReg = global_pPWRReg_t->PWR_CSR;
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_PWR_CSR_BRE, globalConstArr_PWRConfig_t[0].BackUpEnable);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_PWR_CSR_EWUP, globalConstArr_PWRConfig_t[0].WakeUpPinEnable);
        LIB_MATH_BTT_ASSIGN_BIT(local_u32TempReg, HAL_PWR_CSR_BRE, globalConstArr_PWRConfig_t[0].BackUpEnable);
        global_pPWRReg_t->PWR_CSR = local_u32TempReg;

        // configure System control register (SCR)
        HAL_CM4F_CONFIGURE_SLEEP_ON_EXIT(globalConstArr_PWRConfig_t[0].SleepOnExitFromISREnable);
    }

    return local_errState_t;
}

/**
 *
 */
HAL_PWR_ErrStates_t HAL_PWR_EnterMode(const uint8_t argConst_u8Mode)
{
    // local used variables
    HAL_PWR_ErrStates_t local_errState_t = HAL_PWR_OK;

    // validate parameters
    if (argConst_u8Mode >= HAL_PWR_MAX_MODE)
    {
        local_errState_t = HAL_PWR_ERR_INVALID_PARAMS;
    }

    // main function
    if (local_errState_t == HAL_PWR_OK)
    {
        // check which mode to switch to
        if (argConst_u8Mode == HAL_MODE_RUN)
        {
            /* code */
        }
        else if (argConst_u8Mode == HAL_MODE_SLEEP)
        {
            HAL_CM4F_CONFIGURE_SLEEPDEEP(LIB_CONSTANTS_DISABLED);
            if (global_u8SleepMethod == HAL_PWR_VAL_SLEEP_METHOD_WFE)
            {
                HAL_CM4F_WAIT_FOR_EVENT();
            }
            else if (global_u8SleepMethod == HAL_PWR_VAL_SLEEP_METHOD_WFI)
            {
                HAL_CM4F_WAIT_FOR_INTERRUPT();
            }
            else
            {
                // do nothing
            }
        }
        else if (argConst_u8Mode == HAL_MODE_STOP)
        {
            HAL_CM4F_CONFIGURE_SLEEPDEEP(LIB_CONSTANTS_ENABLED);
            LIB_MATH_BTT_CLR_BIT(global_pPWRReg_t->PWR_CR, HAL_PWR_CR_PDDS);
            if (global_u8SleepMethod == HAL_PWR_VAL_SLEEP_METHOD_WFE)
            {
                HAL_CM4F_WAIT_FOR_EVENT();
            }
            else if (global_u8SleepMethod == HAL_PWR_VAL_SLEEP_METHOD_WFI)
            {
                HAL_CM4F_WAIT_FOR_INTERRUPT();
            }
            else
            {
                // do nothing
            }
        }
        else if (argConst_u8Mode == HAL_MODE_STANDBY)
        {
            HAL_CM4F_CONFIGURE_SLEEPDEEP(LIB_CONSTANTS_ENABLED);
            LIB_MATH_BTT_SET_BIT(global_pPWRReg_t->PWR_CR, HAL_PWR_CR_PDDS);
            LIB_MATH_BTT_SET_BIT(global_pPWRReg_t->PWR_CR, HAL_PWR_CR_CWUF);

            if (global_u8SleepMethod == HAL_PWR_VAL_SLEEP_METHOD_WFE)
            {
                HAL_CM4F_WAIT_FOR_EVENT();
            }
            else if (global_u8SleepMethod == HAL_PWR_VAL_SLEEP_METHOD_WFI)
            {
                HAL_CM4F_WAIT_FOR_INTERRUPT();
            }
            else
            {
                // do nothing
            }
        }
        else
        {
            // do nothing
        }
    }

    return local_errState_t;
}

/**
 *
 */
HAL_PWR_ErrStates_t HAL_PWR_Config(const uint8_t argConst_u8Key, const uint8_t argConst_u8Value)
{
    // local used variables
    HAL_PWR_ErrStates_t local_errState_t = HAL_PWR_OK;

    // validate inputs
    if (argConst_u8Key >= HAL_PWR_MAX_CONFIG_KEYS)
    {
        local_errState_t = HAL_PWR_ERR_INVALID_PARAMS;
    }
    else
    {
        if ((argConst_u8Key == HAL_PWR_KEY_SLEEP_METHOD && argConst_u8Value >= HAL_PWR_MAX_VAL_SLEEP_METHOD) ||
            (argConst_u8Key == HAL_PWR_KEY_SLEEP_EXIT_ISR_ENABLE && argConst_u8Value >= LIB_CONSTANTS_MAX_DRIVER_STATE))
        {
            local_errState_t = HAL_PWR_ERR_INVALID_PARAMS;
        }
        else
        {
            // do nothing
        }
    }

    // main function
    if (local_errState_t == HAL_PWR_OK)
    {
        if (argConst_u8Key == HAL_PWR_KEY_SLEEP_METHOD)
        {
            global_u8SleepMethod = argConst_u8Value;
        }
        else if (argConst_u8Key == HAL_PWR_KEY_SLEEP_EXIT_ISR_ENABLE)
        {
            HAL_CM4F_CONFIGURE_SLEEP_ON_EXIT(argConst_u8Value);
        }
    }

    return local_errState_t;
}

/**
 *
 */
HAL_PWR_ErrStates_t HAL_PWR_RegisterCallback(const uint8_t argConst_u8CallBackType, const functionCallBack_t argConst_pFunctionCallBack)
{
    // local used variables
    HAL_PWR_ErrStates_t local_errState_t = HAL_PWR_OK;

    // check for errors
    if (argConst_u8CallBackType >= HAL_PWR_MAX_CALLBACK_TYPE || argConst_pFunctionCallBack == NULL)
    {
        local_errState_t = HAL_PWR_ERR_INVALID_PARAMS;
    }
    else
    {
        // do nothing
    }

    // main function
    if (local_errState_t == HAL_PWR_OK)
    {
        if (argConst_u8CallBackType == HAL_PWR_CALLBACK_PVD_LEVEL)
        {
            global_pPVDLevelChangeCallBack_t = argConst_pFunctionCallBack;
        }
        else
        {
            // do nothing
        }
    }

    return local_errState_t;
}

/**
 * @brief: interrupt handler for PVD, to indicate if VDD is higher or lower than the PVD threshold.
 */
void PVD_IRQHandler(void)
{
    global_pPVDLevelChangeCallBack_t(); // call the function from user
}

/*************** END OF FUNCTIONS ***************************************************************************/
