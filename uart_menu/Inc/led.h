/*
 * led.h
 *
 *  Created on: Sep 20, 2024
 *      Author: sunbeam
 */

#ifndef LED_H_
#define LED_H_
#include "stm32f4xx.h"

#define GREEN	12
#define ORANGE	13
#define RED		14
#define BLUE	15


#define LEDCLK 3


//#define port 13

void SET_LED(uint32_t port);
void ON(uint32_t port);
void OFF(uint32_t port);
void blink(uint32_t port,uint32_t delay_ms);
void ledtoggle(uint32_t port);


#endif /* LED_H_ */


