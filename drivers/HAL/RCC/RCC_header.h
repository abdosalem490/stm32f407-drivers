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

/******************************************************************************
 * Preprocessor Constants
 *******************************************************************************/

/******************************************************************************
 * Configuration Constants
 *******************************************************************************/

/******************************************************************************
 * Tables
 *******************************************************************************/

/**
 * @ref: Clock tree
 * ============================================================================================================================================================================================
 *                    |
 *                    |
 *                    |                                                                                                   |=====|
 *                    |         *--------*      LSI                                               Watchdog enable ----->--| AND |-->-----> IWDGCLK --> (to independent watchdog)
 *                    |         | LSI RC |-----------------------------+----------------------------------------------->--|     |
 *                    |         | 32 kHz |                             |                                                  |=====|
 *                    |         *--------*                             |                RTCS EL[1:0]
 *                    |                                                |                     |
 *                    |                                                |                  |=====|                          |=====|
 *                    |    *------------*                              +--------------->--| MUX |       RTC enable ----->--| AND |-->-------> RTCCLK ---> (to RTC)
 * OSC32_IN-----------X----| LSE OSC    |-->----------------------------+-------------->--|     |-->-------------------->--|     |
 * OSC32_OUT----------X----| 32.768kHz  |                               |            +->--|     |                          |=====|
 *                    |    *------------*                               |            |    |=====|
 *                    |                                         LSE O---+            |
 *                    |                                                              |
 *                    |                                                              |
 *                    |                                       *---------*    HSE_RTC |
 *                    |                           HSE O-------| /2to 31 |-->---------+
 *                    |                                       *---------*
 *                    |
 *                    |
 *                    |
 *                    |                        |=====|
 *                    |                        |     |--<-- SYSCLK
 *                    |      *---------*       | MUX |--<--O PLLI2SCLK
 * MCO2---------------X------| /1 to 5 |--<----|     |--<--O HSE
 *                    |      *---------*       |     |--<--O PLLCLK
 *                    |                        |=====|
 *                    |
 *                    |
 *                    |                        |=====|
 *                    |                        |     |--<--O LSE
 *                    |      *---------*       | MUX |--<--O PLLI2SCLK
 * MCO1---------------X------| /1 to 5 |--<----|     |--<--O HSI
 *                    |      *---------*       |     |--<--O PLLCLK
 *                    |                        |=====|
 *                    |
 *                    |                                                                                                                   |=====|
 *                    |                                             Peripheral clock enable ------------------------------------------->--| AND |-->----> Ethernet PTP clock
 *                    |                                                                                        +----------------------->--|     |
 *                    |                                                                                        |                          |=====|
 *                    |                                                                                        |
 *                    |                                                                                        |                                                             |=====|
 *                    |                                                                                        |                     Clock Enable ------------------------>--| AND |-->------> HCLK to AHB bus, core, memory and DMA.
 *                    |                                                                                        |                                                     +---->--|     |
 *                    |                                                                                        |                                     168 MHz max     |       |=====|
 *                    |                                                                                        |                                    +----------------+
 *                    |                                                                                        |                                    |                       *----*
 *                    |                                                                                        |                                    +-------------------->--| /8 |-->-------------------> to Cortex System timer
 *                    |                                                                                        |                                    |                       *----*
 *                    |                                                       SW --+                           |                                    |
 *                    |                                                            |                           |                                    +----------------------------------------------------> FCLK Cortex free-running clock
 *                    |                                                         |=====|                        |                                    |
 *                    |                                             HSI O---->--| MUX |    SYSCLK 168 MHz max  |         *------------*             |
 *                    |                                             HSE O---->--|     |-->---------------------+------>--| AHB PRESC  |-->----------+
 *                    |                                          PLLCLK O---->--|     |                                  | /1,2,..512 |             |
 *                    |                                                         |=====|                                  *------------*             |                                                                                  |=====|
 *                    |                                                                                                                             |           *--------------*                   Peripheral clock enable --------->--| AND |-->-----------> APBx peripheral clocks
 *                    |         *--------*                                                                                                          +-------->--| APBx PRESC   |-------------+-------------------------------------->--|     |
 *                    |         | HSI RC |--->----O HSI                                                                                                         | / 1,2,4,8,16 |             |                                         |=====|
 *                    |         | 16 MHz |                                                                                                                      *--------------*             |
 *                    |         *--------*                                                                                                                                                   |
 *                    |                                                                                                                                                                      |                                                        |=====|
 *                    |                                                                                                                                                                      |      Peripheral clock enable ----------------------->--| AND |-->------> APBx timer clocks
 *                    |                                                                                                                                                                      |                                           +--------->--|     |
 *                    |                                                                                                                                                                      |                                           |            |=====|
 *                    |                                                                                                                                                                      |          *------------------------*       |
 *                    |                                                                                                                                                                      +------->--| if (APBx presc = 1) x1 |-------+
 *                    |                                                                                                                                                                                 | else x2                |
 *                    |                                                                                                                                                                                 *------------------------*
 *                    |    *-----------*
 * OSC_OUT------------X----| 4-26 MHz  |----->-------O HSE
 * OSC_IN-------------X----| HSE OSC   |
 *                    |    *-----------*
 *                    |
 *                    |
 *                    |
 *                    |
 *                    |                                          +-->--O Label_1
 *                    |                                          |
 *                    |  *-----------------------------------*   |
 *                    |  |                                   |   |     *----*          |=====|
 *                    |  |  +--------------------------------X---+--<--| /M |---<------| MUX |--<---O HSI
 *                    |  |  |                                |         *----*          |     |--<---O HSE
 *                    |  |  |                                |                         |=====|
 *                    |  |  |    *-----*            *----*   |                                                                              |=====|
 *                    |  |  +----| VCO |---+----+---| /P |---+------------>--O PLLCLK                       Peripheral clock enable------>--| AND |
 *                    |  |  |    *-----*   |    |   *----*   |                                                                       +------|     |----> 48 MHz clocks
 *                    |  |  |              |    |   *----*   |      PLL48CK                                                          |      |=====|
 *                    |  |  |   *----*     |    +---| /Q |---+-----------------------------------------------------------------------+
 *                    |  |  +---| xN |-----+    |   *----*   |
 *                    |  |      *----*          |   *----*   |
 *                    |  |                      +---| /R |---+
 *                    |  |                          *----*   |
 *                    |  |                                   |
 *                    |  |  *PLL*                            |
 *                    |  *-----------------------------------*
 *                    |
 *                    |
 *                    |  *-----------------------------------*
 *                    |  |                                   |
 *                    |  |  +--------------------------------X------------<--O Label_1
 *                    |  |  |                                |
 *                    |  |  |    *-----*            *----*   |
 *                    |  |  +----| VCO |---+----+---| /P |---+
 *                    |  |  |    *-----*   |    |   *----*   |
 *                    |  |  |              |    |   *----*   |
 *                    |  |  |   *----*     |    +---| /Q |---+
 *                    |  |  +---| xN |-----+    |   *----*   |
 *                    |  |      *----*          |   *----*   |
 *                    |  |                      +---| /R |---+            +------O PLLI2SCLK
 *                    |  |                          *----*   |            |
 *                    |  |                                   |  PLLI2SCLK |
 *                    |  |  *PLLI2S*                         |------------+       I2SSRC
 *                    |  *-----------------------------------*            |          |
 *                    |                                                   |       |=====|                                               |=====|
 *                    |                                  Ext. clock       +---->--| MUX |               Peripheral clock enable------>--| AND |
 *  I2S_CKIN----------X-------------------------------------------------------->--|     |->------------------------------------------>--|     |->----> I2S clocks
 *                    |                                                           |=====|                                               |=====|
 *                    |
 *                    |
 *                    |
 *                    |
 *                    |
 *                    |
 *                    |                                                                                                                                 to Ethernet MAC
 * *--------------*   |  ETH_MII_TX_CLK_MII                         |=====|                                                         |=====|
 * | PHY Ethernet |---X--------------------->-------------------->--| MUX |                         Peripheral clock enable------>--| AND |
 * | 25 to 50 MHz |   |                                 +-------->--|     |->---------------------------------------------------->--|     |-->-----> MACTXCLK
 * |              |   |                                 |           |=====|                                                         |=====|
 * |              |   |                 *-------*       |              |
 * |              |---X---------+-------| /2,20 |-------+   MII_RMII_SEL in SYSCFG_PMC
 * *--------------*   |         |       *-------*       |              |
 *                    |         |                       |           |=====|                                                         |=====|
 *                    |         |  ETH_MII_RX_CLK_MII   +-------->--| MUX |                         Peripheral clock enable------>--| AND |
 *                    |         +-------------------------------->--|     |-->------------------------------------------------------|     |-->----> MACRXCLK
 *                    |         |                                   |=====|                                                         |=====|
 *                    |         |
 *                    |         |                                                                                                   |=====|
 *                    |         |                                                                   Peripheral clock enable------>--| AND |
 *                    |         +------------------------------------------------------------------------------------------------>--|     |-->----> MACRMIICLK
 *                    |                                                                                                             |=====|
 *                    |
 *                    |
 *                    |
 *                    |                                                                                                             |=====|
 * *--------------*   |         OTG_HS_ULPI_CK                                                      Peripheral clock enable------>--| AND |
 * | USB2.0 PHY   |---X---------------------------------------------------------------------------------------------------------->--|     |-->------> USBHS ULPI clock
 * | 24 to 60 MHz |   |                                                                                                             |=====|
 * *--------------*   |
 *                    |
 *                    |
 * ===========================================================================================================================================================================================
 *
 */

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
 * @enum: Hal_RCC_ErrStates_t
 * @brief: contains all possible errors that can result from dealing with the Reset and clock control.
 */
typedef enum
{
    HAL_RCC_OK,                 /**< it means everything has gone as intended so no errors*/
    HAL_RCC_ERR_INVALID_PARAMS, /**< it means that the supplied parameters of the function are invalid*/
    HAL_RCC_ERR_INVALID_CONFIG, /**< it means that the supplied configurations in the "RCC_config.h" file are incorrect*/
} HAL_RCC_ErrStates_t;

/**
 * @enum: HAL_RCC_Mode_t
 * @brief: contains all possible errors that can result from dealing with the power controller.
 */
typedef enum
{
    HAL_MODE_RUN,     /**< CPU is clocked by HCLK and the program code is executed. (normal run)*/
    HAL_MODE_SLEEP,   /**< Cortex®-M4 with FPU core stopped, peripherals kept running (lowest power saving with the least latency) */
    HAL_MODE_STOP,    /**< all clocks are stopped (moderate power saving with the moderate latency)*/
    HAL_MODE_STANDBY, /**< 1.2 V domain powered off (highest power saving with the highest latency)*/
    HAL_RCC_MAX_MODE, /**< this value shall never used by the user and it's only used by implementation code to verify input*/
} HAL_RCC_PeripheralsModify_t;

/**
 * @enum: HAL_RCC_VAL_SleepMethod_t
 * @brief: contains all possibles values regarding how to enter sleep mode.
 */
typedef enum
{
    HAL_RCC_VAL_SLEEP_METHOD_WFE, /**< this makes MCU waits for event to occur while sleeping, refer to @DIFF_BETWEEN_WFI_AND_WFE in "RCC_header" to know difference between WFE and WFI*/
    HAL_RCC_VAL_SLEEP_METHOD_WFI, /**< this makes MCU waits for interrupt to occur while sleeping, refer to @DIFF_BETWEEN_WFI_AND_WFE in "RCC_header" to know difference between WFE and WFI*/
    HAL_RCC_MAX_VAL_SLEEP_METHOD, /**< this value shall never used by the user and it's only used by implementation code to verify input*/
} HAL_RCC_VAL_SleepMethod_t;

/**
 * @enum: HAL_RCC_ConfigKeys_t
 * @brief: contains all possibles keys of configuration that can be edited during runtime, each value inside this enum has a comment telling where to find the the corresponding possible values.
 */
typedef enum
{
    HAL_RCC_KEY_SLEEP_METHOD,          /**< for possible corresponding values refer to @HAL_RCC_VAL_SleepMethod_t in "RCC_header.h", it indicates how the MCU shall enter the sleep mode*/
    HAL_RCC_KEY_SLEEP_EXIT_ISR_ENABLE, /**< for for possible values refer to @LIB_CONSTANTS_DriverStates_t in "constants.h", it indicates whether to enable or disable sleeping on exit from ISR*/
    HAL_RCC_MAX_CONFIG_KEYS,           /**< this value shall never used by the user and it's only used by implementation code to verify input*/
} HAL_RCC_ConfigKeys_t;

/**
 * @enum: HAL_RCC_CallbacksTypes_t
 * @brief: constants used to as key to register a callback when a specific even happens
 */
typedef enum
{
    HAL_RCC_CALLBACK_PVD_LEVEL, /**< used to tell*/
    HAL_RCC_MAX_CALLBACK_TYPE,  /**< that value should never be used and it's only used by the implementation code for verifying the input*/
} HAL_RCC_CallbacksTypes_t;

/******************************************************************************
 * Variables
 *******************************************************************************/

/******************************************************************************
 * Function Prototypes
 *******************************************************************************/

/**
 *  \b function                     :       HAL_RCC_Init()
 *  \b Description                  :       this functions initialize the power controller configuration with the configurations supplied in "RCC_config.h"
 *  @param                          :       None
 *  @note                           :       This shall be the first function to be called before using any other function in this interface, also it's a blocking function
 *                                          IT IS ADVISED TO CALL HAL_RCC_Init() BEFORE CALLING ANY OTHER FUNCTION
 *  \b PRE-CONDITION                :       make sure to edit all configurations in file "RCC_config.h" (any array labeled with @user_todo shall be edited)
 *  \b POST-CONDITION               :       it configures the following properties of RCC memory:
 *                                              -> Regulator voltage scaling output selection
 *                                              -> Flash power-down in Stop mode enablement
 *                                              -> PVD level selection
 *                                              -> Power voltage detector enable
 *                                              -> Enable WKUP pin
 *  @return                         :       it return one of error states indicating whether a failure or success happened during initialization (refer to @HAL_RCC_ErrStates_t in "RCC_header.h")
 *  @see                            :       HAL_RCC_EnterMode(const uint8_t argConst_u8Mode)
 *  @see                            :       HAL_RCC_Config(const uint8_t argConst_u8Key, const uint8_t argConst_u8Value)
 *  @see                            :       HAL_RCC_RegisterCallback(const uint8_t argConst_u8CallBackType, const functionCallBack_t argConst_pFunctionCallBack)
 *
 *  \b Example:
 * @code
 * #include "RCC_header.h"
 * int main() {
 *  HAL_RCC_ErrStates_t local_errState_t = HAL_RCC_Init();    // make sure that you edited any array in "RCC_config.h" labeled with @user_todo so that Power controller can be initialized correctly
 *  if (local_errState_t == HAL_RCC_OK)
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
HAL_RCC_ErrStates_t HAL_RCC_Init();

/**
 *  \b function                             :       HAL_RCC_EnterMode(const uint8_t argConst_u8Mode)
 *  \b Description                          :       this functions is used to enter one of the sleep modes or return to the run mode.
 *  @param  argConst_u8Mode [IN]            :       for possible values refer to @HAL_RCC_Mode_t in "RCC_header.h", this is input parameter which indicates which mode to switch to.
 *  @note                                   :       the function will return in run mode unless interrupt/event happened (it's not possible the function will return while MCU is in sleep mode).
 *  \b PRE-CONDITION                        :       make sure to call HAL_RCC_Init() and there is no interrupt/event pending.
 *  \b POST-CONDITION                       :       MCU enters to the selected mode.
 *  @return                                 :       it return one of error states indicating whether a failure or success happened during writing of data (refer to @HAL_RCC_ErrStates_t in "RCC_header.h")
 *  @see                                    :       HAL_RCC_Init()
 *  @see                                    :       HAL_RCC_Config(const uint8_t argConst_u8Key, const uint8_t argConst_u8Value)
 *  @see                                    :       HAL_RCC_RegisterCallback(const uint8_t argConst_u8CallBackType, const functionCallBack_t argConst_pFunctionCallBack)
 *  \b Example:
 * @code
 * #include "RCC_header.h"
 * int main() {
 * HAL_RCC_Init();    // make sure that you edited any array in "RCC_config.h" labeled with @user_todo so that Power controller can be initialized correctly
 * HAL_RCC_ErrStates_t local_errState_t = HAL_RCC_EnterMode(HAL_MODE_STOP);
 * if (local_errState_t == HAL_RCC_OK)
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
HAL_RCC_ErrStates_t HAL_RCC_EnterMode(const uint8_t argConst_u8Mode);

/**
 *  \b function                             :       HAL_RCC_Config(const uint8_t argConst_u8Key, const uint8_t argConst_u8Value)
 *  \b Description                          :       this functions is used to change the behavior of the functions by changing some key configuration values during runtime.
 *  @param  argConst_u8Key [IN]             :       this is input parameter which is key of the parameter to be changed, for possible values refer to @HAL_RCC_ConfigKeys_t in "RCC_header.h".
 *  @param  argConst_u8Value [IN]           :       this is input parameter which value of configuration to be assigned to the corresponding selected key. for possible values, every key has its set of values, refer to @HAL_RCC_ConfigKeys_t in "RCC_header.h" as the possible values are written as comments for every key.
 *  @note                                   :       None.
 *  \b PRE-CONDITION                        :       None.
 *  \b POST-CONDITION                       :       it changes the behavior of some functions of the interface.
 *  @return                                 :       it return one of error states indicating whether a failure or success happened during the edit of configuration (refer to @HAL_RCC_ErrStates_t in "RCC_header.h")
 *  @see                                    :       HAL_RCC_Init()
 *  @see                                    :       HAL_RCC_EnterMode(const uint8_t argConst_u8Mode)
 *  @see                                    :       HAL_RCC_RegisterCallback(const uint8_t argConst_u8CallBackType, const functionCallBack_t argConst_pFunctionCallBack)
 *  \b Example:
 * @code
 * #include "RCC_header.h"
 * int main() {
 *  HAL_RCC_Init();    // make sure that you edited any array in "RCC_config.h" labeled with @user_todo so that Power controller can be initialized correctly
 *  HAL_RCC_ErrStates_t local_errState_t = HAL_RCC_Config(HAL_RCC_KEY_SLEEP_METHOD, HAL_RCC_VAL_SLEEP_METHOD_WFE);
 *  if (local_errState_t == HAL_RCC_OK)
 *  {
 *      HAL_RCC_EnterMode(HAL_MODE_STOP);   // function will use instruction WFE to enter the STOP mode
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
HAL_RCC_ErrStates_t HAL_RCC_Config(const uint8_t argConst_u8Key, const uint8_t argConst_u8Value);

/**
 *  \b function                             :       HAL_RCC_RegisterCallback(const uint8_t argConst_u8CallBackType, const functionCallBack_t argConst_pFunctionCallBack)
 *  \b Description                          :       this functions is used to register a callback function to be executed from user code when an interrupt happens.
 *  @param  argConst_u8CallBackType [IN]    :       this is input parameter indicates which interrupt handler to attach this function to, for possible values, refer to  @HAL_RCC_CallbacksTypes_t in "RCC_header.h"
 *  @param  argConst_pFunctionCallBack [IN] :       this is the function to be called when the specified action interrupt happens.
 *  @note                                   :       None.
 *  \b PRE-CONDITION                        :       make sure to call HAL_RCC_Init() and make sure the address of function is valid address and the interrupts are enabled for that event.
 *  \b POST-CONDITION                       :       assign the given function to a specific action.
 *  @return                                 :       it return one of error states indicating whether a failure or success happened during the registration of callbacks (refer to @HAL_RCC_ErrStates_t in "RCC_header.h")
 *  @see                                    :       HAL_RCC_Init()
 *  @see                                    :       HAL_RCC_EnterMode(const uint8_t argConst_u8Mode)
 *  @see                                    :       HAL_RCC_Config(const uint8_t argConst_u8Key, const uint8_t argConst_u8Value)
 *  \b Example:
 * @code
 * #include "RCC_header.h"
 *
 * int code = 0;
 * void levelChange(void)    // this function is to be called when PVD level is under a specific volt level.
 * {
 *  code = 1;
 * }
 *
 * int main() {
 *  HAL_RCC_Init();    // make sure that you edited any array in "RCC_config.h" labeled with @user_todo so that power controller can be initialized correctly
 *  HAL_RCC_ErrStates_t error_state;
 *
 *  HAL_RCC_RegisterCallback(HAL_RCC_CALLBACK_PVD_LEVEL, levelChange);  // when PVD level is less/more than a specific threshold specified int "RCC_config.h" function called "levelChange()" will be called
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
HAL_RCC_ErrStates_t HAL_RCC_RegisterCallback(const uint8_t argConst_u8CallBackType, const functionCallBack_t argConst_pFunctionCallBack);

/*** End of File **************************************************************/
#endif /*HAL_RCC_HEADER_H_*/