#if !defined(HEADER_SYSTEM_H_)  
#define HEADER_SYSTEM_H_

#include "Header.h"

/*Define register for EXIT*/
typedef struct
{
	__IO uint32_t IMR;	 /* Interrupt mask register (EXTI_IMR)        	   */
	__IO uint32_t EMR;	 /* Event mask register (EXTI_EMR)                 */
	__IO uint32_t RTSR;	 /* Rising trigger selection register (EXTI_RTSR)	 */
	__IO uint32_t FTSR;	 /* Falling trigger selection register (EXTI_FTSR) */
	__IO uint32_t SWIER; /* Software interrupt event register (EXTI_SWIER) */
	__IO uint32_t PR;	   /* Pending register (EXTI_PR)                   	 */

} EXTI_RegDef_t;
#define EXTI ((EXTI_RegDef_t *)EXTI_BASEADDR)

/*Define register for  SYSCFG*/
typedef struct
{
	__IO uint32_t MEMRMP;	   /* SYSCFG memory remap register (SYSCFG_MEMRMP)                    */
	__IO uint32_t PMC;		   /* SYSCFG peripheral mode configuration register     		          */
	__IO uint32_t EXTICR[4]; /* SYSCFG external interrupt configuration register 1, 2,  3, 4 	  */
	uint32_t RESERVED1[2];	 /* Reserved, 0x18-0x1C    	                                        */
	__IO uint32_t CMPCR;	   /* Compensation cell control register (SYSCFG_CMPCR)               */
	uint32_t RESERVED2[2];	 /* Reserved, 0x24-0x28 	                                          */
	__IO uint32_t CFGR;		   /*                                                              	  */
} SYSCFG_RegDef_t;
#define SYSCFG ((SYSCFG_RegDef_t *)SYSCFG_BASEADDR)


/******************  Bits definition for EXTI_IMR register  ***************/
#define EXTI_IMR_MR0_Pos          (0U)                                         
#define EXTI_IMR_MR0_Msk          (0x1UL << EXTI_IMR_MR0_Pos)                 
#define EXTI_IMR_MR0              EXTI_IMR_MR0_Msk                            
#define EXTI_IMR_MR1_Pos          (1U)                                        
#define EXTI_IMR_MR1_Msk          (0x1UL << EXTI_IMR_MR1_Pos)                 
#define EXTI_IMR_MR1              EXTI_IMR_MR1_Msk                            
#define EXTI_IMR_MR2_Pos          (2U)                                        
#define EXTI_IMR_MR2_Msk          (0x1UL << EXTI_IMR_MR2_Pos)                 
#define EXTI_IMR_MR2              EXTI_IMR_MR2_Msk                            
#define EXTI_IMR_MR3_Pos          (3U)                                        
#define EXTI_IMR_MR3_Msk          (0x1UL << EXTI_IMR_MR3_Pos)                 
#define EXTI_IMR_MR3              EXTI_IMR_MR3_Msk                            
#define EXTI_IMR_MR4_Pos          (4U)                                        
#define EXTI_IMR_MR4_Msk          (0x1UL << EXTI_IMR_MR4_Pos)                 
#define EXTI_IMR_MR4              EXTI_IMR_MR4_Msk                            
#define EXTI_IMR_MR5_Pos          (5U)                                        
#define EXTI_IMR_MR5_Msk          (0x1UL << EXTI_IMR_MR5_Pos)                 
#define EXTI_IMR_MR5              EXTI_IMR_MR5_Msk                            
#define EXTI_IMR_MR6_Pos          (6U)                                        
#define EXTI_IMR_MR6_Msk          (0x1UL << EXTI_IMR_MR6_Pos)                 
#define EXTI_IMR_MR6              EXTI_IMR_MR6_Msk                            
#define EXTI_IMR_MR7_Pos          (7U)                                        
#define EXTI_IMR_MR7_Msk          (0x1UL << EXTI_IMR_MR7_Pos)                 
#define EXTI_IMR_MR7              EXTI_IMR_MR7_Msk                            
#define EXTI_IMR_MR8_Pos          (8U)                                        
#define EXTI_IMR_MR8_Msk          (0x1UL << EXTI_IMR_MR8_Pos)                 
#define EXTI_IMR_MR8              EXTI_IMR_MR8_Msk                            
#define EXTI_IMR_MR9_Pos          (9U)                                        
#define EXTI_IMR_MR9_Msk          (0x1UL << EXTI_IMR_MR9_Pos)                 
#define EXTI_IMR_MR9              EXTI_IMR_MR9_Msk                            
#define EXTI_IMR_MR10_Pos         (10U)                                       
#define EXTI_IMR_MR10_Msk         (0x1UL << EXTI_IMR_MR10_Pos)                
#define EXTI_IMR_MR10             EXTI_IMR_MR10_Msk                           
#define EXTI_IMR_MR11_Pos         (11U)                                        
#define EXTI_IMR_MR11_Msk         (0x1UL << EXTI_IMR_MR11_Pos)               
#define EXTI_IMR_MR11             EXTI_IMR_MR11_Msk                          
#define EXTI_IMR_MR12_Pos         (12U)                                      
#define EXTI_IMR_MR12_Msk         (0x1UL << EXTI_IMR_MR12_Pos)               
#define EXTI_IMR_MR12             EXTI_IMR_MR12_Msk                          
#define EXTI_IMR_MR13_Pos         (13U)                                      
#define EXTI_IMR_MR13_Msk         (0x1UL << EXTI_IMR_MR13_Pos)               
#define EXTI_IMR_MR13             EXTI_IMR_MR13_Msk                          
#define EXTI_IMR_MR14_Pos         (14U)                                      
#define EXTI_IMR_MR14_Msk         (0x1UL << EXTI_IMR_MR14_Pos)               
#define EXTI_IMR_MR14             EXTI_IMR_MR14_Msk                          
#define EXTI_IMR_MR15_Pos         (15U)                                      
#define EXTI_IMR_MR15_Msk         (0x1UL << EXTI_IMR_MR15_Pos)               
#define EXTI_IMR_MR15             EXTI_IMR_MR15_Msk                          
#define EXTI_IMR_MR16_Pos         (16U)                                      
#define EXTI_IMR_MR16_Msk         (0x1UL << EXTI_IMR_MR16_Pos)               
#define EXTI_IMR_MR16             EXTI_IMR_MR16_Msk                          
#define EXTI_IMR_MR17_Pos         (17U)                                      
#define EXTI_IMR_MR17_Msk         (0x1UL << EXTI_IMR_MR17_Pos)               
#define EXTI_IMR_MR17             EXTI_IMR_MR17_Msk                          
#define EXTI_IMR_MR18_Pos         (18U)                                      
#define EXTI_IMR_MR18_Msk         (0x1UL << EXTI_IMR_MR18_Pos)               
#define EXTI_IMR_MR18             EXTI_IMR_MR18_Msk                          
#define EXTI_IMR_MR19_Pos         (19U)                                      
#define EXTI_IMR_MR19_Msk         (0x1UL << EXTI_IMR_MR19_Pos)               
#define EXTI_IMR_MR19             EXTI_IMR_MR19_Msk                          
#define EXTI_IMR_MR20_Pos         (20U)                                      
#define EXTI_IMR_MR20_Msk         (0x1UL << EXTI_IMR_MR20_Pos)               
#define EXTI_IMR_MR20             EXTI_IMR_MR20_Msk                          
#define EXTI_IMR_MR21_Pos         (21U)                                      
#define EXTI_IMR_MR21_Msk         (0x1UL << EXTI_IMR_MR21_Pos)               
#define EXTI_IMR_MR21             EXTI_IMR_MR21_Msk                          
#define EXTI_IMR_MR22_Pos         (22U)                                      
#define EXTI_IMR_MR22_Msk         (0x1UL << EXTI_IMR_MR22_Pos)               
#define EXTI_IMR_MR22             EXTI_IMR_MR22_Msk                          

/* Reference Defines */
#define  EXTI_IMR_IM0                        EXTI_IMR_MR0
#define  EXTI_IMR_IM1                        EXTI_IMR_MR1
#define  EXTI_IMR_IM2                        EXTI_IMR_MR2
#define  EXTI_IMR_IM3                        EXTI_IMR_MR3
#define  EXTI_IMR_IM4                        EXTI_IMR_MR4
#define  EXTI_IMR_IM5                        EXTI_IMR_MR5
#define  EXTI_IMR_IM6                        EXTI_IMR_MR6
#define  EXTI_IMR_IM7                        EXTI_IMR_MR7
#define  EXTI_IMR_IM8                        EXTI_IMR_MR8
#define  EXTI_IMR_IM9                        EXTI_IMR_MR9
#define  EXTI_IMR_IM10                       EXTI_IMR_MR10
#define  EXTI_IMR_IM11                       EXTI_IMR_MR11
#define  EXTI_IMR_IM12                       EXTI_IMR_MR12
#define  EXTI_IMR_IM13                       EXTI_IMR_MR13
#define  EXTI_IMR_IM14                       EXTI_IMR_MR14
#define  EXTI_IMR_IM15                       EXTI_IMR_MR15
#define  EXTI_IMR_IM16                       EXTI_IMR_MR16
#define  EXTI_IMR_IM17                       EXTI_IMR_MR17
#define  EXTI_IMR_IM18                       EXTI_IMR_MR18
#define  EXTI_IMR_IM19                       EXTI_IMR_MR19
#define  EXTI_IMR_IM20                       EXTI_IMR_MR20
#define  EXTI_IMR_IM21                       EXTI_IMR_MR21
#define  EXTI_IMR_IM22                       EXTI_IMR_MR22
#define EXTI_IMR_IM_Pos           (0U)                                         
#define EXTI_IMR_IM_Msk           (0x7FFFFFUL << EXTI_IMR_IM_Pos)             
#define EXTI_IMR_IM               EXTI_IMR_IM_Msk                             

/*******************  Bit definition for EXTI_EMR register  *******************/
#define EXTI_EMR_MR0_Pos          (0U)                                         
#define EXTI_EMR_MR0_Msk          (0x1UL << EXTI_EMR_MR0_Pos)                
#define EXTI_EMR_MR0              EXTI_EMR_MR0_Msk                           
#define EXTI_EMR_MR1_Pos          (1U)                                       
#define EXTI_EMR_MR1_Msk          (0x1UL << EXTI_EMR_MR1_Pos)                
#define EXTI_EMR_MR1              EXTI_EMR_MR1_Msk                           
#define EXTI_EMR_MR2_Pos          (2U)                                       
#define EXTI_EMR_MR2_Msk          (0x1UL << EXTI_EMR_MR2_Pos)                
#define EXTI_EMR_MR2              EXTI_EMR_MR2_Msk                           
#define EXTI_EMR_MR3_Pos          (3U)                                       
#define EXTI_EMR_MR3_Msk          (0x1UL << EXTI_EMR_MR3_Pos)                
#define EXTI_EMR_MR3              EXTI_EMR_MR3_Msk                           
#define EXTI_EMR_MR4_Pos          (4U)                                       
#define EXTI_EMR_MR4_Msk          (0x1UL << EXTI_EMR_MR4_Pos)                
#define EXTI_EMR_MR4              EXTI_EMR_MR4_Msk                           
#define EXTI_EMR_MR5_Pos          (5U)                                       
#define EXTI_EMR_MR5_Msk          (0x1UL << EXTI_EMR_MR5_Pos)                
#define EXTI_EMR_MR5              EXTI_EMR_MR5_Msk                           
#define EXTI_EMR_MR6_Pos          (6U)                                       
#define EXTI_EMR_MR6_Msk          (0x1UL << EXTI_EMR_MR6_Pos)                
#define EXTI_EMR_MR6              EXTI_EMR_MR6_Msk                           
#define EXTI_EMR_MR7_Pos          (7U)                                       
#define EXTI_EMR_MR7_Msk          (0x1UL << EXTI_EMR_MR7_Pos)               
#define EXTI_EMR_MR7              EXTI_EMR_MR7_Msk                          
#define EXTI_EMR_MR8_Pos          (8U)                                      
#define EXTI_EMR_MR8_Msk          (0x1UL << EXTI_EMR_MR8_Pos)               
#define EXTI_EMR_MR8              EXTI_EMR_MR8_Msk                          
#define EXTI_EMR_MR9_Pos          (9U)                                      
#define EXTI_EMR_MR9_Msk          (0x1UL << EXTI_EMR_MR9_Pos)               
#define EXTI_EMR_MR9              EXTI_EMR_MR9_Msk                          
#define EXTI_EMR_MR10_Pos         (10U)                                     
#define EXTI_EMR_MR10_Msk         (0x1UL << EXTI_EMR_MR10_Pos)              
#define EXTI_EMR_MR10             EXTI_EMR_MR10_Msk                         
#define EXTI_EMR_MR11_Pos         (11U)                                     
#define EXTI_EMR_MR11_Msk         (0x1UL << EXTI_EMR_MR11_Pos)              
#define EXTI_EMR_MR11             EXTI_EMR_MR11_Msk                         
#define EXTI_EMR_MR12_Pos         (12U)                                     
#define EXTI_EMR_MR12_Msk         (0x1UL << EXTI_EMR_MR12_Pos)              
#define EXTI_EMR_MR12             EXTI_EMR_MR12_Msk                         
#define EXTI_EMR_MR13_Pos         (13U)                                     
#define EXTI_EMR_MR13_Msk         (0x1UL << EXTI_EMR_MR13_Pos)              
#define EXTI_EMR_MR13             EXTI_EMR_MR13_Msk                         
#define EXTI_EMR_MR14_Pos         (14U)                                     
#define EXTI_EMR_MR14_Msk         (0x1UL << EXTI_EMR_MR14_Pos)              
#define EXTI_EMR_MR14             EXTI_EMR_MR14_Msk                         
#define EXTI_EMR_MR15_Pos         (15U)                                     
#define EXTI_EMR_MR15_Msk         (0x1UL << EXTI_EMR_MR15_Pos)              
#define EXTI_EMR_MR15             EXTI_EMR_MR15_Msk                         
#define EXTI_EMR_MR16_Pos         (16U)                                     
#define EXTI_EMR_MR16_Msk         (0x1UL << EXTI_EMR_MR16_Pos)              
#define EXTI_EMR_MR16             EXTI_EMR_MR16_Msk                         
#define EXTI_EMR_MR17_Pos         (17U)                                     
#define EXTI_EMR_MR17_Msk         (0x1UL << EXTI_EMR_MR17_Pos)              
#define EXTI_EMR_MR17             EXTI_EMR_MR17_Msk                         
#define EXTI_EMR_MR18_Pos         (18U)                                     
#define EXTI_EMR_MR18_Msk         (0x1UL << EXTI_EMR_MR18_Pos)              
#define EXTI_EMR_MR18             EXTI_EMR_MR18_Msk                         
#define EXTI_EMR_MR19_Pos         (19U)                                     
#define EXTI_EMR_MR19_Msk         (0x1UL << EXTI_EMR_MR19_Pos)              
#define EXTI_EMR_MR19             EXTI_EMR_MR19_Msk                         
#define EXTI_EMR_MR20_Pos         (20U)                                     
#define EXTI_EMR_MR20_Msk         (0x1UL << EXTI_EMR_MR20_Pos)              
#define EXTI_EMR_MR20             EXTI_EMR_MR20_Msk                         
#define EXTI_EMR_MR21_Pos         (21U)                                      
#define EXTI_EMR_MR21_Msk         (0x1UL << EXTI_EMR_MR21_Pos)               
#define EXTI_EMR_MR21             EXTI_EMR_MR21_Msk                          
#define EXTI_EMR_MR22_Pos         (22U)                                      
#define EXTI_EMR_MR22_Msk         (0x1UL << EXTI_EMR_MR22_Pos)               
#define EXTI_EMR_MR22             EXTI_EMR_MR22_Msk                          

/* Reference Defines */
#define  EXTI_EMR_EM0                        EXTI_EMR_MR0
#define  EXTI_EMR_EM1                        EXTI_EMR_MR1
#define  EXTI_EMR_EM2                        EXTI_EMR_MR2
#define  EXTI_EMR_EM3                        EXTI_EMR_MR3
#define  EXTI_EMR_EM4                        EXTI_EMR_MR4
#define  EXTI_EMR_EM5                        EXTI_EMR_MR5
#define  EXTI_EMR_EM6                        EXTI_EMR_MR6
#define  EXTI_EMR_EM7                        EXTI_EMR_MR7
#define  EXTI_EMR_EM8                        EXTI_EMR_MR8
#define  EXTI_EMR_EM9                        EXTI_EMR_MR9
#define  EXTI_EMR_EM10                       EXTI_EMR_MR10
#define  EXTI_EMR_EM11                       EXTI_EMR_MR11
#define  EXTI_EMR_EM12                       EXTI_EMR_MR12
#define  EXTI_EMR_EM13                       EXTI_EMR_MR13
#define  EXTI_EMR_EM14                       EXTI_EMR_MR14
#define  EXTI_EMR_EM15                       EXTI_EMR_MR15
#define  EXTI_EMR_EM16                       EXTI_EMR_MR16
#define  EXTI_EMR_EM17                       EXTI_EMR_MR17
#define  EXTI_EMR_EM18                       EXTI_EMR_MR18
#define  EXTI_EMR_EM19                       EXTI_EMR_MR19
#define  EXTI_EMR_EM20                       EXTI_EMR_MR20
#define  EXTI_EMR_EM21                       EXTI_EMR_MR21
#define  EXTI_EMR_EM22                       EXTI_EMR_MR22

/******************  Bit definition for EXTI_RTSR register  *******************/
#define EXTI_RTSR_TR0_Pos         (0U)                                         
#define EXTI_RTSR_TR0_Msk         (0x1UL << EXTI_RTSR_TR0_Pos)              
#define EXTI_RTSR_TR0             EXTI_RTSR_TR0_Msk                         
#define EXTI_RTSR_TR1_Pos         (1U)                                      
#define EXTI_RTSR_TR1_Msk         (0x1UL << EXTI_RTSR_TR1_Pos)              
#define EXTI_RTSR_TR1             EXTI_RTSR_TR1_Msk                         
#define EXTI_RTSR_TR2_Pos         (2U)                                      
#define EXTI_RTSR_TR2_Msk         (0x1UL << EXTI_RTSR_TR2_Pos)              
#define EXTI_RTSR_TR2             EXTI_RTSR_TR2_Msk                         
#define EXTI_RTSR_TR3_Pos         (3U)                                      
#define EXTI_RTSR_TR3_Msk         (0x1UL << EXTI_RTSR_TR3_Pos)              
#define EXTI_RTSR_TR3             EXTI_RTSR_TR3_Msk                         
#define EXTI_RTSR_TR4_Pos         (4U)                                      
#define EXTI_RTSR_TR4_Msk         (0x1UL << EXTI_RTSR_TR4_Pos)              
#define EXTI_RTSR_TR4             EXTI_RTSR_TR4_Msk                         
#define EXTI_RTSR_TR5_Pos         (5U)                                      
#define EXTI_RTSR_TR5_Msk         (0x1UL << EXTI_RTSR_TR5_Pos)              
#define EXTI_RTSR_TR5             EXTI_RTSR_TR5_Msk                         
#define EXTI_RTSR_TR6_Pos         (6U)                                      
#define EXTI_RTSR_TR6_Msk         (0x1UL << EXTI_RTSR_TR6_Pos)              
#define EXTI_RTSR_TR6             EXTI_RTSR_TR6_Msk                         
#define EXTI_RTSR_TR7_Pos         (7U)                                      
#define EXTI_RTSR_TR7_Msk         (0x1UL << EXTI_RTSR_TR7_Pos)              
#define EXTI_RTSR_TR7             EXTI_RTSR_TR7_Msk                         
#define EXTI_RTSR_TR8_Pos         (8U)                                      
#define EXTI_RTSR_TR8_Msk         (0x1UL << EXTI_RTSR_TR8_Pos)              
#define EXTI_RTSR_TR8             EXTI_RTSR_TR8_Msk                         
#define EXTI_RTSR_TR9_Pos         (9U)                                      
#define EXTI_RTSR_TR9_Msk         (0x1UL << EXTI_RTSR_TR9_Pos)              
#define EXTI_RTSR_TR9             EXTI_RTSR_TR9_Msk                         
#define EXTI_RTSR_TR10_Pos        (10U)                                     
#define EXTI_RTSR_TR10_Msk        (0x1UL << EXTI_RTSR_TR10_Pos)             
#define EXTI_RTSR_TR10            EXTI_RTSR_TR10_Msk                        
#define EXTI_RTSR_TR11_Pos        (11U)                                     
#define EXTI_RTSR_TR11_Msk        (0x1UL << EXTI_RTSR_TR11_Pos)             
#define EXTI_RTSR_TR11            EXTI_RTSR_TR11_Msk                        
#define EXTI_RTSR_TR12_Pos        (12U)                                     
#define EXTI_RTSR_TR12_Msk        (0x1UL << EXTI_RTSR_TR12_Pos)             
#define EXTI_RTSR_TR12            EXTI_RTSR_TR12_Msk                        
#define EXTI_RTSR_TR13_Pos        (13U)                                     
#define EXTI_RTSR_TR13_Msk        (0x1UL << EXTI_RTSR_TR13_Pos)             
#define EXTI_RTSR_TR13            EXTI_RTSR_TR13_Msk                        
#define EXTI_RTSR_TR14_Pos        (14U)                                     
#define EXTI_RTSR_TR14_Msk        (0x1UL << EXTI_RTSR_TR14_Pos)             
#define EXTI_RTSR_TR14            EXTI_RTSR_TR14_Msk                        
#define EXTI_RTSR_TR15_Pos        (15U)                                     
#define EXTI_RTSR_TR15_Msk        (0x1UL << EXTI_RTSR_TR15_Pos)             
#define EXTI_RTSR_TR15            EXTI_RTSR_TR15_Msk                        
#define EXTI_RTSR_TR16_Pos        (16U)                                     
#define EXTI_RTSR_TR16_Msk        (0x1UL << EXTI_RTSR_TR16_Pos)             
#define EXTI_RTSR_TR16            EXTI_RTSR_TR16_Msk                        
#define EXTI_RTSR_TR17_Pos        (17U)                                     
#define EXTI_RTSR_TR17_Msk        (0x1UL << EXTI_RTSR_TR17_Pos)             
#define EXTI_RTSR_TR17            EXTI_RTSR_TR17_Msk                        
#define EXTI_RTSR_TR18_Pos        (18U)                                     
#define EXTI_RTSR_TR18_Msk        (0x1UL << EXTI_RTSR_TR18_Pos)             
#define EXTI_RTSR_TR18            EXTI_RTSR_TR18_Msk                        
#define EXTI_RTSR_TR19_Pos        (19U)                                     
#define EXTI_RTSR_TR19_Msk        (0x1UL << EXTI_RTSR_TR19_Pos)             
#define EXTI_RTSR_TR19            EXTI_RTSR_TR19_Msk                        
#define EXTI_RTSR_TR20_Pos        (20U)                                     
#define EXTI_RTSR_TR20_Msk        (0x1UL << EXTI_RTSR_TR20_Pos)             
#define EXTI_RTSR_TR20            EXTI_RTSR_TR20_Msk                        
#define EXTI_RTSR_TR21_Pos        (21U)                                     
#define EXTI_RTSR_TR21_Msk        (0x1UL << EXTI_RTSR_TR21_Pos)             
#define EXTI_RTSR_TR21            EXTI_RTSR_TR21_Msk                        
#define EXTI_RTSR_TR22_Pos        (22U)                                     
#define EXTI_RTSR_TR22_Msk        (0x1UL << EXTI_RTSR_TR22_Pos)             
#define EXTI_RTSR_TR22            EXTI_RTSR_TR22_Msk                        

/******************  Bit definition for EXTI_FTSR register  ****************/
#define EXTI_FTSR_TR0_Pos         (0U)                                      
#define EXTI_FTSR_TR0_Msk         (0x1UL << EXTI_FTSR_TR0_Pos)              
#define EXTI_FTSR_TR0             EXTI_FTSR_TR0_Msk                         
#define EXTI_FTSR_TR1_Pos         (1U)                                      
#define EXTI_FTSR_TR1_Msk         (0x1UL << EXTI_FTSR_TR1_Pos)              
#define EXTI_FTSR_TR1             EXTI_FTSR_TR1_Msk                         
#define EXTI_FTSR_TR2_Pos         (2U)                                      
#define EXTI_FTSR_TR2_Msk         (0x1UL << EXTI_FTSR_TR2_Pos)              
#define EXTI_FTSR_TR2             EXTI_FTSR_TR2_Msk                         
#define EXTI_FTSR_TR3_Pos         (3U)                                      
#define EXTI_FTSR_TR3_Msk         (0x1UL << EXTI_FTSR_TR3_Pos)              
#define EXTI_FTSR_TR3             EXTI_FTSR_TR3_Msk                         
#define EXTI_FTSR_TR4_Pos         (4U)                                      
#define EXTI_FTSR_TR4_Msk         (0x1UL << EXTI_FTSR_TR4_Pos)              
#define EXTI_FTSR_TR4             EXTI_FTSR_TR4_Msk                         
#define EXTI_FTSR_TR5_Pos         (5U)                                      
#define EXTI_FTSR_TR5_Msk         (0x1UL << EXTI_FTSR_TR5_Pos)              
#define EXTI_FTSR_TR5             EXTI_FTSR_TR5_Msk                         
#define EXTI_FTSR_TR6_Pos         (6U)                                      
#define EXTI_FTSR_TR6_Msk         (0x1UL << EXTI_FTSR_TR6_Pos)              
#define EXTI_FTSR_TR6             EXTI_FTSR_TR6_Msk                         
#define EXTI_FTSR_TR7_Pos         (7U)                                      
#define EXTI_FTSR_TR7_Msk         (0x1UL << EXTI_FTSR_TR7_Pos)              
#define EXTI_FTSR_TR7             EXTI_FTSR_TR7_Msk                         
#define EXTI_FTSR_TR8_Pos         (8U)                                      
#define EXTI_FTSR_TR8_Msk         (0x1UL << EXTI_FTSR_TR8_Pos)              
#define EXTI_FTSR_TR8             EXTI_FTSR_TR8_Msk                         
#define EXTI_FTSR_TR9_Pos         (9U)                                      
#define EXTI_FTSR_TR9_Msk         (0x1UL << EXTI_FTSR_TR9_Pos)              
#define EXTI_FTSR_TR9             EXTI_FTSR_TR9_Msk                         
#define EXTI_FTSR_TR10_Pos        (10U)                                     
#define EXTI_FTSR_TR10_Msk        (0x1UL << EXTI_FTSR_TR10_Pos)             
#define EXTI_FTSR_TR10            EXTI_FTSR_TR10_Msk                        
#define EXTI_FTSR_TR11_Pos        (11U)                                     
#define EXTI_FTSR_TR11_Msk        (0x1UL << EXTI_FTSR_TR11_Pos)             
#define EXTI_FTSR_TR11            EXTI_FTSR_TR11_Msk                        
#define EXTI_FTSR_TR12_Pos        (12U)                                     
#define EXTI_FTSR_TR12_Msk        (0x1UL << EXTI_FTSR_TR12_Pos)             
#define EXTI_FTSR_TR12            EXTI_FTSR_TR12_Msk                        
#define EXTI_FTSR_TR13_Pos        (13U)                                     
#define EXTI_FTSR_TR13_Msk        (0x1UL << EXTI_FTSR_TR13_Pos)             
#define EXTI_FTSR_TR13            EXTI_FTSR_TR13_Msk                        
#define EXTI_FTSR_TR14_Pos        (14U)                                     
#define EXTI_FTSR_TR14_Msk        (0x1UL << EXTI_FTSR_TR14_Pos)             
#define EXTI_FTSR_TR14            EXTI_FTSR_TR14_Msk                        
#define EXTI_FTSR_TR15_Pos        (15U)                                     
#define EXTI_FTSR_TR15_Msk        (0x1UL << EXTI_FTSR_TR15_Pos)             
#define EXTI_FTSR_TR15            EXTI_FTSR_TR15_Msk                        
#define EXTI_FTSR_TR16_Pos        (16U)                                     
#define EXTI_FTSR_TR16_Msk        (0x1UL << EXTI_FTSR_TR16_Pos)             
#define EXTI_FTSR_TR16            EXTI_FTSR_TR16_Msk                        
#define EXTI_FTSR_TR17_Pos        (17U)                                     
#define EXTI_FTSR_TR17_Msk        (0x1UL << EXTI_FTSR_TR17_Pos)             
#define EXTI_FTSR_TR17            EXTI_FTSR_TR17_Msk                        
#define EXTI_FTSR_TR18_Pos        (18U)                                     
#define EXTI_FTSR_TR18_Msk        (0x1UL << EXTI_FTSR_TR18_Pos)             
#define EXTI_FTSR_TR18            EXTI_FTSR_TR18_Msk                        
#define EXTI_FTSR_TR19_Pos        (19U)                                     
#define EXTI_FTSR_TR19_Msk        (0x1UL << EXTI_FTSR_TR19_Pos)             
#define EXTI_FTSR_TR19            EXTI_FTSR_TR19_Msk                        
#define EXTI_FTSR_TR20_Pos        (20U)                                     
#define EXTI_FTSR_TR20_Msk        (0x1UL << EXTI_FTSR_TR20_Pos)             
#define EXTI_FTSR_TR20            EXTI_FTSR_TR20_Msk                        
#define EXTI_FTSR_TR21_Pos        (21U)                                     
#define EXTI_FTSR_TR21_Msk        (0x1UL << EXTI_FTSR_TR21_Pos)             
#define EXTI_FTSR_TR21            EXTI_FTSR_TR21_Msk                        
#define EXTI_FTSR_TR22_Pos        (22U)                                     
#define EXTI_FTSR_TR22_Msk        (0x1UL << EXTI_FTSR_TR22_Pos)             
#define EXTI_FTSR_TR22            EXTI_FTSR_TR22_Msk                        

/******************  Bit definition for EXTI_SWIER register  ***************/
#define EXTI_SWIER_SWIER0_Pos     (0U)                                      
#define EXTI_SWIER_SWIER0_Msk     (0x1UL << EXTI_SWIER_SWIER0_Pos)          
#define EXTI_SWIER_SWIER0         EXTI_SWIER_SWIER0_Msk                     
#define EXTI_SWIER_SWIER1_Pos     (1U)                                      
#define EXTI_SWIER_SWIER1_Msk     (0x1UL << EXTI_SWIER_SWIER1_Pos)          
#define EXTI_SWIER_SWIER1         EXTI_SWIER_SWIER1_Msk                     
#define EXTI_SWIER_SWIER2_Pos     (2U)                                      
#define EXTI_SWIER_SWIER2_Msk     (0x1UL << EXTI_SWIER_SWIER2_Pos)          
#define EXTI_SWIER_SWIER2         EXTI_SWIER_SWIER2_Msk                     
#define EXTI_SWIER_SWIER3_Pos     (3U)                                      
#define EXTI_SWIER_SWIER3_Msk     (0x1UL << EXTI_SWIER_SWIER3_Pos)          
#define EXTI_SWIER_SWIER3         EXTI_SWIER_SWIER3_Msk                     
#define EXTI_SWIER_SWIER4_Pos     (4U)                                      
#define EXTI_SWIER_SWIER4_Msk     (0x1UL << EXTI_SWIER_SWIER4_Pos)          
#define EXTI_SWIER_SWIER4         EXTI_SWIER_SWIER4_Msk                     
#define EXTI_SWIER_SWIER5_Pos     (5U)                                      
#define EXTI_SWIER_SWIER5_Msk     (0x1UL << EXTI_SWIER_SWIER5_Pos)          
#define EXTI_SWIER_SWIER5         EXTI_SWIER_SWIER5_Msk                     
#define EXTI_SWIER_SWIER6_Pos     (6U)                                      
#define EXTI_SWIER_SWIER6_Msk     (0x1UL << EXTI_SWIER_SWIER6_Pos)          
#define EXTI_SWIER_SWIER6         EXTI_SWIER_SWIER6_Msk                     
#define EXTI_SWIER_SWIER7_Pos     (7U)                                      
#define EXTI_SWIER_SWIER7_Msk     (0x1UL << EXTI_SWIER_SWIER7_Pos)          
#define EXTI_SWIER_SWIER7         EXTI_SWIER_SWIER7_Msk                     
#define EXTI_SWIER_SWIER8_Pos     (8U)                                      
#define EXTI_SWIER_SWIER8_Msk     (0x1UL << EXTI_SWIER_SWIER8_Pos)          
#define EXTI_SWIER_SWIER8         EXTI_SWIER_SWIER8_Msk                     
#define EXTI_SWIER_SWIER9_Pos     (9U)                                      
#define EXTI_SWIER_SWIER9_Msk     (0x1UL << EXTI_SWIER_SWIER9_Pos)          
#define EXTI_SWIER_SWIER9         EXTI_SWIER_SWIER9_Msk                     
#define EXTI_SWIER_SWIER10_Pos    (10U)                                     
#define EXTI_SWIER_SWIER10_Msk    (0x1UL << EXTI_SWIER_SWIER10_Pos)         
#define EXTI_SWIER_SWIER10        EXTI_SWIER_SWIER10_Msk                    
#define EXTI_SWIER_SWIER11_Pos    (11U)                                     
#define EXTI_SWIER_SWIER11_Msk    (0x1UL << EXTI_SWIER_SWIER11_Pos)         
#define EXTI_SWIER_SWIER11        EXTI_SWIER_SWIER11_Msk                    
#define EXTI_SWIER_SWIER12_Pos    (12U)                                     
#define EXTI_SWIER_SWIER12_Msk    (0x1UL << EXTI_SWIER_SWIER12_Pos)         
#define EXTI_SWIER_SWIER12        EXTI_SWIER_SWIER12_Msk                    
#define EXTI_SWIER_SWIER13_Pos    (13U)                                     
#define EXTI_SWIER_SWIER13_Msk    (0x1UL << EXTI_SWIER_SWIER13_Pos)         
#define EXTI_SWIER_SWIER13        EXTI_SWIER_SWIER13_Msk                    
#define EXTI_SWIER_SWIER14_Pos    (14U)                                     
#define EXTI_SWIER_SWIER14_Msk    (0x1UL << EXTI_SWIER_SWIER14_Pos)         
#define EXTI_SWIER_SWIER14        EXTI_SWIER_SWIER14_Msk                    
#define EXTI_SWIER_SWIER15_Pos    (15U)                                     
#define EXTI_SWIER_SWIER15_Msk    (0x1UL << EXTI_SWIER_SWIER15_Pos)         
#define EXTI_SWIER_SWIER15        EXTI_SWIER_SWIER15_Msk                    
#define EXTI_SWIER_SWIER16_Pos    (16U)                                     
#define EXTI_SWIER_SWIER16_Msk    (0x1UL << EXTI_SWIER_SWIER16_Pos)         
#define EXTI_SWIER_SWIER16        EXTI_SWIER_SWIER16_Msk                    
#define EXTI_SWIER_SWIER17_Pos    (17U)                                     
#define EXTI_SWIER_SWIER17_Msk    (0x1UL << EXTI_SWIER_SWIER17_Pos)         
#define EXTI_SWIER_SWIER17        EXTI_SWIER_SWIER17_Msk                    
#define EXTI_SWIER_SWIER18_Pos    (18U)                                     
#define EXTI_SWIER_SWIER18_Msk    (0x1UL << EXTI_SWIER_SWIER18_Pos)         
#define EXTI_SWIER_SWIER18        EXTI_SWIER_SWIER18_Msk                    
#define EXTI_SWIER_SWIER19_Pos    (19U)                                     
#define EXTI_SWIER_SWIER19_Msk    (0x1UL << EXTI_SWIER_SWIER19_Pos)         
#define EXTI_SWIER_SWIER19        EXTI_SWIER_SWIER19_Msk                    
#define EXTI_SWIER_SWIER20_Pos    (20U)                                     
#define EXTI_SWIER_SWIER20_Msk    (0x1UL << EXTI_SWIER_SWIER20_Pos)         
#define EXTI_SWIER_SWIER20        EXTI_SWIER_SWIER20_Msk                    
#define EXTI_SWIER_SWIER21_Pos    (21U)                                     
#define EXTI_SWIER_SWIER21_Msk    (0x1UL << EXTI_SWIER_SWIER21_Pos)         
#define EXTI_SWIER_SWIER21        EXTI_SWIER_SWIER21_Msk                    
#define EXTI_SWIER_SWIER22_Pos    (22U)                                     
#define EXTI_SWIER_SWIER22_Msk    (0x1UL << EXTI_SWIER_SWIER22_Pos)         
#define EXTI_SWIER_SWIER22        EXTI_SWIER_SWIER22_Msk                    

/*******************  Bit definition for EXTI_PR register  ********************/
#define EXTI_PR_PR0_Pos           (0U)                                         
#define EXTI_PR_PR0_Msk           (0x1UL << EXTI_PR_PR0_Pos)                 
#define EXTI_PR_PR0               EXTI_PR_PR0_Msk                            
#define EXTI_PR_PR1_Pos           (1U)                                       
#define EXTI_PR_PR1_Msk           (0x1UL << EXTI_PR_PR1_Pos)                 
#define EXTI_PR_PR1               EXTI_PR_PR1_Msk                            
#define EXTI_PR_PR2_Pos           (2U)                                       
#define EXTI_PR_PR2_Msk           (0x1UL << EXTI_PR_PR2_Pos)                 
#define EXTI_PR_PR2               EXTI_PR_PR2_Msk                            
#define EXTI_PR_PR3_Pos           (3U)                                       
#define EXTI_PR_PR3_Msk           (0x1UL << EXTI_PR_PR3_Pos)                 
#define EXTI_PR_PR3               EXTI_PR_PR3_Msk                            
#define EXTI_PR_PR4_Pos           (4U)                                       
#define EXTI_PR_PR4_Msk           (0x1UL << EXTI_PR_PR4_Pos)                 
#define EXTI_PR_PR4               EXTI_PR_PR4_Msk                            
#define EXTI_PR_PR5_Pos           (5U)                                       
#define EXTI_PR_PR5_Msk           (0x1UL << EXTI_PR_PR5_Pos)                 
#define EXTI_PR_PR5               EXTI_PR_PR5_Msk                            
#define EXTI_PR_PR6_Pos           (6U)                                       
#define EXTI_PR_PR6_Msk           (0x1UL << EXTI_PR_PR6_Pos)                 
#define EXTI_PR_PR6               EXTI_PR_PR6_Msk                            
#define EXTI_PR_PR7_Pos           (7U)                                       
#define EXTI_PR_PR7_Msk           (0x1UL << EXTI_PR_PR7_Pos)                 
#define EXTI_PR_PR7               EXTI_PR_PR7_Msk                            
#define EXTI_PR_PR8_Pos           (8U)                                       
#define EXTI_PR_PR8_Msk           (0x1UL << EXTI_PR_PR8_Pos)                 
#define EXTI_PR_PR8               EXTI_PR_PR8_Msk                            
#define EXTI_PR_PR9_Pos           (9U)                                       
#define EXTI_PR_PR9_Msk           (0x1UL << EXTI_PR_PR9_Pos)                 
#define EXTI_PR_PR9               EXTI_PR_PR9_Msk                            
#define EXTI_PR_PR10_Pos          (10U)                                      
#define EXTI_PR_PR10_Msk          (0x1UL << EXTI_PR_PR10_Pos)                
#define EXTI_PR_PR10              EXTI_PR_PR10_Msk                           
#define EXTI_PR_PR11_Pos          (11U)                                      
#define EXTI_PR_PR11_Msk          (0x1UL << EXTI_PR_PR11_Pos)                
#define EXTI_PR_PR11              EXTI_PR_PR11_Msk                           
#define EXTI_PR_PR12_Pos          (12U)                                      
#define EXTI_PR_PR12_Msk          (0x1UL << EXTI_PR_PR12_Pos)                
#define EXTI_PR_PR12              EXTI_PR_PR12_Msk                           
#define EXTI_PR_PR13_Pos          (13U)                                      
#define EXTI_PR_PR13_Msk          (0x1UL << EXTI_PR_PR13_Pos)                
#define EXTI_PR_PR13              EXTI_PR_PR13_Msk                           
#define EXTI_PR_PR14_Pos          (14U)                                      
#define EXTI_PR_PR14_Msk          (0x1UL << EXTI_PR_PR14_Pos)                
#define EXTI_PR_PR14              EXTI_PR_PR14_Msk                           
#define EXTI_PR_PR15_Pos          (15U)                                      
#define EXTI_PR_PR15_Msk          (0x1UL << EXTI_PR_PR15_Pos)                
#define EXTI_PR_PR15              EXTI_PR_PR15_Msk                           
#define EXTI_PR_PR16_Pos          (16U)                                      
#define EXTI_PR_PR16_Msk          (0x1UL << EXTI_PR_PR16_Pos)                
#define EXTI_PR_PR16              EXTI_PR_PR16_Msk                           
#define EXTI_PR_PR17_Pos          (17U)                                      
#define EXTI_PR_PR17_Msk          (0x1UL << EXTI_PR_PR17_Pos)                
#define EXTI_PR_PR17              EXTI_PR_PR17_Msk                           
#define EXTI_PR_PR18_Pos          (18U)                                      
#define EXTI_PR_PR18_Msk          (0x1UL << EXTI_PR_PR18_Pos)                
#define EXTI_PR_PR18              EXTI_PR_PR18_Msk                           
#define EXTI_PR_PR19_Pos          (19U)                                      
#define EXTI_PR_PR19_Msk          (0x1UL << EXTI_PR_PR19_Pos)                
#define EXTI_PR_PR19              EXTI_PR_PR19_Msk                           
#define EXTI_PR_PR20_Pos          (20U)                                      
#define EXTI_PR_PR20_Msk          (0x1UL << EXTI_PR_PR20_Pos)                
#define EXTI_PR_PR20              EXTI_PR_PR20_Msk                           
#define EXTI_PR_PR21_Pos          (21U)                                      
#define EXTI_PR_PR21_Msk          (0x1UL << EXTI_PR_PR21_Pos)                
#define EXTI_PR_PR21              EXTI_PR_PR21_Msk                           
#define EXTI_PR_PR22_Pos          (22U)                                      
#define EXTI_PR_PR22_Msk          (0x1UL << EXTI_PR_PR22_Pos)                
#define EXTI_PR_PR22              EXTI_PR_PR22_Msk  

/******************  Bit definition for SYSCFG_MEMRMP register  ***************/
#define SYSCFG_MEMRMP_MEM_MODE_Pos           (0U)                              
#define SYSCFG_MEMRMP_MEM_MODE_Msk           (0x3UL << SYSCFG_MEMRMP_MEM_MODE_Pos) 
#define SYSCFG_MEMRMP_MEM_MODE               SYSCFG_MEMRMP_MEM_MODE_Msk       
#define SYSCFG_MEMRMP_MEM_MODE_0             (0x1UL << SYSCFG_MEMRMP_MEM_MODE_Pos) 
#define SYSCFG_MEMRMP_MEM_MODE_1             (0x2UL << SYSCFG_MEMRMP_MEM_MODE_Pos) 
/******************  Bit definition for SYSCFG_PMC register  ******************/
#define SYSCFG_PMC_MII_RMII_SEL_Pos          (23U)                             
#define SYSCFG_PMC_MII_RMII_SEL_Msk          (0x1UL << SYSCFG_PMC_MII_RMII_SEL_Pos)
#define SYSCFG_PMC_MII_RMII_SEL              SYSCFG_PMC_MII_RMII_SEL_Msk      
/* Old MII_RMII_SEL bit definition, maintained for legacy purpose */
#define SYSCFG_PMC_MII_RMII             SYSCFG_PMC_MII_RMII_SEL    

/*****************  Bit definition for SYSCFG_EXTICR1 register  ***************/
#define SYSCFG_EXTICR1_EXTI0_Pos             (0U)                              
#define SYSCFG_EXTICR1_EXTI0_Msk             (0xFUL << SYSCFG_EXTICR1_EXTI0_Pos) 
#define SYSCFG_EXTICR1_EXTI0                 SYSCFG_EXTICR1_EXTI0_Msk         
#define SYSCFG_EXTICR1_EXTI1_Pos             (4U)                              
#define SYSCFG_EXTICR1_EXTI1_Msk             (0xFUL << SYSCFG_EXTICR1_EXTI1_Pos)
#define SYSCFG_EXTICR1_EXTI1                 SYSCFG_EXTICR1_EXTI1_Msk         
#define SYSCFG_EXTICR1_EXTI2_Pos             (8U)                              
#define SYSCFG_EXTICR1_EXTI2_Msk             (0xFUL << SYSCFG_EXTICR1_EXTI2_Pos) 
#define SYSCFG_EXTICR1_EXTI2                 SYSCFG_EXTICR1_EXTI2_Msk          
#define SYSCFG_EXTICR1_EXTI3_Pos             (12U)                             
#define SYSCFG_EXTICR1_EXTI3_Msk             (0xFUL << SYSCFG_EXTICR1_EXTI3_Pos) 
#define SYSCFG_EXTICR1_EXTI3                 SYSCFG_EXTICR1_EXTI3_Msk  
/**       
  *    EXTI0 configuration  
  */
#define SYSCFG_EXTICR1_EXTI0_PA              0x0000U                         
#define SYSCFG_EXTICR1_EXTI0_PB              0x0001U                         
#define SYSCFG_EXTICR1_EXTI0_PC              0x0002U                         
#define SYSCFG_EXTICR1_EXTI0_PD              0x0003U                         
#define SYSCFG_EXTICR1_EXTI0_PE              0x0004U                         
#define SYSCFG_EXTICR1_EXTI0_PF              0x0005U                         
#define SYSCFG_EXTICR1_EXTI0_PG              0x0006U                         
#define SYSCFG_EXTICR1_EXTI0_PH              0x0007U                         
#define SYSCFG_EXTICR1_EXTI0_PI              0x0008U                         

/**
  *    EXTI1 configuration  
  */
#define SYSCFG_EXTICR1_EXTI1_PA              0x0000U                         
#define SYSCFG_EXTICR1_EXTI1_PB              0x0010U                         
#define SYSCFG_EXTICR1_EXTI1_PC              0x0020U                         
#define SYSCFG_EXTICR1_EXTI1_PD              0x0030U                         
#define SYSCFG_EXTICR1_EXTI1_PE              0x0040U                         
#define SYSCFG_EXTICR1_EXTI1_PF              0x0050U                         
#define SYSCFG_EXTICR1_EXTI1_PG              0x0060U                         
#define SYSCFG_EXTICR1_EXTI1_PH              0x0070U                         
#define SYSCFG_EXTICR1_EXTI1_PI              0x0080U                         

/**
  *    EXTI2 configuration  
  */
#define SYSCFG_EXTICR1_EXTI2_PA              0x0000U                         
#define SYSCFG_EXTICR1_EXTI2_PB              0x0100U                         
#define SYSCFG_EXTICR1_EXTI2_PC              0x0200U                         
#define SYSCFG_EXTICR1_EXTI2_PD              0x0300U                         
#define SYSCFG_EXTICR1_EXTI2_PE              0x0400U                         
#define SYSCFG_EXTICR1_EXTI2_PF              0x0500U                         
#define SYSCFG_EXTICR1_EXTI2_PG              0x0600U                         
#define SYSCFG_EXTICR1_EXTI2_PH              0x0700U                         
#define SYSCFG_EXTICR1_EXTI2_PI              0x0800U                         

/**
  *    EXTI3 configuration  
  */
#define SYSCFG_EXTICR1_EXTI3_PA              0x0000U                         
#define SYSCFG_EXTICR1_EXTI3_PB              0x1000U                         
#define SYSCFG_EXTICR1_EXTI3_PC              0x2000U                          
#define SYSCFG_EXTICR1_EXTI3_PD              0x3000U                          
#define SYSCFG_EXTICR1_EXTI3_PE              0x4000U                          
#define SYSCFG_EXTICR1_EXTI3_PF              0x5000U                          
#define SYSCFG_EXTICR1_EXTI3_PG              0x6000U                          
#define SYSCFG_EXTICR1_EXTI3_PH              0x7000U                          
#define SYSCFG_EXTICR1_EXTI3_PI              0x8000U                          

/*****************  Bit definition for SYSCFG_EXTICR2 register  ***************/
#define SYSCFG_EXTICR2_EXTI4_Pos             (0U)                              
#define SYSCFG_EXTICR2_EXTI4_Msk             (0xFUL << SYSCFG_EXTICR2_EXTI4_Pos) 
#define SYSCFG_EXTICR2_EXTI4                 SYSCFG_EXTICR2_EXTI4_Msk          
#define SYSCFG_EXTICR2_EXTI5_Pos             (4U)                              
#define SYSCFG_EXTICR2_EXTI5_Msk             (0xFUL << SYSCFG_EXTICR2_EXTI5_Pos) 
#define SYSCFG_EXTICR2_EXTI5                 SYSCFG_EXTICR2_EXTI5_Msk          
#define SYSCFG_EXTICR2_EXTI6_Pos             (8U)                              
#define SYSCFG_EXTICR2_EXTI6_Msk             (0xFUL << SYSCFG_EXTICR2_EXTI6_Pos) 
#define SYSCFG_EXTICR2_EXTI6                 SYSCFG_EXTICR2_EXTI6_Msk          
#define SYSCFG_EXTICR2_EXTI7_Pos             (12U)                             
#define SYSCFG_EXTICR2_EXTI7_Msk             (0xFUL << SYSCFG_EXTICR2_EXTI7_Pos) 
#define SYSCFG_EXTICR2_EXTI7                 SYSCFG_EXTICR2_EXTI7_Msk          

/**
  *    EXTI4 configuration  
  */
#define SYSCFG_EXTICR2_EXTI4_PA              0x0000U                         
#define SYSCFG_EXTICR2_EXTI4_PB              0x0001U                         
#define SYSCFG_EXTICR2_EXTI4_PC              0x0002U                         
#define SYSCFG_EXTICR2_EXTI4_PD              0x0003U                         
#define SYSCFG_EXTICR2_EXTI4_PE              0x0004U                         
#define SYSCFG_EXTICR2_EXTI4_PF              0x0005U                         
#define SYSCFG_EXTICR2_EXTI4_PG              0x0006U                         
#define SYSCFG_EXTICR2_EXTI4_PH              0x0007U                         
#define SYSCFG_EXTICR2_EXTI4_PI              0x0008U                         

/**
  *    EXTI5 configuration  
  */
#define SYSCFG_EXTICR2_EXTI5_PA              0x0000U                         
#define SYSCFG_EXTICR2_EXTI5_PB              0x0010U                         
#define SYSCFG_EXTICR2_EXTI5_PC              0x0020U                         
#define SYSCFG_EXTICR2_EXTI5_PD              0x0030U                         
#define SYSCFG_EXTICR2_EXTI5_PE              0x0040U                         
#define SYSCFG_EXTICR2_EXTI5_PF              0x0050U                         
#define SYSCFG_EXTICR2_EXTI5_PG              0x0060U                         
#define SYSCFG_EXTICR2_EXTI5_PH              0x0070U                         
#define SYSCFG_EXTICR2_EXTI5_PI              0x0080U                         

/**
  *    EXTI6 configuration  
  */
#define SYSCFG_EXTICR2_EXTI6_PA              0x0000U                         
#define SYSCFG_EXTICR2_EXTI6_PB              0x0100U                         
#define SYSCFG_EXTICR2_EXTI6_PC              0x0200U                         
#define SYSCFG_EXTICR2_EXTI6_PD              0x0300U                         
#define SYSCFG_EXTICR2_EXTI6_PE              0x0400U                         
#define SYSCFG_EXTICR2_EXTI6_PF              0x0500U                         
#define SYSCFG_EXTICR2_EXTI6_PG              0x0600U                         
#define SYSCFG_EXTICR2_EXTI6_PH              0x0700U                         
#define SYSCFG_EXTICR2_EXTI6_PI              0x0800U                         

/**
  *    EXTI7 configuration  
  */
#define SYSCFG_EXTICR2_EXTI7_PA              0x0000U                       
#define SYSCFG_EXTICR2_EXTI7_PB              0x1000U                       
#define SYSCFG_EXTICR2_EXTI7_PC              0x2000U                       
#define SYSCFG_EXTICR2_EXTI7_PD              0x3000U                       
#define SYSCFG_EXTICR2_EXTI7_PE              0x4000U                       
#define SYSCFG_EXTICR2_EXTI7_PF              0x5000U                       
#define SYSCFG_EXTICR2_EXTI7_PG              0x6000U                       
#define SYSCFG_EXTICR2_EXTI7_PH              0x7000U                       
#define SYSCFG_EXTICR2_EXTI7_PI              0x8000U                       

/*****************  Bit definition for SYSCFG_EXTICR3 register  ***************/
#define SYSCFG_EXTICR3_EXTI8_Pos             (0U)                              
#define SYSCFG_EXTICR3_EXTI8_Msk             (0xFUL << SYSCFG_EXTICR3_EXTI8_Pos) 
#define SYSCFG_EXTICR3_EXTI8                 SYSCFG_EXTICR3_EXTI8_Msk          
#define SYSCFG_EXTICR3_EXTI9_Pos             (4U)                              
#define SYSCFG_EXTICR3_EXTI9_Msk             (0xFUL << SYSCFG_EXTICR3_EXTI9_Pos) 
#define SYSCFG_EXTICR3_EXTI9                 SYSCFG_EXTICR3_EXTI9_Msk         
#define SYSCFG_EXTICR3_EXTI10_Pos            (8U)                              
#define SYSCFG_EXTICR3_EXTI10_Msk            (0xFUL << SYSCFG_EXTICR3_EXTI10_Pos) 
#define SYSCFG_EXTICR3_EXTI10                SYSCFG_EXTICR3_EXTI10_Msk        
#define SYSCFG_EXTICR3_EXTI11_Pos            (12U)                             
#define SYSCFG_EXTICR3_EXTI11_Msk            (0xFUL << SYSCFG_EXTICR3_EXTI11_Pos) 
#define SYSCFG_EXTICR3_EXTI11                SYSCFG_EXTICR3_EXTI11_Msk        

/**
  *    EXTI8 configuration  
  */
#define SYSCFG_EXTICR3_EXTI8_PA              0x0000U                         
#define SYSCFG_EXTICR3_EXTI8_PB              0x0001U                         
#define SYSCFG_EXTICR3_EXTI8_PC              0x0002U                         
#define SYSCFG_EXTICR3_EXTI8_PD              0x0003U                         
#define SYSCFG_EXTICR3_EXTI8_PE              0x0004U                         
#define SYSCFG_EXTICR3_EXTI8_PF              0x0005U                         
#define SYSCFG_EXTICR3_EXTI8_PG              0x0006U                         
#define SYSCFG_EXTICR3_EXTI8_PH              0x0007U                         
#define SYSCFG_EXTICR3_EXTI8_PI              0x0008U                         

/**
  *    EXTI9 configuration  
  */
#define SYSCFG_EXTICR3_EXTI9_PA              0x0000U                         
#define SYSCFG_EXTICR3_EXTI9_PB              0x0010U                         
#define SYSCFG_EXTICR3_EXTI9_PC              0x0020U                         
#define SYSCFG_EXTICR3_EXTI9_PD              0x0030U                         
#define SYSCFG_EXTICR3_EXTI9_PE              0x0040U                         
#define SYSCFG_EXTICR3_EXTI9_PF              0x0050U                         
#define SYSCFG_EXTICR3_EXTI9_PG              0x0060U                         
#define SYSCFG_EXTICR3_EXTI9_PH              0x0070U                         
#define SYSCFG_EXTICR3_EXTI9_PI              0x0080U                         

/**
  *    EXTI10 configuration  
  */
#define SYSCFG_EXTICR3_EXTI10_PA             0x0000U                         
#define SYSCFG_EXTICR3_EXTI10_PB             0x0100U                         
#define SYSCFG_EXTICR3_EXTI10_PC             0x0200U                         
#define SYSCFG_EXTICR3_EXTI10_PD             0x0300U                         
#define SYSCFG_EXTICR3_EXTI10_PE             0x0400U                         
#define SYSCFG_EXTICR3_EXTI10_PF             0x0500U                         
#define SYSCFG_EXTICR3_EXTI10_PG             0x0600U                         
#define SYSCFG_EXTICR3_EXTI10_PH             0x0700U                         
#define SYSCFG_EXTICR3_EXTI10_PI             0x0800U                         

/**
  *    EXTI11 configuration  
  */
#define SYSCFG_EXTICR3_EXTI11_PA             0x0000U                         
#define SYSCFG_EXTICR3_EXTI11_PB             0x1000U                         
#define SYSCFG_EXTICR3_EXTI11_PC             0x2000U                         
#define SYSCFG_EXTICR3_EXTI11_PD             0x3000U                         
#define SYSCFG_EXTICR3_EXTI11_PE             0x4000U                         
#define SYSCFG_EXTICR3_EXTI11_PF             0x5000U                         
#define SYSCFG_EXTICR3_EXTI11_PG             0x6000U                         
#define SYSCFG_EXTICR3_EXTI11_PH             0x7000U                         
#define SYSCFG_EXTICR3_EXTI11_PI             0x8000U                         

/*****************  Bit definition for SYSCFG_EXTICR4 register  ***************/
#define SYSCFG_EXTICR4_EXTI12_Pos            (0U)                              
#define SYSCFG_EXTICR4_EXTI12_Msk            (0xFUL << SYSCFG_EXTICR4_EXTI12_Pos)
#define SYSCFG_EXTICR4_EXTI12                SYSCFG_EXTICR4_EXTI12_Msk        
#define SYSCFG_EXTICR4_EXTI13_Pos            (4U)                              
#define SYSCFG_EXTICR4_EXTI13_Msk            (0xFUL << SYSCFG_EXTICR4_EXTI13_Pos) 
#define SYSCFG_EXTICR4_EXTI13                SYSCFG_EXTICR4_EXTI13_Msk        
#define SYSCFG_EXTICR4_EXTI14_Pos            (8U)                              
#define SYSCFG_EXTICR4_EXTI14_Msk            (0xFUL << SYSCFG_EXTICR4_EXTI14_Pos) 
#define SYSCFG_EXTICR4_EXTI14                SYSCFG_EXTICR4_EXTI14_Msk         
#define SYSCFG_EXTICR4_EXTI15_Pos            (12U)                             
#define SYSCFG_EXTICR4_EXTI15_Msk            (0xFUL << SYSCFG_EXTICR4_EXTI15_Pos) 
#define SYSCFG_EXTICR4_EXTI15                SYSCFG_EXTICR4_EXTI15_Msk        

/**
  *    EXTI12 configuration  
  */
#define SYSCFG_EXTICR4_EXTI12_PA             0x0000U                       
#define SYSCFG_EXTICR4_EXTI12_PB             0x0001U                       
#define SYSCFG_EXTICR4_EXTI12_PC             0x0002U                       
#define SYSCFG_EXTICR4_EXTI12_PD             0x0003U                       
#define SYSCFG_EXTICR4_EXTI12_PE             0x0004U                       
#define SYSCFG_EXTICR4_EXTI12_PF             0x0005U                       
#define SYSCFG_EXTICR4_EXTI12_PG             0x0006U                       
#define SYSCFG_EXTICR4_EXTI12_PH             0x0007U                       

/**
  *    EXTI13 configuration  
  */
#define SYSCFG_EXTICR4_EXTI13_PA             0x0000U                       
#define SYSCFG_EXTICR4_EXTI13_PB             0x0010U                       
#define SYSCFG_EXTICR4_EXTI13_PC             0x0020U                       
#define SYSCFG_EXTICR4_EXTI13_PD             0x0030U                       
#define SYSCFG_EXTICR4_EXTI13_PE             0x0040U                       
#define SYSCFG_EXTICR4_EXTI13_PF             0x0050U                       
#define SYSCFG_EXTICR4_EXTI13_PG             0x0060U                       
#define SYSCFG_EXTICR4_EXTI13_PH             0x0070U                       

/**
  *    EXTI14 configuration  
  */
#define SYSCFG_EXTICR4_EXTI14_PA             0x0000U                       
#define SYSCFG_EXTICR4_EXTI14_PB             0x0100U                       
#define SYSCFG_EXTICR4_EXTI14_PC             0x0200U                       
#define SYSCFG_EXTICR4_EXTI14_PD             0x0300U                       
#define SYSCFG_EXTICR4_EXTI14_PE             0x0400U                       
#define SYSCFG_EXTICR4_EXTI14_PF             0x0500U                       
#define SYSCFG_EXTICR4_EXTI14_PG             0x0600U                       
#define SYSCFG_EXTICR4_EXTI14_PH             0x0700U                       

/**
  *    EXTI15 configuration  
  */
#define SYSCFG_EXTICR4_EXTI15_PA             0x0000U                      
#define SYSCFG_EXTICR4_EXTI15_PB             0x1000U                      
#define SYSCFG_EXTICR4_EXTI15_PC             0x2000U                      
#define SYSCFG_EXTICR4_EXTI15_PD             0x3000U                      
#define SYSCFG_EXTICR4_EXTI15_PE             0x4000U                      
#define SYSCFG_EXTICR4_EXTI15_PF             0x5000U                      
#define SYSCFG_EXTICR4_EXTI15_PG             0x6000U                      
#define SYSCFG_EXTICR4_EXTI15_PH             0x7000U                      

/******************  Bit definition for SYSCFG_CMPCR register  ****************/
#define SYSCFG_CMPCR_CMP_PD_Pos              (0U)                              
#define SYSCFG_CMPCR_CMP_PD_Msk              (0x1UL << SYSCFG_CMPCR_CMP_PD_Pos) 
#define SYSCFG_CMPCR_CMP_PD                  SYSCFG_CMPCR_CMP_PD_Msk          
#define SYSCFG_CMPCR_READY_Pos               (8U)                             
#define SYSCFG_CMPCR_READY_Msk               (0x1UL << SYSCFG_CMPCR_READY_Pos) 
#define SYSCFG_CMPCR_READY                   SYSCFG_CMPCR_READY_Msk   

#endif  /* HEADER_SYSTEM_H_ */
