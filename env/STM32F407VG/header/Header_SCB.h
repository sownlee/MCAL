#ifndef HEADER_SCB_H_
#define HEADER_SCB_H_

#include "Header.h"

typedef struct
{
  __I  uint32_t CPUID;                 
  __O uint32_t ICSR;                  
  __O uint32_t VTOR;                  
  __O uint32_t AIRCR;                 
  __O uint32_t SCR;                   
  __O uint32_t CCR;                   
  __O uint8_t  SHP[12U];              
  __O uint32_t SHCSR;                 
  __O uint32_t CFSR;                  
  __O uint32_t HFSR;                  
  __O uint32_t DFSR;                  
  __O uint32_t MMFAR;                 
  __O uint32_t BFAR;                  
  __O uint32_t AFSR;                  
  __O  uint32_t PFR[2U];               
  __O  uint32_t DFR;                   
  __O  uint32_t ADR;                   
  __O  uint32_t MMFR[4U];              
  __O  uint32_t ISAR[5U];              
      uint32_t RESERVED0[5U];
  __O uint32_t CPACR;                 
} SCB_Type;
#define SCB                 ((SCB_Type*)SCB_BASE)  

/* SCB CPUID Register Definitions */
#define SCB_CPUID_IMPLEMENTER_Pos          24U                                          
#define SCB_CPUID_IMPLEMENTER_Msk          (0xFFUL << SCB_CPUID_IMPLEMENTER_Pos)        

#define SCB_CPUID_VARIANT_Pos              20U                                          
#define SCB_CPUID_VARIANT_Msk              (0xFUL << SCB_CPUID_VARIANT_Pos)             

#define SCB_CPUID_ARCHITECTURE_Pos         16U                                          
#define SCB_CPUID_ARCHITECTURE_Msk         (0xFUL << SCB_CPUID_ARCHITECTURE_Pos)        

#define SCB_CPUID_PARTNO_Pos                4U                                          
#define SCB_CPUID_PARTNO_Msk               (0xFFFUL << SCB_CPUID_PARTNO_Pos)            

#define SCB_CPUID_REVISION_Pos              0U                                          
#define SCB_CPUID_REVISION_Msk             (0xFUL /* SCB_CPUID_REVISION_Pos*/)        

/* SCB Interrupt Control State Register Definitions */
#define SCB_ICSR_NMIPENDSET_Pos            31U                                          
#define SCB_ICSR_NMIPENDSET_Msk            (1UL << SCB_ICSR_NMIPENDSET_Pos)             

#define SCB_ICSR_PENDSVSET_Pos             28U                                          
#define SCB_ICSR_PENDSVSET_Msk             (1UL << SCB_ICSR_PENDSVSET_Pos)              

#define SCB_ICSR_PENDSVCLR_Pos             27U                                          
#define SCB_ICSR_PENDSVCLR_Msk             (1UL << SCB_ICSR_PENDSVCLR_Pos)              

#define SCB_ICSR_PENDSTSET_Pos             26U                                          
#define SCB_ICSR_PENDSTSET_Msk             (1UL << SCB_ICSR_PENDSTSET_Pos)              

#define SCB_ICSR_PENDSTCLR_Pos             25U                                          
#define SCB_ICSR_PENDSTCLR_Msk             (1UL << SCB_ICSR_PENDSTCLR_Pos)              

#define SCB_ICSR_ISRPREEMPT_Pos            23U                                          
#define SCB_ICSR_ISRPREEMPT_Msk            (1UL << SCB_ICSR_ISRPREEMPT_Pos)             

#define SCB_ICSR_ISRPENDING_Pos            22U                                          
#define SCB_ICSR_ISRPENDING_Msk            (1UL << SCB_ICSR_ISRPENDING_Pos)             

#define SCB_ICSR_VECTPENDING_Pos           12U                                          
#define SCB_ICSR_VECTPENDING_Msk           (0x1FFUL << SCB_ICSR_VECTPENDING_Pos)        

#define SCB_ICSR_RETTOBASE_Pos             11U                                          
#define SCB_ICSR_RETTOBASE_Msk             (1UL << SCB_ICSR_RETTOBASE_Pos)              

#define SCB_ICSR_VECTACTIVE_Pos             0U                                          
#define SCB_ICSR_VECTACTIVE_Msk            (0x1FFUL /* SCB_ICSR_VECTACTIVE_Pos*/)     

/* SCB Vector Table Offset Register Definitions */
#define SCB_VTOR_TBLOFF_Pos                 7U                                          
#define SCB_VTOR_TBLOFF_Msk                (0x1FFFFFFUL << SCB_VTOR_TBLOFF_Pos)         

/* SCB Application Interrupt and Reset Control Register Definitions */
#define SCB_AIRCR_VECTKEY_Pos              16U                                          
#define SCB_AIRCR_VECTKEY_Msk              (0xFFFFUL << SCB_AIRCR_VECTKEY_Pos)          

#define SCB_AIRCR_VECTKEYSTAT_Pos          16U                                          
#define SCB_AIRCR_VECTKEYSTAT_Msk          (0xFFFFUL << SCB_AIRCR_VECTKEYSTAT_Pos)      

#define SCB_AIRCR_ENDIANESS_Pos            15U                                          
#define SCB_AIRCR_ENDIANESS_Msk            (1UL << SCB_AIRCR_ENDIANESS_Pos)             

#define SCB_AIRCR_PRIGROUP_Pos              8U                                          
#define SCB_AIRCR_PRIGROUP_Msk             (7UL << SCB_AIRCR_PRIGROUP_Pos)              

#define SCB_AIRCR_SYSRESETREQ_Pos           2U                                          
#define SCB_AIRCR_SYSRESETREQ_Msk          (1UL << SCB_AIRCR_SYSRESETREQ_Pos)           

#define SCB_AIRCR_VECTCLRACTIVE_Pos         1U                                          
#define SCB_AIRCR_VECTCLRACTIVE_Msk        (1UL << SCB_AIRCR_VECTCLRACTIVE_Pos)         

#define SCB_AIRCR_VECTRESET_Pos             0U                                          
#define SCB_AIRCR_VECTRESET_Msk            (1UL /* SCB_AIRCR_VECTRESET_Pos*/)         

/* SCB System Control Register Definitions */
#define SCB_SCR_SEVONPEND_Pos               4U                                          
#define SCB_SCR_SEVONPEND_Msk              (1UL << SCB_SCR_SEVONPEND_Pos)               

#define SCB_SCR_SLEEPDEEP_Pos               2U                                          
#define SCB_SCR_SLEEPDEEP_Msk              (1UL << SCB_SCR_SLEEPDEEP_Pos)               

#define SCB_SCR_SLEEPONEXIT_Pos             1U                                          
#define SCB_SCR_SLEEPONEXIT_Msk            (1UL << SCB_SCR_SLEEPONEXIT_Pos)             

/* SCB Configuration Control Register Definitions */
#define SCB_CCR_STKALIGN_Pos                9U                                          
#define SCB_CCR_STKALIGN_Msk               (1UL << SCB_CCR_STKALIGN_Pos)                

#define SCB_CCR_BFHFNMIGN_Pos               8U                                          
#define SCB_CCR_BFHFNMIGN_Msk              (1UL << SCB_CCR_BFHFNMIGN_Pos)               

#define SCB_CCR_DIV_0_TRP_Pos               4U                                          
#define SCB_CCR_DIV_0_TRP_Msk              (1UL << SCB_CCR_DIV_0_TRP_Pos)               

#define SCB_CCR_UNALIGN_TRP_Pos             3U                                          
#define SCB_CCR_UNALIGN_TRP_Msk            (1UL << SCB_CCR_UNALIGN_TRP_Pos)             

#define SCB_CCR_USERSETMPEND_Pos            1U                                          
#define SCB_CCR_USERSETMPEND_Msk           (1UL << SCB_CCR_USERSETMPEND_Pos)            

#define SCB_CCR_NONBASETHRDENA_Pos          0U                                          
#define SCB_CCR_NONBASETHRDENA_Msk         (1UL /* SCB_CCR_NONBASETHRDENA_Pos*/)      

/* SCB System Handler Control and State Register Definitions */
#define SCB_SHCSR_USGFAULTENA_Pos          18U                                          
#define SCB_SHCSR_USGFAULTENA_Msk          (1UL << SCB_SHCSR_USGFAULTENA_Pos)           

#define SCB_SHCSR_BUSFAULTENA_Pos          17U                                          
#define SCB_SHCSR_BUSFAULTENA_Msk          (1UL << SCB_SHCSR_BUSFAULTENA_Pos)           

#define SCB_SHCSR_MEMFAULTENA_Pos          16U                                          
#define SCB_SHCSR_MEMFAULTENA_Msk          (1UL << SCB_SHCSR_MEMFAULTENA_Pos)           

#define SCB_SHCSR_SVCALLPENDED_Pos         15U                                          
#define SCB_SHCSR_SVCALLPENDED_Msk         (1UL << SCB_SHCSR_SVCALLPENDED_Pos)          

#define SCB_SHCSR_BUSFAULTPENDED_Pos       14U                                          
#define SCB_SHCSR_BUSFAULTPENDED_Msk       (1UL << SCB_SHCSR_BUSFAULTPENDED_Pos)        

#define SCB_SHCSR_MEMFAULTPENDED_Pos       13U                                          
#define SCB_SHCSR_MEMFAULTPENDED_Msk       (1UL << SCB_SHCSR_MEMFAULTPENDED_Pos)        

#define SCB_SHCSR_USGFAULTPENDED_Pos       12U                                          
#define SCB_SHCSR_USGFAULTPENDED_Msk       (1UL << SCB_SHCSR_USGFAULTPENDED_Pos)        

#define SCB_SHCSR_SYSTICKACT_Pos           11U                                          
#define SCB_SHCSR_SYSTICKACT_Msk           (1UL << SCB_SHCSR_SYSTICKACT_Pos)            

#define SCB_SHCSR_PENDSVACT_Pos            10U                                          
#define SCB_SHCSR_PENDSVACT_Msk            (1UL << SCB_SHCSR_PENDSVACT_Pos)             

#define SCB_SHCSR_MONITORACT_Pos            8U                                          
#define SCB_SHCSR_MONITORACT_Msk           (1UL << SCB_SHCSR_MONITORACT_Pos)            

#define SCB_SHCSR_SVCALLACT_Pos             7U                                          
#define SCB_SHCSR_SVCALLACT_Msk            (1UL << SCB_SHCSR_SVCALLACT_Pos)             

#define SCB_SHCSR_USGFAULTACT_Pos           3U                                          
#define SCB_SHCSR_USGFAULTACT_Msk          (1UL << SCB_SHCSR_USGFAULTACT_Pos)           

#define SCB_SHCSR_BUSFAULTACT_Pos           1U                                          
#define SCB_SHCSR_BUSFAULTACT_Msk          (1UL << SCB_SHCSR_BUSFAULTACT_Pos)           

#define SCB_SHCSR_MEMFAULTACT_Pos           0U                                          
#define SCB_SHCSR_MEMFAULTACT_Msk          (1UL /* SCB_SHCSR_MEMFAULTACT_Pos*/)       

/* SCB Configurable Fault Status Register Definitions */
#define SCB_CFSR_USGFAULTSR_Pos            16U                                        
#define SCB_CFSR_USGFAULTSR_Msk            (0xFFFFUL << SCB_CFSR_USGFAULTSR_Pos)      

#define SCB_CFSR_BUSFAULTSR_Pos             8U                                        
#define SCB_CFSR_BUSFAULTSR_Msk            (0xFFUL << SCB_CFSR_BUSFAULTSR_Pos)        

#define SCB_CFSR_MEMFAULTSR_Pos             0U                                        
#define SCB_CFSR_MEMFAULTSR_Msk            (0xFFUL /* SCB_CFSR_MEMFAULTSR_Pos*/)    

/* MemManage Fault Status Register (part of SCB Configurable Fault Status Register) */
#define SCB_CFSR_MMARVALID_Pos             (SCB_SHCSR_MEMFAULTACT_Pos + 7U)             
#define SCB_CFSR_MMARVALID_Msk             (1UL << SCB_CFSR_MMARVALID_Pos)              

#define SCB_CFSR_MLSPERR_Pos               (SCB_SHCSR_MEMFAULTACT_Pos + 5U)             
#define SCB_CFSR_MLSPERR_Msk               (1UL << SCB_CFSR_MLSPERR_Pos)                

#define SCB_CFSR_MSTKERR_Pos               (SCB_SHCSR_MEMFAULTACT_Pos + 4U)             
#define SCB_CFSR_MSTKERR_Msk               (1UL << SCB_CFSR_MSTKERR_Pos)                

#define SCB_CFSR_MUNSTKERR_Pos             (SCB_SHCSR_MEMFAULTACT_Pos + 3U)             
#define SCB_CFSR_MUNSTKERR_Msk             (1UL << SCB_CFSR_MUNSTKERR_Pos)              

#define SCB_CFSR_DACCVIOL_Pos              (SCB_SHCSR_MEMFAULTACT_Pos + 1U)             
#define SCB_CFSR_DACCVIOL_Msk              (1UL << SCB_CFSR_DACCVIOL_Pos)               

#define SCB_CFSR_IACCVIOL_Pos              (SCB_SHCSR_MEMFAULTACT_Pos + 0U)             
#define SCB_CFSR_IACCVIOL_Msk              (1UL /* SCB_CFSR_IACCVIOL_Pos*/)           

/* BusFault Status Register (part of SCB Configurable Fault Status Register) */
#define SCB_CFSR_BFARVALID_Pos            (SCB_CFSR_BUSFAULTSR_Pos + 7U)                
#define SCB_CFSR_BFARVALID_Msk            (1UL << SCB_CFSR_BFARVALID_Pos)               

#define SCB_CFSR_LSPERR_Pos               (SCB_CFSR_BUSFAULTSR_Pos + 5U)                
#define SCB_CFSR_LSPERR_Msk               (1UL << SCB_CFSR_LSPERR_Pos)                  

#define SCB_CFSR_STKERR_Pos               (SCB_CFSR_BUSFAULTSR_Pos + 4U)                
#define SCB_CFSR_STKERR_Msk               (1UL << SCB_CFSR_STKERR_Pos)                  

#define SCB_CFSR_UNSTKERR_Pos             (SCB_CFSR_BUSFAULTSR_Pos + 3U)                
#define SCB_CFSR_UNSTKERR_Msk             (1UL << SCB_CFSR_UNSTKERR_Pos)                

#define SCB_CFSR_IMPRECISERR_Pos          (SCB_CFSR_BUSFAULTSR_Pos + 2U)                
#define SCB_CFSR_IMPRECISERR_Msk          (1UL << SCB_CFSR_IMPRECISERR_Pos)             

#define SCB_CFSR_PRECISERR_Pos            (SCB_CFSR_BUSFAULTSR_Pos + 1U)                
#define SCB_CFSR_PRECISERR_Msk            (1UL << SCB_CFSR_PRECISERR_Pos)               

#define SCB_CFSR_IBUSERR_Pos              (SCB_CFSR_BUSFAULTSR_Pos + 0U)                
#define SCB_CFSR_IBUSERR_Msk              (1UL << SCB_CFSR_IBUSERR_Pos)                 

/* UsageFault Status Register (part of SCB Configurable Fault Status Register) */
#define SCB_CFSR_DIVBYZERO_Pos            (SCB_CFSR_USGFAULTSR_Pos + 9U)                
#define SCB_CFSR_DIVBYZERO_Msk            (1UL << SCB_CFSR_DIVBYZERO_Pos)               

#define SCB_CFSR_UNALIGNED_Pos            (SCB_CFSR_USGFAULTSR_Pos + 8U)                
#define SCB_CFSR_UNALIGNED_Msk            (1UL << SCB_CFSR_UNALIGNED_Pos)               

#define SCB_CFSR_NOCP_Pos                 (SCB_CFSR_USGFAULTSR_Pos + 3U)                
#define SCB_CFSR_NOCP_Msk                 (1UL << SCB_CFSR_NOCP_Pos)                    

#define SCB_CFSR_INVPC_Pos                (SCB_CFSR_USGFAULTSR_Pos + 2U)                
#define SCB_CFSR_INVPC_Msk                (1UL << SCB_CFSR_INVPC_Pos)                   

#define SCB_CFSR_INVSTATE_Pos             (SCB_CFSR_USGFAULTSR_Pos + 1U)                
#define SCB_CFSR_INVSTATE_Msk             (1UL << SCB_CFSR_INVSTATE_Pos)                

#define SCB_CFSR_UNDEFINSTR_Pos           (SCB_CFSR_USGFAULTSR_Pos + 0U)                
#define SCB_CFSR_UNDEFINSTR_Msk           (1UL << SCB_CFSR_UNDEFINSTR_Pos)              

/* SCB Hard Fault Status Register Definitions */
#define SCB_HFSR_DEBUGEVT_Pos              31U                                          
#define SCB_HFSR_DEBUGEVT_Msk              (1UL << SCB_HFSR_DEBUGEVT_Pos)               

#define SCB_HFSR_FORCED_Pos                30U                                          
#define SCB_HFSR_FORCED_Msk                (1UL << SCB_HFSR_FORCED_Pos)                 

#define SCB_HFSR_VECTTBL_Pos                1U                                          
#define SCB_HFSR_VECTTBL_Msk               (1UL << SCB_HFSR_VECTTBL_Pos)                

/* SCB Debug Fault Status Register Definitions */
#define SCB_DFSR_EXTERNAL_Pos               4U                                          
#define SCB_DFSR_EXTERNAL_Msk              (1UL << SCB_DFSR_EXTERNAL_Pos)               

#define SCB_DFSR_VCATCH_Pos                 3U                                          
#define SCB_DFSR_VCATCH_Msk                (1UL << SCB_DFSR_VCATCH_Pos)                 

#define SCB_DFSR_DWTTRAP_Pos                2U                                          
#define SCB_DFSR_DWTTRAP_Msk               (1UL << SCB_DFSR_DWTTRAP_Pos)                

#define SCB_DFSR_BKPT_Pos                   1U                                          
#define SCB_DFSR_BKPT_Msk                  (1UL << SCB_DFSR_BKPT_Pos)                   

#define SCB_DFSR_HALTED_Pos                 0U                                          
#define SCB_DFSR_HALTED_Msk                (1UL /* SCB_DFSR_HALTED_Pos*/)  

#endif /* HEADER_SCB_H_ */