/**
 *******************************************************************************
 * @file  ev_hc32f472_lqfp100.h
 * @brief This file contains all the functions prototypes of the
 *        EV_HC32F472_LQFP100 BSP driver library.
 @verbatim
   Change Logs:
   Date             Author          Notes
   2022-06-30       CDT             First version
   2023-09-30       CDT             Add include file named hc32_ll_fcm.h and add declaration of BSP_XTAL32_Init()
                                    Modify I2C baudrate: 400000 -> 100000
   2023-12-15       CDT             Modify BSP_XTAL32_IN/OUT_PIN
   2025-11-03       CDT             Modify XTAL/XTAL32 pins definition
                                    Optimized the naming of BSP KEY related definitions
 @endverbatim
 *******************************************************************************
 * Copyright (C) 2022-2025, Xiaohua Semiconductor Co., Ltd. All rights reserved.
 *
 * This software component is licensed by XHSC under BSD 3-Clause license
 * (the "License"); You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                    opensource.org/licenses/BSD-3-Clause
 *
 *******************************************************************************
 */
#ifndef __EV_HC32F472_LQFP100_H__
#define __EV_HC32F472_LQFP100_H__

/* C binding of definitions if building with C++ compiler */
#ifdef __cplusplus
extern "C"
{
#endif

/*******************************************************************************
 * Include files
 ******************************************************************************/
#include "hc32_ll_aos.h"
#include "hc32_ll_clk.h"
#include "hc32_ll_dma.h"
#include "hc32_ll_efm.h"
#include "hc32_ll_fcg.h"
#include "hc32_ll_fcm.h"
#include "hc32_ll_gpio.h"
#include "hc32_ll_i2c.h"
#include "hc32_ll_interrupts.h"
#include "hc32_ll_keyscan.h"
#include "hc32_ll_pwc.h"
#include "hc32_ll_spi.h"
#include "hc32_ll_sram.h"
#include "hc32_ll_usart.h"
#include "hc32_ll_utility.h"

/**
 * @addtogroup BSP
 * @{
 */

/**
 * @addtogroup EV_HC32F472_LQFP100
 * @{
 */

/**
 * @addtogroup EV_HC32F472_LQFP100_BASE
 * @{
 */

#if (BSP_EV_HC32F472_LQFP100 == BSP_EV_HC32F4XX)

/*******************************************************************************
 * Global type definitions ('typedef')
 ******************************************************************************/

/*******************************************************************************
 * Global pre-processor symbols/macros ('#define')
 ******************************************************************************/
/**
 * @defgroup EV_HC32F472_LQFP100_Global_Macros EV_HC32F472_LQFP100 Global Macros
 * @{
 */

/**
 * @defgroup EV_HC32F472_LQFP100_I2C_Configuration EV_HC32F472_LQFP100 I2C Configuration
 * @{
 */
#define BSP_I2C_BAUDRATE        (100000UL)
#define BSP_I2C_TIMEOUT         (0x40000U)
/**
 * @}
 */

/**
 * @defgroup EV_HC32F472_LQFP100_KEY_Sel EV_HC32F472_LQFP100 KEY definition
 * @{
 */
#define BSP_KEY_1               (0x0001UL)    /*!< BSP KEY 1 */
#define BSP_KEY_2               (0x0002UL)    /*!< BSP KEY 2 */
#define BSP_KEY_3               (0x0004UL)    /*!< BSP KEY 3 */
#define BSP_KEY_4               (0x0010UL)    /*!< BSP KEY 4 */
#define BSP_KEY_5               (0x0020UL)    /*!< BSP KEY 5 */
#define BSP_KEY_6               (0x0040UL)    /*!< BSP KEY 6 */
#define BSP_KEY_7               (0x0100UL)    /*!< BSP KEY 7 */
#define BSP_KEY_8               (0x0200UL)    /*!< BSP KEY 8 */
#define BSP_KEY_9               (0x0400UL)    /*!< BSP KEY 9 */
#define BSP_KEY_10              (0x0800UL)    /*!< BSP KEY 10. Independent key. */
/**
 * @}
 */

/**
 * @defgroup EV_HC32F472_LQFP100_KEY_Number EV_HC32F472_LQFP100 KEY Number
 * @{
 */
#define BSP_KEY_ROW_NUM         (3U)
#define BSP_KEY_COL_NUM         (3U)
#define BSP_KEY_INDEPENDENT_NUM (1U)
/**
 * @}
 */

/**
 * @defgroup EV_HC32F472_LQFP100_KEY_PortPin EV_HC32F472_LQFP100 KEY port/pin definition
 * @{
 */
#define BSP_KEY10_PORT          (GPIO_PORT_B)
#define BSP_KEY10_PIN           (GPIO_PIN_05)
#define BSP_KEY10_EXTINT        (EXTINT_CH05)
#define BSP_KEY10_IRQn          (EXTINT_PORT_EIRQ5_IRQn)
#define BSP_KEY10_WAKEUP        (INTC_STOP_WKUP_EXTINT_CH5)
#define BSP_KEY10_EVT           (EVT_SRC_PORT_EIRQ5)

#define BSP_KEYOUT0_PORT        (GPIO_PORT_C)
#define BSP_KEYOUT0_PIN         (GPIO_PIN_05)
#define BSP_KEYOUT1_PORT        (GPIO_PORT_C)
#define BSP_KEYOUT1_PIN         (GPIO_PIN_03)
#define BSP_KEYOUT2_PORT        (GPIO_PORT_C)
#define BSP_KEYOUT2_PIN         (GPIO_PIN_02)

#define BSP_KEYIN0_PORT         (GPIO_PORT_A)
#define BSP_KEYIN0_PIN          (GPIO_PIN_02)
#define BSP_KEY_ROW0_EXTINT     (EXTINT_CH02)
#define BSP_KEY_ROW0_IRQn       (EXTINT_PORT_EIRQ2_IRQn)

#define BSP_KEYIN1_PORT         (GPIO_PORT_A)
#define BSP_KEYIN1_PIN          (GPIO_PIN_03)
#define BSP_KEY_ROW1_EXTINT     (EXTINT_CH03)
#define BSP_KEY_ROW1_IRQn       (EXTINT_PORT_EIRQ3_IRQn)

#define BSP_KEYIN2_PORT         (GPIO_PORT_F)
#define BSP_KEYIN2_PIN          (GPIO_PIN_08)
#define BSP_KEY_ROW2_EXTINT     (EXTINT_CH08)
#define BSP_KEY_ROW2_IRQn       (EXTINT_PORT_EIRQ8_IRQn)

#define BSP_KEY1_EVT            (EVT_SRC_PORT_EIRQ2)
#define BSP_KEY2_EVT            (EVT_SRC_PORT_EIRQ2)
#define BSP_KEY3_EVT            (EVT_SRC_PORT_EIRQ2)
#define BSP_KEY4_EVT            (EVT_SRC_PORT_EIRQ3)
#define BSP_KEY5_EVT            (EVT_SRC_PORT_EIRQ3)
#define BSP_KEY6_EVT            (EVT_SRC_PORT_EIRQ3)
#define BSP_KEY7_EVT            (EVT_SRC_PORT_EIRQ8)
#define BSP_KEY8_EVT            (EVT_SRC_PORT_EIRQ8)
#define BSP_KEY9_EVT            (EVT_SRC_PORT_EIRQ8)
/**
 * @}
 */

/**
 * @defgroup EV_HC32F472_LQFP100_KEYSCAN_CONFIG EV_HC32F472_LQFP100 KEYSCAN Configure definition
 * @{
 */
#define BSP_KEYOUT_SELECT       (KEYSCAN_OUT_0T2)
#define BSP_KEYIN_SELECT        (KEYSCAN_IN_2 | KEYSCAN_IN_3 | KEYSCAN_IN_8)
/**
 * @}
 */

/**
 * @defgroup EV_HC32F472_LQFP100_PRINT_CONFIG EV_HC32F472_LQFP100 PRINT Configure definition
 * @{
 */
#define BSP_PRINTF_DEVICE               (CM_USART2)
#define BSP_PRINTF_DEVICE_FCG           (FCG3_PERIPH_USART2)

#define BSP_PRINTF_BAUDRATE             (115200UL)
#define BSP_PRINTF_BAUDRATE_ERR_MAX     (0.025F)

#define BSP_PRINTF_PORT                 (GPIO_PORT_C)
#define BSP_PRINTF_PIN                  (GPIO_PIN_13)
#define BSP_PRINTF_PORT_FUNC            (GPIO_FUNC_34)
/**
 * @}
 */

/**
 * @defgroup EV_HC32F472_LQFP100_XTAL_CONFIG EV_HC32F472_LQFP100 XTAL port/pin definition
 * @{
 */
#define BSP_XTAL_PORT                   (GPIO_PORT_F)
#define BSP_XTAL_PIN                    (GPIO_PIN_00 | GPIO_PIN_01)
/**
 * @}
 */

/**
 * @defgroup EV_HC32F472_LQFP100_XTAL32_CONFIG EV_HC32F472_LQFP100 XTAL32 port/pin definition
 * @{
 */
#define BSP_XTAL32_PORT                 (GPIO_PORT_C)
#define BSP_XTAL32_PIN                  (GPIO_PIN_14 | GPIO_PIN_15)
/**
 * @}
 */

/**
 * @}
 */

/*******************************************************************************
 * Global variable definitions ('extern')
 ******************************************************************************/

/*******************************************************************************
  Global function prototypes (definition in C source)
 ******************************************************************************/
/**
 * @addtogroup EV_HC32F472_LQFP100_Global_Functions
 * @{
 */
int32_t BSP_XTAL_Init(void);
int32_t BSP_XTAL32_Init(void);
void BSP_CLK_Init(void);

void BSP_KEY_Init(void);
en_flag_status_t BSP_KEY_GetStatus(uint32_t u32Key);

#if (LL_PRINT_ENABLE == DDL_ON)
int32_t BSP_PRINTF_Preinit(void *vpDevice, uint32_t u32Baudrate);
#endif

/* User Callbacks: User has to implement these functions in his code if they're needed. */
void BSP_KEY10_IrqCallback(void);

#if (LL_I2C_ENABLE == DDL_ON)
int32_t BSP_I2C_Init(CM_I2C_TypeDef *I2Cx);
void BSP_I2C_DeInit(CM_I2C_TypeDef *I2Cx);
int32_t BSP_I2C_Write(CM_I2C_TypeDef *I2Cx, uint16_t u16DevAddr, const uint8_t *pu8Reg, uint8_t u8RegLen, const uint8_t *pu8Buf, uint32_t u32Len);
int32_t BSP_I2C_Read(CM_I2C_TypeDef *I2Cx, uint16_t u16DevAddr, const uint8_t *pu8Reg, uint8_t u8RegLen, uint8_t *pu8Buf, uint32_t u32Len);
int32_t BSP_I2C_GetDevStatus(CM_I2C_TypeDef *I2Cx, uint16_t u16DevAddr);
#endif /* LL_I2C_ENABLE */

/**
 * @}
 */

#endif /* BSP_EV_HC32F472_LQFP100 */
/**
 * @}
 */

/**
 * @}
 */

/**
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif /* __EV_HC32F472_LQFP100_H__ */

/*******************************************************************************
 * EOF (not truncated)
 ******************************************************************************/
