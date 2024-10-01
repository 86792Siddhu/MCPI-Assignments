/*
 * uart.c
 *
 *  Created on: Sep 23, 2024
 *      Author: sunbeam
 */

#include"uart.h"
#include"string.h"

void uartinit(uint32_t baud){

	RCC->AHB1ENR |= BV(GPIO_CLK);

	GPIOA->MODER |=BV(TX*2+1)|BV(RX*2+1);

	GPIOA->MODER &=~(BV(TX*2)|BV(RX*2));

	GPIOA->AFR[0] |=BV(8) |BV(9)|BV(10)|BV(12)|BV(13)|BV(14);

	GPIOA->AFR[0] &=~(BV(11)|BV(15));

	RCC->APB1ENR |=BV(CLK);

	UART->CR1 = BV(USART_CR1_TE_Pos)|BV(USART_CR1_RE_Pos);

	UART->CR1 &=~(BV(USART_CR1_M_Pos)|BV(USART_CR1_OVER8_Pos));

	UART->CR2 &= ~(USART_CR2_STOP_0 | USART_CR2_STOP_1);

	if(baud == 9600)
			UART->BRR = UBRR_9600;
	UART->CR1 |=BV(USART_CR1_UE_Pos);

}

void uartputch(uint8_t ch){
	UART->DR = ch;
	while((UART->SR & BV(USART_SR_TXE_Pos))==0);
}

void uartputs(char str[]){
	for (int i=0;str[i];i++)
	{
		uartputch((uint8_t)str[i]);
	}
}
uint8_t uartgetch(void){
	while((UART->SR & BV(USART_SR_RXNE_Pos))==0);
	uint8_t ch = UART->DR;
	return ch;
}
void uartgets(char str[]){
	char ch;
	int i =0;
	do{
		ch =uartgetch();
		str[i]=ch;
		i++;
		}while(ch!='\r');
	str[i++] = '\n';
	str[i]='\0';
}





