#if !defined(HEADER_I2C_H_) 
#define HEADER_I2C_H_

#include "Header.h"

typedef struct
{
	__O uint32_t CR1;	 /* I2C Control register 1     */
	__O uint32_t CR2;	 /* I2C Control register 2     */
	__O uint32_t OAR1;	 /* I2C Own address register 1 */
	__O uint32_t OAR2;	 /* I2C Own address register 2 */
	__O uint32_t DR;	 /* I2C Data register     	   */
    __O uint32_t SR1;	 /* I2C Status register 1      */
	__O uint32_t SR2;	 /* I2C Status register 2      */
	__O uint32_t CCR;	 /* I2C Clock control register */
	__O uint32_t TRISE;  /* I2C TRISE register         */
	__O uint32_t FLTR;	 /* I2C FLTR register     	   */
} I2C_RegDef_t;
#define I2C1 ((I2C_RegDef_t *)I2C1_BASEADDR)
#define I2C2 ((I2C_RegDef_t *)I2C2_BASEADDR)
#define I2C3 ((I2C_RegDef_t *)I2C3_BASEADDR)

/*  Bit definition for I2C_CR1 register  */
#define I2C_CR1_PE 0
#define I2C_CR1_NOSTRETCH 7
#define I2C_CR1_START 8
#define I2C_CR1_STOP 9
#define I2C_CR1_ACK 10
#define I2C_CR1_SWRST 15

/*  Bit definition for I2C_CR2 register  */
#define I2C_CR2_FREQ 0
#define I2C_CR2_ITERREN 8
#define I2C_CR2_ITEVTEN 9
#define I2C_CR2_ITBUFEN 10

/*  Bit definition for I2C_OAR1 register  */
#define I2C_OAR1_ADD0 0
#define I2C_OAR1_ADD71 1
#define I2C_OAR1_ADD98 8
#define I2C_OAR1_ADDMODE 15

/*  Bit definition for I2C_SR1 register  */
#define I2C_SR1_SB 0
#define I2C_SR1_ADDR 1
#define I2C_SR1_BTF 2
#define I2C_SR1_ADD10 3
#define I2C_SR1_STOPF 4
#define I2C_SR1_RXNE 6
#define I2C_SR1_TXE 7
#define I2C_SR1_BERR 8
#define I2C_SR1_ARLO 9
#define I2C_SR1_AF 10
#define I2C_SR1_OVR 11
#define I2C_SR1_TIMEOUT 14

/*  Bit definition for I2C_SR2 register  */
#define I2C_SR2_MSL 0
#define I2C_SR2_BUSY 1
#define I2C_SR2_TRA 2
#define I2C_SR2_GENCALL 4
#define I2C_SR2_DUALF 7

/*  Bit definition for I2C_CRR register  */
#define I2C_CCR_CCR 0
#define I2C_CCR_DUTY 14
#define I2C_CCR_FS 15

#endif  /* HEADER_LPI2C_H_ */
