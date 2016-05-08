
/*
 * UART.h
 *
 *  Created on: May 3, 2016
 *      Author: AnhTuan
 */

#ifndef UART_UART_H_
#define UART_UART_H_


#include "include.h"
	 
extern void ConfigUART4(void);
extern void UARTPut(USART_TypeDef* UART_Base, int32_t num2send);
extern void UARTPutnlong(USART_TypeDef*  UART_Base, long Num);
extern void UARTPutFloat(USART_TypeDef* UART_Base, float fnum2send);
extern void UART_Print_Matrix(real_T a[4][4]);
extern void UARTFloatx(USART_TypeDef* UART_Base ,float fnum2send);
#endif /* UART_UART_H_ */