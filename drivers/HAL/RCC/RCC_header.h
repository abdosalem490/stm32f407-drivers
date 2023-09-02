/**
 * --------------------------------------------------------------------------------------------------------------------------------------
 * |    @title          :   Reset and clock control                                                                                     |
 * |    @file           :   RCC_header.h                                                                                                |
 * |    @author         :   Abdelrahman Mohamed Salem                                                                                   |
 * |    @origin_date    :   20/08/2023                                                                                                  |
 * |    @version        :   1.0.0                                                                                                       |
 * |    @tool_chain     :   GNU Tools for STM32                                                                                         |
 * |    @compiler       :   GCC                                                                                                         |
 * |    @C_standard     :   ISO C99 (-std=c99)                                                                                          |
 * |    @target         :   stm32f407VGTX                                                                                               |
 * |    @notes          :   None                                                                                                        |
 * |    @license        :   MIT License                                                                                                 |
 * |    @brief          :   this header file contains useful functions to interface with the Reset and clock control (RCC)              |
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
 * |    20/08/2023      1.0.0           Abdelrahman Mohamed Salem       Interface Created.                                              |
 * --------------------------------------------------------------------------------------------------------------------------------------
 */

#ifndef HAL_RCC_HEADER_H_
#define HAL_RCC_HEADER_H_

/******************************************************************************
 * Includes
 *******************************************************************************/

/**
 * @reason: contains standard integer definition
 */
#include "../../lib/stdint.h"

/**
 * @reason: contains function callback type
 */
#include "../../lib/common.h"

/******************************************************************************
 * Preprocessor Constants
 *******************************************************************************/

/******************************************************************************
 * Configuration Constants
 *******************************************************************************/

/******************************************************************************
 * Macros
 *******************************************************************************/

// TODO: add the functionality for enabling backup domain access (RTC & SRAM)

/******************************************************************************
 * Typedefs
 *******************************************************************************/

/**
 * @enum: Hal_RCC_ErrStates_t
 * @brief: contains all possible errors that can result from dealing with the Reset and clock control.
 */
typedef enum
{
    HAL_RCC_OK,                  /**< it means everything has gone as intended so no errors*/
    HAL_RCC_ERR_INVALID_PARAMS,  /**< it means that the supplied parameters of the function are invalid*/
    HAL_RCC_ERR_INVALID_CONFIG,  /**< it means that the supplied configurations in the "RCC_config.h" file are incorrect*/
    HAL_RCC_ERR_INVALID_CLK_VAL, /**< it means that the entered clock value couldn't be configured (mostly it's due to PLL,PLLI2S vals)*/
} HAL_RCC_ErrStates_t;

/**
 * @enum: HAL_RCC_Peripherals_t
 * @brief: contains all possible peripherals controlled by RCC.
 */
typedef enum
{
    HAL_RCC_PERIPHERAL_USB_OTG,   /**< USB module, whether it's high speed or full speed it depends on configurations supplied to "USB_condig.h" */
    HAL_RCC_PERIPHERAL_ETHERNET,  /**< Ethernet module whether we are talking about RX,TX,MAC, etc.. */
    HAL_RCC_PERIPHERAL_DMA1,      /**< DMA1 (direct memory access) module */
    HAL_RCC_PERIPHERAL_DMA2,      /**< DMA2 (direct memory access) module */
    HAL_RCC_PERIPHERAL_CCM,       /**< CCM (coupled core memory) module*/
    HAL_RCC_PERIPHERAL_BKP_SRAM,  /**< Backup SRAM module */
    HAL_RCC_PERIPHERAL_SRAM1,     /**< SRAM1 module */
    HAL_RCC_PERIPHERAL_SRAM2,     /**< SRAM2 module */
    HAL_RCC_PERIPHERAL_CRC,       /**< CRC (cyclic redundancy check) module */
    HAL_RCC_PERIPHERAL_GPIOA,     /**< GPIOA module */
    HAL_RCC_PERIPHERAL_GPIOB,     /**< GPIOB module */
    HAL_RCC_PERIPHERAL_GPIOC,     /**< GPIOC module */
    HAL_RCC_PERIPHERAL_GPIOD,     /**< GPIOD module */
    HAL_RCC_PERIPHERAL_GPIOE,     /**< GPIOE module */
    HAL_RCC_PERIPHERAL_GPIOF,     /**< GPIOF module */
    HAL_RCC_PERIPHERAL_GPIOG,     /**< GPIOG module */
    HAL_RCC_PERIPHERAL_GPIOH,     /**< GPIOH module */
    HAL_RCC_PERIPHERAL_GPIOI,     /**< GPIOI module */
    HAL_RCC_PERIPHERAL_RNG,       /**< RNG (Random number generator) module */
    HAL_RCC_PERIPHERAL_HASH,      /**< HASH processor module */
    HAL_RCC_PERIPHERAL_CRYPTO,    /**< Cryptographic processor module */
    HAL_RCC_PERIPHERAL_CAMERA,    /**< Camera digital module */
    HAL_RCC_PERIPHERAL_FSMC,      /**< Flexible static Memory controller module */
    HAL_RCC_PERIPHERAL_DAC,       /**< DAC module */
    HAL_RCC_PERIPHERAL_PWR,       /**< Power controller module */
    HAL_RCC_PERIPHERAL_CAN1,      /**< CAN1 module */
    HAL_RCC_PERIPHERAL_CAN2,      /**< CAN2 module */
    HAL_RCC_PERIPHERAL_I2C1,      /**< I2C1 module */
    HAL_RCC_PERIPHERAL_I2C2,      /**< I2C2 module */
    HAL_RCC_PERIPHERAL_I2C3,      /**< I2C3 module */
    HAL_RCC_PERIPHERAL_USART1,    /**< USART1 module */
    HAL_RCC_PERIPHERAL_USART2,    /**< USART2 module */
    HAL_RCC_PERIPHERAL_USART3,    /**< USART3 module */
    HAL_RCC_PERIPHERAL_UART4,     /**< UART4 module */
    HAL_RCC_PERIPHERAL_UART5,     /**< UART5 module */
    HAL_RCC_PERIPHERAL_USART6,    /**< USART6 module */
    HAL_RCC_PERIPHERAL_SPI1,      /**< SPI1 module */
    HAL_RCC_PERIPHERAL_SPI2,      /**< SPI2 module */
    HAL_RCC_PERIPHERAL_SPI3,      /**< SPI3 module */
    HAL_RCC_PERIPHERAL_WWDG,      /**< Window watchdog module */
    HAL_RCC_PERIPHERAL_TIM1,      /**< TIM1 (Timer) module */
    HAL_RCC_PERIPHERAL_TIM2,      /**< TIM2 (Timer) module */
    HAL_RCC_PERIPHERAL_TIM3,      /**< TIM3 (Timer) module */
    HAL_RCC_PERIPHERAL_TIM4,      /**< TIM4 (Timer) module */
    HAL_RCC_PERIPHERAL_TIM5,      /**< TIM5 (Timer) module */
    HAL_RCC_PERIPHERAL_TIM6,      /**< TIM6 (Timer) module */
    HAL_RCC_PERIPHERAL_TIM7,      /**< TIM7 (Timer) module */
    HAL_RCC_PERIPHERAL_TIM8,      /**< TIM8 (Timer) module */
    HAL_RCC_PERIPHERAL_TIM9,      /**< TIM9 (Timer) module */
    HAL_RCC_PERIPHERAL_TIM10,     /**< TIM10 (Timer) module */
    HAL_RCC_PERIPHERAL_TIM11,     /**< TIM11 (Timer) module */
    HAL_RCC_PERIPHERAL_TIM12,     /**< TIM12 (Timer) module */
    HAL_RCC_PERIPHERAL_TIM13,     /**< TIM13 (Timer) module */
    HAL_RCC_PERIPHERAL_TIM14,     /**< TIM14 (Timer) module */
    HAL_RCC_PERIPHERAL_SYS_CFG,   /**< System Configuration module */
    HAL_RCC_PERIPHERAL_SDIO,      /**< SDIO (Secure digital input/output) module */
    HAL_RCC_PERIPHERAL_ADC1,      /**< ADC1 module */
    HAL_RCC_PERIPHERAL_ADC2,      /**< ADC2 module */
    HAL_RCC_PERIPHERAL_ADC3,      /**< ADC3 module */
    HAL_RCC_PERIPHERAL_FLASH_MEM, /**< Flash interface module */
    HAL_RCC_PERIPHERAL_RTC,       /**< RTC (real time clock) module */
    HAL_RCC_MAX_PERIPHERAL,       /**< this value shall never used by the user and it's only used by implementation code to verify input*/
} HAL_RCC_Peripherals_t;

/**
 * @enum: HAL_RCC_PeripheralOperation_t
 * @brief: constants used to to determine which operation to be performed on a peripheral via RCC.
 */
typedef enum
{
    HAL_RCC_PERI_OP_RESET,           /**< used to reset the peripheral*/
    HAL_RCC_PERI_OP_ENABLE,          /**< used to enable the peripheral in run mode*/
    HAL_RCC_PERI_OP_DISABLE,         /**< used to disable the peripheral in run mode*/
    HAL_RCC_PERI_OP_LOW_PWR_ENABLE,  /**< used to enable the peripheral in sleep mode*/
    HAL_RCC_PERI_OP_LOW_PWR_DISABLE, /**< used to disable the peripheral in sleep mode*/
    HAL_RCC_MAX_PERI_OP,             /**< that value should never be used and it's only used by the implementation code for verifying the input*/
} HAL_RCC_PeripheralOperation_t;

/**
 * @enum: HAL_RCC_CallbacksTypes_t
 * @brief: constants used to as key to register a callback when a specific even happens
 */
typedef enum
{
    HAL_RCC_CALLBACK_CLOCK_SECURITY, /**< used when the clock becomes unstable */
    HAL_RCC_MAX_CALLBACK_TYPE,       /**< that value should never be used and it's only used by the implementation code for verifying the input*/
} HAL_RCC_CallbacksTypes_t;

/**
 * @enum: HAL_RCC_ResetCause_t
 * @brief: it holds all the causes that can cause system reset
 */
typedef enum
{
    HAL_RCC_RESET_CAUSE_LOW_POWER,             /**< when a Low-power management reset occurs.*/
    HAL_RCC_RESET_CAUSE_WINDOW_WATCHDOG,       /**< when a window watchdog reset occurs.*/
    HAL_RCC_RESET_CAUSE_INDEPENDEDNT_WATCHDOG, /**< when an independent watchdog reset from VDD domain occurs.*/
    HAL_RCC_RESET_CAUSE_SOFTWARE,              /**< when a software reset occurs.*/
    HAL_RCC_RESET_CAUSE_POR_PDR,               /**< when a POR/PDR reset occurs.*/
    HAL_RCC_RESET_CAUSE_PIN,                   /**< when a reset from the NRST pin occurs.*/
    HAL_RCC_RESET_CAUSE_BOR,                   /**< when a BOR reset occurs.*/
    HAL_RCC_NO_RESET_HAPPENED,                 /**< No reset happened*/
    HAL_RCC_MAX_RESET_CAUSE_TYPE,              /**< that value should never be used and it's only used by the implementation code for verifying the input*/
} HAL_RCC_ResetCause_t;

/******************************************************************************
 * Variables
 *******************************************************************************/

/******************************************************************************
 * Function Prototypes
 *******************************************************************************/

/**
 *  \b function                     :       HAL_RCC_Init()
 *  \b Description                  :       this functions initialize the Reset and clock control configuration with the configurations supplied in "RCC_config.h"
 *  @param                          :       None
 *  @note                           :       This shall be the first function to be called before using any other function in this interface, also it's a blocking function
 *                                          IT IS ADVISED TO CALL HAL_RCC_Init() BEFORE CALLING ANY OTHER FUNCTION
 *  \b PRE-CONDITION                :       make sure to edit all configurations in file "RCC_config.h" (any array labeled with @user_todo shall be edited)
 *  \b POST-CONDITION               :       it configures the Clock sources.
 *                                          it configures all peripherals enablement of RCC clock during sleep and run mode.
 *  @return                         :       it return one of error states indicating whether a failure or success happened during initialization (refer to @HAL_RCC_ErrStates_t in "RCC_header.h")
 *  @see                            :       HAL_RCC_PeripheralModify(const uint8_t argConst_u8PeripheralName, const uint8_t argConst_u8Operation)
 *  @see                            :       HAL_RCC_GetSystemResetType(uint8_t *const arg_Constpu8Value)
 *  @see                            :       HAL_RCC_GetPeripheralInputFrequency(const uint8_t argConst_u8PeripheralName, uint32_t *const arg_Constpu32Value)
 *  @see                            :       HAL_RCC_RegisterCallback(const uint8_t argConst_u8CallBackType, const functionCallBack_t argConst_pFunctionCallBack)
 *
 *  \b Example:
 * @code
 * #include "RCC_header.h"
 * int main() {
 *  HAL_RCC_ErrStates_t local_errState_t = HAL_RCC_Init();    // make sure that you edited any array in "RCC_config.h" labeled with @user_todo so that Power controller can be initialized correctly
 *  if (local_errState_t == HAL_RCC_OK)
 *  {
 *      // Reset and clock initialized successfully
 *  }
 *  return 0;
 * }
 * @endcode
 *
 * <br><b> - HISTORY OF CHANGES - </b>
 * <table align="left" style="width:800px">
 * <tr><td> Date       </td><td> Software Version </td><td> Initials </td><td> Description </td></tr>
 * <tr><td> 26/08/2023 </td><td> 1.0.0            </td><td> AMS      </td><td> Interface Created </td></tr>
 * </table><br><br>
 * <hr>
 */
HAL_RCC_ErrStates_t HAL_RCC_Init();

/**
 *  \b function                                 :       HAL_RCC_ErrStates_t HAL_RCC_PeripheralModify(const uint8_t argConst_u8PeripheralName, const uint8_t argConst_u8Operation)
 *  \b Description                              :       this functions is used to modify peripheral during runtime like enable\reset\disable\low_power_enable\low_power_disable\etc...
 *  @param  argConst_u8PeripheralName [IN]      :       for possible values refer to @HAL_RCC_Peripherals_t in "RCC_header.h", this is input parameter which indicates which peripheral to modify.
 *  @param  argConst_u8Operation [IN]           :       for possible values refer to @HAL_RCC_PeripheralOperation_t in "RCC_header.h", this is input parameter which indicates which operation to perform on the peripheral.
 *  @note                                       :       None.
 *  \b PRE-CONDITION                            :       make sure to call HAL_RCC_Init().
 *  \b POST-CONDITION                           :       MCU peripheral status changes according to the desired operation.
 *  @return                                     :       it return one of error states indicating whether a failure or success happened (refer to @HAL_RCC_ErrStates_t in "RCC_header.h")
 *  @see                                        :       HAL_RCC_Init()
 *  @see                                        :       HAL_RCC_GetSystemResetType(uint8_t *const arg_Constpu8Value)
 *  @see                                        :       HAL_RCC_GetPeripheralInputFrequency(const uint8_t argConst_u8PeripheralName, uint32_t *const arg_Constpu32Value)
 *  @see                                        :       HAL_RCC_RegisterCallback(const uint8_t argConst_u8CallBackType, const functionCallBack_t argConst_pFunctionCallBack)
 *
 *  \b Example:
 * @code
 * #include "RCC_header.h"
 * int main() {
 * HAL_RCC_Init();    // make sure that you edited any array in "RCC_config.h" labeled with @user_todo so that RCC can be initialized correctly
 * HAL_RCC_ErrStates_t local_errState_t = HAL_RCC_PeripheralModify(HAL_RCC_PERIPHERAL_TIM1, HAL_RCC_PERI_OP_RESET);
 * if (local_errState_t == HAL_RCC_OK)
 * {
 *  // TIM1 is reset successfully
 * }
 * return 0;
 * }
 * @endcode
 *
 * <br><b> - HISTORY OF CHANGES - </b>
 * <table align="left" style="width:800px">
 * <tr><td> Date       </td><td> Software Version </td><td> Initials </td><td> Description </td></tr>
 * <tr><td> 27/08/2023 </td><td> 1.0.0            </td><td> AMS      </td><td> Interface Created </td></tr>
 * </table><br><br>
 * <hr>
 */
HAL_RCC_ErrStates_t HAL_RCC_PeripheralModify(const uint8_t argConst_u8PeripheralName, const uint8_t argConst_u8Operation);

/**
 *  \b function                             :       HAL_RCC_GetSystemResetType(const uint8_t *argConst_pu8Value)
 *  \b Description                          :       this functions is used to return what caused the last system reset.
 *  @param  argConst_pu8Value [OUT]         :       this is output parameter indicates what cased the last system reset, it will hold one of the value mentioned in  @HAL_RCC_ResetCause_t in "RCC_header.h"
 *  @note                                   :       this function once called, it will clear all the reset flags so it can't be called again.
 *  \b PRE-CONDITION                        :       None.
 *  \b POST-CONDITION                       :       it clears the reset flags.
 *  @return                                 :       it return one of error states indicating whether a failure or success regarding function operation
 *  @see                                    :       HAL_RCC_Init()
 *  @see                                    :       HAL_RCC_PeripheralModify(const uint8_t argConst_u8PeripheralName, const uint8_t argConst_u8Operation)
 *  @see                                    :       HAL_RCC_GetPeripheralInputFrequency(const uint8_t argConst_u8PeripheralName, uint32_t *const arg_Constpu32Value)
 *  @see                                    :       HAL_RCC_RegisterCallback(const uint8_t argConst_u8CallBackType, const functionCallBack_t argConst_pFunctionCallBack)
 *
 *  \b Example:
 * @code
 * #include "RCC_header.h"
 * int main() {
 *  HAL_RCC_Init();    // make sure that you edited any array in "RCC_config.h" labeled with @user_todo so thatRCC can be initialized correctly
 *  uint8_t resetCause = 0;
 *  HAL_RCC_ErrStates_t local_errState_t = HAL_RCC_GetSystemResetType(&resetCause);
 *  if (local_errState_t == HAL_RCC_OK)
 *  {
 *      // check for cause of reset
 *      if(resetCause == HAL_RCC_RESET_CAUSE_PIN)
 *      {
 *          // the reset is due to nrst
 *      }
 *  }
 *  return 0;
 * }
 * @endcode
 *
 * <br><b> - HISTORY OF CHANGES - </b>
 * <table align="left" style="width:800px">
 * <tr><td> Date       </td><td> Software Version </td><td> Initials </td><td> Description </td></tr>
 * <tr><td> 31/08/2023 </td><td> 1.0.0            </td><td> AMS      </td><td> Interface Created </td></tr>
 * </table><br><br>
 * <hr>
 */
HAL_RCC_ErrStates_t HAL_RCC_GetSystemResetType(uint8_t *const arg_Constpu8Value);

/**
 *  \b function                             :       HAL_RCC_GetPeripheralInputFrequency(const uint8_t argConst_u8PeripheralName, uint32_t *const arg_Constpu32Value)
 *  \b Description                          :       this functions is used to return clock input frequency to a specific peripheral.
 *  @param  argConst_u8PeripheralName [IN]  :       this is input parameter which is the peripheral that you want to know what's the input clock frequency to it. for possible values refer to @HAL_RCC_Peripherals_t in "RCC_header.h".
 *  @param  argConst_pu8Value [OUT]         :       this is output parameter which is the input clock frequency in HZ to that peripheral.
 *  @note                                   :       None.
 *  \b PRE-CONDITION                        :       None.
 *  \b POST-CONDITION                       :       None.
 *  @return                                 :       it return one of error states indicating whether a failure or success regarding function operation
 *  @see                                    :       HAL_RCC_Init()
 *  @see                                    :       HAL_RCC_PeripheralModify(const uint8_t argConst_u8PeripheralName, const uint8_t argConst_u8Operation)
 *  @see                                    :       HAL_RCC_GetSystemResetType(uint8_t *const arg_Constpu8Value)
 *  @see                                    :       HAL_RCC_RegisterCallback(const uint8_t argConst_u8CallBackType, const functionCallBack_t argConst_pFunctionCallBack)
 * \b Example:
 * @code
 * #include "RCC_header.h"
 * int main() {
 *  HAL_RCC_Init();    // make sure that you edited any array in "RCC_config.h" labeled with @user_todo so thatRCC can be initialized correctly
 *  uint32_t GPIOA_inputClockFrequency = 0;
 *  HAL_RCC_ErrStates_t local_errState_t = HAL_RCC_GetSystemResetType(HAL_RCC_PERIPHERAL_GPIOA, &GPIOA_inputClockFrequency);
 *  if (local_errState_t == HAL_RCC_OK)
 *  {
 *      // GPIOA_inputClockFrequency will hold the value of input clock frequency to GPIOA
 *  }
 *  return 0;
 * }
 * @endcode
 *
 * <br><b> - HISTORY OF CHANGES - </b>
 * <table align="left" style="width:800px">
 * <tr><td> Date       </td><td> Software Version </td><td> Initials </td><td> Description </td></tr>
 * <tr><td> 31/08/2023 </td><td> 1.0.0            </td><td> AMS      </td><td> Interface Created </td></tr>
 * </table><br><br>
 * <hr>
 */
HAL_RCC_ErrStates_t HAL_RCC_GetPeripheralInputFrequency(const uint8_t argConst_u8PeripheralName, uint32_t *const arg_Constpu32Value);

/**
 *  \b function                             :       HAL_RCC_RegisterCallback(const uint8_t argConst_u8CallBackType, const functionCallBack_t argConst_pFunctionCallBack)
 *  \b Description                          :       this functions is used to register a callback function to be executed from user code when an interrupt happens.
 *  @param  argConst_u8CallBackType [IN]    :       this is input parameter indicates which interrupt handler to attach this function to, for possible values, refer to  @HAL_PWR_CallbacksTypes_t in "PWR_header.h"
 *  @param  argConst_pFunctionCallBack [IN] :       this is the function to be called when the specified action interrupt happens.
 *  @note                                   :       None.
 *  \b PRE-CONDITION                        :       make sure to call HAL_RCC_Init() and make sure the address of function is valid address.
 *  \b POST-CONDITION                       :       assign the given function to a specific action.
 *  @return                                 :       it return one of error states indicating whether a failure or success happened during the registration of callbacks (refer to @HAL_RCC_ErrStates_t in "RCC_header.h")
 *  @see                                    :       HAL_RCC_Init()
 *  @see                                    :       HAL_RCC_PeripheralModify(const uint8_t argConst_u8PeripheralName, const uint8_t argConst_u8Operation)
 *  @see                                    :       HAL_RCC_GetSystemResetType(uint8_t *const arg_Constpu8Value)
 *  @see                                    :       HAL_RCC_GetPeripheralInputFrequency(const uint8_t argConst_u8PeripheralName, uint32_t *const arg_Constpu32Value)
 * \b Example:
 * @code
 * #include "RCC_header.h"
 *
 * int code = 0;
 * void clockUnstable(void)    // this function is to be called when PVD level is under a specific volt level.
 * {
 *  code = 1;
 * }
 *
 * int main() {
 *  HAL_RCC_Init();    // make sure that you edited any array in "RCC_config.h" labeled with @user_todo so that RCC can be initialized correctly
 *  HAL_RCC_ErrStates_t error_state;
 *
 *  HAL_RCC_RegisterCallback(HAL_RCC_CALLBACK_PVD_LEVEL, clockUnstable);  // when system clock becomes unstable "function called "levelChange()" will be called.
 *
 *
 * return 0;
 * }
 * @endcode
 *
 * <br><b> - HISTORY OF CHANGES - </b>
 * <table align="left" style="width:800px">
 * <tr><td> Date       </td><td> Software Version </td><td> Initials </td><td> Description </td></tr>
 * <tr><td> 31/08/2023 </td><td> 1.0.0            </td><td> AMS      </td><td> Interface Created </td></tr>
 * </table><br><br>
 * <hr>
 */
HAL_RCC_ErrStates_t HAL_RCC_RegisterCallback(const uint8_t argConst_u8CallBackType, const functionCallBack_t argConst_pFunctionCallBack);

/*** End of File **************************************************************/
#endif /*HAL_RCC_HEADER_H_*/