/**************************************************************************//**
 * @file     ssp.c
 * @brief    This file provides SSP firmware functions.
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

#include "ssp.h"




/****************************************************************************//**
 * @brief      Initializes the SSP
 *
 * @param[in]  SSPx            :  Select the SSP port
 * @param[in]  u8MasterOrSlave :  Define SSP in master or slave mode
 *                                 - \ref SSP_MASTER_MODE
 *                                 - \ref SSP_SLAVE_MODE
 * @param[in]  u8DataSize      :  Define SSP data size in one frame
 * @param[in]  u32Baudrate     :  Define SSP Baudrate
 * @param[in]  u1FramePolarity :  Select frame polarity from 
 *                                SSP_FramePolarityEnum
 * @param[in]  u1ClockIdleLevel:  Select clock idle state from 
 *                                SSP_ClockIdleLevelEnum
 * @param[in]  u1DataSendEdge  :  Select send data on which clock edge from 
 *                                SSP_SendDataEdgeEnum
 * @return none
 *
 *******************************************************************************/
void SSP_Init(SSP_REGS* SSPx, uint8_t u8MasterOrSlave, uint8_t u8DataSize, uint32_t u32Baudrate, SSP_FramePolarityEnum u1FramePolarity, SSP_ClockIdleLevelEnum u1ClockIdleLevel, SSP_SendDataEdgeEnum u1DataSendEdge)
{
#ifdef SPC1068_DRIVER_DEBUG
  if (u32Baudrate > 40000)
  {}
  else
  {
    printf("Error: Baudrate too low you need to be sure, may need to slow down CPU clock to get this speed");
    while(1)
    {}
  }
  
  if (u8MasterOrSlave <=1)
  {
  }
  else
  {
    printf("Error: wrong mode code, please check");
    while(1)
    {}
  }
#endif
  
  
  uint16_t u16DivRitio = 0;
  
  /* Enable SSP clock */
  CLOCK_EnableModule(SSP_MODULE);
  
  /* Configure SSP clock divider */
  u16DivRitio = SysInfo.u32CLK0 / u32Baudrate;
  if (u16DivRitio <= 63)
  {
    CLOCK->SSPCLKCTL.bit.DIV0 = u16DivRitio;
    CLOCK->SSPCLKCTL.bit.DIV1 = 1;
  }
  else
  {
    CLOCK->SSPCLKCTL.bit.DIV0 = 0x3F;
    CLOCK->SSPCLKCTL.bit.DIV1 = u16DivRitio / 63;
  }

  /* Configure SSP function mode: Master or Slave */
  if (u8MasterOrSlave == SSP_MASTER_MODE)
  {
    SSPx->SSPCTL1.bit.FRMDIR = SSPCTL1_BIT_FRMDIR_MASTER_MODE;
    SSPx->SSPCTL1.bit.CLKDIR = SSPCTL1_BIT_CLKDIR_MASTER_MODE;
  }
  else
  {
    SSPx->SSPCTL1.bit.FRMDIR = SSPCTL1_BIT_FRMDIR_SLAVE_MODE;
    SSPx->SSPCTL1.bit.CLKDIR = SSPCTL1_BIT_CLKDIR_SLAVE_MODE;
    /* Use external clock in slave mode */
    SSPx->SSPCTL1.bit.SLVCLKSEL = SSPCTL1_BIT_SLVCLKSEL_SLAVE_EXTENAL_SCLK;  
  }

  /* Configure SSP data size */
  if (u8DataSize <= 16)
  {
    SSPx->SSPCTL0.bit.ESIZESEL = SSPCTL0_BIT_ESIZESEL_DISABLE;
    SSPx->SSPCTL0.bit.SIZESEL = u8DataSize - 1;
  }
  else
  {
    SSPx->SSPCTL0.bit.ESIZESEL = SSPCTL0_BIT_ESIZESEL_ENABLE;
    SSPx->SSPCTL0.bit.SIZESEL = u8DataSize - 17;
  }
  
  /* Configure SSP Frame level according to user selection */
  SSPx->SSPCTL1.bit.FRMINV = u1FramePolarity;

  /* Configure SSP clock idle level according to user selection */
  SSPx->SSPCTL1.bit.CLKPOL = u1ClockIdleLevel;

  /* Configure SSP clock phase according to user selection */
  if(u1DataSendEdge == SSP_SEND_ON_RISING_EDGE)
  {
    /* CLKPHS != CLKPOL */
    SSPx->SSPCTL1.bit.CLKPHS = ((u1ClockIdleLevel == 0)? 1 : 0);
  }
  else
  {
    /* CLKPHS = CLKPOS */
    SSPx->SSPCTL1.bit.CLKPHS = u1ClockIdleLevel;
  }

  /* Disable TX overrun, RX overrun */
  SSPx->SSPCTL0.bit.TFINTMSK = SSPCTL0_BIT_TFINTMSK_TXFIFO_UNDERFLOW_INT_MASK;
  SSPx->SSPCTL0.bit.RFINTMSK = SSPCTL0_BIT_RFINTMSK_RXFIFO_OVERFLOW_INT_MASK;
}




/****************************************************************************//**
 * @brief      Initializes the SSP with pre-define settings
 *
 * @param[in]  SSPx           :  Select the SSP port
 * @param[in]  u8MasterOrSlave:  Define SSP in master or slave mode
 * @param[in]  u8DataSize     :  Define SSP data size in one frame
 * @param[in]  u32Baudrate    :  Define SSP Baudrate
 *
 * @return     none
 *
 * @detail     As in a lot of SPI application scenario, 
 *             Frame is active low
 *             Clock idle      low
 *             Data send on    Falling edge
 * In these cases, user can use this funtion as a simple method to configure SSP 
 *
 *******************************************************************************/
void SSP_InitEasy(SSP_REGS* SSPx, uint8_t u8MasterOrSlave, uint8_t u8DataSize, uint32_t u32Baudrate)
{
  SSP_Init(SSPx, u8MasterOrSlave, u8DataSize, u32Baudrate, SSP_FRM_ACTIVE_LOW, SSP_CLK_IDLE_LOW, SSP_SEND_ON_RISING_EDGE);
}




/****************************************************************************//**
 * @brief      Configure SPI format with specifical parameters
 *
 * @param[in]  PSPConfig:  Pointer to the structure contains PSP parameters information
 *
 * @return     none
 *
 * @detail     PSP mode is a advance mode in SSP, user need to read carefully the 
 *             SSP application note or the technical manual before using this function
 *
 *******************************************************************************/
void SSP_InitPSPMode(SSP_REGS* SSPx, SSP_PSPType *PSPConfig)
{  
  #ifdef SPC1068_DRIVER_DEBUG
  if ((PSPConfig->T1 <= 7)&&(PSPConfig->T2 <= 15)&&(PSPConfig->T3 >= 4)&&(PSPConfig->T3 <= 32)&&(PSPConfig->T4 <= 31)&&(PSPConfig->T5 <= 127)&&(PSPConfig->T6 >=1)&&(PSPConfig->T6 <= 63))
  {}
  else
  {
    printf("Error: Parameter too big");
    while(1)
    {}
  }
  
  if((PSPConfig->T5 + PSPConfig->T6) > ( PSPConfig->T1 + PSPConfig->T2 + PSPConfig->T3 + PSPConfig->T4))
  {
    printf("Error: T5 + T6 > T1 + T2 + T3 + T4");
    while(1)
    {}
  }
  
  if(1 > PSPConfig->T6)
  {
    printf("Error: T6 < 1");
    while(1)
    {}
  }
  
  if(PSPConfig->T6 >= ( PSPConfig->T2 + PSPConfig->T3 + PSPConfig->T4))
  {
    printf("Error: T6 >= T2 + T3 + T4");
    while(1)
    {}
  }
  
  if(( PSPConfig->T5 + PSPConfig->T6) < ( PSPConfig->T1 +1))
  {
    printf("Error: T5 + T6 >= T1 + 1");
    while(1)
    {}
  }
  #endif
  
  /* Select SSP as PSP mode */
  SSPx->SSPCTL0.bit.FRMSEL    = SSPCTL0_BIT_FRMSEL_PSP;
  /* FRM POL  */
  SSPx->SSPPSP.bit.FRMPOL     = PSPConfig->SFRMP;
  /* Clock Mode  */
  SSPx->SSPPSP.bit.CLKMODE    = PSPConfig->SCMODE;
  /* End of tranfer data state */
  SSPx->SSPPSP.bit.ETDS       = PSPConfig->ETDS;

  /* T1 clock Start Delay */
  SSPx->SSPPSP.bit.STARTDLY   = PSPConfig->T1;
  /* T2 Dummy start */
  SSPx->SSPPSP.bit.DMYSTART   = PSPConfig->T2 & 0x3;
  SSPx->SSPPSP.bit.EDMYSTART  = (PSPConfig->T2 & 0xC)>>2;
  /* T3 Data length */
  SSPx->SSPCTL0.bit.ESIZESEL  = ((PSPConfig->T3-1) & 0x10)>>4;
  SSPx->SSPCTL0.bit.SIZESEL   = (PSPConfig->T3 - 1)&0xF;
  /* T4 Dummy stop */
  SSPx->SSPPSP.bit.DMYSTOP    = PSPConfig->T4; 
  SSPx->SSPPSP.bit.EDMYSTOP   = (PSPConfig->T4 & 0x1C)>>2;
  /* T5 Inter FRM Delay */
  SSPx->SSPPSP.bit.FRMDLY     = PSPConfig->T5;
  /* T6 Frame Length */
  SSPx->SSPPSP.bit.FRMWIDTH   = PSPConfig->T6;
}




/****************************************************************************//**
 * @brief      Configure SPI format with specifical parameters
 *
 * @param[in]  u8InterframeLength:  Interlevel delay between frames
 * @param[in]  u8DataLength      :  Data length in on frame
 *
 * @return     none
 *
 * @detail     As in many PSP application, user only care about 
 *             (1) interleave between frames
 *             (2) data length
 *             In these cases, user can use this function to configure PSP mode in simple method
 *
 *******************************************************************************/
void SSP_PSPEasy(SSP_REGS* SSPx, uint8_t u8InterframeLength, uint8_t u8DataLength)
{
#ifdef SPC1068_DRIVER_DEBUG
  if (u8InterframeLength >= 22)
  {
    printf("Error: Inter Frame length too big");
    while(1)
    {}
  }
#endif
  
  SSP_PSPType PSPTempConfig;
  
  /* Calculate T1~T6 accordign to  u8InterframeLength & u8DataLength */
  PSPTempConfig.T1 =(u8InterframeLength>=7)?7:u8InterframeLength;
  PSPTempConfig.T2 =(u8InterframeLength>=7)?(u8InterframeLength-7):0;
  PSPTempConfig.T3 =u8DataLength;
  PSPTempConfig.T4 =3;
  PSPTempConfig.T5 =u8InterframeLength<<1;
  PSPTempConfig.T6 =u8DataLength+2;
  PSPTempConfig.SCMODE = 1;
  
  /* Setting T1~T6 */
  SSP_InitPSPMode(SSPx, &PSPTempConfig);
}




/****************************************************************************//**
 * @brief      Send data to SSP peripheral
 *
 * @param[in]  pu8Buffer:  Pointer to the data buffer to be sent out
 * @param[in]  u32Offset:  Offset from the start of array
 * @param[in]  u32Count :  Number of data to be sent
 *
 * @return none
 *
 *******************************************************************************/
void SSP_Send(SSP_REGS* SSPx, uint32_t *pu8Buffer, uint32_t u32Offset, uint32_t u32Count)
{
  uint32_t i;
  
  for(i = u32Offset; i < (u32Count + u32Offset); i++)
  {
    SSP_SendData(SSPx, pu8Buffer[i]);
  }
}




/****************************************************************************//**
 * @brief      Receive data from SSP peripheral
 *
 * @param[in]  pu8Buffer:  Pointer to the buffer to be filled by reveived data
 * @param[in]  u32Offset:  Offset from the start of array
 * @param[in]  u32Count :  Number of data to be received
 *
 * @return Quantity of data be read out
 *
 *******************************************************************************/
uint32_t SSP_Recv(SSP_REGS* SSPx, uint32_t *pu8Buffer, uint32_t u32Offset, uint32_t u32Count)
{
  uint32_t i;
  
  for(i = 0; i < u32Count; i++)
  {
    if(!SSP_IsRxFifoNotEmpty(SSPx))
      return i;
    else
      pu8Buffer[i + u32Offset] = SSP_ReceiveData(SSPx);
  }
  return i;
}


/******************* (C) COPYRIGHT 2021 SPINTROL LIMITED CO. *****END OF FILE****/
