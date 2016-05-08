/*
 * MY_GPIO.h
 *
 *  Created on: May 4, 2016
 *      Author: AnhTuan
 */

#ifndef MY_GPIO_H_
#define MY_GPIO_H_

#include "include.h"

extern void ConfigGPIOD(void);
extern void ConfigGPIOA(void);
//extern void Pull_Pulse(int pulse , uint32_t frequency , uint16_t joint);

static GPIO_TypeDef * ServoBase_Pin_Pulse[6] =
{ GPIOD, GPIOD, GPIOD, GPIOD, GPIOD, GPIOD };
static uint32_t ServoPin_Pulse[6] =
{ GPIO_Pin_12, GPIO_Pin_13, GPIO_Pin_14, GPIO_Pin_15, GPIO_Pin_10, GPIO_Pin_11 };

static GPIO_TypeDef * ServoBase_Pin_Dir[6] =
{ GPIOA, GPIOA, GPIOA, GPIOA, GPIOA, GPIOA };
static uint32_t ServoPin_Dir[6] =
{ GPIO_Pin_1, GPIO_Pin_2, GPIO_Pin_3, GPIO_Pin_4, GPIO_Pin_5, GPIO_Pin_6 };

static uint32_t ServoPulse[6] =
{ 0, 0, 0, 0, 0, 0 };
static uint32_t ServoPos[6] =
{ 0, 0, 0, 0, 0, 0 }; // dem so lan vao ngat de dao bit
static uint32_t ServoPosTemp[6] =
{ 0, 0, 0, 0, 0, 0 };

#endif /* MY_GPIO_H_ */
