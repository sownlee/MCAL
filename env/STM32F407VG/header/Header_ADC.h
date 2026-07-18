#if !defined(HEADER_ADC_H_)  
#define HEADER_ADC_H_

#include "Header.h"

typedef struct
{
  __IO uint32_t SR;     /* ADC status register,                          */
  __IO uint32_t CR1;    /* ADC control register 1,                       */
  __IO uint32_t CR2;    /* ADC control register 2,                       */
  __IO uint32_t SMPR1;  /* ADC sample time register 1,                   */
  __IO uint32_t SMPR2;  /* ADC sample time register 2,                   */
  __IO uint32_t JOFR1;  /* ADC injected channel data offset register 1,  */
  __IO uint32_t JOFR2;  /* ADC injected channel data offset register 2,  */
  __IO uint32_t JOFR3;  /* ADC injected channel data offset register 3,  */
  __IO uint32_t JOFR4;  /* ADC injected channel data offset register 4,  */
  __IO uint32_t HTR;    /* ADC watchdog higher threshold register,       */
  __IO uint32_t LTR;    /* ADC watchdog lower threshold register,        */
  __IO uint32_t SQR1;   /* ADC regular sequence register 1,              */
  __IO uint32_t SQR2;   /* ADC regular sequence register 2,              */
  __IO uint32_t SQR3;   /* ADC regular sequence register 3,              */
  __IO uint32_t JSQR;   /* ADC injected sequence register,              */
  __IO uint32_t JDR1;   /* ADC injected data register 1,                 */
  __IO uint32_t JDR2;   /* ADC injected data register 2,                 */
  __IO uint32_t JDR3;   /* ADC injected data register 3,                 */
  __IO uint32_t JDR4;   /* ADC injected data register 4,                 */
  __IO uint32_t DR;     /* ADC regular data register,                    */
} ADC_TypeDef;

typedef struct
{
  __IO uint32_t CSR;    /* ADC Common status register,                   */
  __IO uint32_t CCR;    /* ADC common control register,                  */
  __IO uint32_t CDR;    /* ADC common regular data register for dual AND triple modes  */
} ADC_Common_TypeDef;

#define ADC1                ((ADC_TypeDef *) ADC1_BASEADDR)
#define ADC2                ((ADC_TypeDef *) ADC2_BASEADDR)
#define ADC3                ((ADC_TypeDef *) ADC3_BASEADDR)
#define ADC123_COMMON       ((ADC_Common_TypeDef *) ADC123_COMMON_BASE)

/********************  Bit definition for ADC_SR register  ********************/
#define ADC_SR_AWD_Pos            (0U)                                         
#define ADC_SR_AWD_Msk            (0x1UL << ADC_SR_AWD_Pos)                     
#define ADC_SR_AWD                ADC_SR_AWD_Msk                             
#define ADC_SR_EOC_Pos            (1U)                                       
#define ADC_SR_EOC_Msk            (0x1UL << ADC_SR_EOC_Pos)                  
#define ADC_SR_EOC                ADC_SR_EOC_Msk                             
#define ADC_SR_JEOC_Pos           (2U)                                       
#define ADC_SR_JEOC_Msk           (0x1UL << ADC_SR_JEOC_Pos)                 
#define ADC_SR_JEOC               ADC_SR_JEOC_Msk                            
#define ADC_SR_JSTRT_Pos          (3U)                                       
#define ADC_SR_JSTRT_Msk          (0x1UL << ADC_SR_JSTRT_Pos)                
#define ADC_SR_JSTRT              ADC_SR_JSTRT_Msk                           
#define ADC_SR_STRT_Pos           (4U)                                       
#define ADC_SR_STRT_Msk           (0x1UL << ADC_SR_STRT_Pos)                 
#define ADC_SR_STRT               ADC_SR_STRT_Msk                            
#define ADC_SR_OVR_Pos            (5U)                                       
#define ADC_SR_OVR_Msk            (0x1UL << ADC_SR_OVR_Pos)                  
#define ADC_SR_OVR                ADC_SR_OVR_Msk                             

/*******************  Bit definition for ADC_CR1 register  ********************/
#define ADC_CR1_AWDCH_Pos         (0U)                                         
#define ADC_CR1_AWDCH_Msk         (0x1FUL << ADC_CR1_AWDCH_Pos)                 
#define ADC_CR1_AWDCH             ADC_CR1_AWDCH_Msk                            
#define ADC_CR1_AWDCH_0           (0x01UL << ADC_CR1_AWDCH_Pos)                 
#define ADC_CR1_AWDCH_1           (0x02UL << ADC_CR1_AWDCH_Pos)                 
#define ADC_CR1_AWDCH_2           (0x04UL << ADC_CR1_AWDCH_Pos)                 
#define ADC_CR1_AWDCH_3           (0x08UL << ADC_CR1_AWDCH_Pos)                 
#define ADC_CR1_AWDCH_4           (0x10UL << ADC_CR1_AWDCH_Pos)                 
#define ADC_CR1_EOCIE_Pos         (5U)                                         
#define ADC_CR1_EOCIE_Msk         (0x1UL << ADC_CR1_EOCIE_Pos)                  
#define ADC_CR1_EOCIE             ADC_CR1_EOCIE_Msk                          
#define ADC_CR1_AWDIE_Pos         (6U)                                       
#define ADC_CR1_AWDIE_Msk         (0x1UL << ADC_CR1_AWDIE_Pos)               
#define ADC_CR1_AWDIE             ADC_CR1_AWDIE_Msk                          
#define ADC_CR1_JEOCIE_Pos        (7U)                                       
#define ADC_CR1_JEOCIE_Msk        (0x1UL << ADC_CR1_JEOCIE_Pos)              
#define ADC_CR1_JEOCIE            ADC_CR1_JEOCIE_Msk                         
#define ADC_CR1_SCAN_Pos          (8U)                                       
#define ADC_CR1_SCAN_Msk          (0x1UL << ADC_CR1_SCAN_Pos)                
#define ADC_CR1_SCAN              ADC_CR1_SCAN_Msk                           
#define ADC_CR1_AWDSGL_Pos        (9U)                                       
#define ADC_CR1_AWDSGL_Msk        (0x1UL << ADC_CR1_AWDSGL_Pos)              
#define ADC_CR1_AWDSGL            ADC_CR1_AWDSGL_Msk                         
#define ADC_CR1_JAUTO_Pos         (10U)                                      
#define ADC_CR1_JAUTO_Msk         (0x1UL << ADC_CR1_JAUTO_Pos)               
#define ADC_CR1_JAUTO             ADC_CR1_JAUTO_Msk                          
#define ADC_CR1_DISCEN_Pos        (11U)                                      
#define ADC_CR1_DISCEN_Msk        (0x1UL << ADC_CR1_DISCEN_Pos)              
#define ADC_CR1_DISCEN            ADC_CR1_DISCEN_Msk                         
#define ADC_CR1_JDISCEN_Pos       (12U)                                      
#define ADC_CR1_JDISCEN_Msk       (0x1UL << ADC_CR1_JDISCEN_Pos)             
#define ADC_CR1_JDISCEN           ADC_CR1_JDISCEN_Msk                        
#define ADC_CR1_DISCNUM_Pos       (13U)                                      
#define ADC_CR1_DISCNUM_Msk       (0x7UL << ADC_CR1_DISCNUM_Pos)             
#define ADC_CR1_DISCNUM           ADC_CR1_DISCNUM_Msk                        
#define ADC_CR1_DISCNUM_0         (0x1UL << ADC_CR1_DISCNUM_Pos)             
#define ADC_CR1_DISCNUM_1         (0x2UL << ADC_CR1_DISCNUM_Pos)             
#define ADC_CR1_DISCNUM_2         (0x4UL << ADC_CR1_DISCNUM_Pos)             
#define ADC_CR1_JAWDEN_Pos        (22U)                                      
#define ADC_CR1_JAWDEN_Msk        (0x1UL << ADC_CR1_JAWDEN_Pos)              
#define ADC_CR1_JAWDEN            ADC_CR1_JAWDEN_Msk                         
#define ADC_CR1_AWDEN_Pos         (23U)                                      
#define ADC_CR1_AWDEN_Msk         (0x1UL << ADC_CR1_AWDEN_Pos)               
#define ADC_CR1_AWDEN             ADC_CR1_AWDEN_Msk                          
#define ADC_CR1_RES_Pos           (24U)                                      
#define ADC_CR1_RES_Msk           (0x3UL << ADC_CR1_RES_Pos)                 
#define ADC_CR1_RES               ADC_CR1_RES_Msk                            
#define ADC_CR1_RES_0             (0x1UL << ADC_CR1_RES_Pos)                 
#define ADC_CR1_RES_1             (0x2UL << ADC_CR1_RES_Pos)                 
#define ADC_CR1_OVRIE_Pos         (26U)                                      
#define ADC_CR1_OVRIE_Msk         (0x1UL << ADC_CR1_OVRIE_Pos)               
#define ADC_CR1_OVRIE             ADC_CR1_OVRIE_Msk                          
  
/*******************  Bit definition for ADC_CR2 register  ********************/
#define ADC_CR2_ADON_Pos          (0U)                                         
#define ADC_CR2_ADON_Msk          (0x1UL << ADC_CR2_ADON_Pos)                   
#define ADC_CR2_ADON              ADC_CR2_ADON_Msk                           
#define ADC_CR2_CONT_Pos          (1U)                                       
#define ADC_CR2_CONT_Msk          (0x1UL << ADC_CR2_CONT_Pos)                
#define ADC_CR2_CONT              ADC_CR2_CONT_Msk                           
#define ADC_CR2_DMA_Pos           (8U)                                       
#define ADC_CR2_DMA_Msk           (0x1UL << ADC_CR2_DMA_Pos)                 
#define ADC_CR2_DMA               ADC_CR2_DMA_Msk                            
#define ADC_CR2_DDS_Pos           (9U)                                       
#define ADC_CR2_DDS_Msk           (0x1UL << ADC_CR2_DDS_Pos)                 
#define ADC_CR2_DDS               ADC_CR2_DDS_Msk                            
#define ADC_CR2_EOCS_Pos          (10U)                                      
#define ADC_CR2_EOCS_Msk          (0x1UL << ADC_CR2_EOCS_Pos)                
#define ADC_CR2_EOCS              ADC_CR2_EOCS_Msk                           
#define ADC_CR2_ALIGN_Pos         (11U)                                      
#define ADC_CR2_ALIGN_Msk         (0x1UL << ADC_CR2_ALIGN_Pos)               
#define ADC_CR2_ALIGN             ADC_CR2_ALIGN_Msk                          
#define ADC_CR2_JEXTSEL_Pos       (16U)                                      
#define ADC_CR2_JEXTSEL_Msk       (0xFUL << ADC_CR2_JEXTSEL_Pos)             
#define ADC_CR2_JEXTSEL           ADC_CR2_JEXTSEL_Msk                        
#define ADC_CR2_JEXTSEL_0         (0x1UL << ADC_CR2_JEXTSEL_Pos)             
#define ADC_CR2_JEXTSEL_1         (0x2UL << ADC_CR2_JEXTSEL_Pos)             
#define ADC_CR2_JEXTSEL_2         (0x4UL << ADC_CR2_JEXTSEL_Pos)             
#define ADC_CR2_JEXTSEL_3         (0x8UL << ADC_CR2_JEXTSEL_Pos)             
#define ADC_CR2_JEXTEN_Pos        (20U)                                      
#define ADC_CR2_JEXTEN_Msk        (0x3UL << ADC_CR2_JEXTEN_Pos)              
#define ADC_CR2_JEXTEN            ADC_CR2_JEXTEN_Msk                         
#define ADC_CR2_JEXTEN_0          (0x1UL << ADC_CR2_JEXTEN_Pos)              
#define ADC_CR2_JEXTEN_1          (0x2UL << ADC_CR2_JEXTEN_Pos)              
#define ADC_CR2_JSWSTART_Pos      (22U)                                      
#define ADC_CR2_JSWSTART_Msk      (0x1UL << ADC_CR2_JSWSTART_Pos)            
#define ADC_CR2_JSWSTART          ADC_CR2_JSWSTART_Msk                       
#define ADC_CR2_EXTSEL_Pos        (24U)                                      
#define ADC_CR2_EXTSEL_Msk        (0xFUL << ADC_CR2_EXTSEL_Pos)              
#define ADC_CR2_EXTSEL            ADC_CR2_EXTSEL_Msk                         
#define ADC_CR2_EXTSEL_0          (0x1UL << ADC_CR2_EXTSEL_Pos)              
#define ADC_CR2_EXTSEL_1          (0x2UL << ADC_CR2_EXTSEL_Pos)              
#define ADC_CR2_EXTSEL_2          (0x4UL << ADC_CR2_EXTSEL_Pos)              
#define ADC_CR2_EXTSEL_3          (0x8UL << ADC_CR2_EXTSEL_Pos)              
#define ADC_CR2_EXTEN_Pos         (28U)                                      
#define ADC_CR2_EXTEN_Msk         (0x3UL << ADC_CR2_EXTEN_Pos)               
#define ADC_CR2_EXTEN             ADC_CR2_EXTEN_Msk                          
#define ADC_CR2_EXTEN_0           (0x1UL << ADC_CR2_EXTEN_Pos)               
#define ADC_CR2_EXTEN_1           (0x2UL << ADC_CR2_EXTEN_Pos)               
#define ADC_CR2_SWSTART_Pos       (30U)                                      
#define ADC_CR2_SWSTART_Msk       (0x1UL << ADC_CR2_SWSTART_Pos)             
#define ADC_CR2_SWSTART           ADC_CR2_SWSTART_Msk                        

/******************  Bit definition for ADC_SMPR1 register  *******************/
#define ADC_SMPR1_SMP10_Pos       (0U)                                         
#define ADC_SMPR1_SMP10_Msk       (0x7UL << ADC_SMPR1_SMP10_Pos)             
#define ADC_SMPR1_SMP10           ADC_SMPR1_SMP10_Msk                        
#define ADC_SMPR1_SMP10_0         (0x1UL << ADC_SMPR1_SMP10_Pos)             
#define ADC_SMPR1_SMP10_1         (0x2UL << ADC_SMPR1_SMP10_Pos)             
#define ADC_SMPR1_SMP10_2         (0x4UL << ADC_SMPR1_SMP10_Pos)             
#define ADC_SMPR1_SMP11_Pos       (3U)                                       
#define ADC_SMPR1_SMP11_Msk       (0x7UL << ADC_SMPR1_SMP11_Pos)             
#define ADC_SMPR1_SMP11           ADC_SMPR1_SMP11_Msk                        
#define ADC_SMPR1_SMP11_0         (0x1UL << ADC_SMPR1_SMP11_Pos)             
#define ADC_SMPR1_SMP11_1         (0x2UL << ADC_SMPR1_SMP11_Pos)             
#define ADC_SMPR1_SMP11_2         (0x4UL << ADC_SMPR1_SMP11_Pos)             
#define ADC_SMPR1_SMP12_Pos       (6U)                                       
#define ADC_SMPR1_SMP12_Msk       (0x7UL << ADC_SMPR1_SMP12_Pos)             
#define ADC_SMPR1_SMP12           ADC_SMPR1_SMP12_Msk                        
#define ADC_SMPR1_SMP12_0         (0x1UL << ADC_SMPR1_SMP12_Pos)             
#define ADC_SMPR1_SMP12_1         (0x2UL << ADC_SMPR1_SMP12_Pos)             
#define ADC_SMPR1_SMP12_2         (0x4UL << ADC_SMPR1_SMP12_Pos)             
#define ADC_SMPR1_SMP13_Pos       (9U)                                       
#define ADC_SMPR1_SMP13_Msk       (0x7UL << ADC_SMPR1_SMP13_Pos)             
#define ADC_SMPR1_SMP13           ADC_SMPR1_SMP13_Msk                        
#define ADC_SMPR1_SMP13_0         (0x1UL << ADC_SMPR1_SMP13_Pos)             
#define ADC_SMPR1_SMP13_1         (0x2UL << ADC_SMPR1_SMP13_Pos)             
#define ADC_SMPR1_SMP13_2         (0x4UL << ADC_SMPR1_SMP13_Pos)             
#define ADC_SMPR1_SMP14_Pos       (12U)                                      
#define ADC_SMPR1_SMP14_Msk       (0x7UL << ADC_SMPR1_SMP14_Pos)             
#define ADC_SMPR1_SMP14           ADC_SMPR1_SMP14_Msk                        
#define ADC_SMPR1_SMP14_0         (0x1UL << ADC_SMPR1_SMP14_Pos)             
#define ADC_SMPR1_SMP14_1         (0x2UL << ADC_SMPR1_SMP14_Pos)             
#define ADC_SMPR1_SMP14_2         (0x4UL << ADC_SMPR1_SMP14_Pos)             
#define ADC_SMPR1_SMP15_Pos       (15U)                                      
#define ADC_SMPR1_SMP15_Msk       (0x7UL << ADC_SMPR1_SMP15_Pos)             
#define ADC_SMPR1_SMP15           ADC_SMPR1_SMP15_Msk                        
#define ADC_SMPR1_SMP15_0         (0x1UL << ADC_SMPR1_SMP15_Pos)             
#define ADC_SMPR1_SMP15_1         (0x2UL << ADC_SMPR1_SMP15_Pos)             
#define ADC_SMPR1_SMP15_2         (0x4UL << ADC_SMPR1_SMP15_Pos)             
#define ADC_SMPR1_SMP16_Pos       (18U)                                      
#define ADC_SMPR1_SMP16_Msk       (0x7UL << ADC_SMPR1_SMP16_Pos)             
#define ADC_SMPR1_SMP16           ADC_SMPR1_SMP16_Msk                        
#define ADC_SMPR1_SMP16_0         (0x1UL << ADC_SMPR1_SMP16_Pos)             
#define ADC_SMPR1_SMP16_1         (0x2UL << ADC_SMPR1_SMP16_Pos)             
#define ADC_SMPR1_SMP16_2         (0x4UL << ADC_SMPR1_SMP16_Pos)             
#define ADC_SMPR1_SMP17_Pos       (21U)                                      
#define ADC_SMPR1_SMP17_Msk       (0x7UL << ADC_SMPR1_SMP17_Pos)              
#define ADC_SMPR1_SMP17           ADC_SMPR1_SMP17_Msk                         
#define ADC_SMPR1_SMP17_0         (0x1UL << ADC_SMPR1_SMP17_Pos)              
#define ADC_SMPR1_SMP17_1         (0x2UL << ADC_SMPR1_SMP17_Pos)              
#define ADC_SMPR1_SMP17_2         (0x4UL << ADC_SMPR1_SMP17_Pos)              
#define ADC_SMPR1_SMP18_Pos       (24U)                                       
#define ADC_SMPR1_SMP18_Msk       (0x7UL << ADC_SMPR1_SMP18_Pos)              
#define ADC_SMPR1_SMP18           ADC_SMPR1_SMP18_Msk                         
#define ADC_SMPR1_SMP18_0         (0x1UL << ADC_SMPR1_SMP18_Pos)              
#define ADC_SMPR1_SMP18_1         (0x2UL << ADC_SMPR1_SMP18_Pos)              
#define ADC_SMPR1_SMP18_2         (0x4UL << ADC_SMPR1_SMP18_Pos)              

/******************  Bit definition for ADC_SMPR2 register  *******************/
#define ADC_SMPR2_SMP0_Pos        (0U)                                         
#define ADC_SMPR2_SMP0_Msk        (0x7UL << ADC_SMPR2_SMP0_Pos)             
#define ADC_SMPR2_SMP0            ADC_SMPR2_SMP0_Msk                        
#define ADC_SMPR2_SMP0_0          (0x1UL << ADC_SMPR2_SMP0_Pos)             
#define ADC_SMPR2_SMP0_1          (0x2UL << ADC_SMPR2_SMP0_Pos)             
#define ADC_SMPR2_SMP0_2          (0x4UL << ADC_SMPR2_SMP0_Pos)             
#define ADC_SMPR2_SMP1_Pos        (3U)                                      
#define ADC_SMPR2_SMP1_Msk        (0x7UL << ADC_SMPR2_SMP1_Pos)             
#define ADC_SMPR2_SMP1            ADC_SMPR2_SMP1_Msk                        
#define ADC_SMPR2_SMP1_0          (0x1UL << ADC_SMPR2_SMP1_Pos)             
#define ADC_SMPR2_SMP1_1          (0x2UL << ADC_SMPR2_SMP1_Pos)             
#define ADC_SMPR2_SMP1_2          (0x4UL << ADC_SMPR2_SMP1_Pos)             
#define ADC_SMPR2_SMP2_Pos        (6U)                                      
#define ADC_SMPR2_SMP2_Msk        (0x7UL << ADC_SMPR2_SMP2_Pos)             
#define ADC_SMPR2_SMP2            ADC_SMPR2_SMP2_Msk                        
#define ADC_SMPR2_SMP2_0          (0x1UL << ADC_SMPR2_SMP2_Pos)             
#define ADC_SMPR2_SMP2_1          (0x2UL << ADC_SMPR2_SMP2_Pos)             
#define ADC_SMPR2_SMP2_2          (0x4UL << ADC_SMPR2_SMP2_Pos)             
#define ADC_SMPR2_SMP3_Pos        (9U)                                      
#define ADC_SMPR2_SMP3_Msk        (0x7UL << ADC_SMPR2_SMP3_Pos)             
#define ADC_SMPR2_SMP3            ADC_SMPR2_SMP3_Msk                        
#define ADC_SMPR2_SMP3_0          (0x1UL << ADC_SMPR2_SMP3_Pos)             
#define ADC_SMPR2_SMP3_1          (0x2UL << ADC_SMPR2_SMP3_Pos)             
#define ADC_SMPR2_SMP3_2          (0x4UL << ADC_SMPR2_SMP3_Pos)             
#define ADC_SMPR2_SMP4_Pos        (12U)                                     
#define ADC_SMPR2_SMP4_Msk        (0x7UL << ADC_SMPR2_SMP4_Pos)             
#define ADC_SMPR2_SMP4            ADC_SMPR2_SMP4_Msk                        
#define ADC_SMPR2_SMP4_0          (0x1UL << ADC_SMPR2_SMP4_Pos)             
#define ADC_SMPR2_SMP4_1          (0x2UL << ADC_SMPR2_SMP4_Pos)             
#define ADC_SMPR2_SMP4_2          (0x4UL << ADC_SMPR2_SMP4_Pos)             
#define ADC_SMPR2_SMP5_Pos        (15U)                                     
#define ADC_SMPR2_SMP5_Msk        (0x7UL << ADC_SMPR2_SMP5_Pos)             
#define ADC_SMPR2_SMP5            ADC_SMPR2_SMP5_Msk                        
#define ADC_SMPR2_SMP5_0          (0x1UL << ADC_SMPR2_SMP5_Pos)             
#define ADC_SMPR2_SMP5_1          (0x2UL << ADC_SMPR2_SMP5_Pos)             
#define ADC_SMPR2_SMP5_2          (0x4UL << ADC_SMPR2_SMP5_Pos)             
#define ADC_SMPR2_SMP6_Pos        (18U)                                     
#define ADC_SMPR2_SMP6_Msk        (0x7UL << ADC_SMPR2_SMP6_Pos)             
#define ADC_SMPR2_SMP6            ADC_SMPR2_SMP6_Msk                        
#define ADC_SMPR2_SMP6_0          (0x1UL << ADC_SMPR2_SMP6_Pos)             
#define ADC_SMPR2_SMP6_1          (0x2UL << ADC_SMPR2_SMP6_Pos)             
#define ADC_SMPR2_SMP6_2          (0x4UL << ADC_SMPR2_SMP6_Pos)             
#define ADC_SMPR2_SMP7_Pos        (21U)                                     
#define ADC_SMPR2_SMP7_Msk        (0x7UL << ADC_SMPR2_SMP7_Pos)             
#define ADC_SMPR2_SMP7            ADC_SMPR2_SMP7_Msk                        
#define ADC_SMPR2_SMP7_0          (0x1UL << ADC_SMPR2_SMP7_Pos)             
#define ADC_SMPR2_SMP7_1          (0x2UL << ADC_SMPR2_SMP7_Pos)             
#define ADC_SMPR2_SMP7_2          (0x4UL << ADC_SMPR2_SMP7_Pos)             
#define ADC_SMPR2_SMP8_Pos        (24U)                                     
#define ADC_SMPR2_SMP8_Msk        (0x7UL << ADC_SMPR2_SMP8_Pos)             
#define ADC_SMPR2_SMP8            ADC_SMPR2_SMP8_Msk                        
#define ADC_SMPR2_SMP8_0          (0x1UL << ADC_SMPR2_SMP8_Pos)             
#define ADC_SMPR2_SMP8_1          (0x2UL << ADC_SMPR2_SMP8_Pos)             
#define ADC_SMPR2_SMP8_2          (0x4UL << ADC_SMPR2_SMP8_Pos)             
#define ADC_SMPR2_SMP9_Pos        (27U)                                     
#define ADC_SMPR2_SMP9_Msk        (0x7UL << ADC_SMPR2_SMP9_Pos)             
#define ADC_SMPR2_SMP9            ADC_SMPR2_SMP9_Msk                        
#define ADC_SMPR2_SMP9_0          (0x1UL << ADC_SMPR2_SMP9_Pos)             
#define ADC_SMPR2_SMP9_1          (0x2UL << ADC_SMPR2_SMP9_Pos)             
#define ADC_SMPR2_SMP9_2          (0x4UL << ADC_SMPR2_SMP9_Pos)             

/******************  Bit definition for ADC_JOFR1 register  *******************/
#define ADC_JOFR1_JOFFSET1_Pos    (0U)                                         
#define ADC_JOFR1_JOFFSET1_Msk    (0xFFFUL << ADC_JOFR1_JOFFSET1_Pos)          
#define ADC_JOFR1_JOFFSET1        ADC_JOFR1_JOFFSET1_Msk                       

/******************  Bit definition for ADC_JOFR2 register  *******************/
#define ADC_JOFR2_JOFFSET2_Pos    (0U)                                         
#define ADC_JOFR2_JOFFSET2_Msk    (0xFFFUL << ADC_JOFR2_JOFFSET2_Pos)           
#define ADC_JOFR2_JOFFSET2        ADC_JOFR2_JOFFSET2_Msk                       /

/******************  Bit definition for ADC_JOFR3 register  *******************/
#define ADC_JOFR3_JOFFSET3_Pos    (0U)                                         
#define ADC_JOFR3_JOFFSET3_Msk    (0xFFFUL << ADC_JOFR3_JOFFSET3_Pos)          
#define ADC_JOFR3_JOFFSET3        ADC_JOFR3_JOFFSET3_Msk                       

/******************  Bit definition for ADC_JOFR4 register  *******************/
#define ADC_JOFR4_JOFFSET4_Pos    (0U)                                         
#define ADC_JOFR4_JOFFSET4_Msk    (0xFFFUL << ADC_JOFR4_JOFFSET4_Pos)         
#define ADC_JOFR4_JOFFSET4        ADC_JOFR4_JOFFSET4_Msk                      

/*******************  Bit definition for ADC_HTR register  ********************/
#define ADC_HTR_HT_Pos            (0U)                                         
#define ADC_HTR_HT_Msk            (0xFFFUL << ADC_HTR_HT_Pos)                  
#define ADC_HTR_HT                ADC_HTR_HT_Msk                               

/*******************  Bit definition for ADC_LTR register  ********************/
#define ADC_LTR_LT_Pos            (0U)                                        
#define ADC_LTR_LT_Msk            (0xFFFUL << ADC_LTR_LT_Pos)                  
#define ADC_LTR_LT                ADC_LTR_LT_Msk                               

/*******************  Bit definition for ADC_SQR1 register  *******************/
#define ADC_SQR1_SQ13_Pos         (0U)                                         
#define ADC_SQR1_SQ13_Msk         (0x1FUL << ADC_SQR1_SQ13_Pos)                 
#define ADC_SQR1_SQ13             ADC_SQR1_SQ13_Msk                           
#define ADC_SQR1_SQ13_0           (0x01UL << ADC_SQR1_SQ13_Pos)               
#define ADC_SQR1_SQ13_1           (0x02UL << ADC_SQR1_SQ13_Pos)                 
#define ADC_SQR1_SQ13_2           (0x04UL << ADC_SQR1_SQ13_Pos)                 
#define ADC_SQR1_SQ13_3           (0x08UL << ADC_SQR1_SQ13_Pos)                 
#define ADC_SQR1_SQ13_4           (0x10UL << ADC_SQR1_SQ13_Pos)                 
#define ADC_SQR1_SQ14_Pos         (5U)                                      
#define ADC_SQR1_SQ14_Msk         (0x1FUL << ADC_SQR1_SQ14_Pos)             
#define ADC_SQR1_SQ14             ADC_SQR1_SQ14_Msk                         
#define ADC_SQR1_SQ14_0           (0x01UL << ADC_SQR1_SQ14_Pos)             
#define ADC_SQR1_SQ14_1           (0x02UL << ADC_SQR1_SQ14_Pos)             
#define ADC_SQR1_SQ14_2           (0x04UL << ADC_SQR1_SQ14_Pos)             
#define ADC_SQR1_SQ14_3           (0x08UL << ADC_SQR1_SQ14_Pos)             
#define ADC_SQR1_SQ14_4           (0x10UL << ADC_SQR1_SQ14_Pos)             
#define ADC_SQR1_SQ15_Pos         (10U)                                     
#define ADC_SQR1_SQ15_Msk         (0x1FUL << ADC_SQR1_SQ15_Pos)             
#define ADC_SQR1_SQ15             ADC_SQR1_SQ15_Msk                         
#define ADC_SQR1_SQ15_0           (0x01UL << ADC_SQR1_SQ15_Pos)             
#define ADC_SQR1_SQ15_1           (0x02UL << ADC_SQR1_SQ15_Pos)             
#define ADC_SQR1_SQ15_2           (0x04UL << ADC_SQR1_SQ15_Pos)             
#define ADC_SQR1_SQ15_3           (0x08UL << ADC_SQR1_SQ15_Pos)             
#define ADC_SQR1_SQ15_4           (0x10UL << ADC_SQR1_SQ15_Pos)             
#define ADC_SQR1_SQ16_Pos         (15U)                                     
#define ADC_SQR1_SQ16_Msk         (0x1FUL << ADC_SQR1_SQ16_Pos)             
#define ADC_SQR1_SQ16             ADC_SQR1_SQ16_Msk                         
#define ADC_SQR1_SQ16_0           (0x01UL << ADC_SQR1_SQ16_Pos)             
#define ADC_SQR1_SQ16_1           (0x02UL << ADC_SQR1_SQ16_Pos)             
#define ADC_SQR1_SQ16_2           (0x04UL << ADC_SQR1_SQ16_Pos)             
#define ADC_SQR1_SQ16_3           (0x08UL << ADC_SQR1_SQ16_Pos)             
#define ADC_SQR1_SQ16_4           (0x10UL << ADC_SQR1_SQ16_Pos)             
#define ADC_SQR1_L_Pos            (20U)                                     
#define ADC_SQR1_L_Msk            (0xFUL << ADC_SQR1_L_Pos)                 
#define ADC_SQR1_L                ADC_SQR1_L_Msk                            
#define ADC_SQR1_L_0              (0x1UL << ADC_SQR1_L_Pos)                 
#define ADC_SQR1_L_1              (0x2UL << ADC_SQR1_L_Pos)                 
#define ADC_SQR1_L_2              (0x4UL << ADC_SQR1_L_Pos)                 
#define ADC_SQR1_L_3              (0x8UL << ADC_SQR1_L_Pos)                 

/*******************  Bit definition for ADC_SQR2 register  *******************/
#define ADC_SQR2_SQ7_Pos          (0U)                                         
#define ADC_SQR2_SQ7_Msk          (0x1FUL << ADC_SQR2_SQ7_Pos)                  
#define ADC_SQR2_SQ7              ADC_SQR2_SQ7_Msk                          
#define ADC_SQR2_SQ7_0            (0x01UL << ADC_SQR2_SQ7_Pos)              
#define ADC_SQR2_SQ7_1            (0x02UL << ADC_SQR2_SQ7_Pos)              
#define ADC_SQR2_SQ7_2            (0x04UL << ADC_SQR2_SQ7_Pos)              
#define ADC_SQR2_SQ7_3            (0x08UL << ADC_SQR2_SQ7_Pos)              
#define ADC_SQR2_SQ7_4            (0x10UL << ADC_SQR2_SQ7_Pos)              
#define ADC_SQR2_SQ8_Pos          (5U)                                      
#define ADC_SQR2_SQ8_Msk          (0x1FUL << ADC_SQR2_SQ8_Pos)              
#define ADC_SQR2_SQ8              ADC_SQR2_SQ8_Msk                          
#define ADC_SQR2_SQ8_0            (0x01UL << ADC_SQR2_SQ8_Pos)              
#define ADC_SQR2_SQ8_1            (0x02UL << ADC_SQR2_SQ8_Pos)              
#define ADC_SQR2_SQ8_2            (0x04UL << ADC_SQR2_SQ8_Pos)              
#define ADC_SQR2_SQ8_3            (0x08UL << ADC_SQR2_SQ8_Pos)              
#define ADC_SQR2_SQ8_4            (0x10UL << ADC_SQR2_SQ8_Pos)              
#define ADC_SQR2_SQ9_Pos          (10U)                                     
#define ADC_SQR2_SQ9_Msk          (0x1FUL << ADC_SQR2_SQ9_Pos)              
#define ADC_SQR2_SQ9              ADC_SQR2_SQ9_Msk                          
#define ADC_SQR2_SQ9_0            (0x01UL << ADC_SQR2_SQ9_Pos)              
#define ADC_SQR2_SQ9_1            (0x02UL << ADC_SQR2_SQ9_Pos)              
#define ADC_SQR2_SQ9_2            (0x04UL << ADC_SQR2_SQ9_Pos)              
#define ADC_SQR2_SQ9_3            (0x08UL << ADC_SQR2_SQ9_Pos)              
#define ADC_SQR2_SQ9_4            (0x10UL << ADC_SQR2_SQ9_Pos)              
#define ADC_SQR2_SQ10_Pos         (15U)                                     
#define ADC_SQR2_SQ10_Msk         (0x1FUL << ADC_SQR2_SQ10_Pos)             
#define ADC_SQR2_SQ10             ADC_SQR2_SQ10_Msk                         
#define ADC_SQR2_SQ10_0           (0x01UL << ADC_SQR2_SQ10_Pos)             
#define ADC_SQR2_SQ10_1           (0x02UL << ADC_SQR2_SQ10_Pos)             
#define ADC_SQR2_SQ10_2           (0x04UL << ADC_SQR2_SQ10_Pos)             
#define ADC_SQR2_SQ10_3           (0x08UL << ADC_SQR2_SQ10_Pos)             
#define ADC_SQR2_SQ10_4           (0x10UL << ADC_SQR2_SQ10_Pos)             
#define ADC_SQR2_SQ11_Pos         (20U)                                     
#define ADC_SQR2_SQ11_Msk         (0x1FUL << ADC_SQR2_SQ11_Pos)             
#define ADC_SQR2_SQ11             ADC_SQR2_SQ11_Msk                         
#define ADC_SQR2_SQ11_0           (0x01UL << ADC_SQR2_SQ11_Pos)             
#define ADC_SQR2_SQ11_1           (0x02UL << ADC_SQR2_SQ11_Pos)             
#define ADC_SQR2_SQ11_2           (0x04UL << ADC_SQR2_SQ11_Pos)              
#define ADC_SQR2_SQ11_3           (0x08UL << ADC_SQR2_SQ11_Pos)              
#define ADC_SQR2_SQ11_4           (0x10UL << ADC_SQR2_SQ11_Pos)              
#define ADC_SQR2_SQ12_Pos         (25U)                                      
#define ADC_SQR2_SQ12_Msk         (0x1FUL << ADC_SQR2_SQ12_Pos)              
#define ADC_SQR2_SQ12             ADC_SQR2_SQ12_Msk                          
#define ADC_SQR2_SQ12_0           (0x01UL << ADC_SQR2_SQ12_Pos)              
#define ADC_SQR2_SQ12_1           (0x02UL << ADC_SQR2_SQ12_Pos)              
#define ADC_SQR2_SQ12_2           (0x04UL << ADC_SQR2_SQ12_Pos)              
#define ADC_SQR2_SQ12_3           (0x08UL << ADC_SQR2_SQ12_Pos)              
#define ADC_SQR2_SQ12_4           (0x10UL << ADC_SQR2_SQ12_Pos)              

/*******************  Bit definition for ADC_SQR3 register  *******************/
#define ADC_SQR3_SQ1_Pos          (0U)                                         
#define ADC_SQR3_SQ1_Msk          (0x1FUL << ADC_SQR3_SQ1_Pos)            
#define ADC_SQR3_SQ1              ADC_SQR3_SQ1_Msk                        
#define ADC_SQR3_SQ1_0            (0x01UL << ADC_SQR3_SQ1_Pos)            
#define ADC_SQR3_SQ1_1            (0x02UL << ADC_SQR3_SQ1_Pos)            
#define ADC_SQR3_SQ1_2            (0x04UL << ADC_SQR3_SQ1_Pos)            
#define ADC_SQR3_SQ1_3            (0x08UL << ADC_SQR3_SQ1_Pos)            
#define ADC_SQR3_SQ1_4            (0x10UL << ADC_SQR3_SQ1_Pos)            
#define ADC_SQR3_SQ2_Pos          (5U)                                    
#define ADC_SQR3_SQ2_Msk          (0x1FUL << ADC_SQR3_SQ2_Pos)            
#define ADC_SQR3_SQ2              ADC_SQR3_SQ2_Msk                        
#define ADC_SQR3_SQ2_0            (0x01UL << ADC_SQR3_SQ2_Pos)            
#define ADC_SQR3_SQ2_1            (0x02UL << ADC_SQR3_SQ2_Pos)            
#define ADC_SQR3_SQ2_2            (0x04UL << ADC_SQR3_SQ2_Pos)            
#define ADC_SQR3_SQ2_3            (0x08UL << ADC_SQR3_SQ2_Pos)            
#define ADC_SQR3_SQ2_4            (0x10UL << ADC_SQR3_SQ2_Pos)            
#define ADC_SQR3_SQ3_Pos          (10U)                                   
#define ADC_SQR3_SQ3_Msk          (0x1FUL << ADC_SQR3_SQ3_Pos)            
#define ADC_SQR3_SQ3              ADC_SQR3_SQ3_Msk                        
#define ADC_SQR3_SQ3_0            (0x01UL << ADC_SQR3_SQ3_Pos)            
#define ADC_SQR3_SQ3_1            (0x02UL << ADC_SQR3_SQ3_Pos)            
#define ADC_SQR3_SQ3_2            (0x04UL << ADC_SQR3_SQ3_Pos)            
#define ADC_SQR3_SQ3_3            (0x08UL << ADC_SQR3_SQ3_Pos)            
#define ADC_SQR3_SQ3_4            (0x10UL << ADC_SQR3_SQ3_Pos)            
#define ADC_SQR3_SQ4_Pos          (15U)                                   
#define ADC_SQR3_SQ4_Msk          (0x1FUL << ADC_SQR3_SQ4_Pos)            
#define ADC_SQR3_SQ4              ADC_SQR3_SQ4_Msk                        
#define ADC_SQR3_SQ4_0            (0x01UL << ADC_SQR3_SQ4_Pos)           
#define ADC_SQR3_SQ4_1            (0x02UL << ADC_SQR3_SQ4_Pos)           
#define ADC_SQR3_SQ4_2            (0x04UL << ADC_SQR3_SQ4_Pos)           
#define ADC_SQR3_SQ4_3            (0x08UL << ADC_SQR3_SQ4_Pos)           
#define ADC_SQR3_SQ4_4            (0x10UL << ADC_SQR3_SQ4_Pos)            
#define ADC_SQR3_SQ5_Pos          (20U)                                   
#define ADC_SQR3_SQ5_Msk          (0x1FUL << ADC_SQR3_SQ5_Pos)            
#define ADC_SQR3_SQ5              ADC_SQR3_SQ5_Msk                        
#define ADC_SQR3_SQ5_0            (0x01UL << ADC_SQR3_SQ5_Pos)            
#define ADC_SQR3_SQ5_1            (0x02UL << ADC_SQR3_SQ5_Pos)            
#define ADC_SQR3_SQ5_2            (0x04UL << ADC_SQR3_SQ5_Pos)            
#define ADC_SQR3_SQ5_3            (0x08UL << ADC_SQR3_SQ5_Pos)            
#define ADC_SQR3_SQ5_4            (0x10UL << ADC_SQR3_SQ5_Pos)            
#define ADC_SQR3_SQ6_Pos          (25U)                                   
#define ADC_SQR3_SQ6_Msk          (0x1FUL << ADC_SQR3_SQ6_Pos)            
#define ADC_SQR3_SQ6              ADC_SQR3_SQ6_Msk                        
#define ADC_SQR3_SQ6_0            (0x01UL << ADC_SQR3_SQ6_Pos)            
#define ADC_SQR3_SQ6_1            (0x02UL << ADC_SQR3_SQ6_Pos)            
#define ADC_SQR3_SQ6_2            (0x04UL << ADC_SQR3_SQ6_Pos)            
#define ADC_SQR3_SQ6_3            (0x08UL << ADC_SQR3_SQ6_Pos)            
#define ADC_SQR3_SQ6_4            (0x10UL << ADC_SQR3_SQ6_Pos)            

/*******************  Bit definition for ADC_JSQR register  *******************/
#define ADC_JSQR_JSQ1_Pos         (0U)                                         
#define ADC_JSQR_JSQ1_Msk         (0x1FUL << ADC_JSQR_JSQ1_Pos)           
#define ADC_JSQR_JSQ1             ADC_JSQR_JSQ1_Msk                       
#define ADC_JSQR_JSQ1_0           (0x01UL << ADC_JSQR_JSQ1_Pos)           
#define ADC_JSQR_JSQ1_1           (0x02UL << ADC_JSQR_JSQ1_Pos)           
#define ADC_JSQR_JSQ1_2           (0x04UL << ADC_JSQR_JSQ1_Pos)           
#define ADC_JSQR_JSQ1_3           (0x08UL << ADC_JSQR_JSQ1_Pos)           
#define ADC_JSQR_JSQ1_4           (0x10UL << ADC_JSQR_JSQ1_Pos)           
#define ADC_JSQR_JSQ2_Pos         (5U)                                    
#define ADC_JSQR_JSQ2_Msk         (0x1FUL << ADC_JSQR_JSQ2_Pos)           
#define ADC_JSQR_JSQ2             ADC_JSQR_JSQ2_Msk                       
#define ADC_JSQR_JSQ2_0           (0x01UL << ADC_JSQR_JSQ2_Pos)           
#define ADC_JSQR_JSQ2_1           (0x02UL << ADC_JSQR_JSQ2_Pos)           
#define ADC_JSQR_JSQ2_2           (0x04UL << ADC_JSQR_JSQ2_Pos)           
#define ADC_JSQR_JSQ2_3           (0x08UL << ADC_JSQR_JSQ2_Pos)           
#define ADC_JSQR_JSQ2_4           (0x10UL << ADC_JSQR_JSQ2_Pos)           
#define ADC_JSQR_JSQ3_Pos         (10U)                                   
#define ADC_JSQR_JSQ3_Msk         (0x1FUL << ADC_JSQR_JSQ3_Pos)           
#define ADC_JSQR_JSQ3             ADC_JSQR_JSQ3_Msk                       
#define ADC_JSQR_JSQ3_0           (0x01UL << ADC_JSQR_JSQ3_Pos)           
#define ADC_JSQR_JSQ3_1           (0x02UL << ADC_JSQR_JSQ3_Pos)           
#define ADC_JSQR_JSQ3_2           (0x04UL << ADC_JSQR_JSQ3_Pos)           
#define ADC_JSQR_JSQ3_3           (0x08UL << ADC_JSQR_JSQ3_Pos)           
#define ADC_JSQR_JSQ3_4           (0x10UL << ADC_JSQR_JSQ3_Pos)           
#define ADC_JSQR_JSQ4_Pos         (15U)                                   
#define ADC_JSQR_JSQ4_Msk         (0x1FUL << ADC_JSQR_JSQ4_Pos)           
#define ADC_JSQR_JSQ4             ADC_JSQR_JSQ4_Msk                       
#define ADC_JSQR_JSQ4_0           (0x01UL << ADC_JSQR_JSQ4_Pos)           
#define ADC_JSQR_JSQ4_1           (0x02UL << ADC_JSQR_JSQ4_Pos)           
#define ADC_JSQR_JSQ4_2           (0x04UL << ADC_JSQR_JSQ4_Pos)           
#define ADC_JSQR_JSQ4_3           (0x08UL << ADC_JSQR_JSQ4_Pos)           
#define ADC_JSQR_JSQ4_4           (0x10UL << ADC_JSQR_JSQ4_Pos)           
#define ADC_JSQR_JL_Pos           (20U)                                   
#define ADC_JSQR_JL_Msk           (0x3UL << ADC_JSQR_JL_Pos)              
#define ADC_JSQR_JL               ADC_JSQR_JL_Msk                         
#define ADC_JSQR_JL_0             (0x1UL << ADC_JSQR_JL_Pos)              
#define ADC_JSQR_JL_1             (0x2UL << ADC_JSQR_JL_Pos)              

/*******************  Bit definition for ADC_JDR1 register  *******************/
#define ADC_JDR1_JDATA_Pos        (0U)                                        
#define ADC_JDR1_JDATA_Msk        (0xFFFFUL << ADC_JDR1_JDATA_Pos)            
#define ADC_JDR1_JDATA            ADC_JDR1_JDATA_Msk                          

/*******************  Bit definition for ADC_JDR2 register  *******************/
#define ADC_JDR2_JDATA_Pos        (0U)                                      
#define ADC_JDR2_JDATA_Msk        (0xFFFFUL << ADC_JDR2_JDATA_Pos)          
#define ADC_JDR2_JDATA            ADC_JDR2_JDATA_Msk                        

/*******************  Bit definition for ADC_JDR3 register  *******************/
#define ADC_JDR3_JDATA_Pos        (0U)                                        
#define ADC_JDR3_JDATA_Msk        (0xFFFFUL << ADC_JDR3_JDATA_Pos)            
#define ADC_JDR3_JDATA            ADC_JDR3_JDATA_Msk                          

/*******************  Bit definition for ADC_JDR4 register  *******************/
#define ADC_JDR4_JDATA_Pos        (0U)                                       
#define ADC_JDR4_JDATA_Msk        (0xFFFFUL << ADC_JDR4_JDATA_Pos)           
#define ADC_JDR4_JDATA            ADC_JDR4_JDATA_Msk                         

/********************  Bit definition for ADC_DR register  ********************/
#define ADC_DR_DATA_Pos           (0U)                                     
#define ADC_DR_DATA_Msk           (0xFFFFUL << ADC_DR_DATA_Pos)            
#define ADC_DR_DATA               ADC_DR_DATA_Msk                          
#define ADC_DR_ADC2DATA_Pos       (16U)                                    
#define ADC_DR_ADC2DATA_Msk       (0xFFFFUL << ADC_DR_ADC2DATA_Pos)        
#define ADC_DR_ADC2DATA           ADC_DR_ADC2DATA_Msk                      

/*******************  Bit definition for ADC_CSR register  ********************/
#define ADC_CSR_AWD1_Pos          (0U)                                         
#define ADC_CSR_AWD1_Msk          (0x1UL << ADC_CSR_AWD1_Pos)             
#define ADC_CSR_AWD1              ADC_CSR_AWD1_Msk                        
#define ADC_CSR_EOC1_Pos          (1U)                                    
#define ADC_CSR_EOC1_Msk          (0x1UL << ADC_CSR_EOC1_Pos)             
#define ADC_CSR_EOC1              ADC_CSR_EOC1_Msk                        
#define ADC_CSR_JEOC1_Pos         (2U)                                    
#define ADC_CSR_JEOC1_Msk         (0x1UL << ADC_CSR_JEOC1_Pos)            
#define ADC_CSR_JEOC1             ADC_CSR_JEOC1_Msk                       
#define ADC_CSR_JSTRT1_Pos        (3U)                                    
#define ADC_CSR_JSTRT1_Msk        (0x1UL << ADC_CSR_JSTRT1_Pos)           
#define ADC_CSR_JSTRT1            ADC_CSR_JSTRT1_Msk                      
#define ADC_CSR_STRT1_Pos         (4U)                                    
#define ADC_CSR_STRT1_Msk         (0x1UL << ADC_CSR_STRT1_Pos)            
#define ADC_CSR_STRT1             ADC_CSR_STRT1_Msk                       
#define ADC_CSR_OVR1_Pos          (5U)                                    
#define ADC_CSR_OVR1_Msk          (0x1UL << ADC_CSR_OVR1_Pos)             
#define ADC_CSR_OVR1              ADC_CSR_OVR1_Msk                        
#define ADC_CSR_AWD2_Pos          (8U)                                    
#define ADC_CSR_AWD2_Msk          (0x1UL << ADC_CSR_AWD2_Pos)             
#define ADC_CSR_AWD2              ADC_CSR_AWD2_Msk                        
#define ADC_CSR_EOC2_Pos          (9U)                                    
#define ADC_CSR_EOC2_Msk          (0x1UL << ADC_CSR_EOC2_Pos)             
#define ADC_CSR_EOC2              ADC_CSR_EOC2_Msk                        
#define ADC_CSR_JEOC2_Pos         (10U)                                   
#define ADC_CSR_JEOC2_Msk         (0x1UL << ADC_CSR_JEOC2_Pos)            
#define ADC_CSR_JEOC2             ADC_CSR_JEOC2_Msk                       
#define ADC_CSR_JSTRT2_Pos        (11U)                                   
#define ADC_CSR_JSTRT2_Msk        (0x1UL << ADC_CSR_JSTRT2_Pos)           
#define ADC_CSR_JSTRT2            ADC_CSR_JSTRT2_Msk                      
#define ADC_CSR_STRT2_Pos         (12U)                                   
#define ADC_CSR_STRT2_Msk         (0x1UL << ADC_CSR_STRT2_Pos)            
#define ADC_CSR_STRT2             ADC_CSR_STRT2_Msk                       
#define ADC_CSR_OVR2_Pos          (13U)                                   
#define ADC_CSR_OVR2_Msk          (0x1UL << ADC_CSR_OVR2_Pos)             
#define ADC_CSR_OVR2              ADC_CSR_OVR2_Msk                        
#define ADC_CSR_AWD3_Pos          (16U)                                   
#define ADC_CSR_AWD3_Msk          (0x1UL << ADC_CSR_AWD3_Pos)            
#define ADC_CSR_AWD3              ADC_CSR_AWD3_Msk                       
#define ADC_CSR_EOC3_Pos          (17U)                                  
#define ADC_CSR_EOC3_Msk          (0x1UL << ADC_CSR_EOC3_Pos)            
#define ADC_CSR_EOC3              ADC_CSR_EOC3_Msk                        
#define ADC_CSR_JEOC3_Pos         (18U)                                   
#define ADC_CSR_JEOC3_Msk         (0x1UL << ADC_CSR_JEOC3_Pos)            
#define ADC_CSR_JEOC3             ADC_CSR_JEOC3_Msk                       
#define ADC_CSR_JSTRT3_Pos        (19U)                                   
#define ADC_CSR_JSTRT3_Msk        (0x1UL << ADC_CSR_JSTRT3_Pos)           
#define ADC_CSR_JSTRT3            ADC_CSR_JSTRT3_Msk                      
#define ADC_CSR_STRT3_Pos         (20U)                                   
#define ADC_CSR_STRT3_Msk         (0x1UL << ADC_CSR_STRT3_Pos)            
#define ADC_CSR_STRT3             ADC_CSR_STRT3_Msk                       
#define ADC_CSR_OVR3_Pos          (21U)                                   
#define ADC_CSR_OVR3_Msk          (0x1UL << ADC_CSR_OVR3_Pos)             
#define ADC_CSR_OVR3              ADC_CSR_OVR3_Msk                        

/* Legacy defines */
#define  ADC_CSR_DOVR1                        ADC_CSR_OVR1
#define  ADC_CSR_DOVR2                        ADC_CSR_OVR2
#define  ADC_CSR_DOVR3                        ADC_CSR_OVR3

/*******************  Bit definition for ADC_CCR register  ********************/
#define ADC_CCR_MULTI_Pos         (0U)                                         
#define ADC_CCR_MULTI_Msk         (0x1FUL << ADC_CCR_MULTI_Pos)             
#define ADC_CCR_MULTI             ADC_CCR_MULTI_Msk                         
#define ADC_CCR_MULTI_0           (0x01UL << ADC_CCR_MULTI_Pos)             
#define ADC_CCR_MULTI_1           (0x02UL << ADC_CCR_MULTI_Pos)             
#define ADC_CCR_MULTI_2           (0x04UL << ADC_CCR_MULTI_Pos)             
#define ADC_CCR_MULTI_3           (0x08UL << ADC_CCR_MULTI_Pos)             
#define ADC_CCR_MULTI_4           (0x10UL << ADC_CCR_MULTI_Pos)             
#define ADC_CCR_DELAY_Pos         (8U)                                      
#define ADC_CCR_DELAY_Msk         (0xFUL << ADC_CCR_DELAY_Pos)              
#define ADC_CCR_DELAY             ADC_CCR_DELAY_Msk                         
#define ADC_CCR_DELAY_0           (0x1UL << ADC_CCR_DELAY_Pos)              
#define ADC_CCR_DELAY_1           (0x2UL << ADC_CCR_DELAY_Pos)              
#define ADC_CCR_DELAY_2           (0x4UL << ADC_CCR_DELAY_Pos)              
#define ADC_CCR_DELAY_3           (0x8UL << ADC_CCR_DELAY_Pos)              
#define ADC_CCR_DDS_Pos           (13U)                                     
#define ADC_CCR_DDS_Msk           (0x1UL << ADC_CCR_DDS_Pos)                
#define ADC_CCR_DDS               ADC_CCR_DDS_Msk                           
#define ADC_CCR_DMA_Pos           (14U)                                     
#define ADC_CCR_DMA_Msk           (0x3UL << ADC_CCR_DMA_Pos)                
#define ADC_CCR_DMA               ADC_CCR_DMA_Msk                           
#define ADC_CCR_DMA_0             (0x1UL << ADC_CCR_DMA_Pos)                
#define ADC_CCR_DMA_1             (0x2UL << ADC_CCR_DMA_Pos)                
#define ADC_CCR_ADCPRE_Pos        (16U)                                     
#define ADC_CCR_ADCPRE_Msk        (0x3UL << ADC_CCR_ADCPRE_Pos)             
#define ADC_CCR_ADCPRE            ADC_CCR_ADCPRE_Msk                        
#define ADC_CCR_ADCPRE_0          (0x1UL << ADC_CCR_ADCPRE_Pos)             
#define ADC_CCR_ADCPRE_1          (0x2UL << ADC_CCR_ADCPRE_Pos)             
#define ADC_CCR_VBATE_Pos         (22U)                                     
#define ADC_CCR_VBATE_Msk         (0x1UL << ADC_CCR_VBATE_Pos)              
#define ADC_CCR_VBATE             ADC_CCR_VBATE_Msk                         
#define ADC_CCR_TSVREFE_Pos       (23U)                                     
#define ADC_CCR_TSVREFE_Msk       (0x1UL << ADC_CCR_TSVREFE_Pos)            
#define ADC_CCR_TSVREFE           ADC_CCR_TSVREFE_Msk                       

/*******************  Bit definition for ADC_CDR register  ********************/
#define ADC_CDR_DATA1_Pos         (0U)                                        
#define ADC_CDR_DATA1_Msk         (0xFFFFUL << ADC_CDR_DATA1_Pos)              
#define ADC_CDR_DATA1             ADC_CDR_DATA1_Msk                            
#define ADC_CDR_DATA2_Pos         (16U)                                       
#define ADC_CDR_DATA2_Msk         (0xFFFFUL << ADC_CDR_DATA2_Pos)              
#define ADC_CDR_DATA2             ADC_CDR_DATA2_Msk                            

/* Legacy defines */
#define ADC_CDR_RDATA_MST         ADC_CDR_DATA1
#define ADC_CDR_RDATA_SLV         ADC_CDR_DATA2

#endif  /* HEADER_ADC_H_ */
