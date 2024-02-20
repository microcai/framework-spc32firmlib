/**************************************************************************//**
 * @file     delay.c
 * @brief    This file provides Time-Delay firmware functions.
 * @version  V1.2.0
 * @date     05-Feb-2021
 *
 * @note
 * Copyright (C) 2021 Spintrol Limited Corporation. All rights reserved.
 *
 * @attention
 * THIS SOFTWARE JUST PROVIDES CUSTOMERS WITH CODING INFORMATION REGARDING 
 * THEIR PRODUCTS, WHICH AIMS AT SAVING TIME FOR THEM. SPINTROL SHALL NOT BE
 * LIABLE FOR THE USE OF THE SOFTWARE. SPINTROL DOES NOT GUARANTEE THE 
 * CORRECTNESS OF THIS SOFTWARE AND RESERVES THE RIGHT TO MODIFY THE SOFTWARE 
 * WITHOUT NOTIFICATION.
 *
 ******************************************************************************/

#include "delay.h"




/**
 *  @brief  Clock cycles per microseconds
 */
uint32_t u32DelayLoopPerUs;      /* (1) The number of loops in one us 
                                    (2) Used for time out when timer is used as delay */
uint32_t u32DelayClockPerUs;




/****************************************************************************//**
 * @brief      Initializes the time-delay module
 *
 * @param[in]  none
 *
 * @return     none
 *
 *******************************************************************************/
void Delay_Init(void)
{
  u32DelayLoopPerUs  = ((SysInfo.u32HCLK) / 1000000)>>2;  /* Each loop will cost 4 cycles */
  
  /* Delay by timer */
  u32DelayClockPerUs = (SysInfo.u32PCLK) / 1000000;

#if DELAY_TYPE != DELAY_BY_CPU
  u32DelayLoopPerUs  = ((SysInfo.u32HCLK) / 1000000)<<2;
  TIMER_EnableInt(DELAY_TIMER);
#endif
}




/****************************************************************************//**
 * @brief      Delays the specified milliseconds
 *
 * @param[in]  u32Delay_ms:  The milliseconds to delay, if the system clock = 24 MHz, 
 *                           the maximum time delay is 699 ms.
 *
 * @return     none
 *
 *******************************************************************************/
void Delay_ms(uint32_t u32Delay_ms)
{
  Delay_us(u32Delay_ms * 1000);
}




/****************************************************************************//**
 * @brief      Delays the specified microseconds
 *
 * @param[in]  u32Delay_us:  The microseconds to delay
 *
 * @return     none
 *
 *******************************************************************************/
void Delay_us(uint32_t u32Delay_us)
{
#if  DELAY_TYPE == DELAY_BY_CPU
  /* Delay by CPU */
  u32Delay_us=(u32Delay_us*u32DelayLoopPerUs);                          /* there is 4 cycle during for in O0~O3  */
  while(u32Delay_us){u32Delay_us--;}
#else
  /* Delay by timer */
  volatile uint32_t u32Timeout;                                         /* Prevant optimization effect           */
                                                                        /* This timeout is suitable for O0~O3    */
  
  u32Timeout = u32DelayLoopPerUs;                                       /* About 1.25 us as timeout in O1~O3     */
                                                                        /* About 1.5  us as timeout in O0        */
  
  TIMER_Stop(DELAY_TIMER);                                              /* Stop timer                            */
  TIMER_SetReloadValue(DELAY_TIMER, u32Delay_us * u32DelayClockPerUs);  /* Set timer reload value                */
  TIMER_ClearInt(DELAY_TIMER);                                          /* Clear timer interrupt flag            */
  TIMER_Run(DELAY_TIMER);                                               /* Timer run                             */
  while((!TIMER_GetIntFlag(DELAY_TIMER)))                               /* Wait until (1) Timer flag enable      */
  {                                                                     /*            (2) Timer out  occurs      */
    if((u32Timeout--)==0){ break;}
  }
#endif 
}


/******************* (C) COPYRIGHT 2021 SPINTROL LIMITED CO. *****END OF FILE****/
