#if !defined(HEADER_MPU_H_)  
#define HEADER_MPU_H_

#include "Header.h"

/**
*  Structure type to access the Memory Protection Unit (MPU).
 */
typedef struct
{
  __I  uint32_t TYPE;                  
  __IO uint32_t CTRL;                  
  __IO uint32_t RNR;                   
  __IO uint32_t RBAR;                  
  __IO uint32_t RASR;                  
  __IO uint32_t RBAR_A1;               
  __IO uint32_t RASR_A1;               
  __IO uint32_t RBAR_A2;               
  __IO uint32_t RASR_A2;               
  __IO uint32_t RBAR_A3;               
  __IO uint32_t RASR_A3;               
} MPU_Type;
#define MPU               ((MPU_Type       *)     MPU_BASE      )

#define MPU_TYPE_RALIASES                  4U

/* MPU Type Register Definitions */
#define MPU_TYPE_IREGION_Pos               16U                                            
#define MPU_TYPE_IREGION_Msk               (0xFFUL << MPU_TYPE_IREGION_Pos)               

#define MPU_TYPE_DREGION_Pos                8U                                            
#define MPU_TYPE_DREGION_Msk               (0xFFUL << MPU_TYPE_DREGION_Pos)               

#define MPU_TYPE_SEPARATE_Pos               0U                                            
#define MPU_TYPE_SEPARATE_Msk              (1UL /* MPU_TYPE_SEPARATE_Pos*/)             

/* MPU Control Register Definitions */
#define MPU_CTRL_PRIVDEFENA_Pos             2U                                            
#define MPU_CTRL_PRIVDEFENA_Msk            (1UL << MPU_CTRL_PRIVDEFENA_Pos)               

#define MPU_CTRL_HFNMIENA_Pos               1U                                            
#define MPU_CTRL_HFNMIENA_Msk              (1UL << MPU_CTRL_HFNMIENA_Pos)                 

#define MPU_CTRL_ENABLE_Pos                 0U                                            
#define MPU_CTRL_ENABLE_Msk                (1UL /* MPU_CTRL_ENABLE_Pos*/)               

/* MPU Region Number Register Definitions */
#define MPU_RNR_REGION_Pos                  0U                                            
#define MPU_RNR_REGION_Msk                 (0xFFUL /* MPU_RNR_REGION_Pos*/)             

/* MPU Region Base Address Register Definitions */
#define MPU_RBAR_ADDR_Pos                   5U                                            
#define MPU_RBAR_ADDR_Msk                  (0x7FFFFFFUL << MPU_RBAR_ADDR_Pos)             

#define MPU_RBAR_VALID_Pos                  4U                                            
#define MPU_RBAR_VALID_Msk                 (1UL << MPU_RBAR_VALID_Pos)                    

#define MPU_RBAR_REGION_Pos                 0U                                            
#define MPU_RBAR_REGION_Msk                (0xFUL /* MPU_RBAR_REGION_Pos*/)             

/* MPU Region Attribute and Size Register Definitions */
#define MPU_RASR_ATTRS_Pos                 16U                                            
#define MPU_RASR_ATTRS_Msk                 (0xFFFFUL << MPU_RASR_ATTRS_Pos)               

#define MPU_RASR_XN_Pos                    28U                                            
#define MPU_RASR_XN_Msk                    (1UL << MPU_RASR_XN_Pos)                       

#define MPU_RASR_AP_Pos                    24U                                            
#define MPU_RASR_AP_Msk                    (0x7UL << MPU_RASR_AP_Pos)                     

#define MPU_RASR_TEX_Pos                   19U                                            
#define MPU_RASR_TEX_Msk                   (0x7UL << MPU_RASR_TEX_Pos)                    

#define MPU_RASR_S_Pos                     18U                                            
#define MPU_RASR_S_Msk                     (1UL << MPU_RASR_S_Pos)                        

#define MPU_RASR_C_Pos                     17U                                            
#define MPU_RASR_C_Msk                     (1UL << MPU_RASR_C_Pos)                        

#define MPU_RASR_B_Pos                     16U                                            
#define MPU_RASR_B_Msk                     (1UL << MPU_RASR_B_Pos)                        

#define MPU_RASR_SRD_Pos                    8U                                            
#define MPU_RASR_SRD_Msk                   (0xFFUL << MPU_RASR_SRD_Pos)                   

#define MPU_RASR_SIZE_Pos                   1U                                            
#define MPU_RASR_SIZE_Msk                  (0x1FUL << MPU_RASR_SIZE_Pos)                  

#define MPU_RASR_ENABLE_Pos                 0U                                            
#define MPU_RASR_ENABLE_Msk                (1UL /* MPU_RASR_ENABLE_Pos*/)    

#endif  /* HEADER_MPU_H_ */
