/*******************************************************************************
* @file     comp.h
* @brief    Comparator driver header file.
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


#ifndef COMP_H
#define COMP_H

#ifdef __cplusplus
extern "C" {
#endif


#include "spc1068.h"




/**
 *  @brief  Comparator selection
 */
typedef enum
{
  COMP_0_LO             = 0,
  COMP_1_LO             = 1,
  COMP_2_LO             = 2,
  COMP_0_HI             = 3,
  COMP_1_HI             = 4,
  COMP_2_HI             = 5
} COMP_ComparatorSelEnum;




/**
 *  @brief  Comparator Channel selection
 */
typedef enum
{
  FROM_PGAxN_OUT        = 0,                /*!< Select the input source of high speed comparator as output of pga0n */
  FROM_PGAxP_OUT        = 1,                /*!< Select the input source of high speed comparator as output of pga0p */
  FROM_PGAxN_IN         = 2,                /*!< Select the input source of high speed comparator as  input of pga0n */
  FROM_PGAxP_IN         = 3                 /*!< Select the input source of high speed comparator as  input of pga0p */
} COMP_CHSelEnum;




/****************************************************************************//**
 * @brief      Enable analog comparator
 *
 * @param[in]  eComp: Select the comparator
 *                    See COMP_ComparatorSelEnum for details
 *                     - \ref COMP_0_LO
 *                     - \ref COMP_1_LO
 *                     - \ref COMP_2_LO
 *                     - \ref COMP_0_HI
 *                     - \ref COMP_1_HI
 *                     - \ref COMP_2_HI
 *                    COMP_x_LO is for too low protection
 *                    COMP_x_HI is for too high protection
 *
 *                    COMP_x_LO = 1 when input value < Configure value(DAC_LO)
 *                    COMP_x_HI = 1 when input value > Configure value(DAC_HI)
 * @return     none
 *
 * @example    COMP_Enable(COMP_2_LO);
 *
 *******************************************************************************/
__STATIC_INLINE void COMP_Enable(COMP_ComparatorSelEnum eCOMP)
{
  ADC->ADCCTL0.bit.EN = ADCCTL0_BIT_EN_ENABLE_ADC; 
  COMP->COMPCTL.all |= COMPCTL_ALL_COMP0LEN_ENABLE<<(eCOMP);
}




/****************************************************************************//**
 * @brief      Disable analog comparator
 *
 * @param[in]  eCOMP: Select the comparator
 *                    See COMP_ComparatorSelEnum for details
 *                     - \ref COMP_0_LO
 *                     - \ref COMP_1_LO
 *                     - \ref COMP_2_LO
 *                     - \ref COMP_0_HI
 *                     - \ref COMP_1_HI
 *                     - \ref COMP_2_HI
 *                    COMP_x_LO is for too low protection
 *                    COMP_x_HI is for too high protection
 *
 *                    COMP_x_LO = 1 when input value < Configure value(DAC_LO)
 *                    COMP_x_HI = 1 when input value > Configure value(DAC_HI)
 *
 * @return     none
 *
 * @example    COMP_Disable(COMP_2_LO);
 *
 *******************************************************************************/
#define COMP_Disable(eCOMP)                 (COMP->COMPCTL.all &= (~(COMPCTL_ALL_COMP0LEN_Msk<<(eCOMP))))




/****************************************************************************//**
 * @brief      Enable comparator output deglitch function
 *
 * @param[in]  none
 *
 * @return     none
 *
 * @details    Comparator output deglitch is as digital filter function
 *             The output state(0 or 1) must be consistent for COMP->COMPCTL.bit.DGPRDSEL 
 *             consecutive clocks before change
 *             Example :
 *             If COMP->COMPCTL.bit.DGPRDSEL = 2, output need 2 consistent clock holds at same state before
 *             final output change.
 *             If comparator output = 00010000 
 *             The final output     = 00000000
 *
 *             If comparator output = 00011111
 *             The final output     = 00000111
 *
 *             This function is important in power and motor control which signal is very noisy while running.
 *             Enable this function can avoid comparator too sensitive to noise that turn off PWM at wrong time.
 *
 *******************************************************************************/
#define COMP_EnableDeglitch()               (COMP->COMPCTL.all |= COMPCTL_ALL_DGEN_FILTER_ENABLE)




/****************************************************************************//**
 * @brief      Disable comparator output deglitch function
 *
 * @param[in]  none
 *
 * @return     none
 *
 *******************************************************************************/
#define COMP_DisableDeglitch()              (COMP->COMPCTL.all &= (~COMPCTL_ALL_DGEN_Msk))




/****************************************************************************//**
 * @brief      Set deglitch window size (clock cycles)
 *
 * @param[in]  none
 *
 * @return     none
 *
 * @details    The output state(0 or 1) must be consistent for COMP->COMPCTL.bit.DGPRDSEL 
 *             consecutive clocks before change
 *             This clock is from CLK0 in the system
 *
 *******************************************************************************/
#define COMP_SetDeglitchCnt(u7ClkCnt)          (COMP->COMPCTL.bit.DGPRDSEL = (u7ClkCnt))




/****************************************************************************//**
 * @brief      Invert comparator output
 *
 * @param[in]  eCOMP: Select the comparator
 *                    See COMP_ComparatorSelEnum for details
 *
 * @return     none
 *
 *******************************************************************************/
#define COMP_InvertOutput(eCOMP)            (COMP->COMPCTL.all |= (BIT6<<(eCOMP)))




/****************************************************************************//**
 * @brief      Clear all comparators output status flag
 *
 * @param[in]  none
 *
 * @return     none
 *
 *
 *******************************************************************************/
#define COMP_ClearAllOutputStatus()         (ADC->ADCSTS.all = ADCSTS_ALL_COMPSTSCLR_CLEAR)




/****************************************************************************//**
 * @brief      Enable comparator hysteresis function
 *
 * @param[in]  eCOMP: Select the comparator
 *                    See COMP_ComparatorSelEnum for details
 *
 * @return     none
 *
 *******************************************************************************/
#define COMP_EnableHysteresis(eCOMP)        (COMP->COMPCTL.all |= (COMPCTL_ALL_COMP0LHYEN_ENABLE<<(eCOMP)))




/****************************************************************************//**
 * @brief      Disable comparator hysteresis function
 *
 * @param[in]  eCOMP: Select the comparator
 *                    See COMP_ComparatorSelEnum for details
 *
 * @return     none
 *
 *******************************************************************************/
#define COMP_DisableHysteresis(eCOMP)       (COMP->COMPCTL.all &= (~(COMPCTL_ALL_COMP0LHYEN_Msk<<(eCOMP))))




/****************************************************************************//**
 * @brief      Select the comparator input channel
 *
 * @param[in]  eCOMP:  Select the comparator
 *                     See COMP_ComparatorSelEnum for details
 *                      - \ref COMP_0_LO
 *                      - \ref COMP_1_LO
 *                      - \ref COMP_2_LO
 *                      - \ref COMP_0_HI
 *                      - \ref COMP_1_HI
 *                      - \ref COMP_2_HI
 * @param[in]  eCH  :  Select the comparator input channel
 *                     See COMP_CHSelEnum for details
 *                      - \ref FROM_PGAxN_OUT
 *                      - \ref FROM_PGAxP_OUT
 *                      - \ref FROM_PGAxN_IN
 *                      - \ref FROM_PGAxP_IN
 *
 * @return     PWM current counter (16 bit)
 *
 * @example    COMP_SetChannel(COMP_0_HI,FROM_PGAxN_IN)
 *             Note that COMPx can only select PGAx channel.
 *             The above means COMP_0_HI comparator input channel is from PGA0 negative input
 *
 *******************************************************************************/
#define COMP_SelectChannel(eCOMP,eCH)       (COMP->COMPSEL.all = (COMP->COMPSEL.all & (~(COMPSEL_ALL_CHSEL0_Msk<<((eCOMP%3)*2)))) | ((eCH)<<((eCOMP%3)*2)))




/****************************************************************************//**
 * @brief      Enable DAC function
 *
 * @param[in]  none
 *
 * @return     none
 *
 * @details    This function enable DAC High and DAC Low function at the same time
 *             All 3 COMP_HI are share the same DAC Highe value as its negative input.
 *             The 3 COMP_LO are the same but from DAC Low value.
 *             In motor control application, this 6 comparator can realize phase current protection
 *             easily even if the current sensing voltage is level shift at 1.65V
 *             Our design can also turn off all 3 phase PWM if only one phase over current.
 *             Please reference the trip zone function/datasheet and API in motor_pwm.c
 *
 *******************************************************************************/
#define COMP_EnableDAC()                    (COMP->DACCTL.all = DACCTL_ALL_DIVSRCLO_VDDX_DRV | DACCTL_ALL_DIVSRCHI_VDDX_DRV|DACCTL_ALL_ENHI_ENABLE|DACCTL_ALL_ENLO_ENABLE)




/****************************************************************************//**
 * @brief      Set DAC High/Low value
 *
 * @param[in]  x:  Range from 0(0 voltage) ~ 1023 (3.3 Voltage)
 *
 * @return     none
 *
 *******************************************************************************/
#define COMP_SetHighDACValue10Bit(x)        (COMP->DACCODE.all = (COMP->DACCODE.all & (~DACCODE_ALL_HI_Msk)) | DACCODE_ALL_HI_(x))
#define COMP_SetLowDACValue10Bit(x)         (COMP->DACCODE.all = (COMP->DACCODE.all & (~DACCODE_ALL_LO_Msk)) | DACCODE_ALL_LO_(x))




/****************************************************************************//**
 * @brief      Set DAC High value in milli voltage
 *
 * @param[in]  i32ValueMV: Range from 0(0 voltage) ~ 3300 (3300 mV = 3.3 V)
 *
 * @return     none
 *
 *******************************************************************************/
__STATIC_INLINE void COMP_SetHighDACValueMV(int32_t i32ValueMV)
{
  int32_t i32Val;
  i32Val = (i32ValueMV*1024)/3300;
  
  if(i32Val > 1023) i32Val = 1023;
  if(i32Val < 0)    i32Val = 0;
  
  COMP_SetHighDACValue10Bit(i32Val);
}




/****************************************************************************//**
 * @brief      Set DAC Low value in milli voltage
 *
 * @param[in]  i32ValueMV: Range from 0(0 voltage) ~ 3300 (3300 mV = 3.3 V)
 *
 * @return     none
 *
 *******************************************************************************/
__STATIC_INLINE void COMP_SetLowDACValueMV(int32_t i32ValueMV)
{
  int32_t i32Val;
  
  i32Val = (i32ValueMV*1024)/3300;
  
  if(i32Val > 1023) i32Val = 1023;
  if(i32Val < 0)    i32Val = 0;
  
  COMP_SetLowDACValue10Bit(i32Val);
}




/****************************************************************************//**
 * @brief      Get the comparator output status
 *
 * @param[in]  eCOMP:  Select the comparator
 *
 * @return     0 or 1
 *
 *******************************************************************************/
#define COMP_GetOutputStatus(eCOMP)         ((ADC->ADCSTS.all & (ADCSTS_ALL_COMP0L_Msk<<(eCOMP)))>>(eCOMP))




/**
 *  @brief  Comparator Public Function Declaration
 */
void COMP_Init(COMP_ComparatorSelEnum eCOMP, COMP_CHSelEnum eCH, int32_t i32DACVoltageMV, uint32_t u32DeglicthTimeNs);

void COMP_SetDeglitchTimeNs(uint32_t u32TimeNS);

#ifdef __cplusplus
}
#endif /* extern "C" */

#endif /* COMP_H */


/******************* (C) COPYRIGHT 2021 SPINTROL LIMITED CO. *****END OF FILE****/
