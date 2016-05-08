/**
  ******************************************************************************
  * @file   Robot/main.c 
  * @author  AnhTuan
  * @version V1.0.0
  * @date    5/5/2016
  * @brief   Main program body
  ******************************************************************************
  */ 

/* Includes ------------------------------------------------------------------*/
#include "include.h"


int main(void)
{
	//EN FPU
	ConfigUART4();
	ConfigGPIOD();
	Make_DK(10,10,10,10,10,10);
	INTTIM_Config();//timer
	Pull_Pulse(-1000,100,2);
	Pull_Pulse(-1000,20,1);
	Pull_Pulse(-1000,10,3);
	Encoder_Pulse_6=1;

//	UARTPutnlong(UART4,1111);	
  while (1)
  {}
		
  
}


#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif

/**
  * @}
  */ 

/**
  * @}
  */ 

/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
