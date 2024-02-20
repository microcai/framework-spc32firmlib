/**************************************************************************//**
 * @file     timer.c
 * @brief    This file provides TIMER firmware functions.
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

#include "timer.h"


/****************************************************************************//**
 * @brief      Initialize the timer 
 *
 * @param[in]  TIMERx          :  Select the timer module
 * @param[in]  u32TimerPeriodMs:  Timer interrupt period (ms)
 *
 * @return     none
 *
 *******************************************************************************/
void TIMER_Init(TIMER_REGS* TIMERx, uint32_t u32TimerPeriodMs)
{
  /* Timer's clock comes from APB clock, which means from PLCK */
  uint32_t u32TimerClk = SysInfo.u32PCLK;
  
  /*  Enable timer and select internal clock  */
  TIMERx->TMRCTL.all = TMRCTL_ALL_EN_ENABLE 
                     | TMRCTL_ALL_EXINT4EN_NOT_SEL_EXTERNAL 
                     | TMRCTL_ALL_INTEN_ENABLE;
  
  /*  Set reload timer while timer reaches 0 */
  TIMERx->TMRRELOAD.all = TMRRELOAD_ALL_VAL_(CLOCK_MsToCounter(u32TimerPeriodMs,u32TimerClk));
}


/******************* (C) COPYRIGHT 2021 SPINTROL LIMITED CO. *****END OF FILE****/
