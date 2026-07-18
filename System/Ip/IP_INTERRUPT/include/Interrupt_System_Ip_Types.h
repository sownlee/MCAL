/***********************************************************************************************************************
 * Project Name: HuLa STM
 * 
 * File Name: Interrupt_System_Ip_Types.h
 *
 * Description: Implementation of Interrupt_System_Ip_Types High Level layer
 *              
 * AutoSAR Version:         4.4.0
 *
 * Compiler: GCC IAR
 *
 * Revision:
 *              Version         Date                Change History
 *              0.9.0          23/02/2024           Initial version
 *
 **********************************************************************************************************************/

#ifndef INTERRUPT_SYSTEM_TYPE_H
#define INTERRUPT_SYSTEM_TYPE_H

#ifdef __cplusplus
extern "C" {
#endif

/***********************************************************************************************************************
 *                                                     INCLUDES AND 
 **********************************************************************************************************************/
#include "Std_Types.h"
#include "Interrupt_System_Ip_Devassert.h"
/***********************************************************************************************************************
 *                                                 SOURCE FILE VERSION
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *                                                 FILE VERSION CHECK
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *                                                   LOCAL MACROS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *                                       LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
 **********************************************************************************************************************/
/**
 * @brief Function pointer type to void/void function
 */
typedef void (*func_ptr_t)(void);

/**
 * @brief  Interrupt priority brief.
 */
typedef enum
{
    INTERRUPT_SYSTEM_IP_PRIORITY_0 = 0U,     /* The Priority for Interrupt channel is 0. */
    INTERRUPT_SYSTEM_IP_PRIORITY_1 = 1U,     /* The Priority for Interrupt channel is 1. */
    INTERRUPT_SYSTEM_IP_PRIORITY_2 = 2U,     /* The Priority for Interrupt channel is 2. */
    INTERRUPT_SYSTEM_IP_PRIORITY_3 = 3U,     /* The Priority for Interrupt channel is 3. */
    INTERRUPT_SYSTEM_IP_PRIORITY_4 = 4U,     /* The Priority for Interrupt channel is 4. */
    INTERRUPT_SYSTEM_IP_PRIORITY_5 = 5U,     /* The Priority for Interrupt channel is 5. */
    INTERRUPT_SYSTEM_IP_PRIORITY_6 = 6U,     /* The Priority for Interrupt channel is 6. */
    INTERRUPT_SYSTEM_IP_PRIORITY_7 = 7U,     /* The Priority for Interrupt channel is 7. */
    INTERRUPT_SYSTEM_IP_PRIORITY_8 = 8U,     /* The Priority for Interrupt channel is 8. */
    INTERRUPT_SYSTEM_IP_PRIORITY_9 = 9U,     /* The Priority for Interrupt channel is 9. */
    INTERRUPT_SYSTEM_IP_PRIORITY_10 = 10U,   /* The Priority for Interrupt channel is 10. */
    INTERRUPT_SYSTEM_IP_PRIORITY_11 = 11U,   /* The Priority for Interrupt channel is 11. */
    INTERRUPT_SYSTEM_IP_PRIORITY_12 = 12U,   /* The Priority for Interrupt channel is 12. */
    INTERRUPT_SYSTEM_IP_PRIORITY_13 = 13U,   /* The Priority for Interrupt channel is 13. */
    INTERRUPT_SYSTEM_IP_PRIORITY_14 = 14U,   /* The Priority for Interrupt channel is 14. */
    INTERRUPT_SYSTEM_IP_PRIORITY_15 = 15U,   /* The Priority for Interrupt channel is 15. */
    INTERRUPT_SYSTEM_IP_PRIORITY_NONE = 16U, /* The Priority for Interrupt channel should be lower than 16. */      
} Interrupt_System_Ip_IntPriorityType;


/* Interrupt Number Definitions */
#define NUMBER_OF_INT_VECTORS 139                /* Number of interrupts in the Vector table */

typedef enum
{
/* Auxiliary constants */
  NotAvail_IRQn                = -128,  /* Not available device specific interrupt */
/******  Cortex-M4 Processor Exceptions Numbers ****************************************************************/
  NonMaskableInt_IRQn         = -14,    /* 2 Non Maskable Interrupt                                          */
  MemoryManagement_IRQn       = -12,    /* 4 Cortex-M4 Memory Management Interrupt                           */
  BusFault_IRQn               = -11,    /* 5 Cortex-M4 Bus Fault Interrupt                                   */
  UsageFault_IRQn             = -10,    /* 6 Cortex-M4 Usage Fault Interrupt                                 */
  SVCall_IRQn                 = -5,     /* 11 Cortex-M4 SV Call Interrupt                                    */
  DebugMonitor_IRQn           = -4,     /* 12 Cortex-M4 Debug Monitor Interrupt                              */
  PendSV_IRQn                 = -2,     /* 14 Cortex-M4 Pend SV Interrupt                                    */
  SysTick_IRQn                = -1,     /* 15 Cortex-M4 System Tick Interrupt                                */
/******  STM32 specific Interrupt Numbers **********************************************************************/
  WWDG_IRQn                   = 0,      /* Window WatchDog Interrupt                                         */
  PVD_IRQn                    = 1,      /* PVD through EXTI Line detection Interrupt                         */
  TAMP_STAMP_IRQn             = 2,      /* Tamper and TimeStamp interrupts through the EXTI line             */
  RTC_WKUP_IRQn               = 3,      /* RTC Wakeup interrupt through the EXTI line                        */
  FLASH_IRQn                  = 4,      /* FLASH global Interrupt                                            */
  RCC_IRQn                    = 5,      /* RCC global Interrupt                                              */
  EXTI0_IRQn                  = 6,      /* EXTI Line0 Interrupt                                              */
  EXTI1_IRQn                  = 7,      /* EXTI Line1 Interrupt                                              */
  EXTI2_IRQn                  = 8,      /* EXTI Line2 Interrupt                                              */
  EXTI3_IRQn                  = 9,      /* EXTI Line3 Interrupt                                              */
  EXTI4_IRQn                  = 10,     /* EXTI Line4 Interrupt                                              */
  DMA1_Stream0_IRQn           = 11,     /* DMA1 Stream 0 global Interrupt                                    */
  DMA1_Stream1_IRQn           = 12,     /* DMA1 Stream 1 global Interrupt                                    */
  DMA1_Stream2_IRQn           = 13,     /* DMA1 Stream 2 global Interrupt                                    */
  DMA1_Stream3_IRQn           = 14,     /* DMA1 Stream 3 global Interrupt                                    */
  DMA1_Stream4_IRQn           = 15,     /* DMA1 Stream 4 global Interrupt                                    */
  DMA1_Stream5_IRQn           = 16,     /* DMA1 Stream 5 global Interrupt                                    */
  DMA1_Stream6_IRQn           = 17,     /* DMA1 Stream 6 global Interrupt                                    */
  ADC_IRQn                    = 18,     /* ADC1, ADC2 and ADC3 global Interrupts                             */
  CAN1_TX_IRQn                = 19,     /* CAN1 TX Interrupt                                                 */
  CAN1_RX0_IRQn               = 20,     /* CAN1 RX0 Interrupt                                                */
  CAN1_RX1_IRQn               = 21,     /* CAN1 RX1 Interrupt                                                */
  CAN1_SCE_IRQn               = 22,     /* CAN1 SCE Interrupt                                                */
  EXTI9_5_IRQn                = 23,     /* External Line[9:5] Interrupts                                     */
  TIM1_BRK_TIM9_IRQn          = 24,     /* TIM1 Break interrupt and TIM9 global interrupt                    */
  TIM1_UP_TIM10_IRQn          = 25,     /* TIM1 Update Interrupt and TIM10 global interrupt                  */
  TIM1_TRG_COM_TIM11_IRQn     = 26,     /* TIM1 Trigger and Commutation Interrupt and TIM11 global interrupt */
  TIM1_CC_IRQn                = 27,     /* TIM1 Capture Compare Interrupt                                    */
  TIM2_IRQn                   = 28,     /* TIM2 global Interrupt                                             */
  TIM3_IRQn                   = 29,     /* TIM3 global Interrupt                                             */
  TIM4_IRQn                   = 30,     /* TIM4 global Interrupt                                             */
  I2C1_EV_IRQn                = 31,     /* I2C1 Event Interrupt                                              */
  I2C1_ER_IRQn                = 32,     /* I2C1 Error Interrupt                                              */
  I2C2_EV_IRQn                = 33,     /* I2C2 Event Interrupt                                              */
  I2C2_ER_IRQn                = 34,     /* I2C2 Error Interrupt                                              */
  SPI1_IRQn                   = 35,     /* SPI1 global Interrupt                                             */
  SPI2_IRQn                   = 36,     /* SPI2 global Interrupt                                             */
  USART1_IRQn                 = 37,     /* USART1 global Interrupt                                           */
  USART2_IRQn                 = 38,     /* USART2 global Interrupt                                           */
  USART3_IRQn                 = 39,     /* USART3 global Interrupt                                           */
  EXTI15_10_IRQn              = 40,     /* External Line[15:10] Interrupts                                   */
  RTC_Alarm_IRQn              = 41,     /* RTC Alarm (A and B) through EXTI Line Interrupt                   */
  OTG_FS_WKUP_IRQn            = 42,     /* USB OTG FS Wakeup through EXTI line interrupt                     */
  TIM8_BRK_TIM12_IRQn         = 43,     /* TIM8 Break Interrupt and TIM12 global interrupt                   */
  TIM8_UP_TIM13_IRQn          = 44,     /* TIM8 Update Interrupt and TIM13 global interrupt                  */
  TIM8_TRG_COM_TIM14_IRQn     = 45,     /* TIM8 Trigger and Commutation Interrupt and TIM14 global interrupt */
  TIM8_CC_IRQn                = 46,     /* TIM8 Capture Compare global interrupt                             */
  DMA1_Stream7_IRQn           = 47,     /* DMA1 Stream7 Interrupt                                            */
  FSMC_IRQn                   = 48,     /* FSMC global Interrupt                                             */
  SDIO_IRQn                   = 49,     /* SDIO global Interrupt                                             */
  TIM5_IRQn                   = 50,     /* TIM5 global Interrupt                                             */
  SPI3_IRQn                   = 51,     /* SPI3 global Interrupt                                             */
  UART4_IRQn                  = 52,     /* UART4 global Interrupt                                            */
  UART5_IRQn                  = 53,     /* UART5 global Interrupt                                            */
  TIM6_DAC_IRQn               = 54,     /* TIM6 global and DAC1&2 underrun error  interrupts                 */
  TIM7_IRQn                   = 55,     /* TIM7 global interrupt                                             */
  DMA2_Stream0_IRQn           = 56,     /* DMA2 Stream 0 global Interrupt                                    */
  DMA2_Stream1_IRQn           = 57,     /* DMA2 Stream 1 global Interrupt                                    */
  DMA2_Stream2_IRQn           = 58,     /* DMA2 Stream 2 global Interrupt                                    */
  DMA2_Stream3_IRQn           = 59,     /* DMA2 Stream 3 global Interrupt                                    */
  DMA2_Stream4_IRQn           = 60,     /* DMA2 Stream 4 global Interrupt                                    */
  ETH_IRQn                    = 61,     /* Ethernet global Interrupt                                         */
  ETH_WKUP_IRQn               = 62,     /* Ethernet Wakeup through EXTI line Interrupt                       */
  CAN2_TX_IRQn                = 63,     /* CAN2 TX Interrupt                                                 */
  CAN2_RX0_IRQn               = 64,     /* CAN2 RX0 Interrupt                                                */
  CAN2_RX1_IRQn               = 65,     /* CAN2 RX1 Interrupt                                                */
  CAN2_SCE_IRQn               = 66,     /* CAN2 SCE Interrupt                                                */
  OTG_FS_IRQn                 = 67,     /* USB OTG FS global Interrupt                                       */
  DMA2_Stream5_IRQn           = 68,     /* DMA2 Stream 5 global interrupt                                    */
  DMA2_Stream6_IRQn           = 69,     /* DMA2 Stream 6 global interrupt                                    */
  DMA2_Stream7_IRQn           = 70,     /* DMA2 Stream 7 global interrupt                                    */
  USART6_IRQn                 = 71,     /* USART6 global interrupt                                           */
  I2C3_EV_IRQn                = 72,     /* I2C3 event interrupt                                              */
  I2C3_ER_IRQn                = 73,     /* I2C3 error interrupt                                              */
  OTG_HS_EP1_OUT_IRQn         = 74,     /* USB OTG HS End Point 1 Out global interrupt                       */
  OTG_HS_EP1_IN_IRQn          = 75,     /* USB OTG HS End Point 1 In global interrupt                        */
  OTG_HS_WKUP_IRQn            = 76,     /* USB OTG HS Wakeup through EXTI interrupt                          */
  OTG_HS_IRQn                 = 77,     /* USB OTG HS global interrupt                                       */
  DCMI_IRQn                   = 78,     /* DCMI global interrupt                                             */
  RNG_IRQn                    = 80,     /* RNG global Interrupt                                              */
  FPU_IRQn                    = 81      /* FPU global interrupt                                               */
} IRQn_Type;


/* IRQ number for EXTI*/
/* 
#define IRQ_NO_EXTI0 6
#define IRQ_NO_EXTI1 7
#define IRQ_NO_EXTI2 8
#define IRQ_NO_EXTI3 9
#define IRQ_NO_EXTI4 10
#define IRQ_NO_EXTI9_5 23
#define IRQ_NO_EXTI15_10 40 
*/

/* IRQ number for SPI*/
/* 
#define IRQ_NO_SPI1 35
#define IRQ_NO_SPI2 36
#define IRQ_NO_SPI3 51 
*/

/* IRQ number for UART*/
/* 
#define IRQ_NO_USART1 37
#define IRQ_NO_USART2 38
#define IRQ_NO_USART3 39
#define IRQ_NO_UART4 52
#define IRQ_NO_UART5 53
#define IRQ_NO_USART6 71 
*/

/* IRQ number for I2C*/
/*
#define IRQ_NO_I2C1_EV 31
#define IRQ_NO_I2C1_ER 32
#define IRQ_NO_I2C2_EV 33
#define IRQ_NO_I2C2_ER 34
#define IRQ_NO_I2C3_EV 72
#define IRQ_NO_I2C3_ER 73
*/

/* IRQ number for CAN*/
/*
#define IRQ_NO_CAN1_TX  19
#define IRQ_NO_CAN1_RX0 20
#define IRQ_NO_CAN1_RX1 21
#define IRQ_NO_CAN1_SCE 22
*/

/* 
#define IRQ_NO_CAN2_TX  63
#define IRQ_NO_CAN2_RX0 64
#define IRQ_NO_CAN2_RX1 65
#define IRQ_NO_CAN2_SCE 66
*/

/* IRQ number for DMA*/
/*
#define IRQ_NO_DMA1_SREAM_0 11
#define IRQ_NO_DMA1_SREAM_1 12
#define IRQ_NO_DMA1_SREAM_2 13
#define IRQ_NO_DMA1_SREAM_3 14
#define IRQ_NO_DMA1_SREAM_4 15
#define IRQ_NO_DMA1_SREAM_5 16
#define IRQ_NO_DMA1_SREAM_6 17
#define IRQ_NO_DMA1_SREAM_7 47
#define IRQ_NO_DMA2_SREAM_0 56
#define IRQ_NO_DMA2_SREAM_1 57
#define IRQ_NO_DMA2_SREAM_2 58
#define IRQ_NO_DMA2_SREAM_3 59
#define IRQ_NO_DMA2_SREAM_4 60
#define IRQ_NO_DMA2_SREAM_5 68
#define IRQ_NO_DMA2_SREAM_6 69
#define IRQ_NO_DMA2_SREAM_7 70
*/


/**
 * @brief  The structure for intc configuration set element member.
 */
typedef struct Interrupt_System_Ip_InterruptConfigSetElementMember_t
{
    IRQn_Type IrqNum;                                      /* The number of Irq. */
    func_ptr_t IrqHandler;                                 /* The interrupt handler for Irq. */
    Interrupt_System_Ip_IntPriorityType IntPriority;       /* The interrupt priority for Irq. */
}  Interrupt_System_Ip_InterruptConfigSetElementMemberType;

/**
 * @brief  The structure for intc configuration set element.
 */
typedef struct Interrupt_System_IP_InterruptConfigSetElement_t
{
    uint8 NumberOfConfigIrq_u8;                                                                  /* The total number IRQ configured. */ 
    Interrupt_System_Ip_InterruptConfigSetElementMemberType *InterruptConfigSetElementMem_ptr;   /* Pointer to Interrupt configure set element. */    
}  Interrupt_System_IP_InterruptConfigSetElementType;

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

#endif /* INTERRUPT_SYSTEM_TYPE_H */

/*--------------------------------------------------- EOF -----------------------------------------------------*/