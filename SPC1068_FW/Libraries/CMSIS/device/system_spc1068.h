/**************************************************************************//**
 * @file     system_spc1068.h
 * @brief    CMSIS Device System Header File for SPC1068 Device Series
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


#ifndef SYSTEM_SPC1068_H
#define SYSTEM_SPC1068_H

#ifdef __cplusplus
extern "C" {
#endif




/**
 *  @brief  System Clock Frequency (Core Clock)
 */
extern uint32_t SystemCoreClock;




/**
 *  @brief  OTP Data Structure Declaration
 */
typedef struct
{
  uint32_t RESERVED0;
  uint8_t  LDOCTL_VREFSEL;                  /*!<                          */
  uint8_t  CPREGCTL_VREFSEL;                /*!<                          */
  uint8_t  RCO0CTL_TEMPTRIM;                /*!<                          */
  uint8_t  RCO1CTL_TEMPTRIM;                /*!<                          */
  uint16_t RCO0CTL_FREQTRIM_LDO;            /*!<                          */
  uint16_t RCO0CTL_FREQTRIM_CPREG;          /*!<                          */
  uint16_t RCO1CTL_FREQTRIM_LDO;            /*!<                          */
  uint16_t RCO1CTL_FREQTRIM_CPREG;          /*!<                          */
  uint8_t  ADCTRIM_VREGBLEEDTRIM;           /*!< VDDR12_DIG               */
  uint8_t  ADCTRIM_VREFTRIM;                /*!< VREFOUT12                */
  uint8_t  ADCTRIM_VREGTRIM;                /*!< VDDR12_ANA               */
  uint8_t  RESERVED1;
  uint16_t ADCGAINTRIM_SHBGAIN;             /*!<                          */
  uint16_t ADCGAINTRIM_SHAGAIN;             /*!<                          */
  uint16_t ADCOFFSETTRIM_SHBOFFSET;         /*!<                          */
  uint16_t ADCOFFSETTRIM_SHAOFFSET;         /*!<                          */
  uint8_t  BODCTL_VREFSEL;                  /*!<                          */
} OTPInfoStruct;




/**
 *  @brief  System Information Structure Declaration
 */
typedef struct
{
  OTPInfoStruct myOTPInfo;                  /*!< Data Information in OTP  */
  int16_t  i16SHAOffset;                    /*!< ADC SHA Offset           */
  int32_t  i32SHAGain;                      /*!< ADC SHA Gain             */
  int32_t  i32SHAGain3V3;                   /*!< ADC SHA Gain for 3.3V    */
  uint32_t u32HCLK;                         /*!< HCLK(CPU Core) Frequency */
  uint32_t u32PCLK;                         /*!< PCLK Frequency           */
  uint32_t u32CLK0;                         /*!< RCO0 Clock Frequency     */
  uint32_t u32CLK1;                         /*!< RCO1 Clock Frequency     */
} SysInfoStruct;




/**
 *  @brief  System information data
 */
extern SysInfoStruct SysInfo;




/******************************************************************************
 * @brief      Initialize the system
 *             Setup the microcontroller system
 *
 * @param[in]  none
 *
 * @return     none
 *
 *******************************************************************************/
extern void SystemInit(void);




/******************************************************************************
 * @brief      Update SystemCoreClock variable
 *             Updates the SystemCoreClock with current core Clock retrieved 
 *             from cpu registers
 *
 * @param[in]  none
 *
 * @return     none
 *
 *******************************************************************************/
extern void SystemCoreClockUpdate(void);




/******************************************************************************
 * @brief      Initialize SPC1068
 *             Updates SPC1068 related register value from OTP data
 *
 * @param[in]  none
 *
 * @return     none
 *
 *******************************************************************************/
extern void Sys_Init(void);


#ifdef __cplusplus
}
#endif

#endif /* SYSTEM_SPC1068_H */

/******************* (C) COPYRIGHT 2021 SPINTROL LIMITED CO. *****END OF FILE****/
