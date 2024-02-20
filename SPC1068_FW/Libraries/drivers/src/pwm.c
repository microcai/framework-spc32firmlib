/**************************************************************************//**
 * @file     pwm.c
 * @brief    This file provides PWM firmware functions.
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

#include "pwm.h"




/****************************************************************************//**
 * @brief      Initializes PWM complementary pair channel/ PWMxA and PWMxB
 *
 * @param[in]  PWMx         :  Select the PWM module (PWM0~PWM6)
 * @param[in]  u32PWMFreqHz :  PWM output waveform frequency (Hz)
 * @param[in]  u32DeadTimeNs:  Dead time (ns)
 *
 * @return     none
 *
 *******************************************************************************/
void PWM_ComplementaryPairChannelInit(PWM_REGS* PWMx, uint32_t u32PWMFreqHz, uint32_t u32DeadTimeNs)
{
  uint32_t u32DeadTimeClk;
  uint32_t u32PWMPeriod;
  
  /* Enable PWMx clock */
  CLOCK_EnablePWMModule(PWMx);
  
  /*  PWM initial step */
  /*  Step 1: Set PWM frequency and dead time */
  u32PWMPeriod   = ((CLOCK_GetPWMModuleClk(PWMx))/u32PWMFreqHz)/2;
  u32DeadTimeClk = ((u32DeadTimeNs*((CLOCK_GetPWMModuleClk(PWMx))/100000))/10000);
  
  
  /*  Step 2: Enable EPWM clock and clock prescale*/
  PWMx->TBCTL.all   = 0;  //Reset TBCTL
  PWMx->TBCTL.all  |= TBCTL_ALL_TBCLKDIV_1;


  /*  Step 3: PWM clock and counter synchronization config  */
  /*  Step 3.1: Set PWM freq, counter type(count up-down as center alignment ) */
  PWMx->TBPRD.all   = u32PWMPeriod;                             /* PWM frequency setting */
  //PWMx->TBCTL.all  |= TBCTL_ALL_CNTMODE_COUNT_UP_DOWN_AND_RUN;  /* center alignment and PWM counter start to run */

  /*  Step 3.2: PWM module sync setting
      PWM1~PWM5 are all sync with PWM0
  */
  PWMx->TBCTL.all |=   TBCTL_ALL_SYNCOSEL_TBCNT_EQU_ZERO         // Generate sync signal when Zero point
                     | TBCTL_ALL_PHSEN_ENABLE
                     | TBCTL_ALL_PHSDIR_COUNT_UP_AFTER_SYNC;
  
  PWMx->TBPHS.all = 3;

  /*  Step 4: Set PWM output waveform, central alignment and CMPA with duty are propotional  */
  PWMx->AQCTLA.all |=  AQCTLA_ALL_ZRO_SET_LOW 
                      |AQCTLA_ALL_CAU_SET_HIGH      // PWM_AQCTLA_ALL_CAU_SET_LOW
                      |AQCTLA_ALL_PRD_DO_NOTHING   
                      |AQCTLA_ALL_CAD_SET_LOW;      // PWM_AQCTLA_ALL_CAD_SET_HIGH

  /*  Step 5: Set duty reload timing, Shadow mode and reload on period point  */
  PWMx->CMPCTL.all |=  CMPCTL_ALL_SHDWAMODE_SHADOW_MODE
                      |CMPCTL_ALL_SHDWBMODE_SHADOW_MODE
                      |CMPCTL_ALL_LOADAMODE_LOAD_ON_ZERO
                      |CMPCTL_ALL_LOADBMODE_LOAD_ON_ZERO
                      |CMPCTL_ALL_ADVCMPA_ADVANCED_MODE
                      |CMPCTL_ALL_ADVCMPB_ADVANCED_MODE;

  /* Step 6: Waveform generating with Dead-time */
  PWMx->DBCTL.all |=   DBCTL_ALL_INMODE_0 
                     | DBCTL_ALL_POLSEL_MODE_AHL       // PWM_DBCTL_ALL_POLSEL_MODE_ALH // Active High complementary.
                     | DBCTL_ALL_OUTMODE_3             // PWMxA and PWMxB are all from dead band generator. Please read datasheet for detail.
                     | DBCTL_ALL_HALFCYCLE_DISABLE;
                     
  PWMx->DBFED.all  = u32DeadTimeClk;       // Dead time width
  PWMx->DBRED.all  = u32DeadTimeClk;

  /*  Config PWM clock stop mode */
  PWMx->TBCTL.all |= (TBCTL_ALL_DBGRUN_STOP_AFTER_CYCLE );   //If PWM clock stop, stop at next clock.
}




/****************************************************************************//**
 * @brief      Initializes PWM single channel
 *             Example : Enable PWM0A or PWM3B
 *             Note    : This function only intial PWM control logic but not Pin
 *
 * @param[in]  PWMx        :  Select the PWM module (PWM0~PWM6)
 * @param[in]  ePWM_CH     :  PWM channel selection (PWM_CHA or PWM_CHB)
 * @param[in]  u32PWMFreqHz:  PWM output waveform frequency (Hz)
 *  
 * @return     none
 *
 *******************************************************************************/
void PWM_SingleChannelInit(PWM_REGS* PWMx, PWM_ChannelEnum ePWM_CH, uint32_t u32PWMFreqHz)
{
  uint32_t u3232PWMPeriod;
  
  /* Enable PWMx clock */
  CLOCK_EnablePWMModule(PWMx);
  
  /*  PWM initial step */
  /*  Step 1: Set PWM frequency and dead time */
  u3232PWMPeriod   = ((CLOCK_GetPWMModuleClk(PWMx))/u32PWMFreqHz)/2;
  
  /*  Step 3: Enable EPWM clock	and clock prescale*/
  PWMx->TBCTL.all   = 0;  //Reset TBCTL
  PWMx->TBCTL.all  |= TBCTL_ALL_TBCLKDIV_1;


  /*  Step 4: PWM clock and counter synchronization config  */

  /*  Step 4.1: Set PWM freq, counter type(count up-down as center alignment ) */
  PWMx->TBPRD.all   = u3232PWMPeriod;                      // PWM frequency setting
  //PWMx->TBCTL.all  |= TBCTL_ALL_CNTMODE_COUNT_UP_DOWN_AND_RUN; // center alignment and PWM counter start to run

  /* Step 4.2: PWM module sync setting
     PWM1~PWM5 are all sync with PWM0
  */

  /*  Step 5: Set PWM output waveform, central alignment and CMPA with duty are propotional  */
  if(ePWM_CH==PWM_CHA)
  {
    PWMx->AQCTLA.all  =  AQCTLA_ALL_ZRO_SET_LOW       /* Do not change output while counter reaches zero  */
                        |AQCTLA_ALL_CAU_SET_HIGH 
                        |AQCTLA_ALL_PRD_DO_NOTHING 
                        |AQCTLA_ALL_CAD_SET_LOW;
  }
  else
  {
    PWMx->AQCTLB.all  =  AQCTLA_ALL_ZRO_SET_LOW       /* Do not change output while counter reaches zero  */
                        |AQCTLA_ALL_CBU_SET_HIGH 
                        |AQCTLA_ALL_PRD_DO_NOTHING 
                        |AQCTLA_ALL_CBD_SET_LOW;
  }

  /*  Step 6: Set PWMA and PWMB are complementary mode, dead time is 500ns    */


  /*  Step 7: Set duty reload timing, Shadow mode and reload on period point  */
  PWMx->CMPCTL.all |=  CMPCTL_ALL_SHDWAMODE_SHADOW_MODE 
                      |CMPCTL_ALL_SHDWBMODE_SHADOW_MODE 
                      |CMPCTL_ALL_LOADAMODE_LOAD_ON_ZERO 
                      |CMPCTL_ALL_LOADBMODE_LOAD_ON_ZERO 
                      |CMPCTL_ALL_ADVCMPA_ADVANCED_MODE 
                      |CMPCTL_ALL_ADVCMPB_ADVANCED_MODE;
    
  /*  Config PWM clock stop mode  */
  PWMx->TBCTL.all |= (TBCTL_ALL_DBGRUN_STOP_AFTER_CYCLE );   //If PWM clock stop, stop at next clock.
}




/****************************************************************************//**
 * @brief      Initializes comparator trip zone one-shot function
 *
 * @param[in]  PWMx :  Select the PWM module (PWM0~PWM6)
 * @param[in]  eCOMP:  Select the comparator module
 *                     Please goto COMP_ComparatorSelEnum for selection
 *                      - \ref COMP_0_LO
 *                      - \ref COMP_1_LO
 *                      - \ref COMP_2_LO
 *                      - \ref COMP_0_HI
 *                      - \ref COMP_1_HI
 *                      - \ref COMP_2_HI
 * @return     none
 *
 * @example    PWM_EnableOneShotTripFromComp(PWM0,COMP_0_HI);
 *             PWM0 CHA and CHB will be triped (tristate by default) when COMP0H is 1
 *
 * @note       PWM output will be tri-state(high impedence) when trip by default
 *
 *******************************************************************************/
void PWM_EnableOneShotTripFromComp(PWM_REGS* pPWM, uint8_t eCOMP)
{
  pPWM->TZSEL.all |= ((TZSEL_ALL_OSHTCOMP0H_ENABLE)<<(PWM_GetTripSelCompIndex(eCOMP)));
}




/****************************************************************************//**
 * @brief      Initializes TZx trip zone one-shot function
 *             Note: This function will auto configure pin as GPIO input
 *
 * @param[in]  PWMx   :  Select the PWM module (PWM0~PWM6)
 * @param[in]  ePinNum:  Select GPIO pin for TZx
 *                       Please goto GPIO_PinEnum for selection
 *  
 * @return     none
 *
 * @example    PWM_SetOneshotTripFromExtPin(PWM0,GPIO_9);
 *
 * @note       PWM output will be tri-state(high impedence) when trip by default
 *
 *******************************************************************************/
void PWM_SetOneshotTripFromExtPin(PWM_REGS* pPWM, GPIO_PinEnum ePinNum)
{
  uint32_t u32TZn;
  uint32_t u32BitPattern;
  uint32_t u32TZSELShift;

  /* Set Pin as GPIO */
  GPIO_SetPinAsGPIO(ePinNum);
  GPIO_SetPinDir(ePinNum, GPIO_INPUT);

  /* Calculate parameter */
  u32TZn=(ePinNum%5);
  u32TZSELShift=(u32TZn)*3;
  u32BitPattern=(ePinNum/5)+1;

  /* Select GPIO to TZx */
  GLOBAL->GPIOMISC.all = (GLOBAL->GPIOMISC.all&(~(GPIOMISC_ALL_TZ1SEL_Msk<<u32TZSELShift)))|(u32BitPattern<<u32TZSELShift);

  /* Enable oneshot in PWM*/
  pPWM->TZSEL.all    |= (TZSEL_ALL_OSHT1_ENABLE<<u32TZn); 

  pPWM->TZIE.bit.OST = TZIE_BIT_OST_ENABLE;
}


/******************* (C) COPYRIGHT 2021 SPINTROL LIMITED CO. *****END OF FILE****/
