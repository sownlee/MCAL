#if !defined(HEADER_SPI_H_)  
#define HEADER_SPI_H_

#include "Header.h"

typedef struct
{
	__O uint32_t CR1;	   /* SPI control register 1         */
	__O uint32_t CR2;	   /* SPI control register 2         */
	__O uint32_t SR;	     /* SPI status register            */
	__O uint32_t DR;	     /* SPI data register              */
	__O uint32_t CRCPR;   /* SPI CRC polynomial register    */
	__O uint32_t RXCRCR;  /* SPI RX CRC register            */
	__O uint32_t TXCRCR;  /* SPI TX CRC register            */
	__O uint32_t I2SCFGR; /* SPI_I2S configuration register */
	__O uint32_t I2SPR;   /* SPI_I2S prescaler register     */
} SPI_RegDef_t;
#define SPI1 ((SPI_RegDef_t *)SPI1_BASEADDR)
#define SPI2 ((SPI_RegDef_t *)SPI2_BASEADDR)
#define SPI3 ((SPI_RegDef_t *)SPI3_BASEADDR)

/*  Bit definition for SPI_CR1 register  */
#define SPI_CR1_CPHA 0
#define SPI_CR1_CPOL 1
#define SPI_CR1_MSTR 2
#define SPI_CR1_BR 3
#define SPI_CR1_SPE 6
#define SPI_CR1_LSBFIRST 7
#define SPI_CR1_SSI 8
#define SPI_CR1_SSM 9
#define SPI_CR1_RXONLY 10
#define SPI_CR1_DFF 11
#define SPI_CR1_CRCNEXT 12
#define SPI_CR1_CRCEN 13
#define SPI_CR1_BIDIOE 14
#define SPI_CR1_BIDIMODE 15

/*  Bit definition for SPI_CR2 register  */
#define SPI_CR2_RXDMAEN 0
#define SPI_CR2_TXDMAEN 1
#define SPI_CR2_SSOE 2
#define SPI_CR2_FRF 4
#define SPI_CR2_ERRIE 5
#define SPI_CR2_RXNEIE 6
#define SPI_CR2_TXEIE 7

/*  Bit definition for SPI_CR2 register  */
#define SPI_SR_RXNE 0
#define SPI_SR_TXE 1
#define SPI_SR_CHSIDE 2
#define SPI_SR_UDR 3
#define SPI_SR_CRCERR 4
#define SPI_SR_MODF 5
#define SPI_SR_OVR 6
#define SPI_SR_BSY 7
#define SPI_SR_FRE 8

#endif  /* HEADER_LPSPI_H_ */
