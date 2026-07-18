#if !defined(HEADER_CAN_H_) 
#define HEADER_CAN_H_

#include "Header.h"

/**
  * CAN TxMailBox 
*/
typedef struct
{
  __O uint32_t TIR;  /* CAN TX mailbox identifier register */
  __O uint32_t TDTR; /* CAN mailbox data length control and time stamp register */
  __O uint32_t TDLR; /* CAN mailbox data low register */
  __O uint32_t TDHR; /* CAN mailbox data high register */
} CAN_TxMailBox_RegDef_t;

/** 
  * CAN FIFO Register 
  */
typedef struct
{
  __O uint32_t RIR;  /* CAN receive FIFO mailbox identifier register */
  __O uint32_t RDTR; /* CAN receive FIFO mailbox data length control and time stamp register */
  __O uint32_t RDLR; /* CAN receive FIFO mailbox data low register */
  __O uint32_t RDHR; /* CAN receive FIFO mailbox data high register */
} CAN_FIFOMailBox_RegDef_t;

/*
  * CAN Filter Register 
  */
typedef struct
{
  __O uint32_t FR1; /* CAN Filter bank register 1 */
  __O uint32_t FR2; /* CAN Filter bank register 2 */
} CAN_FilterRegister_RegDef_t;

/*Define register for  CANx*/
typedef struct
{
	__O uint32_t MCR;                          /* CAN master control register          Address offset: 0x00*/
	__O uint32_t MSR;                          /* CAN master status register           Address offset: 0x04*/
	__O uint32_t TSR;                          /* CAN transmit status register         Address offset: 0x08*/
	__O uint32_t RF0R;                         /* CAN receive FIFO 0 register          Address offset: 0x0C*/
	__O uint32_t RF1R;                         /* CAN receive FIFO 1 register          Address offset: 0x10*/
  __O uint32_t IER;                        /* CAN interrupt enable register        Address offset: 0x14*/
	__O uint32_t ESR;                          /* CAN error status register            Address offset: 0x18*/
	__O uint32_t BTR;                          /* CAN bit timing register              Address offset: 0x1C*/
	uint32_t RESERVED0[88];                     /* Reserved,                            0x020 - 0x17F       */
  CAN_TxMailBox_RegDef_t TxMailBox[3];      /* CAN Tx MailBox,                      Address offset: 0x180 - 0x1AC*/
	CAN_FIFOMailBox_RegDef_t FIFOMailBox[2];    /* CAN FIFO MailBox,                    Address offset: 0x1B0 - 0x1CC */
	uint32_t RESERVED1[12];                     /* Reserved, 0x1D0 - 0x1FF                              */
	__O uint32_t FMR;                          /* CAN filter master register,          Address offset: 0x200         */
  __O uint32_t FM1R;                       /* CAN filter mode register,            Address offset: 0x204         */
  uint32_t RESERVED2;                       /* Reserved, 0x208                                                    */
  __O uint32_t FS1R;                       /* CAN filter scale register,           Address offset: 0x20C         */
  uint32_t RESERVED3;                       /* Reserved, 0x210                                                    */
  __O uint32_t FFA1R;                      /* CAN filter FIFO assignment register, Address offset: 0x214         */
  uint32_t RESERVED4;                       /* Reserved, 0x218                                                    */
  __O uint32_t FA1R;                       /* CAN filter activation register,      Address offset: 0x21C         */
  uint32_t RESERVED5[8];                    /* Reserved, 0x220-0x23F                                              */ 
  CAN_FilterRegister_RegDef_t FilterRegister[28]; /* CAN Filter Register,              Address offset: 0x240-0x31C   */
} CAN_RegDef_t;
#define CAN1                ((CAN_RegDef_t *) CAN1_BASEADDR)
#define CAN2                ((CAN_RegDef_t *) CAN2_BASEADDR)

/*******************  Bit definition for CAN_MCR register  ********************/
#define CAN_MCR_INRQ_Pos       (0U)                                            
#define CAN_MCR_INRQ_Msk       (0x1UL << CAN_MCR_INRQ_Pos)                   
#define CAN_MCR_INRQ           CAN_MCR_INRQ_Msk                              
#define CAN_MCR_SLEEP_Pos      (1U)                                          
#define CAN_MCR_SLEEP_Msk      (0x1UL << CAN_MCR_SLEEP_Pos)                  
#define CAN_MCR_SLEEP          CAN_MCR_SLEEP_Msk                             
#define CAN_MCR_TXFP_Pos       (2U)                                          
#define CAN_MCR_TXFP_Msk       (0x1UL << CAN_MCR_TXFP_Pos)                   
#define CAN_MCR_TXFP           CAN_MCR_TXFP_Msk                              
#define CAN_MCR_RFLM_Pos       (3U)                                          
#define CAN_MCR_RFLM_Msk       (0x1UL << CAN_MCR_RFLM_Pos)                   
#define CAN_MCR_RFLM           CAN_MCR_RFLM_Msk                              
#define CAN_MCR_NART_Pos       (4U)                                          
#define CAN_MCR_NART_Msk       (0x1UL << CAN_MCR_NART_Pos)                   
#define CAN_MCR_NART           CAN_MCR_NART_Msk                              
#define CAN_MCR_AWUM_Pos       (5U)                                          
#define CAN_MCR_AWUM_Msk       (0x1UL << CAN_MCR_AWUM_Pos)                   
#define CAN_MCR_AWUM           CAN_MCR_AWUM_Msk                              
#define CAN_MCR_ABOM_Pos       (6U)                                          
#define CAN_MCR_ABOM_Msk       (0x1UL << CAN_MCR_ABOM_Pos)                   
#define CAN_MCR_ABOM           CAN_MCR_ABOM_Msk                              
#define CAN_MCR_TTCM_Pos       (7U)                                          
#define CAN_MCR_TTCM_Msk       (0x1UL << CAN_MCR_TTCM_Pos)                   
#define CAN_MCR_TTCM           CAN_MCR_TTCM_Msk                              
#define CAN_MCR_RESET_Pos      (15U)                                         
#define CAN_MCR_RESET_Msk      (0x1UL << CAN_MCR_RESET_Pos)                  
#define CAN_MCR_RESET          CAN_MCR_RESET_Msk                             
#define CAN_MCR_DBF_Pos        (16U)                                         
#define CAN_MCR_DBF_Msk        (0x1UL << CAN_MCR_DBF_Pos)                    
#define CAN_MCR_DBF            CAN_MCR_DBF_Msk                               
/*******************  Bit definition for CAN_MSR register  ********************/
#define CAN_MSR_INAK_Pos       (0U)                                            
#define CAN_MSR_INAK_Msk       (0x1UL << CAN_MSR_INAK_Pos)                  
#define CAN_MSR_INAK           CAN_MSR_INAK_Msk                             
#define CAN_MSR_SLAK_Pos       (1U)                                         
#define CAN_MSR_SLAK_Msk       (0x1UL << CAN_MSR_SLAK_Pos)                  
#define CAN_MSR_SLAK           CAN_MSR_SLAK_Msk                             
#define CAN_MSR_ERRI_Pos       (2U)                                         
#define CAN_MSR_ERRI_Msk       (0x1UL << CAN_MSR_ERRI_Pos)                  
#define CAN_MSR_ERRI           CAN_MSR_ERRI_Msk                             
#define CAN_MSR_WKUI_Pos       (3U)                                         
#define CAN_MSR_WKUI_Msk       (0x1UL << CAN_MSR_WKUI_Pos)                  
#define CAN_MSR_WKUI           CAN_MSR_WKUI_Msk                             
#define CAN_MSR_SLAKI_Pos      (4U)                                         
#define CAN_MSR_SLAKI_Msk      (0x1UL << CAN_MSR_SLAKI_Pos)                 
#define CAN_MSR_SLAKI          CAN_MSR_SLAKI_Msk                            
#define CAN_MSR_TXM_Pos        (8U)                                         
#define CAN_MSR_TXM_Msk        (0x1UL << CAN_MSR_TXM_Pos)                   
#define CAN_MSR_TXM            CAN_MSR_TXM_Msk                              
#define CAN_MSR_RXM_Pos        (9U)                                         
#define CAN_MSR_RXM_Msk        (0x1UL << CAN_MSR_RXM_Pos)                   
#define CAN_MSR_RXM            CAN_MSR_RXM_Msk                              
#define CAN_MSR_SAMP_Pos       (10U)                                        
#define CAN_MSR_SAMP_Msk       (0x1UL << CAN_MSR_SAMP_Pos)                  
#define CAN_MSR_SAMP           CAN_MSR_SAMP_Msk                             
#define CAN_MSR_RX_Pos         (11U)                                        
#define CAN_MSR_RX_Msk         (0x1UL << CAN_MSR_RX_Pos)                    
#define CAN_MSR_RX             CAN_MSR_RX_Msk                               

/*******************  Bit definition for CAN_TSR register  ********************/
#define CAN_TSR_RQCP0_Pos      (0U)                                            
#define CAN_TSR_RQCP0_Msk      (0x1UL << CAN_TSR_RQCP0_Pos)                
#define CAN_TSR_RQCP0          CAN_TSR_RQCP0_Msk                           
#define CAN_TSR_TXOK0_Pos      (1U)                                        
#define CAN_TSR_TXOK0_Msk      (0x1UL << CAN_TSR_TXOK0_Pos)                
#define CAN_TSR_TXOK0          CAN_TSR_TXOK0_Msk                           
#define CAN_TSR_ALST0_Pos      (2U)                                        
#define CAN_TSR_ALST0_Msk      (0x1UL << CAN_TSR_ALST0_Pos)                
#define CAN_TSR_ALST0          CAN_TSR_ALST0_Msk                           
#define CAN_TSR_TERR0_Pos      (3U)                                        
#define CAN_TSR_TERR0_Msk      (0x1UL << CAN_TSR_TERR0_Pos)                
#define CAN_TSR_TERR0          CAN_TSR_TERR0_Msk                           
#define CAN_TSR_ABRQ0_Pos      (7U)                                        
#define CAN_TSR_ABRQ0_Msk      (0x1UL << CAN_TSR_ABRQ0_Pos)                
#define CAN_TSR_ABRQ0          CAN_TSR_ABRQ0_Msk                           
#define CAN_TSR_RQCP1_Pos      (8U)                                        
#define CAN_TSR_RQCP1_Msk      (0x1UL << CAN_TSR_RQCP1_Pos)                
#define CAN_TSR_RQCP1          CAN_TSR_RQCP1_Msk                           
#define CAN_TSR_TXOK1_Pos      (9U)                                        
#define CAN_TSR_TXOK1_Msk      (0x1UL << CAN_TSR_TXOK1_Pos)                
#define CAN_TSR_TXOK1          CAN_TSR_TXOK1_Msk                           
#define CAN_TSR_ALST1_Pos      (10U)                                       
#define CAN_TSR_ALST1_Msk      (0x1UL << CAN_TSR_ALST1_Pos)                
#define CAN_TSR_ALST1          CAN_TSR_ALST1_Msk                           
#define CAN_TSR_TERR1_Pos      (11U)                                       
#define CAN_TSR_TERR1_Msk      (0x1UL << CAN_TSR_TERR1_Pos)                
#define CAN_TSR_TERR1          CAN_TSR_TERR1_Msk                           
#define CAN_TSR_ABRQ1_Pos      (15U)                                       
#define CAN_TSR_ABRQ1_Msk      (0x1UL << CAN_TSR_ABRQ1_Pos)                
#define CAN_TSR_ABRQ1          CAN_TSR_ABRQ1_Msk                           
#define CAN_TSR_RQCP2_Pos      (16U)                                       
#define CAN_TSR_RQCP2_Msk      (0x1UL << CAN_TSR_RQCP2_Pos)                
#define CAN_TSR_RQCP2          CAN_TSR_RQCP2_Msk                           
#define CAN_TSR_TXOK2_Pos      (17U)                                       
#define CAN_TSR_TXOK2_Msk      (0x1UL << CAN_TSR_TXOK2_Pos)                
#define CAN_TSR_TXOK2          CAN_TSR_TXOK2_Msk                           
#define CAN_TSR_ALST2_Pos      (18U)                                       
#define CAN_TSR_ALST2_Msk      (0x1UL << CAN_TSR_ALST2_Pos)                
#define CAN_TSR_ALST2          CAN_TSR_ALST2_Msk                           
#define CAN_TSR_TERR2_Pos      (19U)                                       
#define CAN_TSR_TERR2_Msk      (0x1UL << CAN_TSR_TERR2_Pos)                
#define CAN_TSR_TERR2          CAN_TSR_TERR2_Msk                           
#define CAN_TSR_ABRQ2_Pos      (23U)                                       
#define CAN_TSR_ABRQ2_Msk      (0x1UL << CAN_TSR_ABRQ2_Pos)                
#define CAN_TSR_ABRQ2          CAN_TSR_ABRQ2_Msk                           
#define CAN_TSR_CODE_Pos       (24U)                                       
#define CAN_TSR_CODE_Msk       (0x3UL << CAN_TSR_CODE_Pos)                 
#define CAN_TSR_CODE           CAN_TSR_CODE_Msk                            

#define CAN_TSR_TME_Pos        (26U)                                       
#define CAN_TSR_TME_Msk        (0x7UL << CAN_TSR_TME_Pos)                  
#define CAN_TSR_TME            CAN_TSR_TME_Msk                             
#define CAN_TSR_TME0_Pos       (26U)                                       
#define CAN_TSR_TME0_Msk       (0x1UL << CAN_TSR_TME0_Pos)                 
#define CAN_TSR_TME0           CAN_TSR_TME0_Msk                            
#define CAN_TSR_TME1_Pos       (27U)                                       
#define CAN_TSR_TME1_Msk       (0x1UL << CAN_TSR_TME1_Pos)                 
#define CAN_TSR_TME1           CAN_TSR_TME1_Msk                            
#define CAN_TSR_TME2_Pos       (28U)                                       
#define CAN_TSR_TME2_Msk       (0x1UL << CAN_TSR_TME2_Pos)                 
#define CAN_TSR_TME2           CAN_TSR_TME2_Msk                            

#define CAN_TSR_LOW_Pos        (29U)                                       
#define CAN_TSR_LOW_Msk        (0x7UL << CAN_TSR_LOW_Pos)                  
#define CAN_TSR_LOW            CAN_TSR_LOW_Msk                             
#define CAN_TSR_LOW0_Pos       (29U)                                       
#define CAN_TSR_LOW0_Msk       (0x1UL << CAN_TSR_LOW0_Pos)                 
#define CAN_TSR_LOW0           CAN_TSR_LOW0_Msk                            
#define CAN_TSR_LOW1_Pos       (30U)                                       
#define CAN_TSR_LOW1_Msk       (0x1UL << CAN_TSR_LOW1_Pos)                 
#define CAN_TSR_LOW1           CAN_TSR_LOW1_Msk                            
#define CAN_TSR_LOW2_Pos       (31U)                                       
#define CAN_TSR_LOW2_Msk       (0x1UL << CAN_TSR_LOW2_Pos)                 
#define CAN_TSR_LOW2           CAN_TSR_LOW2_Msk                            

/*******************  Bit definition for CAN_RF0R register  *******************/
#define CAN_RF0R_FMP0_Pos      (0U)                                        
#define CAN_RF0R_FMP0_Msk      (0x3UL << CAN_RF0R_FMP0_Pos)                
#define CAN_RF0R_FMP0          CAN_RF0R_FMP0_Msk                           
#define CAN_RF0R_FULL0_Pos     (3U)                                        
#define CAN_RF0R_FULL0_Msk     (0x1UL << CAN_RF0R_FULL0_Pos)               
#define CAN_RF0R_FULL0         CAN_RF0R_FULL0_Msk                          
#define CAN_RF0R_FOVR0_Pos     (4U)                                        
#define CAN_RF0R_FOVR0_Msk     (0x1UL << CAN_RF0R_FOVR0_Pos)               
#define CAN_RF0R_FOVR0         CAN_RF0R_FOVR0_Msk                          
#define CAN_RF0R_RFOM0_Pos     (5U)                                        
#define CAN_RF0R_RFOM0_Msk     (0x1UL << CAN_RF0R_RFOM0_Pos)               
#define CAN_RF0R_RFOM0         CAN_RF0R_RFOM0_Msk                          

/*******************  Bit definition for CAN_RF1R register  *******************/
#define CAN_RF1R_FMP1_Pos      (0U)                                           
#define CAN_RF1R_FMP1_Msk      (0x3UL << CAN_RF1R_FMP1_Pos)                   
#define CAN_RF1R_FMP1          CAN_RF1R_FMP1_Msk                              
#define CAN_RF1R_FULL1_Pos     (3U)                                           
#define CAN_RF1R_FULL1_Msk     (0x1UL << CAN_RF1R_FULL1_Pos)                  
#define CAN_RF1R_FULL1         CAN_RF1R_FULL1_Msk                             
#define CAN_RF1R_FOVR1_Pos     (4U)                                           
#define CAN_RF1R_FOVR1_Msk     (0x1UL << CAN_RF1R_FOVR1_Pos)                  
#define CAN_RF1R_FOVR1         CAN_RF1R_FOVR1_Msk                             
#define CAN_RF1R_RFOM1_Pos     (5U)                                           
#define CAN_RF1R_RFOM1_Msk     (0x1UL << CAN_RF1R_RFOM1_Pos)                  
#define CAN_RF1R_RFOM1         CAN_RF1R_RFOM1_Msk                             

/********************  Bit definition for CAN_IER register  *******************/
#define CAN_IER_TMEIE_Pos      (0U)                                            
#define CAN_IER_TMEIE_Msk      (0x1UL << CAN_IER_TMEIE_Pos)                     
#define CAN_IER_TMEIE          CAN_IER_TMEIE_Msk                           
#define CAN_IER_FMPIE0_Pos     (1U)                                        
#define CAN_IER_FMPIE0_Msk     (0x1UL << CAN_IER_FMPIE0_Pos)               
#define CAN_IER_FMPIE0         CAN_IER_FMPIE0_Msk                          
#define CAN_IER_FFIE0_Pos      (2U)                                        
#define CAN_IER_FFIE0_Msk      (0x1UL << CAN_IER_FFIE0_Pos)                
#define CAN_IER_FFIE0          CAN_IER_FFIE0_Msk                           
#define CAN_IER_FOVIE0_Pos     (3U)                                        
#define CAN_IER_FOVIE0_Msk     (0x1UL << CAN_IER_FOVIE0_Pos)               
#define CAN_IER_FOVIE0         CAN_IER_FOVIE0_Msk                          
#define CAN_IER_FMPIE1_Pos     (4U)                                        
#define CAN_IER_FMPIE1_Msk     (0x1UL << CAN_IER_FMPIE1_Pos)               
#define CAN_IER_FMPIE1         CAN_IER_FMPIE1_Msk                          
#define CAN_IER_FFIE1_Pos      (5U)                                        
#define CAN_IER_FFIE1_Msk      (0x1UL << CAN_IER_FFIE1_Pos)                
#define CAN_IER_FFIE1          CAN_IER_FFIE1_Msk                           
#define CAN_IER_FOVIE1_Pos     (6U)                                        
#define CAN_IER_FOVIE1_Msk     (0x1UL << CAN_IER_FOVIE1_Pos)               
#define CAN_IER_FOVIE1         CAN_IER_FOVIE1_Msk                          
#define CAN_IER_EWGIE_Pos      (8U)                                        
#define CAN_IER_EWGIE_Msk      (0x1UL << CAN_IER_EWGIE_Pos)                
#define CAN_IER_EWGIE          CAN_IER_EWGIE_Msk                           
#define CAN_IER_EPVIE_Pos      (9U)                                        
#define CAN_IER_EPVIE_Msk      (0x1UL << CAN_IER_EPVIE_Pos)                
#define CAN_IER_EPVIE          CAN_IER_EPVIE_Msk                           
#define CAN_IER_BOFIE_Pos      (10U)                                       
#define CAN_IER_BOFIE_Msk      (0x1UL << CAN_IER_BOFIE_Pos)                
#define CAN_IER_BOFIE          CAN_IER_BOFIE_Msk                           
#define CAN_IER_LECIE_Pos      (11U)                                       
#define CAN_IER_LECIE_Msk      (0x1UL << CAN_IER_LECIE_Pos)                
#define CAN_IER_LECIE          CAN_IER_LECIE_Msk                           
#define CAN_IER_ERRIE_Pos      (15U)                                       
#define CAN_IER_ERRIE_Msk      (0x1UL << CAN_IER_ERRIE_Pos)                
#define CAN_IER_ERRIE          CAN_IER_ERRIE_Msk                           
#define CAN_IER_WKUIE_Pos      (16U)                                       
#define CAN_IER_WKUIE_Msk      (0x1UL << CAN_IER_WKUIE_Pos)                
#define CAN_IER_WKUIE          CAN_IER_WKUIE_Msk                           
#define CAN_IER_SLKIE_Pos      (17U)                                       
#define CAN_IER_SLKIE_Msk      (0x1UL << CAN_IER_SLKIE_Pos)                
#define CAN_IER_SLKIE          CAN_IER_SLKIE_Msk                           
#define CAN_IER_EWGIE_Pos      (8U)                                            

/********************  Bit definition for CAN_ESR register  *******************/
#define CAN_ESR_EWGF_Pos       (0U)                                            
#define CAN_ESR_EWGF_Msk       (0x1UL << CAN_ESR_EWGF_Pos)                  
#define CAN_ESR_EWGF           CAN_ESR_EWGF_Msk                             
#define CAN_ESR_EPVF_Pos       (1U)                                         
#define CAN_ESR_EPVF_Msk       (0x1UL << CAN_ESR_EPVF_Pos)                  
#define CAN_ESR_EPVF           CAN_ESR_EPVF_Msk                             
#define CAN_ESR_BOFF_Pos       (2U)                                         
#define CAN_ESR_BOFF_Msk       (0x1UL << CAN_ESR_BOFF_Pos)                  
#define CAN_ESR_BOFF           CAN_ESR_BOFF_Msk                             

#define CAN_ESR_LEC_Pos        (4U)                                         
#define CAN_ESR_LEC_Msk        (0x7UL << CAN_ESR_LEC_Pos)                   
#define CAN_ESR_LEC            CAN_ESR_LEC_Msk                              
#define CAN_ESR_LEC_0          (0x1UL << CAN_ESR_LEC_Pos)                   
#define CAN_ESR_LEC_1          (0x2UL << CAN_ESR_LEC_Pos)                   
#define CAN_ESR_LEC_2          (0x4UL << CAN_ESR_LEC_Pos)                   

#define CAN_ESR_TEC_Pos        (16U)                                        
#define CAN_ESR_TEC_Msk        (0xFFUL << CAN_ESR_TEC_Pos)                  
#define CAN_ESR_TEC            CAN_ESR_TEC_Msk                              
#define CAN_ESR_REC_Pos        (24U)                                        
#define CAN_ESR_REC_Msk        (0xFFUL << CAN_ESR_REC_Pos)                  
#define CAN_ESR_REC            CAN_ESR_REC_Msk                              

/*******************  Bit definition for CAN_BTR register  ********************/
#define CAN_BTR_BRP_Pos        (0U)                                            
#define CAN_BTR_BRP_Msk        (0x3FFUL << CAN_BTR_BRP_Pos)                 
#define CAN_BTR_BRP            CAN_BTR_BRP_Msk                              
#define CAN_BTR_TS1_Pos        (16U)                                        
#define CAN_BTR_TS1_Msk        (0xFUL << CAN_BTR_TS1_Pos)                   
#define CAN_BTR_TS1            CAN_BTR_TS1_Msk                              
#define CAN_BTR_TS1_0          (0x1UL << CAN_BTR_TS1_Pos)                   
#define CAN_BTR_TS1_1          (0x2UL << CAN_BTR_TS1_Pos)                   
#define CAN_BTR_TS1_2          (0x4UL << CAN_BTR_TS1_Pos)                   
#define CAN_BTR_TS1_3          (0x8UL << CAN_BTR_TS1_Pos)                   
#define CAN_BTR_TS2_Pos        (20U)                                        
#define CAN_BTR_TS2_Msk        (0x7UL << CAN_BTR_TS2_Pos)                   
#define CAN_BTR_TS2            CAN_BTR_TS2_Msk                              
#define CAN_BTR_TS2_0          (0x1UL << CAN_BTR_TS2_Pos)                   
#define CAN_BTR_TS2_1          (0x2UL << CAN_BTR_TS2_Pos)                   
#define CAN_BTR_TS2_2          (0x4UL << CAN_BTR_TS2_Pos)                   
#define CAN_BTR_SJW_Pos        (24U)                                        
#define CAN_BTR_SJW_Msk        (0x3UL << CAN_BTR_SJW_Pos)                   
#define CAN_BTR_SJW            CAN_BTR_SJW_Msk                              
#define CAN_BTR_SJW_0          (0x1UL << CAN_BTR_SJW_Pos)                   
#define CAN_BTR_SJW_1          (0x2UL << CAN_BTR_SJW_Pos)                   
#define CAN_BTR_LBKM_Pos       (30U)                                        
#define CAN_BTR_LBKM_Msk       (0x1UL << CAN_BTR_LBKM_Pos)                  
#define CAN_BTR_LBKM           CAN_BTR_LBKM_Msk                             
#define CAN_BTR_SILM_Pos       (31U)                                        
#define CAN_BTR_SILM_Msk       (0x1UL << CAN_BTR_SILM_Pos)                  
#define CAN_BTR_SILM           CAN_BTR_SILM_Msk                             


/*Mailbox registers */
/******************  Bit definition for CAN_TI0R register  ********************/
#define CAN_TI0R_TXRQ_Pos      (0U)                                            
#define CAN_TI0R_TXRQ_Msk      (0x1UL << CAN_TI0R_TXRQ_Pos)               
#define CAN_TI0R_TXRQ          CAN_TI0R_TXRQ_Msk                          
#define CAN_TI0R_RTR_Pos       (1U)                                       
#define CAN_TI0R_RTR_Msk       (0x1UL << CAN_TI0R_RTR_Pos)                
#define CAN_TI0R_RTR           CAN_TI0R_RTR_Msk                           
#define CAN_TI0R_IDE_Pos       (2U)                                       
#define CAN_TI0R_IDE_Msk       (0x1UL << CAN_TI0R_IDE_Pos)                
#define CAN_TI0R_IDE           CAN_TI0R_IDE_Msk                           
#define CAN_TI0R_EXID_Pos      (3U)                                       
#define CAN_TI0R_EXID_Msk      (0x3FFFFUL << CAN_TI0R_EXID_Pos)           
#define CAN_TI0R_EXID          CAN_TI0R_EXID_Msk                          
#define CAN_TI0R_STID_Pos      (21U)                                      
#define CAN_TI0R_STID_Msk      (0x7FFUL << CAN_TI0R_STID_Pos)             
#define CAN_TI0R_STID          CAN_TI0R_STID_Msk                          

/******************  Bit definition for CAN_TDT0R register  *******************/
#define CAN_TDT0R_DLC_Pos      (0U)                                         
#define CAN_TDT0R_DLC_Msk      (0xFUL << CAN_TDT0R_DLC_Pos)                 
#define CAN_TDT0R_DLC          CAN_TDT0R_DLC_Msk                            
#define CAN_TDT0R_TGT_Pos      (8U)                                         
#define CAN_TDT0R_TGT_Msk      (0x1UL << CAN_TDT0R_TGT_Pos)                 
#define CAN_TDT0R_TGT          CAN_TDT0R_TGT_Msk                            
#define CAN_TDT0R_TIME_Pos     (16U)                                        
#define CAN_TDT0R_TIME_Msk     (0xFFFFUL << CAN_TDT0R_TIME_Pos)             
#define CAN_TDT0R_TIME         CAN_TDT0R_TIME_Msk                           

/******************  Bit definition for CAN_TDL0R register  *******************/
#define CAN_TDL0R_DATA0_Pos    (0U)                                            
#define CAN_TDL0R_DATA0_Msk    (0xFFUL << CAN_TDL0R_DATA0_Pos)            
#define CAN_TDL0R_DATA0        CAN_TDL0R_DATA0_Msk                        
#define CAN_TDL0R_DATA1_Pos    (8U)                                       
#define CAN_TDL0R_DATA1_Msk    (0xFFUL << CAN_TDL0R_DATA1_Pos)            
#define CAN_TDL0R_DATA1        CAN_TDL0R_DATA1_Msk                        
#define CAN_TDL0R_DATA2_Pos    (16U)                                      
#define CAN_TDL0R_DATA2_Msk    (0xFFUL << CAN_TDL0R_DATA2_Pos)            
#define CAN_TDL0R_DATA2        CAN_TDL0R_DATA2_Msk                        
#define CAN_TDL0R_DATA3_Pos    (24U)                                      
#define CAN_TDL0R_DATA3_Msk    (0xFFUL << CAN_TDL0R_DATA3_Pos)            
#define CAN_TDL0R_DATA3        CAN_TDL0R_DATA3_Msk                        

/******************  Bit definition for CAN_TDH0R register  *******************/
#define CAN_TDH0R_DATA4_Pos    (0U)                                         
#define CAN_TDH0R_DATA4_Msk    (0xFFUL << CAN_TDH0R_DATA4_Pos)              
#define CAN_TDH0R_DATA4        CAN_TDH0R_DATA4_Msk                          
#define CAN_TDH0R_DATA5_Pos    (8U)                                         
#define CAN_TDH0R_DATA5_Msk    (0xFFUL << CAN_TDH0R_DATA5_Pos)              
#define CAN_TDH0R_DATA5        CAN_TDH0R_DATA5_Msk                          
#define CAN_TDH0R_DATA6_Pos    (16U)                                        
#define CAN_TDH0R_DATA6_Msk    (0xFFUL << CAN_TDH0R_DATA6_Pos)              
#define CAN_TDH0R_DATA6        CAN_TDH0R_DATA6_Msk                          
#define CAN_TDH0R_DATA7_Pos    (24U)                                        
#define CAN_TDH0R_DATA7_Msk    (0xFFUL << CAN_TDH0R_DATA7_Pos)              
#define CAN_TDH0R_DATA7        CAN_TDH0R_DATA7_Msk                          

/*******************  Bit definition for CAN_TI1R register  *******************/
#define CAN_TI1R_TXRQ_Pos      (0U)                                            
#define CAN_TI1R_TXRQ_Msk      (0x1UL << CAN_TI1R_TXRQ_Pos)                  
#define CAN_TI1R_TXRQ          CAN_TI1R_TXRQ_Msk                             
#define CAN_TI1R_RTR_Pos       (1U)                                          
#define CAN_TI1R_RTR_Msk       (0x1UL << CAN_TI1R_RTR_Pos)                   
#define CAN_TI1R_RTR           CAN_TI1R_RTR_Msk                              
#define CAN_TI1R_IDE_Pos       (2U)                                          
#define CAN_TI1R_IDE_Msk       (0x1UL << CAN_TI1R_IDE_Pos)                   
#define CAN_TI1R_IDE           CAN_TI1R_IDE_Msk                              
#define CAN_TI1R_EXID_Pos      (3U)                                          
#define CAN_TI1R_EXID_Msk      (0x3FFFFUL << CAN_TI1R_EXID_Pos)              
#define CAN_TI1R_EXID          CAN_TI1R_EXID_Msk                             
#define CAN_TI1R_STID_Pos      (21U)                                         
#define CAN_TI1R_STID_Msk      (0x7FFUL << CAN_TI1R_STID_Pos)                
#define CAN_TI1R_STID          CAN_TI1R_STID_Msk                             

/*******************  Bit definition for CAN_TDT1R register  ******************/
#define CAN_TDT1R_DLC_Pos      (0U)                                            
#define CAN_TDT1R_DLC_Msk      (0xFUL << CAN_TDT1R_DLC_Pos)                  
#define CAN_TDT1R_DLC          CAN_TDT1R_DLC_Msk                             
#define CAN_TDT1R_TGT_Pos      (8U)                                          
#define CAN_TDT1R_TGT_Msk      (0x1UL << CAN_TDT1R_TGT_Pos)                  
#define CAN_TDT1R_TGT          CAN_TDT1R_TGT_Msk                             
#define CAN_TDT1R_TIME_Pos     (16U)                                         
#define CAN_TDT1R_TIME_Msk     (0xFFFFUL << CAN_TDT1R_TIME_Pos)              
#define CAN_TDT1R_TIME         CAN_TDT1R_TIME_Msk                            

/*******************  Bit definition for CAN_TDL1R register  ******************/
#define CAN_TDL1R_DATA0_Pos    (0U)                                            
#define CAN_TDL1R_DATA0_Msk    (0xFFUL << CAN_TDL1R_DATA0_Pos)                
#define CAN_TDL1R_DATA0        CAN_TDL1R_DATA0_Msk                            
#define CAN_TDL1R_DATA1_Pos    (8U)                                           
#define CAN_TDL1R_DATA1_Msk    (0xFFUL << CAN_TDL1R_DATA1_Pos)                
#define CAN_TDL1R_DATA1        CAN_TDL1R_DATA1_Msk                            
#define CAN_TDL1R_DATA2_Pos    (16U)                                          
#define CAN_TDL1R_DATA2_Msk    (0xFFUL << CAN_TDL1R_DATA2_Pos)                
#define CAN_TDL1R_DATA2        CAN_TDL1R_DATA2_Msk                            
#define CAN_TDL1R_DATA3_Pos    (24U)                                          
#define CAN_TDL1R_DATA3_Msk    (0xFFUL << CAN_TDL1R_DATA3_Pos)                
#define CAN_TDL1R_DATA3        CAN_TDL1R_DATA3_Msk                            

/*******************  Bit definition for CAN_TDH1R register  ******************/
#define CAN_TDH1R_DATA4_Pos    (0U)                                            
#define CAN_TDH1R_DATA4_Msk    (0xFFUL << CAN_TDH1R_DATA4_Pos)               
#define CAN_TDH1R_DATA4        CAN_TDH1R_DATA4_Msk                           
#define CAN_TDH1R_DATA5_Pos    (8U)                                          
#define CAN_TDH1R_DATA5_Msk    (0xFFUL << CAN_TDH1R_DATA5_Pos)               
#define CAN_TDH1R_DATA5        CAN_TDH1R_DATA5_Msk                           
#define CAN_TDH1R_DATA6_Pos    (16U)                                         
#define CAN_TDH1R_DATA6_Msk    (0xFFUL << CAN_TDH1R_DATA6_Pos)               
#define CAN_TDH1R_DATA6        CAN_TDH1R_DATA6_Msk                           
#define CAN_TDH1R_DATA7_Pos    (24U)                                         
#define CAN_TDH1R_DATA7_Msk    (0xFFUL << CAN_TDH1R_DATA7_Pos)               
#define CAN_TDH1R_DATA7        CAN_TDH1R_DATA7_Msk                           

/*******************  Bit definition for CAN_TI2R register  *******************/
#define CAN_TI2R_TXRQ_Pos      (0U)                                            
#define CAN_TI2R_TXRQ_Msk      (0x1UL << CAN_TI2R_TXRQ_Pos)                 
#define CAN_TI2R_TXRQ          CAN_TI2R_TXRQ_Msk                            
#define CAN_TI2R_RTR_Pos       (1U)                                         
#define CAN_TI2R_RTR_Msk       (0x1UL << CAN_TI2R_RTR_Pos)                  
#define CAN_TI2R_RTR           CAN_TI2R_RTR_Msk                             
#define CAN_TI2R_IDE_Pos       (2U)                                         
#define CAN_TI2R_IDE_Msk       (0x1UL << CAN_TI2R_IDE_Pos)                  
#define CAN_TI2R_IDE           CAN_TI2R_IDE_Msk                             
#define CAN_TI2R_EXID_Pos      (3U)                                         
#define CAN_TI2R_EXID_Msk      (0x3FFFFUL << CAN_TI2R_EXID_Pos)             
#define CAN_TI2R_EXID          CAN_TI2R_EXID_Msk                            
#define CAN_TI2R_STID_Pos      (21U)                                        
#define CAN_TI2R_STID_Msk      (0x7FFUL << CAN_TI2R_STID_Pos)               
#define CAN_TI2R_STID          CAN_TI2R_STID_Msk                            

/*******************  Bit definition for CAN_TDT2R register  ******************/  
#define CAN_TDT2R_DLC_Pos      (0U)                                            
#define CAN_TDT2R_DLC_Msk      (0xFUL << CAN_TDT2R_DLC_Pos)                  
#define CAN_TDT2R_DLC          CAN_TDT2R_DLC_Msk                             
#define CAN_TDT2R_TGT_Pos      (8U)                                          
#define CAN_TDT2R_TGT_Msk      (0x1UL << CAN_TDT2R_TGT_Pos)                  
#define CAN_TDT2R_TGT          CAN_TDT2R_TGT_Msk                             
#define CAN_TDT2R_TIME_Pos     (16U)                                         
#define CAN_TDT2R_TIME_Msk     (0xFFFFUL << CAN_TDT2R_TIME_Pos)              
#define CAN_TDT2R_TIME         CAN_TDT2R_TIME_Msk                            

/*******************  Bit definition for CAN_TDL2R register  ******************/
#define CAN_TDL2R_DATA0_Pos    (0U)                                            
#define CAN_TDL2R_DATA0_Msk    (0xFFUL << CAN_TDL2R_DATA0_Pos)              
#define CAN_TDL2R_DATA0        CAN_TDL2R_DATA0_Msk                          
#define CAN_TDL2R_DATA1_Pos    (8U)                                         
#define CAN_TDL2R_DATA1_Msk    (0xFFUL << CAN_TDL2R_DATA1_Pos)              
#define CAN_TDL2R_DATA1        CAN_TDL2R_DATA1_Msk                          
#define CAN_TDL2R_DATA2_Pos    (16U)                                        
#define CAN_TDL2R_DATA2_Msk    (0xFFUL << CAN_TDL2R_DATA2_Pos)              
#define CAN_TDL2R_DATA2        CAN_TDL2R_DATA2_Msk                          
#define CAN_TDL2R_DATA3_Pos    (24U)                                        
#define CAN_TDL2R_DATA3_Msk    (0xFFUL << CAN_TDL2R_DATA3_Pos)              
#define CAN_TDL2R_DATA3        CAN_TDL2R_DATA3_Msk                          

/*******************  Bit definition for CAN_TDH2R register  ******************/
#define CAN_TDH2R_DATA4_Pos    (0U)                                            
#define CAN_TDH2R_DATA4_Msk    (0xFFUL << CAN_TDH2R_DATA4_Pos)                
#define CAN_TDH2R_DATA4        CAN_TDH2R_DATA4_Msk                            
#define CAN_TDH2R_DATA5_Pos    (8U)                                           
#define CAN_TDH2R_DATA5_Msk    (0xFFUL << CAN_TDH2R_DATA5_Pos)                
#define CAN_TDH2R_DATA5        CAN_TDH2R_DATA5_Msk                            
#define CAN_TDH2R_DATA6_Pos    (16U)                                          
#define CAN_TDH2R_DATA6_Msk    (0xFFUL << CAN_TDH2R_DATA6_Pos)                
#define CAN_TDH2R_DATA6        CAN_TDH2R_DATA6_Msk                            
#define CAN_TDH2R_DATA7_Pos    (24U)                                          
#define CAN_TDH2R_DATA7_Msk    (0xFFUL << CAN_TDH2R_DATA7_Pos)                
#define CAN_TDH2R_DATA7        CAN_TDH2R_DATA7_Msk                            

/*******************  Bit definition for CAN_RI0R register  *******************/
#define CAN_RI0R_RTR_Pos       (1U)                                            
#define CAN_RI0R_RTR_Msk       (0x1UL << CAN_RI0R_RTR_Pos)                      
#define CAN_RI0R_RTR           CAN_RI0R_RTR_Msk                              
#define CAN_RI0R_IDE_Pos       (2U)                                          
#define CAN_RI0R_IDE_Msk       (0x1UL << CAN_RI0R_IDE_Pos)                   
#define CAN_RI0R_IDE           CAN_RI0R_IDE_Msk                              
#define CAN_RI0R_EXID_Pos      (3U)                                          
#define CAN_RI0R_EXID_Msk      (0x3FFFFUL << CAN_RI0R_EXID_Pos)              
#define CAN_RI0R_EXID          CAN_RI0R_EXID_Msk                             
#define CAN_RI0R_STID_Pos      (21U)                                         
#define CAN_RI0R_STID_Msk      (0x7FFUL << CAN_RI0R_STID_Pos)                
#define CAN_RI0R_STID          CAN_RI0R_STID_Msk                             

/*******************  Bit definition for CAN_RDT0R register  ******************/
#define CAN_RDT0R_DLC_Pos      (0U)                                            
#define CAN_RDT0R_DLC_Msk      (0xFUL << CAN_RDT0R_DLC_Pos)                  
#define CAN_RDT0R_DLC          CAN_RDT0R_DLC_Msk                             
#define CAN_RDT0R_FMI_Pos      (8U)                                          
#define CAN_RDT0R_FMI_Msk      (0xFFUL << CAN_RDT0R_FMI_Pos)                 
#define CAN_RDT0R_FMI          CAN_RDT0R_FMI_Msk                             
#define CAN_RDT0R_TIME_Pos     (16U)                                         
#define CAN_RDT0R_TIME_Msk     (0xFFFFUL << CAN_RDT0R_TIME_Pos)              
#define CAN_RDT0R_TIME         CAN_RDT0R_TIME_Msk                            

/*******************  Bit definition for CAN_RDL0R register  ******************/
#define CAN_RDL0R_DATA0_Pos    (0U)                                            
#define CAN_RDL0R_DATA0_Msk    (0xFFUL << CAN_RDL0R_DATA0_Pos)             
#define CAN_RDL0R_DATA0        CAN_RDL0R_DATA0_Msk                         
#define CAN_RDL0R_DATA1_Pos    (8U)                                        
#define CAN_RDL0R_DATA1_Msk    (0xFFUL << CAN_RDL0R_DATA1_Pos)             
#define CAN_RDL0R_DATA1        CAN_RDL0R_DATA1_Msk                         
#define CAN_RDL0R_DATA2_Pos    (16U)                                       
#define CAN_RDL0R_DATA2_Msk    (0xFFUL << CAN_RDL0R_DATA2_Pos)             
#define CAN_RDL0R_DATA2        CAN_RDL0R_DATA2_Msk                         
#define CAN_RDL0R_DATA3_Pos    (24U)                                       
#define CAN_RDL0R_DATA3_Msk    (0xFFUL << CAN_RDL0R_DATA3_Pos)             
#define CAN_RDL0R_DATA3        CAN_RDL0R_DATA3_Msk                         

/*******************  Bit definition for CAN_RDH0R register  ******************/
#define CAN_RDH0R_DATA4_Pos    (0U)                                            
#define CAN_RDH0R_DATA4_Msk    (0xFFUL << CAN_RDH0R_DATA4_Pos)               
#define CAN_RDH0R_DATA4        CAN_RDH0R_DATA4_Msk                           
#define CAN_RDH0R_DATA5_Pos    (8U)                                          
#define CAN_RDH0R_DATA5_Msk    (0xFFUL << CAN_RDH0R_DATA5_Pos)               
#define CAN_RDH0R_DATA5        CAN_RDH0R_DATA5_Msk                           
#define CAN_RDH0R_DATA6_Pos    (16U)                                         
#define CAN_RDH0R_DATA6_Msk    (0xFFUL << CAN_RDH0R_DATA6_Pos)               
#define CAN_RDH0R_DATA6        CAN_RDH0R_DATA6_Msk                           
#define CAN_RDH0R_DATA7_Pos    (24U)                                         
#define CAN_RDH0R_DATA7_Msk    (0xFFUL << CAN_RDH0R_DATA7_Pos)               
#define CAN_RDH0R_DATA7        CAN_RDH0R_DATA7_Msk                           

/*******************  Bit definition for CAN_RI1R register  *******************/
#define CAN_RI1R_RTR_Pos       (1U)                                            
#define CAN_RI1R_RTR_Msk       (0x1UL << CAN_RI1R_RTR_Pos)                      
#define CAN_RI1R_RTR           CAN_RI1R_RTR_Msk                              
#define CAN_RI1R_IDE_Pos       (2U)                                          
#define CAN_RI1R_IDE_Msk       (0x1UL << CAN_RI1R_IDE_Pos)                   
#define CAN_RI1R_IDE           CAN_RI1R_IDE_Msk                              
#define CAN_RI1R_EXID_Pos      (3U)                                          
#define CAN_RI1R_EXID_Msk      (0x3FFFFUL << CAN_RI1R_EXID_Pos)              
#define CAN_RI1R_EXID          CAN_RI1R_EXID_Msk                             
#define CAN_RI1R_STID_Pos      (21U)                                         
#define CAN_RI1R_STID_Msk      (0x7FFUL << CAN_RI1R_STID_Pos)                
#define CAN_RI1R_STID          CAN_RI1R_STID_Msk                             

/*******************  Bit definition for CAN_RDT1R register  ******************/
#define CAN_RDT1R_DLC_Pos      (0U)                                         
#define CAN_RDT1R_DLC_Msk      (0xFUL << CAN_RDT1R_DLC_Pos)                 
#define CAN_RDT1R_DLC          CAN_RDT1R_DLC_Msk                            
#define CAN_RDT1R_FMI_Pos      (8U)                                         
#define CAN_RDT1R_FMI_Msk      (0xFFUL << CAN_RDT1R_FMI_Pos)                
#define CAN_RDT1R_FMI          CAN_RDT1R_FMI_Msk                            
#define CAN_RDT1R_TIME_Pos     (16U)                                        
#define CAN_RDT1R_TIME_Msk     (0xFFFFUL << CAN_RDT1R_TIME_Pos)             
#define CAN_RDT1R_TIME         CAN_RDT1R_TIME_Msk                           

/*******************  Bit definition for CAN_RDL1R register  ******************/
#define CAN_RDL1R_DATA0_Pos    (0U)                                            
#define CAN_RDL1R_DATA0_Msk    (0xFFUL << CAN_RDL1R_DATA0_Pos)                 
#define CAN_RDL1R_DATA0        CAN_RDL1R_DATA0_Msk                             
#define CAN_RDL1R_DATA1_Pos    (8U)                                           
#define CAN_RDL1R_DATA1_Msk    (0xFFUL << CAN_RDL1R_DATA1_Pos)                 
#define CAN_RDL1R_DATA1        CAN_RDL1R_DATA1_Msk                             
#define CAN_RDL1R_DATA2_Pos    (16U)                                          
#define CAN_RDL1R_DATA2_Msk    (0xFFUL << CAN_RDL1R_DATA2_Pos)                 
#define CAN_RDL1R_DATA2        CAN_RDL1R_DATA2_Msk                             
#define CAN_RDL1R_DATA3_Pos    (24U)                                          
#define CAN_RDL1R_DATA3_Msk    (0xFFUL << CAN_RDL1R_DATA3_Pos)                 
#define CAN_RDL1R_DATA3        CAN_RDL1R_DATA3_Msk                             

/*******************  Bit definition for CAN_RDH1R register  ******************/
#define CAN_RDH1R_DATA4_Pos    (0U)                                            
#define CAN_RDH1R_DATA4_Msk    (0xFFUL << CAN_RDH1R_DATA4_Pos)                
#define CAN_RDH1R_DATA4        CAN_RDH1R_DATA4_Msk                            
#define CAN_RDH1R_DATA5_Pos    (8U)                                          
#define CAN_RDH1R_DATA5_Msk    (0xFFUL << CAN_RDH1R_DATA5_Pos)                
#define CAN_RDH1R_DATA5        CAN_RDH1R_DATA5_Msk                            
#define CAN_RDH1R_DATA6_Pos    (16U)                                         
#define CAN_RDH1R_DATA6_Msk    (0xFFUL << CAN_RDH1R_DATA6_Pos)                
#define CAN_RDH1R_DATA6        CAN_RDH1R_DATA6_Msk                            
#define CAN_RDH1R_DATA7_Pos    (24U)                                         
#define CAN_RDH1R_DATA7_Msk    (0xFFUL << CAN_RDH1R_DATA7_Pos)                
#define CAN_RDH1R_DATA7        CAN_RDH1R_DATA7_Msk                            

/*CAN filter registers */
/*******************  Bit definition for CAN_FMR register  ********************/
#define CAN_FMR_FINIT_Pos      (0U)                                            
#define CAN_FMR_FINIT_Msk      (0x1UL << CAN_FMR_FINIT_Pos)                   
#define CAN_FMR_FINIT          CAN_FMR_FINIT_Msk                              
#define CAN_FMR_CAN2SB_Pos     (8U)                                           
#define CAN_FMR_CAN2SB_Msk     (0x3FUL << CAN_FMR_CAN2SB_Pos)                 
#define CAN_FMR_CAN2SB         CAN_FMR_CAN2SB_Msk                             

/*******************  Bit definition for CAN_FM1R register  *******************/
#define CAN_FM1R_FBM_Pos       (0U)                                            
#define CAN_FM1R_FBM_Msk       (0xFFFFFFFUL << CAN_FM1R_FBM_Pos)             
#define CAN_FM1R_FBM           CAN_FM1R_FBM_Msk                              
#define CAN_FM1R_FBM0_Pos      (0U)                                          
#define CAN_FM1R_FBM0_Msk      (0x1UL << CAN_FM1R_FBM0_Pos)                  
#define CAN_FM1R_FBM0          CAN_FM1R_FBM0_Msk                             
#define CAN_FM1R_FBM1_Pos      (1U)                                          
#define CAN_FM1R_FBM1_Msk      (0x1UL << CAN_FM1R_FBM1_Pos)                  
#define CAN_FM1R_FBM1          CAN_FM1R_FBM1_Msk                             
#define CAN_FM1R_FBM2_Pos      (2U)                                          
#define CAN_FM1R_FBM2_Msk      (0x1UL << CAN_FM1R_FBM2_Pos)                  
#define CAN_FM1R_FBM2          CAN_FM1R_FBM2_Msk                             
#define CAN_FM1R_FBM3_Pos      (3U)                                          
#define CAN_FM1R_FBM3_Msk      (0x1UL << CAN_FM1R_FBM3_Pos)                  
#define CAN_FM1R_FBM3          CAN_FM1R_FBM3_Msk                             
#define CAN_FM1R_FBM4_Pos      (4U)                                          
#define CAN_FM1R_FBM4_Msk      (0x1UL << CAN_FM1R_FBM4_Pos)                  
#define CAN_FM1R_FBM4          CAN_FM1R_FBM4_Msk                             
#define CAN_FM1R_FBM5_Pos      (5U)                                          
#define CAN_FM1R_FBM5_Msk      (0x1UL << CAN_FM1R_FBM5_Pos)                  
#define CAN_FM1R_FBM5          CAN_FM1R_FBM5_Msk                             
#define CAN_FM1R_FBM6_Pos      (6U)                                          
#define CAN_FM1R_FBM6_Msk      (0x1UL << CAN_FM1R_FBM6_Pos)                  
#define CAN_FM1R_FBM6          CAN_FM1R_FBM6_Msk                             
#define CAN_FM1R_FBM7_Pos      (7U)                                          
#define CAN_FM1R_FBM7_Msk      (0x1UL << CAN_FM1R_FBM7_Pos)                  
#define CAN_FM1R_FBM7          CAN_FM1R_FBM7_Msk                             
#define CAN_FM1R_FBM8_Pos      (8U)                                          
#define CAN_FM1R_FBM8_Msk      (0x1UL << CAN_FM1R_FBM8_Pos)                  
#define CAN_FM1R_FBM8          CAN_FM1R_FBM8_Msk                             
#define CAN_FM1R_FBM9_Pos      (9U)                                          
#define CAN_FM1R_FBM9_Msk      (0x1UL << CAN_FM1R_FBM9_Pos)                  
#define CAN_FM1R_FBM9          CAN_FM1R_FBM9_Msk                             
#define CAN_FM1R_FBM10_Pos     (10U)                                         
#define CAN_FM1R_FBM10_Msk     (0x1UL << CAN_FM1R_FBM10_Pos)                 
#define CAN_FM1R_FBM10         CAN_FM1R_FBM10_Msk                            
#define CAN_FM1R_FBM11_Pos     (11U)                                         
#define CAN_FM1R_FBM11_Msk     (0x1UL << CAN_FM1R_FBM11_Pos)                 
#define CAN_FM1R_FBM11         CAN_FM1R_FBM11_Msk                            
#define CAN_FM1R_FBM12_Pos     (12U)                                         
#define CAN_FM1R_FBM12_Msk     (0x1UL << CAN_FM1R_FBM12_Pos)                
#define CAN_FM1R_FBM12         CAN_FM1R_FBM12_Msk                           
#define CAN_FM1R_FBM13_Pos     (13U)                                        
#define CAN_FM1R_FBM13_Msk     (0x1UL << CAN_FM1R_FBM13_Pos)                
#define CAN_FM1R_FBM13         CAN_FM1R_FBM13_Msk                           
#define CAN_FM1R_FBM14_Pos     (14U)                                        
#define CAN_FM1R_FBM14_Msk     (0x1UL << CAN_FM1R_FBM14_Pos)                
#define CAN_FM1R_FBM14         CAN_FM1R_FBM14_Msk                           
#define CAN_FM1R_FBM15_Pos     (15U)                                        
#define CAN_FM1R_FBM15_Msk     (0x1UL << CAN_FM1R_FBM15_Pos)                
#define CAN_FM1R_FBM15         CAN_FM1R_FBM15_Msk                           
#define CAN_FM1R_FBM16_Pos     (16U)                                        
#define CAN_FM1R_FBM16_Msk     (0x1UL << CAN_FM1R_FBM16_Pos)                
#define CAN_FM1R_FBM16         CAN_FM1R_FBM16_Msk                           
#define CAN_FM1R_FBM17_Pos     (17U)                                        
#define CAN_FM1R_FBM17_Msk     (0x1UL << CAN_FM1R_FBM17_Pos)                
#define CAN_FM1R_FBM17         CAN_FM1R_FBM17_Msk                           
#define CAN_FM1R_FBM18_Pos     (18U)                                        
#define CAN_FM1R_FBM18_Msk     (0x1UL << CAN_FM1R_FBM18_Pos)                
#define CAN_FM1R_FBM18         CAN_FM1R_FBM18_Msk                           
#define CAN_FM1R_FBM19_Pos     (19U)                                        
#define CAN_FM1R_FBM19_Msk     (0x1UL << CAN_FM1R_FBM19_Pos)                
#define CAN_FM1R_FBM19         CAN_FM1R_FBM19_Msk                           
#define CAN_FM1R_FBM20_Pos     (20U)                                        
#define CAN_FM1R_FBM20_Msk     (0x1UL << CAN_FM1R_FBM20_Pos)                
#define CAN_FM1R_FBM20         CAN_FM1R_FBM20_Msk                           
#define CAN_FM1R_FBM21_Pos     (21U)                                        
#define CAN_FM1R_FBM21_Msk     (0x1UL << CAN_FM1R_FBM21_Pos)                
#define CAN_FM1R_FBM21         CAN_FM1R_FBM21_Msk                           
#define CAN_FM1R_FBM22_Pos     (22U)                                        
#define CAN_FM1R_FBM22_Msk     (0x1UL << CAN_FM1R_FBM22_Pos)                
#define CAN_FM1R_FBM22         CAN_FM1R_FBM22_Msk                           
#define CAN_FM1R_FBM23_Pos     (23U)                                        
#define CAN_FM1R_FBM23_Msk     (0x1UL << CAN_FM1R_FBM23_Pos)                
#define CAN_FM1R_FBM23         CAN_FM1R_FBM23_Msk                          
#define CAN_FM1R_FBM24_Pos     (24U)                                       
#define CAN_FM1R_FBM24_Msk     (0x1UL << CAN_FM1R_FBM24_Pos)               
#define CAN_FM1R_FBM24         CAN_FM1R_FBM24_Msk                          
#define CAN_FM1R_FBM25_Pos     (25U)                                       
#define CAN_FM1R_FBM25_Msk     (0x1UL << CAN_FM1R_FBM25_Pos)               
#define CAN_FM1R_FBM25         CAN_FM1R_FBM25_Msk                          
#define CAN_FM1R_FBM26_Pos     (26U)                                       
#define CAN_FM1R_FBM26_Msk     (0x1UL << CAN_FM1R_FBM26_Pos)               
#define CAN_FM1R_FBM26         CAN_FM1R_FBM26_Msk                          
#define CAN_FM1R_FBM27_Pos     (27U)                                       
#define CAN_FM1R_FBM27_Msk     (0x1UL << CAN_FM1R_FBM27_Pos)               
#define CAN_FM1R_FBM27         CAN_FM1R_FBM27_Msk                          

/*******************  Bit definition for CAN_FS1R register  *******************/
#define CAN_FS1R_FSC_Pos       (0U)                                            
#define CAN_FS1R_FSC_Msk       (0xFFFFFFFUL << CAN_FS1R_FSC_Pos)         
#define CAN_FS1R_FSC           CAN_FS1R_FSC_Msk                          
#define CAN_FS1R_FSC0_Pos      (0U)                                      
#define CAN_FS1R_FSC0_Msk      (0x1UL << CAN_FS1R_FSC0_Pos)              
#define CAN_FS1R_FSC0          CAN_FS1R_FSC0_Msk                         
#define CAN_FS1R_FSC1_Pos      (1U)                                      
#define CAN_FS1R_FSC1_Msk      (0x1UL << CAN_FS1R_FSC1_Pos)              
#define CAN_FS1R_FSC1          CAN_FS1R_FSC1_Msk                         
#define CAN_FS1R_FSC2_Pos      (2U)                                      
#define CAN_FS1R_FSC2_Msk      (0x1UL << CAN_FS1R_FSC2_Pos)              
#define CAN_FS1R_FSC2          CAN_FS1R_FSC2_Msk                         
#define CAN_FS1R_FSC3_Pos      (3U)                                      
#define CAN_FS1R_FSC3_Msk      (0x1UL << CAN_FS1R_FSC3_Pos)              
#define CAN_FS1R_FSC3          CAN_FS1R_FSC3_Msk                         
#define CAN_FS1R_FSC4_Pos      (4U)                                      
#define CAN_FS1R_FSC4_Msk      (0x1UL << CAN_FS1R_FSC4_Pos)              
#define CAN_FS1R_FSC4          CAN_FS1R_FSC4_Msk                         
#define CAN_FS1R_FSC5_Pos      (5U)                                      
#define CAN_FS1R_FSC5_Msk      (0x1UL << CAN_FS1R_FSC5_Pos)              
#define CAN_FS1R_FSC5          CAN_FS1R_FSC5_Msk                         
#define CAN_FS1R_FSC6_Pos      (6U)                                      
#define CAN_FS1R_FSC6_Msk      (0x1UL << CAN_FS1R_FSC6_Pos)              
#define CAN_FS1R_FSC6          CAN_FS1R_FSC6_Msk                         
#define CAN_FS1R_FSC7_Pos      (7U)                                      
#define CAN_FS1R_FSC7_Msk      (0x1UL << CAN_FS1R_FSC7_Pos)              
#define CAN_FS1R_FSC7          CAN_FS1R_FSC7_Msk                         
#define CAN_FS1R_FSC8_Pos      (8U)                                      
#define CAN_FS1R_FSC8_Msk      (0x1UL << CAN_FS1R_FSC8_Pos)              
#define CAN_FS1R_FSC8          CAN_FS1R_FSC8_Msk                         
#define CAN_FS1R_FSC9_Pos      (9U)                                      
#define CAN_FS1R_FSC9_Msk      (0x1UL << CAN_FS1R_FSC9_Pos)              
#define CAN_FS1R_FSC9          CAN_FS1R_FSC9_Msk                         
#define CAN_FS1R_FSC10_Pos     (10U)                                     
#define CAN_FS1R_FSC10_Msk     (0x1UL << CAN_FS1R_FSC10_Pos)             
#define CAN_FS1R_FSC10         CAN_FS1R_FSC10_Msk                        
#define CAN_FS1R_FSC11_Pos     (11U)                                     
#define CAN_FS1R_FSC11_Msk     (0x1UL << CAN_FS1R_FSC11_Pos)             
#define CAN_FS1R_FSC11         CAN_FS1R_FSC11_Msk                           
#define CAN_FS1R_FSC12_Pos     (12U)                                        
#define CAN_FS1R_FSC12_Msk     (0x1UL << CAN_FS1R_FSC12_Pos)                
#define CAN_FS1R_FSC12         CAN_FS1R_FSC12_Msk                           
#define CAN_FS1R_FSC13_Pos     (13U)                                        
#define CAN_FS1R_FSC13_Msk     (0x1UL << CAN_FS1R_FSC13_Pos)                
#define CAN_FS1R_FSC13         CAN_FS1R_FSC13_Msk                           
#define CAN_FS1R_FSC14_Pos     (14U)                                        
#define CAN_FS1R_FSC14_Msk     (0x1UL << CAN_FS1R_FSC14_Pos)                
#define CAN_FS1R_FSC14         CAN_FS1R_FSC14_Msk                           
#define CAN_FS1R_FSC15_Pos     (15U)                                        
#define CAN_FS1R_FSC15_Msk     (0x1UL << CAN_FS1R_FSC15_Pos)                
#define CAN_FS1R_FSC15         CAN_FS1R_FSC15_Msk                           
#define CAN_FS1R_FSC16_Pos     (16U)                                        
#define CAN_FS1R_FSC16_Msk     (0x1UL << CAN_FS1R_FSC16_Pos)                
#define CAN_FS1R_FSC16         CAN_FS1R_FSC16_Msk                           
#define CAN_FS1R_FSC17_Pos     (17U)                                        
#define CAN_FS1R_FSC17_Msk     (0x1UL << CAN_FS1R_FSC17_Pos)                
#define CAN_FS1R_FSC17         CAN_FS1R_FSC17_Msk                           
#define CAN_FS1R_FSC18_Pos     (18U)                                        
#define CAN_FS1R_FSC18_Msk     (0x1UL << CAN_FS1R_FSC18_Pos)                
#define CAN_FS1R_FSC18         CAN_FS1R_FSC18_Msk                           
#define CAN_FS1R_FSC19_Pos     (19U)                                        
#define CAN_FS1R_FSC19_Msk     (0x1UL << CAN_FS1R_FSC19_Pos)                
#define CAN_FS1R_FSC19         CAN_FS1R_FSC19_Msk                           
#define CAN_FS1R_FSC20_Pos     (20U)                                        
#define CAN_FS1R_FSC20_Msk     (0x1UL << CAN_FS1R_FSC20_Pos)                
#define CAN_FS1R_FSC20         CAN_FS1R_FSC20_Msk                           
#define CAN_FS1R_FSC21_Pos     (21U)                                        
#define CAN_FS1R_FSC21_Msk     (0x1UL << CAN_FS1R_FSC21_Pos)                
#define CAN_FS1R_FSC21         CAN_FS1R_FSC21_Msk                           
#define CAN_FS1R_FSC22_Pos     (22U)                                        
#define CAN_FS1R_FSC22_Msk     (0x1UL << CAN_FS1R_FSC22_Pos)                
#define CAN_FS1R_FSC22         CAN_FS1R_FSC22_Msk                           
#define CAN_FS1R_FSC23_Pos     (23U)                                        
#define CAN_FS1R_FSC23_Msk     (0x1UL << CAN_FS1R_FSC23_Pos)                
#define CAN_FS1R_FSC23         CAN_FS1R_FSC23_Msk                           
#define CAN_FS1R_FSC24_Pos     (24U)                                        
#define CAN_FS1R_FSC24_Msk     (0x1UL << CAN_FS1R_FSC24_Pos)              
#define CAN_FS1R_FSC24         CAN_FS1R_FSC24_Msk                         
#define CAN_FS1R_FSC25_Pos     (25U)                                      
#define CAN_FS1R_FSC25_Msk     (0x1UL << CAN_FS1R_FSC25_Pos)              
#define CAN_FS1R_FSC25         CAN_FS1R_FSC25_Msk                         
#define CAN_FS1R_FSC26_Pos     (26U)                                      
#define CAN_FS1R_FSC26_Msk     (0x1UL << CAN_FS1R_FSC26_Pos)              
#define CAN_FS1R_FSC26         CAN_FS1R_FSC26_Msk                         
#define CAN_FS1R_FSC27_Pos     (27U)                                      
#define CAN_FS1R_FSC27_Msk     (0x1UL << CAN_FS1R_FSC27_Pos)              
#define CAN_FS1R_FSC27         CAN_FS1R_FSC27_Msk                         

/******************  Bit definition for CAN_FFA1R register  *******************/
#define CAN_FFA1R_FFA_Pos      (0U)                                            
#define CAN_FFA1R_FFA_Msk      (0xFFFFFFFUL << CAN_FFA1R_FFA_Pos)         
#define CAN_FFA1R_FFA          CAN_FFA1R_FFA_Msk                          
#define CAN_FFA1R_FFA0_Pos     (0U)                                       
#define CAN_FFA1R_FFA0_Msk     (0x1UL << CAN_FFA1R_FFA0_Pos)              
#define CAN_FFA1R_FFA0         CAN_FFA1R_FFA0_Msk                         
#define CAN_FFA1R_FFA1_Pos     (1U)                                       
#define CAN_FFA1R_FFA1_Msk     (0x1UL << CAN_FFA1R_FFA1_Pos)              
#define CAN_FFA1R_FFA1         CAN_FFA1R_FFA1_Msk                         
#define CAN_FFA1R_FFA2_Pos     (2U)                                       
#define CAN_FFA1R_FFA2_Msk     (0x1UL << CAN_FFA1R_FFA2_Pos)              
#define CAN_FFA1R_FFA2         CAN_FFA1R_FFA2_Msk                         
#define CAN_FFA1R_FFA3_Pos     (3U)                                       
#define CAN_FFA1R_FFA3_Msk     (0x1UL << CAN_FFA1R_FFA3_Pos)              
#define CAN_FFA1R_FFA3         CAN_FFA1R_FFA3_Msk                         
#define CAN_FFA1R_FFA4_Pos     (4U)                                       
#define CAN_FFA1R_FFA4_Msk     (0x1UL << CAN_FFA1R_FFA4_Pos)              
#define CAN_FFA1R_FFA4         CAN_FFA1R_FFA4_Msk                         
#define CAN_FFA1R_FFA5_Pos     (5U)                                       
#define CAN_FFA1R_FFA5_Msk     (0x1UL << CAN_FFA1R_FFA5_Pos)              
#define CAN_FFA1R_FFA5         CAN_FFA1R_FFA5_Msk                         
#define CAN_FFA1R_FFA6_Pos     (6U)                                       
#define CAN_FFA1R_FFA6_Msk     (0x1UL << CAN_FFA1R_FFA6_Pos)              
#define CAN_FFA1R_FFA6         CAN_FFA1R_FFA6_Msk                         
#define CAN_FFA1R_FFA7_Pos     (7U)                                       
#define CAN_FFA1R_FFA7_Msk     (0x1UL << CAN_FFA1R_FFA7_Pos)              
#define CAN_FFA1R_FFA7         CAN_FFA1R_FFA7_Msk                         
#define CAN_FFA1R_FFA8_Pos     (8U)                                       
#define CAN_FFA1R_FFA8_Msk     (0x1UL << CAN_FFA1R_FFA8_Pos)              
#define CAN_FFA1R_FFA8         CAN_FFA1R_FFA8_Msk                         
#define CAN_FFA1R_FFA9_Pos     (9U)                                       
#define CAN_FFA1R_FFA9_Msk     (0x1UL << CAN_FFA1R_FFA9_Pos)              
#define CAN_FFA1R_FFA9         CAN_FFA1R_FFA9_Msk                         
#define CAN_FFA1R_FFA10_Pos    (10U)                                      
#define CAN_FFA1R_FFA10_Msk    (0x1UL << CAN_FFA1R_FFA10_Pos)             
#define CAN_FFA1R_FFA10        CAN_FFA1R_FFA10_Msk                        
#define CAN_FFA1R_FFA11_Pos    (11U)                                      
#define CAN_FFA1R_FFA11_Msk    (0x1UL << CAN_FFA1R_FFA11_Pos)             
#define CAN_FFA1R_FFA11        CAN_FFA1R_FFA11_Msk                        
#define CAN_FFA1R_FFA12_Pos    (12U)                                      
#define CAN_FFA1R_FFA12_Msk    (0x1UL << CAN_FFA1R_FFA12_Pos)             
#define CAN_FFA1R_FFA12        CAN_FFA1R_FFA12_Msk                        
#define CAN_FFA1R_FFA13_Pos    (13U)                                      
#define CAN_FFA1R_FFA13_Msk    (0x1UL << CAN_FFA1R_FFA13_Pos)             
#define CAN_FFA1R_FFA13        CAN_FFA1R_FFA13_Msk                        
#define CAN_FFA1R_FFA14_Pos    (14U)                                      
#define CAN_FFA1R_FFA14_Msk    (0x1UL << CAN_FFA1R_FFA14_Pos)             
#define CAN_FFA1R_FFA14        CAN_FFA1R_FFA14_Msk                        
#define CAN_FFA1R_FFA15_Pos    (15U)                                      
#define CAN_FFA1R_FFA15_Msk    (0x1UL << CAN_FFA1R_FFA15_Pos)             
#define CAN_FFA1R_FFA15        CAN_FFA1R_FFA15_Msk                        
#define CAN_FFA1R_FFA16_Pos    (16U)                                      
#define CAN_FFA1R_FFA16_Msk    (0x1UL << CAN_FFA1R_FFA16_Pos)             
#define CAN_FFA1R_FFA16        CAN_FFA1R_FFA16_Msk                        
#define CAN_FFA1R_FFA17_Pos    (17U)                                      
#define CAN_FFA1R_FFA17_Msk    (0x1UL << CAN_FFA1R_FFA17_Pos)             
#define CAN_FFA1R_FFA17        CAN_FFA1R_FFA17_Msk                        
#define CAN_FFA1R_FFA18_Pos    (18U)                                      
#define CAN_FFA1R_FFA18_Msk    (0x1UL << CAN_FFA1R_FFA18_Pos)             
#define CAN_FFA1R_FFA18        CAN_FFA1R_FFA18_Msk                        
#define CAN_FFA1R_FFA19_Pos    (19U)                                      
#define CAN_FFA1R_FFA19_Msk    (0x1UL << CAN_FFA1R_FFA19_Pos)             
#define CAN_FFA1R_FFA19        CAN_FFA1R_FFA19_Msk                        
#define CAN_FFA1R_FFA20_Pos    (20U)                                      
#define CAN_FFA1R_FFA20_Msk    (0x1UL << CAN_FFA1R_FFA20_Pos)             
#define CAN_FFA1R_FFA20        CAN_FFA1R_FFA20_Msk                        
#define CAN_FFA1R_FFA21_Pos    (21U)                                      
#define CAN_FFA1R_FFA21_Msk    (0x1UL << CAN_FFA1R_FFA21_Pos)             
#define CAN_FFA1R_FFA21        CAN_FFA1R_FFA21_Msk                        
#define CAN_FFA1R_FFA22_Pos    (22U)                                      
#define CAN_FFA1R_FFA22_Msk    (0x1UL << CAN_FFA1R_FFA22_Pos)             
#define CAN_FFA1R_FFA22        CAN_FFA1R_FFA22_Msk                        
#define CAN_FFA1R_FFA23_Pos    (23U)                                      
#define CAN_FFA1R_FFA23_Msk    (0x1UL << CAN_FFA1R_FFA23_Pos)             
#define CAN_FFA1R_FFA23        CAN_FFA1R_FFA23_Msk                        
#define CAN_FFA1R_FFA24_Pos    (24U)                                      
#define CAN_FFA1R_FFA24_Msk    (0x1UL << CAN_FFA1R_FFA24_Pos)             
#define CAN_FFA1R_FFA24        CAN_FFA1R_FFA24_Msk                        
#define CAN_FFA1R_FFA25_Pos    (25U)                                      
#define CAN_FFA1R_FFA25_Msk    (0x1UL << CAN_FFA1R_FFA25_Pos)             
#define CAN_FFA1R_FFA25        CAN_FFA1R_FFA25_Msk                        
#define CAN_FFA1R_FFA26_Pos    (26U)                                      
#define CAN_FFA1R_FFA26_Msk    (0x1UL << CAN_FFA1R_FFA26_Pos)             
#define CAN_FFA1R_FFA26        CAN_FFA1R_FFA26_Msk                        
#define CAN_FFA1R_FFA27_Pos    (27U)                                      
#define CAN_FFA1R_FFA27_Msk    (0x1UL << CAN_FFA1R_FFA27_Pos)             
#define CAN_FFA1R_FFA27        CAN_FFA1R_FFA27_Msk                        

/*******************  Bit definition for CAN_FA1R register  *******************/
#define CAN_FA1R_FACT_Pos      (0U)                                          
#define CAN_FA1R_FACT_Msk      (0xFFFFFFFUL << CAN_FA1R_FACT_Pos)            
#define CAN_FA1R_FACT          CAN_FA1R_FACT_Msk                             
#define CAN_FA1R_FACT0_Pos     (0U)                                          
#define CAN_FA1R_FACT0_Msk     (0x1UL << CAN_FA1R_FACT0_Pos)                 
#define CAN_FA1R_FACT0         CAN_FA1R_FACT0_Msk                            
#define CAN_FA1R_FACT1_Pos     (1U)                                          
#define CAN_FA1R_FACT1_Msk     (0x1UL << CAN_FA1R_FACT1_Pos)                 
#define CAN_FA1R_FACT1         CAN_FA1R_FACT1_Msk                            
#define CAN_FA1R_FACT2_Pos     (2U)                                          
#define CAN_FA1R_FACT2_Msk     (0x1UL << CAN_FA1R_FACT2_Pos)                 
#define CAN_FA1R_FACT2         CAN_FA1R_FACT2_Msk                            
#define CAN_FA1R_FACT3_Pos     (3U)                                          
#define CAN_FA1R_FACT3_Msk     (0x1UL << CAN_FA1R_FACT3_Pos)                 
#define CAN_FA1R_FACT3         CAN_FA1R_FACT3_Msk                            
#define CAN_FA1R_FACT4_Pos     (4U)                                          
#define CAN_FA1R_FACT4_Msk     (0x1UL << CAN_FA1R_FACT4_Pos)                 
#define CAN_FA1R_FACT4         CAN_FA1R_FACT4_Msk                            
#define CAN_FA1R_FACT5_Pos     (5U)                                          
#define CAN_FA1R_FACT5_Msk     (0x1UL << CAN_FA1R_FACT5_Pos)                 
#define CAN_FA1R_FACT5         CAN_FA1R_FACT5_Msk                            
#define CAN_FA1R_FACT6_Pos     (6U)                                          
#define CAN_FA1R_FACT6_Msk     (0x1UL << CAN_FA1R_FACT6_Pos)                 
#define CAN_FA1R_FACT6         CAN_FA1R_FACT6_Msk                            
#define CAN_FA1R_FACT7_Pos     (7U)                                          
#define CAN_FA1R_FACT7_Msk     (0x1UL << CAN_FA1R_FACT7_Pos)                 
#define CAN_FA1R_FACT7         CAN_FA1R_FACT7_Msk                            
#define CAN_FA1R_FACT8_Pos     (8U)                                          
#define CAN_FA1R_FACT8_Msk     (0x1UL << CAN_FA1R_FACT8_Pos)                 
#define CAN_FA1R_FACT8         CAN_FA1R_FACT8_Msk                            
#define CAN_FA1R_FACT9_Pos     (9U)                                          
#define CAN_FA1R_FACT9_Msk     (0x1UL << CAN_FA1R_FACT9_Pos)                 
#define CAN_FA1R_FACT9         CAN_FA1R_FACT9_Msk                            
#define CAN_FA1R_FACT10_Pos    (10U)                                         
#define CAN_FA1R_FACT10_Msk    (0x1UL << CAN_FA1R_FACT10_Pos)                
#define CAN_FA1R_FACT10        CAN_FA1R_FACT10_Msk                           
#define CAN_FA1R_FACT11_Pos    (11U)                                         
#define CAN_FA1R_FACT11_Msk    (0x1UL << CAN_FA1R_FACT11_Pos)                
#define CAN_FA1R_FACT11        CAN_FA1R_FACT11_Msk                           
#define CAN_FA1R_FACT12_Pos    (12U)                                         
#define CAN_FA1R_FACT12_Msk    (0x1UL << CAN_FA1R_FACT12_Pos)                
#define CAN_FA1R_FACT12        CAN_FA1R_FACT12_Msk                           
#define CAN_FA1R_FACT13_Pos    (13U)                                         
#define CAN_FA1R_FACT13_Msk    (0x1UL << CAN_FA1R_FACT13_Pos)                
#define CAN_FA1R_FACT13        CAN_FA1R_FACT13_Msk                           
#define CAN_FA1R_FACT14_Pos    (14U)                                         
#define CAN_FA1R_FACT14_Msk    (0x1UL << CAN_FA1R_FACT14_Pos)                
#define CAN_FA1R_FACT14        CAN_FA1R_FACT14_Msk                           
#define CAN_FA1R_FACT15_Pos    (15U)                                         
#define CAN_FA1R_FACT15_Msk    (0x1UL << CAN_FA1R_FACT15_Pos)                
#define CAN_FA1R_FACT15        CAN_FA1R_FACT15_Msk                           
#define CAN_FA1R_FACT16_Pos    (16U)                                         
#define CAN_FA1R_FACT16_Msk    (0x1UL << CAN_FA1R_FACT16_Pos)                
#define CAN_FA1R_FACT16        CAN_FA1R_FACT16_Msk                           
#define CAN_FA1R_FACT17_Pos    (17U)                                         
#define CAN_FA1R_FACT17_Msk    (0x1UL << CAN_FA1R_FACT17_Pos)                
#define CAN_FA1R_FACT17        CAN_FA1R_FACT17_Msk                           
#define CAN_FA1R_FACT18_Pos    (18U)                                         
#define CAN_FA1R_FACT18_Msk    (0x1UL << CAN_FA1R_FACT18_Pos)                
#define CAN_FA1R_FACT18        CAN_FA1R_FACT18_Msk                           
#define CAN_FA1R_FACT19_Pos    (19U)                                         
#define CAN_FA1R_FACT19_Msk    (0x1UL << CAN_FA1R_FACT19_Pos)                
#define CAN_FA1R_FACT19        CAN_FA1R_FACT19_Msk                           
#define CAN_FA1R_FACT20_Pos    (20U)                                         
#define CAN_FA1R_FACT20_Msk    (0x1UL << CAN_FA1R_FACT20_Pos)                
#define CAN_FA1R_FACT20        CAN_FA1R_FACT20_Msk                           
#define CAN_FA1R_FACT21_Pos    (21U)                                         
#define CAN_FA1R_FACT21_Msk    (0x1UL << CAN_FA1R_FACT21_Pos)                
#define CAN_FA1R_FACT21        CAN_FA1R_FACT21_Msk                           
#define CAN_FA1R_FACT22_Pos    (22U)                                         
#define CAN_FA1R_FACT22_Msk    (0x1UL << CAN_FA1R_FACT22_Pos)                
#define CAN_FA1R_FACT22        CAN_FA1R_FACT22_Msk                           
#define CAN_FA1R_FACT23_Pos    (23U)                                         
#define CAN_FA1R_FACT23_Msk    (0x1UL << CAN_FA1R_FACT23_Pos)                
#define CAN_FA1R_FACT23        CAN_FA1R_FACT23_Msk                           
#define CAN_FA1R_FACT24_Pos    (24U)                                         
#define CAN_FA1R_FACT24_Msk    (0x1UL << CAN_FA1R_FACT24_Pos)                
#define CAN_FA1R_FACT24        CAN_FA1R_FACT24_Msk                           
#define CAN_FA1R_FACT25_Pos    (25U)                                         
#define CAN_FA1R_FACT25_Msk    (0x1UL << CAN_FA1R_FACT25_Pos)                
#define CAN_FA1R_FACT25        CAN_FA1R_FACT25_Msk                           
#define CAN_FA1R_FACT26_Pos    (26U)                                         
#define CAN_FA1R_FACT26_Msk    (0x1UL << CAN_FA1R_FACT26_Pos)                
#define CAN_FA1R_FACT26        CAN_FA1R_FACT26_Msk                           
#define CAN_FA1R_FACT27_Pos    (27U)                                         
#define CAN_FA1R_FACT27_Msk    (0x1UL << CAN_FA1R_FACT27_Pos)                
#define CAN_FA1R_FACT27        CAN_FA1R_FACT27_Msk                           


/*******************  Bit definition for CAN_F0R1 register  *******************/
#define CAN_F0R1_FB0_Pos       (0U)                                            
#define CAN_F0R1_FB0_Msk       (0x1UL << CAN_F0R1_FB0_Pos)                      
#define CAN_F0R1_FB0           CAN_F0R1_FB0_Msk                              
#define CAN_F0R1_FB1_Pos       (1U)                                          
#define CAN_F0R1_FB1_Msk       (0x1UL << CAN_F0R1_FB1_Pos)                   
#define CAN_F0R1_FB1           CAN_F0R1_FB1_Msk                              
#define CAN_F0R1_FB2_Pos       (2U)                                          
#define CAN_F0R1_FB2_Msk       (0x1UL << CAN_F0R1_FB2_Pos)                   
#define CAN_F0R1_FB2           CAN_F0R1_FB2_Msk                              
#define CAN_F0R1_FB3_Pos       (3U)                                          
#define CAN_F0R1_FB3_Msk       (0x1UL << CAN_F0R1_FB3_Pos)                   
#define CAN_F0R1_FB3           CAN_F0R1_FB3_Msk                              
#define CAN_F0R1_FB4_Pos       (4U)                                          
#define CAN_F0R1_FB4_Msk       (0x1UL << CAN_F0R1_FB4_Pos)                   
#define CAN_F0R1_FB4           CAN_F0R1_FB4_Msk                              
#define CAN_F0R1_FB5_Pos       (5U)                                          
#define CAN_F0R1_FB5_Msk       (0x1UL << CAN_F0R1_FB5_Pos)                   
#define CAN_F0R1_FB5           CAN_F0R1_FB5_Msk                              
#define CAN_F0R1_FB6_Pos       (6U)                                          
#define CAN_F0R1_FB6_Msk       (0x1UL << CAN_F0R1_FB6_Pos)                   
#define CAN_F0R1_FB6           CAN_F0R1_FB6_Msk                              
#define CAN_F0R1_FB7_Pos       (7U)                                          
#define CAN_F0R1_FB7_Msk       (0x1UL << CAN_F0R1_FB7_Pos)                   
#define CAN_F0R1_FB7           CAN_F0R1_FB7_Msk                              
#define CAN_F0R1_FB8_Pos       (8U)                                          
#define CAN_F0R1_FB8_Msk       (0x1UL << CAN_F0R1_FB8_Pos)                   
#define CAN_F0R1_FB8           CAN_F0R1_FB8_Msk                              
#define CAN_F0R1_FB9_Pos       (9U)                                          
#define CAN_F0R1_FB9_Msk       (0x1UL << CAN_F0R1_FB9_Pos)                   
#define CAN_F0R1_FB9           CAN_F0R1_FB9_Msk                              
#define CAN_F0R1_FB10_Pos      (10U)                                         
#define CAN_F0R1_FB10_Msk      (0x1UL << CAN_F0R1_FB10_Pos)                  
#define CAN_F0R1_FB10          CAN_F0R1_FB10_Msk                             
#define CAN_F0R1_FB11_Pos      (11U)                                         
#define CAN_F0R1_FB11_Msk      (0x1UL << CAN_F0R1_FB11_Pos)                  
#define CAN_F0R1_FB11          CAN_F0R1_FB11_Msk                             
#define CAN_F0R1_FB12_Pos      (12U)                                         
#define CAN_F0R1_FB12_Msk      (0x1UL << CAN_F0R1_FB12_Pos)                  
#define CAN_F0R1_FB12          CAN_F0R1_FB12_Msk                             
#define CAN_F0R1_FB13_Pos      (13U)                                         
#define CAN_F0R1_FB13_Msk      (0x1UL << CAN_F0R1_FB13_Pos)                  
#define CAN_F0R1_FB13          CAN_F0R1_FB13_Msk                             
#define CAN_F0R1_FB14_Pos      (14U)                                         
#define CAN_F0R1_FB14_Msk      (0x1UL << CAN_F0R1_FB14_Pos)                  
#define CAN_F0R1_FB14          CAN_F0R1_FB14_Msk                             
#define CAN_F0R1_FB15_Pos      (15U)                                         
#define CAN_F0R1_FB15_Msk      (0x1UL << CAN_F0R1_FB15_Pos)                  
#define CAN_F0R1_FB15          CAN_F0R1_FB15_Msk                             
#define CAN_F0R1_FB16_Pos      (16U)                                         
#define CAN_F0R1_FB16_Msk      (0x1UL << CAN_F0R1_FB16_Pos)                  
#define CAN_F0R1_FB16          CAN_F0R1_FB16_Msk                             
#define CAN_F0R1_FB17_Pos      (17U)                                         
#define CAN_F0R1_FB17_Msk      (0x1UL << CAN_F0R1_FB17_Pos)                  
#define CAN_F0R1_FB17          CAN_F0R1_FB17_Msk                             
#define CAN_F0R1_FB18_Pos      (18U)                                         
#define CAN_F0R1_FB18_Msk      (0x1UL << CAN_F0R1_FB18_Pos)                  
#define CAN_F0R1_FB18          CAN_F0R1_FB18_Msk                             
#define CAN_F0R1_FB19_Pos      (19U)                                         
#define CAN_F0R1_FB19_Msk      (0x1UL << CAN_F0R1_FB19_Pos)                  
#define CAN_F0R1_FB19          CAN_F0R1_FB19_Msk                             
#define CAN_F0R1_FB20_Pos      (20U)                                         
#define CAN_F0R1_FB20_Msk      (0x1UL << CAN_F0R1_FB20_Pos)                  
#define CAN_F0R1_FB20          CAN_F0R1_FB20_Msk                             
#define CAN_F0R1_FB21_Pos      (21U)                                         
#define CAN_F0R1_FB21_Msk      (0x1UL << CAN_F0R1_FB21_Pos)                  
#define CAN_F0R1_FB21          CAN_F0R1_FB21_Msk                             
#define CAN_F0R1_FB22_Pos      (22U)                                         
#define CAN_F0R1_FB22_Msk      (0x1UL << CAN_F0R1_FB22_Pos)                  
#define CAN_F0R1_FB22          CAN_F0R1_FB22_Msk                             
#define CAN_F0R1_FB23_Pos      (23U)                                         
#define CAN_F0R1_FB23_Msk      (0x1UL << CAN_F0R1_FB23_Pos)                  
#define CAN_F0R1_FB23          CAN_F0R1_FB23_Msk                             
#define CAN_F0R1_FB24_Pos      (24U)                                         
#define CAN_F0R1_FB24_Msk      (0x1UL << CAN_F0R1_FB24_Pos)                  
#define CAN_F0R1_FB24          CAN_F0R1_FB24_Msk                             
#define CAN_F0R1_FB25_Pos      (25U)                                         
#define CAN_F0R1_FB25_Msk      (0x1UL << CAN_F0R1_FB25_Pos)                  
#define CAN_F0R1_FB25          CAN_F0R1_FB25_Msk                             
#define CAN_F0R1_FB26_Pos      (26U)                                         
#define CAN_F0R1_FB26_Msk      (0x1UL << CAN_F0R1_FB26_Pos)                  
#define CAN_F0R1_FB26          CAN_F0R1_FB26_Msk                             
#define CAN_F0R1_FB27_Pos      (27U)                                         
#define CAN_F0R1_FB27_Msk      (0x1UL << CAN_F0R1_FB27_Pos)                  
#define CAN_F0R1_FB27          CAN_F0R1_FB27_Msk                             
#define CAN_F0R1_FB28_Pos      (28U)                                         
#define CAN_F0R1_FB28_Msk      (0x1UL << CAN_F0R1_FB28_Pos)                  
#define CAN_F0R1_FB28          CAN_F0R1_FB28_Msk                             
#define CAN_F0R1_FB29_Pos      (29U)                                         
#define CAN_F0R1_FB29_Msk      (0x1UL << CAN_F0R1_FB29_Pos)                  
#define CAN_F0R1_FB29          CAN_F0R1_FB29_Msk                             
#define CAN_F0R1_FB30_Pos      (30U)                                         
#define CAN_F0R1_FB30_Msk      (0x1UL << CAN_F0R1_FB30_Pos)                  
#define CAN_F0R1_FB30          CAN_F0R1_FB30_Msk                             
#define CAN_F0R1_FB31_Pos      (31U)                                         
#define CAN_F0R1_FB31_Msk      (0x1UL << CAN_F0R1_FB31_Pos)                  
#define CAN_F0R1_FB31          CAN_F0R1_FB31_Msk                             

/*******************  Bit definition for CAN_F1R1 register  *******************/
#define CAN_F1R1_FB0_Pos       (0U)                                            
#define CAN_F1R1_FB0_Msk       (0x1UL << CAN_F1R1_FB0_Pos)                      
#define CAN_F1R1_FB0           CAN_F1R1_FB0_Msk                             
#define CAN_F1R1_FB1_Pos       (1U)                                         
#define CAN_F1R1_FB1_Msk       (0x1UL << CAN_F1R1_FB1_Pos)                  
#define CAN_F1R1_FB1           CAN_F1R1_FB1_Msk                             
#define CAN_F1R1_FB2_Pos       (2U)                                         
#define CAN_F1R1_FB2_Msk       (0x1UL << CAN_F1R1_FB2_Pos)                  
#define CAN_F1R1_FB2           CAN_F1R1_FB2_Msk                             
#define CAN_F1R1_FB3_Pos       (3U)                                         
#define CAN_F1R1_FB3_Msk       (0x1UL << CAN_F1R1_FB3_Pos)                  
#define CAN_F1R1_FB3           CAN_F1R1_FB3_Msk                             
#define CAN_F1R1_FB4_Pos       (4U)                                         
#define CAN_F1R1_FB4_Msk       (0x1UL << CAN_F1R1_FB4_Pos)                  
#define CAN_F1R1_FB4           CAN_F1R1_FB4_Msk                             
#define CAN_F1R1_FB5_Pos       (5U)                                         
#define CAN_F1R1_FB5_Msk       (0x1UL << CAN_F1R1_FB5_Pos)                  
#define CAN_F1R1_FB5           CAN_F1R1_FB5_Msk                             
#define CAN_F1R1_FB6_Pos       (6U)                                         
#define CAN_F1R1_FB6_Msk       (0x1UL << CAN_F1R1_FB6_Pos)                  
#define CAN_F1R1_FB6           CAN_F1R1_FB6_Msk                             
#define CAN_F1R1_FB7_Pos       (7U)                                         
#define CAN_F1R1_FB7_Msk       (0x1UL << CAN_F1R1_FB7_Pos)                  
#define CAN_F1R1_FB7           CAN_F1R1_FB7_Msk                             
#define CAN_F1R1_FB8_Pos       (8U)                                         
#define CAN_F1R1_FB8_Msk       (0x1UL << CAN_F1R1_FB8_Pos)                  
#define CAN_F1R1_FB8           CAN_F1R1_FB8_Msk                             
#define CAN_F1R1_FB9_Pos       (9U)                                         
#define CAN_F1R1_FB9_Msk       (0x1UL << CAN_F1R1_FB9_Pos)                  
#define CAN_F1R1_FB9           CAN_F1R1_FB9_Msk                             
#define CAN_F1R1_FB10_Pos      (10U)                                        
#define CAN_F1R1_FB10_Msk      (0x1UL << CAN_F1R1_FB10_Pos)                 
#define CAN_F1R1_FB10          CAN_F1R1_FB10_Msk                            
#define CAN_F1R1_FB11_Pos      (11U)                                        
#define CAN_F1R1_FB11_Msk      (0x1UL << CAN_F1R1_FB11_Pos)                 
#define CAN_F1R1_FB11          CAN_F1R1_FB11_Msk                            
#define CAN_F1R1_FB12_Pos      (12U)                                        
#define CAN_F1R1_FB12_Msk      (0x1UL << CAN_F1R1_FB12_Pos)                 
#define CAN_F1R1_FB12          CAN_F1R1_FB12_Msk                            
#define CAN_F1R1_FB13_Pos      (13U)                                        
#define CAN_F1R1_FB13_Msk      (0x1UL << CAN_F1R1_FB13_Pos)                 
#define CAN_F1R1_FB13          CAN_F1R1_FB13_Msk                            
#define CAN_F1R1_FB14_Pos      (14U)                                        
#define CAN_F1R1_FB14_Msk      (0x1UL << CAN_F1R1_FB14_Pos)                 
#define CAN_F1R1_FB14          CAN_F1R1_FB14_Msk                            
#define CAN_F1R1_FB15_Pos      (15U)                                        
#define CAN_F1R1_FB15_Msk      (0x1UL << CAN_F1R1_FB15_Pos)                 
#define CAN_F1R1_FB15          CAN_F1R1_FB15_Msk                            
#define CAN_F1R1_FB16_Pos      (16U)                                        
#define CAN_F1R1_FB16_Msk      (0x1UL << CAN_F1R1_FB16_Pos)                 
#define CAN_F1R1_FB16          CAN_F1R1_FB16_Msk                            
#define CAN_F1R1_FB17_Pos      (17U)                                        
#define CAN_F1R1_FB17_Msk      (0x1UL << CAN_F1R1_FB17_Pos)                 
#define CAN_F1R1_FB17          CAN_F1R1_FB17_Msk                            
#define CAN_F1R1_FB18_Pos      (18U)                                        
#define CAN_F1R1_FB18_Msk      (0x1UL << CAN_F1R1_FB18_Pos)                 
#define CAN_F1R1_FB18          CAN_F1R1_FB18_Msk                            
#define CAN_F1R1_FB19_Pos      (19U)                                        
#define CAN_F1R1_FB19_Msk      (0x1UL << CAN_F1R1_FB19_Pos)                 
#define CAN_F1R1_FB19          CAN_F1R1_FB19_Msk                            
#define CAN_F1R1_FB20_Pos      (20U)                                        
#define CAN_F1R1_FB20_Msk      (0x1UL << CAN_F1R1_FB20_Pos)                 
#define CAN_F1R1_FB20          CAN_F1R1_FB20_Msk                            
#define CAN_F1R1_FB21_Pos      (21U)                                        
#define CAN_F1R1_FB21_Msk      (0x1UL << CAN_F1R1_FB21_Pos)                 
#define CAN_F1R1_FB21          CAN_F1R1_FB21_Msk                            
#define CAN_F1R1_FB22_Pos      (22U)                                        
#define CAN_F1R1_FB22_Msk      (0x1UL << CAN_F1R1_FB22_Pos)                 
#define CAN_F1R1_FB22          CAN_F1R1_FB22_Msk                            
#define CAN_F1R1_FB23_Pos      (23U)                                        
#define CAN_F1R1_FB23_Msk      (0x1UL << CAN_F1R1_FB23_Pos)                 
#define CAN_F1R1_FB23          CAN_F1R1_FB23_Msk                            
#define CAN_F1R1_FB24_Pos      (24U)                                        
#define CAN_F1R1_FB24_Msk      (0x1UL << CAN_F1R1_FB24_Pos)                 
#define CAN_F1R1_FB24          CAN_F1R1_FB24_Msk                            
#define CAN_F1R1_FB25_Pos      (25U)                                        
#define CAN_F1R1_FB25_Msk      (0x1UL << CAN_F1R1_FB25_Pos)                 
#define CAN_F1R1_FB25          CAN_F1R1_FB25_Msk                            
#define CAN_F1R1_FB26_Pos      (26U)                                        
#define CAN_F1R1_FB26_Msk      (0x1UL << CAN_F1R1_FB26_Pos)                 
#define CAN_F1R1_FB26          CAN_F1R1_FB26_Msk                            
#define CAN_F1R1_FB27_Pos      (27U)                                        
#define CAN_F1R1_FB27_Msk      (0x1UL << CAN_F1R1_FB27_Pos)                 
#define CAN_F1R1_FB27          CAN_F1R1_FB27_Msk                            
#define CAN_F1R1_FB28_Pos      (28U)                                        
#define CAN_F1R1_FB28_Msk      (0x1UL << CAN_F1R1_FB28_Pos)                 
#define CAN_F1R1_FB28          CAN_F1R1_FB28_Msk                            
#define CAN_F1R1_FB29_Pos      (29U)                                        
#define CAN_F1R1_FB29_Msk      (0x1UL << CAN_F1R1_FB29_Pos)                 
#define CAN_F1R1_FB29          CAN_F1R1_FB29_Msk                            
#define CAN_F1R1_FB30_Pos      (30U)                                        
#define CAN_F1R1_FB30_Msk      (0x1UL << CAN_F1R1_FB30_Pos)                 
#define CAN_F1R1_FB30          CAN_F1R1_FB30_Msk                            
#define CAN_F1R1_FB31_Pos      (31U)                                        
#define CAN_F1R1_FB31_Msk      (0x1UL << CAN_F1R1_FB31_Pos)                 
#define CAN_F1R1_FB31          CAN_F1R1_FB31_Msk                            

/*******************  Bit definition for CAN_F2R1 register  *******************/
#define CAN_F2R1_FB0_Pos       (0U)                                            
#define CAN_F2R1_FB0_Msk       (0x1UL << CAN_F2R1_FB0_Pos)                      
#define CAN_F2R1_FB0           CAN_F2R1_FB0_Msk                              
#define CAN_F2R1_FB1_Pos       (1U)                                          
#define CAN_F2R1_FB1_Msk       (0x1UL << CAN_F2R1_FB1_Pos)                   
#define CAN_F2R1_FB1           CAN_F2R1_FB1_Msk                              
#define CAN_F2R1_FB2_Pos       (2U)                                          
#define CAN_F2R1_FB2_Msk       (0x1UL << CAN_F2R1_FB2_Pos)                   
#define CAN_F2R1_FB2           CAN_F2R1_FB2_Msk                              
#define CAN_F2R1_FB3_Pos       (3U)                                          
#define CAN_F2R1_FB3_Msk       (0x1UL << CAN_F2R1_FB3_Pos)                   
#define CAN_F2R1_FB3           CAN_F2R1_FB3_Msk                              
#define CAN_F2R1_FB4_Pos       (4U)                                          
#define CAN_F2R1_FB4_Msk       (0x1UL << CAN_F2R1_FB4_Pos)                   
#define CAN_F2R1_FB4           CAN_F2R1_FB4_Msk                              
#define CAN_F2R1_FB5_Pos       (5U)                                          
#define CAN_F2R1_FB5_Msk       (0x1UL << CAN_F2R1_FB5_Pos)                   
#define CAN_F2R1_FB5           CAN_F2R1_FB5_Msk                              
#define CAN_F2R1_FB6_Pos       (6U)                                          
#define CAN_F2R1_FB6_Msk       (0x1UL << CAN_F2R1_FB6_Pos)                   
#define CAN_F2R1_FB6           CAN_F2R1_FB6_Msk                              
#define CAN_F2R1_FB7_Pos       (7U)                                          
#define CAN_F2R1_FB7_Msk       (0x1UL << CAN_F2R1_FB7_Pos)                   
#define CAN_F2R1_FB7           CAN_F2R1_FB7_Msk                              
#define CAN_F2R1_FB8_Pos       (8U)                                          
#define CAN_F2R1_FB8_Msk       (0x1UL << CAN_F2R1_FB8_Pos)                   
#define CAN_F2R1_FB8           CAN_F2R1_FB8_Msk                              
#define CAN_F2R1_FB9_Pos       (9U)                                          
#define CAN_F2R1_FB9_Msk       (0x1UL << CAN_F2R1_FB9_Pos)                   
#define CAN_F2R1_FB9           CAN_F2R1_FB9_Msk                              
#define CAN_F2R1_FB10_Pos      (10U)                                         
#define CAN_F2R1_FB10_Msk      (0x1UL << CAN_F2R1_FB10_Pos)                  
#define CAN_F2R1_FB10          CAN_F2R1_FB10_Msk                             
#define CAN_F2R1_FB11_Pos      (11U)                                         
#define CAN_F2R1_FB11_Msk      (0x1UL << CAN_F2R1_FB11_Pos)                  
#define CAN_F2R1_FB11          CAN_F2R1_FB11_Msk                             
#define CAN_F2R1_FB12_Pos      (12U)                                         
#define CAN_F2R1_FB12_Msk      (0x1UL << CAN_F2R1_FB12_Pos)                  
#define CAN_F2R1_FB12          CAN_F2R1_FB12_Msk                             
#define CAN_F2R1_FB13_Pos      (13U)                                         
#define CAN_F2R1_FB13_Msk      (0x1UL << CAN_F2R1_FB13_Pos)                  
#define CAN_F2R1_FB13          CAN_F2R1_FB13_Msk                             
#define CAN_F2R1_FB14_Pos      (14U)                                         
#define CAN_F2R1_FB14_Msk      (0x1UL << CAN_F2R1_FB14_Pos)                  
#define CAN_F2R1_FB14          CAN_F2R1_FB14_Msk                             
#define CAN_F2R1_FB15_Pos      (15U)                                         
#define CAN_F2R1_FB15_Msk      (0x1UL << CAN_F2R1_FB15_Pos)                  
#define CAN_F2R1_FB15          CAN_F2R1_FB15_Msk                             
#define CAN_F2R1_FB16_Pos      (16U)                                         
#define CAN_F2R1_FB16_Msk      (0x1UL << CAN_F2R1_FB16_Pos)                  
#define CAN_F2R1_FB16          CAN_F2R1_FB16_Msk                             
#define CAN_F2R1_FB17_Pos      (17U)                                         
#define CAN_F2R1_FB17_Msk      (0x1UL << CAN_F2R1_FB17_Pos)                  
#define CAN_F2R1_FB17          CAN_F2R1_FB17_Msk                             
#define CAN_F2R1_FB18_Pos      (18U)                                         
#define CAN_F2R1_FB18_Msk      (0x1UL << CAN_F2R1_FB18_Pos)                  
#define CAN_F2R1_FB18          CAN_F2R1_FB18_Msk                             
#define CAN_F2R1_FB19_Pos      (19U)                                         
#define CAN_F2R1_FB19_Msk      (0x1UL << CAN_F2R1_FB19_Pos)                  
#define CAN_F2R1_FB19          CAN_F2R1_FB19_Msk                             
#define CAN_F2R1_FB20_Pos      (20U)                                         
#define CAN_F2R1_FB20_Msk      (0x1UL << CAN_F2R1_FB20_Pos)                  
#define CAN_F2R1_FB20          CAN_F2R1_FB20_Msk                             
#define CAN_F2R1_FB21_Pos      (21U)                                         
#define CAN_F2R1_FB21_Msk      (0x1UL << CAN_F2R1_FB21_Pos)                  
#define CAN_F2R1_FB21          CAN_F2R1_FB21_Msk                             
#define CAN_F2R1_FB22_Pos      (22U)                                         
#define CAN_F2R1_FB22_Msk      (0x1UL << CAN_F2R1_FB22_Pos)                  
#define CAN_F2R1_FB22          CAN_F2R1_FB22_Msk                             
#define CAN_F2R1_FB23_Pos      (23U)                                         
#define CAN_F2R1_FB23_Msk      (0x1UL << CAN_F2R1_FB23_Pos)                  
#define CAN_F2R1_FB23          CAN_F2R1_FB23_Msk                             
#define CAN_F2R1_FB24_Pos      (24U)                                         
#define CAN_F2R1_FB24_Msk      (0x1UL << CAN_F2R1_FB24_Pos)                  
#define CAN_F2R1_FB24          CAN_F2R1_FB24_Msk                             
#define CAN_F2R1_FB25_Pos      (25U)                                         
#define CAN_F2R1_FB25_Msk      (0x1UL << CAN_F2R1_FB25_Pos)                  
#define CAN_F2R1_FB25          CAN_F2R1_FB25_Msk                             
#define CAN_F2R1_FB26_Pos      (26U)                                         
#define CAN_F2R1_FB26_Msk      (0x1UL << CAN_F2R1_FB26_Pos)                  
#define CAN_F2R1_FB26          CAN_F2R1_FB26_Msk                             
#define CAN_F2R1_FB27_Pos      (27U)                                         
#define CAN_F2R1_FB27_Msk      (0x1UL << CAN_F2R1_FB27_Pos)                  
#define CAN_F2R1_FB27          CAN_F2R1_FB27_Msk                             
#define CAN_F2R1_FB28_Pos      (28U)                                         
#define CAN_F2R1_FB28_Msk      (0x1UL << CAN_F2R1_FB28_Pos)                  
#define CAN_F2R1_FB28          CAN_F2R1_FB28_Msk                             
#define CAN_F2R1_FB29_Pos      (29U)                                         
#define CAN_F2R1_FB29_Msk      (0x1UL << CAN_F2R1_FB29_Pos)                  
#define CAN_F2R1_FB29          CAN_F2R1_FB29_Msk                             
#define CAN_F2R1_FB30_Pos      (30U)                                         
#define CAN_F2R1_FB30_Msk      (0x1UL << CAN_F2R1_FB30_Pos)                  
#define CAN_F2R1_FB30          CAN_F2R1_FB30_Msk                             
#define CAN_F2R1_FB31_Pos      (31U)                                         
#define CAN_F2R1_FB31_Msk      (0x1UL << CAN_F2R1_FB31_Pos)                  
#define CAN_F2R1_FB31          CAN_F2R1_FB31_Msk                             

/*******************  Bit definition for CAN_F3R1 register  *******************/
#define CAN_F3R1_FB0_Pos       (0U)                                            
#define CAN_F3R1_FB0_Msk       (0x1UL << CAN_F3R1_FB0_Pos)                      
#define CAN_F3R1_FB0           CAN_F3R1_FB0_Msk                              
#define CAN_F3R1_FB1_Pos       (1U)                                          
#define CAN_F3R1_FB1_Msk       (0x1UL << CAN_F3R1_FB1_Pos)                   
#define CAN_F3R1_FB1           CAN_F3R1_FB1_Msk                              
#define CAN_F3R1_FB2_Pos       (2U)                                          
#define CAN_F3R1_FB2_Msk       (0x1UL << CAN_F3R1_FB2_Pos)                   
#define CAN_F3R1_FB2           CAN_F3R1_FB2_Msk                              
#define CAN_F3R1_FB3_Pos       (3U)                                          
#define CAN_F3R1_FB3_Msk       (0x1UL << CAN_F3R1_FB3_Pos)                   
#define CAN_F3R1_FB3           CAN_F3R1_FB3_Msk                              
#define CAN_F3R1_FB4_Pos       (4U)                                          
#define CAN_F3R1_FB4_Msk       (0x1UL << CAN_F3R1_FB4_Pos)                   
#define CAN_F3R1_FB4           CAN_F3R1_FB4_Msk                              
#define CAN_F3R1_FB5_Pos       (5U)                                          
#define CAN_F3R1_FB5_Msk       (0x1UL << CAN_F3R1_FB5_Pos)                   
#define CAN_F3R1_FB5           CAN_F3R1_FB5_Msk                              
#define CAN_F3R1_FB6_Pos       (6U)                                          
#define CAN_F3R1_FB6_Msk       (0x1UL << CAN_F3R1_FB6_Pos)                   
#define CAN_F3R1_FB6           CAN_F3R1_FB6_Msk                              
#define CAN_F3R1_FB7_Pos       (7U)                                          
#define CAN_F3R1_FB7_Msk       (0x1UL << CAN_F3R1_FB7_Pos)                   
#define CAN_F3R1_FB7           CAN_F3R1_FB7_Msk                              
#define CAN_F3R1_FB8_Pos       (8U)                                          
#define CAN_F3R1_FB8_Msk       (0x1UL << CAN_F3R1_FB8_Pos)                   
#define CAN_F3R1_FB8           CAN_F3R1_FB8_Msk                              
#define CAN_F3R1_FB9_Pos       (9U)                                          
#define CAN_F3R1_FB9_Msk       (0x1UL << CAN_F3R1_FB9_Pos)                   
#define CAN_F3R1_FB9           CAN_F3R1_FB9_Msk                              
#define CAN_F3R1_FB10_Pos      (10U)                                         
#define CAN_F3R1_FB10_Msk      (0x1UL << CAN_F3R1_FB10_Pos)                  
#define CAN_F3R1_FB10          CAN_F3R1_FB10_Msk                             
#define CAN_F3R1_FB11_Pos      (11U)                                         
#define CAN_F3R1_FB11_Msk      (0x1UL << CAN_F3R1_FB11_Pos)                  
#define CAN_F3R1_FB11          CAN_F3R1_FB11_Msk                             
#define CAN_F3R1_FB12_Pos      (12U)                                         
#define CAN_F3R1_FB12_Msk      (0x1UL << CAN_F3R1_FB12_Pos)                  
#define CAN_F3R1_FB12          CAN_F3R1_FB12_Msk                             
#define CAN_F3R1_FB13_Pos      (13U)                                         
#define CAN_F3R1_FB13_Msk      (0x1UL << CAN_F3R1_FB13_Pos)                  
#define CAN_F3R1_FB13          CAN_F3R1_FB13_Msk                             
#define CAN_F3R1_FB14_Pos      (14U)                                         
#define CAN_F3R1_FB14_Msk      (0x1UL << CAN_F3R1_FB14_Pos)                  
#define CAN_F3R1_FB14          CAN_F3R1_FB14_Msk                             
#define CAN_F3R1_FB15_Pos      (15U)                                         
#define CAN_F3R1_FB15_Msk      (0x1UL << CAN_F3R1_FB15_Pos)                  
#define CAN_F3R1_FB15          CAN_F3R1_FB15_Msk                             
#define CAN_F3R1_FB16_Pos      (16U)                                         
#define CAN_F3R1_FB16_Msk      (0x1UL << CAN_F3R1_FB16_Pos)                  
#define CAN_F3R1_FB16          CAN_F3R1_FB16_Msk                             
#define CAN_F3R1_FB17_Pos      (17U)                                         
#define CAN_F3R1_FB17_Msk      (0x1UL << CAN_F3R1_FB17_Pos)                  
#define CAN_F3R1_FB17          CAN_F3R1_FB17_Msk                             
#define CAN_F3R1_FB18_Pos      (18U)                                         
#define CAN_F3R1_FB18_Msk      (0x1UL << CAN_F3R1_FB18_Pos)                  
#define CAN_F3R1_FB18          CAN_F3R1_FB18_Msk                             
#define CAN_F3R1_FB19_Pos      (19U)                                         
#define CAN_F3R1_FB19_Msk      (0x1UL << CAN_F3R1_FB19_Pos)                  
#define CAN_F3R1_FB19          CAN_F3R1_FB19_Msk                             
#define CAN_F3R1_FB20_Pos      (20U)                                         
#define CAN_F3R1_FB20_Msk      (0x1UL << CAN_F3R1_FB20_Pos)                  
#define CAN_F3R1_FB20          CAN_F3R1_FB20_Msk                             
#define CAN_F3R1_FB21_Pos      (21U)                                         
#define CAN_F3R1_FB21_Msk      (0x1UL << CAN_F3R1_FB21_Pos)                  
#define CAN_F3R1_FB21          CAN_F3R1_FB21_Msk                             
#define CAN_F3R1_FB22_Pos      (22U)                                         
#define CAN_F3R1_FB22_Msk      (0x1UL << CAN_F3R1_FB22_Pos)                  
#define CAN_F3R1_FB22          CAN_F3R1_FB22_Msk                             
#define CAN_F3R1_FB23_Pos      (23U)                                         
#define CAN_F3R1_FB23_Msk      (0x1UL << CAN_F3R1_FB23_Pos)                  
#define CAN_F3R1_FB23          CAN_F3R1_FB23_Msk                             
#define CAN_F3R1_FB24_Pos      (24U)                                         
#define CAN_F3R1_FB24_Msk      (0x1UL << CAN_F3R1_FB24_Pos)                  
#define CAN_F3R1_FB24          CAN_F3R1_FB24_Msk                             
#define CAN_F3R1_FB25_Pos      (25U)                                         
#define CAN_F3R1_FB25_Msk      (0x1UL << CAN_F3R1_FB25_Pos)                  
#define CAN_F3R1_FB25          CAN_F3R1_FB25_Msk                             
#define CAN_F3R1_FB26_Pos      (26U)                                         
#define CAN_F3R1_FB26_Msk      (0x1UL << CAN_F3R1_FB26_Pos)                  
#define CAN_F3R1_FB26          CAN_F3R1_FB26_Msk                             
#define CAN_F3R1_FB27_Pos      (27U)                                         
#define CAN_F3R1_FB27_Msk      (0x1UL << CAN_F3R1_FB27_Pos)                  
#define CAN_F3R1_FB27          CAN_F3R1_FB27_Msk                             
#define CAN_F3R1_FB28_Pos      (28U)                                         
#define CAN_F3R1_FB28_Msk      (0x1UL << CAN_F3R1_FB28_Pos)                  
#define CAN_F3R1_FB28          CAN_F3R1_FB28_Msk                             
#define CAN_F3R1_FB29_Pos      (29U)                                         
#define CAN_F3R1_FB29_Msk      (0x1UL << CAN_F3R1_FB29_Pos)                  
#define CAN_F3R1_FB29          CAN_F3R1_FB29_Msk                             
#define CAN_F3R1_FB30_Pos      (30U)                                         
#define CAN_F3R1_FB30_Msk      (0x1UL << CAN_F3R1_FB30_Pos)                  
#define CAN_F3R1_FB30          CAN_F3R1_FB30_Msk                             
#define CAN_F3R1_FB31_Pos      (31U)                                         
#define CAN_F3R1_FB31_Msk      (0x1UL << CAN_F3R1_FB31_Pos)                  
#define CAN_F3R1_FB31          CAN_F3R1_FB31_Msk                             

/*******************  Bit definition for CAN_F4R1 register  *******************/
#define CAN_F4R1_FB0_Pos       (0U)                                            
#define CAN_F4R1_FB0_Msk       (0x1UL << CAN_F4R1_FB0_Pos)                      
#define CAN_F4R1_FB0           CAN_F4R1_FB0_Msk                              
#define CAN_F4R1_FB1_Pos       (1U)                                          
#define CAN_F4R1_FB1_Msk       (0x1UL << CAN_F4R1_FB1_Pos)                   
#define CAN_F4R1_FB1           CAN_F4R1_FB1_Msk                              
#define CAN_F4R1_FB2_Pos       (2U)                                          
#define CAN_F4R1_FB2_Msk       (0x1UL << CAN_F4R1_FB2_Pos)                   
#define CAN_F4R1_FB2           CAN_F4R1_FB2_Msk                              
#define CAN_F4R1_FB3_Pos       (3U)                                          
#define CAN_F4R1_FB3_Msk       (0x1UL << CAN_F4R1_FB3_Pos)                   
#define CAN_F4R1_FB3           CAN_F4R1_FB3_Msk                              
#define CAN_F4R1_FB4_Pos       (4U)                                          
#define CAN_F4R1_FB4_Msk       (0x1UL << CAN_F4R1_FB4_Pos)                   
#define CAN_F4R1_FB4           CAN_F4R1_FB4_Msk                              
#define CAN_F4R1_FB5_Pos       (5U)                                          
#define CAN_F4R1_FB5_Msk       (0x1UL << CAN_F4R1_FB5_Pos)                   
#define CAN_F4R1_FB5           CAN_F4R1_FB5_Msk                              
#define CAN_F4R1_FB6_Pos       (6U)                                          
#define CAN_F4R1_FB6_Msk       (0x1UL << CAN_F4R1_FB6_Pos)                   
#define CAN_F4R1_FB6           CAN_F4R1_FB6_Msk                              
#define CAN_F4R1_FB7_Pos       (7U)                                          
#define CAN_F4R1_FB7_Msk       (0x1UL << CAN_F4R1_FB7_Pos)                   
#define CAN_F4R1_FB7           CAN_F4R1_FB7_Msk                              
#define CAN_F4R1_FB8_Pos       (8U)                                          
#define CAN_F4R1_FB8_Msk       (0x1UL << CAN_F4R1_FB8_Pos)                   
#define CAN_F4R1_FB8           CAN_F4R1_FB8_Msk                              
#define CAN_F4R1_FB9_Pos       (9U)                                          
#define CAN_F4R1_FB9_Msk       (0x1UL << CAN_F4R1_FB9_Pos)                   
#define CAN_F4R1_FB9           CAN_F4R1_FB9_Msk                              
#define CAN_F4R1_FB10_Pos      (10U)                                         
#define CAN_F4R1_FB10_Msk      (0x1UL << CAN_F4R1_FB10_Pos)                  
#define CAN_F4R1_FB10          CAN_F4R1_FB10_Msk                             
#define CAN_F4R1_FB11_Pos      (11U)                                         
#define CAN_F4R1_FB11_Msk      (0x1UL << CAN_F4R1_FB11_Pos)                  
#define CAN_F4R1_FB11          CAN_F4R1_FB11_Msk                             
#define CAN_F4R1_FB12_Pos      (12U)                                         
#define CAN_F4R1_FB12_Msk      (0x1UL << CAN_F4R1_FB12_Pos)                  
#define CAN_F4R1_FB12          CAN_F4R1_FB12_Msk                             
#define CAN_F4R1_FB13_Pos      (13U)                                         
#define CAN_F4R1_FB13_Msk      (0x1UL << CAN_F4R1_FB13_Pos)                  
#define CAN_F4R1_FB13          CAN_F4R1_FB13_Msk                             
#define CAN_F4R1_FB14_Pos      (14U)                                         
#define CAN_F4R1_FB14_Msk      (0x1UL << CAN_F4R1_FB14_Pos)                  
#define CAN_F4R1_FB14          CAN_F4R1_FB14_Msk                             
#define CAN_F4R1_FB15_Pos      (15U)                                         
#define CAN_F4R1_FB15_Msk      (0x1UL << CAN_F4R1_FB15_Pos)                  
#define CAN_F4R1_FB15          CAN_F4R1_FB15_Msk                             
#define CAN_F4R1_FB16_Pos      (16U)                                         
#define CAN_F4R1_FB16_Msk      (0x1UL << CAN_F4R1_FB16_Pos)                  
#define CAN_F4R1_FB16          CAN_F4R1_FB16_Msk                             
#define CAN_F4R1_FB17_Pos      (17U)                                         
#define CAN_F4R1_FB17_Msk      (0x1UL << CAN_F4R1_FB17_Pos)                  
#define CAN_F4R1_FB17          CAN_F4R1_FB17_Msk                             
#define CAN_F4R1_FB18_Pos      (18U)                                         
#define CAN_F4R1_FB18_Msk      (0x1UL << CAN_F4R1_FB18_Pos)                  
#define CAN_F4R1_FB18          CAN_F4R1_FB18_Msk                             
#define CAN_F4R1_FB19_Pos      (19U)                                         
#define CAN_F4R1_FB19_Msk      (0x1UL << CAN_F4R1_FB19_Pos)                  
#define CAN_F4R1_FB19          CAN_F4R1_FB19_Msk                             
#define CAN_F4R1_FB20_Pos      (20U)                                         
#define CAN_F4R1_FB20_Msk      (0x1UL << CAN_F4R1_FB20_Pos)                  
#define CAN_F4R1_FB20          CAN_F4R1_FB20_Msk                             
#define CAN_F4R1_FB21_Pos      (21U)                                         
#define CAN_F4R1_FB21_Msk      (0x1UL << CAN_F4R1_FB21_Pos)                  
#define CAN_F4R1_FB21          CAN_F4R1_FB21_Msk                             
#define CAN_F4R1_FB22_Pos      (22U)                                         
#define CAN_F4R1_FB22_Msk      (0x1UL << CAN_F4R1_FB22_Pos)                  
#define CAN_F4R1_FB22          CAN_F4R1_FB22_Msk                             
#define CAN_F4R1_FB23_Pos      (23U)                                         
#define CAN_F4R1_FB23_Msk      (0x1UL << CAN_F4R1_FB23_Pos)                  
#define CAN_F4R1_FB23          CAN_F4R1_FB23_Msk                             
#define CAN_F4R1_FB24_Pos      (24U)                                         
#define CAN_F4R1_FB24_Msk      (0x1UL << CAN_F4R1_FB24_Pos)                  
#define CAN_F4R1_FB24          CAN_F4R1_FB24_Msk                             
#define CAN_F4R1_FB25_Pos      (25U)                                         
#define CAN_F4R1_FB25_Msk      (0x1UL << CAN_F4R1_FB25_Pos)                  
#define CAN_F4R1_FB25          CAN_F4R1_FB25_Msk                             
#define CAN_F4R1_FB26_Pos      (26U)                                         
#define CAN_F4R1_FB26_Msk      (0x1UL << CAN_F4R1_FB26_Pos)                  
#define CAN_F4R1_FB26          CAN_F4R1_FB26_Msk                             
#define CAN_F4R1_FB27_Pos      (27U)                                         
#define CAN_F4R1_FB27_Msk      (0x1UL << CAN_F4R1_FB27_Pos)                  
#define CAN_F4R1_FB27          CAN_F4R1_FB27_Msk                             
#define CAN_F4R1_FB28_Pos      (28U)                                         
#define CAN_F4R1_FB28_Msk      (0x1UL << CAN_F4R1_FB28_Pos)                  
#define CAN_F4R1_FB28          CAN_F4R1_FB28_Msk                             
#define CAN_F4R1_FB29_Pos      (29U)                                         
#define CAN_F4R1_FB29_Msk      (0x1UL << CAN_F4R1_FB29_Pos)                  
#define CAN_F4R1_FB29          CAN_F4R1_FB29_Msk                             
#define CAN_F4R1_FB30_Pos      (30U)                                         
#define CAN_F4R1_FB30_Msk      (0x1UL << CAN_F4R1_FB30_Pos)                  
#define CAN_F4R1_FB30          CAN_F4R1_FB30_Msk                             
#define CAN_F4R1_FB31_Pos      (31U)                                         
#define CAN_F4R1_FB31_Msk      (0x1UL << CAN_F4R1_FB31_Pos)                  
#define CAN_F4R1_FB31          CAN_F4R1_FB31_Msk                             

/*******************  Bit definition for CAN_F5R1 register  *******************/
#define CAN_F5R1_FB0_Pos       (0U)                                            
#define CAN_F5R1_FB0_Msk       (0x1UL << CAN_F5R1_FB0_Pos)                      
#define CAN_F5R1_FB0           CAN_F5R1_FB0_Msk                             
#define CAN_F5R1_FB1_Pos       (1U)                                         
#define CAN_F5R1_FB1_Msk       (0x1UL << CAN_F5R1_FB1_Pos)                  
#define CAN_F5R1_FB1           CAN_F5R1_FB1_Msk                             
#define CAN_F5R1_FB2_Pos       (2U)                                         
#define CAN_F5R1_FB2_Msk       (0x1UL << CAN_F5R1_FB2_Pos)                  
#define CAN_F5R1_FB2           CAN_F5R1_FB2_Msk                             
#define CAN_F5R1_FB3_Pos       (3U)                                         
#define CAN_F5R1_FB3_Msk       (0x1UL << CAN_F5R1_FB3_Pos)                  
#define CAN_F5R1_FB3           CAN_F5R1_FB3_Msk                             
#define CAN_F5R1_FB4_Pos       (4U)                                         
#define CAN_F5R1_FB4_Msk       (0x1UL << CAN_F5R1_FB4_Pos)                  
#define CAN_F5R1_FB4           CAN_F5R1_FB4_Msk                             
#define CAN_F5R1_FB5_Pos       (5U)                                         
#define CAN_F5R1_FB5_Msk       (0x1UL << CAN_F5R1_FB5_Pos)                  
#define CAN_F5R1_FB5           CAN_F5R1_FB5_Msk                             
#define CAN_F5R1_FB6_Pos       (6U)                                         
#define CAN_F5R1_FB6_Msk       (0x1UL << CAN_F5R1_FB6_Pos)                  
#define CAN_F5R1_FB6           CAN_F5R1_FB6_Msk                             
#define CAN_F5R1_FB7_Pos       (7U)                                         
#define CAN_F5R1_FB7_Msk       (0x1UL << CAN_F5R1_FB7_Pos)                  
#define CAN_F5R1_FB7           CAN_F5R1_FB7_Msk                             
#define CAN_F5R1_FB8_Pos       (8U)                                         
#define CAN_F5R1_FB8_Msk       (0x1UL << CAN_F5R1_FB8_Pos)                  
#define CAN_F5R1_FB8           CAN_F5R1_FB8_Msk                             
#define CAN_F5R1_FB9_Pos       (9U)                                         
#define CAN_F5R1_FB9_Msk       (0x1UL << CAN_F5R1_FB9_Pos)                  
#define CAN_F5R1_FB9           CAN_F5R1_FB9_Msk                             
#define CAN_F5R1_FB10_Pos      (10U)                                        
#define CAN_F5R1_FB10_Msk      (0x1UL << CAN_F5R1_FB10_Pos)                 
#define CAN_F5R1_FB10          CAN_F5R1_FB10_Msk                            
#define CAN_F5R1_FB11_Pos      (11U)                                        
#define CAN_F5R1_FB11_Msk      (0x1UL << CAN_F5R1_FB11_Pos)                 
#define CAN_F5R1_FB11          CAN_F5R1_FB11_Msk                            
#define CAN_F5R1_FB12_Pos      (12U)                                        
#define CAN_F5R1_FB12_Msk      (0x1UL << CAN_F5R1_FB12_Pos)                 
#define CAN_F5R1_FB12          CAN_F5R1_FB12_Msk                            
#define CAN_F5R1_FB13_Pos      (13U)                                        
#define CAN_F5R1_FB13_Msk      (0x1UL << CAN_F5R1_FB13_Pos)                 
#define CAN_F5R1_FB13          CAN_F5R1_FB13_Msk                            
#define CAN_F5R1_FB14_Pos      (14U)                                        
#define CAN_F5R1_FB14_Msk      (0x1UL << CAN_F5R1_FB14_Pos)                 
#define CAN_F5R1_FB14          CAN_F5R1_FB14_Msk                            
#define CAN_F5R1_FB15_Pos      (15U)                                        
#define CAN_F5R1_FB15_Msk      (0x1UL << CAN_F5R1_FB15_Pos)                 
#define CAN_F5R1_FB15          CAN_F5R1_FB15_Msk                            
#define CAN_F5R1_FB16_Pos      (16U)                                        
#define CAN_F5R1_FB16_Msk      (0x1UL << CAN_F5R1_FB16_Pos)                 
#define CAN_F5R1_FB16          CAN_F5R1_FB16_Msk                            
#define CAN_F5R1_FB17_Pos      (17U)                                        
#define CAN_F5R1_FB17_Msk      (0x1UL << CAN_F5R1_FB17_Pos)                 
#define CAN_F5R1_FB17          CAN_F5R1_FB17_Msk                            
#define CAN_F5R1_FB18_Pos      (18U)                                        
#define CAN_F5R1_FB18_Msk      (0x1UL << CAN_F5R1_FB18_Pos)                 
#define CAN_F5R1_FB18          CAN_F5R1_FB18_Msk                            
#define CAN_F5R1_FB19_Pos      (19U)                                        
#define CAN_F5R1_FB19_Msk      (0x1UL << CAN_F5R1_FB19_Pos)                 
#define CAN_F5R1_FB19          CAN_F5R1_FB19_Msk                            
#define CAN_F5R1_FB20_Pos      (20U)                                        
#define CAN_F5R1_FB20_Msk      (0x1UL << CAN_F5R1_FB20_Pos)                 
#define CAN_F5R1_FB20          CAN_F5R1_FB20_Msk                            
#define CAN_F5R1_FB21_Pos      (21U)                                        
#define CAN_F5R1_FB21_Msk      (0x1UL << CAN_F5R1_FB21_Pos)                 
#define CAN_F5R1_FB21          CAN_F5R1_FB21_Msk                            
#define CAN_F5R1_FB22_Pos      (22U)                                        
#define CAN_F5R1_FB22_Msk      (0x1UL << CAN_F5R1_FB22_Pos)                 
#define CAN_F5R1_FB22          CAN_F5R1_FB22_Msk                            
#define CAN_F5R1_FB23_Pos      (23U)                                        
#define CAN_F5R1_FB23_Msk      (0x1UL << CAN_F5R1_FB23_Pos)                 
#define CAN_F5R1_FB23          CAN_F5R1_FB23_Msk                            
#define CAN_F5R1_FB24_Pos      (24U)                                        
#define CAN_F5R1_FB24_Msk      (0x1UL << CAN_F5R1_FB24_Pos)                 
#define CAN_F5R1_FB24          CAN_F5R1_FB24_Msk                            
#define CAN_F5R1_FB25_Pos      (25U)                                        
#define CAN_F5R1_FB25_Msk      (0x1UL << CAN_F5R1_FB25_Pos)                 
#define CAN_F5R1_FB25          CAN_F5R1_FB25_Msk                            
#define CAN_F5R1_FB26_Pos      (26U)                                        
#define CAN_F5R1_FB26_Msk      (0x1UL << CAN_F5R1_FB26_Pos)                 
#define CAN_F5R1_FB26          CAN_F5R1_FB26_Msk                            
#define CAN_F5R1_FB27_Pos      (27U)                                        
#define CAN_F5R1_FB27_Msk      (0x1UL << CAN_F5R1_FB27_Pos)                 
#define CAN_F5R1_FB27          CAN_F5R1_FB27_Msk                            
#define CAN_F5R1_FB28_Pos      (28U)                                        
#define CAN_F5R1_FB28_Msk      (0x1UL << CAN_F5R1_FB28_Pos)                 
#define CAN_F5R1_FB28          CAN_F5R1_FB28_Msk                            
#define CAN_F5R1_FB29_Pos      (29U)                                        
#define CAN_F5R1_FB29_Msk      (0x1UL << CAN_F5R1_FB29_Pos)                 
#define CAN_F5R1_FB29          CAN_F5R1_FB29_Msk                            
#define CAN_F5R1_FB30_Pos      (30U)                                        
#define CAN_F5R1_FB30_Msk      (0x1UL << CAN_F5R1_FB30_Pos)                 
#define CAN_F5R1_FB30          CAN_F5R1_FB30_Msk                            
#define CAN_F5R1_FB31_Pos      (31U)                                        
#define CAN_F5R1_FB31_Msk      (0x1UL << CAN_F5R1_FB31_Pos)                 
#define CAN_F5R1_FB31          CAN_F5R1_FB31_Msk                            

/*******************  Bit definition for CAN_F6R1 register  *******************/
#define CAN_F6R1_FB0_Pos       (0U)                                            
#define CAN_F6R1_FB0_Msk       (0x1UL << CAN_F6R1_FB0_Pos)                      
#define CAN_F6R1_FB0           CAN_F6R1_FB0_Msk                              
#define CAN_F6R1_FB1_Pos       (1U)                                          
#define CAN_F6R1_FB1_Msk       (0x1UL << CAN_F6R1_FB1_Pos)                   
#define CAN_F6R1_FB1           CAN_F6R1_FB1_Msk                              
#define CAN_F6R1_FB2_Pos       (2U)                                          
#define CAN_F6R1_FB2_Msk       (0x1UL << CAN_F6R1_FB2_Pos)                   
#define CAN_F6R1_FB2           CAN_F6R1_FB2_Msk                              
#define CAN_F6R1_FB3_Pos       (3U)                                          
#define CAN_F6R1_FB3_Msk       (0x1UL << CAN_F6R1_FB3_Pos)                   
#define CAN_F6R1_FB3           CAN_F6R1_FB3_Msk                              
#define CAN_F6R1_FB4_Pos       (4U)                                          
#define CAN_F6R1_FB4_Msk       (0x1UL << CAN_F6R1_FB4_Pos)                   
#define CAN_F6R1_FB4           CAN_F6R1_FB4_Msk                              
#define CAN_F6R1_FB5_Pos       (5U)                                          
#define CAN_F6R1_FB5_Msk       (0x1UL << CAN_F6R1_FB5_Pos)                   
#define CAN_F6R1_FB5           CAN_F6R1_FB5_Msk                              
#define CAN_F6R1_FB6_Pos       (6U)                                          
#define CAN_F6R1_FB6_Msk       (0x1UL << CAN_F6R1_FB6_Pos)                   
#define CAN_F6R1_FB6           CAN_F6R1_FB6_Msk                              
#define CAN_F6R1_FB7_Pos       (7U)                                          
#define CAN_F6R1_FB7_Msk       (0x1UL << CAN_F6R1_FB7_Pos)                   
#define CAN_F6R1_FB7           CAN_F6R1_FB7_Msk                              
#define CAN_F6R1_FB8_Pos       (8U)                                          
#define CAN_F6R1_FB8_Msk       (0x1UL << CAN_F6R1_FB8_Pos)                   
#define CAN_F6R1_FB8           CAN_F6R1_FB8_Msk                              
#define CAN_F6R1_FB9_Pos       (9U)                                          
#define CAN_F6R1_FB9_Msk       (0x1UL << CAN_F6R1_FB9_Pos)                   
#define CAN_F6R1_FB9           CAN_F6R1_FB9_Msk                              
#define CAN_F6R1_FB10_Pos      (10U)                                         
#define CAN_F6R1_FB10_Msk      (0x1UL << CAN_F6R1_FB10_Pos)                  
#define CAN_F6R1_FB10          CAN_F6R1_FB10_Msk                             
#define CAN_F6R1_FB11_Pos      (11U)                                         
#define CAN_F6R1_FB11_Msk      (0x1UL << CAN_F6R1_FB11_Pos)                  
#define CAN_F6R1_FB11          CAN_F6R1_FB11_Msk                             
#define CAN_F6R1_FB12_Pos      (12U)                                         
#define CAN_F6R1_FB12_Msk      (0x1UL << CAN_F6R1_FB12_Pos)                  
#define CAN_F6R1_FB12          CAN_F6R1_FB12_Msk                             
#define CAN_F6R1_FB13_Pos      (13U)                                         
#define CAN_F6R1_FB13_Msk      (0x1UL << CAN_F6R1_FB13_Pos)                  
#define CAN_F6R1_FB13          CAN_F6R1_FB13_Msk                             
#define CAN_F6R1_FB14_Pos      (14U)                                         
#define CAN_F6R1_FB14_Msk      (0x1UL << CAN_F6R1_FB14_Pos)                  
#define CAN_F6R1_FB14          CAN_F6R1_FB14_Msk                             
#define CAN_F6R1_FB15_Pos      (15U)                                         
#define CAN_F6R1_FB15_Msk      (0x1UL << CAN_F6R1_FB15_Pos)                  
#define CAN_F6R1_FB15          CAN_F6R1_FB15_Msk                             
#define CAN_F6R1_FB16_Pos      (16U)                                         
#define CAN_F6R1_FB16_Msk      (0x1UL << CAN_F6R1_FB16_Pos)                  
#define CAN_F6R1_FB16          CAN_F6R1_FB16_Msk                             
#define CAN_F6R1_FB17_Pos      (17U)                                         
#define CAN_F6R1_FB17_Msk      (0x1UL << CAN_F6R1_FB17_Pos)                  
#define CAN_F6R1_FB17          CAN_F6R1_FB17_Msk                             
#define CAN_F6R1_FB18_Pos      (18U)                                         
#define CAN_F6R1_FB18_Msk      (0x1UL << CAN_F6R1_FB18_Pos)                  
#define CAN_F6R1_FB18          CAN_F6R1_FB18_Msk                             
#define CAN_F6R1_FB19_Pos      (19U)                                         
#define CAN_F6R1_FB19_Msk      (0x1UL << CAN_F6R1_FB19_Pos)                  
#define CAN_F6R1_FB19          CAN_F6R1_FB19_Msk                             
#define CAN_F6R1_FB20_Pos      (20U)                                         
#define CAN_F6R1_FB20_Msk      (0x1UL << CAN_F6R1_FB20_Pos)                  
#define CAN_F6R1_FB20          CAN_F6R1_FB20_Msk                             
#define CAN_F6R1_FB21_Pos      (21U)                                         
#define CAN_F6R1_FB21_Msk      (0x1UL << CAN_F6R1_FB21_Pos)                  
#define CAN_F6R1_FB21          CAN_F6R1_FB21_Msk                             
#define CAN_F6R1_FB22_Pos      (22U)                                         
#define CAN_F6R1_FB22_Msk      (0x1UL << CAN_F6R1_FB22_Pos)                  
#define CAN_F6R1_FB22          CAN_F6R1_FB22_Msk                             
#define CAN_F6R1_FB23_Pos      (23U)                                         
#define CAN_F6R1_FB23_Msk      (0x1UL << CAN_F6R1_FB23_Pos)                  
#define CAN_F6R1_FB23          CAN_F6R1_FB23_Msk                             
#define CAN_F6R1_FB24_Pos      (24U)                                         
#define CAN_F6R1_FB24_Msk      (0x1UL << CAN_F6R1_FB24_Pos)                  
#define CAN_F6R1_FB24          CAN_F6R1_FB24_Msk                             
#define CAN_F6R1_FB25_Pos      (25U)                                         
#define CAN_F6R1_FB25_Msk      (0x1UL << CAN_F6R1_FB25_Pos)                  
#define CAN_F6R1_FB25          CAN_F6R1_FB25_Msk                             
#define CAN_F6R1_FB26_Pos      (26U)                                         
#define CAN_F6R1_FB26_Msk      (0x1UL << CAN_F6R1_FB26_Pos)                  
#define CAN_F6R1_FB26          CAN_F6R1_FB26_Msk                             
#define CAN_F6R1_FB27_Pos      (27U)                                         
#define CAN_F6R1_FB27_Msk      (0x1UL << CAN_F6R1_FB27_Pos)                  
#define CAN_F6R1_FB27          CAN_F6R1_FB27_Msk                             
#define CAN_F6R1_FB28_Pos      (28U)                                         
#define CAN_F6R1_FB28_Msk      (0x1UL << CAN_F6R1_FB28_Pos)                  
#define CAN_F6R1_FB28          CAN_F6R1_FB28_Msk                             
#define CAN_F6R1_FB29_Pos      (29U)                                         
#define CAN_F6R1_FB29_Msk      (0x1UL << CAN_F6R1_FB29_Pos)                  
#define CAN_F6R1_FB29          CAN_F6R1_FB29_Msk                             
#define CAN_F6R1_FB30_Pos      (30U)                                         
#define CAN_F6R1_FB30_Msk      (0x1UL << CAN_F6R1_FB30_Pos)                  
#define CAN_F6R1_FB30          CAN_F6R1_FB30_Msk                             
#define CAN_F6R1_FB31_Pos      (31U)                                         
#define CAN_F6R1_FB31_Msk      (0x1UL << CAN_F6R1_FB31_Pos)                  
#define CAN_F6R1_FB31          CAN_F6R1_FB31_Msk                             

/*******************  Bit definition for CAN_F7R1 register  *******************/
#define CAN_F7R1_FB0_Pos       (0U)                                            
#define CAN_F7R1_FB0_Msk       (0x1UL << CAN_F7R1_FB0_Pos)                      
#define CAN_F7R1_FB0           CAN_F7R1_FB0_Msk                              
#define CAN_F7R1_FB1_Pos       (1U)                                          
#define CAN_F7R1_FB1_Msk       (0x1UL << CAN_F7R1_FB1_Pos)                   
#define CAN_F7R1_FB1           CAN_F7R1_FB1_Msk                              
#define CAN_F7R1_FB2_Pos       (2U)                                          
#define CAN_F7R1_FB2_Msk       (0x1UL << CAN_F7R1_FB2_Pos)                   
#define CAN_F7R1_FB2           CAN_F7R1_FB2_Msk                              
#define CAN_F7R1_FB3_Pos       (3U)                                          
#define CAN_F7R1_FB3_Msk       (0x1UL << CAN_F7R1_FB3_Pos)                   
#define CAN_F7R1_FB3           CAN_F7R1_FB3_Msk                              
#define CAN_F7R1_FB4_Pos       (4U)                                          
#define CAN_F7R1_FB4_Msk       (0x1UL << CAN_F7R1_FB4_Pos)                   
#define CAN_F7R1_FB4           CAN_F7R1_FB4_Msk                              
#define CAN_F7R1_FB5_Pos       (5U)                                          
#define CAN_F7R1_FB5_Msk       (0x1UL << CAN_F7R1_FB5_Pos)                   
#define CAN_F7R1_FB5           CAN_F7R1_FB5_Msk                              
#define CAN_F7R1_FB6_Pos       (6U)                                          
#define CAN_F7R1_FB6_Msk       (0x1UL << CAN_F7R1_FB6_Pos)                   
#define CAN_F7R1_FB6           CAN_F7R1_FB6_Msk                              
#define CAN_F7R1_FB7_Pos       (7U)                                          
#define CAN_F7R1_FB7_Msk       (0x1UL << CAN_F7R1_FB7_Pos)                   
#define CAN_F7R1_FB7           CAN_F7R1_FB7_Msk                              
#define CAN_F7R1_FB8_Pos       (8U)                                          
#define CAN_F7R1_FB8_Msk       (0x1UL << CAN_F7R1_FB8_Pos)                   
#define CAN_F7R1_FB8           CAN_F7R1_FB8_Msk                              
#define CAN_F7R1_FB9_Pos       (9U)                                          
#define CAN_F7R1_FB9_Msk       (0x1UL << CAN_F7R1_FB9_Pos)                   
#define CAN_F7R1_FB9           CAN_F7R1_FB9_Msk                              
#define CAN_F7R1_FB10_Pos      (10U)                                         
#define CAN_F7R1_FB10_Msk      (0x1UL << CAN_F7R1_FB10_Pos)                  
#define CAN_F7R1_FB10          CAN_F7R1_FB10_Msk                             
#define CAN_F7R1_FB11_Pos      (11U)                                         
#define CAN_F7R1_FB11_Msk      (0x1UL << CAN_F7R1_FB11_Pos)                  
#define CAN_F7R1_FB11          CAN_F7R1_FB11_Msk                             
#define CAN_F7R1_FB12_Pos      (12U)                                         
#define CAN_F7R1_FB12_Msk      (0x1UL << CAN_F7R1_FB12_Pos)                  
#define CAN_F7R1_FB12          CAN_F7R1_FB12_Msk                             
#define CAN_F7R1_FB13_Pos      (13U)                                         
#define CAN_F7R1_FB13_Msk      (0x1UL << CAN_F7R1_FB13_Pos)                  
#define CAN_F7R1_FB13          CAN_F7R1_FB13_Msk                             
#define CAN_F7R1_FB14_Pos      (14U)                                         
#define CAN_F7R1_FB14_Msk      (0x1UL << CAN_F7R1_FB14_Pos)                  
#define CAN_F7R1_FB14          CAN_F7R1_FB14_Msk                             
#define CAN_F7R1_FB15_Pos      (15U)                                         
#define CAN_F7R1_FB15_Msk      (0x1UL << CAN_F7R1_FB15_Pos)                  
#define CAN_F7R1_FB15          CAN_F7R1_FB15_Msk                             
#define CAN_F7R1_FB16_Pos      (16U)                                         
#define CAN_F7R1_FB16_Msk      (0x1UL << CAN_F7R1_FB16_Pos)                  
#define CAN_F7R1_FB16          CAN_F7R1_FB16_Msk                             
#define CAN_F7R1_FB17_Pos      (17U)                                         
#define CAN_F7R1_FB17_Msk      (0x1UL << CAN_F7R1_FB17_Pos)                  
#define CAN_F7R1_FB17          CAN_F7R1_FB17_Msk                             
#define CAN_F7R1_FB18_Pos      (18U)                                         
#define CAN_F7R1_FB18_Msk      (0x1UL << CAN_F7R1_FB18_Pos)                  
#define CAN_F7R1_FB18          CAN_F7R1_FB18_Msk                             
#define CAN_F7R1_FB19_Pos      (19U)                                         
#define CAN_F7R1_FB19_Msk      (0x1UL << CAN_F7R1_FB19_Pos)                  
#define CAN_F7R1_FB19          CAN_F7R1_FB19_Msk                             
#define CAN_F7R1_FB20_Pos      (20U)                                         
#define CAN_F7R1_FB20_Msk      (0x1UL << CAN_F7R1_FB20_Pos)                  
#define CAN_F7R1_FB20          CAN_F7R1_FB20_Msk                             
#define CAN_F7R1_FB21_Pos      (21U)                                         
#define CAN_F7R1_FB21_Msk      (0x1UL << CAN_F7R1_FB21_Pos)                  
#define CAN_F7R1_FB21          CAN_F7R1_FB21_Msk                             
#define CAN_F7R1_FB22_Pos      (22U)                                         
#define CAN_F7R1_FB22_Msk      (0x1UL << CAN_F7R1_FB22_Pos)                  
#define CAN_F7R1_FB22          CAN_F7R1_FB22_Msk                             
#define CAN_F7R1_FB23_Pos      (23U)                                         
#define CAN_F7R1_FB23_Msk      (0x1UL << CAN_F7R1_FB23_Pos)                  
#define CAN_F7R1_FB23          CAN_F7R1_FB23_Msk                             
#define CAN_F7R1_FB24_Pos      (24U)                                         
#define CAN_F7R1_FB24_Msk      (0x1UL << CAN_F7R1_FB24_Pos)                  
#define CAN_F7R1_FB24          CAN_F7R1_FB24_Msk                             
#define CAN_F7R1_FB25_Pos      (25U)                                         
#define CAN_F7R1_FB25_Msk      (0x1UL << CAN_F7R1_FB25_Pos)                  
#define CAN_F7R1_FB25          CAN_F7R1_FB25_Msk                             
#define CAN_F7R1_FB26_Pos      (26U)                                         
#define CAN_F7R1_FB26_Msk      (0x1UL << CAN_F7R1_FB26_Pos)                  
#define CAN_F7R1_FB26          CAN_F7R1_FB26_Msk                             
#define CAN_F7R1_FB27_Pos      (27U)                                         
#define CAN_F7R1_FB27_Msk      (0x1UL << CAN_F7R1_FB27_Pos)                  
#define CAN_F7R1_FB27          CAN_F7R1_FB27_Msk                             
#define CAN_F7R1_FB28_Pos      (28U)                                         
#define CAN_F7R1_FB28_Msk      (0x1UL << CAN_F7R1_FB28_Pos)                  
#define CAN_F7R1_FB28          CAN_F7R1_FB28_Msk                             
#define CAN_F7R1_FB29_Pos      (29U)                                         
#define CAN_F7R1_FB29_Msk      (0x1UL << CAN_F7R1_FB29_Pos)                  
#define CAN_F7R1_FB29          CAN_F7R1_FB29_Msk                             
#define CAN_F7R1_FB30_Pos      (30U)                                         
#define CAN_F7R1_FB30_Msk      (0x1UL << CAN_F7R1_FB30_Pos)                  
#define CAN_F7R1_FB30          CAN_F7R1_FB30_Msk                             
#define CAN_F7R1_FB31_Pos      (31U)                                         
#define CAN_F7R1_FB31_Msk      (0x1UL << CAN_F7R1_FB31_Pos)                  
#define CAN_F7R1_FB31          CAN_F7R1_FB31_Msk                             

/*******************  Bit definition for CAN_F8R1 register  *******************/
#define CAN_F8R1_FB0_Pos       (0U)                                            
#define CAN_F8R1_FB0_Msk       (0x1UL << CAN_F8R1_FB0_Pos)                      
#define CAN_F8R1_FB0           CAN_F8R1_FB0_Msk                               
#define CAN_F8R1_FB1_Pos       (1U)                                           
#define CAN_F8R1_FB1_Msk       (0x1UL << CAN_F8R1_FB1_Pos)                    
#define CAN_F8R1_FB1           CAN_F8R1_FB1_Msk                               
#define CAN_F8R1_FB2_Pos       (2U)                                           
#define CAN_F8R1_FB2_Msk       (0x1UL << CAN_F8R1_FB2_Pos)                    
#define CAN_F8R1_FB2           CAN_F8R1_FB2_Msk                               
#define CAN_F8R1_FB3_Pos       (3U)                                           
#define CAN_F8R1_FB3_Msk       (0x1UL << CAN_F8R1_FB3_Pos)                    
#define CAN_F8R1_FB3           CAN_F8R1_FB3_Msk                               
#define CAN_F8R1_FB4_Pos       (4U)                                           
#define CAN_F8R1_FB4_Msk       (0x1UL << CAN_F8R1_FB4_Pos)                    
#define CAN_F8R1_FB4           CAN_F8R1_FB4_Msk                               
#define CAN_F8R1_FB5_Pos       (5U)                                           
#define CAN_F8R1_FB5_Msk       (0x1UL << CAN_F8R1_FB5_Pos)                    
#define CAN_F8R1_FB5           CAN_F8R1_FB5_Msk                               
#define CAN_F8R1_FB6_Pos       (6U)                                           
#define CAN_F8R1_FB6_Msk       (0x1UL << CAN_F8R1_FB6_Pos)                    
#define CAN_F8R1_FB6           CAN_F8R1_FB6_Msk                               
#define CAN_F8R1_FB7_Pos       (7U)                                           
#define CAN_F8R1_FB7_Msk       (0x1UL << CAN_F8R1_FB7_Pos)                    
#define CAN_F8R1_FB7           CAN_F8R1_FB7_Msk                               
#define CAN_F8R1_FB8_Pos       (8U)                                           
#define CAN_F8R1_FB8_Msk       (0x1UL << CAN_F8R1_FB8_Pos)                    
#define CAN_F8R1_FB8           CAN_F8R1_FB8_Msk                               
#define CAN_F8R1_FB9_Pos       (9U)                                           
#define CAN_F8R1_FB9_Msk       (0x1UL << CAN_F8R1_FB9_Pos)                    
#define CAN_F8R1_FB9           CAN_F8R1_FB9_Msk                               
#define CAN_F8R1_FB10_Pos      (10U)                                          
#define CAN_F8R1_FB10_Msk      (0x1UL << CAN_F8R1_FB10_Pos)                   
#define CAN_F8R1_FB10          CAN_F8R1_FB10_Msk                              
#define CAN_F8R1_FB11_Pos      (11U)                                          
#define CAN_F8R1_FB11_Msk      (0x1UL << CAN_F8R1_FB11_Pos)                   
#define CAN_F8R1_FB11          CAN_F8R1_FB11_Msk                              
#define CAN_F8R1_FB12_Pos      (12U)                                          
#define CAN_F8R1_FB12_Msk      (0x1UL << CAN_F8R1_FB12_Pos)                   
#define CAN_F8R1_FB12          CAN_F8R1_FB12_Msk                              
#define CAN_F8R1_FB13_Pos      (13U)                                          
#define CAN_F8R1_FB13_Msk      (0x1UL << CAN_F8R1_FB13_Pos)                   
#define CAN_F8R1_FB13          CAN_F8R1_FB13_Msk                              
#define CAN_F8R1_FB14_Pos      (14U)                                          
#define CAN_F8R1_FB14_Msk      (0x1UL << CAN_F8R1_FB14_Pos)                   
#define CAN_F8R1_FB14          CAN_F8R1_FB14_Msk                              
#define CAN_F8R1_FB15_Pos      (15U)                                          
#define CAN_F8R1_FB15_Msk      (0x1UL << CAN_F8R1_FB15_Pos)                   
#define CAN_F8R1_FB15          CAN_F8R1_FB15_Msk                              
#define CAN_F8R1_FB16_Pos      (16U)                                          
#define CAN_F8R1_FB16_Msk      (0x1UL << CAN_F8R1_FB16_Pos)                   
#define CAN_F8R1_FB16          CAN_F8R1_FB16_Msk                              
#define CAN_F8R1_FB17_Pos      (17U)                                          
#define CAN_F8R1_FB17_Msk      (0x1UL << CAN_F8R1_FB17_Pos)                   
#define CAN_F8R1_FB17          CAN_F8R1_FB17_Msk                              
#define CAN_F8R1_FB18_Pos      (18U)                                          
#define CAN_F8R1_FB18_Msk      (0x1UL << CAN_F8R1_FB18_Pos)                   
#define CAN_F8R1_FB18          CAN_F8R1_FB18_Msk                              
#define CAN_F8R1_FB19_Pos      (19U)                                          
#define CAN_F8R1_FB19_Msk      (0x1UL << CAN_F8R1_FB19_Pos)                   
#define CAN_F8R1_FB19          CAN_F8R1_FB19_Msk                              
#define CAN_F8R1_FB20_Pos      (20U)                                          
#define CAN_F8R1_FB20_Msk      (0x1UL << CAN_F8R1_FB20_Pos)                   
#define CAN_F8R1_FB20          CAN_F8R1_FB20_Msk                              
#define CAN_F8R1_FB21_Pos      (21U)                                          
#define CAN_F8R1_FB21_Msk      (0x1UL << CAN_F8R1_FB21_Pos)                   
#define CAN_F8R1_FB21          CAN_F8R1_FB21_Msk                              
#define CAN_F8R1_FB22_Pos      (22U)                                          
#define CAN_F8R1_FB22_Msk      (0x1UL << CAN_F8R1_FB22_Pos)                   
#define CAN_F8R1_FB22          CAN_F8R1_FB22_Msk                              
#define CAN_F8R1_FB23_Pos      (23U)                                          
#define CAN_F8R1_FB23_Msk      (0x1UL << CAN_F8R1_FB23_Pos)                   
#define CAN_F8R1_FB23          CAN_F8R1_FB23_Msk                              
#define CAN_F8R1_FB24_Pos      (24U)                                          
#define CAN_F8R1_FB24_Msk      (0x1UL << CAN_F8R1_FB24_Pos)                   
#define CAN_F8R1_FB24          CAN_F8R1_FB24_Msk                              
#define CAN_F8R1_FB25_Pos      (25U)                                          
#define CAN_F8R1_FB25_Msk      (0x1UL << CAN_F8R1_FB25_Pos)                   
#define CAN_F8R1_FB25          CAN_F8R1_FB25_Msk                              
#define CAN_F8R1_FB26_Pos      (26U)                                          
#define CAN_F8R1_FB26_Msk      (0x1UL << CAN_F8R1_FB26_Pos)                   
#define CAN_F8R1_FB26          CAN_F8R1_FB26_Msk                              
#define CAN_F8R1_FB27_Pos      (27U)                                          
#define CAN_F8R1_FB27_Msk      (0x1UL << CAN_F8R1_FB27_Pos)                   
#define CAN_F8R1_FB27          CAN_F8R1_FB27_Msk                              
#define CAN_F8R1_FB28_Pos      (28U)                                          
#define CAN_F8R1_FB28_Msk      (0x1UL << CAN_F8R1_FB28_Pos)                   
#define CAN_F8R1_FB28          CAN_F8R1_FB28_Msk                              
#define CAN_F8R1_FB29_Pos      (29U)                                          
#define CAN_F8R1_FB29_Msk      (0x1UL << CAN_F8R1_FB29_Pos)                   
#define CAN_F8R1_FB29          CAN_F8R1_FB29_Msk                              
#define CAN_F8R1_FB30_Pos      (30U)                                          
#define CAN_F8R1_FB30_Msk      (0x1UL << CAN_F8R1_FB30_Pos)                   
#define CAN_F8R1_FB30          CAN_F8R1_FB30_Msk                              
#define CAN_F8R1_FB31_Pos      (31U)                                          
#define CAN_F8R1_FB31_Msk      (0x1UL << CAN_F8R1_FB31_Pos)                   
#define CAN_F8R1_FB31          CAN_F8R1_FB31_Msk                              

/*******************  Bit definition for CAN_F9R1 register  *******************/
#define CAN_F9R1_FB0_Pos       (0U)                                            
#define CAN_F9R1_FB0_Msk       (0x1UL << CAN_F9R1_FB0_Pos)                      
#define CAN_F9R1_FB0           CAN_F9R1_FB0_Msk                               
#define CAN_F9R1_FB1_Pos       (1U)                                           
#define CAN_F9R1_FB1_Msk       (0x1UL << CAN_F9R1_FB1_Pos)                    
#define CAN_F9R1_FB1           CAN_F9R1_FB1_Msk                               
#define CAN_F9R1_FB2_Pos       (2U)                                           
#define CAN_F9R1_FB2_Msk       (0x1UL << CAN_F9R1_FB2_Pos)                    
#define CAN_F9R1_FB2           CAN_F9R1_FB2_Msk                               
#define CAN_F9R1_FB3_Pos       (3U)                                           
#define CAN_F9R1_FB3_Msk       (0x1UL << CAN_F9R1_FB3_Pos)                    
#define CAN_F9R1_FB3           CAN_F9R1_FB3_Msk                               
#define CAN_F9R1_FB4_Pos       (4U)                                           
#define CAN_F9R1_FB4_Msk       (0x1UL << CAN_F9R1_FB4_Pos)                    
#define CAN_F9R1_FB4           CAN_F9R1_FB4_Msk                               
#define CAN_F9R1_FB5_Pos       (5U)                                           
#define CAN_F9R1_FB5_Msk       (0x1UL << CAN_F9R1_FB5_Pos)                    
#define CAN_F9R1_FB5           CAN_F9R1_FB5_Msk                               
#define CAN_F9R1_FB6_Pos       (6U)                                           
#define CAN_F9R1_FB6_Msk       (0x1UL << CAN_F9R1_FB6_Pos)                    
#define CAN_F9R1_FB6           CAN_F9R1_FB6_Msk                               
#define CAN_F9R1_FB7_Pos       (7U)                                           
#define CAN_F9R1_FB7_Msk       (0x1UL << CAN_F9R1_FB7_Pos)                    
#define CAN_F9R1_FB7           CAN_F9R1_FB7_Msk                               
#define CAN_F9R1_FB8_Pos       (8U)                                           
#define CAN_F9R1_FB8_Msk       (0x1UL << CAN_F9R1_FB8_Pos)                    
#define CAN_F9R1_FB8           CAN_F9R1_FB8_Msk                               
#define CAN_F9R1_FB9_Pos       (9U)                                           
#define CAN_F9R1_FB9_Msk       (0x1UL << CAN_F9R1_FB9_Pos)                    
#define CAN_F9R1_FB9           CAN_F9R1_FB9_Msk                               
#define CAN_F9R1_FB10_Pos      (10U)                                          
#define CAN_F9R1_FB10_Msk      (0x1UL << CAN_F9R1_FB10_Pos)                   
#define CAN_F9R1_FB10          CAN_F9R1_FB10_Msk                              
#define CAN_F9R1_FB11_Pos      (11U)                                          
#define CAN_F9R1_FB11_Msk      (0x1UL << CAN_F9R1_FB11_Pos)                   
#define CAN_F9R1_FB11          CAN_F9R1_FB11_Msk                              
#define CAN_F9R1_FB12_Pos      (12U)                                          
#define CAN_F9R1_FB12_Msk      (0x1UL << CAN_F9R1_FB12_Pos)                   
#define CAN_F9R1_FB12          CAN_F9R1_FB12_Msk                              
#define CAN_F9R1_FB13_Pos      (13U)                                          
#define CAN_F9R1_FB13_Msk      (0x1UL << CAN_F9R1_FB13_Pos)                   
#define CAN_F9R1_FB13          CAN_F9R1_FB13_Msk                              
#define CAN_F9R1_FB14_Pos      (14U)                                          
#define CAN_F9R1_FB14_Msk      (0x1UL << CAN_F9R1_FB14_Pos)                   
#define CAN_F9R1_FB14          CAN_F9R1_FB14_Msk                              
#define CAN_F9R1_FB15_Pos      (15U)                                          
#define CAN_F9R1_FB15_Msk      (0x1UL << CAN_F9R1_FB15_Pos)                   
#define CAN_F9R1_FB15          CAN_F9R1_FB15_Msk                              
#define CAN_F9R1_FB16_Pos      (16U)                                          
#define CAN_F9R1_FB16_Msk      (0x1UL << CAN_F9R1_FB16_Pos)                   
#define CAN_F9R1_FB16          CAN_F9R1_FB16_Msk                              
#define CAN_F9R1_FB17_Pos      (17U)                                          
#define CAN_F9R1_FB17_Msk      (0x1UL << CAN_F9R1_FB17_Pos)                   
#define CAN_F9R1_FB17          CAN_F9R1_FB17_Msk                              
#define CAN_F9R1_FB18_Pos      (18U)                                          
#define CAN_F9R1_FB18_Msk      (0x1UL << CAN_F9R1_FB18_Pos)                   
#define CAN_F9R1_FB18          CAN_F9R1_FB18_Msk                              
#define CAN_F9R1_FB19_Pos      (19U)                                          
#define CAN_F9R1_FB19_Msk      (0x1UL << CAN_F9R1_FB19_Pos)                   
#define CAN_F9R1_FB19          CAN_F9R1_FB19_Msk                              
#define CAN_F9R1_FB20_Pos      (20U)                                          
#define CAN_F9R1_FB20_Msk      (0x1UL << CAN_F9R1_FB20_Pos)                   
#define CAN_F9R1_FB20          CAN_F9R1_FB20_Msk                              
#define CAN_F9R1_FB21_Pos      (21U)                                          
#define CAN_F9R1_FB21_Msk      (0x1UL << CAN_F9R1_FB21_Pos)                   
#define CAN_F9R1_FB21          CAN_F9R1_FB21_Msk                              
#define CAN_F9R1_FB22_Pos      (22U)                                          
#define CAN_F9R1_FB22_Msk      (0x1UL << CAN_F9R1_FB22_Pos)                   
#define CAN_F9R1_FB22          CAN_F9R1_FB22_Msk                              
#define CAN_F9R1_FB23_Pos      (23U)                                          
#define CAN_F9R1_FB23_Msk      (0x1UL << CAN_F9R1_FB23_Pos)                   
#define CAN_F9R1_FB23          CAN_F9R1_FB23_Msk                              
#define CAN_F9R1_FB24_Pos      (24U)                                          
#define CAN_F9R1_FB24_Msk      (0x1UL << CAN_F9R1_FB24_Pos)                   
#define CAN_F9R1_FB24          CAN_F9R1_FB24_Msk                              
#define CAN_F9R1_FB25_Pos      (25U)                                          
#define CAN_F9R1_FB25_Msk      (0x1UL << CAN_F9R1_FB25_Pos)                   
#define CAN_F9R1_FB25          CAN_F9R1_FB25_Msk                              
#define CAN_F9R1_FB26_Pos      (26U)                                          
#define CAN_F9R1_FB26_Msk      (0x1UL << CAN_F9R1_FB26_Pos)                   
#define CAN_F9R1_FB26          CAN_F9R1_FB26_Msk                              
#define CAN_F9R1_FB27_Pos      (27U)                                          
#define CAN_F9R1_FB27_Msk      (0x1UL << CAN_F9R1_FB27_Pos)                   
#define CAN_F9R1_FB27          CAN_F9R1_FB27_Msk                              
#define CAN_F9R1_FB28_Pos      (28U)                                          
#define CAN_F9R1_FB28_Msk      (0x1UL << CAN_F9R1_FB28_Pos)                   
#define CAN_F9R1_FB28          CAN_F9R1_FB28_Msk                              
#define CAN_F9R1_FB29_Pos      (29U)                                          
#define CAN_F9R1_FB29_Msk      (0x1UL << CAN_F9R1_FB29_Pos)                   
#define CAN_F9R1_FB29          CAN_F9R1_FB29_Msk                              
#define CAN_F9R1_FB30_Pos      (30U)                                          
#define CAN_F9R1_FB30_Msk      (0x1UL << CAN_F9R1_FB30_Pos)                   
#define CAN_F9R1_FB30          CAN_F9R1_FB30_Msk                              
#define CAN_F9R1_FB31_Pos      (31U)                                          
#define CAN_F9R1_FB31_Msk      (0x1UL << CAN_F9R1_FB31_Pos)                   
#define CAN_F9R1_FB31          CAN_F9R1_FB31_Msk                              

/*******************  Bit definition for CAN_F10R1 register  ******************/
#define CAN_F10R1_FB0_Pos      (0U)                                            
#define CAN_F10R1_FB0_Msk      (0x1UL << CAN_F10R1_FB0_Pos)                     
#define CAN_F10R1_FB0          CAN_F10R1_FB0_Msk                              
#define CAN_F10R1_FB1_Pos      (1U)                                           
#define CAN_F10R1_FB1_Msk      (0x1UL << CAN_F10R1_FB1_Pos)                   
#define CAN_F10R1_FB1          CAN_F10R1_FB1_Msk                              
#define CAN_F10R1_FB2_Pos      (2U)                                           
#define CAN_F10R1_FB2_Msk      (0x1UL << CAN_F10R1_FB2_Pos)                   
#define CAN_F10R1_FB2          CAN_F10R1_FB2_Msk                              
#define CAN_F10R1_FB3_Pos      (3U)                                           
#define CAN_F10R1_FB3_Msk      (0x1UL << CAN_F10R1_FB3_Pos)                   
#define CAN_F10R1_FB3          CAN_F10R1_FB3_Msk                              
#define CAN_F10R1_FB4_Pos      (4U)                                           
#define CAN_F10R1_FB4_Msk      (0x1UL << CAN_F10R1_FB4_Pos)                   
#define CAN_F10R1_FB4          CAN_F10R1_FB4_Msk                              
#define CAN_F10R1_FB5_Pos      (5U)                                           
#define CAN_F10R1_FB5_Msk      (0x1UL << CAN_F10R1_FB5_Pos)                   
#define CAN_F10R1_FB5          CAN_F10R1_FB5_Msk                              
#define CAN_F10R1_FB6_Pos      (6U)                                           
#define CAN_F10R1_FB6_Msk      (0x1UL << CAN_F10R1_FB6_Pos)                   
#define CAN_F10R1_FB6          CAN_F10R1_FB6_Msk                              
#define CAN_F10R1_FB7_Pos      (7U)                                           
#define CAN_F10R1_FB7_Msk      (0x1UL << CAN_F10R1_FB7_Pos)                   
#define CAN_F10R1_FB7          CAN_F10R1_FB7_Msk                              
#define CAN_F10R1_FB8_Pos      (8U)                                           
#define CAN_F10R1_FB8_Msk      (0x1UL << CAN_F10R1_FB8_Pos)                   
#define CAN_F10R1_FB8          CAN_F10R1_FB8_Msk                              
#define CAN_F10R1_FB9_Pos      (9U)                                           
#define CAN_F10R1_FB9_Msk      (0x1UL << CAN_F10R1_FB9_Pos)                   
#define CAN_F10R1_FB9          CAN_F10R1_FB9_Msk                              
#define CAN_F10R1_FB10_Pos     (10U)                                          
#define CAN_F10R1_FB10_Msk     (0x1UL << CAN_F10R1_FB10_Pos)                  
#define CAN_F10R1_FB10         CAN_F10R1_FB10_Msk                             
#define CAN_F10R1_FB11_Pos     (11U)                                          
#define CAN_F10R1_FB11_Msk     (0x1UL << CAN_F10R1_FB11_Pos)                  
#define CAN_F10R1_FB11         CAN_F10R1_FB11_Msk                             
#define CAN_F10R1_FB12_Pos     (12U)                                          
#define CAN_F10R1_FB12_Msk     (0x1UL << CAN_F10R1_FB12_Pos)                  
#define CAN_F10R1_FB12         CAN_F10R1_FB12_Msk                             
#define CAN_F10R1_FB13_Pos     (13U)                                          
#define CAN_F10R1_FB13_Msk     (0x1UL << CAN_F10R1_FB13_Pos)                  
#define CAN_F10R1_FB13         CAN_F10R1_FB13_Msk                             
#define CAN_F10R1_FB14_Pos     (14U)                                          
#define CAN_F10R1_FB14_Msk     (0x1UL << CAN_F10R1_FB14_Pos)                  
#define CAN_F10R1_FB14         CAN_F10R1_FB14_Msk                             
#define CAN_F10R1_FB15_Pos     (15U)                                          
#define CAN_F10R1_FB15_Msk     (0x1UL << CAN_F10R1_FB15_Pos)                  
#define CAN_F10R1_FB15         CAN_F10R1_FB15_Msk                             
#define CAN_F10R1_FB16_Pos     (16U)                                          
#define CAN_F10R1_FB16_Msk     (0x1UL << CAN_F10R1_FB16_Pos)                  
#define CAN_F10R1_FB16         CAN_F10R1_FB16_Msk                             
#define CAN_F10R1_FB17_Pos     (17U)                                          
#define CAN_F10R1_FB17_Msk     (0x1UL << CAN_F10R1_FB17_Pos)                  
#define CAN_F10R1_FB17         CAN_F10R1_FB17_Msk                             
#define CAN_F10R1_FB18_Pos     (18U)                                          
#define CAN_F10R1_FB18_Msk     (0x1UL << CAN_F10R1_FB18_Pos)                  
#define CAN_F10R1_FB18         CAN_F10R1_FB18_Msk                             
#define CAN_F10R1_FB19_Pos     (19U)                                          
#define CAN_F10R1_FB19_Msk     (0x1UL << CAN_F10R1_FB19_Pos)                  
#define CAN_F10R1_FB19         CAN_F10R1_FB19_Msk                             
#define CAN_F10R1_FB20_Pos     (20U)                                          
#define CAN_F10R1_FB20_Msk     (0x1UL << CAN_F10R1_FB20_Pos)                  
#define CAN_F10R1_FB20         CAN_F10R1_FB20_Msk                             
#define CAN_F10R1_FB21_Pos     (21U)                                          
#define CAN_F10R1_FB21_Msk     (0x1UL << CAN_F10R1_FB21_Pos)                  
#define CAN_F10R1_FB21         CAN_F10R1_FB21_Msk                             
#define CAN_F10R1_FB22_Pos     (22U)                                          
#define CAN_F10R1_FB22_Msk     (0x1UL << CAN_F10R1_FB22_Pos)                  
#define CAN_F10R1_FB22         CAN_F10R1_FB22_Msk                             
#define CAN_F10R1_FB23_Pos     (23U)                                          
#define CAN_F10R1_FB23_Msk     (0x1UL << CAN_F10R1_FB23_Pos)                  
#define CAN_F10R1_FB23         CAN_F10R1_FB23_Msk                             
#define CAN_F10R1_FB24_Pos     (24U)                                          
#define CAN_F10R1_FB24_Msk     (0x1UL << CAN_F10R1_FB24_Pos)                  
#define CAN_F10R1_FB24         CAN_F10R1_FB24_Msk                             
#define CAN_F10R1_FB25_Pos     (25U)                                          
#define CAN_F10R1_FB25_Msk     (0x1UL << CAN_F10R1_FB25_Pos)                  
#define CAN_F10R1_FB25         CAN_F10R1_FB25_Msk                             
#define CAN_F10R1_FB26_Pos     (26U)                                          
#define CAN_F10R1_FB26_Msk     (0x1UL << CAN_F10R1_FB26_Pos)                  
#define CAN_F10R1_FB26         CAN_F10R1_FB26_Msk                             
#define CAN_F10R1_FB27_Pos     (27U)                                          
#define CAN_F10R1_FB27_Msk     (0x1UL << CAN_F10R1_FB27_Pos)                  
#define CAN_F10R1_FB27         CAN_F10R1_FB27_Msk                             
#define CAN_F10R1_FB28_Pos     (28U)                                          
#define CAN_F10R1_FB28_Msk     (0x1UL << CAN_F10R1_FB28_Pos)                  
#define CAN_F10R1_FB28         CAN_F10R1_FB28_Msk                             
#define CAN_F10R1_FB29_Pos     (29U)                                          
#define CAN_F10R1_FB29_Msk     (0x1UL << CAN_F10R1_FB29_Pos)                  
#define CAN_F10R1_FB29         CAN_F10R1_FB29_Msk                             
#define CAN_F10R1_FB30_Pos     (30U)                                          
#define CAN_F10R1_FB30_Msk     (0x1UL << CAN_F10R1_FB30_Pos)                  
#define CAN_F10R1_FB30         CAN_F10R1_FB30_Msk                             
#define CAN_F10R1_FB31_Pos     (31U)                                          
#define CAN_F10R1_FB31_Msk     (0x1UL << CAN_F10R1_FB31_Pos)                  
#define CAN_F10R1_FB31         CAN_F10R1_FB31_Msk                             

/*******************  Bit definition for CAN_F11R1 register  ******************/
#define CAN_F11R1_FB0_Pos      (0U)                                            
#define CAN_F11R1_FB0_Msk      (0x1UL << CAN_F11R1_FB0_Pos)                     
#define CAN_F11R1_FB0          CAN_F11R1_FB0_Msk                              
#define CAN_F11R1_FB1_Pos      (1U)                                           
#define CAN_F11R1_FB1_Msk      (0x1UL << CAN_F11R1_FB1_Pos)                   
#define CAN_F11R1_FB1          CAN_F11R1_FB1_Msk                              
#define CAN_F11R1_FB2_Pos      (2U)                                           
#define CAN_F11R1_FB2_Msk      (0x1UL << CAN_F11R1_FB2_Pos)                   
#define CAN_F11R1_FB2          CAN_F11R1_FB2_Msk                              
#define CAN_F11R1_FB3_Pos      (3U)                                           
#define CAN_F11R1_FB3_Msk      (0x1UL << CAN_F11R1_FB3_Pos)                   
#define CAN_F11R1_FB3          CAN_F11R1_FB3_Msk                              
#define CAN_F11R1_FB4_Pos      (4U)                                           
#define CAN_F11R1_FB4_Msk      (0x1UL << CAN_F11R1_FB4_Pos)                   
#define CAN_F11R1_FB4          CAN_F11R1_FB4_Msk                              
#define CAN_F11R1_FB5_Pos      (5U)                                           
#define CAN_F11R1_FB5_Msk      (0x1UL << CAN_F11R1_FB5_Pos)                   
#define CAN_F11R1_FB5          CAN_F11R1_FB5_Msk                              
#define CAN_F11R1_FB6_Pos      (6U)                                           
#define CAN_F11R1_FB6_Msk      (0x1UL << CAN_F11R1_FB6_Pos)                   
#define CAN_F11R1_FB6          CAN_F11R1_FB6_Msk                              
#define CAN_F11R1_FB7_Pos      (7U)                                           
#define CAN_F11R1_FB7_Msk      (0x1UL << CAN_F11R1_FB7_Pos)                   
#define CAN_F11R1_FB7          CAN_F11R1_FB7_Msk                              
#define CAN_F11R1_FB8_Pos      (8U)                                           
#define CAN_F11R1_FB8_Msk      (0x1UL << CAN_F11R1_FB8_Pos)                   
#define CAN_F11R1_FB8          CAN_F11R1_FB8_Msk                              
#define CAN_F11R1_FB9_Pos      (9U)                                           
#define CAN_F11R1_FB9_Msk      (0x1UL << CAN_F11R1_FB9_Pos)                   
#define CAN_F11R1_FB9          CAN_F11R1_FB9_Msk                              
#define CAN_F11R1_FB10_Pos     (10U)                                          
#define CAN_F11R1_FB10_Msk     (0x1UL << CAN_F11R1_FB10_Pos)                  
#define CAN_F11R1_FB10         CAN_F11R1_FB10_Msk                             
#define CAN_F11R1_FB11_Pos     (11U)                                          
#define CAN_F11R1_FB11_Msk     (0x1UL << CAN_F11R1_FB11_Pos)                  
#define CAN_F11R1_FB11         CAN_F11R1_FB11_Msk                             
#define CAN_F11R1_FB12_Pos     (12U)                                          
#define CAN_F11R1_FB12_Msk     (0x1UL << CAN_F11R1_FB12_Pos)                  
#define CAN_F11R1_FB12         CAN_F11R1_FB12_Msk                             
#define CAN_F11R1_FB13_Pos     (13U)                                          
#define CAN_F11R1_FB13_Msk     (0x1UL << CAN_F11R1_FB13_Pos)                  
#define CAN_F11R1_FB13         CAN_F11R1_FB13_Msk                             
#define CAN_F11R1_FB14_Pos     (14U)                                          
#define CAN_F11R1_FB14_Msk     (0x1UL << CAN_F11R1_FB14_Pos)                  
#define CAN_F11R1_FB14         CAN_F11R1_FB14_Msk                             
#define CAN_F11R1_FB15_Pos     (15U)                                          
#define CAN_F11R1_FB15_Msk     (0x1UL << CAN_F11R1_FB15_Pos)                  
#define CAN_F11R1_FB15         CAN_F11R1_FB15_Msk                             
#define CAN_F11R1_FB16_Pos     (16U)                                          
#define CAN_F11R1_FB16_Msk     (0x1UL << CAN_F11R1_FB16_Pos)                  
#define CAN_F11R1_FB16         CAN_F11R1_FB16_Msk                             
#define CAN_F11R1_FB17_Pos     (17U)                                          
#define CAN_F11R1_FB17_Msk     (0x1UL << CAN_F11R1_FB17_Pos)                  
#define CAN_F11R1_FB17         CAN_F11R1_FB17_Msk                             
#define CAN_F11R1_FB18_Pos     (18U)                                          
#define CAN_F11R1_FB18_Msk     (0x1UL << CAN_F11R1_FB18_Pos)                  
#define CAN_F11R1_FB18         CAN_F11R1_FB18_Msk                             
#define CAN_F11R1_FB19_Pos     (19U)                                          
#define CAN_F11R1_FB19_Msk     (0x1UL << CAN_F11R1_FB19_Pos)                  
#define CAN_F11R1_FB19         CAN_F11R1_FB19_Msk                             
#define CAN_F11R1_FB20_Pos     (20U)                                          
#define CAN_F11R1_FB20_Msk     (0x1UL << CAN_F11R1_FB20_Pos)                  
#define CAN_F11R1_FB20         CAN_F11R1_FB20_Msk                             
#define CAN_F11R1_FB21_Pos     (21U)                                          
#define CAN_F11R1_FB21_Msk     (0x1UL << CAN_F11R1_FB21_Pos)                  
#define CAN_F11R1_FB21         CAN_F11R1_FB21_Msk                             
#define CAN_F11R1_FB22_Pos     (22U)                                          
#define CAN_F11R1_FB22_Msk     (0x1UL << CAN_F11R1_FB22_Pos)                  
#define CAN_F11R1_FB22         CAN_F11R1_FB22_Msk                             
#define CAN_F11R1_FB23_Pos     (23U)                                          
#define CAN_F11R1_FB23_Msk     (0x1UL << CAN_F11R1_FB23_Pos)                  
#define CAN_F11R1_FB23         CAN_F11R1_FB23_Msk                             
#define CAN_F11R1_FB24_Pos     (24U)                                          
#define CAN_F11R1_FB24_Msk     (0x1UL << CAN_F11R1_FB24_Pos)                  
#define CAN_F11R1_FB24         CAN_F11R1_FB24_Msk                             
#define CAN_F11R1_FB25_Pos     (25U)                                          
#define CAN_F11R1_FB25_Msk     (0x1UL << CAN_F11R1_FB25_Pos)                  
#define CAN_F11R1_FB25         CAN_F11R1_FB25_Msk                             
#define CAN_F11R1_FB26_Pos     (26U)                                          
#define CAN_F11R1_FB26_Msk     (0x1UL << CAN_F11R1_FB26_Pos)                  
#define CAN_F11R1_FB26         CAN_F11R1_FB26_Msk                             
#define CAN_F11R1_FB27_Pos     (27U)                                          
#define CAN_F11R1_FB27_Msk     (0x1UL << CAN_F11R1_FB27_Pos)                  
#define CAN_F11R1_FB27         CAN_F11R1_FB27_Msk                             
#define CAN_F11R1_FB28_Pos     (28U)                                          
#define CAN_F11R1_FB28_Msk     (0x1UL << CAN_F11R1_FB28_Pos)                  
#define CAN_F11R1_FB28         CAN_F11R1_FB28_Msk                             
#define CAN_F11R1_FB29_Pos     (29U)                                          
#define CAN_F11R1_FB29_Msk     (0x1UL << CAN_F11R1_FB29_Pos)                  
#define CAN_F11R1_FB29         CAN_F11R1_FB29_Msk                             
#define CAN_F11R1_FB30_Pos     (30U)                                          
#define CAN_F11R1_FB30_Msk     (0x1UL << CAN_F11R1_FB30_Pos)                  
#define CAN_F11R1_FB30         CAN_F11R1_FB30_Msk                             
#define CAN_F11R1_FB31_Pos     (31U)                                          
#define CAN_F11R1_FB31_Msk     (0x1UL << CAN_F11R1_FB31_Pos)                  
#define CAN_F11R1_FB31         CAN_F11R1_FB31_Msk                             

/*******************  Bit definition for CAN_F12R1 register  ******************/
#define CAN_F12R1_FB0_Pos      (0U)                                            
#define CAN_F12R1_FB0_Msk      (0x1UL << CAN_F12R1_FB0_Pos)                     
#define CAN_F12R1_FB0          CAN_F12R1_FB0_Msk                              
#define CAN_F12R1_FB1_Pos      (1U)                                           
#define CAN_F12R1_FB1_Msk      (0x1UL << CAN_F12R1_FB1_Pos)                   
#define CAN_F12R1_FB1          CAN_F12R1_FB1_Msk                              
#define CAN_F12R1_FB2_Pos      (2U)                                           
#define CAN_F12R1_FB2_Msk      (0x1UL << CAN_F12R1_FB2_Pos)                   
#define CAN_F12R1_FB2          CAN_F12R1_FB2_Msk                              
#define CAN_F12R1_FB3_Pos      (3U)                                           
#define CAN_F12R1_FB3_Msk      (0x1UL << CAN_F12R1_FB3_Pos)                   
#define CAN_F12R1_FB3          CAN_F12R1_FB3_Msk                              
#define CAN_F12R1_FB4_Pos      (4U)                                           
#define CAN_F12R1_FB4_Msk      (0x1UL << CAN_F12R1_FB4_Pos)                   
#define CAN_F12R1_FB4          CAN_F12R1_FB4_Msk                              
#define CAN_F12R1_FB5_Pos      (5U)                                           
#define CAN_F12R1_FB5_Msk      (0x1UL << CAN_F12R1_FB5_Pos)                   
#define CAN_F12R1_FB5          CAN_F12R1_FB5_Msk                              
#define CAN_F12R1_FB6_Pos      (6U)                                           
#define CAN_F12R1_FB6_Msk      (0x1UL << CAN_F12R1_FB6_Pos)                   
#define CAN_F12R1_FB6          CAN_F12R1_FB6_Msk                              
#define CAN_F12R1_FB7_Pos      (7U)                                           
#define CAN_F12R1_FB7_Msk      (0x1UL << CAN_F12R1_FB7_Pos)                   
#define CAN_F12R1_FB7          CAN_F12R1_FB7_Msk                              
#define CAN_F12R1_FB8_Pos      (8U)                                           
#define CAN_F12R1_FB8_Msk      (0x1UL << CAN_F12R1_FB8_Pos)                   
#define CAN_F12R1_FB8          CAN_F12R1_FB8_Msk                              
#define CAN_F12R1_FB9_Pos      (9U)                                           
#define CAN_F12R1_FB9_Msk      (0x1UL << CAN_F12R1_FB9_Pos)                   
#define CAN_F12R1_FB9          CAN_F12R1_FB9_Msk                              
#define CAN_F12R1_FB10_Pos     (10U)                                          
#define CAN_F12R1_FB10_Msk     (0x1UL << CAN_F12R1_FB10_Pos)                  
#define CAN_F12R1_FB10         CAN_F12R1_FB10_Msk                             
#define CAN_F12R1_FB11_Pos     (11U)                                          
#define CAN_F12R1_FB11_Msk     (0x1UL << CAN_F12R1_FB11_Pos)                  
#define CAN_F12R1_FB11         CAN_F12R1_FB11_Msk                             
#define CAN_F12R1_FB12_Pos     (12U)                                          
#define CAN_F12R1_FB12_Msk     (0x1UL << CAN_F12R1_FB12_Pos)                  
#define CAN_F12R1_FB12         CAN_F12R1_FB12_Msk                             
#define CAN_F12R1_FB13_Pos     (13U)                                          
#define CAN_F12R1_FB13_Msk     (0x1UL << CAN_F12R1_FB13_Pos)                  
#define CAN_F12R1_FB13         CAN_F12R1_FB13_Msk                             
#define CAN_F12R1_FB14_Pos     (14U)                                          
#define CAN_F12R1_FB14_Msk     (0x1UL << CAN_F12R1_FB14_Pos)                  
#define CAN_F12R1_FB14         CAN_F12R1_FB14_Msk                             
#define CAN_F12R1_FB15_Pos     (15U)                                          
#define CAN_F12R1_FB15_Msk     (0x1UL << CAN_F12R1_FB15_Pos)                  
#define CAN_F12R1_FB15         CAN_F12R1_FB15_Msk                             
#define CAN_F12R1_FB16_Pos     (16U)                                          
#define CAN_F12R1_FB16_Msk     (0x1UL << CAN_F12R1_FB16_Pos)                  
#define CAN_F12R1_FB16         CAN_F12R1_FB16_Msk                             
#define CAN_F12R1_FB17_Pos     (17U)                                          
#define CAN_F12R1_FB17_Msk     (0x1UL << CAN_F12R1_FB17_Pos)                  
#define CAN_F12R1_FB17         CAN_F12R1_FB17_Msk                             
#define CAN_F12R1_FB18_Pos     (18U)                                          
#define CAN_F12R1_FB18_Msk     (0x1UL << CAN_F12R1_FB18_Pos)                  
#define CAN_F12R1_FB18         CAN_F12R1_FB18_Msk                             
#define CAN_F12R1_FB19_Pos     (19U)                                          
#define CAN_F12R1_FB19_Msk     (0x1UL << CAN_F12R1_FB19_Pos)                  
#define CAN_F12R1_FB19         CAN_F12R1_FB19_Msk                             
#define CAN_F12R1_FB20_Pos     (20U)                                          
#define CAN_F12R1_FB20_Msk     (0x1UL << CAN_F12R1_FB20_Pos)                  
#define CAN_F12R1_FB20         CAN_F12R1_FB20_Msk                             
#define CAN_F12R1_FB21_Pos     (21U)                                          
#define CAN_F12R1_FB21_Msk     (0x1UL << CAN_F12R1_FB21_Pos)                  
#define CAN_F12R1_FB21         CAN_F12R1_FB21_Msk                             
#define CAN_F12R1_FB22_Pos     (22U)                                          
#define CAN_F12R1_FB22_Msk     (0x1UL << CAN_F12R1_FB22_Pos)                  
#define CAN_F12R1_FB22         CAN_F12R1_FB22_Msk                             
#define CAN_F12R1_FB23_Pos     (23U)                                          
#define CAN_F12R1_FB23_Msk     (0x1UL << CAN_F12R1_FB23_Pos)                  
#define CAN_F12R1_FB23         CAN_F12R1_FB23_Msk                             
#define CAN_F12R1_FB24_Pos     (24U)                                          
#define CAN_F12R1_FB24_Msk     (0x1UL << CAN_F12R1_FB24_Pos)                  
#define CAN_F12R1_FB24         CAN_F12R1_FB24_Msk                             
#define CAN_F12R1_FB25_Pos     (25U)                                          
#define CAN_F12R1_FB25_Msk     (0x1UL << CAN_F12R1_FB25_Pos)                  
#define CAN_F12R1_FB25         CAN_F12R1_FB25_Msk                             
#define CAN_F12R1_FB26_Pos     (26U)                                          
#define CAN_F12R1_FB26_Msk     (0x1UL << CAN_F12R1_FB26_Pos)                  
#define CAN_F12R1_FB26         CAN_F12R1_FB26_Msk                             
#define CAN_F12R1_FB27_Pos     (27U)                                          
#define CAN_F12R1_FB27_Msk     (0x1UL << CAN_F12R1_FB27_Pos)                  
#define CAN_F12R1_FB27         CAN_F12R1_FB27_Msk                             
#define CAN_F12R1_FB28_Pos     (28U)                                          
#define CAN_F12R1_FB28_Msk     (0x1UL << CAN_F12R1_FB28_Pos)                  
#define CAN_F12R1_FB28         CAN_F12R1_FB28_Msk                             
#define CAN_F12R1_FB29_Pos     (29U)                                          
#define CAN_F12R1_FB29_Msk     (0x1UL << CAN_F12R1_FB29_Pos)                  
#define CAN_F12R1_FB29         CAN_F12R1_FB29_Msk                             
#define CAN_F12R1_FB30_Pos     (30U)                                          
#define CAN_F12R1_FB30_Msk     (0x1UL << CAN_F12R1_FB30_Pos)                  
#define CAN_F12R1_FB30         CAN_F12R1_FB30_Msk                             
#define CAN_F12R1_FB31_Pos     (31U)                                          
#define CAN_F12R1_FB31_Msk     (0x1UL << CAN_F12R1_FB31_Pos)                  
#define CAN_F12R1_FB31         CAN_F12R1_FB31_Msk                             

/*******************  Bit definition for CAN_F13R1 register  ******************/
#define CAN_F13R1_FB0_Pos      (0U)                                            
#define CAN_F13R1_FB0_Msk      (0x1UL << CAN_F13R1_FB0_Pos)                     
#define CAN_F13R1_FB0          CAN_F13R1_FB0_Msk                              
#define CAN_F13R1_FB1_Pos      (1U)                                           
#define CAN_F13R1_FB1_Msk      (0x1UL << CAN_F13R1_FB1_Pos)                   
#define CAN_F13R1_FB1          CAN_F13R1_FB1_Msk                              
#define CAN_F13R1_FB2_Pos      (2U)                                           
#define CAN_F13R1_FB2_Msk      (0x1UL << CAN_F13R1_FB2_Pos)                   
#define CAN_F13R1_FB2          CAN_F13R1_FB2_Msk                              
#define CAN_F13R1_FB3_Pos      (3U)                                           
#define CAN_F13R1_FB3_Msk      (0x1UL << CAN_F13R1_FB3_Pos)                   
#define CAN_F13R1_FB3          CAN_F13R1_FB3_Msk                              
#define CAN_F13R1_FB4_Pos      (4U)                                           
#define CAN_F13R1_FB4_Msk      (0x1UL << CAN_F13R1_FB4_Pos)                   
#define CAN_F13R1_FB4          CAN_F13R1_FB4_Msk                              
#define CAN_F13R1_FB5_Pos      (5U)                                           
#define CAN_F13R1_FB5_Msk      (0x1UL << CAN_F13R1_FB5_Pos)                   
#define CAN_F13R1_FB5          CAN_F13R1_FB5_Msk                              
#define CAN_F13R1_FB6_Pos      (6U)                                           
#define CAN_F13R1_FB6_Msk      (0x1UL << CAN_F13R1_FB6_Pos)                   
#define CAN_F13R1_FB6          CAN_F13R1_FB6_Msk                              
#define CAN_F13R1_FB7_Pos      (7U)                                           
#define CAN_F13R1_FB7_Msk      (0x1UL << CAN_F13R1_FB7_Pos)                   
#define CAN_F13R1_FB7          CAN_F13R1_FB7_Msk                              
#define CAN_F13R1_FB8_Pos      (8U)                                           
#define CAN_F13R1_FB8_Msk      (0x1UL << CAN_F13R1_FB8_Pos)                   
#define CAN_F13R1_FB8          CAN_F13R1_FB8_Msk                              
#define CAN_F13R1_FB9_Pos      (9U)                                           
#define CAN_F13R1_FB9_Msk      (0x1UL << CAN_F13R1_FB9_Pos)                   
#define CAN_F13R1_FB9          CAN_F13R1_FB9_Msk                              
#define CAN_F13R1_FB10_Pos     (10U)                                          
#define CAN_F13R1_FB10_Msk     (0x1UL << CAN_F13R1_FB10_Pos)                  
#define CAN_F13R1_FB10         CAN_F13R1_FB10_Msk                             
#define CAN_F13R1_FB11_Pos     (11U)                                          
#define CAN_F13R1_FB11_Msk     (0x1UL << CAN_F13R1_FB11_Pos)                  
#define CAN_F13R1_FB11         CAN_F13R1_FB11_Msk                             
#define CAN_F13R1_FB12_Pos     (12U)                                          
#define CAN_F13R1_FB12_Msk     (0x1UL << CAN_F13R1_FB12_Pos)                  
#define CAN_F13R1_FB12         CAN_F13R1_FB12_Msk                             
#define CAN_F13R1_FB13_Pos     (13U)                                          
#define CAN_F13R1_FB13_Msk     (0x1UL << CAN_F13R1_FB13_Pos)                  
#define CAN_F13R1_FB13         CAN_F13R1_FB13_Msk                             
#define CAN_F13R1_FB14_Pos     (14U)                                          
#define CAN_F13R1_FB14_Msk     (0x1UL << CAN_F13R1_FB14_Pos)                  
#define CAN_F13R1_FB14         CAN_F13R1_FB14_Msk                             
#define CAN_F13R1_FB15_Pos     (15U)                                          
#define CAN_F13R1_FB15_Msk     (0x1UL << CAN_F13R1_FB15_Pos)                  
#define CAN_F13R1_FB15         CAN_F13R1_FB15_Msk                             
#define CAN_F13R1_FB16_Pos     (16U)                                          
#define CAN_F13R1_FB16_Msk     (0x1UL << CAN_F13R1_FB16_Pos)                  
#define CAN_F13R1_FB16         CAN_F13R1_FB16_Msk                             
#define CAN_F13R1_FB17_Pos     (17U)                                          
#define CAN_F13R1_FB17_Msk     (0x1UL << CAN_F13R1_FB17_Pos)                  
#define CAN_F13R1_FB17         CAN_F13R1_FB17_Msk                             
#define CAN_F13R1_FB18_Pos     (18U)                                          
#define CAN_F13R1_FB18_Msk     (0x1UL << CAN_F13R1_FB18_Pos)                  
#define CAN_F13R1_FB18         CAN_F13R1_FB18_Msk                             
#define CAN_F13R1_FB19_Pos     (19U)                                          
#define CAN_F13R1_FB19_Msk     (0x1UL << CAN_F13R1_FB19_Pos)                  
#define CAN_F13R1_FB19         CAN_F13R1_FB19_Msk                             
#define CAN_F13R1_FB20_Pos     (20U)                                          
#define CAN_F13R1_FB20_Msk     (0x1UL << CAN_F13R1_FB20_Pos)                  
#define CAN_F13R1_FB20         CAN_F13R1_FB20_Msk                             
#define CAN_F13R1_FB21_Pos     (21U)                                          
#define CAN_F13R1_FB21_Msk     (0x1UL << CAN_F13R1_FB21_Pos)                  
#define CAN_F13R1_FB21         CAN_F13R1_FB21_Msk                             
#define CAN_F13R1_FB22_Pos     (22U)                                          
#define CAN_F13R1_FB22_Msk     (0x1UL << CAN_F13R1_FB22_Pos)                  
#define CAN_F13R1_FB22         CAN_F13R1_FB22_Msk                             
#define CAN_F13R1_FB23_Pos     (23U)                                          
#define CAN_F13R1_FB23_Msk     (0x1UL << CAN_F13R1_FB23_Pos)                  
#define CAN_F13R1_FB23         CAN_F13R1_FB23_Msk                             
#define CAN_F13R1_FB24_Pos     (24U)                                          
#define CAN_F13R1_FB24_Msk     (0x1UL << CAN_F13R1_FB24_Pos)                  
#define CAN_F13R1_FB24         CAN_F13R1_FB24_Msk                             
#define CAN_F13R1_FB25_Pos     (25U)                                          
#define CAN_F13R1_FB25_Msk     (0x1UL << CAN_F13R1_FB25_Pos)                  
#define CAN_F13R1_FB25         CAN_F13R1_FB25_Msk                             
#define CAN_F13R1_FB26_Pos     (26U)                                          
#define CAN_F13R1_FB26_Msk     (0x1UL << CAN_F13R1_FB26_Pos)                  
#define CAN_F13R1_FB26         CAN_F13R1_FB26_Msk                             
#define CAN_F13R1_FB27_Pos     (27U)                                          
#define CAN_F13R1_FB27_Msk     (0x1UL << CAN_F13R1_FB27_Pos)                  
#define CAN_F13R1_FB27         CAN_F13R1_FB27_Msk                             
#define CAN_F13R1_FB28_Pos     (28U)                                          
#define CAN_F13R1_FB28_Msk     (0x1UL << CAN_F13R1_FB28_Pos)                  
#define CAN_F13R1_FB28         CAN_F13R1_FB28_Msk                             
#define CAN_F13R1_FB29_Pos     (29U)                                          
#define CAN_F13R1_FB29_Msk     (0x1UL << CAN_F13R1_FB29_Pos)                  
#define CAN_F13R1_FB29         CAN_F13R1_FB29_Msk                             
#define CAN_F13R1_FB30_Pos     (30U)                                          
#define CAN_F13R1_FB30_Msk     (0x1UL << CAN_F13R1_FB30_Pos)                  
#define CAN_F13R1_FB30         CAN_F13R1_FB30_Msk                             
#define CAN_F13R1_FB31_Pos     (31U)                                          
#define CAN_F13R1_FB31_Msk     (0x1UL << CAN_F13R1_FB31_Pos)                  
#define CAN_F13R1_FB31         CAN_F13R1_FB31_Msk                             

/*******************  Bit definition for CAN_F0R2 register  *******************/
#define CAN_F0R2_FB0_Pos       (0U)                                            
#define CAN_F0R2_FB0_Msk       (0x1UL << CAN_F0R2_FB0_Pos)                      
#define CAN_F0R2_FB0           CAN_F0R2_FB0_Msk                               
#define CAN_F0R2_FB1_Pos       (1U)                                           
#define CAN_F0R2_FB1_Msk       (0x1UL << CAN_F0R2_FB1_Pos)                    
#define CAN_F0R2_FB1           CAN_F0R2_FB1_Msk                               
#define CAN_F0R2_FB2_Pos       (2U)                                           
#define CAN_F0R2_FB2_Msk       (0x1UL << CAN_F0R2_FB2_Pos)                    
#define CAN_F0R2_FB2           CAN_F0R2_FB2_Msk                               
#define CAN_F0R2_FB3_Pos       (3U)                                           
#define CAN_F0R2_FB3_Msk       (0x1UL << CAN_F0R2_FB3_Pos)                    
#define CAN_F0R2_FB3           CAN_F0R2_FB3_Msk                               
#define CAN_F0R2_FB4_Pos       (4U)                                           
#define CAN_F0R2_FB4_Msk       (0x1UL << CAN_F0R2_FB4_Pos)                    
#define CAN_F0R2_FB4           CAN_F0R2_FB4_Msk                               
#define CAN_F0R2_FB5_Pos       (5U)                                           
#define CAN_F0R2_FB5_Msk       (0x1UL << CAN_F0R2_FB5_Pos)                    
#define CAN_F0R2_FB5           CAN_F0R2_FB5_Msk                               
#define CAN_F0R2_FB6_Pos       (6U)                                           
#define CAN_F0R2_FB6_Msk       (0x1UL << CAN_F0R2_FB6_Pos)                    
#define CAN_F0R2_FB6           CAN_F0R2_FB6_Msk                               
#define CAN_F0R2_FB7_Pos       (7U)                                           
#define CAN_F0R2_FB7_Msk       (0x1UL << CAN_F0R2_FB7_Pos)                    
#define CAN_F0R2_FB7           CAN_F0R2_FB7_Msk                               
#define CAN_F0R2_FB8_Pos       (8U)                                           
#define CAN_F0R2_FB8_Msk       (0x1UL << CAN_F0R2_FB8_Pos)                    
#define CAN_F0R2_FB8           CAN_F0R2_FB8_Msk                               
#define CAN_F0R2_FB9_Pos       (9U)                                           
#define CAN_F0R2_FB9_Msk       (0x1UL << CAN_F0R2_FB9_Pos)                    
#define CAN_F0R2_FB9           CAN_F0R2_FB9_Msk                               
#define CAN_F0R2_FB10_Pos      (10U)                                          
#define CAN_F0R2_FB10_Msk      (0x1UL << CAN_F0R2_FB10_Pos)                   
#define CAN_F0R2_FB10          CAN_F0R2_FB10_Msk                              
#define CAN_F0R2_FB11_Pos      (11U)                                          
#define CAN_F0R2_FB11_Msk      (0x1UL << CAN_F0R2_FB11_Pos)                   
#define CAN_F0R2_FB11          CAN_F0R2_FB11_Msk                              
#define CAN_F0R2_FB12_Pos      (12U)                                          
#define CAN_F0R2_FB12_Msk      (0x1UL << CAN_F0R2_FB12_Pos)                   
#define CAN_F0R2_FB12          CAN_F0R2_FB12_Msk                              
#define CAN_F0R2_FB13_Pos      (13U)                                          
#define CAN_F0R2_FB13_Msk      (0x1UL << CAN_F0R2_FB13_Pos)                   
#define CAN_F0R2_FB13          CAN_F0R2_FB13_Msk                              
#define CAN_F0R2_FB14_Pos      (14U)                                          
#define CAN_F0R2_FB14_Msk      (0x1UL << CAN_F0R2_FB14_Pos)                   
#define CAN_F0R2_FB14          CAN_F0R2_FB14_Msk                              
#define CAN_F0R2_FB15_Pos      (15U)                                          
#define CAN_F0R2_FB15_Msk      (0x1UL << CAN_F0R2_FB15_Pos)                   
#define CAN_F0R2_FB15          CAN_F0R2_FB15_Msk                              
#define CAN_F0R2_FB16_Pos      (16U)                                          
#define CAN_F0R2_FB16_Msk      (0x1UL << CAN_F0R2_FB16_Pos)                   
#define CAN_F0R2_FB16          CAN_F0R2_FB16_Msk                              
#define CAN_F0R2_FB17_Pos      (17U)                                          
#define CAN_F0R2_FB17_Msk      (0x1UL << CAN_F0R2_FB17_Pos)                   
#define CAN_F0R2_FB17          CAN_F0R2_FB17_Msk                              
#define CAN_F0R2_FB18_Pos      (18U)                                          
#define CAN_F0R2_FB18_Msk      (0x1UL << CAN_F0R2_FB18_Pos)                   
#define CAN_F0R2_FB18          CAN_F0R2_FB18_Msk                              
#define CAN_F0R2_FB19_Pos      (19U)                                          
#define CAN_F0R2_FB19_Msk      (0x1UL << CAN_F0R2_FB19_Pos)                   
#define CAN_F0R2_FB19          CAN_F0R2_FB19_Msk                              
#define CAN_F0R2_FB20_Pos      (20U)                                          
#define CAN_F0R2_FB20_Msk      (0x1UL << CAN_F0R2_FB20_Pos)                   
#define CAN_F0R2_FB20          CAN_F0R2_FB20_Msk                              
#define CAN_F0R2_FB21_Pos      (21U)                                          
#define CAN_F0R2_FB21_Msk      (0x1UL << CAN_F0R2_FB21_Pos)                   
#define CAN_F0R2_FB21          CAN_F0R2_FB21_Msk                              
#define CAN_F0R2_FB22_Pos      (22U)                                          
#define CAN_F0R2_FB22_Msk      (0x1UL << CAN_F0R2_FB22_Pos)                   
#define CAN_F0R2_FB22          CAN_F0R2_FB22_Msk                              
#define CAN_F0R2_FB23_Pos      (23U)                                          
#define CAN_F0R2_FB23_Msk      (0x1UL << CAN_F0R2_FB23_Pos)                   
#define CAN_F0R2_FB23          CAN_F0R2_FB23_Msk                              
#define CAN_F0R2_FB24_Pos      (24U)                                          
#define CAN_F0R2_FB24_Msk      (0x1UL << CAN_F0R2_FB24_Pos)                   
#define CAN_F0R2_FB24          CAN_F0R2_FB24_Msk                              
#define CAN_F0R2_FB25_Pos      (25U)                                          
#define CAN_F0R2_FB25_Msk      (0x1UL << CAN_F0R2_FB25_Pos)                   
#define CAN_F0R2_FB25          CAN_F0R2_FB25_Msk                              
#define CAN_F0R2_FB26_Pos      (26U)                                          
#define CAN_F0R2_FB26_Msk      (0x1UL << CAN_F0R2_FB26_Pos)                   
#define CAN_F0R2_FB26          CAN_F0R2_FB26_Msk                              
#define CAN_F0R2_FB27_Pos      (27U)                                          
#define CAN_F0R2_FB27_Msk      (0x1UL << CAN_F0R2_FB27_Pos)                   
#define CAN_F0R2_FB27          CAN_F0R2_FB27_Msk                              
#define CAN_F0R2_FB28_Pos      (28U)                                          
#define CAN_F0R2_FB28_Msk      (0x1UL << CAN_F0R2_FB28_Pos)                   
#define CAN_F0R2_FB28          CAN_F0R2_FB28_Msk                              
#define CAN_F0R2_FB29_Pos      (29U)                                          
#define CAN_F0R2_FB29_Msk      (0x1UL << CAN_F0R2_FB29_Pos)                   
#define CAN_F0R2_FB29          CAN_F0R2_FB29_Msk                              
#define CAN_F0R2_FB30_Pos      (30U)                                          
#define CAN_F0R2_FB30_Msk      (0x1UL << CAN_F0R2_FB30_Pos)                   
#define CAN_F0R2_FB30          CAN_F0R2_FB30_Msk                              
#define CAN_F0R2_FB31_Pos      (31U)                                          
#define CAN_F0R2_FB31_Msk      (0x1UL << CAN_F0R2_FB31_Pos)                   
#define CAN_F0R2_FB31          CAN_F0R2_FB31_Msk                              

/*******************  Bit definition for CAN_F1R2 register  *******************/
#define CAN_F1R2_FB0_Pos       (0U)                                            
#define CAN_F1R2_FB0_Msk       (0x1UL << CAN_F1R2_FB0_Pos)                      
#define CAN_F1R2_FB0           CAN_F1R2_FB0_Msk                               
#define CAN_F1R2_FB1_Pos       (1U)                                           
#define CAN_F1R2_FB1_Msk       (0x1UL << CAN_F1R2_FB1_Pos)                    
#define CAN_F1R2_FB1           CAN_F1R2_FB1_Msk                               
#define CAN_F1R2_FB2_Pos       (2U)                                           
#define CAN_F1R2_FB2_Msk       (0x1UL << CAN_F1R2_FB2_Pos)                    
#define CAN_F1R2_FB2           CAN_F1R2_FB2_Msk                               
#define CAN_F1R2_FB3_Pos       (3U)                                           
#define CAN_F1R2_FB3_Msk       (0x1UL << CAN_F1R2_FB3_Pos)                    
#define CAN_F1R2_FB3           CAN_F1R2_FB3_Msk                               
#define CAN_F1R2_FB4_Pos       (4U)                                           
#define CAN_F1R2_FB4_Msk       (0x1UL << CAN_F1R2_FB4_Pos)                    
#define CAN_F1R2_FB4           CAN_F1R2_FB4_Msk                               
#define CAN_F1R2_FB5_Pos       (5U)                                           
#define CAN_F1R2_FB5_Msk       (0x1UL << CAN_F1R2_FB5_Pos)                    
#define CAN_F1R2_FB5           CAN_F1R2_FB5_Msk                               
#define CAN_F1R2_FB6_Pos       (6U)                                           
#define CAN_F1R2_FB6_Msk       (0x1UL << CAN_F1R2_FB6_Pos)                    
#define CAN_F1R2_FB6           CAN_F1R2_FB6_Msk                               
#define CAN_F1R2_FB7_Pos       (7U)                                           
#define CAN_F1R2_FB7_Msk       (0x1UL << CAN_F1R2_FB7_Pos)                    
#define CAN_F1R2_FB7           CAN_F1R2_FB7_Msk                               
#define CAN_F1R2_FB8_Pos       (8U)                                           
#define CAN_F1R2_FB8_Msk       (0x1UL << CAN_F1R2_FB8_Pos)                    
#define CAN_F1R2_FB8           CAN_F1R2_FB8_Msk                               
#define CAN_F1R2_FB9_Pos       (9U)                                           
#define CAN_F1R2_FB9_Msk       (0x1UL << CAN_F1R2_FB9_Pos)                    
#define CAN_F1R2_FB9           CAN_F1R2_FB9_Msk                               
#define CAN_F1R2_FB10_Pos      (10U)                                          
#define CAN_F1R2_FB10_Msk      (0x1UL << CAN_F1R2_FB10_Pos)                   
#define CAN_F1R2_FB10          CAN_F1R2_FB10_Msk                              
#define CAN_F1R2_FB11_Pos      (11U)                                          
#define CAN_F1R2_FB11_Msk      (0x1UL << CAN_F1R2_FB11_Pos)                   
#define CAN_F1R2_FB11          CAN_F1R2_FB11_Msk                              
#define CAN_F1R2_FB12_Pos      (12U)                                          
#define CAN_F1R2_FB12_Msk      (0x1UL << CAN_F1R2_FB12_Pos)                   
#define CAN_F1R2_FB12          CAN_F1R2_FB12_Msk                              
#define CAN_F1R2_FB13_Pos      (13U)                                          
#define CAN_F1R2_FB13_Msk      (0x1UL << CAN_F1R2_FB13_Pos)                   
#define CAN_F1R2_FB13          CAN_F1R2_FB13_Msk                              
#define CAN_F1R2_FB14_Pos      (14U)                                          
#define CAN_F1R2_FB14_Msk      (0x1UL << CAN_F1R2_FB14_Pos)                   
#define CAN_F1R2_FB14          CAN_F1R2_FB14_Msk                              
#define CAN_F1R2_FB15_Pos      (15U)                                          
#define CAN_F1R2_FB15_Msk      (0x1UL << CAN_F1R2_FB15_Pos)                   
#define CAN_F1R2_FB15          CAN_F1R2_FB15_Msk                              
#define CAN_F1R2_FB16_Pos      (16U)                                          
#define CAN_F1R2_FB16_Msk      (0x1UL << CAN_F1R2_FB16_Pos)                   
#define CAN_F1R2_FB16          CAN_F1R2_FB16_Msk                              
#define CAN_F1R2_FB17_Pos      (17U)                                          
#define CAN_F1R2_FB17_Msk      (0x1UL << CAN_F1R2_FB17_Pos)                   
#define CAN_F1R2_FB17          CAN_F1R2_FB17_Msk                              
#define CAN_F1R2_FB18_Pos      (18U)                                          
#define CAN_F1R2_FB18_Msk      (0x1UL << CAN_F1R2_FB18_Pos)                   
#define CAN_F1R2_FB18          CAN_F1R2_FB18_Msk                              
#define CAN_F1R2_FB19_Pos      (19U)                                          
#define CAN_F1R2_FB19_Msk      (0x1UL << CAN_F1R2_FB19_Pos)                   
#define CAN_F1R2_FB19          CAN_F1R2_FB19_Msk                              
#define CAN_F1R2_FB20_Pos      (20U)                                          
#define CAN_F1R2_FB20_Msk      (0x1UL << CAN_F1R2_FB20_Pos)                   
#define CAN_F1R2_FB20          CAN_F1R2_FB20_Msk                              
#define CAN_F1R2_FB21_Pos      (21U)                                          
#define CAN_F1R2_FB21_Msk      (0x1UL << CAN_F1R2_FB21_Pos)                   
#define CAN_F1R2_FB21          CAN_F1R2_FB21_Msk                              
#define CAN_F1R2_FB22_Pos      (22U)                                          
#define CAN_F1R2_FB22_Msk      (0x1UL << CAN_F1R2_FB22_Pos)                   
#define CAN_F1R2_FB22          CAN_F1R2_FB22_Msk                              
#define CAN_F1R2_FB23_Pos      (23U)                                          
#define CAN_F1R2_FB23_Msk      (0x1UL << CAN_F1R2_FB23_Pos)                   
#define CAN_F1R2_FB23          CAN_F1R2_FB23_Msk                              
#define CAN_F1R2_FB24_Pos      (24U)                                          
#define CAN_F1R2_FB24_Msk      (0x1UL << CAN_F1R2_FB24_Pos)                   
#define CAN_F1R2_FB24          CAN_F1R2_FB24_Msk                              
#define CAN_F1R2_FB25_Pos      (25U)                                          
#define CAN_F1R2_FB25_Msk      (0x1UL << CAN_F1R2_FB25_Pos)                   
#define CAN_F1R2_FB25          CAN_F1R2_FB25_Msk                              
#define CAN_F1R2_FB26_Pos      (26U)                                          
#define CAN_F1R2_FB26_Msk      (0x1UL << CAN_F1R2_FB26_Pos)                   
#define CAN_F1R2_FB26          CAN_F1R2_FB26_Msk                              
#define CAN_F1R2_FB27_Pos      (27U)                                          
#define CAN_F1R2_FB27_Msk      (0x1UL << CAN_F1R2_FB27_Pos)                   
#define CAN_F1R2_FB27          CAN_F1R2_FB27_Msk                              
#define CAN_F1R2_FB28_Pos      (28U)                                          
#define CAN_F1R2_FB28_Msk      (0x1UL << CAN_F1R2_FB28_Pos)                   
#define CAN_F1R2_FB28          CAN_F1R2_FB28_Msk                              
#define CAN_F1R2_FB29_Pos      (29U)                                          
#define CAN_F1R2_FB29_Msk      (0x1UL << CAN_F1R2_FB29_Pos)                   
#define CAN_F1R2_FB29          CAN_F1R2_FB29_Msk                              
#define CAN_F1R2_FB30_Pos      (30U)                                          
#define CAN_F1R2_FB30_Msk      (0x1UL << CAN_F1R2_FB30_Pos)                   
#define CAN_F1R2_FB30          CAN_F1R2_FB30_Msk                              
#define CAN_F1R2_FB31_Pos      (31U)                                          
#define CAN_F1R2_FB31_Msk      (0x1UL << CAN_F1R2_FB31_Pos)                   
#define CAN_F1R2_FB31          CAN_F1R2_FB31_Msk                              

/*******************  Bit definition for CAN_F2R2 register  *******************/
#define CAN_F2R2_FB0_Pos       (0U)                                            
#define CAN_F2R2_FB0_Msk       (0x1UL << CAN_F2R2_FB0_Pos)                      
#define CAN_F2R2_FB0           CAN_F2R2_FB0_Msk                               
#define CAN_F2R2_FB1_Pos       (1U)                                           
#define CAN_F2R2_FB1_Msk       (0x1UL << CAN_F2R2_FB1_Pos)                    
#define CAN_F2R2_FB1           CAN_F2R2_FB1_Msk                               
#define CAN_F2R2_FB2_Pos       (2U)                                           
#define CAN_F2R2_FB2_Msk       (0x1UL << CAN_F2R2_FB2_Pos)                    
#define CAN_F2R2_FB2           CAN_F2R2_FB2_Msk                               
#define CAN_F2R2_FB3_Pos       (3U)                                           
#define CAN_F2R2_FB3_Msk       (0x1UL << CAN_F2R2_FB3_Pos)                    
#define CAN_F2R2_FB3           CAN_F2R2_FB3_Msk                               
#define CAN_F2R2_FB4_Pos       (4U)                                           
#define CAN_F2R2_FB4_Msk       (0x1UL << CAN_F2R2_FB4_Pos)                    
#define CAN_F2R2_FB4           CAN_F2R2_FB4_Msk                               
#define CAN_F2R2_FB5_Pos       (5U)                                           
#define CAN_F2R2_FB5_Msk       (0x1UL << CAN_F2R2_FB5_Pos)                    
#define CAN_F2R2_FB5           CAN_F2R2_FB5_Msk                               
#define CAN_F2R2_FB6_Pos       (6U)                                           
#define CAN_F2R2_FB6_Msk       (0x1UL << CAN_F2R2_FB6_Pos)                    
#define CAN_F2R2_FB6           CAN_F2R2_FB6_Msk                               
#define CAN_F2R2_FB7_Pos       (7U)                                           
#define CAN_F2R2_FB7_Msk       (0x1UL << CAN_F2R2_FB7_Pos)                    
#define CAN_F2R2_FB7           CAN_F2R2_FB7_Msk                               
#define CAN_F2R2_FB8_Pos       (8U)                                           
#define CAN_F2R2_FB8_Msk       (0x1UL << CAN_F2R2_FB8_Pos)                    
#define CAN_F2R2_FB8           CAN_F2R2_FB8_Msk                               
#define CAN_F2R2_FB9_Pos       (9U)                                           
#define CAN_F2R2_FB9_Msk       (0x1UL << CAN_F2R2_FB9_Pos)                    
#define CAN_F2R2_FB9           CAN_F2R2_FB9_Msk                               
#define CAN_F2R2_FB10_Pos      (10U)                                          
#define CAN_F2R2_FB10_Msk      (0x1UL << CAN_F2R2_FB10_Pos)                   
#define CAN_F2R2_FB10          CAN_F2R2_FB10_Msk                              
#define CAN_F2R2_FB11_Pos      (11U)                                          
#define CAN_F2R2_FB11_Msk      (0x1UL << CAN_F2R2_FB11_Pos)                   
#define CAN_F2R2_FB11          CAN_F2R2_FB11_Msk                              
#define CAN_F2R2_FB12_Pos      (12U)                                          
#define CAN_F2R2_FB12_Msk      (0x1UL << CAN_F2R2_FB12_Pos)                   
#define CAN_F2R2_FB12          CAN_F2R2_FB12_Msk                              
#define CAN_F2R2_FB13_Pos      (13U)                                          
#define CAN_F2R2_FB13_Msk      (0x1UL << CAN_F2R2_FB13_Pos)                   
#define CAN_F2R2_FB13          CAN_F2R2_FB13_Msk                              
#define CAN_F2R2_FB14_Pos      (14U)                                          
#define CAN_F2R2_FB14_Msk      (0x1UL << CAN_F2R2_FB14_Pos)                   
#define CAN_F2R2_FB14          CAN_F2R2_FB14_Msk                              
#define CAN_F2R2_FB15_Pos      (15U)                                          
#define CAN_F2R2_FB15_Msk      (0x1UL << CAN_F2R2_FB15_Pos)                   
#define CAN_F2R2_FB15          CAN_F2R2_FB15_Msk                              
#define CAN_F2R2_FB16_Pos      (16U)                                          
#define CAN_F2R2_FB16_Msk      (0x1UL << CAN_F2R2_FB16_Pos)                   
#define CAN_F2R2_FB16          CAN_F2R2_FB16_Msk                              
#define CAN_F2R2_FB17_Pos      (17U)                                          
#define CAN_F2R2_FB17_Msk      (0x1UL << CAN_F2R2_FB17_Pos)                   
#define CAN_F2R2_FB17          CAN_F2R2_FB17_Msk                              
#define CAN_F2R2_FB18_Pos      (18U)                                          
#define CAN_F2R2_FB18_Msk      (0x1UL << CAN_F2R2_FB18_Pos)                   
#define CAN_F2R2_FB18          CAN_F2R2_FB18_Msk                              
#define CAN_F2R2_FB19_Pos      (19U)                                          
#define CAN_F2R2_FB19_Msk      (0x1UL << CAN_F2R2_FB19_Pos)                   
#define CAN_F2R2_FB19          CAN_F2R2_FB19_Msk                              
#define CAN_F2R2_FB20_Pos      (20U)                                          
#define CAN_F2R2_FB20_Msk      (0x1UL << CAN_F2R2_FB20_Pos)                   
#define CAN_F2R2_FB20          CAN_F2R2_FB20_Msk                              
#define CAN_F2R2_FB21_Pos      (21U)                                          
#define CAN_F2R2_FB21_Msk      (0x1UL << CAN_F2R2_FB21_Pos)                   
#define CAN_F2R2_FB21          CAN_F2R2_FB21_Msk                              
#define CAN_F2R2_FB22_Pos      (22U)                                          
#define CAN_F2R2_FB22_Msk      (0x1UL << CAN_F2R2_FB22_Pos)                   
#define CAN_F2R2_FB22          CAN_F2R2_FB22_Msk                              
#define CAN_F2R2_FB23_Pos      (23U)                                          
#define CAN_F2R2_FB23_Msk      (0x1UL << CAN_F2R2_FB23_Pos)                   
#define CAN_F2R2_FB23          CAN_F2R2_FB23_Msk                              
#define CAN_F2R2_FB24_Pos      (24U)                                          
#define CAN_F2R2_FB24_Msk      (0x1UL << CAN_F2R2_FB24_Pos)                   
#define CAN_F2R2_FB24          CAN_F2R2_FB24_Msk                              
#define CAN_F2R2_FB25_Pos      (25U)                                          
#define CAN_F2R2_FB25_Msk      (0x1UL << CAN_F2R2_FB25_Pos)                   
#define CAN_F2R2_FB25          CAN_F2R2_FB25_Msk                              
#define CAN_F2R2_FB26_Pos      (26U)                                          
#define CAN_F2R2_FB26_Msk      (0x1UL << CAN_F2R2_FB26_Pos)                   
#define CAN_F2R2_FB26          CAN_F2R2_FB26_Msk                              
#define CAN_F2R2_FB27_Pos      (27U)                                          
#define CAN_F2R2_FB27_Msk      (0x1UL << CAN_F2R2_FB27_Pos)                   
#define CAN_F2R2_FB27          CAN_F2R2_FB27_Msk                              
#define CAN_F2R2_FB28_Pos      (28U)                                          
#define CAN_F2R2_FB28_Msk      (0x1UL << CAN_F2R2_FB28_Pos)                   
#define CAN_F2R2_FB28          CAN_F2R2_FB28_Msk                              
#define CAN_F2R2_FB29_Pos      (29U)                                          
#define CAN_F2R2_FB29_Msk      (0x1UL << CAN_F2R2_FB29_Pos)                   
#define CAN_F2R2_FB29          CAN_F2R2_FB29_Msk                              
#define CAN_F2R2_FB30_Pos      (30U)                                          
#define CAN_F2R2_FB30_Msk      (0x1UL << CAN_F2R2_FB30_Pos)                   
#define CAN_F2R2_FB30          CAN_F2R2_FB30_Msk                              
#define CAN_F2R2_FB31_Pos      (31U)                                          
#define CAN_F2R2_FB31_Msk      (0x1UL << CAN_F2R2_FB31_Pos)                   
#define CAN_F2R2_FB31          CAN_F2R2_FB31_Msk                              

/*******************  Bit definition for CAN_F3R2 register  *******************/
#define CAN_F3R2_FB0_Pos       (0U)                                            
#define CAN_F3R2_FB0_Msk       (0x1UL << CAN_F3R2_FB0_Pos)                      
#define CAN_F3R2_FB0           CAN_F3R2_FB0_Msk                               
#define CAN_F3R2_FB1_Pos       (1U)                                           
#define CAN_F3R2_FB1_Msk       (0x1UL << CAN_F3R2_FB1_Pos)                    
#define CAN_F3R2_FB1           CAN_F3R2_FB1_Msk                               
#define CAN_F3R2_FB2_Pos       (2U)                                           
#define CAN_F3R2_FB2_Msk       (0x1UL << CAN_F3R2_FB2_Pos)                    
#define CAN_F3R2_FB2           CAN_F3R2_FB2_Msk                               
#define CAN_F3R2_FB3_Pos       (3U)                                           
#define CAN_F3R2_FB3_Msk       (0x1UL << CAN_F3R2_FB3_Pos)                    
#define CAN_F3R2_FB3           CAN_F3R2_FB3_Msk                               
#define CAN_F3R2_FB4_Pos       (4U)                                           
#define CAN_F3R2_FB4_Msk       (0x1UL << CAN_F3R2_FB4_Pos)                    
#define CAN_F3R2_FB4           CAN_F3R2_FB4_Msk                               
#define CAN_F3R2_FB5_Pos       (5U)                                           
#define CAN_F3R2_FB5_Msk       (0x1UL << CAN_F3R2_FB5_Pos)                    
#define CAN_F3R2_FB5           CAN_F3R2_FB5_Msk                               
#define CAN_F3R2_FB6_Pos       (6U)                                           
#define CAN_F3R2_FB6_Msk       (0x1UL << CAN_F3R2_FB6_Pos)                    
#define CAN_F3R2_FB6           CAN_F3R2_FB6_Msk                               
#define CAN_F3R2_FB7_Pos       (7U)                                           
#define CAN_F3R2_FB7_Msk       (0x1UL << CAN_F3R2_FB7_Pos)                    
#define CAN_F3R2_FB7           CAN_F3R2_FB7_Msk                               
#define CAN_F3R2_FB8_Pos       (8U)                                           
#define CAN_F3R2_FB8_Msk       (0x1UL << CAN_F3R2_FB8_Pos)                    
#define CAN_F3R2_FB8           CAN_F3R2_FB8_Msk                               
#define CAN_F3R2_FB9_Pos       (9U)                                           
#define CAN_F3R2_FB9_Msk       (0x1UL << CAN_F3R2_FB9_Pos)                    
#define CAN_F3R2_FB9           CAN_F3R2_FB9_Msk                               
#define CAN_F3R2_FB10_Pos      (10U)                                          
#define CAN_F3R2_FB10_Msk      (0x1UL << CAN_F3R2_FB10_Pos)                   
#define CAN_F3R2_FB10          CAN_F3R2_FB10_Msk                              
#define CAN_F3R2_FB11_Pos      (11U)                                          
#define CAN_F3R2_FB11_Msk      (0x1UL << CAN_F3R2_FB11_Pos)                   
#define CAN_F3R2_FB11          CAN_F3R2_FB11_Msk                              
#define CAN_F3R2_FB12_Pos      (12U)                                          
#define CAN_F3R2_FB12_Msk      (0x1UL << CAN_F3R2_FB12_Pos)                   
#define CAN_F3R2_FB12          CAN_F3R2_FB12_Msk                              
#define CAN_F3R2_FB13_Pos      (13U)                                          
#define CAN_F3R2_FB13_Msk      (0x1UL << CAN_F3R2_FB13_Pos)                   
#define CAN_F3R2_FB13          CAN_F3R2_FB13_Msk                              
#define CAN_F3R2_FB14_Pos      (14U)                                          
#define CAN_F3R2_FB14_Msk      (0x1UL << CAN_F3R2_FB14_Pos)                   
#define CAN_F3R2_FB14          CAN_F3R2_FB14_Msk                              
#define CAN_F3R2_FB15_Pos      (15U)                                          
#define CAN_F3R2_FB15_Msk      (0x1UL << CAN_F3R2_FB15_Pos)                   
#define CAN_F3R2_FB15          CAN_F3R2_FB15_Msk                              
#define CAN_F3R2_FB16_Pos      (16U)                                          
#define CAN_F3R2_FB16_Msk      (0x1UL << CAN_F3R2_FB16_Pos)                   
#define CAN_F3R2_FB16          CAN_F3R2_FB16_Msk                              
#define CAN_F3R2_FB17_Pos      (17U)                                          
#define CAN_F3R2_FB17_Msk      (0x1UL << CAN_F3R2_FB17_Pos)                   
#define CAN_F3R2_FB17          CAN_F3R2_FB17_Msk                              
#define CAN_F3R2_FB18_Pos      (18U)                                          
#define CAN_F3R2_FB18_Msk      (0x1UL << CAN_F3R2_FB18_Pos)                   
#define CAN_F3R2_FB18          CAN_F3R2_FB18_Msk                              
#define CAN_F3R2_FB19_Pos      (19U)                                          
#define CAN_F3R2_FB19_Msk      (0x1UL << CAN_F3R2_FB19_Pos)                   
#define CAN_F3R2_FB19          CAN_F3R2_FB19_Msk                              
#define CAN_F3R2_FB20_Pos      (20U)                                          
#define CAN_F3R2_FB20_Msk      (0x1UL << CAN_F3R2_FB20_Pos)                   
#define CAN_F3R2_FB20          CAN_F3R2_FB20_Msk                              
#define CAN_F3R2_FB21_Pos      (21U)                                          
#define CAN_F3R2_FB21_Msk      (0x1UL << CAN_F3R2_FB21_Pos)                   
#define CAN_F3R2_FB21          CAN_F3R2_FB21_Msk                              
#define CAN_F3R2_FB22_Pos      (22U)                                          
#define CAN_F3R2_FB22_Msk      (0x1UL << CAN_F3R2_FB22_Pos)                   
#define CAN_F3R2_FB22          CAN_F3R2_FB22_Msk                              
#define CAN_F3R2_FB23_Pos      (23U)                                          
#define CAN_F3R2_FB23_Msk      (0x1UL << CAN_F3R2_FB23_Pos)                   
#define CAN_F3R2_FB23          CAN_F3R2_FB23_Msk                              
#define CAN_F3R2_FB24_Pos      (24U)                                          
#define CAN_F3R2_FB24_Msk      (0x1UL << CAN_F3R2_FB24_Pos)                   
#define CAN_F3R2_FB24          CAN_F3R2_FB24_Msk                              
#define CAN_F3R2_FB25_Pos      (25U)                                          
#define CAN_F3R2_FB25_Msk      (0x1UL << CAN_F3R2_FB25_Pos)                   
#define CAN_F3R2_FB25          CAN_F3R2_FB25_Msk                              
#define CAN_F3R2_FB26_Pos      (26U)                                          
#define CAN_F3R2_FB26_Msk      (0x1UL << CAN_F3R2_FB26_Pos)                   
#define CAN_F3R2_FB26          CAN_F3R2_FB26_Msk                              
#define CAN_F3R2_FB27_Pos      (27U)                                          
#define CAN_F3R2_FB27_Msk      (0x1UL << CAN_F3R2_FB27_Pos)                   
#define CAN_F3R2_FB27          CAN_F3R2_FB27_Msk                              
#define CAN_F3R2_FB28_Pos      (28U)                                          
#define CAN_F3R2_FB28_Msk      (0x1UL << CAN_F3R2_FB28_Pos)                   
#define CAN_F3R2_FB28          CAN_F3R2_FB28_Msk                              
#define CAN_F3R2_FB29_Pos      (29U)                                          
#define CAN_F3R2_FB29_Msk      (0x1UL << CAN_F3R2_FB29_Pos)                   
#define CAN_F3R2_FB29          CAN_F3R2_FB29_Msk                              
#define CAN_F3R2_FB30_Pos      (30U)                                          
#define CAN_F3R2_FB30_Msk      (0x1UL << CAN_F3R2_FB30_Pos)                   
#define CAN_F3R2_FB30          CAN_F3R2_FB30_Msk                              
#define CAN_F3R2_FB31_Pos      (31U)                                          
#define CAN_F3R2_FB31_Msk      (0x1UL << CAN_F3R2_FB31_Pos)                   
#define CAN_F3R2_FB31          CAN_F3R2_FB31_Msk                              

/*******************  Bit definition for CAN_F4R2 register  *******************/
#define CAN_F4R2_FB0_Pos       (0U)                                            
#define CAN_F4R2_FB0_Msk       (0x1UL << CAN_F4R2_FB0_Pos)                    
#define CAN_F4R2_FB0           CAN_F4R2_FB0_Msk                               
#define CAN_F4R2_FB1_Pos       (1U)                                           
#define CAN_F4R2_FB1_Msk       (0x1UL << CAN_F4R2_FB1_Pos)                    
#define CAN_F4R2_FB1           CAN_F4R2_FB1_Msk                               
#define CAN_F4R2_FB2_Pos       (2U)                                           
#define CAN_F4R2_FB2_Msk       (0x1UL << CAN_F4R2_FB2_Pos)                    
#define CAN_F4R2_FB2           CAN_F4R2_FB2_Msk                               
#define CAN_F4R2_FB3_Pos       (3U)                                           
#define CAN_F4R2_FB3_Msk       (0x1UL << CAN_F4R2_FB3_Pos)                    
#define CAN_F4R2_FB3           CAN_F4R2_FB3_Msk                               
#define CAN_F4R2_FB4_Pos       (4U)                                           
#define CAN_F4R2_FB4_Msk       (0x1UL << CAN_F4R2_FB4_Pos)                    
#define CAN_F4R2_FB4           CAN_F4R2_FB4_Msk                               
#define CAN_F4R2_FB5_Pos       (5U)                                           
#define CAN_F4R2_FB5_Msk       (0x1UL << CAN_F4R2_FB5_Pos)                    
#define CAN_F4R2_FB5           CAN_F4R2_FB5_Msk                               
#define CAN_F4R2_FB6_Pos       (6U)                                           
#define CAN_F4R2_FB6_Msk       (0x1UL << CAN_F4R2_FB6_Pos)                    
#define CAN_F4R2_FB6           CAN_F4R2_FB6_Msk                               
#define CAN_F4R2_FB7_Pos       (7U)                                           
#define CAN_F4R2_FB7_Msk       (0x1UL << CAN_F4R2_FB7_Pos)                    
#define CAN_F4R2_FB7           CAN_F4R2_FB7_Msk                               
#define CAN_F4R2_FB8_Pos       (8U)                                           
#define CAN_F4R2_FB8_Msk       (0x1UL << CAN_F4R2_FB8_Pos)                    
#define CAN_F4R2_FB8           CAN_F4R2_FB8_Msk                               
#define CAN_F4R2_FB9_Pos       (9U)                                           
#define CAN_F4R2_FB9_Msk       (0x1UL << CAN_F4R2_FB9_Pos)                    
#define CAN_F4R2_FB9           CAN_F4R2_FB9_Msk                               
#define CAN_F4R2_FB10_Pos      (10U)                                          
#define CAN_F4R2_FB10_Msk      (0x1UL << CAN_F4R2_FB10_Pos)                   
#define CAN_F4R2_FB10          CAN_F4R2_FB10_Msk                              
#define CAN_F4R2_FB11_Pos      (11U)                                          
#define CAN_F4R2_FB11_Msk      (0x1UL << CAN_F4R2_FB11_Pos)                   
#define CAN_F4R2_FB11          CAN_F4R2_FB11_Msk                              
#define CAN_F4R2_FB12_Pos      (12U)                                          
#define CAN_F4R2_FB12_Msk      (0x1UL << CAN_F4R2_FB12_Pos)                   
#define CAN_F4R2_FB12          CAN_F4R2_FB12_Msk                              
#define CAN_F4R2_FB13_Pos      (13U)                                          
#define CAN_F4R2_FB13_Msk      (0x1UL << CAN_F4R2_FB13_Pos)                   
#define CAN_F4R2_FB13          CAN_F4R2_FB13_Msk                              
#define CAN_F4R2_FB14_Pos      (14U)                                          
#define CAN_F4R2_FB14_Msk      (0x1UL << CAN_F4R2_FB14_Pos)                   
#define CAN_F4R2_FB14          CAN_F4R2_FB14_Msk                              
#define CAN_F4R2_FB15_Pos      (15U)                                          
#define CAN_F4R2_FB15_Msk      (0x1UL << CAN_F4R2_FB15_Pos)                   
#define CAN_F4R2_FB15          CAN_F4R2_FB15_Msk                              
#define CAN_F4R2_FB16_Pos      (16U)                                          
#define CAN_F4R2_FB16_Msk      (0x1UL << CAN_F4R2_FB16_Pos)                   
#define CAN_F4R2_FB16          CAN_F4R2_FB16_Msk                              
#define CAN_F4R2_FB17_Pos      (17U)                                          
#define CAN_F4R2_FB17_Msk      (0x1UL << CAN_F4R2_FB17_Pos)                   
#define CAN_F4R2_FB17          CAN_F4R2_FB17_Msk                              
#define CAN_F4R2_FB18_Pos      (18U)                                          
#define CAN_F4R2_FB18_Msk      (0x1UL << CAN_F4R2_FB18_Pos)                   
#define CAN_F4R2_FB18          CAN_F4R2_FB18_Msk                              
#define CAN_F4R2_FB19_Pos      (19U)                                          
#define CAN_F4R2_FB19_Msk      (0x1UL << CAN_F4R2_FB19_Pos)                   
#define CAN_F4R2_FB19          CAN_F4R2_FB19_Msk                              
#define CAN_F4R2_FB20_Pos      (20U)                                          
#define CAN_F4R2_FB20_Msk      (0x1UL << CAN_F4R2_FB20_Pos)                   
#define CAN_F4R2_FB20          CAN_F4R2_FB20_Msk                              
#define CAN_F4R2_FB21_Pos      (21U)                                          
#define CAN_F4R2_FB21_Msk      (0x1UL << CAN_F4R2_FB21_Pos)                   
#define CAN_F4R2_FB21          CAN_F4R2_FB21_Msk                              
#define CAN_F4R2_FB22_Pos      (22U)                                          
#define CAN_F4R2_FB22_Msk      (0x1UL << CAN_F4R2_FB22_Pos)                   
#define CAN_F4R2_FB22          CAN_F4R2_FB22_Msk                              
#define CAN_F4R2_FB23_Pos      (23U)                                          
#define CAN_F4R2_FB23_Msk      (0x1UL << CAN_F4R2_FB23_Pos)                   
#define CAN_F4R2_FB23          CAN_F4R2_FB23_Msk                              
#define CAN_F4R2_FB24_Pos      (24U)                                          
#define CAN_F4R2_FB24_Msk      (0x1UL << CAN_F4R2_FB24_Pos)                   
#define CAN_F4R2_FB24          CAN_F4R2_FB24_Msk                              
#define CAN_F4R2_FB25_Pos      (25U)                                          
#define CAN_F4R2_FB25_Msk      (0x1UL << CAN_F4R2_FB25_Pos)                   
#define CAN_F4R2_FB25          CAN_F4R2_FB25_Msk                              
#define CAN_F4R2_FB26_Pos      (26U)                                          
#define CAN_F4R2_FB26_Msk      (0x1UL << CAN_F4R2_FB26_Pos)                   
#define CAN_F4R2_FB26          CAN_F4R2_FB26_Msk                              
#define CAN_F4R2_FB27_Pos      (27U)                                          
#define CAN_F4R2_FB27_Msk      (0x1UL << CAN_F4R2_FB27_Pos)                   
#define CAN_F4R2_FB27          CAN_F4R2_FB27_Msk                              
#define CAN_F4R2_FB28_Pos      (28U)                                          
#define CAN_F4R2_FB28_Msk      (0x1UL << CAN_F4R2_FB28_Pos)                   
#define CAN_F4R2_FB28          CAN_F4R2_FB28_Msk                              
#define CAN_F4R2_FB29_Pos      (29U)                                          
#define CAN_F4R2_FB29_Msk      (0x1UL << CAN_F4R2_FB29_Pos)                   
#define CAN_F4R2_FB29          CAN_F4R2_FB29_Msk                              
#define CAN_F4R2_FB30_Pos      (30U)                                          
#define CAN_F4R2_FB30_Msk      (0x1UL << CAN_F4R2_FB30_Pos)                   
#define CAN_F4R2_FB30          CAN_F4R2_FB30_Msk                              
#define CAN_F4R2_FB31_Pos      (31U)                                          
#define CAN_F4R2_FB31_Msk      (0x1UL << CAN_F4R2_FB31_Pos)                   
#define CAN_F4R2_FB31          CAN_F4R2_FB31_Msk                              

/*******************  Bit definition for CAN_F5R2 register  *******************/
#define CAN_F5R2_FB0_Pos       (0U)                                            
#define CAN_F5R2_FB0_Msk       (0x1UL << CAN_F5R2_FB0_Pos)                      
#define CAN_F5R2_FB0           CAN_F5R2_FB0_Msk                               
#define CAN_F5R2_FB1_Pos       (1U)                                           
#define CAN_F5R2_FB1_Msk       (0x1UL << CAN_F5R2_FB1_Pos)                    
#define CAN_F5R2_FB1           CAN_F5R2_FB1_Msk                               
#define CAN_F5R2_FB2_Pos       (2U)                                           
#define CAN_F5R2_FB2_Msk       (0x1UL << CAN_F5R2_FB2_Pos)                    
#define CAN_F5R2_FB2           CAN_F5R2_FB2_Msk                               
#define CAN_F5R2_FB3_Pos       (3U)                                           
#define CAN_F5R2_FB3_Msk       (0x1UL << CAN_F5R2_FB3_Pos)                    
#define CAN_F5R2_FB3           CAN_F5R2_FB3_Msk                               
#define CAN_F5R2_FB4_Pos       (4U)                                           
#define CAN_F5R2_FB4_Msk       (0x1UL << CAN_F5R2_FB4_Pos)                    
#define CAN_F5R2_FB4           CAN_F5R2_FB4_Msk                               
#define CAN_F5R2_FB5_Pos       (5U)                                           
#define CAN_F5R2_FB5_Msk       (0x1UL << CAN_F5R2_FB5_Pos)                    
#define CAN_F5R2_FB5           CAN_F5R2_FB5_Msk                               
#define CAN_F5R2_FB6_Pos       (6U)                                           
#define CAN_F5R2_FB6_Msk       (0x1UL << CAN_F5R2_FB6_Pos)                    
#define CAN_F5R2_FB6           CAN_F5R2_FB6_Msk                               
#define CAN_F5R2_FB7_Pos       (7U)                                           
#define CAN_F5R2_FB7_Msk       (0x1UL << CAN_F5R2_FB7_Pos)                    
#define CAN_F5R2_FB7           CAN_F5R2_FB7_Msk                               
#define CAN_F5R2_FB8_Pos       (8U)                                           
#define CAN_F5R2_FB8_Msk       (0x1UL << CAN_F5R2_FB8_Pos)                    
#define CAN_F5R2_FB8           CAN_F5R2_FB8_Msk                               
#define CAN_F5R2_FB9_Pos       (9U)                                           
#define CAN_F5R2_FB9_Msk       (0x1UL << CAN_F5R2_FB9_Pos)                    
#define CAN_F5R2_FB9           CAN_F5R2_FB9_Msk                               
#define CAN_F5R2_FB10_Pos      (10U)                                          
#define CAN_F5R2_FB10_Msk      (0x1UL << CAN_F5R2_FB10_Pos)                   
#define CAN_F5R2_FB10          CAN_F5R2_FB10_Msk                              
#define CAN_F5R2_FB11_Pos      (11U)                                          
#define CAN_F5R2_FB11_Msk      (0x1UL << CAN_F5R2_FB11_Pos)                   
#define CAN_F5R2_FB11          CAN_F5R2_FB11_Msk                              
#define CAN_F5R2_FB12_Pos      (12U)                                          
#define CAN_F5R2_FB12_Msk      (0x1UL << CAN_F5R2_FB12_Pos)                   
#define CAN_F5R2_FB12          CAN_F5R2_FB12_Msk                              
#define CAN_F5R2_FB13_Pos      (13U)                                          
#define CAN_F5R2_FB13_Msk      (0x1UL << CAN_F5R2_FB13_Pos)                   
#define CAN_F5R2_FB13          CAN_F5R2_FB13_Msk                              
#define CAN_F5R2_FB14_Pos      (14U)                                          
#define CAN_F5R2_FB14_Msk      (0x1UL << CAN_F5R2_FB14_Pos)                   
#define CAN_F5R2_FB14          CAN_F5R2_FB14_Msk                              
#define CAN_F5R2_FB15_Pos      (15U)                                          
#define CAN_F5R2_FB15_Msk      (0x1UL << CAN_F5R2_FB15_Pos)                   
#define CAN_F5R2_FB15          CAN_F5R2_FB15_Msk                              
#define CAN_F5R2_FB16_Pos      (16U)                                          
#define CAN_F5R2_FB16_Msk      (0x1UL << CAN_F5R2_FB16_Pos)                   
#define CAN_F5R2_FB16          CAN_F5R2_FB16_Msk                              
#define CAN_F5R2_FB17_Pos      (17U)                                          
#define CAN_F5R2_FB17_Msk      (0x1UL << CAN_F5R2_FB17_Pos)                   
#define CAN_F5R2_FB17          CAN_F5R2_FB17_Msk                              
#define CAN_F5R2_FB18_Pos      (18U)                                          
#define CAN_F5R2_FB18_Msk      (0x1UL << CAN_F5R2_FB18_Pos)                   
#define CAN_F5R2_FB18          CAN_F5R2_FB18_Msk                              
#define CAN_F5R2_FB19_Pos      (19U)                                          
#define CAN_F5R2_FB19_Msk      (0x1UL << CAN_F5R2_FB19_Pos)                   
#define CAN_F5R2_FB19          CAN_F5R2_FB19_Msk                              
#define CAN_F5R2_FB20_Pos      (20U)                                          
#define CAN_F5R2_FB20_Msk      (0x1UL << CAN_F5R2_FB20_Pos)                   
#define CAN_F5R2_FB20          CAN_F5R2_FB20_Msk                              
#define CAN_F5R2_FB21_Pos      (21U)                                          
#define CAN_F5R2_FB21_Msk      (0x1UL << CAN_F5R2_FB21_Pos)                   
#define CAN_F5R2_FB21          CAN_F5R2_FB21_Msk                              
#define CAN_F5R2_FB22_Pos      (22U)                                          
#define CAN_F5R2_FB22_Msk      (0x1UL << CAN_F5R2_FB22_Pos)                   
#define CAN_F5R2_FB22          CAN_F5R2_FB22_Msk                              
#define CAN_F5R2_FB23_Pos      (23U)                                          
#define CAN_F5R2_FB23_Msk      (0x1UL << CAN_F5R2_FB23_Pos)                   
#define CAN_F5R2_FB23          CAN_F5R2_FB23_Msk                              
#define CAN_F5R2_FB24_Pos      (24U)                                          
#define CAN_F5R2_FB24_Msk      (0x1UL << CAN_F5R2_FB24_Pos)                   
#define CAN_F5R2_FB24          CAN_F5R2_FB24_Msk                              
#define CAN_F5R2_FB25_Pos      (25U)                                          
#define CAN_F5R2_FB25_Msk      (0x1UL << CAN_F5R2_FB25_Pos)                   
#define CAN_F5R2_FB25          CAN_F5R2_FB25_Msk                              
#define CAN_F5R2_FB26_Pos      (26U)                                          
#define CAN_F5R2_FB26_Msk      (0x1UL << CAN_F5R2_FB26_Pos)                   
#define CAN_F5R2_FB26          CAN_F5R2_FB26_Msk                              
#define CAN_F5R2_FB27_Pos      (27U)                                          
#define CAN_F5R2_FB27_Msk      (0x1UL << CAN_F5R2_FB27_Pos)                   
#define CAN_F5R2_FB27          CAN_F5R2_FB27_Msk                              
#define CAN_F5R2_FB28_Pos      (28U)                                          
#define CAN_F5R2_FB28_Msk      (0x1UL << CAN_F5R2_FB28_Pos)                   
#define CAN_F5R2_FB28          CAN_F5R2_FB28_Msk                              
#define CAN_F5R2_FB29_Pos      (29U)                                          
#define CAN_F5R2_FB29_Msk      (0x1UL << CAN_F5R2_FB29_Pos)                   
#define CAN_F5R2_FB29          CAN_F5R2_FB29_Msk                              
#define CAN_F5R2_FB30_Pos      (30U)                                          
#define CAN_F5R2_FB30_Msk      (0x1UL << CAN_F5R2_FB30_Pos)                   
#define CAN_F5R2_FB30          CAN_F5R2_FB30_Msk                              
#define CAN_F5R2_FB31_Pos      (31U)                                          
#define CAN_F5R2_FB31_Msk      (0x1UL << CAN_F5R2_FB31_Pos)                   
#define CAN_F5R2_FB31          CAN_F5R2_FB31_Msk                              

/*******************  Bit definition for CAN_F6R2 register  *******************/
#define CAN_F6R2_FB0_Pos       (0U)                                            
#define CAN_F6R2_FB0_Msk       (0x1UL << CAN_F6R2_FB0_Pos)                      
#define CAN_F6R2_FB0           CAN_F6R2_FB0_Msk                               
#define CAN_F6R2_FB1_Pos       (1U)                                           
#define CAN_F6R2_FB1_Msk       (0x1UL << CAN_F6R2_FB1_Pos)                    
#define CAN_F6R2_FB1           CAN_F6R2_FB1_Msk                               
#define CAN_F6R2_FB2_Pos       (2U)                                           
#define CAN_F6R2_FB2_Msk       (0x1UL << CAN_F6R2_FB2_Pos)                    
#define CAN_F6R2_FB2           CAN_F6R2_FB2_Msk                               
#define CAN_F6R2_FB3_Pos       (3U)                                           
#define CAN_F6R2_FB3_Msk       (0x1UL << CAN_F6R2_FB3_Pos)                    
#define CAN_F6R2_FB3           CAN_F6R2_FB3_Msk                               
#define CAN_F6R2_FB4_Pos       (4U)                                           
#define CAN_F6R2_FB4_Msk       (0x1UL << CAN_F6R2_FB4_Pos)                    
#define CAN_F6R2_FB4           CAN_F6R2_FB4_Msk                               
#define CAN_F6R2_FB5_Pos       (5U)                                           
#define CAN_F6R2_FB5_Msk       (0x1UL << CAN_F6R2_FB5_Pos)                    
#define CAN_F6R2_FB5           CAN_F6R2_FB5_Msk                               
#define CAN_F6R2_FB6_Pos       (6U)                                           
#define CAN_F6R2_FB6_Msk       (0x1UL << CAN_F6R2_FB6_Pos)                    
#define CAN_F6R2_FB6           CAN_F6R2_FB6_Msk                               
#define CAN_F6R2_FB7_Pos       (7U)                                           
#define CAN_F6R2_FB7_Msk       (0x1UL << CAN_F6R2_FB7_Pos)                    
#define CAN_F6R2_FB7           CAN_F6R2_FB7_Msk                               
#define CAN_F6R2_FB8_Pos       (8U)                                           
#define CAN_F6R2_FB8_Msk       (0x1UL << CAN_F6R2_FB8_Pos)                    
#define CAN_F6R2_FB8           CAN_F6R2_FB8_Msk                               
#define CAN_F6R2_FB9_Pos       (9U)                                           
#define CAN_F6R2_FB9_Msk       (0x1UL << CAN_F6R2_FB9_Pos)                    
#define CAN_F6R2_FB9           CAN_F6R2_FB9_Msk                               
#define CAN_F6R2_FB10_Pos      (10U)                                          
#define CAN_F6R2_FB10_Msk      (0x1UL << CAN_F6R2_FB10_Pos)                   
#define CAN_F6R2_FB10          CAN_F6R2_FB10_Msk                              
#define CAN_F6R2_FB11_Pos      (11U)                                          
#define CAN_F6R2_FB11_Msk      (0x1UL << CAN_F6R2_FB11_Pos)                   
#define CAN_F6R2_FB11          CAN_F6R2_FB11_Msk                              
#define CAN_F6R2_FB12_Pos      (12U)                                          
#define CAN_F6R2_FB12_Msk      (0x1UL << CAN_F6R2_FB12_Pos)                   
#define CAN_F6R2_FB12          CAN_F6R2_FB12_Msk                              
#define CAN_F6R2_FB13_Pos      (13U)                                          
#define CAN_F6R2_FB13_Msk      (0x1UL << CAN_F6R2_FB13_Pos)                   
#define CAN_F6R2_FB13          CAN_F6R2_FB13_Msk                              
#define CAN_F6R2_FB14_Pos      (14U)                                          
#define CAN_F6R2_FB14_Msk      (0x1UL << CAN_F6R2_FB14_Pos)                   
#define CAN_F6R2_FB14          CAN_F6R2_FB14_Msk                              
#define CAN_F6R2_FB15_Pos      (15U)                                          
#define CAN_F6R2_FB15_Msk      (0x1UL << CAN_F6R2_FB15_Pos)                   
#define CAN_F6R2_FB15          CAN_F6R2_FB15_Msk                              
#define CAN_F6R2_FB16_Pos      (16U)                                          
#define CAN_F6R2_FB16_Msk      (0x1UL << CAN_F6R2_FB16_Pos)                   
#define CAN_F6R2_FB16          CAN_F6R2_FB16_Msk                              
#define CAN_F6R2_FB17_Pos      (17U)                                          
#define CAN_F6R2_FB17_Msk      (0x1UL << CAN_F6R2_FB17_Pos)                   
#define CAN_F6R2_FB17          CAN_F6R2_FB17_Msk                              
#define CAN_F6R2_FB18_Pos      (18U)                                          
#define CAN_F6R2_FB18_Msk      (0x1UL << CAN_F6R2_FB18_Pos)                   
#define CAN_F6R2_FB18          CAN_F6R2_FB18_Msk                              
#define CAN_F6R2_FB19_Pos      (19U)                                          
#define CAN_F6R2_FB19_Msk      (0x1UL << CAN_F6R2_FB19_Pos)                   
#define CAN_F6R2_FB19          CAN_F6R2_FB19_Msk                              
#define CAN_F6R2_FB20_Pos      (20U)                                          
#define CAN_F6R2_FB20_Msk      (0x1UL << CAN_F6R2_FB20_Pos)                   
#define CAN_F6R2_FB20          CAN_F6R2_FB20_Msk                              
#define CAN_F6R2_FB21_Pos      (21U)                                          
#define CAN_F6R2_FB21_Msk      (0x1UL << CAN_F6R2_FB21_Pos)                   
#define CAN_F6R2_FB21          CAN_F6R2_FB21_Msk                              
#define CAN_F6R2_FB22_Pos      (22U)                                          
#define CAN_F6R2_FB22_Msk      (0x1UL << CAN_F6R2_FB22_Pos)                   
#define CAN_F6R2_FB22          CAN_F6R2_FB22_Msk                              
#define CAN_F6R2_FB23_Pos      (23U)                                          
#define CAN_F6R2_FB23_Msk      (0x1UL << CAN_F6R2_FB23_Pos)                   
#define CAN_F6R2_FB23          CAN_F6R2_FB23_Msk                              
#define CAN_F6R2_FB24_Pos      (24U)                                          
#define CAN_F6R2_FB24_Msk      (0x1UL << CAN_F6R2_FB24_Pos)                   
#define CAN_F6R2_FB24          CAN_F6R2_FB24_Msk                              
#define CAN_F6R2_FB25_Pos      (25U)                                          
#define CAN_F6R2_FB25_Msk      (0x1UL << CAN_F6R2_FB25_Pos)                   
#define CAN_F6R2_FB25          CAN_F6R2_FB25_Msk                              
#define CAN_F6R2_FB26_Pos      (26U)                                          
#define CAN_F6R2_FB26_Msk      (0x1UL << CAN_F6R2_FB26_Pos)                   
#define CAN_F6R2_FB26          CAN_F6R2_FB26_Msk                              
#define CAN_F6R2_FB27_Pos      (27U)                                          
#define CAN_F6R2_FB27_Msk      (0x1UL << CAN_F6R2_FB27_Pos)                   
#define CAN_F6R2_FB27          CAN_F6R2_FB27_Msk                              
#define CAN_F6R2_FB28_Pos      (28U)                                          
#define CAN_F6R2_FB28_Msk      (0x1UL << CAN_F6R2_FB28_Pos)                   
#define CAN_F6R2_FB28          CAN_F6R2_FB28_Msk                              
#define CAN_F6R2_FB29_Pos      (29U)                                          
#define CAN_F6R2_FB29_Msk      (0x1UL << CAN_F6R2_FB29_Pos)                   
#define CAN_F6R2_FB29          CAN_F6R2_FB29_Msk                              
#define CAN_F6R2_FB30_Pos      (30U)                                          
#define CAN_F6R2_FB30_Msk      (0x1UL << CAN_F6R2_FB30_Pos)                   
#define CAN_F6R2_FB30          CAN_F6R2_FB30_Msk                              
#define CAN_F6R2_FB31_Pos      (31U)                                          
#define CAN_F6R2_FB31_Msk      (0x1UL << CAN_F6R2_FB31_Pos)                   
#define CAN_F6R2_FB31          CAN_F6R2_FB31_Msk                              

/*******************  Bit definition for CAN_F7R2 register  *******************/
#define CAN_F7R2_FB0_Pos       (0U)                                            
#define CAN_F7R2_FB0_Msk       (0x1UL << CAN_F7R2_FB0_Pos)                      
#define CAN_F7R2_FB0           CAN_F7R2_FB0_Msk                               
#define CAN_F7R2_FB1_Pos       (1U)                                           
#define CAN_F7R2_FB1_Msk       (0x1UL << CAN_F7R2_FB1_Pos)                    
#define CAN_F7R2_FB1           CAN_F7R2_FB1_Msk                               
#define CAN_F7R2_FB2_Pos       (2U)                                           
#define CAN_F7R2_FB2_Msk       (0x1UL << CAN_F7R2_FB2_Pos)                    
#define CAN_F7R2_FB2           CAN_F7R2_FB2_Msk                               
#define CAN_F7R2_FB3_Pos       (3U)                                           
#define CAN_F7R2_FB3_Msk       (0x1UL << CAN_F7R2_FB3_Pos)                    
#define CAN_F7R2_FB3           CAN_F7R2_FB3_Msk                               
#define CAN_F7R2_FB4_Pos       (4U)                                           
#define CAN_F7R2_FB4_Msk       (0x1UL << CAN_F7R2_FB4_Pos)                    
#define CAN_F7R2_FB4           CAN_F7R2_FB4_Msk                               
#define CAN_F7R2_FB5_Pos       (5U)                                           
#define CAN_F7R2_FB5_Msk       (0x1UL << CAN_F7R2_FB5_Pos)                    
#define CAN_F7R2_FB5           CAN_F7R2_FB5_Msk                               
#define CAN_F7R2_FB6_Pos       (6U)                                           
#define CAN_F7R2_FB6_Msk       (0x1UL << CAN_F7R2_FB6_Pos)                    
#define CAN_F7R2_FB6           CAN_F7R2_FB6_Msk                               
#define CAN_F7R2_FB7_Pos       (7U)                                           
#define CAN_F7R2_FB7_Msk       (0x1UL << CAN_F7R2_FB7_Pos)                    
#define CAN_F7R2_FB7           CAN_F7R2_FB7_Msk                               
#define CAN_F7R2_FB8_Pos       (8U)                                           
#define CAN_F7R2_FB8_Msk       (0x1UL << CAN_F7R2_FB8_Pos)                    
#define CAN_F7R2_FB8           CAN_F7R2_FB8_Msk                               
#define CAN_F7R2_FB9_Pos       (9U)                                           
#define CAN_F7R2_FB9_Msk       (0x1UL << CAN_F7R2_FB9_Pos)                    
#define CAN_F7R2_FB9           CAN_F7R2_FB9_Msk                               
#define CAN_F7R2_FB10_Pos      (10U)                                          
#define CAN_F7R2_FB10_Msk      (0x1UL << CAN_F7R2_FB10_Pos)                   
#define CAN_F7R2_FB10          CAN_F7R2_FB10_Msk                              
#define CAN_F7R2_FB11_Pos      (11U)                                          
#define CAN_F7R2_FB11_Msk      (0x1UL << CAN_F7R2_FB11_Pos)                   
#define CAN_F7R2_FB11          CAN_F7R2_FB11_Msk                              
#define CAN_F7R2_FB12_Pos      (12U)                                          
#define CAN_F7R2_FB12_Msk      (0x1UL << CAN_F7R2_FB12_Pos)                   
#define CAN_F7R2_FB12          CAN_F7R2_FB12_Msk                              
#define CAN_F7R2_FB13_Pos      (13U)                                          
#define CAN_F7R2_FB13_Msk      (0x1UL << CAN_F7R2_FB13_Pos)                   
#define CAN_F7R2_FB13          CAN_F7R2_FB13_Msk                              
#define CAN_F7R2_FB14_Pos      (14U)                                          
#define CAN_F7R2_FB14_Msk      (0x1UL << CAN_F7R2_FB14_Pos)                   
#define CAN_F7R2_FB14          CAN_F7R2_FB14_Msk                              
#define CAN_F7R2_FB15_Pos      (15U)                                          
#define CAN_F7R2_FB15_Msk      (0x1UL << CAN_F7R2_FB15_Pos)                   
#define CAN_F7R2_FB15          CAN_F7R2_FB15_Msk                              
#define CAN_F7R2_FB16_Pos      (16U)                                          
#define CAN_F7R2_FB16_Msk      (0x1UL << CAN_F7R2_FB16_Pos)                   
#define CAN_F7R2_FB16          CAN_F7R2_FB16_Msk                              
#define CAN_F7R2_FB17_Pos      (17U)                                          
#define CAN_F7R2_FB17_Msk      (0x1UL << CAN_F7R2_FB17_Pos)                   
#define CAN_F7R2_FB17          CAN_F7R2_FB17_Msk                              
#define CAN_F7R2_FB18_Pos      (18U)                                          
#define CAN_F7R2_FB18_Msk      (0x1UL << CAN_F7R2_FB18_Pos)                   
#define CAN_F7R2_FB18          CAN_F7R2_FB18_Msk                              
#define CAN_F7R2_FB19_Pos      (19U)                                          
#define CAN_F7R2_FB19_Msk      (0x1UL << CAN_F7R2_FB19_Pos)                   
#define CAN_F7R2_FB19          CAN_F7R2_FB19_Msk                              
#define CAN_F7R2_FB20_Pos      (20U)                                          
#define CAN_F7R2_FB20_Msk      (0x1UL << CAN_F7R2_FB20_Pos)                   
#define CAN_F7R2_FB20          CAN_F7R2_FB20_Msk                              
#define CAN_F7R2_FB21_Pos      (21U)                                          
#define CAN_F7R2_FB21_Msk      (0x1UL << CAN_F7R2_FB21_Pos)                   
#define CAN_F7R2_FB21          CAN_F7R2_FB21_Msk                              
#define CAN_F7R2_FB22_Pos      (22U)                                          
#define CAN_F7R2_FB22_Msk      (0x1UL << CAN_F7R2_FB22_Pos)                   
#define CAN_F7R2_FB22          CAN_F7R2_FB22_Msk                              
#define CAN_F7R2_FB23_Pos      (23U)                                          
#define CAN_F7R2_FB23_Msk      (0x1UL << CAN_F7R2_FB23_Pos)                   
#define CAN_F7R2_FB23          CAN_F7R2_FB23_Msk                              
#define CAN_F7R2_FB24_Pos      (24U)                                          
#define CAN_F7R2_FB24_Msk      (0x1UL << CAN_F7R2_FB24_Pos)                   
#define CAN_F7R2_FB24          CAN_F7R2_FB24_Msk                              
#define CAN_F7R2_FB25_Pos      (25U)                                          
#define CAN_F7R2_FB25_Msk      (0x1UL << CAN_F7R2_FB25_Pos)                   
#define CAN_F7R2_FB25          CAN_F7R2_FB25_Msk                              
#define CAN_F7R2_FB26_Pos      (26U)                                          
#define CAN_F7R2_FB26_Msk      (0x1UL << CAN_F7R2_FB26_Pos)                   
#define CAN_F7R2_FB26          CAN_F7R2_FB26_Msk                              
#define CAN_F7R2_FB27_Pos      (27U)                                          
#define CAN_F7R2_FB27_Msk      (0x1UL << CAN_F7R2_FB27_Pos)                   
#define CAN_F7R2_FB27          CAN_F7R2_FB27_Msk                              
#define CAN_F7R2_FB28_Pos      (28U)                                          
#define CAN_F7R2_FB28_Msk      (0x1UL << CAN_F7R2_FB28_Pos)                   
#define CAN_F7R2_FB28          CAN_F7R2_FB28_Msk                              
#define CAN_F7R2_FB29_Pos      (29U)                                          
#define CAN_F7R2_FB29_Msk      (0x1UL << CAN_F7R2_FB29_Pos)                   
#define CAN_F7R2_FB29          CAN_F7R2_FB29_Msk                              
#define CAN_F7R2_FB30_Pos      (30U)                                          
#define CAN_F7R2_FB30_Msk      (0x1UL << CAN_F7R2_FB30_Pos)                   
#define CAN_F7R2_FB30          CAN_F7R2_FB30_Msk                              
#define CAN_F7R2_FB31_Pos      (31U)                                          
#define CAN_F7R2_FB31_Msk      (0x1UL << CAN_F7R2_FB31_Pos)                   
#define CAN_F7R2_FB31          CAN_F7R2_FB31_Msk                              

/*******************  Bit definition for CAN_F8R2 register  *******************/
#define CAN_F8R2_FB0_Pos       (0U)                                            
#define CAN_F8R2_FB0_Msk       (0x1UL << CAN_F8R2_FB0_Pos)                      
#define CAN_F8R2_FB0           CAN_F8R2_FB0_Msk                                
#define CAN_F8R2_FB1_Pos       (1U)                                           
#define CAN_F8R2_FB1_Msk       (0x1UL << CAN_F8R2_FB1_Pos)                     
#define CAN_F8R2_FB1           CAN_F8R2_FB1_Msk                                
#define CAN_F8R2_FB2_Pos       (2U)                                           
#define CAN_F8R2_FB2_Msk       (0x1UL << CAN_F8R2_FB2_Pos)                     
#define CAN_F8R2_FB2           CAN_F8R2_FB2_Msk                                
#define CAN_F8R2_FB3_Pos       (3U)                                           
#define CAN_F8R2_FB3_Msk       (0x1UL << CAN_F8R2_FB3_Pos)                     
#define CAN_F8R2_FB3           CAN_F8R2_FB3_Msk                                
#define CAN_F8R2_FB4_Pos       (4U)                                           
#define CAN_F8R2_FB4_Msk       (0x1UL << CAN_F8R2_FB4_Pos)                     
#define CAN_F8R2_FB4           CAN_F8R2_FB4_Msk                                
#define CAN_F8R2_FB5_Pos       (5U)                                           
#define CAN_F8R2_FB5_Msk       (0x1UL << CAN_F8R2_FB5_Pos)                     
#define CAN_F8R2_FB5           CAN_F8R2_FB5_Msk                                
#define CAN_F8R2_FB6_Pos       (6U)                                           
#define CAN_F8R2_FB6_Msk       (0x1UL << CAN_F8R2_FB6_Pos)                     
#define CAN_F8R2_FB6           CAN_F8R2_FB6_Msk                                
#define CAN_F8R2_FB7_Pos       (7U)                                           
#define CAN_F8R2_FB7_Msk       (0x1UL << CAN_F8R2_FB7_Pos)                     
#define CAN_F8R2_FB7           CAN_F8R2_FB7_Msk                                
#define CAN_F8R2_FB8_Pos       (8U)                                           
#define CAN_F8R2_FB8_Msk       (0x1UL << CAN_F8R2_FB8_Pos)                     
#define CAN_F8R2_FB8           CAN_F8R2_FB8_Msk                                
#define CAN_F8R2_FB9_Pos       (9U)                                           
#define CAN_F8R2_FB9_Msk       (0x1UL << CAN_F8R2_FB9_Pos)                     
#define CAN_F8R2_FB9           CAN_F8R2_FB9_Msk                                
#define CAN_F8R2_FB10_Pos      (10U)                                          
#define CAN_F8R2_FB10_Msk      (0x1UL << CAN_F8R2_FB10_Pos)                    
#define CAN_F8R2_FB10          CAN_F8R2_FB10_Msk                               
#define CAN_F8R2_FB11_Pos      (11U)                                          
#define CAN_F8R2_FB11_Msk      (0x1UL << CAN_F8R2_FB11_Pos)                    
#define CAN_F8R2_FB11          CAN_F8R2_FB11_Msk                               
#define CAN_F8R2_FB12_Pos      (12U)                                          
#define CAN_F8R2_FB12_Msk      (0x1UL << CAN_F8R2_FB12_Pos)                    
#define CAN_F8R2_FB12          CAN_F8R2_FB12_Msk                               
#define CAN_F8R2_FB13_Pos      (13U)                                          
#define CAN_F8R2_FB13_Msk      (0x1UL << CAN_F8R2_FB13_Pos)                    
#define CAN_F8R2_FB13          CAN_F8R2_FB13_Msk                               
#define CAN_F8R2_FB14_Pos      (14U)                                          
#define CAN_F8R2_FB14_Msk      (0x1UL << CAN_F8R2_FB14_Pos)                    
#define CAN_F8R2_FB14          CAN_F8R2_FB14_Msk                               
#define CAN_F8R2_FB15_Pos      (15U)                                          
#define CAN_F8R2_FB15_Msk      (0x1UL << CAN_F8R2_FB15_Pos)                    
#define CAN_F8R2_FB15          CAN_F8R2_FB15_Msk                               
#define CAN_F8R2_FB16_Pos      (16U)                                          
#define CAN_F8R2_FB16_Msk      (0x1UL << CAN_F8R2_FB16_Pos)                    
#define CAN_F8R2_FB16          CAN_F8R2_FB16_Msk                               
#define CAN_F8R2_FB17_Pos      (17U)                                          
#define CAN_F8R2_FB17_Msk      (0x1UL << CAN_F8R2_FB17_Pos)                    
#define CAN_F8R2_FB17          CAN_F8R2_FB17_Msk                               
#define CAN_F8R2_FB18_Pos      (18U)                                          
#define CAN_F8R2_FB18_Msk      (0x1UL << CAN_F8R2_FB18_Pos)                    
#define CAN_F8R2_FB18          CAN_F8R2_FB18_Msk                               
#define CAN_F8R2_FB19_Pos      (19U)                                          
#define CAN_F8R2_FB19_Msk      (0x1UL << CAN_F8R2_FB19_Pos)                    
#define CAN_F8R2_FB19          CAN_F8R2_FB19_Msk                               
#define CAN_F8R2_FB20_Pos      (20U)                                          
#define CAN_F8R2_FB20_Msk      (0x1UL << CAN_F8R2_FB20_Pos)                    
#define CAN_F8R2_FB20          CAN_F8R2_FB20_Msk                               
#define CAN_F8R2_FB21_Pos      (21U)                                          
#define CAN_F8R2_FB21_Msk      (0x1UL << CAN_F8R2_FB21_Pos)                    
#define CAN_F8R2_FB21          CAN_F8R2_FB21_Msk                               
#define CAN_F8R2_FB22_Pos      (22U)                                          
#define CAN_F8R2_FB22_Msk      (0x1UL << CAN_F8R2_FB22_Pos)                    
#define CAN_F8R2_FB22          CAN_F8R2_FB22_Msk                               
#define CAN_F8R2_FB23_Pos      (23U)                                          
#define CAN_F8R2_FB23_Msk      (0x1UL << CAN_F8R2_FB23_Pos)                    
#define CAN_F8R2_FB23          CAN_F8R2_FB23_Msk                               
#define CAN_F8R2_FB24_Pos      (24U)                                          
#define CAN_F8R2_FB24_Msk      (0x1UL << CAN_F8R2_FB24_Pos)                    
#define CAN_F8R2_FB24          CAN_F8R2_FB24_Msk                               
#define CAN_F8R2_FB25_Pos      (25U)                                          
#define CAN_F8R2_FB25_Msk      (0x1UL << CAN_F8R2_FB25_Pos)                    
#define CAN_F8R2_FB25          CAN_F8R2_FB25_Msk                               
#define CAN_F8R2_FB26_Pos      (26U)                                          
#define CAN_F8R2_FB26_Msk      (0x1UL << CAN_F8R2_FB26_Pos)                    
#define CAN_F8R2_FB26          CAN_F8R2_FB26_Msk                               
#define CAN_F8R2_FB27_Pos      (27U)                                          
#define CAN_F8R2_FB27_Msk      (0x1UL << CAN_F8R2_FB27_Pos)                    
#define CAN_F8R2_FB27          CAN_F8R2_FB27_Msk                               
#define CAN_F8R2_FB28_Pos      (28U)                                          
#define CAN_F8R2_FB28_Msk      (0x1UL << CAN_F8R2_FB28_Pos)                    
#define CAN_F8R2_FB28          CAN_F8R2_FB28_Msk                               
#define CAN_F8R2_FB29_Pos      (29U)                                          
#define CAN_F8R2_FB29_Msk      (0x1UL << CAN_F8R2_FB29_Pos)                    
#define CAN_F8R2_FB29          CAN_F8R2_FB29_Msk                               
#define CAN_F8R2_FB30_Pos      (30U)                                          
#define CAN_F8R2_FB30_Msk      (0x1UL << CAN_F8R2_FB30_Pos)                    
#define CAN_F8R2_FB30          CAN_F8R2_FB30_Msk                               
#define CAN_F8R2_FB31_Pos      (31U)                                          
#define CAN_F8R2_FB31_Msk      (0x1UL << CAN_F8R2_FB31_Pos)                    
#define CAN_F8R2_FB31          CAN_F8R2_FB31_Msk                               

/*******************  Bit definition for CAN_F9R2 register  *******************/
#define CAN_F9R2_FB0_Pos       (0U)                                           
#define CAN_F9R2_FB0_Msk       (0x1UL << CAN_F9R2_FB0_Pos)                     
#define CAN_F9R2_FB0           CAN_F9R2_FB0_Msk                                
#define CAN_F9R2_FB1_Pos       (1U)                                           
#define CAN_F9R2_FB1_Msk       (0x1UL << CAN_F9R2_FB1_Pos)                     
#define CAN_F9R2_FB1           CAN_F9R2_FB1_Msk                                
#define CAN_F9R2_FB2_Pos       (2U)                                           
#define CAN_F9R2_FB2_Msk       (0x1UL << CAN_F9R2_FB2_Pos)                     
#define CAN_F9R2_FB2           CAN_F9R2_FB2_Msk                                
#define CAN_F9R2_FB3_Pos       (3U)                                           
#define CAN_F9R2_FB3_Msk       (0x1UL << CAN_F9R2_FB3_Pos)                     
#define CAN_F9R2_FB3           CAN_F9R2_FB3_Msk                                
#define CAN_F9R2_FB4_Pos       (4U)                                           
#define CAN_F9R2_FB4_Msk       (0x1UL << CAN_F9R2_FB4_Pos)                     
#define CAN_F9R2_FB4           CAN_F9R2_FB4_Msk                                
#define CAN_F9R2_FB5_Pos       (5U)                                           
#define CAN_F9R2_FB5_Msk       (0x1UL << CAN_F9R2_FB5_Pos)                     
#define CAN_F9R2_FB5           CAN_F9R2_FB5_Msk                                
#define CAN_F9R2_FB6_Pos       (6U)                                           
#define CAN_F9R2_FB6_Msk       (0x1UL << CAN_F9R2_FB6_Pos)                     
#define CAN_F9R2_FB6           CAN_F9R2_FB6_Msk                                
#define CAN_F9R2_FB7_Pos       (7U)                                           
#define CAN_F9R2_FB7_Msk       (0x1UL << CAN_F9R2_FB7_Pos)                     
#define CAN_F9R2_FB7           CAN_F9R2_FB7_Msk                                
#define CAN_F9R2_FB8_Pos       (8U)                                           
#define CAN_F9R2_FB8_Msk       (0x1UL << CAN_F9R2_FB8_Pos)                     
#define CAN_F9R2_FB8           CAN_F9R2_FB8_Msk                                
#define CAN_F9R2_FB9_Pos       (9U)                                           
#define CAN_F9R2_FB9_Msk       (0x1UL << CAN_F9R2_FB9_Pos)                     
#define CAN_F9R2_FB9           CAN_F9R2_FB9_Msk                                
#define CAN_F9R2_FB10_Pos      (10U)                                          
#define CAN_F9R2_FB10_Msk      (0x1UL << CAN_F9R2_FB10_Pos)                    
#define CAN_F9R2_FB10          CAN_F9R2_FB10_Msk                               
#define CAN_F9R2_FB11_Pos      (11U)                                          
#define CAN_F9R2_FB11_Msk      (0x1UL << CAN_F9R2_FB11_Pos)                    
#define CAN_F9R2_FB11          CAN_F9R2_FB11_Msk                               
#define CAN_F9R2_FB12_Pos      (12U)                                          
#define CAN_F9R2_FB12_Msk      (0x1UL << CAN_F9R2_FB12_Pos)                    
#define CAN_F9R2_FB12          CAN_F9R2_FB12_Msk                               
#define CAN_F9R2_FB13_Pos      (13U)                                          
#define CAN_F9R2_FB13_Msk      (0x1UL << CAN_F9R2_FB13_Pos)                    
#define CAN_F9R2_FB13          CAN_F9R2_FB13_Msk                               
#define CAN_F9R2_FB14_Pos      (14U)                                          
#define CAN_F9R2_FB14_Msk      (0x1UL << CAN_F9R2_FB14_Pos)                    
#define CAN_F9R2_FB14          CAN_F9R2_FB14_Msk                               
#define CAN_F9R2_FB15_Pos      (15U)                                          
#define CAN_F9R2_FB15_Msk      (0x1UL << CAN_F9R2_FB15_Pos)                    
#define CAN_F9R2_FB15          CAN_F9R2_FB15_Msk                               
#define CAN_F9R2_FB16_Pos      (16U)                                          
#define CAN_F9R2_FB16_Msk      (0x1UL << CAN_F9R2_FB16_Pos)                    
#define CAN_F9R2_FB16          CAN_F9R2_FB16_Msk                               
#define CAN_F9R2_FB17_Pos      (17U)                                          
#define CAN_F9R2_FB17_Msk      (0x1UL << CAN_F9R2_FB17_Pos)                    
#define CAN_F9R2_FB17          CAN_F9R2_FB17_Msk                               
#define CAN_F9R2_FB18_Pos      (18U)                                          
#define CAN_F9R2_FB18_Msk      (0x1UL << CAN_F9R2_FB18_Pos)                    
#define CAN_F9R2_FB18          CAN_F9R2_FB18_Msk                               
#define CAN_F9R2_FB19_Pos      (19U)                                          
#define CAN_F9R2_FB19_Msk      (0x1UL << CAN_F9R2_FB19_Pos)                    
#define CAN_F9R2_FB19          CAN_F9R2_FB19_Msk                               
#define CAN_F9R2_FB20_Pos      (20U)                                          
#define CAN_F9R2_FB20_Msk      (0x1UL << CAN_F9R2_FB20_Pos)                    
#define CAN_F9R2_FB20          CAN_F9R2_FB20_Msk                               
#define CAN_F9R2_FB21_Pos      (21U)                                          
#define CAN_F9R2_FB21_Msk      (0x1UL << CAN_F9R2_FB21_Pos)                    
#define CAN_F9R2_FB21          CAN_F9R2_FB21_Msk                               
#define CAN_F9R2_FB22_Pos      (22U)                                          
#define CAN_F9R2_FB22_Msk      (0x1UL << CAN_F9R2_FB22_Pos)                    
#define CAN_F9R2_FB22          CAN_F9R2_FB22_Msk                               
#define CAN_F9R2_FB23_Pos      (23U)                                          
#define CAN_F9R2_FB23_Msk      (0x1UL << CAN_F9R2_FB23_Pos)                    
#define CAN_F9R2_FB23          CAN_F9R2_FB23_Msk                               
#define CAN_F9R2_FB24_Pos      (24U)                                          
#define CAN_F9R2_FB24_Msk      (0x1UL << CAN_F9R2_FB24_Pos)                    
#define CAN_F9R2_FB24          CAN_F9R2_FB24_Msk                               
#define CAN_F9R2_FB25_Pos      (25U)                                          
#define CAN_F9R2_FB25_Msk      (0x1UL << CAN_F9R2_FB25_Pos)                    
#define CAN_F9R2_FB25          CAN_F9R2_FB25_Msk                               
#define CAN_F9R2_FB26_Pos      (26U)                                          
#define CAN_F9R2_FB26_Msk      (0x1UL << CAN_F9R2_FB26_Pos)                    
#define CAN_F9R2_FB26          CAN_F9R2_FB26_Msk                               
#define CAN_F9R2_FB27_Pos      (27U)                                          
#define CAN_F9R2_FB27_Msk      (0x1UL << CAN_F9R2_FB27_Pos)                    
#define CAN_F9R2_FB27          CAN_F9R2_FB27_Msk                               
#define CAN_F9R2_FB28_Pos      (28U)                                          
#define CAN_F9R2_FB28_Msk      (0x1UL << CAN_F9R2_FB28_Pos)                    
#define CAN_F9R2_FB28          CAN_F9R2_FB28_Msk                               
#define CAN_F9R2_FB29_Pos      (29U)                                          
#define CAN_F9R2_FB29_Msk      (0x1UL << CAN_F9R2_FB29_Pos)                    
#define CAN_F9R2_FB29          CAN_F9R2_FB29_Msk                               
#define CAN_F9R2_FB30_Pos      (30U)                                          
#define CAN_F9R2_FB30_Msk      (0x1UL << CAN_F9R2_FB30_Pos)                    
#define CAN_F9R2_FB30          CAN_F9R2_FB30_Msk                               
#define CAN_F9R2_FB31_Pos      (31U)                                          
#define CAN_F9R2_FB31_Msk      (0x1UL << CAN_F9R2_FB31_Pos)                    
#define CAN_F9R2_FB31          CAN_F9R2_FB31_Msk                               

/*******************  Bit definition for CAN_F10R2 register  ******************/
#define CAN_F10R2_FB0_Pos      (0U)                                           
#define CAN_F10R2_FB0_Msk      (0x1UL << CAN_F10R2_FB0_Pos)                    
#define CAN_F10R2_FB0          CAN_F10R2_FB0_Msk                               
#define CAN_F10R2_FB1_Pos      (1U)                                           
#define CAN_F10R2_FB1_Msk      (0x1UL << CAN_F10R2_FB1_Pos)                    
#define CAN_F10R2_FB1          CAN_F10R2_FB1_Msk                               
#define CAN_F10R2_FB2_Pos      (2U)                                           
#define CAN_F10R2_FB2_Msk      (0x1UL << CAN_F10R2_FB2_Pos)                    
#define CAN_F10R2_FB2          CAN_F10R2_FB2_Msk                               
#define CAN_F10R2_FB3_Pos      (3U)                                           
#define CAN_F10R2_FB3_Msk      (0x1UL << CAN_F10R2_FB3_Pos)                    
#define CAN_F10R2_FB3          CAN_F10R2_FB3_Msk                               
#define CAN_F10R2_FB4_Pos      (4U)                                           
#define CAN_F10R2_FB4_Msk      (0x1UL << CAN_F10R2_FB4_Pos)                    
#define CAN_F10R2_FB4          CAN_F10R2_FB4_Msk                               
#define CAN_F10R2_FB5_Pos      (5U)                                           
#define CAN_F10R2_FB5_Msk      (0x1UL << CAN_F10R2_FB5_Pos)                    
#define CAN_F10R2_FB5          CAN_F10R2_FB5_Msk                               
#define CAN_F10R2_FB6_Pos      (6U)                                           
#define CAN_F10R2_FB6_Msk      (0x1UL << CAN_F10R2_FB6_Pos)                    
#define CAN_F10R2_FB6          CAN_F10R2_FB6_Msk                               
#define CAN_F10R2_FB7_Pos      (7U)                                           
#define CAN_F10R2_FB7_Msk      (0x1UL << CAN_F10R2_FB7_Pos)                    
#define CAN_F10R2_FB7          CAN_F10R2_FB7_Msk                               
#define CAN_F10R2_FB8_Pos      (8U)                                           
#define CAN_F10R2_FB8_Msk      (0x1UL << CAN_F10R2_FB8_Pos)                    
#define CAN_F10R2_FB8          CAN_F10R2_FB8_Msk                               
#define CAN_F10R2_FB9_Pos      (9U)                                           
#define CAN_F10R2_FB9_Msk      (0x1UL << CAN_F10R2_FB9_Pos)                    
#define CAN_F10R2_FB9          CAN_F10R2_FB9_Msk                               
#define CAN_F10R2_FB10_Pos     (10U)                                          
#define CAN_F10R2_FB10_Msk     (0x1UL << CAN_F10R2_FB10_Pos)                   
#define CAN_F10R2_FB10         CAN_F10R2_FB10_Msk                              
#define CAN_F10R2_FB11_Pos     (11U)                                          
#define CAN_F10R2_FB11_Msk     (0x1UL << CAN_F10R2_FB11_Pos)                   
#define CAN_F10R2_FB11         CAN_F10R2_FB11_Msk                              
#define CAN_F10R2_FB12_Pos     (12U)                                          
#define CAN_F10R2_FB12_Msk     (0x1UL << CAN_F10R2_FB12_Pos)                   
#define CAN_F10R2_FB12         CAN_F10R2_FB12_Msk                              
#define CAN_F10R2_FB13_Pos     (13U)                                          
#define CAN_F10R2_FB13_Msk     (0x1UL << CAN_F10R2_FB13_Pos)                   
#define CAN_F10R2_FB13         CAN_F10R2_FB13_Msk                              
#define CAN_F10R2_FB14_Pos     (14U)                                          
#define CAN_F10R2_FB14_Msk     (0x1UL << CAN_F10R2_FB14_Pos)                   
#define CAN_F10R2_FB14         CAN_F10R2_FB14_Msk                              
#define CAN_F10R2_FB15_Pos     (15U)                                          
#define CAN_F10R2_FB15_Msk     (0x1UL << CAN_F10R2_FB15_Pos)                   
#define CAN_F10R2_FB15         CAN_F10R2_FB15_Msk                              
#define CAN_F10R2_FB16_Pos     (16U)                                          
#define CAN_F10R2_FB16_Msk     (0x1UL << CAN_F10R2_FB16_Pos)                   
#define CAN_F10R2_FB16         CAN_F10R2_FB16_Msk                              
#define CAN_F10R2_FB17_Pos     (17U)                                          
#define CAN_F10R2_FB17_Msk     (0x1UL << CAN_F10R2_FB17_Pos)                   
#define CAN_F10R2_FB17         CAN_F10R2_FB17_Msk                              
#define CAN_F10R2_FB18_Pos     (18U)                                          
#define CAN_F10R2_FB18_Msk     (0x1UL << CAN_F10R2_FB18_Pos)                   
#define CAN_F10R2_FB18         CAN_F10R2_FB18_Msk                              
#define CAN_F10R2_FB19_Pos     (19U)                                          
#define CAN_F10R2_FB19_Msk     (0x1UL << CAN_F10R2_FB19_Pos)                   
#define CAN_F10R2_FB19         CAN_F10R2_FB19_Msk                              
#define CAN_F10R2_FB20_Pos     (20U)                                          
#define CAN_F10R2_FB20_Msk     (0x1UL << CAN_F10R2_FB20_Pos)                   
#define CAN_F10R2_FB20         CAN_F10R2_FB20_Msk                              
#define CAN_F10R2_FB21_Pos     (21U)                                          
#define CAN_F10R2_FB21_Msk     (0x1UL << CAN_F10R2_FB21_Pos)                   
#define CAN_F10R2_FB21         CAN_F10R2_FB21_Msk                              
#define CAN_F10R2_FB22_Pos     (22U)                                          
#define CAN_F10R2_FB22_Msk     (0x1UL << CAN_F10R2_FB22_Pos)                   
#define CAN_F10R2_FB22         CAN_F10R2_FB22_Msk                              
#define CAN_F10R2_FB23_Pos     (23U)                                          
#define CAN_F10R2_FB23_Msk     (0x1UL << CAN_F10R2_FB23_Pos)                   
#define CAN_F10R2_FB23         CAN_F10R2_FB23_Msk                              
#define CAN_F10R2_FB24_Pos     (24U)                                          
#define CAN_F10R2_FB24_Msk     (0x1UL << CAN_F10R2_FB24_Pos)                   
#define CAN_F10R2_FB24         CAN_F10R2_FB24_Msk                              
#define CAN_F10R2_FB25_Pos     (25U)                                          
#define CAN_F10R2_FB25_Msk     (0x1UL << CAN_F10R2_FB25_Pos)                   
#define CAN_F10R2_FB25         CAN_F10R2_FB25_Msk                              
#define CAN_F10R2_FB26_Pos     (26U)                                          
#define CAN_F10R2_FB26_Msk     (0x1UL << CAN_F10R2_FB26_Pos)                   
#define CAN_F10R2_FB26         CAN_F10R2_FB26_Msk                              
#define CAN_F10R2_FB27_Pos     (27U)                                          
#define CAN_F10R2_FB27_Msk     (0x1UL << CAN_F10R2_FB27_Pos)                   
#define CAN_F10R2_FB27         CAN_F10R2_FB27_Msk                              
#define CAN_F10R2_FB28_Pos     (28U)                                          
#define CAN_F10R2_FB28_Msk     (0x1UL << CAN_F10R2_FB28_Pos)                   
#define CAN_F10R2_FB28         CAN_F10R2_FB28_Msk                              
#define CAN_F10R2_FB29_Pos     (29U)                                          
#define CAN_F10R2_FB29_Msk     (0x1UL << CAN_F10R2_FB29_Pos)                   
#define CAN_F10R2_FB29         CAN_F10R2_FB29_Msk                              
#define CAN_F10R2_FB30_Pos     (30U)                                          
#define CAN_F10R2_FB30_Msk     (0x1UL << CAN_F10R2_FB30_Pos)                   
#define CAN_F10R2_FB30         CAN_F10R2_FB30_Msk                              
#define CAN_F10R2_FB31_Pos     (31U)                                          
#define CAN_F10R2_FB31_Msk     (0x1UL << CAN_F10R2_FB31_Pos)                   
#define CAN_F10R2_FB31         CAN_F10R2_FB31_Msk                              

/*******************  Bit definition for CAN_F11R2 register  ******************/
#define CAN_F11R2_FB0_Pos      (0U)                                           
#define CAN_F11R2_FB0_Msk      (0x1UL << CAN_F11R2_FB0_Pos)                    
#define CAN_F11R2_FB0          CAN_F11R2_FB0_Msk                               
#define CAN_F11R2_FB1_Pos      (1U)                                           
#define CAN_F11R2_FB1_Msk      (0x1UL << CAN_F11R2_FB1_Pos)                    
#define CAN_F11R2_FB1          CAN_F11R2_FB1_Msk                               
#define CAN_F11R2_FB2_Pos      (2U)                                           
#define CAN_F11R2_FB2_Msk      (0x1UL << CAN_F11R2_FB2_Pos)                    
#define CAN_F11R2_FB2          CAN_F11R2_FB2_Msk                               
#define CAN_F11R2_FB3_Pos      (3U)                                           
#define CAN_F11R2_FB3_Msk      (0x1UL << CAN_F11R2_FB3_Pos)                    
#define CAN_F11R2_FB3          CAN_F11R2_FB3_Msk                               
#define CAN_F11R2_FB4_Pos      (4U)                                           
#define CAN_F11R2_FB4_Msk      (0x1UL << CAN_F11R2_FB4_Pos)                    
#define CAN_F11R2_FB4          CAN_F11R2_FB4_Msk                               
#define CAN_F11R2_FB5_Pos      (5U)                                           
#define CAN_F11R2_FB5_Msk      (0x1UL << CAN_F11R2_FB5_Pos)                    
#define CAN_F11R2_FB5          CAN_F11R2_FB5_Msk                               
#define CAN_F11R2_FB6_Pos      (6U)                                           
#define CAN_F11R2_FB6_Msk      (0x1UL << CAN_F11R2_FB6_Pos)                    
#define CAN_F11R2_FB6          CAN_F11R2_FB6_Msk                               
#define CAN_F11R2_FB7_Pos      (7U)                                           
#define CAN_F11R2_FB7_Msk      (0x1UL << CAN_F11R2_FB7_Pos)                    
#define CAN_F11R2_FB7          CAN_F11R2_FB7_Msk                               
#define CAN_F11R2_FB8_Pos      (8U)                                           
#define CAN_F11R2_FB8_Msk      (0x1UL << CAN_F11R2_FB8_Pos)                    
#define CAN_F11R2_FB8          CAN_F11R2_FB8_Msk                               
#define CAN_F11R2_FB9_Pos      (9U)                                           
#define CAN_F11R2_FB9_Msk      (0x1UL << CAN_F11R2_FB9_Pos)                    
#define CAN_F11R2_FB9          CAN_F11R2_FB9_Msk                               
#define CAN_F11R2_FB10_Pos     (10U)                                          
#define CAN_F11R2_FB10_Msk     (0x1UL << CAN_F11R2_FB10_Pos)                   
#define CAN_F11R2_FB10         CAN_F11R2_FB10_Msk                              
#define CAN_F11R2_FB11_Pos     (11U)                                          
#define CAN_F11R2_FB11_Msk     (0x1UL << CAN_F11R2_FB11_Pos)                   
#define CAN_F11R2_FB11         CAN_F11R2_FB11_Msk                              
#define CAN_F11R2_FB12_Pos     (12U)                                          
#define CAN_F11R2_FB12_Msk     (0x1UL << CAN_F11R2_FB12_Pos)                   
#define CAN_F11R2_FB12         CAN_F11R2_FB12_Msk                              
#define CAN_F11R2_FB13_Pos     (13U)                                          
#define CAN_F11R2_FB13_Msk     (0x1UL << CAN_F11R2_FB13_Pos)                   
#define CAN_F11R2_FB13         CAN_F11R2_FB13_Msk                              
#define CAN_F11R2_FB14_Pos     (14U)                                          
#define CAN_F11R2_FB14_Msk     (0x1UL << CAN_F11R2_FB14_Pos)                   
#define CAN_F11R2_FB14         CAN_F11R2_FB14_Msk                              
#define CAN_F11R2_FB15_Pos     (15U)                                          
#define CAN_F11R2_FB15_Msk     (0x1UL << CAN_F11R2_FB15_Pos)                   
#define CAN_F11R2_FB15         CAN_F11R2_FB15_Msk                              
#define CAN_F11R2_FB16_Pos     (16U)                                          
#define CAN_F11R2_FB16_Msk     (0x1UL << CAN_F11R2_FB16_Pos)                   
#define CAN_F11R2_FB16         CAN_F11R2_FB16_Msk                              
#define CAN_F11R2_FB17_Pos     (17U)                                          
#define CAN_F11R2_FB17_Msk     (0x1UL << CAN_F11R2_FB17_Pos)                   
#define CAN_F11R2_FB17         CAN_F11R2_FB17_Msk                              
#define CAN_F11R2_FB18_Pos     (18U)                                          
#define CAN_F11R2_FB18_Msk     (0x1UL << CAN_F11R2_FB18_Pos)                   
#define CAN_F11R2_FB18         CAN_F11R2_FB18_Msk                              
#define CAN_F11R2_FB19_Pos     (19U)                                          
#define CAN_F11R2_FB19_Msk     (0x1UL << CAN_F11R2_FB19_Pos)                   
#define CAN_F11R2_FB19         CAN_F11R2_FB19_Msk                              
#define CAN_F11R2_FB20_Pos     (20U)                                          
#define CAN_F11R2_FB20_Msk     (0x1UL << CAN_F11R2_FB20_Pos)                   
#define CAN_F11R2_FB20         CAN_F11R2_FB20_Msk                              
#define CAN_F11R2_FB21_Pos     (21U)                                          
#define CAN_F11R2_FB21_Msk     (0x1UL << CAN_F11R2_FB21_Pos)                   
#define CAN_F11R2_FB21         CAN_F11R2_FB21_Msk                              
#define CAN_F11R2_FB22_Pos     (22U)                                          
#define CAN_F11R2_FB22_Msk     (0x1UL << CAN_F11R2_FB22_Pos)                   
#define CAN_F11R2_FB22         CAN_F11R2_FB22_Msk                              
#define CAN_F11R2_FB23_Pos     (23U)                                          
#define CAN_F11R2_FB23_Msk     (0x1UL << CAN_F11R2_FB23_Pos)                   
#define CAN_F11R2_FB23         CAN_F11R2_FB23_Msk                              
#define CAN_F11R2_FB24_Pos     (24U)                                          
#define CAN_F11R2_FB24_Msk     (0x1UL << CAN_F11R2_FB24_Pos)                   
#define CAN_F11R2_FB24         CAN_F11R2_FB24_Msk                              
#define CAN_F11R2_FB25_Pos     (25U)                                          
#define CAN_F11R2_FB25_Msk     (0x1UL << CAN_F11R2_FB25_Pos)                   
#define CAN_F11R2_FB25         CAN_F11R2_FB25_Msk                              
#define CAN_F11R2_FB26_Pos     (26U)                                          
#define CAN_F11R2_FB26_Msk     (0x1UL << CAN_F11R2_FB26_Pos)                   
#define CAN_F11R2_FB26         CAN_F11R2_FB26_Msk                              
#define CAN_F11R2_FB27_Pos     (27U)                                          
#define CAN_F11R2_FB27_Msk     (0x1UL << CAN_F11R2_FB27_Pos)                   
#define CAN_F11R2_FB27         CAN_F11R2_FB27_Msk                              
#define CAN_F11R2_FB28_Pos     (28U)                                          
#define CAN_F11R2_FB28_Msk     (0x1UL << CAN_F11R2_FB28_Pos)                   
#define CAN_F11R2_FB28         CAN_F11R2_FB28_Msk                              
#define CAN_F11R2_FB29_Pos     (29U)                                          
#define CAN_F11R2_FB29_Msk     (0x1UL << CAN_F11R2_FB29_Pos)                   
#define CAN_F11R2_FB29         CAN_F11R2_FB29_Msk                              
#define CAN_F11R2_FB30_Pos     (30U)                                          
#define CAN_F11R2_FB30_Msk     (0x1UL << CAN_F11R2_FB30_Pos)                   
#define CAN_F11R2_FB30         CAN_F11R2_FB30_Msk                              
#define CAN_F11R2_FB31_Pos     (31U)                                          
#define CAN_F11R2_FB31_Msk     (0x1UL << CAN_F11R2_FB31_Pos)                   
#define CAN_F11R2_FB31         CAN_F11R2_FB31_Msk                              

/*******************  Bit definition for CAN_F12R2 register  ******************/
#define CAN_F12R2_FB0_Pos      (0U)                                           
#define CAN_F12R2_FB0_Msk      (0x1UL << CAN_F12R2_FB0_Pos)                    
#define CAN_F12R2_FB0          CAN_F12R2_FB0_Msk                               
#define CAN_F12R2_FB1_Pos      (1U)                                           
#define CAN_F12R2_FB1_Msk      (0x1UL << CAN_F12R2_FB1_Pos)                    
#define CAN_F12R2_FB1          CAN_F12R2_FB1_Msk                               
#define CAN_F12R2_FB2_Pos      (2U)                                           
#define CAN_F12R2_FB2_Msk      (0x1UL << CAN_F12R2_FB2_Pos)                    
#define CAN_F12R2_FB2          CAN_F12R2_FB2_Msk                               
#define CAN_F12R2_FB3_Pos      (3U)                                           
#define CAN_F12R2_FB3_Msk      (0x1UL << CAN_F12R2_FB3_Pos)                    
#define CAN_F12R2_FB3          CAN_F12R2_FB3_Msk                               
#define CAN_F12R2_FB4_Pos      (4U)                                           
#define CAN_F12R2_FB4_Msk      (0x1UL << CAN_F12R2_FB4_Pos)                    
#define CAN_F12R2_FB4          CAN_F12R2_FB4_Msk                               
#define CAN_F12R2_FB5_Pos      (5U)                                           
#define CAN_F12R2_FB5_Msk      (0x1UL << CAN_F12R2_FB5_Pos)                    
#define CAN_F12R2_FB5          CAN_F12R2_FB5_Msk                               
#define CAN_F12R2_FB6_Pos      (6U)                                           
#define CAN_F12R2_FB6_Msk      (0x1UL << CAN_F12R2_FB6_Pos)                    
#define CAN_F12R2_FB6          CAN_F12R2_FB6_Msk                               
#define CAN_F12R2_FB7_Pos      (7U)                                           
#define CAN_F12R2_FB7_Msk      (0x1UL << CAN_F12R2_FB7_Pos)                    
#define CAN_F12R2_FB7          CAN_F12R2_FB7_Msk                               
#define CAN_F12R2_FB8_Pos      (8U)                                           
#define CAN_F12R2_FB8_Msk      (0x1UL << CAN_F12R2_FB8_Pos)                    
#define CAN_F12R2_FB8          CAN_F12R2_FB8_Msk                               
#define CAN_F12R2_FB9_Pos      (9U)                                           
#define CAN_F12R2_FB9_Msk      (0x1UL << CAN_F12R2_FB9_Pos)                    
#define CAN_F12R2_FB9          CAN_F12R2_FB9_Msk                               
#define CAN_F12R2_FB10_Pos     (10U)                                          
#define CAN_F12R2_FB10_Msk     (0x1UL << CAN_F12R2_FB10_Pos)                   
#define CAN_F12R2_FB10         CAN_F12R2_FB10_Msk                              
#define CAN_F12R2_FB11_Pos     (11U)                                          
#define CAN_F12R2_FB11_Msk     (0x1UL << CAN_F12R2_FB11_Pos)                   
#define CAN_F12R2_FB11         CAN_F12R2_FB11_Msk                              
#define CAN_F12R2_FB12_Pos     (12U)                                          
#define CAN_F12R2_FB12_Msk     (0x1UL << CAN_F12R2_FB12_Pos)                   
#define CAN_F12R2_FB12         CAN_F12R2_FB12_Msk                              
#define CAN_F12R2_FB13_Pos     (13U)                                          
#define CAN_F12R2_FB13_Msk     (0x1UL << CAN_F12R2_FB13_Pos)                   
#define CAN_F12R2_FB13         CAN_F12R2_FB13_Msk                              
#define CAN_F12R2_FB14_Pos     (14U)                                          
#define CAN_F12R2_FB14_Msk     (0x1UL << CAN_F12R2_FB14_Pos)                   
#define CAN_F12R2_FB14         CAN_F12R2_FB14_Msk                              
#define CAN_F12R2_FB15_Pos     (15U)                                          
#define CAN_F12R2_FB15_Msk     (0x1UL << CAN_F12R2_FB15_Pos)                   
#define CAN_F12R2_FB15         CAN_F12R2_FB15_Msk                              
#define CAN_F12R2_FB16_Pos     (16U)                                          
#define CAN_F12R2_FB16_Msk     (0x1UL << CAN_F12R2_FB16_Pos)                   
#define CAN_F12R2_FB16         CAN_F12R2_FB16_Msk                              
#define CAN_F12R2_FB17_Pos     (17U)                                          
#define CAN_F12R2_FB17_Msk     (0x1UL << CAN_F12R2_FB17_Pos)                   
#define CAN_F12R2_FB17         CAN_F12R2_FB17_Msk                              
#define CAN_F12R2_FB18_Pos     (18U)                                          
#define CAN_F12R2_FB18_Msk     (0x1UL << CAN_F12R2_FB18_Pos)                   
#define CAN_F12R2_FB18         CAN_F12R2_FB18_Msk                              
#define CAN_F12R2_FB19_Pos     (19U)                                          
#define CAN_F12R2_FB19_Msk     (0x1UL << CAN_F12R2_FB19_Pos)                   
#define CAN_F12R2_FB19         CAN_F12R2_FB19_Msk                              
#define CAN_F12R2_FB20_Pos     (20U)                                          
#define CAN_F12R2_FB20_Msk     (0x1UL << CAN_F12R2_FB20_Pos)                   
#define CAN_F12R2_FB20         CAN_F12R2_FB20_Msk                              
#define CAN_F12R2_FB21_Pos     (21U)                                          
#define CAN_F12R2_FB21_Msk     (0x1UL << CAN_F12R2_FB21_Pos)                   
#define CAN_F12R2_FB21         CAN_F12R2_FB21_Msk                              
#define CAN_F12R2_FB22_Pos     (22U)                                          
#define CAN_F12R2_FB22_Msk     (0x1UL << CAN_F12R2_FB22_Pos)                   
#define CAN_F12R2_FB22         CAN_F12R2_FB22_Msk                              
#define CAN_F12R2_FB23_Pos     (23U)                                          
#define CAN_F12R2_FB23_Msk     (0x1UL << CAN_F12R2_FB23_Pos)                   
#define CAN_F12R2_FB23         CAN_F12R2_FB23_Msk                              
#define CAN_F12R2_FB24_Pos     (24U)                                          
#define CAN_F12R2_FB24_Msk     (0x1UL << CAN_F12R2_FB24_Pos)                   
#define CAN_F12R2_FB24         CAN_F12R2_FB24_Msk                              
#define CAN_F12R2_FB25_Pos     (25U)                                          
#define CAN_F12R2_FB25_Msk     (0x1UL << CAN_F12R2_FB25_Pos)                   
#define CAN_F12R2_FB25         CAN_F12R2_FB25_Msk                              
#define CAN_F12R2_FB26_Pos     (26U)                                          
#define CAN_F12R2_FB26_Msk     (0x1UL << CAN_F12R2_FB26_Pos)                   
#define CAN_F12R2_FB26         CAN_F12R2_FB26_Msk                              
#define CAN_F12R2_FB27_Pos     (27U)                                          
#define CAN_F12R2_FB27_Msk     (0x1UL << CAN_F12R2_FB27_Pos)                   
#define CAN_F12R2_FB27         CAN_F12R2_FB27_Msk                              
#define CAN_F12R2_FB28_Pos     (28U)                                          
#define CAN_F12R2_FB28_Msk     (0x1UL << CAN_F12R2_FB28_Pos)                   
#define CAN_F12R2_FB28         CAN_F12R2_FB28_Msk                              
#define CAN_F12R2_FB29_Pos     (29U)                                          
#define CAN_F12R2_FB29_Msk     (0x1UL << CAN_F12R2_FB29_Pos)                   
#define CAN_F12R2_FB29         CAN_F12R2_FB29_Msk                              
#define CAN_F12R2_FB30_Pos     (30U)                                          
#define CAN_F12R2_FB30_Msk     (0x1UL << CAN_F12R2_FB30_Pos)                   
#define CAN_F12R2_FB30         CAN_F12R2_FB30_Msk                              
#define CAN_F12R2_FB31_Pos     (31U)                                          
#define CAN_F12R2_FB31_Msk     (0x1UL << CAN_F12R2_FB31_Pos)                   
#define CAN_F12R2_FB31         CAN_F12R2_FB31_Msk                              

/*******************  Bit definition for CAN_F13R2 register  ******************/
#define CAN_F13R2_FB0_Pos      (0U)                                           
#define CAN_F13R2_FB0_Msk      (0x1UL << CAN_F13R2_FB0_Pos)                    
#define CAN_F13R2_FB0          CAN_F13R2_FB0_Msk                               
#define CAN_F13R2_FB1_Pos      (1U)                                           
#define CAN_F13R2_FB1_Msk      (0x1UL << CAN_F13R2_FB1_Pos)                    
#define CAN_F13R2_FB1          CAN_F13R2_FB1_Msk                               
#define CAN_F13R2_FB2_Pos      (2U)                                           
#define CAN_F13R2_FB2_Msk      (0x1UL << CAN_F13R2_FB2_Pos)                    
#define CAN_F13R2_FB2          CAN_F13R2_FB2_Msk                               
#define CAN_F13R2_FB3_Pos      (3U)                                           
#define CAN_F13R2_FB3_Msk      (0x1UL << CAN_F13R2_FB3_Pos)                    
#define CAN_F13R2_FB3          CAN_F13R2_FB3_Msk                               
#define CAN_F13R2_FB4_Pos      (4U)                                           
#define CAN_F13R2_FB4_Msk      (0x1UL << CAN_F13R2_FB4_Pos)                    
#define CAN_F13R2_FB4          CAN_F13R2_FB4_Msk                               
#define CAN_F13R2_FB5_Pos      (5U)                                           
#define CAN_F13R2_FB5_Msk      (0x1UL << CAN_F13R2_FB5_Pos)                    
#define CAN_F13R2_FB5          CAN_F13R2_FB5_Msk                               
#define CAN_F13R2_FB6_Pos      (6U)                                           
#define CAN_F13R2_FB6_Msk      (0x1UL << CAN_F13R2_FB6_Pos)                    
#define CAN_F13R2_FB6          CAN_F13R2_FB6_Msk                               
#define CAN_F13R2_FB7_Pos      (7U)                                           
#define CAN_F13R2_FB7_Msk      (0x1UL << CAN_F13R2_FB7_Pos)                    
#define CAN_F13R2_FB7          CAN_F13R2_FB7_Msk                               
#define CAN_F13R2_FB8_Pos      (8U)                                           
#define CAN_F13R2_FB8_Msk      (0x1UL << CAN_F13R2_FB8_Pos)                    
#define CAN_F13R2_FB8          CAN_F13R2_FB8_Msk                               
#define CAN_F13R2_FB9_Pos      (9U)                                           
#define CAN_F13R2_FB9_Msk      (0x1UL << CAN_F13R2_FB9_Pos)                    
#define CAN_F13R2_FB9          CAN_F13R2_FB9_Msk                               
#define CAN_F13R2_FB10_Pos     (10U)                                          
#define CAN_F13R2_FB10_Msk     (0x1UL << CAN_F13R2_FB10_Pos)                   
#define CAN_F13R2_FB10         CAN_F13R2_FB10_Msk                              
#define CAN_F13R2_FB11_Pos     (11U)                                          
#define CAN_F13R2_FB11_Msk     (0x1UL << CAN_F13R2_FB11_Pos)                   
#define CAN_F13R2_FB11         CAN_F13R2_FB11_Msk                              
#define CAN_F13R2_FB12_Pos     (12U)                                          
#define CAN_F13R2_FB12_Msk     (0x1UL << CAN_F13R2_FB12_Pos)                   
#define CAN_F13R2_FB12         CAN_F13R2_FB12_Msk                              
#define CAN_F13R2_FB13_Pos     (13U)                                          
#define CAN_F13R2_FB13_Msk     (0x1UL << CAN_F13R2_FB13_Pos)                   
#define CAN_F13R2_FB13         CAN_F13R2_FB13_Msk                              
#define CAN_F13R2_FB14_Pos     (14U)                                          
#define CAN_F13R2_FB14_Msk     (0x1UL << CAN_F13R2_FB14_Pos)                   
#define CAN_F13R2_FB14         CAN_F13R2_FB14_Msk                              
#define CAN_F13R2_FB15_Pos     (15U)                                          
#define CAN_F13R2_FB15_Msk     (0x1UL << CAN_F13R2_FB15_Pos)                   
#define CAN_F13R2_FB15         CAN_F13R2_FB15_Msk                              
#define CAN_F13R2_FB16_Pos     (16U)                                          
#define CAN_F13R2_FB16_Msk     (0x1UL << CAN_F13R2_FB16_Pos)                   
#define CAN_F13R2_FB16         CAN_F13R2_FB16_Msk                              
#define CAN_F13R2_FB17_Pos     (17U)                                          
#define CAN_F13R2_FB17_Msk     (0x1UL << CAN_F13R2_FB17_Pos)                   
#define CAN_F13R2_FB17         CAN_F13R2_FB17_Msk                              
#define CAN_F13R2_FB18_Pos     (18U)                                          
#define CAN_F13R2_FB18_Msk     (0x1UL << CAN_F13R2_FB18_Pos)                   
#define CAN_F13R2_FB18         CAN_F13R2_FB18_Msk                              
#define CAN_F13R2_FB19_Pos     (19U)                                          
#define CAN_F13R2_FB19_Msk     (0x1UL << CAN_F13R2_FB19_Pos)                   
#define CAN_F13R2_FB19         CAN_F13R2_FB19_Msk                              
#define CAN_F13R2_FB20_Pos     (20U)                                          
#define CAN_F13R2_FB20_Msk     (0x1UL << CAN_F13R2_FB20_Pos)                   
#define CAN_F13R2_FB20         CAN_F13R2_FB20_Msk                              
#define CAN_F13R2_FB21_Pos     (21U)                                          
#define CAN_F13R2_FB21_Msk     (0x1UL << CAN_F13R2_FB21_Pos)                   
#define CAN_F13R2_FB21         CAN_F13R2_FB21_Msk                              
#define CAN_F13R2_FB22_Pos     (22U)                                          
#define CAN_F13R2_FB22_Msk     (0x1UL << CAN_F13R2_FB22_Pos)                   
#define CAN_F13R2_FB22         CAN_F13R2_FB22_Msk                              
#define CAN_F13R2_FB23_Pos     (23U)                                          
#define CAN_F13R2_FB23_Msk     (0x1UL << CAN_F13R2_FB23_Pos)                   
#define CAN_F13R2_FB23         CAN_F13R2_FB23_Msk                              
#define CAN_F13R2_FB24_Pos     (24U)                                          
#define CAN_F13R2_FB24_Msk     (0x1UL << CAN_F13R2_FB24_Pos)                   
#define CAN_F13R2_FB24         CAN_F13R2_FB24_Msk                              
#define CAN_F13R2_FB25_Pos     (25U)                                          
#define CAN_F13R2_FB25_Msk     (0x1UL << CAN_F13R2_FB25_Pos)                   
#define CAN_F13R2_FB25         CAN_F13R2_FB25_Msk                              
#define CAN_F13R2_FB26_Pos     (26U)                                          
#define CAN_F13R2_FB26_Msk     (0x1UL << CAN_F13R2_FB26_Pos)                   
#define CAN_F13R2_FB26         CAN_F13R2_FB26_Msk                              
#define CAN_F13R2_FB27_Pos     (27U)                                          
#define CAN_F13R2_FB27_Msk     (0x1UL << CAN_F13R2_FB27_Pos)                   
#define CAN_F13R2_FB27         CAN_F13R2_FB27_Msk                              
#define CAN_F13R2_FB28_Pos     (28U)                                          
#define CAN_F13R2_FB28_Msk     (0x1UL << CAN_F13R2_FB28_Pos)                   
#define CAN_F13R2_FB28         CAN_F13R2_FB28_Msk                              
#define CAN_F13R2_FB29_Pos     (29U)                                          
#define CAN_F13R2_FB29_Msk     (0x1UL << CAN_F13R2_FB29_Pos)                   
#define CAN_F13R2_FB29         CAN_F13R2_FB29_Msk                              
#define CAN_F13R2_FB30_Pos     (30U)                                          
#define CAN_F13R2_FB30_Msk     (0x1UL << CAN_F13R2_FB30_Pos)                   
#define CAN_F13R2_FB30         CAN_F13R2_FB30_Msk                              
#define CAN_F13R2_FB31_Pos     (31U)                                          
#define CAN_F13R2_FB31_Msk     (0x1UL << CAN_F13R2_FB31_Pos)                   
#define CAN_F13R2_FB31         CAN_F13R2_FB31_Msk          

#endif  /* HEADER_FLEXCAN_H_ */
