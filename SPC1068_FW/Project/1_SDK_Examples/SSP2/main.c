#include "spc1068.h"
#include <stdio.h>


uint32_t u8DataToSend[32] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,11,12,13,14,15,
                              16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31};
uint32_t u8DataToRev[32];


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

  /* Set Tx FIFO trigger threshold */
  SSP_SetTxFifoTriggerLevel(SSP, 0);
  
  /* Enable Tx FIFO empty interrupt */
  SSP_EnableTxFifoEmptyInt(SSP);
  
  /* Enable SSP interrupt in CPU side */
  NVIC_EnableIRQ(SSP_IRQn);

  while(1)
  {
  }
}


void SSP_IRQHandler()
{
  int i;
  
  /* Receive Data */
  SSP_Recv(SSP, u8DataToRev,0,8);
  printf("Rev  (0)%X,(1)%X,(2)%X,(3)%X,(4)%X,(5)%X,(6)%X,(7)%X \n\n",
         u8DataToRev[0],
         u8DataToRev[1],
         u8DataToRev[2],
         u8DataToRev[3],
         u8DataToRev[4],
         u8DataToRev[5],
         u8DataToRev[6],
         u8DataToRev[7]);
  
  Delay_ms(2000);
  
  for(i = 0; i < 8; i++)
  {
    u8DataToSend[i]++;
  }
  
  /* Send Data */
  printf("Send (0)%X,(1)%X,(2)%X,(3)%X,(4)%X,(5)%X,(6)%X,(7)%X \n",
       u8DataToSend[0],
       u8DataToSend[1],
       u8DataToSend[2],
       u8DataToSend[3],
       u8DataToSend[4],
       u8DataToSend[5],
       u8DataToSend[6],
       u8DataToSend[7]);
  SSP_Send(SSP, u8DataToSend,0,8);
  
  Delay_ms(100);
}
