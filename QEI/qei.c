/*
 * QEI.c
 *
 *  Created on: May 3, 2016
 *      Author: AnhTuan
 */



#include "include.h"

	
	 void TIM1_IRQHandler(void)
{
  if (TIM_GetITStatus(TIM1, TIM_IT_Update) != RESET)
  {
    TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
    GPIO_ToggleBits(GPIOD, GPIO_Pin_12);
		USART_SendData(UART4,(uint16_t)20);
  }
}
 void TIM8_IRQHandler(void)
{
  if (TIM_GetITStatus(TIM8, TIM_IT_Update) != RESET)
  {
    TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
    GPIO_ToggleBits(GPIOD, GPIO_Pin_13);
		USART_SendData(UART4,(uint16_t)20);
  }
}
 void TIM3_IRQHandler(void)
{
  if (TIM_GetITStatus(TIM3, TIM_IT_Update) != RESET)
  {
    TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
    GPIO_ToggleBits(GPIOD, GPIO_Pin_14);
		USART_SendData(UART4,(uint16_t)20);
  }
}
 void TIM4_IRQHandler(void)
{
  if (TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET)
  {
    TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
    GPIO_ToggleBits(GPIOD, GPIO_Pin_15);
		USART_SendData(UART4,(uint16_t)20);
  }
}

void EncodersInit (void)
{
	
	GPIO_InitTypeDef GPIO_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;

  // turn on the clocks for each of the ports needed
  RCC_AHB1PeriphClockCmd (ENC1A_GPIO_CLK, ENABLE);
  RCC_AHB1PeriphClockCmd (ENC1B_GPIO_CLK, ENABLE);
  RCC_AHB1PeriphClockCmd (ENC2A_GPIO_CLK, ENABLE);
  RCC_AHB1PeriphClockCmd (ENC2B_GPIO_CLK, ENABLE);
	RCC_AHB1PeriphClockCmd (ENC3A_GPIO_CLK, ENABLE);
  RCC_AHB1PeriphClockCmd (ENC3B_GPIO_CLK, ENABLE);
	RCC_AHB1PeriphClockCmd (ENC4A_GPIO_CLK, ENABLE);
  RCC_AHB1PeriphClockCmd (ENC4B_GPIO_CLK, ENABLE);
	RCC_AHB1PeriphClockCmd (ENC5A_GPIO_CLK, ENABLE);
  RCC_AHB1PeriphClockCmd (ENC5B_GPIO_CLK, ENABLE);
	RCC_AHB1PeriphClockCmd (ENC6A_GPIO_CLK, ENABLE);
  RCC_AHB1PeriphClockCmd (ENC6B_GPIO_CLK, ENABLE);

  // now configure the pins themselves

	// init for all pin 
	  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
   // motor1 
    GPIO_InitStructure.GPIO_Pin = ENC1A_PIN;
    GPIO_Init (ENC1A_GPIO_PORT, &GPIO_InitStructure);
		GPIO_InitStructure.GPIO_Pin = ENC1B_PIN;
    GPIO_Init (ENC1B_GPIO_PORT, &GPIO_InitStructure);
	 // motor2 
    GPIO_InitStructure.GPIO_Pin = ENC2A_PIN;
    GPIO_Init (ENC2A_GPIO_PORT, &GPIO_InitStructure);
		GPIO_InitStructure.GPIO_Pin = ENC2B_PIN;
    GPIO_Init (ENC2B_GPIO_PORT, &GPIO_InitStructure);
	 // motor3 
    GPIO_InitStructure.GPIO_Pin = ENC3A_PIN;
    GPIO_Init (ENC3A_GPIO_PORT, &GPIO_InitStructure);
		GPIO_InitStructure.GPIO_Pin = ENC3B_PIN;
    GPIO_Init (ENC3B_GPIO_PORT, &GPIO_InitStructure);
	 // motor4 
    GPIO_InitStructure.GPIO_Pin = ENC4A_PIN;
    GPIO_Init (ENC4A_GPIO_PORT, &GPIO_InitStructure);
		GPIO_InitStructure.GPIO_Pin = ENC4B_PIN;
    GPIO_Init (ENC4B_GPIO_PORT, &GPIO_InitStructure);
		// motor5 
    GPIO_InitStructure.GPIO_Pin = ENC5A_PIN;
    GPIO_Init (ENC5A_GPIO_PORT, &GPIO_InitStructure);
		GPIO_InitStructure.GPIO_Pin = ENC5B_PIN;
    GPIO_Init (ENC5B_GPIO_PORT, &GPIO_InitStructure);
		// motor6 
    GPIO_InitStructure.GPIO_Pin = ENC6A_PIN;
    GPIO_Init (ENC6A_GPIO_PORT, &GPIO_InitStructure);
		GPIO_InitStructure.GPIO_Pin = ENC6B_PIN;
    GPIO_Init (ENC6B_GPIO_PORT, &GPIO_InitStructure);
	
	


  // Connect the pins to their Alternate Functions
  GPIO_PinAFConfig (ENC1A_GPIO_PORT, ENC1A_SOURCE, ENC1A_AF);
  GPIO_PinAFConfig (ENC1B_GPIO_PORT, ENC1B_SOURCE, ENC1B_AF);
	
  GPIO_PinAFConfig (ENC2A_GPIO_PORT, ENC2A_SOURCE, ENC2A_AF);
  GPIO_PinAFConfig (ENC2B_GPIO_PORT, ENC2B_SOURCE, ENC2B_AF);

  GPIO_PinAFConfig (ENC3A_GPIO_PORT, ENC3A_SOURCE, ENC3A_AF);
  GPIO_PinAFConfig (ENC3B_GPIO_PORT, ENC3B_SOURCE, ENC3B_AF);
	
	GPIO_PinAFConfig (ENC4A_GPIO_PORT, ENC4A_SOURCE, ENC4A_AF);
  GPIO_PinAFConfig (ENC4B_GPIO_PORT, ENC4B_SOURCE, ENC4B_AF);
	
	GPIO_PinAFConfig (ENC5A_GPIO_PORT, ENC5A_SOURCE, ENC5A_AF);
  GPIO_PinAFConfig (ENC5B_GPIO_PORT, ENC5B_SOURCE, ENC5B_AF);
	
	GPIO_PinAFConfig (ENC6A_GPIO_PORT, ENC6A_SOURCE, ENC6A_AF);
  GPIO_PinAFConfig (ENC6B_GPIO_PORT, ENC6B_SOURCE, ENC6B_AF);

	
	
	
  // Timer peripheral clock enable
  RCC_APB1PeriphClockCmd (RCC_APB1Periph_TIM2, ENABLE);
  RCC_APB1PeriphClockCmd (RCC_APB1Periph_TIM3, ENABLE);
	RCC_APB1PeriphClockCmd (RCC_APB1Periph_TIM4, ENABLE);
  RCC_APB1PeriphClockCmd (RCC_APB1Periph_TIM5, ENABLE);
	
	RCC_APB2PeriphClockCmd (RCC_APB2Periph_TIM1, ENABLE);
  RCC_APB2PeriphClockCmd (RCC_APB2Periph_TIM8, ENABLE);
	

  // set them up as encoder inputs
  // set both inputs to rising polarity to let it use both edges
  TIM_EncoderInterfaceConfig (TIM1, TIM_EncoderMode_TI12, TIM_ICPolarity_Rising, TIM_ICPolarity_Rising);
  TIM_SetAutoreload (TIM1, 0xffff);
	
	TIM_EncoderInterfaceConfig (TIM2, TIM_EncoderMode_TI12, TIM_ICPolarity_Rising, TIM_ICPolarity_Rising);
  TIM_SetAutoreload (TIM2, 0xffffffff);
	
	TIM_EncoderInterfaceConfig (TIM3, TIM_EncoderMode_TI12, TIM_ICPolarity_Rising, TIM_ICPolarity_Rising);
	TIM_SetAutoreload (TIM3, 0xffff);

	TIM_EncoderInterfaceConfig (TIM4, TIM_EncoderMode_TI12, TIM_ICPolarity_Rising, TIM_ICPolarity_Rising);
	TIM_SetAutoreload (TIM4, 0xffff);
	
	TIM_EncoderInterfaceConfig (TIM5, TIM_EncoderMode_TI12, TIM_ICPolarity_Rising, TIM_ICPolarity_Rising);
  TIM_SetAutoreload (TIM5, 0xffffffff);
	
	TIM_EncoderInterfaceConfig (TIM6, TIM_EncoderMode_TI12, TIM_ICPolarity_Rising, TIM_ICPolarity_Rising);
  TIM_SetAutoreload (TIM6, 0xffff);
	

	

	//Timer 2 5 32bit not use interrupt for my application  
	//Config Timer 3 4 1 8

  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	
	NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;
  NVIC_Init(&NVIC_InitStructure);
	
	NVIC_InitStructure.NVIC_IRQChannel = TIM4_IRQn;
  NVIC_Init(&NVIC_InitStructure);
	
//	NVIC_InitStructure.NVIC_IRQChannel = TIM1_IRQn;
//  NVIC_Init(&NVIC_InitStructure);
//	
//	NVIC_InitStructure.NVIC_IRQChannel = TIM8_IRQn;
//  NVIC_Init(&NVIC_InitStructure);



  /* Time base configuration */
  TIM_TimeBaseStructure.TIM_Period = 65536-1;  // (2^16-1)
  TIM_TimeBaseStructure.TIM_Prescaler = 0; // 84MHZ
  TIM_TimeBaseStructure.TIM_ClockDivision = 0;
  TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	
  TIM_TimeBaseInit(TIM1, &TIM_TimeBaseStructure);
	TIM_TimeBaseInit(TIM8, &TIM_TimeBaseStructure);
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);
	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);
	
	
  /* TIM IT enable */
  TIM_ITConfig(TIM1, TIM_IT_Update, ENABLE);
	TIM_ITConfig(TIM8, TIM_IT_Update, ENABLE);
	TIM_ITConfig(TIM3, TIM_IT_Update, ENABLE);
  TIM_ITConfig(TIM4, TIM_IT_Update, ENABLE);
  /* TIMx enable counter */
  TIM_Cmd(TIM1, ENABLE);
	TIM_Cmd(TIM8, ENABLE);
	TIM_Cmd(TIM3, ENABLE);
	TIM_Cmd(TIM4, ENABLE);

}

