/**************************************************************************//**
 * @file     ssp.h
 * @brief    SSP driver module header file.
 * @version  V1.2.0
 * @date     05-Feb-2021
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


#ifndef SSP_H
#define SSP_H

#ifdef __cplusplus
extern "C" {
#endif


#include "spc1068.h"




/**
 *  @brief  SSP Frame signal polarity type definition
 */
typedef enum
{
  SSP_FRM_ACTIVE_LOW              = 0,      /*!< SSP frame signal = 0, signal actvie  */
  SSP_FRM_ACTIVE_HIGH             = 1,      /*!< SSP frame signal = 1, signal actvie  */
} SSP_FramePolarityEnum;




/**
 *  @brief  SSP clock signal idle level type definition
 */
typedef enum
{
  SSP_CLK_IDLE_LOW                = 0,      /*!< SSP clock = 0, in idle state         */
  SSP_CLK_IDLE_HIGH               = 1,      /*!< SSP clock = 1, in idle state         */
} SSP_ClockIdleLevelEnum;




/**
 *  @brief  SSP Send data on which edge type definition
 */
typedef enum
{
  SSP_SEND_ON_RISING_EDGE         = 0,      /*!< SSP send data on rising edge and 
                                                 receiveed data latched on falling edge */
  SSP_SEND_ON_FALLING_EDGE        = 1,      /*!< SSP send data on falling edge and 
                                                 received data latched on rising edge */
} SSP_SendDataEdgeEnum;



/**
 *  @brief  SPI Communication mode
 */
typedef enum
{
  SSP_SPI_MODE_0                  = 0,      /*!< CLKPOL = 0, CLKPHS = 0         */
  SSP_SPI_MODE_1                  = 1,      /*!< CLKPOL = 0, CLKPHS = 1         */
  SSP_SPI_MODE_2                  = 2,      /*!< CLKPOL = 1, CLKPHS = 0         */
  SSP_SPI_MODE_3                  = 3,      /*!< CLKPOL = 1, CLKPHS = 1         */
} SSP_SPIModeEnum;





/**
 *  @brief  SSP PSP Mode Configure type definition
 */
typedef struct
{
  uint8_t T1;                     /*!< Start delay                                         (0 ~ 7)  */
  uint8_t T2;                     /*!< Dummy start(SSP_SSPSP[EDMYSTRT] +SSP_SSPSP[DMYSTRT])(0 ~ 15) */
  uint8_t T3;                     /*!< Data size (SSP_SSCR0[EDSS] and SSP_SSCR0[DSS])      (4 ~32)  */
  uint8_t T4;                     /*!< Dummy stop(SSP_SSPSP[EDMYSTOP] +SSP_SSPSP[DMYSTOP]) (0 ~ 31) */
  uint8_t T5;                     /*!< SSPSFRM delay                                       (0 ~ 127)*/
  uint8_t T6;                     /*!< SSPSFRM width                                       (1 ~ 63) */
  uint8_t SCMODE;                 /*!< Serial clock mode    0 = Fall, rise, low
                                                            1 = Rise, fall, low
                                                            2 = Rise, fall, high
                                                            3 = Fall, rise, high                    */
  uint8_t SFRMP;                  /*!< Serial frame polarity                                        */
  uint8_t ETDS;                   /*!< Receiver Time Out interrupt status                           */
} SSP_PSPType;




/**
 *  @brief  SSP Operate mode
 */
#define SSP_MASTER_MODE           (0x0)
#define SSP_SLAVE_MODE            (0x1)




/****************************************************************************//**
 * @brief      Enable SSP port
 *
 * @param[in]  SSPx : Select the SSP module
 *
 * @return     none
 *
 *******************************************************************************/
#define SSP_Enable(SSPx)                    ((SSPx)->SSPCTL0.bit.EN = SSPCTL0_BIT_EN_ENABLE)




/****************************************************************************//**
 * @brief      Disable SSP port
 *
 * @param[in]  SSPx : Select the SSP module
 *
 * @return     none
 *
 *******************************************************************************/
#define SSP_Disable(SSPx)                   ((SSPx)->SSPCTL0.bit.EN = SSPCTL0_BIT_EN_DISABLE)




/****************************************************************************//**
 * @brief      Enable Receive FIFO Overflow Interrupt
 *
 * @param[in]  SSPx : Select the SSP module
 *
 * @return     none
 *
 *******************************************************************************/
#define SSP_EnableRxFifoOverflowInt(SSPx)   ((SSPx)->SSPCTL0.bit.RFINTMSK = SSPCTL0_BIT_RFINTMSK_RXFIFO_OVERFLOW_INT_UNMASK)




/****************************************************************************//**
 * @brief      Disable Receive FIFO Overflow Interrupt
 *
 * @param[in]  SSPx : Select the SSP module
 *
 * @return     none
 *
 *******************************************************************************/
#define SSP_DisableRxFifoOverflowInt(SSPx)  ((SSPx)->SSPCTL0.bit.RFINTMSK = SSPCTL0_BIT_RFINTMSK_RXFIFO_OVERFLOW_INT_MASK)




/****************************************************************************//**
 * @brief      Enable Transmit FIFO Underflow Interrupt
 *
 * @param[in]  SSPx : Select the SSP module
 *
 * @return     none
 *
 *******************************************************************************/
#define SSP_EnableTxFifoUnderflowInt(SSPx)  ((SSPx)->SSPCTL0.bit.TFINTMSK = SSPCTL0_BIT_TFINTMSK_TXFIFO_UNDERFLOW_INT_UNMASK)




/****************************************************************************//**
 * @brief      Disable Transmit FIFO Underflow Interrupt
 *
 * @param[in]  SSPx : Select the SSP module
 *
 * @return     none
 *
 *******************************************************************************/
#define SSP_DisableTxFifoUnderflowInt(SSPx) ((SSPx)->SSPCTL0.bit.TFINTMSK = SSPCTL0_BIT_TFINTMSK_TXFIFO_UNDERFLOW_INT_MASK)




/****************************************************************************//**
 * @brief      Enable Bit Count Error Interrupt
 *
 * @param[in]  SSPx : Select the SSP module
 *
 * @return     none
 *
 *******************************************************************************/
#define SSP_EnableBitCountErrorInt(SSPx)    ((SSPx)->SSPCTL1.bit.BITCNTERRIE = SSPCTL1_BIT_BITCNTERRIE_BCE_INT_ENABLE)




/****************************************************************************//**
 * @brief      Disable Bit Count Error Interrupt
 *
 * @param[in]  SSPx : Select the SSP module
 *
 * @return     none
 *
 *******************************************************************************/
#define SSP_DisableBitCountErrorInt(SSPx)   ((SSPx)->SSPCTL1.bit.BITCNTERRIE = SSPCTL1_BIT_BITCNTERRIE_BCE_INT_DISABLE)




/****************************************************************************//**
 * @brief      Enable Receiver Time-out Interrupt
 *
 * @param[in]  SSPx : Select the SSP module
 *
 * @return     none
 *
 * @detail     Rx timeout interrupt do not generate NVIC interrupt service routine, 
 *             it just generate an Rx timeout status signal
 *
 *******************************************************************************/
#define SSP_EnableRxTimeoutInt(SSPx)        ((SSPx)->SSPCTL1.bit.RXTOIE = SSPCTL1_BIT_RXTOIE_RX_TIMEOUT_INT_ENABLE)




/****************************************************************************//**
 * @brief      Disable Receiver Time-out Interrupt
 *
 * @param[in]  SSPx : Select the SSP module
 *
 * @return     none
 *
 *******************************************************************************/
#define SSP_DisableRxTimeoutInt(SSPx)       ((SSPx)->SSPCTL1.bit.RXTOIE = SSPCTL1_BIT_RXTOIE_RX_TIMEOUT_INT_DISABLE)




/****************************************************************************//**
 * @brief      Enable Transmit FIFO Empty Interrupt
 *
 * @param[in]  SSPx : Select the SSP module
 *
 * @return     none
 *
 *******************************************************************************/
#define SSP_EnableTxFifoEmptyInt(SSPx)      ((SSPx)->SSPCTL1.bit.TFIE = SSPCTL1_BIT_TFIE_TXFIFO_INT_ENABLE)




/****************************************************************************//**
 * @brief      Disable Transmit FIFO Empty Interrupt
 *
 * @param[in]  SSPx : Select the SSP module
 *
 * @return     none
 *
 *******************************************************************************/
#define SSP_DisableTxFifoEmptyInt(SSPx)     ((SSPx)->SSPCTL1.bit.TFIE = SSPCTL1_BIT_TFIE_TXFIFO_INT_DISABLE)




/****************************************************************************//**
 * @brief      Enable Receive FIFO Full Interrupt
 *
 * @param[in]  SSPx : Select the SSP module
 *
 * @return     none
 *
 *******************************************************************************/
#define SSP_EnableRxFifoFullInt(SSPx)       ((SSPx)->SSPCTL1.bit.RFIE = SSPCTL1_BIT_RFIE_RXFIFO_INT_ENABLE)




/****************************************************************************//**
 * @brief      Disable Receive FIFO Full Interrupt
 *
 * @param[in]  SSPx : Select the SSP module
 *
 * @return     none
 *
 *******************************************************************************/
#define SSP_DisableRxFifoFullInt(SSPx)      ((SSPx)->SSPCTL1.bit.RFIE = SSPCTL1_BIT_RFIE_RXFIFO_INT_DISABLE)




/****************************************************************************//**
 * @brief      Enable loop back mode
 *
 * @param[in]  SSPx : Select the SSP module
 *
 * @return     none
 *
 *******************************************************************************/
#define SSP_EnableLoopBackMode(SSPx)        ((SSPx)->SSPCTL1.bit.LOOP = SSPCTL1_BIT_LOOP_ENABLE)




/****************************************************************************//**
 * @brief      Disable loop back mode
 *
 * @param[in]  SSPx : Select the SSP module
 *
 * @return     none
 *
 *******************************************************************************/
#define SSP_DisableLoopBackMode(SSPx)       ((SSPx)->SSPCTL1.bit.LOOP = SSPCTL1_BIT_LOOP_DISABLE)




/****************************************************************************//**
 * @brief      Get Transmit FIFO Level
 *
 * @param[in]  SSPx : Select the SSP module
 *
 * @return     Number of entries in TXFIFO
 *
 *******************************************************************************/
#define SSP_GetTxFifoLevel(SSPx)            ((SSPx)->SSPSTS.bit.TFLVL)




/****************************************************************************//**
 * @brief      Get Receive FIFO Level
 *
 * @param[in]  SSPx : Select the SSP module
 *
 * @return     Number of entries minus one in RXFIFO
 *
 *******************************************************************************/
#define SSP_GetRxFifoLevel(SSPx)            ((SSPx)->SSPSTS.bit.RFLVL)




/****************************************************************************//**
 * @brief      Set Receive FIFO Trigger Threshold
 *
 * @param[in]  SSPx : Select the SSP module
 *
 * @return     none
 *
 *******************************************************************************/
#define SSP_SetRxFifoTriggerLevel(SSPx,u8RxLevel)   ((SSPx)->SSPCTL1.bit.RFTH = (u8RxLevel))




/****************************************************************************//**
 * @brief      Set Transmit FIFO Trigger Threshold
 *
 * @param[in]  SSPx : Select the SSP module
 *
 * @return     none
 *
 *******************************************************************************/
#define SSP_SetTxFifoTriggerLevel(SSPx,u8TxLevel)   ((SSPx)->SSPCTL1.bit.TFTH = (u8TxLevel))




/****************************************************************************//**
 * @brief      Is Transmit FIFO Not Full
 *
 * @param[in]  SSPx : Select the SSP module
 *
 * @return     0 : TXFIFO is full
 *             1 : TXFIFO is not full
 *
 *******************************************************************************/
#define SSP_IsTxFifoNotFull(SSPx)           ((SSPx)->SSPSTS.bit.TNF)




/****************************************************************************//**
 * @brief      Is Receive FIFO Not Empty
 *
 * @param[in]  SSPx : Select the SSP module
 *
 * @return     0 : RXFIFO is empty
 *             1 : RXFIFO is not empty
 *
 *******************************************************************************/
#define SSP_IsRxFifoNotEmpty(SSPx)          ((SSPx)->SSPSTS.bit.RNE)




/****************************************************************************//**
 * @brief      Is Port Busy
 *
 * @param[in]  SSPx : Select the SSP module
 *
 * @return     0 : SSPx port is idle or disabled
 *             1 : SSPx port is currently transmitting or receiving framed data
 *
 *******************************************************************************/
#define SSP_IsBusy(SSPx)                    ((SSPx)->SSPSTS.bit.BUSY)




/****************************************************************************//**
 * @brief      Is Transmit FIFO Service Request
 *
 * @param[in]  SSPx : Select the SSP module
 *
 * @return     0 : TXFIFO level exceeds the TFT threshold (TFT + 1), or SSPx port disabled
 *             1 : TXFIFO level is at or below TFT threshold (TFT + 1), causes an interrupt request
 *
 *******************************************************************************/
#define SSP_IsTxFifoServiceRequest(SSPx)    ((SSPx)->SSPSTS.bit.TFS)




/****************************************************************************//**
 * @brief      Is Receive FIFO Service Request
 *
 * @param[in]  SSPx : Select the SSP module
 *
 * @return     0 : RXFIFO level is at or below RFT threshold (RFT), or SSPx port is disabled
 *             1 : RXFIFO level exceeds RFT threshold (RFT), causes an interrupt request
 *
 *******************************************************************************/
#define SSP_IsRxFifoServiceRequest(SSPx)    ((SSPx)->SSPSTS.bit.RFS)




/****************************************************************************//**
 * @brief      Is Receive FIFO Overflow
 *
 * @param[in]  SSPx : Select the SSP module
 *
 * @return     0 : Receive FIFO Overflow
 *             1 : Attempted data write to full RXFIFO, causes an interrupt request
 *
 *******************************************************************************/
#define SSP_IsRxFifoOverflow(SSPx)          ((SSPx)->SSPSTS.bit.RFOVF)




/****************************************************************************//**
 * @brief      Is Receive Time-out Interrupt pending
 *
 * @param[in]  SSPx : Select the SSP module
 *
 * @return     0 : No receiver time-out is pending
 *             1 : Receiver time-out pending, causes an interrupt request
 *
 *******************************************************************************/
#define SSP_IsRxTimeoutPending(SSPx)        ((SSPx)->SSPSTS.bit.RXTOINT)




/****************************************************************************//**
 * @brief      Is Transmit FIFO Underflow
 *
 * @param[in]  SSPx : Select the SSP module
 *
 * @return     0 : The TXFIFO has not experienced an underflow.
 *             1 : A read from the TXFIFO was attempted when the TXFIFO was 
 *                 empty, causes an interrupt if it is enabled (<Transmit FIFO 
 *                 Underrun Interrupt Mask> in the SSP Control Register 0 is 0)
 *
 *******************************************************************************/
#define SSP_IsTxFifoUnderflow(SSPx)         ((SSPx)->SSPSTS.bit.TFUDF)




/****************************************************************************//**
 * @brief      Clock Synchronization Status
 *
 * @param[in]  SSPx : Select the SSP module
 *
 * @return     0 : The SSPx port is ready for slave clock operations
 *             1 : The SSPx port is currently busy synchronizing slave mode signals
 *
 *******************************************************************************/
#define SSP_IsBusySyncSlaveClk(SSPx)        ((SSPx)->SSPSTS.bit.SLVCLKSTS)




/****************************************************************************//**
 * @brief      Is Bit Count Error
 *
 * @param[in]  SSPx : Select the SSP module
 *
 * @return     0 : The SSPx port has not experienced a bit count error
 *             1 : The SSPSFRMx signal was asserted when the bit counter was not zero
 *
 *******************************************************************************/
#define SSP_IsBitCountError(SSPx)           ((SSPx)->SSPSTS.bit.BITCNTERR)




/****************************************************************************//**
 * @brief      TX FIFO Odd Sample Status
 *
 * @param[in]  SSPx : Select the SSP module
 *
 * @return     0 : TxFIFO entry has an even number of samples
 *             1 : TxFIFO entry has an even number of samples
 *
 *******************************************************************************/
#define SSP_IsTxFifoHasOddSample(SSPx)      ((SSPx)->SSPSTS.bit.TFODDSTS)




/****************************************************************************//**
 * @brief      RX FIFO Odd Sample Status
 *
 * @param[in]  SSPx : Select the SSP module
 *
 * @return     0 : RxFIFO entry has 2 samples
 *             1 : RxFIFO entry has 1 sample
 *
 *******************************************************************************/
#define SSP_IsRxFifoHasOddSample(SSPx)      ((SSPx)->SSPSTS.bit.RFODDSTS)




/****************************************************************************//**
 * @brief      Clear Receive FIFO Overflow Interrupt
 *
 * @param[in]  SSPx : Select the SSP module
 *
 * @return     none
 *
 *******************************************************************************/
#define SSP_ClearRxFifoOverflowInt(SSPx)    ((SSPx)->SSPSTS.all = SSPSTS_ALL_RFOVF_Msk)




/****************************************************************************//**
 * @brief      Clear Transmit FIFO Underflow Interrupt
 *
 * @param[in]  SSPx : Select the SSP module
 *
 * @return     none
 *
 *******************************************************************************/
#define SSP_ClearTxFifoUnderflowInt(SSPx)   ((SSPx)->SSPSTS.all = SSPSTS_ALL_TFUDF_Msk)




/****************************************************************************//**
 * @brief      Clear Receive Time-out Interrupt
 *
 * @param[in]  SSPx : Select the SSP module
 *
 * @return     none
 *
 *******************************************************************************/
#define SSP_ClearRxTimeoutInt(SSPx)         ((SSPx)->SSPSTS.all = SSPSTS_ALL_RXTOINT_Msk)




/****************************************************************************//**
 * @brief      Clear Bit Count Error Interrupt
 *
 * @param[in]  SSPx : Select the SSP module
 *
 * @return     none
 *
 *******************************************************************************/
#define SSP_ClearBitCountErrorInt(SSPx)     ((SSPx)->SSPSTS.all = SSPSTS_ALL_BITCNTERR_Msk)




/****************************************************************************//**
 * @brief      Set Rx Time-out interval
 *
 * @param[in]  SSPx : Select the SSP module
 *
 * @return     none
 *
 *******************************************************************************/
#define SSP_SetRxTimeout(SSPx,u32Timeout)   ((SSPx)->SSPTO.all = (u32Timeout))




/****************************************************************************//**
 * @brief      Send one "data size" length data to SSP peripheral
 *
 * @param[in]  SSPx   :  Select the SSP module
 * @param[in]  u32Data:  The data to be sent
 *
 * @return     none
 *
 *******************************************************************************/
#define SSP_SendData(SSPx,u32Data)          ((SSPx)->SSPDATA.all = (u32Data))




/****************************************************************************//**
 * @brief      Receive one "data size" length data from the SSP peripheral
 *
 * @param[in]  SSPx:  Select the SSP module
 *
 * @return     The received data
 *
 *******************************************************************************/
#define SSP_ReceiveData(SSPx)               ((SSPx)->SSPDATA.all)




/**
 *  @brief  SSP Public Function Declaration
 */
void SSP_Init(SSP_REGS* SSPx, uint8_t u8MasterOrSlave, uint8_t u8DataSize, uint32_t u32Baudrate, SSP_FramePolarityEnum u1FramePolarity, SSP_ClockIdleLevelEnum u1ClockIdleLevel, SSP_SendDataEdgeEnum u1DataSendEdge);

void SSP_InitEasy(SSP_REGS* SSPx, uint8_t u8MasterOrSlave, uint8_t u8DataSize, uint32_t u32Baudrate);

void SSP_InitPSPMode(SSP_REGS* SSPx, SSP_PSPType *PSPConfig);
void SSP_PSPEasy(SSP_REGS* SSPx, uint8_t u8InterframeLength, uint8_t u8DataLength);

void SSP_Send(SSP_REGS* SSPx, uint32_t *pu8Buffer, uint32_t u32Offset, uint32_t u32Count);
uint32_t SSP_Recv(SSP_REGS* SSPx, uint32_t *pu8Buffer, uint32_t u32Offset, uint32_t u32Count);


#ifdef __cplusplus
}
#endif /* extern "C" */

#endif /* SSP_H */


/******************* (C) COPYRIGHT 2021 SPINTROL LIMITED CO. *****END OF FILE****/
