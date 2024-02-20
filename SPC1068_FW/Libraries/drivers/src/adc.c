/**************************************************************************//**
 * @file     adc.c
 * @brief    This file provides ADC firmware functions.
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
 
#include "adc.h"
#include <stdio.h>




/****************************************************************************//**
 * @brief      ADC power up
 *
 * @param[in]  none
 *
 * @return     none
 *
 * @note       Need to call it before using ADC
 *
 *******************************************************************************/
void ADC_PowerUP(void)
{
  /* Enable ADC Module Clock */
  CLOCK_EnableModule(ADC_MODULE);
  
  /* Enable ADC Bandgap */
  POWER->BGCTL.bit.ADCBGDIS = BGCTL_BIT_ADCBGDIS_ENABLE_ADC_BANDGAP;
  
  ADC->ADCCTL0.bit.VREFEN = ADCCTL0_BIT_VREFEN_ENABLE_REF_BUFF;
  ADC->ADCCTL0.bit.EN     = ADCCTL0_BIT_EN_ENABLE_ADC;
  
  /* Init ADC related parameter */
  ADC->ADCTRIM.bit.VREGBLEEDTRIM    = SysInfo.myOTPInfo.ADCTRIM_VREGBLEEDTRIM;
  ADC->ADCTRIM.bit.VREFTRIM         = SysInfo.myOTPInfo.ADCTRIM_VREFTRIM;
  ADC->ADCTRIM.bit.VREGTRIM         = SysInfo.myOTPInfo.ADCTRIM_VREGTRIM;
  ADC->ADCGAINTRIM.bit.SHBGAIN      = SysInfo.myOTPInfo.ADCGAINTRIM_SHBGAIN;
  ADC->ADCGAINTRIM.bit.SHAGAIN      = SysInfo.myOTPInfo.ADCGAINTRIM_SHAGAIN;
  ADC->ADCOFFSETTRIM.bit.SHBOFFSET  = SysInfo.myOTPInfo.ADCOFFSETTRIM_SHBOFFSET;
  ADC->ADCOFFSETTRIM.bit.SHAOFFSET  = SysInfo.myOTPInfo.ADCOFFSETTRIM_SHAOFFSET;
  ADC->ADCCTL1.bit.COMPPREAMPCTL    = 3;
  ADC->ADCCTL1.bit.DACSETTLECTL     = 1;
  ADC->ADCCTL1.bit.SPEEDUP          = 1;
  ADC->ADCCTL1.bit.DLYSEL           = 0;
}




/****************************************************************************//**
 * @brief      Enable ADC Interrupt
 *
 * @param[in]  u8SOC:  Select SOC to be used from ADC_SocEnum
 *
 * @return     none
 *
 * @note       Please use contant value is its input to reduce code size
 *
 *******************************************************************************/
                               /* SOC: 0   1    2     3      4       5      6       7      8      9     10     11     12     13      14 */
const uint8_t au8IntIndexArray[15] = { 5, 13,5+32,13+32,5+32*2,13+32*2,5+32*3,13+32*3,5+32*4,3+32*4,1+32*4,3+32*3,1+32*3,11+32*3,9+32*3};

void ADC_EnableInt(ADC_SocEnum u8SOC)
{
  if(u8SOC != 15)
  {
    *((uint32_t *)((uint32_t)(&ADC->ADCINTSEL0.all)+((au8IntIndexArray[u8SOC]>>5)<<2))) |= ((BIT0<<(au8IntIndexArray[u8SOC]&0x1f)) | (BIT1<<(au8IntIndexArray[u8SOC]&0x1f))) ;
  }
  else
  {
    ADC_EnableInt15();
  }
}




/****************************************************************************//**
 * @brief      Configure the sample & conversion window size (ns) for SOC
 *
 * @param[in]  u8SOC          :  Select SOC to be used from ADC_SocEnum
 *             u32SampleTimeNs:  Sample window time, no less than 125 ns
 *             u32ConvTimeNs  :  Convert window time
 *
 * @return     none
 *
 *******************************************************************************/
void ADC_SetSampleAndConvTime(ADC_SocEnum u8SOC, uint32_t u32SampleTimeNs, uint32_t u32ConvTimeNs)
{
  uint32_t u32ADCModuleClk,u32SampleTimeCnt,u32ConvTimeCnt;

  u32ADCModuleClk = CLOCK_GetModuleClk(ADC_MODULE);
  
  u32SampleTimeCnt = ((u32ADCModuleClk/100000)*u32SampleTimeNs)/10000;
  u32ConvTimeCnt   = ((u32ADCModuleClk/100000)*u32ConvTimeNs)/10000 + 1;
  
  if(u32SampleTimeCnt >= 127) u32SampleTimeCnt = 127;
  if(u32ConvTimeCnt >= 63)    u32ConvTimeCnt   = 63;
  
  ADC->ADCSOCCTL[u8SOC].bit.SAMPCNT = u32SampleTimeCnt;   /* SAMPCNT is 7-bit length */
  ADC->ADCSOCCTL[u8SOC].bit.CONVCNT = u32ConvTimeCnt;     /* CONVCNT is 6-bit length */
}




/****************************************************************************//**
 * @brief      Select ADC trigger source (PWMxSOCA) according to PWM module
 *
 * @param[in]  PWMx:  PWM module
 *             - \ref PWM0
 *             - \ref PWM1
 *             ...
 *             - \ref PWM6 
 *
 * @return     ADC_TriggerSourceEnum
 *
 *******************************************************************************/
ADC_TriggerSourceEnum ADC_TrigFromPWMxSOCA(PWM_REGS* PWMx)
{
  uint32_t u32PWMModuleNum;
  
  u32PWMModuleNum = (((uint32_t)PWMx)&0x0F00UL)>>8;
  
//  printf("PWM%d TrigSrc=%d\n",u32PWMModuleNum,(ADCTRIG_PWM0A + u32PWMModuleNum*2));
  
  return (ADC_TriggerSourceEnum)(ADCTRIG_PWM0A + u32PWMModuleNum*2);
}




/****************************************************************************//**
 * @brief      Select ADC trigger source (PWMxSOCA) according to PWM module
 *
 * @param[in]  PWMx:  PWM module
 *             - \ref PWM0
 *             - \ref PWM1
 *             ...
 *             - \ref PWM6 
 *
 * @return     ADC_TriggerSourceEnum
 *
 *******************************************************************************/
ADC_TriggerSourceEnum ADC_TrigFromPWMxSOCB(PWM_REGS* PWMx)
{
  uint32_t u32PWMModuleNum;
  
  u32PWMModuleNum = (((uint32_t)PWMx)&0x0F00UL)>>8;
  
//  printf("PWM%d TrigSrc=%d\n",u32PWMModuleNum,(ADCTRIG_PWM0B + u32PWMModuleNum*2));
  
  return (ADC_TriggerSourceEnum)(ADCTRIG_PWM0B + u32PWMModuleNum*2);
}




/****************************************************************************//**
 * @brief      This function is only for single-ended use, that is 
 *             (1) The signal ternimal selected by u8PinSel
 *             (2) The other terminal is internal GND 
 *             (3) Default sampling time is ADC_DEFAULT_SAMPLE_TIME_NS(default 150ns) 
 *                 and conversion time is ADC_DEFAULT_CONVERSION_TIME_NS(default 150ns) 
 *                 Total time = 300ns = 3.33MHz SPS rate
 *             (4) This function will auto-set selected pin as analog pin
 *                 If user select pin outside the range of ADC pin, it will not effect.
 *
 * @param[in]  u8SOC    :  Select SOC to be used (ADC_SOC_0 ~ ADC_SOC_15)
 * @param[in]  u8PinSel :  Select the ADC input pin
 *                         It can be GPIO pin number or Pin defined in adc.h
 *
 *                         GPIO_PinEnum  (Only support ADC pin GPIO1~GPIO16)
 *                          - \ref GPIO_1     -->ADC0 
 *                          - \ref GPIO_2     -->ADC1 
 *                          - \ref GPIO_3     -->ADC2 
 *                          - \ref GPIO_4     -->ADC3 
 *                          - \ref GPIO_5     -->ADC4 
 *                          - \ref GPIO_6     -->ADC5 
 *                          - \ref GPIO_7     -->ADC6 
 *                          - \ref GPIO_8     -->ADC7 
 *                          - \ref GPIO_9     -->ADC8 
 *                          - \ref GPIO_10    -->ADC9 
 *                          - \ref GPIO_11    -->ADC10 
 *                          - \ref GPIO_12    -->ADC11 
 *                          - \ref GPIO_13    -->ADC12 
 *                          - \ref GPIO_14    -->ADC13 
 *                          - \ref GPIO_15    -->ADC14 
 *                          - \ref GPIO_16    -->ADC15 
 *                         Please do NOT use GPIO0, GPIO17 ~ GPIO35!
 *
 *                         If user want to use internal signal like VDD12, please use this type
 *                         ADC_PinSelEnum  
 *                          - \ref ADC0_GPIO1
 *                          - \ref ADC1_GPIO2
 *                          - \ref ADC2_GPIO3
 *                          - \ref ADC3_GPIO4
 *                          - \ref ADC4_GPIO5
 *                          - \ref ADC5_GPIO6
 *                          - \ref ADC6_GPIO7
 *                          - \ref ADC7_GPIO8
 *                          - \ref ADC8_GPIO9
 *                          - \ref ADC9_GPIO10
 *                          - \ref ADC10_GPIO11
 *                          - \ref ADC11_GPIO12
 *                          - \ref ADC12_GPIO13
 *                          - \ref ADC13_GPIO14
 *                          - \ref ADC14_GPIO15
 *                          - \ref ADC15_GPIO16
 *                          - \ref ADCx_PGA0P
 *                          - \ref ADCx_PGA0N
 *                          - \ref ADCx_PGA1P
 *                          - \ref ADCx_PGA1N
 *                          - \ref ADCx_PGA2P
 *                          - \ref ADCx_PGA2N
 *                          - \ref ADCx_TSENSOR_L
 *                          - \ref ADCx_TSENSOR_H
 *                          - \ref ADCx_VDD12     -> Internal 1.2V
 *                          - \ref ADCx_VDDA      -> Internal 3.3V
 * @param[in]  u8TrigSrc:  Select the trigger source
 *                         Please goto ADC_TriggerSourceEnum for detail
 *                          - \ref ADCTRIG_Software
 *                          - \ref ADCTRIG_Timer0
 *                          - \ref ADCTRIG_Timer1
 *                          - \ref ADCTRIG_Timer2
 *                          - \ref ADCTRIG_XINT2
 *                          - \ref ADCTRIG_PWM0A
 *                          - \ref ADCTRIG_PWM0B
 *                          - \ref ADCTRIG_PWM1A
 *                          - \ref ADCTRIG_PWM1B
 *                          - \ref ADCTRIG_PWM2A
 *                          - \ref ADCTRIG_PWM2B
 *                          - \ref ADCTRIG_PWM3A
 *                          - \ref ADCTRIG_PWM3B
 *                          - \ref ADCTRIG_PWM4A
 *                          - \ref ADCTRIG_PWM4B
 *                          - \ref ADCTRIG_PWM5A
 *                          - \ref ADCTRIG_PWM5B
 *                          - \ref ADCTRIG_PWM6A
 *                          - \ref ADCTRIG_PWM6B

 * @return     none
 *
 * @example    (1) Initial SOC1 to get ADC1(GPIO_2) signal with software trigger
 *                 ADC_EasyInit1(ADC_SOC_1,GPIO_2,ADCTRIG_Software);
 *                 or
 *                 ADC_EasyInit1(ADC_SOC_1,ADC1_GPIO2,ADCTRIG_Software);
 *
 *             (2) Initial SOC2 to get internal VDD12 signal with PWM trigger
 *                 ADC_EasyInit1(ADC_SOC_2,ADCx_VDD12,ADCTRIG_PWM0A);
 *
 *             (3) Initial SOC3 to get GPIO5(ADC4) signal with software trigger
 *                 <1> ADC_EasyInit1(ADC_SOC_3,GPIO_5,ADCTRIG_Software);
 *                 <2> Software trigger
 *                     ADC_SoftwareTrigger(ADC_SOC_3);
 *                 <3> Get value when data ready
 *                     ADC_GetTrimResult1(ADC_SOC_3); --> Take longer cpu cycle but accuracy (Recommend)
 *                     
 *                     ADC_GetRawResult(ADC_SOC_3); --> Raw data, user should determine polarity and calibration.
 *
 *******************************************************************************/
void ADC_EasyInit1(ADC_SocEnum u8SOC, uint8_t u8PinSel, ADC_TriggerSourceEnum u8TrigSrc)
{
  ADC_PowerUP();
  
  ADC_SelectPinSingleEnd(u8SOC,u8PinSel,u8TrigSrc);
  
  ADC_SetSampleAndConvTime(u8SOC,ADC_DEFAULT_SAMPLE_TIME_NS,ADC_DEFAULT_CONVERSION_TIME_NS);
  
  ADC_EnableInt(u8SOC);

  GPIO_SetPinAsAnalog((GPIO_PinEnum)u8PinSel);  /* Only GPIO1(ADC0)~GPIO16(ADC15) can be congigured */
}




/****************************************************************************//**
 * @brief      This function is for differential mode, that is
 *             (1) Default sampling time is ADC_DEFAULT_SAMPLE_TIME_NS(default 150ns) 
 *                 and conversion time is ADC_DEFAULT_CONVERSION_TIME_NS(default 150ns) 
 *                 Total time = 300ns = 3.33MHz SPS rate
 *             (2) This function will auto-set selected pin as analog pin
 *                 If user select pin outside the range of ADC pin, it will not effect.
 *
 * @param[in]  u8SOC     :  Select SOC to be used
 * @param[in]  u8PinSel_1:  Select the first terminal ADC pin
 *                          It can be GPIO pin number or Pin defined in adc.h
 *
 *                          GPIO_PinEnum  (Only support ADC pin GPIO1~GPIO16)
 *                           - \ref GPIO_1     -->ADC0 
 *                           - \ref GPIO_2     -->ADC1 
 *                           - \ref GPIO_3     -->ADC2 
 *                           - \ref GPIO_4     -->ADC3 
 *                           - \ref GPIO_5     -->ADC4 
 *                           - \ref GPIO_6     -->ADC5 
 *                           - \ref GPIO_7     -->ADC6 
 *                           - \ref GPIO_8     -->ADC7 
 *                           - \ref GPIO_9     -->ADC8 
 *                           - \ref GPIO_10    -->ADC9 
 *                           - \ref GPIO_11    -->ADC10 
 *                           - \ref GPIO_12    -->ADC11 
 *                           - \ref GPIO_13    -->ADC12 
 *                           - \ref GPIO_14    -->ADC13 
 *                           - \ref GPIO_15    -->ADC14 
 *                           - \ref GPIO_16    -->ADC15 
 *                          Please do NOT use GPIO0, GPIO17~GPIO35!
 *
 *                          If user want to use internal signal like VDD12, please use this type
 *                          ADC_PinSelEnum
 *                           - \ref ADC0_GPIO1
 *                           - \ref ADC1_GPIO2
 *                           - \ref ADC2_GPIO3
 *                           - \ref ADC3_GPIO4
 *                           - \ref ADC4_GPIO5
 *                           - \ref ADC5_GPIO6
 *                           - \ref ADC6_GPIO7
 *                           - \ref ADC7_GPIO8
 *                           - \ref ADC8_GPIO9
 *                           - \ref ADC9_GPIO10
 *                           - \ref ADC10_GPIO11
 *                           - \ref ADC11_GPIO12
 *                           - \ref ADC12_GPIO13
 *                           - \ref ADC13_GPIO14
 *                           - \ref ADC14_GPIO15
 *                           - \ref ADC15_GPIO16
 *                           - \ref ADCx_PGA0P
 *                           - \ref ADCx_PGA0N
 *                           - \ref ADCx_PGA1P
 *                           - \ref ADCx_PGA1N
 *                           - \ref ADCx_PGA2P
 *                           - \ref ADCx_PGA2N
 *                           - \ref ADCx_TSENSOR_L
 *                           - \ref ADCx_TSENSOR_H
 *                           - \ref ADCx_VDD12      -> Internal 1.2V
 *                           - \ref ADCx_VDDA       -> Internal 3.3V
 *
 * @param[in]  u8PinSel_2:  Select the second terminal ADC pin
 * @param[in]  u8TrigSrc :  Select the trigger source
 *                          Please goto ADC_TriggerSourceEnum for detail
 *                           - \ref ADCTRIG_Software
 *                           - \ref ADCTRIG_Timer0
 *                           - \ref ADCTRIG_Timer1
 *                           - \ref ADCTRIG_Timer2
 *                           - \ref ADCTRIG_XINT2
 *                           - \ref ADCTRIG_PWM0A
 *                           - \ref ADCTRIG_PWM0B
 *                           - \ref ADCTRIG_PWM1A
 *                           - \ref ADCTRIG_PWM1B
 *                           - \ref ADCTRIG_PWM2A
 *                           - \ref ADCTRIG_PWM2B
 *                           - \ref ADCTRIG_PWM3A
 *                           - \ref ADCTRIG_PWM3B
 *                           - \ref ADCTRIG_PWM4A
 *                           - \ref ADCTRIG_PWM4B
 *                           - \ref ADCTRIG_PWM5A
 *                           - \ref ADCTRIG_PWM5B
 *                           - \ref ADCTRIG_PWM6A
 *                           - \ref ADCTRIG_PWM6B
 *
 * @return     none
 *
 * @details    Be sure to select pin as descripted as figure in datasheet
 *             SPC1068 do not support dedicated pins to differential mode
 *             Example : 
 *                Wrong  --> ADC_EasyInit2(ADC_SOC_5, ADC1_GPIO2, ADC2_GPIO3, ADCTRIG_Software);
 *                Correct -> ADC_EasyInit2(ADC_SOC_5, ADC3_GPIO4, ADC2_GPIO3, ADCTRIG_Software);
 *             Please #define SPC1068_DRIVER_DEBUG 1 when develop, there is an error message printf in
 *             ADC_SelectPinDifferetial() to help user debug.
 *
 * @example    Initial SOC3 to get differential signal between GPIO5(ADC4) and GPIO4(ADC3) signal 
 *             with software trigger
 *                 <1> ADC_EasyInit2(ADC_SOC_3,GPIO_5,GPIO_4,ADCTRIG_Software);
 *                 <2> Software trigger
 *                     ADC_SoftwareTrigger(ADC_SOC_3);
 *                 <3> Get value when data ready
 *                     ADC_GetTrimResult2(ADC_SOC_3); --> Take longer cpu cycle but accuracy (Recommend)
 *                     
 *                     ADC_GetRawResult(ADC_SOC_3);  --> Raw data, user should determine polarity and calibration.
 *
 * @note       ADC_EasyInit2(ADC_SOC_3,GPIO_5,GPIO_4,ADCTRIG_Software);
 *             and
 *             ADC_EasyInit2(ADC_SOC_3,GPIO_4,GPIO_5,ADCTRIG_Software);
 *             Are the same, the polarity of GPIO5(ADC4) and GPIO4(ADC3) is determined in 
 *             ADC hardware channel structure, please read the datasheet for details.
 *
 *******************************************************************************/
void ADC_EasyInit2(ADC_SocEnum u8SOC, uint8_t u8PinSel_1, uint8_t u8PinSel_2, ADC_TriggerSourceEnum u8TrigSrc)
{
  ADC_PowerUP();
  
  ADC_SelectPinDifferetial(u8SOC, (ADC_PinSelEnum)u8PinSel_1, (ADC_PinSelEnum)u8PinSel_2,u8TrigSrc);
  
  ADC_SetSampleAndConvTime(u8SOC,ADC_DEFAULT_SAMPLE_TIME_NS,ADC_DEFAULT_CONVERSION_TIME_NS);
  ADC_EnableInt(u8SOC);

  GPIO_SetPinAsAnalog((GPIO_PinEnum)u8PinSel_1);  /* Only GPIO1(ADC0)~GPIO16(ADC15) can be congigured */
  GPIO_SetPinAsAnalog((GPIO_PinEnum)u8PinSel_2);  /* Only GPIO1(ADC0)~GPIO16(ADC15) can be congigured */
}




/****************************************************************************//**
 * @brief      Configure ADC channel for single-ended
 *             It can auto configure SHA or SHB by the channel structure designed in ADC
 *             The other terminal is default as internal GND.
 *
 * @param[in]  u8SOC    :  Select SOC to be used (ADC_SOC_0 ~ ADC_SOC_15)
 * @param[in]  u8PinSel :  Select the ADC input pin
 *                         It can be GPIO pin number or Pin defined in adc.h
 *                         GPIO_PinEnum  (Only support ADC pin GPIO1~GPIO16)
 *                          - \ref GPIO_1     -->ADC0 
 *                          - \ref GPIO_2     -->ADC1 
 *                          - \ref GPIO_3     -->ADC2 
 *                          - \ref GPIO_4     -->ADC3 
 *                          - \ref GPIO_5     -->ADC4 
 *                          - \ref GPIO_6     -->ADC5 
 *                          - \ref GPIO_7     -->ADC6 
 *                          - \ref GPIO_8     -->ADC7 
 *                          - \ref GPIO_9     -->ADC8 
 *                          - \ref GPIO_10    -->ADC9 
 *                          - \ref GPIO_11    -->ADC10 
 *                          - \ref GPIO_12    -->ADC11 
 *                          - \ref GPIO_13    -->ADC12 
 *                          - \ref GPIO_14    -->ADC13 
 *                          - \ref GPIO_15    -->ADC14 
 *                          - \ref GPIO_16    -->ADC15 
 *                         Please do NOT initial GPIO0, GPIO17~GPIO35!
 *
 *                         If user want to use internal signal like VDD12, please use this type
 *                         ADC_PinSelEnum
 *                          - \ref ADC0_GPIO1
 *                          - \ref ADC1_GPIO2
 *                          - \ref ADC2_GPIO3
 *                          - \ref ADC3_GPIO4
 *                          - \ref ADC4_GPIO5
 *                          - \ref ADC5_GPIO6
 *                          - \ref ADC6_GPIO7
 *                          - \ref ADC7_GPIO8
 *                          - \ref ADC8_GPIO9
 *                          - \ref ADC9_GPIO10
 *                          - \ref ADC10_GPIO11
 *                          - \ref ADC11_GPIO12
 *                          - \ref ADC12_GPIO13
 *                          - \ref ADC13_GPIO14
 *                          - \ref ADC14_GPIO15
 *                          - \ref ADC15_GPIO16
 *                          - \ref ADCx_PGA0P
 *                          - \ref ADCx_PGA0N
 *                          - \ref ADCx_PGA1P
 *                          - \ref ADCx_PGA1N
 *                          - \ref ADCx_PGA2P
 *                          - \ref ADCx_PGA2N
 *                          - \ref ADCx_TSENSOR_L
 *                          - \ref ADCx_TSENSOR_H
 *                          - \ref ADCx_VDD12     -> Internal 1.2V
 *                          - \ref ADCx_VDDA      -> Internal 3.3V
 * @param[in]  u8TrigSrc:  Select the trigger source
 *                         Please goto ADC_TriggerSourceEnum for detail
 *                          - \ref ADCTRIG_Software
 *                          - \ref ADCTRIG_Timer0
 *                          - \ref ADCTRIG_Timer1
 *                          - \ref ADCTRIG_Timer2
 *                          - \ref ADCTRIG_XINT2
 *                          - \ref ADCTRIG_PWM0A
 *                          - \ref ADCTRIG_PWM0B
 *                          - \ref ADCTRIG_PWM1A
 *                          - \ref ADCTRIG_PWM1B
 *                          - \ref ADCTRIG_PWM2A
 *                          - \ref ADCTRIG_PWM2B
 *                          - \ref ADCTRIG_PWM3A
 *                          - \ref ADCTRIG_PWM3B
 *                          - \ref ADCTRIG_PWM4A
 *                          - \ref ADCTRIG_PWM4B
 *                          - \ref ADCTRIG_PWM5A
 *                          - \ref ADCTRIG_PWM5B
 *                          - \ref ADCTRIG_PWM6A
 *                          - \ref ADCTRIG_PWM6B
 *
 * @return     none
 *
 *******************************************************************************/
void ADC_SelectPinSingleEnd(ADC_SocEnum u8SOC, uint8_t u8PinSel, ADC_TriggerSourceEnum u8TrigSrc)
{
  uint32_t u8ADCHx   = u8PinSel-1;
  uint32_t ABGroup   = (((u8ADCHx&BIT3)>>3));
  uint32_t PNChannel = (1-(((u8ADCHx)&BIT2)>>2));
  uint32_t ABEnable  = ADCSOCCTL0_ALL_SHAEN_Msk>>ABGroup;
  
  uint32_t SignalCHSelPos = ADCSOCCTL0_ALL_CHSELAN_Pos + 6*ABGroup + 3*PNChannel;
  uint32_t GndCHSelPos    = ADCSOCCTL0_ALL_CHSELAN_Pos + 6*ABGroup + 3*(1-PNChannel);
  
  uint32_t IsOtherCh      = (1-((u8ADCHx&BIT4)>>4));
  
  uint32_t SignalCHSel    = ((4*IsOtherCh + ((u8ADCHx)&(BIT0|BIT1))) << SignalCHSelPos);
  uint32_t GndCHSel       = (ADCSOCCTL0_BIT_CHSELAN_GND << GndCHSelPos);
  
  ADC->ADCSOCCTL[u8SOC].all = ABEnable
                             |SignalCHSel
                             |GndCHSel
                             |((u8TrigSrc) << ADCSOCCTL0_ALL_TRIGSEL_Pos);

#if SPC1068_DRIVER_DEBUG == 1
  if(u8PositionPin > 31)
  {
    printf("Error in ADC_SelectPinSingleEnd\n");
    while(1){};
  }
#endif
}




/****************************************************************************//**
 * @brief      Configure ADC channel for differential mode
 *
 * @param[in]  u8SOC     :  Select SOC to be used
 * @param[in]  u8PinSel_1:  Select the first terminal ADC pin 
 *                          It can be ADC_PinSelEnum or GPIO_PinEnum
 * @param[in]  u8PinSel_2:  Select the second terminal ADC pin 
 *                          It can be ADC_PinSelEnum or GPIO_PinEnum
 * @param[in]  u8TrigSrc :  Select the trigger source
 *                          Please goto ADC_TriggerSourceEnum for detail
 *
 * @return     none
 *
 * @details    Be sure to select pin as descripted as figure in datasheet
 *             SPC1068 do not support dedicated pins to differential mode
 *             Example : 
 *                Wrong  --> ADC_SelectPinDifferetial(ADC_SOC_5, ADC1_GPIO2, ADC2_GPIO3, ADCTRIG_Software);
 *                Correct -> ADC_SelectPinDifferetial(ADC_SOC_5, ADC3_GPIO4, ADC2_GPIO3, ADCTRIG_Software);
 *             Please 
 *                      #define SPC1068_DRIVER_DEBUG 1 
 *             when develop, there is an error message printf in ADC_SelectPinDifferetial() to help user debug.
 *
 *******************************************************************************/
void ADC_SelectPinDifferetial(ADC_SocEnum u8SOC, ADC_PinSelEnum u8PinSel_1, ADC_PinSelEnum u8PinSel_2,ADC_TriggerSourceEnum u8TrigSrc)
{
  uint32_t u8ADCHx,ABEnable,SignalCHSelPos,NotGPIOCh,SignalCHSel;
  uint32_t ABGroup_1,ABGroup_2,PNChannel_1,PNChannel_2;
  
  u8ADCHx        = u8PinSel_1-1;
  ABGroup_1      = (((u8ADCHx&BIT3)>>3));
  PNChannel_1    = (1-(((u8ADCHx)&BIT2)>>2));
  ABEnable       = ADCSOCCTL0_ALL_SHAEN_Msk>>ABGroup_1;
  SignalCHSelPos = ADCSOCCTL0_ALL_CHSELAN_Pos+6*ABGroup_1+3*PNChannel_1;
  NotGPIOCh      = (1-((u8ADCHx&BIT4)>>4));
  SignalCHSel    = ((4*NotGPIOCh+((u8ADCHx)&(BIT0|BIT1)))<< SignalCHSelPos);
  
  ADC->ADCSOCCTL[u8SOC].all = ABEnable
                             |SignalCHSel
                             |((u8TrigSrc)<<ADCSOCCTL0_ALL_TRIGSEL_Pos);
  
  u8ADCHx        = u8PinSel_2-1;
  ABGroup_2      = (((u8ADCHx&BIT3)>>3));
  PNChannel_2    = (1-(((u8ADCHx)&BIT2)>>2));
  SignalCHSelPos = ADCSOCCTL0_ALL_CHSELAN_Pos+6*ABGroup_2+3*PNChannel_2;
  NotGPIOCh      = (1-((u8ADCHx&BIT4)>>4));
  SignalCHSel    = ((4*NotGPIOCh+((u8ADCHx)&(BIT0|BIT1)))<< SignalCHSelPos);
  
  
  ADC->ADCSOCCTL[u8SOC].all |= SignalCHSel;
  
  #if SPC1068_DRIVER_DEBUG == 1
  if((ABGroup_1 != ABGroup_2) || (PNChannel_1 == PNChannel_2))
  {
    printf("Error in ADC_SelectPinDifferetial\n");
    while(1){};
  }
  
  printf("CHA Enable = %d\n",ADC->ADCSOCCTL[u8SOC].bit.SHAEN);
  printf("CHB Enable = %d\n",ADC->ADCSOCCTL[u8SOC].bit.SHBEN);
  printf("CH SEL AN  = %d\n",ADC->ADCSOCCTL[u8SOC].bit.CHSELAN);
  printf("CH SEL AP  = %d\n",ADC->ADCSOCCTL[u8SOC].bit.CHSELAP);
  printf("CH SEL BN  = %d\n",ADC->ADCSOCCTL[u8SOC].bit.CHSELBN);
  printf("CH SEL BP  = %d\n",ADC->ADCSOCCTL[u8SOC].bit.CHSELBP);
  
  #endif
}


/******************* (C) COPYRIGHT 2021 SPINTROL LIMITED CO. *****END OF FILE****/
