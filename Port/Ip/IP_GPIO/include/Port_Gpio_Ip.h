/***********************************************************************************************************************
 * Project Name: Classic_Autosar_02
 * 
 * File Name: Port_Gpio_Ip.h
 *
 * Description: Implementation of Port_Gpio_Ip IP Level layer
 *              
 * AutoSAR Version:         4.4.0
 *
 * Compiler: GCC IAR GHS TASKING
 *
 * Revision:
 *              Version         Date                Change History
 *              0.0.1          07/05/2026           Initial version
 *
 **********************************************************************************************************************/

#ifndef PORT_GPIO_IP_H
#define PORT_GPIO_IP_H

#ifdef __cplusplus
extern "C" {
#endif

/***********************************************************************************************************************
 *                                                     INCLUDES 
 **********************************************************************************************************************/

#include "Port_Hw.h"
#include "Port_Gpio_Ip_Cfg.h"


/***********************************************************************************************************************
 *                                                 SOURCE FILE VERSION
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *                                                 FILE VERSION CHECK
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *                                                   LOCAL MACROS
 **********************************************************************************************************************/

/**
 * @brief  API Port called with no error.
 */
#define PORT_GPIO_IP_PROCESS_SUCCESS (uint8)(0x00U)

/**
 * @brief  API Port_Gpio_Ip_SetPinMode service called when mode is invalid.
 */
#define PORT_GPIO_IP_INVALID_MODE (uint8)(0x0DU)

/**
 * @brief  API Port_Gpio_Ip_SetPinMode service called when mode is unchangeable.
 */
#define PORT_GPIO_IP_MODE_UNCHANGEABLE (uint8)(0x0EU)

/**
 * @brief  API Port_Gpio_Ip_SetPinDirection service called when direction is unchangeable.
 */
#define PORT_GPIO_IP_DIRECTION_UNCHANGEABLE (uint8)(0x0BU)

/**
 * @brief  API Port service called when PinId is not existed in config set.
 */
#define PORT_GPIO_IP_CONFIG (uint8)(0x11U)

/**
 * @brief  API Port_Gpio_Ip_SetPinDirection service called when direction is invalid.
 */
#define PORT_GPIO_IP_INVALID_DIRECTION (uint8)(0x12U)

/**
 * @brief  API service called when port driver haven't initialized before.
 */
#define PORT_GPIO_IP_UNINIT (uint8)(0x0FU)


/**
 * @brief  Direction of Pin definition
 */
#define PORT_GPIO_IP_PIN_IN    (0U)
#define PORT_GPIO_IP_PIN_OUT   (1U)
#define PORT_GPIO_IP_PIN_INOUT (2U)

/**
 * @brief  Port pin input enable selection.
 */
#define PORT_GPIO_IP_PIN_OUT_OFF (0U)
#define PORT_GPIO_IP_PIN_OUT_ON  (1U)

/**
 * @brief  Port pin output data selection.
 */
#define PORT_GPIO_IP_PIN_OUT_LOW  (0U)
#define PORT_GPIO_IP_PIN_OUT_HIGH (1U)

/**
 * @brief  PORT_PinOutType_Sel PORT Pin Output Type Selection.
 */
#define PORT_GPIO_IP_PIN_OUT_TYPE_PP  (0U)
#define PORT_GPIO_IP_PIN_OUT_TYPE_OD  (1U)

/**
 * @brief  Port pin internal pull-up and pull-down resistor selection.
 */
#define PORT_GPIO_IP_PIN_PULL_OFF  (0U)
#define PORT_GPIO_IP_PIN_PULLUP_ON (1U)
#define PORT_GPIO_IP_PIN_PULLDN_ON (2U)

/**
 * @brief  Port pin output speed.
 */
#define PORT_GPIO_IP_PIN_OUT_SPEED_LOW    (0U)
#define PORT_GPIO_IP_PIN_OUT_SPEED_MEDIUM (1U)
#define PORT_GPIO_IP_PIN_OUT_SPEED_FAST   (2U)
#define PORT_GPIO_IP_PIN_OUT_SPEED_HIGH   (3U)

/**
 * @brief  Port pin input enable selection
 */
#define PORT_GPIO_IP_PIN_IN_OFF (0U)
#define PORT_GPIO_IP_PIN_IN_ON  (1U)

/**
 * @brief  Port pin output latch.
 */
#define PORT_GPIO_IP_PIN_LATCH_OFF (0U)
#define PORT_GPIO_IP_PIN_LATCH_ON  (1U)

/**
 * @brief  Port pin type selection.
 */
#define PORT_GPIO_IP_PIN_ATTR_DIGITAL (0U)
#define PORT_GPIO_IP_PIN_ATTR_ANALOG  (1U)


/**
 * @brief  Port pin External falling rising.
 */
#define PORT_GPIO_IP_PIN_IT_OFF (0U)
#define PORT_GPIO_IP_PIN_IT_FT  (1U)
#define PORT_GPIO_IP_PIN_IT_RT  (2U)
#define PORT_GPIO_IP_PIN_IT_RFT (3U)

/***********************************************************************************************************************
 *                                       LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *                                                      EXTERN
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *                                                  LOCAL CONSTANTS
 **********************************************************************************************************************/
#define START_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"
/**
 * @brief   Export IPC configurations.
 */
PORT_IP_CONFIG_EXT
#define STOP_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"
/***********************************************************************************************************************
 *                                                  LOCAL VARIABLES
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *                                                 GLOBAL VARIABLES
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *                                             LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *                                                  LOCAL FUNCTION
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *                                                  GLOBAL FUNCTION
 **********************************************************************************************************************/


#ifdef __cplusplus
}
#endif

#endif /* PORT_GPIO_IP_H */

/*--------------------------------------------------- End Of File -----------------------------------------------------*/
