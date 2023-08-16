/**
 * --------------------------------------------------------------------------------------------------------------------------------------
 * |    @title          :   power controller                                                                                            |
 * |    @file           :   PWR_reg.h                                                                                                   |
 * |    @author         :   Abdelrahman Mohamed Salem                                                                                   |
 * |    @origin_date    :   11/08/2023                                                                                                  |
 * |    @version        :   1.0.0                                                                                                       |
 * |    @tool_chain     :   GNU Tools for STM32                                                                                         |
 * |    @compiler       :   GCC                                                                                                         |
 * |    @C_standard     :   ISO C99 (-std=c99)                                                                                          |
 * |    @target         :   stm32f407VGTX                                                                                               |
 * |    @notes          :   None                                                                                                        |
 * |    @license        :   MIT License                                                                                                 |
 * |    @brief          :   this file contains registers addresses and definitions structs that deals with PWR registers                |
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

#ifndef HAL_PWR_REG_H_
#define HAL_PWR_REG_H_

/******************************************************************************
 * Includes
 *******************************************************************************/
/**
 * @reason: contains standard definitions for the integer variables
 */
#include "../../lib/stdint.h"

/**
 * @reason: contains base addresses of APB1 bus
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
 * @brief: this is the base address of PWR registers used to configure some of the PWR behaviors
 * @note: it will be referred to as @HAL_PWR_BASE_ADDR
 */
#define HAL_PWR_OFFSET 0x00007000 /**< this is the offset of the PWR register from APB1 bus base address*/

/**
 * @brief: bit position definitions for PWR_CR (PWR power control register)
 */
#define HAL_PWR_CR_LPDS 0 /**< Low-power deepsleep, This bit is set and cleared by software. It works together with the PDDS bit*/
#define HAL_PWR_CR_PDDS 1 /**< Power-down deepsleep, This bit is set and cleared by software. It works together with the LPDS bit*/
#define HAL_PWR_CR_CWUF 2 /**< Clear wakeup flag, This bit is always read as 0. Clear the WUF Wakeup Flag after 2 System clock cycles.*/
#define HAL_PWR_CR_CSBF 3 /**< Clear standby flag, This bit is always read as 0. Clear the SBF Standby Flag (write).*/
#define HAL_PWR_CR_PVDE 4 /**< Power voltage detector enable, This bit is set and cleared by software.*/
#define HAL_PWR_CR_PLS 5  /**< PVD level selection, These bits are written by software to select the voltage threshold detected by the Power Voltage Detector*/
#define HAL_PWR_CR_DBP 8  /**< Disable backup domain write protection, In reset state, the RCC_BDCR register, the RTC registers (including the backup registers), and the BRE bit of the PWR_CSR register, are protected against parasitic write access. This bit must be set to enable write access to these registers.*/
#define HAL_PWR_CR_FPDS 9 /**< Flash power-down in Stop mode, When set, the Flash memory enters power-down mode when the device enters Stop mode. This allows to achieve a lower consumption in stop mode but a longer restart time.*/
#define HAL_PWR_CR_VOS 14 /**< Regulator voltage scaling output selection, This bit controls the main internal voltage regulator output voltage to achieve a trade-off between performance and power consumption when the device does not operate at the maximum frequency*/

/**
 * @brief: bit position definitions for PWR_CSR (PWR power control/status register)
 */
#define HAL_PWR_CSR_WUF 0     /**< Wakeup flag, This bit is set by hardware and cleared either by a system reset or by setting the CWUF bit in the PWR_CR register.*/
#define HAL_PWR_CSR_SBF 1     /**< Standby flag, This bit is set by hardware and cleared only by a POR/PDR (power-on reset/power-down reset) or by setting the CSBF bit in the PWR_CR register.*/
#define HAL_PWR_CSR_PVDO 2    /**< PVD output, This bit is set and cleared by hardware. It is valid only if PVD is enabled by the PVDE bit. The PVD is stopped by Standby mode. For this reason, this bit is equal to 0 after Standby or reset until the PVDE bit is set.*/
#define HAL_PWR_CSR_BRR 3     /**< Backup regulator ready, Set by hardware to indicate that the Backup Regulator is ready. This bit is not reset when the device wakes up from Standby mode or by a system reset or power reset.*/
#define HAL_PWR_CSR_EWUP 8    /**< Enable WKUP pin, This bit is set and cleared by software. This bit is reset by a system reset.*/
#define HAL_PWR_CSR_BRE 9     /**< Backup regulator enable, When set, the Backup regulator (used to maintain backup SRAM content in Standby and VBAT modes) is enabled. If BRE is reset, the backup regulator is switched off. The backup SRAM can still be used but its content will be lost in the Standby and VBAT modes. Once set, the application must wait that the Backup Regulator Ready flag (BRR) is set to indicate that the data written into the RAM will be maintained in the Standby and VBAT modes. Note: This bit is not reset when the device wakes up from Standby mode, by a system reset or by a power reset.*/
#define HAL_PWR_CSR_VOSRDY 14 /**< Regulator voltage scaling output selection ready bit.*/

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
 * @brief: this holds all registers used to configure embedded PWR
 */
typedef struct
{
    __io uint32_t PWR_CR;  /**< PWR power control register.*/
    __io uint32_t PWR_CSR; /**< PWR power control/status register*/
} HAL_PWR_RegDef_t;

/******************************************************************************
 * Variables
 *******************************************************************************/
static __io HAL_PWR_RegDef_t *global_pPWRReg_t = ((HAL_PWR_RegDef_t *)(HAL_CM4F_APB1_BASEADDR + HAL_PWR_OFFSET)); /**< this is a pointer variable through which we will access our PWR registers to configure them*/

/******************************************************************************
 * Function Prototypes
 *******************************************************************************/

/*** End of File **************************************************************/
#endif /*HAL_PWR_REG_H_*/