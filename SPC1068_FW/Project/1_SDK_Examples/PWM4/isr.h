/**************************************************************************//**
 * @file     isr.h
 * @brief    SPC1068 Interrupt ISR Definitions.
 * @version  V1.0.0
 * @date     09-May-2016
 *
 * @note
 * Copyright (C) 2016 Spintrol Limited Corporation. All rights reserved.
 *
 * @attention
 * THIS SOFTWARE JUST PROVIDES CUSTOMERS WITH CODING INFORMATION REGARDING 
 * THEIR PRODUCTS, WHICH AIMS AT SAVING TIME FOR THEM. SPINTROL SHALL NOT BE
 * LIABLE FOR THE USE OF THE SOFTWARE. SPINTROL DOES NOT GUARANTEE THE 
 * CORRECTNESS OF THIS SOFTWARE AND RESERVES THE RIGHT TO MODIFY THE SOFTWARE 
 * WITHOUT NOTIFICATION.
 *
 ******************************************************************************/

#ifndef ISR_H
#define ISR_H

#ifdef __cplusplus
extern "C" {
#endif

//---------------------------------------------------------------------------
// The headers of the interrupt handlers
//
// Cortex-M3 Processor Exceptions
void NMI_Handler(void);
void HardFault_Handler(void);
void MemManage_Handler(void);
void BusFault_Handler(void);
void UsageFault_Handler(void);
void SVC_Handler(void);
void DebugMon_Handler(void);
void PendSV_Handler(void);
void SysTick_Handler(void);

// SPC1068 Specific Interrupt handler
void UART_IRQHandler(void);
void I2C_IRQHandler(void);
void SSP_IRQHandler(void);
void GPIOEdge_IRQHandler(void);
void GPIOLevel_IRQHandler(void);
void QSPI_IRQHandler(void);
void ECAP_IRQHandler(void);
void TIM0_IRQHandler(void);
void TIM1_IRQHandler(void);
void TIM2_IRQHandler(void);
void WDT1_IRQHandler(void);
void ADC0_IRQHandler(void);
void ADC1_IRQHandler(void);
void ADC2_IRQHandler(void);
void ADC3_IRQHandler(void);
void ADC4_IRQHandler(void);
void ADC5_IRQHandler(void);
void ADC6_IRQHandler(void);
void ADC7_IRQHandler(void);
void ADC8_IRQHandler(void);
void ADC9_IRQHandler(void);
void ADC10_IRQHandler(void);
void ADC11_IRQHandler(void);
void ADC12_IRQHandler(void);
void ADC13_IRQHandler(void);
void ADC14_IRQHandler(void);
void ADC15_IRQHandler(void);
void PWM0_IRQHandler(void);
void PWM0TZ_IRQHandler(void);
void PWM1_IRQHandler(void);
void PWM1TZ_IRQHandler(void);
void PWM2_IRQHandler(void);
void PWM2TZ_IRQHandler(void);
void PWM3_IRQHandler(void);
void PWM3TZ_IRQHandler(void);
void PWM4_IRQHandler(void);
void PWM4TZ_IRQHandler(void);
void PWM5_IRQHandler(void);
void PWM5TZ_IRQHandler(void);
void PWM6_IRQHandler(void);
void PWM6TZ_IRQHandler(void);
void MemParity_IRQHandler(void);
void AES_IRQHandler(void);
void CRC_IRQHandler(void);
void CLOCK_IRQHandler(void);
void BOD_IRQHandler(void);


#ifdef __cplusplus
}
#endif /* extern "C" */

#endif /* ISR_H */


/******************* (C) COPYRIGHT 2015 SPINTROL LIMITED CO. *****END OF FILE****/
