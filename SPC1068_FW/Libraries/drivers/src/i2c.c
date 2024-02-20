/**************************************************************************//**
 * @file     i2c.c
 * @brief    This file provides I2C firmware functions.
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

#include "i2c.h"




/****************************************************************************//**
 * @brief      Initializes the I2C master
 *
 * @param[in]  I2Cx      :  Select the I2C module
 * @param[in]  eAddrMode :  Address mode
 *                          See I2C_AddrModeEnum for details
 *                           - \ref I2C_ADDR_7BIT
 *                           - \ref I2C_ADDR_10BIT
 * @param[in]  u32TarAddr:  Target address
 *
 * @return     none
 *
 * @Note       Clock SCL High/Low Count Setting
 *             - I2C Clock = 24MHz
 *               Standard Speed : MIN_SCL_HIGH =  96  MIN_SCL_LOW = 113
 *               Fast     Speed : MIN_SCL_HIGH =  15  MIN_SCL_LOW =  32
 *               High     Speed : MIN_SCL_HIGH =   5  MIN_SCL_LOW =   8
 *                                                    
 *             - I2C Clock = 40MHz
 *               Standard Speed : MIN_SCL_HIGH = 160  MIN_SCL_LOW = 188
 *               Fast     Speed : MIN_SCL_HIGH =  24  MIN_SCL_LOW =  53
 *               High     Speed : MIN_SCL_HIGH =   7  MIN_SCL_LOW =  13
 *                                                    
 *             - I2C Clock = 75MHz                    
 *               Standard Speed : MIN_SCL_HIGH = 300  MIN_SCL_LOW = 353
 *               Fast     Speed : MIN_SCL_HIGH =  38  MIN_SCL_LOW =  98
 *               High     Speed : MIN_SCL_HIGH =  12  MIN_SCL_LOW =  24
                                                      
 *             - I2C Clock = 100MHz                   
 *               Standard Speed : MIN_SCL_HIGH = 400  MIN_SCL_LOW = 470
 *               Fast     Speed : MIN_SCL_HIGH =  60  MIN_SCL_LOW = 130
 *               High     Speed : MIN_SCL_HIGH =  16  MIN_SCL_LOW =  32
                                                      
 *             - I2C Clock = 150MHz                   
 *               Standard Speed : MIN_SCL_HIGH = 600  MIN_SCL_LOW = 705
 *               Fast     Speed : MIN_SCL_HIGH =  36  MIN_SCL_LOW = 195
 *               High     Speed : MIN_SCL_HIGH =  24  MIN_SCL_LOW =  48
 *
 *******************************************************************************/
void I2C_MasterInit(I2C_REGS* I2Cx, I2C_AddrModeEnum eAddrMode, uint32_t u32TarAddr)
{
  /* I2C Clock SCL Count Register value */
  uint32_t u32Count;
  
  /* Enable I2C Module Clock */
  CLOCK_EnableModule(I2C_MODULE);
  
  /* Slave is diable */
  I2Cx->I2CCTL.bit.SLVDIS = I2CCTL_BIT_SLVDIS_SLAVE_DISABLE;
  /* Master enable */
  I2Cx->I2CCTL.bit.MASTER = I2CCTL_BIT_MASTER_ENABLE;
  
  /* Restart enable */
  I2Cx->I2CCTL.bit.RESTARTEN = I2CCTL_BIT_RESTARTEN_ENABLE;
  
  /* I2C operating speed = 400kb/s */
  I2Cx->I2CCTL.bit.SPEED = I2CCTL_BIT_SPEED_400K_BPS;
  
  /* Master address type */
  I2Cx->I2CMASTERADDR.bit.MASTERADDR10B = eAddrMode;
  
  /* Target address */
  I2Cx->I2CMASTERADDR.bit.TARADDR = u32TarAddr;
  
  
  /* Count register value for 400kb/s */
  u32Count = (1250 * (CLOCK_GetModuleClk(I2C_MODULE) / 1000000)) / 1000;
  
  /* High count value */
  I2Cx->I2CFSHCNT.all = u32Count;
  /* Low count value */
  I2Cx->I2CFSLCNT.all = u32Count;

  /* Enable I2C */
  I2Cx->I2CENABLE.all = I2CENABLE_ALL_EN_ENABLE;
}




/****************************************************************************//**
 * @brief      Initializes the I2C slave
 *
 * @param[in]  I2Cx      :  Select the I2C module
 * @param[in]  eAddrMode :  Address mode
 *                          See I2C_AddrModeEnum for details
 *                           - \ref I2C_ADDR_7BIT
 *                           - \ref I2C_ADDR_10BIT
 * @param[in]  u32SlvAddr:  Slave address
 *
 * @return     none
 *
 *******************************************************************************/
void I2C_SlaveInit(I2C_REGS* I2Cx, I2C_AddrModeEnum eAddrMode, uint32_t u32SlvAddr)
{
  /* Enable I2C Module Clock */
  CLOCK_EnableModule(I2C_MODULE);
  
  /* Slave enable */
  I2Cx->I2CCTL.bit.SLVDIS = I2CCTL_BIT_SLVDIS_SLAVE_ENABLE;
  I2Cx->I2CCTL.bit.MASTER = I2CCTL_BIT_MASTER_DISABLE;
  
  /* Restart enable */
  I2Cx->I2CCTL.bit.RESTARTEN = I2CCTL_BIT_RESTARTEN_ENABLE;
  
  /* Slave address mode */
  I2Cx->I2CCTL.bit.SLVADDR10B = eAddrMode;
  
  /* Slave address */
  I2Cx->I2CSLVADDR.all = u32SlvAddr;
  
  /* Enable I2C */
  I2Cx->I2CENABLE.all = I2CENABLE_ALL_EN_ENABLE;
}




/****************************************************************************//**
 * @brief      Enable I2C General Call function
 *
 * @param[in]  I2Cx:  Select the I2C module
 *
 * @return     none
 *
 *******************************************************************************/
void I2C_EnableGeneralCall(I2C_REGS* I2Cx)
{
  I2Cx->I2CMASTERADDR.bit.SPECIAL = 1;
  I2Cx->I2CMASTERADDR.bit.GCORSTART = 0;
}




/****************************************************************************//**
 * @brief      Disable I2C General Call function
 *
 * @param[in]  I2Cx:  Select the I2C module
 *
 * @return     none
 *
 *******************************************************************************/
void I2C_DisableGeneralCall(I2C_REGS* I2Cx)
{
  I2Cx->I2CMASTERADDR.bit.SPECIAL = 0;
}




/****************************************************************************//**
 * @brief      Enable I2C START BYTE function
 *
 * @param[in]  I2Cx:  Select the I2C module
 *
 * @return     none
 *
 *******************************************************************************/
void I2C_EnableStartByte(I2C_REGS* I2Cx)
{
  I2Cx->I2CMASTERADDR.bit.SPECIAL = 1;
  I2Cx->I2CMASTERADDR.bit.GCORSTART = 1;
}




/****************************************************************************//**
 * @brief      Disable I2C START BYTE function
 *
 * @param[in]  I2Cx:  Select the I2C module
 *
 * @return     none
 *
 *******************************************************************************/
void I2C_DisableStartByte(I2C_REGS* I2Cx)
{
  I2Cx->I2CMASTERADDR.bit.SPECIAL = 0;
}




/****************************************************************************//**
 * @brief      Clear specified interrupt type
 *
 * @param[in]  I2Cx    :  Select the I2C module
 * @param[in]  eIntType:  Specified interrupt type
 *                        See I2C_IntEnum for details
 *                         - \ref I2C_INT_RX_UNDER
 *                         - \ref I2C_INT_RX_OVER
 *                         - \ref I2C_INT_TX_OVER
 *                         - \ref I2C_INT_RD_REQ
 *                         - \ref I2C_INT_TX_ABORT
 *                         - \ref I2C_INT_RX_DONE
 *                         - \ref I2C_INT_ACTIVITY
 *                         - \ref I2C_INT_STOP_DET
 *                         - \ref I2C_INT_START_DET
 *                         - \ref I2C_INT_GEN_CALL
 *                         - \ref I2C_INT_ALL
 *
 * @return     none
 *
 *******************************************************************************/
void I2C_ClearInt(I2C_REGS* I2Cx, I2C_IntEnum eIntType)
{
  volatile uint32_t dummyData;

  switch(eIntType)
  {
    case I2C_INT_RX_UNDER:
      dummyData = I2Cx->I2CRXUDFCLR.bit.CLR;
      break;

    case I2C_INT_RX_OVER:
      dummyData = I2Cx->I2CRXOVFCLR.bit.CLR;
      break;

    case I2C_INT_TX_OVER:
      dummyData = I2Cx->I2CTXOVFCLR.bit.CLR;
      break;

    case I2C_INT_RD_REQ:
      dummyData = I2Cx->I2CRDREQCLR.bit.CLR;
      break;

    case I2C_INT_TX_ABORT:
      dummyData = I2Cx->I2CTXABRTCLR.bit.CLR;
      break;

    case I2C_INT_RX_DONE:
      dummyData = I2Cx->I2CRXDONECLR.bit.CLR;
      break;

    case I2C_INT_ACTIVITY:
      dummyData = I2Cx->I2CACTCLR.bit.CLR;
      break;

    case I2C_INT_STOP_DET:
      dummyData = I2Cx->I2CSTOPDETCLR.bit.CLR;
      break;

    case I2C_INT_START_DET:
      dummyData = I2Cx->I2CSTARTDETCLR.bit.CLR;
      break;

    case I2C_INT_GEN_CALL:
      dummyData = I2Cx->I2CGENCALLCLR.bit.CLR;
      break;

    case I2C_INT_ALL:
      dummyData = I2Cx->I2CINTCLR.bit.CLR;
      break;

    default:
      break;
  }
}


/******************* (C) COPYRIGHT 2021 SPINTROL LIMITED CO. *****END OF FILE****/
