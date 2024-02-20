#include "spc1068.h"
#include <stdio.h>


/**
 *  @brief  Define LED driver pin
 */
#define LED             (GPIO_19)




/**
 *  @brief  PWM Duty counter and Duty time
 */
uint32_t u32DutyCounter = 0;
uint32_t u32DutyInUs;




/****************************************************************************//**
 * @brief      ECAP Capture Mode Init
 *
 * @param[in]  ECAPx  :  Select the ECAP module
 * @param[in]  ePinNum:  Select the GPIO pin as ECAP input
 *
 * @return     none
 *
 *******************************************************************************/
void ECAP_CaptureModeInit_GetPulseWidth(ECAP_REGS* ECAPx, GPIO_PinEnum ePinNum);




int main()
{
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
  
  
  /* Configure LED driver pin */
  GPIO_SetPinAsGPIO(LED);
  GPIO_SetPinDir(LED, GPIO_OUTPUT);
  
  
  /* Configure GPIO pin as UART function */
  GPIO_SetPinChannel(GPIO_34, GPIO34_UART_TXD);
  GPIO_SetPinChannel(GPIO_35, GPIO35_UART_RXD);
  
  /* Enable UART Clock */
  CLOCK_EnableModule(UART_MODULE);
  
  /* UART Init */
  UART_Init(UART, 38400);


  /* ECAP Init */
  /* Config ECAP to capture the length between rising edge to falling edge */
  ECAP_CaptureModeInit_GetPulseWidth(ECAP, GPIO_22);
  
  /* Clear any pending ECAP interrupts */
  ECAP_ClearCEVT1Int(ECAP);
  ECAP_ClearCntOverflowInt(ECAP);
  ECAP_ClearGlobalInt(ECAP);
  
  /* Enable ECAP interrupt and set its priority */
  NVIC_SetPriority(ECAP_IRQn, 10);
  NVIC_EnableIRQ(ECAP_IRQn);
  
  
  /* Select GPIO23 as PWM0B */
  GPIO_SetPinChannel(GPIO_23, GPIO23_PWM0B);
  
  /* PWM Init - Frequency = 15000 Hz */
  PWM_SingleChannelInit(PWM0, PWM_CHB, 15000);
  /* Start PWM with counting up and down */
  PWM_CounterRunControl(PWM0, COUNT_UP_DOWN_AND_RUN);
  
  /* Now PWM period = 150000000/15000/2 = 5000 */
  /* Change the CMPB value to adjust duty */
  PWM_SetCMPB(PWM0, 4000);

  while(1)
  {
    /* Toggle LED */
    GPIO_TogglePin(LED);
    
    Delay_ms(1000);
    
    u32DutyInUs = u32DutyCounter/150;
    
    printf("Duty is %d us\n", u32DutyInUs);
  }
}




void ECAP_IRQHandler(void)
{
  if(ECAP_GetCEVT1IntFlag(ECAP))
  {
    /* Get the count value */
    u32DutyCounter = ECAP->CAP1.all;
    
    /* Clear CEVT1 */
    ECAP_ClearCEVT1Int(ECAP);
  }
  
  ECAP_ClearGlobalInt(ECAP);
}




void ECAP_CaptureModeInit_GetPulseWidth(ECAP_REGS* ECAPx, GPIO_PinEnum ePinNum)
{
  /* Config IO Pin for capture */
  GLOBAL_SetECAPInputPin(ePinNum);
  
  /* Open ECAP clock */
  CLOCK_EnableModule(ECAP_MODULE);
  
  ECAPx->CAPCTL.all =   CAPCTL_ALL_CAPAPWM_CAPTURE_MODE             /* Config ECAP as Capture mode                */
                      | CAPCTL_ALL_CAPLDEN_CAPTURE_LOAD_ENABLE      /* Enable Capture Register load               */
                      | CAPCTL_ALL_STOPWRAP_ON_CAPTURE_EVENT1       /* Stop/Wrap after Capture Event 3            */
                      | CAPCTL_ALL_MODE_CONTINOUS_MODE              /* Operate in Continous mode                  */
                      | CAPCTL_ALL_CAP0POL_TRIG_ON_RISING_EDGE      /* Event 0 occurs on pulse rising edge        */
                      | CAPCTL_ALL_CAP1POL_TRIG_ON_FALLING_EDGE     /* Event 1 occurs on pulse falling edge       */
                      | CAPCTL_ALL_CNTRST0_RESET_ON_CAPTURE         /* Reset capture counter when Event 0 occurs  */
                      | CAPCTL_ALL_CNTRST1_RESET_ON_CAPTURE         /* Reset capture counter when Event 1 occurs  */
                      | CAPCTL_ALL_TSCNTRUN_START_COUNTER;          /* Enable ECAP working                        */

  /* Enable Capture event interrupt */
  ECAPx->CAPIEIF.all |= CAPIEIF_ALL_IECEVT0_DISABLE | 
                        CAPIEIF_ALL_IECEVT1_ENABLE | 
                        CAPIEIF_ALL_IECEVT0_DISABLE | 
                        CAPIEIF_ALL_IECEVT3_DISABLE | 
                        CAPIEIF_ALL_IECNTOVF_DISABLE;
}
