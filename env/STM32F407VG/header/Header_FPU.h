#if !defined(HEADER_FPU_H_)  
#define HEADER_FPU_H_

#include "Header.h"

/**
*  Structure type to access the Floating Point Unit (FPU).
 */
typedef struct
{
        uint32_t RESERVED0[1U];
  __IO uint32_t FPCCR;                  /*   Floating-Point Context Control Register */
  __IO uint32_t FPCAR;                  /*   Floating-Point Context Address Register */
  __IO uint32_t FPDSCR;                 /*   Floating-Point Default Status Control Register */
  __I  uint32_t MVFR0;                  /*   Media and FP Feature Register 0 */
  __I  uint32_t MVFR1;                  /*   Media and FP Feature Register 1 */
} FPU_Type;
#define FPU                 ((FPU_Type       *)     FPU_BASE      )

/* Floating-Point Context Control Register Definitions */
#define FPU_FPCCR_ASPEN_Pos                31U                                           
#define FPU_FPCCR_ASPEN_Msk                (1UL << FPU_FPCCR_ASPEN_Pos)                  

#define FPU_FPCCR_LSPEN_Pos                30U                                           
#define FPU_FPCCR_LSPEN_Msk                (1UL << FPU_FPCCR_LSPEN_Pos)                  

#define FPU_FPCCR_MONRDY_Pos                8U                                           
#define FPU_FPCCR_MONRDY_Msk               (1UL << FPU_FPCCR_MONRDY_Pos)                 

#define FPU_FPCCR_BFRDY_Pos                 6U                                           
#define FPU_FPCCR_BFRDY_Msk                (1UL << FPU_FPCCR_BFRDY_Pos)                  

#define FPU_FPCCR_MMRDY_Pos                 5U                                           
#define FPU_FPCCR_MMRDY_Msk                (1UL << FPU_FPCCR_MMRDY_Pos)                  

#define FPU_FPCCR_HFRDY_Pos                 4U                                           
#define FPU_FPCCR_HFRDY_Msk                (1UL << FPU_FPCCR_HFRDY_Pos)                  

#define FPU_FPCCR_THREAD_Pos                3U                                           
#define FPU_FPCCR_THREAD_Msk               (1UL << FPU_FPCCR_THREAD_Pos)                 

#define FPU_FPCCR_USER_Pos                  1U                                           
#define FPU_FPCCR_USER_Msk                 (1UL << FPU_FPCCR_USER_Pos)                   

#define FPU_FPCCR_LSPACT_Pos                0U                                          
#define FPU_FPCCR_LSPACT_Msk               (1UL /* FPU_FPCCR_LSPACT_Pos*/)            

/* Floating-Point Context Address Register Definitions */
#define FPU_FPCAR_ADDRESS_Pos               3U                                           
#define FPU_FPCAR_ADDRESS_Msk              (0x1FFFFFFFUL << FPU_FPCAR_ADDRESS_Pos)       

/* Floating-Point Default Status Control Register Definitions */
#define FPU_FPDSCR_AHP_Pos                 26U                                           
#define FPU_FPDSCR_AHP_Msk                 (1UL << FPU_FPDSCR_AHP_Pos)                   

#define FPU_FPDSCR_DN_Pos                  25U                                           
#define FPU_FPDSCR_DN_Msk                  (1UL << FPU_FPDSCR_DN_Pos)                    

#define FPU_FPDSCR_FZ_Pos                  24U                                           
#define FPU_FPDSCR_FZ_Msk                  (1UL << FPU_FPDSCR_FZ_Pos)                    

#define FPU_FPDSCR_RMode_Pos               22U                                           
#define FPU_FPDSCR_RMode_Msk               (3UL << FPU_FPDSCR_RMode_Pos)                 

/* Media and FP Feature Register 0 Definitions */
#define FPU_MVFR0_FP_rounding_modes_Pos    28U                                           
#define FPU_MVFR0_FP_rounding_modes_Msk    (0xFUL << FPU_MVFR0_FP_rounding_modes_Pos)    

#define FPU_MVFR0_Short_vectors_Pos        24U                                           
#define FPU_MVFR0_Short_vectors_Msk        (0xFUL << FPU_MVFR0_Short_vectors_Pos)        

#define FPU_MVFR0_Square_root_Pos          20U                                           
#define FPU_MVFR0_Square_root_Msk          (0xFUL << FPU_MVFR0_Square_root_Pos)          

#define FPU_MVFR0_Divide_Pos               16U                                           
#define FPU_MVFR0_Divide_Msk               (0xFUL << FPU_MVFR0_Divide_Pos)               

#define FPU_MVFR0_FP_excep_trapping_Pos    12U                                           
#define FPU_MVFR0_FP_excep_trapping_Msk    (0xFUL << FPU_MVFR0_FP_excep_trapping_Pos)    

#define FPU_MVFR0_Double_precision_Pos      8U                                           
#define FPU_MVFR0_Double_precision_Msk     (0xFUL << FPU_MVFR0_Double_precision_Pos)     

#define FPU_MVFR0_Single_precision_Pos      4U                                           
#define FPU_MVFR0_Single_precision_Msk     (0xFUL << FPU_MVFR0_Single_precision_Pos)     

#define FPU_MVFR0_A_SIMD_registers_Pos      0U                                           
#define FPU_MVFR0_A_SIMD_registers_Msk     (0xFUL /* FPU_MVFR0_A_SIMD_registers_Pos*/) 

/* Media and FP Feature Register 1 Definitions */
#define FPU_MVFR1_FP_fused_MAC_Pos         28U                                           
#define FPU_MVFR1_FP_fused_MAC_Msk         (0xFUL << FPU_MVFR1_FP_fused_MAC_Pos)         

#define FPU_MVFR1_FP_HPFP_Pos              24U                                           
#define FPU_MVFR1_FP_HPFP_Msk              (0xFUL << FPU_MVFR1_FP_HPFP_Pos)              

#define FPU_MVFR1_D_NaN_mode_Pos            4U                                           
#define FPU_MVFR1_D_NaN_mode_Msk           (0xFUL << FPU_MVFR1_D_NaN_mode_Pos)           

#define FPU_MVFR1_FtZ_mode_Pos              0U                                           
#define FPU_MVFR1_FtZ_mode_Msk             (0xFUL /* FPU_MVFR1_FtZ_mode_Pos*/)   

#endif  /* HEADER_FPU_H_ */
