/**************************************************************************//**
 * @file     adc.h
 * @brief    ADC driver header file.
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


#ifndef ADC_H
#define ADC_H

#ifdef __cplusplus
extern "C" {
#endif


#include "spc1068.h"




/**
 *  @brief  ADC default sampling and conversion time
 *          User can adjust with different application
 */
#define ADC_DEFAULT_SAMPLE_TIME_NS          150
#define ADC_DEFAULT_CONVERSION_TIME_NS      150




/**
 *  @brief  ADC full scale selection
 */
#define ADC_FULL_SCALE_3V65                 (0x1)
#define ADC_FULL_SCALE_3V3                  (0x2)
#define ADC_FULL_SCALE_SEL                  ADC_FULL_SCALE_3V65




/**
 *  @brief  ADC full scale voltage
 *
 *  @note   User should not change
 */
#if ADC_FULL_SCALE_SEL == ADC_FULL_SCALE_3V65
  #define ADC_FULLSCALE_VOLT                (3.650)
#elif ADC_FULL_SCALE_SEL == ADC_FULL_SCALE_3V3
  #define ADC_FULLSCALE_VOLT                (3.3)
#else
  #define ADC_FULLSCALE_VOLT                (3.650)
#endif
#define ADC_FULLSCALE_mV                    ((int32_t)(ADC_FULLSCALE_VOLT * 1000.0))




/**
 *  @brief  ADC interrupt type definition
 */
typedef enum
{
  ADC_INT_0             =  0,               /*!< ADC interrupt  0         */
  ADC_INT_1             =  1,               /*!< ADC interrupt  1         */
  ADC_INT_2             =  2,               /*!< ADC interrupt  2         */
  ADC_INT_3             =  3,               /*!< ADC interrupt  3         */
  ADC_INT_4             =  4,               /*!< ADC interrupt  4         */
  ADC_INT_5             =  5,               /*!< ADC interrupt  5         */
  ADC_INT_6             =  6,               /*!< ADC interrupt  6         */
  ADC_INT_7             =  7,               /*!< ADC interrupt  7         */
  ADC_INT_8             =  8,               /*!< ADC interrupt  8         */
  ADC_INT_9             =  9,               /*!< ADC interrupt  9         */
  ADC_INT_10            = 10,               /*!< ADC interrupt 10         */
  ADC_INT_11            = 11,               /*!< ADC interrupt 11         */
  ADC_INT_12            = 12,               /*!< ADC interrupt 12         */
  ADC_INT_13            = 13,               /*!< ADC interrupt 13         */
  ADC_INT_14            = 14,               /*!< ADC interrupt 14         */
  ADC_INT_15            = 15,               /*!< ADC interrupt 15         */
} ADC_IntEnum;




/**
 *  @brief  ADC SOC type definition
 */
typedef enum
{
  ADC_SOC_0             =  0,               /*!< ADC SOC  0               */
  ADC_SOC_1             =  1,               /*!< ADC SOC  1               */
  ADC_SOC_2             =  2,               /*!< ADC SOC  2               */
  ADC_SOC_3             =  3,               /*!< ADC SOC  3               */
  ADC_SOC_4             =  4,               /*!< ADC SOC  4               */
  ADC_SOC_5             =  5,               /*!< ADC SOC  5               */
  ADC_SOC_6             =  6,               /*!< ADC SOC  6               */
  ADC_SOC_7             =  7,               /*!< ADC SOC  7               */
  ADC_SOC_8             =  8,               /*!< ADC SOC  8               */
  ADC_SOC_9             =  9,               /*!< ADC SOC  9               */
  ADC_SOC_10            = 10,               /*!< ADC SOC 10               */
  ADC_SOC_11            = 11,               /*!< ADC SOC 11               */
  ADC_SOC_12            = 12,               /*!< ADC SOC 12               */
  ADC_SOC_13            = 13,               /*!< ADC SOC 13               */
  ADC_SOC_14            = 14,               /*!< ADC SOC 14               */
  ADC_SOC_15            = 15,               /*!< ADC SOC 15               */
} ADC_SocEnum;




/**
 *  @brief  ADC Input Pin Selection Table
 */
typedef enum
{
  ADC0_GPIO1            =  1,               /*!< SHA positive terminal: GPIO1                       */
  ADC1_GPIO2            =  2,               /*!< SHA positive terminal: GPIO2                       */
  ADC2_GPIO3            =  3,               /*!< SHA positive terminal: GPIO3                       */
  ADC3_GPIO4            =  4,               /*!< SHA positive terminal: GPIO4                       */
  ADC4_GPIO5            =  5,               /*!< SHA negative terminal: GPIO5                       */
  ADC5_GPIO6            =  6,               /*!< SHA negative terminal: GPIO6                       */
  ADC6_GPIO7            =  7,               /*!< SHA negative terminal: GPIO7                       */
  ADC7_GPIO8            =  8,               /*!< SHA negative terminal: GPIO8                       */
  ADC8_GPIO9            =  9,               /*!< SHB positive terminal: GPIO9                       */
  ADC9_GPIO10           = 10,               /*!< SHB positive terminal: GPIO10                      */
  ADC10_GPIO11          = 11,               /*!< SHB positive terminal: GPIO11                      */
  ADC11_GPIO12          = 12,               /*!< SHB positive terminal: GPIO12                      */
  ADC12_GPIO13          = 13,               /*!< SHB positive terminal: GPIO13                      */
  ADC13_GPIO14          = 14,               /*!< SHB positive terminal: GPIO14                      */
  ADC14_GPIO15          = 15,               /*!< SHB positive terminal: GPIO15                      */
  ADC15_GPIO16          = 16,               /*!< SHB positive terminal: GPIO16                      */
  ADCx_PGA0P            = 17,               /*!< SHA positive terminal: Positive output of PGA0     */
  ADCx_PGA0N            = 21,               /*!< SHA negative terminal: Positive output of PGA0     */
  ADCx_PGA1P            = 26,               /*!< SHA positive terminal: Negative output of PGA1     */
  ADCx_PGA1N            = 30,               /*!< SHA negative terminal: Negative output of PGA1     */
  ADCx_PGA2P            = 25,               /*!< SHB positive terminal: Positive output of PGA2     */
  ADCx_PGA2N            = 29,               /*!< SHB negative terminal: Negative output of PGA2     */
  ADCx_TSENSOR_L        = 28,               /*!< SHB negative terminal: T-sensor output 0           */
  ADCx_TSENSOR_H        = 32,               /*!< SHB positive terminal: T-sensor output 1           */
  ADCx_VDD12            = 20,               /*!< SHA positive terminal: VDD12                       */
  ADCx_VDDA             = 24,               /*!< SHA negative terminal: VDDA                        */
} ADC_PinSelEnum;




/**
 *  @brief  ADC Trigger Source Table
 */
typedef enum
{
  ADCTRIG_Software     =  0,               /*!< ADCTRIG0  - Software     */
  ADCTRIG_Timer0       =  1,               /*!< ADCTRIG1  - CPU Timer 0  */
  ADCTRIG_Timer1       =  2,               /*!< ADCTRIG1  - CPU Timer 1  */
  ADCTRIG_Timer2       =  3,               /*!< ADCTRIG1  - CPU Timer 2  */
  ADCTRIG_XINT2        =  4,               /*!< ADCTRIG4  - XINT2        */
  ADCTRIG_PWM0A        =  5,               /*!< ADCTRIG5  - PWM0A        */
  ADCTRIG_PWM0B        =  6,               /*!< ADCTRIG6  - PWM0B        */
  ADCTRIG_PWM1A        =  7,               /*!< ADCTRIG7  - PWM1A        */
  ADCTRIG_PWM1B        =  8,               /*!< ADCTRIG8  - PWM1B        */
  ADCTRIG_PWM2A        =  9,               /*!< ADCTRIG9  - PWM2A        */
  ADCTRIG_PWM2B        = 10,               /*!< ADCTRIG10 - PWM2B        */
  ADCTRIG_PWM3A        = 11,               /*!< ADCTRIG11 - PWM3A        */
  ADCTRIG_PWM3B        = 12,               /*!< ADCTRIG12 - PWM3B        */
  ADCTRIG_PWM4A        = 13,               /*!< ADCTRIG13 - PWM4A        */
  ADCTRIG_PWM4B        = 14,               /*!< ADCTRIG14 - PWM4B        */
  ADCTRIG_PWM5A        = 15,               /*!< ADCTRIG15 - PWM5A        */
  ADCTRIG_PWM5B        = 16,               /*!< ADCTRIG16 - PWM5B        */
  ADCTRIG_PWM6A        = 17,               /*!< ADCTRIG17 - PWM6A        */
  ADCTRIG_PWM6B        = 18,               /*!< ADCTRIG18 - PWM6B        */
} ADC_TriggerSourceEnum;




/****************************************************************************//**
 * @brief      Enable ADC Interrupt
 *
 * @param[in]  none
 *
 * @return     none
 *
 *******************************************************************************/
#define ADC_EnableInt0()          (ADC->ADCINTSEL0.all |= (ADCINTSEL0_ALL_INT0EN_ENABLE  | ADCINTSEL0_ALL_INT0CONT_CONTINUE_MODE_ENABLE))
#define ADC_EnableInt1()          (ADC->ADCINTSEL0.all |= (ADCINTSEL0_ALL_INT1EN_ENABLE  | ADCINTSEL0_ALL_INT1CONT_CONTINUE_MODE_ENABLE))
#define ADC_EnableInt2()          (ADC->ADCINTSEL1.all |= (ADCINTSEL1_ALL_INT2EN_ENABLE  | ADCINTSEL1_ALL_INT2CONT_CONTINUE_MODE_ENABLE))
#define ADC_EnableInt3()          (ADC->ADCINTSEL1.all |= (ADCINTSEL1_ALL_INT3EN_ENABLE  | ADCINTSEL1_ALL_INT3CONT_CONTINUE_MODE_ENABLE))
#define ADC_EnableInt4()          (ADC->ADCINTSEL2.all |= (ADCINTSEL2_ALL_INT4EN_ENABLE  | ADCINTSEL2_ALL_INT4CONT_CONTINUE_MODE_ENABLE))
#define ADC_EnableInt5()          (ADC->ADCINTSEL2.all |= (ADCINTSEL2_ALL_INT5EN_ENABLE  | ADCINTSEL2_ALL_INT5CONT_CONTINUE_MODE_ENABLE))
#define ADC_EnableInt6()          (ADC->ADCINTSEL3.all |= (ADCINTSEL3_ALL_INT6EN_ENABLE  | ADCINTSEL3_ALL_INT6CONT_CONTINUE_MODE_ENABLE))
#define ADC_EnableInt7()          (ADC->ADCINTSEL3.all |= (ADCINTSEL3_ALL_INT7EN_ENABLE  | ADCINTSEL3_ALL_INT7CONT_CONTINUE_MODE_ENABLE))
#define ADC_EnableInt8()          (ADC->ADCINTSEL4.all |= (ADCINTSEL4_ALL_INT8EN_ENABLE  | ADCINTSEL4_ALL_INT8CONT_CONTINUE_MODE_ENABLE))
#define ADC_EnableInt9()          (ADC->ADCINTSEL4.all |= (ADCINTSEL4_ALL_INT9EN_ENABLE  | ADCINTSEL4_ALL_INT9CONT_CONTINUE_MODE_ENABLE))
#define ADC_EnableInt10()         (ADC->ADCINTSEL4.all |= (ADCINTSEL4_ALL_INT10EN_ENABLE | ADCINTSEL4_ALL_INT10CONT_CONTINUE_MODE_ENABLE))
#define ADC_EnableInt11()         (ADC->ADCINTSEL3.all |= (ADCINTSEL3_ALL_INT11EN_ENABLE | ADCINTSEL3_ALL_INT11CONT_CONTINUE_MODE_ENABLE))
#define ADC_EnableInt12()         (ADC->ADCINTSEL3.all |= (ADCINTSEL3_ALL_INT12EN_ENABLE | ADCINTSEL3_ALL_INT12CONT_CONTINUE_MODE_ENABLE))
#define ADC_EnableInt13()         (ADC->ADCINTSEL3.all |= (ADCINTSEL3_ALL_INT13EN_ENABLE | ADCINTSEL3_ALL_INT13CONT_CONTINUE_MODE_ENABLE))
#define ADC_EnableInt14()         (ADC->ADCINTSEL3.all |= (ADCINTSEL3_ALL_INT14EN_ENABLE | ADCINTSEL3_ALL_INT14CONT_CONTINUE_MODE_ENABLE))
#define ADC_EnableInt15()         (ADC->ADCINTSEL3.all |= (ADCINTSEL3_ALL_INT15EN_ENABLE | ADCINTSEL3_ALL_INT15CONT_CONTINUE_MODE_ENABLE))




/****************************************************************************//**
 * @brief      Disable ADC Interrupt
 *
 * @param[in]  none
 *
 * @return     none
 *
 *******************************************************************************/
#define ADC_DisableInt0()                   (ADC->ADCINTSEL0.bit.INT0EN  = DISABLE)
#define ADC_DisableInt1()                   (ADC->ADCINTSEL0.bit.INT1EN  = DISABLE)
#define ADC_DisableInt2()                   (ADC->ADCINTSEL1.bit.INT2EN  = DISABLE)
#define ADC_DisableInt3()                   (ADC->ADCINTSEL1.bit.INT3EN  = DISABLE)
#define ADC_DisableInt4()                   (ADC->ADCINTSEL2.bit.INT4EN  = DISABLE)
#define ADC_DisableInt5()                   (ADC->ADCINTSEL2.bit.INT5EN  = DISABLE)
#define ADC_DisableInt6()                   (ADC->ADCINTSEL3.bit.INT6EN  = DISABLE)
#define ADC_DisableInt7()                   (ADC->ADCINTSEL3.bit.INT7EN  = DISABLE)
#define ADC_DisableInt8()                   (ADC->ADCINTSEL4.bit.INT8EN  = DISABLE)
#define ADC_DisableInt9()                   (ADC->ADCINTSEL4.bit.INT9EN  = DISABLE)
#define ADC_DisableInt10()                  (ADC->ADCINTSEL4.bit.INT10EN = DISABLE)
#define ADC_DisableInt11()                  (ADC->ADCINTSEL3.bit.INT11EN = DISABLE)
#define ADC_DisableInt12()                  (ADC->ADCINTSEL3.bit.INT12EN = DISABLE)
#define ADC_DisableInt13()                  (ADC->ADCINTSEL3.bit.INT13EN = DISABLE)
#define ADC_DisableInt14()                  (ADC->ADCINTSEL3.bit.INT14EN = DISABLE)
#define ADC_DisableInt15()                  (ADC->ADCINTSEL3.bit.INT15EN = DISABLE)




/****************************************************************************//**
 * @brief      Enable ADC Continous Interrupt Mode
 *
 * @param[in]  none
 *
 * @return     none
 *
 *******************************************************************************/
#define ADC_EnableContinousInt0()           (ADC->ADCINTSEL0.bit.INT0CONT  = ENABLE)
#define ADC_EnableContinousInt1()           (ADC->ADCINTSEL0.bit.INT1CONT  = ENABLE)
#define ADC_EnableContinousInt2()           (ADC->ADCINTSEL1.bit.INT2CONT  = ENABLE)
#define ADC_EnableContinousInt3()           (ADC->ADCINTSEL1.bit.INT3CONT  = ENABLE)
#define ADC_EnableContinousInt4()           (ADC->ADCINTSEL2.bit.INT4CONT  = ENABLE)
#define ADC_EnableContinousInt5()           (ADC->ADCINTSEL2.bit.INT5CONT  = ENABLE)
#define ADC_EnableContinousInt6()           (ADC->ADCINTSEL3.bit.INT6CONT  = ENABLE)
#define ADC_EnableContinousInt7()           (ADC->ADCINTSEL3.bit.INT7CONT  = ENABLE)
#define ADC_EnableContinousInt8()           (ADC->ADCINTSEL4.bit.INT8CONT  = ENABLE)
#define ADC_EnableContinousInt9()           (ADC->ADCINTSEL4.bit.INT9CONT  = ENABLE)
#define ADC_EnableContinousInt10()          (ADC->ADCINTSEL4.bit.INT10CONT = ENABLE)
#define ADC_EnableContinousInt11()          (ADC->ADCINTSEL3.bit.INT11CONT = ENABLE)
#define ADC_EnableContinousInt12()          (ADC->ADCINTSEL3.bit.INT12CONT = ENABLE)
#define ADC_EnableContinousInt13()          (ADC->ADCINTSEL3.bit.INT13CONT = ENABLE)
#define ADC_EnableContinousInt14()          (ADC->ADCINTSEL3.bit.INT14CONT = ENABLE)
#define ADC_EnableContinousInt15()          (ADC->ADCINTSEL3.bit.INT15CONT = ENABLE)




/****************************************************************************//**
 * @brief      Disable ADC Continous Interrupt Mode
 *
 * @param[in]  none
 *
 * @return     none
 *
 *******************************************************************************/
#define ADC_DisableContinousInt0()          (ADC->ADCINTSEL0.bit.INT0CONT  = DISABLE)
#define ADC_DisableContinousInt1()          (ADC->ADCINTSEL0.bit.INT1CONT  = DISABLE)
#define ADC_DisableContinousInt2()          (ADC->ADCINTSEL1.bit.INT2CONT  = DISABLE)
#define ADC_DisableContinousInt3()          (ADC->ADCINTSEL1.bit.INT3CONT  = DISABLE)
#define ADC_DisableContinousInt4()          (ADC->ADCINTSEL2.bit.INT4CONT  = DISABLE)
#define ADC_DisableContinousInt5()          (ADC->ADCINTSEL2.bit.INT5CONT  = DISABLE)
#define ADC_DisableContinousInt6()          (ADC->ADCINTSEL3.bit.INT6CONT  = DISABLE)
#define ADC_DisableContinousInt7()          (ADC->ADCINTSEL3.bit.INT7CONT  = DISABLE)
#define ADC_DisableContinousInt8()          (ADC->ADCINTSEL4.bit.INT8CONT  = DISABLE)
#define ADC_DisableContinousInt9()          (ADC->ADCINTSEL4.bit.INT9CONT  = DISABLE)
#define ADC_DisableContinousInt10()         (ADC->ADCINTSEL4.bit.INT10CONT = DISABLE)
#define ADC_DisableContinousInt11()         (ADC->ADCINTSEL3.bit.INT11CONT = DISABLE)
#define ADC_DisableContinousInt12()         (ADC->ADCINTSEL3.bit.INT12CONT = DISABLE)
#define ADC_DisableContinousInt13()         (ADC->ADCINTSEL3.bit.INT13CONT = DISABLE)
#define ADC_DisableContinousInt14()         (ADC->ADCINTSEL3.bit.INT14CONT = DISABLE)
#define ADC_DisableContinousInt15()         (ADC->ADCINTSEL3.bit.INT15CONT = DISABLE)




/****************************************************************************//**
 * @brief      Clear ADC Interrupt Flag
 *
 * @param[in]  none
 *
 * @return     none
 *
 *******************************************************************************/
#define ADC_ClearInt0()                     (ADC->ADCIC.all = ADCIC_ALL_INT0_CLEAR_FLAG)
#define ADC_ClearInt1()                     (ADC->ADCIC.all = ADCIC_ALL_INT1_CLEAR_FLAG)
#define ADC_ClearInt2()                     (ADC->ADCIC.all = ADCIC_ALL_INT2_CLEAR_FLAG)
#define ADC_ClearInt3()                     (ADC->ADCIC.all = ADCIC_ALL_INT3_CLEAR_FLAG)
#define ADC_ClearInt4()                     (ADC->ADCIC.all = ADCIC_ALL_INT4_CLEAR_FLAG)
#define ADC_ClearInt5()                     (ADC->ADCIC.all = ADCIC_ALL_INT5_CLEAR_FLAG)
#define ADC_ClearInt6()                     (ADC->ADCIC.all = ADCIC_ALL_INT6_CLEAR_FLAG)
#define ADC_ClearInt7()                     (ADC->ADCIC.all = ADCIC_ALL_INT7_CLEAR_FLAG)
#define ADC_ClearInt8()                     (ADC->ADCIC.all = ADCIC_ALL_INT8_CLEAR_FLAG)
#define ADC_ClearInt9()                     (ADC->ADCIC.all = ADCIC_ALL_INT9_CLEAR_FLAG)
#define ADC_ClearInt10()                    (ADC->ADCIC.all = ADCIC_ALL_INT10_CLEAR_FLAG)
#define ADC_ClearInt11()                    (ADC->ADCIC.all = ADCIC_ALL_INT11_CLEAR_FLAG)
#define ADC_ClearInt12()                    (ADC->ADCIC.all = ADCIC_ALL_INT12_CLEAR_FLAG)
#define ADC_ClearInt13()                    (ADC->ADCIC.all = ADCIC_ALL_INT13_CLEAR_FLAG)
#define ADC_ClearInt14()                    (ADC->ADCIC.all = ADCIC_ALL_INT14_CLEAR_FLAG)
#define ADC_ClearInt15()                    (ADC->ADCIC.all = ADCIC_ALL_INT15_CLEAR_FLAG)




/****************************************************************************//**
 * @brief      Clear ADC Interrupt Flag
 *
 * @param[in]  u8SOC:  Select SOC to be used from ADC_SocEnum
 *
 * @return     none
 *
 *******************************************************************************/
#define ADC_ClearInt(u8SOC)                 ((ADC->ADCIC.all = (ADCIF_ALL_INT0_Msk<<(u8SOC))))




/****************************************************************************//**
 * @brief      Get ADC Interrupt Flag
 *
 * @param[in]  none
 *
 * @return     0 : Interrupt do not occur
 *             1 : Interrupt occurs
 *
 *******************************************************************************/
#define ADC_GetInt0Flag()                   (ADC->ADCIF.bit.INT0)
#define ADC_GetInt1Flag()                   (ADC->ADCIF.bit.INT1)
#define ADC_GetInt2Flag()                   (ADC->ADCIF.bit.INT2)
#define ADC_GetInt3Flag()                   (ADC->ADCIF.bit.INT3)
#define ADC_GetInt4Flag()                   (ADC->ADCIF.bit.INT4)
#define ADC_GetInt5Flag()                   (ADC->ADCIF.bit.INT5)
#define ADC_GetInt6Flag()                   (ADC->ADCIF.bit.INT6)
#define ADC_GetInt7Flag()                   (ADC->ADCIF.bit.INT7)
#define ADC_GetInt8Flag()                   (ADC->ADCIF.bit.INT8)
#define ADC_GetInt9Flag()                   (ADC->ADCIF.bit.INT9)
#define ADC_GetInt10Flag()                  (ADC->ADCIF.bit.INT10)
#define ADC_GetInt11Flag()                  (ADC->ADCIF.bit.INT11)
#define ADC_GetInt12Flag()                  (ADC->ADCIF.bit.INT12)
#define ADC_GetInt13Flag()                  (ADC->ADCIF.bit.INT13)
#define ADC_GetInt14Flag()                  (ADC->ADCIF.bit.INT14)
#define ADC_GetInt15Flag()                  (ADC->ADCIF.bit.INT15)




/****************************************************************************//**
 * @brief      Get ADC Interrupt Flag
 *
 * @param[in]  u8SOC:  Select SOC to be used from ADC_SocEnum
 *
 * @return     0 : Interrupt do not occur
 *             1 : Interrupt occurs
 *
 *******************************************************************************/
#define ADC_GetIntFlag(u8SOC)               ((ADC->ADCIF.all & (ADCIF_ALL_INT0_Msk<<(u8SOC))) >> (u8SOC))




/****************************************************************************//**
 * @brief      Enable ADC module 
 *
 * @param[in]  none
 *
 * @return     none
 *
 *******************************************************************************/
#define ADC_Enable()                        (ADC->ADCCTL0.all |= ADCCTL0_ALL_EN_ENABLE_ADC)




/****************************************************************************//**
 * @brief      Disable ADC module 
 *
 * @param[in]  none
 *
 * @return     none
 *
 *******************************************************************************/
#define ADC_Disable()                       (ADC->ADCCTL0.bit.EN = ADCCTL0_BIT_EN_DISABLE_ADC)




/****************************************************************************//**
 * @brief      Reset ADC module 
 *
 * @param[in]  none
 *
 * @return     none
 *
 *******************************************************************************/
#define ADC_Reset()                         (ADC->ADCCTL0.all |= ADCCTL0_ALL_RST_RESET_ADC)




/****************************************************************************//**
 * @brief      Select Trigger source for SOC
 *
 * @param[in]  u8TriggerSource:  Select ADC Trigger Source, value from  ADC_TriggerSourceEnum
 * @param[in]  u8SOC:  Select SOC to be used
 *
 * @return     none
 *
*******************************************************************************/
#define ADC_SelectTrigger(u8SOC,u8TriggerSource)   (ADC->ADCSOCCTL[(u8SOC)].bit.TRIGSEL = (u8TriggerSource))




/****************************************************************************//**
 * @brief      Software trigger SOC
 *
 * @param[in]  u8SOC:  Select SOC to be used
 *
 * @return     none
 *
*******************************************************************************/
#define ADC_SoftwareTrigger(u8SOC)          (ADC->ADCSOCFRC.all = (ADCSOCFRC_ALL_SOC0_FORCE_CONVERT << (u8SOC)))




/****************************************************************************//**
 * @brief      Get raw result(code) from ADC result register
 *
 * @param[in]  u8SOC:  Select SOC to be used
 *
 * @return     ADC result in 0~8191
 *             Code            Real Voltage in ADC view
 *             0               -3.65 V
 *             4095            0 V
 *             8191            3.65 V
 *
 *******************************************************************************/
#define ADC_GetRawResult(u8SOC)             (ADC->ADCRESULT[(u8SOC)].bit.VAL)




/****************************************************************************//**
 * @brief      For Single End Mode Only (One terminal is GND)
 *             Get Trim result(code) from ADC result register
 *             The trim coefficient locates at flash and load in SysInfo when start up
 *
 * @param[in]  u8SOC:  Select SOC to be used
 *
 * @return     ADC result in 0~4095
 *             Note: User can choose ADC fullscale voltage in adc.h
 *             If full scale is 3.65V 
 *             Code            Real Voltage in ADC view
 *             0               0 V
 *             4095            3.65 V
 *
 *             If full scale is 3.3V 
 *             Code            Real Voltage in ADC view
 *             0               0 V
 *             4095            3.3 V
 *
 *******************************************************************************/
#if ADC_FULL_SCALE_SEL == ADC_FULL_SCALE_3V65
#define ADC_GetTrimResult1(u8SOC)           (ABS(((((int16_t)ADC->ADCRESULT[(u8SOC)].bit.VAL+\
                                              SysInfo.i16SHAOffset)*(int32_t)(SysInfo.i32SHAGain))>>15)))
#elif ADC_FULL_SCALE_SEL == ADC_FULL_SCALE_3V3
#define ADC_GetTrimResult1(u8SOC)           (ABS(((((int16_t)ADC->ADCRESULT[(u8SOC)].bit.VAL+\
                                              SysInfo.i16SHAOffset)*(int32_t)(SysInfo.i32SHAGain3V3))>>15)))
#else
#define ADC_GetTrimResult1(u8SOC)           (ABS(((((int16_t)ADC->ADCRESULT[(u8SOC)].bit.VAL+\
                                              SysInfo.i16SHAOffset)*(int32_t)(SysInfo.i32SHAGain))>>15)))
#endif




/****************************************************************************//**
 * @brief      For Differential Mode 
 *             Get Trim result(code) from ADC result register
 *             The trim coefficient locates at flash and load in SysInfo when start up
 *
 * @param[in]  u8SOC:  Select SOC to be used
 *
 * @return     ADC result in 0~4095
 *             Note: User can choose ADC fullscale voltage
 *             If full scale is 3.65V 
 *             Code            Real Voltage in ADC view
 *             -4095           -3.65 V
 *             0               0 V
 *             4095             3.65 V
 *
 *             If full scale is 3.3V 
 *             Code            Real Voltage in ADC view
 *             -4095           -3.3 V
 *             0               0 V
 *             4095             3.3 V
 *
 *******************************************************************************/
#if ADC_FULL_SCALE_SEL == ADC_FULL_SCALE_3V65
#define ADC_GetTrimResult2(u8SOC)           ((((((int16_t)ADC->ADCRESULT[(u8SOC)].bit.VAL+\
                                              SysInfo.i16SHAOffset)*(int32_t)(SysInfo.i32SHAGain))>>15)))
#elif ADC_FULL_SCALE_SEL == ADC_FULL_SCALE_3V3
#define ADC_GetTrimResult2(u8SOC)           ((((((int16_t)ADC->ADCRESULT[(u8SOC)].bit.VAL+\
                                              SysInfo.i16SHAOffset)*(int32_t)(SysInfo.i32SHAGain3V3))>>15)))
#else
#define ADC_GetTrimResult2(u8SOC)           ((((((int16_t)ADC->ADCRESULT[(u8SOC)].bit.VAL+\
                                              SysInfo.i16SHAOffset)*(int32_t)(SysInfo.i32SHAGain))>>15)))
#endif



/**
 *  @brief  ADC Public Function Declaration
 */
void ADC_PowerUP(void);

void ADC_SetSampleAndConvTime(ADC_SocEnum ADC_SOC_Ch, uint32_t u32SampleTimeNs, uint32_t u32ConvTimeNs);
void ADC_SelectPinSingleEnd(ADC_SocEnum u8SOC, uint8_t u8PositionPin, ADC_TriggerSourceEnum u8TrigSrc);
void ADC_SelectPinDifferetial(ADC_SocEnum u8SOC, ADC_PinSelEnum u8PositionPin_1, ADC_PinSelEnum u8PositionPin_2, ADC_TriggerSourceEnum u8TrigSrc);
void ADC_EasyInit1(ADC_SocEnum u8SOC, uint8_t u8PinSel, ADC_TriggerSourceEnum u8TrigSrc);
void ADC_EasyInit2(ADC_SocEnum u8SOC, uint8_t u8PinSel_1, uint8_t u8PinSel_2, ADC_TriggerSourceEnum u8TrigSrc);
void ADC_EnableInt(ADC_SocEnum u8SOC);
ADC_TriggerSourceEnum ADC_TrigFromPWMxSOCA(PWM_REGS* PWMx);
ADC_TriggerSourceEnum ADC_TrigFromPWMxSOCB(PWM_REGS* PWMx);


#ifdef __cplusplus
}
#endif /* extern "C" */

#endif /* ADC_H */

/******************* (C) COPYRIGHT 2021 SPINTROL LIMITED CO. *****END OF FILE****/
