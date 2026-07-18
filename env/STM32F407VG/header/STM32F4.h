#include "Header_ADC.h"
#include "Header_CRC.h"
#include "Header_DMA.h"
#include "Header_GPIO.h"
#include "Header_I2C.h"
#include "Header_SPI.h"
#include "Header_UART.h"
#include "Header_NVIC.h"
#include "Header_GPIO.h"
#include "Header_SCB.h"
#include "Header_SYSTICK.h"
#include "Header_CAN.h"
#include "Header_FLASH.h"
#include "Header_TIMER.h"
#include "Header_FPU.h"
#include "Header_MPU.h"
#include "Header_PSR.h"
#include "Header_ETH.h"
#include "Header_WDOG.h"
#include "Header_SYSTEM.h"
#include "Header_MCU.h"
#include "Header.h"

/*************************************************** Begin Enable Clock ************************************/
/***********************************************************************************************************/
/***********************************************************************************************************/
/*
 * Clock Enable Macros for GPIOx peripherals
 */
#define GPIOA_PCLK_EN() (RCC->AHB1ENR |= (1 << 0)) /* Enable clock for port A */
#define GPIOB_PCLK_EN() (RCC->AHB1ENR |= (1 << 1)) /* Enable clock for port B */
#define GPIOC_PCLK_EN() (RCC->AHB1ENR |= (1 << 2)) /* Enable clock for port C */
#define GPIOD_PCLK_EN() (RCC->AHB1ENR |= (1 << 3)) /* Enable clock for port D */
#define GPIOE_PCLK_EN() (RCC->AHB1ENR |= (1 << 4)) /* Enable clock for port E */
#define GPIOF_PCLK_EN() (RCC->AHB1ENR |= (1 << 5)) /* Enable clock for port F */
#define GPIOG_PCLK_EN() (RCC->AHB1ENR |= (1 << 6)) /* Enable clock for port G */
#define GPIOH_PCLK_EN() (RCC->AHB1ENR |= (1 << 7)) /* Enable clock for port H */
#define GPIOI_PCLK_EN() (RCC->AHB1ENR |= (1 << 8)) /* Enable clock for port I */

/*
 * Clock Enable Macros for DMA peripherals
*/
#define DMA1_PCLK_EN() (RCC->AHB1ENR |= (1 << 21)) /* Enable clock for  DMA1*/
#define DMA2_PCLK_EN() (RCC->AHB1ENR |= (1 << 22)) /* Enable clock for  DMA2 */


/*
 * Clock Enable Macros for I2Cx peripherals
 */
#define I2C1_PCLK_EN() (RCC->APB1ENR |= (1 << 21)) /* Enable clock for I2C1 */
#define I2C2_PCLK_EN() (RCC->APB1ENR |= (1 << 22)) /* Enable clock for I2C2 */
#define I2C3_PCLK_EN() (RCC->APB1ENR |= (1 << 23)) /* Enable clock for I2C3 */

/*
 * Clock Enable Macros for TIMx peripherals
 */
#define TIM5_PCLK_EN() (RCC->APB1ENR |= (1 << 3))   /* Enable clock for TIM5 */
#define TIM1_PCLK_EN() (RCC->APB2ENR |= (1 << 0))   /* Enable clock for TIM1 */
#define TIM9_PCLK_EN() (RCC->APB2ENR |= (1 << 16))  /* Enable clock for TIM9 */
#define TIM11_PCLK_EN() (RCC->APB2ENR |= (1 << 18)) /* Enable clock for TIM11 */

/*
 * Clock Enable Macros for WWDG peripherals
 */
#define WWDG_PCLK_EN() (RCC->APB1ENR |= (1 << 11)) /* Enable clock for WWDG*/

/*
 * Clock Enable Macros for PWR peripherals
 */
#define PWR_PCLK_EN() (RCC->APB1ENR |= (1 << 28)) /* Enable clock for PWR*/



/*
 * Clock Enable Macros for SPIx peripheralsbu
 */
#define SPI1_PCLK_EN() (RCC->APB2ENR |= (1 << 12)) /*Enable clock for SPI1*/
#define SPI2_PCLK_EN() (RCC->APB1ENR |= (1 << 14)) /*Enable clock for SPI2*/
#define SPI3_PCLK_EN() (RCC->APB1ENR |= (1 << 15)) /*Enable clock for SPI3*/
#define SPI4_PCLK_EN() (RCC->APB2ENR |= (1 << 13)) /*Enable clock for SPI4*/

/*
 * Clock Enable Macros for USARTx peripherals
 */
#define USART1_PCCK_EN() (RCC->APB2ENR |= (1 << 4))  /*Enable clock for UART1*/
#define USART2_PCCK_EN() (RCC->APB1ENR |= (1 << 17)) /*Enable clock for UART2*/
#define USART3_PCCK_EN() (RCC->APB1ENR |= (1 << 18)) /*Enable clock for UART3*/
#define UART4_PCCK_EN() (RCC->APB1ENR |= (1 << 19))  /*Enable clock for UART4*/
#define UART5_PCCK_EN() (RCC->APB1ENR |= (1 << 20))  /*Enable clock for UART5*/
#define USART6_PCCK_EN() (RCC->APB1ENR |= (1 << 5))  /*Enable clock for UART6*/

/*
 * Clock Enable Macros for SYSCFG peripheral
 */
#define SYSCFG_PCLK_EN() (RCC->APB2ENR |= (1 << 14)) /*Enable clock for SYSCFG*/

/*
 * Clock Enable Macros for CANx peripherals
*/
#define CAN1_PCLK_EN() (RCC->APB1ENR |= (1 << 25)) /*Enable clock for  CAN1*/
#define CAN2_PCLK_EN() (RCC->APB1ENR |= (1 << 26)) /*Enable clock for  CAN2*/


/*************************************************** End Enable Clock ************************************/


/*************************************************** Begin Disable Clock ************************************/
/***********************************************************************************************************/
/***********************************************************************************************************/
/*
 * Clock Disable Macros for GPIOx peripherals
 */
#define GPIOA_PCLK_DI() (RCC->AHB1ENR &=~ (1 << 0)) /*Disable clock for port A*/
#define GPIOB_PCLK_DI() (RCC->AHB1ENR &=~ (1 << 1)) /*Disable clock for port B*/
#define GPIOC_PCLK_DI() (RCC->AHB1ENR &=~ (1 << 2)) /*Disable clock for port C*/
#define GPIOD_PCLK_DI() (RCC->AHB1ENR &=~ (1 << 3)) /*Disable clock for port D*/
#define GPIOE_PCLK_DI() (RCC->AHB1ENR &=~ (1 << 4)) /*Disable clock for port E*/
#define GPIOF_PCLK_DI() (RCC->AHB1ENR &=~ (1 << 5)) /*Disable clock for port F*/
#define GPIOG_PCLK_DI() (RCC->AHB1ENR &=~ (1 << 6)) /*Disable clock for port G*/
#define GPIOH_PCLK_DI() (RCC->AHB1ENR &=~ (1 << 7)) /*Disable clock for port H*/
#define GPIOI_PCLK_DI() (RCC->AHB1ENR &=~ (1 << 8)) /*Disable clock for port I*/

/*
 * Clock Enable Macros for DMA peripherals
*/
#define DMA1_PCLK_DI() (RCC->AHB1ENR &=~ (1 << 21)) /*Enable clock for  DMA1*/
#define DMA2_PCLK_DI() (RCC->AHB1ENR &=~ (1 << 22)) /*Enable clock for  DMA2*/

/*
 * Clock Disable Macros for SPIx peripherals
 */
#define I2C1_PCLK_DI() (RCC->APB1ENR &=~ (1 << 21))
#define I2C2_PCLK_DI() (RCC->APB1ENR &=~ (1 << 22))
#define I2C3_PCLK_DI() (RCC->APB1ENR &=~ (1 << 23))

/*
 * Clock Disable Macros for TIM5 peripherals
 */
#define TIM5_PCLK_DI() (RCC->APB1ENR &=~ (1 << 3)) /*Disable clock for TIM5*/

/*
 * Clock Disable Macros for WWDG peripherals
 */
#define WWDG_PCLK_DI() (RCC->APB1ENR &=~ (1 << 11)) /*Disable clock for WWDG*/

/*
 * Clock Disable Macros for PWR peripherals
 */
#define PWR_PCLK_DI() (RCC->APB1ENR &=~ (1 << 28)) /*Disable clock for PWR*/

/*
 * Clock Disable Macros for SPI peripherals
 */
#define SPI1_PCLK_DI() (RCC->APB2ENR &=~ (1 << 12))
#define SPI2_PCLK_DI() (RCC->APB1ENR &=~ (1 << 14))
#define SPI3_PCLK_DI() (RCC->APB1ENR &=~ (1 << 15))
#define SPI4_PCLK_DI() (RCC->APB2ENR &=~ (1 << 13))

/*
 * Clock Disable Macros for USART peripheral
 */
#define USART1_PCCK_DI() (RCC->APB2ENR &=~ (1 << 4))
#define USART2_PCCK_DI() (RCC->APB1ENR &=~ (1 << 17))
#define USART3_PCCK_DI() (RCC->APB1ENR &=~ (1 << 18))
#define UART4_PCCK_DI() (RCC->APB1ENR &=~ (1 << 19))
#define UART5_PCCK_DI() (RCC->APB1ENR &=~ (1 << 20))
#define USART6_PCCK_DI() (RCC->APB1ENR &=~ (1 << 5))

/*
 * Clock Disable Macros for SYSCFG peripheral
 */
#define SYSCFG_PCLK_DI() (RCC->APB2ENR &=~ (1 << 14))

/*
 * Clock Disable Macros for CANx peripherals
 */
#define CAN1_PCLK_DI() (RCC->APB1ENR &=~ (1 << 25)) /*Disable clock for  CAN1*/
#define CAN2_PCLK_DI() (RCC->APB1ENR &=~ (1 << 26)) /*Disable clock for  CAN2*/



/*************************************************** End Disable Clock ****************************************************************/


/*************************************************** Begin Reset Register Module  *****************************************************/
/**************************************************************************************************************************************/
/**************************************************************************************************************************************/

#define GPIOA_REG_RESET()     do {  (RCC->AHB1RSTR |= (1 << 0));  (RCC->AHB1RSTR &= ~(1 << 0)); } while(0)
#define GPIOB_REG_RESET()     do {  (RCC->AHB1RSTR |= (1 << 1));  (RCC->AHB1RSTR &= ~(1 << 1)); } while(0)
#define GPIOC_REG_RESET()     do {  (RCC->AHB1RSTR |= (1 << 2));  (RCC->AHB1RSTR &= ~(1 << 2)); } while(0)
#define GPIOD_REG_RESET()     do {  (RCC->AHB1RSTR |= (1 << 3));  (RCC->AHB1RSTR &= ~(1 << 3)); } while(0)
#define GPIOE_REG_RESET()     do {  (RCC->AHB1RSTR |= (1 << 4));  (RCC->AHB1RSTR &= ~(1 << 4)); } while(0)
#define GPIOF_REG_RESET()     do {  (RCC->AHB1RSTR |= (1 << 5));  (RCC->AHB1RSTR &= ~(1 << 5)); } while(0)
#define GPIOG_REG_RESET()     do {  (RCC->AHB1RSTR |= (1 << 6));  (RCC->AHB1RSTR &= ~(1 << 6)); } while(0)
#define GPIOH_REG_RESET()     do {  (RCC->AHB1RSTR |= (1 << 7));  (RCC->AHB1RSTR &= ~(1 << 7)); } while(0)
#define GPIOI_REG_RESET()     do {  (RCC->AHB1RSTR |= (1 << 8));  (RCC->AHB1RSTR &= ~(1 << 8)); } while(0)


/*************************************************** End Reset Register Module  *****************************************************/