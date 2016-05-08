/*
 * UART.c
 *
 *  Created on: Oct 14, 2014
 *      Author: CTCNGH
 */

#include "include.h"


//void delay_ms(uint16_t period);
void ConfigUART4(void)
{

  USART_InitTypeDef USART_InitStructure;   
  GPIO_InitTypeDef GPIO_InitStructure; 
   
  /* Enable GPIO clock */
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
  /* Enable UART clock */;
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_UART4, ENABLE);

  /* Connect UART4 and USART2 pins to AF2 */  
  GPIO_PinAFConfig(GPIOC, GPIO_PinSource10, GPIO_AF_UART4);
  GPIO_PinAFConfig(GPIOC, GPIO_PinSource11, GPIO_AF_UART4); 
	

  /* GPIO Configuration for USART Tx */
  GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_10 ;
  GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOC, &GPIO_InitStructure);

  /* GPIO Configuration for USART Rx */
  GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_11 ;
  GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF;
  GPIO_Init(GPIOC, &GPIO_InitStructure);
  
       
  /* USARTx configured as follow:
        - BaudRate = 9600 baud  
        - Word Length = 8 Bits
        - One Stop Bit
        - No parity
        - Hardware flow control disabled (RTS and CTS signals)
        - Receive and transmit enabled
  */
  USART_InitStructure.USART_BaudRate = 9600;
  USART_InitStructure.USART_WordLength = USART_WordLength_8b;
  USART_InitStructure.USART_StopBits = USART_StopBits_1;
  USART_InitStructure.USART_Parity = USART_Parity_No;
  USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
  USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;


  USART_Init(UART4, &USART_InitStructure);

  /* Enable USART */
  USART_Cmd(UART4, ENABLE);
  
}




void UARTPut(USART_TypeDef* UART_Base, int32_t num2send)
{

	int i;
	int32_t temp=num2send;
	for(i=4;i>0;i--)
	{
		USART_SendData(UART_Base, (char)((temp&0xff000000)>>24));
		temp=temp<<8;
	}

}

void UARTPutnlong(USART_TypeDef*  UART_Base, long Num)
{
	unsigned long temp = 1;
	long NumTemp;
	NumTemp = Num;
	if (Num == 0)
	{
		USART_SendData(UART_Base, 48);
			delay_ms(10);
	}
	else
	{
		if (Num < 0)
		{
			USART_SendData(UART_Base, '-');
			// Delay after SendData
			delay_ms(10);

			Num *= -1;
		}
		while (NumTemp)
		{
			NumTemp /= 10;
			temp *= 10;
		}
		temp /= 10;
		while (temp)
		{
			USART_SendData(UART_Base,(Num / temp) % 10 + 48);
			delay_ms(10);

			temp /= 10;
		}
	}

}




void UARTFloatx(USART_TypeDef* UART_Base ,float fnum2send)
{
	
	long NumTemp = fnum2send * 1000000;
	long Num = NumTemp;
	unsigned long temp = 1;
	if (Num == 0)
	{
		USART_SendData( UART_Base,(uint16_t) 48 );
	
	}
	else
	{
		if (Num < 0)
		{
			USART_SendData( UART_Base, (uint16_t)'-');

			Num *= -1;
		}
		while (NumTemp)
		{
			NumTemp /= 10;
			temp *= 10;
		}
		temp /= 10;
		while (temp)
		{
			USART_SendData( UART_Base, (uint16_t)((Num / temp) % 10 + 48) );

			temp /= 10;
		}
	}
}


void UART_Print_Matrix(real_T a[4][4])
{
	int i, j;
	for ( i = 0; i < 4 ; ++i )
		for ( j = 0; j < 4 ; ++j )
		{

			UARTPutnlong( UART4, a[i][j] );
			delay_ms(100);
			USART_SendData( UART4, (uint16_t)' ' );
			if (j == 4 - 1) USART_SendData( UART4, (uint16_t)'\n' );
		}

}





