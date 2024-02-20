/*******************************************************************************
* @file     clock.h
* @brief    CLOCK driver header file.
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


#ifndef CLOCK_H
#define CLOCK_H

#ifdef __cplusplus
extern "C" {
#endif


#include "spc1068.h"




/**  
 *  @brief Union type to access the Peripheral Clock Control Register
*/
typedef union
{
  struct
  {
    uint32_t DIV:6;               /*!< bit:  0.. 5  Clock dividing ratio                */
    uint32_t RESERVED_6:1;        /*!< bit:      6  Reserved                            */
    uint32_t EN:1;                /*!< bit:      7  Clock output enable                 */
    uint32_t RESERVED_31_8:24;    /*!< bit:  8..31  Reserved                            */
  } bit;                          /*!< Structure used for bit  access                   */
  uint32_t all;                   /*!< Type      used for word access                   */
} MODULE_CLOCK_REG;




/**
 *  @brief  RCO clock frequency
 */
#define __RCO0_CLOCK    (24000000UL)
#define __RCO1_CLOCK    (24000000UL)




/**
 *  @brief  PLL maximum frequency
 */
#define PLL_MAX_FREQ    (150000000UL)




/**  
 *  @brief  IP Clock Module
 */
typedef enum
{
  UART_MODULE           = 0x9C,             /*!< UART Clock Control Module   */
  SSP_MODULE            = 0xA0,             /*!< SSP  Clock Control Module   */
  QSPI_MODULE           = 0xA4,             /*!< QSPI Clock Control Module   */
  I2C_MODULE            = 0xA8,             /*!< I2C  Clock Control Module   */
  ADC_MODULE            = 0xAC,             /*!< ADC  Clock Control Module   */
  COMP_MODULE           = 0xAC,             /*!< COMP Clock Control Module   */
  PGA_MODULE            = 0xAC,             /*!< PGA  Clock Control Module   */
  PWM0_MODULE           = 0xB0,             /*!< PWM0 Clock Control Module   */
  ECAP_MODULE           = 0xB8,             /*!< ECAP Clock Control Module   */
  PWM1_MODULE           = 0xE4,             /*!< PWM1 Clock Control Module   */
  PWM2_MODULE           = 0xE8,             /*!< PWM2 Clock Control Module   */
  PWM3_MODULE           = 0xEC,             /*!< PWM3 Clock Control Module   */
  PWM4_MODULE           = 0xF0,             /*!< PWM4 Clock Control Module   */
  PWM5_MODULE           = 0xF4,             /*!< PWM5 Clock Control Module   */
  PWM6_MODULE           = 0xF8,             /*!< PWM6 Clock Control Module   */
  WDT0_MODULE           = 0x164,            /*!< WDT0 Clock Control Module   */
  WDT1_MODULE           = 0x168,            /*!< WDT1 Clock Control Module   */
} CLOCK_ModuleEnum;




/**  
 *  @brief  Pre-defined system HCLK value
 */
typedef enum
{
  CLOCK_HCLK_24MHZ      = ( 24000000UL),    /*!< System clock frequency =  24MHz */
  CLOCK_HCLK_40MHZ      = ( 40000000UL),    /*!< System clock frequency =  40MHz */
  CLOCK_HCLK_75MHZ      = ( 75000000UL),    /*!< System clock frequency =  75MHz */
  CLOCK_HCLK_100MHZ     = (100000000UL),    /*!< System clock frequency = 100MHz */
  CLOCK_HCLK_120MHZ     = (120000000UL),    /*!< System clock frequency = 120MHz */
  CLOCK_HCLK_150MHZ     = (150000000UL),    /*!< System clock frequency = 150MHz */
} CLOCK_HCLKSelEnum;




/**  
 *  @brief  Pre-defined system clock source
 */
typedef enum
{
  CLOCK_FROM_RC24MHZ    = (       0UL),     /*!< PLL reference clock = RCO0(24MHz) */
  CLOCK_FROM_XTAL6MHZ   = ( 6000000UL),     /*!< PLL reference clock = XO(6MHz)    */
  CLOCK_FROM_XTAL8MHZ   = ( 8000000UL),     /*!< PLL reference clock = XO(8MHz)    */
  CLOCK_FROM_XTAL12MHZ  = (12000000UL),     /*!< PLL reference clock = XO(12MHz)   */
  CLOCK_FROM_XTAL24MHZ  = (24000000UL),     /*!< PLL reference clock = XO(24MHz)   */
} CLOCK_RefSelEnum;




/****************************************************************************//**
 * @brief      Get the pointer to access clock control register of the selected module
 *
 * @param[in]  eModule: Select the IP module
 *                      See CLOCK_ModuleEnum for details
 *                       - \ref UART_MODULE
 *                       - \ref SSP_MODULE
 *                       - \ref QSPI_MODULE
 *                       - \ref I2C_MODULE
 *                       - \ref ADC_MODULE
 *                       - \ref COMP_MODULE
 *                       - \ref PGA_MODULE
 *                       - \ref PWM0_MODULE
 *                       - \ref ECAP_MODULE
 *                       - \ref PWM1_MODULE
 *                       - \ref PWM2_MODULE
 *                       - \ref PWM3_MODULE
 *                       - \ref PWM4_MODULE
 *                       - \ref PWM5_MODULE
 *                       - \ref PWM6_MODULE
 *                       - \ref WDT0_MODULE
 *                       - \ref WDT1_MODULE
 *
 * @return     none
 * 
 *******************************************************************************/
#define CLOCK_MODULECTL(eModule)            ((__IO MODULE_CLOCK_REG*)(CLOCK_BASE + (eModule)))




/****************************************************************************//**
 * @brief      Enable/Disable the clock of selected module
 *
 * @param[in]  eModule: Select the IP module
 *                      See CLOCK_ModuleEnum for details
 *                       - \ref UART_MODULE
 *                       - \ref SSP_MODULE
 *                       - \ref QSPI_MODULE
 *                       - \ref I2C_MODULE
 *                       - \ref ADC_MODULE
 *                       - \ref COMP_MODULE
 *                       - \ref PGA_MODULE
 *                       - \ref PWM0_MODULE
 *                       - \ref ECAP_MODULE
 *                       - \ref PWM1_MODULE
 *                       - \ref PWM2_MODULE
 *                       - \ref PWM3_MODULE
 *                       - \ref PWM4_MODULE
 *                       - \ref PWM5_MODULE
 *                       - \ref PWM6_MODULE
 *                       - \ref WDT0_MODULE
 *                       - \ref WDT1_MODULE
 *
 * @return     none
 *
 * @example    CLOCK_EnableModule(PWM1_MODULE);
 *             CLOCK_EnableModule(ADC_MODULE);
 *             CLOCK_DisableModule(ADC_MODULE);
 *
 * @note       Please DO NOT trun off PCLK and HCLK!
 *
 *******************************************************************************/
#define CLOCK_EnableModule(eModule)         (CLOCK_MODULECTL((eModule))->bit.EN = 1)
#define CLOCK_DisableModule(eModule)        (CLOCK_MODULECTL((eModule))->bit.EN = 0)




/****************************************************************************//**
 * @brief      Set the clock divide ratio of selected module
 *
 * @param[in]  eModule:  Select the IP module
 *                       See CLOCK_ModuleEnum for details
 *                        - \ref UART_MODULE
 *                        - \ref SSP_MODULE
 *                        - \ref QSPI_MODULE
 *                        - \ref I2C_MODULE
 *                        - \ref ADC_MODULE
 *                        - \ref COMP_MODULE
 *                        - \ref PGA_MODULE
 *                        - \ref PWM0_MODULE
 *                        - \ref ECAP_MODULE
 *                        - \ref PWM1_MODULE
 *                        - \ref PWM2_MODULE
 *                        - \ref PWM3_MODULE
 *                        - \ref PWM4_MODULE
 *                        - \ref PWM5_MODULE
 *                        - \ref PWM6_MODULE
 *                        - \ref WDT0_MODULE
 *                        - \ref WDT1_MODULE
 * @param[in]  u32Div :  Clock divide ratio value
 *                       IP Clock = CLK0/Divide
 *                        - \ref u32Div = 0 --> Divide = 1
 *                        - \ref u32Div = 1 --> Divide = 1
 *                        - \ref u32Div = N(N>0) --> Divide = N
 *
 * @return     none
 *
 * @example    CLOCK_SetModuleDiv(PWM1_MODULE, 2);
 *             CLOCK_SetModuleDiv(ADC_MODULE, 4);
 *
 * @note       PCLK should be the lowest clock among all modules,
 *             otherwise data might be loss.
 *
 *******************************************************************************/
#define CLOCK_SetModuleDiv(eModule,u32Div)  (CLOCK_MODULECTL((eModule))->bit.DIV = (u32Div))




/****************************************************************************//**
 * @brief      Calculate the counter value according to clock frequency and 
 *             desired time in us, ns or ms
 *
 * @param[in]  u32Ns/u32Us/u32Ms:  Nero second / Micro second / Milli second
 * @param[in]  CLKHz            :  Clock frequency
 *
 * @return     none
 *
 * @example    If there is a module with 1MHz working frequency and there is a 
 *             counter inside sourced as same as this module.
 *             If we want this counter in 5 us, the following code can help to design
 *             Module.Counter = CLOCK_NsToCounter(5,1000000)
 * 
 *******************************************************************************/
#define CLOCK_NstoCounter(u32Ns,CLKHz)      (((u32Ns)*((CLKHz)/100000))/10000)
#define CLOCK_UsToCounter(u32Us,CLKHz)      (((u32Us)*((CLKHz)/1000))/1000)
#define CLOCK_MsToCounter(u32Ms,CLKHz)      ((u32Ms)*((CLKHz)/1000))




/**
 *  @brief  CLOCK Public Function Declaration
 */
ErrorStatus CLOCK_Init(CLOCK_RefSelEnum u32PLLRef, uint32_t u32HCLKFreq);
ErrorStatus CLOCK_InitWithRCO(uint32_t u32HCLKFreq);

ErrorStatus CLOCK_PLLConfig(uint8_t u8RefClkFromXO, uint32_t u32RefClkHz, uint32_t u32PLLClk);
ErrorStatus CLOCK_PLLQuickConfigWithRCO(uint32_t u32PLLClk);


void CLOCK_EnableAllModule(void);
void CLOCK_DisableAllModule(void);

void CLOCK_SetAllModuleDiv(uint32_t u32Div);
uint32_t CLOCK_GetModuleDiv(CLOCK_ModuleEnum eModule);
uint32_t CLOCK_GetModuleClk(CLOCK_ModuleEnum eModule);


void CLOCK_EnablePWMModule(PWM_REGS* PWMx);
uint32_t CLOCK_GetPWMModuleDiv(PWM_REGS* PWMx);
uint32_t CLOCK_GetPWMModuleClk(PWM_REGS* PWMx);


#ifdef __cplusplus
}
#endif /* extern "C" */

#endif /* CLOCK_H */


/******************* (C) COPYRIGHT 2021 SPINTROL LIMITED CO. *****END OF FILE****/
