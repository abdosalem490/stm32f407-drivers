/**
 * --------------------------------------------------------------------------------------------------------------------------------------
 * |    @title          :   Direct Memory Access Controller                                                                             |
 * |    @file           :   DMA_reg.h                                                                                                   |
 * |    @author         :   Abdelrahman Mohamed Salem                                                                                   |
 * |    @origin_date    :   04/09/2023                                                                                                  |
 * |    @version        :   1.0.0                                                                                                       |
 * |    @tool_chain     :   GNU Tools for STM32                                                                                         |
 * |    @compiler       :   GCC                                                                                                         |
 * |    @C_standard     :   ISO C99 (-std=c99)                                                                                          |
 * |    @target         :   stm32f407VGTX                                                                                               |
 * |    @notes          :   None                                                                                                        |
 * |    @license        :   MIT License                                                                                                 |
 * |    @brief          :   this file contains registers addresses and definitions structs that deals with DMA registers                |
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

#ifndef HAL_DMA_REG_H_
#define HAL_DMA_REG_H_

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
 * @brief: this is the base address of DMA registers used to configure some of the DMA behaviors
 * @note: it will be referred to as @HAL_DMA_BASE_ADDR
 */
#define HAL_DMA1_OFFSET 0x00006000 /**< this is the offset of the DMA1 register from AHB1 bus base address*/
#define HAL_DMA2_OFFSET 0x00006400 /**< this is the offset of the DMA2 register from AHB1 bus base address*/

/**
 * @brief: bit definitions for DMA low interrupt status register (DMA_LISR)
 */
#define HAL_DMA_LISR_TCIF3 27 /**< Stream 3 transfer complete interrupt flag. This bit is set by hardware. It is cleared by software writing 1 to the corresponding bit in the DMA_LIFCR register.*/
#define HAL_DMA_LISR_TCIF2 21 /**< Stream 2 transfer complete interrupt flag. This bit is set by hardware. It is cleared by software writing 1 to the corresponding bit in the DMA_LIFCR register.*/
#define HAL_DMA_LISR_TCIF1 11 /**< Stream 1 transfer complete interrupt flag. This bit is set by hardware. It is cleared by software writing 1 to the corresponding bit in the DMA_LIFCR register.*/
#define HAL_DMA_LISR_TCIF0 5  /**< Stream 0 transfer complete interrupt flag. This bit is set by hardware. It is cleared by software writing 1 to the corresponding bit in the DMA_LIFCR register.*/

#define HAL_DMA_LISR_HTIF3 26 /**< Stream 3 half transfer interrupt flag. This bit is set by hardware. It is cleared by software writing 1 to the corresponding bit in the DMA_LIFCR register.*/
#define HAL_DMA_LISR_HTIF2 20 /**< Stream 2 half transfer interrupt flag. This bit is set by hardware. It is cleared by software writing 1 to the corresponding bit in the DMA_LIFCR register.*/
#define HAL_DMA_LISR_HTIF1 10 /**< Stream 1 half transfer interrupt flag. This bit is set by hardware. It is cleared by software writing 1 to the corresponding bit in the DMA_LIFCR register.*/
#define HAL_DMA_LISR_HTIF0 4  /**< Stream 0 half transfer interrupt flag. This bit is set by hardware. It is cleared by software writing 1 to the corresponding bit in the DMA_LIFCR register.*/

#define HAL_DMA_LISR_TEIF3 25 /**< Stream x transfer error interrupt flag. This bit is set by hardware. It is cleared by software writing 1 to the corresponding bit in the  DMA_LIFCR register.*/
#define HAL_DMA_LISR_TEIF2 19 /**< Stream x transfer error interrupt flag. This bit is set by hardware. It is cleared by software writing 1 to the corresponding bit in the  DMA_LIFCR register.*/
#define HAL_DMA_LISR_TEIF1 9  /**< Stream x transfer error interrupt flag. This bit is set by hardware. It is cleared by software writing 1 to the corresponding bit in the  DMA_LIFCR register.*/
#define HAL_DMA_LISR_TEIF0 3  /**< Stream x transfer error interrupt flag. This bit is set by hardware. It is cleared by software writing 1 to the corresponding bit in the  DMA_LIFCR register.*/

#define HAL_DMA_LISR_DMEIF3 24 /**< Stream 3 direct mode error interrupt flag. This bit is set by hardware. It is cleared by software writing 1 to the corresponding bit in the DMA_LIFCR register.*/
#define HAL_DMA_LISR_DMEIF2 18 /**< Stream 2 direct mode error interrupt flag. This bit is set by hardware. It is cleared by software writing 1 to the corresponding bit in the DMA_LIFCR register.*/
#define HAL_DMA_LISR_DMEIF1 8  /**< Stream 1 direct mode error interrupt flag. This bit is set by hardware. It is cleared by software writing 1 to the corresponding bit in the DMA_LIFCR register.*/
#define HAL_DMA_LISR_DMEIF0 2  /**< Stream 0 direct mode error interrupt flag. This bit is set by hardware. It is cleared by software writing 1 to the corresponding bit in the DMA_LIFCR register.*/

#define HAL_DMA_LISR_FEIF3 22 /**< Stream 3 FIFO error interrupt flag. This bit is set by hardware. It is cleared by software writing 1 to the corresponding bit in the DMA_LIFCR register.*/
#define HAL_DMA_LISR_FEIF2 16 /**< Stream 2 FIFO error interrupt flag. This bit is set by hardware. It is cleared by software writing 1 to the corresponding bit in the DMA_LIFCR register.*/
#define HAL_DMA_LISR_FEIF1 6  /**< Stream 1 FIFO error interrupt flag. This bit is set by hardware. It is cleared by software writing 1 to the corresponding bit in the DMA_LIFCR register.*/
#define HAL_DMA_LISR_FEIF0 0  /**< Stream 0 FIFO error interrupt flag. This bit is set by hardware. It is cleared by software writing 1 to the corresponding bit in the DMA_LIFCR register.*/

/**
 * @brief: bit definitions for DMA high interrupt status register (DMA_HISR)
 */
#define HAL_DMA_HISR_TCIF7 27 /**< Stream 7 transfer complete interrupt flag. This bit is set by hardware. It is cleared by software writing 1 to the corresponding bit in the DMA_HIFCR register.*/
#define HAL_DMA_HISR_TCIF6 21 /**< Stream 6 transfer complete interrupt flag. This bit is set by hardware. It is cleared by software writing 1 to the corresponding bit in the DMA_HIFCR register.*/
#define HAL_DMA_HISR_TCIF5 11 /**< Stream 5 transfer complete interrupt flag. This bit is set by hardware. It is cleared by software writing 1 to the corresponding bit in the DMA_HIFCR register.*/
#define HAL_DMA_HISR_TCIF4 5  /**< Stream 4 transfer complete interrupt flag. This bit is set by hardware. It is cleared by software writing 1 to the corresponding bit in the DMA_HIFCR register.*/

#define HAL_DMA_HISR_HTIF7 26 /**< Stream 7 half transfer interrupt flag. This bit is set by hardware. It is cleared by software writing 1 to the corresponding bit in the DMA_HIFCR register.*/
#define HAL_DMA_HISR_HTIF6 20 /**< Stream 6 half transfer interrupt flag. This bit is set by hardware. It is cleared by software writing 1 to the corresponding bit in the DMA_HIFCR register.*/
#define HAL_DMA_HISR_HTIF5 10 /**< Stream 4 half transfer interrupt flag. This bit is set by hardware. It is cleared by software writing 1 to the corresponding bit in the DMA_HIFCR register.*/
#define HAL_DMA_HISR_HTIF4 4  /**< Stream 3 half transfer interrupt flag. This bit is set by hardware. It is cleared by software writing 1 to the corresponding bit in the DMA_HIFCR register.*/

#define HAL_DMA_HISR_TEIF7 25 /**< Stream x transfer error interrupt flag. This bit is set by hardware. It is cleared by software writing 1 to the corresponding bit in the DMA_HIFCR register.*/
#define HAL_DMA_HISR_TEIF6 19 /**< Stream x transfer error interrupt flag. This bit is set by hardware. It is cleared by software writing 1 to the corresponding bit in the DMA_HIFCR register.*/
#define HAL_DMA_HISR_TEIF5 9  /**< Stream x transfer error interrupt flag. This bit is set by hardware. It is cleared by software writing 1 to the corresponding bit in the DMA_HIFCR register.*/
#define HAL_DMA_HISR_TEIF4 3  /**< Stream x transfer error interrupt flag. This bit is set by hardware. It is cleared by software writing 1 to the corresponding bit in the DMA_HIFCR register.*/

#define HAL_DMA_HISR_DMEIF7 24 /**< Stream 7 direct mode error interrupt flag. This bit is set by hardware. It is cleared by software writing 1 to the corresponding bit in the DMA_HIFCR register.*/
#define HAL_DMA_HISR_DMEIF6 18 /**< Stream 6 direct mode error interrupt flag. This bit is set by hardware. It is cleared by software writing 1 to the corresponding bit in the DMA_HIFCR register.*/
#define HAL_DMA_HISR_DMEIF5 8  /**< Stream 5 direct mode error interrupt flag. This bit is set by hardware. It is cleared by software writing 1 to the corresponding bit in the DMA_HIFCR register.*/
#define HAL_DMA_HISR_DMEIF4 2  /**< Stream 4 direct mode error interrupt flag. This bit is set by hardware. It is cleared by software writing 1 to the corresponding bit in the DMA_HIFCR register.*/

#define HAL_DMA_HISR_FEIF7 22 /**< Stream 7 FIFO error interrupt flag. This bit is set by hardware. It is cleared by software writing 1 to the corresponding bit in the DMA_HIFCR register.*/
#define HAL_DMA_HISR_FEIF6 16 /**< Stream 6 FIFO error interrupt flag. This bit is set by hardware. It is cleared by software writing 1 to the corresponding bit in the DMA_HIFCR register.*/
#define HAL_DMA_HISR_FEIF5 6  /**< Stream 5 FIFO error interrupt flag. This bit is set by hardware. It is cleared by software writing 1 to the corresponding bit in the DMA_HIFCR register.*/
#define HAL_DMA_HISR_FEIF4 0  /**< Stream 4 FIFO error interrupt flag. This bit is set by hardware. It is cleared by software writing 1 to the corresponding bit in the DMA_HIFCR register.*/

/**
 * @brief: bit definitions for DMA low interrupt flag clear register (DMA_LIFCR)
 */
#define HAL_DMA_LIFCR_CTCIF3 27 /**< Stream 3 clear transfer complete interrupt flag. Writing 1 to this bit clears the corresponding TCIFx flag in the DMA_LISR register.*/
#define HAL_DMA_LIFCR_CTCIF2 21 /**< Stream 2 clear transfer complete interrupt flag. Writing 1 to this bit clears the corresponding TCIFx flag in the DMA_LISR register.*/
#define HAL_DMA_LIFCR_CTCIF1 11 /**< Stream 1 clear transfer complete interrupt flag. Writing 1 to this bit clears the corresponding TCIFx flag in the DMA_LISR register.*/
#define HAL_DMA_LIFCR_CTCIF0 5  /**< Stream 0 clear transfer complete interrupt flag. Writing 1 to this bit clears the corresponding TCIFx flag in the DMA_LISR register.*/

#define HAL_DMA_LIFCR_CHTIF3 26 /**< Stream 3 clear half transfer interrupt flag. Writing 1 to this bit clears the corresponding HTIFx flag in the DMA_LISR register.*/
#define HAL_DMA_LIFCR_CHTIF2 20 /**< Stream 2 clear half transfer interrupt flag. Writing 1 to this bit clears the corresponding HTIFx flag in the DMA_LISR register.*/
#define HAL_DMA_LIFCR_CHTIF1 10 /**< Stream 1 clear half transfer interrupt flag. Writing 1 to this bit clears the corresponding HTIFx flag in the DMA_LISR register.*/
#define HAL_DMA_LIFCR_CHTIF0 4  /**< Stream 0 clear half transfer interrupt flag. Writing 1 to this bit clears the corresponding HTIFx flag in the DMA_LISR register.*/

#define HAL_DMA_LIFCR_CTEIF3 25 /**< Stream 3 clear transfer error interrupt flag. Writing 1 to this bit clears the corresponding TEIFx flag in the DMA_LISR register.*/
#define HAL_DMA_LIFCR_CTEIF2 19 /**< Stream 2 clear transfer error interrupt flag. Writing 1 to this bit clears the corresponding TEIFx flag in the DMA_LISR register.*/
#define HAL_DMA_LIFCR_CTEIF1 9  /**< Stream 1 clear transfer error interrupt flag. Writing 1 to this bit clears the corresponding TEIFx flag in the DMA_LISR register.*/
#define HAL_DMA_LIFCR_CTEIF0 3  /**< Stream 0 clear transfer error interrupt flag. Writing 1 to this bit clears the corresponding TEIFx flag in the DMA_LISR register.*/

#define HAL_DMA_LIFCR_CDMEIF3 24 /**< Stream 3 clear direct mode error interrupt flag. Writing 1 to this bit clears the corresponding DMEIFx flag in the DMA_LISR register.*/
#define HAL_DMA_LIFCR_CDMEIF2 18 /**< Stream 2 clear direct mode error interrupt flag. Writing 1 to this bit clears the corresponding DMEIFx flag in the DMA_LISR register.*/
#define HAL_DMA_LIFCR_CDMEIF1 8  /**< Stream 1 clear direct mode error interrupt flag. Writing 1 to this bit clears the corresponding DMEIFx flag in the DMA_LISR register.*/
#define HAL_DMA_LIFCR_CDMEIF0 2  /**< Stream 0 clear direct mode error interrupt flag. Writing 1 to this bit clears the corresponding DMEIFx flag in the DMA_LISR register.*/

#define HAL_DMA_LIFCR_CFEIF3 22 /**< Stream 3 clear FIFO error interrupt flag. Writing 1 to this bit clears the corresponding CFEIFx flag in the DMA_LISR register.*/
#define HAL_DMA_LIFCR_CFEIF2 16 /**< Stream 2 clear FIFO error interrupt flag. Writing 1 to this bit clears the corresponding CFEIFx flag in the DMA_LISR register.*/
#define HAL_DMA_LIFCR_CFEIF1 6  /**< Stream 1 clear FIFO error interrupt flag. Writing 1 to this bit clears the corresponding CFEIFx flag in the DMA_LISR register.*/
#define HAL_DMA_LIFCR_CFEIF0 0  /**< Stream 0 clear FIFO error interrupt flag. Writing 1 to this bit clears the corresponding CFEIFx flag in the DMA_LISR register.*/

/**
 * @brief: bit definitions for DMA high interrupt flag clear register (DMA_HIFCR)
 */
#define HAL_DMA_HIFCR_CTCIF7 27 /**< Stream 7 clear transfer complete interrupt flag. Writing 1 to this bit clears the corresponding TCIFx flag in the DMA_HISR register */
#define HAL_DMA_HIFCR_CTCIF6 21 /**< Stream 6 clear transfer complete interrupt flag. Writing 1 to this bit clears the corresponding TCIFx flag in the DMA_HISR register */
#define HAL_DMA_HIFCR_CTCIF5 11 /**< Stream 5 clear transfer complete interrupt flag. Writing 1 to this bit clears the corresponding TCIFx flag in the DMA_HISR register */
#define HAL_DMA_HIFCR_CTCIF4 5  /**< Stream 4 clear transfer complete interrupt flag. Writing 1 to this bit clears the corresponding TCIFx flag in the DMA_HISR register */

#define HAL_DMA_HIFCR_CHTIF7 26 /**< Stream 7 clear half transfer interrupt flag. Writing 1 to this bit clears the corresponding HTIFx flag in the DMA_HISR register.*/
#define HAL_DMA_HIFCR_CHTIF6 20 /**< Stream 6 clear half transfer interrupt flag. Writing 1 to this bit clears the corresponding HTIFx flag in the DMA_HISR register.*/
#define HAL_DMA_HIFCR_CHTIF5 10 /**< Stream 5 clear half transfer interrupt flag. Writing 1 to this bit clears the corresponding HTIFx flag in the DMA_HISR register.*/
#define HAL_DMA_HIFCR_CHTIF4 4  /**< Stream 4 clear half transfer interrupt flag. Writing 1 to this bit clears the corresponding HTIFx flag in the DMA_HISR register.*/

#define HAL_DMA_HIFCR_CTEIF7 25 /**< Stream 7 clear transfer error interrupt flag. Writing 1 to this bit clears the corresponding TEIFx flag in the DMA_HISR register.*/
#define HAL_DMA_HIFCR_CTEIF6 19 /**< Stream 6 clear transfer error interrupt flag. Writing 1 to this bit clears the corresponding TEIFx flag in the DMA_HISR register.*/
#define HAL_DMA_HIFCR_CTEIF5 9  /**< Stream 5 clear transfer error interrupt flag. Writing 1 to this bit clears the corresponding TEIFx flag in the DMA_HISR register.*/
#define HAL_DMA_HIFCR_CTEIF4 3  /**< Stream 4 clear transfer error interrupt flag. Writing 1 to this bit clears the corresponding TEIFx flag in the DMA_HISR register.*/

#define HAL_DMA_HIFCR_CDMEIF7 24 /**< Stream 7 clear direct mode error interrupt flag. Writing 1 to this bit clears the corresponding DMEIFx flag in the DMA_HISR register.*/
#define HAL_DMA_HIFCR_CDMEIF6 18 /**< Stream 6 clear direct mode error interrupt flag. Writing 1 to this bit clears the corresponding DMEIFx flag in the DMA_HISR register.*/
#define HAL_DMA_HIFCR_CDMEIF5 8  /**< Stream 5 clear direct mode error interrupt flag. Writing 1 to this bit clears the corresponding DMEIFx flag in the DMA_HISR register.*/
#define HAL_DMA_HIFCR_CDMEIF4 2  /**< Stream 4 clear direct mode error interrupt flag. Writing 1 to this bit clears the corresponding DMEIFx flag in the DMA_HISR register.*/

#define HAL_DMA_HIFCR_CFEIF7 22 /**< Stream 7 clear FIFO error interrupt flag. Writing 1 to this bit clears the corresponding CFEIFx flag in the DMA_HISR register.*/
#define HAL_DMA_HIFCR_CFEIF6 16 /**< Stream 6 clear FIFO error interrupt flag. Writing 1 to this bit clears the corresponding CFEIFx flag in the DMA_HISR register.*/
#define HAL_DMA_HIFCR_CFEIF5 6  /**< Stream 5 clear FIFO error interrupt flag. Writing 1 to this bit clears the corresponding CFEIFx flag in the DMA_HISR register.*/
#define HAL_DMA_HIFCR_CFEIF4 0  /**< Stream 4 clear FIFO error interrupt flag. Writing 1 to this bit clears the corresponding CFEIFx flag in the DMA_HISR register.*/

/**
 * @brief: bit definitions for DMA stream x configuration register (DMA_SxCR) (x = 0..7)
 */
#define HAL_DMA_SxCR_CHSEL 25  /**< Channel selection. These bits are set and cleared by software. These bits are protected and can be written only if EN is ‘0’.*/
#define HAL_DMA_SxCR_MBURST 23 /**< Memory burst transfer configuration. These bits are set and cleared by software. These bits are protected and can be written only if EN is ‘0’ In direct mode, these bits are forced to 0x0 by hardware as soon as bit EN= '1'.*/
#define HAL_DMA_SxCR_PBURST 21 /**< Peripheral burst transfer configuration. These bits are set and cleared by software. These bits are protected and can be written only if EN is ‘0’. In direct mode, these bits are forced to 0x0 by hardware.*/
#define HAL_DMA_SxCR_CT 19     /**< Current target (only in double buffer mode). This bits is set and cleared by hardware. It can also be written by software. This bit can be written only if EN is ‘0’ to indicate the target memory area of the first transfer. Once the stream is enabled, this bit operates as a status flag indicating which memory area is the current target.*/
#define HAL_DMA_SxCR_DBM 18    /**< Double buffer mode. This bits is set and cleared by software. This bit is protected and can be written only if EN is ‘0’.*/
#define HAL_DMA_SxCR_PL 16     /**< Priority level. These bits are set and cleared by software. These bits are protected and can be written only if EN is ‘0’.*/
#define HAL_DMA_SxCR_PINCOS 15 /**< Peripheral increment offset size. This bit is set and cleared by software. This bit has no meaning if bit PINC = '0'. This bit is protected and can be written only if EN = '0'. This bit is forced low by hardware when the stream is enabled (bit EN = '1') if the direct  mode is selected or if PBURST are different from “00”.*/
#define HAL_DMA_SxCR_MSIZE 13  /**< Memory data size. These bits are set and cleared by software. These bits are protected and can be written only if EN is ‘0’. In direct mode, MSIZE is forced by hardware to the same value as PSIZE as soon as bit EN  = '1'.*/
#define HAL_DMA_SxCR_PSIZE 11  /**< Peripheral data size. These bits are set and cleared by software. These bits are protected and can be written only if EN is ‘0’.*/
#define HAL_DMA_SxCR_MINC 10   /**< Memory increment mode. This bit is set and cleared by software. This bit is protected and can be written only if EN is ‘0’.*/
#define HAL_DMA_SxCR_PINC 9    /**< Peripheral increment mode. This bit is set and cleared by software. This bit is protected and can be written only if EN is ‘0’.*/
#define HAL_DMA_SxCR_CIRC 8    /**< Circular mode. This bit is set and cleared by software and can be cleared by hardware. When the peripheral is the flow controller (bit PFCTRL=1) and the stream is enabled (bit EN=1), then this bit is automatically forced by hardware to 0.  It is automatically forced by hardware to 1 if the DBM bit is set, as soon as the stream is enabled (bit EN ='1').*/
#define HAL_DMA_SxCR_DIR 6     /**< Data transfer direction. These bits are set and cleared by software. These bits are protected and can be written only if EN is ‘0’. */
#define HAL_DMA_SxCR_PFCTRL 5  /**< Peripheral flow controller. This bit is set and cleared by software. This bit is protected and can be written only if EN is ‘0’. When the memory-to-memory mode is selected (bits DIR[1:0]=10), then this bit is automatically forced to 0 by hardware.*/
#define HAL_DMA_SxCR_TCIE 4    /**< Transfer complete interrupt enable. This bit is set and cleared by software.*/
#define HAL_DMA_SxCR_HTIE 3    /**< Half transfer interrupt enable. This bit is set and cleared by software. */
#define HAL_DMA_SxCR_TEIE 2    /**< Transfer error interrupt enable. This bit is set and cleared by software.*/
#define HAL_DMA_SxCR_DMEIE 1   /**< Direct mode error interrupt enable. This bit is set and cleared by software.*/
#define HAL_DMA_SxCR_EN 0      /**< Stream enable / flag stream ready when read low. This bit is set and cleared by software. */

/**
 * @brief: bit definitions for DMA stream x number of data register (DMA_SxNDTR) (x = 0..7)
 */
#define HAL_DMA_SxNDTR_NDT 0 /**< Number of data items to transfer. Number of data items to be transferred (0 up to 65535)*/

/**
 * @brief: bit definitions for DMA stream x FIFO control register (DMA_SxFCR) (x = 0..7)
 */
#define HAL_DMA_SxFCR_FEIE 7  /**< FIFO error interrupt enable. This bit is set and cleared by software.*/
#define HAL_DMA_SxFCR_FS 3    /**< FIFO status. These bits are read-only. others: no meaning. These bits are not relevant in the direct mode (DMDIS bit is zero).*/
#define HAL_DMA_SxFCR_DMDIS 2 /**<  Direct mode disable. This bit is set and cleared by software. It can be set by hardware. This bit is protected and can be written only if EN is ‘0’. This bit is set by hardware if the memory-to-memory mode is selected (DIR bit in  DMA_SxCR are “10”) and the EN bit in the DMA_SxCR register is ‘1’ because the direct  mode is not allowed in the memory-to-memory configuration.*/
#define HAL_DMA_SxFCR_FTH 0   /**< FIFO threshold selection. These bits are set and cleared by software. These bits are not used in the direct mode when the DMIS value is zero. These bits are protected and can be written only if EN is ‘0’.*/
#define HAL_DMA_SxFCR_FTH 0   /**< FIFO threshold selection. These bits are set and cleared by software. These bits are not used in the direct mode when the DMIS value is zero. These bits are protected and can be written only if EN is ‘0’.*/

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
 * @brief: holds configurations for each stream
 */
typedef struct
{
    __io uint32_t DMA_SxCR;   /**< DMA stream x configuration register. This register is used to configure the concerned stream. Address offset: 0x10 + 0x18 × stream number. */
    __io uint32_t DMA_SxNDTR; /**< DMA stream x number of data register. Address offset: 0x14 + 0x18 × stream number. */
    __io uint32_t DMA_SxPAR;  /**< DMA stream x peripheral address register. Address offset: 0x18 + 0x18 × stream number. */
    __io uint32_t DMA_SxM0AR; /**< DMA stream x memory 0 address register. Address offset: 0x1C + 0x18 × stream number. */
    __io uint32_t DMA_SxM1AR; /**< DMA stream x memory 1 address register. Address offset: 0x20 + 0x18 × stream number. */
    __io uint32_t DMA_SxFCR;  /**< DMA stream x FIFO control register. Address offset: 0x24 + 0x24 × stream number. */
} HAL_DMA_StreamRegDef_t;

/**
 * @brief: this holds all registers used to configure DMA
 */
typedef struct
{
    __io uint32_t DMA_LISR;                 /**< DMA low interrupt status register.*/
    __io uint32_t DMA_HISR;                 /**< DMA high interrupt status register.*/
    __io uint32_t DMA_LIFCR;                /**< DMA low interrupt flag clear register. */
    __io uint32_t DMA_HIFCR;                /**< DMA high interrupt flag clear register. */
    __io HAL_DMA_StreamRegDef_t Streams[8]; /**< contains registers regarding each stream*/
} HAL_DMA_RegDef_t;

static __io HAL_DMA_RegDef_t *const global_pDMA1Reg_t = ((HAL_DMA_RegDef_t *)(HAL_CM4F_AHB1_BASEADDR + HAL_DMA1_OFFSET)); /**< this is a pointer variable through which we will access our DMA1 registers to configure them*/
static __io HAL_DMA_RegDef_t *const global_pDMA2Reg_t = ((HAL_DMA_RegDef_t *)(HAL_CM4F_AHB1_BASEADDR + HAL_DMA2_OFFSET)); /**< this is a pointer variable through which we will access our DMA2 registers to configure them*/

/******************************************************************************
 * Variables
 *******************************************************************************/

/******************************************************************************
 * Function Prototypes
 *******************************************************************************/

/******************************************************************************
 * Interface for peripherals in same level
 *******************************************************************************/

/*** End of File **************************************************************/
#endif /*HAL_DMA_REG_H_*/
