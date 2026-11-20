/**
 *******************************************************************************
 * @file  ev_hc32f472_lqfp100_24cxx.h
 * @brief This file contains all the functions prototypes of the
          ev_hc32f472_lqfp100_24cxx driver library.
 @verbatim
   Change Logs:
   Date             Author          Notes
   2022-06-30       CDT             First version
   2025-11-03       CDT             Modify macro of EEPROM capacity
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
#ifndef __EV_HC32F472_LQFP100_24CXX_H__
#define __EV_HC32F472_LQFP100_24CXX_H__

/* C binding of definitions if building with C++ compiler */
#ifdef __cplusplus
extern "C"
{
#endif

/*******************************************************************************
 * Include files
 ******************************************************************************/
#include "24cxx.h"
#include "ev_hc32f472_lqfp100.h"

/**
 * @addtogroup BSP
 * @{
 */

/**
 * @addtogroup EV_HC32F472_LQFP100
 * @{
 */

/**
 * @addtogroup EV_HC32F472_LQFP100_24CXX
 * @{
 */
#if ((BSP_24CXX_ENABLE == DDL_ON) && (BSP_EV_HC32F472_LQFP100 == BSP_EV_HC32F4XX))

/*******************************************************************************
 * Global type definitions ('typedef')
 ******************************************************************************/

/*******************************************************************************
 * Global pre-processor symbols/macros ('#define')
 ******************************************************************************/
/**
 * @defgroup EV_HC32F472_LQFP100_24CXX_Global_Macros EV_HC32F472_LQFP100 24CXX Global Macros
 * @{
 */
/* I2C unit define */
#define BSP_24CXX_I2C_UNIT              (CM_I2C1)
#define BSP_24CXX_I2C_FCG               (FCG1_PERIPH_I2C1)

/* Define port and pin for SDA and SCL */
#define BSP_24CXX_I2C_SCL_PORT          (GPIO_PORT_B)
#define BSP_24CXX_I2C_SCL_PIN           (GPIO_PIN_06)
#define BSP_24CXX_I2C_SDA_PORT          (GPIO_PORT_B)
#define BSP_24CXX_I2C_SDA_PIN           (GPIO_PIN_09)
#define BSP_24CXX_I2C_SCL_FUNC          (GPIO_FUNC_55)
#define BSP_24CXX_I2C_SDA_FUNC          (GPIO_FUNC_54)

/* Define for EEPROM BL24C256 */
#define EE_24CXX_DEV_ADDR               (0x50U)
#define EE_24CXX_MEM_ADDR_LEN           (2U)
#define EE_24CXX_PAGE_SIZE              (64U)
#define EE_24CXX_CAPACITY               (32 * 1024UL)
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
 * @addtogroup EV_HC32F472_LQFP100_24CXX_Global_Functions
 * @{
 */
int32_t BSP_24CXX_Init(void);
int32_t BSP_24CXX_DeInit(void);
int32_t BSP_24CXX_Write(uint16_t u16Addr, const uint8_t *pu8Buf, uint32_t u32Len);
int32_t BSP_24CXX_Read(uint16_t u16Addr, uint8_t *pu8Buf, uint32_t u32Len);
int32_t BSP_24CXX_WaitIdle(void);
/**
 * @}
 */

#endif /* (BSP_24CXX_ENABLE && BSP_EV_HC32F472_LQFP100) */

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

#endif /* __EV_HC32F472_LQFP100_24CXX_H__ */

/*******************************************************************************
 * EOF (not truncated)
 ******************************************************************************/
