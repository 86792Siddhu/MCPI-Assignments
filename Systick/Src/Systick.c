/*
 * Systick.c
 *
 *  Created on: Oct 6, 2024
 *      Author: chintha
 */
#include "Systick.h"

volatile uint32_t jiffies = 0;
void SysTick_Handler(void) {
	jiffies++;
	//GPIOD->ODR ^= BV(LED_RED_PIN); // ---> Oscilloscope/Analyzer
}
void SysTick_Delay(uint32_t ms) {
	uint32_t until = jiffies + ms;
	while(jiffies < until)
		;
}
