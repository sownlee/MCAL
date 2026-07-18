#if !defined(HEADER_MCU_H_)  
#define HEADER_MCU_H_

#include "Header.h"

/*Define register for RCC module*/
typedef struct
{
	__IO uint32_t CR;		      /* RCC clock control register,                                   */
	__IO uint32_t PLLCFGR;	      /* RCC PLL configuration register,                               */
	__IO uint32_t CFGR;		      /* RCC clock configuration register,                             */
	__IO uint32_t CIR;		      /* RCC clock interrupt register,                                 */
	__IO uint32_t AHB1RSTR;	      /* RCC AHB1 peripheral reset register,                           */
	__IO uint32_t AHB2RSTR;	      /* RCC AHB2 peripheral reset register,                           */
	__IO uint32_t AHB3RSTR;	      /* RCC AHB3 peripheral reset register,                           */
	uint32_t RESERVED0;		      /* Reserved, 0x1C                                                */
	__IO uint32_t APB1RSTR;	      /* RCC APB1 peripheral reset register,                           */
	__IO uint32_t APB2RSTR;	      /* RCC APB2 peripheral reset register,                           */
	uint32_t RESERVED1[2];	      /* Reserved, 0x28-0x2C                                           */
	__IO uint32_t AHB1ENR;	      /* RCC AHB1 peripheral clock register,                           */
	__IO uint32_t AHB2ENR;	      /* RCC AHB2 peripheral clock register,                           */
	__IO uint32_t AHB3ENR;	      /* RCC AHB3 peripheral clock register,                           */
	uint32_t RESERVED2;		      /* Reserved, 0x3C                                                */
	__IO uint32_t APB1ENR;	      /* RCC APB1 peripheral clock enable register,                    */
	__IO uint32_t APB2ENR;	      /* RCC APB2 peripheral clock enable register,                    */
	uint32_t RESERVED3[2];	      /* Reserved, 0x48-0x4C                                           */
	__IO uint32_t AHB1LPENR;      /* RCC AHB1 peripheral clock enable in low power mode register   */
	__IO uint32_t AHB2LPENR;      /* RCC AHB2 peripheral clock enable in low power mode register   */
	__IO uint32_t AHB3LPENR;      /* RCC AHB3 peripheral clock enable in low power mode register   */
	uint32_t RESERVED4;		      /* Reserved, 0x5C                                                */
	__IO uint32_t APB1LPENR;      /* RCC APB1 peripheral clock enable in low power mode register   */
	__IO uint32_t APB2LPENR;      /* RCC APB2 peripheral clock enable in low power mode register   */
	uint32_t RESERVED5[2];	      /* Reserved, 0x68-0x6C                                           */
	__IO uint32_t BDCR;		      /* RCC Backup domain control register,                           */
	__IO uint32_t CSR;		      /* RCC clock control & status register,                          */
	uint32_t RESERVED6[2];	      /* Reserved, 0x78-0x7C                                           */
	__IO uint32_t SSCGR;	      /* RCC spread spectrum clock generation register,                */
	__IO uint32_t PLLI2SCFGR;     /* RCC PLLI2S configuration register,                            */
} RCC_RegDef_t;
#define RCC ((RCC_RegDef_t *)RCC_BASEADDR)

/** 
  *  Power Control
*/
typedef struct
{
  __IO uint32_t CR;   /* PWR power control register        */
  __IO uint32_t CSR;  /* PWR power control/status register */
} PWR_TypeDef_t;
#define PWR                 ((PWR_TypeDef_t *) PWR_BASEADDR)

#define RCC_MAX_FREQUENCY           168000000U         /* Max frequency of family in Hz*/
#define RCC_MAX_FREQUENCY_SCALE1    RCC_MAX_FREQUENCY  /* Maximum frequency for system clock at power scale1, in Hz */
#define RCC_MAX_FREQUENCY_SCALE2    144000000U         /* Maximum frequency for system clock at power scale2, in Hz */
#define RCC_PLLVCO_OUTPUT_MIN       100000000U         /* Frequency min for PLLVCO output, in Hz */
#define RCC_PLLVCO_INPUT_MIN           950000U         /* Frequency min for PLLVCO input, in Hz  */
#define RCC_PLLVCO_INPUT_MAX          2100000U         /* Frequency max for PLLVCO input, in Hz  */
#define RCC_PLLVCO_OUTPUT_MAX       432000000U         /* Frequency max for PLLVCO output, in Hz */

/*  Bit definition PWR_CR */
#define PWR_CR_LPDS_Pos        (0U)                                            
#define PWR_CR_LPDS_Msk        (0x1UL << PWR_CR_LPDS_Pos)                     
#define PWR_CR_LPDS            PWR_CR_LPDS_Msk                                
#define PWR_CR_PDDS_Pos        (1U)                                           
#define PWR_CR_PDDS_Msk        (0x1UL << PWR_CR_PDDS_Pos)                     
#define PWR_CR_PDDS            PWR_CR_PDDS_Msk                                
#define PWR_CR_CWUF_Pos        (2U)                                           
#define PWR_CR_CWUF_Msk        (0x1UL << PWR_CR_CWUF_Pos)                     
#define PWR_CR_CWUF            PWR_CR_CWUF_Msk                                
#define PWR_CR_CSBF_Pos        (3U)                                           
#define PWR_CR_CSBF_Msk        (0x1UL << PWR_CR_CSBF_Pos)                     
#define PWR_CR_CSBF            PWR_CR_CSBF_Msk                                
#define PWR_CR_PVDE_Pos        (4U)                                           
#define PWR_CR_PVDE_Msk        (0x1UL << PWR_CR_PVDE_Pos)                     
#define PWR_CR_PVDE            PWR_CR_PVDE_Msk                                

#define PWR_CR_PLS_Pos         (5U)                                           
#define PWR_CR_PLS_Msk         (0x7UL << PWR_CR_PLS_Pos)                      
#define PWR_CR_PLS             PWR_CR_PLS_Msk                                 
#define PWR_CR_PLS_0           (0x1UL << PWR_CR_PLS_Pos)                      
#define PWR_CR_PLS_1           (0x2UL << PWR_CR_PLS_Pos)                      
#define PWR_CR_PLS_2           (0x4UL << PWR_CR_PLS_Pos)                      

/* PVD level configuration */
#define PWR_CR_PLS_LEV0        0x00000000U                                    
#define PWR_CR_PLS_LEV1        0x00000020U                                  
#define PWR_CR_PLS_LEV2        0x00000040U                                  
#define PWR_CR_PLS_LEV3        0x00000060U                                  
#define PWR_CR_PLS_LEV4        0x00000080U                                  
#define PWR_CR_PLS_LEV5        0x000000A0U                                  
#define PWR_CR_PLS_LEV6        0x000000C0U                                  
#define PWR_CR_PLS_LEV7        0x000000E0U                                  
#define PWR_CR_DBP_Pos         (8U)                                         
#define PWR_CR_DBP_Msk         (0x1UL << PWR_CR_DBP_Pos)                    
#define PWR_CR_DBP             PWR_CR_DBP_Msk                               
#define PWR_CR_FPDS_Pos        (9U)                                         
#define PWR_CR_FPDS_Msk        (0x1UL << PWR_CR_FPDS_Pos)                   
#define PWR_CR_FPDS            PWR_CR_FPDS_Msk                              
#define PWR_CR_VOS_Pos         (14U)                                        
#define PWR_CR_VOS_Msk         (0x1UL << PWR_CR_VOS_Pos)                    
#define PWR_CR_VOS             PWR_CR_VOS_Msk                               

/*******************  Bit definition for PWR_CSR register  ********************/
#define PWR_CSR_WUF_Pos        (0U)                                            
#define PWR_CSR_WUF_Msk        (0x1UL << PWR_CSR_WUF_Pos)                   
#define PWR_CSR_WUF            PWR_CSR_WUF_Msk                              
#define PWR_CSR_SBF_Pos        (1U)                                         
#define PWR_CSR_SBF_Msk        (0x1UL << PWR_CSR_SBF_Pos)                   
#define PWR_CSR_SBF            PWR_CSR_SBF_Msk                              
#define PWR_CSR_PVDO_Pos       (2U)                                         
#define PWR_CSR_PVDO_Msk       (0x1UL << PWR_CSR_PVDO_Pos)                  
#define PWR_CSR_PVDO           PWR_CSR_PVDO_Msk                             
#define PWR_CSR_BRR_Pos        (3U)                                         
#define PWR_CSR_BRR_Msk        (0x1UL << PWR_CSR_BRR_Pos)                   
#define PWR_CSR_BRR            PWR_CSR_BRR_Msk                              
#define PWR_CSR_EWUP_Pos       (8U)                                         
#define PWR_CSR_EWUP_Msk       (0x1UL << PWR_CSR_EWUP_Pos)                  
#define PWR_CSR_EWUP           PWR_CSR_EWUP_Msk                             
#define PWR_CSR_BRE_Pos        (9U)                                         
#define PWR_CSR_BRE_Msk        (0x1UL << PWR_CSR_BRE_Pos)                   
#define PWR_CSR_BRE            PWR_CSR_BRE_Msk                              
#define PWR_CSR_VOSRDY_Pos     (14U)                                        
#define PWR_CSR_VOSRDY_Msk     (0x1UL << PWR_CSR_VOSRDY_Pos)                
#define PWR_CSR_VOSRDY         PWR_CSR_VOSRDY_Msk                           





/*  Bit definition for RCC_CR register */
#define RCC_CR_HSION_Pos                   (0U)                                
#define RCC_CR_HSION_Msk                   (0x1UL << RCC_CR_HSION_Pos)        
#define RCC_CR_HSION                       RCC_CR_HSION_Msk                   
#define RCC_CR_HSIRDY_Pos                  (1U)                               
#define RCC_CR_HSIRDY_Msk                  (0x1UL << RCC_CR_HSIRDY_Pos)       
#define RCC_CR_HSIRDY                      RCC_CR_HSIRDY_Msk                  

#define RCC_CR_HSITRIM_Pos                 (3U)                               
#define RCC_CR_HSITRIM_Msk                 (0x1FUL << RCC_CR_HSITRIM_Pos)     
#define RCC_CR_HSITRIM                     RCC_CR_HSITRIM_Msk                 
#define RCC_CR_HSITRIM_0                   (0x01UL << RCC_CR_HSITRIM_Pos)     
#define RCC_CR_HSITRIM_1                   (0x02UL << RCC_CR_HSITRIM_Pos)     
#define RCC_CR_HSITRIM_2                   (0x04UL << RCC_CR_HSITRIM_Pos)     
#define RCC_CR_HSITRIM_3                   (0x08UL << RCC_CR_HSITRIM_Pos)     
#define RCC_CR_HSITRIM_4                   (0x10UL << RCC_CR_HSITRIM_Pos)     

#define RCC_CR_HSICAL_Pos                  (8U)                               
#define RCC_CR_HSICAL_Msk                  (0xFFUL << RCC_CR_HSICAL_Pos)      
#define RCC_CR_HSICAL                      RCC_CR_HSICAL_Msk                  
#define RCC_CR_HSICAL_0                    (0x01UL << RCC_CR_HSICAL_Pos)      
#define RCC_CR_HSICAL_1                    (0x02UL << RCC_CR_HSICAL_Pos)      
#define RCC_CR_HSICAL_2                    (0x04UL << RCC_CR_HSICAL_Pos)      
#define RCC_CR_HSICAL_3                    (0x08UL << RCC_CR_HSICAL_Pos)      
#define RCC_CR_HSICAL_4                    (0x10UL << RCC_CR_HSICAL_Pos)      
#define RCC_CR_HSICAL_5                    (0x20UL << RCC_CR_HSICAL_Pos)      
#define RCC_CR_HSICAL_6                    (0x40UL << RCC_CR_HSICAL_Pos)      
#define RCC_CR_HSICAL_7                    (0x80UL << RCC_CR_HSICAL_Pos)      

#define RCC_CR_HSEON_Pos                   (16U)                              
#define RCC_CR_HSEON_Msk                   (0x1UL << RCC_CR_HSEON_Pos)        
#define RCC_CR_HSEON                       RCC_CR_HSEON_Msk                   
#define RCC_CR_HSERDY_Pos                  (17U)                              
#define RCC_CR_HSERDY_Msk                  (0x1UL << RCC_CR_HSERDY_Pos)       
#define RCC_CR_HSERDY                      RCC_CR_HSERDY_Msk                  
#define RCC_CR_HSEBYP_Pos                  (18U)                              
#define RCC_CR_HSEBYP_Msk                  (0x1UL << RCC_CR_HSEBYP_Pos)       
#define RCC_CR_HSEBYP                      RCC_CR_HSEBYP_Msk                  
#define RCC_CR_CSSON_Pos                   (19U)                              
#define RCC_CR_CSSON_Msk                   (0x1UL << RCC_CR_CSSON_Pos)        
#define RCC_CR_CSSON                       RCC_CR_CSSON_Msk                   
#define RCC_CR_PLLON_Pos                   (24U)                              
#define RCC_CR_PLLON_Msk                   (0x1UL << RCC_CR_PLLON_Pos)        
#define RCC_CR_PLLON                       RCC_CR_PLLON_Msk                   
#define RCC_CR_PLLRDY_Pos                  (25U)                              
#define RCC_CR_PLLRDY_Msk                  (0x1UL << RCC_CR_PLLRDY_Pos)       
#define RCC_CR_PLLRDY                      RCC_CR_PLLRDY_Msk     

#define RCC_PLLI2S_SUPPORT                                                
#define RCC_CR_PLLI2SON_Pos                (26U)                          
#define RCC_CR_PLLI2SON_Msk                (0x1UL << RCC_CR_PLLI2SON_Pos) 
#define RCC_CR_PLLI2SON                    RCC_CR_PLLI2SON_Msk            
#define RCC_CR_PLLI2SRDY_Pos               (27U)                          
#define RCC_CR_PLLI2SRDY_Msk               (0x1UL << RCC_CR_PLLI2SRDY_Pos)
#define RCC_CR_PLLI2SRDY                   RCC_CR_PLLI2SRDY_Msk           

#define RCC_PLLCFGR_PLLM_Pos               (0U)                                
#define RCC_PLLCFGR_PLLM_Msk               (0x3FUL << RCC_PLLCFGR_PLLM_Pos)    
#define RCC_PLLCFGR_PLLM                   RCC_PLLCFGR_PLLM_Msk               
#define RCC_PLLCFGR_PLLM_0                 (0x01UL << RCC_PLLCFGR_PLLM_Pos)    
#define RCC_PLLCFGR_PLLM_1                 (0x02UL << RCC_PLLCFGR_PLLM_Pos)    
#define RCC_PLLCFGR_PLLM_2                 (0x04UL << RCC_PLLCFGR_PLLM_Pos)    
#define RCC_PLLCFGR_PLLM_3                 (0x08UL << RCC_PLLCFGR_PLLM_Pos)    
#define RCC_PLLCFGR_PLLM_4                 (0x10UL << RCC_PLLCFGR_PLLM_Pos)    
#define RCC_PLLCFGR_PLLM_5                 (0x20UL << RCC_PLLCFGR_PLLM_Pos)    

#define RCC_PLLCFGR_PLLN_Pos               (6U)                               
#define RCC_PLLCFGR_PLLN_Msk               (0x1FFUL << RCC_PLLCFGR_PLLN_Pos)   
#define RCC_PLLCFGR_PLLN                   RCC_PLLCFGR_PLLN_Msk               
#define RCC_PLLCFGR_PLLN_0                 (0x001UL << RCC_PLLCFGR_PLLN_Pos)   
#define RCC_PLLCFGR_PLLN_1                 (0x002UL << RCC_PLLCFGR_PLLN_Pos)   
#define RCC_PLLCFGR_PLLN_2                 (0x004UL << RCC_PLLCFGR_PLLN_Pos)   
#define RCC_PLLCFGR_PLLN_3                 (0x008UL << RCC_PLLCFGR_PLLN_Pos)   
#define RCC_PLLCFGR_PLLN_4                 (0x010UL << RCC_PLLCFGR_PLLN_Pos)   
#define RCC_PLLCFGR_PLLN_5                 (0x020UL << RCC_PLLCFGR_PLLN_Pos)   
#define RCC_PLLCFGR_PLLN_6                 (0x040UL << RCC_PLLCFGR_PLLN_Pos)   
#define RCC_PLLCFGR_PLLN_7                 (0x080UL << RCC_PLLCFGR_PLLN_Pos)   
#define RCC_PLLCFGR_PLLN_8                 (0x100UL << RCC_PLLCFGR_PLLN_Pos)   

#define RCC_PLLCFGR_PLLP_Pos               (16U)                              
#define RCC_PLLCFGR_PLLP_Msk               (0x3UL << RCC_PLLCFGR_PLLP_Pos)     
#define RCC_PLLCFGR_PLLP                   RCC_PLLCFGR_PLLP_Msk               
#define RCC_PLLCFGR_PLLP_0                 (0x1UL << RCC_PLLCFGR_PLLP_Pos)     
#define RCC_PLLCFGR_PLLP_1                 (0x2UL << RCC_PLLCFGR_PLLP_Pos)     

#define RCC_PLLCFGR_PLLSRC_Pos             (22U)                              
#define RCC_PLLCFGR_PLLSRC_Msk             (0x1UL << RCC_PLLCFGR_PLLSRC_Pos)   
#define RCC_PLLCFGR_PLLSRC                 RCC_PLLCFGR_PLLSRC_Msk             
#define RCC_PLLCFGR_PLLSRC_HSE_Pos         (22U)                               
#define RCC_PLLCFGR_PLLSRC_HSE_Msk         (0x1UL << RCC_PLLCFGR_PLLSRC_HSE_Pos) 
#define RCC_PLLCFGR_PLLSRC_HSE             RCC_PLLCFGR_PLLSRC_HSE_Msk          
#define RCC_PLLCFGR_PLLSRC_HSI             0x00000000U                         

#define RCC_PLLCFGR_PLLQ_Pos               (24U)                               
#define RCC_PLLCFGR_PLLQ_Msk               (0xFUL << RCC_PLLCFGR_PLLQ_Pos)      
#define RCC_PLLCFGR_PLLQ                   RCC_PLLCFGR_PLLQ_Msk                
#define RCC_PLLCFGR_PLLQ_0                 (0x1UL << RCC_PLLCFGR_PLLQ_Pos)      
#define RCC_PLLCFGR_PLLQ_1                 (0x2UL << RCC_PLLCFGR_PLLQ_Pos)      
#define RCC_PLLCFGR_PLLQ_2                 (0x4UL << RCC_PLLCFGR_PLLQ_Pos)      
#define RCC_PLLCFGR_PLLQ_3                 (0x8UL << RCC_PLLCFGR_PLLQ_Pos)      


/********************  Bit definition for RCC_CFGR register  ******************/
/* SW configuration */
#define RCC_CFGR_SW_Pos                    (0U)                                
#define RCC_CFGR_SW_Msk                    (0x3UL << RCC_CFGR_SW_Pos)       
#define RCC_CFGR_SW                        RCC_CFGR_SW_Msk                  
#define RCC_CFGR_SW_0                      (0x1UL << RCC_CFGR_SW_Pos)       
#define RCC_CFGR_SW_1                      (0x2UL << RCC_CFGR_SW_Pos)       

#define RCC_CFGR_SW_HSI                    0x00000000U                      
#define RCC_CFGR_SW_HSE                    0x00000001U                      
#define RCC_CFGR_SW_PLL                    0x00000002U                      

/* SWS configuration */
#define RCC_CFGR_SWS_Pos                   (2U)                             
#define RCC_CFGR_SWS_Msk                   (0x3UL << RCC_CFGR_SWS_Pos)      
#define RCC_CFGR_SWS                       RCC_CFGR_SWS_Msk                 
#define RCC_CFGR_SWS_0                     (0x1UL << RCC_CFGR_SWS_Pos)      
#define RCC_CFGR_SWS_1                     (0x2UL << RCC_CFGR_SWS_Pos)      

#define RCC_CFGR_SWS_HSI                   0x00000000U                      
#define RCC_CFGR_SWS_HSE                   0x00000004U                      
#define RCC_CFGR_SWS_PLL                   0x00000008U                      

/* HPRE configuration */
#define RCC_CFGR_HPRE_Pos                  (4U)                                
#define RCC_CFGR_HPRE_Msk                  (0xFUL << RCC_CFGR_HPRE_Pos)      
#define RCC_CFGR_HPRE                      RCC_CFGR_HPRE_Msk                 
#define RCC_CFGR_HPRE_0                    (0x1UL << RCC_CFGR_HPRE_Pos)      
#define RCC_CFGR_HPRE_1                    (0x2UL << RCC_CFGR_HPRE_Pos)      
#define RCC_CFGR_HPRE_2                    (0x4UL << RCC_CFGR_HPRE_Pos)      
#define RCC_CFGR_HPRE_3                    (0x8UL << RCC_CFGR_HPRE_Pos)      

#define RCC_CFGR_HPRE_DIV1                 0x00000000U                       
#define RCC_CFGR_HPRE_DIV2                 0x00000080U                       
#define RCC_CFGR_HPRE_DIV4                 0x00000090U                       
#define RCC_CFGR_HPRE_DIV8                 0x000000A0U                       
#define RCC_CFGR_HPRE_DIV16                0x000000B0U                       
#define RCC_CFGR_HPRE_DIV64                0x000000C0U                       
#define RCC_CFGR_HPRE_DIV128               0x000000D0U                       
#define RCC_CFGR_HPRE_DIV256               0x000000E0U                       
#define RCC_CFGR_HPRE_DIV512               0x000000F0U                       

/* PPRE1 configuration */
#define RCC_CFGR_PPRE1_Pos                 (10U)                               
#define RCC_CFGR_PPRE1_Msk                 (0x7UL << RCC_CFGR_PPRE1_Pos)    
#define RCC_CFGR_PPRE1                     RCC_CFGR_PPRE1_Msk               
#define RCC_CFGR_PPRE1_0                   (0x1UL << RCC_CFGR_PPRE1_Pos)    
#define RCC_CFGR_PPRE1_1                   (0x2UL << RCC_CFGR_PPRE1_Pos)    
#define RCC_CFGR_PPRE1_2                   (0x4UL << RCC_CFGR_PPRE1_Pos)    

#define RCC_CFGR_PPRE1_DIV1                0x00000000U                      
#define RCC_CFGR_PPRE1_DIV2                0x00001000U                      
#define RCC_CFGR_PPRE1_DIV4                0x00001400U                      
#define RCC_CFGR_PPRE1_DIV8                0x00001800U                      
#define RCC_CFGR_PPRE1_DIV16               0x00001C00U                      

/* PPRE2 configuration */
#define RCC_CFGR_PPRE2_Pos                 (13U)                            
#define RCC_CFGR_PPRE2_Msk                 (0x7UL << RCC_CFGR_PPRE2_Pos)    
#define RCC_CFGR_PPRE2                     RCC_CFGR_PPRE2_Msk               
#define RCC_CFGR_PPRE2_0                   (0x1UL << RCC_CFGR_PPRE2_Pos)    
#define RCC_CFGR_PPRE2_1                   (0x2UL << RCC_CFGR_PPRE2_Pos)    
#define RCC_CFGR_PPRE2_2                   (0x4UL << RCC_CFGR_PPRE2_Pos)    

#define RCC_CFGR_PPRE2_DIV1                0x00000000U                      
#define RCC_CFGR_PPRE2_DIV2                0x00008000U                      
#define RCC_CFGR_PPRE2_DIV4                0x0000A000U                      
#define RCC_CFGR_PPRE2_DIV8                0x0000C000U                      
#define RCC_CFGR_PPRE2_DIV16               0x0000E000U                      

/* RTCPRE configuration */
#define RCC_CFGR_RTCPRE_Pos                (16U)                               
#define RCC_CFGR_RTCPRE_Msk                (0x1FUL << RCC_CFGR_RTCPRE_Pos)    
#define RCC_CFGR_RTCPRE                    RCC_CFGR_RTCPRE_Msk                
#define RCC_CFGR_RTCPRE_0                  (0x01UL << RCC_CFGR_RTCPRE_Pos)    
#define RCC_CFGR_RTCPRE_1                  (0x02UL << RCC_CFGR_RTCPRE_Pos)    
#define RCC_CFGR_RTCPRE_2                  (0x04UL << RCC_CFGR_RTCPRE_Pos)    
#define RCC_CFGR_RTCPRE_3                  (0x08UL << RCC_CFGR_RTCPRE_Pos)    
#define RCC_CFGR_RTCPRE_4                  (0x10UL << RCC_CFGR_RTCPRE_Pos)    

/* MCO1 configuration */
#define RCC_CFGR_MCO1_Pos                  (21U)                              
#define RCC_CFGR_MCO1_Msk                  (0x3UL << RCC_CFGR_MCO1_Pos)       
#define RCC_CFGR_MCO1                      RCC_CFGR_MCO1_Msk                  
#define RCC_CFGR_MCO1_0                    (0x1UL << RCC_CFGR_MCO1_Pos)       
#define RCC_CFGR_MCO1_1                    (0x2UL << RCC_CFGR_MCO1_Pos)       

#define RCC_CFGR_I2SSRC_Pos                (23U)                              
#define RCC_CFGR_I2SSRC_Msk                (0x1UL << RCC_CFGR_I2SSRC_Pos)     
#define RCC_CFGR_I2SSRC                    RCC_CFGR_I2SSRC_Msk                

#define RCC_CFGR_MCO1PRE_Pos               (24U)                              
#define RCC_CFGR_MCO1PRE_Msk               (0x7UL << RCC_CFGR_MCO1PRE_Pos)    
#define RCC_CFGR_MCO1PRE                   RCC_CFGR_MCO1PRE_Msk               
#define RCC_CFGR_MCO1PRE_0                 (0x1UL << RCC_CFGR_MCO1PRE_Pos)    
#define RCC_CFGR_MCO1PRE_1                 (0x2UL << RCC_CFGR_MCO1PRE_Pos)    
#define RCC_CFGR_MCO1PRE_2                 (0x4UL << RCC_CFGR_MCO1PRE_Pos)    

#define RCC_CFGR_MCO2PRE_Pos               (27U)                              
#define RCC_CFGR_MCO2PRE_Msk               (0x7UL << RCC_CFGR_MCO2PRE_Pos)    
#define RCC_CFGR_MCO2PRE                   RCC_CFGR_MCO2PRE_Msk               
#define RCC_CFGR_MCO2PRE_0                 (0x1UL << RCC_CFGR_MCO2PRE_Pos)     
#define RCC_CFGR_MCO2PRE_1                 (0x2UL << RCC_CFGR_MCO2PRE_Pos)     
#define RCC_CFGR_MCO2PRE_2                 (0x4UL << RCC_CFGR_MCO2PRE_Pos)     

#define RCC_CFGR_MCO2_Pos                  (30U)                              
#define RCC_CFGR_MCO2_Msk                  (0x3UL << RCC_CFGR_MCO2_Pos)        
#define RCC_CFGR_MCO2                      RCC_CFGR_MCO2_Msk                  
#define RCC_CFGR_MCO2_0                    (0x1UL << RCC_CFGR_MCO2_Pos)        
#define RCC_CFGR_MCO2_1                    (0x2UL << RCC_CFGR_MCO2_Pos)        

/********************  Bit definition for RCC_CIR register  *******************/
#define RCC_CIR_LSIRDYF_Pos                (0U)                                
#define RCC_CIR_LSIRDYF_Msk                (0x1UL << RCC_CIR_LSIRDYF_Pos)     
#define RCC_CIR_LSIRDYF                    RCC_CIR_LSIRDYF_Msk                
#define RCC_CIR_LSERDYF_Pos                (1U)                               
#define RCC_CIR_LSERDYF_Msk                (0x1UL << RCC_CIR_LSERDYF_Pos)     
#define RCC_CIR_LSERDYF                    RCC_CIR_LSERDYF_Msk                
#define RCC_CIR_HSIRDYF_Pos                (2U)                               
#define RCC_CIR_HSIRDYF_Msk                (0x1UL << RCC_CIR_HSIRDYF_Pos)     
#define RCC_CIR_HSIRDYF                    RCC_CIR_HSIRDYF_Msk                
#define RCC_CIR_HSERDYF_Pos                (3U)                               
#define RCC_CIR_HSERDYF_Msk                (0x1UL << RCC_CIR_HSERDYF_Pos)     
#define RCC_CIR_HSERDYF                    RCC_CIR_HSERDYF_Msk                
#define RCC_CIR_PLLRDYF_Pos                (4U)                               
#define RCC_CIR_PLLRDYF_Msk                (0x1UL << RCC_CIR_PLLRDYF_Pos)     
#define RCC_CIR_PLLRDYF                    RCC_CIR_PLLRDYF_Msk                
#define RCC_CIR_PLLI2SRDYF_Pos             (5U)                               
#define RCC_CIR_PLLI2SRDYF_Msk             (0x1UL << RCC_CIR_PLLI2SRDYF_Pos)  
#define RCC_CIR_PLLI2SRDYF                 RCC_CIR_PLLI2SRDYF_Msk             

#define RCC_CIR_CSSF_Pos                   (7U)                               
#define RCC_CIR_CSSF_Msk                   (0x1UL << RCC_CIR_CSSF_Pos)        
#define RCC_CIR_CSSF                       RCC_CIR_CSSF_Msk                   
#define RCC_CIR_LSIRDYIE_Pos               (8U)                               
#define RCC_CIR_LSIRDYIE_Msk               (0x1UL << RCC_CIR_LSIRDYIE_Pos)    
#define RCC_CIR_LSIRDYIE                   RCC_CIR_LSIRDYIE_Msk               
#define RCC_CIR_LSERDYIE_Pos               (9U)                               
#define RCC_CIR_LSERDYIE_Msk               (0x1UL << RCC_CIR_LSERDYIE_Pos)    
#define RCC_CIR_LSERDYIE                   RCC_CIR_LSERDYIE_Msk                
#define RCC_CIR_HSIRDYIE_Pos               (10U)                               
#define RCC_CIR_HSIRDYIE_Msk               (0x1UL << RCC_CIR_HSIRDYIE_Pos)      
#define RCC_CIR_HSIRDYIE                   RCC_CIR_HSIRDYIE_Msk                
#define RCC_CIR_HSERDYIE_Pos               (11U)                               
#define RCC_CIR_HSERDYIE_Msk               (0x1UL << RCC_CIR_HSERDYIE_Pos)      
#define RCC_CIR_HSERDYIE                   RCC_CIR_HSERDYIE_Msk                
#define RCC_CIR_PLLRDYIE_Pos               (12U)                               
#define RCC_CIR_PLLRDYIE_Msk               (0x1UL << RCC_CIR_PLLRDYIE_Pos)      
#define RCC_CIR_PLLRDYIE                   RCC_CIR_PLLRDYIE_Msk                
#define RCC_CIR_PLLI2SRDYIE_Pos            (13U)                               
#define RCC_CIR_PLLI2SRDYIE_Msk            (0x1UL << RCC_CIR_PLLI2SRDYIE_Pos)   
#define RCC_CIR_PLLI2SRDYIE                RCC_CIR_PLLI2SRDYIE_Msk             

#define RCC_CIR_LSIRDYC_Pos                (16U)                               
#define RCC_CIR_LSIRDYC_Msk                (0x1UL << RCC_CIR_LSIRDYC_Pos)       
#define RCC_CIR_LSIRDYC                    RCC_CIR_LSIRDYC_Msk                 
#define RCC_CIR_LSERDYC_Pos                (17U)                               
#define RCC_CIR_LSERDYC_Msk                (0x1UL << RCC_CIR_LSERDYC_Pos)       
#define RCC_CIR_LSERDYC                    RCC_CIR_LSERDYC_Msk                 
#define RCC_CIR_HSIRDYC_Pos                (18U)                               
#define RCC_CIR_HSIRDYC_Msk                (0x1UL << RCC_CIR_HSIRDYC_Pos)       
#define RCC_CIR_HSIRDYC                    RCC_CIR_HSIRDYC_Msk                 
#define RCC_CIR_HSERDYC_Pos                (19U)                               
#define RCC_CIR_HSERDYC_Msk                (0x1UL << RCC_CIR_HSERDYC_Pos)       
#define RCC_CIR_HSERDYC                    RCC_CIR_HSERDYC_Msk                 
#define RCC_CIR_PLLRDYC_Pos                (20U)                               
#define RCC_CIR_PLLRDYC_Msk                (0x1UL << RCC_CIR_PLLRDYC_Pos)       
#define RCC_CIR_PLLRDYC                    RCC_CIR_PLLRDYC_Msk                 
#define RCC_CIR_PLLI2SRDYC_Pos             (21U)                              
#define RCC_CIR_PLLI2SRDYC_Msk             (0x1UL << RCC_CIR_PLLI2SRDYC_Pos)   
#define RCC_CIR_PLLI2SRDYC                 RCC_CIR_PLLI2SRDYC_Msk             

#define RCC_CIR_CSSC_Pos                   (23U)                              
#define RCC_CIR_CSSC_Msk                   (0x1UL << RCC_CIR_CSSC_Pos)         
#define RCC_CIR_CSSC                       RCC_CIR_CSSC_Msk                    

/********************  Bit definition for RCC_AHB1RSTR register  **************/
#define RCC_AHB1RSTR_GPIOARST_Pos          (0U)                                
#define RCC_AHB1RSTR_GPIOARST_Msk          (0x1UL << RCC_AHB1RSTR_GPIOARST_Pos) 
#define RCC_AHB1RSTR_GPIOARST              RCC_AHB1RSTR_GPIOARST_Msk           
#define RCC_AHB1RSTR_GPIOBRST_Pos          (1U)                                
#define RCC_AHB1RSTR_GPIOBRST_Msk          (0x1UL << RCC_AHB1RSTR_GPIOBRST_Pos) 
#define RCC_AHB1RSTR_GPIOBRST              RCC_AHB1RSTR_GPIOBRST_Msk           
#define RCC_AHB1RSTR_GPIOCRST_Pos          (2U)                                
#define RCC_AHB1RSTR_GPIOCRST_Msk          (0x1UL << RCC_AHB1RSTR_GPIOCRST_Pos) 
#define RCC_AHB1RSTR_GPIOCRST              RCC_AHB1RSTR_GPIOCRST_Msk           
#define RCC_AHB1RSTR_GPIODRST_Pos          (3U)                                
#define RCC_AHB1RSTR_GPIODRST_Msk          (0x1UL << RCC_AHB1RSTR_GPIODRST_Pos) 
#define RCC_AHB1RSTR_GPIODRST              RCC_AHB1RSTR_GPIODRST_Msk           
#define RCC_AHB1RSTR_GPIOERST_Pos          (4U)                                
#define RCC_AHB1RSTR_GPIOERST_Msk          (0x1UL << RCC_AHB1RSTR_GPIOERST_Pos) 
#define RCC_AHB1RSTR_GPIOERST              RCC_AHB1RSTR_GPIOERST_Msk           
#define RCC_AHB1RSTR_GPIOFRST_Pos          (5U)                                
#define RCC_AHB1RSTR_GPIOFRST_Msk          (0x1UL << RCC_AHB1RSTR_GPIOFRST_Pos) 
#define RCC_AHB1RSTR_GPIOFRST              RCC_AHB1RSTR_GPIOFRST_Msk           
#define RCC_AHB1RSTR_GPIOGRST_Pos          (6U)                                
#define RCC_AHB1RSTR_GPIOGRST_Msk          (0x1UL << RCC_AHB1RSTR_GPIOGRST_Pos) 
#define RCC_AHB1RSTR_GPIOGRST              RCC_AHB1RSTR_GPIOGRST_Msk           
#define RCC_AHB1RSTR_GPIOHRST_Pos          (7U)                                
#define RCC_AHB1RSTR_GPIOHRST_Msk          (0x1UL << RCC_AHB1RSTR_GPIOHRST_Pos) 
#define RCC_AHB1RSTR_GPIOHRST              RCC_AHB1RSTR_GPIOHRST_Msk           
#define RCC_AHB1RSTR_GPIOIRST_Pos          (8U)                                
#define RCC_AHB1RSTR_GPIOIRST_Msk          (0x1UL << RCC_AHB1RSTR_GPIOIRST_Pos) 
#define RCC_AHB1RSTR_GPIOIRST              RCC_AHB1RSTR_GPIOIRST_Msk           
#define RCC_AHB1RSTR_CRCRST_Pos            (12U)                               
#define RCC_AHB1RSTR_CRCRST_Msk            (0x1UL << RCC_AHB1RSTR_CRCRST_Pos)   
#define RCC_AHB1RSTR_CRCRST                RCC_AHB1RSTR_CRCRST_Msk             
#define RCC_AHB1RSTR_DMA1RST_Pos           (21U)                               
#define RCC_AHB1RSTR_DMA1RST_Msk           (0x1UL << RCC_AHB1RSTR_DMA1RST_Pos)  
#define RCC_AHB1RSTR_DMA1RST               RCC_AHB1RSTR_DMA1RST_Msk            
#define RCC_AHB1RSTR_DMA2RST_Pos           (22U)                               
#define RCC_AHB1RSTR_DMA2RST_Msk           (0x1UL << RCC_AHB1RSTR_DMA2RST_Pos)  
#define RCC_AHB1RSTR_DMA2RST               RCC_AHB1RSTR_DMA2RST_Msk            
#define RCC_AHB1RSTR_ETHMACRST_Pos         (25U)                               
#define RCC_AHB1RSTR_ETHMACRST_Msk         (0x1UL << RCC_AHB1RSTR_ETHMACRST_Pos)
#define RCC_AHB1RSTR_ETHMACRST             RCC_AHB1RSTR_ETHMACRST_Msk          
#define RCC_AHB1RSTR_OTGHRST_Pos           (29U)                               
#define RCC_AHB1RSTR_OTGHRST_Msk           (0x1UL << RCC_AHB1RSTR_OTGHRST_Pos)  
#define RCC_AHB1RSTR_OTGHRST               RCC_AHB1RSTR_OTGHRST_Msk            

/********************  Bit definition for RCC_AHB2RSTR register  **************/
#define RCC_AHB2RSTR_DCMIRST_Pos           (0U)                                
#define RCC_AHB2RSTR_DCMIRST_Msk           (0x1UL << RCC_AHB2RSTR_DCMIRST_Pos)  
#define RCC_AHB2RSTR_DCMIRST               RCC_AHB2RSTR_DCMIRST_Msk            
#define RCC_AHB2RSTR_RNGRST_Pos            (6U)                                
#define RCC_AHB2RSTR_RNGRST_Msk            (0x1UL << RCC_AHB2RSTR_RNGRST_Pos)   
#define RCC_AHB2RSTR_RNGRST                RCC_AHB2RSTR_RNGRST_Msk             
#define RCC_AHB2RSTR_OTGFSRST_Pos          (7U)                                
#define RCC_AHB2RSTR_OTGFSRST_Msk          (0x1UL << RCC_AHB2RSTR_OTGFSRST_Pos) 
#define RCC_AHB2RSTR_OTGFSRST              RCC_AHB2RSTR_OTGFSRST_Msk           
/********************  Bit definition for RCC_AHB3RSTR register  **************/
#define RCC_AHB3RSTR_FSMCRST_Pos           (0U)                                
#define RCC_AHB3RSTR_FSMCRST_Msk           (0x1UL << RCC_AHB3RSTR_FSMCRST_Pos)  
#define RCC_AHB3RSTR_FSMCRST               RCC_AHB3RSTR_FSMCRST_Msk            


/********************  Bit definition for RCC_APB1RSTR register  **************/
#define RCC_APB1RSTR_TIM2RST_Pos           (0U)                                
#define RCC_APB1RSTR_TIM2RST_Msk           (0x1UL << RCC_APB1RSTR_TIM2RST_Pos)  
#define RCC_APB1RSTR_TIM2RST               RCC_APB1RSTR_TIM2RST_Msk            
#define RCC_APB1RSTR_TIM3RST_Pos           (1U)                                
#define RCC_APB1RSTR_TIM3RST_Msk           (0x1UL << RCC_APB1RSTR_TIM3RST_Pos)  
#define RCC_APB1RSTR_TIM3RST               RCC_APB1RSTR_TIM3RST_Msk            
#define RCC_APB1RSTR_TIM4RST_Pos           (2U)                                
#define RCC_APB1RSTR_TIM4RST_Msk           (0x1UL << RCC_APB1RSTR_TIM4RST_Pos)  
#define RCC_APB1RSTR_TIM4RST               RCC_APB1RSTR_TIM4RST_Msk            
#define RCC_APB1RSTR_TIM5RST_Pos           (3U)                                
#define RCC_APB1RSTR_TIM5RST_Msk           (0x1UL << RCC_APB1RSTR_TIM5RST_Pos)  
#define RCC_APB1RSTR_TIM5RST               RCC_APB1RSTR_TIM5RST_Msk            
#define RCC_APB1RSTR_TIM6RST_Pos           (4U)                                
#define RCC_APB1RSTR_TIM6RST_Msk           (0x1UL << RCC_APB1RSTR_TIM6RST_Pos)  
#define RCC_APB1RSTR_TIM6RST               RCC_APB1RSTR_TIM6RST_Msk            
#define RCC_APB1RSTR_TIM7RST_Pos           (5U)                                
#define RCC_APB1RSTR_TIM7RST_Msk           (0x1UL << RCC_APB1RSTR_TIM7RST_Pos)  
#define RCC_APB1RSTR_TIM7RST               RCC_APB1RSTR_TIM7RST_Msk            
#define RCC_APB1RSTR_TIM12RST_Pos          (6U)                                
#define RCC_APB1RSTR_TIM12RST_Msk          (0x1UL << RCC_APB1RSTR_TIM12RST_Pos) 
#define RCC_APB1RSTR_TIM12RST              RCC_APB1RSTR_TIM12RST_Msk           
#define RCC_APB1RSTR_TIM13RST_Pos          (7U)                                
#define RCC_APB1RSTR_TIM13RST_Msk          (0x1UL << RCC_APB1RSTR_TIM13RST_Pos) 
#define RCC_APB1RSTR_TIM13RST              RCC_APB1RSTR_TIM13RST_Msk           
#define RCC_APB1RSTR_TIM14RST_Pos          (8U)                                
#define RCC_APB1RSTR_TIM14RST_Msk          (0x1UL << RCC_APB1RSTR_TIM14RST_Pos) 
#define RCC_APB1RSTR_TIM14RST              RCC_APB1RSTR_TIM14RST_Msk           
#define RCC_APB1RSTR_WWDGRST_Pos           (11U)                               
#define RCC_APB1RSTR_WWDGRST_Msk           (0x1UL << RCC_APB1RSTR_WWDGRST_Pos)  
#define RCC_APB1RSTR_WWDGRST               RCC_APB1RSTR_WWDGRST_Msk            
#define RCC_APB1RSTR_SPI2RST_Pos           (14U)                               
#define RCC_APB1RSTR_SPI2RST_Msk           (0x1UL << RCC_APB1RSTR_SPI2RST_Pos)  
#define RCC_APB1RSTR_SPI2RST               RCC_APB1RSTR_SPI2RST_Msk            
#define RCC_APB1RSTR_SPI3RST_Pos           (15U)                               
#define RCC_APB1RSTR_SPI3RST_Msk           (0x1UL << RCC_APB1RSTR_SPI3RST_Pos)  
#define RCC_APB1RSTR_SPI3RST               RCC_APB1RSTR_SPI3RST_Msk            
#define RCC_APB1RSTR_USART2RST_Pos         (17U)                               
#define RCC_APB1RSTR_USART2RST_Msk         (0x1UL << RCC_APB1RSTR_USART2RST_Pos)
#define RCC_APB1RSTR_USART2RST             RCC_APB1RSTR_USART2RST_Msk          
#define RCC_APB1RSTR_USART3RST_Pos         (18U)                               
#define RCC_APB1RSTR_USART3RST_Msk         (0x1UL << RCC_APB1RSTR_USART3RST_Pos)
#define RCC_APB1RSTR_USART3RST             RCC_APB1RSTR_USART3RST_Msk          
#define RCC_APB1RSTR_UART4RST_Pos          (19U)                               
#define RCC_APB1RSTR_UART4RST_Msk          (0x1UL << RCC_APB1RSTR_UART4RST_Pos) 
#define RCC_APB1RSTR_UART4RST              RCC_APB1RSTR_UART4RST_Msk           
#define RCC_APB1RSTR_UART5RST_Pos          (20U)                               
#define RCC_APB1RSTR_UART5RST_Msk          (0x1UL << RCC_APB1RSTR_UART5RST_Pos) 
#define RCC_APB1RSTR_UART5RST              RCC_APB1RSTR_UART5RST_Msk           
#define RCC_APB1RSTR_I2C1RST_Pos           (21U)                               
#define RCC_APB1RSTR_I2C1RST_Msk           (0x1UL << RCC_APB1RSTR_I2C1RST_Pos)  
#define RCC_APB1RSTR_I2C1RST               RCC_APB1RSTR_I2C1RST_Msk            
#define RCC_APB1RSTR_I2C2RST_Pos           (22U)                               
#define RCC_APB1RSTR_I2C2RST_Msk           (0x1UL << RCC_APB1RSTR_I2C2RST_Pos)  
#define RCC_APB1RSTR_I2C2RST               RCC_APB1RSTR_I2C2RST_Msk            
#define RCC_APB1RSTR_I2C3RST_Pos           (23U)                               
#define RCC_APB1RSTR_I2C3RST_Msk           (0x1UL << RCC_APB1RSTR_I2C3RST_Pos)  
#define RCC_APB1RSTR_I2C3RST               RCC_APB1RSTR_I2C3RST_Msk            
#define RCC_APB1RSTR_CAN1RST_Pos           (25U)                               
#define RCC_APB1RSTR_CAN1RST_Msk           (0x1UL << RCC_APB1RSTR_CAN1RST_Pos)  
#define RCC_APB1RSTR_CAN1RST               RCC_APB1RSTR_CAN1RST_Msk            
#define RCC_APB1RSTR_CAN2RST_Pos           (26U)                               
#define RCC_APB1RSTR_CAN2RST_Msk           (0x1UL << RCC_APB1RSTR_CAN2RST_Pos)  
#define RCC_APB1RSTR_CAN2RST               RCC_APB1RSTR_CAN2RST_Msk            
#define RCC_APB1RSTR_PWRRST_Pos            (28U)                               
#define RCC_APB1RSTR_PWRRST_Msk            (0x1UL << RCC_APB1RSTR_PWRRST_Pos)   
#define RCC_APB1RSTR_PWRRST                RCC_APB1RSTR_PWRRST_Msk             
#define RCC_APB1RSTR_DACRST_Pos            (29U)                               
#define RCC_APB1RSTR_DACRST_Msk            (0x1UL << RCC_APB1RSTR_DACRST_Pos)   
#define RCC_APB1RSTR_DACRST                RCC_APB1RSTR_DACRST_Msk             

/********************  Bit definition for RCC_APB2RSTR register  **************/
#define RCC_APB2RSTR_TIM1RST_Pos           (0U)                                
#define RCC_APB2RSTR_TIM1RST_Msk           (0x1UL << RCC_APB2RSTR_TIM1RST_Pos)  
#define RCC_APB2RSTR_TIM1RST               RCC_APB2RSTR_TIM1RST_Msk            
#define RCC_APB2RSTR_TIM8RST_Pos           (1U)                                
#define RCC_APB2RSTR_TIM8RST_Msk           (0x1UL << RCC_APB2RSTR_TIM8RST_Pos)  
#define RCC_APB2RSTR_TIM8RST               RCC_APB2RSTR_TIM8RST_Msk            
#define RCC_APB2RSTR_USART1RST_Pos         (4U)                                
#define RCC_APB2RSTR_USART1RST_Msk         (0x1UL << RCC_APB2RSTR_USART1RST_Pos)
#define RCC_APB2RSTR_USART1RST             RCC_APB2RSTR_USART1RST_Msk          
#define RCC_APB2RSTR_USART6RST_Pos         (5U)                                
#define RCC_APB2RSTR_USART6RST_Msk         (0x1UL << RCC_APB2RSTR_USART6RST_Pos)
#define RCC_APB2RSTR_USART6RST             RCC_APB2RSTR_USART6RST_Msk          
#define RCC_APB2RSTR_ADCRST_Pos            (8U)                                
#define RCC_APB2RSTR_ADCRST_Msk            (0x1UL << RCC_APB2RSTR_ADCRST_Pos)   
#define RCC_APB2RSTR_ADCRST                RCC_APB2RSTR_ADCRST_Msk             
#define RCC_APB2RSTR_SDIORST_Pos           (11U)                               
#define RCC_APB2RSTR_SDIORST_Msk           (0x1UL << RCC_APB2RSTR_SDIORST_Pos)  
#define RCC_APB2RSTR_SDIORST               RCC_APB2RSTR_SDIORST_Msk            
#define RCC_APB2RSTR_SPI1RST_Pos           (12U)                               
#define RCC_APB2RSTR_SPI1RST_Msk           (0x1UL << RCC_APB2RSTR_SPI1RST_Pos)  
#define RCC_APB2RSTR_SPI1RST               RCC_APB2RSTR_SPI1RST_Msk            
#define RCC_APB2RSTR_SYSCFGRST_Pos         (14U)                               
#define RCC_APB2RSTR_SYSCFGRST_Msk         (0x1UL << RCC_APB2RSTR_SYSCFGRST_Pos)
#define RCC_APB2RSTR_SYSCFGRST             RCC_APB2RSTR_SYSCFGRST_Msk          
#define RCC_APB2RSTR_TIM9RST_Pos           (16U)                               
#define RCC_APB2RSTR_TIM9RST_Msk           (0x1UL << RCC_APB2RSTR_TIM9RST_Pos)  
#define RCC_APB2RSTR_TIM9RST               RCC_APB2RSTR_TIM9RST_Msk            
#define RCC_APB2RSTR_TIM10RST_Pos          (17U)                               
#define RCC_APB2RSTR_TIM10RST_Msk          (0x1UL << RCC_APB2RSTR_TIM10RST_Pos) 
#define RCC_APB2RSTR_TIM10RST              RCC_APB2RSTR_TIM10RST_Msk           
#define RCC_APB2RSTR_TIM11RST_Pos          (18U)                               
#define RCC_APB2RSTR_TIM11RST_Msk          (0x1UL << RCC_APB2RSTR_TIM11RST_Pos) 
#define RCC_APB2RSTR_TIM11RST              RCC_APB2RSTR_TIM11RST_Msk           

/********************  Bit definition for RCC_AHB1ENR register  ***************/
#define RCC_AHB1ENR_GPIOAEN_Pos            (0U)                                
#define RCC_AHB1ENR_GPIOAEN_Msk            (0x1UL << RCC_AHB1ENR_GPIOAEN_Pos)   
#define RCC_AHB1ENR_GPIOAEN                RCC_AHB1ENR_GPIOAEN_Msk             
#define RCC_AHB1ENR_GPIOBEN_Pos            (1U)                                
#define RCC_AHB1ENR_GPIOBEN_Msk            (0x1UL << RCC_AHB1ENR_GPIOBEN_Pos)   
#define RCC_AHB1ENR_GPIOBEN                RCC_AHB1ENR_GPIOBEN_Msk             
#define RCC_AHB1ENR_GPIOCEN_Pos            (2U)                                
#define RCC_AHB1ENR_GPIOCEN_Msk            (0x1UL << RCC_AHB1ENR_GPIOCEN_Pos)   
#define RCC_AHB1ENR_GPIOCEN                RCC_AHB1ENR_GPIOCEN_Msk             
#define RCC_AHB1ENR_GPIODEN_Pos            (3U)                                
#define RCC_AHB1ENR_GPIODEN_Msk            (0x1UL << RCC_AHB1ENR_GPIODEN_Pos)   
#define RCC_AHB1ENR_GPIODEN                RCC_AHB1ENR_GPIODEN_Msk             
#define RCC_AHB1ENR_GPIOEEN_Pos            (4U)                                
#define RCC_AHB1ENR_GPIOEEN_Msk            (0x1UL << RCC_AHB1ENR_GPIOEEN_Pos)   
#define RCC_AHB1ENR_GPIOEEN                RCC_AHB1ENR_GPIOEEN_Msk             
#define RCC_AHB1ENR_GPIOFEN_Pos            (5U)                                
#define RCC_AHB1ENR_GPIOFEN_Msk            (0x1UL << RCC_AHB1ENR_GPIOFEN_Pos)   
#define RCC_AHB1ENR_GPIOFEN                RCC_AHB1ENR_GPIOFEN_Msk             
#define RCC_AHB1ENR_GPIOGEN_Pos            (6U)                                
#define RCC_AHB1ENR_GPIOGEN_Msk            (0x1UL << RCC_AHB1ENR_GPIOGEN_Pos)   
#define RCC_AHB1ENR_GPIOGEN                RCC_AHB1ENR_GPIOGEN_Msk             
#define RCC_AHB1ENR_GPIOHEN_Pos            (7U)                                
#define RCC_AHB1ENR_GPIOHEN_Msk            (0x1UL << RCC_AHB1ENR_GPIOHEN_Pos)   
#define RCC_AHB1ENR_GPIOHEN                RCC_AHB1ENR_GPIOHEN_Msk             
#define RCC_AHB1ENR_GPIOIEN_Pos            (8U)                                
#define RCC_AHB1ENR_GPIOIEN_Msk            (0x1UL << RCC_AHB1ENR_GPIOIEN_Pos)   
#define RCC_AHB1ENR_GPIOIEN                RCC_AHB1ENR_GPIOIEN_Msk             
#define RCC_AHB1ENR_CRCEN_Pos              (12U)                               
#define RCC_AHB1ENR_CRCEN_Msk              (0x1UL << RCC_AHB1ENR_CRCEN_Pos)     
#define RCC_AHB1ENR_CRCEN                  RCC_AHB1ENR_CRCEN_Msk               
#define RCC_AHB1ENR_BKPSRAMEN_Pos          (18U)                               
#define RCC_AHB1ENR_BKPSRAMEN_Msk          (0x1UL << RCC_AHB1ENR_BKPSRAMEN_Pos) 
#define RCC_AHB1ENR_BKPSRAMEN              RCC_AHB1ENR_BKPSRAMEN_Msk           
#define RCC_AHB1ENR_CCMDATARAMEN_Pos       (20U)                               
#define RCC_AHB1ENR_CCMDATARAMEN_Msk       (0x1UL << RCC_AHB1ENR_CCMDATARAMEN_Pos)/
#define RCC_AHB1ENR_CCMDATARAMEN           RCC_AHB1ENR_CCMDATARAMEN_Msk        
#define RCC_AHB1ENR_DMA1EN_Pos             (21U)                               
#define RCC_AHB1ENR_DMA1EN_Msk             (0x1UL << RCC_AHB1ENR_DMA1EN_Pos)   
#define RCC_AHB1ENR_DMA1EN                 RCC_AHB1ENR_DMA1EN_Msk              
#define RCC_AHB1ENR_DMA2EN_Pos             (22U)                               
#define RCC_AHB1ENR_DMA2EN_Msk             (0x1UL << RCC_AHB1ENR_DMA2EN_Pos)   
#define RCC_AHB1ENR_DMA2EN                 RCC_AHB1ENR_DMA2EN_Msk              
#define RCC_AHB1ENR_ETHMACEN_Pos           (25U)                               
#define RCC_AHB1ENR_ETHMACEN_Msk           (0x1UL << RCC_AHB1ENR_ETHMACEN_Pos) 
#define RCC_AHB1ENR_ETHMACEN               RCC_AHB1ENR_ETHMACEN_Msk            
#define RCC_AHB1ENR_ETHMACTXEN_Pos         (26U)                               
#define RCC_AHB1ENR_ETHMACTXEN_Msk         (0x1UL << RCC_AHB1ENR_ETHMACTXEN_Pos) 
#define RCC_AHB1ENR_ETHMACTXEN             RCC_AHB1ENR_ETHMACTXEN_Msk          
#define RCC_AHB1ENR_ETHMACRXEN_Pos         (27U)                               
#define RCC_AHB1ENR_ETHMACRXEN_Msk         (0x1UL << RCC_AHB1ENR_ETHMACRXEN_Pos) 
#define RCC_AHB1ENR_ETHMACRXEN             RCC_AHB1ENR_ETHMACRXEN_Msk          
#define RCC_AHB1ENR_ETHMACPTPEN_Pos        (28U)                               
#define RCC_AHB1ENR_ETHMACPTPEN_Msk        (0x1UL << RCC_AHB1ENR_ETHMACPTPEN_Pos)
#define RCC_AHB1ENR_ETHMACPTPEN            RCC_AHB1ENR_ETHMACPTPEN_Msk         
#define RCC_AHB1ENR_OTGHSEN_Pos            (29U)                               
#define RCC_AHB1ENR_OTGHSEN_Msk            (0x1UL << RCC_AHB1ENR_OTGHSEN_Pos)   
#define RCC_AHB1ENR_OTGHSEN                RCC_AHB1ENR_OTGHSEN_Msk             
#define RCC_AHB1ENR_OTGHSULPIEN_Pos        (30U)                               
#define RCC_AHB1ENR_OTGHSULPIEN_Msk        (0x1UL << RCC_AHB1ENR_OTGHSULPIEN_Pos) 
#define RCC_AHB1ENR_OTGHSULPIEN            RCC_AHB1ENR_OTGHSULPIEN_Msk         
/********************  Bit definition for RCC_AHB2ENR register  ***************/
#define RCC_AHB2_SUPPORT                 

#define RCC_AHB2ENR_DCMIEN_Pos             (0U)                                
#define RCC_AHB2ENR_DCMIEN_Msk             (0x1UL << RCC_AHB2ENR_DCMIEN_Pos)    
#define RCC_AHB2ENR_DCMIEN                 RCC_AHB2ENR_DCMIEN_Msk              
#define RCC_AHB2ENR_RNGEN_Pos              (6U)                                
#define RCC_AHB2ENR_RNGEN_Msk              (0x1UL << RCC_AHB2ENR_RNGEN_Pos)     
#define RCC_AHB2ENR_RNGEN                  RCC_AHB2ENR_RNGEN_Msk               
#define RCC_AHB2ENR_OTGFSEN_Pos            (7U)                                
#define RCC_AHB2ENR_OTGFSEN_Msk            (0x1UL << RCC_AHB2ENR_OTGFSEN_Pos)   
#define RCC_AHB2ENR_OTGFSEN                RCC_AHB2ENR_OTGFSEN_Msk             

/********************  Bit definition for RCC_AHB3ENR register  ***************/
#define RCC_AHB3_SUPPORT                  

#define RCC_AHB3ENR_FSMCEN_Pos             (0U)                                
#define RCC_AHB3ENR_FSMCEN_Msk             (0x1UL << RCC_AHB3ENR_FSMCEN_Pos)    
#define RCC_AHB3ENR_FSMCEN                 RCC_AHB3ENR_FSMCEN_Msk              

/********************  Bit definition for RCC_APB1ENR register  ***************/
#define RCC_APB1ENR_TIM2EN_Pos             (0U)                                
#define RCC_APB1ENR_TIM2EN_Msk             (0x1UL << RCC_APB1ENR_TIM2EN_Pos)   
#define RCC_APB1ENR_TIM2EN                 RCC_APB1ENR_TIM2EN_Msk             
#define RCC_APB1ENR_TIM3EN_Pos             (1U)                               
#define RCC_APB1ENR_TIM3EN_Msk             (0x1UL << RCC_APB1ENR_TIM3EN_Pos)   
#define RCC_APB1ENR_TIM3EN                 RCC_APB1ENR_TIM3EN_Msk             
#define RCC_APB1ENR_TIM4EN_Pos             (2U)                               
#define RCC_APB1ENR_TIM4EN_Msk             (0x1UL << RCC_APB1ENR_TIM4EN_Pos)   
#define RCC_APB1ENR_TIM4EN                 RCC_APB1ENR_TIM4EN_Msk             
#define RCC_APB1ENR_TIM5EN_Pos             (3U)                               
#define RCC_APB1ENR_TIM5EN_Msk             (0x1UL << RCC_APB1ENR_TIM5EN_Pos)   
#define RCC_APB1ENR_TIM5EN                 RCC_APB1ENR_TIM5EN_Msk             
#define RCC_APB1ENR_TIM6EN_Pos             (4U)                               
#define RCC_APB1ENR_TIM6EN_Msk             (0x1UL << RCC_APB1ENR_TIM6EN_Pos)   
#define RCC_APB1ENR_TIM6EN                 RCC_APB1ENR_TIM6EN_Msk             
#define RCC_APB1ENR_TIM7EN_Pos             (5U)                               
#define RCC_APB1ENR_TIM7EN_Msk             (0x1UL << RCC_APB1ENR_TIM7EN_Pos)   
#define RCC_APB1ENR_TIM7EN                 RCC_APB1ENR_TIM7EN_Msk             
#define RCC_APB1ENR_TIM12EN_Pos            (6U)                               
#define RCC_APB1ENR_TIM12EN_Msk            (0x1UL << RCC_APB1ENR_TIM12EN_Pos)  
#define RCC_APB1ENR_TIM12EN                RCC_APB1ENR_TIM12EN_Msk            
#define RCC_APB1ENR_TIM13EN_Pos            (7U)                               
#define RCC_APB1ENR_TIM13EN_Msk            (0x1UL << RCC_APB1ENR_TIM13EN_Pos)  
#define RCC_APB1ENR_TIM13EN                RCC_APB1ENR_TIM13EN_Msk            
#define RCC_APB1ENR_TIM14EN_Pos            (8U)                               
#define RCC_APB1ENR_TIM14EN_Msk            (0x1UL << RCC_APB1ENR_TIM14EN_Pos)  
#define RCC_APB1ENR_TIM14EN                RCC_APB1ENR_TIM14EN_Msk            
#define RCC_APB1ENR_WWDGEN_Pos             (11U)                              
#define RCC_APB1ENR_WWDGEN_Msk             (0x1UL << RCC_APB1ENR_WWDGEN_Pos)   
#define RCC_APB1ENR_WWDGEN                 RCC_APB1ENR_WWDGEN_Msk             
#define RCC_APB1ENR_SPI2EN_Pos             (14U)                              
#define RCC_APB1ENR_SPI2EN_Msk             (0x1UL << RCC_APB1ENR_SPI2EN_Pos)   
#define RCC_APB1ENR_SPI2EN                 RCC_APB1ENR_SPI2EN_Msk             
#define RCC_APB1ENR_SPI3EN_Pos             (15U)                              
#define RCC_APB1ENR_SPI3EN_Msk             (0x1UL << RCC_APB1ENR_SPI3EN_Pos)   
#define RCC_APB1ENR_SPI3EN                 RCC_APB1ENR_SPI3EN_Msk             
#define RCC_APB1ENR_USART2EN_Pos           (17U)                              
#define RCC_APB1ENR_USART2EN_Msk           (0x1UL << RCC_APB1ENR_USART2EN_Pos) 
#define RCC_APB1ENR_USART2EN               RCC_APB1ENR_USART2EN_Msk           
#define RCC_APB1ENR_USART3EN_Pos           (18U)                               
#define RCC_APB1ENR_USART3EN_Msk           (0x1UL << RCC_APB1ENR_USART3EN_Pos)  
#define RCC_APB1ENR_USART3EN               RCC_APB1ENR_USART3EN_Msk            
#define RCC_APB1ENR_UART4EN_Pos            (19U)                               
#define RCC_APB1ENR_UART4EN_Msk            (0x1UL << RCC_APB1ENR_UART4EN_Pos)   
#define RCC_APB1ENR_UART4EN                RCC_APB1ENR_UART4EN_Msk             
#define RCC_APB1ENR_UART5EN_Pos            (20U)                               
#define RCC_APB1ENR_UART5EN_Msk            (0x1UL << RCC_APB1ENR_UART5EN_Pos)   
#define RCC_APB1ENR_UART5EN                RCC_APB1ENR_UART5EN_Msk             
#define RCC_APB1ENR_I2C1EN_Pos             (21U)                               
#define RCC_APB1ENR_I2C1EN_Msk             (0x1UL << RCC_APB1ENR_I2C1EN_Pos)    
#define RCC_APB1ENR_I2C1EN                 RCC_APB1ENR_I2C1EN_Msk              
#define RCC_APB1ENR_I2C2EN_Pos             (22U)                               
#define RCC_APB1ENR_I2C2EN_Msk             (0x1UL << RCC_APB1ENR_I2C2EN_Pos)    
#define RCC_APB1ENR_I2C2EN                 RCC_APB1ENR_I2C2EN_Msk              
#define RCC_APB1ENR_I2C3EN_Pos             (23U)                               
#define RCC_APB1ENR_I2C3EN_Msk             (0x1UL << RCC_APB1ENR_I2C3EN_Pos)    
#define RCC_APB1ENR_I2C3EN                 RCC_APB1ENR_I2C3EN_Msk              
#define RCC_APB1ENR_CAN1EN_Pos             (25U)                               
#define RCC_APB1ENR_CAN1EN_Msk             (0x1UL << RCC_APB1ENR_CAN1EN_Pos)    
#define RCC_APB1ENR_CAN1EN                 RCC_APB1ENR_CAN1EN_Msk              
#define RCC_APB1ENR_CAN2EN_Pos             (26U)                               
#define RCC_APB1ENR_CAN2EN_Msk             (0x1UL << RCC_APB1ENR_CAN2EN_Pos)    
#define RCC_APB1ENR_CAN2EN                 RCC_APB1ENR_CAN2EN_Msk              
#define RCC_APB1ENR_PWREN_Pos              (28U)                               
#define RCC_APB1ENR_PWREN_Msk              (0x1UL << RCC_APB1ENR_PWREN_Pos)     
#define RCC_APB1ENR_PWREN                  RCC_APB1ENR_PWREN_Msk               
#define RCC_APB1ENR_DACEN_Pos              (29U)                               
#define RCC_APB1ENR_DACEN_Msk              (0x1UL << RCC_APB1ENR_DACEN_Pos)     
#define RCC_APB1ENR_DACEN                  RCC_APB1ENR_DACEN_Msk               

/********************  Bit definition for RCC_APB2ENR register  ***************/
#define RCC_APB2ENR_TIM1EN_Pos             (0U)                                
#define RCC_APB2ENR_TIM1EN_Msk             (0x1UL << RCC_APB2ENR_TIM1EN_Pos)    
#define RCC_APB2ENR_TIM1EN                 RCC_APB2ENR_TIM1EN_Msk              
#define RCC_APB2ENR_TIM8EN_Pos             (1U)                                
#define RCC_APB2ENR_TIM8EN_Msk             (0x1UL << RCC_APB2ENR_TIM8EN_Pos)    
#define RCC_APB2ENR_TIM8EN                 RCC_APB2ENR_TIM8EN_Msk              
#define RCC_APB2ENR_USART1EN_Pos           (4U)                                
#define RCC_APB2ENR_USART1EN_Msk           (0x1UL << RCC_APB2ENR_USART1EN_Pos)  
#define RCC_APB2ENR_USART1EN               RCC_APB2ENR_USART1EN_Msk            
#define RCC_APB2ENR_USART6EN_Pos           (5U)                                
#define RCC_APB2ENR_USART6EN_Msk           (0x1UL << RCC_APB2ENR_USART6EN_Pos)  
#define RCC_APB2ENR_USART6EN               RCC_APB2ENR_USART6EN_Msk            
#define RCC_APB2ENR_ADC1EN_Pos             (8U)                                
#define RCC_APB2ENR_ADC1EN_Msk             (0x1UL << RCC_APB2ENR_ADC1EN_Pos)    
#define RCC_APB2ENR_ADC1EN                 RCC_APB2ENR_ADC1EN_Msk              
#define RCC_APB2ENR_ADC2EN_Pos             (9U)                                
#define RCC_APB2ENR_ADC2EN_Msk             (0x1UL << RCC_APB2ENR_ADC2EN_Pos)    
#define RCC_APB2ENR_ADC2EN                 RCC_APB2ENR_ADC2EN_Msk              
#define RCC_APB2ENR_ADC3EN_Pos             (10U)                               
#define RCC_APB2ENR_ADC3EN_Msk             (0x1UL << RCC_APB2ENR_ADC3EN_Pos)    
#define RCC_APB2ENR_ADC3EN                 RCC_APB2ENR_ADC3EN_Msk              
#define RCC_APB2ENR_SDIOEN_Pos             (11U)                               
#define RCC_APB2ENR_SDIOEN_Msk             (0x1UL << RCC_APB2ENR_SDIOEN_Pos)    
#define RCC_APB2ENR_SDIOEN                 RCC_APB2ENR_SDIOEN_Msk              
#define RCC_APB2ENR_SPI1EN_Pos             (12U)                               
#define RCC_APB2ENR_SPI1EN_Msk             (0x1UL << RCC_APB2ENR_SPI1EN_Pos)    
#define RCC_APB2ENR_SPI1EN                 RCC_APB2ENR_SPI1EN_Msk              
#define RCC_APB2ENR_SYSCFGEN_Pos           (14U)                               
#define RCC_APB2ENR_SYSCFGEN_Msk           (0x1UL << RCC_APB2ENR_SYSCFGEN_Pos)  
#define RCC_APB2ENR_SYSCFGEN               RCC_APB2ENR_SYSCFGEN_Msk            
#define RCC_APB2ENR_TIM9EN_Pos             (16U)                               
#define RCC_APB2ENR_TIM9EN_Msk             (0x1UL << RCC_APB2ENR_TIM9EN_Pos)    
#define RCC_APB2ENR_TIM9EN                 RCC_APB2ENR_TIM9EN_Msk              
#define RCC_APB2ENR_TIM10EN_Pos            (17U)                               
#define RCC_APB2ENR_TIM10EN_Msk            (0x1UL << RCC_APB2ENR_TIM10EN_Pos)   
#define RCC_APB2ENR_TIM10EN                RCC_APB2ENR_TIM10EN_Msk             
#define RCC_APB2ENR_TIM11EN_Pos            (18U)                               
#define RCC_APB2ENR_TIM11EN_Msk            (0x1UL << RCC_APB2ENR_TIM11EN_Pos)   
#define RCC_APB2ENR_TIM11EN                RCC_APB2ENR_TIM11EN_Msk             

/********************  Bit definition for RCC_AHB1LPENR register  *************/
#define RCC_AHB1LPENR_GPIOALPEN_Pos        (0U)                                
#define RCC_AHB1LPENR_GPIOALPEN_Msk        (0x1UL << RCC_AHB1LPENR_GPIOALPEN_Pos) 
#define RCC_AHB1LPENR_GPIOALPEN            RCC_AHB1LPENR_GPIOALPEN_Msk         
#define RCC_AHB1LPENR_GPIOBLPEN_Pos        (1U)                                
#define RCC_AHB1LPENR_GPIOBLPEN_Msk        (0x1UL << RCC_AHB1LPENR_GPIOBLPEN_Pos) 
#define RCC_AHB1LPENR_GPIOBLPEN            RCC_AHB1LPENR_GPIOBLPEN_Msk         
#define RCC_AHB1LPENR_GPIOCLPEN_Pos        (2U)                                
#define RCC_AHB1LPENR_GPIOCLPEN_Msk        (0x1UL << RCC_AHB1LPENR_GPIOCLPEN_Pos) 
#define RCC_AHB1LPENR_GPIOCLPEN            RCC_AHB1LPENR_GPIOCLPEN_Msk         
#define RCC_AHB1LPENR_GPIODLPEN_Pos        (3U)                                
#define RCC_AHB1LPENR_GPIODLPEN_Msk        (0x1UL << RCC_AHB1LPENR_GPIODLPEN_Pos) 
#define RCC_AHB1LPENR_GPIODLPEN            RCC_AHB1LPENR_GPIODLPEN_Msk         
#define RCC_AHB1LPENR_GPIOELPEN_Pos        (4U)                                
#define RCC_AHB1LPENR_GPIOELPEN_Msk        (0x1UL << RCC_AHB1LPENR_GPIOELPEN_Pos) 
#define RCC_AHB1LPENR_GPIOELPEN            RCC_AHB1LPENR_GPIOELPEN_Msk         
#define RCC_AHB1LPENR_GPIOFLPEN_Pos        (5U)                                
#define RCC_AHB1LPENR_GPIOFLPEN_Msk        (0x1UL << RCC_AHB1LPENR_GPIOFLPEN_Pos) 
#define RCC_AHB1LPENR_GPIOFLPEN            RCC_AHB1LPENR_GPIOFLPEN_Msk         
#define RCC_AHB1LPENR_GPIOGLPEN_Pos        (6U)                                
#define RCC_AHB1LPENR_GPIOGLPEN_Msk        (0x1UL << RCC_AHB1LPENR_GPIOGLPEN_Pos) 
#define RCC_AHB1LPENR_GPIOGLPEN            RCC_AHB1LPENR_GPIOGLPEN_Msk         
#define RCC_AHB1LPENR_GPIOHLPEN_Pos        (7U)                                
#define RCC_AHB1LPENR_GPIOHLPEN_Msk        (0x1UL << RCC_AHB1LPENR_GPIOHLPEN_Pos) 
#define RCC_AHB1LPENR_GPIOHLPEN            RCC_AHB1LPENR_GPIOHLPEN_Msk         
#define RCC_AHB1LPENR_GPIOILPEN_Pos        (8U)                                
#define RCC_AHB1LPENR_GPIOILPEN_Msk        (0x1UL << RCC_AHB1LPENR_GPIOILPEN_Pos) 
#define RCC_AHB1LPENR_GPIOILPEN            RCC_AHB1LPENR_GPIOILPEN_Msk         
#define RCC_AHB1LPENR_CRCLPEN_Pos          (12U)                               
#define RCC_AHB1LPENR_CRCLPEN_Msk          (0x1UL << RCC_AHB1LPENR_CRCLPEN_Pos) 
#define RCC_AHB1LPENR_CRCLPEN              RCC_AHB1LPENR_CRCLPEN_Msk           
#define RCC_AHB1LPENR_FLITFLPEN_Pos        (15U)                               
#define RCC_AHB1LPENR_FLITFLPEN_Msk        (0x1UL << RCC_AHB1LPENR_FLITFLPEN_Pos) 
#define RCC_AHB1LPENR_FLITFLPEN            RCC_AHB1LPENR_FLITFLPEN_Msk         
#define RCC_AHB1LPENR_SRAM1LPEN_Pos        (16U)                               
#define RCC_AHB1LPENR_SRAM1LPEN_Msk        (0x1UL << RCC_AHB1LPENR_SRAM1LPEN_Pos) 
#define RCC_AHB1LPENR_SRAM1LPEN            RCC_AHB1LPENR_SRAM1LPEN_Msk         
#define RCC_AHB1LPENR_SRAM2LPEN_Pos        (17U)                               
#define RCC_AHB1LPENR_SRAM2LPEN_Msk        (0x1UL << RCC_AHB1LPENR_SRAM2LPEN_Pos) 
#define RCC_AHB1LPENR_SRAM2LPEN            RCC_AHB1LPENR_SRAM2LPEN_Msk         
#define RCC_AHB1LPENR_BKPSRAMLPEN_Pos      (18U)                               
#define RCC_AHB1LPENR_BKPSRAMLPEN_Msk      (0x1UL << RCC_AHB1LPENR_BKPSRAMLPEN_Pos) 
#define RCC_AHB1LPENR_BKPSRAMLPEN          RCC_AHB1LPENR_BKPSRAMLPEN_Msk       
#define RCC_AHB1LPENR_DMA1LPEN_Pos         (21U)                               
#define RCC_AHB1LPENR_DMA1LPEN_Msk         (0x1UL << RCC_AHB1LPENR_DMA1LPEN_Pos) 
#define RCC_AHB1LPENR_DMA1LPEN             RCC_AHB1LPENR_DMA1LPEN_Msk          
#define RCC_AHB1LPENR_DMA2LPEN_Pos         (22U)                               
#define RCC_AHB1LPENR_DMA2LPEN_Msk         (0x1UL << RCC_AHB1LPENR_DMA2LPEN_Pos) 
#define RCC_AHB1LPENR_DMA2LPEN             RCC_AHB1LPENR_DMA2LPEN_Msk          

#define RCC_AHB1LPENR_ETHMACLPEN_Pos       (25U)                               
#define RCC_AHB1LPENR_ETHMACLPEN_Msk       (0x1UL << RCC_AHB1LPENR_ETHMACLPEN_Pos) 
#define RCC_AHB1LPENR_ETHMACLPEN           RCC_AHB1LPENR_ETHMACLPEN_Msk        
#define RCC_AHB1LPENR_ETHMACTXLPEN_Pos     (26U)                               
#define RCC_AHB1LPENR_ETHMACTXLPEN_Msk     (0x1UL << RCC_AHB1LPENR_ETHMACTXLPEN_Pos) 
#define RCC_AHB1LPENR_ETHMACTXLPEN         RCC_AHB1LPENR_ETHMACTXLPEN_Msk      
#define RCC_AHB1LPENR_ETHMACRXLPEN_Pos     (27U)                               
#define RCC_AHB1LPENR_ETHMACRXLPEN_Msk     (0x1UL << RCC_AHB1LPENR_ETHMACRXLPEN_Pos) 
#define RCC_AHB1LPENR_ETHMACRXLPEN         RCC_AHB1LPENR_ETHMACRXLPEN_Msk      
#define RCC_AHB1LPENR_ETHMACPTPLPEN_Pos    (28U)                               
#define RCC_AHB1LPENR_ETHMACPTPLPEN_Msk    (0x1UL << RCC_AHB1LPENR_ETHMACPTPLPEN_Pos)
#define RCC_AHB1LPENR_ETHMACPTPLPEN        RCC_AHB1LPENR_ETHMACPTPLPEN_Msk     
#define RCC_AHB1LPENR_OTGHSLPEN_Pos        (29U)                               
#define RCC_AHB1LPENR_OTGHSLPEN_Msk        (0x1UL << RCC_AHB1LPENR_OTGHSLPEN_Pos)
#define RCC_AHB1LPENR_OTGHSLPEN            RCC_AHB1LPENR_OTGHSLPEN_Msk         
#define RCC_AHB1LPENR_OTGHSULPILPEN_Pos    (30U)                               
#define RCC_AHB1LPENR_OTGHSULPILPEN_Msk    (0x1UL << RCC_AHB1LPENR_OTGHSULPILPEN_Pos) 
#define RCC_AHB1LPENR_OTGHSULPILPEN        RCC_AHB1LPENR_OTGHSULPILPEN_Msk     

/********************  Bit definition for RCC_AHB2LPENR register  *************/
#define RCC_AHB2LPENR_DCMILPEN_Pos         (0U)                                
#define RCC_AHB2LPENR_DCMILPEN_Msk         (0x1UL << RCC_AHB2LPENR_DCMILPEN_Pos) 
#define RCC_AHB2LPENR_DCMILPEN             RCC_AHB2LPENR_DCMILPEN_Msk          
#define RCC_AHB2LPENR_RNGLPEN_Pos          (6U)                                
#define RCC_AHB2LPENR_RNGLPEN_Msk          (0x1UL << RCC_AHB2LPENR_RNGLPEN_Pos) 
#define RCC_AHB2LPENR_RNGLPEN              RCC_AHB2LPENR_RNGLPEN_Msk           
#define RCC_AHB2LPENR_OTGFSLPEN_Pos        (7U)                                
#define RCC_AHB2LPENR_OTGFSLPEN_Msk        (0x1UL << RCC_AHB2LPENR_OTGFSLPEN_Pos) 
#define RCC_AHB2LPENR_OTGFSLPEN            RCC_AHB2LPENR_OTGFSLPEN_Msk         

/********************  Bit definition for RCC_AHB3LPENR register  *************/
#define RCC_AHB3LPENR_FSMCLPEN_Pos         (0U)                                
#define RCC_AHB3LPENR_FSMCLPEN_Msk         (0x1UL << RCC_AHB3LPENR_FSMCLPEN_Pos) 
#define RCC_AHB3LPENR_FSMCLPEN             RCC_AHB3LPENR_FSMCLPEN_Msk          

/********************  Bit definition for RCC_APB1LPENR register  *************/
#define RCC_APB1LPENR_TIM2LPEN_Pos         (0U)                                
#define RCC_APB1LPENR_TIM2LPEN_Msk         (0x1UL << RCC_APB1LPENR_TIM2LPEN_Pos) 
#define RCC_APB1LPENR_TIM2LPEN             RCC_APB1LPENR_TIM2LPEN_Msk          
#define RCC_APB1LPENR_TIM3LPEN_Pos         (1U)                                
#define RCC_APB1LPENR_TIM3LPEN_Msk         (0x1UL << RCC_APB1LPENR_TIM3LPEN_Pos) 
#define RCC_APB1LPENR_TIM3LPEN             RCC_APB1LPENR_TIM3LPEN_Msk          
#define RCC_APB1LPENR_TIM4LPEN_Pos         (2U)                                
#define RCC_APB1LPENR_TIM4LPEN_Msk         (0x1UL << RCC_APB1LPENR_TIM4LPEN_Pos) 
#define RCC_APB1LPENR_TIM4LPEN             RCC_APB1LPENR_TIM4LPEN_Msk          
#define RCC_APB1LPENR_TIM5LPEN_Pos         (3U)                                
#define RCC_APB1LPENR_TIM5LPEN_Msk         (0x1UL << RCC_APB1LPENR_TIM5LPEN_Pos) 
#define RCC_APB1LPENR_TIM5LPEN             RCC_APB1LPENR_TIM5LPEN_Msk          
#define RCC_APB1LPENR_TIM6LPEN_Pos         (4U)                                
#define RCC_APB1LPENR_TIM6LPEN_Msk         (0x1UL << RCC_APB1LPENR_TIM6LPEN_Pos) 
#define RCC_APB1LPENR_TIM6LPEN             RCC_APB1LPENR_TIM6LPEN_Msk          
#define RCC_APB1LPENR_TIM7LPEN_Pos         (5U)                                
#define RCC_APB1LPENR_TIM7LPEN_Msk         (0x1UL << RCC_APB1LPENR_TIM7LPEN_Pos) 
#define RCC_APB1LPENR_TIM7LPEN             RCC_APB1LPENR_TIM7LPEN_Msk          
#define RCC_APB1LPENR_TIM12LPEN_Pos        (6U)                                
#define RCC_APB1LPENR_TIM12LPEN_Msk        (0x1UL << RCC_APB1LPENR_TIM12LPEN_Pos)
#define RCC_APB1LPENR_TIM12LPEN            RCC_APB1LPENR_TIM12LPEN_Msk         
#define RCC_APB1LPENR_TIM13LPEN_Pos        (7U)                                
#define RCC_APB1LPENR_TIM13LPEN_Msk        (0x1UL << RCC_APB1LPENR_TIM13LPEN_Pos)
#define RCC_APB1LPENR_TIM13LPEN            RCC_APB1LPENR_TIM13LPEN_Msk         
#define RCC_APB1LPENR_TIM14LPEN_Pos        (8U)                                
#define RCC_APB1LPENR_TIM14LPEN_Msk        (0x1UL << RCC_APB1LPENR_TIM14LPEN_Pos)
#define RCC_APB1LPENR_TIM14LPEN            RCC_APB1LPENR_TIM14LPEN_Msk         
#define RCC_APB1LPENR_WWDGLPEN_Pos         (11U)                               
#define RCC_APB1LPENR_WWDGLPEN_Msk         (0x1UL << RCC_APB1LPENR_WWDGLPEN_Pos) 
#define RCC_APB1LPENR_WWDGLPEN             RCC_APB1LPENR_WWDGLPEN_Msk          
#define RCC_APB1LPENR_SPI2LPEN_Pos         (14U)                               
#define RCC_APB1LPENR_SPI2LPEN_Msk         (0x1UL << RCC_APB1LPENR_SPI2LPEN_Pos) 
#define RCC_APB1LPENR_SPI2LPEN             RCC_APB1LPENR_SPI2LPEN_Msk          
#define RCC_APB1LPENR_SPI3LPEN_Pos         (15U)                               
#define RCC_APB1LPENR_SPI3LPEN_Msk         (0x1UL << RCC_APB1LPENR_SPI3LPEN_Pos) 
#define RCC_APB1LPENR_SPI3LPEN             RCC_APB1LPENR_SPI3LPEN_Msk          
#define RCC_APB1LPENR_USART2LPEN_Pos       (17U)                               
#define RCC_APB1LPENR_USART2LPEN_Msk       (0x1UL << RCC_APB1LPENR_USART2LPEN_Pos) 
#define RCC_APB1LPENR_USART2LPEN           RCC_APB1LPENR_USART2LPEN_Msk        
#define RCC_APB1LPENR_USART3LPEN_Pos       (18U)                               
#define RCC_APB1LPENR_USART3LPEN_Msk       (0x1UL << RCC_APB1LPENR_USART3LPEN_Pos) 
#define RCC_APB1LPENR_USART3LPEN           RCC_APB1LPENR_USART3LPEN_Msk        
#define RCC_APB1LPENR_UART4LPEN_Pos        (19U)                               
#define RCC_APB1LPENR_UART4LPEN_Msk        (0x1UL << RCC_APB1LPENR_UART4LPEN_Pos) 
#define RCC_APB1LPENR_UART4LPEN            RCC_APB1LPENR_UART4LPEN_Msk         
#define RCC_APB1LPENR_UART5LPEN_Pos        (20U)                               
#define RCC_APB1LPENR_UART5LPEN_Msk        (0x1UL << RCC_APB1LPENR_UART5LPEN_Pos)
#define RCC_APB1LPENR_UART5LPEN            RCC_APB1LPENR_UART5LPEN_Msk         
#define RCC_APB1LPENR_I2C1LPEN_Pos         (21U)                               
#define RCC_APB1LPENR_I2C1LPEN_Msk         (0x1UL << RCC_APB1LPENR_I2C1LPEN_Pos) 
#define RCC_APB1LPENR_I2C1LPEN             RCC_APB1LPENR_I2C1LPEN_Msk          
#define RCC_APB1LPENR_I2C2LPEN_Pos         (22U)                               
#define RCC_APB1LPENR_I2C2LPEN_Msk         (0x1UL << RCC_APB1LPENR_I2C2LPEN_Pos) 
#define RCC_APB1LPENR_I2C2LPEN             RCC_APB1LPENR_I2C2LPEN_Msk          
#define RCC_APB1LPENR_I2C3LPEN_Pos         (23U)                               
#define RCC_APB1LPENR_I2C3LPEN_Msk         (0x1UL << RCC_APB1LPENR_I2C3LPEN_Pos) 
#define RCC_APB1LPENR_I2C3LPEN             RCC_APB1LPENR_I2C3LPEN_Msk          
#define RCC_APB1LPENR_CAN1LPEN_Pos         (25U)                               
#define RCC_APB1LPENR_CAN1LPEN_Msk         (0x1UL << RCC_APB1LPENR_CAN1LPEN_Pos) 
#define RCC_APB1LPENR_CAN1LPEN             RCC_APB1LPENR_CAN1LPEN_Msk          
#define RCC_APB1LPENR_CAN2LPEN_Pos         (26U)                               
#define RCC_APB1LPENR_CAN2LPEN_Msk         (0x1UL << RCC_APB1LPENR_CAN2LPEN_Pos) 
#define RCC_APB1LPENR_CAN2LPEN             RCC_APB1LPENR_CAN2LPEN_Msk          
#define RCC_APB1LPENR_PWRLPEN_Pos          (28U)                               
#define RCC_APB1LPENR_PWRLPEN_Msk          (0x1UL << RCC_APB1LPENR_PWRLPEN_Pos) 
#define RCC_APB1LPENR_PWRLPEN              RCC_APB1LPENR_PWRLPEN_Msk           
#define RCC_APB1LPENR_DACLPEN_Pos          (29U)                               
#define RCC_APB1LPENR_DACLPEN_Msk          (0x1UL << RCC_APB1LPENR_DACLPEN_Pos) 
#define RCC_APB1LPENR_DACLPEN              RCC_APB1LPENR_DACLPEN_Msk           

/********************  Bit definition for RCC_APB2LPENR register  *************/
#define RCC_APB2LPENR_TIM1LPEN_Pos         (0U)                                
#define RCC_APB2LPENR_TIM1LPEN_Msk         (0x1UL << RCC_APB2LPENR_TIM1LPEN_Pos) 
#define RCC_APB2LPENR_TIM1LPEN             RCC_APB2LPENR_TIM1LPEN_Msk          
#define RCC_APB2LPENR_TIM8LPEN_Pos         (1U)                                
#define RCC_APB2LPENR_TIM8LPEN_Msk         (0x1UL << RCC_APB2LPENR_TIM8LPEN_Pos) 
#define RCC_APB2LPENR_TIM8LPEN             RCC_APB2LPENR_TIM8LPEN_Msk          
#define RCC_APB2LPENR_USART1LPEN_Pos       (4U)                                
#define RCC_APB2LPENR_USART1LPEN_Msk       (0x1UL << RCC_APB2LPENR_USART1LPEN_Pos) 
#define RCC_APB2LPENR_USART1LPEN           RCC_APB2LPENR_USART1LPEN_Msk        
#define RCC_APB2LPENR_USART6LPEN_Pos       (5U)                                
#define RCC_APB2LPENR_USART6LPEN_Msk       (0x1UL << RCC_APB2LPENR_USART6LPEN_Pos) 
#define RCC_APB2LPENR_USART6LPEN           RCC_APB2LPENR_USART6LPEN_Msk        
#define RCC_APB2LPENR_ADC1LPEN_Pos         (8U)                                
#define RCC_APB2LPENR_ADC1LPEN_Msk         (0x1UL << RCC_APB2LPENR_ADC1LPEN_Pos) 
#define RCC_APB2LPENR_ADC1LPEN             RCC_APB2LPENR_ADC1LPEN_Msk          
#define RCC_APB2LPENR_ADC2LPEN_Pos         (9U)                                
#define RCC_APB2LPENR_ADC2LPEN_Msk         (0x1UL << RCC_APB2LPENR_ADC2LPEN_Pos) 
#define RCC_APB2LPENR_ADC2LPEN             RCC_APB2LPENR_ADC2LPEN_Msk          
#define RCC_APB2LPENR_ADC3LPEN_Pos         (10U)                               
#define RCC_APB2LPENR_ADC3LPEN_Msk         (0x1UL << RCC_APB2LPENR_ADC3LPEN_Pos) 
#define RCC_APB2LPENR_ADC3LPEN             RCC_APB2LPENR_ADC3LPEN_Msk          
#define RCC_APB2LPENR_SDIOLPEN_Pos         (11U)                               
#define RCC_APB2LPENR_SDIOLPEN_Msk         (0x1UL << RCC_APB2LPENR_SDIOLPEN_Pos) 
#define RCC_APB2LPENR_SDIOLPEN             RCC_APB2LPENR_SDIOLPEN_Msk          
#define RCC_APB2LPENR_SPI1LPEN_Pos         (12U)                               
#define RCC_APB2LPENR_SPI1LPEN_Msk         (0x1UL << RCC_APB2LPENR_SPI1LPEN_Pos) 
#define RCC_APB2LPENR_SPI1LPEN             RCC_APB2LPENR_SPI1LPEN_Msk          
#define RCC_APB2LPENR_SYSCFGLPEN_Pos       (14U)                               
#define RCC_APB2LPENR_SYSCFGLPEN_Msk       (0x1UL << RCC_APB2LPENR_SYSCFGLPEN_Pos) 
#define RCC_APB2LPENR_SYSCFGLPEN           RCC_APB2LPENR_SYSCFGLPEN_Msk        
#define RCC_APB2LPENR_TIM9LPEN_Pos         (16U)                               
#define RCC_APB2LPENR_TIM9LPEN_Msk         (0x1UL << RCC_APB2LPENR_TIM9LPEN_Pos) 
#define RCC_APB2LPENR_TIM9LPEN             RCC_APB2LPENR_TIM9LPEN_Msk          
#define RCC_APB2LPENR_TIM10LPEN_Pos        (17U)                               
#define RCC_APB2LPENR_TIM10LPEN_Msk        (0x1UL << RCC_APB2LPENR_TIM10LPEN_Pos) 
#define RCC_APB2LPENR_TIM10LPEN            RCC_APB2LPENR_TIM10LPEN_Msk         
#define RCC_APB2LPENR_TIM11LPEN_Pos        (18U)                               
#define RCC_APB2LPENR_TIM11LPEN_Msk        (0x1UL << RCC_APB2LPENR_TIM11LPEN_Pos) 
#define RCC_APB2LPENR_TIM11LPEN            RCC_APB2LPENR_TIM11LPEN_Msk         

/********************  Bit definition for RCC_BDCR register  ******************/
#define RCC_BDCR_LSEON_Pos                 (0U)                                
#define RCC_BDCR_LSEON_Msk                 (0x1UL << RCC_BDCR_LSEON_Pos)        
#define RCC_BDCR_LSEON                     RCC_BDCR_LSEON_Msk                  
#define RCC_BDCR_LSERDY_Pos                (1U)                                
#define RCC_BDCR_LSERDY_Msk                (0x1UL << RCC_BDCR_LSERDY_Pos)       
#define RCC_BDCR_LSERDY                    RCC_BDCR_LSERDY_Msk                 
#define RCC_BDCR_LSEBYP_Pos                (2U)                                
#define RCC_BDCR_LSEBYP_Msk                (0x1UL << RCC_BDCR_LSEBYP_Pos)       
#define RCC_BDCR_LSEBYP                    RCC_BDCR_LSEBYP_Msk                 

#define RCC_BDCR_RTCSEL_Pos                (8U)                                
#define RCC_BDCR_RTCSEL_Msk                (0x3UL << RCC_BDCR_RTCSEL_Pos)       
#define RCC_BDCR_RTCSEL                    RCC_BDCR_RTCSEL_Msk                 
#define RCC_BDCR_RTCSEL_0                  (0x1UL << RCC_BDCR_RTCSEL_Pos)       
#define RCC_BDCR_RTCSEL_1                  (0x2UL << RCC_BDCR_RTCSEL_Pos)       

#define RCC_BDCR_RTCEN_Pos                 (15U)                               
#define RCC_BDCR_RTCEN_Msk                 (0x1UL << RCC_BDCR_RTCEN_Pos)        
#define RCC_BDCR_RTCEN                     RCC_BDCR_RTCEN_Msk                  
#define RCC_BDCR_BDRST_Pos                 (16U)                               
#define RCC_BDCR_BDRST_Msk                 (0x1UL << RCC_BDCR_BDRST_Pos)        
#define RCC_BDCR_BDRST                     RCC_BDCR_BDRST_Msk                  

/********************  Bit definition for RCC_CSR register  *******************/
#define RCC_CSR_LSION_Pos                  (0U)                                
#define RCC_CSR_LSION_Msk                  (0x1UL << RCC_CSR_LSION_Pos)        
#define RCC_CSR_LSION                      RCC_CSR_LSION_Msk                  
#define RCC_CSR_LSIRDY_Pos                 (1U)                               
#define RCC_CSR_LSIRDY_Msk                 (0x1UL << RCC_CSR_LSIRDY_Pos)       
#define RCC_CSR_LSIRDY                     RCC_CSR_LSIRDY_Msk                 
#define RCC_CSR_RMVF_Pos                   (24U)                              
#define RCC_CSR_RMVF_Msk                   (0x1UL << RCC_CSR_RMVF_Pos)         
#define RCC_CSR_RMVF                       RCC_CSR_RMVF_Msk                   
#define RCC_CSR_BORRSTF_Pos                (25U)                              
#define RCC_CSR_BORRSTF_Msk                (0x1UL << RCC_CSR_BORRSTF_Pos)      
#define RCC_CSR_BORRSTF                    RCC_CSR_BORRSTF_Msk                
#define RCC_CSR_PINRSTF_Pos                (26U)
#define RCC_CSR_PINRSTF_Msk                (0x1UL << RCC_CSR_PINRSTF_Pos)      
#define RCC_CSR_PINRSTF                    RCC_CSR_PINRSTF_Msk
#define RCC_CSR_PORRSTF_Pos                (27U)                              
#define RCC_CSR_PORRSTF_Msk                (0x1UL << RCC_CSR_PORRSTF_Pos)      
#define RCC_CSR_PORRSTF                    RCC_CSR_PORRSTF_Msk                
#define RCC_CSR_SFTRSTF_Pos                (28U)                              
#define RCC_CSR_SFTRSTF_Msk                (0x1UL << RCC_CSR_SFTRSTF_Pos)      
#define RCC_CSR_SFTRSTF                    RCC_CSR_SFTRSTF_Msk                
#define RCC_CSR_IWDGRSTF_Pos               (29U)
#define RCC_CSR_IWDGRSTF_Msk               (0x1UL << RCC_CSR_IWDGRSTF_Pos)     
#define RCC_CSR_IWDGRSTF                   RCC_CSR_IWDGRSTF_Msk
#define RCC_CSR_WWDGRSTF_Pos               (30U)                              
#define RCC_CSR_WWDGRSTF_Msk               (0x1UL << RCC_CSR_WWDGRSTF_Pos)     
#define RCC_CSR_WWDGRSTF                   RCC_CSR_WWDGRSTF_Msk               
#define RCC_CSR_LPWRRSTF_Pos               (31U)                              
#define RCC_CSR_LPWRRSTF_Msk               (0x1UL << RCC_CSR_LPWRRSTF_Pos)     
#define RCC_CSR_LPWRRSTF                   RCC_CSR_LPWRRSTF_Msk

/********************  Bit definition for RCC_SSCGR register  *****************/
#define RCC_SSCGR_MODPER_Pos               (0U)                                
#define RCC_SSCGR_MODPER_Msk               (0x1FFFUL << RCC_SSCGR_MODPER_Pos)  
#define RCC_SSCGR_MODPER                   RCC_SSCGR_MODPER_Msk               
#define RCC_SSCGR_INCSTEP_Pos              (13U)                              
#define RCC_SSCGR_INCSTEP_Msk              (0x7FFFUL << RCC_SSCGR_INCSTEP_Pos) 
#define RCC_SSCGR_INCSTEP                  RCC_SSCGR_INCSTEP_Msk              
#define RCC_SSCGR_SPREADSEL_Pos            (30U)                              
#define RCC_SSCGR_SPREADSEL_Msk            (0x1UL << RCC_SSCGR_SPREADSEL_Pos)  
#define RCC_SSCGR_SPREADSEL                RCC_SSCGR_SPREADSEL_Msk            
#define RCC_SSCGR_SSCGEN_Pos               (31U)                              
#define RCC_SSCGR_SSCGEN_Msk               (0x1UL << RCC_SSCGR_SSCGEN_Pos)     
#define RCC_SSCGR_SSCGEN                   RCC_SSCGR_SSCGEN_Msk               

/********************  Bit definition for RCC_PLLI2SCFGR register  ************/
#define RCC_PLLI2SCFGR_PLLI2SN_Pos         (6U)                                
#define RCC_PLLI2SCFGR_PLLI2SN_Msk         (0x1FFUL << RCC_PLLI2SCFGR_PLLI2SN_Pos) 
#define RCC_PLLI2SCFGR_PLLI2SN             RCC_PLLI2SCFGR_PLLI2SN_Msk          
#define RCC_PLLI2SCFGR_PLLI2SN_0           (0x001UL << RCC_PLLI2SCFGR_PLLI2SN_Pos) 
#define RCC_PLLI2SCFGR_PLLI2SN_1           (0x002UL << RCC_PLLI2SCFGR_PLLI2SN_Pos) 
#define RCC_PLLI2SCFGR_PLLI2SN_2           (0x004UL << RCC_PLLI2SCFGR_PLLI2SN_Pos) 
#define RCC_PLLI2SCFGR_PLLI2SN_3           (0x008UL << RCC_PLLI2SCFGR_PLLI2SN_Pos) 
#define RCC_PLLI2SCFGR_PLLI2SN_4           (0x010UL << RCC_PLLI2SCFGR_PLLI2SN_Pos) 
#define RCC_PLLI2SCFGR_PLLI2SN_5           (0x020UL << RCC_PLLI2SCFGR_PLLI2SN_Pos) 
#define RCC_PLLI2SCFGR_PLLI2SN_6           (0x040UL << RCC_PLLI2SCFGR_PLLI2SN_Pos) 
#define RCC_PLLI2SCFGR_PLLI2SN_7           (0x080UL << RCC_PLLI2SCFGR_PLLI2SN_Pos) 
#define RCC_PLLI2SCFGR_PLLI2SN_8           (0x100UL << RCC_PLLI2SCFGR_PLLI2SN_Pos) 

#define RCC_PLLI2SCFGR_PLLI2SR_Pos         (28U)                               
#define RCC_PLLI2SCFGR_PLLI2SR_Msk         (0x7UL << RCC_PLLI2SCFGR_PLLI2SR_Pos) 
#define RCC_PLLI2SCFGR_PLLI2SR             RCC_PLLI2SCFGR_PLLI2SR_Msk          
#define RCC_PLLI2SCFGR_PLLI2SR_0           (0x1UL << RCC_PLLI2SCFGR_PLLI2SR_Pos) 
#define RCC_PLLI2SCFGR_PLLI2SR_1           (0x2UL << RCC_PLLI2SCFGR_PLLI2SR_Pos) 
#define RCC_PLLI2SCFGR_PLLI2SR_2           (0x4UL << RCC_PLLI2SCFGR_PLLI2SR_Pos) 


#endif  /* HEADER_MCU_H_ */
