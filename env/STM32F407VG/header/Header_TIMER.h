#if !defined(HEADER_TMR_H_)  
#define HEADER_TMR_H_

#include "Header.h"

typedef struct
{
  __O uint32_t CR1;         /* TIM control register 1               */
  __O uint32_t CR2;         /* TIM control register 2               */
  __O uint32_t SMCR;        /* TIM slave mode control register      */
  __O uint32_t DIER;        /* TIM DMA/interrupt enable register    */
  __O uint32_t SR;          /* TIM status register                  */
  __O uint32_t EGR;         /* TIM event generation register        */
  __O uint32_t CCMR1;       /* TIM capture/compare mode register 1  */
  __O uint32_t CCMR2;       /* TIM capture/compare mode register 2  */
  __O uint32_t CCER;        /* TIM capture/compare enable register  */
  __O uint32_t CNT;         /* TIM counter register                 */
  __O uint32_t PSC;         /* TIM prescaler                        */
  __O uint32_t ARR;         /* TIM auto-reload register             */
  __O uint32_t RCR;         /* TIM repetition counter register      */
  __O uint32_t CCR1;        /* TIM capture/compare register 1       */
  __O uint32_t CCR2;        /* TIM capture/compare register 2       */
  __O uint32_t CCR3;        /* TIM capture/compare register 3       */
  __O uint32_t CCR4;        /* TIM capture/compare register 4       */
  __O uint32_t BDTR;        /* TIM break and dead-time register     */
  __O uint32_t DCR;         /* TIM DMA control register             */
  __O uint32_t DMAR;        /* TIM DMA address for full transfer    */
  __O uint32_t OR;          /* TIM option register                  */
} TIM_RegDef_t;
#define TIM1                ((TIM_RegDef_t *) TIM1_BASEADDR)
#define TIM2                ((TIM_RegDef_t *) TIM2_BASEADDR)
#define TIM3                ((TIM_RegDef_t *) TIM3_BASEADDR)
#define TIM4                ((TIM_RegDef_t *) TIM4_BASEADDR)
#define TIM5                ((TIM_RegDef_t *) TIM5_BASEADDR)
#define TIM6                ((TIM_RegDef_t *) TIM6_BASEADDR)
#define TIM7                ((TIM_RegDef_t *) TIM7_BASEADDR)
#define TIM8                ((TIM_RegDef_t *) TIM8_BASEADDR)
#define TIM9                ((TIM_RegDef_t *) TIM9_BASEADDR)
#define TIM10               ((TIM_RegDef_t *) TIM10_BASEADDR)
#define TIM11               ((TIM_RegDef_t *) TIM11_BASEADDR)
#define TIM12               ((TIM_RegDef_t *) TIM12_BASEADDR)
#define TIM13               ((TIM_RegDef_t *) TIM13_BASEADDR)
#define TIM14               ((TIM_RegDef_t *) TIM14_BASEADDR)




#endif  /* #if !defined(HEADER_LPTMR_H_) */
