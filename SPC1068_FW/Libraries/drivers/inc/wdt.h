/**************************************************************************//**
 * @file     wdt.h
 * @brief    Watch Dog driver module header file.
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

#ifndef WDT_H
#define WDT_H

#ifdef __cplusplus
extern "C" {
#endif


#include "spc1068.h"




/****************************************************************************//**
 * @brief      Start watchdog counter 
 *
 * @param[in]  WDTx:  Select the watchdog module
 *
 * @return     none
 *
 *******************************************************************************/
#define WDT_Run(WDTx)                       ((WDTx)->WDTCTL.all |= WDTCTL_ALL_INTEN_ENABLE)




/****************************************************************************//**
 * @brief      Enable watchdog interrupt and the counter
 *
 * @param[in]  WDTx:  Select the watchdog module
 *
 * @return     none
 *
 *******************************************************************************/
#define WDT_EnableInt(WDTx)                 ((WDTx)->WDTCTL.all |= WDTCTL_ALL_INTEN_ENABLE)




/****************************************************************************//**
 * @brief      Disable watchdog interrupt and the counter
 *
 * @param[in]  WDTx:  Select the watchdog module
 *
 * @return     none
 *
 *******************************************************************************/
#define WDT_DisableInt(WDTx)                ((WDTx)->WDTCTL.bit.INTEN = 0)




/****************************************************************************//**
 * @brief      Enable watchdog system reset request
 *
 * @param[in]  WDTx:  Select the watchdog module
 *
 * @return     none
 *
 *******************************************************************************/
#define WDT_EnableSystemReset(WDTx)         ((WDTx)->WDTCTL.all |= WDTCTL_ALL_RSTEN_ENABLE)




/****************************************************************************//**
 * @brief      Disable watchdog reset system request
 *
 * @param[in]  WDTx:  Select the watchdog module
 *
 * @return     none
 *
 *******************************************************************************/
#define WDT_DisableSystemReset(WDTx)        ((WDTx)->WDTCTL.bit.RSTEN = 0)




/****************************************************************************//**
 * @brief      Set watchdog load register value(feed dog)
 *
 * @param[in]  WDTx:  Select the watchdog module
 * @param[in]  u32LoadVal:  Watchdog load register value
 *
 * @return     none
 *
 *******************************************************************************/
#define WDT_SetLoadVal(WDTx,u32LoadVal)     ((WDTx)->WDTLOAD.all = (u32LoadVal))




/****************************************************************************//**
 * @brief      Get watchdog lock status 
 *
 * @param[in]  WDTx:  Select the watchdog module
 *
 * @return     0 : write access to all other registers is enabled (not locked)
 *             1 : write access to all other registers is disabled (locked)
 *
 *******************************************************************************/
#define WDT_GetLockStatus(WDTx)             ((WDTx)->WDTLOCK.all)




/****************************************************************************//**
 * @brief      Get watchdog raw interrupt status
 *
 * @param[in]  WDTx:  Select the watchdog module
 *
 * @return     0 : Interrupt not occurred
 *             1 : Interrupt occurred
 *
 *******************************************************************************/
#define WDT_GetRawIntFlag(WDTx)             ((WDTx)->WDTRAWIF.bit.RAWINT)




/****************************************************************************//**
 * @brief      Get watchdog interrupt status
 *
 * @param[in]  WDTx:  Select the watchdog module
 *
 * @return     0 : Interrupt not occurred
 *             1 : Interrupt occurred
 *
 *******************************************************************************/
#define WDT_GetIntFlag(WDTx)                ((WDTx)->WDTIF.bit.INT)




/****************************************************************************//**
 * @brief      Clear watchdog interrupt flag
 *             A write of any value to the WDTIC register clears the watchdog 
 *             interrupt, and reloads the counter from the value in WDTLOAD
 *
 * @param[in]  WDTx:  Select the watchdog module
 *
 * @return     none
 * 
 *******************************************************************************/
#define WDT_ClearInt(WDTx)                  ((WDTx)->WDTIC.all = 0x0)




/****************************************************************************//**
 * @brief      Feed dog
 *             A write of any value to the WDTIC register clears the watchdog 
 *             interrupt, and reloads the counter from the value in WDTLOAD
 *
 * @param[in]  WDTx:  Select the watchdog module
 *
 * @return     none
 * 
 *******************************************************************************/
#define WDT_FeedDog(WDTx)                   ((WDTx)->WDTIC.all = 0x0)




/**
 *  @brief Watchdog Public Function Declaration
 */
void WDT_Init(WDT_REGS* WDTx, uint32_t u32TimeMs);


#ifdef __cplusplus
}
#endif /* extern "C" */

#endif /* WDT_H */


/******************* (C) COPYRIGHT 2021 SPINTROL LIMITED CO. *****END OF FILE****/
