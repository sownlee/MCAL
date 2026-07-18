#if !defined(HEADER_WDOG_H_)  
#define HEADER_WDOG_H_

#include "Header.h"

/**
  *brief  Structure type to access the Data Watchpoint and Trace Register (DWT).
 */
typedef struct
{
  __IO uint32_t CTRL;                   /* Offset: 0x000 (R/W)  Control Register */
  __IO uint32_t CYCCNT;                 /* Offset: 0x004 (R/W)  Cycle Count Register */
  __IO uint32_t CPICNT;                 /* Offset: 0x008 (R/W)  CPI Count Register */
  __IO uint32_t EXCCNT;                 /* Offset: 0x00C (R/W)  Exception Overhead Count Register */
  __IO uint32_t SLEEPCNT;               /* Offset: 0x010 (R/W)  Sleep Count Register */
  __IO uint32_t LSUCNT;                 /* Offset: 0x014 (R/W)  LSU Count Register */
  __IO uint32_t FOLDCNT;                /* Offset: 0x018 (R/W)  Folded-instruction Count Register */
  __I  uint32_t PCSR;                   /* Offset: 0x01C (R/ )  Program Counter Sample Register */
  __IO uint32_t COMP0;                  /* Offset: 0x020 (R/W)  Comparator Register 0 */
  __IO uint32_t MASK0;                  /* Offset: 0x024 (R/W)  Mask Register 0 */
  __IO uint32_t FUNCTION0;              /* Offset: 0x028 (R/W)  Function Register 0 */
        uint32_t RESERVED0[1U];
  __IO uint32_t COMP1;                  /* Offset: 0x030 (R/W)  Comparator Register 1 */
  __IO uint32_t MASK1;                  /* Offset: 0x034 (R/W)  Mask Register 1 */
  __IO uint32_t FUNCTION1;              /* Offset: 0x038 (R/W)  Function Register 1 */
        uint32_t RESERVED1[1U];
  __IO uint32_t COMP2;                  /* Offset: 0x040 (R/W)  Comparator Register 2 */
  __IO uint32_t MASK2;                  /* Offset: 0x044 (R/W)  Mask Register 2 */
  __IO uint32_t FUNCTION2;              /* Offset: 0x048 (R/W)  Function Register 2 */
        uint32_t RESERVED2[1U];
  __IO uint32_t COMP3;                  /* Offset: 0x050 (R/W)  Comparator Register 3 */
  __IO uint32_t MASK3;                  /* Offset: 0x054 (R/W)  Mask Register 3 */
  __IO uint32_t FUNCTION3;              /* Offset: 0x058 (R/W)  Function Register 3 */
} DWT_Type;
#define DWT                 ((DWT_Type       *)     DWT_BASE      ) 

typedef struct
{
  __IO uint32_t KR;   /* IWDG Key register,        */
  __IO uint32_t PR;   /* IWDG Prescaler register,  */
  __IO uint32_t RLR;  /* IWDG Reload register,     */
  __IO uint32_t SR;   /* IWDG Status register,     */
} IWDG_TypeDef;
#define IWDG                ((IWDG_TypeDef *) IWDG_BASE)

typedef struct
{
  __IO uint32_t CR;   /* WWDG Control register,       */
  __IO uint32_t CFR;  /* WWDG Configuration register, */
  __IO uint32_t SR;   /* WWDG Status register,        */
} WWDG_TypeDef;
#define WWDG                ((WWDG_TypeDef *) WWDG_BASE)

/* DWT Control Register Definitions */
#define DWT_CTRL_NUMCOMP_Pos               28U                                        
#define DWT_CTRL_NUMCOMP_Msk               (0xFUL << DWT_CTRL_NUMCOMP_Pos)            

#define DWT_CTRL_NOTRCPKT_Pos              27U                                        
#define DWT_CTRL_NOTRCPKT_Msk              (0x1UL << DWT_CTRL_NOTRCPKT_Pos)           

#define DWT_CTRL_NOEXTTRIG_Pos             26U                                        
#define DWT_CTRL_NOEXTTRIG_Msk             (0x1UL << DWT_CTRL_NOEXTTRIG_Pos)          

#define DWT_CTRL_NOCYCCNT_Pos              25U                                        
#define DWT_CTRL_NOCYCCNT_Msk              (0x1UL << DWT_CTRL_NOCYCCNT_Pos)           

#define DWT_CTRL_NOPRFCNT_Pos              24U                                        
#define DWT_CTRL_NOPRFCNT_Msk              (0x1UL << DWT_CTRL_NOPRFCNT_Pos)           

#define DWT_CTRL_CYCEVTENA_Pos             22U                                        
#define DWT_CTRL_CYCEVTENA_Msk             (0x1UL << DWT_CTRL_CYCEVTENA_Pos)          

#define DWT_CTRL_FOLDEVTENA_Pos            21U                                        
#define DWT_CTRL_FOLDEVTENA_Msk            (0x1UL << DWT_CTRL_FOLDEVTENA_Pos)         

#define DWT_CTRL_LSUEVTENA_Pos             20U                                        
#define DWT_CTRL_LSUEVTENA_Msk             (0x1UL << DWT_CTRL_LSUEVTENA_Pos)          

#define DWT_CTRL_SLEEPEVTENA_Pos           19U                                        
#define DWT_CTRL_SLEEPEVTENA_Msk           (0x1UL << DWT_CTRL_SLEEPEVTENA_Pos)        

#define DWT_CTRL_EXCEVTENA_Pos             18U                                        
#define DWT_CTRL_EXCEVTENA_Msk             (0x1UL << DWT_CTRL_EXCEVTENA_Pos)          

#define DWT_CTRL_CPIEVTENA_Pos             17U                                        
#define DWT_CTRL_CPIEVTENA_Msk             (0x1UL << DWT_CTRL_CPIEVTENA_Pos)          

#define DWT_CTRL_EXCTRCENA_Pos             16U                                        
#define DWT_CTRL_EXCTRCENA_Msk             (0x1UL << DWT_CTRL_EXCTRCENA_Pos)          

#define DWT_CTRL_PCSAMPLENA_Pos            12U                                        
#define DWT_CTRL_PCSAMPLENA_Msk            (0x1UL << DWT_CTRL_PCSAMPLENA_Pos)         

#define DWT_CTRL_SYNCTAP_Pos               10U                                        
#define DWT_CTRL_SYNCTAP_Msk               (0x3UL << DWT_CTRL_SYNCTAP_Pos)            

#define DWT_CTRL_CYCTAP_Pos                 9U                                        
#define DWT_CTRL_CYCTAP_Msk                (0x1UL << DWT_CTRL_CYCTAP_Pos)             

#define DWT_CTRL_POSTINIT_Pos               5U                                        
#define DWT_CTRL_POSTINIT_Msk              (0xFUL << DWT_CTRL_POSTINIT_Pos)           

#define DWT_CTRL_POSTPRESET_Pos             1U                                        
#define DWT_CTRL_POSTPRESET_Msk            (0xFUL << DWT_CTRL_POSTPRESET_Pos)         

#define DWT_CTRL_CYCCNTENA_Pos              0U                                        
#define DWT_CTRL_CYCCNTENA_Msk             (0x1UL /* DWT_CTRL_CYCCNTENA_Pos*/)      

/* DWT CPI Count Register Definitions */
#define DWT_CPICNT_CPICNT_Pos               0U                                        
#define DWT_CPICNT_CPICNT_Msk              (0xFFUL /* DWT_CPICNT_CPICNT_Pos*/)      

/* DWT Exception Overhead Count Register Definitions */
#define DWT_EXCCNT_EXCCNT_Pos               0U                                        
#define DWT_EXCCNT_EXCCNT_Msk              (0xFFUL /* DWT_EXCCNT_EXCCNT_Pos*/)      

/* DWT Sleep Count Register Definitions */
#define DWT_SLEEPCNT_SLEEPCNT_Pos           0U                                        
#define DWT_SLEEPCNT_SLEEPCNT_Msk          (0xFFUL /* DWT_SLEEPCNT_SLEEPCNT_Pos*/)  

/* DWT LSU Count Register Definitions */
#define DWT_LSUCNT_LSUCNT_Pos               0U                                        
#define DWT_LSUCNT_LSUCNT_Msk              (0xFFUL /* DWT_LSUCNT_LSUCNT_Pos*/)      

/* DWT Folded-instruction Count Register Definitions */
#define DWT_FOLDCNT_FOLDCNT_Pos             0U                                        
#define DWT_FOLDCNT_FOLDCNT_Msk            (0xFFUL /* DWT_FOLDCNT_FOLDCNT_Pos*/)    

/* DWT Comparator Mask Register Definitions */
#define DWT_MASK_MASK_Pos                   0U                                        
#define DWT_MASK_MASK_Msk                  (0x1FUL /* DWT_MASK_MASK_Pos*/)          

/* DWT Comparator Function Register Definitions */
#define DWT_FUNCTION_MATCHED_Pos           24U                                        
#define DWT_FUNCTION_MATCHED_Msk           (0x1UL << DWT_FUNCTION_MATCHED_Pos)        

#define DWT_FUNCTION_DATAVADDR1_Pos        16U                                        
#define DWT_FUNCTION_DATAVADDR1_Msk        (0xFUL << DWT_FUNCTION_DATAVADDR1_Pos)     

#define DWT_FUNCTION_DATAVADDR0_Pos        12U                                        
#define DWT_FUNCTION_DATAVADDR0_Msk        (0xFUL << DWT_FUNCTION_DATAVADDR0_Pos)     

#define DWT_FUNCTION_DATAVSIZE_Pos         10U                                        
#define DWT_FUNCTION_DATAVSIZE_Msk         (0x3UL << DWT_FUNCTION_DATAVSIZE_Pos)      

#define DWT_FUNCTION_LNK1ENA_Pos            9U                                        
#define DWT_FUNCTION_LNK1ENA_Msk           (0x1UL << DWT_FUNCTION_LNK1ENA_Pos)        

#define DWT_FUNCTION_DATAVMATCH_Pos         8U                                        
#define DWT_FUNCTION_DATAVMATCH_Msk        (0x1UL << DWT_FUNCTION_DATAVMATCH_Pos)     

#define DWT_FUNCTION_CYCMATCH_Pos           7U                                        
#define DWT_FUNCTION_CYCMATCH_Msk          (0x1UL << DWT_FUNCTION_CYCMATCH_Pos)       

#define DWT_FUNCTION_EMITRANGE_Pos          5U                                        
#define DWT_FUNCTION_EMITRANGE_Msk         (0x1UL << DWT_FUNCTION_EMITRANGE_Pos)      

#define DWT_FUNCTION_FUNCTION_Pos           0U                                        
#define DWT_FUNCTION_FUNCTION_Msk          (0xFUL /* DWT_FUNCTION_FUNCTION_Pos*/)   

/******************************************************************************/
/*                                                                            */
/*                           Independent WATCHDOG                             */
/*                                                                            */
/******************************************************************************/
/*******************  Bit definition for IWDG_KR register  ********************/
#define IWDG_KR_KEY_Pos     (0U)                                              
#define IWDG_KR_KEY_Msk     (0xFFFFUL << IWDG_KR_KEY_Pos)                      
#define IWDG_KR_KEY         IWDG_KR_KEY_Msk                                    

/*******************  Bit definition for IWDG_PR register  ********************/
#define IWDG_PR_PR_Pos      (0U)                                               
#define IWDG_PR_PR_Msk      (0x7UL << IWDG_PR_PR_Pos)                       
#define IWDG_PR_PR          IWDG_PR_PR_Msk                                  
#define IWDG_PR_PR_0        (0x1UL << IWDG_PR_PR_Pos)                       
#define IWDG_PR_PR_1        (0x2UL << IWDG_PR_PR_Pos)                       
#define IWDG_PR_PR_2        (0x4UL << IWDG_PR_PR_Pos)                       

/*******************  Bit definition for IWDG_RLR register  *******************/
#define IWDG_RLR_RL_Pos     (0U)                                              
#define IWDG_RLR_RL_Msk     (0xFFFUL << IWDG_RLR_RL_Pos)                      
#define IWDG_RLR_RL         IWDG_RLR_RL_Msk                                   

/*******************  Bit definition for IWDG_SR register  ********************/
#define IWDG_SR_PVU_Pos     (0U)                                               
#define IWDG_SR_PVU_Msk     (0x1UL << IWDG_SR_PVU_Pos)                        
#define IWDG_SR_PVU         IWDG_SR_PVU_Msk                                   
#define IWDG_SR_RVU_Pos     (1U)                                              
#define IWDG_SR_RVU_Msk     (0x1UL << IWDG_SR_RVU_Pos)                        
#define IWDG_SR_RVU         IWDG_SR_RVU_Msk    

/******************************************************************************/
/*                                                                            */
/*                            Window WATCHDOG                                 */
/*                                                                            */
/******************************************************************************/
/*******************  Bit definition for WWDG_CR register  ********************/
#define WWDG_CR_T_Pos           (0U)                                           
#define WWDG_CR_T_Msk           (0x7FUL << WWDG_CR_T_Pos)                       /* 0x0000007F */
#define WWDG_CR_T               WWDG_CR_T_Msk                                  /*T[6:0] bits (7-Bit counter (MSB to LSB)) */
#define WWDG_CR_T_0             (0x01UL << WWDG_CR_T_Pos)                       /* 0x01 */
#define WWDG_CR_T_1             (0x02UL << WWDG_CR_T_Pos)                       /* 0x02 */
#define WWDG_CR_T_2             (0x04UL << WWDG_CR_T_Pos)                       /* 0x04 */
#define WWDG_CR_T_3             (0x08UL << WWDG_CR_T_Pos)                       /* 0x08 */
#define WWDG_CR_T_4             (0x10UL << WWDG_CR_T_Pos)                       /* 0x10 */
#define WWDG_CR_T_5             (0x20UL << WWDG_CR_T_Pos)                       /* 0x20 */
#define WWDG_CR_T_6             (0x40UL << WWDG_CR_T_Pos)                       /* 0x40 */
/* Legacy defines */
#define  WWDG_CR_T0                          WWDG_CR_T_0
#define  WWDG_CR_T1                          WWDG_CR_T_1
#define  WWDG_CR_T2                          WWDG_CR_T_2
#define  WWDG_CR_T3                          WWDG_CR_T_3
#define  WWDG_CR_T4                          WWDG_CR_T_4
#define  WWDG_CR_T5                          WWDG_CR_T_5
#define  WWDG_CR_T6                          WWDG_CR_T_6

#define WWDG_CR_WDGA_Pos        (7U)                                           
#define WWDG_CR_WDGA_Msk        (0x1UL << WWDG_CR_WDGA_Pos)                     /* 0x00000080 */
#define WWDG_CR_WDGA            WWDG_CR_WDGA_Msk                               /*Activation bit */

/*******************  Bit definition for WWDG_CFR register  *******************/
#define WWDG_CFR_W_Pos          (0U)                                           
#define WWDG_CFR_W_Msk          (0x7FUL << WWDG_CFR_W_Pos)                      /* 0x0000007F */
#define WWDG_CFR_W              WWDG_CFR_W_Msk                                 /*W[6:0] bits (7-bit window value) */
#define WWDG_CFR_W_0            (0x01UL << WWDG_CFR_W_Pos)                      /* 0x0001 */
#define WWDG_CFR_W_1            (0x02UL << WWDG_CFR_W_Pos)                      /* 0x0002 */
#define WWDG_CFR_W_2            (0x04UL << WWDG_CFR_W_Pos)                      /* 0x0004 */
#define WWDG_CFR_W_3            (0x08UL << WWDG_CFR_W_Pos)                      /* 0x0008 */
#define WWDG_CFR_W_4            (0x10UL << WWDG_CFR_W_Pos)                      /* 0x0010 */
#define WWDG_CFR_W_5            (0x20UL << WWDG_CFR_W_Pos)                      /* 0x0020 */
#define WWDG_CFR_W_6            (0x40UL << WWDG_CFR_W_Pos)                      /* 0x0040 */
/* Legacy defines */
#define  WWDG_CFR_W0                         WWDG_CFR_W_0
#define  WWDG_CFR_W1                         WWDG_CFR_W_1
#define  WWDG_CFR_W2                         WWDG_CFR_W_2
#define  WWDG_CFR_W3                         WWDG_CFR_W_3
#define  WWDG_CFR_W4                         WWDG_CFR_W_4
#define  WWDG_CFR_W5                         WWDG_CFR_W_5
#define  WWDG_CFR_W6                         WWDG_CFR_W_6

#define WWDG_CFR_WDGTB_Pos      (7U)                                           
#define WWDG_CFR_WDGTB_Msk      (0x3UL << WWDG_CFR_WDGTB_Pos)                   /* 0x00000180 */
#define WWDG_CFR_WDGTB          WWDG_CFR_WDGTB_Msk                             /*WDGTB[1:0] bits (Timer Base) */
#define WWDG_CFR_WDGTB_0        (0x1UL << WWDG_CFR_WDGTB_Pos)                   /* 0x0080 */
#define WWDG_CFR_WDGTB_1        (0x2UL << WWDG_CFR_WDGTB_Pos)                   /* 0x0100 */
/* Legacy defines */
#define  WWDG_CFR_WDGTB0                     WWDG_CFR_WDGTB_0
#define  WWDG_CFR_WDGTB1                     WWDG_CFR_WDGTB_1

#define WWDG_CFR_EWI_Pos        (9U)                                           
#define WWDG_CFR_EWI_Msk        (0x1UL << WWDG_CFR_EWI_Pos)                     /* 0x00000200 */
#define WWDG_CFR_EWI            WWDG_CFR_EWI_Msk                               /*Early Wakeup Interrupt */

/*******************  Bit definition for WWDG_SR register  ********************/
#define WWDG_SR_EWIF_Pos        (0U)                                           
#define WWDG_SR_EWIF_Msk        (0x1UL << WWDG_SR_EWIF_Pos)                     
#define WWDG_SR_EWIF            WWDG_SR_EWIF_Msk                               /*Early Wakeup Interrupt Flag */

#endif  /* #if !defined(HEADER_WDOG_H_) */
