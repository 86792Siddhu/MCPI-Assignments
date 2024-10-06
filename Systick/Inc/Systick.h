/*
 * Systick.h
 *
 *  Created on: Oct 3, 2024
 *      Author: chintha
 */

#ifndef SYSTICK_H_
#define SYSTICK_H_
#include"stm32f4xx.h"
void Systick_Handler(void);
void Systick_Delay(uint32_t ms);

#endif /* SYSTICK_H_ */
