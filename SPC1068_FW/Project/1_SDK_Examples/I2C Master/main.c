#include "spc1068.h"
#include <stdio.h>

#include "driver_i2c.h"


uint16_t u16AdcData = 0x1234;
uint8_t au8AdcArray[2];




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
  
  printf("I2C master test...\n");
  
  
  /* Config I2C related GPIO */
  GPIO_SetPinChannel(GPIO_1, GPIO1_I2C_SDA);
  GPIO_SetPinChannel(GPIO_27, GPIO27_I2C_SCL);
  
  /* Enable I2C Module Clock */
  CLOCK_EnableModule(I2C_MODULE);
  
  /* I2C Master Init */
  I2C_MasterInit(I2C, I2C_ADDR_7BIT, 0x09);


  /* Timer0 Init */
  TIMER_Init(TIMER0, 1000);
  
  /* Enable TIMER0 interrupt */
  NVIC_EnableIRQ(TIM0_IRQn);
  
  
  printf("Test begin\n");

  while(1)
  {
  }
}


void TIM0_IRQHandler(void)
{
  /* Read ADC Data from I2C slave */
  i2c_master_read(au8AdcArray, 2);
  
  u16AdcData = (au8AdcArray[1]<<8) + au8AdcArray[0];
  
  printf("ADC Data = 0x%08X\n", u16AdcData);
  
  TIMER_ClearInt(TIMER0);
}
