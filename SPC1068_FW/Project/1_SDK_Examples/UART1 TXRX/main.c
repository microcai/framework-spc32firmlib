#include "spc1068.h"
#include <stdio.h>


#define LED         GPIO_19


uint8_t u8TempData = 0x55;
uint8_t u8TempData2 = 0x0;




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
  
  
  /* Enable Internal loopback for ease of test */
  UART_EnableLoopBackMode(UART);
  
  /* Enable RX data interrupt */
  UART_EnableRxDataAvailableInt(UART);
  /* Enable UART interrupt (main switch of UART interrupt) */
  UART_EnableInt(UART);
  
  /* Enable UART interrupt in CPU side */
  NVIC_EnableIRQ(UART_IRQn);
  
  
  /* Send a byte to trigger the loop */
  UART_WriteByte(UART, u8TempData);
  
  
  while(1)
  {
  }
}




void UART_IRQHandler(void)
{ 
  u8TempData2 = u8TempData;
  
  /* Read UART reception buffer */
  u8TempData = UART_ReadByte(UART);
  
  /* If data correct */
  if((u8TempData2+1) == u8TempData)
  {
    /* Toggle LED  */
    GPIO_TogglePin(LED);
  }
  
  Delay_ms(100);
  
  /* Send data again */
  UART_WriteByte(UART, u8TempData +1);
}
