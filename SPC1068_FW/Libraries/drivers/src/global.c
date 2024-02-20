/**************************************************************************//**
 * @file     global.c
 * @brief    This file provides GLOBAL firmware functions.
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

#include "global.h"




/****************************************************************************//**
 * @brief      Set ECAP input pin
 *
 * @param[in]  ePinNum:  Select the GPIO pin
 *                       See GPIO_PinEnum for details
 *
 * @return     none
 *
 *******************************************************************************/
void GLOBAL_SetECAPInputPin(GPIO_PinEnum ePin)
{
  /* Set Pin as GPIO function */
  GPIO_SetPinAsGPIO(ePin);
  
  /* Select ECAP event source pin */
  GLOBAL->GPIOMISC.bit.ECAPSEL = (ePin + 1);
}


/******************* (C) COPYRIGHT 2021 SPINTROL LIMITED CO. *****END OF FILE****/
