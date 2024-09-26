/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
#include <stdio.h>
#include "stm32f4xx.h"
#include "system_stm32f4xx.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

// Orange LED -- GPIOD pin 13.
//	1 -- Led On
//	0 -- Led Off

int main(void) {
	SystemInit();
	RCC->AHB1ENR |= BV(3);
	//PD=15
	GPIOD->MODER &=~BV(31);
	GPIOD->MODER |=BV(30);

	GPIOD->OTYPER &=~BV(15);

	GPIOD->OSPEEDR &=~BV(31);
	GPIOD->OSPEEDR |=BV(30);
	

	while(1){
	GPIOD->BSRR |=BV(15);

	DelayMs(500);

	GPIOD->BSRR |=BV(31);

	DelayMs(500);
	}

	return 0;
}

