/**************************************************************************//**
 * @file     i2c.h
 * @brief    I2C driver header file.
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


#ifndef I2C_H
#define I2C_H

#ifdef __cplusplus
extern "C" {
#endif


#include "spc1068.h"




/**
 *  @brief I2C address mode type definition
 */
typedef enum
{
  I2C_ADDR_7BIT         = 0,                  /*!< I2C 7 bits address mode  */
  I2C_ADDR_10BIT        = 1,                  /*!< I2C 10 bits address mode */
} I2C_AddrModeEnum;




/**
 *  @brief I2C interrupt type definition
 */
typedef enum
{
  I2C_INT_RX_UNDER = 0,                     /*!< Receive FIFO underflow interrupt */

  I2C_INT_RX_OVER,                          /*!< Receive FIFO overflow interrupt  */

  I2C_INT_RX_FULL,                          /*!< Receive FIFO full interrupt      */

  I2C_INT_TX_OVER,                          /*!< Transmit FIFO overflow interrupt */

  I2C_INT_TX_EMPTY,                         /*!< Transmit FIFO empty interrupt    */

  I2C_INT_RD_REQ,                           /*!< Read request interrupt. It is set when I2C as a slave has been addressed
                                                  by a remote master that is asking for data to be transferred */

  I2C_INT_TX_ABORT,                         /*!< Transmit abort interrupt         */

  I2C_INT_RX_DONE,                          /*!< Transmit done interrupt. When I2C is acting as a slave-transmitter, this bit
                                                  is set to 1 if the master does not acknowledge a transmitted byte. This
                                                  occurs on the last byte of the transmission, indicating that the transmission
                                                  is done */

  I2C_INT_ACTIVITY,                         /*!< Bus activity interrupt           */

  I2C_INT_STOP_DET,                         /*!< Stop condition occur interrupt.Indicates whether a STOP condition has occurred
                                                  on the I2C interface            */

  I2C_INT_START_DET,                        /*!< Start condition occur interrupt. Indicates whether a START or RESTART condition
                                                  has occurred on the I2C interface */

  I2C_INT_GEN_CALL,                         /*!< General call interrupt. Set only when a General Call address is received and
                                                  it is acknowledged */

  I2C_INT_ALL,                              /*!< All the interrupts               */
} I2C_IntEnum;




/****************************************************************************//**
 * @brief      Enable I2C
 *
 * @param[in]  I2Cx:  Select the I2C module
 *
 * @return     none
 *
 *******************************************************************************/
#define I2C_Enable(I2Cx)                    ((I2Cx)->I2CENABLE.all = I2CENABLE_ALL_EN_ENABLE)




/****************************************************************************//**
 * @brief      Disable I2C
 *
 * @param[in]  I2Cx:  Select the I2C module
 *
 * @return     none
 *
 *******************************************************************************/
#define I2C_Disable(I2Cx)                   ((I2Cx)->I2CENABLE.all = I2CENABLE_ALL_EN_DISABLE)




/****************************************************************************//**
 * @brief      Master read request
 *
 * @param[in]  I2Cx:  Select the I2C module
 *
 * @return     none
 *
 *******************************************************************************/
#define I2C_MasterReadCmd(I2Cx)             ((I2Cx)->I2CDATACMD.all = 0x100)




/****************************************************************************//**
 * @brief      Send one byte data
 *
 * @param[in]  I2Cx  : Select the I2C module
 * @param[in]  u8Data: Byte data to be sent
  *
 * @return     none
 *
 *******************************************************************************/
#define I2C_SendByte(I2Cx,u8Data)           ((I2Cx)->I2CDATACMD.all = (((uint32_t)(u8Data)) & 0xFF))




/****************************************************************************//**
 * @brief      I2c read one byte
 *
 * @param[in]  I2Cx:  Select the I2C module
 *
 * @return     The received data(8-bit)
 *
 *******************************************************************************/
#define I2C_ReceiveByte(I2Cx)               ((uint8_t)((I2Cx)->I2CDATACMD.all & 0xFF))




/****************************************************************************//**
 * @brief      Enable I2C receive buffer underflow interrupt
 *
 * @param[in]  I2Cx:  Select the I2C module
 *
 * @return     none
 *
 *******************************************************************************/
#define I2C_EnableRxUnderflowInt(I2Cx)      ((I2Cx)->I2CIE.bit.RXUDF = I2CIE_BIT_RXUDF_ENABLE)




/****************************************************************************//**
 * @brief      Disable I2C receive buffer underflow interrupt
 *
 * @param[in]  I2Cx:  Select the I2C module
 *
 * @return     none
 *
 *******************************************************************************/
#define I2C_DisableRxUnderflowInt(I2Cx)     ((I2Cx)->I2CIE.bit.RXUDF = I2CIE_BIT_RXUDF_DISABLE)




/****************************************************************************//**
 * @brief      Enable I2C receive buffer overflow interrupt
 *
 * @param[in]  I2Cx:  Select the I2C module
 *
 * @return     none
 *
 *******************************************************************************/
#define I2C_EnableRxOverflowInt(I2Cx)       ((I2Cx)->I2CIE.bit.RXOVF = I2CIE_BIT_RXOVF_ENABLE)




/****************************************************************************//**
 * @brief      Disable I2C receive buffer overflow interrupt
 *
 * @param[in]  I2Cx:  Select the I2C module
 *
 * @return     none
 *
 *******************************************************************************/
#define I2C_DisableRxOverflowInt(I2Cx)      ((I2Cx)->I2CIE.bit.RXOVF = I2CIE_BIT_RXOVF_DISABLE)




/****************************************************************************//**
 * @brief      Enable I2C receive buffer full interrupt
 *
 * @param[in]  I2Cx:  Select the I2C module
 *
 * @return     none
 *
 *******************************************************************************/
#define I2C_EnableRxFullInt(I2Cx)           ((I2Cx)->I2CIE.bit.RXFULL = I2CIE_BIT_RXFULL_ENABLE)




/****************************************************************************//**
 * @brief      Disable I2C receive buffer full interrupt
 *
 * @param[in]  I2Cx:  Select the I2C module
 *
 * @return     none
 *
 *******************************************************************************/
#define I2C_DisableRxFullInt(I2Cx)          ((I2Cx)->I2CIE.bit.RXFULL = I2CIE_BIT_RXFULL_DISABLE)




/****************************************************************************//**
 * @brief      Enable I2C transmit buffer overflow interrupt
 *
 * @param[in]  I2Cx:  Select the I2C module
 *
 * @return     none
 *
 *******************************************************************************/
#define I2C_EnableTxOverflowInt(I2Cx)       ((I2Cx)->I2CIE.bit.TXOVF = I2CIE_BIT_TXOVF_ENABLE)




/****************************************************************************//**
 * @brief      Disable I2C transmit buffer overflow interrupt
 *
 * @param[in]  I2Cx:  Select the I2C module
 *
 * @return     none
 *
 *******************************************************************************/
#define I2C_DisableTxOverflowInt(I2Cx)      ((I2Cx)->I2CIE.bit.TXOVF = I2CIE_BIT_TXOVF_DISABLE)




/****************************************************************************//**
 * @brief      Enable I2C transmit buffer empty interrupt
 *
 * @param[in]  I2Cx:  Select the I2C module
 *
 * @return     none
 *
 *******************************************************************************/
#define I2C_EnableTxEmptyInt(I2Cx)          ((I2Cx)->I2CIE.bit.TXEMPTY = I2CIE_BIT_TXEMPTY_ENABLE)




/****************************************************************************//**
 * @brief      Disable I2C transmit buffer empty interrupt
 *
 * @param[in]  I2Cx:  Select the I2C module
 *
 * @return     none
 *
 *******************************************************************************/
#define I2C_DisableTxEmptyInt(I2Cx)         ((I2Cx)->I2CIE.bit.TXEMPTY = I2CIE_BIT_TXEMPTY_DISABLE)




/****************************************************************************//**
 * @brief      Enable I2C read request interrupt(Act as a slave)
 *
 * @param[in]  I2Cx:  Select the I2C module
 *
 * @return     none
 *
 *******************************************************************************/
#define I2C_EnableReadRequestInt(I2Cx)      ((I2Cx)->I2CIE.bit.RDREQ = I2CIE_BIT_RDREQ_ENABLE)




/****************************************************************************//**
 * @brief      Disable I2C read request empty interrupt(Act as a slave)
 *
 * @param[in]  I2Cx:  Select the I2C module
 *
 * @return     none
 *
 *******************************************************************************/
#define I2C_DisableReadRequestInt(I2Cx)     ((I2Cx)->I2CIE.bit.RDREQ = I2CIE_BIT_RDREQ_DISABLE)




/****************************************************************************//**
 * @brief      Enable I2C transmit abort interrupt
 *
 * @param[in]  I2Cx:  Select the I2C module
 *
 * @return     none
 *
 *******************************************************************************/
#define I2C_EnableTxAbortInt(I2Cx)          ((I2Cx)->I2CIE.bit.TXABRT = I2CIE_BIT_TXABRT_ENABLE)




/****************************************************************************//**
 * @brief      Disable I2C transmit abort interrupt
 *
 * @param[in]  I2Cx:  Select the I2C module
 *
 * @return     none
 *
 *******************************************************************************/
#define I2C_DisableTxAbortInt(I2Cx)         ((I2Cx)->I2CIE.bit.TXABRT = I2CIE_BIT_TXABRT_DISABLE)




/****************************************************************************//**
 * @brief      Enable I2C slave transmit done interrupt(Act as a slave-transmitter)
 *
 * @param[in]  I2Cx:  Select the I2C module
 *
 * @return     none
 *
 *******************************************************************************/
#define I2C_EnableRxDoneInt(I2Cx)           ((I2Cx)->I2CIE.bit.RXDONE = I2CIE_BIT_RXDONE_ENABLE)




/****************************************************************************//**
 * @brief      Disable I2C slave transmit done interrupt(Act as a slave-transmitter)
 *
 * @param[in]  I2Cx:  Select the I2C module
 *
 * @return     none
 *
 *******************************************************************************/
#define I2C_DisableRxDoneInt(I2Cx)          ((I2Cx)->I2CIE.bit.RXDONE = I2CIE_BIT_RXDONE_DISABLE)




/****************************************************************************//**
 * @brief      Enable I2C activity interrupt
 *
 * @param[in]  I2Cx:  Select the I2C module
 *
 * @return     none
 *
 *******************************************************************************/
#define I2C_EnableActivityInt(I2Cx)         ((I2Cx)->I2CIE.bit.ACT = I2CIE_BIT_ACT_ENABLE)




/****************************************************************************//**
 * @brief      Disable I2C activity interrupt
 *
 * @param[in]  I2Cx:  Select the I2C module
 *
 * @return     none
 *
 *******************************************************************************/
#define I2C_DisableActivityInt(I2Cx)        ((I2Cx)->I2CIE.bit.ACT = I2CIE_BIT_ACT_DISABLE)




/****************************************************************************//**
 * @brief      Enable I2C STOP detect interrupt
 *
 * @param[in]  I2Cx:  Select the I2C module
 *
 * @return     none
 *
 *******************************************************************************/
#define I2C_EnableStopDetectInt(I2Cx)       ((I2Cx)->I2CIE.bit.STOPDET = I2CIE_BIT_STOPDET_ENABLE)




/****************************************************************************//**
 * @brief      Disable I2C STOP detect interrupt
 *
 * @param[in]  I2Cx:  Select the I2C module
 *
 * @return     none
 *
 *******************************************************************************/
#define I2C_DisableStopDetectInt(I2Cx)      ((I2Cx)->I2CIE.bit.STOPDET = I2CIE_BIT_STOPDET_DISABLE)




/****************************************************************************//**
 * @brief      Enable I2C START detect interrupt
 *
 * @param[in]  I2Cx:  Select the I2C module
 *
 * @return     none
 *
 *******************************************************************************/
#define I2C_EnableStartDetectInt(I2Cx)      ((I2Cx)->I2CIE.bit.STARTDET = I2CIE_BIT_STARTDET_ENABLE)




/****************************************************************************//**
 * @brief      Disable I2C START detect interrupt
 *
 * @param[in]  I2Cx:  Select the I2C module
 *
 * @return     none
 *
 *******************************************************************************/
#define I2C_DisableStartDetectInt(I2Cx)     ((I2Cx)->I2CIE.bit.STARTDET = I2CIE_BIT_STARTDET_DISABLE)




/****************************************************************************//**
 * @brief      Enable I2C General Call interrupt
 *
 * @param[in]  I2Cx:  Select the I2C module
 *
 * @return     none
 *
 *******************************************************************************/
#define I2C_EnableGeneralCallInt(I2Cx)      ((I2Cx)->I2CIE.bit.GENCALL = I2CIE_BIT_GENCALL_ENABLE)




/****************************************************************************//**
 * @brief      Disable I2C General Call interrupt
 *
 * @param[in]  I2Cx:  Select the I2C module
 *
 * @return     none
 *
 *******************************************************************************/
#define I2C_DisableGeneralCallInt(I2Cx)     ((I2Cx)->I2CIE.bit.GENCALL = I2CIE_BIT_GENCALL_DISABLE)




/****************************************************************************//**
 * @brief      Disable I2C General Call interrupt
 *
 * @param[in]  I2Cx:  Select the I2C module
 *
 * @return     none
 *
 *******************************************************************************/
#define I2C_DisableAllInt(I2Cx)             ((I2Cx)->I2CIE.all = 0x0000)




/****************************************************************************//**
 * @brief      Get I2C receive buffer underflow interrupt status
 *
 * @param[in]  I2Cx:  Select the I2C module
 *
 * @return     0 : Receive buffer underflow interrupt not occurred
 *             1 : Receive buffer underflow interrupt occurred
 *
 * @note       Set if the processor attempts to read the receive buffer 
 *             when it is empty by reading from the I2CDATACMD register
 *
 *******************************************************************************/
#define I2C_GetRxUnderflowIntFlag(I2Cx)     ((I2Cx)->I2CIF.bit.RXUDF)




/****************************************************************************//**
 * @brief      Get I2C receive buffer overflow interrupt status
 *
 * @param[in]  I2Cx:  Select the I2C module
 *
 * @return     0 : Receive buffer overflow interrupt not occurred
 *             1 : Receive buffer overflow interrupt occurred
 *
 * @note       Set if the receive buffer is completely filled to RX_BUFFER_DEPTH 
 *             and an additional byte is received from an external I2C device
 *
 *******************************************************************************/
#define I2C_GetRxOverflowIntFlag(I2Cx)      ((I2Cx)->I2CIF.bit.RXOVF)




/****************************************************************************//**
 * @brief      Get I2C receive buffer full interrupt status
 *
 * @param[in]  I2Cx:  Select the I2C module
 *
 * @return     0 : Receive buffer full interrupt not occurred
 *             1 : Receive buffer full interrupt occurred
 *
 * @note       Set when the receive buffer reaches or goes above the threshold 
 *             in the I2CRXTH register
 *
 *******************************************************************************/
#define I2C_GetRxFullIntFlag(I2Cx)          ((I2Cx)->I2CIF.bit.RXFULL)




/****************************************************************************//**
 * @brief      Get I2C transmit buffer overflow interrupt status
 *
 * @param[in]  I2Cx:  Select the I2C module
 *
 * @return     0 : Transmit buffer overflow interrupt not occurred
 *             1 : Transmit buffer overflow interrupt occurred
 *
 * @note       Set during transmit if the transmit buffer is filled to 
 *             TX_BUFFER_DEPTH and the processor attempts to issue another 
 *             I2C command by writing to the I2CDATACMD register
 *
 *******************************************************************************/
#define I2C_GetTxOverflowIntFlag(I2Cx)      ((I2Cx)->I2CIF.bit.TXOVF)




/****************************************************************************//**
 * @brief      Get I2C transmit buffer empty interrupt status
 *
 * @param[in]  I2Cx:  Select the I2C module
 *
 * @return     0 : Transmit buffer empty interrupt not occurred
 *             1 : Transmit buffer empty interrupt occurred
 *
 * @note       This bit is set to 1 when the transmit buffer is at or below the 
 *             threshold value set in the I2CTXTH register. It is automatically 
 *             cleared by hardware when the buffer level goes above the threshold
 *
 *******************************************************************************/
#define I2C_GetTxEmptyIntFlag(I2Cx)         ((I2Cx)->I2CIF.bit.TXEMPTY)




/****************************************************************************//**
 * @brief      Get I2C read request interrupt status
 *
 * @param[in]  I2Cx:  Select the I2C module
 *
 * @return     0 : Read request interrupt not occurred
 *             1 : Read request interrupt occurred
 *
 * @note       This bit is set to 1 when I2C is acting as a slave and another 
 *             I2C master is attempting to read data from I2C
 *
 *******************************************************************************/
#define I2C_GetReadRequestIntFlag(I2Cx)     ((I2Cx)->I2CIF.bit.RDREQ)




/****************************************************************************//**
 * @brief      Get I2C transmit abort interrupt status
 *
 * @param[in]  I2Cx:  Select the I2C module
 *
 * @return     0 : Transmit abort interrupt not occurred
 *             1 : Transmit abort interrupt occurred
 *
 * @note       This bit is set to 1 when I2C is acting as a slave and another 
 *             I2C master is attempting to read data from I2C
 *
 *******************************************************************************/
#define I2C_GetTxAbortIntFlag(I2Cx)         ((I2Cx)->I2CIF.bit.TXABRT)




/****************************************************************************//**
 * @brief      Get I2C slave transmit done interrupt status
 *
 * @param[in]  I2Cx:  Select the I2C module
 *
 * @return     0 : Slave transmit done interrupt not occurred
 *             1 : Slave transmit done interrupt occurred
 *
 * @note       When the I2C is acting as a slave-transmitter, this bit is set to 1 
 *             if the master does not acknowledge a transmitted byte. This occurs on 
 *             the last byte of the transmission, indicating that the transmission 
 *             is done
 *
 *******************************************************************************/
#define I2C_GetRxDoneIntFlag(I2Cx)          ((I2Cx)->I2CIF.bit.RXDONE)




/****************************************************************************//**
 * @brief      Get I2C activity interrupt status
 *
 * @param[in]  I2Cx:  Select the I2C module
 *
 * @return     0 : Slave transmit done interrupt not occurred
 *             1 : Slave transmit done interrupt occurred
 *
 *******************************************************************************/
#define I2C_GetActivityIntFlag(I2Cx)        ((I2Cx)->I2CIF.bit.ACT)




/****************************************************************************//**
 * @brief      Get I2C STOP detect interrupt status
 *
 * @param[in]  I2Cx:  Select the I2C module
 *
 * @return     0 : A STOP condition not occurred on the I2C interface
 *             1 : A STOP condition has occurred on the I2C interface
 *
 *******************************************************************************/
#define I2C_GetStopDetectIntFlag(I2Cx)      ((I2Cx)->I2CIF.bit.STOPDET)




/****************************************************************************//**
 * @brief      Get I2C START detect interrupt status
 *
 * @param[in]  I2Cx:  Select the I2C module
 *
 * @return     0 : A START or RESTART condition not occurred on the I2C interface
 *             1 : A START or RESTART condition has occurred on the I2C interface
 *
 *******************************************************************************/
#define I2C_GetStartDetectIntFlag(I2Cx)     ((I2Cx)->I2CIF.bit.STARTDET)




/****************************************************************************//**
 * @brief      Get I2C General Call interrupt status
 *
 * @param[in]  I2Cx:  Select the I2C module
 *
 * @return     0 : A General Call address is not received
 *             1 : A General Call address is received and it is acknowledged
 *
 *******************************************************************************/
#define I2C_GetGeneralCallIntFlag(I2Cx)     ((I2Cx)->I2CIF.bit.GENCALL)




/****************************************************************************//**
 * @brief      Get I2C receive buffer underflow interrupt raw status
 *
 * @param[in]  I2Cx:  Select the I2C module
 *
 * @return     1 or 0
 *
 *******************************************************************************/
#define I2C_GetRxUnderflowIntRawFlag(I2Cx)  ((I2Cx)->I2CRAWIF.bit.RXUDF)




/****************************************************************************//**
 * @brief      Get I2C receive buffer overflow interrupt raw status
 *
 * @param[in]  I2Cx:  Select the I2C module
 *
 * @return     1 or 0
 *
 *******************************************************************************/
#define I2C_GetRxOverflowIntRawFlag(I2Cx)   ((I2Cx)->I2CRAWIF.bit.RXOVF)




/****************************************************************************//**
 * @brief      Get I2C receive buffer full interrupt raw status
 *
 * @param[in]  I2Cx:  Select the I2C module
 *
 * @return     1 or 0
 *
 *******************************************************************************/
#define I2C_GetRxFullIntRawFlag(I2Cx)       ((I2Cx)->I2CRAWIF.bit.RXFULL)




/****************************************************************************//**
 * @brief      Get I2C transmit buffer overflow interrupt raw status
 *
 * @param[in]  I2Cx:  Select the I2C module
 *
 * @return     1 or 0
 *
 *******************************************************************************/
#define I2C_GetTxOverflowIntRawFlag(I2Cx)   ((I2Cx)->I2CRAWIF.bit.TXOVF)




/****************************************************************************//**
 * @brief      Get I2C transmit buffer empty interrupt raw status
 *
 * @param[in]  I2Cx:  Select the I2C module
 *
 * @return     1 or 0
 *
 *******************************************************************************/
#define I2C_GetTxEmptyIntRawFlag(I2Cx)      ((I2Cx)->I2CRAWIF.bit.TXEMPTY)




/****************************************************************************//**
 * @brief      Get I2C read request interrupt raw status
 *
 * @param[in]  I2Cx:  Select the I2C module
 *
 * @return     1 or 0
 *
 *******************************************************************************/
#define I2C_GetReadRequestIntRawFlag(I2Cx)  ((I2Cx)->I2CRAWIF.bit.RDREQ)




/****************************************************************************//**
 * @brief      Get I2C transmit abort interrupt raw status
 *
 * @param[in]  I2Cx:  Select the I2C module
 *
 * @return     1 or 0
 *
 *******************************************************************************/
#define I2C_GetTxAbortIntRawFlag(I2Cx)      ((I2Cx)->I2CRAWIF.bit.TXABRT)




/****************************************************************************//**
 * @brief      Get I2C slave transmit done interrupt raw status
 *
 * @param[in]  I2Cx:  Select the I2C module
 *
 * @return     1 or 0
 *
 *******************************************************************************/
#define I2C_GetRxDoneIntRawFlag(I2Cx)       ((I2Cx)->I2CRAWIF.bit.RXDONE)




/****************************************************************************//**
 * @brief      Get I2C activity interrupt raw status
 *
 * @param[in]  I2Cx:  Select the I2C module
 *
 * @return     1 or 0
 *
 *******************************************************************************/
#define I2C_GetActivityIntRawFlag(I2Cx)     ((I2Cx)->I2CRAWIF.bit.ACT)




/****************************************************************************//**
 * @brief      Get I2C STOP detect interrupt raw status
 *
 * @param[in]  I2Cx:  Select the I2C module
 *
 * @return     1 or 0
 *
 *******************************************************************************/
#define I2C_GetStopDetectIntRawFlag(I2Cx)   ((I2Cx)->I2CRAWIF.bit.STOPDET)




/****************************************************************************//**
 * @brief      Get I2C START detect interrupt raw status
 *
 * @param[in]  I2Cx:  Select the I2C module
 *
 * @return     1 or 0
 *
 *******************************************************************************/
#define I2C_GetStartDetectIntRawFlag(I2Cx)  ((I2Cx)->I2CRAWIF.bit.STARTDET)




/****************************************************************************//**
 * @brief      Get I2C General Call interrupt raw status
 *
 * @param[in]  I2Cx:  Select the I2C module
 *
 * @return     1 or 0
 *
 *******************************************************************************/
#define I2C_GetGeneralCallIntRawFlag(I2Cx)  ((I2Cx)->I2CRAWIF.bit.GENCALL)




/****************************************************************************//**
 * @brief      I2C activity status
 *
 * @param[in]  I2Cx:  Select the I2C module
 *
 * @return     0 : I2C is idle
 *             1 : I2C is active
 *
 *******************************************************************************/
#define I2C_IsActivity(I2Cx)                ((I2Cx)->I2CSTS.bit.ACT)




/****************************************************************************//**
 * @brief      Is I2C Transmit FIFO Not Full
 *
 * @param[in]  I2Cx:  Select the I2C module
 *
 * @return     0 : Transmit FIFO is full
 *             1 : Transmit FIFO is not full
 *
 *******************************************************************************/
#define I2C_IsTxFifoNotFull(I2Cx)           ((I2Cx)->I2CSTS.bit.TFNF)




/****************************************************************************//**
 * @brief      Is I2C Transmit FIFO Completely Empty
 *
 * @param[in]  I2Cx:  Select the I2C module
 *
 * @return     0 : Transmit FIFO is not empty
 *             1 : Transmit FIFO is empty
 *
 *******************************************************************************/
#define I2C_IsTxFifoEmpty(I2Cx)             ((I2Cx)->I2CSTS.bit.TFE)




/****************************************************************************//**
 * @brief      Is I2C Receive FIFO Not Empty
 *
 * @param[in]  I2Cx:  Select the I2C module
 *
 * @return     0 : Receive FIFO is empty
 *             1 : Receive FIFO is not empty
 *
 *******************************************************************************/
#define I2C_IsRxFifoNotEmpty(I2Cx)          ((I2Cx)->I2CSTS.bit.RFNE)




/****************************************************************************//**
 * @brief      Is I2C Receive FIFO Completely Full
 *
 * @param[in]  I2Cx:  Select the I2C module
 *
 * @return     0 : Receive FIFO is not full
 *             1 : Receive FIFO is full
 *
 *******************************************************************************/
#define I2C_IsRxFifoFull(I2Cx)              ((I2Cx)->I2CSTS.bit.RFF)




/****************************************************************************//**
 * @brief      Master FSM Activity Status
 *
 * @param[in]  I2Cx:  Select the I2C module
 *
 * @return     0 : Master FSM is in IDLE state so the Master part of I2C is not Active
 *             1 : Master FSM is not in IDLE state so the Master part of I2C is Active
 *
 *******************************************************************************/
#define I2C_IsMasterActivity(I2Cx)          ((I2Cx)->I2CSTS.bit.MACT)




/****************************************************************************//**
 * @brief      Slave FSM Activity Status
 *
 * @param[in]  I2Cx:  Select the I2C module
 *
 * @return     0 : Slave FSM is in IDLE state so the Slave part of I2C is not Active
 *             1 : Slave FSM is not in IDLE state so the Slave part of I2C is Active
 *
 *******************************************************************************/
#define I2C_IsSlaveActivity(I2Cx)           ((I2Cx)->I2CSTS.bit.SACT)




/****************************************************************************//**
 * @brief      Set the Transmit FIFO threshold
 *
 * @param[in]  I2Cx      :  Select the I2C module
 * @param[in]  u32TxLevel:  Transmit FIFO threshold level
 *
 * @return     none
 *
 *******************************************************************************/
#define I2C_SetTxFifoThreshold(I2Cx,u32TxLevel)   ((I2Cx)->I2CTXTH.all = u32TxLevel)




/****************************************************************************//**
 * @brief      Set the Receive FIFO threshold
 *
 * @param[in]  I2Cx      :  Select the I2C module
 * @param[in]  u32RxLevel:  Receive FIFO threshold level
 *
 * @return     none
 *
 *******************************************************************************/
#define I2C_SetRxFifoThreshold(I2Cx,u32RxLevel)   ((I2Cx)->I2CRXTH.all = u32RxLevel)




/****************************************************************************//**
 * @brief      Get the Transmit FIFO level
 *
 * @param[in]  I2Cx      :  Select the I2C module
 * @param[in]  u32TxLevel:  Transmit FIFO threshold level
 *
 * @return     The number of valid data entries in the transmit FIFO
 *
 *******************************************************************************/
#define I2C_GetTxFifoLevel(I2Cx)            ((I2Cx)->I2CTFLVL.all)




/****************************************************************************//**
 * @brief      Get the Receive FIFO level
 *
 * @param[in]  I2Cx      :  Select the I2C module
 * @param[in]  u32RxLevel:  Receive FIFO threshold level
 *
 * @return     The number of valid data entries in the receive FIFO
 *
 *******************************************************************************/
#define I2C_GetRxFifoLevel(I2Cx)            ((I2Cx)->I2CRFLVL.all)




/****************************************************************************//**
 * @brief      Enable I2C General Call ACK function
 *             I2C responses with a ACK when it receives a general call
 *
 * @param[in]  I2Cx:  Select the I2C module
 *
 * @return     none
 *
 *******************************************************************************/
#define I2C_AckGeneralCall(I2Cx)            ((I2Cx)->I2CACKGC.all = I2CACKGC_ALL_ACKGC_ENABLE)





/****************************************************************************//**
 * @brief      Disable I2C General Call ACK function
 *             I2C responds with a NACK
 *
 * @param[in]  I2Cx:  Select the I2C module
 *
 * @return     none
 *
 *******************************************************************************/
#define I2C_NotAckGeneralCall(I2Cx)         ((I2Cx)->I2CACKGC.all = I2CACKGC_ALL_ACKGC_DISABLE)




/**
 *  @brief  I2C Public Function Declaration
 */
void I2C_MasterInit(I2C_REGS* I2Cx, I2C_AddrModeEnum eAddrMode, uint32_t u32TarAddr);
void I2C_SlaveInit(I2C_REGS* I2Cx, I2C_AddrModeEnum eAddrMode, uint32_t u32SlvAddr);

void I2C_EnableGeneralCall(I2C_REGS* I2Cx);
void I2C_DisableGeneralCall(I2C_REGS* I2Cx);

void I2C_EnableStartByte(I2C_REGS* I2Cx);
void I2C_DisableStartByte(I2C_REGS* I2Cx);

void I2C_ClearInt(I2C_REGS* I2Cx, I2C_IntEnum eIntType);


#ifdef __cplusplus
}
#endif /* extern "C" */

#endif /* I2C_H */


/******************* (C) COPYRIGHT 2021 SPINTROL LIMITED CO. *****END OF FILE****/
