/**************************************************************************//**
 * @file     driver_i2c.h
 * @brief    I2C high level driver header file.
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

#ifndef DRIVER_I2C_H
#define DRIVER_I2C_H

#ifdef __cplusplus
extern "C" {
#endif


#include "spc1068.h"

uint32_t i2c_master_write(const uint8_t *data, uint32_t num);
uint32_t i2c_master_read(uint8_t *data, uint32_t num);
uint32_t i2c_slave_write(const uint8_t *data, uint32_t num);
uint32_t i2c_slave_read(uint8_t *data, uint32_t num);


#ifdef __cplusplus
}
#endif /* extern "C" */

#endif /* DRIVER_I2C_H */


/******************* (C) COPYRIGHT 2015 SPINTROL LIMITED CO. *****END OF FILE****/
