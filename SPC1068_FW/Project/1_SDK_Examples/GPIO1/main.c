#include "spc1068.h"
#include <stdio.h>


GPIO_PinEnum GPIO_OutX;
GPIO_PinEnum GPIO_InX;




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
  
  
  /* Configure GPIO pin as UART function */
  GPIO_SetPinChannel(GPIO_34, GPIO34_UART_TXD);
  GPIO_SetPinChannel(GPIO_35, GPIO35_UART_RXD);
  
  /* Enable UART Clock */
  CLOCK_EnableModule(UART_MODULE);
  
  /* UART Init */
  UART_Init(UART, 38400);
  
  
  /* Select GPIO pin */
  GPIO_InX  = GPIO_1;
  GPIO_OutX = GPIO_28;
  
  /* Set GPIO pin function */
  GPIO_SetPinAsGPIO(GPIO_InX);
  GPIO_SetPinAsGPIO(GPIO_OutX);
  
  /* Set GPIO direction */
  GPIO_SetPinDir(GPIO_InX,  GPIO_INPUT);
  GPIO_SetPinDir(GPIO_OutX, GPIO_OUTPUT);

  while(1)
  {
    /* If GPIO_InX = 1, toggle GPIO_X every 100 ms */
    if(GPIO_ReadPin(GPIO_InX) == GPIO_LEVEL_HIGH)
    {
      GPIO_WritePin(GPIO_OutX, GPIO_LEVEL_HIGH);
      Delay_ms(100);
      
      GPIO_WritePin(GPIO_OutX, GPIO_LEVEL_LOW);
      Delay_ms(100);
      
      printf("Toggle GPIO_%d every 200 ms\n", GPIO_OutX);
    }
    else /* If GPIO_InX = 0, toggle GPIO_X every 500 ms */
    {
      GPIO_WritePin(GPIO_OutX, GPIO_LEVEL_HIGH);
      Delay_ms(500);
      
      GPIO_WritePin(GPIO_OutX, GPIO_LEVEL_LOW);
      Delay_ms(500);
      
      printf("Toggle GPIO_%d every 1 second\n", GPIO_OutX);
    }
  }
}
