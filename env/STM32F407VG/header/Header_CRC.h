#if !defined(HEADER_CRC_H_)  
#define HEADER_CRC_H_

#include "Header.h"

typedef struct
{
  __O uint32_t DR;         /* CRC Data register              */
  __O uint8_t  IDR;        /* CRC Independent data register  */
  uint8_t       RESERVED0;  /* Reserved 0x05                  */
  uint16_t      RESERVED1;  /* Reserved 0x06                  */
  __O uint32_t CR;         /* CRC Control register           */
} CRC_RegDef_t;
#define CRC                 ((CRC_RegDef_t *) CRC_BASEADDR)

/*******************  Bit definition for CRC_DR register  *********************/
#define CRC_DR_DR_Pos       (0U)                                               
#define CRC_DR_DR_Msk       (0xFFFFFFFFUL << CRC_DR_DR_Pos)                    
#define CRC_DR_DR           CRC_DR_DR_Msk                                      


/*******************  Bit definition for CRC_IDR register  ********************/
#define CRC_IDR_IDR_Pos     (0U)                                              
#define CRC_IDR_IDR_Msk     (0xFFUL << CRC_IDR_IDR_Pos)                        
#define CRC_IDR_IDR         CRC_IDR_IDR_Msk                                    


/********************  Bit definition for CRC_CR register  ********************/
#define CRC_CR_RESET_Pos    (0U)                                               
#define CRC_CR_RESET_Msk    (0x1UL << CRC_CR_RESET_Pos)                         
#define CRC_CR_RESET        CRC_CR_RESET_Msk          

#endif  /* HEADER_CRC_H_ */
