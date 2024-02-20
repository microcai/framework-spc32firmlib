/*******************************************************************************
* @file     aes.h
* @brief    AES driver header file.
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


#ifndef AES_H
#define AES_H

#ifdef __cplusplus
extern "C" {
#endif

#include "spc1068.h"




/**
 *  @brief  AES running mode type definition
 */
typedef enum
{
  AES_MODE_ECB          = AESCTL0_BIT_MODE_ECB,         /*!< AES running mode: ECB          */
  AES_MODE_CBC          = AESCTL0_BIT_MODE_CBC,         /*!< AES running mode: CBC          */
  AES_MODE_CTR          = AESCTL0_BIT_MODE_CTR,         /*!< AES running mode: CTR          */
  AES_MODE_CCM          = AESCTL0_BIT_MODE_CCM,         /*!< AES running mode: CCM          */
  AES_MODE_MMO          = AESCTL0_BIT_MODE_MMO,         /*!< AES running mode: MMO          */
  AES_MODE_BYPASS       = AESCTL0_BIT_MODE_BYPASS,      /*!< AES running mode: Bypass       */
} AES_ModeEnum;




/**
 *  @brief  AES key size type definition
 */
typedef enum
{
  AES_KEYSIZE_16BYTE    = AESCTL0_BIT_KEYSIZE_16BYTE,   /*!< AES key size select: 16 bytes  */
  AES_KEYSIZE_32BYTE    = AESCTL0_BIT_KEYSIZE_32BYTE,   /*!< AES key size select: 32 bytes  */
  AES_KEYSIZE_24BYTE    = AESCTL0_BIT_KEYSIZE_24BYTE,   /*!< AES key size select: 24 bytes  */
} AES_KeySizeEnum;




/**
 *  @brief  AES MIC size type definition
 */
typedef enum
{
  AES_MICLEN_0BYTE      = AESCTL0_BIT_MICLEN_0BYTE,     /*!< AES MIC length: 0 bytes        */
  AES_MICLEN_4BYTE      = AESCTL0_BIT_MICLEN_4BYTE,     /*!< AES MIC length: 4 bytes        */
  AES_MICLEN_8BYTE      = AESCTL0_BIT_MICLEN_8BYTE,     /*!< AES MIC length: 8 bytes        */
  AES_MICLEN_16BYTE     = AESCTL0_BIT_MICLEN_16BYTE,    /*!< AES MIC length: 16 bytes       */
} AES_MicLenEnum;




/****************************************************************************//**
 * @brief      Start AES
 *
 * @param[in]  AESx:  Select the AES module
 *
 * @return     none
 *
 *******************************************************************************/
#define AES_Start(AESx)                     ((AESx)->AESCTL0.all |= AESCTL0_ALL_START_AES_START)




/****************************************************************************//**
 * @brief      AES Encrypt mode
 *
 * @param[in]  AESx:  Select the AES module
 *
 * @return     none
 *
 *******************************************************************************/
#define AES_EncryptMode(AESx)               ((AESx)->AESCTL0.bit.DECRYPTEN = AESCTL0_BIT_DECRYPTEN_ENCRYPT)




/****************************************************************************//**
 * @brief      AES Decrypt mode
 *
 * @param[in]  AESx:  Select the AES module
 *
 * @return     none
 *
 *******************************************************************************/
#define AES_DecryptMode(AESx)               ((AESx)->AESCTL0.bit.DECRYPTEN = AESCTL0_BIT_DECRYPTEN_DECRYPT)




/****************************************************************************//**
 * @brief      Feed data in AES input stream
 *
 * @param[in]  AESx   :  Select the AES module
 * @param[in]  u32Data:  Data to be fed into input stream
 *
 * @return     none
 *
 *******************************************************************************/
#define AES_FeedData(AESx,u32Data)          ((AESx)->AESSTRIN.all = (u32Data))




/****************************************************************************//**
 * @brief      Read AES output data
 *
 * @param[in]  AESx:  Select the AES module
 *
 * @return     Stream output data
 *
 *******************************************************************************/
#define AES_ReadData(AESx)                  ((AESx)->AESSTROUT.all)




/****************************************************************************//**
 * @brief      Clear input FIFO
 *
 * @param[in]  AESx:  Select the AES module
 *
 * @return     none
 *
 *******************************************************************************/
#define AES_ClearInputFifo(AESx)            ((AESx)->AESCTL0.all |= AESCTL0_ALL_IFIFOCLR_CLEAR_INPUT_FIFO)




/****************************************************************************//**
 * @brief      Clear output FIFO
 *
 * @param[in]  AESx:  Select the AES module
 *
 * @return     none
 *
 *******************************************************************************/
#define AES_ClearOutputFifo(AESx)           ((AESx)->AESCTL0.all |= AESCTL0_ALL_OFIFOCLR_CLEAR_OUTPUT_FIFO)




/****************************************************************************//**
 * @brief      Enable AES operation done interrupt
 *
 * @param[in]  AESx:  Select the AES module
 *
 * @return     none
 *
 *******************************************************************************/
#define AES_EnableOperateDoneInt(AESx)      ((AESx)->AESINTMSK.bit.DONE = AESINTMSK_BIT_DONE_UNMASK)




/****************************************************************************//**
 * @brief      Disable AES operation done interrupt
 *
 * @param[in]  AESx:  Select the AES module
 *
 * @return     none
 *
 *******************************************************************************/
#define AES_DisableOperateDoneInt(AESx)     ((AESx)->AESINTMSK.bit.DONE = AESINTMSK_BIT_DONE_MASK)




/****************************************************************************//**
 * @brief      Enable AES input fifo full interrupt
 *
 * @param[in]  AESx:  Select the AES module
 *
 * @return     none
 *
 *******************************************************************************/
#define AES_EnableInputFifoFullInt(AESx)    ((AESx)->AESINTMSK.bit.IFIFOFULL = AESINTMSK_BIT_IFIFOFULL_UNMASK)




/****************************************************************************//**
 * @brief      Disable AES input fifo full interrupt
 *
 * @param[in]  AESx:  Select the AES module
 *
 * @return     none
 *
 *******************************************************************************/
#define AES_DisableInputFifoFullInt(AESx)   ((AESx)->AESINTMSK.bit.IFIFOFULL = AESINTMSK_BIT_IFIFOFULL_MASK)




/****************************************************************************//**
 * @brief      Enable AES output fifo empty interrupt
 *
 * @param[in]  AESx:  Select the AES module
 *
 * @return     none
 *
 *******************************************************************************/
#define AES_EnableOutputFifoEmptyInt(AESx)  ((AESx)->AESINTMSK.bit.OFIFOEMPTY = AESINTMSK_BIT_OFIFOEMPTY_UNMASK)




/****************************************************************************//**
 * @brief      Disable AES output fifo empty interrupt
 *
 * @param[in]  AESx:  Select the AES module
 *
 * @return     none
 *
 *******************************************************************************/
#define AES_DisableOutputFifoEmptyInt(AESx) ((AESx)->AESINTMSK.bit.OFIFOEMPTY = AESINTMSK_BIT_OFIFOEMPTY_MASK)




/****************************************************************************//**
 * @brief      Clear AES operation done interrupt status and raw status
 *
 * @param[in]  AESx:  Select the AES module
 *
 * @return     none
 *
 *******************************************************************************/
#define AES_ClearOperateDoneInt(AESx)       ((AESx)->AESIC.all = AESIC_ALL_DONE_CLEAR_FLAG)




/****************************************************************************//**
 * @brief      Clear AES input fifo full interrupt status and raw status
 *
 * @param[in]  AESx:  Select the AES module
 *
 * @return     none
 *
 *******************************************************************************/
#define AES_ClearInputFifoFullInt(AESx)     ((AESx)->AESIC.all = AESIC_ALL_IFIFOFULL_CLEAR_FLAG)




/****************************************************************************//**
 * @brief      Clear AES output fifo empty interrupt staus and raw status
 *
 * @param[in]  AESx:  Select the AES module
 *
 * @return     none
 *
 *******************************************************************************/
#define AES_ClearOutputFifoEmptyInt(AESx)   ((AESx)->AESIC.all = AESIC_ALL_OFIFOEMPTY_CLEAR_FLAG)




/****************************************************************************//**
 * @brief      Get AES operation done interrupt flag
 *
 * @param[in]  AESx:  Select the AES module
 *
 * @return     0 : AES operation done interrupt not occurred
 *             1 : AES operation done interrupt occurred
 *
 *******************************************************************************/
#define AES_GetOperateDoneIntFlag(AESx)     ((AESx)->AESIF.bit.DONE)




/****************************************************************************//**
 * @brief      Get AES input fifo full interrupt flag
 *
 * @param[in]  AESx:  Select the AES module
 *
 * @return     0 : AES input FIFO full interrupt not occurred
 *             1 : AES input FIFO full interrupt occurred
 *
 *******************************************************************************/
#define AES_GetInputFifoFullIntFlag(AESx)   ((AESx)->AESIF.bit.IFIFOFULL)




/****************************************************************************//**
 * @brief      Get AES output fifo empty interrupt flag
 *
 * @param[in]  AESx:  Select the AES module
 *
 * @return     0 : AES output FIFO empty interrupt not occurred
 *             1 : AES output FIFO empty interrupt occurred
 *
 *******************************************************************************/
#define AES_GetOutputFifoEmptyIntFlag(AESx) ((AESx)->AESIF.bit.OFIFOEMPTY)




/****************************************************************************//**
 * @brief      Get AES operation done interrupt raw flag
 *
 * @param[in]  AESx:  Select the AES module
 *
 * @return     0 : AES operation done interrupt not occurred
 *             1 : AES operation done interrupt occurred
 *
 *******************************************************************************/
#define AES_GetOperateDoneIntRawFlag(AESx)  ((AESx)->AESRAWIF.bit.DONE)




/****************************************************************************//**
 * @brief      Get AES input fifo full interrupt raw flag
 *
 * @param[in]  AESx:  Select the AES module
 *
 * @return     0 : AES input FIFO full interrupt not occurred
 *             1 : AES input FIFO full interrupt occurred
 *
 *******************************************************************************/
#define AES_GetInputFifoFullIntRawFlag(AESx)    ((AESx)->AESRAWIF.bit.IFIFOFULL)




/****************************************************************************//**
 * @brief      Get AES output fifo empty interrupt raw flag
 *
 * @param[in]  AESx:  Select the AES module
 *
 * @return     0 : AES output FIFO empty interrupt not occurred
 *             1 : AES output FIFO empty interrupt occurred
 *
 *******************************************************************************/
#define AES_GetOutputFifoEmptyIntRawFlag(AESx)  ((AESx)->AESRAWIF.bit.OFIFOEMPTY)




/****************************************************************************//**
 * @brief      Is AES operation done
 *
 * @param[in]  AESx:  Select the AES module
 *
 * @return     0 : AES operation has not done yet
 *             1 : AES operation done
 *
 *******************************************************************************/
#define AES_IsOperateDone(AESx)             ((AESx)->AESSTS.bit.DONE)




/****************************************************************************//**
 * @brief      Is AES input fifo full
 *
 * @param[in]  AESx:  Select the AES module
 *
 * @return     0 : Input FIFO is not full
 *             1 : Input FIFO is full
 *
 *******************************************************************************/
#define AES_IsInputFifoFull(AESx)           ((AESx)->AESSTS.bit.IFIFOFULL)




/****************************************************************************//**
 * @brief      Is AES output fifo ready to read
 *
 * @param[in]  AESx:  Select the AES module
 *
 * @return     0 : Output FIFO is not ready to read
 *             1 : Output FIFO is ready to read
 *
 *******************************************************************************/
#define AES_IsOutputFifoReady(AESx)         ((AESx)->AESSTS.bit.OFIFORDY)




/****************************************************************************//**
 * @brief      Is AES output fifo empty
 *
 * @param[in]  AESx:  Select the AES module
 *
 * @return     0 : Output FIFO is not empty
 *             1 : Output FIFO is empty
 *
 *******************************************************************************/
#define AES_IsOutputFifoEmpty(AESx)         ((AESx)->AESSTS.bit.OFIFOEMPTY)




/****************************************************************************//**
 * @brief      Is AES operation error
 *
 * @param[in]  AESx:  Select the AES module
 *
 * @return     0 : No operation error
 *             1 : Operation error occurred
 *
 *******************************************************************************/
#define AES_IsOperateError(AESx)            (((AESx)->AESSTS.bit.ERRCODE)? (1) : (0))




/**
 *  @brief  AES Public Function Declaration
 */
void AES_CBCModeInit(AES_REGS* AESx, uint32_t au32IV[], uint32_t au32Key[], AES_KeySizeEnum eKeySize, uint32_t u32MstrLen);
void AES_CCMModeInit(AES_REGS* AESx, uint32_t au32IV[], uint32_t au32Key[], AES_KeySizeEnum eKeySize, uint32_t u32MstrLen, uint32_t u32AstrLen);

ErrorStatus AES_EncryptData(AES_REGS* AESx, uint32_t u32DataIn[], uint32_t u32DataOut[], uint32_t u32InLen, uint32_t u32OutLen);
ErrorStatus AES_DecryptData(AES_REGS* AESx, uint32_t u32DataIn[], uint32_t u32DataOut[], uint32_t u32InLen, uint32_t u32OutLen);

void AES_Reset(AES_REGS* AESx);

void AES_ReadMIC(AES_REGS* AESx, uint32_t *pu32MicData, AES_MicLenEnum eMicLen);


#ifdef __cplusplus
}
#endif /* extern "C" */

#endif /* AES_H */


/******************* (C) COPYRIGHT 2021 SPINTROL LIMITED CO. *****END OF FILE****/
