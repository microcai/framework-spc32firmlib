/**************************************************************************//**
 * @file     ecap.c
 * @brief    This file provides eCAP firmware functions.
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

#include "ecap.h"




/****************************************************************************//**
 * @brief      Initializes the ECAP module operating in capture mode
 *
 * @param[in]  ECAPx  :  Select the ECAP module
 * @param[in]  ePinNum:  Select the GPIO pin as capture input
 *
 * @return     none
 *
 *******************************************************************************/
void ECAP_CaptureModeInit(ECAP_REGS* ECAPx, GPIO_PinEnum ePinNum)
{
  /* Config IO Pin for capture */
  GLOBAL_SetECAPInputPin(ePinNum);
  
  /* Open ECAP clock */
  CLOCK_EnableModule(ECAP_MODULE);
  
  ECAPx->CAPCTL.all =   CAPCTL_ALL_CAPAPWM_CAPTURE_MODE             /* Config ECAP as Capture mode                */
                      | CAPCTL_ALL_CAPLDEN_CAPTURE_LOAD_ENABLE      /* Enable Capture Register load               */
                      | CAPCTL_ALL_STOPWRAP_ON_CAPTURE_EVENT3       /* Stop/Wrap after Capture Event 3            */
                      | CAPCTL_ALL_MODE_CONTINOUS_MODE              /* Operate in Continous mode                  */
                      | CAPCTL_ALL_CAP0POL_TRIG_ON_RISING_EDGE      /* Event 0 occurs on pulse rising edge        */
                      | CAPCTL_ALL_CAP1POL_TRIG_ON_FALLING_EDGE     /* Event 1 occurs on pulse falling edge       */
                      | CAPCTL_ALL_CAP2POL_TRIG_ON_RISING_EDGE      /* Event 2 occurs on pulse rising edge        */
                      | CAPCTL_ALL_CAP3POL_TRIG_ON_FALLING_EDGE     /* Event 3 occurs on pulse falling edge       */
                      | CAPCTL_ALL_CNTRST0_RESET_ON_CAPTURE         /* Reset capture counter when Event 0 occurs  */
                      | CAPCTL_ALL_CNTRST1_RESET_ON_CAPTURE         /* Reset capture counter when Event 1 occurs  */
                      | CAPCTL_ALL_CNTRST2_RESET_ON_CAPTURE         /* Reset capture counter when Event 2 occurs  */
                      | CAPCTL_ALL_CNTRST3_RESET_ON_CAPTURE         /* Reset capture counter when Event 3 occurs  */
                      | CAPCTL_ALL_TSCNTRUN_START_COUNTER;          /* Enable ECAP working                        */

  /* Enable Capture event interrupt */
  ECAPx->CAPIEIF.all |= CAPIEIF_ALL_IECEVT0_ENABLE | 
                        CAPIEIF_ALL_IECEVT1_ENABLE | 
                        CAPIEIF_ALL_IECEVT2_ENABLE | 
                        CAPIEIF_ALL_IECEVT3_ENABLE ;

  /* If you do NOT want to lose any pulse information, please use interrupt type */
  // NVIC_EnableIRQ(ECAP_IRQn);
}




/****************************************************************************//**
 * @brief      Initializes the ECAP module operating in APWM mode
 *
 * @param[in]  ECAPx     :  Select the ECAP module
 * @param[in]  ePinNum   :  Select GPIO pin for output PWM
 * @param[in]  u32PwmFreq:  Define the frequency of PWM
 *                          This function will calculate period automaticlly
 *
 * @return     none
 *
 *******************************************************************************/
void ECAP_APwmModeInit(ECAP_REGS* ECAPx, GPIO_PinEnum ePinNum, uint32_t u32PwmFreq)
{
  /* Config ECAP APWM pin */
  GPIO_SetPinChannel(ePinNum, PINMUX_CHANNEL_7);
  
  /* Config ECAP operating mode */
  ECAPx->CAPCTL.bit.CAPAPWM = CAPCTL_BIT_CAPAPWM_APWM_MODE;
  
  /* Calculate Period Value based on system clock, ECAP clock and PWM frequency*/
  ECAPx->CAP0.all = CLOCK_GetModuleClk(ECAP_MODULE)/u32PwmFreq;
}




/****************************************************************************//**
 * @brief      Set the duty of PWM waveform
 *
 * @param[in]  u32PwmDuty:  Define the duty of PWM
 *                          PWM duty = u32PwmDuty/10000  (00.00% ~ 100.00%)
 *
 * @return     none
 *
 *******************************************************************************/
void ECAP_APwmSetDuty(ECAP_REGS* ECAPx, uint32_t u32PwmDuty)
{
  if(u32PwmDuty == 10000)
  {
    ECAPx->CAP1.all = ECAPx->CAP0.all;
  }
  else
  {
    ECAPx->CAP1.all = (ECAPx->CAP0.all / 10000) * u32PwmDuty;
  }
}


/******************* (C) COPYRIGHT 2021 SPINTROL LIMITED CO. *****END OF FILE****/
