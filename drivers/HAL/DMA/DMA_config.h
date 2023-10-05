
/**
 * --------------------------------------------------------------------------------------------------------------------------------------
 * |    @title          :   Direct Memory Access Controller                                                                             |
 * |    @file           :   DMA_config.h                                                                                                |
 * |    @author         :   Abdelrahman Mohamed Salem                                                                                   |
 * |    @origin_date    :   16/09/2023                                                                                                  |
 * |    @version        :   1.0.0                                                                                                       |
 * |    @tool_chain     :   GNU Tools for STM32                                                                                         |
 * |    @compiler       :   GCC                                                                                                         |
 * |    @C_standard     :   ISO C99 (-std=c99)                                                                                          |
 * |    @target         :   stm32f407VGTX                                                                                               |
 * |    @notes          :   None                                                                                                        |
 * |    @license        :   MIT License                                                                                                 |
 * |    @brief          :   this header file contains configurations related to the Direct Memory Access Controller (DMA)               |                                                               |
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
 * |    16/09/2023      1.0.0           Abdelrahman Mohamed Salem       Interface Created.                                              |
 * --------------------------------------------------------------------------------------------------------------------------------------
 */

#ifndef HAL_DMA_CONFIG_H_
#define HAL_DMA_CONFIG_H_

/******************************************************************************
 * Includes
 *******************************************************************************/

/**
 * @reason: it contains standard definition for integers
 */
#include "../../lib/stdint.h"

/**
 * @reason: it holds the definitions for (ENABLED and DISABLED)
 */
#include "../../lib/constants.h"

/**
 * @reason: hold possible values for DMA ports and pins
 */
#include "DMA_header.h"

/**
 * @reason: hold possible values for configuration indexes
 */
#include "DMA_private.h"

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
 * Tables
 *******************************************************************************/

/******************************************************************************
 * Typedefs
 *******************************************************************************/

/**
 * @enum: HAL_DMA1_StreamsChannels_t
 * @brief: used to Select a stream channel for DMA1
 */
typedef enum
{
    // channels for stream 0
    HAL_DMA1_STREAM0_CH0_SPI3_RX = 0,     /**< SPI3 RX mapped to channel 0 on stream 0 */
    HAL_DMA1_STREAM0_CH1_I2C1_RX = 1,     /**< I2C1 RX mapped to channel 1 on stream 0 */
    HAL_DMA1_STREAM0_CH2_TIM4_CH1 = 2,    /**< TIM4 CH1 mapped to channel 2 on stream 0 */
    HAL_DMA1_STREAM0_CH3_I2S3_EXT_RX = 3, /**< I2S3 EXT RX mapped to channel 3 on stream 0 */
    HAL_DMA1_STREAM0_CH4_UART5_RX = 4,    /**< UART5 RX mapped to channel 4 on stream 0 */
    HAL_DMA1_STREAM0_CH5_UART8_TX = 5,    /**< UART8 TX mapped to channel 5 on stream 0 */
    HAL_DMA1_STREAM0_CH5_TIM5_CH3 = 6,    /**< TIM5 CH3 mapped to channel 6 on stream 0 */
    HAL_DMA1_STREAM0_CH5_TIM5_UP = 6,     /**< TIM5 UP mapped to channel 6 on stream 0 */

    // channels for stream 1
    HAL_DMA1_STREAM1_CH3_TIM2_UP = 3,   /**< TIM2 UP mapped to channel 3 on stream 1 */
    HAL_DMA1_STREAM1_CH3_TIM2_CH3 = 3,  /**< TIM2 CH3 mapped to channel 3 on stream 1 */
    HAL_DMA1_STREAM1_CH4_USART3_RX = 4, /**< USART3 RX mapped to channel 4 on stream 1 */
    HAL_DMA1_STREAM1_CH5_UART7_TX = 5,  /**< UART7 TX mapped to channel 5 on stream 1 */
    HAL_DMA1_STREAM1_CH6_TIM5_CH4 = 6,  /**< TIM5 CH4 mapped to channel 6 on stream 1 */
    HAL_DMA1_STREAM1_CH6_TIM5_TRIG = 6, /**< TIM5 TRIG mapped to channel 6 on stream 1 */
    HAL_DMA1_STREAM1_CH7_TIM6_UP = 7,   /**< TIM6 UP mapped to channel 7 on stream 1 */

    // channels for stream 2
    HAL_DMA1_STREAM2_CH0_SPI3_RX = 0,     /**< SPI3 RX mapped to channel 0 on stream 2 */
    HAL_DMA1_STREAM2_CH1_TIM7_UP = 1,     /**< TIM7 UP mapped to channel 1 on stream 2 */
    HAL_DMA1_STREAM2_CH2_I2S3_EXT_RX = 2, /**< I2S3 EXT RX mapped to channel 2 on stream 2 */
    HAL_DMA1_STREAM2_CH3_I2C3_RX = 3,     /**< I2C3 RX mapped to channel 3 on stream 2 */
    HAL_DMA1_STREAM2_CH4_UART4_RX = 4,    /**< UART4 RX mapped to channel 4 on stream 2 */
    HAL_DMA1_STREAM2_CH5_TIM3_CH4 = 5,    /**< TIM3 CH4 mapped to channel 5 on stream 2 */
    HAL_DMA1_STREAM2_CH5_TIM3_UP = 5,     /**< TIM3 UP mapped to channel 5 on stream 2 */
    HAL_DMA1_STREAM2_CH6_TIM5_CH1 = 6,    /**< TIM5 CH1 mapped to channel 6 on stream 2 */
    HAL_DMA1_STREAM2_CH7_I2C2_RX = 7,     /**< I2C2 RX mapped to channel 7 on stream 2 */

    // channels for stream 3
    HAL_DMA1_STREAM3_CH0_SPI2_RX = 0,     /**< SPI2 RX mapped to channel 0 on stream 3 */
    HAL_DMA1_STREAM3_CH2_TIM4_CH2 = 2,    /**< TIM4 CH2 mapped to channel 2 on stream 3 */
    HAL_DMA1_STREAM3_CH3_I2S2_EXT_RX = 3, /**< I2S2 EXT RX mapped to channel 3 on stream 3 */
    HAL_DMA1_STREAM3_CH4_USART3_TX = 4,   /**< USART3 TX mapped to channel 4 on stream 3 */
    HAL_DMA1_STREAM3_CH5_UART7_RX = 5,    /**< UART7 RX mapped to channel 5 on stream 3 */
    HAL_DMA1_STREAM3_CH6_TIM5_CH4 = 6,    /**< TIM5 CH4 mapped to channel 6 on stream 3 */
    HAL_DMA1_STREAM3_CH6_TIM5_TRIG = 6,   /**< TIM5 TRIG mapped to channel 6 on stream 3 */
    HAL_DMA1_STREAM3_CH7_I2C2_RX = 7,     /**< I2C2 RX mapped to channel 7 on stream 3 */

    // channels for stream 4
    HAL_DMA1_STREAM4_CH0_SPI2_TX = 0,     /**< SPI2 TX mapped to channel 0 on stream 4 */
    HAL_DMA1_STREAM4_CH1_TIM7_UP = 1,     /**< TIM7 UP mapped to channel 1 on stream 4 */
    HAL_DMA1_STREAM4_CH2_I2S2_EXT_TX = 2, /**< I2S2 EXT TX mapped to channel 2 on stream 4 */
    HAL_DMA1_STREAM4_CH3_I2C3_TX = 3,     /**< I2C3 TX mapped to channel 3 on stream 4 */
    HAL_DMA1_STREAM4_CH4_UART4_TX = 4,    /**< UART4 TX mapped to channel 4 on stream 4 */
    HAL_DMA1_STREAM4_CH5_TIM3_CH1 = 5,    /**< TIM3 CH1 mapped to channel 5 on stream 4 */
    HAL_DMA1_STREAM4_CH5_TIM3_TRIG = 5,   /**< TIM3 TRIG mapped to channel 5 on stream 4 */
    HAL_DMA1_STREAM4_CH6_TIM5_CH2 = 6,    /**< TIM5 CH2 mapped to channel 6 on stream 4 */
    HAL_DMA1_STREAM4_CH6_USART3_TX = 7,   /**< USART3 TX mapped to channel 7 on stream 4 */

    // channels for stream 5
    HAL_DMA1_STREAM5_CH0_SPI3_TX = 0,     /**< SPI3 TX mapped to channel 0 on stream 5 */
    HAL_DMA1_STREAM5_CH1_I2C1_RX = 1,     /**< I2C1 RX mapped to channel 1 on stream 5 */
    HAL_DMA1_STREAM5_CH2_I2S3_EXT_TX = 2, /**< I2S3 EXT TX mapped to channel 2 on stream 5 */
    HAL_DMA1_STREAM5_CH3_TIM2_CH1 = 3,    /**< TIM2 CH1 mapped to channel 3 on stream 5 */
    HAL_DMA1_STREAM5_CH4_USART2_RX = 4,   /**< USART2 RX mapped to channel 4 on stream 5 */
    HAL_DMA1_STREAM5_CH5_TIM3_CH2 = 5,    /**< TIM3 CH2 mapped to channel 5 on stream 5 */
    HAL_DMA1_STREAM5_CH7_DAC1 = 7,        /**< DAC1 mapped to channel 7 on stream 5 */

    // channels for stream 6
    HAL_DMA1_STREAM6_CH1_I2C1_TX = 1,   /**< I2C1 TX mapped to channel 1 on stream 6 */
    HAL_DMA1_STREAM6_CH2_TIM4_UP = 2,   /**< TIM4 UP mapped to channel 2 on stream 6 */
    HAL_DMA1_STREAM6_CH3_TIM2_CH2 = 3,  /**< TIM2 CH2 mapped to channel 3 on stream 6 */
    HAL_DMA1_STREAM6_CH3_TIM2_CH4 = 3,  /**< TIM2 CH4 mapped to channel 3 on stream 6 */
    HAL_DMA1_STREAM6_CH4_USART2_TX = 4, /**< USART2 TX mapped to channel 4 on stream 6 */
    HAL_DMA1_STREAM6_CH5_UART8_RX = 5,  /**< UART8 RX mapped to channel 5 on stream 6 */
    HAL_DMA1_STREAM6_CH6_TIM5_UP = 6,   /**< TIM5 UP mapped to channel 6 on stream 6 */
    HAL_DMA1_STREAM6_CH7_DAC2 = 7,      /**< DAC2 mapped to channel 7 on stream 6 */

    // channels for stream 7
    HAL_DMA1_STREAM7_CH0_SPI3_TX = 0,  /**< SPI3 TX mapped to channel 0 on stream 7 */
    HAL_DMA1_STREAM7_CH1_I2C1_TX = 1,  /**< I2C1 TX mapped to channel 1 on stream 7 */
    HAL_DMA1_STREAM7_CH2_TIM4_CH3 = 2, /**< TIM4 CH3 mapped to channel 2 on stream 7 */
    HAL_DMA1_STREAM7_CH3_TIM2_UP = 3,  /**< TIM2 UP mapped to channel 3 on stream 7 */
    HAL_DMA1_STREAM7_CH3_TIM2_CH4 = 3, /**< TIM2 CH4 mapped to channel 3 on stream 7 */
    HAL_DMA1_STREAM7_CH4_UART5_TX = 4, /**< UART5 TX mapped to channel 4 on stream 7 */
    HAL_DMA1_STREAM7_CH5_TIM3_CH3 = 5, /**< TIM3 CH3 mapped to channel 5 on stream 7 */
    HAL_DMA1_STREAM7_CH7_I2C2_TX = 7,  /**< I2C2 TX mapped to channel 7 on stream 7 */

    HAL_DMA1_MAX_STREAMS_CHANNELS = 8, /**< this value shall never used by the user and it's only used by implementation code to verify input*/
} HAL_DMA1_StreamsChannels_t;

/**
 * @enum: HAL_DMA2_StreamsChannels_t
 * @brief: used to Select a stream channel for DMA2
 */
typedef enum
{

    // channels for stream 0
    HAL_DMA2_STREAM0_CH0_ADC1 = 0,      /**< ADC1 mapped to channel 0 on stream 0 */
    HAL_DMA2_STREAM0_CH2_ADC3 = 2,      /**< ADC3 mapped to channel 2 on stream 0 */
    HAL_DMA2_STREAM0_CH3_SPI1_RX = 3,   /**< SPI1 RX mapped to channel 3 on stream 0 */
    HAL_DMA2_STREAM0_CH4_SPI4_RX = 4,   /**< SPI4 RX mapped to channel 4 on stream 0 */
    HAL_DMA2_STREAM0_CH6_TIM1_TRIG = 6, /**< TIM1 TRIG mapped to channel 6 on stream 0 */

    // channels for stream 1
    HAL_DMA2_STREAM1_CH0_SAI1_A = 0,    /**< SAI1 A mapped to channel 0 on stream 1 */
    HAL_DMA2_STREAM1_CH1_DCMI = 1,      /**< DCMI mapped to channel 1 on stream 1 */
    HAL_DMA2_STREAM1_CH2_ADC3 = 2,      /**< ADC3 mapped to channel 2 on stream 1 */
    HAL_DMA2_STREAM1_CH4_SPI4_TX = 4,   /**< SPI4 TX mapped to channel 4 on stream 1 */
    HAL_DMA2_STREAM1_CH5_USART6_RX = 5, /**< USART6 RX mapped to channel 5 on stream 1 */
    HAL_DMA2_STREAM1_CH6_TIM1_CH1 = 6,  /**< TIM1 CH1 mapped to channel 6 on stream 1 */
    HAL_DMA2_STREAM1_CH7_TIM8_UP = 7,   /**< TIM8 UP mapped to channel 7 on stream 1 */

    // channels for stream 2
    HAL_DMA2_STREAM2_CH0_TIM8_CH1 = 0,  /**< TIM8 CH1 mapped to channel 0 on stream 2 */
    HAL_DMA2_STREAM2_CH0_TIM8_CH2 = 0,  /**< TIM8 CH2 mapped to channel 0 on stream 2 */
    HAL_DMA2_STREAM2_CH0_TIM8_CH3 = 0,  /**< TIM8 CH3 mapped to channel 0 on stream 2 */
    HAL_DMA2_STREAM2_CH1_ADC2 = 1,      /**< ADC2 mapped to channel 1 on stream 2 */
    HAL_DMA2_STREAM2_CH3_SPI1_RX = 3,   /**< SPI1 RX mapped to channel 3 on stream 2 */
    HAL_DMA2_STREAM2_CH4_USART1_RX = 4, /**< USART1 RX mapped to channel 4 on stream 2 */
    HAL_DMA2_STREAM2_CH5_USART6_RX = 5, /**< USART6 RX mapped to channel 5 on stream 2 */
    HAL_DMA2_STREAM2_CH6_TIM1_CH2 = 6,  /**< TIM1 CH2 mapped to channel 6 on stream 2 */
    HAL_DMA2_STREAM2_CH7_TIM8_CH1 = 7,  /**< TIM8 CH1 mapped to channel 7 on stream 2 */

    // channels for stream 3
    HAL_DMA2_STREAM3_CH0_SAI1_A = 0,   /**< SAI1 A mapped to channel 0 on stream 3 */
    HAL_DMA2_STREAM3_CH1_ADC2 = 1,     /**< ADC2 mapped to channel 1 on stream 3 */
    HAL_DMA2_STREAM3_CH2_SPI5_RX = 2,  /**< SPI5 RX mapped to channel 2 on stream 3 */
    HAL_DMA2_STREAM3_CH3_SPI1_TX = 3,  /**< SPI1 TX mapped to channel 3 on stream 3 */
    HAL_DMA2_STREAM3_CH4_SDIO = 4,     /**< SDIO mapped to channel 4 on stream 3 */
    HAL_DMA2_STREAM3_CH5_SPI4_RX = 5,  /**< SPI4 RX mapped to channel 5 on stream 3 */
    HAL_DMA2_STREAM3_CH6_TIM1_CH1 = 6, /**< TIM1 CH1 mapped to channel 6 on stream 3 */
    HAL_DMA2_STREAM3_CH7_TIM8_CH2 = 7, /**< TIM8 CH2 mapped to channel 7 on stream 3 */

    // channels for stream 4
    HAL_DMA2_STREAM4_CH0_ADC1 = 0,      /**< ADC1 mapped to channel 0 on stream 4 */
    HAL_DMA2_STREAM4_CH1_SAI1_B = 1,    /**< SAI1_B mapped to channel 1 on stream 4 */
    HAL_DMA2_STREAM4_CH2_SPI5_TX = 2,   /**< SPI5 TX mapped to channel 2 on stream 4 */
    HAL_DMA2_STREAM4_CH5_SPI4_TX = 5,   /**< SPI4 TX mapped to channel 5 on stream 4 */
    HAL_DMA2_STREAM4_CH6_TIM1_CH4 = 6,  /**< TIM1 CH4 mapped to channel 6 on stream 4 */
    HAL_DMA2_STREAM4_CH6_TIM1_TRIG = 6, /**< TIM1 TRIG mapped to channel 6 on stream 4 */
    HAL_DMA2_STREAM4_CH6_TIM1_COM = 6,  /**< TIM1 COM mapped to channel 6 on stream 4 */
    HAL_DMA2_STREAM4_CH7_TIM8_CH3 = 7,  /**< TIM8 CH3 mapped to channel 7 on stream 4 */

    // channels for stream 5
    HAL_DMA2_STREAM5_CH0_SAI1_B = 0,    /**< SAI1 B mapped to channel 0 on stream 5 */
    HAL_DMA2_STREAM5_CH1_SPI6_TX = 1,   /**< SPI6 TX mapped to channel 1 on stream 5 */
    HAL_DMA2_STREAM5_CH2_CRYP_OUT = 2,  /**< CRYP OUT mapped to channel 2 on stream 5 */
    HAL_DMA2_STREAM5_CH3_SPI1_TX = 3,   /**< SPI1 TX mapped to channel 3 on stream 5 */
    HAL_DMA2_STREAM5_CH4_USART1_RX = 4, /**< USART1 RX mapped to channel 4 on stream 5 */
    HAL_DMA2_STREAM5_CH6_TIM1_UP = 6,   /**< TIM1 UP mapped to channel 6 on stream 5 */
    HAL_DMA2_STREAM5_CH7_SPI5_RX = 7,   /**< SPI5 RX mapped to channel 7 on stream 5 */

    // channels for stream 6
    HAL_DMA2_STREAM6_CH0_TIM1_CH1 = 0,  /**< TIM1 CH1 mapped to channel 0 on stream 6 */
    HAL_DMA2_STREAM6_CH0_TIM1_CH2 = 0,  /**< TIM1 CH2 mapped to channel 0 on stream 6 */
    HAL_DMA2_STREAM6_CH0_TIM1_CH3 = 0,  /**< TIM1 CH3 mapped to channel 0 on stream 6 */
    HAL_DMA2_STREAM6_CH1_SPI6_RX = 1,   /**< SPI6 RX mapped to channel 1 on stream 6 */
    HAL_DMA2_STREAM6_CH2_CRYP_IN = 2,   /**< CRYP IN mapped to channel 2 on stream 6 */
    HAL_DMA2_STREAM6_CH4_SDIO = 4,      /**< SDIO mapped to channel 4 on stream 6 */
    HAL_DMA2_STREAM6_CH5_USART6_TX = 5, /**< USART6 TX mapped to channel 5 on stream 6 */
    HAL_DMA2_STREAM6_CH6_TIM1_CH3 = 6,  /**< TIM1 CH3 mapped to channel 6 on stream 6 */
    HAL_DMA2_STREAM6_CH7_SPI5_TX = 7,   /**< SPI5 TX mapped to channel 7 on stream 6 */

    // channels for stream 7
    HAL_DMA2_STREAM7_CH1_DCMI = 1,      /**< DCMI mapped to channel 1 on stream 7 */
    HAL_DMA2_STREAM7_CH2_HASH_IN = 2,   /**< HASH IN mapped to channel 2 on stream 7 */
    HAL_DMA2_STREAM7_CH4_UASRT1_TX = 4, /**< UASRT1 TX mapped to channel 4 on stream 7 */
    HAL_DMA2_STREAM7_CH5_UASRT6_TX = 5, /**< UASRT6 TX mapped to channel 5 on stream 7 */
    HAL_DMA2_STREAM7_CH7_TIM8_CH4 = 7,  /**< TIM8 CH4 mapped to channel 7 on stream 7 */
    HAL_DMA2_STREAM7_CH7_TIM8_TRIG = 7, /**< TIM8 TRIG mapped to channel 7 on stream 7 */
    HAL_DMA2_STREAM7_CH7_TIM8_COM = 7,  /**< TIM8 COM mapped to channel 7 on stream 7 */

    HAL_DMA2_MAX_STREAMS_CHANNELS = 8, /**< this value shall never used by the user and it's only used by implementation code to verify input*/
} HAL_DMA2_StreamsChannels_t;

/**
 * @enum: HAL_DMA_StreamDirection_t
 * @brief: used to select the direction of DMA
 */
typedef enum
{
    HAL_DMA_DIR_PERI_TO_MEM = 0, /**< direction is from peripheral to memory*/
    HAL_DMA_DIR_MEM_TO_PERI = 1, /**< direction is from memory to peripheral*/
    HAL_DMA_DIR_MEM_TO_MEM = 2,  /**< direction is from memory to memory*/
    HAL_DMA_MAX_STREAM_DIR,      /**< this value shall never used by the user and it's only used by implementation code to verify input*/
} HAL_DMA_StreamDirection_t;

/**
 * @enum: HAL_DMA_StreamPriorityLevel_t
 * @brief: used to select the priority of the stream
 */
typedef enum
{
    HAL_DMA_STREAM_PRIORITY_LVL_LOW = 0,       /**< low priority level*/
    HAL_DMA_STREAM_PRIORITY_LVL_MEDIUM = 1,    /**< Medium priority level*/
    HAL_DMA_STREAM_PRIORITY_LVL_HIGH = 2,      /**< High priority level*/
    HAL_DMA_STREAM_PRIORITY_LVL_VERY_HIGH = 3, /**< Very High priority level*/

    HAL_DMA_MAX_PRIORITY_LVL, /**< this value shall never used by the user and it's only used by implementation code to verify input*/
} HAL_DMA_StreamPriorityLevel_t;

/**
 * @struct: HAL_DMA_StreamConfig_t
 * @brief: contains the essential info regarding DMA streams
 */
typedef struct
{
    uint8_t EnableStream;    /**< for possible values refer to @LIB_CONSTANTS_LockStates_t in "constants.h", used to disable/enable the stream*/
    uint8_t StreamDirection; /**< for possible values refer to @HAL_DMA_StreamDirection_t in "DMA_config.h", used to select the direction of the DMA */
    uint8_t StreamSource;    /**< for possible values refer to @HAL_DMA2_StreamsChannels_t and @HAL_DMA1_StreamsChannels_t in "DMA_config.h", used to Select the stream peripheral source*/
    uint8_t Priority;        /**< for possible values refer to @HAL_DMA_StreamPriorityLevel_t in "DMA_config.h", used to select the priority of the stream */
    
} HAL_DMA_StreamConfig_t;

/******************************************************************************
 * Variables
 *******************************************************************************/

/******************************************************************************
 * Function Prototypes
 *******************************************************************************/

/*** End of File **************************************************************/
#endif /*HAL_DMA_CONFIG_H_*/