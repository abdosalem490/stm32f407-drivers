/**
 * --------------------------------------------------------------------------------------------------------------------------------------
 * |    @title          :   stdint                                                                                                      |
 * |    @file           :   stdint.h                                                                                                    |
 * |    @author         :   Abdelrahman Mohamed Salem                                                                                   |
 * |    @origin_date    :   19/07/2023                                                                                                  |
 * |    @version        :   1.0.0                                                                                                       |
 * |    @tool_chain     :   GNU Tools for STM32                                                                                         |
 * |    @compiler       :   GCC                                                                                                         |
 * |    @C_standard     :   ISO C99 (-std=c99)                                                                                          |
 * |    @target         :   stm32f407VGTX                                                                                               |
 * |    @notes          :   None                                                                                                        |
 * |    @license        :   MIT License                                                                                                 |
 * |    @brief          :   this file contains standard var types specified for stm32f407                                               |
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
 * |    15/07/2023      1.0.0           Abdelrahman Mohamed Salem       stdint Created.                                                 |
 * --------------------------------------------------------------------------------------------------------------------------------------
 */


#ifndef LIB_STDINT_H_
#define LIB_STDINT_H_

/******************************************************************************
 * Includes
 *******************************************************************************/

/******************************************************************************
 * Preprocessor Constants
 *******************************************************************************/
/**
 * @brief maximum values for signed integer variables
 */
#ifndef INT8_MAX
	#define INT8_MAX 127                  /**< maximum value for signed 8-bit variable*/
#endif
#ifndef INT16_MAX
	#define INT16_MAX 32767               /**< maximum value for signed 16-bit variable*/
#endif
#ifndef INT32_MAX
	#define INT32_MAX 2147483647          /**< maximum value for signed 32-bit variable*/
#endif
#ifndef INT64_MAX
	#define INT64_MAX 9223372036854775807 /**< maximum value for signed 64-bit variable*/
#endif

/**
 * @brief minimum values for signed integer variables
 */
#ifndef INT8_MAX
	#define INT8_MAX -128                  /**< minimum value for signed 8-bit variable*/
#endif
#ifndef INT16_MAX
	#define INT16_MAX -32768               /**< minimum value for signed 16-bit variable*/
#endif
#ifndef INT32_MAX
	#define INT32_MAX -2147483648          /**< minimum value for signed 32-bit variable*/
#endif
#ifndef INT64_MAX
	#define INT64_MAX -9223372036854775808 /**< minimum value for signed 64-bit variable*/
#endif
/**
 * @brief maximum values for un-signed integer variables
 */
#define UINT8_MAX 0xff                /**< maximum value for un-signed 8-bit variable*/
#define UINT16_MAX 0xffff             /**< maximum value for un-signed 16-bit variable*/
#define UINT32_MAX 0xffffffff         /**< maximum value for un-signed 32-bit variable*/
#define UINT64_MAX 0xffffffffffffffff /**< maximum value for un-signed 64-bit variable*/

/**
 * @brief minium values for un-signed integer variables
 */
#define UINT8_MIN 0  /**< minium value for un-signed 8-bit variable*/
#define UINT16_MIN 0 /**< minium value for un-signed 16-bit variable*/
#define UINT32_MIN 0 /**< minium value for un-signed 32-bit variable*/
#define UINT64_MIN 0 /**< minium value for un-signed 64-bit variable*/

/**
 * @brief maximum values float numbers
 */
#define FLOAT32_MAX 3.402823466e+38F        /**< maximum value for single precision float variable (32-bit)*/
#define FLOAT64_MAX 1.7976931348623158e+308 /**< maximum value for double precision float variable (64-bit)*/

/**
 * @brief minimum values float numbers
 */
#define FLOAT32_MIN 1.175494351e-38F        /**< minimum value for single precision float variable (32-bit)*/
#define FLOAT64_MIN 2.2250738585072014e-308 /**< minimum value for double precision float variable (64-bit)*/

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
 * @brief signed integer variables
 */
typedef signed char int8_t;       /**< 8-bit signed variable type*/
typedef signed short int int16_t; /**< 16-bit signed variable type*/
typedef signed long int int32_t;  /**< 32-bit signed variable type*/
typedef signed long long int64_t; /**< 64-bit signed variable type*/

/**
 * @brief un-signed integer variables
 */
typedef unsigned char uint8_t;       /**< 8-bit un-signed variable type*/
typedef unsigned short int uint16_t; /**< 16-bit un-signed variable type*/
typedef unsigned long int uint32_t;  /**< 32-bit un-signed variable type*/
typedef unsigned long long uint64_t; /**< 64-bit un-signed variable type*/

/**
 * @brief float standard types
 */
typedef float float32_t;  /**< 32-bit float (single precision)*/
typedef double float64_t; /**< 64-bit float (double precision)*/

/**
 * @brief fast signed integers (used if specified by either compiler or MCU that certain types of int are faster than others)
 */
typedef signed char int_fast8_t;        /**< 8-bit fast signed variable type*/
typedef signed short int int_fast16_t;  /**< 16-bit fast signed variable type*/
typedef signed long int int_fast32_t;   /**< 32-bit fast signed variable type*/
typedef signed long long int_fasts64_t; /**< 64-bit fast signed variable type*/

/**
 * @brief fast un-signed integers (used if specified by either compiler or MCU that certain types of int are faster than others)
 */
typedef unsigned char uint_fast8_t;        /**< 8-bit fast un-signed variable type*/
typedef unsigned short int uint_fast16_t;  /**< 16-bit fast un-signed variable type*/
typedef unsigned long int uint_fast32_t;   /**< 32-bit fast un-signed variable type*/
typedef unsigned long long uint_fasts64_t; /**< 64-bit fast un-signed variable type*/

/******************************************************************************
 * Variables
 *******************************************************************************/

/******************************************************************************
 * Function Prototypes
 *******************************************************************************/

/*** End of File **************************************************************/
#endif /*LIB_STDINT_H_*/
