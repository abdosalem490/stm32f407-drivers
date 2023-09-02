/**
 * --------------------------------------------------------------------------------------------------------------------------------------
 * |    @title          :   General Purpose Input/Output                                                                                |
 * |    @file           :   GPIO_config.h                                                                                               |
 * |    @author         :   Abdelrahman Mohamed Salem                                                                                   |
 * |    @origin_date    :   01/09/2023                                                                                                  |
 * |    @version        :   1.0.0                                                                                                       |
 * |    @tool_chain     :   GNU Tools for STM32                                                                                         |
 * |    @compiler       :   GCC                                                                                                         |
 * |    @C_standard     :   ISO C99 (-std=c99)                                                                                          |
 * |    @target         :   stm32f407VGTX                                                                                               |
 * |    @notes          :   None                                                                                                        |
 * |    @license        :   MIT License                                                                                                 |
 * |    @brief          :   this header file contains configurations related to the General Purpose Input/Output (GPIO)                 |                                                               |
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
 * |    01/09/2023      1.0.0           Abdelrahman Mohamed Salem       Interface Created.                                              |
 * --------------------------------------------------------------------------------------------------------------------------------------
 */

#ifndef HAL_GPIO_CONFIG_H_
#define HAL_GPIO_CONFIG_H_

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
 * @reason: hold possible values for GPIO ports and pins
 */
#include "GPIO_header.h"

/**
 * @reason: hold possible values for configuration indexes
 */
#include "GPIO_private.h"

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
 * @ref: HAL_GPIO_PIN_SPEED
 * @brief: this tables holds the information on how fast can a GPIO pin reach depending on different configuration
 *
 *  +-------------------------------+---------------------------------+----------------------------------+-------+----------+
 *  |      Speed                    |            Parameter            |            Condition             |  Min  |   Max    |
 *  +-------------------------------+---------------------------------+----------------------------------+-------+----------+
 *  |                               |                                 |     CL = 50 pF, VDD > 2.70 V     |   -   |  4 MHZ   |
 *  |                               |        Maximum frequency        |     CL = 50 pF, VDD > 2.70 V     |   -   |  2 MHZ   |
 *  |  HAL_GPIO_OUT_SPEED_LOW       |                                 |     CL = 10 pF, VDD > 2.70 V     |   -   |  8 MHZ   |
 *  |                               |                                 |     CL = 10 pF, VDD > 1.8 V      |   -   |  4 MHZ   |
 *  |                               |---------------------------------+----------------------------------+-------+----------|
 *  |                               |        fall and rise time       | CL = 50 pF, VDD = 1.8 V to 3.6 V |   -   |  100 ns  |
 *  |-------------------------------+---------------------------------+----------------------------------+-------+----------|
 *  |                               |                                 |     CL = 50 pF, VDD > 2.70 V     |   -   |  25 MHZ  |
 *  |                               |        Maximum frequency        |     CL = 50 pF, VDD > 1.8 V      |   -   | 12.5 MHZ |
 *  |                               |                                 |     CL = 10 pF, VDD > 2.70 V     |   -   |  50 MHZ  |
 *  |                               |                                 |     CL = 10 pF, VDD > 1.8 V      |   -   |  20 MHZ  |
 *  |  HAL_GPIO_OUT_SPEED_MEDIUM    |---------------------------------+----------------------------------+-------+----------|
 *  |                               |                                 |      CL = 50 pF, VDD >2.7 V      |   -   |  10 ns   |
 *  |                               |        fall and rise time       |     CL = 50 pF, VDD > 1.8 V      |   -   |  20 ns   |
 *  |                               |                                 |     CL = 10 pF, VDD > 2.70 V     |   -   |   6 ns   |
 *  |                               |                                 |     CL = 10 pF, VDD > 1.8 V      |   -   |  10 ns   |
 *  |-------------------------------+---------------------------------+----------------------------------+-------+----------|
 *  |                               |                                 |     CL = 40 pF, VDD > 2.70 V     |   -   |  50 MHZ  |
 *  |                               |        Maximum frequency        |     CL = 40 pF, VDD > 1.8 V      |   -   |  25 MHZ  |
 *  |                               |                                 |     CL = 10 pF, VDD > 2.70 V     |   -   | 100 MHZ  |
 *  |                               |                                 |     CL = 10 pF, VDD > 2.70 V     |   -   |  50 MHZ  |
 *  |   HAL_GPIO_OUT_SPEED_HIGH     |---------------------------------+----------------------------------+-------+----------|
 *  |                               |                                 |     CL = 40 pF, VDD > 2.70 V     |   -   |   6 ns   |
 *  |                               |        fall and rise time       |     CL = 40 pF, VDD > 1.8 V      |   -   |  10 ns   |
 *  |                               |                                 |     CL = 10 pF, VDD > 2.70 V     |   -   |   4 ns   |
 *  |                               |                                 |     CL = 10 pF, VDD > 1.8 V      |   -   |   6 ns   |
 *  |-------------------------------+---------------------------------+----------------------------------+-------+----------|
 *  |                               |                                 |     CL = 30 pF, VDD > 2.70 V     |   -   | 100 MHZ  |
 *  |                               |        Maximum frequency        |     CL = 30 pF, VDD > 2.70 V     |   -   |  50 MHZ  |
 *  |                               |                                 |     CL = 10 pF, VDD > 2.70 V     |   -   | 180 MHZ  |
 *  |                               |                                 |     CL = 10 pF, VDD > 1.8 V      |   -   | 100 MHZ  |
 *  | HAL_GPIO_OUT_SPEED_VERY_HEIGH |---------------------------------+----------------------------------+-------+----------|
 *  |                               |                                 |     CL = 30 pF, VDD > 2.70 V     |   -   |   4 ns   |
 *  |                               |        fall and rise time       |     CL = 30 pF, VDD > 1.8 V      |   -   |   6 ns   |
 *  |                               |                                 |     CL = 10 pF, VDD > 2.70 V     |   -   |  2.5 ns  |
 *  |                               |                                 |     CL = 10 pF, VDD > 1.8 V      |   -   |   4 ns   |
 *  |-------------------------------+---------------------------------+----------------------------------+-------+----------|
 *  |        -                      | Pulse width of external signals |                -                 | 10 ns |          |
 *  |                               | detected by the EXTI controller |                                  |       |          |
 *  +-------------------------------+---------------------------------+----------------------------------+-------+----------+
 *
 */

/******************************************************************************
 * Typedefs
 *******************************************************************************/

/**
 * @enum: HAL_GPIOA_AlternateFunctions_t
 * @brief: used to select alternative functionality for a pin of GPIOA instead of being general purpose
 */
typedef enum
{
    // PIN0
    HAL_GPIOA_PIN0_TIM2_CH1_ETR = 1, /**< Timer2 -> channel 1 -> external input trigger. */
    HAL_GPIOA_PIN0_TIM5_CH1 = 2,     /**< Timer5 -> channel 1. */
    HAL_GPIOA_PIN0_TIM8_ETR = 3,     /**< Timer8 -> External input trigger. */
    HAL_GPIOA_PIN0_USART2_CTS = 7,   /**< USART2 -> CTS (clear to send). */
    HAL_GPIOA_PIN0_UART4_TX = 8,     /**< UART4 -> TX (transmitter). */
    HAL_GPIOA_PIN0_ETH_MII_CRS = 11, /**< Ethernet -> MII_CRS. */
    HAL_GPIOA_PIN0_EVENTOUT = 15,    /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN1
    HAL_GPIOA_PIN1_TIM2_CH2 = 1,          /**< Timer2 -> channel 2. */
    HAL_GPIOA_PIN1_TIM5_CH2 = 2,          /**< Timer5 -> channel 2. */
    HAL_GPIOA_PIN1_USART2_RTS = 7,        /**< USART2 -> RTS (request to send). */
    HAL_GPIOA_PIN1_UART4_RX = 8,          /**< UART4 -> RX (receiver). */
    HAL_GPIOA_PIN1_ETH_MII_RX_CLK = 11,   /**< Ethernet -> MII_RX_CLK. */
    HAL_GPIOA_PIN1_ETH_RMII_REF_CLK = 11, /**< Ethernet -> RMII_REF_CLK. */
    HAL_GPIOA_PIN1_EVENTOUT = 15,         /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN2
    HAL_GPIOA_PIN2_TIM2_CH3 = 1,  /**< Timer2 -> channel 3. */
    HAL_GPIOA_PIN2_TIM5_CH3 = 2,  /**< Timer5 -> channel 3. */
    HAL_GPIOA_PIN2_TIM9_CH1 = 3,  /**< Timer9 -> channel 1. */
    HAL_GPIOA_PIN2_USART2_TX = 7, /**< USART2 -> TX (transmitter). */
    HAL_GPIOA_PIN2_ETH_MDIO = 11, /**< Ethernet -> MDIO. */
    HAL_GPIOA_PIN2_EVENTOUT = 15, /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN3
    HAL_GPIOA_PIN3_TIM2_CH4 = 1,        /**< Timer2 -> channel 4. */
    HAL_GPIOA_PIN3_TIM5_CH4 = 2,        /**< Timer5 -> channel 4. */
    HAL_GPIOA_PIN3_TIM9_CH2 = 3,        /**< Timer9 -> channel 2. */
    HAL_GPIOA_PIN3_USART2_RX = 7,       /**< USART2 -> RX (Receiver). */
    HAL_GPIOA_PIN3_OTG_HS_ULPI_D0 = 10, /**< USB OTG HS -> ULPI_D0. */
    HAL_GPIOA_PIN3_ETH_MII_COL = 11,    /**< Ethernet -> MII_COL. */
    HAL_GPIOA_PIN3_EVENTOUT = 15,       /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN4
    HAL_GPIOA_PIN4_SPI1_NSS = 5,    /**< SPI1 -> NSS. */
    HAL_GPIOA_PIN4_SPI3_NSS = 6,    /**< SPI3 -> NSS. */
    HAL_GPIOA_PIN4_I2S3_WS = 6,     /**< I2S3 -> WS. */
    HAL_GPIOA_PIN4_USART2_CK = 7,   /**< USART2 -> CLK. */
    HAL_GPIOA_PIN4_OTG_HS_SOF = 12, /**< USB OTG HS -> SOF. */
    HAL_GPIOA_PIN4_DCMI_HSYNC = 13, /**< DCMI (camera) -> HSYNC. */
    HAL_GPIOA_PIN4_EVENTOUT = 15,   /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN5
    HAL_GPIOA_PIN5_TIM2_CH1_ETR = 1,    /**< Timer2 -> channel 1 -> external trigger. */
    HAL_GPIOA_PIN5_TIM8_CH1N = 3,       /**< Timer8 -> CH1N. */
    HAL_GPIOA_PIN5_SPI1_SCK = 5,        /**< SPI1 -> clk. */
    HAL_GPIOA_PIN5_OTG_HS_ULPI_CK = 10, /**< USB OTG HS -> ULPI_CK. */
    HAL_GPIOA_PIN5_EVENTOUT = 15,       /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN6
    HAL_GPIOA_PIN6_TIM1_BKIN = 1,    /**< Timer1 -> BKIN. */
    HAL_GPIOA_PIN6_TIM3_CH1 = 2,     /**< Timer3 -> channel 1. */
    HAL_GPIOA_PIN6_TIM8_BKIN = 3,    /**< Timer8 -> BKIN. */
    HAL_GPIOA_PIN6_SPI1_MISO = 5,    /**< SPI1 -> MISO (master in slave out). */
    HAL_GPIOA_PIN6_TIM13_CH1 = 9,    /**< Timer13 -> channel 1. */
    HAL_GPIOA_PIN6_DCMI_PIXCLK = 13, /**< DCMI (camera) -> PIXCLK. */
    HAL_GPIOA_PIN6_EVENTOUT = 15,    /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN7
    HAL_GPIOA_PIN7_TIM1_CH1N = 1,        /**< Timer1 -> CH1N. */
    HAL_GPIOA_PIN7_TIM3_CH2 = 2,         /**< Timer3 -> channel 2. */
    HAL_GPIOA_PIN7_TIM8_CH1N = 3,        /**< Timer8 -> CH1N. */
    HAL_GPIOA_PIN7_SPI1_MOSI = 5,        /**< SPI1 -> MOSI (master out slave in). */
    HAL_GPIOA_PIN7_TIM14_CH1 = 9,        /**< Timer14 -> channel 1. */
    HAL_GPIOA_PIN7_ETH_MII_RX_DV = 11,   /**< Ethernet -> MII_RX_DV. */
    HAL_GPIOA_PIN7_ETH_RMII_CRS_DV = 11, /**< Ethernet -> RMII_CRS_DV. */
    HAL_GPIOA_PIN7_EVENTOUT = 15,        /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN8
    HAL_GPIOA_PIN8_MCO1 = 0,        /**< MCO1. */
    HAL_GPIOA_PIN8_TIM1_CH1 = 1,    /**< Timer1 -> channel 1. */
    HAL_GPIOA_PIN8_I2C3_SCL = 4,    /**< I2C3 -> SCL (clk). */
    HAL_GPIOA_PIN8_USART1_CK = 7,   /**< USART1 -> CK (clk). */
    HAL_GPIOA_PIN8_OTG_FS_SOF = 10, /**< USB OTG FS -> SOF. */
    HAL_GPIOA_PIN8_EVENTOUT = 15,   /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN9
    HAL_GPIOA_PIN9_TIM1_CH2 = 1,  /**< Timer1 -> channel 2. */
    HAL_GPIOA_PIN9_I2C3_SMBA = 4, /**< I2C3 -> SMBA. */
    HAL_GPIOA_PIN9_USART1_TX = 7, /**< USART1 -> TX (transmitter). */
    HAL_GPIOA_PIN9_DCMI_D0 = 13,  /**< DCMI (camera) -> D0. */
    HAL_GPIOA_PIN9_EVENTOUT = 15, /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN10
    HAL_GPIOA_PIN10_TIM1_CH3 = 1,   /**< Timer1 -> channel 3. */
    HAL_GPIOA_PIN10_USART1_RX = 7,  /**< USART1 -> RX (Receiver). */
    HAL_GPIOA_PIN10_OTG_FS_ID = 10, /**< USB OTG FS -> ID. */
    HAL_GPIOA_PIN10_DCMI_D1 = 13,   /**< DCMI (camera) -> D1. */
    HAL_GPIOA_PIN10_EVENTOUT = 15,  /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN11
    HAL_GPIOA_PIN11_TIM1_CH4 = 1,   /**< Timer1 -> channel 4. */
    HAL_GPIOA_PIN11_USART1_CTS = 7, /**< USART1 -> CTS (clear to send). */
    HAL_GPIOA_PIN11_CAN1_RX = 9,    /**< CAN1 -> RX (receiver). */
    HAL_GPIOA_PIN11_OTG_FS_DM = 10, /**< USB OTG FS -> DM. */
    HAL_GPIOA_PIN11_EVENTOUT = 15,  /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN12
    HAL_GPIOA_PIN12_TIM1_ETR = 1,   /**< Timer1 -> ETR (external input trigger). */
    HAL_GPIOA_PIN12_USART1_RTS = 7, /**< USART1 -> RTS (Request to send). */
    HAL_GPIOA_PIN12_CAN1_TX = 9,    /**< CAN1 -> TX (Transmitter). */
    HAL_GPIOA_PIN12_OTG_FS_DP = 10, /**< USB OTG FS -> DP. */
    HAL_GPIOA_PIN12_EVENTOUT = 15,  /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN13
    HAL_GPIOA_PIN13_JTMS_SWDIO = 0, /**< JTMS -> SWDIO (used in debugging). */
    HAL_GPIOA_PIN13_EVENTOUT = 15,  /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN14
    HAL_GPIOA_PIN14_JTCK_SWCLK = 0, /**< JTCK -> SWCLK (used in debugging). */
    HAL_GPIOA_PIN14_EVENTOUT = 15,  /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN15
    HAL_GPIOA_PIN15_JTDI = 0,      /**< JTDI (used in debugging). */
    HAL_GPIOA_PIN15_TIM2_CH1 = 1,  /**< Timer2 -> Channel 1. */
    HAL_GPIOA_PIN15_TIM2_ETR = 1,  /**< Timer2 -> ETR (external intput trigger). */
    HAL_GPIOA_PIN15_SPI1_NSS = 5,  /**< SPI1 -> NSS. */
    HAL_GPIOA_PIN15_SPI3_NSS = 6,  /**< SPI3 -> NSS. */
    HAL_GPIOA_PIN15_I2S3_WS = 6,   /**< I2S3 -> WS. */
    HAL_GPIOA_PIN15_EVENTOUT = 15, /**< EVENTOUT signal used to wake other MCU using SEV. */

    HAL_GPIO_MAX_GPIOA_FUNCTIONS = 16, /**< this value shall never used by the user and it's only used by implementation code to verify input*/
} HAL_GPIOA_AlternateFunctions_t;

/**
 * @enum: HAL_GPIOB_AlternateFunctions_t
 * @brief: used to select alternative functionality for a pin of GPIOB instead of being general purpose
 */
typedef enum
{
    // PIN0
    HAL_GPIOB_PIN0_TIM1_CH2N = 1,       /**< Timer1 -> CH2N. */
    HAL_GPIOB_PIN0_TIM3_CH3 = 2,        /**< Timer3 -> channel 3. */
    HAL_GPIOB_PIN0_TIM8_CH2N = 3,       /**< Timer8 -> CH2N. */
    HAL_GPIOB_PIN0_OTG_HS_ULPI_D1 = 10, /**< USB OTG HS -> ULPI_D1. */
    HAL_GPIOB_PIN0_ETH_MII_RXD2 = 11,   /**< Ethernet -> MII_RXD2. */
    HAL_GPIOB_PIN0_EVENTOUT = 15,       /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN1
    HAL_GPIOB_PIN1_TIM1_CH3N = 1,       /**< Timer1 -> CH3N. */
    HAL_GPIOB_PIN1_TIM3_CH4 = 2,        /**< Timer3 -> channel 4. */
    HAL_GPIOB_PIN1_TIM8_CH3N = 3,       /**< Timer8 -> CH3N. */
    HAL_GPIOB_PIN1_OTG_HS_ULPI_D2 = 10, /**< USB OTG HS -> ULPI_D2. */
    HAL_GPIOB_PIN1_ETH_MII_RXD3 = 11,   /**< Ethernet -> MII_RXD3. */
    HAL_GPIOB_PIN1_EVENTOUT = 15,       /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN2
    HAL_GPIOB_PIN2_EVENTOUT = 15, /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN3
    HAL_GPIOB_PIN3_JTDO = 0,      /**< JTDO. */
    HAL_GPIOB_PIN3_TRACES_WO = 0, /**< TRACES_WO. */
    HAL_GPIOB_PIN3_TIM2_CH2 = 1,  /**< Timer2 -> channel 2. */
    HAL_GPIOB_PIN3_SPI1_SCK = 5,  /**< SPI1 -> SCK (clk). */
    HAL_GPIOB_PIN3_SPI3_SCK = 6,  /**< SPI3 -> SCK (clk). */
    HAL_GPIOB_PIN3_I2S3_CK = 6,   /**< I2S3 -> CK (clk). */
    HAL_GPIOB_PIN3_EVENTOUT = 15, /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN4
    HAL_GPIOB_PIN4_NJTRST = 0,     /**< NJTRST. */
    HAL_GPIOB_PIN4_TIM3_CH1 = 2,   /**< Timer3 -> channel 1. */
    HAL_GPIOB_PIN4_SPI1_MISO = 5,  /**< SPI1 -> MISO (master in slave out). */
    HAL_GPIOB_PIN4_SPI3_MISO = 6,  /**< SPI3 -> MISO (master in slave out). */
    HAL_GPIOB_PIN4_I2S3ext_SD = 7, /**< I2S3ext -> SD. */
    HAL_GPIOB_PIN4_EVENTOUT = 15,  /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN5
    HAL_GPIOB_PIN5_TIM3_CH2 = 2,        /**< Timer3 -> channel 2. */
    HAL_GPIOB_PIN5_I2C1_SMBA = 4,       /**< I2C1 -> SMBA. */
    HAL_GPIOB_PIN5_SPI1_MOSI = 5,       /**< SPI1 -> MOSI (master out slave in). */
    HAL_GPIOB_PIN5_SPI3_MOSI = 6,       /**< SPI3 -> MOSI (master out slave in). */
    HAL_GPIOB_PIN5_I2S3_SD = 6,         /**< I2S3 -> SD. */
    HAL_GPIOB_PIN5_CAN2_RX = 9,         /**< CAN2 -> RX (receiver). */
    HAL_GPIOB_PIN5_OTG_HS_ULPI_D7 = 10, /**< USB OTG HS -> ULPI_D7. */
    HAL_GPIOB_PIN5_ETH_PPS_OUT = 11,    /**< Ethernet -> PPS. */
    HAL_GPIOB_PIN5_DCMI_D10 = 13,       /**< DCMI (camera) -> D10. */
    HAL_GPIOB_PIN5_EVENTOUT = 15,       /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN6
    HAL_GPIOB_PIN6_TIM4_CH1 = 2,  /**< Timer4 -> channel 1. */
    HAL_GPIOB_PIN6_I2C1_SCL = 4,  /**< I2C1 -> SCL (clk). */
    HAL_GPIOB_PIN6_USART1_TX = 7, /**< USART1 -> TX (transmitter). */
    HAL_GPIOB_PIN5_CAN2_TX = 9,   /**< CAN2 -> TX (transmitter). */
    HAL_GPIOB_PIN6_DCMI_D5 = 13,  /**< DCMI (camera) -> D5. */
    HAL_GPIOB_PIN6_EVENTOUT = 15, /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN7
    HAL_GPIOB_PIN7_TIM4_CH2 = 2,    /**< Timer4 -> channel 2. */
    HAL_GPIOB_PIN7_I2C1_SDA = 4,    /**< I2C1 -> SDA (data). */
    HAL_GPIOB_PIN7_USART1_RX = 7,   /**< USART1 -> RX (Receiver). */
    HAL_GPIOB_PIN7_FSMC_NL = 12,    /**< FSMC -> NL. */
    HAL_GPIOB_PIN7_DCMI_VSYNC = 13, /**< DCMI (camera) -> VSYNC. */
    HAL_GPIOB_PIN7_EVENTOUT = 15,   /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN8
    HAL_GPIOB_PIN8_TIM4_CH3 = 2,      /**< Timer4 -> channel 3. */
    HAL_GPIOB_PIN8_TIM10_CH1 = 3,     /**< Timer10 -> channel 1. */
    HAL_GPIOB_PIN8_I2C1_SCL = 4,      /**< I2C1 -> SCL (clk). */
    HAL_GPIOB_PIN8_CAN1_RX = 9,       /**< CAN1 -> RX (receiver). */
    HAL_GPIOB_PIN8_ETH_MII_TXD3 = 11, /**< Ethernet -> MII_TXD3. */
    HAL_GPIOB_PIN8_SDIO_D4 = 12,      /**< SDIO -> D4. */
    HAL_GPIOB_PIN8_DCMI_D6 = 13,      /**< DCMI (camera) -> D6. */
    HAL_GPIOB_PIN8_EVENTOUT = 15,     /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN9
    HAL_GPIOB_PIN9_TIM4_CH4 = 2,  /**< Timer4 -> channel 4. */
    HAL_GPIOB_PIN9_TIM11_CH1 = 3, /**< Timer11 -> channel 1. */
    HAL_GPIOB_PIN9_I2C1_SDA = 4,  /**< I2C1 -> SDA (data). */
    HAL_GPIOB_PIN9_SPI2_NSS = 5,  /**< SPI2 -> NSS. */
    HAL_GPIOB_PIN9_I2S2_WS = 5,   /**< I2S2 -> WS. */
    HAL_GPIOB_PIN9_CAN1_TX = 9,   /**< CAN1 -> TX (transmitter). */
    HAL_GPIOB_PIN9_SDIO_D5 = 12,  /**< SDIO -> D5. */
    HAL_GPIOB_PIN9_DCMI_D7 = 13,  /**< DCMI (camera) -> D7. */
    HAL_GPIOB_PIN9_EVENTOUT = 15, /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN10
    HAL_GPIOB_PIN10_TIM2_CH3 = 1,        /**< Timer2 -> channel 3. */
    HAL_GPIOB_PIN10_I2C2_SCL = 4,        /**< I2C2 -> SCL (clk). */
    HAL_GPIOB_PIN10_SPI2_SCL = 5,        /**< SPI2 -> SCK (clk). */
    HAL_GPIOB_PIN10_I2S2_CK = 5,         /**< I2S2 -> CK. */
    HAL_GPIOB_PIN10_USART3_TX = 7,       /**< USART3 -> TX (transmitter). */
    HAL_GPIOB_PIN10_OTG_HS_ULPI_D3 = 10, /**< USB OTG HS -> ULPI_D3. */
    HAL_GPIOB_PIN10_ETH_MII_RX_ER = 11,  /**< Ethernet -> MII_RX_ER. */
    HAL_GPIOB_PIN10_EVENTOUT = 15,       /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN11
    HAL_GPIOB_PIN11_TIM2_CH4 = 1,        /**< Timer2 -> channel 4. */
    HAL_GPIOB_PIN11_I2C2_SDA = 4,        /**< I2C2 -> SDA (data). */
    HAL_GPIOB_PIN11_USART3_RX = 7,       /**< USART3 -> RX (Receiver). */
    HAL_GPIOB_PIN11_OTG_HS_ULPI_D4 = 10, /**< USB OTG HS -> ULPI_D4. */
    HAL_GPIOB_PIN11_ETH_MII_TX_EN = 11,  /**< Ethernet -> MII_TX_EN. */
    HAL_GPIOB_PIN11_ETH_RMII_TX_EN = 11, /**< Ethernet -> RMII_TX_EN. */
    HAL_GPIOB_PIN11_EVENTOUT = 15,       /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN12
    HAL_GPIOB_PIN12_TIM1_BKIN = 1,       /**< Timer1 -> BKIN. */
    HAL_GPIOB_PIN12_I2C2_SMBA = 4,       /**< I2C2 -> SMBA. */
    HAL_GPIOB_PIN12_SPI2_NSS = 5,        /**< SPI2 -> NSS. */
    HAL_GPIOB_PIN12_I2S2_WS = 5,         /**< I2S2 -> WS. */
    HAL_GPIOB_PIN12_USART3_CK = 7,       /**< USART3 -> CK. */
    HAL_GPIOB_PIN12_CAN2_RX = 9,         /**< CAN2 -> RX. */
    HAL_GPIOB_PIN12_OTG_HS_ULPI_D5 = 10, /**< USB OTG HS -> ULPI_D5. */
    HAL_GPIOB_PIN12_ETH_MII_TXD0 = 11,   /**< Ethernet -> MII_TXD0. */
    HAL_GPIOB_PIN12_ETH_RMII_TXD0 = 11,  /**< Ethernet -> RMII_TXD0. */
    HAL_GPIOB_PIN12_OTG_HS_ID = 12,      /**< USB OTG HS -> ID. */
    HAL_GPIOB_PIN12_EVENTOUT = 15,       /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN13
    HAL_GPIOB_PIN13_TIM1_CH1N = 1,       /**< Timer1 -> CH1N. */
    HAL_GPIOB_PIN13_SPI2_SCK = 5,        /**< SPI2 -> SCK. */
    HAL_GPIOB_PIN13_I2S2_CK = 5,         /**< I2S2 -> CK. */
    HAL_GPIOB_PIN13_USART3_CTS = 7,      /**< USART3 -> CTS. */
    HAL_GPIOB_PIN13_CAN2_TX = 9,         /**< CAN2 -> TX. */
    HAL_GPIOB_PIN13_OTG_HS_ULPI_D6 = 10, /**< USB OTG HS -> ULPI_D6. */
    HAL_GPIOB_PIN13_ETH_MII_TXD1 = 11,   /**< Ethernet -> MII_TXD1. */
    HAL_GPIOB_PIN13_ETH_RMII_TXD1 = 11,  /**< Ethernet -> RMII_TXD1. */
    HAL_GPIOB_PIN13_EVENTOUT = 15,       /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN14
    HAL_GPIOB_PIN14_TIM1_CH2N = 1,  /**< Timer1 -> CH2N. */
    HAL_GPIOB_PIN14_TIM8_CH2N = 3,  /**< Timer8 -> CH2N. */
    HAL_GPIOB_PIN14_SPI2_MISO = 5,  /**< SPI2 -> MISO. */
    HAL_GPIOB_PIN14_I2S2ext_SD = 6, /**< I2S2ext -> SD. */
    HAL_GPIOB_PIN14_USART3_RTS = 7, /**< USART3 -> RTS. */
    HAL_GPIOB_PIN14_TIM12_CH1 = 9,  /**< Timer12 -> Channel 1. */
    HAL_GPIOB_PIN14_OTG_HS_DM = 12, /**< USB OTG HS -> DM. */
    HAL_GPIOB_PIN14_EVENTOUT = 15,  /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN15
    HAL_GPIOB_PIN15_RTC_REFIN = 0,  /**< RTC -> REFIN. */
    HAL_GPIOB_PIN15_TIM1_CH3N = 1,  /**< Timer1 -> CH3N. */
    HAL_GPIOB_PIN15_TIM8_CH3N = 3,  /**< Timer8 -> CH3N. */
    HAL_GPIOB_PIN15_SPI2_MOSI = 5,  /**< SPI2 -> MOSI. */
    HAL_GPIOB_PIN15_I2S2_SD = 5,    /**< I2S2 -> SD. */
    HAL_GPIOB_PIN15_TIM12_CH2 = 9,  /**< Timer12 -> Channel 2. */
    HAL_GPIOB_PIN15_OTG_HS_Dp = 12, /**< USB OTG HS -> DP. */
    HAL_GPIOB_PIN15_EVENTOUT = 15,  /**< EVENTOUT signal used to wake other MCU using SEV. */

    HAL_GPIO_MAX_GPIOB_FUNCTIONS = 16, /**< this value shall never used by the user and it's only used by implementation code to verify input*/
} HAL_GPIOB_AlternateFunctions_t;

/**
 * @enum: HAL_GPIOC_AlternateFunctions_t
 * @brief: used to select alternative functionality for a pin of GPIOC instead of being general purpose
 */
typedef enum
{
    // PIN0
    HAL_GPIOC_PIN0_OTG_HS_ULPI_STP = 10, /**< USB OTG HS -> ULPI_STP. */
    HAL_GPIOC_PIN0_EVENTOUT = 15,        /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN1
    HAL_GPIOC_PIN1_ETH_MDC = 11,  /**< Ethernet -> MDC. */
    HAL_GPIOC_PIN1_EVENTOUT = 15, /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN2
    HAL_GPIOC_PIN2_SPI2_MISO = 5,        /**< SPI2 -> MISO. */
    HAL_GPIOC_PIN2_I2S2ext_SD = 6,       /**< I2S2ext -> SD. */
    HAL_GPIOC_PIN2_OTG_HS_ULPI_DIR = 10, /**< USB OTG HS -> ULPI_DIR. */
    HAL_GPIOC_PIN2_ETH_MII_TXD2 = 11,    /**< Ethernet -> MII_TXD2. */
    HAL_GPIOC_PIN2_EVENTOUT = 15,        /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN3
    HAL_GPIOC_PIN3_SPI2_MOSI = 5,        /**< SPI2 -> MOSI. */
    HAL_GPIOC_PIN3_I2S2_SD = 5,          /**< I2S2 -> SD. */
    HAL_GPIOC_PIN3_OTG_HS_ULPI_NXT = 10, /**< USB OTG HS -> ULPI_NXT. */
    HAL_GPIOC_PIN3_ETH_MII_TX_CLK = 11,  /**< Ethernet -> MII_TX_CLK. */
    HAL_GPIOC_PIN3_EVENTOUT = 15,

    // PIN4
    HAL_GPIOC_PIN4_ETH_MII_RXD0 = 11,  /**< Ethernet -> MII_RXD0. */
    HAL_GPIOC_PIN4_ETH_RMII_RXD0 = 11, /**< Ethernet -> RMII_RXD0. */
    HAL_GPIOC_PIN4_EVENTOUT = 15,      /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN5
    HAL_GPIOC_PIN5_ETH_MII_RXD1 = 11,  /**< Ethernet -> MII_RXD1. */
    HAL_GPIOC_PIN5_ETH_RMII_RXD1 = 11, /**< Ethernet -> RMII_RXD1. */
    HAL_GPIOC_PIN5_EVENTOUT = 15,      /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN6
    HAL_GPIOC_PIN6_TIM3_CH1 = 2,  /**< Timer3 -> Channel 1. */
    HAL_GPIOC_PIN6_TIM8_CH1 = 3,  /**< Timer8 -> Channel 1. */
    HAL_GPIOC_PIN6_I2S2_MCK = 5,  /**< I2S2 -> MCK. */
    HAL_GPIOC_PIN6_USART6_TX = 8, /**< USART6 -> TX. */
    HAL_GPIOC_PIN6_SDIO_D6 = 12,  /**< SDIO -> D6. */
    HAL_GPIOC_PIN6_DCMI_D0 = 13,  /**< DCMI (camera) -> D0. */
    HAL_GPIOC_PIN6_EVENTOUT = 15, /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN7
    HAL_GPIOC_PIN7_TIM3_CH2 = 2,  /**< Timer3 -> Channel 2. */
    HAL_GPIOC_PIN7_TIM8_CH2 = 3,  /**< Timer8 -> Channel 2. */
    HAL_GPIOC_PIN7_I2S3_MCK = 6,  /**< I2S3 -> MCK. */
    HAL_GPIOC_PIN7_USART6_RX = 8, /**< USART6 -> RX. */
    HAL_GPIOC_PIN7_SDIO_D7 = 12,  /**< SDIO -> D7. */
    HAL_GPIOC_PIN7_DCMI_D1 = 13,  /**< DCMI (camera) -> D1. */
    HAL_GPIOC_PIN7_EVENTOUT = 15, /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN8
    HAL_GPIOC_PIN8_TIM3_CH3 = 2,  /**< Timer3 -> Channel 3. */
    HAL_GPIOC_PIN8_TIM8_CH3 = 3,  /**< Timer8 -> Channel 3. */
    HAL_GPIOC_PIN8_USART6_CK = 8, /**< USART6 -> CK. */
    HAL_GPIOC_PIN8_SDIO_D0 = 12,  /**< SDIO -> D0. */
    HAL_GPIOC_PIN8_DCMI_D2 = 13,  /**< DCMI (camera) -> D2. */
    HAL_GPIOC_PIN8_EVENTOUT = 15, /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN9
    HAL_GPIOC_PIN9_MCO2 = 0,      /**< MCO2. */
    HAL_GPIOC_PIN9_TIM3_CH4 = 2,  /**< Timer3 -> Channel 4. */
    HAL_GPIOC_PIN9_TIM8_CH4 = 3,  /**< Timer8 -> Channel 4. */
    HAL_GPIOC_PIN9_I2C3_SDA = 4,  /**< I2C3 -> SDA. */
    HAL_GPIOC_PIN9_I2S_CKIN = 5,  /**< I2C3 -> SDA. */
    HAL_GPIOC_PIN9_SDIO_D1 = 12,  /**< SDIO -> D1. */
    HAL_GPIOC_PIN9_DCMI_D3 = 13,  /**< DCMI (camera) -> D3. */
    HAL_GPIOC_PIN9_EVENTOUT = 15, /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN10
    HAL_GPIOC_PIN10_SPI3_SCK = 4,  /**< SPI3 -> SCK (clk). */
    HAL_GPIOC_PIN10_I2S3_CK = 4,   /**< I2S3 -> CK. */
    HAL_GPIOC_PIN10_I2S_CKIN = 6,  /**< I2C3 -> SDA. */
    HAL_GPIOC_PIN10_USART3_TX = 7, /**< USART3 -> TX. */
    HAL_GPIOC_PIN10_UART4_TX = 8,  /**< USART4 -> TX. */
    HAL_GPIOC_PIN10_SDIO_D2 = 12,  /**< SDIO -> D2. */
    HAL_GPIOC_PIN10_DCMI_D8 = 13,  /**< DCMI (camera) -> D8. */
    HAL_GPIOC_PIN10_EVENTOUT = 15, /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN11
    HAL_GPIOC_PIN11_I2S3ext_SD = 5, /**< I2S3ext -> SD. */
    HAL_GPIOC_PIN11_SPI3_MISO = 6,  /**< SPI3 -> MISO. */
    HAL_GPIOC_PIN11_USART3_RX = 7,  /**< USART3 -> RX. */
    HAL_GPIOC_PIN11_UART4_RX = 8,   /**< USART4 -> RX. */
    HAL_GPIOC_PIN11_SDIO_D3 = 12,   /**< SDIO -> D3. */
    HAL_GPIOC_PIN11_DCMI_D4 = 13,   /**< DCMI (camera) -> D4. */
    HAL_GPIOC_PIN11_EVENTOUT = 15,  /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN12
    HAL_GPIOC_PIN12_SPI3_MOSI = 6, /**< SPI3 -> MOSI. */
    HAL_GPIOC_PIN12_I2S3_SD = 6,   /**< I2S3 -> SD. */
    HAL_GPIOC_PIN12_USART3_CK = 7, /**< USART3 -> CK. */
    HAL_GPIOC_PIN12_UART5_TX = 8,  /**< UART5 -> TX. */
    HAL_GPIOC_PIN12_SDIO_CK = 12,  /**< SDIO -> CK. */
    HAL_GPIOC_PIN12_DCMI_D9 = 13,  /**< DCMI (camera) -> D9. */
    HAL_GPIOC_PIN12_EVENTOUT = 15, /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN13
    HAL_GPIOC_PIN13_EVENTOUT = 15, /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN14
    HAL_GPIOC_PIN14_EVENTOUT = 15, /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN15
    HAL_GPIOC_PIN15_EVENTOUT = 15, /**< EVENTOUT signal used to wake other MCU using SEV. */

    HAL_GPIO_MAX_GPIOC_FUNCTIONS = 16, /**< this value shall never used by the user and it's only used by implementation code to verify input*/
} HAL_GPIOC_AlternateFunctions_t;

/**
 * @enum: HAL_GPIOD_AlternateFunctions_t
 * @brief: used to select alternative functionality for a pin of GPIOD instead of being general purpose
 */
typedef enum
{
    // PIN0
    HAL_GPIOD_PIN0_CAN1_RX = 9,   /**< CAN1 -> RX. */
    HAL_GPIOD_PIN0_FSMC_D2 = 12,  /**< FSMC -> D2. */
    HAL_GPIOD_PIN0_EVENTOUT = 15, /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN1
    HAL_GPIOD_PIN1_CAN1_TX = 9,   /**< CAN1 -> TX. */
    HAL_GPIOD_PIN1_FSMC_D3 = 12,  /**< FSMC -> D3. */
    HAL_GPIOD_PIN1_EVENTOUT = 15, /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN2
    HAL_GPIOD_PIN2_TIM3_ETR = 2,  /**< Timer3 -> ETR. */
    HAL_GPIOD_PIN2_UART5_RX = 8,  /**< UART5 -> RX. */
    HAL_GPIOD_PIN2_SDIO_CMD = 12, /**< SDIO -> CMD. */
    HAL_GPIOD_PIN2_DCMI_D11 = 13, /**< DCMI (camera) -> D11. */
    HAL_GPIOD_PIN2_EVENTOUT = 15, /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN3
    HAL_GPIOD_PIN3_USART2_CTS = 7, /**< USART2 -> CTS. */
    HAL_GPIOD_PIN3_FSMC_CLK = 12,  /**< FSMC -> CLK. */
    HAL_GPIOD_PIN3_EVENTOUT = 15,  /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN4
    HAL_GPIOD_PIN4_USART2_RTS = 7, /**< USART2 -> RTS. */
    HAL_GPIOD_PIN4_FSMC_NOE = 12,  /**< FSMC -> NOE. */
    HAL_GPIOD_PIN4_EVENTOUT = 15,  /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN5
    HAL_GPIOD_PIN5_USART2_TX = 7, /**< USART2 -> TX. */
    HAL_GPIOD_PIN5_FSMC_NWE = 12, /**< FSMC -> NWE. */
    HAL_GPIOD_PIN5_EVENTOUT = 15, /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN6
    HAL_GPIOD_PIN6_USART2_RX = 7,   /**< USART2 -> RX. */
    HAL_GPIOD_PIN6_FSMC_NWAIT = 12, /**< FSMC -> NWAIT. */
    HAL_GPIOD_PIN6_EVENTOUT = 15,   /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN7
    HAL_GPIOD_PIN7_USART2_CK = 7,  /**< USART2 -> CK. */
    HAL_GPIOD_PIN7_FSMC_NE1 = 12,  /**< FSMC -> NE1. */
    HAL_GPIOD_PIN7_FSMC_NCE2 = 12, /**< FSMC -> NCE2. */
    HAL_GPIOD_PIN7_EVENTOUT = 15,  /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN8
    HAL_GPIOD_PIN8_USART3_TX = 7, /**< USART3 -> TX. */
    HAL_GPIOD_PIN8_FSMC_D13 = 12, /**< FSMC -> D13. */
    HAL_GPIOD_PIN8_EVENTOUT = 15, /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN9
    HAL_GPIOD_PIN9_USART3_RX = 7, /**< USART3 -> RX. */
    HAL_GPIOD_PIN9_FSMC_D14 = 12, /**< FSMC -> D14. */
    HAL_GPIOD_PIN9_EVENTOUT = 15, /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN10
    HAL_GPIOD_PIN10_USART3_CK = 7, /**< USART3 -> CK. */
    HAL_GPIOD_PIN10_FSMC_D14 = 12, /**< FSMC -> D15. */
    HAL_GPIOD_PIN10_EVENTOUT = 15, /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN11
    HAL_GPIOD_PIN11_USART3_CTS = 7, /**< USART3 -> CTS. */
    HAL_GPIOD_PIN11_FSMC_A16 = 12,  /**< FSMC -> A16. */
    HAL_GPIOD_PIN11_EVENTOUT = 15,  /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN12
    HAL_GPIOD_PIN12_TIM4_CH1 = 2,   /**< Timer4 -> Channel 1. */
    HAL_GPIOD_PIN12_USART3_RTS = 7, /**< USART3 -> RTS. */
    HAL_GPIOD_PIN12_FSMC_A17 = 12,  /**< FSMC -> A17. */
    HAL_GPIOD_PIN12_EVENTOUT = 15,  /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN13
    HAL_GPIOD_PIN13_TIM4_CH2 = 2,  /**< Timer4 -> Channel 2. */
    HAL_GPIOD_PIN13_FSMC_A18 = 12, /**< FSMC -> A18. */
    HAL_GPIOD_PIN13_EVENTOUT = 15, /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN14
    HAL_GPIOD_PIN14_TIM4_CH3 = 2,  /**< Timer4 -> Channel 3. */
    HAL_GPIOD_PIN14_FSMC_D0 = 12,  /**< FSMC -> D0. */
    HAL_GPIOD_PIN14_EVENTOUT = 15, /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN15
    HAL_GPIOD_PIN15_TIM4_CH4 = 2,  /**< Timer4 -> Channel 4. */
    HAL_GPIOD_PIN15_FSMC_D1 = 12,  /**< FSMC -> D1. */
    HAL_GPIOD_PIN15_EVENTOUT = 15, /**< EVENTOUT signal used to wake other MCU using SEV. */

    HAL_GPIO_MAX_GPIOD_FUNCTIONS = 16, /**< this value shall never used by the user and it's only used by implementation code to verify input*/
} HAL_GPIOD_AlternateFunctions_t;

/**
 * @enum: HAL_GPIOE_AlternateFunctions_t
 * @brief: used to select alternative functionality for a pin of GPIOE instead of being general purpose
 */
typedef enum
{
    // PIN0
    HAL_GPIOE_PIN0_TIM4_ETR = 2,   /**< Timer4 -> ETR. */
    HAL_GPIOE_PIN0_FSMC_NBL0 = 12, /**< FSMC -> NBL0. */
    HAL_GPIOE_PIN0_DCMI_D2 = 13,   /**< DMCI (camera) -> D2. */
    HAL_GPIOE_PIN0_EVENTOUT = 15,  /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN1
    HAL_GPIOE_PIN1_FSMC_NBL1 = 12, /**< FSMC -> NBL1. */
    HAL_GPIOE_PIN1_DCMI_D3 = 13,   /**< DMCI (camera) -> D3. */
    HAL_GPIOE_PIN1_EVENTOUT = 15,  /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN2
    HAL_GPIOE_PIN2_TRACECLK = 0,      /**< TRACE CLK. */
    HAL_GPIOE_PIN2_ETH_MII_TXD3 = 11, /**< Ethernet -> MII_TXD3. */
    HAL_GPIOE_PIN2_FSMC_A23 = 12,     /**< FSMC -> A23. */
    HAL_GPIOE_PIN2_EVENTOUT = 15,     /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN3
    HAL_GPIOE_PIN3_TRACED0 = 0,   /**< TRACE D0. */
    HAL_GPIOE_PIN3_FSMC_A19 = 12, /**< FSMC -> A19. */
    HAL_GPIOE_PIN3_EVENTOUT = 15, /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN4
    HAL_GPIOE_PIN4_TRACED1 = 0,   /**< TRACE D1. */
    HAL_GPIOE_PIN4_FSMC_A20 = 12, /**< FSMC -> A20. */
    HAL_GPIOE_PIN4_DCMI_D4 = 13,  /**< DCMI (camera) -> D4. */
    HAL_GPIOE_PIN4_EVENTOUT = 15, /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN5
    HAL_GPIOE_PIN5_TRACED2 = 0,   /**< TRACE D2. */
    HAL_GPIOE_PIN5_TIM9_CH1 = 3,  /**< Timer9 -> Channel 1. */
    HAL_GPIOE_PIN5_FSMC_A21 = 12, /**< FSMC -> A21. */
    HAL_GPIOE_PIN5_DCMI_D6 = 13,  /**< DCMI (camera) -> D6. */
    HAL_GPIOE_PIN5_EVENTOUT = 15, /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN6
    HAL_GPIOE_PIN6_TRACED3 = 0,   /**< TRACE D3. */
    HAL_GPIOE_PIN6_TIM9_CH2 = 3,  /**< Timer9 -> Channel 2. */
    HAL_GPIOE_PIN6_FSMC_A22 = 12, /**< FSMC -> A22. */
    HAL_GPIOE_PIN6_DCMI_D7 = 13,  /**< DCMI (camera) -> D7. */
    HAL_GPIOE_PIN6_EVENTOUT = 15, /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN7
    HAL_GPIOE_PIN7_TIM1_ETR = 1,  /**< Timer1 -> ETR. */
    HAL_GPIOE_PIN7_FSMC_D4 = 12,  /**< FSMC -> D4. */
    HAL_GPIOE_PIN7_EVENTOUT = 15, /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN8
    HAL_GPIOE_PIN8_TIM1_CH1N = 1, /**< Timer1 -> CH1N. */
    HAL_GPIOE_PIN8_FSMC_D5 = 12,  /**< FSMC -> D5. */
    HAL_GPIOE_PIN8_EVENTOUT = 15, /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN9
    HAL_GPIOE_PIN9_TIM1_CH1 = 1,  /**< Timer1 -> Channel 1. */
    HAL_GPIOE_PIN9_FSMC_D6 = 12,  /**< FSMC -> D6. */
    HAL_GPIOE_PIN9_EVENTOUT = 15, /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN10
    HAL_GPIOE_PIN10_TIM1_CH2N = 1, /**< Timer1 -> CH2N. */
    HAL_GPIOE_PIN10_FSMC_D7 = 12,  /**< FSMC -> D7. */
    HAL_GPIOE_PIN10_EVENTOUT = 15, /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN11
    HAL_GPIOE_PIN11_TIM1_CH2 = 1,  /**< Timer1 -> Channel 2. */
    HAL_GPIOE_PIN11_FSMC_D8 = 12,  /**< FSMC -> D8. */
    HAL_GPIOE_PIN11_EVENTOUT = 15, /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN12
    HAL_GPIOE_PIN12_TIM1_CH3N = 1, /**< Timer1 -> CH3N. */
    HAL_GPIOE_PIN12_FSMC_D9 = 12,  /**< FSMC -> D9. */
    HAL_GPIOE_PIN12_EVENTOUT = 15, /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN13
    HAL_GPIOE_PIN13_TIM1_CH3 = 1,  /**< Timer1 -> Channel 3. */
    HAL_GPIOE_PIN13_FSMC_D10 = 12, /**< FSMC -> D10. */
    HAL_GPIOE_PIN13_EVENTOUT = 15, /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN14
    HAL_GPIOE_PIN14_TIM1_CH4 = 1,  /**< Timer1 -> Channel 4. */
    HAL_GPIOE_PIN14_FSMC_D11 = 12, /**< FSMC -> D11. */
    HAL_GPIOE_PIN14_EVENTOUT = 15, /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN15
    HAL_GPIOE_PIN15_TIM1_BKIN = 1, /**< Timer1 -> BKIN. */
    HAL_GPIOE_PIN15_FSMC_D12 = 12, /**< FSMC -> D12. */
    HAL_GPIOE_PIN15_EVENTOUT = 15, /**< EVENTOUT signal used to wake other MCU using SEV. */

    HAL_GPIO_MAX_GPIOE_FUNCTIONS = 16, /**< this value shall never used by the user and it's only used by implementation code to verify input*/
} HAL_GPIOE_AlternateFunctions_t;

/**
 * @enum: HAL_GPIOF_AlternateFunctions_t
 * @brief: used to select alternative functionality for a pin of GPIOF instead of being general purpose
 */
typedef enum
{
    // PIN0
    HAL_GPIOF_PIN0_I2C2_SDA = 4,  /**< I2C2 -> SDA. */
    HAL_GPIOF_PIN0_FSMC_A0 = 12,  /**< FSMC -> A0. */
    HAL_GPIOF_PIN0_EVENTOUT = 15, /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN1
    HAL_GPIOF_PIN1_I2C2_SCL = 4,  /**< I2C2 -> SCL. */
    HAL_GPIOF_PIN1_FSMC_A1 = 12,  /**< FSMC -> A1. */
    HAL_GPIOF_PIN1_EVENTOUT = 15, /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN2
    HAL_GPIOF_PIN2_I2C2_SMBA = 4, /**< I2C2 -> SMBA. */
    HAL_GPIOF_PIN2_FSMC_A2 = 12,  /**< FSMC -> A2. */
    HAL_GPIOF_PIN2_EVENTOUT = 15, /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN3
    HAL_GPIOF_PIN3_FSMC_A3 = 12,  /**< FSMC -> A3. */
    HAL_GPIOF_PIN3_EVENTOUT = 15, /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN4
    HAL_GPIOF_PIN4_FSMC_A4 = 12,  /**< FSMC -> A4. */
    HAL_GPIOF_PIN4_EVENTOUT = 15, /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN5
    HAL_GPIOF_PIN5_FSMC_A5 = 12,  /**< FSMC -> A5. */
    HAL_GPIOF_PIN5_EVENTOUT = 15, /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN6
    HAL_GPIOF_PIN6_TIM10_CH1 = 3,   /**< Timer10 -> Channel 1. */
    HAL_GPIOF_PIN6_FSMC_NIORD = 12, /**< FSMC -> NIORD. */
    HAL_GPIOF_PIN6_EVENTOUT = 15,   /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN7
    HAL_GPIOF_PIN7_TIM11_CH1 = 3,  /**< Timer11 -> Channel 1. */
    HAL_GPIOF_PIN7_FSMC_NREG = 12, /**< FSMC -> NREG. */
    HAL_GPIOF_PIN7_EVENTOUT = 15,  /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN8
    HAL_GPIOF_PIN8_TIM13_CH1 = 9,   /**< Timer13 -> Channel 1. */
    HAL_GPIOF_PIN8_FSMC_NIOWR = 12, /**< FSMC -> NIOWR. */
    HAL_GPIOF_PIN8_EVENTOUT = 15,   /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN9
    HAL_GPIOF_PIN9_TIM14_CH1 = 9, /**< Timer14 -> Channel 1. */
    HAL_GPIOF_PIN9_FSMC_CD = 12,  /**< FSMC -> CD. */
    HAL_GPIOF_PIN9_EVENTOUT = 15, /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN10
    HAL_GPIOF_PIN10_FSMC_INTR = 12, /**< FSMC -> INTR. */
    HAL_GPIOF_PIN10_EVENTOUT = 15,  /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN11
    HAL_GPIOF_PIN11_DCMI_D12 = 13, /**< DCMI (camera) -> D12. */
    HAL_GPIOF_PIN11_EVENTOUT = 15, /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN12
    HAL_GPIOF_PIN12_FSMC_A6 = 12,  /**< FSMC -> A6. */
    HAL_GPIOF_PIN12_EVENTOUT = 15, /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN13
    HAL_GPIOF_PIN13_FSMC_A7 = 12,  /**< FSMC -> A7. */
    HAL_GPIOF_PIN13_EVENTOUT = 15, /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN14
    HAL_GPIOF_PIN14_FSMC_A8 = 12,  /**< FSMC -> A8. */
    HAL_GPIOF_PIN14_EVENTOUT = 15, /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN15
    HAL_GPIOF_PIN15_FSMC_A9 = 12,  /**< FSMC -> A9. */
    HAL_GPIOF_PIN15_EVENTOUT = 15, /**< EVENTOUT signal used to wake other MCU using SEV. */

    HAL_GPIO_MAX_GPIOF_FUNCTIONS = 16, /**< this value shall never used by the user and it's only used by implementation code to verify input*/
} HAL_GPIOF_AlternateFunctions_t;

/**
 * @enum: HAL_GPIOG_AlternateFunctions_t
 * @brief: used to select alternative functionality for a pin of GPIOG instead of being general purpose
 */
typedef enum
{
    // PIN0
    HAL_GPIOG_PIN0_FSMC_A10 = 12, /**< FSMC -> A10. */
    HAL_GPIOG_PIN0_EVENTOUT = 15, /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN1
    HAL_GPIOG_PIN1_FSMC_A11 = 12, /**< FSMC -> A11. */
    HAL_GPIOG_PIN1_EVENTOUT = 15, /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN2
    HAL_GPIOG_PIN2_FSMC_A12 = 12, /**< FSMC -> A12. */
    HAL_GPIOG_PIN2_EVENTOUT = 15, /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN3
    HAL_GPIOG_PIN3_FSMC_A13 = 12, /**< FSMC -> A13. */
    HAL_GPIOG_PIN3_EVENTOUT = 15, /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN4
    HAL_GPIOG_PIN4_FSMC_A14 = 12, /**< FSMC -> A14. */
    HAL_GPIOG_PIN4_EVENTOUT = 15, /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN5
    HAL_GPIOG_PIN5_FSMC_A15 = 12, /**< FSMC -> A15. */
    HAL_GPIOG_PIN5_EVENTOUT = 15, /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN6
    HAL_GPIOG_PIN6_FSMC_INT2 = 12, /**< FSMC -> INT2. */
    HAL_GPIOG_PIN6_EVENTOUT = 15,  /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN7
    HAL_GPIOG_PIN7_USART6_CK = 8,  /**< USART6 -> CK. */
    HAL_GPIOG_PIN7_FSMC_INT3 = 12, /**< FSMC -> INT3. */
    HAL_GPIOG_PIN7_EVENTOUT = 15,  /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN8
    HAL_GPIOG_PIN8_USART6_RTS = 8,   /**< USART6 -> RTS. */
    HAL_GPIOG_PIN8_ETH_PPS_OUT = 11, /**< Ethernet -> PPS_OUT. */
    HAL_GPIOG_PIN8_EVENTOUT = 15,    /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN9
    HAL_GPIOG_PIN9_USART6_RX = 8,  /**< USART6 -> RX. */
    HAL_GPIOG_PIN9_FSMC_NE2 = 12,  /**< FSMC -> NE2. */
    HAL_GPIOG_PIN9_FSMC_NCE3 = 12, /**< FSMC -> NCE3. */
    HAL_GPIOG_PIN9_EVENTOUT = 15,  /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN10
    HAL_GPIOG_PIN10_FSMC_NCE4_1 = 12, /**< FSMC -> NCE4_1. */
    HAL_GPIOG_PIN10_FSMC_NE3 = 12,    /**< FSMC -> NE3. */
    HAL_GPIOG_PIN10_EVENTOUT = 15,    /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN11
    HAL_GPIOG_PIN11_ETH_MII_TX_EN = 11,  /**< Ethernet -> MII_TX_EN. */
    HAL_GPIOG_PIN11_ETH_RMII_TX_EN = 11, /**< Ethernet -> RMII_TX_EN. */
    HAL_GPIOG_PIN11_FSMC_NCE4_2 = 12,    /**< FSMC -> NCE4_2. */
    HAL_GPIOG_PIN11_EVENTOUT = 15,       /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN12
    HAL_GPIOG_PIN12_USART6_RTS = 8, /**< USART6 -> RTS. */
    HAL_GPIOG_PIN12_FSMC_NE4 = 12,  /**< FSMC -> NE4. */
    HAL_GPIOG_PIN12_EVENTOUT = 15,  /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN13
    HAL_GPIOG_PIN13_USART6_CTS = 8,     /**< USART6 -> CTS. */
    HAL_GPIOG_PIN13_ETH_MII_TXD0 = 11,  /**< Ethernet -> MII_TXD0. */
    HAL_GPIOG_PIN13_ETH_RMII_TXD0 = 11, /**< Ethernet -> RMII_TXD0. */
    HAL_GPIOG_PIN13_FSMC_A24 = 12,      /**< FSMC -> A24. */
    HAL_GPIOG_PIN13_EVENTOUT = 15,      /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN14
    HAL_GPIOG_PIN14_USART6_TX = 8,      /**< USART6 -> TX. */
    HAL_GPIOG_PIN14_ETH_MII_TXD1 = 11,  /**< Ethernet -> MII_TXD1. */
    HAL_GPIOG_PIN14_ETH_RMII_TXD1 = 11, /**< Ethernet -> RMII_TXD1. */
    HAL_GPIOG_PIN14_FSMC_A25 = 12,      /**< FSMC -> A25. */
    HAL_GPIOG_PIN14_EVENTOUT = 15,      /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN15
    HAL_GPIOG_PIN15_USART6_CTS = 8, /**< USART6 -> CTS. */
    HAL_GPIOG_PIN15_DCMI_D13 = 12,  /**< DCMI (camera) -> D13. */
    HAL_GPIOG_PIN15_EVENTOUT = 15,  /**< EVENTOUT signal used to wake other MCU using SEV. */

    HAL_GPIO_MAX_GPIOG_FUNCTIONS = 16, /**< this value shall never used by the user and it's only used by implementation code to verify input*/
} HAL_GPIOG_AlternateFunctions_t;

/**
 * @enum: HAL_GPIOH_AlternateFunctions_t
 * @brief: used to select alternative functionality for a pin of GPIOH instead of being general purpose
 */
typedef enum
{
    // PIN0
    HAL_GPIOH_PIN0_EVENTOUT = 15, /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN1
    HAL_GPIOH_PIN1_EVENTOUT = 15, /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN2
    HAL_GPIOH_PIN2_ETH_MII_CRS = 11, /**< Ethernet -> MII_CRS. */
    HAL_GPIOH_PIN2_EVENTOUT = 15,    /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN3
    HAL_GPIOH_PIN3_ETH_MII_COL = 11, /**< Ethernet -> MII_COL. */
    HAL_GPIOH_PIN3_EVENTOUT = 15,    /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN4
    HAL_GPIOH_PIN4_I2C2_SCL = 4,         /**< I2C2 -> SCL. */
    HAL_GPIOH_PIN4_OTG_HS_ULPI_NXT = 10, /**< USB OTG HS -> ULPI_NXT. */
    HAL_GPIOH_PIN4_EVENTOUT = 15,        /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN5
    HAL_GPIOH_PIN5_I2C2_SDA = 4,  /**< I2C2 -> SDA. */
    HAL_GPIOH_PIN5_EVENTOUT = 15, /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN6
    HAL_GPIOH_PIN6_I2C2_SMBA = 4,     /**< I2C2 -> SMBA. */
    HAL_GPIOH_PIN6_TIM12_CH1 = 9,     /**< Timer12 -> Channel 1. */
    HAL_GPIOH_PIN6_ETH_MII_RXD2 = 11, /**< Ethernet -> MII_RXD2. */
    HAL_GPIOH_PIN6_EVENTOUT = 15,     /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN7
    HAL_GPIOH_PIN7_I2C3_SCL = 4,      /**< I2C3 -> SCL. */
    HAL_GPIOH_PIN7_ETH_MII_RXD3 = 11, /**< Ethernet -> MII_RXD3. */
    HAL_GPIOH_PIN7_EVENTOUT = 15,     /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN8
    HAL_GPIOH_PIN8_I2C3_SDA = 4,    /**< I2C3 -> SDA. */
    HAL_GPIOH_PIN8_DCMI_HSYNC = 13, /**< DCMI (camera) -> HSYNC. */
    HAL_GPIOH_PIN8_EVENTOUT = 15,   /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN9
    HAL_GPIOH_PIN9_I2C3_SMBA = 4, /**< I2C3 -> SMBA. */
    HAL_GPIOH_PIN9_TIM12_CH2 = 9, /**< Timer12 -> Channel 2. */
    HAL_GPIOH_PIN9_DCMI_D0 = 13,  /**< DCMI (camera) -> D0. */
    HAL_GPIOH_PIN9_EVENTOUT = 15, /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN10
    HAL_GPIOH_PIN10_TIM5_CH1 = 2,  /**< Timer5 -> Channel 1. */
    HAL_GPIOH_PIN10_DCMI_D1 = 13,  /**< DCMI (camera) -> D1. */
    HAL_GPIOH_PIN10_EVENTOUT = 15, /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN11
    HAL_GPIOH_PIN11_TIM5_CH2 = 2,  /**< Timer5 -> Channel 2. */
    HAL_GPIOH_PIN11_DCMI_D2 = 13,  /**< DCMI (camera) -> D2. */
    HAL_GPIOH_PIN11_EVENTOUT = 15, /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN12
    HAL_GPIOH_PIN12_TIM5_CH3 = 2,  /**< Timer5 -> Channel 3. */
    HAL_GPIOH_PIN12_DCMI_D3 = 13,  /**< DCMI (camera) -> D3. */
    HAL_GPIOH_PIN12_EVENTOUT = 15, /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN13
    HAL_GPIOH_PIN13_TIM8_CH1N = 3, /**< Timer8 -> CH1N. */
    HAL_GPIOH_PIN13_CAN1_TX = 9,   /**< CAN1 -> TX. */
    HAL_GPIOH_PIN13_EVENTOUT = 15, /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN14
    HAL_GPIOH_PIN14_TIM8_CH2N = 3, /**< Timer8 -> CH2N. */
    HAL_GPIOH_PIN14_DCMI_D4 = 13,  /**< DCMI (camera) -> D4. */
    HAL_GPIOH_PIN14_EVENTOUT = 15, /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN15
    HAL_GPIOH_PIN15_TIM8_CH3N = 3, /**< Timer8 -> CH3N. */
    HAL_GPIOH_PIN15_DCMI_D11 = 13, /**< DCMI (camera) -> D11. */
    HAL_GPIOH_PIN15_EVENTOUT = 15, /**< EVENTOUT signal used to wake other MCU using SEV. */

    HAL_GPIO_MAX_GPIOH_FUNCTIONS = 16, /**< this value shall never used by the user and it's only used by implementation code to verify input*/
} HAL_GPIOH_AlternateFunctions_t;

/**
 * @enum: HAL_GPIOI_AlternateFunctions_t
 * @brief: used to select alternative functionality for a pin of GPIOI instead of being general purpose
 */
typedef enum
{
    // PIN0
    HAL_GPIOI_PIN0_TIM5_CH4 = 2,  /**< Timer5 -> Channel 4. */
    HAL_GPIOI_PIN0_SPI2_NSS = 5,  /**< SPI2 -> NSS. */
    HAL_GPIOI_PIN0_I2S2_WS = 5,   /**< I2S2 -> WS. */
    HAL_GPIOI_PIN0_DCMI_D13 = 13, /**< DCMI (camera) -> D13. */
    HAL_GPIOI_PIN0_EVENTOUT = 15, /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN1
    HAL_GPIOI_PIN1_SPI2_SCK = 5,  /**< SPI2 -> SCK. */
    HAL_GPIOI_PIN1_I2S2_CK = 5,   /**< I2S2 -> CK. */
    HAL_GPIOI_PIN1_DCMI_D8 = 13,  /**< DCMI (camera) -> D8. */
    HAL_GPIOI_PIN1_EVENTOUT = 15, /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN2
    HAL_GPIOI_PIN2_TIM8_CH4 = 3,   /**< Timer8 -> Channel 4. */
    HAL_GPIOI_PIN2_SPI2_MISO = 5,  /**< SPI2 -> MISO. */
    HAL_GPIOI_PIN2_I2S2ext_SD = 6, /**< I2S2ext -> SD. */
    HAL_GPIOI_PIN2_DCMI_D9 = 13,   /**< DCMI (camera) -> D9. */
    HAL_GPIOI_PIN2_EVENTOUT = 15,  /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN3
    HAL_GPIOI_PIN3_TIM8_ETR = 3,  /**< Timer8 -> ETR. */
    HAL_GPIOI_PIN3_SPI2_MOSI = 5, /**< SPI2 -> MOSI. */
    HAL_GPIOI_PIN3_I2S2_SD = 5,   /**< I2S2 -> SD. */
    HAL_GPIOI_PIN3_DCMI_D10 = 13, /**< DCMI (camera) -> D10. */
    HAL_GPIOI_PIN3_EVENTOUT = 15, /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN4
    HAL_GPIOI_PIN4_TIM8_BKIN = 3, /**< Timer8 -> BKIN. */
    HAL_GPIOI_PIN4_DCMI_D5 = 13,  /**< DCMI (camera) -> D5. */
    HAL_GPIOI_PIN4_EVENTOUT = 15, /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN5
    HAL_GPIOI_PIN5_TIM8_CH1 = 3,    /**< Timer8 -> Channel 1. */
    HAL_GPIOI_PIN5_DCMI_VSYNC = 13, /**< DCMI (camera) -> VSYNC. */
    HAL_GPIOI_PIN5_EVENTOUT = 15,   /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN6
    HAL_GPIOI_PIN6_TIM8_CH2 = 3,  /**< Timer8 -> Channel 2. */
    HAL_GPIOI_PIN6_DCMI_D6 = 13,  /**< DCMI (camera) -> D6. */
    HAL_GPIOI_PIN6_EVENTOUT = 15, /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN7
    HAL_GPIOI_PIN7_TIM8_CH3 = 3,  /**< Timer8 -> Channel 3. */
    HAL_GPIOI_PIN7_DCMI_D7 = 13,  /**< DCMI (camera) -> D7. */
    HAL_GPIOI_PIN7_EVENTOUT = 15, /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN8
    HAL_GPIOI_PIN8_EVENTOUT = 15, /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN9
    HAL_GPIOI_PIN9_CAN1_RX = 9,   /**< CAN1 -> RX. */
    HAL_GPIOI_PIN9_EVENTOUT = 15, /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN10
    HAL_GPIOI_PIN10_ETH_MII_RX_ER = 11, /**< Ethernet -> MII_RX_ER. */
    HAL_GPIOI_PIN10_EVENTOUT = 15,      /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN11
    HAL_GPIOI_PIN11_OTG_HS_ULPI_DIR = 10, /**< USB OTG HS -> ULPI_DIR. */
    HAL_GPIOI_PIN11_EVENTOUT = 15,        /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN12
    HAL_GPIOI_PIN12_EVENTOUT = 15, /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN13
    HAL_GPIOI_PIN13_EVENTOUT = 15, /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN14
    HAL_GPIOI_PIN14_EVENTOUT = 15, /**< EVENTOUT signal used to wake other MCU using SEV. */

    // PIN15
    HAL_GPIOI_PIN15_EVENTOUT = 15, /**< EVENTOUT signal used to wake other MCU using SEV. */

    HAL_GPIO_MAX_GPIOI_FUNCTIONS = 16, /**< this value shall never used by the user and it's only used by implementation code to verify input*/
} HAL_GPIOI_AlternateFunctions_t;

/**
 * @enum: HAL_GPIO_PinMode_t
 * @brief: used to select the mode for a GPIO pin
 */
typedef enum
{
    HAL_GPIO_PIN_MODE_INPUT = 0,          /**< Input (reset state). */
    HAL_GPIO_PIN_MODE_OUTPUT = 1,         /**< General purpose output mode. */
    HAL_GPIO_PIN_MODE_ALTERNATE_FUNC = 2, /**< Alternate function mode. */
    HAL_GPIO_PIN_MODE_ANALOG = 3,         /**< Analog mode. */
    HAL_GPIO_MAX_PIN_MODE,                /**< this value shall never used by the user and it's only used by implementation code to verify input*/
} HAL_GPIO_PinMode_t;

/**
 * @enum: HAL_GPIO_OutputType_t
 * @brief: used to select the output mode for GPIO pin if it in output mode
 */
typedef enum
{
    HAL_GPIO_OUT_MODE_PUSH_PULL = 0,  /**< Output push-pull (reset state). writing High on a pin will result in high on output and writing low on a pin will result in low on output  */
    HAL_GPIO_OUT_MODE_OPEN_DRAIN = 1, /**< Output open-drain. writing High on a pin will make pin leave the bus (have no effect on the bus) and writing low on a pin will result in low on output  */
    HAL_GPIO_MAX_OUT_MODE,            /**< this value shall never used by the user and it's only used by implementation code to verify input*/
} HAL_GPIO_OutputType_t;

/**
 * @enum: HAL_GPIO_OutputSpeed_t
 * @brief: used to select the speed for output GPIO pin
 */
typedef enum
{
    HAL_GPIO_OUT_SPEED_LOW = 0,        /**< maximum achievable frequency = 8 MHZ, refer to @HAL_GPIO_PIN_SPEED in "GPIO_config.h for more information" */
    HAL_GPIO_OUT_SPEED_MEDIUM = 1,     /**< maximum achievable frequency = 50 MHZ, refer to @HAL_GPIO_PIN_SPEED in "GPIO_config.h for more information" */
    HAL_GPIO_OUT_SPEED_HIGH = 2,       /**< maximum achievable frequency = 100 MHZ, refer to @HAL_GPIO_PIN_SPEED in "GPIO_config.h for more information" */
    HAL_GPIO_OUT_SPEED_VERY_HEIGH = 3, /**< maximum achievable frequency = 180 MHZ, refer to @HAL_GPIO_PIN_SPEED in "GPIO_config.h for more information" */
    HAL_GPIO_MAX_OUT_SPEED,            /**< this value shall never used by the user and it's only used by implementation code to verify input*/
} HAL_GPIO_OutputSpeed_t;

/**
 * @enum: HAL_GPIO_PullUpDown_t
 * @brief: used to enable/disable pull-up/pull-down resistors
 */
typedef enum
{
    HAL_GPIO_NO_PULL_UP_DOWN = 0, /**< No pull-up, pull-down resistors are enabled. */
    HAL_GPIO_PULL_UP = 0,         /**< Pull-up resistor is enabled. */
    HAL_GPIO_PULL_DOWN = 0,       /**< Pull-down resistor is enabled. */
    HAL_GPIO_MAX_PULL_UP_DOWN,    /**< this value shall never used by the user and it's only used by implementation code to verify input*/
} HAL_GPIO_PullUpDown_t;

/**
 * @struct: HAL_GPIO_PinConfig_t
 * @brief: used to configure a specific pin on a GPIO
 */
typedef struct
{
    uint16_t GPIOName;         /**< for possible values refer to @HAL_GPIO_Ports_t in "GPIO_header.h", it represents the name of the GPIO port*/
    uint16_t PINNumber;        /**< for possible values refer to @HAL_GPIO_Pins_t in "GPIO_header.h", it represents the numbre of the GPIO pin*/
    uint8_t Mode;              /**< for possible values refer to @HAL_GPIO_PinMode_t in "GPIO_config.h", used to Configure the mode of the pin.*/
    uint8_t OutputType;        /**< for possible values refer to @HAL_GPIO_OutputType_t in "GPIO_config.h", used to configure which method used to derive ouptut pin*/
    uint8_t OutputSpeed;       /**< for possible values refer to @HAL_GPIO_OutputSpeed_t in "GPIO_config.h", used to configure the speed of gpio pin in case it was output, refer to @HAL_GPIO_PIN_SPEED in "GPIO_config.h" to know the electric characteristics of each speed */
    uint8_t PullUpDown;        /**< for possible values refer to @HAL_GPIO_PullUpDown_t in "GPIO_config.h", used to enable/disable pull-up/pull-down resistors of a pin*/
    uint8_t LockEnable;        /**< for possible values refer to @LIB_CONSTANTS_LockStates_t in "constants.h", used to lock configuration for such pin so that it can't be changed unless after a reset*/
    uint8_t AlternateFunction; /**< depending on which port pin you are dealling with, refer to its corresponding avaialbe alternate functions so for example, if the pin belong to port I then refer to  @HAL_GPIOI_AlternateFunctions_t in "GPIO_config.h", if ihe pin belongs to PORT A then refer to @HAL_GPIOA_AlternateFunctions_t in "GPIO_config.h" and so on, used to assign a specific functionlity to a pin so that a pin can be configured to be USART2 RX and so on.*/
} HAL_GPIO_PinConfig_t;

/******************************************************************************
 * Variables
 *******************************************************************************/

/**
 * @user_todo: the user must edit this array.
 * @brief: it configures mode, speed, type, pull-up/pull-down, mode. alternate-function and locking of all GPIO pins
 */
const HAL_GPIO_PinConfig_t globalConstArr_GPIO_PinsConfig_t[][HAL_GPIO_MAX_PIN_INDEX] = {

    // configure pins of GPIO A
    [HAL_GPIO_PORTA_INDEX] = {

        // PA0
        [HAL_GPIO_PIN0_INDEX] = {
            .GPIOName = HAL_GPIO_PORTA,
            .PINNumber = HAL_GPIO_PIN0,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOA_PIN0_EVENTOUT,
        },

        // PA1
        [HAL_GPIO_PIN1_INDEX] = {
            .GPIOName = HAL_GPIO_PORTA,
            .PINNumber = HAL_GPIO_PIN1,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOA_PIN1_EVENTOUT,
        },

        // PA2
        [HAL_GPIO_PIN2_INDEX] = {
            .GPIOName = HAL_GPIO_PORTA,
            .PINNumber = HAL_GPIO_PIN2,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOA_PIN2_EVENTOUT,
        },

        // PA3
        [HAL_GPIO_PIN3_INDEX] = {
            .GPIOName = HAL_GPIO_PORTA,
            .PINNumber = HAL_GPIO_PIN3,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOA_PIN3_EVENTOUT,
        },

        // PA4
        [HAL_GPIO_PIN4_INDEX] = {
            .GPIOName = HAL_GPIO_PORTA,
            .PINNumber = HAL_GPIO_PIN4,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOA_PIN4_EVENTOUT,
        },

        // PA5
        [HAL_GPIO_PIN5_INDEX] = {
            .GPIOName = HAL_GPIO_PORTA,
            .PINNumber = HAL_GPIO_PIN5,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOA_PIN5_EVENTOUT,
        },

        // PA6
        [HAL_GPIO_PIN6_INDEX] = {
            .GPIOName = HAL_GPIO_PORTA,
            .PINNumber = HAL_GPIO_PIN6,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOA_PIN6_EVENTOUT,
        },

        // PA7
        [HAL_GPIO_PIN7_INDEX] = {
            .GPIOName = HAL_GPIO_PORTA,
            .PINNumber = HAL_GPIO_PIN7,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOA_PIN7_EVENTOUT,
        },

        // PA8
        [HAL_GPIO_PIN8_INDEX] = {
            .GPIOName = HAL_GPIO_PORTA,
            .PINNumber = HAL_GPIO_PIN8,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOA_PIN8_EVENTOUT,
        },

        // PA9
        [HAL_GPIO_PIN9_INDEX] = {
            .GPIOName = HAL_GPIO_PORTA,
            .PINNumber = HAL_GPIO_PIN9,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOA_PIN9_EVENTOUT,
        },

        // PA10
        [HAL_GPIO_PIN10_INDEX] = {
            .GPIOName = HAL_GPIO_PORTA,
            .PINNumber = HAL_GPIO_PIN10,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOA_PIN10_EVENTOUT,
        },

        // PA11
        [HAL_GPIO_PIN11_INDEX] = {
            .GPIOName = HAL_GPIO_PORTA,
            .PINNumber = HAL_GPIO_PIN11,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOA_PIN11_EVENTOUT,
        },

        // PA12
        [HAL_GPIO_PIN12_INDEX] = {
            .GPIOName = HAL_GPIO_PORTA,
            .PINNumber = HAL_GPIO_PIN12,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOA_PIN12_EVENTOUT,
        },

        // PA13
        [HAL_GPIO_PIN13_INDEX] = {
            .GPIOName = HAL_GPIO_PORTA,
            .PINNumber = HAL_GPIO_PIN13,
            .Mode = HAL_GPIO_PIN_MODE_ALTERNATE_FUNC,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_VERY_HEIGH,
            .PullUpDown = HAL_GPIO_PULL_UP,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOA_PIN13_JTMS_SWDIO,
        },

        // PA14
        [HAL_GPIO_PIN14_INDEX] = {
            .GPIOName = HAL_GPIO_PORTA,
            .PINNumber = HAL_GPIO_PIN14,
            .Mode = HAL_GPIO_PIN_MODE_ALTERNATE_FUNC,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_PULL_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOA_PIN14_JTCK_SWCLK,
        },

        // PA15
        [HAL_GPIO_PIN15_INDEX] = {
            .GPIOName = HAL_GPIO_PORTA,
            .PINNumber = HAL_GPIO_PIN15,
            .Mode = HAL_GPIO_PIN_MODE_ALTERNATE_FUNC,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_PULL_UP,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOA_PIN15_JTDI,
        },
    },

    // configure pins of GPIO C
    [HAL_GPIO_PORTC_INDEX] = {

        // PC0
        [HAL_GPIO_PIN0_INDEX] = {
            .GPIOName = HAL_GPIO_PORTC,
            .PINNumber = HAL_GPIO_PIN0,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOC_PIN0_EVENTOUT,
        },

        // PC1
        [HAL_GPIO_PIN1_INDEX] = {
            .GPIOName = HAL_GPIO_PORTC,
            .PINNumber = HAL_GPIO_PIN1,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOC_PIN1_EVENTOUT,
        },

        // PC2
        [HAL_GPIO_PIN2_INDEX] = {
            .GPIOName = HAL_GPIO_PORTC,
            .PINNumber = HAL_GPIO_PIN2,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOC_PIN2_EVENTOUT,
        },

        // PC3
        [HAL_GPIO_PIN3_INDEX] = {
            .GPIOName = HAL_GPIO_PORTC,
            .PINNumber = HAL_GPIO_PIN3,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOC_PIN3_EVENTOUT,
        },

        // PC4
        [HAL_GPIO_PIN4_INDEX] = {
            .GPIOName = HAL_GPIO_PORTC,
            .PINNumber = HAL_GPIO_PIN4,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOC_PIN4_EVENTOUT,
        },

        // PC5
        [HAL_GPIO_PIN5_INDEX] = {
            .GPIOName = HAL_GPIO_PORTC,
            .PINNumber = HAL_GPIO_PIN5,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOC_PIN5_EVENTOUT,
        },

        // PC6
        [HAL_GPIO_PIN6_INDEX] = {
            .GPIOName = HAL_GPIO_PORTC,
            .PINNumber = HAL_GPIO_PIN6,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOC_PIN6_EVENTOUT,
        },

        // PC7
        [HAL_GPIO_PIN7_INDEX] = {
            .GPIOName = HAL_GPIO_PORTC,
            .PINNumber = HAL_GPIO_PIN7,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOC_PIN7_EVENTOUT,
        },

        // PC8
        [HAL_GPIO_PIN8_INDEX] = {
            .GPIOName = HAL_GPIO_PORTC,
            .PINNumber = HAL_GPIO_PIN8,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOC_PIN8_EVENTOUT,
        },

        // PC9
        [HAL_GPIO_PIN9_INDEX] = {
            .GPIOName = HAL_GPIO_PORTC,
            .PINNumber = HAL_GPIO_PIN9,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOC_PIN9_EVENTOUT,
        },

        // PC10
        [HAL_GPIO_PIN10_INDEX] = {
            .GPIOName = HAL_GPIO_PORTC,
            .PINNumber = HAL_GPIO_PIN10,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOC_PIN10_EVENTOUT,
        },

        // PC11
        [HAL_GPIO_PIN11_INDEX] = {
            .GPIOName = HAL_GPIO_PORTC,
            .PINNumber = HAL_GPIO_PIN11,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOC_PIN11_EVENTOUT,
        },

        // PC12
        [HAL_GPIO_PIN12_INDEX] = {
            .GPIOName = HAL_GPIO_PORTC,
            .PINNumber = HAL_GPIO_PIN12,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOC_PIN12_EVENTOUT,
        },

        // PC13
        [HAL_GPIO_PIN13_INDEX] = {
            .GPIOName = HAL_GPIO_PORTC,
            .PINNumber = HAL_GPIO_PIN13,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOC_PIN13_EVENTOUT,
        },

        // PC14
        [HAL_GPIO_PIN14_INDEX] = {
            .GPIOName = HAL_GPIO_PORTC,
            .PINNumber = HAL_GPIO_PIN14,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOC_PIN14_EVENTOUT,
        },

        // PC15
        [HAL_GPIO_PIN15_INDEX] = {
            .GPIOName = HAL_GPIO_PORTC,
            .PINNumber = HAL_GPIO_PIN15,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOC_PIN15_EVENTOUT,
        },
    },

    // configure pins of GPIO D
    [HAL_GPIO_PORTD_INDEX] = {

        // PD0
        [HAL_GPIO_PIN0_INDEX] = {
            .GPIOName = HAL_GPIO_PORTD,
            .PINNumber = HAL_GPIO_PIN0,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOD_PIN0_EVENTOUT,
        },

        // PD1
        [HAL_GPIO_PIN1_INDEX] = {
            .GPIOName = HAL_GPIO_PORTD,
            .PINNumber = HAL_GPIO_PIN1,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOD_PIN1_EVENTOUT,
        },

        // PD2
        [HAL_GPIO_PIN2_INDEX] = {
            .GPIOName = HAL_GPIO_PORTD,
            .PINNumber = HAL_GPIO_PIN2,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOD_PIN2_EVENTOUT,
        },

        // PD3
        [HAL_GPIO_PIN3_INDEX] = {
            .GPIOName = HAL_GPIO_PORTD,
            .PINNumber = HAL_GPIO_PIN3,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOD_PIN3_EVENTOUT,
        },

        // PD4
        [HAL_GPIO_PIN4_INDEX] = {
            .GPIOName = HAL_GPIO_PORTD,
            .PINNumber = HAL_GPIO_PIN4,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOD_PIN4_EVENTOUT,
        },

        // PD5
        [HAL_GPIO_PIN5_INDEX] = {
            .GPIOName = HAL_GPIO_PORTD,
            .PINNumber = HAL_GPIO_PIN5,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOD_PIN5_EVENTOUT,
        },

        // PD6
        [HAL_GPIO_PIN6_INDEX] = {
            .GPIOName = HAL_GPIO_PORTD,
            .PINNumber = HAL_GPIO_PIN6,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOD_PIN6_EVENTOUT,
        },

        // PD7
        [HAL_GPIO_PIN7_INDEX] = {
            .GPIOName = HAL_GPIO_PORTD,
            .PINNumber = HAL_GPIO_PIN7,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOD_PIN7_EVENTOUT,
        },

        // PD8
        [HAL_GPIO_PIN8_INDEX] = {
            .GPIOName = HAL_GPIO_PORTD,
            .PINNumber = HAL_GPIO_PIN8,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOD_PIN8_EVENTOUT,
        },

        // PD9
        [HAL_GPIO_PIN9_INDEX] = {
            .GPIOName = HAL_GPIO_PORTD,
            .PINNumber = HAL_GPIO_PIN9,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOD_PIN9_EVENTOUT,
        },

        // PD10
        [HAL_GPIO_PIN10_INDEX] = {
            .GPIOName = HAL_GPIO_PORTD,
            .PINNumber = HAL_GPIO_PIN10,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOD_PIN10_EVENTOUT,
        },

        // PD11
        [HAL_GPIO_PIN11_INDEX] = {
            .GPIOName = HAL_GPIO_PORTD,
            .PINNumber = HAL_GPIO_PIN11,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOD_PIN11_EVENTOUT,
        },

        // PD12
        [HAL_GPIO_PIN12_INDEX] = {
            .GPIOName = HAL_GPIO_PORTD,
            .PINNumber = HAL_GPIO_PIN12,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOD_PIN12_EVENTOUT,
        },

        // PD13
        [HAL_GPIO_PIN13_INDEX] = {
            .GPIOName = HAL_GPIO_PORTD,
            .PINNumber = HAL_GPIO_PIN13,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOD_PIN13_EVENTOUT,
        },

        // PD14
        [HAL_GPIO_PIN14_INDEX] = {
            .GPIOName = HAL_GPIO_PORTD,
            .PINNumber = HAL_GPIO_PIN14,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOD_PIN14_EVENTOUT,
        },

        // PD15
        [HAL_GPIO_PIN15_INDEX] = {
            .GPIOName = HAL_GPIO_PORTD,
            .PINNumber = HAL_GPIO_PIN15,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOD_PIN15_EVENTOUT,
        },
    },

    // configure pins of GPIO E
    [HAL_GPIO_PORTE_INDEX] = {

        // PE0
        [HAL_GPIO_PIN0_INDEX] = {
            .GPIOName = HAL_GPIO_PORTE,
            .PINNumber = HAL_GPIO_PIN0,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOE_PIN0_EVENTOUT,
        },

        // PE1
        [HAL_GPIO_PIN1_INDEX] = {
            .GPIOName = HAL_GPIO_PORTE,
            .PINNumber = HAL_GPIO_PIN1,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOE_PIN1_EVENTOUT,
        },

        // PE2
        [HAL_GPIO_PIN2_INDEX] = {
            .GPIOName = HAL_GPIO_PORTE,
            .PINNumber = HAL_GPIO_PIN2,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOE_PIN2_EVENTOUT,
        },

        // PE3
        [HAL_GPIO_PIN3_INDEX] = {
            .GPIOName = HAL_GPIO_PORTE,
            .PINNumber = HAL_GPIO_PIN3,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOE_PIN3_EVENTOUT,
        },

        // PE4
        [HAL_GPIO_PIN4_INDEX] = {
            .GPIOName = HAL_GPIO_PORTE,
            .PINNumber = HAL_GPIO_PIN4,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOE_PIN4_EVENTOUT,
        },

        // PE5
        [HAL_GPIO_PIN5_INDEX] = {
            .GPIOName = HAL_GPIO_PORTE,
            .PINNumber = HAL_GPIO_PIN5,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOE_PIN5_EVENTOUT,
        },

        // PE6
        [HAL_GPIO_PIN6_INDEX] = {
            .GPIOName = HAL_GPIO_PORTE,
            .PINNumber = HAL_GPIO_PIN6,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOE_PIN6_EVENTOUT,
        },

        // PE7
        [HAL_GPIO_PIN7_INDEX] = {
            .GPIOName = HAL_GPIO_PORTE,
            .PINNumber = HAL_GPIO_PIN7,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOE_PIN7_EVENTOUT,
        },

        // PE8
        [HAL_GPIO_PIN8_INDEX] = {
            .GPIOName = HAL_GPIO_PORTE,
            .PINNumber = HAL_GPIO_PIN8,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOE_PIN8_EVENTOUT,
        },

        // PE9
        [HAL_GPIO_PIN9_INDEX] = {
            .GPIOName = HAL_GPIO_PORTE,
            .PINNumber = HAL_GPIO_PIN9,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOE_PIN9_EVENTOUT,
        },

        // PE10
        [HAL_GPIO_PIN10_INDEX] = {
            .GPIOName = HAL_GPIO_PORTE,
            .PINNumber = HAL_GPIO_PIN10,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOE_PIN10_EVENTOUT,
        },

        // PE11
        [HAL_GPIO_PIN11_INDEX] = {
            .GPIOName = HAL_GPIO_PORTE,
            .PINNumber = HAL_GPIO_PIN11,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOE_PIN11_EVENTOUT,
        },

        // PE12
        [HAL_GPIO_PIN12_INDEX] = {
            .GPIOName = HAL_GPIO_PORTE,
            .PINNumber = HAL_GPIO_PIN12,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOE_PIN12_EVENTOUT,
        },

        // PE13
        [HAL_GPIO_PIN13_INDEX] = {
            .GPIOName = HAL_GPIO_PORTE,
            .PINNumber = HAL_GPIO_PIN13,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOE_PIN13_EVENTOUT,
        },

        // PE14
        [HAL_GPIO_PIN14_INDEX] = {
            .GPIOName = HAL_GPIO_PORTE,
            .PINNumber = HAL_GPIO_PIN14,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOE_PIN14_EVENTOUT,
        },

        // PE15
        [HAL_GPIO_PIN15_INDEX] = {
            .GPIOName = HAL_GPIO_PORTE,
            .PINNumber = HAL_GPIO_PIN15,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOE_PIN15_EVENTOUT,
        },
    },

    // configure pins of GPIO F
    [HAL_GPIO_PORTF_INDEX] = {

        // PF0
        [HAL_GPIO_PIN0_INDEX] = {
            .GPIOName = HAL_GPIO_PORTF,
            .PINNumber = HAL_GPIO_PIN0,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOF_PIN0_EVENTOUT,
        },

        // PF1
        [HAL_GPIO_PIN1_INDEX] = {
            .GPIOName = HAL_GPIO_PORTF,
            .PINNumber = HAL_GPIO_PIN1,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOF_PIN1_EVENTOUT,
        },

        // PF2
        [HAL_GPIO_PIN2_INDEX] = {
            .GPIOName = HAL_GPIO_PORTF,
            .PINNumber = HAL_GPIO_PIN2,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOF_PIN2_EVENTOUT,
        },

        // PF3
        [HAL_GPIO_PIN3_INDEX] = {
            .GPIOName = HAL_GPIO_PORTF,
            .PINNumber = HAL_GPIO_PIN3,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOF_PIN3_EVENTOUT,
        },

        // PF4
        [HAL_GPIO_PIN4_INDEX] = {
            .GPIOName = HAL_GPIO_PORTF,
            .PINNumber = HAL_GPIO_PIN4,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOF_PIN4_EVENTOUT,
        },

        // PF5
        [HAL_GPIO_PIN5_INDEX] = {
            .GPIOName = HAL_GPIO_PORTF,
            .PINNumber = HAL_GPIO_PIN5,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOF_PIN5_EVENTOUT,
        },

        // PF6
        [HAL_GPIO_PIN6_INDEX] = {
            .GPIOName = HAL_GPIO_PORTF,
            .PINNumber = HAL_GPIO_PIN6,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOF_PIN6_EVENTOUT,
        },

        // PF7
        [HAL_GPIO_PIN7_INDEX] = {
            .GPIOName = HAL_GPIO_PORTF,
            .PINNumber = HAL_GPIO_PIN7,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOF_PIN7_EVENTOUT,
        },

        // PF8
        [HAL_GPIO_PIN8_INDEX] = {
            .GPIOName = HAL_GPIO_PORTF,
            .PINNumber = HAL_GPIO_PIN8,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOF_PIN8_EVENTOUT,
        },

        // PF9
        [HAL_GPIO_PIN9_INDEX] = {
            .GPIOName = HAL_GPIO_PORTF,
            .PINNumber = HAL_GPIO_PIN9,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOF_PIN9_EVENTOUT,
        },

        // PF10
        [HAL_GPIO_PIN10_INDEX] = {
            .GPIOName = HAL_GPIO_PORTF,
            .PINNumber = HAL_GPIO_PIN10,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOF_PIN10_EVENTOUT,
        },

        // PF11
        [HAL_GPIO_PIN11_INDEX] = {
            .GPIOName = HAL_GPIO_PORTF,
            .PINNumber = HAL_GPIO_PIN11,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOF_PIN11_EVENTOUT,
        },

        // PF12
        [HAL_GPIO_PIN12_INDEX] = {
            .GPIOName = HAL_GPIO_PORTF,
            .PINNumber = HAL_GPIO_PIN12,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOF_PIN12_EVENTOUT,
        },

        // PF13
        [HAL_GPIO_PIN13_INDEX] = {
            .GPIOName = HAL_GPIO_PORTF,
            .PINNumber = HAL_GPIO_PIN13,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOF_PIN13_EVENTOUT,
        },

        // PF14
        [HAL_GPIO_PIN14_INDEX] = {
            .GPIOName = HAL_GPIO_PORTF,
            .PINNumber = HAL_GPIO_PIN14,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOF_PIN14_EVENTOUT,
        },

        // PF15
        [HAL_GPIO_PIN15_INDEX] = {
            .GPIOName = HAL_GPIO_PORTF,
            .PINNumber = HAL_GPIO_PIN15,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOF_PIN15_EVENTOUT,
        },
    },

    // configure pins of GPIO G
    [HAL_GPIO_PORTG_INDEX] = {

        // PG0
        [HAL_GPIO_PIN0_INDEX] = {
            .GPIOName = HAL_GPIO_PORTG,
            .PINNumber = HAL_GPIO_PIN0,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOG_PIN0_EVENTOUT,
        },

        // PG1
        [HAL_GPIO_PIN1_INDEX] = {
            .GPIOName = HAL_GPIO_PORTG,
            .PINNumber = HAL_GPIO_PIN1,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOG_PIN1_EVENTOUT,
        },

        // PG2
        [HAL_GPIO_PIN2_INDEX] = {
            .GPIOName = HAL_GPIO_PORTG,
            .PINNumber = HAL_GPIO_PIN2,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOG_PIN2_EVENTOUT,
        },

        // PG3
        [HAL_GPIO_PIN3_INDEX] = {
            .GPIOName = HAL_GPIO_PORTG,
            .PINNumber = HAL_GPIO_PIN3,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOG_PIN3_EVENTOUT,
        },

        // PG4
        [HAL_GPIO_PIN4_INDEX] = {
            .GPIOName = HAL_GPIO_PORTG,
            .PINNumber = HAL_GPIO_PIN4,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOG_PIN4_EVENTOUT,
        },

        // PG5
        [HAL_GPIO_PIN5_INDEX] = {
            .GPIOName = HAL_GPIO_PORTG,
            .PINNumber = HAL_GPIO_PIN5,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOG_PIN5_EVENTOUT,
        },

        // PG6
        [HAL_GPIO_PIN6_INDEX] = {
            .GPIOName = HAL_GPIO_PORTG,
            .PINNumber = HAL_GPIO_PIN6,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOG_PIN6_EVENTOUT,
        },

        // PG7
        [HAL_GPIO_PIN7_INDEX] = {
            .GPIOName = HAL_GPIO_PORTG,
            .PINNumber = HAL_GPIO_PIN7,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOG_PIN7_EVENTOUT,
        },

        // PG8
        [HAL_GPIO_PIN8_INDEX] = {
            .GPIOName = HAL_GPIO_PORTG,
            .PINNumber = HAL_GPIO_PIN8,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOG_PIN8_EVENTOUT,
        },

        // PG9
        [HAL_GPIO_PIN9_INDEX] = {
            .GPIOName = HAL_GPIO_PORTG,
            .PINNumber = HAL_GPIO_PIN9,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOG_PIN9_EVENTOUT,
        },

        // PG10
        [HAL_GPIO_PIN10_INDEX] = {
            .GPIOName = HAL_GPIO_PORTG,
            .PINNumber = HAL_GPIO_PIN10,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOG_PIN10_EVENTOUT,
        },

        // PG11
        [HAL_GPIO_PIN11_INDEX] = {
            .GPIOName = HAL_GPIO_PORTG,
            .PINNumber = HAL_GPIO_PIN11,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOG_PIN11_EVENTOUT,
        },

        // PG12
        [HAL_GPIO_PIN12_INDEX] = {
            .GPIOName = HAL_GPIO_PORTG,
            .PINNumber = HAL_GPIO_PIN12,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOG_PIN12_EVENTOUT,
        },

        // PG13
        [HAL_GPIO_PIN13_INDEX] = {
            .GPIOName = HAL_GPIO_PORTG,
            .PINNumber = HAL_GPIO_PIN13,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOG_PIN13_EVENTOUT,
        },

        // PG14
        [HAL_GPIO_PIN14_INDEX] = {
            .GPIOName = HAL_GPIO_PORTG,
            .PINNumber = HAL_GPIO_PIN14,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOG_PIN14_EVENTOUT,
        },

        // PG15
        [HAL_GPIO_PIN15_INDEX] = {
            .GPIOName = HAL_GPIO_PORTG,
            .PINNumber = HAL_GPIO_PIN15,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOG_PIN15_EVENTOUT,
        },
    },

    // configure pins of GPIO H
    [HAL_GPIO_PORTH_INDEX] = {

        // PH0
        [HAL_GPIO_PIN0_INDEX] = {
            .GPIOName = HAL_GPIO_PORTH,
            .PINNumber = HAL_GPIO_PIN0,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOH_PIN0_EVENTOUT,
        },

        // PH1
        [HAL_GPIO_PIN1_INDEX] = {
            .GPIOName = HAL_GPIO_PORTH,
            .PINNumber = HAL_GPIO_PIN1,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOH_PIN1_EVENTOUT,
        },

        // PH2
        [HAL_GPIO_PIN2_INDEX] = {
            .GPIOName = HAL_GPIO_PORTH,
            .PINNumber = HAL_GPIO_PIN2,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOH_PIN2_EVENTOUT,
        },

        // PH3
        [HAL_GPIO_PIN3_INDEX] = {
            .GPIOName = HAL_GPIO_PORTH,
            .PINNumber = HAL_GPIO_PIN3,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOH_PIN3_EVENTOUT,
        },

        // PH4
        [HAL_GPIO_PIN4_INDEX] = {
            .GPIOName = HAL_GPIO_PORTH,
            .PINNumber = HAL_GPIO_PIN4,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOH_PIN4_EVENTOUT,
        },

        // PH5
        [HAL_GPIO_PIN5_INDEX] = {
            .GPIOName = HAL_GPIO_PORTH,
            .PINNumber = HAL_GPIO_PIN5,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOH_PIN5_EVENTOUT,
        },

        // PH6
        [HAL_GPIO_PIN6_INDEX] = {
            .GPIOName = HAL_GPIO_PORTH,
            .PINNumber = HAL_GPIO_PIN6,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOH_PIN6_EVENTOUT,
        },

        // PH7
        [HAL_GPIO_PIN7_INDEX] = {
            .GPIOName = HAL_GPIO_PORTH,
            .PINNumber = HAL_GPIO_PIN7,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOH_PIN7_EVENTOUT,
        },

        // PH8
        [HAL_GPIO_PIN8_INDEX] = {
            .GPIOName = HAL_GPIO_PORTH,
            .PINNumber = HAL_GPIO_PIN8,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOH_PIN8_EVENTOUT,
        },

        // PH9
        [HAL_GPIO_PIN9_INDEX] = {
            .GPIOName = HAL_GPIO_PORTH,
            .PINNumber = HAL_GPIO_PIN9,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOH_PIN9_EVENTOUT,
        },

        // PH10
        [HAL_GPIO_PIN10_INDEX] = {
            .GPIOName = HAL_GPIO_PORTH,
            .PINNumber = HAL_GPIO_PIN10,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOH_PIN10_EVENTOUT,
        },

        // PH11
        [HAL_GPIO_PIN11_INDEX] = {
            .GPIOName = HAL_GPIO_PORTH,
            .PINNumber = HAL_GPIO_PIN11,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOH_PIN11_EVENTOUT,
        },

        // PH12
        [HAL_GPIO_PIN12_INDEX] = {
            .GPIOName = HAL_GPIO_PORTH,
            .PINNumber = HAL_GPIO_PIN12,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOH_PIN12_EVENTOUT,
        },

        // PH13
        [HAL_GPIO_PIN13_INDEX] = {
            .GPIOName = HAL_GPIO_PORTH,
            .PINNumber = HAL_GPIO_PIN13,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOH_PIN13_EVENTOUT,
        },

        // PH14
        [HAL_GPIO_PIN14_INDEX] = {
            .GPIOName = HAL_GPIO_PORTH,
            .PINNumber = HAL_GPIO_PIN14,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOH_PIN14_EVENTOUT,
        },

        // PH15
        [HAL_GPIO_PIN15_INDEX] = {
            .GPIOName = HAL_GPIO_PORTH,
            .PINNumber = HAL_GPIO_PIN15,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOH_PIN15_EVENTOUT,
        },
    },

    // configure pins of GPIO I
    [HAL_GPIO_PORTI_INDEX] = {

        // PI0
        [HAL_GPIO_PIN0_INDEX] = {
            .GPIOName = HAL_GPIO_PORTI,
            .PINNumber = HAL_GPIO_PIN0,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOI_PIN0_EVENTOUT,
        },

        // PI1
        [HAL_GPIO_PIN1_INDEX] = {
            .GPIOName = HAL_GPIO_PORTI,
            .PINNumber = HAL_GPIO_PIN1,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOI_PIN1_EVENTOUT,
        },

        // PI2
        [HAL_GPIO_PIN2_INDEX] = {
            .GPIOName = HAL_GPIO_PORTI,
            .PINNumber = HAL_GPIO_PIN2,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOI_PIN2_EVENTOUT,
        },

        // PI3
        [HAL_GPIO_PIN3_INDEX] = {
            .GPIOName = HAL_GPIO_PORTI,
            .PINNumber = HAL_GPIO_PIN3,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOI_PIN3_EVENTOUT,
        },

        // PI4
        [HAL_GPIO_PIN4_INDEX] = {
            .GPIOName = HAL_GPIO_PORTI,
            .PINNumber = HAL_GPIO_PIN4,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOI_PIN4_EVENTOUT,
        },

        // PI5
        [HAL_GPIO_PIN5_INDEX] = {
            .GPIOName = HAL_GPIO_PORTI,
            .PINNumber = HAL_GPIO_PIN5,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOI_PIN5_EVENTOUT,
        },

        // PI6
        [HAL_GPIO_PIN6_INDEX] = {
            .GPIOName = HAL_GPIO_PORTI,
            .PINNumber = HAL_GPIO_PIN6,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOI_PIN6_EVENTOUT,
        },

        // PI7
        [HAL_GPIO_PIN7_INDEX] = {
            .GPIOName = HAL_GPIO_PORTI,
            .PINNumber = HAL_GPIO_PIN7,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOI_PIN7_EVENTOUT,
        },

        // PI8
        [HAL_GPIO_PIN8_INDEX] = {
            .GPIOName = HAL_GPIO_PORTI,
            .PINNumber = HAL_GPIO_PIN8,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOI_PIN8_EVENTOUT,
        },

        // PI9
        [HAL_GPIO_PIN9_INDEX] = {
            .GPIOName = HAL_GPIO_PORTI,
            .PINNumber = HAL_GPIO_PIN9,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOI_PIN9_EVENTOUT,
        },

        // PI10
        [HAL_GPIO_PIN10_INDEX] = {
            .GPIOName = HAL_GPIO_PORTI,
            .PINNumber = HAL_GPIO_PIN10,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOI_PIN10_EVENTOUT,
        },

        // PI11
        [HAL_GPIO_PIN11_INDEX] = {
            .GPIOName = HAL_GPIO_PORTI,
            .PINNumber = HAL_GPIO_PIN11,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOI_PIN11_EVENTOUT,
        },

        // PI12
        [HAL_GPIO_PIN12_INDEX] = {
            .GPIOName = HAL_GPIO_PORTI,
            .PINNumber = HAL_GPIO_PIN12,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOI_PIN12_EVENTOUT,
        },

        // PI13
        [HAL_GPIO_PIN13_INDEX] = {
            .GPIOName = HAL_GPIO_PORTI,
            .PINNumber = HAL_GPIO_PIN13,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOI_PIN13_EVENTOUT,
        },

        // PI14
        [HAL_GPIO_PIN14_INDEX] = {
            .GPIOName = HAL_GPIO_PORTI,
            .PINNumber = HAL_GPIO_PIN14,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOI_PIN14_EVENTOUT,
        },

        // PI15
        [HAL_GPIO_PIN15_INDEX] = {
            .GPIOName = HAL_GPIO_PORTI,
            .PINNumber = HAL_GPIO_PIN15,
            .Mode = HAL_GPIO_PIN_MODE_INPUT,
            .OutputType = HAL_GPIO_OUT_MODE_PUSH_PULL,
            .OutputSpeed = HAL_GPIO_OUT_SPEED_LOW,
            .PullUpDown = HAL_GPIO_NO_PULL_UP_DOWN,
            .LockEnable = LIB_CONSTANTS_UNLOCKED,
            .AlternateFunction = HAL_GPIOI_PIN15_EVENTOUT,
        },
    },

};

/******************************************************************************
 * Function Prototypes
 *******************************************************************************/

/*** End of File **************************************************************/
#endif /*HAL_GPIO_CONFIG_H_*/
