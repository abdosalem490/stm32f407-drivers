/**
 * --------------------------------------------------------------------------------------------------------------------------------------
 * |    @title          :   Reset and clock control                                                                                     |
 * |    @file           :   RCC_config.h                                                                                                |
 * |    @author         :   Abdelrahman Mohamed Salem                                                                                   |
 * |    @origin_date    :   26/08/2023                                                                                                  |
 * |    @version        :   1.0.0                                                                                                       |
 * |    @tool_chain     :   GNU Tools for STM32                                                                                         |
 * |    @compiler       :   GCC                                                                                                         |
 * |    @C_standard     :   ISO C99 (-std=c99)                                                                                          |
 * |    @target         :   stm32f407VGTX                                                                                               |
 * |    @notes          :   None                                                                                                        |
 * |    @license        :   MIT License                                                                                                 |
 * |    @brief          :   this header file contains configurations related to the Reset and clock control (RCC)                       |                                                               |
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

#ifndef HAL_RCC_CONFIG_H_
#define HAL_RCC_CONFIG_H_

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
 * @reason: hold possible values for HAL_RCC_Peripherals_t
 */
#include "RCC_header.h"

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
 * @ref: @HAL_RCC_CLOCK_TREE
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

/**
 * @ref: HAL_RCC_INFO_SYSTEM
 * @brief: these are things that's connected to SYSCLK
 *      -> Ethernet PTP clock
 *      -> HCLK to AHB bus, core, memory and DMA
 *      -> Cortex System timer
 *      -> FCLK Cortex free-running clock
 *      -> APBx peripheral clocks
 *      -> APBx timer clocks
 */

/**
 * @ref: HAL_RCC_INFO_AHB_PERIPHERALS
 * @brief: defines which peripherals are on AHB bus:
 *  -> FSMC control
 *  -> RNG
 *  -> HASH
 *  -> CRYP
 *  -> DCMI
 *  -> USB OTG FS
 *  -> USB OTG HS
 *  -> DMA2D
 *  -> ETHERNET MAC
 *  -> DMA2
 *  -> DMA1
 *  -> BKPSRAM
 *  -> Flash interface
 *  -> RCC
 *  -> CRC
 *  -> GPIOK
 *  -> GPIOJ
 *  -> GPIOI
 *  -> GPIOH
 *  -> GPIOG
 *  -> GPIOF
 *  -> GPIOE
 *  -> GPIOD
 *  -> GPIOC
 *  -> GPIOB
 *  -> GPIOA
 *  -> GPIOA
 */

/**
 * @ref: HAL_RCC_INFO_APB2_PERIPHERALS
 * @brief: defines which peripherals are on APB2 bus:
 *  -> LCD-TFT
 *  -> SAI1
 *  -> SPI6
 *  -> SPI5
 *  -> TIM11
 *  -> TIM10
 *  -> TIM9
 *  -> EXTI
 *  -> SYSCFG
 *  -> SPI4
 *  -> SPI1
 *  -> SDIO
 *  -> ADC1 - ADC2 - ADC3
 *  -> USART6
 *  -> USART1
 *  -> TIM8
 *  -> TIM1
 */

/**
 * @ref: HAL_RCC_INFO_APB1_PERIPHERALS
 * @brief: defines which peripherals are on APB1 bus:
 *  -> UART8
 *  -> UART7
 *  -> DAC
 *  -> PWR
 *  -> CAN2
 *  -> CAN1
 *  -> I2C3
 *  -> I2C2
 *  -> I2C1
 *  -> UART5
 *  -> UART4
 *  -> USART3
 *  -> USART2
 *  -> I2S3ext
 *  -> SPI3 / I2S3
 *  -> SPI2 / I2S2
 *  -> I2S2ext
 *  -> IWDG
 *  -> WWDG
 *  -> RTC & BKP Registers
 *  -> TIM14
 *  -> TIM13
 *  -> TIM12
 *  -> TIM7
 *  -> TIM6
 *  -> TIM5
 *  -> TIM4
 *  -> TIM3
 *  -> TIM2
 */
/******************************************************************************
 * Typedefs
 *******************************************************************************/

/**
 * @enum: HAL_RCC_RTC_ClockSource_t
 * @brief: used to select clock source for RTC
 */
typedef enum
{
    HAL_RCC_RTC_CLK_SRC_LSE = 1, /**< LSE (Low Speed External clock) whose value is 32.768 KHZ*/
    HAL_RCC_RTC_CLK_SRC_LSI = 2, /**< LSI (Low Speed Internal clock) whose value is 32 KHZ*/
    HAL_RCC_RTC_CLK_SRC_HSE = 3, /**< HSE (High Speed External clock) whose value is in range of 4 to 26 MHz*/
    HAL_RCC_MAX_RTC_CLK_SRC,     /**< this value shall never used by the user and it's only used by implementation code to verify input*/
} HAL_RCC_RTC_ClockSource_t;

/**
 * @enum: HAL_RCC_MCO1_ClockSource_t
 * @brief: used to select clock source for RTC
 * @note: THE MCO1 OUTPUT CLOCK FREQUENCY MUST BE LESS THAN 100MHZ THAT'S WHY THERE IS A PRESCALAR TO DECREASE THE FREQUENCY IF IT'S MORE THAN 100 MHZ
 */
typedef enum
{
    HAL_RCC_MCO1_CLK_SRC_HSI = 0, /**< HSI (High Speed Internal clock) whose value is 16 MHZ, @note: HSI has to be enabled*/
    HAL_RCC_MCO1_CLK_SRC_LSE = 1, /**< LSE (Low Speed External clock) whose value is 32.768 KHZ, @note: LSE has to be enabled*/
    HAL_RCC_MCO1_CLK_SRC_HSE = 2, /**< HSE (High Speed External clock) whose value is in range of 4 to 26 MHz, @note: HSE has to be enabled*/
    HAL_RCC_MCO1_CLK_SRC_PLL = 3, /**< PLL (Phase locked loop) whose value varies from few MHZ to hundreds of MHZ, @note: PLL has to be enabled and PLL has to be configured*/
    HAL_RCC_MAX_MCO1_CLK_SRC,     /**< this value shall never used by the user and it's only used by implementation code to verify input*/
} HAL_RCC_MCO1_ClockSource_t;

/**
 * @enum: HAL_RCC_MCO2_ClockSource_t
 * @brief: used to select clock source for RTC
 * @note: THE MCO2 OUTPUT CLOCK FREQUENCY MUST BE LESS THAN 100MHZ THAT'S WHY THERE IS A PRESCALAR TO DECREASE THE FREQUENCY IF IT'S MORE THAN 100 MHZ
 */
typedef enum
{
    HAL_RCC_MCO2_CLK_SRC_SYSCLK = 0, /**< SYSCLK (System clock) which is clock feed into the most of the system , @note: SYSCLK has to configured*/
    HAL_RCC_MCO2_CLK_SRC_PLLI2S = 1, /**< PLLI2S (Phase locked loop for I2S communication) whose value varies from few MHZ to hundreds of MHZ, @note: PLLI2S has to be enabled and configured*/
    HAL_RCC_MCO2_CLK_SRC_HSE = 2,    /**< HSE (High Speed External clock) whose value is in range of 4 to 26 MHz, @note: HSE has to be enabled*/
    HAL_RCC_MCO2_CLK_SRC_PLL = 3,    /**< PLL (Phase locked loop) whose value varies from few MHZ to hundreds of MHZ, @note: PLL has to be enabled and PLL has to be configured*/
    HAL_RCC_MAX_MCO2_CLK_SRC,        /**< this value shall never used by the user and it's only used by implementation code to verify input*/
} HAL_RCC_MCO2_ClockSource_t;

/**
 * @enum: HAL_RCC_MCO2_ClockSource_t
 * @brief: used to select clock source for RTC
 * @note: THE MCO2 OUTPUT CLOCK FREQUENCY MUST BE LESS THAN 100MHZ THAT'S WHY THERE IS A PRESCALAR TO DECREASE THE FREQUENCY IF IT'S MORE THAN 100 MHZ
 */
typedef enum
{
    HAL_RCC_SYSCLK_CLK_SRC_HSI = 0, /**< HSI (High Speed Internal clock) whose value is 16 MHZ, @note: HSI has to be enabled*/
    HAL_RCC_SYSCLK_CLK_SRC_HSE = 1, /**< HSE (High Speed External clock) whose value is in range of 4 to 26 MHz, @note: HSE has to be enabled*/
    HAL_RCC_SYSCLK_CLK_SRC_PLL = 2, /**< PLL (Phase locked loop) whose value varies from few MHZ to hundreds of MHZ, @note: PLL has to be enabled and PLL has to be configured*/
    HAL_RCC_MAX_SYSCLK_CLK_SRC,     /**< this value shall never used by the user and it's only used by implementation code to verify input*/
} HAL_RCC_SYSCLK_ClockSource_t;

/**
 * @enum: HAL_RCC_PLL_ClockSource_t
 * @brief: used to select clock source for PLL.
 */
typedef enum
{
    HAL_RCC_PLL_CLK_SRC_HSI = 0, /**< HSI (High Speed Internal clock) whose value is 16 MHZ, @note: HSI has to be enabled*/
    HAL_RCC_PLL_CLK_SRC_HSE = 1, /**< HSE (High Speed External clock) whose value is in range of 4 to 26 MHz, @note: HSE has to be enabled*/
    HAL_RCC_MAX_PLL_CLK_SRC,     /**< this value shall never used by the user and it's only used by implementation code to verify input*/
} HAL_RCC_PLL_ClockSource_t;

/**
 * @enum: HAL_RCC_I2S_ClockSource_t
 * @brief: used to select clock source for I2S.
 */
typedef enum
{
    HAL_RCC_I2S_CLK_SRC_PLLI2S = 0,  /**< PLLI2S (Phase locked loop for I2S communication) whose value varies from few MHZ to hundreds of MHZ, @note: PLLI2S has to be enabled and configured*/
    HAL_RCC_I2S_CLK_SRC_EXT_I2S = 1, /**< external clock supplied to I2S_CKIN.*/
    HAL_RCC_MAX_I2S_CLK_SRC,         /**< this value shall never used by the user and it's only used by implementation code to verify input*/
} HAL_RCC_I2S_ClockSource_t;

/**
 * @struct: HAL_RTC_ClockSources
 * @brief: used to configure the RTC (real time clock) clock source and their prescalars
 */
typedef struct
{
    uint8_t RTCClockSource; /**< for possible values refer to @HAL_RCC_RTC_ClockSource_t in "RCC_config.h" and it's used to select the clock source for RTC*/
} HAL_RCC_RTC_ClockConfig_t;

/**
 * @struct: HAL_RCC_ClockSources
 * @brief: used to configure all the clock sources for your MCU, refer to @HAL_RCC_CLOCK_TREE in "RCC_config.h" to see the clock tree
 */
typedef struct
{
    uint8_t MCO1Enable;      /**< for possible values refer to @LIB_CONSTANTS_DriverStates_t in "constants.h", used to enable MCO1 output so that pin will be configured as MCO1 not GPIO*/
    uint8_t MCO1ClockSource; /**< for possible values refer to @HAL_RCC_MCO1_ClockSource_t in "RCC_config.h", used to select a clock source for MCO1*/
    uint8_t MCO1Prescalar;   /**< possible values are integers from 1 to 5, note that MCO1 clock frequency has to be less than 100 MHZ that's why you shall use the prescalar to divide the clock by that prescalar*/
    uint8_t MCO2Enable;      /**< for possible values refer to @LIB_CONSTANTS_DriverStates_t in "constants.h", used to enable MCO2 output so that pin will be configured as MCO2 not GPIO*/
    uint8_t MCO2ClockSource; /**< for possible values refer to @HAL_RCC_MCO2_ClockSource_t in "RCC_config.h", used to select a clock source for MCO2*/
    uint8_t MCO2Prescalar;   /**< possible values are integers from 1 to 5, note that MCO2 clock frequency has to be less than 100 MHZ that's why you shall use the prescalar to divide the clock by that prescalar*/
} HAL_RCC_MCOClockConfig_t;

/**
 * @struct: HAL_RCC_SYSCLK_ClockConfig_t
 * @brief: used to configure system clock that's fed into most of the system (anything that's doesn't have clock configuration here is configured by SYSCLK)
 * @note: cortex timer is fed by SYSCLK through /8 Prescalar. THE AHB CLOCK FREQUENCY MUST BE AT LEAST 25 MHZ WHEN THE ETHERNET IS USED.
 */
typedef struct
{
    uint8_t SYSClkClockSource;        /**< for possible values refer to @HAL_RCC_SYSCLK_ClockSource_t in "RCC_config.h", used to select a clock source for System clock that's feed into most system, refer to @HAL_RCC_INFO_SYSTEM in "RCC_config.h" to know what's fed by SYSCLK, @Note: max clock frequency for SYSCLK is 168 MHz so don't try and burn it up*/
    uint16_t SYSCLK_to_AHB_Prescalar; /**< possible values are 1, 2, 4, 8, 16, 64, 128, 256, 512. refer to @HAL_RCC_INFO_APB1_PERIPHERALS in "RCC_config.h" to know what peripherals are on this bus. this is used to divide SYSCLK by the selected value to pass it through all AHB buses to decrease power consumption, @Note: Max AHB BUS FREQUENCY IS 168 MHZ.*/
    uint8_t AHB_to_APB1_Prescalar;    /**< possible values are 1, 2, 4, 8, 16. refer to @HAL_RCC_INFO_APB1_PERIPHERALS in "RCC_config.h" to know what peripherals are on this bus. this is used to divide AHB clock by the selected value to pass it through all APB1 buses to decrease power consumption, @Note: Max AHB BUS FREQUENCY IS 42 MHZ.*/
    uint8_t AHB_to_APB2_Prescalar;    /**< possible values are 1, 2, 4, 8, 16. refer to @HAL_RCC_INFO_APB2_PERIPHERALS in "RCC_config.h" to know what peripherals are on this bus. this is used to divide AHB clock by the selected value to pass it through all APB1 buses to decrease power consumption, @Note: Max AHB BUS FREQUENCY IS 84 MHZ.*/
} HAL_RCC_SYSCLK_ClockConfig_t;

/**
 * @struct: HAL_RCC_PLL_ClockConfig_t
 * @brief: used to configure PLL (Phase locked loop) to generate high frequencies (support wide variety of frequencies).
 */
typedef struct
{
    uint8_t PLLClockSource;     /**< for possible values refer to @HAL_RCC_PLL_ClockSource_t in "RCC_config.h", used to select a clock source for PLL (phase locked loop) that's can selected later as source of other clocks.*/
    uint32_t PLLOutputValue;    /**< possible values are values that are multiple of 1000000 which is 1 MHZ and higher than 25 MHZ but less than 168 MHZ, so 1500 isn't possible value but 150000000 which is 150 MHZ is possible, this PLL is used to be source clock of other later systems */
    uint32_t PLLI2SOutputValue; /**< possible values are values that are multiple of 1000000 which is 1 MHZ and higher than 25 MHZ but less than 192 MHZ,, so 1500 isn't possible value but 150000000 which is 150 MHZ is possible, this PLLI2S is used to be source clock of I2S module that require high speed */
} HAL_RCC_PLL_ClockConfig_t;

/**
 * @struct: HAL_RCC_Miscellaneous_t
 * @brief: used to configure other Miscellaneous peripherals clock sources.
 */
typedef struct
{
    uint8_t I2SClockSource;       /**< for possible values refer to @HAL_RCC_I2S_ClockSource_t in "RCC_config.h", used to select a clock source for I2S peripheral.*/
    uint8_t EthernetMACPrescalar; /**< possible values are integers ranging from 1 to 20, it's used to divide RX and TX clk of PHY Ethernet that are later passed to Ethernet MAC*/
    uint32_t HSEVal;              /**< this is the value of HSE in case it was connected, valid input ranges from 4000000 to 26000000*/
    uint8_t ClockSecurityEnable;  /**< for possible values refer to @LIB_CONSTANTS_DriverStates_t in "constants.h", used to enable clock security which generates interrupts if the clock becomes unstable */
} HAL_RCC_Miscellaneous_t;

/**
 * @struct: HAL_RCC_ClocksEnablement_t
 * @brief: used to enable/disable clocks of the system.
 */
typedef struct
{
    uint8_t PLL_ClkEnable;    /**< for possible values refer to @LIB_CONSTANTS_DriverStates_t in "constants.h", used to enable clock of PLL*/
    uint8_t PLLI2S_ClkEnable; /**< for possible values refer to @LIB_CONSTANTS_DriverStates_t in "constants.h", used to enable clock of PLLI2S*/
    uint8_t PLL48_ClkEnable;  /**< for possible values refer to @LIB_CONSTANTS_DriverStates_t in "constants.h", used to enable clock of 48MHZ domain that controls USB OTG FS, SDIO, RNG clock output*/
    uint8_t HSI_ClkEnable;    /**< for possible values refer to @LIB_CONSTANTS_DriverStates_t in "constants.h", used to enable clock of HSI*/
    uint8_t HSE_ClkEnable;    /**< for possible values refer to @LIB_CONSTANTS_DriverStates_t in "constants.h", used to enable clock of HSE*/
    uint8_t LSI_ClkEnable;    /**< for possible values refer to @LIB_CONSTANTS_DriverStates_t in "constants.h", used to enable clock of LSI*/
    uint8_t LSE_ClkEnable;    /**< for possible values refer to @LIB_CONSTANTS_DriverStates_t in "constants.h", used to enable clock of LSE*/

} HAL_RCC_ClocksEnablement_t;

/**
 * @struct: HAL_RCC_Enablement_t
 * @brief: used to enable peripherals controlled by RCC whether this enablement configuration is in run mode or sleep mode
 */
typedef struct
{
    uint8_t PeripheralName;    /**< for possible values refer to @HAL_RCC_Peripherals_t in "RCC_header.h", this only defines which peripherals to control.*/
    uint8_t EnableInSleepMode; /**< for possible values refer to @LIB_CONSTANTS_DriverStates_t in "constants.h", determine whether <PeripheralName> will be enabled when MCU enters sleep mode or not*/
    uint8_t EnableInRunMode;   /**< for possible values refer to @LIB_CONSTANTS_DriverStates_t in "constants.h", determine whether <PeripheralName> will be enabled when MCU enters run mode or not*/
} HAL_RCC_EnablementConfig_t;

/******************************************************************************
 * Variables
 *******************************************************************************/

/**
 * @user_todo: user must edit this array with his needed configurations.
 * @brief: it represents clock configurations related to the whole system.
 */
const HAL_RCC_SYSCLK_ClockConfig_t globalConstArr_RCC_SYSCLK_ClockConfig_t[] = {
    {
        .SYSClkClockSource = HAL_RCC_SYSCLK_CLK_SRC_HSI,
        .SYSCLK_to_AHB_Prescalar = 1,
        .AHB_to_APB1_Prescalar = 1,
        .AHB_to_APB2_Prescalar = 1,
    }

};

/**
 * @user_todo: user shall edit this array with his needed configurations if he needed I2S or Ethernet or HSE.
 * @brief: it represents Miscellaneous configurations related to clock.
 */
const HAL_RCC_Miscellaneous_t globalConstArr_RCC_MiscellaneousConfig_t[] = {{
    .I2SClockSource = HAL_RCC_I2S_CLK_SRC_EXT_I2S,
    .EthernetMACPrescalar = 1,
    .HSEVal = 4000000,
    .ClockSecurityEnable = LIB_CONSTANTS_DISABLED,
}

};

/**
 * @user_todo: user must edit this array with his needed configurations.
 * @brief: it represents which clocks to be enable
 */
const HAL_RCC_ClocksEnablement_t globalConstArr_RCC_ClocksEnable_t[] = {
    {
        .PLL_ClkEnable = LIB_CONSTANTS_DISABLED,
        .PLLI2S_ClkEnable = LIB_CONSTANTS_DISABLED,
        .PLL48_ClkEnable = LIB_CONSTANTS_DISABLED,
        .HSI_ClkEnable = LIB_CONSTANTS_ENABLED,
        .HSE_ClkEnable = LIB_CONSTANTS_DISABLED,
        .LSI_ClkEnable = LIB_CONSTANTS_DISABLED,
        .LSE_ClkEnable = LIB_CONSTANTS_DISABLED,
    }

};

/**
 * @user_todo: user shall edit this array with his needed configurations (only modify it if you are configuring PLL and/or PLLI2S)
 * @brief: it represents the configurations for PLL
 */
const HAL_RCC_PLL_ClockConfig_t globalConstArr_RCC_PLL_ClockConfig_t[] = {
    {
        .PLLClockSource = HAL_RCC_PLL_CLK_SRC_HSI,
        .PLLOutputValue = 168000000,   /**< 168 MHZ*/
        .PLLI2SOutputValue = 25000000, /**< 25 MHZ*/
    }

};

/**
 * @user_todo: user shall edit this array with his needed configurations (only modify it if you are configuring MCO1 and/or MCO2)
 * @brief: it represents the configurations for MCO
 */
const HAL_RCC_MCOClockConfig_t globalConstArr_RCC_MCO_ClockConfig_t[] = {
    {
        .MCO1Enable = LIB_CONSTANTS_DISABLED,
        .MCO1ClockSource = HAL_RCC_MCO1_CLK_SRC_HSI,
        .MCO1Prescalar = 1,
        .MCO2Enable = LIB_CONSTANTS_DISABLED,
        .MCO2ClockSource = HAL_RCC_MCO2_CLK_SRC_PLL,
        .MCO2Prescalar = 1,
    }

};

/**
 * @user_todo: user shall edit this array with his needed configurations (only modify it if you are configuring the RTC)
 * @brief: it represents the configurations for RTC clock source
 */
const HAL_RCC_RTC_ClockConfig_t globalConstArr_RCC_RTC_ClockConfig_t[] = {
    {
        .RTCClockSource = HAL_RCC_RTC_CLK_SRC_LSI,
    }

};

/**
 * @user_todo: user shall edit this array with his needed configurations
 * @brief: it represents the configurations for enabling peripherals in run and sleep modes.
 */
const HAL_RCC_EnablementConfig_t globalConstArr_RCCEnablementConfig_t[] = {
    [HAL_RCC_PERIPHERAL_USB_OTG] = {
        .PeripheralName = HAL_RCC_PERIPHERAL_USB_OTG,
        .EnableInSleepMode = LIB_CONSTANTS_ENABLED,
        .EnableInRunMode = LIB_CONSTANTS_ENABLED,
    },
    [HAL_RCC_PERIPHERAL_ETHERNET] = {
        .PeripheralName = HAL_RCC_PERIPHERAL_ETHERNET,
        .EnableInSleepMode = LIB_CONSTANTS_DISABLED,
        .EnableInRunMode = LIB_CONSTANTS_DISABLED,
    },
    [HAL_RCC_PERIPHERAL_DMA1] = {
        .PeripheralName = HAL_RCC_PERIPHERAL_DMA1,
        .EnableInSleepMode = LIB_CONSTANTS_ENABLED,
        .EnableInRunMode = LIB_CONSTANTS_ENABLED,
    },
    [HAL_RCC_PERIPHERAL_DMA2] = {
        .PeripheralName = HAL_RCC_PERIPHERAL_DMA2,
        .EnableInSleepMode = LIB_CONSTANTS_ENABLED,
        .EnableInRunMode = LIB_CONSTANTS_ENABLED,
    },
    [HAL_RCC_PERIPHERAL_CCM] = {
        .PeripheralName = HAL_RCC_PERIPHERAL_CCM,
        .EnableInSleepMode = LIB_CONSTANTS_ENABLED,
        .EnableInRunMode = LIB_CONSTANTS_ENABLED,
    },
    [HAL_RCC_PERIPHERAL_BKP_SRAM] = {
        .PeripheralName = HAL_RCC_PERIPHERAL_BKP_SRAM,
        .EnableInSleepMode = LIB_CONSTANTS_ENABLED,
        .EnableInRunMode = LIB_CONSTANTS_ENABLED,
    },
    [HAL_RCC_PERIPHERAL_SRAM1] = {
        .PeripheralName = HAL_RCC_PERIPHERAL_SRAM1,
        .EnableInSleepMode = LIB_CONSTANTS_ENABLED,
        .EnableInRunMode = LIB_CONSTANTS_ENABLED,
    },
    [HAL_RCC_PERIPHERAL_SRAM2] = {
        .PeripheralName = HAL_RCC_PERIPHERAL_SRAM2,
        .EnableInSleepMode = LIB_CONSTANTS_ENABLED,
        .EnableInRunMode = LIB_CONSTANTS_ENABLED,
    },
    [HAL_RCC_PERIPHERAL_CRC] = {
        .PeripheralName = HAL_RCC_PERIPHERAL_CRC,
        .EnableInSleepMode = LIB_CONSTANTS_ENABLED,
        .EnableInRunMode = LIB_CONSTANTS_ENABLED,
    },
    [HAL_RCC_PERIPHERAL_GPIOA] = {
        .PeripheralName = HAL_RCC_PERIPHERAL_GPIOA,
        .EnableInSleepMode = LIB_CONSTANTS_ENABLED,
        .EnableInRunMode = LIB_CONSTANTS_ENABLED,
    },
    [HAL_RCC_PERIPHERAL_GPIOB] = {
        .PeripheralName = HAL_RCC_PERIPHERAL_GPIOB,
        .EnableInSleepMode = LIB_CONSTANTS_ENABLED,
        .EnableInRunMode = LIB_CONSTANTS_ENABLED,
    },
    [HAL_RCC_PERIPHERAL_GPIOC] = {
        .PeripheralName = HAL_RCC_PERIPHERAL_GPIOC,
        .EnableInSleepMode = LIB_CONSTANTS_ENABLED,
        .EnableInRunMode = LIB_CONSTANTS_ENABLED,
    },
    [HAL_RCC_PERIPHERAL_GPIOD] = {
        .PeripheralName = HAL_RCC_PERIPHERAL_GPIOD,
        .EnableInSleepMode = LIB_CONSTANTS_ENABLED,
        .EnableInRunMode = LIB_CONSTANTS_ENABLED,
    },
    [HAL_RCC_PERIPHERAL_GPIOE] = {
        .PeripheralName = HAL_RCC_PERIPHERAL_GPIOE,
        .EnableInSleepMode = LIB_CONSTANTS_ENABLED,
        .EnableInRunMode = LIB_CONSTANTS_ENABLED,
    },
    [HAL_RCC_PERIPHERAL_GPIOF] = {
        .PeripheralName = HAL_RCC_PERIPHERAL_GPIOF,
        .EnableInSleepMode = LIB_CONSTANTS_ENABLED,
        .EnableInRunMode = LIB_CONSTANTS_ENABLED,
    },
    [HAL_RCC_PERIPHERAL_GPIOG] = {
        .PeripheralName = HAL_RCC_PERIPHERAL_GPIOG,
        .EnableInSleepMode = LIB_CONSTANTS_ENABLED,
        .EnableInRunMode = LIB_CONSTANTS_ENABLED,
    },
    [HAL_RCC_PERIPHERAL_GPIOH] = {
        .PeripheralName = HAL_RCC_PERIPHERAL_GPIOH,
        .EnableInSleepMode = LIB_CONSTANTS_ENABLED,
        .EnableInRunMode = LIB_CONSTANTS_ENABLED,
    },
    [HAL_RCC_PERIPHERAL_GPIOI] = {
        .PeripheralName = HAL_RCC_PERIPHERAL_GPIOI,
        .EnableInSleepMode = LIB_CONSTANTS_ENABLED,
        .EnableInRunMode = LIB_CONSTANTS_ENABLED,
    },
    [HAL_RCC_PERIPHERAL_RNG] = {
        .PeripheralName = HAL_RCC_PERIPHERAL_RNG,
        .EnableInSleepMode = LIB_CONSTANTS_ENABLED,
        .EnableInRunMode = LIB_CONSTANTS_ENABLED,
    },
    [HAL_RCC_PERIPHERAL_HASH] = {
        .PeripheralName = HAL_RCC_PERIPHERAL_HASH,
        .EnableInSleepMode = LIB_CONSTANTS_ENABLED,
        .EnableInRunMode = LIB_CONSTANTS_ENABLED,
    },
    [HAL_RCC_PERIPHERAL_CRYPTO] = {
        .PeripheralName = HAL_RCC_PERIPHERAL_CRYPTO,
        .EnableInSleepMode = LIB_CONSTANTS_ENABLED,
        .EnableInRunMode = LIB_CONSTANTS_ENABLED,
    },
    [HAL_RCC_PERIPHERAL_CAMERA] = {
        .PeripheralName = HAL_RCC_PERIPHERAL_CAMERA,
        .EnableInSleepMode = LIB_CONSTANTS_ENABLED,
        .EnableInRunMode = LIB_CONSTANTS_ENABLED,
    },
    [HAL_RCC_PERIPHERAL_FSMC] = {
        .PeripheralName = HAL_RCC_PERIPHERAL_FSMC,
        .EnableInSleepMode = LIB_CONSTANTS_ENABLED,
        .EnableInRunMode = LIB_CONSTANTS_ENABLED,
    },
    [HAL_RCC_PERIPHERAL_DAC] = {
        .PeripheralName = HAL_RCC_PERIPHERAL_DAC,
        .EnableInSleepMode = LIB_CONSTANTS_ENABLED,
        .EnableInRunMode = LIB_CONSTANTS_ENABLED,
    },
    [HAL_RCC_PERIPHERAL_PWR] = {
        .PeripheralName = HAL_RCC_PERIPHERAL_PWR,
        .EnableInSleepMode = LIB_CONSTANTS_ENABLED,
        .EnableInRunMode = LIB_CONSTANTS_ENABLED,
    },
    [HAL_RCC_PERIPHERAL_CAN1] = {
        .PeripheralName = HAL_RCC_PERIPHERAL_CAN1,
        .EnableInSleepMode = LIB_CONSTANTS_ENABLED,
        .EnableInRunMode = LIB_CONSTANTS_ENABLED,
    },
    [HAL_RCC_PERIPHERAL_CAN2] = {
        .PeripheralName = HAL_RCC_PERIPHERAL_CAN2,
        .EnableInSleepMode = LIB_CONSTANTS_ENABLED,
        .EnableInRunMode = LIB_CONSTANTS_ENABLED,
    },
    [HAL_RCC_PERIPHERAL_I2C1] = {
        .PeripheralName = HAL_RCC_PERIPHERAL_I2C1,
        .EnableInSleepMode = LIB_CONSTANTS_ENABLED,
        .EnableInRunMode = LIB_CONSTANTS_ENABLED,
    },
    [HAL_RCC_PERIPHERAL_I2C2] = {
        .PeripheralName = HAL_RCC_PERIPHERAL_I2C2,
        .EnableInSleepMode = LIB_CONSTANTS_ENABLED,
        .EnableInRunMode = LIB_CONSTANTS_ENABLED,
    },
    [HAL_RCC_PERIPHERAL_I2C3] = {
        .PeripheralName = HAL_RCC_PERIPHERAL_I2C3,
        .EnableInSleepMode = LIB_CONSTANTS_ENABLED,
        .EnableInRunMode = LIB_CONSTANTS_ENABLED,
    },
    [HAL_RCC_PERIPHERAL_USART1] = {
        .PeripheralName = HAL_RCC_PERIPHERAL_USART1,
        .EnableInSleepMode = LIB_CONSTANTS_ENABLED,
        .EnableInRunMode = LIB_CONSTANTS_ENABLED,
    },
    [HAL_RCC_PERIPHERAL_USART2] = {
        .PeripheralName = HAL_RCC_PERIPHERAL_USART2,
        .EnableInSleepMode = LIB_CONSTANTS_ENABLED,
        .EnableInRunMode = LIB_CONSTANTS_ENABLED,
    },
    [HAL_RCC_PERIPHERAL_USART3] = {
        .PeripheralName = HAL_RCC_PERIPHERAL_USART3,
        .EnableInSleepMode = LIB_CONSTANTS_ENABLED,
        .EnableInRunMode = LIB_CONSTANTS_ENABLED,
    },
    [HAL_RCC_PERIPHERAL_UART4] = {
        .PeripheralName = HAL_RCC_PERIPHERAL_UART4,
        .EnableInSleepMode = LIB_CONSTANTS_ENABLED,
        .EnableInRunMode = LIB_CONSTANTS_ENABLED,
    },
    [HAL_RCC_PERIPHERAL_UART5] = {
        .PeripheralName = HAL_RCC_PERIPHERAL_UART5,
        .EnableInSleepMode = LIB_CONSTANTS_ENABLED,
        .EnableInRunMode = LIB_CONSTANTS_ENABLED,
    },
    [HAL_RCC_PERIPHERAL_USART6] = {
        .PeripheralName = HAL_RCC_PERIPHERAL_USART6,
        .EnableInSleepMode = LIB_CONSTANTS_ENABLED,
        .EnableInRunMode = LIB_CONSTANTS_ENABLED,
    },
    [HAL_RCC_PERIPHERAL_SPI1] = {
        .PeripheralName = HAL_RCC_PERIPHERAL_SPI1,
        .EnableInSleepMode = LIB_CONSTANTS_ENABLED,
        .EnableInRunMode = LIB_CONSTANTS_ENABLED,
    },
    [HAL_RCC_PERIPHERAL_SPI2] = {
        .PeripheralName = HAL_RCC_PERIPHERAL_SPI2,
        .EnableInSleepMode = LIB_CONSTANTS_ENABLED,
        .EnableInRunMode = LIB_CONSTANTS_ENABLED,
    },
    [HAL_RCC_PERIPHERAL_SPI3] = {
        .PeripheralName = HAL_RCC_PERIPHERAL_SPI3,
        .EnableInSleepMode = LIB_CONSTANTS_ENABLED,
        .EnableInRunMode = LIB_CONSTANTS_ENABLED,
    },
    [HAL_RCC_PERIPHERAL_WWDG] = {
        .PeripheralName = HAL_RCC_PERIPHERAL_WWDG,
        .EnableInSleepMode = LIB_CONSTANTS_ENABLED,
        .EnableInRunMode = LIB_CONSTANTS_ENABLED,
    },
    [HAL_RCC_PERIPHERAL_TIM1] = {
        .PeripheralName = HAL_RCC_PERIPHERAL_TIM1,
        .EnableInSleepMode = LIB_CONSTANTS_ENABLED,
        .EnableInRunMode = LIB_CONSTANTS_ENABLED,
    },
    [HAL_RCC_PERIPHERAL_TIM2] = {
        .PeripheralName = HAL_RCC_PERIPHERAL_TIM2,
        .EnableInSleepMode = LIB_CONSTANTS_ENABLED,
        .EnableInRunMode = LIB_CONSTANTS_ENABLED,
    },
    [HAL_RCC_PERIPHERAL_TIM3] = {
        .PeripheralName = HAL_RCC_PERIPHERAL_TIM3,
        .EnableInSleepMode = LIB_CONSTANTS_ENABLED,
        .EnableInRunMode = LIB_CONSTANTS_ENABLED,
    },
    [HAL_RCC_PERIPHERAL_TIM4] = {
        .PeripheralName = HAL_RCC_PERIPHERAL_TIM4,
        .EnableInSleepMode = LIB_CONSTANTS_ENABLED,
        .EnableInRunMode = LIB_CONSTANTS_ENABLED,
    },
    [HAL_RCC_PERIPHERAL_TIM5] = {
        .PeripheralName = HAL_RCC_PERIPHERAL_TIM5,
        .EnableInSleepMode = LIB_CONSTANTS_ENABLED,
        .EnableInRunMode = LIB_CONSTANTS_ENABLED,
    },
    [HAL_RCC_PERIPHERAL_TIM6] = {
        .PeripheralName = HAL_RCC_PERIPHERAL_TIM6,
        .EnableInSleepMode = LIB_CONSTANTS_ENABLED,
        .EnableInRunMode = LIB_CONSTANTS_ENABLED,
    },
    [HAL_RCC_PERIPHERAL_TIM7] = {
        .PeripheralName = HAL_RCC_PERIPHERAL_TIM7,
        .EnableInSleepMode = LIB_CONSTANTS_ENABLED,
        .EnableInRunMode = LIB_CONSTANTS_ENABLED,
    },
    [HAL_RCC_PERIPHERAL_TIM8] = {
        .PeripheralName = HAL_RCC_PERIPHERAL_TIM8,
        .EnableInSleepMode = LIB_CONSTANTS_ENABLED,
        .EnableInRunMode = LIB_CONSTANTS_ENABLED,
    },
    [HAL_RCC_PERIPHERAL_TIM9] = {
        .PeripheralName = HAL_RCC_PERIPHERAL_TIM9,
        .EnableInSleepMode = LIB_CONSTANTS_ENABLED,
        .EnableInRunMode = LIB_CONSTANTS_ENABLED,
    },
    [HAL_RCC_PERIPHERAL_TIM10] = {
        .PeripheralName = HAL_RCC_PERIPHERAL_TIM10,
        .EnableInSleepMode = LIB_CONSTANTS_ENABLED,
        .EnableInRunMode = LIB_CONSTANTS_ENABLED,
    },
    [HAL_RCC_PERIPHERAL_TIM11] = {
        .PeripheralName = HAL_RCC_PERIPHERAL_TIM11,
        .EnableInSleepMode = LIB_CONSTANTS_ENABLED,
        .EnableInRunMode = LIB_CONSTANTS_ENABLED,
    },
    [HAL_RCC_PERIPHERAL_TIM12] = {
        .PeripheralName = HAL_RCC_PERIPHERAL_TIM12,
        .EnableInSleepMode = LIB_CONSTANTS_ENABLED,
        .EnableInRunMode = LIB_CONSTANTS_ENABLED,
    },
    [HAL_RCC_PERIPHERAL_TIM13] = {
        .PeripheralName = HAL_RCC_PERIPHERAL_TIM13,
        .EnableInSleepMode = LIB_CONSTANTS_ENABLED,
        .EnableInRunMode = LIB_CONSTANTS_ENABLED,
    },
    [HAL_RCC_PERIPHERAL_TIM14] = {
        .PeripheralName = HAL_RCC_PERIPHERAL_TIM14,
        .EnableInSleepMode = LIB_CONSTANTS_ENABLED,
        .EnableInRunMode = LIB_CONSTANTS_ENABLED,
    },
    [HAL_RCC_PERIPHERAL_SYS_CFG] = {
        .PeripheralName = HAL_RCC_PERIPHERAL_SYS_CFG,
        .EnableInSleepMode = LIB_CONSTANTS_ENABLED,
        .EnableInRunMode = LIB_CONSTANTS_ENABLED,
    },
    [HAL_RCC_PERIPHERAL_SDIO] = {
        .PeripheralName = HAL_RCC_PERIPHERAL_SDIO,
        .EnableInSleepMode = LIB_CONSTANTS_ENABLED,
        .EnableInRunMode = LIB_CONSTANTS_ENABLED,
    },
    [HAL_RCC_PERIPHERAL_ADC1] = {
        .PeripheralName = HAL_RCC_PERIPHERAL_ADC1,
        .EnableInSleepMode = LIB_CONSTANTS_ENABLED,
        .EnableInRunMode = LIB_CONSTANTS_ENABLED,
    },
    [HAL_RCC_PERIPHERAL_ADC2] = {
        .PeripheralName = HAL_RCC_PERIPHERAL_ADC2,
        .EnableInSleepMode = LIB_CONSTANTS_ENABLED,
        .EnableInRunMode = LIB_CONSTANTS_ENABLED,
    },
    [HAL_RCC_PERIPHERAL_ADC3] = {
        .PeripheralName = HAL_RCC_PERIPHERAL_ADC3,
        .EnableInSleepMode = LIB_CONSTANTS_ENABLED,
        .EnableInRunMode = LIB_CONSTANTS_ENABLED,
    },
    [HAL_RCC_PERIPHERAL_FLASH_MEM] = {
        .PeripheralName = HAL_RCC_PERIPHERAL_FLASH_MEM,
        .EnableInSleepMode = LIB_CONSTANTS_ENABLED,
        .EnableInRunMode = LIB_CONSTANTS_ENABLED,
    },
    [HAL_RCC_PERIPHERAL_RTC] = {
        .PeripheralName = HAL_RCC_PERIPHERAL_RTC,
        .EnableInSleepMode = LIB_CONSTANTS_ENABLED,
        .EnableInRunMode = LIB_CONSTANTS_ENABLED,
    },

};

/******************************************************************************
 * Function Prototypes
 *******************************************************************************/

/*** End of File **************************************************************/
#endif /*HAL_RCC_CONFIG_H_*/