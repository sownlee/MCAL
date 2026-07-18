#if !defined(HEADER_UART_H_)  
#define HEADER_UART_H_

#include "Header.h"

typedef struct
{
	__O uint32_t SR;	  /* USART Status register                   */
	__O uint32_t DR;	  /* USART Data register                     */
	__O uint32_t BRR;	/* USART Baud rate register                */
	__O uint32_t CR1;	/* USART Control register 1                */
	__O uint32_t CR2;	/* USART Control register 2                */
	__O uint32_t CR3;	/* USART Control register 3                */
	__O uint32_t GTPR; /* USART Guard time and prescaler register */
} USART_RegDef_t;
#define USART1 ((USART_RegDef_t *)USART1_BASEADDR)
#define USART2 ((USART_RegDef_t *)USART2_BASEADDR)
#define USART3 ((USART_RegDef_t *)USART3_BASEADDR)
#define UART4 ((USART_RegDef_t *)UART4_BASEADDR)
#define UART5 ((USART_RegDef_t *)UART5_BASEADDR)
#define USART6 ((USART_RegDef_t *)USART6_BASEADDR)

/*  Bit definition for USART_SR register  */
#define USART_SR_PE 0
#define USART_SR_FE 1
#define USART_SR_NE 2
#define USART_SR_ORE 3
#define USART_SR_IDLE 4
#define USART_SR_RXNE 5
#define USART_SR_TC 6
#define USART_SR_TXE 7
#define USART_SR_LBD 8
#define USART_SR_CTS 9

/*  Bit definition for USART_CR1 register  */
#define USART_CR1_SBK 0
#define USART_CR1_RWU 1
#define USART_CR1_RE 2
#define USART_CR1_TE 3
#define USART_CR1_IDLEIE 4
#define USART_CR1_RXNEIE 5
#define USART_CR1_TCIE 6
#define USART_CR1_TXEIE 7
#define USART_CR1_PEIE 8
#define USART_CR1_PS 9
#define USART_CR1_PCE 10
#define USART_CR1_WAKE 11
#define USART_CR1_M 12
#define USART_CR1_UE 13
#define USART_CR1_OVER8 15

/* Bit definition for USART_CR2 register  */
#define USART_CR2_ADD 0
#define USART_CR2_LBDL 5
#define USART_CR2_LBDIE 6
#define USART_CR2_LBCL 8
#define USART_CR2_CPHA 9
#define USART_CR2_CPOL 10
#define USART_CR2_STOP 12
#define USART_CR2_LINEN 14

/*  Bit definition for USART_CR3 register  */
#define USART_CR3_EIE 0
#define USART_CR3_IREN 1
#define USART_CR3_IRLP 2
#define USART_CR3_HDSEL 3
#define USART_CR3_NACK 4
#define USART_CR3_SCEN 5
#define USART_CR3_DMAR 6
#define USART_CR3_DMAT 7
#define USART_CR3_RTSE 8
#define USART_CR3_CTSE 9
#define USART_CR3_CTSIE 10
#define USART_CR3_ONEBIT 11

#endif  /* HEADER_UART_H_ */
