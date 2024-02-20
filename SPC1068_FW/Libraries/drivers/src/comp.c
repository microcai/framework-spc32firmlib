/**************************************************************************//**
 * @file     comp.c
 * @brief    This file provides COMPARATOR firmware functions.
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


#include "comp.h"




/****************************************************************************//**
 * @brief      Configure Comparator
 *
 * @param[in]  eCOMP            :  Select the comparator
 *                                 See COMP_ComparatorSelEnum for details
 *                                  - \ref COMP_0_LO
 *                                  - \ref COMP_1_LO
 *                                  - \ref COMP_2_LO
 *                                  - \ref COMP_0_HI
 *                                  - \ref COMP_1_HI
 *                                  - \ref COMP_2_HI
 * @param[in]  eCH              :  Select the comparator input channel
 *                                 See COMP_CHSelEnum for details
 *                                  - \ref FROM_PGAxN_OUT
 *                                  - \ref FROM_PGAxP_OUT
 *                                  - \ref FROM_PGAxN_IN
 *                                  - \ref FROM_PGAxP_IN
 * @param[in]  i32DACVoltageMV  :  DAC voltage range from 0(0 voltage) ~ 3300 (3300 mV = 3.3 V)
 *                                 Note that if COMP_x_HI is selected, program will config correspond DAC
 *                                 That is, if COMP_0_HI is selected and DAC_HI is configured.
 * @param[in]  u32DeglicthTimeNs:  Deglitch window size (nero second)
 *                                 This function clock source from CLK0 
 *                                 If CLK0=100MHZ, its range from 0~127*(1/100MHz)=1270 ns= 1.27 us
 *                                 If CLK0=150MHZ, its range from 0~127*(1/150MHz)=846 ns
 *
 * @return     none
 *
 * @example    Configure protection in 3 phase currents whose signal is amplified by PGA inside
 *             VoltageUpperBond = 1650+X;
 *             VoltageLowerBond = 1650-X;
 *             FilterTimeNs = 300;
 *             COMP_Init(COMP_0_LO,FROM_PGAxP_OUT,VoltageLowerBond,FilterTimeNs);  //COMP_0_LO input select PGA0P output (I_U)
 *             COMP_Init(COMP_1_LO,FROM_PGAxP_OUT,VoltageLowerBond,FilterTimeNs);  //COMP_1_LO input select PGA1P output (I_V)
 *             COMP_Init(COMP_2_LO,FROM_PGAxP_OUT,VoltageLowerBond,FilterTimeNs);  //COMP_2_LO input select PGA2P output (I_W)
 *             COMP_Init(COMP_0_HI,FROM_PGAxP_OUT,VoltageUpperBond,FilterTimeNs);  //COMP_0_HI input select PGA0P output (I_U)
 *             COMP_Init(COMP_1_HI,FROM_PGAxP_OUT,VoltageUpperBond,FilterTimeNs);  //COMP_1_HI input select PGA1P output (I_V)
 *             COMP_Init(COMP_2_HI,FROM_PGAxP_OUT,VoltageUpperBond,FilterTimeNs);  //COMP_2_HI input select PGA2P output (I_W)
 *
 *             Then user can use 
 *                PWM_EnableOneShotTripFromComp()
 *             to shut down(trip) PWM when over current.
 *
 * @note       (1) All 3 COMP_x_LO share same DAC_LO
 *             (2) All 3 COMP_x_HI share same DAC_HI
 *             (3) This function do NOT saturate DAC value and deglitch(filter) value, please note it!
 *
 *******************************************************************************/
void COMP_Init(COMP_ComparatorSelEnum eCOMP, COMP_CHSelEnum eCH, int32_t i32DACVoltageMV, uint32_t u32DeglicthTimeNs)
{
  CLOCK_EnableModule(COMP_MODULE);
  
  /* Enable comparator */
  COMP_Enable(eCOMP);
  
  COMP_SelectChannel(eCOMP, eCH);
  COMP_SetDeglitchTimeNs(u32DeglicthTimeNs);
  COMP_EnableDeglitch();

  /* Enable DAC for comparison */
  COMP_EnableDAC();
  
  if(eCOMP>=COMP_0_HI){ COMP_SetHighDACValueMV(i32DACVoltageMV); }
  else { COMP_SetLowDACValueMV(i32DACVoltageMV); }
  
  COMP_ClearAllOutputStatus();
}




/****************************************************************************//**
 * @brief      Set deglitch window size (nero second)
 *
 * @param[in]  u32TimeNS: Time in ns
 *
 * @return     none
 *
 * @details    The output state(0 or 1) must be consistent for COMP->COMPCTL.bit.DGPRDSEL 
 *             consecutive clocks before change
 *             This function translate the nero second to clock and make it easier to configure.
 *             This clock is from CLK0 in the system.
 *
 *******************************************************************************/
void COMP_SetDeglitchTimeNs(uint32_t u32TimeNS)
{
  uint32_t u32TimeCnt;
  
  u32TimeCnt = (((u32TimeNS) * (CLOCK_GetModuleClk(COMP_MODULE) / 100000 )) / 10000);
  if(u32TimeCnt > 127) u32TimeCnt = 127;
  
  COMP->COMPCTL.bit.DGPRDSEL = u32TimeCnt;  /* DGPRDSEL is 7-bit length */
}


/******************* (C) COPYRIGHT 2021 SPINTROL LIMITED CO. *****END OF FILE****/
