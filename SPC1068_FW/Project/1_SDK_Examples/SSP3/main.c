#include "spc1068.h"
#include <stdio.h>


uint32_t u8DataToSend[32] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,11,12,13,14,15,
                              16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31 };
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
  
  
  /* Enable Clock for SSP & UART */
  CLOCK_EnableModule(UART_MODULE);
  CLOCK_EnableModule(SSP_MODULE);
  
  /* Init UART IOs */
  GPIO_SetPinChannel(GPIO_34, GPIO34_UART_TXD);
  GPIO_SetPinChannel(GPIO_35, GPIO35_UART_RXD);
  
  /* UART init */
  UART_Init(UART, 38400);
  
  
  /* Init SSP IOs */
  GPIO_SetPinChannel(GPIO_19,GPIO19_SPI_CLK);
  GPIO_SetPinChannel(GPIO_20,GPIO20_SPI_FRM);
  GPIO_SetPinChannel(GPIO_21,GPIO21_SPI_MI);
  GPIO_SetPinChannel(GPIO_22,GPIO22_SPI_MO);
  
  /* Init SSP PSP mode */
  SSP_InitEasy(SSP, SSP_MASTER_MODE, 24, 1000000);
  SSP_PSPEasy(SSP,
                10/*Delay between SPI frame, multiply by SPI clk*/,
                24/*SPI data length, will overwrite config in SSP_Init*/);
  SSP_Enable(SSP);
  
 /* Send data by 5ms interval */
  while(1)
  {
    SSP_SendData(SSP,0x555555);
    SSP_SendData(SSP,0x555555);
    SSP_SendData(SSP,0x555555);
    SSP_SendData(SSP,0x555555);
    
    Delay_ms(5);
  }
}
