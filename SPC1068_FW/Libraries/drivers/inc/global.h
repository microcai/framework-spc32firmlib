/*******************************************************************************
* @file     global.h
* @brief    GLOBAL driver header file.
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


#ifndef GLOBAL_H
#define GLOBAL_H

#ifdef __cplusplus
extern "C" {
#endif


#include "spc1068.h"




/****************************************************************************//**
 * @brief      Enable ROM parity check
 *
 * @param[in]  none
 *
 * @return     none
 *
 *******************************************************************************/
#define GLOBAL_RomParityCheckEnable()       (GLOBAL->MEMPCE.all |= (MEMPCE_ALL_ROMPCE_ENABLE | MEMPCE_ALL_GLBPCE_ENABLE))




/****************************************************************************//**
 * @brief      Enable 16KB SRAM parity check
 *
 * @param[in]  none
 *
 * @return     none
 *
 *******************************************************************************/
#define GLOBAL_Ram16KParityCheckEnable()    (GLOBAL->MEMPCE.all |= (MEMPCE_ALL_RAM16KPCE_ENABLE | MEMPCE_ALL_GLBPCE_ENABLE))




/****************************************************************************//**
 * @brief      Enable 32KB SRAM parity check
 *
 * @param[in]  none
 *
 * @return     none
 *
 *******************************************************************************/
#define GLOBAL_Ram32KParityCheckEnable()    (GLOBAL->MEMPCE.all |= (MEMPCE_ALL_RAM32KPCE_ENABLE | MEMPCE_ALL_GLBPCE_ENABLE))




/****************************************************************************//**
 * @brief      Force PWM synchronization
 *
 * @param[in]  u32PwmSyncMsk:  PWM sychronization mask value
 *                             - \ref PWMFRCSYNC_ALL_PWMxSYNC_ENABLE(x = 0 ~ 6)
 *
 * @return     none
 *
 * @example    GLOBAL_ForcePwmSync(PWMFRCSYNC_ALL_PWM0SYNC_ENABLE);
 *             GLOBAL_ForcePwmSync(PWMFRCSYNC_ALL_PWM0SYNC_ENABLE | PWMFRCSYNC_ALL_PWM1SYNC_ENABLE);
 *
 *******************************************************************************/
#define GLOBAL_ForcePwmSync(u32PwmSyncVal)  (GLOBAL->PWMFRCSYNC.all |= (u32PwmSyncVal))




/**
 *  @brief Global Public Function Declaration
 */
void GLOBAL_SetECAPInputPin(GPIO_PinEnum ePin);


#ifdef __cplusplus
}
#endif /* extern "C" */

#endif /* GLOBAL_H */


/******************* (C) COPYRIGHT 2021 SPINTROL LIMITED CO. *****END OF FILE****/
