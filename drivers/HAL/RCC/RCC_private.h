/**
 * --------------------------------------------------------------------------------------------------------------------------------------
 * |    @title          :   Reset and clock control                                                                                     |
 * |    @file           :   RCC_private.h                                                                                               |
 * |    @author         :   Abdelrahman Mohamed Salem                                                                                   |
 * |    @origin_date    :   16/08/2023                                                                                                  |
 * |    @version        :   1.0.0                                                                                                       |
 * |    @tool_chain     :   GNU Tools for STM32                                                                                         |
 * |    @compiler       :   GCC                                                                                                         |
 * |    @C_standard     :   ISO C99 (-std=c99)                                                                                          |
 * |    @target         :   stm32f407VGTX                                                                                               |
 * |    @notes          :   None                                                                                                        |
 * |    @license        :   MIT License                                                                                                 |
 * |    @brief          :   this header file contains private functions and variables for the Reset and clock control (RCC)             |                                                               |
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

#ifndef HAL_RCC_PRIVATE_H_
#define HAL_RCC_PRIVATE_H_

/******************************************************************************
 * Includes
 *******************************************************************************/
/**
 * @reason: contains definition for function callback
 */
#include "../../lib/common.h"

/**
 * @reason: contains definitions for standard integers
 */
#include "../../lib/stdint.h"

/**
 * @reason: contains all math bits functions
 */
#include "../../lib/math_btt.h"

/**
 * @reason: contains all register definitions for RCC
 */
#include "RCC_reg.h"

/******************************************************************************
 * Preprocessor Constants
 *******************************************************************************/

/******************************************************************************
 * Configuration Constants
 *******************************************************************************/

/******************************************************************************
 * Macros
 *******************************************************************************/

/**
 * @brief: these are the speeds of internal clocks
 */
#define HAL_RCC_LSI_SPEED 32000         /**< 32 KHZ*/
#define HAL_RCC_LSE_SPEED 32768         /**< 32.768 kHz*/
#define HAL_RCC_HSI_SPEED 16000000      /**< 16 MHZ*/
#define HAL_RCC_PLL48CLK_SPEED 48000000 /**< 48 MHZ*/

/**
 * @brief maximum/minimum frequencies allowed on a bus
 */
#define HAL_RCC_VCO_MIN_SPEED 100000000    /**< 100 MHZ*/
#define HAL_RCC_VCO_MAX_SPEED 432000000    /**< 432 MHZ*/
#define HAL_RCC_SYSCLK_MAX_SPEED 168000000 /**< 168 MHZ*/

/**
 * @brief: USB OTG module RCC utilities
 */
#define HAL_RCC_RST_OTGHSRST()  \ 
    LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_AHB1RSTR, HAL_RCC_AHB1RSTR_OTGHSRST)

#define HAL_RCC_RST_OTGFSRST()  \ 
    LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_AHB2RSTR, HAL_RCC_AHB2RSTR_OTGFSRST)

#define HAL_RCC_EN_OTGHSULPIEN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_AHB1ENR, HAL_RCC_AHB1ENR_OTGHSULPIEN)

#define HAL_RCC_EN_OTGHSEN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_AHB1ENR, HAL_RCC_AHB1ENR_OTGHSEN)

#define HAL_RCC_EN_OTGFSEN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_AHB2ENR, HAL_RCC_AHB2ENR_OTGFSEN)

#define HAL_RCC_LOW_PWR_OTGHSULPILPEN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_AHB1LPENR, HAL_RCC_AHB1LPENR_OTGHSULPILPEN)

#define HAL_RCC_LOW_PWR_OTGHSLPEN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_AHB1LPENR, HAL_RCC_AHB1LPENR_OTGHSLPEN)

#define HAL_RCC_LOW_PWR_OTGFSLPEN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_AHB2LPENR, HAL_RCC_AHB2LPENR_OTGFSLPEN)

/**
 * @brief: Ethernet MAC module RCC utilities
 */
#define HAL_RCC_RST_ETHMACRST()  \ 
    LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_AHB1RSTR, HAL_RCC_AHB1RSTR_ETHMACRST)

#define HAL_RCC_EN_ETHMACPTPEN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_AHB1ENR, HAL_RCC_AHB1ENR_ETHMACPTPEN)

#define HAL_RCC_EN_ETHMACRXEN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_AHB1ENR, HAL_RCC_AHB1ENR_ETHMACRXEN)

#define HAL_RCC_EN_ETHMACTXEN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_AHB1ENR, HAL_RCC_AHB1ENR_ETHMACTXEN)

#define HAL_RCC_EN_ETHMACEN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_AHB1ENR, HAL_RCC_AHB1ENR_ETHMACEN)

#define HAL_RCC_LOW_PWR_ETHMACPTPLPEN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_AHB1LPENR, HAL_RCC_AHB1LPENR_OTGHSLPEN)

#define HAL_RCC_LOW_PWR_ETHMACRXLPEN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_AHB1LPENR, HAL_RCC_AHB1LPENR_OTGHSLPEN)

#define HAL_RCC_LOW_PWR_ETHMACTXLPEN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_AHB1LPENR, HAL_RCC_AHB1LPENR_OTGHSLPEN)

#define HAL_RCC_LOW_PWR_ETHMACLPEN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_AHB1LPENR, HAL_RCC_AHB1LPENR_OTGHSLPEN)

/**
 * @brief: DMA module RCC utilities
 */
#define HAL_RCC_RST_DMA2RST()  \ 
    LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_AHB1RSTR, HAL_RCC_AHB1RSTR_DMA2RST)

#define HAL_RCC_RST_DMA1RST()  \ 
    LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_AHB1RSTR, HAL_RCC_AHB1RSTR_DMA1RST)

#define HAL_RCC_EN_DMA2EN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_AHB1ENR, HAL_RCC_AHB1ENR_DMA2EN)

#define HAL_RCC_EN_DMA1EN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_AHB1ENR, HAL_RCC_AHB1ENR_DMA1EN)

#define HAL_RCC_LOW_PWR_DMA2LPEN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_AHB1LPENR, HAL_RCC_AHB1LPENR_DMA2LPEN)

#define HAL_RCC_LOW_PWR_DMA1LPEN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_AHB1LPENR, HAL_RCC_AHB1LPENR_DMA1LPEN)

/**
 * @brief:  CCM data RAM module RCC utilities
 */
#define HAL_RCC_EN_CCMDATARAMEN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_AHB1ENR, HAL_RCC_AHB1ENR_CCMDATARAMEN)

/**
 * @brief:  Backup SRAM interface module RCC utilities
 */
#define HAL_RCC_EN_BKPSRAMEN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_AHB1ENR, HAL_RCC_AHB1ENR_BKPSRAMEN)

#define HAL_RCC_LOW_PWR_BKPSRAMLPEN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_AHB1LPENR, HAL_RCC_AHB1LPENR_BKPSRAMLPEN)

/**
 * @brief:  SRAM interface module RCC utilities
 */
#define HAL_RCC_LOW_PWR_SRAM2LPEN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_AHB1LPENR, HAL_RCC_AHB1LPENR_SRAM2LPEN)

#define HAL_RCC_LOW_PWR_SRAM1LPEN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_AHB1LPENR, HAL_RCC_AHB1LPENR_SRAM1LPEN)

/**
 * @brief: CRC module RCC utilities
 */
#define HAL_RCC_RST_CRCRST()  \ 
    LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_AHB1RSTR, HAL_RCC_AHB1RSTR_CRCRST)

#define HAL_RCC_EN_CRCEN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_AHB1ENR, HAL_RCC_AHB1ENR_CRCEN)

#define HAL_RCC_LOW_PWR_CRCLPEN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_AHB1LPENR, HAL_RCC_AHB1LPENR_CRCLPEN)

/**
 * @brief: IO port module RCC utilities
 */
#define HAL_RCC_RST_GPIOIRST()  \ 
    LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_AHB1RSTR, HAL_RCC_AHB1RSTR_GPIOIRST)

#define HAL_RCC_RST_GPIOHRST()  \ 
    LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_AHB1RSTR, HAL_RCC_AHB1RSTR_GPIOHRST)

#define HAL_RCC_RST_GPIOGRST()  \ 
    LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_AHB1RSTR, HAL_RCC_AHB1RSTR_GPIOGRST)

#define HAL_RCC_RST_GPIOFRST()  \ 
    LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_AHB1RSTR, HAL_RCC_AHB1RSTR_GPIOFRST)

#define HAL_RCC_RST_GPIOERST()  \ 
    LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_AHB1RSTR, HAL_RCC_AHB1RSTR_GPIOERST)

#define HAL_RCC_RST_GPIODRST()  \ 
    LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_AHB1RSTR, HAL_RCC_AHB1RSTR_GPIODRST)

#define HAL_RCC_RST_GPIOCRST()  \ 
    LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_AHB1RSTR, HAL_RCC_AHB1RSTR_GPIOCRST)

#define HAL_RCC_RST_GPIOBRST()  \ 
    LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_AHB1RSTR, HAL_RCC_AHB1RSTR_GPIOBRST)

#define HAL_RCC_RST_GPIOARST()  \ 
    LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_AHB1RSTR, HAL_RCC_AHB1RSTR_GPIOARST)

#define HAL_RCC_EN_GPIOIEN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_AHB1ENR, HAL_RCC_AHB1ENR_GPIOIEN)

#define HAL_RCC_EN_GPIOHEN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_AHB1ENR, HAL_RCC_AHB1ENR_GPIOHEN)

#define HAL_RCC_EN_GPIOGEN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_AHB1ENR, HAL_RCC_AHB1ENR_GPIOGEN)

#define HAL_RCC_EN_GPIOFEN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_AHB1ENR, HAL_RCC_AHB1ENR_GPIOFEN)

#define HAL_RCC_EN_GPIOEEN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_AHB1ENR, HAL_RCC_AHB1ENR_GPIOEEN)

#define HAL_RCC_EN_GPIOFEN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_AHB1ENR, HAL_RCC_AHB1ENR_GPIODEN)

#define HAL_RCC_EN_GPIOCEN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_AHB1ENR, HAL_RCC_AHB1ENR_GPIOCEN)

#define HAL_RCC_EN_GPIOBEN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_AHB1ENR, HAL_RCC_AHB1ENR_GPIOBEN)

#define HAL_RCC_EN_GPIOAEN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_AHB1ENR, HAL_RCC_AHB1ENR_GPIOAEN)

#define HAL_RCC_LOW_PWR_GPIOILPEN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_AHB1LPENR, HAL_RCC_AHB1LPENR_GPIOILPEN)

#define HAL_RCC_LOW_PWR_GPIOHLPEN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_AHB1LPENR, HAL_RCC_AHB1LPENR_GPIOHLPEN)

#define HAL_RCC_LOW_PWR_GPIOGLPEN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_AHB1LPENR, HAL_RCC_AHB1LPENR_GPIOGLPEN)

#define HAL_RCC_LOW_PWR_GPIOFLPEN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_AHB1LPENR, HAL_RCC_AHB1LPENR_GPIOFLPEN)

#define HAL_RCC_LOW_PWR_GPIOELPEN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_AHB1LPENR, HAL_RCC_AHB1LPENR_GPIOELPEN)

#define HAL_RCC_LOW_PWR_GPIODLPEN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_AHB1LPENR, HAL_RCC_AHB1LPENR_GPIODLPEN)

#define HAL_RCC_LOW_PWR_GPIOCLPEN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_AHB1LPENR, HAL_RCC_AHB1LPENR_GPIOCLPEN)

#define HAL_RCC_LOW_PWR_GPIOBLPEN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_AHB1LPENR, HAL_RCC_AHB1LPENR_GPIOBLPEN)

#define HAL_RCC_LOW_PWR_GPIOALPEN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_AHB1LPENR, HAL_RCC_AHB1LPENR_GPIOALPEN)

/**
 * @brief: Random number generator module RCC utilities
 */
#define HAL_RCC_RST_RNGRST()  \ 
    LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_AHB2RSTR, HAL_RCC_AHB2RSTR_RNGRST)

#define HAL_RCC_EN_RNGEN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_AHB2ENR, HAL_RCC_AHB2ENR_RNGEN)

#define HAL_RCC_LOW_PWR_RNGLPEN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_AHB2LPENR, HAL_RCC_AHB2LPENR_RNGLPEN)

/**
 * @brief: Hash module RCC utilities
 */
#define HAL_RCC_RST_HASHRST()  \ 
    LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_AHB2RSTR, HAL_RCC_AHB2RSTR_HASHRST)

#define HAL_RCC_EN_HASHEN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_AHB2ENR, HAL_RCC_AHB2ENR_HASHEN)

#define HAL_RCC_LOW_PWR_HASHLPEN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_AHB2LPENR, HAL_RCC_AHB2LPENR_HASHLPEN)

/**
 * @brief: Cryptographic module RCC utilities
 */
#define HAL_RCC_RST_CRYPRST()  \ 
    LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_AHB2RSTR, HAL_RCC_AHB2RSTR_CRYPRST)

#define HAL_RCC_EN_CRYPEN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_AHB2ENR, HAL_RCC_AHB2ENR_CRYPEN)

#define HAL_RCC_LOW_PWR_CRYPLPEN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_AHB2LPENR, HAL_RCC_AHB2LPENR_CRYPLPEN)

/**
 * @brief: Camera interface module RCC utilities
 */
#define HAL_RCC_RST_DCMIRST()  \ 
    LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_AHB2RSTR, HAL_RCC_AHB2RSTR_DCMIRST)

#define HAL_RCC_EN_DCMIEN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_AHB2ENR, HAL_RCC_AHB2ENR_DCMIEN)

#define HAL_RCC_LOW_PWR_DCMILPEN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_AHB2LPENR, HAL_RCC_AHB2LPENR_DCMILPEN)

/**
 * @brief: Flexible static memory controller module RCC utilities
 */
#define HAL_RCC_RST_FSMCRST()  \ 
    LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_AHB3RSTR, HAL_RCC_AHB3RSTR_FSMCRST)

#define HAL_RCC_EN_FSMCEN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_AHB3ENR, HAL_RCC_AHB3ENR_FSMCEN)

#define HAL_RCC_LOW_PWR_FSMCLPEN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_AHB3LPENR, HAL_RCC_AHB3LPENR_FSMCLPEN)

/**
 * @brief: DAC module RCC utilities
 */
#define HAL_RCC_RST_DACRST()  \ 
    LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB1RSTR, HAL_RCC_APB1RSTR_DACRST)

#define HAL_RCC_EN_DACEN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_APB1ENR, HAL_RCC_APB1ENR_DACEN)

#define HAL_RCC_LOW_PWR_DACLPEN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_APB1LPENR, HAL_RCC_RCC_APB1LPENR_DACLPEN)

/**
 * @brief: Power interface RCC utilities
 */
#define HAL_RCC_RST_PWRRST()  \ 
    LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB1RSTR, HAL_RCC_APB1RSTR_PWRRST)

#define HAL_RCC_EN_PWREN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_APB1ENR, HAL_RCC_APB1ENR_PWREN)

#define HAL_RCC_LOW_PWR_PWRLPEN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_APB1LPENR, HAL_RCC_APB1LPENR_PWRLPEN)

/**
 * @brief: CAN module RCC utilities
 */
#define HAL_RCC_RST_CAN2RST()  \ 
    LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB1RSTR, HAL_RCC_APB1RSTR_CAN2RST)

#define HAL_RCC_RST_CAN2RST()  \ 
    LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB1RSTR, HAL_RCC_APB1RSTR_CAN1RST)

#define HAL_RCC_EN_CAN2EN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_APB1ENR, HAL_RCC_APB1ENR_CAN2EN)

#define HAL_RCC_EN_CAN1EN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_APB1ENR, HAL_RCC_APB1ENR_CAN1EN)

#define HAL_RCC_LOW_PWR_CAN2LPEN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_APB1LPENR, HAL_RCC_APB1LPENR_CAN2LPEN)

#define HAL_RCC_LOW_PWR_CAN1LPEN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_APB1LPENR, HAL_RCC_APB1LPENR_CAN1LPEN)

/**
 * @brief: I2C module RCC utilities
 */
#define HAL_RCC_RST_I2C3RST()  \ 
    LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB1RSTR, HAL_RCC_APB1RSTR_I2C3RST)

#define HAL_RCC_RST_I2C2RST()  \ 
    LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB1RSTR, HAL_RCC_APB1RSTR_I2C2RST)

#define HAL_RCC_RST_I2C1RST()  \ 
    LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB1RSTR, HAL_RCC_APB1RSTR_I2C1RST)

#define HAL_RCC_EN_I2C3EN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_APB1ENR, HAL_RCC_APB1ENR_I2C3EN)

#define HAL_RCC_EN_I2C2EN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_APB1ENR, HAL_RCC_APB1ENR_I2C2EN)

#define HAL_RCC_EN_I2C1EN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_APB1ENR, HAL_RCC_APB1ENR_I2C1EN)

#define HAL_RCC_LOW_PWR_I2C3LPEN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_APB1LPENR, HAL_RCC_APB1LPENR_I2C3LPEN)

#define HAL_RCC_LOW_PWR_I2C2LPEN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_APB1LPENR, HAL_RCC_APB1LPENR_I2C2LPEN)

#define HAL_RCC_LOW_PWR_I2C1LPEN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_APB1LPENR, HAL_RCC_APB1LPENR_I2C1LPEN)

/**
 * @brief: UART module RCC utilities
 */
#define HAL_RCC_RST_UART5RST()  \ 
    LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB1RSTR, HAL_RCC_APB1RSTR_UART5RST)

#define HAL_RCC_RST_UART4RST()  \ 
    LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB1RSTR, HAL_RCC_APB1RSTR_UART4RST)

#define HAL_RCC_RST_USART3RST()  \ 
    LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB1RSTR, HAL_RCC_APB1RSTR_USART3RST)

#define HAL_RCC_RST_USART2RST()  \ 
    LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB1RSTR, HAL_RCC_APB1RSTR_USART2RST)

#define HAL_RCC_RST_USART6RST()  \ 
    LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB2RSTR, HAL_RCC_APB2RSTR_USART6RST)

#define HAL_RCC_RST_USART1RST()  \ 
    LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB2RSTR, HAL_RCC_APB2RSTR_USART1RST)

#define HAL_RCC_EN_UART5EN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_APB1ENR, HAL_RCC_APB1ENR_UART5EN)

#define HAL_RCC_EN_UART4EN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_APB1ENR, HAL_RCC_APB1ENR_UART4EN)

#define HAL_RCC_EN_USART3EN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_APB1ENR, HAL_RCC_APB1ENR_USART3EN)

#define HAL_RCC_EN_USART2EN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_APB1ENR, HAL_RCC_APB1ENR_USART2EN)

#define HAL_RCC_EN_USART6EN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_APB2ENR, HAL_RCC_APB2ENR_USART6EN)

#define HAL_RCC_EN_USART1EN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_APB2ENR, HAL_RCC_APB2ENR_USART1EN)

#define HAL_RCC_LOW_PWR_UART5LPEN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_APB1LPENR, HAL_RCC_APB1LPENR_UART5LPEN)

#define HAL_RCC_LOW_PWR_UART4LPEN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_APB1LPENR, HAL_RCC_APB1LPENR_UART4LPEN)

#define HAL_RCC_LOW_PWR_USART3LPEN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_APB1LPENR, HAL_RCC_APB1LPENR_USART3LPEN)

#define HAL_RCC_LOW_PWR_USART2LPEN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_APB1LPENR, HAL_RCC_APB1LPENR_USART2LPEN)

#define HAL_RCC_LOW_PWR_USART6LPEN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_APB2LPENR, HAL_RCC_APB2LPENR_USART6LPEN)

#define HAL_RCC_LOW_PWR_USART1LPEN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_APB2LPENR, HAL_RCC_APB2LPENR_USART1LPEN)

/**
 * @brief: SPI module RCC utilities
 */
#define HAL_RCC_RST_SPI3RST()  \ 
    LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB1RSTR, HAL_RCC_APB1RSTR_SPI3RST)

#define HAL_RCC_RST_SPI2RST()  \ 
    LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB1RSTR, HAL_RCC_APB1RSTR_SPI2RST)

#define HAL_RCC_RST_SPI1RST()  \ 
    LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB2RSTR, HAL_RCC_APB2RSTR_SPI1RST)

#define HAL_RCC_EN_SPI3EN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_APB1ENR, HAL_RCC_APB1ENR_SPI3EN)

#define HAL_RCC_EN_SPI2EN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_APB1ENR, HAL_RCC_APB1ENR_SPI2EN)

#define HAL_RCC_EN_SPI1EN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_APB2ENR, HAL_RCC_APB2ENR_SPI1EN)

#define HAL_RCC_LOW_PWR_SPI3LPEN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_APB1LPENR, HAL_RCC_APB1LPENR_SPI3LPEN)

#define HAL_RCC_LOW_PWR_SPI2LPEN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_APB1LPENR, HAL_RCC_APB1LPENR_SPI2LPEN)

#define HAL_RCC_LOW_PWR_SPI1LPEN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_APB2LPENR, HAL_RCC_APB2LPENR_SPI1LPEN)

/**
 * @brief: Window watchdog module RCC utilities
 */
#define HAL_RCC_EN_WWDGEN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_APB1ENR, HAL_RCC_APB1ENR_WWDGEN)

#define HAL_RCC_LOW_PWR_WWDGLPEN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_APB1LPENR, HAL_RCC_APB1LPENR_WWDGLPEN)

/**
 * @brief: TIM module RCC utilities
 */
#define HAL_RCC_RST_TIM14RST()  \ 
    LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB1RSTR, HAL_RCC_APB1RSTR_TIM14RST)

#define HAL_RCC_RST_TIM13RST()  \ 
    LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB1RSTR, HAL_RCC_APB1RSTR_TIM13RST)

#define HAL_RCC_RST_TIM12RST()  \ 
    LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB1RSTR, HAL_RCC_APB1RSTR_TIM12RST)

#define HAL_RCC_RST_TIM7RST()  \ 
    LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB1RSTR, HAL_RCC_APB1RSTR_TIM7RST)

#define HAL_RCC_RST_TIM6RST()  \ 
    LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB1RSTR, HAL_RCC_APB1RSTR_TIM6RST)

#define HAL_RCC_RST_TIM4RST()  \ 
    LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB1RSTR, HAL_RCC_APB1RSTR_TIM4RST)

#define HAL_RCC_RST_TIM3RST()  \ 
    LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB1RSTR, HAL_RCC_APB1RSTR_TIM3RST)

#define HAL_RCC_RST_TIM2RST()  \ 
    LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB1RSTR, HAL_RCC_APB1RSTR_TIM2RST)

#define HAL_RCC_RST_TIM11RST()  \ 
    LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB2RSTR, HAL_RCC_APB2RSTR_TIM11RST)

#define HAL_RCC_RST_TIM10RST()  \ 
    LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB2RSTR, HAL_RCC_APB2RSTR_TIM10RST)

#define HAL_RCC_RST_TIM9RST()  \ 
    LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB2RSTR, HAL_RCC_APB2RSTR_TIM9RST)

#define HAL_RCC_RST_TIM8RST()  \ 
    LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB2RSTR, HAL_RCC_APB2RSTR_TIM8RST)

#define HAL_RCC_RST_TIM1RST()  \ 
    LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB2RSTR, HAL_RCC_APB2RSTR_TIM1RST)

#define HAL_RCC_EN_TIM14EN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_APB1ENR, HAL_RCC_APB1ENR_TIM14EN)

#define HAL_RCC_EN_TIM13EN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_APB1ENR, HAL_RCC_APB1ENR_TIM13EN)

#define HAL_RCC_EN_TIM12EN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_APB1ENR, HAL_RCC_APB1ENR_TIM12EN)

#define HAL_RCC_EN_TIM7EN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_APB1ENR, HAL_RCC_APB1ENR_TIM7EN)

#define HAL_RCC_EN_TIM6EN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_APB1ENR, HAL_RCC_APB1ENR_TIM6EN)

#define HAL_RCC_EN_TIM5EN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_APB1ENR, HAL_RCC_APB1ENR_TIM5EN)

#define HAL_RCC_EN_TIM4EN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_APB1ENR, HAL_RCC_APB1ENR_TIM4EN)

#define HAL_RCC_EN_TIM3EN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_APB1ENR, HAL_RCC_APB1ENR_TIM3EN)

#define HAL_RCC_EN_TIM2EN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_APB1ENR, HAL_RCC_APB1ENR_TIM2EN)

#define HAL_RCC_EN_TIM11EN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_APB2ENR, HAL_RCC_APB2ENR_TIM11EN)

#define HAL_RCC_EN_TIM10EN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_APB2ENR, HAL_RCC_APB2ENR_TIM10EN)

#define HAL_RCC_EN_TIM9EN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_APB2ENR, HAL_RCC_APB2ENR_TIM9EN)

#define HAL_RCC_EN_TIM8EN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_APB2ENR, HAL_RCC_APB2ENR_TIM8EN)

#define HAL_RCC_EN_TIM1EN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_APB2ENR, HAL_RCC_APB2ENR_TIM1EN)

#define HAL_RCC_LOW_PWR_TIM14LPEN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_APB1LPENR, HAL_RCC_APB1LPENR_TIM14LPEN)

#define HAL_RCC_LOW_PWR_TIM13LPEN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_APB1LPENR, HAL_RCC_APB1LPENR_TIM13LPEN)

#define HAL_RCC_LOW_PWR_TIM12LPEN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_APB1LPENR, HAL_RCC_APB1LPENR_TIM12LPEN)

#define HAL_RCC_LOW_PWR_TIM7LPEN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_APB1LPENR, HAL_RCC_APB1LPENR_TIM7LPEN)

#define HAL_RCC_LOW_PWR_TIM6LPEN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_APB1LPENR, HAL_RCC_APB1LPENR_TIM6LPEN)

#define HAL_RCC_LOW_PWR_TIM5LPEN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_APB1LPENR, HAL_RCC_APB1LPENR_TIM5LPEN)

#define HAL_RCC_LOW_PWR_TIM4LPEN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_APB1LPENR, HAL_RCC_APB1LPENR_TIM4LPEN)

#define HAL_RCC_LOW_PWR_TIM3LPEN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_APB1LPENR, HAL_RCC_APB1LPENR_TIM3LPEN)

#define HAL_RCC_LOW_PWR_TIM2LPEN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_APB1LPENR, HAL_RCC_APB1LPENR_TIM2LPEN)

#define HAL_RCC_LOW_PWR_TIM11LPEN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_APB2LPENR, HAL_RCC_APB2LPENR_TIM11LPEN)

#define HAL_RCC_LOW_PWR_TIM10LPEN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_APB2LPENR, HAL_RCC_APB2LPENR_TIM10LPEN)

#define HAL_RCC_LOW_PWR_TIM9LPEN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_APB2LPENR, HAL_RCC_APB2LPENR_TIM9LPEN)

#define HAL_RCC_LOW_PWR_TIM8LPEN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_APB2LPENR, HAL_RCC_APB2LPENR_TIM8LPEN)

#define HAL_RCC_LOW_PWR_TIM1LPEN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_APB2LPENR, HAL_RCC_APB2LPENR_TIM1LPEN)

/**
 * @brief: System configuration controller module RCC utilities
 */
#define HAL_RCC_RST_SYSCFGRST()  \ 
    LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB2RSTR, HAL_RCC_APB2RSTR_SYSCFGRST)

#define HAL_RCC_EN_SYSCFGEN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_APB2ENR, HAL_RCC_APB2ENR_SYSCFGEN)

#define HAL_RCC_LOW_PWR_SYSCFGLPEN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_APB2LPENR, HAL_RCC_APB2LPENR_SYSCFGLPEN)

/**
 * @brief: SDIO module RCC utilities
 */
#define HAL_RCC_RST_SDIORST()  \ 
    LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB2RSTR, HAL_RCC_APB2RSTR_SDIORST)

#define HAL_RCC_EN_SDIOEN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_APB2ENR, HAL_RCC_APB2ENR_SDIOEN)

#define HAL_RCC_LOW_PWR_SDIOLPEN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_APB2LPENR, HAL_RCC_APB2LPENR_SDIOLPEN)

/**
 * @brief: ADC interface module RCC utilities
 */
#define HAL_RCC_RST_ADCRST()  \ 
    LIB_MATH_BTT_SET_BIT(global_pRCCReg_t->RCC_APB2RSTR, HAL_RCC_APB2RSTR_ADCRST)

#define HAL_RCC_EN_ADC3EN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_APB2ENR, HAL_RCC_APB2ENR_ADC3EN)

#define HAL_RCC_EN_ADC2EN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_APB2ENR, HAL_RCC_APB2ENR_ADC2EN)

#define HAL_RCC_EN_ADC1EN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_APB2ENR, HAL_RCC_APB2ENR_ADC1EN)

#define HAL_RCC_LOW_PWR_ADC3LPEN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_APB2LPENR, HAL_RCC_APB2LPENR_ADC3LPEN)

#define HAL_RCC_LOW_PWR_ADC2LPEN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_APB2LPENR, HAL_RCC_APB2LPENR_ADC2LPEN)

#define HAL_RCC_LOW_PWR_ADC1LPEN(ENABLEMENT_VAL) \
    LIB_MATH_BTT_ASSIGN_BIT(global_pRCCReg_t->RCC_APB2LPENR, HAL_RCC_APB2LPENR_ADC1LPEN)

/******************************************************************************
 * Tables
 *******************************************************************************/

/******************************************************************************
 * Typedefs
 *******************************************************************************/

/******************************************************************************
 * Variables
 *******************************************************************************/

/**
 * @brief: these variables holds the current clock values of the system
 */
static uint32_t global_u32SystemClock = 0;
static uint32_t global_u32HSEtoRTCClk = 0;

/**
 * @brief: these are the function to be called when special event happens
 */
static functionCallBack_t global_pClockUnstableCallBack_t = NULL;

/******************************************************************************
 * Function Prototypes
 *******************************************************************************/

/*** End of File **************************************************************/
#endif /*HAL_RCC_PRIVATE_H_*/