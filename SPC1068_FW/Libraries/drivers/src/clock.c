/**************************************************************************//**
 * @file     clock.c
 * @brief    This file provides CLOCK firmware functions.
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


#include "clock.h"




/**
 *  @brief  Peripheral Module Index
 */
#define MODULE_INDEX_NUM          (16)
const uint16_t gau16ModuleIndex[MODULE_INDEX_NUM] = { UART_MODULE,  SSP_MODULE,  QSPI_MODULE,  I2C_MODULE,  ADC_MODULE,
                                                      COMP_MODULE,  PWM0_MODULE, ECAP_MODULE,  PWM1_MODULE, PWM2_MODULE,
                                                      PWM3_MODULE,  PWM4_MODULE, PWM5_MODULE,  PWM6_MODULE, WDT0_MODULE,
                                                      WDT1_MODULE };




/****************************************************************************//**
 * @brief      Get the dividing ratio value of selected module
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
 *
 * @return     Divider value range from 1~63 
 *             SSP_MODULE is 1 ~ (63 x 63)
 * 
 *******************************************************************************/
uint32_t CLOCK_GetModuleDiv(CLOCK_ModuleEnum eModule)
{
  uint32_t u32Div;
  uint32_t u32Div1;
  
  u32Div = CLOCK_MODULECTL(eModule)->bit.DIV;
  u32Div = (u32Div == 0)? (1) : (u32Div);
  
  if(eModule == SSP_MODULE)
  {
    u32Div1 = CLOCK->SSPCLKCTL.bit.DIV1;
    u32Div1 = (u32Div1 == 0)? (1) : (u32Div1);
    
    u32Div = u32Div * u32Div1;
  }
  
  return u32Div;
}




/****************************************************************************//**
 * @brief      Get the clock frequency (Hz) of the selected module
 *
 * @param[in]  eModule:  Select the IP module
 *                       See CLOCK_ModuleEnum for details
 *
 * @return     Clock frequency in Hz
 *
 * @note       This function can only excute correctly after CLOCK_Init()
 *             which will initial the value of SysInfo.u32CLK0
 * 
 *******************************************************************************/
uint32_t CLOCK_GetModuleClk(CLOCK_ModuleEnum eModule)
{
  uint32_t u32Div,u32Clk;
  
  u32Div = CLOCK_GetModuleDiv(eModule);
  
  if(eModule == WDT0_MODULE)
  {
    u32Clk = __RCO0_CLOCK;
  }
  else if (eModule == WDT1_MODULE)
  {
    u32Clk = __RCO1_CLOCK;
  }
  else
  {
    u32Clk = SysInfo.u32CLK0;
  }

  return (u32Clk / u32Div);
}




/****************************************************************************//**
 * @brief      Disable all Module clock
 *
 * @param[in]  none
 *
 * @return     none
 *
 *******************************************************************************/
void CLOCK_DisableAllModule(void)
{
  uint8_t i;
  
  for(i = 0; i < MODULE_INDEX_NUM; i++)
  {
     CLOCK_MODULECTL(gau16ModuleIndex[i])->bit.EN = 0;
  }
}




/****************************************************************************//**
 * @brief      Enable all Module clock
 *
 * @param[in]  none
 *
 * @return     none
 * 
 *******************************************************************************/
void CLOCK_EnableAllModule(void)
{
  uint8_t i;
  
  for(i = 0; i < MODULE_INDEX_NUM; i++)
  {
     CLOCK_MODULECTL(gau16ModuleIndex[i])->bit.EN = 1;
  }
}




/****************************************************************************//**
 * @brief      Enable the clock of selected PWM module
 *
 * @param[in]  PWMx:  Select the PWM module
 *
 * @return     none
 * 
 *******************************************************************************/
void CLOCK_EnablePWMModule(PWM_REGS* PWMx)
{
  if((PWMx>= PWM0) && (PWMx<= PWM6))
  {
    if(PWMx == PWM0)
    {
      CLOCK_MODULECTL(PWM0_MODULE)->bit.EN = 1;
    }
    else
    {
      CLOCK_MODULECTL(PWM1_MODULE + ((((uint32_t)(PWMx)) & 0x00000F00UL) >> 6) - 4)->bit.EN = 1;
    }
  }
}




/****************************************************************************//**
 * @brief      Get the clock divide ratio of seleted PWM module
 *
 * @param[in]  PWMx:  Select the PWM module
 *
 * @return     none
 * 
 *******************************************************************************/
uint32_t CLOCK_GetPWMModuleDiv(PWM_REGS* PWMx)
{
  uint32_t u32Div;
  
  u32Div = 1;
  
  if(PWMx >= PWM0 && PWMx <= PWM6)
  {
    if(PWMx == PWM0)
    {
      u32Div = CLOCK_MODULECTL(PWM0_MODULE)->bit.DIV;
    }
    else
    {
      u32Div = CLOCK_MODULECTL(PWM1_MODULE + ((((uint32_t)(PWMx)) & 0x00000F00UL) >> 6) - 4)->bit.DIV;
    }
  }
  
  u32Div = (u32Div == 0)? (1) : (u32Div);
  
  return u32Div;
}




/****************************************************************************//**
 * @brief      Get the clock frequency (Hz) of the selected PWM module
 *
 * @param[in]  PWMx:  Select the PWM module
 *
 * @return     none
 * 
 *******************************************************************************/
uint32_t CLOCK_GetPWMModuleClk(PWM_REGS* PWMx)
{
  return (SysInfo.u32CLK0 / CLOCK_GetPWMModuleDiv(PWMx));
}




/****************************************************************************//**
 * @brief      Set clock divide ratio for all modules
 *
 * @param[in]  u32Div :  Divider value range from 1~63
 *
 * @return     none
 * 
 *******************************************************************************/
void CLOCK_SetAllModuleDiv(uint32_t u32Div)
{
  uint8_t i;
  
  /* Do not Set DIV for WDT0 and WDT1 */
  for(i = 0; i < (MODULE_INDEX_NUM - 2); i++)
  {
     CLOCK_MODULECTL(gau16ModuleIndex[i])->bit.DIV = u32Div;
  }
}




/****************************************************************************//**
 * @brief      Set HCLK frequency which is the same as CPU clock
 *
 * @param[in]  u32HCLKFreq:  HCLK frequency in Hz
 *                           Pre-defined value in CLOCK_HCLKSelEnum can be used
 *                           for simplicity, see CLOCK_HCLKSelEnum for details
 *                             - \ref CLOCK_HCLK_24MHZ
 *                             - \ref CLOCK_HCLK_40MHZ
 *                             - \ref CLOCK_HCLK_75MHZ
 *                             - \ref CLOCK_HCLK_100MHZ
 *                             - \ref CLOCK_HCLK_125MHz
 *                             - \ref CLOCK_HCLK_150MHZ
 * @param[in]  u32PLLRef  :  Reference clock selection
 *                            See CLOCK_RefSelEnum for details
 *                             - \ref CLOCK_FROM_RC24MHZ
 *                             - \ref CLOCK_FROM_XTAL6MHZ
 *                             - \ref CLOCK_FROM_XTAL8MHZ
 *                             - \ref CLOCK_FROM_XTAL12MHZ
 *                             - \ref CLOCK_FROM_XTAL24MHZ
 *
 * @return     none
 * 
 * @note       This version of SDK only support the HCLK frequency aboved.
 *             In this function, 
 *             (1) HCLK will be the fast clock in the total system.
 *             (2) WDT0 clock is from RCO0
 *             (3) WDT1 clock is from RCO1
 *             If there is a demand to config special frequency. Such as CPU is 60MHz
 *             but PWM is 150MHz, please read datasheet or technical reference mannual.
 *             Please note that
 *             (1) PCLK should be the lowest clock among all IP modules.
 *             (2) PCLK Less (equal) than 37.5MHz
 *             (3) ADC must be less than 37.5MHz
 *             (4) QSPI cannot exceeds 50MHz(If 0x3h read instruction is used)
 *                 In this function, QSPI clock is the same as PCLK<37.5MHz
 *
 * @example    (1)  CLOCK_Init(CLOCK_FROM_XTAL6MHZ,CLOCK_HCLK_24MHZ);
 *             (2)  CLOCK_Init(CLOCK_FROM_RC24MHZ,CLOCK_HCLK_150MHZ);
 *
 *******************************************************************************/
ErrorStatus CLOCK_Init(CLOCK_RefSelEnum u32PLLRef, uint32_t u32HCLKFreq)
{
  ErrorStatus Status = SUCCESS;
  
  uint32_t u32PLLClk;
  uint32_t u32HCLKDiv;
  uint32_t u32PCLKDiv;

  /* Default settings */
  CLOCK->GLBCLKCTL.bit.CLK0SEL = GLBCLKCTL_BIT_CLK0SEL_RCO0;
  CLOCK->GLBCLKCTL.bit.CLK1SEL = GLBCLKCTL_BIT_CLK1SEL_RCO1;
  
  
  u32PLLClk  = u32HCLKFreq;
  u32HCLKDiv = 1;
  
  
  /* Calculate PLL clock */
  if(u32HCLKFreq < 100000000UL)
  {
    u32HCLKDiv = 100000000UL / u32HCLKFreq;
    
    if( (u32HCLKDiv * u32HCLKFreq) != 100000000UL)
    {
      u32HCLKDiv += 1;
    }
    
    u32PLLClk = u32HCLKDiv * u32HCLKFreq;
  }
  

  if(u32PLLRef == 0UL)
  {
    /* Select RCO0 as reference */
    Status = CLOCK_PLLConfig(0, 24000000, u32PLLClk);
  }
  else
  {
    /* Select XO as reference */
    Status = CLOCK_PLLConfig(1, u32PLLRef, u32PLLClk);
  }

  
  if(Status == SUCCESS)
  {
    /* Set PCLK dividing ratio */
    u32PCLKDiv = u32PLLClk / 37500000;
    if( (u32PCLKDiv * 37500000) != u32PLLClk )
    {
      u32PCLKDiv += 1;
    }
    
    if(u32PCLKDiv < u32HCLKDiv)
    {
      u32PCLKDiv = u32HCLKDiv;
    }
    
    CLOCK->PCLKCTL.bit.DIV = u32PCLKDiv;
    
    /* Set HCLK dividing ratio */
    CLOCK->HCLKCTL.bit.DIV = u32HCLKDiv;
    
    /* Set All peripherals' dividing ratio */
    CLOCK_SetAllModuleDiv(u32HCLKDiv);
    
    /* Set ADC/QSPI clock = PCLK */
    CLOCK_SetModuleDiv(ADC_MODULE,  u32PCLKDiv);
    CLOCK_SetModuleDiv(QSPI_MODULE, u32PCLKDiv);
    

    /* Select PLL as system clock (CLK0 /CLK1) source */
    /* Select RCO0/RCO1 as WDT0/1 source */
    CLOCK->GLBCLKCTL.all  =   GLBCLKCTL_ALL_CLK0SEL_PLL
                            | GLBCLKCTL_ALL_CLK1SEL_PLL
                            | GLBCLKCTL_ALL_PWM0CLKSEL_CLK0
                            | GLBCLKCTL_ALL_PWM1CLKSEL_CLK0
                            | GLBCLKCTL_ALL_PWM2CLKSEL_CLK0
                            | GLBCLKCTL_ALL_PWM3CLKSEL_CLK0
                            | GLBCLKCTL_ALL_PWM4CLKSEL_CLK0
                            | GLBCLKCTL_ALL_PWM5CLKSEL_CLK0
                            | GLBCLKCTL_ALL_PWM6CLKSEL_CLK0
                            | GLBCLKCTL_ALL_ECAPCLKSEL_CLK0
                            | GLBCLKCTL_ALL_WDT0CLKSEL_RCO0
                            | GLBCLKCTL_ALL_WDT1CLKSEL_RCO1;
    
    /* Update system information */
    SysInfo.u32CLK0 = u32PLLClk;
    SysInfo.u32CLK1 = u32PLLClk;
    SystemCoreClock = SysInfo.u32CLK0;
    
    SysInfo.u32HCLK = SysInfo.u32CLK0 / u32HCLKDiv;
    SysInfo.u32PCLK = SysInfo.u32CLK0 / u32PCLKDiv;
  }
  
  return Status;
}




/****************************************************************************//**
 * @brief      Set HCLK frequency with reference clock selected RCO
 *
 * @param[in]  u32HCLKFreq:  HCLK frequency selection
 *                           From CLOCK_HCLKSelEnum
 *                           - \ref CLOCK_HCLK_24MHZ
 *                           - \ref CLOCK_HCLK_40MHZ
 *                           - \ref CLOCK_HCLK_75MHZ
 *                           - \ref CLOCK_HCLK_100MHZ
 *                           - \ref CLOCK_HCLK_125MHz
 *                           - \ref CLOCK_HCLK_150MHZ
 *
 * @return     none
 * 
 * @note       This version of SDK only support the HCLK freq aboved.
 *             In this function, 
 *              (1) HCLK will be the fast clock in the total system.
 *              (2) WDT0 clock is from RCO0(24MHz)
 *              (3) WDT1 clock is from RCO1 (24MHz)
 *             If there is a demand to config special frequency. Such as CPU is 60MHz 
 *             but PWM is 150MHz, please read datasheet or technical reference mannual.
 *             Please note that
 *              (1) PCLK should be the lowest clock among all IP modules.
 *              (2) PCLK Less (equal) than 37.5MHz
 *              (3) ADC must be less than 37.5MHz
 *              (4) QSPI cannot exceeds 50MHz(If 0x3h read instruction is used)
 *                  In this initial, QSPI clock is the same as PCLK<37.5MHz
 *
 * @example    (1)  CLOCK_InitWithRCO(CLOCK_HCLK_24MHZ);
 *             (2)  CLOCK_InitWithRCO(CLOCK_HCLK_150MHZ);
 *
 *******************************************************************************/
ErrorStatus CLOCK_InitWithRCO(uint32_t u32HCLKFreq)
{
  ErrorStatus Status = SUCCESS;
  
  uint32_t u32PLLClk;
  uint32_t u32HCLKDiv;
  uint32_t u32PCLKDiv;
  uint32_t u32TimeOut;

  /* Default settings */
  CLOCK->GLBCLKCTL.bit.CLK0SEL = GLBCLKCTL_BIT_CLK0SEL_RCO0;
  CLOCK->GLBCLKCTL.bit.CLK1SEL = GLBCLKCTL_BIT_CLK1SEL_RCO1;
  
  
  u32PLLClk  = u32HCLKFreq;
  u32HCLKDiv = 1;
  
  
  if(u32HCLKFreq == CLOCK_HCLK_24MHZ)
  {
    /* Enable RCO0 */
    CLOCK->RCO0CTL.bit.MODE = RCO0CTL_BIT_MODE_24MHZ;
    CLOCK->RCO0CTL.bit.EN   = RCO0CTL_BIT_EN_ENABLE;
    
    /* Wait RCO0 ready */
    u32TimeOut = 10000;
    while(CLOCK->CLKSTS.bit.RCO0DRDY == CLKSTS_BIT_RCO0DRDY_NOT_READY)
    {
      if((u32TimeOut--) == 0)
      {
        Status = ERROR;
        break;
      }
    }
  }
  else
  {
    /* Calculate PLL clock */
    if(u32HCLKFreq < 100000000UL)
    {
      u32HCLKDiv = 100000000UL / u32HCLKFreq;
      
      if( (u32HCLKDiv * u32HCLKFreq) != 100000000UL)
      {
        u32HCLKDiv += 1;
      }
      
      u32PLLClk = u32HCLKDiv * u32HCLKFreq;
    }
    
    /* Configure PLL */
    Status = CLOCK_PLLQuickConfigWithRCO(u32PLLClk);
  }

  
  if(Status == SUCCESS)
  {
    /* Set PCLK dividing ratio */
    u32PCLKDiv = u32PLLClk / 37500000;
    if( (u32PCLKDiv * 37500000) != u32PLLClk )
    {
      u32PCLKDiv += 1;
    }
    
    if(u32PCLKDiv < u32HCLKDiv)
    {
      u32PCLKDiv = u32HCLKDiv;
    }
    
    CLOCK->PCLKCTL.bit.DIV = u32PCLKDiv;
    
    /* Set HCLK dividing ratio */
    CLOCK->HCLKCTL.bit.DIV = u32HCLKDiv;
    
    /* Set All peripherals' dividing ratio */
    CLOCK_SetAllModuleDiv(u32HCLKDiv);
    
    /* Set ADC/QSPI clock = PCLK */
    CLOCK_SetModuleDiv(ADC_MODULE,  u32PCLKDiv);
    CLOCK_SetModuleDiv(QSPI_MODULE, u32PCLKDiv);
    

    /* Select PLL as system clock (CLK0 /CLK1) source */
    /* Select RCO0/RCO1 as WDT0/1 source */
    CLOCK->GLBCLKCTL.all  =   GLBCLKCTL_ALL_CLK0SEL_PLL
                            | GLBCLKCTL_ALL_CLK1SEL_PLL
                            | GLBCLKCTL_ALL_PWM0CLKSEL_CLK0
                            | GLBCLKCTL_ALL_PWM1CLKSEL_CLK0
                            | GLBCLKCTL_ALL_PWM2CLKSEL_CLK0
                            | GLBCLKCTL_ALL_PWM3CLKSEL_CLK0
                            | GLBCLKCTL_ALL_PWM4CLKSEL_CLK0
                            | GLBCLKCTL_ALL_PWM5CLKSEL_CLK0
                            | GLBCLKCTL_ALL_PWM6CLKSEL_CLK0
                            | GLBCLKCTL_ALL_ECAPCLKSEL_CLK0
                            | GLBCLKCTL_ALL_WDT0CLKSEL_RCO0
                            | GLBCLKCTL_ALL_WDT1CLKSEL_RCO1;
    
    /* Update system information */
    SysInfo.u32CLK0 = u32PLLClk;
    SysInfo.u32CLK1 = u32PLLClk;
    SystemCoreClock = SysInfo.u32CLK0;
    
    SysInfo.u32HCLK = SysInfo.u32CLK0 / u32HCLKDiv;
    SysInfo.u32PCLK = SysInfo.u32CLK0 / u32PCLKDiv;
  }

  return Status;
}




/******************************************************************************
 * @brief      Configure PLL clock
 *
 * @param[in]  u8RefClkFromXO:  Reference clock selection
 *                               - \ref 1 -> clock source(reference) is from external crystal clock
 *                               - \ref 0 -> clock source(reference) is from internal RCO(24MHz)
 * @param[in]  u32RefClkHz   :  Reference clock frequency (Hz)
 *                              Example: If RCO is choosed, u32RefClkHz = 24000000
 *                                       If external crystal = 8MHz, u32RefClkHz = 8000000
 *
 * @param[in]  u32PLLClk     :  PLL output clock frequency (Hz)
 *
 * @return     1 : Success
 *             0 : Failed
 *
 *******************************************************************************/
ErrorStatus CLOCK_PLLConfig(uint8_t u8RefClkFromXO, uint32_t u32RefClkHz, uint32_t u32PLLClk)
{
  uint32_t u32TimeOut;
  
  uint32_t u32NIN, u32NOUT, u32NFBINT, u32NFBFRAC;
  uint64_t u64Freq;
  
  uint32_t u32FreqTrimCode;
  
  uint32_t u32GlbClkCtl;
  
  /* Check PLL frequency */
  if(u32PLLClk > PLL_MAX_FREQ)
  {
    return ERROR;
  }
  
  /* Save Global clock setting */
  u32GlbClkCtl = CLOCK->GLBCLKCTL.all;
 
  
  /* Enable RCO0 */
  CLOCK->RCO0CTL.bit.EN = RCO0CTL_BIT_EN_ENABLE;
  
  /* Wait RCO0 ready */
  u32TimeOut = 10000;
  while(CLOCK->CLKSTS.bit.RCO0DRDY == CLKSTS_BIT_RCO0DRDY_NOT_READY)
  {
    if((u32TimeOut--) == 0)
    {
      return ERROR;
    }
  }
  
  /* Temporary change system clock source */
  CLOCK->GLBCLKCTL.bit.CLK0SEL = GLBCLKCTL_BIT_CLK0SEL_RCO0;
  
  
  /* Trim PLL */
  CLOCK->PLLCTL0.all =  (0 << PLLCTL0_ALL_CPREGBYP_Pos)
                      | (PLLCTL0_ALL_RCLKSEL_RCO0)
                      | ((3) << PLLCTL0_ALL_NIN_Pos)
                      | PLLCTL0_ALL_ICP_(15)
                      | PLLCTL0_ALL_LOOPCLOSE_OPEN_LOOP
                      | PLLCTL0_ALL_DCLKEN_DISABLE
                      | PLLCTL0_ALL_PWMCLKEN_DISABLE
                      | PLLCTL0_ALL_ACLKEN_DISABLE
                      | PLLCTL0_ALL_FCALWIN_DISABLE
                      | PLLCTL0_ALL_FCALEN_ENABLE
                      | PLLCTL0_ALL_EN_ENABLE;

  /* Enable CPREG */
  CLOCK->CPREGCTL.bit.EN = CPREGCTL_BIT_EN_ENABLE;
  
  /* Wait CPREG ready */
  u32TimeOut = 1000;
  while(CLOCK->CLKSTS.bit.CPREGRDY == CLKSTS_BIT_CPREGRDY_NOT_READY)
  {
    if((u32TimeOut--) == 0) { return ERROR; }
  }
  
  /* Trimming */
  for(u32FreqTrimCode = 0; u32FreqTrimCode < 8; u32FreqTrimCode++)
  {
    CLOCK->PLLCTL0.bit.FREQTRIM = u32FreqTrimCode;
    CLOCK->PLLCTL0.bit.FCALWIN  = 1;
    
    while(CLOCK->CLKSTS.bit.PLLFLGRDY != 1)
    {
    }
    
    /* VCO in PLL is too fast */
    if(CLOCK->CLKSTS.bit.PLLFLG == 1)
    {
      CLOCK->PLLCTL0.bit.FCALWIN = 0;
      break;
    }
    CLOCK->PLLCTL0.bit.FCALWIN = 0;
  }

  
  if(u8RefClkFromXO==1)
  {
    /* Enable XO */
    CLOCK->XOCTL.all = 0xff05;
    
    /* Wait XO ready */
    u32TimeOut = 100000;
    while(CLOCK->CLKSTS.bit.XORDY == CLKSTS_BIT_XORDY_NOT_READY)
    {
      if((u32TimeOut--) == 0) { return ERROR; }
    }
  }
  
  
  
  /* NIN number */
  u32NIN = u32RefClkHz / 8000000;
  if((u32RefClkHz % 8000000) != 0)
  {
    u32NIN++;
  }
  
  
  /* NOUT number (VCO range is [400 : 600] MHz) */
  if(u32PLLClk >= 200000000)
  {
    u32NOUT = 2;        /* [200, 300) MHz */
  }
  else if(u32PLLClk >= 150000000)
  {
    u32NOUT = 3;        /* [150, 200) MHz */
  }
  else if (u32PLLClk >= 100000000U)
  {
    u32NOUT = 4U;      /* [100 : 150) MHz    */
  }
  else
  {
    return ERROR;
  }
  
  
  /* NFB Number */
  u64Freq    = (uint64_t)u32PLLClk * u32NOUT * u32NIN;
  u32NFBINT  = (uint32_t)(u64Freq / (uint64_t)u32RefClkHz);
  
  u64Freq    = (u64Freq - u32NFBINT * (uint64_t)u32RefClkHz) * 65536;
  u32NFBFRAC = (uint32_t)(u64Freq / u32RefClkHz);
  
  
  /* Set NIN, NOUT and NFB */
  CLOCK->PLLCTL0.bit.NIN  = u32NIN;
  CLOCK->PLLCTL1.bit.NDIG = (u32NOUT - 1);
  CLOCK->PLLCTL1.bit.NPWM = (u32NOUT - 1);
  
  CLOCK->PLLCTL1.bit.NFBINTG = u32NFBINT;
  CLOCK->PLLCTL1.bit.NFBFRAC = u32NFBFRAC;

  /* Set ICP */
  u32FreqTrimCode = CLOCK->PLLCTL0.bit.FREQTRIM;
  CLOCK->PLLCTL0.bit.ICP = u32NFBINT / (12 - u32FreqTrimCode);
  
  /* Select PLL reference clock */
  CLOCK->PLLCTL0.bit.RCLKSEL = u8RefClkFromXO;
  
  /* Enable cyclic slip detection */
  CLOCK->PLLCTL0.all |=  PLLCTL0_ALL_LOOPCLOSE_CLOSE_LOOP
                       | PLLCTL0_ALL_EN_ENABLE
                       | PLLCTL0_ALL_DCLKEN_ENABLE
                       | PLLCTL0_ALL_CSDEN_ENABLE;
  
  /* Clear latched CSD status */
  CLOCK->PLLCTL0.bit.CSDRST = 1;
  CLOCK->PLLCTL0.bit.CSDRST = 0;
  
  /* Should wait 10us */
  u32TimeOut = 10000;
  while(u32TimeOut--){};
  
  if((CLOCK->CLKSTS.bit.PLLCSDUP == 1) || (CLOCK->CLKSTS.bit.PLLCSDDN == 1))
  {
    return ERROR;
  }
  
  /* Restore Global Clock setting */
  CLOCK->GLBCLKCTL.all = u32GlbClkCtl;
  
  /* Enable PLL */
  CLOCK->PLLCTL0.all |= (PLLCTL0_ALL_DCLKEN_ENABLE | PLLCTL0_ALL_EN_ENABLE);

  return SUCCESS;
}




/******************************************************************************
 * @brief      Configure PLL clock with reference from internal RCO(24MHz)
 *
 * @param[in]  u32PLLClk:  PLL output clock frequency (Hz)
 *
 * @return     1 : Success
 *             0 : Failed
 *
 *******************************************************************************/
ErrorStatus CLOCK_PLLQuickConfigWithRCO(uint32_t u32PLLClk)
{
  uint32_t u32TimeOut;
  
  uint32_t u32NIN, u32NOUT, u32NFBINT, u32NFBFRAC;
  uint64_t u64Freq;
  
  uint32_t u32FreqTrimCode;
  
  uint32_t u32GlbClkCtl;
  
  
  
  /* Check PLL frequency */
  if(u32PLLClk > PLL_MAX_FREQ)
  {
    return ERROR;
  }
  
  /* Save Global clock setting */
  u32GlbClkCtl = CLOCK->GLBCLKCTL.all;

  
  /* Enable RCO0 */
  CLOCK->RCO0CTL.bit.EN = RCO0CTL_BIT_EN_ENABLE;
  
  /* Wait RCO0 ready */
  u32TimeOut = 10000;
  while(CLOCK->CLKSTS.bit.RCO0DRDY == CLKSTS_BIT_RCO0DRDY_NOT_READY)
  {
    if((u32TimeOut--) == 0) { return ERROR; }
  }
  
  /* Temporary change system clock source */
  CLOCK->GLBCLKCTL.bit.CLK0SEL = GLBCLKCTL_BIT_CLK0SEL_RCO0;
  
  
  /* Trim PLL */
  CLOCK->PLLCTL0.all =  (0 << PLLCTL0_ALL_CPREGBYP_Pos)
                      | (PLLCTL0_ALL_RCLKSEL_RCO0)
                      | ((3) << PLLCTL0_ALL_NIN_Pos)
                      | PLLCTL0_ALL_ICP_(15)
                      | PLLCTL0_ALL_LOOPCLOSE_OPEN_LOOP
                      | PLLCTL0_ALL_DCLKEN_DISABLE
                      | PLLCTL0_ALL_PWMCLKEN_DISABLE
                      | PLLCTL0_ALL_ACLKEN_DISABLE
                      | PLLCTL0_ALL_FCALWIN_DISABLE
                      | PLLCTL0_ALL_FCALEN_ENABLE
                      | PLLCTL0_ALL_EN_ENABLE;
  
  /* Enable CPREG */
  CLOCK->CPREGCTL.bit.EN = CPREGCTL_BIT_EN_ENABLE;
  
  /* Wait CPREG ready */
  u32TimeOut = 1000;
  while(CLOCK->CLKSTS.bit.CPREGRDY == CLKSTS_BIT_CPREGRDY_NOT_READY)
  {
    if((u32TimeOut--) == 0) { return ERROR; }
  }
  
  /* Trimming */
  for(u32FreqTrimCode = 0; u32FreqTrimCode < 8; u32FreqTrimCode++)
  {
    CLOCK->PLLCTL0.bit.FREQTRIM = u32FreqTrimCode;
    CLOCK->PLLCTL0.bit.FCALWIN  = 1;
    
    while(CLOCK->CLKSTS.bit.PLLFLGRDY != 1)
    {
    }
    
    /* VCO in PLL is too fast */
    if(CLOCK->CLKSTS.bit.PLLFLG == 1)
    {
      CLOCK->PLLCTL0.bit.FCALWIN = 0;
      break;
    }
    CLOCK->PLLCTL0.bit.FCALWIN = 0;
  }
  
  
  /* NIN number */
  u32NIN = 3;
  
  
  /* NOUT number (VCO range is [400 : 600] MHz) */
  if(u32PLLClk >= 200000000)
  {
    u32NOUT = 2;        /* [200, 300) MHz */
  }
  else if(u32PLLClk >= 150000000)
  {
    u32NOUT = 3;        /* [150, 200) MHz */
  }
  else if (u32PLLClk >= 100000000U)
  {
    u32NOUT = 4U;      /* [100 : 150) MHz    */
  }
  else
  {
    return ERROR;
  }
  
  
  /* NFB Number */
  u64Freq    = (uint64_t)u32PLLClk * u32NOUT * u32NIN;
  u32NFBINT  = (uint32_t)(u64Freq / __RCO0_CLOCK);
  
  u64Freq    = (u64Freq - u32NFBINT * (uint64_t)__RCO0_CLOCK) * 65536;
  u32NFBFRAC = (uint32_t)(u64Freq / __RCO0_CLOCK);
  
  
  /* Set NIN, NOUT and NFB */
  CLOCK->PLLCTL0.bit.NIN  = u32NIN;
  CLOCK->PLLCTL1.bit.NDIG = (u32NOUT - 1);
  CLOCK->PLLCTL1.bit.NPWM = (u32NOUT - 1);
  
  CLOCK->PLLCTL1.bit.NFBINTG = u32NFBINT;
  CLOCK->PLLCTL1.bit.NFBFRAC = u32NFBFRAC;

  /* Set ICP */
  u32FreqTrimCode = CLOCK->PLLCTL0.bit.FREQTRIM;
  CLOCK->PLLCTL0.bit.ICP = u32NFBINT / (12 - u32FreqTrimCode);
  
  
  /* Select RCO0 as reference clock */
  CLOCK->PLLCTL0.bit.RCLKSEL = PLLCTL0_BIT_RCLKSEL_RCO0;
  
  /* Enable cyclic slip detection */
  CLOCK->PLLCTL0.all |= PLLCTL0_ALL_LOOPCLOSE_CLOSE_LOOP
                       |PLLCTL0_ALL_EN_ENABLE
                       |PLLCTL0_ALL_DCLKEN_ENABLE
                       |PLLCTL0_ALL_CSDEN_ENABLE;
  
  /* Clear latched CSD status */
  CLOCK->PLLCTL0.bit.CSDRST = 1;
  CLOCK->PLLCTL0.bit.CSDRST = 0;
  
  /* Should wait 10us */
  u32TimeOut = 10000;
  while(u32TimeOut--){};
  
  if((CLOCK->CLKSTS.bit.PLLCSDUP == 1) || (CLOCK->CLKSTS.bit.PLLCSDDN == 1))
  {
    return ERROR;
  }
  
  /* Restore Global Clock setting */
  CLOCK->GLBCLKCTL.all = u32GlbClkCtl;
  
  
  /* Enable PLL */
  CLOCK->PLLCTL0.all |= (PLLCTL0_ALL_DCLKEN_ENABLE | PLLCTL0_ALL_EN_ENABLE);

  return SUCCESS;
}


/******************* (C) COPYRIGHT 2021 SPINTROL LIMITED CO. *****END OF FILE****/
