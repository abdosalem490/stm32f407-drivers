/**
 * --------------------------------------------------------------------------------------------------------------------------------------
 * |    @title          :   General Purpose Input/Output                                                                                |
 * |    @file           :   GPIO_reg.h                                                                                                  |
 * |    @author         :   Abdelrahman Mohamed Salem                                                                                   |
 * |    @origin_date    :   01/09/2023                                                                                                  |
 * |    @version        :   1.0.0                                                                                                       |
 * |    @tool_chain     :   GNU Tools for STM32                                                                                         |
 * |    @compiler       :   GCC                                                                                                         |
 * |    @C_standard     :   ISO C99 (-std=c99)                                                                                          |
 * |    @target         :   stm32f407VGTX                                                                                               |
 * |    @notes          :   None                                                                                                        |
 * |    @license        :   MIT License                                                                                                 |
 * |    @brief          :   this file contains registers addresses and definitions structs that deals with GPIO registers                |
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

#ifndef HAL_GPIO_REG_H_
#define HAL_GPIO_REG_H_

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
 * @brief: this is the base address of GPIO registers used to configure some of the GPIO behaviors
 * @note: it will be referred to as @HAL_GPIO_BASE_ADDR
 */
#define HAL_GPIOA_OFFSET 0x00000000 /**< this is the offset of the GPIOA register from AHB1 bus base address*/
#define HAL_GPIOB_OFFSET 0x00000400 /**< this is the offset of the GPIOB register from AHB1 bus base address*/
#define HAL_GPIOC_OFFSET 0x00000800 /**< this is the offset of the GPIOC register from AHB1 bus base address*/
#define HAL_GPIOD_OFFSET 0x00000C00 /**< this is the offset of the GPIOD register from AHB1 bus base address*/
#define HAL_GPIOE_OFFSET 0x00001000 /**< this is the offset of the GPIOE register from AHB1 bus base address*/
#define HAL_GPIOF_OFFSET 0x00001400 /**< this is the offset of the GPIOF register from AHB1 bus base address*/
#define HAL_GPIOG_OFFSET 0x00001800 /**< this is the offset of the GPIOG register from AHB1 bus base address*/
#define HAL_GPIOH_OFFSET 0x00001C00 /**< this is the offset of the GPIOH register from AHB1 bus base address*/
#define HAL_GPIOI_OFFSET 0x00002000 /**< this is the offset of the GPIOI register from AHB1 bus base address*/
#define HAL_GPIOJ_OFFSET 0x00002400 /**< this is the offset of the GPIOJ register from AHB1 bus base address*/
#define HAL_GPIOK_OFFSET 0x00002800 /**< this is the offset of the GPIOK register from AHB1 bus base address*/

/**
 * @brief: bit definitions for GPIO port configuration lock register (GPIOx_LCKR)
 */
#define HAL_GPIOx_LCKR_LCKK 16 /**< Lock key. This bit can be read any time. It can only be modified using the lock key write sequence.*/

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
 * @brief: this holds all registers used to configure GPIO
 */
typedef struct
{
    __io uint32_t GPIOx_MODER;   /**< GPIO port mode register.*/
    __io uint32_t GPIOx_OTYPER;  /**< GPIO port output type register.*/
    __io uint32_t GPIOx_OSPEEDR; /**< GPIO port output speed register.*/
    __io uint32_t GPIOx_PUPDR;   /**< GPIO port pull-up/pull-down register.*/
    __io uint32_t GPIOx_IDR;     /**< GPIO port input data register.*/
    __io uint32_t GPIOx_ODR;     /**< GPIO port output data register.*/
    __io uint32_t GPIOx_BSRR;    /**< GPIO port bit set/reset register.*/
    __io uint32_t GPIOx_LCKR;    /**< GPIO port configuration lock register.*/
    __io uint32_t GPIOx_AFRL;    /**< GPIO alternate function low register.*/
    __io uint32_t GPIOx_AFRH;    /**< GPIO alternate function high register.*/
} HAL_GPIO_RegDef_t;

/******************************************************************************
 * Variables
 *******************************************************************************/
static __io HAL_GPIO_RegDef_t *global_pGPIOAReg_t = ((HAL_GPIO_RegDef_t *)(HAL_CM4F_AHB1_BASEADDR + HAL_GPIOA_OFFSET)); /**< this is a pointer variable through which we will access our GPIOA registers to configure them*/
static __io HAL_GPIO_RegDef_t *global_pGPIOBReg_t = ((HAL_GPIO_RegDef_t *)(HAL_CM4F_AHB1_BASEADDR + HAL_GPIOB_OFFSET)); /**< this is a pointer variable through which we will access our GPIOB registers to configure them*/
static __io HAL_GPIO_RegDef_t *global_pGPIOCReg_t = ((HAL_GPIO_RegDef_t *)(HAL_CM4F_AHB1_BASEADDR + HAL_GPIOC_OFFSET)); /**< this is a pointer variable through which we will access our GPIOC registers to configure them*/
static __io HAL_GPIO_RegDef_t *global_pGPIODReg_t = ((HAL_GPIO_RegDef_t *)(HAL_CM4F_AHB1_BASEADDR + HAL_GPIOD_OFFSET)); /**< this is a pointer variable through which we will access our GPIOD registers to configure them*/
static __io HAL_GPIO_RegDef_t *global_pGPIOEReg_t = ((HAL_GPIO_RegDef_t *)(HAL_CM4F_AHB1_BASEADDR + HAL_GPIOE_OFFSET)); /**< this is a pointer variable through which we will access our GPIOE registers to configure them*/
static __io HAL_GPIO_RegDef_t *global_pGPIOFReg_t = ((HAL_GPIO_RegDef_t *)(HAL_CM4F_AHB1_BASEADDR + HAL_GPIOF_OFFSET)); /**< this is a pointer variable through which we will access our GPIOF registers to configure them*/
static __io HAL_GPIO_RegDef_t *global_pGPIOGReg_t = ((HAL_GPIO_RegDef_t *)(HAL_CM4F_AHB1_BASEADDR + HAL_GPIOG_OFFSET)); /**< this is a pointer variable through which we will access our GPIOG registers to configure them*/
static __io HAL_GPIO_RegDef_t *global_pGPIOHReg_t = ((HAL_GPIO_RegDef_t *)(HAL_CM4F_AHB1_BASEADDR + HAL_GPIOH_OFFSET)); /**< this is a pointer variable through which we will access our GPIOH registers to configure them*/
static __io HAL_GPIO_RegDef_t *global_pGPIOIReg_t = ((HAL_GPIO_RegDef_t *)(HAL_CM4F_AHB1_BASEADDR + HAL_GPIOI_OFFSET)); /**< this is a pointer variable through which we will access our GPIOI registers to configure them*/
static __io HAL_GPIO_RegDef_t *global_pGPIOJReg_t = ((HAL_GPIO_RegDef_t *)(HAL_CM4F_AHB1_BASEADDR + HAL_GPIOJ_OFFSET)); /**< this is a pointer variable through which we will access our GPIOJ registers to configure them*/
static __io HAL_GPIO_RegDef_t *global_pGPIOKReg_t = ((HAL_GPIO_RegDef_t *)(HAL_CM4F_AHB1_BASEADDR + HAL_GPIOK_OFFSET)); /**< this is a pointer variable through which we will access our GPIOK registers to configure them*/

/******************************************************************************
 * Function Prototypes
 *******************************************************************************/

/*** End of File **************************************************************/
#endif /*HAL_GPIO_REG_H_*/