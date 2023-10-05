/**
 * --------------------------------------------------------------------------------------------------------------------------------------
 * |    @title          :   Direct Memory Access Controller                                                                             |
 * |    @file           :   DMA_header.h                                                                                                |
 * |    @author         :   Abdelrahman Mohamed Salem                                                                                   |
 * |    @origin_date    :   09/09/2023                                                                                                  |
 * |    @version        :   1.0.0                                                                                                       |
 * |    @tool_chain     :   GNU Tools for STM32                                                                                         |
 * |    @compiler       :   GCC                                                                                                         |
 * |    @C_standard     :   ISO C99 (-std=c99)                                                                                          |
 * |    @target         :   stm32f407VGTX                                                                                               |
 * |    @notes          :   None                                                                                                        |
 * |    @license        :   MIT License                                                                                                 |
 * |    @brief          :   this header file contains useful functions to interface with the Direct Memory Access Controller (DMA)      |
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
 * |    09/09/2023      1.0.0           Abdelrahman Mohamed Salem       Interface Created.                                              |
 * --------------------------------------------------------------------------------------------------------------------------------------
 */

#ifndef HAL_DMA_HEADER_H_
#define HAL_DMA_HEADER_H_

/******************************************************************************
 * Includes
 *******************************************************************************/

/**
 * @reason: contains standard integer definition
 */
#include "../../lib/stdint.h"

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
 * Typedefs
 *******************************************************************************/

/**
 * @enum: Hal_DMA_ErrStates_t
 * @brief: contains all possible errors that can result from dealing with the DMA.
 */
typedef enum
{
    HAL_DMA_OK,                 /**< it means everything has gone as intended so no errors*/
    HAL_DMA_ERR_INVALID_PARAMS, /**< it means that the supplied parameters of the function are invalid*/
    HAL_DMA_ERR_INVALID_CONFIG, /**< it means that the supplied configurations in the "DMA_config.h" file are incorrect*/
    HAL_DMA_ADDR_NOT_ALIGNED,   /**< it means that the passed address to the function isn't aligned to address boundary given in configuration meaning that if data size is word (4-byte) then the passed address has to be 4-byte aligned*/

} HAL_DMA_ErrStates_t;

/******************************************************************************
 * Variables
 *******************************************************************************/

/******************************************************************************
 * Function Prototypes
 *******************************************************************************/

// only Each stream also supports software trigger for memory-to-memory transfers (only
// available for the DMA2 controller)

// The DMA1 controller AHB peripheral port is not connected to the bus matrix like DMA2 controller. As a result, only DMA2
// streams are able to perform memory-to-memory transfers.

/**
 *  \b function                                 :       HAL_DMA_BootFrom(const uint8_t argConst_u8MemoryType)
 *  \b Description                              :       this functions is used to boot from a specific memory.
 *  @param  argConst_u8MemoryType [IN]          :       this is input parameter and for possible values refer to @HAL_DMA_BootMem_t in "DMA_header.h", used to tell the function from which function to boot.
 *  @note                                       :       THE FUNCTION ISN'T COMPLETE YET.
 *  \b PRE-CONDITION                            :       None.
 *  \b POST-CONDITION                           :       MCU boots from the selected memory.
 *  @return                                     :       it return one of error states indicating whether a failure or success happened (refer to @HAL_DMA_ErrStates_t in "DMA_header.h")
 *  @see                                        :       None
 *
 *  \b Example:
 * @code
 * #include "DMA_header.h"
 * int main() {
 *  HAL_DMA_ErrStates_t local_errState_t = HAL_DMA_BootFrom(HAL_BOOT_MEM_SYSTEM_FLASH);
 *  if (local_errState_t != HAL_DMA_OK)
 *  {
 *      // if the function returned thus means it failed.
 *  }
 *  return 0;
 * }
 * @endcode
 *
 * <br><b> - HISTORY OF CHANGES - </b>
 * <table align="left" style="width:800px">
 * <tr><td> Date       </td><td> Software Version </td><td> Initials </td><td> Description </td></tr>
 * <tr><td> 04/09/2023 </td><td> 1.0.0            </td><td> AMS      </td><td> Interface Created </td></tr>
 * </table><br><br>
 * <hr>
 */
// HAL_DMA_ErrStates_t HAL_DMA_BootFrom(const uint8_t argConst_u8MemoryType);

/*** End of File **************************************************************/
#endif /*HAL_DMA_HEADER_H_*/