#if !defined(HEADER_FLASH_H_)  
#define HEADER_FLASH_H_

#include "Header.h"


typedef struct
{
  __IO uint32_t ACR;      /* FLASH access control register  */
  __IO uint32_t KEYR;     /* FLASH key register             */
  __IO uint32_t OPTKEYR;  /* FLASH option key register      */
  __IO uint32_t SR;       /* FLASH status register          */
  __IO uint32_t CR;       /* FLASH control register         */
  __IO uint32_t OPTCR;    /* FLASH option control register  */
  __IO uint32_t OPTCR1;   /* FLASH option control register 1*/
} FLASH_RegDef_t;
#define FLASH               ((FLASH_RegDef_t *) FLASH_R_BASEADDR)

/** 
  *  Flexible Static Memory Controller
  */

typedef struct
{
  __IO uint32_t BTCR[8];    /* NOR/PSRAM chip-select control register(BCR) and chip-select timing register(BTR) */   
} FSMC_Bank1_TypeDef;
#define FSMC_Bank1          ((FSMC_Bank1_TypeDef *) FSMC_Bank1_R_BASE)

/** 
  *  Flexible Static Memory Controller Bank1E
  */

typedef struct
{
  __IO uint32_t BWTR[7];    /* NOR/PSRAM write timing registers */
} FSMC_Bank1E_TypeDef;
#define FSMC_Bank1E         ((FSMC_Bank1E_TypeDef *) FSMC_Bank1E_R_BASE)

/** 
  *  Flexible Static Memory Controller Bank2
  */
  
typedef struct
{
  __IO uint32_t PCR2;       /* NAND Flash control register 2,                        */
  __IO uint32_t SR2;        /* NAND Flash FIFO status and interrupt register 2,      */
  __IO uint32_t PMEM2;      /* NAND Flash Common memory space timing register 2,     */
  __IO uint32_t PATT2;      /* NAND Flash Attribute memory space timing register 2,  */
  uint32_t      RESERVED0;  /* Reserved, 0x70                                        */
  __IO uint32_t ECCR2;      /* NAND Flash ECC result registers 2,                    */
  uint32_t      RESERVED1;  /* Reserved, 0x78                                        */
  uint32_t      RESERVED2;  /* Reserved, 0x7C                                        */
  __IO uint32_t PCR3;       /* NAND Flash control register 3,                        */
  __IO uint32_t SR3;        /* NAND Flash FIFO status and interrupt register 3,      */
  __IO uint32_t PMEM3;      /* NAND Flash Common memory space timing register 3,     */
  __IO uint32_t PATT3;      /* NAND Flash Attribute memory space timing register 3,  */
  uint32_t      RESERVED3;  /* Reserved, 0x90                                        */
  __IO uint32_t ECCR3;      /* NAND Flash ECC result registers 3,                    */
} FSMC_Bank2_3_TypeDef;
#define FSMC_Bank2_3        ((FSMC_Bank2_3_TypeDef *) FSMC_Bank2_3_R_BASE)

/** 
  *  Flexible Static Memory Controller Bank4
  */

typedef struct
{
  __IO uint32_t PCR4;       /* PC Card  control register 4,                       */
  __IO uint32_t SR4;        /* PC Card  FIFO status and interrupt register 4,     */
  __IO uint32_t PMEM4;      /* PC Card  Common memory space timing register 4,    */
  __IO uint32_t PATT4;      /* PC Card  Attribute memory space timing register 4, */
  __IO uint32_t PIO4;       /* PC Card  I/O space timing register 4,              */
} FSMC_Bank4_TypeDef; 
#define FSMC_Bank4          ((FSMC_Bank4_TypeDef *) FSMC_Bank4_R_BASE)



/*******************  Bits definition for FLASH_ACR register  *****************/
#define FLASH_ACR_LATENCY_Pos          (0U)
#define FLASH_ACR_LATENCY_Msk          (0x7UL << FLASH_ACR_LATENCY_Pos)       
#define FLASH_ACR_LATENCY              FLASH_ACR_LATENCY_Msk
#define FLASH_ACR_LATENCY_0WS          0x00000000U
#define FLASH_ACR_LATENCY_1WS          0x00000001U
#define FLASH_ACR_LATENCY_2WS          0x00000002U
#define FLASH_ACR_LATENCY_3WS          0x00000003U
#define FLASH_ACR_LATENCY_4WS          0x00000004U
#define FLASH_ACR_LATENCY_5WS          0x00000005U
#define FLASH_ACR_LATENCY_6WS          0x00000006U
#define FLASH_ACR_LATENCY_7WS          0x00000007U

#define FLASH_ACR_PRFTEN_Pos           (8U)                                    
#define FLASH_ACR_PRFTEN_Msk           (0x1UL << FLASH_ACR_PRFTEN_Pos)         
#define FLASH_ACR_PRFTEN               FLASH_ACR_PRFTEN_Msk                   
#define FLASH_ACR_ICEN_Pos             (9U)                                   
#define FLASH_ACR_ICEN_Msk             (0x1UL << FLASH_ACR_ICEN_Pos)           
#define FLASH_ACR_ICEN                 FLASH_ACR_ICEN_Msk                     
#define FLASH_ACR_DCEN_Pos             (10U)                                  
#define FLASH_ACR_DCEN_Msk             (0x1UL << FLASH_ACR_DCEN_Pos)           
#define FLASH_ACR_DCEN                 FLASH_ACR_DCEN_Msk                     
#define FLASH_ACR_ICRST_Pos            (11U)                                  
#define FLASH_ACR_ICRST_Msk            (0x1UL << FLASH_ACR_ICRST_Pos)          
#define FLASH_ACR_ICRST                FLASH_ACR_ICRST_Msk                    
#define FLASH_ACR_DCRST_Pos            (12U)                                  
#define FLASH_ACR_DCRST_Msk            (0x1UL << FLASH_ACR_DCRST_Pos)          
#define FLASH_ACR_DCRST                FLASH_ACR_DCRST_Msk                     
#define FLASH_ACR_BYTE0_ADDRESS_Pos    (10U)                                   
#define FLASH_ACR_BYTE0_ADDRESS_Msk    (0x10008FUL << FLASH_ACR_BYTE0_ADDRESS_Pos) 
#define FLASH_ACR_BYTE0_ADDRESS        FLASH_ACR_BYTE0_ADDRESS_Msk             
#define FLASH_ACR_BYTE2_ADDRESS_Pos    (0U)                                    
#define FLASH_ACR_BYTE2_ADDRESS_Msk    (0x40023C03UL << FLASH_ACR_BYTE2_ADDRESS_Pos) 
#define FLASH_ACR_BYTE2_ADDRESS        FLASH_ACR_BYTE2_ADDRESS_Msk             

/*******************  Bits definition for FLASH_SR register  ******************/
#define FLASH_SR_EOP_Pos               (0U)                                    
#define FLASH_SR_EOP_Msk               (0x1UL << FLASH_SR_EOP_Pos)             
#define FLASH_SR_EOP                   FLASH_SR_EOP_Msk                       
#define FLASH_SR_SOP_Pos               (1U)                                   
#define FLASH_SR_SOP_Msk               (0x1UL << FLASH_SR_SOP_Pos)             
#define FLASH_SR_SOP                   FLASH_SR_SOP_Msk                       
#define FLASH_SR_WRPERR_Pos            (4U)                                   
#define FLASH_SR_WRPERR_Msk            (0x1UL << FLASH_SR_WRPERR_Pos)          
#define FLASH_SR_WRPERR                FLASH_SR_WRPERR_Msk                    
#define FLASH_SR_PGAERR_Pos            (5U)                                   
#define FLASH_SR_PGAERR_Msk            (0x1UL << FLASH_SR_PGAERR_Pos)          
#define FLASH_SR_PGAERR                FLASH_SR_PGAERR_Msk                    
#define FLASH_SR_PGPERR_Pos            (6U)                                   
#define FLASH_SR_PGPERR_Msk            (0x1UL << FLASH_SR_PGPERR_Pos)          
#define FLASH_SR_PGPERR                FLASH_SR_PGPERR_Msk                    
#define FLASH_SR_PGSERR_Pos            (7U)                                   
#define FLASH_SR_PGSERR_Msk            (0x1UL << FLASH_SR_PGSERR_Pos)          
#define FLASH_SR_PGSERR                FLASH_SR_PGSERR_Msk                    
#define FLASH_SR_BSY_Pos               (16U)                                  
#define FLASH_SR_BSY_Msk               (0x1UL << FLASH_SR_BSY_Pos)             
#define FLASH_SR_BSY                   FLASH_SR_BSY_Msk                       

/*******************  Bits definition for FLASH_CR register  ******************/
#define FLASH_CR_PG_Pos                (0U)                                    
#define FLASH_CR_PG_Msk                (0x1UL << FLASH_CR_PG_Pos)              
#define FLASH_CR_PG                    FLASH_CR_PG_Msk                        
#define FLASH_CR_SER_Pos               (1U)                                   
#define FLASH_CR_SER_Msk               (0x1UL << FLASH_CR_SER_Pos)             
#define FLASH_CR_SER                   FLASH_CR_SER_Msk                       
#define FLASH_CR_MER_Pos               (2U)                                   
#define FLASH_CR_MER_Msk               (0x1UL << FLASH_CR_MER_Pos)             
#define FLASH_CR_MER                   FLASH_CR_MER_Msk                       
#define FLASH_CR_SNB_Pos               (3U)                                   
#define FLASH_CR_SNB_Msk               (0x1FUL << FLASH_CR_SNB_Pos)            
#define FLASH_CR_SNB                   FLASH_CR_SNB_Msk                       
#define FLASH_CR_SNB_0                 (0x01UL << FLASH_CR_SNB_Pos)            
#define FLASH_CR_SNB_1                 (0x02UL << FLASH_CR_SNB_Pos)            
#define FLASH_CR_SNB_2                 (0x04UL << FLASH_CR_SNB_Pos)            
#define FLASH_CR_SNB_3                 (0x08UL << FLASH_CR_SNB_Pos)            
#define FLASH_CR_SNB_4                 (0x10UL << FLASH_CR_SNB_Pos)            
#define FLASH_CR_PSIZE_Pos             (8U)                                   
#define FLASH_CR_PSIZE_Msk             (0x3UL << FLASH_CR_PSIZE_Pos)           
#define FLASH_CR_PSIZE                 FLASH_CR_PSIZE_Msk                     
#define FLASH_CR_PSIZE_0               (0x1UL << FLASH_CR_PSIZE_Pos)           
#define FLASH_CR_PSIZE_1               (0x2UL << FLASH_CR_PSIZE_Pos)           
#define FLASH_CR_STRT_Pos              (16U)                                  
#define FLASH_CR_STRT_Msk              (0x1UL << FLASH_CR_STRT_Pos)            
#define FLASH_CR_STRT                  FLASH_CR_STRT_Msk                      
#define FLASH_CR_EOPIE_Pos             (24U)                                  
#define FLASH_CR_EOPIE_Msk             (0x1UL << FLASH_CR_EOPIE_Pos)           
#define FLASH_CR_EOPIE                 FLASH_CR_EOPIE_Msk                     
#define FLASH_CR_ERRIE_Pos             (25U)
#define FLASH_CR_ERRIE_Msk             (0x1UL << FLASH_CR_ERRIE_Pos)
#define FLASH_CR_ERRIE                 FLASH_CR_ERRIE_Msk
#define FLASH_CR_LOCK_Pos              (31U)                                  
#define FLASH_CR_LOCK_Msk              (0x1UL << FLASH_CR_LOCK_Pos)            
#define FLASH_CR_LOCK                  FLASH_CR_LOCK_Msk                       

/*******************  Bits definition for FLASH_OPTCR register  ***************/
#define FLASH_OPTCR_OPTLOCK_Pos        (0U)                                    
#define FLASH_OPTCR_OPTLOCK_Msk        (0x1UL << FLASH_OPTCR_OPTLOCK_Pos)      
#define FLASH_OPTCR_OPTLOCK            FLASH_OPTCR_OPTLOCK_Msk                
#define FLASH_OPTCR_OPTSTRT_Pos        (1U)                                   
#define FLASH_OPTCR_OPTSTRT_Msk        (0x1UL << FLASH_OPTCR_OPTSTRT_Pos)      
#define FLASH_OPTCR_OPTSTRT            FLASH_OPTCR_OPTSTRT_Msk                

#define FLASH_OPTCR_BOR_LEV_0          0x00000004U                            
#define FLASH_OPTCR_BOR_LEV_1          0x00000008U                            
#define FLASH_OPTCR_BOR_LEV_Pos        (2U)                                   
#define FLASH_OPTCR_BOR_LEV_Msk        (0x3UL << FLASH_OPTCR_BOR_LEV_Pos)      
#define FLASH_OPTCR_BOR_LEV            FLASH_OPTCR_BOR_LEV_Msk                
#define FLASH_OPTCR_WDG_SW_Pos         (5U)                                   
#define FLASH_OPTCR_WDG_SW_Msk         (0x1UL << FLASH_OPTCR_WDG_SW_Pos)       
#define FLASH_OPTCR_WDG_SW             FLASH_OPTCR_WDG_SW_Msk                 
#define FLASH_OPTCR_nRST_STOP_Pos      (6U)                                   
#define FLASH_OPTCR_nRST_STOP_Msk      (0x1UL << FLASH_OPTCR_nRST_STOP_Pos)    
#define FLASH_OPTCR_nRST_STOP          FLASH_OPTCR_nRST_STOP_Msk              
#define FLASH_OPTCR_nRST_STDBY_Pos     (7U)                                   
#define FLASH_OPTCR_nRST_STDBY_Msk     (0x1UL << FLASH_OPTCR_nRST_STDBY_Pos)   
#define FLASH_OPTCR_nRST_STDBY         FLASH_OPTCR_nRST_STDBY_Msk             
#define FLASH_OPTCR_RDP_Pos            (8U)                                   
#define FLASH_OPTCR_RDP_Msk            (0xFFUL << FLASH_OPTCR_RDP_Pos)         
#define FLASH_OPTCR_RDP                FLASH_OPTCR_RDP_Msk                    
#define FLASH_OPTCR_RDP_0              (0x01UL << FLASH_OPTCR_RDP_Pos)         
#define FLASH_OPTCR_RDP_1              (0x02UL << FLASH_OPTCR_RDP_Pos)         
#define FLASH_OPTCR_RDP_2              (0x04UL << FLASH_OPTCR_RDP_Pos)         
#define FLASH_OPTCR_RDP_3              (0x08UL << FLASH_OPTCR_RDP_Pos)         
#define FLASH_OPTCR_RDP_4              (0x10UL << FLASH_OPTCR_RDP_Pos)         
#define FLASH_OPTCR_RDP_5              (0x20UL << FLASH_OPTCR_RDP_Pos)         
#define FLASH_OPTCR_RDP_6              (0x40UL << FLASH_OPTCR_RDP_Pos)         
#define FLASH_OPTCR_RDP_7              (0x80UL << FLASH_OPTCR_RDP_Pos)         
#define FLASH_OPTCR_nWRP_Pos           (16U)                                  
#define FLASH_OPTCR_nWRP_Msk           (0xFFFUL << FLASH_OPTCR_nWRP_Pos)       
#define FLASH_OPTCR_nWRP               FLASH_OPTCR_nWRP_Msk                   
#define FLASH_OPTCR_nWRP_0             0x00010000U                             
#define FLASH_OPTCR_nWRP_1             0x00020000U                             
#define FLASH_OPTCR_nWRP_2             0x00040000U                             
#define FLASH_OPTCR_nWRP_3             0x00080000U                             
#define FLASH_OPTCR_nWRP_4             0x00100000U                             
#define FLASH_OPTCR_nWRP_5             0x00200000U                             
#define FLASH_OPTCR_nWRP_6             0x00400000U                             
#define FLASH_OPTCR_nWRP_7             0x00800000U                             
#define FLASH_OPTCR_nWRP_8             0x01000000U                             
#define FLASH_OPTCR_nWRP_9             0x02000000U                             
#define FLASH_OPTCR_nWRP_10            0x04000000U                             
#define FLASH_OPTCR_nWRP_11            0x08000000U                             
                                             
/******************  Bits definition for FLASH_OPTCR1 register  ***************/
#define FLASH_OPTCR1_nWRP_Pos          (16U)                                   
#define FLASH_OPTCR1_nWRP_Msk          (0xFFFUL << FLASH_OPTCR1_nWRP_Pos)      
#define FLASH_OPTCR1_nWRP              FLASH_OPTCR1_nWRP_Msk                  
#define FLASH_OPTCR1_nWRP_0            (0x001UL << FLASH_OPTCR1_nWRP_Pos)      
#define FLASH_OPTCR1_nWRP_1            (0x002UL << FLASH_OPTCR1_nWRP_Pos)      
#define FLASH_OPTCR1_nWRP_2            (0x004UL << FLASH_OPTCR1_nWRP_Pos)      
#define FLASH_OPTCR1_nWRP_3            (0x008UL << FLASH_OPTCR1_nWRP_Pos)      
#define FLASH_OPTCR1_nWRP_4            (0x010UL << FLASH_OPTCR1_nWRP_Pos)      
#define FLASH_OPTCR1_nWRP_5            (0x020UL << FLASH_OPTCR1_nWRP_Pos)      
#define FLASH_OPTCR1_nWRP_6            (0x040UL << FLASH_OPTCR1_nWRP_Pos)      
#define FLASH_OPTCR1_nWRP_7            (0x080UL << FLASH_OPTCR1_nWRP_Pos)      
#define FLASH_OPTCR1_nWRP_8            (0x100UL << FLASH_OPTCR1_nWRP_Pos)      
#define FLASH_OPTCR1_nWRP_9            (0x200UL << FLASH_OPTCR1_nWRP_Pos)      
#define FLASH_OPTCR1_nWRP_10           (0x400UL << FLASH_OPTCR1_nWRP_Pos)      
#define FLASH_OPTCR1_nWRP_11           (0x800UL << FLASH_OPTCR1_nWRP_Pos)   

/******************************************************************************/
/*                                                                            */
/*                                    FLASH                                   */
/*                                                                            */
/******************************************************************************/
/*******************  Bits definition for FLASH_ACR register  *****************/
#define FLASH_ACR_LATENCY_Pos          (0U)
#define FLASH_ACR_LATENCY_Msk          (0x7UL << FLASH_ACR_LATENCY_Pos)        
#define FLASH_ACR_LATENCY              FLASH_ACR_LATENCY_Msk
#define FLASH_ACR_LATENCY_0WS          0x00000000U
#define FLASH_ACR_LATENCY_1WS          0x00000001U
#define FLASH_ACR_LATENCY_2WS          0x00000002U
#define FLASH_ACR_LATENCY_3WS          0x00000003U
#define FLASH_ACR_LATENCY_4WS          0x00000004U
#define FLASH_ACR_LATENCY_5WS          0x00000005U
#define FLASH_ACR_LATENCY_6WS          0x00000006U
#define FLASH_ACR_LATENCY_7WS          0x00000007U


#define FLASH_ACR_PRFTEN_Pos           (8U)                                   
#define FLASH_ACR_PRFTEN_Msk           (0x1UL << FLASH_ACR_PRFTEN_Pos)         
#define FLASH_ACR_PRFTEN               FLASH_ACR_PRFTEN_Msk                   
#define FLASH_ACR_ICEN_Pos             (9U)                                   
#define FLASH_ACR_ICEN_Msk             (0x1UL << FLASH_ACR_ICEN_Pos)           
#define FLASH_ACR_ICEN                 FLASH_ACR_ICEN_Msk                     
#define FLASH_ACR_DCEN_Pos             (10U)                                  
#define FLASH_ACR_DCEN_Msk             (0x1UL << FLASH_ACR_DCEN_Pos)           
#define FLASH_ACR_DCEN                 FLASH_ACR_DCEN_Msk                     
#define FLASH_ACR_ICRST_Pos            (11U)                                  
#define FLASH_ACR_ICRST_Msk            (0x1UL << FLASH_ACR_ICRST_Pos)          
#define FLASH_ACR_ICRST                FLASH_ACR_ICRST_Msk                    
#define FLASH_ACR_DCRST_Pos            (12U)                                  
#define FLASH_ACR_DCRST_Msk            (0x1UL << FLASH_ACR_DCRST_Pos)          
#define FLASH_ACR_DCRST                FLASH_ACR_DCRST_Msk                     
#define FLASH_ACR_BYTE0_ADDRESS_Pos    (10U)                                   
#define FLASH_ACR_BYTE0_ADDRESS_Msk    (0x10008FUL << FLASH_ACR_BYTE0_ADDRESS_Pos) 
#define FLASH_ACR_BYTE0_ADDRESS        FLASH_ACR_BYTE0_ADDRESS_Msk             
#define FLASH_ACR_BYTE2_ADDRESS_Pos    (0U)                                    
#define FLASH_ACR_BYTE2_ADDRESS_Msk    (0x40023C03UL << FLASH_ACR_BYTE2_ADDRESS_Pos)
#define FLASH_ACR_BYTE2_ADDRESS        FLASH_ACR_BYTE2_ADDRESS_Msk             

/*******************  Bits definition for FLASH_SR register  ******************/
#define FLASH_SR_EOP_Pos               (0U)                                    
#define FLASH_SR_EOP_Msk               (0x1UL << FLASH_SR_EOP_Pos)              
#define FLASH_SR_EOP                   FLASH_SR_EOP_Msk                        
#define FLASH_SR_SOP_Pos               (1U)                                    
#define FLASH_SR_SOP_Msk               (0x1UL << FLASH_SR_SOP_Pos)              
#define FLASH_SR_SOP                   FLASH_SR_SOP_Msk                        
#define FLASH_SR_WRPERR_Pos            (4U)                                    
#define FLASH_SR_WRPERR_Msk            (0x1UL << FLASH_SR_WRPERR_Pos)           
#define FLASH_SR_WRPERR                FLASH_SR_WRPERR_Msk                     
#define FLASH_SR_PGAERR_Pos            (5U)                                    
#define FLASH_SR_PGAERR_Msk            (0x1UL << FLASH_SR_PGAERR_Pos)           
#define FLASH_SR_PGAERR                FLASH_SR_PGAERR_Msk                     
#define FLASH_SR_PGPERR_Pos            (6U)                                   
#define FLASH_SR_PGPERR_Msk            (0x1UL << FLASH_SR_PGPERR_Pos)         
#define FLASH_SR_PGPERR                FLASH_SR_PGPERR_Msk                    
#define FLASH_SR_PGSERR_Pos            (7U)                                   
#define FLASH_SR_PGSERR_Msk            (0x1UL << FLASH_SR_PGSERR_Pos)         
#define FLASH_SR_PGSERR                FLASH_SR_PGSERR_Msk                    
#define FLASH_SR_BSY_Pos               (16U)                                  
#define FLASH_SR_BSY_Msk               (0x1UL << FLASH_SR_BSY_Pos)            
#define FLASH_SR_BSY                   FLASH_SR_BSY_Msk                        

/*******************  Bits definition for FLASH_CR register  ******************/
#define FLASH_CR_PG_Pos                (0U)                                    
#define FLASH_CR_PG_Msk                (0x1UL << FLASH_CR_PG_Pos)               
#define FLASH_CR_PG                    FLASH_CR_PG_Msk                         
#define FLASH_CR_SER_Pos               (1U)                                    
#define FLASH_CR_SER_Msk               (0x1UL << FLASH_CR_SER_Pos)              
#define FLASH_CR_SER                   FLASH_CR_SER_Msk                        
#define FLASH_CR_MER_Pos               (2U)                                    
#define FLASH_CR_MER_Msk               (0x1UL << FLASH_CR_MER_Pos)              
#define FLASH_CR_MER                   FLASH_CR_MER_Msk                        
#define FLASH_CR_SNB_Pos               (3U)                                  
#define FLASH_CR_SNB_Msk               (0x1FUL << FLASH_CR_SNB_Pos)          
#define FLASH_CR_SNB                   FLASH_CR_SNB_Msk                      
#define FLASH_CR_SNB_0                 (0x01UL << FLASH_CR_SNB_Pos)          
#define FLASH_CR_SNB_1                 (0x02UL << FLASH_CR_SNB_Pos)          
#define FLASH_CR_SNB_2                 (0x04UL << FLASH_CR_SNB_Pos)          
#define FLASH_CR_SNB_3                 (0x08UL << FLASH_CR_SNB_Pos)          
#define FLASH_CR_SNB_4                 (0x10UL << FLASH_CR_SNB_Pos)          
#define FLASH_CR_PSIZE_Pos             (8U)                                  
#define FLASH_CR_PSIZE_Msk             (0x3UL << FLASH_CR_PSIZE_Pos)         
#define FLASH_CR_PSIZE                 FLASH_CR_PSIZE_Msk                    
#define FLASH_CR_PSIZE_0               (0x1UL << FLASH_CR_PSIZE_Pos)         
#define FLASH_CR_PSIZE_1               (0x2UL << FLASH_CR_PSIZE_Pos)         
#define FLASH_CR_STRT_Pos              (16U)                                 
#define FLASH_CR_STRT_Msk              (0x1UL << FLASH_CR_STRT_Pos)          
#define FLASH_CR_STRT                  FLASH_CR_STRT_Msk                     
#define FLASH_CR_EOPIE_Pos             (24U)                                 
#define FLASH_CR_EOPIE_Msk             (0x1UL << FLASH_CR_EOPIE_Pos)         
#define FLASH_CR_EOPIE                 FLASH_CR_EOPIE_Msk                    
#define FLASH_CR_ERRIE_Pos             (25U)
#define FLASH_CR_ERRIE_Msk             (0x1UL << FLASH_CR_ERRIE_Pos)
#define FLASH_CR_ERRIE                 FLASH_CR_ERRIE_Msk
#define FLASH_CR_LOCK_Pos              (31U)                                 
#define FLASH_CR_LOCK_Msk              (0x1UL << FLASH_CR_LOCK_Pos)          
#define FLASH_CR_LOCK                  FLASH_CR_LOCK_Msk                     

/*******************  Bits definition for FLASH_OPTCR register  ***************/
#define FLASH_OPTCR_OPTLOCK_Pos        (0U)                                    
#define FLASH_OPTCR_OPTLOCK_Msk        (0x1UL << FLASH_OPTCR_OPTLOCK_Pos)       
#define FLASH_OPTCR_OPTLOCK            FLASH_OPTCR_OPTLOCK_Msk                 
#define FLASH_OPTCR_OPTSTRT_Pos        (1U)                                    
#define FLASH_OPTCR_OPTSTRT_Msk        (0x1UL << FLASH_OPTCR_OPTSTRT_Pos)       
#define FLASH_OPTCR_OPTSTRT            FLASH_OPTCR_OPTSTRT_Msk                 

#define FLASH_OPTCR_BOR_LEV_0          0x00000004U                             
#define FLASH_OPTCR_BOR_LEV_1          0x00000008U                           
#define FLASH_OPTCR_BOR_LEV_Pos        (2U)                                  
#define FLASH_OPTCR_BOR_LEV_Msk        (0x3UL << FLASH_OPTCR_BOR_LEV_Pos)    
#define FLASH_OPTCR_BOR_LEV            FLASH_OPTCR_BOR_LEV_Msk               
#define FLASH_OPTCR_WDG_SW_Pos         (5U)                                  
#define FLASH_OPTCR_WDG_SW_Msk         (0x1UL << FLASH_OPTCR_WDG_SW_Pos)     
#define FLASH_OPTCR_WDG_SW             FLASH_OPTCR_WDG_SW_Msk                
#define FLASH_OPTCR_nRST_STOP_Pos      (6U)                                  
#define FLASH_OPTCR_nRST_STOP_Msk      (0x1UL << FLASH_OPTCR_nRST_STOP_Pos)  
#define FLASH_OPTCR_nRST_STOP          FLASH_OPTCR_nRST_STOP_Msk             
#define FLASH_OPTCR_nRST_STDBY_Pos     (7U)                                  
#define FLASH_OPTCR_nRST_STDBY_Msk     (0x1UL << FLASH_OPTCR_nRST_STDBY_Pos) 
#define FLASH_OPTCR_nRST_STDBY         FLASH_OPTCR_nRST_STDBY_Msk            
#define FLASH_OPTCR_RDP_Pos            (8U)                                  
#define FLASH_OPTCR_RDP_Msk            (0xFFUL << FLASH_OPTCR_RDP_Pos)       
#define FLASH_OPTCR_RDP                FLASH_OPTCR_RDP_Msk                   
#define FLASH_OPTCR_RDP_0              (0x01UL << FLASH_OPTCR_RDP_Pos)       
#define FLASH_OPTCR_RDP_1              (0x02UL << FLASH_OPTCR_RDP_Pos)       
#define FLASH_OPTCR_RDP_2              (0x04UL << FLASH_OPTCR_RDP_Pos)       
#define FLASH_OPTCR_RDP_3              (0x08UL << FLASH_OPTCR_RDP_Pos)       
#define FLASH_OPTCR_RDP_4              (0x10UL << FLASH_OPTCR_RDP_Pos)       
#define FLASH_OPTCR_RDP_5              (0x20UL << FLASH_OPTCR_RDP_Pos)       
#define FLASH_OPTCR_RDP_6              (0x40UL << FLASH_OPTCR_RDP_Pos)       
#define FLASH_OPTCR_RDP_7              (0x80UL << FLASH_OPTCR_RDP_Pos)       
#define FLASH_OPTCR_nWRP_Pos           (16U)                                 
#define FLASH_OPTCR_nWRP_Msk           (0xFFFUL << FLASH_OPTCR_nWRP_Pos)     
#define FLASH_OPTCR_nWRP               FLASH_OPTCR_nWRP_Msk                  
#define FLASH_OPTCR_nWRP_0             0x00010000U                           
#define FLASH_OPTCR_nWRP_1             0x00020000U                           
#define FLASH_OPTCR_nWRP_2             0x00040000U                           
#define FLASH_OPTCR_nWRP_3             0x00080000U                             
#define FLASH_OPTCR_nWRP_4             0x00100000U                             
#define FLASH_OPTCR_nWRP_5             0x00200000U                             
#define FLASH_OPTCR_nWRP_6             0x00400000U                             
#define FLASH_OPTCR_nWRP_7             0x00800000U                             
#define FLASH_OPTCR_nWRP_8             0x01000000U                             
#define FLASH_OPTCR_nWRP_9             0x02000000U                             
#define FLASH_OPTCR_nWRP_10            0x04000000U                             
#define FLASH_OPTCR_nWRP_11            0x08000000U                             
                                             
/******************  Bits definition for FLASH_OPTCR1 register  ***************/
#define FLASH_OPTCR1_nWRP_Pos          (16U)                                  
#define FLASH_OPTCR1_nWRP_Msk          (0xFFFUL << FLASH_OPTCR1_nWRP_Pos)      
#define FLASH_OPTCR1_nWRP              FLASH_OPTCR1_nWRP_Msk                  
#define FLASH_OPTCR1_nWRP_0            (0x001UL << FLASH_OPTCR1_nWRP_Pos)      
#define FLASH_OPTCR1_nWRP_1            (0x002UL << FLASH_OPTCR1_nWRP_Pos)      
#define FLASH_OPTCR1_nWRP_2            (0x004UL << FLASH_OPTCR1_nWRP_Pos)      
#define FLASH_OPTCR1_nWRP_3            (0x008UL << FLASH_OPTCR1_nWRP_Pos)      
#define FLASH_OPTCR1_nWRP_4            (0x010UL << FLASH_OPTCR1_nWRP_Pos)      
#define FLASH_OPTCR1_nWRP_5            (0x020UL << FLASH_OPTCR1_nWRP_Pos)      
#define FLASH_OPTCR1_nWRP_6            (0x040UL << FLASH_OPTCR1_nWRP_Pos)      
#define FLASH_OPTCR1_nWRP_7            (0x080UL << FLASH_OPTCR1_nWRP_Pos)      
#define FLASH_OPTCR1_nWRP_8            (0x100UL << FLASH_OPTCR1_nWRP_Pos)      
#define FLASH_OPTCR1_nWRP_9            (0x200UL << FLASH_OPTCR1_nWRP_Pos)      
#define FLASH_OPTCR1_nWRP_10           (0x400UL << FLASH_OPTCR1_nWRP_Pos)      
#define FLASH_OPTCR1_nWRP_11           (0x800UL << FLASH_OPTCR1_nWRP_Pos)      


#endif  /* HEADER_FLASH_H_ */
