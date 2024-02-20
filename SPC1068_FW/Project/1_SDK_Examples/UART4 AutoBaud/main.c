#include "spc1068.h"
#include <stdio.h>


#define LED         GPIO_19


uint8_t autoBaud = 0;




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
  
  
Autobaud: 
  UART->UARTABR.bit.ABE   = UARTABR_BIT_ABE_ENABLE;              /* Enable Autobaud detect */
  UART->UARTABR.bit.ABUP  = UARTABR_BIT_ABUP_UART_PROG_DIVISOR;  /* UART unit programs Divisor Latch registers */
  UART->UARTABR.bit.ABLIE = UARTABR_BIT_ABLIE_ENABLE;            /* Enable Autobuad lock interrupt */
  UART->UARTABR.bit.ABT   = UARTABR_BIT_ABT_FORMULA;             /* Formula used to calculate baud rates */
  
  UART->UARTLCR.bit.WLS   = UARTLCR_BIT_WLS_8_DATA_BIT;          /* 8 databits */
  UART->UARTLCR.bit.STB   = UARTLCR_BIT_STB_1_STOP_BIT;          /* 1 stop bit */
  UART->UARTLCR.bit.EPS   = UARTLCR_BIT_PEN_NO_PARITY;           /* No parity  */
  
  /* Enable UART unit */
  UART_Enable(UART);

  /* Enable UART interrupt */
  UART_EnableInt(UART);
  
  /* Enable UART interrupt in CPU side */
  NVIC_EnableIRQ(UART_IRQn);
  
  
  /* Wait auto-baud lock */
  while(autoBaud == 0);
  
  /* Disable auto-baud detect */
  UART->UARTABR.bit.ABE = 0;
  /* Disable auto-baud lock interrupt */
  UART->UARTABR.bit.ABLIE = 0;
  
  
  /* Wait data received */
  while(!UART_IsRxDataReady(UART));
  
  /* Read data and validate it */
  while(UART_ReadByte(UART) != 0x01)
  {
    UART_Disable(UART);
    goto Autobaud;
  }

  printf("Auto-baud success!\n");
  
  /* Enable receive data available interrupt */
  UART_EnableRxDataAvailableInt(UART);
  
  
  while(1)
  {
    Delay_ms(1000);
    
    GPIO_TogglePin(LED);
  }
}




void UART_IRQHandler(void)
{
  /* Auto-baud locked */
  if(UART->UARTIIR_UARTFCR.UARTIIR.bit.ABL == 1)
  {
    autoBaud = 1;
  }
  
  /* Receive data available */
  if(UART_GetRxDataAvailableIntStatus(UART))
  {
    /* Write data back */
    UART_WriteByte(UART, UART_ReadByte(UART));
  }
}
