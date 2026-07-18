#if !defined(HEADER_PSR_H_)  
#define HEADER_PSR_H_

#include "Header.h"

/**
*  Union type to access the Application Program Status Register (APSR).
*/
typedef union
{
  struct
  {
    uint32_t _reserved0:16;              /* bit:  0..15  Reserved */
    uint32_t GE:4;                       /* bit: 16..19  Greater than or Equal flags */
    uint32_t _reserved1:7;               /* bit: 20..26  Reserved */
    uint32_t Q:1;                        /* bit:     27  Saturation condition flag */
    uint32_t V:1;                        /* bit:     28  Overflow condition code flag */
    uint32_t C:1;                        /* bit:     29  Carry condition code flag */
    uint32_t Z:1;                        /* bit:     30  Zero condition code flag */
    uint32_t N:1;                        /* bit:     31  Negative condition code flag */
  } b;                                   /* Structure used for bit  access */
  uint32_t w;                            /* Type      used for word access */
} APSR_Type;
/* APSR Register Definitions */
#define APSR_N_Pos                         31U                                          
#define APSR_N_Msk                         (1UL << APSR_N_Pos)                          

#define APSR_Z_Pos                         30U                                          
#define APSR_Z_Msk                         (1UL << APSR_Z_Pos)                          

#define APSR_C_Pos                         29U                                          
#define APSR_C_Msk                         (1UL << APSR_C_Pos)                          

#define APSR_V_Pos                         28U                                          
#define APSR_V_Msk                         (1UL << APSR_V_Pos)                          

#define APSR_Q_Pos                         27U                                          
#define APSR_Q_Msk                         (1UL << APSR_Q_Pos)                          

#define APSR_GE_Pos                        16U                                          
#define APSR_GE_Msk                        (0xFUL << APSR_GE_Pos)                       

/**
*  Union type to access the Interrupt Program Status Register (IPSR).
 */
typedef union
{
  struct
  {
    uint32_t ISR:9;                      /* bit:  0.. 8  Exception number */
    uint32_t _reserved0:23;              /* bit:  9..31  Reserved */
  } b;                                   /* Structure used for bit  access */
  uint32_t w;                            /* Type      used for word access */
} IPSR_Type;

/* IPSR Register Definitions */
#define IPSR_ISR_Pos                        0U                                           
#define IPSR_ISR_Msk                       (0x1FFUL /* IPSR_ISR_Pos*/)    

/**
*  Union type to access the Special-Purpose Program Status Registers (xPSR).
 */
typedef union
{
  struct
  {
    uint32_t ISR:9;                      /* bit:  0.. 8  Exception number */
    uint32_t _reserved0:1;               /* bit:      9  Reserved */
    uint32_t ICI_IT_1:6;                 /* bit: 10..15  ICI/IT part 1 */
    uint32_t GE:4;                       /* bit: 16..19  Greater than or Equal flags */
    uint32_t _reserved1:4;               /* bit: 20..23  Reserved */
    uint32_t T:1;                        /* bit:     24  Thumb bit */
    uint32_t ICI_IT_2:2;                 /* bit: 25..26  ICI/IT part 2 */
    uint32_t Q:1;                        /* bit:     27  Saturation condition flag */
    uint32_t V:1;                        /* bit:     28  Overflow condition code flag */
    uint32_t C:1;                        /* bit:     29  Carry condition code flag */
    uint32_t Z:1;                        /* bit:     30  Zero condition code flag */
    uint32_t N:1;                        /* bit:     31  Negative condition code flag */
  } b;                                   /* Structure used for bit  access */
  uint32_t w;                            /* Type      used for word access */
} xPSR_Type;
/* xPSR Register Definitions */
#define xPSR_N_Pos                         31U                                         
#define xPSR_N_Msk                         (1UL << xPSR_N_Pos)                         

#define xPSR_Z_Pos                         30U                                         
#define xPSR_Z_Msk                         (1UL << xPSR_Z_Pos)                         

#define xPSR_C_Pos                         29U                                         
#define xPSR_C_Msk                         (1UL << xPSR_C_Pos)                         

#define xPSR_V_Pos                         28U                                         
#define xPSR_V_Msk                         (1UL << xPSR_V_Pos)                         

#define xPSR_Q_Pos                         27U                                         
#define xPSR_Q_Msk                         (1UL << xPSR_Q_Pos)                         

#define xPSR_ICI_IT_2_Pos                  25U                                         
#define xPSR_ICI_IT_2_Msk                  (3UL << xPSR_ICI_IT_2_Pos)                  

#define xPSR_T_Pos                         24U                                         
#define xPSR_T_Msk                         (1UL << xPSR_T_Pos)                         

#define xPSR_GE_Pos                        16U                                         
#define xPSR_GE_Msk                        (0xFUL << xPSR_GE_Pos)                      

#define xPSR_ICI_IT_1_Pos                  10U                                         
#define xPSR_ICI_IT_1_Msk                  (0x3FUL << xPSR_ICI_IT_1_Pos)               

#define xPSR_ISR_Pos                        0U                                          
#define xPSR_ISR_Msk                       (0x1FFUL /* xPSR_ISR_Pos*/)   

/**
*  Union type to access the Control Registers (CONTROL).
 */
typedef union
{
  struct
  {
    uint32_t nPRIV:1;                    /* bit:      0  Execution privilege in Thread mode */
    uint32_t SPSEL:1;                    /* bit:      1  Stack to be used */
    uint32_t FPCA:1;                     /* bit:      2  FP extension active flag */
    uint32_t _reserved0:29;              /* bit:  3..31  Reserved */
  } b;                                   /* Structure used for bit  access */
  uint32_t w;                            /* Type      used for word access */
} CONTROL_Type;

/* CONTROL Register Definitions */
#define CONTROL_FPCA_Pos                    2U                                          
#define CONTROL_FPCA_Msk                   (1UL << CONTROL_FPCA_Pos)                    

#define CONTROL_SPSEL_Pos                   1U                                          
#define CONTROL_SPSEL_Msk                  (1UL << CONTROL_SPSEL_Pos)                   

#define CONTROL_nPRIV_Pos                   0U                                          
#define CONTROL_nPRIV_Msk                  (1UL /* CONTROL_nPRIV_Pos*/)  

#endif  /* HEADER_PSR_H_ */
