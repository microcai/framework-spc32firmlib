#include "spc1068.h"
#include <stdio.h>

#include "driver_i2c.h"


uint8_t au8AdcResult[16] = { 89, 0xAB, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18};
uint8_t u8Count = 0;
uint8_t u8AdcCount = 0;




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
  
  
  /*** I2C Pin Config ***/
  GPIO_SetPinChannel(GPIO_1, GPIO1_I2C_SDA);
  GPIO_SetPinChannel(GPIO_27, GPIO27_I2C_SCL);
  
  /* Enable I2C Module Clock */
  CLOCK_EnableModule(I2C_MODULE);
  
  /* I2C Slave Init */
  I2C_SlaveInit(I2C, I2C_ADDR_7BIT, 0x09);
  
  /* Disable I2C All interrupts */
  I2C_DisableAllInt(I2C);
  /* Enable Read Request interrupt */
  I2C_EnableReadRequestInt(I2C);
  
  /* Enable I2C interrupt in CPU side */
  NVIC_EnableIRQ(I2C_IRQn);
  
  
  /* Enable ADC Module Clock */
  CLOCK_EnableModule(ADC_MODULE);
  /* Init GPIO9 as ADC input */
  ADC_EasyInit1(ADC_SOC_0, ADC8_GPIO9, ADCTRIG_Software);
  
  
  /* Timer0 Init */
  TIMER_Init(TIMER0, 50);
  
  /* Enable TIMER0 INT in CPU side */
  NVIC_EnableIRQ(TIM0_IRQn);
  
  
  printf("Test I2C slave begin\n");
  
  while(1)
  {
  }
}


void TIM0_IRQHandler(void)
{
  uint16_t u16Result;
  
  /* Trigger ADC */
  ADC_SoftwareTrigger(ADC_SOC_0);
  
  /* Get ADC result data */
  u16Result = ADC_GetTrimResult1(ADC_SOC_0);
  
  au8AdcResult[u8AdcCount] = u16Result & 0xFF;
  au8AdcResult[u8AdcCount++] = (u16Result >> 8) & 0xFF;
  
  if (u8AdcCount < 15)
    u8AdcCount++;
  else
    u8AdcCount = 0;
  
  TIMER_ClearInt(TIMER0);
}


void I2C_IRQHandler(void)
{
  /* Get I2C Read Request interrupt flag */
  if(I2C_GetReadRequestIntFlag(I2C))
  {
    if(u8Count < 15)
      u8Count++;
    else
      u8Count = 0;
    
    /* Send Data */
    I2C_SendByte(I2C, au8AdcResult[u8Count]);

    /* Clear Read Request interrupt flag */
    I2C_ClearInt(I2C,I2C_INT_RD_REQ);
  }
  
  I2C_ClearInt(I2C,I2C_INT_ALL);
}
