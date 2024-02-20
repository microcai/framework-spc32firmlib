/**************************************************************************//**
 * @file     pga.c
 * @brief    This file provides PGA firmware functions.
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

 
#include "pga.h"




/****************************************************************************//**
 * @brief      Set Positive channel as commom mode signal 
 *
 * @param[in]  ePGANo:  Select the PGA module
 *                      See PGA_NumEnum for details
 *                       - \ref PGA0
 *                       - \ref PGA1
 *                       - \ref PGA2

 * @return     none
 *
 * @exmaple    If PGA is in differential mode, there should be two input signal
 *             One is common mode signal (VDD/2)
 *             One is signal signal(swaying among VDD/2)
 *             If PGA_DiffInit() is used, the common mode signal default comes into
 *             Negative channel, but SPC1068 supports common mode signal comes into
 *             Positive channel to make the flexibilty of PCB layout.
 *             Please note that even with such feature, the final signal polarity still 
 *             the same, thus
 *             Final signal = Gain*(PositiveCH-NegativeCH)
 *
 *******************************************************************************/
void PGA_SelecPositiveCHAsComInput(PGA_NumEnum ePGANo)
{
  PGA->PGACTL1.all &= (~((PGACTL1_ALL_CMEN0N_Msk  )<<ePGANo));     /* Disable negative CH as common mode input */
  PGA->PGACTL0.all |= ((PGACTL0_ALL_CMEN0P_ENABLE )<<ePGANo);      /* Enable positive CH as common mode input  */
}




/****************************************************************************//**
 * @brief      Set Negative channel as commom mode signal 
 *
 * @param[in]  ePGANo:  Select the PGA module
 *                      See PGA_NumEnum for details
 *                       - \ref PGA0
 *                       - \ref PGA1
 *                       - \ref PGA2

 * @return     none
 *
 * @exmaple    If PGA is in differential mode, there should be two input signal
 *             One is common mode signal (VDD/2)
 *             One is signal signal(swaying among VDD/2)
 *             If PGA_DiffInit() is used, the common mode signal default comes into
 *             Negative channel.
 *
 *******************************************************************************/
void PGA_SelecNegativeCHAsComInput(PGA_NumEnum ePGANo)
{
  PGA->PGACTL1.all |= ((PGACTL1_ALL_CMEN0N_ENABLE )<<ePGANo);      /* Enable negative CH as common mode input */
  PGA->PGACTL0.all &= (~((PGACTL0_ALL_CMEN0P_Msk  )<<ePGANo));     /* Disable positive CH as common mode input  */
}




/****************************************************************************//**
 * @brief      Set PGA in differetial ended mode
 *
 * @param[in]  ePGANo        :  Select the PGA module from
 *                              PGA_NumEnum
 * @param[in]  u8PositiveCHNo:  Select Positive Channel from 
 *                              PGA_CH_P
 * @param[in]  u8NegativeCHNo:  Select Negative Channel from 
 *                              PGA_CH_N
 * @param[in]  u8DiffGain    :  Select PGA amplitue scale from 
 *                              PGA_SCALE
 *
 * @return     none
 *
 * @exmaple    PGA_Init(PGA0,PGA0_CH_P_ADC14,PGA0_CH_N_ADC15,PGA_SCALE_8X)
 *             PGA_Init(PGA1,PGA1_CH_P_ADC11,PGA1_CH_N_ADC10,PGA_SCALE_8X)
 *             PGA_Init(PGA2,PGA2_CH_P_ADC13,PGA2_CH_N_ADC12,PGA_SCALE_8X)
 *
 *******************************************************************************/
void PGA_DiffInit(PGA_NumEnum ePGANo, PGA_CH_P u8PositiveCHNo, PGA_CH_N u8NegativeCHNo, PGA_SCALE u8DiffGain)
{
  /* Check parameters inputs */
#if SPC1068_DRIVER_DEBUG
  if ((ePGANo == u8PositiveCHNo>>4) && ((u8PositiveCHNo>>4)+(u8NegativeCHNo>>4) == 5))
  {
  }
  else
  {
    //printf("Prameter wronng in PGA_Init");
    while (1)
    {}
  }
#endif
  
  uint32_t u32SetGainMask;
  uint32_t u32SetCHMask;
  #define u32PGAMaskTemp (u32SetGainMask|u32SetCHMask)

  /* Enable PGA(ADC) Module Clock */
  CLOCK_EnableModule(PGA_MODULE);
  
  u8PositiveCHNo = (PGA_CH_P)(u8PositiveCHNo & 0xF);
  u8NegativeCHNo = (PGA_CH_N)(u8NegativeCHNo & 0xF);

  u32SetGainMask = PGACHCTL0_ALL_GAIN0P_Msk<<(ePGANo*2);
  u32SetCHMask   = PGACHCTL0_ALL_CHSEL0P_Msk<<(ePGANo*3);

  /* Positive channel enable */ 
  PGA->PGACTL0.all |= (PGACTL1_ALL_EN0N_ENABLE    )<<ePGANo;     /* Enable positive channel                 */

  /* Negative channel enable */ 
  PGA->PGACTL1.all |= (PGACTL1_ALL_EN0N_ENABLE    |              /* Enable negative channel                 */
                       PGACTL1_ALL_RDIVEN0_ENABLE |              /* Enable resistor divider                 */
                       PGACTL1_ALL_CMEN0N_ENABLE  )<<ePGANo;     /* Enable negative CH as common mode input */


  /* Select positve channel and gain */
  PGA->PGACHCTL0.all  = (PGA->PGACHCTL0.all & (~u32PGAMaskTemp)) |
                        (u8PositiveCHNo << (PGACHCTL0_ALL_CHSEL0P_Pos + (3*ePGANo))) |
                        (u8DiffGain     << (PGACHCTL0_ALL_GAIN0P_Pos  + (2*ePGANo))) ;

  /* Select negatve channel and gain */
  PGA->PGACHCTL1.all  = (PGA->PGACHCTL1.all & (~u32PGAMaskTemp)) |
                        (u8NegativeCHNo << (PGACHCTL1_ALL_CHSEL0N_Pos + (3*ePGANo))) |
                        (u8DiffGain     << (PGACHCTL1_ALL_GAIN0N_Pos  + (2*ePGANo))) ;
}




/****************************************************************************//**
 * @brief      Set PGA resistor divider feature
 *
 * @param[in]  ePGANo              :  Select the PGA module from
 *                                    PGA_NumEnum
 * @param[in]  u8ResistDividerValue:  Resitor divider output
 *                                    (u8ResistDividerValue * VDDA / 32)
 *
 * @return     none
 *
 * @exmaple    If you want to set PGA0 resitor output to be 1V, and VDDA is 3.3V, 
 *             then 1/3 *32 = 11, you can use PGA_ResistorDividerConifg(PGA0,11)
 *
 *******************************************************************************/
void PGA_ResistorDividerConifg(PGA_NumEnum ePGANo, uint8_t u5ResistDividerValue)
{
  /* Check parameters inputs */
#if SPC1068_DRIVER_DEBUG
  if (u5ResistDividerValue > 31)
  {
    printf("u8ResistDividerValue should be less than 32");
    while (1)
    {}
  }
#endif
  uint32_t u32SetDivIndex;
  u32SetDivIndex = ePGANo*5;
  PGA->PGACHCTL1.all  = ( PGA->PGACHCTL1.all & (~(PGACHCTL1_ALL_RDIVSEL0_Msk<<u32SetDivIndex))) | 
                        ( PGACHCTL1_ALL_RDIVSEL0_(u5ResistDividerValue) << u32SetDivIndex);

}


/******************* (C) COPYRIGHT 2021 SPINTROL LIMITED CO. *****END OF FILE****/
