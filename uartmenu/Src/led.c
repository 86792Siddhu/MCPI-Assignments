/*
 *
 * led.c
 *
 *  Created on: Sep 20, 2024
 *      Author: sunbeam
 */
#include"led.h"

void SET_LED(uint32_t port){
	RCC->AHB1ENR |= BV(LEDCLK);
	GPIOD->MODER &=~BV(port*2+1);
	GPIOD->MODER |=BV(port*2);
	GPIOD->OTYPER &=~BV(port);
	GPIOD->OSPEEDR &=~BV(port*2+1);
	GPIOD->OSPEEDR |=BV(port*2);
	GPIOD->PUPDR &= ~(BV(port*2+1) | BV(port*2));
}
void ON(uint32_t port){
	GPIOD->ODR |=BV(port);
}

void OFF(uint32_t port){
	GPIOD->ODR &=~BV(port);
}

void blink(uint32_t port,uint32_t delayms){
	ON(port);
	DelayMs(delayms);
	OFF(port);
}
void ledtoggle(uint32_t port){

	GPIOD->ODR ^=BV(port);
}






