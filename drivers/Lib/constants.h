/**
 * --------------------------------------------------------------------------------------------------------------------------------------
 * |    @title          :   constants                                                                                                   |
 * |    @file           :   constants.h                                                                                                 |
 * |    @author         :   Abdelrahman Mohamed Salem                                                                                   |
 * |    @origin_date    :   28/07/2023                                                                                                  |
 * |    @version        :   1.0.0                                                                                                       |
 * |    @tool_chain     :   GNU Tools for STM32                                                                                         |
 * |    @compiler       :   GCC                                                                                                         |
 * |    @C_standard     :   ISO C99 (-std=c99)                                                                                          |
 * |    @target         :   stm32f407VGTX                                                                                               |
 * |    @notes          :   None                                                                                                        |
 * |    @license        :   MIT License                                                                                                 |
 * |    @brief          :   this file contains some common definitions which seems to be compiler dependent                             |
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

#ifndef LIB_CONSTANTS_H_
#define LIB_CONSTANTS_H_

/******************************************************************************
 * Includes
 *******************************************************************************/

/******************************************************************************
 * Preprocessor Constants
 *******************************************************************************/

/**
 * @enum: LIB_Constants_DriverStates_t
 * @brief: this is mostly used in configurations to configure whether something is enabled or disabled
 */
typedef enum
{
    LIB_CONSTANTS_DISABLED = 0,     /**< that means the thing we are dealing with is diabled*/
    LIB_CONSTANTS_ENABLED = 1,      /**< that means the thing we are dealing with is enabled*/
    LIB_CONSTANTS_MAX_DRIVER_STATE, /**< that value should never be used and it's only used by the implementation code for verifying the input*/
} LIB_CONSTANTS_DriverStates_t;

/**
 * @enum: LIB_CONSTANTS_LogicalStates_t
 * @brief: this is mostly used in dealing with things that have digital values (HIGH and LOW)
 */
typedef enum
{
    LIB_CONSTANTS_LOW = 0,         /**< that means the thing we are dealing with is having a logic high volt*/
    LIB_CONSTANTS_HIGH = 1,        /**< that means the thing we are dealing with is is having a logic low volt*/
    LIB_CONSTANTS_MAX_LOGIC_STATE, /**< that value should never be used and it's only used by the implementation code for verifying the input*/
} LIB_CONSTANTS_LogicalStates_t;

/**
 * @enum: LIB_CONSTANTS_LockStates_t
 * @brief: this is mostly used in dealing with things that have locking and unlocking sequences
 */
typedef enum
{
    LIB_CONSTANTS_UNLOCKED = 0,   /**< that means the thing we are dealing with is un locked (can't be dealt with)*/
    LIB_CONSTANTS_LOCKED = 1,     /**< that means the thing we are dealing with is locked (can be dealt with)*/
    LIB_CONSTANTS_MAX_LOCK_STATE, /**< that value should never be used and it's only used by the implementation code for verifying the input*/
} LIB_CONSTANTS_LockStates_t;

/******************************************************************************
 * Configuration Constants
 *******************************************************************************/

/******************************************************************************
 * Macros
 *******************************************************************************/

/******************************************************************************
 * Typedefs
 *******************************************************************************/

/******************************************************************************
 * Variables
 *******************************************************************************/

/******************************************************************************
 * Function Prototypes
 *******************************************************************************/

/*** End of File **************************************************************/
#endif /*LIB_CONSTANTS_H_*/