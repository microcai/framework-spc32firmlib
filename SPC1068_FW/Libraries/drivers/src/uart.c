/**************************************************************************//**
 * @file     uart.c
 * @brief    This file provides UART firmware functions.
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

#include "uart.h"




/****************************************************************************//**
 * @brief      Initializes the UART
 *
 * @param[in]  UARTx      :  Select the UART module
 * @param[in]  u32Baudrate:  Baudrate
 *
 * @return     none
 *
 *******************************************************************************/
void UART_Init(UART_REGS* UARTx, uint32_t u32Baudrate)
{
  uint32_t baudRateDivisor;
  
  /* Enable UART Clock */
  CLOCK_EnableModule(UART_MODULE);
  
  /************Configure the Baud Rate*********************************/
  /* Calculate UART clock divisor */
  baudRateDivisor = CLOCK_GetModuleClk(UART_MODULE) / (16 * u32Baudrate);
  
  /* Enable DLAB to set baud rate */
  UARTx->UARTLCR.bit.DLAB = UARTLCR_BIT_DLAB_DIVISOR_ACCESS;

  /* Config the DLL and DLH registers */
  UARTx->UARTRBR_UARTTHR_UARTDLL.UARTDLL.bit.VAL = baudRateDivisor & 0xFF;
  UARTx->UARTDLH_UARTIER.UARTDLH.bit.VAL = (baudRateDivisor >> 0x08) & 0xFF;

  /* Disable DLAB */
  UARTx->UARTLCR.bit.DLAB = UARTLCR_BIT_DLAB_DIVISOR_LOCK;

  
  /***********Configure Line control register (LCR)********************/
  /* Set parity */
  UARTx->UARTLCR.bit.PEN = UARTLCR_BIT_PEN_NO_PARITY;

  /* Set UART Data Length and stop bit */
  UARTx->UARTLCR.bit.WLS = UARTLCR_BIT_WLS_8_DATA_BIT;  /* 8 data bits */
  UARTx->UARTLCR.bit.STB = UARTLCR_BIT_STB_1_STOP_BIT;  /* 1 stop bit  */
  
  /* FIFO enable */
//  UART_EnableFifo(UARTx);
  
  /* Uart unit enable */
  UARTx->UARTDLH_UARTIER.UARTIER.bit.UUE = UARTIER_BIT_UUE_UART_ENABLE;
}




/****************************************************************************//**
 * @brief      Set FIFO interrupt trigger level
 *
 * @param[in]  UARTx     :  Select the UART module
 * @param[in]  eRxTrigLvl:  Receive FIFO trigger level
 * @param[in]  eTxTrigLvl:  Transmit FIFO trigger level
 *
 * @return     none
 *
 *******************************************************************************/
void UART_SetFifoTriggerLevel(UART_REGS* UARTx, UART_RxTriggerLevelEnum eRxTrigLvl, UART_TxTriggerLevelEnum eTxTrigLvl)
{
  /* Set RX and TX threshold */
  UARTx->UARTIIR_UARTFCR.UARTFCR.all = ((eRxTrigLvl << UARTFCR_ALL_ITL_Pos) & UARTFCR_ALL_ITL_Msk) | 
                                       ((eTxTrigLvl << UARTFCR_ALL_TIL_Pos) & UARTFCR_ALL_TIL_Msk) | 
                                       UARTFCR_ALL_TRFIFOE_FIFO_ENABLE;
}




/****************************************************************************//**
 * @brief      Writes the specified string to the UART peripheral
 *
 * @param[in]  UARTx  :  Select the UART module
 * @param[in]  pu8Text:  String message to be sent
 *
 * @return     none
 *
 *******************************************************************************/
void UART_WriteText(UART_REGS* UARTx, const uint8_t *pu8Text)
{
  while(*pu8Text)
  {
    /* Wait until transmiter empty */
    while((UARTx->UARTLSR.all & UARTLSR_ALL_TXEMPTY_Msk) == UARTLSR_ALL_TXEMPTY_TXFIFO_NOT_EMPTY);
    
    UART_WriteByte(UARTx, *(pu8Text++));
  }
}




/****************************************************************************//**
 * @brief      Writes a specified number of bytes to the UART peripheral
 *
 * @param[in]  UARTx    :  Select the UART module
 * @param[in]  pu8Buffer:  Byte array that contains the data to send
 * @param[in]  u32Offset:  Zero-based byte offset in the buffer parameter 
                           at which to begin copying bytes to UART peripheral
 * @param[in]  u32Count:   Number of byte data to be sent
 *
 * @return     none
 *
 *******************************************************************************/
void UART_Write(UART_REGS* UARTx, uint8_t *pu8Buffer, uint32_t u32Offset, uint32_t u32Count)
{
  uint32_t i = 0;

  for(i = 0; i < u32Count; i++)
  {
    /* Wait until transmiter empty */
    while((UARTx->UARTLSR.all & UARTLSR_ALL_TXEMPTY_Msk) == UARTLSR_ALL_TXEMPTY_TXFIFO_NOT_EMPTY);
    
    UART_WriteByte(UARTx, (uint8_t)pu8Buffer[u32Offset + i]);
  }
}




/****************************************************************************//**
 * @brief      Reads a specified number of bytes from the UART peripheral
 *
 * @param[in]  UARTx    :  Select the UART module
 * @param[in]  pu8Buffer:  Byte array that contains the data to be read
 * @param[in]  u32Offset:  Offset in the buffer array to begin reading from
 * @param[in]  u32Count:   Number of byte data to be read
 *
 * @return     none
 *
 *******************************************************************************/
void UART_Read(UART_REGS* UARTx, uint8_t *pu8Buffer, uint32_t u32Offset, uint32_t u32Count)
{
  uint32_t i;
  
  for(i = 0; i < u32Count; i++)
  {
    /* Wait until data is available in RBR or the FIFO */
    while((UARTx->UARTLSR.all & UARTLSR_ALL_DR_Msk) == UARTLSR_ALL_DR_NO_DATA_RECEVIED);
    
    /* Read one byte data from UART peripheral */
    pu8Buffer[u32Offset + i] = UART_ReadByte(UARTx);
  }
}


/******************* (C) COPYRIGHT 2021 SPINTROL LIMITED CO. *****END OF FILE****/
