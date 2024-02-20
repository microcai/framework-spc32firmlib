/**************************************************************************//**
 * @file     driver_i2c.c
 * @brief    This file provides I2C high-level functions.
 * @version  V1.0.0
 * @date     21-Oct-2015
 *
 * @note
 * Copyright (C) 2015 Spintrol Limited Corporation. All rights reserved.
 *
 * @attention
 * THIS SOFTWARE JUST PROVIDES CUSTOMERS WITH CODING INFORMATION REGARDING 
 * THEIR PRODUCTS, WHICH AIMS AT SAVING TIME FOR THEM. SPINTROL SHALL NOT BE
 * LIABLE FOR THE USE OF THE SOFTWARE. SPINTROL DOES NOT GUARANTEE THE 
 * CORRECTNESS OF THIS SOFTWARE AND RESERVES THE RIGHT TO MODIFY THE SOFTWARE 
 * WITHOUT NOTIFICATION.
 *
 ******************************************************************************/

#include "driver_i2c.h"


/****************************************************************************//**
 * @brief      I2C master transmit data
 *
 * @param[in]  data:  data to be transmitted
 *             num:   number of data to be transmitted
 *
 * @return  number of data that has been transmitted
 *
 *******************************************************************************/
uint32_t i2c_master_write(const uint8_t *data, uint32_t num)
{
  uint32_t len = 0;

  while(num > 0)
  {
    /* Wait if fifo is full */
    while(I2C_IsTxFifoNotFull(I2C) == 0);

    I2C_SendByte(I2C, *data);
    
    data++;
    num--;
    len++;
  }
  
  return len;
}


/****************************************************************************//**
 * @brief      I2C slave transmit data - polling mode
 *
 * @param[in]  data:  data to be transmitted
 *             num:   number of data to be transmitted
 *
 * @return  number of data that has been transmitted
 *
 *******************************************************************************/
uint32_t i2c_slave_write(const uint8_t *data, uint32_t num)
{
  uint32_t len = 0;

  while(num > 0)
  {
    /* Wait for master read request */
    while(I2C_GetReadRequestIntRawFlag(I2C) == 0);
    
    I2C_SendByte(I2C, *data);
    
    /* Clear RD_REQ status */
    I2C_ClearInt(I2C, I2C_INT_RD_REQ);
    
    data++;
    num--;
    len++;
  }
  return len;
}


/****************************************************************************//**
 * @brief      I2C master receive data
 *
 * @param[in]  data:  data that has been received
 *             num:   number of data that has been received
 *
 * @return number of data that has been received
 *
 *******************************************************************************/
uint32_t i2c_master_read(uint8_t *data, uint32_t num)
{
  uint32_t len = 0;
  
  while(num > 0)
  {
    I2C_MasterReadCmd(I2C);
    
    while(I2C_IsRxFifoNotEmpty(I2C) == 0);
    
    *data = I2C_ReceiveByte(I2C);
    
    data++;
    len++;
    num--;
  }
  
  return len;
}


/****************************************************************************//**
 * @brief      I2C slave receive data
 *
 * @param[in]  data:  data that has been received
 *             num:   number of data that has been received
 *
 * @return number of data that has been received
 *
 *******************************************************************************/
uint32_t i2c_slave_read(uint8_t *data, uint32_t num)
{
  uint32_t len = 0;
  
  while(num > 0)
  {
    while(I2C_IsRxFifoNotEmpty(I2C) == 0);
    
    *data = I2C_ReceiveByte(I2C);
    
    num--;
    len++;
    data++;
  }
  
  return len;
}



/******************* (C) COPYRIGHT 2015 SPINTROL LIMITED CO. *****END OF FILE****/
