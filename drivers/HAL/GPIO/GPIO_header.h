/**
 * --------------------------------------------------------------------------------------------------------------------------------------
 * |    @title          :   General Purpose Input/Output                                                                                |
 * |    @file           :   GPIO_header.h                                                                                               |
 * |    @author         :   Abdelrahman Mohamed Salem                                                                                   |
 * |    @origin_date    :   02/09/2023                                                                                                  |
 * |    @version        :   1.0.0                                                                                                       |
 * |    @tool_chain     :   GNU Tools for STM32                                                                                         |
 * |    @compiler       :   GCC                                                                                                         |
 * |    @C_standard     :   ISO C99 (-std=c99)                                                                                          |
 * |    @target         :   stm32f407VGTX                                                                                               |
 * |    @notes          :   None                                                                                                        |
 * |    @license        :   MIT License                                                                                                 |
 * |    @brief          :   this header file contains useful functions to interface with the General Purpose Input/Output (GPIO)        |
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
 * |    02/09/2023      1.0.0           Abdelrahman Mohamed Salem       Interface Created.                                              |
 * --------------------------------------------------------------------------------------------------------------------------------------
 */

#ifndef HAL_GPIO_HEADER_H_
#define HAL_GPIO_HEADER_H_

/******************************************************************************
 * Includes
 *******************************************************************************/

/**
 * @reason: contains standard integer definition
 */
#include "../../lib/stdint.h"

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
 * @enum: Hal_GPIO_ErrStates_t
 * @brief: contains all possible errors that can result from dealing with the Reset and clock control.
 */
typedef enum
{
    HAL_GPIO_OK,                 /**< it means everything has gone as intended so no errors*/
    HAL_GPIO_ERR_INVALID_PARAMS, /**< it means that the supplied parameters of the function are invalid*/
    HAL_GPIO_ERR_INVALID_CONFIG, /**< it means that the supplied configurations in the "GPIO_config.h" file are incorrect*/
} HAL_GPIO_ErrStates_t;

/**
 * @enum: HAL_GPIO_Ports_t
 * @brief: contains all possible Ports available.
 */
typedef enum
{
    HAL_GPIO_PORTA = 0x0001,    /**< PORT named A, value = 0b0000 0000 0000 0001 */
    HAL_GPIO_PORTB = 0x0002,    /**< PORT named B, value = 0b0000 0000 0000 0010 */
    HAL_GPIO_PORTC = 0x0004,    /**< PORT named C, value = 0b0000 0000 0000 0100 */
    HAL_GPIO_PORTD = 0x0008,    /**< PORT named D, value = 0b0000 0000 0000 1000 */
    HAL_GPIO_PORTE = 0x0010,    /**< PORT named E, value = 0b0000 0000 0001 0000 */
    HAL_GPIO_PORTF = 0x0020,    /**< PORT named F, value = 0b0000 0000 0010 0000 */
    HAL_GPIO_PORTG = 0x0040,    /**< PORT named G, value = 0b0000 0000 0100 0000 */
    HAL_GPIO_PORTH = 0x0080,    /**< PORT named H, value = 0b0000 0000 1000 0000 */
    HAL_GPIO_PORTI = 0x0100,    /**< PORT named I, value = 0b0000 0001 0000 0000 */
    HAL_GPIO_MAX_PORT = 0x0200, /**< this value shall never used by the user and it's only used by implementation code to verify input*/
} HAL_GPIO_Ports_t;

/**
 * @enum: HAL_GPIO_Pins_t
 * @brief: contains all possible pin numbers for a GPIO.
 */
typedef enum
{
    HAL_GPIO_PIN0 = 0x0001,  /**< PIN0 of whatever GPIO specified, value = 0b0000 0000 0000 0001*/
    HAL_GPIO_PIN1 = 0x0002,  /**< PIN1 of whatever GPIO specified, value = 0b0000 0000 0000 0010*/
    HAL_GPIO_PIN2 = 0x0004,  /**< PIN2 of whatever GPIO specified, value = 0b0000 0000 0000 0100*/
    HAL_GPIO_PIN3 = 0x0008,  /**< PIN3 of whatever GPIO specified, value = 0b0000 0000 0000 1000*/
    HAL_GPIO_PIN4 = 0x0010,  /**< PIN4 of whatever GPIO specified, value = 0b0000 0000 0001 0000*/
    HAL_GPIO_PIN5 = 0x0020,  /**< PIN5 of whatever GPIO specified, value = 0b0000 0000 0010 0000*/
    HAL_GPIO_PIN6 = 0x0040,  /**< PIN6 of whatever GPIO specified, value = 0b0000 0000 0100 0000*/
    HAL_GPIO_PIN7 = 0x0080,  /**< PIN7 of whatever GPIO specified, value = 0b0000 0000 1000 0000*/
    HAL_GPIO_PIN8 = 0x0100,  /**< PIN8 of whatever GPIO specified, value = 0b0000 0001 0000 0000*/
    HAL_GPIO_PIN9 = 0x0200,  /**< PIN9 of whatever GPIO specified, value = 0b0000 0010 0000 0000*/
    HAL_GPIO_PIN10 = 0x0400, /**< PIN10 of whatever GPIO specified, value = 0b0000 0100 0000 0000*/
    HAL_GPIO_PIN11 = 0x0800, /**< PIN11 of whatever GPIO specified, value = 0b0000 1000 0000 0000*/
    HAL_GPIO_PIN12 = 0x1000, /**< PIN12 of whatever GPIO specified, value = 0b0001 0000 0000 0000*/
    HAL_GPIO_PIN13 = 0x2000, /**< PIN13 of whatever GPIO specified, value = 0b0010 0000 0000 0000*/
    HAL_GPIO_PIN14 = 0x4000, /**< PIN14 of whatever GPIO specified, value = 0b0100 0000 0000 0000*/
    HAL_GPIO_PIN15 = 0x8000, /**< PIN15 of whatever GPIO specified, value = 0b1000 0000 0000 0000*/
    HAL_GPIO_MAX_PIN,        /**< this value shall never used by the user and it's only used by implementation code to verify input*/
} HAL_GPIO_Pins_t;

/**
 * @enum: HAL_GPIO_PinsOperation_t
 * @brief: constants used to to determine which operation to be performed on a GPIO pin.
 */
typedef enum
{
    HAL_GPIO_PIN_OP_WRITE_HIGH, /**< used to Write high on a pin*/
    HAL_GPIO_PIN_OP_WRITE_LOW,  /**< used to Write low on a pin*/
    HAL_GPIO_PIN_OP_TOGGLE,     /**< used to Write toggle a pin*/
    HAL_GPIO_MAX_PIN_OP,        /**< that value should never be used and it's only used by the implementation code for verifying the input*/
} HAL_GPIO_PinsOperation_t;

/******************************************************************************
 * Variables
 *******************************************************************************/

/******************************************************************************
 * Function Prototypes
 *******************************************************************************/

/**
 *  \b function                     :       HAL_GPIO_Init()
 *  \b Description                  :       this functions initialize the General purpose input/output configuration with the configurations supplied in "GPIO_config.h"
 *  @param                          :       None
 *  @note                           :       This shall be the first function to be called before using any other function in this interface, also it's a blocking function
 *                                          IT IS ADVISED TO CALL HAL_GPIO_Init() BEFORE CALLING ANY OTHER FUNCTION
 *  \b PRE-CONDITION                :       make sure to edit all configurations in file "GPIO_config.h" (any array labeled with @user_todo shall be edited)
 *  \b POST-CONDITION               :       it configures the GPIO pins regarding mode, speed, alternate functions, etc...
 *  @return                         :       it return one of error states indicating whether a failure or success happened during initialization (refer to @HAL_GPIO_ErrStates_t in "GPIO_header.h")
 *  @see                            :       HAL_GPIO_PinStateModify(uint16_t arg_u16GpioName, uint16_t arg_u16PinNumber, const uint8_t argConst_u8Operation)
 *  @see                            :       HAL_GPIO_PinStateRead(uint16_t arg_u16GpioName, uint16_t arg_u16PinNumber, uint8_t *const arg_constpu8State)
 *
 *  \b Example:
 * @code
 * #include "GPIO_header.h"
 * int main() {
 *  HAL_GPIO_ErrStates_t local_errState_t = HAL_GPIO_Init();    // make sure that you edited any array in "GPIO_config.h" labeled with @user_todo so that Power controller can be initialized correctly
 *  if (local_errState_t == HAL_GPIO_OK)
 *  {
 *      // GPIO initialized successfully
 *  }
 *  return 0;
 * }
 * @endcode
 *
 * <br><b> - HISTORY OF CHANGES - </b>
 * <table align="left" style="width:800px">
 * <tr><td> Date       </td><td> Software Version </td><td> Initials </td><td> Description </td></tr>
 * <tr><td> 03/09/2023 </td><td> 1.0.0            </td><td> AMS      </td><td> Interface Created </td></tr>
 * </table><br><br>
 * <hr>
 */
HAL_GPIO_ErrStates_t HAL_GPIO_Init();

/**
 *  \b function                                 :       HAL_GPIO_PinStateModify(uint16_t arg_u16GpioName, uint16_t arg_u16PinNumber, const uint8_t argConst_u8Operation)
 *  \b Description                              :       this functions is used to modify pin state.
 *  @param  arg_u16GpioName [IN]                :       this is input parameter and for possible values refer to @HAL_GPIO_Ports_t in "GPIO_header.h", this is input parameter which indicates which port to deal with..
 *  @param  arg_u16PinNumber [IN]               :       this is input parameter and for possible values refer to @HAL_GPIO_Pins_t in "GPIO_header.h", this is input parameter which indicates which pin to deal with.
 *  @param  argConst_u8Operation [IN]           :       this is input parameter and for possible values refer to @HAL_GPIO_PinsOperation_t in "GPIO_header.h", this is input parameter which indicates which operation to perform on the selected pins on the specified ports.
 *  @note                                       :       None.
 *  \b PRE-CONDITION                            :       make sure to call HAL_GPIO_Init().
 *  \b POST-CONDITION                           :       MCU pins status changes according to the desired operation.
 *  @return                                     :       it return one of error states indicating whether a failure or success happened (refer to @HAL_GPIO_ErrStates_t in "GPIO_header.h")
 *  @see                                        :       HAL_GPIO_Init()
 *  @see                                        :       HAL_GPIO_PinStateRead(uint16_t arg_u16GpioName, uint16_t arg_u16PinNumber, uint8_t *const arg_constpu8State)
 *
 *  \b Example:
 * @code
 * #include "GPIO_header.h"
 * int main() {
 *  HAL_GPIO_Init();    // make sure that you edited any array in "GPIO_config.h" labeled with @user_todo so that GPIO can be initialized correctly
 *  HAL_GPIO_ErrStates_t local_errState_t = HAL_GPIO_PinStateModify(HAL_GPIO_PORTC | HAL_GPIO_PORTG, HAL_GPIO_PIN7 | HAL_GPIO_PIN4, HAL_GPIO_PIN_OP_WRITE_HIGH);
 *  if (local_errState_t == HAL_GPIO_OK)
 *  {
 *      // Pins 7 and 4 on both ports C and G have a high state
 *  }
 *  return 0;
 * }
 * @endcode
 *
 * <br><b> - HISTORY OF CHANGES - </b>
 * <table align="left" style="width:800px">
 * <tr><td> Date       </td><td> Software Version </td><td> Initials </td><td> Description </td></tr>
 * <tr><td> 03/09/2023 </td><td> 1.0.0            </td><td> AMS      </td><td> Interface Created </td></tr>
 * </table><br><br>
 * <hr>
 */
HAL_GPIO_ErrStates_t HAL_GPIO_PinStateModify(uint16_t arg_u16GpioName, uint16_t arg_u16PinNumber, const uint8_t argConst_u8Operation);

/**
 *  \b function                                 :       HAL_GPIO_PinStateRead(uint16_t arg_u16GpioName, uint16_t arg_u16PinNumber, uint8_t *const arg_constpu8Operation)
 *  \b Description                              :       this functions is used to read pin state.
 *  @param  arg_u16GpioName [IN]                :       this is input parameter and for possible values refer to @HAL_GPIO_Ports_t in "GPIO_header.h", this is input parameter which indicates which port to deal with..
 *  @param  arg_u16PinNumber [IN]               :       this is input parameter and for possible values refer to @HAL_GPIO_Pins_t in "GPIO_header.h", this is input parameter which indicates which pin to deal with.
 *  @param  arg_constpu8State [OUT]             :       this is output parameter which indicates which holds the address of the variable to which it will write the state of the pin, for possible states refer to @LIB_CONSTANTS_LogicalStates_t in "constants.h".
 *  @note                                       :       None.
 *  \b PRE-CONDITION                            :       make sure to call HAL_GPIO_Init().
 *  \b POST-CONDITION                           :       None.
 *  @return                                     :       it return one of error states indicating whether a failure or success happened (refer to @HAL_GPIO_ErrStates_t in "GPIO_header.h")
 *  @see                                        :       HAL_GPIO_Init()
 *  @see                                        :       HAL_GPIO_PinStateModify(uint16_t arg_u16GpioName, uint16_t arg_u16PinNumber, const uint8_t argConst_u8Operation)
 *
 *  \b Example:
 * @code
 * #include "GPIO_header.h"
 * int main() {
 *  HAL_GPIO_Init();    // make sure that you edited any array in "GPIO_config.h" labeled with @user_todo so that GPIO can be initialized correctly
 *  uint8_t state = 0;
 *  HAL_GPIO_ErrStates_t local_errState_t = HAL_GPIO_PinStateRead(HAL_GPIO_PORTC, HAL_GPIO_PIN7, &state);
 *  if (local_errState_t == HAL_GPIO_OK)
 *  {
 *      // state of pin 7 on port C is written into variable state
 *  }
 *  return 0;
 * }
 * @endcode
 *
 * <br><b> - HISTORY OF CHANGES - </b>
 * <table align="left" style="width:800px">
 * <tr><td> Date       </td><td> Software Version </td><td> Initials </td><td> Description </td></tr>
 * <tr><td> 03/09/2023 </td><td> 1.0.0            </td><td> AMS      </td><td> Interface Created </td></tr>
 * </table><br><br>
 * <hr>
 */
HAL_GPIO_ErrStates_t HAL_GPIO_PinStateRead(uint16_t arg_u16GpioName, uint16_t arg_u16PinNumber, uint8_t *const arg_constpu8State);

/*** End of File **************************************************************/
#endif /*HAL_GPIO_HEADER_H_*/