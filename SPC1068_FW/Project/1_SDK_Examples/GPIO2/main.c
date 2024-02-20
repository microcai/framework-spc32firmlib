#include "spc1068.h"
#include <stdio.h>


GPIO_PinEnum GPIO_OutX;
GPIO_PinEnum GPIO_InX;

uint8_t u8Flag = 0;




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
  /* GPIO0 also used as BOOT pin, 
     (1) Set GPIO0 high, then reset chip, chip will running code 
     (2) Then Toggle GPIO0, GPIO15 output waveform will change accordingly 
  */
  GPIO_InX  = GPIO_0;
  GPIO_OutX = GPIO_15;
  
  /* Set GPIO pin function */
  GPIO_SetPinAsGPIO(GPIO_InX);
  GPIO_SetPinAsGPIO(GPIO_OutX);
  
  /* Set GPIO direction */
  GPIO_SetPinDir(GPIO_InX,  GPIO_INPUT);
  GPIO_SetPinDir(GPIO_OutX, GPIO_OUTPUT);

  /* GPIO Interrupt configuration: Rising and Falling edge will trigger interrupt */
  GPIO_SetEdgeIntMode(GPIO_InX, GPIO_INT_BOTH_EDGES);
  GPIO_EnableEdgeInt(GPIO_InX);
  
  /* Enable GPIO Edge-trigger interrupt */
  NVIC_EnableIRQ(GPIO_EDGE_IRQn);
  
  
  while(1)
  {
    /* If GPIO_InX = 1, toggle GPIO_OutX every 100 ms */
    if(u8Flag)
    {
      GPIO_WritePin(GPIO_OutX, GPIO_LEVEL_HIGH);
      Delay_ms(100);
      
      GPIO_WritePin(GPIO_OutX, GPIO_LEVEL_LOW);
      Delay_ms(100);
      
      printf("Toggle GPIO_%d every 200 ms\n", GPIO_OutX);
    }
    /* If GPIO_InX = 0, toggle GPIO_OutX every 500 ms */
    else
    {
      GPIO_WritePin(GPIO_OutX, GPIO_LEVEL_HIGH);
      Delay_ms(500);
      
      GPIO_WritePin(GPIO_OutX, GPIO_LEVEL_LOW);
      Delay_ms(500);
      
      printf("Toggle GPIO_%d every 1 second\n", GPIO_OutX);
    }
  }
}




/* GPIO Edge Interrupt Handler */
void GPIOEdge_IRQHandler()
{
  if(GPIO_ReadPin(GPIO_InX))
    u8Flag = 1;
  else
    u8Flag = 0;
  
  GPIO_ClearEdgeInt(GPIO_InX);
}
