/**************************************************************************//**
 * @file     isr.c
 * @brief    This file provides template for all exceptions handler and 
             peripherals interrupt service routine.
 * @version  V1.2.0
 * @date     05-Feb-2021
 *
 * @note
 * Copyright (C) 2021 Spintrol Limited Corporation. All rights reserved.
 *
 * @attention
 * THIS SOFTWARE JUST PROVIDES CUSTOMERS WITH CODING INFORMATION REGARDING 
 * THEIR PRODUCTS, WHICH AIMS AT SAVING TIME FOR THEM. SPINTROL SHALL NOT BE
 * LIABLE FOR THE USE OF THE SOFTWARE. SPINTROL DOES NOT GUARANTEE THE 
 * CORRECTNESS OF THIS SOFTWARE AND RESERVES THE RIGHT TO MODIFY THE SOFTWARE 
 * WITHOUT NOTIFICATION.
 *
 ******************************************************************************/

#include "isr.h"

//---------------------------------------------------------------------------
// Cortex-M3 Processor Exceptions Handlers
//

/***************************************************************
  * @brief  This function handles NMI exception.
  * @param  None
  * @retval None
***************************************************************/
void NMI_Handler(void)
{
}


/***************************************************************
  * @brief  This function handles Hard Fault exception.
  * @param  None
  * @retval None
***************************************************************/
void HardFault_Handler(void)
{
}


/***************************************************************
  * @brief  This function handles Memory Manage exception.
  * @param  None
  * @retval None
***************************************************************/
void MemManage_Handler(void)
{
}


/***************************************************************
  * @brief  This function handles Bus Fault exception.
  * @param  None
  * @retval None
***************************************************************/
void BusFault_Handler(void)
{
}


/***************************************************************
  * @brief  This function handles Usage Fault exception.
  * @param  None
  * @retval None
***************************************************************/
void UsageFault_Handler(void)
{
}


/***************************************************************
  * @brief  This function handles SVCall exception.
  * @param  None
  * @retval None
***************************************************************/
void SVC_Handler(void)
{
}


/***************************************************************
  * @brief  This function handles Debug Monitor exception.
  * @param  None
  * @retval None
***************************************************************/
void DebugMon_Handler(void)
{
}


/***************************************************************
  * @brief  This function handles PendSVC exception.
  * @param  None
  * @retval None
***************************************************************/
void PendSV_Handler(void)
{
}


/***************************************************************
  * @brief  This function handles SysTick Handler.
  * @param  None
  * @retval None
***************************************************************/
void SysTick_Handler(void)
{
}


/******************************************************************************/
/*                 SPC1068 Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_spc1068.s).                                                 */
/******************************************************************************/

/***************************************************************
  * @brief  This function handles UART interrupt request.
  * @param  None
  * @retval None
***************************************************************/
void UART_IRQHandler(void)
{
}


/***************************************************************
  * @brief  This function handles I2C interrupt request.
  * @param  None
  * @retval None
***************************************************************/
void I2C_IRQHandler(void)
{
}


/***************************************************************
  * @brief  This function handles SSP interrupt request.
  * @param  None
  * @retval None
***************************************************************/
void SSP_IRQHandler(void)
{
}


/***************************************************************
  * @brief  This function handles GPIO edge triggered interrupt request.
  * @param  None
  * @retval None
***************************************************************/
void GPIOEdge_IRQHandler(void)
{
}


/***************************************************************
  * @brief  This function handles GPIO level triggered interrupt request.
  * @param  None
  * @retval None
***************************************************************/
void GPIOLevel_IRQHandler(void)
{
}


/***************************************************************
  * @brief  This function handles QSPI interrupt request.
  * @param  None
  * @retval None
***************************************************************/
void QSPI_IRQHandler(void)
{
}


/***************************************************************
  * @brief  This function handles ECAP interrupt request.
  * @param  None
  * @retval None
***************************************************************/
void ECAP_IRQHandler(void)
{
}


/***************************************************************
  * @brief  This function handles TIM0 interrupt request.
  * @param  None
  * @retval None
***************************************************************/
void TIM0_IRQHandler(void)
{
}


/***************************************************************
  * @brief  This function handles TIM1 interrupt request.
  * @param  None
  * @retval None
***************************************************************/
void TIM1_IRQHandler(void)
{
}


/***************************************************************
  * @brief  This function handles TIM2 interrupt request.
  * @param  None
  * @retval None
***************************************************************/
void TIM2_IRQHandler(void)
{
}


/***************************************************************
  * @brief  This function handles WDG1 interrupt request.
  * @param  None
  * @retval None
***************************************************************/
void WDT1_IRQHandler(void)
{
}


/***************************************************************
  * @brief  This function handles ADC SOC0 interrupt request.
  * @param  None
  * @retval None
***************************************************************/
void ADC0_IRQHandler(void)
{
}


/***************************************************************
  * @brief  This function handles ADC SOC1 interrupt request.
  * @param  None
  * @retval None
***************************************************************/
void ADC1_IRQHandler(void)
{
}


/***************************************************************
  * @brief  This function handles ADC SOC2 interrupt request.
  * @param  None
  * @retval None
***************************************************************/
void ADC2_IRQHandler(void)
{
}


/***************************************************************
  * @brief  This function handles ADC SOC3 interrupt request.
  * @param  None
  * @retval None
***************************************************************/
void ADC3_IRQHandler(void)
{
}


/***************************************************************
  * @brief  This function handles ADC SOC4 interrupt request.
  * @param  None
  * @retval None
***************************************************************/
void ADC4_IRQHandler(void)
{
}


/***************************************************************
  * @brief  This function handles ADC SOC5 interrupt request.
  * @param  None
  * @retval None
***************************************************************/
void ADC5_IRQHandler(void)
{
}


/***************************************************************
  * @brief  This function handles ADC SOC6 interrupt request.
  * @param  None
  * @retval None
***************************************************************/
void ADC6_IRQHandler(void)
{
}


/***************************************************************
  * @brief  This function handles ADC SOC7 interrupt request.
  * @param  None
  * @retval None
***************************************************************/
void ADC7_IRQHandler(void)
{
}


/***************************************************************
  * @brief  This function handles ADC SOC8 interrupt request.
  * @param  None
  * @retval None
***************************************************************/
void ADC8_IRQHandler(void)
{
}


/***************************************************************
  * @brief  This function handles ADC SOC9 interrupt request.
  * @param  None
  * @retval None
***************************************************************/
void ADC9_IRQHandler(void)
{
}


/***************************************************************
  * @brief  This function handles ADC SOC10 interrupt request.
  * @param  None
  * @retval None
***************************************************************/
void ADC10_IRQHandler(void)
{
}


/***************************************************************
  * @brief  This function handles ADC SOC11 interrupt request.
  * @param  None
  * @retval None
***************************************************************/
void ADC11_IRQHandler(void)
{
}


/***************************************************************
  * @brief  This function handles ADC SOC12 interrupt request.
  * @param  None
  * @retval None
***************************************************************/
void ADC12_IRQHandler(void)
{
}


/***************************************************************
  * @brief  This function handles ADC SOC13 interrupt request.
  * @param  None
  * @retval None
***************************************************************/
void ADC13_IRQHandler(void)
{
}


/***************************************************************
  * @brief  This function handles ADC SOC14 interrupt request.
  * @param  None
  * @retval None
***************************************************************/
void ADC14_IRQHandler(void)
{
}


/***************************************************************
  * @brief  This function handles ADC SOC15 interrupt request.
  * @param  None
  * @retval None
***************************************************************/
void ADC15_IRQHandler(void)
{
}


/***************************************************************
  * @brief  This function handles PWM0 interrupt request.
  * @param  None
  * @retval None
***************************************************************/
void PWM0_IRQHandler(void)
{
}


/***************************************************************
  * @brief  This function handles PWM0 Trip-Zone interrupt request.
  * @param  None
  * @retval None
***************************************************************/
void PWM0TZ_IRQHandler(void)
{
}


/***************************************************************
  * @brief  This function handles PWM1 interrupt request.
  * @param  None
  * @retval None
***************************************************************/
void PWM1_IRQHandler(void)
{
}


/***************************************************************
  * @brief  This function handles PWM1 Trip-Zone interrupt request.
  * @param  None
  * @retval None
***************************************************************/
void PWM1TZ_IRQHandler(void)
{
}


/***************************************************************
  * @brief  This function handles PWM2 interrupt request.
  * @param  None
  * @retval None
***************************************************************/
void PWM2_IRQHandler(void)
{
}


/***************************************************************
  * @brief  This function handles PWM2 Trip-Zone interrupt request.
  * @param  None
  * @retval None
***************************************************************/
void PWM2TZ_IRQHandler(void)
{
}


/***************************************************************
  * @brief  This function handles PWM3 interrupt request.
  * @param  None
  * @retval None
***************************************************************/
void PWM3_IRQHandler(void)
{
}


/***************************************************************
  * @brief  This function handles PWM3 Trip-Zone interrupt request.
  * @param  None
  * @retval None
***************************************************************/
void PWM3TZ_IRQHandler(void)
{
}


/***************************************************************
  * @brief  This function handles PWM4 interrupt request.
  * @param  None
  * @retval None
***************************************************************/
void PWM4_IRQHandler(void)
{
}


/***************************************************************
  * @brief  This function handles PWM4 Trip-Zone interrupt request.
  * @param  None
  * @retval None
***************************************************************/
void PWM4TZ_IRQHandler(void)
{
}


/***************************************************************
  * @brief  This function handles PWM5 interrupt request.
  * @param  None
  * @retval None
***************************************************************/
void PWM5_IRQHandler(void)
{
}


/***************************************************************
  * @brief  This function handles PWM5 Trip-Zone interrupt request.
  * @param  None
  * @retval None
***************************************************************/
void PWM5TZ_IRQHandler(void)
{
}


/***************************************************************
  * @brief  This function handles PWM6 interrupt request.
  * @param  None
  * @retval None
***************************************************************/
void PWM6_IRQHandler(void)
{
}


/***************************************************************
  * @brief  This function handles PWM6 Trip-Zone interrupt request.
  * @param  None
  * @retval None
***************************************************************/
void PWM6TZ_IRQHandler(void)
{
}


/***************************************************************
  * @brief  This function handles Memory parity check interrupt request.
  * @param  None
  * @retval None
***************************************************************/
void MemParity_IRQHandler(void)
{
}


/***************************************************************
  * @brief  This function handles AES interrupt request.
  * @param  None
  * @retval None
***************************************************************/
void AES_IRQHandler(void)
{
}


/***************************************************************
  * @brief  This function handles CRC interrupt request.
  * @param  None
  * @retval None
***************************************************************/
void CRC_IRQHandler(void)
{
}


/***************************************************************
  * @brief  This function handles CLOCK interrupt request.
  * @param  None
  * @retval None
***************************************************************/
void CLOCK_IRQHandler(void)
{
}


/***************************************************************
  * @brief  This function handles BOD interrupt request.
  * @param  None
  * @retval None
***************************************************************/
void BOD_IRQHandler(void)
{
}


/******************* (C) COPYRIGHT 2021 SPINTROL LIMITED CO. *****END OF FILE****/
