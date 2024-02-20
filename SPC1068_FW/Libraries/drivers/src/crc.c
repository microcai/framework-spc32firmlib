/**************************************************************************//**
 * @file     crc.c
 * @brief    This file provides CRC firmware functions.
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

#include "crc.h"




/****************************************************************************//**
 * @brief      Calculate CRC value of the specified data
 *
 * @param[in]  CRCx      :  Select the CRC module
 * @param[in]  pu8DataStr:  Pointer to the input data stream
 * @param[in]  u32DataLen:  Data length in byte
 *
 * @return     CRC result
 *
 *******************************************************************************/
uint32_t CRC_Calculate(CRC_REGS* CRCx, const uint8_t *pu8DataStr, uint32_t u32DataLen)
{
  uint32_t cnt;

  uint32_t divisor, tail;

  /* Set stream data length */
  CRC_SetStreamLen(CRCx, u32DataLen);

  /* Padding first and copy data in */
  divisor = u32DataLen / 4;
  tail    = u32DataLen % 4;

  switch(tail)
  {
    case 1:
        CRCx->CRCSTRIN.all = (((uint32_t)pu8DataStr[0]) << 24);
        break;

    case 2:
        CRCx->CRCSTRIN.all = ((((uint32_t)pu8DataStr[0]) << 16) |
                              (((uint32_t)pu8DataStr[1]) << 24));
        break;

    case 3:
        CRCx->CRCSTRIN.all = ((((uint32_t)pu8DataStr[0]) << 8)  |
                              (((uint32_t)pu8DataStr[1]) << 16) |
                              (((uint32_t)pu8DataStr[2]) << 24));
        break;

    default:
        break;
  }

  /* Compose last data from byte to word and copy data in  */
  for(cnt = 0; cnt < divisor; cnt++)
  {
    CRCx->CRCSTRIN.all = (((uint32_t)pu8DataStr[4*cnt + tail    ])        |
                         (((uint32_t)pu8DataStr[4*cnt + tail + 1]) << 8)  |
                         (((uint32_t)pu8DataStr[4*cnt + tail + 2]) << 16) |
                         (((uint32_t)pu8DataStr[4*cnt + tail + 3]) << 24));
  }

  /* Wait for the result */
  while(CRC_IsCalculateDone(CRCx) == 0);

  /* Clear interrupt flag */
  CRC_ClearInt(CRCx);

  /* Return the result */
  return CRC_GetResult(CRCx);
}




/****************************************************************************//**
 * @brief      Feed data stream to CRC input register
 *
 * @param[in]  CRCx      :  Select the CRC module
 * @param[in]  pu8DataStr:  Pointer to the input data stream
 * @param[in]  u32DataLen:  Data length in byte
 *
 * @return     none
 *
 *******************************************************************************/
void CRC_FeedStream(CRC_REGS* CRCx, const uint8_t *pu8DataStr, uint32_t u32DataLen)
{
  uint32_t cnt;
  uint32_t divisor, tail;

  /* Padding first and copy data in */
  divisor = u32DataLen / 4;
  tail    = u32DataLen % 4;

  switch(tail)
  {
    case 1:
        CRCx->CRCSTRIN.all = (((uint32_t)pu8DataStr[0]) << 24);
        break;

    case 2:
        CRCx->CRCSTRIN.all = ((((uint32_t)pu8DataStr[0]) << 16) |
                              (((uint32_t)pu8DataStr[1]) << 24));
        break;

    case 3:
        CRCx->CRCSTRIN.all = ((((uint32_t)pu8DataStr[0]) << 8)  |
                              (((uint32_t)pu8DataStr[1]) << 16) |
                              (((uint32_t)pu8DataStr[2]) << 24));
        break;

    default:
        break;
  }

  /* Compose last data from byte to word and copy data in  */
  for(cnt = 0; cnt < divisor; cnt++)
  {
    CRCx->CRCSTRIN.all = (((uint32_t)pu8DataStr[4*cnt + tail    ])        |
                         (((uint32_t)pu8DataStr[4*cnt + tail + 1]) << 8)  |
                         (((uint32_t)pu8DataStr[4*cnt + tail + 2]) << 16) |
                         (((uint32_t)pu8DataStr[4*cnt + tail + 3]) << 24));
  }
}


/******************* (C) COPYRIGHT 2021 SPINTROL LIMITED CO. *****END OF FILE****/
