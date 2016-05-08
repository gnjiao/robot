/*
 * TIMER.h
 *
 *  Created on: May 3, 2016
 *      Author: AnhTuan
 */

#include "include.h"



void TIM9_IRQHandler(void)//interupt Timer2
{
	int i=0;
if (TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET)
{
TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
GPIO_ToggleBits(GPIOD, GPIO_Pin_12);

for ( i = 0; i < 6 ; i++ )
	{
		if (0 != ServoPulse[i])
		{
			if (0 == ServoPosTemp[i])
			{			
				GPIO_ToggleBits(ServoBase_Pin_Pulse[i],ServoPin_Pulse[i]);//toggle pin 
				ServoPulse[i]--;
				ServoPosTemp[i] = ServoPos[i];
			}
			else
			{
				ServoPosTemp[i]--;
			}
		}

	}	
}
}

void INTTIM_Config(void)
{
TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
NVIC_InitTypeDef NVIC_InitStructure;
	
/* Enable the TIM2 gloabal Interrupt */
NVIC_InitStructure.NVIC_IRQChannel = TIM9_IRQn;
NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
NVIC_Init(&NVIC_InitStructure);
 
/* TIM2 clock enable */
RCC_APB1PeriphClockCmd(RCC_APB2Periph_TIM9, ENABLE);
/* Time base configuration */
TIM_TimeBaseStructure.TIM_Period =10-1 ;     //0.1mhz period = clock of timer *10 =100000 KHz
TIM_TimeBaseStructure.TIM_Prescaler =((SystemCoreClock/2)/1000000)-1; // 83 24 MHz Clock down to 1 MHz (adjust per your clock)
TIM_TimeBaseStructure.TIM_ClockDivision = 0;
TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
TIM_TimeBaseInit(TIM9, &TIM_TimeBaseStructure);
/* TIM IT enable */
TIM_ITConfig(TIM9, TIM_IT_Update, ENABLE);
/* TIM2 enable counter */
TIM_Cmd(TIM9, ENABLE);

}


void Pull_Pulse(int pulse , uint32_t frequency , uint16_t joint)
{
	if (pulse < 0)
	{
		GPIO_ResetBits( ServoBase_Pin_Dir[joint], ServoPin_Dir[joint] ); // Quay nguoc DIR=0
		ServoPulse[joint] = -pulse;
	}
	else
	{
		GPIO_SetBits( ServoBase_Pin_Dir[joint], ServoPin_Dir[joint]);
		
		ServoPulse[joint] = pulse;
	}

	ServoPos[joint] = fre_Timer / frequency; // dem so lan vao ngat de dao bit
	ServoPosTemp[joint] = ServoPos[joint];
}


void delay_us(uint16_t period)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM6,ENABLE);
	TIM6->PSC=83;
	TIM6->ARR=period-1;
	TIM6->CNT=0;
	TIM6->EGR=1;//update register
	TIM6->SR=0;//clr overflow flag
	TIM6->CR1=1;// enable tim6 
	while (!TIM6->SR);
	TIM6->CR1=0; 
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM6,DISABLE);
		
}
void delay_ms(uint16_t period)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM6,ENABLE);
	TIM6->PSC=8399;
	TIM6->ARR=period-1;
	TIM6->CNT=0;
	TIM6->EGR=1;//update register
	TIM6->SR=0;//clr overflow flag
	TIM6->CR1=1;// enable tim6 
	while (!TIM6->SR);
	TIM6->CR1=0; 
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM6,DISABLE);
		
}
void Delay(__IO uint32_t nCount)
{
  while(nCount--)
  {
  }
}





