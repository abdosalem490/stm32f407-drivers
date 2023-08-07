/**
 * --------------------------------------------------------------------------------------------------------------------------------------
 * |    @title          :   Flash                                                                                                       |
 * |    @file           :   Flash_header.h                                                                                              |
 * |    @author         :   Abdelrahman Mohamed Salem                                                                                   |
 * |    @origin_date    :   01/08/2023                                                                                                  |
 * |    @version        :   1.0.0                                                                                                       |
 * |    @tool_chain     :   GNU Tools for STM32                                                                                         |
 * |    @compiler       :   GCC                                                                                                         |
 * |    @C_standard     :   ISO C99 (-std=c99)                                                                                          |
 * |    @target         :   stm32f407VGTX                                                                                               |
 * |    @notes          :   None                                                                                                        |
 * |    @license        :   MIT License                                                                                                 |
 * |    @brief          :   this header file contains useful functions to interface with the embedded flash memory inside stm32f407     |
 * |                        common to cortex-M4 microprocessors with FPU.                                                               |
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
 * |    01/08/2023      1.0.0           Abdelrahman Mohamed Salem       Interface Created.                                              |
 * --------------------------------------------------------------------------------------------------------------------------------------
 */

/******************************************************************************
 * Includes
 *******************************************************************************/
/**
 * @reason: contains standard definitions for standard integers
 */
#include "../../lib/stdint.h"

/**
 * @reason: contains definition for NULL
 */
#include "../../lib/common.h"

/**
 * @reason: contains constants common values
 */
#include "../../lib/constants.h"

/**
 * @reason: contains useful functions that deals with bit level math
 */
#include "../../math_btt.h"

/**
 * @reason: contains all initial user configurations for flash
 */
#include "flash_config.h"

/**
 * @reason: contains all the interface functions to be implemented
 */
#include "flash_header.h"

/**
 * @reason: contains all register addresses and bit definitions for embedded flash configuration registers
 */
#include "flash_reg.h"

/**
 * @reason: contains all private function declaration and global variables
 */
#include "flash_private.h"

/******************************************************************************
 * Module Preprocessor Constants
 *******************************************************************************/

/******************************************************************************
 * Module Preprocessor Macros
 *******************************************************************************/

/******************************************************************************
 * Module Typedefs
 *******************************************************************************/

/******************************************************************************
 * Module Variable Definitions
 *******************************************************************************/

/******************************************************************************
 * Function Prototypes
 *******************************************************************************/

/******************************************************************************
 * Function Definitions
 *******************************************************************************/

/**
 *
 */
HAL_FLASH_ErrStates_t HAL_FLASH_Init()
{
    // local used variables
    uint16_t local_u16TempVal = 0;
    uint8_t local_u32Counter = 0;
    uint8_t local_u8SectorsLength = sizeof globalConstArr_SectorsConfig_t / sizeof globalConstArr_SectorsConfig_t[0];
    HAL_FLASH_ErrStates_t local_errState_t = HAL_FLASH_OK;

    // check for errors
    for (local_u32Counter = 0; local_u32Counter < local_u8SectorsLength; i++) // if you want to improve code, unroll this for loop for 11 lines of code
    {
        if (globalConstArr_SectorsConfig_t[local_u32Counter].WriteProtection >= LIB_CONSTANTS_MAX_DRIVER_STATE || globalConstArr_SectorsConfig_t[local_u32Counter].SectorNumber >= HAL_FLASH_MAX_MAIN_MEM_SECTOR)
        {
            local_errState_t = HAL_FLASH_ERR_INVALID_CONFIG;
            break;
        }
        else
        {
            // do nothing
        }
    }
    if (globalConstArr_FlashConfig_t[0].DataCacheEnabled >= LIB_CONSTANTS_MAX_DRIVER_STATE || globalConstArr_FlashConfig_t[0].InstructionCacheEnabled >= LIB_CONSTANTS_MAX_DRIVER_STATE || globalConstArr_FlashConfig_t[0].PrefetchEnabled >= LIB_CONSTANTS_MAX_DRIVER_STATE || globalConstArr_FlashConfig_t[0].WaitStates >= HAL_FLASH_MAX_WAIT_STATE || globalConstArr_FlashConfig_t[0].LockConfiguration >= LIB_CONSTANTS_MAX_LOCK_STATE || globalConstArr_FlashConfig_t[0].InterruptsEnabled >= LIB_CONSTANTS_MAX_DRIVER_STATE || globalConstArr_FlashConfig_t[0].ProgramSize >= HAL_FLASH_MAX_PROGRAM_SIZE || globalConstArr_FlashConfig_t[0].ReadProtectionLevel >= HAL_FLASH_MAX_READ_PROTECT_LVL || globalConstArr_MiscellaneousConfig_t[0].ResetOnStandBy >= LIB_CONSTANTS_MAX_DRIVER_STATE || globalConstArr_MiscellaneousConfig_t[0].ResetOnStop >= LIB_CONSTANTS_MAX_DRIVER_STATE || globalConstArr_MiscellaneousConfig_t[0].IndependentWatchDogType >= HAL_FLASH_MAX_INDPEND_WATCH_DOG_TYPE || globalConstArr_MiscellaneousConfig_t[0].BrownoutResetLevel >= HAL_FLASH_MAX_BROWN_RESET_LVL)
    {
        local_errState_t = HAL_FLASH_ERR_INVALID_CONFIG;
    }
    else
    {
        // do nothing
    }

    // check for busy wait or not
    local_errState_t = HAL_FLASH_GetHardwareErrors();
    if (local_errState_t == HAL_FLASH_ERR_FLASH_BUSY && globalConstArr_FlashConfig_t[0].InterruptsEnabled == LIB_CONSTANTS_DISABLED)
    {
        // busy wait
        while (LIB_MATH_BTT_GET_BIT(global_pFlashReg_t->FLASH_SR, HAL_FLASH_SR_BSY) == 1)
        {
        };
        local_errState_t = HAL_FLASH_OK;
    }

    // main function
    if (local_errState_t == HAL_FLASH_OK)
    {
        // unlock all configuration registers
        global_pFlashReg_t->FLASH_KEYR = HAL_FLASH_CR_KEY1;
        global_pFlashReg_t->FLASH_KEYR = HAL_FLASH_CR_KEY2;
        global_pFlashReg_t->FLASH_OPTKEYR = HAL_FLASH_OPTCR_OPTKEY1;
        global_pFlashReg_t->FLASH_KEYR = HAL_FLASH_OPTCR_OPTKEY2;

        // assign global configuration variables
        global_u8BehaviorType = globalConstArr_FlashConfig_t[0].InterruptsEnabled == LIB_CONSTANTS_ENABLED ? HAL_FLASH_CONFIG_VAL_OPERATION_TYPE_INTERRUPT : HAL_FLASH_CONFIG_VAL_OPERATION_TYPE_BLOCKING;

        // configure flash & sectors
        LIB_MATH_BTT_ASSIGN_BIT(global_pFlashReg_t->FLASH_ACR, HAL_FLASH_ACR_DCEN, globalConstArr_FlashConfig_t[0].DataCacheEnabled);
        LIB_MATH_BTT_ASSIGN_BIT(global_pFlashReg_t->FLASH_ACR, HAL_FLASH_ACR_ICEN, globalConstArr_FlashConfig_t[0].InstructionCacheEnabled);
        LIB_MATH_BTT_ASSIGN_BIT(global_pFlashReg_t->FLASH_ACR, HAL_FLASH_ACR_PRFTEN, globalConstArr_FlashConfig_t[0].PrefetchEnabled);
        LIB_MATH_BTT_ASSIGN_BITS(global_pFlashReg_t->FLASH_ACR, HAL_FLASH_ACR_LATENCY, globalConstArr_FlashConfig_t[0].WaitStates, 3);
        LIB_MATH_BTT_ASSIGN_BIT(global_pFlashReg_t->FLASH_CR, HAL_FLASH_CR_ERRIE, globalConstArr_FlashConfig_t[0].InterruptsEnabled);
        LIB_MATH_BTT_ASSIGN_BIT(global_pFlashReg_t->FLASH_CR, HAL_FLASH_CR_EOPIE, globalConstArr_FlashConfig_t[0].InterruptsEnabled);
        LIB_MATH_BTT_ASSIGN_BITS(global_pFlashReg_t->FLASH_CR, HAL_FLASH_CR_PSIZE, globalConstArr_FlashConfig_t[0].ProgramSize, 2);
        LIB_MATH_BTT_ASSIGN_BITS(global_pFlashReg_t->FLASH_OPTCR, HAL_FLASH_OPTCR_RDP, globalConstArr_FlashConfig_t[0].ReadProtectionLevel, 8);

        for (local_u32Counter = 0; local_u32Counter < local_u8SectorsLength; i++) // if you want to improve code, unroll this for loop for 11 lines of code
        {
            local_u16TempVal |= (!globalConstArr_SectorsConfig_t[local_u32Counter].WriteProtection << globalConstArr_SectorsConfig_t[local_u32Counter].SectorNumber);
        }
        LIB_MATH_BTT_ASSIGN_BITS(global_pFlashReg_t->FLASH_OPTCR, HAL_FLASH_OPTCR_nWRP, local_u16TempVal, 12);

        LIB_MATH_BTT_ASSIGN_BIT(global_pFlashReg_t->FLASH_OPTCR, HAL_FLASH_OPTCR_nRST_STDBY, !globalConstArr_MiscellaneousConfig_t[0].ResetOnStandBy);
        LIB_MATH_BTT_ASSIGN_BIT(global_pFlashReg_t->FLASH_OPTCR, HAL_FLASH_OPTCR_nRST_STOP, !globalConstArr_MiscellaneousConfig_t[0].ResetOnStop);
        LIB_MATH_BTT_ASSIGN_BIT(global_pFlashReg_t->FLASH_OPTCR, HAL_FLASH_OPTCR_WDG_SW, !globalConstArr_MiscellaneousConfig_t[0].IndependentWatchDogType);
        LIB_MATH_BTT_ASSIGN_BITS(global_pFlashReg_t->FLASH_OPTCR, HAL_FLASH_OPTCR_BOR_LEV, globalConstArr_MiscellaneousConfig_t[0].BrownoutResetLevel, 2);
        LIB_MATH_BTT_SET_BIT(global_pFlashReg_t->FLASH_OPTCR, HAL_FLASH_OPTCR_OPTSTRT);

        // lock configuration if configured
        LIB_MATH_BTT_ASSIGN_BIT(global_pFlashReg_t->FLASH_CR, HAL_FLASH_CR_LOCK, globalConstArr_FlashConfig_t[0].LockConfiguration);
        LIB_MATH_BTT_ASSIGN_BIT(global_pFlashReg_t->FLASH_OPTCR, HAL_FLASH_OPTCR_OPTLOCK, globalConstArr_FlashConfig_t[0].LockConfiguration);

        // check for errors
        local_errState_t = HAL_FLASH_GetHardwareErrors();
        if (local_errState_t == HAL_FLASH_ERR_FLASH_BUSY && globalConstArr_FlashConfig_t[0].InterruptsEnabled == LIB_CONSTANTS_DISABLED)
        {
            // busy wait
            while (LIB_MATH_BTT_GET_BIT(global_pFlashReg_t->FLASH_SR, HAL_FLASH_SR_BSY) == 1)
            {
            };
            local_errState_t = HAL_FLASH_OK;
        }
        local_errState_t = HAL_FLASH_ERR_FLASH_BUSY ? HAL_FLASH_OK : local_errState_t;
    }

    return local_errState_t;
}

/**
 *
 */
HAL_FLASH_ErrStates_t HAL_FLASH_Erase(uint16_t arg_u8SectorNum)
{
    // local used variables
    HAL_FLASH_ErrStates_t local_errState_t = HAL_FLASH_OK;
    uint8_t local_u8sectorBitPos = 0;

    // check for errors
    if (arg_u8SectorNum >= HAL_FLASH_MAX_MAIN_MEM_SECTOR)
    {
        local_errState_t = HAL_FLASH_ERR_INVALID_PARAMS;
    }

    // check for busy wait or not
    local_errState_t = HAL_FLASH_GetHardwareErrors();
    if (local_errState_t == HAL_FLASH_ERR_FLASH_BUSY && global_u8BehaviorType == HAL_FLASH_CONFIG_VAL_OPERATION_TYPE_BLOCKING)
    {
        // busy wait
        while (LIB_MATH_BTT_GET_BIT(global_pFlashReg_t->FLASH_SR, HAL_FLASH_SR_BSY) == 1)
        {
        };
        local_errState_t = HAL_FLASH_OK;
    }

    // main function
    if (local_errState_t == HAL_FLASH_OK)
    {
        // check for type of operation
        if (global_u8BehaviorType == HAL_FLASH_CONFIG_VAL_OPERATION_TYPE_BLOCKING)
        {
            // check for type of erase
            if (arg_u8SectorNum == HAL_FLASH_MAIN_MEM_ALL_SECTORS)
            {
                LIB_MATH_BTT_SET_BIT(global_pFlashReg_t->FLASH_CR, HAL_FLASH_CR_MER);
                LIB_MATH_BTT_SET_BIT(global_pFlashReg_t->FLASH_CR, HAL_FLASH_CR_STRT);
                while (LIB_MATH_BTT_GET_BIT(global_pFlashReg_t->FLASH_SR, HAL_FLASH_SR_BSY) == 1)
                {
                };
            }
            else
            {
                while (arg_u8SectorNum != 0)
                {
                    LIB_MATH_BTT_SET_BIT(global_pFlashReg_t->FLASH_CR, HAL_FLASH_CR_SER);
                    local_u8sectorBitPos = LIB_MATH_BTT_u8GetMSBSetPos(arg_u8SectorNum);
                    LIB_MATH_BTT_ASSIGN_BITS(global_pFlashReg_t->FLASH_CR, HAL_FLASH_CR_SNB, local_u8sectorBitPos, 4);
                    LIB_MATH_BTT_SET_BIT(global_pFlashReg_t->FLASH_CR, HAL_FLASH_CR_STRT);
                    while (LIB_MATH_BTT_GET_BIT(global_pFlashReg_t->FLASH_SR, HAL_FLASH_SR_BSY) == 1)
                    {
                    };
                    LIB_MATH_BTT_CLR_BIT(arg_u8SectorNum, local_u8sectorBitPos);
                }
            }

            // flush caches
            LIB_MATH_BTT_CLR_BIT(global_pFlashReg_t->FLASH_ACR, HAL_FLASH_ACR_DCEN);
            LIB_MATH_BTT_CLR_BIT(global_pFlashReg_t->FLASH_ACR, HAL_FLASH_ACR_ICEN);

            LIB_MATH_BTT_SET_BIT(global_pFlashReg_t->FLASH_ACR, HAL_FLASH_ACR_DCRST);
            LIB_MATH_BTT_SET_BIT(global_pFlashReg_t->FLASH_ACR, HAL_FLASH_ACR_ICRST);

            LIB_MATH_BTT_ASSIGN_BIT(global_pFlashReg_t->FLASH_ACR, HAL_FLASH_ACR_DCEN, globalConstArr_FlashConfig_t[0].DataCacheEnabled);
            LIB_MATH_BTT_ASSIGN_BIT(global_pFlashReg_t->FLASH_ACR, HAL_FLASH_ACR_ICEN, globalConstArr_FlashConfig_t[0].InstructionCacheEnabled);
        }
        else if (global_u8BehaviorType == HAL_FLASH_CONFIG_VAL_OPERATION_TYPE_INTERRUPT)
        {
            global_u8WhichOperationToExecute = HAL_FLASH_IRQ_OP_ERASE;

            // check for type of erase
            if (arg_u8SectorNum == HAL_FLASH_MAIN_MEM_ALL_SECTORS)
            {
                LIB_MATH_BTT_SET_BIT(global_pFlashReg_t->FLASH_CR, HAL_FLASH_CR_MER);
                LIB_MATH_BTT_SET_BIT(global_pFlashReg_t->FLASH_CR, HAL_FLASH_CR_STRT);
                global_u8SuccessOperationState = LIB_CONSTANTS_SUCCESS;
            }
            else
            {
                global_u16SectorsToErase = arg_u8SectorNum;
                LIB_MATH_BTT_SET_BIT(global_pFlashReg_t->FLASH_CR, HAL_FLASH_CR_SER);
                local_u8sectorBitPos = LIB_MATH_BTT_u8GetMSBSetPos(global_u16SectorsToErase);
                LIB_MATH_BTT_ASSIGN_BITS(global_pFlashReg_t->FLASH_CR, HAL_FLASH_CR_SNB, local_u8sectorBitPos, 4);
                LIB_MATH_BTT_SET_BIT(global_pFlashReg_t->FLASH_CR, HAL_FLASH_CR_STRT);
                LIB_MATH_BTT_CLR_BIT(global_u16SectorsToErase, local_u8sectorBitPos);
            }
        }
        else
        {
            local_errState_t = HAL_FLASH_ERR_INVALID_CONFIG;
        }
    }

    if (local_errState_t == HAL_FLASH_OK)
    {
        local_errState_t = HAL_FLASH_GetHardwareErrors();
    }
    else
    {
        // do nothing
    }

    return local_errState_t;
}

/**
 *
 */
HAL_FLASH_ErrStates_t HAL_FLASH_Write(const uint32_t argConst_u32BaseAddress, uint32_t arg_u32DataLen, const uint8_t *argConst_pu8WriteData)
{
    // local used variables
    HAL_FLASH_ErrStates_t local_errState_t = HAL_FLASH_OK;

    // check for errors
    if (!((argConst_u32BaseAddress >= HAL_FLASH_MAIN_MEM_SECTOR_0_BASEADDR && argConst_u32BaseAddress <= (HAL_FLASH_MAIN_MEM_SECTOR_11_BASEADDR + HAL_FLASH_MAIN_MEM_SECTOR_11_SIZE)) ||
          argConst_u32BaseAddress >= HAL_FLASH_OTP_BLOCK_0_BASEADDR && argConst_u32BaseAddress <= (HAL_FLASH_OTP_BLOCK_15_BASEADDR + HAL_FLASH_OPT_BLOCK_SIZE)))
    {
        local_errState_t = HAL_FLASH_ERR_OUT_OF_RANGE;
    }
    else if ((argConst_u32BaseAddress <= (HAL_FLASH_MAIN_MEM_SECTOR_11_BASEADDR + HAL_FLASH_MAIN_MEM_SECTOR_11_SIZE) && (argConst_u32BaseAddress + argConst_u32DataLen) > (HAL_FLASH_MAIN_MEM_SECTOR_11_BASEADDR + HAL_FLASH_MAIN_MEM_SECTOR_11_SIZE)) ||
             argConst_u32BaseAddress <= (HAL_FLASH_OTP_BLOCK_15_BASEADDR + HAL_FLASH_OPT_BLOCK_SIZE) && (argConst_u32BaseAddress + argConst_u32DataLen) > (HAL_FLASH_OTP_BLOCK_15_BASEADDR + HAL_FLASH_OPT_BLOCK_SIZE))
    {
        local_errState_t = HAL_FLASH_ERR_NOT_ENOUGH_MEM;
    }
    else if (argConst_pu8WriteData == NULL)
    {
        local_errState_t = HAL_FLASH_ERR_INVALID_PARAMS;
    }
    else
    {
        // do nothing
    }

    // check for busy wait or not
    local_errState_t = HAL_FLASH_GetHardwareErrors();
    if (local_errState_t == HAL_FLASH_ERR_FLASH_BUSY && global_u8BehaviorType == HAL_FLASH_CONFIG_VAL_OPERATION_TYPE_BLOCKING)
    {
        // busy wait
        while (LIB_MATH_BTT_GET_BIT(global_pFlashReg_t->FLASH_SR, HAL_FLASH_SR_BSY) == 1)
        {
        };
        local_errState_t = HAL_FLASH_OK;
    }

    // main function
    if (local_errState_t == HAL_FLASH_OK)
    {
        // assign some values
        global_pu8MemWriteVar = (uint8_t *)argConst_u32BaseAddress;
        global_pu16MemWriteVar = (uint16_t *)argConst_u32BaseAddress;
        global_pu32MemWriteVar = (uint32_t *)argConst_u32BaseAddress;
        global_pu64MemWriteVar = (uint64_t *)argConst_u32BaseAddress;

        // check for type of operation
        if (global_u8BehaviorType == HAL_FLASH_CONFIG_VAL_OPERATION_TYPE_BLOCKING)
        {

            if (globalConstArr_FlashConfig_t[0].ProgramSize == HAL_FLASH_PROGRAM_SIZE_X8)
            {

                for (; arg_u32DataLen > 0; arg_u32DataLen -= 1)
                {
                    LIB_MATH_BTT_SET_BIT(global_pFlashReg_t->CR, HAL_FLASH_CR_PG);

                    *global_pu8MemWriteVar = *(uint8_t *)argConst_pu8WriteData;
                    global_pu8MemWriteVar++;
                    argConst_pu8WriteData += 1;

                    while (LIB_MATH_BTT_GET_BIT(global_pFlashReg_t->FLASH_SR, HAL_FLASH_SR_BSY) == 1)
                    {
                    };
                }
            }
            else if (globalConstArr_FlashConfig_t[0].ProgramSize == HAL_FLASH_PROGRAM_SIZE_X16)
            {

                for (; arg_u32DataLen > 0; arg_u32DataLen -= 2)
                {
                    LIB_MATH_BTT_SET_BIT(global_pFlashReg_t->CR, HAL_FLASH_CR_PG);

                    *global_pu16MemWriteVar = *(uint16_t *)argConst_pu8WriteData;
                    global_pu16MemWriteVar++;
                    argConst_pu8WriteData += 2;

                    while (LIB_MATH_BTT_GET_BIT(global_pFlashReg_t->FLASH_SR, HAL_FLASH_SR_BSY) == 1)
                    {
                    };
                }
            }
            else if (globalConstArr_FlashConfig_t[0].ProgramSize == HAL_FLASH_PROGRAM_SIZE_X32)
            {

                for (; arg_u32DataLen > 0; arg_u32DataLen -= 4)
                {
                    LIB_MATH_BTT_SET_BIT(global_pFlashReg_t->CR, HAL_FLASH_CR_PG);

                    *global_pu32MemWriteVar = *(uint32_t *)argConst_pu8WriteData;
                    global_pu32MemWriteVar++;
                    argConst_pu8WriteData += 4;

                    while (LIB_MATH_BTT_GET_BIT(global_pFlashReg_t->FLASH_SR, HAL_FLASH_SR_BSY) == 1)
                    {
                    };
                }
            }
            else if (globalConstArr_FlashConfig_t[0].ProgramSize == HAL_FLASH_PROGRAM_SIZE_X64)
            {

                for (; arg_u32DataLen > 0; arg_u32DataLen -= 8)
                {
                    LIB_MATH_BTT_SET_BIT(global_pFlashReg_t->CR, HAL_FLASH_CR_PG);

                    *global_pu64MemWriteVar = *(uint64_t *)argConst_pu8WriteData;
                    global_pu32MemWriteVar++;
                    argConst_pu8WriteData += 8;

                    while (LIB_MATH_BTT_GET_BIT(global_pFlashReg_t->FLASH_SR, HAL_FLASH_SR_BSY) == 1)
                    {
                    };
                }
            }
            else
            {
                local_errState_t = HAL_FLASH_ERR_INVALID_CONFIG;
            }

            // reset values
            global_pu8MemWriteVar = NULL;
            global_pu16MemWriteVar = NULL;
            global_pu32MemWriteVar = NULL;
            global_pu64MemWriteVar = NULL;
        }
        else if (global_u8BehaviorType == HAL_FLASH_CONFIG_VAL_OPERATION_TYPE_INTERRUPT)
        {
            global_u32DataLen = arg_u32DataLen;
            globalConst_pu8WriteData = argConst_pu8WriteData;
            global_u8WhichOperationToExecute = HAL_FLASH_IRQ_OP_WRITE;

            LIB_MATH_BTT_SET_BIT(global_pFlashReg_t->CR, HAL_FLASH_CR_PG);
            if (globalConstArr_FlashConfig_t[0].ProgramSize == HAL_FLASH_PROGRAM_SIZE_X8)
            {
                *global_pu8MemWriteVar = *(uint8_t *)globalConst_pu8WriteData;
                global_pu8MemWriteVar++;
                globalConst_pu8WriteData += 1;
                global_u32DataLen -= 1;
            }
            else if (globalConstArr_FlashConfig_t[0].ProgramSize == HAL_FLASH_PROGRAM_SIZE_X16)
            {
                *global_pu16MemWriteVar = *(uint16_t *)globalConst_pu8WriteData;
                global_pu16MemWriteVar++;
                globalConst_pu8WriteData += 2;
                global_u32DataLen -= 2;
            }
            else if (globalConstArr_FlashConfig_t[0].ProgramSize == HAL_FLASH_PROGRAM_SIZE_X32)
            {
                *global_pu32MemWriteVar = *(uint32_t *)globalConst_pu8WriteData;
                global_pu32MemWriteVar++;
                globalConst_pu8WriteData += 4;
                global_u32DataLen -= 4;
            }
            else if (globalConstArr_FlashConfig_t[0].ProgramSize == HAL_FLASH_PROGRAM_SIZE_X64)
            {
                *global_pu64MemWriteVar = *(uint64_t *)globalConst_pu8WriteData;
                global_pu32MemWriteVar++;
                globalConst_pu8WriteData += 8;
                global_u32DataLen -= 8;
            }
            else
            {
                local_errState_t = HAL_FLASH_ERR_INVALID_CONFIG;
            }
        }
        else
        {
            local_errState_t = HAL_FLASH_ERR_INVALID_CONFIG;
        }
    }

    return local_errState_t;
}

/**
 *
 */
HAL_FLASH_ErrStates_t HAL_FLASH_OTPFuse(uint16_t arg_u32OTPBlockNum)
{
    // local used variables
    HAL_FLASH_ErrStates_t local_errState_t = HAL_FLASH_OK;
    uint8_t local_u8MSBSetPos = 0;
    uint8_t *local_pu8LockAddr = NULL;

    if (arg_u32OTPBlockNum > HAL_FLASH_MAX_OTP_SECTOR)
    {
        local_errState_t = HAL_FLASH_ERR_INVALID_PARAMS;
    }
    else
    {
        // do nothing
    }

    // check for busy wait or not
    local_errState_t = HAL_FLASH_GetHardwareErrors();
    if (local_errState_t == HAL_FLASH_ERR_FLASH_BUSY && global_u8BehaviorType == HAL_FLASH_CONFIG_VAL_OPERATION_TYPE_BLOCKING)
    {
        // busy wait
        while (LIB_MATH_BTT_GET_BIT(global_pFlashReg_t->FLASH_SR, HAL_FLASH_SR_BSY) == 1)
        {
        };
        local_errState_t = HAL_FLASH_OK;
    }

    // main function
    if (local_errState_t == HAL_FLASH_OK)
    {
        while (arg_u32OTPBlockNum != 0)
        {
            local_u8MSBSetPos = LIB_MATH_BTT_u8GetMSBSetPos(arg_u32OTPBlockNum);
            LIB_MATH_BTT_CLR_BIT(arg_u32OTPBlockNum, local_u8MSBSetPos);
            local_pu8LockAddr = (uint8_t *)(HAL_FLASH_OTP_LOCK_BASEADDR + 8 * local_u8MSBSetPos);
            *local_pu8LockAddr = 0x00;
        }
    }

    return local_errState_t;
}

/**
 *
 */
HAL_FLASH_ErrStates_t HAL_FLASH_Fill(const uint32_t argConst_u32BaseAddress, uint32_t arg_u32AddressLen, const uint8_t argConst_u8WriteData)
{
    // local used variables
    HAL_FLASH_ErrStates_t local_errState_t = HAL_FLASH_OK;

    // check for errors
    if (!((argConst_u32BaseAddress >= HAL_FLASH_MAIN_MEM_SECTOR_0_BASEADDR && argConst_u32BaseAddress <= (HAL_FLASH_MAIN_MEM_SECTOR_11_BASEADDR + HAL_FLASH_MAIN_MEM_SECTOR_11_SIZE)) ||
          argConst_u32BaseAddress >= HAL_FLASH_OTP_BLOCK_0_BASEADDR && argConst_u32BaseAddress <= (HAL_FLASH_OTP_BLOCK_15_BASEADDR + HAL_FLASH_OPT_BLOCK_SIZE)))
    {
        local_errState_t = HAL_FLASH_ERR_OUT_OF_RANGE;
    }
    else if ((argConst_u32BaseAddress <= (HAL_FLASH_MAIN_MEM_SECTOR_11_BASEADDR + HAL_FLASH_MAIN_MEM_SECTOR_11_SIZE) && (argConst_u32BaseAddress + arg_u32AddressLen) > (HAL_FLASH_MAIN_MEM_SECTOR_11_BASEADDR + HAL_FLASH_MAIN_MEM_SECTOR_11_SIZE)) ||
             argConst_u32BaseAddress <= (HAL_FLASH_OTP_BLOCK_15_BASEADDR + HAL_FLASH_OPT_BLOCK_SIZE) && (argConst_u32BaseAddress + arg_u32AddressLen) > (HAL_FLASH_OTP_BLOCK_15_BASEADDR + HAL_FLASH_OPT_BLOCK_SIZE))
    {
        local_errState_t = HAL_FLASH_ERR_NOT_ENOUGH_MEM;
    }
    else
    {
        // do nothing
    }

    // check for busy wait or not
    local_errState_t = HAL_FLASH_GetHardwareErrors();
    if (local_errState_t == HAL_FLASH_ERR_FLASH_BUSY && global_u8BehaviorType == HAL_FLASH_CONFIG_VAL_OPERATION_TYPE_BLOCKING)
    {
        // busy wait
        while (LIB_MATH_BTT_GET_BIT(global_pFlashReg_t->FLASH_SR, HAL_FLASH_SR_BSY) == 1)
        {
        };
        local_errState_t = HAL_FLASH_OK;
    }

    // main function
    if (local_errState_t == HAL_FLASH_OK)
    {
        // assign some values
        global_pu8MemWriteVar = (uint8_t *)argConst_u32BaseAddress;
        global_pu16MemWriteVar = (uint16_t *)argConst_u32BaseAddress;
        global_pu32MemWriteVar = (uint32_t *)argConst_u32BaseAddress;
        global_pu64MemWriteVar = (uint64_t *)argConst_u32BaseAddress;

        // check for type of operation
        if (global_u8BehaviorType == HAL_FLASH_CONFIG_VAL_OPERATION_TYPE_BLOCKING)
        {

            if (globalConstArr_FlashConfig_t[0].ProgramSize == HAL_FLASH_PROGRAM_SIZE_X8)
            {

                for (; arg_u32AddressLen > 0; arg_u32AddressLen -= 1)
                {
                    LIB_MATH_BTT_SET_BIT(global_pFlashReg_t->CR, HAL_FLASH_CR_PG);

                    *global_pu8MemWriteVar = (uint8_t)argConst_u8WriteData;
                    global_pu8MemWriteVar++;

                    while (LIB_MATH_BTT_GET_BIT(global_pFlashReg_t->FLASH_SR, HAL_FLASH_SR_BSY) == 1)
                    {
                    };
                }
            }
            else if (globalConstArr_FlashConfig_t[0].ProgramSize == HAL_FLASH_PROGRAM_SIZE_X16)
            {

                for (; arg_u32AddressLen > 0; arg_u32AddressLen -= 2)
                {
                    LIB_MATH_BTT_SET_BIT(global_pFlashReg_t->CR, HAL_FLASH_CR_PG);

                    *global_pu16MemWriteVar = (uint16_t)(argConst_u8WriteData | argConst_u8WriteData << 8);
                    global_pu16MemWriteVar++;

                    while (LIB_MATH_BTT_GET_BIT(global_pFlashReg_t->FLASH_SR, HAL_FLASH_SR_BSY) == 1)
                    {
                    };
                }
            }
            else if (globalConstArr_FlashConfig_t[0].ProgramSize == HAL_FLASH_PROGRAM_SIZE_X32)
            {

                for (; arg_u32AddressLen > 0; arg_u32AddressLen -= 4)
                {
                    LIB_MATH_BTT_SET_BIT(global_pFlashReg_t->CR, HAL_FLASH_CR_PG);

                    *global_pu32MemWriteVar = (uint32_t)(argConst_u8WriteData | argConst_u8WriteData << 8 | argConst_u8WriteData << 16 | argConst_u8WriteData << 24);
                    global_pu32MemWriteVar++;

                    while (LIB_MATH_BTT_GET_BIT(global_pFlashReg_t->FLASH_SR, HAL_FLASH_SR_BSY) == 1)
                    {
                    };
                }
            }
            else if (globalConstArr_FlashConfig_t[0].ProgramSize == HAL_FLASH_PROGRAM_SIZE_X64)
            {

                for (; arg_u32AddressLen > 0; arg_u32AddressLen -= 8)
                {
                    LIB_MATH_BTT_SET_BIT(global_pFlashReg_t->CR, HAL_FLASH_CR_PG);

                    *global_pu64MemWriteVar = (uint64_t)(argConst_u8WriteData | argConst_u8WriteData << 8 | argConst_u8WriteData << 16 | argConst_u8WriteData << 24 | argConst_u8WriteData << 32 | argConst_u8WriteData << 40 | argConst_u8WriteData << 48 | argConst_u8WriteData << 56);
                    global_pu32MemWriteVar++;

                    while (LIB_MATH_BTT_GET_BIT(global_pFlashReg_t->FLASH_SR, HAL_FLASH_SR_BSY) == 1)
                    {
                    };
                }
            }
            else
            {
                local_errState_t = HAL_FLASH_ERR_INVALID_CONFIG;
            }

            // reset values
            global_pu8MemWriteVar = NULL;
            global_pu16MemWriteVar = NULL;
            global_pu32MemWriteVar = NULL;
            global_pu64MemWriteVar = NULL;
        }
        else if (global_u8BehaviorType == HAL_FLASH_CONFIG_VAL_OPERATION_TYPE_INTERRUPT)
        {
            global_u32DataLen = arg_u32AddressLen;
            global_u8WriteData = argConst_u8WriteData;
            global_u8WhichOperationToExecute = HAL_FLASH_IRQ_OP_WRITE;

            LIB_MATH_BTT_SET_BIT(global_pFlashReg_t->CR, HAL_FLASH_CR_PG);
            if (globalConstArr_FlashConfig_t[0].ProgramSize == HAL_FLASH_PROGRAM_SIZE_X8)
            {
                *global_pu8MemWriteVar = (uint8_t)global_u8WriteData;
                global_pu8MemWriteVar++;
                global_u32DataLen -= 1;
            }
            else if (globalConstArr_FlashConfig_t[0].ProgramSize == HAL_FLASH_PROGRAM_SIZE_X16)
            {
                *global_pu16MemWriteVar = (uint16_t)(argConst_u8WriteData | argConst_u8WriteData << 8);
                global_pu16MemWriteVar++;
                global_u32DataLen -= 2;
            }
            else if (globalConstArr_FlashConfig_t[0].ProgramSize == HAL_FLASH_PROGRAM_SIZE_X32)
            {
                *global_pu32MemWriteVar = (uint32_t)(argConst_u8WriteData | argConst_u8WriteData << 8 | argConst_u8WriteData << 16 | argConst_u8WriteData << 24);
                global_pu32MemWriteVar++;
                global_u32DataLen -= 4;
            }
            else if (globalConstArr_FlashConfig_t[0].ProgramSize == HAL_FLASH_PROGRAM_SIZE_X64)
            {
                *global_pu64MemWriteVar = (uint64_t)(argConst_u8WriteData | argConst_u8WriteData << 8 | argConst_u8WriteData << 16 | argConst_u8WriteData << 24 | argConst_u8WriteData << 32 | argConst_u8WriteData << 40 | argConst_u8WriteData << 48 | argConst_u8WriteData << 56);
                global_pu32MemWriteVar++;
                global_u32DataLen -= 8;
            }
            else
            {
                local_errState_t = HAL_FLASH_ERR_INVALID_CONFIG;
            }
        }
        else
        {
            local_errState_t = HAL_FLASH_ERR_INVALID_CONFIG;
        }
    }

    return local_errState_t;
}

/**
 *
 */
HAL_FLASH_ErrStates_t HAL_FLASH_Read(const uint32_t argConst_u32BaseAddress, uint32_t arg_u32DataLen, uint8_t *arg_pu8ReadData)
{
    // local used variables
    HAL_FLASH_ErrStates_t local_errState_t = HAL_FLASH_OK;
    uint8_t *local_pu8FlashAddr = (uint8_t *)argConst_u32BaseAddress;

    // check for errors
    if (!((argConst_u32BaseAddress >= HAL_FLASH_MAIN_MEM_SECTOR_0_BASEADDR && argConst_u32BaseAddress <= (HAL_FLASH_MAIN_MEM_SECTOR_11_BASEADDR + HAL_FLASH_MAIN_MEM_SECTOR_11_SIZE)) ||
          argConst_u32BaseAddress >= HAL_FLASH_OTP_BLOCK_0_BASEADDR && argConst_u32BaseAddress <= (HAL_FLASH_OTP_BLOCK_15_BASEADDR + HAL_FLASH_OPT_BLOCK_SIZE)))
    {
        local_errState_t = HAL_FLASH_ERR_OUT_OF_RANGE;
    }
    else if ((argConst_u32BaseAddress <= (HAL_FLASH_MAIN_MEM_SECTOR_11_BASEADDR + HAL_FLASH_MAIN_MEM_SECTOR_11_SIZE) && (argConst_u32BaseAddress + arg_u32DataLen) > (HAL_FLASH_MAIN_MEM_SECTOR_11_BASEADDR + HAL_FLASH_MAIN_MEM_SECTOR_11_SIZE)) ||
             argConst_u32BaseAddress <= (HAL_FLASH_OTP_BLOCK_15_BASEADDR + HAL_FLASH_OPT_BLOCK_SIZE) && (argConst_u32BaseAddress + arg_u32DataLen) > (HAL_FLASH_OTP_BLOCK_15_BASEADDR + HAL_FLASH_OPT_BLOCK_SIZE))
    {
        local_errState_t = HAL_FLASH_ERR_NOT_ENOUGH_MEM;
    }
    else if (arg_pu8ReadData == NULL)
    {
        local_errState_t = HAL_FLASH_ERR_INVALID_PARAMS;
    }
    else
    {
        // do nothing
    }

    // main function
    local_errState_t = HAL_FLASH_GetHardwareErrors();
    if (local_errState_t == HAL_FLASH_OK)
    {
        for (; arg_u32DataLen > 0; arg_u32DataLen--)
        {
            *arg_pu8ReadData = *(uint8_t *)local_pu8FlashAddr;
            local_pu8FlashAddr++;
            arg_pu8ReadData++;
        }
    }

    return local_errState_t;
}

/**
 *
 */
HAL_FLASH_ErrStates_t HAL_FLASH_Config(const uint8_t argConst_u8Key, const uint8_t argConst_u8Value)
{
    // local used variables
    HAL_FLASH_ErrStates_t local_errState_t = HAL_FLASH_OK;

    // check for errors
    if (argConst_u8Key >= HAL_FLASH_MAX_CONFIG_KEY)
    {
        local_errState_t = HAL_FLASH_ERR_INVALID_PARAMS;
    }
    else if (argConst_u8Key == HAL_FLASH_CONFIG_KEY_OPERATION_TYPE)
    {
        if (argConst_u8Value >= HAL_FLASH_CONFIG_VAL_MAX_OPERATION_TYPE)
        {
            local_errState_t = HAL_FLASH_ERR_INVALID_PARAMS;
        }
        else
        {
            // do nothing
        }
    }
    else
    {
        // do nothing
    }

    // main function
    if (local_errState_t == HAL_FLASH_OK)
    {
        if (argConst_u8Key == HAL_FLASH_CONFIG_KEY_OPERATION_TYPE)
        {
            global_u8BehaviorType = argConst_u8Value;
        }
    }

    return local_errState_t;
}

/**
 *
 */
HAL_FLASH_ErrStates_t HAL_FLASH_RegisterCallback(const uint8_t argConst_u8CallBackType, const functionCallBack_t argConst_pFunctionCallBack)
{
    // local used variables
    HAL_FLASH_ErrStates_t local_errState_t = HAL_FLASH_OK;

    // check for errors
    if (argConst_u8CallBackType >= HAL_FLASH_MAX_CALLBACK_TYPE)
    {
        local_errState_t = HAL_FLASH_ERR_INVALID_PARAMS;
    }

    // main function
    if (local_errState_t == HAL_FLASH_OK)
    {
        if (LIB_MATH_BTT_GET_BIT(argConst_u8CallBackType, HAL_FLASH_CALLBACK_TYPE_SUCCESS) == 1)
        {
            global_pOperationSuccess_t = argConst_pFunctionCallBack;
        }
        else
        {
            // do nothing
        }

        if (LIB_MATH_BTT_GET_BIT(argConst_u8CallBackType, HAL_FLASH_CALLBACK_TYPE_ERR_WRITE_PROTECTION) == 1)
        {
            global_pErrWriteProtection_t = argConst_pFunctionCallBack;
        }
        else
        {
            // do nothing
        }

        if (LIB_MATH_BTT_GET_BIT(argConst_u8CallBackType, HAL_FLASH_CALLBACK_TYPE_ERR_PROGRAMMING_SEQUENCE) == 1)
        {
            global_pErrProgrammingSequence_t = argConst_pFunctionCallBack;
        }
        else
        {
            // do nothing
        }

        if (LIB_MATH_BTT_GET_BIT(argConst_u8CallBackType, HAL_FLASH_CALLBACK_TYPE_ERR_PROGRAMMING_PARALLELISM) == 1)
        {
            global_pErrProgrammingParallelism_t = argConst_pFunctionCallBack;
        }
        else
        {
            // do nothing
        }

        if (LIB_MATH_BTT_GET_BIT(argConst_u8CallBackType, HAL_FLASH_CALLBACK_TYPE_ERR_PROGRAMMING_ALIGNMENT) == 1)
        {
            global_pErrProgrammingAlignment_t = argConst_pFunctionCallBack;
        }
        else
        {
            // do nothing
        }

        if (LIB_MATH_BTT_GET_BIT(argConst_u8CallBackType, HAL_FLASH_CALLBACK_TYPE_ERR_OPERATION) == 1)
        {
            global_pErrOperation_t = argConst_pFunctionCallBack;
        }
        else
        {
            // do nothing
        }
    }

    return local_errState_t;
}

/**
 * @brief: that's the interrupt request Handler
 * @note: the name of this function is dependent on the startup code, so if you change the name of the interrupt request in the startup code, you shall change it here too
 */
void FLASH_IRQHandler(void)
{
    // check for which operation to execute
    if (global_u8WhichOperationToExecute == HAL_FLASH_IRQ_OP_ERASE) // check if there is sectors to erase
    {
        if (global_u16SectorsToErase == 0)
        {
            // flush caches
            LIB_MATH_BTT_CLR_BIT(global_pFlashReg_t->FLASH_ACR, HAL_FLASH_ACR_DCEN);
            LIB_MATH_BTT_CLR_BIT(global_pFlashReg_t->FLASH_ACR, HAL_FLASH_ACR_ICEN);

            LIB_MATH_BTT_SET_BIT(global_pFlashReg_t->FLASH_ACR, HAL_FLASH_ACR_DCRST);
            LIB_MATH_BTT_SET_BIT(global_pFlashReg_t->FLASH_ACR, HAL_FLASH_ACR_ICRST);

            LIB_MATH_BTT_ASSIGN_BIT(global_pFlashReg_t->FLASH_ACR, HAL_FLASH_ACR_DCEN, globalConstArr_FlashConfig_t[0].DataCacheEnabled);
            LIB_MATH_BTT_ASSIGN_BIT(global_pFlashReg_t->FLASH_ACR, HAL_FLASH_ACR_ICEN, globalConstArr_FlashConfig_t[0].InstructionCacheEnabled);

            global_u8SuccessOperationState = LIB_CONSTANTS_SUCCESS;
            global_u8WhichOperationToExecute = HAL_FLASH_IRQ_OP_NONE;
        }
        else
        {
            LIB_MATH_BTT_SET_BIT(global_pFlashReg_t->FLASH_CR, HAL_FLASH_CR_SER);
            uint8_t local_u8sectorBitPos = LIB_MATH_BTT_u8GetMSBSetPos(global_u16SectorsToErase);
            LIB_MATH_BTT_ASSIGN_BITS(global_pFlashReg_t->FLASH_CR, HAL_FLASH_CR_SNB, local_u8sectorBitPos, 4);
            LIB_MATH_BTT_SET_BIT(global_pFlashReg_t->FLASH_CR, HAL_FLASH_CR_STRT);
            LIB_MATH_BTT_CLR_BIT(global_u16SectorsToErase, local_u8sectorBitPos);
        }
    }
    else if (global_u8WhichOperationToExecute == HAL_FLASH_IRQ_OP_WRITE) // check if there is data to write
    {
        LIB_MATH_BTT_SET_BIT(global_pFlashReg_t->CR, HAL_FLASH_CR_PG);
        if (globalConstArr_FlashConfig_t[0].ProgramSize == HAL_FLASH_PROGRAM_SIZE_X8)
        {
            *global_pu8MemWriteVar = *(uint8_t *)globalConst_pu8WriteData;
            global_pu8MemWriteVar++;
            globalConst_pu8WriteData += 1;
            global_u32DataLen -= 1;
        }
        else if (globalConstArr_FlashConfig_t[0].ProgramSize == HAL_FLASH_PROGRAM_SIZE_X16)
        {
            *global_pu16MemWriteVar = *(uint16_t *)globalConst_pu8WriteData;
            global_pu16MemWriteVar++;
            globalConst_pu8WriteData += 2;
            global_u32DataLen -= 2;
        }
        else if (globalConstArr_FlashConfig_t[0].ProgramSize == HAL_FLASH_PROGRAM_SIZE_X32)
        {
            *global_pu32MemWriteVar = *(uint32_t *)globalConst_pu8WriteData;
            global_pu32MemWriteVar++;
            globalConst_pu8WriteData += 4;
            global_u32DataLen -= 4;
        }
        else if (globalConstArr_FlashConfig_t[0].ProgramSize == HAL_FLASH_PROGRAM_SIZE_X64)
        {
            *global_pu64MemWriteVar = *(uint64_t *)globalConst_pu8WriteData;
            global_pu32MemWriteVar++;
            globalConst_pu8WriteData += 8;
            global_u32DataLen -= 8;
        }
        else
        {
            local_errState_t = HAL_FLASH_ERR_INVALID_CONFIG;
        }
        else
        {
            // do nothing
        }

        if (global_u32DataLen <= 0)
        {
            global_pu8MemWriteVar = NULL;
            global_pu16MemWriteVar = NULL;
            global_pu32MemWriteVar = NULL;
            global_pu64MemWriteVar = NULL;
            globalConst_pu8WriteData = NULL;
            global_u32DataLen = 0;
            global_u8SuccessOperationState = LIB_CONSTANTS_SUCCESS;
            global_u8WhichOperationToExecute = HAL_FLASH_IRQ_OP_NONE;
        }
        else
        {
            // do nothing
        }
    }
    else if (global_u8WhichOperationToExecute == HAL_FLASH_IRQ_OP_FILL)
    {
        LIB_MATH_BTT_SET_BIT(global_pFlashReg_t->CR, HAL_FLASH_CR_PG);
        if (globalConstArr_FlashConfig_t[0].ProgramSize == HAL_FLASH_PROGRAM_SIZE_X8)
        {
            *global_pu8MemWriteVar = (uint8_t)global_u8WriteData;
            global_pu8MemWriteVar++;
            global_u32DataLen -= 1;
        }
        else if (globalConstArr_FlashConfig_t[0].ProgramSize == HAL_FLASH_PROGRAM_SIZE_X16)
        {
            *global_pu16MemWriteVar = (uint16_t)(argConst_u8WriteData | argConst_u8WriteData << 8);
            global_pu16MemWriteVar++;
            global_u32DataLen -= 2;
        }
        else if (globalConstArr_FlashConfig_t[0].ProgramSize == HAL_FLASH_PROGRAM_SIZE_X32)
        {
            *global_pu32MemWriteVar = (uint32_t)(argConst_u8WriteData | argConst_u8WriteData << 8 | argConst_u8WriteData << 16 | argConst_u8WriteData << 24);
            global_pu32MemWriteVar++;
            global_u32DataLen -= 4;
        }
        else if (globalConstArr_FlashConfig_t[0].ProgramSize == HAL_FLASH_PROGRAM_SIZE_X64)
        {
            *global_pu64MemWriteVar = (uint64_t)(argConst_u8WriteData | argConst_u8WriteData << 8 | argConst_u8WriteData << 16 | argConst_u8WriteData << 24 | argConst_u8WriteData << 32 | argConst_u8WriteData << 40 | argConst_u8WriteData << 48 | argConst_u8WriteData << 56);
            global_pu32MemWriteVar++;
            global_u32DataLen -= 8;
        }
        else
        {
            local_errState_t = HAL_FLASH_ERR_INVALID_CONFIG;
        }

        if (global_u32DataLen <= 0)
        {
            global_pu8MemWriteVar = NULL;
            global_pu16MemWriteVar = NULL;
            global_pu32MemWriteVar = NULL;
            global_pu64MemWriteVar = NULL;
            global_u8WriteData = 0;
            global_u32DataLen = 0;
            global_u8SuccessOperationState = LIB_CONSTANTS_SUCCESS;
            global_u8WhichOperationToExecute = HAL_FLASH_IRQ_OP_NONE;
        }
        else
        {
            // do nothing
        }
    }
    else
    {
        // do nothing
    }

    // check for any hardware errors
    HAL_FLASH_ErrStates_t local_hardwareErrors_t = HAL_FLASH_GetHardwareErrors();
    if (local_hardwareErrors_t == HAL_FLASH_ERR_PROGRAMMING_SEQUENCE && global_pErrProgrammingSequence_t != NULL)
    {
        global_u8SuccessOperationState = LIB_CONSTANTS_FAIL;
        global_pErrProgrammingSequence_t();
    }
    else if (local_hardwareErrors_t == HAL_FLASH_ERR_PROGRAMMING_PARALLELISM && global_pErrProgrammingParallelism_t != NULL)
    {
        global_u8SuccessOperationState = LIB_CONSTANTS_FAIL;
        global_pErrProgrammingParallelism_t();
    }
    else if (local_hardwareErrors_t == HAL_FLASH_ERR_PROGRAMMING_ALIGNMENT && global_pErrProgrammingAlignment_t != NULL)
    {
        global_u8SuccessOperationState = LIB_CONSTANTS_FAIL;
        global_pErrProgrammingAlignment_t();
    }
    else if (local_hardwareErrors_t == HAL_FLASH_ERR_WRITE_PROTECTION && global_pErrWriteProtection_t != NULL)
    {
        global_u8SuccessOperationState = LIB_CONSTANTS_FAIL;
        global_pErrWriteProtection_t();
    }
    else if (local_hardwareErrors_t == HAL_FLASH_ERR_OPERATION && global_pErrOperation_t != NULL)
    {
        global_u8SuccessOperationState = LIB_CONSTANTS_FAIL;
        global_pErrOperation_t();
    }
    else if (global_u8SuccessOperationState == LIB_CONSTANTS_SUCCESS && global_pOperationSuccess_t != NULL)
    {
        global_u8SuccessOperationState = LIB_CONSTANTS_FAIL;
        global_pOperationSuccess_t();
    }
    else
    {
        // do nothing
    }
}

/**
 * @brief: used as a helpful function
 */
static HAL_FLASH_ErrStates_t HAL_FLASH_GetHardwareErrors()
{
    // local used variables
    HAL_FLASH_ErrStates_t local_errState_t = HAL_FLASH_OK;

    if (LIB_MATH_BTT_GET_BIT(global_pFlashReg_t->FLASH_SR, HAL_FLASH_SR_BSY) == 1)
    {
        local_errState_t = HAL_FLASH_ERR_FLASH_BUSY;
    }
    else if (LIB_MATH_BTT_GET_BIT(global_pFlashReg_t->FLASH_SR, HAL_FLASH_SR_PGSERR) == 1)
    {
        local_errState_t = HAL_FLASH_ERR_PROGRAMMING_SEQUENCE;
        LIB_MATH_BTT_SET_BIT(global_pFlashReg_t->FLASH_SR, HAL_FLASH_SR_PGSERR);
    }
    else if (LIB_MATH_BTT_GET_BIT(global_pFlashReg_t->FLASH_SR, HAL_FLASH_SR_PGPERR) == 1)
    {
        local_errState_t = HAL_FLASH_ERR_PROGRAMMING_PARALLELISM;
        LIB_MATH_BTT_SET_BIT(global_pFlashReg_t->FLASH_SR, HAL_FLASH_SR_PGPERR);
    }
    else if (LIB_MATH_BTT_GET_BIT(global_pFlashReg_t->FLASH_SR, HAL_FLASH_SR_PGAERR) == 1)
    {
        local_errState_t = HAL_FLASH_ERR_PROGRAMMING_ALIGNMENT;
        LIB_MATH_BTT_SET_BIT(global_pFlashReg_t->FLASH_SR, HAL_FLASH_SR_PGAERR);
    }
    else if (LIB_MATH_BTT_GET_BIT(global_pFlashReg_t->FLASH_SR, HAL_FLASH_SR_WRPERR) == 1)
    {
        local_errState_t = HAL_FLASH_ERR_WRITE_PROTECTION;
        LIB_MATH_BTT_SET_BIT(global_pFlashReg_t->FLASH_SR, HAL_FLASH_SR_WRPERR);
    }
    else if (LIB_MATH_BTT_GET_BIT(global_pFlashReg_t->FLASH_SR, HAL_FLASH_SR_OPERR) == 1)
    {
        local_errState_t = HAL_FLASH_ERR_OPERATION;
    }
    else
    {
        // do nothing
    }

    return local_errState_t;
}

/*************** END OF FUNCTIONS ***************************************************************************/
