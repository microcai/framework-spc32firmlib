#include "spc1068.h"
#include <stdio.h>


#define GPIO_InX      (GPIO_1)
#define GPIO_OutX     (GPIO_19)




int main()
{
  uint16_t u16PrdVal = 0;
  
  
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
  
  
  /* Configure GPIO pin as UART function */
  GPIO_SetPinChannel(GPIO_34, GPIO34_UART_TXD);
  GPIO_SetPinChannel(GPIO_35, GPIO35_UART_RXD);
  
  /* Enable UART Clock */
  CLOCK_EnableModule(UART_MODULE);
  
  /* UART Init */
  UART_Init(UART, 38400);
  
  
  /* Enable PWM1 Clock */ 
  CLOCK_EnableModule(PWM1_MODULE);
  
  /* Set GPIO as PWM1 output pin */
  GPIO_SetPinChannel(GPIO_28, GPIO28_PWM1A);
  
  
  /* Set frequecny of PWM1 */
  u16PrdVal = 500;     /* It can enter interrupt     */
//  u16PrdVal = 40;      /* It can not enter interrupt */
  PWM1->TBPRD.all = u16PrdVal;
  PWM1->CMPA.all = u16PrdVal / 2;   /* PWM Duty = 50% */
 
  /* Following 3 configurations are by default */
  PWM1->TBCTL.bit.PRDLD      = TBCTL_BIT_PRDLD_TBPRD_FROM_SHADOW;
  PWM1->CMPCTL.bit.SHDWAMODE = CMPCTL_BIT_SHDWAMODE_SHADOW_MODE;
  PWM1->CMPCTL.bit.LOADAMODE = CMPCTL_BIT_LOADAMODE_LOAD_ON_ZERO;
  
  /* Configure output action */
  PWM1->AQCTLA.bit.CAU = AQCTLA_BIT_CAU_TOGGLE;
  PWM1->AQCTLA.bit.PRD = AQCTLA_BIT_PRD_TOGGLE;
  
  /* Start PWM1 */
  PWM_CounterRunControl(PWM1, COUNT_UP_AND_RUN);
  
  
  /* Set GPIO pin function */
  GPIO_SetPinAsGPIO(GPIO_InX);
  GPIO_SetPinAsGPIO(GPIO_OutX);
  
  /* Set GPIO direction */
  GPIO_SetPinDir(GPIO_InX,  GPIO_INPUT);
  GPIO_SetPinDir(GPIO_OutX, GPIO_OUTPUT);

  /* De-glitch settings, if IO signal state in 128 PCLK cycles, then it is assumed valid */
  GPIO_SetDeglitchWindow(GPIO_DEGLITCH_WINDOW_128);
  GPIO_EnableDeglitch(GPIO_InX);


  /* GPIO Interrupt configuration: Rising edge will trigger interrupt */
  GPIO_SetEdgeIntMode(GPIO_InX, GPIO_INT_RISING_EDGE);
  GPIO_EnableEdgeInt(GPIO_InX);
  
  /* Enable GPIO Edge-triggered interrupt in CPU side */
  NVIC_EnableIRQ(GPIO_EDGE_IRQn);

  while(1)
  {}
}



void GPIOEdge_IRQHandler()
{
  /* Toggle GPIO */
  GPIO_TogglePin(GPIO_OutX);
  
  printf("x");
  
  /* Clear interrupt flag */
  GPIO_ClearEdgeInt(GPIO_InX);
}
