#include "spc1068.h"
#include <stdio.h>


uint8_t u8DataToSend = 0x55;
uint8_t u8DataReceived = 0;


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
  
  
  /* Enable UART and SSP clock */
  CLOCK_EnableModule(UART_MODULE);
  CLOCK_EnableModule(SSP_MODULE);
  
  
  /* Configure GPIO pin as UART function */
  GPIO_SetPinChannel(GPIO_34, GPIO34_UART_TXD);
  GPIO_SetPinChannel(GPIO_35, GPIO35_UART_RXD);
  /* UART Init */
  UART_Init(UART, 38400);
  
  
  /* Init SSP as 1) Master Mode   2) 8 bit frame width, baudrate 2M bps */
  SSP_InitEasy(SSP, SSP_MASTER_MODE, 8, 2000000);

  /* Enable loopback mode for test purpose */
  SSP_EnableLoopBackMode(SSP);
  
  /* Enable SSP */
  SSP_Enable(SSP);

  /* Print data to be sent */
  printf("Data to Send = %4X    ", u8DataToSend);
  
  /* Send data */
  SSP_SendData(SSP, u8DataToSend); 


  while(1)
  {
    /* Wait until SSP receive buffer is not empty, eg. SSP received data */
    while(!SSP_IsRxFifoNotEmpty(SSP)){}
    
    /* Get SSP receive data from buffer */
    u8DataReceived = SSP_ReceiveData(SSP);
    /* Print data received */
    printf("Data Received = %4X\n", u8DataReceived);
    
    Delay_ms(1000);
    
    u8DataToSend = u8DataReceived + 1;
    /* Print data to send */
    printf("Data to Send = %4X    ",u8DataToSend);
    
    /* Send data */
    SSP_SendData(SSP, u8DataToSend);
  }
}

