/**
 * --------------------------------------------------------------------------------------------------------------------------------------
 * |    @title          :   System Configuration Controller                                                                             |
 * |    @file           :   SYSCFG_reg.h                                                                                                |
 * |    @author         :   Abdelrahman Mohamed Salem                                                                                   |
 * |    @origin_date    :   04/09/2023                                                                                                  |
 * |    @version        :   1.0.0                                                                                                       |
 * |    @tool_chain     :   GNU Tools for STM32                                                                                         |
 * |    @compiler       :   GCC                                                                                                         |
 * |    @C_standard     :   ISO C99 (-std=c99)                                                                                          |
 * |    @target         :   stm32f407VGTX                                                                                               |
 * |    @notes          :   None                                                                                                        |
 * |    @license        :   MIT License                                                                                                 |
 * |    @brief          :   this file contains registers addresses and definitions structs that deals with SYSCFG registers             |
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
 * |    04/09/2023      1.0.0           Abdelrahman Mohamed Salem       Interface Created.                                              |
 * --------------------------------------------------------------------------------------------------------------------------------------
 */

#ifndef HAL_SYSCFG_REG_H_
#define HAL_SYSCFG_REG_H_

/******************************************************************************
 * Includes
 *******************************************************************************/
/**
 * @reason: contains standard definitions for the integer variables
 */
#include "../../lib/stdint.h"

/**
 * @reason: contains useful math bit level functions
 */
#include "../../lib/math_btt.h"

/**
 * @reason: contains base addresses of APB2 bus
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
 * @brief: this is the base address of SYSCFG registers used to configure some of the SYSCFG behaviors
 * @note: it will be referred to as @HAL_SYSCFG_BASE_ADDR
 */
#define HAL_SYSCFG_OFFSET 0x00003800 /**< this is the offset of the SYSCFGA register from APB2 bus base address*/

/**
 * @brief: bit definitions for SYSCFG memory remap register (SYSCFG_MEMRMP)
 */
#define HAL_SYSCFG_MEMRMP_MEM_MODE 0 /**< Memory mapping selection. Set and cleared by software. This bit controls the memory internal mapping at address 0x0000 0000. After reset these bits take the value selected by the Boot pins (except for FSMC).*/

/**
 * @brief: bit definitions for SYSCFG peripheral mode configuration register (SYSCFG_PMC)
 */
#define HAL_SYSCFG_PMC_MII_RMII_SEL 23 /**< Ethernet PHY interface selection. Set and Cleared by software.These bits control the PHY interface for the Ethernet MAC..*/

/**
 * @brief: bit definitions for Compensation cell control register (SYSCFG_CMPCR)
 */
#define HAL_SYSCFG_CMPCR_READY 8 /**< Compensation cell ready flag.*/
#define HAL_SYSCFG_CMP_PD 0      /**< Compensation cell power-down.*/

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
 * @brief: this holds all registers used to configure SYSCFG
 */
typedef struct
{
    __io uint32_t SYSCFG_MEMRMP;    /**< SYSCFG memory remap register. This register is used for specific configurations on memory remap. Two bits are used to configure the type of memory accessible at address 0x0000 0000. After reset these bits take the value selected by the BOOT pins.*/
    __io uint32_t SYSCFG_PMC;       /**< SYSCFG peripheral mode configuration register.*/
    __io uint32_t SYSCFG_EXTICR[4]; /**< SYSCFG external interrupt configuration register. */
    __io uint32_t Reserved[2];      /**< Reserved. */
    __io uint32_t SYSCFG_CMPCR;     /**< Compensation cell control register.*/
} HAL_SYSCFG_RegDef_t;

static __io HAL_SYSCFG_RegDef_t *const global_pSYSCFGReg_t = ((HAL_SYSCFG_RegDef_t *)(HAL_CM4F_APB2_BASEADDR + HAL_SYSCFG_OFFSET)); /**< this is a pointer variable through which we will access our SYSCFG registers to configure them*/

/******************************************************************************
 * Variables
 *******************************************************************************/

/******************************************************************************
 * Function Prototypes
 *******************************************************************************/

/******************************************************************************
 * Interface for peripherals in same level
 *******************************************************************************/

/**
 * @brief: used to enable compensation cell in case of fast speeds of GPIO are used
 */
#define HAL_SYSCFG_ENABLE_COMPEN_CELL()                                                     \
    LIB_MATH_BTT_SET_BIT(global_pGPIOAReg_t->SYSCFG_CMPCR, HAL_SYSCFG_CMP_PD);              \
    while (!LIB_MATH_BTT_GET_BIT(global_pGPIOAReg_t->SYSCFG_CMPCR, HAL_SYSCFG_CMPCR_READY)) \
        ;

#define HAL_SYSCFG_ETH_MII 0      /**< type of ethernet PHY interface is MII*/
#define HAL_SYSCFG_ETH_RMII_PHY 1 /**< type of ethernet PHY interface is RMII*/
/**
 * @brief: used to select Ethernet PHY interface
 * @param Value: possible values are HAL_SYSCFG_ETH_MII and HAL_SYSCFG_ETH_RMII_PHY
 */
#define HAL_SYSCFG_ETH_PHY_TYPE(Value)  \   
    LIB_MATH_BTT_ASSIGN_BIT(global_pGPIOAReg_t->SYSCFG_PMC, HAL_SYSCFG_PMC_MII_RMII_SEL, Value)

/**
 * @brief: used to assign a specific EXTI line to a port number
 * @param arg_u8EXTILine : a number from 0 to 15 expressing which EXTI line
 * @param argConst_u8PortName : a number from 0 to 8 expressing which PORT to assign to where 0 is PORTA and 1 is PORTB and so on.
 */
void HAL_SYSCFG_voidAssignEXTILine(const uint8_t argConst_u8EXTILine, const uint8 argConst_u8PortName);

/*** End of File **************************************************************/
#endif /*HAL_SYSCFG_REG_H_*/
