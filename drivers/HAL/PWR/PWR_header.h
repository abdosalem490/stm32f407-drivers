/**
 * --------------------------------------------------------------------------------------------------------------------------------------
 * |    @title          :   Power Controller                                                                                            |
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
 * |    @brief          :   this header file contains useful functions to interface with the Power Controller (PWR)                     |                                                               |
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

#ifndef HAL_PWR_HEADER_H_
#define HAL_PWR_HEADER_H_

/******************************************************************************
 * Includes
 *******************************************************************************/

/**
 * @reason: contains standard integer definition
 */
#include "../../lib/stdint.h"

/**
 * @reason: contains register definitions and addresses
 */
#include "PWR_reg.h"

/******************************************************************************
 * Preprocessor Constants
 *******************************************************************************/

/******************************************************************************
 * Configuration Constants
 *******************************************************************************/

/******************************************************************************
 * info
 *******************************************************************************/

/**
 * @ref: DIFF_BETWEEN_WFI_AND_WFE
 * difference between wait for interrupt (WFI) and wait for event (WFE)?
 *
 *  WFI (wait for interrupt)    :       it suspends execution until one of the following events occurs:
 *                                              ->  An exception.
 *                                              ->  A Debug Entry request, regardless of whether Debug is enabled.
 *  WFE (wait for Event)        :       it suspends execution until one of the following events occurs:
 *                                              ->  An exception, unless masked by exception mask registers or the current priority level.
 *                                              ->  An exception enters Pending state, if SEVONPEND in System Control Register is set.
 *                                              ->  A Debug Entry request, if Debug is enabled.
 *                                              ->  An event signaled by a peripheral or another processor in a multiprocessor system using the SEV instruction.
 */

/******************************************************************************
 * Macros
 *******************************************************************************/

// TODO: add the functionality for enabling backup domain access (RTC & SRAM)

/******************************************************************************
 * Typedefs
 *******************************************************************************/

/**
 * @enum: Hal_PWR_ErrStates_t
 * @brief: contains all possible errors that can result from dealing with the power controller.
 */
typedef enum
{
    HAL_PWR_OK,                 /**< it means everything has gone as intended so no errors*/
    HAL_PWR_ERR_INVALID_PARAMS, /**< it means that the supplied parameters of the function are invalid*/
} HAL_PWR_ErrStates_t;

/**
 * @enum: HAL_PWR_Mode_t
 * @brief: contains all possible errors that can result from dealing with the power controller.
 */
typedef enum
{
    HAL_MODE_RUN,     /**< CPU is clocked by HCLK and the program code is executed. (normal run)*/
    HAL_MODE_SLEEP,   /**< Cortex®-M4 with FPU core stopped, peripherals kept running (lowest power saving with the least latency) */
    HAL_MODE_STOP,    /**< all clocks are stopped (moderate power saving with the moderate latency)*/
    HAL_MODE_STANDBY, /**< 1.2 V domain powered off (highest power saving with the highest latency)*/
    HAL_MAX_MODE,     /**< this value shall never used by the user and it's only used by implementation code to verify input*/
} HAL_PWR_Mode_t;

/**
 * @enum: HAL_PWR_VAL_SleepMethod_t
 * @brief: contains all possibles values regarding how to enter sleep mode.
 */
typedef enum
{
    HAL_PWR_VAL_SLEEP_METHOD_WFE, /**< this makes MCU waits for event to occur while sleeping, refer to @DIFF_BETWEEN_WFI_AND_WFE in "PWR_header" to know difference between WFE and WFI*/
    HAL_PWR_VAL_SLEEP_METHOD_WFI, /**< this makes MCU waits for interrupt to occur while sleeping, refer to @DIFF_BETWEEN_WFI_AND_WFE in "PWR_header" to know difference between WFE and WFI*/
    HAL_PWR_MAX_VAL_SLEEP_METHOD, /**< this value shall never used by the user and it's only used by implementation code to verify input*/
} HAL_PWR_VAL_SleepMethod_t;

/**
 * @enum: HAL_PWR_ConfigKeys_t
 * @brief: contains all possibles keys of configuration that can be edited during runtime, each value inside this enum has a comment telling where to find the the corresponding possible values.
 */
typedef enum
{
    HAL_PWR_KEY_SLEEP_METHOD,          /**< for possible corresponding values refer to @HAL_PWR_VAL_SleepMethod_t in "PWR_header.h", it indicates how the MCU shall enter the sleep mode*/
    HAL_PWR_KEY_SLEEP_EXIT_ISR_ENABLE, /**< for for possible values refer to @LIB_CONSTANTS_DriverStates_t in "constants.h", it indicates whether to enable or disable sleeping on exit from ISR*/
    HAL_PWR_MAX_CONFIG_KEYS,           /**< this value shall never used by the user and it's only used by implementation code to verify input*/
} HAL_PWR_ConfigKeys_t;

/**
 * @enum: HAL_PWR_CallbacksTypes_t
 * @brief: constants used to as key to register a callback when a specific even happens
 */
typedef enum
{
    HAL_PWR_CALLBACK_PVD_LEVEL, /**< used to tell*/
    HAL_PWR_MAX_CALLBACK_TYPE,  /**< that value should never be used and it's only used by the implementation code for verifying the input*/
} HAL_PWR_CallbacksTypes_t;

/******************************************************************************
 * Variables
 *******************************************************************************/

/******************************************************************************
 * Function Prototypes
 *******************************************************************************/

/**
 *  \b function                     :       HAL_PWR_Init()
 *  \b Description                  :       this functions initialize the power controller configuration with the configurations supplied in "PWR_config.h"
 *  @param                          :       None
 *  @note                           :       This shall be the first function to be called before using any other function in this interface, also it's a blocking function
 *                                          IT IS ADVISED TO CALL HAL_PWR_Init() BEFORE CALLING ANY OTHER FUNCTION
 *  \b PRE-CONDITION                :       make sure to edit all configurations in file "PWR_config.h" (any array labeled with @user_todo shall be edited)
 *  \b POST-CONDITION               :       it configures the following properties of PWR memory:
 *                                              -> Regulator voltage scaling output selection
 *                                              -> Flash power-down in Stop mode enablement
 *                                              -> PVD level selection
 *                                              -> Power voltage detector enable
 *                                              -> Enable WKUP pin
 *  @return                         :       it return one of error states indicating whether a failure or success happened during initialization (refer to @HAL_PWR_ErrStates_t in "PWR_header.h")
 *  @see                            :       HAL_PWR_EnterMode(const uint8_t argConst_u8Mode)
 *  @see                            :       HAL_PWR_Config(const uint8_t argConst_u8Key, const uint8_t argConst_u8Value)
 *  @see                            :       HAL_PWR_RegisterCallback(const uint8_t argConst_u8CallBackType, const functionCallBack_t argConst_pFunctionCallBack)
 *
 *  \b Example:
 * @code
 * #include "PWR_header.h"
 * int main() {
 *  HAL_PWR_ErrStates_t local_errState_t = HAL_PWR_Init();    // make sure that you edited any array in "PWR_config.h" labeled with @user_todo so that Power controller can be initialized correctly
 *  if (local_errState_t == HAL_PWR_OK)
 *  {
 *      // power controller initialized successfully
 *  }
 *  return 0;
 * }
 * @endcode
 *
 * <br><b> - HISTORY OF CHANGES - </b>
 * <table align="left" style="width:800px">
 * <tr><td> Date       </td><td> Software Version </td><td> Initials </td><td> Description </td></tr>
 * <tr><td> 16/08/2023 </td><td> 1.0.0            </td><td> AMS      </td><td> Interface Created </td></tr>
 * </table><br><br>
 * <hr>
 */
HAL_PWR_ErrStates_t HAL_PWR_Init();

/**
 *  \b function                             :       HAL_PWR_EnterMode(const uint8_t argConst_u8Mode)
 *  \b Description                          :       this functions is used to enter one of the sleep modes or return to the run mode.
 *  @param  argConst_u8Mode [IN]            :       for possible values refer to @HAL_PWR_Mode_t in "PWR_header.h", this is input parameter which indicates which mode to switch to.
 *  @note                                   :       the function will return in run mode unless interrupt/event happened (it's not possible the function will return while MCU is in sleep mode).
 *  \b PRE-CONDITION                        :       make sure to call HAL_PWR_Init() and there is no interrupt/event pending.
 *  \b POST-CONDITION                       :       MCU enters to the selected mode.
 *  @return                                 :       it return one of error states indicating whether a failure or success happened during writing of data (refer to @HAL_PWR_ErrStates_t in "PWR_header.h")
 *  @see                                    :       HAL_PWR_Init()
 *  @see                                    :       HAL_PWR_Config(const uint8_t argConst_u8Key, const uint8_t argConst_u8Value)
 *  @see                                    :       HAL_PWR_RegisterCallback(const uint8_t argConst_u8CallBackType, const functionCallBack_t argConst_pFunctionCallBack)
 *  \b Example:
 * @code
 * #include "PWR_header.h"
 * int main() {
 * HAL_PWR_Init();    // make sure that you edited any array in "PWR_config.h" labeled with @user_todo so that Power controller can be initialized correctly
 * HAL_PWR_ErrStates_t local_errState_t = HAL_PWR_EnterMode(HAL_MODE_STOP);
 * if (local_errState_t == HAL_PWR_OK)
 * {
 *  // MCU entered mode successfully and just exited from the mode
 * }
 * return 0;
 * }
 * @endcode
 *
 * <br><b> - HISTORY OF CHANGES - </b>
 * <table align="left" style="width:800px">
 * <tr><td> Date       </td><td> Software Version </td><td> Initials </td><td> Description </td></tr>
 * <tr><td> 16/08/2023 </td><td> 1.0.0            </td><td> AMS      </td><td> Interface Created </td></tr>
 * </table><br><br>
 * <hr>
 */
HAL_PWR_ErrStates_t HAL_PWR_EnterMode(const uint8_t argConst_u8Mode);

/**
 *  \b function                             :       HAL_PWR_Config(const uint8_t argConst_u8Key, const uint8_t argConst_u8Value)
 *  \b Description                          :       this functions is used to change the behavior of the functions by changing some key configuration values during runtime.
 *  @param  argConst_u8Key [IN]             :       this is input parameter which is key of the parameter to be changed, for possible values refer to @HAL_PWR_ConfigKeys_t in "PWR_header.h".
 *  @param  argConst_u8Value [IN]           :       this is input parameter which value of configuration to be assigned to the corresponding selected key. for possible values, every key has its set of values, refer to @HAL_PWR_ConfigKeys_t in "PWR_header.h" as the possible values are written as comments for every key.
 *  @note                                   :       None.
 *  \b PRE-CONDITION                        :       None.
 *  \b POST-CONDITION                       :       it changes the behavior of some functions of the interface.
 *  @return                                 :       it return one of error states indicating whether a failure or success happened during the edit of configuration (refer to @HAL_PWR_ErrStates_t in "PWR_header.h")
 *  @see                                    :       HAL_PWR_Init()
 *  @see                                    :       HAL_PWR_EnterMode(const uint8_t argConst_u8Mode)
 *  @see                                    :       HAL_PWR_RegisterCallback(const uint8_t argConst_u8CallBackType, const functionCallBack_t argConst_pFunctionCallBack)
 *  \b Example:
 * @code
 * #include "PWR_header.h"
 * int main() {
 *  HAL_PWR_Init();    // make sure that you edited any array in "PWR_config.h" labeled with @user_todo so that Power controller can be initialized correctly
 *  HAL_PWR_ErrStates_t local_errState_t = HAL_PWR_Config(HAL_PWR_KEY_SLEEP_METHOD, HAL_PWR_VAL_SLEEP_METHOD_WFE);
 *  if (local_errState_t == HAL_PWR_OK)
 *  {
 *      HAL_PWR_EnterMode(HAL_MODE_STOP);   // function will use instruction WFE to enter the STOP mode
 *  }
 *  return 0;
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
HAL_PWR_ErrStates_t HAL_PWR_Config(const uint8_t argConst_u8Key, const uint8_t argConst_u8Value);

/**
 *  \b function                             :       HAL_PWR_RegisterCallback(const uint8_t argConst_u8CallBackType, const functionCallBack_t argConst_pFunctionCallBack)
 *  \b Description                          :       this functions is used to register a callback function to be executed from user code when an interrupt happens.
 *  @param  argConst_u8CallBackType [IN]    :       this is input parameter indicates which interrupt handler to attach this function to, for possible values, refer to  @HAL_PWR_CallbacksTypes_t in "PWR_header.h"
 *  @param  argConst_pFunctionCallBack [IN] :       this is the function to be called when the specified action interrupt happens.
 *  @note                                   :       None.
 *  \b PRE-CONDITION                        :       make sure to call HAL_PWR_Init() and make sure the address of function is valid address and the interrupts are enabled for that event.
 *  \b POST-CONDITION                       :       assign the given function to a specific action.
 *  @return                                 :       it return one of error states indicating whether a failure or success happened during the registration of callbacks (refer to @HAL_PWR_ErrStates_t in "PWR_header.h")
 *  @see                                    :       HAL_PWR_Init()
 *  @see                                    :       HAL_PWR_EnterMode(const uint8_t argConst_u8Mode)
 *  @see                                    :       HAL_PWR_Config(const uint8_t argConst_u8Key, const uint8_t argConst_u8Value)
 *  \b Example:
 * @code
 * #include "PWR_header.h"
 *
 * int code = 0;
 * void levelChange(void)    // this function is to be called when PVD level is under a specific volt level.
 * {
 *  code = 1;
 * }
 *
 * int main() {
 *  HAL_PWR_Init();    // make sure that you edited any array in "PWR_config.h" labeled with @user_todo so that power controller can be initialized correctly
 *  HAL_PWR_ErrStates_t error_state;
 *
 *  HAL_PWR_RegisterCallback(HAL_PWR_CALLBACK_PVD_LEVEL, levelChange);  // when PVD level is less/more than a specific threshold specified int "PWR_config.h" function called "levelChange()" will be called
 *
 *
 * return 0;
 * }
 * @endcode
 *
 * <br><b> - HISTORY OF CHANGES - </b>
 * <table align="left" style="width:800px">
 * <tr><td> Date       </td><td> Software Version </td><td> Initials </td><td> Description </td></tr>
 * <tr><td> 16/08/2023 </td><td> 1.0.0            </td><td> AMS      </td><td> Interface Created </td></tr>
 * </table><br><br>
 * <hr>
 */
HAL_PWR_ErrStates_t HAL_PWR_RegisterCallback(const uint8_t argConst_u8CallBackType, const functionCallBack_t argConst_pFunctionCallBack);

/*** End of File **************************************************************/
#endif /*HAL_PWR_HEADER_H_*/