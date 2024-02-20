/*----------------------------------------------------------------------------
 * Name:    Retarget.c
 * Purpose: 'Retarget' layer for target-dependent low level functions
 * Note(s):
 *----------------------------------------------------------------------------
 * This file is part of the uVision/ARM development tools.
 * This software may only be used under the terms of a valid, current,
 * end user licence from KEIL for a compatible version of KEIL software
 * development tools. Nothing else gives you the right to use this software.
 *
 * This software is supplied "AS IS" without warranties of any kind.
 *
 * Copyright (c) 2012 Keil - An ARM Company. All rights reserved.
 *----------------------------------------------------------------------------*/

#include <stdio.h>
#include "spc1068.h"




/**
 *  @brief  These must be defined to avoid linking in stdio.o from the C Library
 */
struct __FILE { int handle;   /* Add whatever you need here */};
FILE __stdout;
FILE __stdin;
FILE __stderr;




/****************************************************************************//**
 * @brief      Get character from UART
 *
 * @param[in]  f:  Pointer to a FILE object that identifies the stream on which 
 *                 the operation is to be performed
 *
 * @return     The character read from UART
 *
 *******************************************************************************/
int fgetc(FILE *f)
{
  /* Wait until data is available in RBR or the FIFO */
  while((UART->UARTLSR.all & UARTLSR_ALL_DR_Msk) == UARTLSR_ALL_DR_NO_DATA_RECEVIED);
  
  return (int)UART_ReadByte(UART);
}




/****************************************************************************//**
 * @brief      Write character to stream
 *
 * @param[in]  ch:  Character to be written
 * @param[in]  f :  Pointer to a FILE object that identifies the stream on which 
 *                  the operation is to be written
 *
 * @return     The same character that has been written
 *
 *******************************************************************************/
int fputc(int ch, FILE *f)
{
  if(ch =='\n')
  {
    UART_WriteByte(UART, (uint8_t)'\r');
    while((UART->UARTLSR.all & UARTLSR_ALL_TXEMPTY_Msk) == UARTLSR_ALL_TXEMPTY_TXFIFO_NOT_EMPTY){};
  }
  
  UART_WriteByte(UART,(uint8_t) ch);
  while((UART->UARTLSR.all & UARTLSR_ALL_TXEMPTY_Msk) == UARTLSR_ALL_TXEMPTY_TXFIFO_NOT_EMPTY){};
  
  return ch;
}




void _ttywrch(int ch)
{
  UART_WriteByte(UART, (uint8_t) ch);
  while((UART->UARTLSR.all & UARTLSR_ALL_TXEMPTY_Msk) == UARTLSR_ALL_TXEMPTY_TXFIFO_NOT_EMPTY){};
}




int __backspace(FILE *f)
{
  return 0;
}




int ferror(FILE *f)
{
  /* Your implementation of ferror */
  return EOF;
}




void _sys_exit(int return_code)
{
  /* Endless loop */
  while(1);
}
