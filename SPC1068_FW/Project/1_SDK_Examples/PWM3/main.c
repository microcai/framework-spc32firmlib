#include "spc1068.h"
#include <stdio.h>


#define PWM_Frequency       5000        /* 5kHz PWM  */
#define PWM_Deadband_NS     2000        /* unit is ns */




int main()
{
  uint16_t u16PrdVal = 0;
  uint16_t u16DeadbandDelay = 0;
  
  
  /**********Initial Step************
   *
   *  In SPC1068, the recommand basic intial step is as followed
   *  (1) System initial
   *  (2) Clock initial
   *  (3) Delay Initial
  */


  /*----------------------------------------------------------------- 
     Step 1: System initial
     Load calibration parameter from flash, please do not modify this function.
  ------------------------------------------------------------------*/
  Sys_Init();

  /*----------------------------------------------------------------- 
     Step 2: Clock initial
         This function initial CPU(HCLK) and configure all IP clock as fast as 
         HCLK. Except for ADC, PCLK and QSPI whose clock have limit.
    Note:
     (1) SPC1068 provide RC Oscillator with 1% precision at full temperature range
     (2) If external crystal is as clock source, please use
              CLOCK_Init(CLOCK_FROM_XTAL8MHZ,CLOCK_HCLK_75MHZ);
         to initial clock however with larger code size.
  ------------------------------------------------------------------*/
  CLOCK_InitWithRCO(CLOCK_HCLK_150MHZ);
  /* Optional function for more flexibility */
  //CLOCK_Init(CLOCK_FROM_XTAL8MHZ,CLOCK_HCLK_100MHZ);
 
  
  /*----------------------------------------------------------------- 
     Step 3. Delay initial
     In this demo code, Delay is realized with timer2 which can provide a precision
     delay. Clock of Timer is from PCLK.
  ------------------------------------------------------------------*/
  Delay_Init();
  
  
  /* Enable PWM1 and PWM2 clock */
  CLOCK_EnableModule(PWM1_MODULE);
  CLOCK_EnableModule(PWM2_MODULE);
  
  /* Set GPIO pin as PWM1 output pin */
  GPIO_SetPinChannel(GPIO_28, GPIO28_PWM1A);
  GPIO_SetPinChannel(GPIO_29, GPIO29_PWM1B);
  
  /* Set frequecny of PWM1 */
  u16PrdVal = CLOCK_GetPWMModuleClk(PWM1) / PWM_Frequency / 2;
  PWM_SetPeriodValue(PWM1, u16PrdVal);
  PWM_SetCMPA(PWM1, u16PrdVal / 2);       /* PWM Duty = 50% */
  
  /* Following 3 configurations are by default */
  PWM1->TBCTL.bit.PRDLD      = TBCTL_BIT_PRDLD_TBPRD_FROM_SHADOW;
  PWM1->CMPCTL.bit.SHDWAMODE = CMPCTL_BIT_SHDWAMODE_SHADOW_MODE;
  PWM1->CMPCTL.bit.LOADAMODE = CMPCTL_BIT_LOADAMODE_LOAD_ON_ZERO;

  /* Configure output action */
  PWM1->AQCTLA.bit.CAU = AQCTLA_BIT_CAU_SET_HIGH;
  PWM1->AQCTLA.bit.CAD = AQCTLA_BIT_CAD_SET_LOW;
  
  /* Configure Deadband */
  PWM1->DBCTL.all |=   DBCTL_ALL_INMODE_0
                     | DBCTL_ALL_POLSEL_MODE_AHL      /* Active High complementary */
                     | DBCTL_ALL_OUTMODE_3            /* PWMxA and PWMxB are all from dead band generator */
                     | DBCTL_ALL_HALFCYCLE_DISABLE;
  
  u16DeadbandDelay = (PWM_Deadband_NS * (CLOCK_GetPWMModuleClk(PWM1)/100000)) / 10000;
  /* Deadband falling edge delay */
  PWM_DeadBandFallingDelay(PWM1, u16DeadbandDelay);
  /* Deadband rising edge delay */
  PWM_DeadBandRisingDelay(PWM1, u16DeadbandDelay);
  
  /* Start PWM1 */
  PWM_CounterRunControl(PWM1, COUNT_UP_DOWN_AND_RUN);




  /* Set GPIO pin as PWM2 output pin */
  GPIO_SetPinChannel(GPIO_30, GPIO30_PWM2A);
  GPIO_SetPinChannel(GPIO_31, GPIO31_PWM2B);
  
  /* Set frequecny of PWM2 */
  u16PrdVal = CLOCK_GetPWMModuleClk(PWM2) / PWM_Frequency / 2;
  PWM_SetPeriodValue(PWM2, u16PrdVal);
  PWM_SetCMPA(PWM2, u16PrdVal / 2);       /* PWM Duty = 50% */
  
  /* Following 3 configurations are by default */
  PWM2->TBCTL.bit.PRDLD      = TBCTL_BIT_PRDLD_TBPRD_FROM_SHADOW;
  PWM2->CMPCTL.bit.SHDWAMODE = CMPCTL_BIT_SHDWAMODE_SHADOW_MODE;
  PWM2->CMPCTL.bit.LOADAMODE = CMPCTL_BIT_LOADAMODE_LOAD_ON_ZERO;

  /* Configure output action */
  PWM2->AQCTLA.bit.CAU = AQCTLA_BIT_CAU_SET_HIGH;  
  PWM2->AQCTLA.bit.CAD = AQCTLA_BIT_CAD_SET_LOW; 
  
  /* Configure Deadband */
  PWM2->DBCTL.all |=  DBCTL_ALL_INMODE_0 
                    | DBCTL_ALL_POLSEL_MODE_AHL       /* Active High complementary */
                    | DBCTL_ALL_OUTMODE_3             /* PWMxA and PWMxB are all from dead band generator */
                    | DBCTL_ALL_HALFCYCLE_DISABLE;
  
  u16DeadbandDelay = (PWM_Deadband_NS * (CLOCK_GetPWMModuleClk(PWM2)/100000)) / 10000 ;
  /* Deadband falling edge delay */
  PWM_DeadBandFallingDelay(PWM2, u16DeadbandDelay);
  /* Deadband rising edge delay */
  PWM_DeadBandRisingDelay(PWM2, u16DeadbandDelay);
  
  /* Start PWM2 */
  PWM_CounterRunControl(PWM2,COUNT_UP_DOWN_AND_RUN);
  
  
  
  
  /* Enalbe PWM1 send out SYNC signal when TBCNT == 0 */
  PWM1->TBCTL.bit.SYNCOSEL = TBCTL_BIT_SYNCOSEL_TBCNT_EQU_ZERO;
  /* PWM2 phase delay */
  PWM2->TBPHS.all = 0;
  /* PWM2 count up after SYNC */
  PWM2->TBCTL.bit.PHSDIR = TBCTL_BIT_PHSDIR_COUNT_UP_AFTER_SYNC;
  /* Enalbe PWM2 SYNC function */
  PWM2->TBCTL.bit.PHSEN = ENABLE;
  
  
  
  
  /* Enable PWM1 TBCNT = TBPRD event */
  PWM_SetTimeEvtTiming(PWM1,EQU_PERIOD);
  PWM_SetTimeEvtPeriod(PWM1,ON_1ST_EVENT);
  PWM_EnableTimeEvtINT(PWM1);
  
  /* Enable PWM1 Interrupt in CPU side */
  NVIC_EnableIRQ(PWM1_IRQn);
  

  while(1)
  {
   
  }
}



uint32_t u32Count = 0;

void PWM1_IRQHandler(void)
{
  u32Count++;
  
  /* Update PWM2 phase delay */
  PWM2->TBPHS.all = u32Count % PWM_GetPeriodValue(PWM1);
  
  /* Clear interrupt flag */
  PWM_ClearTimeEvtInt(PWM1);
}
