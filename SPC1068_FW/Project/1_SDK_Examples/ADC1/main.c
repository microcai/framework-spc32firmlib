/**************************************************************************//**
 * @file     ADC1/main.c
 * @brief    Main program body
 * @version  V1.1.0
 * @date     03-August-2017
 *
 * @note
 * Copyright (C) 2017 Spintrol Limited Corporation. All rights reserved.
 *
 * @attention
 * THIS SOFTWARE JUST PROVIDES CUSTOMERS WITH CODING INFORMATION REGARDING 
 * THEIR PRODUCTS, WHICH AIMS AT SAVING TIME FOR THEM. SPINTROL SHALL NOT BE
 * LIABLE FOR THE USE OF THE SOFTWARE. SPINTROL DOES NOT GUARANTEE THE 
 * CORRECTNESS OF THIS SOFTWARE AND RESERVES THE RIGHT TO MODIFY THE SOFTWARE 
 * WITHOUT NOTIFICATION.
 *
 ******************************************************************************/

#include "spc1068.h"
#include <stdio.h>


/**
 *  @brief  Define LED driver pin
 */
#define LED             (GPIO_19)




/**
 *  @brief  Variable for ADC result
 */
int16_t i16VSP;




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
  
  
  /* ADC Init */
  ADC_EasyInit1(ADC_SOC_0, ADC8_GPIO9, ADCTRIG_Software);
  
  while(1)
  {
    /* Software trigger */
    ADC_SoftwareTrigger(ADC_SOC_0);
    
    /* Wait until ADC conversion finished (Interrupt flag is set) */
    while(!ADC_GetIntFlag(ADC_SOC_0));
    
    /* Get result (already trimmed and rescale from 0~4095) */
    i16VSP = ADC_GetTrimResult1(ADC_SOC_0);
    
    /* Clear interrupt flag */
    ADC_ClearInt(ADC_SOC_0);
    
    printf("ADC Trim Result = %d\n", i16VSP);
    
    Delay_ms(500);
    
    /* Toggle LED */
    GPIO_TogglePin(LED);
  }
}
