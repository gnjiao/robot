

#ifndef TIMER_H_
#define TIMER_H_

#include "include.h"


/******************************************************************
 * PROTOTYPE
 *****************************************************************/
extern void ConfigIntervalTimer(uint32_t TimerIntervalms);
extern void TimerInterruptHandler(void);
extern void Pull_Pulse(int pulse , uint32_t frequency , uint16_t joint);
extern void Delay(__IO uint32_t nCount);
extern void delay_us(uint16_t period);
extern void delay_ms(uint16_t period);
extern void INTTIM_Config(void);

#endif /* TIMER_H_ */
