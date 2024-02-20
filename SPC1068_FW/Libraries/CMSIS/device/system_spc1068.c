/**************************************************************************//**
 * @file     system_spc1068.c
 * @brief    CMSIS Device System Source File for SPC1068 Device Series
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


#include "spc1068.h"



/**
 *  @brief  ADC Calibration Gain
 */
#define ADC_CALIBRATION_GAIN      (36690)




/**
 *  @brief  ADC Calibration Gain for 3.3V recalibration
 */
#define ADC_CALIBRATION_GAIN_3V3  ((uint32_t)(((float)ADC_CALIBRATION_GAIN)*3.65/3.3))




/**
 *  @brief  Define clocks
 */
#define __SYSTEM_CLOCK            (24000000UL)




/**
 *  @brief  System Core Clock Variable
 */
uint32_t SystemCoreClock = __SYSTEM_CLOCK;    /* System Core Clock Frequency      */



/**
 *  @brief  System Information Data Variable
 */
SysInfoStruct SysInfo;




/**
 * Update SystemCoreClock variable
 *
 * @param  none
 * @return none
 *
 * @brief  Updates the SystemCoreClock with current core Clock
 *         retrieved from cpu registers.
 */
void SystemCoreClockUpdate(void)
{
  SystemCoreClock = __SYSTEM_CLOCK;
}




/******************************************************************************
 * @brief      Initialize the system
 *
 * @param[in]  none
 *
 * @return     none
 *
 *******************************************************************************/
void SystemInit(void)
{

#ifdef UNALIGNED_SUPPORT_DISABLE
  SCB->CCR |= SCB_CCR_UNALIGN_TRP_Msk;
#endif

  SystemCoreClock = __SYSTEM_CLOCK;
  
  /* Set VECTOR Table Offset */
  SCB->VTOR = 0x1FFF8000;
  
  /* Disable IPs Clock */
  CLOCK_DisableAllModule();
}




/******************************************************************************
 * @brief      Initializes the register from OTP flash
 *
 * @param[in]  none
 *
 * @return     none
 *
 *******************************************************************************/
void Sys_Init(void)
{
  /* Read OTP information data */
  CLOCK_EnableModule(QSPI_MODULE);
  FLASH_ReadOTP((uint8_t *)(&SysInfo.myOTPInfo), 0x1000, sizeof(OTPInfoStruct));
  
  /* Init power related parameter */
  POWER->LDOCTL.bit.VREFSEL   = SysInfo.myOTPInfo.LDOCTL_VREFSEL;
  POWER->BODCTL.bit.VREFSEL   = SysInfo.myOTPInfo.BODCTL_VREFSEL;

  /* Init clock related parameter */
  CLOCK->CPREGCTL.bit.VREFSEL = SysInfo.myOTPInfo.CPREGCTL_VREFSEL;
  CLOCK->RCO0CTL.bit.TEMPTRIM = SysInfo.myOTPInfo.RCO0CTL_TEMPTRIM;
  CLOCK->RCO1CTL.bit.TEMPTRIM = SysInfo.myOTPInfo.RCO1CTL_TEMPTRIM;
  
  CLOCK->RCO0CTL.bit.MODE     = (SysInfo.myOTPInfo.RCO0CTL_FREQTRIM_LDO > 511)? (1) : (0);
  CLOCK->RCO0CTL.bit.FREQTRIM = SysInfo.myOTPInfo.RCO0CTL_FREQTRIM_LDO & 511;
  
  CLOCK->RCO1CTL.bit.MODE     = (SysInfo.myOTPInfo.RCO1CTL_FREQTRIM_LDO > 511)? (1) : (0);
  CLOCK->RCO1CTL.bit.FREQTRIM = SysInfo.myOTPInfo.RCO1CTL_FREQTRIM_LDO & 511;

  /* Calculate ADC SHA Gain and Offset */
  SysInfo.i32SHAGain    = (((int32_t)(SysInfo.myOTPInfo.ADCGAINTRIM_SHAGAIN)) * (ADC_CALIBRATION_GAIN))>>15;
  SysInfo.i16SHAOffset  = SysInfo.myOTPInfo.ADCOFFSETTRIM_SHAOFFSET - 4351;
  SysInfo.i32SHAGain3V3 = (((int32_t)(SysInfo.myOTPInfo.ADCGAINTRIM_SHAGAIN)) * (ADC_CALIBRATION_GAIN_3V3))>>15;
  
  /* External Osc */
  CLOCK->XOCTL.bit.PRECNT     = 255;
}


/******************* (C) COPYRIGHT 2021 SPINTROL LIMITED CO. *****END OF FILE****/
