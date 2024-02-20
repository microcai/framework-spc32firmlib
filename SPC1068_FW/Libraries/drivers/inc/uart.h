/**************************************************************************//**
 * @file     uart.h
 * @brief    UART driver header file.
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


#ifndef UART_H
#define UART_H

#ifdef __cplusplus
extern "C" {
#endif


#include "spc1068.h"




/**
 *  @brief  UART Transmit FIFO interrupt level type definition
 */
typedef enum
{
  UART_TXFIFO_HALF_EMPTY      = UARTFCR_BIT_TIL_TXFIFO_HALF_EMPTY,    /*!< Interrupt when FIFO is half empty */
  UART_TXFIFO_EMPTY           = UARTFCR_BIT_TIL_TXFIFO_EMPTY          /*!< Interrupt when FIFO is empty      */
} UART_TxTriggerLevelEnum;




/**
 *  @brief  UART Receive FIFO interrupt level type definition
 */
typedef enum
{
  UART_RXFIFO_1BYTE_OR_MORE   = UARTFCR_BIT_ITL_RX_FIFO_THRESHOLD_1,  /*!< 1  byte  or more in FIFO causes interrupt */
  UART_RXFIFO_8BYTE_OR_MORE   = UARTFCR_BIT_ITL_RX_FIFO_THRESHOLD_8,  /*!< 8  bytes or more in FIFO causes interrupt */
  UART_RXFIFO_16BYTE_OR_MORE  = UARTFCR_BIT_ITL_RX_FIFO_THRESHOLD_16, /*!< 16 bytes or more in FIFO causes interrupt */
  UART_RXFIFO_32BYTE_OR_MORE  = UARTFCR_BIT_ITL_RX_FIFO_THRESHOLD_32  /*!< 32 bytes or more in FIFO causes interrupt */
} UART_RxTriggerLevelEnum;




/****************************************************************************//**
 * @brief      Enable UART module
 *
 * @param[in]  UARTx :  Select the UART module
 *
 * @return     none
 *
 *******************************************************************************/
#define UART_Enable(UARTx)                  ((UARTx)->UARTDLH_UARTIER.UARTIER.all |= UARTIER_ALL_UUE_UART_ENABLE)




/****************************************************************************//**
 * @brief      Disable UART module
 *
 * @param[in]  UARTx :  Select the UART module
 *
 * @return     none
 *
 *******************************************************************************/
#define UART_Disable(UARTx)                 ((UARTx)->UARTDLH_UARTIER.UARTIER.bit.UUE = UARTIER_BIT_UUE_UART_DISABLE)




/****************************************************************************//**
 * @brief      Send one byte data to the UART peripheral
 *
 * @param[in]  UARTx :  Select the UART module
 * @param[in]  u8Data:  Byte data to be sent
 *
 * @return     none
 *
 *******************************************************************************/
#define UART_WriteByte(UARTx, u8Data)       ((UARTx)->UARTRBR_UARTTHR_UARTDLL.UARTTHR.all = (((uint32_t)(u8Data)) & 0xFF))




/****************************************************************************//**
 * @brief      Receive one byte data from the UART peripheral
 *
 * @param[in]  UARTx:  Select the UART module
 *
 * @return     The received byte data
 *
 *******************************************************************************/
#define UART_ReadByte(UARTx)                ((uint8_t)((UARTx)->UARTRBR_UARTTHR_UARTDLL.UARTRBR.all))




/****************************************************************************//**
 * @brief      Enable UART interrupt
 *
 * @param[in]  UARTx :  Select the UART module
 *
 * @return     none
 *
 *******************************************************************************/
#define UART_EnableInt(UARTx)               ((UARTx)->UARTMCR.all |= UARTMCR_ALL_OUT2_INT_ENABLE)




/****************************************************************************//**
 * @brief      Disable UART interrupt
 *
 * @param[in]  UARTx :  Select the UART module
 *
 * @return     none
 *
 *******************************************************************************/
#define UART_DisableInt(UARTx)              ((UARTx)->UARTMCR.bit.OUT2 = UARTMCR_BIT_OUT2_INT_DISABLE)




/****************************************************************************//**
 * @brief      Enable Receiver Data Available Interrupt
 *
 * @param[in]  UARTx :  Select the UART module
 *
 * @return     none
 *
 *******************************************************************************/
#define UART_EnableRxDataAvailableInt(UARTx)    ((UARTx)->UARTDLH_UARTIER.UARTIER.bit.RAVIE = UARTIER_BIT_RAVIE_RX_DATA_INT_ENABLE)




/****************************************************************************//**
 * @brief      Disable Receiver Data Available Interrupt
 *
 * @param[in]  UARTx :  Select the UART module
 *
 * @return     none
 *
 *******************************************************************************/
#define UART_DisableRxDataAvailableInt(UARTx)   ((UARTx)->UARTDLH_UARTIER.UARTIER.bit.RAVIE = UARTIER_BIT_RAVIE_RX_DATA_INT_DISABLE)




/****************************************************************************//**
 * @brief      Enable Transmit Data Request Interrupt
 *
 * @param[in]  UARTx :  Select the UART module
 *
 * @return     none
 *
 *******************************************************************************/
#define UART_EnableTxDataRequestInt(UARTx)      ((UARTx)->UARTDLH_UARTIER.UARTIER.bit.TIE = UARTIER_BIT_TIE_TX_FIFO_INT_ENABLE)




/****************************************************************************//**
 * @brief      Disable Transmit Data Request Interrupt
 *
 * @param[in]  UARTx :  Select the UART module
 *
 * @return     none
 *
 *******************************************************************************/
#define UART_DisableTxDataRequestInt(UARTx)     ((UARTx)->UARTDLH_UARTIER.UARTIER.bit.TIE = UARTIER_BIT_TIE_TX_FIFO_INT_DISABLE)




/****************************************************************************//**
 * @brief      Enable Receiver Error Interrupt
 *
 * @param[in]  UARTx :  Select the UART module
 *
 * @return     none
 *
 *******************************************************************************/
#define UART_EnableRxErrorInt(UARTx)        ((UARTx)->UARTDLH_UARTIER.UARTIER.bit.RLSE = UARTIER_BIT_RLSE_RX_LINE_INT_ENABLE)




/****************************************************************************//**
 * @brief      Disable Receiver Error Interrupt
 *
 * @param[in]  UARTx :  Select the UART module
 *
 * @return     none
 *
 *******************************************************************************/
#define UART_DisableRxErrorInt(UARTx)       ((UARTx)->UARTDLH_UARTIER.UARTIER.bit.RLSE = UARTIER_BIT_RLSE_RX_LINE_INT_DISABLE)




/****************************************************************************//**
 * @brief      Enable Modem Interrupt
 *
 * @param[in]  UARTx :  Select the UART module
 *
 * @return     none
 *
 *******************************************************************************/
#define UART_EnableModemInt(UARTx)          ((UARTx)->UARTDLH_UARTIER.UARTIER.bit.MIE = UARTIER_BIT_MIE_MODEM_INT_ENABLE)




/****************************************************************************//**
 * @brief      Disable Modem Interrupt
 *
 * @param[in]  UARTx :  Select the UART module
 *
 * @return     none
 *
 *******************************************************************************/
#define UART_DisableModemInt(UARTx)         ((UARTx)->UARTDLH_UARTIER.UARTIER.bit.MIE = UARTIER_BIT_MIE_MODEM_INT_DISABLE)




/****************************************************************************//**
 * @brief      Enable Receiver Time-out Interrupt
 *
 * @param[in]  UARTx :  Select the UART module
 *
 * @return     none
 *
 *******************************************************************************/
#define UART_EnableRxTimeoutInt(UARTx)      ((UARTx)->UARTDLH_UARTIER.UARTIER.bit.RTOIE = UARTIER_BIT_RTOIE_RX_TIMEOUT_INT_ENABLE)




/****************************************************************************//**
 * @brief      Disable Receiver Time-out Interrupt
 *
 * @param[in]  UARTx :  Select the UART module
 *
 * @return     none
 *
 *******************************************************************************/
#define UART_DisableRxTimeoutInt(UARTx)     ((UARTx)->UARTDLH_UARTIER.UARTIER.bit.RTOIE = UARTIER_BIT_RTOIE_RX_TIMEOUT_INT_DISABLE)




/****************************************************************************//**
 * @brief      Get Global Interrupt status
 *
 * @param[in]  UARTx :  Select the UART module
 *
 * @return     0 : A Interrupt not occurred
 *             1 : Interrupts has occurred
 *
 *******************************************************************************/
#define UART_GetGlobalIntStatus(UARTx)      (((UARTx)->UARTIIR_UARTFCR.UARTIIR.bit.NIP == UARTIIR_BIT_NIP_INT_OCCUR)? (1) : (0))




/****************************************************************************//**
 * @brief      Get Modem interrupt status
 *
 * @param[in]  UARTx :  Select the UART module
 *
 * @return     0 : Modem status interrupt not occurred
 *             1 : Modem status interrupt occurred
 *
 *******************************************************************************/
#define UART_GetModemIntStatus(UARTx)       (((UARTx)->UARTIIR_UARTFCR.UARTIIR.bit.IID == UARTIIR_BIT_IID_MODEM_INT)? (1) : (0))




/****************************************************************************//**
 * @brief      Get Transmit FIFO requests data interrupt status
 *
 * @param[in]  UARTx :  Select the UART module
 *
 * @return     0 : Transmit FIFO requests data interrupt not occurred
 *             1 : Transmit FIFO requests data interrupt occurred
 *
 *******************************************************************************/
#define UART_GetTxDataRequestIntStatus(UARTx)     (((UARTx)->UARTIIR_UARTFCR.UARTIIR.bit.IID == UARTIIR_BIT_IID_TX_FIFO_REQUEST_DATA_INT)? (1) : (0))




/****************************************************************************//**
 * @brief      Get Received data available interrupt status
 *
 * @param[in]  UARTx :  Select the UART module
 *
 * @return     0 : Received data available interrupt not occurred
 *             1 : Received data available interrupt occurred
 *
 *******************************************************************************/
#define UART_GetRxDataAvailableIntStatus(UARTx)   (((UARTx)->UARTIIR_UARTFCR.UARTIIR.bit.IID == UARTIIR_BIT_IID_RX_DATA_READY_INT)? (1) : (0))




/****************************************************************************//**
 * @brief      Get Receive error(Overrun, parity, framing, break, FIFO error) interrupt status
 *
 * @param[in]  UARTx :  Select the UART module
 *
 * @return     0 : Received error interrupt not occurred
 *             1 : Received error interrupt occurred
 *
 *******************************************************************************/
#define UART_GetRxErrorIntStatus(UARTx)     (((UARTx)->UARTIIR_UARTFCR.UARTIIR.bit.IID == UARTIIR_BIT_IID_RX_ERROR_INT)? (1) : (0))




/****************************************************************************//**
 * @brief      Get Receive timeout interrupt status
 *
 * @param[in]  UARTx :  Select the UART module
 *
 * @return     0 : No time out interrupt is pending
 *             1 : Time out interrupt is pending.(FIFO mode only)
 *
 *******************************************************************************/
#define UART_GetRxTimeoutIntStatus(UARTx)   ((UARTx)->UARTIIR_UARTFCR.UARTIIR.bit.TOD)




/****************************************************************************//**
 * @brief      Disable UART FIFOs
 *
 * @param[in]  UARTx :  Select the UART module
 *
 * @return     none
 *
 *******************************************************************************/
#define UART_DisableFifo(UARTx)             ((UARTx)->UARTIIR_UARTFCR.UARTFCR.all = UARTFCR_ALL_TRFIFOE_FIFO_DISABLE)




/****************************************************************************//**
 * @brief      Reset receive fifo
 *
 * @param[in]  UARTx :  Select the UART module
 *
 * @return     none
 *
 *******************************************************************************/
#define UART_ResetRxFifo(UARTx)             ((UARTx)->UARTIIR_UARTFCR.UARTFCR.all = (UARTFCR_ALL_RSTRF_CLEAR_RX_FIFO | UARTFCR_ALL_TRFIFOE_FIFO_ENABLE))




/****************************************************************************//**
 * @brief      Reset transmit fifo
 *
 * @param[in]  UARTx :  Select the UART module
 *
 * @return     none
 *
 *******************************************************************************/
#define UART_ResetTxFifo(UARTx)             ((UARTx)->UARTIIR_UARTFCR.UARTFCR.all = (UARTFCR_ALL_RSTTF_CLEAR_TX_FIFO | UARTFCR_ALL_TRFIFOE_FIFO_ENABLE))




/****************************************************************************//**
 * @brief      Get receive fifo level
 *
 * @param[in]  UARTx :  Select the UART module
 *
 * @return     Number of bytes (0-63) remaining in the Receive FIFO
 *
 *******************************************************************************/ 
#define UART_GetRxFifoLevel(UARTx)          ((UARTx)->UARTFOR.all & UARTFOR_ALL_BYTECNT_Msk)




/****************************************************************************//**
 * @brief      Enable set break
 *
 * @param[in]  UARTx :  Select the UART module
 *
 * @return     none
 *
 *******************************************************************************/
#define UART_EnableSetBreak(UARTx)          ((UARTx)->UARTLCR.all |= UARTLCR_ALL_SB_FORCE_TX_0)




/****************************************************************************//**
 * @brief      Disable set break
 *
 * @param[in]  UARTx :  Select the UART module
 *
 * @return     none
 *
 *******************************************************************************/
#define UART_DisableSetBreak(UARTx)         ((UARTx)->UARTLCR.bit.SB = 0)




/****************************************************************************//**
 * @brief      Enable stick parity
 *
 * @param[in]  UARTx :  Select the UART module
 *
 * @return     none
 *
 *******************************************************************************/
#define UART_EnableStickParity(UARTx)       ((UARTx)->UARTLCR.all |= UARTLCR_ALL_STKYP_PARITY_EQU_INVERT_EPS)




/****************************************************************************//**
 * @brief      Disable stick parity
 *
 * @param[in]  UARTx :  Select the UART module
 *
 * @return     none
 *
 *******************************************************************************/
#define UART_DisableStickParity(UARTx)      ((UARTx)->UARTLCR.bit.STKYP = 0)




/****************************************************************************//**
 * @brief      Enable loopback mode
 *
 * @param[in]  UARTx :  Select the UART module
 *
 * @return     none
 *
 *******************************************************************************/
#define UART_EnableLoopBackMode(UARTx)      ((UARTx)->UARTMCR.bit.LOOP = 1)




/****************************************************************************//**
 * @brief      Disable loopback mode
 *
 * @param[in]  UARTx :  Select the UART module
 *
 * @return     none
 *
 *******************************************************************************/
#define UART_DisableLoopBackMode(UARTx)     ((UARTx)->UARTMCR.bit.LOOP = 0)




/****************************************************************************//**
 * @brief      Is Fifo error
 *
 * @param[in]  UARTx :  Select the UART module
 *
 * @return     0 : No FIFO or no errors in receive FIFO
 *             1 : At least one character in receive FIFO has errors
 *
 *******************************************************************************/
#define UART_IsFifoError(UARTx)             ((UARTx)->UARTLSR.bit.FIFOERR)




/****************************************************************************//**
 * @brief      Is Transfer Fifo/buffer empty
 *
 * @param[in]  UARTx :  Select the UART module
 *
 * @return     0 : There is data in the transmit shift register, the Transmit 
 *                 Holding Register, or the FIFO.
 *             1 : All the data in the transmitter has been shifted
 *
 *******************************************************************************/
#define UART_IsTxFifoEmpty(UARTx)           ((UARTx)->UARTLSR.bit.TXEMPTY)




/****************************************************************************//**
 * @brief      Is data in the holding register or FIFO waiting to be shifted out
 *
 * @param[in]  UARTx :  Select the UART module
 *
 * @return     0 : There is data in the holding register or FIFO waiting to be shifted out.
 *             1 : The transmit FIFO has half or less than half data
 *
 *******************************************************************************/
#define UART_IsTxDataRequest(UARTx)         ((UARTx)->UARTLSR.bit.TDRQ)




/****************************************************************************//**
 * @brief      Is break signal received
 *
 * @param[in]  UARTx :  Select the UART module
 *
 * @return     0 : No break signal has been received
 *             1 : Break signal received
 *
 *******************************************************************************/
#define UART_IsBreakReceived(UARTx)         ((UARTx)->UARTLSR.bit.BI)




/****************************************************************************//**
 * @brief      Is frame error detected
 *
 * @param[in]  UARTx :  Select the UART module
 *
 * @return     0 : No Framing error
 *             1 : Invalid stop bit has been detected
 *
 *******************************************************************************/
#define UART_IsFrameError(UARTx)            ((UARTx)->UARTLSR.bit.FE)




/****************************************************************************//**
 * @brief      Is parity error detected
 *
 * @param[in]  UARTx :  Select the UART module
 *
 * @return     0 : No Parity Error
 *             1 : Parity error has occurred
 *
 *******************************************************************************/
#define UART_IsParityError(UARTx)            ((UARTx)->UARTLSR.bit.PE)




/****************************************************************************//**
 * @brief      Is receive data lost
 *
 * @param[in]  UARTx :  Select the UART module
 *
 * @return     0 : No data has been overrun
 *             1 : Receive data has been overrun
 *
 *******************************************************************************/
#define UART_IsRxDataLost(UARTx)            ((UARTx)->UARTLSR.bit.OE)




/****************************************************************************//**
 * @brief      Is data available in BRB or receive fifo
 *
 * @param[in]  UARTx :  Select the UART module
 *
 * @return     0 : No data has been received
 *             1 : Data is available in RBR or the FIFO
 *
 *******************************************************************************/
#define UART_IsRxDataReady(UARTx)           ((UARTx)->UARTLSR.bit.DR)




/**
 *  @brief  UART Public Function Declaration
 */
void UART_Init(UART_REGS* UARTx, uint32_t u32Baudrate);

void UART_SetFifoTriggerLevel(UART_REGS* UARTx, UART_RxTriggerLevelEnum eRxTrigLvl, UART_TxTriggerLevelEnum eTxTrigLvl);

void UART_Write(UART_REGS* UARTx, uint8_t *pu8Buffer, uint32_t u32Offset, uint32_t u32Count);
void UART_WriteText(UART_REGS* UARTx, const uint8_t *pu8Text);

void UART_Read(UART_REGS* UARTx, uint8_t *pu8Buffer, uint32_t u32Offset, uint32_t u32Count);


#ifdef __cplusplus
}
#endif /* extern "C" */

#endif /* UART_H */


/******************* (C) COPYRIGHT 2021 SPINTROL LIMITED CO. *****END OF FILE****/
