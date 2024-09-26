/*
 * uart.h
 *
 *  Created on: Sep 23, 2024
 *      Author: sunbeam
 */

#ifndef UART_H_
#define UART_H_

#include"stm32f4xx.h"

#define UART 		USART2

#define TX	2
#define RX 3

#define GPIO_CLK 0

#define CLK 17

#define UBRR_9600   0x683

void uartinit(uint32_t baud);
void uartputch(uint8_t ch);
void uartputs(char str[]);
uint8_t uartgetch(void);
void uartgets(char str[]);


#endif /* UART_H_ */
