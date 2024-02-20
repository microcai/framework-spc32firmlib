/**************************************************************************//**
 * @file     crc.h
 * @brief    CRC driver header file.
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

#ifndef CRC_H
#define CRC_H

#ifdef __cplusplus
extern "C" {
#endif


#include "spc1068.h"




/**
 *  @brief  CRC mode type definition
 */
typedef enum
{
  CRC_MODE_16_CCITT     = 0,         /*!< CRC-16-CCITT   */
  CRC_MODE_16_IBM       = 1,         /*!< CRC-16-IBM     */
  CRC_MODE_16_T10_DIF   = 2,         /*!< CRC-16-T10-DIF */
  CRC_MODE_32_IEEE      = 3,         /*!< CRC-32-IEEE    */
  CRC_MODE_16_DNP       = 4,         /*!< CRC-16-DNP     */
} CRC_ModeEnum;




/****************************************************************************//**
 * @brief      Set CRC mode
 *
 * @param[in]  CRCx :  Select the CRC module
 * @param[in]  eMode:  CRC mode
 *                     See CRC_ModeEnum for details
 *
 * @return     none
 *
 *******************************************************************************/
#define CRC_SetMode(CRCx, eMode)            ((CRCx)->CRCCTL.bit.MODE = (eMode))




/****************************************************************************//**
 * @brief      Enable CRC calculate
 *
 * @param[in]  CRCx:  Select the CRC module
 *
 * @return     none
 *
 *******************************************************************************/
#define CRC_Enable(CRCx)                    ((CRCx)->CRCCTL.all |= CRCCTL_ALL_EN_ENABLE)




/****************************************************************************//**
 * @brief      Disable CRC calculate
 *
 * @param[in]  CRCx:  Select the CRC module
 *
 * @return     none
 *
 *******************************************************************************/
#define CRC_Disable(CRCx)                   ((CRCx)->CRCCTL.bit.EN = CRCCTL_BIT_EN_DISABLE)




/****************************************************************************//**
 * @brief      Set CRC stream length
 *
 * @param[in]  CRCx     :  Select the CRC module
 * @param[in]  u32StrLen:  Stream length in byte
 *
 * @return     none
 *
 *******************************************************************************/
#define CRC_SetStreamLen(CRCx,u32StrLen)    ((CRCx)->CRCSTRLEN.all = ((u32StrLen)- 1))




/****************************************************************************//**
 * @brief      Feed data into CRC stream
 *
 * @param[in]  CRCx   :  Select the CRC module
 * @param[in]  u32Data:  Input data
 *
 * @return     none
 *
 *******************************************************************************/
#define CRC_FeedData(CRCx,u32Data)          ((CRCx)->CRCSTRIN.all = (u32Data))




/****************************************************************************//**
 * @brief      Get CRC result
 *
 * @param[in]  CRCx:  Select the CRC module
 *
 * @return     CRC calculation result
 *
 *******************************************************************************/
#define CRC_GetResult(CRCx)                 ((CRCx)->CRCRESULT.all)




/****************************************************************************//**
 * @brief      Enable CRC calculation done interrupt
 *
 * @param[in]  CRCx:  Select the CRC module
 *
 * @return     none
 *
 *******************************************************************************/
#define CRC_EnableInt(CRCx)                 ((CRCx)->CRCINTMSK.bit.MSKDONE = CRCINTMSK_BIT_MSKDONE_UNMASK)




/****************************************************************************//**
 * @brief      Disable CRC calculation done interrupt
 *
 * @param[in]  CRCx:  Select the CRC module
 *
 * @return     none
 *
 *******************************************************************************/
#define CRC_DisableInt(CRCx)                ((CRCx)->CRCINTMSK.bit.MSKDONE = CRCINTMSK_BIT_MSKDONE_MASK)




/****************************************************************************//**
 * @brief      Clear CRC calculation done interrupt status and raw status
 *
 * @param[in]  CRCx:  Select the CRC module
 *
 * @return     none
 *
 *******************************************************************************/
#define CRC_ClearInt(CRCx)                  ((CRCx)->CRCIC.all = CRCIC_ALL_DONE_CLEAR_FLAG)




/****************************************************************************//**
 * @brief      Get CRC calculation done interrupt flag
 *
 * @param[in]  CRCx:  Select the CRC module
 *
 * @return     0 : interrupt is not occurred
 *             1 : interrupt is occurred
 *
 *******************************************************************************/
#define CRC_GetIntFlag(CRCx)                ((CRCx)->CRCIF.bit.DONE)




/****************************************************************************//**
 * @brief      Get CRC calculation done interrupt raw flag
 *
 * @param[in]  CRCx:  Select the CRC module
 *
 * @return     0 : interrupt is not occurred
 *             1 : interrupt is occurred
 *
 *******************************************************************************/
#define CRC_GetIntRawFlag(CRCx)             ((CRCx)->CRCRAWIF.bit.DONE)




/****************************************************************************//**
 * @brief      Is CRC calculation done
 *
 * @param[in]  CRCx:  Select the CRC module
 *
 * @return     0: CRC calculation has not done yet
 *             1: CRC calculation has done
 *
 *******************************************************************************/
#define CRC_IsCalculateDone(CRCx)           ((CRCx)->CRCRAWIF.bit.DONE)




/**
 *  @brief  CRC Public Function Declaration
 */
uint32_t CRC_Calculate(CRC_REGS* CRCx, const uint8_t *pu8DataStr, uint32_t u32DataLen);
void CRC_FeedStream(CRC_REGS* CRCx, const uint8_t *pu8DataStr, uint32_t u32DataLen);


#ifdef __cplusplus
}
#endif /* extern "C" */

#endif /* CRC_H */


/******************* (C) COPYRIGHT 2021 SPINTROL LIMITED CO. *****END OF FILE****/
