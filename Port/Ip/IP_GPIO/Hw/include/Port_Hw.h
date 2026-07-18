/***********************************************************************************************************************
 * Project Name: Classic_Autosar_02
 * 
 * File Name: Port_Hw.h
 *
 * Description: Implementation of Port_Hw HW Level layer
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

#ifndef PORT_HW_H
#define PORT_HW_H

#ifdef __cplusplus
extern "C" {
#endif

/***********************************************************************************************************************
 *                                                     INCLUDES 
 **********************************************************************************************************************/

#include "STM32F4.h"

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
 * @brief  Port maximum pin number
 */
#define PORT_PIN_NUM_MAX     (16U)


/**
 * @brief  Port pin source value.
 */
#define PORT_PIN_00  (0U)           /* Pin 00 selected   */
#define PORT_PIN_01  (1U)           /* Pin 01 selected   */
#define PORT_PIN_02  (2U)           /* Pin 02 selected   */
#define PORT_PIN_03  (3U)           /* Pin 03 selected   */
#define PORT_PIN_04  (4U)           /* Pin 04 selected   */
#define PORT_PIN_05  (5U)           /* Pin 05 selected   */
#define PORT_PIN_06  (6U)           /* Pin 06 selected   */
#define PORT_PIN_07  (7U)           /* Pin 07 selected   */
#define PORT_PIN_08  (8U)           /* Pin 08 selected   */
#define PORT_PIN_09  (9U)           /* Pin 09 selected   */
#define PORT_PIN_10  (10U)          /* Pin 10 selected   */
#define PORT_PIN_11  (11U)          /* Pin 11 selected   */
#define PORT_PIN_12  (12U)          /* Pin 12 selected   */
#define PORT_PIN_13  (13U)          /* Pin 13 selected   */
#define PORT_PIN_14  (14U)          /* Pin 14 selected   */
#define PORT_PIN_15  (15U)          /* Pin 15 selected   */
#define PORT_PIN_ALL (0xFFFFU)      /* All pins selected */


/**
 * @brief  Port group source value.
 */
#define PORT_GROUP_A (0U) /* Port A selected */
#define PORT_GROUP_B (1U) /* Port B selected */
#define PORT_GROUP_C (2U) /* Port C selected */
#define PORT_GROUP_D (3U) /* Port D selected */
#define PORT_GROUP_E (4U) /* Port E selected */
#define PORT_GROUP_F (5U) /* Port F selected */
#define PORT_GROUP_G (6U) /* Port G selected */
#define PORT_GROUP_H (7U) /* Port H selected */
#define PORT_GROUP_I (8U) /* Port I selected */


/**
 * @brief  Port output mode selection.
 */
#define PORT_FUNC_ALT15     (uint32)(15UL)
#define PORT_FUNC_ALT14     (uint32)(14UL)
#define PORT_FUNC_ALT13     (uint32)(13UL)
#define PORT_FUNC_ALT12     (uint32)(12UL)
#define PORT_FUNC_ALT11     (uint32)(11UL)
#define PORT_FUNC_ALT10     (uint32)(10UL)
#define PORT_FUNC_ALT9      (uint32)(9UL)
#define PORT_FUNC_ALT8      (uint32)(8UL)
#define PORT_FUNC_ALT7      (uint32)(7UL)
#define PORT_FUNC_ALT6      (uint32)(6UL)
#define PORT_FUNC_ALT5      (uint32)(5UL)
#define PORT_FUNC_ALT4      (uint32)(4UL)
#define PORT_FUNC_ALT3      (uint32)(3UL)
#define PORT_FUNC_ALT2      (uint32)(2UL)
#define PORT_FUNC_ALT1      (uint32)(1UL)
#define PORT_FUNC_ALT0      (uint32)(0UL)

#define GPIO_BASEADDR_TO_CODE(x) ((x == GPIOA) ? 0 : (x == GPIOB)     ? 1 \
												   : (x == GPIOC)	  ? 2 \
												   : (x == GPIOD)	  ? 3 \
												   : (x == GPIOE)	  ? 4 \
												   : (x == GPIOF)	  ? 5 \
												   : (x == GPIOG)	  ? 6 \
												   : (x == GPIOH)	  ? 7 \
												   : (x == GPIOI)	  ? 8 \
												   : 0)

#define GET_PORT_BASEADDR(x) ((x == PORT_GROUP_A) ? GPIOA : (x == PORT_GROUP_B)   ? GPIOB \
												   		  : (x == PORT_GROUP_C)	  ? GPIOC \
												   		  : (x == PORT_GROUP_D)	  ? GPIOD \
												   		  : (x == PORT_GROUP_E)	  ? GPIOE \
												   		  : (x == PORT_GROUP_F)	  ? GPIOF \
												   		  : (x == PORT_GROUP_G)	  ? GPIOG \
												   		  : (x == PORT_GROUP_H)	  ? GPIOH \
												   		  : (x == PORT_GROUP_I)	  ? GPIOI \
												   		  : 0)


/**
 * @brief  Port HW pin External falling rising.
 */
#define PORT_GPIO_HW_PIN_IT_OFF (0U)
#define PORT_GPIO_HW_PIN_IT_FT  (1U)
#define PORT_GPIO_HW_PIN_IT_RT  (2U)
#define PORT_GPIO_HW_PIN_IT_RFT (3U)
/***********************************************************************************************************************
 *                                       LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *                                                      EXTERN
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *                                                  LOCAL CONSTANTS
 **********************************************************************************************************************/

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

#endif /* PORT_HW_H */

/*--------------------------------------------------- End Of File -----------------------------------------------------*/
