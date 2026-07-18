#ifndef HEADER_H_
#define HEADER_H_

/*************************************************** BEGIN Library C ****************************************************/
#include <stdint.h>
#include <stddef.h>
#include "Platform_Types.h"
/*************************************************** END Library C ******************************************************/

/*************************************************** Flags General ******************************************************/
#define __O     volatile             /* Defines 'write only' permissions                */
#define __IO    volatile             /* Defines 'read / write' permissions              */
#define __I     volatile const       /* Defines 'read only' permissions                 */

#define ENABLE              1
#define DISABLE             0
#define SET                 ENABLE
#define RESET               DISABLE
#define GPIO_PIN_SET        SET
#define GPIO_PIN_RESET      RESET
#define FLAG_RESET          RESET
#define FLAG_SET            SET
#define ON                  ENABLE
#define OFF                 DISABLE

/*************************************************** BEGIN Register Core and General **************************************/
#define CCMDATARAM_BASE       0x10000000UL /* CCM(core coupled memory) data RAM(64 KB) base address in the alias region  */
#define BKPSRAM_BASE          0x40024000UL /* Backup SRAM(4 KB) base address in the alias region                         */
#define SRAM1_BB_BASE         0x22000000UL /* SRAM1(112 KB) base address in the bit-band region                          */
#define SRAM2_BB_BASE         0x22380000UL /* SRAM2(16 KB) base address in the bit-band region                           */
#define PERIPH_BB_BASE        0x42000000UL /* Peripheral base address in the bit-band region                             */
#define BKPSRAM_BB_BASE       0x42480000UL /* Backup SRAM(4 KB) base address in the bit-band region                      */
#define FLASH_OTP_BASE        0x1FFF7800UL /* Base address of : (up to 528 Bytes) embedded FLASH OTP Area                */
#define FLASH_OTP_END         0x1FFF7A0FUL /* End address of : (up to 528 Bytes) embedded FLASH OTP Area                 */
#define CCMDATARAM_END        0x1000FFFFUL /* CCM data RAM end address                                                   */
#define PERIPH_BB_BASEADDR    0x40000000UL /* Base of bit band Peripheral*/

/* Memory mapping of Core Hardware */
#define SCS_BASE            (0xE000E000UL)                            /* System Control Space Base Address */
#define ITM_BASE            (0xE0000000UL)                            /* ITM Base Address */
#define DWT_BASE            (0xE0001000UL)                            /* DWT Base Address */
#define TPI_BASE            (0xE0040000UL)                            /* TPI Base Address */
#define CoreDebug_BASE      (0xE000EDF0UL)                            /* Core Debug Base Address */
#define SysTick_BASE        (SCS_BASE +  0x0010UL)                    /* SysTick Base Address */
#define NVIC_BASE           (SCS_BASE +  0x0100UL)                    /* NVIC Base Address */
#define SCB_BASE            (SCS_BASE +  0x0D00UL)                    /* System Control Block Base Address */
#define FPU_BASE            (SCS_BASE +  0x0F30UL)                    /* Floating Point Unit */
#define MPU_BASE          (SCS_BASE +  0x0D90UL)                      /* Memory Protection Unit */



/************************************************* Base address of register ***********************************************/
/*STEP 1*/ 
#define FLASH_BASEADDR 0x08000000UL
#define SRAM1_BASEADDR 0x20000000UL
#define SRAM2_BASEADDR 0x2001C000UL /* Ram2 = Ram 1+ size Ram 1:  112Kb   112x1024 = 114688 = 0x1C000*/
#define ROM_BASEADDR   0x1FFF0000UL
#define SRAM SRAM1_BASEADDR

/*STEP 2*/ 
#define PERIPH_BASEADDR 0x40000000UL
#define APB1PERIPH_BASEADDR PERIPH_BASEADDR
#define APB2PERIPH_BASEADDR 0x40010000UL
#define AHB1PERIPH_BASEADDR 0x40020000UL
#define AHB2PERIPH_BASEADDR 0x50000000UL
#define FSMC_BASEADDR 0xA0000000UL 

/*STEP 3 AHB1*/  
#define GPIOA_BASEADDR (AHB1PERIPH_BASEADDR + 0x0000UL)
#define GPIOA_BASEADDR (AHB1PERIPH_BASEADDR + 0x0000UL)
#define GPIOB_BASEADDR (AHB1PERIPH_BASEADDR + 0x0400UL)
#define GPIOC_BASEADDR (AHB1PERIPH_BASEADDR + 0x0800UL)
#define GPIOD_BASEADDR (AHB1PERIPH_BASEADDR + 0x0C00UL)
#define GPIOE_BASEADDR (AHB1PERIPH_BASEADDR + 0x1000UL)
#define GPIOF_BASEADDR (AHB1PERIPH_BASEADDR + 0x1400UL)
#define GPIOG_BASEADDR (AHB1PERIPH_BASEADDR + 0x1800UL)
#define GPIOH_BASEADDR (AHB1PERIPH_BASEADDR + 0x1C00UL)
#define GPIOI_BASEADDR (AHB1PERIPH_BASEADDR + 0x2000UL)
#define CRC_BASEADDR              (AHB1PERIPH_BASEADDR + 0x3000UL)
#define RCC_BASEADDR   			      (AHB1PERIPH_BASEADDR + 0x3800)
#define FLASH_R_BASEADDR          (AHB1PERIPH_BASEADDR + 0x3C00UL)
#define DMA1_BASEADDR             (AHB1PERIPH_BASEADDR + 0x6000UL)
#define DMA1_Stream0_BASEADDR     (DMA1_BASEADDR + 0x010UL)
#define DMA1_Stream1_BASEADDR     (DMA1_BASEADDR + 0x028UL)
#define DMA1_Stream2_BASEADDR     (DMA1_BASEADDR + 0x040UL)
#define DMA1_Stream3_BASEADDR     (DMA1_BASEADDR + 0x058UL)
#define DMA1_Stream4_BASEADDR     (DMA1_BASEADDR + 0x070UL)
#define DMA1_Stream5_BASEADDR     (DMA1_BASEADDR + 0x088UL)
#define DMA1_Stream6_BASEADDR     (DMA1_BASEADDR + 0x0A0UL)
#define DMA1_Stream7_BASEADDR     (DMA1_BASEADDR + 0x0B8UL)
#define DMA2_BASEADDR             (AHB1PERIPH_BASEADDR + 0x6400UL)
#define DMA2_Stream0_BASEADDR     (DMA2_BASEADDR + 0x010UL)
#define DMA2_Stream1_BASEADDR     (DMA2_BASEADDR + 0x028UL)
#define DMA2_Stream2_BASEADDR     (DMA2_BASEADDR + 0x040UL)
#define DMA2_Stream3_BASEADDR     (DMA2_BASEADDR + 0x058UL)
#define DMA2_Stream4_BASEADDR     (DMA2_BASEADDR + 0x070UL)
#define DMA2_Stream5_BASEADDR     (DMA2_BASEADDR + 0x088UL)
#define DMA2_Stream6_BASEADDR     (DMA2_BASEADDR + 0x0A0UL)
#define DMA2_Stream7_BASEADDR     (DMA2_BASEADDR + 0x0B8UL)
#define ETH_BASEADDR              (AHB1PERIPH_BASEADDR + 0x8000UL)
#define ETH_MAC_BASEADDR          (ETH_BASEADDR)
#define ETH_MMC_BASEADDR          (ETH_BASEADDR + 0x0100UL)
#define ETH_PTP_BASEADDR          (ETH_BASEADDR + 0x0700UL)
#define ETH_DMA_BASEADDR          (ETH_BASEADDR + 0x1000UL)

/* STEP 4 APB1 */
#define TIM2_BASEADDR            (APB1PERIPH_BASEADDR + 0x0000UL)
#define TIM3_BASEADDR            (APB1PERIPH_BASEADDR + 0x0400UL)
#define TIM4_BASEADDR            (APB1PERIPH_BASEADDR + 0x0800UL)
#define TIM5_BASEADDR            (APB1PERIPH_BASEADDR + 0x0C00UL)
#define TIM6_BASEADDR            (APB1PERIPH_BASEADDR + 0x1000UL)
#define TIM7_BASEADDR            (APB1PERIPH_BASEADDR + 0x1400UL)
#define TIM12_BASEADDR           (APB1PERIPH_BASEADDR + 0x1800UL)
#define TIM13_BASEADDR           (APB1PERIPH_BASEADDR + 0x1C00UL)
#define TIM14_BASEADDR           (APB1PERIPH_BASEADDR + 0x2000UL)
#define RTC_BASEADDR             (APB1PERIPH_BASEADDR + 0x2800UL)
#define WWDG_BASEADDR            (APB1PERIPH_BASEADDR + 0x2C00UL)
#define IWDG_BASEADDR            (APB1PERIPH_BASEADDR + 0x3000UL)
#define I2S2ext_BASEADDR         (APB1PERIPH_BASEADDR + 0x3400UL)
#define SPI2_BASEADDR            (APB1PERIPH_BASEADDR + 0x3800UL)
#define SPI3_BASEADDR            (APB1PERIPH_BASEADDR + 0x3C00UL)
#define I2S3ext_BASEADDR         (APB1PERIPH_BASEADDR + 0x4000UL)
#define USART2_BASEADDR          (APB1PERIPH_BASEADDR + 0x4400UL)
#define USART3_BASEADDR          (APB1PERIPH_BASEADDR + 0x4800UL)
#define UART4_BASEADDR           (APB1PERIPH_BASEADDR + 0x4C00UL)
#define UART5_BASEADDR           (APB1PERIPH_BASEADDR + 0x5000UL)
#define I2C1_BASEADDR            (APB1PERIPH_BASEADDR + 0x5400UL)
#define I2C2_BASEADDR            (APB1PERIPH_BASEADDR + 0x5800UL)
#define I2C3_BASEADDR            (APB1PERIPH_BASEADDR + 0x5C00UL)
#define CAN1_BASEADDR            (APB1PERIPH_BASEADDR + 0x6400UL)
#define CAN2_BASEADDR            (APB1PERIPH_BASEADDR + 0x6800UL)
#define PWR_BASEADDR             (APB1PERIPH_BASEADDR + 0x7000UL)
#define DAC_BASEADDR             (APB1PERIPH_BASEADDR + 0x7400UL)

/* STEP 5 APB2 */
#define TIM1_BASEADDR            (APB2PERIPH_BASEADDR+ 0x0000UL)
#define TIM8_BASEADDR            (APB2PERIPH_BASEADDR+ 0x0400UL)
#define USART1_BASEADDR          (APB2PERIPH_BASEADDR+ 0x1000UL)
#define USART6_BASEADDR          (APB2PERIPH_BASEADDR+ 0x1400UL)
#define ADC1_BASEADDR            (APB2PERIPH_BASEADDR+ 0x2000UL)
#define ADC2_BASEADDR            (APB2PERIPH_BASEADDR+ 0x2100UL)
#define ADC3_BASEADDR            (APB2PERIPH_BASEADDR+ 0x2200UL)
#define ADC123_COMMON_BASE       (APB2PERIPH_BASEADDR+ 0x2300UL)
#define ADC_BASEADDR             (APB2PERIPH_BASEADDR+ 0x2300UL)
#define SDIO_BASEADDR            (APB2PERIPH_BASEADDR+ 0x2C00UL)
#define SPI1_BASEADDR            (APB2PERIPH_BASEADDR+ 0x3000UL)
#define SYSCFG_BASEADDR          (APB2PERIPH_BASEADDR+ 0x3800UL)
#define EXTI_BASEADDR            (APB2PERIPH_BASEADDR+ 0x3C00UL)
#define TIM9_BASEADDR            (APB2PERIPH_BASEADDR+ 0x4000UL)
#define TIM10_BASEADDR           (APB2PERIPH_BASEADDR+ 0x4400UL)
#define TIM11_BASEADDR           (APB2PERIPH_BASEADDR+ 0x4800UL)

/* AHB2 peripherals */
#define DCMI_BASE             (AHB2PERIPH_BASE + 0x50000UL)
#define RNG_BASE              (AHB2PERIPH_BASE + 0x60800UL)

/* FSMC Bankx registers base address */
#define FSMC_Bank1_R_BASE     (FSMC_R_BASE + 0x0000UL)
#define FSMC_Bank1E_R_BASE    (FSMC_R_BASE + 0x0104UL)
#define FSMC_Bank2_3_R_BASE   (FSMC_R_BASE + 0x0060UL)
#define FSMC_Bank4_R_BASE     (FSMC_R_BASE + 0x00A0UL)

/* USB registers base address */
#define USB_OTG_HS_PERIPH_BASE               0x40040000UL
#define USB_OTG_FS_PERIPH_BASE               0x50000000UL
#define USB_OTG_GLOBAL_BASE                  0x000UL
#define USB_OTG_DEVICE_BASE                  0x800UL
#define USB_OTG_IN_ENDPOINT_BASE             0x900UL
#define USB_OTG_OUT_ENDPOINT_BASE            0xB00UL
#define USB_OTG_EP_REG_SIZE                  0x20UL
#define USB_OTG_HOST_BASE                    0x400UL
#define USB_OTG_HOST_PORT_BASE               0x440UL
#define USB_OTG_HOST_CHANNEL_BASE            0x500UL
#define USB_OTG_HOST_CHANNEL_SIZE            0x20UL
#define USB_OTG_PCGCCTL_BASE                 0xE00UL
#define USB_OTG_FIFO_BASE                    0x1000UL
#define USB_OTG_FIFO_SIZE                    0x1000UL

#define UID_BASE                             0x1FFF7A10UL           /* Unique device ID register base address */
#define FLASHSIZE_BASE                       0x1FFF7A22UL           /* FLASH Size register base address       */
#define PACKAGE_BASE                         0x1FFF7BF0UL           /* Package size register base address     */

/* Debug MCU registers base address */
#define DBGMCU_BASE                          0xE0042000UL


/************************************************* END Base address of register ***********************************************/

#define MPU_PRESENT                  1         /* Defines if an MPU is present or not */
#define NVIC_PRIO_BITS               4         /* Number of priority bits implemented in the NVIC */
#define FPU_PRESENT                  1         /* Defines if an FPU is present or not */

/**
* @brief 32 bits memory read macro.
*/
#define REG_READ32(address)               (*(volatile uint32_t*)(address))

/**
* @brief 32 bits memory write macro.
*/
#define REG_WRITE32(address, value)       ((*(volatile uint32_t*)(address))= (uint32_t)(value))

/**
* @brief 32 bits bits setting macro.
*/
#define REG_BIT_SET32(address, mask)      ((*(volatile uint32_t*)(address))|= (uint32_t)(mask))

/**
* @brief 32 bits bits clearing macro.
*/
#define REG_BIT_CLEAR32(address, mask)    ((*(volatile uint32_t*)(address))&= ((uint32_t)~((uint32_t)(mask))))

/**
* @brief 32 bit clear bits and set with new value
* @note It is user's responsability to make sure that value has only "mask" bits set - (value&~mask)==0
*/
#define REG_RMW32(address, mask, value)   (REG_WRITE32((address), ((REG_READ32(address)& ((uint32_t)~((uint32_t)(mask))))| ((uint32_t)(value)))))



#endif /* HEADER_H_ */