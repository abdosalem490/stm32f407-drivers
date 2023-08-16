/**
 * --------------------------------------------------------------------------------------------------------------------------------------
 * |    @title          :   Flash                                                                                                       |
 * |    @file           :   Flash_reg.h                                                                                                 |
 * |    @author         :   Abdelrahman Mohamed Salem                                                                                   |
 * |    @origin_date    :   19/07/2023                                                                                                  |
 * |    @version        :   1.0.0                                                                                                       |
 * |    @tool_chain     :   GNU Tools for STM32                                                                                         |
 * |    @compiler       :   GCC                                                                                                         |
 * |    @C_standard     :   ISO C99 (-std=c99)                                                                                          |
 * |    @target         :   stm32f407VGTX                                                                                               |
 * |    @notes          :   None                                                                                                        |
 * |    @license        :   MIT License                                                                                                 |
 * |    @brief          :   this file contains registers addresses and definitions structs that deals with flash registers              |
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
 * |    15/07/2023      1.0.0           Abdelrahman Mohamed Salem       Interface Created.                                              |
 * --------------------------------------------------------------------------------------------------------------------------------------
 */

#ifndef HAL_FLASH_REG_H_
#define HAL_FLASH_REG_H_

/******************************************************************************
 * Includes
 *******************************************************************************/
/**
 * @reason: contains standard definitions for the variables
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
 * @brief: base address of one-time programmable fuses that will lock OTP forever
 */
#define HAL_FLASH_OTP_LOCK_BASEADDR 0x1FFF7A00 /**< this is the base address of the lock bytes of otp memory*/

/**
 * @brief: these are base addresses of additional memory other than main memory base address
 */
#define HAL_FLASH_SYSTEM_MEMORY_BASEADDR 0x1FFF0000 /**< Base address of System memory*/
#define HAL_FLASH_OTP_AREA_BASEADDR 0x1FFF7800      /**< Base address of One time programmable (OTP) area*/
#define HAL_FLASH_OPTION_BYTES_BASEADDR 0x1FFFC000  /**< Base address of System memory*/

/**
 * @brief: these are the addresses of the additional memories other than main memory base addresses
 */
#define HAL_FLASH_SYSTEM_MEMORY_SIZE 30000 /**< Size of System memory = 30 Kbytes (showed size is in bytes)*/
#define HAL_FLASH_OTP_AREA_SIZE 512        /**< Size of One time programmable (OTP) = 512 bytes (showed size is in bytes)*/
#define HAL_FLASH_OPTION_BYTES_SIZE 16     /**< Size of option bytes = 16 bytes (showed size is in bytes)*/

/**
 * @brief: this is the base address of flash interface registers used to configure some of the flash interface behaviors
 * @note: it will be referred to as @HAL_FLASH_BASE_ADDR
 */
#define HAL_FLASH_INTERFACE_OFFSET 0x00003C00 /**< this is the offset of the flash register from AHB1 bus base address*/

/**
 * @brief: bit position definitions for FLASH_ACR (Flash access control register)
 */
#define HAL_FLASH_ACR_LATENCY 0 /**< Latency, These bits represent the ratio of the CPU clock period to the Flash memory access time.*/
#define HAL_FLASH_ACR_PRFTEN 8  /**< Prefetch enable.*/
#define HAL_FLASH_ACR_ICEN 9    /**< Instruction cache enable.*/
#define HAL_FLASH_ACR_DCEN 10   /**< Data cache enable*/
#define HAL_FLASH_ACR_ICRST 11  /**< Instruction cache reset, This bit can be written only when the I cache is disabled.*/
#define HAL_FLASH_ACR_DCRST 12  /**< Data cache reset, This bit can be written only when the D cache is disabled.*/

/**
 * @brief: bit position definitions for FLASH_SR (Flash status register)
 */
#define HAL_FLASH_SR_EOP 0    /**< End of operation. Set by hardware when one or more Flash memory operations (program/erase) has/have completed successfully. It is set only if the end of operation interrupts are enabled (EOPIE = 1). Cleared by writing a 1.*/
#define HAL_FLASH_SR_OPERR 1  /**< Operation error. Set by hardware when a flash operation (programming / erase /read) request is detected and  can not be run because of parallelism, alignment, or write protection error. This bit is set only if  error interrupts are enabled (ERRIE = 1).*/
#define HAL_FLASH_SR_WRPERR 4 /**< Write protection error. Set by hardware when an address to be erased/programmed belongs to a write-protected part of the Flash memory. Cleared by writing 1.*/
#define HAL_FLASH_SR_PGAERR 5 /**< Programming alignment error. Set by hardware when the data to program cannot be contained in the same 128-bit Flash memory row. Cleared by writing 1.*/
#define HAL_FLASH_SR_PGPERR 6 /**< Programming parallelism error. Set by hardware when the size of the access (byte, half-word, word, double word) during the program sequence does not correspond to the parallelism configuration PSIZE (x8, x16, x32, x64). Cleared by writing 1.*/
#define HAL_FLASH_SR_PGSERR 7 /**< Programming sequence error. Set by hardware when a write access to the Flash memory is performed by the code while the control register has not been correctly configured. Cleared by writing 1.*/
#define HAL_FLASH_SR_BSY 16   /**< Busy. This bit indicates that a Flash memory operation is in progress. It is set at the beginning of a Flash memory operation and cleared when the operation finishes or an error occurs. */

/**
 * @brief: bit position definitions for FLASH_CR (Flash control register)
 */
#define HAL_FLASH_CR_PG 0     /**< Programming. Flash programming activated.*/
#define HAL_FLASH_CR_SER 1    /**< Sector Erase. Sector Erase activated.*/
#define HAL_FLASH_CR_MER 2    /**< Mass Erase. Erase activated for all user sectors.*/
#define HAL_FLASH_CR_SNB 3    /**< Sector number. These bits select the sector to erase.*/
#define HAL_FLASH_CR_PSIZE 8  /**< Program size. These bits select the program parallelism.*/
#define HAL_FLASH_CR_STRT 16  /**< Start. This bit triggers an erase operation when set. It is set only by software and cleared when the BSY bit is cleared.*/
#define HAL_FLASH_CR_EOPIE 24 /**< End of operation interrupt enable. This bit enables the interrupt generation when the EOP bit in the FLASH_SR register goes to 1.*/
#define HAL_FLASH_CR_ERRIE 25 /**< Error interrupt enable. This bit enables the interrupt generation when the OPERR bit in the FLASH_SR register is set to 1.*/
#define HAL_FLASH_CR_LOCK 31  /**< Lock. Write to 1 only. When it is set, this bit indicates that the FLASH_CR register is locked. It is cleared by hardware after detecting the unlock sequence. In the event of an unsuccessful unlock operation, this bit remains set until the next reset.*/

/**
 * @brief: bit position definitions for FLASH_OPTCR (Flash option control register)
 */
#define HAL_FLASH_OPTCR_OPTLOCK 0    /**< Option lock. Write to 1 only. When this bit is set, it indicates that the FLASH_OPTCR register is locked. This bit is cleared by hardware after detecting the unlock sequence. In the event of an unsuccessful unlock operation, this bit remains set until the next reset.*/
#define HAL_FLASH_OPTCR_OPTSTRT 1    /**< Option start. This bit triggers a user option operation when set. It is set only by software and cleared when the BSY bit is cleared.*/
#define HAL_FLASH_OPTCR_BOR_LEV 2    /**< BOR reset Level. These bits contain the supply level threshold that activates/releases the reset. They can be written to program a new BOR level. By default, BOR is off. When the supply voltage (VDD) drops below the selected BOR level, a device reset is generated.*/
#define HAL_FLASH_OPTCR_WDG_SW 5     /**< User option bytes. These bits contain the value of the user option byte after reset. They can be written to program a new user option byte value into Flash memory. When changing the WDG mode from hardware to software or from software to hardware, a system reset is required to make the change effective.*/
#define HAL_FLASH_OPTCR_nRST_STOP 6  /**< User option bytes. These bits contain the value of the user option byte after reset. They can be written to program a new user option byte value into Flash memory.*/
#define HAL_FLASH_OPTCR_nRST_STDBY 7 /**< User option bytes. These bits contain the value of the user option byte after reset. They can be written to program a new user option byte value into Flash memory.*/
#define HAL_FLASH_OPTCR_RDP 8        /**< Read protect. These bits contain the value of the read-protection option level after reset. They can be written to program a new read protection value into Flash memory.*/
#define HAL_FLASH_OPTCR_nWRP 16      /**< Not write protect. These bits contain the value of the write-protection option bytes after reset. They can be written to program a new write protect value into Flash memory.*/

/******************************************************************************
 * Configuration Constants
 *******************************************************************************/

/**
 * @brief: The following keys values must be programmed consecutively to unlock the FLASH_CR register and allow programming/erasing it
 */
#define HAL_FLASH_CR_KEY1 0x45670123 /**< this is the first key to be written to the register called FLASH_KEYR in order to unlock the register called FLASH_CR*/
#define HAL_FLASH_CR_KEY2 0xCDEF89AB /**< this is the second key to be written to the register called FLASH_KEYR in order to unlock the register called FLASH_CR*/

/**
 * @brief: The following keys values must be programmed consecutively to unlock the FLASH_OPTCR register and allow programming/erasing it
 */
#define HAL_FLASH_OPTCR_OPTKEY1 0x08192A3B /**< this is the first key to be written to the register called FLASH_OPTKEYR in order to unlock the register called FLASH_OPTCR*/
#define HAL_FLASH_OPTCR_OPTKEY2 0x4C5D6E7F /**< this is the second key to be written to the register called FLASH_OPTKEYR in order to unlock the register called FLASH_OPTCR*/

/******************************************************************************
 * Macros
 *******************************************************************************/

/******************************************************************************
 * Typedefs
 *******************************************************************************/

/**
 * @brief: this holds all registers used to configure embedded flash memory
 */
typedef struct
{
    __io uint32_t FLASH_ACR;     /**< The Flash access control register is used to enable/disable the acceleration features and control the Flash memory access time according to CPU frequency. address offset = 0x00 and reset value =  0x0000 0000*/
    __io uint32_t FLASH_KEYR;    /**< The Flash key register is used to allow access to the Flash control register and so, to allow program and erase operations. Address offset: 0x04 and Reset value: 0x0000 0000. notes: The following values must be programmed consecutively to unlock the FLASH_CR register and allow programming/erasing it: a) KEY1 = 0x45670123  b) KEY2 = 0xCDEF89AB*/
    __io uint32_t FLASH_OPTKEYR; /**< The Flash option key register is used to allow program and erase operations in the user configuration sector. Address offset: 0x08 and Reset value: 0x0000 0000. The following values must be programmed consecutively to unlock the FLASH_OPTCR  register and allow programming it: a) OPTKEY1 = 0x08192A3B b) OPTKEY2 = 0x4C5D6E7F */
    __io uint32_t FLASH_SR;      /**< The Flash status register gives information on ongoing program and erase operations. Address offset: 0x0C and Reset value: 0x0000 0000*/
    __io uint32_t FLASH_CR;      /**< The Flash control register is used to configure and start Flash memory operations. Address offset: 0x10 and Reset value: 0x8000 0000 */
    __io uint32_t FLASH_OPTCR;   /**< The Flash option control register register is used to modify the user option bytes. Address offset: 0x14 and Reset value: 0x0FFF AAED. The option bits are loaded with values from Flash memory at reset release.*/
} HAL_FLASH_RegDef_t;

/******************************************************************************
 * Variables
 *******************************************************************************/
__io HAL_FLASH_RegDef_t *global_pFlashReg_t = ((HAL_FLASH_RegDef_t *)(HAL_CM4F_AHB1_BASEADDR + HAL_FLASH_INTERFACE_OFFSET)); /**< this is a pointer variable through which we will access our flash registers to configure them*/

/******************************************************************************
 * Function Prototypes
 *******************************************************************************/

/*** End of File **************************************************************/
#endif /*HAL_FLASH_REG_H_*/