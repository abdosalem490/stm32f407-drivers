/**
 * --------------------------------------------------------------------------------------------------------------------------------------
 * |    @title          :   Reset and clock control                                                                                     |
 * |    @file           :   RCC_reg.h                                                                                                   |
 * |    @author         :   Abdelrahman Mohamed Salem                                                                                   |
 * |    @origin_date    :   17/08/2023                                                                                                  |
 * |    @version        :   1.0.0                                                                                                       |
 * |    @tool_chain     :   GNU Tools for STM32                                                                                         |
 * |    @compiler       :   GCC                                                                                                         |
 * |    @C_standard     :   ISO C99 (-std=c99)                                                                                          |
 * |    @target         :   stm32f407VGTX                                                                                               |
 * |    @notes          :   None                                                                                                        |
 * |    @license        :   MIT License                                                                                                 |
 * |    @brief          :   this file contains registers addresses and definitions structs that deals with RCC registers                |
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

#ifndef HAL_RCC_REG_H_
#define HAL_RCC_REG_H_

/******************************************************************************
 * Includes
 *******************************************************************************/
/**
 * @reason: contains standard definitions for the integer variables
 */
#include "../../lib/stdint.h"

/**
 * @reason: contains base addresses of AHB1 bus
 */
#include "../CM4F/CM4F_reg.h"

/**
 * @reason: contains volatile keyword definition regarding selected compiler
 */
#include "../../lib/common.h"

/******************************************************************************
 * Preprocessor Constants
 *******************************************************************************/

/**
 * @brief: this is the base address of RCC registers used to configure some of the RCC behaviors
 * @note: it will be referred to as @HAL_RCC_BASE_ADDR
 */
#define HAL_RCC_OFFSET 0x00003800 /**< this is the offset of the RCC register from AHB1 bus base address*/

/**
 * @brief: RCC clock control register (RCC_CR), Reset value: 0x0000 XX83 where X is undefined.
 */
#define HAL_RCC_CR_PLLI2SRDY 27 /**< PLLI2S clock ready flag. Set by hardware to indicate that the PLLI2S is locked.*/
#define HAL_RCC_CR_PLLI2SON 26  /**< PLLI2S enable. Set and cleared by software to enable PLLI2S. Cleared by hardware when entering Stop or Standby mode. */
#define HAL_RCC_CR_PLLRDY 25    /**< Main PLL (PLL) clock ready flag. Set by hardware to indicate that PLL is locked.*/
#define HAL_RCC_CR_PLLON 24     /**< Main PLL (PLL) enable. Set and cleared by software to enable PLL. Cleared by hardware when entering Stop or Standby mode. This bit cannot be reset if PLL clock is used as the system clock.*/
#define HAL_RCC_CR_CSSON 19     /**< Clock security system enable. Set and cleared by software to enable the clock security system. When CSSON is set, the clock detector is enabled by hardware when the HSE oscillator is ready, and disabled by hardware if an oscillator failure is detected.*/
#define HAL_RCC_CR_HSEBYP 18    /**< HSE clock bypass. Set and cleared by software to bypass the oscillator with an external clock. The external clock must be enabled with the HSEON bit, to be used by the device. The HSEBYP bit can be written only if the HSE oscillator is disabled.*/
#define HAL_RCC_CR_HSERDY 17    /**< HSE clock ready flag. Set by hardware to indicate that the HSE oscillator is stable. After the HSEON bit is cleared, HSERDY goes low after 6 HSE oscillator clock cycles.*/
#define HAL_RCC_CR_HSEON 16     /**< HSE clock enable. Set and cleared by software. Cleared by hardware to stop the HSE oscillator when entering Stop or Standby mode. This bit cannot be reset if the HSE oscillator is used directly or indirectly as the system clock.*/
#define HAL_RCC_CR_HSICAL 8     /**< Internal high-speed clock calibration. These bits are initialized automatically at startup.*/
#define HAL_RCC_CR_HSITRIM 3    /**< Internal high-speed clock trimming. These bits provide an additional user-programmable trimming value that is added to the HSICAL[7:0] bits. It can be programmed to adjust to variations in voltage and temperature that influence the frequency of the internal HSI RC.*/
#define HAL_RCC_CR_HSIRDY 1     /**< Internal high-speed clock ready flag. Set by hardware to indicate that the HSI oscillator is stable. After the HSION bit is cleared, HSIRDY goes low after 6 HSI clock cycles.*/
#define HAL_RCC_CR_HSION 0      /**< Internal high-speed clock enable. Set and cleared by software. Set by hardware to force the HSI oscillator ON when leaving the Stop or Standby mode or in case of a failure of the HSE oscillator used directly or indirectly as the system clock. This bit  cannot be cleared if the HSI is used directly or indirectly as the system clock.*/

/**
 * @brief: RCC PLL configuration register (RCC_PLLCFGR), Reset value:0x2400 3010.
 */
#define HAL_RCC_PLLCFGR_PLLQ 24   /**< Main PLL (PLL) division factor for USB OTG FS, SDIO and random number generator clocks. Set and cleared by software to control the frequency of USB OTG FS clock, the random number generator clock and the SDIO clock. These bits should be written only if PLL is disabled.*/
#define HAL_RCC_PLLCFGR_PLLSRC 22 /**< Main PLL(PLL) and audio PLL (PLLI2S) entry clock source. Set and cleared by software to select PLL and PLLI2S clock source. This bit can be written only when PLL and PLLI2S are disabled.*/
#define HAL_RCC_PLLCFGR_PLLP 16   /**< Main PLL (PLL) division factor for main system clock. Set and cleared by software to control the frequency of the general PLL output clock. These bits can be written only if PLL is disabled.*/
#define HAL_RCC_PLLCFGR_PLLN 6    /**< Main PLL (PLL) multiplication factor for VCO. Set and cleared by software to control the multiplication factor of the VCO. These bits can be written only when PLL is disabled. Only half-word and word accesses are allowed to write these bits.*/
#define HAL_RCC_PLLCFGR_PLLM 0    /**< Division factor for the main PLL (PLL) and audio PLL (PLLI2S) input clock. Set and cleared by software to divide the PLL and PLLI2S input clock before the VCO. These bits can be written only when the PLL and PLLI2S are disabled.*/

/**
 * @brief: RCC clock configuration register (RCC_CFGR), Reset value: 0x0000 0000.
 */
#define HAL_RCC_CFGR_MCO2 30    /**< Microcontroller clock output 2. Set and cleared by software. Clock source selection may generate glitches on MCO2. It is highly recommended to configure these bits only after reset before enabling the external oscillators and the PLLs.*/
#define HAL_RCC_CFGR_MCO2PRE 27 /**< MCO2 prescaler. Set and cleared by software to configure the prescaler of the MCO2. Modification of this prescaler may generate glitches on MCO2. It is highly recommended to change this prescaler only after reset before enabling the external oscillators and the PLLs.*/
#define HAL_RCC_CFGR_MCO1PRE 24 /**< MCO1 prescaler. Set and cleared by software to configure the prescaler of the MCO1. Modification of this prescaler may generate glitches on MCO1. It is highly recommended to change this prescaler only after reset before enabling the external oscillators and the PLL.*/
#define HAL_RCC_CFGR_I2SSRC 23  /**< I2S clock selection. Set and cleared by software. This bit allows to select the I2S clock source between the PLLI2S clock and the external clock. It is highly recommended to change this bit only after  reset and before enabling the I2S module.*/
#define HAL_RCC_CFGR_MCO1 21    /**< Microcontroller clock output 1. Set and cleared by software. Clock source selection may generate glitches on MCO1. It is highly recommended to configure these bits only after reset before enabling the external oscillators and PLL.*/
#define HAL_RCC_CFGR_RTCPRE 16  /**< HSE division factor for RTC clock. Set and cleared by software to divide the HSE clock input clock to generate a 1 MHz clock for RTC.*/
#define HAL_RCC_CFGR_PPRE2 13   /**< APB high-speed prescaler (APB2). Set and cleared by software to control APB high-speed clock division factor.*/
#define HAL_RCC_CFGR_PPRE1 10   /**< APB Low speed prescaler (APB1). Set and cleared by software to control APB low-speed clock division factor.*/
#define HAL_RCC_CFGR_HPRE 4     /**< AHB prescaler. Set and cleared by software to control AHB clock division factor. */
#define HAL_RCC_CFGR_SWS 2      /**< System clock switch status. Set and cleared by hardware to indicate which clock source is used as the system clock.*/
#define HAL_RCC_CFGR_SW 0       /**< System clock switch. Set and cleared by software to select the system clock source. Set by hardware to force the HSI selection when leaving the Stop or Standby mode or in case of failure of the HSE oscillator used directly or indirectly as the system clock.*/

/**
 * @brief: RCC clock interrupt register (RCC_CIR), Reset value: 0x0000 0000.
 */
#define HAL_RCC_CIR_CSSC 23        /**< Clock security system interrupt clear. This bit is set by software to clear the CSSF flag.*/
#define HAL_RCC_CIR_PLLI2SRDYC 21  /**< PLLI2S ready interrupt clear. This bit is set by software to clear the PLLI2SRDYF flag.*/
#define HAL_RCC_CIR_PLLRDYC 20     /**< Main PLL(PLL) ready interrupt clear. This bit is set by software to clear the PLLRDYF flag.*/
#define HAL_RCC_CIR_HSERDYC 19     /**< HSE ready interrupt clear. This bit is set by software to clear the HSERDYF flag.*/
#define HAL_RCC_CIR_HSIRDYC 18     /**< HSI ready interrupt clear. This bit is set software to clear the HSIRDYF flag.*/
#define HAL_RCC_CIR_LSERDYC 17     /**< LSE ready interrupt clear. This bit is set by software to clear the LSERDYF flag.*/
#define HAL_RCC_CIR_LSIRDYC 16     /**< LSI ready interrupt clear. This bit is set by software to clear the LSIRDYF flag.*/
#define HAL_RCC_CIR_PLLI2SRDYIE 13 /**< PLLI2S ready interrupt enable. Set and cleared by software to enable/disable interrupt caused by PLLI2S lock.*/
#define HAL_RCC_CIR_PLLRDYIE 12    /**< Main PLL (PLL) ready interrupt enable. Set and cleared by software to enable/disable interrupt caused by PLL lock.*/
#define HAL_RCC_CIR_HSERDYIE 11    /**< HSE ready interrupt enable. Set and cleared by software to enable/disable interrupt caused by the HSE oscillator stabilization.*/
#define HAL_RCC_CIR_HSIRDYIE 10    /**< HSI ready interrupt enable. Set and cleared by software to enable/disable interrupt caused by the HSI oscillator stabilization.*/
#define HAL_RCC_CIR_LSERDYIE 9     /**< LSE ready interrupt enable. Set and cleared by software to enable/disable interrupt caused by the LSE oscillator stabilization.*/
#define HAL_RCC_CIR_LSIRDYIE 8     /**< LSI ready interrupt enable. Set and cleared by software to enable/disable interrupt caused by LSI oscillator stabilization.*/
#define HAL_RCC_CIR_CSSF 7         /**< Clock security system interrupt flag. Set by hardware when a failure is detected in the HSE oscillator. Cleared by software setting the CSSC bit.*/
#define HAL_RCC_CIR_PLLI2SRDYF 6   /**< PLLI2S ready interrupt flag. Set by hardware when the PLLI2S locks and PLLI2SRDYDIE is set. Cleared by software setting the PLLRI2SDYC bit.*/
#define HAL_RCC_CIR_PLLRDYF 4      /**< Main PLL (PLL) ready interrupt flag. Set by hardware when PLL locks and PLLRDYDIE is set. Cleared by software setting the PLLRDYC bit.*/
#define HAL_RCC_CIR_HSERDYF 3      /**< HSE ready interrupt flag. Set by hardware when External High Speed clock becomes stable and HSERDYDIE is set. Cleared by software setting the HSERDYC bit.*/
#define HAL_RCC_CIR_HSIRDYF 2      /**< HSI ready interrupt flag. Set by hardware when the Internal High Speed clock becomes stable and HSIRDYDIE is set. Cleared by software setting the HSIRDYC bit.*/
#define HAL_RCC_CIR_LSERDYF 1      /**< LSE ready interrupt flag. Set by hardware when the External Low Speed clock becomes stable and LSERDYDIE is  set. Cleared by software setting the LSERDYC bit.*/
#define HAL_RCC_CIR_LSIRDYF 0      /**< LSI ready interrupt flag. Set by hardware when the internal low speed clock becomes stable and LSIRDYDIE is set. Cleared by software setting the LSIRDYC bit.*/

/**
 * @brief: bit definitions for RCC AHB1 peripheral reset register (RCC_AHB1RSTR), Reset value: 0x0000 0000.
 */
#define HAL_RCC_AHB1RSTR_OTGHSRST 29  /**< USB OTG HS module reset. Set and cleared by software.*/
#define HAL_RCC_AHB1RSTR_ETHMACRST 25 /**< Ethernet MAC reset. Set and cleared by software.*/
#define HAL_RCC_AHB1RSTR_DMA2RST 22   /**< DMA2 reset. Set and cleared by software.*/
#define HAL_RCC_AHB1RSTR_DMA1RST 21   /**< DMA1 reset. Set and cleared by software.*/
#define HAL_RCC_AHB1RSTR_CRCRST 12    /**< CRC reset. Set and cleared by software.*/
#define HAL_RCC_AHB1RSTR_GPIOIRST 8   /**<  IO port I reset. Set and cleared by software.*/
#define HAL_RCC_AHB1RSTR_GPIOHRST 7   /**<  IO port H reset. Set and cleared by software.*/
#define HAL_RCC_AHB1RSTR_GPIOGRST 6   /**<  IO port G reset. Set and cleared by software.*/
#define HAL_RCC_AHB1RSTR_GPIOFRST 5   /**<  IO port F reset. Set and cleared by software.*/
#define HAL_RCC_AHB1RSTR_GPIOERST 4   /**<  IO port E reset. Set and cleared by software.*/
#define HAL_RCC_AHB1RSTR_GPIODRST 3   /**<  IO port D reset. Set and cleared by software.*/
#define HAL_RCC_AHB1RSTR_GPIOCRST 2   /**<  IO port C reset. Set and cleared by software.*/
#define HAL_RCC_AHB1RSTR_GPIOBRST 1   /**<  IO port B reset. Set and cleared by software.*/
#define HAL_RCC_AHB1RSTR_GPIOARST 0   /**<  IO port A reset. Set and cleared by software.*/

/**
 * @brief: bit definitions for RCC AHB2 peripheral reset register (RCC_AHB2RSTR), Reset value: 0x0000 0000.
 */
#define HAL_RCC_AHB2RSTR_OTGFSRST 7 /**< USB OTG FS module reset. Set and cleared by software.*/
#define HAL_RCC_AHB2RSTR_RNGRST 6   /**< Random number generator module reset. Set and cleared by software.*/
#define HAL_RCC_AHB2RSTR_HASHRST 5  /**< Hash module reset. Set and cleared by software.*/
#define HAL_RCC_AHB2RSTR_CRYPRST 4  /**< Cryptographic module reset. Set and cleared by software.*/
#define HAL_RCC_AHB2RSTR_DCMIRST 0  /**< Camera interface reset. Set and cleared by software.*/

/**
 * @brief: bit definitions for RCC AHB3 peripheral reset register (RCC_AHB3RSTR), Reset value: 0x0000 0000.
 */
#define HAL_RCC_AHB3RSTR_FSMCRST 0 /**< Flexible static memory controller module reset. Set and cleared by software.*/

/**
 * @brief: bit definitions for RCC APB1 peripheral reset register (RCC_APB1RSTR), Reset value: 0x0000 0000.
 */
#define HAL_RCC_APB1RSTR_DACRST 29    /**< DAC reset. Set and cleared by software.*/
#define HAL_RCC_APB1RSTR_PWRRST 28    /**< Power interface reset. Set and cleared by software.*/
#define HAL_RCC_APB1RSTR_CAN2RST 26   /**< CAN2 reset. Set and cleared by software.*/
#define HAL_RCC_APB1RSTR_CAN1RST 25   /**< CAN1 reset. Set and cleared by software.*/
#define HAL_RCC_APB1RSTR_I2C3RST 23   /**< I2C3 reset. Set and cleared by software.*/
#define HAL_RCC_APB1RSTR_I2C2RST 22   /**< I2C2 reset. Set and cleared by software.*/
#define HAL_RCC_APB1RSTR_I2C1RST 21   /**< I2C1 reset. Set and cleared by software.*/
#define HAL_RCC_APB1RSTR_UART5RST 20  /**< UART5 reset. Set and cleared by software.*/
#define HAL_RCC_APB1RSTR_UART4RST 19  /**< UART4 reset. Set and cleared by software.*/
#define HAL_RCC_APB1RSTR_USART3RST 18 /**< USART3 reset. Set and cleared by software.*/
#define HAL_RCC_APB1RSTR_USART2RST 17 /**< USART2 reset. Set and cleared by software.*/
#define HAL_RCC_APB1RSTR_SPI3RST 15   /**< SPI3 reset. Set and cleared by software.*/
#define HAL_RCC_APB1RSTR_SPI2RST 14   /**< SPI2 reset. Set and cleared by software.*/
#define HAL_RCC_APB1RSTR_WWDGRST 11   /**< Window watchdog reset. Set and cleared by software.*/
#define HAL_RCC_APB1RSTR_TIM14RST 8   /**< TIM14 reset. Set and cleared by software.*/
#define HAL_RCC_APB1RSTR_TIM13RST 7   /**< TIM13 reset. Set and cleared by software.*/
#define HAL_RCC_APB1RSTR_TIM12RST 6   /**< TIM12 reset. Set and cleared by software.*/
#define HAL_RCC_APB1RSTR_TIM7RST 5    /**< TIM7 reset. Set and cleared by software.*/
#define HAL_RCC_APB1RSTR_TIM6RST 4    /**< TIM6 reset. Set and cleared by software.*/
#define HAL_RCC_APB1RSTR_TIM5RST 3    /**< TIM5 reset. Set and cleared by software.*/
#define HAL_RCC_APB1RSTR_TIM4RST 2    /**< TIM4 reset. Set and cleared by software.*/
#define HAL_RCC_APB1RSTR_TIM3RST 1    /**< TIM3 reset. Set and cleared by software.*/
#define HAL_RCC_APB1RSTR_TIM2RST 0    /**< TIM2 reset. Set and cleared by software.*/

/**
 * @brief: bit definitions for RCC APB2 peripheral reset register (RCC_APB2RSTR), Reset value: 0x0000 0000.
 */
#define HAL_RCC_APB2RSTR_TIM11RST 18  /**< TIM11 reset. Set and cleared by software.*/
#define HAL_RCC_APB2RSTR_TIM10RST 17  /**< TIM10 reset. Set and cleared by software.*/
#define HAL_RCC_APB2RSTR_TIM9RST 16   /**< TIM9 reset. Set and cleared by software.*/
#define HAL_RCC_APB2RSTR_SYSCFGRST 14 /**< System configuration controller reset. Set and cleared by software.*/
#define HAL_RCC_APB2RSTR_SPI1RST 12   /**< SPI1 reset. Set and cleared by software.*/
#define HAL_RCC_APB2RSTR_SDIORST 11   /**< SDIO reset. Set and cleared by software.*/
#define HAL_RCC_APB2RSTR_ADCRST 8     /**< ADC interface reset (common to all ADCs). Set and cleared by software.*/
#define HAL_RCC_APB2RSTR_USART6RST 5  /**< USART6 reset. Set and cleared by software.*/
#define HAL_RCC_APB2RSTR_USART1RST 4  /**< USART1 reset. Set and cleared by software.*/
#define HAL_RCC_APB2RSTR_TIM8RST 1    /**< TIM1 reset. Set and cleared by software.*/
#define HAL_RCC_APB2RSTR_TIM1RST 0    /**< TIM8 reset. Set and cleared by software.*/

/**
 * @brief: bit definitions for RCC AHB1 peripheral clock enable register (RCC_AHB1ENR), Reset value: 0x0010 0000.
 */
#define HAL_RCC_AHB1ENR_OTGHSULPIEN 30  /**< USB OTG HSULPI clock enable. Set and cleared by software. This bit must be cleared when the OTG_HS is used in FS mode.*/
#define HAL_RCC_AHB1ENR_OTGHSEN 29      /**< USB OTG HS clock enable. Set and cleared by software.*/
#define HAL_RCC_AHB1ENR_ETHMACPTPEN 28  /**< Ethernet PTP clock enable. Set and cleared by software. */
#define HAL_RCC_AHB1ENR_ETHMACRXEN 27   /**< Ethernet Reception clock enable. Set and cleared by software.*/
#define HAL_RCC_AHB1ENR_ETHMACTXEN 26   /**< Ethernet Transmission clock enable. Set and cleared by software.*/
#define HAL_RCC_AHB1ENR_ETHMACEN 25     /**< Ethernet MAC clock enable. Set and cleared by software.*/
#define HAL_RCC_AHB1ENR_DMA2EN 22       /**< DMA2 clock enable. Set and cleared by software..*/
#define HAL_RCC_AHB1ENR_DMA1EN 21       /**< DMA1 clock enable. Set and cleared by software.*/
#define HAL_RCC_AHB1ENR_CCMDATARAMEN 20 /**< CCM data RAM clock enable. Set and cleared by software.  */
#define HAL_RCC_AHB1ENR_BKPSRAMEN 18    /**< Backup SRAM interface clock enable. Set and cleared by software.*/
#define HAL_RCC_AHB1ENR_CRCEN 12        /**< CRC clock enable. Set and cleared by software.*/
#define HAL_RCC_AHB1ENR_GPIOIEN 8       /**< IO port I clock enable. Set and cleared by software. */
#define HAL_RCC_AHB1ENR_GPIOHEN 7       /**< IO port H clock enable. Set and cleared by software. */
#define HAL_RCC_AHB1ENR_GPIOGEN 6       /**< IO port G clock enable. Set and cleared by software. */
#define HAL_RCC_AHB1ENR_GPIOFEN 5       /**< IO port F clock enable. Set and cleared by software. */
#define HAL_RCC_AHB1ENR_GPIOEEN 4       /**< IO port E clock enable. Set and cleared by software. */
#define HAL_RCC_AHB1ENR_GPIODEN 3       /**< IO port D clock enable. Set and cleared by software. */
#define HAL_RCC_AHB1ENR_GPIOCEN 2       /**< IO port C clock enable. Set and cleared by software. */
#define HAL_RCC_AHB1ENR_GPIOBEN 1       /**< IO port B clock enable. Set and cleared by software. */
#define HAL_RCC_AHB1ENR_GPIOAEN 0       /**< IO port A clock enable. Set and cleared by software. */

/**
 * @brief: bit definitions for RCC AHB2 peripheral clock enable register (RCC_AHB2ENR), Reset value: 0x0000 0000.
 */
#define HAL_RCC_AHB2ENR_OTGFSEN 7 /**< USB OTG FS clock enable. Set and cleared by software. */
#define HAL_RCC_AHB2ENR_RNGEN 6   /**< Random number generator clock enable. Set and cleared by software.*/
#define HAL_RCC_AHB2ENR_HASHEN 5  /**< Hash modules clock enable. Set and cleared by software.*/
#define HAL_RCC_AHB2ENR_CRYPEN 4  /**< Cryptographic modules clock enable. Set and cleared by software.*/
#define HAL_RCC_AHB2ENR_DCMIEN 0  /**< Camera interface enable. Set and cleared by software.*/

/**
 * @brief: bit definitions for RCC AHB3 peripheral clock enable register (RCC_AHB3ENR), Reset value: 0x0000 0000.
 */
#define HAL_RCC_AHB3ENR_FSMCEN 0 /**< Flexible static memory controller module clock enable. Set and cleared by software.*/

/**
 * @brief: bit definitions for RCC APB1 peripheral clock enable register (RCC_APB1ENR), Reset value: 0x0000 0000.
 */
#define HAL_RCC_APB1ENR_DACEN 29    /**< DAC interface clock enable. Set and cleared by software.*/
#define HAL_RCC_APB1ENR_PWREN 28    /**< Power interface clock enable. Set and cleared by software.*/
#define HAL_RCC_APB1ENR_CAN2EN 26   /**< CAN 2 clock enable. Set and cleared by software.*/
#define HAL_RCC_APB1ENR_CAN1EN 25   /**< CAN 1 clock enable. Set and cleared by software.*/
#define HAL_RCC_APB1ENR_I2C3EN 23   /**< I2C3 clock enable. Set and cleared by software.*/
#define HAL_RCC_APB1ENR_I2C2EN 22   /**< I2C2 clock enable. Set and cleared by software.*/
#define HAL_RCC_APB1ENR_I2C1EN 21   /**< I2C1 clock enable. Set and cleared by software.*/
#define HAL_RCC_APB1ENR_UART5EN 20  /**< UART5 clock enable. Set and cleared by software.*/
#define HAL_RCC_APB1ENR_UART4EN 19  /**< UART4 clock enable. Set and cleared by software.*/
#define HAL_RCC_APB1ENR_USART3EN 18 /**< USART3 clock enable. Set and cleared by software.*/
#define HAL_RCC_APB1ENR_USART2EN 17 /**< USART2 clock enable. Set and cleared by software.*/
#define HAL_RCC_APB1ENR_SPI3EN 15   /**< SPI3 clock enable. Set and cleared by software.*/
#define HAL_RCC_APB1ENR_SPI2EN 14   /**< SPI2 clock enable. Set and cleared by software.*/
#define HAL_RCC_APB1ENR_WWDGEN 11   /**< Window watchdog clock enable. Set and cleared by software.*/
#define HAL_RCC_APB1ENR_TIM14EN 8   /**< TIM14 clock enable. Set and cleared by software.*/
#define HAL_RCC_APB1ENR_TIM13EN 7   /**< TIM13 clock enable. Set and cleared by software.*/
#define HAL_RCC_APB1ENR_TIM12EN 6   /**< TIM12 clock enable. Set and cleared by software.*/
#define HAL_RCC_APB1ENR_TIM7EN 5    /**< TIM7 clock enable. Set and cleared by software.*/
#define HAL_RCC_APB1ENR_TIM6EN 4    /**< TIM6 clock enable. Set and cleared by software.*/
#define HAL_RCC_APB1ENR_TIM5EN 3    /**< TIM5 clock enable. Set and cleared by software.*/
#define HAL_RCC_APB1ENR_TIM4EN 2    /**< TIM4 clock enable. Set and cleared by software.*/
#define HAL_RCC_APB1ENR_TIM3EN 1    /**< TIM3 clock enable. Set and cleared by software.*/
#define HAL_RCC_APB1ENR_TIM2EN 0    /**< TIM2 clock enable. Set and cleared by software.*/

/**
 * @brief: bit definitions for RCC APB2 peripheral clock enable register (RCC_APB2ENR), Reset value: 0x0000 0000.
 */
#define HAL_RCC_APB2ENR_TIM11EN 18  /**< TIM11 clock enable. Set and cleared by software.*/
#define HAL_RCC_APB2ENR_TIM10EN 17  /**< TIM10 clock enable. Set and cleared by software.*/
#define HAL_RCC_APB2ENR_TIM9EN 16   /**< TIM9 clock enable. Set and cleared by software.*/
#define HAL_RCC_APB2ENR_SYSCFGEN 14 /**< System configuration controller clock enable. Set and cleared by software.*/
#define HAL_RCC_APB2ENR_SPI1EN 12   /**< SPI1 clock enable. Set and cleared by software.*/
#define HAL_RCC_APB2ENR_SDIOEN 11   /**< SDIO clock enable. Set and cleared by software.*/
#define HAL_RCC_APB2ENR_ADC3EN 10   /**< ADC3 clock enable. Set and cleared by software.*/
#define HAL_RCC_APB2ENR_ADC2EN 9    /**< ADC2 clock enable. Set and cleared by software.*/
#define HAL_RCC_APB2ENR_ADC1EN 8    /**< ADC1 clock enable. Set and cleared by software.*/
#define HAL_RCC_APB2ENR_USART6EN 5  /**< USART6 clock enable. Set and cleared by software.*/
#define HAL_RCC_APB2ENR_USART1EN 4  /**< USART1 clock enable. Set and cleared by software.*/
#define HAL_RCC_APB2ENR_TIM8EN 1    /**< TIM8 clock enable. Set and cleared by software.*/
#define HAL_RCC_APB2ENR_TIM1EN 0    /**< TIM1 clock enable. Set and cleared by software.*/

/**
 * @brief: bit definitions for RCC AHB1 peripheral clock enable in low power mode register (RCC_AHB1LPENR), Reset value: 0x7E67 91FF.
 */
#define HAL_RCC_AHB1LPENR_OTGHSULPILPEN 30 /**< USB OTG HS ULPI clock enable during Sleep mode. Set and cleared by software. This bit must be cleared when the OTG_HS is used in FS mode.*/
#define HAL_RCC_AHB1LPENR_OTGHSLPEN 29     /**< USB OTG HS clock enable during Sleep mode. Set and cleared by software.*/
#define HAL_RCC_AHB1LPENR_ETHMACPTPLPEN 28 /**< Ethernet PTP clock enable during Sleep mode. Set and cleared by software.*/
#define HAL_RCC_AHB1LPENR_ETHMACRXLPEN 27  /**< Ethernet reception clock enable during Sleep mode. Set and cleared by software.*/
#define HAL_RCC_AHB1LPENR_ETHMACTXLPEN 26  /**< Ethernet transmission clock enable during Sleep mode. Set and cleared by software.*/
#define HAL_RCC_AHB1LPENR_ETHMACLPEN 25    /**< Ethernet MAC clock enable during Sleep mode. Set and cleared by software.*/
#define HAL_RCC_AHB1LPENR_DMA2LPEN 22      /**< DMA2 clock enable during Sleep mode. Set and cleared by software.*/
#define HAL_RCC_AHB1LPENR_DMA1LPEN 21      /**< DMA1 clock enable during Sleep mode. Set and cleared by software.*/
#define HAL_RCC_AHB1LPENR_BKPSRAMLPEN 18   /**< Backup SRAM interface clock enable during Sleep mode. Set and cleared by software.*/
#define HAL_RCC_AHB1LPENR_SRAM2LPEN 17     /**< SRAM 2 interface clock enable during Sleep mode. Set and cleared by software.*/
#define HAL_RCC_AHB1LPENR_SRAM1LPEN 16     /**< SRAM 1interface clock enable during Sleep mode. Set and cleared by software.*/
#define HAL_RCC_AHB1LPENR_FLITFLPEN 15     /**< Flash interface clock enable during Sleep mode. Set and cleared by software.*/
#define HAL_RCC_AHB1LPENR_CRCLPEN 12       /**< CRC clock enable during Sleep mode. Set and cleared by software.*/
#define HAL_RCC_AHB1LPENR_GPIOILPEN 8      /**< IO port I clock enable during Sleep mode. Set and cleared by software.*/
#define HAL_RCC_AHB1LPENR_GPIOHLPEN 7      /**< IO port H clock enable during Sleep mode. Set and cleared by software.*/
#define HAL_RCC_AHB1LPENR_GPIOGLPEN 6      /**< IO port G clock enable during Sleep mode. Set and cleared by software.*/
#define HAL_RCC_AHB1LPENR_GPIOFLPEN 5      /**< IO port F clock enable during Sleep mode. Set and cleared by software.*/
#define HAL_RCC_AHB1LPENR_GPIOELPEN 4      /**< IO port E clock enable during Sleep mode. Set and cleared by software.*/
#define HAL_RCC_AHB1LPENR_GPIODLPEN 3      /**< IO port D clock enable during Sleep mode. Set and cleared by software.*/
#define HAL_RCC_AHB1LPENR_GPIOCLPEN 2      /**< IO port C clock enable during Sleep mode. Set and cleared by software.*/
#define HAL_RCC_AHB1LPENR_GPIOBLPEN 1      /**< IO port B clock enable during Sleep mode. Set and cleared by software.*/
#define HAL_RCC_AHB1LPENR_GPIOALPEN 0      /**< IO port A clock enable during Sleep mode. Set and cleared by software.*/

/**
 * @brief: bit definitions for RCC AHB2 peripheral clock enable in low power mode register (RCC_AHB2LPENR), Reset value: 0x0000 00F1.
 */
#define HAL_RCC_AHB2LPENR_OTGFSLPEN 7 /**< USB OTG FS clock enable during Sleep mode. Set and cleared by software.*/
#define HAL_RCC_AHB2LPENR_RNGLPEN 6   /**< Random number generator clock enable during Sleep mode. Set and cleared by software.*/
#define HAL_RCC_AHB2LPENR_HASHLPEN 5  /**< Hash modules clock enable during Sleep mode. Set and cleared by software.*/
#define HAL_RCC_AHB2LPENR_CRYPLPEN 4  /**< Cryptography modules clock enable during Sleep mode. Set and cleared by software.*/
#define HAL_RCC_AHB2LPENR_DCMILPEN 0  /**< Camera interface enable during Sleep mode. Set and cleared by software.*/

/**
 * @brief: bit definitions for RCC AHB3 peripheral clock enable in low power mode register (RCC_AHB3LPENR), Reset value: 0x0000 0001.
 */
#define HAL_RCC_AHB3LPENR_FSMCLPEN 0 /**< Flexible static memory controller module clock enable during Sleep mode. Set and cleared by software.*/

/**
 * @brief: bit definitions for RCC APB1 peripheral clock enable in low power mode register (RCC_APB1LPENR), Reset value: 0x36FE C9FF.
 */
#define HAL_RCC_APB1LPENR_DACLPEN 29    /**< DAC interface clock enable during Sleep mode. Set and cleared by software.*/
#define HAL_RCC_APB1LPENR_PWRLPEN 28    /**< Power interface clock enable during Sleep mode. Set and cleared by software.*/
#define HAL_RCC_APB1LPENR_CAN2LPEN 26   /**< CAN 2 clock enable during Sleep mode. Set and cleared by software.*/
#define HAL_RCC_APB1LPENR_CAN1LPEN 25   /**< CAN 1 clock enable during Sleep mode. Set and cleared by software.*/
#define HAL_RCC_APB1LPENR_I2C3LPEN 23   /**< I2C3 clock enable during Sleep mode. Set and cleared by software.*/
#define HAL_RCC_APB1LPENR_I2C2LPEN 22   /**< I2C2 clock enable during Sleep mode. Set and cleared by software.*/
#define HAL_RCC_APB1LPENR_I2C1LPEN 21   /**< I2C1 clock enable during Sleep mode. Set and cleared by software.*/
#define HAL_RCC_APB1LPENR_UART5LPEN 20  /**< UART5 clock enable during Sleep mode. Set and cleared by software.*/
#define HAL_RCC_APB1LPENR_UART4LPEN 19  /**< UART4 clock enable during Sleep mode. Set and cleared by software.*/
#define HAL_RCC_APB1LPENR_USART3LPEN 18 /**< USART3 clock enable during Sleep mode. Set and cleared by software.*/
#define HAL_RCC_APB1LPENR_USART2LPEN 17 /**< USART2 clock enable during Sleep mode. Set and cleared by software.*/
#define HAL_RCC_APB1LPENR_SPI3LPEN 15   /**< SPI3 clock enable during Sleep mode. Set and cleared by software.*/
#define HAL_RCC_APB1LPENR_SPI2LPEN 14   /**< SPI2 clock enable during Sleep mode. Set and cleared by software.*/
#define HAL_RCC_APB1LPENR_WWDGLPEN 11   /**< Window watchdog clock enable during Sleep mode. Set and cleared by software.*/
#define HAL_RCC_APB1LPENR_TIM14LPEN 8   /**< TIM14 clock enable during Sleep mode*/
#define HAL_RCC_APB1LPENR_TIM13LPEN 7   /**< TIM13 clock enable during Sleep mode*/
#define HAL_RCC_APB1LPENR_TIM12LPEN 6   /**< TIM12 clock enable during Sleep mode*/
#define HAL_RCC_APB1LPENR_TIM7LPEN 5    /**< TIM7 clock enable during Sleep mode*/
#define HAL_RCC_APB1LPENR_TIM6LPEN 4    /**< TIM6 clock enable during Sleep mode*/
#define HAL_RCC_APB1LPENR_TIM5LPEN 3    /**< TIM5 clock enable during Sleep mode*/
#define HAL_RCC_APB1LPENR_TIM4LPEN 2    /**< TIM4 clock enable during Sleep mode*/
#define HAL_RCC_APB1LPENR_TIM3LPEN 1    /**< TIM3 clock enable during Sleep mode*/
#define HAL_RCC_APB1LPENR_TIM2LPEN 0    /**< TIM2 clock enable during Sleep mode*/

/**
 * @brief: bit definitions for RCC APB2 peripheral clock enabled in low power mode (RCC_APB2LPENR), Reset value: 0x0007 5F33.
 */
#define HAL_RCC_APB2LPENR_TIM11LPEN 18  /**< TIM11 clock enable during Sleep mode. Set and cleared by software.*/
#define HAL_RCC_APB2LPENR_TIM10LPEN 17  /**< TIM10 clock enable during Sleep mode. Set and cleared by software*/
#define HAL_RCC_APB2LPENR_TIM9LPEN 16   /**< TIM9 clock enable during Sleep mode. Set and cleared by software*/
#define HAL_RCC_APB2LPENR_SYSCFGLPEN 14 /**< System configuration controller clock enable during Sleep mode. Set and cleared by software.*/
#define HAL_RCC_APB2LPENR_SPI1LPEN 12   /**< SPI1 clock enable during Sleep mode. Set and cleared by software.*/
#define HAL_RCC_APB2LPENR_SDIOLPEN 11   /**< SDIO clock enable during Sleep mode. Set and cleared by software.*/
#define HAL_RCC_APB2LPENR_ADC3LPEN 10   /**< ADC 3 clock enable during Sleep mode. Set and cleared by software.*/
#define HAL_RCC_APB2LPENR_ADC2LPEN 9    /**< ADC 2 clock enable during Sleep mode. Set and cleared by software.*/
#define HAL_RCC_APB2LPENR_ADC1LPEN 8    /**< ADC 1 clock enable during Sleep mode. Set and cleared by software.*/
#define HAL_RCC_APB2LPENR_USART6LPEN 5  /**< USART6 clock enable during Sleep mode. Set and cleared by software.*/
#define HAL_RCC_APB2LPENR_USART1LPEN 4  /**< USART1 clock enable during Sleep mode. Set and cleared by software.*/
#define HAL_RCC_APB2LPENR_TIM8LPEN 1    /**< TIM8 clock enable during Sleep mode. Set and cleared by software.*/
#define HAL_RCC_APB2LPENR_TIM1LPEN 0    /**< TIM1 clock enable during Sleep mode. Set and cleared by software.*/

/**
 * @brief: bit definitions for RCC Backup domain control register (RCC_BDCR), Reset value: 0x0000 0000.
 */
#define HAL_RCC_BDCR_BDRST 16 /**< Backup domain software reset. Set and cleared by software. Note: The BKPSRAM is not affected by this reset, the only way of resetting the BKPSRAM is through the Flash interface when a protection level change from level 1 to level 0 is   requested.*/
#define HAL_RCC_BDCR_RTCEN 15 /**< RTC clock enable. Set and cleared by software.*/
#define HAL_RCC_BDCR_RTCSEL 8 /**< RTC clock source selection. Set by software to select the clock source for the RTC. Once the RTC clock source has been selected, it cannot be changed anymore unless the Backup domain is reset. The BDRST bit can be used to reset them.*/
#define HAL_RCC_BDCR_LSEBYP 2 /**< External low-speed oscillator bypass. Set and cleared by software to bypass the oscillator. This bit can be written only when the LSE clock is disabled.*/
#define HAL_RCC_BDCR_LSERDY 1 /**< External low-speed oscillator ready. Set and cleared by hardware to indicate when the external 32 kHz oscillator is stable. After the LSEON bit is cleared, LSERDY goes low after 6 external low-speed oscillator clock cycles.*/
#define HAL_RCC_BDCR_BDRST 0  /**< External low-speed oscillator enable. Set and cleared by software.*/

/**
 * @brief: bit definitions for RCC clock control & status register (RCC_CSR), Reset value: 0x0E00 0000.
 */
#define HAL_RCC_CSR_LPWRRSTF 31 /**< Low-power reset flag. Set by hardware when a Low-power management reset occurs. Cleared by writing to the RMVF bit.*/
#define HAL_RCC_CSR_WWDGRSTF 30 /**< Window watchdog reset flag. Set by hardware when a window watchdog reset occurs. Cleared by writing to the RMVF bit.*/
#define HAL_RCC_CSR_IWDGRSTF 29 /**< Independent watchdog reset flag. Set by hardware when an independent watchdog reset from VDD domain occurs. Cleared by writing to the RMVF bit.*/
#define HAL_RCC_CSR_SFTRSTF 28  /**< Software reset flag. Set by hardware when a software reset occurs. Cleared by writing to the RMVF bit.*/
#define HAL_RCC_CSR_PORRSTF 27  /**< POR/PDR reset flag. Set by hardware when a POR/PDR reset occurs. Cleared by writing to the RMVF bit.*/
#define HAL_RCC_CSR_PINRSTF 26  /**< PIN reset flag. Set by hardware when a reset from the NRST pin occurs. Cleared by writing to the RMVF bit.*/
#define HAL_RCC_CSR_BORRSTF 25  /**< BOR reset flag. Cleared by software by writing the RMVF bit. Cleared by software by writing the RMVF bit.*/
#define HAL_RCC_CSR_RMVF 24     /**< Remove reset flag. Set by software to clear the reset flags.*/
#define HAL_RCC_CSR_LSIRDY 1    /**< Internal low-speed oscillator ready. Set and cleared by hardware to indicate when the internal RC 40 kHz oscillator is stable.  After the LSION bit is cleared, LSIRDY goes low after 3 LSI clock cycles.*/
#define HAL_RCC_CSR_LSION 0     /**< Internal low-speed oscillator enable. Set and cleared by software.*/

/**
 * @brief: bit definitions for RCC spread spectrum clock generation register (RCC_SSCGR), Reset value: 0x0000 0000.
 */
#define HAL_RCC_SSCGR_SSCGEN 31    /**< Spread spectrum modulation enable. Set and cleared by software.*/
#define HAL_RCC_SSCGR_SPREADSEL 30 /**< Spread Select. Set and cleared by software. To write before to set CR[24]=PLLON bit.*/
#define HAL_RCC_SSCGR_INCSTEP 13   /**< Incrementation step. Set and cleared by software. To write before setting CR[24]=PLLON bit. Configuration input for modulation profile amplitude.*/
#define HAL_RCC_SSCGR_MODPER 0     /**< Modulation period. Set and cleared by software. To write before setting CR[24]=PLLON bit. Configuration input for modulation profile period.*/

/**
 * @brief: bit definitions for RCC PLLI2S configuration register (RCC_PLLI2SCFGR), Reset value: 0x2000 3000.
 */
#define HAL_RCC_PLLI2SCFGR_PLLI2SR 28 /**< PLLI2S division factor for I2S clocks. Set and cleared by software to control the I2S clock frequency. These bits should be written  only if the PLLI2S is disabled. The factor must be chosen in accordance with the prescaler values inside the I2S peripherals, to reach 0.3% error when using standard crystals and 0% error with audio crystals.*/
#define HAL_RCC_PLLI2SCFGR_PLLI2SN 6  /**< PLLI2S multiplication factor for VCO. These bits are set and cleared by software to control the multiplication factor of the VCO. These bits can be written only when PLLI2S is disabled. Only half-word and word accesses  are allowed to write these bits.*/

/******************************************************************************
 * Configuration Constants
 *******************************************************************************/

/******************************************************************************
 * Macros
 *******************************************************************************/

/******************************************************************************
 * Typedefs
 *******************************************************************************/

/**
 * @brief: this holds all registers used to configure RCC
 */
typedef struct
{
    __io uint32_t RCC_CR;         /**< RCC clock control register.*/
    __io uint32_t RCC_PLLCFGR;    /**< RCC PLL configuration register. This register is used to configure the PLL clock outputs according to the formulas: 1. f(VCO clock) = f(PLL clock input) × (PLLN / PLLM). 2. f(PLL general clock output) = f(VCO clock) / PLLP. 3. f(USB OTG FS, SDIO, RNG clock output) = f(VCO clock) / PLLQ.*/
    __io uint32_t RCC_CFGR;       /**< RCC clock configuration register. 1 or 2 wait states inserted only if the access occurs during a clock source switch.*/
    __io uint32_t RCC_CIR;        /**< RCC clock interrupt register.*/
    __io uint32_t RCC_AHB1RSTR;   /**< RCC AHB1 peripheral reset register.*/
    __io uint32_t RCC_AHB2RSTR;   /**< RCC AHB2 peripheral reset register.*/
    __io uint32_t RCC_AHB3RSTR;   /**< RCC AHB3 peripheral reset register.*/
    __io uint32_t Reserved1;      /**< Reserved.*/
    __io uint32_t RCC_APB1RSTR;   /**< RCC APB1 peripheral reset register.*/
    __io uint32_t RCC_APB2RSTR;   /**< RCC APB2 peripheral reset register.*/
    __io uint32_t Reserved2[2];   /**< Reserved.*/
    __io uint32_t RCC_AHB1ENR;    /**< RCC AHB1 peripheral clock enable register.*/
    __io uint32_t RCC_AHB2ENR;    /**< RCC AHB2 peripheral clock enable register.*/
    __io uint32_t RCC_AHB3ENR;    /**< RCC AHB3 peripheral clock enable register.*/
    __io uint32_t Reserved3;      /**< Reserved.*/
    __io uint32_t RCC_APB1ENR;    /**< RCC APB1 peripheral clock enable register.*/
    __io uint32_t RCC_APB2ENR;    /**< RCC APB2 peripheral clock enable register.*/
    __io uint32_t Reserved4[2];   /**< Reserved.*/
    __io uint32_t RCC_AHB1LPENR;  /**< RCC AHB1 peripheral clock enable in low power mode register.*/
    __io uint32_t RCC_AHB2LPENR;  /**< RCC AHB2 peripheral clock enable in low power mode register.*/
    __io uint32_t RCC_AHB3LPENR;  /**< RCC AHB3 peripheral clock enable in low power mode register.*/
    __io uint32_t Reserved5;      /**< Reserved.*/
    __io uint32_t RCC_APB1LPENR;  /**< RCC APB1 peripheral clock enable in low power mode register.*/
    __io uint32_t RCC_APB2LPENR;  /**< RCC APB2 peripheral clock enabled in low power mode .*/
    __io uint32_t Reserved6[2];   /**< Reserved.*/
    __io uint32_t RCC_BDCR;       /**< RCC Backup domain control register. */
    __io uint32_t RCC_CSR;        /**< RCC clock control & status register.*/
    __io uint32_t Reserved7[2];   /**< Reserved.*/
    __io uint32_t RCC_SSCGR;      /**< RCC spread spectrum clock generation register. The spread spectrum clock generation is available only for the main PLL. The RCC_SSCGR register must be written either before the main PLL is enabled or after the main PLL disabled.*/
    __io uint32_t RCC_PLLI2SCFGR; /**< RCC PLLI2S configuration register. This register is used to configure the PLLI2S clock outputs according to the formulas: 1. f(VCO clock) = f(PLLI2S clock input) × (PLLI2SN / PLLM). 2. f(PLL I2S clock output) = f(VCO clock) / PLLI2SR. */
} HAL_RCC_RegDef_t;

/******************************************************************************
 * Variables
 *******************************************************************************/
static __io HAL_RCC_RegDef_t *global_pRCCReg_t = ((HAL_RCC_RegDef_t *)(HAL_CM4F_AHB1_BASEADDR + HAL_RCC_OFFSET)); /**< this is a pointer variable through which we will access our RCC registers to configure them*/

/******************************************************************************
 * Function Prototypes
 *******************************************************************************/

/*** End of File **************************************************************/
#endif /*HAL_RCC_REG_H_*/