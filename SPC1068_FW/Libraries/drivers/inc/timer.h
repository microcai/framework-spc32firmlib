/**************************************************************************//**
 * @file     timer.h
 * @brief    TIMER driver header file.
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


#ifndef TIMER_H
#define TIMER_H

#ifdef __cplusplus
extern "C" {
#endif


#include "spc1068.h"




/****************************************************************************//**
 * @brief      Enable Timer
 *
 * @param[in]  TIMERx:  Select the timer module
 *
 * @return     none
 *
 *******************************************************************************/
#define TIMER_Run(TIMERx)                   ((TIMERx)->TMRCTL.all |= TMRCTL_ALL_EN_ENABLE)




/****************************************************************************//**
 * @brief      Disable Timer
 *
 * @param[in]  TIMERx:  Select the timer module
 *
 * @return     none
 *
 *******************************************************************************/
#define TIMER_Stop(TIMERx)                  ((TIMERx)->TMRCTL.all &= (~TMRCTL_ALL_EN_ENABLE))




/****************************************************************************//**
 * @brief      Set Timer Re-Load value
 *
 * @param[in]  TIMERxb       :  Select the timer module
 * @param[in]  u32ReloadValue:  Reload value
 *
 * @return     none
 *
 *******************************************************************************/
#define TIMER_SetReloadValue(TIMERx,u32ReloadValue)   ((TIMERx)->TMRRELOAD.all = (u32ReloadValue))




/****************************************************************************//**
 * @brief      Enable Timer interrupt
 *
 * @param[in]  TIMERx:  Select the timer module
 *
 * @return     none
 *
 *******************************************************************************/
#define TIMER_EnableInt(TIMERx)             ((TIMERx)->TMRCTL.all |= TMRCTL_ALL_INTEN_ENABLE)




/****************************************************************************//**
 * @brief      Disable Timer interrupt
 *
 * @param[in]  TIMERx:  Select the timer module
 *
 * @return     none
 *
 *******************************************************************************/
#define TIMER_DisableInt(TIMERx)             ((TIMERx)->TMRCTL.bit.INTEN = TMRCTL_BIT_INTEN_DISABLE)




/****************************************************************************//**
 * @brief      Clear Timer interrupt
 *
 * @param[in]  TIMERx:  Select the timer module
 *
 * @return     none
 *
 *******************************************************************************/
#define TIMER_ClearInt(TIMERx)              ((TIMERx)->TMRIF.all = TMRIF_ALL_INT_OCCUR)




/****************************************************************************//**
 * @brief      Get Timer interrupt flag
 *
 * @param[in]  TIMERx:  Select the timer module
 *
 * @return     none
 *
 *******************************************************************************/
#define TIMER_GetIntFlag(TIMERx)            ((TIMERx)->TMRIF.bit.INT)




/**
 *  @brief  TIMER Public Function Declaration
 */
void TIMER_Init(TIMER_REGS* TIMERx, uint32_t u32TimerPeriodMs);


#ifdef __cplusplus
}
#endif /* extern "C" */

#endif /* TIMER_H */


/******************* (C) COPYRIGHT 2021 SPINTROL LIMITED CO. *****END OF FILE****/
