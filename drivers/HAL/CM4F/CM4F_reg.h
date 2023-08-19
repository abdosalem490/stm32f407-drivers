/**
 * --------------------------------------------------------------------------------------------------------------------------------------
 * |    @title          :   CM4F                                                                                                       |
 * |    @file           :   CM4F_reg.h                                                                                                  |
 * |    @author         :   Abdelrahman Mohamed Salem                                                                                   |
 * |    @origin_date    :   17/07/2023                                                                                                  |
 * |    @version        :   1.0.0                                                                                                       |
 * |    @tool_chain     :   GNU Tools for STM32                                                                                         |
 * |    @compiler       :   GCC                                                                                                         |
 * |    @C_standard     :   ISO C99 (-std=c99)                                                                                          |
 * |    @target         :   stm32f407VGTX                                                                                               |
 * |    @notes          :   None                                                                                                        |
 * |    @license        :   MIT License                                                                                                 |
 * |    @brief          :   this file contains register addresses of arm cortex m4 with FPU and bus base addresses                      |
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
 * |    15/07/2023      1.0.0           Abdelrahman Mohamed Salem       file Created.                                                      |
 * |    14/08/2023      1.0.0           Abdelrahman Mohamed Salem       add SCB reg def.                                                |
 * --------------------------------------------------------------------------------------------------------------------------------------
 */

#ifndef HAL_CM4F_REG_H_
#define HAL_CM4F_REG_H_

/******************************************************************************
 * Includes
 *******************************************************************************/
/**
 * @reason: contains standard definitions for the variables
 */
#include "../../lib/stdint.h"

/**
 * @reason: contains volatile keyword definition regarding selected compiler
 */
#include "../../lib/common.h"
/******************************************************************************
 * Preprocessor Constants
 *******************************************************************************/

/**
 * @brief: these are buses base addresses, will be referred to as @HAL_CM4F_BUSES_BASE_ADDR
 */
#define HAL_CM4F_AHB3_BASEADDR 0x60000000 /**< boundary address = 0x6000 0000 - 0xA000 0FFF where this bus is advanced high performance bus */
#define HAL_CM4F_AHB2_BASEADDR 0x50000000 /**< boundary address = 0x5000 0000 - 0x5006 0BFF where this bus is advanced high performance bus */
#define HAL_CM4F_AHB1_BASEADDR 0x40020000 /**< boundary address = 0x4002 0000 - 0x4007 FFFF where this bus is advanced high performance bus */
#define HAL_CM4F_APB2_BASEADDR 0x40010000 /**< boundary address = 0x4001 0000 - 0x4001 57FF where this bus is advanced peripheral bus */
#define HAL_CM4F_APB1_BASEADDR 0x40000000 /**< boundary address = 0x4000 0000 - 0x4000 7FFF where this bus is advanced peripheral bus */

/**
 * @brief: these are some common peripherals base addresses
 */
#define HAL_CM4F_FLASH_BASE_ADDR 0x08000000	   /**< base address of the flash memory, size = 1 Megabyte*/
#define HAL_CM4F_SRAM1_BASE_ADDR 0x20000000	   /**< base address of the sram1 memory, size = 112 KiloByte*/
#define HAL_CM4F_SRAM2_BASE_ADDR 0x2001C000	   /**< base address of the sram2 memory, size = 16 KiloByte*/
#define HAL_CM4F_CCM_SRAM_BASE_ADDR 0x10000000 /**< base address of the core coupled sram memory, size = 64 KiloByte*/

/**
 * @brief: contains peripheral base addresses
 */
#define HAL_CM4F_SCB_BASE_ADDR 0xE000ED00	/**< The System control block (SCB) provides system implementation information, and system control. This includes configuration, control, and reporting of the system exceptions.*/
#define HAL_CM4F_ACTLR_BASE_ADDR 0xE000E008 /**< Auxiliary control register (ACTLR). By default this register is set to provide optimum performance from the Cortex-M4 processor, and does not normally require modification. The ACTLR register provides disable bits for the following processor functions: 1. IT folding. 2. write buffer use for accesses to the default memory map. 3. interruption of multi-cycle instructions.*/

/******************************************************************************
 * Bit Definitions for registers
 *******************************************************************************/

/**
 * @brief: represents bit position and lengths for CPUID base register, Reset value: 0x410F C241
 */

// bit positions
#define HAL_CM4F_CPUID_REVISION_POS 0	  /**< Revision number. The p value in the rnpn product revision identifier, indicates patch release. 0x1: = patch 1*/
#define HAL_CM4F_CPUID_PART_NO_POS 4	  /**< Part number of the processor. 0xC24: = Cortex-M4*/
#define HAL_CM4F_CPUID_CONSTANT_POS 16	  /**< Reads as 0xF*/
#define HAL_CM4F_CPUID_VARIANT_POS 20	  /**< Variant number. The r value in the rnpn product revision identifier. 0x0: revision 0*/
#define HAL_CM4F_CPUID_IMPLEMENTER_POS 24 /**< Implementer code. 0x41: Arm*/

// bit lengths
#define HAL_CM4F_CPUID_REVISION_LENGTH 4	/**< uses 4 bits*/
#define HAL_CM4F_CPUID_PART_NO_LENGTH 12	/**< uses 12 bits*/
#define HAL_CM4F_CPUID_CONSTANT_LENGTH 4	/**< uses 4 bits*/
#define HAL_CM4F_CPUID_VARIANT_LENGTH 4		/**< uses 4 bits*/
#define HAL_CM4F_CPUID_IMPLEMENTER_LENGTH 8 /**< uses 8 bits*/

/**
 * @brief: represents bit position and lengths for Interrupt control and state register (ICSR), Reset value: 0x0000 0000
 */

// bit positions
#define HAL_CM4F_ICSR_VECTACTIVE_POS 0	 /**< VECTACTIVE Active vector. Contains the active exception number. Subtract 16 from this value to obtain CMSIS IRQ number required to index into the Interrupt Clear-Enable, Set-Enable, Clear-Pending, Set-Pending, or Priority Registers*/
#define HAL_CM4F_ICSR_RETOBASE_POS 11	 /**< Return to base level. Indicates whether there are preempted active exceptions*/
#define HAL_CM4F_ICSR_VECTPENDING_POS 12 /**< Pending vector. Indicates the exception number of the highest priority pending enabled exception.*/
#define HAL_CM4F_ICSR_ISRPENDING_POS 22	 /**< Interrupt pending flag, excluding NMI and Faults.*/
#define HAL_CM4F_ICSR_PENDSTCLR_POS 25	 /**< SysTick exception clear-pending bit. Write-only. On a read, value is unknown.*/
#define HAL_CM4F_ICSR_PENDSTSET_POS 26	 /**< SysTick exception set-pending bit. */
#define HAL_CM4F_ICSR_PENDSVCLR_POS 27	 /**< PendSV clear-pending bit. This bit is write-only. On a read, value is unknown.*/
#define HAL_CM4F_ICSR_PENDSVSET_POS 28	 /**< PendSV set-pending bit. Writing 1 to this bit is the only way to set the PendSV exception state to pending.*/
#define HAL_CM4F_ICSR_NMIPENDSET_POS 31	 /**< NMI set-pending bit. Because NMI is the highest-priority exception, normally the processor enter the NMI  exception handler as soon as it registers a write of 1 to this bit, and entering the handler clears this bit to 0. A read of this bit by the NMI exception handler returns 1 only if the NMI signal is  reasserted while the processor is executing that handler.*/

// bit lengths
#define HAL_CM4F_ICSR_VECTACTIVE_LENGTH 9  /**< uses 9 bits*/
#define HAL_CM4F_ICSR_RETOBASE_LENGTH 1	   /**< uses 1 bits*/
#define HAL_CM4F_ICSR_VECTPENDING_LENGTH 7 /**< uses 7 bits*/
#define HAL_CM4F_ICSR_ISRPENDING_LENGTH 1  /**< uses 1 bits*/
#define HAL_CM4F_ICSR_PENDSTCLR_LENGTH 1   /**< uses 1 bits*/
#define HAL_CM4F_ICSR_PENDSTSET_LENGTH 1   /**< uses 1 bits*/
#define HAL_CM4F_ICSR_PENDSVCLR_LENGTH 1   /**< uses 1 bits*/
#define HAL_CM4F_ICSR_PENDSVSET_LENGTH 1   /**< uses 1 bits*/
#define HAL_CM4F_ICSR_NMIPENDSET_LENGTH 1  /**< uses 1 bits*/

/**
 * @brief: represents bit position and lengths for Vector table offset register (VTOR), Reset value: 0x0000 0000
 */

// bit positions
#define HAL_CM4F_VTOR_TBLOFF_POS 0 /**< Vector table base offset field. It contains bits [29:9] of the offset of the table base from memory address 0x00000000. When  setting TBLOFF, you must align the offset to the number of exception entries in the vector  table. The minimum alignment is 128 words. Table alignment requirements mean that bits[8:0] of the table offset are always zero . Bit 29 determines whether the vector table is in the code or SRAM memory region.*/

// bit lengths
#define HAL_CM4F_VTOR_TBLOFF_LENGTH 21 /**< uses 21 bits*/

/**
 * @brief: represents bit position and lengths for Application interrupt and reset control register (AIRCR), Reset value: 0xFA05 0000
 */

// bit positions
#define HAL_CM4F_AIRCR_VECTRESET_POS 0	   /**< Reserved for Debug use. This bit reads as 0. When writing to the register you must write 0 to  this bit, otherwise behavior is unpredictable.*/
#define HAL_CM4F_AIRCR_VECTCLRACTIVE_POS 1 /**< Reserved for Debug use. This bit reads as 0. When writing to the register you must write 0 to  this bit, otherwise behavior is unpredictable.*/
#define HAL_CM4F_AIRCR_SYSRESETREQ_POS 2   /**< System reset request. This is intended to force a large system reset of all major components except for debug. This bit reads as 0.*/
#define HAL_CM4F_AIRCR_PRIGROUP_POS 8	   /**< Interrupt priority grouping field. This field determines the split of group priority from subpriority.*/
#define HAL_CM4F_AIRCR_ENDIANESS_POS 15	   /**< Data endianness. bit Reads as 0.*/
#define HAL_CM4F_AIRCR_VECTKEY_POS 16	   /**< Reads as 0xFA05, On writes, write 0x5FA to VECTKEY, otherwise the write is ignored.*/

// bit lengths
#define HAL_CM4F_AIRCR_VECTRESET_LENGTH 1	  /**< uses 1 bits*/
#define HAL_CM4F_AIRCR_VECTCLRACTIVE_LENGTH 1 /**< uses 1 bits*/
#define HAL_CM4F_AIRCR_SYSRESETREQ_LENGTH 1	  /**< uses 1 bits*/
#define HAL_CM4F_AIRCR_PRIGROUP_LENGTH 3	  /**< uses 3 bits*/
#define HAL_CM4F_AIRCR_ENDIANESS_LENGTH 1	  /**< uses 1 bits*/
#define HAL_CM4F_AIRCR_VECTKEY_LENGTH 16	  /**< uses 16 bits*/

/**
 * @brief: represents bit position and lengths for System control register (SCR), Reset value: 0x0000 0000
 */

// bit positions
#define HAL_CM4F_SCR_SLEEPONEXIT_POS 1 /**< Configures sleep-on-exit when returning from Handler mode to Thread mode. Setting this bit to 1 enables an interrupt-driven application to avoid returning to an empty main application.*/
#define HAL_CM4F_SCR_SLEEPDEEP_POS 2   /**< Controls whether the processor uses sleep or deep sleep as its low power mode.*/
#define HAL_CM4F_SCR_SEVEONPEND_POS 4  /**< Send Event on Pending bit. When an event or interrupt enters pending state, the event signal wakes up the processor from WFE. If the processor is not waiting for an event, the event is registered and affects the next WFE. The processor also wakes up on execution of an SEV instruction or an external event*/

// bit lengths
#define HAL_CM4F_SCR_SLEEPONEXIT_LENGTH 1 /**< uses 1 bits*/
#define HAL_CM4F_SCR_SLEEPDEEP_LENGTH 1	  /**< uses 1 bits*/
#define HAL_CM4F_SCR_SEVEONPEND_LENGTH 1  /**< uses 1 bits*/

/**
 * @brief: represents bit position and lengths for Configuration and control register (CCR), Reset value: 0x0000 0200
 */

// bit positions
#define HAL_CM4F_CCR_NONBASETHRDENA_POS 0 /**< Configures how the processor enters Thread mode*/
#define HAL_CM4F_CCR_USERSETMPEND_POS 1	  /**< Enables unprivileged software access to the STIR*/
#define HAL_CM4F_CCR_UNALIGN_TRP_POS 3	  /**< Enables unaligned access traps. If this bit is set to 1, an unaligned access generates a usage fault. Unaligned LDM, STM, LDRD, and STRD instructions always fault irrespective of whether UNALIGN_TRP is set to 1.*/
#define HAL_CM4F_CCR_DIV_0_TRP_POS 4	  /**< Enables faulting or halting when the processor executes an SDIV or UDIV instruction with a divisor of 0.*/
#define HAL_CM4F_CCR_BFHFNMIGN_POS 8	  /**< Enables handlers with priority -1 or -2 to ignore data bus faults caused by load and store instructions. This applies to the hard fault, NMI, and FAULTMASK escalated handlers. Set this bit to 1 only when the handler and its data are in absolutely safe memory. The normal use of  this bit is to probe system devices and bridges to detect control path problems and fix them.*/
#define HAL_CM4F_CCR_STKALIGN_POS 9		  /**< Configures stack alignment on exception entry. On exception entry, the processor uses bit 9 of the stacked PSR to indicate the stack alignment. On return from the exception it uses this stacked bit to restore the correct stack alignment.*/

// bit lengths
#define HAL_CM4F_CCR_NONBASETHRDENA_LENGTH 1 /**< uses 1 bits*/
#define HAL_CM4F_CCR_USERSETMPEND_LENGTH 1	 /**< uses 1 bits*/
#define HAL_CM4F_CCR_UNALIGN_TRP_LENGTH 1	 /**< uses 1 bits*/
#define HAL_CM4F_CCR_DIV_0_TRP_LENGTH 1		 /**< uses 1 bits*/
#define HAL_CM4F_CCR_BFHFNMIGN_LENGTH 1		 /**< uses 1 bits*/
#define HAL_CM4F_CCR_STKALIGN_LENGTH 1		 /**< uses 1 bits*/

/**
 * @brief: represents bit position and lengths for System handler priority register 1 (SHPR1), Reset value: 0x0000 0000
 */

// bit positions
#define HAL_CM4F_SHPR1_USG_FAULT_POS 20		 /**< Priority of system handler 6, usage fault*/
#define HAL_CM4F_SHPR1_BUS_FAULT_POS 12		 /**< Priority of system handler 5, bus fault*/
#define HAL_CM4F_SHPR1_MEM_MANGE_FAULT_POS 4 /**< Priority of system handler 4, memory management fault */

// bit lengths
#define HAL_CM4F_SHPR1_USG_FAULT_LENGTH 4		/**< uses 4 bits*/
#define HAL_CM4F_SHPR1_BUS_FAULT_LENGTH 4		/**< uses 4 bits*/
#define HAL_CM4F_SHPR1_MEM_MANGE_FAULT_LENGTH 4 /**< uses 4 bits*/

/**
 * @brief: represents bit position and lengths for System handler priority register 2 (SHPR2), Reset value: 0x0000 0000
 */

// bit positions
#define HAL_CM4F_SHPR2_SVCALL_POS 28 /**< Priority of system handler 11, SVCall*/

// bit lengths
#define HAL_CM4F_SHPR2_SVCALL_LENGTH 4 /**< uses 4 bits*/

/**
 * @brief: represents bit position and lengths for System handler priority register 3 (SHPR3), Reset value: 0x0000 0000
 */

// bit positions
#define HAL_CM4F_SHPR3_SYSTICK_EXCEPT_POS 28 /**< Priority of system handler 15, SysTick exception */
#define HAL_CM4F_SHPR3_PENDSV_EXCEPT_POS 20	 /**< Priority of system handler 14, PendSV */

// bit lengths
#define HAL_CM4F_SHPR3_SYSTICK_EXCEPT_LENGTH 4 /**< uses 4 bits*/
#define HAL_CM4F_SHPR3_PENDSV_EXCEPT_LENGTH 4  /**< uses 4 bits*/

/**
 * @brief: represents bit position for System handler control and state register (SHCSR), Reset value: 0x0000 0000
 */

// bit positions
#define HAL_CM4F_SHCSR_MEMFAULTACT_POS 0	 /**< Memory management fault exception active bit, reads as 1 if exception is active. */
#define HAL_CM4F_SHCSR_BUSFAULTACT_POS 1	 /**< Bus fault exception active bit, reads as 1 if exception is active. */
#define HAL_CM4F_SHCSR_USGFAULTACT_POS 3	 /**< Usage fault exception active bit, reads as 1 if exception is activ. */
#define HAL_CM4F_SHCSR_SVCALLACT_POS 7		 /**< SVC call active bit, reads as 1 if SVC call is active. */
#define HAL_CM4F_SHCSR_MONITORACT_POS 8		 /**< Debug monitor active bit, reads as 1 if Debug monitor is active. */
#define HAL_CM4F_SHCSR_PENDSVACT_POS 10		 /**< SysTick exception active bit, reads as 1 if exception is active. */
#define HAL_CM4F_SHCSR_SYSTICKACT_POS 11	 /**< SysTick exception active bit, reads as 1 if exception is active. */
#define HAL_CM4F_SHCSR_USGFAULTPENDED_POS 12 /**< Usage fault exception pending bit, reads as 1 if exception is pending. */
#define HAL_CM4F_SHCSR_MEMFAULTPENDED_POS 13 /**< Memory management fault exception pending bit, reads as 1 if exception is pending. */
#define HAL_CM4F_SHCSR_BUSFAULTPENDED_POS 14 /**< Bus fault exception pending bit, reads as 1 if exception is pending. */
#define HAL_CM4F_SHCSR_SVCALLPENDED_POS 15	 /**< SVC call pending bit, reads as 1 if exception is pending. */
#define HAL_CM4F_SHCSR_MEMFAULTENA_POS 16	 /**< Memory management fault enable bit, set to 1 to enable. */
#define HAL_CM4F_SHCSR_BUSFAULTENA_POS 17	 /**< Bus fault enable bit, set to 1 to enable. */
#define HAL_CM4F_SHCSR_USGFAULTENA_POS 18	 /**< Usage fault enable bit, set to 1 to enable. */

/**
 * @brief: represents bit position for Configurable fault status register (CFSR; UFSR+BFSR+MMFSR), Reset value: 0x0000 0000
 */

// Usage fault status register (UFSR)
#define HAL_CM4F_CFSR_UFSR_DIVBYZERO 25	 /**< Divide by zero usage fault. When the processor sets this bit to 1, the PC value stacked for the exception return points to the instruction that performed the divide by zero.  */
#define HAL_CM4F_CFSR_UFSR_UNALIGNED 24	 /**< Unaligned access usage fault. Enable trapping of unaligned accesses by setting the UNALIGN_TRP bit in the CCR to 1*/
#define HAL_CM4F_CFSR_UFSR_NOCP 19		 /**< No coprocessor usage fault. The processor does not support coprocessor instructions:*/
#define HAL_CM4F_CFSR_UFSR_INVPC 18		 /**< Invalid PC load usage fault, caused by an invalid PC load by EXC_RETURN: When this bit is set to 1, the PC value stacked for the exception return points to the instruction  that tried to perform the illegal load of the PC.*/
#define HAL_CM4F_CFSR_UFSR_INVSTATE 17	 /**< Invalid state usage fault. When this bit is set to 1, the PC value stacked for the exception return points to the instruction that attempted the illegal use of the EPSR. This bit is not set to 1 if an undefined instruction uses the EPSR.*/
#define HAL_CM4F_CFSR_UFSR_UNDEFINSTR 16 /**< Undefined instruction usage fault. When this bit is set to 1, the PC value stacked for the exception return points to the undefined instruction. An undefined instruction is an instruction that the processor cannot decode.*/

// Bus fault status register (BFSR)
#define HAL_CM4F_CFSR_BFSR_BFARVALID 15	  /**< Bus Fault Address Register (BFAR) valid flag. The processor sets this bit to 1 after a bus fault where the address is known. Other faults can set this bit to 0, such as a memory management fault occurring later. If a bus fault occurs and is escalated to a hard fault because of priority, the hard fault handler If a bus fault occurs and is escalated to a hard fault because of priority, the hard fault handler  whose BFAR value is overwritten.*/
#define HAL_CM4F_CFSR_BFSR_LSPERR 13	  /**< Bus fault on floating-point lazy state preservation.*/
#define HAL_CM4F_CFSR_BFSR_STKERR 12	  /**< Bus fault on stacking for exception entry. When the processor sets this bit to 1, the  SP is still adjusted but the values in the context area on the stack might be incorrect. The  processor does not write a fault address to the BFAR.*/
#define HAL_CM4F_CFSR_BFSR_UNSTKERR 11	  /**< Bus fault on unstacking for a return from exception. This fault is chained to the handler. This means that when the processor sets this bit to 1, the original return stack is still present. The processor does not adjust the SP from the failing return, does not performed a new save, and does not write a fault address to the BFAR.*/
#define HAL_CM4F_CFSR_BFSR_IMPRECISERR 10 /**< Imprecise data bus error. When the processor sets this bit to 1, it does not write a fault address to the BFAR. This is an asynchronous fault. Therefore, if it is detected when the priority of the current process is higher than the bus fault priority, the bus fault becomes pending and becomes active only when the processor returns from all higher priority processes. If a precise fault occurs before the processor enters the handler for the imprecise bus fault, the handler detects both IMPRECISERR set to 1 and one of the precise fault status bits set to 1.*/
#define HAL_CM4F_CFSR_BFSR_PRECISERR 9	  /**< Precise data bus error. When the processor sets this bit is 1, it writes the faulting address to the BFAR.*/
#define HAL_CM4F_CFSR_BFSR_IBUSERR 8	  /**< Instruction bus error. The processor detects the instruction bus error on prefetching an instruction, but it sets the IBUSERR flag to 1 only if it attempts to issue the faulting instruction.*/

// Memory management fault address register (MMFSR)
#define HAL_CM4F_CFSR_MMFSR_MMARVALID 7 /**< Memory Management Fault Address Register (MMAR) valid flag. If a memory management fault occurs and is escalated to a hard fault because of priority, the hard fault handler must set this bit to 0. This prevents problems on return to a stacked active memory management fault handler whose MMAR value is overwritten.*/
#define HAL_CM4F_CFSR_MMFSR_MLSPERR 5	/**< MemManage fault flag during floating-point lazy state preservation*/
#define HAL_CM4F_CFSR_MMFSR_MSTKERR 4	/**< Memory manager fault on stacking for exception entry. When this bit is 1, the SP is still adjusted but the values in the context area on the stack might be incorrect. The processor has not written a fault address to the MMAR.*/
#define HAL_CM4F_CFSR_MMFSR_MUNSTKERR 3 /**< Memory manager fault on unstacking for a return from exception. This fault is chained to the handler. This means that when this bit is 1, the original return stack is still  present. The processor has not adjusted the SP from the failing return, and has not performed a new save. The processor has not written a fault address to the MMAR.*/
#define HAL_CM4F_CFSR_MMFSR_DACCVIOL 1	/**< Data access violation flag. When this bit is 1, the PC value stacked for the exception return points to the faulting instruction. The processor has loaded the MMAR with  the address of the attempted access.*/
#define HAL_CM4F_CFSR_MMFSR_IACCVIOL 0	/**< Instruction access violation flag. This fault occurs on any access to an XN region, even the MPU is disabled or not present. When this bit is 1, the PC value stacked for the exception return points to the faulting instruction. The processor has not written a fault address to the MMAR.*/

/**
 * @brief: represents bit position for Hard fault status register (HFSR), Reset value: 0x0000 0000
 */

#define HAL_CM4F_HFSR_DEBUG_VT 31 /**< Reserved for Debug use. When writing to the register you must write 0 to this bit, otherwise behavior is unpredictable.*/
#define HAL_CM4F_HFSR_FORCED 30	  /**< Forced hard fault. Indicates a forced hard fault, generated by escalation of a fault with configurable priority that cannot be handles, either because of priority or because it is disabled. */
#define HAL_CM4F_HFSR_VECTTBL 1	  /**< Vector table hard fault. Indicates a bus fault on a vector table read during exception processing. This error is always handled by the hard fault handler. When this bit is set to 1, the PC value stacked for the exception return points to the instruction that was preempted by the exception.*/

/**
 * @brief: represents bit position for Auxiliary control register (ACTLR), Reset value: 0x0000 0000
 */

#define HAL_CM4F_ACTLR_DISOOFP 9	/**< Disables floating point instructions completing out of order with respect to integer instructions.*/
#define HAL_CM4F_ACTLR_DISFPCA 8	/**< Disables automatic update of CONTROL.FPCA. The value of this bit should be written as zero or preserved (SBZP).*/
#define HAL_CM4F_ACTLR_DISFOLD 2	/**< Disables folding of IT instructions. In some situations, the processor can start executing the first instruction in an IT block while it is still executing the IT instruction. This behavior is called IT folding, and improves performance, However, IT folding can cause jitter in looping. If a task must avoid jitter, set the DISFOLD bit to 1 before executing the task, to disable IT folding.*/
#define HAL_CM4F_ACTLR_DISDEFWBUF 1 /**< This bit only affects write buffers implemented in the Cortex-M4 processor. Disables write buffer use during default memory map accesses: This causes all BusFaults to be precise BusFaults but decreases performance because any store to memory must complete before the processor can execute the next instruction.*/
#define HAL_CM4F_ACTLR_DISMCYCINT 0 /**< Disables interrupt of multi-cycle instructions. When set to 1, disables interruption of load multiple and store multiple instructions. This increases the interrupt latency of the processor because any LDM or STM must complete before the processor can stack the current state and enter the interrupt handler.*/

/******************************************************************************
 *
 *******************************************************************************/

/******************************************************************************
 * Typedefs
 *******************************************************************************/

/**
 * @brief: registers of SCB (system control block)
 */
typedef struct
{
	__io uint32_t CPUID;	 /**< CPUID base register. The CPUID register contains the processor part number, version, and implementation information. */
	__io uint32_t ICSR;		 /**< Interrupt control and state register. Provides: 1. A set-pending bit for the Non-Maskable Interrupt (NMI) exception. 2. Set-pending and clear-pending bits for the PendSV and SysTick exceptions. Indicates:  1. The exception number of the exception being processed. 2.  Whether there are preempted active exceptions. 3. The exception number of the highest priority pending exception. 4. Whether any interrupts are pending.*/
	__io uint32_t VTOR;		 /**< Vector table offset register.*/
	__io uint32_t AIRCR;	 /**< Application interrupt and reset control register. The AIRCR provides priority grouping control for the exception model, endian status for data accesses, and reset control of the system. */
	__io uint32_t SCR;		 /**< System control register. accesses, and reset control of the system. */
	__io uint32_t CCR;		 /**< Configuration and control register (CCR). The CCR controls entry to Thread mode and enables: 1. The handlers for NMI, hard fault and faults escalated by FAULTMASK to ignore bus faults. 2. Trapping of divide by zero and unaligned accesses. Access to the STIR by unprivileged software.*/
	__io uint32_t SHPR1;	 /**< System handler priority registers 1. The SHPR1-SHPR3 registers set the priority level, 0 to 255 of the exception handlers that have configurable priority. SHPR1-SHPR3 are byte accessible. */
	__io uint32_t SHPR2;	 /**< System handler priority registers 2. The SHPR1-SHPR3 registers set the priority level, 0 to 255 of the exception handlers that have configurable priority. SHPR1-SHPR3 are byte accessible. */
	__io uint32_t SHPR3;	 /**< System handler priority registers 3. The SHPR1-SHPR3 registers set the priority level, 0 to 255 of the exception handlers that have configurable priority. SHPR1-SHPR3 are byte accessible. */
	__io uint32_t SHCSR;	 /**< System handler control and state register. enables the system handlers, and indicates: 1. The pending status of the bus fault, memory management fault, and SVC exceptions. 2. The active status of the system handlers.  */
	__io uint32_t CFSR;		 /**< Configurable fault status register (CFSR; UFSR+BFSR+MMFSR). Configurable fault status register (CFSR; UFSR+BFSR+MMFSR): 1. Usage fault status register (UFSR). 2. Bus fault status register (BFSR). 3. Memory management fault address register (MMFSR)*/
	__io uint32_t HFSR;		 /**< Hard fault status register (HFSR). The HFSR gives information about events that activate the hard fault handler. This register is read, write to clear. This means that bits in the register read normally, but writing 1 to any  bit clears that bit to 0.*/
	__io uint32_t Reserved2; /**< Reserved*/
	__io uint32_t MMAR;		 /**< Memory management fault address register (MMFAR). When the MMARVALID bit of the MMFSR is set to 1, this field holds the address of the location that generated the memory management fault. When an unaligned access faults, the address is the actual address that faulted. Because a  single read or write instruction can be split into multiple aligned accesses, the fault address  can be any address in the range of the requested access size. */
	__io uint32_t BFAR;		 /**< Bus fault address register (BFAR). When the BFARVALID bit of the BFSR is set to 1, this field holds the address of the location that generated the bus fault. When an unaligned access faults the address in the BFAR is the one requested by the instruction, even if it is not the address of the fault. */
	__io uint32_t AFSR;		 /**< Auxiliary fault status register (AFSR). Implementation defined. The AFSR contains additional system fault information. The bits map to the AUXFAULT input signals. This register is read, write to clear. This means that bits in the register read normally, but writing 1 to any bit clears that bit to 0. Each AFSR bit maps directly to an AUXFAULT input of the processor, and a single-cycle HIGH signal on the input sets the corresponding AFSR bit to one. It remains set to 1 until you write 1 to the bit to clear it to zero. When an AFSR bit is latched as one, an exception does not occur. Use an interrupt if an exception is required.*/
} HAL_CM4F_SCBRegDef_t;

/******************************************************************************
 * Variables
 *******************************************************************************/

/**
 * @brief: pointers through which we will access our registers
 */
static __io HAL_CM4F_SCBRegDef_t *global_pSCBReg_t = (HAL_CM4F_SCBRegDef_t *)HAL_CM4F_SCB_BASE_ADDR;
static __io uint32_t *global_pu32ACTLRreg_t = (uint32_t *)HAL_CM4F_ACTLR_BASE_ADDR;

/******************************************************************************
 * Function Prototypes
 *******************************************************************************/

/******************************************************************************
 * private functions and macros used by other modules of same level
 *******************************************************************************/

/**
 * @brief: private macro used by power controller (PWR)
 */
#define HAL_CM4F_CONFIGURE_SLEEP_ON_EXIT(VAL) \
	LIB_MATH_BTT_ASSIGN_BIT(global_pSCBReg_t->SCR, HAL_CM4F_SCR_SLEEPONEXIT_POS, VAL)

/**
 * @brief: private macro used by power controller (PWR)
 */
#define HAL_CM4F_CONFIGURE_SLEEPDEEP(VAL) \
	LIB_MATH_BTT_ASSIGN_BIT(global_pSCBReg_t->SCR, HAL_CM4F_SCR_SLEEPDEEP_POS, VAL)

/*** End of File **************************************************************/
#endif /*HAL_CM4F_REG_H_*/