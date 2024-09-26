/*
 * switch.c
 *
 *  Created on: Sep 24, 2024
 *      Author: sunbeam
 */

#include <stdio.h>
#include "stm32f4xx.h"
#include "switch.h"

void switchinit(void){
	RCC->AHB1ENR |=BV(0);
	GPIOA->MODER &= ~(BV(PIN*2)|BV(PIN*2+1));
	GPIOA->PUPDR &=~(BV(PIN*2)|BV(PIN*2+1));
}

int switchispressed(void){

	uint32_t idr = GPIOA->IDR;
	if ((idr & BV(PIN))== 0)
		return  0;
	return 1;
}
