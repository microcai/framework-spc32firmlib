/**************************************************************************//**
 * @file     wdt.c
 * @brief    This file provides Watch Dog firmware functions.
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

#include "wdt.h"




/****************************************************************************//**
 * @brief      Initialize the Watchdog Timer
 *
 * @param[in]  WDTx     :  Select the watchdog module
 * @param[in]  u32TimeMs:  Watchdog timeout in ms
 *
 * @return     none
 *
 *******************************************************************************/
void WDT_Init(WDT_REGS* WDTx, uint32_t u32TimeMs)
{
  uint32_t u32WdtClk;
  
  /* Check WDT lock status */
  if(WDTx->WDTLOCK.all == WDTLOCK_ALL_LCKSTS_LOCK)
  {
    /* Writing a value of 0x1ACCE551 enables write access to all other registers */
    WDTx->WDTLOCK.all = 0x1ACCE551;
  }
  
  /* Enable and Get WDT module clock */
  if(WDTx == WDT0)
  {
    CLOCK_EnableModule(WDT0_MODULE);
    
    u32WdtClk = CLOCK_GetModuleClk(WDT0_MODULE);
  }
  else
  {
    CLOCK_EnableModule(WDT1_MODULE);
    
    u32WdtClk = CLOCK_GetModuleClk(WDT1_MODULE);
  }

  /* Watchdog load register value */
  WDTx->WDTLOAD.all = u32WdtClk / 1000 * u32TimeMs;

  /* Watchdog reset output enable */
  WDTx->WDTCTL.all |= WDTCTL_ALL_RSTEN_ENABLE;

  /* Watchdog counter and interrupt enable */
//  WDTx->WDTCTL.all |= WDTCTL_ALL_INTEN_ENABLE;
}


/******************* (C) COPYRIGHT 2021 SPINTROL LIMITED CO. *****END OF FILE****/
