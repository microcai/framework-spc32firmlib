#include "spc1068.h"
#include <stdio.h>


/* Buffer stores data to be written to flash security register */
uint8_t au8WriteData[16] = { 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 
                             0x09, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16 };


/* Buffer stores data read from flash security register */
uint8_t au8ReadData[16] = {0};




int main()
{
  ErrorStatus status;
  
  uint32_t i;
  
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
  CLOCK_InitWithRCO(CLOCK_HCLK_24MHZ);
  /* Optional function for more flexibility */
  //CLOCK_Init(CLOCK_FROM_XTAL8MHZ,CLOCK_HCLK_100MHZ); 
 
  
  /*----------------------------------------------------------------- 
     Step 3. Delay initial
     In this demo code, Delay is realized with timer2 which can provide a precision
     delay. Clock of Timer is from PCLK.
  ------------------------------------------------------------------*/
  Delay_Init();


  /* Set GPIO function as UART  */
  GPIO_SetPinChannel(GPIO_34, GPIO34_UART_TXD);
  GPIO_SetPinChannel(GPIO_35, GPIO35_UART_RXD);
  
  /* Enable UART Clock */
  CLOCK_EnableModule(UART_MODULE);
  
  /* UART Init */
  UART_Init(UART, 38400);
  
  
  
  /* Erase flash sector */
  printf("1. Erase flash security register 2\n");
  
  status = FLASH_EraseOTP(FLASH_OTP2_ADDR);
  if(status == ERROR)
  {
    return 1;
  }
  printf("Erase flash security register 2: SUCCESS!\n\n");
  
  
  
  /* Read data from flash */
  printf("2. Read data from flash security register 2:\n");
  FLASH_ReadOTP(au8ReadData, FLASH_OTP2_ADDR, 16);
  for(i = 0; i < 16; i++)
  {
    printf("0x%02X ", au8ReadData[i]);
  }
  printf("\n\n");
  
  
  
  /* Write data to flash */
  printf("3. Write data to flash security register 2:\n");
  for(i = 0; i < 16; i++)
  {
    printf("0x%02X ", au8WriteData[i]);
  }
  printf("\n");
  
  status = FLASH_WriteOTP(au8WriteData, FLASH_OTP2_ADDR, 16);
  if(status == ERROR)
  {
    return 1;
  }
  printf("Write data to flash security register 2: SUCCESS!\n\n");
  
  
  
  /* Read data from flash */
  printf("4. Read data from flash security register 2:\n");
  FLASH_ReadOTP(au8ReadData, FLASH_OTP2_ADDR, 16);
  for(i = 0; i < 16; i++)
  {
    printf("0x%02X ", au8ReadData[i]);
  }
  printf("\n\n");
  
  
  
  /* Lock flash security register 2 */
  /* Be careful: If locked, data in security register 2 can not be changed! */
  /* Be careful: If locked, data in security register 2 can not be changed! */
  /* Be careful: If locked, data in security register 2 can not be changed! */
  printf("5. Lock flash security register 2:\n");
  
  status = FLASH_LockOTP(FLASH_OTP2_LOCK_BIT_Val);
  if(status == ERROR)
  {
    return 1;
  }
  printf("Lock flash security register 2: SUCCESS!\n");
}

